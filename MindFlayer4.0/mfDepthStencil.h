/**
 * @LC	   : 13/10/2019
 * @file   : mfDepthStencil.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 13/10/2019
 * @brief  : Class that creates a depth stencil.
 * @bug	   : No known bugs.
 */

/**
 * Header 
 */
#include "mfBaseTexture.h"
#pragma once

/**
 * @brief : 
 */
class mfDepthStencil : public mfBaseTexture
{
public:
  mfDepthStencil();
  ~mfDepthStencil();
private:
  /**
   * Functions 
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
};

