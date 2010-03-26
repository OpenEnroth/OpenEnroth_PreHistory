#include "Level.h"

#include "defs.h"

#include "data.h"

#include "classes.h"

#include "FrameTables.h"

//----- (0047D0A6) --------------------------------------------------------
extern struct CObjectDescriptionList *pObjectDescriptionList;
extern struct CTileTable *pTileTable;
extern struct CTextureFrameTable *pTextureFrameTable;
extern struct CDecorationDescriptionList *pDecorationDescriptionList;
extern struct CObjectDescriptionList *pObjectDescriptionList;
extern struct CSoundList *pSoundList;
extern struct class17 *pClass17_Games_LOD;
extern struct class17 *pClass17_New_LOD;
extern struct class35 class35_obj;
extern size_t dword_665228;
extern size_t Count;
extern char byte_6BE3C4;
extern _UNKNOWN unk_73D514;
extern _UNKNOWN unk_6836D2;
extern _UNKNOWN unk_665230;
extern _UNKNOWN unk_5FF158;
extern _UNKNOWN unk_576E30;
extern int dword_4EC2A8;
extern int dword_4EC2AC;
extern int dword_4EC268[];
extern int dword_4EC28C[];
extern char byte_6BE114[];
extern char byte_6BE124[];
extern char byte_5E4C90[];
extern char byte_5E4CDA[];
extern char byte_5E4CDB[];
extern __int16 word_75D514[];
extern __int16 word_75D516[];
extern int dword_6BE364;
extern int dword_6807E0;
extern int uTextureID_LocationMap;
extern int dword_ACD6D0;
extern int dword_73D510;
extern unsigned char *dword_73D514;
extern __int16 word_5E5150[];
extern size_t dword_5FF140;
extern size_t dword_69ADD0;
extern unsigned char *dword_76D514;
extern __int16 word_6836D0[];
extern __int16 word_5D29F8[];
signed int __fastcall maybe_decompress_file(int a1, int *a2, int a3, int a4);
FILE *sub_47D0A6(struct class51 *Dst, const char *Source, int File, int a4, int a5)
{
  int v5; // esi@1
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
  int v37; // edi@43
  int v38; // eax@43
  int v39; // edi@45
  size_t v40; // eax@50
  int v41; // eax@50
  void *v42; // eax@56
  int v43; // ebx@56
  size_t v44; // edi@56
  int v45; // eax@58
  const void *v46; // ebx@59
  const void *v47; // ebx@59
  int v48; // eax@59
  int v49; // eax@59
  int v50; // ecx@59
  int v51; // ebx@60
  int v52; // eax@61
  int v53; // eax@61
  int v54; // eax@61
  int v55; // eax@61
  int v56; // eax@61
  int v57; // eax@61
  int v58; // ecx@61
  int v59; // ecx@61
  int v60; // ecx@61
  void *v61; // ST24_4@61
  int v62; // ecx@61
  void *v63; // ST18_4@61
  __int16 v64; // ax@64
  __int16 v65; // ax@65
  int v66; // ecx@65
  __int16 v67; // ax@80
  int v68; // ecx@80
  int v69; // eax@81
  int v70; // eax@81
  int v71; // ecx@81
  int v72; // eax@81
  int v73; // eax@81
  int v74; // eax@81
  int v75; // ecx@81
  int v76; // eax@81
  size_t v77; // eax@81
  int v78; // edi@87
  int v79; // edi@88
  int v80; // eax@92
  int v81; // edx@94
  int v82; // ecx@94
  int v83; // eax@95
  int v84; // edx@97
  int v85; // eax@99
  int v86; // eax@107
  int v87; // eax@110
  char v88; // zf@112
  int v89; // edi@114
  int v90; // eax@118
  const void *v91; // edi@120
  size_t v92; // eax@120
  const void *v93; // edi@120
  unsigned __int8 v94; // zf@122
  unsigned __int8 v95; // sf@122
  int v96; // eax@124
  int v97; // eax@124
  int v98; // eax@126
  int v99; // eax@127
  int v100; // eax@129
  const void *v101; // edi@138
  const void *v102; // edi@141
  const void *v103; // edi@141
  const void *v104; // edi@144
  const void *v105; // edi@144
  int v106; // eax@147
  int v107; // edi@147
  int v108; // eax@147
  int v109; // eax@147
  int v110; // eax@147
  int v111; // ecx@150
  int v112; // eax@157
  int v113; // edi@159
  char v115; // [sp-14h] [bp-B94h]@55
  int v116; // [sp-10h] [bp-B90h]@55
  int v117; // [sp-Ch] [bp-B8Ch]@55
  void *v118; // [sp-8h] [bp-B88h]@55
  signed int v119; // [sp-4h] [bp-B84h]@12
  int v120; // [sp+0h] [bp-B80h]@10
  char v121; // [sp+10h] [bp-B70h]@110
  char v122; // [sp+3D8h] [bp-7A8h]@110
  char v123[4]; // [sp+79Ch] [bp-3E4h]@50
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
  char FileName[8 + array_size_unknown]; // [sp+A20h] [bp-160h]@8
  char v151; // [sp+A28h] [bp-158h]@12
  char v152; // [sp+B1Ch] [bp-64h]@10
  char Str[32]; // [sp+B20h] [bp-60h]@1
  char *v154; // [sp+B40h] [bp-40h]@50
  __int64 v155; // [sp+B44h] [bp-3Ch]@55
  size_t ElementSize; // [sp+B4Ch] [bp-34h]@56
  int v157; // [sp+B50h] [bp-30h]@61
  int v158; // [sp+B54h] [bp-2Ch]@68

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
  void *v172; // [sp+B88h] [bp+8h]@13
  const char *v173; // [sp+B88h] [bp+8h]@15
  const char *v174; // [sp+B88h] [bp+8h]@16
  const char *v175; // [sp+B88h] [bp+8h]@18
  int v176; // [sp+B88h] [bp+8h]@24
  int v177; // [sp+B88h] [bp+8h]@30
  int v178; // [sp+B88h] [bp+8h]@32
  char *v179; // [sp+B88h] [bp+8h]@55
  void *v180; // [sp+B88h] [bp+8h]@58
  size_t v181; // [sp+B88h] [bp+8h]@59
  int v182; // [sp+B88h] [bp+8h]@59
  int v183; // [sp+B88h] [bp+8h]@61
  int v184; // [sp+B88h] [bp+8h]@61
  size_t v185; // [sp+B88h] [bp+8h]@61
  size_t v186; // [sp+B88h] [bp+8h]@61
  size_t v187; // [sp+B88h] [bp+8h]@61
  int v188; // [sp+B88h] [bp+8h]@63
  int v189; // [sp+B88h] [bp+8h]@64
  int v190; // [sp+B88h] [bp+8h]@65
  int v191; // [sp+B88h] [bp+8h]@67
  int v192; // [sp+B88h] [bp+8h]@69
  int v193; // [sp+B88h] [bp+8h]@70
  int v194; // [sp+B88h] [bp+8h]@71
  int v195; // [sp+B88h] [bp+8h]@72
  char *v196; // [sp+B88h] [bp+8h]@77
  unsigned int v197; // [sp+B88h] [bp+8h]@78
  int v198; // [sp+B88h] [bp+8h]@79
  int v199; // [sp+B88h] [bp+8h]@80
  int v200; // [sp+B88h] [bp+8h]@81
  char *v201; // [sp+B88h] [bp+8h]@86
  int v202; // [sp+B88h] [bp+8h]@87
  unsigned int v203; // [sp+B88h] [bp+8h]@88
  char *v204; // [sp+B88h] [bp+8h]@89
  int v205; // [sp+B88h] [bp+8h]@90
  unsigned int v206; // [sp+B88h] [bp+8h]@92
  unsigned int v207; // [sp+B88h] [bp+8h]@114
  int v208; // [sp+B88h] [bp+8h]@116
  unsigned int v209; // [sp+B88h] [bp+8h]@118
  int v210; // [sp+B88h] [bp+8h]@128
  int v211; // [sp+B88h] [bp+8h]@129
  int v212; // [sp+B88h] [bp+8h]@133
  unsigned int v213; // [sp+B88h] [bp+8h]@141
  unsigned int v214; // [sp+B88h] [bp+8h]@144
  unsigned int v215; // [sp+B88h] [bp+8h]@147
 wchar_t pLevelMapFilename[256];

  v5 = Dst;
  strcpy(Str, Source);
  if ( byte_6BE3C4 )
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
    v8 = strlen(&Str);
    v120 = 2;
    *(&v152 + v8) = 0;
    uTextureID_LocationMap = class17_LoadTexture(pClass17_Icons_LOD, &Str, v120);
    locked_fread(&DstBuf, 0x180u, 1u, v7);
    fseek(v7, Offset, 0);
    locked_fread((void *)v5, 0xB0u, 1u, v7);
    sub_47F420((void *)v5);
    sub_47F3EA(v5);
    strcpy((char *)(v5 + 128), "grastyl");
    fseek(v7, v127, 0);
    locked_fread((void *)(v5 + 176), 4u, 1u, v7);
    fseek(v7, v128, 0);
    locked_fread(&Count, 4u, 1u, v7);
    fseek(v7, v129, 0);
    locked_fread(&dword_69ADD0, 4u, 1u, v7);
    fseek(v7, v130, 0);
    locked_fread(&dword_665228, 4u, 1u, v7);
    fseek(v7, v131, 0);
    locked_fread(&dword_5FF140, 4u, 1u, v7);
    sub_47CD44((int *)(v5 + 180));
    fseek(v7, v132, 0);
    locked_fread(*(void **)(v5 + 180), 1u, 0x4000u, v7);
    fseek(v7, v133, 0);
    locked_fread(*(void **)(v5 + 184), 1u, 0x4000u, v7);
    fseek(v7, v134, 0);
    locked_fread(*(void **)(v5 + 188), 1u, 0x4000u, v7);
    sub_47C80A((void *)(v5 + 180), 0, 0, 128, 128);
    class23_DeleteBuffer((int)&class23_instance, *(_DWORD *)(v5 + 212));
    *(_DWORD *)(v5 + 212) = 0;
    v9 = class23_AllocatedNamedBuffer(&class23_instance, 0, 32768, "CMAP");
    v120 = *(_DWORD *)(v5 + 228);
    *(_DWORD *)(v5 + 212) = v9;
    class23_DeleteBuffer((int)&class23_instance, v120);
    *(_DWORD *)(v5 + 228) = 0;
    v10 = class23_AllocatedNamedBuffer(&class23_instance, 0, 65536, "OMAP");
    v120 = 0;
    *(_DWORD *)(v5 + 228) = v10;
    fseek(v7, v149, v120);
    locked_fread(&dword_73D510, 4u, 1u, v7);
    locked_fread(&unk_73D514, 1u, 0x20000u, v7);
    locked_fread(word_75D514, 1u, 0x10000u, v7);
    dword_76D514 = class23_AllocatedNamedBuffer(&class23_instance, dword_76D514, 12 * dword_73D510, "TerNorm");
    locked_fread((void *)dword_76D514, 1u, 12 * dword_73D510, v7);
    v11 = class23_AllocatedNamedBuffer(&class23_instance, *(_DWORD *)(v5 + 216), 188 * *(_DWORD *)(v5 + 176), "BDdata");
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
        sprintfex(FileName, "%s", v120);
        v14 = *(_DWORD *)(v5 + 216);
        v151 = 0;
        v120 = (int)&FileName;
        *(_DWORD *)(*(_DWORD *)(v5 + 216) + v12 + 72) = class23_AllocatedNamedBuffer(
                                                          &class23_instance,
                                                          *(_DWORD *)(v12 + v14 + 72),
                                                          12 * *(_DWORD *)(v12 + v14 + 68),
                                                          &FileName);
        *(_DWORD *)(*(_DWORD *)(v5 + 216) + v12 + 84) = class23_AllocatedNamedBuffer(
                                                          &class23_instance,
                                                          *(_DWORD *)(v12 + *(_DWORD *)(v5 + 216) + 84),
                                                          308 * *(_DWORD *)(v12 + *(_DWORD *)(v5 + 216) + 76),
                                                          &FileName);
        v15 = v12 + *(_DWORD *)(v5 + 216);
        v120 = (int)&FileName;
        *(_DWORD *)(*(_DWORD *)(v5 + 216) + v12 + 88) = class23_AllocatedNamedBuffer(
                                                          &class23_instance,
                                                          *(_DWORD *)(v15 + 88),
                                                          2 * *(_DWORD *)(v15 + 76),
                                                          &FileName);
        v16 = v12 + *(_DWORD *)(v5 + 216);
        v120 = (int)&FileName;
        v17 = class23_AllocatedNamedBuffer(&class23_instance, *(_DWORD *)(v16 + 96), 8 * *(_DWORD *)(v16 + 92), &FileName);
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
        call_delete(v13, (unsigned int)v167);
        ++a4;
        v12 += 188;
        if ( a4 >= *(_DWORD *)(v5 + 176) )
          goto LABEL_26;
      }
      v166 = 0;
      v172 = v167;
      while ( 1 )
      {
        a5 = v166 + *(_DWORD *)(v13 + v12 + 84);
        if ( !(*(_BYTE *)(a5 + 29) & 0x40) )
          break;
        v21 = sub_44E163(pTextureFrameTable, v173);
        *(_WORD *)(a5 + 272) = v21;
        if ( !v21 )
        {
          v22 = class17_LoadTexture(pClass17_Bitmaps_LOD, v174, 0);
          v23 = a5;
          *(_BYTE *)(v23 + 29) &= 0xBFu;
LABEL_19:
          *(_WORD *)(v23 + 272) = v22;
          v168 = v22 != -1 ? 72 * v22 + 7278780 : 0;
          *(_WORD *)(v22 != -1 ? 72 * v22 + 7278780 + 0x26 : 38) = class35_sub_48A3BC(
                                                                     &class35_obj,
                                                                     *(_WORD *)(v22 != -1 ? 72 * v22 + 7278780 + 0x24 : 36));
          goto LABEL_20;
        }
        sub_44E0ED(pTextureFrameTable, *(_WORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 216) + v12 + 84) + v166 + 272));
