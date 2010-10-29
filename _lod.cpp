#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "defs.h"
#include "RenderD3D3.h"
#include "AIL.h"
#include "Smacker.h"
#include "Level.h"
#include "FrameTables.h"
 #include "_lod.h"
#include "data.h"

 struct class18 pending_texture;
void *hStdHandle = 0;

 void LODFile_ctor(struct LODFile *_this)
{
 memset(_this, 0, sizeof(struct LODFile));
}
	//int __stdcall sub_462C57(int, size_t Size)
//----- (00461954) --------------------------------------------------------
void LODFile_AllocateSubidexAndIOBuffer(struct LODFile *_this, unsigned int uNumSubIndices, signed int uIOBufferSize)
{
 if (_this->pLODSubIndexNamedBuffer)
 {
  MessageBoxW(0, L"Attempt to reset a LOD subindex!", L"MM7", 0x30u);
  mem_mng.DeleteBuffer( (void *)_this->pLODSubIndexNamedBuffer);
  _this->pLODSubIndexNamedBuffer = 0;
 }
 _this->pLODSubIndexNamedBuffer =
	 (LODIndex *)mem_mng.AllocatedNamedBuffer( _this->pLODSubIndexNamedBuffer, 32 * uNumSubIndices, "LODsubindex");

 if (_this->pLODIOBuffer)
 {
  MessageBoxW(0, L"Attempt to reset a LOD IObuffer!", L"MM7", 0x30u);
  mem_mng.DeleteBuffer( (void *)_this->pLODIOBuffer);
  _this->pLODIOBuffer = 0;
  _this->uIOBufferSize = 0;
 }
 else if (uIOBufferSize)
 {
  _this->pLODIOBuffer = (unsigned char *)mem_mng.AllocatedNamedBuffer( _this->pLODIOBuffer, uIOBufferSize, "LODiobuffer");
  _this->uIOBufferSize = uIOBufferSize;
 }
}

//----- (00461A43) --------------------------------------------------------
int LODFile_LoadLOD_Games(struct LODFile *_this, const char *pLODFilename, unsigned char uFileFlags)
{
  char DstBuf[32]; // [sp+Ch] [bp-20h]@5

 if (uFileFlags & 1)
   _this->pLODFile = fopen(pLODFilename, "rb");
 else
   _this->pLODFile = fopen(pLODFilename, "rb+");
 if (!_this->pLODFile)
   return false;

 strcpy(_this->sLODName, pLODFilename);

 locked_fread(&_this->sLODFileHeader, sizeof(struct LODFileHeader), 1, _this->pLODFile);

 sub_46172B((int)DstBuf);

 locked_fread(DstBuf, 0x20, 1, _this->pLODFile);
 fseek(_this->pLODFile, 0, SEEK_SET);

 _this->dword_000104 = 1;
  strcpy(_this->sContainerName, "chapter");

 _this->dword_000224 = 0;
 _this->dword_000228 = *(int *)(DstBuf + 20);
 _this->uNumSubidices = *(int *)(DstBuf + 28);

 _this->dword_000234 = *(int *)(DstBuf + 16);
 fseek(_this->pLODFile, _this->dword_000234, SEEK_SET);

 if (_this->uNumSubidices > 300)
 {
  MessageBoxW(0, L"LODchapterPages exceed 300", L"LODFile", 0x30u);
  fclose(_this->pLODFile);
  return false;
 }

 locked_fread(_this->pLODSubIndexNamedBuffer, sizeof(struct LODIndex), _this->uNumSubidices, _this->pLODFile);
 return true;
}

