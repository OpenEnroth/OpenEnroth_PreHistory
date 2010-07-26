#include "RenderOperatorsD3D10.h"
#include "RenderD3D10.h"
#include "..\\Camera.h"

#include <d3dx10.h>





unsigned int RenderOperatorD3D10_DrawEnvironment::Initialize(Render *pHostRender, Texture *pTargetTexture, Camera *pObserver)
{
 pRender = (RenderD3D10 *)pHostRender;
 pEnvTexture = (TextureD3D10 *)pTargetTexture;
 pCamera = pObserver;

 ID3D10Blob *pShader,
            *pErrors;
 D3DX10CompileFromFileW(L"data\\new\\shaders\\DrawEnvironment.psh", 0, 0, "main", "ps_4_0", 0, 0, 0, &pShader, &pErrors, 0);
 if (pErrors)
 {
  MessageBoxA(0, (const char *)pErrors->GetBufferPointer(), "Pixel shader error", 0);
  ExitProcess(0);
 }
 pRender->pDevice->CreatePixelShader(pShader->GetBufferPointer(), pShader->GetBufferSize(), &pPixelShader);
 pShader->Release();

 D3D10_SAMPLER_DESC sdCubeSampler;
 sdCubeSampler.Filter = D3D10_FILTER_ANISOTROPIC;
 sdCubeSampler.AddressU = D3D10_TEXTURE_ADDRESS_CLAMP;
 sdCubeSampler.AddressV = D3D10_TEXTURE_ADDRESS_CLAMP;
 sdCubeSampler.AddressW = D3D10_TEXTURE_ADDRESS_CLAMP;
 sdCubeSampler.MipLODBias = 0;
 sdCubeSampler.MaxAnisotropy = 8;
 sdCubeSampler.ComparisonFunc = D3D10_COMPARISON_NEVER;
 sdCubeSampler.BorderColor[0] = 0;
 sdCubeSampler.BorderColor[1] = 0;
 sdCubeSampler.BorderColor[2] = 0;
 sdCubeSampler.BorderColor[3] = 0;
 sdCubeSampler.MinLOD = 0;
 sdCubeSampler.MaxLOD = FLT_MAX;
 pRender->pDevice->CreateSamplerState(&sdCubeSampler, &pPixelShaderSampler0);


 pRender->CreateDepthStencilState((DepthStencilState **)&pDepthState_ScreenQuadClearingZ);
 pDepthState_ScreenQuadClearingZ->Initialize(pRender, true, true, DepthOperator::Always);



 D3DX10CompileFromFileW(L"data\\new\\shaders\\DrawEnvironment.vsh", 0, 0, "main", "vs_4_0", 0, 0, 0, &pShader, &pErrors, 0);
 if (pErrors)
 {
  MessageBoxA(0, (const char *)pErrors->GetBufferPointer(), "Vertex shader error", 0);
  ExitProcess(0);
 }
 pRender->pDevice->CreateVertexShader(pShader->GetBufferPointer(), pShader->GetBufferSize(), &pVertexShader);

 D3D10_BUFFER_DESC bdVertexConstants;
 bdVertexConstants.ByteWidth = 16 * sizeof(float);
 bdVertexConstants.Usage = D3D10_USAGE_DYNAMIC;
 bdVertexConstants.BindFlags = D3D10_BIND_CONSTANT_BUFFER;
 bdVertexConstants.CPUAccessFlags = D3D10_CPU_ACCESS_WRITE;
 bdVertexConstants.MiscFlags = 0;
 pRender->pDevice->CreateBuffer(&bdVertexConstants, 0, &pVertexShaderConstants);

 D3D10_INPUT_ELEMENT_DESC layout[] =
 {
  {"SV_Position", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0},
  {"TEXCOORD",    0, DXGI_FORMAT_R32_UINT,     1, 0, D3D10_INPUT_PER_VERTEX_DATA, 0}
 };
 pRender->pDevice->CreateInputLayout(layout, 2, pShader->GetBufferPointer(), pShader->GetBufferSize(), &pInputLayout);
 pShader->Release();


 D3D10_BUFFER_DESC bdScreenQuad;
 bdScreenQuad.ByteWidth = 6 * 2 * sizeof(float);
 bdScreenQuad.Usage = D3D10_USAGE_DEFAULT;
 bdScreenQuad.BindFlags = D3D10_BIND_VERTEX_BUFFER;
 bdScreenQuad.CPUAccessFlags = 0;
 bdScreenQuad.MiscFlags = 0;

 struct
 {
  float x, y;
 } pScreenQuad[] =
 {
  {-1,  1},
  { 1,  1},
  {-1, -1},

  {-1, -1},
  { 1,  1},
  { 1, -1}
 };
 D3D10_SUBRESOURCE_DATA sdScreenQuadInitializator;
 sdScreenQuadInitializator.pSysMem = pScreenQuad;
 sdScreenQuadInitializator.SysMemPitch = 6 * 2 * sizeof(float);
 sdScreenQuadInitializator.SysMemSlicePitch = 0;
 pRender->pDevice->CreateBuffer(&bdScreenQuad, &sdScreenQuadInitializator, &pVertexBuffer);

 return 0;
}

