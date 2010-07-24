#include "RenderOGL.h"
#include "wgl\\wglext.h"
#include "TextureOGL.h"


unsigned int RenderOGL::GetPrimaryDepthTarget(Texture **pOut)
{
 if (pOut)
 {
  *pOut = pPrimaryDepthTarget;
  return 0;
 }
 return -1;
}

unsigned int RenderOGL::GetPrimaryColorTarget(Texture **pOut)
{
 if (pOut)
 {
  *pOut = pPrimaryColorTarget;
  return 0;
 }
 return -1;
}

unsigned int RenderOGL::CreateTexture(unsigned int uWidth, unsigned int uDepth, enum TextureFormat eFormat, Texture **)
{
 return -1;
}

unsigned int RenderOGL::CreateTexture(const wchar_t *pName, Texture **)
{
 return -1;
}




unsigned int RenderOGL::Reset(Window *pOutputWindow, bool bFullscreen, struct Viewport *pOutputArea)
{
 pTargetWindow = pOutputWindow;
 memcpy(&defaultViewport, pOutputArea, sizeof(struct Viewport));

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
 
 hTargetWindowDC = GetDC((HWND)(pTargetWindow->GetAPIHandle()));

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

 struct Viewport windowClientArea;
 pTargetWindow->GetClientArea(&windowClientArea);
 if (bFullscreen)
 {
  DEVMODE devmod;
  memset(&devmod, 0, sizeof(DEVMODE));

  EnumDisplaySettings(0, ENUM_CURRENT_SETTINGS, &devmod);
  devmod.dmPelsWidth = windowClientArea.z - windowClientArea.x;
  devmod.dmPelsHeight = windowClientArea.w - windowClientArea.y;

  ChangeDisplaySettings(&devmod, CDS_FULLSCREEN);
 }

 pPrimaryColorTarget = new TextureOGL;
 pPrimaryColorTarget->eFormat = TF_R8G8B8A8_int;
 
 pPrimaryDepthTarget = new TextureOGL;
 pPrimaryDepthTarget->eFormat = TF_D32_float;

 glViewport(defaultViewport.x, defaultViewport.y,
            defaultViewport.z - defaultViewport.x, defaultViewport.w - defaultViewport.y);

 glClearColor(0, 0, 0, 1);
 glClear(GL_COLOR_BUFFER_BIT);
 SwapBuffers(hTargetWindowDC);

 return 0;
}

unsigned int RenderOGL::Initialize()
{
 return 0;
}



Render *CreateOpenGL32Render()
{
 return new RenderOGL;
}


#pragma comment(lib, "OpenGL32.lib")