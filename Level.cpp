#include <io.h>

#include "Level.h"
#include "menus.h"
#include "data.h"
 #include "_lod.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "_audio.h"
#include "FrameTables.h"

#include "Actor.h"

#include "RenderD3D3.h"


bool __cdecl TryLoadLevelFromFile(); // internal
bool LoadLevelFromODM(struct class51 *_this, const char *Source, int File, int a4, int a5); // internal



//----- (00488EB1) --------------------------------------------------------
int class51_sub_488EB1_GetSomeOtherTileInfo(struct class51 *_this, int sX, int sY)
{
  int v3; // eax@1
  int v4; // edi@1

 v4 = WorldPosToGridCellZ(sY);
 v3 = WorldPosToGridCellX(sX);
 if ( v3 < 0 || v3 > 127 || v4 < 0 || v4 > 127 )
   return 0;

 return class51_sub_47EDB3_ActuallyGetSomeOtherTileInfo(_this, v3, v4);
}

//----- (0047EDB3) --------------------------------------------------------
int class51_sub_47EDB3_ActuallyGetSomeOtherTileInfo(struct class51 *_this, unsigned int uX, unsigned int uY)
{
  int v3; // esi@5

 if (uX > 127 || uY > 127)
   return 0;
 else
 {
   v3 = _this->struct_0000B4.pTilemap[128 * uY + uX];
   if ( v3 >= 90 )
     v3 = v3 + _this->array_0000A0[1 + (v3 - 90) / 18] - 36 * (v3 - 90) / 36 - 90;
   return pTileTable->pTiles[v3].word_000018;
 }
}

//----- (00488EEF) --------------------------------------------------------
int class51_GetTileTexture(struct class51 *_this, int sX, int sY)
{
 int v3; // eax@1
 int v4; // edi@1

 v4 = WorldPosToGridCellZ(sY);
 v3 = WorldPosToGridCellX(sX);
 if ( v3 < 0 || v3 > 127 || v4 < 0 || v4 > 127 )
   return -1;
 return class51_GetTileTexture2(_this, v3, v4);
}

//----- (0047ED08) --------------------------------------------------------
int class51_GetTileTexture2(struct class51 *_this, unsigned int uX, unsigned int uY)
{
 int v3; // esi@5

 if (uX > 127 || uY > 127)
   return 0;

 v3 = _this->struct_0000B4.pTilemap[uY * 128 + uX];
 if (v3 < 198)
 {
  if (v3 >= 90)
    v3 = v3 + _this->array_0000A0[1 + (v3 - 90) / 18] - 36 * (v3 - 90) / 36 - 90;
 }
 else
   v3 = v3 + _this->array_0000A0[7] - 198;

 return pTileTable->pTiles[v3].word_000012;
}

