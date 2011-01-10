#include "VideoPlayer.h"

#include <stdio.h>


#include "AudioPlayer.h"
#include "clock.h"
#include "data.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"
#include "Game.h"

#include "GUI\GUI.h"

#include "libs\Smacker\Smacker.h"
#include "libs\Bink\Bink.h"
#include "libs\AIL\AIL.h" // parasite include, have to move all ail stuff to AudioPlayer class




Result::Code VideoPlayer::StopMovie()
{
 if (bPlayingMovie)
 {
  bStopBeforeSchedule = true;
  return Result::Success;
 }

 return Result::Generic;
}

Result::Code VideoPlayer::BinkPlayMovie(unsigned int uOutX, unsigned int uOutY)
{
 if (!pBinkMovie)
   return Result::Generic;

 BinkDrawFrame(uOutX, uOutY);
 while (pBinkMovie)
 {
    MSG msg;
    while (PeekMessageA(&msg, 0, 0, 0, PM_REMOVE))
    {
     if (msg.message == WM_QUIT)
       Game_DeinitializeAndTerminate(0);
     if (msg.message == WM_PAINT)
       break;

     TranslateMessage(&msg);
     DispatchMessageA(&msg);
    }

    sub_435748_PlayerCreationUI_MessageProc();

    if (bStopBeforeSchedule)
      break;
    else if (!BinkWait(pBinkMovie))
       BinkDrawFrame(uOutX, uOutY);
 }

 return Result::Success;
}


Result::Code VideoPlayer::SmackPlayMovie(unsigned int uOutX, unsigned int uOutY)
{
 if (!pSmackerMovie)
   return Result::Generic;

 SmackDrawFrame(uOutX, uOutY);
 while (pSmackerMovie)
 {
    MSG msg;
    while (PeekMessageA(&msg, 0, 0, 0, PM_REMOVE))
    {
     if (msg.message == WM_QUIT)
       Game_DeinitializeAndTerminate(0);
     else if (msg.message == WM_PAINT)
       break;

     TranslateMessage(&msg);
     DispatchMessageA(&msg);
    }
    sub_435748_PlayerCreationUI_MessageProc();

    if (bStopBeforeSchedule)
      break;
    else if (!SmackWait(pSmackerMovie))
       SmackDrawFrame(uOutX, uOutY);
 }

 return Result::Success;
}


//----- (004BE70E) --------------------------------------------------------
Result::Code VideoPlayer::PlayMovie(const char *pMovieName, Rect<unsigned int> cOutRegion, unsigned int bLoop)
{
 if (OpenMovie(pMovieName))
   return Result::Generic;

 bStopBeforeSchedule = false;
 bLoopPlaying = bLoop;

 bPlayingMovie = true;

 Render_ClearAndPresent(pRender, 0xFF000000);

 dword_4E28F8_PartyCantJumpIfTrue = 16;

 
 ShowCursor(false);
 if (pVideoPlayer->uMovieFormat == Video::Format::Bink)
   BinkPlayMovie(cOutRegion.x.min, cOutRegion.y.min);
 else if (pVideoPlayer->uMovieFormat == Video::Format::Smack)
   SmackPlayMovie(cOutRegion.x.min, cOutRegion.y.min);

 ShowCursor(true);
 bPlayingMovie = false;

 dword_4E28F8_PartyCantJumpIfTrue = 0;

 return Result::Success;
}






