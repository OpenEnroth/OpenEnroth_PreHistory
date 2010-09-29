#include "defs.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "data.h"

#include "RenderD3D3.h"


#pragma comment(lib, "legacy dx\\lib\\ddraw.lib")
#pragma comment(lib, "legacy dx\\lib\\dxguid.lib")
#pragma comment(lib, "legacy dx\\lib\\dinput8.lib")



//----- (MM7exe::00452347) --------------------------------------------------------
void Render_HWLContainer_ctor(struct Render_HWLContainer *_this)
{
 _this->pHWLFile = 0;
 _this->dword_000004 = 0;
 _this->dword_000008 = 0;

 _this->uNumElements = 0;
 memset(_this->pSriteNames, 0, 50000 * 4);
 memset(_this->pSpriteFileOffsets, 0, 50000 * 4);
 _this->dword_061A90 = 0;
 _this->dword_061A94 = 0;
}

//----- (MM7.exe::0045237F) --------------------------------------------------------
int Render_HWLContainer_LoadHWLHeaders(struct Render_HWLContainer *_this, const char *pFilename)
{
 int i;

 _this->pHWLFile = fopen(pFilename, "rb");
 if ( !_this->pHWLFile)
   return false;

 locked_fread(&_this->dword_000004, 1, 4, _this->pHWLFile);
 if (_this->dword_000004 != 0x54443344)
   return false;
 
 locked_fread(&_this->dword_000008, 4, 1, _this->pHWLFile);
 fseek(_this->pHWLFile, _this->dword_000008, 0);

 locked_fread(&_this->uNumElements, 4, 1, _this->pHWLFile);
 for (i = 0; i <_this->uNumElements; ++i)
 {
  _this->pSriteNames[i] = malloc(20);  //operator new(0x14u)
  locked_fread(_this->pSriteNames[i], 1, 20, _this->pHWLFile);
 }

 locked_fread(_this->pSpriteFileOffsets, 4, _this->uNumElements, _this->pHWLFile);
 _this->dword_061A90 = 0;
 return true;
}

//----- (MM7.exe::0049E992) --------------------------------------------------------
void Render_ctor(struct Render *_this)
{
  int v1; // eax@1
  char v3; // zf@1

 memset(_this, 0, sizeof(struct Render));


 _this->pdd4 = 0;
 _this->pdds4_FrontBuffer = 0;
 pD3DRenderer->pdds4_BackBuffer = 0;
 _this->dword_040098 = 0;
 _this->pdd2 = 0;
 _this->pdds2_FrontBuffer = 0;
 _this->pdds2_BackBuffer = 0;
 _this->dword_0400A8 = 0;

 Render_HWLContainer_ctor(&_this->struct_040114);
 Render_HWLContainer_ctor(&_this->struct_0A1BAC);

 _this->dword_040054 = 0;
 _this->dword_040058 = 1;
 _this->bUseDirect3D = ReadWindowsRegistry("Use D3D", false);
 _this->bStartInWindow = ReadWindowsRegistry("startinwindow", false);
 v1 = ReadWindowsRegistry("D3D Device", true);
 v3 = _this->bStartInWindow == 0;

 _this->bStartInWindow = v3 && v1 != 1;
 _this->uDesiredDirect3DDevice = v1;

  //force d3d
 _this->bUseDirect3D = true;

 _this->dword_000010 = 640;
 _this->dword_000014 = 480;
 _this->dword_00001C = 0;
 _this->dword_000020 = 0;
 _this->dword_000024 = 639;
 _this->dword_000028 = 479;

 _this->dword_04002C = 0;
 _this->dword_040030 = 0;
 _this->pActiveZBuffer = 0;
 _this->pDefaultZBuffer = 0;
 _this->dword_04003C = &unk_4EED80;
 _this->dword_040040 = dword_4EED78;

 _this->dword_040044 = 2;
 _this->dword_040048 = 6;

 _this->pRenderD3D3 = 0;

 _this->bSceneBegun = 0;

 _this->pTargetSurface = 0;
 _this->uTargetSurfacePitch = 0;

 _this->uClipRectY = 0;
 _this->uClipRectX = 0;
 _this->uClipRectW = 480;
 _this->uClipRectZ = 640;
 _this->dword_040104 = 1;

 _this->dword_040108 = 0;
 _this->uD3D3SceneBegun = 0;
 _this->dword_040110 = 0;

 _this->bUseColoredLights = ReadWindowsRegistry("Colored Lights", false);
 _this->bRequiredTextureStagesAvailable = false;
 _this->bTinting = true;
 _this->uLevelOfDetail = ReadWindowsRegistry("Detail Level", 1);

 _this->byte_103668[0] = 0;

 _this->dword_1036B8 = 0;
 _this->dword_1036BC = 0;
 Render_HWLContainer_LoadHWLHeaders(&_this->struct_040114, "data\\d3dbitmap.hwl");
 Render_HWLContainer_LoadHWLHeaders(&_this->struct_0A1BAC, "data\\d3dsprite.hwl");
}

//----- (MM7.exe::0049FBCD) --------------------------------------------------------
void Render_ClearTarget(struct Render *_this, unsigned int uColor)
{
 int v4; // ecx@4

 if (_this->pRenderD3D3)
 {
  if (_this->dword_040110)
    RenderD3D3_ClearTarget(_this->pRenderD3D3, 1, uColor, 0, 0.0);
 }
 else
 {
  v4 = _this->dword_000010 * _this->dword_000014 >> 1;
  memset(_this->pTargetSurface, uColor, 4 * v4);
 }
}

//----- (MM7.exe::004A51CB) --------------------------------------------------------
unsigned int Render_BeginScene(struct Render *_this)
{
  int v1; // eax@1
  //int Dst; // [sp+Ch] [bp-7Ch]@4
  //int v6; // [sp+1Ch] [bp-6Ch]@5
  //int v7; // [sp+30h] [bp-58h]@5
 char local_0[124];
 DDSURFACEDESC2 ddsd2;

 v1 = _this->bSceneBegun++;
 if (!v1)
 {
  if (_this->pRenderD3D3)
  {
   if (_this->dword_040108)
   {
    memset(&ddsd2, 0, sizeof(DDSURFACEDESC2));
    ddsd2.dwSize = sizeof(DDSURFACEDESC2);
    LOBYTE(v1) = LockSurface_DDraw4(_this->dword_040098, &ddsd2, 2049);
    if ((_BYTE)v1)
    {
     _this->pTargetSurface = ddsd2.lpSurface;
     _this->uTargetSurfacePitch = ddsd2.lPitch / (ddsd2.ddpfPixelFormat.dwRGBBitCount / 8);
     _this->dword_000018 = _this->uTargetSurfacePitch;
     goto LABEL_11;
    }

    _this->bSceneBegun--;
    return v1;
   }
  }
  else
  {
   if (!_this->pTargetSurface)
   {
    LOBYTE(v1) = Render_LockBackBuffer(_this, &_this->pTargetSurface, &_this->uTargetSurfacePitch);
    if (_this->pTargetSurface)
    {
     _this->dword_000018 = _this->uTargetSurfacePitch;
     goto LABEL_11;
    }
    _this->bSceneBegun--;
    return v1;
   }
  }

LABEL_11:
  LOBYTE(v1) = Render_RestoreFrontBuffer(_this);
 }
 return v1;
}

//----- (004A0BEE) --------------------------------------------------------
char Render_FillRect(struct Render *_this, unsigned int uX, unsigned int uY, unsigned int uZ, unsigned int uW, unsigned int uColor)
{
  int v13; // edi@21
  int v14; // eax@21
  int v15; // eax@22
  int v16; // eax@25
  int v17; // eax@27
  int v18; // eax@28
  int v19; // edi@30
  signed __int64 v20; // qax@41
  int v21; // edi@41
  signed int v25; // edx@50
  int v27; // esi@52
  int v28; // ebx@54
  int v29; // edx@55
  int v30; // edi@55
  int v31; // ebx@60
  int v32; // edx@61
  int v36; // [sp+10h] [bp-Ch]@1
  __int64 v37; // [sp+14h] [bp-8h]@1
  signed int v38; // [sp+18h] [bp-4h]@28
  int v40; // [sp+28h] [bp+Ch]@28
  int v42; // [sp+2Ch] [bp+10h]@19
  int v43; // [sp+2Ch] [bp+10h]@38
 unsigned int *pTargetSurface;
 unsigned int  uRectWidth,
               uRectHeight;
 unsigned int  x, y;
  
  v36 = _this;
  v37 = 0i64;

  if (uX < _this->dword_00001C)
    HIDWORD(v37) = 8;
  if (uX > _this->dword_000024)
    HIDWORD(v37) |= 4u;

  if (uY < _this->dword_000020)
    HIDWORD(v37) |= 2;
  if (uY > _this->dword_000028)
    HIDWORD(v37) |= 1u;

  if (uZ < _this->dword_00001C)
    LODWORD(v37) = 8;
  if (uZ > _this->dword_000024)
    LODWORD(v37) = v37 | 4;

  if (uW < _this->dword_000020)
    LODWORD(v37) = v37 | 2;
  if (uW > _this->dword_000028)
    LODWORD(v37) = v37 | 1;

  if ( (_DWORD)v37 & HIDWORD(v37) )
    return (_BYTE)v37;

 pTargetSurface = pD3DRenderer->pTargetSurface;
 for (y = uY; y < uW; ++y)
   for (x = uX; x < uZ; ++x)
      pTargetSurface[y * pD3DRenderer->uTargetSurfacePitch + x] = uColor;

  /*
  if ( !v37 )
  {
LABEL_46:
      uRectWidth = uZ - uX;
      uRectHeight = uW - uY;

      v25 = 1;

      v27 = 0;

      pTargetSurface = _this->pTargetSurface + uX + uY * pD3DRenderer->uTargetSurfacePitch;
        if ( uRectWidth <= uRectHeight )
        {
          v31 = uRectHeight + 1;
          if ( v31 > 0 )
          {
            v32 = v25;
            do
            {
              v27 += uRectWidth;
              *pTargetSurface = uColor;
              pTargetSurface += pD3DRenderer->uTargetSurfacePitch;
              if ( v27 > 0 )
              {
                v27 -= uRectHeight;
                pTargetSurface += v32;
              }
              --v31;
            }
            while ( v31 );
          }
        }
        else
        {
          v28 = uRectWidth + 1;
          if ( uRectWidth + 1 > 0 )
          {
            v30 = pD3DRenderer->uTargetSurfacePitch;
            v29 = v25;
            do
            {
              v27 += uRectHeight;
              *pTargetSurface = uColor;
              pTargetSurface += v29;
              if ( v27 > uRectWidth )
              {
                v27 -= uRectWidth;
                pTargetSurface += v30;
              }
              --v28;
            }
            while ( v28 );
          }
        }
    return pTargetSurface;
  }
  v42 = HIDWORD(v37) ^ v37;
  if ( (BYTE4(v37) ^ (_BYTE)v37) & 8 )
  {
    if ( BYTE4(v37) & 8 )
    {
      v14 = (uW - uY) * (_this->dword_00001C - uX) / (uZ - uX);
      v13 = v36;
      uY = v14 + uY;
      uX = *(_DWORD *)(v36 + 28);
      goto LABEL_24;
    }
    v15 = (uY - uW) * (_this->dword_00001C - uZ) / (uX - uZ);
    uZ = _this->dword_00001C;
    uW = v15 + uW;
  }
  v13 = v36;
LABEL_24:
  if ( v42 & 4 )
  {
    v16 = *(_DWORD *)(v13 + 36);
    if ( BYTE4(v37) & 4 )
    {
      v13 = v36;
      uY += (uW - uY) * (v16 - uX) / (uZ - uX);
      uX = *(_DWORD *)(v36 + 36);
    }
    else
    {
      v17 = (uY - uW) * (v16 - uZ) / (uX - uZ);
      uZ = *(_DWORD *)(v13 + 36);
      uW += v17;
    }
  }
  v18 = *(_DWORD *)(v13 + 32);
  v38 = 0;
  v40 = *(_DWORD *)(v13 + 32);
  if ( uY < v18 )
    v38 = 2;
  v19 = *(_DWORD *)(v13 + 40);
  if ( uY > v19 )
    v38 |= 1u;
  if ( uW >= v18 )
    pTargetSurface = 0;
  else
    pTargetSurface = 2;
  compile_error;
  if ( uW > v19 )
    LOBYTE(pTargetSurface) = pTargetSurface | 1;
  if ( !(pTargetSurface & v38) )
  {
    pTargetSurface ^= v38;
    v43 = pTargetSurface;
    if ( pTargetSurface & 2 )
    {
      if ( v38 & 2 )
      {
        uX += (uZ - uX) * (v40 - uY) / (uW - uY);
        LOBYTE(pTargetSurface) = v36;
        uY = *(_DWORD *)(v36 + 32);
      }
      else
      {
        v20 = (uX - uZ) * (v40 - uW);
        v21 = uY - uW;
        uW = v40;
        pTargetSurface = v20 / v21;
        uZ += pTargetSurface;
      }
    }
    if ( v43 & 1 )
    {
      if ( v38 & 1 )
      {
        uX += (uZ - uX) * (*(_DWORD *)(v36 + 40) - uY) / (uW - uY);
        LOBYTE(pTargetSurface) = v36;
        uY = *(_DWORD *)(v36 + 40);
      }
      else
      {
        pTargetSurface = (uX - uZ) * (*(_DWORD *)(v36 + 40) - uW) / (uY - uW);
        uW = *(_DWORD *)(v36 + 40);
        uZ += pTargetSurface;
      }
    }
    goto LABEL_46;
  }
  return pTargetSurface;*/
}

//----- (MM7.exe::004A1605) --------------------------------------------------------
int Render_LockBackBuffer(struct Render *_this, void **ppOutSurfacePtr, unsigned int *pOutSurfaceWidth)
{
  DDSURFACEDESC2 ddsd2;
  //int v6; // [sp+4h] [bp-7Ch]@4
  int Dst; // [sp+14h] [bp-6Ch]@3
  int v8; // [sp+24h] [bp-5Ch]@3
  int v9; // [sp+28h] [bp-58h]@4
  int v10; // [sp+38h] [bp-48h]@3

 if ( dword_F79D7C != 2 || dword_F79D70 != 4 )
 {
  memset(&ddsd2, 0, sizeof(DDSURFACEDESC2));
  ddsd2.dwSize = sizeof(DDSURFACEDESC2);

  LockSurface_DDraw4(_this->pdds4_BackBuffer, &ddsd2, 1);
  *ppOutSurfacePtr = ddsd2.lpSurface;
  *pOutSurfaceWidth = ddsd2.lPitch / (ddsd2.ddpfPixelFormat.dwRGBBitCount / 8);
 }
  else
  {
   _asm int 3;  //ddraw2
    memset(&Dst, 0, 0x6Cu);
    Dst = 108;
    LockSurface_DDraw2(_this->pdds2_BackBuffer, &Dst, 1);
    *ppOutSurfacePtr = v10;
    *pOutSurfaceWidth = v8;
  }

 return *pOutSurfaceWidth;
}

//----- (004A5B81) --------------------------------------------------------
void Render_Set2DClippingRect(struct Render *_this, unsigned int uX, unsigned int uY, unsigned int uZ, unsigned int uW)
{
 _this->uClipRectX = uX;
 _this->uClipRectY = uY;
 _this->uClipRectZ = uZ;
 _this->uClipRectW = uW;
 _this->dword_040104 = 1;
}

