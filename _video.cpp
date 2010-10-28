#include "_video.h"

#include <stdio.h>


#include "AIL.h"
#include "_audio.h"

#include "data.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"





//----- (MM7.exe::004BF411) --------------------------------------------------------
int __stdcall radmalloc(long);
void CVideoPlayer_OpenMovie(struct CVideoPlayer *_this, const char *pVideoName, int a3, int a4)
{
 unsigned int uSmackerSurfaceType;
 char         pVideoFile[256];

 if (_this->dword_000054)
   return;

 CVideoPlayer_Initialize(_this);
 _this->dword_000064 = a3;
 wsprintfA(pVideoFile, "%s.bik", pVideoName);
 strcpy((char *)_this->array_0000A4, pVideoName);

 _this->pBinkMovie = CVideoPlayer_OpenBinkMovie(_this, pVideoFile);
 if (_this->pBinkMovie)
 {
  _this->dword_00009C = 2;
  _this->dword_0000A0 = 1;
  _this->pBinkBuffer = (unsigned char *)sub_4BFE2D(_this->hWnd, _this->pBinkMovie->Width, _this->pBinkMovie->Height, 0);
 }
 else
 {
  CVideoPlayer_UnloadAll(_this);

  wsprintfA(pVideoFile, "%s.smk", pVideoName);
  _this->pSmackerMovie = CVideoPlayer_OpenSmackMovie(_this, pVideoFile);
  if (!_this->pSmackerMovie)
  {
   CVideoPlayer_UnloadAll(_this);
   wsprintfA(pVideoFile, "Can't load file - anims\\%s.smk", pVideoName);
   MessageBoxA(0, pVideoFile, "Smacker Error", 0);
   return;
  }

  _this->dword_00009C = 1;
  _this->dword_0000A0 = 2;

  //_this->dword_000030 = radmalloc(_this->ptr_000028[1] * _this->ptr_000028[2]);
  _this->ptr_000030 = (unsigned char *)malloc(_this->pSmackerMovie->Width * _this->pSmackerMovie->Height);
  if (!_this->ptr_000030)
  {
   CVideoPlayer_UnloadAll(_this);
   MessageBoxW(0, L"Can't allocate memory for buffer", L"Smacker Error", 0);
   return;
  }

  SmackToBuffer(_this->pSmackerMovie, 0, 0,
                _this->pSmackerMovie->Width, _this->pSmackerMovie->Height,
                _this->ptr_000030, 0);

  if (a4)
  {
   if ((unsigned int)dword_6A0D00 < 0xA5)
     uSmackerSurfaceType = VideoPlayer_Smacker_CheckSurfaceFromat() | 2;
   else
   {
    uSmackerSurfaceType = VideoPlayer_Smacker_CheckSurfaceFromat() | 6;
   }
  }
  else
    uSmackerSurfaceType = VideoPlayer_Smacker_CheckSurfaceFromat();

  _this->pSmackMoviekBlit = SmackBlitOpen(uSmackerSurfaceType);
  if (!_this->pSmackMoviekBlit)
  {
   CVideoPlayer_UnloadAll(_this);
   MessageBoxW(0, L"Failed to open Blit API", L"Smacker Error", 0);
   return;
  }
 }
}

//----- (MM7.exe::004BF1E6) --------------------------------------------------------
HSMACK CVideoPlayer_OpenSmackMovie(struct CVideoPlayer *_this, const char *pVideoFile)
{
 int i;

 for (i = 0; i < _this->uNumMightVideoHeaders; ++i)
 {
  if (!_strcmpi((char *)_this->pMightVideoHeaders[i].sVideoName, pVideoFile))
  {
   SetFilePointer(_this->hMightVid, _this->pMightVideoHeaders[i].uContainerOffset, 0, FILE_BEGIN);
   return SmackOpen(_this->hMightVid, 28992, -1);
  }
 }

 for (i = 0; i < _this->uNumMagicVideoHeaders; ++i)
 {
  if (!_strcmpi((char *)_this->pMagicVideoHeaders[i].sVideoName, pVideoFile))
  {
   SetFilePointer(_this->hMagicVid, _this->pMagicVideoHeaders[i].uContainerOffset, 0, FILE_BEGIN);
   return SmackOpen(_this->hMightVid, 28992, -1);
  }
 }

 return 0;
}

