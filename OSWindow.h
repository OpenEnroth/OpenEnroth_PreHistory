#ifndef MMWINDOW_H
#define MMWINDOW_H

#include <windows.h>
#include "CoreDefinitions.h"


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
   virtual Result::Code OnClose() = 0;
};



class OSWindow: public EventHandler
{
 public:
   virtual Result::Code Initialize(const wchar_t *pClassName, const wchar_t *pWindowName, unsigned int uCreationParams) = 0;
   virtual Result::Code SetWindowArea(const Rect<float> *) = 0;
   virtual Result::Code SetClientArea(const Rect<float> *) = 0;
   virtual Result::Code Show() = 0;
   virtual unsigned int Update(float dt) = 0;

   virtual Result::Code  GetClientArea(Rect<float> *) = 0;
   virtual Result::Code  GetWindowArea(Rect<float> *) = 0;
   virtual HWND          GetAPIHandle() = 0;
};



class Win32Window: public OSWindow
{
 public:
   virtual Result::Code Initialize(const wchar_t *pClassName, const wchar_t *pWindowName, unsigned int uCreationParams);
   virtual Result::Code SetWindowArea(const Rect<float> *);
   virtual Result::Code SetClientArea(const Rect<float> *);
   virtual Result::Code Show();
   virtual unsigned int Update(float dt);

   virtual Result::Code  GetClientArea(Rect<float> *);
   virtual Result::Code  GetWindowArea(Rect<float> *);
   virtual HWND          GetAPIHandle();

   virtual Result::Code OnClose();

 protected:
   friend long *__stdcall wDefaultWinProc(HWND hWnd, unsigned int Msg, unsigned int wParam, long *lParam);
   Result::Code           SystemMessageHandler(unsigned int msg, unsigned int wparam, long *lparam);

   WNDCLASSEXW  wcxw;
   wchar_t      pClassName[256],
                pWindowName[250];
   unsigned int uCreationFlags;
   HWND         hWindow;
};

#endif