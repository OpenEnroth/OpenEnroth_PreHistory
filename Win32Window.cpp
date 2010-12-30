#include "OSWindow.h"
#include "CbmTools.h"
#include "memory_mng.h"


Result::Code Win32InsertCDWindow::SystemMessageHandler(unsigned int uMsg, unsigned int wParam, long *lParam)
{
 if (uMsg == WM_PAINT)
 {
  RECT rcUpdate;
  if (GetUpdateRect(hWindow, &rcUpdate, true))
  {
   PAINTSTRUCT ps;
   BeginPaint(hWindow, &ps);
     BitBlt(ps.hdc, ps.rcPaint.left, ps.rcPaint.top, ps.rcPaint.right, ps.rcPaint.bottom,
            hWindowBackgroundDC, ps.rcPaint.left, ps.rcPaint.top, SRCCOPY);
   EndPaint(hWindow, &ps);
  }
  return Result::Success;
 }
 else if (uMsg == WM_KEYUP)
 {
  if (wParam == VK_ESCAPE)
  {
   bVisible = false;
   ShowWindow(hWindow, SW_HIDE);

   return Result::Success;
  }
 }
 else if (uMsg == WM_CLOSE)
   return OnClose();

 return Result::Generic;
}



Result::Code Win32InsertCDWindow::Close()
{
 return OnClose();
}



Result::Code Win32InsertCDWindow::OnClose()
{
 SelectObject(hWindowBackgroundDC, hWindowBackgroundBackbuffer);
 DeleteObject(hWindowBackgroundImage);
 DeleteDC(hWindowBackgroundDC);
 ReleaseDC(hWindow, hWindowDC);

 MSG msg;
 while (PeekMessageW(&msg, hWindow, 0, 0, PM_REMOVE));

 DestroyWindow(hWindow);
 DestroyIcon(hWindowIcon);

 return Result::Success;
}

Result::Code Win32InsertCDWindow::Initialize(const wchar_t *pWindowClassName, const wchar_t *pWindowCaption, unsigned int uCreationParams)
{
 lstrcpyW(pClassName, pWindowClassName);
 lstrcpyW(pWindowName, pWindowCaption);
 uCreationFlags = uCreationParams;

 if (uCreationFlags & WindowCreationParams::Unique)
 {
  hWindow = FindWindowW(pClassName, 0);
  if (hWindow)
  {
   if (IsIconic(hWindow))
     ShowWindow(hWindow, SW_RESTORE);

   SetWindowLongPtrW(hWindow, GWL_STYLE, (LONG_PTR)(WS_OVERLAPPEDWINDOW | WS_VISIBLE));
   ShowWindow(hWindow, SW_SHOWNORMAL);
   UpdateWindow(hWindow);

   SetForegroundWindow(GetLastActivePopup(hWindow));
   return Result::Generic;
  }
 }

 wcxw.cbClsExtra = 0;
 wcxw.cbSize = sizeof(WNDCLASSEXW);
 wcxw.cbWndExtra = 0;
 wcxw.hbrBackground = 0;
 wcxw.hCursor = LoadCursorW(nullptr, (const wchar_t *)(IDC_ARROW));
 wcxw.hIcon = wcxw.hIconSm = hWindowIcon = (HICON)LoadImageW(nullptr, L"data\\mm7.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);
 wcxw.hInstance = GetModuleHandleW(nullptr);
 wcxw.lpfnWndProc = (WNDPROC)(wWin32DefaultWinProc);
 wcxw.lpszClassName = pClassName;
 wcxw.lpszMenuName = 0;
 wcxw.style = CS_OWNDC;
 RegisterClassExW(&wcxw);

 if (uCreationParams & WindowCreationParams::Framed)
   hWindow = CreateWindowExW(0, pClassName, pWindowName, WS_OVERLAPPEDWINDOW, 0, 0, 1, 1, 0, 0, wcxw.hInstance, this);
 else hWindow = CreateWindowExW(0, pClassName, pWindowName, WS_POPUP, 0, 0, 1, 1, 0, 0, wcxw.hInstance, this);


 unsigned int  uBackgroundWidth,
               uBackgroundHeight,
              *pBackgroundPixels;
 LoadPNG(L"data\\logo.png", &uBackgroundWidth, &uBackgroundHeight, &pBackgroundPixels);

 hWindowDC = GetDC(hWindow);
 hWindowBackgroundDC = CreateCompatibleDC(hWindowDC);
 hWindowBackgroundImage = CreateCompatibleBitmap(hWindowDC, uBackgroundWidth, uBackgroundHeight);
 hWindowBackgroundBackbuffer = (HBITMAP)SelectObject(hWindowBackgroundDC, hWindowBackgroundImage);

 BITMAPINFO bmi;
 bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
 bmi.bmiHeader.biWidth = uBackgroundWidth;
 bmi.bmiHeader.biHeight = -(signed)uBackgroundHeight;
 bmi.bmiHeader.biPlanes = 1;
 bmi.bmiHeader.biBitCount = 32;
 bmi.bmiHeader.biCompression = BI_RGB;
 bmi.bmiHeader.biSizeImage = 0;

 GetDIBits(hWindowBackgroundDC, hWindowBackgroundImage, 0, uBackgroundHeight, 0, &bmi, DIB_RGB_COLORS);
 SetDIBits(hWindowBackgroundDC, hWindowBackgroundImage, 0, uBackgroundHeight, pBackgroundPixels, &bmi, DIB_RGB_COLORS);

 MemFree(pBackgroundPixels);
 return Result::Success;
}




long *__stdcall wWin32DefaultWinProc(HWND hwnd, unsigned int msg, unsigned int wparam, long *lparam)
{
 if (msg == WM_NCCREATE || msg == WM_NCCALCSIZE)
   return (long *)DefWindowProcW(hwnd, msg, wparam, (LPARAM)(lparam));
 if (msg == WM_CREATE)
 {
  CREATESTRUCTW *pCS = (CREATESTRUCTW *)(lparam);
  SetWindowLongPtrW(hwnd, GWLP_USERDATA, (LONG_PTR)(pCS->lpCreateParams));
  return (long *)DefWindowProcW(hwnd, msg, wparam, (LPARAM)(lparam));
 }

 Win32Window *pTarget = (Win32Window *)(GetWindowLongPtrW(hwnd, GWLP_USERDATA));
 if (!pTarget->SystemMessageHandler(msg, wparam, lparam))
   return 0;
 else return (long *)DefWindowProcW(hwnd, msg, wparam, (LPARAM)(lparam));
}




Win32InsertCDWindow::Win32InsertCDWindow():
  Win32Window()
{
}

Win32InsertCDWindow::~Win32InsertCDWindow()
{
}

Win32Window::Win32Window():
  OSWindow()
{
}

Win32Window::~Win32Window()
{
}