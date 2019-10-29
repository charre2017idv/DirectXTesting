/**
 * @LC	   : 13/10/2019
 * @file   : mfVertexShader.cpp
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 13/10/2019
 * @brief  : Class that initialize a vertex shader.
 * @bug	   : No known bugs.
 */
#include "mfVertexShader.h"



mfVertexShader::mfVertexShader()
{
#ifdef mfDIRECTX
  m_vertexShader.ID = NULL;
  m_vertexShader.VSBlob = NULL;
#endif // mfDIRECTX

}


mfVertexShader::~mfVertexShader()
{
}

HRESULT mfVertexShader::Init(mfBaseShaderDesc _Desc)
{
  HRESULT hr = CompileShaderFromFile(_Desc);
#ifdef mfDIRECTX
  if (FAILED(hr))
  {
    mfOutputLOG("mfVertexShader", "Init()", "Vertex Shader Initialization Failed.");
    return hr;
  }

  hr = mfRenderManager::getSingleton().CreateVertexShader(*this);

  if (FAILED(hr))
  {
    m_vertexShader.VSBlob->Release();
    return hr;
  }
  return hr;
#elif defined mfOPENGL
  mfOutputLOG("mfVertexShader", "Init()", "Vertex Shader has been Initializated.");
  return S_OK;
#endif // mfDIRECTX

}

void mfVertexShader::Render()
{
#ifdef mfDIRECTX
  mfRenderManager::getSingleton().VSSetShader(*this);
#elif defined mfOPENGL
  mfOutputLOG("mfVertexShader", "Render()", "Render has been Initializated.");
#endif // mfDIRECTX
}

void mfVertexShader::Destroy()
{
#ifdef mfDIRECTX
  SAFE_RELEASE(m_vertexShader.ID);
#endif // mfDIRECTX
}

mfVertexShaderID & mfVertexShader::getInterface()
{
  return m_vertexShader;
}