//----- (00461B48) --------------------------------------------------------
signed int LODFile_sub_461B48(struct LODFile *_this, const char *Count, const void *a3, FILE *File)
{
  int v4; // ebx@1
  int v5; // esi@1
  unsigned __int8 v7; // zf@7
  unsigned __int8 v8; // sf@7
  int v9; // eax@9
  char *v10; // edi@9
  //unsigned __int8 v11; // sf@15
  //unsigned __int8 v12; // of@15
  int v13; // eax@17
  unsigned __int16 v14; // dx@17
  unsigned __int16 v15; // cx@17
  int v16; // eax@27
  int v17; // edi@27
  int v18; // eax@29
  char v19; // zf@29
  int v20; // eax@31
  int v21; // edx@31
  void *v22; // edi@32
  int v23; // eax@34
  int v24; // edi@34
  int v25; // esi@34
  int v26; // edx@35
  int v27; // ecx@35
  __int32 v28; // eax@37
  int i; // esi@39
  __int32 v30; // esi@46
  char Filename[256]; // [sp+Ch] [bp-230h]@22
  char NewFilename[256]; // [sp+10Ch] [bp-130h]@51

  char Str[16 + array_size_unknown]; // [sp+20Ch] [bp-30h]@27
  __int32 Offset; // [sp+21Ch] [bp-20h]@29
  int v36; // [sp+220h] [bp-1Ch]@29
  int v37; // [sp+224h] [bp-18h]@27
  __int16 v38; // [sp+228h] [bp-14h]@27
  __int16 v39; // [sp+22Ah] [bp-12h]@27
  size_t v40; // [sp+22Ch] [bp-10h]@27
  int v41; // [sp+230h] [bp-Ch]@7
  __int32 v42; // [sp+234h] [bp-8h]@8
  int v43; // [sp+238h] [bp-4h]@7
  size_t v44; // [sp+244h] [bp+8h]@40
  __int32 v45; // [sp+244h] [bp+8h]@46
  size_t v46; // [sp+244h] [bp+8h]@47
  FILE *v47; // [sp+24Ch] [bp+10h]@22

  v4 = (int)_this;
  v5 = 0;
  if ( !_this->dword_000104)
    return 1;
  if ( !_this->pLODSubIndexNamedBuffer)
    return 2;
  if ( _this->pLODIOBuffer && _this->uIOBufferSize)
  {
    v7 = _this->uNumSubidices == 0;
    v8 = _this->uNumSubidices < 0;
    v43 = 0;
    v41 = 0;
    if ( v8 | v7 )
    {
      v10 = (char *)Count;
      goto LABEL_22;
    }
    v42 = 0;
    while ( 1 )
    {
      v10 = (char *)Count;
      v9 = _strcmpi((const char *)(v42 + *(_DWORD *)(v4 + 560)), Count);
      if ( v9 )
      {
        if ( v9 > 0 )
          goto LABEL_22;
      }
      else
      {
        if ( !File )
          goto LABEL_20;
        if ( File == (FILE *)1 )
        {
          v14 = *((_WORD *)Count + 14);
          v13 = *(_DWORD *)(v4 + 560) + 32 * v5;
          v15 = *(_WORD *)(v13 + 28);
          if ( v15 >= v14 && (v15 != v14 || *(_WORD *)(v13 + 30) >= *((_WORD *)Count + 15)) )
            return 4;
LABEL_20:
          v43 = 1;
LABEL_22:
          strcpy(Filename, "lod.tmp");
          v47 = fopen(Filename, "wb+");
          if ( !v47 )
            return 5;
          if ( v43 )
            v42 = *(_DWORD *)(32 * v5 + *(_DWORD *)(v4 + 560) + 20);
          else
            v42 = 0;
          v40 = *((_DWORD *)v10 + 5);
          v17 = v40 - v42;
          sub_46172B((int)Str);
          strcpy(Str, "chapter");
          v16 = *(_DWORD *)(v4 + 552);
          v38 = *(_WORD *)(v4 + 556);
          v37 = 0;
          v39 = 0;
          if ( !v43 )
          {
            ++v38;
            v17 += 32;
          }
          v19 = v43 == 0;
          v36 = v17 + v16;
          Offset = 288;
          v18 = v38;
          *(_DWORD *)(v4 + 556) = v38;
          if ( v19 )
          {
            if ( v18 > v5 )
            {
              v21 = 32 * v18;
              v20 = v18 - v5;
              do
              {
                v22 = (void *)(v21 + *(_DWORD *)(v4 + 560));
                v21 -= 32;
                --v20;
                memcpy(v22, (char *)v22 - 32, 0x20u);
              }
              while ( v20 );
              v5 = v41;
            }
          }
          v24 = *(_DWORD *)(v4 + 560);
          v41 = 32 * v5;
          memcpy((void *)(32 * v5 + v24), Count, 0x20u);
          v25 = 0;
          v23 = 32 * *(_DWORD *)(v4 + 556);
          if ( *(_DWORD *)(v4 + 556) > 0 )
          {
            v27 = *(_DWORD *)(v4 + 560);
            v26 = 0;
            do
            {
              *(_DWORD *)(v26 + v27 + 16) = v23;
              v27 = *(_DWORD *)(v4 + 560);
              v23 += *(_DWORD *)(v26 + v27 + 20);
              ++v25;
              v26 += 32;
            }
            while ( v25 < *(_DWORD *)(v4 + 556) );
          }
          locked_fwrite((const void *)(v4 + 272), 0x100u, 1u, v47);
          locked_fwrite(Str, 0x20u, 1u, v47);
          fseek(*(FILE **)v4, Offset, 0);
          locked_fwrite(*(const void **)(v4 + 560), 0x20u, *(_DWORD *)(v4 + 556), v47);
          v28 = 32 * *(_DWORD *)(v4 + 556);
          if ( !v43 )
            v28 -= 32;
          fseek(*(FILE **)v4, v28, 1);
          for ( i = *(_DWORD *)(v41 + *(_DWORD *)(v4 + 560) + 16) - *(_DWORD *)(*(_DWORD *)(v4 + 560) + 16); i > 0; i -= v44 )
          {
            v44 = *(_DWORD *)(v4 + 268);
            if ( i <= *(_DWORD *)(v4 + 268) )
              v44 = i;
            locked_fread(*(void **)(v4 + 264), 1u, v44, *(FILE **)v4);
            locked_fwrite(*(const void **)(v4 + 264), 1u, v44, v47);
          }
          locked_fwrite(a3, 1u, v40, v47);
          if ( v43 )
            fseek(*(FILE **)v4, v42, 1);
          v45 = ftell(*(FILE **)v4);
          fseek(*(FILE **)v4, 0, 2);
          v30 = ftell(*(FILE **)v4) - v45;
          fseek(*(FILE **)v4, v45, 0);
          while ( v30 > 0 )
          {
            v46 = *(_DWORD *)(v4 + 268);
            if ( v30 <= *(_DWORD *)(v4 + 268) )
              v46 = v30;
            locked_fread(*(void **)(v4 + 264), 1u, v46, *(FILE **)v4);
            locked_fwrite(*(const void **)(v4 + 264), 1u, v46, v47);
            v30 -= v46;
          }
          strcpy(NewFilename, (const char *)(v4 + 4));
          fclose(v47);
          LODFile_sub_461EE9((LODFile *)v4);
          remove(NewFilename);
          rename(Filename, NewFilename);
          LODFile_sub_461EE9((LODFile *)v4);
          LODFile_LoadLOD_Games((LODFile *)v4, (const char *)(v4 + 4), 0);
          return 0;
        }
        if ( File == (FILE *)2 )
          return 4;
      }
      v42 += 32;
      ++v5;
      //v12 = __SETO__(v5, *(_DWORD *)(v4 + 556));
      //v11 = v5 - *(_DWORD *)(v4 + 556) < 0;
      v41 = v5;
      if (v5 < *(_DWORD *)(v4 + 556))
        goto LABEL_22;
    }
  }
  return 3;
}

