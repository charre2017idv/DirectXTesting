/**
 * @LC	   : 13/10/2019
 * @file   : mfPixelShader.cpp
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 13/10/2019
 * @brief  : Class that initialize a pixel shader.
 * @bug	   : No known bugs.
 */
#include "mfPixelShader.h"

mfPixelShader::mfPixelShader()
{
#ifdef mfDIRECTX
  m_pixelShader.ID = NULL;
  m_pixelShader.PSBlob = NULL;
#endif // mfDIRECTX
}


mfPixelShader::~mfPixelShader()
{
}

HRESULT mfPixelShader::Init(mfBaseShaderDesc _Desc)
{
  HRESULT hr = CompileShaderFromFile(_Desc);
  // Compile the pixel shader
#ifdef mfDIRECTX
  if (FAILED(hr))
  {
    MessageBox(NULL,
      L"The FX file cannot be compiled.  Please run this executable from the directory that contains the FX file.", L"Error", MB_OK);
    return hr;
  }
  mfRenderManager::getSingleton().CreatePixelShader(*this);

  m_pixelShader.PSBlob->Release();
  if (FAILED(hr))
    return hr;

  return hr;
#elif defined mfOPENGL
  mfOutputLOG("mfPixelShader", "Init()", "Pixel Shader has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}

void mfPixelShader::Render()
{
#ifdef mfDIRECTX
  mfRenderManager::getSingleton().PSSetShader(*this);
#elif defined mfOPENGL
  mfOutputLOG("mfPixelShader", "Render()", "Render has been Initializated.");
#endif // mfDIRECTX
}

void mfPixelShader::Destroy()
{
#ifdef mfDIRECTX
  SAFE_RELEASE(m_pixelShader.ID);
#endif // mfDIRECTX
}

mfPixelShaderID & mfPixelShader::getInterface()
{
  return m_pixelShader;
}
