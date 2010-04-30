#pragma once
#pragma pack(push, 1)
#include <windows.h>
#include <stdio.h>

#include "defs.h"



struct class51_Geodata
{
 unsigned char *pHeightmap;    // ptr @ 000000    128x128 heightmap data scaled by 1/32
 unsigned char *pTilemap;      // ptr @ 000004    128x128 tilemap data
 unsigned char *pAttributemap; // ptr @ 000008    128x128 attributes
 unsigned char *ptr_00000C;
 short          word_000010;
 short          word_000012;
 short          word_000014;
 short          word_000016;
 int            dword_000018;
 int            dword_00001C;
};
//sizeof == 20

struct class51_stru3
{
 signed int int_000000;
 signed int int_000004;
 signed int int_000008;
};
//sizeof == 0C

struct class51_BModel
{
 unsigned char pSomeName[16 + array_size_unknown];

 char byte_a[0x40 - 16 - array_size_unknown];

 int                   dword_000040;
 unsigned int          dword_000044;
 struct class51_stru3 *ptr_000048;
 unsigned int          dword_00004C;

 int dword_000050;

 struct class51_stru2 *ptr_000054;
 unsigned char        *ptr_000058;
 unsigned int          dword_00005C;
 unsigned char        *ptr_000060;

 int dword_000064[6];
 int dword_00007C;
 int dword_000080;
 int dword_000084;
 int dword_000088;
 int dword_00008C;
 int dword_000090[7];
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
 short array_000020[60];
 short array_000098[20];
 short array_0000C0[20];
 char  byte_0000E8[40];
 short word_000110;
 char  byte_000112[4];
 short word_000116;
 short word_000118;
 short word_00011A;
 char  word_00011C;
 char  byte_00011E[6];
 short word_000124;     //related to Event::dword_000000
 char  byte_000126[8];
 char  byte_00012E;
 char  byte_00012F[5];
};
//sizeof == 134

struct class51
{
 unsigned char  string_000000[32];
 unsigned char  pFileName[32];        // byte[32] @ 000020
 unsigned char  pFileDescription[32]; // byte[32] @ 000040
 unsigned char  pSkyTextureName[32];  // byte[32] @ 000060
 unsigned char  pGroundTileset[32];   // byte[32] @ 000080

 short array_0000A0[8];

 unsigned int           uNumBModels; // dword @ 0000B0

 struct class51_Geodata struct_0000B4;

 unsigned char         *ptr_0000D4;
 struct class51_BModel *pBModels;      // ptr @ 0000D8
 int                    dword_0000DC;
 unsigned char         *ptr_0000E0;
 unsigned char         *ptr_0000E4;
 unsigned int           uSkyTextureID; // dword @ 0000E8
 int                    dword_0000EC;  // id in bitmaps.lod; main tile texture id?

 int            dword_0004C0;
 unsigned char *ptr_0004C4;

 int array_0004C8[10];
 int array_0004F0[14];

 unsigned char array_000528[0x3C8];
 unsigned char array_0008F0[0x3C8];

 char maybe_more[0x20000];
};
//sizeof
//int __thiscall sub_488F2E(int this, signed int a2, signed int a3);
int class51_sub_488F2E_GetHeightOnTerrain(struct class51 *_this, signed int uX, signed int uY);
//int __thiscall sub_47EE16(int this, signed int a2, signed int a3);
int class51_sub_47EE16_ActuallyGetHeightOnTerrain(struct class51 *_this, signed int uX, signed int uY);
//int __thiscall sub_47EDB3(int this, signed int a2, signed int a3);
int class51_sub_47EDB3_MessWithHeightmapAndTiles(struct class51 *_this, signed int uX, signed int uY);
//signed int __thiscall sub_47EF60(void *this, int a2, int a3, int a4);
bool class51_sub_47EF60(struct class51 *_this, int a2, int a3, int a4);


void Level_LoadEvtAndStr(const char *pLevelName);
bool LoadLevel(struct class51 *_this, const char *Source, int File, signed int a4, int a5);


int sub_47F420(struct class51 *_this);
int sub_47F3EA(struct class51 *_this);

bool class51_InitializeGeodata(struct class51_Geodata *_this);
void sub_47C7C2(struct class51_Geodata *_this);
int sub_47C80A(struct class51_Geodata *_this, int a2, int a3, int a4, int a5);

bool sub_44C1E8(struct class51_stru2 *_this);
bool sub_482170(struct class51_stru2 *_this, int a2, struct struct8 *a3);
bool __stdcall sub_45CDB7(struct class51_stru2 *_this);

bool __stdcall sub_45CE50(struct struct7 *_this, struct class51_stru2 *a2, int *a3, char a4);

#pragma pack(pop)