//----- (MM7.exe::0040FC08) --------------------------------------------------------
int LODFile_LoadPalette(struct LODFile *_this, struct class18 *pClass18, const char *pContainerName, unsigned int uSomeInt)
{
  //int v4; // eax@1
  int v5; // ebx@1
  int v6; // edi@1
  struct class18 *v8; // esi@3
  void *v9; // ST24_4@8
  int v10; // esi@14
  size_t v11; // eax@14
  unsigned int v12; // eax@14
  int v13; // eax@21
  int v19; // eax@29
  int v21; // eax@29
  size_t v22; // ST2C_4@29
  const void *v23; // ecx@29
  __int16 v24; // ax@29
  int v25; // ecx@29
  int v26; // edx@29
  int v27; // ecx@29
  int v33; // eax@37
  signed int v34; // eax@37
  int v35;
  int v36; // ecx@37
  signed int v40; // ecx@43
  signed int v41; // ecx@48
  //FILE *v42; // [sp+14h] [bp-4h]@1
  signed int v45; // [sp+20h] [bp+8h]@29

  unsigned char *pCompressedBuffer,
                *pDecompressedBuffer;
  unsigned char aReadBuf[4];
  int   i;
  FILE *f;

  v5 = (int)pContainerName;
  v6 = (int)_this;
 v8 = pClass18;

 f = LODFile_FindContainer(_this, pContainerName, 0);
 if (!f)
   return -1;

 locked_fread(pClass18, 1, 0x30, f);
 strcpy(pClass18->sContainerName, pContainerName);

 if (pD3DRenderer->pRenderD3D3 && pClass18->word_00002C & 0x0002 && _this->dword_011BA8)
  {
    if ( !*(_DWORD *)(v6 + 0x11BAC) || !*(_DWORD *)(v6 + 0x11BB0) )
    {
      compile_error;//*(_DWORD *)(v6 + 0x11BAC) = new char[0xFA0u];
      compile_error;//*(_DWORD *)(v6 + 0x11BB0) = new char[0xFA0u];
      v9 = *(void **)(v6 + 72620);
      compile_error;//*(_DWORD *)(v6 + 0x11BB4) = new char[0x3E8u];
      memset(v9, 0, 0xFA0u);
      memset(*(void **)(v6 + 72624), 0, 0xFA0u);
      memset(*(void **)(v6 + 72628), 0, 0x3E8u);
    }
    if ( *(_BYTE *)v5 != 119
      || *(_BYTE *)(v5 + 1) != 116
      || *(_BYTE *)(v5 + 2) != 114
      || *(_BYTE *)(v5 + 3) != 100
      || *(_BYTE *)(v5 + 4) != 114 )
    {
      if ( *(_BYTE *)v5 != 87
        || *(_BYTE *)(v5 + 1) != 116
        || *(_BYTE *)(v5 + 2) != 114
        || *(_BYTE *)(v5 + 3) != 84
        || *(_BYTE *)(v5 + 4) != 121
        || *(_BYTE *)(v5 + 5) != 108 )
      {
        v13 = *(_DWORD *)(v6 + 72572);
      }
      else
      {
        dword_EF5294 = *(_DWORD *)(v6 + 72572);
        v13 = *(_DWORD *)(v6 + 72572);
      }
      v10 = Render_sub_4A4DE1(
              (int)pD3DRenderer,
              v5,
              *((_WORD *)v8 + 18),
              4 * v13 + *(_DWORD *)(v6 + 72620),
              4 * v13 + *(_DWORD *)(v6 + 72624));
    }
    else
    {
      v11 = strlen((const char *)v5);
      compile_error;//v12 = (unsigned int)operator new(v11 + 2);
      uSomeInt = v12;
      *(_BYTE *)v12 = 104;
      strcpy((char *)(v12 + 1), (const char *)v5);
      v10 = Render_sub_4A4DE1(
              (int)pD3DRenderer,
              uSomeInt,
              *((_WORD *)v8 + 18),
              4 * *(_DWORD *)(v6 + 72572) + *(_DWORD *)(v6 + 72620),
              4 * *(_DWORD *)(v6 + 72572) + *(_DWORD *)(v6 + 72624));
      operator_delete((int *)uSomeInt);
    }
    return v10;
 }



 if (!pClass18->uDecompressedSize || _this->dword_011BA4)
 {
  pClass18->pIndexedPixels = (unsigned char *)mem_mng.AllocatedNamedBuffer( pClass18->pIndexedPixels, pClass18->uCompressedSize, pClass18->sContainerName);
  locked_fread(pClass18->pIndexedPixels, 1u, pClass18->uCompressedSize, f);
 }
 else
 {
  pCompressedBuffer = (unsigned char *)malloc(pClass18->uCompressedSize);
  pDecompressedBuffer = (unsigned char *)malloc(pClass18->uDecompressedSize);

  locked_fread(pCompressedBuffer, 1, pClass18->uCompressedSize, f);
  MemUnzip(pDecompressedBuffer, &pClass18->uDecompressedSize, pCompressedBuffer, pClass18->uCompressedSize);
  call_delete(pCompressedBuffer);

  pClass18->uCompressedSize = pClass18->uDecompressedSize;


  if (bUseLoResSprites && pClass18->word_00002C & 0x0002)
  {
      v45 = (*((_DWORD *)v8 + 4) >> 2) + (*((_DWORD *)v8 + 4) >> 4) + (*((_DWORD *)v8 + 4) >> 6);
      v21 = (int)mem_mng.AllocatedNamedBuffer( (void*) *((_DWORD *)v8 + 12), v45, (const char *)v8);
      v22 = v45;
      compile_error;//v23 = (const void *)(v31 + *((_WORD *)v8 + 12) * *((_WORD *)v8 + 13));
      *((_DWORD *)v8 + 12) = v21;
      memcpy((void *)v21, v23, v22);
      *((_WORD *)v8 + 12) >>= 1;
      v24 = *((_WORD *)v8 + 12);
      *((_WORD *)v8 + 13) >>= 1;
      LOWORD(v25) = *((_WORD *)v8 + 13);
      --*((_WORD *)v8 + 14);
      --*((_WORD *)v8 + 15);
      *((_WORD *)v8 + 16) = v24 - 1;
      v26 = v25 - 1;
      v27 = v24 * (signed __int16)v25;
      v19 = v45;
      *((_WORD *)v8 + 17) = v26;
      *((_DWORD *)v8 + 4) = v27;
      *((_DWORD *)v8 + 5) = v19;
  }
  else
  {
   pClass18->pIndexedPixels = (unsigned char *)mem_mng.AllocatedNamedBuffer( pClass18->pIndexedPixels, pClass18->uDecompressedSize, pClass18->sContainerName);
   memcpy(pClass18->pIndexedPixels, pDecompressedBuffer, pClass18->uDecompressedSize);
  }
  call_delete(pDecompressedBuffer);
 }


 mem_mng.DeleteBuffer( (void *)pClass18->pPalette);
 mem_mng.DeleteBuffer( (void *)pClass18->ptr_000044);

 if (uSomeInt == 1)
 {
  pClass18->ptr_000044 = (unsigned char *)mem_mng.AllocatedNamedBuffer( pClass18->ptr_000044, 768, pClass18->sContainerName);
  locked_fread(pClass18->ptr_000044, 1u, 0x300u, f);

LABEL_35:
  pClass18->pPalette = 0;
  goto LABEL_36;
 }

 pClass18->ptr_000044 = 0;
 if (uSomeInt != 2)
   goto LABEL_35;

 pClass18->pPalette = (unsigned short *)mem_mng.AllocatedNamedBuffer( pClass18->pPalette, 512, pClass18->sContainerName);
 for (i = 0; i < 256; ++i)
 {
  locked_fread(aReadBuf, 3, 1, f);

  pClass18->pPalette[i] = (aReadBuf[0] >> (8 - _this->dword_011B8C)) << (_this->dword_011B94 + _this->dword_011B90);
  pClass18->pPalette[i] += (aReadBuf[1] >> (8 - _this->dword_011B90)) << _this->dword_011B94;
  pClass18->pPalette[i] += aReadBuf[2] >> (8 - _this->dword_011B94);
 }

LABEL_36:
 if (pClass18->word_00002C & 0x0002)
 {
    v34 = *((_DWORD *)v8 + 4);
    v35 = v34 + *((_DWORD *)v8 + 12);
    *((_DWORD *)v8 + 13) = v35;
    v36 = (v34 >> 2) + v35;
    *((_DWORD *)v8 + 14) = v36;
    v33 = v36 + (v34 >> 4);
 }
 else
 {
  v33 = 0;
  pClass18->dword_000034 = 0;
  pClass18->dword_000038 = 0;
 }

 pClass18->dword_00003C = v33;
 v40 = 1;
 while (1 << v40 != pClass18->uTextureWidth)
 {
  ++v40;
  if (v40 >= 15)
    goto LABEL_48;
 }
 pClass18->word_00001C = v40;

LABEL_48:
 v41 = 1;
 while ( 1 << v41 != pClass18->uTextureHeight)
 {
  ++v41;
  if ( v41 >= 15 )
    goto LABEL_53;
 }
 pClass18->word_00001E = v41;

LABEL_53:
 switch (pClass18->word_00001C)
 {
  case 2:   *((_WORD *)v8 + 16) = 3;    break;
  case 3:   *((_WORD *)v8 + 16) = 7;    break;
  case 4:   *((_WORD *)v8 + 16) = 15;   break;
  case 5:   *((_WORD *)v8 + 16) = 31;   break;
  case 6:   *((_WORD *)v8 + 16) = 63;   break;
  case 7:   *((_WORD *)v8 + 16) = 127;  break;
  case 8:   *((_WORD *)v8 + 16) = 255;  break;
  case 9:   *((_WORD *)v8 + 16) = 511;  break;
  case 10:  *((_WORD *)v8 + 16) = 1023; break;
  case 11:  *((_WORD *)v8 + 16) = 2047; break;
  case 12:  *((_WORD *)v8 + 16) = 4095; break;
 }

 switch (pClass18->word_00001E)
 {
  case 2:   *((_WORD *)v8 + 17) = 3;    break;
  case 3:   *((_WORD *)v8 + 17) = 7;    break;
  case 4:   *((_WORD *)v8 + 17) = 15;   break;
  case 5:   *((_WORD *)v8 + 17) = 31;   break;
  case 6:   *((_WORD *)v8 + 17) = 63;   break;
  case 7:   *((_WORD *)v8 + 17) = 127;  break;
  case 8:   *((_WORD *)v8 + 17) = 255;  break;
  case 9:   *((_WORD *)v8 + 17) = 511;  break;
  case 10:  *((_WORD *)v8 + 17) = 1023; break;
  case 11:  *((_WORD *)v8 + 17) = 2047; break;
  case 12:  *((_WORD *)v8 + 17) = 4095; break;
 }

 return 1;
}