//----- (MM7.exe::004BEBD7) --------------------------------------------------------
void CVideoPlayer_UnloadAll(struct CVideoPlayer *_this)
{
  int v2; // esi@1
  int v4; // eax@4
  v2 = (int)_this;

 if (_this->pBinkMovie)
 {
  BinkPause(_this->pBinkMovie, true);
  Sleep(300);
  BinkClose(_this->pBinkMovie);
  _this->pBinkMovie = 0;
 }

 if (_this->pBinkBuffer)
 {
  v4 = (int)_this->pBinkBuffer;

  (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(_this->pBinkBuffer + 72) + 8))(*(_DWORD *)(v4 + 72));
  *(_DWORD *)(v4 + 72) = 0;

  call_delete(_this->pBinkBuffer);
  _this->pBinkBuffer = 0;
 }

 if (_this->pSmackerMovie)
 {
  SmackSoundOnOff(_this->pSmackerMovie, false);
  SmackClose(_this->pSmackerMovie);
  _this->pSmackerMovie = 0;
 }

 if (_this->pSmackerBuffer)
 {
  SmackBufferClose(_this->pSmackerBuffer);
  _this->pSmackerBuffer = 0;
 }

 if (_this->pSmackMoviekBlit)
 {
  SmackBlitClose(_this->pSmackMoviekBlit);
  _this->pSmackMoviekBlit = 0;
 }

 _this->dword_000054 = 0;
 _this->dword_00009C = 0;
 _this->dword_0000A0 = 0;

 memset(_this->array_0000A4, 0, 64);
 if (pAudioPlayer->hAILRedbook)
 {
  if (!dword_F8BC10)
    AIL_redbook_resume(pAudioPlayer->hAILRedbook);
 }
 class24_sub_426363(pClass24_global);
}

//----- (004BED4F) --------------------------------------------------------
void sub_4BED4F(struct CVideoPlayer *_this, HWND hWnd, int a3, int a4)
{
  int v6; // edx@6
  int v7; // edx@6
  int v8; // ecx@6

  RECT rcSrc;//int v9; // [sp+8h] [bp-20h]@10
  //int v10; // [sp+Ch] [bp-1Ch]@10
  //int v11; // [sp+10h] [bp-18h]@10
  //int v12; // [sp+14h] [bp-14h]@10
  RECT rcDst;//int v13; // [sp+18h] [bp-10h]@6
  //int v14; // [sp+1Ch] [bp-Ch]@6
  //int v15; // [sp+20h] [bp-8h]@6
  //int v16; // [sp+24h] [bp-4h]@8
 unsigned char *pBinkBuffer;

 if (_this->pBinkMovie)
 {
  pBinkBuffer = _this->pBinkBuffer;
  if (_this->pBinkBuffer)
  {
   BinkDoFrame(_this->pBinkMovie);
   BinkGetRects(_this->pBinkMovie, *(_DWORD *)(pBinkBuffer + 16));
   if (BinkLockSurface(_this->pBinkBuffer))
   {
    BinkCopyToBuffer(
          _this->pBinkMovie,
          *(_DWORD **)(pBinkBuffer + 20),
          *(_DWORD *)(pBinkBuffer + 24),
          *(_DWORD *)(pBinkBuffer + 4),
          0,
          0,
          (unsigned int)*(_DWORD *)(pBinkBuffer + 16));
    BinkBufferUnlock(_this->pBinkBuffer);
   }

   if (pD3DRenderer->dword_040058)
   {
    v7 = *(_DWORD *)(pBinkBuffer + 80);
    rcDst.left = v7;
    rcDst.top = *(_DWORD *)(pBinkBuffer + 84);
    v8 = v7 + *(_DWORD *)pBinkBuffer;
    rcDst.right = v7 + *(_DWORD *)pBinkBuffer;
    v6 = rcDst.top + *(_DWORD *)(pBinkBuffer + 4);
   }
   else
   {
    rcDst.left = 0;
    rcDst.top = 0;
    rcDst.right = *(_DWORD *)pBinkBuffer;
    rcDst.bottom = *(_DWORD *)(pBinkBuffer + 4);

    v8 = *(_DWORD *)pBinkBuffer;
    v6 = *(_DWORD *)(pBinkBuffer + 4);
   }
   rcDst.bottom = v6;
   if (a4)
   {
    rcDst.right = *(_DWORD *)pBinkBuffer + v8;
    rcDst.bottom = *(_DWORD *)(pBinkBuffer + 4) + v6;
   }
   rcSrc.left = 0;
   rcSrc.top = 0;
   rcSrc.right = *(_DWORD *)pBinkBuffer;
   rcSrc.bottom = *(_DWORD *)(pBinkBuffer + 4);

   BltToFrontBuffer(&rcDst, (IDirectDrawSurface *)(pBinkBuffer + 72), &rcSrc, DDBLT_WAIT);
   if (_this->pBinkMovie->FrameRate != _this->pBinkMovie->Data1 - 1 || _this->dword_000064)
     BinkNextFrame(_this->pBinkMovie);
   else
     CVideoPlayer_UnloadAll(_this);
  }
 }
}