//----- (MM7.exe::004BEB41) --------------------------------------------------------
//----- (MM7.exe::004BE9D8) --------------------------------------------------------
Result::Code VideoPlayer::Initialize(OSWindow *pTargetWindow, BaseRender *pTargetRenderer, AudioPlayer *pExternalAudioPlayer)
{
 if (!pTargetWindow)
   return Result::InvalidParams;

 hMightVid = CreateFileW(L"anims\\might7.vid", GENERIC_READ, 1, 0, 3, 0x8000080, 0);
 if (hMightVid == INVALID_HANDLE_VALUE)
 {
  MessageBoxW(0, L"Can't open file: Might7.vid", L"VideoPlayer error", 0);
  return Result::NotFound;
 }

 hMagicVid = CreateFileW(L"anims\\magic7.vid", GENERIC_READ, 1, 0, 3, 0x8000080, 0);
 if (hMagicVid == INVALID_HANDLE_VALUE && bCanLoadFromCD)
 {
  wchar_t pCDPath[512];
  wsprintfW(pCDPath, L"%c:\\%s", cGameCDDriveLetter, L"anims\\magic7.vid");

  hMagicVid = CreateFileW(pCDPath, GENERIC_READ, 1, 0, 3, 0x8000080, 0);
 }
 if (hMagicVid == INVALID_HANDLE_VALUE)
 {
  MessageBoxW(0, L"Can't open file: Magic7.vid", L"VideoPlayer error", 0);
  return Result::NotFound;
 }
 
 DWORD w;
 ReadFile(hMightVid, &uNumMightVideoHeaders, 4, &w, 0);
 ReadFile(hMagicVid, &uNumMagicVideoHeaders, 4, &w, 0);

 pMightVideoHeaders = NamedMemAlloc(VideoPlayer::MovieHeader, uNumMightVideoHeaders, "Might video headers");
 pMagicVideoHeaders = NamedMemAlloc(VideoPlayer::MovieHeader, uNumMagicVideoHeaders, "Magic video headers");

 ReadFile(hMightVid, pMightVideoHeaders, uNumMightVideoHeaders * sizeof(VideoPlayer::MovieHeader), &w, 0);
 ReadFile(hMagicVid, pMagicVideoHeaders, uNumMagicVideoHeaders * sizeof(VideoPlayer::MovieHeader), &w, 0);


 pAudioPlayer = pExternalAudioPlayer;
 if (pAudioPlayer)
 {
  BinkSetSoundSystem(BinkOpenMiles, pAudioPlayer->hDigDriver);  
  SmackSoundUseMSS(pAudioPlayer->hDigDriver);
 }
 else
   BinkSetSoundSystem(BinkOpenMiles, 0);
 

 pSmackerMovie = 0;
 pSmackerBuffer = 0;
 
 pBinkMovie = 0;
 pBinkBuffer = 0;
 
 bFirstFrame = true;
 bUsingSmackerMMX = SmackUseMMX(1);

 pWindow = pTargetWindow;
 pRender = pTargetRenderer;

 sBinkDirectDrawSurfaceType = BinkDDSurfaceType((IDirectDrawSurface *)pRender->pdds4_BackBuffer);

 return Result::Success;
}






VideoPlayer::VideoPlayer()
{
 pSmackerMovie = 0;
 pSmackerBuffer = 0;
 pSmackMovieBlit = 0;

 pBinkMovie = 0;
 pBinkBuffer = 0;

 pMightVideoHeaders = 0;
 pMagicVideoHeaders = 0;

 uNumMightVideoHeaders = 0;
 uNumMagicVideoHeaders = 0;

 hMightVid = INVALID_HANDLE_VALUE;
 hMagicVid = INVALID_HANDLE_VALUE;

 pWindow = 0;

 pSomeSmackerBuffer = 0;

 uMovieFormat = Video::Format::Unknown;

 bUsingSmackerMMX = false;
 bStopBeforeSchedule = false;
 bPlayingMovie = false;
}



//----- (MM7.exe::004BF411) --------------------------------------------------------
Result::Code VideoPlayer::OpenMovie(const char *pVideoName)
{
 wsprintfA(pCurrentMovieName, "%s.bik", pVideoName);

 pBinkMovie = OpenBinkMovie(pCurrentMovieName);
 if (pBinkMovie)
 {
  uMovieFormat = Video::Format::Bink;
  dword_0000A0 = 1;
  pBinkBuffer = BinkCreateBuffer(pBinkMovie->Width, pBinkMovie->Height, 0);

  bFirstFrame = true;
  return Result::Success;
 }

 wsprintfA(pCurrentMovieName, "%s.smk", pVideoName);
 pSmackerMovie = OpenSmackMovie(pCurrentMovieName);
 if (!pSmackerMovie)
 {
  wsprintfA(pCurrentMovieName, "Can't find movie: \"%s\"", pVideoName);
  MessageBoxA(0, pCurrentMovieName, "VideoPlayer::OpenMovie", 0);

  pCurrentMovieName[0] = 0;
  return Result::NotFound;
 }

 uMovieFormat = Video::Format::Smack;
 dword_0000A0 = 2;

 pSomeSmackerBuffer = NamedMemAlloc(unsigned char, pSmackerMovie->Width * pSmackerMovie->Height, "VideoPlayer some Smacker buffer");
 if (!pSomeSmackerBuffer)
 {
  UnloadAll();
  MessageBoxW(0, L"Out of memory", L"VideoPlayer::OpenMovie", 0);

  return Result::OutOfMemory;
 }


 SmackToBuffer(pSmackerMovie, 0, 0,
               pSmackerMovie->Width, pSmackerMovie->Height,
               pSomeSmackerBuffer, 0);
  
 pSmackMovieBlit = SmackBlitOpen(SmackCheckSurfaceFromat());
 if (!pSmackMovieBlit)
 {
  UnloadAll();
  MessageBoxW(0, L"Failed to open Smacker Blit API", L"VideoPlayer::OpenMovie", 0);

  return Result::Generic;
 }

 bFirstFrame = true;
 return Result::Success;
}

