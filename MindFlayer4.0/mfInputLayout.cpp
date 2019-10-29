#include "mfInputLayout.h"



mfInputLayout::mfInputLayout()
{
#ifdef mfDIRECTX
  m_inputLayout.ID = NULL;
#endif // mfDIRECTX

}


mfInputLayout::~mfInputLayout()
{
}

HRESULT mfInputLayout::Init(mfVertexShader _VertexShader)
{
  return mfRenderManager::getSingleton().CreateInputLayout(*this, _VertexShader);
}

void mfInputLayout::Render()
{
  mfRenderManager::getSingleton().IASetInputLayout(*this);
}

void mfInputLayout::Destroy()
{
  SAFE_RELEASE(m_inputLayout.ID);
}

mfInputLayoutID & mfInputLayout::getInterface()
{
  return m_inputLayout;
}
