#pragma once


class Render;
class Texture;
class RenderOperator
{
 public:
   RenderOperator(): pChildren(0) {}

   virtual unsigned int Execute(Render *pRender) = 0;

   RenderOperator *pChildren;
};

class RenderOperator_Clear: public RenderOperator
{
 public:
   RenderOperator_Clear(): RenderOperator() {}

   virtual unsigned int Initialize(Texture *pTexture, float pClearColor[4]) = 0;
};

class RenderOperator_Present: public RenderOperator
{
 public:
   RenderOperator_Present(): RenderOperator() {}

   virtual unsigned int Initialize() = 0;
};