//----- (0041097D) --------------------------------------------------------
////int __thiscall sub_41097D(void *_this, int a2, int a3, int a4);
int LODFile_SetupPalettes(struct LODFile *_this, int a2, int a3, int a4)
{
 //depricated, though somehow sets font colors
 compile_warning

 unsigned int v14;
 unsigned int v15;
 
 int             i, j;
 unsigned char   data[4];
 FILE           *f;
 struct class18 *pClass18;
 struct class18  class18_obj;


 if (_this->dword_011B8C != a2 || _this->dword_011B90 != a3 || _this->dword_011B94 != a4)
 {
  _this->dword_011B8C = a2;
  _this->dword_011B90 = a3;
  _this->dword_011B94 = a4;
  if (!_this->uNumLoadedFiles)
    return 0;

  for (i = 0; i < _this->uNumLoadedFiles; ++i)
  {
   pClass18 = &_this->aLODHeaders[i];

   class18_ctor(&class18_obj);
   if (!pClass18->pPalette)
     continue;

   f = LODFile_FindContainer(_this, pClass18->sContainerName, 0);
   if (!f)
     continue;

   locked_fread(&class18_obj, 1, 0x30, f);
   fseek(f, class18_obj.uCompressedSize, SEEK_CUR);

   for (j = 0; j < 512; ++j)
   {
    locked_fread(data + 0, 1, 1, f);
    locked_fread(data + 1, 1, 1, f);
    locked_fread(data + 2, 1, 1, f);

    v14 = (unsigned short)(data[0] >> (8 - (unsigned char)(_this->dword_011B8C)));
    v15 = (unsigned short)(data[1] >> (8 - (unsigned char)(_this->dword_011B90)));

    pClass18->pPalette[j] = v14 << ((unsigned char)(_this->dword_011B90) + (unsigned char)(_this->dword_011B94));
    pClass18->pPalette[j] |= v15 << (unsigned char)(_this->dword_011B94);
    pClass18->pPalette[j] |= data[2] >> (8 - (unsigned char)(_this->dword_011B94));
   }
  }
 }

 return _this->uNumLoadedFiles;
}

//----- (004114F2) --------------------------------------------------------
int LODFile_sub_4114F2(struct LODFile *_this)
{
  int result; // eax@1
  int v2; // ecx@1
  int v3; // esi@1
  int v4; // ecx@2
  int v5; // edi@3
  int v6; // ebx@4
  int v7; // eax@5
  int v8; // eax@6
  int v9; // eax@8
  int v10; // eax@9

  v3 = (int)_this;
  result = (int)&_this->dword_011B9C;
  v2 = _this->dword_011B9C;
  if ( v2 )
  {
    v4 = v2 - 1;
    _this->dword_011B9C = v4;
    if ( !v4 )
    {
      v5 = _this->uNumLoadedFiles - 1;
      if ( v5 >= _this->dword_011B98)
      {
        v6 = (int)&_this->aLODHeaders[v5];
        do
        {
          class18_sub_40F77C((class18 *)v6);
          v7 = (int)_this->pHardwareTextures;
          if ( v7 )
          {
            v8 = *(_DWORD *)(v7 + 4 * v5);
            if ( v8 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v8 + 8))(v8);
              *(_DWORD *)(*(_DWORD *)(v3 + 72624) + 4 * v5) = 0;
            }
          }
          v9 = *(_DWORD *)(v3 + 72620);
          if ( v9 )
          {
            v10 = *(_DWORD *)(v9 + 4 * v5);
            if ( v10 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v10 + 8))(v10);
              *(_DWORD *)(*(_DWORD *)(v3 + 72620) + 4 * v5) = 0;
            }
          }
          --v5;
          v6 -= 72;
        }
        while ( v5 >= *(_DWORD *)(v3 + 72600) );
      }
      result = *(_DWORD *)(v3 + 72600);
      *(_DWORD *)(v3 + 72600) = 0;
      *(_DWORD *)(v3 + 72572) = result;
    }
  }
  return result;
}



