#pragma once

#include <d3d11.h>

struct D3D11Texture2D : public ID3D11Texture2D
{
	D3D11Texture2D(ID3D11Texture2D* real, D3D11_TEXTURE2D_DESC& desc) : real_(real), desc_(desc) {}

	void GetDevice(ID3D11Device** ppDevice) {
		return real_->GetDevice(ppDevice);
	}

	HRESULT GetPrivateData(
		[in]            REFGUID guid,
		[in, out]       UINT* pDataSize,
		[out, optional] void* pData
	);

	HRESULT SetPrivateData(
		[in]           REFGUID    guid,
		[in]           UINT       DataSize,
		[in, optional] const void* pData
	);

	HRESULT SetPrivateDataInterface(
		[in]           REFGUID        guid,
		[in, optional] const IUnknown* pData
	);

	ULONG AddRef();

	ULONG Release();

	HRESULT QueryInterface(
		REFIID riid,
		void** ppvObject
	);

	void GetDesc(
		[out] D3D11_TEXTURE2D_DESC* pDesc
	);

	UINT GetEvictionPriority();

	void GetType(
		[out] D3D11_RESOURCE_DIMENSION* pResourceDimension
	);

	void SetEvictionPriority(
		[in] UINT EvictionPriority
	);

protected:
	ID3D11Texture2D* real_;
	D3D11_TEXTURE2D_DESC desc_;
};