#pragma pack(push, 1)

#include <windows.h>
#include "defs.h"





HDIGDRIVER __cdecl sub_4ABAF7();



//class31
struct class31_sound_header_struct
{
 unsigned char sSoundName[40]; //byte[40] @ 000000
 int           dword_000024;
 int           dword_000028;
 int           dword_00002C;
};
//sizeof = 34

struct class31
{
 int  dword_000000;
 int  dword_000004;
 int  dword_000008;

 int  dword_000218;

 int  dword_00029C;
 HWND        hWnd;          // ptr @ 0002A0
 HREDBOOK    hAILRedbook;   // ptr @ 0002A4
 HDIGDRIVER  hDigDriver;    // ptr @ 0002A8
 int  dword_0002AC;
 int  dword_0002B0;
 int  dword_0002B4;

 struct class31_sound_header_struct *pSoundHeaders; // ptr @ 0002B8
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
 int          cGameCDDriveLetter; // byte @  000C80
};
//sizeof ~ ?
void class31_ctor(struct class31 *_this);
//int __thiscall sub_4AB8CE(int this, HWND);
int class31_Initialize(struct class31 *_this, HWND);
//void __thiscall sub_4AA214(int this, signed int a2);
void sub_4AA214(struct class31 *_this, signed int a2);
//int __thiscall sub_4AB818(void *this);
int class31_LoadSoundHeaders(struct class31 *_this);




#pragma pack(pop)