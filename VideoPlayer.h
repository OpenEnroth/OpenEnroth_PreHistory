#pragma once

#include <windows.h>
#include "CoreDefinitions.h"
#include "defs.h"



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
   ~VideoPlayer()
   {
    UnloadAll();
   }
   
   Result::Code Initialize(OSWindow *pWindow, AudioPlayer *pAudioPlayer);
   Result::Code PlayMovie(const char *pMovieName, unsigned int uOutX, unsigned int uOutY, unsigned int bLoop);
   Result::Code StopMovie();

 protected:
   Result::Code OpenMovie(const char *pVideoName);
   HBINK        OpenBinkMovie(const char *pVideoFile);
   HSMACK       OpenSmackMovie(const char *pVideoFile);

   Result::Code SmackPlayMovie(unsigned int uOutX, unsigned int uOutY);
   void         SmackDrawFrame(unsigned int uOutX, unsigned int uOutY);
   unsigned int SmackCheckSurfaceFromat();

   
   HBINKBUF     BinkCreateBuffer(unsigned int uWidth, unsigned int uHeight, char a4);
   Result::Code BinkPlayMovie(unsigned int uOutX, unsigned int uOutY);
   Result::Code BinkDrawFrame(unsigned int uOutX, unsigned int uOutY);
   Result::Code BinkLockBuffer(HBINKBUF pBinkBuffer);
   Result::Code BinkUnlockBuffer(HBINKBUF pBinkBuffer);



 public:
   bool IsAnyMovieLoaded();
   void UnloadAll();

   void sub_4BECD5(unsigned int a2);
   int  sub_4BF5B2();
   void sub_4BF73A();
   void sub_4BF28F(char a2, int a3);
   void sub_4BF08B(int a2);

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
   //int  dword_000040;                     // depricated
   //int  dword_000044;                     // depricated
   int          uNumMightVideoHeaders;      // dword @ 000048
   int          uNumMagicVideoHeaders;      // dword @ 00004C
   int          sBinkDirectDrawSurfaceType; // dword @ 000050
   //int        dword_000054;               // depricated
   unsigned int  bPlayingMovie;             // dword @ 000058    is any movie currently playing?
   unsigned int  bFirstFrame;               // dword @ 00005C    is this a first frame we're drawing?
   unsigned int  bUsingSmackerMMX;          // dword @ 000060
   unsigned int  bLoopPlaying;              // dword @ 000064    do we play this movie in a loop?
   //int          dword_000068;             // depricated, no use
   unsigned int  bStopBeforeSchedule;       // dword @ 00006C    do we have to stop the video right now?
   OSWindow     *pWindow;                   // dword @ 000070
   HSMACKBLIT    pSmackMovieBlit;           // dword @ 000074
   HANDLE        hMightVid;                 // dword @ 000078   OS file handle of might.vid
   HANDLE        hMagicVid;                 // dword @ 00007C   OS file handle of magic.vid
   HBINK         pBinkMovie;                // dword @ 000080
   HBINKBUF      pBinkBuffer;               // dword @ 000084

   unsigned int  uMovieFormat;          // dword @ 00009C     Video::Format
   int           dword_0000A0;          // 1 bink 2 smacker
   char          pCurrentMovieName[64]; // byte[64] @ 0000A4

 protected:
   //new
   AudioPlayer *pAudioPlayer;
};