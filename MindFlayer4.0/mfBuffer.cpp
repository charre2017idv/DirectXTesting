/**
 * @LC	    10/10/2019
 * @file   mfBuffer.cpp
 * @Author
 * @date   10/10/2019
 * @brief  Common buffer base class. This represent something in memory,
           also this is a virtual base class
 * @bug	   No known bugs.
 */

 /**
  * Class Headers
  */
#include "mfBuffer.h"


mfBuffer::mfBuffer()
{
#if defined(mfDIRECTX)
  m_buffer.ID = nullptr;
#endif
}

mfBuffer::~mfBuffer()
{
  Destroy();
}

void mfBuffer::Init(mfBufferDesc  _Desc)
{
  m_descriptor = _Desc;
}

void mfBuffer::Destroy()
{
#ifdef mfDIRECTX
  SAFE_RELEASE(m_buffer.ID);
#endif // mfDIRECTX
}

mfBufferID & mfBuffer::getInterface()
{
  return m_buffer;
}


mfBufferDesc & mfBuffer::getDescriptor()
{
  return m_descriptor;
}
