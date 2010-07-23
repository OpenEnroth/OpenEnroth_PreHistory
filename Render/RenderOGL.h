#pragma once
#include <windows.h>
#include <gl\\gl.h>
#include "Render.h"
#include "..\\Window.h"

class RenderOGL: public Render
{
 public:
   virtual unsigned int Initialize();
   virtual unsigned int Reset(Window *pTargetWindow, bool bFullscreen, struct Viewport *pOutputArea);

 protected:
   Window *pTargetWindow;
   HDC     hTargetWindowDC;
   HGLRC   hTargetWindowRC;
};