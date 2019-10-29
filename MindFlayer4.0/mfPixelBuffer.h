/**
 * @LC	   : 14/10/2019
 * @file   : mfPixelBuffer.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 14/10/2019
 * @brief  : Class in charge of setting the vertex buffer.
 * @bug	   : No known bugs.
 */

 /**
  * Headers
  */
#include "mfBuffer.h"
#pragma once
  /**
   * @brief  Buffer descriptor struct
   */

struct mfIndexBufferDesc
{
  void * Data;
};

/**
 * @brief : Class in charge of setting the vertex buffer.
 */
class mfIndexBuffer : public mfBuffer
{
public:
  mfIndexBuffer();
  ~mfIndexBuffer();
  /**
   * Members
   */
private:
  /**
   * @brief : 
   */
  mfIndexBufferDesc m_descriptor;
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
    Init(mfBufferDesc _BufferDesc, mfIndexBufferDesc _PixelBufferDesc);
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
    Render(unsigned int _Offset);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  mfIndexBufferDesc & getIndexDescriptor();
};

