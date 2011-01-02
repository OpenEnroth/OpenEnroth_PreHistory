#include <windows.h>

#include "Indoor.h"
#include "..\mm7_unparsed_data.h"
#include "..\Memory_mng.h"
#include "..\_lod.h"
#include "..\menus.h"
#include "..\AudioPlayer.h"



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

 if (ptr_0000284)
 {
  MemFree(ptr_0000284);
  ptr_0000284 = nullptr;
 }

 dword_000288 = 0;

 if (ptr_000028C)
 {
  MemFree(ptr_000028C);
  ptr_000028C = nullptr;
 }

 dword_000290 = 0;

 if (ptr_0000294)
 {
  MemFree(ptr_0000294);
  ptr_0000294 = nullptr;
 }

 dword_000298 = 0;

 if (ptr_000029C)
 {
  MemFree(ptr_000029C);
  ptr_000029C = nullptr;
 }

 dword_0002A0 = 0;

 if (pNodes)
 {
  MemFree(pNodes);
  pNodes = nullptr;
 }

 if (ptr_00002A8)
 {
  MemFree(ptr_00002A8);
  ptr_00002A8 = nullptr;
 }

 if (ptr_00002AC)
 {
  MemFree(ptr_00002AC);
  ptr_00002AC = nullptr;
 }

 if (ptr_00002B0)
 {
  MemFree(ptr_00002B0);
  ptr_00002B0 = nullptr;
 }

 if (ptr_00002B4)
 {
  MemFree(ptr_00002B4);
  ptr_00002B4 = nullptr;
 }

 if (ptr_00002B8)
 {
  MemFree(ptr_00002B8);
  ptr_00002B8 = nullptr;
 }

 if (ptr_00002C0)
 {
  MemFree(ptr_00002C0);
  ptr_00002C0 = nullptr;
 }

 bLoaded = false;

 return Result::Success;
}



