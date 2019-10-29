#include "mfDepthStencil.h"



mfDepthStencil::mfDepthStencil()
{
}


mfDepthStencil::~mfDepthStencil()
{
}

void mfDepthStencil::Init(mfBaseTextureDesc _Desc)
{
  mfBaseTexture::Init(_Desc);
}

void mfDepthStencil::Destroy()
{
  mfBaseTexture::Destroy();
}
