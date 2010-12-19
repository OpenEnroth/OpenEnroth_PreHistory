#pragma once

#include <windows.h>
#include "defs.h"

#include "Smacker.h"
#include "Bink.h"



int __cdecl VideoPlayer_Smacker_CheckSurfaceFromat();


namespace Video
{
 namespace Format
 {
  enum
  {
   Unknown = 0,
   Smack = 1,
   Bink = 2
  };
 };
};




class OSWindow;
class AudioPlayer;
class VideoPlayer
{
 public:
    VideoPlayer();
   ~VideoPlayer() {}
   
   unsigned int Initialize(OSWindow *pWindow, AudioPlayer *pAudioPlayer);

   
   unsigned int PlayMovie(const char *pMovieName);

 protected:
   unsigned int OpenMovie(const char *pVideoName, int a3);
   HBINK        OpenBinkMovie(const char *pVideoFile);
   HSMACK       OpenSmackMovie(const char *pVideoFile);

   unsigned int PlaySmackMovie();

   
   HBINKBUF     BinkCreateBuffer(unsigned int uWidth, unsigned int uHeight, char a4);
   unsigned int BinkPlayMovie();
   unsigned int BinkDrawFrame(int a3, int a4);
   unsigned int BinkLockBuffer(HBINKBUF pBinkBuffer);
   unsigned int BinkUnlockBuffer(HBINKBUF pBinkBuffer);

   
   void SmackDrawFrame(int a3, int a4);

 public:
   bool IsAnyMovieLoaded();
   void UnloadAll();

   void sub_4BECD5(unsigned int a2);
   int  sub_4BF5B2();
   void sub_4BF73A();
   void sub_4BF28F(char a2, int a3);

 public:
   int            dword_000000[9];
   int            dword_000024;
   HSMACK         pSmackerMovie;      // dword @ 000028
   HSMACKBUF      pSmackerBuffer;     // dword @ 00002C
   unsigned char *pSomeSmackerBuffer; // dword @ 000030

 protected:
   struct MovieHeader  // class32, sizeof = 2C
   {
    char          sVideoName[40];   // byte[40] @ 000000
    unsigned int  uContainerOffset; // dword    @ 000028
   };

   MovieHeader *pMightVideoHeaders;  // dword @ 000038
   MovieHeader *pMagicVideoHeaders;  // dword @ 00003C

 public:
   int  dword_000040;
   int  dword_000044;

   int  uNumMightVideoHeaders; // dword @ 000048
   int  uNumMagicVideoHeaders; // dword @ 00004C

   int          sBinkDirectDrawSurfaceType; // dword @ 000050
   int          dword_000054; // initialization flag
   int          dword_000058;
   int          dword_00005C;
   unsigned int bUsingSmackerMMX; // dword @ 000060
   int          dword_000064; //a3 from OpenMovie
   int          dword_000068;
   int          dword_00006C; //RGBTexture ptr

   //HWND    hWnd;      // dword @ 000070
   OSWindow *pWindow;   // dword @ 000070

   HSMACKBLIT pSmackMovieBlit; // ptr @ 000074

   HANDLE  hMightVid; // ptr @ 000078
   HANDLE  hMagicVid; // ptr @ 00007C

   HBINK    pBinkMovie;   // ptr @ 000080
   HBINKBUF pBinkBuffer;  // ptr @ 000084

   unsigned int  uMovieFormat;      // dword @ 00009C     Video::Format
   int           dword_0000A0;      // 1 bink 2 smacker
   char          pCurrentMovieName[64]; // byte[64] @ 0000A4

 protected:
   //new
   AudioPlayer *pAudioPlayer;
};