//----- (MM7.exe::004BF141) --------------------------------------------------------
HBINK CVideoPlayer_OpenBinkMovie(struct CVideoPlayer *_this, const char *pVideoFile)
{
 for (unsigned int i = 0; i < _this->uNumMightVideoHeaders; ++i)
 {
  if (!_strcmpi((char *)_this->pMightVideoHeaders[i].sVideoName, pVideoFile))
  {
   SetFilePointer(_this->hMightVid, _this->pMightVideoHeaders[i].uContainerOffset, 0, FILE_BEGIN);
   return BinkOpen(_this->hMightVid, 0x82000000);
  }
 }

 for (unsigned int i = 0; i < _this->uNumMagicVideoHeaders; ++i)
 {
  if (!_strcmpi((char *)_this->pMagicVideoHeaders[i].sVideoName, pVideoFile))
  {
   SetFilePointer(_this->hMagicVid, _this->pMagicVideoHeaders[i].uContainerOffset, 0, FILE_BEGIN);
   return BinkOpen(_this->hMagicVid, 0x82000000);
  }
 }

 return 0;
}

//----- (MM7.exe::004BEB41) --------------------------------------------------------
void CVideoPlayer_Initialize(struct CVideoPlayer *_this)
{
 IDirectDrawSurface *v3;

 class24_fn1(pClass24_global);
 if (pAudioPlayer->hAILRedbook)
   AIL_redbook_pause(pAudioPlayer->hAILRedbook);

 _this->pSmackerMovie = 0;
 _this->pSmackerBuffer = 0;

 _this->pBinkMovie = 0;
 _this->pBinkBuffer = 0;

 _this->dword_000054 = 1;
 _this->dword_000058 = 0;
 _this->dword_00005C = 0;
 _this->bUsingSmackerMMX = SmackUseMMX(1);

 _this->dword_00006C = 0;
 _this->hWnd = pAppWindow->GetAPIHandle();

 BinkSetSoundSystem(BinkOpenMiles, pAudioPlayer->hDigDriver);

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
   v3 = (IDirectDrawSurface *)pD3DRenderer->pdds4_BackBuffer;
 else
 {
  v3 = (IDirectDrawSurface *)pD3DRenderer->pdds2_BackBuffer;
  runtime_error;
 }

 _this->dword_000050 = BinkDDSurfaceType(v3);
 _flushall();
}