//----- (0047D0A6) --------------------------------------------------------
bool LoadLevelFromODM(struct class51 *_this, const char *Source, int File, int a4, int a5)
{
 int v5;
  FILE *result; // eax@9
  FILE *v7; // ebx@9
  size_t v8; // eax@10
  int v9; // eax@10
  int v10; // eax@10
  int v11; // eax@10
  int v12; // ebx@11
  int v13; // eax@12
  int v14; // eax@12
  int v15; // eax@12
  int v16; // eax@12
  int v17; // eax@12
  int v18; // ecx@12
  void *v19; // eax@12
  int v20; // ecx@12
  __int16 v21; // ax@15
  __int16 v22; // ax@16
  int v23; // ecx@16
  FILE *v24; // ebx@26
  _UNKNOWN *v25; // ecx@27
  FILE *v26; // eax@28
  int v27; // eax@28
  unsigned __int8 v28; // zf@28
  unsigned __int8 v29; // sf@28
  int i; // edx@29
  __int16 v31; // ax@33
  __int16 v33; // ax@37
  int v34; // ecx@37
  int v35; // eax@38
  int v36; // eax@38
  int v38; // eax@43
  int v39; // edi@45
  size_t v40; // eax@50
  unsigned char *v42; // eax@56
  size_t v44; // edi@56
  int v45; // eax@58
  int v48; // eax@59
  int v51; // ebx@60
  int v52; // eax@61
  __int16 v64; // ax@64
  __int16 v65; // ax@65
  struct class51_stru2 *v66; // ecx@65
  __int16 v67; // ax@80
  int v69; // eax@81
  int v73; // eax@81
  int v76; // eax@81
  size_t v77; // eax@81
  int v78; // edi@87
  int v79; // edi@88
  int v80; // eax@92
  int v82; // ecx@94
  int v83; // eax@95
  int v84; // edx@97
  int v85; // eax@99
  int v86; // eax@107
  int v87; // eax@110
  int v89; // edi@114
  int v90; // eax@118
  size_t v92; // eax@120
  int v100; // eax@129
  int v106; // eax@147
  int v108; // eax@147
  int v109; // eax@147
  struct TileDesc *v110; // eax@147
  int v111; // ecx@150
  int v113; // edi@159
  char v115; // [sp-14h] [bp-B94h]@55
  int v116; // [sp-10h] [bp-B90h]@55
  int v117; // [sp-Ch] [bp-B8Ch]@55
  void *v118; // [sp-8h] [bp-B88h]@55
  signed int v119; // [sp-4h] [bp-B84h]@12
  int v120; // [sp+0h] [bp-B80h]@10
  char v121[0x3C8]; // [sp+10h] [bp-B70h]@110
  char v122[0x3C8]; // [sp+3D8h] [bp-7A8h]@110
  //char v123[4]; // [sp+79Ch] [bp-3E4h]@50
  char Str1[256]; // [sp+7A0h] [bp-3E0h]@50
  char DstBuf; // [sp+8A0h] [bp-2E0h]@10
  __int32 Offset; // [sp+8A4h] [bp-2DCh]@10
  __int32 v127; // [sp+8B0h] [bp-2D0h]@10
  __int32 v128; // [sp+8BCh] [bp-2C4h]@10
  __int32 v129; // [sp+8C8h] [bp-2B8h]@10
  __int32 v130; // [sp+8D4h] [bp-2ACh]@10
  __int32 v131; // [sp+8E0h] [bp-2A0h]@10
  __int32 v132; // [sp+8ECh] [bp-294h]@10
  __int32 v133; // [sp+8F8h] [bp-288h]@10
  __int32 v134; // [sp+904h] [bp-27Ch]@10
  __int32 v135; // [sp+910h] [bp-270h]@10
  __int32 v136; // [sp+91Ch] [bp-264h]@10
  __int32 v137; // [sp+928h] [bp-258h]@26
  __int32 v138; // [sp+934h] [bp-24Ch]@35
  __int32 v139; // [sp+940h] [bp-240h]@38
  __int32 v140; // [sp+94Ch] [bp-234h]@38
  __int32 v141; // [sp+958h] [bp-228h]@38
  __int32 v142; // [sp+964h] [bp-21Ch]@38
  __int32 v143; // [sp+970h] [bp-210h]@38
  __int32 v144; // [sp+97Ch] [bp-204h]@38
  __int32 v145; // [sp+988h] [bp-1F8h]@38
  __int32 v146; // [sp+994h] [bp-1ECh]@38
  __int32 v147; // [sp+9A0h] [bp-1E0h]@38
  __int32 v148; // [sp+9ACh] [bp-1D4h]@38
  __int32 v149; // [sp+9D0h] [bp-1B0h]@10
  char FileName[8 + 4*array_size_unknown]; // [sp+A20h] [bp-160h]@8
  char v151; // [sp+A28h] [bp-158h]@12
  char v152; // [sp+B1Ch] [bp-64h]@10
  char Str[32]; // [sp+B20h] [bp-60h]@1
  char *v154; // [sp+B40h] [bp-40h]@50
  __int64 v155; // [sp+B44h] [bp-3Ch]@55
  size_t ElementSize; // [sp+B4Ch] [bp-34h]@56
  int v157; // [sp+B50h] [bp-30h]@61
  cTexture *v158; // [sp+B54h] [bp-2Ch]@68

  struct maybe_odm_header
  {
   int v159; // [sp+B58h] [bp-28h]@50
   char v160; // [sp+B5Ch] [bp-24h]@50
   char v161; // [sp+B5Dh] [bp-23h]@50
   char v162; // [sp+B5Eh] [bp-22h]@50
   char v163; // [sp+B5Fh] [bp-21h]@50
   unsigned int v164; // [sp+B60h] [bp-20h]@50
   size_t Size; // [sp+B64h] [bp-1Ch]@50
  };
  struct maybe_odm_header v159;

  unsigned int v166; // [sp+B68h] [bp-18h]@13
  void *v167; // [sp+B6Ch] [bp-14h]@12
  unsigned int v168; // [sp+B70h] [bp-10h]@19
  char *Str2; // [sp+B74h] [bp-Ch]@12
  int v170; // [sp+B78h] [bp-8h]@59
  void *Src; // [sp+B7Ch] [bp-4h]@59
  int wtf;
 unsigned char *pTexturesNames;


 
 FILE    *hODMFile;
 
 int      j;

  v5 = (int)_this;
  strcpy(Str, Source);
  if ( byte_6BE3C4_MaybeDrowningFlag )
  {
    class35_obj.byte_267AD3 = 16;
    class35_obj.byte_267AD4 = -62;
    class35_obj.byte_267AD5 = -103;
    class35_obj.byte_267AD0 = 37;
    class35_obj.byte_267AD1 = -113;
    class35_obj.byte_267AD2 = 92;
    class35_sub_48A614(&class35_obj);
  }
  else
  {
   class35_obj.byte_267AD3 = 0;
   class35_obj.byte_267AD4 = 0;
   class35_obj.byte_267AD5 = 0;
   if ( class35_obj.byte_267AD0 != -128 || class35_obj.byte_267AD1 != -128 || class35_obj.byte_267AD2 != -128 )
   {
     class35_obj.byte_267AD0 = -128;
     class35_obj.byte_267AD1 = -128;
     class35_obj.byte_267AD2 = -128;
     class35_sub_48A614(&class35_obj);
   }
  }

  dword_6807E0 = 0;
  wsprintfA(FileName, "levels\\%s", Str);
  if ( _access(FileName, 4) != -1 )
  {
    result = fopen(FileName, "rb");
    v7 = result;
    File = (int)result;
    if ( !result )
      return result;
    *(_DWORD *)a5 = 1;
    v8 = strlen(Str);
    v120 = 2;
    *(&v152 + v8) = 0;
    struct_576FE8.uTextureID_LocationMap = LODFile_Icons_LOD.LODFile_LoadTexture( Str, v120);
    locked_fread(&DstBuf, 0x180u, 1u, v7);
    fseek(v7, Offset, 0);
    locked_fread(_this, 0xB0u, 1u, v7);
    class51_sub_47F420(_this);
    class51_sub_47F3EA(_this);
    strcpy((char *)_this->pGroundTileset, "grastyl");
    fseek(v7, v127, 0);
    locked_fread(&_this->uNumBModels, 4u, 1u, v7);
    fseek(v7, v128, 0);
    locked_fread(&uNumLayingItems, 4u, 1u, v7);
    fseek(v7, v129, 0);
    locked_fread(&uNumLevelDecorations, 4u, 1u, v7);
    fseek(v7, v130, 0);
    locked_fread(&uNumActors, 4u, 1u, v7);
    fseek(v7, v131, 0);
    locked_fread(&dword_5FF140, 4u, 1u, v7);
    class51_InitializeGeodata((class51_Geodata *)(v5 + 180));
    fseek(v7, v132, 0);
    locked_fread(*(void **)(v5 + 180), 1u, 0x4000u, v7);
    fseek(v7, v133, 0);
    locked_fread(*(void **)(v5 + 184), 1u, 0x4000u, v7);
    fseek(v7, v134, 0);
    locked_fread(*(void **)(v5 + 188), 1u, 0x4000u, v7);
    sub_47C80A((class51_Geodata *)(v5 + 180), 0, 0, 128, 128);
    mem_mng.DeleteBuffer( (void *)(void *)*(_DWORD *)(v5 + 212));
    *(_DWORD *)(v5 + 212) = 0;
    v9 = (int)mem_mng.AllocatedNamedBuffer( NULL, 32768, "CMAP");
    v120 = *(_DWORD *)(v5 + 228);
    *(_DWORD *)(v5 + 212) = v9;
    mem_mng.DeleteBuffer( (void *)(void *)v120);
    *(_DWORD *)(v5 + 228) = 0;
    v10 = (int)mem_mng.AllocatedNamedBuffer(NULL, 65536, "OMAP");
    v120 = 0;
    *(_DWORD *)(v5 + 228) = v10;
    fseek(v7, v149, v120);
    locked_fread(&uNumTerrainNormals, 4u, 1u, v7);
    locked_fread(&unk_73D514, 1u, 0x20000u, v7);
    locked_fread(uTerrainNormalIndices, 1u, 0x10000u, v7);
    pTerrainNormals = (Normal *)mem_mng.AllocatedNamedBuffer( pTerrainNormals, uNumTerrainNormals * sizeof(struct Normal), "TerNorm");
    locked_fread(pTerrainNormals, 1u, uNumTerrainNormals * sizeof(struct Normal), v7);
    v11 = (int)mem_mng.AllocatedNamedBuffer( (void*) *(_DWORD *)(v5 + 216), 188 * *(_DWORD *)(v5 + 176), "BDdata");
    v120 = 0;
    *(_DWORD *)(v5 + 216) = v11;
    fseek(v7, v135, v120);
    locked_fread(*(void **)(v5 + 216), 0xBCu, *(_DWORD *)(v5 + 176), v7);
    fseek(v7, v136, 0);
    a4 = 0;
    if ( *(_DWORD *)(v5 + 176) > 0 )
    {
      v12 = 0;
      while ( 1 )
      {
        *(_DWORD *)(*(_DWORD *)(v5 + 216) + v12 + 72) = 0;
        *(_DWORD *)(*(_DWORD *)(v5 + 216) + v12 + 84) = 0;
        *(_DWORD *)(*(_DWORD *)(v5 + 216) + v12 + 88) = 0;
        *(_DWORD *)(*(_DWORD *)(v5 + 216) + v12 + 96) = 0;
        FileName[0] = 0;
        v120 = v12 + *(_DWORD *)(v5 + 216);
        wsprintfA(FileName, "%s", v120);
        v14 = *(_DWORD *)(v5 + 216);
        v151 = 0;
        v120 = (int)FileName;
        *(_DWORD *)(*(_DWORD *)(v5 + 216) + v12 + 72) = (int)mem_mng.AllocatedNamedBuffer(
                                                         (void*) * (_DWORD *)(v12 + v14 + 72),
                                                          12 * *(_DWORD *)(v12 + v14 + 68),
                                                          FileName);
        *(_DWORD *)(*(_DWORD *)(v5 + 216) + v12 + 84) = (int)mem_mng.AllocatedNamedBuffer(
                                                          (void*) *(_DWORD *)(v12 + *(_DWORD *)(v5 + 216) + 84),
                                                          308 * *(_DWORD *)(v12 + *(_DWORD *)(v5 + 216) + 76),
                                                          FileName);
        v15 = v12 + *(_DWORD *)(v5 + 216);
        v120 = (int)FileName;
        *(_DWORD *)(*(_DWORD *)(v5 + 216) + v12 + 88) = (int)mem_mng.AllocatedNamedBuffer(
                                                          (void*) *(_DWORD *)(v15 + 88),
                                                          2 * *(_DWORD *)(v15 + 76),
                                                          FileName);
        v16 = v12 + *(_DWORD *)(v5 + 216);
        v120 = (int)FileName;
        v17 = (int)mem_mng.AllocatedNamedBuffer((void*) * (_DWORD *)(v16 + 96), 8 * *(_DWORD *)(v16 + 92), FileName);
        v18 = *(_DWORD *)(v5 + 216);
        v120 = File;
        *(_DWORD *)(v18 + v12 + 96) = v17;
        locked_fread(
          *(void **)(v12 + *(_DWORD *)(v5 + 216) + 72),
          0xCu,
          *(_DWORD *)(v12 + *(_DWORD *)(v5 + 216) + 68),
          (FILE *)v120);
        locked_fread(
          *(void **)(v12 + *(_DWORD *)(v5 + 216) + 84),
          0x134u,
          *(_DWORD *)(v12 + *(_DWORD *)(v5 + 216) + 76),
          (FILE *)File);
        locked_fread(
          *(void **)(v12 + *(_DWORD *)(v5 + 216) + 88),
          2,
          *(_DWORD *)(v12 + *(_DWORD *)(v5 + 216) + 76),
          (FILE *)File);
        locked_fread(
          *(void **)(v12 + *(_DWORD *)(v5 + 216) + 96),
          8u,
          *(_DWORD *)(v12 + *(_DWORD *)(v5 + 216) + 92),
          (FILE *)File);
        v19 = malloc(10 * *(_DWORD *)(*(_DWORD *)(v5 + 216) + v12 + 76));
        v119 = File;
        v20 = *(_DWORD *)(v5 + 216);
        v167 = v19;
        locked_fread(v19, 0xAu, *(_DWORD *)(v20 + v12 + 76), (FILE *)File);
        v13 = *(_DWORD *)(v5 + 216);
        Str2 = 0;
        if ( *(_DWORD *)(v13 + v12 + 76) > 0 )
          break;
LABEL_25:
        free(v167);
        ++a4;
        v12 += 188;
        if ( a4 >= *(_DWORD *)(v5 + 176) )
          goto LABEL_26;
      }
      v166 = 0;
      wtf = (int)v167;
      while ( 1 )
      {
        a5 = v166 + *(_DWORD *)(v13 + v12 + 84);
        if ( !(*(_BYTE *)(a5 + 29) & 0x40) )
          break;
        v21 = TextureFrameTable_sub_44E163(pTextureFrameTable, (char *)wtf);
        *(_WORD *)(a5 + 272) = v21;
        if ( !v21 )
        {
          v22 = LODFile_Bitmaps_LOD.LODFile_LoadTexture((char *)wtf, 0);
          v23 = a5;
          *(_BYTE *)(v23 + 29) &= 0xBFu;
LABEL_19:
          *(_WORD *)(v23 + 272) = v22;
          v168 = v22 != -1 ? 72 * v22 + 7278780 : 0;
          *(_WORD *)(v22 != -1 ? 72 * v22 + 7278780 + 0x26 : 38) = class35_sub_48A3BC_MessWithPalettes(
                                                                     &class35_obj,
                                                                     *(_WORD *)(v22 != -1 ? 72 * v22 + 7278780 + 0x24 : 36));
          goto LABEL_20;
        }
        TextureFrameTable_sub_44E0ED(pTextureFrameTable, *(_WORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 216) + v12 + 84) + v166 + 272));
LABEL_20:
        if ( *(_WORD *)(a5 + 292) )
        {
          if ( sub_44C1E8((class51_stru2 *)a5) )
            *(_BYTE *)(a5 + 30) |= 0x10u;
          else
            *(_BYTE *)(a5 + 30) &= 0xEFu;
        }
        ++Str2;
        v13 = *(_DWORD *)(v5 + 216);
        v166 += 308;
        wtf += 10;
        if ( (signed int)Str2 >= *(_DWORD *)(v13 + v12 + 76) )
          goto LABEL_25;
      }
      v22 = LODFile_Bitmaps_LOD.LODFile_LoadTexture((char *)wtf, 0);
      v23 = a5;
      goto LABEL_19;
    }