extern struct class18 pending_texture;
void Render_DrawIndexedTextureHandle(struct Render *_this, unsigned int uX, unsigned int uY, unsigned int uTextureID)
{
  //int v5; // eax@4
  int v6; // ebx@4
  //int v7; // edx@5
  int v8; // edx@6
  //int v9; // edx@7
  int v10; // edx@8
  int v11; // edx@9
  int v12; // esi@12
  int v13; // esi@15
  int v14; // edx@17
  int v15; // esi@18
  int v16; // edx@22
  char v18; // zf@26
  int v19; // [sp+10h] [bp-10h]@4
  int v20; // [sp+18h] [bp-8h]@4
  int v21; // [sp+1Ch] [bp-4h]@4
  int v22; // [sp+28h] [bp+8h]@24
  int v23; // [sp+2Ch] [bp+Ch]@22
  int v24; // [sp+30h] [bp+10h]@11
  int v25; // [sp+30h] [bp+10h]@22
 unsigned int   *pSurfacePtr;
 unsigned int    y,
                 x;
 unsigned int    uSrcColor,
                 uDstColor,
                 uAlpha;
 struct class18 *pTexture;

 if (uTextureID != -1)
   pTexture = &pLODFile_Icons_LOD->aLODHeaders[uTextureID];
 else pTexture = &pending_texture;

 if (!_this->bSceneBegun || !pTexture)
   return;


 pSurfacePtr = (unsigned int *)(_this->pTargetSurface);

 for (y = 0; y < pTexture->uTextureHeight; ++y)
 {
  if (y + uY < _this->uClipRectY)
    continue;
  if (y + uY >= _this->uClipRectW)
    continue;

  for (x = 0; x < pTexture->uTextureWidth; ++x)
  {
   if (x + uX < _this->uClipRectX)
     continue;
   if (x + uX >= _this->uClipRectZ)
     continue;

   uSrcColor = pTexture->pTruecolorPixels[y * pTexture->uTextureWidth + x];
   uDstColor = pSurfacePtr[(y + uY) * _this->uTargetSurfacePitch + x + uX];
   uAlpha = ((uSrcColor & 0xFF000000) >> 8) | ((uSrcColor & 0xFF000000) >> 16) | ((uSrcColor & 0xFF000000) >> 24);
   pSurfacePtr[(y + uY) * _this->uTargetSurfacePitch + x + uX] = (uSrcColor & uAlpha) + (uDstColor & (0x00FFFFFF - uAlpha));
  }
 }
}

//----- (004A5EB2) --------------------------------------------------------
void Render_DrawIndexedTexture(struct Render *_this, unsigned int uX, unsigned int uY, struct class18 *pTexture)
{
  //int v5; // eax@4
  int v6; // ebx@4
  //int v7; // edx@5
  int v8; // edx@6
  //int v9; // edx@7
  int v10; // edx@8
  int v11; // edx@9
  int v12; // esi@12
  int v13; // esi@15
  int v14; // edx@17
  int v15; // esi@18
  int v16; // edx@22
  char v18; // zf@26
  int v19; // [sp+10h] [bp-10h]@4
  int v20; // [sp+18h] [bp-8h]@4
  int v21; // [sp+1Ch] [bp-4h]@4
  int v22; // [sp+28h] [bp+8h]@24
  int v23; // [sp+2Ch] [bp+Ch]@22
  int v24; // [sp+30h] [bp+10h]@11
  int v25; // [sp+30h] [bp+10h]@22
 unsigned int *pSurfacePtr;
 unsigned int  y,
               x;
 unsigned int  uSrcColor,
               uDstColor;

 if (!_this->bSceneBegun || !pTexture)
   return;


 pSurfacePtr = (unsigned int *)(_this->pTargetSurface);

 for (y = 0; y < pTexture->uTextureHeight; ++y)
 {
  if (y + uY < _this->uClipRectY)
    continue;
  if (y + uY >= _this->uClipRectW)
    continue;

  for (x = 0; x < pTexture->uTextureWidth; ++x)
  {
   if (x + uX < _this->uClipRectX)
     continue;
   if (x + uX >= _this->uClipRectZ)
     continue;

   uSrcColor = pTexture->pTruecolorPixels[y * pTexture->uTextureWidth + x];
   uDstColor = pSurfacePtr[(y + uY) * _this->uTargetSurfacePitch + x + uX];
   pSurfacePtr[(y + uY) * _this->uTargetSurfacePitch + x + uX] = uSrcColor;
  }
 }
}


//----- (004A6C4F) --------------------------------------------------------
void Render_DrawText(struct Render *_this, unsigned int uOutX, unsigned int uOutY,
                unsigned char *pFontPixels, unsigned int uCharWidth, unsigned int uCharHeight,
                unsigned short *pFontPalette, unsigned int uMainColor, unsigned int uShadowColor)
{
 unsigned int  *pSurfacePtr;
 unsigned char *pPixel;
 int x, y;

 if (!_this->bSceneBegun)
   return;

 pSurfacePtr = (unsigned int *)(_this->pTargetSurface);
 pPixel = pFontPixels;

 for (y = 0; y < uCharHeight; ++y)
   for (x = 0; x < uCharWidth; ++x)
   {
    if (*pPixel++)
    {
     unsigned int uSrc = pFontPalette[pPixel[-1]] == 0x0000 ? uShadowColor : uMainColor;

     pSurfacePtr[(uOutY + y) * _this->uTargetSurfacePitch + uOutX + x] = uSrc;
    }
   }
}




//----- (004A6274) --------------------------------------------------------
void Render_DrawTransparentTexture(struct Render *_this, unsigned int uX, unsigned int uY, struct class18 *pTexture)
{
  int v5; // eax@4
  int v6; // ebx@4
  int v7; // edx@5
  int v8; // edx@6
  int v9; // edx@7
  int v10; // edx@8
  int v11; // edx@9
  int v12; // esi@12
  int v13; // esi@15
  int v14; // edx@17
  int v15; // esi@18
  int v16; // ebx@22
  char v18; // zf@28
  int v19; // [sp+10h] [bp-10h]@4
  int v20; // [sp+18h] [bp-8h]@4
  int v21; // [sp+1Ch] [bp-4h]@4
  int v22; // [sp+28h] [bp+8h]@24
  int v23; // [sp+2Ch] [bp+Ch]@22
  int v24; // [sp+30h] [bp+10h]@11
  int v25; // [sp+30h] [bp+10h]@22
 unsigned int *pSurfacePtr;
 unsigned int  x, y;
 unsigned int  uSrcColor,
               uDstColor,
               uAlpha;

 if (!_this->bSceneBegun || !pTexture)
   return;

 pSurfacePtr = (unsigned int *)(_this->pTargetSurface);
 for (y = 0; y < pTexture->uTextureHeight; ++y)
 {
  if (y + uY < _this->uClipRectY)
    continue;
  if (y + uY >= _this->uClipRectW)
    continue;

  for (x = 0; x < pTexture->uTextureWidth; ++x)
  {
   float        src_alpha,
                dst_alpha;
   unsigned int dst_channel[3];

   if (x + uX < _this->uClipRectX)
     continue;
   if (x + uX >= _this->uClipRectZ)
     continue;

   uSrcColor = pTexture->pTruecolorPixels[y * pTexture->uTextureWidth + x];
   uDstColor = pSurfacePtr[(y + uY) * _this->uTargetSurfacePitch + x + uX];

   src_alpha = (uSrcColor >> 24) / 255.0f;
   dst_alpha = 1.0f - src_alpha; //(uDstColor >> 24) / 255.0f

   dst_channel[0] = (unsigned char)(src_alpha * ((uSrcColor >> 16) & 0xFF) + dst_alpha * ((uDstColor >> 16) & 0xFF));
   dst_channel[1] = (unsigned char)(src_alpha * ((uSrcColor >> 8) & 0xFF) + dst_alpha * ((uDstColor >> 8) & 0xFF));
   dst_channel[2] = (unsigned char)(src_alpha * (uSrcColor & 0xFF) + dst_alpha * (uDstColor & 0xFF));

   pSurfacePtr[(y + uY) * _this->uTargetSurfacePitch + x + uX] = 0xFF000000 |
                                                                 (dst_channel[0] << 16) |
                                                                 (dst_channel[1] << 8) |
                                                                 dst_channel[2];
  }
 }
}

void Render_DrawTransparentRect(struct Render *_this, unsigned int uOutX, unsigned int uOutY,
                                      unsigned int uSrcX, unsigned int uSrcY, unsigned int uSrcWidth, unsigned int uSrcHeight,
                                      struct class18 *pTexture)
{
 unsigned int *pSurfacePtr;
 unsigned int  x, y;
 unsigned int  uSrcColor,
               uDstColor;

 if (!_this->bSceneBegun || !pTexture)
   return;

 pSurfacePtr = (unsigned int *)(_this->pTargetSurface);
 for (y = 0; y < uSrcHeight; ++y)
   for (x = 0; x < uSrcWidth; ++x)
   {
    float        src_alpha,
                 dst_alpha;
    unsigned int dst_channel[3];
    uSrcColor = pTexture->pTruecolorPixels[(y + uSrcY) * pTexture->uTextureWidth + x + uSrcX];
    uDstColor = pSurfacePtr[(y + uOutY) * _this->uTargetSurfacePitch + x + uOutX];

    src_alpha = (uSrcColor >> 24) / 255.0f;
    dst_alpha = 1.0f - src_alpha; //(uDstColor >> 24) / 255.0f

    dst_channel[0] = (unsigned char)(src_alpha * ((uSrcColor >> 16) & 0xFF) + dst_alpha * ((uDstColor >> 16) & 0xFF));
    dst_channel[1] = (unsigned char)(src_alpha * ((uSrcColor >> 8) & 0xFF) + dst_alpha * ((uDstColor >> 8) & 0xFF));
    dst_channel[2] = (unsigned char)(src_alpha * (uSrcColor & 0xFF) + dst_alpha * (uDstColor & 0xFF));

    pSurfacePtr[(y + uOutY) * _this->uTargetSurfacePitch + x + uOutX] = 0xFF000000 |
                                                                        (dst_channel[0] << 16) |
                                                                        (dst_channel[1] << 8) |
                                                                        dst_channel[2];
   }
}

//----- (004A172E) --------------------------------------------------------
int Render_LockFrontBuffer(struct Render *_this, void **ppOutSurfacePtr, unsigned int *pOutSurfaceWidth)
{
 DDSURFACEDESC2 ddsd2;

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
 {
  memset(&ddsd2, 0, sizeof(DDSURFACEDESC2));
  ddsd2.dwSize = sizeof(DDSURFACEDESC2);
  LockSurface_DDraw4(_this->pdds4_FrontBuffer, &ddsd2, 1);
  *ppOutSurfacePtr = ddsd2.lpSurface;
  *pOutSurfaceWidth = ddsd2.lPitch / (ddsd2.ddpfPixelFormat.dwRGBBitCount / 8);
 }
 else
 {
  __asm int 3;
 }
 return *pOutSurfaceWidth;
}

//----- (004A527D) --------------------------------------------------------
HRESULT Render_EndScene(struct Render *_this)
{
 if (_this->pRenderD3D3)
   return RenderD3D3_EndScene(_this->pRenderD3D3);

 if (!_this->bSceneBegun)
   return E_FAIL;

 _this->bSceneBegun--;
 _this->pTargetSurface = 0;
 _this->uTargetSurfacePitch = 0;
 _this->dword_000018 = 0;
 return Render_UnlockBackBuffer(_this);
}

//----- (004A16E1) --------------------------------------------------------
void *Render_UnlockBackBuffer(struct Render *_this)
{
 IDirectDrawSurface *v1;
 HRESULT             hr;
 char                local_0[128];


 if (dword_F79D7C != 2 || dword_F79D70 != 4)
   v1 = _this->pdds4_BackBuffer;
 else
   v1 = _this->pdds2_BackBuffer;

 hr = (_this->pdds4_BackBuffer->lpVtbl->Unlock)(_this->pdds4_BackBuffer, 0);
 return CheckHRESULT(local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2560, 0);
}



void Render_DrawRGBTexture_New(struct Render *_this, unsigned int uX, unsigned int uY, unsigned int uTextureID)
{
 unsigned int   *pSurfacePtr;
 unsigned int    uColor;
 int             x, y;
 struct class18 *pTexture;

 if (!_this->bSceneBegun)
   return;

 if (uTextureID == -1)
   return;

 pTexture = &pLODFile_Icons_LOD->aLODHeaders[uTextureID];


 pSurfacePtr = (unsigned int *)(_this->pTargetSurface);
 for (y = 0; y < pTexture->uTextureHeight; ++y)
 {
  unsigned int startX,
               endX;

  if (y + uY < _this->uClipRectY)
    continue;
  else if (y + uY >= _this->uClipRectW)
    return;

  startX = max(_this->uClipRectX, uX);
  endX = min(min(_this->uClipRectZ, uX + pTexture->uTextureWidth), 640);

  memcpy(pSurfacePtr + (y + uY) * _this->uTargetSurfacePitch + startX,
         pTexture->pTruecolorPixels + y * pTexture->uTextureWidth + startX - uX,
         (endX - startX) * 4);
 }
}

//----- (004A5BE3) --------------------------------------------------------
void Render_DrawRGBTexture(struct Render *_this, unsigned int uX, unsigned int uY, struct RGBTexture *pTexture)
{
 unsigned int *pSurfacePtr;
 unsigned int uColor;
  int v5; // edi@3
 unsigned short *v6; // esi@3
 int x, y;
  int v7; // ebx@4
  int v8; // eax@5
  int v9; // ebx@5
  int v10; // eax@6
  int v11; // eax@7
  int v12; // ebx@8
  int v13; // eax@10
  int v14; // edi@11
  int v15; // eax@14
  int v16; // ebx@17
  int v17; // eax@23
  char v18; // zf@25
  int v19; // [sp+10h] [bp-8h]@3
  int v20; // [sp+14h] [bp-4h]@3
  int v21; // [sp+20h] [bp+8h]@16
  int v22; // [sp+20h] [bp+8h]@21
  int v23; // [sp+24h] [bp+Ch]@21
  int v24; // [sp+28h] [bp+10h]@3

 if (!_this->bSceneBegun)
   return;

 if (!pTexture)
   return;


 pSurfacePtr = (unsigned int *)(_this->pTargetSurface);
 for (y = 0; y < pTexture->uHeight; ++y)
 {
  unsigned int startX,
               endX;

  if (y + uY < _this->uClipRectY)
    continue;
  else if (y + uY >= _this->uClipRectW)
    return;

  startX = max(_this->uClipRectX, uX);
  endX = min(min(_this->uClipRectZ, uX + pTexture->uWidth), 640);

  memcpy(pSurfacePtr + (y + uY) * _this->uTargetSurfacePitch + startX,
         pTexture->pPixels + y * pTexture->uWidth + startX - uX,
         (endX - startX) * 4);
 }
}