//----- (MM7.exe::004BE9D8) --------------------------------------------------------
int CVideoPlayer_LoadVideoHeaders(struct CVideoPlayer *_this)
{
 DWORD w;

 strcpy((char *)TmpBuf, "anims\\might7.vid");
 _this->hMightVid = CreateFileW(L"anims\\might7.vid", GENERIC_READ, 1, 0, 3, 0x8000080, 0);
 if (_this->hMightVid == INVALID_HANDLE_VALUE)
 {
  MessageBoxW(0, L"Can't open file: Might7.vid", L"Video File Error", 0);
  return false;
 }

 strcpy((char *)TmpBuf, "anims\\magic7.vid");
 _this->hMagicVid = CreateFileW(L"anims\\magic7.vid", GENERIC_READ, 1, 0, 3, 0x8000080, 0);
 if (_this->hMagicVid == INVALID_HANDLE_VALUE)
 {
  if (!bLoadingFromCD)
  {
   MessageBoxW(0, L"Can't open file: Magic7.vid", L"Video File Error", 0);
   return false;
  }

  wsprintfA((char *)pStringBuffer, "%c:\\%s", cGameCDDriveLetter, "anims\\magic7.vid");
  _this->hMagicVid = CreateFileA((char *)pStringBuffer, GENERIC_READ, 1u, 0, 3u, 0x8000080u, 0);
  if ( _this->hMagicVid == INVALID_HANDLE_VALUE )
  {
   MessageBoxW(0, L"Can't open file: Magic7.vid", L"Video File Error", 0);
   return false;
  }
 }

 ReadFile(_this->hMightVid, &_this->uNumMightVideoHeaders, 4, &w, 0);
 ReadFile(_this->hMagicVid, &_this->uNumMagicVideoHeaders, 4, &w, 0);

 _this->pMightVideoHeaders = (CVideoPlayer_movie_header_struct *)mem_mng.AllocatedNamedBuffer( 0, _this->uNumMightVideoHeaders * sizeof(struct CVideoPlayer_movie_header_struct) + 2, 0);
 _this->pMagicVideoHeaders = (CVideoPlayer_movie_header_struct *)mem_mng.AllocatedNamedBuffer( 0, _this->uNumMagicVideoHeaders * sizeof(struct CVideoPlayer_movie_header_struct) + 2, 0);

 ReadFile(_this->hMightVid, _this->pMightVideoHeaders, _this->uNumMightVideoHeaders * sizeof(struct CVideoPlayer_movie_header_struct), &w, 0);
 ReadFile(_this->hMagicVid, _this->pMagicVideoHeaders, _this->uNumMagicVideoHeaders * sizeof(struct CVideoPlayer_movie_header_struct), &w, 0);

 return true;
}

