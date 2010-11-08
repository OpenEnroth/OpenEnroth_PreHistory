#include "defs.h"
#include "_lod.h"
#include "c18.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "data.h"

#include "RenderD3D3.h"


#pragma comment(lib, "legacy dx\\lib\\ddraw.lib")
#pragma comment(lib, "legacy dx\\lib\\dxguid.lib")
#pragma comment(lib, "legacy dx\\lib\\dinput8.lib")

#define FI16_565_RED_MASK		0xF800
#define FI16_565_GREEN_MASK		0x07E0
#define FI16_565_BLUE_MASK		0x001F
#define FI16_565_RED_SHIFT		11
#define FI16_565_GREEN_SHIFT	5
#define FI16_565_BLUE_SHIFT		0

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
  _this->pSriteNames[i] = (unsigned char *)malloc(20);  //operator new(0x14u)
  locked_fread(_this->pSriteNames[i], 1, 20, _this->pHWLFile);
 }

 locked_fread(_this->pSpriteFileOffsets, 4, _this->uNumElements, _this->pHWLFile);
 _this->dword_061A90 = 0;
 return true;
}

//----- (MM7.exe::0049E992) --------------------------------------------------------
BaseRender::BaseRender()
{
  int v1; // eax@1
  char v3; // zf@1


 this->pdd4 = 0;
 this->pdds4_FrontBuffer = 0;
 this->pdds4_BackBuffer = 0;
 this->dword_040098 = 0;
 this->pdd2 = 0;
 this->pdds2_FrontBuffer = 0;
 this->pdds2_BackBuffer = 0;
 this->dword_0400A8 = 0;

 Render_HWLContainer_ctor(&this->struct_040114);
 Render_HWLContainer_ctor(&this->struct_0A1BAC);

 this->dword_040054 = 0;
 this->dword_040058 = 1;
 this->bUseDirect3D = ReadWindowsRegistry("Use D3D", false);
 this->bStartInWindow = ReadWindowsRegistry("startinwindow", false);
 v1 = ReadWindowsRegistry("D3D Device", true);
 v3 = this->bStartInWindow == 0;

 this->bStartInWindow = v3 && v1 != 1;
 this->uDesiredDirect3DDevice = v1;

  //force d3d
 this->bUseDirect3D = true;

 this->dword_000010 = 640;
 this->dword_000014 = 480;
 this->dword_00001C = 0;
 this->dword_000020 = 0;
 this->dword_000024 = 639;
 this->dword_000028 = 479;

 this->dword_04002C = 0;
 this->dword_040030 = 0;
 this->pActiveZBuffer = 0;
 this->pDefaultZBuffer = 0;
 this->dword_04003C = (int)&unk_4EED80;
 this->dword_040040 = dword_4EED78;

 this->dword_040044 = 2;
 this->dword_040048 = 6;

 this->pRenderD3D3 = 0;

 this->bSceneBegun = 0;

 this->pTargetSurface = 0;
 this->uTargetSurfacePitch = 0;

 this->uClipRectY = 0;
 this->uClipRectX = 0;
 this->uClipRectW = 480;
 this->uClipRectZ = 640;
 this->dword_040104 = 1;

 this->dword_040108 = 0;
 this->uD3D3SceneBegun = 0;
 this->dword_040110 = 0;

 this->bUseColoredLights = ReadWindowsRegistry("Colored Lights", false);
 this->bRequiredTextureStagesAvailable = false;
 this->bTinting = true;
 this->uLevelOfDetail = ReadWindowsRegistry("Detail Level", 1);

 this->byte_103668[0] = 0;

 this->dword_1036B8 = 0;
 this->dword_1036BC = 0;
 Render_HWLContainer_LoadHWLHeaders(&this->struct_040114, "data\\d3dbitmap.hwl");
 Render_HWLContainer_LoadHWLHeaders(&this->struct_0A1BAC, "data\\d3dsprite.hwl");

 this->uNumBillboardsToDraw = 0;
}

//----- (MM7.exe::0049FBCD) --------------------------------------------------------
void Render_ClearTarget(struct BaseRender *_this, unsigned int uColor)
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
unsigned int RenderDirect3D3::BeginScene()
{
  int v1; // eax@1
  //int Dst; // [sp+Ch] [bp-7Ch]@4
  //int v6; // [sp+1Ch] [bp-6Ch]@5
  //int v7; // [sp+30h] [bp-58h]@5
 char local_0[124];
 DDSURFACEDESC2 ddsd2;

 v1 = this->bSceneBegun++;
 if (!v1)
 {
   if (this->dword_040108)
   {
    memset(&ddsd2, 0, sizeof(DDSURFACEDESC2));
    ddsd2.dwSize = sizeof(DDSURFACEDESC2);
    LOBYTE(v1) = LockSurface_DDraw4(this->dword_040098, &ddsd2, 2049);
    if ((_BYTE)v1)
    {
     this->pTargetSurface = (unsigned int *)ddsd2.lpSurface;
     this->uTargetSurfacePitch = ddsd2.lPitch / (ddsd2.ddpfPixelFormat.dwRGBBitCount / 8);
     this->dword_000018 = this->uTargetSurfacePitch;
     goto LABEL_11;
    }

    this->bSceneBegun--;
    return v1;
   }


LABEL_11:
  LOBYTE(v1) = Render_RestoreFrontBuffer(this);
 }



 int v4, result;
  result = this->uD3D3SceneBegun++;
  if ( !result )
  {
      RenderD3D3_ClearTarget(this->pRenderD3D3, 1, result, 1, 1.0);
      this->uNumBillboardsToDraw = 0;
      this->pRenderD3D3->pDevice->BeginScene();

      if ( dword_6BE360 == 2 )
        v4 = sub_47C370();
      else
        v4 = 0;
      if ( v4 & 0xFF000000 )
      {
        this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_FOGENABLE, 1);
        this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_FOGCOLOR, v4 & 0xFFFFFF);
        this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_FOGTABLEMODE, 0);
        this->bUsingSpecular = true;
      }
      else
      {
        this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_FOGENABLE, 0);
        this->bUsingSpecular = false;
      }
    }








 return v1;
}

//----- (004A0BEE) --------------------------------------------------------
char Render_FillRect(struct BaseRender *_this, unsigned int uX, unsigned int uY, unsigned int uZ, unsigned int uW, unsigned int uColor)
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
  
  v36 = (int)_this;
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
int Render_LockBackBuffer(struct BaseRender *_this, void **ppOutSurfacePtr, unsigned int *pOutSurfaceWidth)
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
    LockSurface_DDraw2(_this->pdds2_BackBuffer, (DDSURFACEDESC *)&Dst, 1);
    *ppOutSurfacePtr = (void *)v10;
    *pOutSurfaceWidth = v8;
  }

 return *pOutSurfaceWidth;
}

//----- (004A5B81) --------------------------------------------------------
void Render_Set2DClippingRect(struct BaseRender *_this, unsigned int uX, unsigned int uY, unsigned int uZ, unsigned int uW)
{
 _this->uClipRectX = uX;
 _this->uClipRectY = uY;
 _this->uClipRectZ = uZ;
 _this->uClipRectW = uW;
 _this->dword_040104 = 1;
}

