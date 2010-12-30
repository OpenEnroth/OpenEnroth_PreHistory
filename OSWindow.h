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


class OSWindow
{
 public:
    inline  OSWindow(): bVisible(false) {}
   virtual ~OSWindow() {}

   virtual Result::Code Initialize(const wchar_t *pClassName, const wchar_t *pWindowName, unsigned int uCreationParams) = 0;
   virtual Result::Code SetWindowArea(const Rect<float> *) = 0;
   virtual Result::Code SetClientArea(const Rect<float> *) = 0;
   virtual Result::Code Show(bool) = 0;
   virtual Result::Code Close() = 0;
   virtual Result::Code HandleEvents() = 0;

   virtual Result::Code GetClientArea(Rect<float> *) = 0;
   virtual Result::Code GetWindowArea(Rect<float> *) = 0;
   virtual HWND         GetAPIHandle() = 0;

   virtual bool         Visible() {return bVisible;}

   virtual Result::Code OnClose() = 0;

 protected:
   bool bVisible;
};



class Win32Window: public OSWindow
{
 public:
            Win32Window();
   virtual ~Win32Window();

   virtual Result::Code Initialize(const wchar_t *pClassName, const wchar_t *pWindowName, unsigned int uCreationParams);
   virtual Result::Code SetWindowArea(const Rect<float> *);
   virtual Result::Code SetClientArea(const Rect<float> *);
   virtual Result::Code Show(bool);
   virtual Result::Code Close();
   virtual Result::Code HandleEvents();

   virtual Result::Code  GetClientArea(Rect<float> *);
   virtual Result::Code  GetWindowArea(Rect<float> *);
   virtual HWND          GetAPIHandle();

   virtual Result::Code OnClose();

 protected:
   friend long *__stdcall wMM7DefaultWinProc(HWND hWnd, unsigned int Msg, unsigned int wParam, long *lParam);
   friend long *__stdcall wWin32DefaultWinProc(HWND, unsigned int, unsigned int, long *);
   virtual Result::Code   SystemMessageHandler(unsigned int msg, unsigned int wparam, long *lparam);

   WNDCLASSEXW  wcxw;
   wchar_t      pClassName[256],
                pWindowName[250];
   unsigned int uCreationFlags;
   HWND         hWindow;
};




class Win32InsertCDWindow: public Win32Window
{
 public:
            Win32InsertCDWindow();
   virtual ~Win32InsertCDWindow();

   virtual Result::Code Initialize(const wchar_t *pClassName, const wchar_t *pWindowName, unsigned int uCreationParams);
   virtual Result::Code Close();

   virtual Result::Code OnClose();

 protected:
   friend long *__stdcall wWin32DefaultWinProc(HWND, unsigned int, unsigned int, long *);
   virtual Result::Code   SystemMessageHandler(unsigned int msg, unsigned int wparam, long *lparam);

   HDC     hWindowDC,
           hWindowBackgroundDC;
   HBITMAP hWindowBackgroundBackbuffer,
           hWindowBackgroundImage;
   HICON   hWindowIcon;
};

#endif