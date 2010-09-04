#include "RenderOperatorsD3D10.h"
#include "RenderD3D10.h"
#include "..\\Camera.h"

#include <d3dx10.h>






unsigned int RenderOperatorD3D10_DrawTerrain::Execute()
{
 Vec3 vCameraPos = *pCamera->GetPosition();
 float fHeightmapPosX = (float)(uHeightmapDimX) * (vCameraPos.x / fTerrainCellScale) / uResolutionX,
       fHeightmapPosZ = (float)(uHeightmapDimY) * (vCameraPos.z / fTerrainCellScale) / uResolutionZ;

 if (fHeightmapPosX < 0)
 {
  fHeightmapPosX = 0;
  vCameraPos.x = 0;
 }
 else if (fHeightmapPosX >= uHeightmapDimX)
 {
  fHeightmapPosX = uHeightmapDimX - 1;
  vCameraPos.x = uResolutionX * fTerrainCellScale;
 }

 if (fHeightmapPosZ < 0)
 {
  fHeightmapPosZ = 0;
  vCameraPos.z = 0;
 }
 else if (fHeightmapPosZ >= uHeightmapDimY)
 {
  fHeightmapPosZ = uHeightmapDimY - 1;
  vCameraPos.z = uResolutionZ * fTerrainCellScale;
 }


 //vCameraPos.y = 5 + 128 * (unsigned char)pHeights[(unsigned int)(fHeightmapPosZ * uHeightmapDimX + fHeightmapPosX)] / 255.0f;
 pCamera->SetPosition(&vCameraPos);



 float *pConstants;
 pVertexConstants->Map(D3D10_MAP_WRITE_DISCARD, 0, (void **)&pConstants);
 {
  pCamera->GetViewProjection((Matrix4x4 *)pConstants);

  pConstants[16] = 1.0f / (uResolutionX * fTerrainCellScale);
  pConstants[17] = 1.0f / (uResolutionZ * fTerrainCellScale);
  pConstants[18] = 0;
  pConstants[19] = 0;
 }
 pVertexConstants->Unmap();


 unsigned int pStrides[] = {2 * sizeof(float)},
              pOffsets[] = {0};

 pRender->pDevice->IASetInputLayout(pInputLayout);
 pRender->pDevice->IASetVertexBuffers(0, 1, &pTerrain, pStrides, pOffsets);
 pRender->pDevice->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
 pRender->pDevice->IASetIndexBuffer(pTerrainLOD0, DXGI_FORMAT_R16_UINT, 0);

 pRender->pDevice->VSSetShader(pVertexShader);
 pRender->pDevice->VSSetConstantBuffers(0, 1, &pVertexConstants);
 pRender->pDevice->VSSetShaderResources(0, 1, (ID3D10ShaderResourceView **)&pHeightmap->pResourceView);

 pRender->pDevice->GSSetShader(0);

 pRender->pDevice->PSSetShader(pPixelShader);
 pRender->pDevice->PSSetShaderResources(0, 1, (ID3D10ShaderResourceView **)&_pmarkup->pResourceView);

 pRender->pDevice->OMSetBlendState(pRender->pBlendState_Default, 0, 0xFFFFFFFF);

 pRender->pDevice->OMSetDepthStencilState(pRender->pDepthStencilState_Default, 0);

 pRender->pDevice->DrawIndexed((uResolutionX - 1) * (uResolutionZ - 1) * 6, 0, 0);

 if (pChildren)
   return pChildren->Execute();
 else return 0;
}