extern class cTexture pending_texture;
void Render_DrawIndexedTextureHandle(struct BaseRender *_this, unsigned int uX, unsigned int uY, unsigned int uTextureID)
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
 cTexture *pTexture;

 if (uTextureID != -1)
   pTexture = &LODFile_Icons_LOD.aLODHeaders[uTextureID];
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


 #define OLD_CODE
//----- (004A5EB2) --------------------------------------------------------
void Render_DrawIndexedTexture(struct BaseRender *_this, unsigned int uX, unsigned int uY, cTexture *pTexture)
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
 unsigned int  y, i,
               x;
 unsigned int  uSrcColor,
               uDstColor;
#ifdef OLD_CODE
 unsigned short	packedPixel;
 unsigned char unpackedPixels[4];
#endif
 if (!_this->bSceneBegun || !pTexture)
   return;


 pSurfacePtr = (unsigned int *)(_this->pTargetSurface);
#ifdef OLD_CODE
 //new unpack paletted texture code
 if	(!pTexture->pTruecolorPixels)
	 {
	 if (!pTexture->pPalette)
		 return;
	  pTexture->pTruecolorPixels=(unsigned int*) malloc(pTexture->uTextureWidth*pTexture->uTextureHeight*4);
	  for(i=0;i<pTexture->uTextureWidth*pTexture->uTextureHeight; i++)
		  {
			packedPixel=pTexture->pPalette[pTexture->pIndexedPixels[i]];
			unpackedPixels[2]=(BYTE)((((packedPixel & FI16_565_RED_MASK) >> FI16_565_RED_SHIFT) * 0xFF) / 0x1F);
			unpackedPixels[1]=(BYTE)((((packedPixel & FI16_565_GREEN_MASK) >> FI16_565_GREEN_SHIFT) * 0xFF) / 0x3F);
			unpackedPixels[0]= (BYTE)((((packedPixel & FI16_565_BLUE_MASK) >> FI16_565_BLUE_SHIFT) * 0xFF) / 0x1F);
			unpackedPixels[3]=  0xFF;
			pTexture->pTruecolorPixels[i]=*(DWORD*)&unpackedPixels[0];
		  }
	 }
