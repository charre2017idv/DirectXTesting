/**
 * @LC	   : 13/10/2019
 * @file   : mfDepthStencilView.cpp
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 13/10/2019
 * @brief  : Class in charge of creating Depth Stencil Views.
 * @bug	   : No known bugs.
 */
#include "mfDepthStencilView.h"



mfDepthStencilView::mfDepthStencilView()
{
#ifdef mfDIRECTX
  m_DepthStencilView.ID = NULL;
#endif // mfDIRECTX

}


mfDepthStencilView::~mfDepthStencilView()
{
}

void mfDepthStencilView::Init(mfDepthStencilViewDesc _Desc)
{
  m_descriptor = _Desc;
  // Fill Descriptor
#ifdef mfDIRECTX
  m_DepthStencilView.Resource = _Desc.Resource;
#endif // mfDIRECTX
  // Create Depth Stencil View
  mfRenderManager::getSingleton().CreateDepthStencilView(*this);
}

void mfDepthStencilView::Destroy()
{
#ifdef mfDIRECTX
  SAFE_RELEASE(m_DepthStencilView.ID);
#endif // mfDIRECTX
}

mfDepthStencilViewID & mfDepthStencilView::getInterface()
{
  return m_DepthStencilView;
}

mfDepthStencilViewDesc & mfDepthStencilView::getDescriptor()
{
  return m_descriptor;
}
