#include "mm7DDrawRenderer.h"

#include "defs.h"

#include "classes.h"

#include "data.h"

extern float flt_6BE3A0;
extern int dword_AD4730;
extern int dword_720010;
extern int dword_F79D70;
extern int dword_F79D7C;


int unknown_libname_107();
void __cdecl sub_4A57E9();
char __cdecl sub_4A597D();



//----- (MM7exe::00452347) --------------------------------------------------------
void CD3DRenderer_HWLContainer_ctor(struct CD3DRenderer_HWLContainer *_this)
{
 _this->pHWLFile = 0;
 _this->dword_000004 = 0;
 _this->dword_000008 = 0;

 _this->uNumElements = 0;
 memset(_this->array_000010, 0, 50000 * 4);
 memset(_this->array_030D50, 0, 50000 * 4);
 _this->dword_061A90 = 0;
 _this->dword_061A94 = 0;
}

//----- (MM7.exe::0045237F) --------------------------------------------------------
int CD3DRenderer_HWLContainer_LoadHWLHeaders(struct CD3DRenderer_HWLContainer *_this, const char *pFilename)
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
  _this->array_000010[i] = malloc(0x14);  //operator new(0x14u)
  locked_fread(_this->array_000010[i], 1, 0x14, _this->pHWLFile);
 }

 locked_fread(_this->array_030D50, 4, _this->uNumElements, _this->pHWLFile);
 _this->dword_061A90 = 0;
 return true;
}

//----- (MM7.exe::0049E992) --------------------------------------------------------
extern int dword_4EED78; // weak
extern _UNKNOWN unk_4EED80; // weak
void CD3DRenderer_ctor(struct CD3DRenderer *_this)
{
  int v1; // eax@1
  char v3; // zf@1

 memset(_this, 0, sizeof(struct CD3DRenderer));


 _this->pdd4 = 0;
 _this->pdds4_FrontBuffer = 0;
 pD3DRenderer->pdds4_BackBuffer = 0;
 _this->dword_040098 = 0;
 _this->pdd2 = 0;
 _this->pdds2_FrontBuffer = 0;
 _this->pdds2_BackBuffer = 0;
 _this->dword_0400A8 = 0;

 CD3DRenderer_HWLContainer_ctor(&_this->struct_040114);
 CD3DRenderer_HWLContainer_ctor(&_this->struct_0A1BAC);

 _this->dword_040054 = 0;
 _this->dword_040058 = 1;
 _this->bUseDirect3D = ReadWindowsRegistry("Use D3D", false);
 _this->bStartInWindow = ReadWindowsRegistry("startinwindow", false);
 v1 = ReadWindowsRegistry("D3D Device", true);
 v3 = _this->bStartInWindow == 0;

 _this->bStartInWindow = v3 && v1 != 1;
 _this->bUseDirect3DDevice = v1;
 _this->dword_000010 = 640;
 _this->dword_000014 = 480;
 _this->dword_00001C = 0;
 _this->dword_000020 = 0;
 _this->dword_000024 = 639;
 _this->dword_000028 = 479;

 _this->dword_04002C = 0;
 _this->dword_040030 = 0;
 _this->dword_040034 = 0;
 _this->pZBuffer = 0;
 _this->dword_04003C = &unk_4EED80;
 _this->dword_040040 = dword_4EED78;

 _this->dword_040044 = 2;
 _this->dword_040048 = 6;

 _this->dword_040088 = 0;

 _this->bSceneBegun = false;

 _this->pTargetSurface = 0;
 _this->uTargetSurfacePitch = 0;

 _this->dword_0400F4 = 0;
 _this->dword_0400F8 = 0;
 _this->dword_0400FC = 480;
 _this->dword_040100 = 640;
 _this->dword_040104 = 1;
 _this->dword_040108 = 0;
 _this->dword_04010C = 0;
 _this->dword_040110 = 0;

 _this->bUseColoredLights = ReadWindowsRegistry("Colored Lights", false);
 _this->dword_103648 = 0;
 _this->dword_10364C = 1;
 _this->uLevelOfDetail = ReadWindowsRegistry("Detail Level", 1);

 _this->byte_103668[0] = 0;

 _this->dword_1036B8 = 0;
 _this->dword_1036BC = 0;
 CD3DRenderer_HWLContainer_LoadHWLHeaders(&_this->struct_040114, "data\\d3dbitmap.hwl");
 CD3DRenderer_HWLContainer_LoadHWLHeaders(&_this->struct_0A1BAC, "data\\d3dsprite.hwl");
}

//----- (MM7.exe::0049FBCD) --------------------------------------------------------
int sub_49FBCD(struct CD3DRenderer *_this, int a2)
{
 int result;
  int v4; // ecx@4

 result = _this;
 if (_this->dword_040088)
 {
  if (_this->dword_040110)
    result = sub_49E4FC(_this->dword_040088, 1, a2, 0, 0.0);
 }
 else
 {
  v4 = _this->dword_000010 * _this->dword_000014 >> 1;
  memset(_this->pTargetSurface, a2, 4 * v4);

  result = a2;
 }
 return _this;
}