#endif

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
void Render_DrawText(struct BaseRender *_this, unsigned int uOutX, unsigned int uOutY,
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
void Render_DrawTransparentTexture(struct BaseRender *_this, unsigned int uX, unsigned int uY, cTexture *pTexture)
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
 unsigned int  x, y, i;
 unsigned int  uSrcColor,
               uDstColor,
               uAlpha;
 #ifdef OLD_CODE
  unsigned short	packedPixel;
 unsigned char unpackedPixels[4];
 FILE *f;
#endif
 if (!_this->bSceneBegun || !pTexture)
   return;

 pSurfacePtr = (unsigned int *)(_this->pTargetSurface);
#ifdef OLD_CODE
 //new unpack paletted texture code
 if	(!pTexture->pTruecolorPixels)
	 {
	 
	  pTexture->pTruecolorPixels=(unsigned int*) malloc(pTexture->uTextureWidth*pTexture->uTextureHeight*4);
	  if (!pTexture->pPalette)
			return;
		 
	  for(i=0;i<pTexture->uTextureWidth*pTexture->uTextureHeight; i++)
		  {
		   if ( pTexture->pIndexedPixels[i]==0)
				 *(unsigned int*)&unpackedPixels[0]=0;
		   else
			   {
			packedPixel=pTexture->pPalette[pTexture->pIndexedPixels[i]];
			unpackedPixels[2]=(BYTE)((((packedPixel & FI16_565_RED_MASK) >> FI16_565_RED_SHIFT) * 0xFF) / 0x1F);
			unpackedPixels[1]=(BYTE)((((packedPixel & FI16_565_GREEN_MASK) >> FI16_565_GREEN_SHIFT) * 0xFF) / 0x3F);
			unpackedPixels[0]= (BYTE)((((packedPixel & FI16_565_BLUE_MASK) >> FI16_565_BLUE_SHIFT) * 0xFF) / 0x1F);
			unpackedPixels[3]=  0xFF;
			   }
			pTexture->pTruecolorPixels[i]=*(unsigned int*)&unpackedPixels[0];
		  }
	  /*
	    	f=fopen(pTexture->sContainerName,"wb");
		if(f)
			{
			fwrite(pTexture->pIndexedPixels,1,pTexture->uTextureSize, f);
			fclose(f);
			}	*/
	
	 }
#endif

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

#undef OLD_CODE
void Render_DrawTransparentRect(struct BaseRender *_this, unsigned int uOutX, unsigned int uOutY,
                                      unsigned int uSrcX, unsigned int uSrcY, unsigned int uSrcWidth, unsigned int uSrcHeight,
                                      cTexture *pTexture)
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
int Render_LockFrontBuffer(struct BaseRender *_this, void **ppOutSurfacePtr, unsigned int *pOutSurfaceWidth)
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
unsigned int RenderDirect3D3::EndScene()
{
 if (this->pRenderD3D3)
   return RenderD3D3_EndScene(this->pRenderD3D3);




 if (!this->bSceneBegun)
   return E_FAIL;

 this->bSceneBegun--;
 this->pTargetSurface = 0;
 this->uTargetSurfacePitch = 0;
 this->dword_000018 = 0;
 Render_UnlockBackBuffer(this);
}

//----- (004A16E1) --------------------------------------------------------
void *Render_UnlockBackBuffer(struct BaseRender *_this)
{
 IDirectDrawSurface *v1;
 HRESULT             hr;
 char                local_0[128];


 if (dword_F79D7C != 2 || dword_F79D70 != 4)
   v1 = (IDirectDrawSurface *)_this->pdds4_BackBuffer;
 else
   v1 = (IDirectDrawSurface *)_this->pdds2_BackBuffer;

 hr = _this->pdds4_BackBuffer->Unlock(0);
 return CheckHRESULT((void **)local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", __LINE__, 0);
}



void Render_DrawRGBTexture_New(struct BaseRender *_this, unsigned int uX, unsigned int uY, unsigned int uTextureID)
{
 unsigned int   *pSurfacePtr;
 unsigned int    uColor;
 int             x, y;
cTexture *pTexture;

 if (!_this->bSceneBegun)
   return;

 if (uTextureID == -1)
   return;

 pTexture = &LODFile_Icons_LOD.aLODHeaders[uTextureID];


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
void Render_DrawRGBTexture(struct BaseRender *_this, unsigned int uX, unsigned int uY, struct RGBTexture *pTexture)
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


//----- (004A05F3) --------------------------------------------------------
unsigned int RenderDirect3D3::Initialize(OSWindow *pOutputWindow)
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
  v2 = (int)this;
  flt_6BE3A0 = 0.55000001;

  
 pTargetWindow = pOutputWindow;

 Viewport_fn2(pOldViewport, 36044);

 this->dword_040108 = 0;
 this->dword_040110 = 0;
 sub_49FE05(this);

 this->pdd4 = 0;
 this->pdds4_FrontBuffer = 0;
 this->pdds4_BackBuffer = 0;
 this->dword_040098 = 0;

 Render_Initialize_ZBuffer(this);

 if (this->bUseDirect3D)
 {
  this->pRenderD3D3 = new RenderD3D3;
  v43 = (int)this->pRenderD3D3;
  v44 = 0;
  if (this->pRenderD3D3)
    RenderD3D3_FindAvailableDevices(this->pRenderD3D3);

    v44 = -1;
    v7 = (int)this->pRenderD3D3->pAvailableDevices;
    if (this->pRenderD3D3->pAvailableDevices[this->uDesiredDirect3DDevice].bDeviceIsValid &&
        this->uDesiredDirect3DDevice != 1)
    {
     v8 = RenderD3D3_Initialize(this->pRenderD3D3, this->uDesiredDirect3DDevice, true, pTargetWindow->GetAPIHandle());
     this->uAcquiredDirect3DDevice = this->uDesiredDirect3DDevice;
    }
    else if (this->pRenderD3D3->pAvailableDevices[0].bDeviceIsValid)
    {
      v8 = RenderD3D3_Initialize(this->pRenderD3D3, 0, true, pTargetWindow->GetAPIHandle());
     this->uAcquiredDirect3DDevice = 0;
    }
    else
      erroneous_printf("There aren't any D3D devices to init.");

    if (!v8)
      erroneous_printf("D3Drend->Init failed.");

    this->pdd4 = this->pRenderD3D3->pHostInterface;
    this->pdds4_FrontBuffer = this->pRenderD3D3->pFontBuffer;
    this->pdds4_BackBuffer = this->pRenderD3D3->pBackBuffer;
    this->dword_040098 = 0;

    uDeviceCaps = RenderD3D3_GetDeviceCaps(this->pRenderD3D3);
    if (uDeviceCaps & CAPS_NO_CAPS)
    {
      v43 = *(_DWORD *)(v2 + 262280);
      if ( v43 )
      {
        v11 = sub_49DC90(v43);
        operator_delete((void *)v43);
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
        operator_delete((void *)v43);
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
        operator_delete((void *)v43);
      }
      *(_DWORD *)(v2 + 262280) = 0;
      *(_DWORD *)(v2 + 262292) = 0;
      *(_DWORD *)(v2 + 262288) = 0;
      *(_DWORD *)(v2 + 262284) = 0;
      erroneous_printf("Direct3D renderer:  The device doesn't support non-square textures.");
    }

  this->dword_10365C |= ~(unsigned __int8)((unsigned int)uDeviceCaps >> 6) & 1;
  this->bRequiredTextureStagesAvailable = Render_ValidateTextureStages();

  memset(&d3ddd1, 0, sizeof(D3DDEVICEDESC));
  d3ddd1.dwSize = sizeof(D3DDEVICEDESC);

  memset(&d3ddd2, 0, sizeof(D3DDEVICEDESC));
  d3ddd2.dwSize = sizeof(D3DDEVICEDESC);

  hr = this->pRenderD3D3->pDevice->GetCaps(&d3ddd1, &d3ddd2);
  CheckHRESULT((void **)&v43, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", __LINE__, 0);

  v14 = d3ddd1.dwMinTextureWidth;
  if (d3ddd1.dwMinTextureWidth >= d3ddd1.dwMinTextureHeight)
    v14 = d3ddd1.dwMinTextureHeight;
  this->uMinDeviceTextureDim = v14;

  v17 = d3ddd1.dwMaxTextureWidth;
  if (d3ddd1.dwMaxTextureWidth < d3ddd1.dwMaxTextureHeight)
    v17 = d3ddd1.dwMaxTextureHeight;
  this->uMaxDeviceTextureDim = v17;

  Render_sub_49FFD7(this);
  this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_ZENABLE, 1);
  this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_ZWRITEENABLE, 1);
  this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_ZFUNC, D3DCMP_LESS);
  this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_SPECULARENABLE, 0);
  this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_COLORKEYENABLE, 0);
  this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_CULLMODE, D3DCULL_NONE);

  this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_MAGFILTER, 2);
  this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_MINFILTER, 2);
  this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_MIPFILTER, 3);
  this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, 2);
  this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, 0);
  this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, 2);
  this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, 2);
  this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, 0);
  this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_COLOROP, 4);
 }

 this->ddpfPrimarySurface.dwSize = sizeof(DDPIXELFORMAT);
 Render_GetPrimarySurfacePixelFormat(this, &this->ddpfPrimarySurface);
 Render_sub_4A0EB6(this);
 Render_sub_49EBF1(this);

 if (!this->pRenderD3D3)
 {
  this->pfn_1036C0 = (int (*)())nullsub_1;
  this->dword_040058 = 1;
  this->hWnd = pTargetWindow->GetAPIHandle();
  return 0;
 }

 this->dword_040108 = sub_49E756(this->pdd4);
 if (this->uAcquiredDirect3DDevice != 1)
   this->dword_040108 = 0;

 if (this->dword_040108)
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
    CheckHRESULT((void **)&v43, v21, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 1783, 0);
    *(_DWORD *)(v2 + 1062592) = (int)sub_4A57E9;
    *(_DWORD *)(v2 + 262416) = 1;
    *(_DWORD *)(v2 + 262232) = 1;
    this->hWnd = pTargetWindow->GetAPIHandle();
    return 0;
 }
 
 this->pTargetSurface = 0;
 this->ptr_0400E8 = (int)malloc(640 * 480 * 4 + 32);
 if (this->ptr_0400E8)
 {
  memset(&ddsd2, 0, sizeof(DDSURFACEDESC2));
  ddsd2.dwSize = sizeof(DDSURFACEDESC2);

  if (LockSurface_DDraw4(this->pdds4_BackBuffer, &ddsd2, 1))
  {
   pD3DRenderer->pdds4_BackBuffer->Unlock(0);

      v23 = (unsigned int)ddsd2.lpSurface & 7;
      v25 = this->ptr_0400E8 & 7;
      if ( v25 == v23 )
        this->pTargetSurface = (unsigned int *)this->ptr_0400E8;
      else
      {
        if ( v25 >= v23 )
          this->pTargetSurface = (unsigned int *)(this->ptr_0400E8 + 4 * (v25 - v23) + 16);
        else
          this->pTargetSurface = (unsigned int *)(this->ptr_0400E8 + 4 * (v23 - v25) + 16);
      }
      this->uTargetSurfacePitch = 640;
      this->pfn_1036C0 = (int (__cdecl *)())sub_4A597D;

      this->dword_040110 = 1;
      this->dword_040058 = 1;
      this->hWnd = pTargetWindow->GetAPIHandle();
      return 0;
    }
 }
 return 0;
}

//----- (004A0E97) --------------------------------------------------------
void Render_sub_4A0E97(struct BaseRender *_this, int a2, int a3, int a4, int a5)
{
 _this->dword_00001C = a2;
 _this->dword_000020 = a3;
 _this->dword_000024 = a4;
 _this->dword_000028 = a5;
}