LABEL_26:
    v24 = (FILE *)File;
    fseek((FILE *)File, v137, 0);
    locked_fread(pLayingItemsList, 0x70u, uNumLayingItems, v24);
    if ( (signed int)uNumLayingItems > 0 )
    {
      v25 = (char *)pLayingItemsList;
      a4 = uNumLayingItems;
      do
      {
        v27 = *((_DWORD *)v25 + 9);
        a5 = 0;
        v26 = (FILE *)(48 * v27);
        v28 = pObjectDescriptionList->uNumObjects == 0;
        v29 = pObjectDescriptionList->uNumObjects < 0;
        LOWORD(v26) = *(_WORD *)((_DWORD)word_5D29F8 + (_DWORD)v26);
        File = (int)v26;
        *(_WORD *)v25 = (_WORD)v26;
        if ( v29 | v28 )
        {
LABEL_33:
          v31 = 0;
        }
        else
        {
          for ( i = (int)(pObjectDescriptionList->pDescriptions + 32); (_WORD)v26 != *(_WORD *)i; i = wtf )
          {
            ++a5;
            wtf = i + 56;
            if ( a5 >= pObjectDescriptionList->uNumObjects )
              goto LABEL_33;
            LOWORD(v26) = File;
          }
          v31 = a5;
        }
        *((_WORD *)v25 + 1) = v31;
        v25 = (char *)v25 + 112;
      }
      while ( a4-- != 1 );
    }
    fseek(v24, v138, 0);
    locked_fread(pLevelDecorations, sizeof(struct LevelDecoration), uNumLevelDecorations, v24);
    a4 = 0;
    if ( (signed int)uNumLevelDecorations > 0 )
    {
      a5 = (int)pLevelDecorations;
      do
      {
        locked_fread(&FileName, 1u, 0x20u, v24);
        v33 = sub_4488B6(pDecorationDescriptionList, FileName);
        v34 = a5;
        ++a4;
        a5 += 32;
        *(_WORD *)v34 = v33;
      }
      while ( a4 < (signed int)uNumLevelDecorations );
    }
    fseek(v24, v139, 0);
    locked_fread(pActors, 0x344u, uNumActors, v24);
    fseek(v24, v140, 0);
    locked_fread(array_5E5150, 0x14CCu, dword_5FF140, v24);
    fseek(v24, v141, 0);
    locked_fread((void *)(v5 + 220), 4u, 1u, v24);
    mem_mng.DeleteBuffer((void *)*(_DWORD *)(v5 + 224));
    v35 = *(_DWORD *)(v5 + 220);
    *(_DWORD *)(v5 + 224) = 0;
    v36 = (int)mem_mng.AllocatedNamedBuffer(NULL, 2 * v35, "IDLIST");
    v120 = (int)v24;
    *(_DWORD *)(v5 + 224) = v36;
    locked_fread((void *)v36, 2, *(_DWORD *)(v5 + 220), (FILE *)v120);
    fseek(v24, v142, 0);
    locked_fread(*(void **)(v5 + 228), 4u, 0x4000u, v24);
    fseek(v24, v143, 0);
    locked_fread((void *)(v5 + 1216), 4u, 1u, v24);
    *(_DWORD *)(v5 + 1220) = (int)mem_mng.AllocatedNamedBuffer( (void*) *(_DWORD *)(v5 + 1220), 24 * *(_DWORD *)(v5 + 1216), "Spawn");
    fseek(v24, v144, 0);
    locked_fread(*(void **)(v5 + 1220), 0x18u, *(_DWORD *)(v5 + 1216), v24);
    fseek(v24, v145, 0);
    locked_fread((void *)(v5 + 1224), 0x28u, 1u, v24);
    fseek(v24, v146, 0);
    locked_fread(&global_5E4C90, 1, sizeof(struct struct4), v24);
    fseek(v24, v147, 0);
    locked_fread((void *)(v5 + 1264), 1u, 0x38u, v24);
    fseek(v24, v148, 0);
    locked_fread((void *)(v5 + 1264), 1u, 4u, v24);
    CTileTable_LoadSomeTiles(pTileTable, 4);
    a5 = v5 + 160;
    CTileTable_LoadSomeTiles(pTileTable, *(_WORD *)(v5 + 160));
    CTileTable_LoadSomeTiles(pTileTable, *(_WORD *)(v5 + 164));
    CTileTable_LoadSomeTiles(pTileTable, *(_WORD *)(v5 + 168));
    CTileTable_LoadSomeTiles(pTileTable, *(_WORD *)(v5 + 172));
    if ( v5 != -96 && *(_BYTE *)(v5 + 96) )
    {
      v120 = 0;
      v119 = v5 + 96;
    }
    else
    {
      v120 = 0;
      v119 = (signed int)byte_6BE114_cfg_textures_DefaultSkyTexture;
    }
    _this->uSkyTextureID = LODFile_Bitmaps_LOD.LODFile_LoadTexture( (const char *)v119, 2);
    strcpy((char *)_this->pGroundTileset, byte_6BE124_cfg_textures_DefaultGroundTexture);
    v38 = (int)TileTable_GetTile(pTileTable, _this->array_0000A0[1]);

    _this->dword_0000EC = LODFile_Bitmaps_LOD.LODFile_LoadTexture( (const char *)v38, 2);
    if ( _this->uSkyTextureID != -1 )
      *(_WORD *)(_this->uSkyTextureID != -1 ? 72 * _this->uSkyTextureID + 0x6F10BC + 0x26 : 38) = class35_sub_48A3BC_MessWithPalettes(
                                                                 &class35_obj,
                                                                 *(_WORD *)(_this->uSkyTextureID != -1 ? 72 * _this->uSkyTextureID + 0x6F10BC + 0x24 : 36));
    v39 = _this->dword_0000EC;
    if ( v39 != -1 )
      *(_WORD *)(v39 != -1 ? 72 * v39 + 7278780 + 0x26 : 38) = class35_sub_48A3BC_MessWithPalettes(
                                                                 &class35_obj,
                                                                 *(_WORD *)(v39 != -1 ? 72 * v39 + 7278780 + 0x24 : 36));
    sub_47F0E2();
    LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
    fclose(v24);
    goto LABEL_150;
  }

  if (!LODFile_Games_LOD.IsContainerExist( Str))
    erroneous_printf("Unable to find %s in Games.LOD", Str);

  strcpy(FileName, Str);

  strcpy(Str1, Str);
  Str1[strlen(Str1) - 4] = 0;

#ifndef OLD_CODE
  wchar_t  pLevelMapFilename[256];
  wsprintfW(pLevelMapFilename, L"%S", Str1);
  struct_576FE8.uTextureID_LocationMap = LODFile_Icons_LOD.LODFile_LoadTexture_New( pLevelMapFilename);
#endif
#ifdef OLD_CODE
 
  struct_576FE8.uTextureID_LocationMap = LODFile_Icons_LOD.LODFile_LoadTexture( Str1,2);