//----- (MM7.exe::004BF1E6) --------------------------------------------------------
HSMACK VideoPlayer::OpenSmackMovie(const char *pVideoFile)
{
 for (unsigned int i = 0; i < uNumMightVideoHeaders; ++i)
 {
  if (!strcmpi(pMightVideoHeaders[i].sVideoName, pVideoFile))
  {
   SetFilePointer(hMightVid, pMightVideoHeaders[i].uContainerOffset, 0, FILE_BEGIN);
   return SmackOpen(hMightVid, 28992, -1);
  }
 }

 for (unsigned int i = 0; i < uNumMagicVideoHeaders; ++i)
 {
  if (!strcmpi(pMagicVideoHeaders[i].sVideoName, pVideoFile))
  {
   SetFilePointer(hMagicVid, pMagicVideoHeaders[i].uContainerOffset, 0, FILE_BEGIN);
   return SmackOpen(hMagicVid, 28992, -1);
  }
 }

 return 0;
}

//----- (MM7.exe::004BEBD7) --------------------------------------------------------
void VideoPlayer::UnloadAll()
{
 if (pBinkMovie)
 {
  BinkPause(pBinkMovie, true);
  Sleep(300);
  BinkClose(pBinkMovie);
  pBinkMovie = 0;
 }

 if (pBinkBuffer)
 {
  pBinkBuffer->pTargetDDrawSurface->Release();
  pBinkBuffer->pTargetDDrawSurface = 0;

  MemFree(pBinkBuffer);
  pBinkBuffer = 0;
 }

 if (pSmackerMovie)
 {
  SmackSoundOnOff(pSmackerMovie, false);
  SmackClose(pSmackerMovie);
  pSmackerMovie = 0;
 }

 if (pSmackerBuffer)
 {
  SmackBufferClose(pSmackerBuffer);
  pSmackerBuffer = 0;
 }

 if (pSmackMovieBlit)
 {
  SmackBlitClose(pSmackMovieBlit);
  pSmackMovieBlit = 0;
 }

 uMovieFormat = Video::Format::Unknown;
 dword_0000A0 = 0;

 pCurrentMovieName[0] = 0;
 if (pAudioPlayer->hAILRedbook)
 {
  if (!dword_F8BC10)
    AIL_redbook_resume(pAudioPlayer->hAILRedbook);
 }

 cEventTimer.Resume();
}