//----- (MM7.exe::0049FDBF) --------------------------------------------------------
void Render_Initialize_ZBuffer(struct BaseRender *_this)
{
 if (!_this->pDefaultZBuffer)
 {
  _this->pDefaultZBuffer = (int *)mem_mng.AllocatedNamedBuffer( 0, 640 * 480 * 4, "ZBuffer");
  _this->pActiveZBuffer = _this->pDefaultZBuffer;
  memset(_this->pDefaultZBuffer, -65536, 640 * 480 * 4);
 }
}

//----- (MM7.exe::004A10E4) --------------------------------------------------------
int Render_CreateDirectDraw(struct BaseRender *_this)
{
 HRESULT      hr;
 IDirectDraw *pdd;
 char         some_class[1024];

 hr = DirectDrawCreate(0, &pdd, 0);
 CheckHRESULT((void **)some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2286, 0);

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
 {
  hr = pdd->QueryInterface(IID_IDirectDraw4, (void **)&_this->pdd4);
  CheckHRESULT((void **)some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2296, 0);
 }
 else
 {
  hr = pdd->QueryInterface(IID_IDirectDraw2, (void **)&_this->pdd2);
  CheckHRESULT((void **)some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2291, 0);
 }

 return pdd->Release();
}

//----- (MM7.exe::004A1169) --------------------------------------------------------
void *Render_SetCooperativeLevel(struct BaseRender *_this, HWND hWnd, int bFullscreen)
{
 IDirectDraw *pdd;
 HRESULT      hr;
 unsigned int flags;
 char         local_0[128];

 //flags = bFullscreen ? DDSCL_NORMAL | DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN : DDSCL_NORMAL;
 flags = bFullscreen ? DDSCL_NORMAL | DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN : DDSCL_NORMAL;
 if (dword_F79D7C != 2 || dword_F79D70 != 4)
 {
  pdd = (IDirectDraw *)_this->pdd4;
  flags |= DDSCL_MULTITHREADED;
 }
 else
 {
  __asm int 3;
  pdd = (IDirectDraw *)_this->pdd2;
 }

 hr = pdd->SetCooperativeLevel(hWnd, flags);
 return CheckHRESULT((void **)local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2320, 0);
}

//----- (MM7.exe::004A11C6) --------------------------------------------------------
void *Render_SetDisplayMode(struct BaseRender *_this, unsigned int uWidth, unsigned int uHeight, unsigned int uBPP)
{
 IDirectDraw *pdd;
 HRESULT      hr;
 unsigned int some_class[128];
 int          v8;

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
 {
  pdd = (IDirectDraw *)_this->pdd4;
  v8 = 2331;
 }
 else
 {
  pdd = (IDirectDraw *)_this->pdd2;
  v8 = 2327;
 }

 hr = S_OK;//(pdd->lpVtbl->SetDisplayMode)(pdd, uWidth, uHeight, uBPP, 0, 0);
 return CheckHRESULT((void **)some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", v8, 0);
}

//----- (M7.exe::004A139A) --------------------------------------------------------
void *Render_CreatePrimarySurface(struct BaseRender *_this)
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
  ddsd2_PrimarySurface.ddsCaps.dwCaps = DDSCAPS_COMPLEX | DDSCAPS_FLIP | DDSCAPS_3DDEVICE | DDSCAPS_PRIMARYSURFACE;

  hr = _this->pdd4->CreateSurface(&ddsd2_PrimarySurface, &_this->pdds4_FrontBuffer, 0);
  CheckHRESULT((void **)some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", __LINE__, 0);
 }
 else
 {
  __asm int 3 //ddraw2 impl
 }

 memset(&ddsCaps2_AttachedSurface, 0, sizeof(DDSCAPS2));
 ddsCaps2_AttachedSurface.dwCaps = DDSCAPS_BACKBUFFER;

 hr = _this->pdds4_FrontBuffer->GetAttachedSurface(&ddsCaps2_AttachedSurface, &pD3DRenderer->pdds4_BackBuffer);
 result = CheckHRESULT((void **)some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", __LINE__, 0);

 _this->dword_040030 = 0;
 _this->dword_000018 = 0;
 return result;
}

//----- (MM7.exe::004A15D8) --------------------------------------------------------
HRESULT Render_GetPrimarySurfacePixelFormat(struct BaseRender *_this, DDPIXELFORMAT *pddpf)
{
 IDirectDrawSurface *pdds;

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
   pdds = (IDirectDrawSurface *)_this->pdds4_FrontBuffer;
 else
   pdds = (IDirectDrawSurface *)_this->pdds2_FrontBuffer;

 return pdds->GetPixelFormat(pddpf);
}

//----- (MM7.exe::004A5BB6) --------------------------------------------------------
void Render_Reset2DClippingRect(struct BaseRender *_this)
{
 _this->uClipRectY = 0;
 _this->uClipRectX = 0;
 _this->uClipRectW = 480;
 _this->uClipRectZ = 640;
 _this->dword_040104 = 1;
}

//----- (004A0EB6) --------------------------------------------------------
void *Render_sub_4A0EB6(struct BaseRender *_this)
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
int Render_sub_49EBF1(struct BaseRender *_this)
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

  result = (int)_this;
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
int Render_ClearBackBufferAndPresent(struct BaseRender *_this)
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
   v1 = (IDirectDrawSurface *)pD3DRenderer->pdds4_BackBuffer;
 else
 {
  v1 = (IDirectDrawSurface *)pD3DRenderer->pdds2_BackBuffer;
  __asm int 3
 }

 ddblt.dwSize = sizeof(DDBLTFX);
 ddblt.dwFillColor = 0x00000000;
 
 hr = pD3DRenderer->pdds4_BackBuffer->Blt(&rcDst, 0, 0, DDBLT_COLORFILL, &ddblt);
 return pD3DRenderer->Present();
}

//----- (MM7.exe::0049FC37) --------------------------------------------------------
unsigned int RenderDirect3D3::Present()
{
  struct tagRECT Rect; // [sp+8h] [bp-28h]@11
  struct tagRECT rc;
  struct tagPOINT Point; // [sp+28h] [bp-8h]@11


 if (pD3DRenderer->pRenderD3D3 && !this->dword_040110)
   return false;

 (this->pfn_1036C0)();

 if (this->pRenderD3D3)
 {
  if (dword_720010)
    sub_46BAEC((void *)dword_720010);
  RenderD3D3_Present(this->pRenderD3D3, 0);
  if (dword_720010)
    sub_46BB0A(dword_720010);
 }
 else
 {
  rc.left = 0;
  rc.top = 0;
  rc.right = 640;
  rc.bottom = 480;

  Render_RestoreFrontBuffer(this);
  if (this->dword_040058)
  {
   GetClientRect(this->hWnd, &Rect);
   Point.y = 0;
   Point.x = 0;
   ClientToScreen(this->hWnd, &Point);
   OffsetRect(&Rect, Point.x, Point.y);
   Render_PresentRegion(this, &Rect, &rc);
  }
  else Render_PresentBackBuffer(this, 0, 0, &rc);
 }
 return true;
}

