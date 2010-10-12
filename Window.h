#pragma once
#include <windows.h>

struct Viewport
{
 float x,     y;
 float z,     w;
 float znear, zfar;
};


namespace WindowCreationParams
{
 enum
 {
  Framed = 0x0001,
  Unique = 0x0002
 };
};


class EventHandler
{
 public:
   virtual unsigned int OnClose() = 0;
};


class OSWindow: public EventHandler
{
 public:
   virtual unsigned int Initialize(const wchar_t *pClassName, const wchar_t *pWindowName, unsigned int uCreationParams) = 0;
   virtual unsigned int SetWindowArea(struct Viewport *) = 0;
   virtual unsigned int SetClientArea(struct Viewport *) = 0;
   virtual unsigned int Show() = 0;
   virtual unsigned int Update(float dt) = 0;

   virtual unsigned int GetClientArea(struct Viewport *) = 0;
   virtual unsigned int GetWindowArea(struct Viewport *) = 0;
   virtual HWND         GetAPIHandle() = 0;

   virtual unsigned int OnClose() = 0;
};



class Win32Window: public OSWindow
{
 public:
   virtual unsigned int Initialize(const wchar_t *pClassName, const wchar_t *pWindowName, unsigned int uCreationParams);
   virtual unsigned int SetWindowArea(struct Viewport *);
   virtual unsigned int SetClientArea(struct Viewport *);
   virtual unsigned int Show();
   virtual unsigned int Update(float dt);

   virtual unsigned int GetClientArea(struct Viewport *);
   virtual unsigned int GetWindowArea(struct Viewport *);
   virtual HWND         GetAPIHandle();

   virtual unsigned int OnClose();

 protected:
   friend long *__stdcall wDefaultWinProc(HWND hWnd, unsigned int Msg, unsigned int wParam, long *lParam);
   unsigned int           SystemMessageHandler(unsigned int msg, unsigned int wparam, long *lparam);

   WNDCLASSEXW  wcxw;
   wchar_t      pClassName[256],
                pWindowName[250];
   unsigned int uCreationFlags;
   HWND         hWindow;
};