#pragma pack(push, 1)

#include <windows.h>
#include "defs.h"





HDIGDRIVER __cdecl sub_4ABAF7();









struct SoundDescription
{
 unsigned char sSoundName[12]; // byte[] @ 000000
 char byte_00000C[8];
 int dword_000014;
 int dword_000018;
 int dword_00001C;
 int dword_000020;
 int dword_000024;
 int dword_000028;
 int *ptr_00002C;
 char b[72];
};
//sizeof == 78



struct CSoundList
{
 unsigned int             uNumSounds;  // dword @ 000000
 struct SoundDescription *pDescriptions; // ptr @ 000004
};

void CSoundList_ctor(struct CSoundList *_this);
//int __thiscall sub_4A9E3D(void *Str)
int CSoundList_SaveToBIN(struct CSoundList *_this);
//signed int __thiscall sub_4A9ED0(int this, const char *Args);
int CSoundList_InitializeFromTXT(struct CSoundList *_this, const char *pSourceFile);
//void *__thiscall sub_4A9E89(void *Dst, void *Src)
void *CSoundList_Initialize(struct CSoundList *_this, unsigned char *pSrc);
//signed int __thiscall sub_4A9953(void *this);
int sub_4A9953(struct CSoundList *_this);
//void __thiscall sub_4A9D79(void *this, int a2)
void sub_4A9D79(struct CSoundList *_this, int a2);
//int __thiscall sub_4A9A67(void *this, int a2, int a3);
int sub_4A9A67(struct CSoundList *_this, int a2, int a3);









//class31
struct AudioPlayer_sound_header_struct
{
 unsigned char sSoundName[40]; //byte[40] @ 000000
 int           dword_000024;
 int           dword_000028;
 int           dword_00002C;
};
//sizeof = 34

struct AudioPlayer_struct_0
{
 int a[4];
};

struct AudioPlayer
{
 int  dword_000000;
 int  dword_000004;
 int  dword_000008;
 int  dword_00000C;
 int  num_structs_0;
 struct AudioPlayer_struct_0 struct_0[10]; // struct @ 000014

 int  dword_000218;

 int  dword_00029C;
 HWND        hWnd;          // ptr @ 0002A0
 HREDBOOK    hAILRedbook;   // ptr @ 0002A4
 HDIGDRIVER  hDigDriver;    // ptr @ 0002A8
 int  dword_0002AC;
 int  dword_0002B0;
 int  dword_0002B4;

 struct AudioPlayer_sound_header_struct *pSoundHeaders; // ptr @ 0002B8
 HANDLE      hSoundsSource; // ptr @ 0002BC

 unsigned int dword_0002DC;

 unsigned int uNumSounds; //0002C0

 int  dword_0002C4;
 int  dword_0002C8;
 int  dword_0002CC;

 int  array_0002E8[64];       // dword[?] @ 0002E8

 int  iMixerChannels;         // dword   @ 0003E8
 char aDeviceNames[16][128];  // byte[?] @ 0003F0

 int array_000BF0[32];  // byte[?]

 unsigned int uNumDevices;        // dword @ 000C70
 int dword_000C74;
 int          cGameCDDriveLetter; // byte @  000C80
};
//sizeof ~ ?
void AudioPlayer_ctor(struct AudioPlayer *_this);
//int __thiscall sub_4AB8CE(int this, HWND);
int AudioPlayer_Initialize(struct AudioPlayer *_this, HWND);
//void __thiscall sub_4AA214(int this, signed int a2);
void AudioPlayer_sub_4AA214(struct AudioPlayer *_this, signed int a2);
//int __thiscall sub_4AB818(void *this);
int AudioPlayer_LoadSoundHeaders(struct AudioPlayer *_this);
//int __fastcall sub_4AA1F3(int a1, int a2, int a3);
int AudioPlayer_SetVolume(struct AudioPlayer *_this, float fVolume);
//int __thiscall sub_4AB71F(void *this, int a2, int a3);
void AudioPlayer_sub_4AB71F(struct AudioPlayer *_this, int a2, int a3);
//void __thiscall sub_4AA306(int this, int a2, signed int a3, int a4, signed int a5, int a6, int a7, int a8, int a9)
void AudioPlayer_sub_4AA306(struct AudioPlayer *_this, int a2, signed int a3, int a4, signed int a5, int a6, int a7, int a8, int a9);
//void __thiscall sub_4AAFCF(int this);
void AudioPlayer_sub_4AAFCF(struct AudioPlayer *_this);
//signed int __thiscall sub_4AC041(void *this);
signed int AudioPlayer_sub_4AC041(struct AudioPlayer *_this);



#pragma pack(pop)