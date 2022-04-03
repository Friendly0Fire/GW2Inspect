#pragma once

#include <d3d11_1.h>

typedef struct ID3D11DeviceVtbl
{
    BEGIN_INTERFACE

        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT(STDMETHODCALLTYPE* QueryInterface)(
            ID3D11Device* This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */
            _COM_Outptr_  void** ppvObject);

    DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG(STDMETHODCALLTYPE* AddRef)(
            ID3D11Device* This);

    DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG(STDMETHODCALLTYPE* Release)(
            ID3D11Device* This);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateBuffer)
        HRESULT(STDMETHODCALLTYPE* CreateBuffer)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  const D3D11_BUFFER_DESC* pDesc,
            /* [annotation] */
            _In_opt_  const D3D11_SUBRESOURCE_DATA* pInitialData,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11Buffer** ppBuffer);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateTexture1D)
        HRESULT(STDMETHODCALLTYPE* CreateTexture1D)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  const D3D11_TEXTURE1D_DESC* pDesc,
            /* [annotation] */
            _In_reads_opt_(_Inexpressible_(pDesc->MipLevels* pDesc->ArraySize))  const D3D11_SUBRESOURCE_DATA* pInitialData,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11Texture1D** ppTexture1D);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateTexture2D)
        HRESULT(STDMETHODCALLTYPE* CreateTexture2D)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  const D3D11_TEXTURE2D_DESC* pDesc,
            /* [annotation] */
            _In_reads_opt_(_Inexpressible_(pDesc->MipLevels* pDesc->ArraySize))  const D3D11_SUBRESOURCE_DATA* pInitialData,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11Texture2D** ppTexture2D);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateTexture3D)
        HRESULT(STDMETHODCALLTYPE* CreateTexture3D)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  const D3D11_TEXTURE3D_DESC* pDesc,
            /* [annotation] */
            _In_reads_opt_(_Inexpressible_(pDesc->MipLevels))  const D3D11_SUBRESOURCE_DATA* pInitialData,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11Texture3D** ppTexture3D);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateShaderResourceView)
        HRESULT(STDMETHODCALLTYPE* CreateShaderResourceView)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  ID3D11Resource* pResource,
            /* [annotation] */
            _In_opt_  const D3D11_SHADER_RESOURCE_VIEW_DESC* pDesc,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11ShaderResourceView** ppSRView);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateUnorderedAccessView)
        HRESULT(STDMETHODCALLTYPE* CreateUnorderedAccessView)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  ID3D11Resource* pResource,
            /* [annotation] */
            _In_opt_  const D3D11_UNORDERED_ACCESS_VIEW_DESC* pDesc,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11UnorderedAccessView** ppUAView);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateRenderTargetView)
        HRESULT(STDMETHODCALLTYPE* CreateRenderTargetView)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  ID3D11Resource* pResource,
            /* [annotation] */
            _In_opt_  const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11RenderTargetView** ppRTView);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateDepthStencilView)
        HRESULT(STDMETHODCALLTYPE* CreateDepthStencilView)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  ID3D11Resource* pResource,
            /* [annotation] */
            _In_opt_  const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11DepthStencilView** ppDepthStencilView);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateInputLayout)
        HRESULT(STDMETHODCALLTYPE* CreateInputLayout)(
            ID3D11Device* This,
            /* [annotation] */
            _In_reads_(NumElements)  const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
            /* [annotation] */
            _In_range_(0, D3D11_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT)  UINT NumElements,
            /* [annotation] */
            _In_reads_(BytecodeLength)  const void* pShaderBytecodeWithInputSignature,
            /* [annotation] */
            _In_  SIZE_T BytecodeLength,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11InputLayout** ppInputLayout);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateVertexShader)
        HRESULT(STDMETHODCALLTYPE* CreateVertexShader)(
            ID3D11Device* This,
            /* [annotation] */
            _In_reads_(BytecodeLength)  const void* pShaderBytecode,
            /* [annotation] */
            _In_  SIZE_T BytecodeLength,
            /* [annotation] */
            _In_opt_  ID3D11ClassLinkage* pClassLinkage,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11VertexShader** ppVertexShader);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateGeometryShader)
        HRESULT(STDMETHODCALLTYPE* CreateGeometryShader)(
            ID3D11Device* This,
            /* [annotation] */
            _In_reads_(BytecodeLength)  const void* pShaderBytecode,
            /* [annotation] */
            _In_  SIZE_T BytecodeLength,
            /* [annotation] */
            _In_opt_  ID3D11ClassLinkage* pClassLinkage,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11GeometryShader** ppGeometryShader);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateGeometryShaderWithStreamOutput)
        HRESULT(STDMETHODCALLTYPE* CreateGeometryShaderWithStreamOutput)(
            ID3D11Device* This,
            /* [annotation] */
            _In_reads_(BytecodeLength)  const void* pShaderBytecode,
            /* [annotation] */
            _In_  SIZE_T BytecodeLength,
            /* [annotation] */
            _In_reads_opt_(NumEntries)  const D3D11_SO_DECLARATION_ENTRY* pSODeclaration,
            /* [annotation] */
            _In_range_(0, D3D11_SO_STREAM_COUNT* D3D11_SO_OUTPUT_COMPONENT_COUNT)  UINT NumEntries,
            /* [annotation] */
            _In_reads_opt_(NumStrides)  const UINT* pBufferStrides,
            /* [annotation] */
            _In_range_(0, D3D11_SO_BUFFER_SLOT_COUNT)  UINT NumStrides,
            /* [annotation] */
            _In_  UINT RasterizedStream,
            /* [annotation] */
            _In_opt_  ID3D11ClassLinkage* pClassLinkage,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11GeometryShader** ppGeometryShader);

    DECLSPEC_XFGVIRT(ID3D11Device, CreatePixelShader)
        HRESULT(STDMETHODCALLTYPE* CreatePixelShader)(
            ID3D11Device* This,
            /* [annotation] */
            _In_reads_(BytecodeLength)  const void* pShaderBytecode,
            /* [annotation] */
            _In_  SIZE_T BytecodeLength,
            /* [annotation] */
            _In_opt_  ID3D11ClassLinkage* pClassLinkage,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11PixelShader** ppPixelShader);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateHullShader)
        HRESULT(STDMETHODCALLTYPE* CreateHullShader)(
            ID3D11Device* This,
            /* [annotation] */
            _In_reads_(BytecodeLength)  const void* pShaderBytecode,
            /* [annotation] */
            _In_  SIZE_T BytecodeLength,
            /* [annotation] */
            _In_opt_  ID3D11ClassLinkage* pClassLinkage,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11HullShader** ppHullShader);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateDomainShader)
        HRESULT(STDMETHODCALLTYPE* CreateDomainShader)(
            ID3D11Device* This,
            /* [annotation] */
            _In_reads_(BytecodeLength)  const void* pShaderBytecode,
            /* [annotation] */
            _In_  SIZE_T BytecodeLength,
            /* [annotation] */
            _In_opt_  ID3D11ClassLinkage* pClassLinkage,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11DomainShader** ppDomainShader);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateComputeShader)
        HRESULT(STDMETHODCALLTYPE* CreateComputeShader)(
            ID3D11Device* This,
            /* [annotation] */
            _In_reads_(BytecodeLength)  const void* pShaderBytecode,
            /* [annotation] */
            _In_  SIZE_T BytecodeLength,
            /* [annotation] */
            _In_opt_  ID3D11ClassLinkage* pClassLinkage,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11ComputeShader** ppComputeShader);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateClassLinkage)
        HRESULT(STDMETHODCALLTYPE* CreateClassLinkage)(
            ID3D11Device* This,
            /* [annotation] */
            _COM_Outptr_  ID3D11ClassLinkage** ppLinkage);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateBlendState)
        HRESULT(STDMETHODCALLTYPE* CreateBlendState)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  const D3D11_BLEND_DESC* pBlendStateDesc,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11BlendState** ppBlendState);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateDepthStencilState)
        HRESULT(STDMETHODCALLTYPE* CreateDepthStencilState)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  const D3D11_DEPTH_STENCIL_DESC* pDepthStencilDesc,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11DepthStencilState** ppDepthStencilState);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateRasterizerState)
        HRESULT(STDMETHODCALLTYPE* CreateRasterizerState)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  const D3D11_RASTERIZER_DESC* pRasterizerDesc,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11RasterizerState** ppRasterizerState);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateSamplerState)
        HRESULT(STDMETHODCALLTYPE* CreateSamplerState)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  const D3D11_SAMPLER_DESC* pSamplerDesc,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11SamplerState** ppSamplerState);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateQuery)
        HRESULT(STDMETHODCALLTYPE* CreateQuery)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  const D3D11_QUERY_DESC* pQueryDesc,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11Query** ppQuery);

    DECLSPEC_XFGVIRT(ID3D11Device, CreatePredicate)
        HRESULT(STDMETHODCALLTYPE* CreatePredicate)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  const D3D11_QUERY_DESC* pPredicateDesc,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11Predicate** ppPredicate);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateCounter)
        HRESULT(STDMETHODCALLTYPE* CreateCounter)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  const D3D11_COUNTER_DESC* pCounterDesc,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11Counter** ppCounter);

    DECLSPEC_XFGVIRT(ID3D11Device, CreateDeferredContext)
        HRESULT(STDMETHODCALLTYPE* CreateDeferredContext)(
            ID3D11Device* This,
            UINT ContextFlags,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11DeviceContext** ppDeferredContext);

    DECLSPEC_XFGVIRT(ID3D11Device, OpenSharedResource)
        HRESULT(STDMETHODCALLTYPE* OpenSharedResource)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  HANDLE hResource,
            /* [annotation] */
            _In_  REFIID ReturnedInterface,
            /* [annotation] */
            _COM_Outptr_opt_  void** ppResource);

    DECLSPEC_XFGVIRT(ID3D11Device, CheckFormatSupport)
        HRESULT(STDMETHODCALLTYPE* CheckFormatSupport)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  DXGI_FORMAT Format,
            /* [annotation] */
            _Out_  UINT* pFormatSupport);

    DECLSPEC_XFGVIRT(ID3D11Device, CheckMultisampleQualityLevels)
        HRESULT(STDMETHODCALLTYPE* CheckMultisampleQualityLevels)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  DXGI_FORMAT Format,
            /* [annotation] */
            _In_  UINT SampleCount,
            /* [annotation] */
            _Out_  UINT* pNumQualityLevels);

    DECLSPEC_XFGVIRT(ID3D11Device, CheckCounterInfo)
        void (STDMETHODCALLTYPE* CheckCounterInfo)(
            ID3D11Device* This,
            /* [annotation] */
            _Out_  D3D11_COUNTER_INFO* pCounterInfo);

    DECLSPEC_XFGVIRT(ID3D11Device, CheckCounter)
        HRESULT(STDMETHODCALLTYPE* CheckCounter)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  const D3D11_COUNTER_DESC* pDesc,
            /* [annotation] */
            _Out_  D3D11_COUNTER_TYPE* pType,
            /* [annotation] */
            _Out_  UINT* pActiveCounters,
            /* [annotation] */
            _Out_writes_opt_(*pNameLength)  LPSTR szName,
            /* [annotation] */
            _Inout_opt_  UINT* pNameLength,
            /* [annotation] */
            _Out_writes_opt_(*pUnitsLength)  LPSTR szUnits,
            /* [annotation] */
            _Inout_opt_  UINT* pUnitsLength,
            /* [annotation] */
            _Out_writes_opt_(*pDescriptionLength)  LPSTR szDescription,
            /* [annotation] */
            _Inout_opt_  UINT* pDescriptionLength);

    DECLSPEC_XFGVIRT(ID3D11Device, CheckFeatureSupport)
        HRESULT(STDMETHODCALLTYPE* CheckFeatureSupport)(
            ID3D11Device* This,
            D3D11_FEATURE Feature,
            /* [annotation] */
            _Out_writes_bytes_(FeatureSupportDataSize)  void* pFeatureSupportData,
            UINT FeatureSupportDataSize);

    DECLSPEC_XFGVIRT(ID3D11Device, GetPrivateData)
        HRESULT(STDMETHODCALLTYPE* GetPrivateData)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  REFGUID guid,
            /* [annotation] */
            _Inout_  UINT* pDataSize,
            /* [annotation] */
            _Out_writes_bytes_opt_(*pDataSize)  void* pData);

    DECLSPEC_XFGVIRT(ID3D11Device, SetPrivateData)
        HRESULT(STDMETHODCALLTYPE* SetPrivateData)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  REFGUID guid,
            /* [annotation] */
            _In_  UINT DataSize,
            /* [annotation] */
            _In_reads_bytes_opt_(DataSize)  const void* pData);

    DECLSPEC_XFGVIRT(ID3D11Device, SetPrivateDataInterface)
        HRESULT(STDMETHODCALLTYPE* SetPrivateDataInterface)(
            ID3D11Device* This,
            /* [annotation] */
            _In_  REFGUID guid,
            /* [annotation] */
            _In_opt_  const IUnknown* pData);

    DECLSPEC_XFGVIRT(ID3D11Device, GetFeatureLevel)
        D3D_FEATURE_LEVEL(STDMETHODCALLTYPE* GetFeatureLevel)(
            ID3D11Device* This);

    DECLSPEC_XFGVIRT(ID3D11Device, GetCreationFlags)
        UINT(STDMETHODCALLTYPE* GetCreationFlags)(
            ID3D11Device* This);

    DECLSPEC_XFGVIRT(ID3D11Device, GetDeviceRemovedReason)
        HRESULT(STDMETHODCALLTYPE* GetDeviceRemovedReason)(
            ID3D11Device* This);

    DECLSPEC_XFGVIRT(ID3D11Device, GetImmediateContext)
        void (STDMETHODCALLTYPE* GetImmediateContext)(
            ID3D11Device* This,
            /* [annotation] */
            _Outptr_  ID3D11DeviceContext** ppImmediateContext);

    DECLSPEC_XFGVIRT(ID3D11Device, SetExceptionMode)
        HRESULT(STDMETHODCALLTYPE* SetExceptionMode)(
            ID3D11Device* This,
            UINT RaiseFlags);

    DECLSPEC_XFGVIRT(ID3D11Device, GetExceptionMode)
        UINT(STDMETHODCALLTYPE* GetExceptionMode)(
            ID3D11Device* This);

    END_INTERFACE
} ID3D11DeviceVtbl;

