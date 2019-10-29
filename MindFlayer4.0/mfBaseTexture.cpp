#include "mfBaseTexture.h"



mfBaseTexture::mfBaseTexture()
{
  m_TextureType = mf_UNKNOWN_TEXTURE;
#ifdef mfDIRECTX
  m_baseTexture.ID = NULL;
#endif // mfDIRECTX
}


mfBaseTexture::~mfBaseTexture()
{
}

void mfBaseTexture::Init(mfBaseTextureDesc _Desc)
{
  m_descriptor = _Desc;
#ifdef mfDIRECTX
    mfRenderManager::getSingleton().CreateTexture2D(*this);
#endif // mfDIRECTX
}

void mfBaseTexture::Destroy()
{
#ifdef mfDIRECTX
  SAFE_RELEASE(m_baseTexture.ID);
#endif // mfDIRECTX
}

mfBaseTextureID & mfBaseTexture::getInterface()
{
  return m_baseTexture;
}

mfTextureType & mfBaseTexture::getTextureType()
{
  return m_TextureType;
}


mfBaseTextureDesc & mfBaseTexture::getDescriptor()
{
  return m_descriptor;
}
