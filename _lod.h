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
 char pFilename[16];
 //unsigned int unk1;
// unsigned int unk2;
 unsigned int offset_from_unit_start; //10h 16
 unsigned int size_data;		   //14h 20
 unsigned int reserved1;		   //18h 24 
 unsigned short uSubIndixes;		   //1ch 28
 unsigned short reserved3;		   // 1Eh 30
};
//sizeof == 20

struct LODFileHeader
{
 char Signature[4];     // dword @ 000000    "LOD\0"
 char           a1[80];			  //00004
 char           a2[80];			   //  
 unsigned int   dword00A4;        // dword @ 0000A4
 unsigned int   dword00A8;        // dword @ 0000A8
 unsigned int   uNumIndexDirs;        // dword @ 0000AC

 unsigned char array_0000B0[28]; // byte[28] @ 0000B0
 char          b[52];

};
//sizeof == 100


class LOD_file
	{
	protected:
		FILE            *pLODFile;               //dword ptr [0000]
		char             sLODName[32];           //dword ptr [0004]
		char             byte_000024[0x0000E0];
		bool             file_opened;			 // 104	260
		unsigned char   *pLODIOBuffer;  // ptr @ 000108	 264
		unsigned int     uIOBufferSize; // dword @ 00010C 268
		LODFileHeader    sLODFileHeader;  //struct @ 000110	  272

		char            *pLODCArray;//dword_000210;
		char             sContainerName[12];    //string ptr [0214]
		int              dword_000220;
		int              current_index_dir;//dword_000224;
		long             lLOD_Datasize;
		unsigned int     uNumSubidices; // dword @ 00022C	556
		LODIndex        *pLODSubIndexNamedBuffer;  // ptr @ 000230	 560
		unsigned int     offset_to_subindex;	// 234    564
		FILE             *ptemp_write_file;			//  238    568   

		int Fast_Calc_Index( int startIndex, int maxIndex, const char *pContainerName);
	public:
		void Close_Open_File();
		//signed int __thiscall sub_46188A(int _this, const char *Source);
         int Load_SubIndexes( const char *pContainer); //LODFile_fn6
//int __thiscall sub_46153F(int _this);
         void Reset_SubIndexBuffer(); //int LODFile_fn7();
		void FreeSubIndxIOBuffers();
		bool IsContainerExist(const char *pContainerName);
		void AllocateSubidexAndIOBuffer(unsigned int uNumSubInd, unsigned int uIOBuffSize);
		bool Load_LODHeader( const char *pFilename, bool openmode);
		FILE *Find_Container(const char *pContainerName, bool linearSearch);
		LOD_file();
		~LOD_file();
	};

  class LOD_Writefile:public LOD_file
	  {
	  public:
	   void Close_Written_File();  
	   bool  Load_File(const char *pLODFilename, unsigned char uFileFlags);
	   int _sub_461B48( const char *Count, const void *a3, FILE *File);
	  bool Append_item(const LODIndex *pHeader, const void *Data);
	  signed int LODFile_sub_4621A7();
	  int LODFile_sub_461FD4();
	   int Write_Lod_Header( LODFileHeader* file_header, LODIndex * indx, const char *Source);

	  int LODFile_sub_461F1E();
	  }	;



//LODFile
class LODFile_sp: public  LOD_file
{
public:

	 struct class18 aLODHeaders[1000];  // class18[~ 1000] @ 00023C   	   //48h
     unsigned int uNumLoadedFiles; // dword @ 011B7C	 72572
     int     dword_011B80;//
     int     dword_011B84; //
 int     dword_011B88;
 int     dword_011B8C;
 int     dword_011B90;
 int     dword_011B94;
 int     dword_011B98; //
 int     dword_011B9C; //
 int     dword_011BA0;
 int     dword_011BA4; //

 int     dword_011BA8; //check	on load palette may be rendrer3d
 

 IDirectDrawSurface4 **pHardwareSurfaces; // dword @ 011BAC   1000 of them  72620
 IDirect3DTexture2   **pHardwareTextures; // dword @ 011BB0   1000 of them  72624
 int    **dword_011BB4;//         							  72628
 /*struct IDirect3DTexture2   **pHardwareTextures; // dword @ 011BB0   1000	11BB0
 struct IDirect3DTexture2   **pHardwareTextures2; //dword  11BB4		 72628
 void  **dword_011BB4; */         //                  250

//sizeof = 011BB8

 