//----- (004BED4F) --------------------------------------------------------
Result::Code VideoPlayer::BinkDrawFrame(unsigned int uOutX, unsigned int uOutY)
{
  //int v6; // edx@6
  //int v7; // edx@6
  //int v8; // ecx@6
  //RECT rcSrc;//int v9; // [sp+8h] [bp-20h]@10
  //int v10; // [sp+Ch] [bp-1Ch]@10
  //int v11; // [sp+10h] [bp-18h]@10
  //int v12; // [sp+14h] [bp-14h]@10
  //RECT rcDst;//int v13; // [sp+18h] [bp-10h]@6
  //int v14; // [sp+1Ch] [bp-Ch]@6
  //int v15; // [sp+20h] [bp-8h]@6
  //int v16; // [sp+24h] [bp-4h]@8


 BinkDoFrame(pBinkMovie);
 BinkGetRects(pBinkMovie, pBinkBuffer->uBinkDDSurfaceType);




 RECT rcDst = {uOutX,                       uOutY,
               uOutX + pBinkBuffer->uWidth, uOutY + pBinkBuffer->uHeight};
 if (pD3DRenderer->bWindowMode)
 {
  POINT ptWindowOffset = {0, 0};
  ClientToScreen(pWindow->GetAPIHandle(), &ptWindowOffset);

  rcDst.left += ptWindowOffset.x;
  rcDst.right += ptWindowOffset.x;

  rcDst.top += ptWindowOffset.y;
  rcDst.bottom += ptWindowOffset.y;
 }

 RECT rcSrc = {0,                   0,
               pBinkBuffer->uWidth, pBinkBuffer->uHeight};
   /*if (a4) bool strech to window
   {
    rcDst.right = pBinkBuffer->uWidth + v8;
    rcDst.bottom = pBinkBuffer->uHeight + v6;
   }
   rcSrc.left = 0;
   rcSrc.top = 0;
   rcSrc.right = pBinkBuffer->uWidth;
   rcSrc.bottom = pBinkBuffer->uHeight;*/

 if (!BinkLockBuffer(pBinkBuffer))
 {
  BinkCopyToBuffer(pBinkMovie, pBinkBuffer->pDDrawSurfaceData, pBinkBuffer->uDDrawSurfacePitch,
                   pBinkBuffer->uHeight,
                   0, 0,
                   pBinkBuffer->uBinkDDSurfaceType);
  BinkUnlockBuffer(pBinkBuffer);
 }



 BltToFrontBuffer(&rcDst, pBinkBuffer->pTargetDDrawSurface, &rcSrc, DDBLT_WAIT);
 if (bLoopPlaying || pBinkMovie->FrameRate != pBinkMovie->Data1 - 1)
   BinkNextFrame(pBinkMovie);
 else
   UnloadAll();

 return Result::Success;
}

//----- (MM7.exe::004BF141) --------------------------------------------------------
HBINK VideoPlayer::OpenBinkMovie(const char *pVideoFile)
{
 for (unsigned int i = 0; i < uNumMightVideoHeaders; ++i)
 {
  if (!strcmpi(pMightVideoHeaders[i].sVideoName, pVideoFile))
  {
   SetFilePointer(hMightVid, pMightVideoHeaders[i].uContainerOffset, 0, FILE_BEGIN);
   return BinkOpen(hMightVid, 0x82000000);
  }
 }

 for (unsigned int i = 0; i < uNumMagicVideoHeaders; ++i)
 {
  if (!strcmpi(pMagicVideoHeaders[i].sVideoName, pVideoFile))
  {
   SetFilePointer(hMagicVid, pMagicVideoHeaders[i].uContainerOffset, 0, FILE_BEGIN);
   return BinkOpen(hMagicVid, 0x82000000);
  }
 }

 return 0;
}

//----- (004BEE6B) --------------------------------------------------------
void VideoPlayer::SmackDrawFrame(unsigned int uOutX, unsigned int uOutY)
{
  int v11; // eax@20
  //LONG v13; // [sp-18h] [bp-30h]@7
  //LONG v14; // [sp-14h] [bp-2Ch]@7
  //signed int v15; // [sp-10h] [bp-28h]@7
  //signed int v16; // [sp-Ch] [bp-24h]@7
  //signed int v17; // [sp-8h] [bp-20h]@7
  //struct tagPOINT Point; // [sp+8h] [bp-10h]@7
  //int v19; // [sp+10h] [bp-8h]@5
  //int v20; // [sp+14h] [bp-4h]@5

 unsigned int    uColor;
 unsigned short *pSmackerFrameData;
 unsigned int   *pSurfaceData;
 unsigned int    uSurfacePitch;


 pSmackerFrameData = 0;
 //pSmackerFrameData = MemAlloc(unsigned short, 1280 * 1024);
 pSmackerFrameData = MemAlloc(unsigned short, 640 * 480);


 if (pSmackerMovie->NewPalette)
   SmackBlitSetPalette(pSmackMovieBlit, pSmackerMovie->Palette, pSmackerMovie->PalType);
 SmackDoFrame(pSmackerMovie);

 Render_LockFrontBuffer(pD3DRenderer, (void **)&pSurfaceData, &uSurfacePitch);

 if (bFirstFrame)
 {
  SmackBlitClear(pSmackMovieBlit, pSmackerFrameData, 640 * 2, uOutX, uOutY, 640, 480, -1);

  bFirstFrame = false;
 }

 Render_RestoreFrontBuffer(pD3DRenderer);
 /*if (a4) //bool strech
 {
    while (SmackToBufferRect(pSmackerMovie, 0))
    {
     SmackBlit(pSmackMovieBlit, pSmackerFrameData, 640 * 2,
               pSmackerMovie->LastRectx + uOutX + 0 / 2,
               pSmackerMovie->LastRecty + uOutY + 0 / 2,
               pSomeSmackerBuffer,
               pSmackerMovie->Width,
               pSmackerMovie->LastRectx,
               pSmackerMovie->LastRecty,
               pSmackerMovie->LastRectw,
               pSmackerMovie->LastRecth);
    }
 }
 else
 {*/
   while (SmackToBufferRect(pSmackerMovie, 0))
   {
    SmackBlit(pSmackMovieBlit, pSmackerFrameData, 640 * 2,
              pSmackerMovie->LastRectx + uOutX,
              pSmackerMovie->LastRecty + uOutY,
              pSomeSmackerBuffer,
              pSmackerMovie->Width,
              pSmackerMovie->LastRectx,
              pSmackerMovie->LastRecty,
              pSmackerMovie->LastRectw,
              pSmackerMovie->LastRecth);
   }
 //}


 POINT ptWindowOffset = {0, 0};
 if (pD3DRenderer->bWindowMode)
   ClientToScreen(pWindow->GetAPIHandle(), &ptWindowOffset);


 for (unsigned int y = 0; y < 480; ++y)
   for (unsigned x = 0; x < 640; ++x)
   {
     uColor = ((pSmackerFrameData[y * 640 + x] & 0x001F) * 8) & 0xFF;
     uColor |= ((((((unsigned int)(pSmackerFrameData[y * 640 + x]) & 0x07E0) >> 5) * 4) & 0xFF) << 8);
     uColor |= ((((((unsigned int)(pSmackerFrameData[y * 640 + x]) & 0xF800) >> 11) * 8) & 0xFF) << 16);

    pSurfaceData[(ptWindowOffset.y + y) * uSurfacePitch + ptWindowOffset.x + x] = uColor;
   }
 Render_UnlockFrontBuffer(pD3DRenderer);


 if (bLoopPlaying || pSmackerMovie->FrameNum != pSmackerMovie->Frames - 1)
   SmackNextFrame(pSmackerMovie);
 else UnloadAll();


 MemFree(pSmackerFrameData);
}