//----- (004A17C7) --------------------------------------------------------
void *Render_UnlockFrontBuffer(struct BaseRender *_this)
{
 IDirectDrawSurface *v1;
 HRESULT             hr;
 char                local_0[128];

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
   v1 = (IDirectDrawSurface *)_this->pdds4_FrontBuffer;
 else
 {
  __asm int 3;
  //v1 = _this->pdds2_FrontBuffer;
 }

 hr = _this->pdds4_FrontBuffer->Unlock(0);
 return CheckHRESULT((void **)local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", __LINE__, 0);
}

//----- (MM7.exe::004A194A) --------------------------------------------------------
HRESULT Render_PresentBackBuffer(struct BaseRender *_this, int a2, int a3, RECT *pRect)
{
 IDirectDrawSurface *v4,
                    *v6;

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
 {
  v4 = (IDirectDrawSurface *)_this->pdds4_FrontBuffer;
  v6 = (IDirectDrawSurface *)_this->pdds4_BackBuffer;
 }
 else
 {
  v4 = (IDirectDrawSurface *)_this->pdds2_FrontBuffer;
  v6 = (IDirectDrawSurface *)_this->pdds2_BackBuffer;
  __asm int 3
 }

 return _this->pdds4_FrontBuffer->BltFast(0, 0, _this->pdds4_BackBuffer, pRect, DDBLTFAST_WAIT);
}

//----- (MM7.exe::004A1814) --------------------------------------------------------
HRESULT Render_RestoreFrontBuffer(struct BaseRender *_this)
{
 IDirectDrawSurface *v1;
 HRESULT             hr;


 if ( dword_F79D7C != 2 || dword_F79D70 != 4)
   v1 = (IDirectDrawSurface *)_this->pdds4_FrontBuffer;
 else
 {
  v1 = (IDirectDrawSurface *)_this->pdds2_FrontBuffer;
  __asm int 3;
 }

 hr = _this->pdds4_FrontBuffer->IsLost();
 if ( hr == DDERR_SURFACELOST )
    hr = _this->pdds4_FrontBuffer->Restore();
 return hr;
}

//----- (MM7.exe::0044F2B2) --------------------------------------------------------
unsigned int RenderDirect3D3::IsGammaControlSupported()
{
 HRESULT    hr;
 DDCAPS_DX7 ddCaps;
 char       some_class[128];

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
 {
  memset(&ddCaps, 0, sizeof(DDCAPS_DX7));
  ddCaps.dwSize = sizeof(DDCAPS_DX7);

  hr = pD3DRenderer->pdd4->GetCaps(&ddCaps, 0);
  CheckHRESULT((void **)some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\GammaControl.cpp", __LINE__, 0);
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
void *GammaController_sub_44F4D9(struct CGammaController *_this, float a2)
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
  GammaController_sub_44F45B((int)_this, (int)&_this->ddGammaRamp2);
  result = GammaController_sub_44F408((int)_this, (char *)&_this->ddGammaRamp2);
 }
 return result;
}

//----- (MM7.exe::0044F24B) --------------------------------------------------------
void CGammaController_InitializeFromSurface(struct CGammaController *_this, struct IDirectDrawSurface4 *pdds)
{
 _this->pdds4 = pdds;
 if (_this->pddgc)
 {
  _this->pddgc->Release();
  _this->pddgc = 0;
 }
 if (pD3DRenderer->IsGammaControlSupported())
 {
  pdds->QueryInterface(IID_IDirectDrawGammaControl, (void **)&_this->pddgc);
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
  hr = _this->pddgc->GetGammaRamp(0, &_this->ddGammaRamp);
  result = CheckHRESULT((void **)some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\GammaControl.cpp", 87, 0);
 }
 else
 {
   Game_sub_40E2C8(&hr, "Gamma control not active", (int)&v12);
   result = sub_467834(some_class, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\GammaControl.cpp", 0, 0, (char *)83, 0);
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
   v4 = (IDirectDrawSurface *)pD3DRenderer->pdds4_FrontBuffer;
 else
 {
  __asm int 3; //ddraw2
  v4 = (IDirectDrawSurface *)pD3DRenderer->pdds2_FrontBuffer;
 }

 hr = pD3DRenderer->pdds4_FrontBuffer->Blt(pDestRect, (IDirectDrawSurface4 *)pddsSrc, pSrcRect, uFlags, 0);
 return CheckHRESULT((void **)local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", __LINE__, 0);
}

//----- (004A0F40) --------------------------------------------------------
bool __stdcall LockSurface_DDraw4(struct IDirectDrawSurface4 *pdds4, DDSURFACEDESC2 *pddsd2, unsigned int uLockFlags)
{
 char    local_0[128];
 HRESULT hr;

 hr = pdds4->Lock(0, pddsd2, uLockFlags, 0);
 if (hr == DDERR_SURFACELOST)
 {
  if (dword_720010)
    Mouse_suspend(dword_720010);

  hr = pdds4->Restore();
  if (FAILED(hr))
  {
   if (hr != -2005532084)
   {
    pddsd2->dwSize = 0;
    return false;
   }

   pD3DRenderer->pdds4_FrontBuffer->Restore();
   pdds4->Restore();
  }

  hr = pdds4->Lock(0, pddsd2, DDLOCK_WAIT, 0);
  if (hr == DDERR_SURFACELOST || hr == DDERR_SURFACEBUSY)
  {
   pddsd2->dwSize = 0;
   return false;
  }
  else if (FAILED(hr))
  {
   CheckHRESULT((void **)local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2161, 0);
   pddsd2->dwSize = 0;
   return false;
  }

  if (pD3DRenderer->pRenderD3D3)
    sub_4A5190();
  pD3DRenderer->pdd4->RestoreAllSurfaces();
  if (dword_720010)
    sub_46B105((void *)dword_720010);
 }
 else if (FAILED(hr))
 {
  if (hr == DDERR_SURFACEBUSY)
  {
   pddsd2->dwSize = 0;
   return false;
  }

  CheckHRESULT((void **)local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2199, 0);
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

  v4 = (int)a1;
  v3 = (*(int (__stdcall **)(int, _DWORD, void *, int, _DWORD))(*(_DWORD *)a1 + 100))((int)a1, 0, Dst, a3, 0);
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
      (*(void (__stdcall **)(int))(*(_DWORD *)pD3DRenderer->pdds2_FrontBuffer + 108))((int)pD3DRenderer->pdds2_FrontBuffer);
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
      CheckHRESULT((void **)&a1, v3, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", v7, v8);
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











#ifndef OLD_CODE
int RGBTexture_Load_New(struct RGBTexture *_this, const wchar_t *pTextureName)
{
 unsigned int uTextureID;

 uTextureID = LODFile_Icons_LOD.LODFile_LoadTexture_New( pTextureName);

 _this->pPixels = LODFile_Icons_LOD.aLODHeaders[uTextureID].pTruecolorPixels;
 _this->uWidth = LODFile_Icons_LOD.aLODHeaders[uTextureID].uTextureWidth;
 _this->uHeight = LODFile_Icons_LOD.aLODHeaders[uTextureID].uTextureHeight;
 _this->uNumPixels = _this->uWidth * _this->uHeight;

 return 0;
}
#endif

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

  cTexture cTexture_obj;
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
  unsigned int uTextureID;
#ifndef OLD_CODE
 wchar_t      pFilepath[256];

 wsprintfW(pFilepath, L"%S", pContainerName);

 return RGBTexture_Load_New(_this, pFilepath);
#endif
#ifdef OLD_CODE
  char      pFilepath[256];
 

 wsprintfA(pFilepath, "%S", pContainerName);

 return RGBTexture_Load(_this, pFilepath,0); 
#endif
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
 v36 = (unsigned short *)v9;

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
 while ((1 << v10) != (int)v36 )
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
 return (int)_this;
}


//----- (004A0E80) --------------------------------------------------------
void Render_ClearZBuffer(struct BaseRender *_this, int a2, int a3)
{
  memset(_this->pActiveZBuffer, -65536, 640 * 480 * 4);
}

//----- (004A121C) --------------------------------------------------------
void *Render_CreateSurface(struct BaseRender *_this)
{
 char    local_0[128];
 HRESULT hr; 
 DDSURFACEDESC2 dd;

 memset(&dd, 0, sizeof(DDSURFACEDESC2));
 dd.dwSize = sizeof(DDSURFACEDESC2);
 dd.dwFlags = DDSD_CAPS;
 dd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;

 hr = _this->pdd4->CreateSurface(&dd, &pD3DRenderer->pdds4_FrontBuffer, 0);
 return CheckHRESULT((void **)local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2357, 0);
}

//----- (004A12CD) --------------------------------------------------------
void *Render_CreateWndSurface(struct BaseRender *_this)
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

 hr = _this->pdd4->CreateSurface(&dd, &pD3DRenderer->pdds4_BackBuffer, 0);
 return CheckHRESULT((void **)local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2357, 0);
}

//----- (004A14F4) --------------------------------------------------------
extern IDirectDrawClipper *pDDrawClipper;
void *Render_CreateClipper(struct BaseRender *_this, HWND hClipWnd)
{
 char    local_0[128];
 HRESULT hr; 

 hr = _this->pdd4->CreateClipper(NULL, &pDDrawClipper, NULL);
 CheckHRESULT((void **)&local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2463, 0);

 hr = pDDrawClipper->SetHWnd(0, hClipWnd);
 CheckHRESULT((void **)&local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2464, 0);

 hr = _this->pdds4_FrontBuffer->SetClipper(pDDrawClipper);
 return CheckHRESULT((void **)&local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 2465, 0);
}

//----- (004A1884) --------------------------------------------------------
void *Render_PresentRegion(struct BaseRender *_this, RECT *pDestRect, RECT *pSrcRect)
{
 HRESULT hr;
 char    local_0[128];

  hr = pD3DRenderer->pdds4_FrontBuffer->Blt(pDestRect, pD3DRenderer->pdds4_BackBuffer, pSrcRect, DDBLT_WAIT, 0);
  return CheckHRESULT((void **)local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", __LINE__, 0);
}



HRESULT __stdcall DDrawEnumDisplayModesCallback(DDSURFACEDESC2 *pDDSurfaceDesc, void *a2)
{
 if (*(_DWORD *)((char *)pDDSurfaceDesc + 0x68) | 0x2000 && *(_DWORD *)((char *)pDDSurfaceDesc + 84) == 16 )
 {
  *(unsigned short *)a2 = true;
    return S_OK;
 }
 else return 1;
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
 local_4CC.Dest = new char[v4 + 1];//Dest = (char *)operator new(v4 + 1);
 strcpy(local_4CC.Dest, pDriverName);

 v5 = strlen(pDriverDescription);
 local_4CC.v36 = new char[v5 + 1];//v36 = (char *)operator new(v5 + 1);
 strcpy(local_4CC.v36, pDriverDescription);

 if (pGUID)
 {
  local_4CC.lpGUID = new GUID;
  memcpy(local_4CC.lpGUID, pGUID, sizeof(GUID));
 }
 else
   local_4CC.lpGUID = 0;

 hr = DirectDrawCreate(pGUID, &pDirectDraw, 0);
 if (FAILED(hr))
 {
  operator_delete((void *)local_4CC.Dest);
  operator_delete((void *)local_4CC.v36);
  if (local_4CC.lpGUID)
    operator_delete(local_4CC.lpGUID);
 }

 hr = pDirectDraw->QueryInterface(IID_IDirectDraw4, (void **)&pDirectDraw4);
 if (FAILED(hr))
 {
  operator_delete(local_4CC.Dest);
  operator_delete(local_4CC.v36);
  if (local_4CC.lpGUID)
    operator_delete(local_4CC.lpGUID);

  pDirectDraw->Release();
  return 1;
 }

 pDirectDraw->Release();

 hr = pDirectDraw4->GetDeviceIdentifier(&ddDeviceId, DDGDI_GETHOSTIDENTIFIER);
 if (FAILED(hr))
   local_4CC.v37 = 0;
 else
 {
  v13 = strlen(ddDeviceId.szDescription);
  local_4CC.v37 = new char[v13 + 1];//v37 = (char *)operator new(v13 + 1);
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

 hr = pDirectDraw4->EnumDisplayModes(0, 0, &v33, DDrawEnumDisplayModesCallback);
 pDirectDraw4->QueryInterface(memory_4D8410.IID_IDirect3D3, (void **)&pDirect3D3);
 //if (FAILED(hr) || !v33 || !pDirect3D3)
 if (FAILED(hr) || !pDirect3D3)
 {
  operator_delete(local_4CC.Dest);
  operator_delete(local_4CC.v36);
  if (local_4CC.v37)
    operator_delete(local_4CC.v37);
  if (local_4CC.lpGUID)
    operator_delete(local_4CC.lpGUID);

  pDirectDraw4->Release();
  return 1;
 }

 local_4BC.v30 = (unsigned char *)a4;
 local_4BC.v31 = (char *)&local_4CC;
 hr = pDirect3D3->EnumDevices((LPD3DENUMDEVICESCALLBACK)Direct3D3EnumDevicesCallback, &local_4BC);

 operator_delete(local_4CC.Dest);
 operator_delete(local_4CC.v36);
 if (local_4CC.v37)
   operator_delete(local_4CC.v37);
 if (local_4CC.lpGUID)
   operator_delete(local_4CC.lpGUID);

 pDirectDraw4->Release();
 pDirect3D3->Release();


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

 RenderD3D3_CreateTexture(pD3DRenderer->pRenderD3D3, 64, 64, &pTexture1Surface, &pTexture1, true, false, (void *)0x20);
 RenderD3D3_CreateTexture(pD3DRenderer->pRenderD3D3, 64, 64, &pTexture2Surface, &pTexture2, true, false, (void *)0x20);

 pD3DRenderer->pRenderD3D3->pDevice->SetTexture(0, pTexture1);
 pD3DRenderer->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_ADDRESS, 1);
 pD3DRenderer->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_COLOROP, 2);
 pD3DRenderer->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, 2);
 pD3DRenderer->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_MAGFILTER, 2);
 pD3DRenderer->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_MINFILTER, 2);
 pD3DRenderer->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_MIPFILTER, 1);

 pD3DRenderer->pRenderD3D3->pDevice->SetTexture(1, pTexture2);
 pD3DRenderer->pRenderD3D3->pDevice->SetTextureStageState(1, D3DTSS_ADDRESS, 3);
 pD3DRenderer->pRenderD3D3->pDevice->SetTextureStageState(1, D3DTSS_TEXCOORDINDEX, 1);
 pD3DRenderer->pRenderD3D3->pDevice->SetTextureStageState(1, D3DTSS_COLOROP, 7);
 pD3DRenderer->pRenderD3D3->pDevice->SetTextureStageState(1, D3DTSS_COLORARG1, 2);
 pD3DRenderer->pRenderD3D3->pDevice->SetTextureStageState(1, D3DTSS_COLORARG2, 1);
 pD3DRenderer->pRenderD3D3->pDevice->SetTextureStageState(1, D3DTSS_MAGFILTER, 2);
 pD3DRenderer->pRenderD3D3->pDevice->SetTextureStageState(1, D3DTSS_MINFILTER, 2);
 pD3DRenderer->pRenderD3D3->pDevice->SetTextureStageState(1, D3DTSS_MIPFILTER, 1);
 
 v0 = false;
 if (pD3DRenderer->pRenderD3D3->pDevice->ValidateDevice((LPDWORD)&v4) == S_OK)
 {
    if ( v4 == 1 )
      v0 = true;
 }

 pD3DRenderer->pRenderD3D3->pDevice->SetTextureStageState(1, D3DTSS_COLOROP, 1);

 pTexture1->Release();
 pTexture1Surface->Release();

 pTexture2->Release();
 pTexture2Surface->Release();

 return v0;
}


//----- (0049FFD7) --------------------------------------------------------
bool Render_sub_49FFD7(struct BaseRender *_this)
{
 return RenderD3D3_CreateTexture(_this->pRenderD3D3, 64, 64, &_this->ptr_1036B0, &_this->ptr_1036B4, true, false, (void *)0x20);
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
 pBitmap = Render_LoadHWLTexture(&pD3DRenderer->struct_040114, (unsigned char *)pFilenameA, 0);
 if (!pBitmap)
   return -1;

 *pWidth = pBitmap->uWidth;
 *pHeight = pBitmap->uHeight;
 *pPixels = pBitmap->pTruecolorPixels;

 free(pBitmap->pPixels);

 return 0;
};

unsigned int Render_MoveToGPU(struct BaseRender *_this, unsigned int uWidth, unsigned int uHeight, unsigned int *pData, struct IDirectDrawSurface4 **pOutSurface, struct IDirect3DTexture2 **pOutTexture)
{
 DDSURFACEDESC2 ddsd;
 HRESULT        hr;

 if (!_this->pRenderD3D3)
 {
  *pOutSurface = 0;
  *pOutTexture = 0;
  return 0;
 }
 if (!RenderD3D3_CreateTexture(_this->pRenderD3D3, uWidth, uHeight, pOutSurface, pOutTexture, true, 0, (void *)_this->uMinDeviceTextureDim))
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

  hr = (*pOutSurface)->Unlock(0);
  if (FAILED(hr))
  {
   __asm int 3;
   return -1;
  }
 }
 return 0;
}

//----- (004A5048) --------------------------------------------------------
bool Render_MoveHWSpriteToVideoMemory(struct BaseRender *_this, struct HardwareSprite *pSprite)
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

  v4 = (int)pSprite;
  v3 = (int)_this;
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

 if (!RenderD3D3_CreateTexture(_this->pRenderD3D3, result->uWidth, result->uHeight, &pSprite->pTextureSurface, &pSprite->pTexture, true, 0, (void *)_this->uMinDeviceTextureDim))
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

  hr = pSprite->pTextureSurface->Unlock(0);
  if (FAILED(hr))
    __asm int 3;

  //CheckHRESULT((void **)0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
 }

 free(result->pPixels);
 operator_delete(result);

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
      if (!strcmpi(Str1, (char *)_this->pSriteNames[v6]))
        break;
      //if ( _strcmpi(Str1, *((const char **)v4 + v6 + 4)) <= 0 )
      else if (strcmpi(Str1, (char *)_this->pSriteNames[v6]) < 0)
        v32 = v5 + (v32 - v5) / 2;
      else
        v5 = v6 + 1;

      if ( v5 >= v32 )
        return 0;
    }

    fseek(_this->pHWLFile, _this->pSpriteFileOffsets[v6], SEEK_SET);
    v10 = new Render_HWLBitmap;
    locked_fread(&DstBuf, 4u, 1u, _this->pHWLFile);
    locked_fread(&v10->dword_000018, 4, 1, _this->pHWLFile);
    locked_fread(&v10->dword_00001C, 4, 1, _this->pHWLFile);
    locked_fread(&v10->dword_000020, 4, 1, _this->pHWLFile);
    locked_fread(&v10->dword_000024, 4, 1, _this->pHWLFile);
    locked_fread(&v10->uWidth, 4, 1, _this->pHWLFile);
    locked_fread(&v10->uHeight, 4, 1, _this->pHWLFile);
    locked_fread(&v10->dword_000030, 4, 1, _this->pHWLFile);
    locked_fread(&v10->dword_000034, 4, 1, _this->pHWLFile);
    v10->pPixels = new unsigned short[v10->uWidth * v10->uHeight];
    if ( DstBuf )
    {
      v33 = malloc(DstBuf);
      locked_fread(v33, 1u, DstBuf, _this->pHWLFile);
      v27 = 2 * v10->uWidth * v10->uHeight;
      MemUnzip(v10->pPixels, (unsigned int *)&v27, v33, DstBuf);
    }
    else
      locked_fread(v10->pPixels, 2, v10->uWidth * v10->uHeight, _this->pHWLFile);

    v10->pTruecolorPixels = new unsigned int[v10->uWidth * v10->uHeight];
    for (i = 0; i < v10->uWidth * v10->uHeight; ++i)
    {/*
     v10->pTruecolorPixels[i] = (unsigned int)(((unsigned char)(((v10->pPixels[i] & 0xF800) >> 11) * 8)) << 16) |
                                (unsigned int)(((unsigned char)(((v10->pPixels[i] & 0x07E0) >> 5) * 4)) << 8) |
                                (unsigned char)((v10->pPixels[i] & 0x1F) * 8);*/
     //HWL bitmaps are all in A1R5G5B format
     v10->pTruecolorPixels[i] = (unsigned int)(((unsigned char)(((v10->pPixels[i] & 0xF800) >> 10) * 8)) << 16) |
                                (unsigned int)(((unsigned char)(((v10->pPixels[i] & 0x03E0) >> 5) * 8)) << 8) |
                                (unsigned char)((v10->pPixels[i] & 0x1F) * 8);
     if (v10->pPixels[i] & 0x8000)
       v10->pTruecolorPixels[i] |= 0xFF000000;
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
      operator_delete((void *)*((_DWORD *)v10 + 14));
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

 pdd4->GetCaps(&ddcDriver, &ddcReference);
 return *((char *)(&ddcReference) + 0xAC) & 0x40 &&
        *((char *)(&ddcReference) + 0xAF) & 0x02;
}



