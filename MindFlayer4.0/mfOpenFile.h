/**
 * @LC	   : 17/10/2019
 * @file   : mfOpenFile.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 17/10/2019
 * @brief  : Class in charge of setting parameters to open the file browser.
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
struct mfOpenFileID
{
  OPENFILENAME Desc;
  string Filepath;
};
/**
 * @brief : Open file descriptor struct.
 */
struct mfOpenFileDesc
{
  HWND hwndOwner;
  LPCWSTR lpstrFilter;
  DWORD nMaxFile;
  LPCWSTR lpstrTitle;
  LPCWSTR lpstrInitialDir;
  DWORD Flags;
};
/**
 * @brief : Class in charge of setting parameters to open the file browser.
 */
class mfOpenFile
{
public:
  mfOpenFile();
  ~mfOpenFile();
  /**
   * Members 
   */
private:
  /**
   * @brief : Structure that provides an ID of the class.
   */
  mfOpenFileID m_OpenFile;
  /**
   * @brief : Empty buffer for initialization. 
   */
  wstring m_wideStringBuffer = L"";
  /**
   * Functions 
   */
public:
  /**
    * @brief  : Function that initialize the descriptor.
    * @param  : mfOpenFileDesc _Desc : Open File descriptor.
    * @bug    : The Initial Directory don't open the correct path.
    */
  void 
  Init(mfOpenFileDesc _Desc);
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
* @brief  : Return the object API representation.
* @bug    : No know Bugs.
*/
  mfOpenFileID & getInterface();
  /**
    * @brief  : function that allocate the path of the selected file.
    * @bug    : No known bugs.
    */
  string getFileString();
};

