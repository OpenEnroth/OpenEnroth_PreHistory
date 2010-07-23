#pragma once
#include "RenderOperators.h"
#include "TextureOGL.h"

class RenderOGL;
class RenderOperatorOGL_Clear: public RenderOperator_Clear
{
 public:
   virtual unsigned int Initialize(Texture *pTexture, float pClearColor[4]);
   virtual unsigned int Execute(Render *);
   
 protected:
   TextureOGL *pTexture;
   float       pClearColor[4];
};


class RenderOperatorOGL_Present: public RenderOperator_Present
{
 public:
   virtual unsigned int Initialize();
   virtual unsigned int Execute(Render *);
};