/**
 * @LC	   : 13/10/209
 * @file   : mfDeviceContext.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 11/10/2019
 * @brief  : The ID3D11DeviceContext interface represents a device
             context which generates rendering commands.
 * @bug	   : No known bugs.
 */

#include "mfDeviceContext.h"
#include "mfViewport.h"
#include "mfRenderTarget.h"
#include "mfDepthStencilView.h"
#include "mfInputLayout.h"
#include "mfConstBuffer.h"
#include "mfSampler.h"
#include "mfTexture.h"
#include "mfPixelBuffer.h"
#include "mfVertexBuffer.h"
#include "mfPixelShader.h"
#include "mfVertexShader.h"
mfDeviceContext::mfDeviceContext()
{
#ifdef mfDIRECTX
  m_DeviceContext.ID = NULL;
#endif // mfDIRECTX
}


mfDeviceContext::~mfDeviceContext()
{
}

void mfDeviceContext::Destroy()
{
#ifdef mfDIRECTX
  SAFE_RELEASE(m_DeviceContext.ID);
#endif // mfDIRECTX
}

void mfDeviceContext::OMSetRenderTargets(int _numViews, mfRenderTarget & _RenderTarget, mfDepthStencilView & _DepthStencilView)
{
#ifdef mfDIRECTX
  m_DeviceContext.ID->OMSetRenderTargets
  (
    _numViews,
    &_RenderTarget.getInterfaceRT().ID,
    _DepthStencilView.getInterface().ID
  );
#elif defined mfOPENGL
  mfOutputLOG("mfDeviceContext", "OMSetRenderTargets()", "Set Render Targets has been Initializated.");
#endif // mfDIRECTX
}

void mfDeviceContext::RSSetViewports(mfViewport & _Viewport)
{
#ifdef mfDIRECTX
  D3D11_VIEWPORT Desc;
  // Fill Descriptor
  Desc.Width = _Viewport.getDescriptor().Width;
  Desc.Height = _Viewport.getDescriptor().Height;
  Desc.MinDepth = _Viewport.getDescriptor().MinDepth;
  Desc.MaxDepth = _Viewport.getDescriptor().MaxDepth;
  Desc.TopLeftX = _Viewport.getDescriptor().TopLeftX;
  Desc.TopLeftY = _Viewport.getDescriptor().TopLeftY;
  // Set Viewport
  m_DeviceContext.ID->RSSetViewports(1, &Desc);
#elif defined mfOPENGL
  mfOutputLOG("mfDeviceContext", "RSSetViewports()", "Set Viewports has been Initializated.");
#endif // mfDIRECTX
}

void mfDeviceContext::IASetInputLayout(mfInputLayout & _InputLayout)
{
#ifdef mfDIRECTX
  m_DeviceContext.ID->IASetInputLayout(_InputLayout.getInterface().ID);
#elif defined mfOPENGL
  mfOutputLOG("mfDeviceContext", "IASetInputLayout()", "Set Input Layout has been Initializated.");
#endif // mfDIRECTX
}

void mfDeviceContext::IASetVertexBuffers
(
  unsigned int _StartSlot, 
  unsigned int _NumBuffers, 
  mfVertexBuffer & _VertexBuffers, 
  const unsigned int _Strides,
  const unsigned int _Offsets
)
{
#ifdef mfDIRECTX
  m_DeviceContext.ID->IASetVertexBuffers(_StartSlot, _NumBuffers, &_VertexBuffers.getInterface().ID, &_Strides, &_Offsets);
#elif defined mfOPENGL
  mfOutputLOG("mfDeviceContext", "IASetVertexBuffers()", "Set Vertex Buffers has been Initializated.");
#endif // mfDIRECTX
}

void mfDeviceContext::IASetIndexBuffer(mfIndexBuffer & _IndexBuffer, mf_FORMAT _Format, unsigned int _Offset)
{
#ifdef mfDIRECTX
  DXGI_FORMAT tmpFormat;
  if (_Format == mf_FORMAT_R16_UINT)
  {
    tmpFormat = DXGI_FORMAT_R16_UINT;
  }
  m_DeviceContext.ID->IASetIndexBuffer(_IndexBuffer.getInterface().ID, tmpFormat, _Offset);
#elif defined mfOPENGL
  mfOutputLOG("mfDeviceContext", "IASetIndexBuffer()", "Set Index Buffer has been Initializated.");
#endif // mfDIRECTX
}

void mfDeviceContext::IASetPrimitiveTopology(mf_PRIMITIVE_TOPOLOGY _Topology)
{
#ifdef mfDIRECTX
  D3D11_PRIMITIVE_TOPOLOGY  tmptopology;
  if (_Topology == mf_PRIMITIVE_TOPOLOGY_TRIANGLELIST )
  {
    tmptopology = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
  }
  m_DeviceContext.ID->IASetPrimitiveTopology(tmptopology);
#elif defined mfOPENGL
  mfOutputLOG("mfDeviceContext", "IASetPrimitiveTopology()", "Set Topology has been Initializated.");
#endif // mfDIRECTX
}

