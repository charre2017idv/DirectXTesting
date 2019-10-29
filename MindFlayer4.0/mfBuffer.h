/**
 * @LC	   10/10/2019
 * @file   mfBuffer.h
 * @Author Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   10/10/2019
 * @brief  Common buffer base class. This represent something in memory, 
           also this is a virtual base class
 * @bug	   No known bugs.
 */

/**
 * Class Headers
 */
#include "mfDefines.h"
#include "mfRenderManager.h"
/**
 * @brief : 
 */
struct mfBufferID
{
#if defined(mfDIRECTX)
  /**
   * @brief  DirectX buffer interface
   */
  ID3D11Buffer* ID;
#endif
};
/**
 * @brief  Buffer descriptor struct
 */

struct mfBufferDesc
{

  /**
   * Var
   */
  mf_USAGE Usage;
  unsigned int ByteWidth;
  unsigned int BindFlags;
  unsigned int CPUAccessFlags;
  unsigned int MiscFlags = 0;
  unsigned int StructureByteStride = 0;
};

/**
 * @brief  Common buffer base class. This represent something in memory,
 *         also this is a virtual base class.
 */
#pragma once
class mfBuffer
{
public:
  mfBuffer();
  virtual ~mfBuffer();

  /**
   * Var
   */
private:
  /**
   * @brief : 
   */
  mfBufferID m_buffer;
protected:
  /**
   * @brief  Buffer Descriptor
   */
  mfBufferDesc m_descriptor;

  /**
   * Functions
   */
public:

  /**
    * @brief  : Init API buffer in hardware
    * @param  : mfBufferDesc _Desc: Buffer desc
    * @bug    : No know Bugs
    */
  void Init(mfBufferDesc _Desc);

  /**
    * @brief  : Update buffer if needed
    * @param  : void* _Data: Pointer to update data(Must be same size has buffer)
    * @bug    : No know Bugs
    */
  void Update(void *_Data);

  /**
    * @brief  : Set buffer in render pipeline
    * @param  : unsigned int _BufferIndex
    * @bug    : No know Bugs
    */
  void Render(unsigned int _BufferIndex);

  /**
    * @brief  : Release Object
    * @bug    : No know Bugs
    */
  void Destroy();

  /**
    * @brief  : Return the object API representation
    * @bug    : No know Bugs
    */
  mfBufferID & getInterface();

  /**
    * @brief  : Return the object desc
    * @bug    : No know Bugs
    */
  mfBufferDesc& getDescriptor();
};