	 LODFile_sp();
	 ~LODFile_sp();
//void LODFile_ctor(struct LODFile *_this);
//bool __thiscall sub_40FAEE(int _this, const char *Filename);
bool LODFile_LoadLOD_Icons_Events( const char *pLODFilename);
//bool __thiscall sub_40FA2E(int _this, const char *Filename);
bool LODFile_LoadLOD_Bitmaps( const char *pLODFilename);

//int __thiscall sub_41088B(void *_this, const char *Args, int a3);
void *LODFile_LoadRaw( const char *pLODContainer, int a3);
//int __thiscall sub_461580(int _this, const char *Str1, int a3);
//FILE *LODFile_FindContainer(struct LODFile *_this, const char *pContainerName, int a3);
//int __thiscall sub_46165E(void *_this, int a2, int a3, const char *Str1);
int LODFile_fn3( int a2, int a3, const char *pContainerName);
//void __thiscall sub_40FA60(int _this);
void Reset_TextureBuffs(); //LODFile_fn4();
//signed int __thiscall sub_4617D5(int _this, const char *Filename, char a3)
//int LODFile_MaybeLoadLODHeader(struct LODFile *_this, const char *pFilename, char a3);

//int __thiscall sub_40FB20(int _this, const char *Source, unsigned int a3)
int LODFile_LoadTexture( const char *pContainerName, unsigned int a3);
//signed int __thiscall sub_40FC08(int _this, void *Dest, int Source, unsigned int DstBuf);
int LODFile_LoadPalette( struct class18 *pClass18, const char *pContainerName, unsigned int DstBuf);
//int __thiscall sub_461954(int _this, int a2, signed int Size);
//void LODFile_AllocateSubidexAndIOBuffer(struct LODFile *_this, unsigned int uNumSubIndices, signed int uIOBufferSize);
//signed int __thiscall sub_461A43(void *_this, const char *Filename, char a3);
//int LODFile_LoadLOD_Games(struct LODFile *_this, const char *pLODFilename, unsigned char uFileFlags);
//int __thiscall LODFile_sub_4114F2(_DWORD);
int LODFile_sub_4114F2();
//int __thiscall sub_46454B(int _this);
int sub_46454B();

//signed int __thiscall sub_46161C(int _this, const char *Str1);
//bool LODFile_Games_LOD_FindLeveL( const char *pLevelName);
//signed int __thiscall sub_4AC67E(int _this, char *DstBuf, const char *Size);


int LODFile_SetupPalettes( int a2, int a3, int a4);

 signed int  LODFile_sub_4101B1( char *DstBuf, const char *Source, size_t Count);
 #ifndef	OLD_CODE
unsigned int   LODFile_LoadTexture_New(const wchar_t *pFilename);
#endif
unsigned char *LODFile_LoadEvent( const wchar_t *pFilename);
bool LODFile_ReleaseTexture( unsigned int uTextureID);

int  LODFile_sub_40F9C5();

signed int  LODFile_sub_40F9F0( const char *Str2);

signed int LODFile_sub_410522( void *DstBuf, const char *Source, int a4);

void sub_4355F7();


void sub_4103BB();

void sub_410423();


void  sub_41033D();


   };

   class LODFile_Sprite: public  LOD_file
	   {
	   public:
		   Sprites_Header aSpriteHeaders[1500]; 			 // 23Ch   struct size 28h
		   unsigned int   uNumLoadedSprites;  // dword @ 00EC9C  60572	 
		   int   dword_00ECA0;
		   int   dword_00ECA4;
		   int   dword_00ECA8;  //	60584
		   int   dword_00ECAC;
		   struct HardwareSprite *pHardwareSprites; // dword @ 00ECB0    1500 structs 40 bytes long, maybe only for pLODFile_Sprites_LOD
		   //                   addon: 3000 structs	  60592
		  // int   dword_00ECB4; 
		   LODFile_Sprite();
		   ~LODFile_Sprite();
		   //int __thiscall sub_4645DC(int _this);	
           
           int sub_4645DC();   
		   void sub_4ACBE0();
		   void sub_4ACB70(); 
		   void  sub_4ACADA();
		   int Delete_sprites_Range( int start_indx, int stop_indx);
		   void  LODFile_sub_450C8B();
		   int sub_4AC67E_LoadSpriteFromFile( Sprites_Header *pDstBuf, const char *pFilename);
		   int LODFile_sub_461397();   
		   //bool __thiscall sub_4AC795(int _this, const char *Filename);
bool LODFile_LoadLOD_Sprites( const char *pLODFilename);
		   unsigned int LODFile_LoadSprite( const char *pSourceFile, int a3);
	   };


void Reset_LODIndex(LODIndex *pLIndx);
void Reset_LODFileHeader(LODFileHeader *p_hdr);

#pragma pack(pop)