//----- (00498E0A) --------------------------------------------------------
Result::Code IndoorLocation::Load(const char *pLevelFilename, int a3, int a5)
{
  int v5; // ebx@1
  //int v6; // esi@1
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
  //size_t v90; // eax@56
  //int v91; // eax@56
  void *v93; // eax@67
  //int v94; // ebx@67
  size_t v95; // edi@67
  int v96; // eax@71
  int v97; // eax@72
  const void *v98; // ebx@72
  const char *v99; // ebx@72
  //const void *v100; // ebx@72
  //const void *v101; // ebx@72
  //int v102; // eax@72
  //size_t v103; // ecx@72
  //unsigned __int8 v104; // zf@72
  //unsigned __int8 v105; // sf@72
  int v106; // ecx@73
  int v107; // ecx@73
  int v108; // edx@73
  int v109; // ecx@73
  int v110; // ecx@73
  int v111; // edx@73
  int v112; // edx@73
  int v113; // edx@73
  int v114; // edx@73
  unsigned __int8 v115; // zf@74
  unsigned __int8 v116; // sf@74
  __int16 v117; // ax@77
  __int16 v118; // ax@77
  int v119; // ecx@77
  __int16 v120; // ax@78
  int v121; // ecx@78
  const void *v122; // ebx@82
  const void *v123; // ebx@82
  __int16 v124; // ax@86
  int v125; // ecx@86
  int v126; // edx@86
  unsigned __int8 v127; // zf@87
  unsigned __int8 v128; // sf@87
  int v129; // ecx@89
  int v130; // eax@94
  const void *v131; // ebx@94
  const void *v132; // ebx@94
  const void *v133; // ebx@94
  int v134; // eax@94
  size_t v135; // ecx@94
  unsigned __int8 v136; // zf@94
  unsigned __int8 v137; // sf@94
  int v138; // edx@95
  int v139; // ecx@95
  void *v140; // ecx@95
  int v141; // edx@95
  int v142; // ecx@95
  void *v143; // ecx@95
  int v144; // edx@95
  int v145; // edx@95
  int v146; // edx@95
  int v147; // edx@95
  int v148; // edx@95
  int v149; // ecx@95
  int v150; // edx@95
  const void *v151; // ebx@96
  int v152; // eax@96
  size_t v153; // ecx@96
  unsigned __int8 v154; // zf@96
  unsigned __int8 v155; // sf@96
  int v156; // eax@97
  FILE *v157; // ecx@97
  int v158; // edx@99
  const void *v159; // ebx@100
  const void *v160; // ebx@100
  __int16 v161; // ax@102
  FILE *v162; // ecx@102
  const void *v163; // ebx@103
  const void *v164; // ebx@103
  const void *v165; // ebx@103
  int v166; // eax@103
  int v167; // eax@103
  int v168; // ecx@103
  int v169; // ebx@103
  int v170; // ecx@103
  int v171; // eax@103
  //size_t v172; // eax@103
  size_t v173; // ebx@109
  int v174; // eax@114
  int v175; // ecx@116
  int v176; // eax@117
  size_t v177; // ebx@126
  int v178; // eax@130
  char v179; // zf@132
  size_t v180; // ebx@134
  int v181; // eax@138
  //size_t v182; // eax@140
  signed int v183; // ebx@142
  int v184; // ebx@148
  int v185; // ecx@149
  int v186; // eax@149
  int v187; // ecx@149
  signed int v188; // ebx@154
  unsigned int v189; // ebx@157
  unsigned int v190; // ebx@157
  int v191; // edx@158
  _UNKNOWN *v192; // ecx@158
  __int16 v193; // ax@161
  __int16 v194; // ax@165
  int v196; // edx@168
  unsigned int v197; // ebx@168
  int v198; // eax@168
  size_t v199; // ebx@168
  unsigned __int8 v200; // zf@168
  unsigned __int8 v201; // sf@168
  int v202; // eax@169
  int v203; // ecx@169
  int v204; // ecx@172
  int v205; // edx@172
  int v206; // ecx@172
  int v207; // edx@172
  int v208; // ecx@172
  int v209; // edx@172
  int v210; // ecx@172
  int v211; // edx@172
  int v212; // ecx@172
  int v213; // edx@172
  int v214; // ecx@172
  int v215; // edx@172
  int v216; // ecx@172
  int v217; // edx@172
  int v218; // ebx@172
  int v219; // edx@173
  unsigned __int8 v220; // zf@173
  unsigned __int8 v221; // sf@173
  int v222; // ecx@174
  int l; // eax@175
  int v224; // ebx@176
  int v225; // ecx@176
  int v226; // ecx@176
  void *v227; // ebx@178
  int v228; // eax@178
  char v229; // [sp-18h] [bp-680h]@66
  //int v230; // [sp-14h] [bp-67Ch]@66
  int v231; // [sp-10h] [bp-678h]@66
  int v232; // [sp-Ch] [bp-674h]@66
  int v233; // [sp-8h] [bp-670h]@4
  //int v234; // [sp-4h] [bp-66Ch]@4
  char v235; // [sp+Ch] [bp-65Ch]@130
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
  char Str1; // [sp+5FCh] [bp-6Ch]@42
  size_t ElementSize; // [sp+624h] [bp-44h]@67
  char Dst; // [sp+628h] [bp-40h]@9
  //char *v270; // [sp+634h] [bp-34h]@38

  struct maybe_blv_header
  {
   int v271; // [sp+B58h] [bp-28h]@50
   unsigned int magic;  // "MVII" for mm7
   unsigned int uCompressedSize; // [sp+B60h] [bp-20h]@50
   unsigned int uUncompressedSize; // [sp+B64h] [bp-1Ch]@50
  } v271;
  //int v271; // [sp+638h] [bp-30h]@61
  //char v272; // [sp+63Ch] [bp-2Ch]@61
  //char v273; // [sp+63Dh] [bp-2Bh]@61
  //char v274; // [sp+63Eh] [bp-2Ah]@61
  //char v275; // [sp+63Fh] [bp-29h]@61
  //size_t v276; // [sp+640h] [bp-28h]@61
  //size_t Size; // [sp+644h] [bp-24h]@61
  unsigned int v278; // [sp+648h] [bp-20h]@66
  size_t Count; // [sp+64Ch] [bp-1Ch]@109
  __int64 v280; // [sp+650h] [bp-18h]@66
  FILE *File; // [sp+658h] [bp-10h]@56
  int v282; // [sp+65Ch] [bp-Ch]@72
  int v283; // [sp+660h] [bp-8h]@72
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
  int v295; // [sp+670h] [bp+8h]@143
  void *v296; // [sp+670h] [bp+8h]@155
  int v297; // [sp+670h] [bp+8h]@161
  int v298; // [sp+670h] [bp+8h]@172
  signed int v299; // [sp+670h] [bp+8h]@175

  v5 = 0;
  dword_6807E0 = 0;

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
          LOWORD(v82) = *(__int16 *)((char *)word_5D29F8 + v82);
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
    v278 = (unsigned int)&v229;
    //Game_sub_40E2C8(&v229, "Can't load file!", (int)((char *)&v280 + 3));
    //sub_466D09(&v278, *(int *)&v229, v230, v231, v232, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Polydata.cpp", 792);
    MessageBoxW(0, L"Can't load file!", 0, 0);
    ExitProcess(0);
  }
  v95 = v271.uCompressedSize;
  ElementSize = v271.uUncompressedSize;
  v93 = malloc(v271.uUncompressedSize);
  v99 = (char *)v93;
  v278 = (unsigned int)v93;
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
    File = (FILE *)&v229;
    //Game_sub_40E2C8(&v229, "Can't load file!", (int)((char *)&v280 + 3));
    //sub_466D09(&File, *(int *)&v229, v230, v231, v232, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Polydata.cpp", 803);
    MessageBoxW(0, L"Can't load file!", 0, 0);
    ExitProcess(0);
  }

  lstrcpyA(pLocationFileName, pLevelFilename);
 
  bLoaded = true;

  memcpy(&struct_0001E8, (const void *)v99, 136);
  v99 += 136;
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

  ptr_00002AC = NamedMemAlloc(char, struct_0001E8.dword_000068_sizeof_lf_data, "L.FData");
  memcpy(ptr_00002AC, v99, struct_0001E8.dword_000068_sizeof_lf_data);


  v98 = (char *)v99 + struct_0001E8.dword_000068_sizeof_lf_data;
  v97 = 0;
  v282 = 0;
  v283 = 0;
  if (uNumFaces > 0)
  {
    do
    {
      *(_DWORD *)(*(_DWORD *)(this + 636) + v97 + 48) = v282 + *(_DWORD *)(this + 684);
      v106 = v97 + *(_DWORD *)(this + 636);
      Src = (void *)v106;
      v107 = v282 + 2 * *(_BYTE *)(v106 + 93) + 2;
      v108 = v107 + *(_DWORD *)(this + 684);
      v282 = v107;
      *((_DWORD *)Src + 13) = v108;
      v109 = v97 + *(_DWORD *)(this + 636);
      Src = (void *)v109;
      v110 = v282 + 2 * *(_BYTE *)(v109 + 93) + 2;
      v111 = v110 + *(_DWORD *)(this + 684);
      v282 = v110;
      *((_DWORD *)Src + 14) = v111;
      Src = (void *)(v97 + *(_DWORD *)(this + 636));
      v112 = *(_DWORD *)(this + 684);
      v282 += 2 * *((_BYTE *)Src + 93) + 2;
      *((_DWORD *)Src + 15) = v282 + v112;
      Src = (void *)(v97 + *(_DWORD *)(this + 636));
      v113 = *(_DWORD *)(this + 684);
      v282 += 2 * *((_BYTE *)Src + 93) + 2;
      *((_DWORD *)Src + 16) = v282 + v113;
      Src = (void *)(v97 + *(_DWORD *)(this + 636));
      v97 += 96;
      v114 = *(_DWORD *)(this + 684);
      v282 += 2 * *((_BYTE *)Src + 93) + 2;
      ++v283;
      *((_DWORD *)Src + 17) = v282 + v114;
      v282 += 2 * *(_BYTE *)(*(_DWORD *)(this + 636) + v97 - 3) + 2;
    }
    while ( v283 < *(_DWORD *)(this + 632) );
  }
  v115 = *(_DWORD *)(this + 632) == 0;
  v116 = *(_DWORD *)(this + 632) < 0;
  v283 = 0;
  if ( !(v116 | v115) )
  {
    v282 = 0;
    do
    {
      memcpy(&Dst, v98, 0xAu);
      v98 = (char *)v98 + 10;
      if ( *(_BYTE *)(v282 + *(_DWORD *)(this + 636) + 45) & 0x40 )
      {
        v118 = TextureFrameTable_sub_44E163(pTextureFrameTable, &Dst);
        v119 = v282;
        *(_WORD *)(v282 + *(_DWORD *)(this + 636) + 74) = v118;
        v117 = *(_WORD *)(v119 + *(_DWORD *)(this + 636) + 74);
        if ( v117 )
        {
          TextureFrameTable_sub_44E0ED(pTextureFrameTable, v117);
        }
        else
        {
          v120 = LODFile_Bitmaps_LOD.LODFile_LoadTexture(&Dst, 0);
          v121 = v282;
          *(_WORD *)(v282 + *(_DWORD *)(this + 636) + 74) = v120;
          *(_BYTE *)(v121 + *(_DWORD *)(this + 636) + 45) &= 0xBFu;
        }
      }
      else
      {
        *(_WORD *)(v282 + *(_DWORD *)(this + 636) + 74) = LODFile_Bitmaps_LOD.LODFile_LoadTexture(&Dst, 0);
      }
      ++v283;
      v282 += 96;
    }
    while ( v283 < *(_DWORD *)(this + 632) );
  }
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  memcpy((void *)(this + 640), v98, 4u);
  v123 = (char *)v98 + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  v283 = 36 * *(_DWORD *)(this + 640);
  v233 = (int)v123;
  v232 = *(_DWORD *)(this + 644);
  memcpy((void *)v232, v123, v283);
  v122 = (char *)v123 + v283;
  v283 = 0;
  if ( *(_DWORD *)(this + 640) > 0 )
  {
    HIDWORD(v280) = 0;
    do
    {
      memcpy(&Dst, v122, 0xAu);
      v122 = (char *)v122 + 10;
      if ( !_strcmpi(&Dst, "") )
        *(_WORD *)(HIDWORD(v280) + *(_DWORD *)(this + 644) + 14) = -1;
      v124 = LODFile_Bitmaps_LOD.LODFile_LoadTexture(&Dst, 0);
      v125 = *(_DWORD *)(this + 644);
      v126 = HIDWORD(v280);
      ++v283;
      v280 += 154618822656i64;
      *(_WORD *)(v126 + v125 + 14) = v124;
    }
    while ( v283 < *(_DWORD *)(this + 640) );
  }
  v127 = *(_DWORD *)(this + 632) == 0;
  v128 = *(_DWORD *)(this + 632) < 0;
  v283 = 0;
  if ( !(v128 | v127) )
  {
    v282 = 0;
    do
    {
      v129 = *(_DWORD *)(this + 644) + 36 * *(_WORD *)(v282 + *(_DWORD *)(this + 636) + 72);
      if ( *(_WORD *)(v129 + 26) )
      {
        if ( sub_44C23B(v129) )
          *(_BYTE *)(v282 + *(_DWORD *)(this + 636) + 46) |= 0x10u;
        else
          *(_BYTE *)(v282 + *(_DWORD *)(this + 636) + 46) &= 0xEFu;
      }
      ++v283;
      v282 += 96;
    }
    while ( v283 < *(_DWORD *)(this + 632) );
  }
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  memcpy((void *)(this + 648), v122, 4u);
  v132 = (char *)v122 + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  v283 = 116 * *(_DWORD *)(this + 648);
  v233 = (int)v132;
  v232 = *(_DWORD *)(this + 652);
  memcpy((void *)v232, v132, v283);
  v133 = (char *)v132 + v283;
  v233 = *(_DWORD *)(this + 596);
  v232 = *(_DWORD *)(this + 688);
  v134 = (int)NamedMemAlloc(unsigned char, v233, "L.RData");
  v135 = *(_DWORD *)(this + 596);
  *(_DWORD *)(this + 688) = v134;
  v283 = v135;
  memcpy((void *)v134, v133, v135);
  v131 = (char *)v133 + v283;
  v130 = 0;
  v136 = *(_DWORD *)(this + 648) == 0;
  v137 = *(_DWORD *)(this + 648) < 0;
  Src = 0;
  v283 = 0;
  if ( !(v137 | v136) )
  {
    do
    {
      *(_DWORD *)(*(_DWORD *)(this + 652) + v130 + 8) = (int)Src + *(_DWORD *)(this + 688);
      v282 = v130 + *(_DWORD *)(this + 652);
      v138 = *(_DWORD *)(this + 688);
      Src = (char *)Src + 2 * *(_WORD *)(v282 + 4);
      *(_DWORD *)(v282 + 16) = (int)Src + v138;
      v139 = v130 + *(_DWORD *)(this + 652);
      v282 = v139;
      v140 = (char *)Src + 2 * *(_WORD *)(v139 + 12);
      v141 = (int)((char *)v140 + *(_DWORD *)(this + 688));
      Src = v140;
      *(_DWORD *)(v282 + 24) = v141;
      v142 = v130 + *(_DWORD *)(this + 652);
      v282 = v142;
      v143 = (char *)Src + 2 * *(_WORD *)(v142 + 20);
      v144 = (int)((char *)v143 + *(_DWORD *)(this + 688));
      Src = v143;
      *(_DWORD *)(v282 + 32) = v144;
      v282 = v130 + *(_DWORD *)(this + 652);
      v145 = *(_DWORD *)(this + 688);
      Src = (char *)Src + 2 * *(_WORD *)(v282 + 28);
      *(_DWORD *)(v282 + 40) = (int)Src + v145;
      v282 = v130 + *(_DWORD *)(this + 652);
      v146 = *(_DWORD *)(this + 688);
      Src = (char *)Src + 2 * *(_WORD *)(v282 + 36);
      *(_DWORD *)(v282 + 48) = (int)Src + v146;
      v282 = v130 + *(_DWORD *)(this + 652);
      v147 = *(_DWORD *)(this + 688);
      Src = (char *)Src + 2 * *(_WORD *)(v282 + 44);
      *(_DWORD *)(v282 + 64) = (int)Src + v147;
      v282 = v130 + *(_DWORD *)(this + 652);
      v148 = *(_DWORD *)(this + 688);
      Src = (char *)Src + 2 * *(_WORD *)(v282 + 60);
      *(_DWORD *)(v282 + 72) = (int)Src + v148;
      v149 = v130 + *(_DWORD *)(this + 652);
      v130 += 116;
      v282 = v149;
      v150 = *(_DWORD *)(this + 688);
      Src = (char *)Src + 2 * *(_WORD *)(v149 + 68);
      ++v283;
      *(_DWORD *)(v149 + 80) = (int)Src + v150;
      Src = (char *)Src + 2 * *(_WORD *)(*(_DWORD *)(this + 652) + v130 - 40);
    }
    while ( v283 < *(_DWORD *)(this + 648) );
  }

  v233 = *(_DWORD *)(this + 600);
  v232 = *(_DWORD *)(this + 696);
  v152 = (int)NamedMemAlloc(unsigned char, v233, "L.RLData");
  v153 = *(_DWORD *)(this + 600);
  *(_DWORD *)(this + 696) = v152;
  v283 = v153;
  memcpy((void *)v152, v131, v153);
  v151 = (char *)v131 + v283;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  v154 = *(_DWORD *)(this + 648) == 0;
  v155 = *(_DWORD *)(this + 648) < 0;
  Src = 0;
  v283 = 0;
  if ( !(v155 | v154) )
  {
    v156 = *(_DWORD *)(this + 652);
    v157 = 0;
    for ( File = 0; ; v157 = File )
    {
      v158 = *(_DWORD *)(this + 696);
      File = (FILE *)((char *)File + 116);
      ++v283;
      *(int *)((char *)&v157[2]._bufsiz + v156) = (int)((char *)Src + v158);
      v156 = *(_DWORD *)(this + 652);
      Src = (char *)Src + 2 * *(_WORD *)((char *)&v157[2]._charbuf + v156);
      if ( v283 >= *(_DWORD *)(this + 648) )
        break;
    }
  }
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  memcpy((void *)(this + 664), v151, 4u);
  v160 = (char *)v151 + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  memcpy(&uNumLevelDecorations, v160, 4u);
  v160 = (char *)v160 + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  v283 = 32 * uNumLevelDecorations;
  memcpy(pLevelDecorations, v160, 32 * uNumLevelDecorations);
  v159 = (char *)v160 + v283;
  v283 = 0;
  if ( (signed int)uNumLevelDecorations > 0 )
  {
    File = (FILE *)pLevelDecorations;
    do
    {
      memcpy(&Str1, v159, 0x20u);
      v159 = (char *)v159 + 32;
      v161 = DecorationList_FindDecoration(pDecorationDescriptionList, &Str1);
      v162 = File;
      ++v283;
      ++File;
      LOWORD(v162->_ptr) = v161;
    }
    while ( v283 < (signed int)uNumLevelDecorations );
  }
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  memcpy((void *)(this + 656), v159, 4u);
  v163 = (char *)v159 + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  v283 = 16 * *(_DWORD *)(this + 656);
  v233 = (int)v163;
  v232 = *(_DWORD *)(this + 660);
  memcpy((void *)v232, v163, v283);
  v164 = (char *)v163 + v283;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  memcpy((void *)(this + 672), v164, 4u);
  v164 = (char *)v164 + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  v283 = 8 * *(_DWORD *)(this + 672);
  v233 = (int)v164;
  v232 = *(_DWORD *)(this + 676);
  memcpy((void *)v232, v164, v283);
  v165 = (char *)v164 + v283;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  memcpy((void *)(this + 700), v165, 4u);
  v165 = (char *)v165 + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  v166 = *(_DWORD *)(this + 700);
  v233 = 24 * v166;
  v232 = *(_DWORD *)(this + 704);
  v167 = (int)NamedMemAlloc(unsigned char, 24 * v166, "Spawn");
  v168 = *(_DWORD *)(this + 700);
  *(_DWORD *)(this + 704) = v167;
  v283 = 24 * v168;
  memcpy((void *)v167, v165, 24 * v168);
  v169 = (int)((char *)v165 + v283);
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  v233 = v169;
  v232 = *(_DWORD *)(this + 680);
  memcpy((void *)v232, (const void *)v169, 4u);
  v170 = *(_DWORD *)(this + 680);
  v231 = 12 * *(_DWORD *)v170;
  v171 = (int)memcpy((void *)(v170 + 4), (const void *)(v169 + 4), v231);
  free((void *)v278);

  char pLevelDLVName[256];
  strcpy(pLevelDLVName, pLevelFilename);
  strcpy(pLevelDLVName + strlen(pLevelFilename) - 4, ".dlv");
  v283 = (int)LODFile_New_LOD.Find_Container(pLevelDLVName, 1);

  locked_fread(&v271, 0x10u, 1u, (FILE *)v283);
  v282 = 0;
  if ( v271.v271 != 91969 || v271.magic != 'iivm' && v271.magic != 'IIVM')
  {
    v278 = (unsigned int)&v229;
    Game_sub_40E2C8(&v229, "Can't load file!", (int)((char *)&v280 + 3));
    sub_466D09(&v278, *(int *)&v229, 0, v231, v232, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Polydata.cpp", 1090);
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
        locked_fread(Src, 1u, Count, (FILE *)v283);
      }
      else
      {
        HIDWORD(v280) = (long)malloc(v173);
        locked_fread((void *)HIDWORD(v280), v173, 1u, (FILE *)v283);
        v174 = MemUnzip(Src, (unsigned int *)&Count, (void *)SHIDWORD(v280), v173);
        free((void *)HIDWORD(v280));
      }
    }
    else
    {
      v278 = (unsigned int)&v229;
      Game_sub_40E2C8(&v229, "Can't load file!", (int)((char *)&v280 + 3));
      sub_466D09(&v278, *(int *)&v229, 0, v231, v232, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Polydata.cpp", 1108);
    }
    memcpy((void *)(this + 708), Src, 0x28u);
    Src = (char *)Src + 40;
  }
  v175 = *(_DWORD *)(this + 724);
  if ( v175 )
  {
    v176 = *(_DWORD *)(this + 728);
    if ( v176 )
    {
      if ( v175 != pIndoor->uNumFaces || v176 != uNumLevelDecorations )
        v282 = 1;
    }
  }

 unsigned int uRespawnInterval = pMapStats->GetMapInfo(pLevelFilename)->uRespawnInterval;
  if ( BYTE1(dword_6BE364) & 0x20 )
    uRespawnInterval = 29030400;
  HIDWORD(v280) = 0;
  if ( a3 - *(_DWORD *)(this + 712) >= (unsigned int)uRespawnInterval )
  {
    if ( _strcmpi(&Str1, "d29.dlv") )
      HIDWORD(v280) = 1;
  }
  v177 = 875;
  if ( v282 )
  {
    v178 = (int)memset(&v235, 0, 0x36Bu);
    goto LABEL_132;
  }
  if ( HIDWORD(v280) || !*(_DWORD *)(this + 712) )
  {
    v178 = (int)memcpy(&v235, Src, 0x36Bu);
LABEL_132:
    free((unsigned int *)File);
    v179 = v282 == 1;
    *(_DWORD *)(this + 712) = a3;
    if ( v179 )
      ++*(_DWORD *)(this + 708);

    v233 = (int)pLevelFilename;
    *(_DWORD *)a5 = 1;
    v283 = (int)LODFile_Games_LOD.Find_Container((const char *)v233, 0);
    locked_fread(&v271, 0x10u, 1u, (FILE *)v283);
    v180 = v271.uCompressedSize;
    Count = v271.uUncompressedSize;
    Src = malloc(v271.uUncompressedSize);
    File = (FILE *)Src;
    if ( v180 <= Count )
    {
      if ( v180 == Count )
      {
        locked_fread(Src, 1u, Count, (FILE *)v283);
      }
      else
      {
        HIDWORD(v280) = (long)malloc(v180);
        locked_fread((void *)HIDWORD(v280), v180, 1u, (FILE *)v283);
        v181 = MemUnzip(Src, (unsigned int *)&Count, (void *)SHIDWORD(v280), v180);
        free((void *)HIDWORD(v280));
      }
    }
    else
    {
      Game_sub_40E2C8(&v229, "Can't load file!", 0);
      sub_466D09(&a3, *(int *)&v229, 0, v231, v232, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Polydata.cpp", 1195);
    }
    Src = (char *)Src + 40;
    v177 = 875;
    goto LABEL_140;
  }
  *(_DWORD *)a5 = 0;
LABEL_140:

  memcpy((void *)(this + 804), Src, v177);
  Src = (char *)Src + v177;
  if ( *(_DWORD *)a5 )
    memcpy((void *)(this + 804), &v235, v177);
  v183 = 0;
  if ( *(_DWORD *)pIndoor->ptr_00002A8 > 0 )
  {
    v295 = 0;
    do
    {
      if ( (unsigned __int8)(1 << (7 - v183 % 8)) & *(_BYTE *)(v183 / 8 + this + 804) )
        *(_BYTE *)(*(_DWORD *)(this + 680) + v295 + 14) |= 1u;
      v295 += 12;
      ++v183;
    }
    while ( v183 < *(_DWORD *)pIndoor->ptr_00002A8 );
  }
  v283 = 0;
  if ( *(_DWORD *)(this + 632) > 0 )
  {
    v184 = 0;
    do
    {
      v232 = v184 + *(_DWORD *)(this + 636) + 44;
      memcpy((void *)v232, Src, 4u);
      v186 = *(_DWORD *)(this + 636);
      v187 = *(_DWORD *)(this + 644);
      Src = (char *)Src + 4;
      v185 = v187 + 36 * *(_WORD *)(v184 + v186 + 72);
      if ( *(_WORD *)(v185 + 26) )
      {
        if ( sub_44C23B(v185) )
          *(_BYTE *)(v184 + *(_DWORD *)(this + 636) + 46) |= 0x10u;
        else
          *(_BYTE *)(v184 + *(_DWORD *)(this + 636) + 46) &= 0xEFu;
      }
      ++v283;
      v184 += 96;
    }
    while ( v283 < *(_DWORD *)(this + 632) );
  }
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  v188 = 0;
  if ( (signed int)uNumLevelDecorations > 0 )
  {
    v296 = &pLevelDecorations[0].word_000002;
    do
    {
      memcpy(v296, Src, 2);
      Src = (char *)Src + 2;
      v296 = (char *)v296 + 32;
      ++v188;
    }
    while ( v188 < (signed int)uNumLevelDecorations );
  }
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  memcpy(&uNumActors, Src, 4u);
  Src = (char *)Src + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  v189 = 836 * uNumActors;
  memcpy(pActors, Src, 836 * uNumActors);
  Src = (char *)Src + v189;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  memcpy(&Count, Src, 4u);
  Src = (char *)Src + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  v190 = 112 * Count;
  memcpy(pLayingItemsList, Src, 112 * Count);
  Src = (char *)Src + v190;
  int i;
  if ( (signed int)Count > 0 )
  {
    v191 = pObjectDescriptionList->uNumObjects;
    v192 = (char *)pLayingItemsList + 0x24;
    i = Count;
    do
    {
      if ( *(_DWORD *)v192 && !(*((_BYTE *)v192 - 9) & 1) )
      {
        v297 = 0;
        v193 = word_5D29F8[24 * *(_DWORD *)v192];
        *((_WORD *)v192 - 18) = v193;
        if ( v191 <= 0 )
        {
LABEL_165:
          v194 = 0;
        }
        else
        {
          a5 = (int)pObjectDescriptionList->pDescriptions + 32;
          while ( v193 != *(_WORD *)a5 )
          {
            ++v297;
            a5 += 56;
            if ( v297 >= v191 )
              goto LABEL_165;
          }
          v194 = v297;
        }
        *((_WORD *)v192 - 17) = v194;
      }
      v192 = (char *)v192 + 112;
    }
    while ( i-- != 1 );
  }
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  memcpy(&dword_5FF140, Src, 4u);
  Src = (char *)Src + 4;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  v197 = 5324 * dword_5FF140;
  memcpy(array_5E5150, Src, 5324 * dword_5FF140);
  Src = (char *)Src + v197;
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);

  v233 = (int)Src;
  v232 = *(_DWORD *)(this + 668);
  memcpy((void *)v232, Src, 0x3E80u);
  Src = (char *)Src + 16000;

  v233 = *(_DWORD *)(this + 604);
  v232 = *(_DWORD *)(this + 692);
  v198 = (int)NamedMemAlloc(unsigned char, v233, "L.DData");
  v199 = *(_DWORD *)(this + 604);
  *(_DWORD *)(this + 692) = v198;
  memcpy((void *)v198, Src, v199);
  Src = (char *)Src + v199;
  v196 = 0;
  v200 = *(_DWORD *)(this + 664) == 0;
  v201 = *(_DWORD *)(this + 664) < 0;
  v283 = 0;
  if ( !(v201 | v200) )
  {
    v203 = *(_DWORD *)(this + 668);
    v202 = 0;
    while ( 1 )
    {
      *(_DWORD *)(v203 + v202 + 36) = v196 + *(_DWORD *)(this + 692);
      v204 = v202 + *(_DWORD *)(this + 668);
      v205 = v196 + 2 * *(_WORD *)(v204 + 68);
      *(_DWORD *)(v204 + 40) = v205 + *(_DWORD *)(this + 692);
      v206 = v202 + *(_DWORD *)(this + 668);
      v207 = v205 + 2 * *(_WORD *)(v206 + 70);
      *(_DWORD *)(v206 + 44) = v207 + *(_DWORD *)(this + 692);
      v208 = v202 + *(_DWORD *)(this + 668);
      v209 = v207 + 2 * *(_WORD *)(v208 + 72);
      *(_DWORD *)(v208 + 48) = v209 + *(_DWORD *)(this + 692);
      v210 = v202 + *(_DWORD *)(this + 668);
      v211 = v209 + 2 * *(_WORD *)(v210 + 70);
      *(_DWORD *)(v210 + 52) = v211 + *(_DWORD *)(this + 692);
      v212 = v202 + *(_DWORD *)(this + 668);
      v213 = v211 + 2 * *(_WORD *)(v212 + 70);
      *(_DWORD *)(v212 + 56) = v213 + *(_DWORD *)(this + 692);
      v214 = v202 + *(_DWORD *)(this + 668);
      v215 = v213 + 2 * *(_WORD *)(v214 + 74);
      *(_DWORD *)(v214 + 60) = v215 + *(_DWORD *)(this + 692);
      v216 = v202 + *(_DWORD *)(this + 668);
      v202 += 80;
      v217 = v215 + 2 * *(_WORD *)(v216 + 74);
      v218 = v217 + *(_DWORD *)(this + 692);
      ++v283;
      *(_DWORD *)(v216 + 64) = v218;
      v203 = *(_DWORD *)(this + 668);
      v298 = v217 + 2 * *(_WORD *)(v203 + v202 - 6);
      if ( v283 >= *(_DWORD *)(this + 664) )
        break;
      v196 = v298;
    }
  }
  v219 = 0;
  v220 = *(_DWORD *)(this + 664) == 0;
  v221 = *(_DWORD *)(this + 664) < 0;
  v283 = 0;
  if ( !(v221 | v220) )
  {
    v222 = *(_DWORD *)(this + 668);
    a5 = 0;
    do
    {
      v299 = 0;
      for (l = v222 + v219; v299 < *(_WORD *)(v222 + v219 + 70); l = v222 + v219 )
      {
        v224 = 2 * v299;
        v225 = 96 * *(_WORD *)(*(_DWORD *)(l + 40) + 2 * v299++);
        v226 = *(_DWORD *)(this + 644) + 36 * *(_WORD *)(v225 + *(_DWORD *)(this + 636) + 72);
        *(_WORD *)(v224 + *(_DWORD *)(l + 48)) = *(_WORD *)(v226 + 20);
        v219 = a5;
        *(_WORD *)(v224 + *(_DWORD *)(a5 + *(_DWORD *)(this + 668) + 52)) = *(_WORD *)(v226 + 22);
        v222 = *(_DWORD *)(this + 668);
      }
      ++v283;
      v219 += 80;
      a5 = v219;
    }
    while ( v283 < *(_DWORD *)(this + 664) );
  }
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  v227 = Src;
  memcpy(&global_5E4C90, Src, 0xC8u);
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  v228 = (int)memcpy((void *)(this + 748), (char *)v227 + 200, 0x38u);
  free((unsigned int *)File);
  v5 = 0;
LABEL_179:
  sub_4A9A67(pSoundList, 64, v5);
  sub_4A9A67(pSoundList, 103, v5);
  sub_4A9A67(pSoundList, 63, v5);
  sub_4A9A67(pSoundList, 102, v5);
  sub_4A9A67(pSoundList, 50, v5);
  sub_4A9A67(pSoundList, 89, v5);

 return Result::Success;
}



IndoorLocation::IndoorLocation():
  uNumVertices(0), pVertices(nullptr),
  uNumFaces(0),    pFaces(nullptr),
  ptr_0000284(nullptr),
  dword_000288(0),
  ptr_000028C(nullptr),
  dword_000290(0),
  ptr_0000294(nullptr),
  dword_000298(0),
  ptr_000029C(nullptr),
  dword_0002A0(0),
  pNodes(nullptr),
  ptr_00002A8(nullptr),
  ptr_00002AC(nullptr),
  ptr_00002B0(nullptr),
  ptr_00002B4(nullptr),
  ptr_00002B8(nullptr),
  ptr_00002C0(nullptr),
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

