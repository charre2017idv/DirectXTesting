/**
 * @LC	   : 13/10/2019
 * @file   : mfRenderManager.cpp
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 11/10/2019
 * @brief  : Manager in charge of setting all the resources and structures
             of Device, Device Context and Swap chain. Also this class is a
             Singleton for those classes.
 * @bug	   : No known bugs.
 */
#include "mfRenderManager.h"
#include "mfBaseTexture.h"
#include "mfVertexShader.h"
#include "mfInputLayout.h"
#include "mfViewport.h"
#include "mfRenderTarget.h"
#include "mfDepthStencilView.h"
#include "mfSampler.h"
#include "mfInputLayout.h"
#include "mfSwapchain.h"
#include "mfConstBuffer.h"
#include "mfVertexBuffer.h"
#include "mfPixelBuffer.h"
#include "mfPixelShader.h"
#include "mfTexture.h"
mfRenderManager::mfRenderManager()
{
#ifdef mfDIRECTX
  m_RenderManager.driverType = D3D_DRIVER_TYPE_NULL;
  m_RenderManager.featureLevel = D3D_FEATURE_LEVEL_11_0;
#endif // mfDIRECTX
}


mfRenderManager::~mfRenderManager()
{
}

void mfRenderManager::onPrepare()
{
  mfOutputLOG("mfRenderManager", "onPrepare()", "Module has been Initializated.");
}

void mfRenderManager::Init(HWND wnd, mfSwapchain & _Swapchain)
{
  // 3) Init Device
  // 4) Init Device Context
  // 4.1) Set Device and Swap chain
  // 4.2) Set back buffer
  // 5) Create Render target view
  // 6) Create Depth Stencil Texture
  // 7) Create Depth Stencil view
  // 8) Init Viewport
  // 9) Init Shader
  // 9.1) Create Vertex Shader
  // 9.2) Init Layout
  // 9.3) Create Pixel Shader
  // 10) Create buffers
  // 10.1) Create Vertex Buffer
  // 10.2) Set Vertex Buffer
  // 10.3) Create Index Buffer
  // 10.4) Set Index Buffer
  // 11) Set Primitive Topology
  // 12) Create Constant Buffers
  // 13) Load Textures
  // 14) Create Sample State
  // 15) Init world (mesh) Matrix
  // 16) Init View Matrix
  // 17) Init Projection Matrix
}

void mfRenderManager::Render()
{

}

void mfRenderManager::Destroy()
{
  // Release Device
  m_Device.Destroy();
  // Release Device Context
  m_DeviceContext.Destroy();
}

mfRenderManagerID & mfRenderManager::getInterface()
{
  return m_RenderManager;
}

