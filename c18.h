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
		unsigned short short_0016;				  //22
		unsigned short uTextureWidth;   // word @ 000018	//24
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
		struct SomeSpriteData *pSomeSpriteData;  //  dword @ 000020   sprite: some data pt        	//32
		unsigned char *ptr_000024; // dword @ 000024  sprite: decompressed sprite data 		   //36
		void Clear_Data();
		Sprites_Header();
		~Sprites_Header();
	};



// class18
class cTexture
	{
	public:
		char  sContainerName[16];
		unsigned int    uSizeOfMaxLevelOfDetal;	   //16
	

		unsigned int   uCompressedSize; // dword @ 000014	  20

		unsigned short uTextureWidth;   // word @ 000018  	 24
		unsigned short uTextureHeight;  // word @ 00001A	 26


		short  word_00001C;			  //28
		short  word_00001E;			  //30


		short word_000020;			 //32
		short word_000022;			 //34


		short  word_000024;			//36
		short  word_000026;			//38

		unsigned int    uDecompressedSize;   // dword @ 000028	 40
		short           word_00002C;				  // 2c  44
		char            byte_00002E[2];
	//	union
	//		{
		unsigned char  *pIndexedPixels; // ptr @ 000030 48	 
			
	//	unsigned int *pTruecolorPixels;
	//		 };
		unsigned char  *pLevelOfDetal1;   //  	dword_000034 52				
		unsigned char  *pLevelOfDetal2;  //     dword_000038  56 looks like pixels (4 lods - levels of details) for bitmaps.lod textures
		unsigned char  *pLevelOfDetal3;   //	dword_0003C 60

		unsigned short *pPalette; // ptr @ 000040 64
		unsigned char  *ptr_000044;		  //68
		unsigned int   *pTruecolorPixels;
		

	};

//sizeof = 000048	  
void cTexture_Zero(cTexture* cTxtr); 
void cTexture_Free(cTexture* cTxtr);
//sizeof = 28 for Sprites_LOD
//int __thiscall sub_40F5BE(int _this);

//int __thiscall cTexture_Free(int _this);

//int __thiscall sub_40F806(int _this);
int cTexture_UnzipPalette(cTexture *_this);

