/**
 * @LC	   : 13/10/2019
 * @file   : mfDepthStencilView.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 13/10/2019
 * @brief  : Class in charge of creating Depth Stencil Views.
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "mfDefines.h"
#include "mfRenderManager.h"
#pragma once
 /**
    * @brief : Structure responsible for providing the class ID.
    */
struct mfDepthStencilViewID
{
#ifdef mfDIRECTX
  /**
   * @brief : DirectX 11's own resource that serves as an identifier and
  which can be accessed during execution
   */
  ID3D11DepthStencilView* ID;
  /**
   * @brief : Depth Stencil Description
   */
  //D3D11_DEPTH_STENCIL_VIEW_DESC Desc;
  /**
   * @brief : Object that receives any DirectX pointer.
   */
  ID3D11Resource * Resource;
#endif // mfDIRECTX
};

/**
 * @brief : Structure that helps fill the depth Stencil view descriptor.
 */
struct mfDepthStencilViewDesc
{
  /**
   * Variables
   */
  mf_FORMAT texFormat;
  mf_DSV_DIMENSION ViewDimension;
  unsigned int MipSlice;
  /**
   * @brief : Object that receives any DirectX pointer.
   */
  ID3D11Resource * Resource;
};

/**
 * @brief : Class in charge of creating Depth Stencil Views.
 */
class mfDepthStencilView
{
public:
  mfDepthStencilView();
  ~mfDepthStencilView();
private:
  /**
   * @brief : Structure that provides an ID of the class.
   */
  mfDepthStencilViewID m_DepthStencilView;

  /**
   * @brief : 
   */
  mfDepthStencilViewDesc m_descriptor;
  /**
   * Functions 
   */
public:
  /**
    * @brief  : Initializes the Depth Stencil View descriptor.
    * @param  : mfDepthStencilViewDesc _Desc : Depth Stencil view Descriptor 
    * @bug    : No known bugs.
    */
  void 
  Init(mfDepthStencilViewDesc _Desc);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Update();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Render();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Destroy();

  /**
  * @brief  : Return the object API representation
  * @bug    : No know Bugs
  */
  mfDepthStencilViewID & getInterface();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  mfDepthStencilViewDesc & getDescriptor();
  };

