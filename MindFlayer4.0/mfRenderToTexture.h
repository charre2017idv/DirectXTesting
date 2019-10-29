/**
 * @LC	   : 25/10/2019
 * @file   : mfRenderToTexture.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 25/10/2019
 * @brief  : Class in charge of set render targets to a shader resource.
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "mfDefines.h"
#include "mfRenderTarget.h"
#include "mfRenderManager.h"
#pragma once
/**
 * Forward Class Declarations 
 */
class mfDepthStencilView;
/**
 * @brief : 
 */
struct mfRenderToTextureID
{
  /**
 * @brief : Render Target that will be used as a shader resource.
 */
  mfRenderTarget RenderTargetToTexture;
};

/**
 * @brief : Class in charge of set render targets to a shader resource.
 */
class mfRenderToTexture
{
public:
  mfRenderToTexture();
  ~mfRenderToTexture();
  /**
   * Members 
   */
private:
  /**
   * @brief : Structure that provides an ID of the class.
   */
  mfRenderToTextureID m_RenderToTexture;
  /**
   * Methods 
   */
public:
  /**
    * @brief  : Function in charge of setting the render target.
    * @bug    : No known bugs.
    */
  void 
  Init();
  /**
    * @brief  : 
    * @bug    : No known bugs.
    */
  void 
  Update();
  /**
    * @brief  : Function responsible for cleaning and setting the render targets.
    * @param  : mfDepthStencilView & _DepthStencilView : Depth stencil View object.
                float _ClearColor[4] : Color Array.
    * @bug    : No known bugs.
    */
  void 
  Render(mfDepthStencilView & _DepthStencilView, float _ClearColor[4]);
  /**
    * @brief  : Function that release the render target.
    * @bug    : No known bugs.
    */
  void 
  Destroy();
  /**
    * @brief  : Return the object API representation.
    * @bug    : No know bugs.
    */
  mfRenderToTextureID & getInterface();
  /**
    * @brief  : Function in charge of setting the shader resource view with 
                the render target texture.
    * @bug    : No know bugs.
    */
  void CreateShaderResourceView();
};