//----- (MM7.exe::004A51CB) --------------------------------------------------------
unsigned int CD3DRenderer_BeginScene(struct CD3DRenderer *_this)
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
  if (_this->dword_040088)
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
    LOBYTE(v1) = CD3DRenderer_LockBackBuffer(_this, &_this->pTargetSurface, &_this->uTargetSurfacePitch);
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
  LOBYTE(v1) = CD3DRenderer_RestoreFrontBuffer(_this);
 }
 return v1;
}

//----- (MM7.exe::004A1605) --------------------------------------------------------
int CD3DRenderer_LockBackBuffer(struct CD3DRenderer *_this, void **ppOutSurfacePtr, unsigned int *pOutSurfaceWidth)
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
int sub_4A5B81(struct CD3DRenderer *_this, int a2, int a3, int a4, int a5)
{
 _this->dword_0400F4 = a3;
 _this->dword_0400F8 = a2;
 _this->dword_0400FC = a5;
 _this->dword_040100 = a4;
 _this->dword_040104 = 1;
 return a4;
}

//----- (004A5EB2) --------------------------------------------------------
void CD3DRenderer_DrawIndexedTexture(struct CD3DRenderer *_this, unsigned int uX, unsigned int uY, struct class18 *pTexture)
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
               uDstColor,
               uAlpha;

 if (!_this->bSceneBegun || !pTexture)
   return;


 pSurfacePtr = (unsigned int *)(_this->pTargetSurface);
 for (y = 0; y < min(pTexture->uTextureHeight, (_this->dword_0400FC - _this->dword_0400F4)); ++y)
   for (x = 0; x < pTexture->uTextureWidth; ++x)
   {
    uSrcColor = pTexture->pTruecolorPixels[y * pTexture->uTextureWidth + x];
    uDstColor = pSurfacePtr[(y + uY) * _this->uTargetSurfacePitch + x + uX];
    uAlpha = ((uSrcColor & 0xFF000000) >> 8) | ((uSrcColor & 0xFF000000) >> 16) | ((uSrcColor & 0xFF000000) >> 24);
    pSurfacePtr[(y + uY) * _this->uTargetSurfacePitch + x + uX] = (uSrcColor & uAlpha) + (uDstColor & (0x00FFFFFF - uAlpha));
 }



 if (!pTexture->pPalette)
   return;

 pSurfacePtr = _this->pTargetSurface + (uX + uY * _this->uTargetSurfacePitch);

 v6 = pTexture->uTextureHeight;
 v21 = pTexture->uTextureWidth;
 v19 = pTexture->uTextureWidth;
 v20 = pTexture->pIndexedPixels;

 if (_this->dword_040104)
 {
  if (uX < _this->dword_0400F8)
  {
   v8 = _this->dword_0400F8 - uX;
   v20 += v8;
   v21 += uX - _this->dword_0400F8;
   pSurfacePtr += v8;
  }

  if (uY < _this->dword_0400F4)
  {
   v10 = _this->dword_0400F4 - uY;
   v20 += v19 * v10;
   v6 = uY - _this->dword_0400F4 + pTexture->uTextureHeight;
   pSurfacePtr += _this->uTargetSurfacePitch * v10;
  }

  v11 = _this->dword_0400F8;
  if (v11 < uX)
    v11 = uX;

  v24 = _this->dword_040100;
  if (v11 + v21 > v24)
  {
   v12 = _this->dword_0400F8;
   if (v12 < uX)
     v12 = uX;
   v21 = v24 - v12;
  }

  v13 = _this->dword_0400F4;
  if (v13 < uY)
    v13 = uY;

  v14 = _this->dword_0400FC;
  if (v6 + v13 > v14)
  {
   v15 = _this->dword_0400F4;
   if ( v15 < uY )
     v15 = uY;
   v6 = v14 - v15;
  }
 }
}