//----- (MM7.exe::0049FFFB) --------------------------------------------------------
int Render_Initialize(struct Render *_this, HWND hwnd)
{
  int v3; // esi@1
  int v4; // eax@2
  int v6; // edx@5
  int v7; // ecx@5
  signed int v8; // eax@6
  signed int v9; // eax@13
  int v10; // ecx@13
  int v11; // eax@15
  int v12; // eax@19
  int v13; // eax@23
  unsigned int v14; // ecx@25
  int v15; // eax@25
  int v16; // eax@25
  unsigned int v17; // eax@27
  int v18; // ebx@31
  bool v19; // eax@35
  char v20; // zf@35
  int v21; // eax@38
  int v22; // eax@38
  void *v23; // eax@39
  int v25; // eax@42
  int v26; // ecx@42
  int v27; // [sp+Ch] [bp-300h]@25
  int v28; // [sp+108h] [bp-204h]@40
  int v29; // [sp+12Ch] [bp-1E0h]@42
  int Dst; // [sp+184h] [bp-188h]@25
  unsigned int v31; // [sp+230h] [bp-DCh]@25
  unsigned int v32; // [sp+234h] [bp-D8h]@25
  unsigned int v33; // [sp+238h] [bp-D4h]@27
  unsigned int v34; // [sp+23Ch] [bp-D0h]@27
  int v35; // [sp+280h] [bp-8Ch]@38
  int v36; // [sp+284h] [bp-88h]@38
  int v37; // [sp+288h] [bp-84h]@38
  int v38; // [sp+28Ch] [bp-80h]@38
  int v39; // [sp+2C0h] [bp-4Ch]@38
  int v40; // [sp+2C4h] [bp-48h]@38
  int v41; // [sp+2E8h] [bp-24h]@38
  int v42; // [sp+2FCh] [bp-10h]@2
  int v43; // [sp+308h] [bp-4h]@2

  v3 = _this;
  _this->pdd4 = 0;
  _this->pdds4_FrontBuffer = 0;
  pD3DRenderer->pdds4_BackBuffer = 0;
  _this->dword_040098 = 0;
  _this->dword_040108 = 0;
  _this->dword_040110 = 0;

  //try_catch session
  sub_49FE05(_this);
  _this->hWnd = hwnd;
  Render_Initialize_ZBuffer(_this);

  if (_this->bUseDirect3D)
  {
    v4 = malloc(0x148u);
    v42 = v4;
    v43 = 0;
    if ( v4 )
      RenderD3D3_FindAvailableDevices(v4);

    v6 = *(_DWORD *)(v3 + 8);
    v43 = -1;
    *(_DWORD *)(v3 + 262280) = v4;
    v7 = *(_DWORD *)(v4 + 28);
    if ( *(_DWORD *)(v7 + 40 * v6) )
    {
      v8 = RenderD3D3_Initialize(v4, v6, 0, hwnd);
      *(_DWORD *)(v3 + 12) = *(_DWORD *)(v3 + 8);
    }
    else
    {
      if ( *(_DWORD *)(v7 + 40) )
      {
        v8 = RenderD3D3_Initialize(v4, 1, 0, hwnd);
        *(_DWORD *)(v3 + 12) = 1;
      }
      else
      {
        if ( !*(_DWORD *)v7 )
          erroneous_printf("There aren't any D3D devices to create.");
        v8 = RenderD3D3_Initialize(v4, 0, 0, hwnd);
        *(_DWORD *)(v3 + 12) = 0;
      }
    }
    if ( !v8 )
      erroneous_printf("D3Drend->Init failed.");
    v10 = *(_DWORD *)(v3 + 262280);
    *(_DWORD *)(v3 + 262292) = *(_DWORD *)(v10 + 44);
    *(_DWORD *)(v3 + 262288) = *(_DWORD *)(v10 + 48);
    *(_DWORD *)(v3 + 262284) = *(_DWORD *)(v10 + 32);
    v9 = RenderD3D3_GetDeviceCaps((void *)v10);
    if ( v9 & 1 )
    {
      hwnd = *(_DWORD *)(v3 + 262280);
      if ( hwnd )
      {
        v11 = sub_49DC90(hwnd);
        operator_delete(v11, hwnd);
      }
      *(_DWORD *)(v3 + 262280) = 0;
      *(_DWORD *)(v3 + 262292) = 0;
      *(_DWORD *)(v3 + 262288) = 0;
      *(_DWORD *)(v3 + 262284) = 0;
      erroneous_printf("Direct3D renderer:  The device failed to return capabilities.");
    }
    if ( v9 & 0x3E )
    {
      hwnd = *(_DWORD *)(v3 + 262280);
      if ( hwnd)
      {
        v12 = sub_49DC90(hwnd);
        operator_delete(v12, hwnd);
      }
      *(_DWORD *)(v3 + 262296) = 0;
      *(_DWORD *)(v3 + 262280) = 0;
      *(_DWORD *)(v3 + 262292) = 0;
      *(_DWORD *)(v3 + 262288) = 0;
      *(_DWORD *)(v3 + 262284) = 0;
      erroneous_printf("Direct3D renderer:  The device doesn't support the necessary alpha blending modes.");
    }
    if ( (_BYTE)v9 < 0 )
    {
      hwnd = *(_DWORD *)(v3 + 262280);
      if ( hwnd )
      {
        v13 = sub_49DC90(hwnd);
        operator_delete(v13, hwnd);
      }
      *(_DWORD *)(v3 + 262280) = 0;
      *(_DWORD *)(v3 + 262292) = 0;
      *(_DWORD *)(v3 + 262288) = 0;
      *(_DWORD *)(v3 + 262284) = 0;
      erroneous_printf("Direct3D renderer:  The device doesn't support non-square textures.");
    }
    *(_BYTE *)(v3 + 1062492) = ~(unsigned __int8)((unsigned int)v9 >> 6) & 1;
    *(_DWORD *)(v3 + 1062472) = Render_ValidateTextureStages();
    memset(&Dst, 0, 0xFCu);
    Dst = 252;
    memset(&v27, 0, 0xFCu);
    v15 = *(_DWORD *)(v3 + 262280);
    v27 = 252;
    v16 = (*(int (__stdcall **)(_DWORD, int *, int *))(**(_DWORD **)(v15 + 56) + 12))(*(_DWORD *)(v15 + 56), &Dst, &v27);
    CheckHRESULT(&hwnd, v16, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 0x583u, 0);
    v14 = v31;
    if ( v31 >= v32 )
      v14 = v32;
    v17 = v33;
    *(_DWORD *)(v3 + 1062488) = v14;
    if ( v17 < v34 )
      v17 = v34;
    *(_DWORD *)(v3 + 1062484) = v17;
    if ( v14 < 4 )
      *(_DWORD *)(v3 + 1062488) = 4;
    Render_sub_49FFD7(v3);
    v18 = 1;
    (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v3 + 262280) + 56) + 88))(
      *(_DWORD *)(*(_DWORD *)(v3 + 262280) + 56),
      7,
      1);
    (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v3 + 262280) + 56) + 88))(
      *(_DWORD *)(*(_DWORD *)(v3 + 262280) + 56),
      14,
      1);
    (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v3 + 262280) + 56) + 88))(
      *(_DWORD *)(*(_DWORD *)(v3 + 262280) + 56),
      23,
      2);
    (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v3 + 262280) + 56) + 88))(
      *(_DWORD *)(*(_DWORD *)(v3 + 262280) + 56),
      29,
      0);
    (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v3 + 262280) + 56) + 88))(
      *(_DWORD *)(*(_DWORD *)(v3 + 262280) + 56),
      41,
      0);
    (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v3 + 262280) + 56) + 88))(
      *(_DWORD *)(*(_DWORD *)(v3 + 262280) + 56),
      15,
      0);
    (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v3 + 262280) + 56) + 88))(
      *(_DWORD *)(*(_DWORD *)(v3 + 262280) + 56),
      22,
      1);
    (*(void (__stdcall **)(_DWORD, _DWORD, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v3 + 262280) + 56) + 160))(
      *(_DWORD *)(*(_DWORD *)(v3 + 262280) + 56),
      0,
      16,
      2);
    (*(void (__stdcall **)(_DWORD, _DWORD, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v3 + 262280) + 56) + 160))(
      *(_DWORD *)(*(_DWORD *)(v3 + 262280) + 56),
      0,
      17,
      2);
    (*(void (__stdcall **)(_DWORD, _DWORD, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v3 + 262280) + 56) + 160))(
      *(_DWORD *)(*(_DWORD *)(v3 + 262280) + 56),
      0,
      18,
      3);
    (*(void (__stdcall **)(_DWORD, _DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v3 + 262280) + 56) + 160))(
      *(_DWORD *)(*(_DWORD *)(v3 + 262280) + 56),
      0,
      5,
      2);
    (*(void (__stdcall **)(_DWORD, _DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v3 + 262280) + 56) + 160))(
      *(_DWORD *)(*(_DWORD *)(v3 + 262280) + 56),
      0,
      6,
      0);
    (*(void (__stdcall **)(_DWORD, _DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v3 + 262280) + 56) + 160))(
      *(_DWORD *)(*(_DWORD *)(v3 + 262280) + 56),
      0,
      4,
      2);
    (*(void (__stdcall **)(_DWORD, _DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v3 + 262280) + 56) + 160))(
      *(_DWORD *)(*(_DWORD *)(v3 + 262280) + 56),
      0,
      2,
      2);
    (*(void (__stdcall **)(_DWORD, _DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v3 + 262280) + 56) + 160))(
      *(_DWORD *)(*(_DWORD *)(v3 + 262280) + 56),
      0,
      3,
      0);
    (*(void (__stdcall **)(_DWORD, _DWORD, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v3 + 262280) + 56) + 160))(
      *(_DWORD *)(*(_DWORD *)(v3 + 262280) + 56),
      0,
      1,
      4);
  }
  else
  {
    Render_CreateDirectDraw(_this);
    Render_SetCooperativeLevel(_this, _this->hWnd, true);
    Render_SetDisplayMode(_this, 1280, 1024, 16);
    Render_CreatePrimarySurface(_this);
    v18 = 1;
  }
  _this->ddpfPrimarySurface.dwSize = sizeof(DDPIXELFORMAT);
  (_this->pdds4_FrontBuffer->lpVtbl->GetPixelFormat)(_this->pdds4_FrontBuffer, &_this->ddpfPrimarySurface);

  Render_sub_4A0EB6(_this);
  Render_sub_49EBF1(_this);
  if (_this->pRenderD3D3)
  {
    v19 = sub_49E756(*(void **)(v3 + 262284));
    v20 = *(_DWORD *)(v3 + 12) == v18;
    *(_DWORD *)(v3 + 262408) = v19;
    if ( !v20 )
      *(_DWORD *)(v3 + 262408) = 0;
    if ( *(_DWORD *)(v3 + 262408) )
    {
      memset(&v35, 0, 0x7Cu);
      v39 = *(_DWORD *)(v3 + 262364) | *(_DWORD *)(v3 + 262368);
      v40 = v39;
      v21 = *(_DWORD *)(v3 + 262284);
      v35 = 124;
      v36 = 65543;
      v41 = 2112;
      v38 = 640;
      v37 = 480;
      v22 = (*(int (__stdcall **)(int, int *, int, _DWORD))(*(_DWORD *)v21 + 24))(v21, &v35, v3 + 262296, 0);
      CheckHRESULT(&hwnd, v22, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 0x5CAu, 0);
      *(_DWORD *)(v3 + 1062592) = sub_4A57E9;
    }
    else
    {
      *(_DWORD *)(v3 + 262380) = 0;
      *(_DWORD *)(v3 + 262376) = 0;
      compile_error;//v23 = operator new(0x96020u);
      *(_DWORD *)(v3 + 262376) = v23;
      if ( !v23 || (memset(&v28, 0, 0x7Cu), v28 = 124, !LockSurface_DDraw4(pD3DRenderer->pdds4_BackBuffer, &v28, v18)) )
        return 0;
      (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)pD3DRenderer->pdds4_BackBuffer + 128))(pD3DRenderer->pdds4_BackBuffer, 0);
      v25 = *(_DWORD *)(v3 + 262376) + 16;
      v26 = v29 & 7;
      LOBYTE(v25) = v25 & 0xF8;
      *(_DWORD *)(v3 + 262384) = 640;
      *(_DWORD *)(v3 + 1062592) = sub_4A597D;
      v18 = 1;
      *(_DWORD *)(v3 + 262380) = v25 + 2 * v26;
    }
    *(_DWORD *)(v3 + 262416) = v18;
  }
  else _this->pfn_1036C0 = nullsub_1;


  _this->dword_040058 = 0;
  pParty_global->dword_007778 |= 2u;
  flt_6BE3A0 = 0.55f;
  Viewport_fn2(pOldViewport, 36044);
  return v18;
}