unsigned int LODFile_LoadTexture_New(struct LODFile *_this, const wchar_t *pFilename)
{
 void    *hFile;
 DWORD    w;
 wchar_t  pFileNotFound[256];

 wchar_t      pFilePath[256];
 unsigned int uCBMWdith,
              uCBMHeight;

 int  i;
 char pAnsiFilename[256];

 wsprintfA(pAnsiFilename, "%S", pFilename);
 for (i = 0; i < _this->uNumLoadedFiles; ++i)
 {
  if (!lstrcmpiA(pAnsiFilename, _this->aLODHeaders[i].sContainerName))
    return i;
 }



 if (_this->uNumLoadedFiles >= 2500) //>= 1000
   err_show();

 //try to open CBM
 wsprintfW(pFilePath, L".\\Data\\%S\\%s.cbm", _this->sContainerName, pFilename);
 if (LoadCBM(pFilePath, &uCBMWdith, &uCBMHeight, &_this->aLODHeaders[_this->uNumLoadedFiles].pTruecolorPixels))
 {
  //try open TGA
  wsprintfW(pFilePath, L".\\Data\\%S\\%s.tga", _this->sContainerName, pFilename);
  if (LoadTGA(pFilePath, &uCBMWdith, &uCBMHeight, &_this->aLODHeaders[_this->uNumLoadedFiles].pTruecolorPixels))
  {
   //try open PNG
   wsprintfW(pFilePath, L".\\Data\\%S\\%s.png", _this->sContainerName, pFilename);
   if (LoadPNG(pFilePath, &uCBMWdith, &uCBMHeight, &_this->aLODHeaders[_this->uNumLoadedFiles].pTruecolorPixels))
   {
    if (LoadHWL(pFilename, &uCBMWdith, &uCBMHeight, &_this->aLODHeaders[_this->uNumLoadedFiles].pTruecolorPixels))
    {
     if (!hStdHandle)
       hStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
     wsprintfW(pFileNotFound, L"Texture not found: %s\n", pFilename);
     WriteConsoleW(hStdHandle, pFileNotFound, lstrlenW(pFileNotFound), &w, 0);

     if (!pending_texture.pTruecolorPixels)
       pending_texture.pTruecolorPixels = new unsigned int[52 * 53];
     pending_texture.uTextureWidth = 52;
     pending_texture.uTextureHeight = 53;
     return -1;
    }
   }
  }
 }

 wsprintfA(_this->aLODHeaders[_this->uNumLoadedFiles].sContainerName, "%S", pFilename);
 _this->aLODHeaders[_this->uNumLoadedFiles].uTextureWidth = uCBMWdith;
 _this->aLODHeaders[_this->uNumLoadedFiles].uTextureHeight = uCBMHeight;

 Render_MoveToGPU(pD3DRenderer, uCBMWdith, uCBMHeight, _this->aLODHeaders[_this->uNumLoadedFiles].pTruecolorPixels, &_this->pHardwareSurfaces[_this->uNumLoadedFiles], &_this->pHardwareTextures[_this->uNumLoadedFiles]);

 _this->uNumLoadedFiles++;
 return _this->uNumLoadedFiles - 1;
}

 //----- (0046161C) --------------------------------------------------------
bool LODFile_Games_LOD_FindLeveL(struct LODFile *_this, const char *pLevelName)
{
  int v2; // ebx@1

  v2 = 0;
  if (!_this->uNumSubidices)
    return false;

  while (strcmpi(pLevelName, (char *)_this->pLODSubIndexNamedBuffer[v2++].pFilename))
  {
   if ( v2 >= _this->uNumSubidices)
     return false;
  }
 return true;
}


 

//----- (004AC7C0) --------------------------------------------------------
unsigned int LODFile_LoadSprite(struct LODFile *_this, const char *pSourceFile, int a3)
{
  int v4; // esi@1
  int v8; // eax@12
  signed int v12; // eax@22
  struct
  {
   char DstBuf[0x10]; // [sp+Ch] [bp-3Ch]@13
  __int16 v16; // [sp+1Ch] [bp-2Ch]@21
  __int16 v17; // [sp+1Eh] [bp-2Ah]@12
  __int16 v18; // [sp+20h] [bp-28h]@12
  short _22;
  short _24;
  __int16 v19; // [sp+26h] [bp-22h]@12
   short _28;
   short _2A;
  int v20; // [sp+2Ch] [bp-1Ch]@12
  int v21; // [sp+30h] [bp-18h]@12
  } local_0C;
  int v24; // [sp+44h] [bp-4h]@12
 int i;


 v4 = (int)_this;
 if (pD3DRenderer->pRenderD3D3)
 {
  for (i = 0; i < _this->uNumLoadedSprites; ++i)
   if (!strcmpi((char *)_this->pHardwareSprites[i].pSpriteName, pSourceFile))
      return i;
 }
 else for (i = 0; i < _this->uNumLoadedSprites; ++i)
   if (!strcmpi(_this->aLODHeaders[i].sContainerName, pSourceFile))
     return i;

 if (_this->uNumLoadedSprites >= 3000)
   return -1;


 if (pD3DRenderer->pRenderD3D3 && _this->dword_00ECAC)
 {
  if (!_this->pHardwareSprites)
  {
   _this->pHardwareSprites = (HardwareSprite *)mem_mng.AllocatedNamedBuffer( NULL, 3000 * sizeof(struct HardwareSprite), "hardwareSprites");

   for (i = 0; i < 3000; ++i)
   {
    _this->pHardwareSprites[i].pSpriteName = 0;
    _this->pHardwareSprites[i].pTexture = 0;
    _this->pHardwareSprites[i].pTextureSurface = 0;
   }
  }

    local_0C.v17 = 0;
    local_0C.v18 = 0;
    local_0C.v19 = 0;
    local_0C.v20 = 0;
    local_0C.v21 = 0;
    v24 = 0;
    v8 = (int)LODFile_FindContainer(_this, pSourceFile, 0);
    if ( !v8 )
    {
      v24 = -1;
      //sub_462463((int)&local_0C);
      return -1;
    }

    locked_fread(&local_0C, 1u, 0x20, (FILE *)v8);
    v24 = -1;
    _this->pHardwareSprites[_this->uNumLoadedSprites].dword_000018 = local_0C.v16;
    _this->pHardwareSprites[_this->uNumLoadedSprites].dword_00001C = local_0C.v17;
    _this->aLODHeaders[_this->uNumLoadedSprites].word_000010 = local_0C.v16;
    _this->aLODHeaders[_this->uNumLoadedSprites].word_000012 = local_0C.v17;
    //sub_462463(&local_0C);
    goto LABEL_29;
  }

  v12 = sub_4AC67E_LoadSpriteFromFile(_this, &_this->aLODHeaders[_this->uNumLoadedSprites], pSourceFile);
  _this->aLODHeaders[_this->uNumLoadedSprites].uTextureHeight = 0;
  if ( v12 != -1 )
  {
LABEL_28:
   _this->aLODHeaders[_this->uNumLoadedSprites].uPaletteID = class35_sub_48A3BC_MessWithPalettes(&class35_obj, _this->aLODHeaders[_this->uNumLoadedSprites].uPaletteID);

LABEL_29:
    if (pD3DRenderer->pRenderD3D3)
    {
     _this->pHardwareSprites[_this->uNumLoadedSprites].pSpriteName = (unsigned char *)mem_mng.AllocatedNamedBuffer( _this->pHardwareSprites[_this->uNumLoadedSprites].pSpriteName, 20, pSourceFile);
     strcpy((char *)_this->pHardwareSprites[_this->uNumLoadedSprites].pSpriteName, pSourceFile);
     _this->pHardwareSprites[_this->uNumLoadedSprites].dword_000004 = a3;
     Render_MoveHWSpriteToVideoMemory(pD3DRenderer, &_this->pHardwareSprites[_this->uNumLoadedSprites]);
    }
    ++_this->uNumLoadedSprites;
    return _this->uNumLoadedSprites - 1;
  }
  if (!_this->uNumLoadedSprites)
  {
LABEL_27:
    if ( sub_4AC67E_LoadSpriteFromFile(_this, &_this->aLODHeaders[_this->uNumLoadedSprites], "pending") == -1 )
      return -1;
    goto LABEL_28;
  }

 for (i = 0; i < _this->uNumLoadedSprites; ++i)
   if (!strcmpi(_this->aLODHeaders[i].sContainerName, "pending"))
     return i;

 goto LABEL_27;
}