unsigned int RenderOperatorD3D10_DrawEnvironment::Execute()
{
 Matrix4x4 *pNewView;
 pVertexShaderConstants->Map(D3D10_MAP_WRITE_DISCARD, 0, (void **)&pNewView);
 {
  pCamera->GetViewOrientation(pNewView);
  /*Matrix4x4 rx;
  rx.RotateX(0.25f * 3.14159 * (GetTickCount() % 1000) / 1000.0f);
  pNewView->RotateY(3.14159 * (GetTickCount() % 1000) / 1000.0f);

  (*pNewView) = *pNewView * rx;*/

    //pNewView->RotateY(3.14159 * (GetTickCount() % 1000) / 1000.0f);

  //pNewView->RotateY(3.1415f / 8);
  DWORD w;
  char str[256];
  wsprintfA(str, "draw env: angle == 0.%04uï (%u)\n", GetTickCount() % 1000, (int)(3.14159 * (GetTickCount() % 1000)));
  WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), str, strlen(str), &w, 0);
  /*
  memset(pNewView, 0, 16 * 4);
  (*pNewView)[0][0] = 1;
  (*pNewView)[1][1] = 1;
  (*pNewView)[2][2] = 1;
  (*pNewView)[3][3] = 1;

  (*pNewView)[0][0] = cosf(2 * 3.14159 * (GetTickCount() % 2500) / 2500.0f);
  (*pNewView)[2][0] = sinf(2 * 3.14159 * (GetTickCount() % 2500) / 2500.0f);

  (*pNewView)[2][0] = -sinf(2 * 3.14159 * (GetTickCount() % 2500) / 2500.0f);
  (*pNewView)[2][2] = cosf(2 * 3.14159 * (GetTickCount() % 2500) / 2500.0f);*/
 }
 pVertexShaderConstants->Unmap();


 unsigned int pStrides[] = {2 * sizeof(float)},
              pOffsets[] = {0};

 pRender->pDevice->IASetInputLayout(pInputLayout);
 pRender->pDevice->IASetVertexBuffers(0, 1, &pVertexBuffer, pStrides, pOffsets);
 pRender->pDevice->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

 pRender->pDevice->VSSetShader(pVertexShader);
 pRender->pDevice->VSSetConstantBuffers(0, 1, &pVertexShaderConstants);

 pRender->pDevice->GSSetShader(0);

 pRender->pDevice->PSSetShader(pPixelShader);
 pRender->pDevice->PSSetShaderResources(0, 1, (ID3D10ShaderResourceView **)&pEnvTexture->pResourceView);
 pRender->pDevice->PSSetSamplers(0, 1, &pPixelShaderSampler0);

 pRender->pDevice->OMSetBlendState(pRender->pBlendState_Default, 0, 0xFFFFFF);

 pRender->pDevice->OMSetDepthStencilState(pDepthState_ScreenQuadClearingZ->pState, 0);

 pRender->pDevice->Draw(6, 0);

 if (pChildren)
   return pChildren->Execute();
 else return 0;
}



unsigned int RenderOperatorD3D10_Clear::Execute()
{
 if (pTexture->eFormat == TF_D16_float || pTexture->eFormat == TF_D32_float)
   pRender->pDevice->ClearDepthStencilView((ID3D10DepthStencilView *)(pTexture->pResourceView), D3D10_CLEAR_DEPTH, pClearColor[0], 0);
 else
   pRender->pDevice->ClearRenderTargetView((ID3D10RenderTargetView *)(pTexture->pResourceView), pClearColor);

 if (pChildren)
   return pChildren->Execute();
 else return 0;
};

unsigned int RenderOperatorD3D10_Clear::Initialize(Render *pHostRender, Texture *pTargetTexture, float pColor[4])
{
 pRender = (RenderD3D10 *)pHostRender;
 pTexture = (TextureD3D10 *)pTargetTexture;
 memcpy(pClearColor, pColor, 16);
 return 0;
}




unsigned int RenderOperatorD3D10_Present::Execute()
{
 RenderD3D10 *pRenderD3D10 = (RenderD3D10 *)pRender;

 pRenderD3D10->pSwapChain->Present(0, 0);

 if (pChildren)
   return pChildren->Execute();
 else return 0;
}

unsigned int RenderOperatorD3D10_Present::Initialize(Render *pHostRender)
{
 pRender = (RenderD3D10 *)pHostRender;
 return 0;
}



RenderOperator_Clear           *RenderD3D10::CreateClearOperator()           {return new RenderOperatorD3D10_Clear;}
RenderOperator_Present         *RenderD3D10::CreatePresentOperator()         {return new RenderOperatorD3D10_Present;}
RenderOperator_DrawEnvironment *RenderD3D10::CreateDrawEnvironmentOperator() {return new RenderOperatorD3D10_DrawEnvironment;}