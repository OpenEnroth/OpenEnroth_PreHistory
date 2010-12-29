#include "defs.h"

#include "OSWindow.h"



unsigned int Win32Window::Update(float dt)
{
 MSG  msg;
 unsigned int uMessagesLeft = PeekMessageW(&msg, hWindow, 0, 0, PM_REMOVE);

 if (msg.message == WM_QUIT)
 {
 }

 TranslateMessage(&msg);
 DispatchMessageW(&msg);
 return uMessagesLeft;
}


Result::Code Win32Window::GetClientArea(Rect<float> *pOutArea)
{
 RECT rcClient;

 GetClientRect(hWindow, &rcClient);
 pOutArea->x = Range<float>(rcClient.left, rcClient.right);
 pOutArea->y = Range<float>(rcClient.top, rcClient.bottom);

 return Result::Success;
}

Result::Code Win32Window::GetWindowArea(Rect<float> *pOutArea)
{
 RECT rcWindow;

 GetWindowRect(hWindow, &rcWindow);
 pOutArea->x = Range<float>(rcWindow.left, rcWindow.right);
 pOutArea->y = Range<float>(rcWindow.top, rcWindow.bottom);

 return Result::Success;
}

HWND Win32Window::GetAPIHandle()
{
 return hWindow;
}

Result::Code Win32Window::OnClose()
{
 return Result::Generic;
}

Result::Code Win32Window::SetClientArea(const Rect<float> *pArea)
{
 RECT rcWindow, rcClient;
 GetWindowRect(hWindow, &rcWindow);
 GetClientRect(hWindow, &rcClient);

 unsigned int uWindowWidth = rcWindow.right - rcWindow.left,
              uClientWidth = rcClient.right - rcClient.left;
 unsigned int uWindowHeight = rcWindow.bottom - rcWindow.top,
              uClientHeight = rcClient.bottom - rcClient.top;

 SetWindowPos(hWindow, HWND_TOP, pArea->x.min, pArea->y.min,
              pArea->x.Length() + (uWindowWidth - uClientWidth),
              pArea->y.Length() + (uWindowHeight - uClientHeight), SWP_NOACTIVATE | SWP_NOZORDER);

 return Result::Success;
}

Result::Code Win32Window::SetWindowArea(const Rect<float> *pArea)
{
 SetWindowPos(hWindow, HWND_TOP, pArea->x.min, pArea->y.min, pArea->x.Length(), pArea->y.Length(), 0);

 return Result::Success;
}


Result::Code Win32Window::Show()
{
 ShowWindow(hWindow, SW_SHOWNORMAL);

 return Result::Success;
}

long *__stdcall wDefaultWinProc(HWND, unsigned int, unsigned int, long *);
Result::Code Win32Window::Initialize(const wchar_t *pWindowClassName, const wchar_t *pWindowCaptionName, unsigned int uCreationParams)
{
 lstrcpyW(pClassName, pWindowClassName);
 lstrcpyW(pWindowName, pWindowCaptionName);
 uCreationFlags = uCreationParams;

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

 wcxw.cbClsExtra = 0;
 wcxw.cbSize = sizeof(WNDCLASSEXW);
 wcxw.cbWndExtra = 0;
 wcxw.hbrBackground = 0;
 wcxw.hCursor = LoadCursorW(0, (const wchar_t *)(IDC_ARROW));
 wcxw.hIcon = wcxw.hIconSm = LoadIconW(0, (const wchar_t *)(IDI_APPLICATION));
 wcxw.hInstance = GetModuleHandleW(0);
 wcxw.lpfnWndProc = (WNDPROC)(wDefaultWinProc);
 wcxw.lpszClassName = pClassName;
 wcxw.lpszMenuName = 0;
 wcxw.style = CS_OWNDC;
 RegisterClassExW(&wcxw);

 if (uCreationParams & WindowCreationParams::Framed)
   hWindow = CreateWindowExW(0, pClassName, pWindowName, WS_OVERLAPPEDWINDOW, 0, 0, 1, 1, 0, 0, wcxw.hInstance, this);
 else hWindow = CreateWindowExW(0, pClassName, pWindowName, WS_POPUP, 0, 0, 1, 1, 0, 0, wcxw.hInstance, this);

 return Result::Success;
}

Result::Code Win32Window::SystemMessageHandler(unsigned int msg, unsigned int wparam, long *lparam)
{
 return Result::NotImplemented;
}





/*
long *__stdcall wDefaultWinProc(HWND hwnd, unsigned int msg, unsigned int wparam, long *lparam)
{
 if (msg == WM_NCCREATE || msg == WM_NCCALCSIZE)
   return (long *)DefWindowProcW(hwnd, msg, wparam, (LPARAM)(lparam));
 if (msg == WM_CREATE)
 {
  CREATESTRUCTW *pCS = (CREATESTRUCTW *)(lparam);
  SetWindowLongPtrW(hwnd, GWLP_USERDATA, (LONG_PTR)(pCS->lpCreateParams));
  return (long *)DefWindowProcW(hwnd, msg, wparam, (LPARAM)(lparam));
 }

 Window *pTarget = (Window *)(GetWindowLongPtrW(hwnd, GWLP_USERDATA));
 if (!pTarget->SystemMessageHandler(msg, wparam, lparam))
   return 0;
 else return (long *)DefWindowProcW(hwnd, msg, wparam, (LPARAM)(lparam));
}*/