interface ID3D11DeviceVT
{
    CONST_VTBL struct ID3D11DeviceVtbl* lpVtbl;
};

typedef struct ID3D11DeviceContextVtbl
{
    BEGIN_INTERFACE

        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT(STDMETHODCALLTYPE* QueryInterface)(
            ID3D11DeviceContext* This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */
            _COM_Outptr_  void** ppvObject);

    DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG(STDMETHODCALLTYPE* AddRef)(
            ID3D11DeviceContext* This);

    DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG(STDMETHODCALLTYPE* Release)(
            ID3D11DeviceContext* This);

    DECLSPEC_XFGVIRT(ID3D11DeviceChild, GetDevice)
        void (STDMETHODCALLTYPE* GetDevice)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _Outptr_  ID3D11Device** ppDevice);

    DECLSPEC_XFGVIRT(ID3D11DeviceChild, GetPrivateData)
        HRESULT(STDMETHODCALLTYPE* GetPrivateData)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  REFGUID guid,
            /* [annotation] */
            _Inout_  UINT* pDataSize,
            /* [annotation] */
            _Out_writes_bytes_opt_(*pDataSize)  void* pData);

    DECLSPEC_XFGVIRT(ID3D11DeviceChild, SetPrivateData)
        HRESULT(STDMETHODCALLTYPE* SetPrivateData)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  REFGUID guid,
            /* [annotation] */
            _In_  UINT DataSize,
            /* [annotation] */
            _In_reads_bytes_opt_(DataSize)  const void* pData);

    DECLSPEC_XFGVIRT(ID3D11DeviceChild, SetPrivateDataInterface)
        HRESULT(STDMETHODCALLTYPE* SetPrivateDataInterface)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  REFGUID guid,
            /* [annotation] */
            _In_opt_  const IUnknown* pData);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, VSSetConstantBuffers)
        void (STDMETHODCALLTYPE* VSSetConstantBuffers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, PSSetShaderResources)
        void (STDMETHODCALLTYPE* PSSetShaderResources)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, PSSetShader)
        void (STDMETHODCALLTYPE* PSSetShader)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_opt_  ID3D11PixelShader* pPixelShader,
            /* [annotation] */
            _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
            UINT NumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, PSSetSamplers)
        void (STDMETHODCALLTYPE* PSSetSamplers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, VSSetShader)
        void (STDMETHODCALLTYPE* VSSetShader)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_opt_  ID3D11VertexShader* pVertexShader,
            /* [annotation] */
            _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
            UINT NumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DrawIndexed)
        void (STDMETHODCALLTYPE* DrawIndexed)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  UINT IndexCount,
            /* [annotation] */
            _In_  UINT StartIndexLocation,
            /* [annotation] */
            _In_  INT BaseVertexLocation);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, Draw)
        void (STDMETHODCALLTYPE* Draw)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  UINT VertexCount,
            /* [annotation] */
            _In_  UINT StartVertexLocation);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, Map)
        HRESULT(STDMETHODCALLTYPE* Map)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11Resource* pResource,
            /* [annotation] */
            _In_  UINT Subresource,
            /* [annotation] */
            _In_  D3D11_MAP MapType,
            /* [annotation] */
            _In_  UINT MapFlags,
            /* [annotation] */
            _Out_opt_  D3D11_MAPPED_SUBRESOURCE* pMappedResource);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, Unmap)
        void (STDMETHODCALLTYPE* Unmap)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11Resource* pResource,
            /* [annotation] */
            _In_  UINT Subresource);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, PSSetConstantBuffers)
        void (STDMETHODCALLTYPE* PSSetConstantBuffers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, IASetInputLayout)
        void (STDMETHODCALLTYPE* IASetInputLayout)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_opt_  ID3D11InputLayout* pInputLayout);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, IASetVertexBuffers)
        void (STDMETHODCALLTYPE* IASetVertexBuffers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppVertexBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pStrides,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pOffsets);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, IASetIndexBuffer)
        void (STDMETHODCALLTYPE* IASetIndexBuffer)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_opt_  ID3D11Buffer* pIndexBuffer,
            /* [annotation] */
            _In_  DXGI_FORMAT Format,
            /* [annotation] */
            _In_  UINT Offset);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DrawIndexedInstanced)
        void (STDMETHODCALLTYPE* DrawIndexedInstanced)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  UINT IndexCountPerInstance,
            /* [annotation] */
            _In_  UINT InstanceCount,
            /* [annotation] */
            _In_  UINT StartIndexLocation,
            /* [annotation] */
            _In_  INT BaseVertexLocation,
            /* [annotation] */
            _In_  UINT StartInstanceLocation);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DrawInstanced)
        void (STDMETHODCALLTYPE* DrawInstanced)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  UINT VertexCountPerInstance,
            /* [annotation] */
            _In_  UINT InstanceCount,
            /* [annotation] */
            _In_  UINT StartVertexLocation,
            /* [annotation] */
            _In_  UINT StartInstanceLocation);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GSSetConstantBuffers)
        void (STDMETHODCALLTYPE* GSSetConstantBuffers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GSSetShader)
        void (STDMETHODCALLTYPE* GSSetShader)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_opt_  ID3D11GeometryShader* pShader,
            /* [annotation] */
            _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
            UINT NumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, IASetPrimitiveTopology)
        void (STDMETHODCALLTYPE* IASetPrimitiveTopology)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  D3D11_PRIMITIVE_TOPOLOGY Topology);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, VSSetShaderResources)
        void (STDMETHODCALLTYPE* VSSetShaderResources)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, VSSetSamplers)
        void (STDMETHODCALLTYPE* VSSetSamplers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, Begin)
        void (STDMETHODCALLTYPE* Begin)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11Asynchronous* pAsync);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, End)
        void (STDMETHODCALLTYPE* End)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11Asynchronous* pAsync);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GetData)
        HRESULT(STDMETHODCALLTYPE* GetData)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11Asynchronous* pAsync,
            /* [annotation] */
            _Out_writes_bytes_opt_(DataSize)  void* pData,
            /* [annotation] */
            _In_  UINT DataSize,
            /* [annotation] */
            _In_  UINT GetDataFlags);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, SetPredication)
        void (STDMETHODCALLTYPE* SetPredication)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_opt_  ID3D11Predicate* pPredicate,
            /* [annotation] */
            _In_  BOOL PredicateValue);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GSSetShaderResources)
        void (STDMETHODCALLTYPE* GSSetShaderResources)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GSSetSamplers)
        void (STDMETHODCALLTYPE* GSSetSamplers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, OMSetRenderTargets)
        void (STDMETHODCALLTYPE* OMSetRenderTargets)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT)  UINT NumViews,
            /* [annotation] */
            _In_reads_opt_(NumViews)  ID3D11RenderTargetView* const* ppRenderTargetViews,
            /* [annotation] */
            _In_opt_  ID3D11DepthStencilView* pDepthStencilView);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, OMSetRenderTargetsAndUnorderedAccessViews)
        void (STDMETHODCALLTYPE* OMSetRenderTargetsAndUnorderedAccessViews)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  UINT NumRTVs,
            /* [annotation] */
            _In_reads_opt_(NumRTVs)  ID3D11RenderTargetView* const* ppRenderTargetViews,
            /* [annotation] */
            _In_opt_  ID3D11DepthStencilView* pDepthStencilView,
            /* [annotation] */
            _In_range_(0, D3D11_1_UAV_SLOT_COUNT - 1)  UINT UAVStartSlot,
            /* [annotation] */
            _In_  UINT NumUAVs,
            /* [annotation] */
            _In_reads_opt_(NumUAVs)  ID3D11UnorderedAccessView* const* ppUnorderedAccessViews,
            /* [annotation] */
            _In_reads_opt_(NumUAVs)  const UINT* pUAVInitialCounts);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, OMSetBlendState)
        void (STDMETHODCALLTYPE* OMSetBlendState)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_opt_  ID3D11BlendState* pBlendState,
            /* [annotation] */
            _In_opt_  const FLOAT BlendFactor[4],
            /* [annotation] */
            _In_  UINT SampleMask);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, OMSetDepthStencilState)
        void (STDMETHODCALLTYPE* OMSetDepthStencilState)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_opt_  ID3D11DepthStencilState* pDepthStencilState,
            /* [annotation] */
            _In_  UINT StencilRef);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, SOSetTargets)
        void (STDMETHODCALLTYPE* SOSetTargets)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_SO_BUFFER_SLOT_COUNT)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppSOTargets,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pOffsets);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DrawAuto)
        void (STDMETHODCALLTYPE* DrawAuto)(
            ID3D11DeviceContext* This);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DrawIndexedInstancedIndirect)
        void (STDMETHODCALLTYPE* DrawIndexedInstancedIndirect)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11Buffer* pBufferForArgs,
            /* [annotation] */
            _In_  UINT AlignedByteOffsetForArgs);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DrawInstancedIndirect)
        void (STDMETHODCALLTYPE* DrawInstancedIndirect)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11Buffer* pBufferForArgs,
            /* [annotation] */
            _In_  UINT AlignedByteOffsetForArgs);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, Dispatch)
        void (STDMETHODCALLTYPE* Dispatch)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  UINT ThreadGroupCountX,
            /* [annotation] */
            _In_  UINT ThreadGroupCountY,
            /* [annotation] */
            _In_  UINT ThreadGroupCountZ);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DispatchIndirect)
        void (STDMETHODCALLTYPE* DispatchIndirect)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11Buffer* pBufferForArgs,
            /* [annotation] */
            _In_  UINT AlignedByteOffsetForArgs);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, RSSetState)
        void (STDMETHODCALLTYPE* RSSetState)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_opt_  ID3D11RasterizerState* pRasterizerState);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, RSSetViewports)
        void (STDMETHODCALLTYPE* RSSetViewports)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE)  UINT NumViewports,
            /* [annotation] */
            _In_reads_opt_(NumViewports)  const D3D11_VIEWPORT* pViewports);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, RSSetScissorRects)
        void (STDMETHODCALLTYPE* RSSetScissorRects)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE)  UINT NumRects,
            /* [annotation] */
            _In_reads_opt_(NumRects)  const D3D11_RECT* pRects);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CopySubresourceRegion)
        void (STDMETHODCALLTYPE* CopySubresourceRegion)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11Resource* pDstResource,
            /* [annotation] */
            _In_  UINT DstSubresource,
            /* [annotation] */
            _In_  UINT DstX,
            /* [annotation] */
            _In_  UINT DstY,
            /* [annotation] */
            _In_  UINT DstZ,
            /* [annotation] */
            _In_  ID3D11Resource* pSrcResource,
            /* [annotation] */
            _In_  UINT SrcSubresource,
            /* [annotation] */
            _In_opt_  const D3D11_BOX* pSrcBox);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CopyResource)
        void (STDMETHODCALLTYPE* CopyResource)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11Resource* pDstResource,
            /* [annotation] */
            _In_  ID3D11Resource* pSrcResource);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, UpdateSubresource)
        void (STDMETHODCALLTYPE* UpdateSubresource)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11Resource* pDstResource,
            /* [annotation] */
            _In_  UINT DstSubresource,
            /* [annotation] */
            _In_opt_  const D3D11_BOX* pDstBox,
            /* [annotation] */
            _In_  const void* pSrcData,
            /* [annotation] */
            _In_  UINT SrcRowPitch,
            /* [annotation] */
            _In_  UINT SrcDepthPitch);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CopyStructureCount)
        void (STDMETHODCALLTYPE* CopyStructureCount)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11Buffer* pDstBuffer,
            /* [annotation] */
            _In_  UINT DstAlignedByteOffset,
            /* [annotation] */
            _In_  ID3D11UnorderedAccessView* pSrcView);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, ClearRenderTargetView)
        void (STDMETHODCALLTYPE* ClearRenderTargetView)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11RenderTargetView* pRenderTargetView,
            /* [annotation] */
            _In_  const FLOAT ColorRGBA[4]);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, ClearUnorderedAccessViewUint)
        void (STDMETHODCALLTYPE* ClearUnorderedAccessViewUint)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11UnorderedAccessView* pUnorderedAccessView,
            /* [annotation] */
            _In_  const UINT Values[4]);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, ClearUnorderedAccessViewFloat)
        void (STDMETHODCALLTYPE* ClearUnorderedAccessViewFloat)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11UnorderedAccessView* pUnorderedAccessView,
            /* [annotation] */
            _In_  const FLOAT Values[4]);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, ClearDepthStencilView)
        void (STDMETHODCALLTYPE* ClearDepthStencilView)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11DepthStencilView* pDepthStencilView,
            /* [annotation] */
            _In_  UINT ClearFlags,
            /* [annotation] */
            _In_  FLOAT Depth,
            /* [annotation] */
            _In_  UINT8 Stencil);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GenerateMips)
        void (STDMETHODCALLTYPE* GenerateMips)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11ShaderResourceView* pShaderResourceView);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, SetResourceMinLOD)
        void (STDMETHODCALLTYPE* SetResourceMinLOD)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11Resource* pResource,
            FLOAT MinLOD);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GetResourceMinLOD)
        FLOAT(STDMETHODCALLTYPE* GetResourceMinLOD)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11Resource* pResource);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, ResolveSubresource)
        void (STDMETHODCALLTYPE* ResolveSubresource)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11Resource* pDstResource,
            /* [annotation] */
            _In_  UINT DstSubresource,
            /* [annotation] */
            _In_  ID3D11Resource* pSrcResource,
            /* [annotation] */
            _In_  UINT SrcSubresource,
            /* [annotation] */
            _In_  DXGI_FORMAT Format);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, ExecuteCommandList)
        void (STDMETHODCALLTYPE* ExecuteCommandList)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_  ID3D11CommandList* pCommandList,
            BOOL RestoreContextState);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, HSSetShaderResources)
        void (STDMETHODCALLTYPE* HSSetShaderResources)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, HSSetShader)
        void (STDMETHODCALLTYPE* HSSetShader)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_opt_  ID3D11HullShader* pHullShader,
            /* [annotation] */
            _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
            UINT NumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, HSSetSamplers)
        void (STDMETHODCALLTYPE* HSSetSamplers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, HSSetConstantBuffers)
        void (STDMETHODCALLTYPE* HSSetConstantBuffers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DSSetShaderResources)
        void (STDMETHODCALLTYPE* DSSetShaderResources)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DSSetShader)
        void (STDMETHODCALLTYPE* DSSetShader)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_opt_  ID3D11DomainShader* pDomainShader,
            /* [annotation] */
            _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
            UINT NumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DSSetSamplers)
        void (STDMETHODCALLTYPE* DSSetSamplers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DSSetConstantBuffers)
        void (STDMETHODCALLTYPE* DSSetConstantBuffers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSSetShaderResources)
        void (STDMETHODCALLTYPE* CSSetShaderResources)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSSetUnorderedAccessViews)
        void (STDMETHODCALLTYPE* CSSetUnorderedAccessViews)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_1_UAV_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_1_UAV_SLOT_COUNT - StartSlot)  UINT NumUAVs,
            /* [annotation] */
            _In_reads_opt_(NumUAVs)  ID3D11UnorderedAccessView* const* ppUnorderedAccessViews,
            /* [annotation] */
            _In_reads_opt_(NumUAVs)  const UINT* pUAVInitialCounts);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSSetShader)
        void (STDMETHODCALLTYPE* CSSetShader)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_opt_  ID3D11ComputeShader* pComputeShader,
            /* [annotation] */
            _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
            UINT NumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSSetSamplers)
        void (STDMETHODCALLTYPE* CSSetSamplers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSSetConstantBuffers)
        void (STDMETHODCALLTYPE* CSSetConstantBuffers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, VSGetConstantBuffers)
        void (STDMETHODCALLTYPE* VSGetConstantBuffers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, PSGetShaderResources)
        void (STDMETHODCALLTYPE* PSGetShaderResources)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, PSGetShader)
        void (STDMETHODCALLTYPE* PSGetShader)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _Outptr_result_maybenull_  ID3D11PixelShader** ppPixelShader,
            /* [annotation] */
            _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
            /* [annotation] */
            _Inout_opt_  UINT* pNumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, PSGetSamplers)
        void (STDMETHODCALLTYPE* PSGetSamplers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, VSGetShader)
        void (STDMETHODCALLTYPE* VSGetShader)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _Outptr_result_maybenull_  ID3D11VertexShader** ppVertexShader,
            /* [annotation] */
            _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
            /* [annotation] */
            _Inout_opt_  UINT* pNumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, PSGetConstantBuffers)
        void (STDMETHODCALLTYPE* PSGetConstantBuffers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, IAGetInputLayout)
        void (STDMETHODCALLTYPE* IAGetInputLayout)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _Outptr_result_maybenull_  ID3D11InputLayout** ppInputLayout);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, IAGetVertexBuffers)
        void (STDMETHODCALLTYPE* IAGetVertexBuffers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppVertexBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  UINT* pStrides,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  UINT* pOffsets);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, IAGetIndexBuffer)
        void (STDMETHODCALLTYPE* IAGetIndexBuffer)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _Outptr_opt_result_maybenull_  ID3D11Buffer** pIndexBuffer,
            /* [annotation] */
            _Out_opt_  DXGI_FORMAT* Format,
            /* [annotation] */
            _Out_opt_  UINT* Offset);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GSGetConstantBuffers)
        void (STDMETHODCALLTYPE* GSGetConstantBuffers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GSGetShader)
        void (STDMETHODCALLTYPE* GSGetShader)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _Outptr_result_maybenull_  ID3D11GeometryShader** ppGeometryShader,
            /* [annotation] */
            _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
            /* [annotation] */
            _Inout_opt_  UINT* pNumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, IAGetPrimitiveTopology)
        void (STDMETHODCALLTYPE* IAGetPrimitiveTopology)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _Out_  D3D11_PRIMITIVE_TOPOLOGY* pTopology);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, VSGetShaderResources)
        void (STDMETHODCALLTYPE* VSGetShaderResources)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, VSGetSamplers)
        void (STDMETHODCALLTYPE* VSGetSamplers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GetPredication)
        void (STDMETHODCALLTYPE* GetPredication)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _Outptr_opt_result_maybenull_  ID3D11Predicate** ppPredicate,
            /* [annotation] */
            _Out_opt_  BOOL* pPredicateValue);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GSGetShaderResources)
        void (STDMETHODCALLTYPE* GSGetShaderResources)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GSGetSamplers)
        void (STDMETHODCALLTYPE* GSGetSamplers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, OMGetRenderTargets)
        void (STDMETHODCALLTYPE* OMGetRenderTargets)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT)  UINT NumViews,
            /* [annotation] */
            _Out_writes_opt_(NumViews)  ID3D11RenderTargetView** ppRenderTargetViews,
            /* [annotation] */
            _Outptr_opt_result_maybenull_  ID3D11DepthStencilView** ppDepthStencilView);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, OMGetRenderTargetsAndUnorderedAccessViews)
        void (STDMETHODCALLTYPE* OMGetRenderTargetsAndUnorderedAccessViews)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT)  UINT NumRTVs,
            /* [annotation] */
            _Out_writes_opt_(NumRTVs)  ID3D11RenderTargetView** ppRenderTargetViews,
            /* [annotation] */
            _Outptr_opt_result_maybenull_  ID3D11DepthStencilView** ppDepthStencilView,
            /* [annotation] */
            _In_range_(0, D3D11_PS_CS_UAV_REGISTER_COUNT - 1)  UINT UAVStartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_PS_CS_UAV_REGISTER_COUNT - UAVStartSlot)  UINT NumUAVs,
            /* [annotation] */
            _Out_writes_opt_(NumUAVs)  ID3D11UnorderedAccessView** ppUnorderedAccessViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, OMGetBlendState)
        void (STDMETHODCALLTYPE* OMGetBlendState)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _Outptr_opt_result_maybenull_  ID3D11BlendState** ppBlendState,
            /* [annotation] */
            _Out_opt_  FLOAT BlendFactor[4],
            /* [annotation] */
            _Out_opt_  UINT* pSampleMask);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, OMGetDepthStencilState)
        void (STDMETHODCALLTYPE* OMGetDepthStencilState)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _Outptr_opt_result_maybenull_  ID3D11DepthStencilState** ppDepthStencilState,
            /* [annotation] */
            _Out_opt_  UINT* pStencilRef);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, SOGetTargets)
        void (STDMETHODCALLTYPE* SOGetTargets)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_SO_BUFFER_SLOT_COUNT)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppSOTargets);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, RSGetState)
        void (STDMETHODCALLTYPE* RSGetState)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _Outptr_result_maybenull_  ID3D11RasterizerState** ppRasterizerState);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, RSGetViewports)
        void (STDMETHODCALLTYPE* RSGetViewports)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _Inout_ /*_range(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE )*/   UINT* pNumViewports,
            /* [annotation] */
            _Out_writes_opt_(*pNumViewports)  D3D11_VIEWPORT* pViewports);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, RSGetScissorRects)
        void (STDMETHODCALLTYPE* RSGetScissorRects)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _Inout_ /*_range(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE )*/   UINT* pNumRects,
            /* [annotation] */
            _Out_writes_opt_(*pNumRects)  D3D11_RECT* pRects);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, HSGetShaderResources)
        void (STDMETHODCALLTYPE* HSGetShaderResources)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, HSGetShader)
        void (STDMETHODCALLTYPE* HSGetShader)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _Outptr_result_maybenull_  ID3D11HullShader** ppHullShader,
            /* [annotation] */
            _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
            /* [annotation] */
            _Inout_opt_  UINT* pNumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, HSGetSamplers)
        void (STDMETHODCALLTYPE* HSGetSamplers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, HSGetConstantBuffers)
        void (STDMETHODCALLTYPE* HSGetConstantBuffers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DSGetShaderResources)
        void (STDMETHODCALLTYPE* DSGetShaderResources)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DSGetShader)
        void (STDMETHODCALLTYPE* DSGetShader)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _Outptr_result_maybenull_  ID3D11DomainShader** ppDomainShader,
            /* [annotation] */
            _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
            /* [annotation] */
            _Inout_opt_  UINT* pNumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DSGetSamplers)
        void (STDMETHODCALLTYPE* DSGetSamplers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DSGetConstantBuffers)
        void (STDMETHODCALLTYPE* DSGetConstantBuffers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSGetShaderResources)
        void (STDMETHODCALLTYPE* CSGetShaderResources)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSGetUnorderedAccessViews)
        void (STDMETHODCALLTYPE* CSGetUnorderedAccessViews)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_1_UAV_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_1_UAV_SLOT_COUNT - StartSlot)  UINT NumUAVs,
            /* [annotation] */
            _Out_writes_opt_(NumUAVs)  ID3D11UnorderedAccessView** ppUnorderedAccessViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSGetShader)
        void (STDMETHODCALLTYPE* CSGetShader)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _Outptr_result_maybenull_  ID3D11ComputeShader** ppComputeShader,
            /* [annotation] */
            _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
            /* [annotation] */
            _Inout_opt_  UINT* pNumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSGetSamplers)
        void (STDMETHODCALLTYPE* CSGetSamplers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSGetConstantBuffers)
        void (STDMETHODCALLTYPE* CSGetConstantBuffers)(
            ID3D11DeviceContext* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, ClearState)
        void (STDMETHODCALLTYPE* ClearState)(
            ID3D11DeviceContext* This);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, Flush)
        void (STDMETHODCALLTYPE* Flush)(
            ID3D11DeviceContext* This);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GetType)
        D3D11_DEVICE_CONTEXT_TYPE(STDMETHODCALLTYPE* GetType)(
            ID3D11DeviceContext* This);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GetContextFlags)
        UINT(STDMETHODCALLTYPE* GetContextFlags)(
            ID3D11DeviceContext* This);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, FinishCommandList)
        HRESULT(STDMETHODCALLTYPE* FinishCommandList)(
            ID3D11DeviceContext* This,
            BOOL RestoreDeferredContextState,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11CommandList** ppCommandList);

    END_INTERFACE
} ID3D11DeviceContextVtbl;

