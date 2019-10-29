/**
 * @LC	   : 21/10/2019
 * @file   : mfMaterial.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 17/10/2019
 * @brief  : Class in charge of creating a new material.
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "mfDefines.h"
#include "mfTexture.h"
#include "mfRenderManager.h"
#pragma once
/**
 * @brief : Class in charge of creating a new material.
 */
struct mfMaterialID
{
  /**
 * @brief : Vector in charge of allocating textures.
 */
  vector<mfTexture> Textures;
};

/**
 * @brief : Class in charge of creating a new material.
 */
class mfMaterial
{
public:
  mfMaterial();
  ~mfMaterial();
/**
 * Members 
 */
private:
  /**
   * @brief : Structure that provides an ID of the class.
   */
  mfMaterialID m_Material;
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
  Init(mfTexture _Texture);
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
  Render(int _TexIndex);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Destroy();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  mfMaterialID & getInterface();
};

