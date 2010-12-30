#include "defs.h"

#include "OSWindow.h"



Result::Code Win32Window::HandleEvents()
{
 MSG msg;
 while (PeekMessageW(&msg, hWindow, 0, 0, PM_REMOVE))
 {
  if (msg.message == WM_QUIT)
    return Result::Generic;

  TranslateMessage(&msg);
  DispatchMessageW(&msg);
 }
 return Result::Success;
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
 SetWindowPos(hWindow, HWND_TOP, pArea->x.min, pArea->y.min, pArea->x.Length(), pArea->y.Length(), SWP_NOACTIVATE | SWP_NOZORDER);

 return Result::Success;
}


Result::Code Win32Window::Show(bool bShow)
{
 if (bShow && !bVisible)
 {
  ShowWindow(hWindow, SW_SHOWNORMAL);
  UpdateWindow(hWindow);
  bVisible = true;
 }
 else if (!bShow && bVisible)
 {
  ShowWindow(hWindow, SW_HIDE);
  bVisible = false;
 }
 return Result::Success;
}

long *__stdcall wMM7DefaultWinProc(HWND, unsigned int, unsigned int, long *);
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
 wcxw.hCursor = LoadCursorW(nullptr, (const wchar_t *)(IDC_ARROW));
 wcxw.hIcon = wcxw.hIconSm = LoadIconW(nullptr, (const wchar_t *)(IDI_APPLICATION));
 wcxw.hInstance = GetModuleHandleW(nullptr);
 wcxw.lpfnWndProc = (WNDPROC)(wMM7DefaultWinProc);
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


Result::Code Win32Window::OnClose()
{
 return Result::NotImplemented;
}


Result::Code Win32Window::Close()
{
 return Result::NotImplemented;
}


