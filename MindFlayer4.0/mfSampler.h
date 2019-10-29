/**
 * @LC	   : 13/10/2019
 * @file   : mfSampler.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 13/10/2019
 * @brief  : Class in charge of setting the samplers.
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
struct mfSamplerID
{
#ifdef mfDIRECTX
  /**
   * @brief : DirectX 11's own resource that serves as an identifier and
  which can be accessed during execution
   */
  ID3D11SamplerState* ID;
#endif // mfDIRECTX
};

/**
 * @brief  Swap chain descriptor struct
 */
typedef
struct mfSamplerDesc
{
  /**
   * Var
   */
  mf_FILTER Filter;
  mf_TEXTURE_ADDRESS_MODE AddressU;
  mf_TEXTURE_ADDRESS_MODE AddressV;
  mf_TEXTURE_ADDRESS_MODE AddressW;
  mf_COMPARISON_FUNC ComparisionFunc;
  float MinLOD;
  float MaxLOD;
}mfSamplerDesc;

/**
 * @brief : Class in charge of setting the samplers.
 */
class mfSampler
{
public:
  mfSampler();
  ~mfSampler();
private:
  /**
   * @brief : Structure that provides an ID of the class.
   */
  mfSamplerID m_Sampler;
  /**
   * @brief : 
   */
  mfSamplerDesc m_descriptor;
public:
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Init(mfSamplerDesc _Desc);
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
  mfSamplerID & getInterface();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : 
    */
  mfSamplerDesc & getDescriptor();
};