#endif
  v154 = &v152;
  v40 = strlen(Str);
  strcpy(Str + v40 - 4, ".odm");
  hODMFile = LODFile_Games_LOD.Find_Container( Str, 1);

  v159.v159 = 91969;
  v159.v160 = 109;
  v159.v161 = 118;
  v159.v162 = 105;
  v159.v163 = 105;
  v159.v164 = 0;
  v159.Size = 0;

  locked_fread(&v159, 0x10, 1, hODMFile);
  if ( v159.v159 != 91969 || v159.v160 != 109 || v159.v161 != 118 || v159.v162 != 105 || v159.v163 != 105 )
  {
    wtf = (int)&v115;
    Game_sub_40E2C8(&v115, "Can't load file!", (int)((char *)&Source + 3));
    sub_466D09((char *)&v155 + 4, *(int *)&v115, v116, v117, (int)v118, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp", __LINE__);
  }
  v44 = v159.v164;
  ElementSize = v159.Size;
  v42 = (unsigned char *)malloc(v159.Size);

  HIDWORD(v155) = (int)v42;
  if ( v44 < ElementSize )
  {
    wtf = (int)malloc(v44);
    locked_fread((unsigned char *)wtf, v44, 1, hODMFile);
    MemUnzip(v42, &ElementSize, (unsigned char *)wtf, v44);
   // free((unsigned char *)wtf);	   crash lower	at label 69
  }
  else
  {
    locked_fread(v42, ElementSize, 1, hODMFile);
  }

  memcpy(_this, v42, 0xB0);
  v42 += 0xB0;

  class51_sub_47F420(_this);
  class51_sub_47F3EA(_this);

  strcpy((char *)_this->pGroundTileset, "grastyl");

  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  class51_InitializeGeodata(&_this->struct_0000B4);

  memcpy(_this->struct_0000B4.pHeightmap, v42, 128 * 128);
  v42 += 128 * 128;

  memcpy(_this->struct_0000B4.pTilemap, v42, 128 * 128);
  v42 += 128 * 128;

  memcpy(_this->struct_0000B4.pAttributemap, v42, 128 * 128);
  v42 += 128 * 128;

  mem_mng.DeleteBuffer( (void *)_this->ptr_0000D4);
  _this->ptr_0000D4 = (unsigned char *)mem_mng.AllocatedNamedBuffer( NULL, 0x8000, "CMAP");

  sub_47C80A(&_this->struct_0000B4, 0, 0, 128, 128);

  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  memcpy(&uNumTerrainNormals, v42, 4);
  v42 += 4;

  memcpy(unk_73D514, v42, 0x20000);
  v42 += 0x20000;

  memcpy(uTerrainNormalIndices, v42, 0x10000);
  v42 += 0x10000;

  pTerrainNormals = (Normal *)mem_mng.AllocatedNamedBuffer( pTerrainNormals, uNumTerrainNormals * sizeof(struct Normal), "TerNorm");
  memcpy(pTerrainNormals, v42, uNumTerrainNormals * sizeof(struct Normal));
  v42 += uNumTerrainNormals * sizeof(struct Normal);

  memcpy(&_this->uNumBModels, v42, 4);
  v42 += 4;

  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v48 = _this->uNumBModels;

  _this->pBModels = (class51_BModel *)mem_mng.AllocatedNamedBuffer( _this->pBModels, v48 * sizeof(struct class51_BModel), "ODM BModel data");
  memcpy(_this->pBModels, v42, v48 * sizeof(struct class51_BModel));
  Src = v42 + v48 * sizeof(struct class51_BModel);

  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);

  v170 = 0;
  if (_this->uNumBModels > 0)
  {
    v51 = 0;
   i = 0;
    while (true)
    {
      _this->pBModels[i].ptr_000048 = 0;
      _this->pBModels[i].ptr_000054 = 0;
      _this->pBModels[i].ptr_000058 = 0;
      _this->pBModels[i].ptr_000060 = 0;

      lstrcpyA(FileName, (const char *)(_this->pBModels[i].pModelName));
      v151 = 0;
      v120 = (int)FileName;

      v119 = 12 * _this->pBModels[i].dword_000044;
      _this->pBModels[i].ptr_000048 = (class51_stru3 *)mem_mng.AllocatedNamedBuffer( NULL, v119, FileName);
      memcpy(_this->pBModels[i].ptr_000048, Src, v119);
      Src = (char *)Src + v119;

      v119 = _this->pBModels[i].dword_00004C * sizeof(struct class51_stru2);
      _this->pBModels[i].ptr_000054 = (class51_stru2 *)mem_mng.AllocatedNamedBuffer( NULL, v119, FileName);
      memcpy(_this->pBModels[i].ptr_000054, Src, v119);
      Src = (char *)Src + v119;

      v119 = 2 * _this->pBModels[i].dword_00004C;
      _this->pBModels[i].ptr_000058 = (unsigned short *)mem_mng.AllocatedNamedBuffer( NULL, v119, FileName);
      memcpy(_this->pBModels[i].ptr_000058, Src, v119);
      Src = (char *)Src + v119;

      v119 = 8 * _this->pBModels[i].dword_00005C;
      _this->pBModels[i].ptr_000060 = (unsigned char *)mem_mng.AllocatedNamedBuffer( NULL, v119, FileName);
      memcpy(_this->pBModels[i].ptr_000060, Src, v119);
      Src = (char *)Src + v119;
	  
      pTexturesNames = (unsigned char *)malloc(10 * _this->pBModels[i].dword_00004C);
      v119 = 10 * _this->pBModels[i].dword_00004C;
      memcpy(pTexturesNames, Src, v119);
      Src = (char *)Src + v119;

      v157 = 0;
      v52 = (int)_this->pBModels;
      if (_this->pBModels[i].dword_00004C > 0 )
        break;

LABEL_74:
      free(pTexturesNames);
      ++v170;
      v51 += 188;
      ++i;
      if ( v170 >= _this->uNumBModels)
        goto LABEL_75;
    }


    v168 = 0;
    Str2 = (char *)pTexturesNames;
    j = 0;
    while ( 1 )
    {
      v66 = &_this->pBModels[i].ptr_000054[j];
      if ( !(v66->byte_000010[13] & 0x40) )
        break;

      v64 = TextureFrameTable_sub_44E163(pTextureFrameTable, Str2);
      v66->uTextureID = v64;
      if ( !v64 )
      {
        v65 = LODFile_Bitmaps_LOD.LODFile_LoadTexture( Str2, 0);

        *(_BYTE *)(v66 + 29) &= 0xBFu;
        *(_WORD *)(v66 + 272) = v65;
        v158 = (cTexture *)(v65 != -1 ? 72 * v65 + 7278780 : 0);
        v120 = *(_WORD *)(v65 != -1 ? 72 * v65 + 7278780 + 0x24 : 36);
        *(_WORD *)(v65 != -1 ? 72 * v65 + 7278780 + 0x26 : 38) = class35_sub_48A3BC_MessWithPalettes(&class35_obj, v120);
        goto LABEL_69;
      }
      v120 = _this->pBModels[v51 / 188].ptr_000054[v168 / 308].uTextureID;
      TextureFrameTable_sub_44E0ED(pTextureFrameTable, v120);
LABEL_69:
      if ( *(_WORD *)(wtf + 292) )
      {
        if ( sub_44C1E8((class51_stru2 *)wtf) )
          *(_BYTE *)(wtf + 30) |= 0x10u;
        else
          *(_BYTE *)(wtf + 30) &= 0xEFu;
      }
      ++v157;
      v52 = (int)_this->pBModels;
      v168 += 308;
      ++j;
      Str2 += 10;
      if ( v157 >= _this->pBModels[i].dword_00004C)
        goto LABEL_74;
    }

#ifndef OLD_CODE
	wchar_t  pFilename[256];
    wsprintfW(pFilename, L"%S", Str2);
    v66->uTextureID = LODFile_Bitmaps_LOD.LODFile_LoadTexture_New( pFilename);
#endif
#ifdef OLD_CODE
    v66->uTextureID = LODFile_Bitmaps_LOD.LODFile_LoadTexture(Str2,2);
#endif

    if (v66->uTextureID != -1)
    {
     v158 = &LODFile_Bitmaps_LOD.aLODHeaders[v66->uTextureID];
     v158->word_000026 = class35_sub_48A3BC_MessWithPalettes(&class35_obj, v158->word_000024);
    }
    goto LABEL_69;
  }

