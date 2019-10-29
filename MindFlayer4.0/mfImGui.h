/**
 * @LC	   : 18/10/2019
 * @file   : mfImGui.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 18/10/2019
 * @brief  : Class in charge of setting the ImGui interface.
 * @bug	   : No known bugs.
 */

/**
 * Headers 
 */
#include "mfDefines.h"
#include "ImGui/ImGuiDirectX/imgui.h"
#include "ImGui/ImGuiDirectX/imgui_impl_dx11.h"
#include "ImGui/ImGuiDirectX/imgui_impl_win32.h"
#pragma once
class mfDevice;
class mfDeviceContext;
class mfWindow;
/**
 * @brief : 
 */
struct mfImGuiDesc
{
#ifdef mfDIRECTX
  
#endif // mfDIRECTX

};
/**
 * @brief :  Class in charge of setting the ImGui interface.
 */
class mfImGui
{
public:
  mfImGui();
  ~mfImGui();
  /**
   * Members 
   */
private:

  /**
   * Methods 
   */
  public:
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
    
  void 
  Init(mfDevice _Device, mfDeviceContext _DevContext, mfWindow _window);
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
  
};