LABEL_20:
        if ( *(_WORD *)(a5 + 292) )
        {
          if ( sub_44C1E8(a5) )
            *(_BYTE *)(a5 + 30) |= 0x10u;
          else
            *(_BYTE *)(a5 + 30) &= 0xEFu;
        }
        ++Str2;
        v13 = *(_DWORD *)(v5 + 216);
        v166 += 308;
        v176 += 10;
        if ( (signed int)Str2 >= *(_DWORD *)(v13 + v12 + 76) )
          goto LABEL_25;
      }
      v22 = class17_LoadTexture(pClass17_Bitmaps_LOD, v175, 0);
      v23 = a5;
      goto LABEL_19;
    }
LABEL_26:
    v24 = (FILE *)File;
    fseek((FILE *)File, v137, 0);
    locked_fread(&unk_665230, 0x70u, Count, v24);
    if ( (signed int)Count > 0 )
    {
      v25 = &unk_665230;
      a4 = Count;
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
          for ( i = pObjectDescriptionList->pDescriptions + 32; (_WORD)v26 != *(_WORD *)i; i = v177 )
          {
            ++a5;
            v178 = i + 56;
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
    locked_fread(word_6836D0, 0x20u, dword_69ADD0, v24);
    a4 = 0;
    if ( (signed int)dword_69ADD0 > 0 )
    {
      a5 = (int)word_6836D0;
      do
      {
        locked_fread(&FileName, 1u, 0x20u, v24);
        v33 = sub_4488B6(pDecorationDescriptionList, &FileName);
        v34 = a5;
        ++a4;
        a5 += 32;
        *(_WORD *)v34 = v33;
      }
      while ( a4 < (signed int)dword_69ADD0 );
    }
    fseek(v24, v139, 0);
    locked_fread(&unk_5FF158, 0x344u, dword_665228, v24);
    fseek(v24, v140, 0);
    locked_fread(word_5E5150, 0x14CCu, dword_5FF140, v24);
    fseek(v24, v141, 0);
    locked_fread((void *)(v5 + 220), 4u, 1u, v24);
    class23_DeleteBuffer((int)&class23_instance, *(_DWORD *)(v5 + 224));
    v35 = *(_DWORD *)(v5 + 220);
    *(_DWORD *)(v5 + 224) = 0;
    v36 = class23_AllocatedNamedBuffer(&class23_instance, 0, 2 * v35, "IDLIST");
    v120 = (int)v24;
    *(_DWORD *)(v5 + 224) = v36;
    locked_fread((void *)v36, 2, *(_DWORD *)(v5 + 220), (FILE *)v120);
    fseek(v24, v142, 0);
    locked_fread(*(void **)(v5 + 228), 4u, 0x4000u, v24);
    fseek(v24, v143, 0);
    locked_fread((void *)(v5 + 1216), 4u, 1u, v24);
    *(_DWORD *)(v5 + 1220) = class23_AllocatedNamedBuffer(&class23_instance, *(_DWORD *)(v5 + 1220), 24 * *(_DWORD *)(v5 + 1216), "Spawn");
    fseek(v24, v144, 0);
    locked_fread(*(void **)(v5 + 1220), 0x18u, *(_DWORD *)(v5 + 1216), v24);
    fseek(v24, v145, 0);
    locked_fread((void *)(v5 + 1224), 0x28u, 1u, v24);
    fseek(v24, v146, 0);
    locked_fread(byte_5E4C90, 1u, 0xC8u, v24);
    fseek(v24, v147, 0);
    locked_fread((void *)(v5 + 1264), 1u, 0x38u, v24);
    fseek(v24, v148, 0);
    locked_fread((void *)(v5 + 1264), 1u, 4u, v24);
    sub_487E58(pTileTable, 4);
    a5 = v5 + 160;
    sub_487E58(pTileTable, *(_WORD *)(v5 + 160));
    sub_487E58(pTileTable, *(_WORD *)(v5 + 164));
    sub_487E58(pTileTable, *(_WORD *)(v5 + 168));
    sub_487E58(pTileTable, *(_WORD *)(v5 + 172));
    if ( v5 != -96 && *(_BYTE *)(v5 + 96) )
    {
      v120 = 0;
      v119 = v5 + 96;
    }
    else
    {
      v120 = 0;
      v119 = (signed int)byte_6BE114;
    }
    *(_DWORD *)(v5 + 232) = class17_LoadTexture(pClass17_Bitmaps_LOD, (const char *)v119, v120);
    strcpy((char *)(v5 + 128), byte_6BE124);
    v38 = sub_487E3B(pTileTable, *(_WORD *)(v5 + 162));
    v37 = *(_DWORD *)(v5 + 232);
    *(_DWORD *)(v5 + 236) = class17_LoadTexture(pClass17_Bitmaps_LOD, (const char *)v38, 0);
    if ( v37 != -1 )
      *(_WORD *)(v37 != -1 ? 72 * v37 + 7278780 + 0x26 : 38) = class35_sub_48A3BC(
                                                                 &class35_obj,
                                                                 *(_WORD *)(v37 != -1 ? 72 * v37 + 7278780 + 0x24 : 36));
    v39 = *(_DWORD *)(v5 + 236);
    if ( v39 != -1 )
      *(_WORD *)(v39 != -1 ? 72 * v39 + 7278780 + 0x26 : 38) = class35_sub_48A3BC(
                                                                 &class35_obj,
                                                                 *(_WORD *)(v39 != -1 ? 72 * v39 + 7278780 + 0x24 : 36));
    sub_47F0E2();
    sub_4435CD(&unk_576E30);
    fclose(v24);
    goto LABEL_150;
  }

  if (!class17_Games_LOD_FindLeveL(pClass17_Games_LOD, Str))
    erroneous_printf("Unable to find %s in Games.LOD", &Str);

  strcpy(FileName, Str);

  strcpy(Str1, Str);
  Str1[strlen(Str1) - 4] = 0;
  wsprintfW(pLevelMapFilename, L"%S.cbm", Str1);
  uTextureID_LocationMap = class17_LoadTextureFromCBM(pClass17_Icons_LOD, pLevelMapFilename);

  v154 = &v152;
  v40 = strlen(Str);
  strcpy(&v152 + v40, ".odm");
  v41 = class17_FindContainer(pClass17_Games_LOD, Str, 1);

  v167 = (void *)v41;

  v159.v159 = 91969;
  v159.v160 = 109;
  v159.v161 = 118;
  v159.v162 = 105;
  v159.v163 = 105;
  v159.v164 = 0;
  v159.Size = 0;

  locked_fread(&v159, 0x10, 1, (FILE *)v41);
  if ( v159.v159 != 91969 || v159.v160 != 109 || v159.v161 != 118 || v159.v162 != 105 || v159.v163 != 105 )
  {
    v120 = 507;
    v119 = (signed int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp";
    v179 = &v115;
    sub_40E2C8(&v115, "Can't load file!", (int)((char *)&Source + 3));
    sub_466D09((char *)&v155 + 4, *(int *)&v115, v116, v117, (int)v118, (const char *)v119, v120);
  }
  v44 = v159.v164;
  ElementSize = v159.Size;
  v42 = malloc(v159.Size);
  v43 = (int)v42;
  HIDWORD(v155) = v42;
  if ( v44 < ElementSize )
  {
    v180 = malloc(v44);
    locked_fread(v180, v44, 1u, (FILE *)v167);
    v45 = maybe_decompress_file(v43, (int *)&ElementSize, (int)v180, v44);
    call_delete(v45, (unsigned int)v180);
  }
  else
  {
    locked_fread(v42, ElementSize, 1u, (FILE *)v167);
  }
  memcpy((void *)v5, (const void *)v43, 0xB0u);
  v46 = (const void *)(v43 + 176);
  sub_47F420((void *)v5);
  sub_47F3EA(v5);
  strcpy((char *)(v5 + 128), "grastyl");
  sub_4435CD(&unk_576E30);
  sub_47CD44((int *)(v5 + 180));
  v120 = 16384;
  v119 = (signed int)v46;
  v118 = *(void **)(v5 + 180);
  memcpy(v118, v46, 0x4000u);
  v46 = (char *)v46 + 16384;
  v117 = 16384;
  v116 = (int)v46;
  *(_DWORD *)&v115 = *(_DWORD *)(v5 + 184);
  memcpy(*(void **)&v115, v46, 0x4000u);
  v46 = (char *)v46 + 16384;
  memcpy(*(void **)(v5 + 188), v46, 0x4000u);
  v46 = (char *)v46 + 16384;
  v120 = *(_DWORD *)(v5 + 212);
  class23_DeleteBuffer((int)&class23_instance, v120);
  *(_DWORD *)(v5 + 212) = 0;
  *(_DWORD *)(v5 + 212) = class23_AllocatedNamedBuffer(&class23_instance, 0, 32768, "CMAP");
  sub_47C80A((void *)(v5 + 180), 0, 0, 128, 128);
  sub_4435CD(&unk_576E30);
  memcpy(&dword_73D510, v46, 4u);
  v46 = (char *)v46 + 4;
  memcpy(&unk_73D514, v46, 0x20000u);
  v46 = (char *)v46 + 131072;
  memcpy(word_75D514, v46, 0x10000u);
  v46 = (char *)v46 + 65536;
  v181 = 12 * dword_73D510;
  dword_76D514 = class23_AllocatedNamedBuffer(&class23_instance, dword_76D514, 12 * dword_73D510, "TerNorm");
  memcpy((void *)dword_76D514, v46, v181);
  v47 = (char *)v46 + v181;
  memcpy((void *)(v5 + 176), v47, 4u);
  v47 = (char *)v47 + 4;
  sub_4435CD(&unk_576E30);
  v48 = *(_DWORD *)(v5 + 176);
  v120 = (int)"BDdata";
  v119 = 188 * v48;
  v118 = *(void **)(v5 + 216);
  v49 = class23_AllocatedNamedBuffer(&class23_instance, (int)v118, 188 * v48, "BDdata");
  v50 = *(_DWORD *)(v5 + 176);
  *(_DWORD *)(v5 + 216) = v49;
  v182 = 188 * v50;
  memcpy((void *)v49, v47, 188 * v50);
  Src = (char *)v47 + v182;
  sub_4435CD(&unk_576E30);
  v170 = 0;
  if ( *(_DWORD *)(v5 + 176) > 0 )
  {
    v51 = 0;
    while ( 1 )
    {
      *(_DWORD *)(*(_DWORD *)(v5 + 216) + v51 + 72) = 0;
      *(_DWORD *)(*(_DWORD *)(v5 + 216) + v51 + 84) = 0;
      *(_DWORD *)(*(_DWORD *)(v5 + 216) + v51 + 88) = 0;
      *(_DWORD *)(*(_DWORD *)(v5 + 216) + v51 + 96) = 0;
      FileName[0] = 0;
      v120 = v51 + *(_DWORD *)(v5 + 216);
      sprintfex(FileName, "%s", v120);
      v53 = *(_DWORD *)(v5 + 216);
      v151 = 0;
      v54 = v51 + v53;
      v120 = (int)&FileName;
      v119 = 12 * *(_DWORD *)(v54 + 68);
      v118 = *(void **)(v54 + 72);
      *(_DWORD *)(*(_DWORD *)(v5 + 216) + v51 + 72) = class23_AllocatedNamedBuffer(&class23_instance, (int)v118, v119, &FileName);
      v55 = v51 + *(_DWORD *)(v5 + 216);
      v120 = (int)&FileName;
      v119 = 308 * *(_DWORD *)(v55 + 76);
      v118 = *(void **)(v55 + 84);
      *(_DWORD *)(*(_DWORD *)(v5 + 216) + v51 + 84) = class23_AllocatedNamedBuffer(&class23_instance, (int)v118, v119, &FileName);
      v56 = v51 + *(_DWORD *)(v5 + 216);
      v120 = (int)&FileName;
      v119 = 2 * *(_DWORD *)(v56 + 76);
      v118 = *(void **)(v56 + 88);
      *(_DWORD *)(*(_DWORD *)(v5 + 216) + v51 + 88) = class23_AllocatedNamedBuffer(&class23_instance, (int)v118, v119, &FileName);
      v57 = v51 + *(_DWORD *)(v5 + 216);
      v120 = (int)&FileName;
      v119 = 8 * *(_DWORD *)(v57 + 92);
      v118 = *(void **)(v57 + 96);
      *(_DWORD *)(*(_DWORD *)(v5 + 216) + v51 + 96) = class23_AllocatedNamedBuffer(&class23_instance, (int)v118, v119, &FileName);
      v58 = *(_DWORD *)(v5 + 216) + v51;
      v120 = 12 * *(_DWORD *)(v58 + 68);
      v183 = v120;
      v119 = (signed int)Src;
      v118 = *(void **)(v58 + 72);
      memcpy(v118, Src, v120);
      Src = (char *)Src + v183;
      v59 = *(_DWORD *)(v5 + 216) + v51;
      v117 = 308 * *(_DWORD *)(v59 + 76);
      v116 = (int)Src;
      *(_DWORD *)&v115 = *(_DWORD *)(v59 + 84);
      v184 = v117;
      memcpy(*(void **)&v115, Src, v117);
      v60 = *(_DWORD *)(v5 + 216) + v51;
      Src = (char *)Src + v184;
      v61 = *(void **)(v60 + 88);
      v185 = 2 * *(_DWORD *)(v60 + 76);
      memcpy(v61, Src, v185);
      v62 = *(_DWORD *)(v5 + 216) + v51;
      Src = (char *)Src + v185;
      v63 = *(void **)(v62 + 96);
      v186 = 8 * *(_DWORD *)(v62 + 92);
      memcpy(v63, Src, v186);
      Src = (char *)Src + v186;
      v167 = malloc(10 * *(_DWORD *)(*(_DWORD *)(v5 + 216) + v51 + 76));
      v187 = 10 * *(_DWORD *)(*(_DWORD *)(v5 + 216) + v51 + 76);
      memcpy(v167, Src, v187);
      v157 = 0;
      Src = (char *)Src + v187;
      v52 = *(_DWORD *)(v5 + 216);
      if ( *(_DWORD *)(v51 + v52 + 76) > 0 )
        break;
LABEL_74:
      call_delete(v52, (unsigned int)v167);
      ++v170;
      v51 += 188;
      if ( v170 >= *(_DWORD *)(v5 + 176) )
        goto LABEL_75;
    }
    v168 = 0;
    Str2 = (char *)v167;
    while ( 1 )
    {
      v188 = v168 + *(_DWORD *)(v51 + v52 + 84);
      if ( !(*(_BYTE *)(v188 + 29) & 0x40) )
        break;
      v64 = sub_44E163(pTextureFrameTable, Str2);
      *(_WORD *)(v189 + 272) = v64;
      if ( !v64 )
      {
        v65 = class17_LoadTexture(pClass17_Bitmaps_LOD, Str2, 0);
        v66 = v190;
        *(_BYTE *)(v66 + 29) &= 0xBFu;
LABEL_68:
        *(_WORD *)(v66 + 272) = v65;
        v158 = v65 != -1 ? 72 * v65 + 7278780 : 0;
        v120 = *(_WORD *)(v65 != -1 ? 72 * v65 + 7278780 + 0x24 : 36);
        *(_WORD *)(v65 != -1 ? 72 * v65 + 7278780 + 0x26 : 38) = class35_sub_48A3BC(&class35_obj, v120);
        goto LABEL_69;
      }
      v120 = *(_WORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 216) + v51 + 84) + v168 + 272);
      sub_44E0ED(pTextureFrameTable, v120);
LABEL_69:
      if ( *(_WORD *)(v192 + 292) )
      {
        if ( sub_44C1E8(v193) )
          *(_BYTE *)(v194 + 30) |= 0x10u;
        else
          *(_BYTE *)(v195 + 30) &= 0xEFu;
      }
      ++v157;
      v52 = *(_DWORD *)(v5 + 216);
      v168 += 308;
      Str2 += 10;
      if ( v157 >= *(_DWORD *)(v51 + v52 + 76) )
        goto LABEL_74;
    }
    v65 = class17_LoadTexture(pClass17_Bitmaps_LOD, Str2, 0);
    v66 = v191;
    goto LABEL_68;
  }