LABEL_75:
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  memcpy(&uNumLevelDecorations, Src, 4);
  Src = (char *)Src + 4;
  if ( (signed int)uNumLevelDecorations < 0 || (signed int)uNumLevelDecorations > 3000 )
  {
    wtf = (int)&v115;
    Game_sub_40E2C8(&v115, "Can't load file!", (int)((char *)&Source + 3));
    sub_466D09(&v167, *(int *)&v115, v116, v117, (int)v118, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp", __LINE__);
  }

  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);



 memcpy(pLevelDecorations, Src, uNumLevelDecorations * sizeof(struct LevelDecoration));
 Src = (char *)Src + uNumLevelDecorations * sizeof(struct LevelDecoration);

 for (i = 0; i < uNumLevelDecorations; ++i)
 {
  memcpy(FileName, Src, 32);
  Src = (char *)Src + 32;

  pLevelDecorations[i].uDecorationDescriptionID = sub_4488B6(pDecorationDescriptionList, FileName);
 }
 LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);



 memcpy(&_this->dword_0000DC, Src, 4);
 Src = (char *)Src + 4;

 v120 = (int)_this->ptr_0000E0;
 v69 = _this->dword_0000DC;

 mem_mng.DeleteBuffer( (void *)_this->ptr_0000E0);
 _this->ptr_0000E0 = (unsigned short *)mem_mng.AllocatedNamedBuffer( NULL, v69 * sizeof(short), "IDLIST");
 memcpy(_this->ptr_0000E0, Src, 2 * v69);
 Src = (char *)Src + 2 * v69;

 LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);



 mem_mng.DeleteBuffer( (void *)_this->ptr_0000E4);
 _this->ptr_0000E4 = (unsigned int *)mem_mng.AllocatedNamedBuffer( NULL, 128 * 128 * sizeof(int), "OMAP");
 memcpy(_this->ptr_0000E4, Src, 128 * 128 * 4);
 Src = (char *)Src + 65536;
 LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);



 memcpy(&_this->dword_0004C0, Src, 4);
 Src = (char *)Src + 4;
 LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);



 v73 = _this->dword_0004C0;
 _this->ptr_0004C4 = (unsigned char *)mem_mng.AllocatedNamedBuffer( NULL, 24 * v73, "Spawn");
 memcpy(_this->ptr_0004C4, Src, 24 * v73);
 LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);






 free((unsigned char *)HIDWORD(v155));
 v77 = strlen(Str);
 strcpy(Str + v77 - 4, ".ddm");
 //hODMFile = LODFile_FindContainer(pLODFile_New_LOD, Str, 1);
 hODMFile = LODFile_Games_LOD.Find_Container( Str, 1);
 locked_fread(&v159, 0x10u, 1, hODMFile);
 Str2 = 0;
 if ( v159.v159 != 91969 || v159.v160 != 109 || v159.v161 != 118 || v159.v162 != 105 || v159.v163 != 105 )
 {
    wtf = (int)&v115;
    Game_sub_40E2C8(&v115, "Can't load file!", (int)((char *)&Source + 3));
    sub_466D09((char *)&v155 + 4, *(int *)&v115, v116, v117, (int)v118, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp", __LINE__);
    Str2 = (char *)1;
 }
  v78 = 0;
  wtf = v159.v164;
  v168 = 0;
  v166 = v159.Size;
  if ( !Str2 )
  {
    v79 = (int)malloc(v159.Size);
    v168 = v79;
    if ( wtf <= v166 )
    {
      if ( wtf == v166 )
      {
        locked_fread((void *)v79, v166, 1u, hODMFile);
      }
      else
      {
        Src = malloc(wtf);
        locked_fread(Src, wtf, 1u, hODMFile);
        MemUnzip((unsigned char *)v79, &v166, Src, wtf);
        free(Src);
      }
    }
    else
    {
      wtf = (int)&v115;
      Game_sub_40E2C8(&v115, "Can't load file!", (int)((char *)&Source + 3));
      sub_466D09((char *)&v155 + 4, *(int *)&v115, v116, v117, (int)v118, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp", __LINE__);
    }
    memcpy(_this->array_0004C8, (const void *)v79, 0x28u);
    v78 = v79 + 40;
  }

  v82 = 0;
  for (i = 0; i < _this->uNumBModels; ++i)
    v82 += _this->pBModels[i].dword_00004C;

  v84 = _this->array_0004C8[4];
  if ( v84 )
  {
    if (_this->array_0004C8[6])
    {
      v85 = _this->array_0004C8[5];
      if ( v85 )
      {
        if ( v84 != v82 || _this->array_0004C8[6] != _this->uNumBModels || v85 != uNumLevelDecorations )
          Str2 = (char *)1;
      }
    }
  }
  if ( BYTE1(dword_6BE364) & 0x20 )
    a4 = 29030400;

  if ( Str2 )
  {
    memset(v122, 0, 0x3C8u);
    v87 = (int)memset(v121, 0, 0x3C8u);
    goto LABEL_112;
  }

  v86 = _this->array_0004C8[1];
  if ( File - v86 >= (unsigned int)a4 || !v86 )
  {
    memcpy(v122, (const void *)v78, 0x3C8);
    v87 = (int)memcpy(v121, (const void *)(v78 + 0x3C8), 0x3C8);

LABEL_112:
    free((unsigned char *)v168);

    _this->array_0004C8[1] = File;
    if (!Str2)
      ++_this->array_0004C8[0];
    v120 = 0;

    *(_DWORD *)a5 = 1;
    hODMFile = LODFile_Games_LOD.Find_Container( Str, v120);
    locked_fread(&v159, 0x10, 1, hODMFile);
    wtf = v159.v164;
    v166 = v159.Size;
    v89 = (int)malloc(v159.Size);
    v168 = v89;
    if ( wtf <= v166 )
    {
      if ( wtf == v166 )
      {
        locked_fread((void *)v89, v166, 1, hODMFile);
      }
      else
      {
        Src = malloc(wtf);
        locked_fread(Src, wtf, 1, hODMFile);
        MemUnzip((char *)v89, &v166, Src, wtf);
        free(Src);
      }
    }
    else
    {
      a4 = (signed int)&v115;
      Game_sub_40E2C8(&v115, "Can't load file!", (int)((char *)&a4 + 3));
      sub_466D09(&File, *(int *)&v115, v116, v117, (int)v118, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp", __LINE__);
    }
    v78 = v89 + 40;
    goto LABEL_120;
  }

  *(_DWORD *)a5 = 0;

LABEL_120:
  v92 = strlen(Str);
  strcpy(Str + v92 - 4, ".odm");
  memcpy(_this->array_000528, (char *)v78, 0x3C8);

  memcpy(_this->array_0008F0, (char *)v78 + 0x3C8, 0x3C8);
  v78 = (int)((char *)v78 + 0x3C8 + 0x3C8);
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);



  if ( *(_DWORD *)a5 )
  {
    memcpy(_this->array_000528, v122, 0x3C8);
    memcpy(_this->array_0008F0, v121, 0x3C8);
  }

  for (i = 0; i < _this->uNumBModels; ++i)
  {

      for (j = 0; j < _this->pBModels[i].dword_00004C; ++j)
      {
        v118 = (void *)(_this->pBModels[i].ptr_000054[j].byte_000010 + 12);
        memcpy(v118, (char *)v78, 4);
        v78 = (int)((char *)v78 + 4);
      }

      for (j = 0; j < _this->pBModels[i].dword_00004C; ++j)
      {
          if (_this->pBModels[i].ptr_000054[j].word_000124)
          {
            if ( sub_44C1E8(&_this->pBModels[i].ptr_000054[j]) )
              _this->pBModels[i].ptr_000054[j].byte_000010[14] |= 0x10u;
            else
              _this->pBModels[i].ptr_000054[j].byte_000010[14] &= 0xEFu;
          }

      }
  }
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);



  for (i = 0; i < uNumLevelDecorations; ++i)
  {
      memcpy(&pLevelDecorations[i].word_000002, (char *)v78, 2);
      v78 = (int)((char *)v78 + 2);
  }
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);



  memcpy(&uNumActors, (char *)v78, 4);
  v78 = (int)((char *)v78 + 4);
  if ( (signed int)uNumActors < 0 || uNumActors > 500 )
  {
    a5 = (int)&v115;
    Game_sub_40E2C8(&v115, "Can't load file!", (int)((char *)&a5 + 3));
    sub_466D09(&a4, *(int *)&v115, v116, v117, (int)v118, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp", __LINE__);
  }
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);



  memcpy(pActors, (char *)v78, uNumActors * sizeof(struct Actor));
  v78 = (int)((char *)v78 + uNumActors * sizeof(struct Actor));
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);



  memcpy(&uNumLayingItems, (char *)v78, 4);
  v78 = (int)((char *)v78 + 4);
  if ( (signed int)uNumLayingItems < 0 || uNumLayingItems > 1000 )
  {
    a5 = (int)&v115;
    Game_sub_40E2C8(&v115, "Can't load file!", (int)((char *)&a5 + 3));
    sub_466D09(&a4, *(int *)&v115, v116, v117, (int)v118, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp", __LINE__);
  }
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);



  memcpy(pLayingItemsList, (char *)v78, uNumLayingItems * sizeof(struct LayingItem));
  v78 = (int)((char *)v78 + uNumLayingItems * sizeof(struct LayingItem));
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);



  memcpy(&dword_5FF140, (char *)v78, 4);
  v78 = (int)((char *)v78 + 4);
  if ( (signed int)dword_5FF140 < 0 || (signed int)dword_5FF140 > 20 )
  {
    a5 = (int)&v115;
    Game_sub_40E2C8(&v115, "Can't load file!", (int)((char *)&a5 + 3));
    sub_466D09(&a4, *(int *)&v115, v116, v117, (int)v118, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp", __LINE__);
  }
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);



  memcpy(array_5E5150, (char *)v78, dword_5FF140 * sizeof(struct struct3));
  v78 = (int)((char *)v78 + dword_5FF140 * sizeof(struct struct3));
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);



  memcpy(&global_5E4C90, (char *)v78, sizeof(struct struct4));
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);



  memcpy(_this->array_0004F0, (char *)v78 + 200, 0x38);
  free((char *)v168);
  CTileTable_LoadSomeTiles(pTileTable, 4);
  CTileTable_LoadSomeTiles(pTileTable, _this->array_0000A0[0]);
  CTileTable_LoadSomeTiles(pTileTable, _this->array_0000A0[2]);
  CTileTable_LoadSomeTiles(pTileTable, _this->array_0000A0[4]);
  CTileTable_LoadSomeTiles(pTileTable, _this->array_0000A0[6]);

  strcpy((char *)_this->pGroundTileset, byte_6BE124_cfg_textures_DefaultGroundTexture);
  v109 = _this->array_0000A0[1];
  v120 = 0;
  v110 = TileTable_GetTile(pTileTable, _this->array_0000A0[1]);
  {

#ifndef OLD_CODE
   wchar_t pTmp[256];
   wsprintfW(pTmp, L"%S", v110->sTileName);

   v106 = LODFile_Bitmaps_LOD.LODFile_LoadTexture_New( pTmp);
#endif
#ifdef OLD_CODE
   v106 = LODFile_Bitmaps_LOD.LODFile_LoadTexture((const char*) &v110->sTileName,2);
#endif

  }
  _this->dword_0000EC = v106;
  if ( v106 != -1 )
    LODFile_Bitmaps_LOD.aLODHeaders[v106].word_000026 = class35_sub_48A3BC_MessWithPalettes(&class35_obj, LODFile_Bitmaps_LOD.aLODHeaders[v106].word_000024);

  sub_47F0E2();

