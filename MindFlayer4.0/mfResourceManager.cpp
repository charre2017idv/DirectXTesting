#include "mfResourceManager.h"
#include "stb_image.h"



mfResourceManager::mfResourceManager()
{
}


mfResourceManager::~mfResourceManager()
{
}

void mfResourceManager::onPrepare()
{
  mfOutputLOG("mfResourceManager", "onPrepare()", "Module has been Initializated.");
}

void mfResourceManager::Destroy()
{
  m_ResourceManager.clear();
}

void mfResourceManager::LoadModel(const char * _Path)
{
  mfRawModelData tmpRawData;
  tmpRawData.Path = _Path;
  // Assign content of mesh to Model variable
  Model = aiImportFile(_Path, aiProcessPreset_TargetRealtime_MaxQuality);

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
    m_VertexArray = Model->mMeshes[i]->mVertices;
    m_IndexArray = mIndices;
    m_textCoord = Model->mMeshes[i]->mTextureCoords[0];
    tmpRawData.VertexSize = Model->mMeshes[i]->mNumVertices;
    tmpRawData.IndexSize = Model->mMeshes[i]->mNumFaces * 3;
  }
  // Allocate Texture names
  string textName;
  for (unsigned int i = 0; i < Model->mNumMeshes; i++)
  {
    const aiMaterial* modelMaterial = Model->mMaterials[Model->mMeshes[i]->mMaterialIndex];
    if (modelMaterial->GetTextureCount(aiTextureType_DIFFUSE) > 0)
    {
      aiString Path;
      if (modelMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &Path, NULL, NULL, NULL, NULL, NULL) == AI_SUCCESS)
      {
        textName += (std::string)Path.data;
        tmpRawData.TextureNames.push_back(textName);
        textName.clear();
      }
    }
  }

  // Allocate the indices amount to a private variable
  m_numIndex = tmpRawData.IndexSize;
#ifdef mfDIRECTX
  tmpRawData.Vertex = new SimpleVertex[tmpRawData.VertexSize];
  for (size_t i = 0; i < tmpRawData.VertexSize; i++)
  {
    // Allocate Vertices
    tmpRawData.Vertex[i].Pos.x = m_VertexArray[i].x;
    tmpRawData.Vertex[i].Pos.y = m_VertexArray[i].y;
    tmpRawData.Vertex[i].Pos.z = m_VertexArray[i].z;
    // Allocate Texture Coordinates
    if (m_textCoord == NULL)
    {
      tmpRawData.Vertex[i].Tex.x = 1;
      tmpRawData.Vertex[i].Tex.y = 1;
    }
    else
    {
      tmpRawData.Vertex[i].Tex.x = m_textCoord[i].x;
      tmpRawData.Vertex[i].Tex.y = -m_textCoord[i].y;
    }
  }

  // Allocate the information on Index Array
  tmpRawData.Index = new WORD[tmpRawData.IndexSize];
  for (size_t i = 0; i < tmpRawData.IndexSize; i++)
  {
    // Allocate Indices
    tmpRawData.Index[i] = (WORD)m_IndexArray[i];
  }
#endif // mfDIRECTX
  // Allocate the information on Vertex Structure
  mfResourceID tmpResourceID;

  tmpResourceID.ModelRawData = tmpRawData;
  // Allocate Resource
  m_ResourceManager.push_back(tmpResourceID);
}

void mfResourceManager::LoadTexture(const char * _Path)
{
  // Create temp texture data to allocate the pointer and path of the texture.
  mfRawTextureData tmpRawData;
  // Allocate the texture path.
  tmpRawData.Path = _Path;
#ifdef mfDIRECTX
  string tmpPath = _Path;
  ID3D11ShaderResourceView* tmpShaderResource;
  std::wstring stemp = std::wstring(tmpPath.begin(), tmpPath.end());
  LPCWSTR newPath = stemp.c_str();
  D3DX11CreateShaderResourceViewFromFile
  (
    mfRenderManager::getSingleton().GetDevice().getInterface().ID,
    newPath,
    NULL,
    NULL,
    &tmpShaderResource,
    NULL
  );
  // Allocate the shader resource pointer.
  tmpRawData.textureID = tmpShaderResource;
  // Create temp resource to allocate the texture raw data.
  mfResourceID tmpResourcesID;
  // Allocate the temp texture raw data in the resource.
  tmpResourcesID.TextureRawData = tmpRawData;
  // Allocate Resource
  m_ResourceManager.push_back(tmpResourcesID);
#elif defined mfOPENGL
int width = 0;
  int height = 0;
  int BPP = 0;
  string filepath = _Path;
  unsigned char* localBuffer = NULL;
  // Flip textures because OPENGL texture starts at bottom left (0,0).
  stbi_set_flip_vertically_on_load(1);
  localBuffer = stbi_load(_Path, &width, &height, &BPP, 4);

  if (localBuffer)
  {
    stbi_image_free(localBuffer);
  }
#endif // mfDIRECTX
}

vector<mfResourceID> & mfResourceManager::getRawData()
{
  if (m_ResourceManager.size() != 0)
  {
    return m_ResourceManager;
  }
  else
  {
    mfOutputLOG("mfRawModelData", "getRawData()", "Data vector size is cero.");
  }
}

void mfResourceManager::DestroyRawModelData(int i)
{
  m_ResourceManager.erase(m_ResourceManager.begin() + i);
}

void mfResourceManager::DestroyRawTextureData()
{
  //m_ResourceManager.
}
