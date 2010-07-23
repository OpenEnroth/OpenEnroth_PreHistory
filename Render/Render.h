#pragma once

class Render;
class Window;
Render *CreateDirect3D10Render();
Render *CreateOpenGLRender();

class Render
{
 public:
   virtual unsigned int Initialize() = 0;
   virtual unsigned int Reset(Window *pTargetWindow, bool bFullscreen, struct Viewport *pOutputArea) = 0;
};






extern "C"
{
 void         *NewRender_CreateD3D10();
 void         *NewRender_CreateOGL();
 unsigned int  NewRender_Initialize(void *);
 unsigned int  NewRender_Reset(void *, Window *, bool bFullscreen, struct Viewport *);
};