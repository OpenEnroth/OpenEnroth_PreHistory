#include <io.h>

#include "Level.h"
#include "menus.h"
#include "tiles.h"
#include "data.h"
 #include "_lod.h"
#include "Events.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "GUI\GUI.h"

#include "AudioPlayer.h"
#include "FrameTables.h"

#include "Actor.h"

#include "RenderD3D3.h"





OutdoorLocation::OutdoorLocation()
{
 uNumBModels = 0;

 uNumSpawnPoints = 0;
 pSpawnPoints = nullptr;

 pBModels = nullptr;

 ptr_0000D4 = nullptr;
 ptr_0000E4 = nullptr;
 ptr_0000E0 = nullptr;

 pTerrainNormals = nullptr;
}

//----- (00488EB1) --------------------------------------------------------
int class51_sub_488EB1_GetSomeOtherTileInfo(OutdoorLocation *_this, int sX, int sY){
  int v3; // eax@1
  int v4; // edi@1

 v4 = WorldPosToGridCellZ(sY);
 v3 = WorldPosToGridCellX(sX);
 if ( v3 < 0 || v3 > 127 || v4 < 0 || v4 > 127 )
   return 0;

 return class51_sub_47EDB3_ActuallyGetSomeOtherTileInfo(_this, v3, v4);
}

//----- (0047EDB3) --------------------------------------------------------
int class51_sub_47EDB3_ActuallyGetSomeOtherTileInfo(OutdoorLocation *_this, unsigned int uX, unsigned int uY){
  int v3; // esi@5

 if (uX > 127 || uY > 127)
   return 0;
 else
 {
  v3 = _this->cTerrainData.pTilemap[128 * uY + uX];
  if ( v3 >= 90 )
     v3 = v3 + _this->pTileTypes[(v3 - 90) / 18].uTileID - 36 * (v3 - 90) / 36 - 90;
  return pTileTable->pTiles[v3].word_000018;
 }
}

//----- (00488EEF) --------------------------------------------------------
int class51_GetTileTexture(OutdoorLocation *_this, int sX, int sY){
 int v3; // eax@1
 int v4; // edi@1

 v4 = WorldPosToGridCellZ(sY);
 v3 = WorldPosToGridCellX(sX);
 if ( v3 < 0 || v3 > 127 || v4 < 0 || v4 > 127 )
   return -1;
 return class51_GetTileTexture2(_this, v3, v4);
}

//----- (0047ED08) --------------------------------------------------------
int class51_GetTileTexture2(OutdoorLocation *_this, unsigned int uX, unsigned int uY){
 int v3; // esi@5

 if (uX > 127 || uY > 127)
   return 0;

 v3 = _this->cTerrainData.pTilemap[uY * 128 + uX];
 if (v3 < 198)
 {
  if (v3 >= 90)
    v3 = v3 + _this->pTileTypes[(v3 - 90) / 18].uTileID - 36 * (v3 - 90) / 36 - 90;
 }
 else
   v3 = v3 + _this->pTileTypes[3].uTileID - 198;

 return pTileTable->pTiles[v3].uBitmapID;
}



//----- (00478389) --------------------------------------------------------
int __thiscall BModel_Clear(int _this)
{
  int result; // eax@1
  int v2; // esi@1
  int v3; // ST00_4@1
  int v4; // ST00_4@1
  int v5; // ST00_4@1
  result=0;
  v2 = _this;
  //MemFree( (void *)*(_DWORD *)(_this + 4));
  MemFree(*(_DWORD **)(_this + 4));
  v3 = *(_DWORD *)(v2 + 16);
  *(_DWORD *)(v2 + 4) = 0;
  //MemFree( (void *)v3);
  MemFree((void *)v3);
  v4 = *(_DWORD *)(v2 + 20);
  *(_DWORD *)(v2 + 16) = 0;
  //MemFree( (void *)v4);
  MemFree((void *)v4);
  v5 = *(_DWORD *)(v2 + 28);
  *(_DWORD *)(v2 + 20) = 0;
  //MemFree( (void *)v5);
  MemFree((void *)v5);
  *(_DWORD *)(v2 + 28) = 0;
  *(_DWORD *)(v2 + 24) = 0;
  *(_DWORD *)(v2 + 8) = 0;
  *(_DWORD *)v2 = 0;
  *(_WORD *)(v2 + 12) = 0;
  return result;
}


Result::Code OutdoorLocation::Clear()
{
 lstrcpyA((char *)string_000000, "blank");
 lstrcpyA((char *)pLocationFileName, "default.odm");
 lstrcpyA((char *)pLocationFileDescription, "WW Outdoor v1.00");
 lstrcpyA((char *)pSkyTextureName, "sky043");
 lstrcpyA((char *)pGroundTileset, "hm005");
 
 for (unsigned int i = 0; i < uNumBModels; ++i)
   BModel_Clear((int)&pBModels[i].pVertices);
 uNumBModels = 0;
 
 
 cTerrainData.Clear();
 
 if (pBModels)
 {
  MemFree(pBModels);
  pBModels = nullptr;
 }

 uNumSpawnPoints = 0;
 if (pSpawnPoints)
 {
  MemFree(pSpawnPoints);
  pSpawnPoints = nullptr;
 }

 if (ptr_0000D4)
 {
  MemFree(ptr_0000D4);
  ptr_0000D4 = nullptr;
 }

 if (ptr_0000E4)
 {
  MemFree(ptr_0000E4);
  ptr_0000E4 = nullptr;
 }

 if (ptr_0000E0)
 {
  MemFree(ptr_0000E0);
  ptr_0000E0 = nullptr;
 }

 if (pTerrainNormals)
 {
  MemFree(pTerrainNormals);
  pTerrainNormals = nullptr;
 }

 return Result::Success;
}