//----- (004A6AB1) --------------------------------------------------------
void sub_4A6AB1(struct CD3DRenderer *_this, unsigned int uX, unsigned int uY, unsigned char *pData, int a5, int a6, unsigned short *pFontPixels, int a8)
{
  int v8; // eax@2
  int v9; // edx@2
  int v10; // edi@2
  int v11; // esi@2
  int v12; // ebx@3
  int v13; // edx@5
  int v14; // edx@6
  int v15; // ebx@7
  int v16; // edx@9
  int v17; // edi@10
  int v18; // ebx@13
  int v19; // edx@15
  int v20; // esi@16
  int v21; // ebx@22
  char v23; // zf@28
  int v24; // ebx@31
  __int16 v25; // si@35
  char v27; // zf@38
  int v28; // [sp+Ch] [bp-4h]@2
  int v29; // [sp+18h] [bp+8h]@22
  int v30; // [sp+18h] [bp+8h]@31
  int v31; // [sp+1Ch] [bp+Ch]@24
  int v32; // [sp+1Ch] [bp+Ch]@33
  int v33; // [sp+20h] [bp+10h]@30
  int v34; // [sp+24h] [bp+14h]@22
  int v35; // [sp+24h] [bp+14h]@31
 unsigned int  *pSurfacePtr;
 unsigned char *pSrc;
 int x, y;

  if (!_this->bSceneBegun)
    return;

 pSurfacePtr = (unsigned int *)(_this->pTargetSurface);
 pSrc = pData;


 for (y = 0; y < a6; ++y)
   for (x = 0; x < a5; ++x)
   {
    if (*pSrc++)
      pSurfacePtr[(uY + y) * _this->uTargetSurfacePitch + uX + x] = (unsigned int)pFontPixels[pSrc[-1]] * 0xFFFFFFFF;

   }


/*

    v10 = a5;
    v11 = a6;

    v8 = _this->pTargetSurface + 2 * (uX + uY * _this->uTargetSurfacePitch);

    v9 = pData;
    v28 = pData;
    if (_this->dword_040104)
    {
      v12 = _this->dword_0400F8;
      if ( uX < v12 )
      {
        v28 = v12 - uY + pData;
        v8 += 2 * (v12 - uX);
        v10 = a5 + uX - v12;
      }
      v13 = _this->dword_0400F4;
      if ( uY < v13 )
      {
        v14 = v13 - uY;
        v28 += a5 * v14;
        v11 = a6 + uY - _this->dword_0400F4;
        v8 += 2 * _this->uTargetSurfacePitch * v14;
      }
      v15 = _this->dword_0400F8;
      if ( v15 < uX )
        v15 = uX;
      v16 = _this->dword_040100;
      if ( v10 + v15 > v16 )
      {
        v17 = _this->dword_0400F8;
        if ( v17 < uX )
          v17 = uX;
        v10 = v16 - v17;
      }
      v18 = _this->dword_0400F4;
      if ( v18 < uY )
        v18 = uY;
      v19 = _this->dword_0400FC;
      if ( v11 + v18 > v19 )
      {
        v20 = _this->dword_0400F4;
        if ( v20 < uY )
          v20 = uY;
        v11 = v19 - v20;
      }
      v9 = v28;
    }


    if ( a8 )
    {
      v33 = pD3DRenderer->dword_0400DC | pD3DRenderer->dword_0400E0;
      if ( v11 > 0 )
      {
        v24 = a5;
        v35 = v11;
        v30 = v24 - v10;
        do
        {
          if ( v10 > 0 )
          {
            v32 = v10;
            do
            {
              if ( *(_BYTE *)v9 )
                v25 = *(_WORD *)(a7 + 2 * *(_BYTE *)v9);
              else
                v25 = v33;
              *(_WORD *)v8 = v25;
              v8 += 2;
              ++v9;
            }
            while ( v32-- != 1 );
          }
          v9 += v30;
          v27 = v35-- == 1;
          v8 += 2 * (*(_DWORD *)(_this + 262384) - v10);
        }
        while ( !v27 );
      }
    }
    else
    {
      if ( v11 > 0 )
      {
        v21 = a5;
        v34 = v11;
        v29 = v21 - v10;
        do
        {
          if ( v10 > 0 )
          {
            v31 = v10;
            do
            {
              if ( *(_BYTE *)v9 )
                *(_WORD *)v8 = *(_WORD *)(a7 + 2 * *(_BYTE *)v9);
              v8 += 2;
              ++v9;
            }
            while ( v31-- != 1 );
          }
          v9 += v29;
          v23 = v34-- == 1;
          v8 += 2 * (*(_DWORD *)(_this + 262384) - v10);
        }
        while ( !v23 );
      }
    }*/
}

//----- (004A6274) --------------------------------------------------------
void CD3DRenderer_DrawTransparentTexture(struct CD3DRenderer *_this, unsigned int uX, unsigned int uY, struct class18 *pTexture)
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
   for (x = 0; x < pTexture->uTextureWidth; ++x)
   {
    uSrcColor = pTexture->pTruecolorPixels[y * pTexture->uTextureWidth + x];
    uDstColor = pSurfacePtr[(y + uY) * _this->uTargetSurfacePitch + x + uX];
    uAlpha = ((uSrcColor & 0xFF000000) >> 8) | ((uSrcColor & 0xFF000000) >> 16) | ((uSrcColor & 0xFF000000) >> 24);
    pSurfacePtr[(y + uY) * _this->uTargetSurfacePitch + x + uX] = (uSrcColor & uAlpha) + (uDstColor & (0x00FFFFFF - uAlpha));
   }



 if (!pTexture->pPalette)
   return;


 v6 = pTexture->uTextureHeight;
 v5 = _this->pTargetSurface + (uX + uY * _this->uTargetSurfacePitch);
 v20 = pTexture->pIndexedPixels;
 v21 = pTexture->uTextureWidth;
 v19 = pTexture->uTextureWidth;

 if (_this->dword_040104)
 {
          v7 = _this->dword_0400F8;
          if ( uX < v7 )
          {
            v8 = v7 - uX;
            v20 += v8;
            v21 += uX - _this->dword_0400F8;
            v5 += v8;
          }
          v9 = _this->dword_0400F4;
          v6 = pTexture->uTextureHeight;
          if ( uY < v9 )
          {
            v10 = v9 - uY;
            v20 += v19 * v10;
            v6 = uY - _this->dword_0400F4 + pTexture->uTextureHeight;
            v5 += _this->uTargetSurfacePitch * v10;
          }
          v11 = _this->dword_0400F8;
          if ( v11 < uX )
            v11 = uX;
          v24 = _this->dword_040100;
          if ( v11 + v21 > v24 )
          {
            v12 = _this->dword_0400F8;
            if ( v12 < uX )
              v12 = uX;
            v21 = v24 - v12;
          }
          v13 = _this->dword_0400F4;
          if ( v13 < uY )
            v13 = uY;
          v14 = _this->dword_0400FC;
          if ( v6 + v13 > v14 )
          {
            v15 = _this->dword_0400F4;
            if ( v15 < uY )
              v15 = uY;
            v6 = v14 - v15;
          }
        }
}

