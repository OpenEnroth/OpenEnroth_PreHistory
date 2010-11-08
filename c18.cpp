#include "c18.h"
#include "_lod.h"
#include "defs.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

//--------------------------------------  .text:00463766   sprite_header_constr

Sprites_Header::Sprites_Header()
	{

	uSomeSprtDataCount=0; // * 8 for sprite size                      
	uPaletteID=0; // dword @ 000014
	short_001A=0;
	pSomeSpriteData=NULL;
	ptr_000024=NULL; 

	}
//---------------------------------------------.text:0046377D     
Sprites_Header::~Sprites_Header()
	{
	if  (!(c0001B&4==0))
		{
		mem_mng.DeleteBuffer(pSomeSpriteData);
		mem_mng.DeleteBuffer(ptr_000024);
		}
	pSomeSpriteData=NULL;
	ptr_000024=NULL;
	}


//----- (00450D1D) --sub_450D1D--------.text:00451E32  ----------------------------------------------
void Sprites_Header::Clear_Data()
{
  int v1; // esi@1
  int result; // eax@3

  if  (!(c0001B&4==0))
		{
		mem_mng.DeleteBuffer(pSomeSpriteData);
		mem_mng.DeleteBuffer(ptr_000024);
		}
	pSomeSpriteData=NULL;
	ptr_000024=NULL;
	sContainerName[0]=0;
	dSpriteSize=0;
    word_000010=0;
	uSomeSprtDataCount=0; // * 8 for sprite size
	short_0016=0;
	uTextureWidth=0;
	uPaletteID=0; // dword @ 000014
	short_001A=0;

}


//----- (MM7.exe::0040F5BE) ----.text:0040F8B0  ----------------------------------------------------
void cTexture::cTexture_Zero()
{
	sContainerName[0] = 0;
	uSizeOfMaxLevelOfDetal = 0;
	uTextureSize = 0; 
	uTextureWidth = 0;
	uTextureHeight = 0;
	word_00001C = 0;
	word_00001E = 0;

	word_000024 = 0;
	word_000026 = 0;

	pIndexedPixels = NULL;
	pLevelOfDetal1 = NULL;
	pLevelOfDetal2 = NULL;
	pLevelOfDetal3 = NULL;
	pPalette = NULL;
	ptr_000044 = NULL;
	pTruecolorPixels=NULL;
}

  //----- (0040F77C) ---------text:0040FA6E-----------------------------------------------
void cTexture_Free(cTexture* cTxtr)
{
  //int v1; // esi@1
  char v2; // zf@2

  runtime_warning(no no more implace deleting);
  runtime_warning( this thing CRUSHES);
 
  /*
  if ( cTxtr )
  {
    cTxtr->sContainerName[0] = 0;
    if (!(cTxtr->word_00002C&0x400) )
    {
      mem_mng.DeleteBuffer( (void *)cTxtr->pIndexedPixels);
      mem_mng.DeleteBuffer( (void *)cTxtr->pPalette);
      mem_mng.DeleteBuffer( (void *)cTxtr->ptr_000044);
    }
	cTxtr->uSizeOfMaxLevelOfDetal = 0;
    cTxtr->pIndexedPixels = NULL;
	cTxtr->pLevelOfDetal1 = NULL;
	cTxtr->pLevelOfDetal2 = NULL;
	cTxtr->pLevelOfDetal3 = NULL;
    cTxtr->pPalette = NULL;
    cTxtr->ptr_000044 = NULL;
    cTxtr->uCompressedSize = 0;
    cTxtr->uTextureWidth = 0;
    cTxtr->uTextureHeight = 0;
    cTxtr->word_00001C = 0;
    cTxtr->word_00001E = 0;
    cTxtr->word_000024 = 0;
    cTxtr->word_000026 = 0;
    cTxtr->word_00002C = 0;
  }*/
}