//----- (0047CF9C) --------------------------------------------------------
Result::Code OutdoorLocation::Load(const char *pFilename, int File, int a5)
{
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
  __int16 v31; // ax@33
  __int16 v33; // ax@37
  int v34; // ecx@37
  int v35; // eax@38
  int v36; // eax@38
  int v38; // eax@43
  int v39; // edi@45
  int v45; // eax@58
  int v51; // ebx@60
  int v52; // eax@61
  __int16 v64; // ax@64
  __int16 v65; // ax@65
  struct BSPModel::Face *v66; // ecx@65
  __int16 v67; // ax@80
  int v76; // eax@81
  int v78;  int v80; // eax@92
  int v82; // ecx@94
  int v83; // eax@95
  int v84; // edx@97
  int v85; // eax@99
  int v86; // eax@107
  int v87; // eax@110
  int v89; // edi@114
  int v90; // eax@118
  int v100; // eax@129
  int v106; // eax@147
  int v108; // eax@147
  int v109; // eax@147
  struct TileDesc *v110; // eax@147
  int v111; // ecx@150
  //int v113; // edi@159
  char v115; // [sp-14h] [bp-B94h]@55
  int v116; // [sp-10h] [bp-B90h]@55
  int v117; // [sp-Ch] [bp-B8Ch]@55
  void *v118; // [sp-8h] [bp-B88h]@55
  int v120; // [sp+0h] [bp-B80h]@10
  char v121[0x3C8]; // [sp+10h] [bp-B70h]@110
  char v122[0x3C8]; // [sp+3D8h] [bp-7A8h]@110
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
  //__int64 v155; // [sp+B44h] [bp-3Ch]@55
  int v157; // [sp+B50h] [bp-30h]@61
  cTexture *v158; // [sp+B54h] [bp-2Ch]@68
  struct maybe_odm_header
  {
   int v159; // [sp+B58h] [bp-28h]@50
   unsigned int magic;  // "MVII" for mm7
   unsigned int uCompressedSize; // [sp+B60h] [bp-20h]@50
   unsigned int uUncompressedSize; // [sp+B64h] [bp-1Ch]@50
  } v159;

  unsigned int v166; // [sp+B68h] [bp-18h]@13
  void *v167; // [sp+B6Ch] [bp-14h]@12
  unsigned int v168; // [sp+B70h] [bp-10h]@19
  int v170; // [sp+B78h] [bp-8h]@59
  char *Str2;  unsigned char *Src; // [sp+B7Ch] [bp-4h]@59
  int wtf;

 unsigned char *pTexturesNames;



 if (!pFilename)
   return Result::InvalidParams;

 Clear();

 LODFile_Bitmaps_LOD.sub_46454B();
 LODFile_Sprites_LOD.sub_4645DC();
 SpriteFrameTable_fn3(pSpriteFrameTable);
 LODFile_Icons_LOD.sub_46454B();
 /*if ( !_this->Load(Source, File, a4, a5) )
   {
    MessageBoxA(0, "Error!", "Couldn't Load Map!", 0);
    class51_CreateDefaultMap((int)_this);
    }*/	



 if (byte_6BE3C4_MaybeDrowningFlag)
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
  if (class35_obj.byte_267AD0 != -128 ||
      class35_obj.byte_267AD1 != -128 ||
      class35_obj.byte_267AD2 != -128)
  {
   class35_obj.byte_267AD0 = -128;
   class35_obj.byte_267AD1 = -128;
   class35_obj.byte_267AD2 = -128;
   class35_sub_48A614(&class35_obj);
  }
 }
 dword_6807E0 = 0;

 if (!LODFile_Games_LOD.IsContainerExist(pFilename))
   erroneous_printf("Unable to find %s in Games.LOD", pFilename);

#ifndef OLD_CODE
 wchar_t pLevelMapFilename[256];
 wsprintfW(pLevelMapFilename, L"%S", pFilename);

 pLevelMapFilename[lstrlenW(pLevelMapFilename) - 4] = 0;
 struct_576FE8.uTextureID_LocationMap = LODFile_Icons_LOD.LODFile_LoadTexture_New(pLevelMapFilename);
#else
 char pLevelMapFilename[256];
 lstrcpyA(pLevelMapFilename, pFilename);

 pLevelMapFilename[lstrlenA(pLevelMapFilename) - 4] = 0;
 struct_576FE8.uTextureID_LocationMap = LODFile_Icons_LOD.LODFile_LoadTexture(pLevelMapFilename, 2);
