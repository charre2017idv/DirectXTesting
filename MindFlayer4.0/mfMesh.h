/**
 * @LC	   : 16/10/2019
 * @file   : mfMesh.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 16/10/2019
 * @brief  : Class that set a mesh.
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "mfDefines.h"
#include "mfVertexBuffer.h"
#include "mfPixelBuffer.h"
#include "mfLoadModel.h"
#pragma once
/**
 * @brief :  Class that set a mesh.
 */
class mfMesh
{
public:
  mfMesh();
  ~mfMesh();
  /**
   * Members 
   */
private:
  /**
   * @brief : Vertex Buffer Object.
   */
  mfVertexBuffer m_vertexBuffer;
  /**
   * @brief : Index Buffer Object.
   */
  mfIndexBuffer m_indexBuffer;
  /**
   * @brief : Variable that stores the number of indices.
   */
  int m_indexSize = 0;
public:
  /**
   * Methods
   */
public:
  /**
    * @brief  : Function that takes the data from the loaded mesh.
    * @param  : mfLoadModelID _Data : Load Model Data struct.
    * @bug    : No known bugs.
    */
  void 
  Init(mfLoadModelID _Data);
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
    * @brief  : Function that returns the num of index of mesh.
    * @bug    : No known bugs.
    */
  int getIndexSize() { return m_indexSize; }
};

