/**
 * @LC	   : 15/10/2019
 * @file   : mfBaseShader.cpp
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 15/10/2019
 * @brief  : Class in charge of setting a basic structure that will be
             inhered in different classes.
 * @bug	   : No known bugs.
 */
#include "mfBaseShader.h"



mfBaseShader::mfBaseShader()
{
}


mfBaseShader::~mfBaseShader()
{
}

HRESULT mfBaseShader::CompileShaderFromFile(mfBaseShaderDesc _Desc)
{
#ifdef mfDIRECTX
  HRESULT hr = S_OK;

  DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
  // Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
  // Setting this flag improves the shader debugging experience, but still allows 
  // the shaders to be optimized and to run exactly the way they will run in 
  // the release configuration of this program.
  dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

  ID3DBlob* pErrorBlob;
  hr = D3DX11CompileFromFile(_Desc.FileName, NULL, NULL, _Desc.EntryPoint, _Desc.ShaderModel,
    dwShaderFlags, 0, NULL, _Desc.BlobOut, &pErrorBlob, NULL);
  if (FAILED(hr))
  {
    if (pErrorBlob != NULL)
      OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
    if (pErrorBlob) pErrorBlob->Release();
    return hr;
  }
  if (pErrorBlob) pErrorBlob->Release();

  return S_OK;
#elif defined mfOPENGL
  mfOutputLOG("mfBaseShader", "CompileShaderFromFile()", "Compilation has been Initializated.");
  return S_OK;
#endif // mfDIRECTX
}