//----- (004A6C4F) --------------------------------------------------------
void sub_4A6C4F(struct CD3DRenderer *_this, unsigned int uOutX, unsigned int uOutY,
                unsigned short *pFontPixels, unsigned int uCharWidth, unsigned int uCharHeight,
                unsigned short *pFontPalette, unsigned int uMainColor, unsigned int uShadowColor)
{
  int v9; // eax@2
  int v10; // edi@2
  int v11; // esi@2
  int v12; // ebx@3
  int v13; // edx@5
  int v14; // edx@6
  int v15; // ebx@7
  int v16; // edx@9
  int v17; // edi@10
  int v18; // ebx@13
  int v19; // edx@15
  int v20; // esi@16
  int v21; // esi@22
  __int16 v22; // dx@24
  char v23; // zf@28
  int v24; // [sp+Ch] [bp-4h]@2
  int v25; // [sp+18h] [bp+8h]@20
 unsigned int  *pSurfacePtr;
 unsigned char *pSrc;
 int x, y;

  if (!_this->bSceneBegun)
    return;

 pSurfacePtr = (unsigned int *)(_this->pTargetSurface);
 pSrc = pFontPixels;

 for (y = 0; y < uCharHeight; ++y)
   for (x = 0; x < uCharWidth; ++x)
   {
    if (*pSrc++)
      if (pFontPalette[pSrc[-1]] == 1)
        pSurfacePtr[(uOutY + y) * _this->uTargetSurfacePitch + uOutX + x] = uShadowColor;
      else
        pSurfacePtr[(uOutY + y) * _this->uTargetSurfacePitch + uOutX + x] = uMainColor;
   }
/*
 v10 = a5;
 v11 = a6;
 v9 = _this->pTargetSurface + (a2 + a3 * _this->uTargetSurfacePitch);
 v24 = a4;
 if (_this->dword_040104)
 {
  v12 = _this->dword_0400F8;
  if (a2 < v12)
  {
   v24 = v12 - a2 + a4;
   v9 += 2 * (v12 - a2);
   v10 = a5 + a2 - v12;
  }
  v13 = _this->dword_0400F4;
  if (a3 < v13)
  {
   v14 = v13 - a3;
   v24 += a5 * v14;
   v11 = a6 + a3 - _this->dword_0400F4;
   v9 += _this->uTargetSurfacePitch * v14;
  }
  v15 = _this->dword_0400F8;
  if (v15 < a2)
    v15 = a2;

  v16 = _this->dword_040100;
  if (v10 + v15 > v16)
  {
   v17 = _this->dword_0400F8;
   if (v17 < a2)
     v17 = a2;
   v10 = v16 - v17;
  }

  v18 = _this->dword_0400F4;
  if (v18 < a3)
    v18 = a3;
  v19 = _this->dword_0400FC;

  if (v11 + v18 > v19)
  {
   v20 = _this->dword_0400F4;
   if (v20 < a3)
     v20 = a3;
   v11 = v19 - v20;
  }
 }


 if (v11 > 0)
 {
  v25 = v11;
  do
  {
   if ( v10 > 0 )
   {
    v21 = v10;
    do
    {
     if ( *(_BYTE *)v24 )
     {
      v22 = a9;
      if ( *(_BYTE *)v24 != 1 )
        v22 = a8;
      *(_WORD *)v9 = v22;
     }
     v9 += 2;
     ++v24;
     --v21;
    }
    while (v21);
   }
   v24 += a5 - v10;
   v23 = v25-- == 1;
   v9 += (_this->uTargetSurfacePitch - v10);
  }
  while ( !v23 );
 }*/
}

