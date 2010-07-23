#pragma once
#include <windows.h>
#include <gl\\gl.h>
#include "Render.h"
#include "..\\Window.h"

class TextureOGL;
class RenderOGL: public Render
{
 friend struct RenderOperatorOGL_Clear;
 friend struct RenderOperatorOGL_Present;
 public:
   virtual unsigned int Initialize();
   virtual unsigned int Reset(Window *pTargetWindow, bool bFullscreen, struct Viewport *pOutputArea);
   
   virtual unsigned int CreateTexture(unsigned int uWidth, unsigned int uDepth, enum TextureFormat eFormat, Texture **pOut);
   virtual unsigned int CreateTexture(const wchar_t *pTextureName, Texture **pOut);

   virtual unsigned int GetPrimaryColorTarget(Texture **pOut);
   virtual unsigned int GetPrimaryDepthTarget(Texture **pOut);

   virtual RenderOperator_Clear   *CreateClearOperator();
   virtual RenderOperator_Present *CreatePresentOperator();

 protected:
   Window *pTargetWindow;
   HDC     hTargetWindowDC;
   HGLRC   hTargetWindowRC;

   TextureOGL *pPrimaryColorTarget;
   TextureOGL *pPrimaryDepthTarget;

   struct Viewport defaultViewport;
};