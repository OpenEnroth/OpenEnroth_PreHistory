#pragma pack(push, 1)

#include <windows.h>
#include "defs.h"

#include "Smacker.h"



int __cdecl VideoPlayer_Smacker_CheckSurfaceFromat();


//class32
struct CVideoPlayer_movie_header_struct
{
 unsigned char sVideoName[40];   // byte[40] @ 000000
 unsigned int  uContainerOffset; // dword    @ 000028
};
//sizeof = 2C

struct CVideoPlayer
{
 int dword_000024;

 HSMACK pSmackerMovie; // ptr @ 000028
 int *ptr_00002C;
 unsigned char *ptr_000030;

 struct CVideoPlayer_movie_header_struct *pMightVideoHeaders;  // ptr @ 000038
 struct CVideoPlayer_movie_header_struct *pMagicVideoHeaders;  // ptr @ 00003C

 int  dword_000040;
 int  dword_000044;

 int  uNumMightVideoHeaders; // dword @ 000048
 int  uNumMagicVideoHeaders; // dword @ 00004C

 int  dword_000050;
 int  dword_000054;
 int  dword_000058;
 int  dword_00005C;
 unsigned int bUsingSmackerMMX; // dword @ 000060
 int  dword_000064;
 int  dword_00006C;

 HWND    hWnd;      // ptr @ 000070

 HSMACKBLIT pSmacMoviekBlit;

 HANDLE  hMightVid; // ptr @ 000078
 HANDLE  hMagicVid; // ptr @ 00007C

 int  *ptr_000080;
 int  *ptr_000084;

 int           dword_00009C;
 int           dword_0000A0;
 unsigned char array_0000A4[64]; // byte[64]
};
//sizeof ~ ?
void CVideoPlayer_ctor(struct CVideoPlayer *_this);
//int __thiscall sub_4BE9D8(void *this)
int CVideoPlayer_LoadVideoHeaders(struct CVideoPlayer *_this);
//void __thiscall sub_4BF411(int this, const char *Source, int a3, int a4)
void sub_4BF411(struct CVideoPlayer *_this, const char *pVideoName, int a3, int a4);
//int __thiscall sub_4BEB41(void *this);
void CVideoPlayer_Initialize(struct CVideoPlayer *_this);
//int __thiscall sub_4BF141(int this, const char *Str2);
int CVideoPlayer_OpenBinkMovie(struct CVideoPlayer *_this, const char *pVideoFile);
//void __thiscall sub_4BEBD7(int this);
void CVideoPlayer_UnloadAll(struct CVideoPlayer *_this);
//int __thiscall sub_4BF1E6(int this, const char *Str2);
void *CVideoPlayer_OpenSmackMovie(struct CVideoPlayer *_this, const char *pVideoFile);
#pragma pack(pop)