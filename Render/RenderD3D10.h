#pragma once
#include <d3d10.h>
#include "Render.h"

class TextureD3D10;
class RenderD3D10: public Render
{
 friend class RenderOperatorD3D10_Clear;
 friend class RenderOperatorD3D10_Present;
 friend class RenderOperatorD3D10_DrawEnvironment;
 public:
            RenderD3D10();
   virtual ~RenderD3D10();

   virtual unsigned int Initialize();
   virtual unsigned int Reset(Window *pTargetWindow, bool bFullscreen, struct Viewport *pOutputArea);
   
   virtual unsigned int CreateTexture(unsigned int uWidth, unsigned int uDepth, enum TextureFormat eFormat, Texture **pOut);
   virtual unsigned int CreateTexture(const wchar_t *pTextureName, Texture **pOut);
   virtual unsigned int CreateTextureCube(const wchar_t *pFilename, Texture **pOut);
   
   virtual unsigned int GetPrimaryColorTarget(Texture **pOut);
   virtual unsigned int GetPrimaryDepthTarget(Texture **pOut);

   virtual RenderOperator_Clear           *CreateClearOperator();
   virtual RenderOperator_Present         *CreatePresentOperator();
   virtual RenderOperator_DrawEnvironment *CreateDrawEnvironmentOperator();

 protected:
   HMODULE                hDXGIDll,
                          hD3D10Dll;
   IDXGIFactory          *pDXGIFactory;
   ID3D10Device          *pDevice;
   IDXGISwapChain        *pSwapChain;
   D3D10_VIEWPORT         defaultViewport;
   Window                *pTargetWindow;
   
   TextureD3D10          *pPrimaryColorTarget;
   TextureD3D10          *pPrimaryDepthTarget;
   ID3D10BlendState      *pBlendState_Default;
   ID3D10RasterizerState *pRasterizerState_Default;
};