#endif

 FILE *hODMFile = LODFile_Games_LOD.Find_Container(pFilename, 1);

 v159.v159 = 91969;
 v159.magic = 'IIVM';
 v159.uCompressedSize = 0;
 v159.uUncompressedSize = 0;
 locked_fread(&v159, 0x10, 1, hODMFile);

 if (v159.v159 != 91969 || v159.magic != 'iivm' && v159.magic != 'IIVM')
 {
  Game_sub_40E2C8(nullptr, "Invalid ODM format", 0);
  ExitProcess(0);
 }

 unsigned char *pRawODM = MemAlloc(unsigned char, v159.uUncompressedSize);

 if (v159.uCompressedSize < v159.uUncompressedSize)
 {
  Src = MemAlloc(unsigned char, v159.uCompressedSize);
  wtf = (int)Src;
  locked_fread(Src, v159.uCompressedSize, 1, hODMFile);
  MemUnzip(pRawODM, &v159.uUncompressedSize, Src, v159.uCompressedSize);
 }
 else
   locked_fread(pRawODM, v159.uUncompressedSize, 1, hODMFile);

 Src = pRawODM;

 memcpy(string_000000, Src, 32);
 memcpy(pLocationFileName, Src + 1 * 32, 32);
 memcpy(pLocationFileDescription, Src + 2 * 32, 32);
 memcpy(pSkyTextureName, Src + 3 * 32, 32);
 memcpy(pGroundTileset, Src + 4 * 32, 32);
 memcpy(pTileTypes, Src + 5 * 32, 4 * sizeof(TileType));
 Src += 0xB0;

 class51_sub_47F420(this);
 class51_sub_47F3EA(this);

  pGameLoadingUI_ProgressBar->SetProgress(0.15f);
 
 cTerrainData.Initialize();
 {
  memcpy(cTerrainData.pHeightmap, Src, 128 * 128);
  Src += 128 * 128;

  memcpy(cTerrainData.pTilemap, Src, 128 * 128);
  Src += 128 * 128;

  memcpy(cTerrainData.pAttributemap, Src, 128 * 128);
  Src += 128 * 128;

  ptr_0000D4 = NamedMemAlloc(unsigned char, 128 * 128 * 2, "ODM CMAP");
 }
 cTerrainData.sub_47C80A(0, 0, 128, 128);

 pGameLoadingUI_ProgressBar->SetProgress(0.20f);
 
 memcpy(&uNumTerrainNormals, Src, 4);
 Src += 4;

 memcpy(pTerrainSomeOtherData, Src, 128 * 128 * 2 * sizeof(unsigned int));
 Src += 0x20000;
 memcpy(pTerrainNormalIndices, Src, 128 * 128 * 2 * sizeof(unsigned short));
 Src += 0x10000;

 pTerrainNormals = NamedMemAlloc(Vec3, uNumTerrainNormals, "ODM Terrain Normals");
 memcpy(pTerrainNormals, Src, uNumTerrainNormals * sizeof(struct Vec3));
 Src += uNumTerrainNormals * sizeof(struct Vec3);

 memcpy(&uNumBModels, Src, 4);
 Src += 4;


 pBModels = NamedMemAlloc(BSPModel, uNumBModels, "ODM BSP Models");
 memcpy(pBModels, Src, uNumBModels * sizeof(struct BSPModel));
 Src += uNumBModels * sizeof(struct BSPModel);


 pGameLoadingUI_ProgressBar->SetProgress(0.25f);


 v170 = 0;
 if (uNumBModels > 0)
 {
  v51 = 0;
  unsigned int i = 0;
  
  while (true)
  {
   pBModels[i].ptr_000058 = 0;
   pBModels[i].ptr_000060 = 0;

   pBModels[i].pVertices = NamedMemAlloc(BSPModel::Vertex, pBModels[i].uNumVertices, (char *)pBModels[i].pModelName);
   memcpy(pBModels[i].pVertices, Src, pBModels[i].uNumVertices * sizeof(BSPModel::Vertex));
   Src += pBModels[i].uNumVertices * sizeof(BSPModel::Vertex);

   pBModels[i].pFaces = NamedMemAlloc(BSPModel::Face, pBModels[i].uNumFaces, (char *)pBModels[i].pModelName);
   memcpy(pBModels[i].pFaces, Src, pBModels[i].uNumFaces * sizeof(BSPModel::Face));
   Src += pBModels[i].uNumFaces * sizeof(BSPModel::Face);

   pBModels[i].ptr_000058 = NamedMemAlloc(unsigned short, pBModels[i].uNumFaces, (char *)pBModels[i].pModelName);
   memcpy(pBModels[i].ptr_000058, Src, pBModels[i].uNumFaces * 2);
   Src += pBModels[i].uNumFaces * 2;

   pBModels[i].ptr_000060 = NamedMemAlloc(unsigned char, 8 * pBModels[i].dword_00005C, (char *)pBModels[i].pModelName);
   memcpy(pBModels[i].ptr_000060, Src, 8 * pBModels[i].dword_00005C);
   Src += 8 * pBModels[i].dword_00005C;

   pTexturesNames = NamedMemAlloc(unsigned char, 10 * pBModels[i].uNumFaces, "ODM Loading tmp texture names");
   memcpy(pTexturesNames, Src, 10 * pBModels[i].uNumFaces);
   Src += 10 * pBModels[i].uNumFaces;

   v157 = 0;
   v52 = (int)pBModels;
   if (pBModels[i].uNumFaces > 0)
     break;

LABEL_74:
   MemFree(pTexturesNames);
   ++v170;
   v51 += 188;
   ++i;
   if ( v170 >= uNumBModels)
     goto LABEL_75;
  }
  
  v168 = 0;
  Str2 = (char *)pTexturesNames;
  unsigned int j = 0;
  while ( 1 )
  {
   v66 = &this->pBModels[i].pFaces[j];
   if (~v66->uFaceAttributes & 0x4000)
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
   
   v120 = this->pBModels[v51 / 188].pFaces[v168 / 308].uTextureID;
   TextureFrameTable_sub_44E0ED(pTextureFrameTable, v120);

LABEL_69:
   if ( *(_WORD *)(wtf + 292) )
   {
    if ( sub_44C1E8((BSPModel::Face *)wtf) )
      *(_BYTE *)(wtf + 30) |= 0x10u;
    else
      *(_BYTE *)(wtf + 30) &= 0xEFu;
   }
   ++v157;
   
   v52 = (int)this->pBModels;
   v168 += 308;
   ++j;
   Str2 += 10;
   if ( v157 >= this->pBModels[i].uNumFaces)
      goto LABEL_74;
  }

#ifndef OLD_CODE
	wchar_t  pFilename[256];
    wsprintfW(pFilename, L"%S", Str2);

    v66->uTextureID = LODFile_Bitmaps_LOD.LODFile_LoadTexture_New(pFilename);
#else
    v66->uTextureID = LODFile_Bitmaps_LOD.LODFile_LoadTexture(Str2, 2);
#endif

    if (v66->uTextureID != -1)
    {
     v158 = &LODFile_Bitmaps_LOD.aLODHeaders[v66->uTextureID];
     v158->word_000026 = class35_sub_48A3BC_MessWithPalettes(&class35_obj, v158->word_000024);
    }
    goto LABEL_69;
  }

