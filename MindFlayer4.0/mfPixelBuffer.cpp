#include "mfPixelBuffer.h"



mfIndexBuffer::mfIndexBuffer()
{
}


mfIndexBuffer::~mfIndexBuffer()
{
}

void mfIndexBuffer::Init(mfBufferDesc _BufferDesc, mfIndexBufferDesc _PixelBufferDesc)
{
  // Set values of buffer
  mfBuffer::Init(_BufferDesc);
  m_descriptor = _PixelBufferDesc;

  HRESULT hr = mfRenderManager::getSingleton().CreateBuffer(*this);
  if (FAILED(hr))
  {
    mfOutputLOG("mfPixelBuffer", "init()", "Pixel Buffer creation fail.")
  }
}

void mfIndexBuffer::Render(unsigned int _Offset)
{
  mfRenderManager::getSingleton().IASetIndexBuffer(*this, mf_FORMAT_R16_UINT, _Offset);
}

mfIndexBufferDesc & mfIndexBuffer::getIndexDescriptor()
{
  return m_descriptor;
}