//----- (004BF3F9) --------------------------------------------------------
bool VideoPlayer::IsAnyMovieLoaded()
{
 return pSmackerMovie || pBinkMovie;
}


//----- (MM7.exe::004BE95A) --------------------------------------------------------
unsigned int VideoPlayer::SmackCheckSurfaceFromat()
{
 return 0xC0000000;
 /*
 DDPIXELFORMAT ddpsFrontBuffer;
 ddpsFrontBuffer.dwSize = sizeof(DDPIXELFORMAT);
 ddpsFrontBuffer.dwFlags = DDPF_RGB;

 Render_GetPrimarySurfacePixelFormat(pD3DRenderer, &ddpsFrontBuffer);

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
 return 0;*/
}


//----- (004BFE2D) --------------------------------------------------------
HBINKBUF VideoPlayer::BinkCreateBuffer(unsigned int uWidth, unsigned int uHeight, char a4)
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

  v5 = MemAlloc(char, 0x7C);
  memset(v5, 0, 0x7C);

  *(_DWORD *)v5 = uWidth;
  *((_DWORD *)v5 + 1) = uHeight;
  *((_DWORD *)v5 + 4) = BinkDDSurfaceType((IDirectDrawSurface *)pdds);
  *((_DWORD *)v5 + 14) = 0;


 *((_DWORD *)v5 + 9) = GetSystemMetrics(0);
 *((_DWORD *)v5 + 10) = GetSystemMetrics(1);
 *((_DWORD *)v5 + 11) = 16;
 *((_DWORD *)v5 + 18) = (int)pdds;
 *((_DWORD *)v5 + 19) = 0;
 *((_DWORD *)v5 + 22) = (int)pWindow->GetAPIHandle();
 v10 = a4;
 *((_DWORD *)v5 + 26) = 0;
 *((_DWORD *)v5 + 23) = 0;
 *((_DWORD *)v5 + 29) = v10 & 0x1F;
 *((_DWORD *)v5 + 30) = 1;
 GetWindowRect(pWindow->GetAPIHandle(), &Rect);
 *((_DWORD *)v5 + 2) = Rect.right - Rect.left;
 *((_DWORD *)v5 + 3) = Rect.bottom - Rect.top;
 *((_DWORD *)v5 + 7) = Rect.left;
 *((_DWORD *)v5 + 8) = Rect.top;
 Rect.left = 0;
 Rect.top = 0;
 ClientToScreen(pWindow->GetAPIHandle(), (LPPOINT)&Rect);
 *((_DWORD *)v5 + 7) = Rect.left - *((_DWORD *)v5 + 7);
 *((_DWORD *)v5 + 8) = Rect.top - *((_DWORD *)v5 + 8);
 GetClientRect(pWindow->GetAPIHandle(), &Rect);
 *((_DWORD *)v5 + 12) = *((_DWORD *)v5 + 2) - Rect.right;
 *((_DWORD *)v5 + 13) = *((_DWORD *)v5 + 3) - Rect.bottom;
 *((_DWORD *)v5 + 2) = *(_DWORD *)v5 + *((_DWORD *)v5 + 12);
 *((_DWORD *)v5 + 3) = *((_DWORD *)v5 + 1) + *((_DWORD *)v5 + 13);

 BinkBufferSetOffset(v5, 0, 0);
 BinkBufferSetScale(v5, *(_DWORD *)v5, *((_DWORD *)v5 + 1));
 return (HBINKBUF)v5;
}

