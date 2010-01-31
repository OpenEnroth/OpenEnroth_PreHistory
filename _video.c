#include "_video.h"

#include <stdio.h>


#include "AIL.h"
#include "Bink.h"
#include "_audio.h"
#include "mm7DDrawRenderer.h"

#include "data.h"



extern char off_4E7ECC[];
extern int dword_4E800C;
extern float flt_6BE3A0;
extern int dword_AD4730;
extern int dword_E31C7C;
extern char byte_6BE371;
extern int dword_4F00DC;
extern char unk_F79CC8[];
extern char byte_F79448[];
extern HWND hWnd_global;


extern char unk_4EB8BC;
extern char unk_4EBBD0;
extern char byte_6BE36F;

extern int dword_4F00E4;
extern short word_F1B4C4;
extern int dword_4F00E4;
extern int dword_4F00E0;
extern short word_F1B4C6;
extern int dword_4F00E0;
extern int dword_4F00E4;
extern int dword_4F00E0;

extern char byte_4D8410[];

extern int *dword_4F2688;

extern int dword_51B6E8;
extern int dword_51B6EC;
extern int dword_51B6F0;

extern int dword_6A0CA4;

extern int dword_720010;

extern int dword_720018;

extern int dword_E31C70;

extern int dword_F792F0;

extern int dword_F79D70;
extern int dword_F79D7C;





//----- (MM7.exe::004BF411) --------------------------------------------------------
extern int dword_6A0D00;
void *__fastcall sub_4BFE2D(HWND a1, int a2, int a3, char a4);
int __stdcall radmalloc(long);
void sub_4BF411(struct CVideoPlayer *_this, const char *pVideoName, int a3, int a4)
{
  int v9; // eax@7
  int v10; // eax@11
  const char *v12; // [sp-4h] [bp-38h]@8
  char pVideoFile[256];

 if (!_this->dword_000054)
 {
  CVideoPlayer_Initialize(_this);
  _this->dword_000064 = a3;
  sprintfex(pVideoFile, "%s.bik", pVideoName);
  strcpy(_this->array_0000A4, pVideoName);

  _this->dword_00006C = CVideoPlayer_OpenBinkMovie(_this, pVideoFile);
  if (_this->dword_00006C)
  {
   _this->dword_00009C = 2;
   _this->dword_0000A0 = 1;
   if (_this->ptr_000080)
     _this->ptr_000084 = sub_4BFE2D(_this->hWnd, _this->ptr_000080[0], _this->ptr_000080[1], 0);
  }
  else
  {
   CVideoPlayer_UnloadAll(_this);

   sprintfex(pVideoFile, "%s.smk", pVideoName);
   _this->pSmackerMovie = CVideoPlayer_OpenSmackMovie(_this, pVideoFile);
   if (!_this->pSmackerMovie)
   {
    CVideoPlayer_UnloadAll(_this);
    sprintfex(pVideoFile, "Can't load file - anims\\%s.smk", pVideoName);
LABEL_17:
    MessageBoxA(0, pVideoFile, "Smacker Error", 0);
    return;
   }

   _this->dword_00009C = 1;
   _this->dword_0000A0 = 2;

   //_this->dword_000030 = radmalloc(_this->ptr_000028[1] * _this->ptr_000028[2]);
   _this->ptr_000030 = malloc(_this->pSmackerMovie->Width * _this->pSmackerMovie->Height);
   if (!_this->ptr_000030)
   {
    CVideoPlayer_UnloadAll(_this);
    v12 = "Can't allocate memory for buffer";
LABEL_16:
    sprintfex(pVideoFile, v12);
    goto LABEL_17;
   }

   SmackToBuffer(_this->pSmackerMovie, 0, 0,
                 _this->pSmackerMovie->Width, _this->pSmackerMovie->Height,
                 _this->ptr_000030, 0);

   if (a4)
   {
    if ((unsigned int)dword_6A0D00 < 0xA5)
      v10 = VideoPlayer_Smacker_CheckSurfaceFromat() | 2;
    else
    {
     v10 = VideoPlayer_Smacker_CheckSurfaceFromat();
     LOBYTE(v10) = v10 | 6;
    }
   }
   else
     v10 = VideoPlayer_Smacker_CheckSurfaceFromat();

   _this->pSmacMoviekBlit = SmackBlitOpen(v10);
   if (!_this->pSmacMoviekBlit)
      {
        CVideoPlayer_UnloadAll(_this);
        v12 = "Failed to open Blit API";
        goto LABEL_16;
      }
    }
  }
}

