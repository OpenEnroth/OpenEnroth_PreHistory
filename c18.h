 #pragma once

#include "defs.h"

//class18
struct class18
{
 char  sContainerName[8];
 int   dword_000008;
 int   dword_00000C;  // sprite: resource size;  actual size stored in dword_00001C (if compressed), otherwise this is actual size
 union
 {
  int     dword_000010;
  struct
  {
   short  word_000010; // sprite width?
   short  word_000012; // * 8 for sprite size
  };
 };
 union
 {
  unsigned int   uCompressedSize; // dword @ 000014
  struct
  {
   short uPaletteID; // word @ 000014   sprite: pal%d for sprite
   short word_000016;
  };
 };
 unsigned short uTextureWidth;   // word @ 000018
 unsigned short uTextureHeight;  // word @ 00001A
 union
 {
  int dword_00001C;   // sprite:  0 if uncompressed, otherwise decompressed size
  struct
  {
   short  word_00001C;
   short  word_00001E;
  };
 };
union
 {
  struct SomeSpriteData *pSomeSpriteData;  // dword @ 000020   sprite: some data ptr
  struct
  {
   short word_000020;
   short word_000022;
  };
 };

 union
 {
  unsigned char *ptr_000024; // dword @ 000024  sprite: decompressed sprite data
  struct
  {
   short  word_000024;
   short  word_000026;
  };
 };
 unsigned int    uDecompressedSize;   // dword @ 000028
 short           word_00002C;
 char            byte_00002E[2];
 union
 {
  unsigned char  *pIndexedPixels; // ptr @ 000030
  unsigned int    dword_000030;    //
 };
 int             dword_000034;   //  
 int             dword_000038;  // looks like pixels (4 lods - levels of details) for bitmaps.lod textures
 int             dword_00003C;   //
 unsigned short *pPalette; // ptr @ 000040
 unsigned char  *ptr_000044;

 unsigned int *pTruecolorPixels;
};


//sizeof = 000048
//sizeof = 28 for Sprites_LOD
//int __thiscall sub_40F5BE(int _this);
void *class18_ctor(struct class18 *_this);
//int __thiscall class18_sub_40F77C(int _this);
void class18_sub_40F77C(struct class18 *_this);
//int __thiscall sub_40F806(int _this);
int class18_UnzipPalette(struct class18 *_this);

