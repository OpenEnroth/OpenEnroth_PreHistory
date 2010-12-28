#pragma once

#include <windows.h>
#include "CoreDefinitions.h"
#include "defs.h"

#pragma pack(push, 1)




struct SoundDesc
{
 char pSoundName[20]; // byte[] @ 000000
 int  dword_000014;
 int  dword_000018;
 int  dword_00001C;
 unsigned int uSoundID; // dword @ 000020
 int  dword_000024;
 int  dword_000028;
 unsigned int *pSoundData[19]; // dword[?] @ 00002C   blocks of memory; first int of rist block == size of following raw data
};
//sizeof == 78



struct SoundList
{
  SoundList();
 ~SoundList();

 unsigned int      uNumSounds;            // dword @ 000000
 struct SoundDesc *pSounds;               // dword @ 000004
 unsigned int      uTotalLoadedSoundSize; // dword @ 000008

 Result::Code Initialize(const wchar_t *pSourceFile);

 Result::Code LoadSounds();
};
//void *__thiscall sub_4A9E89(void *Dst, void *Src)           004A9E89  SoundList::Initialize
//signed int __thiscall sub_4A9953(void *_this)               004A9953  SoundList::LoadSounds

//int __thiscall sub_4A9E3D(void *Str)
int CSoundList_SaveToBIN(SoundList *_this);
//void __thiscall SoundList_sub_4A9D79(void *_this, int a2)
void SoundList_sub_4A9D79(SoundList *_this, bool a2);
//int __thiscall sub_4A9A67(void *_this, int a2, int a3);
int sub_4A9A67(SoundList *_this, int a2, int a3);











struct AudioPlayer_struct_0
{
 int a[4];
};

class OSWindow;
class AudioPlayer
{
 friend struct SoundList;
 protected:
   struct SoundHeader
   {
    char         pSoundName[40];    // byte[40] @ 000000
    unsigned int uFileOffset;       // dword    @ 000028
    unsigned int uCompressedSize;   // dword    @ 00002C
    unsigned int uUncompressedSize; // dword    @ 000030   sound file size in bytes
   };
   //sizeof = 34

   struct MixerChannel
   {
    HSAMPLE      hSample;
    int          dword_000004;
    unsigned int uSourceTrackIdx; // dword @ 000008    SoundList::pSounds
    unsigned int uSourceTrackID;  // dword @ 00000C    generic id
   };

 public:
 unsigned int bEAXSupported;       // dword @ 000000
 unsigned int b3DSoundInitialized; // dword @ 000004
 int          s3DSoundVolume;      // dword @ 000008
 HPROVIDER h3DSoundProvider;       // dword @ 00000C
 int       num_structs_0;  // dword @ 000010
 struct AudioPlayer_struct_0 struct_0[10]; // struct @ 000014

 int           sRedbookVolume;        // dword @ 000218
 char          p3DSoundProvider[128]; // byte[128] @ 00021C
 unsigned int  bPlayerReady;  // dword @ 00029C    everything initialized, stopped and ready
 OSWindow     *pWindow;     // dword @ 0002A0
 HREDBOOK      hAILRedbook;   // dword @ 0002A4
 HDIGDRIVER    hDigDriver;    // dword @ 0002A8
 int           dword_0002AC;
 HSEQUENCE     hSequence;     // dword @ 0002B0
 int           dword_0002B4;
 SoundHeader  *pSoundHeaders;    // dword @ 0002B8
 HANDLE        hAudioSnd;        // dword @ 0002BC  OS file handle of Audio.snd
 unsigned int  uNumSoundHeaders; // dword @ 0002C0
 unsigned int  uMasterVolume;    // dword @ 0002C4
 int           dword_0002C8;
 int           dword_0002CC;

