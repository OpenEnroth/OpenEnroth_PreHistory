#pragma once

#include <stdio.h>


#include "c18.h"
#include "BaseRender.h"
#include "CbmTools.h"



#pragma pack(push, 1)


struct LODIndex
{
 char            pFilename[16];
 unsigned int    offset_from_unit_start; //10h 16
 unsigned int    size_data;		   //14h 20
 unsigned int    reserved1;		   //18h 24 
 unsigned short  uSubIndixes;		   //1ch 28
 unsigned short  reserved3;		   // 1Eh 30
};
//sizeof == 20

struct LODFileHeader
{
 char           Signature[4];     // dword @ 000000    "LOD\0"
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
	public:
		FILE            *pLODFile;               //dword ptr [0000]
		char             sLODName[255];           //dword ptr [0004]
		bool             file_opened;			 // 104	260
		unsigned char   *pLODIOBuffer;           // ptr @ 000108	 264
		unsigned int     uIOBufferSize;           // dword @ 00010C 268
		LODFileHeader    sLODFileHeader;         //struct @ 000110	  272
		char            *pLODCArray;             //dword_000210;
		char             sContainerName[16];    //string ptr [0214]
		int              current_index_dir;       //dword_000224;
		long             lLOD_Datasize;	          //dword_000228;
		unsigned int     uNumSubidices;           // dword @ 00022C	556
		LODIndex        *pLODSubIndexNamedBuffer;  // ptr @ 000230	 560
		unsigned int     offset_to_subindex;	   // 234    564
		FILE             *ptemp_write_file;			//  238    568   

		int Fast_Calc_Index( int startIndex, int maxIndex, const char *pContainerName);
	public:
		void Close_Open_File();
        int Load_SubIndexes( const char *pContainer); 
        void Reset_SubIndexBuffer(); 
		void FreeSubIndxIOBuffers();
		bool IsContainerExist(const char *pContainerName);
		void AllocateSubidexAndIOBuffer(unsigned int uNumSubInd, unsigned int uIOBuffSize);
        Result::Code Load_LODHeader(const char *pFilename, bool openmode);
		FILE *Find_Container(const char *pContainerName, bool linearSearch);
		LOD_file();
		~LOD_file();
	};

  class LOD_Writefile:public LOD_file
	  {
	  public:
	   void Close_Written_File();
	   int OpenTempFile();
	   bool  Load_File(const char *pLODFilename, unsigned char uFileFlags);
	   unsigned int Add_Container_to_File(const LODIndex *container_index, const void *container_data, int a4);
	   bool Append_item_to_temp_file(const LODIndex *container_index, const void *container_data);
	   signed int ReloadFile();
	   int Write_SubIndex();
	   int Write_Lod_Header(LODFileHeader* file_header, LODIndex * indx, const char *Source);
	  
	  }	;



//LODFile
class LODFile_IB: public  LOD_file
{


public:

	 cTexture aLODHeaders[1000];  // cTexture[~ 1000] @ 00023C   	   //48h
     unsigned int uNumLoadedFiles; // dword @ 011B7C	 72572
     int     lod_IB_dword_011B80;//
     int     lod_IB_dword_011B84; // 72580
 int     lod_IB_dword_011B88;
 int     uTextureRedBits;		//  dword_011B8C
 int     uTextureGreenBits;	   //  dword_011B90
 int     uTextureBlueBits;		//  dword_011B94
 unsigned int     uPrevLoadedFiles; //	 72600	//previous load files  count	dword_011B98
 unsigned int     uTexturePacksCount; //	72604 //texture packs count	  dword_011B9C
 int     lod_IB_dword_011BA0;
 int     lod_IB_dword_011BA4; //

 int     lod_IB_dword_011BA8; //check	on load palette may be rendrer3d
 

 IDirectDrawSurface4 **pHardwareSurfaces; // dword @ 011BAC   1000 of them  72620
 IDirect3DTexture2   **pHardwareTextures; // dword @ 011BB0   1000 of them  72624
 char    *lod_IB_dword_011BB4;//         							  72628

 

	 LODFile_IB();
	 ~LODFile_IB();

//bool __thiscall sub_40FAEE(int _this, const char *Filename);
Result::Code LODFile_LoadLOD_Icons_Events( const char *pLODFilename);
//bool __thiscall sub_40FA2E(int _this, const char *Filename);
Result::Code LODFile_LoadLOD_Bitmaps( const char *pLODFilename);

//int __thiscall sub_41088B(void *_this, const char *Args, int a3);
void *LODFile_LoadRaw(const char *pLODContainer, int a3);
void *LODFile_LoadRaw(const wchar_t *pLODContainer, int a3);

void Reset_TextureBuffs(); //LODFile_fn4();

//int __thiscall sub_40FB20(int _this, const char *Source, unsigned int a3)
int LODFile_LoadTexture( const char *pContainerName, unsigned int a3);
//signed int __thiscall sub_40FC08(int _this, void *Dest, int Source, unsigned int DstBuf);
int LoadTextureFromLOD(cTexture *pcTexture, const char *pContainerName, unsigned int uTextureType);

//int __thiscall LODFile_sub_4114F2(_DWORD);
void LODFile_sub_4114F2();
//int __thiscall sub_46454B(int _this);
int sub_46454B();



void SetupPalettes( int uTargetRBits, int uTargetGBits, int uTargetBBits);

 signed int  ReLoadTexture(class cTexture *dst_texture, const char *pContainerName, int mode);
 #ifndef	OLD_CODE
    unsigned int   LODFile_LoadTexture_New(const wchar_t *pFilename);
    bool LODFile_ReleaseTexture( unsigned int uTextureID);
    unsigned char *LODFile_LoadEvent( const wchar_t *pFilename);
#endif

int  LODFile_sub_40F9C5();

signed int  LODFile_sub_40F9F0( const char *Str2);

signed int LODFile_sub_410522( cTexture *pcTexture, const char *pContainerName, unsigned int uTextureType);

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
		  
		   LODFile_Sprite();
		   ~LODFile_Sprite();

           
           void sub_4645DC();   
		   void sub_4ACBE0();
		   void sub_4ACB70(); //-<-re
		   void  sub_4ACADA(); //<-re
		   int Delete_sprites_Range( int start_indx, int stop_indx);
		   void  LODFile_sub_450C8B();
		   int LoadSpriteFromFile( Sprites_Header *pSpriteHdr, const char *pFilename);
		   int LODFile_sub_461397();   
		   //bool __thiscall sub_4AC795(int _this, const char *Filename);
            Result::Code LODFile_LoadLOD_Sprites( const char *pLODFilename);
		   unsigned int LODFile_LoadSprite( const char *pSourceFile, int a3);
	   };


void Reset_LODIndex(LODIndex *pLIndx);
void Reset_LODFileHeader(LODFileHeader *p_hdr);

#pragma pack(pop)
