/**
 * @LC	   : 21/10/2019
 * @file   : mfMaterial.cpp
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 17/10/2019
 * @brief  : Class in charge of creating a new material.
 * @bug	   : No known bugs.
 */
#include "mfMaterial.h"



mfMaterial::mfMaterial()
{
}


mfMaterial::~mfMaterial()
{
}

void mfMaterial::Init(mfTexture _Texture)
{
  m_Material.Textures.push_back(_Texture);
}

void mfMaterial::Render(int _TexIndex)
{
  for (int i = 0; i < m_Material.Textures.size(); i++)
  {
    mfRenderManager::getSingleton().PSSetShaderResources(0, 1, m_Material.Textures[_TexIndex]);
  }
}

void mfMaterial::Destroy()
{
  for (int i = 0; i < m_Material.Textures.size(); i++)
  {
    m_Material.Textures[i].Destroy();
  }
}

mfMaterialID & mfMaterial::getInterface()
{
  return m_Material;
}
