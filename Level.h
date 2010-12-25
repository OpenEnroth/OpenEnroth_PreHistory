#pragma once
#include <windows.h>
#include <stdio.h>

#include "defs.h"


#pragma pack(push, 1)

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
 signed int x; // dword @ 000000
 signed int z; // dword @ 000004
 signed int y; // dword @ 000008
};
//sizeof == 0C

struct class51_BModel
{
 unsigned char pModelName[16 + array_size_unknown];

 char byte_a[0x40 - 16 - array_size_unknown];

 int                   dword_000040;
 unsigned int          dword_000044;
 struct class51_stru3 *ptr_000048;
 unsigned int          dword_00004C; // num elements in 000054
 int                   dword_000050;
 struct class51_stru2 *ptr_000054;
 unsigned short       *ptr_000058;
 unsigned int          dword_00005C;
 unsigned char        *ptr_000060;

 int dword_000064[6];
 int dword_00007C;
 int dword_000080;
 int dword_000084;
 int dword_000088;
 int dword_00008C;
 int dword_000090;
 int dword_000094[6];
 int dword_0000AC;
 int dword_0000B0;
 int dword_0000B4;
 int dword_0000B8;
};
//sizeof == BC

struct class51_stru2
{
 int    dword_000000;
 int    dword_000004;
 int    dword_000008;
 int    dword_00000C;
 char   byte_000010[12]; //if (byte_000010[13] & 0x40) then word_000110 == TextureFrameTable ID  else  plain Texture ID

 //int    dword_00001C;
 char  byte_00001C;
 char  byte_00001D;
 char  byte_00001E;
 char  byte_00001F;	 
 short  array_000020[20];
 short  array_000048[20];
 short  array_000070[20];
 short  array_000098[20];
 short  array_0000C0[20];
 char   byte_0000E8[40];
 short  uTextureID;      // word @ 000110
 short  word_000112;
 short  word_000114;
 short  sSomeX1;        // word @ 000116    x1..
 short  sSomeX2;        // word @ 000118     ..x2
 short  sSomeY1;        // word @ 00011A    y1..
 short  sSomeY2;        // word @ 00011C     ..y2
 short  sSomeZ1;        // word @ 00011E    z1..
 short  sSomeZ2;        // word @ 000120     ..z2  some boundaries
 char   byte_000122[2];
 short  word_000124;     //related to Event::dword_000000
 char   byte_000126[4];
 char   byte_00012A;
 char   byte_00012B;
 char   byte_00012C;
 char   byte_00012D;
 unsigned char uNumVertices; // byte @ 00012E
 char  byte_00012F;
 char  byte_000130;
 char  byte_000131;
 char  byte_000132[2];
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
 unsigned short        *ptr_0000E0;   // IDLIST
 unsigned int          *ptr_0000E4;   // OMAP
 unsigned int           uSkyTextureID; // dword @ 0000E8
 int                    dword_0000EC;  // id in bitmaps.lod; main tile texture id?

 int            dword_0004C0;
 unsigned char *ptr_0004C4;

 int array_0004C8[10];
 int array_0004F0[14];

 unsigned char array_000528[0x3C8];
 unsigned char array_0008F0[0x3C8];
 int           dword_000CB8;
 int           dword_000CBC;
 
 int dword_000D18;
 int dword_000D1C;
 int dword_000D20;

 int dword_000D30; // looks like some light vector
 int dword_000D34;
 int dword_000D38;

 float flt_01C284;
 int   dword_01C288;

 char maybe_more[0x30000];
};
//sizeof ~ ?
//int __thiscall sub_488F2E(int _this, signed int a2, signed int a3);
int class51_sub_488F2E_GetHeightOnTerrain(struct class51 *_this, unsigned int uX, unsigned int uY);
//int __thiscall sub_47EE16(int _this, signed int a2, signed int a3);
int class51_sub_47EE16_ActuallyGetHeightOnTerrain(struct class51 *_this, unsigned int uX, unsigned int uY);
//signed int __thiscall sub_47EF60(void *_this, int a2, int a3, int a4);
bool class51_sub_47EF60(struct class51 *_this, int a2, int a3, int a4);
bool class51_sub_47F420(struct class51 *_this);
bool class51_sub_47F3EA(struct class51 *_this);
//int __thiscall sub_488EEF(void *_this, signed int a2, signed int a3);
int class51_GetTileTexture(struct class51 *_this, int a2, int a3);
//int __thiscall sub_47ED08(int _this, signed int a2, signed int a3);
int class51_GetTileTexture2(struct class51 *_this, unsigned int uX, unsigned int uY);
//int __thiscall sub_488EB1(void *_this, signed int a2, signed int a3);
int class51_sub_488EB1_GetSomeOtherTileInfo(struct class51 *_this, int sX, int sY);
//int __thiscall sub_47EDB3(int _this, signed int a2, signed int a3);
int class51_sub_47EDB3_ActuallyGetSomeOtherTileInfo(struct class51 *_this, unsigned int uX, unsigned int uY);



void Level_LoadEvtAndStr(const char *pLevelName);
bool LoadLevel(struct class51 *_this, const char *Source, int File, signed int a4, int a5);



bool class51_InitializeGeodata(struct class51_Geodata *_this);
void sub_47C7C2(struct class51_Geodata *_this);
void sub_47C80A(struct class51_Geodata *_this, int sX, int sY, int sZ, int sW);

bool sub_44C1E8(struct class51_stru2 *_this);
bool sub_482170(struct class51_stru2 *_this, struct RenderVertex *a2, struct struct8 *a3);
bool __stdcall sub_45CDB7(struct class51_stru2 *_this, struct class04 *);

//----- (0047C7C2) --------------------------------------------------------
void class51_FreeGeodata(struct class51_Geodata *_this);

#pragma pack(pop)