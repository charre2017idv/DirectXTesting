#include "mfMesh.h"



mfMesh::mfMesh()
{
}


mfMesh::~mfMesh()
{
}

void mfMesh::Init(mfLoadModelID _Data)
{
  m_indexSize = _Data.IndexSize;
  mfBufferDesc VertexBufferDesc;
  VertexBufferDesc.Usage = mf_USAGE_DEFAULT;
  VertexBufferDesc.ByteWidth = sizeof(SimpleVertex) * _Data.VertexSize;// 24;
  VertexBufferDesc.BindFlags = mf_BIND_VERTEX_BUFFER;
  VertexBufferDesc.CPUAccessFlags = 0;
  VertexBufferDesc.MiscFlags = 0;
  VertexBufferDesc.StructureByteStride = 0;
  mfVertexBufferDesc InitVertexBufferDesc;
  InitVertexBufferDesc.Data = _Data.Vertex;

  // Set vertex buffer
  UINT stride = sizeof(SimpleVertex);
  UINT offset = 0;

  m_vertexBuffer.Init(VertexBufferDesc, InitVertexBufferDesc);

  m_vertexBuffer.Render(stride, offset);

  mfBufferDesc PixelBufferDesc;
  PixelBufferDesc.Usage = mf_USAGE_DEFAULT;
  PixelBufferDesc.ByteWidth = sizeof(WORD) * _Data.IndexSize;// 36;
  PixelBufferDesc.BindFlags = mf_BIND_INDEX_BUFFER;
  PixelBufferDesc.CPUAccessFlags = 0;
  mfIndexBufferDesc InitPixelBufferDesc;
  InitPixelBufferDesc.Data = _Data.Index;// indices;

  m_indexBuffer.Init(PixelBufferDesc, InitPixelBufferDesc);

  m_indexBuffer.Render(offset);
}

void mfMesh::Destroy()
{
  m_vertexBuffer.Destroy();
  m_indexBuffer.Destroy();
}