//----- (004A6D87) --------------------------------------------------------
void Render_FillRect2(struct BaseRender *_this, unsigned int uX, unsigned int uY, unsigned int a5, int a6, unsigned int a7)
{
 int y, x;

 if (!_this->bSceneBegun)
   return;

 for (y = uY; y < uY + a6; ++y)
   for (x = uX; x < uX + a5; ++x)
     _this->pTargetSurface[x + y * _this->uTargetSurfacePitch] = a7;
}


//----- (0049FE05) --------------------------------------------------------
void sub_49FE05(struct BaseRender *pD3DRenderer)
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

 v3 = (int)pD3DRenderer;
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
      operator_delete(*(_DWORD **)(v3 + 262376));
      *(_DWORD *)(v3 + 262380) = 0;
      *(_DWORD *)(v3 + 262376) = 0;
    }
    v5 = *(_DWORD *)(v3 + 262280);
    if ( v5 )
    {
      v6 = sub_49DC90(*(_DWORD *)(v3 + 262280));
      operator_delete((int *)v5);
    }
    *(_DWORD *)(v3 + 262280) = 0;
  }
 else
 {
  if (dword_4E800C == 1)
  {
   if (!pD3DRenderer->pdd2)
     return;

      (*(void (__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)pD3DRenderer->pdd2 + 80))((int)pD3DRenderer->pdd2, *(_DWORD *)(v3 + 262224), 8);
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
       return;

      (*(void (__stdcall **)(int, _DWORD, signed int))(*(_DWORD *)pD3DRenderer->pdd4 + 80))((int)pD3DRenderer->pdd4, *(_DWORD *)(v3 + 262224), 1032);
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
      operator_delete((void *)*v14);
      *(_DWORD *)v13 = 0;
      *v14 = 0;
    }
  }
}




