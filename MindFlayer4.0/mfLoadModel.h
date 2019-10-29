/**
 * @LC	   : 16/10/2019
 * @file   : mfLoadModel.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 16/10/2019
 * @brief  : This class is responsible for loading a file through the Assimp library,
            it has two structures that will handle the information of the file,
            one that will obtain its attributes (modelDescriptor) and another
            that will store the attributes (modelData). This way you will have
            a structure at all times with the information of the model ready
            to be used.
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "mfDefines.h"
#include "Assimp/scene.h"
#include "Assimp/ai_assert.h"
#include "Assimp/cimport.h"
#include "Assimp/postprocess.h"
#include "Assimp/Importer.hpp"
#include "Assimp/material.h"
#pragma once
class mfTexture;
/**
 * @brief : Load Model descriptor struct.
 */
struct mfLoadModelDesc
{
  aiVector3D * VertexArray;
  std::vector<std::uint32_t> IndexArray;
  aiVector3D * textCoord;
  int VertexSize;
  int IndexSize;
};
/**
 * @brief : This class is responsible for loading a file through the Assimp library,
            it has two structures that will handle the information of the file, 
            one that will obtain its attributes (modelDescriptor) and another
            that will store the attributes (modelData). This way you will have
            a structure at all times with the information of the model ready 
            to be used.
 */
struct mfLoadModelID
{
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

  int VertexSize = 0;
  int IndexSize = 0;
  vector<string> textNames;
};
class mfLoadModel
{
public:
  mfLoadModel();
  ~mfLoadModel();
private:
  mfLoadModelID m_LoadModel;
  /**
   * @brief : Descriptor that stores all the information of the loaded mesh.
   */
  mfLoadModelDesc m_Desc;
private:
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
   * @brief : 
   */
  string TexName;
public:
  /**
    * @brief  : This function receives the address of the mesh which will be
                read to obtain its attributes.
    * @param  : const char * filepath : File path of the mesh.
    * @bug    : No known bugs.
    */
  void 
  Init(const char * filepath);
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
    * @brief  : It is necessary to have a function that receives the data
                from the model descriptor in order to store it in a structure
                that can be manipulated at all times.
    * @param  : mfLoadModelDesc desc : Model Descriptor.
    * @bug    : No known bugs.
    */
  void AssignModelData(mfLoadModelDesc desc);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  mfLoadModelID & getInterface();
};

