#include "mfOpenFile.h"



mfOpenFile::mfOpenFile()
{
}


mfOpenFile::~mfOpenFile()
{
}

void mfOpenFile::Init(mfOpenFileDesc _Desc)
{
  m_wideStringBuffer.resize(MAX_PATH);
  ZeroMemory(&m_OpenFile.Desc, sizeof(m_OpenFile.Desc));
  m_OpenFile.Desc.lStructSize = sizeof(m_OpenFile.Desc);
  m_OpenFile.Desc.hwndOwner = _Desc.hwndOwner;
  m_OpenFile.Desc.lpstrFilter = _Desc.lpstrFilter;
  m_OpenFile.Desc.lpstrFile = &m_wideStringBuffer[0];
  m_OpenFile.Desc.nMaxFile = _Desc.nMaxFile;
  m_OpenFile.Desc.lpstrTitle = _Desc.lpstrTitle;
  m_OpenFile.Desc.lpstrInitialDir = _Desc.lpstrInitialDir;
  m_OpenFile.Desc.Flags = _Desc.Flags;
}

mfOpenFileID & mfOpenFile::getInterface()
{
  return m_OpenFile;
}

string mfOpenFile::getFileString()
{
  int size_needed = WideCharToMultiByte(CP_UTF8, 0, &m_wideStringBuffer[0], (int)m_wideStringBuffer.size(), NULL, 0, NULL, NULL);
  std::string multibyteString(size_needed, 0);
  WideCharToMultiByte(CP_UTF8, 0, &m_wideStringBuffer[0], (int)m_wideStringBuffer.size(), &multibyteString[0], size_needed, NULL, NULL);
  m_OpenFile.Filepath = multibyteString;
  return multibyteString;
}
