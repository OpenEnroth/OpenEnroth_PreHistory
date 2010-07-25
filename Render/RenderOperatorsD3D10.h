#pragma once
#include "RenderOperators.h"
#include "TextureD3D10.h"


class RenderD3D10;
class RenderOperatorD3D10_Clear: public RenderOperator_Clear
{
 public:
   virtual unsigned int Initialize(Render *pRender, Texture *pTexture, float pClearColor[4]);
   virtual unsigned int Execute();

 protected:
   RenderD3D10  *pRender;
   TextureD3D10 *pTexture;
   float         pClearColor[4];
};


class RenderOperatorD3D10_Present: public RenderOperator_Present
{
 public:
   virtual unsigned int Initialize(Render *pRender);
   virtual unsigned int Execute();

 protected:
   RenderD3D10 *pRender;
};





class RenderOperatorD3D10_DrawEnvironment: public RenderOperator_DrawEnvironment
{
 public:
   virtual unsigned int Initialize(Render *pRender, Texture *pTexture, Camera *pObserver);
   virtual unsigned int Execute();

 protected:
   Camera *pCamera;

   RenderD3D10  *pRender;
   TextureD3D10 *pEnvTexture;
   
   ID3D10InputLayout  *pInputLayout;
   ID3D10Buffer       *pVertexBuffer;

   ID3D10VertexShader *pVertexShader;
   ID3D10Buffer       *pVertexShaderConstants;

   ID3D10PixelShader  *pPixelShader;
   ID3D10SamplerState *pPixelShaderSampler0;

   ID3D10DepthStencilState *pScreenQuadClearingZ;
};