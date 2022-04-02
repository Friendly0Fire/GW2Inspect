#include <Core.h>
#include <Direct3D11Loader.h>
#include <imgui.h>
#include <backends/imgui_impl_dx11.h>
#include <backends/imgui_impl_win32.h>
#include <Input.h>
#include <ConfigurationFile.h>
#include <SettingsMenu.h>
#include <Utility.h>
#include <imgui_internal.h>
#include <shellapi.h>
#include <UpdateCheck.h>
#include <ImGuiPopup.h>
#include <MiscTab.h>
#include <MumbleLink.h>
#include <ShaderManager.h>
#include <GFXSettings.h>
#include <Log.h>
#include <Version.h>
#include <MiscTab.h>
#include <VTables.h>
#include <InspectUtility.h>
#include <ranges>
#include <algorithm>
#include <ImGuiExtensions.h>
#include <imgui_internal.h>
#include <DirectXTK/ScreenGrab.h>

namespace GW2Inspect
{

class InspectMiscTab : public ::MiscTab
{
public:
	void AdditionalGUI() override
	{
	}
};

void Core::InnerInitPreImGui()
{
	InspectMiscTab::init<InspectMiscTab>();
}

decltype(ID3D11DeviceVtbl::CreateTexture2D) orig_CreateTexture2D;
HRESULT __stdcall HookedCreateTexture2D(
	ID3D11Device* This,
	const D3D11_TEXTURE2D_DESC* pDesc,
	const D3D11_SUBRESOURCE_DATA* pInitialData,
	ID3D11Texture2D** ppTexture2D
)
{
	auto& c = Core::i();
	auto hr = orig_CreateTexture2D(This, pDesc, pInitialData, ppTexture2D);
	if (SUCCEEDED(hr))
		Core::i().AddTexture(*ppTexture2D, pDesc);
	return hr;
}

decltype(ID3D11DeviceVtbl::CreateShaderResourceView) orig_CreateShaderResourceView;
HRESULT __stdcall HookedCreateShaderResourceView(
	ID3D11Device* This,
	ID3D11Resource* pResource,
	const D3D11_SHADER_RESOURCE_VIEW_DESC* pDesc,
	ID3D11ShaderResourceView** ppSRView
)
{
	auto hr = orig_CreateShaderResourceView(This, pResource, pDesc, ppSRView);
	if (SUCCEEDED(hr))
	{
		ComPtr<ID3D11Texture2D> tex2D;
		if (pResource && SUCCEEDED(pResource->QueryInterface(tex2D.GetAddressOf())))
			Core::i().AddSRV(tex2D, *ppSRView);
	}

	return hr;
}

void Core::InnerInitPostImGui()
{
	auto* ctxVT = (ID3D11DeviceContextVT*)context_.Get();

	auto* devVT = (ID3D11DeviceVT*)device_.Get();
	orig_CreateShaderResourceView = HookVTableEntry(&devVT->lpVtbl->CreateShaderResourceView, HookedCreateShaderResourceView);
	orig_CreateTexture2D = HookVTableEntry(&devVT->lpVtbl->CreateTexture2D, HookedCreateTexture2D);

	saveDDSDialog_.SetTitle("Save Texture");
	saveDDSDialog_.SetTypeFilters({ ".dds" });
}

void Core::InnerInternalInit()
{
	ULONG_PTR contextToken;
	if (CoGetContextToken(&contextToken) == CO_E_NOTINITIALIZED) {
		HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
		if (hr != S_FALSE && hr != RPC_E_CHANGED_MODE && FAILED(hr))
			CriticalMessageBox(L"Could not initialize COM library: error code 0x%X.", hr);
	}
}

void Core::InnerShutdown()
{
	CoUninitialize();
}

void Core::ShowSaveButton(LoadedTexture& t)
{
	if (ImGui::Button(std::format("Save##{}", (void*)t.tex.Get()).c_str()))
	{
		savingTexture_ = t.tex;
		auto n = std::format("{}.dds", (void*)t.tex.Get());
		saveDDSDialog_.Open();
		saveDDSDialog_.SetInputName(n);
	}
}

void Core::AddTexture(ID3D11Texture2D* tex, const D3D11_TEXTURE2D_DESC* desc)
{
	createCalls_++;

	LoadedTexture lt{ tex };
	if (desc)
		lt.desc = *desc;
	else
		tex->GetDesc(&lt.desc);
	loadedTextures_.push_back(std::move(lt));
}

void Core::AddSRV(ComPtr<ID3D11Texture2D> tex, ID3D11ShaderResourceView* srv)
{
	srvCalls_++;

	auto it = std::ranges::find_if(loadedTextures_, [&](auto& lt) { return lt.tex == tex; });
	if (it != loadedTextures_.end())
		it->srv = srv;
}

void Core::InnerUpdate()
{
}

Core::Core()
	: saveDDSDialog_(ImGuiFileBrowserFlags_EnterNewFilename | ImGuiFileBrowserFlags_CreateNewDir)
{
}

void Core::InnerDraw()
{
	saveDDSDialog_.Display();
	if (saveDDSDialog_.HasSelected())
	{
		auto fs = saveDDSDialog_.GetSelected();
		fs.replace_extension(".dds");
		GW2_HASSERT(DirectX::SaveDDSTextureToFile(context_.Get(), savingTexture_.Get(), fs.wstring().c_str()));
		saveDDSDialog_.ClearSelected();
		savingTexture_.Reset();
	}

	for (auto it = displayedTextures_.begin(); it != displayedTextures_.end();)
	{
		auto& t = *it;
		bool isOpen = true;
		ImGui::SetNextWindowSizeConstraints(ImVec2(256, 256), ImVec2(t.desc.Width * 4, t.desc.Height * 4));
		if (ImGui::Begin(std::format("View {}", (void*)t.tex.Get()).c_str(), &isOpen))
		{
			ImGui::Text("%ux%u (%u)", t.desc.Width, t.desc.Height, t.desc.MipLevels);
			ImGui::SameLine();
			ImGui::Text(FormatToString(t.desc.Format));
			ImGui::SameLine();
			ShowSaveButton(t);

			ImVec2 dims = AdjustToArea(t.desc.Width * 4, t.desc.Height * 4, ImGuiGetWindowContentRegionWidth());

			ImGui::Image(t.srv.Get(), dims);
		}
		ImGui::End();

		if (!isOpen)
			it = displayedTextures_.erase(it);
		else
			it++;
	}

	if (ImGui::Begin("Loaded Textures"))
	{
		ImGui::Text("Found %u textures.", createCalls_);
		ImGui::Text("Found %u SRVs.", srvCalls_);

		ImGui::Separator();
		ImGuiTitle("Filter Settings");

		int lastFilterMaxWidth = filterMaxWidth_;

		ImGui::Checkbox("Independent Dimensions", &filterIndependentDims_);
		if (filterIndependentDims_)
		{
			ImGui::InputInt2("Min", &filterMinWidth_);
			ImGui::InputInt2("Max", &filterMaxWidth_);
		}
		else
		{
			ImGui::InputInt("Min", &filterMinWidth_);
			filterMinHeight_ = filterMinWidth_;
			ImGui::InputInt("Max", &filterMaxWidth_);
			filterMaxHeight_ = filterMaxWidth_;
		}

		ImGui::Checkbox("Only BC Formats", &onlyBC_);

		auto filtered = loadedTextures_ | std::views::filter([&](auto& lt) {
			if (!lt.srv)
				return false;
			if (onlyBC_ && !IsBCFormat(lt.desc.Format))
				return false;

			return lt.desc.Width >= filterMinWidth_ && lt.desc.Width <= filterMaxWidth_ &&
				   lt.desc.Height >= filterMinHeight_ && lt.desc.Height <= filterMaxHeight_;
			});

		if (!std::ranges::empty(filtered) && ImGui::BeginTable("LoadedTextures", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg))
		{
			ImGui::TableSetupColumn("Preview", ImGuiTableColumnFlags_WidthFixed, 128);
			ImGui::TableSetupColumn("Details", ImGuiTableColumnFlags_WidthStretch);

			if (lastFilterMaxWidth != filterMaxWidth_)
				ImGui::TableSetColumnWidth(0, filterMaxWidth_);

			std::vector filteredv(filtered.begin(), filtered.end());

			ImGuiListClipper clip;
			clip.Begin(filteredv.size());
			while (clip.Step())
			{
				for (auto& t : filteredv | std::views::drop(clip.DisplayStart) | std::views::take(clip.DisplayEnd - clip.DisplayStart))
				{
					ImGui::TableNextRow(ImGuiTableRowFlags_None, lastAvailableWidth_);
					ImGui::TableSetColumnIndex(0);
					lastAvailableWidth_ = ImGui::GetContentRegionMax().x;

					ImVec2 dims = AdjustToArea(t.desc.Width, t.desc.Height, lastAvailableWidth_);

					ImGui::Image(t.srv.Get(), dims);

					ImGui::TableNextColumn();

					ImGui::PushFont(fontBold());
					ImGui::Text("0x%p", t.tex.Get());
					ImGui::PopFont();

					ImGui::Text("%ux%u (%u)", t.desc.Width, t.desc.Height, t.desc.MipLevels);
					ImGui::Text(FormatToString(t.desc.Format));
					ImGui::Spacing();
					ShowSaveButton(t);
					ImGui::SameLine();
					if (ImGui::Button(std::format("View##{}", (void*)t.tex.Get()).c_str()))
					{
						auto it = std::ranges::find_if(displayedTextures_, [&](auto& t2) { return t2.tex == t.tex; });
						if (it != displayedTextures_.end())
							ImGui::SetWindowFocus(std::format("View {}", (void*)t.tex.Get()).c_str());
						else
							displayedTextures_.push_back(t);
					}
				}
			}

			ImGui::EndTable();
		}

		
	}
	ImGui::End();
}

}