//----- (004C0133) --------------------------------------------------------
Result::Code VideoPlayer::BinkLockBuffer(HBINKBUF pBinkBuffer)
{
 DDSURFACEDESC2 ddsd2;//int v8; // [sp+Ch] [bp-7Ch]@10
  int Dst; // [sp+1Ch] [bp-6Ch]@4
  int v10; // [sp+2Ch] [bp-5Ch]@8
  int v11; // [sp+30h] [bp-58h]@14
  int v12; // [sp+40h] [bp-48h]@8
 IDirectDrawSurface *pdds;
 HRESULT             hr;


 pdds = pBinkBuffer->pTargetDDrawSurface;
 if (pdds)
 {
   memset(&ddsd2, 0, sizeof(DDSURFACEDESC2));
   ddsd2.dwSize = sizeof(DDSURFACEDESC2);

   while (1)
   {
    hr = pdds->Lock(0, (DDSURFACEDESC *)&ddsd2, DDLOCK_WAIT, 0);
    if (hr == S_OK)
      break;

    pBinkBuffer->uBinkDDSurfaceType |= 0x04000000;
    pdds->Restore();
    return Result::Generic;
   }

   pBinkBuffer->pDDrawSurfaceData = ddsd2.lpSurface;
   pBinkBuffer->uDDrawSurfacePitch = ddsd2.lPitch;
   pBinkBuffer->pDDrawSurfaceData_ = ddsd2.lpSurface;
  }


 return Result::Success;
}

//----- (004C01FB) --------------------------------------------------------
Result::Code VideoPlayer::BinkUnlockBuffer(HBINKBUF pBinkBuffer)
{
 IDirectDrawSurface *pdds;

 pdds = pBinkBuffer->pTargetDDrawSurface;
 if (pdds)
 {
  pdds->Unlock(0);

  pBinkBuffer->uBinkDDSurfaceType &= 0xFBFFFFFF;
  pBinkBuffer->pDDrawSurfaceData = 0;
  pBinkBuffer->uDDrawSurfacePitch = 0;
 }
 return Result::Success;
}



//----- (004BECBD) --------------------------------------------------------
int sub_4BECBD(int a1, int a2)
{
 if (!bNoVideo)
   pVideoPlayer->StopMovie();

 compile_error();
 return 0; //RGBTexture_Release((int)pVideoPlayer);
}

//----- (004BECD5) --------------------------------------------------------
void VideoPlayer::sub_4BECD5(unsigned int a2)
{
  int v2; // eax@1
  int v3; // esi@1

  v3 = (int)this;
  v2 = *(_DWORD *)(v3 + 156);
  if ( v2 == 2 )
  {
    if ( a2 )
    {
      while ( *(_DWORD *)(*(_DWORD *)(v3 + 128) + 20) < a2 )
      {
        BinkDoFrame(*(HBINK *)(v3 + 128));
        BinkNextFrame(*(HBINK *)(v3 + 128));
      }
    }
  }
  else
  {
    if ( v2 != 1 )
      return;
    SmackSoundOnOff(*(HSMACK *)(v3 + 40), 0);
    if ( a2 )
    {
      while ( *(_DWORD *)(*(_DWORD *)(v3 + 40) + 884) < a2 )
      {
        SmackDoFrame(*(HSMACK *)(v3 + 40));
        SmackNextFrame(*(HSMACK *)(v3 + 40));
      }
    }
  }
 UnloadAll();
}

