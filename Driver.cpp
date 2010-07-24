#include "Render\\Render.h"
#include "Window.h"

Window *pDxWindow = 0,
       *pOglWindow = 0;
Render *pDxRender = 0,
       *pOglRender = 0;

extern "C" void Game_Initialize()
{
 return;

 struct Viewport dxWindowArea =
 {
  50,    0,
  850,  600,
  0,    0
 };

 struct Viewport dxRenderArea =
 {
  0,    0,
  800,  600,
  0,    0
 };


 pDxWindow = new Window;
 pDxWindow->Initialize(L"MM7w2dx", L"MM7 C++ Direct3D10 Render", true);
 pDxWindow->SetClientArea(&dxWindowArea);
 pDxWindow->Show();

 pDxRender = CreateDirect3D10Render();
 pDxRender->Initialize();
 pDxRender->Reset(pDxWindow, false, &dxRenderArea);




 struct Viewport oglWindowArea =
 {
  450,   300,
  1250,  990,
  0,    0
 };

 struct Viewport oglRenderArea =
 {
  0,    0,
  800,  600,
  0,    0
 };

 pOglWindow = new Window;
 pOglWindow->Initialize(L"MM7w2ogl", L"MM7 C++ OpenGL 3.2 Render", true);
 pOglWindow->SetClientArea(&oglWindowArea);
 pOglWindow->Show();

 pOglRender = CreateOpenGL32Render();
 pOglRender->Initialize();
 pOglRender->Reset(pOglWindow, false, &oglRenderArea);

 extern void InitializeRenderOperators();
 InitializeRenderOperators();
}





RenderOperator         *pDxRoot = 0;
RenderOperator_Clear   *pDxClearColorOperator = 0,
                       *pDxClearDepthOperator = 0;
RenderOperator_Present *pDxPresentOperator = 0;

RenderOperator         *pOglRoot = 0;
RenderOperator_Clear   *pOglClearColorOperator = 0,
                       *pOglClearDepthOperator = 0;
RenderOperator_Present *pOglPresentOperator = 0;

extern "C" void Game_Process_cpp()
{
 return;

 while (pDxWindow->Update(0));
 pDxRoot->Execute(pDxRender);

 while (pOglWindow->Update(0));
 pOglRoot->Execute(pOglRender);
}





extern "C" void InitializeRenderOperators()
{
 Texture *pDxPrimaryColorTarget,
         *pDxPrimaryDepthTarget;
 pDxRender->GetPrimaryColorTarget(&pDxPrimaryColorTarget);
 pDxRender->GetPrimaryDepthTarget(&pDxPrimaryDepthTarget);

 float pDxColorClear[4] = {0.5, 0.5, 0.5, 1},
       pDxDepthClear[4] = {1, 0, 0, 0};

 pDxClearColorOperator = pDxRender->CreateClearOperator();
 pDxClearColorOperator->Initialize(pDxPrimaryColorTarget, pDxColorClear);

 pDxClearDepthOperator = pDxRender->CreateClearOperator();
 pDxClearDepthOperator->Initialize(pDxPrimaryDepthTarget, pDxDepthClear);

 pDxPresentOperator = pDxRender->CreatePresentOperator();

 pDxRoot = pDxClearColorOperator;
 pDxClearColorOperator->pChildren = pDxClearDepthOperator;
 pDxClearDepthOperator->pChildren = pDxPresentOperator;
 pDxPresentOperator->pChildren = 0;




 Texture *pOglPrimaryColorTarget,
         *pOglPrimaryDepthTarget;
 pOglRender->GetPrimaryColorTarget(&pOglPrimaryColorTarget);
 pOglRender->GetPrimaryDepthTarget(&pOglPrimaryDepthTarget);

 float pOglColorClear[4] = {0.75, 0.75, 0.75, 1},
       pOglDepthClear[4] = {1, 0, 0, 0};

 pOglClearColorOperator = pOglRender->CreateClearOperator();
 pOglClearColorOperator->Initialize(pOglPrimaryColorTarget, pOglColorClear);

 pOglClearDepthOperator = pOglRender->CreateClearOperator();
 pOglClearDepthOperator->Initialize(pOglPrimaryDepthTarget, pOglDepthClear);

 pOglPresentOperator = pOglRender->CreatePresentOperator();

 pOglRoot = pOglClearColorOperator;
 pOglClearColorOperator->pChildren = pOglClearDepthOperator;
 pOglClearDepthOperator->pChildren = pOglPresentOperator;
 pOglPresentOperator->pChildren = 0;
}