LABEL_150:
  v111 = _this->array_0004F0[1];
  LODWORD(v155) = _this->array_0004F0[0];
  HIDWORD(v155) = _this->array_0004F0[1];
  if ( v111 | (_DWORD)v155 )
  {
    v120 = 28;
    if ( (signed int)((signed int)(signed __int64)((double)v155 * 0.234375) / 60 / 60 / 0x18u) % 28 != pParty_global->uDaysPlayed )
    {
      if ( rand() % 100 >= 20 )
        v120 = dword_4EC268[rand() % dword_4EC2A8];
      else
        v120 = dword_4EC28C[rand() % dword_4EC2AC];
      wsprintfA((char *)&_this->array_0004F0[2], "plansky%d", v120);
    }
  }
  else
  {
    strcpy((char *)&_this->array_0004F0[2], "plansky3");
  }

  {

#ifndef OLD_CODE
   wchar_t pSkyFilename[256];

   wsprintfW(pSkyFilename, L"%S", &_this->array_0004F0[2]);
   _this->uSkyTextureID = LODFile_Bitmaps_LOD.LODFile_LoadTexture_New( pSkyFilename);
#endif
  #ifdef OLD_CODE
  
   _this->uSkyTextureID = LODFile_Bitmaps_LOD.LODFile_LoadTexture((const char*)&_this->array_0004F0[2],2);
#endif
  }

  v158 = &LODFile_Bitmaps_LOD.aLODHeaders[_this->uSkyTextureID];
  v120 = v158->word_000024;
  v158->word_000026 = class35_sub_48A3BC_MessWithPalettes(&class35_obj, v158->word_000024);
																		 
  class35_sub_48A614(&class35_obj);
  sub_4A9A67(pSoundList, 53, 0);
  sub_4A9A67(pSoundList, 92, 0);
  sub_4A9A67(pSoundList, 57, 0);
  sub_4A9A67(pSoundList, 96, 0);
  sub_4A9A67(pSoundList, 64, 0);
  sub_4A9A67(pSoundList, 103, 0);
  v113 = (int)_this->array_0000A0;
  a5 = 3;
  do
  {
    if ( *(_WORD *)v113 )
    {
      switch ( *(_WORD *)v113 )
      {
        case 1:
          sub_4A9A67(pSoundList, 58, 0);
          v120 = 0;
          v119 = 97;
          break;
        case 2:
          sub_4A9A67(pSoundList, 52, 0);
          v120 = 0;
          v119 = 91;
          break;
        case 3:
          sub_4A9A67(pSoundList, 51, 0);
          v120 = 0;
          v119 = 90;
          break;
        case 5:
          sub_4A9A67(pSoundList, 62, 0);
          v120 = 0;
          v119 = 101;
          break;
        case 6:
          sub_4A9A67(pSoundList, 49, 0);
          v120 = 0;
          v119 = 88;
          break;
        default:
          if ( *(_WORD *)v113 != 7 )
            goto LABEL_175;
          sub_4A9A67(pSoundList, 61, 0);
          v120 = 0;
          v119 = 100;
          break;
      }
    }
    else
    {
      sub_4A9A67(pSoundList, 54, 0);
      v120 = 0;
      v119 = 93;
    }

    runtime_warning(sound loading error);
    sub_4A9A67(pSoundList, v119, v120);

LABEL_175:
    v113 += 4;
  }
  while ( a5-- != 1 );
 return true;
}




