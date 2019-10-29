/**
 * @LC	   : 14/10/2019
 * @file   : mfconstBuffer.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 14/10/2019
 * @brief  : Class in charge of setting const buffer.
             This class inherits from mfbuffer.
 * @bug	   : No known bugs.
 */

 /**
  * Headers
  */
#include "mfBuffer.h"
#pragma once

/**
 * @brief : Class in charge of setting const buffer.
            This class inherits from mfbuffer.
 */
class mfConstBuffer : public mfBuffer
{
public:
  mfConstBuffer();
  ~mfConstBuffer();
  /**
   * Members 
   */
private:

  public:
  /**
    * @brief  : Function that initialize the constant buffer.
    * @param  : mfBufferDesc _Desc : Buffer Descriptor.
    * @bug    : No known bugs.
    */
  void 
  Init(mfBufferDesc _Desc);
  /**
    * @brief  : Function that update the information of the constant buffer.
    * @param  : const void * _Resource : Resource that get structures of data.
    * @bug    : No known bugs.
    */
  void 
  Update(const void * _Resource);
  /**
    * @brief  : 
    * @param  : unsigned int _startSlot : Beginning of slot.
                unsigned int _numBuffers : Index of buffers created.
    * @bug    : No known bugs.
    */
  void 
  Render(unsigned int _startSlot, unsigned int _numBuffers);  
};

