/**
 * @LC	   : 12/10/2019
 * @file   : mfDevice.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 11/10/2019
 * @brief  : This class represents a virtual adapter; it is used to create resources.
 * @bug	   : No known bugs.
 */
#include "mdDevice.h"
#include "mfBaseTexture.h"
#include "mfDepthStencilView.h"
#include "mfVertexShader.h"
#include "mfInputLayout.h"
#include "mfPixelShader.h"
#include "mfSampler.h"
#include "mfRenderTarget.h"
#include "mfSwapchain.h"
#include "mfConstBuffer.h"
#include "mfVertexBuffer.h"
#include "mfPixelBuffer.h"
mfDevice::mfDevice()
{
#ifdef mfDIRECTX
  m_Device.ID = NULL;
#endif // mfDIRECTX

}


mfDevice::~mfDevice()
{
}

void mfDevice::Destroy()
{
#ifdef mfDIRECTX
  SAFE_RELEASE(m_Device.ID);
#endif // mfDIRECTX
}

HRESULT mfDevice::CreateRenderTargetView(mfSwapchain & _Swapchain, mfRenderTarget & _RenderTarget)
{
#ifdef mfDIRECTX
  return m_Device.ID->CreateRenderTargetView(_Swapchain.getInterface().backbuffer, NULL, &_RenderTarget.getInterfaceRT().ID);
#elif defined mfOPENGL
  mfOutputLOG("mfDevice", "CreateRenderTargetView()", "Render Target View has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfDevice::CreateRenderTargetView(mfRenderTarget & _RenderTarget)
{
#ifdef mfDIRECTX
  D3D11_RENDER_TARGET_VIEW_DESC Desc;
  if (_RenderTarget.getDescriptor().TexFormat == mf_FORMAT_D24_UNORM_S8_UINT)
  {
    Desc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
}
  if (_RenderTarget.getDescriptor().TexFormat == mf_FORMAT_R32G32B32A32_FLOAT)
  {
    Desc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
  }
  Desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
  Desc.Texture2D.MipSlice = 0;
  return m_Device.ID->CreateRenderTargetView(_RenderTarget.getInterface().ID, &Desc, &_RenderTarget.getInterfaceRT().ID);
#elif defined mfOPENGL
  mfOutputLOG("mfDevice", "CreateRenderTargetView()", "Render Target View has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfDevice::CreateTexture2D(mfBaseTexture & _texture)
{
#ifdef mfDIRECTX
  D3D11_TEXTURE2D_DESC Desc;
  // Set Memory
  memset(&Desc, 0, sizeof(Desc));
  Desc.Width = _texture.getDescriptor().Width;
  Desc.Height = _texture.getDescriptor().Height;
  Desc.MipLevels = _texture.getDescriptor().MipLevels;
  Desc.ArraySize = _texture.getDescriptor().Arraysize;
  if (_texture.getDescriptor().TexFormat == mf_FORMAT_D24_UNORM_S8_UINT)
  {
    Desc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
  }
  if (_texture.getDescriptor().TexFormat == mf_FORMAT_R32G32B32A32_FLOAT)
  {
    Desc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
  }
  //Desc.Format = _texture.getDescriptor().TexFormat;
  Desc.SampleDesc.Count = _texture.getDescriptor().SamplerDescCount;
  Desc.SampleDesc.Quality = _texture.getDescriptor().SamplerDescQuality;
  if (_texture.getDescriptor().Usage == mf_USAGE_DEFAULT)
  {
    Desc.Usage = D3D11_USAGE_DEFAULT;
  }
  //Desc.Usage = _texture.getDescriptor().Usage;
  Desc.BindFlags = _texture.getDescriptor().Bindflags;
  Desc.CPUAccessFlags = _texture.getDescriptor().CPUAccessFlags;
  Desc.MiscFlags = _texture.getDescriptor().MiscFlags;
  // Return ID
  return m_Device.ID->CreateTexture2D
  (
    &Desc, 
    NULL,
    &_texture.getInterface().ID
  );
#elif defined mfOPENGL
  mfOutputLOG("mfDevice", "CreateTexture2D()", "Texture2D has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfDevice::CreateDepthStencilView(mfDepthStencilView & _DepthStencilView)
{
#ifdef mfDIRECTX
  D3D11_DEPTH_STENCIL_VIEW_DESC Desc;
  // Set Memory
  memset(&Desc, 0, sizeof(Desc));
  // Fill Descriptor
  if (_DepthStencilView.getDescriptor().texFormat = mf_FORMAT_D24_UNORM_S8_UINT)
  {
    Desc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
  }
  if (_DepthStencilView.getDescriptor().ViewDimension == mf_DSV_DIMENSION_TEXTURE2D)
  {
    Desc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
  }
  Desc.Texture2D.MipSlice = _DepthStencilView.getDescriptor().MipSlice;
  // Return ID
  return m_Device.ID->CreateDepthStencilView
  (
    _DepthStencilView.getInterface().Resource,
    &Desc,
    &_DepthStencilView.getInterface().ID
  );
#elif defined mfOPENGL
  mfOutputLOG("mfDevice", "CreateDepthStencilView()", "Depth Stencil View has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfDevice::CreateVertexShader(mfVertexShader & _VertexShader)
{
#ifdef mfDIRECTX
  return m_Device.ID->CreateVertexShader
  (
    _VertexShader.getInterface().VSBlob->GetBufferPointer(),
    _VertexShader.getInterface().VSBlob->GetBufferSize(),
    NULL,
    &_VertexShader.getInterface().ID
  );
#elif defined mfOPENGL
  mfOutputLOG("mfDevice", "CreateVertexShader()", "Vertex Shader has been Initializated."); 
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfDevice::CreateInputLayout(mfInputLayout & _InputLayout, mfVertexShader & _VertexShader)
{
#ifdef mfDIRECTX
  return m_Device.ID->CreateInputLayout
  (
    _InputLayout.getInterface().Desc,
    _InputLayout.getInterface().numElements,
    _VertexShader.getInterface().VSBlob->GetBufferPointer(),
    _VertexShader.getInterface().VSBlob->GetBufferSize(),
    &_InputLayout.getInterface().ID
  );
#elif defined mfOPENGL
  mfOutputLOG("mfDevice", "CreateInputLayout()", "Input Layout has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfDevice::CreatePixelShader(mfPixelShader & _PixelShader)
{
#ifdef mfDIRECTX
  return m_Device.ID->CreatePixelShader(
    _PixelShader.getInterface().PSBlob->GetBufferPointer(),
    _PixelShader.getInterface().PSBlob->GetBufferSize(),
    NULL,
    &_PixelShader.getInterface().ID);
#elif defined mfOPENGL
  mfOutputLOG("mfDevice", "CreatePixelShader()", "Pixel Shader has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}


HRESULT mfDevice::CreateBuffer(mfConstBuffer & _ConstBuffer)
{
#ifdef mfDIRECTX
  D3D11_BUFFER_DESC Desc;
  // Set Memory
  memset(&Desc, 0, sizeof(Desc));
  // Fill Descriptor
  if (_ConstBuffer.getDescriptor().Usage == mf_USAGE_DEFAULT)
  {
    Desc.Usage = D3D11_USAGE_DEFAULT;
  }
  Desc.ByteWidth = _ConstBuffer.getDescriptor().ByteWidth;
  Desc.BindFlags = _ConstBuffer.getDescriptor().BindFlags;
  Desc.CPUAccessFlags = _ConstBuffer.getDescriptor().CPUAccessFlags;
  Desc.MiscFlags = _ConstBuffer.getDescriptor().MiscFlags;
  Desc.StructureByteStride = _ConstBuffer.getDescriptor().StructureByteStride;
  // Return ID
  return m_Device.ID->CreateBuffer(&Desc, NULL, &_ConstBuffer.getInterface().ID);
#elif defined mfOPENGL
  mfOutputLOG("mfDevice", "CreateBuffer()", "Buffer has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfDevice::CreateBuffer(mfIndexBuffer & _IndexBuffer)
{
#ifdef mfDIRECTX
  D3D11_BUFFER_DESC Desc;
  // Set Memory
  memset(&Desc, 0, sizeof(Desc));
  // Fill Descriptor
  if (_IndexBuffer.getDescriptor().Usage == mf_USAGE_DEFAULT)
  {
    Desc.Usage = D3D11_USAGE_DEFAULT;
  }
  Desc.ByteWidth = _IndexBuffer.getDescriptor().ByteWidth;
  Desc.BindFlags = _IndexBuffer.getDescriptor().BindFlags;
  Desc.CPUAccessFlags = _IndexBuffer.getDescriptor().CPUAccessFlags;
  Desc.MiscFlags = _IndexBuffer.getDescriptor().MiscFlags;
  Desc.StructureByteStride = _IndexBuffer.getDescriptor().StructureByteStride;

  D3D11_SUBRESOURCE_DATA initDesc;
  // Set Memory
  memset(&initDesc, 0, sizeof(initDesc));
  initDesc.pSysMem = _IndexBuffer.getIndexDescriptor().Data;
  // Return ID
  return m_Device.ID->CreateBuffer
  (
    &Desc, 
    &initDesc, 
    &_IndexBuffer.getInterface().ID
  );
#elif defined mfOPENGL
  mfOutputLOG("mfDevice", "CreateBuffer()", "Buffer has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfDevice::CreateBuffer(mfVertexBuffer & _VertexBuffer)
{
#ifdef mfDIRECTX
  D3D11_BUFFER_DESC Desc;
  // Set Memory
  memset(&Desc, 0, sizeof(Desc));
  // Fill Descriptor
  if (_VertexBuffer.getDescriptor().Usage == mf_USAGE_DEFAULT)
  {
    Desc.Usage = D3D11_USAGE_DEFAULT;
  }
  Desc.ByteWidth = _VertexBuffer.getDescriptor().ByteWidth;
  Desc.BindFlags = _VertexBuffer.getDescriptor().BindFlags;
  Desc.CPUAccessFlags = _VertexBuffer.getDescriptor().CPUAccessFlags;
  Desc.MiscFlags = _VertexBuffer.getDescriptor().MiscFlags;
  Desc.StructureByteStride = _VertexBuffer.getDescriptor().StructureByteStride;

  D3D11_SUBRESOURCE_DATA initDesc;
  // Set Memory
  memset(&initDesc, 0, sizeof(initDesc));
  initDesc.pSysMem = _VertexBuffer.getVertexDescriptor().Data;
  // Return ID
  return m_Device.ID->CreateBuffer
  (
    &Desc,
    &initDesc,
    &_VertexBuffer.getInterface().ID
  );
#elif defined mfOPENGL
  mfOutputLOG("mfDevice", "CreateBuffer()", "Buffer has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfDevice::CreateSamplerState(mfSampler & _Sampler)
{
#ifdef mfDIRECTX
  D3D11_SAMPLER_DESC Desc;
  // Set Memory
  memset(&Desc, 0, sizeof(Desc));
  // Fill Descriptor
  Desc.Filter = (D3D11_FILTER)_Sampler.getDescriptor().Filter;
  Desc.AddressU = (D3D11_TEXTURE_ADDRESS_MODE)_Sampler.getDescriptor().AddressU;
  Desc.AddressV = (D3D11_TEXTURE_ADDRESS_MODE)_Sampler.getDescriptor().AddressV;
  Desc.AddressW = (D3D11_TEXTURE_ADDRESS_MODE)_Sampler.getDescriptor().AddressW;
  Desc.ComparisonFunc = (D3D11_COMPARISON_FUNC)_Sampler.getDescriptor().ComparisionFunc;
  Desc.MinLOD = _Sampler.getDescriptor().MinLOD;
  Desc.MaxLOD = _Sampler.getDescriptor().MaxLOD;
  // Return ID
  return m_Device.ID->CreateSamplerState(&Desc, &_Sampler.getInterface().ID);
#elif defined mfOPENGL
  mfOutputLOG("mfDevice", "CreateSamplerState()", "Sampler State has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfDevice::CreateShaderResourceView(mfRenderTarget & _RenderTarget)
{
  return m_Device.ID->CreateShaderResourceView(_RenderTarget.getInterface().ID, NULL, &_RenderTarget.getInterface().ResourceViewID);
}

mfDeviceID & mfDevice::getInterface()
{
   return m_Device;
}