//----- (MM7.exe::004BF1E6) --------------------------------------------------------
void *CVideoPlayer_OpenSmackMovie(struct CVideoPlayer *_this, const char *pVideoFile)
{
 int i;

 for (i = 0; i < _this->uNumMightVideoHeaders; ++i)
 {
  if (!_strcmpi(_this->pMightVideoHeaders[i].sVideoName, pVideoFile))
  {
   SetFilePointer(_this->hMightVid, _this->pMightVideoHeaders[i].uContainerOffset, 0, FILE_BEGIN);
   return SmackOpen(_this->hMightVid, 28992, -1);
  }
 }

 for (i = 0; i < _this->uNumMagicVideoHeaders; ++i)
 {
  if (!_strcmpi(_this->pMagicVideoHeaders[i].sVideoName, pVideoFile))
  {
   SetFilePointer(_this->hMagicVid, _this->pMagicVideoHeaders[i].uContainerOffset, 0, FILE_BEGIN);
   return SmackOpen(_this->hMightVid, 28992, -1);
  }
 }

 return 0;
}

//----- (MM7.exe::004BEBD7) --------------------------------------------------------
extern int dword_F8BC10;
extern struct class24 *pClass24_global;
void CVideoPlayer_UnloadAll(struct CVideoPlayer *_this)
{
  int v2; // esi@1
  int v4; // eax@4
  v2 = _this;

 if (_this->ptr_000080)
 {
  BinkPause(_this->ptr_000080, 1);
  Sleep(300);
  BinkClose(_this->ptr_000080);
  _this->ptr_000080 = 0;
 }

 if (_this->ptr_000084)
 {
  v4 = _this->ptr_000084;

  (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v4 + 72) + 8))(*(_DWORD *)(v4 + 72));
  *(_DWORD *)(v4 + 72) = 0;

  call_delete(0, _this->ptr_000084);
  _this->ptr_000084 = 0;
 }

 if (_this->pSmackerMovie)
 {
   SmackSoundOnOff(_this->pSmackerMovie, 0);
   SmackClose(_this->pSmackerMovie);
   _this->pSmackerMovie = 0;
 }

 if (_this->ptr_00002C)
 {
  SmackBufferClose(_this->ptr_00002C);
  _this->ptr_00002C = 0;
 }

 if (_this->pSmacMoviekBlit)
 {
  SmackBlitClose(_this->pSmacMoviekBlit);
  _this->pSmacMoviekBlit = 0;
 }

 _this->dword_000054 = 0;
 _this->dword_00009C = 0;
 _this->dword_0000A0 = 0;

 memset(_this->array_0000A4, 0, 64);
 if (pClass31_global->hAILRedbook)
 {
  if (!dword_F8BC10)
    AIL_redbook_resume(pClass31_global->hAILRedbook);
 }
 sub_426363(pClass24_global);
}

