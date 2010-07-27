#include "RenderOperatorsOGL.h"
#include "RenderOGL.h"


unsigned int RenderOperatorOGL_DrawTerrain::Initialize(Render *pRender, Texture *pHeightmap, unsigned int uResolutionX, unsigned int uResolutionZ, Camera *pObserver)
{
 return -1;
}

unsigned int RenderOperatorOGL_DrawTerrain::Execute()
{
 return -1;
}

unsigned int RenderOperatorOGL_DrawEnvironment::Initialize(Render *pRender, Texture *pTexture, Camera *pObserver)
{
 return -1;
}

unsigned int RenderOperatorOGL_DrawEnvironment::Execute()
{
 return -1;
}



unsigned int RenderOperatorOGL_Clear::Execute()
{
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
   return pChildren->Execute();
 else return 0;
};


unsigned int RenderOperatorOGL_Clear::Initialize(Render *pHostRender, Texture *pTargetTexture, float pColor[4])
{
 pRender = (RenderOGL *)pHostRender;
 pTexture = (TextureOGL *)pTargetTexture;
 memcpy(pClearColor, pColor, 16);
 return 0;
}






unsigned int RenderOperatorOGL_Present::Execute()
{
 SwapBuffers(pRender->hTargetWindowDC);

 if (pChildren)
   return pChildren->Execute();
 else return 0;
}

unsigned int RenderOperatorOGL_Present::Initialize(Render *pHostRender)
{
 pRender = (RenderOGL *)pHostRender;
 return 0;
}




RenderOperator_Clear           *RenderOGL::CreateClearOperator()           {return new RenderOperatorOGL_Clear;}
RenderOperator_Present         *RenderOGL::CreatePresentOperator()         {return new RenderOperatorOGL_Present;}
RenderOperator_DrawEnvironment *RenderOGL::CreateDrawEnvironmentOperator() {return new RenderOperatorOGL_DrawEnvironment;}
RenderOperator_DrawTerrain     *RenderOGL::CreateDrawTerrainOperator()     {return new RenderOperatorOGL_DrawTerrain;}