unsigned int RenderOperatorD3D10_DrawTerrain::Initialize(Render *pHostRender, Texture *pTerrainHeightmap, unsigned int uResX, unsigned int uResZ, float fCellScale, Camera *pObserver)
{
 pRender = (RenderD3D10 *)pHostRender;
 pHeightmap = (TextureD3D10 *)pTerrainHeightmap;
 pCamera = pObserver;

 fTerrainCellScale = fCellScale;
 uResolutionX = uResX;
 uResolutionZ = uResZ;

 pRender->CreateTexture(L".\\data\\new\\markup.png", (Texture **)&_pmarkup);


 ID3D10Blob *pShader,
            *pErrors;
 D3DX10CompileFromFileW(L"data\\new\\shaders\\DrawTerrain.psh", 0, 0, "main", "ps_4_0", 0, 0, 0, &pShader, &pErrors, 0);
 if (pErrors)
 {
  MessageBoxA(0, (const char *)pErrors->GetBufferPointer(), "Pixel shader error", 0);
  ExitProcess(0);
 }
 pRender->pDevice->CreatePixelShader(pShader->GetBufferPointer(), pShader->GetBufferSize(), &pPixelShader);
 pShader->Release();



 D3DX10CompileFromFileW(L"data\\new\\shaders\\DrawTerrain.vsh", 0, 0, "main", "vs_4_0", 0, 0, 0, &pShader, &pErrors, 0);
 if (pErrors)
 {
  MessageBoxA(0, (const char *)pErrors->GetBufferPointer(), "Vertex shader error", 0);
  ExitProcess(0);
 }
 pRender->pDevice->CreateVertexShader(pShader->GetBufferPointer(), pShader->GetBufferSize(), &pVertexShader);

 D3D10_BUFFER_DESC bdVertexConstants;
 bdVertexConstants.ByteWidth = (16 + 4) * sizeof(float);
 bdVertexConstants.Usage = D3D10_USAGE_DYNAMIC;
 bdVertexConstants.BindFlags = D3D10_BIND_CONSTANT_BUFFER;
 bdVertexConstants.CPUAccessFlags = D3D10_CPU_ACCESS_WRITE;
 bdVertexConstants.MiscFlags = 0;
 pRender->pDevice->CreateBuffer(&bdVertexConstants, 0, &pVertexConstants);

 D3D10_INPUT_ELEMENT_DESC layout[] =
 {
  {"SV_Position", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0}
 };
 pRender->pDevice->CreateInputLayout(layout, 1, pShader->GetBufferPointer(), pShader->GetBufferSize(), &pInputLayout);
 pShader->Release();



 struct TerrainVertex *pTerrainVertices = new struct TerrainVertex[uResolutionX * uResolutionZ];
 for (int z = 0; z < uResolutionZ; ++z)
   for (int x = 0; x < uResolutionX; ++x)
   {
    pTerrainVertices[z * uResolutionX + x].x = x * fTerrainCellScale;
    pTerrainVertices[z * uResolutionX + x].z = z * fTerrainCellScale;
   }

 D3D10_BUFFER_DESC bdTerrain;
 bdTerrain.ByteWidth = uResolutionX * uResolutionZ * sizeof(struct TerrainVertex);
 bdTerrain.Usage = D3D10_USAGE_DEFAULT;
 bdTerrain.BindFlags = D3D10_BIND_VERTEX_BUFFER;
 bdTerrain.CPUAccessFlags = 0;
 bdTerrain.MiscFlags = 0;

 D3D10_SUBRESOURCE_DATA srdTerrainInitializator;
 srdTerrainInitializator.pSysMem = pTerrainVertices;
 srdTerrainInitializator.SysMemPitch = uResolutionX * uResolutionZ * sizeof(struct TerrainVertex);
 srdTerrainInitializator.SysMemSlicePitch = 0;

 pRender->pDevice->CreateBuffer(&bdTerrain, &srdTerrainInitializator, &pTerrain);





 unsigned short *pTerrainLOD0Indices = new unsigned short[(uResolutionX - 1) * (uResolutionZ - 1) * 6];
 unsigned short *pIndexData = pTerrainLOD0Indices;
 for (int z = 0; z < uResolutionZ - 1; ++z)
   for (int x = 0; x < uResolutionX - 1; ++x)
   {
    *pIndexData++ = z * uResolutionX + x;
    *pIndexData++ = (z + 1) * uResolutionX + x;
    *pIndexData++ = z * uResolutionX + x + 1;
    
    *pIndexData++ = z * uResolutionX + x + 1;
    *pIndexData++ = (z + 1) * uResolutionX + x;
    *pIndexData++ = (z + 1) * uResolutionX + x + 1;
   }

 D3D10_BUFFER_DESC bdTerrainLOD0;
 bdTerrainLOD0.ByteWidth = (uResolutionX - 1) * (uResolutionZ - 1) * 6 * sizeof(short);
 bdTerrainLOD0.Usage = D3D10_USAGE_DEFAULT;
 bdTerrainLOD0.BindFlags = D3D10_BIND_INDEX_BUFFER;
 bdTerrainLOD0.CPUAccessFlags = 0;
 bdTerrainLOD0.MiscFlags = 0;

 D3D10_SUBRESOURCE_DATA srdTerrainLOD0Initializator;
 srdTerrainLOD0Initializator.pSysMem = pTerrainLOD0Indices;
 srdTerrainLOD0Initializator.SysMemPitch = (uResolutionX - 1) * (uResolutionZ - 1) * 6 * sizeof(short);
 srdTerrainLOD0Initializator.SysMemSlicePitch = 0;

 pRender->pDevice->CreateBuffer(&bdTerrainLOD0, &srdTerrainLOD0Initializator, &pTerrainLOD0);

 delete [] pTerrainVertices;
 delete [] pTerrainLOD0Indices;




#pragma pack(push, 1)
struct TGAHeader
{
 unsigned char  tgaSkip;
 unsigned char  tgaDontCare1;
 unsigned char  tgaType;
 unsigned char  tgaDontCare2[9];
 unsigned short tgaWidth;
 unsigned short tgaHeight;
 unsigned char  tgaBPP;
 unsigned char  tgaDontCare3;
};
#pragma pack(pop)

 DWORD  w;
 void  *hFile = CreateFileW(L".\\data\\new\\Emerald Island.tga", GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
 if (hFile == INVALID_HANDLE_VALUE)
   return 1;

 struct TGAHeader tgaHeader;
 ReadFile(hFile, &tgaHeader, sizeof(struct TGAHeader), &w, 0);
 SetFilePointer(hFile, tgaHeader.tgaSkip, 0, FILE_CURRENT);

 if (tgaHeader.tgaBPP != 32)
 {
  MessageBoxW(0, L"Invalid Targa format", L"LoadTGA", 0);

  CloseHandle(hFile);
  return 1;
 }

 uHeightmapDimX = tgaHeader.tgaWidth;
 uHeightmapDimY = tgaHeader.tgaHeight;
 pHeights = new unsigned int[uHeightmapDimX * uHeightmapDimY];

 ReadFile(hFile, pHeights, uHeightmapDimX * uHeightmapDimY * sizeof(__int32), &w, 0);
 CloseHandle(hFile);

 return 0;
}





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

 pRender->pDevice->OMSetBlendState(pRender->pBlendState_Default, 0, 0xFFFFFFFF);

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
RenderOperator_DrawTerrain     *RenderD3D10::CreateDrawTerrainOperator()     {return new RenderOperatorD3D10_DrawTerrain;}