//----- (004BEE6B) --------------------------------------------------------
void sub_4BEE6B(struct CVideoPlayer *_this, HWND hWnd, int a3, int a4)
{
  int v11; // eax@20
  LONG v13; // [sp-18h] [bp-30h]@7
  LONG v14; // [sp-14h] [bp-2Ch]@7
  //signed int v15; // [sp-10h] [bp-28h]@7
  //signed int v16; // [sp-Ch] [bp-24h]@7
  signed int v17; // [sp-8h] [bp-20h]@7
  struct tagPOINT Point; // [sp+8h] [bp-10h]@7
  //int v19; // [sp+10h] [bp-8h]@5
  //int v20; // [sp+14h] [bp-4h]@5

 unsigned int    uColor;
 unsigned short *pSmackerFrameData;
 unsigned int   *pSurfaceData;
 unsigned int    uSurfacePitch;
 int             x, y;


 pSmackerFrameData = 0;
 pSmackerFrameData = (unsigned short *)malloc(1280 * 1024 * 2);

 if (!pD3DRenderer->dword_040058 || GetFocus() == hWnd)
 {
  if (_this->pSmackerMovie->NewPalette)
    SmackBlitSetPalette(_this->pSmackMoviekBlit, _this->pSmackerMovie->Palette, _this->pSmackerMovie->PalType);
  SmackDoFrame(_this->pSmackerMovie);

  Render_LockFrontBuffer(pD3DRenderer, (void **)&pSurfaceData, &uSurfacePitch);

  if (_this->dword_00005C)
  {
   if (pD3DRenderer->dword_040058)
   {
    Point.y = 0;
    Point.x = 0;
    ClientToScreen(hWnd, &Point);
    v17 = -1;
    v14 = Point.y;
    v13 = Point.x;
   }
   else
   {
    v17 = -1;
    v14 = 0;
    v13 = 0;
   }
   SmackBlitClear((long)_this->pSmackMoviekBlit, (long)pSmackerFrameData, uSurfacePitch * 2, v13, v14, 640, 480, v17);

   _this->dword_00005C = 0;
  }

  Render_RestoreFrontBuffer(pD3DRenderer);
  if (pD3DRenderer->dword_040058)
  {
   Point.y = 0;
   Point.x = 0;
   ClientToScreen(hWnd, &Point);
   if (a4)
   {
    while (SmackToBufferRect(_this->pSmackerMovie, 0))
    {
     SmackBlit(_this->pSmackMoviekBlit, pSmackerFrameData, uSurfacePitch * 2,
               _this->pSmackerMovie->LastRectx + Point.x / 2,
               _this->pSmackerMovie->LastRecty + a3 + Point.y / 2,
               _this->ptr_000030,
               _this->pSmackerMovie->Width,
               _this->pSmackerMovie->LastRectx,
               _this->pSmackerMovie->LastRecty,
               _this->pSmackerMovie->LastRectw,
               _this->pSmackerMovie->LastRecth);
    }
   }
   else
   {
    while (SmackToBufferRect(_this->pSmackerMovie, 0))
    {
     SmackBlit(_this->pSmackMoviekBlit, pSmackerFrameData, uSurfacePitch * 2,
               _this->pSmackerMovie->LastRectx + Point.x,
               _this->pSmackerMovie->LastRecty + Point.y + a3,
               _this->ptr_000030,
               _this->pSmackerMovie->Width,
               _this->pSmackerMovie->LastRectx,
               _this->pSmackerMovie->LastRecty,
               _this->pSmackerMovie->LastRectw,
               _this->pSmackerMovie->LastRecth);
    }
   }
  }
  else
  {
   while (SmackToBufferRect(_this->pSmackerMovie, 0))
   {
    SmackBlit(_this->pSmackMoviekBlit, pSmackerFrameData, uSurfacePitch * 2,
              _this->pSmackerMovie->LastRectx,
              _this->pSmackerMovie->LastRecty + a3,
              _this->ptr_000030,
              _this->pSmackerMovie->Width,
              _this->pSmackerMovie->LastRectx,
              _this->pSmackerMovie->LastRecty,
              _this->pSmackerMovie->LastRectw,
              _this->pSmackerMovie->LastRecth);
   }
  }

  for (y = 0; y < 480; ++y)
    for (x = 0; x < 640; ++x)
    {
     uColor = ((pSmackerFrameData[y * 1280 + x] & 0x001F) * 8) & 0xFF;
     uColor |= ((((((unsigned int)(pSmackerFrameData[y * 1280 + x]) & 0x07E0) >> 5) * 4) & 0xFF) << 8);
     uColor |= ((((((unsigned int)(pSmackerFrameData[y * 1280 + x]) & 0xF800) >> 11) * 8) & 0xFF) << 16);

     pSurfaceData[y * 1280 + x] = uColor;
    }

  Render_UnlockFrontBuffer(pD3DRenderer);
  if (_this->pSmackerMovie->FrameNum != _this->pSmackerMovie->Frames - 1 || _this->dword_000064)
    SmackNextFrame(_this->pSmackerMovie);
  else CVideoPlayer_UnloadAll(_this);
 }

 free(pSmackerFrameData);
}

//----- (004BF3F9) --------------------------------------------------------
int CVideoPlayer_IsAnyMovieLoaded(struct CVideoPlayer *_this)
{
 return _this->pSmackerMovie || _this->pBinkMovie;
}


void CVideoPlayer_ctor(struct CVideoPlayer *_this)
{
 memset(_this, 0, sizeof(struct CVideoPlayer));
}


