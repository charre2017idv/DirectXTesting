#include "mfRenderTarget.h"



mfRenderTarget::mfRenderTarget()
{
#ifdef mfDIRECTX
  m_RenderTarget.ID = NULL;
#endif // mfDIRECTX

}


mfRenderTarget::~mfRenderTarget()
{
}

void mfRenderTarget::Init(mfBaseTextureDesc _Desc)
{
  mfBaseTexture::Init(_Desc);
}

void mfRenderTarget::Destroy()
{
#ifdef mfDIRECTX
  SAFE_RELEASE(m_RenderTarget.ID);
#endif // mfDIRECTX
  mfBaseTexture::Destroy();
}

mfRenderTargetViewID & mfRenderTarget::getInterfaceRT()
{
  return m_RenderTarget;
}