void mfDeviceContext::UpdateSubresource(mfConstBuffer & _ConstBuffer, const void * _SrcData)
{
#ifdef mfDIRECTX
  m_DeviceContext.ID->UpdateSubresource(_ConstBuffer.getInterface().ID, 0, NULL, _SrcData, 0, 0);
#elif defined mfOPENGL
  mfOutputLOG("mfDeviceContext", "UpdateSubresource()", "Update Subresource has been Initializated.");
#endif // mfDIRECTX
}

void mfDeviceContext::ClearRenderTargetView(mfRenderTarget _RenderTarget, float _ColorRGBA[4])
{
#ifdef mfDIRECTX
  m_DeviceContext.ID->ClearRenderTargetView(_RenderTarget.getInterfaceRT().ID, _ColorRGBA);
#elif defined mfOPENGL
  mfOutputLOG("mfDeviceContext", "ClearRenderTargetView()", "Clear Render Target View has been Initializated.");
#endif // mfDIRECTX
}

void mfDeviceContext::ClearDepthStencilView(mfDepthStencilView & _DepthStencilView)
{
#ifdef mfDIRECTX
  m_DeviceContext.ID->ClearDepthStencilView(_DepthStencilView.getInterface().ID, D3D11_CLEAR_DEPTH, 1.0f, 0);
#elif defined mfOPENGL
  mfOutputLOG("mfDeviceContext", "ClearDepthStencilView()", "Clear DepthS tencil view has been Initializated.");
#endif // mfDIRECTX
}

void mfDeviceContext::VSSetShader(mfVertexShader & _VertexShader)
{
#ifdef mfDIRECTX
  m_DeviceContext.ID->VSSetShader(_VertexShader.getInterface().ID, NULL, 0);
#elif defined mfOPENGL
  mfOutputLOG("mfDeviceContext", "VSSetShader()", "VSSet Shader has been Initializated.");
#endif // mfDIRECTX
}

void mfDeviceContext::VSSetConstantBuffers(unsigned int _StartSlot, unsigned int _NumBuffers, mfConstBuffer & _ConstantBuffers)
{
#ifdef mfDIRECTX
  m_DeviceContext.ID->VSSetConstantBuffers(_StartSlot, _NumBuffers, &_ConstantBuffers.getInterface().ID);
#elif defined mfOPENGL
  mfOutputLOG("mfDeviceContext", "VSSetConstantBuffers()", "Set Constant Buffers has been Initializated.");
#endif // mfDIRECTX
}

void mfDeviceContext::PSSetShader(mfPixelShader & _PixelShader)
{
#ifdef mfDIRECTX
  m_DeviceContext.ID->PSSetShader(_PixelShader.getInterface().ID, NULL, 0);
#elif defined mfOPENGL
  mfOutputLOG("mfDeviceContext", "PSSetShader()", "Set Shader has been Initializated.");
#endif // mfDIRECTX
}

void mfDeviceContext::PSSetConstantBuffers(unsigned int _StartSlot, unsigned int _NumBuffers, mfConstBuffer & _ConstantBuffers)
{
#ifdef mfDIRECTX
  m_DeviceContext.ID->PSSetConstantBuffers(_StartSlot, _NumBuffers, &_ConstantBuffers.getInterface().ID);
#elif defined mfOPENGL
  mfOutputLOG("mfDeviceContext", "PSSetConstantBuffers()", "Constant Buffers has been Initializated.");
#endif // mfDIRECTX
}

void mfDeviceContext::PSSetShaderResources(unsigned int _StartSlot, unsigned int _NumViews, mfTexture & _Texture)
{
#ifdef mfDIRECTX
  m_DeviceContext.ID->PSSetShaderResources(_StartSlot, _NumViews, &_Texture.getInterface().ResourceViewID);
#elif defined mfOPENGL
  mfOutputLOG("mfDeviceContext", "PSSetShaderResources()", "Shader Resources has been Initializated.");
#endif // mfDIRECTX
}

void mfDeviceContext::PSSetSamplers(unsigned int _StartSlot, unsigned int _NumSamplers, mfSampler & _Samplers)
{
#ifdef mfDIRECTX
  m_DeviceContext.ID->PSSetSamplers(_StartSlot, _NumSamplers, &_Samplers.getInterface().ID);
#elif defined mfOPENGL
  mfOutputLOG("mfDeviceContext", "PSSetSamplers()", "Samplers has been Initializated.");
#endif // mfDIRECTX
}

void mfDeviceContext::DrawIndexed(unsigned int _IndexCount, unsigned int _StartIndexLocation, int _BaseVertexLocation)
{
#ifdef mfDIRECTX
  m_DeviceContext.ID->DrawIndexed(_IndexCount, _StartIndexLocation, _BaseVertexLocation);
#elif defined mfOPENGL
  mfOutputLOG("mfDeviceContext", "DrawIndex()", "Draw Index has been Initializated.");
#endif // mfDIRECTX
}

mfDeviceContextID & mfDeviceContext::getInterface()
{
  return m_DeviceContext;
}