//----- (MM7.exe::004BE95A) --------------------------------------------------------
int __cdecl VideoPlayer_Smacker_CheckSurfaceFromat()
{

 DDPIXELFORMAT ddpsFrontBuffer;
 ddpsFrontBuffer.dwSize = sizeof(DDPIXELFORMAT);
 ddpsFrontBuffer.dwFlags = DDPF_RGB;

 Render_GetPrimarySurfacePixelFormat(pD3DRenderer, &ddpsFrontBuffer);

 return 0xC0000000;
 if (ddpsFrontBuffer.dwFourCC != 8)
 {
  if (ddpsFrontBuffer.dwRBitMask == 0xF800 &&
      ddpsFrontBuffer.dwGBitMask == 0x07E0 &&
      ddpsFrontBuffer.dwBBitMask == 0x001F)
    return 0xC0000000;
  else if (ddpsFrontBuffer.dwRBitMask == 0x7C00 &&
           ddpsFrontBuffer.dwGBitMask == 0x03E0 &&
           ddpsFrontBuffer.dwBBitMask == 0x001F)
    return 0x80000000;

  MessageBoxW(0, L"Unsupported pixel format.", L"Smacker Error", 0);
 }
 return 0;
}


//----- (004BFE2D) --------------------------------------------------------
void *__fastcall sub_4BFE2D(HWND hWnd, unsigned int uWidth, unsigned int uHeight, char a4)
{
  void *v5; // esi@3
  int v6; // eax@5
  char v10; // al@11
  DDSURFACEDESC2 ddsd2;//int v11; // [sp+Ch] [bp-108h]@7
  int v12; // [sp+10h] [bp-104h]@7
  int v13; // [sp+14h] [bp-100h]@7
  int v14; // [sp+18h] [bp-FCh]@7
  int v15; // [sp+54h] [bp-C0h]@7
  int v16; // [sp+58h] [bp-BCh]@7
  int v17; // [sp+5Ch] [bp-B8h]@7
  int v18; // [sp+74h] [bp-A0h]@7

  int Dst; // [sp+88h] [bp-8Ch]@3
  int v20; // [sp+8Ch] [bp-88h]@3
  int v21; // [sp+90h] [bp-84h]@3
  int v22; // [sp+94h] [bp-80h]@3
  int v23; // [sp+D0h] [bp-44h]@3
  int v24; // [sp+D4h] [bp-40h]@3
  int v25; // [sp+D8h] [bp-3Ch]@3
  int v26; // [sp+F0h] [bp-24h]@3
  int v27; // [sp+F4h] [bp-20h]@1
  struct tagRECT Rect; // [sp+F8h] [bp-1Ch]@11
  IDirectDrawSurface4 *pdds;//int v29; // [sp+108h] [bp-Ch]@7
  int v30; // [sp+10Ch] [bp-8h]@3
 HRESULT hr;
 char    local_0[128];

  v27 = uWidth;

 pdds = 0;
 if (dword_F79D7C != 2 || dword_F79D70 != 4)
 {
  memset(&ddsd2, 0, sizeof(DDSURFACEDESC2));

  ddsd2.dwSize = sizeof(DDSURFACEDESC2);
  ddsd2.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT | DDSD_PIXELFORMAT;
  ddsd2.dwHeight = uHeight;
  ddsd2.dwWidth = uWidth;
  ddsd2.ddpfPixelFormat.dwSize = sizeof(DDPIXELFORMAT);
  ddsd2.ddpfPixelFormat.dwFlags = DDPF_FOURCC;
  ddsd2.ddpfPixelFormat.dwFourCC = 844715353;
  ddsd2.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_VIDEOMEMORY;

  hr = pD3DRenderer->pdd4->CreateSurface(&ddsd2, &pdds, 0);
  if (dword_6BE384_2dacceloff || FAILED(hr))
  {
   memset(&ddsd2.ddpfPixelFormat, 0, sizeof(DDPIXELFORMAT));

   ddsd2.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;
   ddsd2.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

   hr = pD3DRenderer->pdd4->CreateSurface(&ddsd2, &pdds, 0);
   CheckHRESULT((void **)local_0, hr, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Video.cpp", __LINE__, 0);
  }

  v5 = malloc(0x7Cu);
  memset(v5, 0, 0x7Cu);

  *(_DWORD *)v5 = uWidth;
  *((_DWORD *)v5 + 1) = uHeight;
  *((_DWORD *)v5 + 4) = BinkDDSurfaceType((IDirectDrawSurface *)pdds);
  *((_DWORD *)v5 + 14) = 0;
 }
 else __asm int 3;  //ddraw2

 *((_DWORD *)v5 + 9) = GetSystemMetrics(0);
 *((_DWORD *)v5 + 10) = GetSystemMetrics(1);
 *((_DWORD *)v5 + 11) = 16;
 *((_DWORD *)v5 + 18) = (int)pdds;
 *((_DWORD *)v5 + 19) = 0;
 *((_DWORD *)v5 + 22) = (int)hWnd;
 v10 = a4;
 *((_DWORD *)v5 + 26) = 0;
 *((_DWORD *)v5 + 23) = 0;
 *((_DWORD *)v5 + 29) = v10 & 0x1F;
 *((_DWORD *)v5 + 30) = 1;
 GetWindowRect(hWnd, &Rect);
 *((_DWORD *)v5 + 2) = Rect.right - Rect.left;
 *((_DWORD *)v5 + 3) = Rect.bottom - Rect.top;
 *((_DWORD *)v5 + 7) = Rect.left;
 *((_DWORD *)v5 + 8) = Rect.top;
 Rect.left = 0;
 Rect.top = 0;
 ClientToScreen(hWnd, (LPPOINT)&Rect);
 *((_DWORD *)v5 + 7) = Rect.left - *((_DWORD *)v5 + 7);
 *((_DWORD *)v5 + 8) = Rect.top - *((_DWORD *)v5 + 8);
 GetClientRect(hWnd, &Rect);
 *((_DWORD *)v5 + 12) = *((_DWORD *)v5 + 2) - Rect.right;
 *((_DWORD *)v5 + 13) = *((_DWORD *)v5 + 3) - Rect.bottom;
 *((_DWORD *)v5 + 2) = *(_DWORD *)v5 + *((_DWORD *)v5 + 12);
 *((_DWORD *)v5 + 3) = *((_DWORD *)v5 + 1) + *((_DWORD *)v5 + 13);

 BinkBufferSetOffset(v5, 0, 0);
 BinkBufferSetScale(v5, *(_DWORD *)v5, *((_DWORD *)v5 + 1));
 return v5;
}

//----- (004C0133) --------------------------------------------------------
int BinkLockSurface(unsigned char *pBinkBuffer)
{
 DDSURFACEDESC2 ddsd2;//int v8; // [sp+Ch] [bp-7Ch]@10
  int Dst; // [sp+1Ch] [bp-6Ch]@4
  int v10; // [sp+2Ch] [bp-5Ch]@8
  int v11; // [sp+30h] [bp-58h]@14
  int v12; // [sp+40h] [bp-48h]@8
 IDirectDrawSurface *pdds;
 HRESULT             hr;

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
 {
  pdds = (IDirectDrawSurface *)*(_DWORD *)(pBinkBuffer + 72);
  if (pdds)
  {
   memset(&ddsd2, 0, sizeof(DDSURFACEDESC2));
   ddsd2.dwSize = sizeof(DDSURFACEDESC2);

   while (1)
   {
    hr = pdds->Lock(0, (DDSURFACEDESC *)&ddsd2, DDLOCK_WAIT, 0);
    if (hr == S_OK)
      break;

    *(_BYTE *)(pBinkBuffer + 19) |= 4u;
    pdds->Restore();
    return false;
   }

   *(_DWORD *)(pBinkBuffer + 20) = (int)ddsd2.lpSurface;
   *(_DWORD *)(pBinkBuffer + 24) = ddsd2.lPitch;
   *(_DWORD *)(pBinkBuffer + 112) = (int)ddsd2.lpSurface;
  }
 }
 else
   __asm int 3;  //ddraw2

 return true;
}

//----- (004C01FB) --------------------------------------------------------
HRESULT BinkBufferUnlock(unsigned char *pBinkBuffer)
{
 IDirectDrawSurface *pdds;
 HRESULT hr;

 pdds = (IDirectDrawSurface *)*(_DWORD *)(pBinkBuffer + 72);
 if (pdds)
 {
  hr = pdds->Unlock(0);

  *(_BYTE *)(pBinkBuffer + 19) &= 0xFBu;
  *(_DWORD *)(pBinkBuffer + 20) = 0;
  *(_DWORD *)(pBinkBuffer + 24) = 0;
 }
 return hr;
}