//----- (004A172E) --------------------------------------------------------
int CD3DRenderer_LockFrontBuffer(struct CD3DRenderer *_this, void **ppOutSurfacePtr, unsigned int *pOutSurfaceWidth)
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
HRESULT CD3DRenderer_EndScene(struct CD3DRenderer *_this)
{
 HRESULT hr;
 char    local_0[128];

  if (_this->bSceneBegun)
  {
   _this->bSceneBegun--;
    if (!_this->bSceneBegun)
    {
      if (_this->dword_040088)
      {
        if (_this->dword_040108)
        {
          _this->pTargetSurface = 0;
          _this->uTargetSurfacePitch = 0;
          _this->dword_000018 = 0;
          runtime_error;
          //hr = (**(_DWORD **)(_this->dword_040098) + 128)(
          //       *(_DWORD *)(_this + 262296),
          //       0);
          return CheckHRESULT(local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16blt.cpp", 207, 0);
        }
      }
      else
      {
        _this->pTargetSurface = 0;
        _this->uTargetSurfacePitch = 0;
        _this->dword_000018 = 0;
        return CD3DRenderer_UnlockBackBuffer(_this);
      }
    }
  }
  return E_FAIL;
}

//----- (004A16E1) --------------------------------------------------------
void *CD3DRenderer_UnlockBackBuffer(struct CD3DRenderer *_this)
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

//----- (004A5BE3) --------------------------------------------------------
void CD3DRenderer_DrawRGBTexture(struct CD3DRenderer *_this, unsigned int uX, unsigned int uY, struct RGBTexture *pTexture)
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

 v5 = pTexture->uWidth;
 v24 = pTexture->uHeight;
 pSurfacePtr = (unsigned int *)(_this->pTargetSurface) + (uX + uY * _this->uTargetSurfacePitch);
 v6 = pTexture->pPixels;
 v20 = v5;
 v19 = v5;

 if (_this->dword_040104)
 {
  v7 = _this->dword_0400F8;
  if (uX < v7)
  {
   v8 = v7 - uX;
   v9 = uX - v7;
   v5 += v9;
   v6 += v8;
   v20 += v9;
   pSurfacePtr += v8;
  }

  v10 = _this->dword_0400F4;
  if (uY < v10)
  {
   v11 = v10 - uY;
   v6 += v19 * v11;
   v24 += uY - _this->dword_0400F4;
   v5 = v20;
   pSurfacePtr += _this->uTargetSurfacePitch * v11;
  }

  v12 = _this->dword_0400F8;
  if ( v12 < uX)
    v12 = uX;

  v13 = _this->dword_040100;
  if (v5 + v12 > v13)
  {
   v14 = _this->dword_0400F8;
   if (v14 < uX)
     v14 = uX;
   v5 = v13 - v14;
  }

  v15 = _this->dword_0400F4;
  if (v15 < uY)
    v15 = uY;

  v21 = _this->dword_0400FC;
  if (v15 + v24 > v21)
  {
   v16 = _this->dword_0400F4;
   if (v16 < uY)
     v16 = uY;
   v24 = v21 - v16;
  }
 }



 pSurfacePtr = (unsigned int *)(_this->pTargetSurface);
 for (y = 0; y < pTexture->uHeight; ++y)
   memcpy(pSurfacePtr + (y + uY) * _this->uTargetSurfacePitch + uX, pTexture->pPixels + y * pTexture->uWidth, pTexture->uWidth * 4);

 /*
 if (v24 > 0)
 {
  v22 = v24;
  v23 = (v19 - v5);
  do
  {
   for (x = 0; x < v5; ++x)
   {
    uColor = *v6 & 0x001F;
    uColor |= ((unsigned int)(*v6) & 0x07E0 >> 5) << 8;
    v6++;
    *pSurfacePtr++ = uColor;
   }

   v6 += v23;
   v18 = v22-- == 1;
   pSurfacePtr += (_this->uTargetSurfacePitch - v5);
  }
  while ( !v18 );
 }*/
}

