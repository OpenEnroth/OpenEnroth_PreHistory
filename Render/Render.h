#pragma once
#include "Texture.h"
#include "RenderOperators.h"


class Window;
class Render
{
 public:
   virtual unsigned int Initialize() = 0;
   virtual unsigned int Reset(Window *pTargetWindow, bool bFullscreen, struct Viewport *pOutputArea) = 0;

   virtual unsigned int CreateTexture(unsigned int uWidth, unsigned int uDepth, enum TextureFormat eFormat, Texture **pOut) = 0;
   virtual unsigned int CreateTexture(const wchar_t *pTextureName, Texture **pOut) = 0;

   virtual unsigned int GetPrimaryColorTarget(Texture **pOut) = 0;
   virtual unsigned int GetPrimaryDepthTarget(Texture **pOut) = 0;

   virtual RenderOperator_Clear   *CreateClearOperator() = 0;
   virtual RenderOperator_Present *CreatePresentOperator() = 0;
};





Render *CreateDirect3D10Render();
Render *CreateOpenGL32Render();
