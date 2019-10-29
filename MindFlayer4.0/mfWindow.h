/**
 * @LC	   : 12/10/2019
 * @file   : mfWindow.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 12/10/2019
 * @brief  : Common Window base class.         
 * @bug	   : No known bugs.
 */

/**
 * Headers
 */
#include "mfDefines.h"
#pragma once

 /**
    * @brief : Structure responsible for providing the class ID.
    */
struct mfWindowID
{
#ifdef mfDIRECTX
  /**
    * @brief : Window Identifier.
    */
  HWND ID;
  /**
   * @brief : Instance Identifier.
   */
  HINSTANCE hInst;
#elif defined mfOPENGL
  int ID;
#endif 
};

/**
 * @brief  Register Class descriptor struct
 */
typedef
struct mfRegisterClassWindowDesc
{
  /**
   * Var
   */
  unsigned int cbSize;
  unsigned int style;
  WNDPROC lpfnWndProc;
  int cbClsExtra;
  int cbWndExtra;
  HINSTANCE hInstance;
  HICON hIcon;
  HCURSOR hCursor;
  HBRUSH hbrBackground;
  LPCWSTR lpszMenuName;
  LPCWSTR lpszClassName;
  HICON hIconSm;
}mfRegisterClassWindowDesc;

/**
 * @brief  Window descriptor struct
 */
typedef
struct mfWindowDesc
{
  /**
   * Var
   */
  int width;
  int height;
  int nCmdShow;

}mfWindowDesc;

/**
 * @brief : Common Window base class.
 */
class mfWindow
{
public:
  mfWindow();
  ~mfWindow();
private:
  /**
   * @brief : Structure that provides an ID of the class.
   */
  mfWindowID m_Window;
public:
  /**
    * @brief  : Init window in hardware
    * @param  : mfRegisterClassWindowDesc _Register : Register class, 
                mfWindowDesc _Desc : Create Window
    * @bug    : No known bugs.
    */
  void 
  Init(mfRegisterClassWindowDesc _Register, mfWindowDesc _Desc);
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
    * @brief  : Release object
    * @bug    : No known bugs.
    */
  void 
  Destroy();

  /**
    * @brief  : Return the object desc
    * @bug    : No know Bugs
    */
  mfWindowID getInterface();
};