//----- (MM7.exe::0049FFFB) --------------------------------------------------------
int CD3DRenderer_Initialize(struct CD3DRenderer *_this, HWND hwnd)
{
  int v3; // esi@1
  int v4; // eax@2
  int v5; // eax@3
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
  sub_49FE05(unknown_libname_107, _this);
  _this->hWnd = hwnd;
  CD3DRenderer_Initialize_ZBuffer(_this);

  if (_this->bUseDirect3D)
  {
    v4 = malloc(0x148u);
    v42 = v4;
    v43 = 0;
    if ( v4 )
      v5 = sub_49DC58(v4);
    else
      v5 = 0;
    v6 = *(_DWORD *)(v3 + 8);
    v43 = -1;
    *(_DWORD *)(v3 + 262280) = v5;
    v7 = *(_DWORD *)(v5 + 28);
    if ( *(_DWORD *)(v7 + 40 * v6) )
    {
      v8 = sub_49DE14(v5, v6, 0, hwnd);
      *(_DWORD *)(v3 + 12) = *(_DWORD *)(v3 + 8);
    }
    else
    {
      if ( *(_DWORD *)(v7 + 40) )
      {
        v8 = sub_49DE14(v5, 1, 0, hwnd);
        *(_DWORD *)(v3 + 12) = 1;
      }
      else
      {
        if ( !*(_DWORD *)v7 )
          erroneous_printf("There aren't any D3D devices to create.");
        v8 = sub_49DE14(v5, 0, 0, hwnd);
        *(_DWORD *)(v3 + 12) = 0;
      }
    }
    if ( !v8 )
      erroneous_printf("D3Drend->Init failed.");
    v10 = *(_DWORD *)(v3 + 262280);
    *(_DWORD *)(v3 + 262292) = *(_DWORD *)(v10 + 44);
    *(_DWORD *)(v3 + 262288) = *(_DWORD *)(v10 + 48);
    *(_DWORD *)(v3 + 262284) = *(_DWORD *)(v10 + 32);
    v9 = sub_49E444((void *)v10);
    if ( v9 & 1 )
    {
      hwnd = *(_DWORD *)(v3 + 262280);
      if ( hwnd )
      {
        v11 = sub_49DC90(hwnd);
        sub_4CA32D(v11, hwnd);
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
        sub_4CA32D(v12, hwnd);
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
        sub_4CA32D(v13, hwnd);
      }
      *(_DWORD *)(v3 + 262280) = 0;
      *(_DWORD *)(v3 + 262292) = 0;
      *(_DWORD *)(v3 + 262288) = 0;
      *(_DWORD *)(v3 + 262284) = 0;
      erroneous_printf("Direct3D renderer:  The device doesn't support non-square textures.");
    }
    *(_BYTE *)(v3 + 1062492) = ~(unsigned __int8)((unsigned int)v9 >> 6) & 1;
    *(_DWORD *)(v3 + 1062472) = sub_49E79F();
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
    sub_49FFD7(v3);
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
    CD3DRenderer_CreateDirectDraw(_this);
    CD3DRenderer_SetCooperativeLevel(_this, _this->hWnd, true);
    CD3DRenderer_SetDisplayMode(_this, 1280, 1024, 16);
    CD3DRenderer_CreatePrimarySurface(_this);
    v18 = 1;
  }
  _this->ddpfPrimarySurface.dwSize = sizeof(DDPIXELFORMAT);
  (_this->pdds4_FrontBuffer->lpVtbl->GetPixelFormat)(_this->pdds4_FrontBuffer, &_this->ddpfPrimarySurface);

  CD3DRenderer_sub_4A0EB6(_this);
  CD3DRenderer_sub_49EBF1(_this);
  if (_this->dword_040088)
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
  dword_AD4730 |= 2u;
  flt_6BE3A0 = 0.55f;
  class28_fn2(class28_global, 36044);
  return v18;
}

//----- (004A0E97) --------------------------------------------------------
void CD3DRenderer_sub_4A0E97(struct CD3DRenderer *_this, int a2, int a3, int a4, int a5)
{
 _this->dword_00001C = a2;
 _this->dword_000020 = a3;
 _this->dword_000024 = a4;
 _this->dword_000028 = a5;
}

//----- (MM7.exe::0049FDBF) --------------------------------------------------------
int CD3DRenderer_Initialize_ZBuffer(struct CD3DRenderer *_this)
{
 signed int result; // eax@1
 int *v3; // edi@2

 result = 0;
 if (!_this->pZBuffer)
 {
  _this->pZBuffer = class23_AllocatedNamedBuffer(class23_instance, 0, 640 * 480 * 4, "Z Buf.");
  result = -65536;
  _this->dword_040034 = _this->pZBuffer;
  memset(_this->pZBuffer, -65536, 640 * 480 * 4);
 }
 return result;
}

//----- (MM7.exe::004A10E4) --------------------------------------------------------
int CD3DRenderer_CreateDirectDraw(struct CD3DRenderer *_this)
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
void *CD3DRenderer_SetCooperativeLevel(struct CD3DRenderer *_this, HWND hWnd, int bFullscreen)
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
void *CD3DRenderer_SetDisplayMode(struct CD3DRenderer *_this, unsigned int uWidth, unsigned int uHeight, unsigned int uBPP)
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
void *CD3DRenderer_CreatePrimarySurface(struct CD3DRenderer *_this)
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
HRESULT CD3DRenderer_GetPrimarySurfacePixelFormat(struct CD3DRenderer *_this, DDPIXELFORMAT *pddpf)
{
 IDirectDrawSurface *pdds;

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
   pdds = _this->pdds4_FrontBuffer;
 else
   pdds = _this->pdds2_FrontBuffer;

 return (pdds->lpVtbl->GetPixelFormat)(pdds, pddpf);
}

//----- (MM7.exe::004A5BB6) --------------------------------------------------------
void CD3DRenderer_sub_4A5BB6(struct CD3DRenderer *_this)
{
 _this->dword_0400F4 = 0;
 _this->dword_0400F8 = 0;
 _this->dword_0400FC = 480;
 _this->dword_0400D0 = 640;
 _this->dword_0400D4 = 1;
}