//----- (MM7.exe::0040FAEE) -------0040FDE7 -------------------------------------------------
int LODFile_LoadLOD_Icons_Events(struct LODFile *_this, const char *pFilename)
{
 LODFile_fn4(_this);
 if (LODFile_MaybeLoadLODHeader(_this, pFilename, 1))
   return 0;
 
 _this->pHardwareSurfaces = new IDirectDrawSurface4 *[1000];
 _this->pHardwareTextures = new IDirect3DTexture2 *[1000];
 _this->dword_011BB4 = new void *[250];
  
 return LODFile_fn6(_this, "icons") == 0;
}

//----- (MM7.exe::0040FA2E) --------------------------------------------------------
int LODFile_LoadLOD_Bitmaps(struct LODFile *_this, const char *pFilename)
{
 LODFile_fn4(_this);
 if (LODFile_MaybeLoadLODHeader(_this, pFilename, 1))
   return 0;

 _this->pHardwareSurfaces = new IDirectDrawSurface4 *[1000];
 _this->pHardwareTextures = new IDirect3DTexture2 *[1000];
 _this->dword_011BB4 = new void *[250];

 return LODFile_fn6(_this, "bitmaps") == 0;
}

//----- (MM7.exe::004AC795) --------------------------------------------------------
int LODFile_LoadLOD_Sprites(struct LODFile *_this, const char *pFilename)
{
 if (LODFile_MaybeLoadLODHeader(_this, pFilename, 1))
   return 0;

 return LODFile_fn6(_this, "sprites08") == 0;
}

