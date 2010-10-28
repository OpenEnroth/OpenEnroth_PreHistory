#pragma once

#include <stdio.h>

#include "AIL.h"
#include "c18.h"
#include "Party.h"
#include "Items.h"
#include "GUI.h"
#include "Render.h"
#include "CbmTools.h"

#pragma pack(push, 1)

struct LODIndex
{
 unsigned char pFilename[8];
 char a[24];
};
//sizeof == 20

struct LODFileHeader
{
 unsigned char Signature[4];     // dword @ 000000    "LOD\0"
 char          a[168];
 unsigned int  uNumFiles;        // dword @ 0000AC
 unsigned char array_0000B0[28]; // byte[28] @ 0000B0
 char          b[52];
};
//sizeof == 100


//LODFile
struct LODFile
{
 FILE *pLODFile;               //dword ptr [0000]
 char  sLODName[32];           //dword ptr [0004]

 char   byte_000024[0x0000E0];
 int   dword_000104;
 unsigned char *pLODIOBuffer;  // ptr @ 000108
 unsigned int   uIOBufferSize; // dword @ 00010C
 struct LODFileHeader sLODFileHeader;  //struct @ 000110
 char *dword_000210;
 char   sContainerName[12];    //string ptr [0214]
 int   dword_000220;
 int   dword_000224;
 int   dword_000228;
 unsigned int   uNumSubidices; // dword @ 00022C
 struct LODIndex *pLODSubIndexNamedBuffer;  // ptr @ 000230
 int   dword_000234;
 int   dword_000238;

 struct class18 aLODHeaders[2500];  // class18[~ 1000] @ 00023C   1500 i sprites.lod
 //char   byte_00023C[16];
 //short  array_00024C[0x7528];

 unsigned int   uNumLoadedSprites;  // dword @ 00EC9C
 int   dword_00ECA0;
 int   dword_00ECA4;
 int   dword_00ECA8;
 int   dword_00ECAC;
 struct HardwareSprite *pHardwareSprites; // dword @ 00ECB0    1500 structs 40 bytes long, maybe only for pLODFile_Sprites_LOD
                                          //                   addon: 3000 structs

 char byte_00ECB4[0x2EC8];

 unsigned int uNumLoadedFiles; // dword @ 011B7C
 int     dword_011B80;
 int     dword_011B84;
 int     dword_011B88;
 int     dword_011B8C;
 int     dword_011B90;
 int     dword_011B94;
 int     dword_011B98;
 int     dword_011B9C;
 int     dword_011BA0;
 int     dword_011BA4;
 int     dword_011BA8;
 struct IDirectDrawSurface4 **pHardwareSurfaces; // dword @ 011BAC   1000 of them
 struct IDirect3DTexture2   **pHardwareTextures; // dword @ 011BB0   1000
 void  **dword_011BB4;          //                  250
};
//sizeof = 011BB8

 

void LODFile_ctor(struct LODFile *_this);
//bool __thiscall sub_40FAEE(int _this, const char *Filename);
int LODFile_LoadLOD_Icons_Events(struct LODFile *_this, const char *pLODFilename);
//bool __thiscall sub_40FA2E(int _this, const char *Filename);
int LODFile_LoadLOD_Bitmaps(struct LODFile *_this, const char *pLODFilename);
//bool __thiscall sub_4AC795(int _this, const char *Filename);
int LODFile_LoadLOD_Sprites(struct LODFile *_this, const char *pLODFilename);
//int __thiscall sub_41088B(void *_this, const char *Args, int a3);
void *LODFile_LoadRaw(struct LODFile *_this, const char *pLODContainer, int a3);
//int __thiscall sub_461580(int _this, const char *Str1, int a3);
FILE *LODFile_FindContainer(struct LODFile *_this, const char *pContainerName, int a3);
//int __thiscall sub_46165E(void *_this, int a2, int a3, const char *Str1);
int LODFile_fn3(struct LODFile *_this, int a2, int a3, const char *pContainerName);
//void __thiscall sub_40FA60(int _this);
void LODFile_fn4(struct LODFile *_this);
//signed int __thiscall sub_4617D5(int _this, const char *Filename, char a3)
int LODFile_MaybeLoadLODHeader(struct LODFile *_this, const char *pFilename, char a3);
//signed int __thiscall sub_46188A(int _this, const char *Source);
int LODFile_fn6(struct LODFile *_this, const char *pContainer);
//int __thiscall sub_46153F(int _this);
int LODFile_fn7(struct LODFile *_this);
//int __thiscall sub_40FB20(int _this, const char *Source, unsigned int a3)
int LODFile_LoadTexture(struct LODFile *_this, const char *pContainerName, unsigned int a3);
//signed int __thiscall sub_40FC08(int _this, void *Dest, int Source, unsigned int DstBuf);
int LODFile_LoadPalette(struct LODFile *_this, struct class18 *pClass18, const char *pContainerName, unsigned int DstBuf);
//int __thiscall sub_461954(int _this, int a2, signed int Size);
void LODFile_AllocateSubidexAndIOBuffer(struct LODFile *_this, unsigned int uNumSubIndices, signed int uIOBufferSize);
//signed int __thiscall sub_461A43(void *_this, const char *Filename, char a3);
int LODFile_LoadLOD_Games(struct LODFile *_this, const char *pLODFilename, unsigned char uFileFlags);
//int __thiscall LODFile_sub_4114F2(_DWORD);
int LODFile_sub_4114F2(struct LODFile *_this);
//int __thiscall sub_46454B(int _this);
int sub_46454B(struct LODFile *_this);
//int __thiscall sub_4645DC(int _this);
int sub_4645DC(struct LODFile *_this);
//signed int __thiscall sub_46161C(int _this, const char *Str1);
bool LODFile_Games_LOD_FindLeveL(struct LODFile *_this, const char *pLevelName);
//signed int __thiscall sub_4AC67E(int _this, char *DstBuf, const char *Size);
int sub_4AC67E_LoadSpriteFromFile(struct LODFile *_this, struct class18 *pDstBuf, const char *pFilename);

unsigned int LODFile_LoadSprite(struct LODFile *_this, const char *pSourceFile, int a3);

int LODFile_SetupPalettes(struct LODFile *_this, int a2, int a3, int a4);


unsigned int   LODFile_LoadTexture_New(struct LODFile *_this, const wchar_t *pFilename);
unsigned char *LODFile_LoadEvent(struct LODFile *_this, const wchar_t *pFilename);
bool LODFile_ReleaseTexture(struct LODFile *_this, unsigned int uTextureID);







#pragma pack(pop)
