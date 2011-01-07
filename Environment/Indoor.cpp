#include <windows.h>

#include "Indoor.h"
#include "..\mm7_unparsed_data.h"
#include "..\Memory_mng.h"
#include "..\_lod.h"
#include "..\menus.h"
#include "..\AudioPlayer.h"
#include "..\Events.h"



//----- (00498B15) --------------------------------------------------------
Result::Code IndoorLocation::Clear()
{
 if (pVertices)
 {
  MemFree(pVertices);
  pVertices = nullptr;
 }
 uNumVertices = 0;

 if (pFaces)
 {
  MemFree(pFaces);
  pFaces = nullptr;
 }
 uNumFaces = 0;

 if (pFaceExtras)
 {
  MemFree(pFaceExtras);
  pFaceExtras = nullptr;
 }
 uNumFaceExtras = 0;

 if (pSectors)
 {
  MemFree(pSectors);
  pSectors = nullptr;
 }
 uNumSectors = 0;

 if (pLights)
 {
  MemFree(pLights);
  pLights = nullptr;
 }
 uNumLights = 0;


 if (pDoors)
 {
  MemFree(pDoors);
  pDoors = nullptr;
 }
 uNumDoors = 0;

 if (pNodes)
 {
  MemFree(pNodes);
  pNodes = nullptr;
 }
 uNumNodes = 0;

 if (ptr_0002A8)
 {
  MemFree(ptr_0002A8);
  ptr_0002A8 = nullptr;
 }

 if (ptr_0002AC)
 {
  MemFree(ptr_0002AC);
  ptr_0002AC = nullptr;
 }

 if (ptr_0002B0_sector_rdata)
 {
  MemFree(ptr_0002B0_sector_rdata);
  ptr_0002B0_sector_rdata = nullptr;
 }

 if (ptr_0002B4_doors_ddata)
 {
  MemFree(ptr_0002B4_doors_ddata);
  ptr_0002B4_doors_ddata = nullptr;
 }

 if (ptr_0002B8_sector_lrdata)
 {
  MemFree(ptr_0002B8_sector_lrdata);
  ptr_0002B8_sector_lrdata = nullptr;
 }

 if (pSpawnPoints)
 {
  MemFree(pSpawnPoints);
  pSpawnPoints = nullptr;
 }
 uNumSpawnPoints = 0;


 bLoaded = false;

 return Result::Success;
}



