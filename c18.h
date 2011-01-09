 #pragma once

#include "defs.h"

//WARNING!!! 11 chars max name for icons and 15 (for 8.3 format possible)


class Sprites_Header
	{
	public:
		char             sContainerName[12];
		unsigned int     dSpriteSize;  // dword 00000C 12sprite: resource size;  actual size stored in dword_00001C (if compressed), otherwise this is actual size
		short            word_000010;	 //16
		short            uSomeSprtDataCount; // word 000012 18   * 8 for sprite size                      
		unsigned short   uPaletteID; // dword @ 000014	 20
		unsigned short   short_0016;				  //22
		unsigned short   uTextureWidth;   // word @ 000018	//24
		union
			{
			unsigned short short_001A;				   //26
			struct
				{
				char        c0001A;  // word @ 00001A
				char        c0001B;  // word @ 00001B
				};
			};
		unsigned int    dUnCompressedSize ;		//dword 00001C		   //28
		struct  SomeSpriteData *pSomeSpriteData;  //  dword @ 000020   sprite: some data pt        	//32
		unsigned char  *ptr_000024; // dword @ 000024  sprite: decompressed sprite data 		   //36

		void Clear_Data();
		Sprites_Header();
		~Sprites_Header();
	};	//0x28 	40



// class18
class cTexture
	{
	public:
		char            sContainerName[16];
		unsigned int    uSizeOfMaxLevelOfDetal;//0x10	   //16
		unsigned int    uTextureSize; // dword @ 000014	  20
		unsigned short  uTextureWidth;   // word @ 000018  	 24
		unsigned short  uTextureHeight;  // word @ 00001A	 26
		short           word_00001C;			  //28
		short           word_00001E;			  //30
		short           word_000020;			 //32
		short           word_000022;			 //34
		short           word_000024;			//36
		short           word_000026;			//3
		unsigned int    uDecompressedSize;   // dword @ 000028	 40
		short           word_00002C;				  // 2c  44
		char            byte_00002E[2];
		unsigned char  *pIndexedPixels; // ptr @ 000030 48	 
		unsigned char  *pLevelOfDetal1;   //  	dword_000034 52				
		unsigned char  *pLevelOfDetal2;  //     dword_000038  56 looks like pixels (4 lods - levels of details) for bitmaps.lod textures
		unsigned char  *pLevelOfDetal3;   //	dword_0003C 60

		unsigned short *pPalette; // ptr @ 000040 64
		unsigned char  *ptr_000044;		  //68
		unsigned int   *pTruecolorPixels;	   //not in original!!!!!

		
		void cTexture_Zero();
        void cTexture_Load(const wchar_t *pPath);
	};
//sizeof = 000048	  

void cTexture_Free(cTexture* cTxtr);
//sizeof = 28 for Sprites_LOD

//int __thiscall sub_40F806(int _this);
int cTexture_UnzipPalette(cTexture *_this);




//class33
class cPCXTexture
{
public:
 char  sContainerName[16];
 unsigned int uNumPixels; // 16 dword @ 000010
 short uWidth;  // 20 word @ 000014
 short uHeight;  // 22 word @ 000016
 short word_000018;		   //24
 short word_00001A;			//26
 short word_00001C;		   //28
 short word_00001E;		  //30
 short word_000020;		 //32
 short word_000022;		 //34
 unsigned int *pPixels; // 36 ptr @ 000024
//int __thiscall sub_40D73D(int _this);
void PCXTexture_Zero();			// constr
void PCXTexture_Release();	   //  destr
//signed int __thiscall sub_40F414(void *_this, const char *Str1, int a3);
 int LODPCXLoad(const char *pContainerName, int mode);

//signed int __thiscall sub_40F037(void *_this, void *Src, int a3, int a4)
int DecodePCX(unsigned char *pPCXData,unsigned long *pOutBuffer, unsigned int uWidth);
int LODPCXReLoad(const char *pContainerName); // signed int __thiscall sub_40F5F5(void *_this, const char *Str1);
int LoadPCXFromFile(FILE *File, unsigned int mode, bool close_file);	//sub_40EAD8
};
//sizeof = 28
signed int __thiscall sub_40E55E(void *Source, unsigned int Filename, unsigned int a3);

//
#ifndef OLD_CODE 
//signed int __thiscall sub_40F414(void *_this, const char *Str1, int a3);
int RGBTexture_Load(cPCXTexture *_this, const char *pContainerName, int a3);
int RGBTexture_Load_New(cPCXTexture *_this , const wchar_t *pTextureName);
#endif
