#include "mfSwapchain.h"



mfSwapchain::mfSwapchain()
{
#ifdef mfDIRECTX
  m_swapchain.ID = NULL;
  m_swapchain.backbuffer = NULL;
  memset(&m_swapchain.Desc, 0, sizeof(m_swapchain.Desc));
#elif defined mfOPENGL
#endif // mfDIRECTX
}


mfSwapchain::~mfSwapchain()
{
}

void mfSwapchain::Init(mfSwapchainDesc & _Desc)
{
#ifdef mfDIRECTX
  DXGI_SWAP_CHAIN_DESC Desc;
  if (_Desc.BufferUsage == mf_USAGE_RENDER_TARGET_OUTPUT)
  {
    m_swapchain.Desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
  }
  m_swapchain.Desc.BufferDesc.Format = (DXGI_FORMAT)_Desc.Format;
  m_swapchain.Desc.BufferCount = _Desc.BufferCount;
  m_swapchain.Desc.BufferDesc.Width = _Desc.Width;
  m_swapchain.Desc.BufferDesc.Height = _Desc.Height;
  m_swapchain.Desc.BufferDesc.RefreshRate.Numerator = _Desc.Numerator;
  m_swapchain.Desc.BufferDesc.RefreshRate.Denominator = _Desc.Denominator;
  m_swapchain.Desc.OutputWindow = _Desc.OutputWindow;
  m_swapchain.Desc.SampleDesc.Count = _Desc.Count;
  m_swapchain.Desc.SampleDesc.Quality = _Desc.Quality;
  m_swapchain.Desc.Windowed = _Desc.Windowed;
#endif // mfDIRECTX

}

void mfSwapchain::Destroy()
{
#ifdef mfDIRECTX
  SAFE_RELEASE(m_swapchain.ID);
#endif // mfDIRECTX
}

mfSwapchainID & mfSwapchain::getInterface()
{
  return m_swapchain;
}


void mfSwapchain::setBackBuffer()
{
//   HRESULT hr = m_swapchain.ID->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&m_backbuffer);
#ifdef mfDIRECTX
  HRESULT hr = GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&m_swapchain.backbuffer);
  if (FAILED(hr))
    mfOutputLOG("mfSwapchain", "setBackBuffer()", "Backbuffer setting fail.");
#elif defined mfOPENGL
#endif // mfDIRECTX
}

HRESULT mfSwapchain::GetBuffer(UINT _Buffer, REFIID _riid, void ** _Surface)
{
#ifdef mfDIRECTX
  return m_swapchain.ID->GetBuffer(_Buffer,_riid,_Surface);
#elif defined mfOPENGL
#endif // mfDIRECTX
  return true;
}

void mfSwapchain::Present(UINT _SyncInterval, UINT _Flags)
{
#ifdef mfDIRECTX
  m_swapchain.ID->Present(_SyncInterval, _Flags);
#elif defined mfOPENGL
#endif // mfDIRECTX
}
