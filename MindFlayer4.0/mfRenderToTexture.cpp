/**
 * @LC	   : 25/10/2019
 * @file   : mfRenderToTexture.cpp
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 25/10/2019
 * @brief  : Class in charge of set render targets to a shader resource.
 * @bug	   : No known bugs.
 */
#include "mfRenderToTexture.h"
#include "mfDepthStencilView.h"


mfRenderToTexture::mfRenderToTexture()
{
}


mfRenderToTexture::~mfRenderToTexture()
{
}

void mfRenderToTexture::Init()
{
  mfBaseTextureDesc RenderTargetToTextureDesc;
  RenderTargetToTextureDesc.Tag = "RENDER_TARGET";
  RenderTargetToTextureDesc.ID = mf_RENDER_TARGET_TEXTURE;
  RenderTargetToTextureDesc.Width = SCREEN_WIDTH;
  RenderTargetToTextureDesc.Height = SCREEN_HEIGHT;
  RenderTargetToTextureDesc.MipLevels = 1;
  RenderTargetToTextureDesc.Arraysize = 1;
  RenderTargetToTextureDesc.TexFormat = mf_FORMAT_R32G32B32A32_FLOAT;
  RenderTargetToTextureDesc.SamplerDescCount = 1;
  RenderTargetToTextureDesc.SamplerDescQuality = 0;
  RenderTargetToTextureDesc.Usage = mf_USAGE_DEFAULT;
  RenderTargetToTextureDesc.Bindflags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
  RenderTargetToTextureDesc.CPUAccessFlags = 0;
  RenderTargetToTextureDesc.MiscFlags = 0;
  RenderTargetToTextureDesc.Filepath = NULL;

  m_RenderToTexture.RenderTargetToTexture.Init(RenderTargetToTextureDesc);

  mfRenderManager::getSingleton().CreateRenderTargetView
  (
    m_RenderToTexture.RenderTargetToTexture
  );
}

void mfRenderToTexture::Render(mfDepthStencilView & _DepthStencilView, float _ClearColor[4])
{
  mfRenderManager::getSingleton().ClearRenderTargetView
  (
    m_RenderToTexture.RenderTargetToTexture, _ClearColor
  );
  mfRenderManager::getSingleton().OMSetRenderTargets
  (
    1,
    m_RenderToTexture.RenderTargetToTexture, 
    _DepthStencilView
  );
}

void mfRenderToTexture::Destroy()
{
  m_RenderToTexture.RenderTargetToTexture.Destroy();
}

mfRenderToTextureID & mfRenderToTexture::getInterface()
{
  return m_RenderToTexture;
}

void mfRenderToTexture::CreateShaderResourceView()
{
  mfRenderManager::getSingleton().CreateShaderResourceView
  (
    m_RenderToTexture.RenderTargetToTexture
  );
}
