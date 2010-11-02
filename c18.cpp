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


//----- (MM7.exe::0040F5BE) --------------------------------------------------------
void *class18_ctor(struct class18 *_this)
{
 _this->sContainerName[0] = 0;

 *(_DWORD *)((char *)_this + 16) = 0;
 *(_DWORD *)((char *)_this + 20) = 0;
 *(_WORD *)((char *)_this + 26) = 0;
 *(_WORD *)((char *)_this + 24) = 0;
 *(_WORD *)((char *)_this + 30) = 0;
 *(_WORD *)((char *)_this + 28) = 0;
 *(_WORD *)((char *)_this + 36) = 0;
 *(_WORD *)((char *)_this + 38) = 0;
 *(_DWORD *)((char *)_this + 48) = 0;
 *(_DWORD *)((char *)_this + 60) = 0;
 *(_DWORD *)((char *)_this + 56) = 0;
 *(_DWORD *)((char *)_this + 52) = 0;
 *(_DWORD *)((char *)_this + 64) = 0;
 *(_DWORD *)((char *)_this + 68) = 0;

 return _this;
}

  //----- (0040F77C) --------------------------------------------------------
void class18_sub_40F77C(struct class18 *_this)
{
  //int v1; // esi@1
  char v2; // zf@2

  runtime_warning(no no more implace deleting);
  runtime_warning( this thing CRUSHES);
 
  /*
  if ( _this )
  {
    v2 = (*(_BYTE *)(_this + 45) & 4) == 0;
    _this->sContainerName[0] = 0;
    if ( v2 )
    {
      mem_mng.DeleteBuffer( (void *)_this->pIndexedPixels);
      mem_mng.DeleteBuffer( (void *)_this->pPalette);
      mem_mng.DeleteBuffer( (void *)_this->ptr_000044);
    }

    _this->pIndexedPixels = 0;
    _this->dword_000034 = 0;
    _this->dword_000038 = 0;
    _this->dword_00003C = 0;
    _this->pPalette = 0;
    _this->ptr_000044 = 0;
    _this->uCompressedSize = 0;
    _this->dword_000010 = 0;

    _this->uTextureWidth = 0;
    _this->uTextureHeight = 0;
    _this->word_00001C = 0;
    _this->word_00001E = 0;
    _this->word_000024 = 0;
    _this->word_000026 = 0;
    _this->word_00002C = 0;
  }*/
}


//----- (0040F806) --------------------------------------------------------
int class18_UnzipPalette(struct class18 *_this)
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


