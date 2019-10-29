/**
 * @LC	   : 12/10/2019
 * @file   : mfTexture.cpp
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 12/10/2019
 * @brief  : Class in charge of provide textures to different classes.
 * @bug	   : No known bugs.
 */
#include "mfTexture.h"



mfTexture::mfTexture()
{
#ifdef mfDIRECTX
  m_texture.ResourceViewID = NULL;
#endif // mfDIRECTX

}


mfTexture::~mfTexture()
{
}

void mfTexture::Init(mfBaseTextureDesc _Desc)
{

  if (_Desc.Filepath == NULL || _Desc.Filepath[0] == 0)
  {
    mfBaseTexture::Init(_Desc);
  }
  else
  {
#ifdef mfDIRECTX
    D3DX11CreateShaderResourceViewFromFile
    (
      mfRenderManager::getSingleton().GetDevice().getInterface().ID,
      _Desc.Filepath,
      NULL,
      NULL,
      &m_texture.ResourceViewID, 
      NULL
    );
#elif defined mfOPENGL

#endif // mfDIRECTX
  }
}

void mfTexture::Render()
{
  //mfRenderManager::getSingleton().PSSetShaderResources(0, 1, *this);
}

void mfTexture::Destroy()
{
  mfBaseTexture::Destroy();
#ifdef mfDIRECTX
  SAFE_RELEASE(m_texture.ResourceViewID);
#endif // mfDIRECTX
}

mfTextureID & mfTexture::getInterface()
{
  return m_texture;
}
