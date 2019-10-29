/**
 * @LC	   : 15/10/2019
 * @file   : mfBaseTexture.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 15/10/2019
 * @brief  : Base class in charge of setting a texture structure.
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "mfDefines.h"
#include "mfRenderManager.h"
#pragma once
 /**
   * @brief : Structure responsible for providing the class ID.
   */
struct mfBaseTextureID
{
#ifdef mfDIRECTX
  /**
    * @brief : DirectX 11's own resource that serves as an identifier and
               which can be accessed during execution
    */
  ID3D11Texture2D* ID;
  /**
   * @brief : 
   */
  //D3D11_TEXTURE2D_DESC Desc;
  /**
   * @brief : Identifier of the texture that is generated, in cases such
              as setting the shader resource or in ImGui :: Image it is
              necessary to call this member of the class.
   */
  ID3D11ShaderResourceView* ResourceViewID;
#elif defined mfOPENGL
  int ResourceViewID;
#endif // mfDIRECTX

};

/**
 * @brief : Structure that helps fill the texture descriptor, can be
            initialized by means of the FillDescriptor function.
 */
struct mfBaseTextureDesc
{
  /**
   * Variables
   */
  mfTextureType ID;
  string Tag;
  LPCWSTR Filepath;
  mf_FORMAT TexFormat;
  mf_USAGE Usage;
  int Width;
  int Height;
  int MipLevels;
  int Arraysize;
  int SamplerDescCount;
  int SamplerDescQuality;
  unsigned int Bindflags;
  unsigned int CPUAccessFlags;
  unsigned int MiscFlags;
};

/**
 * @brief : Base class in charge of setting a texture structure.
 */
class mfBaseTexture
{
public:
  mfBaseTexture();
  ~mfBaseTexture();
  /**
   * Members 
   */
private:
  /**
   * @brief :
   */
  mfBaseTextureID m_baseTexture;
  /**
   * @brief : 
   */
  mfTextureType m_TextureType;
  /**
   * @brief : 
   */
  mfBaseTextureDesc m_descriptor;
  /**
   * Methods 
   */
public:
  /**
    * @brief  : 
    * @param  : 
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
    * @brief  : This function will be override.
    * @bug    : No known bugs.
    */
  void 
  Render();
  /**
    * @brief  : Release Object.
    * @bug    : No known bugs.
    */
  void 
  Destroy();
  /**
    * @brief  : Return the object API representation
    * @bug    : No know Bugs
    */
  mfBaseTextureID & getInterface();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  mfTextureType  & getTextureType();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  mfBaseTextureDesc & getDescriptor();
};