//----- (004BF08B) --------------------------------------------------------
void VideoPlayer::sub_4BF08B(int a2)
{
  int v2; // eax@1
  int v3; // esi@1
  int v4; // ebx@1
  int v5; // edi@1
  signed int v6; // eax@1

  //VideoPlayer::dword_00006C may be passed as this

  v3 = (int)this;
  pD3DRenderer->BeginScene();
  v4 = (int)pD3DRenderer->pTargetSurface;
  v5 = pD3DRenderer->uTargetSurfacePitch;
  v6 = SmackCheckSurfaceFromat();
  SmackToBuffer(*(HSMACK *)(v3 + 40), 8, 8, 2 * v5, pD3DRenderer->dword_000014, (void *)v4, v6);
  v2 = *(_DWORD *)(v3 + 40);
  if ( *(_DWORD *)(v2 + 104) )
  {
    SmackBufferNewPalette(*(_DWORD *)(v3 + 44), v2 + 108, *(_WORD *)(v2 + 880));
    SmackColorRemapWithTrans(
      *(_DWORD *)(v3 + 40),
      *(_DWORD *)(v3 + 44) + 60,
      *(_DWORD *)(*(_DWORD *)(v3 + 44) + 44),
      *(_DWORD *)(*(_DWORD *)(v3 + 44) + 1084),
      1000);
  }
  SmackDoFrame((HSMACK)*(_DWORD *)(v3 + 40));
  if ( *(_DWORD *)(*(_DWORD *)(v3 + 40) + 884) != *(_DWORD *)(*(_DWORD *)(v3 + 40) + 12) - 1 || *(_DWORD *)(v3 + 100) )
    SmackNextFrame((HSMACK)*(_DWORD *)(v3 + 40));
  else
    ((VideoPlayer *)v3)->UnloadAll();
  pD3DRenderer->EndScene();
}

//----- (004BF28F) --------------------------------------------------------
void VideoPlayer::sub_4BF28F(char a2, int a3)
{
  int v3; // esi@1
  void *v4; // ecx@3
  int v5; // eax@4
  int v6; // ecx@7
  int v7; // eax@7
  int v8; // eax@7
  int v9; // ebx@8
  signed int v10; // eax@8
  signed __int64 v11; // qax@9
  const char *v12; // [sp-20h] [bp-54h]@3
  int v13; // [sp-1Ch] [bp-50h]@3
  char v14; // [sp-18h] [bp-4Ch]@3
  int v15; // [sp-14h] [bp-48h]@6
  int v16; // [sp-10h] [bp-44h]@6
  int v17; // [sp-Ch] [bp-40h]@6
  const char *v18; // [sp-8h] [bp-3Ch]@3
  int v19; // [sp-4h] [bp-38h]@3
  char Str2[48]; // [sp+Ch] [bp-28h]@4
  char *v21; // [sp+3Ch] [bp+8h]@3
  char *v22; // [sp+3Ch] [bp+8h]@5
  int v23; // [sp+3Ch] [bp+8h]@8

  compile_error();
/*
  v3 = (int)_this;
  if ( !*(_DWORD *)(_this + 84) )
  {
    InitializeSomething();
    *(_DWORD *)(v3 + 100) = a3;
    if ( *(_BYTE *)(v3 + 260) == 1 )
    {
      v19 = 925;
      v18 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Video.cpp";
      v4 = &v14;
      v21 = &v14;
      v13 = (int)(&a2 + 3);
      v12 = "Unsupported Bink playback!";
LABEL_6:
      Game_sub_40E2C8(v4, v12, v13);
      sub_466D09(&a3, *(int *)&v14, v15, v16, v17, v18, v19);
      return;
    }
    wsprintfA(Str2, "%s.smk", a2);
    v5 = (int)((VideoPlayer *)v3)->OpenSmackMovie(Str2);
    *(_DWORD *)(v3 + 40) = v5;
    if ( !v5 )
    {
      ((VideoPlayer *)v3)->UnloadAll();
      wsprintfA((char *)TmpBuf, "Can't load %s", Str2);
      v19 = 937;
      v18 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Video.cpp";
      v4 = &v14;
      v22 = &v14;
      v13 = (int)(&a2 + 3);
      v12 = (char *)TmpBuf;
      goto LABEL_6;
    }
    v19 = a2;
    *(_DWORD *)(v3 + 156) = 1;
    strcpy((char *)(v3 + 164), (const char *)v19);
    v7 = *(_DWORD *)(v3 + 40);
    *(_DWORD *)(v3 + 160) = 1;
    v8 = SmackBufferOpen(
           *(_DWORD *)(v3 + 112),
           4,
           *(_WORD *)(v7 + 4),
           *(_WORD *)(v7 + 8),
           *(_WORD *)(v7 + 4),
           *(_WORD *)(v7 + 8));
    *(_DWORD *)(v3 + 44) = v8;
    if ( v8 )
    {
      pD3DRenderer->BeginScene();
      v9 = pD3DRenderer->uTargetSurfacePitch;
      v23 = (int)pD3DRenderer->pTargetSurface;
      v10 = VideoPlayer_Smacker_CheckSurfaceFromat();
      SmackToBuffer(*(HSMACK *)(v3 + 40), 8, 8, 2 * v9, pD3DRenderer->dword_000014, (void *)v23, v10);
      pD3DRenderer->EndScene();
    }
    v19 = 32767;
    v11 = (signed __int64)(pSoundVolumeLevels[uSoundVolumeMultiplier] * 32767.0);
    SmackVolumePan(v6, HIDWORD(v11), *(_DWORD *)(v3 + 40), 1040384, v11, 32767);
  }*/
}

