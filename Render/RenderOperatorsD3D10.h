#pragma once
#include "RenderOperators.h"
#include "TextureD3D10.h"


class RenderD3D10;
class RenderOperatorD3D10_Clear: public RenderOperator_Clear
{
 public:
   virtual unsigned int Initialize(Texture *pTexture, float pClearColor[4]);
   virtual unsigned int Execute(Render *);

 protected:
   TextureD3D10 *pTexture;
   float         pClearColor[4];
};


class RenderOperatorD3D10_Present: public RenderOperator_Present
{
 public:
   virtual unsigned int Initialize();
   virtual unsigned int Execute(Render *);
};