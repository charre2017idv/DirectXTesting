/**
 * @LC	   : 21/10/2019
 * @file   : mfResourceManager
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 21/10/2019
 * @brief  : Class in charge of providing multiple resources in the project.
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "mfModule.h"
#include "mfRenderManager.h"
#include "mfDefines.h"
#include "Assimp/scene.h"
#include "Assimp/ai_assert.h"
#include "Assimp/cimport.h"
#include "Assimp/postprocess.h"
#include "Assimp/Importer.hpp"
#include "Assimp/material.h"
#pragma once
/**
 * @brief : Structure that allocate the Model raw information.
 */
struct mfRawModelData
{
#ifdef mfDIRECTX
  /**
   * @brief : Structure responsible for storing the necessary data for
              vertex shader input, each variable that it contains is
              necessary for the proper functioning of the shader.
   */
  SimpleVertex* Vertex = NULL;
  /**
   * @brief : WORD type arrangement that stores mesh indices.
   */
  WORD* Index = NULL;
#elif defined mfOPENGL
#endif // mfDIRECTX
  const char * Path;
  int VertexSize = 0;
  int IndexSize = 0;
  vector<string> TextureNames;
};

/**
 * @brief : Structure that allocate the texture raw information.
 */
struct mfRawTextureData
{
  const char * Path;
#ifdef mfDIRECTX
  ID3D11ShaderResourceView* textureID;
#elif defined mfOPENGL
  int ID;
#endif // mfDIRECTX
};

/**
 * @brief : Structure that allocates the Raw information of the resource manager.
 */
struct mfResourceID
{
  /**
   * @brief : Structure that allocates the information of the loaded mesh that
              will be used when a new model is created.
   */
  mfRawModelData ModelRawData;
  /**
   * @brief : 
   */
  mfRawTextureData TextureRawData;

};

/**
 * @brief : Class in charge of providing multiple resources in the project.
 */
class mfResourceManager : public mfModule<mfResourceManager>
{
public:
  mfResourceManager();
  ~mfResourceManager();
  /**
   * Members 
   */
private:
  /**
   * @brief : Structure that provides an ID of the class with the raw data.
   */
  vector<mfResourceID> m_ResourceManager;

  /**
   * @brief : Essential object for loading meshes to the environment,
              only manipulate if you find a better place for loading files.
   */
  const aiScene* Model;
  /**
   * @brief : Variable to store the amount of indices.
   */
  int m_numIndex;
  /**
   * @brief : Temporal Vector that has the mesh vertices.
   */
  aiVector3D * m_VertexArray;
  /**
   * @brief : Temporal Vector that has the mesh indices.
   */
  std::vector<std::uint32_t> m_IndexArray;
  /**
   * @brief : Temporal Vector that has the mesh texture coordinates.
   */
  aiVector3D * m_textCoord;

  /**
   * Methods 
   */
public:
  /**
  * @brief  : Function that initialize the module.
  * @bug    : No know bugs.
  */
  virtual void onPrepare() override;
  /**
    * @brief  : Function in charge of release modules.
    * @bug    : No know bugs.
    */
  virtual void onShutDown() override {}
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void Init();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void Destroy();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void LoadModel(const char* _Path);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void LoadTexture(const char * _Path);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  vector<mfResourceID> & getRawData();
  /**
    * @brief  : Function that erase an specific element of the resource vector.
    * @param  : int i : Index value for erased element.
    * @bug    : No know bugs.
    */
  void DestroyRawModelData(int i);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  void DestroyRawTextureData();
};

