#pragma once

#include <Main.h>
#include <Singleton.h>
#include <Defs.h>
#include <d3d11_1.h>
#include <dxgi.h>
#include <Direct3D11Loader.h>
#include <ConfigurationOption.h>
#include <imgui.h>
#include <imfilebrowser.h>

class ShaderManager;

namespace GW2Inspect
{

class Core : public BaseCore, public Singleton<Core>
{
public:
	Core();

	void AddTexture(ID3D11Texture2D* tex, const D3D11_TEXTURE2D_DESC* desc = nullptr);
	void AddSRV(ComPtr<ID3D11Texture2D> tex, ID3D11ShaderResourceView* srv);
protected:
	struct LoadedTexture
	{
		ComPtr<ID3D11Texture2D> tex;
		D3D11_TEXTURE2D_DESC desc;
		ComPtr<ID3D11ShaderResourceView> srv;
	};

	void InnerDraw() override;
	void InnerUpdate() override;
	void InnerInitPreImGui() override;
	void InnerInitPostImGui() override;
	void InnerInternalInit() override;
	void InnerShutdown() override;

	uint GetShaderArchiveID() const override { return IDR_SHADERS; }
	const wchar_t* GetShaderDirectory() const override { return SHADERS_DIR; }
	const wchar_t* GetGithubRepoSubUrl() const override { return L"Friendly0Fire/GW2Inspect"; }

	void ShowSaveButton(LoadedTexture& t);

	bool onlyBC_ = true;
	bool filterIndependentDims_ = false;
	int filterMinWidth_ = 0;
	int filterMinHeight_ = 0;
	int filterMaxWidth_ = 8192;
	int filterMaxHeight_ = 8192;

	int lastAvailableWidth_ = 0;

	ImGui::FileBrowser saveDDSDialog_;

	ComPtr<ID3D11Texture2D> savingTexture_;

	uint createCalls_ = 0;
	uint srvCalls_ = 0;

	std::vector<LoadedTexture> loadedTextures_;

	std::vector<LoadedTexture> displayedTextures_;
};
}
