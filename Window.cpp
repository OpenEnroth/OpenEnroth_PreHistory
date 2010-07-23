#include "Window.h"




unsigned int Window::Update(float dt)
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


unsigned int Window::GetClientArea(struct Viewport *pOutArea)
{
 RECT rcClient;

 GetClientRect(hWindow, &rcClient);
 pOutArea->x = rcClient.left;
 pOutArea->y = rcClient.top;
 pOutArea->z = rcClient.right;
 pOutArea->w = rcClient.bottom;
 pOutArea->znear = 0;
 pOutArea->zfar = 0;
 return 0;
}

unsigned int Window::GetWindowArea(struct Viewport *pOutArea)
{
 RECT rcWindow;

 GetWindowRect(hWindow, &rcWindow);
 pOutArea->x = rcWindow.left;
 pOutArea->y = rcWindow.top;
 pOutArea->z = rcWindow.right;
 pOutArea->w = rcWindow.bottom;
 pOutArea->znear = 0;
 pOutArea->zfar = 0;
 return 0;
}

void *Window::GetAPIHandle()
{
 return hWindow;
}

unsigned int Window::OnClose()
{
 return -1;
}

unsigned int Window::SetClientArea(struct Viewport *pArea)
{
 RECT rcWindow, rcClient;
 GetWindowRect(hWindow, &rcWindow);
 GetClientRect(hWindow, &rcClient);

 unsigned int uWindowWidth = rcWindow.right - rcWindow.left,
              uClientWidth = rcClient.right - rcClient.left;
 unsigned int uWindowHeight = rcWindow.bottom - rcWindow.top,
              uClientHeight = rcClient.bottom - rcClient.top;

 SetWindowPos(hWindow, HWND_TOP, pArea->x, pArea->y,
              (pArea->z - pArea->x) + (uWindowWidth - uClientWidth),
              (pArea->w - pArea->y) + (uWindowHeight - uClientHeight), 0);
 return 0;
}

unsigned int Window::SetWindowArea(struct Viewport *pArea)
{
 SetWindowPos(hWindow, HWND_TOP, pArea->x, pArea->y, pArea->z - pArea->x, pArea->w - pArea->y, 0);
 return 0;
}


unsigned int Window::Show()
{
 ShowWindow(hWindow, SW_SHOWNORMAL);
 return 0;
}

long *__stdcall wDefaultWinProc(HWND, unsigned int, unsigned int, long *);
unsigned int Window::Initialize(const wchar_t *pWindowClassName, const wchar_t *pWindowName, bool bWindowFrame)
{
 lstrcpyW(pClassName, pWindowClassName);

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

 if (bWindowFrame)
   hWindow = CreateWindowExW(0, pClassName, pWindowName, WS_OVERLAPPEDWINDOW, 0, 0, 640, 480, 0, 0, wcxw.hInstance, this);
 else hWindow = CreateWindowExW(0, pClassName, pWindowName, WS_OVERLAPPEDWINDOW, 0, 0, 640, 480, 0, 0, wcxw.hInstance, this);

 return 0;
}

unsigned int Window::SystemMessageHandler(unsigned int msg, unsigned int wparam, long *lparam)
{
 return -1;
}



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
}










void *Window_Initialize(const wchar_t *pClassName, const wchar_t *pWindowName, bool bFrame)
{
 Window *pWindow = new Window;
 pWindow->Initialize(pClassName, pWindowName, bFrame);

 return pWindow;
}


unsigned int Window_SetClientArea(void *_this, struct Viewport *pArea)
{
 Window *pWindow = (Window *)_this;
 return pWindow->SetClientArea(pArea);
}

unsigned int Window_Show(void *_this)
{
 Window *pWindow = (Window *)_this;
 return pWindow->Show();
}

unsigned int Window_Update(void *_this, float dt)
{
 Window *pWindow = (Window *)_this;
 return pWindow->Update(dt);
}