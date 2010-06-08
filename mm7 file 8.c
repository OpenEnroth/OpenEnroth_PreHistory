#include <ddraw.h>
#include <dinput.h>

#include "defs.h"



#include "AIL.h"

#include "data.h"
#include "mm7DDrawRenderer.h"
#include "_audio.h"
#include "_video.h"
#include "FrameTables.h"
#include "GUI.h"
#include "Level.h"
#include "Actor.h"
#include "codec.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"




//----- (00481212) --------------------------------------------------------
void __fastcall sub_481212(int a1, int a2, int a3)
{
  int v3; // edi@1
  int v4; // esi@1
  int v5; // ecx@1
  int v6; // ST10_4@1
  int v7; // ebx@2
  int v8; // eax@2
  int v9; // eax@3
  int v10; // edi@3
  char *v11; // ecx@4
  int v12; // ebx@4
  float v13; // eax@6
  double v14; // st7@6
  double v15; // st7@6
  int v16; // ebx@12
  __int16 v17; // ax@12
  int v18; // eax@13
  int v19; // eax@13
  int v20; // ecx@13
  int v21; // eax@13
  int v22; // eax@13
  int v23; // eax@15
  double v24; // st7@18
  double v25; // st5@24
  double v26; // st5@24
  double v27; // st5@24
  double v28; // st5@24
  float v29; // eax@25
  int v30; // edi@29
  double v31; // st7@31
  int v32; // esi@35
  int v33; // edx@36
  int v34; // ecx@36
  signed int v35; // eax@39
  int v36; // esi@40
  int v37; // ebx@43
  __int16 v38; // ax@43
  int v39; // eax@44
  int v40; // eax@44
  int v41; // ecx@44
  int v42; // eax@44
  int v43; // eax@44
  int v44; // eax@44
  int v45; // eax@46
  double v46; // st7@49
  double v47; // st5@57
  double v48; // st5@57
  double v49; // st5@57
  float v50; // eax@58
  int v51; // edi@62
  double v52; // st7@63
  int v53; // esi@66
  int v54; // eax@69
  signed int v55; // esi@71
  __int16 v56; // ax@75
  int v57; // eax@76
  int v58; // eax@76
  int v59; // eax@77
  double v60; // st7@80
  double v61; // st5@88
  double v62; // st5@88
  double v63; // st5@88
  float v64; // eax@89
  double v65; // st7@94
  int v68; // [sp-Ch] [bp-C4h]@36
  int v69; // [sp-8h] [bp-C0h]@36
  int v70; // [sp-4h] [bp-BCh]@36
  char v71; // [sp+Ch] [bp-ACh]@88
  double v72; // [sp+10h] [bp-A8h]@6
  double v73; // [sp+18h] [bp-A0h]@82
  double v74; // [sp+20h] [bp-98h]@6
  double v75; // [sp+28h] [bp-90h]@51
  double v76; // [sp+30h] [bp-88h]@6
  double v77; // [sp+38h] [bp-80h]@20
  double v78; // [sp+40h] [bp-78h]@6
  char v79; // [sp+48h] [bp-70h]@57
  float v80; // [sp+4Ch] [bp-6Ch]@6
  float v81; // [sp+50h] [bp-68h]@6
  int v82; // [sp+54h] [bp-64h]@1
  int v83; // [sp+58h] [bp-60h]@6
  int v84; // [sp+5Ch] [bp-5Ch]@82
  int v85; // [sp+60h] [bp-58h]@20
  int v86; // [sp+64h] [bp-54h]@1
  int v87; // [sp+68h] [bp-50h]@1
  int v88; // [sp+6Ch] [bp-4Ch]@51
  float v89; // [sp+70h] [bp-48h]@51
  int v90; // [sp+74h] [bp-44h]@6
  int v91; // [sp+78h] [bp-40h]@1
  char v92; // [sp+7Ch] [bp-3Ch]@24
  int v93; // [sp+80h] [bp-38h]@2
  float v94; // [sp+84h] [bp-34h]@44
  int v95; // [sp+88h] [bp-30h]@6
  float v96; // [sp+8Ch] [bp-2Ch]@1
  float v97; // [sp+90h] [bp-28h]@1
  float v98; // [sp+94h] [bp-24h]@1
  int X; // [sp+98h] [bp-20h]@1
  float v100; // [sp+9Ch] [bp-1Ch]@6
  int v101; // [sp+A0h] [bp-18h]@6
  int v102; // [sp+A4h] [bp-14h]@6
  int v103; // [sp+A8h] [bp-10h]@6
  int v104; // [sp+ACh] [bp-Ch]@6
  int v105; // [sp+B0h] [bp-8h]@6
  int v106; // [sp+B4h] [bp-4h]@3
  float v107; // [sp+C0h] [bp+8h]@6
  float v108; // [sp+C0h] [bp+8h]@6
  int v109; // [sp+C0h] [bp+8h]@17
  int v110; // [sp+C0h] [bp+8h]@48
  int v111; // [sp+C0h] [bp+8h]@77

  v4 = a1;
  v5 = *(_WORD *)(a3 + 4);
  v6 = *(_WORD *)(a3 + 6);
  v86 = a2;
  v87 = v5;
  X = abs(v6);
  v3 = 0;
  v91 = 0;
  v82 = v4 - 1;
  v96 = (double)dword_6A1B20 * 0.0000152587890625;
  v97 = (double)dword_6A1B24 * 0.0000152587890625;
  v98 = (double)dword_6A1B28 * 0.0000152587890625;
  if ( v4 - 1 > 0 )
  {
    while ( 1 )
    {
      v7 = abs(X);
      v8 = abs(v87);
      --X;
      v93 = 4 * ((v7 << 7) + v8) + 0x76E5C8;



/*
      if ( !byte_76E5C8[4 * ((v7 << 7) + v8)]
        || ((v9 = 48 * v3, v10 = (int)((char *)&unk_806210 + 48 * v3), v106 = v10, !v86) ? (v12 = (int)((char *)&unk_801A10 + v9),
                                                                                            v11 = (char *)&unk_806240
                                                                                                + v9) : (v12 = (int)((char *)&unk_806240 + v9), v11 = (char *)&unk_801A10 + v9),
            ((v103 = v12,
              v105 = (int)((char *)&unk_801A40 + v9),
              LODWORD(v13) = *(_DWORD *)v10,
              v104 = (int)v11,
              v81 = v13,
              v74 = v13 + 6.755399441055744e15,
              v102 = LODWORD(v74),
              LODWORD(v80) = *(_DWORD *)(v10 + 4),
              v76 = v80 + 6.755399441055744e15,
              v101 = LODWORD(v76),
              v107 = (*(float *)v11 + *(float *)v10) * 0.5,
              v72 = v107 + 6.755399441055744e15,
              v90 = LODWORD(v72),
              v14 = *(float *)(v12 + 4) + *(float *)(v10 + 4),
              v95 = sub_47F44B(COERCE_UNSIGNED_INT64(v107 + 6.755399441055744e15)),
              v108 = v14 * 0.5,
              v15 = v108 + 6.755399441055744e15,
              v78 = v15,
              v83 = LODWORD(v78),
              LODWORD(v100) = sub_47F458(SLODWORD(v15)),
              sub_47F44B(v102),
              sub_47F458(v101),
              !byte_4D8410[572])
          || !(*(_BYTE *)(LODWORD(pGame) + 3616) & 0x80))
         && !sub_481EFA(v10, v12, v104, v105, 1)) )
        goto LABEL_105;
*/

      if ( !byte_76E5C8[4 * ((v7 << 7) + v8)])
        goto LABEL_105;

      v9 = 48 * v3;
      v10 = (int)((char *)array_806210 + 48 * v3);
      v106 = v10;
      if (!v86)
      {
       v12 = (int)((char *)array_801A10 + v9);
       v11 = (char *)(array_806210 + 1) + v9;
      }
      else
      {
       v12 = (int)((char *)(array_806210 + 1) + v9);
       v11 = (char *)array_801A10 + v9;
      }
      v103 = v12;
      v105 = (int)((char *)(array_801A10 + 1) + v9);
      LODWORD(v13) = *(_DWORD *)v10;
      v104 = (int)v11;
      v81 = v13;
      v74 = v13 + 6.755399441055744e15;
      v102 = LODWORD(v74);
      LODWORD(v80) = *(_DWORD *)(v10 + 4);
      v76 = v80 + 6.755399441055744e15;
      v101 = LODWORD(v76);
      v107 = (*(float *)v11 + *(float *)v10) * 0.5;
      v72 = v107 + 6.755399441055744e15;
      v90 = LODWORD(v72);
      v14 = *(float *)(v12 + 4) + *(float *)(v10 + 4);
      v95 = sub_47F44B(v107 + 6.755399441055744e15);
      v108 = v14 * 0.5;
      v15 = v108 + 6.755399441055744e15;
      v78 = v15;
      v83 = LODWORD(v78);
      LODWORD(v100) = sub_47F458(SLODWORD(v15));
      sub_47F44B(v102);
      sub_47F458(v101);
      if ((!byte_4D8410[572] || !(*(_BYTE *)(&pGame->uSomeFlags) & 0x80)) &&
          !sub_481EFA(v10, v12, v104, v105, 1))
        goto LABEL_105;






      if ( *(float *)(v10 + 8) != *(float *)(v12 + 8)
        || *(float *)(v12 + 8) != *(float *)(v105 + 8)
        || *(float *)(v105 + 8) != *(float *)(v104 + 8) )
        break;
      v16 = &array_77EC08[pStruct9_global->dword_00002C];
      v17 = sub_488EEF(pClass51_global, v102, v101);
      *(_WORD *)(v16 + 76) = v17;
      if ( v17 != -1 )
      {
        v19 = sub_488EB1(pClass51_global, v102, v101);
        LOWORD(v19) = v19 | 0x8010;
        v20 = LODWORD(v100);
        *(_DWORD *)(v16 + 48) = v19;
        v21 = v93;
        *(_BYTE *)(v16 + 89) = 1;
        *(_BYTE *)(v16 + 93) = v20;
        *(_DWORD *)(v16 + 52) = *(_WORD *)(v21 + 2);
        v22 = v95;
        *(_BYTE *)(v16 + 92) = v95;
        v18 = (unsigned __int16)word_75D514[2 * (v20 + (v22 << 7)) + 1];
        if ( v18 < 0 || v18 > dword_73D510 - 1 )
          v23 = 0;
        else
          v23 = dword_76D514 + 12 * v18;
        v109 = v23;
        if ( v23 )
        {
          v24 = -(v98 * *(float *)(v23 + 8) + v97 * *(float *)(v23 + 4) + v96 * *(float *)v23);
          if ( v24 < 0.0 )
            v24 = 0.0;
          v100 = v24 * 31.0;
          v77 = v100 + 6.755399441055744e15;
          v85 = LODWORD(v77);
          *(_BYTE *)(v16 + 88) = 31 - LOBYTE(v77);
        }
        else
        {
          *(_BYTE *)(v16 + 88) = 0;
        }
        if ( pStruct9_global->dword_00002C >= 1999 )
          return;
        ++pStruct9_global->dword_00002C;
        if ( !sub_481FC9(v10, v103, v104, v16) )
          goto LABEL_104;
        v25 = 1.0 / (*(float *)(v106 + 12) + 0.0000001000000011686097);
        memcpy(&unk_50AC10, (const void *)v106, 0x30u);
        flt_50AC30 = v25;
        flt_50AC34 = 0.0;
        flt_50AC38 = 0.0;
        v26 = *(float *)(v103 + 12) + 0.0000001000000011686097;
        memcpy(&unk_50AC40, (const void *)v103, 0x30u);
        flt_50AC60 = 1.0 / v26;
        flt_50AC64 = 0.0;
        flt_50AC68 = 1.0;
        v27 = *(float *)(v105 + 12) + 0.0000001000000011686097;
        memcpy(&unk_50AC70, (const void *)v105, 0x30u);
        flt_50AC90 = 1.0 / v27;
        flt_50AC94 = 1.0;
        flt_50AC98 = 1.0;
        v28 = *(float *)(v104 + 12) + 0.0000001000000011686097;
        memcpy(&unk_50ACA0, (const void *)v104, 0x30u);
        flt_50ACC0 = 1.0 / v28;
        flt_50ACC4 = 1.0;
        flt_50ACC8 = 0.0;
        compile_error;//sub_45D036(v109, (int)&v92, COERCE_FLOAT(&unk_50AC10), COERCE_FLOAT(4), 1);
        if ( dword_F8ADD4 <= 0 )
        {
          *(_BYTE *)(v16 + 264) = 0;
        }
        else
        {
          compile_error;//v29 = pGame;
          *(_BYTE *)(v16 + 264) = 1;
          sub_45CA88(*(void **)(LODWORD(v29) + 3656), (int)&dword_F8AD28, (int)&unk_50AC10, 4, v109);
        }
        if ( *(float *)(v106 + 12) < 8.0
          || *(float *)(v103 + 12) < 8.0
          || (v30 = v104, *(float *)(v104 + 12) < 8.0)
          || *(float *)(v105 + 12) < 8.0 )
        {
          v35 = sub_4250FE(4);
        }
        else
        {
          v31 = (double)pStruct9_global->shading_dist_mist;
          if ( v31 >= *(float *)(v106 + 12)
            && v31 >= *(float *)(v103 + 12)
            && v31 >= *(float *)(v104 + 12)
            && v31 >= *(float *)(v105 + 12) )
          {
            v32 = sub_4254D2(4);
            *(_DWORD *)(v16 + 20) = v32;
            if ( !v32 )
              goto LABEL_104;
            v33 = v103;
            v34 = v106;
            v70 = 0;
            v69 = v16;
            v68 = v30;
            goto LABEL_37;
          }
          v35 = sub_4252E8(4);
        }
        v36 = v35;
        if ( !v35 )
          goto LABEL_104;
LABEL_41:
        sub_481E55(v36);
LABEL_102:
        v32 = sub_4254D2(v36);
        *(_DWORD *)(v16 + 20) = v32;
        if ( !v32 )
          goto LABEL_104;
        sub_48276F(v16);
        goto LABEL_38;
      }
LABEL_105:
      v3 = v91 + 1;
      //v67 = __SETO__(v91 + 1, v82);
      //v66 = v91++ + 1 - v82 < 0;
      if (++v91 >= v82)
        return;
    }
    v37 = &array_77EC08[pStruct9_global->dword_00002C];
    v38 = sub_488EEF(pClass51_global, v102, v101);
    *(_WORD *)(v37 + 76) = v38;
    if ( v38 == -1 )
      goto LABEL_105;
    v40 = sub_488EB1(pClass51_global, v102, v101);
    BYTE1(v40) |= 0x80u;
    v41 = LODWORD(v100);
    *(_DWORD *)(v37 + 48) = v40;
    v42 = v93;
    *(_BYTE *)(v37 + 89) = 1;
    *(_BYTE *)(v37 + 93) = v41;
    *(_DWORD *)(v37 + 52) = *(_WORD *)(v42 + 2);
    v43 = v95;
    *(_BYTE *)(v37 + 92) = v95;
    v44 = 4 * (v41 + (v43 << 7));
    LODWORD(v94) = v44;
    v39 = *(unsigned __int16 *)((char *)word_75D514 + v44 + 2);
    if ( v39 < 0 || v39 > dword_73D510 - 1 )
      v45 = 0;
    else
      v45 = dword_76D514 + 12 * v39;
    v110 = v45;
    if ( v45 )
    {
      v46 = -(v98 * *(float *)(v45 + 8) + v97 * *(float *)(v45 + 4) + v96 * *(float *)v45);
      if ( v46 < 0.0 )
        v46 = 0.0;
      v89 = v46 * 31.0;
      v75 = v89 + 6.755399441055744e15;
      v88 = LODWORD(v75);
      *(_BYTE *)(v37 + 88) = 31 - LOBYTE(v75);
    }
    else
    {
      *(_BYTE *)(v37 + 88) = 0;
    }
    if ( *(_BYTE *)(v37 + 88) < 0 )
      *(_BYTE *)(v37 + 88) = 0;
    if ( pStruct9_global->dword_00002C >= 1999 )
      return;
    ++pStruct9_global->dword_00002C;
    if ( !sub_481FC9(v103, v105, v106, v37) )
      goto LABEL_74;
    v47 = 1.0 / (*(float *)(v106 + 12) + 0.0000001000000011686097);
    memcpy(&unk_50AC10, (const void *)v106, 0x30u);
    flt_50AC30 = v47;
    flt_50AC34 = 0.0;
    flt_50AC38 = 0.0;
    v48 = *(float *)(v103 + 12) + 0.0000001000000011686097;
    memcpy(&unk_50AC40, (const void *)v103, 0x30u);
    flt_50AC60 = 1.0 / v48;
    flt_50AC64 = 0.0;
    flt_50AC68 = 1.0;
    v49 = *(float *)(v105 + 12) + 0.0000001000000011686097;
    memcpy(&unk_50AC70, (const void *)v105, 0x30u);
    flt_50AC90 = 1.0 / v49;
    flt_50AC94 = 1.0;
    flt_50AC98 = 1.0;
    compile_error;//sub_45D036(v110, (int)&v79, COERCE_FLOAT(&unk_50AC10), COERCE_FLOAT(3), 0);
    if ( dword_F8ADD4 <= 0 )
    {
      *(_BYTE *)(v37 + 264) = 0;
    }
    else
    {
      compile_error;//v50 = pGame;
      *(_BYTE *)(v37 + 264) = 1;
      sub_45CA88(*(void **)(LODWORD(v50) + 3656), (int)&dword_F8AD28, (int)&unk_50AC10, 3, v110);
    }
    if ( *(float *)(v106 + 12) < 8.0 || *(float *)(v103 + 12) < 8.0 || (v51 = v105, *(float *)(v105 + 12) < 8.0) )
    {
      v54 = sub_4250FE(3);
    }
    else
    {
      v52 = (double)pStruct9_global->shading_dist_mist;
      if ( v52 >= *(float *)(v106 + 12) && v52 >= *(float *)(v103 + 12) && v52 >= *(float *)(v105 + 12) )
      {
        v53 = sub_4254D2(3);
        *(_DWORD *)(v37 + 20) = v53;
        if ( v53 )
        {
          sub_4829B9(v103, v51, v106, v37, 0);
LABEL_68:
          sub_481DB2((int)flt_508690, v53, v37);
LABEL_75:
          v16 = &array_77EC08[pStruct9_global->dword_00002C];
          v56 = sub_488EEF(pClass51_global, v102, v101);
          *(_WORD *)(v16 + 76) = v56;
          if ( v56 == -1 )
            goto LABEL_105;
          *(_DWORD *)(v16 + 48) = sub_488EB1(pClass51_global, v102, v101);
          v58 = v93;
          *(_BYTE *)(v16 + 89) = 1;
          *(_DWORD *)(v16 + 52) = *(_WORD *)(v58 + 2);
          *(_BYTE *)(v16 + 92) = v95;
          *(_BYTE *)(v16 + 93) = LOBYTE(v100);
          v57 = *(unsigned __int16 *)((char *)word_75D514 + LODWORD(v94));
          if ( v57 > dword_73D510 - 1 )
          {
            v111 = 0;
            v59 = 0;
          }
          else
          {
            v59 = dword_76D514 + 12 * v57;
            v111 = v59;
          }
          if ( v59 )
          {
            v60 = -(v98 * *(float *)(v59 + 8) + v97 * *(float *)(v59 + 4) + v96 * *(float *)v59);
            if ( v60 < 0.0 )
              v60 = 0.0;
            v94 = v60 * 31.0;
            v73 = v94 + 6.755399441055744e15;
            v84 = LODWORD(v73);
            *(_BYTE *)(v16 + 88) = 31 - LOBYTE(v73);
          }
          else
          {
            *(_BYTE *)(v16 + 88) = 0;
          }
          if ( *(_BYTE *)(v16 + 88) < 0 )
            *(_BYTE *)(v16 + 88) = 0;
          if ( pStruct9_global->dword_00002C >= 1999 )
            return;
          ++pStruct9_global->dword_00002C;
          if ( !sub_481FC9(v104, v106, v105, v16) )
          {
LABEL_104:
            --pStruct9_global->dword_00002C;
            goto LABEL_105;
          }
          v61 = 1.0 / (*(float *)(v106 + 12) + 0.0000001000000011686097);
          memcpy(&unk_50AC10, (const void *)v106, 0x30u);
          flt_50AC30 = v61;
          flt_50AC34 = 0.0;
          flt_50AC38 = 0.0;
          v62 = *(float *)(v105 + 12) + 0.0000001000000011686097;
          memcpy(&unk_50AC40, (const void *)v105, 0x30u);
          flt_50AC60 = 1.0 / v62;
          flt_50AC64 = 1.0;
          flt_50AC68 = 1.0;
          v63 = *(float *)(v104 + 12) + 0.0000001000000011686097;
          memcpy(&unk_50AC70, (const void *)v104, 0x30u);
          flt_50AC90 = 1.0 / v63;
          flt_50AC94 = 1.0;
          flt_50AC98 = 0.0;
          compile_error;//sub_45D036(v111, (int)&v71, COERCE_FLOAT(&unk_50AC10), COERCE_FLOAT(3), 1);
          if ( dword_F8ADD4 <= 0 )
          {
            *(_BYTE *)(v16 + 264) = 0;
          }
          else
          {
            compile_error;//v64 = pGame;
            *(_BYTE *)(v16 + 264) = 1;
            sub_45CA88(*(void **)(LODWORD(v64) + 3656), (int)&dword_F8AD28, (int)&unk_50AC10, 3, v111);
          }
          if ( *(float *)(v106 + 12) < 8.0 || *(float *)(v105 + 12) < 8.0 || *(float *)(v104 + 12) < 8.0 )
          {
            v36 = sub_4250FE(3);
            sub_481E55(v36);
            if ( !v36 )
              goto LABEL_104;
            goto LABEL_102;
          }
          v65 = (double)pStruct9_global->shading_dist_mist;
          if ( v65 < *(float *)(v106 + 12) || v65 < *(float *)(v105 + 12) || v65 < *(float *)(v104 + 12) )
          {
            v36 = sub_4252E8(3);
            if ( !v36 )
              goto LABEL_105;
            goto LABEL_41;
          }
          v32 = sub_4254D2(3);
          *(_DWORD *)(v16 + 20) = v32;
          if ( !v32 )
            goto LABEL_104;
          v33 = v106;
          v34 = v104;
          v70 = 0;
          v69 = v16;
          v68 = v105;
LABEL_37:
          sub_4829B9(v34, v33, v68, v69, v70);
LABEL_38:
          sub_481DB2((int)flt_508690, v32, v16);
          goto LABEL_105;
        }
        goto LABEL_74;
      }
      v54 = sub_4252E8(3);
    }
    v55 = v54;
    if ( v54 )
    {
      sub_481E55(v54);
      v53 = sub_4254D2(v55);
      *(_DWORD *)(v37 + 20) = v53;
      if ( v53 )
      {
        sub_48276F(v37);
        goto LABEL_68;
      }
    }
LABEL_74:
    --pStruct9_global->dword_00002C;
    goto LABEL_75;
  }
}

//----- (00403854) --------------------------------------------------------
int __fastcall sub_403854(int a1, signed int a2, signed int a3)
{
  int v3; // ebx@1
  int v4; // edi@3
  int v5; // esi@3
  int v6; // eax@4
  int result; // eax@7
  char *v8; // eax@8
  unsigned int v9; // esi@8
  void *v10; // esi@9
  int v11; // eax@10
  int v12; // ecx@10
  __int16 v13; // ax@10
  signed int v14; // ecx@10
  signed int v15; // ecx@17
  char v16; // [sp+Ch] [bp-48h]@9
  char v17; // [sp+28h] [bp-2Ch]@9
  int v18; // [sp+44h] [bp-10h]@6
  int v19; // [sp+48h] [bp-Ch]@1
  int v20; // [sp+4Ch] [bp-8h]@3
  int v21; // [sp+50h] [bp-4h]@1
  signed int v22; // [sp+5Ch] [bp+8h]@10

  v21 = a1;
  v3 = &pActors[a1];
  v19 = a2;
  if ( (a2 & 7) == 3 )
  {
    v6 = 836 * (a2 >> 3);
    v5 = pActors[a2 >> 3].word_00008E;
    v4 = pActors[a2 >> 3].word_000090;
    v20 = (signed __int64)((double)pActors[a2 >> 3].word_00008A * *(double *)&byte_4D8410[72]
                         + (double)pActors[a2 >> 3].word_000092);
  }
  else
  {
    if ( (a2 & 7) == 4 )
    {
      v5 = pParty_global->dword_0006B4;
      v4 = pParty_global->dword_0006B8;
      v20 = pParty_global->dword_0006BC + pParty_global->dword_00000C;
    }
    else
    {
      v5 = a3;
      v4 = a3;
    }
  }
  v18 = *(_WORD *)(v3 + 138);
  if ( sub_407A1C(
         v5,
         v4,
         v20,
         *(_WORD *)(v3 + 142),
         *(_WORD *)(v3 + 144),
         *(_WORD *)(v3 + 146) - (unsigned int)(signed __int64)((double)v18 * *(double *)&byte_4D8410[64])) )
  {
    v8 = (char *)a3;
    v9 = 0;
    if ( !a3 )
    {
      v10 = sub_4040E9(8 * v21 | 3, v19, &v16, 0);
      v8 = &v17;
      memcpy(&v17, v10, 0x1Cu);
      v9 = 0;
    }
    //v12 = dword_5C6DCC;
    v12 = pSpriteFrameTable->pSpriteSFrames;

    *(_WORD *)(v3 + 154) = *((_WORD *)v8 + 10);
    v13 = *(_WORD *)(60 * *(_WORD *)(v3 + 194) + v12 + 56);
    v14 = v21;
    *(_WORD *)(v3 + 160) = 8 * v13;
    *(_DWORD *)(v3 + 184) = v9;
    *(_WORD *)(v3 + 176) = 13;
    sub_402CED(v14, 0);
    v11 = pMonsterStats->pMonsterInfos[*(_WORD *)(v3 + 96)].dword_000050;
    v22 = pMonsterStats->pMonsterInfos[*(_WORD *)(v3 + 96)].dword_000050;
    if ( *(_DWORD *)(v3 + 328) >= (signed int)v9 )
    {
      if ( *(_DWORD *)(v3 + 328) > (signed int)v9 || *(_DWORD *)(v3 + 324) > v9 )
      {
        v11 *= 2;
        v22 = v11;
      }
    }
    if ( dword_ACD834 == 1 )
      *(_DWORD *)(v3 + 124) = v11;
    else
      *(_DWORD *)(v3 + 124) = *(_WORD *)(v3 + 160)
                            - (unsigned int)(signed __int64)(flt_6BE3A8 * (double)v22 * *(double *)&byte_4D8410[56]);
    v15 = *(_BYTE *)(v3 + 77);
    *(_WORD *)(v3 + 152) = v9;
    *(_WORD *)(v3 + 150) = v9;
    *(_WORD *)(v3 + 148) = v9;
    if ( sub_42FB5C(v15) )
    {
      *(_WORD *)(v3 + 160) = 64;
      *(_DWORD *)(v3 + 184) = v9;
      *(_WORD *)(v3 + 176) = 9;
      result = sub_45976D(v3);
      *(_WORD *)(v3 + 176) = 13;
    }
    else
    {
      result = sub_45976D(v3);
    }
  }
  else
  {
    result = sub_402AD7(v21, v19, v21, 64, a3);
  }
  return result;
}

//----- (0046086A) --------------------------------------------------------
int __cdecl MaybeDoAutosave()
{
  signed int v0; // esi@3
  int v1; // eax@4
  int v2; // edx@5
  int v3; // eax@7
  char v4; // zf@7

  //local struct
  char v6[4 + 32*array_size_unknown]; // [sp+Ch] [bp-16Ch]@3
  char Dest[80 + 4*array_size_unknown]; // [sp+10h] [bp-168h]@3
  char v8[80 + 4*array_size_unknown]; // [sp+60h] [bp-118h]@3
  int v9; // [sp+B0h] [bp-C8h]@3
  int v10; // [sp+B4h] [bp-C4h]@3
  char v11[32 + 4*array_size_unknown]; // [sp+10Ch] [bp-6Ch]@4
  char v12[20 + 4*array_size_unknown]; // [sp+12Ch] [bp-4Ch]@9
  int v13; // [sp+140h] [bp-38h]@9

  //local struct
  char v14[24 + 4*array_size_unknown]; // [sp+14Ch] [bp-2Ch]@3
  int v15; // [sp+164h] [bp-14h]@3
  __int16 v16; // [sp+16Ah] [bp-Eh]@3
  int v17; // [sp+16Ch] [bp-Ch]@5
  void *DstBuf; // [sp+170h] [bp-8h]@3
  int v19; // [sp+174h] [bp-4h]@5

  if ( CVideoPlayer_IsAnyMovieLoaded(pVideoPlayer) )
    CVideoPlayer_UnloadAll(pVideoPlayer);
  v0 = 0;
  DstBuf = (void *)class23_AllocatedNamedBuffer(class23_instance, 0, 1000000, 0);
  sub_461EE9(pClass17_New_LOD);
  remove("data\\new.lod");

  sub_4617B6(v6);
  strcpy(Dest, "MMVII");
  strcpy(v8, "newmaps for MMVII");
  v9 = 100;
  v10 = 0;

  sub_46172B(v14);
  v15 = 0;
  v16 = 0;
  strcpy(v14, "current");

  sub_461492(pClass17_New_LOD, v6, v14, "data\\new.lod");

  if ( class17_LoadLOD_Games(pClass17_New_LOD, "data\\new.lod", 0) )
  {
    sub_461F1E(pClass17_New_LOD);
    dword_6A0A4C = 0;
    sub_461743(v11);
    v1 = dword_6A0C8C / 2;
    if ( dword_6A0C8C / 2 < dword_6A0C8C )
    {
      v2 = 32 * v1;
      v19 = 32 * v1;
      v17 = dword_6A0C8C - v1;
      while ( 1 )
      {
        memcpy(v11, (const void *)(v2 + dword_6A0C90), 0x20u);
        v3 = class17_FindContainer(pClass17_Games_LOD, (const char *)(v2 + dword_6A0C90), 1);
        locked_fread(DstBuf, *(_DWORD *)(v19 + dword_6A0C90 + 20), 1u, (FILE *)v3);
        sub_461F71(pClass17_New_LOD, v11, DstBuf);
        v19 += 32;
        v4 = v17-- == 1;
        if ( v4 )
          break;
        v2 = v19;
      }
      v0 = 0;
    }
    sub_461743(v12);
    strcpy(byte_69BD7C, "out01.odm");
    strcpy(v12, "header.bin");
    v13 = 100;
    sub_461F71(pClass17_New_LOD, v12, &unk_69BD68);
    sub_461FD4(pClass17_New_LOD);

    pParty_global->dword_0006B4 = 12552;
    pParty_global->dword_0006B8 = 1816;
    pParty_global->dword_0006BC = v0;
    pParty_global->dword_0006C0 = 512;
    pParty_global->dword_0006C4 = v0;

    pParty_global->dword_0006C8 = 12552;
    pParty_global->dword_0006CC = 1816;
    pParty_global->dword_0006D0 = v0;
    pParty_global->dword_0006D4 = 512;
    pParty_global->dword_0006D8 = v0;

    pParty_global->dword_000700 = v0;

    v0 = 1;
    sub_45F469(1, 1);
  }
  class23_DeleteBuffer(class23_instance, (int)DstBuf);
  return v0;
}

//----- (00497526) --------------------------------------------------------
int __fastcall MenuLoop_CharacterCreation()
{
  signed int v3; // ecx@3
  int v4; // eax@6
  struct GUIButton *v5; // edx@6
  int v6; // edi@6
  int v7; // ecx@7
  int v8; // esi@12
  //int v9; // eax@28
  signed int v10; // edi@30
  int v11; // edx@31
  signed int v12; // ebx@37
  int v13; // esi@38
  short *v14; // eax@40
  signed int v15; // ecx@40
  signed int v16; // eax@45
  int v17; // eax@70
  signed int v18; // ecx@70
  int v20; // [sp-4h] [bp-84h]@48

  unsigned char local_0[0x44];
  //char Dst; // [sp+Ch] [bp-74h]@37
  //char v22; // [sp+30h] [bp-50h]@29
  //char v23[0x1C]; // [sp+31h] [bp-4Fh]@29
  //__int16 v24; // [sp+4Dh] [bp-33h]@29
  //char v25; // [sp+4Fh] [bp-31h]@29

  MSG Msg; // [sp+50h] [bp-30h]@17
  char v27; // [sp+6Ch] [bp-14h]@6
  int v28; // [sp+74h] [bp-Ch]@1
  char v29; // [sp+78h] [bp-8h]@6
  int v30; // [sp+7Ch] [bp-4h]@45
 int i;

  v28 = 0;
  RGBTexture_Load(pRGBTexture_Menu, "makeme", 0);
  sub_4A5B81(pD3DRenderer, 0, 0, 640, 480);

  if (dword_720010)
    sub_46B105(dword_720010);

  v3 = MENU_CREATEPARTY;
  pGUIWindow_PlayerCreation->dword_000040 = 0;
LABEL_27:
  SetCurrentMenu(v3);
  while (true)
  {
    if (sub_466CA0() != MENU_CREATEPARTY)
      break;

    if (dword_720010)
      sub_46B736(dword_720010, 1);

    class03_GetMouseClickPos(pGame->pClass03, &v6, &v4);

    v5 = pGUIWindow_PlayerCreation->pControlsHead;
    if ( v5 != 0)
    {
      v7 = dword_50CBD0[0];
      do
      {
       if (v6 >= v5->uX && v6 <= v5->uZ &&
           v4 >= v5->uY && v4 <= v5->uW)
       {
        v8 = v5->dword_000024;
                if ( v7 < 40 )
                {
                  dword_50CBD0[3 * v7 + 1] = *(_DWORD *)(v5 + 28);
                  dword_50CBD0[3 * dword_50CBD0[0] + 2] = v8;
                  dword_50CBD0[3 * dword_50CBD0[0] + 3] = 0;
                  v7 = dword_50CBD0[0]++ + 1;
                }
       }
       v5 = v5->pNext;
      }
      while ( v5);
    }

    while ( PeekMessageA(&Msg, 0, 0, 0, PM_REMOVE) )
    {
      if ( Msg.message == WM_QUIT )
        sub_464761(0);
      TranslateMessage(&Msg);
      DispatchMessageA(&Msg);
    }
    if ( BYTE1(dword_6BE364) & 1 )
    {
      WaitMessage();
    }
    else
    {
      PlayerCreationUI_Draw();
      sub_435748();
      CD3DRenderer_BeginScene(pD3DRenderer);
      sub_4156F0();
      CD3DRenderer_EndScene(pD3DRenderer);
      CD3DRenderer_Present(pD3DRenderer);
      if ( dword_6A0D48 == 1 )
      {
        v28 = 1;
        v3 = MENU_MAIN;
        goto LABEL_27;
      }
      if ( dword_6A0D48 == 6 )
      {
        dword_6A0D48 = 0;
        v3 = 1;
        goto LABEL_27;
      }
    }
  }
  //sub_40E51F(pRGBTexture_Menu);
  GUIWindowDelete(pGUIWindow_PlayerCreation);
  sub_4114F2(pClass17_Icons_LOD);

  //v22 = 0;
  local_0[0x24] = 0;
  memset(local_0 + 0x25, 0, 0x1Cu);

  //v24 = 0;
  *(short *)(local_0 + 0x41) = 0;
  //v25 = 0;
  local_0[0x43] = 0;

  for (i = 0; i < 32; ++i)
  {
    v10 = 0;
    do
    {
      v11 = rand() % 32;
      //if ( !*(&v22 + v11) )
      if (!local_0[0x24 + v11])
        break;
      ++v10;
    }
    while ( v10 < 10 );
    if ( v10 == 10 )
    {
      v11 = 0;
      //if ( v22 )
      if (local_0[0x24])
      {
        do
          ++v11;
        //while ( *(&v22 + v11) );
         while (local_0[0x24 + v11]);
      }
    }
    //byte_ACD80C[v2++] = v11;
    pParty_global->byte_000854[i] = v11;
    //*(&v22 + v11) = 1;
    local_0[0x24 + v11] = 1;
  }
  sub_402F07(local_0);

  v12 = &pParty_global->pPlayers[0].word_00177E;
  for (i = 0; i < 4; ++i)
  {
    v13 = &pParty_global->pPlayers[i];

    if (!pParty_global->pPlayers[i].uClass)
      pParty_global->pPlayers[i].word_00177E = 10;

    pParty_global->pPlayers[i].word_001A9E = 0;
    v15 = 0;
    v14 = &pParty_global->pPlayers[i].array_000108[12];// v12 - 5726;
    while (!*v14++)
    {
      ++v15;
      if ( v15 >= 9 )
        goto LABEL_45;
    }
    pParty_global->pPlayers[i].byte_001A4E = v15;

LABEL_45:
    sub_456620(pClass40, 2, 40, local_0);
    sub_492826(&pParty_global->pPlayers[i], -1, local_0);
    v16 = 0;
    v30 = 0;
    do
    {
      if (pParty_global->pPlayers[i].array_000108[v16])
      {
        switch ( v16 )
        {
          case 0:
            v20 = 61;
            goto LABEL_69;
          case 1:
            v20 = 1;
            goto LABEL_69;
          case 2:
            v20 = 15;
            goto LABEL_69;
          case 3:
            v20 = 23;
            goto LABEL_69;
          case 4:
            v20 = 31;
            goto LABEL_69;
          case 5:
            v20 = 47;
            goto LABEL_69;
          case 6:
            v20 = 50;
            goto LABEL_69;
          case 8:
            v20 = 84;
            goto LABEL_69;
          case 9:
            v20 = 66;
            goto LABEL_69;
          case 10:
            v20 = 71;
            goto LABEL_69;
          case 11:
            v20 = 76;
            goto LABEL_69;
          case 12:
            sub_4927A8(&pParty_global->pPlayers[i], -1, 401);
            pParty_global->pPlayers[i].byte_000192 = 1;
            break;
          case 13:
            sub_4927A8(&pParty_global->pPlayers[i], -1, 412);
            pParty_global->pPlayers[i].byte_00019D = 1;
            break;
          case 14:
            sub_4927A8(&pParty_global->pPlayers[i], -1, 423);
            pParty_global->pPlayers[i].byte_0001A8 = 1;
            break;
          case 15:
            sub_4927A8(&pParty_global->pPlayers[i], -1, 434);
            pParty_global->pPlayers[i].byte_0001B3 = 1;
            break;
          case 16:
            sub_4927A8(&pParty_global->pPlayers[i], -1, 445);
            pParty_global->pPlayers[i].byte_0001BE = 1;
            break;
          case 17:
            sub_4927A8(&pParty_global->pPlayers[i], -1, 456);
            pParty_global->pPlayers[i].byte_0001C9 = 1;
            break;
          case 18:
            sub_4927A8(&pParty_global->pPlayers[i], -1, 467);
            pParty_global->pPlayers[i].byte_0001D4 = 1;
            break;
          case 21:
          case 23:
          case 25:
          case 26:
          case 29:
          case 36:
            sub_4927A8(&pParty_global->pPlayers[i], -1, 220);
            v20 = 5 * (rand() % 3 + 40);
            goto LABEL_69;
          case 30:
            v20 = 115;
            goto LABEL_69;
          case 31:
            v20 = 110;
LABEL_69:
            sub_4927A8(&pParty_global->pPlayers[i], -1, v20);
            break;
          default:
            break;
        }
        v17 = v13 + 552;
        v18 = 138;
        do
        {
          if ( *(_DWORD *)(v17 - 20) )
            *(_DWORD *)v17 |= 1u;
          v17 += 36;
          --v18;
        }
        while ( v18 );
        pParty_global->pPlayers[i].dword_00193C = sub_48E4F8(&pParty_global->pPlayers[i]);
        pParty_global->pPlayers[i].dword_001940 = sub_48E565(&pParty_global->pPlayers[i]);
        v16 = v30;
      }
      ++v16;
      v30 = v16;
    }
    while ( v16 < 37 );
    v12 += 6972;
  }


  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  if (dword_720010)
    Mouse_suspend(dword_720010);
  return v28;
}

//----- (00486AFC) --------------------------------------------------------
void __cdecl ReleaseDrawBuffers()
{

  class23_DeleteBuffer(class23_instance, pSpansBuf);
  class23_DeleteBuffer(class23_instance, pEdgesBuf);
  class23_DeleteBuffer(class23_instance, pSurfsBuf);
  class23_DeleteBuffer(class23_instance, pNewEdgesBuf);
  pSpansBuf = 0;
  pEdgesBuf = 0;
  pSurfsBuf = 0;
  pNewEdgesBuf = 0;
}

//----- (00403A60) --------------------------------------------------------
int __fastcall sub_403A60(int a1, signed int a2, signed int a3)
{
  int v3; // ebx@1
  int v4; // edi@3
  int v5; // esi@3
  int v6; // eax@4
  int result; // eax@7
  char *v8; // eax@8
  unsigned int v9; // esi@8
  void *v10; // esi@9
  int v11; // eax@10
  int v12; // ecx@10
  __int16 v13; // ax@10
  signed int v14; // ecx@10
  signed int v15; // ecx@17
  char v16; // [sp+Ch] [bp-48h]@9
  char v17; // [sp+28h] [bp-2Ch]@9
  int v18; // [sp+44h] [bp-10h]@6
  int v19; // [sp+48h] [bp-Ch]@1
  int v20; // [sp+4Ch] [bp-8h]@3
  int v21; // [sp+50h] [bp-4h]@1
  signed int v22; // [sp+5Ch] [bp+8h]@10

  v21 = a1;
  v3 = &pActors[a1];
  v19 = a2;
  if ( (a2 & 7) == 3 )
  {
    v6 = 836 * (a2 >> 3);
    v5 = pActors[a2 >> 3].word_00008E;
    v4 = pActors[a2 >> 3].word_000090;
    v20 = (signed __int64)((double)pActors[a2 >> 3].word_00008A * *(double *)&byte_4D8410[72]
                         + (double)pActors[a2 >> 3].word_000092);
  }
  else
  {
    if ( (a2 & 7) == 4 )
    {
      v5 = pParty_global->dword_0006B4;
      v4 = pParty_global->dword_0006B8;
      v20 = pParty_global->dword_0006BC + pParty_global->dword_00000C;
    }
    else
    {
      v5 = a3;
      v4 = a3;
    }
  }
  v18 = *(_WORD *)(v3 + 138);
  if ( sub_407A1C(
         v5,
         v4,
         v20,
         *(_WORD *)(v3 + 142),
         *(_WORD *)(v3 + 144),
         *(_WORD *)(v3 + 146) - (unsigned int)(signed __int64)((double)v18 * *(double *)&byte_4D8410[64])) )
  {
    v8 = (char *)a3;
    v9 = 0;
    if ( !a3 )
    {
      v10 = sub_4040E9(8 * v21 | 3, v19, &v16, 0);
      v8 = &v17;
      memcpy(&v17, v10, 0x1Cu);
      v9 = 0;
    }
    //v12 = dword_5C6DCC;
    v12 = pSpriteFrameTable->pSpriteSFrames;

    *(_WORD *)(v3 + 154) = *((_WORD *)v8 + 10);
    v13 = *(_WORD *)(60 * *(_WORD *)(v3 + 194) + v12 + 56);
    v14 = v21;
    *(_WORD *)(v3 + 160) = 8 * v13;
    *(_DWORD *)(v3 + 184) = v9;
    *(_WORD *)(v3 + 176) = 18;
    sub_402CED(v14, 0);
    v11 = pMonsterStats->pMonsterInfos[*(_WORD *)(v3 + 96)].dword_000050;
    v22 = pMonsterStats->pMonsterInfos[*(_WORD *)(v3 + 96)].dword_000050;
    if ( *(_DWORD *)(v3 + 328) >= (signed int)v9 )
    {
      if ( *(_DWORD *)(v3 + 328) > (signed int)v9 || *(_DWORD *)(v3 + 324) > v9 )
      {
        v11 *= 2;
        v22 = v11;
      }
    }
    if ( dword_ACD834 == 1 )
      *(_DWORD *)(v3 + 124) = v11;
    else
      *(_DWORD *)(v3 + 124) = *(_WORD *)(v3 + 160)
                            - (unsigned int)(signed __int64)(flt_6BE3A8 * (double)v22 * *(double *)&byte_4D8410[56]);
    v15 = *(_BYTE *)(v3 + 79);
    *(_WORD *)(v3 + 152) = v9;
    *(_WORD *)(v3 + 150) = v9;
    *(_WORD *)(v3 + 148) = v9;
    if ( sub_42FB5C(v15) )
    {
      *(_WORD *)(v3 + 160) = 64;
      *(_DWORD *)(v3 + 184) = v9;
      *(_WORD *)(v3 + 176) = 9;
      result = sub_45976D(v3);
      *(_WORD *)(v3 + 176) = 18;
    }
    else
    {
      result = sub_45976D(v3);
    }
  }
  else
  {
    result = sub_402AD7(v21, v19, v21, 64, a3);
  }
  return result;
}

//----- (00403C6C) --------------------------------------------------------
int __fastcall sub_403C6C(int a1, int a2, char *a3)
{
  int v3; // ebx@1
  char v4; // zf@1
  int result; // eax@3
  int v6; // edi@6
  int v7; // esi@6
  int v8; // eax@7
  double v9; // st7@9
  int v10; // eax@10
  char *v11; // eax@11
  unsigned int v12; // esi@11
  void *v13; // esi@12
  signed __int64 v14; // qax@13
  int v15; // ecx@13
  __int16 v16; // ax@13
  signed int v17; // ecx@13
  char v18; // [sp+Ch] [bp-48h]@12
  char v19; // [sp+28h] [bp-2Ch]@12
  int v20; // [sp+44h] [bp-10h]@9
  int v21; // [sp+48h] [bp-Ch]@1
  int v22; // [sp+4Ch] [bp-8h]@6
  int v23; // [sp+50h] [bp-4h]@1
  signed int v24; // [sp+5Ch] [bp+8h]@13

  v3 = (int)((char *)pActors + 836 * a1);
  v21 = a2;
  v4 = *(_BYTE *)(v3 + 59) == 5;
  v23 = a1;
  if ( v4 && *(_BYTE *)(v3 + 60) == 1 )
  {
    result = sub_403EB6(a1, a2, 0, a3);
  }
  else
  {
    if ( (a2 & 7) == 3 )
    {
      v8 = 836 * (a2 >> 3);
      v7 = pActors[a2 >> 3].word_00008E;
      v6 = pActors[a2 >> 3].word_000090;
      v22 = (signed __int64)((double)pActors[a2 >> 3].word_00008A * *(double *)&byte_4D8410[72]
                           + (double)pActors[a2 >> 3].word_000092);
    }
    else
    {
      if ( (a2 & 7) == 4 )
      {
        v7 = pParty_global->dword_0006B4;
        v6 = pParty_global->dword_0006B8;
        v22 = pParty_global->dword_0006BC + pParty_global->dword_00000C;
      }
      else
      {
        v7 = (int)a3;
        v6 = (int)a3;
      }
    }
    v20 = *(_WORD *)(v3 + 138);
    v9 = (double)v20 * *(double *)&byte_4D8410[72];
    v20 = *(_WORD *)(v3 + 146);
    if ( sub_407A1C(v7, v6, v22, *(_WORD *)(v3 + 142), *(_WORD *)(v3 + 144), (signed __int64)(v9 + (double)v20)) )
    {
      v11 = a3;
      v12 = 0;
      if ( !a3 )
      {
        v13 = sub_4040E9(8 * v23 | 3, v21, &v18, 0);
        v11 = &v19;
        memcpy(&v19, v13, 0x1Cu);
        v12 = 0;
      }
      //v15 = dword_5C6DCC;
      v15 = pSpriteFrameTable->pSpriteSFrames;

      *(_WORD *)(v3 + 154) = *((_WORD *)v11 + 10);
      v16 = *(_WORD *)(60 * *(_WORD *)(v3 + 192) + v15 + 56);
      v17 = v23;
      *(_WORD *)(v3 + 160) = 8 * v16;
      *(_DWORD *)(v3 + 184) = v12;
      *(_WORD *)(v3 + 176) = 2;
      sub_402CED(v17, 0);
      LODWORD(v14) = pMonsterStats->pMonsterInfos[*(_WORD *)(v3 + 96)].dword_000050;
      v24 = pMonsterStats->pMonsterInfos[*(_WORD *)(v3 + 96)].dword_000050;
      if ( *(_DWORD *)(v3 + 328) >= (signed int)v12 )
      {
        if ( *(_DWORD *)(v3 + 328) > (signed int)v12 || *(_DWORD *)(v3 + 324) > v12 )
        {
          LODWORD(v14) = 2 * v14;
          v24 = v14;
        }
      }
      if ( dword_ACD834 != 1 )
        v14 = (signed __int64)(flt_6BE3A8 * (double)v24 * *(double *)&byte_4D8410[40]);
      *(_DWORD *)(v3 + 124) = v14;
      *(_WORD *)(v3 + 152) = v12;
      *(_WORD *)(v3 + 150) = v12;
      *(_WORD *)(v3 + 148) = v12;
      result = sub_45976D(v3);
    }
    else
    {
      v10 = rand();
      result = sub_402AD7(v23, v21, v10 % 2, 64, (signed int)a3);
    }
  }
  return result;
}

//----- (00466CA0) --------------------------------------------------------
int __cdecl sub_466CA0()
{
  return uCurrentMenuID;
}

//----- (0044CB4F) --------------------------------------------------------
int __fastcall sub_44CB4F(int a1, int a2, signed int a3, int a4, __int16 a5, const char *Str1, signed int Source, int a8)
{
  int v8; // ebx@1
  int v9; // edi@1
  signed int v11; // esi@3
  unsigned __int8 v12; // cl@7
  int v13; // ebx@19
  int v14; // esi@19
  unsigned __int8 v15; // cl@21
  int v16; // eax@22
  int v17; // ecx@22
  int v18; // ecx@23
  int v19; // ecx@24
  int v20; // ecx@26
  int v21; // eax@28
  int v22; // ebx@34
  int v23; // eax@34
  int v24; // ebx@36
  char Dest; // [sp+Ch] [bp-20h]@34
  char v26; // [sp+Fh] [bp-1Dh]@34
  char v27; // [sp+11h] [bp-1Bh]@35
  int v28; // [sp+20h] [bp-Ch]@17
  int v29; // [sp+24h] [bp-8h]@1
  size_t v30; // [sp+28h] [bp-4h]@1
  int i; // [sp+40h] [bp+14h]@5
  int v32; // [sp+40h] [bp+14h]@19
  const char *v33; // [sp+44h] [bp+18h]@20
  int v34; // [sp+48h] [bp+1Ch]@26

  v9 = a2;
  v29 = a1;
  v30 = strlen(Str1);
  v8 = sub_44C51E(v9, Str1);
  if ( v8 < Source )
  {
    FontDrawText(v29, v9, a3, a4, a5, Str1, 0, 0, 0);
    return v8;
  }
  strcpy(pStringBuffer, Str1);
  v11 = 0;
  if ( a8 )
    _strrev(pStringBuffer);
  for ( i = 0; i < (signed int)v30; ++i )
  {
    if ( v11 >= Source )
      break;
    if ( sub_44C4DE(pStringBuffer[i], v9) )
    {
      if ( v12 < 9u )
        goto LABEL_12;
      if ( v12 > 0xAu )
      {
        if ( v12 == 12 )
        {
          i += 5;
        }
        else
        {
          if ( v12 != 13 )
          {
LABEL_12:
            if ( i > 0 )
              v11 += *(_DWORD *)(v9 + 12 * v12 + 32);
            v11 += *(_DWORD *)(v9 + 4 * (3 * v12 + 9));
            if ( i < (signed int)v30 )
              v11 += *(_DWORD *)(v9 + 12 * v12 + 40);
            continue;
          }
        }
      }
    }
  }
  byte_5C657F[i] = 0;
  v30 = strlen(pStringBuffer);
  v28 = sub_44C51E(v9, pStringBuffer);
  if ( a8 )
    _strrev(pStringBuffer);
  v32 = 0;
  v14 = a3 + *(_DWORD *)v29;
  v13 = a4 + *(_DWORD *)(v29 + 4);
  if ( (signed int)v30 > 0 )
  {
    v33 = pStringBuffer + 1;
    do
    {
      if ( sub_44C4DE(pStringBuffer[v32], v9) )
      {
        v16 = v15;
        v17 = v15 - 9;
        if ( v17 )
        {
          v18 = v17 - 1;
          if ( v18 )
          {
            v19 = v18 - 2;
            if ( v19 )
            {
              if ( v19 == 1 )
              {
                strncpy(&Dest, v33, 3u);
                v26 = 0;
                v32 += 3;
                v33 += 3;
                v22 = atoi(&Dest);
                v23 = sub_44C51E(v9, &pStringBuffer[v32]);
                v14 = *(_DWORD *)(v29 + 16) - v23 - v22;
                v13 = a4;
              }
              else
              {
                v20 = *(_DWORD *)(v9 + 4 * (3 * v16 + 9));
                v34 = *(_DWORD *)(v9 + 4 * (3 * v16 + 9));
                if ( v32 > 0 )
                  v14 += *(_DWORD *)(v9 + 12 * v16 + 32);
                v21 = *(_DWORD *)(v9 + 4 * v16 + 3104) + v9 + 4128;
                if ( a5 )
                  sub_4A6C4F(pD3DRenderer, v14, v13, v21, v20, *(_BYTE *)(v9 + 5), *(_DWORD *)(v9 + 12), a5, 0);
                else
                  sub_4A6AB1(pD3DRenderer, v14, v13, v21, v20, *(_BYTE *)(v9 + 5), *(_DWORD *)(v9 + 12), 0);
                v14 += v34;
                if ( v32 < (signed int)v30 )
                  v14 += *(_DWORD *)(v9 + 12 * (unsigned __int8)pStringBuffer[v32] + 40);
              }
            }
            else
            {
              strncpy(&Dest, v33, 5u);
              v27 = 0;
              v32 += 5;
              v33 += 5;
              *(_DWORD *)&a5 = atoi(&Dest);
            }
          }
          else
          {
            v24 = *(_BYTE *)(v9 + 5);
            v14 = a3;
            a4 = a4 + v24 - 3;
            v13 = v24 + a4 - 3;
          }
        }
        else
        {
          strncpy(&Dest, v33, 3u);
          v26 = 0;
          atoi(&Dest);
          v32 += 3;
          v33 += 3;
        }
      }
      ++v32;
      ++v33;
    }
    while ( v32 < (signed int)v30 );
  }
  return v28;
}

//----- (00403E61) --------------------------------------------------------
int __fastcall sub_403E61(int this)
{
  int v2; // esi@1

  v2 = (int)((char *)pActors + 836 * this);
  *(_WORD *)(v2 + 160) = rand() % 128 + 128;
  *(_DWORD *)(v2 + 184) = 0;
  *(_WORD *)(v2 + 176) = 0;
  *(_WORD *)(v2 + 152) = 0;
  *(_WORD *)(v2 + 150) = 0;
  *(_WORD *)(v2 + 148) = 0;
  return sub_45976D(v2);
}

//----- (00403F58) --------------------------------------------------------
int __fastcall sub_403F58(int a1, int a2, int a3, signed int a4)
{
  int v4; // esi@1
  int result; // eax@2
  char *v6; // eax@3
  int v7; // ebx@3
  int v8; // edi@3
  void *v9; // esi@4
  char v10[0x1C]; // [sp+4h] [bp-3Ch]@4
  char v11[0x1C]; // [sp+20h] [bp-20h]@4
  int v12; // [sp+3Ch] [bp-4h]@1

  v12 = a2;
  v4 = a1;
  if ( rand() % 2 )
  {
    result = sub_402F87(v4, v12, a4);
  }
  else
  {
    v6 = (char *)a4;
    v8 = 0;
    v7 = &pActors[v4];
    if ( !a4 )
    {
      v9 = sub_4040E9(8 * v4 | 3, v12, v10, 0);
      v6 = v11;
      memcpy(v11, v9, 0x1Cu);
      v8 = 0;
    }
    *(_WORD *)(v7 + 154) = *((_WORD *)v6 + 10);
    *(_WORD *)(v7 + 156) = *((_WORD *)v6 + 12);
    if ( a3 == v8 )
      *(_WORD *)(v7 + 160) = rand() % 256 + 256;
    else
      *(_WORD *)(v7 + 160) = a3;
    *(_DWORD *)(v7 + 184) = v8;
    *(_WORD *)(v7 + 176) = v8;
    *(_WORD *)(v7 + 152) = v8;
    *(_WORD *)(v7 + 150) = v8;
    *(_WORD *)(v7 + 148) = v8;
    result = sub_45976D(v7);
  }
  return result;
}

//----- (00458B4F) --------------------------------------------------------
void *__thiscall sub_458B4F(void *Dst, void *Src)
{
  void *v3; // esi@1
  int v4; // eax@1

  v3 = Dst;
  memcpy(Dst, Src, 4u);
  v4 = class23_AllocatedNamedBuffer(class23_instance, *((_DWORD *)v3 + 1), 36 * *(_DWORD *)v3, "Chest Descrip");
  *((_DWORD *)v3 + 1) = v4;
  return memcpy((void *)v4, (char *)Src + 4, 36 * *(_DWORD *)v3);
}

//----- (00404030) --------------------------------------------------------
int __fastcall sub_404030(int a1, signed int a2, int a3, signed int a4)
{
  signed int v4; // edi@1
  int v5; // esi@1
  int result; // eax@2
  char *v7; // eax@3
  int v8; // ecx@3
  int v9; // ebx@3
  void *v10; // esi@4
  __int16 v11; // ax@5
  char v12; // [sp+8h] [bp-38h]@4
  char v13; // [sp+24h] [bp-1Ch]@4

  v4 = a2;
  v5 = a1;
  if ( rand() % 100 >= 5 )
  {
    v7 = (char *)a4;
    v8 = 0;
    v9 = (int)((char *)pActors + 836 * v5);
    if ( !a4 )
    {
      v10 = sub_4040E9(8 * v5 | 3, v4, &v12, 0);
      v7 = &v13;
      memcpy(&v13, v10, 0x1Cu);
      v8 = 0;
    }
    *(_WORD *)(v9 + 154) = *((_WORD *)v7 + 10);
    v11 = *((_WORD *)v7 + 12);
    *(_DWORD *)(v9 + 184) = v8;
    *(_WORD *)(v9 + 152) = v8;
    *(_WORD *)(v9 + 150) = v8;
    *(_WORD *)(v9 + 148) = v8;
    *(_WORD *)(v9 + 156) = v11;
    *(_WORD *)(v9 + 160) = 256;
    *(_WORD *)(v9 + 176) = 10;
    result = sub_45976D(v9);
  }
  else
  {
    result = sub_402F87(v5, v4, a4);
  }
  return result;
}

//----- (00404544) --------------------------------------------------------
signed int __thiscall sub_404544(int this)
{
  int v1; // ebx@1
  int v2; // esi@2
  int v3; // edi@4
  int *v4; // eax@7
  int v5; // ecx@15
  int v6; // eax@16
  int v7; // ecx@18
  int v8; // edx@19
  int v9; // esi@19
  int v10; // esi@21
  int v11; // ST0C_4@25
  int v12; // ST10_4@25
  int v13; // ST14_4@25
  int v14; // ST18_4@25
  signed int result; // eax@28
  int v16; // edi@32
  signed int v17; // [sp+20h] [bp-Ch]@17
  int v18; // [sp+24h] [bp-8h]@1
  int v19; // [sp+28h] [bp-4h]@1
  signed int v20; // [sp+28h] [bp-4h]@16
  signed int v21; // [sp+28h] [bp-4h]@31

  v19 = 0;
  v1 = this;
  v18 = *(_DWORD *)(this + 12);
  if ( *(_DWORD *)(this + 12) > 0 )
  {
    v2 = this + 32;
    do
    {
      if ( (*(_BYTE *)v2 & 7) == 3 )
      {
        v3 = (int)((char *)pActors + 836 * (*(_DWORD *)v2 >> 3));
        *(_BYTE *)(v3 + 36) |= 0x80u;
        if ( !sub_40894B(v3) )
        {
          --v18;
          *(_DWORD *)(v2 + 4) = 1001;
          *(_BYTE *)(v3 + 36) &= 0x7Fu;
        }
      }
      if ( (*(_BYTE *)v2 & 7) == 4 )
      {
        v4 = &pParty_global->pPlayers[1743 * (*(_DWORD *)v2 >> 3)];
        if ( *((_QWORD *)v4 + 14)
          || *((_QWORD *)v4 + 16)
          || *((_QWORD *)v4 + 15)
          || *((_QWORD *)v4 + 13)
          || *((_QWORD *)v4 + 12)
          || *((_QWORD *)v4 + 2) )
        {
          --v18;
          *(_DWORD *)(v2 + 4) = 1001;
        }
      }
      ++v19;
      v2 += 16;
    }
    while ( v19 < *(_DWORD *)(v1 + 12) );
  }
  v5 = *(_DWORD *)(v1 + 12);
  if ( v5 > 0 )
  {
    v20 = 1;
    v6 = v1 + 32;
    do
    {
      v17 = v20;
      if ( v20 < v5 )
      {
        v7 = v6 + 16;
        do
        {
          v8 = *(_DWORD *)(v7 + 4);
          v9 = *(_DWORD *)(v6 + 4);
          if ( v8 < v9
            || v8 == v9
            && ((v10 = *(_DWORD *)v7 & 7, v10 == 4) && (*(_BYTE *)v6 & 7) == 3
             || v10 == (*(_DWORD *)v6 & 7) && (*(_DWORD *)v7 & 0xFFFFFFF8) < (*(_DWORD *)v6 & 0xFFFFFFF8)) )
          {
            v11 = *(_DWORD *)v6;
            v12 = *(_DWORD *)(v6 + 4);
            v13 = *(_DWORD *)(v6 + 8);
            v14 = *(_DWORD *)(v6 + 12);
            *(_DWORD *)v6 = *(_DWORD *)v7;
            *(_DWORD *)(v6 + 4) = *(_DWORD *)(v7 + 4);
            *(_DWORD *)(v6 + 8) = *(_DWORD *)(v7 + 8);
            *(_DWORD *)(v6 + 12) = *(_DWORD *)(v7 + 12);
            *(_DWORD *)v7 = v11;
            *(_DWORD *)(v7 + 4) = v12;
            *(_DWORD *)(v7 + 8) = v13;
            *(_DWORD *)(v7 + 12) = v14;
          }
          ++v17;
          v7 += 16;
        }
        while ( v17 < *(_DWORD *)(v1 + 12) );
      }
      ++v20;
      v5 = *(_DWORD *)(v1 + 12);
      v6 += 16;
    }
    while ( v20 - 1 < v5 );
  }
  *(_DWORD *)(v1 + 12) = v18;
  result = *(_DWORD *)(v1 + 32);
  if ( (*(_BYTE *)(v1 + 32) & 7) == 4 )
  {
    result = (result >> 3) + 1;
    uMaybeSelectedCharacter = result;
    *(_DWORD *)(v1 + 24) |= 4u;
  }
  else
  {
    uMaybeSelectedCharacter = 0;
    *(_DWORD *)(v1 + 24) &= 0xFFFFFFFBu;
  }
  v21 = 0;
  if ( *(_DWORD *)(v1 + 12) > 0 )
  {
    v16 = v1 + 32;
    do
    {
      if ( (*(_BYTE *)v16 & 7) == 4 )
        word_ACF2B8[3486 * (*(_DWORD *)v16 >> 3)] = (signed __int64)((double)*(signed int *)(v16 + 4)
                                                                   * *(double *)&byte_4D8410[88]);
      ++v21;
      v16 += 16;
      result = v21;
    }
    while ( v21 < *(_DWORD *)(v1 + 12) );
  }
  return result;
}

//----- (0040471C) --------------------------------------------------------
int __thiscall sub_40471C(void *this)
{
  int result; // eax@3

  if ( dword_ACD834 == 1 )
  {
    if ( dword_4F885C == 2 )
      result = sub_406457(this, 0);
  }
  return result;
}

//----- (00404736) --------------------------------------------------------
signed int __fastcall sub_404736(int a1)
{
  int v1; // edx@1
  char *v2; // esi@1
  int v3; // ecx@2
  __int16 v4; // ax@5
  int v6; // ebx@6
  int v7; // ecx@6
  int v8; // eax@6
  __int16 v9; // [sp+Ch] [bp-78h]@1
  __int16 v10; // [sp+Eh] [bp-76h]@6
  int v11; // [sp+10h] [bp-74h]@6
  int v12; // [sp+14h] [bp-70h]@6
  int v13; // [sp+18h] [bp-6Ch]@6
  __int16 v14; // [sp+22h] [bp-62h]@6
  __int16 v15; // [sp+24h] [bp-60h]@6
  __int16 v16; // [sp+26h] [bp-5Eh]@6
  __int16 v17; // [sp+28h] [bp-5Ch]@6
  __int16 v18; // [sp+2Ah] [bp-5Ah]@6
  char v19; // [sp+30h] [bp-54h]@6
  int v20; // [sp+54h] [bp-30h]@6
  int v21; // [sp+58h] [bp-2Ch]@6
  int v22; // [sp+5Ch] [bp-28h]@6
  int v23; // [sp+64h] [bp-20h]@6
  int v24; // [sp+68h] [bp-1Ch]@6
  char v25; // [sp+6Ch] [bp-18h]@6
  char v26; // [sp+6Dh] [bp-17h]@6
  int v27; // [sp+7Ch] [bp-8h]@1
  int v28; // [sp+80h] [bp-4h]@6

  v27 = a1;
  v2 = (char *)pActors + 836 * a1;
  sub_404828(&v9);
  v1 = 0;
  v9 = 600;
  if ( pObjectDescriptionList->uNumObjects <= 0 )
  {
LABEL_5:
    v4 = 0;
  }
  else
  {
    v3 = pObjectDescriptionList->pDescriptions + 32;
    while ( *(_WORD *)v3 != 600 )
    {
      ++v1;
      v3 += 56;
      if ( v1 >= pObjectDescriptionList->uNumObjects )
        goto LABEL_5;
    }
    v4 = v1;
  }
  v10 = v4;
  sub_402F07((int)&v19);
  v12 = *((_WORD *)v2 + 72);
  v20 = 0;
  v6 = *((_WORD *)v2 + 71);
  v28 = *((_WORD *)v2 + 69);
  v21 = 0;
  v22 = 0;
  v11 = v6;
  v7 = *((_WORD *)v2 + 73) - (unsigned int)(signed __int64)((double)v28 * -0.75);
  v14 = 0;
  v13 = v7;
  v15 = 0;
  v16 = 0;
  v17 = sub_49AC17((int)byte_6BE3C8, v6, v12, v7);
  v8 = 8 * v27;
  LOBYTE(v8) = 8 * v27 | 3;
  v18 = 0;
  v23 = v8;
  v24 = 0;
  v25 = 3;
  v26 = 4;
  return sub_42F5ED((int)&v9, 0, 0, 0, 0);
}

//----- (00461492) --------------------------------------------------------
signed int sub_461492(struct class17 *_this, char *Str, int a3, const char *Source)
{
  int v4; // esi@1
  FILE *v6; // eax@5

  v4 = _this;
  if ( *(_DWORD *)((char *)_this + 260) )
    return 1;
  if ( !*(_BYTE *)a3 )
    return 2;
  strcpy(Str, "LOD");
  *((_DWORD *)Str + 41) = 100;
  *((_DWORD *)Str + 43) = 1;
  *(_BYTE *)(a3 + 15) = 0;
  *(_DWORD *)(a3 + 20) = 0;
  *(_DWORD *)(a3 + 16) = 288;
  strcpy((char *)(v4 + 4), Source);
  v6 = fopen((const char *)(v4 + 4), "wb+");
  *(_DWORD *)v4 = v6;
  if ( !v6 )
    return 3;
  locked_fwrite(Str, 0x100u, 1u, v6);
  locked_fwrite((const void *)a3, 0x20u, 1u, *(FILE **)v4);
  fclose(*(FILE **)v4);
  *(_DWORD *)v4 = 0;
  return 0;
}

//----- (00404828) --------------------------------------------------------
void *__thiscall sub_404828(void *this)
{
  void *v2; // esi@1

  v2 = this;
  sub_402F07((int)((char *)this + 36));
  *((_WORD *)v2 + 17) = 1;
  *((_WORD *)v2 + 12) = 0;
  *((_WORD *)v2 + 11) = 0;
  *((_WORD *)v2 + 10) = 0;
  *((_WORD *)v2 + 9) = 0;
  *((_WORD *)v2 + 8) = 0;
  *(_WORD *)v2 = 0;
  *((_WORD *)v2 + 1) = 0;
  *((_BYTE *)v2 + 97) = 0;
  *((_BYTE *)v2 + 96) = 0;
  *((_WORD *)v2 + 16) = 0;
  *((_WORD *)v2 + 15) = 0;
  *((_DWORD *)v2 + 20) = 0;
  *((_DWORD *)v2 + 19) = 0;
  *((_DWORD *)v2 + 18) = 0;
  *((_DWORD *)v2 + 21) = 0;
  return v2;
}

//----- (00404874) --------------------------------------------------------
char __fastcall sub_404874(int a1, int a2, int a3, char a4)
{
  int v4; // eax@1
  int v5; // edi@1
  char *v6; // esi@1
  int v7; // eax@15
  __int16 v8; // ax@18
  signed int v9; // ecx@19
  __int16 v10; // ax@19
  __int16 v11; // ax@19
  int v12; // eax@19
  int v13; // edx@28
  __int16 v15; // [sp+Ch] [bp-74h]@1
  __int16 v16; // [sp+Eh] [bp-72h]@19
  int v17; // [sp+10h] [bp-70h]@19
  int v18; // [sp+14h] [bp-6Ch]@19
  int v19; // [sp+18h] [bp-68h]@19
  __int16 v20; // [sp+22h] [bp-5Eh]@19
  __int16 v21; // [sp+24h] [bp-5Ch]@19
  __int16 v22; // [sp+26h] [bp-5Ah]@19
  __int16 v23; // [sp+28h] [bp-58h]@19
  __int16 v24; // [sp+2Ah] [bp-56h]@19
  char v25; // [sp+30h] [bp-50h]@19
  int v26; // [sp+54h] [bp-2Ch]@19
  int v27; // [sp+58h] [bp-28h]@19
  int v28; // [sp+5Ch] [bp-24h]@19
  int v29; // [sp+64h] [bp-1Ch]@19
  int v30; // [sp+68h] [bp-18h]@19
  char v31; // [sp+6Ch] [bp-14h]@20
  char v32; // [sp+6Dh] [bp-13h]@26
  int v33; // [sp+7Ch] [bp-4h]@1
  int v34; // [sp+88h] [bp+8h]@14
  signed int v35; // [sp+88h] [bp+8h]@19

  v33 = a1;
  v5 = a2;
  v6 = (char *)pActors + 836 * a1;
  sub_404828(&v15);
  v4 = a3 - 1;
  switch ( a3 )
  {
    case 1:
      v15 = 545;
      goto LABEL_14;
    case 2:
      v15 = 550;
      goto LABEL_14;
    case 3:
      v15 = 510;
      goto LABEL_14;
    case 4:
      v15 = 500;
      goto LABEL_14;
    case 5:
      v15 = 515;
      goto LABEL_14;
    case 6:
      v15 = 505;
      goto LABEL_14;
    case 7:
      v15 = 530;
      goto LABEL_14;
    case 8:
      v15 = 525;
      goto LABEL_14;
    case 9:
      v15 = 520;
      goto LABEL_14;
    case 10:
      v15 = 535;
      goto LABEL_14;
    case 11:
      v15 = 540;
      goto LABEL_14;
    case 13:
      v15 = 555;
LABEL_14:
      v34 = 0;
      if ( pObjectDescriptionList->uNumObjects <= 0 )
        goto LABEL_18;
      v7 = pObjectDescriptionList->pDescriptions + 32;
      break;
    default:
      return v4;
  }
  while ( v15 != *(_WORD *)v7 )
  {
    ++v34;
    v7 += 56;
    if ( v34 >= pObjectDescriptionList->uNumObjects )
    {
LABEL_18:
      v8 = 0;
      goto LABEL_19;
    }
  }
  v8 = v34;
LABEL_19:
  v16 = v8;
  sub_402F07((int)&v25);
  v17 = *((_WORD *)v6 + 71);
  v26 = 0;
  v18 = *((_WORD *)v6 + 72);
  v27 = 0;
  v35 = *((_WORD *)v6 + 69);
  v28 = 0;
  v10 = *(_WORD *)(v5 + 20);
  v19 = *((_WORD *)v6 + 73) - (unsigned int)(signed __int64)((double)v35 * -0.75);
  v20 = v10;
  v21 = 0;
  v22 = 0;
  v11 = sub_49AC17((int)byte_6BE3C8, v17, v18, v19);
  v9 = *(_DWORD *)(v5 + 12);
  v23 = v11;
  v12 = 8 * v33;
  LOBYTE(v12) = 8 * v33 | 3;
  v24 = 0;
  v29 = v12;
  v30 = 0;
  if ( (double)v9 >= *(double *)&byte_4D8410[32] )
  {
    if ( v9 >= 1024 )
    {
      v31 = 2;
      if ( v9 >= 2560 )
        v31 = 3;
    }
    else
    {
      v31 = 1;
    }
  }
  else
  {
    v31 = 0;
  }
  v32 = a4;
  LOBYTE(v4) = sub_42F5ED(
                 (int)&v15,
                 *(_DWORD *)(v5 + 20),
                 *(_DWORD *)(v5 + 24),
                 *(_WORD *)(56 * v16 + pObjectDescriptionList->pDescriptions + 48),
                 0);
  if ( v6[90] == 1 )
  {
    LOBYTE(v4) = v6[93];
    if ( (_BYTE)v4 == 2 )
    {
      v19 += 40;
      v13 = *(_DWORD *)(v5 + 20);
LABEL_31:
      LOBYTE(v4) = sub_42F5ED(
                     (int)&v15,
                     v13,
                     *(_DWORD *)(v5 + 24),
                     *(_WORD *)(56 * v16 + pObjectDescriptionList->pDescriptions + 48),
                     0);
      return v4;
    }
    if ( (_BYTE)v4 == 3 )
    {
      sub_42F5ED(
        (int)&v15,
        *(_DWORD *)(v5 + 20) + 30,
        *(_DWORD *)(v5 + 24),
        *(_WORD *)(56 * v16 + pObjectDescriptionList->pDescriptions + 48),
        0);
      v13 = *(_DWORD *)(v5 + 20) - 30;
      goto LABEL_31;
    }
  }
  return v4;
}

//----- (00450218) --------------------------------------------------------
char __cdecl sub_450218()
{
  signed int v0; // eax@1
  struct MapInfo *v2; // esi@1
  int v3; // ebx@2
  int v4; // edx@4
  int v5; // ebp@4
  int v6; // edi@4
  int v7; // esi@4
  int v8; // eax@4
  signed int v9; // esi@4
  int v10; // esi@8
  int v11; // eax@14
  signed __int64 v12; // qtt@14
  int v13; // eax@16
  signed __int64 v14; // qtt@16
  int v15; // eax@17
  signed __int64 v16; // qtt@17
  int v17; // eax@19
  signed __int64 v18; // qtt@19
  int v19; // eax@20
  signed __int64 v20; // qtt@20
  int v21; // eax@21
  signed __int64 v22; // qtt@21
  int v23; // ebp@25
  int v24; // esi@25
  signed int v25; // ebp@27
  int v26; // edi@28
  int v27; // eax@32
  signed int v28; // edx@32
  signed __int64 v29; // qtt@32
  int v30; // esi@34
  int v31; // eax@40
  signed __int64 v32; // qtt@40
  int v33; // eax@42
  signed __int64 v34; // qtt@42
  int v35; // eax@43
  signed __int64 v36; // qtt@43
  int v37; // eax@45
  signed __int64 v38; // qtt@45
  int v39; // eax@46
  signed __int64 v40; // qtt@46
  int v41; // eax@47
  signed __int64 v42; // qtt@47
  char v43; // zf@52
  signed int v48; // [sp+10h] [bp-18h]@1
  int v49; // [sp+14h] [bp-14h]@4
  int *v50; // [sp+18h] [bp-10h]@1
  int v51; // [sp+1Ch] [bp-Ch]@1
  int v52; // [sp+20h] [bp-8h]@26
  //signed int v53; // [sp+24h] [bp-4h]@2
 int i, j;

  v48 = rand() % 100;
  v0 = CMapStats_FindLocation(pMapStats, Str1);
  v2 = v50 = &pMapStats->pMapInfos[v0];
  v51 = (int)array_5E5150;
  i = 0;

  runtime_warning;
  return 0;
  for (i = 0; i < 20; ++i)
  {
    v3 = &array_5E5150[i].dword_000004;
    for (j = 0; j < 140; ++j)
    {
     if ( *(int *)v3 >= 0 )
        goto LABEL_56;

      v5 = rand() % 5 + 1;
      v6 = (unsigned __int8)byte_4E816A[2 * (v2->byte_00002F + 7 * abs(*(int *)v3))];
      v7 = (unsigned __int8)byte_4E816B[2 * (v2->byte_00002F + 7 * abs(*(int *)v3))];
      v8 = rand();
      v9 = v7 - v6 + 1;
      v4 = v6 + v8 % v9;
      v49 = v6 + v8 % v9;
      if ( v4 < 7 )
      {
        if ( v48 < 20 )
        {
          sub_402F07(v3);
          LOBYTE(v0) = v3;
          goto LABEL_25;
        }
        if ( v48 < 60 )
        {
          v10 = 0;
          sub_402F07(v3);
          if ( v49 == 1 )
          {
            v21 = rand();
            v22 = v21;
            v0 = v21 / 51;
            v10 = v22 % 51 + 50;
          }
          else
          {
            if ( v49 != 2 )
            {
              if ( v49 == 3 )
              {
                v17 = rand();
                v18 = v17;
                v0 = v17 / 301;
                v10 = v18 % 301 + 200;
              }
              else
              {
                if ( v49 != 4 )
                {
                  if ( v49 == 5 )
                  {
                    v13 = rand();
                    v14 = v13;
                    v0 = v13 / 1001;
                    v10 = v14 % 1001 + 1000;
LABEL_15:
                    *(_DWORD *)v3 = 199;
                  }
                  else
                  {
                    v0 = v49 - 6;
                    if ( v49 == 6 )
                    {
                      v11 = rand();
                      v12 = v11;
                      v0 = v11 / 3001;
                      v10 = v12 % 3001 + 2000;
                      goto LABEL_15;
                    }
                  }
LABEL_23:
                  *(_DWORD *)(v3 + 20) |= 1u;
                  *(_DWORD *)(v3 + 12) = v10;
LABEL_25:
                  v23 = v5 - 1;
                  v24 = 0;
                  if ( v23 > 0 )
                  {
                    v52 = v23;
                    while ( 1 )
                    {
                      LOBYTE(v0) = -116;
                      v25 = v24;
                      if ( v24 >= 140 )
                        goto LABEL_52;
                      v26 = v51 + 36 * v24 + 4;
                      while ( *(_DWORD *)v26 )
                      {
                        ++v25;
                        v26 += 36;
                        if ( v25 >= 140 )
                          goto LABEL_52;
                      }
                      v27 = rand();
                      v29 = v27;
                      v0 = v27 / 100;
                      v28 = v29 % 100;
                      v48 = v29 % 100;
                      if ( v28 < 20 )
                        goto LABEL_52;
                      if ( v28 >= 60 )
                      {
                        LOBYTE(v0) = sub_456620(pClass40, v49, 0, v26);
                        goto LABEL_51;
                      }
                      v30 = 0;
                      sub_402F07(v26);
                      if ( v49 == 1 )
                      {
                        v41 = rand();
                        v42 = v41;
                        v0 = v41 / 51;
                        v30 = v42 % 51 + 50;
                        goto LABEL_48;
                      }
                      if ( v49 == 2 )
                      {
                        v39 = rand();
                        v40 = v39;
                        v0 = v39 / 101;
                        v30 = v40 % 101 + 100;
LABEL_48:
                        *(_DWORD *)v26 = 197;
                        goto LABEL_49;
                      }
                      if ( v49 == 3 )
                      {
                        v37 = rand();
                        v38 = v37;
                        v0 = v37 / 301;
                        v30 = v38 % 301 + 200;
                        goto LABEL_44;
                      }
                      if ( v49 == 4 )
                      {
                        v35 = rand();
                        v36 = v35;
                        v0 = v35 / 501;
                        v30 = v36 % 501 + 500;
LABEL_44:
                        *(_DWORD *)v26 = 198;
                        goto LABEL_49;
                      }
                      if ( v49 == 5 )
                        break;
                      v0 = v49 - 6;
                      if ( v49 == 6 )
                      {
                        v31 = rand();
                        v32 = v31;
                        v0 = v31 / 3001;
                        v30 = v32 % 3001 + 2000;
LABEL_41:
                        *(_DWORD *)v26 = 199;
                      }
LABEL_49:
                      *(_DWORD *)(v26 + 12) = v30;
LABEL_51:
                      v24 = v25 + 1;
LABEL_52:
                      v43 = v52-- == 1;
                      if ( v43 )
                        goto LABEL_55;
                    }
                    v33 = rand();
                    v34 = v33;
                    v0 = v33 / 1001;
                    v30 = v34 % 1001 + 1000;
                    goto LABEL_41;
                  }
                  goto LABEL_55;
                }
                v15 = rand();
                v16 = v15;
                v0 = v15 / 501;
                v10 = v16 % 501 + 500;
              }
              *(_DWORD *)v3 = 198;
              goto LABEL_23;
            }
            v19 = rand();
            v20 = v19;
            v0 = v19 / 101;
            v10 = v20 % 101 + 100;
          }
          *(_DWORD *)v3 = 197;
          goto LABEL_23;
        }
        LOBYTE(v0) = sub_456620(pClass40, v4, 0, v3);
        goto LABEL_25;
      }
      LOBYTE(v0) = sub_4505CC((void *)v3);
LABEL_55:
      v2 = v50;
LABEL_56:
      v3 += 36;
    }
    v51 += 5324;
  }
  return v0;
}

//----- (004768A9) --------------------------------------------------------
void __cdecl InitializeQuests()
{
  char *result; // eax@4
  int v2; // edi@4
  char v3; // dl@5
  char *v4; // ecx@5
  int v5; // esi@9
  signed int v6; // [sp+10h] [bp-8h]@3
  signed int v7; // [sp+14h] [bp-4h]@4

 if (pQuestsTXT_Raw)
   class23_DeleteBuffer(class23_instance, pQuestsTXT_Raw);

 pQuestsTXT_Raw = class17_fn1(pClass17_Events_LOD, "quests.txt", 0);
 strtok(pQuestsTXT_Raw, "\r");

  //v6 = (signed int)&unk_722F14;
 v6 = 0;
  do
  {
    result = strtok(0, "\r") + 1;
    v2 = 0;
    v7 = 0;
    do
    {
      v3 = *result;
      v4 = 0;
      if ( *result != 9 )
      {
        do
        {
          if ( !v3 )
            break;
          ++v4;
          v3 = *(_BYTE *)((_DWORD)v4 + (_DWORD)result);
        }
        while ( v3 != 9 );
      }
      v5 = (_DWORD)v4 + (_DWORD)result;
      if ( *(_BYTE *)((_DWORD)v4 + (_DWORD)result) == 0 )
        v7 = 1;
      *(_BYTE *)v5 = 0;
      if ( v4 == 0)
      {
        v7 = 1;
      }
      else
      {
        if ( v2 == 1 )
          *(_DWORD *)(unk_722F14 + v6) = sub_452C30(result);
      }
      ++v2;
      result = (char *)(v5 + 1);
    }
    while ( v2 - 1 <= 1 && !v7);
    v6 += 4;
  }
  //while ( v6 < (signed int)&unk_723714 );
  while (v6 < 0x800);
}

//----- (004AC1C9) --------------------------------------------------------
long *sub_4AC1C9(char a1, char a2, char a3, char a4, int a5, int a6, int a7)
{
  signed int v7; // ebx@1
  unsigned __int16 v8; // di@1
  signed int v9; // esi@1
  unsigned __int16 v10; // ax@1
  int v11; // ecx@3
  int v12; // eax@10
  char *v13; // esi@14
  char v16; // [sp+Ch] [bp-34h]@10
  int v17; // [sp+1Ch] [bp-24h]@14
  int v18; // [sp+20h] [bp-20h]@14
  int v19; // [sp+24h] [bp-1Ch]@14
  int v20; // [sp+28h] [bp-18h]@14
  char Dst[16]; // [sp+2Ch] [bp-14h]@1
  int v22; // [sp+3Ch] [bp-4h]@1
  long *pWindowDims;

  v9 = a5;
  v10 = 0;//LOBYTE(v10) = sub_4382BC(a1, a2, a3, a4, a6);
  v8 = v10;
  v22 = 0;//v22 = sub_4383ED(a6);
  v7 = 0;
  memset(Dst, 0, 0x10u);
  if ( (signed __int16)v8 < 0 )
    goto LABEL_19;
  if ( v9 > 0 )
  {
    if ( v9 > 150 )
    {
      v11 = a7;
    }
    else
    {
      v11 = 4000 * v9;
      v7 = 1;
    }
  }
  else
  {
    v11 = 4000 * dword_4F031C[v8];
  }
  if ( v22 & 0x10 && !v7 )
  {
    if ( v9 )
      v12 = sub_4AC4FD((int)&v16);
    else
      v12 = sub_4AC33A((int)&v16);
    goto LABEL_14;
  }
  if ( v8 < 3u )
  {
LABEL_19:
    v13 = Dst;
    goto LABEL_16;
  }
  v12 = sub_4AC277((void *)v11, (int)&v16);
LABEL_14:
  v17 = *(_DWORD *)v12;
  v18 = *(_DWORD *)(v12 + 4);
  v19 = *(_DWORD *)(v12 + 8);
  v20 = *(_DWORD *)(v12 + 12);
  v13 = (char *)&v17;
LABEL_16:

  pWindowDims = (long *)(a7);

  pWindowDims[0] = *(_DWORD *)(v13 + 0);
  pWindowDims[1] = *(_DWORD *)(v13 + 4);
  pWindowDims[2] = *(_DWORD *)(v13 + 8);
  pWindowDims[3] = *(_DWORD *)(v13 + 12);
  return pWindowDims;
}

//----- (0047AF11) --------------------------------------------------------
void __cdecl sub_47AF11()
{
  __int16 *v0; // edi@2
  int v1; // ebx@4
  __int16 v2; // cx@5
  __int16 v3; // ax@10
  int v4; // edx@10
  int v5; // ecx@10
  int v6; // ebx@10
  char *v7; // esi@10
  int v8; // eax@10
  int v9; // eax@10
  int v10; // ecx@10
  char *v11; // eax@14
  int v12; // eax@22
  int v13; // ebx@23
  int v14; // ST3C_4@23
  int v15; // eax@23
  int v16; // ecx@23
  int v17; // eax@25
  int v18; // ecx@25
  int v19; // ST40_4@26
  int v20; // ecx@26
  int v21; // ST44_4@28
  int v22; // ST3C_4@29
  int v23; // ebx@30
  signed __int64 v24; // qtt@30
  int v25; // ST3C_4@30
  int v26; // eax@31
  char v27; // zf@31
  int v28; // [sp+Ch] [bp-34h]@10
  __int16 v29; // [sp+10h] [bp-30h]@10
  int v30; // [sp+14h] [bp-2Ch]@23
  int v31; // [sp+14h] [bp-2Ch]@29
  int v32; // [sp+14h] [bp-2Ch]@30
  int v33; // [sp+18h] [bp-28h]@23
  int v34; // [sp+18h] [bp-28h]@26
  int v35; // [sp+18h] [bp-28h]@30
  int v36; // [sp+1Ch] [bp-24h]@10
  int v37; // [sp+1Ch] [bp-24h]@23
  int v38; // [sp+20h] [bp-20h]@10
  int v39; // [sp+20h] [bp-20h]@23
  int v40; // [sp+24h] [bp-1Ch]@25
  int v42; // [sp+2Ch] [bp-14h]@23
  int v43; // [sp+30h] [bp-10h]@10
  int v44; // [sp+34h] [bp-Ch]@10
  int v45; // [sp+38h] [bp-8h]@10
  signed __int16 v46; // [sp+3Ch] [bp-4h]@12
 int i;

  for (i = 0; i < Count; ++i)
  {
   v0 = &array_665230[i].word_00001C;
      if (array_665230[i].uObjectDescriptionID)
      {
        v1 = &pObjectDescriptionList->pDescriptions[array_665230[i].uObjectDescriptionID];
        if ( !(*(_BYTE *)(v1 + 38) & 1) )
        {
         v2 = *(v0 - 14);
          if ( (v2 < 1000 || v2 >= 10000) && (v2 < 500 || v2 >= 600)
            || class06_sub_4A81CA(pGame->class06_obj, (int)(v0 - 14)) )
          {
            v29 = *v0;
            v44 = *((_DWORD *)v0 - 6);
            v43 = *((_DWORD *)v0 - 5);
            v45 = *((_DWORD *)v0 - 4);
            v7 = &array_512250[dword_5187E0];
            v8 = CSpriteFrameTable_fn1(pSpriteFrameTable, *(_WORD *)(v1 + 40), v0[1]);
            v6 = v8;
            v28 = v8;
            v36 = *(_DWORD *)(v8 + 44);
            v38 = *(_WORD *)(v8 + 48) * v0[3];
            v9 = sub_45281E(pClass59_global, *((_DWORD *)v0 - 6) - pClass55_global->dword_000000, *((_DWORD *)v0 - 5) - pClass55_global->dword_000004);
            LOWORD(v10) = *(v0 - 3);
            v4 = v36;
            v5 = ((pClass59_global->dword_001860 + (pClass59_global->dword_001860 >> 3) + v10 - v9) >> 8) & 7;
            v3 = *(_WORD *)(v6 + 2 * v5 + 24);
            *((_WORD *)v7 + 12) = v3;
            if ( v36 & 0x20 )
            {
              v4 = v36;
              v45 -= (signed int)((unsigned __int64)(*(_DWORD *)(v6 + 40) * *(int *)&pClass17_Sprites_LOD->aLODHeaders[1 + 20 * v3].word_000010) >> 16) >> 1;
            }
            v46 = 0;
            if ( v4 & 2 )
              v46 = 2;
            v11 = (char *)(256 << v5);
            if ( (256 << v5) & v4 )
              v46 |= 4u;
            if ( v4 & 0x40000 )
              v46 |= 0x40u;
            if ( v4 & 0x20000 )
              LOBYTE(v46) = v46 | 0x80;
            if ( v38 )
            {
              LOBYTE(v11) = byte_4E94D3;
              sub_467D88((int)&unk_519AB8, v44, v43, v45, v29, v38, -1, -1, -1, v11);
            }
            v12 = (v44 - pClass55_global->dword_000000) << 16;
            if ( pClass55_global->dword_000014 )
            {
              v14 = (v43 - pClass55_global->dword_000004) << 16;
              v30 = ((unsigned __int64)(v12 * pStruct9_global->dword_000020) >> 16) + ((unsigned __int64)(v14 * pStruct9_global->dword_00001C) >> 16);
              v37 = (unsigned __int64)(v12 * pStruct9_global->dword_00001C) >> 16;
              v39 = (unsigned __int64)(v14 * pStruct9_global->dword_000020) >> 16;
              v33 = (v45 - pClass55_global->dword_000008) << 16;
              v15 = (unsigned __int64)(v30 * pStruct9_global->dword_000028) >> 16;
              v16 = (unsigned __int64)(v33 * pStruct9_global->dword_000024) >> 16;
              v13 = v16 + v15;
              v42 = v16 + v15;
              if ( v16 + v15 >= 262144 && v13 <= pStruct9_global->shading_dist_mist << 16 )
              {
                v18 = v39 - v37;
                v40 = v39 - v37;
                v17 = ((unsigned __int64)(v33 * pStruct9_global->dword_000028) >> 16) - ((unsigned __int64)(v30 * pStruct9_global->dword_000024) >> 16);
                goto LABEL_29;
              }
            }
            else
            {
              v34 = (v43 - pClass55_global->dword_000004) << 16;
              v19 = (unsigned __int64)(v12 * pStruct9_global->dword_000020) >> 16;
              v20 = (unsigned __int64)(v34 * pStruct9_global->dword_00001C) >> 16;
              v13 = v20 + v19;
              v42 = v20 + v19;
              if ( v20 + v19 >= 262144 && v13 <= pStruct9_global->shading_dist_mist << 16 )
              {
                v21 = (unsigned __int64)(((v44 - pClass55_global->dword_000000) << 16) * pStruct9_global->dword_00001C) >> 16;
                v18 = ((unsigned __int64)(v34 * pStruct9_global->dword_000020) >> 16) - v21;
                v40 = ((unsigned __int64)(v34 * pStruct9_global->dword_000020) >> 16) - v21;
                v17 = (v45 - pClass55_global->dword_000008) << 16;
LABEL_29:
                v31 = v17;
                v22 = abs(v18);
                if ( abs(v13) >= v22 )
                {
                  LODWORD(v24) = 0;
                  HIDWORD(v24) = pStruct9_global->dword_000014 << 16 >> 16;
                  v23 = v24 / v42;
                  v25 = v24 / v42;
                  LODWORD(v24) = 0;
                  HIDWORD(v24) = pStruct9_global->dword_000014 << 16 >> 16;
                  v35 = dword_F8BC3C - ((signed int)(((unsigned __int64)(v25 * v40) >> 16) + 32768) >> 16);
                  v32 = dword_F8BC40 - ((signed int)(((unsigned __int64)(v24 / v42 * v31) >> 16) + 32768) >> 16);
                  if ( dword_5187E0 >= 500 )
                    return;
                  ++dword_5187E0;
                  ++dword_5187E4;
                  *((_BYTE *)v0 - 2) |= 1u;
                  *((_WORD *)v7 + 13) = *(_WORD *)(v28 + 52);
                  *((_WORD *)v7 + 14) = v29;
                  *(_DWORD *)v7 = (unsigned __int64)(*(_DWORD *)(v28 + 40) * v23) >> 16;
                  v26 = (unsigned __int64)(*(_DWORD *)(v28 + 40) * v23) >> 16;
                  *((_DWORD *)v7 + 12) = v28;
                  *((_DWORD *)v7 + 1) = v26;
                  *((_WORD *)v7 + 15) = v46;
                  *((_WORD *)v7 + 16) = v44;
                  *((_WORD *)v7 + 17) = v43;
                  *((_WORD *)v7 + 18) = v45;
                  *((_WORD *)v7 + 19) = v35;
                  *((_WORD *)v7 + 20) = v32;
                  HIWORD(v26) = HIWORD(v42);
                  LOWORD(v26) = 0;
                  v27 = (*((_BYTE *)v0 - 2) & 0x20) == 0;
                  *((_DWORD *)v7 + 4) = v26 + (8 * i | 2);
                  *((_WORD *)v7 + 21) = 0;
                  *((_DWORD *)v7 + 11) = 0;
                  if ( !v27 )
                  {
                    if ( !pD3DRenderer->dword_040088 )
                      *((_DWORD *)v7 + 4) = 0;
                  }
                }
                goto LABEL_34;
              }
            }
          }
        }
      }
LABEL_34:
      v0 += 56;
  }
}

//----- (004666D5) --------------------------------------------------------
int __cdecl sub_4666D5()
{
  int result; // eax@6

  if ( dword_6BE360 == 2 )
  {
    if ( !byte_6BE388 )
    {
      dword_6BE0FC = 10;
      dword_6BE100 = 15;
      dword_6BE104 = 20;
      pStruct9_global->shading_dist_mist = 8192;
      dword_6BE0C4 = 0;
      byte_577008 = 0;
    }

    dword_6BE0D4 = 0;
    dword_6BE0DC = 0;

    pStruct9_global->shading_dist_shade = 2048;
    pStruct9_global->shading_dist_shademist = 4096;

    dword_6BE0E0 = 0;
    dword_6BE0E4 = 1024;
    dword_6BE0E8 = 2048;
    dword_6BE0EC = 4096;

    dword_6BE0F0 = 1024;
    dword_6BE0F4 = 2048;
    dword_6BE0F8 = 4096;


    sub_47F4D3(dword_6BE0FC, dword_6BE100, dword_6BE104);
  }
  else
  {
    byte_577008 = 0;
  }
  pParty_global->dword_007778 |= 2;
  dword_576FEC = dword_576FFC;
  dword_576FE8 = dword_576FF8;
  dword_576FF0 = dword_577000;
  dword_576FF4 = dword_577004;
  result = class28_fn0(class28_global, dword_576FF8, dword_576FFC, dword_577000, dword_577004);

  if ( dword_6BE360 == 2 )
    result = sub_485F64(pStruct9_global);
  return result;
}

//----- (00464D32) --------------------------------------------------------
LSTATUS __fastcall RegistryWriteInt(const CHAR *a1, int a2)
{
  LSTATUS result; // eax@1
  const CHAR *v3; // [sp+4h] [bp-1Ch]@1
  BYTE Data[4]; // [sp+8h] [bp-18h]@1
  DWORD dwDisposition; // [sp+Ch] [bp-14h]@2
  HKEY hKey; // [sp+10h] [bp-10h]@1
  HKEY phkResult; // [sp+14h] [bp-Ch]@1
  HKEY v8; // [sp+18h] [bp-8h]@1
  HKEY v9; // [sp+1Ch] [bp-4h]@1

  *(_DWORD *)Data = a2;
  v3 = a1;
  v9 = 0;
  v8 = 0;
  hKey = 0;
  phkResult = 0;
  result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE", 0, 0x2001Fu, &hKey);
  if ( !result )
  {
    if ( !RegCreateKeyExA(hKey, "New World Computing", 0, Class, 0, 983103u, 0, &phkResult, &dwDisposition) )
    {
      if ( !RegCreateKeyExA(phkResult, "Might and Magic VII", 0, Class, 0, 0xF003Fu, 0, &v8, &dwDisposition) )
      {
        if ( !RegCreateKeyExA(v8, "1.0", 0, Class, 0, 0xF003Fu, 0, &v9, &dwDisposition) )
        {
          RegSetValueExA(v9, v3, 0, 4u, Data, 4u);
          RegCloseKey(v9);
        }
        RegCloseKey(v8);
      }
      RegCloseKey(phkResult);
    }
    result = RegCloseKey(hKey);
  }
  return result;
}

//----- (0049289C) --------------------------------------------------------
int sub_49289C(struct Player *_this, int a2, const void *Src)
{
  int v3; // eax@1
  signed int v4; // ebx@1
  int result; // eax@6
  struct class18 *v6; // esi@7
  int v7; // eax@7
  int v8; // edx@9
  void *v9; // esi@10
  int v11; // [sp+4h] [bp-Ch]@7
  int v12; // [sp+8h] [bp-8h]@7
  void *v13; // [sp+Ch] [bp-4h]@1
  int v14; // [sp+18h] [bp+8h]@10
 wchar_t pFilename[256];

  v13 = _this;
  v4 = 0;
  v3 = _this->array_000214;
  while ( *(_DWORD *)v3 )
  {
    ++v4;
    v3 += 36;
    if ( v4 >= 126 )
    {
      v4 = -1;
      break;
    }
  }
  if ( v4 == -1 )
  {
    result = 0;
  }
  else
  {
   wsprintfW(pFilename, L"%S", pClass40->pItems[*(_DWORD *)Src].pIconName);
   v7 = class17_LoadTextureFromCBM(pClass17_Icons_LOD, pFilename);
   v6 = &pClass17_Icons_LOD->aLODHeaders[v7];

   v11 = GetSizeInInventorySlots(v6->uTextureWidth);
   v12 = GetSizeInInventorySlots(v6->uTextureHeight);

    if ( !dword_506128 )
    {
      sub_40F77C(v6);
      sub_40F9C5(pClass17_Icons_LOD);
    }
    v8 = a2;
    if ( v12 > 0 )
    {
      v14 = v12;
      v9 = &_this->array_00157C[v8];
      do
      {
        if ( v11 > 0 )
          memset(v9, -1 - v8, 4 * v11);
        v9 = (char *)v9 + 56;
      }
      while ( v14-- != 1 );
    }
    *((_DWORD *)v13 + v8 + 1375) = v4 + 1;
    memcpy((char *)v13 + 36 * v4 + 532, Src, 0x24u);
    result = v4 + 1;
  }
  return result;
}

//----- (00479089) --------------------------------------------------------
bool __fastcall sub_479089(unsigned int uSomeIdx, int *a2)
{
  int v2; // ecx@1
  int v3; // ebx@1
  int v4; // edi@1
  int v5; // eax@1
  int v6; // ST28_4@1
  int v8; // ebx@3
  int v9; // eax@3
  int v10; // eax@3
  signed int v11; // esi@6
  int v12; // esi@8
  char result; // al@9
  //int v14; // [sp+Ch] [bp-20h]@1
  int v15; // [sp+Ch] [bp-20h]@5
  //int v16; // [sp+10h] [bp-1Ch]@1
  int v17; // [sp+1Ch] [bp-10h]@1
  int v18; // [sp+20h] [bp-Ch]@1
  int v19; // [sp+20h] [bp-Ch]@3
  int v20; // [sp+24h] [bp-8h]@1
  int v21; // [sp+28h] [bp-4h]@1
  int v22; // [sp+28h] [bp-4h]@3

  v20 = (pStruct9_global->dword_000010 << 11) / 360 >> 1;

  v5 = &pClass51_global->pBModels[uSomeIdx];

  v4 = pClass51_global->pBModels[uSomeIdx].dword_0000AC - pClass55_global->dword_000000;
  v3 = pClass51_global->pBModels[uSomeIdx].dword_0000B0 - pClass55_global->dword_000000;

  v6 = class59_sub_402CAE(pClass59_global, pClass55_global->dword_000018);
  v21 = class59_sub_402CAE(pClass59_global, pClass55_global->dword_000018 - pClass59_global->dword_001864);
  v18 = class59_sub_402CAE(pClass59_global, pClass55_global->dword_000014);
  class59_sub_402CAE(pClass59_global, pClass55_global->dword_000014 - pClass59_global->dword_001864);

  v2 = v6;
  v17 = v4 * v6 + v3 * v21;
  if ( pClass55_global->dword_000014 )
    v17 = (unsigned __int64)(v17 * v18) >> 16;
  v19 = v3 * v2 - v4 * v21;
  v8 = abs(v3);
  v9 = abs(v4);
  v10 = sub_4621DA(v9, v8, 0);
  v22 = v10;

  if ( v10 < pClass51_global->pBModels[uSomeIdx].dword_0000B8 + 256 )
    *a2 = 1;
  else *a2 = 0;

  v15 = class59_sub_402CAE(pClass59_global, v20 - pClass59_global->dword_001864);
  if ( v19 >= 0 )
    v11 = ((unsigned __int64)(v15 * v17) >> 16) - ((unsigned __int64)(class59_sub_402CAE(pClass59_global, v20) * v19) >> 16);
  else
    v11 = ((unsigned __int64)(class59_sub_402CAE(pClass59_global, v20) * v19) >> 16) + ((unsigned __int64)(v15 * v17) >> 16);
  v12 = v11 >> 16;
  if ( v22 <= pStruct9_global->shading_dist_mist + 2048 )
  {
   if ( abs(v12) > pClass51_global->pBModels[uSomeIdx].dword_0000B8 + 512 )
      return v12 >= 0;
    else
      return true;
  }
  else return false;
}

//----- (004627B7) --------------------------------------------------------
int __cdecl MenuLoop_Main()
{
  int v4; // eax@8
  int v5; // eax@8
  int v6; // eax@8
  int v7; // eax@8
  struct GUIButton *v8; // eax@27
  int v10; // ecx@36
  int v11; // ecx@37
  int v15; // [sp-14h] [bp-50h]@39
  struct GUIWindow *v17; // [sp+4h] [bp-38h]@11
  //int v18; // [sp+8h] [bp-34h]@11
  //int v19; // [sp+Ch] [bp-30h]@11
  //char v20; // [sp+10h] [bp-2Ch]@11
  //char v21; // [sp+18h] [bp-24h]@11
  POINT ptMouse;
  MSG Msg; // [sp+20h] [bp-1Ch]@15

 dword_4E28F8 = 0;
 if (dword_720010)
   sub_46B105(dword_720010);
 if (pGame->class14_obj->dword_000004)
 {
  if (dword_69B00C)
    Keyboard_resume(dword_69B00C);
 }

 pGUIWindow2 = 0;
 AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
 class03_sub_4698A6(pGame->pClass03);
 ++pClass17_Icons_LOD->dword_011B9C;
 if (!pClass17_Icons_LOD->dword_011B98)
   pClass17_Icons_LOD->dword_011B98 = pClass17_Icons_LOD->uNumLoadedFiles;

 pGUIWindow_MainMenu = GUIWindowCreate(0, 0, 640, 480, 1, 0, 0);

 v4 = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"title_new");
 pMainMenu_NewGame = GUIButtonCreate(pGUIWindow_MainMenu,
                                     494, 172,
                                     pClass17_Icons_LOD->aLODHeaders[v4].uTextureWidth,
                                     pClass17_Icons_LOD->aLODHeaders[v4].uTextureHeight,
                                     1,
                                     0,
                                     54,
                                     0,
                                     78,
                                     "New Game",
                                     v4);

 v5 = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"title_load");
 pMainMenu_LoadGame = GUIButtonCreate(pGUIWindow_MainMenu,
                                      494, 227,
                                      pClass17_Icons_LOD->aLODHeaders[v5].uTextureWidth,
                                      pClass17_Icons_LOD->aLODHeaders[v5].uTextureHeight,
                                      1,
                                      0,
                                      55,
                                      1,
                                      76,
                                      "Load Game",
                                      v5);

 v6 = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"title_cred");
 pMainMenu_Credits = GUIButtonCreate(pGUIWindow_MainMenu,
                                     494, 282,
                                     pClass17_Icons_LOD->aLODHeaders[v6].uTextureWidth,
                                     pClass17_Icons_LOD->aLODHeaders[v6].uTextureHeight,
                                     1,
                                     0,
                                     56,
                                     2,
                                     67,
                                     "Creadits",
                                     v6);

 v7 = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"title_exit");
 pMainMenu_Exit = GUIButtonCreate(pGUIWindow_MainMenu,
                                  494, 337,
                                  pClass17_Icons_LOD->aLODHeaders[v7].uTextureWidth,
                                  pClass17_Icons_LOD->aLODHeaders[v7].uTextureHeight,
                                  1,
                                  0,
                                  57,
                                  3,
                                  0,
                                  "Exit",
                                  v7);

 sub_40E51F(pRGBTexture_Menu);
 RGBTexture_LoadFromCBM(pRGBTexture_Menu, L"Title");

 SetCurrentMenu(MENU_MAIN);
 SetForegroundWindow(hWnd_global);
 SendMessageA(hWnd_global, WM_ACTIVATEAPP, 1, 0);

 while (uCurrentMenuID == MENU_MAIN || uCurrentMenuID == 3)
 {
  class03_GetMousePos(pGame->pClass03, &ptMouse);
  v17 = pGUIWindow_MainMenu;
    if ( uCurrentMenuID == 3 )
    {
      if ( dword_4E28F8 != 12 )
      {
        //sub_40E51F(pRGBTexture_Menu);
        RGBTexture_Load(pRGBTexture_Menu, "lsave640", 0);
        pGUIWindow2 = GUIWindowCreate(0, 0, 640, 480, 1, 0, 0);
        dword_4E28F8 = 12;
        sub_45E361(0);
      }
      v17 = pGUIWindow_PlayerCreation;
    }

    while (PeekMessageA(&Msg, 0, 0, 0, PM_REMOVE))
    {
     if ( Msg.message == WM_QUIT)
       sub_464761(0);
     TranslateMessage(&Msg);
     DispatchMessageA(&Msg);
    }
    if ( BYTE1(dword_6BE364) & 1 )
    {
      WaitMessage();
    }
    else
    {
      CD3DRenderer_BeginScene(pD3DRenderer);
      CD3DRenderer_DrawRGBTexture(pD3DRenderer, 0, 0, pRGBTexture_Menu);
      if (dword_720010)
        sub_46B736(dword_720010, 1);
      sub_435748();
      sub_4156F0();
      if ( dword_720010)
        sub_46B736(dword_720010, 1);
      if ( uCurrentMenuID == 9 )
      {
          sub_4114F2(pClass17_Icons_LOD);
          sub_45E006();
          GUIWindowDelete(pGUIWindow_PlayerCreation);
          pGUIWindow_PlayerCreation = 0;
          dword_4E28F8 = 0;
          dword_57702C = 1;
      }
      else if (uCurrentMenuID == MENU_MAIN)
      {
       if (!dword_507BDC && v17->pControlsHead)
       {
        v8 = v17->pControlsHead;
        while (true)
        {
         if (ptMouse.x >= v8->uX && ptMouse.x <= v8->uZ &&
             ptMouse.y >= v8->uY && ptMouse.y <= v8->uW &&
             v17 == pGUIWindow_MainMenu)
         {
          switch (v8->dword_000024)
          {
               case 0: //New Game
               case 1: //Load Game
               case 2: //Credits
               case 3: //Exit
                 ;
          }

          CD3DRenderer_DrawIndexedTexture(pD3DRenderer, v8->uX + 1, v8->uY + 1, &pClass17_Icons_LOD->aLODHeaders[v8->dword_00003C]);
         }
         v8 = v8->pNext;
         if (!v8)
         {
          if ( uCurrentMenuID == 9 )
          {
           sub_4114F2(pClass17_Icons_LOD);
           sub_45E006();
           GUIWindowDelete(pGUIWindow_PlayerCreation);
           pGUIWindow_PlayerCreation = 0;
           dword_4E28F8 = 0;
           dword_57702C = 1;
          }
          break;
         }
        }
       }
      }
      CD3DRenderer_EndScene(pD3DRenderer);
      CD3DRenderer_Present(pD3DRenderer);
    }
  }
  sub_435748();
  CD3DRenderer_BeginScene(pD3DRenderer);
  sub_4156F0();
  CD3DRenderer_EndScene(pD3DRenderer);
  CD3DRenderer_Present(pD3DRenderer);
  //sub_40E51F(pRGBTexture_Menu);
  if ( pGUIWindow2 )
  {
    GUIWindowDelete(pGUIWindow2);
    pGUIWindow2 = 0;
  }
  GUIWindowDelete(pGUIWindow_MainMenu);
  runtime_warning;//return sub_4114F2(pClass17_Icons_LOD);
  return 0;
}

//----- (00404AC7) --------------------------------------------------------
void __fastcall sub_404AC7(int a1, int a2, signed int a3, int a4, int a5)
{
  signed int v5; // eax@1
  int v6; // edi@1
  int v7; // esi@1
  int v8; // edi@16
  int v9; // edi@17
  signed int v10; // ecx@22
  int v11; // eax@29
  int v12; // edi@30
  int v13; // edi@34
  int v14; // esi@34
  int v15; // ecx@34
  signed int v16; // edx@34
  int v17; // eax@34
  __int16 v18; // di@34
  int v19; // eax@34
  signed int v20; // eax@35
  int v21; // eax@39
  int v22; // eax@39
  signed int v23; // eax@41
  double v24; // st7@49
  float v25; // ST5C_4@50
  int v26; // esi@50
  double v27; // st6@50
  double v28; // st7@50
  float v29; // ST4C_4@51
  int v30; // edi@51
  int v31; // ST3C_4@51
  int v32; // eax@54
  __int16 v33; // ax@57
  signed int v34; // ecx@58
  signed int v35; // eax@67
  signed int v36; // eax@68
  signed __int64 v37; // qtt@69
  char v38; // zf@69
  int v39; // ecx@75
  int v40; // eax@79
  int v41; // ecx@90
  int v42; // ecx@91
  int v43; // eax@95
  int v44; // ecx@100
  int v45; // ecx@101
  int v46; // eax@105
  int v47; // ebx@106
  int v48; // ecx@110
  char v49; // zf@123
  int v50; // eax@127
  int v51; // ecx@130
  int v52; // eax@132
  int v53; // ecx@137
  int v54; // ecx@138
  int v55; // eax@142
  int v56; // esi@143
  int *v57; // esi@145
  int v58; // eax@146
  int v59; // edi@146
  int v60; // eax@146
  int v61; // edi@146
  int v62; // eax@146
  signed int v63; // edi@146
  signed int v64; // edi@147
  int v65; // eax@151
  int v66; // eax@160
  int v67; // edi@167
  int v68; // edi@168
  int v69; // eax@171
  signed int v70; // ecx@172
  int v71; // eax@179
  int v72; // edi@180
  int v73; // edi@184
  int v74; // esi@184
  int v75; // ecx@184
  signed int v76; // edx@184
  int v77; // eax@184
  __int16 v78; // di@184
  int v79; // eax@184
  signed int v80; // eax@185
  int v81; // edx@185
  unsigned __int8 v82; // zf@185
  char v83; // sf@185
  unsigned __int8 v84; // of@185
  int v85; // eax@189
  __int16 v86; // ax@190
  signed int v87; // ecx@192
  int v88; // esi@192
  int v89; // ecx@192
  signed int v90; // edx@192
  int v91; // eax@192
  __int16 v92; // di@192
  __int16 v93; // ax@192
  int v94; // eax@192
  signed int v95; // eax@200
  int v96; // eax@201
  int v97; // ecx@207
  int v98; // ecx@208
  int v99; // eax@212
  int v100; // ecx@217
  int v101; // eax@221
  int v102; // [sp-18h] [bp-E8h]@79
  signed int v103; // [sp-14h] [bp-E4h]@39
  int v104; // [sp-10h] [bp-E0h]@39
  signed int v105; // [sp-Ch] [bp-DCh]@39
  int v106; // [sp-8h] [bp-D8h]@39
  int v107; // [sp-4h] [bp-D4h]@39
  int v108; // [sp+0h] [bp-D0h]@39
  signed int v109[9]; // [sp+4h] [bp-CCh]@23
  int v110; // [sp+4h] [bp-CCh]@39
  signed int v111; // [sp+4h] [bp-CCh]@42
  signed int v112; // [sp+4h] [bp-CCh]@173
  int v113; // [sp+2Ch] [bp-A4h]@51
  float v114; // [sp+30h] [bp-A0h]@50
  int v115; // [sp+38h] [bp-98h]@41
  float v116; // [sp+3Ch] [bp-94h]@49
  int v117; // [sp+40h] [bp-90h]@41
  int v118; // [sp+48h] [bp-88h]@41
  __int16 v119; // [sp+4Ch] [bp-84h]@1
  __int16 v120; // [sp+4Eh] [bp-82h]@34
  int v121; // [sp+50h] [bp-80h]@34
  int v122; // [sp+54h] [bp-7Ch]@34
  int v123; // [sp+58h] [bp-78h]@34
  __int16 v124; // [sp+62h] [bp-6Eh]@34
  __int16 v125; // [sp+64h] [bp-6Ch]@34
  __int16 v126; // [sp+66h] [bp-6Ah]@34
  __int16 v127; // [sp+68h] [bp-68h]@34
  __int16 v128; // [sp+6Ah] [bp-66h]@34
  char v129; // [sp+70h] [bp-60h]@34
  int v130; // [sp+94h] [bp-3Ch]@34
  int v131; // [sp+98h] [bp-38h]@34
  int v132; // [sp+9Ch] [bp-34h]@34
  int v133; // [sp+A4h] [bp-2Ch]@34
  int v134; // [sp+A8h] [bp-28h]@34
  char v135; // [sp+ACh] [bp-24h]@34
  char v136; // [sp+ADh] [bp-23h]@67
  int v137; // [sp+BCh] [bp-14h]@49
  int v138; // [sp+C0h] [bp-10h]@1
  int v139; // [sp+C4h] [bp-Ch]@29
  float v140; // [sp+C8h] [bp-8h]@48
  float v141; // [sp+CCh] [bp-4h]@1
  int v142; // [sp+D8h] [bp+8h]@29
  int v143; // [sp+D8h] [bp+8h]@48
  float v144; // [sp+D8h] [bp+8h]@50
  int v145; // [sp+D8h] [bp+8h]@53
  int v146; // [sp+D8h] [bp+8h]@179
  int v147; // [sp+E0h] [bp+10h]@34
  signed int v148; // [sp+E0h] [bp+10h]@145
  int v149; // [sp+E0h] [bp+10h]@184

  LODWORD(v141) = a1;
  v7 = &pActors[a1];
  v138 = a2;
  sub_404828(&v119);
  v6 = a5 & 0x3F;
  v5 = sub_458244(a5);
  if ( a3 <= 47 )
  {
    if ( a3 != 47 )
    {
      if ( a3 <= 18 )
      {
        if ( a3 == 18 || a3 == 2 )
          goto LABEL_159;
        if ( a3 != 5 )
        {
          if ( a3 == 6 )
            goto LABEL_159;
          if ( a3 != 9 )
          {
            if ( a3 != 11 )
            {
              if ( a3 != 15 )
              {
                if ( a3 != 17 )
                  return;
                if ( v5 <= 0 )
                  goto LABEL_20;
                if ( v5 <= 2 )
                {
                  v9 = 300 * v6;
                }
                else
                {
                  if ( v5 != 3 )
                  {
                    if ( v5 == 4 )
                    {
                      v8 = 3600 * (v6 + 64);
LABEL_21:
                      sub_4584E0(
                        v7 + 452,
                        pParty_global->qword_00002C + (signed __int64)((double)(v8 << 7) * 0.03333333507180214),
                        (unsigned __int64)(pParty_global->qword_00002C
                                         + (signed int)(signed __int64)((double)(v8 << 7) * 0.03333333507180214)) >> 32,
                        v5,
                        0,
                        0,
                        0);
                      return;
                    }
LABEL_20:
                    v8 = 0;
                    goto LABEL_21;
                  }
                  v9 = 900 * v6;
                }
                v8 = v9 + 3840;
                goto LABEL_21;
              }
              v10 = 3;
              if ( BYTE1(a5) & 1 )
              {
                v109[0] = 9;
              }
              else
              {
                if ( (_BYTE)a5 >= 0 )
                {
                  if ( !(a5 & 0x40) )
                    goto LABEL_29;
                  v109[0] = 5;
                }
                else
                {
                  v109[0] = 7;
                }
              }
              v10 = v109[0];
LABEL_29:
              v142 = 60 * pClass59_global->dword_001868 / 360;
              v119 = word_4E3B08;
              v139 = 60 * pClass59_global->dword_001868 / 360 / (v10 - 1);
              v11 = 0;
              if ( pObjectDescriptionList->uNumObjects <= 0 )
              {
LABEL_33:
                LOWORD(v11) = 0;
              }
              else
              {
                v12 = pObjectDescriptionList->pDescriptions + 32;
                while ( word_4E3B08 != *(_WORD *)v12 )
                {
                  ++v11;
                  v12 += 56;
                  if ( v11 >= pObjectDescriptionList->uNumObjects )
                    goto LABEL_33;
                }
              }
              v120 = v11;
              sub_402F07((int)&v129);
              v130 = 15;
              v15 = *(_WORD *)(v7 + 142);
              v16 = *(_WORD *)(v7 + 144);
              v131 = a5;
              v121 = v15;
              v17 = *(_WORD *)(v7 + 146) + ((signed int)*(_WORD *)(v7 + 138) >> 1);
              v14 = v138;
              v18 = *(_WORD *)(v138 + 20);
              v132 = 0;
              v122 = v16;
              v123 = v17;
              v124 = v18;
              v125 = 0;
              v126 = 0;
              v127 = sub_49AC17((int)byte_6BE3C8, v15, v16, v17);
              v19 = 8 * LODWORD(v141);
              LOBYTE(v19) = 8 * LOBYTE(v141) | 3;
              v133 = v19;
              v128 = 0;
              v134 = 0;
              v135 = 3;
              v13 = v142 / -2;
              v147 = v142 / 2;
              if ( v142 / -2 > v142 / 2 )
              {
                v20 = v147;
              }
              else
              {
                do
                {
                  v124 = v13 + *(_WORD *)(v14 + 20);
                  v20 = sub_42F5ED(
                          (int)&v119,
                          v124,
                          *(_DWORD *)(v14 + 24),
                          *(_WORD *)(56 * v120 + pObjectDescriptionList->pDescriptions + 48),
                          0);
                  v13 += v139;
                }
                while ( v13 <= v147 );
              }
              if ( v20 != -1 )
              {
                v110 = 0;
                v108 = 0;
                v107 = 0;
                v106 = 0;
                v22 = 8 * v20;
                v105 = -1;
                LOBYTE(v22) = v22 | 2;
                v104 = 0;
                v103 = v22;
                v21 = word_4EE0A6;
LABEL_202:
                v102 = v21;
                goto LABEL_222;
              }
              return;
            }
LABEL_159:
            v119 = word_4E3ACC[2 * a3];
            LODWORD(v140) = 0;
            if ( pObjectDescriptionList->uNumObjects <= 0 )
            {
LABEL_191:
              v86 = 0;
            }
            else
            {
              v66 = pObjectDescriptionList->pDescriptions + 32;
              while ( v119 != *(_WORD *)v66 )
              {
                ++LODWORD(v140);
                v66 += 56;
                if ( LODWORD(v140) >= pObjectDescriptionList->uNumObjects )
                  goto LABEL_191;
              }
              v86 = LOWORD(v140);
            }
            v120 = v86;
            sub_402F07((int)&v129);
            v130 = a3;
            v89 = *(_WORD *)(v7 + 142);
            v90 = *(_WORD *)(v7 + 144);
            v131 = a5;
            v121 = v89;
            v91 = *(_WORD *)(v7 + 146) + ((signed int)*(_WORD *)(v7 + 138) >> 1);
            v88 = v138;
            v92 = *(_WORD *)(v138 + 20);
            v132 = 0;
            v122 = v90;
            v123 = v91;
            v124 = v92;
            v125 = 0;
            v126 = 0;
            v93 = sub_49AC17((int)byte_6BE3C8, v89, v90, v91);
            v87 = *(_DWORD *)(v88 + 12);
            v127 = v93;
            LODWORD(v140) = v87;
            v94 = 8 * LODWORD(v141);
            LOBYTE(v94) = 8 * LOBYTE(v141) | 3;
            v128 = 0;
            v133 = v94;
            v134 = 0;
            v135 = 3;
            if ( (double)v87 >= *(double *)&byte_4D8410[32] )
            {
              if ( v87 >= 1024 )
              {
                if ( v87 >= 2560 )
                {
                  if ( v87 < 5120 )
                    v135 = 3;
                }
                else
                {
                  v135 = 2;
                }
              }
              else
              {
                v135 = 1;
              }
            }
            else
            {
              v135 = 0;
            }
            v136 = 2;
            v95 = sub_42F5ED(
                    (int)&v119,
                    *(_DWORD *)(v88 + 20),
                    *(_DWORD *)(v88 + 24),
                    *(_WORD *)(56 * v120 + pObjectDescriptionList->pDescriptions + 48),
                    0);
            if ( v95 != -1 )
            {
              v110 = 0;
              v108 = 0;
              v107 = 0;
              v106 = 0;
              v96 = 8 * v95;
              v105 = -1;
              LOBYTE(v96) = v96 | 2;
              v104 = 0;
              v103 = v96;
              v21 = word_4EE088[a3];
              goto LABEL_202;
            }
            return;
          }
          if ( dword_6BE360 == 1 )
            return;
          v139 = pParty_global->dword_0006BC;
          v115 = pParty_global->dword_0006B4;
          v118 = pParty_global->dword_0006BC + 2500;
          v117 = pParty_global->dword_0006B8;
          v23 = 8;
          if ( BYTE1(a5) & 1 )
          {
            v111 = 14;
          }
          else
          {
            if ( (_BYTE)a5 >= 0 )
            {
              if ( !(a5 & 0x40) )
                goto LABEL_48;
              v111 = 10;
            }
            else
            {
              v111 = 12;
            }
          }
          v23 = v111;
LABEL_48:
          LODWORD(v140) = 0;
          v143 = 0;
          if ( v23 > 0 )
          {
            v24 = (double)v139;
            v139 = v23;
            v116 = v24;
            v137 = 8 * LODWORD(v141) | 3;
            do
            {
              v28 = (double)v143;
              v114 = v28;
              v27 = (double)SLODWORD(v140);
              v26 = rand() % 1000;
              v25 = (double)v118;
              v144 = (double)v26 + v116 - v25;
              v141 = v27 * v27;
              v140 = v28 * v28;
              if ( sqrt(v144 * v144 + v140 + v141) <= *(double *)&byte_4D8410[24] )
              {
                v30 = 0;
                v113 = 0;
              }
              else
              {
                v31 = (signed __int64)sqrt(v140 + v141);
                v29 = v27;
                v30 = sub_45281E(pClass59_global, (signed __int64)v114, (signed __int64)v29);
                v113 = sub_45281E(pClass59_global, v31, (signed __int64)v144);
              }
              sub_402F07((int)&v129);
              v119 = word_4E3AF0;
              v145 = 0;
              if ( pObjectDescriptionList->uNumObjects <= 0 )
              {
LABEL_57:
                v33 = 0;
              }
              else
              {
                v32 = pObjectDescriptionList->pDescriptions + 32;
                while ( v119 != *(_WORD *)v32 )
                {
                  ++v145;
                  v32 += 56;
                  if ( v145 >= pObjectDescriptionList->uNumObjects )
                    goto LABEL_57;
                }
                v33 = v145;
              }
              v120 = v33;
              v131 = a5;
              v121 = v115;
              v122 = v117;
              v123 = v26 + v118;
              v130 = 9;
              v132 = 0;
              v126 = 0;
              v127 = 0;
              v128 = 0;
              v133 = v137;
              v134 = 0;
              v135 = sub_427546(v26 + 2500);
              v124 = v30;
              v125 = 0;
              v34 = *(_DWORD *)(v138 + 12);
              LODWORD(v140) = *(_DWORD *)(v138 + 12);
              if ( (double)SLODWORD(v140) >= *(double *)&byte_4D8410[32] )
              {
                if ( v34 >= 1024 )
                {
                  if ( v34 >= 2560 )
                  {
                    if ( v34 < 5120 )
                      v135 = 3;
                  }
                  else
                  {
                    v135 = 2;
                  }
                }
                else
                {
                  v135 = 1;
                }
              }
              else
              {
                v135 = 0;
              }
              v136 = 2;
              v35 = sub_42F5ED((int)&v119, v30, v113, *(_WORD *)(56 * v120 + pObjectDescriptionList->pDescriptions + 48), 0);
              if ( v35 != -1 )
              {
                v36 = 8 * v35;
                LOBYTE(v36) = v36 | 2;
                AudioPlayer_sub_4AA306(pAudioPlayer, word_4EE09A, v36, 0, -1, 0, 0, 0, 0);
              }
              v143 = rand() % 1024 - 512;
              v37 = rand();
              v38 = v139-- == 1;
              LODWORD(v140) = v37 % 1024 - 512;
            }
            while ( !v38 );
          }
          return;
        }
        if ( v5 > 0 )
        {
          if ( v5 <= 2 )
          {
            v39 = 60 * (v6 + 60);
            goto LABEL_79;
          }
          if ( v5 == 3 )
          {
            v39 = 180 * (v6 + 20);
            goto LABEL_79;
          }
          if ( v5 == 4 )
          {
            v39 = 240 * (v6 + 15);
LABEL_79:
            sub_4584E0(
              v7 + 516,
              pParty_global->qword_00002C + (signed __int64)((double)(v39 << 7) * 0.03333333507180214),
              (unsigned __int64)(pParty_global->qword_00002C + (signed int)(signed __int64)((double)(v39 << 7) * 0.03333333507180214)) >> 32,
              v5,
              0,
              0,
              0);
            sub_4A7E89(v7, 16727070);
            v110 = 0;
            v108 = 0;
            v107 = 0;
            v106 = 0;
            v40 = 8 * LODWORD(v141);
            v105 = -1;
            LOBYTE(v40) = 8 * LOBYTE(v141) | 3;
            v104 = 0;
            v103 = v40;
            v102 = 10040;
LABEL_222:
            AudioPlayer_sub_4AA306(pAudioPlayer, v102, v103, v104, v105, v106, v107, v108, v110);
            return;
          }
        }
        v39 = 0;
        goto LABEL_79;
      }
      if ( a3 == 26 || a3 == 29 )
        goto LABEL_159;
      if ( a3 != 38 )
      {
        if ( a3 == 39 || a3 == 41 )
          goto LABEL_159;
        if ( a3 != 46 )
          return;
        if ( v5 > 0 )
        {
          if ( v5 <= 2 )
          {
            v41 = 300 * v6;
            goto LABEL_91;
          }
          if ( v5 == 3 )
          {
            v41 = 900 * v6;
            goto LABEL_91;
          }
          if ( v5 == 4 )
          {
            v41 = 1200 * v6;
LABEL_91:
            v42 = v41 + 3840;
LABEL_95:
            sub_4584E0(
              v7 + 484,
              pParty_global->qword_00002C + (signed __int64)((double)(v42 << 7) * 0.03333333507180214),
              (unsigned __int64)(pParty_global->qword_00002C + (signed int)(signed __int64)((double)(v42 << 7) * 0.03333333507180214)) >> 32,
              v5,
              v6 + 5,
              0,
              0);
            sub_4A7E89(v7, pClass58_global->unk_1A6C5D);
            v110 = 0;
            v108 = 0;
            v107 = 0;
            v106 = 0;
            v43 = 8 * LODWORD(v141);
            v105 = -1;
            LOBYTE(v43) = 8 * LOBYTE(v141) | 3;
            v104 = 0;
            v103 = v43;
            v102 = 14010;
            goto LABEL_222;
          }
        }
        v42 = 0;
        goto LABEL_95;
      }
      if ( v5 <= 0 )
        goto LABEL_104;
      if ( v5 <= 2 )
      {
        v45 = 300 * v6;
      }
      else
      {
        if ( v5 != 3 )
        {
          if ( v5 == 4 )
          {
            v44 = 3600 * (v6 + 64);
LABEL_105:
            sub_4584E0(
              v7 + 468,
              pParty_global->qword_00002C + (signed __int64)((double)(v44 << 7) * 0.03333333507180214),
              (unsigned __int64)(pParty_global->qword_00002C + (signed int)(signed __int64)((double)(v44 << 7) * 0.03333333507180214)) >> 32,
              v5,
              v6 + 5,
              0,
              0);
            sub_4A7E89(v7, (int)&unk_5C310E);
            v110 = 0;
            v108 = 0;
            v107 = 0;
            v106 = 0;
            v46 = 8 * LODWORD(v141);
            v105 = -1;
            LOBYTE(v46) = 8 * LOBYTE(v141) | 3;
            v104 = 0;
            v103 = v46;
            v102 = 13040;
            goto LABEL_222;
          }
LABEL_104:
          v44 = 0;
          goto LABEL_105;
        }
        v45 = 900 * v6;
      }
      v44 = v45 + 3840;
      goto LABEL_105;
    }
    v47 = 0;
    if ( v5 > 0 )
    {
      if ( v5 <= 2 )
      {
        v48 = 2 * v6 + 40;
        goto LABEL_114;
      }
      if ( v5 == 3 )
      {
        v48 = 3 * v6 + 60;
        goto LABEL_114;
      }
      if ( v5 == 4 )
      {
        LOWORD(v48) = 2 * (3 * v6 + 60);
LABEL_114:
        sub_4584E0(v7 + 388, pParty_global->qword_00002C + 1280, (unsigned __int64)(pParty_global->qword_00002C + 1280) >> 32, v5, v48, 0, 0);
        sub_4A7E89(v7, pClass58_global->unk_1A6C5D);
LABEL_127:
        v110 = v47;
        v108 = v47;
        v107 = v47;
        v50 = 8 * LODWORD(v141);
        v106 = v47;
        v105 = -1;
        LOBYTE(v50) = 8 * LOBYTE(v141) | 3;
        v104 = v47;
        v103 = v50;
        v102 = 14020;
        goto LABEL_222;
      }
    }
    LOWORD(v48) = 0;
    goto LABEL_114;
  }
  if ( a3 <= 80 )
  {
    if ( a3 == 80 )
    {
      v56 = (int)pParty_global->array_00088C;
      do
      {
        sub_458585(v56);
        v56 += 16;
      }
      while ( v56 < (signed int)&pParty_global->pPlayers[0] );
      v148 = 1;
      v57 = pPlayers;
      do
      {
        v58 = sub_48CA3F(*v57);
        v59 = sub_48EA1B(v58);
        v60 = sub_48C9C2(*v57);
        v61 = (sub_48EA1B(v60) + v59) >> 1;
        v62 = sub_48CC33((void *)*v57);
        v63 = v61 + sub_48EA1B(v62) + 30;
        if ( rand() % v63 < 30 )
        {
          v64 = 6048;
          do
          {
            sub_458585(v64 + *v57);
            v64 += 16;
          }
          while ( v64 < 6432 );
          sub_4418B1(11210, v148 + 99, 0, 65536);
        }
        ++v148;
        ++v57;
      }
      while ( (signed int)v57 <= (signed int)&dword_A750D4 );
      v110 = 0;
      v108 = 0;
      v107 = 0;
      v65 = 8 * LODWORD(v141);
      v106 = 0;
      v105 = -1;
      LOBYTE(v65) = 8 * LOBYTE(v141) | 3;
      v104 = 0;
      v103 = v65;
      v21 = word_4EE128;
      goto LABEL_202;
    }
    if ( a3 != 51 )
    {
      if ( a3 == 57 || a3 == 65 || a3 == 70 )
        goto LABEL_159;
      if ( a3 == 73 )
      {
        if ( v5 <= 0 || v5 > 4 )
          v51 = 0;
        else
          v51 = 3600 * v6;
        sub_4584E0(
          v7 + 548,
          pParty_global->qword_00002C + (signed __int64)((double)(v51 << 7) * 0.03333333507180214),
          (unsigned __int64)(pParty_global->qword_00002C + (signed int)(signed __int64)((double)(v51 << 7) * 0.03333333507180214)) >> 32,
          v5,
          v6,
          0,
          0);
        sub_4A7E89(v7, (int)&unk_A81376);
        v110 = 0;
        v108 = 0;
        v107 = 0;
        v106 = 0;
        v52 = 8 * LODWORD(v141);
        v105 = -1;
        LOBYTE(v52) = 8 * LOBYTE(v141) | 3;
        v104 = 0;
        v103 = v52;
        v102 = 16060;
        goto LABEL_222;
      }
      if ( a3 == 77 )
      {
        *(_WORD *)(v7 + 40) += 5 * v6 + 10;
        if ( (signed int)*(_WORD *)(v7 + 40) >= *(_DWORD *)(v7 + 108) )
          *(_WORD *)(v7 + 40) = *(_WORD *)(v7 + 108);
        sub_4A7E89(v7, (int)&unk_A81376);
        v47 = 0;
        goto LABEL_127;
      }
      v49 = a3 == 78;
LABEL_158:
      if ( !v49 )
        return;
      goto LABEL_159;
    }
    if ( v5 > 0 )
    {
      if ( v5 <= 2 )
      {
        v53 = 300 * v6;
        goto LABEL_138;
      }
      if ( v5 == 3 )
      {
        v53 = 900 * v6;
        goto LABEL_138;
      }
      if ( v5 == 4 )
      {
        v53 = 1200 * v6;
LABEL_138:
        v54 = v53 + 3840;
LABEL_142:
        sub_4584E0(
          v7 + 500,
          pParty_global->qword_00002C + (signed __int64)((double)(v54 << 7) * 0.03333333507180214),
          (unsigned __int64)(pParty_global->qword_00002C + (signed int)(signed __int64)((double)(v54 << 7) * 0.03333333507180214)) >> 32,
          v5,
          v6 + 5,
          0,
          0);
        sub_4A7E89(v7, pClass58_global->unk_1A6C5D);
        v110 = 0;
        v108 = 0;
        v107 = 0;
        v106 = 0;
        v55 = 8 * LODWORD(v141);
        v105 = -1;
        LOBYTE(v55) = 8 * LOBYTE(v141) | 3;
        v104 = 0;
        v103 = v55;
        v102 = 14060;
        goto LABEL_222;
      }
    }
    v54 = 0;
    goto LABEL_142;
  }
  if ( a3 == 85 )
  {
    if ( v5 > 0 )
    {
      if ( v5 <= 2 )
      {
        v100 = 300 * v6 + 3840;
        goto LABEL_221;
      }
      if ( v5 == 3 )
      {
        LOWORD(v6) = 3 * v6;
        v100 = 900 * (a5 & 0x3F) + 3840;
        goto LABEL_221;
      }
      if ( v5 == 4 )
      {
        v100 = 1200 * v6 + 3840;
        LOWORD(v6) = 4 * v6;
LABEL_221:
        sub_4584E0(
          v7 + 420,
          pParty_global->qword_00002C + (signed __int64)((double)(v100 << 7) * 0.03333333507180214),
          (unsigned __int64)(pParty_global->qword_00002C + (signed int)(signed __int64)((double)(v100 << 7) * 0.03333333507180214)) >> 32,
          v5,
          v6,
          0,
          0);
        sub_4A7E89(v7, 16777215);
        v110 = 0;
        v108 = 0;
        v107 = 0;
        v106 = 0;
        v101 = 8 * LODWORD(v141);
        v105 = -1;
        LOBYTE(v101) = 8 * LOBYTE(v141) | 3;
        v104 = 0;
        v103 = v101;
        v102 = 17070;
        goto LABEL_222;
      }
    }
    LOWORD(v6) = a5;
    v100 = 0;
    goto LABEL_221;
  }
  if ( a3 == 86 )
  {
    if ( v5 > 0 )
    {
      if ( v5 <= 2 )
      {
        v97 = 300 * v6;
        goto LABEL_208;
      }
      if ( v5 == 3 )
      {
        v97 = 900 * v6;
        goto LABEL_208;
      }
      if ( v5 == 4 )
      {
        v97 = 1200 * v6;
LABEL_208:
        v98 = v97 + 3840;
LABEL_212:
        sub_4584E0(
          v7 + 436,
          pParty_global->qword_00002C + (signed __int64)((double)(v98 << 7) * 0.03333333507180214),
          (unsigned __int64)(pParty_global->qword_00002C + (signed int)(signed __int64)((double)(v98 << 7) * 0.03333333507180214)) >> 32,
          v5,
          v6 + 5,
          0,
          0);
        sub_4A7E89(v7, 16777215);
        v110 = 0;
        v108 = 0;
        v107 = 0;
        v106 = 0;
        v99 = 8 * LODWORD(v141);
        v105 = -1;
        LOBYTE(v99) = 8 * LOBYTE(v141) | 3;
        v104 = 0;
        v103 = v99;
        v102 = 17080;
        goto LABEL_222;
      }
    }
    v98 = 0;
    goto LABEL_212;
  }
  if ( a3 == 90 )
    goto LABEL_159;
  if ( a3 != 93 )
  {
    if ( a3 != 95 )
    {
      v49 = a3 == 97;
      goto LABEL_158;
    }
    if ( v5 > 0 )
    {
      if ( v5 <= 3 )
      {
        v67 = 300 * v6;
        goto LABEL_168;
      }
      if ( v5 == 4 )
      {
        v67 = 900 * v6;
LABEL_168:
        v68 = v67 + 3840;
LABEL_171:
        sub_4584E0(
          v7 + 532,
          pParty_global->qword_00002C + (signed __int64)((double)(v68 << 7) * 0.03333333507180214),
          (unsigned __int64)(pParty_global->qword_00002C + (signed int)(signed __int64)((double)(v68 << 7) * 0.03333333507180214)) >> 32,
          v5,
          0,
          0,
          0);
        sub_4A7E89(v7, 0x7E7E7E);
        v110 = 0;
        v108 = 0;
        v107 = 0;
        v106 = 0;
        v69 = 8 * LODWORD(v141);
        v105 = -1;
        LOBYTE(v69) = 8 * LOBYTE(v141) | 3;
        v104 = 0;
        v103 = v69;
        v102 = 18060;
        goto LABEL_222;
      }
    }
    v68 = 0;
    goto LABEL_171;
  }
  v70 = 3;
  if ( BYTE1(a5) & 1 )
  {
    v112 = 9;
  }
  else
  {
    if ( (_BYTE)a5 >= 0 )
    {
      if ( !(a5 & 0x40) )
        goto LABEL_179;
      v112 = 5;
    }
    else
    {
      v112 = 7;
    }
  }
  v70 = v112;
LABEL_179:
  v146 = 60 * pClass59_global->dword_001868 / 360;
  v119 = word_4E3C40;
  v137 = 60 * pClass59_global->dword_001868 / 360 / (v70 - 1);
  v71 = 0;
  if ( pObjectDescriptionList->uNumObjects <= 0 )
  {
LABEL_183:
    LOWORD(v71) = 0;
  }
  else
  {
    v72 = pObjectDescriptionList->pDescriptions + 32;
    while ( word_4E3C40 != *(_WORD *)v72 )
    {
      ++v71;
      v72 += 56;
      if ( v71 >= pObjectDescriptionList->uNumObjects )
        goto LABEL_183;
    }
  }
  v120 = v71;
  sub_402F07((int)&v129);
  v130 = 93;
  v75 = *(_WORD *)(v7 + 142);
  v76 = *(_WORD *)(v7 + 144);
  v131 = a5;
  v121 = v75;
  v77 = *(_WORD *)(v7 + 146) + ((signed int)*(_WORD *)(v7 + 138) >> 1);
  v74 = v138;
  v78 = *(_WORD *)(v138 + 20);
  v132 = 0;
  v122 = v76;
  v123 = v77;
  v124 = v78;
  v125 = 0;
  v126 = 0;
  v127 = sub_49AC17((int)byte_6BE3C8, v75, v76, v77);
  v79 = 8 * LODWORD(v141);
  LOBYTE(v79) = 8 * LOBYTE(v141) | 3;
  v133 = v79;
  v128 = 0;
  v134 = 0;
  v135 = 3;
  v149 = v146 / -2;
  v73 = v146 / 2;
  if ( v146 / -2 > v146 / 2 )
  {
    v80 = v149;
  }
  else
  {
    do
    {
      v81 = *(_DWORD *)(v74 + 20);
      v124 = v149 + *(_WORD *)(v74 + 20);
      v80 = sub_42F5ED((int)&v119, v81, *(_DWORD *)(v74 + 24), *(_WORD *)(56 * v120 + pObjectDescriptionList->pDescriptions + 48), 0);
      compile_error;//v84 = __SETO__(v137 + v149, v73);
      v82 = v137 + v149 == v73;
      v83 = v137 + v149 - v73 < 0;
      v149 += v137;
    }
    while ( (unsigned __int8)(v83 ^ v84) | v82 );
  }
  if ( v80 != -1 )
  {
    v110 = 0;
    v108 = 0;
    v107 = 0;
    v106 = 0;
    v85 = 8 * v80;
    v105 = -1;
    LOBYTE(v85) = v85 | 2;
    v104 = 0;
    v103 = v85;
    v21 = word_4EE142;
    goto LABEL_202;
  }
}

//----- (0044D406) --------------------------------------------------------
char *__fastcall sub_44D406(int *a1, unsigned char *pFontData, int a3, int a4, unsigned __int16 a5, const char *pString, int a7)
{
  char *result; // eax@1
  int v8; // ebx@1
  int v9; // edi@1
  int v10; // esi@1
  char *v12; // eax@1
  int v13; // eax@2

  v8 = a1[2] - a3;
  dword_5C6DB4 = a5;
  v12 = FitTextInAWindow(pString, pFontData, a1, a3, 0);
  result = strtok(v12, "\n");
  v9 = a3 + a1[0];
  v10 = a4 + a1[1];
  while ( result )
  {
    v13 = (v8 - sub_44C51E(pFontData, result)) >> 1;
    if ( v13 < 0 )
      v13 = 0;
    sub_44D1E7(pFontData, a5, v9 + v13, v10, result, 640);
    v10 += pFontData[5] - a7;
    result = strtok(0, "\n");
  }
  return result;
}

//----- (00464479) --------------------------------------------------------
void __cdecl sub_464479()
{
  int v0; // esi@9

  if (pGame->pClass03)
    sub_469903(pGame->pClass03, "MICON1");
  sub_48A336(&class35_obj);
  sub_46454B(pClass17_Bitmaps_LOD);
  sub_4645DC(pClass17_Sprites_LOD);
  sub_46454B(pClass17_Icons_LOD);
  if ( pD3DRenderer->dword_040088 )
  {
    dword_EF52A0 = 0;
    dword_EF52A4 = 0;
  }
  sub_46080D();
  if ( dword_6BE360 == 1 )
  {
    sub_498B15((int)byte_6BE3C8);
  }
  else
  {
    if ( dword_6BE360 == 2 )
      sub_48901B((char *)pClass51_global);
  }
  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  sub_4A9D79(pSoundList, 0);
  dword_6BE360 = 0;
  CSpriteFrameTable_fn3(pSpriteFrameTable);
  v0 = uNumGUIWindows;
  dword_AE30F4 = uNumGUIWindows;
  while ( v0 > 0 )
    GUIWindowDelete(&array_506F50[array_5075E0[v0--] - 1]);
}

//----- (004059DB) --------------------------------------------------------
signed int __thiscall sub_4059DB(void *this)
{
  int v1; // ebx@1
  int v2; // edi@1
  int v3; // esi@1
  int v4; // eax@5
  char *v5; // edi@7
  int v6; // esi@7
  int v7; // eax@9
  signed int v8; // edx@10
  unsigned __int8 v9; // zf@14
  char v10; // sf@14
  unsigned __int8 v11; // of@14
  int v12; // esi@15
  int v13; // ecx@16
  unsigned __int16 v14; // ax@17
  int v15; // ecx@18
  signed __int64 v16; // qax@19
  int v17; // edx@22
  int v18; // esi@27
  char *v19; // esi@32
  int *v20; // eax@33
  int v21; // edx@33
  int v22; // ecx@33
  int v23; // eax@34
  char *v24; // eax@34
  char *v25; // ecx@34
  int v26; // edx@34
  int v27; // eax@38
  int v28; // ecx@38
  unsigned __int8 v29; // sf@38
  unsigned __int8 v30; // of@38
  char v32; // [sp+Ch] [bp-68h]@10
  char v33; // [sp+28h] [bp-4Ch]@10
  int v34[4]; // [sp+34h] [bp-40h]@28
  char v35; // [sp+44h] [bp-30h]@10
  int v36[4]; // [sp+50h] [bp-24h]@18
  int v37; // [sp+60h] [bp-14h]@10
  int v38; // [sp+64h] [bp-10h]@6
  int v39; // [sp+68h] [bp-Ch]@5
  int v40; // [sp+6Ch] [bp-8h]@1
  int v41; // [sp+70h] [bp-4h]@7

  dword_4F8870 &= 0xFFFFFFFDu;
  v1 = (int)this;
  sub_426386(pClass24_global);
  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  v2 = 0;
  AudioPlayer_sub_4AA306(pAudioPlayer, 207, 0, 0, -1, 0, 0, 0, 0);
  v40 = (int)&pParty_global->pPlayers[0];
  dword_50C998 = 8 * pIconFrameTable->pIcons[dword_50C990].word_00001A;
  dword_50C994 = 0;
  *(_DWORD *)(v1 + 16) = 100;
  *(_DWORD *)v1 = 0;
  *(_DWORD *)(v1 + 8) = 64;
  *(_DWORD *)(v1 + 4) = 1;
  *(_DWORD *)(v1 + 12) = 0;
  v3 = 0;
  do
  {
    if ( sub_492C0B(v40) )
    {
      *(_DWORD *)(16 * (*(_DWORD *)(v1 + 12) + 2) + v1) = 8 * v3 | 4;
      *(_DWORD *)(16 * *(_DWORD *)(v1 + 12) + v1 + 44) = 2;
      *(_DWORD *)(16 * *(_DWORD *)(v1 + 12) + v1 + 40) = 0;
      compile_error;//dword_AE30FC[*(_DWORD *)(v1 + 12)++] = 0;
    }
    v40 += 6972;
    ++v3;
  }
  while ( v40 < (signed int)&dword_AD4674 );
  v39 = *(_DWORD *)(v1 + 12);
  v4 = v39;
  v40 = v4;
  if ( v4 < v4 + dword_4F75D8 )
  {
    v38 = (int)dword_4F7DB0;
    do
    {
      v41 = *(_DWORD *)v38;
      v6 = v41;
      v5 = (char *)pActors + 836 * v41;
      if ( v41 != 10 )
      {
        if ( sub_40894B((int)((char *)pActors + 836 * v41)) )
        {
          v7 = *((_DWORD *)v5 + 9);
          if ( BYTE1(v7) < 0 )
          {
            v8 = dword_4F6E08[v6];
            LOBYTE(v7) = v7 | 0x80;
            *((_DWORD *)v5 + 9) = v7;
            v37 = 8 * v6 | 3;
            memcpy(&v33, sub_4040E9(8 * v6 | 3, v8, &v35, 0), 0x1Cu);
            memcpy(&v32, &v33, 0x1Cu);
            sub_403F58(v41, 4, 32, (signed int)&v32);
            *(_DWORD *)(16 * (*(_DWORD *)(v1 + 12) + 2) + v1) = v37;
            *(_DWORD *)(16 * *(_DWORD *)(v1 + 12) + v1 + 44) = 2;
            compile_error;//*(_DWORD *)(16 * *(_DWORD *)(v1 + 12)++ + v1 + 40) = 0;
          }
        }
        v4 = v39;
      }
      ++v40;
      v38 += 4;
    }
    while ( v40 < v4 + dword_4F75D8 );
    v2 = 0;
  }
  compile_error;//v11 = __SETO__(*(_DWORD *)(v1 + 12), v2);
  v9 = *(_DWORD *)(v1 + 12) == v2;
  v10 = *(_DWORD *)(v1 + 12) - v2 < 0;
  v41 = v2;
  v40 = v2;
  if ( !((unsigned __int8)(v10 ^ v11) | v9) )
  {
    v12 = v1 + 36;
    while ( 1 )
    {
      v13 = *(_DWORD *)(v12 - 4) & 7;
      if ( v13 != 4 )
        break;
      v14 = *(_WORD *)(pPlayers[*(_DWORD *)(v12 - 4) >> 3] + 6452);
      if ( v14 != (_WORD)v2 )
      {
        v37 = v14;
        v16 = (signed __int64)((double)v14 * *(double *)&byte_4D8410[88]);
LABEL_20:
        *(_DWORD *)v12 = v16;
        goto LABEL_26;
      }
      v15 = v41++;
      v36[v15] = v40;
LABEL_26:
      ++v40;
      v12 += 16;
      if ( v40 >= *(_DWORD *)(v1 + 12) )
        goto LABEL_27;
    }
    if ( v13 != 3 )
    {
      *(_DWORD *)v12 = 666;
      goto LABEL_26;
    }
    v17 = rand() % 99;
    if ( v17 < 33 )
    {
      *(_DWORD *)v12 = 1;
      goto LABEL_26;
    }
    LODWORD(v16) = HIDWORD(v16) < 66;
    LOBYTE(v16) = HIDWORD(v16) >= 66;
    LODWORD(v16) = 2 * v16 + 3;
    goto LABEL_20;
  }
LABEL_27:
  v18 = 0;
  if ( v41 > v2 )
  {
    do
    {
      v34[v18] = sub_48E1B5(&pParty_global->pPlayers[1743 * (*(_DWORD *)(16 * (v36[v18] + 2) + v1) >> 3)], v2);
      ++v18;
    }
    while ( v18 < v41 );
    if ( v41 > v2 )
    {
      v39 = v2;
      v38 = 1;
      do
      {
        v40 = v38;
        if ( v38 < v41 )
        {
          v19 = (char *)v34 + v39;
          do
          {
            v21 = *(_DWORD *)v19;
            v37 = 4 * v40;
            v20 = &v34[v40];
            v22 = *v20;
            if ( *v20 < v21 )
            {
              *v20 = v21;
              v23 = v37;
              *(_DWORD *)v19 = v22;
              v24 = (char *)v36 + v23;
              v25 = (char *)v36 + v39;
              v26 = *(_DWORD *)v24;
              *(_DWORD *)v24 = *(int *)((char *)v36 + v39);
              *(_DWORD *)v25 = v26;
              v2 = 0;
            }
            ++v40;
          }
          while ( v40 < v41 );
        }
        ++v38;
        v39 += 4;
      }
      while ( v38 - 1 < v41 );
      if ( v41 > v2 )
      {
        do
        {
          v27 = v2 + 2;
          v28 = 16 * v36[v2++];
          compile_error;//v30 = __SETO__(v2, v41);
          v29 = v2 - v41 < 0;
          *(_DWORD *)(v28 + v1 + 36) = v27;
        }
        while ( v29 ^ v30 );
      }
    }
  }
  return sub_404544(v1);
}

//----- (00405CFF) --------------------------------------------------------
void __thiscall sub_405CFF(int this, int a2)
{
  signed int v2; // ebx@1
  int v3; // edi@1
  int v4; // esi@1
  unsigned __int8 v5; // zf@1
  unsigned __int8 v6; // sf@1
  int v7; // ecx@2
  size_t v8; // edx@7
  int v9; // ecx@7
  __int16 v10; // ax@8
  int v11; // ebx@12
  int v12; // eax@13
  int v13; // esi@13
  int v14; // [sp+Ch] [bp-4h]@11

  v3 = this;
  v2 = 0;
  v4 = 0;
  v5 = *(_DWORD *)(this + 12) == 0;
  v6 = *(_DWORD *)(this + 12) < 0;
  *(_DWORD *)(this + 4) = 0;
  if ( !(v6 | v5) )
  {
    v7 = this + 32;
    do
    {
      if ( (*(_BYTE *)v7 & 7) == 3 )
       pActors[*(_DWORD *)v7 >> 3].byte_000024[0] &= 0x7Fu;
      ++v4;
      v7 += 16;
    }
    while ( v4 < *(_DWORD *)(v3 + 12) );
  }
  if ( (signed int)Count > 0 )
  {
    v9 = (int)byte_66524A;
    v8 = Count;
    do
    {
      v10 = *(_WORD *)v9;
      if ( *(_WORD *)v9 & 4 )
      {
        LOBYTE(v10) = v10 & 0xFB;
        *(_WORD *)v9 = v10;
      }
      v9 += 112;
      --v8;
    }
    while ( v8 );
  }
  v14 = 0;
  if ( *(_DWORD *)(v3 + 12) > 0 )
  {
    v11 = v3 + 32;
    do
    {
      v12 = *(_DWORD *)v11 & 7;
      v13 = *(_DWORD *)v11 >> 3;
      if ( v12 == 4 )
      {
        *(_WORD *)(pPlayers[v13] + 6452) = (signed __int64)((double)*(signed int *)(v11 + 4)
                                                              * *(double *)&byte_4D8410[40]);
      }
      else
      {
        if ( v12 == 3 )
          dword_5FF1D4[209 * v13] = (signed __int64)((double)*(signed int *)(v11 + 4) * *(double *)&byte_4D8410[40]);
      }
      ++v14;
      v11 += 16;
    }
    while ( v14 < *(_DWORD *)(v3 + 12) );
    v2 = 0;
  }
  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  if ( a2 != v2 )
    AudioPlayer_sub_4AA306(pAudioPlayer, 206, v2, v2, -1, v2, v2, v2, v2);
  dword_4F8870 &= 0xFFFFFFFDu;
  sub_4263A0(pClass24_global);
  dword_50C994 = v2;
  dword_50C998 = v2;
}

//----- (0044C59D) --------------------------------------------------------
int __fastcall sub_44C59D(unsigned char *pFontData, const char *pString, unsigned int *a3, char a4, int a5)
{
  const char *v5; // ebx@1
  signed int v8; // ebx@3
  int v9; // esi@3
  size_t v10; // eax@3
  unsigned __int8 v11; // cl@4
  unsigned __int8 *v13; // [sp+14h] [bp+Ch]@3
 int i;

 if (!pString)
   return 0;

 v5 = pString;
 v9 = pFontData[5] - 3;
 v13 = FitTextInAWindow(pString, pFontData, a3, a4, 0);
 v10 = strlen(pString);
 v8 = 0;

 for (i = 0; i < v10; ++i)
 {
  if (sub_44C4DE(*v13, pFontData))
  {
   v11 = *v13;
   if (v11 == 9)
     goto LABEL_8;

   switch (v11)
   {
    case 0xAu:
      v9 = v9 + *(_BYTE *)(pFontData + 5) - 3;
    break;

    case 0xCu:
      v13 += 5;
      v8 += 5;
    break;

    case 0xDu:
LABEL_8:
      if (a5 != 1)
      {
       v13 += 3;
       v8 += 3;
      }
    break;
   }
  }
  ++v8;
  ++v13;
 }

 return v9;
}

//----- (004647AB) --------------------------------------------------------
void __cdecl sub_4647AB()
{
 class28_fn0(class28_global, dword_576FE8, dword_576FEC, dword_576FF0, dword_576FF4);
 class28_fn2(class28_global, (signed __int64)(flt_6BE3A0 * 65536.0));

 pClass55_global = malloc(sizeof(struct class55));
 memset(pClass55_global, 0, sizeof(struct class55));
 class55_sub_42394D(pClass55_global, 65, dword_577000 - dword_576FF8 + 1, dword_577004 - dword_576FFC + 1);

 sub_42F3D6();
 pClass17_Bitmaps_LOD->dword_011B84 = pClass17_Bitmaps_LOD->uNumLoadedFiles;
 pClass17_Sprites_LOD->dword_00ECA0 = pClass17_Sprites_LOD->dword_00EC9C;
 pClass17_Icons_LOD->dword_011B84 = pClass17_Icons_LOD->uNumLoadedFiles;
}

//----- (00443FDC) --------------------------------------------------------
function_error;//void __usercall sub_443FDC(signed __int64 a1<edx:eax>)
void __fastcall sub_443FDC(__int64 a1)
{
  int v1; // esi@1
  _UNKNOWN *v2; // ebx@2
  char *v3; // esi@7
  int v4; // eax@9
  __int16 v5; // cx@9
  __int16 v6; // di@9
  int v7; // ecx@13
  int v8; // ebx@26
  int v9; // ecx@33
  __int64 v10; // qax@33
  unsigned __int8 v11; // cf@33
  int v12; // ecx@33
  int v13; // edi@33
  __int64 v14; // qax@33
  unsigned __int8 v15; // cf@33
  int v16; // ecx@33
  int v17; // edi@33
  __int64 v18; // qax@33
  unsigned __int8 v19; // cf@33
  int v20; // ecx@33
  int v21; // edi@33
  __int64 v22; // qax@33
  unsigned __int8 v23; // cf@33
  int v24; // ecx@33
  __int64 v25; // ST00_8@33
  __int64 v26; // [sp+Ch] [bp-44h]@12
  signed __int64 v27; // [sp+14h] [bp-3Ch]@26
  __int64 v28; // [sp+1Ch] [bp-34h]@7
  _UNKNOWN *v29; // [sp+28h] [bp-28h]@2
  int v30; // [sp+2Ch] [bp-24h]@26
  int v31; // [sp+30h] [bp-20h]@1
  int v32; // [sp+34h] [bp-1Ch]@26
  int v33; // [sp+38h] [bp-18h]@26
  int v34; // [sp+3Ch] [bp-14h]@15
  int v35; // [sp+3Ch] [bp-14h]@26
  int v36; // [sp+40h] [bp-10h]@26
  __int16 v37; // [sp+46h] [bp-Ah]@9
  __int16 v38; // [sp+48h] [bp-8h]@9
  __int16 v39; // [sp+4Ah] [bp-6h]@9
  __int16 v40; // [sp+4Ch] [bp-4h]@9
  __int16 v41; // [sp+4Eh] [bp-2h]@9

  v1 = 0;
  v31 = 0;
  if ( uLevelEvtNumEvents > 0 )
  {
    v2 = pLevelEvents;
    v29 = pLevelEvents;
    while ( 1 )
    {
      LODWORD(a1) = *((_WORD *)v2 + 4);
      if ( (unsigned __int8)byte_5B3524[(_DWORD)a1] == 3 )
      {
        sub_4A9A67(
          pSoundList,
          (unsigned __int8)byte_5B3525[(_DWORD)a1]
        + (((unsigned __int8)byte_5B3526[(_DWORD)a1]
          + (((unsigned __int8)byte_5B3527[(_DWORD)a1] + ((unsigned __int8)byte_5B3528[(_DWORD)a1] << 8)) << 8)) << 8),
          v1);
        goto LABEL_36;
      }
      if ( (unsigned __int8)byte_5B3524[(_DWORD)a1] == 31 )
        break;
      if ( (unsigned __int8)byte_5B3524[(_DWORD)a1] == 37 )
      {
        v7 = *(_DWORD *)v2;
        dword_597F18 = *((_DWORD *)v2 + 1);
        sub_44684A(v7, 0, v1);
        dword_597F18 = v1;
      }
      else
      {
        if ( (unsigned __int8)byte_5B3524[(_DWORD)a1] == 38 )
          break;
      }
LABEL_36:
      ++v31;
      v2 = (char *)v2 + 12;
      v29 = v2;
      if ( v31 >= uLevelEvtNumEvents )
        return;
    }
    v28 = qword_6A12E0;
    v3 = (char *)&unk_5B5928 + 32 * dword_5B65C8;
    if ( dword_6BE360 == 1 )
      v28 = qword_6BE6B4;
    v5 = (unsigned __int8)byte_5B3524[(_DWORD)a1];
    WORD2(a1) = *(_WORD *)v2;
    *((_WORD *)v3 + 14) = v5;
    *((_WORD *)v3 + 4) = WORD2(a1);
    *((_WORD *)v3 + 5) = *((_WORD *)v2 + 2);
    v41 = (unsigned __int8)byte_5B3526[(_DWORD)a1];
    *((_WORD *)v3 + 9) = v41;
    v40 = (unsigned __int8)byte_5B3527[(_DWORD)a1];
    *((_WORD *)v3 + 10) = v40;
    v39 = (unsigned __int8)byte_5B3528[(_DWORD)a1];
    *((_WORD *)v3 + 11) = v39;
    v6 = (unsigned __int8)byte_5B3525[(_DWORD)a1];
    v38 = (unsigned __int8)byte_5B3529[(_DWORD)a1];
    *((_WORD *)v3 + 12) = v38;
    v37 = (unsigned __int8)byte_5B352A[(_DWORD)a1];
    *((_WORD *)v3 + 13) = v37;
    WORD2(a1) = (unsigned __int8)byte_5B352C[(_DWORD)a1];
    LOWORD(a1) = (unsigned __int8)byte_5B352B[(_DWORD)a1];
    v4 = (HIDWORD(a1) << 8) + a1;
    *((_WORD *)v3 + 8) = v6;
    *((_WORD *)v3 + 6) = v4;
    *((_WORD *)v3 + 7) = v4;
    if ( v5 == 38 && !(_WORD)v4 )
    {
      if ( v28 )
        v26 = pParty_global->qword_00002C - v28;
      else
        v26 = 0i64;
      v34 = (signed int)(signed __int64)((double)v26 * 0.234375) / 60 / 60 / 24;
      HIDWORD(a1) = v34 / 7 / 4 % 12;
      if ( v34 / 7 / 4 / 12 )
      {
        LODWORD(a1) = 0;
        if ( v6 )
        {
LABEL_25:
          *((_DWORD *)v3 + 1) = a1;
LABEL_34:
          ++dword_5B65C8;
          *(_DWORD *)v3 = a1;
          v1 = 0;
          goto LABEL_36;
        }
      }
      else
      {
        LODWORD(a1) = 0;
      }
      if ( v34 / 7 / 4 != (_DWORD)a1 && v41 != (_WORD)a1
        || v34 / 7 != (_DWORD)a1 && v40 != (_WORD)a1
        || v34 != (_DWORD)a1
        || !v28 )
        goto LABEL_25;
    }
    v30 = (signed int)(signed __int64)((double)pParty_global->qword_00002C * 0.234375) / 60 % 60;
    v35 = (signed int)(signed __int64)((double)pParty_global->qword_00002C * 0.234375) / 60 / 60 / 24 % 7;
    v32 = (signed int)(signed __int64)((double)pParty_global->qword_00002C * 0.234375) / 60 / 60 / 24 / 7 / 4 / 12;
    v27 = (signed __int64)((double)pParty_global->qword_00002C * 0.234375) % 60;
    v8 = (signed int)(signed __int64)((double)pParty_global->qword_00002C * 0.234375) / 60 / 60 % 24;
    v33 = (signed int)(signed __int64)((double)pParty_global->qword_00002C * 0.234375) / 60 / 60 / 24 / 7 % 4;
    v36 = (signed int)(signed __int64)((double)pParty_global->qword_00002C * 0.234375) / 60 / 60 / 24 / 7 / 4 % 12;
    if ( v6 )
    {
      ++v32;
    }
    else
    {
      if ( v41 )
      {
        ++v36;
      }
      else
      {
        if ( v40 )
        {
          ++v33;
        }
        else
        {
          ++v35;
          v30 = v38;
          v8 = v39;
          v27 = v37;
        }
      }
    }
    v9 = 2419200 * (v36 + 12 * v32);
    v10 = 86400 * v35;
    v11 = (_DWORD)v10 >= (unsigned int)-v9;
    v12 = v10 + v9;
    v13 = HIDWORD(v10) + v11 + ((unsigned __int64)(2419200 * (v36 + 12i64 * v32)) >> 32);
    v14 = 604800 * v33;
    v15 = (_DWORD)v14 >= (unsigned int)-v12;
    v16 = v14 + v12;
    v17 = HIDWORD(v14) + v15 + v13;
    v18 = 3600 * v8;
    v19 = (_DWORD)v18 >= (unsigned int)-v16;
    v20 = v18 + v16;
    v21 = HIDWORD(v18) + v19 + v17;
    v22 = 60 * v30;
    v23 = (_DWORD)v22 >= (unsigned int)-v20;
    v24 = v22 + v20;
    HIDWORD(v25) = HIDWORD(v27) + ((_DWORD)v27 >= (unsigned int)-v24) + HIDWORD(v22) + v23 + v21;
    LODWORD(v25) = v27 + v24;
    a1 = (signed __int64)((double)(v25 << 7) * 0.03333333507180214);
    v2 = v29;
    *((_DWORD *)v3 + 1) = HIDWORD(a1);
    goto LABEL_34;
  }
}

//----- (00466B8C) --------------------------------------------------------
int __cdecl sub_466B8C()
{
 if ( !pGame->dword_000004 )
  {
    ClipCursor(0);
    pGame->dword_000004 = true;
    if ( !pD3DRenderer->dword_040058 )
      sub_4667E9();
    if ( MessageBoxA(0, pGlobalTXT_LocalizationStrings[176], pGlobalTXT_LocalizationStrings[59], 0x34u) == 6 )
      sub_45F469(1, 0);
    sub_464761((void *)1);
  }
  return 0;
}

//----- (00487DBE) --------------------------------------------------------
void __cdecl sub_487DBE_LooksLikeResetNewEdgesBuf()
{
 int i;

 for (i = 0; i < 480; ++i)
 {
  pNewEdgesBuf[i].ptr_000010 = &unk_4EC3EC;
  dword_80CA10[i] = 0;
 }

 runtime_warning;  //wtf is this shit? o_O
 for (i = 0; i < 2000; ++i)
   *((_WORD *)pSurfsBuf + 17) = 0;
}

//----- (0049F5A2) --------------------------------------------------------
int sub_49F5A2(void *this, int a2, int a3, int a4, void *Dst, int a6, int a7)
{
  void *v7; // ebx@1
  void *v8; // esi@3
  void *v9; // esi@3
  int v10; // eax@4
  int v11; // ecx@4
  int v12; // eax@6
  int v13; // eax@8
  int v14; // ecx@8
  signed int v15; // eax@11
  char v16; // zf@20
  int result; // eax@21
  char v18[0x38]; // [sp+Ch] [bp-ACh]@3
  __int16 v19; // [sp+44h] [bp-74h]@3
  char v20[0x30]; // [sp+48h] [bp-70h]@3
  int v21; // [sp+78h] [bp-40h]@7
  int v22; // [sp+7Ch] [bp-3Ch]@7
  int v23; // [sp+80h] [bp-38h]@4
  int v24; // [sp+84h] [bp-34h]@4
  int v25; // [sp+88h] [bp-30h]@4
  int v26; // [sp+8Ch] [bp-2Ch]@4
  char Src; // [sp+90h] [bp-28h]@3
  char v28; // [sp+91h] [bp-27h]@3
  char v29; // [sp+92h] [bp-26h]@3
  char v30; // [sp+93h] [bp-25h]@3
  __int16 v31; // [sp+94h] [bp-24h]@3
  __int16 v32; // [sp+96h] [bp-22h]@3
  __int16 v33; // [sp+98h] [bp-20h]@3
  __int16 v34; // [sp+9Ah] [bp-1Eh]@3
  __int16 v35; // [sp+9Ch] [bp-1Ch]@3
  __int16 v36; // [sp+9Eh] [bp-1Ah]@3
  char v37; // [sp+A0h] [bp-18h]@3
  char v38; // [sp+A1h] [bp-17h]@3
  __int16 v39; // [sp+A2h] [bp-16h]@3
  __int16 v40; // [sp+A4h] [bp-14h]@3
  int v41; // [sp+A8h] [bp-10h]@3
  int v42; // [sp+ACh] [bp-Ch]@1
  char v43; // [sp+B3h] [bp-5h]@18
  int i; // [sp+B4h] [bp-4h]@6

  v7 = this;
  v42 = a3;
  if ( a3 & 1 )
    v42 = a3 + 1;
  v31 = 0;
  v32 = 0;
  v33 = a3 - 1;
  v34 = a4 - 1;
  v39 = v42;
  memset(v20, 0, 0x30u);
  memset(v18, 0, 0x38u);
  v9 = Dst;
  v37 = 0;
  v19 = 0;
  Src = 10;
  v28 = 5;
  v29 = 1;
  v30 = 8;
  v35 = 75;
  v36 = 75;
  v38 = 3;
  v40 = 1;
  memcpy(Dst, &Src, 1u);
  v9 = (char *)v9 + 1;
  memcpy(v9, &v28, 1u);
  v9 = (char *)v9 + 1;
  memcpy(v9, &v29, 1u);
  v9 = (char *)v9 + 1;
  memcpy(v9, &v30, 1u);
  v9 = (char *)v9 + 1;
  memcpy(v9, &v31, 2);
  v9 = (char *)v9 + 2;
  memcpy(v9, &v32, 2);
  v9 = (char *)v9 + 2;
  memcpy(v9, &v33, 2);
  v9 = (char *)v9 + 2;
  memcpy(v9, &v34, 2);
  v9 = (char *)v9 + 2;
  memcpy(v9, &v35, 2);
  v9 = (char *)v9 + 2;
  memcpy(v9, &v36, 2);
  v9 = (char *)v9 + 2;
  memcpy(v9, v20, 0x30u);
  v9 = (char *)v9 + 48;
  memcpy(v9, &v37, 1u);
  v9 = (char *)v9 + 1;
  memcpy(v9, &v38, 1u);
  v9 = (char *)v9 + 1;
  memcpy(v9, &v39, 2);
  v9 = (char *)v9 + 2;
  memcpy(v9, &v40, 2);
  v9 = (char *)v9 + 2;
  memcpy(v9, v18, 0x3Au);
  v8 = (char *)v9 + 58;
  v41 = class23_AllocatedNamedBuffer(class23_instance, 0, 3 * a3 + 6, 0);
  if ( a4 > 0 )
  {
    v11 = v42;
    v25 = a4;
    v26 = 3 * v42;
    v23 = 2 * a3;
    v10 = a2;
    v24 = a2;
    while ( 1 )
    {
      a4 = v10;
      v12 = 0;
      i = 0;
      if ( a3 > 0 )
      {
        v21 = v41 + v11;
        v22 = v41 + 2 * v42;
        do
        {
          *(_BYTE *)(v12 + v41) = (*((_DWORD *)v7 + 65590) & *(_WORD *)a4) >> (*((_BYTE *)v7 + 262352)
                                                                             + *((_BYTE *)v7 + 262356)
                                                                             + (unsigned __int8)*((_DWORD *)v7 + 65587)
                                                                             - 8);
          v13 = i;
          *(_BYTE *)(v21 + i) = (*((_DWORD *)v7 + 65591) & *(_WORD *)a4) >> (*((_BYTE *)v7 + 262356)
                                                                           + *((_BYTE *)v7 + 262352)
                                                                           - 8);
          v14 = a4;
          a4 += 2;
          *(_BYTE *)(v22 + v13) = (*((_BYTE *)v7 + 262368) & *(_BYTE *)v14) << (8 - *((_BYTE *)v7 + 262356));
          v12 = v13 + 1;
          i = v12;
        }
        while ( v12 < a3 );
      }
      for ( i = 0; i < v26; v8 = (char *)v8 + 1 )
      {
        BYTE3(a4) = 1;
        BYTE3(a2) = *(_BYTE *)(i + v41);
        do
        {
          v15 = i + BYTE3(a4);
          if ( *(_BYTE *)(v15 + v41) != BYTE3(a2) )
            break;
          if ( !(v15 % v42) )
            break;
          a4 += 16777216;
        }
        while ( BYTE3(a4) < 0x3Fu );
        if ( i + BYTE3(a4) > v26 )
          BYTE3(a4) = 3 * v42 - i;
        if ( BYTE3(a4) > 1u || BYTE3(a2) >= 0xC0u )
        {
          v43 = BYTE3(a4) | 0xC0;
          memcpy(v8, &v43, 1u);
          v8 = (char *)v8 + 1;
        }
        memcpy(v8, (char *)&a2 + 3, 1u);
        i += BYTE3(a4);
      }
      v10 = v23 + v24;
      v16 = v25-- == 1;
      v24 += v23;
      if ( v16 )
        break;
      v11 = v42;
    }
  }
  class23_DeleteBuffer(class23_instance, v41);
  result = a7;
  *(_DWORD *)a7 = (char *)v8 - Dst;
  return result;
}


//----- (00405E14) --------------------------------------------------------
void __thiscall sub_405E14(void *this)
{
  signed int v1; // ecx@1
  int v2; // esi@1
  int v3; // edi@2
  int v4; // ebx@3
  int v5; // edx@20
  int v6; // eax@21
  void *v7; // esi@21
  int v8; // eax@21
  int v9; // eax@22
  int v10; // eax@23
  signed int v11; // eax@37
  signed int v12; // eax@44
  char v13; // [sp+4h] [bp-68h]@21
  char v14; // [sp+20h] [bp-4Ch]@21
  char v15; // [sp+3Ch] [bp-30h]@21
  int v16; // [sp+58h] [bp-14h]@2
  int v17; // [sp+5Ch] [bp-10h]@6
  int v18; // [sp+60h] [bp-Ch]@1
  int v19; // [sp+64h] [bp-8h]@8
  int v20; // [sp+68h] [bp-4h]@1

  v2 = (int)this;
  v1 = 0;
  v18 = v2;
  v20 = 0;
  if ( (signed int)uNumActors > 0 )
  {
    v3 = (int)&unk_5FF22C;
    v16 = (int)&unk_5FF22C;
    do
    {
      v4 = v3 - 212;
      if ( *(_DWORD *)(v3 + 52) < v1 || *(_DWORD *)(v3 + 52) <= v1 && *(_DWORD *)(v3 + 48) <= (unsigned int)v1 )
        v17 = v1;
      else
        v17 = 1;
      v19 = v1;
      do
      {
        if ( v19 != 10 )
        {
          sub_4585CA(v3, pParty_global->qword_00002C, SHIDWORD(pParty_global->qword_00002C));
          v1 = 0;
        }
        ++v19;
        v3 += 16;
      }
      while ( v19 < 22 );
      if ( v17 != v1 )
      {
        if ( *(_DWORD *)(v4 + 264) <= v1 )
        {
          if ( *(_DWORD *)(v4 + 264) < v1 || *(_DWORD *)(v4 + 260) <= (unsigned int)v1 )
            *(_WORD *)(v4 + 138) = *(_WORD *)(152 * *(_WORD *)(v4 + 96) + monster_list[1] - 152);
        }
      }
      if ( !(*(_BYTE *)(v4 + 36) & 0x80) )
      {
        if ( !*(_QWORD *)(v4 + 292) )
        {
          if ( !*(_QWORD *)(v4 + 308) )
          {
            v5 = *(_WORD *)(v4 + 160);
            *(_DWORD *)(v4 + 184) += pClass24_global2->dword_00001C;
            if ( *(_DWORD *)(v4 + 184) >= v5 )
            {
              v17 = dword_4F6E08[v20];
              v7 = sub_4040E9(8 * v20 | 3, v17, &v13, v1);
              v8 = *(_WORD *)(v4 + 176);
              memcpy(&v15, v7, 0x1Cu);
              v6 = v8 - 4;
              memcpy(&v14, &v15, 0x1Cu);
              if ( v6 )
              {
                v9 = v6 - 1;
                if ( v9 )
                {
                  v10 = v9 - 6;
                  if ( v10 )
                  {
                    if ( v10 != 8 )
                      sub_403F58(v20, v17, 32, (signed int)&v14);
                  }
                }
              }
              else
              {
                *(_DWORD *)(v4 + 184) = 0;
                *(_WORD *)(v4 + 160) = 0;
                *(_WORD *)(v4 + 176) = 5;
                sub_45976D(v4);
              }
              v2 = v18;
              v1 = 0;
            }
          }
        }
      }
      ++v20;
      v3 = v16 + 836;
      v16 += 836;
    }
    while ( v20 < (signed int)uNumActors );
  }
  if ( *(_DWORD *)(v2 + 4) != 1 )
  {
    if ( *(_DWORD *)(v2 + 4) != 2 )
    {
      if ( *(_DWORD *)(v2 + 4) == 3 )
      {
        if ( *(_DWORD *)(v2 + 20) <= v1 || *(_BYTE *)(v2 + 24) & 8 )
        {
          *(_DWORD *)(v2 + 24) &= 0xFFFFFFF7u;
          *(_DWORD *)(v2 + 4) = 1;
          *(_DWORD *)(v2 + 8) = 64;
        }
        else
        {
          sub_406FA8(v2);
        }
      }
      return;
    }
    if ( !(*(_BYTE *)(v2 + 24) & 1) )
    {
      v11 = *(_DWORD *)(v2 + 16);
      if ( v11 == 100 )
      {
        sub_406051((void *)v2);
LABEL_39:
        sub_40652A(v2);
        return;
      }
      if ( v11 > v1 || *(_DWORD *)(v2 + 36) <= v1 )
      {
        sub_4065B0(v2);
        goto LABEL_39;
      }
    }
    sub_4061CA(v2);
    return;
  }
  v12 = *(_DWORD *)(v2 + 8);
  if ( v12 == 64 )
  {
    sub_406A63(v2);
  }
  else
  {
    if ( v12 > v1 )
    {
      sub_406B9F(v2);
    }
    else
    {
      sub_406AFE(v2);
      *(_DWORD *)(v2 + 16) = 100;
    }
  }
  *(_DWORD *)(v2 + 8) -= pClass24_global->dword_00001C;
}

//----- (00465C8B) --------------------------------------------------------
struct CGame *__cdecl GameInitialize()
{
 pGame = malloc(sizeof(struct CGame));
 if (pGame)
   CGame_ctor(pGame);

 return pGame;
}

//----- (00456D17) --------------------------------------------------------
int __thiscall sub_456D17(struct class40 *_this, int a2)
{
  int result; // eax@1

  result = (int)((char *)_this + 48 * *(_DWORD *)a2);
  if ( *(_BYTE *)(result + 37) == 3 )
  {
    *(_DWORD *)(a2 + 4) = *(_BYTE *)(result + 39);
    *(_DWORD *)(a2 + 12) = *(_BYTE *)(result + 38);
    result = *(_BYTE *)(result + 40);
    *(_DWORD *)(a2 + 8) = result;
  }
  return result;
}

//----- (00406051) --------------------------------------------------------
__int16 __thiscall sub_406051(void *this)
{
  int v1; // ecx@1
  int v2; // ebx@1
  int v3; // edi@1
  int v4; // esi@1
  signed int v5; // eax@4
  int v6; // eax@12
  int v7; // eax@15
  int v8; // edi@17
  int v9; // edx@23
  int v10; // eax@26
  int v11; // eax@30
  int v12; // ebx@30
  int v13; // edi@31
  signed int v15; // [sp+Ch] [bp-10h]@5
  int v16; // [sp+10h] [bp-Ch]@3
  int v17; // [sp+14h] [bp-8h]@2
  int v18; // [sp+14h] [bp-8h]@16
  signed int v19; // [sp+18h] [bp-4h]@1
  int v20; // [sp+18h] [bp-4h]@14

  v4 = (int)this;
  v1 = 0;
  v19 = 0;
  v2 = *(_DWORD *)(v4 + 12);
  *(_DWORD *)(v4 + 28) = 0;
  v3 = 16 * v2 + v4 + 36;
  do
  {
    v17 = v1;
    if ( *(_DWORD *)(v4 + 12) <= v1 )
      goto LABEL_11;
    v16 = v4 + 32;
    while ( 1 )
    {
      v5 = *(_DWORD *)v16;
      if ( (*(_BYTE *)v16 & 7) == 4 )
        break;
LABEL_8:
      ++v17;
      v16 += 16;
      if ( v17 >= *(_DWORD *)(v4 + 12) )
        goto LABEL_11;
    }
    v15 = v5 >> 3;
    if ( !sub_492C0B(pPlayers[v5 >> 3]) || v19 != v15 )
    {
      v1 = 0;
      goto LABEL_8;
    }
    v1 = 0;
LABEL_11:
    if ( v17 == *(_DWORD *)(v4 + 12) )
    {
      *(_DWORD *)v3 = 100;
      v6 = 8 * v19;
      LOBYTE(v6) = 8 * v19 | 4;
      *(_DWORD *)(v3 + 8) = v1;
      *(_DWORD *)(v3 - 4) = v6;
      *(_DWORD *)(v3 + 4) = v1;
      ++v2;
      v3 += 16;
    }
    ++v19;
  }
  while ( v19 < 4 );
  *(_DWORD *)(v4 + 12) = v2;
  v20 = v1;
  if ( dword_4F75D8 > v1 )
  {
    v7 = 16 * v2 + v4 + 36;
    do
    {
      v18 = v1;
      if ( *(_DWORD *)(v4 + 12) > v1 )
      {
        v8 = v4 + 32;
        do
        {
          if ( (*(_BYTE *)v8 & 7) == 3 && dword_4F7DB0[v20] == *(_DWORD *)v8 >> 3 )
            break;
          ++v18;
          v8 += 16;
        }
        while ( v18 < *(_DWORD *)(v4 + 12) );
        v1 = 0;
      }
      if ( v18 == *(_DWORD *)(v4 + 12) )
      {
        v9 = dword_4F7DB0[v20];
        *(_DWORD *)v7 = 1;
        *(_DWORD *)(v7 + 8) = v1;
        *(_DWORD *)(v7 - 4) = 8 * v9 | 3;
        *(_DWORD *)(v7 + 4) = v1;
        ++v2;
        v7 += 16;
      }
      ++v20;
    }
    while ( v20 < dword_4F75D8 );
  }
  ++*(_DWORD *)v4;
  *(_DWORD *)(v4 + 12) = v2;
  *(_DWORD *)(v4 + 16) = 100;
  if ( v2 > 0 )
  {
    v10 = v4 + 36;
    do
    {
      if ( *(_DWORD *)v10 <= 0 )
        *(_DWORD *)v10 = 100;
      ++v1;
      v10 += 16;
    }
    while ( v1 < *(_DWORD *)(v4 + 12) );
  }
  LOWORD(v11) = sub_4063A1(v4);
  v12 = 0;
  if ( *(_DWORD *)(v4 + 12) > 0 )
  {
    v13 = v4 + 36;
    do
    {
      v11 = *(_DWORD *)(v13 - 4) & 7;
      if ( (_BYTE)v11 == 4 )
        break;
      if ( *(_DWORD *)v13 > 0 )
        break;
      LOWORD(v11) = sub_40680F((void *)v4, v12++);
      v13 += 16;
    }
    while ( v12 < *(_DWORD *)(v4 + 12) );
  }
  return v11;
}

//----- (0047F0E2) --------------------------------------------------------
bool __cdecl sub_47F0E2()
{
 int i;

 runtime_warning;
 return true;

 for (i = 0; i < pClass17_Bitmaps_LOD->uNumLoadedFiles; ++i)
   pClass17_Bitmaps_LOD->aLODHeaders[i].uDecompressedSize = sub_47CB57(pClass17_Bitmaps_LOD->aLODHeaders[i].pIndexedPixels,
                                                                       pClass17_Bitmaps_LOD->aLODHeaders[i].word_000026,
                                                                       pClass17_Bitmaps_LOD->aLODHeaders[i].uTextureWidth * pClass17_Bitmaps_LOD->aLODHeaders[i].uTextureHeight);
 return true;
}

//----- (004613C4) --------------------------------------------------------
void __cdecl sub_4613C4()
{
  int v2; // esi@1
  __int16 v3; // ax@1
  int v4; // edx@2
  int v5; // edi@4
 int i;

  dword_6836C8 = 0;
  v3 = sub_4488B6(pDecorationDescriptionList, "Event Trigger");
  v2 = v3;

  for (i = 0; i < dword_69ADD0; ++i)
  {
    v4 = &array_6836D0[i];

      if ( *(_WORD *)v4 == v2 )
      {
        v5 = dword_6836C8++;
        dword_6807E8[v5] = i;
      }

  }
}

//----- (004061CA) --------------------------------------------------------
signed int __thiscall sub_4061CA(int this)
{
  signed int result; // eax@1
  signed int v2; // ebx@1
  int v3; // ebp@1
  int v4; // esi@1
  int v5; // edi@7
  int v6; // ecx@9
  int v7; // ebx@17
  int v8; // ebp@27
  int v9; // edi@28
  __int16 v10; // ax@30
  int v11; // ecx@30
  int v12; // edx@35
  unsigned __int8 v13; // cf@37
  signed int v14; // [sp+10h] [bp-4h]@7

  v4 = this;
  sub_404544(this);
  v3 = v4 + 32;
  v2 = 0;
  result = *(_DWORD *)(v4 + 32);
  if ( (*(_BYTE *)(v4 + 32) & 7) == 4 )
  {
    result = (result >> 3) + 1;
    uMaybeSelectedCharacter = result;
  }
  else
  {
    uMaybeSelectedCharacter = 0;
  }
  dword_57702C = 1;
  if ( *(_DWORD *)(v4 + 28) )
  {
    dword_4F8870 |= 2;
    return result;
  }
  dword_4F8870 &= 0xFFFFFFFDu;
  if ( *(_DWORD *)(v4 + 36) <= 0 )
    return result;
  v5 = 0;
  v14 = 0;
  if ( *(_DWORD *)(v4 + 12) <= 0 )
    goto LABEL_27;
  do
  {
    result = *(_DWORD *)v3;
    if ( (*(_BYTE *)v3 & 7) != 4 )
    {
      result = (signed int)((char *)pActors + 836 * (result >> 3));
      LOWORD(v6) = *(_WORD *)(result + 176);
      if ( (_WORD)v6 == 4
        || (_WORD)v6 == 8
        || (_WORD)v6 == 2
        || (_WORD)v6 == 3
        || (_WORD)v6 == 12
        || (_WORD)v6 == 13
        || (_WORD)v6 == 18
        || (_WORD)v6 == 17 )
      {
        v7 = *(_WORD *)(result + 160);
        //*(_DWORD *)(result + 184) += pClass24_global->dword_00001C;
        *(_DWORD *)(result + 184) += pClass24_global->dword_00001C;        
        if ( *(_DWORD *)(result + 184) < v7 )
        {
          v14 = 1;
LABEL_19:
          v2 = 0;
          goto LABEL_20;
        }
        v6 = (signed __int16)v6;
        if ( (signed __int16)v6 == 4 )
        {
          v2 = 0;
          *(_WORD *)(result + 176) = 5;
          *(_DWORD *)(result + 184) = 0;
          *(_WORD *)(result + 160) = 0;
          result = sub_45976D(result);
        }
        else
        {
          if ( v6 != 8 )
            goto LABEL_19;
          v2 = 0;
          result = sub_403F58(*(_DWORD *)v3 >> 3, dword_4F6E08[*(_DWORD *)v3 >> 3], 32, 0);
        }
      }
    }
LABEL_20:
    ++v5;
    v3 += 16;
  }
  while ( v5 < *(_DWORD *)(v4 + 12) );
  if ( v14 != v2 )
  {
    *(_DWORD *)(v4 + 24) |= 1u;
    return result;
  }
LABEL_27:
  *(_DWORD *)(v4 + 24) &= 0xFFFFFFFEu;
  v8 = 0;
  if ( *(_DWORD *)(v4 + 12) > v2 )
  {
    v9 = v4 + 32;
    do
    {
      if ( (*(_BYTE *)v9 & 7) != 4 )
      {
        v11 = *(_DWORD *)v9 >> 3;
        v10 = *((_WORD *)pActors + 418 * v11 + 88);
        if ( v10 != 5 )
        {
          if ( v10 != 4 )
          {
            if ( v10 != 11 )
            {
              if ( v10 != 19 )
              {
                if ( v10 != 17 )
                {
                  v12 = dword_4F6E08[v11];
                  *(_DWORD *)(v9 + 8) = v2;
                  sub_403F58(v11, v12, 32, v2);
                }
              }
            }
          }
        }
      }
      ++v8;
      v9 += 16;
    }
    while ( v8 < *(_DWORD *)(v4 + 12) );
  }
  *(_DWORD *)(v4 + 4) = 3;
  v13 = (_DWORD)pParty_global->qword_00002C >= 0xFFFFFF2Bu;
  LODWORD(pParty_global->qword_00002C) = pParty_global->qword_00002C + 213;
  HIDWORD(pParty_global->qword_00002C) += v2 + v13;
  result = sub_494035();
  *(_DWORD *)(v4 + 20) = 130;
  return result;
}

//----- (004645FA) --------------------------------------------------------
int __cdecl sub_4645FA()
{
  struct tagRECT Rect; // [sp+0h] [bp-10h]@6

  if (dword_720010)
    Mouse_suspend(dword_720010);

  if ( *(_BYTE *)(&pGame->class14_obj->dword_000004) )
  {
    if (dword_69B00C)
      Keyboard_suspend(dword_69B00C);
  }
  RegistryWriteInt("startinwindow", pD3DRenderer->dword_040058);
  if ( GetWindowRect(hWnd_global, &Rect) )
  {
    if ( pD3DRenderer->dword_040058 )
    {
      RegistryWriteInt("window X", Rect.left);
      RegistryWriteInt("window Y", Rect.top);
    }
  }
  RegistryWriteInt("debug flags", dword_51076C);
  RegistryWriteInt("valAlwaysRun", dword_6BE37C);
  sub_45814E(pClass40);
  sub_477266(pNPCStats);
  sub_465C53();
  sub_465C2C();
  if (pGame->pClass03)
    sub_469CC2(pGame->pClass03);
  sub_4ABD5B(pAudioPlayer);
  sub_461A11(pClass17_New_LOD);
  sub_461A11(pClass17_Games_LOD);
  ClipCursor(0);
  return sub_465CF3();
}

//----- (004063A1) --------------------------------------------------------
signed int __thiscall sub_4063A1(int this)
{
  signed int result; // eax@1
  int v2; // edx@1
  int v3; // ebp@1
  int v4; // esi@1
  int v5; // edx@3
  int v6; // edi@4
  int v7; // ecx@5
  char *v8; // ecx@11
  __int16 v9; // dx@12
  int v10; // edi@16
  int v11; // edx@17
  char v12; // zf@18

  v4 = this;
  sub_404544(this);
  v3 = v4 + 36;
  result = 1;
  dword_57702C = 1;
  v2 = *(_DWORD *)(v4 + 36);
  if ( v2 )
  {
    if ( (*(_BYTE *)(v4 + 32) & 7) == 4 )
    {
      v5 = *(_DWORD *)(v4 + 12);
      while ( 1 )
      {
        v6 = 0;
        if ( v5 > 0 )
        {
          v7 = v4 + 36;
          do
          {
            --*(_DWORD *)v7;
            v5 = *(_DWORD *)(v4 + 12);
            ++v6;
            v7 += 16;
          }
          while ( v6 < v5 );
        }
        --*(_DWORD *)(v4 + 16);
        if ( *(_DWORD *)(v4 + 16) <= 0 )
          break;
        if ( !*(_DWORD *)v3 )
          goto LABEL_9;
      }
LABEL_24:
      result = 1;
    }
    else
    {
      v8 = (char *)pActors + 836 * (*(_DWORD *)(v4 + 32) >> 3);
      if ( v2 > 0 )
      {
        do
        {
          v9 = *((_WORD *)v8 + 88);
          if ( v9 == 5 )
            break;
          if ( v9 == 4 || v9 == 19 || v9 == 11 )
            break;
          v10 = 0;
          if ( *(_DWORD *)(v4 + 12) > 0 )
          {
            v11 = v4 + 36;
            do
            {
              v12 = *(_DWORD *)v11-- == 1;
              if ( v12 )
                *(_DWORD *)(v11 + 4) = 0;
              ++v10;
              v11 += 16;
            }
            while ( v10 < *(_DWORD *)(v4 + 12) );
          }
          --*(_DWORD *)(v4 + 16);
          if ( *(_DWORD *)(v4 + 16) <= 0 )
            goto LABEL_24;
        }
        while ( *(_DWORD *)v3 > 0 );
      }
LABEL_9:
      result = 0;
    }
  }
  return result;
}

//----- (004598AF) --------------------------------------------------------
void *__thiscall sub_4598AF(void *Dst, void *Src)
{
  void *v3; // esi@1
  int v4; // eax@1
  int v5; // ecx@1

  v3 = Dst;
  memcpy(Dst, Src, 4u);
  v4 = class23_AllocatedNamedBuffer(class23_instance, *((_DWORD *)v3 + 1), 152 * *(_DWORD *)v3, "Mon Race");
  v5 = *(_DWORD *)v3;
  *((_DWORD *)v3 + 1) = v4;
  return memcpy((void *)v4, (char *)Src + 4, 152 * v5);
}

//----- (00406457) --------------------------------------------------------
int __thiscall sub_406457(void *this, int a2)
{
  signed int v2; // eax@1
  int v3; // esi@1
  int v4; // eax@2
  int v5; // edx@2
  signed int v6; // ecx@2
  int result; // eax@11
  int v8; // edx@13
  int v9; // ecx@14
  char v10; // zf@15

  v3 = (int)this;
  v2 = *((_DWORD *)this + 4 * (a2 + 2));
  if ( (*((_BYTE *)this + 16 * (a2 + 2)) & 7) == 4 )
  {
    v6 = v2 >> 3;
    v5 = 4 * (v2 >> 3) + 11415804;
    v4 = dword_AE30FC[v2 >> 3];
    if ( v4 )
      *(_DWORD *)v5 = 0;
    else
      v4 = sub_48E1B5((void *)pPlayers[v6], 0);
    if ( v4 < 30 )
      v4 = 30;
  }
  else
  {
    v4 = pMonsterStats->pMonsterInfos[word_5FF1B8[418 * (v2 >> 3)]].dword_000050;
  }
  *(_DWORD *)(16 * a2 + v3 + 36) = v4;
  sub_404544(v3);
  if ( (*(_BYTE *)(v3 + 32) & 7) == 4 )
    uMaybeSelectedCharacter = (*(_DWORD *)(v3 + 32) >> 3) + 1;
  else
    uMaybeSelectedCharacter = 0;
  result = v3 + 36;
  dword_57702C = 1;
  while ( *(_DWORD *)result > 0 )
  {
    if ( *(_DWORD *)(v3 + 16) <= 0 )
      break;
    v8 = 0;
    if ( *(_DWORD *)(v3 + 12) > 0 )
    {
      v9 = v3 + 36;
      do
      {
        v10 = *(_DWORD *)v9-- == 1;
        if ( v10 )
          *(_DWORD *)(v9 + 4) = 0;
        ++v8;
        v9 += 16;
      }
      while ( v8 < *(_DWORD *)(v3 + 12) );
    }
    --*(_DWORD *)(v3 + 16);
    if ( *(_DWORD *)(v3 + 16) <= 0 )
      break;
  }
  return result;
}

//----- (0040652A) --------------------------------------------------------
void __thiscall sub_40652A(int this)
{
  int v1; // edx@2
  char *v2; // eax@5
  __int16 v3; // si@5
  int v4; // esi@8
  int v5; // [sp+Ch] [bp-4h]@1

  v5 = 0;
  if ( *(_DWORD *)(this + 12) > 0 )
  {
    v1 = this + 36;
    do
    {
      if ( !*(_DWORD *)v1 )
      {
        if ( (*(_BYTE *)(v1 - 4) & 7) == 4 )
          return;
        v2 = (char *)pActors + 836 * (*(_DWORD *)(v1 - 4) >> 3);
        v3 = *((_WORD *)v2 + 88);
        if ( !v3 || v3 == 9 || v3 == 7 )
        {
         v4 = pMonsterStats->pMonsterInfos[*((_WORD *)v2 + 48)].dword_000050;
          *(_DWORD *)v1 = v4;
          if ( *(_QWORD *)(v2 + 324) > 0i64 )
            *(_DWORD *)v1 = 2 * v4;
        }
      }
      ++v5;
      v1 += 16;
    }
    while ( v5 < *(_DWORD *)(this + 12) );
  }
}

//----- (0046D49E) --------------------------------------------------------
int __fastcall sub_46D49E(signed int a1, signed int a2, int a3, int a4, int a5, int a6, int a7)
{
  signed int v7; // ebx@1
  signed int v8; // edi@1
  int v9; // eax@1
  struct class51_BModel *v10; // esi@4
  char v11; // al@11
  struct class51_stru2 *v12; // ecx@11
  int v15; // edx@22
  int v17; // edi@24
  signed int v18; // edx@26
  int v19; // eax@28
  int v20; // edx@30
  int v21; // ST1C_4@30
  signed int v22; // edx@30
  signed __int64 v23; // qtt@30
  int v26; // eax@36
  int v27; // ecx@38
  int result; // eax@42
  signed int v29; // ecx@43
  signed int v30; // edx@44
  signed int v31; // edi@44
  int v32; // eax@45
  int v33; // esi@45
  int v34; // eax@57
  int v35; // ecx@59
  int v36; // [sp+Ch] [bp-34h]@8
  int v37; // [sp+10h] [bp-30h]@22
  int v38; // [sp+14h] [bp-2Ch]@24
  int v39; // [sp+18h] [bp-28h]@22
  signed int v42; // [sp+24h] [bp-1Ch]@1
  int v44; // [sp+2Ch] [bp-14h]@8
  bool v45; // [sp+30h] [bp-10h]@22
  bool v46; // [sp+34h] [bp-Ch]@24
  signed int v47; // [sp+38h] [bp-8h]@1
  signed int v48; // [sp+3Ch] [bp-4h]@1
  signed int v50; // [sp+58h] [bp+18h]@22
  signed int v51; // [sp+58h] [bp+18h]@43
 int i, j;

  v8 = a2;
  v7 = a1;
  v47 = a2;
  v42 = a1;
  v48 = 1;
  v9 = sub_48257A(a1, a2, a5, a7);
  dword_721160[0] = -1;
  dword_721110[0] = -1;
  dword_7211B0[0] = v9;

  if ( pClass51_global->uNumBModels <= 0 )
    goto LABEL_63;


  for (i = 0; i < pClass51_global->uNumBModels; ++i)
  {
    v10 = &pClass51_global->pBModels[i];
    if (v7 <= v10->dword_000088 && v7 >= v10->dword_00007C)
      {
        if (v8 <= v10->dword_00008C && v8 >= v10->dword_000080)
          {
            v44 = 0;
            v36 = v10->dword_00004C;
            if (v10->dword_00004C > 0)
            {
              while ( 1 )
              {
                v12 = &v10->ptr_000054[v44];
                v11 = *(_BYTE *)(v12 + 303);
                if ( v11 == 3 || v11 == 4 )
                {
                  if ( !(v12->byte_000010[15] & 0x20) )
                  {
                    if (v7 <= v12->word_000118 && v7 >= v12->word_000116)
                    {
                        if (v8 <= v12->word_00011C && v8 >= v12->word_00011A)
                          {
                            for (j = 0; j < v12->byte_00012E; ++j)
                            {
                                word_721040[2 * j + 0] = v12->array_000098[j] + *(_WORD *)(v10->ptr_000048 + 12 * v12->array_000020[j]);
                                word_721040[2 * j + 1] = v12->array_000098[j] + *(_WORD *)(v10->ptr_000048 + 12 * v12->array_000020[j + 1]);

                                word_720F70[2 * j + 0] = v12->array_0000C0[j] + *(_WORD *)(v10->ptr_000048 + 12 * v12->array_000020[j] + 4);
                                word_720F70[2 * j + 1] = v12->array_0000C0[j] + *(_WORD *)(v10->ptr_000048 + 12 * v12->array_000020[j + 1] + 4);
                              v7 = v42;
                            }
                            word_721040[2 * v12->byte_00012E] = word_721040[0];
                            word_720F70[2 * v12->byte_00012E] = word_720F70[0];
                            v37 = 2 * v12->byte_00012E;
                            v15 = 0;
                            v45 = word_720F70[0] >= v47;
                            v50 = 0;
                            v39 = 0;
                            if ( v37 > 0 )
                            {
                              do
                              {
                                if ( v50 >= 2 )
                                  break;
                                v17 = 2 * v15;
                                v7 = v42;
                                v38 = word_720F70[v15 + 1];
                                v46 = word_720F70[v15 + 1] >= v47;
                                if ( v45 != v46 )
                                {
                                  if (word_721040[v17 / 2 + 1] >= v42 )
                                    v18 = 0;
                                  else
                                    v18 = 2;
                                  v19 = v18 | word_721040[v17 / 2] < v42;
                                  if ( v19 != 3 )
                                  {
                                    if ( !v19)
                                      ++v50;
                                    else
                                    {
                                     v20 = word_720F70[v17 / 2];
                                     v21 = v38 - word_720F70[v17 / 2];
                                     v22 = v47 - word_720F70[v17 / 2];
                                     LODWORD(v23) = v22 << 16;
                                     HIDWORD(v23) = v22 >> 16;
                                     if (((signed int)(word_721040[v17 / 2 + 1] -
                                                       word_721040[v17 / 2] *
                                                       (v23 / v21) >> 16) +
                                                       word_721040[v17 / 2]) >= v42)
                                      ++v50;
                                    }
                                  }
                                }
                                v15 = v39 + 1;
                                v45 = v46;
                              }
                              while (++v39 < v37);

                              if ( v50 == 1 )
                              {
                                if ( v48 >= 20 )
                                  break;
                                if ( *(_BYTE *)(v12 + 303) == 3 )
                                  v26 = *(_DWORD *)(v10->ptr_000048 + 12 * *(_WORD *)(v12 + 32) + 8);
                                else
                                  v26 = ((unsigned __int64)(*(_DWORD *)(v12 + 16) * v7) >> 16)
                                      + ((unsigned __int64)(*(_DWORD *)(v12 + 20) * v47) >> 16)
                                      + *(_WORD *)(v12 + 26);
                                v27 = 4 * v48++;
                                *(int *)((char *)dword_7211B0 + v27) = v26;
                                *(int *)((char *)dword_721160 + v27) = i;
                                *(int *)((char *)dword_721110 + v27) = v44;
                              }
                            }
                        }
                    }
                  }
                }
                ++v44;
                if ( v44 >= v36 )
                  break;
                v8 = v47;
              }
            }
        }
    }
    v8 = v47;
  }

  if ( v48 == 1 )
  {
LABEL_63:
    *(_DWORD *)a6 = 0;
    return dword_7211B0[0];
  }

  v29 = 0;
  v51 = 1;
  if ( v48 <= 1 )
    goto LABEL_55;
  v31 = 0;
  v30 = 4;
  do
  {
    v33 = *(int *)((char *)dword_7211B0 + v30);
    v32 = *(int *)((char *)dword_7211B0 + v31);
    if ( v33 == v32 )
      goto LABEL_51;
    if ( v32 > a3 + 5 )
    {
      if ( v33 >= v32 )
        goto LABEL_52;
LABEL_51:
      v29 = v51;
      v31 = v30;
      goto LABEL_52;
    }
    if ( v33 > v32 && v33 <= a3 + 5 )
      goto LABEL_51;
LABEL_52:
    ++v51;
    v30 += 4;
  }
  while ( v51 < v48 );
  if ( v29 )
  {
    *(_DWORD *)a6 = dword_721110[v29] | (dword_721160[v29] << 6);
    goto LABEL_56;
  }
LABEL_55:
  *(_DWORD *)a6 = 0;
LABEL_56:
  if ( v29 )
  {
    v34 = *(_DWORD *)(188 * dword_721160[v29] + pClass51_global->pBModels + 84) + 308 * dword_721110[v29];
    *(_DWORD *)a5 = 0;
    if ( *(_BYTE *)(v34 + 28) & 0x10 )
      *(_DWORD *)a5 = 1;
  }
  v35 = dword_7211B0[v29];
  result = dword_7211B0[0];
  if ( v35 >= dword_7211B0[0] )
    result = v35;
  return result;
}

//----- (004065B0) --------------------------------------------------------
__int16 __thiscall sub_4065B0(int this)
{
  signed int v1; // eax@1
  int v2; // esi@1
  int v3; // ebx@6
  int v4; // edi@7
  int i; // edi@14

  v2 = this;
  LOWORD(v1) = sub_404544(this);
  if ( *(_DWORD *)(v2 + 36) <= 0
    || ((sub_4063A1(v2), v1 = *(_DWORD *)(v2 + 32), (*(_BYTE *)(v2 + 32) & 7) != 4) ? (uMaybeSelectedCharacter = 0) : (v1 = (v1 >> 3) + 1, uMaybeSelectedCharacter = v1),
        dword_57702C = 1,
        *(_DWORD *)(v2 + 36) <= 0) )
  {
    v3 = 0;
    if ( *(_DWORD *)(v2 + 12) > 0 )
    {
      v4 = v2 + 32;
      do
      {
        v1 = *(_DWORD *)v4;
        if ( (*(_BYTE *)v4 & 7) == 4 )
          break;
        if ( *(_DWORD *)(v4 + 4) > 0 )
          break;
        if ( *(_DWORD *)(v4 + 8) <= 0 )
        {
          LOWORD(v1) = v1 & 3;
          if ( (_BYTE)v1 == 3 )
            LOWORD(v1) = sub_40680F((void *)v2, v3);
        }
        ++v3;
        v4 += 16;
      }
      while ( v3 < *(_DWORD *)(v2 + 12) );
    }
  }
  for ( i = 0; i < *(_DWORD *)(v2 + 12); ++i )
    LOWORD(v1) = sub_406648((void *)v2, i);
  return v1;
}

//----- (00406648) --------------------------------------------------------
__int16 __thiscall sub_406648(void *this, int a2)
{
  signed int v2; // eax@1
  int v3; // ecx@1
  int v4; // ebx@2
  char *v5; // esi@2
  int v6; // edi@5
  int v7; // eax@6
  int v8; // ecx@6
  int v9; // eax@7
  int v10; // eax@8
  int v11; // eax@9
  int v12; // eax@10
  int v13; // eax@11
  int v14; // eax@14
  signed int v15; // edx@14
  int v16; // ecx@14
  signed int v17; // eax@17
  int v18; // eax@20
  char v19; // al@24
  int v21; // [sp-8h] [bp-50h]@16
  int v22; // [sp-8h] [bp-50h]@17
  char *v23; // [sp-4h] [bp-4Ch]@14
  int v24; // [sp-4h] [bp-4Ch]@17
  char v25; // [sp-4h] [bp-4Ch]@20
  char v26; // [sp+Ch] [bp-3Ch]@2
  char v27; // [sp+28h] [bp-20h]@2
  __int16 *v28; // [sp+44h] [bp-4h]@1
  signed int v29; // [sp+50h] [bp+8h]@2

  v3 = (int)((char *)this + 16 * (a2 + 2));
  v28 = (__int16 *)v3;
  v2 = *(_DWORD *)v3;
  if ( (*(_BYTE *)v3 & 7) != 4 )
  {
    v2 >>= 3;
    v4 = v2;
    v29 = dword_4F6E08[v2];
    memcpy(&v26, sub_4040E9(*(_DWORD *)v3, dword_4F6E08[v2], &v26, 0), 0x1Cu);
    memcpy(&v27, &v26, 0x1Cu);
    v5 = (char *)pActors + 836 * v2;
    LOWORD(v2) = *((_WORD *)v5 + 88);
    if ( (_WORD)v2 != 5 )
    {
      if ( (_WORD)v2 != 19 )
      {
        if ( (_WORD)v2 != 11 )
        {
          v6 = *((_WORD *)v5 + 80);
          //*((_DWORD *)v5 + 46) += pClass24_global->dword_00001C;
          *((_DWORD *)v5 + 46) += pClass24_global->dword_00001C;
          if ( *((_DWORD *)v5 + 46) >= v6 )
          {
            v8 = (signed __int16)v2;
            v7 = (signed __int16)v2 - 2;
            if ( !v7 )
            {
              v19 = sub_42704B((int)((char *)pActors + 836 * v4), v4);
              sub_40261D(
                &dword_50FE08,
                *(_DWORD *)v28,
                5120,
                *((_WORD *)v5 + 71),
                *((_WORD *)v5 + 72),
                *((_WORD *)v5 + 73) + ((signed int)*((_WORD *)v5 + 69) >> 1),
                v19,
                1);
              goto LABEL_25;
            }
            v9 = v7 - 1;
            if ( v9 )
            {
              v10 = v9 - 1;
              if ( !v10 )
                goto LABEL_21;
              v11 = v10 - 4;
              if ( !v11 )
              {
LABEL_25:
                v15 = v29;
                v23 = &v27;
                v21 = 0;
                v16 = v4;
                goto LABEL_26;
              }
              v12 = v11 - 4;
              if ( v12 )
              {
                v13 = v12 - 1;
                if ( v13 )
                {
                  if ( v13 != 5 )
                  {
                    if ( v8 != 4 )
                    {
                      v14 = rand();
                      v16 = v4;
                      v23 = &v27;
                      v15 = v29;
                      if ( !(v14 % 2) )
                      {
                        LOWORD(v2) = sub_402F87(v4, v29, (signed int)&v27);
                        return v2;
                      }
                      v21 = 64;
LABEL_26:
                      LOWORD(v2) = sub_403EB6(v16, v15, v21, v23);
                      return v2;
                    }
LABEL_21:
                    *((_DWORD *)v5 + 46) = 0;
                    *((_WORD *)v5 + 80) = 0;
                    *((_WORD *)v5 + 88) = 5;
                    LOWORD(v2) = sub_45976D((int)((char *)pActors + 836 * v4));
                    return v2;
                  }
                  v24 = *((_WORD *)v5 + 51);
                  v22 = 3;
                  v17 = (unsigned __int8)v5[79];
                }
                else
                {
                  v24 = *((_WORD *)v5 + 50);
                  v22 = 2;
                  v17 = (unsigned __int8)v5[77];
                }
                sub_404AC7(v4, (int)&v27, v17, v22, v24);
                goto LABEL_25;
              }
              v18 = (unsigned __int8)v5[75];
              v25 = 1;
            }
            else
            {
              v18 = (unsigned __int8)v5[69];
              v25 = 0;
            }
            sub_404874(v4, (int)&v27, v18, v25);
            goto LABEL_25;
          }
        }
      }
    }
  }
  return v2;
}

//----- (0040680F) --------------------------------------------------------
__int16 __thiscall sub_40680F(void *this, int a2)
{
  signed int v2; // eax@1
  int v3; // eax@1
  int v4; // ebx@2
  int v5; // edi@2
  int v6; // ecx@10
  void *v7; // esi@10
  int v8; // eax@10
  signed int v9; // eax@13
  unsigned __int8 v10; // sf@19
  unsigned __int8 v11; // of@19
  bool v12; // eax@29
  int v13; // esi@29
  char v14; // cl@33
  char v16; // [sp+Ch] [bp-44h]@10
  int v17; // [sp+18h] [bp-38h]@10
  char v18; // [sp+28h] [bp-28h]@10
  int v19; // [sp+44h] [bp-Ch]@2
  int v20; // [sp+48h] [bp-8h]@10
  int v21; // [sp+4Ch] [bp-4h]@1
  int v22; // [sp+58h] [bp+8h]@10

  v3 = (int)((char *)this + 16 * (a2 + 2));
  v21 = v3;
  *(_DWORD *)(v3 + 8) = 0;
  v2 = *(_DWORD *)v3;
  if ( v2 & 3 )
  {
    v2 >>= 3;
    v5 = v2;
    v19 = v2;
    v4 = (int)((char *)pActors + 836 * v2);
    LOWORD(v2) = *(_WORD *)(v4 + 176);
    if ( (_WORD)v2 != 5 )
    {
      if ( (_WORD)v2 != 4 && (_WORD)v2 != 11 && (_WORD)v2 != 19 && (_WORD)v2 != 17 )
      {
        sub_401221(v5, 4 * v5 + 5205512, 1);
        if ( *(_BYTE *)(v4 + 61) )
        {
          if ( !dword_4F6E08[v5] )
            *(_BYTE *)(v4 + 61) = 0;
        }
        v22 = dword_4F6E08[v5];
        v7 = sub_4040E9(8 * v5 | 3, v22, &v16, 0);
        v8 = *(_WORD *)(v4 + 136);
        memcpy(&v16, v7, 0x1Cu);
        memcpy(&v18, &v16, 0x1Cu);
        v6 = v17 - v8;
        v20 = v17 - v8;
        if ( v17 - v8 < 0 )
        {
          v6 = 0;
          v20 = 0;
        }
        if ( (v22 & 7) == 3 )
          v9 = (unsigned __int8)*(&byte_5C8D1A[89 * (pMonsterStats->pMonsterInfos[word_5FF1B8[418 * (v22 >> 3)]].uID - 1) / 3]
                                + (*(_WORD *)(v4 + 96) - 1) / 3);
        else
          v9 = 4;
        if ( v9 == 1 )
        {
          if ( (double)v20 < *(double *)&byte_4D8410[32] )
            goto LABEL_25;
        }
        else
        {
          if ( v9 == 2 )
          {
            compile_error;//v11 = __SETO__(v6, 1024);
            v10 = v6 - 1024 < 0;
          }
          else
          {
            if ( v9 == 3 )
            {
              compile_error;//v11 = __SETO__(v6, 2560);
              v10 = v6 - 2560 < 0;
            }
            else
            {
              if ( v9 != 4 )
                goto LABEL_26;
              compile_error;//v11 = __SETO__(v6, 5120);
              v10 = v6 - 5120 < 0;
            }
          }
          if ( v10 ^ v11 )
          {
LABEL_25:
            *(_BYTE *)(v4 + 61) = 4;
            goto LABEL_26;
          }
        }
LABEL_26:
        if ( *(_BYTE *)(v4 + 61) != 4 || !v22 || v6 >= 5120 )
        {
          v13 = v19;
          goto LABEL_47;
        }
        v13 = v19;
        v12 = sub_42704B(v4, v19);
        if ( v12 == 1 )
        {
          if ( *(_BYTE *)(v4 + 75) )
          {
            sub_40368B(v13, v22, (signed int)&v18);
            goto LABEL_43;
          }
        }
        else
        {
          if ( v12 > 1 && v12 <= 3 )
          {
            if ( v12 == 2 )
              v14 = *(_BYTE *)(v4 + 77);
            else
              v14 = *(_BYTE *)(v4 + 79);
            if ( v14 )
            {
              if ( v12 == 2 )
                sub_403854(v13, v22, (signed int)&v18);
              else
                sub_403A60(v13, v22, (signed int)&v18);
              goto LABEL_43;
            }
            goto LABEL_44;
          }
          if ( *(_BYTE *)(v4 + 69) )
          {
            sub_403476(v13, v22, (signed int)&v18);
LABEL_43:
            v2 = v21;
            *(_DWORD *)(v21 + 12) = 1;
LABEL_48:
            *(_DWORD *)(v2 + 8) = *(_WORD *)(v4 + 160);
            return v2;
          }
        }
LABEL_44:
        if ( (double)v20 < *(double *)&byte_4D8410[32] )
        {
          sub_403C6C(v13, v22, &v18);
          v2 = v21;
          *(_DWORD *)(v21 + 12) = 3;
          goto LABEL_48;
        }
LABEL_47:
        sub_403EB6(v13, v22, 64, &v18);
        v2 = v21;
        *(_DWORD *)(v21 + 12) = 0;
        goto LABEL_48;
      }
    }
  }
  return v2;
}

//----- (00406A63) --------------------------------------------------------
void __thiscall sub_406A63(int this)
{
  int v1; // ebx@1
  signed int v2; // esi@1
  unsigned __int8 v3; // zf@1
  unsigned __int8 v4; // sf@1
  signed int v5; // ecx@4
  char v6; // [sp+8h] [bp-44h]@5
  char v7; // [sp+24h] [bp-28h]@5
  int v8; // [sp+40h] [bp-Ch]@5
  int v9; // [sp+44h] [bp-8h]@1
  signed int *v10; // [sp+48h] [bp-4h]@2

  v1 = this;
  v2 = 0;
  *(_DWORD *)(this + 8) = 64;
  dword_50C994 = 0;
  uMaybeSelectedCharacter = 0;
  v3 = *(_DWORD *)(this + 12) == 0;
  v4 = *(_DWORD *)(this + 12) < 0;
  v9 = 0;
  if ( !(v4 | v3) )
  {
    v10 = (signed int *)(this + 32);
    while ( 1 )
    {
      v5 = *v10;
      if ( (*(_BYTE *)v10 & 7) == 3 )
      {
        v8 = dword_4F6E08[v5 >> 3];
        memcpy(&v7, sub_4040E9(v5, v8, &v6, v2), 0x1Cu);
        if ( !sub_406D10((void *)v1, v9) )
          sub_403EB6(*v10 >> 3, v8, 32, &v7);
      }
      ++v9;
      v10 += 4;
      if ( v9 >= *(_DWORD *)(v1 + 12) )
        break;
      v2 = 0;
    }
  }
}

//----- (00406AFE) --------------------------------------------------------
void __thiscall sub_406AFE(int this)
{
  int v1; // edi@1
  int v2; // ebx@2
  int v3; // esi@4
  signed int v4; // ecx@5
  char v5; // [sp+4h] [bp-48h]@5
  char v6; // [sp+20h] [bp-2Ch]@5
  int v7; // [sp+3Ch] [bp-10h]@1
  int v8; // [sp+40h] [bp-Ch]@4
  int v9; // [sp+44h] [bp-8h]@5
  int v10; // [sp+48h] [bp-4h]@1

  v10 = 0;
  v1 = this;
  v7 = this;
  if ( *(_DWORD *)(this + 12) > 0 )
  {
    v2 = this + 32;
    do
    {
      if ( (*(_BYTE *)v2 & 7) == 3 )
      {
        v3 = *(_DWORD *)v2 >> 3;
        v8 = v3;
        if ( sub_40894B((int)((char *)pActors + 836 * v3)) )
        {
          v4 = *(_DWORD *)v2;
          v9 = dword_4F6E08[v3];
          memcpy(&v6, sub_4040E9(v4, v9, &v5, 0), 0x1Cu);
          sub_403EB6(v8, v9, 32, &v6);
          *(_DWORD *)(v2 + 12) = 0;
          *(_DWORD *)(v2 + 8) = 0;
          v1 = v7;
        }
      }
      ++v10;
      v2 += 16;
    }
    while ( v10 < *(_DWORD *)(v1 + 12) );
  }
  *(_DWORD *)(v1 + 4) = 2;
  *(_DWORD *)(v1 + 8) = 100;
}

//----- (0045E03A) --------------------------------------------------------
int __fastcall sub_45E03A(signed int a1, signed int a2)
{
  void *v2; // ebx@1
  signed int v3; // edi@1
  int v4; // edx@7
  int j; // ecx@9
  int v6; // edi@9
  unsigned __int8 v7; // cf@9
  unsigned int v8; // ecx@9
  int v9; // ecx@15
  int v10; // edi@15
  int v11; // esi@15
  signed __int64 v12; // qax@18
  int v13; // ST10_4@21
  int v14; // eax@21
  int v15; // edi@29
  signed __int64 v16; // qax@30
  signed int v17; // edx@34
  int k; // ecx@36
  unsigned int v19; // edi@36
  int Dst; // [sp+4h] [bp-A0h]@6
  int v22; // [sp+14h] [bp-90h]@15
  int v23; // [sp+28h] [bp-7Ch]@15
  void *v24; // [sp+80h] [bp-24h]@1
  float v25; // [sp+84h] [bp-20h]@1
  int v26; // [sp+88h] [bp-1Ch]@21
  float v27; // [sp+8Ch] [bp-18h]@1
  int v28; // [sp+90h] [bp-14h]@17
  int v29; // [sp+94h] [bp-10h]@1
  int v30; // [sp+98h] [bp-Ch]@16
  int i; // [sp+9Ch] [bp-8h]@15
  unsigned int v32; // [sp+A0h] [bp-4h]@1

  v32 = a1;
  v3 = a2;
  v29 = a2;
  v25 = 452.0 / (double)a1;
  v27 = 336.0 / (double)a2;
  v24 = malloc(a1 * a2 * 2);//v24 = operator new(2 * a2 * a1);
  v2 = v24;
  if ( pD3DRenderer->dword_040088 )
  {
    sub_4A1EB6(pD3DRenderer);
    if ( dword_6BE360 == 1 )
    {
      sub_441BD4();
    }
    else
    {
      if ( dword_6BE360 == 2 )
        sub_441CFF();
    }
    CD3DRenderer_sub_4A1FE1_MaybeRenderSpecialEffects(pD3DRenderer);
    memset(&Dst, 0, 0x7Cu);
    Dst = 124;
    if ( LockSurface_DDraw4(pD3DRenderer->pdds4_BackBuffer, &Dst, 1) )
    {
      v10 = v23;
      v9 = 0;
      v11 = v22 >> 1;
      for ( i = 0; i < v29; ++i )
      {
        v30 = v9;
        if ( (signed int)v32 > v9 )
        {
          v28 = v11 * (signed __int64)((double)i * v27 + 8.0);
          do
          {
            v12 = (signed __int64)((double)v30++ * v25 + 8.0);
            *(_WORD *)v2 = *(_WORD *)(v10 + 2 * (v28 + v12));
            v2 = (char *)v2 + 2;
          }
          while ( v30 < (signed int)v32 );
          v9 = 0;
        }
      }
      v13 = v9;
      v14 = (*(int (__stdcall **)(int, int))(*(_DWORD *)pD3DRenderer->pdds4_BackBuffer + 128))(pD3DRenderer->pdds4_BackBuffer, v9);
      CheckHRESULT(&v26, v14, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", 0x92u, v13);
    }
    else
    {
      v4 = v29;
      if ( v29 > 0 )
      {
        do
        {
          if ( (signed int)v32 > 0 )
          {
            v7 = v32 & 1;
            v8 = v32 >> 1;
            memset(v2, 0, 4 * (v32 >> 1));
            v6 = (int)((char *)v2 + 4 * v8);
            for ( j = 2 * v7; j; --j )
            {
              *(_WORD *)v6 = 0;
              v6 += 2;
            }
            v2 = (char *)v2 + 2 * v32;
          }
          --v4;
        }
        while ( v4 );
      }
    }
  }
  else
  {
    CD3DRenderer_BeginScene(pD3DRenderer);
    if ( dword_6BE360 == 1 )
    {
      sub_441BD4();
    }
    else
    {
      if ( dword_6BE360 == 2 )
        sub_441CFF();
   } 
    v26 = pD3DRenderer->pTargetSurface;
    v28 = pD3DRenderer->uTargetSurfacePitch;
    if (pD3DRenderer->pTargetSurface)
    {
      i = 0;
      if ( v3 > 0 )
      {
        do
        {
          v30 = 0;
          if ( (signed int)v32 > 0 )
          {
            v15 = v28 * (signed __int64)((double)i * v27 + 8.0);
            do
            {
              v16 = (signed __int64)((double)v30++ * v25 + 8.0);
              *(_WORD *)v2 = *(_WORD *)(v26 + 2 * (v15 + v16));
              v2 = (char *)v2 + 2;
            }
            while ( v30 < (signed int)v32 );
          }
          ++i;
        }
        while ( i < v29 );
      }
    }
    else
    {
      if ( v3 > 0 )
      {
        v17 = v3;
        do
        {
          if ( (signed int)v32 > 0 )
          {
            memset(v2, 0, 4 * (v32 >> 1));
            v19 = (unsigned int)((char *)v2 + 4 * (v32 >> 1));
            for ( k = 2 * (v32 & 1); k; --k )
            {
              *(_WORD *)v19 = 0;
              v19 += 2;
            }
            v2 = (char *)v2 + 2 * v32;
          }
          --v17;
        }
        while ( v17 );
      }
    }
    CD3DRenderer_EndScene(pD3DRenderer);
  }
  return (int)v24;
}

//----- (00494035) --------------------------------------------------------
int __cdecl sub_494035()
{
  signed __int64 v0; // qax@1
  unsigned int v1; // edi@1
  int v2; // eax@4
  _UNKNOWN *v3; // ecx@5
  char *v4; // esi@8
  signed int v5; // ecx@12
  int v6; // esi@15
  void *v7; // esi@25
  unsigned int v8; // ecx@27
  signed int v9; // edi@29
  int v10; // ecx@30
  int v11; // esi@35
  double v12; // st7@35
  int v14; // edi@46
  double v15; // st7@46
  float v16; // ST28_4@50
  double v17; // ST38_8@50
  struct Player *v18; // esi@53
  signed int v19; // edi@55
  int v20; // eax@61
  int v21; // ecx@62
  int v22; // eax@65
  int v23; // ecx@66
  int v24; // eax@69
  int v25; // ecx@70
  int v26; // eax@73
  int v27; // ecx@74
  int v28; // eax@77
  int v29; // ecx@78
  int v30; // eax@81
  int v31; // ecx@82
  int v32; // eax@85
  int v33; // ecx@86
  int v34; // eax@89
  int v35; // ecx@90
  int v36; // eax@93
  int v37; // ecx@94
  int v38; // eax@97
  int v39; // ecx@98
  bool v40; // ebx@104
  int v47; // esi@124
  signed int v48; // edx@130
  signed int v49; // ecx@132
  int v50; // eax@133
  int result; // eax@141
  int v52; // [sp-8h] [bp-38h]@18
  int v53; // [sp-8h] [bp-38h]@57
  int v54; // [sp-4h] [bp-34h]@18
  int v55; // [sp-4h] [bp-34h]@33
  int v56; // [sp-4h] [bp-34h]@57
  signed int v57; // [sp+10h] [bp-20h]@1
  unsigned int v58; // [sp+14h] [bp-1Ch]@1
  signed int v60; // [sp+18h] [bp-18h]@1
  signed int v61; // [sp+18h] [bp-18h]@49
  signed int v62; // [sp+1Ch] [bp-14h]@49
 int i, j;

  v60 = pParty_global->dword_00071C;
  v58 = pParty_global->dword_000718;
  v57 = pClass24_global->dword_00001C;
  pParty_global->qword_00002C += pClass24_global->dword_00001C;
  v0 = (signed __int64)((double)pParty_global->qword_00002C * 0.234375) / 60;
  v1 = (unsigned int)(v0 / 60) / 0x18 / 0x1C;
  dword_ACD6DC = (signed __int64)((double)pParty_global->qword_00002C * 0.234375) % 60;
  pParty_global->dword_000720 = v0 % 60;
  dword_ACD6CC = (unsigned int)(v0 / 60) / 0x18 / 7 & 3;
  pParty_global->dword_00071C = v0 / 60 % 24;
  pParty_global->dword_000718 = (unsigned int)(v0 / 60) / 0x18 % 0x1C;
  dword_ACD6C8 = v1 % 0xC;
  dword_ACD6C4 = v1 / 0xC + 1168;
  if ( (unsigned int)pParty_global->dword_00071C >= 3 && (v60 < 3 || (unsigned int)(v0 / 60) / 0x18 % 0x1C > v58) )
  {
    v2 = 0;
    dword_AD46B8 = 0;
    dword_AD4704 = 0;
    if ( dword_73C194 > 0 )
    {
      v3 = &unk_72D6D0;
      do
      {
        *(_DWORD *)v3 = 0;
        ++v2;
        v3 = (char *)v3 + 76;
      }
      while ( v2 < dword_73C194 );
    }
    ++byte_ACD71C;
    if ( (unsigned __int8)byte_ACD71C > 1u )
    {
      v4 = &pParty_global->pPlayers;
      do
      {
        Player_sub_492D65(v4, 1, 0);
        v4 += 6972;
      }
      while ( (signed int)v4 < (signed int)&dword_AD4674 );
      if ( pParty_global->uNumFood )
      {
        sub_492B03((void *)1);
      }
      else
      {
        v5 = (signed int)dword_ACF2C0;
        do
        {
          *(_DWORD *)v5 = *(_DWORD *)v5 / ((unsigned __int8)byte_ACD71C + 1) + 1;
          v5 += 6972;
        }
        while ( v5 < (signed int)&unk_AD5FB0 );
      }
      if ( (unsigned __int8)byte_ACD71C > 3u )
      {
        v6 = (int)&pParty_global->pPlayers[0];
        do
        {
          sub_49070F(v6);
          if ( !(*(_QWORD *)(v6 + 120) | *(_QWORD *)(v6 + 128) | *(_QWORD *)(v6 + 112)) )
          {
            if ( rand() % 100 < 5 * (unsigned __int8)byte_ACD71C )
            {
              v54 = 0;
              v52 = 14;
LABEL_21:
              Player_sub_492D65((char *)v6, v52, v54);
              goto LABEL_22;
            }
            if ( rand() % 100 < 10 * (unsigned __int8)byte_ACD71C )
            {
              v54 = 0;
              v52 = 5;
              goto LABEL_21;
            }
          }
LABEL_22:
          v6 += 6972;
        }
        while ( v6 < (signed int)&dword_AD4674 );
      }
    }
    if ( dword_6BE360 == 2 )
      sub_489487();
    v7 = &unk_ACF4BC;
    do
    {
      memset(v7, 0, 4u);
      v7 = (char *)v7 + 6972;
    }
    while ( (signed int)v7 < (signed int)&unk_AD61AC );
  }
  v8 = pParty_global->qword_00002C;
  if ( pParty_global->dword_007778 & 4 && dword_ACD6B4 < pParty_global->qword_00002C )
  {
    v9 = 1;
    dword_ACD6B4 = pParty_global->qword_00002C + 128;
    dword_57702C = 1;
    while ( 1 )
    {
      if ( sub_48D709(*(&ptr_A750C4 + v9), 516, 3) || sub_48D6D0((void *)v10, 71) || *(_QWORD *)(v10 + 6416) > 0i64 )
      {
        v55 = 0;
      }
      else
      {
        v55 = 0;
        if ( !sub_43EE77(v9) )
        {
          v11 = (int)*(&ptr_A750C4 + v9);
          v12 = (double)sub_48E4F8((int)*(&ptr_A750C4 + v9)) * *(double *)&byte_4D8410[112];
          sub_48DC1E(v11, (signed __int64)v12, 0);
          if ( pParty_global->dword_007778 & 4 )
          {
            strcpy(&byte_5C3428, pGlobalTXT_LocalizationStrings[660]);
            dword_5C35B8 = 128;
          }
          goto LABEL_39;
        }
        v10 = (int)*(&ptr_A750C4 + v9);
      }
      sub_494A25(v10, 37, v55);
LABEL_39:
      ++v9;
      if ( v9 > 4 )
      {
        v8 = pParty_global->qword_00002C;
        break;
      }
    }
  }
  if ( pParty_global->dword_007778 & 0x200 )
  {
    if ( (signed int)((unsigned __int64)dword_ACD6B4 >> 32) <= HIDWORD(pParty_global->qword_00002C) )
    {
      if ( (signed int)((unsigned __int64)dword_ACD6B4 >> 32) < HIDWORD(pParty_global->qword_00002C) || dword_ACD6B4 < v8 )
      {
        dword_57702C = 1;
        dword_ACD6B4 = v8 + 128;
        for (i = 0; i < 4; ++i)
        {
          v14 = pPlayers[i];
          v15 = (double)sub_48E4F8(pPlayers[i]) * *(double *)&byte_4D8410[112];
          sub_48DC1E(v14, (signed __int64)v15, 0);
          if ( pParty_global->dword_007778 & 0x200 )
          {
            strcpy(&byte_5C3428, pGlobalTXT_LocalizationStrings[661]);
            dword_5C35B8 = 128;
          }
        }
      }
    }
  }
  sub_493938();
  v62 = 4;
  v61 = v57;
  if ( dword_ACD83C & 2 )
  {
    v16 = (double)v57 * 0.5;
    v17 = v16 + 6.755399441055744e15;
    v61 = LODWORD(v17);
    if ( LODWORD(v17) <= 0 )
      v61 = 1;
  }

  for (i = 0; i < 4; ++i)
  {
   v18 = pPlayers[i];

    if (pPlayers[i]->word_001934)
      Player_sub_48E8F5(pPlayers[i], v61);

    v19 = v18->dword_00193C;
    if ( sub_48EAAE(pPlayers[i], 3, 0) + v18->dword_00193C + v18->uEndurance >= 1 ||
        *(_QWORD *)(v18 + 6224) > 0i64 )
    {
      if ( v19 >= 1 )
        goto LABEL_61;
      v56 = 0;
      v53 = 13;
    }
    else
    {
      v56 = 0;
      v53 = 14;
    }
    Player_sub_492D65(pPlayers[i], v53, v56);

LABEL_61:
    v20 = &v18->dword_0000E0;
    if (v18->dword_0000E0 )
    {
      v21 = *(_DWORD *)v20 - v57;
      if ( v21 > 0 )
      {
        *(_DWORD *)v20 = v21;
      }
      else
      {
        *(_DWORD *)v20 = 0;
        dword_57702C = 1;
      }
    }
    v22 = &v18->dword_0000E4;
    if (v18->dword_0000E4 )
    {
      v23 = *(_DWORD *)v22 - v57;
      if ( v23 > 0 )
      {
        *(_DWORD *)v22 = v23;
      }
      else
      {
        *(_DWORD *)v22 = 0;
        dword_57702C = 1;
      }
    }

    v24 = &v18->dword_0000E8;
    if (v18->dword_0000E8)
    {
      v25 = *(_DWORD *)v24 - v57;
      if ( v25 > 0 )
      {
        *(_DWORD *)v24 = v25;
      }
      else
      {
        *(_DWORD *)v24 = 0;
        dword_57702C = 1;
      }
    }

    v26 = &v18->dword_0000EC;
    if ( v18->dword_0000EC)
    {
      v27 = *(_DWORD *)v26 - v57;
      if ( v27 > 0 )
      {
        *(_DWORD *)v26 = v27;
      }
      else
      {
        *(_DWORD *)v26 = 0;
        dword_57702C = 1;
      }
    }

    v28 = &v18->dword_0000F0;
    if (v18->dword_0000F0)
    {
      v29 = *(_DWORD *)v28 - v57;
      if ( v29 > 0 )
      {
        *(_DWORD *)v28 = v29;
      }
      else
      {
        *(_DWORD *)v28 = 0;
        dword_57702C = 1;
      }
    }

    v30 = &v18->dword_0000F4;
    if (v18->dword_0000F4)
    {
      v31 = *(_DWORD *)v30 - v57;
      if ( v31 > 0 )
      {
        *(_DWORD *)v30 = v31;
      }
      else
      {
        *(_DWORD *)v30 = 0;
        dword_57702C = 1;
      }
    }

    v32 = &v18->dword_0000F8;
    if (v18->dword_0000F8)
    {
      v33 = *(_DWORD *)v32 - v57;
      if ( v33 > 0 )
      {
        *(_DWORD *)v32 = v33;
      }
      else
      {
        *(_DWORD *)v32 = 0;
        dword_57702C = 1;
      }
    }

    v34 = &v18->dword_0000FC;
    if (v18->dword_0000FC)
    {
      v35 = *(_DWORD *)v34 - v57;
      if ( v35 > 0 )
      {
        *(_DWORD *)v34 = v35;
      }
      else
      {
        *(_DWORD *)v34 = 0;
        dword_57702C = 1;
      }
    }

    v36 = &v18->dword_000100;
    if (v18->dword_000100)
    {
      v37 = *(_DWORD *)v36 - v57;
      if ( v37 > 0 )
      {
        *(_DWORD *)v36 = v37;
      }
      else
      {
        *(_DWORD *)v36 = 0;
        dword_57702C = 1;
      }
    }

    v38 = &v18->dword_000104;
    if (v18->dword_000104)
    {
      v39 = *(_DWORD *)v38 - v57;
      if ( v39 > 0 )
      {
        *(_DWORD *)v38 = v39;
      }
      else
      {
        *(_DWORD *)v38 = 0;
        dword_57702C = 1;
      }
    }

    if ( *(_QWORD *)(v18 + 16) | *(_QWORD *)(v18 + 96) | *(_QWORD *)(v18 + 104) | *(_QWORD *)(v18 + 112) | *(_QWORD *)(v18 + 120) | *(_QWORD *)(v18 + 128) )
      --v62;
    v40 = *(_QWORD *)((char *)v18 + 6160) > 0i64;

    for (j = 0; j < 24; ++j)
    {
      sub_4585CA(v18->array_0017A0[j], pParty_global->qword_00002C, SHIDWORD(pParty_global->qword_00002C));
    }

    if ( v40 )
    {
      if ( *(_QWORD *)(v18 + 6160) <= 0i64 )
        Player_sub_492D65((char *)v18, 1, 0);
    }
  }



  for (i = 0; i < 20; ++i)
  {
    if ( sub_4585CA(pParty_global->array_00088C[i], pParty_global->qword_00002C, SHIDWORD(pParty_global->qword_00002C)) == 1 )
      dword_57702C = 1;
  }

  if ( qword_ACD8C4 > 0 )
  {
    if ( qword_ACD8C4 <= 0 )
    {
     for (i = 0; i < 4; ++i)
       Player_sub_492D65(pPlayers[i], 1, 0);
    }
  }

  i = 0;
  //v46 = (signed int)&unk_4EE07C;
  for (i = 0; i < 2; ++i)
  {
    //v47 = (int)&dword_ACD844[4 * *(_DWORD *)v46];
   v47 = pParty_global->array_00088C[array_4EE07C[i]];
    if ( *(_QWORD *)v47 > 0i64 )
    {
      if ( !(*(_BYTE *)(v47 + 15) & 1) )
      {
        if ( !sub_492C0B((int)*(&ptr_A750C4 + *(_BYTE *)(v47 + 14))) )
        {
          sub_458585(v47);
          if (array_4EE07C[i] == 7 )
            dword_ACD6BC = 0;
        }
      }
    }
    //v46 += 4;
  }
  //while ( v46 < (signed int)&unk_4EE084 );

  v48 = v62;
  if ( v62 )
    goto LABEL_137;
  if ( dword_4E28F8 != 5 )
  {
    v49 = (signed int)pPlayers;
    while ( 1 )
    {
      v50 = *(_DWORD *)v49;
      if ( *(_QWORD *)(*(_DWORD *)v49 + 16) )
        break;
      v49 += 4;
      if ( v49 > (signed int)&dword_A750D4 )
        goto LABEL_137;
    }
    *(_DWORD *)(v50 + 16) = 0;
    *(_DWORD *)(v50 + 20) = 0;
    v48 = 1;
LABEL_137:
    if ( dword_4E28F8 != 5 )
    {
      if ( !v48 || dword_5C35C0 )
        dword_6A0D48 = 8;
    }
  }

  result = uMaybeSelectedCharacter;
  if ( uMaybeSelectedCharacter )
  {
    if ( dword_4E28F8 != 5 )
    {
      result = pPlayers[uMaybeSelectedCharacter - 1];
      if ( *(_QWORD *)(result + 16)
        || *(_QWORD *)(result + 96)
        || *(_QWORD *)(result + 104)
        || *(_QWORD *)(result + 112)
        || *(_QWORD *)(result + 120)
        || *(_QWORD *)(result + 128) )
      {
        dword_57702C = 1;
        result = Party_sub_49370F(pParty_global);
        uMaybeSelectedCharacter = result;
      }
    }
  }
  return result;
}

//----- (00406B9F) --------------------------------------------------------
signed int __thiscall sub_406B9F(int this)
{
  signed int result; // eax@1
  unsigned __int8 v2; // zf@1
  unsigned __int8 v3; // sf@1
  signed int v4; // esi@4
  int v5; // ebx@5
  int v6; // esi@5
  __int16 v7; // cx@15
  char v8; // [sp+0h] [bp-50h]@15
  char v9; // [sp+1Ch] [bp-34h]@15
  int v10; // [sp+28h] [bp-28h]@17
  int v11; // [sp+38h] [bp-18h]@4
  int v12; // [sp+3Ch] [bp-14h]@1
  int v13; // [sp+40h] [bp-10h]@5
  int v14; // [sp+44h] [bp-Ch]@8
  signed int *v15; // [sp+48h] [bp-8h]@2
  int v16; // [sp+4Ch] [bp-4h]@1

  result = 0;
  v12 = this;
  v2 = *(_DWORD *)(this + 12) == 0;
  v3 = *(_DWORD *)(this + 12) < 0;
  v16 = 0;
  if ( !(v3 | v2) )
  {
    v15 = (signed int *)(this + 32);
    while ( 1 )
    {
      v4 = *v15;
      v11 = *v15;
      if ( (v11 & 7) != 4 )
      {
        v6 = v4 >> 3;
        v13 = v6;
        v5 = (int)((char *)pActors + 836 * v6);
        if ( *(_DWORD *)(v5 + 296) < result
          || *(_DWORD *)(v5 + 296) <= result && *(_DWORD *)(v5 + 292) <= (unsigned int)result )
          v14 = result;
        else
          v14 = 1;
        if ( *(_DWORD *)(v5 + 312) >= result )
        {
          if ( *(_DWORD *)(v5 + 312) > result || *(_DWORD *)(v5 + 308) > (unsigned int)result )
            result = 1;
        }
        if ( !(v14 | result | *(_WORD *)(v5 + 176) == 5 | *(_WORD *)(v5 + 176) == 11 | *(_WORD *)(v5 + 176) == 19) )
        {
          v14 = dword_4F6E08[v6];
          memcpy(&v9, sub_4040E9(v11, v14, &v8, 0), 0x1Cu);
          v7 = *(_WORD *)(v5 + 176);
          if ( (v7 == 6 || v7 == 1) && (double)v10 < *(double *)&byte_4D8410[32] )
            goto LABEL_26;
          //*(_DWORD *)(v5 + 184) += pClass24_global->dword_00001C;
          *(_DWORD *)(v5 + 184) += pClass24_global->dword_00001C;
          if ( *(_DWORD *)(v5 + 184) > (signed int)*(_WORD *)(v5 + 160) )
          {
            if ( v7 == 4 )
            {
              *(_DWORD *)(v5 + 184) = 0;
              *(_WORD *)(v5 + 160) = 0;
              *(_WORD *)(v5 + 176) = 5;
              sub_45976D(v5);
            }
            if ( !sub_406D10((void *)v12, v16) )
LABEL_26:
              sub_403EB6(v13, v14, 32, &v9);
          }
        }
      }
      ++v16;
      result = v12;
      v15 += 4;
      if ( v16 >= *(_DWORD *)(v12 + 12) )
        break;
      result = 0;
    }
  }
  return result;
}

//----- (00448B45) --------------------------------------------------------
void __thiscall sub_448B45(void *this)
{
  if ( this || dword_5C35B8 && GetTickCount() >= dword_5C35B8 )
    dword_5C35B8 = 0;
}

//----- (00406D10) --------------------------------------------------------
signed int __thiscall sub_406D10(void *this, int a2)
{
  signed int v2; // ecx@1
  __int16 v3; // dx@2
  int v4; // ecx@2
  char *v5; // ebx@2
  signed int *v6; // edi@7
  int v7; // esi@7
  int v8; // eax@7
  int v9; // ecx@10
  void *v10; // esi@10
  int v11; // eax@10
  char v12; // al@12
  unsigned __int8 v13; // sf@16
  unsigned __int8 v14; // of@16
  int v15; // edx@22
  int v16; // ecx@23
  int v17; // eax@25
  double v18; // st6@33
  double v19; // st7@33
  int v21; // [sp-8h] [bp-5Ch]@23
  int v22; // [sp-8h] [bp-5Ch]@26
  char *v23; // [sp-4h] [bp-58h]@23
  int v24; // [sp-4h] [bp-58h]@26
  char v25; // [sp+Ch] [bp-48h]@10
  int v26; // [sp+18h] [bp-3Ch]@10
  char v27; // [sp+28h] [bp-2Ch]@10
  int v28; // [sp+44h] [bp-10h]@33
  int v29; // [sp+48h] [bp-Ch]@10
  int *v30; // [sp+4Ch] [bp-8h]@7
  int v31; // [sp+50h] [bp-4h]@2
  signed int v32; // [sp+5Ch] [bp+8h]@7

  v2 = *((_DWORD *)this + 4 * (a2 + 2));
  if ( (v2 & 7) == 4 )
    return 0;
  v4 = v2 >> 3;
  v31 = v4;
  v5 = (char *)pActors + 836 * v4;
  v3 = *((_WORD *)v5 + 88);
  if ( v3 == 5 || v3 == 4 || v3 == 11 || v3 == 19 || v3 == 17 )
    return 1;
  v7 = 4 * v4 + 5205512;
  v6 = &dword_4F8878[4 * a2];
  v8 = dword_4F6E08[v4];
  v30 = &dword_4F8878[4 * a2];
  v32 = v8;
  sub_401221(v4, 4 * v4 + 5205512, 1);
  if ( v5[61] )
  {
    if ( !*(_DWORD *)v7 )
      v5[61] = 0;
  }
  v10 = sub_4040E9(*v6, v32, &v25, 0);
  v11 = *((_WORD *)v5 + 68);
  memcpy(&v25, v10, 0x1Cu);
  memcpy(&v27, &v25, 0x1Cu);
  v9 = v26 - v11;
  v29 = v26 - v11;
  if ( v26 - v11 < 0 )
  {
    v9 = 0;
    v29 = 0;
  }
  v12 = v5[61];
  if ( v12 == 1 )
  {
    if ( (double)v29 >= *(double *)&byte_4D8410[32] )
      goto LABEL_21;
LABEL_20:
    v5[61] = 4;
    goto LABEL_21;
  }
  if ( v12 == 2 )
  {
    compile_error;//v14 = __SETO__(v9, 1024);
    v13 = v9 - 1024 < 0;
  }
  else
  {
    if ( v12 != 3 )
      goto LABEL_21;
    compile_error;//v14 = __SETO__(v9, 2560);
    v13 = v9 - 2560 < 0;
  }
  if ( v13 ^ v14 )
    goto LABEL_20;
LABEL_21:
  if ( *(_QWORD *)(v5 + 276) > 0i64 )
  {
    v15 = v32;
    if ( v9 < 10240 )
    {
      v23 = &v27;
      v16 = v31;
      v21 = 0;
      goto LABEL_24;
    }
    v24 = 0;
    v22 = 1024;
    goto LABEL_58;
  }
  if ( v5[61] != 4 )
    goto LABEL_46;
  if ( !(v5[38] & 2) || v5[60] == 1 )
  {
    if ( (unsigned __int8)v5[60] == 1 )
      goto LABEL_36;
    if ( (unsigned __int8)v5[60] == 2 )
    {
      v28 = *((_WORD *)v5 + 20);
      v19 = (double)v28;
      v18 = (double)*((signed int *)v5 + 27) * *(double *)&byte_4D8410[104];
      goto LABEL_34;
    }
    if ( (unsigned __int8)v5[60] == 3 )
    {
      v28 = *((_WORD *)v5 + 20);
      v19 = (double)v28;
      v18 = (double)*((signed int *)v5 + 27) * *(double *)&byte_4D8410[112];
LABEL_34:
      if ( v18 > v19 && v9 < 10240 )
      {
LABEL_36:
        v16 = v31;
        v15 = v32;
        v23 = 0;
        v21 = 32;
        if ( v5[59] == 5 )
        {
          sub_403EB6(v31, v32, 32, 0);
          goto LABEL_25;
        }
LABEL_24:
        sub_402968(v16, v15, v21, v23);
LABEL_25:
        v17 = (int)v30;
        v30[3] = 4;
LABEL_60:
        *(_DWORD *)(v17 + 8) = *((_WORD *)v5 + 80);
        return 1;
      }
      goto LABEL_39;
    }
  }
LABEL_39:
  if ( (double)v29 < *(double *)&byte_4D8410[32] )
    return 0;
  if ( v9 < 5120 )
  {
    if ( v5[69] && v9 < 1024 )
      sub_402AD7(v31, v32, v31, 32, (signed int)&v27);
    else
      sub_40281C(v31, v32, 32, (signed int)&v27, 307);
    goto LABEL_59;
  }
LABEL_46:
  if ( !v5[59] )
  {
    v24 = 32;
    v22 = 1024;
    goto LABEL_57;
  }
  if ( (unsigned __int8)v5[59] == 1 )
  {
    v24 = 32;
    v22 = 2560;
    goto LABEL_57;
  }
  if ( (unsigned __int8)v5[59] == 2 )
  {
    v24 = 32;
    v22 = 5120;
LABEL_57:
    v15 = v32;
LABEL_58:
    sub_4032B2(v31, v15, v22, v24);
LABEL_59:
    v17 = (int)v30;
    v30[3] = 2;
    goto LABEL_60;
  }
  if ( (unsigned __int8)v5[59] == 4 )
  {
    sub_4032B2(v31, v32, 10240, 32);
    goto LABEL_53;
  }
  if ( (unsigned __int8)v5[59] == 5 )
  {
    sub_403EB6(v31, v32, 32, 0);
LABEL_53:
    v17 = (int)v30;
    v30[3] = 2;
    goto LABEL_60;
  }
  return 1;
}

//----- (004356B9) --------------------------------------------------------
void __thiscall sub_4356B9(int this, int a2, int a3, int a4)
{
  int v4; // edx@1
  int v5; // eax@2

  v4 = 0;
  if ( *(_DWORD *)this )
  {
    v5 = this + 4;
    *(_DWORD *)a2 = *(_DWORD *)(this + 4);
    *(_DWORD *)a3 = *(_DWORD *)(this + 8);
    *(_DWORD *)a4 = *(_DWORD *)(this + 12);
    if ( *(_DWORD *)this - 1 > 0 )
    {
      do
      {
        *(_DWORD *)v5 = *(_DWORD *)(v5 + 12);
        *(_DWORD *)(v5 + 4) = *(_DWORD *)(v5 + 16);
        *(_DWORD *)(v5 + 8) = *(_DWORD *)(v5 + 20);
        ++v4;
        v5 += 12;
      }
      while ( v4 < *(_DWORD *)this - 1 );
    }
    --*(_DWORD *)this;
  }
}

//----- (004BF794) --------------------------------------------------------
int __cdecl LoadMainMenu()
{
  signed int result; // eax@6
  //int v1; // eax@6
 float fVolume; // qax@8

  struct RGBTexture *pTitleScreen;//char v3; // [sp+Ch] [bp-30h]@1
  //unsigned int v4; // [sp+30h] [bp-Ch]@6
  int v5; // [sp+34h] [bp-8h]@8
  int v6; // [sp+38h] [bp-4h]@8

 pVideoPlayer->dword_00006C = 0;
 pVideoPlayer->dword_000040 = 0;
 dword_F8BC10 = 1;

 bSkipVideo = true;
 if (!bSkipVideo)
 {
  CD3DRenderer_ClearBackBufferAndPresent(pD3DRenderer);

  PlayMovie(1, 1);

  if (!pVideoPlayer->dword_00006C)
  {
   PlayMovie(2, 1);
   if (!pVideoPlayer->dword_00006C)
   {
    PlayMovie(3, 1);
    if (!pVideoPlayer->dword_00006C)
      PlayMovie(5, 1);
   }
  }
 }

 pTitleScreen = malloc(sizeof(struct RGBTexture));
 RGBTexture_ctor(pTitleScreen);
 RGBTexture_LoadFromCBM(pTitleScreen, L"mm7title");


 CD3DRenderer_BeginScene(pD3DRenderer);
 {
  CD3DRenderer_DrawRGBTexture(pD3DRenderer, 0, 0, pTitleScreen);

  LoadFontsAndSomeStuff();
  sub_415485();
 }

 CD3DRenderer_EndScene(pD3DRenderer);
 result = CD3DRenderer_Present(pD3DRenderer);

 if (!(dword_6BE364 & 0x10))
 {
  if (pAudioPlayer->hAILRedbook)
  {
   fVolume = aMusicVolumeLevels[byte_6BE371] * 64.0;
   AudioPlayer_SetVolume(pAudioPlayer, fVolume);
   AIL_redbook_stop(pAudioPlayer->hAILRedbook);
   AIL_redbook_track_info(pAudioPlayer->hAILRedbook, 14, &v5, &v6);
   result = AIL_redbook_play(pAudioPlayer->hAILRedbook, v5 + 1, v6);
  }
 }
 dword_F8BC10 = 0;
 return result;
}

//----- (00481E55) --------------------------------------------------------
void __fastcall sub_481E55(int a1)
{
  int v1; // eax@2
  int v2; // edx@2
  double v3; // st5@2
  double v4; // st6@2
  double v5; // st7@2
  double v6; // st4@3
  double v7; // st3@3

  runtime_warning;
  return;

  if ( a1 > 0 )
  {
    v5 = (double)pStruct9_global->dword_000014;
    v4 = (double)dword_F8BC3C;
    v3 = (double)dword_F8BC40;
    v1 = 0;
    v2 = a1;
    do
    {
      v6 = v5 * *(float *)(v1 + &unk_507D50);
      v7 = v6 * *(float *)(v1 + &unk_507D40);
      memcpy((char *)&unk_50AC10 + v1, (char *)&unk_507D30 + v1, 0x30u);
      *(float *)(v1 + &flt_50AC28) = v4 - v7;
      *(float *)(v1 + &flt_50AC2C) = v3 - v6 * *(float *)(v1 + &unk_507D44);
      v1 += 48;
      --v2;
    }
    while ( v2 );
  }
}

//----- (00406FA8) --------------------------------------------------------
void __thiscall sub_406FA8(int this)
{
  unsigned __int8 v1; // zf@1
  unsigned __int8 v2; // sf@1
  int v3; // edi@2
  int v4; // eax@4
  __int16 v5; // cx@4
  int v6; // ebx@4
  signed int v7; // esi@8
  unsigned __int8 v8; // sf@13
  unsigned __int8 v9; // of@13
  char v10; // [sp+Ch] [bp-6Ch]@8
  char v11; // [sp+28h] [bp-50h]@8
  char v12; // [sp+44h] [bp-34h]@8
  int v13; // [sp+60h] [bp-18h]@1
  int v14; // [sp+64h] [bp-14h]@2
  int v15; // [sp+68h] [bp-10h]@4
  int v16; // [sp+6Ch] [bp-Ch]@8
  int v17; // [sp+70h] [bp-8h]@1
  int v18; // [sp+74h] [bp-4h]@2

  v17 = 0;
  v1 = *(_DWORD *)(this + 12) == 0;
  v2 = *(_DWORD *)(this + 12) < 0;
  v13 = this;
  if ( !(v2 | v1) )
  {
    v3 = this + 32;
    v18 = (int)((char *)&unk_4F8858 - this);
    v14 = this + 32;
    do
    {
      if ( (*(_BYTE *)v3 & 7) != 4 )
      {
        v4 = *(_DWORD *)v3 >> 3;
        v15 = v4;
        v6 = (int)((char *)pActors + 836 * v4);
        v5 = *(_WORD *)(v6 + 176);
        if ( v5 != 5 )
        {
          if ( v5 != 11 )
          {
            if ( v5 != 19 )
            {
              if ( v5 != 17 )
              {
                v16 = dword_4F6E08[v4];
                v7 = v16;
                sub_401221(v4, 4 * v4 + 5205512, 1);
                memcpy(&v11, sub_4040E9(*(_DWORD *)(v18 + v3), v7, &v10, 0), 0x1Cu);
                memcpy(&v12, &v11, 0x1Cu);
                *(_DWORD *)(v6 + 184) += pClass24_global2->dword_00001C;
                if ( *(_DWORD *)(v6 + 184) >= (signed int)*(_WORD *)(v6 + 160) )
                {
                  if ( *(_WORD *)(v6 + 176) == 4 )
                  {
                    *(_DWORD *)(v6 + 184) = 0;
                    *(_WORD *)(v6 + 160) = 0;
                    *(_WORD *)(v6 + 176) = 5;
                    sub_45976D(v6);
                    return;
                  }
                  if ( rand() % 2 )
                    sub_403EB6(v15, v16, 64, &v12);
                  else
                    sub_402F87(v15, v16, (signed int)&v12);
                }
              }
            }
          }
        }
      }
      ++v17;
      v3 = v14 + 16;
      compile_error;//v9 = __SETO__(v17, *(_DWORD *)(v13 + 12));
      v8 = v17 - *(_DWORD *)(v13 + 12) < 0;
      v14 += 16;
    }
    while ( v8 ^ v9 );
  }
}

//----- (004070EF) --------------------------------------------------------
signed int __fastcall sub_4070EF(signed int a1, signed int a2)
{
  signed int v2; // eax@1
  int v3; // ecx@1
  signed int v4; // esi@1
  int v5; // ecx@2
  int v6; // eax@4
  int v7; // eax@4
  float v8; // ST24_4@5
  double v9; // ST18_8@5
  int v10; // eax@6
  int v11; // ecx@6
  signed int v12; // eax@7
  int v13; // esi@7
  int v14; // esi@8
  int v15; // esi@9
  int v16; // eax@11
  int v17; // edi@11
  int v18; // esi@11
  int v19; // eax@13
  float v20; // ST24_4@14
  double v21; // ST18_8@14
  int v22; // eax@15
  signed int v23; // ecx@16
  int v24; // ebx@16
  int v25; // eax@18
  int v26; // eax@28
  int v27; // edx@31
  int v28; // ecx@31
  int v29; // eax@32
  int v30; // ebx@32
  int v31; // esi@32
  int v32; // edi@44
  int v33; // ST50_4@44
  int v34; // ST54_4@44
  int v35; // eax@44
  char v36; // zf@44
  int v37; // eax@45
  signed int v38; // esi@45
  int v39; // ST4C_4@49
  signed __int64 v40; // qtt@50
  __int16 v42; // bx@58
  signed int v43; // [sp-8h] [bp-70h]@11
  int v44; // [sp-4h] [bp-6Ch]@11
  int v45; // [sp+Ch] [bp-5Ch]@32
  __int16 v46; // [sp+10h] [bp-58h]@32
  int v47; // [sp+18h] [bp-50h]@20
  int v48; // [sp+1Ch] [bp-4Ch]@20
  int v49; // [sp+20h] [bp-48h]@20
  int v50; // [sp+24h] [bp-44h]@16
  signed int v51; // [sp+24h] [bp-44h]@27
  signed int v52; // [sp+28h] [bp-40h]@26
  signed int v53; // [sp+2Ch] [bp-3Ch]@23
  signed int v54; // [sp+30h] [bp-38h]@22
  signed int v55; // [sp+34h] [bp-34h]@21
  signed int v56; // [sp+38h] [bp-30h]@20
  signed int v57; // [sp+3Ch] [bp-2Ch]@28
  int v58; // [sp+44h] [bp-24h]@50
  int v59; // [sp+48h] [bp-20h]@44
  int v60; // [sp+50h] [bp-18h]@11
  signed int v61; // [sp+50h] [bp-18h]@31
  int v62; // [sp+54h] [bp-14h]@16
  int v63; // [sp+58h] [bp-10h]@4
  signed int v64; // [sp+5Ch] [bp-Ch]@4
  int v65; // [sp+60h] [bp-8h]@4
  int v66; // [sp+64h] [bp-4h]@7

  v2 = a1 >> 3;
  v3 = (a1 & 7) - 2;
  v4 = a2;
  if ( v3 )
  {
    v5 = v3 - 1;
    if ( v5 )
    {
      if ( v5 != 2 )
        return 0;
      v7 = 32 * v2;
      v63 = array_6836D0[v2].dword_000004;
      v64 = array_6836D0[v2].dword_000008;
      v65 = array_6836D0[v2].dword_00000C;
      v6 = sub_49AC17((int)byte_6BE3C8, v63, v64, v65);
    }
    else
    {
      v63 = pActors[v2].word_00008E;
      v64 = pActors[v2].word_000090;
      v8 = (double)pActors[v2].word_00008A * 0.699999988079071;
      v9 = v8 + 6.755399441055744e15;
      v65 = LODWORD(v9) + pActors[v2].word_000092;
      v6 = word_5FF1F6[418 * v2];
    }
  }
  else
  {
    v10 = 112 * v2;
    v63 = array_665230[v2].dword_000004;
    v64 = array_665230[v2].dword_000008;
    v11 = array_665230[v2].dword_00000C;
    v6 = array_665230[v2].word_00001C;
    v65 = v11;
  }
  v66 = v6;
  v12 = v4 >> 3;
  v13 = (v4 & 7) - 2;
  if ( v13 )
  {
    v14 = v13 - 1;
    if ( v14 )
    {
      v15 = v14 - 1;
      if ( v15 )
      {
        if ( v15 != 1 )
          return 0;
        v16 = 32 * v12;
        v18 = array_6836D0[v12].dword_000004;
        v43 = v60 = array_6836D0[v12].dword_000008;
        v17 = v44 = array_6836D0[v12].dword_00000C;
      }
      else
      {
        v18 = pParty_global->dword_0006B4;
        v17 = pParty_global->dword_00000C + pParty_global->dword_0006BC;
        v60 = pParty_global->dword_0006B8;
        v44 = pParty_global->dword_00000C + pParty_global->dword_0006BC;
        v43 = pParty_global->dword_0006B8;
      }
      v19 = sub_49AC17((int)byte_6BE3C8, v18, v43, v44);
    }
    else
    {
      v60 = pActors[v12].word_000090;
      v18 = pActors[v12].word_00008E;
      v20 = (double)pActors[v12].word_00008A * 0.699999988079071;
      v21 = v20 + 6.755399441055744e15;
      v17 = LODWORD(v21) + pActors[v12].word_000092;
      v19 = word_5FF1F6[418 * v12];
    }
  }
  else
  {
    v22 = 112 * v12;
    v18 = array_665230[v12].dword_000004;
    v17 = array_665230[v12].dword_000008;
    v60 = array_665230[v12].dword_00000C;
    v19 = array_665230[v12].word_00001C;
  }
  v62 = v19;
  v24 = v18 - v63;
  v50 = v17 - v65;
  v23 = sub_452A9E(v24 * v24 + (v60 - v64) * (v60 - v64) + v50 * v50);
  if ( v23 > 5120 )
    return 0;
  if ( dword_6BE360 == 2 )
    return 1;
  v25 = 65536;
  if ( v23 )
    v25 = 65536 / v23;
  v49 = v24 * v25;
  v47 = v50 * v25;
  v48 = (v60 - v64) * v25;
  v56 = v63;
  if ( v63 < v18 )
  {
    v55 = v18;
  }
  else
  {
    v56 = v18;
    v55 = v63;
  }
  v54 = v64;
  if ( v64 < v60 )
  {
    v53 = v60;
  }
  else
  {
    v54 = v60;
    v53 = v64;
  }
  v52 = v65;
  if ( v65 < v17 )
  {
    v51 = v17;
  }
  else
  {
    v52 = v17;
    v51 = v65;
  }
  v57 = 0;
  v26 = v66;
  while ( 2 )
  {
    if ( v26 == v62 )
      return 1;
    if ( v57 >= 30 || (v27 = dword_6BE654, v28 = 116 * v66, v61 = 0, *(_WORD *)(116 * v66 + dword_6BE654 + 36) <= 0) )
      break;
    while ( 1 )
    {
      v30 = dword_6BE644 + 96 * *(_WORD *)(*(_DWORD *)(v28 + v27 + 40) + 2 * v61);
      v31 = dword_6BE63C + 6 * **(_WORD **)(v30 + 48);
      v45 = *(_DWORD *)v31;
      v46 = *(_WORD *)(v31 + 4);
      v29 = *(_DWORD *)(v30 + 24) * (v46 - v65)
          + *(_DWORD *)(v30 + 20) * (SHIWORD(v45) - v64)
          + *(_DWORD *)(v30 + 16) * ((signed __int16)v45 - v63);
      if ( v66 != *(_WORD *)(v30 + 76) )
        v29 = -v29;
      if ( v29 >= 0 && (signed __int16)v45 != v63 && SHIWORD(v45) != v64 && v46 != v65
        || v56 > *(_WORD *)(v30 + 82)
        || v55 < *(_WORD *)(v30 + 80)
        || v54 > *(_WORD *)(v30 + 86)
        || v53 < *(_WORD *)(v30 + 84)
        || v52 > *(_WORD *)(v30 + 90)
        || v51 < *(_WORD *)(v30 + 88) )
        goto LABEL_54;
      v33 = (unsigned __int64)(v49 * *(_DWORD *)(v30 + 16)) >> 16;
      v34 = (unsigned __int64)(v47 * *(_DWORD *)(v30 + 24)) >> 16;
      v35 = (unsigned __int64)(v48 * *(_DWORD *)(v30 + 20)) >> 16;
      v36 = v33 + v34 + v35 == 0;
      v32 = v33 + v34 + v35;
      v59 = v33 + v34 + v35;
      if ( v36 )
        goto LABEL_53;
      v37 = v65 * *(_DWORD *)(v30 + 24);
      v38 = -(*(_DWORD *)(v30 + 28) + v37 + v63 * *(_DWORD *)(v30 + 16) + v64 * *(_DWORD *)(v30 + 20));
      if ( v32 <= 0 )
        break;
      if ( *(_DWORD *)(v30 + 28) + v37 + v63 * *(_DWORD *)(v30 + 16) + v64 * *(_DWORD *)(v30 + 20) <= 0 )
        goto LABEL_49;
LABEL_53:
      v27 = dword_6BE654;
LABEL_54:
      ++v61;
      if ( v61 >= *(_WORD *)(v28 + v27 + 36) )
        goto LABEL_55;
    }
    if ( *(_DWORD *)(v30 + 28) + v37 + v63 * *(_DWORD *)(v30 + 16) + v64 * *(_DWORD *)(v30 + 20) < 0 )
      goto LABEL_53;
LABEL_49:
    v39 = abs(-(*(_DWORD *)(v30 + 28) + v37 + v63 * *(_DWORD *)(v30 + 16) + v64 * *(_DWORD *)(v30 + 20))) >> 14;
    if ( v39 > abs(v32)
      || (LODWORD(v40) = v38 << 16, HIDWORD(v40) = v38 >> 16, v58 = v40 / v59, (signed int)(v40 / v59) < 0)
      || !sub_4075DB(
            v63 + ((signed int)(((unsigned __int64)(v58 * v49) >> 16) + 32768) >> 16),
            v64 + ((signed int)(((unsigned __int64)(v58 * v48) >> 16) + 32768) >> 16),
            v65 + ((signed int)(((unsigned __int64)(v58 * v47) >> 16) + 32768) >> 16),
            v30) )
    {
      v28 = 116 * v66;
      goto LABEL_53;
    }
    if ( *(_WORD *)(v30 + 76) == v66 )
      v42 = *(_WORD *)(v30 + 78);
    else
      v42 = *(_WORD *)(v30 + 76);
    v26 = v42;
    if ( v42 != v66 )
    {
      ++v57;
      v66 = v42;
      continue;
    }
    break;
  }
LABEL_55:
  if ( v66 != v62 )
    return 0;
  return 1;
}

//----- (00466082) --------------------------------------------------------
int __cdecl sub_466082()
{
  unsigned int v1; // eax@18
  size_t v2; // eax@31
  size_t v3; // ebx@32
  size_t v4; // edi@36
  char String[32]; // [sp+84h] [bp-104h]@32
  CHAR Str[16]; // [sp+FCh] [bp-8Ch]@32
  //const CHAR FileName; // [sp+10Ch] [bp-7Ch]@1
  unsigned int v12; // [sp+184h] [bp-4h]@28
  char pCurrentDirectory[121];
  char pIniFile[132];

  GetCurrentDirectoryA(120, pCurrentDirectory);
  wsprintfA(pIniFile, "%s\\mm6.ini", pCurrentDirectory);
  dword_576FF8 = GetPrivateProfileIntA("screen", "vx1", 8, pIniFile);
  dword_576FFC = GetPrivateProfileIntA("screen", "vy1", 8, pIniFile);
  dword_577000 = GetPrivateProfileIntA("screen", "vx2", 468, pIniFile);
  dword_577004 = GetPrivateProfileIntA("screen", "vy2", 351, pIniFile);

  if (GetPrivateProfileIntA("settings", "nointro", 0, pIniFile))
    dword_6BE364 |= 4;
  if (GetPrivateProfileIntA("settings", "nologo", 0, pIniFile))
    dword_6BE364 |= 8;
  if (GetPrivateProfileIntA("settings", "nosound", 0, pIniFile))
    dword_6BE364 |= 16;
  if (GetPrivateProfileIntA("settings", "nowalksound", 0, pIniFile))
    dword_6BE364 |= 32;
  if (bUseRegistry)
    v1 = ReadWindowsRegistry("startinwindow", 0);
  else
    v1 = GetPrivateProfileIntA("debug", "startinwindow", 0, pIniFile);
  if ( v1 )
    dword_6BE368 |= 1;
  if ( GetPrivateProfileIntA("debug", "showFR", 0, pIniFile) )
    dword_6BE368 |= 2;
  if ( GetPrivateProfileIntA("debug", "nomonster", 0, pIniFile) )
    dword_6BE368 |= 4;
  if ( GetPrivateProfileIntA("debug", "nodecoration", 0, pIniFile) )
    dword_6BE368 |= 8;
  if ( GetPrivateProfileIntA("debug", "nodamage", 0, pIniFile) )
    dword_6BE368 |= 16;
  pParty_global->uWalkSpeed = GetPrivateProfileIntA("debug", "walkspeed", 384, pIniFile);
  GetPrivateProfileStringA("file", "startmap", "out01.odm", pStartMapName, 32, pIniFile);
  v12 = 0;
  if ( strlen(pStartMapName) )
  {
    do
    {
      if ( pStartMapName[v12] == 32 )
        pStartMapName[v12] = 0;
      ++v12;
      v2 = strlen(pStartMapName);
    }
    while ( v12 < v2 );
  }
  byte_6BE108 = GetPrivateProfileIntA("outdoor", "RGBDayTop.r", 81, pIniFile);
  byte_6BE109 = GetPrivateProfileIntA("outdoor", "RGBDayTop.g", 121, pIniFile);
  byte_6BE10A = GetPrivateProfileIntA("outdoor", "RGBDayTop.b", 236, pIniFile);
  byte_6BE10B = GetPrivateProfileIntA("outdoor", "RGBDayBottom.r", 153, pIniFile);
  byte_6BE10C = GetPrivateProfileIntA("outdoor", "RGBDayBottom.g", 193, pIniFile);
  byte_6BE10D = GetPrivateProfileIntA("outdoor", "RGBDayBottom.b", 237, pIniFile);
  byte_6BE10E = GetPrivateProfileIntA("outdoor", "RGBNightTop.r", 0, pIniFile);
  byte_6BE10F = GetPrivateProfileIntA("outdoor", "RGBNightTop.g", 0, pIniFile);
  byte_6BE110 = GetPrivateProfileIntA("outdoor", "RGBNightTop.b", 0, pIniFile);
  byte_6BE111 = GetPrivateProfileIntA("outdoor", "RGBNightBottom.r", 11, pIniFile);
  byte_6BE112 = GetPrivateProfileIntA("outdoor", "RGBNightBottom.g", 41, pIniFile);
  byte_6BE113 = GetPrivateProfileIntA("outdoor", "RGBNightBottom.b", 129, pIniFile);
  dword_6BE0D8 = GetPrivateProfileIntA("debug", "noMist", 0, pIniFile);
  dword_6BE0C4 = GetPrivateProfileIntA("outdoor", "nosky", 0, pIniFile);
  dword_6BE0C8 = GetPrivateProfileIntA("render", "nodecorations", 0, pIniFile);
  dword_6BE0D4 = GetPrivateProfileIntA("outdoor", "nowavywater", 0, pIniFile);
  dword_6BE0FC = GetPrivateProfileIntA("outdoor", "gridband1", 10, pIniFile);
  dword_6BE100 = GetPrivateProfileIntA("outdoor", "gridband2", 15, pIniFile);
  dword_6BE104 = GetPrivateProfileIntA("outdoor", "gridband3", 25, pIniFile);
  dword_6BE0E0 = GetPrivateProfileIntA("outdoor", "ter_gamma", 0, pIniFile);
  dword_6BE0DC = GetPrivateProfileIntA("outdoor", "bld_gamma", 0, pIniFile);
  dword_6BE0F0 = GetPrivateProfileIntA("mipmapping", "ter_mm1", 2048, pIniFile);
  dword_6BE0F4 = GetPrivateProfileIntA("mipmapping", "ter_mm2", 4096, pIniFile);
  dword_6BE0F8 = GetPrivateProfileIntA("mipmapping", "ter_mm3", 8192, pIniFile);
  dword_6BE0E4 = GetPrivateProfileIntA("mipmapping", "bld_mm1", 1024, pIniFile);
  dword_6BE0E8 = GetPrivateProfileIntA("mipmapping", "bld_mm2", 2048, pIniFile);
  dword_6BE0EC = GetPrivateProfileIntA("mipmapping", "bld_mm3", 4096, pIniFile);

  pStruct9_global->shading_dist_shade = GetPrivateProfileIntA("shading", "dist_shade", 2048, pIniFile);
  pStruct9_global->shading_dist_shademist = GetPrivateProfileIntA("shading", "dist_shademist", 4096, pIniFile);
  pStruct9_global->shading_dist_mist = GetPrivateProfileIntA("shading", "dist_mist", 8192, pIniFile);

  GetPrivateProfileStringA("textures", "sky", "plansky1", byte_6BE114, 0x10u, pIniFile);
  GetPrivateProfileStringA("textures", "default", "dirt", Str, 0x10u, pIniFile);
  GetPrivateProfileStringA("debug", "recmod1", "1.0", String, 0x10u, pIniFile);
  flt_6BE3A4 = atof(String);
  GetPrivateProfileStringA("debug", "recmod2", "1.0", String, 0x10u, pIniFile);
  flt_6BE3A8 = atof(String);
  flt_6BE3AC = flt_6BE3A4 * *(double *)&byte_4D8410[768];
  v3 = 0;
  if ( strlen(byte_6BE114) )
  {
    do
    {
      if ( byte_6BE114[v3] == 32 )
        byte_6BE114[v3] = 0;
      ++v3;
    }
    while ( v3 < strlen(byte_6BE114) );
  }
  v4 = 0;
  if ( strlen(Str) )
  {
    do
    {
      if ( Str[v4] == 32 )
        Str[v4] = 0;
      ++v4;
    }
    while ( v4 < strlen(Str) );
  }
  dword_6BE050 = GetPrivateProfileIntA("texmapping", "terrain_subdivsize", 16, pIniFile);
  dword_6BE054 = GetPrivateProfileIntA("texmapping", "terrain_subdivpow2", 4, pIniFile);
  dword_6BE058 = GetPrivateProfileIntA("texmapping", "building_subdivsize", 32, pIniFile);
  dword_6BE05C = GetPrivateProfileIntA("texmapping", "building_subdivpow2", 5, pIniFile);

  pParty_global->dword_00000C = pParty_global->dword_000010 = GetPrivateProfileIntA("party", "eyelevel", 160, pIniFile);
  pParty_global->dword_000004 = pParty_global->dword_000008 = GetPrivateProfileIntA("party", "height", 192, pIniFile);

  return sub_4666D5();
}

//----- (0047F138) --------------------------------------------------------
bool __cdecl sub_47F138()
{
  signed int v0; // ebx@1
  int v2;
  __int16 v3; // ax@5
  int v4; // eax@7
  int v5; // eax@14
  signed int v7; // [sp+Ch] [bp-4h]@1
 int i;

  v0 = 0;
  v7 = 0;
  if ( !_strcmpi(Str1, "out09.odm") )
    v7 = 1;

  for (i = 0; i < dword_69ADD0; ++i)
  {
    v2 = &array_6836D0[i];

      sub_458693(pDecorationDescriptionList, array_6836D0[i].uDecorationDescriptionID);
      v3 = pDecorationDescriptionList->pDescriptions[array_6836D0[i].uDecorationDescriptionID].word_00004C;

      if ( v3 )
      {
        if ( dword_6807E0 < 9 )
        {
          sub_4A9A67(pSoundList, v3, 0);
          v4 = dword_6807E0++;
          dword_6807B8[v4] = i;
        }
      }
      if ( v7 )
      {
       if (array_6836D0[i].word_000014 == 20 )
        *(char *)&array_6836D0[i].word_000002 |= 0x40u;
      }
      if ( !array_6836D0[i].word_000016)
      {
        if ( sub_44C2F4(&array_6836D0[i]) )
        {
          if ( v0 < 124 )
          {
            v5 = v0++ + 75;
            *(_WORD *)(v2 + 28) = v5;
            if ( !global_5E4C90.byte_000000[v0 + 74] )
              *(_BYTE *)(v2 + 2) |= 0x20u;
          }
        }
      }
  }

  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  return true;
}

//----- (00476750) --------------------------------------------------------
void __cdecl InitializeAutonotes()
{
  signed int v0; // ebp@3
  int v1; // ebx@4
  char *v2; // esi@4
  int v3; // eax@5
  char v4; // cl@5
  int v5; // edi@9
  int result; // eax@25
  signed int v7; // [sp+0h] [bp-4h]@4

 if (pAutonoteTXT_Raw)
   class23_DeleteBuffer(class23_instance, pAutonoteTXT_Raw);

 pAutonoteTXT_Raw = class17_fn1(pClass17_Events_LOD, "autonote.txt", 0);
 strtok(pAutonoteTXT_Raw, "\r");

  //v0 = (signed int)&unk_723724;
 v0 = 0;
  do
  {
    v1 = 0;
    v2 = strtok(0, "\r") + 1;
    v7 = 0;
    do
    {
      v4 = *v2;
      v3 = 0;
      while ( v4 != 9 && v4 )
      {
        ++v3;
        v4 = v2[v3];
      }
      v5 = (int)&v2[v3];
      if ( !v2[v3] )
        v7 = 1;
      *(_BYTE *)v5 = 0;
      if ( v3 )
      {
        if ( v1 == 1 )
        {
          *(_DWORD *)(&unk_723724 + v0 - 4) = sub_452C30(v2);
        }
        else
        {
          if ( v1 == 2 )
          {
            if ( _strcmpi(v2, "potion") )
            {
              if ( _strcmpi(v2, "stat") )
              {
                if ( _strcmpi(v2, "seer") )
                {
                  if ( _strcmpi(v2, "obelisk") )
                    *(_DWORD *)(&unk_723724 + v0) = 5 - (_strcmpi(v2, "teacher") != 0);
                  else
                    *(_DWORD *)(&unk_723724 + v0) = 2;
                }
                else
                {
                  *(_DWORD *)(&unk_723724 + v0) = 3;
                }
              }
              else
              {
                *(_DWORD *)(&unk_723724 + v0) = 1;
              }
            }
            else
            {
              *(_DWORD *)(&unk_723724 + v0) = 0;
            }
          }
        }
      }
      else
      {
        v7 = 1;
      }
      ++v1;
      v2 = (char *)(v5 + 1);
      result = v1 - 1;
    }
    while ( v1 - 1 <= 2 && !v7 );
    v0 += 8;
  }
  //while ( v0 < (signed int)&unk_723D3C );
  while (v0 < 0x618);
}

//----- (00443CE1) --------------------------------------------------------
int LoadFileToBuffer(const char *pSourceFile, unsigned char *pOutBuffer, unsigned int uBufferSize)
{
  int v5; // esi@3
  struct class18 class18_obj; // [sp+6Ch] [bp-50h]@1
  void *Src; // [sp+B8h] [bp-4h]@1
 FILE *f;

 Src = (void *)class17_fn1(pClass17_Events_LOD, pSourceFile, 0);
 class18_ctor(&class18_obj);

 f = class17_FindContainer(pClass17_Events_LOD, pSourceFile, 0);
 if (!f)
   erroneous_printf("Unable to load %s", pSourceFile);
 locked_fread(&class18_obj, 1, 0x30, f);

 v5 = class18_obj.uDecompressedSize;
 if (!v5)
   v5 = class18_obj.uCompressedSize;

 memset(&class18_obj, 0, 0x48u);
 if (v5 >= uBufferSize)
 {
  char v7[256];

  sprintf(v7, "File %s Size %lu - Buffer size %lu", pSourceFile, v5, uBufferSize);
  erroneous_printf(v7);
 }

 memcpy(pOutBuffer, Src, v5);
 class23_DeleteBuffer(class23_instance, Src);
 return v5;
}

//----- (004075DB) --------------------------------------------------------
signed int __fastcall sub_4075DB(int a1, int a2, int a3, int a4)
{
  int v4; // eax@1
  int v5; // esi@1
  int v6; // edi@2
  signed int v7; // esi@2
  char v8; // zf@2
  int v9; // ecx@3
  int v10; // edx@4
  signed int v11; // esi@7
  char v12; // zf@7
  int v13; // ecx@8
  int v14; // edx@9
  signed int v15; // esi@11
  char v16; // zf@11
  int v17; // ecx@12
  int v18; // edx@13
  int v19; // eax@14
  int v20; // ecx@14
  bool v21; // esi@14
  int v22; // edx@16
  int v23; // ecx@16
  int v24; // eax@17
  signed int v25; // ebx@18
  int v26; // esi@20
  signed int v27; // eax@22
  signed __int64 v28; // qtt@22
  unsigned __int8 v29; // sf@24
  unsigned __int8 v30; // of@24
  signed int result; // eax@25
  int v32; // [sp+8h] [bp-14h]@14
  int v33; // [sp+10h] [bp-Ch]@14
  signed int v34; // [sp+24h] [bp+8h]@14
  int v35; // [sp+28h] [bp+Ch]@2

  v4 = a4;
  v5 = *(_DWORD *)(a4 + 44);
  if ( v5 & 0x100 )
  {
    v7 = 0;
    v8 = *(_BYTE *)(a4 + 93) == 0;
    v35 = a1;
    v6 = a2;
    if ( !v8 )
    {
      v9 = dword_6BE63C;
      do
      {
        dword_4F5D98[v7] = *(_WORD *)(v9 + 6 * *(_WORD *)(*(_DWORD *)(v4 + 48) + 2 * v7));
        v10 = *(_WORD *)(*(_DWORD *)(v4 + 48) + 2 * v7++);
        dword_4F5CC4[v7] = *(_WORD *)(v9 + 6 * v10 + 2);
      }
      while ( v7 < *(_BYTE *)(v4 + 93) );
    }
  }
  else
  {
    v6 = a3;
    if ( v5 & 0x200 )
    {
      v11 = 0;
      v12 = *(_BYTE *)(a4 + 93) == 0;
      v35 = a1;
      if ( !v12 )
      {
        v13 = dword_6BE63C;
        do
        {
          dword_4F5D98[v11] = *(_WORD *)(v13 + 6 * *(_WORD *)(*(_DWORD *)(v4 + 48) + 2 * v11));
          v14 = *(_WORD *)(*(_DWORD *)(v4 + 48) + 2 * v11++);
          dword_4F5CC4[v11] = *(_WORD *)(v13 + 6 * v14 + 4);
        }
        while ( v11 < *(_BYTE *)(v4 + 93) );
      }
    }
    else
    {
      v15 = 0;
      v16 = *(_BYTE *)(a4 + 93) == 0;
      v35 = a2;
      if ( !v16 )
      {
        v17 = dword_6BE63C;
        do
        {
          dword_4F5D98[v15] = *(_WORD *)(v17 + 6 * *(_WORD *)(*(_DWORD *)(v4 + 48) + 2 * v15) + 2);
          v18 = *(_WORD *)(*(_DWORD *)(v4 + 48) + 2 * v15++);
          dword_4F5CC4[v15] = *(_WORD *)(v17 + 6 * v18 + 4);
        }
        while ( v15 < *(_BYTE *)(v4 + 93) );
      }
    }
  }
  v19 = *(_BYTE *)(v4 + 93);
  v34 = 0;
  dword_4F5D98[v19] = dword_4F5D98[0];
  dword_4F5CC8[v19] = dword_4F5CC8[0];
  v32 = v19;
  v21 = dword_4F5CC8[0] >= v6;
  v20 = 0;
  v33 = 0;
  if ( v19 <= 0 )
    goto LABEL_29;
  do
  {
    if ( v34 >= 2 )
      break;
    v23 = 4 * v20;
    v22 = *(int *)((char *)&dword_4F5CCC + v23);
    if ( v21 ^ v22 >= v6 )
    {
      v24 = *(int *)((char *)&dword_4F5D9C + v23);
      if ( v24 >= v35 )
        v25 = 0;
      else
        v25 = 2;
      v26 = v25 | *(int *)((char *)dword_4F5D98 + v23) < v35;
      if ( v26 != 3 )
      {
        if ( !v26
          || (v27 = v24 - *(int *)((char *)dword_4F5D98 + v23),
              LODWORD(v28) = v27 << 16,
              HIDWORD(v28) = v27 >> 16,
              *(int *)((char *)dword_4F5D98 + v23)
            + ((signed int)(((unsigned __int64)(v28
                                              / (v22 - *(int *)((char *)dword_4F5CC8 + v23))
                                              * ((v6 - *(int *)((char *)dword_4F5CC8 + v23)) << 16)) >> 16)
                          + 32768) >> 16) >= v35) )
          ++v34;
      }
    }
    v21 = v22 >= v6;
    v20 = v33 + 1;
    compile_error;//v30 = __SETO__(v33 + 1, v32);
    v29 = v33++ + 1 - v32 < 0;
  }
  while ( v29 ^ v30 );
  result = 1;
  if ( v34 != 1 )
LABEL_29:
    result = 0;
  return result;
}


//----- (004077F1) --------------------------------------------------------
signed int __fastcall sub_4077F1(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // eax@1
  signed int v6; // edi@1
  int v7; // esi@1
  char v8; // zf@2
  int v9; // edx@3
  int v10; // ecx@4
  char v11; // zf@7
  int v12; // edx@8
  int v13; // ecx@9
  char v14; // zf@11
  int v15; // edx@12
  int v16; // ecx@13
  bool v17; // edi@14
  int v18; // esi@14
  int v19; // edx@16
  int v20; // ecx@16
  int v21; // eax@17
  signed int v22; // ebx@18
  int v23; // edi@20
  signed int v24; // eax@22
  signed __int64 v25; // qtt@22
  signed int result; // eax@25
  int v27; // [sp+14h] [bp-8h]@14
  int v28; // [sp+28h] [bp+Ch]@2
  signed int v29; // [sp+2Ch] [bp+10h]@14

  v5 = a4;
  v7 = *(_DWORD *)(a4 + 28);
  v6 = 0;
  if ( v7 & 0x100 )
  {
    v8 = *(_BYTE *)(a4 + 302) == 0;
    v28 = a1;
    a3 = a2;
    if ( !v8 )
    {
      v9 = v5 + 32;
      do
      {
        ++v6;
        dword_4F5BF4[v6] = *(_DWORD *)(*(_DWORD *)(a5 + 4) + 12 * *(_WORD *)v9);
        v10 = *(_WORD *)v9;
        v9 += 2;
        dword_4F5B24[v6] = *(_DWORD *)(*(_DWORD *)(a5 + 4) + 12 * v10 + 4);
      }
      while ( v6 < *(_BYTE *)(v5 + 302) );
    }
  }
  else
  {
    if ( v7 & 0x200 )
    {
      v11 = *(_BYTE *)(a4 + 302) == 0;
      v28 = a1;
      if ( !v11 )
      {
        v12 = v5 + 32;
        do
        {
          ++v6;
          dword_4F5BF4[v6] = *(_DWORD *)(*(_DWORD *)(a5 + 4) + 12 * *(_WORD *)v12);
          v13 = *(_WORD *)v12;
          v12 += 2;
          dword_4F5B24[v6] = *(_DWORD *)(*(_DWORD *)(a5 + 4) + 12 * v13 + 8);
        }
        while ( v6 < *(_BYTE *)(v5 + 302) );
      }
    }
    else
    {
      v14 = *(_BYTE *)(a4 + 302) == 0;
      v28 = a2;
      if ( !v14 )
      {
        v15 = v5 + 32;
        do
        {
          ++v6;
          dword_4F5BF4[v6] = *(_DWORD *)(*(_DWORD *)(a5 + 4) + 12 * *(_WORD *)v15 + 4);
          v16 = *(_WORD *)v15;
          v15 += 2;
          dword_4F5B24[v6] = *(_DWORD *)(*(_DWORD *)(a5 + 4) + 12 * v16 + 8);
        }
        while ( v6 < *(_BYTE *)(v5 + 302) );
      }
    }
  }
  v18 = *(_BYTE *)(v5 + 302);
  v29 = 0;
  dword_4F5BF8[v18] = dword_4F5BF8[0];
  dword_4F5B28[v18] = dword_4F5B28[0];
  v27 = 0;
  v17 = dword_4F5B28[0] >= a3;
  if ( v18 <= 0 )
    goto LABEL_29;
  do
  {
    if ( v29 >= 2 )
      break;
    v20 = 4 * v27;
    v19 = dword_4F5B2C[v27];
    if ( v17 ^ v19 >= a3 )
    {
      v21 = *(int *)((char *)&dword_4F5BFC + v20);
      if ( v21 >= v28 )
        v22 = 0;
      else
        v22 = 2;
      v23 = v22 | *(int *)((char *)dword_4F5BF8 + v20) < v28;
      if ( v23 != 3 )
      {
        if ( !v23
          || (v24 = v21 - *(int *)((char *)dword_4F5BF8 + v20),
              LODWORD(v25) = v24 << 16,
              HIDWORD(v25) = v24 >> 16,
              *(int *)((char *)dword_4F5BF8 + v20)
            + ((signed int)(((unsigned __int64)(v25
                                              / (v19 - *(int *)((char *)dword_4F5B28 + v20))
                                              * ((a3 - *(int *)((char *)dword_4F5B28 + v20)) << 16)) >> 16)
                          + 32768) >> 16) >= v28) )
          ++v29;
      }
    }
    ++v27;
    v17 = v19 >= a3;
  }
  while ( v27 < v18 );
  result = 1;
  if ( v29 != 1 )
LABEL_29:
    result = 0;
  return result;
}

//----- (0045B2A7) --------------------------------------------------------
void __thiscall Keyboard_resume(int this)
{
  int v1; // esi@1
  char v2; // [sp-18h] [bp-24h]@2
  const CHAR *v3; // [sp-14h] [bp-20h]@2
  int v4; // [sp-10h] [bp-1Ch]@2
  int v5; // [sp-Ch] [bp-18h]@2
  const char *v6; // [sp-8h] [bp-14h]@2
  int v7; // [sp-4h] [bp-10h]@2
  char *v8; // [sp+4h] [bp-8h]@2
  int v9; // [sp+Bh] [bp-1h]@2

  v1 = this;
  if ( *(_DWORD *)(this + 1804) )
  {
    EnterCriticalSection(&pGame->class01_obj->cs4);
    sub_45B1B1(v1);
    set_acquire(*(_DWORD *)(v1 + 1804), 1);
    ResumeThread(*(HANDLE *)(v1 + 4));
    LeaveCriticalSection(&pGame->class01_obj->cs4);
  }
  else
  {
    v7 = 97;
    v6 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\KeyboardAsync.cpp";
    v8 = &v2;
    sub_40E2C8(&v2, "Invalid DI_Keyboard, bailing out of resume()", (int)&v9);
    sub_467834(&v8, v2, v3, v4, v5, v6, v7);
  }
}

//----- (00490109) --------------------------------------------------------
int GetRaceByFace(struct Player *_this)
{
  signed int v2; // ecx@1

  v2 = _this->uFace;
  if ( v2 > 15 && v2 < 20)
    return 2;
  else if ( v2 > 1)
    return 3;
  else if ( v2 >= 0 )
  {
   if ( v2 <= 7 )
     return 0;
   else if ( v2 <= 11 )
     return 1;
  }
  return 0;
}

//----- (0041B690) --------------------------------------------------------
int __cdecl UI_Initialize_Icons()
{
  char v11; // al@1
  int v12; // eax@1
  char v16; // al@1
  int v17; // eax@1
  char v21; // al@1
  int v22; // eax@1
  char v26; // al@1
  char v31; // al@1
  char v36; // al@1
 int i;
 wchar_t pFilepath[256];


 CIconFrameTable_InitializeIcon(pIconFrameTable, CIconFrameTable_FindIcon(pIconFrameTable, "wizeyeC"));
 CIconFrameTable_InitializeIcon(pIconFrameTable, CIconFrameTable_FindIcon(pIconFrameTable, "wizeyeB"));
 CIconFrameTable_InitializeIcon(pIconFrameTable, CIconFrameTable_FindIcon(pIconFrameTable, "wizeyeA"));
 CIconFrameTable_InitializeIcon(pIconFrameTable, CIconFrameTable_FindIcon(pIconFrameTable, "torchC"));
 CIconFrameTable_InitializeIcon(pIconFrameTable, CIconFrameTable_FindIcon(pIconFrameTable, "torchB"));
 CIconFrameTable_InitializeIcon(pIconFrameTable, CIconFrameTable_FindIcon(pIconFrameTable, "torchA"));

 uTextureIdx_MapDirs[0] = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"MAPDIR8");
 uTextureIdx_MapDirs[1] = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"MAPDIR1");
 uTextureIdx_MapDirs[2] = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"MAPDIR2");
 uTextureIdx_MapDirs[3] = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"MAPDIR3");
 uTextureIdx_MapDirs[4] = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"MAPDIR4");
 uTextureIdx_MapDirs[5] = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"MAPDIR5");
 uTextureIdx_MapDirs[6] = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"MAPDIR6");
 uTextureIdx_MapDirs[7] = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"MAPDIR7");

 uTextureIdx_UIBarRed = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ui-bar_red");
 uTextureIdx_UIBarYellow = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ui-bar_yellow");
 uTextureIdx_UIBarGreen = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ui-bar_green");
 uTextureIdx_UIBarBlue = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ui-bar_blue");

 uTextureIdx_MonsterHP_BarYellow = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ui-MonsterHP_BarYellow");
 uTextureIdx_MonsterHP_BarRed = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ui-MonsterHP_BarRed");
 uTextureIdx_MonsterHP_BarGreen = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ui-MonsterHP_BarGreen");
 uTextureIdx_MonsterHP_CapRight = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ui-MonsterHP_CapRight");
 uTextureIdx_MonsterHP_CapLeft = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ui-MonsterHP_CapLeft");
 uTextureIdx_MonsterHP_Bg = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ui-MonsterHP_Bg");

 uTextureIdx_Leather = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"LEATHER");

 pClass18_ibground = &pClass17_Icons_LOD->aLODHeaders[class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ibground")];

 uTextureIdx_BtnMake = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ButtMake");
 uTextureIdx_BtnYes2 = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ButtYes2");
 uTextureIdx_BtnXokU = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"x_ok_u");

 uTextureIdx_BtnEsc2 = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ButtEsc2");
 uTextureIdx_BtnXxU = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"x_x_u");
 uTextureIdx_BtnMake2 = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ButtMake2");

 pGUIWindow0 = GUIWindowCreate(0, 0, 640, 480, 1, 0, 0);
 GUIButtonCreate(pGUIWindow0, 7, 8, 460, 343, 1, 0, 10, 0, 0, "", 0);
 GUIButtonCreate(pGUIWindow0, 61, 424, 31, 40, 2, 94, 110, 1, 49, "", 0);
 GUIButtonCreate(pGUIWindow0, 177, 424, 31, 40, 2, 94, 110, 2, 50, "", 0);
 GUIButtonCreate(pGUIWindow0, 292, 424, 31, 40, 2, 94, 110, 3, 51, "", 0);
 GUIButtonCreate(pGUIWindow0, 407, 424, 31, 40, 2, 94, 110, 4, 52, "", 0);
 GUIButtonCreate(pGUIWindow0, 24, 404, 5, 49, 1, 93, 0, 1, 0, "", 0);
 GUIButtonCreate(pGUIWindow0, 139, 404, 5, 49, 1, 93, 0, 2, 0, "", 0);
 GUIButtonCreate(pGUIWindow0, 255, 404, 5, 49, 1, 93, 0, 3, 0, "", 0);
 GUIButtonCreate(pGUIWindow0, 370, 404, 5, 49, 1, 93, 0, 4, 0, "", 0);
 GUIButtonCreate(pGUIWindow0, 97, 404, 5, 49, 1, 93, 0, 1, 0, "", 0);
 GUIButtonCreate(pGUIWindow0, 212, 404, 5, 49, 1, 93, 0, 2, 0, "", 0);
 GUIButtonCreate(pGUIWindow0, 328, 404, 5, 49, 1, 93, 0, 3, 0, "", 0);
 GUIButtonCreate(pGUIWindow0, 443, 404, 5, 49, 1, 93, 0, 4, 0, "", 0);

 uTextureIdx_ib_td1_A = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ib-td1-A");
 v11 = sub_459C82(&dword_69AE00, 13);
 dword_507A10 = GUIButtonCreate(pGUIWindow0,
                   491,
                   353,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_td1_A].uTextureWidth,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_td1_A].uTextureHeight,
                   1,
                   0,
                   200,
                   0,
                   v11,
                   pGlobalTXT_LocalizationStrings[174],
                   &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_td1_A]);



  uTextureIdx_ib_td2_A = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ib-td2-A");
  v16 = sub_459C82(&dword_69AE00, 17);
  dword_507A0C = GUIButtonCreate(pGUIWindow0,
                   527,
                   353,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_td1_A].uTextureWidth,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_td1_A].uTextureHeight,
                   1,
                   0,
                   201,
                   0,
                   v16,
                   pGlobalTXT_LocalizationStrings[154],
                   &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_td2_A]);



  v17 = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ib-td3-A");
  v21 = sub_459C82(&dword_69AE00, 18);
  dword_507A08 = GUIButtonCreate(pGUIWindow0,
                   546,
                   353,
                   pClass17_Icons_LOD->aLODHeaders[v17].uTextureWidth,
                   pClass17_Icons_LOD->aLODHeaders[v17].uTextureHeight,
                   1,
                   0,
                   202,
                   0,
                   v21,
                   pGlobalTXT_LocalizationStrings[139],
                   &pClass17_Icons_LOD->aLODHeaders[v17]);



  v22 = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ib-td4-A");
  v26 = sub_459C82(&dword_69AE00, 16);
  dword_507A04 = GUIButtonCreate(pGUIWindow0,
                   570,
                   353,
                   pClass17_Icons_LOD->aLODHeaders[v22].uTextureWidth,
                   pClass17_Icons_LOD->aLODHeaders[v22].uTextureHeight,
                   1,
                   0,
                   203,
                   0,
                   v26,
                   pGlobalTXT_LocalizationStrings[78],
                   &pClass17_Icons_LOD->aLODHeaders[v22]);



  uTextureIdx_ib_td5_A = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"ib-td5-A");
  dword_507A00 = GUIButtonCreate(pGUIWindow0,
                   600,
                   361,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_td5_A].uTextureWidth,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_td5_A].uTextureHeight,
                   1,
                   0,
                   224,
                   0,
                   72,
                   pGlobalTXT_LocalizationStrings[159],
                   &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_td5_A]);



  byte_507948 = 0;
  byte_507949 = 0;
  byte_50794A = 0;
  v31 = sub_459C82(&dword_69AE00, 23);
  dword_507A18 = GUIButtonCreate(pGUIWindow0,
                   574,
                   136,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_autout_a].uTextureWidth,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_autout_a].uTextureHeight,
                   2,
                   0,
                   368,
                   0,
                   v31,
                   pGlobalTXT_LocalizationStrings[252],
                   &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_autout_a]);



  v36 = sub_459C82(&dword_69AE00, 24);
  dword_507A14 = GUIButtonCreate(pGUIWindow0,
                   519,
                   136,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_autin_a].uTextureWidth,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_autin_a].uTextureHeight,
                   2,
                   0,
                   367,
                   0,
                   v36,
                   pGlobalTXT_LocalizationStrings[251],
                   &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_autin_a]);



  GUIButtonCreate(pGUIWindow0, 481, 0, 153, 67, 1, 92, 0, 0, 0, "", 0);
  GUIButtonCreate(pGUIWindow0, 491, 149, 64, 74, 1, 0, 134, 0, 53, "", 0);
  GUIButtonCreate(pGUIWindow0, 561, 149, 64, 74, 1, 0, 135, 0, 54, "", 0);
  GUIButtonCreate(pGUIWindow0, 476, 322, 77, 17, 1, 100, 0, 0, 0, "", 0);
  GUIButtonCreate(pGUIWindow0, 555, 322, 77, 17, 1, 101, 0, 0, 0, "", 0);

  dword_5079F8 = GUIButtonCreate(pGUIWindow0,
                   476,
                   450,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_m1d_a].uTextureWidth,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_m1d_a].uTextureHeight,
                   1,
                   0,
                   105,
                   0,
                   67,
                   pGlobalTXT_LocalizationStrings[38],
                   &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_m1d_a]);

  dword_5079FC = GUIButtonCreate(pGUIWindow0,
                   518,
                   450,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_m2d_a].uTextureWidth,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_m2d_a].uTextureHeight,
                   1,
                   0,
                   104,
                   0,
                   82,
                   pGlobalTXT_LocalizationStrings[182],
                   &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_m2d_a]);

  dword_5079F4 = GUIButtonCreate(pGUIWindow0,
                   560,
                   450,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_m3d_a].uTextureWidth,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_m3d_a].uTextureHeight,
                   1,
                   0,
                   106,
                   0,
                   90,
                   pGlobalTXT_LocalizationStrings[173],
                   &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_m3d_a]);

  dword_5079F0 = GUIButtonCreate(pGUIWindow0,
                   602,
                   450,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_m4d_a].uTextureWidth,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_m4d_a].uTextureHeight,
                   1,
                   0,
                   107,
                   0,
                   0,
                   pGlobalTXT_LocalizationStrings[93],
                   &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_m4d_a]);

  dword_5079EC = GUIButtonCreate(pGUIWindow0,
                   469,
                   178,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_npcld_a].uTextureWidth,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_npcld_a].uTextureHeight,
                   1,
                   0,
                   188,
                   0,
                   0,
                   "",
                   &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_npcld_a]);

  dword_5079E8 = GUIButtonCreate(pGUIWindow0,
                   626,
                   178,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_npcrd_a].uTextureWidth,
                   pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_npcrd_a].uTextureHeight,
                   1,
                   0,
                   188,
                   1,
                   0,
                   "",
                   &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_ib_npcrd_a]);


 for (i = 0; i < 14; ++i)
 {
  wsprintfW(pFilepath, L"isn-%02d", i + 1);
  uTextureIdx_SpellEffecIcons[i] = class17_LoadTextureFromCBM(pClass17_Icons_LOD, pFilepath);
 }

 uIconIdx_Spell21 = CIconFrameTable_FindIcon(pIconFrameTable, "spell21");
 uIconIdx_Spell27 = CIconFrameTable_FindIcon(pIconFrameTable, "spell27");
}

//----- (0048E9F4) --------------------------------------------------------
int __thiscall sub_48E9F4(struct Player *_this)
{
  signed int v1; // edx@1

  v1 = 0;
  while (true)
  {
   if (*((int *)_this + 2 * dword_4EDEF8[v1]) | *((int *)_this + 2 * dword_4EDEF8[v1] + 1))
     break;

   if (++v1 >= 18)
     return 18;
  }
  return dword_4EDEF8[v1];
}

//----- (00486B4E) --------------------------------------------------------
char __fastcall sub_486B4E(int a1, int a2, int *a3, struct struct8 *a4)
{
  int v4; // edi@1
  int v5; // esi@1
  int v7; // eax@3
  int v8; // ebx@3
  int *v9; // ecx@7
  int v10; // ebx@8
  int v11; // eax@10
  unsigned __int8 v12; // zf@10
  char v13; // sf@10
  unsigned __int8 v14; // of@10
  int v15; // edx@14
  double v16; // st7@14
  double v17; // st6@14
  int v18; // edi@16
  double v19; // st7@16
  char v20; // zf@16
  double v21; // st7@16
  double v22; // st7@16
  int v23; // edi@18
  char v24; // zf@18
  double v25; // st7@18
  double v26; // st7@18
  char *i; // edx@20
  double v28; // st7@28
  int v29; // eax@28
  char v31; // [sp-18h] [bp-98h]@2
  int v32; // [sp-14h] [bp-94h]@2
  int v33; // [sp-10h] [bp-90h]@2
  int v34; // [sp-Ch] [bp-8Ch]@2
  const char *v35; // [sp-8h] [bp-88h]@2
  int v36; // [sp-4h] [bp-84h]@2
  double v37; // [sp+Ch] [bp-74h]@28
  double v38; // [sp+14h] [bp-6Ch]@28
  double v39; // [sp+1Ch] [bp-64h]@20
  double v40; // [sp+24h] [bp-5Ch]@16
  double v41; // [sp+2Ch] [bp-54h]@14
  int v42; // [sp+34h] [bp-4Ch]@2
  int v43; // [sp+38h] [bp-48h]@28
  float v44; // [sp+3Ch] [bp-44h]@28
  int v45; // [sp+40h] [bp-40h]@28
  int v46; // [sp+44h] [bp-3Ch]@20
  float v47; // [sp+48h] [bp-38h]@18
  int v48; // [sp+4Ch] [bp-34h]@16
  signed int v49; // [sp+50h] [bp-30h]@14
  int v50; // [sp+54h] [bp-2Ch]@3
  int v51; // [sp+58h] [bp-28h]@1
  int v52; // [sp+5Ch] [bp-24h]@14
  int v53; // [sp+60h] [bp-20h]@6
  int v54; // [sp+64h] [bp-1Ch]@6
  int v55; // [sp+68h] [bp-18h]@7
  int v56; // [sp+6Ch] [bp-14h]@1
  int v57; // [sp+70h] [bp-10h]@7
  int v58; // [sp+74h] [bp-Ch]@7
  float v59; // [sp+78h] [bp-8h]@10
  int v60; // [sp+7Ch] [bp-4h]@14
  char *v61; // [sp+8Ch] [bp+Ch]@2

  runtime_warning;
  return 0;

  v5 = a4;
  v4 = a1;
  v56 = a2;
  v51 = a1;
  if ( !(a4->dword_000030 & 0x4000))
  {
    v36 = 162;
    v35 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odspan.cpp";
    v61 = &v31;
    sub_40E2C8(&v31, "The Texture Frame Table is not a supported feature.", (int)((char *)&a4 + 3));
    sub_466D09(&v42, *(int *)&v31, v32, v33, v34, v35, v36);
  }
  LOBYTE(v7) = *(_BYTE *)(v5 + 264);
  v8 = *(_DWORD *)(v5 + 20);
  *(_BYTE *)(v5 + 264) = 0;
  BYTE3(a4) = v7;
  v50 = v8;
  if ( v8 > 0 )
  {
    if ( pStruct9_global->dword_000034 < 1999 )
    {
      v7 = pStruct9_global->dword_000030;
      if ( pStruct9_global->dword_000030 < 5979 )
      {
        *(_DWORD *)(v5 + 176) = 0;
        *(_DWORD *)(v5 + 260) = 0;
        v54 = -1;
        v42 = v7;
        v53 = 10000;
        sub_45CB89(v4, v8);
        if ( v8 > 0 )
        {
          v9 = a3;
          v57 = 1;
          v58 = v4 + 44;
          v55 = v56 - (_DWORD)a3;
          do
          {
            v10 = v57;
            ++pStruct9_global->dword_000030;
            if ( v57 >= v50 )
              v10 = 0;
            v11 = *v9;
            compile_error;//v14 = __SETO__(*v9, v54);
            v12 = *v9 == v54;
            v13 = *v9 - v54 < 0;
            LODWORD(v59) = *v9;
            if ( !((unsigned __int8)(v13 ^ v14) | v12) )
              v54 = v11;
            if ( v11 < v53 )
              v53 = v11;
            v16 = (double)SLODWORD(v59);
            v15 = (int)&a3[v10];
            *(float *)&v60 = v16;
            v17 = (double)*(signed int *)v15;
            v59 = v17;
            *(float *)&v49 = v17 - v16;
            v41 = *(float *)&v49 + 6.755399441055744e15;
            v52 = LODWORD(v41);
            if ( LODWORD(v41) )
            {
              if ( LODWORD(v41) >= 0 )
              {
                v23 = (int)((char *)v9 + v55);
                *(_DWORD *)(dword_80C978 + 8) = 1;
                LODWORD(v47) = v56 + 4 * v10;
                compile_error;//v49 = *LODWORD(v47) - *(_DWORD *)v23;
                v24 = BYTE3(a4) == 0;
                v25 = (double)v49;
                v49 = *(_DWORD *)v15 - *v9;
                v26 = v25 / (double)v49;
                *(float *)(dword_80C978 + 4) = v26;
                *(float *)dword_80C978 = (*(float *)&v60 - (double)*v9) * v26 + (double)*(signed int *)v23;
                if ( !v24 )
                {
                  *(float *)(dword_80C978 + 28) = *(float *)v58;
                  *(float *)(dword_80C978 + 32) = *(float *)(48 * v10 + v51 + 44);
                  *(float *)(dword_80C978 + 36) = (double)*(signed int *)v23;
                  compile_error;//*(float *)(dword_80C978 + 40) = (double)(signed int)*LODWORD(v47);
                  *(float *)(dword_80C978 + 44) = (double)*v9;
                  *(float *)(dword_80C978 + 48) = (double)*(signed int *)v15;
                  compile_error;//*(_DWORD *)(v5 + 4 * *(_DWORD *)(v5 + 176)++ + 96) = dword_80C978;
                }
              }
              else
              {
                v40 = *(float *)&v60 + 6.755399441055744e15;
                v48 = LODWORD(v40);
                v60 = LODWORD(v59);
                v19 = (double)SLODWORD(v40);
                *(_DWORD *)(dword_80C978 + 8) = 0;
                v18 = v56 + 4 * v10;
                v59 = v19;
                v49 = *(int *)((char *)v9 + v55) - *(_DWORD *)v18;
                v20 = BYTE3(a4) == 0;
                v21 = (double)v49;
                v49 = *v9 - *(_DWORD *)v15;
                v22 = v21 / (double)v49;
                *(float *)(dword_80C978 + 4) = v22;
                *(float *)dword_80C978 = (*(float *)&v60 - (double)*(signed int *)v15) * v22
                                       + (double)*(signed int *)v18;
                if ( !v20 )
                {
                  *(float *)(dword_80C978 + 28) = *(float *)(48 * v10 + v51 + 44);
                  *(float *)(dword_80C978 + 32) = *(float *)v58;
                  *(float *)(dword_80C978 + 36) = (double)*(signed int *)v18;
                  *(float *)(dword_80C978 + 40) = (double)*(int *)((char *)v9 + v55);
                  *(float *)(dword_80C978 + 44) = (double)*(signed int *)v15;
                  *(float *)(dword_80C978 + 48) = (double)*v9;
                  compile_error;//*(_DWORD *)(v5 + 4 * *(_DWORD *)(v5 + 260)++ + 180) = dword_80C978;
                }
              }
              v39 = *(float *)&v60 + 6.755399441055744e15;
              v46 = LODWORD(v39);
              for ( i = (char *)pNewEdgesBuf + 52 * LODWORD(v39);
                    **((float **)i + 4) < (double)*(float *)dword_80C978;
                    i = (char *)*((_DWORD *)i + 4) )
                ;
              if ( *(float *)i != *(float *)dword_80C978 || *((_DWORD *)i + 2) || *(_DWORD *)(dword_80C978 + 8) != 1 )
              {
                *(_DWORD *)(dword_80C978 + 16) = *((_DWORD *)i + 4);
                *((_DWORD *)i + 4) = dword_80C978;
              }
              else
              {
                *(_DWORD *)(dword_80C978 + 16) = i;
                *(_DWORD *)(*((_DWORD *)i + 5) + 16) = dword_80C978;
              }
              v28 = v59 - 1.0;
              *(float *)&v49 = v28;
              v47 = v28;
              v38 = v47 + 6.755399441055744e15;
              v45 = LODWORD(v38);
              *(_DWORD *)(dword_80C978 + 24) = dword_80CA10[LODWORD(v38)];
              LODWORD(v44) = v49;
              v37 = *(float *)&v49 + 6.755399441055744e15;
              v43 = LODWORD(v37);
              v29 = dword_80C978;
              dword_80CA10[LODWORD(v37)] = dword_80C978;
              *(_DWORD *)(v29 + 12) = dword_80C97C;
              if ( dword_80C978 < (unsigned int)((char *)pEdgesBuf + 311948) )
                dword_80C978 += 52;
            }
            ++v57;
            v58 += 48;
            ++v9;
          }
          while ( v57 - 1 < v50 );
        }
        LOBYTE(v7) = v42;
        if ( pStruct9_global->dword_000030 != v42 )
        {
          *(_DWORD *)(v5 + 72) = 0;
          *(_WORD *)(dword_80C97C + 34) = 0;
          *(_DWORD *)(dword_80C97C + 28) = v5;
          *(float *)(dword_80C97C + 4) = *(float *)(v5 + 4);
          *(float *)(dword_80C97C + 8) = *(float *)(v5 + 8);
          *(float *)dword_80C97C = *(float *)v5;
          *(float *)(dword_80C97C + 12) = *(float *)(v5 + 12);
          *(float *)(dword_80C97C + 16) = *(float *)(v5 + 16);
          v7 = (int)((char *)pSurfsBuf + 71964);
          if ( dword_80C97C < (unsigned int)((char *)pSurfsBuf + 71964) )
          {
            dword_80C97C += 36;
            ++pStruct9_global->dword_000034;
          }
          if ( BYTE3(a4) )
            *(_BYTE *)(v5 + 264) = 1;
        }
      }
    }
  }
  return v7;
}

//----- (00407A1C) --------------------------------------------------------
bool __fastcall sub_407A1C(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // esi@1
  int v7; // eax@2
  signed int v8; // ecx@2
  int v9; // ebx@2
  int v10; // edi@2
  int v11; // esi@2
  int v12; // ebx@4
  int v13; // ecx@4
  int v14; // eax@4
  int v15; // edx@6
  int v16; // edi@16
  int v17; // esi@19
  int v18; // ebx@25
  int v19; // ST34_4@25
  int v20; // ST38_4@25
  int v21; // eax@25
  char v22; // zf@25
  int v23; // eax@26
  signed int v24; // edi@26
  int v25; // ST34_4@30
  signed __int64 v26; // qtt@31
  int v27; // eax@31
  int v28; // eax@37
  signed int v29; // ecx@37
  int v30; // ebx@37
  int v31; // edi@37
  int v32; // esi@37
  int v33; // ebx@39
  int v34; // ecx@39
  int v35; // eax@39
  int v36; // edx@41
  int v37; // edi@51
  int v38; // esi@54
  int v39; // ebx@60
  char v40; // zf@60
  int v41; // eax@61
  signed int v42; // edi@61
  signed __int64 v43; // qtt@66
  int v44; // eax@66
  int v45; // eax@73
  signed int v46; // ecx@73
  int v47; // ebx@73
  int v48; // edi@73
  int v49; // esi@73
  int v50; // edx@75
  int v51; // ebx@75
  int v52; // ecx@75
  int v53; // eax@75
  int v54; // ecx@77
  int v55; // edi@77
  int v56; // eax@81
  int v57; // esi@81
  int v58; // edx@90
  int v59; // ecx@90
  int v60; // eax@90
  int v61; // esi@91
  int v62; // ebx@98
  int v63; // ST34_4@98
  int v64; // ST30_4@98
  int v65; // eax@98
  char v66; // zf@98
  int v67; // eax@99
  signed int v68; // edi@99
  int v69; // ST2C_4@103
  signed __int64 v70; // qtt@104
  int v71; // eax@104
  int v72; // eax@111
  signed int v73; // ecx@111
  int v74; // ebx@111
  int v75; // edi@111
  int v76; // esi@111
  int v77; // edx@113
  int v78; // ebx@113
  int v79; // ecx@113
  int v80; // eax@113
  int v81; // ecx@115
  int v82; // edi@115
  int v83; // eax@119
  int v84; // esi@119
  int v85; // eax@128
  int v86; // ecx@128
  int v87; // ecx@128
  int v88; // esi@129
  int v89; // ebx@136
  char v90; // zf@136
  int v91; // eax@137
  signed int v92; // edi@137
  signed __int64 v93; // qtt@142
  int v94; // eax@142
  int v96; // [sp-Ch] [bp-88h]@88
  int v97; // [sp-Ch] [bp-88h]@126
  signed int v98; // [sp-8h] [bp-84h]@88
  signed int v99; // [sp-8h] [bp-84h]@126
  int v100; // [sp-4h] [bp-80h]@88
  int v101; // [sp-4h] [bp-80h]@126
  int v102; // [sp+Ch] [bp-70h]@13
  int v103; // [sp+Ch] [bp-70h]@48
  int v104; // [sp+10h] [bp-6Ch]@18
  int v105; // [sp+10h] [bp-6Ch]@98
  int v106; // [sp+10h] [bp-6Ch]@104
  int v107; // [sp+18h] [bp-64h]@25
  int v108; // [sp+18h] [bp-64h]@31
  int i; // [sp+18h] [bp-64h]@90
  int v110; // [sp+18h] [bp-64h]@128
  signed int v111; // [sp+20h] [bp-5Ch]@1
  signed int v112; // [sp+24h] [bp-58h]@1
  int v113; // [sp+28h] [bp-54h]@1
  int v114; // [sp+2Ch] [bp-50h]@1
  int v115; // [sp+30h] [bp-4Ch]@1
  int v116; // [sp+34h] [bp-48h]@4
  int v117; // [sp+34h] [bp-48h]@39
  signed int v118; // [sp+34h] [bp-48h]@75
  signed int v119; // [sp+34h] [bp-48h]@113
  int v120; // [sp+38h] [bp-44h]@4
  int v121; // [sp+38h] [bp-44h]@39
  signed int v122; // [sp+38h] [bp-44h]@76
  signed int v123; // [sp+38h] [bp-44h]@114
  int v124; // [sp+3Ch] [bp-40h]@4
  int v125; // [sp+3Ch] [bp-40h]@39
  signed int v126; // [sp+3Ch] [bp-40h]@77
  signed int v127; // [sp+3Ch] [bp-40h]@115
  signed int v128; // [sp+40h] [bp-3Ch]@11
  signed int v129; // [sp+40h] [bp-3Ch]@46
  signed int v130; // [sp+40h] [bp-3Ch]@78
  signed int v131; // [sp+40h] [bp-3Ch]@116
  signed int v132; // [sp+44h] [bp-38h]@10
  signed int v133; // [sp+44h] [bp-38h]@45
  signed int v134; // [sp+44h] [bp-38h]@81
  signed int v135; // [sp+44h] [bp-38h]@119
  signed int v136; // [sp+48h] [bp-34h]@7
  signed int v137; // [sp+48h] [bp-34h]@42
  signed int v138; // [sp+48h] [bp-34h]@82
  signed int v139; // [sp+48h] [bp-34h]@120
  signed int v140; // [sp+4Ch] [bp-30h]@6
  signed int v141; // [sp+4Ch] [bp-30h]@41
  int v142; // [sp+4Ch] [bp-30h]@75
  int v143; // [sp+4Ch] [bp-30h]@113
  signed int v144; // [sp+50h] [bp-2Ch]@5
  signed int v145; // [sp+50h] [bp-2Ch]@40
  int v146; // [sp+50h] [bp-2Ch]@75
  int v147; // [sp+50h] [bp-2Ch]@113
  signed int v148; // [sp+54h] [bp-28h]@4
  signed int v149; // [sp+54h] [bp-28h]@39
  int v150; // [sp+54h] [bp-28h]@75
  int v151; // [sp+54h] [bp-28h]@113
  int v152; // [sp+58h] [bp-24h]@17
  int v153; // [sp+58h] [bp-24h]@52
  int v154; // [sp+58h] [bp-24h]@90
  int v155; // [sp+5Ch] [bp-20h]@16
  int v156; // [sp+5Ch] [bp-20h]@51
  signed int v157; // [sp+5Ch] [bp-20h]@83
  signed int v158; // [sp+5Ch] [bp-20h]@121
  int v159; // [sp+60h] [bp-1Ch]@12
  int v160; // [sp+60h] [bp-1Ch]@47
  int v161; // [sp+60h] [bp-1Ch]@128
  int v162; // [sp+64h] [bp-18h]@2
  int v163; // [sp+68h] [bp-14h]@2
  int v164; // [sp+6Ch] [bp-10h]@2
  int v165; // [sp+70h] [bp-Ch]@2
  int v166; // [sp+74h] [bp-8h]@2
  int v167; // [sp+78h] [bp-4h]@2
  int v168; // [sp+84h] [bp+8h]@60
  int v169; // [sp+84h] [bp+8h]@136
  int v170; // [sp+88h] [bp+Ch]@60
  int v171; // [sp+88h] [bp+Ch]@60
  int v172; // [sp+88h] [bp+Ch]@66
  int v173; // [sp+88h] [bp+Ch]@136
  int v174; // [sp+88h] [bp+Ch]@136
  int v175; // [sp+88h] [bp+Ch]@142
  int v176; // [sp+8Ch] [bp+10h]@60
  int v177; // [sp+8Ch] [bp+10h]@65
  int v178; // [sp+8Ch] [bp+10h]@136
  int v179; // [sp+8Ch] [bp+10h]@141
  int v180; // [sp+90h] [bp+14h]@53

  v113 = a1;
  v114 = a2;
  v6 = sub_45281E(pClass59_global, a4 - a1, a5 - a2);
  v112 = 0;
  v111 = 0;
  v115 = v6;
  if ( dword_6BE360 != 2 )
  {
    sub_43AA99(32, pClass59_global->dword_001864 + v6, 0, v113, v114, a3, (int)&v166, (int)&v167, (int)&v165);
    sub_43AA99(32, pClass59_global->dword_001864 + v6, 0, a4, a5, a6, (int)&v163, (int)&v164, (int)&v162);
    v48 = v164 - v167;
    v47 = v162 - v165;
    v49 = v163 - v166;
    v46 = sub_452A9E(v49 * v49 + v48 * v48 + v47 * v47);
    v45 = 65536;
    if ( v46 )
      v45 = 65536 / v46;
    v50 = v163;
    v142 = v49 * v45;
    v52 = v48 * v45;
    v53 = v47 * v45;
    v51 = v166;
    v146 = v52;
    v150 = v53;
    v118 = v166;
    if ( v166 < v163 )
    {
      v122 = v163;
    }
    else
    {
      v118 = v163;
      v122 = v166;
    }
    v55 = v167;
    v54 = v164;
    v126 = v167;
    if ( v167 < v164 )
    {
      v130 = v164;
    }
    else
    {
      v126 = v164;
      v130 = v167;
    }
    v56 = v162;
    v57 = v165;
    v134 = v165;
    if ( v165 < v162 )
    {
      v138 = v162;
    }
    else
    {
      v134 = v162;
      v138 = v165;
    }
    v157 = 0;
    while ( !v112 )
    {
      if ( v157 )
      {
        v100 = v57;
        v98 = v55;
        v96 = v51;
      }
      else
      {
        v100 = v56;
        v98 = v54;
        v96 = v50;
      }
      v60 = sub_49AC17((int)byte_6BE3C8, v96, v98, v100);
      v58 = dword_6BE654;
      v59 = 116 * v60;
      v154 = 0;
      for ( i = 116 * v60; v154 < *(_WORD *)(v59 + dword_6BE654 + 12) + 2 * *(_WORD *)(v59 + dword_6BE654 + 4); ++v154 )
      {
        v61 = dword_6BE644 + 96 * *(_WORD *)(*(_DWORD *)(v59 + v58 + 16) + 2 * v154);
        if ( *(_BYTE *)(v61 + 44) & 1
          || v118 > *(_WORD *)(v61 + 82)
          || v122 < *(_WORD *)(v61 + 80)
          || v126 > *(_WORD *)(v61 + 86)
          || v130 < *(_WORD *)(v61 + 84)
          || v134 > *(_WORD *)(v61 + 90)
          || v138 < *(_WORD *)(v61 + 88)
          || (v63 = (unsigned __int64)(v142 * *(_DWORD *)(v61 + 16)) >> 16,
              v64 = (unsigned __int64)(v150 * *(_DWORD *)(v61 + 24)) >> 16,
              v65 = (unsigned __int64)(v146 * *(_DWORD *)(v61 + 20)) >> 16,
              v66 = v63 + v64 + v65 == 0,
              v62 = v63 + v64 + v65,
              v105 = v63 + v64 + v65,
              v66) )
          goto LABEL_107;
        v67 = v165 * *(_DWORD *)(v61 + 24);
        v68 = -(*(_DWORD *)(v61 + 28) + v67 + v167 * *(_DWORD *)(v61 + 20) + v166 * *(_DWORD *)(v61 + 16));
        if ( v62 <= 0 )
        {
          if ( *(_DWORD *)(v61 + 28) + v67 + v167 * *(_DWORD *)(v61 + 20) + v166 * *(_DWORD *)(v61 + 16) < 0 )
            goto LABEL_107;
        }
        else
        {
          if ( *(_DWORD *)(v61 + 28) + v67 + v167 * *(_DWORD *)(v61 + 20) + v166 * *(_DWORD *)(v61 + 16) > 0 )
            goto LABEL_107;
        }
        v69 = abs(-(*(_DWORD *)(v61 + 28) + v67 + v167 * *(_DWORD *)(v61 + 20) + v166 * *(_DWORD *)(v61 + 16))) >> 14;
        if ( v69 <= abs(v62) )
        {
          LODWORD(v70) = v68 << 16;
          HIDWORD(v70) = v68 >> 16;
          v71 = v70 / v105;
          v106 = v70 / v105;
          if ( v71 >= 0 )
          {
            if ( sub_4075DB(
                   v166 + ((signed int)(((unsigned __int64)(v106 * v142) >> 16) + 32768) >> 16),
                   v167 + ((signed int)(((unsigned __int64)(v106 * v146) >> 16) + 32768) >> 16),
                   v165 + ((signed int)(((unsigned __int64)(v106 * v150) >> 16) + 32768) >> 16),
                   v61) )
            {
              v112 = 1;
              break;
            }
          }
        }
        v59 = i;
LABEL_107:
        v58 = dword_6BE654;
      }
      ++v157;
      if ( v157 >= 2 )
        break;
      v56 = v162;
      v54 = v164;
      v50 = v163;
      v57 = v165;
      v55 = v167;
      v51 = v166;
    }
    sub_43AA99(32, v115 - pClass59_global->dword_001864, 0, v113, v114, a3, (int)&v166, (int)&v167, (int)&v165);
    sub_43AA99(32, v115 - pClass59_global->dword_001864, 0, a4, a5, a6, (int)&v163, (int)&v164, (int)&v162);
    v75 = v164 - v167;
    v74 = v162 - v165;
    v76 = v163 - v166;
    v73 = sub_452A9E(v76 * v76 + v75 * v75 + v74 * v74);
    v72 = 65536;
    if ( v73 )
      v72 = 65536 / v73;
    v77 = v163;
    v143 = v76 * v72;
    v79 = v75 * v72;
    v80 = v74 * v72;
    v78 = v166;
    v147 = v79;
    v151 = v80;
    v119 = v166;
    if ( v166 < v163 )
    {
      v123 = v163;
    }
    else
    {
      v119 = v163;
      v123 = v166;
    }
    v82 = v167;
    v81 = v164;
    v127 = v167;
    if ( v167 < v164 )
    {
      v131 = v164;
    }
    else
    {
      v127 = v164;
      v131 = v167;
    }
    v83 = v162;
    v84 = v165;
    v135 = v165;
    if ( v165 < v162 )
    {
      v139 = v162;
    }
    else
    {
      v135 = v162;
      v139 = v165;
    }
    v158 = 0;
    while ( 1 )
    {
      if ( v111 )
        return !v112 || !v111;
      if ( v158 )
      {
        v101 = v84;
        v99 = v82;
        v97 = v78;
      }
      else
      {
        v101 = v83;
        v99 = v81;
        v97 = v77;
      }
      v87 = sub_49AC17((int)byte_6BE3C8, v97, v99, v101);
      v85 = dword_6BE654;
      v86 = 116 * v87;
      v161 = 0;
      v110 = v86;
      if ( *(_WORD *)(v86 + dword_6BE654 + 12) + 2 * *(_WORD *)(v86 + dword_6BE654 + 4) > 0 )
        break;
LABEL_148:
      ++v158;
      if ( v158 >= 2 )
        return !v112 || !v111;
      v83 = v162;
      v81 = v164;
      v77 = v163;
      v84 = v165;
      v82 = v167;
      v78 = v166;
    }
    while ( 1 )
    {
      v88 = dword_6BE644 + 96 * *(_WORD *)(*(_DWORD *)(v86 + v85 + 16) + 2 * v161);
      if ( *(_BYTE *)(v88 + 44) & 1
        || v119 > *(_WORD *)(v88 + 82)
        || v123 < *(_WORD *)(v88 + 80)
        || v127 > *(_WORD *)(v88 + 86)
        || v131 < *(_WORD *)(v88 + 84)
        || v135 > *(_WORD *)(v88 + 90)
        || v139 < *(_WORD *)(v88 + 88)
        || (v169 = (unsigned __int64)(v143 * *(_DWORD *)(v88 + 16)) >> 16,
            v178 = (unsigned __int64)(v147 * *(_DWORD *)(v88 + 20)) >> 16,
            v174 = (unsigned __int64)(v151 * *(_DWORD *)(v88 + 24)) >> 16,
            v90 = v169 + v174 + v178 == 0,
            v89 = v169 + v174 + v178,
            v173 = v169 + v174 + v178,
            v90) )
        goto LABEL_145;
      v91 = v165 * *(_DWORD *)(v88 + 24);
      v92 = -(*(_DWORD *)(v88 + 28) + v91 + v167 * *(_DWORD *)(v88 + 20) + v166 * *(_DWORD *)(v88 + 16));
      if ( v89 <= 0 )
      {
        if ( *(_DWORD *)(v88 + 28) + v91 + v167 * *(_DWORD *)(v88 + 20) + v166 * *(_DWORD *)(v88 + 16) < 0 )
          goto LABEL_145;
      }
      else
      {
        if ( *(_DWORD *)(v88 + 28) + v91 + v167 * *(_DWORD *)(v88 + 20) + v166 * *(_DWORD *)(v88 + 16) > 0 )
          goto LABEL_145;
      }
      v179 = abs(-(*(_DWORD *)(v88 + 28) + v91 + v167 * *(_DWORD *)(v88 + 20) + v166 * *(_DWORD *)(v88 + 16))) >> 14;
      if ( v179 <= abs(v89) )
      {
        LODWORD(v93) = v92 << 16;
        HIDWORD(v93) = v92 >> 16;
        v94 = v93 / v173;
        v175 = v93 / v173;
        if ( v94 >= 0 )
        {
          if ( sub_4075DB(
                 v166 + ((signed int)(((unsigned __int64)(v175 * v143) >> 16) + 32768) >> 16),
                 v167 + ((signed int)(((unsigned __int64)(v175 * v147) >> 16) + 32768) >> 16),
                 v165 + ((signed int)(((unsigned __int64)(v175 * v151) >> 16) + 32768) >> 16),
                 v88) )
          {
            v111 = 1;
            goto LABEL_148;
          }
        }
      }
      v86 = v110;
LABEL_145:
      v85 = dword_6BE654;
      ++v161;
      if ( v161 >= *(_WORD *)(v86 + dword_6BE654 + 12) + 2 * *(_WORD *)(v86 + dword_6BE654 + 4) )
        goto LABEL_148;
    }
  }
  sub_43AA99(32, pClass59_global->dword_001864 + v6, 0, v113, v114, a3, (int)&v166, (int)&v167, (int)&v165);
  sub_43AA99(32, pClass59_global->dword_001864 + v6, 0, a4, a5, a6, (int)&v163, (int)&v164, (int)&v162);
  v10 = v164 - v167;
  v9 = v162 - v165;
  v11 = v163 - v166;
  v8 = sub_452A9E(v11 * v11 + v10 * v10 + v9 * v9);
  v7 = 65536;
  if ( v8 )
    v7 = 65536 / v8;
  v124 = v11 * v7;
  v13 = v7;
  v14 = v9 * v7;
  v12 = v166;
  v116 = v14;
  v120 = v10 * v13;
  v148 = v166;
  if ( v166 < v163 )
  {
    v144 = v163;
  }
  else
  {
    v148 = v163;
    v144 = v166;
  }
  v15 = v164;
  v140 = v167;
  if ( v167 < v164 )
  {
    v136 = v164;
  }
  else
  {
    v140 = v164;
    v136 = v167;
  }
  v132 = v165;
  if ( v165 < v162 )
  {
    v128 = v162;
  }
  else
  {
    v132 = v162;
    v128 = v165;
  }
  v159 = 0;
  if ( pClass51_global->uNumBModels > 0 )
  {
    v102 = 0;
    while ( 1 )
    {
      v16 = v102 + pClass51_global->pBModels + 68;
      v155 = v102 + pClass51_global->pBModels + 68;
      if ( sub_4088E9(
             v12,
             v167,
             v163,
             v15,
             *(_DWORD *)(v102 + pClass51_global->pBModels + 112),
             *(_DWORD *)(v102 + pClass51_global->pBModels + 116)) <= *(_DWORD *)(v102 + pClass51_global->pBModels + 184) + 128 )
      {
        v152 = 0;
        if ( *(_DWORD *)(v16 + 8) > 0 )
          break;
      }
LABEL_36:
      ++v159;
      v102 += 188;
      if ( v159 >= pClass51_global->uNumBModels )
        goto LABEL_37;
      v15 = v164;
      v12 = v166;
    }
    v104 = 0;
    while ( 1 )
    {
      v17 = v104 + *(_DWORD *)(v155 + 16);
      if ( v148 > *(_WORD *)(v17 + 280)
        || v144 < *(_WORD *)(v17 + 278)
        || v140 > *(_WORD *)(v17 + 284)
        || v136 < *(_WORD *)(v17 + 282)
        || v132 > *(_WORD *)(v17 + 288)
        || v128 < *(_WORD *)(v17 + 286)
        || (v19 = (unsigned __int64)(v124 * *(_DWORD *)v17) >> 16,
            v20 = (unsigned __int64)(v120 * *(_DWORD *)(v17 + 4)) >> 16,
            v21 = (unsigned __int64)(v116 * *(_DWORD *)(v17 + 8)) >> 16,
            v22 = v19 + v20 + v21 == 0,
            v18 = v19 + v20 + v21,
            v107 = v19 + v20 + v21,
            v22) )
        goto LABEL_33;
      v23 = v167 * *(_DWORD *)(v17 + 4);
      v24 = -(*(_DWORD *)(v17 + 12) + v23 + v165 * *(_DWORD *)(v17 + 8) + v166 * *(_DWORD *)v17);
      if ( v18 <= 0 )
      {
        if ( *(_DWORD *)(v17 + 12) + v23 + v165 * *(_DWORD *)(v17 + 8) + v166 * *(_DWORD *)v17 < 0 )
          goto LABEL_33;
      }
      else
      {
        if ( *(_DWORD *)(v17 + 12) + v23 + v165 * *(_DWORD *)(v17 + 8) + v166 * *(_DWORD *)v17 > 0 )
          goto LABEL_33;
      }
      v25 = abs(-(*(_DWORD *)(v17 + 12) + v23 + v165 * *(_DWORD *)(v17 + 8) + v166 * *(_DWORD *)v17)) >> 14;
      if ( v25 <= abs(v18) )
      {
        LODWORD(v26) = v24 << 16;
        HIDWORD(v26) = v24 >> 16;
        v27 = v26 / v107;
        v108 = v26 / v107;
        if ( v27 >= 0 )
        {
          if ( sub_4077F1(
                 v166 + ((signed int)(((unsigned __int64)(v108 * v124) >> 16) + 32768) >> 16),
                 v167 + ((signed int)(((unsigned __int64)(v108 * v120) >> 16) + 32768) >> 16),
                 v165 + ((signed int)(((unsigned __int64)(v108 * v116) >> 16) + 32768) >> 16),
                 v17,
                 v155) )
          {
            v112 = 1;
            goto LABEL_36;
          }
        }
      }
LABEL_33:
      ++v152;
      v104 += 308;
      if ( v152 >= *(_DWORD *)(v155 + 8) )
        goto LABEL_36;
    }
  }
LABEL_37:
  sub_43AA99(32, v115 - pClass59_global->dword_001864, 0, v113, v114, a3, (int)&v166, (int)&v167, (int)&v165);
  sub_43AA99(32, v115 - pClass59_global->dword_001864, 0, a4, a5, a6, (int)&v163, (int)&v164, (int)&v162);
  v31 = v164 - v167;
  v30 = v162 - v165;
  v32 = v163 - v166;
  v29 = sub_452A9E(v32 * v32 + v31 * v31 + v30 * v30);
  v28 = 65536;
  if ( v29 )
    v28 = 65536 / v29;
  v125 = v32 * v28;
  v34 = v28;
  v35 = v30 * v28;
  v33 = v166;
  v117 = v35;
  v121 = v31 * v34;
  v149 = v166;
  if ( v166 < v163 )
  {
    v145 = v163;
  }
  else
  {
    v149 = v163;
    v145 = v166;
  }
  v36 = v164;
  v141 = v167;
  if ( v167 < v164 )
  {
    v137 = v164;
  }
  else
  {
    v141 = v164;
    v137 = v167;
  }
  v133 = v165;
  if ( v165 < v162 )
  {
    v129 = v162;
  }
  else
  {
    v133 = v162;
    v129 = v165;
  }
  v160 = 0;
  if ( pClass51_global->uNumBModels > 0 )
  {
    v103 = 0;
    while ( 1 )
    {
      v37 = v103 + pClass51_global->pBModels + 68;
      v156 = v103 + pClass51_global->pBModels + 68;
      if ( sub_4088E9(
             v33,
             v167,
             v163,
             v36,
             *(_DWORD *)(v103 + pClass51_global->pBModels + 112),
             *(_DWORD *)(v103 + pClass51_global->pBModels + 116)) <= *(_DWORD *)(v103 + pClass51_global->pBModels + 184) + 128 )
      {
        v153 = 0;
        if ( *(_DWORD *)(v37 + 8) > 0 )
          break;
      }
LABEL_71:
      ++v160;
      v103 += 188;
      if ( v160 >= pClass51_global->uNumBModels )
        return !v112 || !v111;
      v36 = v164;
      v33 = v166;
    }
    v180 = 0;
    while ( 1 )
    {
      v38 = v180 + *(_DWORD *)(v156 + 16);
      if ( v149 > *(_WORD *)(v38 + 280)
        || v145 < *(_WORD *)(v38 + 278)
        || v141 > *(_WORD *)(v38 + 284)
        || v137 < *(_WORD *)(v38 + 282)
        || v133 > *(_WORD *)(v38 + 288)
        || v129 < *(_WORD *)(v38 + 286)
        || (v168 = (unsigned __int64)(v125 * *(_DWORD *)v38) >> 16,
            v171 = (unsigned __int64)(v121 * *(_DWORD *)(v38 + 4)) >> 16,
            v176 = (unsigned __int64)(v117 * *(_DWORD *)(v38 + 8)) >> 16,
            v40 = v168 + v171 + v176 == 0,
            v39 = v168 + v171 + v176,
            v170 = v168 + v171 + v176,
            v40) )
        goto LABEL_68;
      v41 = v167 * *(_DWORD *)(v38 + 4);
      v42 = -(*(_DWORD *)(v38 + 12) + v41 + v165 * *(_DWORD *)(v38 + 8) + v166 * *(_DWORD *)v38);
      if ( v39 <= 0 )
      {
        if ( *(_DWORD *)(v38 + 12) + v41 + v165 * *(_DWORD *)(v38 + 8) + v166 * *(_DWORD *)v38 < 0 )
          goto LABEL_68;
      }
      else
      {
        if ( *(_DWORD *)(v38 + 12) + v41 + v165 * *(_DWORD *)(v38 + 8) + v166 * *(_DWORD *)v38 > 0 )
          goto LABEL_68;
      }
      v177 = abs(-(*(_DWORD *)(v38 + 12) + v41 + v165 * *(_DWORD *)(v38 + 8) + v166 * *(_DWORD *)v38)) >> 14;
      if ( v177 <= abs(v39) )
      {
        LODWORD(v43) = v42 << 16;
        HIDWORD(v43) = v42 >> 16;
        v44 = v43 / v170;
        v172 = v43 / v170;
        if ( v44 >= 0 )
        {
          if ( sub_4077F1(
                 v166 + ((signed int)(((unsigned __int64)(v172 * v125) >> 16) + 32768) >> 16),
                 v167 + ((signed int)(((unsigned __int64)(v172 * v121) >> 16) + 32768) >> 16),
                 v165 + ((signed int)(((unsigned __int64)(v172 * v117) >> 16) + 32768) >> 16),
                 v38,
                 v156) )
          {
            v111 = 1;
            goto LABEL_71;
          }
        }
      }
LABEL_68:
      ++v153;
      v180 += 308;
      if ( v153 >= *(_DWORD *)(v156 + 8) )
        goto LABEL_71;
    }
  }
  return !v112 || !v111;
}

//----- (00459C82) --------------------------------------------------------
int sub_459C82(int *_this, int a2)
{
  return _this[a2 + 3];
}

//----- (00464866) --------------------------------------------------------
int __fastcall sub_464866(int a1, int a2)
{
  int v3; // esi@1
  signed __int64 v6; // qax@8
  int v10; // [sp+20h] [bp-4h]@1
 unsigned char pLevelName[128],
               pLevelType[32];
 int i;

  v3 = a2;
  v10 = a1;
  sub_464479();

 pClass58_global = malloc(sizeof(struct class58));
 memset(pClass58_global, 0, sizeof(struct class58));
 class58_sub_49B525(pClass58_global, 0);

 pLoadingUI = malloc(sizeof(struct class56));
 memset(pLoadingUI, 0, sizeof(struct class56));
 LevelLoadingUI_Initialize(pLoadingUI, a2);

 sscanf(Str1, "%[^.].%s", pLevelName, pLevelType);
 Level_LoadEvtAndStr(pLevelName);
 LoadLevel_InitializeLevelEvt();


 for (i = 0; i < 1000; ++i)
   array_665230[i].uObjectDescriptionID = 0;


 uLevelMapStatsID = CMapStats_FindLocation(pMapStats, Str1);
  byte_6BE3C4 = 0;

  pGame->dword_000E24 &= 0xFFFFFFF7;

  if ( !strcmpi(Str1, "out15.odm") )
  {
    byte_6BE3C4 = 1;
    pGame->dword_000E24 |= 8;
  }

  dword_ACD6AC = 0;
  if (strcmpi(pLevelType, "blv"))
    PrepareToLoadODM(v10, 0);
  else
    sub_460A78(v10);

  AudioPlayer_sub_4AC041(pAudioPlayer);
  sub_461103();
  if (!strcmpi(Str1, "d11.blv") || !strcmpi(Str1, "d10.blv"))
  {
   for (i = 0; i < uNumActors; ++i)
   {
     pActors[i].byte_00002A[12] = 0;
     pActors[i].byte_00002A[15] = 0;
     pActors[i].dword_000074 = 0;
   }
  }
  LODWORD(v6) = &pActors[uNumActors].byte_00002A[15];

  dword_5C35C4 = 0;
  sub_443FDC(v6);
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  LevelLoadingUI_Release(pLoadingUI);
  return _flushall();
}

//----- (00448B67) --------------------------------------------------------
void __thiscall sub_448B67(void *this)
{
  int v1; // ebp@1
  unsigned int v2; // ebx@4
  unsigned int v3; // edi@4
  _UNKNOWN *v4; // esi@6
  __int16 v5; // ax@8
  int v6; // ecx@10
  unsigned int v7; // ebp@12
  int v8; // eax@16
  int v9; // eax@19
  int v10; // edx@20
  signed __int64 v11; // qax@20
  int v12; // ecx@24
  int v13; // [sp+Ch] [bp-10h]@5
  unsigned int v14; // [sp+10h] [bp-Ch]@4

  v1 = 0;
  if (!pClass24_global->dword_000004)
  {
    if ( this )
      dword_5773C0 = 0;
    v2 = pParty_global->qword_00002C;
    v3 = HIDWORD(pParty_global->qword_00002C);
    v14 = (pParty_global->qword_00002C - qword_5773B8) >> 7;
    if ( v14 )
    {
      qword_5773B8 = pParty_global->qword_00002C;
      v13 = 0;
      if ( dword_5B65C8 > 0 )
      {
        v4 = &unk_5B5934;
        while ( 1 )
        {
          v5 = *(_WORD *)v4;
          if ( *(_WORD *)v4 != (_WORD)v1 )
            break;
          v7 = *((_DWORD *)v4 - 2);
          if ( v7 <= v3 && (v7 < v3 || *((_DWORD *)v4 - 3) <= v2) )
          {
            if ( *((_WORD *)v4 + 2) )
            {
              v8 = 29030400;
            }
            else
            {
              if ( *((_WORD *)v4 + 3) )
              {
                v8 = 2419200;
              }
              else
              {
                v9 = -(*((_WORD *)v4 + 4) != 0);
                v8 = (v9 & 0x7E900) + 86400;
              }
            }
            v11 = *((_DWORD *)v4 - 3) + (signed __int64)((double)((signed __int64)v8 << 7) * 0.03333333507180214);
            v10 = v7 + HIDWORD(v11);
            *((_DWORD *)v4 - 3) = v11;
            *((_DWORD *)v4 - 2) = v10;
            if ( v10 <= v3 )
            {
              if ( v10 < v3 || *((_DWORD *)v4 - 3) < v2 )
              {
                *((_DWORD *)v4 - 3) = v2;
                *((_DWORD *)v4 - 2) = v3;
              }
            }
            v12 = *((_WORD *)v4 - 2);
            dword_597F18 = *((_WORD *)v4 - 1);
            sub_44684A(v12, 0, 1);
            dword_597F18 = 0;
LABEL_25:
            v3 = HIDWORD(pParty_global->qword_00002C);
            v2 = pParty_global->qword_00002C;
          }
LABEL_26:
          ++v13;
          v4 = (char *)v4 + 32;
          if ( v13 >= dword_5B65C8 )
            return;
          v1 = 0;
        }
        if ( v14 < v5 )
        {
          *(_WORD *)v4 = v5 - v14;
          goto LABEL_26;
        }
        v6 = *((_WORD *)v4 - 2);
        *(_WORD *)v4 = *((_WORD *)v4 + 1);
        dword_597F18 = *((_WORD *)v4 - 1);
        sub_44684A(v6, 0, 1);
        dword_597F18 = v1;
        goto LABEL_25;
      }
    }
  }
}


//----- (004086E9) --------------------------------------------------------
char __thiscall sub_4086E9(int this)
{
  int v1; // edi@1
  int v2; // esi@1
  signed int v3; // ebx@2
  int v4; // eax@6
  int v5; // edx@6

  v2 = this;
  v1 = 0;
  if ( !*(_DWORD *)(this + 672) )
  {
    v3 = 0;
    if ( *(_BYTE *)(this + 54) )
    {
      do
      {
        ++v3;
        v1 += rand() % *(_BYTE *)(v2 + 55) + 1;
      }
      while ( v3 < *(_BYTE *)(v2 + 54) );
      if ( v1 )
      {
        *(_DWORD *)(v2 + 672) = 197;
        *(_DWORD *)(v2 + 684) = v1;
      }
    }
  }
  v5 = rand() % 100;
  v4 = *(_BYTE *)(v2 + 53);
  if ( v5 < v4 )
  {
    LOBYTE(v4) = *(_BYTE *)(v2 + 56);
    if ( (_BYTE)v4 )
      LOBYTE(v4) = sub_456620(pClass40, (unsigned __int8)v4, *(_BYTE *)(v2 + 57), v2 + 636);
  }
  *(_BYTE *)(v2 + 38) |= 0x80u;
  return v4;
}

//----- (00408896) --------------------------------------------------------
void __cdecl sub_408896()
{
  signed int result; // eax@7
 int i;

  for (i = 0; i < 1000; ++i)
  {
   if (array_665230[i].uObjectDescriptionID)
   {
    if (array_665230[i].byte_000012[8] & 8 ||
        pObjectDescriptionList->pDescriptions[array_665230[i].uObjectDescriptionID].byte_000026 & 0x10)
      sub_42F933(i);
    }
  }

 for (i = 0; i < 100; ++i)
   array_5118E8[i].word_00000C = 0;
}

//----- (004088E9) --------------------------------------------------------
signed int __fastcall sub_4088E9(int a1, int a2, int a3, int a4, int a5, int a6)
{
  signed int result; // eax@1
  int v7; // edi@1
  int v8; // esi@1
  int v9; // eax@1
  int v10; // [sp+Ch] [bp-4h]@1
  int v11; // [sp+18h] [bp+8h]@1

  v8 = a1;
  v10 = a2;
  v7 = a3 - a1;
  v11 = abs(a3 - a1);
  v9 = abs(a4 - v10);
  result = sub_452A9E(v11 * v11 + v9 * v9);
  if ( result )
    result = abs((v7 * (v10 - a6) - (a4 - v10) * (v8 - a5)) / result);
  return result;
}

//----- (004089C7) --------------------------------------------------------
bool __thiscall sub_4089C7(int this)
{
  signed int v1; // esi@1
  __int16 v2; // ax@3

  v1 = 0;
  if ( *(_QWORD *)(this + 292) > 0i64 )
    v1 = 1;
  v2 = *(_WORD *)(this + 176);
  return (v1 | v2 == 4 | v2 == 5 | v2 == 11 | v2 == 17 | v2 == 19) != 0;
}

//----- (00408A27) --------------------------------------------------------
int __thiscall sub_408A27(void *this)
{
  signed int v1; // ebx@1
  int v2; // ebp@1
  void *v3; // esi@1
  int v4; // eax@1
  int v5; // edi@2
  int v6; // eax@3
  int v8; // [sp+Ch] [bp-4h]@1

  v3 = this;
  v4 = sub_450DA3();
  v2 = 0;
  v1 = 0;
  *(_DWORD *)v3 = 0;
  v8 = v4;
  if ( (signed int)uNumActors > 0 )
  {
    v5 = (int)pActors;
    do
    {
      v6 = *(_DWORD *)(v5 + 36);
      if ( (v6 & 0x100000) == v8 )
      {
        ++*(_DWORD *)v3;
        if ( sub_4089C7(v5) == 1 )
          ++v2;
      }
      ++v1;
      v5 += 836;
    }
    while ( v1 < (signed int)uNumActors );
  }
  return v2;
}

//----- (00408A7E) --------------------------------------------------------
int __fastcall sub_408A7E(int a1, int a2)
{
  signed int v2; // ebx@1
  int v3; // esi@1
  int v4; // edi@2
  int v5; // eax@3
  int v7; // [sp+8h] [bp-Ch]@1
  int v8; // [sp+Ch] [bp-8h]@1
  int v9; // [sp+10h] [bp-4h]@1

  v7 = a2;
  v3 = a1;
  v2 = 0;
  v8 = sub_450DA3();
  *(_DWORD *)v3 = 0;
  v9 = 0;
  if ( (signed int)uNumActors > 0 )
  {
    v4 = (int)word_5FF1B8;
    do
    {
      v5 = *(_DWORD *)(v4 - 60);
      if ( (v5 & 0x100000) == v8 )
      {
        if ( *(_WORD *)v4 - 1 == v7 )
        {
          ++*(_DWORD *)v3;
          if ( sub_4089C7(v4 - 96) == 1 )
            ++v9;
        }
      }
      ++v2;
      v4 += 836;
    }
    while ( v2 < (signed int)uNumActors );
  }
  return v9;
}

//----- (00408AE7) --------------------------------------------------------
int __fastcall sub_408AE7(int a1, int a2)
{
  signed int v2; // ebx@1
  int v3; // esi@1
  int v4; // edi@2
  int v5; // eax@3
  int v7; // [sp+8h] [bp-Ch]@1
  int v8; // [sp+Ch] [bp-8h]@1
  int v9; // [sp+10h] [bp-4h]@1

  v7 = a2;
  v3 = a1;
  v2 = 0;
  v8 = sub_450DA3();
  *(_DWORD *)v3 = 0;
  v9 = 0;
  if ( (signed int)uNumActors > 0 )
  {
    v4 = (int)dword_5FF41C;
    do
    {
      v5 = *(_DWORD *)(v4 - 672);
      if ( (v5 & 0x100000) == v8 )
      {
        if ( *(_DWORD *)v4 == v7 )
        {
          ++*(_DWORD *)v3;
          if ( sub_4089C7(v4 - 708) == 1 )
            ++v9;
        }
      }
      ++v2;
      v4 += 836;
    }
    while ( v2 < (signed int)uNumActors );
  }
  return v9;
}

//----- (00486A28) --------------------------------------------------------
void AllocateDrawBuffers(void *this)
{
  if ( !this || !pSpansBuf )
  {
    ReleaseDrawBuffers();

    pSpansBuf = class23_AllocatedNamedBuffer(class23_instance, pSpansBuf, 300000, "SPANS");
    memset(pSpansBuf, 0, 0x493E0);

    pEdgesBuf = class23_AllocatedNamedBuffer(class23_instance, pEdgesBuf, 312000, "EDGES");
    memset(pEdgesBuf, 0, 0x4C2C0);

    pSurfsBuf = class23_AllocatedNamedBuffer(class23_instance, pSurfsBuf, 72000, "SURFS");
    memset(pSurfsBuf, 0, 0x11940);

    pNewEdgesBuf = class23_AllocatedNamedBuffer(class23_instance, pNewEdgesBuf, 24960, "NEWEDGES");
    memset(pNewEdgesBuf, 0, 0x6180);
  }
}

//----- (00408B54) --------------------------------------------------------
signed int __fastcall sub_408B54(int a1, int a2)
{
  signed int v2; // ebx@1
  int v3; // edi@1
  int v4; // esi@1
  int v5; // eax@1
  int v6; // edx@1

  v3 = a2;
  v4 = a1;
  v5 = sub_450DA3();
  v2 = 0;
  *(_DWORD *)v4 = 0;
  v6 = *(int *)pActors[v3].byte_000024;
  if ( (v6 & 0x100000) == v5 )
  {
    *(_DWORD *)v4 = 1;
    if ( sub_4089C7((int)((char *)pActors + 836 * v3)) == 1 )
      v2 = 1;
  }
  return v2;
}

//----- (0046082C) --------------------------------------------------------
int __cdecl sub_46082C()
{
 pClass17_Games_LOD = malloc(sizeof(struct class17));
 class17_ctor(pClass17_Games_LOD);
 class17_AllocateSubidexAndIOBuffer(pClass17_Games_LOD, 300, 0);

 if (class17_LoadLOD_Games(pClass17_Games_LOD, "data\\games.lod", 1))
 {
  pClass17_New_LOD = malloc(sizeof(struct class17));
  class17_ctor(pClass17_New_LOD);
  class17_AllocateSubidexAndIOBuffer(pClass17_New_LOD, 300, 100000);
  return true;
 }
 return false;;
}

//----- (0049107D) --------------------------------------------------------
int sub_49107D(struct Player *_this)
{
  int v1; // al@1
  int v2; // ecx@1
  int v4; // eax@3
  signed int v6; // [sp-4h] [bp-4h]@2

  v1 = sub_48F882(_this, 24);
  v2 = v1 & 0x3F;
  if ( v1 & 0x100 )
  {
    v6 = 5;
  }
  else
  {
    if ( v1 >= 0 )
    {
      v4 = ((v1 & 0x40) != 0) + 1;
      return v2 * v4;
    }
    v6 = 3;
  }
  v4 = v6;
  return v2 * v4;
}

//----- (00408BB4) --------------------------------------------------------
char __fastcall sub_408BB4(int a1, signed int a2)
{
  int v2; // eax@3
  int v3; // eax@4
  int v4; // ebx@4
  int v5; // eax@5
  int v6; // ebx@5
  signed int v7; // ebx@8
  int v8; // esi@8
  int v9; // edi@9
  int v10; // eax@9
  int v11; // eax@11
  int v12; // eax@11
  int v13; // ecx@18
  int v14; // eax@20
  char v15; // dl@20
  char *v16; // ecx@20
  char v17; // bl@20
  char v18; // dl@24
  int v19; // edx@25
  int v20; // edx@27
  char v21; // dl@31
  int v22; // edx@32
  char v23; // dl@35
  char v24; // dl@39
  int v25; // edx@40
  char v26; // dl@45
  int v27; // edx@46
  char v28; // dl@52
  int v29; // edx@53
  char v30; // dl@58
  int v31; // edx@59
  char v32; // dl@64
  int v33; // edx@65
  char v34; // dl@70
  int v35; // edx@71
  char v36; // dl@76
  int v37; // edx@77
  char v38; // dl@82
  int v39; // edx@83
  char v40; // dl@86
  char v41; // dl@90
  char v42; // dl@93
  int v43; // edi@93
  int v44; // esi@93
  char v45; // bl@94
  int v46; // esi@95
  char v47; // dl@99
  char v48; // dl@103
  char v49; // dl@107
  char v50; // dl@111
  char v51; // dl@115
  char *v52; // edx@116
  char *v53; // ebx@116
  int v54; // edx@124
  int v55; // esi@124
  int v56; // edx@127
  int v57; // esi@130
  int v58; // edi@138
  int l; // esi@138
  int v60; // eax@140
  int v61; // ecx@142
  int v62; // edx@142
  int v63; // ebx@142
  int v65; // eax@145
  int v66; // esi@146
  int v67; // ecx@168
  int v68; // eax@170
  char v69; // dl@170
  char *v70; // ecx@170
  char v71; // bl@170
  char v72; // dl@174
  int v73; // edx@175
  int v74; // edx@177
  char v75; // dl@181
  char v76; // dl@184
  char v77; // dl@188
  int v78; // edx@189
  char v79; // dl@194
  char v80; // dl@200
  int v81; // edx@201
  char v82; // dl@206
  int v83; // edx@207
  char v84; // dl@212
  int v85; // edx@213
  char v86; // dl@218
  int v87; // edx@219
  char v88; // dl@224
  int v89; // edx@225
  char v90; // dl@230
  int v91; // edx@231
  char v92; // dl@234
  int v93; // edx@235
  char v94; // dl@238
  int v95; // edx@239
  char v96; // dl@241
  int v97; // esi@241
  int v98; // esi@241
  char v99; // bl@242
  int v100; // edi@243
  int v101; // edx@245
  int v102; // edi@246
  char v103; // dl@247
  int v104; // edx@248
  char v105; // dl@251
  int v106; // edx@252
  char v107; // dl@255
  int v108; // edx@256
  char v109; // dl@259
  int v110; // edx@260
  char v111; // dl@263
  char *v112; // edx@264
  char *v113; // ebx@264
  int v114; // edx@272
  int v115; // esi@272
  int v116; // edx@275
  int v117; // esi@278
  int v118; // edi@286
  int j; // esi@286
  int v120; // eax@288
  int v121; // ecx@290
  int v122; // edx@290
  int v123; // ebx@290
  int v125; // eax@293
  int v126; // esi@294
  int v128; // [sp-28h] [bp-28h]@130
  int v129; // [sp-28h] [bp-28h]@278
  int k; // [sp-24h] [bp-24h]@18
  int i; // [sp-24h] [bp-24h]@168
  int v132; // [sp-20h] [bp-20h]@4
  int v133; // [sp-20h] [bp-20h]@5
  int v134; // [sp-1Ch] [bp-1Ch]@17
  int v135; // [sp-1Ch] [bp-1Ch]@140
  int v136; // [sp-1Ch] [bp-1Ch]@167
  int v137; // [sp-1Ch] [bp-1Ch]@288
  int v138; // [sp-18h] [bp-18h]@4
  int v139; // [sp-18h] [bp-18h]@5
  int v140; // [sp-14h] [bp-14h]@93
  int v141; // [sp-14h] [bp-14h]@130
  signed int v142; // [sp-14h] [bp-14h]@155
  int v143; // [sp-14h] [bp-14h]@241
  int v144; // [sp-14h] [bp-14h]@278
  signed int v145; // [sp-14h] [bp-14h]@303
  char *v146; // [sp-10h] [bp-10h]@4
  char *v147; // [sp-10h] [bp-10h]@5
  char *v148; // [sp-Ch] [bp-Ch]@4
  char *v149; // [sp-Ch] [bp-Ch]@5
  char v150; // [sp-8h] [bp-8h]@35
  char v151; // [sp-8h] [bp-8h]@184
  char v152; // [sp-5h] [bp-5h]@20
  char v153; // [sp-5h] [bp-5h]@170

  byte_4FAA00 = 1;
  if ( dword_4DF3A4 )
  {
    if ( dword_4DF3A4 != 1 )
    {
      v2 = dword_4DF3A4 - 2;
      if ( dword_4DF3A4 != 2 )
        return v2;
      v4 = a1;
      v148 = &byte_505708[188 * a1];
      v132 = a1;
      v146 = &byte_505708[188 * (a1 + 1) % 2];
      v138 = sub_40BB49(a1);
      v3 = 0;
      do
      {
        if ( v3 >= v138 )
        {
          dword_4FA9B0[2 * v3] = -1;
          dword_4FA9B4[2 * v3] = -9999;
        }
        else
        {
          dword_4FA9B0[2 * v3] = v3;
          dword_4FA9B4[2 * v3] = 0;
        }
        ++v3;
      }
      while ( v3 < 10 );
      v136 = 0;
      if ( v138 > 0 )
      {
        v67 = 47 * v4;
        for ( i = 47 * v4; ; v67 = i )
        {
          v71 = 99;
          v68 = 8 * v136;
          v70 = &aBrickShortage[108 * dword_50574C[v67 + dword_4FA9B0[2 * v136]]];
          v69 = v70[58];
          v153 = v70[58];
          if ( *((_DWORD *)v148 + 9) >= 10 )
          {
            if ( v69 == 99 || v70[76] == 99 || v70[87] == 99 || (v75 = v70[105], v75 == 99) )
              v74 = 5 * (*((_DWORD *)v146 + 9) - *((_DWORD *)v148 + 9));
            else
              v74 = 5 * (v153 + v70[76] + v70[87] + v75);
          }
          else
          {
            if ( v69 == 99 || v70[76] == 99 || v70[87] == 99 || (v72 = v70[105], v72 == 99) )
              v73 = 5 * (*((_DWORD *)v146 + 9) - *((_DWORD *)v148 + 9));
            else
              v73 = 5 * (v153 + v70[76] + v70[87] + v72);
            v74 = 4 * v73;
          }
          *(int *)((char *)dword_4FA9B4 + v68) += v74;
          v76 = v70[57];
          v151 = v70[57];
          if ( *((_DWORD *)v148 + 10) >= 10 )
          {
            if ( v76 == 99 || v70[75] == 99 || v70[86] == 99 || (v79 = v70[104], v79 == 99) )
              v78 = *((_DWORD *)v146 + 10) - *((_DWORD *)v148 + 10);
            else
              v78 = v151 + v70[75] + v70[86] + v79;
          }
          else
          {
            if ( v76 == 99 || v70[75] == 99 || v70[86] == 99 || (v77 = v70[104], v77 == 99) )
              v78 = 5 * (*((_DWORD *)v146 + 10) - *((_DWORD *)v148 + 10));
            else
              v78 = 5 * (v151 + v70[75] + v70[86] + v77);
          }
          *(int *)((char *)dword_4FA9B4 + v68) += v78;
          *(int *)((char *)dword_4FA9B4 + v68) += 7 * (v70[56] + v70[74] + v70[85] + v70[103]);
          if ( v70[50] == 99 || v70[68] == 99 || v70[79] == 99 || (v80 = v70[97], v80 == 99) )
            v81 = 5 * (*((_DWORD *)v146 + 11) - *((_DWORD *)v148 + 11));
          else
            v81 = 5 * (v70[50] + v70[68] + v70[79] + v80);
          *(int *)((char *)dword_4FA9B4 + v68) += 8 * v81;
          if ( v70[51] == 99 || v70[69] == 99 || v70[80] == 99 || (v82 = v70[98], v82 == 99) )
            v83 = 5 * (*((_DWORD *)v146 + 12) - *((_DWORD *)v148 + 12));
          else
            v83 = 5 * (v70[51] + v70[69] + v70[80] + v82);
          *(int *)((char *)dword_4FA9B4 + v68) += 8 * v83;
          if ( v70[52] == 99 || v70[70] == 99 || v70[81] == 99 || (v84 = v70[99], v84 == 99) )
            v85 = 5 * (*((_DWORD *)v146 + 13) - *((_DWORD *)v148 + 13));
          else
            v85 = 5 * (v70[52] + v70[70] + v70[81] + v84);
          *(int *)((char *)dword_4FA9B4 + v68) += 8 * v85;
          if ( v70[53] == 99 || v70[71] == 99 || v70[82] == 99 || (v86 = v70[100], v86 == 99) )
            v87 = *((_DWORD *)v146 + 14) - *((_DWORD *)v148 + 14);
          else
            v87 = v70[53] + v70[71] + v70[82] + v86;
          *(int *)((char *)dword_4FA9B4 + v68) += 2 * v87;
          if ( v70[54] == 99 || v70[72] == 99 || v70[83] == 99 || (v88 = v70[101], v88 == 99) )
            v89 = *((_DWORD *)v146 + 15) - *((_DWORD *)v148 + 15);
          else
            v89 = v70[54] + v70[72] + v70[83] + v88;
          *(int *)((char *)dword_4FA9B4 + v68) += 2 * v89;
          if ( v70[55] == 99 || v70[73] == 99 || v70[84] == 99 || (v90 = v70[102], v90 == 99) )
            v91 = *((_DWORD *)v146 + 16) - *((_DWORD *)v148 + 16);
          else
            v91 = v70[55] + v70[73] + v70[84] + v90;
          *(int *)((char *)dword_4FA9B4 + v68) += 2 * v91;
          if ( v70[67] == 99 || (v92 = v70[96], v92 == 99) )
            v93 = 10 * (*((_DWORD *)v148 + 9) - *((_DWORD *)v146 + 9));
          else
            v93 = -10 * (v70[67] + v92);
          *(int *)((char *)dword_4FA9B4 + v68) += v93;
          if ( v70[66] == 99 || (v94 = v70[95], v94 == 99) )
            v95 = 3 * (*((_DWORD *)v148 + 10) - *((_DWORD *)v146 + 10));
          else
            v95 = -3 * (v70[66] + v94);
          *(int *)((char *)dword_4FA9B4 + v68) += v95;
          v98 = v70[65];
          v143 = v98;
          v96 = v70[59];
          *(int *)((char *)dword_4FA9B4 + v68) += -7 * (v70[94] + v98);
          v97 = *(int *)((char *)dword_4FA9B4 + v68);
          if ( v96 == 99 )
            goto LABEL_245;
          v99 = v70[88];
          if ( v99 == 99 )
          {
            v71 = 99;
LABEL_245:
            v101 = *((_DWORD *)v148 + 11) - *((_DWORD *)v146 + 11);
            *(int *)((char *)dword_4FA9B4 + v68) = v97 + 4 * v101 + v101;
            goto LABEL_246;
          }
          v100 = v96 + v99;
          v71 = 99;
          *(int *)((char *)dword_4FA9B4 + v68) = v97 - 5 * v100;
LABEL_246:
          v102 = v143;
          if ( v70[60] == v71 || (v103 = v70[89], v103 == v71) )
            v104 = 5 * (*((_DWORD *)v148 + 12) - *((_DWORD *)v146 + 12));
          else
            v104 = -5 * (v70[60] + v103);
          *(int *)((char *)dword_4FA9B4 + v68) += v104;
          if ( v70[61] == v71 || (v105 = v70[90], v105 == v71) )
            v106 = 5 * (*((_DWORD *)v148 + 13) - *((_DWORD *)v146 + 13));
          else
            v106 = -5 * (v70[61] + v105);
          *(int *)((char *)dword_4FA9B4 + v68) += v106;
          if ( v70[62] == v71 || (v107 = v70[91], v107 == v71) )
            v108 = *((_DWORD *)v148 + 14) - *((_DWORD *)v146 + 14);
          else
            v108 = -(v70[62] + v107);
          *(int *)((char *)dword_4FA9B4 + v68) += 2 * v108;
          if ( v70[63] == v71 || (v109 = v70[92], v109 == v71) )
            v110 = *((_DWORD *)v148 + 15) - *((_DWORD *)v146 + 15);
          else
            v110 = -(v70[63] + v109);
          *(int *)((char *)dword_4FA9B4 + v68) += 2 * v110;
          if ( v70[64] == v71 || (v111 = v70[93], v111 == v71) )
          {
            v112 = v148;
            v113 = v146;
            *(int *)((char *)dword_4FA9B4 + v68) += 2 * (*((_DWORD *)v148 + 16) - *((_DWORD *)v146 + 16));
          }
          else
          {
            v113 = v146;
            *(int *)((char *)dword_4FA9B4 + v68) += -2 * (v70[64] + v111);
            v112 = v148;
          }
          if ( v70[48] || v70[77] )
            *(int *)((char *)dword_4FA9B4 + v68) *= 10;
          if ( (unsigned __int8)v70[36] == 1 )
          {
            v115 = v70[40];
            v114 = *((_DWORD *)v112 + 14);
          }
          else
          {
            if ( (unsigned __int8)v70[36] == 2 )
            {
              v115 = v70[41];
              v114 = *((_DWORD *)v112 + 15);
            }
            else
            {
              if ( (unsigned __int8)v70[36] != 3 )
                goto LABEL_278;
              v115 = v70[42];
              v114 = *((_DWORD *)v112 + 16);
            }
          }
          v116 = v114 - v115;
          if ( v116 > 3 )
            v116 = 3;
          *(int *)((char *)dword_4FA9B4 + v68) += 5 * v116;
LABEL_278:
          v117 = v70[96];
          v144 = *((_DWORD *)v113 + 9);
          v129 = v70[67];
          if ( v144 <= v117 + v129 )
            *(int *)((char *)dword_4FA9B4 + v68) += 9999;
          v145 = *((_DWORD *)v113 + 10) + v144;
          if ( v145 <= v117 + v129 + v70[94] + v70[95] + v102 + v70[66] )
            *(int *)((char *)dword_4FA9B4 + v68) += 9999;
          if ( v70[87] + v70[105] + *((_DWORD *)v148 + 9) + (signed int)v70[76] + v153 >= dword_4E1884 )
            *(int *)((char *)dword_4FA9B4 + v68) += 9999;
          ++v136;
          if ( v136 >= v138 )
          {
            v4 = v132;
            break;
          }
        }
      }
      v118 = v138 - 1;
      for ( j = v138 - 1; j >= 0; --j )
      {
        v145 = 0;
        if ( j > 0 )
        {
          v120 = (int)dword_4FA9B0;
          v137 = j;
          v145 = j;
          do
          {
            if ( *(_DWORD *)(v120 + 4) < *(_DWORD *)(v120 + 12) )
            {
              v121 = *(_DWORD *)v120;
              v122 = *(_DWORD *)(v120 + 4);
              *(_DWORD *)v120 = *(_DWORD *)(v120 + 8);
              v123 = *(_DWORD *)(v120 + 12);
              *(_DWORD *)(v120 + 8) = v121;
              *(_DWORD *)(v120 + 4) = v123;
              v4 = v132;
              *(_DWORD *)(v120 + 12) = v122;
            }
            v120 += 8;
          }
          while ( v137-- != 1 );
        }
      }
      v125 = v138 - 1;
      if ( byte_4FAA77 )
      {
        if ( v118 >= 0 )
        {
          while ( !byte_4DF3D3[108 * dword_50574C[47 * v4 + dword_4FA9B0[2 * v125]]] )
          {
            --v125;
            if ( v125 < 0 )
              goto LABEL_303;
          }
          v145 = dword_4FA9B0[2 * v125];
        }
      }
      else
      {
        v126 = 0;
        if ( v118 >= 0 )
        {
          while ( !byte_4DF3D3[108 * dword_50574C[47 * v4 + dword_4FA9B0[2 * v125]]] )
          {
            --v125;
            if ( v125 < 0 )
              goto LABEL_299;
          }
          v145 = dword_4FA9B0[2 * v125];
        }
LABEL_299:
        if ( v138 > 0 )
        {
          while ( !sub_40BF15(v4, dword_4FA9B0[2 * v126]) || dword_4FA9B4[2 * v126] < 0 )
          {
            ++v126;
            if ( v126 >= v138 )
              goto LABEL_303;
          }
          LOBYTE(v2) = sub_40BE0E(v4, dword_4FA9B0[2 * v126]);
          return v2;
        }
      }
LABEL_303:
      LOBYTE(v2) = sub_40BCFB(v4, v145);
      return v2;
    }
    v6 = a1;
    v149 = &byte_505708[188 * a1];
    v133 = a1;
    v147 = &byte_505708[188 * (a1 + 1) % 2];
    v139 = sub_40BB49(a1);
    v5 = 0;
    do
    {
      if ( v5 >= v139 )
      {
        dword_4FA9B0[2 * v5] = -1;
        dword_4FA9B4[2 * v5] = -9999;
      }
      else
      {
        dword_4FA9B0[2 * v5] = v5;
        dword_4FA9B4[2 * v5] = 0;
      }
      ++v5;
    }
    while ( v5 < 10 );
    v134 = 0;
    if ( v139 > 0 )
    {
      v13 = 47 * v6;
      for ( k = 47 * v6; ; v13 = k )
      {
        v17 = 99;
        v14 = 8 * v134;
        v16 = &aBrickShortage[108 * dword_50574C[v13 + dword_4FA9B0[2 * v134]]];
        v15 = v16[58];
        v152 = v16[58];
        if ( *((_DWORD *)v149 + 9) >= 10 )
        {
          if ( v15 == 99 || v16[76] == 99 || v16[87] == 99 || (v21 = v16[105], v21 == 99) )
            v22 = 5 * (*((_DWORD *)v147 + 9) - *((_DWORD *)v149 + 9));
          else
            v22 = 5 * (v152 + v16[76] + v16[87] + v21);
          v20 = 2 * v22;
        }
        else
        {
          if ( v15 == 99 || v16[76] == 99 || v16[87] == 99 || (v18 = v16[105], v18 == 99) )
            v19 = 5 * (*((_DWORD *)v147 + 9) - *((_DWORD *)v149 + 9));
          else
            v19 = 5 * (v152 + v16[76] + v16[87] + v18);
          v20 = 4 * v19;
        }
        *(int *)((char *)dword_4FA9B4 + v14) += v20;
        v23 = v16[57];
        v150 = v16[57];
        if ( *((_DWORD *)v149 + 10) >= 10 )
        {
          if ( v23 == 99 || v16[75] == 99 || v16[86] == 99 || (v26 = v16[104], v26 == 99) )
            v27 = *((_DWORD *)v147 + 10) - *((_DWORD *)v149 + 10);
          else
            v27 = v150 + v16[75] + v16[86] + v26;
          v25 = 2 * v27;
        }
        else
        {
          if ( v23 == 99 || v16[75] == 99 || v16[86] == 99 || (v24 = v16[104], v24 == 99) )
            v25 = 5 * (*((_DWORD *)v147 + 10) - *((_DWORD *)v149 + 10));
          else
            v25 = 5 * (v150 + v16[75] + v16[86] + v24);
        }
        *(int *)((char *)dword_4FA9B4 + v14) += v25;
        *(int *)((char *)dword_4FA9B4 + v14) += 7 * (v16[56] + v16[74] + v16[85] + v16[103]);
        if ( v16[50] == 99 || v16[68] == 99 || v16[79] == 99 || (v28 = v16[97], v28 == 99) )
          v29 = 5 * (*((_DWORD *)v147 + 11) - *((_DWORD *)v149 + 11));
        else
          v29 = 5 * (v16[50] + v16[68] + v16[79] + v28);
        *(int *)((char *)dword_4FA9B4 + v14) += 8 * v29;
        if ( v16[51] == 99 || v16[69] == 99 || v16[80] == 99 || (v30 = v16[98], v30 == 99) )
          v31 = 5 * (*((_DWORD *)v147 + 12) - *((_DWORD *)v149 + 12));
        else
          v31 = 5 * (v16[51] + v16[69] + v16[80] + v30);
        *(int *)((char *)dword_4FA9B4 + v14) += 8 * v31;
        if ( v16[52] == 99 || v16[70] == 99 || v16[81] == 99 || (v32 = v16[99], v32 == 99) )
          v33 = 5 * (*((_DWORD *)v147 + 13) - *((_DWORD *)v149 + 13));
        else
          v33 = 5 * (v16[52] + v16[70] + v16[81] + v32);
        *(int *)((char *)dword_4FA9B4 + v14) += 8 * v33;
        if ( v16[53] == 99 || v16[71] == 99 || v16[82] == 99 || (v34 = v16[100], v34 == 99) )
          v35 = *((_DWORD *)v147 + 14) - *((_DWORD *)v149 + 14);
        else
          v35 = v16[53] + v16[71] + v16[82] + v34;
        *(int *)((char *)dword_4FA9B4 + v14) += 2 * v35;
        if ( v16[54] == 99 || v16[72] == 99 || v16[83] == 99 || (v36 = v16[101], v36 == 99) )
          v37 = *((_DWORD *)v147 + 15) - *((_DWORD *)v149 + 15);
        else
          v37 = v16[54] + v16[72] + v16[83] + v36;
        *(int *)((char *)dword_4FA9B4 + v14) += 2 * v37;
        if ( v16[55] == 99 || v16[73] == 99 || v16[84] == 99 || (v38 = v16[102], v38 == 99) )
          v39 = *((_DWORD *)v147 + 16) - *((_DWORD *)v149 + 16);
        else
          v39 = v16[55] + v16[73] + v16[84] + v38;
        *(int *)((char *)dword_4FA9B4 + v14) += 2 * v39;
        if ( v16[67] == 99 || (v40 = v16[96], v40 == 99) )
          *(int *)((char *)dword_4FA9B4 + v14) += *((_DWORD *)v149 + 9) - *((_DWORD *)v147 + 9);
        else
          *(int *)((char *)dword_4FA9B4 + v14) -= v16[67] + v40;
        if ( v16[66] == 99 || (v41 = v16[95], v41 == 99) )
          *(int *)((char *)dword_4FA9B4 + v14) += *((_DWORD *)v149 + 10) - *((_DWORD *)v147 + 10);
        else
          *(int *)((char *)dword_4FA9B4 + v14) -= v16[66] + v41;
        v43 = v16[65];
        v140 = v16[65];
        *(int *)((char *)dword_4FA9B4 + v14) -= v43 + v16[94];
        v42 = v16[59];
        v44 = *(int *)((char *)dword_4FA9B4 + v14);
        if ( v42 == 99 )
          goto LABEL_97;
        v45 = v16[88];
        if ( v45 == 99 )
        {
          v17 = 99;
LABEL_97:
          v43 = v140;
          *(int *)((char *)dword_4FA9B4 + v14) = v44 + *((_DWORD *)v149 + 11) - *((_DWORD *)v147 + 11);
          goto LABEL_98;
        }
        v46 = v44 - v45;
        v17 = 99;
        *(int *)((char *)dword_4FA9B4 + v14) = v46 - v42;
LABEL_98:
        if ( v16[60] == v17 || (v47 = v16[89], v47 == v17) )
          *(int *)((char *)dword_4FA9B4 + v14) += *((_DWORD *)v149 + 12) - *((_DWORD *)v147 + 12);
        else
          *(int *)((char *)dword_4FA9B4 + v14) -= v16[60] + v47;
        if ( v16[61] == v17 || (v48 = v16[90], v48 == v17) )
          *(int *)((char *)dword_4FA9B4 + v14) += *((_DWORD *)v149 + 13) - *((_DWORD *)v147 + 13);
        else
          *(int *)((char *)dword_4FA9B4 + v14) -= v16[61] + v48;
        if ( v16[62] == v17 || (v49 = v16[91], v49 == v17) )
          *(int *)((char *)dword_4FA9B4 + v14) += *((_DWORD *)v149 + 14) - *((_DWORD *)v147 + 14);
        else
          *(int *)((char *)dword_4FA9B4 + v14) -= v16[62] + v49;
        if ( v16[63] == v17 || (v50 = v16[92], v50 == v17) )
          *(int *)((char *)dword_4FA9B4 + v14) += *((_DWORD *)v149 + 15) - *((_DWORD *)v147 + 15);
        else
          *(int *)((char *)dword_4FA9B4 + v14) -= v16[63] + v50;
        if ( v16[64] == v17 || (v51 = v16[93], v51 == v17) )
        {
          v52 = v149;
          v53 = v147;
          *(int *)((char *)dword_4FA9B4 + v14) += *((_DWORD *)v149 + 16) - *((_DWORD *)v147 + 16);
        }
        else
        {
          v53 = v147;
          *(int *)((char *)dword_4FA9B4 + v14) -= v16[64] + v51;
          v52 = v149;
        }
        if ( v16[48] || v16[77] )
          *(int *)((char *)dword_4FA9B4 + v14) *= 10;
        if ( (unsigned __int8)v16[36] == 1 )
        {
          v55 = v16[40];
          v54 = *((_DWORD *)v52 + 14);
        }
        else
        {
          if ( (unsigned __int8)v16[36] == 2 )
          {
            v55 = v16[41];
            v54 = *((_DWORD *)v52 + 15);
          }
          else
          {
            if ( (unsigned __int8)v16[36] != 3 )
              goto LABEL_130;
            v55 = v16[42];
            v54 = *((_DWORD *)v52 + 16);
          }
        }
        v56 = v54 - v55;
        if ( v56 > 3 )
          v56 = 3;
        *(int *)((char *)dword_4FA9B4 + v14) += 5 * v56;
LABEL_130:
        v57 = v16[96];
        v141 = *((_DWORD *)v53 + 9);
        v128 = v16[67];
        if ( v141 <= v57 + v128 )
          *(int *)((char *)dword_4FA9B4 + v14) += 9999;
        v142 = *((_DWORD *)v53 + 10) + v141;
        if ( v142 <= v57 + v128 + v16[94] + v16[95] + v43 + v16[66] )
          *(int *)((char *)dword_4FA9B4 + v14) += 9999;
        if ( v16[87] + v16[105] + *((_DWORD *)v149 + 9) + (signed int)v16[76] + v152 >= dword_4E1884 )
          *(int *)((char *)dword_4FA9B4 + v14) += 9999;
        ++v134;
        if ( v134 >= v139 )
        {
          v6 = v133;
          break;
        }
      }
    }
    v58 = v139 - 1;
    for ( l = v139 - 1; l >= 0; --l )
    {
      v142 = 0;
      if ( l > 0 )
      {
        v60 = (int)dword_4FA9B0;
        v135 = l;
        v142 = l;
        do
        {
          if ( *(_DWORD *)(v60 + 4) < *(_DWORD *)(v60 + 12) )
          {
            v61 = *(_DWORD *)v60;
            v62 = *(_DWORD *)(v60 + 4);
            *(_DWORD *)v60 = *(_DWORD *)(v60 + 8);
            v63 = *(_DWORD *)(v60 + 12);
            *(_DWORD *)(v60 + 8) = v61;
            *(_DWORD *)(v60 + 4) = v63;
            v6 = v133;
            *(_DWORD *)(v60 + 12) = v62;
          }
          v60 += 8;
        }
        while ( v135-- != 1 );
      }
    }
    v65 = v139 - 1;
    if ( byte_4FAA77 )
    {
      if ( v58 >= 0 )
      {
        while ( !byte_4DF3D3[108 * dword_50574C[47 * v6 + dword_4FA9B0[2 * v65]]] )
        {
          --v65;
          if ( v65 < 0 )
            goto LABEL_155;
        }
        v142 = dword_4FA9B0[2 * v65];
      }
    }
    else
    {
      v66 = 0;
      if ( v58 >= 0 )
      {
        while ( !byte_4DF3D3[108 * dword_50574C[47 * v6 + dword_4FA9B0[2 * v65]]] )
        {
          --v65;
          if ( v65 < 0 )
            goto LABEL_151;
        }
        v142 = dword_4FA9B0[2 * v65];
      }
LABEL_151:
      if ( v139 > 0 )
      {
        while ( !sub_40BF15(v6, dword_4FA9B0[2 * v66]) || dword_4FA9B4[2 * v66] < 0 )
        {
          ++v66;
          if ( v66 >= v139 )
            goto LABEL_155;
        }
        LOBYTE(v2) = sub_40BE0E(v6, dword_4FA9B0[2 * v66]);
        return v2;
      }
    }
LABEL_155:
    LOBYTE(v2) = sub_40BCFB(v6, v142);
    return v2;
  }
  v7 = 0;
  v8 = a1;
  if ( byte_4FAA77 )
  {
LABEL_11:
    v11 = sub_40BB49(v8);
    v12 = sub_40DDB1(0, v11 - 1);
    LOBYTE(v2) = sub_40BCFB(v8, v12);
  }
  else
  {
    while ( 1 )
    {
      v10 = sub_40BB49(v8);
      v9 = sub_40DDB1(0, v10 - 1);
      if ( sub_40BF15(v8, v9) )
        break;
      ++v7;
      if ( v7 >= 10 )
        goto LABEL_11;
    }
    LOBYTE(v2) = sub_40BE0E(v8, v9);
  }
  return v2;
}

//----- (00465F5A) --------------------------------------------------------
void __cdecl sub_465F5A()
{
  int v0; // ecx@4
  int v1; // ecx@5
  char v2; // [sp+0h] [bp-24h]@1
  int v3; // [sp+10h] [bp-14h]@4
  char *v4; // [sp+14h] [bp-10h]@1
  int v5; // [sp+20h] [bp-4h]@4

  v4 = &v2;
 if (dword_720010)
   return;

 if (pD3DRenderer)
 {
  if (pD3DRenderer->dword_00000C == 1)
  {
        v5 = 0;
        compile_error;//v0 = (int)operator new(0x88u);
        v3 = v0;
        LOBYTE(v5) = 1;
        if ( v0 )
          v1 = sub_46ACA9(v0, pD3DRenderer->pdd4);
        else
          v1 = 0;
        LOBYTE(v5) = 0;
        dword_720010 = v1;
        if ( v1 )
          sub_46B105((void *)v1);
  }
 }
}

//----- (004764C2) --------------------------------------------------------
void __cdecl InitializeScrolls()
{
  char *result; // eax@4
  int v2; // edi@4
  char v3; // dl@5
  char *v4; // ecx@5
  int v5; // esi@9
  signed int v6; // [sp+10h] [bp-8h]@3
  signed int v7; // [sp+14h] [bp-4h]@4

 if (pScrollsTXT_Raw)
   class23_DeleteBuffer(class23_instance, pScrollsTXT_Raw);

 pScrollsTXT_Raw = class17_fn1(pClass17_Events_LOD, "scroll.txt", 0);
 strtok(pScrollsTXT_Raw, "\r");
  
  //v6 = (signed int)&dword_723D38;
 v6 = 0;
  do
  {
    result = strtok(0, "\r") + 1;
    v2 = 0;
    v7 = 0;
    do
    {
      v3 = *result;
      v4 = 0;
      if ( *result != 9 )
      {
        do
        {
          if ( !v3 )
            break;
          ++v4;
          v3 = *(_BYTE *)((_DWORD)v4 + (_DWORD)result);
        }
        while ( v3 != 9 );
      }
      v5 = (_DWORD)v4 + (_DWORD)result;
      if ( *(_BYTE *)((_DWORD)v4 + (_DWORD)result) == 0)
        v7 = 1;
      *(_BYTE *)v5 = 0;
      if ( v4 == 0)
      {
        v7 = 1;
      }
      else
      {
        if ( v2 == 1 )
          *(_DWORD *)(&dword_723D38 + v6) = sub_452C30(result);
      }
      ++v2;
      result = (char *)(v5 + 1);
    }
    while ( v2 - 1 <= 1 && !v7);
    v6 += 4;
  }
  //while ( v6 < (signed int)dword_723E80 );
 while (v6 < 0x148);
}

//----- (00452C49) --------------------------------------------------------
void __cdecl InitializeGameText()
{
 int i;
  unsigned char *v1; // eax@3
  int v2; // ebp@4
  unsigned char v3; // dl@5
  int v4; // ecx@5
  unsigned char **v7; // [sp+10h] [bp-8h]@3
  signed int v8; // [sp+14h] [bp-4h]@4

 if (pGlobalTXT_Raw)
   class23_DeleteBuffer(class23_instance, pGlobalTXT_Raw);

 pGlobalTXT_Raw = class17_fn1(pClass17_Events_LOD, "global.txt", 0);
 strtok(pGlobalTXT_Raw, "\r");
 strtok(0, "\r");
 v1 = strtok(0, "\r") + 1;
 v7 = pGlobalTXT_LocalizationStrings;

  for (i = 0; i < 677; ++i)
  {
    v2 = 0;
    v8 = 0;
    do
    {
      v3 = *v1;
      v4 = 0;
      if (*v1 != '\t' )
      {
        do
        {
          if ( !v3 )
            break;
          ++v4;
          v3 = v1[v4];
        }
        while ( v3 != '\t' );
      }

      if (v1[v4] == 0)
        v8 = 1;
      v1[v4] = 0;
      if ( v4 == 0)
        v8 = 1;
      else
      {
        if ( v2 == 1 )
          v7[i] = sub_452C30(v1);
      }
      ++v2;
      v1 = &v1[v4] + 1;
    }
    while ( v2 - 1 <= 1 && !v8 );

    v1 = strtok(0, "\r") + 1;
  }

  aMonthNames[0] = pGlobalTXT_LocalizationStrings[415];  aMonthNames[1] = pGlobalTXT_LocalizationStrings[416];
  aMonthNames[2] = pGlobalTXT_LocalizationStrings[417];  aMonthNames[3] = pGlobalTXT_LocalizationStrings[418];
  aMonthNames[4] = pGlobalTXT_LocalizationStrings[419];  aMonthNames[5] = pGlobalTXT_LocalizationStrings[420];
  aMonthNames[6] = pGlobalTXT_LocalizationStrings[421];  aMonthNames[7] = pGlobalTXT_LocalizationStrings[422];
  aMonthNames[8] = pGlobalTXT_LocalizationStrings[423];  aMonthNames[9] = pGlobalTXT_LocalizationStrings[424];
  aMonthNames[10] = pGlobalTXT_LocalizationStrings[425]; aMonthNames[11] = pGlobalTXT_LocalizationStrings[426];

  aDayNames[0] = pGlobalTXT_LocalizationStrings[145];  aDayNames[1] = pGlobalTXT_LocalizationStrings[230];
  aDayNames[2] = pGlobalTXT_LocalizationStrings[243];  aDayNames[3] = pGlobalTXT_LocalizationStrings[227];
  aDayNames[4] = pGlobalTXT_LocalizationStrings[91];   aDayNames[5] = pGlobalTXT_LocalizationStrings[188];
  aDayNames[6] = pGlobalTXT_LocalizationStrings[222];

  dword_5E4C18 = pGlobalTXT_LocalizationStrings[568];
  dword_5E4C1C = pGlobalTXT_LocalizationStrings[271];
  dword_5E4C20 = pGlobalTXT_LocalizationStrings[272];
  dword_5E4C24 = pGlobalTXT_LocalizationStrings[273];
  dword_5E4C28 = pGlobalTXT_LocalizationStrings[274];
  dword_5E4C2C = pGlobalTXT_LocalizationStrings[275];
  dword_5E4C30 = pGlobalTXT_LocalizationStrings[276];
  dword_5E4C34 = pGlobalTXT_LocalizationStrings[277];
  dword_5E4C38 = pGlobalTXT_LocalizationStrings[278];
  dword_5E4C3C = pGlobalTXT_LocalizationStrings[279];
  dword_5E4C40 = pGlobalTXT_LocalizationStrings[280];
  dword_5E4C44 = pGlobalTXT_LocalizationStrings[281];
  dword_5E4C48 = pGlobalTXT_LocalizationStrings[282];
  dword_5E4C4C = pGlobalTXT_LocalizationStrings[143];

  aClassNames[0] = pGlobalTXT_LocalizationStrings[253];
  aClassNames[1] = pGlobalTXT_LocalizationStrings[254];
  aClassNames[2] = pGlobalTXT_LocalizationStrings[255];
  aClassNames[3] = pGlobalTXT_LocalizationStrings[2];
  aClassNames[4] = pGlobalTXT_LocalizationStrings[307];
  aClassNames[5] = pGlobalTXT_LocalizationStrings[114];
  aClassNames[6] = pGlobalTXT_LocalizationStrings[3];
  aClassNames[7] = pGlobalTXT_LocalizationStrings[13];
  aClassNames[8] = pGlobalTXT_LocalizationStrings[21];
  aClassNames[9] = pGlobalTXT_LocalizationStrings[26];
  aClassNames[10] = pGlobalTXT_LocalizationStrings[432];
  aClassNames[11] = pGlobalTXT_LocalizationStrings[27];
  aClassNames[12] = pGlobalTXT_LocalizationStrings[262];
  aClassNames[13] = pGlobalTXT_LocalizationStrings[263];
  aClassNames[14] = pGlobalTXT_LocalizationStrings[264];
  aClassNames[15] = pGlobalTXT_LocalizationStrings[28];
  aClassNames[16] = pGlobalTXT_LocalizationStrings[265];
  aClassNames[17] = pGlobalTXT_LocalizationStrings[267];
  aClassNames[18] = pGlobalTXT_LocalizationStrings[119];
  aClassNames[19] = pGlobalTXT_LocalizationStrings[124];
  aClassNames[20] = pGlobalTXT_LocalizationStrings[31];
  aClassNames[21] = pGlobalTXT_LocalizationStrings[370];
  aClassNames[22] = pGlobalTXT_LocalizationStrings[33];
  aClassNames[23] = pGlobalTXT_LocalizationStrings[40];
  aClassNames[24] = pGlobalTXT_LocalizationStrings[256];
  aClassNames[25] = pGlobalTXT_LocalizationStrings[257];
  aClassNames[26] = pGlobalTXT_LocalizationStrings[44];
  aClassNames[27] = pGlobalTXT_LocalizationStrings[46];
  aClassNames[28] = pGlobalTXT_LocalizationStrings[268];
  aClassNames[29] = pGlobalTXT_LocalizationStrings[269];
  aClassNames[30] = pGlobalTXT_LocalizationStrings[270];
  aClassNames[31] = pGlobalTXT_LocalizationStrings[48];
  aClassNames[32] = pGlobalTXT_LocalizationStrings[259];
  aClassNames[33] = pGlobalTXT_LocalizationStrings[260];
  aClassNames[34] = pGlobalTXT_LocalizationStrings[261];
  aClassNames[35] = pGlobalTXT_LocalizationStrings[49];

  aCharacterConditionNames[0] = pGlobalTXT_LocalizationStrings[52];
  aCharacterConditionNames[1] = pGlobalTXT_LocalizationStrings[241];
  aCharacterConditionNames[2] = pGlobalTXT_LocalizationStrings[14];
  aCharacterConditionNames[3] = pGlobalTXT_LocalizationStrings[4];
  aCharacterConditionNames[4] = pGlobalTXT_LocalizationStrings[69];
  aCharacterConditionNames[5] = pGlobalTXT_LocalizationStrings[117];
  aCharacterConditionNames[6] = pGlobalTXT_LocalizationStrings[166];
  aCharacterConditionNames[7] = pGlobalTXT_LocalizationStrings[65];
  aCharacterConditionNames[8] = pGlobalTXT_LocalizationStrings[166];
  aCharacterConditionNames[9] = pGlobalTXT_LocalizationStrings[65];
  aCharacterConditionNames[10] = pGlobalTXT_LocalizationStrings[166];
  aCharacterConditionNames[11] = pGlobalTXT_LocalizationStrings[65];
  aCharacterConditionNames[12] = pGlobalTXT_LocalizationStrings[162];
  aCharacterConditionNames[13] = pGlobalTXT_LocalizationStrings[231];
  aCharacterConditionNames[14] = pGlobalTXT_LocalizationStrings[58];
  aCharacterConditionNames[15] = pGlobalTXT_LocalizationStrings[220];
  aCharacterConditionNames[16] = pGlobalTXT_LocalizationStrings[76];
  aCharacterConditionNames[17] = pGlobalTXT_LocalizationStrings[601];
  aCharacterConditionNames[18] = pGlobalTXT_LocalizationStrings[98];

  aSkillNames[0] = pGlobalTXT_LocalizationStrings[271];
  aSkillNames[1] = pGlobalTXT_LocalizationStrings[272];
  aSkillNames[2] = pGlobalTXT_LocalizationStrings[273];
  aSkillNames[3] = pGlobalTXT_LocalizationStrings[274];
  aSkillNames[4] = pGlobalTXT_LocalizationStrings[275];
  aSkillNames[5] = pGlobalTXT_LocalizationStrings[276];
  aSkillNames[6] = pGlobalTXT_LocalizationStrings[277];
  aSkillNames[7] = pGlobalTXT_LocalizationStrings[278];
  aSkillNames[8] = pGlobalTXT_LocalizationStrings[279];
  aSkillNames[9] = pGlobalTXT_LocalizationStrings[280];
  aSkillNames[10] = pGlobalTXT_LocalizationStrings[281];
  aSkillNames[11] = pGlobalTXT_LocalizationStrings[282];
  aSkillNames[12] = pGlobalTXT_LocalizationStrings[283];
  aSkillNames[13] = pGlobalTXT_LocalizationStrings[284];
  aSkillNames[14] = pGlobalTXT_LocalizationStrings[285];
  aSkillNames[15] = pGlobalTXT_LocalizationStrings[286];
  aSkillNames[16] = pGlobalTXT_LocalizationStrings[289];
  aSkillNames[17] = pGlobalTXT_LocalizationStrings[290];
  aSkillNames[18] = pGlobalTXT_LocalizationStrings[291];
  aSkillNames[19] = pGlobalTXT_LocalizationStrings[287];
  aSkillNames[20] = pGlobalTXT_LocalizationStrings[288];
  aSkillNames[21] = pGlobalTXT_LocalizationStrings[292];
  aSkillNames[22] = pGlobalTXT_LocalizationStrings[293];
  aSkillNames[23] = pGlobalTXT_LocalizationStrings[294];
  aSkillNames[24] = pGlobalTXT_LocalizationStrings[295];
  aSkillNames[25] = pGlobalTXT_LocalizationStrings[296];
  aSkillNames[26] = pGlobalTXT_LocalizationStrings[297];
  aSkillNames[27] = pGlobalTXT_LocalizationStrings[298];
  aSkillNames[28] = pGlobalTXT_LocalizationStrings[299];
  aSkillNames[29] = pGlobalTXT_LocalizationStrings[300];
  aSkillNames[30] = pGlobalTXT_LocalizationStrings[50];
  aSkillNames[31] = pGlobalTXT_LocalizationStrings[77];
  aSkillNames[32] = pGlobalTXT_LocalizationStrings[88];
  aSkillNames[33] = pGlobalTXT_LocalizationStrings[89];
  aSkillNames[34] = pGlobalTXT_LocalizationStrings[90];
  aSkillNames[35] = pGlobalTXT_LocalizationStrings[95];
  aSkillNames[36] = pGlobalTXT_LocalizationStrings[301];
  aSkillNames[37] = pGlobalTXT_LocalizationStrings[153];

  aSpellSchoolNames[0] = pGlobalTXT_LocalizationStrings[87];
  aSpellSchoolNames[1] = pGlobalTXT_LocalizationStrings[6];
  aSpellSchoolNames[2] = pGlobalTXT_LocalizationStrings[240];
  aSpellSchoolNames[3] = pGlobalTXT_LocalizationStrings[70];
  aSpellSchoolNames[4] = pGlobalTXT_LocalizationStrings[214];
  aSpellSchoolNames[5] = pGlobalTXT_LocalizationStrings[142];
  aSpellSchoolNames[6] = pGlobalTXT_LocalizationStrings[29];
  aSpellSchoolNames[7] = pGlobalTXT_LocalizationStrings[133];
  aSpellSchoolNames[8] = pGlobalTXT_LocalizationStrings[54];

  aAttributeNames[0] = pGlobalTXT_LocalizationStrings[144];
  aAttributeNames[1] = pGlobalTXT_LocalizationStrings[116];
  aAttributeNames[2] = pGlobalTXT_LocalizationStrings[163];
  aAttributeNames[3] = pGlobalTXT_LocalizationStrings[75];
  aAttributeNames[4] = pGlobalTXT_LocalizationStrings[1];
  aAttributeNames[5] = pGlobalTXT_LocalizationStrings[211];
  aAttributeNames[6] = pGlobalTXT_LocalizationStrings[136];

  aAMPMNames[0] = pGlobalTXT_LocalizationStrings[472];
  aAMPMNames[1] = pGlobalTXT_LocalizationStrings[473];

  aNPCProfessionNames[0] = pGlobalTXT_LocalizationStrings[153];
  aNPCProfessionNames[1] = pGlobalTXT_LocalizationStrings[308];
  aNPCProfessionNames[2] = pGlobalTXT_LocalizationStrings[309];
  aNPCProfessionNames[3] = pGlobalTXT_LocalizationStrings[7];
  aNPCProfessionNames[4] = pGlobalTXT_LocalizationStrings[306];
  aNPCProfessionNames[5] = pGlobalTXT_LocalizationStrings[310];
  aNPCProfessionNames[6] = pGlobalTXT_LocalizationStrings[311];
  aNPCProfessionNames[7] = pGlobalTXT_LocalizationStrings[312];
  aNPCProfessionNames[8] = pGlobalTXT_LocalizationStrings[313];
  aNPCProfessionNames[9] = pGlobalTXT_LocalizationStrings[314];
  aNPCProfessionNames[10] = pGlobalTXT_LocalizationStrings[105];
  aNPCProfessionNames[11] = pGlobalTXT_LocalizationStrings[315];
  aNPCProfessionNames[12] = pGlobalTXT_LocalizationStrings[316];
  aNPCProfessionNames[13] = pGlobalTXT_LocalizationStrings[317];
  aNPCProfessionNames[14] = pGlobalTXT_LocalizationStrings[115];
  aNPCProfessionNames[15] = pGlobalTXT_LocalizationStrings[318];
  aNPCProfessionNames[16] = pGlobalTXT_LocalizationStrings[319];
  aNPCProfessionNames[17] = pGlobalTXT_LocalizationStrings[320];
  aNPCProfessionNames[18] = pGlobalTXT_LocalizationStrings[321];
  aNPCProfessionNames[19] = pGlobalTXT_LocalizationStrings[322];
  aNPCProfessionNames[20] = pGlobalTXT_LocalizationStrings[323];
  aNPCProfessionNames[21] = pGlobalTXT_LocalizationStrings[293];
  aNPCProfessionNames[22] = pGlobalTXT_LocalizationStrings[324];
  aNPCProfessionNames[23] = pGlobalTXT_LocalizationStrings[498];
  aNPCProfessionNames[24] = pGlobalTXT_LocalizationStrings[525];
  aNPCProfessionNames[25] = pGlobalTXT_LocalizationStrings[327];
  aNPCProfessionNames[26] = pGlobalTXT_LocalizationStrings[328];
  aNPCProfessionNames[27] = pGlobalTXT_LocalizationStrings[329];
  aNPCProfessionNames[28] = pGlobalTXT_LocalizationStrings[330];
  aNPCProfessionNames[29] = pGlobalTXT_LocalizationStrings[331];
  aNPCProfessionNames[20] = pGlobalTXT_LocalizationStrings[332];
  aNPCProfessionNames[31] = pGlobalTXT_LocalizationStrings[333];
  aNPCProfessionNames[32] = pGlobalTXT_LocalizationStrings[334];
  aNPCProfessionNames[33] = pGlobalTXT_LocalizationStrings[335];
  aNPCProfessionNames[34] = pGlobalTXT_LocalizationStrings[336];
  aNPCProfessionNames[35] = pGlobalTXT_LocalizationStrings[337];
  aNPCProfessionNames[36] = pGlobalTXT_LocalizationStrings[338];
  aNPCProfessionNames[37] = pGlobalTXT_LocalizationStrings[339];
  aNPCProfessionNames[38] = pGlobalTXT_LocalizationStrings[340];
  aNPCProfessionNames[39] = pGlobalTXT_LocalizationStrings[341];
  aNPCProfessionNames[40] = pGlobalTXT_LocalizationStrings[342];
  aNPCProfessionNames[41] = pGlobalTXT_LocalizationStrings[343];
  aNPCProfessionNames[42] = pGlobalTXT_LocalizationStrings[596];
  aNPCProfessionNames[43] = pGlobalTXT_LocalizationStrings[345];
  aNPCProfessionNames[44] = pGlobalTXT_LocalizationStrings[346];
  aNPCProfessionNames[45] = pGlobalTXT_LocalizationStrings[347];
  aNPCProfessionNames[46] = pGlobalTXT_LocalizationStrings[348];
  aNPCProfessionNames[47] = pGlobalTXT_LocalizationStrings[349];  
  aNPCProfessionNames[48] = pGlobalTXT_LocalizationStrings[350];
  aNPCProfessionNames[49] = pGlobalTXT_LocalizationStrings[597];
  aNPCProfessionNames[50] = pGlobalTXT_LocalizationStrings[352];
  aNPCProfessionNames[51] = pGlobalTXT_LocalizationStrings[353];
  aNPCProfessionNames[52] = pGlobalTXT_LocalizationStrings[598];
  aNPCProfessionNames[53] = pGlobalTXT_LocalizationStrings[344];
  aNPCProfessionNames[54] = pGlobalTXT_LocalizationStrings[26];
  aNPCProfessionNames[55] = pGlobalTXT_LocalizationStrings[599];
  aNPCProfessionNames[56] = pGlobalTXT_LocalizationStrings[21];
  aNPCProfessionNames[57] = pGlobalTXT_LocalizationStrings[600];
  aNPCProfessionNames[58] = pGlobalTXT_LocalizationStrings[370];

  aMoonPhaseNames[0] = pGlobalTXT_LocalizationStrings[150];
  aMoonPhaseNames[1] = pGlobalTXT_LocalizationStrings[171];
  aMoonPhaseNames[2] = pGlobalTXT_LocalizationStrings[102];
  aMoonPhaseNames[3] = pGlobalTXT_LocalizationStrings[169];
  aMoonPhaseNames[4] = pGlobalTXT_LocalizationStrings[92];

  aSpellNames[0] = pGlobalTXT_LocalizationStrings[202];
  aSpellNames[1] = pGlobalTXT_LocalizationStrings[204];
  aSpellNames[2] = pGlobalTXT_LocalizationStrings[219];
  aSpellNames[3] = pGlobalTXT_LocalizationStrings[215];
  aSpellNames[4] = pGlobalTXT_LocalizationStrings[208];
  aSpellNames[5] = pGlobalTXT_LocalizationStrings[454];
  aSpellNames[6] = pGlobalTXT_LocalizationStrings[24];
  aSpellNames[7] = pGlobalTXT_LocalizationStrings[455];
  aSpellNames[8] = pGlobalTXT_LocalizationStrings[441];
  aSpellNames[9] = pGlobalTXT_LocalizationStrings[440];
  aSpellNames[10] = pGlobalTXT_LocalizationStrings[218];
  aSpellNames[11] = pGlobalTXT_LocalizationStrings[217];
  aSpellNames[12] = pGlobalTXT_LocalizationStrings[213];
  aSpellNames[13] = pGlobalTXT_LocalizationStrings[462];
  aSpellNames[14] = pGlobalTXT_LocalizationStrings[279];
  aSpellNames[15] = pGlobalTXT_LocalizationStrings[442];
  aSpellNames[16] = pGlobalTXT_LocalizationStrings[452];
  aSpellNames[17] = pGlobalTXT_LocalizationStrings[194];
  aSpellNames[18] = pGlobalTXT_LocalizationStrings[456];
  aSpellNames[19] = pGlobalTXT_LocalizationStrings[453];
  aSpellNames[20] = pGlobalTXT_LocalizationStrings[202];
  aSpellNames[21] = pGlobalTXT_LocalizationStrings[443];
  aSpellNames[22] = pGlobalTXT_LocalizationStrings[204];
  aSpellNames[23] = pGlobalTXT_LocalizationStrings[208];
  aSpellNames[24] = pGlobalTXT_LocalizationStrings[221];
  aSpellNames[25] = pGlobalTXT_LocalizationStrings[24];
  aSpellNames[26] = pGlobalTXT_LocalizationStrings[228];
  aSpellNames[27] = pGlobalTXT_LocalizationStrings[441];
  aSpellNames[28] = pGlobalTXT_LocalizationStrings[440];
  aSpellNames[29] = pGlobalTXT_LocalizationStrings[213];
  aSpellNames[30] = pGlobalTXT_LocalizationStrings[229];
  aSpellNames[31] = pGlobalTXT_LocalizationStrings[233];
  aSpellNames[32] = pGlobalTXT_LocalizationStrings[234];
  aSpellNames[33] = pGlobalTXT_LocalizationStrings[279];
  aSpellNames[34] = pGlobalTXT_LocalizationStrings[442];
  aSpellNames[35] = pGlobalTXT_LocalizationStrings[235];
  aSpellNames[36] = pGlobalTXT_LocalizationStrings[246];
  aSpellNames[37] = pGlobalTXT_LocalizationStrings[247];
  aSpellNames[38] = pGlobalTXT_LocalizationStrings[248];
  aSpellNames[39] = pGlobalTXT_LocalizationStrings[674];
  aSpellNames[40] = pGlobalTXT_LocalizationStrings[249];
  aSpellNames[41] = pGlobalTXT_LocalizationStrings[258];
  aSpellNames[42] = pGlobalTXT_LocalizationStrings[194];
  aSpellNames[43] = pGlobalTXT_LocalizationStrings[657];
}

//----- (MM7.exe::00465061) --------------------------------------------------------
char __fastcall CheckForCD(HWND hwnd, unsigned char *pGameCDDriveLetter)
{
  BYTE v2; // al@6
  DWORD v3; // esi@12
  char result; // al@19
  char cDriveLetter; // al@21
  DWORD cbData; // [sp+Ch] [bp-28h]@1
  char RootPathName[4]; // [sp+10h] [bp-24h]@15
  //char *v8; // [sp+14h] [bp-20h]@1
  HKEY hKey; // [sp+18h] [bp-1Ch]@1
  HKEY phkResult; // [sp+1Ch] [bp-18h]@1
  HKEY v11; // [sp+20h] [bp-14h]@1
  HKEY v12; // [sp+24h] [bp-10h]@1
  BYTE Data[4]; // [sp+28h] [bp-Ch]@5
  char v14; // [sp+29h] [bp-Bh]@21
  char v15; // [sp+2Ah] [bp-Ah]@21
  int v16; // [sp+2Ch] [bp-8h]@13
  char v17; // [sp+33h] [bp-1h]@1

  v12 = 0;
  v11 = 0;
  hKey = 0;
  phkResult = 0;
  v17 = 0;
  cbData = 3;
  if ( RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE", 0, 131103u, &hKey) )
    goto LABEL_25;
  if ( !RegOpenKeyExA(hKey, "New World Computing", 0, 0x2001Fu, &phkResult) )
  {
    if ( !RegOpenKeyExA(phkResult, "Might and Magic VII", 0, 0x2001Fu, &v11) )
    {
      if ( !RegOpenKeyExA(v11, "1.0", 0, 0x2001Fu, &v12) )
      {
        if ( !RegQueryValueExA(v12, "CDDrive", 0, 0, Data, &cbData) )
        {
          v2 = Data[0];
          v17 = 1;
          *pGameCDDriveLetter = Data[0];
          //pAudioPlayer->cGameCDDriveLetter = Data[0];
        }
        RegCloseKey(v12);
      }
      RegCloseKey(v11);
    }
    RegCloseKey(phkResult);
  }
  RegCloseKey(hKey);
  if ( v17 && IsMM7CD(*pGameCDDriveLetter) )
  {
LABEL_22:
    result = 1;
  }
  else
  {
LABEL_25:
    v3 = GetLogicalDrives();
    while ( 2 )
    {
      v16 = 2;
      do
      {
        if ( (1 << v16) & v3 )
        {
          strcpy((char *)RootPathName, "X:\\");
          v17 = v16 + 65;
          RootPathName[0] = v16 + 65;
          if ( GetDriveTypeA(RootPathName) == 5 )
          {
            if ( IsMM7CD(v17) )
            {
              cDriveLetter = v16 + 65;
              *pGameCDDriveLetter = v16 + 65;

              Data[0] = cDriveLetter;
              v14 = 58;
              v15 = 0;
              CreateRegistryKey("CDDrive", (const char *)&Data);
              //pAudioPlayer->cGameCDDriveLetter = Data;
              goto LABEL_22;
            }
          }
        }
        ++v16;
      }
      while ( v16 < 26 );
      if ( DialogBoxParamA(hInstance, "InsertCD", hWnd_global, (DLGPROC)DialogFunc, 0) )
        continue;
      break;
    }
    result = 0;
  }
  return result;
}

//----- (00409BE8) --------------------------------------------------------
int __cdecl sub_409BE8()
{
  int result; // eax@1
  int v1; // eax@1
  int v2; // eax@1
  int v3; // ecx@1

  v1 = *(_DWORD *)(dword_507BC0 + 28);
  dword_4E1874 = 5;
  v2 = 24 * (v1 - 108) + 5118096;
  dword_4E1860 = *(_WORD *)(v2 + 4);
  dword_4E1864 = *(_WORD *)(v2 + 6);
  dword_4E1868 = *(_WORD *)(v2 + 8) - 1;
  dword_4E186C = *(_WORD *)(v2 + 10) - 1;
  dword_4E1870 = *(_WORD *)(v2 + 12) - 1;
  dword_505884 = *(_WORD *)(v2 + 14);
  dword_505888 = *(_WORD *)(v2 + 16);
  dword_50588C = *(_WORD *)(v2 + 18);
  dword_4E1878 = 1;
  dword_4E187C = 1;
  dword_4E1880 = 1;
  dword_4E1884 = *(_WORD *)v2;
  v3 = *(_WORD *)(v2 + 2);
  result = *(_DWORD *)(v2 + 20);
  dword_4E1888 = v3;
  dword_4DF3A4 = result;
  return result;
}

//----- (00409C8B) --------------------------------------------------------
int __cdecl sub_409C8B()
{
  int v0; // ecx@3
  signed __int64 v1; // qax@4
  int v2; // esi@4
  signed int v3; // edi@5
  signed int v4; // esi@5
  void *v5; // esi@7
  int result; // eax@9
  int v7; // [sp+8h] [bp-1Ch]@5
  int v8; // [sp+Ch] [bp-18h]@5
  int v9; // [sp+10h] [bp-14h]@5
  int v10; // [sp+14h] [bp-10h]@5
  int v11; // [sp+18h] [bp-Ch]@5
  int v12; // [sp+1Ch] [bp-8h]@5
  int v13; // [sp+20h] [bp-4h]@3

  if (dword_720010)
    sub_409E3D(dword_720010, 1);
  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  strcpy(Dest, "Иг");
  strcpy(byte_50596C, "П");
  LOBYTE(word_4FAA75) = 0;
  word_4FAA75 = (unsigned __int8)word_4FAA75;
  v13 = 1;
  v0 = (int)byte_4FAA7C;
  do
  {
    v1 = v13;
    *(_DWORD *)(v0 - 4) = -1;
    *(_BYTE *)v0 = 0;
    v0 += 32;
    v2 = 138 * v1 / 4 + 18;
    HIDWORD(v1) = 100 * v1 % 4 + 120;
    *(_DWORD *)(v0 - 28) = HIDWORD(v1);
    *(_DWORD *)(v0 - 24) = v2;
    *(_DWORD *)(v0 - 20) = (120 - HIDWORD(v1)) / 5;
    ++v13;
    *(_DWORD *)(v0 - 16) = (18 - v2) / 5;
    *(_DWORD *)(v0 - 12) = *(_DWORD *)(v0 - 28);
    *(_DWORD *)(v0 - 8) = *(_DWORD *)(v0 - 24);
  }
  while ( v13 - 1 < 10 );
  v11 = 0;
  v12 = 0;
  sub_40D799();
  v7 = 0;
  v9 = 640;
  v8 = 0;
  v10 = 480;
  sub_40D7D5((void *)dword_5058D4, -1, 1);
  sub_40D9B1((int)&v7, (int)&v11, 2);
  sub_40DB10();
  CD3DRenderer_Present(pD3DRenderer);
  sub_40D7B7();
  sub_40DF3D();
  v4 = (signed int)&unk_4FAA08;
  v3 = 120;
  do
  {
    *(_WORD *)v4 = sub_4A9A67(pSoundList, v3++, 0);
    v4 += 2;
  }
  while ( v4 <= (signed int)&unk_4FAA20 );
  v5 = &dword_4FAC10;
  do
  {
    sub_40DFD1(v5);
    v5 = (char *)v5 + 4268;
  }
  while ( (signed int)v5 < (signed int)&unk_5052C8 );
  dword_4FABBC = -1;
  dword_4FAA4C = -1;
  byte_4FAA74 = 0;
  byte_50598C = 0;
  byte_4FAA2C = 0;
  byte_505880 = 0;
  dword_4FAA70 = 0;
  byte_4FAA77 = 0;
  sub_409FE9();
  sub_40A255();
  compile_error;//nullsub_1(&dword_4FAA28);
  byte_50598D = 0;
  dword_5058E0 = pFontComic;
  result = pFontArrus;
  dword_5058E4 = pFontArrus;
  return result;
}

//----- (00409E3D) --------------------------------------------------------
void __thiscall sub_409E3D(int this, char a2)
{
  if ( *(_BYTE *)(this + 128) & 1 )
    *(_BYTE *)(this + 103) = 1;
  else
    *(_BYTE *)(this + 103) = 0;
  if ( a2 )
    *(_DWORD *)(this + 128) |= 1u;
  else
    *(_DWORD *)(this + 128) &= 0xFFFFFFFEu;
}

//----- (0048276F) --------------------------------------------------------
void __thiscall sub_48276F(struct struct8 *_this)
{
  signed int v1; // ebx@1
  int v2; // edx@2
  double v3; // st7@2
  _UNKNOWN *v4; // ecx@3
  float v5; // eax@5
  float v6; // eax@7
  float v7; // eax@9
  int v8; // ecx@13
  int i; // eax@16
  int v10; // edx@20
  int v11; // edx@22
  int v12; // ecx@22
  float *v13; // esi@22
  int v14; // ebx@26
  float *v15; // ebx@27
  double v16; // st4@28
  double v17; // st5@28
  double v18; // st6@28

  struct
  {
   int v19; // [sp+4h] [bp-2Ch]@20
   int v20; // [sp+8h] [bp-28h]@22
   int v21; // [sp+Ch] [bp-24h]@22
   int v22; // [sp+10h] [bp-20h]@1
   int v23; // [sp+14h] [bp-1Ch]@11

   float v24; // [sp+18h] [bp-18h]@7
   float v25; // [sp+1Ch] [bp-14h]@5
   float v26; // [sp+20h] [bp-10h]@2
   float v27; // [sp+24h] [bp-Ch]@2
   float v28; // [sp+28h] [bp-8h]@2
   float v29; // [sp+2Ch] [bp-4h]@9
  } v19;



  v1 = _this->dword_000014;
  v19.v22 = _this;
  if (_this->dword_000014 >= 3 )
  {
    v2 = 0;
    v19.v26 = 10000.0;
    v19.v28 = 10000.0;
    v3 = -10000.0;
    v19.v27 = -10000.0;
    if ( v1 > 0 )
    {
      v4 = &unk_5086AC;
      do
      {
        if ( *((float *)v4 - 1) < (double)v19.v26 )
        {
          LODWORD(v5) = *((_DWORD *)v4 - 1);
          LODWORD(v19.v25) = v2;
          v19.v26 = v5;
        }
        if ( *((float *)v4 - 1) > (double)v19.v27 )
        {
          LODWORD(v6) = *((_DWORD *)v4 - 1);
          LODWORD(v19.v24) = v2;
          v19.v27 = v6;
        }
        if ( *(float *)v4 < (double)v19.v28 )
        {
          LODWORD(v7) = *(_DWORD *)v4;
          LODWORD(v19.v29) = v2;
          v19.v28 = v7;
        }
        if ( v3 < *(float *)v4 )
        {
          v3 = *(float *)v4;
          v19.v23 = v2;
        }
        ++v2;
        v4 = (char *)v4 + 48;
      }
      while ( v2 < v1 );
    }
    v8 = LODWORD(v19.v29);
    if ( LODWORD(v19.v29) == LODWORD(v19.v25) || LODWORD(v19.v29) == LODWORD(v19.v24) )
      v8 = v19.v23;
    LODWORD(v19.v29) = 0;
    for ( i = 0; i < v1; ++i )
    {
      if ( i == LODWORD(v19.v25) || i == LODWORD(v19.v24) || i == v8 )
      {
        v10 = LODWORD(v19.v29)++;
        (&v19.v19)[i] = i;
      }
      else 
        (&v19.v19)[i] = 0;
    }
    v12 = (int)&flt_508690[12 * v19.v19];
    v11 = (int)&flt_508690[12 * v19.v20];
    v13 = &flt_508690[12 * v19.v21];
    if ( LODWORD(v19.v29) != 3 )
    {
      v12 = (int)flt_508690;
      v13 = &flt_508690[4 * (3 * v1 - 3)];
      v11 = (int)flt_5086C0;
      v19.v28 = flt_5086C0[0] - flt_508690[0];
      v19.v27 = flt_5086C4 - flt_508690[1];
      v19.v29 = flt_5086C8 - flt_508690[2];
      v19.v26 = *v13 - flt_508690[0];
      v19.v25 = v13[1] - flt_508690[1];
      v19.v24 = v13[2] - flt_508690[2];
      if ( v19.v24 * v19.v27 - v19.v25 * v19.v29 == 0.0 )
      {
        if ( v19.v26 * v19.v29 - v19.v24 * v19.v28 == 0.0 )
        {
          if ( v19.v25 * v19.v28 - v19.v26 * v19.v27 == 0.0 )
          {
            v14 = v1 - 2;
            LODWORD(v19.v26) = v14;
            if ( v14 >= 2 )
            {
              v15 = &flt_508690[12 * v14];
              do
              {
                v18 = *v15 - flt_508690[0];
                v17 = v15[1] - flt_508690[1];
                v16 = v15[2] - flt_508690[2];
                v13 = v15;
                if ( v19.v27 * v16 - v17 * v19.v29 != 0.0 )
                  break;
                if ( v18 * v19.v29 - v16 * v19.v28 != 0.0 )
                  break;
                if ( v19.v28 * v17 - v18 * v19.v27 != 0.0 )
                  break;
                --LODWORD(v19.v26);
                v15 -= 12;
              }
              while ( LODWORD(v19.v26) >= 2 );
            }
          }
        }
      }
    }
    sub_4829B9(v12, v11, (int)v13, &v19.v22, 1);
  }
}

//----- (00409E6A) --------------------------------------------------------
int __cdecl sub_409E6A()
{
  int *v0; // esi@17
  int v1; // eax@18
  int v2; // eax@18
  int v3; // eax@21
  int *v4; // esi@23
  int result; // eax@24

  while ( !byte_50598D )
  {
    byte_50598E = 1;
    byte_4FAA24 = 1;
    sub_40A346(dword_4FAA6C);
LABEL_8:
    while ( byte_4FAA24 )
    {
      dword_4FABC0 = -1;
      sub_40A283(dword_4FAA6C);
      while ( 1 )
      {
        byte_4FAA24 = sub_40A560((void *)dword_4FAA6C);
        if ( sub_40BB49(dword_4FAA6C) <= dword_4E1874 )
          break;
        byte_4FAA77 = 1;
        if ( byte_50598C )
          goto LABEL_8;
      }
      byte_4FAA77 = 0;
    }
    byte_50598D = sub_40A514();
    if ( !byte_50598D )
      sub_40A383();
    if ( byte_50598C )
      byte_50598D = 1;
  }
  sub_40D444();
  if ( byte_4FAA2C )
    dword_4FAA70 = sub_40DFA7(dword_4FAA28) / 1000;
  else
    dword_4FAA70 = -1;
  compile_error;//nullsub_2(dword_4FAA28);
  v0 = &dword_4FAC10;
  do
  {
    v2 = sub_40E0F5(*v0, 1, 1);
    v1 = sub_40DFFE(v2, *v0);
    v0 += 1067;
  }
  while ( (signed int)v0 < (signed int)&unk_5052C8 );
  if (dword_720010)
  {
    sub_409E3D(dword_720010, *(_BYTE *)(dword_720010 + 103));
    v1 = sub_46B944(dword_720010);
  }
  v3 = sub_40E51F(pClass33_global0);
  sub_40E51F(pClass33_global1);
  byte_505992 = 0;
  dword_57702C = 1;
  if ( CVideoPlayer_IsAnyMovieLoaded(pVideoPlayer) )
    sub_4BF5B2(pVideoPlayer);
  v4 = (int *)&unk_4FAA08;
  do
  {
    result = sub_4A9DCD(pSoundList, *(_WORD *)v4, 1);
    v4 = (int *)((char *)v4 + 2);
  }
  while ( (signed int)v4 <= (signed int)&unk_4FAA20 );
  return result;
}

//----- (00409FE9) --------------------------------------------------------
char __cdecl sub_409FE9()
{
  signed int v0; // edi@1
  int v1; // esi@4
  int *v2; // eax@7
  signed int v3; // edx@7
  int *v4; // ecx@7
  signed int v5; // eax@13
  int v6; // edx@13
  signed int v7; // ecx@13

  dword_4FAA6C = dword_505890;
  sub_409BE8();
  v0 = 0;
  do
  {
    if ( v0 )
    {
      v1 = 188 * v0;
      sub_40DEBE(byte_50596C, &byte_505708[188 * v0]);
      if ( byte_4E185C )
        byte_505728[v1] = 0;
      else
        byte_505728[v1] = 1;
    }
    else
    {
      sub_40DEBE(Dest, byte_505708);
      byte_505728[0] = 1;
    }
    dword_50572C[47 * v0] = dword_4E1860;
    dword_505730[47 * v0] = dword_4E1864;
    dword_505734[47 * v0] = dword_4E1868;
    dword_505738[47 * v0] = dword_4E186C;
    dword_50573C[47 * v0] = dword_4E1870;
    dword_505740[47 * v0] = dword_505884;
    dword_505744[47 * v0] = dword_505888;
    dword_505748[47 * v0] = dword_50588C;
    v4 = &dword_505778[47 * v0];
    v2 = &dword_50574C[47 * v0];
    v3 = 10;
    do
    {
      *v2 = -1;
      if ( byte_4E185D )
      {
        *(v4 - 1) = -1;
        *v4 = -1;
      }
      else
      {
        *(v4 - 1) = 0;
        *v4 = 0;
      }
      ++v2;
      v4 += 2;
      --v3;
    }
    while ( v3 );
    ++v0;
  }
  while ( v0 < 2 );
  sub_40DEBE("Ма", byte_5054C8);
  v6 = 0;
  v7 = (signed int)dword_505554;
  v5 = -2;
  do
  {
    byte_5054EA[v5] = 0;
    *(_DWORD *)v7 = v6;
    switch ( v5 )
    {
      default:
        ++v6;
        break;
      case 0:
      case 2:
      case 6:
      case 9:
      case 13:
      case 18:
      case 23:
      case 33:
      case 36:
      case 38:
      case 44:
      case 46:
      case 52:
      case 57:
      case 69:
      case 71:
      case 75:
      case 79:
      case 81:
      case 84:
      case 89:
        break;
    }
    v7 += 4;
    ++v5;
  }
  while ( v7 < (signed int)&unk_505704 );
  return sub_40A198();
}

//----- (MM7::00464E17) --------------------------------------------------------
int __fastcall IsMM7CD(char cDriveLetter)
{
  FILE *f; // eax@3
  char result; // al@7
  CHAR DstBuf[256]; // [sp+Ch] [bp-218h]@1
  char strCommand[256]; // [sp+10Ch] [bp-118h]@1
  char Filename[256]; // [sp+20Ch] [bp-18h]@1
  char v7; // [sp+220h] [bp-4h]@1

  v7 = cDriveLetter;
  strcpy(Filename, "X:\\anims\\magic7.vid");
  wsprintfA(strCommand, "open %c: type cdaudio alias CD", (unsigned __int8)cDriveLetter);
  if ( !mciSendStringA(strCommand, &DstBuf, 255u, 0) )
  {
    wsprintfA(strCommand, "info CD UPC wait");
    mciSendStringA(strCommand, DstBuf, 0xFFu, 0);
    wsprintfA(strCommand, "close CD");
    mciSendStringA(strCommand, DstBuf, 0xFFu, 0);
  }
  Filename[0] = cDriveLetter;
  f = fopen(Filename, "rb");
  if (f)
  {
    if ( !fseek(f, 0, 2) )
    {
      if ( !fseek(f, -100, 1) )
        locked_fread(&DstBuf, 1u, 0x64u, f);
    }
    fclose(f);
    return 1;
  }
  else return 0;
}

//----- (0048FC00) --------------------------------------------------------
int sub_48FC00(struct Player *_this, signed int a2)
{
  int v2; // eax@1
  signed int v3; // ebx@1
  char v4; // di@1
  void *v5; // esi@1
  signed int v6; // eax@2
  unsigned __int8 v7; // sf@5
  unsigned __int8 v8; // of@5
  int v9; // ebx@19
  void *v10; // ecx@20
  int v11; // edi@21
  signed int v12; // edi@21
  int v13; // eax@21
  char v14; // di@25
  signed int v15; // esi@25
  char v16; // al@32
  int v18; // eax@36
  signed int v19; // eax@37
  int v20; // edi@40
  int v21; // edx@41
  int v22; // eax@42
  signed int v23; // eax@45
  __int16 v24; // bx@45
  signed int v25; // edi@45
  __int16 v26; // ax@45
  unsigned __int8 v27; // sf@50
  unsigned __int8 v28; // of@50
  signed int v29; // eax@52
  int v30; // eax@55
  int v31; // eax@58
  signed int v32; // eax@59
  int v33; // eax@65
  char v34; // si@65
  int v35; // edi@69
  int v36; // edx@70
  int v37; // eax@71
  signed int v38; // edi@74
  int v39; // eax@74
  int v40; // eax@89
  char v41; // si@89
  int v42; // eax@96
  int v43; // eax@97
  signed int v44; // edx@97
  int v45; // eax@98
  int v46; // eax@99
  int v47; // eax@100
  int v48; // eax@101
  int v49; // eax@102
  signed int v50; // eax@113
  signed int i; // ecx@113
  int v52; // edi@113
  __int16 v53; // ax@113
  char v54; // di@113
  signed int v56; // eax@118
  char v57; // si@118
  __int16 v58; // ax@118
  signed int j; // ecx@121
  int v60; // esi@121
  int v61; // eax@126
  int v62; // edi@126
  signed int v63; // [sp-4h] [bp-30h]@26
  signed int v64; // [sp-4h] [bp-30h]@80
  int v65; // [sp+Ch] [bp-20h]@104
  int v66; // [sp+10h] [bp-1Ch]@104
  int v67; // [sp+14h] [bp-18h]@104
  int v68; // [sp+18h] [bp-14h]@104
  int v69; // [sp+1Ch] [bp-10h]@69
  char *v70; // [sp+20h] [bp-Ch]@1
  int v71; // [sp+24h] [bp-8h]@1
  int v72; // [sp+28h] [bp-4h]@1
  int v73; // [sp+34h] [bp+8h]@21
  int v74; // [sp+34h] [bp+8h]@74
  signed int v75; // [sp+34h] [bp+8h]@94

  v5 = _this;
  v71 = 0;
  v70 = 0;
  v72 = 0;
  LOBYTE(v2) = sub_48F882(_this, 33);
  v4 = v2;
  v3 = 1;
  if ( v2 )
  {
    v6 = sub_458244(v2);
    if ( a2 == 26 )
    {
      if ( v6 >= 4 )
        goto LABEL_4;
      compile_error;//v8 = __SETO__(v6, 3);
      v7 = v6 - 3 < 0;
    }
    else
    {
      if ( a2 != 25 )
        goto LABEL_11;
      if ( v6 >= 4 )
      {
LABEL_4:
        v72 = 2;
LABEL_11:
        v70 = (char *)(v72 * (v4 & 0x3F));
        goto LABEL_12;
      }
      compile_error;//v8 = __SETO__(v6, 2);
      v7 = v6 - 2 < 0;
    }
    if ( !(v7 ^ v8) )
      v72 = 1;
    goto LABEL_11;
  }
LABEL_12:
  if ( a2 == 7 )
  {
    v62 = byte_4ED768[_this->uClass];
    v61 = sub_49107D(_this);
    return v62 * v61;
  }
  if ( a2 == 8 )
  {
    v62 = byte_4ED78C[_this->uClass];
    v61 = sub_4910A8(_this);
    return v62 * v61;
  }
  if ( a2 != 9 )
  {
    if ( a2 != 25 )
    {
      if ( a2 <= 25 )
        return v71;
      if ( a2 > 28 )
      {
        if ( a2 != 29 )
          return v71;
        v72 = 0;
        v9 = (int)((char *)v5 + 6472);
        while ( 1 )
        {
          if ( sub_48D6AA(v5, v72) )
          {
            v12 = (unsigned __int8)byte_5D2A01[48 * *((_DWORD *)v5 + 9 * *(_DWORD *)v9 + 124)];
            LOBYTE(v13) = sub_48F882(v10, v12);
            v73 = v13;
            sub_458244(v13);
            v11 = v12 - 5;
            if ( !v11 )
              return v73 & 0x3F;
            if ( v11 == 2 )
              break;
          }
          ++v72;
          v9 += 4;
          if ( v72 >= 16 )
            return v71;
        }
        v14 = v73;
        v15 = 1;
        if ( sub_458244(v73) >= 4 )
        {
          v63 = 5;
          goto LABEL_31;
        }
        if ( sub_458244(v73) >= 3 )
        {
          v63 = 3;
          goto LABEL_31;
        }
        if ( sub_458244(v73) < 2 )
          goto LABEL_32;
        goto LABEL_30;
      }
      if ( sub_48D676(v5) )
      {
        LOBYTE(v18) = sub_48F882(v5, 31);
        v14 = v18;
        if ( !v18 )
          return v71;
        v15 = 0;
        v19 = sub_458244(v18);
        if ( v19 < 3 )
        {
          if ( v19 >= 2 )
            v15 = 1;
LABEL_32:
          v16 = v14;
          return v15 * (v16 & 0x3F);
        }
LABEL_30:
        v63 = 2;
LABEL_31:
        v15 = v63;
        goto LABEL_32;
      }
      v20 = 0;
      while ( 1 )
      {
        if ( sub_48D6AA(v5, v20) )
        {
          v22 = *((_DWORD *)v5 + 9 * *(_DWORD *)v21 + 124);
          if ( (unsigned __int8)byte_5D2A00[48 * v22] <= 1u )
            break;
        }
        ++v20;
        if ( v20 >= 16 )
          return v71;
      }
      v72 = 0;
      v25 = (unsigned __int8)byte_5D2A01[48 * v22];
      LOBYTE(v26) = sub_48F882(v5, v25);
      v24 = v26;
      v23 = sub_458244(v26);
      if ( !v25 )
      {
        if ( sub_458244(v24) >= 4 )
        {
          LOBYTE(v31) = sub_48F882(v5, 31);
          LOBYTE(v24) = v31;
          if ( v31 )
          {
            v15 = 0;
            v32 = sub_458244(v31);
            if ( v32 < 3 )
            {
              if ( v32 >= 2 )
                v15 = 1;
            }
            else
            {
              v15 = 2;
            }
            v16 = v24;
            return v15 * (v16 & 0x3F);
          }
        }
        goto LABEL_55;
      }
      if ( v25 == 2 )
      {
        v29 = sub_458244(v24);
        compile_error;//v28 = __SETO__(v29, 4);
        v27 = v29 - 4 < 0;
      }
      else
      {
        if ( v25 <= 2 )
          goto LABEL_55;
        if ( v25 > 4 )
        {
          if ( v25 == 6 )
          {
            compile_error;//v28 = __SETO__(v23, 2);
            v27 = v23 - 2 < 0;
            goto LABEL_53;
          }
LABEL_55:
          v30 = v72 * (v24 & 0x3F);
          return (int)&v70[v30];
        }
        compile_error;//v28 = __SETO__(v23, 3);
        v27 = v23 - 3 < 0;
      }
LABEL_53:
      if ( !(v27 ^ v28) )
        v72 = 1;
      goto LABEL_55;
    }
    if ( sub_48D676(v5) == 1 )
    {
      LOBYTE(v33) = sub_48F882(v5, 31);
      v34 = v33;
      if ( !v33 )
        return v71;
      if ( sub_458244(v33) >= 3 )
        v3 = 2;
      v30 = v3 * (v34 & 0x3F);
      return (int)&v70[v30];
    }
    v35 = 0;
    v69 = 0;
    while ( 1 )
    {
      if ( sub_48D6AA(v5, v35) )
      {
        v37 = *((_DWORD *)v5 + 9 * *(_DWORD *)v36 + 124);
        if ( (unsigned __int8)byte_5D2A00[48 * v37] <= 1u )
          break;
      }
      ++v35;
      if ( v35 >= 16 )
        return v71;
    }
    v38 = (unsigned __int8)byte_5D2A01[48 * v37];
    LOBYTE(v39) = sub_48F882(v5, v38);
    v74 = v39;
    sub_458244(v39);
    v72 = 0;
    if ( v38 )
    {
      if ( v38 > 0 )
      {
        if ( v38 <= 4 || v38 == 6 )
        {
          v72 = 1;
        }
        else
        {
          if ( v38 == 7 )
          {
            if ( sub_458244(v74) < 4 )
            {
              if ( sub_458244(v74) < 3 )
              {
                if ( sub_458244(v74) < 2 )
                  return v3 * (v74 & 0x3F);
                v64 = 2;
              }
              else
              {
                v64 = 3;
              }
            }
            else
            {
              v64 = 5;
            }
            v3 = v64;
            return v3 * (v74 & 0x3F);
          }
        }
      }
    }
    else
    {
      v72 = 1;
      if ( sub_458244(v74) >= 4 )
      {
        LOBYTE(v40) = sub_48F882(v5, 31);
        v41 = v40;
        if ( v40 )
        {
          if ( sub_458244(v40) >= 3 )
            v3 = 2;
          v69 = v3 * (v41 & 0x3F);
        }
      }
    }
    v30 = v69 + v72 * (v74 & 0x3F);
    return (int)&v70[v30];
  }
  v75 = 0;
  v72 = 0;
  v69 = 16;
  v70 = (char *)v5 + 6472;
  do
  {
    if ( *(_DWORD *)v70 )
    {
      v42 = (int)((char *)v5 + 36 * *(_DWORD *)v70);
      if ( !(*(_BYTE *)(v42 + 516) & 2) )
      {
        v44 = (unsigned __int8)byte_5D2A01[48 * *(_DWORD *)(v42 + 496)];
        v43 = (unsigned __int8)byte_5D2A01[48 * *(_DWORD *)(v42 + 496)];
        if ( v43 )
        {
          v45 = v43 - 1;
          if ( !v45 || (v46 = v45 - 3, !v46) )
          {
            v65 = 0;
            v66 = 0;
            v67 = 0;
            v68 = 1;
            goto LABEL_113;
          }
          v47 = v46 - 4;
          if ( v47 )
          {
            v48 = v47 - 1;
            if ( v48 )
            {
              v49 = v48 - 1;
              if ( v49 )
              {
                if ( v49 != 1 )
                  goto LABEL_117;
                v75 = 1;
                v65 = 1;
                v66 = 0;
                v67 = 0;
                v68 = 0;
                goto LABEL_113;
              }
              v75 = 1;
              v65 = 1;
              v66 = 0;
              goto LABEL_111;
            }
            v72 = 1;
          }
          else
          {
            v75 = 1;
          }
          v65 = 1;
          v66 = 0;
          v67 = 1;
LABEL_112:
          v68 = 0;
LABEL_113:
          LOBYTE(v53) = sub_48F882(v5, v44);
          v54 = v53;
          v50 = sub_458244(v53);
          v52 = v54 & 0x3F;
          for ( i = 0; i < v50; ++i )
          {
            if ( *(&v65 + i) )
              v71 += v52;
          }
          goto LABEL_117;
        }
        v65 = 0;
        v66 = 1;
LABEL_111:
        v67 = 0;
        goto LABEL_112;
      }
    }
LABEL_117:
    v70 += 4;
  }
  while ( v69-- != 1 );
  v65 = 1;
  v66 = 1;
  v67 = 1;
  v68 = 0;
  LOBYTE(v58) = sub_48F882(v5, 30);
  v57 = v58;
  v56 = sub_458244(v58);
  if ( !v75 )
  {
    if ( !v72 || v56 == 4 )
    {
      v60 = v57 & 0x3F;
      for ( j = 0; j < v56; ++j )
      {
        if ( *(&v65 + j) )
          v71 += v60;
      }
    }
  }
  return v71;
}

//----- (0040A198) --------------------------------------------------------
char __cdecl sub_40A198()
{
  signed int v0; // edi@1
  signed int v1; // edx@2
  signed int v2; // esi@2
  signed int v3; // eax@4
  signed int v4; // esi@12
  char *v5; // eax@13
  int v6; // eax@13
  int v7; // edx@13
  char result; // al@14
  char v9[108]; // [sp+8h] [bp-6Ch]@1

  sub_40DDC9((void *)0x14);
  memset(byte_5054E8, 0, 0x6Cu);
  memset(v9, 0, sizeof(v9));
  v0 = (signed int)dword_50574C;
  do
  {
    v1 = v0;
    v2 = 10;
    do
    {
      if ( *(_DWORD *)v1 > -1 )
      {
        v3 = 0;
        while ( dword_505554[v3] != *(_DWORD *)v1 || byte_5054E8[v3] )
        {
          ++v3;
          if ( v3 >= 108 )
            goto LABEL_10;
        }
        byte_5054E8[v3] = 1;
      }
LABEL_10:
      v1 += 4;
      --v2;
    }
    while ( v2 );
    v0 += 188;
  }
  while ( v0 < (signed int)&Msg_global.pt.y );
  v4 = 0;
  do
  {
    do
    {
      v6 = rand();
      v7 = v6 % 108;
      v5 = &v9[v6 % 108];
    }
    while ( *v5 == 1 );
    *v5 = 1;
    dword_505314[v4] = dword_505554[v7];
    result = byte_5054E8[v7];
    byte_5052A8[v4++] = result;
  }
  while ( v4 < 108 );
  dword_4FABC8 = 0;
  dword_4FABC4 = -1;
  byte_50598E = 1;
  return result;
}

//----- (00461EE9) --------------------------------------------------------
int sub_461EE9(struct class17 *_this)
{
  if (_this->dword_000104)
  {
   _this->sContainerName[0] = 0;
   _this->dword_000224 = 0;
   _this->dword_000104 = 0;
    dword_6A0CA8 = 0;
    fflush(_this->pLODFile);
    fclose(_this->pLODFile);
  }
  return 0;
}

//----- (0040A255) --------------------------------------------------------
signed int __cdecl sub_40A255()
{
  int i; // edi@1
  signed int v1; // esi@2
  signed int result; // eax@3

  for ( i = 0; i < dword_4E1874; ++i )
  {
    v1 = 0;
    do
      result = sub_40A283(v1++);
    while ( v1 < 2 );
  }
  byte_50598E = 1;
  return result;
}

//----- (0040A283) --------------------------------------------------------
signed int __fastcall sub_40A283(int a1)
{
  signed int v1; // eax@1
  char v2; // bl@1
  int v3; // edi@1
  int v4; // esi@1
  signed int result; // eax@7
  int v6; // esi@8

  v1 = dword_4FABC8;
  v3 = a1;
  v4 = a1;
  v2 = 0;
  do
  {
    if ( v1 >= 108 )
    {
      sub_40A198();
      v1 = dword_4FABC8;
    }
    if ( !byte_5052A8[v1] )
    {
      v3 = dword_505314[v1];
      v2 = 1;
    }
    ++v1;
    dword_4FABC8 = v1;
  }
  while ( !v2 );
  sub_40DDC9((void *)0x15);
  result = sub_40A324(v4);
  if ( result != -1 )
  {
    dword_4FAA4C = result;
    dword_50574C[result + 47 * v4] = v3;
    v6 = 188 * v4 + 8 * result;
    *(int *)((char *)&dword_505774 + v6) = sub_40DDB1(-4, 4);
    result = sub_40DDB1(-4, 4);
    *(int *)((char *)dword_505778 + v6) = result;
    byte_50598E = 1;
    byte_4FAA2D = 1;
  }
  return result;
}

//----- (0040A324) --------------------------------------------------------
signed int __fastcall sub_40A324(int a1)
{
  signed int result; // eax@1
  signed int v2; // edx@1
  int *v3; // ecx@1

  result = -1;
  v2 = 0;
  v3 = &dword_50574C[47 * a1];
  while ( *v3 != -1 )
  {
    ++v2;
    ++v3;
    if ( v2 >= 10 )
      return result;
  }
  return v2;
}

//----- (0040A346) --------------------------------------------------------
int __fastcall sub_40A346(int a1)
{
  int result; // eax@1
  int v2; // ecx@1

  v2 = 188 * a1;
  *(int *)((char *)dword_505740 + v2) += dword_4E1878 + *(int *)((char *)dword_505734 + v2);
  *(int *)((char *)dword_505744 + v2) += dword_4E187C + *(int *)((char *)dword_505738 + v2);
  result = dword_4E1880 + *(int *)((char *)dword_50573C + v2);
  *(int *)((char *)dword_505748 + v2) += result;
  return result;
}

//----- (0040A383) --------------------------------------------------------
void __cdecl sub_40A383()
{
  int v0; // ecx@4
  int v1; // eax@4
  unsigned __int8 v2; // sf@4
  unsigned __int8 v3; // of@4
  int v4; // eax@6
  int v5; // ecx@7
  char Dest; // [sp+4h] [bp-64h]@4
  int v7; // [sp+44h] [bp-24h]@6
  int v8; // [sp+48h] [bp-20h]@6
  int v9; // [sp+4Ch] [bp-1Ch]@6
  int v10; // [sp+50h] [bp-18h]@6
  int v11; // [sp+54h] [bp-14h]@7
  int v12; // [sp+58h] [bp-10h]@14
  int v13; // [sp+60h] [bp-8h]@4
  int v14; // [sp+64h] [bp-4h]@4

  if ( !byte_50598C )
  {
    if ( byte_505728[0] != 1 || byte_5057E4 != 1 )
    {
      ++dword_4FAA6C;
      compile_error;//byte_4FAA75 = 1;
      if ( dword_4FAA6C >= 2 )
        dword_4FAA6C = 0;
    }
    else
    {
      compile_error;//nullsub_1(0);
      v13 = 0;
      v14 = 0;
      sub_40DEBE("След", &Dest);
      v1 = sub_40DED8();
      v14 = 200;
      v13 = 320 - 12 * v1 / 2;
      sub_40D75D(-1, &Dest, (int)&v13);
      compile_error;//byte_4FAA75 = 1;
      v0 = dword_4FAA6C + 1;
      compile_error;//v3 = __SETO__(dword_4FAA6C + 1, 2);
      v2 = dword_4FAA6C++ - 1 < 0;
      if ( !(v2 ^ v3) )
      {
        v0 = 0;
        dword_4FAA6C = 0;
      }
      sub_40DEBE(&byte_505708[188 * v0], &Dest);
      v4 = sub_40DED8();
      v14 = 260;
      v13 = 320 - 12 * v4 / 2;
      sub_40D75D(-1, &Dest, (int)&v13);
      v7 = 0;
      v9 = 640;
      v8 = 0;
      v10 = 480;
      compile_error;//nullsub_1(&v7);
      sub_40DF3D();
      compile_error;//nullsub_1(1);
      while ( 1 )
      {
        while ( 1 )
        {
          while ( !sub_40DC2D(20, &v11) )
            ;
          if ( v11 != 1 )
            break;
          if ( v12 )
            goto LABEL_13;
          compile_error;//nullsub_1(v5);
        }
        if ( v11 > 4 )
        {
          if ( v11 <= 8 )
            goto LABEL_13;
          if ( v11 == 10 )
            break;
        }
      }
      byte_50598C = 1;
      byte_4FAA74 = 1;
LABEL_13:
      v13 = 0;
      v14 = 0;
      v7 = 0;
      v9 = 640;
      v8 = 0;
      v10 = 480;
      compile_error;//nullsub_1(&v7);
      sub_40DF3D();
    }
  }
}

//----- (0040A514) --------------------------------------------------------
char __cdecl sub_40A514()
{
  char result; // al@1
  signed int v1; // ecx@1

  result = 0;
  v1 = (signed int)dword_50572C;
  do
  {
    if ( *(_DWORD *)v1 <= 0 )
      result = 1;
    if ( *(_DWORD *)v1 >= dword_4E1884 )
      result = 1;
    if ( *(_DWORD *)(v1 + 20) >= dword_4E1888
      || *(_DWORD *)(v1 + 24) >= dword_4E1888
      || *(_DWORD *)(v1 + 28) >= dword_4E1888 )
      result = 1;
    v1 += 188;
  }
  while ( v1 < (signed int)&unk_5058A4 );
  if ( result )
    byte_4FAA2C = 1;
  return result;
}

//----- (0040A560) --------------------------------------------------------
char __thiscall sub_40A560(void *this)
{
  __int64 v1; // qax@3
  signed int v2; // edx@8
  int v3; // ecx@17
  char v4; // sf@54
  char v5; // sf@57
  int v6; // ecx@62
  int v7; // ecx@66
  int v8; // esi@67
  int v9; // ecx@67
  char Dest; // [sp+8h] [bp-A8h]@67
  int v12; // [sp+6Ch] [bp-44h]@3
  int v13; // [sp+70h] [bp-40h]@75
  int v14; // [sp+74h] [bp-3Ch]@75
  int v15; // [sp+78h] [bp-38h]@75
  int v16; // [sp+7Ch] [bp-34h]@75
  int v17; // [sp+80h] [bp-30h]@69
  int v18; // [sp+84h] [bp-2Ch]@69
  int v19; // [sp+88h] [bp-28h]@69
  int v20; // [sp+8Ch] [bp-24h]@69
  int v21; // [sp+90h] [bp-20h]@75
  int v22; // [sp+94h] [bp-1Ch]@75
  int v23; // [sp+98h] [bp-18h]@8
  int v24; // [sp+9Ch] [bp-14h]@13
  int v25; // [sp+A0h] [bp-10h]@14
  void *v26; // [sp+A4h] [bp-Ch]@1
  int v27; // [sp+A8h] [bp-8h]@1
  char v28; // [sp+AEh] [bp-2h]@63
  char v29; // [sp+AFh] [bp-1h]@1

  dword_4FAA50 = -1;
  v27 = (int)this;
  v29 = 0;
  v26 = (void *)20;
  byte_4FAA00 = 0;
  dword_4FAA68 = 0;
  dword_4FAA38 = 10;
  dword_4FAA34 = 5;
  if ( dword_4FAA4C != -1 )
    byte_4FAA2D = 1;
  do
  {
    do
    {
      do
      {
        v1 = class24_fn2(pClass24_global);
        v12 = (unsigned __int64)(v1 - dword_505940) >> 32;
      }
      while ( v12 < 0 );
    }
    while ( HIDWORD(v1) <= (signed int)(((_DWORD)v1 < (unsigned int)dword_505940)
                                      + ((unsigned __int64)dword_505940 >> 32))
         && (unsigned int)(v1 - dword_505940) < 6 );
    dword_505940 = class24_fn2(pClass24_global);
    if ( byte_50598C )
      v29 = 1;
    sub_40DC2D(0, &v23);
    if ( v23 != 2 )
    {
      if ( v23 == 9 )
      {
        byte_50598E = 1;
        goto LABEL_17;
      }
      if ( v23 != 10 )
        goto LABEL_17;
      sub_40DEA5();
      byte_4FAA74 = 1;
      goto LABEL_16;
    }
    if ( v24 == 129 && v25 == 1 )
    {
      sub_40DEA5();
      dword_4FAA68 = 0;
LABEL_16:
      v29 = 1;
      byte_50598C = 1;
    }
LABEL_17:
    v3 = dword_4FAA6C;
    if ( byte_505728[188 * dword_4FAA6C] != 1 )
    {
      if ( !byte_4FAA00 )
      {
        if ( !byte_4FAA2E )
        {
          if ( !byte_4FAA2D )
          {
            compile_error;//if ( byte_4FAA75 )
              compile_error;//byte_4FAA76 = 1;
            sub_408BB4(dword_4FAA6C, v2);
            v3 = dword_4FAA6C;
            byte_4FAA2E = 1;
          }
        }
      }
    }
    if ( dword_4FAA4C != -1 )
    {
      if ( dword_4FAA38 > 10 )
        dword_4FAA38 = 10;
    }
    if ( byte_4FAA2E || byte_4FAA2D || (v3 *= 188, byte_505728[v3] != 1) )
    {
      byte_50598E = 1;
      if ( byte_4FAA2D )
      {
        v4 = dword_4FAA38-- - 1 < 0;
        if ( v4 )
        {
          byte_4FAA2D = 0;
          dword_4FAA38 = 10;
          v29 = 0;
        }
      }
      if ( byte_4FAA2E )
      {
        v5 = (signed int)((char *)v26 - 1) < 0;
        v26 = (char *)v26 - 1;
        if ( v5 )
        {
          if ( dword_4FAA68 > 1 )
          {
            --dword_4FAA68;
            byte_4FAA00 = 0;
          }
          else
          {
            v29 = 1;
          }
          byte_4FAA2E = 0;
          v26 = (void *)20;
        }
      }
    }
    else
    {
      if ( byte_4FAA77 )
      {
        if ( v23 == 7 )
        {
          if ( sub_40BCFB(v27, dword_4FABBC) )
          {
            compile_error;//if ( byte_4FAA75 )
              compile_error;//byte_4FAA76 = 1;
            if ( dword_4FAA64 > 0 )
            {
              --dword_4FAA64;
              byte_4FAA77 = sub_40BB49(v27) > dword_4E1874;
            }
            byte_4FAA2E = 1;
          }
        }
        if ( v23 == 8 )
        {
          if ( sub_40BCFB(v27, dword_4FABBC) )
          {
            compile_error;//if ( byte_4FAA75 )
              compile_error;//byte_4FAA76 = 1;
            if ( dword_4FAA64 > 0 )
            {
              --dword_4FAA64;
              byte_4FAA77 = sub_40BB49(v27) > dword_4E1874;
            }
            byte_4FAA2E = 1;
          }
        }
      }
      else
      {
        if ( v23 == 7 )
        {
          if ( sub_40BE0E(v27, dword_4FABBC) )
          {
            byte_4FAA2E = 1;
            compile_error;//if ( byte_4FAA75 )
              compile_error;//byte_4FAA76 = 1;
          }
        }
        if ( v23 == 8 )
        {
          if ( sub_40BCFB(v27, dword_4FABBC) )
          {
            byte_4FAA2E = 1;
            compile_error;//if ( byte_4FAA75 )
              compile_error;//byte_4FAA76 = 1;
          }
        }
      }
    }
    compile_error;//nullsub_1(v3);
    if ( sub_40DD2C() )
    {
      if ( !v28 )
      {
        compile_error;//nullsub_1(v6);
        v28 = 1;
      }
    }
    else
    {
      v28 = 0;
    }
    if ( sub_40DD2C() )
    {
      compile_error;//nullsub_1(v7);
      compile_error;//nullsub_1(34);
      sub_40DEBE("В", &Dest);
      v8 = sub_40DB22((int)&unk_4E19FC, 0);
      compile_error;//nullsub_1(v9);
      if ( v8 == 1 )
      {
        sub_40DEA5();
        v29 = 1;
        byte_50598C = 1;
        dword_4FAA68 = 0;
      }
      v17 = 0;
      v19 = 640;
      v18 = 0;
      v20 = 480;
      compile_error;//nullsub_1(&v17);
    }
    if ( dword_4FABB8 != sub_40BB67(v27) )
    {
      dword_4FABB8 = sub_40BB67(v27);
      byte_50598E = 1;
    }
    if ( byte_50598E )
    {
      sub_40A9AF(v26);
      sub_40DF47((void *)dword_5058D4);
      byte_50598E = 0;
    }
    if ( byte_505991 )
    {
      v21 = 0;
      v22 = 0;
      v13 = 0;
      v15 = 640;
      v14 = 0;
      v16 = 480;
      sub_40D7D5((void *)dword_5058D4, -1, 1);
      sub_40D9B1((int)&v13, (int)&v21, 2);
      sub_40DB10();
      sub_40A9AF(v26);
      CD3DRenderer_Present(pD3DRenderer);
      byte_505991 = 0;
    }
  }
  while ( !v29 );
  return dword_4FAA68 > 0;
}

//----- (00465FF0) --------------------------------------------------------
void __cdecl sub_465FF0()
{
  //int v0; // eax@1
  int v1; // ecx@3
  int v2; // ecx@4
  char v3; // [sp+0h] [bp-24h]@1
  int v4; // [sp+10h] [bp-14h]@3
  char *v5; // [sp+14h] [bp-10h]@1
  int v6; // [sp+20h] [bp-4h]@3
 struct class14 *pClass14;

 pClass14 = pGame->class14_obj;
 v5 = &v3;
 if (pClass14->dword_000004)
 {
    if ( !dword_69B00C )
    {
      v6 = 0;
      compile_error;//v1 = (int)operator new(0x710u);
      v4 = v1;
      LOBYTE(v6) = 1;
      if ( v1 )
        v2 = sub_45B10A(v1);
      else
        v2 = 0;
      LOBYTE(v6) = 0;
      dword_69B00C = v2;
      if ( v2 )
        Keyboard_resume(v2);
    }
 }
}

//----- (0040A9AF) --------------------------------------------------------
void *__thiscall sub_40A9AF(void *this)
{
  int *v1; // esi@1
  int v2; // esi@1

  v2 = (int)this;
  sub_40D7D5((void *)dword_5058D8, -1, 1);
  sub_40AB0A();
  sub_40DB10();
  sub_40D7D5((void *)dword_5058D8, -1, 1);
  sub_40B4B9();
  sub_40B2DD();
  sub_40B400();
  sub_40AC5F();
  sub_40DB10();
  sub_40D7D5((void *)dword_5058D8, -1, 1);
  sub_40B76F(v2);
  v1 = &dword_4FAC10;
  do
  {
    if ( *((_BYTE *)v1 - 64) )
      sub_40E133(*v1);
    v1 += 1067;
  }
  while ( (signed int)v1 < (signed int)&unk_5052C8 );
  dword_4FABBC = sub_40BB67(dword_4FAA6C);
  sub_40AA4E();
  return sub_40DB10();
}

//----- (0040AA4E) --------------------------------------------------------
void __cdecl sub_40AA4E()
{
  signed int v0; // ebx@1
  char v1; // ch@2@3
  char *v2; // esi@4
  signed int v3; // edi@6
  int v4; // esi@6
  int v5; // [sp-4h] [bp-2Ch]@4
  int v6; // [sp+Ch] [bp-1Ch]@10
  int v7; // [sp+10h] [bp-18h]@10
  int v8; // [sp+14h] [bp-14h]@10
  int v9; // [sp+18h] [bp-10h]@10
  int v10; // [sp+1Ch] [bp-Ch]@6
  char v11; // [sp+20h] [bp-8h]@1
  char v12; // [sp+21h] [bp-7h]@1
  char v13; // [sp+22h] [bp-6h]@1
  char v14; // [sp+24h] [bp-4h]@1
  char v15; // [sp+25h] [bp-3h]@1
  char v16; // [sp+26h] [bp-2h]@1

  v14 = 0;
  v15 = -1;
  v16 = 0;
  v11 = -1;
  v12 = 0;
  v13 = 0;
  v0 = (signed int)byte_4FABD1;
  do
  {
    if ( *(_BYTE *)(v0 - 1) )
    {
      if ( sub_40E2A7(*(_DWORD *)(v0 + 63)) == 2 )
      {
        BYTE3(v5) = v1;
        v2 = &v14;
        if ( !*(_BYTE *)v0 )
          v2 = &v11;
        LOWORD(v5) = *(_WORD *)v2;
        BYTE2(v5) = v2[2];
        v10 = (unsigned __int16)sub_40DEDB(v5);
        v3 = 0;
        v4 = v0 + 71;
        do
        {
          if ( *(_DWORD *)(v4 - 4) > 0 )
          {
            if ( v3 % 2 )
            {
              sub_40DBD3(v4, v10);
            }
            else
            {
              v6 = *(_DWORD *)v4;
              v8 = v6 + 2;
              v7 = *(_DWORD *)(v4 + 4);
              v9 = v7 + 2;
              sub_40DB27((int)&v6, v10, 1);
            }
          }
          ++v3;
          v4 += 28;
        }
        while ( v3 < 150 );
      }
    }
    v0 += 4268;
  }
  while ( v0 < (signed int)&unk_505289 );
}

//----- (0040AB0A) --------------------------------------------------------
void __cdecl sub_40AB0A()
{
  int v0; // eax@1
  int v1; // eax@1
  int v2; // eax@1
  int v3; // eax@1
  int v4; // eax@1
  int v5; // eax@1
  int v6; // [sp+Ch] [bp-18h]@1
  int v7; // [sp+10h] [bp-14h]@1
  int v8; // [sp+14h] [bp-10h]@1
  int v9; // [sp+18h] [bp-Ch]@1
  int v10; // [sp+1Ch] [bp-8h]@1
  int v11; // [sp+20h] [bp-4h]@1

  v7 = 0;
  v6 = 765;
  v8 = 843;
  v9 = 216;
  v10 = 8;
  v11 = 56;
  sub_40D9B1((int)&v6, (int)&v10, 2);
  v10 = 555;
  v11 = 56;
  sub_40D9B1((int)&v6, (int)&v10, 2);
  LOWORD(v0) = word_5058EC;
  v10 = 8;
  v6 = 283;
  v8 = 361;
  v7 = 166;
  v9 = 190;
  v11 = 13;
  sub_40D7EC((int)&v6, (int)&v10, v0, 2);
  LOWORD(v1) = word_5058EC;
  v10 = 555;
  v11 = 13;
  sub_40D7EC((int)&v6, (int)&v10, v1, 2);
  LOWORD(v2) = word_5058EC;
  v6 = 234;
  v8 = 283;
  v7 = 166;
  v9 = 190;
  v10 = 100;
  v11 = 296;
  sub_40D7EC((int)&v6, (int)&v10, v2, 2);
  LOWORD(v3) = word_5058EC;
  v10 = 492;
  v11 = 296;
  sub_40D7EC((int)&v6, (int)&v10, v3, 2);
  LOWORD(v4) = word_5058EC;
  v6 = 192;
  v8 = 234;
  v7 = 166;
  v9 = 190;
  v10 = 168;
  v11 = 296;
  sub_40D7EC((int)&v6, (int)&v10, v4, 2);
  v10 = 430;
  LOWORD(v5) = word_5058EC;
  v11 = 296;
  sub_40D7EC((int)&v6, (int)&v10, v5, 2);
}

//----- (0040AC5F) --------------------------------------------------------
void *__cdecl sub_40AC5F()
{
  int v0; // ecx@7
  int v1; // ecx@9
  int v2; // eax@11
  int v3; // ecx@12
  int v4; // ecx@14
  int v5; // eax@14
  int v6; // ecx@16
  int v7; // eax@16
  int v8; // ecx@18
  int v9; // eax@18
  int v11; // eax@20
  char Dest; // [sp+Ch] [bp-28h]@2
  int v13; // [sp+2Ch] [bp-8h]@2
  int v14; // [sp+30h] [bp-4h]@2

  if ( byte_4FAA77 )
  {
    sub_40DEBE(pGlobalTXT_LocalizationStrings[266], &Dest);
    v13 = 320 - sub_44C51E(dword_5058E4, &Dest) / 2;
    v14 = 306;
    sub_40D75D(-1, &Dest, (int)&v13);
  }
  sub_40DEBE(byte_505708, &Dest);
  if ( !dword_4FAA6C )
    sub_40DEB4("***", &Dest);
  v13 = 47 - sub_44C51E(dword_5058E0, &Dest) / 2;
  v14 = 21;
  sub_40D75D(-1, &Dest, (int)&v13);
  sub_40DEBE(byte_5057C4, &Dest);
  if ( dword_4FAA6C == 1 )
    sub_40DEB4("***", &Dest);
  v13 = 595 - sub_44C51E(dword_5058E0, &Dest) / 2;
  v14 = 21;
  sub_40D75D(-1, &Dest, (int)&v13);
  sub_40DEC8(dword_50572C[0], (int)&Dest);
  v13 = 123 - sub_44C51E(dword_5058E0, &Dest) / 2;
  v14 = 305;
  sub_40D75D(-1, &Dest, (int)&v13);
  sub_40DEC8(dword_5057E8, (int)&Dest);
  v13 = 515 - sub_44C51E(dword_5058E0, &Dest) / 2;
  v14 = 305;
  sub_40D75D(-1, &Dest, (int)&v13);
  sub_40DEC8(dword_505730[0], (int)&Dest);
  v13 = 188 - sub_44C51E(dword_5058E0, &Dest) / 2;
  v14 = 305;
  sub_40D75D(-1, &Dest, (int)&v13);
  sub_40DEC8(dword_5057EC, (int)&Dest);
  v13 = 451 - sub_44C51E(dword_5058E0, &Dest) / 2;
  v14 = 305;
  sub_40D75D(-1, &Dest, (int)&v13);
  v0 = dword_505734[0];
  if ( byte_4E185E )
    v0 = dword_4E1878 + dword_505734[0];
  sub_40DEC8(v0, (int)&Dest);
  v13 = 14 - 6 * sub_40DED8() / 2;
  v14 = 92;
  sub_40B102(-1, (int)&Dest, (int)&v13);
  v1 = dword_5057F0;
  if ( byte_4E185E )
    v1 = dword_4E1878 + dword_5057F0;
  sub_40DEC8(v1, (int)&Dest);
  v2 = sub_40DED8();
  v14 = 92;
  v13 = 561 - 6 * v2 / 2;
  sub_40B102(-1, (int)&Dest, (int)&v13);
  if ( byte_4E185E )
    v3 = dword_505738[0] + dword_4E187C;
  else
    v3 = dword_505738[0];
  sub_40DEC8(v3, (int)&Dest);
  v5 = sub_40DED8();
  v14 = 164;
  v13 = 14 - 6 * v5 / 2;
  sub_40B102(-1, (int)&Dest, (int)&v13);
  v4 = dword_5057F4;
  if ( byte_4E185E )
    v4 = dword_4E187C + dword_5057F4;
  sub_40DEC8(v4, (int)&Dest);
  v7 = sub_40DED8();
  v14 = 164;
  v13 = 561 - 6 * v7 / 2;
  sub_40B102(-1, (int)&Dest, (int)&v13);
  v6 = dword_50573C[0];
  if ( byte_4E185E )
    v6 = dword_4E1880 + dword_50573C[0];
  sub_40DEC8(v6, (int)&Dest);
  v9 = sub_40DED8();
  v14 = 236;
  v13 = 14 - 6 * v9 / 2;
  sub_40B102(-1, (int)&Dest, (int)&v13);
  v8 = dword_5057F8;
  if ( byte_4E185E )
    v8 = dword_4E1880 + dword_5057F8;
  sub_40DEC8(v8, (int)&Dest);
  v11 = sub_40DED8();
  v14 = 236;
  v13 = 561 - 6 * v11 / 2;
  sub_40B102(-1, (int)&Dest, (int)&v13);
  sub_40DEC8(dword_505740[0], (int)&Dest);
  v14 = 114;
  v13 = 10;
  sub_40B17E(-1, (int)&Dest, (int)&v13);
  sub_40DEC8(dword_5057FC, (int)&Dest);
  v13 = 557;
  v14 = 114;
  sub_40B17E(-1, (int)&Dest, (int)&v13);
  sub_40DEC8(dword_505744[0], (int)&Dest);
  v13 = 10;
  v14 = 186;
  sub_40B1F3(-1, (int)&Dest, (int)&v13);
  sub_40DEC8(dword_505800, (int)&Dest);
  v13 = 557;
  v14 = 186;
  sub_40B1F3(-1, (int)&Dest, (int)&v13);
  sub_40DEC8(dword_505748[0], (int)&Dest);
  v13 = 10;
  v14 = 258;
  sub_40B268(-1, (int)&Dest, (int)&v13);
  sub_40DEC8(dword_505804, (int)&Dest);
  v13 = 557;
  v14 = 258;
  return sub_40B268(-1, (int)&Dest, (int)&v13);
}

//----- (0040B102) --------------------------------------------------------
void *__fastcall sub_40B102(int a1, int a2, int a3)
{
  int v3; // esi@1
  int v4; // eax@1
  char v5; // zf@2
  unsigned __int8 v6; // bl@2
  int v7; // eax@3
  int v8; // ecx@3
  int v10; // [sp+8h] [bp-18h]@3
  int v11; // [sp+Ch] [bp-14h]@3
  int v12; // [sp+10h] [bp-10h]@3
  int v13; // [sp+14h] [bp-Ch]@3
  int v14; // [sp+18h] [bp-8h]@1
  int v15; // [sp+1Ch] [bp-4h]@1

  v3 = a2;
  sub_40D7D5((void *)dword_5058D8, -1, 1);
  v4 = *(_DWORD *)(a3 + 4);
  v14 = *(_DWORD *)a3;
  v15 = v4;
  do
  {
    v6 = *(_BYTE *)v3++;
    v5 = v6 == 0;
    if ( v6 )
    {
      v7 = 22 * v6;
      v8 = v7 - 864;
      v7 -= 842;
      v12 = v7;
      LOWORD(v7) = word_5058EC;
      v10 = v8;
      v11 = 190;
      v13 = 207;
      sub_40D7EC((int)&v10, (int)&v14, v7, 1);
      v14 += 22;
      v5 = v6 == 0;
    }
  }
  while ( !v5 );
  return sub_40DB10();
}

//----- (0040B17E) --------------------------------------------------------
void *__fastcall sub_40B17E(int a1, int a2, int a3)
{
  int v3; // esi@1
  int v4; // eax@1
  char v5; // zf@2
  unsigned __int8 v6; // bl@2
  int v7; // eax@3
  int v9; // [sp+8h] [bp-18h]@3
  int v10; // [sp+Ch] [bp-14h]@3
  int v11; // [sp+10h] [bp-10h]@3
  int v12; // [sp+14h] [bp-Ch]@3
  int v13; // [sp+18h] [bp-8h]@1
  int v14; // [sp+1Ch] [bp-4h]@1

  v3 = a2;
  sub_40D7D5((void *)dword_5058D8, -1, 1);
  v4 = *(_DWORD *)(a3 + 4);
  v13 = *(_DWORD *)a3;
  v14 = v4;
  do
  {
    v6 = *(_BYTE *)v3++;
    v5 = v6 == 0;
    if ( v6 )
    {
      v7 = 13 * v6;
      v9 = v7 - 370;
      v11 = v7 - 357;
      v10 = 128;
      v12 = 138;
      sub_40D9B1((int)&v9, (int)&v13, 2);
      v13 += 13;
      v5 = v6 == 0;
    }
  }
  while ( !v5 );
  return sub_40DB10();
}

//----- (0040B1F3) --------------------------------------------------------
void *__fastcall sub_40B1F3(int a1, int a2, int a3)
{
  int v3; // esi@1
  int v4; // eax@1
  char v5; // zf@2
  unsigned __int8 v6; // bl@2
  int v7; // eax@3
  int v9; // [sp+8h] [bp-18h]@3
  int v10; // [sp+Ch] [bp-14h]@3
  int v11; // [sp+10h] [bp-10h]@3
  int v12; // [sp+14h] [bp-Ch]@3
  int v13; // [sp+18h] [bp-8h]@1
  int v14; // [sp+1Ch] [bp-4h]@1

  v3 = a2;
  sub_40D7D5((void *)dword_5058D8, -1, 1);
  v4 = *(_DWORD *)(a3 + 4);
  v13 = *(_DWORD *)a3;
  v14 = v4;
  do
  {
    v6 = *(_BYTE *)v3++;
    v5 = v6 == 0;
    if ( v6 )
    {
      v7 = 13 * v6;
      v9 = v7 - 370;
      v11 = v7 - 357;
      v10 = 138;
      v12 = 148;
      sub_40D9B1((int)&v9, (int)&v13, 2);
      v13 += 13;
      v5 = v6 == 0;
    }
  }
  while ( !v5 );
  return sub_40DB10();
}

//----- (0040B268) --------------------------------------------------------
void *__fastcall sub_40B268(int a1, int a2, int a3)
{
  int v3; // esi@1
  int v4; // eax@1
  char v5; // zf@2
  unsigned __int8 v6; // bl@2
  int v7; // eax@3
  int v9; // [sp+8h] [bp-18h]@3
  int v10; // [sp+Ch] [bp-14h]@3
  int v11; // [sp+10h] [bp-10h]@3
  int v12; // [sp+14h] [bp-Ch]@3
  int v13; // [sp+18h] [bp-8h]@1
  int v14; // [sp+1Ch] [bp-4h]@1

  v3 = a2;
  sub_40D7D5((void *)dword_5058D8, -1, 1);
  v4 = *(_DWORD *)(a3 + 4);
  v13 = *(_DWORD *)a3;
  v14 = v4;
  do
  {
    v6 = *(_BYTE *)v3++;
    v5 = v6 == 0;
    if ( v6 )
    {
      v7 = 13 * v6;
      v9 = v7 - 370;
      v11 = v7 - 357;
      v10 = 148;
      v12 = 158;
      sub_40D9B1((int)&v9, (int)&v13, 2);
      v13 += 13;
      v5 = v6 == 0;
    }
  }
  while ( !v5 );
  return sub_40DB10();
}

//----- (0040B2DD) --------------------------------------------------------
void __cdecl sub_40B2DD()
{
  int v0; // eax@1
  int v1; // eax@3
  int v2; // esi@3
  int v3; // eax@3
  int v4; // esi@5
  int v5; // eax@5
  int v6; // [sp+0h] [bp-18h]@3
  int v7; // [sp+4h] [bp-14h]@3
  int v8; // [sp+8h] [bp-10h]@3
  int v9; // [sp+Ch] [bp-Ch]@3
  int v10; // [sp+10h] [bp-8h]@3
  int v11; // [sp+14h] [bp-4h]@3

  v0 = dword_50572C[0];
  if ( dword_50572C[0] > dword_4E1884 )
    v0 = dword_4E1884;
  v7 = 0;
  v6 = 892;
  v8 = 937;
  v10 = 102;
  v2 = 200 * v0 / dword_4E1884;
  v9 = v2;
  v11 = 297 - v2;
  sub_40D9B1((int)&v6, (int)&v10, 2);
  v7 = 0;
  v3 = 203 - v2;
  v11 = 203 - v2;
  LOWORD(v3) = word_5058EC;
  v6 = 384;
  v8 = 452;
  v9 = 94;
  v10 = 91;
  sub_40D7EC((int)&v6, (int)&v10, v3, 2);
  v1 = dword_5057E8;
  if ( dword_5057E8 > dword_4E1884 )
    v1 = dword_4E1884;
  v7 = 0;
  v6 = 892;
  v8 = 937;
  v10 = 494;
  v4 = 200 * v1 / dword_4E1884;
  v9 = v4;
  v11 = 297 - v4;
  sub_40D9B1((int)&v6, (int)&v10, 2);
  LOWORD(v5) = word_5058EC;
  v6 = 384;
  v8 = 452;
  v7 = 94;
  v9 = 188;
  v10 = 483;
  v11 = 203 - v4;
  sub_40D7EC((int)&v6, (int)&v10, v5, 2);
}

//----- (0040B400) --------------------------------------------------------
void __cdecl sub_40B400()
{
  int v0; // eax@1
  int v1; // eax@4
  int v2; // ecx@4
  signed int v3; // eax@5
  int v4; // eax@8
  int v5; // esi@8
  int v6; // [sp+4h] [bp-18h]@4
  int v7; // [sp+8h] [bp-14h]@4
  int v8; // [sp+Ch] [bp-10h]@4
  int v9; // [sp+10h] [bp-Ch]@4
  int v10; // [sp+14h] [bp-8h]@4
  int v11; // [sp+18h] [bp-4h]@4

  v0 = dword_505730[0];
  if ( dword_505730[0] <= 100 )
  {
    if ( dword_505730[0] <= 0 )
      goto LABEL_5;
  }
  else
  {
    v0 = 100;
  }
  v7 = 0;
  v6 = 843;
  v1 = 200 * v0 / 100;
  v8 = 867;
  v10 = 177;
  v9 = v1;
  v2 = 297 - v1;
  LOWORD(v1) = word_5058EC;
  v11 = v2;
  sub_40D7EC((int)&v6, (int)&v10, v1, 2);
LABEL_5:
  v3 = dword_5057EC;
  if ( dword_5057EC <= 100 )
  {
    if ( dword_5057EC <= 0 )
      return;
  }
  else
  {
    v3 = 100;
  }
  v7 = 0;
  v6 = 843;
  v4 = 200 * v3 / 100;
  v8 = 867;
  v10 = 439;
  v9 = v4;
  v5 = 297 - v4;
  LOWORD(v4) = word_5058EC;
  v11 = v5;
  sub_40D7EC((int)&v6, (int)&v10, v4, 2);
}

//----- (004907E7) --------------------------------------------------------
__int16 __thiscall sub_4907E7(struct Player *_this, int a2)
{
  unsigned __int8 v2; // zf@1
  char v3; // sf@1
  unsigned __int8 v4; // of@1
  __int16 v5; // si@1
  int v7; // eax@1
  int v8; // edx@1
  __int16 result; // ax@2
  __int16 v10; // [sp+8h] [bp-8h]@1
  __int16 v11; // [sp+Ch] [bp-4h]@1

  v11 = sub_40DEF3(0xFFu, 0x23u, 0);
  v10 = sub_40DEF3(0, 0xFFu, 0);
  v5 = sub_40DEF3(0xFFu, 0xFFu, 0xFFu);
  v7 = array_4ED7B0[4 * (a2 + 7 * GetRaceByFace(_this))];
 return v11;
  //v4 = __SETO__(v8, v7);
  //v3 = v8 - v7 < 0;
  //v2 = v8 == v7;
  if ( v8 >= v7 )
  {
    result = v10;
    runtime_warning;
    //if ( (unsigned __int8)(v3 ^ v4) | v2 )
      result = v5;
  }
  else
  {
    result = v11;
  }
  return result;
}

//----- (0040B4B9) --------------------------------------------------------
void __cdecl sub_40B4B9()
{
  int v0; // ebx@1
  int v1; // edi@1
  int v2; // esi@1
  int v3; // edx@2
  int v4; // eax@3
  int v5; // ecx@3
  int v6; // eax@3
  int v7; // ecx@4
  int v8; // eax@16
  int v9; // ecx@16
  int v10; // eax@16
  signed int v11; // edi@18
  int v12; // ecx@20
  int v13; // esi@20
  int v14; // eax@23
  int v15; // eax@25
  int v16; // ecx@25
  int v17; // esi@26
  int v18; // eax@29
  int *v19; // ecx@29
  int v20; // ecx@31
  int v21; // [sp-4h] [bp-2Ch]@8
  int v22; // [sp+Ch] [bp-1Ch]@8
  int v23; // [sp+10h] [bp-18h]@8
  int v24; // [sp+14h] [bp-14h]@8
  int v25; // [sp+18h] [bp-10h]@8
  int v26; // [sp+1Ch] [bp-Ch]@1
  int v27; // [sp+20h] [bp-8h]@1
  int v28; // [sp+24h] [bp-4h]@1

  v2 = sub_40BB49(dword_4FAA6C);
  v0 = 0;
  v1 = 0;
  v27 = 327;
  v28 = (640 - 96 * v2) / (v2 + 1);
  v26 = (640 - 96 * v2) / (v2 + 1);
  while ( v1 < v2 )
  {
    v3 = dword_4FAA6C;
    if ( byte_4E185D != (_BYTE)v0 )
    {
      v4 = 188 * dword_4FAA6C + 8 * v1;
      v5 = *(int *)((char *)&dword_505774 + v4);
      v6 = *(int *)((char *)dword_505778 + v4);
      v26 += v5;
      v27 += v6;
    }
    v7 = dword_50574C[v1 + 47 * dword_4FAA6C];
    if ( v7 == -1 )
    {
      ++v2;
      goto LABEL_15;
    }
    if ( v1 != dword_4FAA4C )
    {
      if ( byte_505728[188 * dword_4FAA6C] == (_BYTE)v0 && byte_505881 == (_BYTE)v0 )
      {
        v22 = 192;
        v24 = 288;
        v23 = v0;
        v25 = 128;
        v21 = 2;
LABEL_12:
        sub_40D9B1((int)&v22, (int)&v26, v21);
        goto LABEL_13;
      }
      sub_40BB12(v7, (int)&v22);
      if ( !sub_40BF15(dword_4FAA6C, v1) )
      {
        v0 = 0;
        v21 = 0;
        goto LABEL_12;
      }
      sub_40D9B1((int)&v22, (int)&v26, 2);
      v0 = 0;
    }
LABEL_13:
    v3 = dword_4FAA6C;
    v26 += v28 + 96;
LABEL_15:
    if ( byte_4E185D != (_BYTE)v0 )
    {
      v8 = 188 * v3 + 8 * v1;
      v9 = *(int *)((char *)&dword_505774 + v8);
      v10 = *(int *)((char *)dword_505778 + v8);
      v26 -= v9;
      v27 -= v10;
    }
    ++v1;
  }
  v11 = 0;
  do
  {
    compile_error;//if ( byte_4FAA76 == (_BYTE)v0 )
    if (v0)
    {
      v13 = 32 * v11;
      v12 = dword_4FAA78[8 * v11];
      if ( v12 != -1 )
      {
        sub_40BB12(v12, (int)&v22);
        sub_40D9B1((int)&v22, (int)((char *)&dword_4FAA90 + v13), v0);
      }
      if ( byte_4FAA7C[v13] != (_BYTE)v0 )
      {
        v26 = *(int *)((char *)&dword_4FAA90 + v13) + 12;
        v14 = *(int *)((char *)&dword_4FAA94 + v13) + 40;
        v27 = *(int *)((char *)&dword_4FAA94 + v13) + 40;
        LOWORD(v14) = word_5058EC;
        v22 = 843;
        v24 = 916;
        v23 = 200;
        v25 = 216;
        sub_40D7EC((int)&v22, (int)&v26, v14, 2);
      }
    }
    else
    {
      if ( dword_4FAA34 <= v0 )
      {
        if ( v11 == 9 )
        {
          compile_error;//byte_4FAA76 = v0;
          compile_error;//byte_4FAA75 = v0;
          dword_4FAA34 = 5;
        }
        v18 = 32 * v11;
        v19 = &dword_4FAA78[8 * v11];
        if ( *v19 != -1 )
          dword_4FABC4 = *v19;
        *v19 = -1;
        *(int *)((char *)&dword_4FAA90 + v18) = *(int *)((char *)dword_4FAA80 + v18);
        v20 = *(int *)((char *)dword_4FAA84 + v18);
        byte_4FAA7C[v18] = v0;
        *(int *)((char *)&dword_4FAA94 + v18) = v20;
      }
      else
      {
        v15 = 32 * v11;
        v16 = dword_4FAA78[8 * v11];
        if ( v16 != -1 )
        {
          v17 = (int)((char *)&dword_4FAA90 + v15);
          *(_DWORD *)v17 += *(int *)((char *)&dword_4FAA88 + v15);
          *(int *)((char *)&dword_4FAA94 + v15) += *(int *)((char *)&dword_4FAA8C + v15);
          sub_40BB12(v16, (int)&v22);
          sub_40D9B1((int)&v22, v17, v0);
        }
      }
    }
    ++v11;
  }
  while ( v11 < 10 );
  compile_error;//if ( byte_4FAA76 != (_BYTE)v0 )
  if (!v0)
    --dword_4FAA34;
  v22 = 192;
  v24 = 288;
  v23 = v0;
  v25 = 128;
  v26 = 120;
  v27 = 18;
  sub_40D9B1((int)&v22, (int)&v26, v0);
}

//----- (0040B76F) --------------------------------------------------------
void __fastcall sub_40B76F(int a1)
{
  int v1; // eax@3
  int v2; // eax@3
  int v3; // eax@4
  int v4; // esi@4
  int v5; // edx@6
  int v6; // ecx@6
  signed int v7; // ebx@11
  int v8; // eax@15
  signed int v9; // ecx@15
  int v10; // eax@20
  int v11; // ecx@20
  int v12; // eax@20
  int v13; // ecx@21
  double v14; // st7@22
  int *v15; // edx@23
  int v16; // eax@32
  char v17; // zf@37
  int v18; // eax@41
  int v19; // eax@46
  int v20; // ecx@46
  int v21; // eax@46
  int v22; // [sp-4h] [bp-2Ch]@6
  int v23; // [sp-4h] [bp-2Ch]@28
  int v24; // [sp+Ch] [bp-1Ch]@6
  int v25; // [sp+10h] [bp-18h]@6
  int v26; // [sp+14h] [bp-14h]@6
  int v27; // [sp+18h] [bp-10h]@6
  int v28; // [sp+1Ch] [bp-Ch]@20
  int v29; // [sp+20h] [bp-8h]@20
  int v30; // [sp+24h] [bp-4h]@1

  v30 = a1;
  if ( dword_4FAA4C != -1 )
  {
    if ( dword_4FAA38 >= 9 )
    {
      dword_4FAA48 = 18;
      dword_4FAA44 = 120;
      v2 = sub_40BB49(dword_4FAA6C);
      v1 = (640 - 96 * v2) / v2 + 96;
      if ( byte_4E185D )
      {
        v4 = 188 * dword_4FAA6C + 8 * dword_4FAA4C;
        dword_4FAA3C = (dword_4FAA4C * v1 + *(int *)((char *)&dword_505774 + v4) - 120) / 10;
        v3 = (*(int *)((char *)dword_505778 + v4) + 309) / 10;
      }
      else
      {
        dword_4FAA3C = (dword_4FAA4C * v1 - 120) / 10;
        v3 = 30;
      }
      dword_4FAA48 += v3;
      dword_4FAA44 += dword_4FAA3C;
      v25 = 0;
      dword_4FAA40 = v3;
      v24 = 192;
      v26 = 288;
      v27 = 128;
      v22 = 2;
      v5 = (int)&dword_4FAA44;
      v6 = (int)&v24;
      goto LABEL_7;
    }
    v25 = 0;
    v6 = (int)&v24;
    v5 = (int)&dword_4FAA44;
    v22 = 2;
    v27 = 128;
    v26 = 288;
    v24 = 192;
    if ( dword_4FAA38 )
    {
      dword_4FAA44 += dword_4FAA3C;
      dword_4FAA48 += dword_4FAA40;
LABEL_7:
      sub_40D9B1(v6, v5, v22);
      goto LABEL_11;
    }
    dword_4FAA44 += dword_4FAA3C;
    dword_4FAA48 += dword_4FAA40;
    sub_40D9B1((int)&v24, (int)&dword_4FAA44, 2);
    dword_4FAA4C = -1;
  }
LABEL_11:
  v7 = (signed int)dword_4FAA78;
  if ( dword_4FAA50 != -1 )
  {
    if ( v30 <= 10 )
    {
      if ( v30 == 10 )
      {
        sub_40BB12(dword_4FAA50, (int)&v24);
        v8 = 0;
        v9 = (signed int)dword_4FAA78;
        while ( *(_DWORD *)v9 != -1 )
        {
          v9 += 32;
          ++v8;
          if ( v9 >= (signed int)&dword_4FABB8 )
            goto LABEL_20;
        }
        dword_4FAA78[8 * v8] = dword_4FAA50;
        byte_4FAA7C[32 * v8] = 1;
LABEL_20:
        v10 = 32 * v8;
        v11 = *(int *)((char *)dword_4FAA80 + v10);
        v12 = *(int *)((char *)dword_4FAA84 + v10);
        v28 = v11;
        v29 = v12;
        sub_40D9B1((int)&v24, (int)&v28, 0);
        dword_4FAA50 = -1;
      }
    }
    else
    {
      sub_40BB12(dword_4FAA50, (int)&v24);
      dword_4FAA5C += dword_4FAA54;
      dword_4FAA60 += dword_4FAA58;
      sub_40D9B1((int)&v24, (int)&dword_4FAA5C, 0);
    }
  }
  v13 = dword_4FABC0;
  if ( dword_4FABC0 != -1 )
  {
    v14 = (double)v30;
    if ( v14 > *(double *)&byte_4D8410[136] )
    {
      sub_40BB12(dword_4FABC0, (int)&v24);
      v15 = &dword_4FAA5C;
      dword_4FAA5C += dword_4FAA54;
      dword_4FAA60 += dword_4FAA58;
LABEL_28:
      v23 = 2;
LABEL_29:
      sub_40D9B1((int)&v24, (int)v15, v23);
      return;
    }
    if ( v14 == *(double *)&byte_4D8410[136] )
    {
      sub_40BF77(dword_4FAA6C, dword_4FABC0);
      v13 = dword_4FABC0;
      goto LABEL_26;
    }
    if ( v14 == *(double *)&byte_4D8410[128] )
    {
      dword_4FAA5C = 272;
      dword_4FAA60 = 173;
      v16 = 0;
      do
      {
        if ( *(_DWORD *)v7 == -1 )
          break;
        v7 += 32;
        ++v16;
      }
      while ( v7 < (signed int)&dword_4FABB8 );
      v30 = 32 * v16;
      dword_4FAA54 = (dword_4FAA80[8 * v16] - 272) / 5;
      dword_4FAA58 = (dword_4FAA84[8 * v16] - 173) / 5;
      sub_40BB12(dword_4FABC0, (int)&v24);
      v28 = 272;
      v29 = 173;
      goto LABEL_27;
    }
    if ( v14 >= *(double *)&byte_4D8410[128] )
    {
      v17 = v30 == 0;
    }
    else
    {
      v17 = v30 == 0;
      if ( v30 > 0 )
      {
        sub_40BB12(dword_4FABC0, (int)&v24);
        v15 = &dword_4FAA5C;
        dword_4FAA5C += dword_4FAA54;
        dword_4FAA60 += dword_4FAA58;
        v23 = 0;
        goto LABEL_29;
      }
    }
    if ( !v17 )
    {
LABEL_26:
      sub_40BB12(v13, (int)&v24);
      v28 = 272;
      v29 = 173;
LABEL_27:
      v15 = &v28;
      goto LABEL_28;
    }
    sub_40BB12(dword_4FABC0, (int)&v24);
    v18 = 0;
    while ( *(_DWORD *)v7 != -1 )
    {
      v7 += 32;
      ++v18;
      if ( v7 >= (signed int)&dword_4FABB8 )
        goto LABEL_46;
    }
    dword_4FAA78[8 * v18] = dword_4FABC0;
LABEL_46:
    v19 = 32 * v18;
    v20 = *(int *)((char *)dword_4FAA80 + v19);
    v21 = *(int *)((char *)dword_4FAA84 + v19);
    v28 = v20;
    v29 = v21;
    sub_40D9B1((int)&v24, (int)&v28, 0);
    dword_4FABC0 = -1;
  }
}

//----- (0047CB57) --------------------------------------------------------
int __stdcall sub_47CB57(unsigned char *pIndexedPixels, int a2, unsigned int uNumPixels)
{
  signed int result; // eax@2
  int v4; // eax@3
  char *v5; // edx@3
  char v6; // bl@3
  double v7; // st7@3
  int v8; // eax@4
  int v9; // eax@5
  unsigned __int8 v10; // sf@6
  unsigned __int8 v11; // of@6
  signed int v12; // edi@7
  double v13; // st6@7
  int v14; // esi@9
  signed int v15; // ecx@10
  signed int v16; // esi@10
  char v17[256]; // [sp+4h] [bp-124h]@9
  char *v18; // [sp+104h] [bp-24h]@3
  int v19; // [sp+108h] [bp-20h]@3
  int v20; // [sp+10Ch] [bp-1Ch]@3
  int v21; // [sp+110h] [bp-18h]@3
  int v22; // [sp+114h] [bp-14h]@3
  float v23; // [sp+118h] [bp-10h]@3
  float v24; // [sp+11Ch] [bp-Ch]@3
  int v25; // [sp+120h] [bp-8h]@3
  int v26; // [sp+124h] [bp-4h]@5
  int v27; // [sp+130h] [bp+8h]@7
  signed int v28; // [sp+134h] [bp+Ch]@3
  int v29; // [sp+134h] [bp+Ch]@7
  float v30; // [sp+138h] [bp+10h]@7
  int v31; // [sp+138h] [bp+10h]@9

  if ( pD3DRenderer->dword_040088 )
  {
    result = 0;
  }
  else
  {
    v5 = sub_41F50D(a2, 0, 1);
    v7 = 0.0;
    v6 = pD3DRenderer->dword_0400D4;
    v20 = pD3DRenderer->dword_0400D8;
    v22 = pD3DRenderer->dword_0400DC;
    v23 = 0.0;
    v21 = pD3DRenderer->dword_0400E0;
    v4 = 0;
    v18 = v5;
    v24 = 0.0;
    v19 = pD3DRenderer->dword_0400D4;
    v28 = 0;
    v25 = 0;
    if ( uNumPixels > 0 )
    {
      do
      {
        v8 = *(_BYTE *)(v4 + pIndexedPixels);
        if ( v8 )
        {
          v9 = *(_WORD *)&v5[2 * v8];
          v7 = v7 + (double)((v20 & v9) >> (pD3DRenderer->dword_0400D4 + pD3DRenderer->dword_0400D0));
          ++v28;
          v26 = v21 & v9;
          v23 = (double)((v22 & v9) >> pD3DRenderer->dword_0400D4) + v23;
          v24 = (double)(v21 & v9) + v24;
        }
        v4 = v25 + 1;
        compile_error;//v11 = __SETO__(v25 + 1, uNumPixels);
        v10 = v25++ + 1 - uNumPixels < 0;
      }
      while ( v10 ^ v11 );
    }
    v13 = 1.0 / (double)v28;
    v30 = v13;
    v27 = (signed __int64)(v13 * v7);
    v26 = (signed __int64)(v30 * v23);
    v25 = (signed __int64)(v30 * v24);
    v12 = 0;
    v29 = pD3DRenderer->dword_0400D4 + pD3DRenderer->dword_0400D0;
    while ( 1 )
    {
      v14 = *(_WORD *)&v18[2 * v12];
      v31 = abs(v27 - ((signed int)(unsigned __int16)(v20 & *(_WORD *)&v18[2 * v12]) >> v29));
      BYTE3(v31) = abs(v26 - ((v22 & v14) >> v6)) + v31;
      v17[v12++] = abs(v25 - (v21 & v14)) + BYTE3(v31);
      if ( v12 >= 256 )
        break;
      v6 = v19;
    }
    result = 0;
    v16 = (signed int)&unk_989680;
    v15 = 0;
    do
    {
      if ( (unsigned __int8)v17[v15] < v16 )
      {
        v16 = (unsigned __int8)v17[v15];
        result = v15;
      }
      ++v15;
    }
    while ( v15 < 256 );
  }
  return result;
}

//----- (0040BB12) --------------------------------------------------------
int __fastcall sub_40BB12(int a1, int a2)
{
  int result; // eax@1
  int v3; // esi@1
  int v4; // edx@1
  int v5; // ecx@1

  v3 = a2;
  v4 = dword_4DF3C8[27 * a1] % 10;
  v5 = (dword_4DF3C8[27 * a1] / 10 << 7) + 220;
  *(_DWORD *)(v3 + 4) = v5;
  *(_DWORD *)v3 = 96 * v4;
  result = 96 * v4 + 96;
  *(_DWORD *)(v3 + 12) = v5 + 128;
  *(_DWORD *)(v3 + 8) = result;
  return result;
}

//----- (0040BB49) --------------------------------------------------------
int __fastcall sub_40BB49(int a1)
{
  int result; // eax@1
  signed int v2; // edx@1
  int *v3; // ecx@1

  result = 0;
  v3 = &dword_50574C[47 * a1];
  v2 = 10;
  do
  {
    if ( *v3 != -1 )
      ++result;
    ++v3;
    --v2;
  }
  while ( v2 );
  return result;
}

//----- (00443EF8) --------------------------------------------------------
void __cdecl LoadLevel_InitializeLevelEvt()
{
 int i, j;

 if (!uLevelEvtFileSize)
   return;

 memset(unk_5B5928, 0, 0xC80);

 dword_5B65C8 = 0;

 uLevelEvtNumEvents = 0;
 memset(pLevelEvents, 128, 4400 * 12);

 for (i = 0, j = 0; j < uLevelEvtFileSize; ++i)
 {
  pLevelEvents[i].dword_000000 = pLevelEvt[j + 1] + ((unsigned short)pLevelEvt[j + 2] << 8);
  pLevelEvents[i].dword_000004 = pLevelEvt[j + 3];
  pLevelEvents[i].dword_000008 = j;
  j += pLevelEvt[j] + 1;

  uLevelEvtNumEvents++;
 }
}

//----- (0040BB67) --------------------------------------------------------
signed int __fastcall sub_40BB67(int a1)
{
  signed int result; // eax@1
  int v2; // ebx@1
  int v3; // esi@1
  char v4; // zf@1
  int v5; // eax@3
  int v6; // eax@4
  int v7; // eax@6
  int v8; // ecx@6
  int v9; // eax@10
  int v10; // ecx@10
  int v11; // eax@10
  char v12; // ch@2@11
  int v13; // ST00_4@12
  __int16 v14; // ax@12
  int v15; // eax@13
  int v16; // ecx@13
  int v17; // eax@13
  char v18; // ch@2@16
  char v19; // al@16
  int v20; // ST00_4@19
  __int16 v21; // ax@19
  int v22; // [sp+Ch] [bp-3Ch]@3
  int v23; // [sp+10h] [bp-38h]@3
  int v24; // [sp+14h] [bp-34h]@3
  int v25; // [sp+18h] [bp-30h]@3
  char v26; // [sp+1Ch] [bp-2Ch]@2
  int v27; // [sp+28h] [bp-20h]@1
  int v28; // [sp+2Ch] [bp-1Ch]@3
  int v29; // [sp+30h] [bp-18h]@3
  int i; // [sp+34h] [bp-14h]@4
  int v31; // [sp+38h] [bp-10h]@1
  int v32; // [sp+3Ch] [bp-Ch]@3
  int v33; // [sp+40h] [bp-8h]@1
  char v34; // [sp+44h] [bp-4h]@12
  char v35; // [sp+45h] [bp-3h]@12
  char v36; // [sp+46h] [bp-2h]@12

  v3 = a1;
  v33 = 0;
  result = -1;
  v2 = 188 * a1;
  v27 = a1;
  v4 = byte_505728[188 * a1] == 0;
  v31 = -1;
  if ( !v4 )
  {
    if ( sub_40DD2F((int)&v26) )
    {
      v5 = sub_40BB49(v3);
      v32 = 0;
      v28 = v5;
      v23 = 327;
      v25 = 455;
      v22 = (640 - 96 * v5) / (v5 + 1);
      v29 = v22 + 96;
      v24 = v22 + 96;
      if ( v5 > 0 )
      {
        v6 = 47 * v3;
        for ( i = 47 * v3; ; v6 = i )
        {
          v8 = v33;
          v7 = 4 * (v33 + v6) + 5265228;
          if ( *(_DWORD *)v7 == -1 )
          {
            do
            {
              v7 += 4;
              ++v8;
            }
            while ( *(_DWORD *)v7 == -1 );
            v33 = v8;
          }
          if ( byte_4E185D )
          {
            v9 = v2 + 8 * v8;
            v10 = *(int *)((char *)&dword_505774 + v9);
            v11 = *(int *)((char *)dword_505778 + v9);
            v22 += v10;
            v24 += v10;
            v23 += v11;
            v25 += v11;
          }
          if ( sub_40DD93((int)&v26, (int)&v22) )
            break;
          v34 = 0;
          v35 = 0;
          v36 = 0;
          BYTE3(v13) = v12;
          LOWORD(v13) = *(_WORD *)&v34;
          BYTE2(v13) = 0;
          v14 = sub_40DEDB(v13);
          sub_40DB27((int)&v22, v14, 0);
          v22 += v29;
          v24 += v29;
          if ( byte_4E185D )
          {
            v15 = v2 + 8 * v33;
            v16 = *(int *)((char *)&dword_505774 + v15);
            v17 = *(int *)((char *)dword_505778 + v15);
            v22 -= v16;
            v24 -= v16;
            v23 -= v17;
            v25 -= v17;
          }
          ++v33;
          ++v32;
          if ( v32 >= v28 )
            goto LABEL_20;
        }
        v31 = v32;
        v19 = sub_40BF15(v27, v32);
        v34 = -1;
        if ( v19 )
        {
          v35 = -1;
          v36 = -1;
        }
        else
        {
          v35 = 0;
          v36 = 0;
        }
        BYTE3(v20) = v18;
        LOWORD(v20) = *(_WORD *)&v34;
        BYTE2(v20) = v36;
        v21 = sub_40DEDB(v20);
        sub_40DB27((int)&v22, v21, 0);
      }
    }
LABEL_20:
    result = v31;
  }
  return result;
}

//----- (004CA564) --------------------------------------------------------
void __cdecl sub_4CA564()
{
  size_t v0; // eax@1
  int v1; // [sp+4h] [bp-3Ch]@1
  char v2; // [sp+20h] [bp-20h]@1
  char v3; // [sp+33h] [bp-Dh]@1
  int v4; // [sp+3Ch] [bp-4h]@1

  v2 = v3;
  CGame_stru0_sub_40E2F6((int)&v2, 0);
  v0 = strlen(&byte_4D8410[11432]);
  sub_40E32E((int)&v2, &byte_4D8410[11432], v0);
  v4 = 0;
  sub_4CA392(&v1, (int)&v2);
  v1 = 5091500;
  _CxxThrowException(&v1, 5097136);
}

//----- (004CA634) --------------------------------------------------------
void *__thiscall sub_4CA634(void *this, int a2)
{
  void *v3; // esi@1

  v3 = this;
  sub_4CA479(this, a2);
  *(_DWORD *)v3 = 5091500;
  return v3;
}

//----- (004CA676) --------------------------------------------------------
int __cdecl sub_4CA676()
{
  return atexit(0);
}

//----- (004CAEC7) --------------------------------------------------------
int __cdecl sub_4CAEC7()
{
  return _unlock(9);
}

//----- (004CAF26) --------------------------------------------------------
int __cdecl sub_4CAF26()
{
  return _unlock(9);
}

//----- (004CAFC6) --------------------------------------------------------
int __cdecl sub_4CAFC6()
{
  return _unlock(9);
}

//----- (004CB01E) --------------------------------------------------------
int __cdecl sub_4CB01E()
{
  return _unlock(9);
}

//----- (004CDA08) --------------------------------------------------------
int __cdecl sub_4CDA08()
{
  return _unlock(9);
}

//----- (004CDA91) --------------------------------------------------------
int __cdecl sub_4CDA91()
{
  return _unlock(9);
}

//----- (004CE45A) --------------------------------------------------------
function_error;//int __usercall sub_4CE45A<eax>(int result<eax>, int a2<ecx>)
int sub_4CE45A(int result, int a2)
{
  char v2; // zf@1

  v2 = *(_DWORD *)(a2 + 8) == 0;
  *(_DWORD *)a2 = 5091724;
  if ( !v2 )
    result = operator_delete(result, *(_DWORD *)(a2 + 4));
  return result;
}

//----- (004CEFD3) --------------------------------------------------------
int __cdecl sub_4CEFD3()
{
  return _unlock(9);
}

//----- (004CF121) --------------------------------------------------------
int __cdecl sub_4CF121()
{
  return _unlock(9);
}

//----- (004CF1E1) --------------------------------------------------------
int __cdecl sub_4CF1E1()
{
  return _unlock(9);
}

//----- (004CF25C) --------------------------------------------------------
int __cdecl sub_4CF25C()
{
  return _unlock(9);
}

//----- (004CFBA2) --------------------------------------------------------
char __cdecl sub_4CFBA2(int a1)
{
  HMODULE v1; // eax@1
  int v2; // ecx@2

  *(_DWORD *)a1 = 0;
  v1 = GetModuleHandleA(0);
  if ( *(_WORD *)v1 == 23117 )
  {
    v2 = *((_DWORD *)v1 + 15);
    if ( v2 )
    {
      v1 = (char *)v1 + v2;
      *(_BYTE *)a1 = *((_BYTE *)v1 + 26);
      LOBYTE(v1) = *((_BYTE *)v1 + 27);
      *(_BYTE *)(a1 + 1) = (_BYTE)v1;
    }
  }
  return (char)v1;
}

//----- (004CFBCF) --------------------------------------------------------
__int32 __cdecl sub_4CFBCF()
{
  __int32 result; // eax@4
  CHAR *v1; // ecx@6
  CHAR v2; // al@7
  char *v3; // eax@12
  CHAR *v4; // ecx@13
  CHAR v5; // al@14
  char *v6; // eax@20
  const char *v7; // eax@21
  const char *v8; // ecx@21
  CHAR Str2; // [sp+4h] [bp-122Ch]@5
  CHAR SubStr; // [sp+1094h] [bp-19Ch]@13
  struct _OSVERSIONINFOA VersionInformation; // [sp+1198h] [bp-98h]@1
  unsigned __int8 v12; // [sp+122Ch] [bp-4h]@29

  VersionInformation.dwOSVersionInfoSize = 148;
  if ( GetVersionExA(&VersionInformation)
    && VersionInformation.dwPlatformId == 2
    && VersionInformation.dwMajorVersion >= 5 )
  {
    result = 1;
  }
  else
  {
    if ( !GetEnvironmentVariableA(&byte_4D8410[12012], &Str2, 0x1090u) )
      goto LABEL_32;
    v1 = &Str2;
    if ( Str2 )
    {
      do
      {
        v2 = *v1;
        if ( *v1 >= 97 )
        {
          if ( v2 <= 122 )
            *v1 = v2 - 32;
        }
        ++v1;
      }
      while ( *v1 );
    }
    if ( strncmp(&byte_4D8410[11988], &Str2, 0x16u) )
    {
      GetModuleFileNameA(0, &SubStr, 0x104u);
      v4 = &SubStr;
      if ( SubStr )
      {
        do
        {
          v5 = *v4;
          if ( *v4 >= 97 )
          {
            if ( v5 <= 122 )
              *v4 = v5 - 32;
          }
          ++v4;
        }
        while ( *v4 );
      }
      v3 = strstr(&Str2, &SubStr);
    }
    else
    {
      v3 = &Str2;
    }
    if ( !v3 )
      goto LABEL_32;
    v6 = strchr(v3, 44);
    if ( !v6 )
      goto LABEL_32;
    v7 = v6 + 1;
    v8 = v7;
    while ( *v8 )
    {
      if ( *v8 == 59 )
        compile_error;//*v8 = 0;
      else
        ++v8;
    }
    result = strtol(v7, 0, 10);
    if ( result != 2 )
    {
      if ( result != 3 && result != 1 )
      {
LABEL_32:
        sub_4CFBA2((int)&v12);
        result = 3 - (v12 < 6u);
      }
    }
  }
  return result;
}

//----- (004CFDE7) --------------------------------------------------------
unsigned int __cdecl sub_4CFDE7(unsigned int a1, int a2)
{
  unsigned int result; // eax@1
  signed int v3; // ecx@1
  unsigned int v4; // edi@1
  int v5; // esi@1
  int v6; // ebx@2
  int v7; // edx@3
  unsigned int v8; // ebx@7
  int v9; // ecx@7
  char v10; // zf@7
  unsigned int v11; // ebx@9
  int v12; // ecx@9
  char v13; // zf@9
  int v14; // ecx@11
  int v15; // edx@14
  int v16; // ebx@17
  unsigned int v17; // esi@24
  char v18; // zf@24
  unsigned int v19; // esi@26
  char v20; // zf@26
  int v21; // ecx@33
  char v22; // zf@41
  void *v23; // eax@43
  int v24; // [sp+Ch] [bp-10h]@1
  signed int v25; // [sp+10h] [bp-Ch]@2
  signed int v26; // [sp+14h] [bp-8h]@2
  int v27; // [sp+18h] [bp-4h]@1
  int v28; // [sp+28h] [bp+Ch]@2
  int v29; // [sp+28h] [bp+Ch]@17
  char v30; // [sp+2Bh] [bp+Fh]@34

  result = *(_DWORD *)(a1 + 16);
  v5 = a2 - 4;
  v4 = (unsigned int)(a2 - *(_DWORD *)(a1 + 12)) >> 15;
  v24 = 516 * v4 + result + 324;
  v3 = *(_DWORD *)(a2 - 4) - 1;
  v27 = *(_DWORD *)(a2 - 4) - 1;
  if ( !(v3 & 1) )
  {
    v6 = v3 + v5;
    v25 = *(_DWORD *)(v3 + v5);
    v26 = *(_DWORD *)(a2 - 8);
    v28 = v3 + v5;
    if ( !(v25 & 1) )
    {
      v7 = (v25 >> 4) - 1;
      if ( (unsigned int)v7 > 0x3F )
        v7 = 63;
      if ( *(_DWORD *)(v6 + 4) == *(_DWORD *)(v6 + 8) )
      {
        if ( (unsigned int)v7 >= 0x20 )
        {
          v12 = v7 + result + 4;
          v11 = ~(0x80000000u >> (v7 - 32));
          *(_DWORD *)(result + 4 * v4 + 196) &= v11;
          v13 = *(_BYTE *)v12-- == 1;
          if ( v13 )
            *(_DWORD *)(a1 + 4) &= v11;
        }
        else
        {
          v9 = v7 + result + 4;
          v8 = ~(0x80000000u >> v7);
          *(_DWORD *)(result + 4 * v4 + 68) &= v8;
          v10 = *(_BYTE *)v9-- == 1;
          if ( v10 )
            *(_DWORD *)a1 &= v8;
        }
        v14 = v27;
        v6 = v28;
      }
      else
      {
        v14 = v27;
      }
      v3 = v25 + v14;
      *(_DWORD *)(*(_DWORD *)(v6 + 8) + 4) = *(_DWORD *)(v6 + 4);
      v27 = v3;
      *(_DWORD *)(*(_DWORD *)(v28 + 4) + 8) = *(_DWORD *)(v28 + 8);
    }
    v15 = (v3 >> 4) - 1;
    if ( (unsigned int)v15 > 0x3F )
      v15 = 63;
    if ( v26 & 1 )
    {
      v16 = a1;
    }
    else
    {
      v29 = v5 - v26;
      v16 = (v26 >> 4) - 1;
      if ( (unsigned int)v16 > 0x3F )
        v16 = 63;
      v27 = v26 + v3;
      v15 = ((v26 + v3) >> 4) - 1;
      if ( (unsigned int)v15 > 0x3F )
        v15 = 63;
      if ( v16 != v15 )
      {
        if ( *(_DWORD *)(v29 + 4) == *(_DWORD *)(v29 + 8) )
        {
          if ( (unsigned int)v16 >= 0x20 )
          {
            v19 = ~(0x80000000u >> (v16 - 32));
            *(_DWORD *)(result + 4 * v4 + 196) &= v19;
            compile_error;//v20 = *(_BYTE *)(v16 + result + 4)-- == 1;
            if ( v20 )
              *(_DWORD *)(a1 + 4) &= v19;
          }
          else
          {
            v17 = ~(0x80000000u >> v16);
            *(_DWORD *)(result + 4 * v4 + 68) &= v17;
            compile_error;//v18 = *(_BYTE *)(v16 + result + 4)-- == 1;
            if ( v18 )
              *(_DWORD *)a1 &= v17;
          }
        }
        *(_DWORD *)(*(_DWORD *)(v29 + 8) + 4) = *(_DWORD *)(v29 + 4);
        *(_DWORD *)(*(_DWORD *)(v29 + 4) + 8) = *(_DWORD *)(v29 + 8);
      }
      v5 = v29;
    }
    if ( v26 & 1 || v16 != v15 )
    {
      v21 = v24 + 8 * v15;
      *(_DWORD *)(v5 + 4) = *(_DWORD *)(v24 + 8 * v15 + 4);
      *(_DWORD *)(v5 + 8) = v21;
      *(_DWORD *)(v21 + 4) = v5;
      *(_DWORD *)(*(_DWORD *)(v5 + 4) + 8) = v5;
      if ( *(_DWORD *)(v5 + 4) == *(_DWORD *)(v5 + 8) )
      {
        v30 = *(_BYTE *)(v15 + result + 4);
        *(_BYTE *)(v15 + result + 4) = v30 + 1;
        if ( (unsigned int)v15 >= 0x20 )
        {
          if ( !v30 )
            *(_DWORD *)(a1 + 4) |= 0x80000000u >> (v15 - 32);
          *(_DWORD *)(result + 4 * v4 + 196) |= 0x80000000u >> (v15 - 32);
        }
        else
        {
          if ( !v30 )
            *(_DWORD *)a1 |= 0x80000000u >> v15;
          *(_DWORD *)(result + 4 * v4 + 68) |= 0x80000000u >> v15;
        }
      }
    }
    *(_DWORD *)v5 = v27;
    *(_DWORD *)(v27 + v5 - 4) = v27;
    result += 516 * v4 + 324;
    v22 = *(_DWORD *)v24 == 1;
    --*(_DWORD *)result;
    if ( v22 )
    {
      if ( dword_F944F4 )
      {
        VirtualFree((LPVOID)(*((_DWORD *)dword_F944F4 + 3) + (dword_F944EC << 15)), 32768u, 16384u);
        *((_DWORD *)dword_F944F4 + 2) |= 0x80000000u >> dword_F944EC;
        *(_DWORD *)(*((_DWORD *)dword_F944F4 + 4) + 4 * dword_F944EC + 196) = 0;
        --*(_BYTE *)(*((_DWORD *)dword_F944F4 + 4) + 67);
        v23 = dword_F944F4;
        if ( !*(_BYTE *)(*((_DWORD *)dword_F944F4 + 4) + 67) )
        {
          *((_DWORD *)dword_F944F4 + 1) &= 0xFFFFFFFEu;
          v23 = dword_F944F4;
        }
        if ( *((_DWORD *)v23 + 2) == -1 )
        {
          VirtualFree(*((LPVOID *)v23 + 3), 0, 0x8000u);
          HeapFree(hHeap, 0, *((LPVOID *)dword_F944F4 + 4));
          compile_error;
          /*memcpy_0(
            dword_F944F4,
            (char *)dword_F944F4 + 20,
            (size_t)(lpMem + 20 * dword_F944F8-- - (_DWORD)dword_F944F4 - 20));*/
          if ( a1 > (unsigned int)dword_F944F4 )
            a1 -= 20;
          dword_F944F0 = (int)lpMem;
        }
      }
      result = a1;
      dword_F944EC = v4;
      dword_F944F4 = (void *)a1;
    }
  }
  return result;
}

//----- (004D08BB) --------------------------------------------------------
LPVOID __cdecl sub_4D08BB()
{
  LPVOID v0; // esi@2
  void *v1; // eax@4
  unsigned int v2; // edi@4
  int v3; // eax@12
  signed int v4; // ebp@12
  bool v5; // edx@13

  if ( dword_4F2D78 == -1 )
  {
    v0 = &off_4F2D68;
  }
  else
  {
    v0 = HeapAlloc(hHeap, 0, 0x2020u);
    if ( !v0 )
      return 0;
  }
  v1 = VirtualAlloc(0, 4194304u, 8192u, 4u);
  v2 = (unsigned int)v1;
  if ( !v1 )
  {
LABEL_19:
    if ( v0 != &off_4F2D68 )
      HeapFree(hHeap, 0, v0);
    return 0;
  }
  if ( !VirtualAlloc(v1, 0x10000u, 0x1000u, 4u) )
  {
    VirtualFree((LPVOID)v2, 0, 0x8000u);
    goto LABEL_19;
  }
  if ( v0 == &off_4F2D68 )
  {
    if ( !off_4F2D68 )
      off_4F2D68 = &off_4F2D68;
    if ( !off_4F2D6C )
      off_4F2D6C = &off_4F2D68;
  }
  else
  {
    *(_DWORD *)v0 = &off_4F2D68;
    *((_DWORD *)v0 + 1) = off_4F2D6C;
    off_4F2D6C = v0;
    **((_DWORD **)v0 + 1) = v0;
  }
  *((_DWORD *)v0 + 5) = v2 + 4194304;
  v3 = (int)((char *)v0 + 24);
  *((_DWORD *)v0 + 3) = (char *)v0 + 152;
  *((_DWORD *)v0 + 4) = v2;
  *((_DWORD *)v0 + 2) = (char *)v0 + 24;
  v4 = 0;
  do
  {
    v5 = v4++ >= 16;
    *(_DWORD *)v3 = ((v5 - 1) & 0xF1) - 1;
    *(_DWORD *)(v3 + 4) = 241;
    v3 += 8;
  }
  while ( v4 < 1024 );
  memset((void *)v2, 0, 0x10000u);
  while ( v2 < *((_DWORD *)v0 + 4) + 65536 )
  {
    *(_BYTE *)(v2 + 248) = -1;
    *(_DWORD *)v2 = v2 + 8;
    *(_DWORD *)(v2 + 4) = 240;
    v2 += 4096;
  }
  return v0;
}

//----- (004D09FF) --------------------------------------------------------
BOOL __cdecl sub_4D09FF(void **lpMem)
{
  BOOL result; // eax@1

  result = VirtualFree(lpMem[4], 0, 0x8000u);
  if ( off_4F4D88 == lpMem )
  {
    result = (BOOL)lpMem[1];
    off_4F4D88 = (void **)lpMem[1];
  }
  if ( lpMem == &off_4F2D68 )
  {
    dword_4F2D78 = -1;
  }
  else
  {
    *(_DWORD *)lpMem[1] = *lpMem;
    *((_DWORD *)*lpMem + 1) = lpMem[1];
    result = HeapFree(hHeap, 0, lpMem);
  }
  return result;
}

//----- (004D0A55) --------------------------------------------------------
void __cdecl sub_4D0A55(int a1)
{
  LPVOID v1; // esi@1
  signed int v2; // ebx@3
  int v3; // edi@3
  unsigned int v4; // eax@6
  char v5; // zf@9
  LPVOID v6; // ecx@11
  int v7; // eax@13
  signed int v8; // edx@13
  int v9; // [sp+Ch] [bp-4h]@3

  v1 = off_4F2D6C;
  do
  {
    if ( *((_DWORD *)v1 + 4) != -1 )
    {
      v9 = 0;
      v3 = (int)((char *)v1 + 8208);
      v2 = 4190208;
      do
      {
        if ( *(_DWORD *)v3 == 240 )
        {
          if ( VirtualFree((LPVOID)(*((_DWORD *)v1 + 4) + v2), 0x1000u, 0x4000u) )
          {
            *(_DWORD *)v3 = -1;
            --dword_F9400C;
            v4 = *((_DWORD *)v1 + 3);
            if ( !v4 || v4 > v3 )
              *((_DWORD *)v1 + 3) = v3;
            ++v9;
            v5 = a1-- == 1;
            if ( v5 )
              break;
          }
        }
        v2 -= 4096;
        v3 -= 8;
      }
      while ( v2 >= 0 );
      v6 = v1;
      v1 = (LPVOID)*((_DWORD *)v1 + 1);
      if ( v9 )
      {
        if ( *((_DWORD *)v6 + 6) == -1 )
        {
          v7 = (int)((char *)v6 + 32);
          v8 = 1;
          do
          {
            if ( *(_DWORD *)v7 != -1 )
              break;
            ++v8;
            v7 += 8;
          }
          while ( v8 < 1024 );
          if ( v8 == 1024 )
            sub_4D09FF((void **)v6);
        }
      }
    }
  }
  while ( v1 != off_4F2D6C && a1 > 0 );
}

//----- (004D0B17) --------------------------------------------------------
int __cdecl sub_4D0B17(unsigned int a1, int a2, int a3)
{
  void **v3; // ecx@1

  v3 = &off_4F2D68;
  while ( a1 <= (unsigned int)v3[4] || a1 >= (unsigned int)v3[5] )
  {
    v3 = (void **)*v3;
    if ( v3 == &off_4F2D68 )
      return 0;
  }
  if ( !(a1 & 0xF) && (a1 & 0xFFF) >= 0x100 )
  {
    *(_DWORD *)a2 = v3;
    *(_DWORD *)a3 = a1 & 0xF000;
    return ((signed int)(a1 - (unsigned __int16)(a1 & 0xF000) - 256) >> 4) + (unsigned __int16)(a1 & 0xF000) + 8;
  }
  return 0;
}

//----- (004D0B6E) --------------------------------------------------------
void __cdecl sub_4D0B6E(int a1, int a2, int a3)
{
  int v3; // eax@1
  char v4; // zf@1

  v3 = a1 + 8 * ((a2 - *(_DWORD *)(a1 + 16)) >> 12) + 24;
  *(_DWORD *)v3 += *(_BYTE *)a3;
  *(_BYTE *)a3 = 0;
  v4 = *(_DWORD *)v3 == 240;
  *(_DWORD *)(v3 + 4) = 241;
  if ( v4 )
  {
    ++dword_F9400C;
    if ( dword_F9400C == 32 )
      sub_4D0A55(16);
  }
}

//----- (004D0BB3) --------------------------------------------------------
int __cdecl sub_4D0BB3(unsigned int a1)
{
  void **v1; // esi@1
  void *v2; // edx@2
  int v3; // eax@3
  int v4; // edi@3
  unsigned int v5; // ebx@4
  int result; // eax@6
  void **v7; // edi@22
  void *v8; // eax@27
  void *v9; // ebx@27
  int i; // esi@27
  unsigned int v11; // ecx@31
  int v12; // eax@32
  int v14; // eax@34
  unsigned __int8 v15; // cf@35
  LPVOID v16; // eax@40
  int v17; // ecx@41
  unsigned int v18; // [sp+Ch] [bp-8h]@11
  int v19; // [sp+10h] [bp-4h]@3
  int v20; // [sp+10h] [bp-4h]@11
  signed int v21; // [sp+10h] [bp-4h]@27

  v1 = off_4F4D88;
  do
  {
    v2 = v1[4];
    if ( v2 == (void *)-1 )
    {
      v5 = a1;
    }
    else
    {
      v4 = (int)v1[2];
      compile_error;//v3 = (int)((char *)v2 + 4096 * ((signed int)(v1[2] - v1 - 24) >> 3));
      compile_error;//v19 = (int)((char *)v2 + 4096 * ((signed int)(v1[2] - v1 - 24) >> 3));
      if ( v4 < (unsigned int)(v1 + 2054) )
      {
        while ( 1 )
        {
          v5 = a1;
          if ( *(_DWORD *)v4 >= (signed int)a1 && *(_DWORD *)(v4 + 4) > a1 )
          {
            result = sub_4D0DBB(v3, *(_DWORD *)v4, a1);
            if ( result )
            {
LABEL_21:
              off_4F4D88 = v1;
              *(_DWORD *)v4 -= v5;
              v1[2] = (void *)v4;
              return result;
            }
            v3 = v19;
            *(_DWORD *)(v4 + 4) = a1;
          }
          v4 += 8;
          v3 += 4096;
          v19 = v3;
          if ( v4 >= (unsigned int)(v1 + 2054) )
            goto LABEL_11;
        }
      }
      v5 = a1;
LABEL_11:
      v4 = (int)(v1 + 6);
      v18 = (unsigned int)v1[2];
      v20 = (int)v1[4];
      if ( (unsigned int)(v1 + 6) < v18 )
      {
        do
        {
          if ( *(_DWORD *)v4 >= (signed int)v5 && *(_DWORD *)(v4 + 4) > v5 )
          {
            result = sub_4D0DBB(v20, *(_DWORD *)v4, v5);
            if ( result )
              goto LABEL_21;
            *(_DWORD *)(v4 + 4) = v5;
          }
          v20 += 4096;
          v4 += 8;
        }
        while ( v4 < v18 );
      }
    }
    v1 = (void **)*v1;
  }
  while ( v1 != off_4F4D88 );
  v7 = &off_4F2D68;
  while ( v7[4] == (void *)-1 || !v7[3] )
  {
    v7 = (void **)*v7;
    if ( v7 == &off_4F2D68 )
    {
      v16 = sub_4D08BB();
      if ( v16 )
      {
        v17 = *((_DWORD *)v16 + 4);
        *(_BYTE *)(v17 + 8) = v5;
        off_4F4D88 = (void **)v16;
        *(_DWORD *)v17 = v17 + v5 + 8;
        *(_DWORD *)(v17 + 4) = 240 - v5;
        *((_DWORD *)v16 + 6) -= (unsigned __int8)v5;
        return v17 + 256;
      }
      return 0;
    }
  }
  v9 = v7[3];
  v21 = 0;
  v8 = v9;
  compile_error;
  /*for ( i = (int)((char *)v7[4] + 4096 * ((signed int)(v9 - v7 - 24) >> 3)); *(_DWORD *)v8 == -1; ++v21 )
  {
    if ( v21 >= 16 )
      break;
    v8 = (char *)v8 + 8;
  }*/
  if ( VirtualAlloc((LPVOID)i, v21 << 12, 0x1000u, 4u) != (LPVOID)i )
    return 0;
  memset((void *)i, v21 << 12, 0);
  v11 = (unsigned int)v9;
  if ( v21 > 0 )
  {
    v12 = i + 4;
    do
    {
      *(_BYTE *)(v12 + 244) = -1;
      *(_DWORD *)(v12 - 4) = v12 + 4;
      *(_DWORD *)v12 = 240;
      *(_DWORD *)v11 = 240;
      *(_DWORD *)(v11 + 4) = 241;
      v12 += 4096;
      v11 += 8;
    }
    while ( v21-- != 1 );
  }
  off_4F4D88 = v7;
  v14 = (int)(v7 + 2054);
  while ( 1 )
  {
    v15 = v11 < v14;
    if ( v11 >= v14 )
      break;
    if ( *(_DWORD *)v11 == -1 )
    {
      v15 = v11 < v14;
      break;
    }
    v11 += 8;
  }
  v7[3] = (void *)(v11 & -v15);
  *(_BYTE *)(i + 8) = a1;
  v7[2] = v9;
  *(_DWORD *)v9 -= a1;
  *(_DWORD *)(i + 4) -= a1;
  result = i + 256;
  *(_DWORD *)i = i + a1 + 8;
  return result;
}

//----- (004D0DBB) --------------------------------------------------------
int __cdecl sub_4D0DBB(int a1, unsigned int a2, unsigned int a3)
{
  int v3; // eax@1
  int v4; // ecx@1
  int v5; // ebx@1
  unsigned int v6; // edi@1
  unsigned int v7; // esi@1
  int v8; // eax@5
  int v9; // esi@6
  int v10; // ebx@10
  signed int v11; // esi@10
  int v12; // esi@20
  signed int v13; // eax@24
  int v14; // ebx@24
  unsigned int v16; // [sp+Ch] [bp-4h]@1
  int v17; // [sp+18h] [bp+8h]@1

  v4 = a1;
  v7 = *(_DWORD *)(a1 + 4);
  v6 = *(_DWORD *)a1;
  v5 = a1 + 248;
  v16 = *(_DWORD *)a1;
  v3 = *(_DWORD *)a1;
  v17 = a1 + 248;
  if ( v7 >= a3 )
  {
    *(_BYTE *)v6 = a3;
    if ( v6 + a3 >= v5 )
    {
      *(_DWORD *)(v4 + 4) = 0;
      *(_DWORD *)v4 = v4 + 8;
    }
    else
    {
      *(_DWORD *)v4 += a3;
      *(_DWORD *)(v4 + 4) -= a3;
    }
    v8 = v6 + 8;
    return 16 * v8 - 15 * v4;
  }
  v9 = v6 + v7;
  if ( *(_BYTE *)v9 )
    v3 = v9;
  if ( v3 + a3 >= v5 )
  {
LABEL_20:
    v12 = v4 + 8;
    while ( v12 < v6 && v12 + a3 < v17 )
    {
      if ( *(_BYTE *)v12 )
      {
        v12 += *(_BYTE *)v12;
      }
      else
      {
        v14 = v12 + 1;
        v13 = 1;
        while ( !*(_BYTE *)v14 )
        {
          ++v14;
          ++v13;
        }
        if ( v13 >= a3 )
        {
          if ( v12 + a3 >= v17 )
          {
            *(_DWORD *)(v4 + 4) = 0;
            *(_DWORD *)v4 = v4 + 8;
          }
          else
          {
            *(_DWORD *)v4 = v12 + a3;
            *(_DWORD *)(v4 + 4) = v13 - a3;
          }
          *(_BYTE *)v12 = a3;
          v8 = v12 + 8;
          return 16 * v8 - 15 * v4;
        }
        a2 -= v13;
        if ( a2 < a3 )
          return 0;
        v12 = v14;
      }
    }
    return 0;
  }
  while ( *(_BYTE *)v3 )
  {
    v3 += *(_BYTE *)v3;
LABEL_19:
    if ( v3 + a3 >= v17 )
      goto LABEL_20;
  }
  v10 = v3 + 1;
  v11 = 1;
  while ( !*(_BYTE *)v10 )
  {
    ++v10;
    ++v11;
  }
  if ( v11 < a3 )
  {
    if ( v3 == v16 )
    {
      *(_DWORD *)(v4 + 4) = v11;
    }
    else
    {
      a2 -= v11;
      if ( a2 < a3 )
        return 0;
    }
    v6 = v16;
    v3 = v10;
    goto LABEL_19;
  }
  if ( v3 + a3 >= v17 )
  {
    *(_DWORD *)(v4 + 4) = 0;
    *(_DWORD *)v4 = v4 + 8;
  }
  else
  {
    *(_DWORD *)v4 = v3 + a3;
    *(_DWORD *)(v4 + 4) = v11 - a3;
  }
  *(_BYTE *)v3 = a3;
  v8 = v3 + 8;
  return 16 * v8 - 15 * v4;
}

//----- (004D0EDF) --------------------------------------------------------
signed int __cdecl sub_4D0EDF(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // ecx@1
  int v5; // edi@1
  int v6; // esi@4
  int i; // eax@5
  char v8; // zf@6
  int v9; // eax@14
  int v11; // [sp+Ch] [bp-4h]@1

  v4 = *(_BYTE *)a3;
  v11 = 0;
  v5 = a1 + 8 * ((a2 - *(_DWORD *)(a1 + 16)) >> 12) + 24;
  if ( v4 > a4 )
  {
    *(_BYTE *)a3 = a4;
    *(_DWORD *)v5 += v4 - a4;
    *(_DWORD *)(v5 + 4) = 241;
    return 1;
  }
  if ( v4 < a4 )
  {
    v6 = a3 + a4;
    if ( a2 + 248 >= a3 + a4 )
    {
      for ( i = v4 + a3; ; ++i )
      {
        v8 = i == v6;
        if ( i >= (unsigned int)v6 )
          break;
        if ( *(_BYTE *)i )
        {
          v8 = i == v6;
          break;
        }
      }
      if ( v8 )
      {
        *(_BYTE *)a3 = a4;
        if ( a3 <= *(_DWORD *)a2 )
        {
          if ( (unsigned int)v6 > *(_DWORD *)a2 )
          {
            if ( v6 >= (unsigned int)(a2 + 248) )
            {
              *(_DWORD *)(a2 + 4) = 0;
              *(_DWORD *)a2 = a2 + 8;
            }
            else
            {
              v9 = 0;
              *(_DWORD *)a2 = v6;
              if ( !*(_BYTE *)v6 )
              {
                do
                  ++v9;
                while ( !*(_BYTE *)(v6 + v9) );
              }
              *(_DWORD *)(a2 + 4) = v9;
            }
          }
        }
        *(_DWORD *)v5 += v4 - a4;
        return 1;
      }
    }
  }
  return v11;
}

//----- (004D191D) --------------------------------------------------------
functon_error;//void __usercall sub_4D191D(int a1<eax>, int a2<ecx>, int a3<ebx>, int a4<edi>, int a5<esi>)
void sub_4D191D(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // [sp-Ch] [bp-24h]@1
  int v6; // [sp-8h] [bp-20h]@1
  int v7; // [sp-4h] [bp-1Ch]@1
  int *v8; // [sp+0h] [bp-18h]@1
  int v9; // [sp+4h] [bp-14h]@1
  int v10; // [sp+8h] [bp-10h]@1
  int (__cdecl *v11)(int, int, int); // [sp+Ch] [bp-Ch]@1
  signed int v12; // [sp+10h] [bp-8h]@1
  int v13; // [sp+14h] [bp-4h]@1

  v12 = 5092216;
  compile_error;//v11 = unknown_libname_59;
  v10 = a1;
  v9 = a2;
  v7 = a3;
  v6 = a5;
  v5 = a4;
  v8 = &v5;
  v13 = 0;
  if ( off_4F4DA0 )
  {
    off_4F4DA0(v5, v6, v7, v8, v9, v10, v11, v12, 1);
    compile_error;//JUMPOUT(*(int *)unk_4D1958);
  }
  v13 = -1;
  terminate();
}

//----- (004D31E1) --------------------------------------------------------
function_error;//double __usercall sub_4D31E1<st0>(double result<st0>)
double sub_4D31E1(double result)
{
  double v3; // st6@2

  compile_error;//_ST6 = result;
  __asm { frndint }

  compile_error;//if ( _ST6 == result )
  if (0)
  {
    v3 = result * dbl_4F5372;
    compile_error;//_ST5 = result * dbl_4F5372;
    __asm { frndint }
    compile_error;//_ST5 == v3;
  }
  return result;
}

//----- (004D44AB) --------------------------------------------------------
int __cdecl sub_4D44AB(int a1, int a2)
{
  return _ld12cvt(a1, a2, &unk_4F54B8);
}

//----- (004D44C1) --------------------------------------------------------
int __cdecl sub_4D44C1(int a1, int a2)
{
  return _ld12cvt(a1, a2, &unk_4F54D0);
}

//----- (004D44D7) --------------------------------------------------------
int __cdecl sub_4D44D7(int a1, int a2)
{
  char v3; // [sp+0h] [bp-Ch]@1

  __strgtold12(&v3, &a2, a2, 0, 0, 0, 0);
  return sub_4D44AB((int)&v3, a1);
}

//----- (004D4504) --------------------------------------------------------
int __cdecl sub_4D4504(int a1, int a2)
{
  char v3; // [sp+0h] [bp-Ch]@1

  __strgtold12(&v3, &a2, a2, 0, 0, 0, 0);
  return sub_4D44C1((int)&v3, a1);
}

//----- (004D5554) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5554()
{
 compile_error;
 return 0;
}

//----- (004D555F) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D555F()
{
 compile_error;
 return 0;
}

//----- (004D556A) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D556A()
{
 compile_error;
 return 0;
}

//----- (004D5570) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5570()
{
 compile_error;
 return 0;
}

//----- (004D5576) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5576()
{
 compile_error;
 return 0;
}

//----- (004D557C) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D557C()
{
 compile_error;
 return 0;
}

//----- (004D5582) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5582()
{
 compile_error;
 return 0;
}

//----- (004D55A3) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D55A3()
{
 compile_error;
 return 0;
}

//----- (004D55BE) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D55BE()
{
 compile_error;
 return 0;
}

//----- (004D55DA) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D55DA()
{
 compile_error;
 return 0;
}

//----- (004D55EA) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D55EA()
{
 compile_error;
 return 0;
}

//----- (004D55FE) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D55FE()
{
 compile_error;
 return 0;
}

//----- (004D560E) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D560E()
{
 compile_error;
 return 0;
}

//----- (004D5633) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5633()
{
 compile_error;
 return 0;
}

//----- (004D5652) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5652()
{
 compile_error;
 return 0;
}

//----- (004D5672) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5672()
{
 compile_error;
 return 0;
}

//----- (004D5686) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5686()
{
 compile_error;
 return 0;
}

//----- (004D569E) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D569E()
{
 compile_error;
 return 0;
}

//----- (004D56B2) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D56B2()
{
 compile_error;
 return 0;
}

//----- (004D56D7) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D56D7()
{
 compile_error;
 return 0;
}

//----- (004D56F6) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D56F6()
{
 compile_error;
 return 0;
}

//----- (004D5716) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5716()
{
 compile_error;
 return 0;
}

//----- (004D572A) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D572A()
{
 compile_error;
 return 0;
}

//----- (004D5742) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5742()
{
 compile_error;
 return 0;
}

//----- (004D5756) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5756()
{
 compile_error;
 return 0;
}

//----- (004D577B) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D577B()
{
 compile_error;
 return 0;
}

//----- (004D579A) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D579A()
{
 compile_error;
 return 0;
}

//----- (004D57BA) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D57BA()
{
 compile_error;
 return 0;
}

//----- (004D57CE) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D57CE()
{
 compile_error;
 return 0;
}

//----- (004D57E6) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D57E6()
{
 compile_error;
 return 0;
}

//----- (004D57FA) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D57FA()
{
 compile_error;
 return 0;
}

//----- (004D581F) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D581F()
{
 compile_error;
 return 0;
}

//----- (004D583E) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D583E()
{
 compile_error;
 return 0;
}

//----- (004D585E) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D585E()
{
 compile_error;
 return 0;
}

//----- (004D5872) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5872()
{
 compile_error;
 return 0;
}

//----- (004D588A) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D588A()
{
 compile_error;
 return 0;
}

//----- (004D589E) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D589E()
{
 compile_error;
 return 0;
}

//----- (004D58C3) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D58C3()
{
 compile_error;
 return 0;
}

//----- (004D58E2) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D58E2()
{
 compile_error;
 return 0;
}

//----- (004D5902) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5902()
{
 compile_error;
 return 0;
}

//----- (004D5916) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5916()
{
 compile_error;
 return 0;
}

//----- (004D592E) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D592E()
{
 compile_error;
 return 0;
}

//----- (004D5942) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5942()
{
 compile_error;
 return 0;
}

//----- (004D5967) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5967()
{
 compile_error;
 return 0;
}

//----- (004D5986) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D5986()
{
 compile_error;
 return 0;
}

//----- (004D59A6) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D59A6()
{
 compile_error;
 return 0;
}

//----- (004D59BA) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D59BA()
{
 compile_error;
 return 0;
}

//----- (004D59D2) --------------------------------------------------------
function_error;//#error "FFFFFFFF: positive sp value has been found (funcsize=0)"
int sub_4D59D2()
{
 compile_error;
 return 0;
}

//----- (004D6FB0) --------------------------------------------------------
function_error;//int __usercall sub_4D6FB0<eax>(int a1<ebp>)
int sub_4D6FB0(int a1)
{
  int result; // eax@1
  int v2; // ebp@1
  unsigned int v3; // edi@1
  unsigned int v4; // esi@1
  int v5; // edx@2
  int v6; // ebx@2
  int v7; // ebx@3
  __int16 v8; // cx@3
  int v9; // edx@4
  __int16 v10; // cx@4
  unsigned __int8 v11; // sf@5
  unsigned __int8 v12; // of@5

  v2 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(v2 + 48);
  v3 = *(_DWORD *)(v2 + 44);
  result = *(_DWORD *)(v2 + 64);
  if ( !(*(_DWORD *)(v2 + 40) & 1) )
    goto LABEL_5;
  --*(_DWORD *)(v2 + 40);
  result -= 2;
  v6 = *(_DWORD *)(v2 + 60);
  v5 = *(_DWORD *)(v2 + 36);
  *(_DWORD *)(v2 + 60) += 4;
  while ( 1 )
  {
    *(_DWORD *)v6 = v5;
    v9 = *(_DWORD *)(v2 + 12) & (v4 >> 16);
    result += 4;
    v4 += *(_DWORD *)(v2 + 4);
    v10 = *(_WORD *)(*(_DWORD *)(v2 + 52)
                   + 2 * *(_BYTE *)(*(_DWORD *)(v2 + 56) + v9 + ((*(_DWORD *)(v2 + 8) & v3) >> *(_BYTE *)(v2 + 16))));
    v3 += *(_DWORD *)v2;
    *(_WORD *)(result - 2) = v10;
LABEL_5:
    compile_error;//v12 = __SETO__(*(_DWORD *)(v2 + 40), 2);
    v11 = *(_DWORD *)(v2 + 40) - 2 < 0;
    *(_DWORD *)(v2 + 40) -= 2;
    if ( v11 ^ v12 )
      break;
    v7 = *(_BYTE *)(*(_DWORD *)(v2 + 56)
                  + (*(_DWORD *)(v2 + 12) & (v4 >> 16))
                  + ((*(_DWORD *)(v2 + 8) & v3) >> *(_BYTE *)(v2 + 16)));
    v4 += *(_DWORD *)(v2 + 4);
    v8 = *(_WORD *)(*(_DWORD *)(v2 + 52) + 2 * v7);
    v3 += *(_DWORD *)v2;
    v6 = *(_DWORD *)(v2 + 60);
    v5 = *(_DWORD *)(v2 + 36);
    *(_WORD *)result = v8;
    *(_DWORD *)(v2 + 60) += 8;
    *(_DWORD *)(v6 + 4) = v5;
  }
  *(_DWORD *)(v2 + 64) = result;
  *(_DWORD *)(v2 + 48) = v4;
  *(_DWORD *)(v2 + 44) = v3;
  return result;
}

//----- (004D705A) --------------------------------------------------------
function_error;//int __usercall sub_4D705A<eax>(int a1<ebp>)
int sub_4D705A(int a1)
{
  int result; // eax@1
  int v2; // ebp@1
  unsigned int v3; // edi@1
  unsigned int v4; // esi@1
  int v5; // edx@2
  int v6; // ebx@2
  unsigned int v7; // edx@3
  unsigned int v8; // ebx@3
  __int16 v9; // cx@11
  unsigned int v10; // edx@12
  unsigned int v11; // ebx@12
  unsigned __int8 v12; // sf@21
  unsigned __int8 v13; // of@21

  v2 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(v2 + 48);
  v3 = *(_DWORD *)(v2 + 44);
  result = *(_DWORD *)(v2 + 64);
  if ( !(*(_DWORD *)(v2 + 40) & 1) )
    goto LABEL_21;
  --*(_DWORD *)(v2 + 40);
  result -= 2;
  v6 = *(_DWORD *)(v2 + 60);
  v5 = *(_DWORD *)(v2 + 36);
  *(_DWORD *)(v2 + 60) += 4;
  while ( 1 )
  {
    *(_DWORD *)v6 = v5;
    v11 = v3;
    v10 = v4;
    if ( (signed int)v4 < *(_DWORD *)(v2 + 20) )
      v10 = *(_DWORD *)(v2 + 20);
    if ( (signed int)v3 < *(_DWORD *)(v2 + 28) )
      v11 = *(_DWORD *)(v2 + 28);
    if ( (signed int)v10 > *(_DWORD *)(v2 + 24) )
      v10 = *(_DWORD *)(v2 + 24);
    if ( (signed int)v11 > *(_DWORD *)(v2 + 32) )
      v11 = *(_DWORD *)(v2 + 32);
    result += 4;
    v4 += *(_DWORD *)(v2 + 4);
    v3 += *(_DWORD *)v2;
    *(_WORD *)(result - 2) = *(_WORD *)(*(_DWORD *)(v2 + 52)
                                      + 2
                                      * *(_BYTE *)(*(_DWORD *)(v2 + 56)
                                                 + (*(_DWORD *)(v2 + 12) & (v10 >> 16))
                                                 + ((*(_DWORD *)(v2 + 8) & v11) >> *(_BYTE *)(v2 + 16))));
LABEL_21:
    compile_error;//v13 = __SETO__(*(_DWORD *)(v2 + 40), 2);
    v12 = *(_DWORD *)(v2 + 40) - 2 < 0;
    *(_DWORD *)(v2 + 40) -= 2;
    if ( v12 ^ v13 )
      break;
    v8 = v3;
    v7 = v4;
    if ( (signed int)v4 < *(_DWORD *)(v2 + 20) )
      v7 = *(_DWORD *)(v2 + 20);
    if ( (signed int)v3 < *(_DWORD *)(v2 + 28) )
      v8 = *(_DWORD *)(v2 + 28);
    if ( (signed int)v7 > *(_DWORD *)(v2 + 24) )
      v7 = *(_DWORD *)(v2 + 24);
    if ( (signed int)v8 > *(_DWORD *)(v2 + 32) )
      v8 = *(_DWORD *)(v2 + 32);
    v4 += *(_DWORD *)(v2 + 4);
    v9 = *(_WORD *)(*(_DWORD *)(v2 + 52)
                  + 2
                  * *(_BYTE *)(*(_DWORD *)(v2 + 56)
                             + (*(_DWORD *)(v2 + 12) & (v7 >> 16))
                             + ((*(_DWORD *)(v2 + 8) & v8) >> *(_BYTE *)(v2 + 16))));
    v3 += *(_DWORD *)v2;
    v6 = *(_DWORD *)(v2 + 60);
    v5 = *(_DWORD *)(v2 + 36);
    *(_WORD *)result = v9;
    *(_DWORD *)(v2 + 60) += 8;
    *(_DWORD *)(v6 + 4) = v5;
  }
  *(_DWORD *)(v2 + 64) = result;
  *(_DWORD *)(v2 + 48) = v4;
  *(_DWORD *)(v2 + 44) = v3;
  return result;
}

//----- (004D714C) --------------------------------------------------------
function_error;//int __usercall sub_4D714C<eax>(int a1<ebp>)
int sub_4D714C(int a1)
{
  int result; // eax@1
  int v2; // ebp@1
  unsigned int v3; // edi@1
  unsigned int v4; // esi@1
  int v5; // ebx@2
  int v6; // edx@2
  int v7; // ebx@3
  __int16 v8; // cx@3
  int v9; // ebx@3
  int v10; // edx@3
  int v11; // edx@4
  __int16 v12; // cx@4
  unsigned __int8 v13; // sf@5
  unsigned __int8 v14; // of@5

  v2 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(v2 + 48);
  v3 = *(_DWORD *)(v2 + 44);
  result = *(_DWORD *)(v2 + 64);
  if ( !(*(_DWORD *)(v2 + 40) & 1) )
    goto LABEL_5;
  --*(_DWORD *)(v2 + 40);
  result += 2;
  v5 = *(_DWORD *)(v2 + 60);
  v6 = *(_DWORD *)(v2 + 36);
  *(_DWORD *)(v2 + 60) -= 4;
  *(_DWORD *)v5 = v6;
  while ( 1 )
  {
    v11 = *(_DWORD *)(v2 + 12) & (v4 >> 16);
    result -= 4;
    v4 += *(_DWORD *)(v2 + 4);
    v12 = *(_WORD *)(*(_DWORD *)(v2 + 52)
                   + 2 * *(_BYTE *)(*(_DWORD *)(v2 + 56) + v11 + ((*(_DWORD *)(v2 + 8) & v3) >> *(_BYTE *)(v2 + 16))));
    v3 += *(_DWORD *)v2;
    *(_WORD *)(result + 2) = v12;
LABEL_5:
    compile_error;//v14 = __SETO__(*(_DWORD *)(v2 + 40), 2);
    v13 = *(_DWORD *)(v2 + 40) - 2 < 0;
    *(_DWORD *)(v2 + 40) -= 2;
    if ( v13 ^ v14 )
      break;
    v7 = *(_BYTE *)(*(_DWORD *)(v2 + 56)
                  + (*(_DWORD *)(v2 + 12) & (v4 >> 16))
                  + ((*(_DWORD *)(v2 + 8) & v3) >> *(_BYTE *)(v2 + 16)));
    v4 += *(_DWORD *)(v2 + 4);
    v8 = *(_WORD *)(*(_DWORD *)(v2 + 52) + 2 * v7);
    v3 += *(_DWORD *)v2;
    v9 = *(_DWORD *)(v2 + 60);
    v10 = *(_DWORD *)(v2 + 36);
    *(_WORD *)result = v8;
    *(_DWORD *)(v2 + 60) -= 8;
    *(_DWORD *)v9 = v10;
    *(_DWORD *)(v9 - 4) = v10;
  }
  *(_DWORD *)(v2 + 64) = result;
  *(_DWORD *)(v2 + 48) = v4;
  *(_DWORD *)(v2 + 44) = v3;
  return result;
}

//----- (004D71F8) --------------------------------------------------------
function_error;//int __usercall sub_4D71F8<eax>(int a1<ebp>)
int sub_4D71F8(int a1)
{
  int result; // eax@1
  int v2; // ebp@1
  unsigned int v3; // edi@1
  unsigned int v4; // esi@1
  int v5; // ebx@2
  int v6; // edx@2
  unsigned int v7; // edx@3
  unsigned int v8; // ebx@3
  __int16 v9; // cx@11
  int v10; // ebx@11
  int v11; // edx@11
  unsigned int v12; // edx@12
  unsigned int v13; // ebx@12
  unsigned __int8 v14; // sf@21
  unsigned __int8 v15; // of@21

  v2 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(v2 + 48);
  v3 = *(_DWORD *)(v2 + 44);
  result = *(_DWORD *)(v2 + 64);
  if ( !(*(_DWORD *)(v2 + 40) & 1) )
    goto LABEL_21;
  --*(_DWORD *)(v2 + 40);
  result += 2;
  v5 = *(_DWORD *)(v2 + 60);
  v6 = *(_DWORD *)(v2 + 36);
  *(_DWORD *)(v2 + 60) -= 4;
  *(_DWORD *)v5 = v6;
  while ( 1 )
  {
    v13 = v3;
    v12 = v4;
    if ( (signed int)v4 < *(_DWORD *)(v2 + 20) )
      v12 = *(_DWORD *)(v2 + 20);
    if ( (signed int)v3 < *(_DWORD *)(v2 + 28) )
      v13 = *(_DWORD *)(v2 + 28);
    if ( (signed int)v12 > *(_DWORD *)(v2 + 24) )
      v12 = *(_DWORD *)(v2 + 24);
    if ( (signed int)v13 > *(_DWORD *)(v2 + 32) )
      v13 = *(_DWORD *)(v2 + 32);
    result -= 4;
    v4 += *(_DWORD *)(v2 + 4);
    v3 += *(_DWORD *)v2;
    *(_WORD *)(result + 2) = *(_WORD *)(*(_DWORD *)(v2 + 52)
                                      + 2
                                      * *(_BYTE *)(*(_DWORD *)(v2 + 56)
                                                 + (*(_DWORD *)(v2 + 12) & (v12 >> 16))
                                                 + ((*(_DWORD *)(v2 + 8) & v13) >> *(_BYTE *)(v2 + 16))));
LABEL_21:
    compile_error;//v15 = __SETO__(*(_DWORD *)(v2 + 40), 2);
    v14 = *(_DWORD *)(v2 + 40) - 2 < 0;
    *(_DWORD *)(v2 + 40) -= 2;
    if ( v14 ^ v15 )
      break;
    v8 = v3;
    v7 = v4;
    if ( (signed int)v4 < *(_DWORD *)(v2 + 20) )
      v7 = *(_DWORD *)(v2 + 20);
    if ( (signed int)v3 < *(_DWORD *)(v2 + 28) )
      v8 = *(_DWORD *)(v2 + 28);
    if ( (signed int)v7 > *(_DWORD *)(v2 + 24) )
      v7 = *(_DWORD *)(v2 + 24);
    if ( (signed int)v8 > *(_DWORD *)(v2 + 32) )
      v8 = *(_DWORD *)(v2 + 32);
    v4 += *(_DWORD *)(v2 + 4);
    v9 = *(_WORD *)(*(_DWORD *)(v2 + 52)
                  + 2
                  * *(_BYTE *)(*(_DWORD *)(v2 + 56)
                             + (*(_DWORD *)(v2 + 12) & (v7 >> 16))
                             + ((*(_DWORD *)(v2 + 8) & v8) >> *(_BYTE *)(v2 + 16))));
    v3 += *(_DWORD *)v2;
    v10 = *(_DWORD *)(v2 + 60);
    v11 = *(_DWORD *)(v2 + 36);
    *(_WORD *)result = v9;
    *(_DWORD *)(v2 + 60) -= 8;
    *(_DWORD *)v10 = v11;
    *(_DWORD *)(v10 - 4) = v11;
  }
  *(_DWORD *)(v2 + 64) = result;
  *(_DWORD *)(v2 + 48) = v4;
  *(_DWORD *)(v2 + 44) = v3;
  return result;
}

//----- (004D72EC) --------------------------------------------------------
function_error;//int __usercall sub_4D72EC<eax>(int a1<ebp>)
int sub_4D72EC(int a1)
{
  int result; // eax@1
  int v2; // ebp@1
  unsigned int v3; // edi@1
  unsigned int v4; // esi@1
  int v5; // edx@2
  int v6; // ebx@2
  unsigned int v7; // edx@3
  unsigned int v8; // ebx@3
  int v9; // ebx@11
  unsigned int v10; // edx@14
  unsigned int v11; // ebx@14
  int v12; // ebx@22
  unsigned __int8 v13; // sf@25
  unsigned __int8 v14; // of@25

  v2 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(v2 + 48);
  v3 = *(_DWORD *)(v2 + 44);
  result = *(_DWORD *)(v2 + 64);
  if ( !(*(_DWORD *)(v2 + 40) & 1) )
    goto LABEL_25;
  --*(_DWORD *)(v2 + 40);
  result -= 2;
  v6 = *(_DWORD *)(v2 + 60);
  v5 = *(_DWORD *)(v2 + 36);
  *(_DWORD *)(v2 + 60) += 4;
  while ( 1 )
  {
    *(_DWORD *)v6 = v5;
    v10 = v4;
    v11 = v3;
    if ( (signed int)v4 < *(_DWORD *)(v2 + 20) )
      v10 = *(_DWORD *)(v2 + 20);
    if ( (signed int)v3 < *(_DWORD *)(v2 + 28) )
      v11 = *(_DWORD *)(v2 + 28);
    if ( (signed int)v10 > *(_DWORD *)(v2 + 24) )
      v10 = *(_DWORD *)(v2 + 24);
    if ( (signed int)v11 > *(_DWORD *)(v2 + 32) )
      v11 = *(_DWORD *)(v2 + 32);
    v12 = *(_BYTE *)(*(_DWORD *)(v2 + 56)
                   + (*(_DWORD *)(v2 + 12) & (v10 >> 16))
                   + ((*(_DWORD *)(v2 + 8) & v11) >> *(_BYTE *)(v2 + 16)));
    result += 4;
    v4 += *(_DWORD *)(v2 + 4);
    if ( v12 )
      *(_WORD *)(result - 2) = *(_WORD *)(*(_DWORD *)(v2 + 52) + 2 * v12);
    v3 += *(_DWORD *)v2;
LABEL_25:
    compile_error;//v14 = __SETO__(*(_DWORD *)(v2 + 40), 2);
    v13 = *(_DWORD *)(v2 + 40) - 2 < 0;
    *(_DWORD *)(v2 + 40) -= 2;
    if ( v13 ^ v14 )
      break;
    v7 = v4;
    v8 = v3;
    if ( (signed int)v4 < *(_DWORD *)(v2 + 20) )
      v7 = *(_DWORD *)(v2 + 20);
    if ( (signed int)v3 < *(_DWORD *)(v2 + 28) )
      v8 = *(_DWORD *)(v2 + 28);
    if ( (signed int)v7 > *(_DWORD *)(v2 + 24) )
      v7 = *(_DWORD *)(v2 + 24);
    if ( (signed int)v8 > *(_DWORD *)(v2 + 32) )
      v8 = *(_DWORD *)(v2 + 32);
    v9 = *(_BYTE *)(*(_DWORD *)(v2 + 56)
                  + (*(_DWORD *)(v2 + 12) & (v7 >> 16))
                  + ((*(_DWORD *)(v2 + 8) & v8) >> *(_BYTE *)(v2 + 16)));
    v4 += *(_DWORD *)(v2 + 4);
    if ( v9 )
      *(_WORD *)result = *(_WORD *)(*(_DWORD *)(v2 + 52) + 2 * v9);
    v3 += *(_DWORD *)v2;
    v6 = *(_DWORD *)(v2 + 60);
    v5 = *(_DWORD *)(v2 + 36);
    *(_DWORD *)(v2 + 60) += 8;
    *(_DWORD *)(v6 + 4) = v5;
  }
  return result;
}

//----- (004D73DF) --------------------------------------------------------
function_error;//int __usercall sub_4D73DF<eax>(int a1<ebp>)
int sub_4D73DF(int a1)
{
  int result; // eax@1
  int v2; // ebp@1
  unsigned int v3; // edi@1
  unsigned int v4; // esi@1
  int v5; // edx@2
  int v6; // ebx@2
  int v7; // edx@3
  int v8; // edx@6
  unsigned __int8 v9; // sf@9
  unsigned __int8 v10; // of@9

  v2 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(v2 + 48);
  v3 = *(_DWORD *)(v2 + 44);
  result = *(_DWORD *)(v2 + 64);
  if ( !(*(_DWORD *)(v2 + 40) & 1) )
    goto LABEL_9;
  --*(_DWORD *)(v2 + 40);
  result -= 2;
  v6 = *(_DWORD *)(v2 + 60);
  v5 = *(_DWORD *)(v2 + 36);
  *(_DWORD *)(v2 + 60) += 4;
  while ( 1 )
  {
    *(_DWORD *)v6 = v5;
    v8 = *(_DWORD *)(v2 + 12) & (v4 >> 16);
    result += 4;
    v4 += *(_DWORD *)(v2 + 4);
    if ( *(_BYTE *)(*(_DWORD *)(v2 + 56) + v8 + ((*(_DWORD *)(v2 + 8) & v3) >> *(_BYTE *)(v2 + 16))) )
      *(_WORD *)(result - 2) = *(_WORD *)(*(_DWORD *)(v2 + 52)
                                        + 2
                                        * *(_BYTE *)(*(_DWORD *)(v2 + 56)
                                                   + v8
                                                   + ((*(_DWORD *)(v2 + 8) & v3) >> *(_BYTE *)(v2 + 16))));
    v3 += *(_DWORD *)v2;
LABEL_9:
    compile_error;//v10 = __SETO__(*(_DWORD *)(v2 + 40), 2);
    v9 = *(_DWORD *)(v2 + 40) - 2 < 0;
    *(_DWORD *)(v2 + 40) -= 2;
    if ( v9 ^ v10 )
      break;
    v7 = *(_DWORD *)(v2 + 12) & (v4 >> 16);
    v4 += *(_DWORD *)(v2 + 4);
    if ( *(_BYTE *)(*(_DWORD *)(v2 + 56) + v7 + ((*(_DWORD *)(v2 + 8) & v3) >> *(_BYTE *)(v2 + 16))) )
      *(_WORD *)result = *(_WORD *)(*(_DWORD *)(v2 + 52)
                                  + 2
                                  * *(_BYTE *)(*(_DWORD *)(v2 + 56)
                                             + v7
                                             + ((*(_DWORD *)(v2 + 8) & v3) >> *(_BYTE *)(v2 + 16))));
    v3 += *(_DWORD *)v2;
    v6 = *(_DWORD *)(v2 + 60);
    v5 = *(_DWORD *)(v2 + 36);
    *(_DWORD *)(v2 + 60) += 8;
    *(_DWORD *)(v6 + 4) = v5;
  }
  return result;
}
