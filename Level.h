#pragma once
#pragma pack(push, 1)
#include <windows.h>
#include <stdio.h>

#include "defs.h"



struct class51_stru0
{
 unsigned char *ptr_000000;
 unsigned char *ptr_000004;
 unsigned char *ptr_000008;
 unsigned char *ptr_00000C;
 short          word_000010;
 short          word_000012;
 short          word_000014;
 short          word_000016;
 int            dword_000018;
 int            dword_00001C;
};
//sizeof == 20

//"BData"
struct class51_stru1
{
 unsigned char pSomeName[16 + array_size_unknown];

 char byte_a[0x40 - 16 - array_size_unknown];

 int            dword_000040;
 unsigned int   dword_000044;
 unsigned char *ptr_000048;
 unsigned int   dword_00004C;

 int dword_000050;

 struct class51_stru2 *ptr_000054;
 unsigned char        *ptr_000058;
 unsigned int          dword_00005C;
 unsigned char        *ptr_000060;

 int dword_000064[18];

 int dword_0000AC;
 int dword_0000B0;
 int dword_0000B4;
 int dword_0000B8;
};
//sizeof == BC

struct class51_stru2
{
 int   dword_000000;
 int   dword_000004;
 int   dword_000008;
 int   dword_00000C;
 char  byte_000010[16]; //if (byte_000010[13] & 0x40) then word_000110 == TextureFrameTable ID  else  plain Texture ID
 short word_000020;
 char  byte_000022[238];
 short word_000110;
 char  byte_000112[18];
 short word_000124;
 char  byte_000126[14];
};
//sizeof == 134

struct class51
{
 unsigned char  string_000000[32];
 unsigned char  pFileName[32];        // byte[32] @ 000020
 unsigned char  pFileDescription[32]; // byte[32] @ 000040
 unsigned char  string_000060[32];
 unsigned char  string_000080[32];

 short array_0000A0[8];

 int            dword_0000B0;

 struct class51_stru0 struct_0000B4;

 unsigned char        *ptr_0000D4;
 struct class51_stru1 *ptr_0000D8;
 int                   dword_0000DC;
 unsigned char        *ptr_0000E0;
 unsigned char        *ptr_0000E4;
 unsigned int          uSkyTextureID; // dword @ 0000E8
 int                   dword_0000EC;  // main tile texture id?

 int            dword_0004C0;
 unsigned char *ptr_0004C4;

 int array_0004C8[10];
 int array_0004F0[14];

 unsigned char array_000528[0x3C8];
 unsigned char array_0008F0[0x3C8];

 char maybe_more[0x20000];
};



bool LoadLevel(struct class51 *_this, const char *Source, int File, signed int a4, int a5);

int sub_47F420(struct class51 *_this);
int sub_47F3EA(struct class51 *_this);

bool sub_47CD44(struct class51_stru0 *_this);
int sub_47C80A(struct class51_stru0 *_this, int a2, int a3, int a4, int a5);

bool sub_44C1E8(struct class51_stru2 *_this);
bool sub_482170(struct class51_stru2 *_this, int a2, struct struct8 *a3);
bool __stdcall sub_45CDB7(struct class51_stru2 *_this);

bool __stdcall sub_45CE50(struct struct7 *_this, struct class51_stru2 *a2, int *a3, char a4);

#pragma pack(pop)