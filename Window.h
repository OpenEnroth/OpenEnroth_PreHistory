#pragma once
#include <windows.h>

struct Viewport
{
 float x,     y;
 float z,     w;
 float znear, zfar;
};



class EventHandler
{
 public:
   virtual unsigned int OnClose() = 0;
};

class Window: public EventHandler
{
 public:
   virtual unsigned int Initialize(const wchar_t *pClassName, const wchar_t *pWindowName, bool bWindowFrame);
   virtual unsigned int SetWindowArea(struct Viewport *);
   virtual unsigned int SetClientArea(struct Viewport *);
   virtual unsigned int Show();
   virtual unsigned int Update(float dt);

   virtual unsigned int  GetClientArea(struct Viewport *);
   virtual unsigned int  GetWindowArea(struct Viewport *);
   virtual void         *GetAPIHandle();

   virtual unsigned int OnClose();

 protected:
   friend long *__stdcall wDefaultWinProc(HWND hwnd, unsigned int msg, unsigned int wparam, long *lparam);
   unsigned int           SystemMessageHandler(unsigned int msg, unsigned int wparam, long *lparam);

   WNDCLASSEXW wcxw;
   wchar_t     pClassName[256];
   HWND        hWindow;
};