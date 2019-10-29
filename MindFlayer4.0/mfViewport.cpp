/**
 * @LC	   : 13/10/2019
 * @file   : mfViewport.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 13/10/2019
 * @brief  : Class in charge of setting the viewport.
 * @bug	   : No known bugs.
 */
#include "mfViewport.h"



mfViewport::mfViewport()
{
}


mfViewport::~mfViewport()
{
}

void mfViewport::Init(mfViewportDesc _Desc)
{
  m_descriptor = _Desc;
  mfRenderManager::getSingleton().RSSetViewports(*this);
}

mfViewportDesc & mfViewport::getDescriptor()
{
  return m_descriptor;
}