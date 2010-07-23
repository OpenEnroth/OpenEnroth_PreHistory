#pragma once
#include <d3d10.h>
#include "Render.h"

class RenderD3D10: public Render
{
 public:
            RenderD3D10();
   virtual ~RenderD3D10();

   virtual unsigned int Initialize();
   virtual unsigned int Reset(Window *pTargetWindow, bool bFullscreen, struct Viewport *pOutputArea);

 protected:
   HMODULE                hDXGIDll,
                          hD3D10Dll;
   IDXGIFactory          *pDXGIFactory;
   ID3D10Device          *pDevice;
   IDXGISwapChain        *pSwapChain;
   D3D10_VIEWPORT         defaultViewport;
   Window                *pTargetWindow;

   ID3D10View            *pDefaultRenderTargetView,
                         *pDefaultDepthStencilView;
   ID3D10BlendState      *pBlendState_Default;
   ID3D10RasterizerState *pRasterizerState_Default;
};