//----- (004BF73A) --------------------------------------------------------
void VideoPlayer::sub_4BF73A()
{
  unsigned __int8 v1; // bl@1
  int v2; // edi@1
  int v4; // edi@1
  char Source; // [sp+Ch] [bp-40h]@1

  v4 = *(_DWORD *)((int)this + 160);
  v1 = *(_BYTE *)((int)this + 100);
  strcpy(&Source, (const char *)((int)this + 164));
  UnloadAll();
  v2 = v4 - 1;
  if ( v2 )
  {
    if ( v2 == 1 )
      //OpenMovie(&Source, v1);
      OpenMovie(&Source);
  }
  else
  {
    sub_4BF28F((unsigned int)&Source, v1);
  }
}

//----- (004BF5B2) --------------------------------------------------------
int VideoPlayer::sub_4BF5B2()
{
  int result; // eax@1
  int v2; // esi@1
  int v3; // edi@2

  v2 = (int)this;
  result = *(_DWORD *)(v2 + 156);
  if ( result == 2 )
  {
    v3 = (int)this + 128;
    BinkGoto(*(_DWORD *)(v2 + 128), 1, 0);
    BinkDoFrame((HBINK)*(_DWORD *)v3);
    BinkNextFrame((HBINK)*(_DWORD *)v3);
  }
  else
  {
    if ( result != 1 )
      return result;
    SmackGoto(*(_DWORD *)((int)this + 40), 1);
    if (dword_F79D70 != 4 )
    {
      SmackDoFrame((HSMACK)*(_DWORD *)(v2 + 40));
      SmackNextFrame((HSMACK)*(_DWORD *)(v2 + 40));
    }
  }
  sub_469E24((int)pGame->pGUICursor);
  result = (int)ptr_507BC0;
  if (ptr_507BC0)
  {
    if (ptr_507BC0->dword_00001C == 165 )
    {
      if ( !*(_DWORD *)(v2 + 40) )
      {
        dword_F8BC10 = 1;
        sub_4BD8B5();
        GUIWindowDelete(ptr_507BC0);
        pParty->dword_007778 &= 0xFFFFFFFDu;
        result = sub_44622E_EnterHouse(165);
        if ( result )
        {
          pAudioPlayer->sub_4AA306(0, 0, 0, -1, 0, 0, 0, 0);
          ptr_507BC0 = GUIWindowCreate(0, 0, 640, 480, 25, (GUIButton*)165, 0);
          GUIButtonCreate(ptr_507BC0, 61, 424, 31, 0, 2, 94, 110, 1, 49, NULL, 0);
          GUIButtonCreate(ptr_507BC0, 177, 424, 31, 0, 2, 94, 110, 2, 50, NULL, 0);
          GUIButtonCreate(ptr_507BC0, 292, 424, 31, 0, 2, 94, 110, 3, 51, NULL, 0);
          result = (int)GUIButtonCreate(ptr_507BC0, 407, 424, 31, 0, 2, 94, 110, 4, 52, NULL, 0);
        }
        dword_F8BC10 = 0;
      }
    }
  }
  return result;
}