LABEL_75:
  sub_4435CD(&unk_576E30);
  memcpy(&dword_69ADD0, Src, 4u);
  Src = (char *)Src + 4;
  if ( (signed int)dword_69ADD0 < 0 || (signed int)dword_69ADD0 > 3000 )
  {
    v120 = 678;
    v119 = (signed int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp";
    v196 = &v115;
    sub_40E2C8(&v115, "Can't load file!", (int)((char *)&Source + 3));
    sub_466D09(&v167, *(int *)&v115, v116, v117, (int)v118, (const char *)v119, v120);
  }
  sub_4435CD(&unk_576E30);
  v197 = 32 * dword_69ADD0;
  memcpy(word_6836D0, Src, 32 * dword_69ADD0);
  v170 = 0;
  Src = (char *)Src + v197;
  if ( (signed int)dword_69ADD0 > 0 )
  {
    v198 = (int)word_6836D0;
    do
    {
      memcpy(&FileName, Src, 0x20u);
      Src = (char *)Src + 32;
      v67 = sub_4488B6(pDecorationDescriptionList, &FileName);
      v68 = v199;
      ++v170;
      v199 += 32;
      *(_WORD *)v68 = v67;
    }
    while ( v170 < (signed int)dword_69ADD0 );
  }
  sub_4435CD(&unk_576E30);
  memcpy((void *)(v5 + 220), Src, 4u);
  Src = (char *)Src + 4;
  v120 = *(_DWORD *)(v5 + 224);
  class23_DeleteBuffer((int)&class23_instance, v120);
  v69 = *(_DWORD *)(v5 + 220);
  *(_DWORD *)(v5 + 224) = 0;
  v70 = class23_AllocatedNamedBuffer(&class23_instance, 0, 2 * v69, "IDLIST");
  v71 = *(_DWORD *)(v5 + 220);
  *(_DWORD *)(v5 + 224) = v70;
  v200 = 2 * v71;
  memcpy((void *)v70, Src, 2 * v71);
  Src = (char *)Src + v200;
  sub_4435CD(&unk_576E30);
  v120 = *(_DWORD *)(v5 + 228);
  class23_DeleteBuffer((int)&class23_instance, v120);
  *(_DWORD *)(v5 + 228) = 0;
  v72 = class23_AllocatedNamedBuffer(&class23_instance, 0, 65536, "OMAP");
  v120 = 65536;
  *(_DWORD *)(v5 + 228) = v72;
  memcpy((void *)v72, Src, v120);
  Src = (char *)Src + 65536;
  sub_4435CD(&unk_576E30);
  memcpy((void *)(v5 + 1216), Src, 4u);
  Src = (char *)Src + 4;
  sub_4435CD(&unk_576E30);
  v73 = *(_DWORD *)(v5 + 1216);
  v120 = (int)"Spawn";
  v119 = 24 * v73;
  v118 = *(void **)(v5 + 1220);
  v74 = class23_AllocatedNamedBuffer(&class23_instance, (int)v118, 24 * v73, "Spawn");
  v75 = *(_DWORD *)(v5 + 1216);
  *(_DWORD *)(v5 + 1220) = v74;
  memcpy((void *)v74, Src, 24 * v75);
  v76 = (int)sub_4435CD(&unk_576E30);
  call_delete(v76, HIDWORD(v155));
  v120 = (int)".ddm";
  v77 = strlen(&Str);
  strcpy(&v154[v77], (const char *)v120);
  v170 = class17_FindContainer(pClass17_New_LOD, &Str, 1);
  locked_fread(&v159, 0x10u, 1u, (FILE *)v170);
  Str2 = 0;
  if ( v159.v159 != 91969 || v159.v160 != 109 || v159.v161 != 118 || v159.v162 != 105 || v159.v163 != 105 )
  {
    v120 = 746;
    v119 = (signed int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp";
    v201 = &v115;
    sub_40E2C8(&v115, "Can't load file!", (int)((char *)&Source + 3));
    sub_466D09((char *)&v155 + 4, *(int *)&v115, v116, v117, (int)v118, (const char *)v119, v120);
    Str2 = (char *)1;
  }
  v78 = 0;
  v202 = v159.v164;
  v168 = 0;
  v166 = v159.Size;
  if ( !Str2 )
  {
    v79 = (int)malloc(v159.Size);
    v168 = v79;
    if ( v203 <= v166 )
    {
      if ( v205 == v166 )
      {
        locked_fread((void *)v79, v166, 1u, (FILE *)v170);
      }
      else
      {
        Src = malloc(v206);
        locked_fread(Src, v206, 1u, (FILE *)v170);
        v80 = maybe_decompress_file(v79, (int *)&v166, (int)Src, v206);
        call_delete(v80, (unsigned int)Src);
      }
    }
    else
    {
      v120 = 765;
      v119 = (signed int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp";
      v204 = &v115;
      sub_40E2C8(&v115, "Can't load file!", (int)((char *)&Source + 3));
      sub_466D09((char *)&v155 + 4, *(int *)&v115, v116, v117, (int)v118, (const char *)v119, v120);
    }
    memcpy((void *)(v5 + 1224), (const void *)v79, 0x28u);
    v78 = v79 + 40;
  }
  v81 = *(_DWORD *)(v5 + 176);
  v82 = 0;
  if ( v81 > 0 )
  {
    v83 = *(_DWORD *)(v5 + 216) + 76;
    do
    {
      v82 += *(_DWORD *)v83;
      v83 += 188;
      --v81;
    }
    while ( v81 );
  }
  v84 = *(_DWORD *)(v5 + 1240);
  if ( v84 )
  {
    if ( *(_DWORD *)(v5 + 1248) )
    {
      v85 = *(_DWORD *)(v5 + 1244);
      if ( v85 )
      {
        if ( v84 != v82 || *(_DWORD *)(v5 + 1248) != *(_DWORD *)(v5 + 176) || v85 != dword_69ADD0 )
          Str2 = (char *)1;
      }
    }
  }
  if ( BYTE1(dword_6BE364) & 0x20 )
    a4 = 29030400;
  if ( Str2 )
  {
    memset(&v122, 0, 0x3C8u);
    v87 = (int)memset(&v121, 0, 0x3C8u);
    goto LABEL_112;
  }
  v86 = *(_DWORD *)(v5 + 1228);
  if ( File - v86 >= (unsigned int)a4 || !v86 )
  {
    memcpy(&v122, (const void *)v78, 0x3C8u);
    v87 = (int)memcpy(&v121, (const void *)(v78 + 968), 0x3C8u);
LABEL_112:
    call_delete(v87, v168);
    v88 = Str2 == 0;
    *(_DWORD *)(v5 + 1228) = File;
    if ( v88 )
      ++*(_DWORD *)(v5 + 1224);
    v120 = 0;
    *(_DWORD *)a5 = 1;
    v170 = class17_FindContainer(pClass17_Games_LOD, &Str, v120);
    locked_fread(&v159, 0x10u, 1u, (FILE *)v170);
    v207 = v159.v164;
    v166 = v159.Size;
    v89 = (int)malloc(v159.Size);
    v168 = v89;
    if ( v207 <= v166 )
    {
      if ( v208 == v166 )
      {
        locked_fread((void *)v89, v166, 1u, (FILE *)v170);
      }
      else
      {
        Src = malloc(v209);
        locked_fread(Src, v209, 1u, (FILE *)v170);
        v90 = maybe_decompress_file(v89, (int *)&v166, (int)Src, v209);
        call_delete(v90, (unsigned int)Src);
      }
    }
    else
    {
      v120 = 857;
      v119 = (signed int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp";
      a4 = (signed int)&v115;
      sub_40E2C8(&v115, "Can't load file!", (int)((char *)&a4 + 3));
      sub_466D09(&File, *(int *)&v115, v116, v117, (int)v118, (const char *)v119, v120);
    }
    v78 = v89 + 40;
    goto LABEL_120;
  }
  *(_DWORD *)a5 = 0;
LABEL_120:
  v120 = (int)".odm";
  v92 = strlen(&Str);
  strcpy(&v154[v92], (const char *)v120);
  memcpy((void *)(v5 + 1320), (const void *)v78, 0x3C8u);
  v93 = (const void *)(v78 + 968);
  memcpy((void *)(v5 + 2288), v93, 0x3C8u);
  v91 = (char *)v93 + 968;
  sub_4435CD(&unk_576E30);
  if ( *(_DWORD *)a5 )
  {
    memcpy((void *)(v5 + 1320), &v122, 0x3C8u);
    memcpy((void *)(v5 + 2288), &v121, 0x3C8u);
  }
  v94 = *(_DWORD *)(v5 + 176) == 0;
  v95 = *(_DWORD *)(v5 + 176) < 0;
  v170 = 0;
  if ( !(v95 | v94) )
  {
    a4 = 0;
    do
    {
      v97 = *(_DWORD *)(v5 + 216);
      a5 = 0;
      v96 = a4 + v97;
      if ( *(_DWORD *)(v96 + 76) > 0 )
      {
        File = 0;
        do
        {
          v118 = (void *)(*(_DWORD *)(v96 + 84) + File + 28);
          memcpy(v118, v91, 4u);
          v98 = *(_DWORD *)(v5 + 216);
          File += 308;
          v91 = (char *)v91 + 4;
          ++a5;
          v96 = a4 + v98;
        }
        while ( a5 < *(_DWORD *)(v96 + 76) );
      }
      v99 = *(_DWORD *)(v5 + 216);
      a5 = 0;
      if ( *(_DWORD *)(a4 + v99 + 76) > 0 )
      {
        v210 = 0;
        do
        {
          v100 = v211 + *(_DWORD *)(a4 + v99 + 84);
          File = v100;
          if ( *(_WORD *)(v100 + 292) )
          {
            if ( sub_44C1E8(v100) )
              *(_BYTE *)(File + 30) |= 0x10u;
            else
              *(_BYTE *)(File + 30) &= 0xEFu;
          }
          ++a5;
          v99 = *(_DWORD *)(v5 + 216);
          v212 += 308;
        }
        while ( a5 < *(_DWORD *)(a4 + v99 + 76) );
      }
      ++v170;
      a4 += 188;
    }
    while ( v170 < *(_DWORD *)(v5 + 176) );
  }
  sub_4435CD(&unk_576E30);
  v170 = 0;
  if ( (signed int)dword_69ADD0 > 0 )
  {
    a5 = (int)&unk_6836D2;
    do
    {
      memcpy((void *)a5, v91, 2);
      a5 += 32;
      v91 = (char *)v91 + 2;
      ++v170;
    }
    while ( v170 < (signed int)dword_69ADD0 );
  }
  sub_4435CD(&unk_576E30);
  memcpy(&dword_665228, v91, 4u);
  v101 = (char *)v91 + 4;
  if ( (signed int)dword_665228 < 0 || (signed int)dword_665228 > 500 )
  {
    v120 = 939;
    v119 = (signed int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp";
    a5 = (int)&v115;
    sub_40E2C8(&v115, "Can't load file!", (int)((char *)&a5 + 3));
    sub_466D09(&a4, *(int *)&v115, v116, v117, (int)v118, (const char *)v119, v120);
  }
  sub_4435CD(&unk_576E30);
  v213 = 836 * dword_665228;
  memcpy(&unk_5FF158, v101, 836 * dword_665228);
  v103 = (char *)v101 + v213;
  sub_4435CD(&unk_576E30);
  memcpy(&Count, v103, 4u);
  v102 = (char *)v103 + 4;
  if ( (signed int)Count < 0 || (signed int)Count > 1000 )
  {
    v120 = 954;
    v119 = (signed int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp";
    a5 = (int)&v115;
    sub_40E2C8(&v115, "Can't load file!", (int)((char *)&a5 + 3));
    sub_466D09(&a4, *(int *)&v115, v116, v117, (int)v118, (const char *)v119, v120);
  }
  sub_4435CD(&unk_576E30);
  v214 = 112 * Count;
  memcpy(&unk_665230, v102, 112 * Count);
  v105 = (char *)v102 + v214;
  sub_4435CD(&unk_576E30);
  memcpy(&dword_5FF140, v105, 4u);
  v104 = (char *)v105 + 4;
  if ( (signed int)dword_5FF140 < 0 || (signed int)dword_5FF140 > 20 )
  {
    v120 = 968;
    v119 = (signed int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odmap.cpp";
    a5 = (int)&v115;
    sub_40E2C8(&v115, "Can't load file!", (int)((char *)&a5 + 3));
    sub_466D09(&a4, *(int *)&v115, v116, v117, (int)v118, (const char *)v119, v120);
  }
  sub_4435CD(&unk_576E30);
  v215 = 5324 * dword_5FF140;
  memcpy(word_5E5150, v104, 5324 * dword_5FF140);
  v107 = (int)((char *)v104 + v215);
  sub_4435CD(&unk_576E30);
  memcpy(byte_5E4C90, (const void *)v107, 0xC8u);
  sub_4435CD(&unk_576E30);
  v108 = (int)memcpy((void *)(v5 + 1264), (const void *)(v107 + 200), 0x38u);
  call_delete(v108, v168);
  sub_487E58(pTileTable, 4);
  a5 = v5 + 160;
  v120 = *(_WORD *)(v5 + 160);
  sub_487E58(pTileTable, v120);
  v120 = *(_WORD *)(v5 + 164);
  sub_487E58(pTileTable, v120);
  v120 = *(_WORD *)(v5 + 168);
  sub_487E58(pTileTable, v120);
  v120 = *(_WORD *)(v5 + 172);
  sub_487E58(pTileTable, v120);
  strcpy((char *)(v5 + 128), byte_6BE124);
  v109 = *(_WORD *)(v5 + 162);
  v120 = 0;
  v110 = sub_487E3B(pTileTable, v109);
  v106 = class17_LoadTexture(pClass17_Bitmaps_LOD, (const char *)v110, v120);
  *(_DWORD *)(v5 + 236) = v106;
  if ( v106 != -1 )
  {
    v120 = *(_WORD *)(v106 != -1 ? 72 * v106 + 7278780 + 0x24 : 36);
    *(_WORD *)(v106 != -1 ? 72 * v106 + 7278780 + 0x26 : 38) = class35_sub_48A3BC(&class35_obj, v120);
  }
  sub_47F0E2();
LABEL_150:
  v111 = *(_DWORD *)(v5 + 1268);
  LODWORD(v155) = *(_DWORD *)(v5 + 1264);
  HIDWORD(v155) = v111;
  if ( v111 | (_DWORD)v155 )
  {
    v120 = 28;
    if ( (signed int)((signed int)(signed __int64)((double)v155 * 0.234375) / 60 / 60 / 0x18u) % 28 != dword_ACD6D0 )
    {
      if ( rand() % 100 >= 20 )
        v120 = dword_4EC268[rand() % dword_4EC2A8];
      else
        v120 = dword_4EC28C[rand() % dword_4EC2AC];
      sprintfex(v5 + 1272, "plansky%d", v120);
    }
  }
  else
  {
    strcpy((char *)(v5 + 1272), "plansky3");
  }
  v112 = class17_LoadTexture(pClass17_Bitmaps_LOD, (const char *)(v5 + 1272), 0);
  *(_DWORD *)(v5 + 232) = v112;
  if ( v112 != -1 )
  {
    v120 = *(_WORD *)(v112 != -1 ? 72 * v112 + 7278780 + 0x24 : 36);
    *(_WORD *)(v112 != -1 ? 72 * v112 + 7278780 + 0x26 : 38) = class35_sub_48A3BC(&class35_obj, v120);
  }
  class35_sub_48A614(&class35_obj);
  sub_4A9A67(pSoundList, 53, 0);
  sub_4A9A67(pSoundList, 92, 0);
  sub_4A9A67(pSoundList, 57, 0);
  sub_4A9A67(pSoundList, 96, 0);
  sub_4A9A67(pSoundList, 64, 0);
  sub_4A9A67(pSoundList, 103, 0);
  v113 = a5;
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
    sub_4A9A67(pSoundList, v119, v120);
LABEL_175:
    v113 += 4;
  }
  while ( a5-- != 1 );
  return (FILE *)1;
}




//----- (00460706) --------------------------------------------------------
extern char Str1[];
int __cdecl LoadLevelFromFile()
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

 strcpy(FullPath, Str1);
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
    dword_6A0D08 = class23_AllocatedNamedBuffer(class23_instance, dword_6A0D08, v2, "LevelLod");
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