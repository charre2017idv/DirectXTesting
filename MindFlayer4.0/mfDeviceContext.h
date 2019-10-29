/**
 * @LC	   : 13/10/209
 * @file   : mfDeviceContext.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 11/10/2019
 * @brief  : The ID3D11DeviceContext interface represents a device 
             context which generates rendering commands.   
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "mfDefines.h"
#pragma once
 /**
  * Forward Class Declarations
  */
class mfViewport;
class mfRenderTarget;
class mfDepthStencilView;
class mfInputLayout;
class mfConstBuffer;
class mfSampler;
class mfTexture;
class mfIndexBuffer;
class mfVertexBuffer;
class mfVertexShader;
class mfPixelShader;
 /**
   * @brief : Structure responsible for providing the class ID.
   */
struct mfDeviceContextID
{
#ifdef mfDIRECTX
  /**
    * @brief : The ID3D11DeviceContext interface represents a device
               context which generates rendering commands.
    */
  ID3D11DeviceContext* ID;
#endif 

};

/**
  * @brief : The ID3D11DeviceContext interface represents 
             a device context which generates rendering commands.
  */
class mfDeviceContext
{
public:
  mfDeviceContext();
  ~mfDeviceContext();
private:
  /**
    * @brief : Structure that provides an ID of the class.
    */
  mfDeviceContextID m_DeviceContext;

public:
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void 
  Init();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void 
  Update();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void 
  Render();
  /**
    * @brief  : Release Object
    * @bug    : No know Bugs
    */
  void 
  Destroy();
  
  /**
    * @brief  : Function that sets Render Targets
    * @param  : 
    * @bug    : No know Bugs.
    */
  void OMSetRenderTargets(int _numViews, mfRenderTarget & _RenderTarget, mfDepthStencilView & _DepthStencilView);

  /**
    * @brief  : Function that sets a Viewport.
    * @param  : UINT _NumViewports : Number of view ports created.
                const D3D11_VIEWPORT *_Viewports : Viewport Pointer ID.
    * @bug    : No know Bugs.
    */
  void RSSetViewports(mfViewport & _Viewport);

  /**
    * @brief  : Function that sets the input layout.
    * @param  : ID3D11InputLayout *_InputLayout : Calls an Input Layout object.
    * @bug    : No know Bugs.
    */
  void IASetInputLayout(mfInputLayout & _InputLayout);

  /**
    * @brief  : Function that sets vertex buffers.
    * @param  : unsigned int _StartSlot : 
                unsigned int _NumBuffers : 
                mfVertexBuffer & _VertexBuffers : 
                const unsigned int _Strides :
                const unsigned int _Offsets :
    * @bug    : No know Bugs.
    */

  void IASetVertexBuffers
  (
    unsigned int _StartSlot,
    unsigned int _NumBuffers,
    mfVertexBuffer & _VertexBuffers,
    const unsigned int _Strides,
    const unsigned int _Offsets
  );

  /**
    * @brief  : Function that sets Index Buffers.
    * @param  : mfIndexBuffer & _IndexBuffer : 
                DXGI_FORMAT _Format : 
                unsigned int _Offset : 
    * @bug    : No know Bugs.
    */
  void IASetIndexBuffer
  (
    mfIndexBuffer & _IndexBuffer,
    mf_FORMAT _Format,
    unsigned int _Offset
  );


  /**
    * @brief  : Function that sets the primitive topology.
    * @param  : D3D11_PRIMITIVE_TOPOLOGY _Topology : Structure With different topologies.
    * @bug    : No know Bugs.
    */
  void IASetPrimitiveTopology(mf_PRIMITIVE_TOPOLOGY _Topology);

  /**
    * @brief  : 
    * @param  : D3D11Resource *_DstResource : Buffer Pointer ID.
                UINT _DstSubresource : Value of sub resource data.
                const D3D11_BOX *_DstBox : 3D box structure.
                const void *_SrcData : Buffer Pointer Data.
                UINT _SrcRowPitch : Row Pitch value.
                UINT _SrcDepthPitch : Depth Pitch Value.
    * @bug    : No know Bugs.
    */

  void UpdateSubresource(mfConstBuffer & _ConstBuffer, const void * _SrcData);

  /**
    * @brief  : Function that clean the Render Target View
    * @param  : mfRenderTarget _RenderTarget : 
                float _ColorRGBA[4] : 
    * @bug    : No know Bugs.
    */
  void ClearRenderTargetView(mfRenderTarget _RenderTarget, float _ColorRGBA[4]);

  /**
    * @brief  : Function that clean the Depth stencil view
    * @param  : mfDepthStencilView & _DepthStencilView : 
    * @bug    : No know Bugs.
    */
  void ClearDepthStencilView(mfDepthStencilView & _DepthStencilView);

  /**
    * @brief  : Set Vertex Shader.
    * @param  : mfVertexShader & _VertexShader : Vertex Shader Object.
    * @bug    : No know Bugs.
    */
  void VSSetShader(mfVertexShader & _VertexShader);

  /**
    * @brief  : Function that sets the vertex shader constant buffers.
    * @param  : unsigned int _StartSlot : 
                unsigned int _NumBuffers : 
                mfConstBuffer & _ConstantBuffers : 
    * @bug    : No know Bugs.
    */
  void VSSetConstantBuffers
  (
    unsigned int _StartSlot,
    unsigned int _NumBuffers, 
    mfConstBuffer & _ConstantBuffers
  );

  /**
    * @brief  : Function that set the pixel shader.
    * @param  : mfPixelShader & _PixelShader
    * @bug    : No know Bugs.
    */
  void PSSetShader(mfPixelShader & _PixelShader);

  /**
    * @brief  : Function that sets the constant buffers.
    * @param  : unsigned int _StartSlot : 
                unsigned int _NumBuffers : 
                mfConstBuffer & _ConstantBuffers : 
    * @bug    : No know Bugs.
    */
  void PSSetConstantBuffers
  (
    unsigned int _StartSlot,
    unsigned int _NumBuffers,
    mfConstBuffer & _ConstantBuffers
  );


  /**
    * @brief  : Function that sets the shader resource.
    * @param  : unsigned int _StartSlot : 
                unsigned int _NumViews : 
                mfTexture _Texture : 
    * @bug    : No know Bugs.
    */
  void PSSetShaderResources
  (
    unsigned int _StartSlot,
    unsigned int _NumViews,
    mfTexture & _Texture
  );

  /**
    * @brief  : Function that Sets Samplers.
    * @param  : UINT _StartSlot : Beginning of the Sampler.
                UINT _NumSamplers : Number of samplers.
                mfSampler & _Samplers : Sampler Pointer ID.
    * @bug    : No know Bugs.
    */
  void PSSetSamplers
  (
    unsigned int _StartSlot,
    unsigned int _NumSamplers,
    mfSampler & _Samplers
  );
  /**
    * @brief  : Function that draw stores Index.
    * @param  : UINT _IndexCount : Number of Index
                UINT _StartIndexLocation : Start Of index position.
                INT _BaseVertexLocation : Location of Vertex.
    * @bug    : 
    */
  void DrawIndexed
  (
    unsigned int _IndexCount,
    unsigned int _StartIndexLocation,
    int _BaseVertexLocation
  );

  /**
    * @brief  : Return the object API representation
    * @bug    : No know Bugs
    */
  mfDeviceContextID & getInterface();
};