//----- (00498E0A) --------------------------------------------------------
Result::Code IndoorLocation::Load(const char *pLevelFilename, int a3, int a5)
{
  signed int result; // eax@3
  FILE *v8; // edi@3
  int v9; // ecx@4
  int v10; // eax@4
  unsigned __int8 v11; // zf@4
  unsigned __int8 v12; // sf@4
  int v13; // eax@5
  int v14; // ecx@6
  int v15; // ecx@6
  int v16; // edx@6
  int v17; // ecx@6
  int v18; // ecx@6
  int v19; // edx@6
  int v20; // edx@6
  int v21; // edx@6
  int v22; // edx@6
  __int16 v23; // cx@10
  __int16 v24; // ax@10
  int v25; // ecx@10
  __int16 v26; // ax@11
  int v27; // ecx@11
  __int16 v28; // ax@17
  int v29; // ecx@17
  int v30; // edx@17
  int v31; // ecx@20
  int v32; // eax@25
  unsigned __int8 v33; // zf@25
  unsigned __int8 v34; // sf@25
  int v35; // eax@26
  int v36; // edx@27
  int v37; // ecx@27
  int v38; // ecx@27
  int v39; // edx@27
  int v40; // ecx@27
  int v41; // ecx@27
  int v42; // edx@27
  int v43; // edx@27
  int v44; // edx@27
  int v45; // edx@27
  int v46; // edx@27
  int v47; // ecx@27
  int v48; // edx@27
  int v49; // eax@28
  unsigned __int8 v50; // zf@28
  unsigned __int8 v51; // sf@28
  int v52; // eax@29
  int v53; // ecx@29
  int v54; // edx@31
  int v55; // eax@32
  unsigned __int8 v56; // zf@32
  unsigned __int8 v57; // sf@32
  int v58; // eax@33
  int v59; // edx@34
  int v60; // ecx@34
  int v61; // ecx@34
  int v62; // edx@34
  int v63; // ecx@34
  int v64; // ecx@34
  int v65; // edx@34
  int v66; // edx@34
  int v67; // edx@34
  int v68; // edx@34
  int v69; // edx@34
  int v70; // ecx@34
  int v71; // ecx@36
  int j; // eax@37
  int v73; // edx@38
  int v74; // ecx@38
  int v75; // edx@38
  int v76; // ecx@38
  int v77; // edx@38
  int v78; // eax@38
  __int16 v79; // ax@42
  int v80; // ecx@42
  _UNKNOWN *v81; // ecx@44
  int v82; // eax@45
  unsigned __int8 v83; // zf@45
  unsigned __int8 v84; // sf@45
  int k; // edx@46
  __int16 v86; // ax@50
  int v88; // eax@52
  void **v89; // esi@52
  void *v93; // eax@67
  size_t v95; // edi@67
  int v96; // eax@71
  const char *v99; // ebx@72
  int v111; // edx@73
  size_t v173; // ebx@109
  int v174; // eax@114
  int v175; // ecx@116
  int v176; // eax@117
  int v178; // eax@130
  char v179; // zf@132
  size_t v180; // ebx@134
  int v181; // eax@138
  char v235[876]; // [sp+Ch] [bp-65Ch]@130
  char FileName; // [sp+378h] [bp-2F0h]@1
  char DstBuf; // [sp+47Ch] [bp-1ECh]@4
  __int32 Offset; // [sp+480h] [bp-1E8h]@4
  __int32 v239; // [sp+48Ch] [bp-1DCh]@4
  __int32 v240; // [sp+498h] [bp-1D0h]@4
  __int32 v241; // [sp+4A4h] [bp-1C4h]@4
  __int32 v242; // [sp+4B0h] [bp-1B8h]@4
  __int32 v243; // [sp+4BCh] [bp-1ACh]@15
  __int32 v244; // [sp+4C8h] [bp-1A0h]@15
  __int32 v245; // [sp+4D4h] [bp-194h]@25
  __int32 v246; // [sp+4E0h] [bp-188h]@25
  __int32 v247; // [sp+4ECh] [bp-17Ch]@32
  __int32 v248; // [sp+4F8h] [bp-170h]@32
  __int32 v249; // [sp+504h] [bp-164h]@40
  __int32 v250; // [sp+510h] [bp-158h]@40
  __int32 v251; // [sp+51Ch] [bp-14Ch]@43
  __int32 v252; // [sp+528h] [bp-140h]@43
  __int32 v253; // [sp+534h] [bp-134h]@52
  __int32 v254; // [sp+540h] [bp-128h]@52
  __int32 v255; // [sp+54Ch] [bp-11Ch]@52
  __int32 v256; // [sp+558h] [bp-110h]@52
  __int32 v257; // [sp+564h] [bp-104h]@52
  __int32 v258; // [sp+570h] [bp-F8h]@52
  __int32 v259; // [sp+57Ch] [bp-ECh]@52
  __int32 v260; // [sp+588h] [bp-E0h]@52
  __int32 v261; // [sp+594h] [bp-D4h]@52
  __int32 v262; // [sp+5A0h] [bp-C8h]@52
  __int32 v263; // [sp+5ACh] [bp-BCh]@52
  __int32 v264; // [sp+5B8h] [bp-B0h]@52
  __int32 v265; // [sp+5C4h] [bp-A4h]@52
  __int32 v266; // [sp+5D0h] [bp-98h]@52
  size_t ElementSize; // [sp+624h] [bp-44h]@67
  char Dst[12]; // [sp+628h] [bp-40h]@9

  struct maybe_blv_header
  {
   int v271; // [sp+B58h] [bp-28h]@50
   unsigned int magic;  // "MVII" for mm7
   unsigned int uCompressedSize; // [sp+B60h] [bp-20h]@50
   unsigned int uUncompressedSize; // [sp+B64h] [bp-1Ch]@50
  } v271;
  size_t Count; // [sp+64Ch] [bp-1Ch]@109
  __int64 v280; // [sp+650h] [bp-18h]@66
  FILE *File; // [sp+658h] [bp-10h]@56
  int v282; // [sp+65Ch] [bp-Ch]@72
  void *Src; // [sp+664h] [bp-4h]@73
  int v285; // [sp+670h] [bp+8h]@4
  int v286; // [sp+670h] [bp+8h]@7
  int v287; // [sp+670h] [bp+8h]@15
  int v288; // [sp+670h] [bp+8h]@18
  int v289; // [sp+670h] [bp+8h]@25
  int v290; // [sp+670h] [bp+8h]@28
  int v291; // [sp+670h] [bp+8h]@32
  int v292; // [sp+670h] [bp+8h]@35
  signed int v293; // [sp+670h] [bp+8h]@40
  int v294; // [sp+670h] [bp+8h]@45
  int v298; // [sp+670h] [bp+8h]@172

  dword_6807E0 = 0;

#pragma region
  /*wsprintfA(&FileName, "levels\\%s", Args);
  if ( _access(&FileName, 4) != -1 )
  {
    IndoorLocation_sub_498B15(v6);
    if ( IndoorLocation_sub_498C45(v6) )
    {
      v8 = fopen(&FileName, "rb");
      result = 1;
      if ( !v8 )
        return result;
      v9 = a5;
      *(_DWORD *)(v6 + 80) = 1;
      v234 = (int)v8;
      v233 = 1;
      *(_DWORD *)v9 = 1;
      locked_fread(&DstBuf, 0x180u, v233, (FILE *)v234);
      fseek(v8, Offset, 0);
      locked_fread((void *)(v6 + 488), 0x88u, 1u, v8);
      fseek(v8, v239, 0);
      locked_fread((void *)(v6 + 624), 1u, 4u, v8);
      fseek(v8, v240, 0);
      locked_fread(*(void **)(v6 + 628), 6u, *(_DWORD *)(v6 + 624), v8);
      fseek(v8, v241, 0);
      locked_fread((void *)(v6 + 632), 4u, 1u, v8);
      fseek(v8, v242, 0);
      locked_fread(*(void **)(v6 + 636), 0x60u, *(_DWORD *)(v6 + 632), v8);
      v10 = mem_mng.AllocatedNamedBuffer( *(_DWORD *)(v6 + 684), *(_DWORD *)(v6 + 592), "L.FData");
      v234 = (int)v8;
      *(_DWORD *)(v6 + 684) = v10;
      locked_fread((void *)v10, 1u, *(_DWORD *)(v6 + 592), (FILE *)v234);
      v11 = *(_DWORD *)(v6 + 632) == 0;
      v12 = *(_DWORD *)(v6 + 632) < 0;
      a5 = 0;
      v285 = 0;
      if ( !(v12 | v11) )
      {
        v13 = 0;
        do
        {
          *(_DWORD *)(*(_DWORD *)(v6 + 636) + v13 + 48) = a5 + *(_DWORD *)(v6 + 684);
          v14 = v13 + *(_DWORD *)(v6 + 636);
          i = v14;
          v15 = a5 + 2 * *(_BYTE *)(v14 + 93) + 2;
          v16 = v15 + *(_DWORD *)(v6 + 684);
          a5 = v15;
          *(_DWORD *)(i + 52) = v16;
          v17 = v13 + *(_DWORD *)(v6 + 636);
          i = v17;
          v18 = a5 + 2 * *(_BYTE *)(v17 + 93) + 2;
          v19 = v18 + *(_DWORD *)(v6 + 684);
          a5 = v18;
          *(_DWORD *)(i + 56) = v19;
          i = v13 + *(_DWORD *)(v6 + 636);
          v20 = *(_DWORD *)(v6 + 684);
          a5 += 2 * *(_BYTE *)(i + 93) + 2;
          *(_DWORD *)(i + 60) = a5 + v20;
          i = v13 + *(_DWORD *)(v6 + 636);
          v21 = *(_DWORD *)(v6 + 684);
          a5 += 2 * *(_BYTE *)(i + 93) + 2;
          *(_DWORD *)(i + 64) = a5 + v21;
          i = v13 + *(_DWORD *)(v6 + 636);
          v13 += 96;
          v22 = *(_DWORD *)(v6 + 684);
          a5 += 2 * *(_BYTE *)(i + 93) + 2;
          ++v285;
          *(_DWORD *)(i + 68) = a5 + v22;
          a5 += 2 * *(_BYTE *)(*(_DWORD *)(v6 + 636) + v13 - 3) + 2;
        }
        while ( v285 < *(_DWORD *)(v6 + 632) );
      }
      v286 = 0;
      if ( *(_DWORD *)(v6 + 632) > 0 )
      {
        a5 = 0;
        do
        {
          locked_fread(&Dst, 1u, 0xAu, v8);
          if ( *(_BYTE *)(a5 + *(_DWORD *)(v6 + 636) + 45) & 0x40 )
          {
            v24 = TextureFrameTable_sub_44E163(pTextureFrameTable, &Dst);
            v25 = a5;
            *(_WORD *)(a5 + *(_DWORD *)(v6 + 636) + 74) = v24;
            v23 = *(_WORD *)(v25 + *(_DWORD *)(v6 + 636) + 74);
            if ( v23 )
            {
              TextureFrameTable_sub_44E0ED(pTextureFrameTable, v23);
            }
            else
            {
              v26 = LODFile_Icons_LOD.LODFile_LoadTexture((int)&unk_6F0E80, &Dst, 0);
              v27 = a5;
              *(_WORD *)(a5 + *(_DWORD *)(v6 + 636) + 74) = v26;
              *(_BYTE *)(v27 + *(_DWORD *)(v6 + 636) + 45) &= 0xBFu;
            }
          }
          else
          {
            *(_WORD *)(a5 + *(_DWORD *)(v6 + 636) + 74) = LODFile_Icons_LOD.LODFile_LoadTexture((int)&unk_6F0E80, &Dst, 0);
          }
          ++v286;
          a5 += 96;
        }
        while ( v286 < *(_DWORD *)(v6 + 632) );
      }
      fseek(v8, v243, 0);
      locked_fread((void *)(v6 + 640), 4u, 1u, v8);
      fseek(v8, v244, 0);
      locked_fread(*(void **)(v6 + 644), 0x24u, *(_DWORD *)(v6 + 640), v8);
      v287 = 0;
      if ( *(_DWORD *)(v6 + 640) > 0 )
      {
        a5 = 0;
        do
        {
          locked_fread(&Dst, 1u, 0xAu, v8);
          v28 = LODFile_Icons_LOD.LODFile_LoadTexture((int)&unk_6F0E80, &Dst, 0);
          v29 = *(_DWORD *)(v6 + 644);
          v30 = a5;
          ++v287;
          a5 += 36;
          *(_WORD *)(v30 + v29 + 14) = v28;
        }
        while ( v287 < *(_DWORD *)(v6 + 640) );
      }
      v288 = 0;
      if ( *(_DWORD *)(v6 + 632) > 0 )
      {
        a5 = 0;
        do
        {
          v31 = *(_DWORD *)(v6 + 644) + 36 * *(_WORD *)(a5 + *(_DWORD *)(v6 + 636) + 72);
          if ( *(_WORD *)(v31 + 26) )
          {
            if ( sub_44C23B(v31) )
              *(_BYTE *)(a5 + *(_DWORD *)(v6 + 636) + 46) |= 0x10u;
            else
              *(_BYTE *)(a5 + *(_DWORD *)(v6 + 636) + 46) &= 0xEFu;
          }
          ++v288;
          a5 += 96;
        }
        while ( v288 < *(_DWORD *)(v6 + 632) );
      }
      fseek(v8, v245, 0);
      locked_fread((void *)(v6 + 648), 4u, 1u, v8);
      fseek(v8, v246, 0);
      locked_fread(*(void **)(v6 + 652), 0x74u, *(_DWORD *)(v6 + 648), v8);
      v32 = mem_mng.AllocatedNamedBuffer( *(_DWORD *)(v6 + 688), *(_DWORD *)(v6 + 596), "L.RData");
      v234 = (int)v8;
      *(_DWORD *)(v6 + 688) = v32;
      locked_fread((void *)v32, 1u, *(_DWORD *)(v6 + 596), (FILE *)v234);
      v33 = *(_DWORD *)(v6 + 648) == 0;
      v34 = *(_DWORD *)(v6 + 648) < 0;
      a5 = 0;
      v289 = 0;
      if ( !(v34 | v33) )
      {
        v35 = 0;
        do
        {
          *(_DWORD *)(v35 + *(_DWORD *)(v6 + 652) + 8) = a5 + *(_DWORD *)(v6 + 688);
          i = v35 + *(_DWORD *)(v6 + 652);
          v36 = *(_DWORD *)(v6 + 688);
          a5 += 2 * *(_WORD *)(i + 4);
          *(_DWORD *)(i + 16) = a5 + v36;
          v37 = v35 + *(_DWORD *)(v6 + 652);
          i = v37;
          v38 = a5 + 2 * *(_WORD *)(v37 + 12);
          v39 = v38 + *(_DWORD *)(v6 + 688);
          a5 = v38;
          *(_DWORD *)(i + 24) = v39;
          v40 = v35 + *(_DWORD *)(v6 + 652);
          i = v40;
          v41 = a5 + 2 * *(_WORD *)(v40 + 20);
          v42 = v41 + *(_DWORD *)(v6 + 688);
          a5 = v41;
          *(_DWORD *)(i + 32) = v42;
          i = v35 + *(_DWORD *)(v6 + 652);
          v43 = *(_DWORD *)(v6 + 688);
          a5 += 2 * *(_WORD *)(i + 28);
          *(_DWORD *)(i + 40) = a5 + v43;
          i = v35 + *(_DWORD *)(v6 + 652);
          v44 = *(_DWORD *)(v6 + 688);
          a5 += 2 * *(_WORD *)(i + 36);
          *(_DWORD *)(i + 48) = a5 + v44;
          i = v35 + *(_DWORD *)(v6 + 652);
          v45 = *(_DWORD *)(v6 + 688);
          a5 += 2 * *(_WORD *)(i + 44);
          *(_DWORD *)(i + 64) = a5 + v45;
          i = v35 + *(_DWORD *)(v6 + 652);
          v46 = *(_DWORD *)(v6 + 688);
          a5 += 2 * *(_WORD *)(i + 60);
          *(_DWORD *)(i + 72) = a5 + v46;
          v47 = v35 + *(_DWORD *)(v6 + 652);
          v35 += 116;
          i = v47;
          v48 = *(_DWORD *)(v6 + 688);
          a5 += 2 * *(_WORD *)(v47 + 68);
          ++v289;
          *(_DWORD *)(v47 + 80) = a5 + v48;
          a5 += 2 * *(_WORD *)(v35 + *(_DWORD *)(v6 + 652) - 40);
        }
        while ( v289 < *(_DWORD *)(v6 + 648) );
      }
      v49 = mem_mng.AllocatedNamedBuffer( *(_DWORD *)(v6 + 696), *(_DWORD *)(v6 + 600), "L.RLData");
      v234 = (int)v8;
      *(_DWORD *)(v6 + 696) = v49;
      locked_fread((void *)v49, 1u, *(_DWORD *)(v6 + 600), (FILE *)v234);
      v50 = *(_DWORD *)(v6 + 648) == 0;
      v51 = *(_DWORD *)(v6 + 648) < 0;
      a5 = 0;
      v290 = 0;
      if ( !(v51 | v50) )
      {
        v52 = *(_DWORD *)(v6 + 652);
        v53 = 0;
        for ( i = 0; ; v53 = i )
        {
          v54 = *(_DWORD *)(v6 + 696);
          i += 116;
          ++v290;
          *(_DWORD *)(v53 + v52 + 88) = a5 + v54;
          v52 = *(_DWORD *)(v6 + 652);
          a5 += 2 * *(_WORD *)(v53 + v52 + 84);
          if ( v290 >= *(_DWORD *)(v6 + 648) )
            break;
        }
      }
      fseek(v8, v247, 0);
      locked_fread((void *)(v6 + 664), 4u, 1u, v8);
      fseek(v8, v248, 0);
      locked_fread(*(void **)(v6 + 668), 0x50u, 0xC8u, v8);
      v55 = mem_mng.AllocatedNamedBuffer( *(_DWORD *)(v6 + 692), *(_DWORD *)(v6 + 604), "L.DData");
      v234 = (int)v8;
      *(_DWORD *)(v6 + 692) = v55;
      locked_fread((void *)v55, 1u, *(_DWORD *)(v6 + 604), (FILE *)v234);
      v56 = *(_DWORD *)(v6 + 664) == 0;
      v57 = *(_DWORD *)(v6 + 664) < 0;
      a5 = 0;
      v291 = 0;
      if ( !(v57 | v56) )
      {
        v58 = 0;
        do
        {
          *(_DWORD *)(v58 + *(_DWORD *)(v6 + 668) + 36) = a5 + *(_DWORD *)(v6 + 692);
          i = v58 + *(_DWORD *)(v6 + 668);
          v59 = *(_DWORD *)(v6 + 692);
          a5 += 2 * *(_WORD *)(i + 68);
          *(_DWORD *)(i + 40) = a5 + v59;
          v60 = v58 + *(_DWORD *)(v6 + 668);
          i = v60;
          v61 = a5 + 2 * *(_WORD *)(v60 + 70);
          v62 = v61 + *(_DWORD *)(v6 + 692);
          a5 = v61;
          *(_DWORD *)(i + 44) = v62;
          v63 = v58 + *(_DWORD *)(v6 + 668);
          i = v63;
          v64 = a5 + 2 * *(_WORD *)(v63 + 72);
          v65 = v64 + *(_DWORD *)(v6 + 692);
          a5 = v64;
          *(_DWORD *)(i + 48) = v65;
          i = v58 + *(_DWORD *)(v6 + 668);
          v66 = *(_DWORD *)(v6 + 692);
          a5 += 2 * *(_WORD *)(i + 70);
          *(_DWORD *)(i + 52) = a5 + v66;
          i = v58 + *(_DWORD *)(v6 + 668);
          v67 = *(_DWORD *)(v6 + 692);
          a5 += 2 * *(_WORD *)(i + 70);
          *(_DWORD *)(i + 56) = a5 + v67;
          i = v58 + *(_DWORD *)(v6 + 668);
          v68 = *(_DWORD *)(v6 + 692);
          a5 += 2 * *(_WORD *)(i + 74);
          *(_DWORD *)(i + 60) = a5 + v68;
          i = v58 + *(_DWORD *)(v6 + 668);
          v69 = *(_DWORD *)(v6 + 692);
          a5 += 2 * *(_WORD *)(i + 74);
          *(_DWORD *)(i + 64) = a5 + v69;
          ++v291;
          v70 = *(_WORD *)(v58 + *(_DWORD *)(v6 + 668) + 74);
          v58 += 80;
          a5 += 2 * v70;
        }
        while ( v291 < *(_DWORD *)(v6 + 664) );
      }
      v292 = 0;
      if ( *(_DWORD *)(v6 + 664) > 0 )
      {
        v71 = *(_DWORD *)(v6 + 668);
        a5 = 0;
        do
        {
          i = 0;
          for ( j = v71 + a5; i < *(_WORD *)(v71 + a5 + 70); j = v71 + a5 )
          {
            v73 = *(_DWORD *)(j + 40);
            a3 = 2 * i;
            v74 = *(_WORD *)(v73 + 2 * i);
            v75 = *(_DWORD *)(v6 + 636);
            ++i;
            v76 = *(_DWORD *)(v6 + 644) + 36 * *(_WORD *)(96 * v74 + v75 + 72);
            v77 = *(_DWORD *)(j + 48);
            v78 = a3;
            v270 = (char *)v76;
            *(_WORD *)(a3 + v77) = *(_WORD *)(v76 + 20);
            *(_WORD *)(v78 + *(_DWORD *)(*(_DWORD *)(v6 + 668) + a5 + 52)) = *((_WORD *)v270 + 11);
            v71 = *(_DWORD *)(v6 + 668);
          }
          ++v292;
          a5 += 80;
        }
        while ( v292 < *(_DWORD *)(v6 + 664) );
      }
      fseek(v8, v249, 0);
      locked_fread(&uNumLevelDecorations, 4u, 1u, v8);
      fseek(v8, v250, 0);
      locked_fread(word_6836D0, 0x20u, uNumLevelDecorations, v8);
      v293 = 0;
      if ( (signed int)uNumLevelDecorations > 0 )
      {
        a5 = (int)word_6836D0;
        do
        {
          locked_fread(&Str1, 1u, 0x20u, v8);
          v79 = DecorationList_FindDecoration(pDecorationDescriptionList, &Str1);
          v80 = a5;
          ++v293;
          a5 += 32;
          *(_WORD *)v80 = v79;
        }
        while ( v293 < (signed int)uNumLevelDecorations );
      }
      fseek(v8, v251, 0);
      locked_fread(&::Count, 4u, 1u, v8);
      fseek(v8, v252, 0);
      locked_fread(pLayingItemsList, 0x70u, ::Count, v8);
      if ( (signed int)::Count > 0 )
      {
        v81 = pLayingItemsList;
        a5 = ::Count;
        do
        {
          v294 = 0;
          v82 = 48 * *((_DWORD *)v81 + 9);
          v83 = pObjectDescriptionList->uNumObjects == 0;
          v84 = pObjectDescriptionList->uNumObjects < 0;
          LOWORD(v82) = *(__int16 *)((char *)&pClass40->pItems[0].uSpriteIndex + v82);
          i = v82;
          *(_WORD *)v81 = v82;
          if ( v84 | v83 )
          {
LABEL_50:
            v86 = 0;
          }
          else
          {
            for ( k = pObjectDescriptionList->pDescriptions + 32; (_WORD)v82 != *(_WORD *)k; k = a3 )
            {
              ++v294;
              a3 = k + 56;
              if ( v294 >= pObjectDescriptionList->uNumObjects )
                goto LABEL_50;
              LOWORD(v82) = i;
            }
            v86 = v294;
          }
          *((_WORD *)v81 + 1) = v86;
          v81 = (char *)v81 + 112;
        }
        while ( a5-- != 1 );
      }
      fseek(v8, v253, 0);
      locked_fread(&uNumActors, 4u, 1u, v8);
      fseek(v8, v254, 0);
      locked_fread(pActors, 0x344u, uNumActors, v8);
      fseek(v8, v260, 0);
      locked_fread(&dword_5FF140, 4u, 1u, v8);
      fseek(v8, v261, 0);
      locked_fread(array_5E5150, 0x14CCu, dword_5FF140, v8);
      fseek(v8, v256, 0);
      locked_fread((void *)(v6 + 656), 4u, 1u, v8);
      fseek(v8, v257, 0);
      locked_fread(*(void **)(v6 + 660), 0x10u, *(_DWORD *)(v6 + 656), v8);
      fseek(v8, v258, 0);
      locked_fread((void *)(v6 + 672), 4u, 1u, v8);
      fseek(v8, v259, 0);
      locked_fread(*(void **)(v6 + 676), 8u, *(_DWORD *)(v6 + 672), v8);
      fseek(v8, v262, 0);
      locked_fread((void *)(v6 + 700), 4u, 1u, v8);
      v88 = mem_mng.AllocatedNamedBuffer( *(_DWORD *)(v6 + 704), 24 * *(_DWORD *)(v6 + 700), "Spawn");
      v234 = 0;
      *(_DWORD *)(v6 + 704) = v88;
      fseek(v8, v263, v234);
      locked_fread(*(void **)(v6 + 704), 0x18u, *(_DWORD *)(v6 + 700), v8);
      fseek(v8, v264, 0);
      locked_fread((void *)(v6 + 708), 0x28u, 1u, v8);
      fseek(v8, v265, 0);
      locked_fread(byte_5E4C90, 1u, 0xC8u, v8);
      fseek(v8, v266, 0);
      locked_fread((void *)(v6 + 748), 1u, 0x38u, v8);
      fseek(v8, v255, 0);
      v89 = (void **)(v6 + 680);
      locked_fread(*v89, 4u, 1u, v8);
      locked_fread((char *)*v89 + 4, 0xCu, *(_DWORD *)*v89, v8);
      fclose(v8);
      goto LABEL_179;
    }
    return 4;
  }*/
#pragma endregion на_всякий_случай


  if ( !LODFile_Games_LOD.IsContainerExist(pLevelFilename) )
    erroneous_printf("Unable to find %s in Games.LOD", pLevelFilename);

  File = LODFile_Games_LOD.Find_Container(pLevelFilename, 1);

 if (bLoaded)
   return (Result::Code)3;

  if ( !IndoorLocation_sub_498C45((int)this) )
    return (Result::Code)4;

  v271.v271 = 91969;
  v271.magic = 'IIVM';
  v271.uCompressedSize = 0;
  v271.uUncompressedSize = 0;

  locked_fread(&v271, 0x10u, 1u, File);
  if ( v271.v271 != 91969 || v271.magic != 'iivm' && v271.magic != 'IIVM')
  {
    //Game_sub_40E2C8(&v229, "Can't load file!", (int)((char *)&v280 + 3));
    //sub_466D09(&v278, *(int *)&v229, v230, v231, v232, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Polydata.cpp", 792);
    MessageBoxW(0, L"Can't load file!", 0, 0);
    ExitProcess(0);
  }
  v95 = v271.uCompressedSize;
  ElementSize = v271.uUncompressedSize;
  unsigned char *pRawBLV = MemAlloc(unsigned char, v271.uUncompressedSize);
  v93 = pRawBLV;
  v99 = (char *)v93;
  if ( v95 <= ElementSize )
  {
    if ( v95 == ElementSize )
    {
      locked_fread(v93, ElementSize, 1u, File);
    }
    else
    {
      HIDWORD(v280) = (long)malloc(v95);
      locked_fread((void *)HIDWORD(v280), v95, 1u, File);
      v96 = MemUnzip((void *)v99, (unsigned int *)&ElementSize, (void *)SHIDWORD(v280), v95);
      free((void *)HIDWORD(v280));
    }
  }
  else
  {
    //Game_sub_40E2C8(&v229, "Can't load file!", (int)((char *)&v280 + 3));
    //sub_466D09(&File, *(int *)&v229, v230, v231, v232, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Polydata.cpp", 803);
    MessageBoxW(0, L"Can't load file!", 0, 0);
    ExitProcess(0);
  }

  lstrcpyA(pLocationFileName, pLevelFilename);
 
  bLoaded = true;

  memcpy(&cBLVHeader, (const void *)v99, sizeof(BLVHeader));
  v99 += sizeof(BLVHeader);
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);

  memcpy(&uNumVertices, v99, 4);
  pVertices = NamedMemAlloc(Vec3<short>, uNumVertices, "Indoor Vertices");
  memcpy(pVertices, v99 + 4, uNumVertices * sizeof(Vec3<short>));
  v99 += uNumVertices * sizeof(Vec3<short>) + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);

  memcpy(&uNumFaces, v99, 4);
  pFaces = NamedMemAlloc(BLVFace, uNumFaces, "Indoor Faces");
  memcpy(pFaces, v99 + 4, uNumFaces * sizeof(BLVFace));
  v99 += uNumFaces * sizeof(BLVFace) + 4;

  ptr_0002AC = (unsigned short *)NamedMemAlloc(char, cBLVHeader.dword_000068_sizeof_faces_fdata, "L.FData");
  memcpy(ptr_0002AC, v99, cBLVHeader.dword_000068_sizeof_faces_fdata);
  v99 += cBLVHeader.dword_000068_sizeof_faces_fdata;

 for (unsigned int i = 0, j = 0; i < uNumFaces; ++i)
 {
  BLVFace *pFace = pFaces + i;

  pFace->pVertexIDs = ptr_0002AC + j;

  j += pFace->uNumVertices + 1;
  pFace->pXInterceptDisplacements = ptr_0002AC + j;

  j += pFace->uNumVertices + 1;
  pFace->pYInterceptDisplacements = ptr_0002AC + j;

  j += pFace->uNumVertices + 1;
  pFace->pZInterceptDisplacements = ptr_0002AC + j;

  j += pFace->uNumVertices + 1;
  pFace->pVertexUIDs = ptr_0002AC + j;

  j += pFace->uNumVertices + 1;
  pFace->pVertexVIDs = ptr_0002AC + j;

  j += pFace->uNumVertices + 1;
 }


 for (unsigned int i = 0; i < uNumFaces; ++i)
 {
  BLVFace *pFace = pFaces + i;

  if (pFace->uAttributes & 0x4000)
  {
   pFace->uBitmapID = TextureFrameTable_sub_44E163(pTextureFrameTable, v99);
   if (pFace->uBitmapID)
     TextureFrameTable_sub_44E0ED(pTextureFrameTable, pFace->uBitmapID);
   else
   {
    pFace->uBitmapID = LODFile_Bitmaps_LOD.LODFile_LoadTexture(v99, 0);
    pFace->uAttributes &= ~0x4000;
   }
  }
  else
    pFace->uBitmapID  = LODFile_Bitmaps_LOD.LODFile_LoadTexture(v99, 0);

  v99 += 10;
 }




  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  memcpy(&uNumFaceExtras, v99, 4);
  pFaceExtras = NamedMemAlloc(BLVFaceExtra, uNumFaceExtras, "L.FX");
  memcpy(pFaceExtras, v99 + 4, uNumFaceExtras * sizeof(BLVFaceExtra));
  v99 += uNumFaceExtras * sizeof(BLVFaceExtra) + 4;


 for (unsigned int i = 0; i < uNumFaceExtras; ++i)
 {
  if (!_strcmpi(v99, ""))
    pFaceExtras[i].uAdditionalBitmapID = -1;
  else
    pFaceExtras[i].uAdditionalBitmapID = LODFile_Bitmaps_LOD.LODFile_LoadTexture(v99, 0);

  v99 += 10;
 }



 for (unsigned int i = 0; i < uNumFaces; ++i)
 {
  BLVFace      *pFace = pFaces + i;
  BLVFaceExtra *pFaceExtra = pFaceExtras + pFace->uFaceExtraID;

  if (pFaceExtra->uEventID)
  {
   if (sub_44C23B(pFaceExtra))
     pFace->uAttributes |= 0x100000;
   else
     pFace->uAttributes &= ~0x100000;
  }
 }

  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
 memcpy(&uNumSectors, v99, 4);
 pSectors = NamedMemAlloc(BLVSector, uNumSectors, "L.R/Indoor Sectors");
 memcpy(pSectors, v99 + 4, uNumSectors * sizeof(BLVSector));
 v99 += uNumSectors * sizeof(BLVSector) + 4;

 ptr_0002B0_sector_rdata = (unsigned short *)NamedMemAlloc(unsigned char, cBLVHeader.dword_00006C_sizeof_sector_rdata, "L.RData");
 memcpy(ptr_0002B0_sector_rdata, v99, cBLVHeader.dword_00006C_sizeof_sector_rdata);
 v99 += cBLVHeader.dword_00006C_sizeof_sector_rdata;

 for (unsigned int i = 0, j = 0; i < uNumSectors; ++i)
 {
  BLVSector *pSector = pSectors + i;

  pSector->ptr_000008 = ptr_0002B0_sector_rdata + j;

  j += pSector->word_000004;
  pSector->ptr_000010 = ptr_0002B0_sector_rdata + j;

  j += pSector->word_00000C;
  pSector->ptr_000018 = ptr_0002B0_sector_rdata + j;

  j += pSector->word_000014;
  pSector->ptr_000020 = ptr_0002B0_sector_rdata + j;

  j += pSector->word_00001C;
  pSector->ptr_000028 = ptr_0002B0_sector_rdata + j;

  j += pSector->word_000024;
  pSector->pSomeFaceIDs = ptr_0002B0_sector_rdata + j;

  j += pSector->word_00002C;
  pSector->ptr_000040 = ptr_0002B0_sector_rdata + j;

  j += pSector->word_00003C;
  pSector->ptr_000048 = ptr_0002B0_sector_rdata + j;

  j += pSector->word_000044;
  pSector->ptr_000050 = ptr_0002B0_sector_rdata + j;

  j += pSector->word_00004C;
 }

 ptr_0002B8_sector_lrdata = (unsigned short *)NamedMemAlloc(unsigned char, cBLVHeader.dword_000070_sizeof_sector_lrdata, "L.RLData/Indoor Sectors");
 memcpy(ptr_0002B8_sector_lrdata, v99, cBLVHeader.dword_000070_sizeof_sector_lrdata);
 v99 += cBLVHeader.dword_000070_sizeof_sector_lrdata;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);

 for (unsigned int i = 0, j = 0; i < uNumSectors; ++i)
 {
  pSectors->ptr_000058 = ptr_0002B8_sector_lrdata + j;

  j += pSectors->word_000054;
 }


 //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
 memcpy(&uNumDoors, v99, 4);

  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
 memcpy(&uNumLevelDecorations, v99 + 4, 4);
 memcpy(pLevelDecorations, v99 + 8, uNumLevelDecorations * sizeof(LevelDecoration));
 v99 += uNumLevelDecorations * sizeof(LevelDecoration) + 8;

 for (unsigned int i = 0; i < uNumLevelDecorations; ++i)
 {
  pLevelDecorations[i].uDecorationDescriptionID = DecorationList_FindDecoration(pDecorationDescriptionList, v99);

  v99 += 32;
 }
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);


  memcpy(&uNumLights, v99, 4);
  pLights = NamedMemAlloc(BLVLight, uNumLights, "Indoor lights");
  memcpy(pLights, v99 + 4, uNumLights * sizeof(BLVLight));
  v99 += uNumLights * sizeof(BLVLight) + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);


  memcpy(&uNumNodes, v99, 4);
  pNodes = NamedMemAlloc(BSPModel::BSPNode, uNumNodes, "Indoor BSP Nodes");
  memcpy(pNodes, v99 + 4, uNumNodes * sizeof(BSPModel::BSPNode));
  v99 += uNumNodes * sizeof(BSPModel::BSPNode) + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);

  memcpy(&uNumSpawnPoints, v99, 4);
  pSpawnPoints = NamedMemAlloc(SpawnPointMM7, uNumSpawnPoints, "Indoor Spawn Points");
  memcpy(pSpawnPoints, v99 + 4, uNumSpawnPoints * sizeof(SpawnPointMM7));
  v99 += uNumSpawnPoints * sizeof(SpawnPointMM7) + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);

  unsigned int uNumElements;
  //memcpy(ptr_0002A8, v99, 4);
  memcpy(&uNumElements, v99, 4);
  ptr_0002A8 = NamedMemAlloc(unsigned char, 4 + uNumElements * 12, "Indoor map");
  *(unsigned int *)(ptr_0002A8) = uNumElements;
  memcpy((char *)ptr_0002A8 + 4, v99 + 4, uNumElements * 12);

 MemFree(pRawBLV);



  char pLevelDLVName[256];
  strcpy(pLevelDLVName, pLevelFilename);
  strcpy(pLevelDLVName + strlen(pLevelFilename) - 4, ".dlv");
  FILE *hDLVFile = LODFile_Games_LOD.Find_Container(pLevelDLVName, 1);

  locked_fread(&v271, 0x10u, 1u, hDLVFile);
  v282 = 0;
  if ( v271.v271 != 91969 || v271.magic != 'iivm' && v271.magic != 'IIVM')
  {
    Game_sub_40E2C8(0, "Can't load file!", (int)((char *)&v280 + 3));
    sub_466D09(0, 0, 0, 0, 0, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Polydata.cpp", 1090);
    v282 = 1;
  }
  v173 = v271.uCompressedSize;
  Count = v271.uUncompressedSize;
  Src = 0;
  File = 0;
  if ( !v282 )
  {
    Src = malloc(v271.uUncompressedSize);
    File = (FILE *)Src;
    if ( v173 <= Count )
    {
      if ( v173 == Count )
      {
        locked_fread(Src, 1u, Count, hDLVFile);
      }
      else
      {
        HIDWORD(v280) = (long)malloc(v173);
        locked_fread((void *)HIDWORD(v280), v173, 1u, hDLVFile);
        v174 = MemUnzip(Src, (unsigned int *)&Count, (void *)SHIDWORD(v280), v173);
        free((void *)HIDWORD(v280));
      }
    }
    else
    {
      Game_sub_40E2C8(0, "Can't load file!", (int)((char *)&v280 + 3));
      sub_466D09(0, 0, 0, 0, 0, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Polydata.cpp", 1108);
    }
    memcpy(&cDLVHeader, Src, sizeof(DLVHeader));
    Src = (char *)Src + 40;
  }
  v175 = cDLVHeader.dword_000010;
  if (cDLVHeader.dword_000010)
  {
    v176 = cDLVHeader.dword_000014;
    if (cDLVHeader.dword_000014)
    {
      if ( v175 != pIndoor->uNumFaces || v176 != uNumLevelDecorations )
        v282 = 1;
    }
  }

 unsigned int uRespawnInterval = pMapStats->GetMapInfo(pLevelFilename)->uRespawnInterval;
  if ( BYTE1(dword_6BE364) & 0x20 )
    uRespawnInterval = 29030400;
  HIDWORD(v280) = 0;
  if ( a3 - cDLVHeader.dword_000004 >= (unsigned int)uRespawnInterval )
  {
    if ( _strcmpi(pLevelDLVName, "d29.dlv") )
      HIDWORD(v280) = 1;
  }

  if ( v282 )
  {
    v178 = (int)memset(v235, 0, 0x36B);
    goto LABEL_132;
  }
  if ( HIDWORD(v280) || !cDLVHeader.dword_000004)
  {
    v178 = (int)memcpy(v235, Src, 0x36B);
LABEL_132:
    free((unsigned int *)File);
    v179 = v282 == 1;
    cDLVHeader.dword_000004 = a3;
    if ( v179 )
      ++cDLVHeader.dword_000000;

    *(_DWORD *)a5 = 1;
    hDLVFile = LODFile_Games_LOD.Find_Container(pLevelDLVName, 0);
    locked_fread(&v271, 0x10u, 1u, hDLVFile);
    v180 = v271.uCompressedSize;
    Count = v271.uUncompressedSize;
    Src = malloc(v271.uUncompressedSize);
    File = (FILE *)Src;
    if ( v180 <= Count )
    {
      if ( v180 == Count )
      {
        locked_fread(Src, 1u, Count, hDLVFile);
      }
      else
      {
        HIDWORD(v280) = (long)malloc(v180);
        locked_fread((void *)HIDWORD(v280), v180, 1u, hDLVFile);
        v181 = MemUnzip(Src, (unsigned int *)&Count, (void *)SHIDWORD(v280), v180);
        free((void *)HIDWORD(v280));
      }
    }
    else
    {
      Game_sub_40E2C8(0, "Can't load file!", 0);
      sub_466D09(&a3, 0, 0, 0, 0, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Polydata.cpp", 1195);
    }
    Src = (char *)Src + 40;

    goto LABEL_140;
  }
  *(_DWORD *)a5 = 0;
LABEL_140:

  memcpy(unk_000324, Src, 0x36B);
  v99 = (char *)Src + 0x36B;
  if ( *(_DWORD *)a5 )
    memcpy(unk_000324, v235, 0x36B);


 for (unsigned int i = 0; i < *(unsigned int *)pIndoor->ptr_0002A8; ++i)
 {
  BLVMapVertex *pMapVertex = (BLVMapVertex *)(pIndoor->ptr_0002A8 + 4) + i;

  if ( (unsigned __int8)(1 << (7 - i % 8)) & *(_BYTE *)(i / 8 + unk_000324) )
    pMapVertex->word_00000A |= 1;
 }


 for (unsigned int i = 0; i < uNumFaces; ++i)
 {
  BLVFace      *pFace = pFaces + i;
  BLVFaceExtra *pFaceExtra = pFaceExtras + pFace->uFaceExtraID;

  memcpy(&pFace->uAttributes, v99, 4);
  if (pFaceExtra->uEventID)
  {
   if (sub_44C23B(pFaceExtra))
     pFace->uAttributes |= 0x100000;
   else
     pFace->uAttributes &= ~0x100000;
  }

  v99 += 4;
 }
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);


 for (unsigned int i = 0; i < uNumLevelDecorations; ++i)
 {
  memcpy(&pLevelDecorations[i].word_000002, v99, 2);
  v99 += 2;
 }
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);


 memcpy(&uNumActors, v99, 4);
 memcpy(pActors, v99 + 4, uNumActors * sizeof(Actor));
 v99 += uNumActors * sizeof(Actor) + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);

 memcpy(&uNumLayingItems, v99, 4);
 memcpy(pLayingItemsList, v99 + 4, uNumLayingItems * sizeof(LayingItem));
 v99 += uNumLayingItems * sizeof(LayingItem) + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);



 for (unsigned int i = 0; i < uNumLayingItems; ++i)
 {
  LayingItem *pItem = pLayingItemsList + i;
 
  if (pItem->stru_000024.uItemID && !(pItem->uAttributes & 0x0100))
  {
   pItem->uItemType = pClass40->pItems[pItem->stru_000024.uItemID - 1].uSpriteIndex;

   unsigned int uObjectID = 0;
   for (unsigned int j = 0; j < pObjectDescriptionList->uNumObjects; ++j)
     if (pItem->uItemType == pObjectDescriptionList->pDescriptions[j].word_000020)
     {
      pItem->uObjectDescriptionID = j;
      break;
     }
  }
 }
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);


  memcpy(&dword_5FF140, v99, 4);
  memcpy(array_5E5150, v99 + 4, dword_5FF140 * sizeof(struct3));
  v99 += dword_5FF140 * sizeof(struct3) + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);

  pDoors = NamedMemAlloc(BLVDoor, uNumDoors, "L.D/Indoor Doors");
  memcpy(pDoors, v99, uNumDoors * sizeof(BLVDoor));
  v99 += uNumDoors * sizeof(BLVDoor);

  ptr_0002B4_doors_ddata = (unsigned short *)NamedMemAlloc(unsigned char, cBLVHeader.dword_000074_sizeof_doors_ddata, "L.DData\Indoor");
  memcpy(ptr_0002B4_doors_ddata, v99, cBLVHeader.dword_000074_sizeof_doors_ddata);
  v99 += cBLVHeader.dword_000074_sizeof_doors_ddata;

 for (unsigned int i = 0, j = 0; i < uNumDoors; ++i)
 {
  BLVDoor *pDoor = pDoors + i;

  pDoor->pVertexIDs = ptr_0002B4_doors_ddata + j;
  j += pDoor->uNumVertices;

  pDoor->pFaceIDs = ptr_0002B4_doors_ddata + j;
  j += pDoor->uNumFaces;

  pDoor->ptr_00002C = ptr_0002B4_doors_ddata + j;
  j += pDoor->word_000048;

  pDoor->pDeltaUs = (short *)(ptr_0002B4_doors_ddata + j);
  j += pDoor->uNumFaces;

  pDoor->pDeltaVs = (short *)(ptr_0002B4_doors_ddata + j);
  j += pDoor->uNumFaces;

  pDoor->pXOffsets = ptr_0002B4_doors_ddata + j;
  j += pDoor->uNumOffsets;

  pDoor->pYOffsets = ptr_0002B4_doors_ddata + j;
  j += pDoor->uNumOffsets;

  pDoor->pZOffsets = ptr_0002B4_doors_ddata + j;
  j += pDoor->uNumOffsets;
 }

 for (unsigned int i = 0; i < uNumDoors; ++i)
 {
  BLVDoor *pDoor = pDoors + i;

  for (unsigned int j = 0; j < pDoor->uNumFaces; ++j)
  {
   BLVFace      *pFace = pFaces + pDoor->pFaceIDs[j];
   BLVFaceExtra *pFaceExtra = pFaceExtras + pFace->uFaceExtraID;

   pDoor->pDeltaUs[j] = pFaceExtra->sTextureDeltaU;
   pDoor->pDeltaVs[j] = pFaceExtra->sTextureDeltaV;
  }
 }
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);


 memcpy(&global_5E4C90, v99, 0xC8);
 memcpy(unk_0002EC, v99 + 200, 0x38);
 free((unsigned int *)File);

