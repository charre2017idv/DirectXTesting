/**
 * @LC	   : 15/10/2019
 * @file   : mfBaseShader.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 15/10/2019
 * @brief  : Class in charge of setting a basic structure that will be 
             inhered in different classes.
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "mfDefines.h"
#include "mfRenderManager.h"
#pragma once
 /**
  * @brief  Buffer descriptor struct
  */
typedef
struct mfBaseShaderDesc
{
  /**
   * Var
   */
  WCHAR* FileName;
  const char * EntryPoint;
  const char * ShaderModel;
  ID3DBlob** BlobOut;
}mfBaseShaderDesc;

/**
 * @brief : Class in charge of setting a basic structure that will be
             inhered in different classes.
 */
class mfBaseShader
{
public:
  mfBaseShader();
  ~mfBaseShader();
  /**
   * Members 
   */
private:

  /**
   * Methods
   */
public:
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  HRESULT 
  Init();
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
  Render();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Destroy();
  /**
    * @brief  : Function that is in charge of compiling different shaders.
    * @param  : mfBaseShaderDesc  _Desc : Description for compiling the shaders.
    * @bug    : No known bugs.
    */
  HRESULT CompileShaderFromFile(mfBaseShaderDesc  _Desc);
};

