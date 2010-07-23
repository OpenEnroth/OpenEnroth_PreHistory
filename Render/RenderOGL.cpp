#include "RenderOGL.h"
#include "wgl\\wglext.h"
#include "..\\Window.h"



unsigned int RenderOGL::Reset(Window *pOutputWindow, bool bFullscreen, struct Viewport *pOutputArea)
{
 pTargetWindow = pOutputWindow;

 hTargetWindowDC = GetDC((HWND)(pTargetWindow->GetAPIHandle()));

 PIXELFORMATDESCRIPTOR pfd =
 {
  sizeof(PIXELFORMATDESCRIPTOR),  //  size of this pfd  
  1,                     // version number  
  PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
  PFD_TYPE_RGBA,         // RGBA type  
  32,                    // 24-bit color depth  
  0, 0, 0, 0, 0, 0,      // color bits ignored  
  0,                     // no alpha buffer  
  0,                     // shift bit ignored  
  0,                     // no accumulation buffer  
  0, 0, 0, 0,            // accum bits ignored  
  32,                    // 32-bit z-buffer      
  0,                     // no stencil buffer  
  0,                     // no auxiliary buffer  
  PFD_MAIN_PLANE,        // main layer  
  0,                     // reserved  
  0, 0, 0                // layer masks ignored  
 };

 int iPixelFormat = ChoosePixelFormat(hTargetWindowDC, &pfd);
 if (!iPixelFormat)
   return -1;

 if (!SetPixelFormat(hTargetWindowDC, iPixelFormat, &pfd))
   return -1;


 HGLRC hLegacyRC = wglCreateContext(hTargetWindowDC);
 wglMakeCurrent(hTargetWindowDC, hLegacyRC);


 const char *(__stdcall *wglGetExtensionsStringARB)(HDC);
 wglGetExtensionsStringARB = (const char *(__stdcall *)(HDC))wglGetProcAddress("wglGetExtensionsStringARB");
 
 const char *pGLExtensions = (const char *)glGetString(GL_EXTENSIONS),
            *pWGLExtension = wglGetExtensionsStringARB(hTargetWindowDC);
 if (!strstr(pWGLExtension, "WGL_ARB_create_context"))
 {
  MessageBoxW(0, L"OpenGL 3.0 not supported", L"Error", 0);
  return -1;
 }

 HGLRC (__stdcall *wglCreateContextAttribsARB)(HDC, HGLRC, const int *);
 wglCreateContextAttribsARB = (HGLRC (__stdcall *)(HDC, HGLRC, const int *))(wglGetProcAddress("wglCreateContextAttribsARB"));

 int pContextAttributes[] =
 {
  WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
  WGL_CONTEXT_MINOR_VERSION_ARB, 2,
  WGL_CONTEXT_FLAGS_ARB,         0,
  0, 0
 };
 hTargetWindowRC = wglCreateContextAttribsARB(hTargetWindowDC, 0, pContextAttributes);

 if (!hTargetWindowRC)
 {
  MessageBoxW(0, L"OpenGL 3.2 not supported", L"Error", 0);
  return -1;
 }

 wglMakeCurrent(0, 0);
 wglDeleteContext(hLegacyRC);
 wglMakeCurrent(hTargetWindowDC, hTargetWindowRC);

 glClearColor(0, 0, 0, 1);
 SwapBuffers(hTargetWindowDC);

 return 0;
}

unsigned int RenderOGL::Initialize()
{
 return 0;
}



Render *CreateOpenGLRender()
{
 return new RenderOGL;
}


#pragma comment(lib, "OpenGL32.lib")










void *NewRender_CreateD3D10()
{
 return CreateDirect3D10Render();
}

void *NewRender_CreateOGL()
{
 return CreateOpenGLRender();
}
unsigned int NewRender_Initialize(void *_this)
{
 Render *pRender = (Render *)_this;
 return pRender->Initialize();
}

unsigned int NewRender_Reset(void *_this, Window *pWindow, bool bFullscreen, struct Viewport *pViewport)
{
 Render *pRender = (Render *)_this;
 return pRender->Reset(pWindow, bFullscreen, pViewport);
}