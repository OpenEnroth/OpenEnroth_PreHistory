#pragma pack(push, 1)

#include <windows.h>
#include "defs.h"




//class32
struct class32_smk_header_struct
{
 unsigned char sVideoName[40]; // byte[40] @ 000000
 int           dword_000028;
};
//sizeof = 2C

struct class32
{
 int dword_000024;
 int dword_000028;

 struct class32_smk_header_struct *pMightVideoHeaders;  // ptr @ 000038
 struct class32_smk_header_struct *pMagicVideoHeaders;  // ptr @ 00003C

 int  dword_000040;
 int  dword_000044;

 int  uNumMightVideoHeaders; // dword @ 000048
 int  uNumMagicVideoHeaders; // dword @ 00004C

 int  dword_000054;
 int  dword_000058;
 int  dword_000064;
 int  dword_00006C;

 HWND    hWnd;      // ptr @ 000070

 HANDLE  hMightVid; // ptr @ 000078
 HANDLE  hMagicVid; // ptr @ 00007C
};
//sizeof ~ ?
void class32_ctor(struct class32 *_this);
//int __thiscall sub_4BE9D8(void *this)
int class32_LoadVideoHeaders(struct class32 *_this);


#pragma pack(pop)