LABEL_179:
  sub_4A9A67(pSoundList, 64, 0);
  sub_4A9A67(pSoundList, 103, 0);
  sub_4A9A67(pSoundList, 63, 0);
  sub_4A9A67(pSoundList, 102, 0);
  sub_4A9A67(pSoundList, 50, 0);
  sub_4A9A67(pSoundList, 89, 0);

 return Result::Success;
}



IndoorLocation::IndoorLocation():
  uNumVertices(0),    pVertices(nullptr),
  uNumFaces(0),       pFaces(nullptr),
  uNumFaceExtras(0),  pFaceExtras(nullptr),
  uNumSectors(0),     pSectors(nullptr),
  uNumLights(0),      pLights(nullptr),
  uNumSpawnPoints(0), pSpawnPoints(nullptr),
  uNumNodes(0),       pNodes(nullptr),
  uNumDoors(0),       pDoors(nullptr),
  ptr_0002A8(nullptr),
  ptr_0002AC(nullptr),
  ptr_0002B0_sector_rdata(nullptr),
  ptr_0002B4_doors_ddata(nullptr),
  ptr_0002B8_sector_lrdata(nullptr),
  bLoaded(false)
{
}








//----- (00498C45) --------------------------------------------------------
signed int __thiscall IndoorLocation_sub_498C45(int _this)
{
  int v1; // eax@1
  void *v2; // ecx@1
  int v3; // esi@1
  int v5; // ST3C_4@1
  int v7; // ST3C_4@1
  int v8; // eax@1
  int v9; // ST3C_4@1
  int v10; // eax@1
  int v11; // ST3C_4@1
  int v12; // eax@1
  int v13; // ST3C_4@1
  int v14; // eax@1
  int v15; // ST3C_4@1
  int v16; // eax@1
  int v17; // ST3C_4@1
  signed int result; // eax@9

  return true;
/*
  v3 = _this;
  //v4 = (int)mem_mng.AllocatedNamedBuffer((void*) *(_DWORD *)(_this + 628), 90000, "L.V");
  v4 = (int);
  v5 = *(_DWORD *)(v3 + 636);
  _this->pVertices = NamedMemAlloc(Vec3<short>, 15000, "L.V");
  //v6 = (int)mem_mng.AllocatedNamedBuffer(  (void*)v5, 960000, "L.F");
  v7 = *(_DWORD *)(v3 + 644);
  _this->pFaces = NamedMemAlloc(BLVFace, 10000, "L.F");
  //v8 = (int)mem_mng.AllocatedNamedBuffer(  (void*)v7, 180000, "L.FX");
  v8 = (int)NamedMemAlloc(char, 180000, "L.FX");
  v9 = *(_DWORD *)(v3 + 652);
  *(_DWORD *)(v3 + 0x284) = v8;
  //v10 = (int)mem_mng.AllocatedNamedBuffer( (void*) v9, 59392, "L.R");
  v10 = (int)NamedMemAlloc(char, 59392, "L.R");
  v11 = *(_DWORD *)(v3 + 660);
  *(_DWORD *)(v3 + 0x28C) = v10;
  //v12 = (int)mem_mng.AllocatedNamedBuffer( (void*) v11, 6400, "L.L");
  v12 = (int)NamedMemAlloc(char, 6400, "L.L");
  v13 = *(_DWORD *)(v3 + 668);
  *(_DWORD *)(v3 + 0x294) = v12;
  //v14 = (int)mem_mng.AllocatedNamedBuffer(  (void*)v13, 16000, "L.D");
  v14 = (int)NamedMemAlloc(char, 16000, "L.D");
  v15 = *(_DWORD *)(v3 + 676);
  *(_DWORD *)(v3 + 0x29C) = v14;
  //v16 = (int)mem_mng.AllocatedNamedBuffer(  (void*)v15, 40000, "L.BSP");
  v16 = (int)NamedMemAlloc(char, 40000, "L.BSP");
  v17 = *(_DWORD *)(v3 + 680);
  *(_DWORD *)(v3 + 0x2A4) = v16;
  //v1 = (int)mem_mng.AllocatedNamedBuffer(  (void*)v17, 84004, "L.Map");
  v1 = (int)NamedMemAlloc(char, 84004, "L.Map");
  v2 = *(void **)(v3 + 628);
  *(_DWORD *)(v3 + 680) = v1;
  if ( v2
    && *(_DWORD *)(v3 + 636)
    && *(_DWORD *)(v3 + 644)
    && *(_DWORD *)(v3 + 652)
    && *(_DWORD *)(v3 + 660)
    && *(_DWORD *)(v3 + 668)
    && *(_DWORD *)(v3 + 676)
    && v1 )
  {
    memset(v2, 90000, 0);
    memset(*(void **)(v3 + 636), 960000, 0);
    memset(*(void **)(v3 + 644), 180000, 0);
    memset(*(void **)(v3 + 652), 59392, 0);
    memset(*(void **)(v3 + 660), 6400, 0);
    memset(*(void **)(v3 + 668), 16000, 0);
    memset(*(void **)(v3 + 676), 40000, 0);
    memset(*(void **)(v3 + 680), 84004, 0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;*/
}






//----- (0044C23B) --------------------------------------------------------
bool sub_44C23B(BLVFaceExtra *_this)
{
  int v1; // eax@1
  _UNKNOWN *v2; // esi@2
  int v4; // eax@6

  v1 = 0;
  if ( uLevelEVT_NumEvents - 1 <= 0 )
    return false;

  v2 = (char *)pLevelEVT_Events;
  while ( *(_DWORD *)v2 != _this->uEventID )
  {
    ++v1;
    v2 = (char *)v2 + 12;
    if ( v1 >= uLevelEVT_NumEvents - 1 )
      return false;
  }
  v4 = 12 * v1;
  if (pLevelEVT[*(int *)((char *)&pLevelEVT_Events[1].uEventOffsetInEVT + v4) + 4] != 1 ||
      pLevelEVT[*(int *)((char *)&pLevelEVT_Events[0].uEventOffsetInEVT + v4) + 4] != 4 )
    return false;
 return true;
}
