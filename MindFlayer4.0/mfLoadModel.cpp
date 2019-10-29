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

#include "mfLoadModel.h"


mfLoadModel::mfLoadModel()
{
}


mfLoadModel::~mfLoadModel()
{
}

void mfLoadModel::Init(const char * _filepath)
{
  // Assign content of mesh to Model variable
  Model = aiImportFile(_filepath, aiProcessPreset_TargetRealtime_MaxQuality);

  for (size_t i = 0; i < Model->mNumMeshes; i++)
  {
    std::vector<std::uint32_t> mIndices;
    mIndices.reserve(Model->mMeshes[i]->mNumFaces * 3);
    // Allocate the indices of the mesh
    for (size_t j = 0; j < Model->mMeshes[i]->mNumFaces; j++)
    {
      mIndices.push_back(Model->mMeshes[i]->mFaces[j].mIndices[0u]);
      mIndices.push_back(Model->mMeshes[i]->mFaces[j].mIndices[1u]);
      mIndices.push_back(Model->mMeshes[i]->mFaces[j].mIndices[2u]);
    }
    // Send the information of the mesh to allocated in a mesh object.
    m_Desc.VertexArray = Model->mMeshes[i]->mVertices;
    m_Desc.IndexArray = mIndices;
    m_Desc.textCoord  = Model->mMeshes[i]->mTextureCoords[0];
    m_Desc.VertexSize = Model->mMeshes[i]->mNumVertices;
    m_Desc.IndexSize  = Model->mMeshes[i]->mNumFaces * 3;
  }
  
  for (unsigned int i = 0; i < Model->mNumMeshes; i++)
  {
    const aiMaterial* modelMaterial = Model->mMaterials[Model->mMeshes[i]->mMaterialIndex];
    if (modelMaterial->GetTextureCount(aiTextureType_DIFFUSE) > 0)
    {
      aiString Path;
      if (modelMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &Path, NULL, NULL, NULL, NULL, NULL) == AI_SUCCESS)
      {
        TexName += (std::string)Path.data;
        m_LoadModel.textNames.push_back(TexName);
        TexName.clear();
      }
    }
  }   

  
  AssignModelData(m_Desc);
}

void mfLoadModel::AssignModelData(mfLoadModelDesc _desc)
{
  // Allocate the indices amount to a private variable
  m_numIndex = _desc.IndexSize;
  m_LoadModel.VertexSize = _desc.VertexSize;
  m_LoadModel.IndexSize  = _desc.IndexSize;

  // Allocate the information on Vertex Structure
  m_LoadModel.Vertex = new SimpleVertex[m_LoadModel.VertexSize];
  for (size_t i = 0; i < m_LoadModel.VertexSize; i++)
  {
    // Allocate Vertices
    m_LoadModel.Vertex[i].Pos.x = _desc.VertexArray[i].x;
    m_LoadModel.Vertex[i].Pos.y = _desc.VertexArray[i].y;
    m_LoadModel.Vertex[i].Pos.z = _desc.VertexArray[i].z;
    // Allocate Texture Coordinates
    if (_desc.textCoord == NULL)
    {
      m_LoadModel.Vertex[i].Tex.x = 1;
      m_LoadModel.Vertex[i].Tex.y = 1;
    }
    else
    {
      m_LoadModel.Vertex[i].Tex.x = _desc.textCoord[i].x;
      m_LoadModel.Vertex[i].Tex.y = -_desc.textCoord[i].y;
    }
  }

  // Allocate the information on Index Array
  m_LoadModel.Index = new WORD[m_LoadModel.IndexSize];
  for (size_t i = 0; i < m_LoadModel.IndexSize; i++)
  {
    // Allocate Indices
    m_LoadModel.Index[i] = (WORD)_desc.IndexArray[i];
  }
}

mfLoadModelID & mfLoadModel::getInterface()
{
  return m_LoadModel;
}
