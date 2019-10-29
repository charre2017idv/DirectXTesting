/**
 * @LC	   : 12/10/2019
 * @file   : mfDevice.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 11/10/2019
 * @brief  : This class represents a virtual adapter; it is used to create resources.          
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "mfDefines.h"
#pragma once
/**
 * forward Class Declarations 
 */
class mfBaseTexture;
class mfDepthStencilView;
class mfVertexShader;
class mfInputLayout;
class mfPixelShader;
class mfSampler;
class mfRenderTarget;
class mfSwapchain;
class mfConstBuffer;
class mfVertexBuffer;
class mfIndexBuffer;
 /**
   * @brief : Structure responsible for providing the class ID.
   */
struct mfDeviceID
{
#ifdef mfDIRECTX
  /** 
    * @brief : The device interface represents a virtual adapter;
               it is used to create resources.
    */
  ID3D11Device* ID;
#elif defined mfOPENGL
  //mfOutputLOG("mfDevice", "mfDeviceID", "ID has been set.");
#endif // mfDIRECTX
};

/**
 * @brief : This class represents a virtual adapter; it is used to create resources.
 */
class mfDevice
{
public:
  mfDevice();
  ~mfDevice();
private:
#ifdef mfDIRECTX
  /**
    * @brief : Structure that provides an ID of the class.
    */
#endif // mfDIRECTX
  mfDeviceID m_Device;

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
    * @brief  : Function that creates a render target view
    * @param  : mfSwapchain & _Swapchain : Swap chain object.
                mfRenderTarget & _RenderTarget : Render Target object.
    * @bug    : No know Bugs.
    */
  HRESULT CreateRenderTargetView(mfSwapchain & _Swapchain, mfRenderTarget & _RenderTarget);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  HRESULT CreateRenderTargetView(mfRenderTarget & _RenderTarget);

  /**
    * @brief  : Function that creates a Texture 2D
    * @param  : mfBaseTexture _texture : 
    * @bug    : No know Bugs.
    */
  HRESULT CreateTexture2D(mfBaseTexture &  _texture);

  /**
    * @brief  : Function that creates a Depth Stencil View.
    * @param  : mfDepthStencilView & _DepthStencilView : 
    * @bug    : No know Bugs.
    */
  HRESULT CreateDepthStencilView(mfDepthStencilView & _DepthStencilView);

  /**
    * @brief  : Function that creates a vertex shader.
    * @param  : mfVertexShader & _VertexShader : Vertex Shader Object.
    * @bug    : No know Bugs.
    */
  HRESULT CreateVertexShader(mfVertexShader & _VertexShader);

  /**
    * @brief  : Function that creates a Input Layout.
    * @param  : mfInputLayout & _InputLayout : Input Layout Object.
                mfVertexShader & _VertexShader : Vertex Shader Object.
    * @bug    : No know Bugs.
    */
  HRESULT CreateInputLayout(mfInputLayout & _InputLayout, mfVertexShader & _VertexShader);

  /**
    * @brief  : Function that creates a Pixel Shader
    * @param  : mfPixelShader & _PixelShader : Pixel Shader Object.
    * @bug    : No know Bugs.
    */
  HRESULT CreatePixelShader(mfPixelShader & _PixelShader);
  /**
    * @brief  : Function that create a Buffer.
    * @param  : mfConstBuffer & _ConstBuffer : Constant Buffer Object
    * @bug    : No know Bugs.
    */
  HRESULT CreateBuffer(mfConstBuffer & _ConstBuffer);
  /**
  * @brief  : Function that create a Buffer.
  * @param  : mfIndexBuffer & _IndexBuffer : Index Buffer Object.
  * @bug    : No know Bugs.
  */
  HRESULT CreateBuffer(mfIndexBuffer & _IndexBuffer);
  /**
  * @brief  : Function that create a Buffer.
  * @param  : mfVertexBuffer & _VertexBuffer : Vertex Buffer Object.
  * @bug    : No know Bugs.
  */
  HRESULT CreateBuffer(mfVertexBuffer & _VertexBuffer);
  /**
    * @brief  : Function that create the sampler state.
    * @param  : mfSampler & _Sampler : Sampler Object.
    * @bug    : No know bugs.
    */
  HRESULT CreateSamplerState(mfSampler & _Sampler);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  HRESULT CreateShaderResourceView(mfRenderTarget & _RenderTarget);
  /**
    * @brief  : Return the object API representation
    * @bug    : No know Bugs.
    */
  mfDeviceID & getInterface();
};

