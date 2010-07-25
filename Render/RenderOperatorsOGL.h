#pragma once
#include "RenderOperators.h"
#include "TextureOGL.h"

class RenderOGL;
class RenderOperatorOGL_Clear: public RenderOperator_Clear
{
 public:
   virtual unsigned int Initialize(Render *, Texture *pTexture, float pClearColor[4]);
   virtual unsigned int Execute();
   
 protected:
   RenderOGL  *pRender;
   TextureOGL *pTexture;
   float       pClearColor[4];
};


class RenderOperatorOGL_Present: public RenderOperator_Present
{
 public:
   virtual unsigned int Initialize(Render *);
   virtual unsigned int Execute();

 protected:
   RenderOGL *pRender;
};



class RenderOperatorOGL_DrawEnvironment: public RenderOperator_DrawEnvironment
{
 public:
   virtual unsigned int Initialize(Render *pRender, Texture *pTexture, Camera *pObserver);
   virtual unsigned int Execute();
};