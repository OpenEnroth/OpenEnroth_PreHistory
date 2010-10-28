#include "c18.h"
#include "defs.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

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
  int v1; // esi@1
  char v2; // zf@2

  runtime_warning(no no more implace deleting);
  /*
  v1 = _this;
  if ( _this )
  {
    v2 = (*(_BYTE *)(v1 + 45) & 4) == 0;
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


