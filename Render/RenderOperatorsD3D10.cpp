#include "RenderOperatorsD3D10.h"
#include "RenderD3D10.h"


unsigned int RenderOperatorD3D10_Clear::Execute(Render *pRender)
{
 RenderD3D10 *pRenderD3D10 = (RenderD3D10 *)pRender;

 if (pTexture->eFormat == TF_D16_float || pTexture->eFormat == TF_D32_float)
   pRenderD3D10->pDevice->ClearDepthStencilView((ID3D10DepthStencilView *)(pTexture->pResourceView), D3D10_CLEAR_DEPTH, pClearColor[0], 0);
 else
   pRenderD3D10->pDevice->ClearRenderTargetView((ID3D10RenderTargetView *)(pTexture->pResourceView), pClearColor);

 if (pChildren)
   return pChildren->Execute(pRender);
 else return 0;
};

unsigned int RenderOperatorD3D10_Clear::Initialize(Texture *pTargetTexture, float pColor[4])
{
 pTexture = (TextureD3D10 *)pTargetTexture;
 memcpy(pClearColor, pColor, 16);
 return 0;
}




unsigned int RenderOperatorD3D10_Present::Execute(Render *pRender)
{
 RenderD3D10 *pRenderD3D10 = (RenderD3D10 *)pRender;

 pRenderD3D10->pSwapChain->Present(0, 0);

 if (pChildren)
   return pChildren->Execute(pRender);
 else return 0;
}

unsigned int RenderOperatorD3D10_Present::Initialize()
{
 return 0;
}



RenderOperator_Clear *RenderD3D10::CreateClearOperator()   {return new RenderOperatorD3D10_Clear;}
RenderOperator_Present *RenderD3D10::CreatePresentOperator() {return new RenderOperatorD3D10_Present;}