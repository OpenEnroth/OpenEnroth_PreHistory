#pragma once
#include "Texture.h"
#include "RenderOperators.h"
#include "..\\CoreDefinitions.h"


namespace DepthOperator
{
 enum Type
 {
  Equal = 0,
  NotEqual,
  Greater,
  GreaterEqual,
  Less,
  LessEqual,
  Always,
  Never
 };
};

class DepthStencilState
{
 public:
   virtual unsigned int Initialize(Render *pRender, bool bZTest, bool bZWrite, DepthOperator::Type eOperator) = 0;
};

class OSWindow;
class Render
{
 public:
   virtual unsigned int Initialize() = 0;
   virtual unsigned int Reset(OSWindow *pTargetWindow, bool bFullscreen, struct Rect<float> *pOutputArea) = 0;

   virtual unsigned int CreateDepthStencilState(DepthStencilState **pOut) = 0;

   virtual unsigned int CreateTexture(unsigned int uWidth, unsigned int uDepth, enum TextureFormat eFormat, Texture **pOut) = 0;
   virtual unsigned int CreateTexture(const wchar_t *pTextureName, Texture **pOut) = 0;
   virtual unsigned int CreateTextureCube(const wchar_t *pFilename, Texture **pOut) = 0;

   virtual unsigned int GetPrimaryColorTarget(Texture **pOut) = 0;
   virtual unsigned int GetPrimaryDepthTarget(Texture **pOut) = 0;

   virtual RenderOperator_Clear           *CreateClearOperator() = 0;
   virtual RenderOperator_DrawEnvironment *CreateDrawEnvironmentOperator() = 0;
   virtual RenderOperator_DrawTerrain     *CreateDrawTerrainOperator() = 0;
   virtual RenderOperator_Present         *CreatePresentOperator() = 0;
};





Render *CreateDirect3D10Render();
Render *CreateOpenGL32Render();
