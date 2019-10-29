/**
 * @LC	   : 13/10/2019
 * @file   : mfVertexShader.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 13/10/2019
 * @brief  : Class that initialize a vertex shader. This class is inherited.
 * @bug	   : No known bugs.
 */

/**
 * Headers
 */
#include "mfBaseShader.h"

#pragma once
/**
 * @brief : Structure responsible for providing the class ID.
 */
struct mfVertexShaderID
{
#ifdef mfDIRECTX
  ID3D11VertexShader* ID;
  ID3DBlob* VSBlob;
#endif // mfDIRECTX

};

/**
 * @brief : Class that initialize a vertex shader.
 */
class mfVertexShader : public mfBaseShader
{
public:
  mfVertexShader();
  ~mfVertexShader();
  /**
   * Variables
   */
private:
  /**
   * @brief : Vertex Shader Pointer ID.
   */
  mfVertexShaderID m_vertexShader;
  /**
   * Functions
   */
public:
  /**
    * @brief  : Function that initialize the Vertex Shader.
    * @bug    : No known bugs.
    */
  HRESULT 
  Init(mfBaseShaderDesc _Desc);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Update();
  /**
    * @brief  : 
    * @bug    : No known bugs.
    */
  void 
  Render();
  /**
    * @brief  : Function that release the Vertex Shader pointer.
    * @bug    : No known bugs.
    */
  void 
  Destroy();
  
  /**
  * @brief  : Return the object API representation
  * @bug    : No know Bugs
  */
  mfVertexShaderID & getInterface();
};

