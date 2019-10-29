/**
 * @LC	   : 13/10/2019
 * @file   : mfViewport.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 13/10/2019
 * @brief  : Class in charge of setting the viewport.
 * @bug	   : No known bugs.
 */

/**
 * Headers
 */
#include "mfDefines.h"
#include "mfRenderManager.h"
#pragma once

/**
 * @brief : Structure that fill the viewport descriptor.
 */
struct mfViewportDesc
{
  /**
   * Var
   */
  float Width;  
  float Height; 
  float MinDepth;
  float MaxDepth;
  float TopLeftX;
  float TopLeftY;
};

/**
 * @brief : Class in charge of setting the viewport.
 */
class mfViewport
{
public:
  mfViewport();
  ~mfViewport();
  /**
   * Members 
   */
private:
  /**
   * @brief : Structure that provides a descriptor ref of the class.
   */
  mfViewportDesc m_descriptor;

  /**
   * Methods 
   */
public:
  /**
    * @brief  : Function that initialize the viewport.
    * @param  : mfViewportDesc _Desc : Descriptor of the viewport.
    * @bug    : No known bugs.
    */
  void 
  Init(mfViewportDesc _Desc);
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
    * @brief  : Function that return a ref to the private descriptor.
    * @bug    : No known bugs.
    */
  mfViewportDesc & getDescriptor();
};

