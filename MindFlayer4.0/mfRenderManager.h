/**
 * @LC	   : 13/10/2019
 * @file   : mfRenderManager.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 11/10/2019
 * @brief  : Manager in charge of setting all the resources and structures
             of Device, Device Context and Swap chain. Also this class is a 
             Singleton for those classes.
 * @bug	   : No known bugs.
 */

/**
 * Header
 */
#include "mfDefines.h"
#include "mdDevice.h"
#include "mfDeviceContext.h"
#include "mfModule.h"
//#include "mfImGui.h"
#pragma once
class mfBaseTexture;
class mfVertexShader;
class mfInputLayout;
class mfPixelShader;
class mfViewport;
class mfRenderTarget;
class mfDepthStencilView;
class mfSampler;
class mfInputLayout;
class mfSwapchain;
class mfConstBuffer;
class mfVertexBuffer;
class mfIndexBuffer;
class mfTexture;
/**
 * @brief : 
 */
struct mfRenderManagerID
{
#ifdef mfDIRECTX
  unsigned int createDeviceFlags;
  D3D_DRIVER_TYPE driverType;
  D3D_FEATURE_LEVEL featureLevel;
  unsigned int numDriverTypes;
  unsigned int numFeatureLevels;

#elif defined mfOPENGL
#endif
};
/**
 * @brief : Manager in charge of setting all the resources and structures
            of Device, Device Context and Swap chain. Also this class is a
            Singleton for those classes.

            How to use this class?
            If you want to use some function of parameter of the class it 
            is necessary to call an instance of the same class to use it.

            Example: mfRenderManager::getSingleton().Init();
 */
class mfRenderManager : public mfModule<mfRenderManager>
{
  /**
   * @brief : It is necessary to keep this constructor as private to not 
              create more instances of it.
   */
public:
  mfRenderManager();
  ~mfRenderManager();
  /**
   * Variables
   */
private:
  /**
   * @brief : 
   */
  mfRenderManagerID m_RenderManager;
  /**
   * @brief : Provides resources from Device object class
   */
  mfDevice  m_Device;
  /**
   * @brief : Provides resources from Device Context object class
   */
  mfDeviceContext m_DeviceContext;

  /**
   * Functions
   */
public:
  /**
    * @brief  : Function that initialize the module.
    * @bug    : No know bugs.
    */
  virtual void onPrepare() override;
  /**
    * @brief  : Function in charge of release modules.
    * @bug    : No know bugs.
    */
  virtual void onShutDown() override {}
  /**
    * @brief  : Init Render Manager in hardware
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Init(HWND wnd, mfSwapchain & _Swapchain);
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
    * @bug    : No known bugs.
    */
  void 
  Destroy();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  mfRenderManagerID & getInterface();
  /**
    * @brief  : Function that initialize samplers. 
    * @param  : mfSamplerDesc _Desc : Sampler Descriptor.
    * @bug    : No known bugs.
    */
  HRESULT CreateSamplerState(mfSampler & _Sampler);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  HRESULT CreateTexture2D(mfBaseTexture & _Texture);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  HRESULT CreateDepthStencilView(mfDepthStencilView & _DepthStencilView);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  HRESULT CreateVertexShader(mfVertexShader & _VertexShader);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  HRESULT CreateInputLayout(mfInputLayout & _InputLayout, mfVertexShader & _VertexShader);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  HRESULT CreatePixelShader(mfPixelShader & _PixelShader);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  HRESULT CreateRenderTargetView(mfSwapchain & _Swapchain, mfRenderTarget & _RenderTarget);
  /**
   * @brief : 
   */
  HRESULT CreateRenderTargetView(mfRenderTarget & _RenderTarget);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  HRESULT CreateBuffer(mfConstBuffer & _ConstBuffer);
  HRESULT CreateBuffer(mfIndexBuffer & _IndexBuffer);
  HRESULT CreateBuffer(mfVertexBuffer & _VertexBuffer);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  HRESULT CreateShaderResourceView(mfRenderTarget & _RenderTarget);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void RSSetViewports(mfViewport & _Viewport);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void OMSetRenderTargets(int _numViews, mfRenderTarget & _RenderTarget, mfDepthStencilView & _DepthStencilView);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void IASetInputLayout(mfInputLayout & _InputLayout);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void UpdateSubresource(mfConstBuffer & _ConstBuffer, const void * _SrcData);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void VSSetConstantBuffers
  (
    unsigned int _StartSlot,
    unsigned int _NumBuffers,
    mfConstBuffer & _ConstantBuffers
  );
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
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void ClearRenderTargetView(mfRenderTarget _RenderTarget, float _ColorRGBA[4]);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void ClearDepthStencilView(mfDepthStencilView & _DepthStencilView);
  /**
  * @brief  : Function that draw stores Index.
  * @param  : unsigned int _IndexCount : Number of Index
              unsigned int _StartIndexLocation : Start Of index position.
              int _BaseVertexLocation : Location of Vertex.
  * @bug    :
  */
  void DrawIndexed
  (
    unsigned int _IndexCount,
    unsigned int _StartIndexLocation,
    int _BaseVertexLocation
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
  * @brief  : Function that set the pixel shader.
  * @param  : mfPixelShader & _PixelShader
  * @bug    : No know Bugs.
  */
  void PSSetShader(mfPixelShader & _PixelShader);
  /**
  * @brief  : Set Vertex Shader.
  * @param  : mfVertexShader & _VertexShader : Vertex Shader Object.
  * @bug    : No know Bugs.
  */
  void VSSetShader(mfVertexShader & _VertexShader);
  /**
    * @brief  : Function that sets the primitive topology.
    * @param  : D3D11_PRIMITIVE_TOPOLOGY _Topology : Structure With different topologies.
    * @bug    : No know Bugs.
    */
  void IASetPrimitiveTopology(mf_PRIMITIVE_TOPOLOGY _Topology);

  mfDevice GetDevice() { return m_Device; }
#ifdef mfDIRECTX
  ID3D11Device*& GetprtDev() { return m_Device.getInterface().ID; }
#elif defined mfOPENGL
#endif // mfDIRECTX

  mfDeviceContext GetDeviceContext() { return m_DeviceContext; }
#ifdef mfDIRECTX
  ID3D11DeviceContext *& GetprtDevCtx() { return m_DeviceContext.getInterface().ID; }
#elif defined mfOPENGL
#endif // mfDIRECTX

  
};