LABEL_75:
  pGameLoadingUI_ProgressBar->SetProgress(0.30f);

  memcpy(&uNumLevelDecorations, Src, 4);
  Src += 4;

  if ( (signed int)uNumLevelDecorations < 0 || (signed int)uNumLevelDecorations > 3000 )
  {
    Game_sub_40E2C8(0, "Can't load file!", (int)((char *)&pFilename + 3));
    sub_466D09(0, *(int *)&v115, v116, v117, (int)v118, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp", __LINE__);
  }


 memcpy(pLevelDecorations, Src, uNumLevelDecorations * sizeof(struct LevelDecoration));
 Src += uNumLevelDecorations * sizeof(struct LevelDecoration);

 for (unsigned int i = 0; i < uNumLevelDecorations; ++i)
 {
  char pStr[32];
  memcpy(pStr, Src, 32);  Src += 32;
  pLevelDecorations[i].uDecorationDescriptionID = DecorationList_FindDecoration(pDecorationDescriptionList, pStr);
 }

 pGameLoadingUI_ProgressBar->SetProgress(0.35f);


 memcpy(&dword_0000DC, Src, 4);
 Src += 4;

 ptr_0000E0 = NamedMemAlloc(unsigned short, dword_0000DC, "ODM IDLIST");
 memcpy(ptr_0000E0, Src, 2 * dword_0000DC);
 Src += 2 * dword_0000DC;


 ptr_0000E4 = NamedMemAlloc(unsigned int, 128 * 128, "ODM OMAP");
 memcpy(ptr_0000E4, Src, 128 * 128 * 4);
 Src += 65536;

 pGameLoadingUI_ProgressBar->SetProgress(0.40f);

 memcpy(&uNumSpawnPoints, Src, 4);
 Src += 4;

#if 0
 pSpawnPoints = NamedMemAlloc(SpawnPointMM6, uNumSpawnPoints * sizeof(SpawnPointMM6), "ODM Spawn");
 memcpy(pSpawnPoints, Src, uNumSpawnPoints * sizeof(SpawnPointMM6));
#else
 pSpawnPoints = NamedMemAlloc(SpawnPointMM7, uNumSpawnPoints * sizeof(SpawnPointMM7), "ODM Spawn");
 memcpy(pSpawnPoints, Src, uNumSpawnPoints * sizeof(SpawnPointMM7));
#endif

 pGameLoadingUI_ProgressBar->SetProgress(0.45f);

 MemFree((void *)wtf);
 MemFree(pRawODM);



 char pDDMName[256];
 lstrcpyA(pDDMName, pFilename);
 pDDMName[lstrlenA(pDDMName) - 3] = 'd';

 FILE *hDDMFile = LODFile_Games_LOD.Find_Container(pDDMName, 1);
 locked_fread(&v159, 0x10u, 1, hDDMFile);

 if (v159.v159 != 91969 || v159.magic != 'iivm' && v159.magic != 'IIVM')
 {
  Game_sub_40E2C8(&v115, "Invalid DDM format", 0);
  sub_466D09((char *)0, *(int *)&v115, v116, v117, (int)v118, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp", __LINE__);
 }

 wtf = v159.uCompressedSize;
 v166 = v159.uUncompressedSize;
 unsigned char *pRawDDMFile = MemAlloc(unsigned char, v159.uUncompressedSize);

 if (v159.uCompressedSize == v159.uUncompressedSize)
   locked_fread(pRawDDMFile, v159.uUncompressedSize, 1, hDDMFile);
 else if (v159.uCompressedSize < v159.uUncompressedSize)
 {
  Src = MemAlloc(unsigned char, v159.uCompressedSize);
  locked_fread(Src, v159.uCompressedSize, 1, hDDMFile);
  MemUnzip(pRawDDMFile, &v159.uUncompressedSize, Src, v159.uCompressedSize);
  MemFree(Src);
 }
 else
 {
  Game_sub_40E2C8(0, "Uncompressed DDM", 0);
  sub_466D09((char *)0, *(int *)&v115, v116, v117, (int)v118, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp", __LINE__);
 }

 pGameLoadingUI_ProgressBar->SetProgress(0.50f);

 memcpy(array_0004C8, pRawDDMFile, 0x28);
 Src = pRawDDMFile + 40;

 v82 = 0;
 for (unsigned int i = 0; i < uNumBModels; ++i)
   v82 += pBModels[i].uNumFaces;

 
 v84 = array_0004C8[4];
 Str2 = 0;
 if ( v84 )
 {
  if (array_0004C8[6])
  {
   v85 = array_0004C8[5];
   if ( v85 )
   {
    if ( v84 != v82 || this->array_0004C8[6] != this->uNumBModels || v85 != uNumLevelDecorations )
      Str2 = (char *)1;
   }
  }
 }

 pGameLoadingUI_ProgressBar->SetProgress(0.55f);


 MapInfo *pMapInfo = pMapStats->GetMapInfo(pFilename);
 unsigned int uRespawnInterval = pMapInfo->uRespawnInterval;
  //unsigned int uLocationID = CMapStats_FindLocation(pMapStats, pFilename);
  //unsigned int uRespawnInterval =  pMapStats->pMapInfos[uLocationID].uRespawnInterval;


 if (dword_6BE364 & 0x2000)
   uRespawnInterval = 29030400;

 if ( Str2 )
 {
    memset(v122, 0, 0x3C8u);
    v87 = (int)memset(v121, 0, 0x3C8u);
    goto LABEL_112;
  }

  v86 = this->array_0004C8[1];
  if ( File - v86 >= (unsigned int)uRespawnInterval || !v86 )
  {
    memcpy(v122, (const void *)Src, 0x3C8);
    v87 = (int)memcpy(v121, (const void *)(Src + 0x3C8), 0x3C8);

LABEL_112:
    MemFree(pRawDDMFile);

    array_0004C8[1] = File;
    if (!Str2)
      ++array_0004C8[0];

    *(_DWORD *)a5 = 1;

    hDDMFile = LODFile_Games_LOD.Find_Container(pDDMName, 0);
    locked_fread(&v159, 0x10, 1, hDDMFile);

    wtf = v159.uCompressedSize;
    v166 = v159.uUncompressedSize;
    v89 = (int)MemAlloc(char, v159.uUncompressedSize);
    v168 = v89;
    if ( wtf <= v166 )
    {
      if ( wtf == v166 )
      {
        locked_fread((void *)v89, v166, 1, hDDMFile);
      }
      else
      {
        Src = MemAlloc(unsigned char, wtf);
        locked_fread(Src, wtf, 1, hDDMFile);
        MemUnzip((char *)v89, &v166, Src, wtf);
        MemFree(Src);
      }
    }
    else
    {
      Game_sub_40E2C8(nullptr, "Can't load file!", 0);
      sub_466D09(&File, *(int *)&v115, v116, v117, (int)v118, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp", __LINE__);
    }
    v78 = v89 + 40;
    goto LABEL_120;
  }

  *(_DWORD *)a5 = 0;

LABEL_120:
  pGameLoadingUI_ProgressBar->SetProgress(0.60f);

  memcpy(this->array_000528, (char *)v78, 0x3C8);
  memcpy(this->array_0008F0, (char *)v78 + 0x3C8, 0x3C8);

  v78 = (int)((char *)v78 + 0x3C8 + 0x3C8);


  if ( *(_DWORD *)a5 )
  {
    memcpy(this->array_000528, v122, 0x3C8);
    memcpy(this->array_0008F0, v121, 0x3C8);
  }

  for (unsigned i = 0; i < this->uNumBModels; ++i)
  {
      for (unsigned j = 0; j < this->pBModels[i].uNumFaces; ++j)
      {
        v118 = (void *)&this->pBModels[i].pFaces[j].uFaceAttributes;
        memcpy(v118, (char *)v78, 4);
        v78 = (int)((char *)v78 + 4);
      }

      for (unsigned j = 0; j < this->pBModels[i].uNumFaces; ++j)
      {
          if (this->pBModels[i].pFaces[j].sCogTriggeredID)
          {
            if ( sub_44C1E8(&this->pBModels[i].pFaces[j]) )
              this->pBModels[i].pFaces[j].uFaceAttributes |= 0x00100000;
            else
              this->pBModels[i].pFaces[j].uFaceAttributes &= 0xFFEFFFFF;
          }

      }
  }

  pGameLoadingUI_ProgressBar->SetProgress(0.65f);

  for (unsigned int i = 0; i < uNumLevelDecorations; ++i)
  {
      memcpy(&pLevelDecorations[i].word_000002, (char *)v78, 2);
      v78 = (int)((char *)v78 + 2);
  }

  memcpy(&uNumActors, (char *)v78, 4);
  v78 = (int)((char *)v78 + 4);
  if ( (signed int)uNumActors < 0 || uNumActors > 500 )
  {
    Game_sub_40E2C8(0, "Can't load file!", 0);
    sub_466D09(nullptr, *(int *)&v115, v116, v117, (int)v118, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp", __LINE__);
  }

  pGameLoadingUI_ProgressBar->SetProgress(0.70f);

  memcpy(pActors, (char *)v78, uNumActors * sizeof(struct Actor));
  v78 = (int)((char *)v78 + uNumActors * sizeof(struct Actor));

  memcpy(&uNumLayingItems, (char *)v78, 4);
  v78 = (int)((char *)v78 + 4);
  if ( (signed int)uNumLayingItems < 0 || uNumLayingItems > 1000 )
  {
    Game_sub_40E2C8(0, "Can't load file!", (int)((char *)&a5 + 3));
    sub_466D09(0, *(int *)&v115, v116, v117, (int)v118, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp", __LINE__);
  }

  memcpy(pLayingItemsList, (char *)v78, uNumLayingItems * sizeof(struct LayingItem));
  v78 = (int)((char *)v78 + uNumLayingItems * sizeof(struct LayingItem));


  pGameLoadingUI_ProgressBar->SetProgress(0.75f);

  memcpy(&dword_5FF140, (char *)v78, 4);
  v78 = (int)((char *)v78 + 4);
  if ( (signed int)dword_5FF140 < 0 || (signed int)dword_5FF140 > 20 )
  {
    Game_sub_40E2C8(0, "Can't load file!", 0);
    sub_466D09(0, *(int *)&v115, v116, v117, (int)v118, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp", __LINE__);
  }


  memcpy(array_5E5150, (char *)v78, dword_5FF140 * sizeof(struct struct3));
  v78 = (int)((char *)v78 + dword_5FF140 * sizeof(struct struct3));

  memcpy(&global_5E4C90, (char *)v78, sizeof(struct struct4));


  memcpy(this->array_0004F0, (char *)v78 + 200, 0x38);
  MemFree((char *)v168);

  CTileTable_LoadSomeTiles(pTileTable, 4);
  CTileTable_LoadSomeTiles(pTileTable, pTileTypes[0].uTileGroup);
  CTileTable_LoadSomeTiles(pTileTable, pTileTypes[1].uTileGroup);
  CTileTable_LoadSomeTiles(pTileTable, pTileTypes[2].uTileGroup);
  CTileTable_LoadSomeTiles(pTileTable, pTileTypes[3].uTileGroup);

  strcpy((char *)this->pGroundTileset, byte_6BE124_cfg_textures_DefaultGroundTexture);
  v109 = pTileTypes[0].uTileID;
  v120 = 0;
  v110 = TileTable_GetTile(pTileTable, pTileTypes[0].uTileID);

  pGameLoadingUI_ProgressBar->SetProgress(0.80f);
  {
#ifndef OLD_CODE
   wchar_t pTmp[256];
   wsprintfW(pTmp, L"%S", v110->sTileName);

   v106 = LODFile_Bitmaps_LOD.LODFile_LoadTexture_New(pTmp);
#else
   v106 = LODFile_Bitmaps_LOD.LODFile_LoadTexture((const char*)&v110->sTileName,2);
#endif
  }
  this->dword_0000EC = v106;
  if ( v106 != -1 )
    LODFile_Bitmaps_LOD.aLODHeaders[v106].word_000026 = class35_sub_48A3BC_MessWithPalettes(&class35_obj, LODFile_Bitmaps_LOD.aLODHeaders[v106].word_000024);

  sub_47F0E2();

LABEL_150:
  v111 = this->array_0004F0[1];

  __int64 v155;
  LODWORD(v155) = this->array_0004F0[0];
  HIDWORD(v155) = this->array_0004F0[1];

  if ( v111 | (_DWORD)v155 )
  {
    v120 = 28;
    if ( (signed int)((signed int)(signed __int64)((double)v155 * 0.234375) / 60 / 60 / 0x18u) % 28 != pParty_global->uDaysPlayed )
    {
      if ( rand() % 100 >= 20 )
        v120 = dword_4EC268[rand() % dword_4EC2A8];
      else
        v120 = dword_4EC28C[rand() % dword_4EC2AC];
      wsprintfA((char *)&this->array_0004F0[2], "plansky%d", v120);
    }
  }
  else
  {
    strcpy((char *)&this->array_0004F0[2], "plansky3");
  }

  {
#ifndef OLD_CODE
   wchar_t pSkyFilename[256];

   wsprintfW(pSkyFilename, L"%S", &this->array_0004F0[2]);
   this->uSkyTextureID = LODFile_Bitmaps_LOD.LODFile_LoadTexture_New(pSkyFilename);
#else
   this->uSkyTextureID = LODFile_Bitmaps_LOD.LODFile_LoadTexture((const char*)&this->array_0004F0[2], 2);
#endif
  }

  v158 = &LODFile_Bitmaps_LOD.aLODHeaders[this->uSkyTextureID];
  v120 = v158->word_000024;
  v158->word_000026 = class35_sub_48A3BC_MessWithPalettes(&class35_obj, v158->word_000024);
  
  class35_sub_48A614(&class35_obj);

 if (!bNoSound)
 {
  sub_4A9A67(pSoundList, 53, 0);
  sub_4A9A67(pSoundList, 92, 0);
  sub_4A9A67(pSoundList, 57, 0);
  sub_4A9A67(pSoundList, 96, 0);
  sub_4A9A67(pSoundList, 64, 0);
  sub_4A9A67(pSoundList, 103, 0);

  for (unsigned int i = 0; i < 3; ++i)
  {
      switch (pTileTypes[i].uTileGroup)
      {
       case Terrain::Tileset::Grass:
          sub_4A9A67(pSoundList, 54, 0);
          sub_4A9A67(pSoundList, 93, 0);
        break;

        case Terrain::Tileset::Sand:
          sub_4A9A67(pSoundList, 58, 0);
          sub_4A9A67(pSoundList, 97, 0);
        break;

        case Terrain::Tileset::Volcanic:
          sub_4A9A67(pSoundList, 52, 0);
          sub_4A9A67(pSoundList, 91, 0);
        break;

        case 3:
          sub_4A9A67(pSoundList, 51, 0);
          sub_4A9A67(pSoundList, 90, 0);
          break;

        case Terrain::Tileset::Water:
          sub_4A9A67(pSoundList, 62, 0);
          sub_4A9A67(pSoundList, 101, 0);
          break;

        case 6:
          sub_4A9A67(pSoundList, 49, 0);
          sub_4A9A67(pSoundList, 88, 0);
          break;

        case 7:
          sub_4A9A67(pSoundList, 61, 0);
          sub_4A9A67(pSoundList, 100, 0);
        break;

        default:
            continue;
      }
   }
 }

 pGameLoadingUI_ProgressBar->SetProgress(0.85f);

  dword_6BE030 = this->array_0004F0[5];
  dword_6BE040 = this->array_0004F0[6];
  dword_6BE044 = this->array_0004F0[7];
  if (!_strcmpi(pFilename, "out15.odm"))
    sub_464851();
  
  dword_6BE134 = pTileTypes[0].uTileGroup;
  return Result::Success;
}



//----- (0047F420) --------------------------------------------------------
bool class51_sub_47F420(OutdoorLocation *_this)
{
 for (unsigned int i = 0; i < 3; ++i)
   _this->pTileTypes[i].uTileID = sub_487ED6(pTileTable, _this->pTileTypes[i].uTileGroup, 1);

 return true;
}


//----- (0047F3EA) --------------------------------------------------------
bool class51_sub_47F3EA(OutdoorLocation *_this)
{
 _this->pTileTypes[3].uTileID = sub_487ED6(pTileTable, _this->pTileTypes[3].uTileGroup, 1);
 CTileTable_LoadSomeTiles(pTileTable, _this->pTileTypes[3].uTileGroup);

 return true;
}



//----- (0047CD44) --------------------------------------------------------
Result::Code OutdoorLocation::TerrainData::Initialize()
{
 pHeightmap = NamedMemAlloc(unsigned char, 128 * 128, "ODM TerrainData::Heightmap");
 if (!pHeightmap)
   return Result::OutOfMemory;

 pTilemap = NamedMemAlloc(unsigned char, 128 * 128, "ODM TerrainData::Tilemap");
 if (!pTilemap)
 {
  MemFree(pHeightmap);
  return Result::OutOfMemory;
 }

 pAttributemap = NamedMemAlloc(unsigned char, 128 * 128, "ODM TerrainData::Attributes map");
 if (!pAttributemap)
 {
  MemFree(pHeightmap);
  MemFree(pTilemap);
  return Result::OutOfMemory;
 }

 ptr_00000C = NamedMemAlloc(unsigned char, 128 * 128 * 2, "ODM TerrainData::DMAP");
 if (!ptr_00000C)
 {
  MemFree(pHeightmap);
  MemFree(pTilemap);
  MemFree(pAttributemap);
  return Result::OutOfMemory;
 }

 return Result::Success;
}

//----- (0047C7C2) --------------------------------------------------------
Result::Code OutdoorLocation::TerrainData::Clear()
{
 if (pHeightmap)
 {
  MemFree(pHeightmap);
  pHeightmap = nullptr;
 }

 if (pTilemap)
 {
  MemFree(pTilemap);
  pTilemap = nullptr;
 }

 if (pAttributemap)
 {
  MemFree(pAttributemap);
  pAttributemap = nullptr;
 }

 if (ptr_00000C)
 {
  MemFree(ptr_00000C);
  ptr_00000C = nullptr;
 }

 word_000010 = 0;
 word_000012 = 0;
 word_000014 = 0;
 word_000016 = 0;
 dword_000018 = 0;
 dword_00001C = 0;

 return Result::Success;
}



//----- (0047C80A) --------------------------------------------------------
void OutdoorLocation::TerrainData::sub_47C80A(int sX, int sY, int sZ, int sW)
{
  int v1;
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
                  v16 = 32 * pHeightmap[y * word_000010 + x];
                  v22 = 32 * pHeightmap[y * word_000010 + x + 1];
                  v23 = (63 - y) * 512;

                  v25 = v23 - v17;

                  v40 = 32 * pHeightmap[(y + 1) * word_000010 + x];
                  v42 = 32 * pHeightmap[(y + 1) * word_000010 + x + 1];
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

                  ptr_00000C[2 * (x + y * word_000010) + 1] = v31;
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
                  ptr_00000C[2 * (x + y * word_000010)] = v38;
   }
  }
 }
}



//----- (0044C1E8) --------------------------------------------------------
bool sub_44C1E8(BSPModel::Face *_this)
{
 for (unsigned i = 0; i < uLevelEVT_NumEvents; ++i)
   if (pLevelEVT_Events[i].dword_000000 == _this->sCogTriggeredID)
   {
    if (pLevelEVT[pLevelEVT_Events[i].uEventOffsetInEVT + 4] != 4 ||
        pLevelEVT[pLevelEVT_Events[i + 1].uEventOffsetInEVT + 4] != 1)
      return false;
    else return true;
   }
 return false;
}



//----- (0047F223) --------------------------------------------------------
int sub_47F223_LooksLikeGenerateMonsterLoot(OutdoorLocation *_this)
{
  void *v5; // [sp+0h] [bp-4h]@1
  LayingItem *pItem;
  ItemGen *pItGen;

  v5 = _this;
  for(unsigned int i = 0;i < uNumLayingItems; i++)
  {
    pItem = &pLayingItemsList[i];
    
    if ( !pItem->uObjectDescriptionID )
     continue;
    
    if ( !(pItem->word_00001A & 8) ) 
    {
      if ( !(pObjectDescriptionList->pDescriptions[pItem->uObjectDescriptionID].byte_000026 & 0x10) )
        pItem->sItemPosZ = sub_48257A(pItem->sItemPosX, pItem->sItemPosY, (int)&v5, 0); // something strange goes here with v5
    }
    pItGen = &pItem->stru_000024;
    if ( pItGen->uItemID )
    {
      if ( pItGen->uItemID != 220 )
      {
        if (pClass40->pItems[pItGen->uItemID - 1].uEquipType == 14 )
        {
          if ( !pItGen->dword_000004 )
            pItGen->dword_000004 = rand() % 15 + 5;
        }
      }
      class40_sub_456D17(pClass40, pItGen);
    }
    
  }
  runtime_warning();
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  return 1;
}



//----- (004892E6) --------------------------------------------------------
int __thiscall class51_sub_4892E6(OutdoorLocation *_this)
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
      _this->dword_000CBC = (signed __int64)(20.0 - v8 * (1.0 / 480.0) * 20.0);
      result = pParty_global->uCurrentMinute;
      _this->dword_01C288 = pParty_global->uCurrentMinute;
    }
  }
  return result;
}


