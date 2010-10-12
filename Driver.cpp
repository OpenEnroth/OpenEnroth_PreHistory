#include "Render\\Render.h"
#include "Window.h"
#include "Camera.h"

Camera *pGameCamera = 0;

Window *pDxWindow = 0,
       *pOglWindow = 0;
Render *pDxRender = 0,
       *pOglRender = 0;

void Game_Initialize()
{
 pGameCamera = new Camera;
 pGameCamera->Initialize(&Vec3(0, 0, 0), &Quaternion(1, 0, 0, 0));
 pGameCamera->SetProjection(3.14159f * (45.0 / 360.0), 1024.0 / 768.0, 0.1, 1000.0);

 struct Viewport dxWindowArea =
 {
  400,  0,
  1200, 600,
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



 /*
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
 */
 extern void InitializeRenderOperators();
 InitializeRenderOperators();
}





RenderOperator                 *pDxRoot = 0;
RenderOperator_Clear           *pDxClearColorOperator = 0,
                               *pDxClearDepthOperator = 0;
RenderOperator_DrawEnvironment *pDxDrawEnvironmentOperator = 0;
RenderOperator_DrawTerrain     *pDxDrawTerrainOperator = 0;
RenderOperator_Present         *pDxPresentOperator = 0;
Texture                        *pDxEnvTexture,
                               *pDxHeightmapTexture;

RenderOperator         *pOglRoot = 0;
RenderOperator_Clear   *pOglClearColorOperator = 0,
                       *pOglClearDepthOperator = 0;
RenderOperator_Present *pOglPresentOperator = 0;

void Game_Process_cpp()
{
 //dirty dirty hack
 {
  static bool first_run = true;
  static POINT old_pos = {0},
               new_pos = {0};
  if (first_run)
  {
   first_run = false;
   GetCursorPos(&old_pos);
   GetCursorPos(&new_pos);
  }
  else
  {
   old_pos.x = new_pos.x;
   old_pos.y = new_pos.y;
   GetCursorPos(&new_pos);
  
   if (old_pos.x - new_pos.x)
     pGameCamera->RotateY(-(old_pos.x - new_pos.x) * 0.0125f);
   if (old_pos.y - new_pos.y)
     pGameCamera->RotateX(-(old_pos.y - new_pos.y) * 0.0125f);

   float fMovementAmount = 7.5;
   if (GetAsyncKeyState(VK_LSHIFT))
     fMovementAmount *= 2.25f;

   if (GetAsyncKeyState('W'))
     pGameCamera->Move(fMovementAmount);
   else if (GetAsyncKeyState('S'))
     pGameCamera->Move(-fMovementAmount);
  }
 }

 //pGameCamera->RotateX(0.01250f);

 while (pDxWindow->Update(0));
 pDxRoot->Execute();
 /*
 while (pOglWindow->Update(0));
 pOglRoot->Execute();*/
}





void InitializeRenderOperators()
{
 pDxRender->CreateTextureCube(L"data\\new\\cubemap-evul.dds", &pDxEnvTexture);
 pDxRender->CreateTexture(L"data\\new\\Emerald Island.png", &pDxHeightmapTexture);

 Texture *pDxPrimaryColorTarget,
         *pDxPrimaryDepthTarget;
 pDxRender->GetPrimaryColorTarget(&pDxPrimaryColorTarget);
 pDxRender->GetPrimaryDepthTarget(&pDxPrimaryDepthTarget);

 float pDxColorClear[4] = {0.5, 0.5, 0.5, 1},
       pDxDepthClear[4] = {1, 0, 0, 0};

 pDxClearColorOperator = pDxRender->CreateClearOperator();
 pDxClearColorOperator->Initialize(pDxRender, pDxPrimaryColorTarget, pDxColorClear);

 pDxClearDepthOperator = pDxRender->CreateClearOperator();
 pDxClearDepthOperator->Initialize(pDxRender, pDxPrimaryDepthTarget, pDxDepthClear);

 pDxDrawEnvironmentOperator = pDxRender->CreateDrawEnvironmentOperator();
 pDxDrawEnvironmentOperator->Initialize(pDxRender, pDxEnvTexture, pGameCamera);

 pDxDrawTerrainOperator = pDxRender->CreateDrawTerrainOperator();
 pDxDrawTerrainOperator->Initialize(pDxRender, pDxHeightmapTexture, 256, 256, 15, pGameCamera);

 pDxPresentOperator = pDxRender->CreatePresentOperator();
 pDxPresentOperator->Initialize(pDxRender);

 
 pDxRoot = pDxDrawEnvironmentOperator;

 //pDxRoot = pDxClearColorOperator;
 //pDxRoot->pChildren = pDxClearDepthOperator;
 //pDxClearDepthOperator->pChildren = pDxDrawEnvironmentOperator;
 pDxDrawEnvironmentOperator->pChildren = pDxDrawTerrainOperator;
 pDxDrawTerrainOperator->pChildren = pDxPresentOperator;
 pDxPresentOperator->pChildren = 0;



 /*
 Texture *pOglPrimaryColorTarget,
         *pOglPrimaryDepthTarget;
 pOglRender->GetPrimaryColorTarget(&pOglPrimaryColorTarget);
 pOglRender->GetPrimaryDepthTarget(&pOglPrimaryDepthTarget);

 float pOglColorClear[4] = {0.75, 0.75, 0.75, 1},
       pOglDepthClear[4] = {1, 0, 0, 0};

 pOglClearColorOperator = pOglRender->CreateClearOperator();
 pOglClearColorOperator->Initialize(pOglRender, pOglPrimaryColorTarget, pOglColorClear);

 pOglClearDepthOperator = pOglRender->CreateClearOperator();
 pOglClearDepthOperator->Initialize(pOglRender, pOglPrimaryDepthTarget, pOglDepthClear);

 pOglPresentOperator = pOglRender->CreatePresentOperator();
 pOglPresentOperator->Initialize(pOglRender);

 pOglRoot = pOglClearColorOperator;
 pOglClearColorOperator->pChildren = pOglClearDepthOperator;
 pOglClearDepthOperator->pChildren = pOglPresentOperator;
 pOglPresentOperator->pChildren = 0;*/
}