//----- (004A05F3) --------------------------------------------------------
int Render_InitWindowed(struct Render *_this, HWND hwnd)
{
  int v2; // esi@1
  int v7; // ecx@5
  signed int v8; // eax@7
  int v11; // eax@14
  int v12; // eax@18
  int v13; // eax@22
  int v14; // eax@24
  int v17; // eax@26
  int v20; // eax@35
  int v21; // eax@35
  int v23; // eax@38
  int v25; // ecx@38

  D3DDEVICEDESC d3ddd2;
  //int v28; // [sp+Ch] [bp-300h]@24

  DDSURFACEDESC2 ddsd2;
  //int v29; // [sp+108h] [bp-204h]@37
  //int v30; // [sp+12Ch] [bp-1E0h]@38

  D3DDEVICEDESC d3ddd1;
  /*int Dst; // [sp+184h] [bp-188h]@24
  unsigned int v32; // [sp+230h] [bp-DCh]@24
  unsigned int v33; // [sp+234h] [bp-D8h]@24
  unsigned int v34; // [sp+238h] [bp-D4h]@26
  unsigned int v35; // [sp+23Ch] [bp-D0h]@26*/

  int v36; // [sp+280h] [bp-8Ch]@35
  int v37; // [sp+284h] [bp-88h]@35
  int v38; // [sp+288h] [bp-84h]@35
  int v39; // [sp+28Ch] [bp-80h]@35
  int v40; // [sp+2C0h] [bp-4Ch]@35
  int v41; // [sp+2C4h] [bp-48h]@35
  int v42; // [sp+2E8h] [bp-24h]@35
  unsigned int v43; // [sp+2FCh] [bp-10h]@2
  int v44; // [sp+308h] [bp-4h]@2
 unsigned int uDeviceCaps;
 HRESULT      hr;

  pParty_global->dword_007778 |= 2;
  v2 = (int)_this;
  flt_6BE3A0 = 0.55000001;


 Viewport_fn2(pOldViewport, 36044);

 _this->dword_040108 = 0;
 _this->dword_040110 = 0;
 sub_49FE05(_this);

 _this->pdd4 = 0;
 _this->pdds4_FrontBuffer = 0;
 _this->pdds4_BackBuffer = 0;
 _this->dword_040098 = 0;

 Render_Initialize_ZBuffer(_this);

 if (_this->bUseDirect3D)
 {
  _this->pRenderD3D3 = malloc(sizeof(struct RenderD3D3));//v4 = (int)operator new(0x148u);
  v43 = _this->pRenderD3D3;
  v44 = 0;
  if (_this->pRenderD3D3)
    RenderD3D3_FindAvailableDevices(_this->pRenderD3D3);

    v44 = -1;
    v7 = _this->pRenderD3D3->pAvailableDevices;
    if (_this->pRenderD3D3->pAvailableDevices[_this->uDesiredDirect3DDevice].bDeviceIsValid &&
        _this->uDesiredDirect3DDevice != 1)
    {
     v8 = RenderD3D3_Initialize(_this->pRenderD3D3, _this->uDesiredDirect3DDevice, true, hwnd);
     _this->uAcquiredDirect3DDevice = _this->uDesiredDirect3DDevice;
    }
    else if (_this->pRenderD3D3->pAvailableDevices[0].bDeviceIsValid)
    {
      v8 = RenderD3D3_Initialize(_this->pRenderD3D3, 0, true, hwnd);
     _this->uAcquiredDirect3DDevice = 0;
    }
    else
      erroneous_printf("There aren't any D3D devices to init.");

    if (!v8)
      erroneous_printf("D3Drend->Init failed.");

    _this->pdd4 = _this->pRenderD3D3->pHostInterface;
    _this->pdds4_FrontBuffer = _this->pRenderD3D3->pFontBuffer;
    _this->pdds4_BackBuffer = _this->pRenderD3D3->pBackBuffer;
    _this->dword_040098 = 0;

    uDeviceCaps = RenderD3D3_GetDeviceCaps(_this->pRenderD3D3);
    if (uDeviceCaps & CAPS_NO_CAPS)
    {
      v43 = *(_DWORD *)(v2 + 262280);
      if ( v43 )
      {
        v11 = sub_49DC90(v43);
        operator_delete(v11, v43);
      }
      *(_DWORD *)(v2 + 262280) = 0;
      *(_DWORD *)(v2 + 262292) = 0;
      *(_DWORD *)(v2 + 262288) = 0;
      *(_DWORD *)(v2 + 262284) = 0;
      erroneous_printf("Direct3D renderer:  The device failed to return capabilities.");
    }
    if (uDeviceCaps & 0x3E)
    {
      v43 = *(_DWORD *)(v2 + 262280);
      if ( v43 )
      {
        v12 = sub_49DC90(v43);
        operator_delete(v12, v43);
      }
      *(_DWORD *)(v2 + 262296) = 0;
      *(_DWORD *)(v2 + 262280) = 0;
      *(_DWORD *)(v2 + 262292) = 0;
      *(_DWORD *)(v2 + 262288) = 0;
      *(_DWORD *)(v2 + 262284) = 0;
      erroneous_printf("Direct3D renderer:  The device doesn't support the necessary alpha blending modes.");
    }
    if ((_BYTE)uDeviceCaps < 0)
    {
      v43 = *(_DWORD *)(v2 + 262280);
      if ( v43 )
      {
        v13 = sub_49DC90(v43);
        operator_delete(v13, v43);
      }
      *(_DWORD *)(v2 + 262280) = 0;
      *(_DWORD *)(v2 + 262292) = 0;
      *(_DWORD *)(v2 + 262288) = 0;
      *(_DWORD *)(v2 + 262284) = 0;
      erroneous_printf("Direct3D renderer:  The device doesn't support non-square textures.");
    }

  _this->dword_10365C |= ~(unsigned __int8)((unsigned int)uDeviceCaps >> 6) & 1;
  _this->bRequiredTextureStagesAvailable = Render_ValidateTextureStages();

  memset(&d3ddd1, 0, sizeof(D3DDEVICEDESC));
  d3ddd1.dwSize = sizeof(D3DDEVICEDESC);

  memset(&d3ddd2, 0, sizeof(D3DDEVICEDESC));
  d3ddd2.dwSize = sizeof(D3DDEVICEDESC);

  hr = (_this->pRenderD3D3->pDevice->lpVtbl->GetCaps)(_this->pRenderD3D3->pDevice, &d3ddd1, &d3ddd2);
  CheckHRESULT(&v43, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 1704, 0);

  v14 = d3ddd1.dwMinTextureWidth;
  if (d3ddd1.dwMinTextureWidth >= d3ddd1.dwMinTextureHeight)
    v14 = d3ddd1.dwMinTextureHeight;
  _this->uMinDeviceTextureDim = v14;

  v17 = d3ddd1.dwMaxTextureWidth;
  if (d3ddd1.dwMaxTextureWidth < d3ddd1.dwMaxTextureHeight)
    v17 = d3ddd1.dwMaxTextureHeight;
  _this->uMaxDeviceTextureDim = v17;

  Render_sub_49FFD7(_this);
  (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice, 7, 1);
  (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice, 14, 1);
  (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice, 23, 2);
  (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice, 29, 0);
  (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice, 41, 0);
  (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice, 22, 1);

  (_this->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(_this->pRenderD3D3->pDevice, 0, 16, 2);
  (_this->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(_this->pRenderD3D3->pDevice, 0, 17, 2);
  (_this->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(_this->pRenderD3D3->pDevice, 0, 18, 3);
  (_this->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(_this->pRenderD3D3->pDevice, 0, 5, 2);
  (_this->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(_this->pRenderD3D3->pDevice, 0, 6, 0);
  (_this->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(_this->pRenderD3D3->pDevice, 0, 4, 2);
  (_this->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(_this->pRenderD3D3->pDevice, 0, 2, 2);
  (_this->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(_this->pRenderD3D3->pDevice, 0, 3, 0);
  (_this->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(_this->pRenderD3D3->pDevice, 0, 1, 4);
 }
  else
  {
    Render_CreateDirectDraw(_this);
    Render_SetCooperativeLevel(_this, hwnd, 0);
    *(_DWORD *)(v2 + 262220) = 1;
    Render_CreateSurface(_this);
    Render_CreateClipper(_this, hwnd);
    Render_CreateWndSurface(_this);
    *(_DWORD *)(v2 + 262192) = 0;
    *(_DWORD *)(v2 + 24) = 0;
  }

 _this->ddpfPrimarySurface.dwSize = sizeof(DDPIXELFORMAT);
 Render_GetPrimarySurfacePixelFormat(_this, &_this->ddpfPrimarySurface);
 Render_sub_4A0EB6(_this);
 Render_sub_49EBF1(_this);

 if (!_this->pRenderD3D3)
 {
  _this->pfn_1036C0 = nullsub_1;
  _this->dword_040058 = 1;
  _this->hWnd = hwnd;
  return 0;
 }

 _this->dword_040108 = sub_49E756(_this->pdd4);
 if (_this->uAcquiredDirect3DDevice != 1)
   _this->dword_040108 = 0;

 if (_this->dword_040108)
 {
    memset(&v36, 0, 0x7Cu);
    v40 = *(_DWORD *)(v2 + 262364) | *(_DWORD *)(v2 + 262368);
    v41 = v40;
    v20 = *(_DWORD *)(v2 + 262284);
    v36 = 124;
    v37 = 65543;
    v42 = 2112;
    v39 = 640;
    v38 = 480;
    v21 = (*(int (__stdcall **)(int, int *, int, _DWORD))(*(_DWORD *)v20 + 24))(v20, &v36, v2 + 262296, 0);
    CheckHRESULT(&v43, v21, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 1783, 0);
    *(_DWORD *)(v2 + 1062592) = sub_4A57E9;
    *(_DWORD *)(v2 + 262416) = 1;
    *(_DWORD *)(v2 + 262232) = 1;
    _this->hWnd = hwnd;
    return 0;
 }
 
 _this->pTargetSurface = 0;
 _this->ptr_0400E8 = malloc(640 * 480 * 4 + 32);
 if (_this->ptr_0400E8)
 {
  memset(&ddsd2, 0, sizeof(DDSURFACEDESC2));
  ddsd2.dwSize = sizeof(DDSURFACEDESC2);

  if (LockSurface_DDraw4(pD3DRenderer->pdds4_BackBuffer, &ddsd2, 1))
  {
   (pD3DRenderer->pdds4_BackBuffer->lpVtbl->Unlock)(pD3DRenderer->pdds4_BackBuffer, 0);

      v23 = (unsigned int)ddsd2.lpSurface & 7;
      v25 = _this->ptr_0400E8 & 7;
      if ( v25 == v23 )
        _this->pTargetSurface = _this->ptr_0400E8;
      else
      {
        if ( v25 >= v23 )
          _this->pTargetSurface = _this->ptr_0400E8 + 4 * (v25 - v23) + 16;
        else
          _this->pTargetSurface = _this->ptr_0400E8 + 4 * (v23 - v25) + 16;
      }
      _this->uTargetSurfacePitch = 640;
      _this->pfn_1036C0 = sub_4A597D;

      _this->dword_040110 = 1;
      _this->dword_040058 = 1;
      _this->hWnd = hwnd;
      return 0;
    }
 }
 return 0;
}

//----- (004A0E97) --------------------------------------------------------
void Render_sub_4A0E97(struct Render *_this, int a2, int a3, int a4, int a5)
{
 _this->dword_00001C = a2;
 _this->dword_000020 = a3;
 _this->dword_000024 = a4;
 _this->dword_000028 = a5;
}

//----- (MM7.exe::0049FDBF) --------------------------------------------------------
void Render_Initialize_ZBuffer(struct Render *_this)
{
 if (!_this->pDefaultZBuffer)
 {
  _this->pDefaultZBuffer = class23_AllocatedNamedBuffer(class23_instance, 0, 640 * 480 * 4, "ZBuffer");
  _this->pActiveZBuffer = _this->pDefaultZBuffer;
  memset(_this->pDefaultZBuffer, -65536, 640 * 480 * 4);
 }
}

//----- (MM7.exe::004A10E4) --------------------------------------------------------
int Render_CreateDirectDraw(struct Render *_this)
{
 HRESULT      hr;
 IDirectDraw *pdd;
 char         some_class[1024];

 hr = DirectDrawCreate(0, &pdd, 0);
 CheckHRESULT(some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2286, 0);

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
 {
  hr = (pdd->lpVtbl->QueryInterface)(pdd, &IID_IDirectDraw4, &_this->pdd4);
  CheckHRESULT(some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2296, 0);
 }
 else
 {
  hr = (pdd->lpVtbl->QueryInterface)(pdd, &IID_IDirectDraw2, &_this->pdd2);
  CheckHRESULT(some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2291, 0);
 }

 return (pdd->lpVtbl->Release)(pdd);
}

//----- (MM7.exe::004A1169) --------------------------------------------------------
void *Render_SetCooperativeLevel(struct Render *_this, HWND hWnd, int bFullscreen)
{
 IDirectDraw *pdd;
 HRESULT      hr;
 unsigned int flags;
 char         local_0[128];

 //flags = bFullscreen ? DDSCL_NORMAL | DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN : DDSCL_NORMAL;
 flags = bFullscreen ? DDSCL_NORMAL | DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN : DDSCL_NORMAL;
 if (dword_F79D7C != 2 || dword_F79D70 != 4)
 {
  pdd = _this->pdd4;
  flags |= DDSCL_MULTITHREADED;
 }
 else
 {
  __asm int 3;
  pdd = _this->pdd2;
 }

 hr = (pdd->lpVtbl->SetCooperativeLevel)(pdd, hWnd, flags);
 return CheckHRESULT(local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2320, 0);
}

//----- (MM7.exe::004A11C6) --------------------------------------------------------
void *Render_SetDisplayMode(struct Render *_this, unsigned int uWidth, unsigned int uHeight, unsigned int uBPP)
{
 IDirectDraw *pdd;
 HRESULT      hr;
 unsigned int some_class[128];
 int          v8;

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
 {
  pdd = _this->pdd4;
  v8 = 2331;
 }
 else
 {
  pdd = _this->pdd2;
  v8 = 2327;
 }

 hr = S_OK;//(pdd->lpVtbl->SetDisplayMode)(pdd, uWidth, uHeight, uBPP, 0, 0);
 return CheckHRESULT(some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", v8, 0);
}

//----- (M7.exe::004A139A) --------------------------------------------------------
void *Render_CreatePrimarySurface(struct Render *_this)
{
  HRESULT hr;
  void           *result; // eax@5
  DDSURFACEDESC2 ddsd2_PrimarySurface;
  DDSCAPS2       ddsCaps2_AttachedSurface;
  char some_class[128];

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
 {
  _this->dword_04004C = 1;
 
  memset(&ddsd2_PrimarySurface, 0, sizeof(DDSURFACEDESC2));
  ddsd2_PrimarySurface.dwSize = sizeof(DDSURFACEDESC2);
  ddsd2_PrimarySurface.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
  ddsd2_PrimarySurface.dwBackBufferCount = 1;
  //ddsd2_PrimarySurface.ddsCaps.dwCaps = DDSCAPS_COMPLEX | DDSCAPS_FLIP | DDSCAPS_3DDEVICE | DDSCAPS_PRIMARYSURFACE;
  ddsd2_PrimarySurface.ddsCaps.dwCaps = DDSCAPS_COMPLEX | DDSCAPS_FLIP | DDSCAPS_3DDEVICE | DDSCAPS_PRIMARYSURFACE;

  hr = (_this->pdd4->lpVtbl->CreateSurface)(_this->pdd4, &ddsd2_PrimarySurface, &_this->pdds4_FrontBuffer, 0);
  CheckHRESULT(some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2440, 0);
 }
 else
 {
  __asm int 3 //ddraw2 impl
 }

 memset(&ddsCaps2_AttachedSurface, 0, sizeof(DDSCAPS2));
 ddsCaps2_AttachedSurface.dwCaps = DDSCAPS_BACKBUFFER;

 hr = (_this->pdds4_FrontBuffer->lpVtbl->GetAttachedSurface)(_this->pdds4_FrontBuffer, &ddsCaps2_AttachedSurface, &pD3DRenderer->pdds4_BackBuffer);
 result = CheckHRESULT(some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2445, 0);

 _this->dword_040030 = 0;
 _this->dword_000018 = 0;
 return result;
}

//----- (MM7.exe::004A15D8) --------------------------------------------------------
HRESULT Render_GetPrimarySurfacePixelFormat(struct Render *_this, DDPIXELFORMAT *pddpf)
{
 IDirectDrawSurface *pdds;

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
   pdds = _this->pdds4_FrontBuffer;
 else
   pdds = _this->pdds2_FrontBuffer;

 return (pdds->lpVtbl->GetPixelFormat)(pdds, pddpf);
}

//----- (MM7.exe::004A5BB6) --------------------------------------------------------
void Render_Reset2DClippingRect(struct Render *_this)
{
 _this->uClipRectY = 0;
 _this->uClipRectX = 0;
 _this->uClipRectW = 480;
 _this->uClipRectZ = 640;
 _this->dword_040104 = 1;
}

//----- (004A0EB6) --------------------------------------------------------
void *Render_sub_4A0EB6(struct Render *_this)
{
  void *result; // eax@1
  int v2; // edx@1
  signed int v3; // ecx@1
  signed int v4; // ecx@5
  int v5; // esi@5
  int v6; // edx@9
  signed int v7; // ecx@9

  result = _this;
  v3 = 0;
  v2 = _this->ddpfPrimarySurface.dwRBitMask;

  _this->uNumTargetRBits = 0;
  _this->uNumTargetGBits = 0;
  _this->uNumTargetBBits = 0;

  do
  {
    if ((1 << v3) & v2)
      ++_this->uNumTargetRBits;
    ++v3;
  }
  while (v3 < 32);

  v5 = _this->ddpfPrimarySurface.dwGBitMask;
  v4 = 0;
  do
  {
    if ((1 << v4) & v5)
      ++_this->uNumTargetGBits;
    ++v4;
  }
  while (v4 < 32);

  v6 = _this->ddpfPrimarySurface.dwBBitMask;
  v7 = 0;
  do
  {
    if ((1 << v7) & v6)
      ++_this->uNumTargetBBits;
    ++v7;
  }
  while (v7 < 32);

  _this->uTargetRMask = _this->ddpfPrimarySurface.dwRBitMask;
  _this->uTargetGMask = v5;
  _this->uTargetBMask = v6;

  return result;
}

//----- (MM7.exe::0049EBF1) --------------------------------------------------------
int Render_sub_49EBF1(struct Render *_this)
{
  int result; // eax@1
  signed int v2; // edx@1
  signed int v3; // edi@1
  signed int v4; // esi@1
  int v5; // edx@4
  int v6; // edi@4
  int v7; // ebx@4
  int v8; // edx@4
  signed int v9; // [sp+8h] [bp-24h]@1
  signed int v10; // [sp+Ch] [bp-20h]@1
  signed int v11; // [sp+20h] [bp-Ch]@1
  signed int i; // [sp+24h] [bp-8h]@2
  signed int v13; // [sp+28h] [bp-4h]@3

  result = _this;
  v11 = 0;
  runtime_warning(hack: here we pretend that we are running 16 bit, otherwise thigs like palettes go crazy o_O);
  //v2 = 1 << _this->uNumTargetRBits;
  //v10 = 1 << _this->uNumTargetRBits;
  v2 = v10 = 1 << 5;
  //v3 = 1 << _this->uNumTargetGBits;
  //v9 = 1 << _this->uNumTargetGBits;
  v3 = v9 = 1 << 6;
  //v4 = 1 << _this->uNumTargetBBits;
  v4 = 1 << 5;
  if ( v2 > 0 )
  {
    do
    {
      for ( i = 0; i < v3; ++i )
      {
        v13 = 0;
        if ( v4 > 0 )
        {
          do
          {
            //v5 = _this->uNumTargetBBits;
           v5 = 5;
            //v6 = v5 + _this->uNumTargetGBits;
           v6 = v5 + 6;
            //v7 = (v13 >> 1) + (v11 >> 1 << v6) + (i >> 1 << _this->uNumTargetBBits);
           v7 = (v13 >> 1) + (v11 >> 1 << v6) + (i >> 1 << 5);
            v8 = (v11 << v6) + v13++ + (i << v5);
            _this->array_00002C[v8] = v7;
          }
          while ( v13 < v4 );
          v2 = v10;
          v3 = v9;
        }
      }
      ++v11;
    }
    while ( v11 < v2 );
  }
  return result;
}



//----- (MM7.exe::0049ED18) --------------------------------------------------------
int Render_ClearBackBufferAndPresent(struct Render *_this)
{
 IDirectDrawSurface *v1; // eax@3
 HRESULT hr;
 DDBLTFX ddblt;
 RECT    rcDst;

 rcDst.left = uWindowPosX;
 rcDst.top = uWindowPosY;
 rcDst.right = uWindowPosX + uWindowWidth;
 rcDst.bottom = uWindowPosY + uWindowHeight;

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
   v1 = pD3DRenderer->pdds4_BackBuffer;
 else
 {
  v1 = pD3DRenderer->pdds2_BackBuffer;
  __asm int 3
 }

 ddblt.dwSize = sizeof(DDBLTFX);
 ddblt.dwFillColor = 0x00000000;
 
 hr = (pD3DRenderer->pdds4_BackBuffer->lpVtbl->Blt)(pD3DRenderer->pdds4_BackBuffer, &rcDst, 0, 0, DDBLT_COLORFILL, &ddblt);
 return Render_Present(pD3DRenderer);
}

//----- (MM7.exe::0049FC37) --------------------------------------------------------
int Render_Present(struct Render *_this)
{
  struct tagRECT Rect; // [sp+8h] [bp-28h]@11
  struct tagRECT rc;
  struct tagPOINT Point; // [sp+28h] [bp-8h]@11


 if (pD3DRenderer->pRenderD3D3 && !_this->dword_040110)
   return false;

 (_this->pfn_1036C0)();

 if (_this->pRenderD3D3)
 {
  if (dword_720010)
    sub_46BAEC(dword_720010);
  RenderD3D3_Present(_this->pRenderD3D3, 0);
  if (dword_720010)
    sub_46BB0A(dword_720010);
 }
 else
 {
  rc.left = 0;
  rc.top = 0;
  rc.right = 640;
  rc.bottom = 480;

  Render_RestoreFrontBuffer(_this);
  if (_this->dword_040058)
  {
   GetClientRect(_this->hWnd, &Rect);
   Point.y = 0;
   Point.x = 0;
   ClientToScreen(_this->hWnd, &Point);
   OffsetRect(&Rect, Point.x, Point.y);
   Render_PresentRegion(_this, &Rect, &rc);
  }
  else Render_PresentBackBuffer(_this, 0, 0, &rc);
 }
 return true;
}

//----- (004A17C7) --------------------------------------------------------
void *Render_UnlockFrontBuffer(struct Render *_this)
{
 IDirectDrawSurface *v1;
 HRESULT             hr;
 char                local_0[128];

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
   v1 = _this->pdds4_FrontBuffer;
 else
 {
  __asm int 3;
  //v1 = _this->pdds2_FrontBuffer;
 }

 hr = (_this->pdds4_FrontBuffer->lpVtbl->Unlock)(_this->pdds4_FrontBuffer, 0);
 return CheckHRESULT(local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2615, 0);
}

//----- (MM7.exe::004A194A) --------------------------------------------------------
HRESULT Render_PresentBackBuffer(struct Render *_this, int a2, int a3, RECT *pRect)
{
 IDirectDrawSurface *v4,
                    *v6;

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
 {
  v4 = _this->pdds4_FrontBuffer;
  v6 = _this->pdds4_BackBuffer;
 }
 else
 {
  v4 = _this->pdds2_FrontBuffer;
  v6 = _this->pdds2_BackBuffer;
  __asm int 3
 }

 return (_this->pdds4_FrontBuffer->lpVtbl->BltFast)(_this->pdds4_FrontBuffer, 0, 0, _this->pdds4_BackBuffer, pRect, DDBLTFAST_WAIT);
}

//----- (MM7.exe::004A1814) --------------------------------------------------------
HRESULT Render_RestoreFrontBuffer(struct Render *_this)
{
 IDirectDrawSurface *v1;
 HRESULT             hr;


 if ( dword_F79D7C != 2 || dword_F79D70 != 4)
   v1 = _this->pdds4_FrontBuffer;
 else
 {
  v1 = _this->pdds2_FrontBuffer;
  __asm int 3;
 }

 hr = (_this->pdds4_FrontBuffer->lpVtbl->IsLost)(_this->pdds4_FrontBuffer);
 if ( hr == DDERR_SURFACELOST )
    hr = (_this->pdds4_FrontBuffer->lpVtbl->Restore)(_this->pdds4_FrontBuffer);
 return hr;
}

//----- (MM7.exe::0044F2B2) --------------------------------------------------------
int CheckIfDeviceSupportsGammaControl()
{
 HRESULT    hr;
 DDCAPS_DX7 ddCaps;
 char       some_class[128];

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
 {
  memset(&ddCaps, 0, sizeof(DDCAPS_DX7));
  ddCaps.dwSize = sizeof(DDCAPS_DX7);

  hr = (pD3DRenderer->pdd4->lpVtbl->GetCaps)(pD3DRenderer->pdd4, &ddCaps, 0);
  CheckHRESULT(some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\GammaControl.cpp", 71, 0);
  return ddCaps.dwCaps2 & DDCAPS2_PRIMARYGAMMA;
 }
 else return false;
}















//----- (MM7.exe::0044F215) --------------------------------------------------------
struct CGammaController *CGammaController_ctor(struct CGammaController *_this)
{
 _this->dword_000000 = 5080696;
 _this->pddgc = 0;
 _this->flt_000C0C = *(float *)&byte_4D8410[608];
 return _this;
}

//----- (MM7.exe::0044F4D9) --------------------------------------------------------
void *sub_44F4D9(struct CGammaController *_this, float a2)
{
  double v3; // st7@3
  double v4; // st6@4
  void *result; // eax@10

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
 {
  CGammaController_InitializeFromSurface(_this, pD3DRenderer->pdds4_FrontBuffer);
  v3 = 2.799999952316284;
  if ( a2 <= 2.799999952316284 )
    v4 = a2;
  else
    v4 = 2.799999952316284;
  if ( v4 >= 0.1000000014901161 )
  {
   if ( a2 <= 2.799999952316284 )
   v3 = a2;
  }
  else
    v3 = 0.1000000014901161;

  _this->flt_000C0C = v3;
  sub_44F45B(_this, &_this->ddGammaRamp2);
  result = sub_44F408(_this, &_this->ddGammaRamp2);
 }
 return result;
}

//----- (MM7.exe::0044F24B) --------------------------------------------------------
void CGammaController_InitializeFromSurface(struct CGammaController *_this, struct IDirectDrawSurface4 *pdds)
{
 _this->pdds4 = pdds;
 if (_this->pddgc)
 {
  (_this->pddgc->lpVtbl->Release)(_this->pddgc);
  _this->pddgc = 0;
 }
 if (CheckIfDeviceSupportsGammaControl())
 {
  (pdds->lpVtbl->QueryInterface)(pdds, &IID_IDirectDrawGammaControl, &_this->pddgc);
  CGammaController_InitializeGammaRamp(_this);
  memcpy(&_this->ddGammaRamp2, &_this->ddGammaRamp, sizeof(DDGAMMARAMP));
  _this->flt_000C0C = sub_44F377(&_this->ddGammaRamp2);
 }
}

//----- (MM7.exe::0044F324) --------------------------------------------------------
void *CGammaController_InitializeGammaRamp(struct CGammaController *_this)
{
 HRESULT hr;
  void *result; // eax@2
  int v12; // [sp+7h] [bp-1h]@2
 char some_class[128];

 if (_this->pddgc)
 {
  hr = (_this->pddgc->lpVtbl->GetGammaRamp)(_this->pddgc, 0, &_this->ddGammaRamp);
  result = CheckHRESULT(some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\GammaControl.cpp", 87, 0);
 }
 else
 {
   sub_40E2C8(&hr, "Gamma control not active", (int)&v12);
   result = sub_467834(some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\GammaControl.cpp", 0, 0, 83, 0);
 }
 return result;
}


//----- (MM7.exe::0044F377) --------------------------------------------------------
double __stdcall sub_44F377(DDGAMMARAMP *pddGammaRamp)
{
  double v2; // st7@1
  double v3; // st6@2
  double result; // st7@7
  signed int v5; // [sp+0h] [bp-8h]@1
  int i;

 v2 = 0.0;
 v5 = 256;
 for (i = 0; i < 256; ++i)
 {
  v3 = (pddGammaRamp->red[i] + pddGammaRamp->green[i] + pddGammaRamp->blue[i]) * 0.00001525902189314365 * 0.3333333432674408;
  if (fabsf(v3) < 1e-5)
    --v5;
  else
    v2 += (double)i * 0.003921568859368563 / v3;
 }

 if ( v5 )
   result = v2 / (double)v5;
 else result = 1.0;
 return result;
}

//----- (004A18F5) --------------------------------------------------------
void *__stdcall BltToFrontBuffer(RECT *pDestRect, IDirectDrawSurface *pddsSrc, RECT *pSrcRect, unsigned int uFlags)
{
 IDirectDrawSurface *v4;
 HRESULT             hr;
 char                local_0[128];

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
   v4 = pD3DRenderer->pdds4_FrontBuffer;
 else
 {
  __asm int 3; //ddraw2
  v4 = pD3DRenderer->pdds2_FrontBuffer;
 }

 hr = (pD3DRenderer->pdds4_FrontBuffer->lpVtbl->Blt)(pD3DRenderer->pdds4_FrontBuffer, pDestRect, pddsSrc, pSrcRect, uFlags, 0);
 return CheckHRESULT(local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2669, 0);
}

//----- (004A0F40) --------------------------------------------------------
bool __stdcall LockSurface_DDraw4(struct IDirectDrawSurface4 *pdds4, DDSURFACEDESC2 *pddsd2, unsigned int uLockFlags)
{
 char    local_0[128];
 HRESULT hr;

 hr = (pdds4->lpVtbl->Lock)(pdds4, 0, pddsd2, uLockFlags, 0);
 if (hr == DDERR_SURFACELOST)
 {
  if (dword_720010)
    Mouse_suspend(dword_720010);

  hr = (pdds4->lpVtbl->Restore)(pdds4);
  if (FAILED(hr))
  {
   if (hr != -2005532084)
   {
    pddsd2->dwSize = 0;
    return false;
   }

   (pD3DRenderer->pdds4_FrontBuffer->lpVtbl->Restore)(pD3DRenderer->pdds4_FrontBuffer);
   (pdds4->lpVtbl->Restore)(pdds4);
  }

  hr = (pdds4->lpVtbl->Lock)(pdds4, 0, pddsd2, DDLOCK_WAIT, 0);
  if (hr == DDERR_SURFACELOST || hr == DDERR_SURFACEBUSY)
  {
   pddsd2->dwSize = 0;
   return false;
  }
  else if (FAILED(hr))
  {
   CheckHRESULT(local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2161, 0);
   pddsd2->dwSize = 0;
   return false;
  }

  if (pD3DRenderer->pRenderD3D3)
    sub_4A5190();
  (pD3DRenderer->pdd4->lpVtbl->RestoreAllSurfaces)(pD3DRenderer->pdd4);
  if (dword_720010)
    sub_46B105(dword_720010);
 }
 else if (FAILED(hr))
 {
  if (hr == DDERR_SURFACEBUSY)
  {
   pddsd2->dwSize = 0;
   return false;
  }

  CheckHRESULT(local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2199, 0);
  pddsd2->dwSize = 0;
 }

 return true;
}

//----- (004A1032) --------------------------------------------------------
int __stdcall LockSurface_DDraw2(struct IDirectDrawSurface2 *a1, DDSURFACEDESC *Dst, unsigned int a3)
{
  int v3; // eax@1
  int v4; // esi@1
  int v5; // eax@2
  unsigned int v7; // [sp-8h] [bp-10h]@8
  int v8; // [sp-4h] [bp-Ch]@8

  v4 = a1;
  v3 = (*(int (__stdcall **)(int, _DWORD, void *, int, _DWORD))(*(_DWORD *)a1 + 100))(a1, 0, Dst, a3, 0);
  BYTE3(a1) = 1;
  if ( v3 == -2005532222 )
  {
    v5 = (*(int (__stdcall **)(int))(*(_DWORD *)v4 + 108))(v4);
    if ( v5 )
    {
      if ( v5 != -2005532084 )
      {
LABEL_14:
        BYTE3(a1) = 0;
        memset(Dst, 0, 4u);
        return BYTE3(a1);
      }
      (*(void (__stdcall **)(int))(*(_DWORD *)pD3DRenderer->pdds2_FrontBuffer + 108))(pD3DRenderer->pdds2_FrontBuffer);
      (*(void (__stdcall **)(int))(*(_DWORD *)v4 + 108))(v4);
    }
    v3 = (*(int (__stdcall **)(int, _DWORD, void *, signed int, _DWORD))(*(_DWORD *)v4 + 100))(v4, 0, Dst, 1, 0) != 0;
    if ( v3 == -2005532522 || v3 == -2005532242 )
      goto LABEL_14;
    if ( v3 )
    {
      v8 = 0;
      v7 = 2247;
LABEL_13:
      CheckHRESULT(&a1, v3, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", v7, v8);
      goto LABEL_14;
    }
  }
  else
  {
    if ( v3 )
    {
      if ( v3 == -2005532522 || v3 == -2005532242 )
        goto LABEL_14;
      v8 = 0;
      v7 = 2269;
      goto LABEL_13;
    }
  }
  return BYTE3(a1);
}












int RGBTexture_Load_New(struct RGBTexture *_this, const wchar_t *pTextureName)
{
 unsigned int uTextureID;

 uTextureID = LODFile_LoadTexture_New(pLODFile_Icons_LOD, pTextureName);

 _this->pPixels = pLODFile_Icons_LOD->aLODHeaders[uTextureID].pTruecolorPixels;
 _this->uWidth = pLODFile_Icons_LOD->aLODHeaders[uTextureID].uTextureWidth;
 _this->uHeight = pLODFile_Icons_LOD->aLODHeaders[uTextureID].uTextureHeight;
 _this->uNumPixels = _this->uWidth * _this->uHeight;

 return 0;
}

//----- (MM7.exe::0040F414) --------------------------------------------------------
int RGBTexture_Load(struct RGBTexture *_this, const char *pContainerName, int a3)
{
  void *v6; // ebx@5
  int v8; // eax@9
  int v9; // ecx@9
  void *v11; // eax@13

  void *pPCXData;

  //v16
  char local_1[48]; // [sp+Ch] [bp-98h]@7

  struct class18 class18_obj;
  //char DstBuf[48]; // [sp+3Ch] [bp-68h]@1
  //size_t v18; // [sp+50h] [bp-54h]@4
  //size_t Size; // [sp+64h] [bp-40h]@4

  char local_2[24];  //v21 == local_2 + 3
  //char Dst; // [sp+84h] [bp-20h]@7
  //char v21; // [sp+87h] [bp-1Dh]@7
  //int v22; // [sp+88h] [bp-1Ch]@9
  //int v23; // [sp+8Ch] [bp-18h]@9
  //char v24; // [sp+94h] [bp-10h]@7
  FILE *f; // [sp+9Ch] [bp-8h]@1

 wchar_t      pFilepath[256];
 unsigned int uTextureID;

 wsprintfW(pFilepath, L"%S", pContainerName);

 return RGBTexture_Load_New(_this, pFilepath);
}

//----- (MM7.exe::0040F037) --------------------------------------------------------
int RGBTexture_DecodePCX(struct RGBTexture *_this, unsigned char *pPCXData, unsigned short *pOutBuffer, unsigned int uWidth)
{
  void *v4; // esi@1
  signed int result; // eax@2
  int v6; // eax@3
  int v7; // edx@3
  signed int v8; // ecx@3
  int v9; // ecx@3
  signed int v10; // ecx@8
  signed int v11; // ebx@37
  unsigned short *v12; // eax@40
  int v13; // edi@40
  int v14; // ebx@41
  unsigned __int8 v15; // bl@42
  unsigned short *v17; // eax@50
  int v18; // ebx@51
  unsigned __int8 v19; // bl@52
  unsigned short *v21; // eax@61
  unsigned __int8 v22; // dl@62
  unsigned __int8 v23; // dl@63
  unsigned __int8 v24; // cl@63

  char local_1[48];
  char v26; // [sp+8h] [bp-54h]@1

  char local_2[24];
  char Dst; // [sp+38h] [bp-24h]@1
  //char v28; // [sp+3Bh] [bp-21h]@1
  //int v29; // [sp+3Ch] [bp-20h]@3
  //int v30; // [sp+40h] [bp-1Ch]@3
  //char v31; // [sp+48h] [bp-14h]@1
  //char v32; // [sp+49h] [bp-13h]@37
  //unsigned __int16 v33; // [sp+4Ah] [bp-12h]@40

  int v34; // [sp+50h] [bp-Ch]@43
  int v35; // [sp+54h] [bp-8h]@38
  unsigned short *v36; // [sp+58h] [bp-4h]@3
  int v37; // [sp+68h] [bp+Ch]@41
  int v38; // [sp+68h] [bp+Ch]@51
  unsigned __int8 v39; // [sp+6Bh] [bp+Fh]@63

  v4 = _this;
 memcpy(local_2, pPCXData, 0x10u);
 memcpy(local_1, (char *)pPCXData + 16, 0x30u);
 memcpy(local_2 + 16, (char *)pPCXData + 64, 6u);

 if (local_2[3] != 8 )
   return 3;

 v6 = *(int *)(local_2 + 8) - *(int *)(local_2 + 4) + 1;
 v9 = *(int *)(local_2 + 10) - *(int *)(local_2 + 6) + 1;

 _this->uWidth = v6 & 0xFFFF;
 _this->uHeight = v9 & 0xFFFF;

 v9 = (signed __int16)v9;
 v36 = v9;

 _this->uNumPixels = (signed __int16)v9 * (signed __int16)v6;

 HIWORD(v7) = 0;
 v8 = 1;
 while (1 << v8 != (signed __int16)v6)
 {
  ++v8;
  if (v8 >= 15)
    goto LABEL_8;
 }
 _this->word_000018 = v8;

LABEL_8:
 v10 = 1;
 while ( 1 << v10 != v36 )
 {
  ++v10;
  if ( v10 >= 15 )
    goto LABEL_13;
 }
 _this->word_00001A = v10;

LABEL_13:
 switch (_this->word_000018)
 {
  case 2:  _this->word_00001C = 3;    break;
  case 3:  _this->word_00001C = 7;    break;
  case 4:  _this->word_00001C = 15;   break;
  case 5:  _this->word_00001C = 31;   break;
  case 6:  _this->word_00001C = 63;   break;
  case 7:  _this->word_00001C = 127;  break;
  case 8:  _this->word_00001C = 255;  break;
  case 9:  _this->word_00001C = 511;  break;
  case 10: _this->word_00001C = 1023; break;
  case 11: _this->word_00001C = 2047; break;
  case 12: _this->word_00001C = 4095; break;
 }

 switch (_this->word_00001A)
 {
  case 2:  _this->word_00001E = 3;    break;
  case 3:  _this->word_00001E = 7;    break;
  case 4:  _this->word_00001E = 15;   break;
  case 5:  _this->word_00001E = 31;   break;
  case 6:  _this->word_00001E = 63;   break;
  case 7:  _this->word_00001E = 127;  break;
  case 8:  _this->word_00001E = 255;  break;
  case 9:  _this->word_00001E = 511;  break;
  case 10: _this->word_00001E = 1023; break;
  case 11: _this->word_00001E = 2047; break;
  case 12: _this->word_00001E = 4095; break;
 }

 v11 = 128;
 if (local_2[17] == 3)
 {
  v35 = 0;
  if ( v36 > 0 )
  {
   v36 = pOutBuffer;
   do
   {
    v12 = v36;
    v13 = 0;
    if (*(short *)(local_2 + 18))
    {
     do
     {
      LOBYTE(v7) = *(pPCXData + v11);
      v14 = v11 + 1;
      v37 = v14;
      if ((v7 & 0xC0) == -64)
      {
       ++v37;
       v15 = *(pPCXData + v14);
       if ((v7 & 0x3F) > 0)
       {
        v34 = v7 & 0x3F;
        do
        {
         ++v13;
         *v12++ = pD3DRenderer->uTargetRMask & (v15 << (pD3DRenderer->uNumTargetGBits + (_BYTE)pD3DRenderer->uNumTargetRBits + (_BYTE)pD3DRenderer->uNumTargetBBits - 8));
         if (v13 == *(short *)(local_2 + 18))
           v12 += (uWidth - *(short *)(local_2 + 18)) - 1;
        }
        while (v34-- != 1);
       }
      }
      else
      {
       v7 &= 0xFFFF00FF;
       v7 = pD3DRenderer->uTargetRMask & (v7 << (pD3DRenderer->uNumTargetGBits + (_BYTE)pD3DRenderer->uNumTargetRBits + (_BYTE)pD3DRenderer->uNumTargetBBits - 8));
       ++v13;
       *v12++ = v7;
      }
      v11 = v37;
     }
     while (v13 < *(short *)(local_2 + 18));
    }

    v17 = v36;
    while (v13 < 2 * *(short *)(local_2 + 18))
    {
     LOBYTE(v7) = *(pPCXData + v11);
     v18 = v11 + 1;
     v38 = v18;
     if ((v7 & 0xC0) == -64)
     {
      ++v38;
      v19 = *(pPCXData + v18);
      if ((v7 & 0x3F) > 0)
      {
       v34 = v7 & 0x3F;
       do
       {
        *v17++ |= (_WORD)pD3DRenderer->uTargetGMask & (unsigned __int16)(v19 << (pD3DRenderer->uNumTargetGBits
                                                                                  + (_BYTE)pD3DRenderer->uNumTargetBBits
                                                                                  - 8));
        ++v13;
        if (v13 == *(short *)(local_2 + 18))
          v17 += (uWidth - *(short *)(local_2 + 18)) - 1;
       }
       while (v34-- != 1);
      }
     }
     else
     {
      v7 &= 0xFFFF00FF;
      v7 = pD3DRenderer->uTargetGMask & (v7 << (pD3DRenderer->uNumTargetGBits + (_BYTE)pD3DRenderer->uNumTargetBBits - 8));
      *v17++ |= v7;
      ++v13;
     }
     v11 = v38;
    }

    v21 = v36;
    while (v13 < 3 * *(short *)(local_2 + 18))
    {
     v22 = *(pPCXData + v11++);
     if ((v22 & 0xC0) == -64)
     {
      v23 = v22 & 0x3F;
      v24 = *(pPCXData + v11++);
      v39 = v24;
      if ((signed int)v23 > 0)
      {
       v34 = v23;
       do
       {
        *v21++ |= v39 >> (8 - pD3DRenderer->uNumTargetBBits);
        ++v13;
        if (v13 == *(short *)(local_2 + 18))
        {
         v7 = uWidth - *(short *)(local_2 + 18);
         v21 += (uWidth - *(short *)(local_2 + 18)) - 1;
        }
       }
       while (v34-- != 1);
      }
     }
     else
     {
      *v21++ |= v22 >> (8 - pD3DRenderer->uNumTargetBBits);
      ++v13;
     }
    }
    ++v35;
    v36 += uWidth;
   }
   while (v35 < _this->uHeight);
  }
 }
 result = 0;

 return result;
}

//----- (0040D73D) --------------------------------------------------------
int RGBTexture_ctor(struct RGBTexture *_this)
{
 _this->dword_000000 = 0;

 _this->uNumPixels = 0;
 _this->word_000020 = 0;
 _this->word_000022 = 0;
 _this->pPixels = 0;
 return _this;
}


//----- (004A0E80) --------------------------------------------------------
void Render_ClearZBuffer(struct Render *_this, int a2, int a3)
{
  memset(_this->pActiveZBuffer, -65536, 640 * 480 * 4);
}




//----- (004A1EB6) --------------------------------------------------------
void Render_BeginSceneD3D3(struct Render *_this)
{
  int result; // eax@1
  int v2; // esi@1
  unsigned int v4; // edi@6
  int v9; // edi@11
  char v10; // [sp-14h] [bp-2Ch]@4
  int v11; // [sp-10h] [bp-28h]@4
  int v12; // [sp-Ch] [bp-24h]@4
  char *v16; // [sp+10h] [bp-8h]@4
  int v17; // [sp+17h] [bp-1h]@4

  v2 = _this;
  result = _this->uD3D3SceneBegun++;
  if ( !result )
  {
    if (_this->pRenderD3D3)
    {
      RenderD3D3_ClearTarget(_this->pRenderD3D3, 1, result, 1, 1.0);
      _this->dword_129830 = 0;
      (_this->pRenderD3D3->pDevice->lpVtbl->BeginScene)(_this->pRenderD3D3->pDevice);

      if ( dword_6BE360 == 2 )
        v4 = sub_47C370();
      else
        v4 = 0;
      if ( v4 & 0xFF000000 )
      {
        (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice, 28, 1);
        (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice, 34, v4 & 0xFFFFFF);
        (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice, 35, 0);
        _this->bUsingSpecular = true;
      }
      else
      {
        (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice, 28, 0);
        _this->bUsingSpecular = false;
      }
    }
    else
    {
      Render_LockBackBuffer(_this, &_this->pTargetSurface, &_this->uTargetSurfacePitch);
      if (_this->pTargetSurface)
      {
        _this->dword_000018 = _this->uTargetSurfacePitch;
      }
      else
      {
        --_this->uD3D3SceneBegun;
      }
    }
  }
}



//----- (004A1FE1) --------------------------------------------------------
void RenderD3D3_DrawBillboards_And_MaybeRenderSpecialEffects_And_EndScene(struct Render *_this)
{
 if (_this->uD3D3SceneBegun-- == 1)
 {
    if (_this->pRenderD3D3)
    {
      sub_44EE7C();
      D3D_DoRenderBillboards();
      class06_sub_4A8C27(pGame->class06_obj);
      (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->EndScene)(pD3DRenderer->pRenderD3D3->pDevice);
    }
    else
      class06_sub_4A8C27(pGame->class06_obj);
 }
}

//----- (004A121C) --------------------------------------------------------
void *Render_CreateSurface(struct Render *_this)
{
 char    local_0[128];
 HRESULT hr; 
 DDSURFACEDESC2 dd;

 memset(&dd, 0, sizeof(DDSURFACEDESC2));
 dd.dwSize = sizeof(DDSURFACEDESC2);
 dd.dwFlags = DDSD_CAPS;
 dd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;

 hr = _this->pdd4->lpVtbl->CreateSurface(pD3DRenderer->pdd4, &dd, &pD3DRenderer->pdds4_FrontBuffer, 0);
 return CheckHRESULT(local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2357, 0);
}

//----- (004A12CD) --------------------------------------------------------
void *Render_CreateWndSurface(struct Render *_this)
{
 char    local_0[128];
 HRESULT hr; 
 DDSURFACEDESC2 dd;

 memset(&dd, 0, sizeof(DDSURFACEDESC2));
 dd.dwSize = sizeof(DDSURFACEDESC2);
 dd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
 dd.dwWidth = 640;
 dd.dwHeight = 480;
 dd.ddsCaps.dwCaps = DDSCAPS_SYSTEMMEMORY | DDSCAPS_OFFSCREENPLAIN;

 hr = _this->pdd4->lpVtbl->CreateSurface(pD3DRenderer->pdd4, &dd, &pD3DRenderer->pdds4_BackBuffer, 0);
 return CheckHRESULT(local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2357, 0);
}

//----- (004A14F4) --------------------------------------------------------
extern IDirectDrawClipper *pDDrawClipper;
void *Render_CreateClipper(struct Render *_this, HWND hClipWnd)
{
 char    local_0[128];
 HRESULT hr; 

 hr = _this->pdd4->lpVtbl->CreateClipper(pD3DRenderer->pdd4, NULL, &pDDrawClipper, NULL);
 CheckHRESULT(&local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2463, 0);

 hr = pDDrawClipper->lpVtbl->SetHWnd(pDDrawClipper, 0, hClipWnd);
 CheckHRESULT(&local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2464, 0);

 hr = _this->pdds4_FrontBuffer->lpVtbl->SetClipper(pD3DRenderer->pdds4_FrontBuffer, pDDrawClipper);
 return CheckHRESULT(&local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2465, 0);
}

//----- (004A1884) --------------------------------------------------------
void *Render_PresentRegion(struct Render *_this, RECT *pDestRect, RECT *pSrcRect)
{
 HRESULT hr;
 char    local_0[128];

  hr = (pD3DRenderer->pdds4_FrontBuffer->lpVtbl->Blt)(pD3DRenderer->pdds4_FrontBuffer, pDestRect, pD3DRenderer->pdds4_BackBuffer, pSrcRect, DDBLT_WAIT, 0);
  return CheckHRESULT(local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", __LINE__, 0);
}



bool __stdcall DDrawEnumDisplayModesCallback(DDSURFACEDESC2 *pDDSurfaceDesc, unsigned short *a2)
{
 if (*(_DWORD *)((char *)pDDSurfaceDesc + 0x68) | 0x2000 && *(_DWORD *)((char *)pDDSurfaceDesc + 84) == 16 )
 {
  a2 = 1;
    return 0;
 }
 else
   return 1;
}

//----- (0049D9BC) --------------------------------------------------------
bool __stdcall DDrawEnumCallback(GUID *pGUID, const char *pDriverDescription, const char *pDriverName, struct RenderD3D3_DeviceDescription *a4)
{

  size_t v4; // eax@1
  size_t v5; // eax@1
  size_t v13; // eax@13
  int v18; // eax@24
  int v19; // eax@24
  DDDEVICEIDENTIFIER ddDeviceId;
  char v22; // [sp+204h] [bp-2F8h]@13
  struct
  {
   int v23; // [sp+42Ch] [bp-D0h]@16
   int v24; // [sp+430h] [bp-CCh]@16
   int v25; // [sp+434h] [bp-C8h]@16
   int v26; // [sp+438h] [bp-C4h]@16
   int a_43C[14];
   int v27; // [sp+474h] [bp-88h]@16
   int a_478[12];
  } local_42C;

  DDSCAPS2 ddsCaps2;
  struct
  {
   unsigned char *v30;
   char *v31; // [sp+4C0h] [bp-3Ch]@19
  } local_4BC;

   short v33; // [sp+4C8h] [bp-34h]@16
   
  struct
  {
   char v34[4]; // [sp+4CCh] [bp-30h]@19
   int dword_4D0;
   int dword_4D4;
   int dword_4D8;
   int dword_4DC;

   char *Dest; // [sp+4E0h] [bp-1Ch]@1
   char *v36; // [sp+4E4h] [bp-18h]@1
   char *v37; // [sp+4E8h] [bp-14h]@12
   GUID *lpGUID; // [sp+4ECh] [bp-10h]@2
  } local_4CC;
  

 IDirectDraw  *pDirectDraw;
 IDirectDraw4 *pDirectDraw4;
 IDirect3D3   *pDirect3D3;
 HRESULT       hr;
 unsigned int  uTotalVideoMem,
               uFreeVideoMem;

 memset(&local_4CC, 0, 36);

 v4 = strlen(pDriverName);
 local_4CC.Dest = malloc(v4 + 1);//Dest = (char *)operator new(v4 + 1);
 strcpy(local_4CC.Dest, pDriverName);

 v5 = strlen(pDriverDescription);
 local_4CC.v36 = malloc(v5 + 1);//v36 = (char *)operator new(v5 + 1);
 strcpy(local_4CC.v36, pDriverDescription);

 if (pGUID)
 {
  local_4CC.lpGUID = malloc(sizeof(GUID));//lpGUID = (GUID *)operator new(0x10u);
  memcpy(local_4CC.lpGUID, pGUID, sizeof(GUID));
 }
 else
   local_4CC.lpGUID = 0;

 hr = DirectDrawCreate(pGUID, &pDirectDraw, 0);
 if (FAILED(hr))
 {
  operator_delete(0, local_4CC.Dest);
  operator_delete(0, local_4CC.v36);
  if (local_4CC.lpGUID)
    operator_delete(0, local_4CC.lpGUID);
 }

 hr = (pDirectDraw->lpVtbl->QueryInterface)(pDirectDraw, &IID_IDirectDraw4, &pDirectDraw4);
 if (FAILED(hr))
 {
  operator_delete(0, local_4CC.Dest);
  operator_delete(0, local_4CC.v36);
  if (local_4CC.lpGUID)
    operator_delete(0, local_4CC.lpGUID);

  (pDirectDraw->lpVtbl->Release)(pDirectDraw);
  return 1;
 }

 (pDirectDraw->lpVtbl->Release)(pDirectDraw);

 hr = (pDirectDraw4->lpVtbl->GetDeviceIdentifier)(pDirectDraw4, &ddDeviceId, DDGDI_GETHOSTIDENTIFIER);
 if (FAILED(hr))
   local_4CC.v37 = 0;
 else
 {
  v13 = strlen(ddDeviceId.szDescription);
  local_4CC.v37 = malloc(v13 + 1);//v37 = (char *)operator new(v13 + 1);
  strcpy(local_4CC.v37, ddDeviceId.szDescription);
 }
 
 memset(&ddsCaps2, 0, sizeof(DDSCAPS2));
 //hr = (pDirectDraw4->lpVtvl->GetAvailableVidMem)(pDirectDraw4, &ddsCaps2, &uTotalVideoMem, &uFreeVideoMem);
 if (FAILED(hr))
   uTotalVideoMem = 0;

 memset(&local_42C, 0, 0x7Cu);
      local_42C.v23 = 124;
      local_42C.v24 = 6;
      local_42C.v25 = 640;
      local_42C.v26 = 480;
      local_42C.v27 = 32;
      v33 = 0;

 hr = (pDirectDraw4->lpVtbl->EnumDisplayModes)(pDirectDraw4, 0, 0, &v33, DDrawEnumDisplayModesCallback);
 (pDirectDraw4->lpVtbl->QueryInterface)(pDirectDraw4, &memory_4D8410.IID_IDirect3D3, &pDirect3D3);
 //if (FAILED(hr) || !v33 || !pDirect3D3)
 if (FAILED(hr) || !pDirect3D3)
 {
  operator_delete(0, local_4CC.Dest);
  operator_delete(0, local_4CC.v36);
  if (local_4CC.v37)
    operator_delete(0, local_4CC.v37);
  if (local_4CC.lpGUID)
    operator_delete(0, local_4CC.lpGUID);

  (pDirectDraw4->lpVtbl->Release)(pDirectDraw4);
  return 1;
 }

 local_4BC.v30 = a4;
 local_4BC.v31 = &local_4CC;
 hr = (pDirect3D3->lpVtbl->EnumDevices)(pDirect3D3, Direct3D3EnumDevicesCallback, &local_4BC);

 operator_delete(0, local_4CC.Dest);
 operator_delete(0, local_4CC.v36);
 if (local_4CC.v37)
   operator_delete(0, local_4CC.v37);
 if (local_4CC.lpGUID)
   operator_delete(0, local_4CC.lpGUID);

 (pDirectDraw4->lpVtbl->Release)(pDirectDraw4);
 (pDirect3D3->lpVtbl->Release)(pDirect3D3);


 return 1;
}



//----- (0049E79F) --------------------------------------------------------
bool Render_ValidateTextureStages()
{
  signed int v0; // edi@1
 IDirectDrawSurface4 *pTexture1Surface;
 IDirectDrawSurface4 *pTexture2Surface;
  int v4; // [sp+14h] [bp-Ch]@1
 IDirect3DTexture2 *pTexture1;
 IDirect3DTexture2 *pTexture2;

 RenderD3D3_CreateTexture(pD3DRenderer->pRenderD3D3, 64, 64, &pTexture1Surface, &pTexture1, true, false, 0x20);
 RenderD3D3_CreateTexture(pD3DRenderer->pRenderD3D3, 64, 64, &pTexture2Surface, &pTexture2, true, false, 0x20);

 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTexture)(pD3DRenderer->pRenderD3D3->pDevice, 0, pTexture1);
 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(pD3DRenderer->pRenderD3D3->pDevice, 0, 12, 1);
 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(pD3DRenderer->pRenderD3D3->pDevice, 0, 1, 2);
 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(pD3DRenderer->pRenderD3D3->pDevice, 0, 2, 2);
 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(pD3DRenderer->pRenderD3D3->pDevice, 0, 16, 2);
 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(pD3DRenderer->pRenderD3D3->pDevice, 0, 17, 2);
 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(pD3DRenderer->pRenderD3D3->pDevice, 0, 18, 1);

 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTexture)(pD3DRenderer->pRenderD3D3->pDevice, 0, pTexture2);
 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(pD3DRenderer->pRenderD3D3->pDevice, 1, 12, 3);
 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(pD3DRenderer->pRenderD3D3->pDevice, 1, 11, 1);
 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(pD3DRenderer->pRenderD3D3->pDevice, 1, 1, 7);
 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(pD3DRenderer->pRenderD3D3->pDevice, 1, 2, 2);
 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(pD3DRenderer->pRenderD3D3->pDevice, 1, 3, 1);
 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(pD3DRenderer->pRenderD3D3->pDevice, 1, 16, 2);
 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(pD3DRenderer->pRenderD3D3->pDevice, 1, 17, 2);
 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(pD3DRenderer->pRenderD3D3->pDevice, 1, 18, 1);
 
 v0 = false;
 if ((pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->ValidateDevice)(pD3DRenderer->pRenderD3D3->pDevice, &v4) == S_OK)
 {
    if ( v4 == 1 )
      v0 = true;
 }

 (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(pD3DRenderer->pRenderD3D3->pDevice, 1, 1, 1);

 (pTexture1->lpVtbl->Release)(pTexture1);
 (pTexture1Surface->lpVtbl->Release)(pTexture1Surface);

 (pTexture2->lpVtbl->Release)(pTexture2);
 (pTexture2Surface->lpVtbl->Release)(pTexture2Surface);

 return v0;
}


//----- (0049FFD7) --------------------------------------------------------
bool Render_sub_49FFD7(struct Render *_this)
{
 return RenderD3D3_CreateTexture(_this->pRenderD3D3, 64, 64, &_this->ptr_1036B0, &_this->ptr_1036B4, true, false, 0x20);
}



//----- (00452442) --------------------------------------------------------
unsigned int __fastcall sub_452442(unsigned __int16 a1, int a2, int a3, unsigned __int16 a4, unsigned __int16 a5)
{
  __int16 v6; // ST14_2@1
  __int16 v7; // dx@1
  __int16 v8; // ST10_2@1
  int v9; // edi@1
  unsigned __int16 v10; // dh@1@1
  int v11; // ebx@1
  int v12; // ebx@1
  __int16 v13; // [sp+1Ch] [bp+8h]@1

  v6 = a1 >> 2;
  v7 = a5 >> 2;
  v8 = (_WORD)a2 >> 2;
  v13 = a4 >> 2;
  LOWORD(a2) = v13;
  v9 = a2;
  LOWORD(a3) = (a5 >> 2) & 0xE0;
  LOWORD(a2) = v13 & 0xE0;
  LOWORD(v9) = v9 & 0x1C00;
  v11 = a2 + a3;
  LOWORD(a2) = v6 & 0xE0;
  v12 = a2 + v11;
  LOWORD(a2) = v8 & 0xE0;
  compile_error;//return ((v8 & 7) + (v6 & 7) + (v13 & 7) + (v7 & 7)) | (a2 + v12) | ((v8 & 0x1C00)
                //                                                    + (v6 & 0x1C00)
                //                                                    + v9
                //                                                    + (__PAIR__(v10, a5 >> 2) & 0x1C00));
  return 0;
}

unsigned int LoadHWL(const wchar_t *pFile, unsigned int *pWidth, unsigned int *pHeight, unsigned int **pPixels)
{
 struct Render_HWLBitmap *pBitmap;
 char                     pFilenameA[256];

 wsprintfA(pFilenameA, "%S", pFile);
 pBitmap = Render_LoadHWLTexture(&pD3DRenderer->struct_040114, pFilenameA, 0);
 if (!pBitmap)
   return -1;

 *pWidth = pBitmap->uWidth;
 *pHeight = pBitmap->uHeight;
 *pPixels = pBitmap->pTruecolorPixels;

 free(pBitmap->pPixels);

 return 0;
};

unsigned int Render_MoveToGPU(struct Render *_this, unsigned int uWidth, unsigned int uHeight, unsigned int *pData, struct IDirectDrawSurface4 **pOutSurface, struct IDirect3DTexture2 **pOutTexture)
{
 DDSURFACEDESC2 ddsd;
 HRESULT        hr;

 if (!_this->pRenderD3D3)
 {
  *pOutSurface = 0;
  *pOutTexture = 0;
  return 0;
 }
 if (!RenderD3D3_CreateTexture(_this->pRenderD3D3, uWidth, uHeight, pOutSurface, pOutTexture, true, 0, _this->uMinDeviceTextureDim))
 {
  *pOutSurface = 0;
  *pOutTexture = 0;
  return -1;
 }

 memset(&ddsd, 0, sizeof(DDSURFACEDESC2));
 ddsd.dwSize = sizeof(DDSURFACEDESC);
 if (LockSurface_DDraw4(*pOutSurface, &ddsd, DDLOCK_WRITEONLY | DDLOCK_WAIT))
 {
  int y;
  for (y = 0; y < uHeight; ++y)
    memcpy((char *)ddsd.lpSurface + y * ddsd.lPitch, pData + y * uWidth, uWidth * 4);

  hr = ((*pOutSurface)->lpVtbl->Unlock)(*pOutSurface, 0);
  if (FAILED(hr))
  {
   __asm int 3;
   return -1;
  }
 }
 return 0;
}

//----- (004A5048) --------------------------------------------------------
bool Render_MoveHWSpriteToVideoMemory(struct Render *_this, struct HardwareSprite *pSprite)
{
  struct Render_HWLBitmap *result; // eax@1
  int v3; // ebx@1
  int v4; // edi@1
  unsigned int v5; // esi@1
  int v16; // eax@11
  DDSURFACEDESC2 ddsd;
  /*int Dst; // [sp+Ch] [bp-7Ch]@4
  int v18; // [sp+1Ch] [bp-6Ch]@9
  int v19; // [sp+30h] [bp-58h]@5*/
 HRESULT      hr;
 unsigned int x, y;

  v4 = pSprite;
  v3 = _this;
  result = Render_LoadHWLTexture(&_this->struct_0A1BAC, pSprite->pSpriteName, pSprite->dword_000004);
  v5 = (unsigned int)result;
  if (!result)
    return 0;
 
 _this->dword_1036BC += 2 * result->uWidth * result->uHeight;
 pSprite->dword_000010 = result->dword_000030;
 pSprite->dword_000014 = result->dword_000034;
 pSprite->dword_000018 = result->dword_000018;
 pSprite->dword_00001C = result->dword_00001C;
 pSprite->dword_000020 = result->dword_000020;
 pSprite->dword_000024 = result->dword_000024;

 if (!RenderD3D3_CreateTexture(_this->pRenderD3D3, result->uWidth, result->uHeight, &pSprite->pTextureSurface, &pSprite->pTexture, true, 0, _this->uMinDeviceTextureDim))
   erroneous_printf("HiScreen16::LoadTexture - D3Drend->CreateTexture() failed: %x", 0);

 memset(&ddsd, 0, sizeof(DDSURFACEDESC2));
 ddsd.dwSize = sizeof(DDSURFACEDESC);

 if (LockSurface_DDraw4(pSprite->pTextureSurface, &ddsd, DDLOCK_WRITEONLY | DDLOCK_WAIT))
 {
      //v11 = result->pPixels;
      //v10 = ddsd.lpSurface;

      //  v13 = result->uWidth / 2;
  for (y = 0; y < result->uHeight; ++y)
  {
    /*for (x = 0; x < result->uWidth; ++x)
    {
              ++v14;
              *(_DWORD *)v10 = *(_DWORD *)v11;
              v11 += 4;
              v10 += 4;
    }
          v13 = *(_DWORD *)(v5 + 40) >> 1;
          v10 += 4 * ((ddsd.lPitch >> 2) - v13);*/
   memcpy((char *)ddsd.lpSurface + y * ddsd.lPitch, result->pTruecolorPixels + y * result->uWidth, result->uWidth * 4);
  }

  hr = (pSprite->pTextureSurface->lpVtbl->Unlock)(pSprite->pTextureSurface, 0);
  if (FAILED(hr))
    __asm int 3;

  //CheckHRESULT(0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
 }

 free(result->pPixels);
 operator_delete(0, result);

 return true;
}


//----- (004524D8) --------------------------------------------------------
struct Render_HWLBitmap *Render_LoadHWLTexture(struct Render_HWLContainer *_this, unsigned char *a2, int a3)
{
  int v3; // eax@1
  void *v4; // esi@1
  int v5; // ebx@2
  int v6; // edi@3
  void *result; // eax@8
  int v9; // ebx@9
  struct Render_HWLBitmap *v10; // edi@9
  int v11; // eax@10
  int v12; // eax@13
  int v13; // eax@13
  int v14; // ecx@13
  unsigned __int8 v15; // zf@13
  unsigned __int8 v16; // sf@13
  int v17; // esi@14
  int v18; // ecx@16
  int v19; // esi@16
  int v20; // eax@16
  int v21; // ecx@16
  int v22; // eax@16
  unsigned __int16 v23; // dx@16
  unsigned __int16 v24; // ST38_2@16
  int v25; // esi@16
  char Str1[20]; // [sp+Ch] [bp-28h]@1
  int v27; // [sp+20h] [bp-14h]@10
  int v28; // [sp+24h] [bp-10h]@13
  int v29; // [sp+28h] [bp-Ch]@14
  int v30; // [sp+2Ch] [bp-8h]@13
  unsigned int DstBuf; // [sp+30h] [bp-4h]@9
  int v32; // [sp+3Ch] [bp+8h]@2
  void *v33; // [sp+3Ch] [bp+8h]@10
  int v34; // [sp+3Ch] [bp+8h]@15
 int i;

  v4 = _this;
 wsprintfA(Str1, "%s", a2);

  v3 = v32 = _this->uNumElements;
  v5 = 0;
  if (!_this->uNumElements)
    return 0;


    while ( 1 )
    {
      v6 = v5 + (v32 - v5) / 2;
      //if ( !_strcmpi(Str1, *((const char **)v4 + v6 + 4)) )
      if (!strcmpi(Str1, _this->pSriteNames[v6]))
        break;
      //if ( _strcmpi(Str1, *((const char **)v4 + v6 + 4)) <= 0 )
      else if (strcmpi(Str1, _this->pSriteNames[v6]) < 0)
        v32 = v5 + (v32 - v5) / 2;
      else
        v5 = v6 + 1;

      if ( v5 >= v32 )
        return 0;
    }

    fseek(_this->pHWLFile, _this->pSpriteFileOffsets[v6], SEEK_SET);
    v10 = malloc(sizeof(struct Render_HWLBitmap));
    locked_fread(&DstBuf, 4u, 1u, _this->pHWLFile);
    locked_fread(&v10->dword_000018, 4, 1, _this->pHWLFile);
    locked_fread(&v10->dword_00001C, 4, 1, _this->pHWLFile);
    locked_fread(&v10->dword_000020, 4, 1, _this->pHWLFile);
    locked_fread(&v10->dword_000024, 4, 1, _this->pHWLFile);
    locked_fread(&v10->uWidth, 4, 1, _this->pHWLFile);
    locked_fread(&v10->uHeight, 4, 1, _this->pHWLFile);
    locked_fread(&v10->dword_000030, 4, 1, _this->pHWLFile);
    locked_fread(&v10->dword_000034, 4, 1, _this->pHWLFile);
    v10->pPixels = malloc(2 * v10->uWidth * v10->uHeight);
    if ( DstBuf )
    {
      v33 = malloc(DstBuf);
      locked_fread(v33, 1u, DstBuf, _this->pHWLFile);
      v27 = 2 * v10->uWidth * v10->uHeight;
      MemUnzip(v10->pPixels, &v27, (int)v33, DstBuf);
    }
    else
      locked_fread(v10->pPixels, 2, v10->uWidth * v10->uHeight, _this->pHWLFile);

    v10->pTruecolorPixels = malloc(4 * v10->uWidth * v10->uHeight);
    for (i = 0; i < v10->uWidth * v10->uHeight; ++i)
    {
     v10->pTruecolorPixels[i] = (unsigned int)(((unsigned char)(((v10->pPixels[i] & 0xF800) >> 11) * 8)) << 16) |
                                (unsigned int)(((unsigned char)(((v10->pPixels[i] & 0x07E0) >> 5) * 4)) << 8) |
                                (unsigned char)((v10->pPixels[i] & 0x1F) * 8);
    }

    if (_this->dword_061A90)
    {
    v9 = (int)((char *)v10 + 40);
      v13 = *((_DWORD *)v10 + 11) / 2;
      v14 = *(_DWORD *)v9 / 2;
      *((_DWORD *)v10 + 11) = v13;
      *(_DWORD *)v9 = v14;
      compile_error;//v12 = (int)operator new(2 * v14 * v13);
      v30 = 0;
      v15 = *((_DWORD *)v10 + 11) == 0;
      v16 = *((_DWORD *)v10 + 11) < 0;
      v28 = v12;
      if ( !(v16 | v15) )
      {
        v17 = *(_DWORD *)v9;
        v29 = 1;
        do
        {
          v34 = 0;
          if ( v17 > 0 )
          {
            do
            {
              v18 = v17 * v29;
              v19 = v30 * v17;
              v20 = *((_DWORD *)v10 + 14);
              v21 = v20 + 4 * (v34 + v18);
              v22 = v20 + 4 * (v34 + 2 * v19);
              v23 = *(_WORD *)(v21 + 2);
              v24 = *(_WORD *)v21;
              LOWORD(v21) = *(_WORD *)v22;
              v25 = v34++ + v19;
              *(_WORD *)(v28 + 2 * v25) = sub_452442(*(_WORD *)(v22 + 2), v21, v9, v24, v23);
              v17 = *(_DWORD *)v9;
            }
            while ( v34 < *(_DWORD *)v9 );
          }
          ++v30;
          v29 += 2;
          v12 = v30;
        }
        while ( v30 < *((_DWORD *)v10 + 11) );
      }
      operator_delete(v12, *((_DWORD *)v10 + 14));
      *((_DWORD *)v10 + 14) = v28;
    }
    return v10;
}



//----- (0049E756) --------------------------------------------------------
bool __thiscall sub_49E756(IDirectDraw4 *pdd4)
{
 DDCAPS ddcDriver,
        ddcReference;
  //int v2; // [sp+0h] [bp-2F8h]@1

  //int v3; // [sp+17Ch] [bp-17Ch]@1
  //char v4; // [sp+228h] [bp-D0h]@1
  //char v5; // [sp+22Dh] [bp-CBh]@2
 
 ddcDriver.dwSize = sizeof(DDCAPS);
 ddcReference.dwSize = sizeof(DDCAPS);

 (pdd4->lpVtbl->GetCaps)(pdd4, &ddcDriver, &ddcReference);
 return *((char *)(&ddcReference) + 0xAC) & 0x40 &&
        *((char *)(&ddcReference) + 0xAF) & 0x02;
}



//----- (004A6D87) --------------------------------------------------------
void Render_FillRect2(struct Render *_this, unsigned int uX, unsigned int uY, unsigned int a5, int a6, unsigned int a7)
{
 int y, x;

 if (!_this->bSceneBegun)
   return;

 for (y = uY; y < uY + a6; ++y)
   for (x = uX; x < uX + a5; ++x)
     _this->pTargetSurface[x + y * _this->uTargetSurfacePitch] = a7;
}


//----- (0049FE05) --------------------------------------------------------
void sub_49FE05(struct Render *pD3DRenderer)
{
  int v3; // esi@1
  char v4; // zf@4
  unsigned int v5; // ebx@6
  int v6; // eax@7
  int v7; // eax@11
  int v8; // eax@13
  int v9; // eax@15
  int v10; // eax@20
  int v11; // eax@22
  int v12; // eax@24
  int v13; // ebx@28
  unsigned int *v14; // esi@29

 v3 = pD3DRenderer;
 if (pD3DRenderer->pRenderD3D3)
 {
  if (pD3DRenderer->dword_040110)
  {
   RenderD3D3_ClearTarget(pD3DRenderer->pRenderD3D3, 1, 0, 0, 1.0);
   RenderD3D3_Present(pD3DRenderer->pRenderD3D3, 0);
   RenderD3D3_ClearTarget(pD3DRenderer->pRenderD3D3, 1, 0, 0, 1.0);
  }

    *(_DWORD *)(v3 + 262296) = 0;
    *(_DWORD *)(v3 + 262292) = 0;
    v4 = *(_DWORD *)(v3 + 262380) == 0;
    *(_DWORD *)(v3 + 262288) = 0;
    *(_DWORD *)(v3 + 262284) = 0;
    if ( !v4 )
    {
      operator_delete(0, *(_DWORD *)(v3 + 262376));
      *(_DWORD *)(v3 + 262380) = 0;
      *(_DWORD *)(v3 + 262376) = 0;
    }
    v5 = *(_DWORD *)(v3 + 262280);
    if ( v5 )
    {
      v6 = sub_49DC90(*(_DWORD *)(v3 + 262280));
      operator_delete(0, v5);
    }
    *(_DWORD *)(v3 + 262280) = 0;
  }
 else
 {
  if (dword_4E800C == 1)
  {
   if (!pD3DRenderer->pdd2)
     return 0;

      (*(void (__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)pD3DRenderer->pdd2 + 80))(pD3DRenderer->pdd2, *(_DWORD *)(v3 + 262224), 8);
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v3 + 262300) + 40))(*(_DWORD *)(v3 + 262300));
      v7 = *(_DWORD *)(v3 + 262312);
      if ( v7 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v7 + 8))(*(_DWORD *)(v3 + 262312));
        *(_DWORD *)(v3 + 262312) = 0;
      }
      v8 = *(_DWORD *)(v3 + 262308);
      if ( v8 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v8 + 8))(*(_DWORD *)(v3 + 262308));
        *(_DWORD *)(v3 + 262308) = 0;
      }
      v9 = *(_DWORD *)(v3 + 262304);
      if ( v9 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v9 + 8))(*(_DWORD *)(v3 + 262304));
        *(_DWORD *)(v3 + 262304) = 0;
      }
      if (*(_DWORD *)(v3 + 262300))
      {
        (*(int (__stdcall **)(_DWORD))(*(_DWORD *)(*(_DWORD *)(v3 + 262300)) + 8))(*(_DWORD *)(v3 + 262300));
        *(_DWORD *)(v3 + 262300) = 0;
      }
    }
    else
    {
     if (!pD3DRenderer->pdd4)
       return 0;

      (*(void (__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)pD3DRenderer->pdd4 + 80))(pD3DRenderer->pdd4, *(_DWORD *)(v3 + 262224), 1032);
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v3 + 262284) + 40))(*(_DWORD *)(v3 + 262284));
      v10 = *(_DWORD *)(v3 + 262296);
      if ( v10 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v10 + 8))(*(_DWORD *)(v3 + 262296));
        *(_DWORD *)(v3 + 262296) = 0;
      }
      v11 = *(_DWORD *)(v3 + 262292);
      if ( v11 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v11 + 8))(*(_DWORD *)(v3 + 262292));
        *(_DWORD *)(v3 + 262292) = 0;
      }
      v12 = *(_DWORD *)(v3 + 262288);
      if ( v12 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v12 + 8))(*(_DWORD *)(v3 + 262288));
        *(_DWORD *)(v3 + 262288) = 0;
      }
      if (*(_DWORD *)(v3 + 262284))
      {
        (*(int (__stdcall **)(_DWORD))(*(_DWORD *)(*(_DWORD *)(v3 + 262284)) + 8))(*(_DWORD *)(v3 + 262284));
        *(_DWORD *)(v3 + 262284) = 0;
      }
    }
    v13 = v3 + 262380;
    if ( *(_DWORD *)(v3 + 262380) )
    {
      v14 = (unsigned int *)(v3 + 262376);
      operator_delete(0, *v14);
      *(_DWORD *)v13 = 0;
      *v14 = 0;
    }
  }
}