//----- (004A0EB6) --------------------------------------------------------
void *CD3DRenderer_sub_4A0EB6(struct CD3DRenderer *_this)
{
  void *result; // eax@1
  int v2; // edx@1
  signed int v3; // ecx@1
  signed int v4; // ecx@5
  int v5; // esi@5
  int v6; // edx@9
  signed int v7; // ecx@9
  int v8; // ecx@13

  result = _this;
  v3 = 0;
  v2 = _this->ddpfPrimarySurface.dwRBitMask;
  _this->dword_0400CC = 0;
  _this->dword_0400D0 = 0;
  _this->dword_0400D4 = 0;
  do
  {
    if ((1 << v3) & v2)
      ++_this->dword_0400CC;
    ++v3;
  }
  while (v3 < 16);
  v5 = _this->ddpfPrimarySurface.dwGBitMask;
  v4 = 0;
  do
  {
    if ((1 << v4) & v5)
      ++_this->dword_0400D0;
    ++v4;
  }
  while (v4 < 16);
  v6 = _this->ddpfPrimarySurface.dwBBitMask;
  v7 = 0;
  do
  {
    if ((1 << v7) & v6)
      ++_this->dword_0400D4;
    ++v7;
  }
  while (v7 < 16);

  v8 = _this->ddpfPrimarySurface.dwRBitMask;
  _this->dword_0400D8 = v8;
  _this->dword_0400DC = v5;
  _this->dword_0400E0 = v6;

  return result;
}

//----- (MM7.exe::0049EBF1) --------------------------------------------------------
int CD3DRenderer_sub_49EBF1(struct CD3DRenderer *_this)
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
  v2 = 1 << _this->dword_0400CC;
  v3 = 1 << _this->dword_0400D0;
  v4 = 1 << _this->dword_0400D4;
  v10 = 1 << _this->dword_0400CC;
  v9 = 1 << _this->dword_0400D0;
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
            v5 = _this->dword_0400D4;
            v6 = v5 + _this->dword_0400D0;
            v7 = (v13 >> 1) + (v11 >> 1 << v6) + (i >> 1 << _this->dword_0400D4);
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



extern int nWidth; // idb
extern int nHeight; // idb
extern int X; // idb
extern int Y; // idb

//----- (MM7.exe::0049ED18) --------------------------------------------------------
int CD3DRenderer_ClearBackBufferAndPresent(struct CD3DRenderer *_this)
{
 IDirectDrawSurface *v1; // eax@3
 HRESULT hr;
 DDBLTFX ddblt;
 RECT    rcDst;

 rcDst.left = X;
 rcDst.top = Y;
 rcDst.right = X + nWidth;
 rcDst.bottom = Y + nHeight;

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
 return CD3DRenderer_Present(pD3DRenderer);
}

//----- (MM7.exe::0049FC37) --------------------------------------------------------
int CD3DRenderer_Present(struct CD3DRenderer *_this)
{
  struct tagRECT Rect; // [sp+8h] [bp-28h]@11
  struct tagRECT rc;
  struct tagPOINT Point; // [sp+28h] [bp-8h]@11


 if (pD3DRenderer->dword_040088 && !_this->dword_040110)
   return false;

 (_this->pfn_1036C0)();

 if (_this->dword_040088)
 {
  if (dword_720010)
    sub_46BAEC(dword_720010);
  sub_49E54D(_this->dword_040088, 0);
  if (dword_720010)
    sub_46BB0A(dword_720010);
 }
 else
 {
  rc.left = 0;
  rc.top = 0;
  rc.right = 640;
  rc.bottom = 480;

  CD3DRenderer_RestoreFrontBuffer(_this);
  if (_this->dword_040058)
  {
   GetClientRect(_this->hWnd, &Rect);
   Point.y = 0;
   Point.x = 0;
   ClientToScreen(_this->hWnd, &Point);
   OffsetRect(&Rect, Point.x, Point.y);
   sub_4A1884(_this, &Rect, &rc);
  }
  else CD3DRenderer_PresentBackBuffer(_this, 0, 0, &rc);
 }
 return true;
}