 unsigned int uCurrentMusicTrackLength;  // dword      @ 0002D8  measured in some weird units
 unsigned int uNumRedbookTracks;         // dword      @ 0002DC
 unsigned int uCurrentMusicTrackStartMS; // dword      @ 0002E0
 unsigned int uCurrentMusicTrackEndMS;   // dword      @ 0002E4
 MixerChannel pMixerChannels[16];        // struct[16] @ 0002E8
 unsigned int uMixerChannels;            // dword      @ 0003E8
 char         pDeviceNames[16][128];     // byte[2048] @ 0003F0

 int          array_000BF0[16];   // dword[16] @ 000BF0
 int          array_000C30[16];   // dword[16] @ 000C30
 unsigned int uNumDevices;        // dword @ 000C70
 HSTREAM      hStream;            // dword @ 000C74
 int          depricated_000C80;  // byte @  000C80     char cGameCDDriveLetter;

          AudioPlayer();
 virtual ~AudioPlayer() {}

 Result::Code Initialize(OSWindow *, wchar_t cCDDriveLetter);

 Result::Code SetMasterVolume(float fVolume);
 Result::Code SetMusicVolume(float fVolume);

 Result::Code PlayMusicTrack(unsigned int uTrackID);
 Result::Code PlayMusicTrack(unsigned int uTrackID, float fVolume);
 Result::Code StopMusic();

 
 void sub_4AA306(int a2, signed int a3, unsigned int uNumRepeats, signed int a5, int a6, int a7, unsigned int uVolume = 0, int sPlaybackRate = 0);
 void sub_4AAFCF();
  int sub_4ABE55(MixerChannel *);

 
 unsigned int *LoadSound(const char *pSoundName, unsigned char *pOutBuffer, _DWORD a3);
 Result::Code MessWithChannels(Range<unsigned int> *pChannels);

 protected:
   HDIGDRIVER GetFirstHardwareDigitalDriver();

   AudioPlayer::SoundHeader *FindSound_BinarySearch(Range<unsigned int> *, const char *pSrouceFile);

};
//sizeof ~ ?
//int sub_4AB818_LoadHeaders(struct AudioPlayer *_this)                                             004AB818  AudioPlayer::merged ->
//int sub_4AB8CE(int _this, HWND)                                                                   004AB8CE  AudioPlayer::Initialize
//int sub_4ABE55(int _this, int a2)                                                                 004ABE55  AudioPlayer::sub_4ABE55
//void sub_4AA306(int this, int a2, signed int a3, int a4, int a5, int a6, int a7, int a8, int a9)  004AA306  AudioPlayer::sub_4AA306
//void sub_4AAFCF(int this)                                                                         004AAFCF  AudioPlayer::sub_4AAFCF
//void sub_4AA214(int _this, int a2)                                                                004AA214  AudioPlayer::SetMasterVolume
//int sub_4AA1F3(int a1, int a2, int a3)                                                            004AA1F3  AudioPlayer::SetMusicVolume
//int __fastcall sub_4A96FF(int a1, int a2, const char *Str1)                                       004A96FF  AudioPlayer::FindSound_BinarySearch
//int sub_4A97C6(char *a1, int a2, _DWORD a3)                                                       004A97C6  AudioPlayer::LoadSound
//int __thiscall sub_4AB71F(void *_this, int a2, int a3)                                            004AB71F  AudioPlayer::MessWithChannels
//char __thiscall sub_4AA13F(int _this, int a2)                                                     004AA13F  AudioPlayer::PlayMusicTrack

//signed int __thiscall sub_4AC041(void *_this);
signed int AudioPlayer_sub_4AC041_ProbablyPrepare3DEnv(struct AudioPlayer *_this);
int SoundList_sub_4A9DCD(int _this, int a2, char a3);
void AudioPlayer_sub_4AA258(AudioPlayer *_this, int a2);
int AudioPlayer_sub_4AC004(int _this);
signed int sub_4AC0A2(AudioPlayer *_this);
void AudioPlayer_sub_4ABD5B(int _this);
int AudioPlayer_sub_4ABF23(AudioPlayer *_this, int a2);


#pragma pack(pop)