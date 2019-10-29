/**
 * @LC	   : 13/10/2019
 * @file   : mfPixelShader.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 13/10/2019
 * @brief  : Class that initialize a pixel shader. This class is inherited.
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
// #include "mfDefines.h"
// #include "mfRenderManager.h"
#include "mfBaseShader.h"
#pragma once
 /**
  * @brief : Structure responsible for providing the class ID.
  */
struct mfPixelShaderID
{
#ifdef mfDIRECTX
  ID3D11PixelShader* ID;
  ID3DBlob* PSBlob;
#endif // mfDIRECTX

};

/**
 * @brief :  Class that initialize a pixel shader.
 */
class mfPixelShader : public mfBaseShader
{
public:
  mfPixelShader();
  ~mfPixelShader();
  /**
   * Variables 
   */
private:
  /**
   * @brief : Pixel Shader pointer ID.
   */
  mfPixelShaderID m_pixelShader;
  /**
   * Functions 
   */
public:
  /**
    * @brief  : Function that initialize the Pixel Shader.
    * @bug    : No known bugs.
    */
  HRESULT 
  Init(mfBaseShaderDesc _Desc);
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
    * @brief  : Function that release the pixel shader pointer.
    * @bug    : No known bugs.
    */
  void 
  Destroy();
  
  /**
  * @brief  : Return the object API representation
  * @bug    : No know Bugs
  */
  mfPixelShaderID & getInterface();

};

