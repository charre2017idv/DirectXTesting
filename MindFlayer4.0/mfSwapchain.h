/**
 * @LC	   : 11/10/2019
 * @file   : mfSwapchain.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 11/10/2019
 * @brief  : Class in charge of setting the swap chain and the back buffer
 * @bug	   : No known bugs.
 */

 /**
  * Class Headers
  */
#include "mfDefines.h"
//#include "mfTexture.h"
#pragma once
  /**
    * @brief : Structure responsible for providing the class ID.
    */
struct mfSwapchainID
{
#ifdef mfDIRECTX
  /**
    * @brief : An IDXGISwapChain interface implements one or more surfaces
               for storing rendered data before presenting it to an output.
    */
  IDXGISwapChain* ID;
  /**
   * @brief : Swap chain Descriptor
   */
  DXGI_SWAP_CHAIN_DESC Desc;
  /**
   * @brief : Texture Object for the back buffer
   */
  ID3D11Texture2D* backbuffer;
#endif // mfDIRECTX
};
 /**
  * @brief  Swap chain descriptor struct
  */
typedef
struct mfSwapchainDesc
{
  /**
   * Var
   */
  unsigned int BufferCount;
  unsigned int Width;
  unsigned int Height;
  mf_FORMAT Format;
  unsigned int Numerator;
  unsigned int Denominator;
  mf_USAGE BufferUsage;
  HWND OutputWindow;
  unsigned int Count;
  unsigned int Quality;
  bool Windowed;
}mfSwapchainDesc;

/**
 * @brief : Class in charge of setting the swap chain and the back buffer
 */
class mfSwapchain
{
public:
  mfSwapchain();
  ~mfSwapchain();
private:
  /**
    * @brief : Structure that provides an ID of the class.
    */
  mfSwapchainID m_swapchain;

  /**
   * Functions
   */
public:
  /**
    * @brief  : Init swap chain in API
    * @param  : mfSwapchainDesc &_Desc : Swap chain descriptor
    * @bug    : No know Bugs
    */
  void 
  Init(mfSwapchainDesc &_Desc);
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No know Bugs
    */
  void 
  Update();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No know Bugs
    */
  void 
  Render();
  /**
    * @brief  : Release Object
    * @bug    : No know Bugs
    */
  void 
  Destroy();
  
  /**
  * @brief  : Return the object API representation
  * @bug    : No know Bugs
  */
  mfSwapchainID & getInterface();

  /**
    * @brief  : Function that sets the back buffer
    * @bug    : No know Bugs.
    */
  void setBackBuffer();

  /**
    * @brief  : Function that gets a buffer from a pointer.
    * @param  : UINT _Buffer : Buffer Number.
                __in  REFIID _riid : Type of value of the buffer.
                void **_Surface : Buffer Poiner ID.
    * @bug    : No know Bugs.
    */
  HRESULT GetBuffer
  (
    UINT _Buffer,
    __in  REFIID _riid,
    void **_Surface
  );

  /**
    * @brief  : Function that show information on screen.
    * @param  : UINT _SyncInterval : Interval of data synchronization.
                UINT _Flags : Flags for present data.
    * @bug    : No know Bugs.
    */
  void Present
  (
    UINT _SyncInterval,
    UINT _Flags
  );
};

