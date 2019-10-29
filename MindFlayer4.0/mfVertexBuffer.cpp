#include "mfVertexBuffer.h"



mfVertexBuffer::mfVertexBuffer()
{
}


mfVertexBuffer::~mfVertexBuffer()
{
}

void mfVertexBuffer::Init(mfBufferDesc _BufferDesc, mfVertexBufferDesc _VertexBufferDesc)
{
  mfBuffer::Init(_BufferDesc);
  m_descriptor = _VertexBufferDesc;

  HRESULT hr = mfRenderManager::getSingleton().CreateBuffer(*this);
  if (FAILED(hr))
  {
    mfOutputLOG("mfVertexBuffer", "init()", "Vertex Buffer creation fail.")
  }
}


void mfVertexBuffer::Render(unsigned int _Stride, unsigned int _Offset)
{
  mfRenderManager::getSingleton().IASetVertexBuffers(0, 1, *this, _Stride, _Offset);
}

mfVertexBufferDesc & mfVertexBuffer::getVertexDescriptor()
{
  return m_descriptor;
}