//----- (00460706) --------------------------------------------------------
bool __cdecl TryLoadLevelFromFile()
{
  FILE *v1; // esi@1
  __int32 v2; // edi@2
  char Ext[256]; // [sp+4h] [bp-40Ch]@1
  char Dir[256]; // [sp+104h] [bp-30Ch]@1
  char Filename[256]; // [sp+204h] [bp-20Ch]@1
  char FullPath[260]; // [sp+304h] [bp-10Ch]@1
  char Drive[4]; // [sp+408h] [bp-8h]@1
  int DstBuf; // [sp+40Ch] [bp-4h]@2
 void *f;

 strcpy(FullPath, CurrentLevelName);
 _splitpath(FullPath, Drive, Dir, Filename, Ext);
 wsprintfA(FullPath, "levels\\%s%s", Filename, ".lod");

 //no files outside LODs in release version, so skip

 //v1 = fopen(FullPath, "rb");
 f = CreateFileA(FullPath, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
  /*if (v1)
  {
    fseek(v1, 0, 2);
    v2 = ftell(v1);
    rewind(v1);
    dword_6A0D08 = mem_mng.AllocatedNamedBuffer( dword_6A0D08, v2, "LevelLod");
    locked_fread(dword_6A0D08, v2, 1u, v1);
    fseek(v1, v2 - 6, 0);
    DstBuf = 0;
    locked_fread(&DstBuf, 4u, 1u, v1);
    locked_fread(&unk_6A0D10, 2, 1u, v1);
    dword_6A0D0C = DstBuf + dword_6A0D08;
    fclose(v1);
  }*/
 if (f != INVALID_HANDLE_VALUE)
 {
  CloseHandle(f);
 }

 return false;
}



//----- (0047F420) --------------------------------------------------------
bool class51_sub_47F420(struct class51 *_this)
{
 int i;
 for (i = 0; i < 6; i += 2)
   _this->array_0000A0[i + 1] = sub_487ED6(pTileTable, _this->array_0000A0[i], 1);

 return true;
}


//----- (0047F3EA) --------------------------------------------------------
bool class51_sub_47F3EA(struct class51 *_this)
{
 _this->array_0000A0[7] = sub_487ED6(pTileTable, _this->array_0000A0[6], 1);
 CTileTable_LoadSomeTiles(pTileTable, _this->array_0000A0[6]);

 return true;
}



//----- (0047CD44) --------------------------------------------------------
bool class51_InitializeGeodata(struct class51_Geodata *_this)
{
 _this->pHeightmap = (unsigned char *)mem_mng.AllocatedNamedBuffer( _this->pHeightmap, 128 * 128, "ODM Heightmap");
 _this->pTilemap = (unsigned char *)mem_mng.AllocatedNamedBuffer( _this->pTilemap, 128 * 128, "ODM Tilemap");
 _this->pAttributemap = (unsigned char *)mem_mng.AllocatedNamedBuffer( _this->pAttributemap, 128 * 128, "ODM Attributes map");
 _this->ptr_00000C = (unsigned char *)mem_mng.AllocatedNamedBuffer( _this->ptr_00000C, 128 * 128 * 2, "DMAP");

 if (_this->pHeightmap && _this->pTilemap && _this->pAttributemap && _this->ptr_00000C)
   return true;
 else return false;
}

//----- (0047C7C2) --------------------------------------------------------
void class51_FreeGeodata(struct class51_Geodata *_this)
{
 mem_mng.DeleteBuffer( (void *)_this->pHeightmap);
 _this->pHeightmap = 0;

 mem_mng.DeleteBuffer( (void *)_this->pTilemap);
 _this->pTilemap = 0;

 mem_mng.DeleteBuffer( (void *)_this->pAttributemap);
 _this->pAttributemap = 0;

 mem_mng.DeleteBuffer( (void *)_this->ptr_00000C);
 _this->ptr_00000C = 0;

 _this->word_000010 = 0;
 _this->word_000012 = 0;
 _this->word_000014 = 0;
 _this->word_000016 = 0;

 _this->dword_000018 = 0;
 _this->dword_00001C = 0;
}



//----- (0047C80A) --------------------------------------------------------
void sub_47C80A(struct class51_Geodata *_this, int sX, int sY, int sZ, int sW)
{
  int v1;
  void *v5; // ebx@1
  double v6; // st7@1
  double v7; // st7@2
  double v8; // st7@2
  int v10; // eax@4
  int v12; // ecx@6
  int v16; // edi@15
  int v17; // esi@15
  double v18; // st7@15
  int v22; // edx@15
  int v23; // ecx@15
  int v25; // ecx@15
  int v26; // ST28_4@15
  double v27; // st7@15
  double v28; // st6@15
  double v29; // st5@15
  double v30; // st7@16
  double v31; // st7@17
  double v32; // st7@21
  int v33; // eax@21
  double v34; // st7@21
  double v35; // st6@21
  double v36; // st5@21
  double v37; // st7@22
  double v38; // st7@23
  int v40; // [sp+18h] [bp-30h]@15
  int v42; // [sp+20h] [bp-28h]@15
  float v45; // [sp+2Ch] [bp-1Ch]@1
  float v46; // [sp+30h] [bp-18h]@1
  float v47; // [sp+34h] [bp-14h]@1
 int x, y;
  
  v45 = 64.0;
  v46 = -64.0;
  v47 = -64.0;

  v5 = _this;

  v6 = sqrt(12288.0);
  if ( v6 != 0.0 )
  {
    v7 = 1.0 / v6;
    v45 = 64.0 * v7;
    v8 = -64.0 * v7;
    v46 = v8;
    v47 = v8;
  }

 if (sY > sW)
 {
  v10 = sY;
  sY = sW;
  sW = v10;
 }

 if (sX > sZ)
 {
  v12 = sX;
  sX = sZ;
  sZ = v12;
 }
 
 for (y = sY - 1; y <= sW; ++y)
 {
  for (x = sX - 1; x <= sZ; ++x)
  {
   if (y >= 0 && y <= 127 &&
       x >= 0 && x <= 127)
   {
    v1 = (sX - 64 + x + 1) * 512;

                  v17 = (64 - y) * 512;
                  v16 = 32 * _this->pHeightmap[y * _this->word_000010 + x];
                  v22 = 32 * _this->pHeightmap[y * _this->word_000010 + x + 1];
                  v23 = (63 - y) * 512;

                  v25 = v23 - v17;

                  v40 = 32 * _this->pHeightmap[(y + 1) * _this->word_000010 + x];
                  v42 = 32 * _this->pHeightmap[(y + 1) * _this->word_000010 + x + 1];

                  v26 = v1 - 512 - v1;

                  v27 = (double)-((v16 - v22) * v25);
                  v28 = (double)-(v26 * (v42 - v22));
                  v29 = (double)(v26 * v25);
                  v18 = sqrt(v29 * v29 + v28 * v28 + v27 * v27);
                  if ( v18 != 0.0 )
                  {
                    v30 = 1.0 / v18;
                    v27 = v27 * v30;
                    v28 = v28 * v30;
                    v29 = v29 * v30;
                  }
                  v31 = (v29 * v47 + v28 * v46 + v27 * v45) * 31.0;
                  if (v31 < 0.0)
                    v31 = 0.0;
                  else if (v31 > 31.0)
                    v31 = 31.0;

                  _this->ptr_00000C[2 * (x + y * _this->word_000010) + 1] = v31;

                  v33 = v1 - (v1 - 512);
                  v34 = (double)-((v42 - v40) * (v17 - v23));
                  v35 = (double)-(v33 * (v16 - v40));
                  v36 = (double)(v33 * (v17 - v23));
                  v32 = sqrt(v36 * v36 + v35 * v35 + v34 * v34);
                  if ( v32 != 0.0 )
                  {
                    v37 = 1.0 / v32;
                    v34 = v34 * v37;
                    v35 = v35 * v37;
                    v36 = v36 * v37;
                  }
                  v38 = (v36 * v47 + v35 * v46 + v34 * v45) * 31.0;

                  if (v38 < 0.0)
                    v38 = 0.0;
                  else if (v38 > 31.0)
                    v38 = 31.0;
                  _this->ptr_00000C[2 * (x + y * _this->word_000010)] = v38;
    }
  }
 }
}



//----- (0044C1E8) --------------------------------------------------------
bool sub_44C1E8(struct class51_stru2 *_this)
{
 int i;

 for (i = 0; i < uLevelEVT_NumEvents; ++i)
   if (pLevelEVT_Events[i].dword_000000 == _this->word_000124)
   {
    if (pLevelEVT[pLevelEVT_Events[i].uEventOffsetInEVT + 4] != 4 ||
        pLevelEVT[pLevelEVT_Events[i + 1].uEventOffsetInEVT + 4] != 1)
      return false;
    else return true;
   }
 return false;
}



//----- (00488F5C) ------.text:0048A961 --------------------------------------------------
bool LoadLevel(struct class51 *_this, const char *Source, int File, signed int a4, int a5)
{
  if ( Source )
  {
    class51_sub_47CF9C(_this);
    LODFile_Bitmaps_LOD.sub_46454B();
    LODFile_Sprites_LOD.sub_4645DC();
    SpriteFrameTable_fn3(pSpriteFrameTable);
    LODFile_Icons_LOD.sub_46454B();
    sub_46080D();
    TryLoadLevelFromFile();
    if ( !LoadLevelFromODM(_this, Source, File, a4, a5) )
    {
      MessageBoxA(0, "Error!", "Couldn't Load Map!", 0);
      class51_sub_47CDE2((int)_this);
    }
    dword_6BE030 = _this->array_0004F0[5];
    dword_6BE040 = _this->array_0004F0[6];
    dword_6BE044 = _this->array_0004F0[7];
    if ( sub_464839() )
      sub_464851();
    dword_6BE134 = _this->array_0000A0[0];
    return true;
  }
  else return false;
}



//----- (0047F223) --------------------------------------------------------
int sub_47F223_LooksLikeGenerateMonsterLoot(struct class51 *_this)
{
  signed int v1; // ebx@1
  int v2; // esi@2
  int v3; // eax@7
  void *v5; // [sp+0h] [bp-4h]@1

  v5 = _this;
  v1 = 0;
  if ( (signed int)uNumLayingItems > 0 )
  {
   v2 = (int)&pLayingItemsList[0].uObjectDescriptionID;
    do
    {
      if ( *(_WORD *)v2 )
      {
        if ( !(*(_BYTE *)(v2 + 24) & 8) )
        {
          if ( !(*(_BYTE *)(56 * *(_WORD *)v2 + pObjectDescriptionList->pDescriptions + 38) & 0x10) )
            *(_DWORD *)(v2 + 10) = sub_48257A(*(_DWORD *)(v2 + 2), *(_DWORD *)(v2 + 6), (int)&v5, 0);
        }
        v3 = *(_DWORD *)(v2 + 34);
        if ( v3 )
        {
          if ( v3 != 220 )
          {
           if (pClass40->pItems[v3 - 1].uEquipType == 14 )
            {
              if ( !*(_DWORD *)(v2 + 38) )
                *(_DWORD *)(v2 + 38) = rand() % 15 + 5;
            }
          }
          class40_sub_456D17(pClass40, (ItemGen *)(v2 + 34));
        }
      }
      ++v1;
      v2 += 112;
    }
    while ( v1 < (signed int)uNumLayingItems );
  }
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  return 1;
}



//----- (004892E6) --------------------------------------------------------
int __thiscall class51_sub_4892E6(struct class51 *_this)
{
  int result; // eax@1
  void *v2; // esi@1
  int v3; // edi@3
  int v4; // ebx@3
  int v5; // eax@3
  int v6; // eax@3
  double v8; // st7@4

  result = pParty_global->uCurrentHour;
  v2 = _this;
  if ( (unsigned int)pParty_global->uCurrentHour >= 5 )
  {
    if ( (unsigned int)pParty_global->uCurrentHour < 0x15 )
    {
      v3 = pParty_global->uCurrentMinute + 60 * (pParty_global->uCurrentHour - 5);
      v4 = v3 * pClass59_global->uIntegerPi / 960;
      v5 = class59_SinCos(pClass59_global, v3 * pClass59_global->uIntegerPi / 960);
      _this->dword_000D18 = v5;
      _this->dword_000D1C = 0;
      v6 = class59_SinCos(pClass59_global, v4 - pClass59_global->uIntegerHalfPi);
      _this->dword_000D20 = v6;
      _this->dword_000D30 = -v5;
      _this->dword_000D34 = -_this->dword_000D1C;
      _this->dword_000D38 = -v6;
      if ( v3 >= 480 )
        v8 = (double)(960 - v3);
      else
        v8 = (double)v3;
      _this->dword_000CBC = (signed __int64)(20.0
                                             - v8 * (1.0 / 480.0) * 20.0);
      result = pParty_global->uCurrentMinute;
      _this->dword_01C288 = pParty_global->uCurrentMinute;
    }
  }
  return result;
}


//----- (00482170) --------------------------------------------------------
bool sub_482170(struct class51_stru2 *_this, struct RenderVertex *a2, struct struct8 *a3)
{
  signed int v3; // edx@1
  struct RenderVertex *v6; // ecx@2
  double v7; // st7@5
  double v8; // st6@5
  double v9; // st5@5
  double v10; // st6@9
  double v11; // st5@9
  double v12; // st4@9
  float v18; // [sp+8h] [bp-38h]@5
  float v19; // [sp+10h] [bp-30h]@5
  float v20; // [sp+14h] [bp-2Ch]@5
  float v21; // [sp+18h] [bp-28h]@5
  float v22; // [sp+1Ch] [bp-24h]@5
  float v23; // [sp+24h] [bp-1Ch]@5
  float v24; // [sp+28h] [bp-18h]@5
  float v25; // [sp+30h] [bp-10h]@5
  float v26; // [sp+34h] [bp-Ch]@5
  float v27; // [sp+38h] [bp-8h]@5
  float v28; // [sp+3Ch] [bp-4h]@5
  float v29; // [sp+48h] [bp+8h]@5
  float v30; // [sp+48h] [bp+8h]@17
  float v31; // [sp+48h] [bp+8h]@17
  float v32; // [sp+48h] [bp+8h]@17
  float v33; // [sp+48h] [bp+8h]@17

 v3 = a3->uNumVertices;
 if (a3->uNumVertices < 3)
   return false;

  v6 = &a2[v3 - 1];
  if (a2[0].y == a2[1].y)
  {
    if (a2[1].y == a2[v3 - 1].y)
      a3->word_000030 |= 0x10;
  }

  v19 = a2[1].flt_00000C - a2->flt_00000C;
  v18 = a2[1].flt_000010 - a2->flt_000010;
  v20 = a2[1].flt_000014 - a2->flt_000014;
  v21 = a2[v3 - 1].flt_00000C - a2->flt_00000C;
  v22 = a2[v3 - 1].flt_000010 - a2->flt_000010;
  v23 = a2[v3 - 1].flt_000014 - a2->flt_000014;
  v28 = a2[1].x - a2->x;
  v27 = a2[1].z - a2->z;
  v29 = a2[1].y - a2->y;
  v7 = a2[v3 - 1].x - a2->x;
  v8 = a2[v3 - 1].z - a2->z;
  v9 = a2[v3 - 1].y - a2->y;

 v26 = v27 * v9 - v8 * v29;
 v24 = v7 * v29 - v9 * v28;
 v25 = v8 * v28 - v7 * v27;
 if (v26 + v24 + v25 == 0.0)
 {
  while (true)
  {
   if (--v3 < 2)
     break;

   v10 = v6->x - a2->x;
   v11 = v6->z - a2->z;
   v12 = v6->y - a2->y;

   v26 = v27 * v12 - v11 * v29;
   v24 = v10 * v29 - v12 * v28;
   v25 = v11 * v28 - v10 * v27;
   if (v26 != 0.0 || v24 != 0.0 || v25 != 0.0)
     break;
   --v6;
  }
  v21 = v6->flt_00000C - a2->flt_00000C;
  v22 = v6->flt_000010 - a2->flt_000010;
  v23 = v6->flt_000014 - a2->flt_000014;
 }

 if ((pOldCamera->dword_000000 - a2->x) * v26 +
     (pOldCamera->dword_000008 - a2->y) * v25 +
     (pOldCamera->dword_000004 - a2->z) * v24 > 0.0)
 {
  v30 = v23 * v18 - v22 * v20;
  a3->dword_000018 = floorf(v30 + 0.5f);

  v31 = v21 * v20 - v23 * v19;
  a3->dword_00001C = floorf(v31 + 0.5f);

  v32 = v22 * v19 - v21 * v18;
  a3->dword_000020 = floorf(v32 + 0.5f);

  sub_486089_NormalizeVector(a3);

  v33 = -(a3->dword_000018 * a2->flt_00000C) - a3->dword_00001C * a2->flt_000010 - a3->dword_000020 * a2->flt_000014;
  a3->dword_000024 = floorf(v33 + 0.5f);
  return true;
 }
 else
   return false;
}



//----- (0045CDB7) --------------------------------------------------------
bool __stdcall sub_45CDB7(struct class51_stru2 *_this, struct class04 *pClass04)
{
  int v2; // eax@1
  int v7; // [sp+10h] [bp-4h]@1
 int i;


 v2 = dword_F8B120 + _this->byte_000126[10];
 dword_F8AD54 = v2 << 16;

 v7 = 0;
 for (i = 0; i < dword_51B6DC; ++i)
 {
  if ( v7 >= 20 )
    break;
  //pClass04 is passed as the first parameter here in ecx but is never used inside StationaryLight_sub_45CE50_ProbablyApplyLightToScene
  StationaryLight_sub_45CE50_ProbablyApplyLightToScene((StationaryLight *)&array_519ABC[i], _this, &v7, 1);
 }

 for (i = 0; i < pStationaryLightsStack->uNumStationaryLightsActive; ++i)
 {
  if ( v7 >= 20 )
    break;
  StationaryLight_sub_45CE50_ProbablyApplyLightToScene(&pStationaryLightsStack->pLights[i], _this, &v7, 0);
 }

 dword_F8ADD4 = v7;
 return true;
}


//----- (0045CE50) --------------------------------------------------------
bool __stdcall StationaryLight_sub_45CE50_ProbablyApplyLightToScene(struct StationaryLight *_this, struct class51_stru2 *a2, int *a3, char a4)
{
  signed int v4; // ebx@1
  int v5; // ecx@2
  int v6; // esi@4
  int v7; // edx@6
  int v8; // ecx@8
  char v9; // dl@11
  int v10; // ecx@11
  int v11; // ebx@11
  int v12; // eax@15

  //apply light to scene
  v4 = _this->word_000006;
  v5 = _this->sLightPosX;
  v6 = _this->sLightPosY;
  v7 = _this->sLightPosZ;
  v8 = ((int)_this->sLightPosX * a2->dword_000000 +
        (int)_this->sLightPosY * a2->dword_000004 +
        (int)_this->sLightPosZ * a2->dword_000008 + a2->dword_00000C) >> 16;

 if (_this->word_000006 > 0 &&
     _this->sLightPosX > *(_WORD *)(a2 + 278) - _this->word_000006 &&
     _this->sLightPosX < *(_WORD *)(a2 + 280) + _this->word_000006 &&
     _this->sLightPosY > *(_WORD *)(a2 + 282) - _this->word_000006 &&
     _this->sLightPosY < *(_WORD *)(a2 + 284) + _this->word_000006 &&
     _this->sLightPosZ > *(_WORD *)(a2 + 286) - _this->word_000006 &&
     _this->sLightPosZ < *(_WORD *)(a2 + 288) + _this->word_000006 && a4 ||
     v8 >= 0 && v8 <= _this->word_000006)
  {
    dword_F8ADD8[*(_DWORD *)a3] = _this->word_000006;
    dword_F8AE28[*(_DWORD *)a3] = 65536 / _this->word_000006;
    dword_F8AE78[*(_DWORD *)a3] = _this->sLightPosX;
    dword_F8AEC8[*(_DWORD *)a3] = _this->sLightPosY;
    dword_F8AFB8[*(_DWORD *)a3] = _this->sLightPosZ;
    flt_F8B008[*(_DWORD *)a3] = (double)_this->uLightColorRed / 255.0;
    flt_F8B058[*(_DWORD *)a3] = (double)_this->uLightColorGreen / 255.0;
    flt_F8B0A8[*(_DWORD *)a3] = (double)_this->uLightColorBlue / 255.0;
    v11 = pD3DRenderer->bUsingSpecular;
    dword_F8AF18[*(_DWORD *)a3] = abs(v8);
    byte_F8B0F8[*(_DWORD *)a3] = _this->byte_00000B;
    v10 = (int)pD3DRenderer->pRenderD3D3;
    v9 = byte_F8B0F8[*(_DWORD *)a3];
    if ( pD3DRenderer->pRenderD3D3 )
    {
      if ( v11 )
      {
        if ( v9 & 4 )
          v9 = byte_4E94D2;
      }
    }
    byte_F8B0F8[*(_DWORD *)a3] = v9;
    v12 = 4 * *(_DWORD *)a3;
    if ( v10 )
    {
      if ( v11 )
      {
        if ( byte_F8B0F8[*(_DWORD *)a3] & 4 )
        {
          *(float *)((char *)flt_F8B008 + v12) = *(float *)((char *)flt_F8B008 + v12) * 0.3300000131130219;
          *(float *)(v12 + 0xF8B058) = *(float *)(v12 + 16298072) * 0.3300000131130219;
          *(float *)(v12 + 0xF8B0A8) = *(float *)(v12 + 16298152) * 0.3300000131130219;
        }
      }
    }
    ++*(_DWORD *)a3;
    return true;
  }
  else return false;
}


//----- (00488F2E) --------------------------------------------------------
int class51_sub_488F2E_GetHeightOnTerrain(struct class51 *_this, unsigned int uX, unsigned int uY)
{
 if (uX > 127 || uY > 127)
   return 0;
 else
   return class51_sub_47EE16_ActuallyGetHeightOnTerrain(_this, uX, uY);
}

//----- (0047EE16) --------------------------------------------------------
int class51_sub_47EE16_ActuallyGetHeightOnTerrain(struct class51 *_this, unsigned int uX, unsigned int uY)
{
 if (uX > 127 || uY > 127)
   return 0;
 else
  return 32 * _this->struct_0000B4.pHeightmap[128 * uY + uX];
}

//----- (0047EF60) --------------------------------------------------------
bool class51_sub_47EF60(struct class51 *_this, int a2, int a3, int a4)
{
  int v4; // ecx@1
  int v5; // edx@2
  int v6; // edi@2
  int v7; // esi@2
  int v8; // eax@4
  int v9; // ebx@4
  int v10; // eax@5
  int v11; // eax@7
  char v12; // al@12
  int v13; // esi@12
  char v14; // zf@16
  int v16; // [sp+4h] [bp-14h]@7
  int v17; // [sp+8h] [bp-10h]@5
  int v18; // [sp+Ch] [bp-Ch]@2
  int v20; // [sp+14h] [bp-4h]@2
  int i; // [sp+24h] [bp+Ch]@5

  v4 = a3 - 10;
  if ( a3 - 10 < a3 + 10 )
  {
    v5 = v4 - a3;
    v6 = 88 * (a3 - 30);
    v7 = a2;
    v20 = v4 - a3;
    v18 = a3 + 10 - v4;
    while ( 1 )
    {
      v8 = abs(v5);
      v9 = v7 - 10;
      if ( v7 - 10 < v7 + 10 )
      {
        v17 = v8 * v8;
        v10 = v9 - v7;
        for ( i = v9 - v7; ; v10 = i )
        {
          v11 = abs(v10);
          v16 = v11 * v11 + v17;
          if ( v16 <= 100 )
          {
            if ( v9 >= 20 )
            {
              if ( v9 <= 107 )
              {
                if ( v6 >= 0 )
                {
                  if ( v6 <= 7656 )
                  {
                    v13 = (v6 + v9 - 20) >> 3;
                    v12 = 1 << (8 - (v6 + v9 - 20) % 8 - 1);
                    //*((_BYTE *)v19 + v13 + 0x8F0) |= v12;
                    _this->array_0008F0[v13] |= v12;
                    if ( v16 <= 49 )
                      //*((_BYTE *)v19 + v13 + 0x528) |= v12;
                      _this->array_000528[v13] |= v12;
                    v7 = a2;
                  }
                }
              }
            }
          }
          ++v9;
          ++i;
          if ( v9 >= v7 + 10 )
            break;
        }
      }
      v6 += 88;
      ++v20;
      v14 = v18-- == 1;
      if ( v14 )
        break;
      v5 = v20;
    }
  }
  return 1;
}