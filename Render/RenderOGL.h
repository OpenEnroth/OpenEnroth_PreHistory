#pragma once
#include <windows.h>
#include <gl\\gl.h>
#include "Render.h"

class DepthStencilStateOGL: public DepthStencilState
{
 public:
   virtual unsigned int Initialize(Render *pRender, bool bZTest, bool bZWrite, DepthOperator::Type eOperator);
};

class OSWindow;

class TextureOGL;
class RenderOGL: public Render
{
 friend class RenderOperatorOGL_Clear;
 friend class RenderOperatorOGL_Present;
 friend class RenderOperatorOGL_DrawEnvironment;
 public:
   virtual unsigned int Initialize();
   virtual unsigned int Reset(OSWindow *pTargetWindow, bool bFullscreen, struct Rect<float> *pOutputArea);
   
   virtual unsigned int CreateDepthStencilState(DepthStencilState **pOut);

   virtual unsigned int CreateTexture(unsigned int uWidth, unsigned int uDepth, enum TextureFormat eFormat, Texture **pOut);
   virtual unsigned int CreateTexture(const wchar_t *pTextureName, Texture **pOut);
   virtual unsigned int CreateTextureCube(const wchar_t *pFilename, Texture **pOut);

   virtual unsigned int GetPrimaryColorTarget(Texture **pOut);
   virtual unsigned int GetPrimaryDepthTarget(Texture **pOut);

   virtual RenderOperator_Clear           *CreateClearOperator();
   virtual RenderOperator_Present         *CreatePresentOperator();
   virtual RenderOperator_DrawTerrain     *CreateDrawTerrainOperator();
   virtual RenderOperator_DrawEnvironment *CreateDrawEnvironmentOperator();

 protected:
   OSWindow *pTargetWindow;
   HDC       hTargetWindowDC;
   HGLRC     hTargetWindowRC;

   TextureOGL *pPrimaryColorTarget;
   TextureOGL *pPrimaryDepthTarget;

   struct Rect<float> defaultViewport;
};