interface ID3D11DeviceContextVT
{
    CONST_VTBL struct ID3D11DeviceContextVtbl* lpVtbl;
};

typedef struct ID3D11DeviceContext1Vtbl
{
    BEGIN_INTERFACE

        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT(STDMETHODCALLTYPE* QueryInterface)(
            ID3D11DeviceContext1* This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */
            _COM_Outptr_  void** ppvObject);

    DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG(STDMETHODCALLTYPE* AddRef)(
            ID3D11DeviceContext1* This);

    DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG(STDMETHODCALLTYPE* Release)(
            ID3D11DeviceContext1* This);

    DECLSPEC_XFGVIRT(ID3D11DeviceChild, GetDevice)
        void (STDMETHODCALLTYPE* GetDevice)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _Outptr_  ID3D11Device** ppDevice);

    DECLSPEC_XFGVIRT(ID3D11DeviceChild, GetPrivateData)
        HRESULT(STDMETHODCALLTYPE* GetPrivateData)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  REFGUID guid,
            /* [annotation] */
            _Inout_  UINT* pDataSize,
            /* [annotation] */
            _Out_writes_bytes_opt_(*pDataSize)  void* pData);

    DECLSPEC_XFGVIRT(ID3D11DeviceChild, SetPrivateData)
        HRESULT(STDMETHODCALLTYPE* SetPrivateData)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  REFGUID guid,
            /* [annotation] */
            _In_  UINT DataSize,
            /* [annotation] */
            _In_reads_bytes_opt_(DataSize)  const void* pData);

    DECLSPEC_XFGVIRT(ID3D11DeviceChild, SetPrivateDataInterface)
        HRESULT(STDMETHODCALLTYPE* SetPrivateDataInterface)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  REFGUID guid,
            /* [annotation] */
            _In_opt_  const IUnknown* pData);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, VSSetConstantBuffers)
        void (STDMETHODCALLTYPE* VSSetConstantBuffers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, PSSetShaderResources)
        void (STDMETHODCALLTYPE* PSSetShaderResources)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, PSSetShader)
        void (STDMETHODCALLTYPE* PSSetShader)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_opt_  ID3D11PixelShader* pPixelShader,
            /* [annotation] */
            _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
            UINT NumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, PSSetSamplers)
        void (STDMETHODCALLTYPE* PSSetSamplers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, VSSetShader)
        void (STDMETHODCALLTYPE* VSSetShader)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_opt_  ID3D11VertexShader* pVertexShader,
            /* [annotation] */
            _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
            UINT NumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DrawIndexed)
        void (STDMETHODCALLTYPE* DrawIndexed)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  UINT IndexCount,
            /* [annotation] */
            _In_  UINT StartIndexLocation,
            /* [annotation] */
            _In_  INT BaseVertexLocation);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, Draw)
        void (STDMETHODCALLTYPE* Draw)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  UINT VertexCount,
            /* [annotation] */
            _In_  UINT StartVertexLocation);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, Map)
        HRESULT(STDMETHODCALLTYPE* Map)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Resource* pResource,
            /* [annotation] */
            _In_  UINT Subresource,
            /* [annotation] */
            _In_  D3D11_MAP MapType,
            /* [annotation] */
            _In_  UINT MapFlags,
            /* [annotation] */
            _Out_opt_  D3D11_MAPPED_SUBRESOURCE* pMappedResource);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, Unmap)
        void (STDMETHODCALLTYPE* Unmap)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Resource* pResource,
            /* [annotation] */
            _In_  UINT Subresource);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, PSSetConstantBuffers)
        void (STDMETHODCALLTYPE* PSSetConstantBuffers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, IASetInputLayout)
        void (STDMETHODCALLTYPE* IASetInputLayout)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_opt_  ID3D11InputLayout* pInputLayout);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, IASetVertexBuffers)
        void (STDMETHODCALLTYPE* IASetVertexBuffers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppVertexBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pStrides,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pOffsets);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, IASetIndexBuffer)
        void (STDMETHODCALLTYPE* IASetIndexBuffer)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_opt_  ID3D11Buffer* pIndexBuffer,
            /* [annotation] */
            _In_  DXGI_FORMAT Format,
            /* [annotation] */
            _In_  UINT Offset);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DrawIndexedInstanced)
        void (STDMETHODCALLTYPE* DrawIndexedInstanced)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  UINT IndexCountPerInstance,
            /* [annotation] */
            _In_  UINT InstanceCount,
            /* [annotation] */
            _In_  UINT StartIndexLocation,
            /* [annotation] */
            _In_  INT BaseVertexLocation,
            /* [annotation] */
            _In_  UINT StartInstanceLocation);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DrawInstanced)
        void (STDMETHODCALLTYPE* DrawInstanced)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  UINT VertexCountPerInstance,
            /* [annotation] */
            _In_  UINT InstanceCount,
            /* [annotation] */
            _In_  UINT StartVertexLocation,
            /* [annotation] */
            _In_  UINT StartInstanceLocation);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GSSetConstantBuffers)
        void (STDMETHODCALLTYPE* GSSetConstantBuffers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GSSetShader)
        void (STDMETHODCALLTYPE* GSSetShader)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_opt_  ID3D11GeometryShader* pShader,
            /* [annotation] */
            _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
            UINT NumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, IASetPrimitiveTopology)
        void (STDMETHODCALLTYPE* IASetPrimitiveTopology)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  D3D11_PRIMITIVE_TOPOLOGY Topology);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, VSSetShaderResources)
        void (STDMETHODCALLTYPE* VSSetShaderResources)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, VSSetSamplers)
        void (STDMETHODCALLTYPE* VSSetSamplers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, Begin)
        void (STDMETHODCALLTYPE* Begin)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Asynchronous* pAsync);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, End)
        void (STDMETHODCALLTYPE* End)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Asynchronous* pAsync);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GetData)
        HRESULT(STDMETHODCALLTYPE* GetData)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Asynchronous* pAsync,
            /* [annotation] */
            _Out_writes_bytes_opt_(DataSize)  void* pData,
            /* [annotation] */
            _In_  UINT DataSize,
            /* [annotation] */
            _In_  UINT GetDataFlags);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, SetPredication)
        void (STDMETHODCALLTYPE* SetPredication)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_opt_  ID3D11Predicate* pPredicate,
            /* [annotation] */
            _In_  BOOL PredicateValue);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GSSetShaderResources)
        void (STDMETHODCALLTYPE* GSSetShaderResources)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GSSetSamplers)
        void (STDMETHODCALLTYPE* GSSetSamplers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, OMSetRenderTargets)
        void (STDMETHODCALLTYPE* OMSetRenderTargets)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT)  UINT NumViews,
            /* [annotation] */
            _In_reads_opt_(NumViews)  ID3D11RenderTargetView* const* ppRenderTargetViews,
            /* [annotation] */
            _In_opt_  ID3D11DepthStencilView* pDepthStencilView);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, OMSetRenderTargetsAndUnorderedAccessViews)
        void (STDMETHODCALLTYPE* OMSetRenderTargetsAndUnorderedAccessViews)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  UINT NumRTVs,
            /* [annotation] */
            _In_reads_opt_(NumRTVs)  ID3D11RenderTargetView* const* ppRenderTargetViews,
            /* [annotation] */
            _In_opt_  ID3D11DepthStencilView* pDepthStencilView,
            /* [annotation] */
            _In_range_(0, D3D11_1_UAV_SLOT_COUNT - 1)  UINT UAVStartSlot,
            /* [annotation] */
            _In_  UINT NumUAVs,
            /* [annotation] */
            _In_reads_opt_(NumUAVs)  ID3D11UnorderedAccessView* const* ppUnorderedAccessViews,
            /* [annotation] */
            _In_reads_opt_(NumUAVs)  const UINT* pUAVInitialCounts);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, OMSetBlendState)
        void (STDMETHODCALLTYPE* OMSetBlendState)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_opt_  ID3D11BlendState* pBlendState,
            /* [annotation] */
            _In_opt_  const FLOAT BlendFactor[4],
            /* [annotation] */
            _In_  UINT SampleMask);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, OMSetDepthStencilState)
        void (STDMETHODCALLTYPE* OMSetDepthStencilState)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_opt_  ID3D11DepthStencilState* pDepthStencilState,
            /* [annotation] */
            _In_  UINT StencilRef);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, SOSetTargets)
        void (STDMETHODCALLTYPE* SOSetTargets)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_SO_BUFFER_SLOT_COUNT)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppSOTargets,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pOffsets);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DrawAuto)
        void (STDMETHODCALLTYPE* DrawAuto)(
            ID3D11DeviceContext1* This);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DrawIndexedInstancedIndirect)
        void (STDMETHODCALLTYPE* DrawIndexedInstancedIndirect)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Buffer* pBufferForArgs,
            /* [annotation] */
            _In_  UINT AlignedByteOffsetForArgs);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DrawInstancedIndirect)
        void (STDMETHODCALLTYPE* DrawInstancedIndirect)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Buffer* pBufferForArgs,
            /* [annotation] */
            _In_  UINT AlignedByteOffsetForArgs);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, Dispatch)
        void (STDMETHODCALLTYPE* Dispatch)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  UINT ThreadGroupCountX,
            /* [annotation] */
            _In_  UINT ThreadGroupCountY,
            /* [annotation] */
            _In_  UINT ThreadGroupCountZ);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DispatchIndirect)
        void (STDMETHODCALLTYPE* DispatchIndirect)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Buffer* pBufferForArgs,
            /* [annotation] */
            _In_  UINT AlignedByteOffsetForArgs);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, RSSetState)
        void (STDMETHODCALLTYPE* RSSetState)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_opt_  ID3D11RasterizerState* pRasterizerState);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, RSSetViewports)
        void (STDMETHODCALLTYPE* RSSetViewports)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE)  UINT NumViewports,
            /* [annotation] */
            _In_reads_opt_(NumViewports)  const D3D11_VIEWPORT* pViewports);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, RSSetScissorRects)
        void (STDMETHODCALLTYPE* RSSetScissorRects)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE)  UINT NumRects,
            /* [annotation] */
            _In_reads_opt_(NumRects)  const D3D11_RECT* pRects);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CopySubresourceRegion)
        void (STDMETHODCALLTYPE* CopySubresourceRegion)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Resource* pDstResource,
            /* [annotation] */
            _In_  UINT DstSubresource,
            /* [annotation] */
            _In_  UINT DstX,
            /* [annotation] */
            _In_  UINT DstY,
            /* [annotation] */
            _In_  UINT DstZ,
            /* [annotation] */
            _In_  ID3D11Resource* pSrcResource,
            /* [annotation] */
            _In_  UINT SrcSubresource,
            /* [annotation] */
            _In_opt_  const D3D11_BOX* pSrcBox);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CopyResource)
        void (STDMETHODCALLTYPE* CopyResource)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Resource* pDstResource,
            /* [annotation] */
            _In_  ID3D11Resource* pSrcResource);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, UpdateSubresource)
        void (STDMETHODCALLTYPE* UpdateSubresource)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Resource* pDstResource,
            /* [annotation] */
            _In_  UINT DstSubresource,
            /* [annotation] */
            _In_opt_  const D3D11_BOX* pDstBox,
            /* [annotation] */
            _In_  const void* pSrcData,
            /* [annotation] */
            _In_  UINT SrcRowPitch,
            /* [annotation] */
            _In_  UINT SrcDepthPitch);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CopyStructureCount)
        void (STDMETHODCALLTYPE* CopyStructureCount)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Buffer* pDstBuffer,
            /* [annotation] */
            _In_  UINT DstAlignedByteOffset,
            /* [annotation] */
            _In_  ID3D11UnorderedAccessView* pSrcView);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, ClearRenderTargetView)
        void (STDMETHODCALLTYPE* ClearRenderTargetView)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11RenderTargetView* pRenderTargetView,
            /* [annotation] */
            _In_  const FLOAT ColorRGBA[4]);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, ClearUnorderedAccessViewUint)
        void (STDMETHODCALLTYPE* ClearUnorderedAccessViewUint)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11UnorderedAccessView* pUnorderedAccessView,
            /* [annotation] */
            _In_  const UINT Values[4]);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, ClearUnorderedAccessViewFloat)
        void (STDMETHODCALLTYPE* ClearUnorderedAccessViewFloat)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11UnorderedAccessView* pUnorderedAccessView,
            /* [annotation] */
            _In_  const FLOAT Values[4]);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, ClearDepthStencilView)
        void (STDMETHODCALLTYPE* ClearDepthStencilView)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11DepthStencilView* pDepthStencilView,
            /* [annotation] */
            _In_  UINT ClearFlags,
            /* [annotation] */
            _In_  FLOAT Depth,
            /* [annotation] */
            _In_  UINT8 Stencil);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GenerateMips)
        void (STDMETHODCALLTYPE* GenerateMips)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11ShaderResourceView* pShaderResourceView);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, SetResourceMinLOD)
        void (STDMETHODCALLTYPE* SetResourceMinLOD)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Resource* pResource,
            FLOAT MinLOD);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GetResourceMinLOD)
        FLOAT(STDMETHODCALLTYPE* GetResourceMinLOD)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Resource* pResource);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, ResolveSubresource)
        void (STDMETHODCALLTYPE* ResolveSubresource)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Resource* pDstResource,
            /* [annotation] */
            _In_  UINT DstSubresource,
            /* [annotation] */
            _In_  ID3D11Resource* pSrcResource,
            /* [annotation] */
            _In_  UINT SrcSubresource,
            /* [annotation] */
            _In_  DXGI_FORMAT Format);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, ExecuteCommandList)
        void (STDMETHODCALLTYPE* ExecuteCommandList)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11CommandList* pCommandList,
            BOOL RestoreContextState);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, HSSetShaderResources)
        void (STDMETHODCALLTYPE* HSSetShaderResources)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, HSSetShader)
        void (STDMETHODCALLTYPE* HSSetShader)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_opt_  ID3D11HullShader* pHullShader,
            /* [annotation] */
            _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
            UINT NumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, HSSetSamplers)
        void (STDMETHODCALLTYPE* HSSetSamplers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, HSSetConstantBuffers)
        void (STDMETHODCALLTYPE* HSSetConstantBuffers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DSSetShaderResources)
        void (STDMETHODCALLTYPE* DSSetShaderResources)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DSSetShader)
        void (STDMETHODCALLTYPE* DSSetShader)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_opt_  ID3D11DomainShader* pDomainShader,
            /* [annotation] */
            _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
            UINT NumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DSSetSamplers)
        void (STDMETHODCALLTYPE* DSSetSamplers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DSSetConstantBuffers)
        void (STDMETHODCALLTYPE* DSSetConstantBuffers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSSetShaderResources)
        void (STDMETHODCALLTYPE* CSSetShaderResources)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _In_reads_opt_(NumViews)  ID3D11ShaderResourceView* const* ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSSetUnorderedAccessViews)
        void (STDMETHODCALLTYPE* CSSetUnorderedAccessViews)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_1_UAV_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_1_UAV_SLOT_COUNT - StartSlot)  UINT NumUAVs,
            /* [annotation] */
            _In_reads_opt_(NumUAVs)  ID3D11UnorderedAccessView* const* ppUnorderedAccessViews,
            /* [annotation] */
            _In_reads_opt_(NumUAVs)  const UINT* pUAVInitialCounts);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSSetShader)
        void (STDMETHODCALLTYPE* CSSetShader)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_opt_  ID3D11ComputeShader* pComputeShader,
            /* [annotation] */
            _In_reads_opt_(NumClassInstances)  ID3D11ClassInstance* const* ppClassInstances,
            UINT NumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSSetSamplers)
        void (STDMETHODCALLTYPE* CSSetSamplers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _In_reads_opt_(NumSamplers)  ID3D11SamplerState* const* ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSSetConstantBuffers)
        void (STDMETHODCALLTYPE* CSSetConstantBuffers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, VSGetConstantBuffers)
        void (STDMETHODCALLTYPE* VSGetConstantBuffers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, PSGetShaderResources)
        void (STDMETHODCALLTYPE* PSGetShaderResources)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, PSGetShader)
        void (STDMETHODCALLTYPE* PSGetShader)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _Outptr_result_maybenull_  ID3D11PixelShader** ppPixelShader,
            /* [annotation] */
            _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
            /* [annotation] */
            _Inout_opt_  UINT* pNumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, PSGetSamplers)
        void (STDMETHODCALLTYPE* PSGetSamplers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, VSGetShader)
        void (STDMETHODCALLTYPE* VSGetShader)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _Outptr_result_maybenull_  ID3D11VertexShader** ppVertexShader,
            /* [annotation] */
            _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
            /* [annotation] */
            _Inout_opt_  UINT* pNumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, PSGetConstantBuffers)
        void (STDMETHODCALLTYPE* PSGetConstantBuffers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, IAGetInputLayout)
        void (STDMETHODCALLTYPE* IAGetInputLayout)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _Outptr_result_maybenull_  ID3D11InputLayout** ppInputLayout);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, IAGetVertexBuffers)
        void (STDMETHODCALLTYPE* IAGetVertexBuffers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppVertexBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  UINT* pStrides,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  UINT* pOffsets);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, IAGetIndexBuffer)
        void (STDMETHODCALLTYPE* IAGetIndexBuffer)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _Outptr_opt_result_maybenull_  ID3D11Buffer** pIndexBuffer,
            /* [annotation] */
            _Out_opt_  DXGI_FORMAT* Format,
            /* [annotation] */
            _Out_opt_  UINT* Offset);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GSGetConstantBuffers)
        void (STDMETHODCALLTYPE* GSGetConstantBuffers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GSGetShader)
        void (STDMETHODCALLTYPE* GSGetShader)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _Outptr_result_maybenull_  ID3D11GeometryShader** ppGeometryShader,
            /* [annotation] */
            _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
            /* [annotation] */
            _Inout_opt_  UINT* pNumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, IAGetPrimitiveTopology)
        void (STDMETHODCALLTYPE* IAGetPrimitiveTopology)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _Out_  D3D11_PRIMITIVE_TOPOLOGY* pTopology);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, VSGetShaderResources)
        void (STDMETHODCALLTYPE* VSGetShaderResources)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, VSGetSamplers)
        void (STDMETHODCALLTYPE* VSGetSamplers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GetPredication)
        void (STDMETHODCALLTYPE* GetPredication)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _Outptr_opt_result_maybenull_  ID3D11Predicate** ppPredicate,
            /* [annotation] */
            _Out_opt_  BOOL* pPredicateValue);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GSGetShaderResources)
        void (STDMETHODCALLTYPE* GSGetShaderResources)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GSGetSamplers)
        void (STDMETHODCALLTYPE* GSGetSamplers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, OMGetRenderTargets)
        void (STDMETHODCALLTYPE* OMGetRenderTargets)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT)  UINT NumViews,
            /* [annotation] */
            _Out_writes_opt_(NumViews)  ID3D11RenderTargetView** ppRenderTargetViews,
            /* [annotation] */
            _Outptr_opt_result_maybenull_  ID3D11DepthStencilView** ppDepthStencilView);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, OMGetRenderTargetsAndUnorderedAccessViews)
        void (STDMETHODCALLTYPE* OMGetRenderTargetsAndUnorderedAccessViews)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT)  UINT NumRTVs,
            /* [annotation] */
            _Out_writes_opt_(NumRTVs)  ID3D11RenderTargetView** ppRenderTargetViews,
            /* [annotation] */
            _Outptr_opt_result_maybenull_  ID3D11DepthStencilView** ppDepthStencilView,
            /* [annotation] */
            _In_range_(0, D3D11_PS_CS_UAV_REGISTER_COUNT - 1)  UINT UAVStartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_PS_CS_UAV_REGISTER_COUNT - UAVStartSlot)  UINT NumUAVs,
            /* [annotation] */
            _Out_writes_opt_(NumUAVs)  ID3D11UnorderedAccessView** ppUnorderedAccessViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, OMGetBlendState)
        void (STDMETHODCALLTYPE* OMGetBlendState)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _Outptr_opt_result_maybenull_  ID3D11BlendState** ppBlendState,
            /* [annotation] */
            _Out_opt_  FLOAT BlendFactor[4],
            /* [annotation] */
            _Out_opt_  UINT* pSampleMask);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, OMGetDepthStencilState)
        void (STDMETHODCALLTYPE* OMGetDepthStencilState)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _Outptr_opt_result_maybenull_  ID3D11DepthStencilState** ppDepthStencilState,
            /* [annotation] */
            _Out_opt_  UINT* pStencilRef);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, SOGetTargets)
        void (STDMETHODCALLTYPE* SOGetTargets)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_SO_BUFFER_SLOT_COUNT)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppSOTargets);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, RSGetState)
        void (STDMETHODCALLTYPE* RSGetState)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _Outptr_result_maybenull_  ID3D11RasterizerState** ppRasterizerState);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, RSGetViewports)
        void (STDMETHODCALLTYPE* RSGetViewports)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _Inout_ /*_range(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE )*/   UINT* pNumViewports,
            /* [annotation] */
            _Out_writes_opt_(*pNumViewports)  D3D11_VIEWPORT* pViewports);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, RSGetScissorRects)
        void (STDMETHODCALLTYPE* RSGetScissorRects)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _Inout_ /*_range(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE )*/   UINT* pNumRects,
            /* [annotation] */
            _Out_writes_opt_(*pNumRects)  D3D11_RECT* pRects);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, HSGetShaderResources)
        void (STDMETHODCALLTYPE* HSGetShaderResources)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, HSGetShader)
        void (STDMETHODCALLTYPE* HSGetShader)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _Outptr_result_maybenull_  ID3D11HullShader** ppHullShader,
            /* [annotation] */
            _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
            /* [annotation] */
            _Inout_opt_  UINT* pNumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, HSGetSamplers)
        void (STDMETHODCALLTYPE* HSGetSamplers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, HSGetConstantBuffers)
        void (STDMETHODCALLTYPE* HSGetConstantBuffers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DSGetShaderResources)
        void (STDMETHODCALLTYPE* DSGetShaderResources)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DSGetShader)
        void (STDMETHODCALLTYPE* DSGetShader)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _Outptr_result_maybenull_  ID3D11DomainShader** ppDomainShader,
            /* [annotation] */
            _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
            /* [annotation] */
            _Inout_opt_  UINT* pNumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DSGetSamplers)
        void (STDMETHODCALLTYPE* DSGetSamplers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, DSGetConstantBuffers)
        void (STDMETHODCALLTYPE* DSGetConstantBuffers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSGetShaderResources)
        void (STDMETHODCALLTYPE* CSGetShaderResources)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
            /* [annotation] */
            _Out_writes_opt_(NumViews)  ID3D11ShaderResourceView** ppShaderResourceViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSGetUnorderedAccessViews)
        void (STDMETHODCALLTYPE* CSGetUnorderedAccessViews)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_1_UAV_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_1_UAV_SLOT_COUNT - StartSlot)  UINT NumUAVs,
            /* [annotation] */
            _Out_writes_opt_(NumUAVs)  ID3D11UnorderedAccessView** ppUnorderedAccessViews);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSGetShader)
        void (STDMETHODCALLTYPE* CSGetShader)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _Outptr_result_maybenull_  ID3D11ComputeShader** ppComputeShader,
            /* [annotation] */
            _Out_writes_opt_(*pNumClassInstances)  ID3D11ClassInstance** ppClassInstances,
            /* [annotation] */
            _Inout_opt_  UINT* pNumClassInstances);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSGetSamplers)
        void (STDMETHODCALLTYPE* CSGetSamplers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
            /* [annotation] */
            _Out_writes_opt_(NumSamplers)  ID3D11SamplerState** ppSamplers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, CSGetConstantBuffers)
        void (STDMETHODCALLTYPE* CSGetConstantBuffers)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, ClearState)
        void (STDMETHODCALLTYPE* ClearState)(
            ID3D11DeviceContext1* This);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, Flush)
        void (STDMETHODCALLTYPE* Flush)(
            ID3D11DeviceContext1* This);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GetType)
        D3D11_DEVICE_CONTEXT_TYPE(STDMETHODCALLTYPE* GetType)(
            ID3D11DeviceContext1* This);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, GetContextFlags)
        UINT(STDMETHODCALLTYPE* GetContextFlags)(
            ID3D11DeviceContext1* This);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext, FinishCommandList)
        HRESULT(STDMETHODCALLTYPE* FinishCommandList)(
            ID3D11DeviceContext1* This,
            BOOL RestoreDeferredContextState,
            /* [annotation] */
            _COM_Outptr_opt_  ID3D11CommandList** ppCommandList);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, CopySubresourceRegion1)
        void (STDMETHODCALLTYPE* CopySubresourceRegion1)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Resource* pDstResource,
            /* [annotation] */
            _In_  UINT DstSubresource,
            /* [annotation] */
            _In_  UINT DstX,
            /* [annotation] */
            _In_  UINT DstY,
            /* [annotation] */
            _In_  UINT DstZ,
            /* [annotation] */
            _In_  ID3D11Resource* pSrcResource,
            /* [annotation] */
            _In_  UINT SrcSubresource,
            /* [annotation] */
            _In_opt_  const D3D11_BOX* pSrcBox,
            /* [annotation] */
            _In_  UINT CopyFlags);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, UpdateSubresource1)
        void (STDMETHODCALLTYPE* UpdateSubresource1)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Resource* pDstResource,
            /* [annotation] */
            _In_  UINT DstSubresource,
            /* [annotation] */
            _In_opt_  const D3D11_BOX* pDstBox,
            /* [annotation] */
            _In_  const void* pSrcData,
            /* [annotation] */
            _In_  UINT SrcRowPitch,
            /* [annotation] */
            _In_  UINT SrcDepthPitch,
            /* [annotation] */
            _In_  UINT CopyFlags);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, DiscardResource)
        void (STDMETHODCALLTYPE* DiscardResource)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11Resource* pResource);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, DiscardView)
        void (STDMETHODCALLTYPE* DiscardView)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11View* pResourceView);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, VSSetConstantBuffers1)
        void (STDMETHODCALLTYPE* VSSetConstantBuffers1)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pFirstConstant,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pNumConstants);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, HSSetConstantBuffers1)
        void (STDMETHODCALLTYPE* HSSetConstantBuffers1)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pFirstConstant,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pNumConstants);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, DSSetConstantBuffers1)
        void (STDMETHODCALLTYPE* DSSetConstantBuffers1)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pFirstConstant,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pNumConstants);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, GSSetConstantBuffers1)
        void (STDMETHODCALLTYPE* GSSetConstantBuffers1)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pFirstConstant,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pNumConstants);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, PSSetConstantBuffers1)
        void (STDMETHODCALLTYPE* PSSetConstantBuffers1)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pFirstConstant,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pNumConstants);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, CSSetConstantBuffers1)
        void (STDMETHODCALLTYPE* CSSetConstantBuffers1)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  ID3D11Buffer* const* ppConstantBuffers,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pFirstConstant,
            /* [annotation] */
            _In_reads_opt_(NumBuffers)  const UINT* pNumConstants);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, VSGetConstantBuffers1)
        void (STDMETHODCALLTYPE* VSGetConstantBuffers1)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  UINT* pFirstConstant,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  UINT* pNumConstants);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, HSGetConstantBuffers1)
        void (STDMETHODCALLTYPE* HSGetConstantBuffers1)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  UINT* pFirstConstant,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  UINT* pNumConstants);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, DSGetConstantBuffers1)
        void (STDMETHODCALLTYPE* DSGetConstantBuffers1)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  UINT* pFirstConstant,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  UINT* pNumConstants);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, GSGetConstantBuffers1)
        void (STDMETHODCALLTYPE* GSGetConstantBuffers1)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  UINT* pFirstConstant,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  UINT* pNumConstants);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, PSGetConstantBuffers1)
        void (STDMETHODCALLTYPE* PSGetConstantBuffers1)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  UINT* pFirstConstant,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  UINT* pNumConstants);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, CSGetConstantBuffers1)
        void (STDMETHODCALLTYPE* CSGetConstantBuffers1)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
            /* [annotation] */
            _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  ID3D11Buffer** ppConstantBuffers,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  UINT* pFirstConstant,
            /* [annotation] */
            _Out_writes_opt_(NumBuffers)  UINT* pNumConstants);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, SwapDeviceContextState)
        void (STDMETHODCALLTYPE* SwapDeviceContextState)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3DDeviceContextState* pState,
            /* [annotation] */
            _Outptr_opt_  ID3DDeviceContextState** ppPreviousState);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, ClearView)
        void (STDMETHODCALLTYPE* ClearView)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11View* pView,
            /* [annotation] */
            _In_  const FLOAT Color[4],
            /* [annotation] */
            _In_reads_opt_(NumRects)  const D3D11_RECT* pRect,
            UINT NumRects);

    DECLSPEC_XFGVIRT(ID3D11DeviceContext1, DiscardView1)
        void (STDMETHODCALLTYPE* DiscardView1)(
            ID3D11DeviceContext1* This,
            /* [annotation] */
            _In_  ID3D11View* pResourceView,
            /* [annotation] */
            _In_reads_opt_(NumRects)  const D3D11_RECT* pRects,
            UINT NumRects);

    END_INTERFACE
} ID3D11DeviceContext1Vtbl;

interface ID3D11DeviceContext1VT
{
    CONST_VTBL struct ID3D11DeviceContext1Vtbl* lpVtbl;
};