//----- (004A2050) --------------------------------------------------------
void Render_DrawPolygon(struct BaseRender *_this, unsigned int uNumVertices, struct struct8 *a3, struct class51_stru2 *a4, IDirect3DTexture2 *pTexture)
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

  v6 = (int)_this;
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
     _this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_ADDRESS, 1);
     _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_CULLMODE, 2);
     if (_this->bUsingSpecular)
     {
      _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, 1);
      _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_SRCBLEND, 2);
      _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_DESTBLEND, 1);
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

     pD3DRenderer->pRenderD3D3->pDevice->SetTexture(0, pTexture);
     pD3DRenderer->pRenderD3D3->pDevice->DrawPrimitive(D3DPT_TRIANGLEFAN, D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1, pVertices, uNumVertices, D3DDP_DONOTLIGHT);
    }
    else
        {
          if (uNumVertices > 0)
          {
            LODWORD(v9) = (int)&pVertices->y;
            v10 = &array_50AC10[0].flt_00000C;
            a4 = (class51_stru2 *)&pVertices->y;
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
              LODWORD(v11) = (int)a4;
              v12 = *v10;
              *(_DWORD *)(a4 + 12) = v15;
              if ( *(_DWORD *)(v6 + 1062496) )
              {
                v17 = v12;
                v16 = sub_47C3D7(0, 0, v17);
                LODWORD(v11) = (int)a4;
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
              a4 = (class51_stru2 *)(LODWORD(v11) + 32);
              if ( v18 )
                break;
              LODWORD(v9) = (int)a4;
            }
          }
          v19 = (*(int (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v6 + 262280) + 56) + 88))(
                  *(_DWORD *)(*(_DWORD *)(v6 + 262280) + 56),
                  14,
                  0);
          CheckHRESULT((void **)&a3, v19, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);

          v20 = _this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_ADDRESS, 1);
          CheckHRESULT((void **)&a3, v20, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);

          if (pD3DRenderer->bUsingSpecular)
            _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_FOGENABLE, 0);

          v23 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v6 + 262280) + 56)
                                                                                         + 152))(
                  *(_DWORD *)(*(_DWORD *)(v6 + 262280) + 56),
                  0,
                  0,
                  (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp",
                  543,
                  0);
          CheckHRESULT((void **)&a3, v23, v24, v25, v26);
          v27 = (*(int (__stdcall **)(_DWORD, signed int, signed int, _UNKNOWN *, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v6 + 262280) + 56) + 112))(
                  *(_DWORD *)(*(_DWORD *)(v6 + 262280) + 56),
                  6,
                  452,
                  (char *)pVertices,
                  uNumVertices,
                  16);
          CheckHRESULT((void **)&a3, v27, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
          v55 = *(const char **)(*(_DWORD *)(v6 + 262280) + 56);
          (*(void (**)(void))(*(_DWORD *)v55 + 88))();
          sub_45D74F_MessWithLight(pGame->class04_obj, -1, 0);
          v22 = uNumVertices;
          if (uNumVertices > 0)
          {
            v28 = (char *)&pVertices->diffuse;
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
                  (int)pTexture);
          CheckHRESULT((void **)&a3, v30, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);

          v31 = _this->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_ADDRESS, 1);
          CheckHRESULT((void **)&a3, v31, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
          if ( !pD3DRenderer->bUsingSpecular )
          {
            v32 = _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_ZWRITEENABLE, 1);
            CheckHRESULT((void **)&a3, v32, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
          }
          v33 = _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, 1);
          CheckHRESULT((void **)&a3, v33, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
          v34 = _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_SRCBLEND, 1);
          CheckHRESULT((void **)&a3, v34, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
          v35 = _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_DESTBLEND, 3);
          CheckHRESULT((void **)&a3, v35, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
          v36 = (*(int (__stdcall **)(_DWORD, signed int, signed int, _UNKNOWN *, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v6 + 262280) + 56) + 112))(
                  *(_DWORD *)(*(_DWORD *)(v6 + 262280) + 56),
                  6,
                  452,
                  (char *)pVertices,
                  uNumVertices,
                  16);
          CheckHRESULT((void **)&a3, v36, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
          if ( pD3DRenderer->bUsingSpecular )
          {
            v38 = _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_ZWRITEENABLE, 1);
            CheckHRESULT((void **)&a3, v38, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
            v37 = uNumVertices;
            if (uNumVertices > 0)
            {
              v39 = (char *)&pVertices->specular;
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
                    (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp",
                    __LINE__,
                    0);
            CheckHRESULT((void **)&a3, v41, v55, 0x16u, 1);
            v42 = _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_SRCBLEND, 6);
            CheckHRESULT((void **)&a3, v42, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
            v43 = _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_DESTBLEND, 5);
            CheckHRESULT((void **)&a3, v43, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
            v44 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)(v6 + 262280) + 56)
                                                                                       + 112))(
                    *(_DWORD *)(*(_DWORD *)(v6 + 262280) + 56),
                    6,
                    452,
                    (int)pVertices,
                    uNumVertices,
                    16);
            CheckHRESULT((void **)0, v44, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, 0);
            _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_FOGENABLE, 1);
            v46 = sub_47C370();
            _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_FOGCOLOR, v46 & 0xFFFFFF);
            v5 = 0;
            _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_FOGTABLEMODE, 0);
          }
          v47 = _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_SRCBLEND, 2);
          CheckHRESULT((void **)0, v47, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, v5);
          v48 = _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_DESTBLEND, 1);
          CheckHRESULT((void **)0, v48, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, v5);
          v49 = _this->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, v5);
          CheckHRESULT((void **)0, v49, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", __LINE__, v5);
        }
      }
}