HRESULT mfRenderManager::CreateSamplerState(mfSampler & _Sampler)
{
#ifdef mfDIRECTX
  return m_Device.CreateSamplerState(_Sampler);
#elif defined mfOPENGL
  mfOutputLOG("mfRenderManager", "CreateSamplerState()", "Sampler has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfRenderManager::CreateTexture2D(mfBaseTexture  & _Texture)
{
#ifdef mfDIRECTX
  return m_Device.CreateTexture2D(_Texture);
#elif defined mfOPENGL
  mfOutputLOG("mfRenderManager", "CreateTexture2D()", "Texture2D has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfRenderManager::CreateDepthStencilView(mfDepthStencilView & _DepthStencilView)
{
#ifdef mfDIRECTX
  return m_Device.CreateDepthStencilView(_DepthStencilView);
#elif defined mfOPENGL
  mfOutputLOG("mfRenderManager", "CreateDepthStencilView()", "Depth Stencil View has been Initializated."); 
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfRenderManager::CreateVertexShader(mfVertexShader & _VertexShader)
{
#ifdef mfDIRECTX
  return m_Device.CreateVertexShader(_VertexShader);
#elif defined mfOPENGL
  mfOutputLOG("mfRenderManager", "CreateVertexShader()", "Vertex Shader has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfRenderManager::CreateInputLayout(mfInputLayout & _InputLayout, mfVertexShader & _VertexShader)
{
#ifdef mfDIRECTX
  return m_Device.CreateInputLayout(_InputLayout, _VertexShader);
#elif defined mfOPENGL
  mfOutputLOG("mfRenderManager", "CreateInputLayout()", "Input Layout has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfRenderManager::CreatePixelShader(mfPixelShader & _PixelShader)
{
#ifdef mfDIRECTX
  return m_Device.CreatePixelShader(_PixelShader);
#elif defined mfOPENGL
  mfOutputLOG("mfRenderManager", "CreatePixelShader()", "Pixel Shader has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfRenderManager::CreateRenderTargetView(mfSwapchain & _Swapchain, mfRenderTarget & _RenderTarget)
{
#ifdef mfDIRECTX
  return m_Device.CreateRenderTargetView(_Swapchain, _RenderTarget);
#elif defined mfOPENGL
  mfOutputLOG("mfRenderManager", "CreateRenderTargetView()", "Render Target View has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfRenderManager::CreateRenderTargetView(mfRenderTarget & _RenderTarget)
{
#ifdef mfDIRECTX
  return m_Device.CreateRenderTargetView(_RenderTarget);
#elif defined mfOPENGL
  mfOutputLOG("mfRenderManager", "CreateRenderTargetView()", "Render Target View has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

HRESULT mfRenderManager::CreateBuffer(mfConstBuffer & _ConstBuffer)
{
  return m_Device.CreateBuffer(_ConstBuffer);
}

HRESULT mfRenderManager::CreateBuffer(mfIndexBuffer & _IndexBuffer)
{
  return m_Device.CreateBuffer(_IndexBuffer);
}

HRESULT mfRenderManager::CreateBuffer(mfVertexBuffer & _VertexBuffer)
{
  return m_Device.CreateBuffer(_VertexBuffer);
}

HRESULT mfRenderManager::CreateShaderResourceView(mfRenderTarget & _RenderTarget)
{
  return m_Device.CreateShaderResourceView(_RenderTarget);
}

void mfRenderManager::RSSetViewports(mfViewport & _Viewport)
{
#ifdef mfDIRECTX
  m_DeviceContext.RSSetViewports(_Viewport);
#elif defined mfOPENGL
  mfOutputLOG("mfRenderManager", "RSSetViewports()", "Viewport has been Initializated.");
#endif // mfDIRECTX
}

void mfRenderManager::OMSetRenderTargets(int _numViews, mfRenderTarget & _RenderTarget, mfDepthStencilView & _DepthStencilView)
{
#ifdef mfDIRECTX
  m_DeviceContext.OMSetRenderTargets(_numViews, _RenderTarget, _DepthStencilView);
#elif defined mfOPENGL
  mfOutputLOG("mfRenderManager", "OMSetRenderTargets()", "Render Target has been Initializated.");
#endif // mfDIRECTX
}

void mfRenderManager::IASetInputLayout(mfInputLayout & _InputLayout)
{
  m_DeviceContext.IASetInputLayout(_InputLayout);
}

void mfRenderManager::UpdateSubresource(mfConstBuffer & _ConstBuffer, const void * _SrcData)
{
  m_DeviceContext.UpdateSubresource(_ConstBuffer, _SrcData);
}

void mfRenderManager::VSSetConstantBuffers(unsigned int _StartSlot, unsigned int _NumBuffers, mfConstBuffer & _ConstantBuffers)
{
  m_DeviceContext.VSSetConstantBuffers(_StartSlot, _NumBuffers, _ConstantBuffers);
}

void mfRenderManager::PSSetConstantBuffers(unsigned int _StartSlot, unsigned int _NumBuffers, mfConstBuffer & _ConstantBuffers)
{
  m_DeviceContext.PSSetConstantBuffers(_StartSlot, _NumBuffers, _ConstantBuffers);
}

void mfRenderManager::ClearRenderTargetView(mfRenderTarget _RenderTarget, float _ColorRGBA[4])
{
  m_DeviceContext.ClearRenderTargetView(_RenderTarget, _ColorRGBA);
}

void mfRenderManager::ClearDepthStencilView(mfDepthStencilView & _DepthStencilView)
{
  m_DeviceContext.ClearDepthStencilView(_DepthStencilView);
}

void mfRenderManager::DrawIndexed(unsigned int _IndexCount, unsigned int _StartIndexLocation, int _BaseVertexLocation)
{
  m_DeviceContext.DrawIndexed(_IndexCount, _StartIndexLocation, _BaseVertexLocation);
}

void mfRenderManager::PSSetSamplers(unsigned int _StartSlot, unsigned int _NumSamplers, mfSampler & _Samplers)
{
  m_DeviceContext.PSSetSamplers(_StartSlot, _NumSamplers, _Samplers);
}

void mfRenderManager::PSSetShaderResources(unsigned int _StartSlot, unsigned int _NumViews, mfTexture & _Texture)
{
  m_DeviceContext.PSSetShaderResources(_StartSlot, _NumViews, _Texture);
}


void mfRenderManager::IASetIndexBuffer(mfIndexBuffer & _IndexBuffer, mf_FORMAT _Format, unsigned int _Offset)
{
  m_DeviceContext.IASetIndexBuffer(_IndexBuffer, _Format, _Offset);
}

void mfRenderManager::IASetVertexBuffers(unsigned int _StartSlot, unsigned int _NumBuffers, mfVertexBuffer & _VertexBuffers, const unsigned int _Strides, const unsigned int _Offsets)
{
  m_DeviceContext.IASetVertexBuffers(_StartSlot, _NumBuffers, _VertexBuffers, _Strides, _Offsets);
}

void mfRenderManager::PSSetShader(mfPixelShader & _PixelShader)
{
  m_DeviceContext.PSSetShader(_PixelShader);
}

void mfRenderManager::VSSetShader(mfVertexShader & _VertexShader)
{
  m_DeviceContext.VSSetShader(_VertexShader);
}

void mfRenderManager::IASetPrimitiveTopology(mf_PRIMITIVE_TOPOLOGY _Topology)
{
  m_DeviceContext.IASetPrimitiveTopology(_Topology);
}
