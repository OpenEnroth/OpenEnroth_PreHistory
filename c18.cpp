#include "c18.h"
#include "defs.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

//--------------------------------------  .text:00463766   sprite_header_constr

Sprites_Header::Sprites_Header()
	{

	word_000012=0; // * 8 for sprite size                      
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
	dword_00000C=0;
    word_000010=0;
	word_000012=0; // * 8 for sprite size
	short_0016=0;
	uTextureWidth=0;
	uPaletteID=0; // dword @ 000014
	short_001A=0;


  ;
}


//----- (MM7.exe::0040F5BE) ----.text:0040F8B0  ----------------------------------------------------
void cTexture_Zero(cTexture* cTxtr)
{
	cTxtr->sContainerName[0] = 0;
	cTxtr->dword_000010 = 0;
	cTxtr->uCompressedSize = 0; 
	cTxtr->uTextureWidth = 0;
	cTxtr->uTextureHeight = 0;
	cTxtr->word_00001C = 0;
	cTxtr->word_00001E = 0;

	cTxtr->word_000024 = 0;
	cTxtr->word_000026 = 0;

	cTxtr->pIndexedPixels = NULL;
	cTxtr->dword_000034 = 0;
	cTxtr->dword_000038 = 0;
	cTxtr->dword_0003C = 0;
	cTxtr->pPalette = NULL;
	cTxtr->ptr_000044 = NULL;
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
	cTxtr->dword_000010 = 0;
    cTxtr->pIndexedPixels = 0;
    cTxtr->dword_000034 = 0;
    cTxtr->dword_000038 = 0;
    cTxtr->dword_0003C = 0;
    cTxtr->pPalette = 0;
    cTxtr->ptr_000044 = 0;
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


