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
#include <d3d11_4.h>
#include <xxhash.h>

namespace GW2Inspect
{

void HookContext(ID3D11DeviceContext* ctx);

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
int count_CreateTexture2D = 0;
HRESULT __stdcall HookedCreateTexture2D(
	ID3D11Device* This,
	const D3D11_TEXTURE2D_DESC* pDesc,
	const D3D11_SUBRESOURCE_DATA* pInitialData,
	ID3D11Texture2D** ppTexture2D
)
{
	count_CreateTexture2D++;
	auto& c = Core::i();
	auto hr = orig_CreateTexture2D(This, pDesc, pInitialData, ppTexture2D);
	if (SUCCEEDED(hr))
		Core::i().AddTexture(*ppTexture2D, pDesc);
	return hr;
}

decltype(ID3D11DeviceVtbl::CreateShaderResourceView) orig_CreateShaderResourceView;
int count_CreateShaderResourceView = 0;
HRESULT __stdcall HookedCreateShaderResourceView(
	ID3D11Device* This,
	ID3D11Resource* pResource,
	const D3D11_SHADER_RESOURCE_VIEW_DESC* pDesc,
	ID3D11ShaderResourceView** ppSRView
)
{
	count_CreateShaderResourceView++;
	auto hr = orig_CreateShaderResourceView(This, pResource, pDesc, ppSRView);
	if (SUCCEEDED(hr))
	{
		ComPtr<ID3D11Texture2D> tex2D;
		if (pResource && SUCCEEDED(pResource->QueryInterface(tex2D.GetAddressOf())))
			Core::i().AddSRV(tex2D, *ppSRView);
	}

	return hr;
}

decltype(ID3D11DeviceVtbl::GetImmediateContext) orig_GetImmediateContext;
int count_GetImmediateContext = 0;
void __stdcall HookedGetImmediateContext(
	ID3D11Device* This,
	ID3D11DeviceContext** ppImmediateContext
)
{
	count_GetImmediateContext++;
	orig_GetImmediateContext(This, ppImmediateContext);
	HookContext(*ppImmediateContext);
}

decltype(ID3D11DeviceContextVtbl::UpdateSubresource) orig_UpdateSubresource;
int count_UpdateSubresource = 0;
void __stdcall HookedUpdateSubresource(
	ID3D11DeviceContext* This,
	ID3D11Resource* pDstResource,
	UINT            DstSubresource,
	const D3D11_BOX* pDstBox,
	const void* pSrcData,
	UINT            SrcRowPitch,
	UINT            SrcDepthPitch
)
{
	count_UpdateSubresource++;
	orig_UpdateSubresource(This, pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch);

	ComPtr<ID3D11Texture2D> tex2D;
	if (DstSubresource == 0 && pDstResource && SUCCEEDED(pDstResource->QueryInterface(tex2D.GetAddressOf())))
	{
		uint w = pDstBox ? pDstBox->right - pDstBox->left : 0;
		uint h = pDstBox ? pDstBox->bottom - pDstBox->top : 0;
		Core::i().CopyToTexture(tex2D, pSrcData, w, h, SrcRowPitch);
	}
}

decltype(ID3D11DeviceContextVtbl::CopySubresourceRegion) orig_CopySubresourceRegion;
int count_CopySubresourceRegion = 0;
void __stdcall HookedCopySubresourceRegion(
	ID3D11DeviceContext* This,
	ID3D11Resource* pDstResource,
	UINT            DstSubresource,
	UINT            DstX,
	UINT            DstY,
	UINT            DstZ,
	ID3D11Resource* pSrcResource,
	UINT            SrcSubresource,
	const D3D11_BOX* pSrcBox
)
{
	count_CopySubresourceRegion++;
	orig_CopySubresourceRegion(This, pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource, SrcSubresource, pSrcBox);
}

decltype(ID3D11DeviceContextVtbl::CopyResource) orig_CopyResource;
int count_CopyResource = 0;
void __stdcall HookedCopyResource(
	ID3D11DeviceContext* This,
	ID3D11Resource* pDstResource,
	ID3D11Resource* pSrcResource
)
{
	count_CopyResource++;
	orig_CopyResource(This, pDstResource, pSrcResource);
}

decltype(ID3D11DeviceContext1Vtbl::CopySubresourceRegion1) orig_CopySubresourceRegion1;
int count_CopySubresourceRegion1 = 0;
void __stdcall HookedCopySubresourceRegion1(
	ID3D11DeviceContext1* This,
	ID3D11Resource* pDstResource,
	UINT            DstSubresource,
	UINT            DstX,
	UINT            DstY,
	UINT            DstZ,
	ID3D11Resource* pSrcResource,
	UINT            SrcSubresource,
	const D3D11_BOX* pSrcBox,
	UINT            CopyFlags
)
{
	count_CopySubresourceRegion1++;
	orig_CopySubresourceRegion1(This, pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource, SrcSubresource, pSrcBox, CopyFlags);
}

#define MAKE_HOOK(obj, fct) HookVTableEntry(&obj->lpVtbl->fct, Hooked##fct, &orig_##fct);
#define PRINT_COUNT(id) ImGui::Text(#id " count: %d", count_##id);

void* ContextVTable[256];
void HookContext(ID3D11DeviceContext* ctx)
{
	ComPtr<ID3D11DeviceContext1> context1;
	ID3D11DeviceContextVT* ctxVT = (ID3D11DeviceContextVT*)ctx;
	ID3D11DeviceContext1VT* ctx1VT = nullptr;
	if (SUCCEEDED(ctx->QueryInterface(context1.GetAddressOf())))
	{
		ctx1VT = (ID3D11DeviceContext1VT*)context1.Get();
	}

	memcpy_s(ContextVTable, sizeof(ContextVTable), ctxVT->lpVtbl, sizeof(ContextVTable));
	ctxVT->lpVtbl = (decltype(ctxVT->lpVtbl))ContextVTable;

	MAKE_HOOK(ctxVT, UpdateSubresource);
	//MAKE_HOOK(ctxVT, CopySubresourceRegion);
	//MAKE_HOOK(ctxVT, CopyResource);
	if (ctx1VT)
	{
		//MAKE_HOOK(ctx1VT, CopySubresourceRegion1);
	}
}

void Core::InnerInitPostImGui()
{
	HookContext(context_.Get());

	auto* devVT = (ID3D11DeviceVT*)device_.Get();
	MAKE_HOOK(devVT, CreateShaderResourceView);
	MAKE_HOOK(devVT, CreateTexture2D);
	MAKE_HOOK(devVT, GetImmediateContext);

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
	LoadedTexture lt{ tex };
	if (desc)
		lt.desc = *desc;
	else
		tex->GetDesc(&lt.desc);
	loadedTextures_.push_back(std::move(lt));
}

void Core::AddSRV(ComPtr<ID3D11Texture2D>& tex, ID3D11ShaderResourceView* srv)
{
	auto it = std::ranges::find_if(loadedTextures_, [&](auto& lt) { return lt.tex == tex; });
	if (it != loadedTextures_.end())
		it->srv = srv;
}

void Core::CopyToTexture(ComPtr<ID3D11Texture2D>& tex, const void* data, uint w, uint h, uint rowPitch_)
{
	auto it = std::ranges::find_if(loadedTextures_, [&](auto& lt) { return lt.tex == tex; });
	if (it != loadedTextures_.end())
	{
		it->wasCopiedTo = true;

		if ((w == it->desc.Width || w == 0) && (h == it->desc.Height || h == 0))
		{
			size_t slicePitch, rowPitch, rowCount;
			GetSurfaceInfo(it->desc.Width, it->desc.Height, it->desc.Format, &slicePitch, &rowPitch, &rowCount);
			it->data.resize(slicePitch);
			std::copy_n((uint8_t*)data, slicePitch, it->data.begin());
			it->hash = XXH3_64bits(data, slicePitch);
		}
	}
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
		ImGui::SetNextWindowSizeConstraints(ImVec2(256, 256), ImGui::GetIO().DisplaySize);
		if (ImGui::Begin(std::format("View {}", (void*)t.tex.Get()).c_str(), &isOpen))
		{
			ImGui::Text("%ux%u (%u) | %s", t.desc.Width, t.desc.Height, t.desc.MipLevels, FormatToString(t.desc.Format));

			ImVec2 dims = AdjustToArea(t.desc.Width * 4, t.desc.Height * 4, ImGuiGetWindowContentRegionWidth());

			ImGui::Image(t.srv.Get(), dims);

			ImGui::Separator();
			DisplayHash((uint64_t)t.tex.Get(), t.hash, fontMono());
			ShowSaveButton(t);

			if (!t.data.empty())
			{
				ImGui::PushFont(fontMono());

				ImVec2 avail = ImGui::GetContentRegionAvail();

				float byteW = ImGui::CalcTextSize("00 ").x;
				int bytesPerLine = std::floor(avail.x / byteW) - 1;

				std::vector<char> displayString;
				displayString.resize(t.data.size() * 3, '0');
				for (size_t i = 0; i < t.data.size(); i++)
				{
					size_t off = t.data[i] <= 9 ? 1 : 0;
					std::to_chars(&displayString[i * 3 + off], &displayString[i * 3 + 2], t.data[i], 16);
					displayString[i * 3 + 2] = i % bytesPerLine == bytesPerLine - 1 ? '\n' : ' ';
				}
				displayString.back() = '\0';

				ImGui::InputTextMultiline(std::format("##RawTexture{}", (void*)t.tex.Get()).c_str(), displayString.data(), displayString.size(), avail, ImGuiInputTextFlags_ReadOnly);
				ImGui::PopFont();
			}
		}
		ImGui::End();

		if (!isOpen)
			it = displayedTextures_.erase(it);
		else
			it++;
	}

	if (ImGui::Begin("Loaded Textures"))
	{
		PRINT_COUNT(GetImmediateContext);
		PRINT_COUNT(CreateTexture2D);
		PRINT_COUNT(CreateShaderResourceView);
		PRINT_COUNT(UpdateSubresource);
		PRINT_COUNT(CopySubresourceRegion);
		PRINT_COUNT(CopyResource);
		PRINT_COUNT(CopySubresourceRegion1);

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
		ImGui::Checkbox("Only UpdateSubresource destinations", &onlyWrittenTo_);

		auto filtered = loadedTextures_ | std::views::filter([&](auto& lt) {
			if (!lt.srv)
				return false;
			if (onlyWrittenTo_ && !lt.wasCopiedTo)
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
					DisplayHash((uint64_t)t.tex.Get(), t.hash, fontMono());
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