//----- (MM7.exe::0041088B) --------------------------------------------------------
void *LODFile_LoadRaw(struct LODFile *_this, const char *pContainer, int a3)
{
  unsigned char *result; // ebx@7
  unsigned char *v8; // edi@7
  struct class18 class18_obj; // [sp+Ch] [bp-4Ch]@1
  FILE *pContainerFile; // [sp+54h] [bp-4h]@1

  wchar_t  pLodFile[256];
  void    *hFile;
  DWORD    w;
  int      ofs;


  class18_ctor(&class18_obj);

  pContainerFile = LODFile_FindContainer(_this, pContainer, 0);
  if (!pContainerFile)
  {
    erroneous_printf("Unable to load %s", pContainer);
	return NULL;
  }


    wsprintfW(pLodFile, L".\\%S", _this->sLODName);
    hFile = CreateFileW(pLodFile, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
    ofs = ftell(pContainerFile);
    SetFilePointer(hFile, ofs, 0, FILE_BEGIN);


  //locked_fread(&class18_obj, 1, 0x30u, pContainerFile);
  ReadFile(hFile, &class18_obj, 0x30, &w, 0);
  if (class18_obj.uDecompressedSize)
  {
    if (a3)
      result = (unsigned char *)malloc(class18_obj.uDecompressedSize);
    else
      result = (unsigned char *)mem_mng.AllocatedNamedBuffer( NULL, class18_obj.uDecompressedSize, class18_obj.sContainerName);

    v8 = (unsigned char *)mem_mng.AllocatedNamedBuffer( NULL, class18_obj.uCompressedSize, class18_obj.sContainerName);

    ReadFile(hFile, v8, class18_obj.uCompressedSize, &w, 0);
    //fread(v8, 1, class18_obj.uCompressedSize, pContainerFile);


    MemUnzip(result, &class18_obj.uDecompressedSize, v8, class18_obj.uCompressedSize);
    class18_obj.uCompressedSize = class18_obj.uDecompressedSize;
    mem_mng.DeleteBuffer( (void *)v8);
  }
  else
  {
    if (a3)
      result = (unsigned char *)malloc(class18_obj.uCompressedSize);
    else
     result = (unsigned char *)mem_mng.AllocatedNamedBuffer( 0, class18_obj.uCompressedSize, class18_obj.sContainerName);
    locked_fread(result, 1u, class18_obj.uCompressedSize, pContainerFile);
  }

    CloseHandle(hFile);
    fseek(pContainerFile, ofs + class18_obj.uCompressedSize, SEEK_SET);


  return result;
}

//----- (MM7.exe::00461580) --------------------------------------------------------
FILE *LODFile_FindContainer(struct LODFile *_this, const char *pContainerName, int a3)
{
  int v4; // eax@4
  int v5; // edi@5
  int v7; // [sp+18h] [bp+Ch]@6

  if (!_this->dword_000104)
    return 0;
  if (a3)
  {
    v5 = 0;
    if (_this->uNumSubidices > 0)
    {
      v7 = 0;
      while (_strcmpi(pContainerName, (const char *)(_this->pLODSubIndexNamedBuffer) + v7))
      {
        v7 += 32;
        ++v5;
        if (v5 >= _this->uNumSubidices)
          return 0;
      }
      v4 = *(_DWORD *)(32 * v5 + (char *)_this->pLODSubIndexNamedBuffer + 16);
      goto LABEL_12;
    }
    return 0;
  }
  LODFile_fn3(_this, 0, _this->uNumSubidices, pContainerName);
  if ( dword_6A0CA4 < 0 )
    return 0;
  v4 = *(_DWORD *)((char *)_this->pLODSubIndexNamedBuffer + 32 * dword_6A0CA4 + 16);
LABEL_12:

 fseek(_this->pLODFile, _this->dword_000234 + v4, 0);
 return _this->pLODFile;
}

//----- (MM7.exe::0046165E) --------------------------------------------------------
int LODFile_fn3(struct LODFile *_this, int a2, int a3, const char *pContainerName)
{
  int v4; // esi@1
  int result; // eax@2
  int v6; // ebx@2
  int v7; // edi@10
  int v8; // esi@11
  int v9; // esi@17
  void *v10; // [sp+Ch] [bp-4h]@1

  v4 = a2;
  v10 = _this;
  while (true)
  {
    while (true)
    {
      v6 = a3 - v4;
      result = _strcmpi(pContainerName, (char *)_this->pLODSubIndexNamedBuffer[(a3 - v4) / 2 + v4].pFilename);
      if ( !result )
        dword_6A0CA4 = (a3 - v4) / 2 + v4;
      if ( v4 == a3 )
        goto LABEL_14;
      if ( result < 0 )
        break;
      if ( v6 <= 4 )
      {
        v7 = v4;
        if ( v4 < a3 )
        {
          v9 = 32 * v4;
          do
          {
            result = _strcmpi(pContainerName, (const char *)(v9 + *((_DWORD *)v10 + 140)));
            if ( !result )
              goto LABEL_21;
            ++v7;
            v9 += 32;
          }
          while ( v7 < a3 );
        }
LABEL_14:
        dword_6A0CA4 = -1;
        return result;
      }
      v4 += (a3 - v4) / 2;
    }
    if ( v6 <= 4 )
      break;
    a3 = (a3 - v4) / 2 + v4;
  }
  v7 = v4;
  if ( v4 >= a3 )
    goto LABEL_14;
  v8 = 32 * v4;
  while ( 1 )
  {
    result = _strcmpi(pContainerName, (const char *)(v8 + *((_DWORD *)v10 + 140)));
    if ( !result )
      break;
    ++v7;
    v8 += 32;
    if ( v7 >= a3 )
      goto LABEL_14;
  }
LABEL_21:
  dword_6A0CA4 = v7;
  return result;
}

//----- (MM7.exe::0040FA60) --------------------------------------------------------
void LODFile_fn4(struct LODFile *_this)
{
  int v1; // edi@1
  int v2; // esi@1
  int v3; // ebp@2
  int v4; // eax@3
  int v5; // eax@4
  int v6; // eax@6
  int v7; // eax@7

 v2 = (int)_this;
 v1 = _this->uNumLoadedFiles  - 1;

 if (v1 >= 0)
 {
  v3 = (int)((char *)_this + 572 + 72 * v1);

  do
  {
   class18_sub_40F77C((class18 *)v3);
   v4 = (int)_this->pHardwareTextures;
   if (v4)
   {
    v5 = *(_DWORD *)(v4 + 4 * v1);

        if ( v5 )
        {
          (*(void (__stdcall **)(int))(*(_DWORD *)v5 + 8))(v5);
          *(_DWORD *)(*(_DWORD *)(v2 + 72624) + 4 * v1) = 0;
        }
      }
      v6 = *(_DWORD *)(v2 + 72620);
      if ( v6 )
      {
        v7 = *(_DWORD *)(v6 + 4 * v1);
        if ( v7 )
        {
          (*(void (__stdcall **)(int))(*(_DWORD *)v7 + 8))(v7);
          *(_DWORD *)(*(_DWORD *)(v2 + 72620) + 4 * v1) = 0;
        }
      }
      --v1;
      v3 -= 72;
    }
    while ( v1 >= 0 );
  }
 _this->uNumLoadedFiles = 0;
 _this->dword_011B80 = 0;
 _this->dword_011B84 = 0;

 _this->dword_011B98 = 0;
 _this->dword_011B9C = 0;
}

//----- (MM7.exe::004617D5) --------------------------------------------------------
int LODFile_MaybeLoadLODHeader(struct LODFile *_this, const char *pFilename, char a3)
{
  int v3; // esi@1
  const char *v7; // [sp-4h] [bp-Ch]@4


 if (_this->dword_000104)
   LODFile_sub_461431((int)_this);

 if (a3 & 1)
   v7 = "rb";
 else 
	v7 = "rb+";

  fopen_s(&_this->pLODFile, pFilename, v7);
 if (!_this->pLODFile)
	 {
	 v3=errno;
   return 1;
	 }
 strcpy(_this->sLODName, pFilename);

 locked_fread(&_this->sLODFileHeader, sizeof(struct LODFileHeader), 1, _this->pLODFile);

 _this->dword_000210 =(char*) mem_mng.AllocatedNamedBuffer( _this->dword_000210, 160, "LOD CArray");

 if (!_this->dword_000210)
 {
  fclose(_this->pLODFile);
  return 1;
 }

 locked_fread(_this->dword_000210, 0x20, _this->sLODFileHeader.uNumFiles, _this->pLODFile);

 fseek(_this->pLODFile, 0, SEEK_SET);
 _this->dword_000104 = 1;
 return 0;
}

//----- (MM7.exe::0046188A) --------------------------------------------------------
int LODFile_fn6(struct LODFile *_this, const char *pContainer)
{
  int v2; // edi@1
  int v3; // esi@1
  int v4; // ebx@2
  signed int result; // eax@5
  int v7; // eax@7
  int v8; // eax@7
  __int32 v9; // edx@7

 v3 = (int)_this;
 LODFile_fn7(_this);
 v2 = 0;

 if (_this->sLODFileHeader.uNumFiles <= 0)
 {
LABEL_5:
  result = 3;
 }
 else
 {
  v4 = 0;
  while (strcmpi(pContainer, &((char *)(_this->dword_000210))[v4]))
  {
   ++v2;
   v4 += 32;
   if (v2 >= _this->sLODFileHeader.uNumFiles)
     goto LABEL_5;
  }

  strcpy(_this->sContainerName, pContainer);

  v7 = (int)_this->dword_000210;
  _this->dword_000224 = v2;

  v8 = 32 * v2 + v7;
  v9 = *(_DWORD *)(v8 + 16);
  _this->dword_000234 = v9;

  _this->uNumSubidices = *(_WORD *)(v8 + 28);
  fseek(_this->pLODFile, v9, 0);

  _this->pLODSubIndexNamedBuffer = (LODIndex *)mem_mng.AllocatedNamedBuffer(_this->pLODSubIndexNamedBuffer, (_this->uNumSubidices + 5) * sizeof(struct LODIndex), "LOD Index");

  if (_this->pLODSubIndexNamedBuffer)
    locked_fread(_this->pLODSubIndexNamedBuffer, sizeof(struct LODIndex), _this->uNumSubidices, _this->pLODFile);
  result = 0;
 }
 return result;
}

//----- (0046153F) --------------------------------------------------------
int LODFile_fn7(struct LODFile *_this)
{
 int result; // eax@2
 result=0;
 if (_this->dword_000104)
 {
  _this->sContainerName[0] = 0;
  _this->dword_000224 = 0;

  _this->dword_000228 = 0;
  _this->uNumSubidices = 0;
  _this->dword_000234 = 0;

  mem_mng.DeleteBuffer( (void *)_this->pLODSubIndexNamedBuffer);
  _this->pLODSubIndexNamedBuffer = 0;
 }
 return result;
}



//----- (MM7.exe::0040FB20) --------------------------------------------------------
int LODFile_LoadTexture(struct LODFile *_this, const char *pContainerName, unsigned int a3)
{
  int v3; // edi@1
  struct class18 *pClass18; // ebx@2
  int v6; // ebx@8

 v3 = 0;
 dword_506128 = 1;
 if (_this->uNumLoadedFiles <= 0 )
 {
LABEL_5:
  if (_this->uNumLoadedFiles >= 1000)
    err_show();

  if (LODFile_LoadPalette(_this, &_this->aLODHeaders[_this->uNumLoadedFiles], pContainerName, a3) == -1)
  {
   v6 = 0;
   if (_this->uNumLoadedFiles > 0)
   {
    pClass18 = _this->aLODHeaders;
    while (_strcmpi(pClass18->sContainerName, "pending"))
    {
     pClass18++;
     ++v6;
     if (v6 >= _this->uNumLoadedFiles)
       goto LABEL_15;
    }
    return v6;
   }

LABEL_15:
   LODFile_LoadPalette(_this, &_this->aLODHeaders[_this->uNumLoadedFiles], "pending", a3);
  }
  dword_506128 = 0;
  _this->uNumLoadedFiles++;
  return _this->uNumLoadedFiles - 1;
 }

 pClass18 = _this->aLODHeaders;
 while (_strcmpi(pClass18->sContainerName, pContainerName))
 {
  ++v3;
  pClass18++;
  if (v3 >= _this->uNumLoadedFiles)
    goto LABEL_5;
 }
 return v3;
}









//----- (004AC67E) --------------------------------------------------------
int sub_4AC67E_LoadSpriteFromFile(struct LODFile *_this, struct class18 *pDstBuf, const char *pFilename)
{
  signed int v6; // eax@3
  char *v8; // esi@3
  int i; // edx@6
  int v16; // [sp+10h] [bp+8h]@4
 FILE *f;

  f = LODFile_FindContainer(_this, pFilename, 0);
  if (!f)
    return -1;

   v8 = (char *)pDstBuf;
   locked_fread(pDstBuf, 1, 0x20, f);
   strcpy(pDstBuf->sContainerName, pFilename);
   pDstBuf->pSomeSpriteData = (SomeSpriteData *)mem_mng.AllocatedNamedBuffer( pDstBuf->pSomeSpriteData, 8 * pDstBuf->word_000012, pDstBuf->sContainerName);
   locked_fread(pDstBuf->pSomeSpriteData, 1, 8 * pDstBuf->word_000012, f);
   v6 = pDstBuf->dword_00001C;
    if ( v6 )
    {
     pDstBuf->ptr_000024 = (unsigned char *)mem_mng.AllocatedNamedBuffer( pDstBuf->ptr_000024, v6, pDstBuf->sContainerName);
     v16 = (int)mem_mng.AllocatedNamedBuffer( 0, pDstBuf->dword_00000C, pDstBuf->sContainerName);
     locked_fread((void *)v16, 1, pDstBuf->dword_00000C, f);
     MemUnzip(pDstBuf->ptr_000024, (unsigned int *)&pDstBuf->dword_00001C, (int *)v16, pDstBuf->dword_00000C);
     pDstBuf->dword_00000C = pDstBuf->dword_00001C;
     mem_mng.DeleteBuffer( (void *)(int *)v16);
    }
    else
    {
     pDstBuf->ptr_000024 = (unsigned char *)mem_mng.AllocatedNamedBuffer( pDstBuf->ptr_000024, pDstBuf->dword_00000C, pDstBuf->sContainerName);
     locked_fread(pDstBuf->ptr_000024, 1, pDstBuf->dword_00000C, f);
    }


    for (i = 0; i < pDstBuf->word_000012; ++i)
      pDstBuf->pSomeSpriteData[i].ptr_000004 += (unsigned int)pDstBuf->ptr_000024;
 
  return 1;
}


//----- (004645DC) --------------------------------------------------------
int sub_4645DC(struct LODFile *_this)
{
  int result; // eax@1
  int v1;
  int v2; // esi@1
  int v3; // edi@1

  v1 = (int)_this;
  v2 = v1 + 60572;
  v3 = v1 + 60576;
  sub_450CA9((int)_this, *(_DWORD *)(v1 + 60576), *(_DWORD *)(v1 + 60572));
  result = *(_DWORD *)v3;
  *(_DWORD *)v2 = *(_DWORD *)v3;
  return result;
}


//----- (0046454B) --------------------------------------------------------
int sub_46454B(struct LODFile *_this)
{
  int v1; // edi@1
  int v2; // esi@1
  struct class18 *v3; // ebx@2
  int v4; // eax@3
  int v5; // eax@4
  int v6; // eax@6
  int v7; // eax@7
  int result; // eax@10

  v2 = (int)_this;
  v1 = _this->uNumLoadedFiles - 1;
  if ( v1 >= _this->dword_011B84)
  {
    //v3 = v2 + 72 * v1 + 572;
    v3 = &_this->aLODHeaders[v1];
    do
    {
     runtime_warning(this stuff kills textures being drawn);
      //class18_sub_40F77C(v3);
      v4 = *(_DWORD *)(v2 + 72624);
      if ( v4 )
      {
        v5 = *(_DWORD *)(v4 + 4 * v1);
        if ( v5 )
        {
          (*(void (__stdcall **)(int))(*(_DWORD *)v5 + 8))(v5);
          *(_DWORD *)(*(_DWORD *)(v2 + 72624) + 4 * v1) = 0;
        }
      }
      v6 = *(_DWORD *)(v2 + 72620);
      if ( v6 )
      {
        v7 = *(_DWORD *)(v6 + 4 * v1);
        if ( v7 )
        {
          (*(void (__stdcall **)(int))(*(_DWORD *)v7 + 8))(v7);
          *(_DWORD *)(*(_DWORD *)(v2 + 72620) + 4 * v1) = 0;
        }
      }
      --v1;
      v3 -= 72;
    }
    while ( v1 >= _this->dword_011B84);
  }
  result = *(_DWORD *)(v2 + 72580);
  *(_DWORD *)(v2 + 72604) = 0;
  *(_DWORD *)(v2 + 72600) = 0;
  *(_DWORD *)(v2 + 72572) = result;
  return result;
}

unsigned char *LODFile_LoadEvent(struct LODFile *_this, const wchar_t *pFilename)
{
 DWORD          w;
 void          *hFile;
 unsigned char *pOut;
 wchar_t        pFilepath[256];
 char           pFilenameA[256];

 wsprintfW(pFilepath, L".\\Data\\Events\\%s", pFilename);
 hFile = CreateFileW(pFilepath, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
 if (hFile == INVALID_HANDLE_VALUE)
 {
  wsprintfA(pFilenameA, "%S", pFilename);
  return (unsigned char *)LODFile_LoadRaw(_this, pFilenameA, 0);
 }

 pOut = new unsigned char[GetFileSize(hFile, 0)];
 ReadFile(hFile, pOut, GetFileSize(hFile, 0), &w, 0);

 CloseHandle(hFile);
 return pOut;
	}

