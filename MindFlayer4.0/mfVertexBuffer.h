/**
 * @LC	   : 14/10/2019
 * @file   : mfVertexBuffer.h
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

struct mfVertexBufferDesc
{
  void * Data;
};

/**
 * @brief : Class in charge of setting the vertex buffer.
 */
class mfVertexBuffer : public mfBuffer
{
public:
  mfVertexBuffer();
  ~mfVertexBuffer();
  /**
   * Members
   */
private:
  /**
 * @brief :
 */
  mfVertexBufferDesc m_descriptor;
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
  Init(mfBufferDesc _BufferDesc, mfVertexBufferDesc _VertexBufferDesc);
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
  Render(unsigned int _Stride, unsigned int _Offset);
  /**
  * @brief  :
  * @param  :
  * @bug    :
  */
  mfVertexBufferDesc & getVertexDescriptor();
};