//----- (00482170) --------------------------------------------------------
bool sub_482170(BSPModel::Face *_this, struct RenderVertex *a2, struct struct8 *a3)
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

 if ((pOldCamera->sPosX - a2->x) * v26 +
     (pOldCamera->sPosZ - a2->y) * v25 +
     (pOldCamera->sPosY - a2->z) * v24 > 0.0)
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
bool __stdcall sub_45CDB7_Face_ApplyLight(BSPModel::Face *_this, struct class04 *pClass04)
{
  int v2; // eax@1
  int v7; // [sp+10h] [bp-4h]@1
 int i;


 v2 = dword_F8B120 + _this->uShadeType;
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
bool __stdcall StationaryLight_sub_45CE50_ProbablyApplyLightToScene(struct StationaryLight *_this, BSPModel::Face *a2, int *a3, char a4)
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
  v8 = ((int)_this->sLightPosX * a2->pFaceNormal[0] +
        (int)_this->sLightPosY * a2->pFaceNormal[1] +
        (int)_this->sLightPosZ * a2->pFaceNormal[2] + a2->sNormalDistance) >> 16;

 if (_this->word_000006 > 0 &&
     _this->sLightPosX > *(_WORD *)(a2 + 278) - _this->word_000006 &&
     _this->sLightPosX < *(_WORD *)(a2 + 280) + _this->word_000006 &&
     _this->sLightPosY > *(_WORD *)(a2 + 282) - _this->word_000006 &&
     _this->sLightPosY < *(_WORD *)(a2 + 284) + _this->word_000006 &&
     _this->sLightPosZ > *(_WORD *)(a2 + 286) - _this->word_000006 &&
     _this->sLightPosZ < *(_WORD *)(a2 + 288) + _this->word_000006 &&
     a4 || v8 >= 0 && v8 <= _this->word_000006)
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
int class51_sub_488F2E_GetHeightOnTerrain(OutdoorLocation *_this, unsigned int uX, unsigned int uY){
 if (uX > 127 || uY > 127)
   return 0;
 else
   return class51_sub_47EE16_ActuallyGetHeightOnTerrain(_this, uX, uY);
}

//----- (0047EE16) --------------------------------------------------------
int class51_sub_47EE16_ActuallyGetHeightOnTerrain(OutdoorLocation *_this, unsigned int uX, unsigned int uY){
 if (uX > 127 || uY > 127)
   return 0;
 else
  return 32 * _this->cTerrainData.pHeightmap[128 * uY + uX];}

//----- (0047EF60) --------------------------------------------------------
bool class51_sub_47EF60(OutdoorLocation *_this, int a2, int a3, int a4){
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

//----- (0047CCE2) --------------------------------------------------------
Result::Code OutdoorLocation::TerrainData::Reset()
{
 void **v2; // esi@1
 v2 = (void **)this;
 
 memset(pHeightmap, 0, 128 * 128);
 memset(pTilemap, 90, 128 * 128);
 memset(pAttributemap, 0, 128 * 128);
 memset(ptr_00000C, 0, 128 * 128 * 2);
 *((_WORD *)v2 + 9) = 128;
 *((_WORD *)v2 + 8) = 128;
 *((_WORD *)v2 + 11) = 7;
 *((_WORD *)v2 + 10) = 7;
 v2[7] = (void *)127;
 v2[6] = (void *)127;
 
 return Result::Success;
}



//----- (004893C1) --------------------------------------------------------
void __cdecl class51_sub_4893C1(struct OutdoorLocation *_this)
{
 _this->flt_01C284 = sub_488E23();
}



//----- (0047CDE2) --------------------------------------------------------
int __thiscall class51_CreateDefaultMap(int Dest)
{
  int result; // eax@1
  int v2; // esi@1
  int v3; // eax@1
  int v4; // ST14_4@1
  int v5; // eax@1
  int v6; // ST14_4@1
  int v7; // eax@1
  char v8; // zf@1

  v2 = Dest;
  strcpy((char *)Dest, "blank");
  strcpy((char *)(v2 + 32), "i6.odm");
  strcpy((char *)(v2 + 64), "MM6 Outdoor v1.00");
  *(_DWORD *)(v2 + 176) = 0;
  *(_WORD *)(v2 + 160) = 0;
  *(_WORD *)(v2 + 164) = 5;
  *(_WORD *)(v2 + 168) = 6;
  *(_WORD *)(v2 + 172) = 10;
  class51_sub_47F420((OutdoorLocation *)v2);
  class51_sub_47F3EA((OutdoorLocation *)v2);
  //MemFree( (void *)*(_DWORD *)(v2 + 216));
  //MemFree( (void *)*(_DWORD *)(v2 + 1220));
  MemFree(*(_DWORD **)(v2 + 216));
  MemFree(*(_DWORD **)(v2 + 1220));
  *(_DWORD *)(v2 + 216) = 0;
  *(_DWORD *)(v2 + 1220) = 0;
  //class51_InitializeGeodata((OutdoorLocation::TerrainData *)(v2 + 180));
  //(TerrainData::Reset)((void **)(v2 + 180));
  //(TerrainData::sub_47C80A)((OutdoorLocation::TerrainData *)(v2 + 180), 0, 0, 128, 128);
  //MemFree( (void *)*(_DWORD *)(v2 + 212));
  MemFree(*(_DWORD **)(v2 + 212));
  *(_DWORD *)(v2 + 212) = 0;
  //v3 = (int)mem_mng.AllocatedNamedBuffer( 0, 32768, "CMAP");
  v3 = (int)NamedMemAlloc(char, 32768, "CMAP");
  v4 = *(_DWORD *)(v2 + 228);
  *(_DWORD *)(v2 + 212) = v3;
  //MemFree( (void *)v4);
  MemFree((void *)v4);
  *(_DWORD *)(v2 + 228) = 0;
  //v5 = (int)mem_mng.AllocatedNamedBuffer( 0, 65536, "OMAP");
  v5 = (int)NamedMemAlloc(char, 65536, "OMAP");
  *(_DWORD *)(v2 + 228) = v5;
  memset((void *)v5, 0, 0x10000u);
  v6 = *(_DWORD *)(v2 + 224);
  *(_DWORD *)(v2 + 220) = 0;
  //MemFree( (void *)v6);
  MemFree((void *)v6);
  *(_DWORD *)(v2 + 224) = 0;
  //v7 = (int)mem_mng.AllocatedNamedBuffer( 0, 2, "IDLIST");
  v7 = (int)NamedMemAlloc(char, 2, "IDLIST");
  *(_DWORD *)(v2 + 224) = v7;
  *(_WORD *)v7 = 0;
  strcpy((char *)(v2 + 96), byte_6BE114_cfg_textures_DefaultSkyTexture);
  *(_DWORD *)(v2 + 232) = LODFile_Bitmaps_LOD.LODFile_LoadTexture( (const char *)(v2 + 96), 2);
  strcpy((char *)(v2 + 128), byte_6BE124_cfg_textures_DefaultGroundTexture);
  result = LODFile_Bitmaps_LOD.LODFile_LoadTexture( (const char *)(v2 + 128), 0);
  v8 = *(_DWORD *)(v2 + 232) == -1;
  *(_DWORD *)(v2 + 236) = result;
  if ( v8 )
    erroneous_printf("Invalid Sky Tex Handle");
  if ( *(_DWORD *)(v2 + 236) == -1 )
    erroneous_printf("Invalid Ground Tex Handle");
  return result;
}



