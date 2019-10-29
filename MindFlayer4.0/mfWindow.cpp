#include "mfWindow.h"



mfWindow::mfWindow()
{
  m_Window.ID = NULL;
#ifdef mfDIRECTX
  m_Window.hInst = NULL;
#endif // mfDIRECTX
}


mfWindow::~mfWindow()
{
}

void mfWindow::Init(mfRegisterClassWindowDesc _Register, mfWindowDesc _Desc)
{
#ifdef mfDIRECTX
  // Register class
  WNDCLASSEX wcex;
  wcex.cbSize = _Register.cbSize; 
  wcex.style = _Register.style;
  wcex.lpfnWndProc = _Register.lpfnWndProc;
  wcex.cbClsExtra = _Register.cbClsExtra;
  wcex.cbWndExtra = _Register.cbWndExtra;
  wcex.hInstance = _Register.hInstance;
  wcex.hIcon = _Register.hIcon;
  wcex.hCursor = _Register.hCursor;
  wcex.hbrBackground = _Register.hbrBackground;
  wcex.lpszMenuName = _Register.lpszMenuName;
  wcex.lpszClassName = _Register.lpszClassName;
  wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_TUTORIAL1);;
  if (!RegisterClassEx(&wcex))
    mfOutputLOG("mfWindow", "Init()", "Register class fail.");
    
  // Create window
  m_Window.hInst = _Register.hInstance;
  RECT rc = { 0, 0, _Desc.width, _Desc.height };
  AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
  m_Window.ID = CreateWindow(
    L"TutorialWindowClass",
    L"Mind Flayer 4.0",
    WS_OVERLAPPEDWINDOW,
    0,
    0,
    rc.right - rc.left, 
    rc.bottom - rc.top,
    NULL,
    NULL,
    NULL,
    NULL);
//   m_Window.ID = CreateWindow(L"TutorialWindowClass", L"Mind Flayer 4.0", WS_OVERLAPPEDWINDOW,
//     CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, m_Window.hInst,
//     NULL);
  if (!m_Window.ID)
    mfOutputLOG("mfWindow", "Init()", "Window Creation fail.");

  ShowWindow(m_Window.ID, _Desc.nCmdShow);
#elif defined mfOPENGL
  mfOutputLOG("mfWindow", "Init()", "Window has been Initializated.");
#endif // mfDIRECTX
}


mfWindowID mfWindow::getInterface()
{
  return m_Window;
}
