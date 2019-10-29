/**
 * @LC	   : 12/10/2019
 * @file   : mfTexture.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 12/10/2019
 * @brief  : Class in charge of provide textures to different classes.
 * @bug	   : No known bugs.
 */

/**
 * Headers
 */
// #include "mfDefines.h"
#include "mfRenderManager.h"
#include "mfBaseTexture.h"
#pragma once
 /**
   * @brief : Structure responsible for providing the class ID.
   */
struct mfTextureID
{
#ifdef mfDIRECTX
  /**
   * @brief : Identifier of the texture that is generated, in cases such
              as setting the shader resource or in ImGui :: Image it is
              necessary to call this member of the class.
   */
  ID3D11ShaderResourceView* ResourceViewID;
#endif // mfDIRECTX
};


/**
 * @brief : Class in charge of provide textures to different classes.
 */
class mfTexture : public mfBaseTexture
{
public:
  mfTexture();
  ~mfTexture();
  /**
   * Variables
   */
private:
  mfTextureID m_texture;
  /**
   * Functions
   */
public:
  /**
    * @brief  : Init Texture in API
    * @param  : mfTextureID _Desc : Texture descriptor
    * @bug    : No know Bugs
    */
  void 
  Init(mfBaseTextureDesc _Desc);
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
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void 
  Destroy();
  /**
    * @brief  : Return the object API representation
    * @bug    : No know Bugs
    */
  mfTextureID & getInterface();
};

