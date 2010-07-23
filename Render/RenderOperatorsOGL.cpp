#include "RenderOperatorsOGL.h"
#include "RenderOGL.h"



unsigned int RenderOperatorOGL_Clear::Execute(Render *pRender)
{
 RenderOGL *pRenderOGL = (RenderOGL *)pRender;

 if (pTexture->eFormat == TF_D32_float)
 {
  glClearDepth(pClearColor[0]);
  glClear(GL_DEPTH_BUFFER_BIT);
 }
 else
 {
  glClearColor(pClearColor[0], pClearColor[1], pClearColor[2], pClearColor[3]);
  glClear(GL_COLOR_BUFFER_BIT);
 }

 if (pChildren)
   return pChildren->Execute(pRender);
 else return 0;
};


unsigned int RenderOperatorOGL_Clear::Initialize(Texture *pTargetTexture, float pColor[4])
{
 pTexture = (TextureOGL *)pTargetTexture;
 memcpy(pClearColor, pColor, 16);
 return 0;
}






unsigned int RenderOperatorOGL_Present::Execute(Render *pRender)
{
 RenderOGL *pRenderOGL = (RenderOGL *)pRender;

 SwapBuffers(pRenderOGL->hTargetWindowDC);

 if (pChildren)
   return pChildren->Execute(pRender);
 else return 0;
}

unsigned int RenderOperatorOGL_Present::Initialize()
{
 return 0;
}




RenderOperator_Clear   *RenderOGL::CreateClearOperator()   {return new RenderOperatorOGL_Clear;}
RenderOperator_Present *RenderOGL::CreatePresentOperator() {return new RenderOperatorOGL_Present;}