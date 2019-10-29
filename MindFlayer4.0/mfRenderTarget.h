/**
 * @LC	   : 12/10/2019
 * @file   : mfRenderTargetView.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 12/10/2019
 * @brief  : Class in charge of encapsulate textures that 
             will be used in future classes.
 * @bug	   : No known bugs.
 */

/**
 * Headers
 */
#include "mfBaseTexture.h"
#pragma once
 /**
   * @brief : Structure responsible for providing the class ID.
   */
struct mfRenderTargetViewID
{
#ifdef mfDIRECTX
  /**
   * @brief : DirectX 11's own resource that serves as an identifier and
  which can be accessed during execution
   */
  ID3D11RenderTargetView* ID;
#endif // mfDIRECTX
};


/**
 * @brief : Class in charge of encapsulate textures that
            will be used in future classes.
 */
class mfRenderTarget : public mfBaseTexture
{
public:
  mfRenderTarget();
  ~mfRenderTarget();
  /**
   * Variables
   */
private:
  /**
   * @brief : Structure that provides an ID of the class.
   */
  mfRenderTargetViewID m_RenderTarget;

  /**
   * Function
   */
public:
  /**
    * @brief  : Initializes a texture with render target values.
    * @param  : mfTextureDesc _Desc : Descriptor of a texture that
                will be interpreted as a render Target.
    * @bug    : No known bugs.
    */
  void 
  Init(mfBaseTextureDesc _Desc);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Update();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Render();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Destroy();

  /**
  * @brief  : Return the object API representation
  * @bug    : No know Bugs
  */
  mfRenderTargetViewID & getInterfaceRT();
};