//----- (004A17C7) --------------------------------------------------------
void *CD3DRenderer_UnlockFrontBuffer(struct CD3DRenderer *_this)
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
HRESULT CD3DRenderer_PresentBackBuffer(struct CD3DRenderer *_this, int a2, int a3, RECT *pRect)
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
HRESULT CD3DRenderer_RestoreFrontBuffer(struct CD3DRenderer *_this)
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
int __stdcall LockSurface_DDraw4(struct IDirectDrawSurface4 *pdds4, DDSURFACEDESC2 *pddsd2, unsigned int uLockFlags)
{
 char    local_0[128];
 HRESULT hr;

 hr = (pdds4->lpVtbl->Lock)(pdds4, 0, pddsd2, uLockFlags, 0);
 if (hr == DDERR_SURFACELOST)
 {
  if (dword_720010)
    sub_46B14F(dword_720010);

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

  if (pD3DRenderer->dword_040088)
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













unsigned int RGBTexture_LoadFromCBM(struct RGBTexture *_this, const wchar_t *pFilename)
{
 wchar_t      pFilepath[256];
 unsigned int uCBMWdith,
              uCBMHeight;

 wsprintfW(pFilepath, L".\\Data\\Icons\\%s.cbm", pFilename);
 LoadCBM(pFilepath, &uCBMWdith, &uCBMHeight, &_this->pPixels);

 _this->uWidth = uCBMWdith;
 _this->uHeight = uCBMHeight;
 _this->uNumPixels = uCBMWdith * uCBMHeight;

 return true;
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
  //size_t Count; // [sp+A0h] [bp-4h]@4
  //unsigned int v27; // [sp+ACh] [bp+8h]@5
 wchar_t      pFilepath[256];
 unsigned int uTextureID;
/*
 class18_ctor(&class18_obj);
 f = class17_FindContainer(pClass17_Icons_LOD, pContainerName, 0);
 if (!f)
 {
  sprintfex(ExistingFileName, "Unable to load %s", pContainerName);
  erroneous_printf(ExistingFileName);
 }

 locked_fread(&class18_obj, 1, 0x30, f);
 if (class18_obj.uDecompressedSize)
 {
  pPCXData = malloc(class18_obj.uDecompressedSize);
  v6 = class23_AllocatedNamedBuffer(class23_instance, 0, class18_obj.uCompressedSize, class18_obj.sContainerName);
  locked_fread(v6, 1, class18_obj.uCompressedSize, f);
  maybe_decompress_file(pPCXData, &class18_obj.uDecompressedSize, v6, class18_obj.uCompressedSize);
  class18_obj.uCompressedSize = class18_obj.uDecompressedSize;
  class23_fn1(class23_instance, v6);
 }
 else
 {
  pPCXData = malloc(class18_obj.uCompressedSize);
  locked_fread(pPCXData, 1, class18_obj.uCompressedSize, f);
 }

  memcpy(local_2, pPCXData, 0x10u);
  memcpy(local_1, (char *)pPCXData + 16, 0x30u);
  memcpy(local_2 + 16, (char *)pPCXData + 64, 6u);

  if ( local_2[3] != 8 )
    return 3;

  v8 = *(int *)(local_2 + 8) - *(int *)(local_2 + 4) + 1;
  v9 = *(int *)(local_2 + 10) - *(int *)(local_2 + 6) + 1;

  _this->uWidth = v8 & 0xFFFF;
  _this->uHeight = v9 & 0xFFFF;

  _this->uNumPixels = (signed __int16)v8 * (signed __int16)v9;

  if (_this->pPixels)
  {
   if (a3)
     goto LABEL_14;
   class23_fn1(class23_instance, _this->pPixels);
  }
  if (!a3)
  {
   _this->pPixels = class23_AllocatedNamedBuffer(class23_instance, _this->pPixels, 2 * _this->uNumPixels + 4, "16bit PCX");
   goto LABEL_17;
  }

LABEL_14:
  if ( a3 != 2 )
    goto LABEL_17;
  _this->pPixels = malloc(2 * _this->uNumPixels + 4);
  _this->dword_000020 |= 1;

LABEL_17:
 if (!_this->pPixels)
   return 2;

 class33_DecodePCX(_this, pPCXData, _this->pPixels, _this->uWidth);
 call_delete(0, pPCXData);
*/
 wsprintfW(pFilepath, L"%S.cbm", pContainerName);
 uTextureID = class17_LoadTextureFromCBM(pClass17_Icons_LOD, pFilepath);

 _this->pPixels = pClass17_Icons_LOD->aLODHeaders[uTextureID].pTruecolorPixels;
 _this->uWidth = pClass17_Icons_LOD->aLODHeaders[uTextureID].uTextureWidth;
 _this->uHeight = pClass17_Icons_LOD->aLODHeaders[uTextureID].uTextureHeight;
 _this->uNumPixels = _this->uWidth * _this->uHeight;

 return 0;
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
         *v12++ = pD3DRenderer->dword_0400D8 & (v15 << (pD3DRenderer->dword_0400D0 + (_BYTE)pD3DRenderer->dword_0400CC + (_BYTE)pD3DRenderer->dword_0400D4 - 8));
         if (v13 == *(short *)(local_2 + 18))
           v12 += (uWidth - *(short *)(local_2 + 18)) - 1;
        }
        while (v34-- != 1);
       }
      }
      else
      {
       v7 &= 0xFFFF00FF;
       v7 = pD3DRenderer->dword_0400D8 & (v7 << (pD3DRenderer->dword_0400D0 + (_BYTE)pD3DRenderer->dword_0400CC + (_BYTE)pD3DRenderer->dword_0400D4 - 8));
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
        *v17++ |= (_WORD)pD3DRenderer->dword_0400DC & (unsigned __int16)(v19 << (pD3DRenderer->dword_0400D0
                                                                                  + (_BYTE)pD3DRenderer->dword_0400D4
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
      v7 = pD3DRenderer->dword_0400DC & (v7 << (pD3DRenderer->dword_0400D0 + (_BYTE)pD3DRenderer->dword_0400D4 - 8));
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
        *v21++ |= v39 >> (8 - pD3DRenderer->dword_0400D4);
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
      *v21++ |= v22 >> (8 - pD3DRenderer->dword_0400D4);
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

 _this->dword_000020 = 0;
 _this->dword_000024 = 0;
 return _this;
}