//----- (0040F806) --------------------------------------------------------
int cTexture_UnzipPalette(cTexture *_this)
{
  int v2; // esi@1
  int v3; // edi@1
  int v4; // [sp+0h] [bp-4h]@1

  v4 = (int)_this;
  v2 = (int)_this;
  v3 = (int)malloc(_this->uDecompressedSize);
  MemUnzip((void *)v3, (unsigned int *)&v4, _this->pIndexedPixels, *(_DWORD *)(v2 + 20));
  return v3;
}

//----- (0040F5F5) --------------------------------------------------------
void cTexture::LODPCXLoader(char *filename)
{




}

/*
signed int __thiscall sub_40F5F5(void *_this, const char *Str1)
{
  void *v2; // esi@1
  FILE *v3; // eax@3
  FILE *v4; // edi@3
  unsigned int v5; // ebx@7
  signed int result; // eax@11
  int v7; // eax@12
  int v8; // ecx@12
  int v9; // ST20_4@14
  int v10; // eax@14
  int v11; // eax@14
  char v13; // [sp+8h] [bp-98h]@9
  char DstBuf; // [sp+38h] [bp-68h]@1
  size_t v15; // [sp+4Ch] [bp-54h]@6
  size_t Size; // [sp+60h] [bp-40h]@6
  cTexture cTexture_obj;//[128]; // [sp+80h] [bp-20h]@9
  char v18; // [sp+83h] [bp-1Dh]@9
  int v19; // [sp+84h] [bp-1Ch]@12
  int v20; // [sp+88h] [bp-18h]@12
  char v21; // [sp+90h] [bp-10h]@9
  FILE *File; // [sp+98h] [bp-8h]@3
  size_t Count; // [sp+9Ch] [bp-4h]@6
  int v24; // [sp+A8h] [bp+8h]@7

  v2 = _this;
  cTexture_obj.cTexture_Zero();
  if ( !*((_DWORD *)v2 + 9) )
    return 2;
  v3 = LODFile_Icons_LOD.Find_Container( Str1, 0);
  v4 = (FILE *)v3;
  File = (FILE *)v3;
  if ( !v3 )
  {
    wsprintfA((char *)TmpBuf, "Unable to load %s", Str1);
    erroneous_printf((char *)TmpBuf);
  }
  locked_fread(&DstBuf, 1u, 0x30u, (FILE *)v3);
  Count = v15;
  if ( Size )
  {
    v5 = (unsigned int)malloc(Size);
    v24 = (int)mem_mng.AllocatedNamedBuffer( 0, v15, cTexture_obj.sContainerName);
    locked_fread((void *)v24, 1u, Count, File);
    MemUnzip((void *)v5, (unsigned int *)&Size, (void *)v24, v15);
    v15 = Size;
    mem_mng.DeleteBuffer( (void *)(void *)v24);
  }
  else
  {
    v5 = (unsigned int)malloc(v15);
    locked_fread((void *)v5, 1u, Count, v4);
  }
  memcpy(&pSpansBuf, (const void *)v5, 0x10u);
  memcpy(&v13, (const void *)(v5 + 16), 0x30u);
  memcpy(&v21, (const void *)(v5 + 64), 6u);
  if ( v18 != 8 )
    return 3;
  v7 = v20 - v19 + 1;
  v8 = (signed __int16)(v20 - (_WORD)v19 + 1);
  if ( v8 * (signed __int16)(HIWORD(v20) - HIWORD(v19) + 1) <= *((_DWORD *)v2 + 4) )
  {
    *((_WORD *)v2 + 10) = v7;
    v9 = *((_DWORD *)v2 + 9);
    v10 = v8 * *((_WORD *)v2 + 11);
    *((_DWORD *)v2 + 4) = v10;
    *((_WORD *)v2 + 11) = v10;
    v11 = RGBTexture_DecodePCX((RGBTexture *)v2, (unsigned char *)v5, (unsigned short *)v9, v8);
    free((void *)v5);
    result = 0;
  }
  else
  {
    result = -1;
  }
  return result;
}
  */