//----- (MM7.exe::004BF141) --------------------------------------------------------
int CVideoPlayer_OpenBinkMovie(struct CVideoPlayer *_this, const char *pVideoFile)
{
 int i;

 for (i = 0; i < _this->uNumMightVideoHeaders; ++i)
 {
  if (!_strcmpi(_this->pMightVideoHeaders[i].sVideoName, pVideoFile))
  {
   SetFilePointer(_this->hMightVid, _this->pMightVideoHeaders[i].uContainerOffset, 0, FILE_BEGIN);
   return BinkOpen(_this->hMightVid, 0x82000000);
  }
 }

 for (i = 0; i < _this->uNumMagicVideoHeaders; ++i)
 {
  if (!_strcmpi(_this->pMagicVideoHeaders[i].sVideoName, pVideoFile))
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
 if (pClass31_global->hAILRedbook)
   AIL_redbook_pause(pClass31_global->hAILRedbook);

 _this->pSmackerMovie = 0;
 _this->ptr_00002C = 0;

 _this->ptr_000080 = 0;
 _this->ptr_000084 = 0;

 _this->dword_000054 = 1;
 _this->dword_000058 = 0;
 _this->dword_00005C = 0;
 _this->bUsingSmackerMMX = SmackUseMMX(1);

 _this->dword_00006C = 0;
 _this->hWnd = hWnd_global;

 BinkSetSoundSystem(BinkOpenMiles, pClass31_global->hDigDriver);

 if (dword_F79D7C != 2 || dword_F79D70 != 4)
   v3 = pD3DRenderer->pdds4_BackBuffer;
 else
 {
  v3 = pD3DRenderer->pdds2_BackBuffer;
  runtime_error;
 }

 _this->dword_000050 = BinkDDSurfaceType(v3);
 _flushall();
}

//----- (MM7.exe::004BE9D8) --------------------------------------------------------
int CVideoPlayer_LoadVideoHeaders(struct CVideoPlayer *_this)
{
 DWORD w;

 strcpy(ExistingFileName, "anims\\might7.vid");
 _this->hMightVid = CreateFileW(L"anims\\might7.vid", GENERIC_READ, 1, 0, 3, 0x8000080, 0);
 if (_this->hMightVid == INVALID_HANDLE_VALUE)
 {
  MessageBoxW(0, L"Can't open file: Might7.vid", L"Video File Error", 0);
  return false;
 }

 strcpy(ExistingFileName, "anims\\magic7.vid");
 _this->hMagicVid = CreateFileW(L"anims\\magic7.vid", GENERIC_READ, 1, 0, 3, 0x8000080, 0);
 if (_this->hMagicVid == INVALID_HANDLE_VALUE)
 {
  if (!bLoadingFromCD)
  {
   MessageBoxW(0, L"Can't open file: Magic7.vid", L"Video File Error", 0);
   return false;
  }

  sprintfex(pStringBuffer, "%c:\\%s", cGameCDDriveLetter, "anims\\magic7.vid");
  _this->hMagicVid = CreateFileA(pStringBuffer, GENERIC_READ, 1u, 0, 3u, 0x8000080u, 0);
  if ( _this->hMagicVid == INVALID_HANDLE_VALUE )
  {
   MessageBoxW(0, L"Can't open file: Magic7.vid", L"Video File Error", 0);
   return false;
  }
 }

 ReadFile(_this->hMightVid, &_this->uNumMightVideoHeaders, 4, &w, 0);
 ReadFile(_this->hMagicVid, &_this->uNumMagicVideoHeaders, 4, &w, 0);

 _this->pMightVideoHeaders = class23_AllocatedNamedBuffer(class23_instance, 0, _this->uNumMightVideoHeaders * sizeof(struct CVideoPlayer_movie_header_struct) + 2, 0);
 _this->pMagicVideoHeaders = class23_AllocatedNamedBuffer(class23_instance, 0, _this->uNumMagicVideoHeaders * sizeof(struct CVideoPlayer_movie_header_struct) + 2, 0);

 ReadFile(_this->hMightVid, _this->pMightVideoHeaders, _this->uNumMightVideoHeaders * sizeof(struct CVideoPlayer_movie_header_struct), &w, 0);
 ReadFile(_this->hMagicVid, _this->pMagicVideoHeaders, _this->uNumMagicVideoHeaders * sizeof(struct CVideoPlayer_movie_header_struct), &w, 0);

 return true;
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

 CD3DRenderer_GetPrimarySurfacePixelFormat(pD3DRenderer, &ddpsFrontBuffer);

 return 
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