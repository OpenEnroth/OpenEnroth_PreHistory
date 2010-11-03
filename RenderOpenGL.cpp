#include "Render.h"
#include "Window.h"

#include <gl/GL.h>

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

unsigned int RenderOpenGL::Initialize(OSWindow *pOutputWindow)
{
  int v2; // esi@1
  int v7; // ecx@5
  signed int v8; // eax@7
  int v11; // eax@14
  int v12; // eax@18
  int v13; // eax@22
  int v14; // eax@24
  int v17; // eax@26
  int v20; // eax@35
  int v21; // eax@35
  int v23; // eax@38
  int v25; // ecx@38


  int v36; // [sp+280h] [bp-8Ch]@35
  int v37; // [sp+284h] [bp-88h]@35
  int v38; // [sp+288h] [bp-84h]@35
  int v39; // [sp+28Ch] [bp-80h]@35
  int v40; // [sp+2C0h] [bp-4Ch]@35
  int v41; // [sp+2C4h] [bp-48h]@35
  int v42; // [sp+2E8h] [bp-24h]@35
  int v44; // [sp+308h] [bp-4h]@2
 unsigned int uDeviceCaps;
 HRESULT      hr;






 pTargetWindow = pOutputWindow;

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
 
 hTargetWindowDC = GetDC(pTargetWindow->GetAPIHandle());

 int iPixelFormat = ChoosePixelFormat(hTargetWindowDC, &pfd);
 if (!iPixelFormat)
   return -1;

 if (!SetPixelFormat(hTargetWindowDC, iPixelFormat, &pfd))
   return -1;


 HGLRC hLegacyRC = wglCreateContext(hTargetWindowDC);
 wglMakeCurrent(hTargetWindowDC, hLegacyRC);

 glViewport(0, 0, 640, 480);

 glClearColor(0, 0, 0, 1);
 glClear(GL_COLOR_BUFFER_BIT);
 SwapBuffers(hTargetWindowDC);










  pParty_global->dword_007778 |= 2;
  v2 = (int)this;
  flt_6BE3A0 = 0.55000001;


 Viewport_fn2(pOldViewport, 36044);

 this->dword_040108 = 0;
 this->dword_040110 = 0;
 sub_49FE05(this);

 this->pdd4 = 0;
 this->pdds4_FrontBuffer = 0;
 this->pdds4_BackBuffer = 0;
 this->dword_040098 = 0;

 Render_Initialize_ZBuffer(this);


  this->pRenderD3D3 = 0;
  v44 = 0;




    this->pdd4 = 0;
    this->pdds4_FrontBuffer = 0;
    this->pdds4_BackBuffer = 0;
    this->dword_040098 = 0;



  this->dword_10365C = 0 | 1;
  this->bRequiredTextureStagesAvailable = true;
  

  this->uMinDeviceTextureDim = 1;


  this->uMaxDeviceTextureDim = 1024;

  
  //Render_sub_49FFD7(this);
  glEnable(GL_DEPTH_TEST);//this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_ZENABLE, 1);
  //this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_ZWRITEENABLE, 1);
  glDepthFunc(GL_LESS);//this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_ZFUNC, D3DCMP_LESS);
  //this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_SPECULARENABLE, 0);
  //this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_COLORKEYENABLE, 0);
  glDisable(GL_CULL_FACE);//this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_CULLMODE, D3DCULL_NONE);
  glDisable(GL_LIGHTING);
  

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_MAGFILTER, 2);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_MINFILTER, 2);
  //this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_MIPFILTER, 3);
  //this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, 2);
  //this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, 0);
  ///this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, 2);
  //this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, 2);
  //this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, 0);
  //this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_COLOROP, 4);



 this->dword_040108 = true;
 this->dword_040108 = 0;

 this->pTargetSurface = 0;
 this->ptr_0400E8 = (int)malloc(640 * 480 * 4 + 32);
 if (this->ptr_0400E8)
 {
        this->pTargetSurface = (unsigned int *)this->ptr_0400E8;

      this->uTargetSurfacePitch = 640;
      this->pfn_1036C0 = (int (__cdecl *)())sub_4A597D;

      this->dword_040110 = 1;
      this->dword_040058 = 1;
      this->hWnd = pTargetWindow->GetAPIHandle();
      return 0;

 }
 return 0;
}




//----- (MM7.exe::004A51CB) --------------------------------------------------------
unsigned int RenderOpenGL::BeginScene()
{
 int v1;

 v1 = this->bSceneBegun++;
 if (!v1)
 {
        this->pTargetSurface = (unsigned int *)this->ptr_0400E8;

      this->uTargetSurfacePitch = 640;
 }
 return v1;
}


unsigned int RenderOpenGL::Present()
{
 unsigned int uScreenQuadID;
 
 glEnable(GL_TEXTURE_2D);
 glGenTextures(1, &uScreenQuadID);
 glBindTexture(GL_TEXTURE_2D, uScreenQuadID);

 for (unsigned int i = 0; i < 640 * 480; ++i)
   this->pTargetSurface[i] = ((this->pTargetSurface[i] & 0x00FF0000) >> 16) |
                             ((this->pTargetSurface[i] & 0x000000FF) << 16) |
                             (this->pTargetSurface[i] & 0xFF00FF00);

 glTexImage2D(GL_TEXTURE_2D, 0, 4, 640, 480, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->pTargetSurface);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


 glDisable(GL_DEPTH_TEST);

 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(0, 640, 480, 0, -1, 1);
 
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();

 glClearDepth(1.0);
 glBegin(GL_TRIANGLES);
   glColor3f(1, 1, 1);

   glTexCoord2f(0, 0);
   glVertex2f(0, 0);
   
   glTexCoord2f(0, 1);
   glVertex2f(0, 480);
   
   glTexCoord2f(1, 0);
   glVertex2f(640, 0);



   glTexCoord2f(0, 1);
   glVertex2f(0, 480);

   glTexCoord2f(1, 1);
   glVertex2f(640, 480);

   glTexCoord2f(1, 0);
   glVertex2f(640, 0);
 glEnd();

 glDisable(GL_TEXTURE_2D);
 glDeleteTextures(1, &uScreenQuadID);

 SwapBuffers(hTargetWindowDC);
 return 0;
}


unsigned int RenderOpenGL::EndScene()
{
 if (!this->bSceneBegun)
   return -1;

 this->bSceneBegun--;
 //this->pTargetSurface = 0;
 //this->uTargetSurfacePitch = 0;
 this->dword_000018 = 0;
 return 0;
}


unsigned int RenderOpenGL::IsGammaControlSupported()
{
 return false;
}


RenderOpenGL::RenderOpenGL():
  BaseRender()
{
}