//----- (004A2050) --------------------------------------------------------
void Render_DrawPolygon(struct Render *_this, unsigned int uNumVertices, struct struct8 *a3, struct class51_stru2 *a4, IDirect3DTexture2 *pTexture)
{
  int v5; // ebx@1
  int v6; // edi@1
  int v8; // eax@7
  float v9; // eax@12
  float *v10; // esi@12
  float v11; // ecx@14
  double v12; // st7@14
  double v13; // st7@14
  double v14; // st7@14
  signed int v15; // eax@14
  int v16; // eax@15
  float v17; // ST48_4@15
  char v18; // zf@17
  int v19; // eax@18
  int v20; // eax@18
  int v21; // edx@20
  signed int v22; // ecx@20
  int v23; // eax@20
  const char *v24; // ST4C_4@20
  unsigned int v25; // ST50_4@20
  int v26; // ST54_4@20
  int v27; // eax@20
  _UNKNOWN *v28; // eax@21
  int v29; // ecx@23
  int v30; // eax@23
  int v31; // eax@23
  int v32; // eax@24
  int v33; // eax@25
  int v34; // eax@25
  int v35; // eax@25
  int v36; // eax@25
  signed int v37; // ecx@26
  int v38; // eax@26
  _UNKNOWN *v39; // eax@27
  int v40; // edx@28
  int v41; // eax@29
  int v42; // eax@29
  int v43; // eax@29
  int v44; // eax@29
  unsigned int v46; // eax@29
  int v47; // eax@30
  int v48; // eax@30
  int v49; // eax@30
  double v52; // st6@35
  const char *v55; // [sp+4Ch] [bp-1Ch]@20
  int v57; // [sp+5Ch] [bp-Ch]@3
  signed int v59; // [sp+60h] [bp-8h]@12
  int v61; // [sp+64h] [bp-4h]@4
 int i;

  v6 = _this;
  v5 = 0;
 if (!_this->uD3D3SceneBegun)
   return;

 if (uNumVertices < 3)
   return;
 
   v57 = pGame->class04_obj->std__vector_000004_size;
   if (pGame->class04_obj->std__vector_000004_size)
     v61 = -1;

   Game_sub_44EE30(pGame, a4, (void **)&v61);
   if (byte_4D8410[572] && pGame->uSomeFlags & 0x01)
   {
    v8 = sub_47C4FC_GetActorTintColor(*(_BYTE *)(a3 + 88), 0, array_50AC10[0].flt_00000C, 0, 0);
    sub_45D74F_MessWithLight(pGame->class04_obj, v8, 0);
   }
   else
   {
    if ( !v57 || byte_4D8410[572] && pGame->uSomeFlags & 0x02)
    {
     (_this->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(_this->pRenderD3D3->pDevice, 0, 12, 1);
     (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice, 22, 2);
     if (_this->bUsingSpecular)
     {
      (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice, 27, 1);
      (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice, 19, 2);
      (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice, 20, 1);
     }
     
     for (i = 0; i < uNumVertices; ++i)
     {
      v61 = sub_47C4FC_GetActorTintColor(a3->byte_000058, 0, array_50AC10[i].flt_00000C, 0, 0);
       Game_sub_44EE30(pGame, a4, (void **)&v61);

       v52 = 1000 * array_50AC10[i].flt_00000C / (double)pStruct9_global->shading_dist_mist;
       pVertices[i].x = array_50AC10[i].flt_000018;
       pVertices[i].y = array_50AC10[i].flt_00001C;
       pVertices[i].z = 1.0 - 1.0 / v52;
       pVertices[i].rhw = 1.0 / (array_50AC10[i].flt_00000C + 0.0000001000000011686097);
              
       pVertices[i].diffuse = sub_47C4FC_GetActorTintColor(a3->byte_000058, 0, array_50AC10[i].flt_00000C, 0, 0);
       if (_this->bUsingSpecular)
         pVertices[i].specular = sub_47C3D7(0, 0, array_50AC10[i].flt_00000C);
       else
         pVertices[i].specular = 0;

       pVertices[i].u = array_50AC10[i].u;
       pVertices[i].v = array_50AC10[i].v;
     }

     (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->SetTexture)(pD3DRenderer->pRenderD3D3->pDevice, 0, pTexture);
     (pD3DRenderer->pRenderD3D3->pDevice->lpVtbl->DrawPrimitive)(pD3DRenderer->pRenderD3D3->pDevice, D3DPT_TRIANGLEFAN, D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1, pVertices, uNumVertices, D3DDP_DONOTLIGHT);
    }
    else
        {
          if (uNumVertices > 0)
          {
            LODWORD(v9) = &pVertices->y;
            v10 = &array_50AC10[0].flt_00000C;
            a4 = (int)&pVertices->y;
            v59 = uNumVertices;
            while ( 1 )
            {
              v13 = *v10 * 1000.0;
              *(_DWORD *)(LODWORD(v9) - 4) = *((_DWORD *)v10 + 3);
              v14 = v13 / (double)pStruct9_global->shading_dist_mist;
              compile_error;//*LODWORD(v9) = *((_DWORD *)v10 + 4);
              *(float *)(LODWORD(v9) + 4) = 1.0 - 1.0 / v14;
              *(float *)(LODWORD(v9) + 8) = 1.0 / (*v10 + 0.0000001000000011686097);
              v15 = sub_47C4FC_GetActorTintColor(*(_BYTE *)(a3 + 88), 0, *v10, 0, 0);
              LODWORD(v11) = a4;
              v12 = *v10;
              *(_DWORD *)(a4 + 12) = v15;
              if ( *(_DWORD *)(v6 + 1062496) )
              {
                v17 = v12;
                v16 = sub_47C3D7(0, 0, v17);
                LODWORD(v11) = a4;
              }
              else
              {
                v16 = 0;
              }
              *(_DWORD *)(LODWORD(v11) + 16) = v16;
              *(_DWORD *)(LODWORD(v11) + 20) = *((_DWORD *)v10 + 6);
              *(_DWORD *)(LODWORD(v11) + 24) = *((_DWORD *)v10 + 7);
              v10 += 12;
              v18 = v59-- == 1;
              a4 = LODWORD(v11) + 32;
              if ( v18 )
                break;
              LODWORD(v9) = a4;
            }
          }
          v19 = (*(int (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v6 + 262280) + 56) + 88))(
                  *(_DWORD *)(*(_DWORD *)(v6 + 262280) + 56),
                  14,
                  0);
          CheckHRESULT(&a3, v19, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);

          v20 = (_this->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(_this->pRenderD3D3->pDevice, 0, 12, 1);
          CheckHRESULT(&a3, v20, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);

          if (pD3DRenderer->bUsingSpecular)
            (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice, 28, 0);

          v23 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v6 + 262280) + 56)
                                                                                         + 152))(
                  *(_DWORD *)(*(_DWORD *)(v6 + 262280) + 56),
                  0,
                  0,
                  "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp",
                  543,
                  0);
          CheckHRESULT(&a3, v23, v24, v25, v26);
          v27 = (*(int (__stdcall **)(_DWORD, signed int, signed int, _UNKNOWN *, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v6 + 262280) + 56) + 112))(
                  *(_DWORD *)(*(_DWORD *)(v6 + 262280) + 56),
                  6,
                  452,
                  pVertices,
                  uNumVertices,
                  16);
          CheckHRESULT(&a3, v27, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
          v55 = *(const char **)(*(_DWORD *)(v6 + 262280) + 56);
          (*(void (**)(void))(*(_DWORD *)v55 + 88))();
          sub_45D74F_MessWithLight(pGame->class04_obj, -1, 0);
          v22 = uNumVertices;
          if (uNumVertices > 0)
          {
            v28 = &pVertices->diffuse;
            do
            {
              v21 = v61;
              *(_DWORD *)v28 = v61;
              v28 = (char *)v28 + 32;
              --v22;
            }
            while ( v22 );
          }
          v29 = **(_DWORD **)(*(_DWORD *)(v6 + 262280) + 56);
          v30 = (*(int (__fastcall **)(int, int, _DWORD, _DWORD, int))(v29 + 152))(
                  v29,
                  v21,
                  *(_DWORD *)(*(_DWORD *)(v6 + 262280) + 56),
                  0,
                  pTexture);
          CheckHRESULT(&a3, v30, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);

          v31 = (_this->pRenderD3D3->pDevice->lpVtbl->SetTextureStageState)(_this->pRenderD3D3->pDevice, 0, 12, 1);
          CheckHRESULT(&a3, v31, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
          if ( !pD3DRenderer->bUsingSpecular )
          {
            v32 = (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice, 14, 1);
            CheckHRESULT(&a3, v32, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
          }
          v33 = (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice,
                  27,
                  1);
          CheckHRESULT(&a3, v33, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
          v34 = (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice,
                  19,
                  1);
          CheckHRESULT(&a3, v34, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
          v35 = (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice,
                  20,
                  3);
          CheckHRESULT(&a3, v35, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
          v36 = (*(int (__stdcall **)(_DWORD, signed int, signed int, _UNKNOWN *, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v6 + 262280) + 56) + 112))(
                  *(_DWORD *)(*(_DWORD *)(v6 + 262280) + 56),
                  6,
                  452,
                  pVertices,
                  uNumVertices,
                  16);
          CheckHRESULT(&a3, v36, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
          if ( pD3DRenderer->bUsingSpecular )
          {
            v38 = (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice,
                    14,
                    1);
            CheckHRESULT(&a3, v38, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
            v37 = uNumVertices;
            if (uNumVertices > 0)
            {
              v39 = &pVertices->specular;
              do
              {
                v40 = *(_DWORD *)v39;
                *(_DWORD *)v39 = 0;
                v39 = (char *)v39 + 32;
                --v37;
                *((_DWORD *)v39 - 9) = dword_EF524C | v40 & 0xFF000000;
              }
              while ( v37 );
            }
            v41 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v6 + 262280) + 56)
                                                                                           + 152))(
                    *(_DWORD *)(*(_DWORD *)(v6 + 262280) + 56),
                    0,
                    0,
                    "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp",
                    __LINE__,
                    0);
            CheckHRESULT(&a3, v41, v55, 0x16u, 1);
            v42 = (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice,
                    19,
                    6);
            CheckHRESULT(&a3, v42, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
            v43 = (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice,
                    20,
                    5);
            CheckHRESULT(&a3, v43, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
            v44 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)(v6 + 262280) + 56)
                                                                                       + 112))(
                    *(_DWORD *)(*(_DWORD *)(v6 + 262280) + 56),
                    6,
                    452,
                    pVertices,
                    uNumVertices,
                    16);
            CheckHRESULT(0, v44, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
            (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice,
              28,
              1);
            v46 = sub_47C370();
            (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice,
              34,
              v46 & 0xFFFFFF);
            v5 = 0;
            (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice,
              35,
              0);
          }
          v47 = (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice,
                  19,
                  2);
          CheckHRESULT(0, v47, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, v5);
          v48 = (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice,
                  20,
                  1);
          CheckHRESULT(0, v48, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, v5);
          v49 = (_this->pRenderD3D3->pDevice->lpVtbl->SetRenderState)(_this->pRenderD3D3->pDevice,
                  27,
                  v5);
          CheckHRESULT(0, v49, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, v5);
        }
      }
}