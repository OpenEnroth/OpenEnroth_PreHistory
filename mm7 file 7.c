#include <ddraw.h>
#include <dinput.h>

#include "defs.h"



#include "AIL.h"

#include "data.h"
#include "RenderD3D3.h"
#include "_audio.h"
#include "_video.h"
#include "FrameTables.h"
#include "GUI.h"
#include "Level.h"
#include "Actor.h"
//#include "codec.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"


//----- (004AD504) --------------------------------------------------------
int __fastcall sub_4AD504(int a1)
{
  int result; // eax@1
  int v2; // ebx@1
  int v3; // esi@3
  int v4; // edi@6
  int v5; // eax@7
  int v6; // edx@7
  int v7; // ecx@7
  int v8; // ebx@8
  int v9; // eax@8
  int v10; // ebx@8
  int v11; // ebx@9
  int v12; // esi@10
  int v13; // eax@13
  int v14; // eax@13
  int v15; // eax@14
  int v16; // ebx@14
  int v17; // ebx@15
  int v18; // eax@15
  int v19; // ebx@15
  signed int v20; // esi@15
  int v21; // ecx@15
  int v22; // eax@15
  int v23; // eax@15
  int v24; // esi@16
  int v25; // eax@18
  int v26; // eax@18
  int v27; // esi@20
  int v28; // eax@20
  signed int v29; // esi@20
  signed int v30; // edx@20
  signed int v31; // esi@20
  signed int v32; // edi@20
  int v33; // eax@26
  unsigned int v34; // edx@27
  char v35; // cl@27
  char v36; // ch@27
  int v37; // ebx@27
  int v38; // edi@27
  int v39; // esi@27
  int v40; // ebx@29
  int v41; // edx@29
  unsigned int v42; // ebx@30
  int v43; // edx@30
  int v44; // eax@33
  unsigned int v45; // edx@34
  char v46; // cl@34
  char v47; // ch@34
  int v48; // ebx@34
  int v49; // edi@34
  int v50; // esi@34
  int v51; // ebx@36
  int v52; // edx@36
  __int16 v53; // bx@37
  int v54; // edx@37
  int v55; // eax@40
  int v56; // eax@41
  unsigned int v57; // edx@42
  char v58; // cl@42
  char v59; // ch@42
  int v60; // ebx@42
  int v61; // edi@42
  int v62; // esi@42
  unsigned int v63; // ebx@44
  int v64; // edx@44
  unsigned int v65; // ebx@44
  int v66; // edx@44
  unsigned int v67; // ebx@45
  int v68; // edx@45
  int v69; // ebx@45
  int v70; // edx@45
  int v71; // eax@48
  unsigned int v72; // edx@49
  char v73; // cl@49
  char v74; // ch@49
  int v75; // ebx@49
  int v76; // edi@49
  int v77; // esi@49
  unsigned int v78; // ebx@51
  int v79; // edx@51
  unsigned int v80; // ebx@51
  int v81; // edx@51
  unsigned int v82; // ebx@52
  int v83; // edx@52
  int v84; // ebx@52
  int v85; // edx@52
  int v86; // [sp+Ch] [bp-98h]@9
  int v87; // [sp+10h] [bp-94h]@9
  int v88; // [sp+14h] [bp-90h]@9
  int v89; // [sp+18h] [bp-8Ch]@9
  int v90; // [sp+1Ch] [bp-88h]@20
  int v91; // [sp+20h] [bp-84h]@3
  int v92; // [sp+24h] [bp-80h]@7
  int i; // [sp+28h] [bp-7Ch]@7
  char *v94; // [sp+2Ch] [bp-78h]@9
  int v95; // [sp+30h] [bp-74h]@1
  int v96; // [sp+34h] [bp-70h]@6
  int v97; // [sp+38h] [bp-6Ch]@15
  int v98; // [sp+3Ch] [bp-68h]@9
  int v99; // [sp+40h] [bp-64h]@9
  int v100; // [sp+44h] [bp-60h]@24
  int v101; // [sp+48h] [bp-5Ch]@10
  int v102; // [sp+4Ch] [bp-58h]@20
  int v103; // [sp+50h] [bp-54h]@20
  int v104; // [sp+54h] [bp-50h]@9
  int v105; // [sp+58h] [bp-4Ch]@20
  int v106; // [sp+5Ch] [bp-48h]@24
  int v107; // [sp+60h] [bp-44h]@20
  int v108; // [sp+64h] [bp-40h]@20
  int v109; // [sp+68h] [bp-3Ch]@20
  int v110; // [sp+6Ch] [bp-38h]@15
  int v111; // [sp+70h] [bp-34h]@20
  int v112; // [sp+74h] [bp-30h]@12
  int v113; // [sp+78h] [bp-2Ch]@9
  int v114; // [sp+7Ch] [bp-28h]@16
  int v115; // [sp+80h] [bp-24h]@18
  int v116; // [sp+84h] [bp-20h]@7
  unsigned int v117; // [sp+88h] [bp-1Ch]@15
  unsigned int v118; // [sp+8Ch] [bp-18h]@24
  int v119; // [sp+90h] [bp-14h]@13
  int v120; // [sp+94h] [bp-10h]@15
  unsigned int v121; // [sp+98h] [bp-Ch]@15
  char *v122; // [sp+9Ch] [bp-8h]@15
  int v123; // [sp+A0h] [bp-4h]@13

  result = pD3DRenderer->uTargetSurfacePitch;
  v2 = a1;
  v95 = pD3DRenderer->uTargetSurfacePitch;
  if ( a1 >= 0 )
  {
    if ( a1 < dword_6BE640 )
    {
      v3 = dword_6BE644 + 96 * a1;
      v91 = dword_6BE644 + 96 * a1;
      if ( !pD3DRenderer->pRendererD3D3 )
      {
        result = sub_423B5D(a1);
        if ( result )
        {
          result = sub_424829(result, (int)&dword_F8A590, dword_51B75C, v2);
          if ( result )
          {
            result = sub_4AE5BA(v3);
            v4 = result;
            v96 = result;
            if ( result )
            {
              v5 = *(_WORD *)(result + 38);
              *(_BYTE *)(v3 + 44) |= 0x80u;
              v92 = v5;
              sub_4AE5F1(v2);
              ++dword_51B764;
              v6 = dword_F8AD64;
              v116 = dword_F8AD68;
              v7 = 0;
              for ( i = (unsigned __int8)bUseLoResSprites; v7 < dword_F8ADD4; *(_DWORD *)v9 = v10 )
              {
                v8 = v116;
                dword_F8AE78[v7] += v6;
                v9 = 4 * v7 + 16297672;
                v10 = v8 - dword_F8AEC8[v7++];
              }
              v94 = sub_47C24C(v3, v92, 0, 1);
              result = dword_F8A590;
              v113 = dword_F8A590;
              v11 = dword_F8A590 * pD3DRenderer->uTargetSurfacePitch;
              v99 = 640 * dword_F8A590;
              v86 = *(_DWORD *)(v4 + 48);
              v87 = *(_DWORD *)(v4 + 52);
              v88 = *(_DWORD *)(v4 + 56);
              v89 = *(_DWORD *)(v4 + 60);
              v98 = dword_F8A590 * pD3DRenderer->uTargetSurfacePitch;
              v104 = 2 * dword_51B6E0;
              if ( dword_F8A590 <= dword_F8A594 )
              {
                v12 = 2 * dword_F8A590;
                v101 = 2 * dword_F8A590;
                while ( 1 )
                {
                  v112 = *(__int16 *)((char *)word_F8A5A8 + v12);
                  sub_4AE313(v112, result, (int)&dword_F81018);
                  if ( struct_576FE8.dword_000020 )
                  {
                    v15 = v95 * (v12 - dword_51B738);
                    v119 = dword_51B748
                         + 4
                         * (2 * (*(__int16 *)((char *)word_F8A5A8 + v12) + 320 * (v12 - dword_51B738)) - dword_51B734);
                    v16 = dword_51B728 + 2 * (v15 + 2 * *(__int16 *)((char *)word_F8A5A8 + v12) - dword_51B734);
                    v13 = dword_51B728 + 2 * (v15 + 2 * *(__int16 *)((char *)word_F8A968 + v12) - dword_51B734);
                    v123 = v16;
                  }
                  else
                  {
                    v14 = *(__int16 *)((char *)word_F8A5A8 + v12);
                    v119 = dword_51B748 + 4 * (v14 + v99);
                    v123 = dword_51B728 + 2 * (v14 + v11);
                    v13 = dword_51B728 + 2 * (v11 + *(__int16 *)((char *)word_F8A968 + v12));
                  }
                  v117 = v13;
                  HIWORD(v18) = HIWORD(dword_F81018);
                  v19 = dword_F81028;
                  LOWORD(v18) = 0;
                  v97 = dword_F8AD28 | v18;
                  v110 = sub_4AE491(word_F8101E, word_F81022);
                  v20 = unk_F8101C >> i;
                  v21 = 11 - v19;
                  v116 = unk_F81020 >> i;
                  v22 = unk_F81020 >> i >> (11 - v19);
                  v17 = pClass59_global;
                  v122 = (char *)v21;
                  v121 = (unk_F8101C >> i) + 4 * class59_SinCos(pClass59_global, v104 + v22);
                  v23 = class59_SinCos(pClass59_global, v104 + (v20 >> (char)v122) - pClass59_global->uNumTableEntries);
                  v120 = v116 + 4 * v23;
                  if ( v123 < v117 )
                  {
                    v24 = (int)&unk_F81054;
                    v114 = (int)&unk_F81054;
                    v112 += 16;
                    while ( 1 )
                    {
                      sub_4AE313(v112, v113, v24 - 8);
                      v26 = *(_DWORD *)(v24 - 8);
                      LOWORD(v26) = 0;
                      v115 = v97;
                      v25 = dword_F8AD28 | v26;
                      if ( v97 <= (unsigned int)v25 )
                        v115 = v25;
                      v97 = v25;
                      v28 = *(_DWORD *)(v24 - 44);
                      v29 = *(_DWORD *)(v24 - 4);
                      v105 = *(&v86 + v28);
                      v111 = v28 + 16;
                      v30 = *(_WORD *)(v4 + 32);
                      v109 = v28 + v28 + 16 - *(_WORD *)(v4 + 28);
                      v107 = v30 >> v28;
                      v31 = v29 >> i;
                      v102 = (signed int)*(_WORD *)(v4 + 34) >> v28 << (v28 + 16);
                      v32 = *(_DWORD *)v114 >> i;
                      v122 = (char *)(11 - v28);
                      v116 = v31 + 4 * class59_SinCos(v17, v104 + (v32 >> (11 - v28)));
                      v90 = v32 + 4 * class59_SinCos(v17, v104 + (v31 >> (char)v122) - pClass59_global->uNumTableEntries);
                      v108 = (signed int)(v116 - v121) >> 4;
                      v103 = (v90 - v120) >> 4;
                      v27 = v123 + 32;
                      if (struct_576FE8.dword_000020)
                        v27 = v123 + 64;
                      if ( v27 > v117 )
                        v27 = v117;
                      v118 = v27;
                      v100 = sub_4AE491(*(_WORD *)(v114 - 2), *(_WORD *)(v114 + 2));
                      v106 = (v27 - v123) >> 1;
                      if ( v110 >> 16 == v100 >> 16 )
                      {
                        v122 = sub_47C24C(v91, v92, v110 >> 16, 1);
                        if (struct_576FE8.dword_000020)
                        {
                          v44 = v123;
                          if ( v123 < v118 )
                          {
                            v50 = v119;
                            v49 = (int)v122;
                            v45 = v121;
                            v48 = v120;
                            v46 = v111;
                            v47 = v109;
                            if ( v106 & 2 )
                            {
                              *(_DWORD *)v119 = v115;
                              v50 -= 8;
                              v44 = v123 + 4;
                              goto LABEL_37;
                            }
                            do
                            {
                              v44 += 8;
                              v51 = *(_BYTE *)(v105 + (v107 & (v45 >> v46)) + ((v102 & (unsigned int)v48) >> v47));
                              v52 = v115;
                              LOWORD(v51) = *(_WORD *)(v49 + 2 * v51);
                              *(_DWORD *)v50 = v115;
                              *(_DWORD *)(v50 + 4) = v52;
                              *(_DWORD *)(v50 + 2560) = v52;
                              *(_DWORD *)(v50 + 2564) = v52;
                              *(_WORD *)(v44 - 8) = v51;
                              *(_WORD *)(v44 - 6) = v51;
                              *(_WORD *)(v44 + 1272) = v51;
                              *(_WORD *)(v44 + 1274) = v51;
                              *(_DWORD *)(v50 + 8) = v52;
                              *(_DWORD *)(v50 + 12) = v52;
                              *(_DWORD *)(v50 + 2568) = v52;
                              *(_DWORD *)(v50 + 2572) = v52;
                              v121 += v108;
                              v120 += v103;
                              v45 = v121;
                              v48 = v120;
LABEL_37:
                              v50 += 16;
                              v53 = *(_WORD *)(v49
                                             + 2
                                             * *(_BYTE *)(v105
                                                        + (v107 & (v45 >> v46))
                                                        + ((v102 & (unsigned int)v48) >> v47)));
                              v54 = v108;
                              *(_WORD *)(v44 - 4) = v53;
                              *(_WORD *)(v44 - 2) = v53;
                              *(_WORD *)(v44 + 1276) = v53;
                              *(_WORD *)(v44 + 1278) = v53;
                              v121 += v54;
                              v120 += v103;
                              v45 = v121;
                              v48 = v120;
                            }
                            while ( v44 < v118 );
                            v123 = v44;
                            v119 = v50;
                          }
                        }
                        else
                        {
                          v33 = v123;
                          if ( v123 < v118 )
                          {
                            v39 = v119;
                            v38 = (int)v122;
                            v34 = v121;
                            v37 = v120;
                            v35 = v111;
                            v36 = v109;
                            if ( v106 & 1 )
                            {
                              *(_DWORD *)v119 = v115;
                              v39 -= 4;
                              v33 = v123 + 2;
                              goto LABEL_30;
                            }
                            do
                            {
                              v33 += 4;
                              v40 = *(_BYTE *)(v105 + (v107 & (v34 >> v35)) + ((v102 & (unsigned int)v37) >> v36));
                              v41 = v115;
                              LOWORD(v40) = *(_WORD *)(v38 + 2 * v40);
                              *(_DWORD *)v39 = v115;
                              *(_WORD *)(v33 - 4) = v40;
                              *(_DWORD *)(v39 + 4) = v41;
                              v121 += v108;
                              v120 += v103;
                              v34 = v121;
                              v37 = v120;
LABEL_30:
                              v42 = v105 + (v107 & (v34 >> v35)) + ((v102 & (unsigned int)v37) >> v36);
                              v39 += 8;
                              v43 = v108;
                              *(_WORD *)(v33 - 2) = *(_WORD *)(v38 + 2 * *(_BYTE *)v42);
                              v121 += v43;
                              v120 += v103;
                              v34 = v121;
                              v37 = v120;
                            }
                            while ( v33 < v118 );
                            v123 = v33;
                            v119 = v39;
                          }
                        }
                      }
                      else
                      {
                        v55 = v110 - ((v100 - v110) >> 4);
                        v110 = (v100 - v110) >> 4;
                        v122 = (char *)v55;
                        if (struct_576FE8.dword_000020)
                        {
                          v71 = v123;
                          if ( v123 < v118 )
                          {
                            v77 = v119;
                            v76 = (int)v94;
                            v72 = v121;
                            v75 = v120;
                            v73 = v111;
                            v74 = v109;
                            if ( v106 & 2 )
                            {
                              *(_DWORD *)v119 = v115;
                              v77 += 8;
                              v71 = v123 + 4;
                              goto LABEL_52;
                            }
                            do
                            {
                              v78 = (v107 & (v72 >> v73)) + ((v102 & (unsigned int)v75) >> v74);
                              v79 = (int)&v122[v110];
                              v71 += 8;
                              v122 = (char *)v79;
                              v80 = ((v79 & 0xFFFF0000u) >> 8) + *(_BYTE *)(v105 + v78);
                              v81 = v115;
                              LOWORD(v80) = *(_WORD *)(v76 + 2 * v80);
                              *(_DWORD *)v77 = v115;
                              *(_DWORD *)(v77 + 4) = v81;
                              *(_DWORD *)(v77 + 2560) = v81;
                              *(_DWORD *)(v77 + 2564) = v81;
                              *(_WORD *)(v71 - 8) = v80;
                              *(_WORD *)(v71 - 6) = v80;
                              *(_WORD *)(v71 + 1272) = v80;
                              *(_WORD *)(v71 + 1274) = v80;
                              *(_DWORD *)(v77 + 8) = v81;
                              *(_DWORD *)(v77 + 12) = v81;
                              *(_DWORD *)(v77 + 2568) = v81;
                              *(_DWORD *)(v77 + 2572) = v81;
                              v121 += v108;
                              v120 += v103;
                              v72 = v121;
                              v75 = v120;
                              v77 += 16;
LABEL_52:
                              v82 = (v107 & (v72 >> v73)) + ((v102 & (unsigned int)v75) >> v74);
                              v83 = (int)&v122[v110];
                              v84 = *(_BYTE *)(v105 + v82);
                              v122 = (char *)v83;
                              LOWORD(v84) = *(_WORD *)(v76 + 2 * (((v83 & 0xFFFF0000u) >> 8) + v84));
                              v85 = v108;
                              *(_WORD *)(v71 - 4) = v84;
                              *(_WORD *)(v71 - 2) = v84;
                              *(_WORD *)(v71 + 1276) = v84;
                              *(_WORD *)(v71 + 1278) = v84;
                              v121 += v85;
                              v120 += v103;
                              v72 = v121;
                              v75 = v120;
                            }
                            while ( v71 < v118 );
                            v123 = v71;
                            v119 = v77;
                          }
                        }
                        else
                        {
                          v56 = v123;
                          if ( v123 < v118 )
                          {
                            v62 = v119;
                            v61 = (int)v94;
                            v57 = v121;
                            v60 = v120;
                            v58 = v111;
                            v59 = v109;
                            if ( v106 & 1 )
                            {
                              *(_DWORD *)v119 = v115;
                              v62 += 4;
                              v56 = v123 + 2;
                              goto LABEL_45;
                            }
                            do
                            {
                              v63 = (v107 & (v57 >> v58)) + ((v102 & (unsigned int)v60) >> v59);
                              v64 = (int)&v122[v110];
                              v56 += 4;
                              v122 = (char *)v64;
                              v65 = ((v64 & 0xFFFF0000u) >> 8) + *(_BYTE *)(v105 + v63);
                              v66 = v115;
                              LOWORD(v65) = *(_WORD *)(v61 + 2 * v65);
                              *(_DWORD *)v62 = v115;
                              *(_WORD *)(v56 - 4) = v65;
                              *(_DWORD *)(v62 + 4) = v66;
                              v121 += v108;
                              v120 += v103;
                              v57 = v121;
                              v60 = v120;
                              v62 += 8;
LABEL_45:
                              v67 = (v107 & (v57 >> v58)) + ((v102 & (unsigned int)v60) >> v59);
                              v68 = (int)&v122[v110];
                              v69 = *(_BYTE *)(v105 + v67);
                              v122 = (char *)v68;
                              LOWORD(v69) = *(_WORD *)(v61 + 2 * (((v68 & 0xFFFF0000u) >> 8) + v69));
                              v70 = v108;
                              *(_WORD *)(v56 - 2) = v69;
                              v121 += v70;
                              v120 += v103;
                              v57 = v121;
                              v60 = v120;
                            }
                            while ( v56 < v118 );
                            v123 = v56;
                            v119 = v62;
                          }
                        }
                      }
                      v114 += 52;
                      v110 = v100;
                      v112 += 16;
                      v4 = v96;
                      v121 = v116;
                      v120 = v90;
                      if ( v123 >= v117 )
                        break;
                      v24 = v114;
                      v17 = pClass59_global;
                    }
                  }
                  ++v113;
                  v98 += v95;
                  result = v113;
                  v101 += 2;
                  v99 += 640;
                  if ( v113 > dword_F8A594 )
                    break;
                  v12 = v101;
                  result = v113;
                  v11 = v98;
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}

//----- (004ADD1D) --------------------------------------------------------
void __fastcall sub_4ADD1D(int a1)
{
  int v1; // edi@1
  int v2; // esi@3
  signed int v3; // ebx@4
  signed int v4; // eax@9
  int v5; // edi@9
  _UNKNOWN *v6; // edi@12
  int v8; // eax@15
  int v9; // eax@16
  int v10; // edi@19
  int v11; // ecx@19
  int v12; // eax@19
  char *v13; // eax@19
  int v14; // ebx@20
  int *v15; // esi@20
  int v16; // ecx@22
  DWORD v17; // eax@22
  signed int v18; // ecx@22
  signed int v19; // ST68_4@22
  int v20; // eax@22
  int v21; // eax@23
  int v22; // edi@23
  unsigned int v23; // esi@23
  int v24; // edx@24
  int v25; // ebx@24
  int v26; // ebx@25
  __int16 v27; // cx@25
  int v28; // edx@26
  __int16 v29; // cx@26
  unsigned __int8 v30; // sf@27
  unsigned __int8 v31; // of@27
  int v32; // eax@29
  int v33; // edi@29
  unsigned int v34; // esi@29
  int v35; // edx@30
  int v36; // ebx@30
  int v37; // ebx@31
  __int16 v38; // cx@31
  int v39; // edx@32
  __int16 v40; // cx@32
  unsigned __int8 v41; // sf@33
  unsigned __int8 v42; // of@33
  int v43; // [sp-10h] [bp-6Ch]@16
  int v44; // [sp-Ch] [bp-68h]@15
  int v45; // [sp+10h] [bp-4Ch]@1
  signed int v46; // [sp+14h] [bp-48h]@12
  signed int v47; // [sp+14h] [bp-48h]@22
  int v48; // [sp+1Ch] [bp-40h]@22
  int v49; // [sp+20h] [bp-3Ch]@22
  int v50; // [sp+24h] [bp-38h]@19
  char v51; // [sp+28h] [bp-34h]@19
  int v52; // [sp+2Ch] [bp-30h]@19
  int v53; // [sp+30h] [bp-2Ch]@19
  char *v54; // [sp+34h] [bp-28h]@19
  int v55; // [sp+38h] [bp-24h]@22
  int v56; // [sp+3Ch] [bp-20h]@22
  signed int v57; // [sp+40h] [bp-1Ch]@12
  int v58; // [sp+40h] [bp-1Ch]@20
  int v59; // [sp+44h] [bp-18h]@20
  int *i; // [sp+48h] [bp-14h]@20
  int v61; // [sp+4Ch] [bp-10h]@23
  int v62; // [sp+50h] [bp-Ch]@4
  int v63; // [sp+50h] [bp-Ch]@19
  int v64; // [sp+54h] [bp-8h]@22
  int v65; // [sp+58h] [bp-4h]@23
  int v66; // [sp+58h] [bp-4h]@29

  v1 = a1;
  v45 = pD3DRenderer->uTargetSurfacePitch;
  if ( a1 >= 0 )
  {
    if ( a1 < dword_6BE640 )
    {
      v2 = dword_6BE644 + 96 * a1;
      if ( pD3DRenderer->pRendererD3D3 )
      {
        v3 = sub_424579(a1, (int)&dword_F8AD28);
        v62 = v3;
      }
      else
      {
        v62 = sub_423B5D(a1);
        v3 = v62;
      }
      if ( v3 )
      {
        if ( pD3DRenderer->pRendererD3D3 || sub_424829(v3, (int)&dword_F8A590, dword_51B75C, v1) )
        {
          v5 = sub_4AE5BA(v2);
          v4 = 0;
          if ( v5 )
          {
            if ( pD3DRenderer->pRendererD3D3 )
            {
              if ( v3 > 0 )
              {
                v57 = v3;
                v46 = v3;
                v6 = &array_507D30[0].v;
                do
                {
                  *((float *)v6 - 1) = (double)((GetTickCount() >> 5) - dword_51B6E8) + *((float *)v6 - 1);
                  *(float *)v6 = (double)(dword_51B6EC + (GetTickCount() >> 5)) + *(float *)v6;
                  v6 = (char *)v6 + 48;
                }
                while ( v57-- != 1 );
                v3 = v62;
                v4 = v46;
              }
              v8 = 48 * v4;
              v44 = dword_F8AD28;
              array_507D30[v4].u *= 0.25;
              array_507D30[v4].v *= 0.25;
              if ( *(_BYTE *)(v2 + 45) & 0x40 )
              {
                v43 = sub_4AE5BA(v2);
                v9 = TextureFrameTable_GetFrame(pTextureFrameTable, *(_WORD *)(v2 + 74), dword_51B6E0);
              }
              else
              {
                v43 = sub_4AE5BA(v2);
                v9 = *(_WORD *)(v2 + 74);
              }
              sub_4A2FC0(pD3DRenderer, v3, v2, *(_DWORD *)(pLODFile_Bitmaps_LOD->dword_011BB0 + 4 * v9), v43, v44, -1, 0);
            }
            else
            {
              v52 = *(_WORD *)(v5 + 32);
              v50 = *(_WORD *)(v5 + 34) << 16;
              v11 = 16 - *(_WORD *)(v5 + 28);
              v12 = *(_DWORD *)(v5 + 48);
              *(_BYTE *)(v2 + 44) |= 0x80u;
              v51 = v11;
              v53 = v12;
              sub_4AF412();
              ++dword_51B760;
              v13 = sub_47C24C(v2, *(_WORD *)(v5 + 38), 0, 1);
              v10 = dword_F8A590;
              v54 = v13;
              v63 = dword_F8A590;
              if ( dword_F8A590 <= dword_F8A594 )
              {
                v14 = 2 * dword_F8A590;
                v15 = &dword_F83B80[14 * dword_F8A590];
                v58 = 2 * dword_F8A590;
                v59 = 640 * dword_F8A590;
                for ( i = &dword_F83B80[14 * dword_F8A590]; ; v15 = i )
                {
                  sub_4AE1E7(v10, *(__int16 *)((char *)word_F8A5A8 + v14), v10);
                  *v15 += (GetTickCount() << 11) - (dword_51B6E8 << 16);
                  v17 = GetTickCount();
                  v18 = *v15;
                  v15[1] += (32 * dword_51B6EC + v17) << 11;
                  v48 = v15[1] >> 3;
                  v47 = v18 >> 3;
                  v19 = (signed int)((unsigned __int64)(dword_51B724 * v15[10]) >> 16) >> 3;
                  v55 = (unsigned __int64)(v19 * -dword_51B704) >> 16;
                  v56 = (unsigned __int64)(v19 * dword_51B700) >> 16;
                  v20 = v15[10];
                  v16 = *(__int16 *)((char *)word_F8A5A8 + v14);
                  LOWORD(v20) = 0;
                  v49 = dword_F8AD28 | v20;
                  v64 = *(__int16 *)((char *)word_F8A968 + v14) - v16;
                  if (struct_576FE8.dword_000020)
                  {
                    v66 = dword_51B748 + 4 * (2 * (v16 + 320 * (v14 - dword_51B738)) - dword_51B734);
                    v34 = v47;
                    v33 = v48;
                    v32 = dword_51B728 + 2 * (v45 * (v14 - dword_51B738) + 2 * v16 - dword_51B734);
                    if ( v64 & 1 )
                    {
                      --v64;
                      v32 = dword_51B728 + 2 * (v45 * (v14 - dword_51B738) + 2 * v16 - dword_51B734) - 4;
                      v36 = dword_51B748 + 4 * (2 * (v16 + 320 * (v14 - dword_51B738)) - dword_51B734);
                      v35 = v49;
                      v66 += 8;
                      goto LABEL_32;
                    }
                    while ( 1 )
                    {
                      compile_error;//v42 = __SETO__(v64, 2);
                      v41 = v64 - 2 < 0;
                      v64 -= 2;
                      if ( v41 ^ v42 )
                        break;
                      v37 = *(_BYTE *)(v53 + (v52 & (v34 >> 16)) + ((v50 & (unsigned int)v33) >> v51));
                      v34 += v55;
                      v38 = *(_WORD *)&v54[2 * v37];
                      v33 += v56;
                      v36 = v66;
                      v35 = v49;
                      *(_WORD *)v32 = v38;
                      *(_WORD *)(v32 + 2) = v38;
                      *(_WORD *)(v32 + 1280) = v38;
                      *(_WORD *)(v32 + 1282) = v38;
                      v66 += 16;
                      *(_DWORD *)(v36 + 8) = v49;
                      *(_DWORD *)(v36 + 12) = v49;
                      *(_DWORD *)(v36 + 2568) = v49;
                      *(_DWORD *)(v36 + 2572) = v49;
LABEL_32:
                      *(_DWORD *)v36 = v35;
                      *(_DWORD *)(v36 + 4) = v35;
                      *(_DWORD *)(v36 + 2560) = v35;
                      *(_DWORD *)(v36 + 2564) = v35;
                      v39 = v52 & (v34 >> 16);
                      v32 += 8;
                      v34 += v55;
                      v40 = *(_WORD *)&v54[2 * *(_BYTE *)(v53 + v39 + ((v50 & (unsigned int)v33) >> v51))];
                      v33 += v56;
                      *(_WORD *)(v32 - 4) = v40;
                      *(_WORD *)(v32 - 2) = v40;
                      *(_WORD *)(v32 + 1276) = v40;
                      *(_WORD *)(v32 + 1278) = v40;
                    }
                  }
                  else
                  {
                    v61 = dword_51B728 + 2 * (v16 + v10 * pD3DRenderer->uTargetSurfacePitch);
                    v65 = dword_51B748 + 4 * (v59 + v16);
                    v23 = v47;
                    v22 = v48;
                    v21 = v61;
                    if ( v64 & 1 )
                    {
                      --v64;
                      v21 = v61 - 2;
                      v25 = dword_51B748 + 4 * (v59 + v16);
                      v24 = v49;
                      v65 += 4;
                      goto LABEL_26;
                    }
                    while ( 1 )
                    {
                      compile_error;//v31 = __SETO__(v64, 2);
                      v30 = v64 - 2 < 0;
                      v64 -= 2;
                      if ( v30 ^ v31 )
                        break;
                      v26 = *(_BYTE *)(v53 + (v52 & (v23 >> 16)) + ((v50 & (unsigned int)v22) >> v51));
                      v23 += v55;
                      v27 = *(_WORD *)&v54[2 * v26];
                      v22 += v56;
                      v25 = v65;
                      v24 = v49;
                      *(_WORD *)v21 = v27;
                      v65 += 8;
                      *(_DWORD *)(v25 + 4) = v49;
LABEL_26:
                      *(_DWORD *)v25 = v24;
                      v28 = v52 & (v23 >> 16);
                      v21 += 4;
                      v23 += v55;
                      v29 = *(_WORD *)&v54[2 * *(_BYTE *)(v53 + v28 + ((v50 & (unsigned int)v22) >> v51))];
                      v22 += v56;
                      *(_WORD *)(v21 - 2) = v29;
                    }
                  }
                  ++v63;
                  i += 14;
                  v59 += 640;
                  v58 += 2;
                  if ( v63 > dword_F8A594 )
                    break;
                  v14 = v58;
                  v10 = v63;
                }
              }
            }
          }
        }
      }
    }
  }
}

//----- (004AE1E7) --------------------------------------------------------
int __fastcall sub_4AE1E7(int a1, int a2, int a3)
{
  int v3; // ebx@1
  int v4; // edi@1
  int v5; // esi@1
  int v6; // esi@1
  int v7; // ecx@1
  char v8; // zf@1
  int v9; // esi@3
  signed __int64 v10; // qtt@3
  int result; // eax@5
  int v12; // eax@5
  int v13; // edx@5
  int v14; // [sp+Ch] [bp-8h]@1
  int v15; // [sp+1Ch] [bp+8h]@2

  v3 = dword_51B758 - a3;
  v4 = dword_51B754 - a2;
  v6 = (dword_51B754 - a2) * dword_F8ADA8;
  v14 = a1;
  v7 = (dword_51B758 - a3) * dword_F8ADAC + dword_F8ADA4;
  v8 = v7 + v6 == 0;
  v5 = v7 + v6;
  if ( v8 || (v15 = abs(dword_F8ADB0) >> 14, v15 > abs(v5)) )
  {
    v9 = 1073741824;
  }
  else
  {
    LODWORD(v10) = dword_F8ADB0 << 16;
    HIDWORD(v10) = dword_F8ADB0 >> 16;
    v9 = v10 / (v3 * dword_F8ADAC + dword_F8ADA4 + v4 * dword_F8ADA8);
  }
  v12 = dword_F8ADCC;
  dword_F83B80[14 * v14] = ((unsigned __int64)((v3 * dword_F8ADBC + dword_F8ADB4 + v4 * dword_F8ADB8) * v9) >> 16)
                         + dword_F8ADC0;
  result = (unsigned __int64)((v3 * v12 + dword_F8ADC4 + v4 * dword_F8ADC8) * v9) >> 16;
  v13 = result + dword_F8ADD0;
  dword_F83BA8[14 * v14] = v9;
  dword_F83B84[14 * v14] = v13;
  return result;
}

//----- (004AE313) --------------------------------------------------------
int __fastcall sub_4AE313(int a1, int a2, int X)
{
  int v3; // ebx@1
  int v4; // edi@1
  int v5; // esi@1
  int v6; // ecx@1
  int v7; // ST18_4@2
  signed int v8; // ecx@3
  signed __int64 v9; // qtt@3
  int result; // eax@8
  int v11; // [sp+Ch] [bp-8h]@1

  v3 = dword_51B758 - a2;
  v4 = dword_51B754 - a1;
  ++dword_51B768;
  v6 = (dword_51B758 - a2) * dword_F8ADAC + dword_F8ADA4;
  v5 = v6 + v4 * dword_F8ADA8;
  v11 = v6 + v4 * dword_F8ADA8;
  if ( v6 + v4 * dword_F8ADA8 && (v7 = abs(dword_F8ADB0) >> 14, v7 <= abs(v5)) )
  {
    LODWORD(v9) = dword_F8ADB0 << 16;
    HIDWORD(v9) = dword_F8ADB0 >> 16;
    v8 = v9 / v11;
  }
  else
  {
    v8 = 1073741824;
  }
  if ( v8 >= dword_F8AD5C )
    *(_DWORD *)X = v8;
  else
    *(_DWORD *)X = dword_F8AD5C;
  *(_DWORD *)(X + 4) = ((unsigned __int64)((v3 * dword_F8ADBC + dword_F8ADB4 + v4 * dword_F8ADB8) * v8) >> 16)
                     + dword_F8ADC0
                     + (dword_F8AD64 << 16);
  *(_DWORD *)(X + 8) = ((unsigned __int64)((v3 * dword_F8ADCC + dword_F8ADC4 + v4 * dword_F8ADC8) * v8) >> 16)
                     + dword_F8ADD0
                     + (dword_F8AD68 << 16);
  result = abs((unsigned __int64)(dword_51B724 * v8) >> 16);
  if ( result < 369620 || bUseLoResSprites )
  {
    if ( result < 184810 )
      *(_DWORD *)(X + 16) = result > 92405;
    else
      *(_DWORD *)(X + 16) = 2;
  }
  else
  {
    *(_DWORD *)(X + 16) = 3;
  }
  return result;
}

//----- (004AE491) --------------------------------------------------------
signed int __fastcall sub_4AE491(signed int a1, signed int a2)
{
  signed int v2; // eax@1
  signed int v3; // ecx@1
  signed int v4; // edi@1
  int v5; // eax@2
  unsigned int v6; // ecx@2
  int v7; // ebx@2
  int v8; // esi@2
  int v9; // edx@5
  int v10; // edx@7
  unsigned int v11; // eax@8
  int v13; // [sp+4h] [bp-18h]@2
  int v14; // [sp+8h] [bp-14h]@2
  signed int v15; // [sp+Ch] [bp-10h]@1
  int v16; // [sp+14h] [bp-8h]@1
  signed int v17; // [sp+18h] [bp-4h]@1

  v2 = a1 >> dword_F8AD60;
  v4 = a2 >> dword_F8AD60;
  v17 = dword_F8AD54;
  v3 = 0;
  v15 = v2;
  v16 = 0;
  if ( dword_F8ADD4 > 0 )
  {
    do
    {
      v8 = 4 * v16;
      v13 = abs(v2 - dword_F8AE78[v16]);
      v14 = abs(v4 - dword_F8AEC8[v16]);
      v5 = dword_F8AF18[v16];
      v7 = v13;
      v6 = v14;
      if ( v5 < v13 )
      {
        v5 = v13;
        v7 = dword_F8AF18[v16];
      }
      if ( v5 < v14 )
      {
        v9 = v5;
        v5 = v14;
        v6 = v9;
      }
      if ( v7 < (signed int)v6 )
      {
        v10 = v6;
        v6 = v7;
        v7 = v10;
      }
      v11 = ((unsigned int)(11 * v7) >> 5) + (v6 >> 2) + v5;
      if ( (signed int)v11 < *(int *)((char *)dword_F8ADD8 + v8) )
        v17 += 30 * (v11 * *(int *)((char *)dword_F8AE28 + v8) - 65536);
      ++v16;
      v2 = v15;
    }
    while ( v16 < dword_F8ADD4 );
    v3 = 0;
  }
  if ( dword_F8B10C != v3 )
    v17 -= dword_F8B110 * (v2 - dword_F8B118) + dword_F8B114 * (v4 - dword_F8B11C);
  if ( v17 >= v3 )
  {
    if ( v17 > 2031616 )
      v17 = 2031616;
  }
  else
  {
    v17 = v3;
  }
  ++dword_51B76C;
  return v17;
}

//----- (004AE5BA) --------------------------------------------------------
int __thiscall sub_4AE5BA(int this)
{
  int v1; // ecx@2

  if ( *(_BYTE *)(this + 45) & 0x40 )
    v1 = TextureFrameTable_GetFrame(pTextureFrameTable, *(_WORD *)(this + 74), dword_51B6E0);
  else
    v1 = *(_WORD *)(this + 74);
  return v1 != -1 ? 72 * v1 + 7278780 : 0;
}

//----- (004AE5F1) --------------------------------------------------------
void __fastcall sub_4AE5F1(int a1)
{
  unsigned int v1; // eax@1
  int v2; // ecx@1
  int v3; // ebx@1
  int v4; // edi@1
  int v5; // esi@1
  int v6; // eax@1
  int v7; // edi@1
  int v8; // eax@1
  unsigned int v9; // eax@1
  int v10; // ecx@5
  int v11; // eax@10
  int v12; // edx@10
  int v13; // ecx@10
  int v14; // edi@10
  int v15; // ebx@12
  int v16; // eax@16
  double v17; // st7@16
  _UNKNOWN *v18; // ebx@17
  int v19; // eax@19
  int v20; // ecx@19
  int v21; // edx@21
  int v22; // eax@23
  int v23; // ST04_4@26
  int v24; // edi@26
  double v25; // st6@26
  int v26; // eax@26
  double v27; // st6@26
  int v28; // ecx@26
  char v29; // al@26
  int v30; // edx@28
  int v31; // ecx@28
  int v32; // ecx@32
  int v33; // eax@33
  int v34; // edx@33
  int v35; // edi@33
  int v36; // edi@35
  int v37; // edx@37
  int v38; // ebx@39
  int v39; // edi@42
  int v40; // eax@42
  unsigned __int8 v41; // sf@43
  unsigned __int8 v42; // of@43
  _UNKNOWN *v43; // ebx@45
  signed int v44; // ecx@47
  int v45; // edi@47
  int v46; // eax@49
  int v47; // edx@51
  int v48; // eax@53
  int v49; // ST04_4@55
  int v50; // edi@55
  double v51; // st6@55
  int v52; // eax@55
  double v53; // st6@55
  int v54; // eax@55
  int v55; // ecx@57
  int v56; // ecx@58
  int v57; // ecx@59
  int v58; // edx@62
  int v59; // ecx@62
  int v60; // eax@63
  int v61; // edx@64
  int v62; // edx@67
  int v63; // ecx@67
  int v64; // eax@68
  int v65; // edx@69
  signed int v66; // ecx@72
  char v67; // zf@72
  double v68; // st7@75
  int v69; // [sp+Ch] [bp-34h]@9
  int v70; // [sp+10h] [bp-30h]@9
  int v71; // [sp+14h] [bp-2Ch]@9
  int v72; // [sp+18h] [bp-28h]@9
  int v73; // [sp+1Ch] [bp-24h]@9
  int v74; // [sp+20h] [bp-20h]@9
  int v75; // [sp+24h] [bp-1Ch]@1
  int v76; // [sp+28h] [bp-18h]@10
  int v77; // [sp+2Ch] [bp-14h]@10
  int X; // [sp+30h] [bp-10h]@10
  int v79; // [sp+34h] [bp-Ch]@10
  int v80; // [sp+38h] [bp-8h]@10
  int v81; // [sp+3Ch] [bp-4h]@10

  v5 = dword_6BE644 + 96 * a1;
  v3 = dword_6BE64C + 36 * *(_WORD *)(v5 + 72);
  v6 = *(_WORD *)(v5 + 74);
  v7 = *(_WORD *)(v5 + 74);
  v75 = v3;
  v4 = v7 != -1 ? 72 * v6 + 7278780 : 0;
  v8 = 8 * a1;
  LOBYTE(v8) = 8 * a1 | 6;
  dword_F8AD28 = v8;
  dword_F8AD2C = *(_DWORD *)(v5 + 16);
  dword_F8AD30 = *(_DWORD *)(v5 + 20);
  dword_F8AD34 = *(_DWORD *)(v5 + 24);
  dword_F8AD38 = *(_DWORD *)(v5 + 28);
  dword_F8AD64 = *(_WORD *)(v3 + 20);
  dword_F8AD68 = *(_WORD *)(v3 + 22);
  v9 = GetTickCount();
  v2 = *(_DWORD *)(v5 + 44);
  v1 = v9 >> 3;
  if ( v2 & 4 )
  {
    dword_F8AD68 -= v1 & *(_WORD *)(v4 + 34);
  }
  else
  {
    if ( v2 & 0x20 )
      dword_F8AD68 += v1 & *(_WORD *)(v4 + 34);
  }
  v10 = *(_DWORD *)(v5 + 44);
  if ( BYTE1(v10) & 8 )
  {
    dword_F8AD64 -= v1 & *(_WORD *)(v4 + 32);
  }
  else
  {
    if ( v10 & 0x40 )
      dword_F8AD64 += v1 & *(_WORD *)(v4 + 32);
  }
  sub_498A41(v5, (int)&v72, (int)&v69);
  dword_F8AD3C = v72;
  dword_F8AD40 = v73;
  dword_F8AD44 = v74;
  dword_F8AD48 = v69;
  dword_F8AD4C = v70;
  dword_F8AD50 = v71;
  dword_F8B120 = *(_WORD *)(v3 + 34);
  if ( dword_51B6F8 )
  {
    v81 = (unsigned __int64)(dword_F8AD30 * dword_51B704) >> 16;
    v81 = ((unsigned __int64)(dword_F8AD2C * dword_51B700) >> 16) - v81;
    X = (unsigned __int64)(dword_F8AD34 * dword_51B70C) >> 16;
    dword_F8AD7C = ((unsigned __int64)(v81 * dword_51B708) >> 16) - X;
    dword_F8AD80 = ((unsigned __int64)(dword_F8AD2C * dword_51B704) >> 16)
                 + ((unsigned __int64)(dword_F8AD30 * dword_51B700) >> 16);
    dword_F8AD84 = ((unsigned __int64)(v81 * dword_51B70C) >> 16)
                 + ((unsigned __int64)(dword_F8AD34 * dword_51B708) >> 16);
    v77 = (unsigned __int64)(dword_F8AD40 * dword_51B704) >> 16;
    v81 = ((unsigned __int64)(dword_F8AD3C * dword_51B700) >> 16) - v77;
    v77 = (unsigned __int64)(dword_F8AD44 * dword_51B70C) >> 16;
    dword_F8AD8C = ((unsigned __int64)(v81 * dword_51B708) >> 16) - v77;
    dword_F8AD90 = ((unsigned __int64)(dword_F8AD3C * dword_51B704) >> 16)
                 + ((unsigned __int64)(dword_F8AD40 * dword_51B700) >> 16);
    dword_F8AD94 = ((unsigned __int64)(v81 * dword_51B70C) >> 16)
                 + ((unsigned __int64)(dword_F8AD44 * dword_51B708) >> 16);
    v77 = (unsigned __int64)(dword_F8AD4C * dword_51B704) >> 16;
    v81 = ((unsigned __int64)(dword_F8AD48 * dword_51B700) >> 16) - v77;
    X = (unsigned __int64)(dword_F8AD48 * dword_51B704) >> 16;
    v79 = (unsigned __int64)(dword_F8AD4C * dword_51B700) >> 16;
    v77 = (unsigned __int64)(dword_F8AD50 * dword_51B70C) >> 16;
    dword_F8AD98 = ((unsigned __int64)(v81 * dword_51B708) >> 16) - v77;
    dword_F8AD9C = ((unsigned __int64)(dword_F8AD48 * dword_51B704) >> 16)
                 + ((unsigned __int64)(dword_F8AD4C * dword_51B700) >> 16);
    dword_F8ADA0 = ((unsigned __int64)(v81 * dword_51B70C) >> 16)
                 + ((unsigned __int64)(dword_F8AD50 * dword_51B708) >> 16);
    v81 = dword_51B704 * dword_51B6EC - dword_51B700 * dword_51B6E8;
    v14 = -(dword_51B700 * dword_51B6EC + dword_51B704 * dword_51B6E8);
    v80 = -65536 * dword_51B6F0;
    v77 = (unsigned __int64)(-65536 * dword_51B6F0 * dword_51B70C) >> 16;
    v13 = ((unsigned __int64)(v81 * dword_51B708) >> 16) - v77;
    v76 = (unsigned __int64)(v81 * dword_51B70C) >> 16;
    v11 = dword_51B6EC;
    v77 = ((unsigned __int64)(v81 * dword_51B70C) >> 16)
        + ((unsigned __int64)(-65536 * dword_51B6F0 * dword_51B708) >> 16);
    v12 = dword_51B6E8;
  }
  else
  {
    v77 = (unsigned __int64)(dword_F8AD30 * dword_51B704) >> 16;
    dword_F8AD7C = ((unsigned __int64)(dword_F8AD2C * dword_51B700) >> 16) - v77;
    dword_F8AD84 = dword_F8AD34;
    dword_F8AD80 = ((unsigned __int64)(dword_F8AD2C * dword_51B704) >> 16)
                 + ((unsigned __int64)(dword_F8AD30 * dword_51B700) >> 16);
    v77 = (unsigned __int64)(dword_F8AD40 * dword_51B704) >> 16;
    dword_F8AD8C = ((unsigned __int64)(dword_F8AD3C * dword_51B700) >> 16) - v77;
    dword_F8AD94 = dword_F8AD44;
    dword_F8AD90 = ((unsigned __int64)(dword_F8AD3C * dword_51B704) >> 16)
                 + ((unsigned __int64)(dword_F8AD40 * dword_51B700) >> 16);
    v77 = (unsigned __int64)(dword_F8AD4C * dword_51B704) >> 16;
    dword_F8AD98 = ((unsigned __int64)(dword_F8AD48 * dword_51B700) >> 16) - v77;
    v76 = (unsigned __int64)(dword_F8AD48 * dword_51B704) >> 16;
    v12 = dword_51B6E8;
    dword_F8ADA0 = dword_F8AD50;
    v11 = dword_51B6EC;
    dword_F8AD9C = ((unsigned __int64)(dword_F8AD48 * dword_51B704) >> 16)
                 + ((unsigned __int64)(dword_F8AD4C * dword_51B700) >> 16);
    v13 = dword_51B704 * dword_51B6EC - dword_51B700 * dword_51B6E8;
    v14 = -(dword_51B700 * dword_51B6EC + dword_51B704 * dword_51B6E8);
    v77 = -65536 * dword_51B6F0;
  }
  dword_F8ADA4 = dword_F8AD7C;
  dword_F8AD88 = dword_F8AD34 * dword_51B6F0 + dword_F8AD38 + dword_F8AD30 * v11 + dword_F8AD2C * v12;
  dword_F8ADA8 = (unsigned __int64)(dword_51B724 * dword_F8AD80) >> 16;
  dword_F8ADAC = (unsigned __int64)(dword_51B724 * dword_F8AD84) >> 16;
  dword_F8ADB0 = -dword_F8AD88;
  dword_F8ADB4 = dword_F8AD8C;
  dword_F8ADB8 = (unsigned __int64)(dword_51B724 * dword_F8AD90) >> 16;
  dword_F8ADBC = (unsigned __int64)(dword_51B724 * dword_F8AD94) >> 16;
  X = (unsigned __int64)(dword_F8AD8C * v13) >> 16;
  v15 = v77;
  v77 = (unsigned __int64)(dword_F8AD94 * v77) >> 16;
  dword_F8ADC4 = dword_F8AD98;
  dword_F8ADC0 = -(X + ((unsigned __int64)(dword_F8AD90 * v14) >> 16) + v77);
  dword_F8ADC8 = (unsigned __int64)(dword_51B724 * dword_F8AD9C) >> 16;
  dword_F8ADCC = (unsigned __int64)(dword_51B724 * dword_F8ADA0) >> 16;
  X = (unsigned __int64)(dword_F8AD98 * v13) >> 16;
  v76 = (unsigned __int64)(dword_F8AD9C * v14) >> 16;
  v77 = (unsigned __int64)(dword_F8ADA0 * v15) >> 16;
  dword_F8AD60 = 0;
  dword_F8ADD0 = -(X + ((unsigned __int64)(dword_F8AD9C * v14) >> 16) + ((unsigned __int64)(dword_F8ADA0 * v15) >> 16));
  if ( *(_DWORD *)(v75 + 4) || *(_DWORD *)(v75 + 8) )
  {
    dword_F8B10C = 1;
    dword_F8B110 = *(_DWORD *)(v75 + 4);
    dword_F8B114 = *(_DWORD *)(v75 + 8);
    dword_F8B118 = *(_WORD *)(v75 + 30);
    dword_F8B11C = *(_WORD *)(v75 + 32);
  }
  else
  {
    dword_F8B10C = 0;
  }
  v17 = 0.003921568859368563;
  v16 = 116 * *(_WORD *)(v5 + 76);
  v76 = v16;
  v81 = 0;
  v80 = 0;
  dword_F8AD54 = (dword_F8B120 + *(_WORD *)(dword_6BE654 + v16 + 98)) << 16;
  v77 = dword_51B6DC;
  if ( dword_51B6DC > 0 )
  {
   v18 = &array_519ABC[0].word_000002;
    do
    {
      if ( v81 >= 20 )
        break;
      v20 = *((_WORD *)v18 + 2);
      v19 = *((_WORD *)v18 - 1);
      if ( v19 > *(_WORD *)(v5 + 80) - v20 )
      {
        if ( v19 < v20 + *(_WORD *)(v5 + 82) )
        {
          v21 = *(_WORD *)v18;
          if ( v21 > *(_WORD *)(v5 + 84) - v20 )
          {
            if ( v21 < v20 + *(_WORD *)(v5 + 86) )
            {
              v22 = *((_WORD *)v18 + 1);
              if ( v22 > *(_WORD *)(v5 + 88) - v20 )
              {
                if ( v22 < v20 + *(_WORD *)(v5 + 90) )
                {
                  X = (*(_DWORD *)(v5 + 28)
                     + (signed int)*((_WORD *)v18 + 1) * *(_DWORD *)(v5 + 24)
                     + v21 * *(_DWORD *)(v5 + 20)
                     + (signed int)*((_WORD *)v18 - 1) * *(_DWORD *)(v5 + 16)) >> 16;
                  if ( X <= v20 )
                  {
                    v23 = X;
                    v24 = 4 * v81;
                    dword_F8ADD8[v81] = v20;
                    *(int *)((char *)dword_F8AE28 + v24) = 65536 / v20;
                    *(int *)((char *)&dword_F8AF68 + v24) = *((_WORD *)v18 + 5) << 16;
                    *(int *)((char *)dword_F8AE78 + v24) = *((_WORD *)v18 - 1);
                    *(int *)((char *)dword_F8AEC8 + v24) = *(_WORD *)v18;
                    *(int *)((char *)dword_F8AFB8 + v24) = *((_WORD *)v18 + 1);
                    v75 = *((_BYTE *)v18 + 6);
                    v25 = (double)v75 * v17;
                    v75 = *((_BYTE *)v18 + 7);
                    v26 = *((_BYTE *)v18 + 8);
                    *(float *)(v24 + 16297992) = v25;
                    v27 = (double)v75;
                    v75 = v26;
                    *(float *)(v24 + 16298072) = v27 * v17;
                    *(float *)(v24 + 16298152) = (double)v75 * v17;
                    v17 = 0.003921568859368563;
                    *(int *)((char *)dword_F8AF18 + v24) = abs(v23);
                    v28 = v81;
                    v29 = *((_BYTE *)v18 + 9);
                    ++v81;
                    byte_F8B0F8[v28] = v29;
                  }
                }
              }
            }
          }
        }
      }
      ++v80;
      v18 = (char *)v18 + 18;
      v16 = v76;
    }
    while ( v80 < v77 );
  }
  v30 = 0;
  v80 = 0;
  v31 = *(_WORD *)(dword_6BE654 + v16 + 84);
  v77 = *(_WORD *)(dword_6BE654 + v16 + 84);
  if ( v31 > 0 )
  {
    while ( v81 < 20 )
    {
      v32 = dword_6BE65C + 16 * *(_WORD *)(*(_DWORD *)(dword_6BE654 + v16 + 88) + 2 * v30);
      if ( !(*(_BYTE *)(v32 + 12) & 8) )
      {
        v35 = *(_WORD *)(v5 + 80);
        v34 = *(_WORD *)v32;
        X = *(_WORD *)(v32 + 14);
        v33 = *(_WORD *)(v32 + 6);
        v75 = *(_WORD *)(v32 + 6);
        if ( v34 > v35 - v33 )
        {
          if ( v34 < v33 + *(_WORD *)(v5 + 82) )
          {
            v36 = *(_WORD *)(v32 + 2);
            if ( v36 > *(_WORD *)(v5 + 84) - v33 )
            {
              if ( v36 < v33 + *(_WORD *)(v5 + 86) )
              {
                v37 = *(_WORD *)(v32 + 4);
                if ( v37 > *(_WORD *)(v5 + 88) - v33 )
                {
                  if ( v37 < v33 + *(_WORD *)(v5 + 90) )
                  {
                    v38 = (*(_DWORD *)(v5 + 28)
                         + (signed int)*(_WORD *)v32 * *(_DWORD *)(v5 + 16)
                         + v37 * *(_DWORD *)(v5 + 24)
                         + v36 * *(_DWORD *)(v5 + 20)) >> 16;
                    if ( v38 >= 0 )
                    {
                      if ( v38 <= v33 )
                      {
                        if ( v33 )
                        {
                          v39 = 4 * v81;
                          dword_F8ADD8[v81] = v33;
                          *(int *)((char *)dword_F8AE28 + v39) = 65536 / v75;
                          *(int *)((char *)&dword_F8AF68 + v39) = X << 16;
                          *(int *)((char *)dword_F8AE78 + v39) = *(_WORD *)v32;
                          *(int *)((char *)dword_F8AEC8 + v39) = *(_WORD *)(v32 + 2);
                          *(int *)((char *)dword_F8AFB8 + v39) = *(_WORD *)(v32 + 4);
                          v75 = *(_BYTE *)(v32 + 8);
                          *(float *)(v39 + 16297992) = (double)v75 * v17;
                          v75 = *(_BYTE *)(v32 + 9);
                          *(float *)(v39 + 16298072) = (double)v75 * v17;
                          v75 = *(_BYTE *)(v32 + 10);
                          *(float *)(v39 + 16298152) = (double)v75 * v17;
                          v17 = 0.003921568859368563;
                          *(int *)((char *)dword_F8AF18 + v39) = abs(v38);
                          v40 = v81++;
                          byte_F8B0F8[v40] = 1;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      v30 = v80 + 1;
      compile_error;//v42 = __SETO__(v80 + 1, v77);
      v41 = v80++ + 1 - v77 < 0;
      if ( !(v41 ^ v42) )
        break;
      v16 = v76;
    }
  }
  v80 = 0;
  if ( dword_519AB4 > 0 )
  {
   v43 = &array_5187F4[0].word_000002;
    do
    {
      if ( v81 >= 20 )
        break;
      v44 = *((_WORD *)v43 + 2);
      v45 = *((_WORD *)v43 - 1);
      if ( v45 > *(_WORD *)(v5 + 80) - v44 )
      {
        if ( v45 < v44 + *(_WORD *)(v5 + 82) )
        {
          v46 = *(_WORD *)v43;
          if ( v46 > *(_WORD *)(v5 + 84) - v44 )
          {
            if ( v46 < v44 + *(_WORD *)(v5 + 86) )
            {
              v47 = *((_WORD *)v43 + 1);
              if ( v47 > *(_WORD *)(v5 + 88) - v44 )
              {
                if ( v47 < v44 + *(_WORD *)(v5 + 90) )
                {
                  v48 = (*(_DWORD *)(v5 + 28)
                       + (signed int)*(_WORD *)v43 * *(_DWORD *)(v5 + 20)
                       + v45 * *(_DWORD *)(v5 + 16)
                       + v47 * *(_DWORD *)(v5 + 24)) >> 16;
                  v76 = v48;
                  if ( v48 >= 0 )
                  {
                    if ( v48 <= v44 )
                    {
                      v49 = v76;
                      v50 = 4 * v81;
                      dword_F8ADD8[v81] = v44;
                      *(int *)((char *)dword_F8AE28 + v50) = 65536 / v44;
                      *(int *)((char *)dword_F8AE78 + v50) = *((_WORD *)v43 - 1);
                      *(int *)((char *)dword_F8AEC8 + v50) = *(_WORD *)v43;
                      *(int *)((char *)dword_F8AFB8 + v50) = *((_WORD *)v43 + 1);
                      v75 = *((_BYTE *)v43 + 6);
                      v51 = (double)v75 * v17;
                      v75 = *((_BYTE *)v43 + 7);
                      v52 = *((_BYTE *)v43 + 8);
                      *(float *)(v50 + 16297992) = v51;
                      v53 = (double)v75;
                      v75 = v52;
                      *(float *)(v50 + 16298072) = v53 * v17;
                      *(float *)(v50 + 16298152) = (double)v75 * v17;
                      v17 = 0.003921568859368563;
                      *(int *)((char *)dword_F8AF18 + v50) = abs(v49);
                      v54 = v81++;
                      byte_F8B0F8[v54] = 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
      ++v80;
      v43 = (char *)v43 + 12;
    }
    while ( v80 < dword_519AB4 );
  }
  dword_F8ADD4 = v81;
  v55 = *(_WORD *)(v5 + 82);
  if ( dword_51B6E8 <= v55 )
  {
    v57 = *(_WORD *)(v5 + 80);
    if ( dword_51B6E8 >= v57 )
      v56 = 0;
    else
      v56 = v57 - dword_51B6E8;
  }
  else
  {
    v56 = dword_51B6E8 - v55;
  }
  v58 = *(_WORD *)(v5 + 86);
  v59 = v56 * v56;
  if ( dword_51B6EC <= v58 )
  {
    v61 = *(_WORD *)(v5 + 84);
    if ( dword_51B6EC >= v61 )
      v60 = 0;
    else
      v60 = v61 - dword_51B6EC;
  }
  else
  {
    v60 = dword_51B6EC - v58;
  }
  v63 = v60 * v60 + v59;
  v62 = *(_WORD *)(v5 + 90);
  if ( dword_51B6F0 <= v62 )
  {
    v65 = *(_WORD *)(v5 + 88);
    if ( dword_51B6F0 >= v65 )
      v64 = 0;
    else
      v64 = v65 - dword_51B6F0;
  }
  else
  {
    v64 = dword_51B6F0 - v62;
  }
  v67 = v64 * v64 + v63 == 0;
  v66 = v64 * v64 + v63;
  if ( v67 )
    dword_F8AD5C = 0;
  else
    dword_F8AD5C = sub_452A9E(v66) << 16;
  v75 = abs(dword_F8AD80);
  v68 = (double)v75;
  if ( v68 >= *(double *)&byte_4D8410[1416] )
  {
    if ( v68 >= *(double *)&byte_4D8410[1408] )
    {
      if ( v68 >= *(double *)&byte_4D8410[1400] )
      {
        dword_F8AD6C = 8;
        dword_F8AD70 = 3;
      }
      else
      {
        dword_F8AD6C = 16;
        dword_F8AD70 = 4;
      }
    }
    else
    {
      dword_F8AD6C = 32;
      dword_F8AD70 = 5;
    }
  }
  else
  {
    dword_F8AD6C = 64;
    dword_F8AD70 = 6;
  }
}

//----- (004AF412) --------------------------------------------------------
int __cdecl sub_4AF412()
{
  int v0; // eax@2
  int v1; // edx@2
  int v2; // ecx@2
  int v3; // ebx@2
  int v4; // edi@2
  int v5; // esi@2
  int v6; // ST20_4@2
  int v7; // ST20_4@2
  int v8; // ST20_4@2
  int v9; // ST20_4@2
  int result; // eax@4

  dword_F8AD34 = -65536;
  dword_F8AD4C = -65536;
  dword_F8AD2C = 0;
  dword_F8AD30 = 0;
  dword_F8AD38 = (dword_51B6F0 + 800) << 16;
  dword_F8AD3C = 65536;
  dword_F8AD40 = 0;
  dword_F8AD44 = 0;
  dword_F8AD48 = 0;
  dword_F8AD50 = 0;
  dword_F8B120 = 0;
  if ( dword_51B6F8 )
  {
    v6 = ((unsigned __int64)(dword_F8AD2C * dword_51B700) >> 16)
       - ((unsigned __int64)(dword_F8AD30 * dword_51B704) >> 16);
    dword_F8AD7C = ((unsigned __int64)(v6 * dword_51B708) >> 16)
                 - ((unsigned __int64)(dword_F8AD34 * dword_51B70C) >> 16);
    dword_F8AD80 = ((unsigned __int64)(dword_F8AD2C * dword_51B704) >> 16)
                 + ((unsigned __int64)(dword_F8AD30 * dword_51B700) >> 16);
    dword_F8AD84 = ((unsigned __int64)(v6 * dword_51B70C) >> 16)
                 + ((unsigned __int64)(dword_F8AD34 * dword_51B708) >> 16);
    v7 = ((unsigned __int64)(dword_F8AD3C * dword_51B700) >> 16)
       - ((unsigned __int64)(dword_F8AD40 * dword_51B704) >> 16);
    dword_F8AD8C = ((unsigned __int64)(v7 * dword_51B708) >> 16)
                 - ((unsigned __int64)(dword_F8AD44 * dword_51B70C) >> 16);
    dword_F8AD90 = ((unsigned __int64)(dword_F8AD3C * dword_51B704) >> 16)
                 + ((unsigned __int64)(dword_F8AD40 * dword_51B700) >> 16);
    dword_F8AD94 = ((unsigned __int64)(v7 * dword_51B70C) >> 16)
                 + ((unsigned __int64)(dword_F8AD44 * dword_51B708) >> 16);
    v8 = ((unsigned __int64)(dword_F8AD48 * dword_51B700) >> 16)
       - ((unsigned __int64)(dword_F8AD4C * dword_51B704) >> 16);
    dword_F8AD98 = ((unsigned __int64)(v8 * dword_51B708) >> 16)
                 - ((unsigned __int64)(dword_F8AD50 * dword_51B70C) >> 16);
    dword_F8AD9C = ((unsigned __int64)(dword_F8AD48 * dword_51B704) >> 16)
                 + ((unsigned __int64)(dword_F8AD4C * dword_51B700) >> 16);
    dword_F8ADA0 = ((unsigned __int64)(v8 * dword_51B70C) >> 16)
                 + ((unsigned __int64)(dword_F8AD50 * dword_51B708) >> 16);
    v5 = -(dword_51B700 * dword_51B6EC + dword_51B704 * dword_51B6E8);
    v9 = dword_51B704 * dword_51B6EC - dword_51B700 * dword_51B6E8;
    v2 = ((unsigned __int64)(v9 * dword_51B708) >> 16)
       - ((unsigned __int64)(-65536 * dword_51B6F0 * dword_51B70C) >> 16);
    v3 = dword_51B6F0;
    v4 = ((unsigned __int64)(-65536 * dword_51B6F0 * dword_51B708) >> 16)
       + ((unsigned __int64)(v9 * dword_51B70C) >> 16);
    v1 = dword_51B6EC;
    v0 = dword_51B6E8;
  }
  else
  {
    dword_F8AD7C = ((unsigned __int64)(dword_F8AD2C * dword_51B700) >> 16)
                 - ((unsigned __int64)(dword_F8AD30 * dword_51B704) >> 16);
    dword_F8AD84 = dword_F8AD34;
    dword_F8AD80 = ((unsigned __int64)(dword_F8AD2C * dword_51B704) >> 16)
                 + ((unsigned __int64)(dword_F8AD30 * dword_51B700) >> 16);
    dword_F8AD8C = ((unsigned __int64)(dword_F8AD3C * dword_51B700) >> 16)
                 - ((unsigned __int64)(dword_F8AD40 * dword_51B704) >> 16);
    dword_F8AD94 = dword_F8AD44;
    dword_F8AD90 = ((unsigned __int64)(dword_F8AD3C * dword_51B704) >> 16)
                 + ((unsigned __int64)(dword_F8AD40 * dword_51B700) >> 16);
    dword_F8AD98 = ((unsigned __int64)(dword_F8AD48 * dword_51B700) >> 16)
                 - ((unsigned __int64)(dword_F8AD4C * dword_51B704) >> 16);
    v1 = dword_51B6EC;
    dword_F8AD9C = ((unsigned __int64)(dword_F8AD48 * dword_51B704) >> 16)
                 + ((unsigned __int64)(dword_F8AD4C * dword_51B700) >> 16);
    dword_F8ADA0 = dword_F8AD50;
    v0 = dword_51B6E8;
    v2 = dword_51B704 * dword_51B6EC - dword_51B700 * dword_51B6E8;
    v3 = dword_51B6F0;
    v5 = -(dword_51B700 * dword_51B6EC + dword_51B704 * dword_51B6E8);
    v4 = -65536 * dword_51B6F0;
  }
  dword_F8ADA4 = dword_F8AD7C;
  dword_F8AD88 = dword_F8AD30 * v1 + dword_F8AD38 + dword_F8AD2C * v0 + dword_F8AD34 * v3;
  dword_F8ADA8 = (unsigned __int64)(dword_51B724 * dword_F8AD80) >> 16;
  dword_F8ADAC = (unsigned __int64)(dword_51B724 * dword_F8AD84) >> 16;
  dword_F8ADB0 = -dword_F8AD88;
  dword_F8ADB4 = dword_F8AD8C;
  dword_F8ADB8 = (unsigned __int64)(dword_51B724 * dword_F8AD90) >> 16;
  dword_F8ADBC = (unsigned __int64)(dword_51B724 * dword_F8AD94) >> 16;
  dword_F8ADC4 = dword_F8AD98;
  dword_F8ADC0 = -(((unsigned __int64)(dword_F8AD8C * v2) >> 16)
                 + ((unsigned __int64)(dword_F8AD90 * v5) >> 16)
                 + ((unsigned __int64)(dword_F8AD94 * v4) >> 16));
  dword_F8ADC8 = (unsigned __int64)(dword_51B724 * dword_F8AD9C) >> 16;
  dword_F8ADCC = (unsigned __int64)(dword_51B724 * dword_F8ADA0) >> 16;
  result = 0;
  dword_F8ADD0 = -(((unsigned __int64)(dword_F8AD98 * v2) >> 16)
                 + ((unsigned __int64)(dword_F8AD9C * v5) >> 16)
                 + ((unsigned __int64)(dword_F8ADA0 * v4) >> 16));
  dword_F8AD60 = 0;
  dword_F8B10C = 0;
  dword_F8AD54 = 0;
  dword_F8ADD4 = 0;
  dword_F8AD5C = 0;
  return result;
}

//----- (004AFB86) --------------------------------------------------------
char __thiscall sub_4AFB86(void *this, int a2, int a3)
{
  int v3; // eax@1
  void *v4; // ebx@1
  char *v5; // ecx@2
  __int16 v6; // ax@11
  int v7; // edx@13
  signed int v8; // ecx@13
  int v9; // edx@16
  int v10; // esi@16
  signed int v11; // ecx@20
  signed int v12; // edi@20
  signed int v13; // esi@20
  int v14; // edx@21
  int v15; // edx@25
  __int16 v16; // ax@35
  int v17; // eax@38
  signed int v19; // [sp+Ch] [bp-14h]@19
  char *v20; // [sp+14h] [bp-Ch]@2
  int v21; // [sp+18h] [bp-8h]@1
  signed int v22; // [sp+1Ch] [bp-4h]@20
  signed int v23; // [sp+28h] [bp+8h]@20

  v4 = this;
  v3 = dword_6BE644 + 96 * a3;
  v21 = v3;
  if ( *(_BYTE *)(v3 + 44) & 1 )
  {
    v5 = (char *)this + 2252 * a2;
    v20 = v5;
    if ( a3 != *((_WORD *)v5 + 2982) )
    {
      if ( !a2
        && dword_51B6E8 >= *(_WORD *)(v3 + 80) - 16
        && dword_51B6E8 <= *(_WORD *)(v3 + 82) + 16
        && dword_51B6EC >= *(_WORD *)(v3 + 84) - 16
        && dword_51B6EC <= *(_WORD *)(v3 + 86) + 16
        && dword_51B6F0 >= *(_WORD *)(v3 + 88) - 16
        && dword_51B6F0 <= *(_WORD *)(v3 + 90) + 16 )
      {
        if ( abs(*(_DWORD *)(v3 + 28) + dword_51B6E8 * *(_DWORD *)(v3 + 16)
                                      + dword_51B6EC * *(_DWORD *)(v3 + 20)
                                      + dword_51B6F0 * *(_DWORD *)(v3 + 24)) <= 589824 )
        {
          v6 = *(_WORD *)(v21 + 76);
          if ( *((_WORD *)v4 + 2004) == v6 )
            v6 = *(_WORD *)(v21 + 78);
          *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2004) = v6;
          *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2982) = a3;
          *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2005) = dword_51B734;
          *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2007) = dword_51B73C;
          *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2006) = dword_51B738;
          *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2008) = dword_51B740;
          compile_error;
          /*
          sub_43F9E1(
            (int)(v4 + 2252 * *((_DWORD *)v4 + 1001)++ + 4020),
            dword_51B734,
            dword_51B738,
            dword_51B73C,
            dword_51B740);*/
          v8 = *((_DWORD *)v4 + 1001) - 1;
          goto LABEL_14;
        }
        v3 = v21;
        v5 = v20;
      }
      v10 = dword_6BE63C + 6 * **(_WORD **)(v3 + 48);
      v9 = *(_DWORD *)(v3 + 16) * ((signed __int16)*(_DWORD *)v10 - dword_51B6E8)
         + *(_DWORD *)(v3 + 20) * ((signed __int16)(*(_DWORD *)v10 >> 16) - dword_51B6EC)
         + *(_DWORD *)(v3 + 24) * (*(_WORD *)(v10 + 4) - dword_51B6F0);
      if ( *((_WORD *)v5 + 2004) != *(_WORD *)(v3 + 76) )
        v9 = -v9;
      if ( v9 < 0 )
      {
        v3 = sub_423B5D(a3);
        v19 = v3;
        if ( v3 )
        {
          v12 = dword_50BAC8[0];
          v11 = dword_50B9D8[0];
          v23 = dword_50BAC8[0];
          v13 = 1;
          v22 = dword_50B9D8[0];
          if ( v3 > 1 )
          {
            do
            {
              v14 = dword_50BAC8[v13];
              if ( v14 < v23 )
                v23 = dword_50BAC8[v13];
              if ( v14 > v12 )
                v12 = dword_50BAC8[v13];
              v15 = dword_50B9D8[v13];
              if ( v15 < v22 )
                v22 = dword_50B9D8[v13];
              if ( v15 > v11 )
                v11 = dword_50B9D8[v13];
              v3 = v19;
              ++v13;
            }
            while ( v13 < v19 );
          }
          if ( v12 >= *((_WORD *)v20 + 2005) )
          {
            if ( v23 <= *((_WORD *)v20 + 2007) )
            {
              if ( v11 >= *((_WORD *)v20 + 2006) )
              {
                if ( v22 <= *((_WORD *)v20 + 2008) )
                {
                  compile_error;//v3 = sub_424829(v3, (int)(v4 + 2252 * *((_DWORD *)v4 + 1001) + 4020), (int)(v20 + 4020), a3);
                  if ( v3 )
                  {
                    v16 = *(_WORD *)(v21 + 76);
                    if ( *((_WORD *)v20 + 2004) == v16 )
                      v16 = *(_WORD *)(v21 + 78);
                    *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2004) = v16;
                    *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2982) = a3;
                    *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2005) = dword_51B734;
                    *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2007) = dword_51B73C;
                    *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2006) = dword_51B738;
                    *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2008) = dword_51B740;
                    v3 = *((_DWORD *)v4 + 1001);
                    if ( v3 < 150 )
                    {
                      v17 = v3 + 1;
                      *((_DWORD *)v4 + 1001) = v17;
                      v8 = v17 - 1;
LABEL_14:
                      LOBYTE(v3) = sub_440639(v8, v7);
                      return v3;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
    v3 = *(_DWORD *)this;
    if ( *(_DWORD *)this < 1000 )
    {
      *((_WORD *)this + 2 * v3 + 2) = a3;
      v3 = *(_DWORD *)this;
      compile_error;//*((_WORD *)this + 2 * *(_DWORD *)this++ + 3) = a2;
    }
  }
  return v3;
}

//----- (004AFF79) --------------------------------------------------------
void __fastcall sub_4AFF79(int a1)
{
  int v1; // ebx@1
  int v2; // eax@3
  int v3; // esi@3
  int v4; // eax@8
  int v5; // edi@8
  int v6; // eax@9
  int v7; // eax@9
  int v8; // ecx@17
  int v9; // ebx@17
  int v10; // eax@17
  int v11; // esi@17
  int v12; // eax@17
  int j; // ecx@19
  int v14; // edx@20
  int v15; // eax@20
  int v16; // edx@20
  int i; // ebx@22
  int v18; // ecx@23
  int v19; // eax@23
  int v20; // eax@23
  int v21; // eax@24
  int v22; // ebx@24
  int v23; // ecx@24
  int v24; // esi@25
  int v25; // eax@28
  int v26; // eax@28
  int v27; // eax@29
  int v28; // eax@30
  int v29; // esi@31
  int v30; // eax@33
  int v31; // eax@33
  int v32; // eax@35
  int v33; // edx@35
  signed int v34; // ebx@35
  int v35; // eax@35
  int v36; // ebx@35
  signed int v37; // ebx@35
  signed int v38; // edi@35
  int v39; // edi@36
  signed int v40; // edx@40
  signed int v41; // edx@40
  signed int v42; // ecx@40
  int v43; // edx@42
  int v44; // eax@42
  int v45; // eax@43
  unsigned int v46; // edx@44
  char v47; // cl@44
  char v48; // ch@44
  int v49; // ebx@44
  int v50; // edi@44
  int v51; // esi@44
  unsigned int v52; // ebx@46
  int v53; // edx@46
  unsigned int v54; // ebx@46
  int v55; // edx@46
  unsigned int v56; // ebx@47
  int v57; // edx@47
  int v58; // ebx@47
  int v59; // edx@47
  int v60; // eax@50
  unsigned int v61; // edx@51
  char v62; // cl@51
  char v63; // ch@51
  int v64; // ebx@51
  int v65; // edi@51
  int v66; // esi@51
  unsigned int v67; // ebx@53
  int v68; // edx@53
  unsigned int v69; // ebx@53
  int v70; // edx@53
  unsigned int v71; // ebx@54
  int v72; // edx@54
  int v73; // ebx@54
  int v74; // edx@54
  int v75; // eax@58
  unsigned int v76; // edx@59
  char v77; // cl@59
  char v78; // ch@59
  int v79; // ebx@59
  int v80; // edi@59
  int v81; // esi@59
  int v82; // ebx@61
  int v83; // edx@61
  unsigned int v84; // ebx@62
  int v85; // edx@62
  int v86; // eax@65
  unsigned int v87; // edx@66
  char v88; // cl@66
  char v89; // ch@66
  int v90; // ebx@66
  int v91; // edi@66
  int v92; // esi@66
  int v93; // ebx@68
  int v94; // edx@68
  __int16 v95; // bx@69
  int v96; // edx@69
  int v97; // [sp+Ch] [bp-9Ch]@24
  int v98; // [sp+10h] [bp-98h]@24
  int v99; // [sp+14h] [bp-94h]@24
  int v100; // [sp+18h] [bp-90h]@24
  char *v101; // [sp+1Ch] [bp-8Ch]@40
  int v102; // [sp+20h] [bp-88h]@31
  int v103; // [sp+24h] [bp-84h]@3
  char *v104; // [sp+28h] [bp-80h]@24
  int v105; // [sp+2Ch] [bp-7Ch]@30
  int v106; // [sp+30h] [bp-78h]@24
  int v107; // [sp+34h] [bp-74h]@9
  int v108; // [sp+38h] [bp-70h]@8
  int v109; // [sp+3Ch] [bp-6Ch]@9
  int v110; // [sp+40h] [bp-68h]@24
  int v111; // [sp+44h] [bp-64h]@1
  int k; // [sp+48h] [bp-60h]@31
  int v113; // [sp+4Ch] [bp-5Ch]@35
  int v114; // [sp+50h] [bp-58h]@35
  int v115; // [sp+54h] [bp-54h]@42
  int v116; // [sp+58h] [bp-50h]@35
  int v117; // [sp+5Ch] [bp-4Ch]@33
  int v118; // [sp+60h] [bp-48h]@27
  int v119; // [sp+64h] [bp-44h]@17
  int v120; // [sp+68h] [bp-40h]@23
  unsigned int v121; // [sp+6Ch] [bp-3Ch]@40
  unsigned int v122; // [sp+70h] [bp-38h]@35
  char *v123; // [sp+74h] [bp-34h]@30
  int v124; // [sp+78h] [bp-30h]@17
  int v125; // [sp+7Ch] [bp-2Ch]@35
  unsigned int v126; // [sp+80h] [bp-28h]@9
  int v127; // [sp+84h] [bp-24h]@17
  int v128; // [sp+88h] [bp-20h]@9
  int v129; // [sp+8Ch] [bp-1Ch]@28
  int v130; // [sp+90h] [bp-18h]@16
  unsigned int v131; // [sp+94h] [bp-14h]@17
  int v132; // [sp+98h] [bp-10h]@28
  int v133; // [sp+9Ch] [bp-Ch]@17
  int v134; // [sp+A0h] [bp-8h]@17
  int v135; // [sp+A4h] [bp-4h]@24

  v1 = a1;
  v111 = pD3DRenderer->uTargetSurfacePitch;
  if ( a1 >= 0 )
  {
    if ( a1 < dword_6BE640 )
    {
      v3 = dword_6BE644 + 96 * a1;
      v103 = v3;
      v2 = *(_DWORD *)(v3 + 44);
      if ( !(BYTE1(v2) & 0x20) )
      {
        if ( v2 & 0x400000 )
        {
          sub_4ADD1D(a1);
          return;
        }
        if ( !(v2 & 0x10) || (sub_4AD504(a1), pD3DRenderer->pRendererD3D3) )
        {
          v4 = sub_4AE5BA(v3);
          ++dword_51B760;
          v5 = v4;
          v108 = v4;
          if ( v4 )
          {
            v7 = *(_WORD *)(v4 + 38);
            *(_BYTE *)(v3 + 44) |= 0x80u;
            v109 = v7;
            sub_4AE5F1(v1);
            v126 = dword_F8AD64;
            v128 = dword_F8AD68;
            v107 = (unsigned __int8)bUseLoResSprites;
            v6 = sub_423B5D(v1);
            if ( v6 )
            {
              if ( sub_424829(v6, (int)&dword_F8A590, dword_51B75C, v1) )
              {
                if ( *(_BYTE *)(v3 + 92) == 1 )
                {
                  for ( i = 0; i < dword_F8ADD4; *(int *)((char *)dword_F8AEC8 + v18) = v20 )
                  {
                    v18 = 4 * i;
                    v120 = dword_F8AE78[i];
                    v134 = (unsigned __int64)(v120 * -dword_F8AD30) >> 16;
                    v133 = dword_F8AD2C;
                    v120 = dword_F8AEC8[i];
                    v133 = (unsigned __int64)(v120 * dword_F8AD2C) >> 16;
                    v19 = v128;
                    dword_F8AE78[i] = v126 + v134 + ((unsigned __int64)(v120 * dword_F8AD2C) >> 16);
                    v20 = v19 - dword_F8AFB8[i++];
                  }
                }
                else
                {
                  if ( *(_BYTE *)(v3 + 92) != 3 )
                  {
                    if ( *(_BYTE *)(v3 + 92) == 4 )
                    {
LABEL_16:
                      v130 = 0;
                      if ( dword_F8ADD4 > 0 )
                      {
                        do
                        {
                          v8 = 4 * v130;
                          v9 = dword_F8AE78[v130];
                          v131 = dword_F8AEC8[v130];
                          v10 = dword_F8AFB8[v130];
                          v11 = (signed int)(v10 * dword_F8AD34 + dword_F8AD38 + v9 * dword_F8AD2C + v131 * dword_F8AD30) >> 16;
                          v119 = v9
                               - ((unsigned __int64)(dword_F8AD2C
                                                   * ((signed int)(v10 * dword_F8AD34
                                                                 + dword_F8AD38
                                                                 + v9 * dword_F8AD2C
                                                                 + v131 * dword_F8AD30) >> 16)) >> 16);
                          v131 -= (unsigned __int64)(dword_F8AD30 * v11) >> 16;
                          v127 = v10 - ((unsigned __int64)(dword_F8AD34 * v11) >> 16);
                          dword_F8AE78[v130] = ((unsigned __int64)(v119 * dword_F8AD3C) >> 16)
                                             + ((unsigned __int64)((signed int)v131 * dword_F8AD40) >> 16);
                          v124 = (unsigned __int64)(v119 * dword_F8AD48) >> 16;
                          v134 = (unsigned __int64)((signed int)v131 * dword_F8AD4C) >> 16;
                          v133 = (unsigned __int64)(v127 * dword_F8AD50) >> 16;
                          v12 = v126;
                          *(int *)((char *)dword_F8AEC8 + v8) = v124
                                                              + ((unsigned __int64)((signed int)v131 * dword_F8AD4C) >> 16)
                                                              + ((unsigned __int64)(v127 * dword_F8AD50) >> 16);
                          *(int *)((char *)dword_F8AE78 + v8) += v12;
                          *(int *)((char *)dword_F8AEC8 + v8) += v128;
                          ++v130;
                        }
                        while ( v130 < dword_F8ADD4 );
                        v3 = v103;
                      }
                      goto LABEL_24;
                    }
                    if ( *(_BYTE *)(v3 + 92) != 5 )
                    {
                      if ( *(_BYTE *)(v3 + 92) != 6 )
                        goto LABEL_24;
                      goto LABEL_16;
                    }
                  }
                  for ( j = 0; j < dword_F8ADD4; *(_DWORD *)v15 = v16 )
                  {
                    v14 = v128;
                    dword_F8AE78[j] += v126;
                    v15 = 4 * j + 16297672;
                    v16 = v14 - dword_F8AEC8[j++];
                  }
                }
LABEL_24:
                v135 = 1;
                Game_sub_44ED0A(pGame, v3, (int)&v135, 31);
                v104 = sub_47C24C(v3, v109, 0, 1);
                v134 = dword_F8AD6C;
                v106 = dword_F8AD70;
                v21 = dword_F8A590;
                v130 = dword_F8A590;
                v110 = v111 * dword_F8A590;
                v97 = *(_DWORD *)(v5 + 48);
                v98 = *(_DWORD *)(v5 + 52);
                v99 = *(_DWORD *)(v5 + 56);
                v23 = *(_DWORD *)(v5 + 60);
                v22 = 640 * dword_F8A590;
                v119 = 640 * dword_F8A590;
                v100 = v23;
                if ( dword_F8A590 <= dword_F8A594 )
                {
                  v24 = 2 * dword_F8A590;
                  v120 = 2 * dword_F8A590;
                  while ( 1 )
                  {
                    v118 = *(__int16 *)((char *)word_F8A5A8 + v24);
                    sub_4AE313(v118, v21, (int)&dword_F81018);
                    if (struct_576FE8.dword_000020)
                    {
                      v27 = v111 * (v24 - dword_51B738);
                      v129 = dword_51B748
                           + 4
                           * (2 * (*(__int16 *)((char *)word_F8A5A8 + v24) + 320 * (v24 - dword_51B738)) - dword_51B734);
                      v132 = dword_51B728 + 2 * (v27 + 2 * *(__int16 *)((char *)word_F8A5A8 + v24) - dword_51B734);
                      v25 = dword_51B728 + 2 * (v27 + 2 * *(__int16 *)((char *)word_F8A968 + v24) - dword_51B734);
                      v22 = v119;
                    }
                    else
                    {
                      v26 = *(__int16 *)((char *)word_F8A5A8 + v24);
                      v129 = dword_51B748 + 4 * (v26 + v22);
                      v132 = dword_51B728 + 2 * (v26 + v110);
                      v25 = dword_51B728 + 2 * (v110 + *(__int16 *)((char *)word_F8A968 + v24));
                    }
                    v131 = v25;
                    HIWORD(v28) = HIWORD(dword_F81018);
                    LOWORD(v28) = 0;
                    v105 = dword_F8AD28 | v28;
                    v123 = (char *)sub_4AE491(word_F8101E, word_F81022);
                    if ( v132 < v131 )
                    {
                      v102 = v107 + v106;
                      v29 = (int)&unk_F81054;
                      v118 += v134;
                      for ( k = (int)&unk_F81054; ; v29 = k )
                      {
                        sub_4AE313(v118, v130, v29 - 8);
                        v31 = *(_DWORD *)(v29 - 8);
                        LOWORD(v31) = 0;
                        v117 = v105;
                        v30 = dword_F8AD28 | v31;
                        if ( v105 <= (unsigned int)v30 )
                          v117 = v30;
                        v105 = v30;
                        v32 = *(_DWORD *)(v29 - 56);
                        v122 = *(_DWORD *)(v29 - 56) >> v107;
                        v33 = *(_DWORD *)(v29 - 52);
                        v125 = *(_DWORD *)(v29 - 52) >> v107;
                        v34 = *(_DWORD *)(v29 - 4) - v32;
                        v113 = (*(_DWORD *)v29 - v33) >> v102;
                        v35 = *(_DWORD *)(v29 - 44);
                        v114 = v34 >> v102;
                        v116 = *(&v97 + v35);
                        v36 = v35 + 16 - *(_WORD *)(v5 + 28);
                        v133 = v35 + 16;
                        v127 = v35 + v36;
                        v37 = (signed int)*(_WORD *)(v5 + 32) >> v35;
                        v38 = (signed int)*(_WORD *)(v5 + 34) >> v35 << (v35 + 16);
                        v128 = v37;
                        v126 = v38;
                        v39 = struct_576FE8.dword_000020 ? v132 + 4 * v134 : v132 + 2 * v134;
                        if ( v39 > v131 )
                          v39 = v131;
                        v41 = *(_WORD *)(v29 + 2);
                        v42 = *(_WORD *)(v29 - 2);
                        v121 = v39;
                        v40 = sub_4AE491(v42, v41);
                        v101 = (char *)v40;
                        v124 = (v39 - v132) >> 1;
                        if ( (signed int)v123 >> 16 == v40 >> 16 || v135 & 2 )
                        {
                          v123 = sub_47C24C(v103, v109, (signed int)v123 >> 16, 1);
                          if (struct_576FE8.dword_000020)
                          {
                            v86 = v132;
                            if ( v132 < v121 )
                            {
                              v92 = v129;
                              v91 = (int)v123;
                              v87 = v122;
                              v90 = v125;
                              v88 = v133;
                              v89 = v127;
                              if ( v124 & 2 )
                              {
                                *(_DWORD *)v129 = v117;
                                v92 -= 8;
                                v86 = v132 + 4;
                                goto LABEL_69;
                              }
                              do
                              {
                                v86 += 8;
                                v93 = *(_BYTE *)(v116 + (v128 & (v87 >> v88)) + ((v126 & v90) >> v89));
                                v94 = v117;
                                LOWORD(v93) = *(_WORD *)(v91 + 2 * v93);
                                *(_DWORD *)v92 = v117;
                                *(_DWORD *)(v92 + 4) = v94;
                                *(_DWORD *)(v92 + 2560) = v94;
                                *(_DWORD *)(v92 + 2564) = v94;
                                *(_WORD *)(v86 - 8) = v93;
                                *(_WORD *)(v86 - 6) = v93;
                                *(_WORD *)(v86 + 1272) = v93;
                                *(_WORD *)(v86 + 1274) = v93;
                                *(_DWORD *)(v92 + 8) = v94;
                                *(_DWORD *)(v92 + 12) = v94;
                                *(_DWORD *)(v92 + 2568) = v94;
                                *(_DWORD *)(v92 + 2572) = v94;
                                v122 += v114;
                                v125 += v113;
                                v87 = v122;
                                v90 = v125;
LABEL_69:
                                v92 += 16;
                                v95 = *(_WORD *)(v91
                                               + 2 * *(_BYTE *)(v116 + (v128 & (v87 >> v88)) + ((v126 & v90) >> v89)));
                                v96 = v114;
                                *(_WORD *)(v86 - 4) = v95;
                                *(_WORD *)(v86 - 2) = v95;
                                *(_WORD *)(v86 + 1276) = v95;
                                *(_WORD *)(v86 + 1278) = v95;
                                v122 += v96;
                                v125 += v113;
                                v87 = v122;
                                v90 = v125;
                              }
                              while ( v86 < v121 );
                              v132 = v86;
                              v129 = v92;
                            }
                          }
                          else
                          {
                            v75 = v132;
                            if ( v132 < v121 )
                            {
                              v81 = v129;
                              v80 = (int)v123;
                              v76 = v122;
                              v79 = v125;
                              v77 = v133;
                              v78 = v127;
                              if ( v124 & 1 )
                              {
                                *(_DWORD *)v129 = v117;
                                v81 -= 4;
                                v75 = v132 + 2;
                                goto LABEL_62;
                              }
                              do
                              {
                                v75 += 4;
                                v82 = *(_BYTE *)(v116 + (v128 & (v76 >> v77)) + ((v126 & v79) >> v78));
                                v83 = v117;
                                LOWORD(v82) = *(_WORD *)(v80 + 2 * v82);
                                *(_DWORD *)v81 = v117;
                                *(_WORD *)(v75 - 4) = v82;
                                *(_DWORD *)(v81 + 4) = v83;
                                v122 += v114;
                                v125 += v113;
                                v76 = v122;
                                v79 = v125;
LABEL_62:
                                v84 = v116 + (v128 & (v76 >> v77)) + ((v126 & v79) >> v78);
                                v81 += 8;
                                v85 = v114;
                                *(_WORD *)(v75 - 2) = *(_WORD *)(v80 + 2 * *(_BYTE *)v84);
                                v122 += v85;
                                v125 += v113;
                                v76 = v122;
                                v79 = v125;
                              }
                              while ( v75 < v121 );
                              v132 = v75;
                              v129 = v81;
                            }
                          }
                        }
                        else
                        {
                          v43 = (v40 - (_DWORD)v123) >> v106;
                          v44 = (int)&v123[-v43];
                          v123 = (char *)v43;
                          v115 = v44;
                          if (struct_576FE8.dword_000020)
                          {
                            v60 = v132;
                            if ( v132 < v121 )
                            {
                              v66 = v129;
                              v65 = (int)v104;
                              v61 = v122;
                              v64 = v125;
                              v62 = v133;
                              v63 = v127;
                              if ( v124 & 2 )
                              {
                                *(_DWORD *)v129 = v117;
                                v66 += 8;
                                v60 = v132 + 4;
                                goto LABEL_54;
                              }
                              do
                              {
                                v67 = (v128 & (v61 >> v62)) + ((v126 & v64) >> v63);
                                v68 = (int)&v123[v115];
                                v60 += 8;
                                v115 = v68;
                                v69 = ((v68 & 0xFFFF0000u) >> 8) + *(_BYTE *)(v116 + v67);
                                v70 = v117;
                                LOWORD(v69) = *(_WORD *)(v65 + 2 * v69);
                                *(_DWORD *)v66 = v117;
                                *(_DWORD *)(v66 + 4) = v70;
                                *(_DWORD *)(v66 + 2560) = v70;
                                *(_DWORD *)(v66 + 2564) = v70;
                                *(_WORD *)(v60 - 8) = v69;
                                *(_WORD *)(v60 - 6) = v69;
                                *(_WORD *)(v60 + 1272) = v69;
                                *(_WORD *)(v60 + 1274) = v69;
                                *(_DWORD *)(v66 + 8) = v70;
                                *(_DWORD *)(v66 + 12) = v70;
                                *(_DWORD *)(v66 + 2568) = v70;
                                *(_DWORD *)(v66 + 2572) = v70;
                                v122 += v114;
                                v125 += v113;
                                v61 = v122;
                                v64 = v125;
                                v66 += 16;
LABEL_54:
                                v71 = (v128 & (v61 >> v62)) + ((v126 & v64) >> v63);
                                v72 = (int)&v123[v115];
                                v73 = *(_BYTE *)(v116 + v71);
                                v115 = v72;
                                LOWORD(v73) = *(_WORD *)(v65 + 2 * (((v72 & 0xFFFF0000u) >> 8) + v73));
                                v74 = v114;
                                *(_WORD *)(v60 - 4) = v73;
                                *(_WORD *)(v60 - 2) = v73;
                                *(_WORD *)(v60 + 1276) = v73;
                                *(_WORD *)(v60 + 1278) = v73;
                                v122 += v74;
                                v125 += v113;
                                v61 = v122;
                                v64 = v125;
                              }
                              while ( v60 < v121 );
                              v132 = v60;
                              v129 = v66;
                            }
                          }
                          else
                          {
                            v45 = v132;
                            if ( v132 < v121 )
                            {
                              v51 = v129;
                              v50 = (int)v104;
                              v46 = v122;
                              v49 = v125;
                              v47 = v133;
                              v48 = v127;
                              if ( v124 & 1 )
                              {
                                *(_DWORD *)v129 = v117;
                                v51 += 4;
                                v45 = v132 + 2;
                                goto LABEL_47;
                              }
                              do
                              {
                                v52 = (v128 & (v46 >> v47)) + ((v126 & v49) >> v48);
                                v53 = (int)&v123[v115];
                                v45 += 4;
                                v115 = v53;
                                v54 = ((v53 & 0xFFFF0000u) >> 8) + *(_BYTE *)(v116 + v52);
                                v55 = v117;
                                LOWORD(v54) = *(_WORD *)(v50 + 2 * v54);
                                *(_DWORD *)v51 = v117;
                                *(_WORD *)(v45 - 4) = v54;
                                *(_DWORD *)(v51 + 4) = v55;
                                v122 += v114;
                                v125 += v113;
                                v46 = v122;
                                v49 = v125;
                                v51 += 8;
LABEL_47:
                                v56 = (v128 & (v46 >> v47)) + ((v126 & v49) >> v48);
                                v57 = (int)&v123[v115];
                                v58 = *(_BYTE *)(v116 + v56);
                                v115 = v57;
                                LOWORD(v58) = *(_WORD *)(v50 + 2 * (((v57 & 0xFFFF0000u) >> 8) + v58));
                                v59 = v114;
                                *(_WORD *)(v45 - 2) = v58;
                                v122 += v59;
                                v125 += v113;
                                v46 = v122;
                                v49 = v125;
                              }
                              while ( v45 < v121 );
                              v132 = v45;
                              v129 = v51;
                            }
                          }
                        }
                        k += 52;
                        v5 = v108;
                        v123 = v101;
                        v118 += v134;
                        if ( v132 >= v131 )
                          break;
                      }
                      v22 = v119;
                      v24 = v120;
                    }
                    ++v130;
                    v110 += v111;
                    v22 += 640;
                    v24 += 2;
                    v120 = v24;
                    v119 = v22;
                    if ( v130 > dword_F8A594 )
                      break;
                    v21 = v130;
                  }
                }
                return;
              }
            }
          }
        }
      }
    }
  }
}

//----- (004B0967) --------------------------------------------------------
void __cdecl sub_4B0967()
{
  int i; // edi@1
  int v1; // esi@2
  int v2; // eax@4
  int v3; // ecx@4
  int v4; // eax@6
  int v5; // edx@6
  int v6; // ecx@7
  int v7; // esi@8

  for ( i = 0; i < class37_global0.dword_000000; ++i )
  {
    v1 = word_51B77C[2 * i];
    if ( v1 >= 0 )
    {
      if ( v1 < dword_6BE640 )
      {
        v3 = word_51B77C[2 * i];
        dword_51B75C = (int)((char *)&unk_51C72C + 2252 * word_51B77E[2 * i]);
        v2 = sub_423B5D(v3);
        if ( v2 )
        {
          if ( sub_424829(v2, (int)&dword_F8A590, dword_51B75C, v1) )
          {
            v4 = dword_F8A590;
            v5 = dword_51B728;
            if ( dword_F8A590 <= dword_F8A594 )
            {
              v6 = 640 * dword_F8A590;
              do
              {
                *(_WORD *)(v5 + 2 * (v6 + word_F8A5A8[v4])) = -1;
                v7 = v6 + word_F8A968[v4];
                v6 += 640;
                *(_WORD *)(v5 + 2 * v7) = -1;
                ++v4;
              }
              while ( v4 <= dword_F8A594 );
            }
          }
        }
      }
    }
  }
}

//----- (004B0A25) --------------------------------------------------------
void __fastcall sub_4B0A25(int a1, int a2, int a3, int a4)
{
  int v4; // esi@1
  _UNKNOWN *v5; // eax@4
  signed int v6; // ecx@4
  _UNKNOWN *v7; // eax@8
  signed int v8; // ecx@8
  int v9; // esi@13
  void *v10; // edi@16
  int v11; // ebx@17
  _UNKNOWN *v12; // edx@18
  int v13; // ecx@18
  int v14; // eax@19
  unsigned __int8 v15; // sf@19
  unsigned __int8 v16; // of@19
  int v17; // ebx@25
  double v18; // st7@27
  double v19; // st6@27
  double v20; // st5@27
  char v21; // dl@27
  int v22; // eax@33
  int v23; // eax@35
  DWORD v24; // eax@37
  int v25; // eax@38
  _UNKNOWN *v26; // edi@38
  char v27; // zf@40
  signed int v28; // eax@42
  int v29; // [sp+Ch] [bp-1Ch]@15
  int i; // [sp+10h] [bp-18h]@38
  int v31; // [sp+14h] [bp-14h]@16
  void *v32; // [sp+18h] [bp-10h]@16
  int v33; // [sp+1Ch] [bp-Ch]@1
  int v34; // [sp+20h] [bp-8h]@1
  int v35; // [sp+24h] [bp-4h]@17
  signed int v36; // [sp+34h] [bp+Ch]@25
  int v37; // [sp+34h] [bp+Ch]@38

  v4 = a1;
  v33 = a2;
  v34 = a1;
  if ( a1 >= 0 )
  {
    if ( a1 < dword_6BE640 )
    {
      if ( !(byte_F7CE28 & 1) )
      {
        byte_F7CE28 |= 1u;
        v5 = &unk_F7C254;
        v6 = 64;
        do
        {
          *(float *)v5 = 0.0;
          v5 = (char *)v5 + 48;
          --v6;
        }
        while ( v6 );
        atexit(0);
      }
      if ( !(byte_F7CE28 & 2) )
      {
        byte_F7CE28 |= 2;
        v7 = &unk_F7B654;
        v8 = 64;
        do
        {
          *(float *)v7 = 0.0;
          v7 = (char *)v7 + 48;
          --v8;
        }
        while ( v8 );
        atexit(0);
      }
      if ( !(byte_F7CE28 & 4) )
      {
        byte_F7CE28 |= 4u;
        sub_49B001(&unk_F7B60C);
        compile_error;//atexit(loc_4B0DFB);
      }
      v9 = dword_6BE644 + 96 * v4;
      if ( *(_BYTE *)(v9 + 93) >= 3u )
      {
        if ( !(*(_BYTE *)(v9 + 45) & 0x20) )
        {
          ++dword_51B760;
          *(_BYTE *)(v9 + 44) |= 0x80u;
          v29 = sub_4AE5BA(v9);
          if ( v29 )
          {
            v10 = pGame->class08_obj;
            v32 = pGame->class08_obj;
            v31 = pGame->class04_obj;
            if ( !sub_436455(v9) )
            {
              v11 = 0;
              v35 = *(_BYTE *)(v9 + 93);
              if ( v35 > 0 )
              {
                v13 = dword_6BE63C;
                v12 = &unk_F7C230;
                do
                {
                  v14 = 2 * v11++;
                  *((float *)v12 - 2) = (double)*(_WORD *)(v13 + 6 * *(_WORD *)(*(_DWORD *)(v9 + 48) + v14));
                  *((float *)v12 - 1) = (double)*(_WORD *)(v13 + 6 * *(_WORD *)(*(_DWORD *)(v9 + 48) + v14) + 2);
                  *(float *)v12 = (double)*(_WORD *)(v13 + 6 * *(_WORD *)(*(_DWORD *)(v9 + 48) + v14) + 4);
                  v12 = (char *)v12 + 48;
                  compile_error;//v16 = __SETO__(v11, v35);
                  v15 = v11 - v35 < 0;
                  *((float *)v12 - 5) = (double)*(_WORD *)(v14 + *(_DWORD *)(v9 + 64));
                  *((float *)v12 - 4) = (double)*(_WORD *)(*(_DWORD *)(v9 + 68) + v14);
                }
                while ( v15 ^ v16 );
                v10 = v32;
              }
              if ( !v33 || (sub_498377(a4, 4, v33, (int)&unk_F7C228, (int)&v35), v35) )
              {
                if ( sub_437285((int)&unk_F7C228, (int)&v35, &unk_F7B628, (int)((char *)v10 + 52), 4, 0, 0) != 1 || v35 )
                {
                  v36 = SHIWORD(dword_F8AD54);
                  v17 = (248 - 8 * SHIWORD(dword_F8AD54)) | (((248 - 8 * SHIWORD(dword_F8AD54)) | ((248
                                                                                                  - 8 * SHIWORD(dword_F8AD54)) << 8)) << 8);
                  sub_4B0E07(v34);
                  sub_45C7F6(v34);
                  sub_49BBBD(pClass58_global, v34);
                  sub_4364C5((int)&unk_F7B628, v35, array_507D30, (int)&dword_F8AD28);
                  class08_sub_436BB7(v32, array_507D30, v35, 0);
                  *(_DWORD *)(v31 + 1587204) = 0;
                  if ( dword_F8ADD4 > 0 || dword_DF1BB4 > 0 )
                  {
                    v18 = *(float *)(v9 + 12);
                    v19 = *(float *)(v9 + 8);
                    v20 = *(float *)(v9 + 4);
                    v21 = *(_BYTE *)(v9 + 92);
                    flt_F7B610 = *(float *)v9;
                    byte_F7B620 = v21;
                    flt_F7B614 = v20;
                    flt_F7B618 = v19;
                    flt_F7B61C = v18;
                  }
                  if ( dword_F8ADD4 > 0 )
                  {
                    if ( !(*(_BYTE *)(v9 + 46) & 0x40) )
                      sub_45BC07(
                        (void *)v31,
                        (int)&dword_F8AD28,
                        (int)&unk_F7B60C,
                        v35,
                        array_507D30,
                        *(float *)&v33,
                        0);
                  }
                  if ( dword_DF1BB4 > 0 )
                    sub_49B540(
                      pClass58_global,
                      v36,
                      1,
                      (int)&unk_F7B60C,
                      v35,
                      array_507D30,
                      v33,
                      0.0,
                      *(_WORD *)(v9 + 76));
                  v22 = *(_DWORD *)(v9 + 44);
                  if ( *(_DWORD *)(v9 + 44) & 0x10 && *(_WORD *)(v9 + 74) == dword_EF5294 )
                  {
                    v23 = uTextureID_WaterTiles[dword_EF5290];
                    goto LABEL_42;
                  }
                  if ( *(_DWORD *)(v9 + 44) & 0x10 )
                  {
                    v24 = GetTickCount() >> 2;
                    if ( v35 > 0 )
                    {
                      v25 = v24 - pClass59_global->uNumTableEntries;
                      v26 = &array_507D30[0].v;
                      v37 = v35;
                      for ( i = v25; ; v25 = i )
                      {
                       compile_error;
                        //*(float *)v26 = (double)(pLODFile_Bitmaps_LOD->array_00024C[9 + 36 * *(_WORD *)(v9 + 74)] & (class59_class59_sub_402CAE(
                        //                                                                    pClass59_global,
                        //                                                                    v25) >> 8))
                        //              + *(float *)v26;
                        v26 = (char *)v26 + 48;
                        v27 = v37-- == 1;
                        if ( v27 )
                          break;
                      }
                    }
                  }
                  else
                  {
                    if ( BYTE1(v22) & 0x40 )
                    {
                      v23 = TextureFrameTable_GetFrame(pTextureFrameTable, *(_WORD *)(v9 + 74), dword_51B6E0);
LABEL_42:
                      v28 = *(_DWORD *)(pLODFile_Bitmaps_LOD->dword_011BB0 + 4 * v23);
                      if ( *(_BYTE *)(v9 + 46) & 0x40 )
                        sub_479A53(v35, v34);
                      else
                        sub_4A2FC0(pD3DRenderer, v35, v9, v28, v29, 8 * v34 | 6, v17, 0);
                      return;
                    }
                  }
                  v23 = *(_WORD *)(v9 + 74);
                  goto LABEL_42;
                }
              }
            }
          }
        }
      }
    }
  }
}

//----- (004B0E07) --------------------------------------------------------
unsigned int __fastcall sub_4B0E07(int a1)
{
  unsigned int result; // eax@1
  int v2; // ecx@1
  int v3; // edi@1
  int v4; // esi@1
  int v5; // ecx@1
  unsigned int v6; // eax@1
  int v7; // ecx@5

  v3 = dword_6BE644 + 96 * a1;
  v5 = dword_6BE64C + 36 * *(_WORD *)(v3 + 72);
  v4 = *(_WORD *)(v3 + 74) != -1 ? 72 * *(_WORD *)(v3 + 74) + 7278780 : 0;
  dword_F8AD64 = *(_WORD *)(v5 + 20);
  dword_F8AD68 = *(_WORD *)(v5 + 22);
  v6 = GetTickCount();
  v2 = *(_DWORD *)(v3 + 44);
  result = v6 >> 3;
  if ( v2 & 4 )
  {
    dword_F8AD68 -= result & *(_WORD *)(v4 + 34);
  }
  else
  {
    if ( v2 & 0x20 )
      dword_F8AD68 += result & *(_WORD *)(v4 + 34);
  }
  v7 = *(_DWORD *)(v3 + 44);
  if ( BYTE1(v7) & 8 )
  {
    dword_F8AD64 -= result & *(_WORD *)(v4 + 32);
  }
  else
  {
    if ( v7 & 0x40 )
      dword_F8AD64 += result & *(_WORD *)(v4 + 32);
  }
  return result;
}

//----- (004B0EA8) --------------------------------------------------------
char __thiscall sub_4B0EA8(int this, signed int a2, int a3)
{
  int v3; // eax@1
  int v4; // edx@1
  int v5; // ebx@1
  int v6; // ecx@2
  __int16 v7; // ax@11
  int v8; // edx@13
  int v9; // edx@15
  int v10; // esi@15
  signed int v11; // ecx@19
  signed int v12; // edi@19
  signed int v13; // esi@19
  signed int v14; // edx@20
  int v15; // edx@24
  int v16; // esi@29
  __int16 v17; // ax@34
  int v18; // edi@34
  _UNKNOWN *v19; // eax@38
  signed int v20; // ecx@38
  _UNKNOWN *v21; // eax@42
  signed int v22; // ecx@42
  signed int v23; // edx@45
  _UNKNOWN *v24; // ecx@46
  int v25; // eax@47
  int v26; // eax@47
  double v27; // st7@47
  signed int v28; // ST28_4@47
  int v29; // edx@48
  int v30; // eax@52
  __int16 v31; // cx@56
  signed int v33; // [sp+Ch] [bp-14h]@18
  int v34; // [sp+14h] [bp-Ch]@2
  void *v35; // [sp+14h] [bp-Ch]@36
  signed int v36; // [sp+18h] [bp-8h]@19
  void *v37; // [sp+18h] [bp-8h]@36
  int v38; // [sp+1Ch] [bp-4h]@1

  v4 = a3;
  v5 = this;
  v3 = dword_6BE644 + 96 * a3;
  *(_DWORD *)(2252 * *(_DWORD *)(this + 4004) + this + 5968) = -1;
  v38 = v3;
  if ( *(_BYTE *)(v3 + 44) & 1 )
  {
    v6 = this + 2252 * a2;
    v34 = v6;
    if ( v4 == *(_WORD *)(v6 + 5964) )
      return v3;
    if ( !a2
      && dword_51B6E8 >= *(_WORD *)(v3 + 80) - 16
      && dword_51B6E8 <= *(_WORD *)(v3 + 82) + 16
      && dword_51B6EC >= *(_WORD *)(v3 + 84) - 16
      && dword_51B6EC <= *(_WORD *)(v3 + 86) + 16
      && dword_51B6F0 >= *(_WORD *)(v3 + 88) - 16
      && dword_51B6F0 <= *(_WORD *)(v3 + 90) + 16 )
    {
      if ( abs(*(_DWORD *)(v3 + 28) + dword_51B6E8 * *(_DWORD *)(v3 + 16)
                                    + dword_51B6EC * *(_DWORD *)(v3 + 20)
                                    + dword_51B6F0 * *(_DWORD *)(v3 + 24)) <= 589824 )
      {
        v7 = *(_WORD *)(v38 + 76);
        if ( *(_WORD *)(v5 + 4008) == v7 )
          v7 = *(_WORD *)(v38 + 78);
        *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4008) = v7;
        *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 5964) = a3;
        *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4010) = dword_51B734;
        *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4014) = dword_51B73C;
        *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4012) = dword_51B738;
        *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4016) = dword_51B740;
        compile_error;//sub_43F9E1(2252 * *(_DWORD *)(v5 + 4004)++ + v5 + 4020, dword_51B734, dword_51B738, dword_51B73C, dword_51B740);
        LOBYTE(v3) = sub_440639(*(_DWORD *)(v5 + 4004) - 1, v8);
        return v3;
      }
      v3 = v38;
      v6 = v34;
    }
    v10 = dword_6BE63C + 6 * **(_WORD **)(v3 + 48);
    v9 = *(_DWORD *)(v3 + 16) * ((signed __int16)*(_DWORD *)v10 - dword_51B6E8)
       + *(_DWORD *)(v3 + 20) * ((signed __int16)(*(_DWORD *)v10 >> 16) - dword_51B6EC)
       + *(_DWORD *)(v3 + 24) * (*(_WORD *)(v10 + 4) - dword_51B6F0);
    if ( *(_WORD *)(v6 + 4008) != *(_WORD *)(v3 + 76) )
      v9 = -v9;
    if ( v9 < 0 )
    {
      v3 = sub_423B5D(a3);
      v33 = v3;
      if ( v3 )
      {
        v12 = dword_50BAC8[0];
        v11 = dword_50B9D8[0];
        a2 = dword_50BAC8[0];
        v13 = 1;
        v36 = dword_50B9D8[0];
        if ( v3 > 1 )
        {
          do
          {
            v14 = dword_50BAC8[v13];
            if ( v14 < a2 )
              a2 = dword_50BAC8[v13];
            if ( v14 > v12 )
              v12 = v14;
            v15 = dword_50B9D8[v13];
            if ( v15 < v36 )
              v36 = dword_50B9D8[v13];
            if ( v15 > v11 )
              v11 = dword_50B9D8[v13];
            v3 = v33;
            ++v13;
          }
          while ( v13 < v33 );
        }
        v16 = v34;
        if ( v12 >= *(_WORD *)(v34 + 4010) )
        {
          if ( a2 <= *(_WORD *)(v34 + 4014) )
          {
            if ( v11 >= *(_WORD *)(v34 + 4012) )
            {
              if ( v36 <= *(_WORD *)(v34 + 4016) )
              {
                v3 = sub_424829(v3, 2252 * *(_DWORD *)(v5 + 4004) + v5 + 4020, v34 + 4020, a3);
                if ( v3 )
                {
                  v18 = v38;
                  v17 = *(_WORD *)(v38 + 76);
                  if ( *(_WORD *)(v34 + 4008) == v17 )
                    v17 = *(_WORD *)(v38 + 78);
                  *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4008) = v17;
                  *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 5964) = a3;
                  *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4010) = dword_51B734;
                  *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4014) = dword_51B73C;
                  *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4012) = dword_51B738;
                  *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4016) = dword_51B740;
                  v37 = pGame->class10_obj;
                  v35 = pGame->class08_obj;
                  if ( *(_DWORD *)(v16 + 5968) == -1 )
                  {
                    LOBYTE(v3) = sub_49C681(
                                   pGame->class10_obj,
                                   v38,
                                   v5 + 2252 * *(_DWORD *)(v5 + 4004) + 5972,
                                   v5 + 2252 * *(_DWORD *)(v5 + 4004) + 6068);
                  }
                  else
                  {
                    if ( !(byte_F7B608 & 1) )
                    {
                      byte_F7B608 |= 1u;
                      v19 = &unk_F7AA34;
                      v20 = 64;
                      do
                      {
                        *(float *)v19 = 0.0;
                        v19 = (char *)v19 + 48;
                        --v20;
                      }
                      while ( v20 );
                      atexit(0);
                    }
                    if ( !(byte_F7B608 & 2) )
                    {
                      byte_F7B608 |= 2;
                      v21 = &unk_F79E34;
                      v22 = 64;
                      do
                      {
                        *(float *)v21 = 0.0;
                        v21 = (char *)v21 + 48;
                        --v22;
                      }
                      while ( v22 );
                      atexit(0);
                    }
                    v23 = 0;
                    a2 = *(_BYTE *)(v38 + 93);
                    if ( a2 > 0 )
                    {
                      v24 = &unk_F7AA10;
                      do
                      {
                        v25 = *(_WORD *)(*(_DWORD *)(v18 + 48) + 2 * v23++);
                        v26 = dword_6BE63C + 6 * v25;
                        v27 = (double)*(_WORD *)(v26 + 4);
                        v28 = *(_WORD *)(v26 + 2);
                        v18 = v38;
                        *((float *)v24 - 2) = (double)*(_WORD *)v26;
                        *((float *)v24 - 1) = (double)v28;
                        *(float *)v24 = v27;
                        v24 = (char *)v24 + 48;
                      }
                      while ( v23 < a2 );
                    }
                    sub_437285((int)&unk_F7AA08, (int)&a2, &unk_F79E08, v16 + 5972, 4, 0, 0);
                    LOBYTE(v3) = sub_49C5DA(
                                   v37,
                                   v18,
                                   (int)&unk_F79E08,
                                   &a2,
                                   v5 + 2252 * *(_DWORD *)(v5 + 4004) + 5972,
                                   v5 + 2252 * *(_DWORD *)(v5 + 4004) + 6068);
                  }
                  if ( (_BYTE)v3 )
                  {
                    *(_DWORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 5968) = a3;
                    v3 = *(_DWORD *)(v5 + 4004);
                    if ( v3 < 150 )
                    {
                      v30 = v3 + 1;
                      *(_DWORD *)(v5 + 4004) = v30;
                      LOBYTE(v3) = sub_440639(v30 - 1, v29);
                    }
                  }
                  if ( byte_51B6E4 & 1 )
                    LOBYTE(v3) = sub_437906(v35, v18, 1974015);
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
    v3 = *(_DWORD *)this;
    if ( *(_DWORD *)this < 1000 )
    {
      v31 = a2;
      *(_WORD *)(v5 + 4 * v3 + 4) = v4;
      v3 = *(_DWORD *)v5;
      *(_WORD *)(v5 + 4 * *(_DWORD *)v5++ + 6) = v31;
    }
  }
  return v3;
}

//----- (004B1447) --------------------------------------------------------
unsigned int __fastcall sub_4B1447(int a1, int a2, int a3)
{
  signed int v3; // esi@1
  char v4; // sf@8
  int v5; // eax@8
  __int64 v6; // qax@12
  _UNKNOWN *v7; // eax@14
  signed int v8; // edi@18
  unsigned int result; // eax@19
  int v10; // esi@20

  v3 = 0;
  if ( a2 )
  {
    if ( a2 != 1 )
    {
      if ( a2 == 2 )
        v3 = 2;
      goto LABEL_13;
    }
    v3 = 2;
  }
  else
  {
    v3 = 1;
  }
  if ( dword_AE31E0 < 4000000 )
  {
    v4 = a3 + dword_AE31E0 < 0;
    v5 = a3 + dword_AE31E0;
    dword_AE31E0 += a3;
    if ( v4 )
    {
      v5 = 0;
      dword_AE31E0 = 0;
    }
    if ( v5 > 4000000 )
      dword_AE31E0 = 4000000;
  }
  v6 = pParty_global->qword_00002C + 368640;
  pParty_global->array_000334[2 * a1] = pParty_global->qword_00002C + 368640;
  pParty_global->array_000334[2 * a1 + 1] = HIDWORD(v6);
LABEL_13:
  dword_AE310C[a1] = 1;
  if ( v3 )
  {
    v7 = &unk_6A12B8;
    if ( dword_6BE360 != 2 )
      v7 = &unk_6BE68C;
    *((_DWORD *)v7 + 2) += v3;
    if ( *((_DWORD *)v7 + 2) > 10000 )
      *((_DWORD *)v7 + 2) = 10000;
  }
  v8 = (signed int)pPlayers;
  do
  {
    result = *(_DWORD *)v8;
    if ( dword_AE31E0 )
    {
      v10 = result + 338;
      result = sub_449B57(result + 338, 1);
      if ( !(_WORD)result )
        result = sub_449B7E(v10, 1, 1);
    }
    v8 += 4;
  }
  while ( v8 <= (signed int)&dword_A750D4 );
  return result;
}

//----- (004B1523) --------------------------------------------------------
char *__thiscall sub_4B1523(void *this)
{
  int v1; // esi@1
  int v2; // edx@1
  int v3; // eax@2
  int v4; // eax@4
  int v5; // ecx@4
  int v6; // eax@10
  const char *v8; // ST44_4@12
  unsigned __int16 v9; // ax@12
  int v10; // [sp+Ch] [bp-68h]@4
  int v11; // [sp+10h] [bp-64h]@4
  int v12; // [sp+14h] [bp-60h]@4
  int v13; // [sp+18h] [bp-5Ch]@4
  int v14; // [sp+1Ch] [bp-58h]@4
  int v15; // [sp+20h] [bp-54h]@4
  int v16; // [sp+54h] [bp-20h]@4
  int v17; // [sp+60h] [bp-14h]@1
  char v18; // [sp+64h] [bp-10h]@1
  int v19; // [sp+68h] [bp-Ch]@4
  int v20; // [sp+6Ch] [bp-8h]@4
  int v21; // [sp+70h] [bp-4h]@4

  v1 = *(_DWORD *)this - 399;
  v2 = (*(_DWORD *)this - 400) % 11 + 1;
  v17 = 4 * (*(_DWORD *)this - 400) / 11;
  sprintfex(&TmpBuf, "%s%03d", *(wchar_t **)((char *)&off_4E1D18 + v17), v2);
  if ( *(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v18) + 4) <= 320 )
    v3 = *(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v18) + 4) + 30;
  else
    v3 = 30;
  v16 = 0;
  v11 = v3;
  v12 = 328;
  v13 = 68;
  v10 = 90;
  v14 = 417;
  v15 = v3 + 67;
  v19 = sub_44C51E(pFontSmallnum, pGlobalTXT_LocalizationStrings[431]);
  v21 = sub_44C51E(pFontSmallnum, pGlobalTXT_LocalizationStrings[433]);
  v20 = sub_44C51E(pFontSmallnum, pGlobalTXT_LocalizationStrings[432]);
  v4 = sub_44C51E(pFontSmallnum, pGlobalTXT_LocalizationStrings[96]);
  v5 = v19;
  if ( v21 > v19 )
    v5 = v21;
  if ( v20 > v5 )
    v5 = v20;
  if ( v4 > v5 )
    v5 = v4;
  sprintfex(
    pStringBuffer,
    "%s\n\n%s\t%03d:\t%03d%s\t000\n%s\t%03d:\t%03d%s\t000\n%s\t%03d:\t%03d%s\t000\n%s\t%03d:\t%03d%s",
    pSpellStats->pSpellInfos[v1 / 4].pSpellDescription,//*((_DWORD *)&unk_5CC038 + 9 * v1),
    pGlobalTXT_LocalizationStrings[431],
    v5 + 3,
    v5 + 10,
    pSpellStats->pSpellInfos[v1 / 4].pSpellBasicSkillDesc,//*((_DWORD *)&unk_5CC03C + 9 * v1),
    pGlobalTXT_LocalizationStrings[433],
    v5 + 3,
    v5 + 10,
    pSpellStats->pSpellInfos[v1 / 4].pSpellExpertSkillDesc,//*((_DWORD *)&unk_5CC040 + 9 * v1),
    pGlobalTXT_LocalizationStrings[432],
    v5 + 3,
    v5 + 10,
    pSpellStats->pSpellInfos[v1 / 4].pSpellMasterSkillDesc,//*((_DWORD *)&unk_5CC044 + 9 * v1),
    pGlobalTXT_LocalizationStrings[96],
    v5 + 3,
    v5 + 10,
    pSpellStats->pSpellInfos[v1 / 4].pSpellGrandmasterSkillDesc);//*((_DWORD *)&unk_5CC048 + 9 * v1));
  v6 = sub_44C59D(pFontSmallnum, pStringBuffer, (int)&v10, 0, 0);
  v13 += v6;
  if ( v13 < 150 )
    v13 = 150;
  v12 = 460;
  sub_415551((int)&v10, 0);
  v12 -= 12;
  v13 -= 12;

  //dword_5CC030 == pSpellStats
  compile_error;//v8 = (const char *)dword_5CC030[9 * v1];
  
  v14 = v10 + v12 - 1;
  v15 = v13 + v11 - 1;
  v9 = 0xFFFFFF9B;
  sub_44D406((int)&v10, pFontArrus, 120, 12, v9, v8, 3);
  FontDrawText((int)&v10, pFontSmallnum, 120, 44, pStringBuffer, 0, 0, 0);
  v14 = v10 + 107;
  v12 = 108;
  //sub_44D406((int)&v10, pFontComic, 12, 75, 0, (&dword_AE3300)[v17], 3);
  sub_44D406((int)&v10, pFontComic, 12, 75, 0, aSkillNames[12 + v17 / 4], 3);
  wsprintfA(TmpBuf, "%s\n%d", pGlobalTXT_LocalizationStrings[522], (unsigned __int16)word_4E3C68[10 * v1]);
  return sub_44D406((int)&v10, pFontComic, 12, v13 - *(_BYTE *)(pFontComic + 5) - 16, 0, &TmpBuf, 3);
}

//----- (004B1784) --------------------------------------------------------
signed int __cdecl sub_4B1784()
{
  int v0; // ebx@1
  signed int result; // eax@2
  unsigned __int16 v2; // ST0C_2@3
  int v3; // eax@3
  int v4; // [sp+4h] [bp-54h]@3
  int v5; // [sp+Ch] [bp-4Ch]@3
  int v6; // [sp+14h] [bp-44h]@3

  v0 = (int)*(&ptr_A750C4 + uActiveCharacter);
  if ( sub_492C0B((int)*(&ptr_A750C4 + uActiveCharacter)) )
  {
    *(_DWORD *)(dword_507BBC + 40) = dword_F8B1E0;
    result = 1;
  }
  else
  {
    *(_DWORD *)(dword_507BBC + 40) = 0;
    memcpy(&v4, pGUIWindow0, sizeof(struct GUIWindow));
    v4 = 483;
    v5 = 148;
    v6 = 334;
    sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[427], v0 + 168, pGlobalTXT_LocalizationStrings[562]);
    v2 = 0xFFFFFF9B;
    v3 = sub_44C59D(pFontArrus, &TmpBuf, (int)&v4, 0, 0);
    sub_44D406((int)&v4, pFontArrus, 0, (212 - v3) / 2 + 101, v2, &TmpBuf, 3);
    result = 0;
  }
  return result;
}

//----- (004B1854) --------------------------------------------------------
char *__thiscall sub_4B1854(void *this, __int64 a2)
{
  unsigned int v2; // ebx@1
  int v3; // ebp@1
  int v4; // ebx@1
  signed __int64 v5; // ST2C_8@1
  signed __int64 v6; // ST08_8@1
  signed __int64 v7; // qax@1
  int v8; // eax@2
  int v9; // eax@9
  int v10; // eax@15
  int v11; // eax@21
  unsigned __int16 v13; // ST0C_2@24
  int v14; // eax@24
  int v15; // [sp+0h] [bp-1Ch]@1
  int v16; // [sp+8h] [bp-14h]@1
  signed __int64 v17; // [sp+Ch] [bp-10h]@1
  signed __int64 v18; // [sp+14h] [bp-8h]@1
  unsigned int v19; // [sp+20h] [bp+4h]@1

  v15 = (int)this;
  v3 = (unsigned __int64)((signed __int64)((double)a2 * 0.234375) / 60) >> 32;
  v4 = (signed __int64)((double)a2 * 0.234375) / 60;
  v5 = (signed __int64)((double)a2 * 0.234375) / 60 / 60;
  v6 = (signed __int64)((double)a2 * 0.234375);
  v19 = (_DWORD)v5 / 0x18u;
  v7 = v6 % 60;
  HIDWORD(v6) = v3;
  LODWORD(v6) = v4;
  v18 = v7;
  v17 = v6 % 60;
  v2 = v5 % 24;
  v16 = (unsigned __int64)(v5 % 24) >> 32;
  strcpy(TmpBuf, pGlobalTXT_LocalizationStrings[532]);
  if ( (_DWORD)v5 / 0x18u )
  {
    v8 = pGlobalTXT_LocalizationStrings[57];
    if ( v19 <= 1 )
      v8 = pGlobalTXT_LocalizationStrings[56];
    sprintfex(pStringBuffer, "%d %s ", v19, v8);
    strcat(TmpBuf, pStringBuffer);
  }
  if ( v16 | v2 )
  {
    if ( v16 < 0 || v16 <= 0 && v2 <= 1 )
      v9 = pGlobalTXT_LocalizationStrings[109];
    else
      v9 = pGlobalTXT_LocalizationStrings[110];
    sprintfex(pStringBuffer, "%d %s ", v2, v9);
    strcat(TmpBuf, pStringBuffer);
  }
  if ( v17 )
  {
    if ( !v19 )
    {
      if ( v17 <= 1 )
        v10 = pGlobalTXT_LocalizationStrings[437];
      else
        v10 = pGlobalTXT_LocalizationStrings[436];
      sprintfex(pStringBuffer, "%d %s ", v17, v10);
      strcat(TmpBuf, pStringBuffer);
    }
  }
  if ( v18 )
  {
    if ( !(v16 | v2) )
    {
      if ( v18 <= 1 )
        v11 = pGlobalTXT_LocalizationStrings[439];
      else
        v11 = pGlobalTXT_LocalizationStrings[438];
      sprintfex(pStringBuffer, "%d %s ", v18, v11);
      strcat(TmpBuf, pStringBuffer);
    }
  }
  v13 = 0xFFFFFF9B;
  v14 = sub_44C59D(pFontArrus, &TmpBuf, v15, 0, 0);
  return sub_44D406(v15, pFontArrus, 0, (212 - v14) / 2 + 101, v13, &TmpBuf, 3);
}

//----- (004B1A2D) --------------------------------------------------------
void __cdecl sub_4B1A2D()
{
  void *v0; // edi@1
  int v1; // ecx@5
  int v2; // esi@5
  int v3; // eax@5
  char v4; // zf@5
  int v5; // eax@12
  int v6; // esi@12
  int v7; // eax@13
  int v8; // ecx@13
  signed int v9; // esi@17
  int v10; // eax@19
  char v11; // [sp+8h] [bp-44h]@12
  char v12; // [sp+10h] [bp-3Ch]@12
  char v13; // [sp+18h] [bp-34h]@18
  char v14; // [sp+20h] [bp-2Ch]@17
  char v15; // [sp+28h] [bp-24h]@17
  char v16; // [sp+30h] [bp-1Ch]@17
  char v17; // [sp+38h] [bp-14h]@5
  char v18; // [sp+40h] [bp-Ch]@5
  int v19; // [sp+48h] [bp-4h]@5

  v0 = *(&ptr_A750C4 + uActiveCharacter);
  if ( dword_F8B198 > 0 )
  {
    if ( dword_F8B198 > 4 )
    {
      if ( dword_F8B198 <= 16 )
      {
        if ( dword_F8B19C == 18 )
        {
          v2 = class03_GetMousePos(pGame->pClass03, (int)&v18);
          v3 = *(_DWORD *)v2 + dword_5059A8[*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v17) + 4)];
          v1 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * v3) & 0xFFFF;
          v4 = (*(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * v3) & 0xFFFF) == 0;
          v19 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * v3) & 0xFFFF;
          if ( !v4 )
            sub_4B1523((void *)(36 * (v1 + 12 * *(_DWORD *)(dword_507BC0 + 28)) + 11341664));
        }
      }
      return;
    }
    if ( dword_F8B19C == 2 )
      goto LABEL_12;
    if ( dword_F8B19C <= 2 )
      return;
    if ( dword_F8B19C > 5 && dword_F8B19C != 94 )
    {
      if ( dword_F8B19C != 95 )
        return;
LABEL_12:
      v6 = class03_GetMousePos(pGame->pClass03, (int)&v12);
      v5 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer
                     + 4 * (*(_DWORD *)v6 + dword_5059A8[*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v11) + 4)])) & 0xFFFF;
      v19 = v5;
      if ( !v5 )
        return;
      v7 = 9 * (v5 + 12 * *(_DWORD *)(dword_507BC0 + 28));
      v8 = 4 * v7 + 11355920;
      if ( dword_F8B19C != 2 )
        v8 = 4 * v7 + 11378816;
      goto LABEL_15;
    }
    v9 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v16) - 14;
    v19 = (v9 >> 5) + 14 * ((*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v15) + 4) - 17) >> 5);
    if ( *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v14) > 13 )
    {
      if ( *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v13) < 462 )
      {
        v10 = sub_421E75(v0, (int)&v19);
        if ( v10 )
        {
          v8 = (int)((char *)v0 + 36 * v10 + 496);
LABEL_15:
          sub_41D895((void *)v8);
          return;
        }
      }
    }
  }
}

//----- (004B1BDB) --------------------------------------------------------
void __stdcall sub_4B1BDB(__int64 a1)
{
  void *v1; // ebx@1
  signed __int64 v2; // ST2C_8@1
  signed __int64 v3; // ST1C_8@1
  unsigned int v4; // ebx@1

  pParty_global->HiredNPC[0].dword_000044 = 0;
  pParty_global->HiredNPC[1].dword_000044 = 0;
  pParty_global->qword_00002C += (signed __int64)((double)(7680 * a1) * 0.03333333507180214);
  v2 = (signed __int64)((double)pParty_global->qword_00002C * 0.234375);
  v3 = v2 / 60 / 60;
  v4 = (_DWORD)v3 / 0x18u / 0x1C;
  pParty_global->uCurrentYear = v4 / 0xC + 1168;
  pParty_global->uCurrentMonth = v4 % 0xC;
  pParty_global->uCurrentMonthWeek = (_DWORD)v3 / 0x18u / 7 & 3;
  pParty_global->uDaysPlayed = (_DWORD)v3 / 0x18u % 0x1C;
  pParty_global->uCurrentHour = v3 % 24;
  pParty_global->uCurrentMinute = v2 / 60 % 60;
  pParty_global->dword_000724 = v2 % 60;
  sub_490D02(pParty_global);
  dword_507B94 = 1;

  //v1 = &unk_ACF4BC;
  v1 = &pParty_global->pPlayers[0].dword_001B38;
  do
  {
    *((_WORD *)v1 - 258) = 0;
    memset(v1, 0, 4u);
    v1 = (char *)v1 + 6972;
  }
  while ( (signed int)v1 < (signed int)&unk_AD61AC );
  sub_4909F4(pParty_global);
}

//----- (004B1D27) --------------------------------------------------------
void __cdecl sub_4B1D27()
{
  int v0; // edx@2
  int v1; // ecx@7
  int v2; // eax@8
  signed int v3; // edi@12
  int v4; // esi@12
  __int16 v5; // ax@17
  signed int v6; // edi@22
  int v7; // esi@22
  int v8[4]; // [sp+Ch] [bp-10h]@14

  if ( dword_F8B198 > 0 )
  {
    v0 = 3;
    if ( dword_F8B198 > 3 )
    {
      if ( dword_F8B198 == 22 )
      {
        if ( !dword_F8B1E4 )
          return;
      }
      else
      {
        if ( dword_F8B198 != 23 )
          return;
      }
      v1 = *(_DWORD *)(dword_507BC0 + 28);
LABEL_30:
      sub_4B1E92(v1, v0);
      return;
    }
    v1 = *(_DWORD *)(dword_507BC0 + 28);
    v2 = pParty_global->array_000334[2 * v1 + 1];
    if ( v2 < HIDWORD(pParty_global->qword_00002C)
      || v2 <= HIDWORD(pParty_global->qword_00002C) && (unsigned int)pParty_global->array_000334[2 * v1] <= (_DWORD)pParty_global->qword_00002C )
    {
      if ( (unsigned int)pParty_global->uNumGold <= 0x2710 )
      {
        if ( !dword_F8B1E4 )
          return;
        v0 = 4;
        goto LABEL_30;
      }
      sub_4B1E92(v1, dword_F8B1E4 + 3);
      if ( !dword_F8B1E4 )
      {
        if ( !qword_A750D8 )
        {
          v6 = 0;
          v7 = 1;
          do
          {
            if ( sub_492C0B((int)*(&ptr_A750C4 + v7)) )
              v8[v6++] = v7;
            ++v7;
          }
          while ( v7 <= 4 );
          if ( v6 )
          {
            qword_A750D8 = 256i64;
            word_A750E0 = 80;
            v5 = LOWORD(v8[rand() % v6]);
            goto LABEL_18;
          }
        }
      }
    }
    else
    {
      if ( !qword_A750D8 )
      {
        v3 = 0;
        v4 = 1;
        do
        {
          if ( sub_492C0B((int)*(&ptr_A750C4 + v4)) )
            v8[v3++] = v4;
          ++v4;
        }
        while ( v4 <= 4 );
        if ( v3 )
        {
          qword_A750D8 = 256i64;
          word_A750E0 = 80;
          v5 = LOWORD(v8[rand() % v3]);
LABEL_18:
          word_A750E2 = v5;
          return;
        }
      }
    }
  }
}

//----- (004B1E92) --------------------------------------------------------
void __fastcall sub_4B1E92(int a1, int a2)
{
  if ( byte_4E5F7D[16 * word_59143A[26 * a1]] )
    AudioPlayer_sub_4AA306(
      pAudioPlayer,
      a2 + 100 * ((unsigned __int8)byte_4E5F7D[16 * word_59143A[26 * a1]] + 300),
      806,
      0,
      -1,
      0,
      0,
      0,
      0);
}

//----- (004B1ECE) --------------------------------------------------------
void __cdecl sub_4B1ECE()
{
  signed int v0; // edi@1
  int v1; // ebx@3
  int v3; // eax@4
  signed int v4; // eax@9
  int v5; // ebx@11
  signed int v6; // esi@13
  signed int v7; // eax@14
  signed int v8; // edi@14
  int v9; // [sp+Ch] [bp-Ch]@11
  signed int v10; // [sp+10h] [bp-8h]@13
  int v11; // [sp+14h] [bp-4h]@1
  signed int v12; // [sp+14h] [bp-4h]@11
 int i;

  dword_F8B1A8 = 0;
  v11 = 0;
  dword_59108C = 84;
  dword_F8B1E8 = (char *)dword_722B44;
  v0 = (signed int)&off_4F0882;
  while ( 1 )
  {
    if ( (unsigned __int16)sub_449B57((int)byte_ACD71D, *(_WORD *)(v0 - 2)) )
    {
      v1 = 0;
      for (i = 0; i < 4; ++i)
      {
        LOBYTE(v3) = sub_449BB4(&pParty_global->pPlayers[i], 17, (void *)*(_WORD *)v0);
        if ( v3 )
          break;
        ++v1;
      }

      if ( v1 == 4 )
        break;
    }
    ++v11;
    v0 += 4;
    if ( v0 >= (signed int)((char *)dword_4F08EC + 2) )
      goto LABEL_10;
  }
  dword_F8B1E8 = (char *)dword_722B3C;
  v4 = *((_WORD *)&off_4F0882 + 2 * v11);
  dword_F8B1A8 = *((_WORD *)&off_4F0882 + 2 * v11);
  sub_44AFFB((char *)&pParty_global->pPlayers[0], 17, v4);
LABEL_10:
  if ( dword_F8B1A8 == 601 )
  {
    v5 = 0;
    v12 = &pParty_global->pPlayers[0].uClass;
    v9 = 0;
    while ( 1 )
    {
      if ( *(_BYTE *)v12 == 35 )
      {
        v10 = 0;
        v6 = (signed int)&unk_ACDBB2;
        do
        {
          v7 = v6;
          v8 = 138;
          do
          {
            if ( *(_DWORD *)(v7 - 26) == 601 )
            {
              if ( !*(_BYTE *)v7 )
                v9 = v7 - 26;
              if ( *(_BYTE *)v7 == v5 )
                v10 = 1;
            }
            v7 += 36;
            --v8;
          }
          while ( v8 );
          v6 += 6972;
        }
        while ( v6 < (signed int)&unk_AD48A2 );
        if ( !v10 )
          break;
      }
      v12 += 6972;
      ++v5;
      if ( v12 >= (signed int)&unk_AD472D )
        return;
    }
    if ( v9 )
      *(_BYTE *)(v9 + 26) = v5;
  }
}

//----- (004B2001) --------------------------------------------------------
int __fastcall sub_4B2001(int this)
{
  int v1; // eax@1
  int v2; // ebp@1
  int v3; // ecx@8
  char *v4; // esi@20
  signed int v5; // eax@28
  signed int v6; // eax@31
  signed int v7; // eax@34
  signed int v8; // eax@37
  signed int v9; // eax@40
  signed int v10; // eax@43
  int v11; // eax@48
  void *v12; // eax@53
  void *v13; // eax@56
  void *v14; // eax@57
  void *v15; // eax@58
  int v16; // ebp@62
  char *v17; // ecx@63
  char *v18; // eax@65
  const char *v19; // ecx@68
  int v20; // eax@69
  unsigned int v21; // ecx@70
  char *v23; // [sp-Ch] [bp-18h]@73
  int v24; // [sp-8h] [bp-14h]@49
  const char *v25; // [sp-8h] [bp-14h]@73
  int v26; // [sp-4h] [bp-10h]@49
 int i;

  v1 = this;
  dword_59108C = this + 1;
  v2 = dword_5913D8[dword_5913F0 - ((dword_591080 != 0) + 1)];
  if ( this <= 23 )
  {
    if ( this == 23 )
    {
      v3 = *(_DWORD *)(v2 + 56);
    }
    else
    {
      if ( this == 13 )
      {
        dword_F8B1E8 = (char *)(&dword_737C34)[20 * *(_DWORD *)(v2 + 24)];
        dword_F8B1E8 = (char *)sub_495461(dword_F8B1E8, uActiveCharacter - 1, 0, 0, 0, 0);
        sub_4B40E6();
        byte_F8B1EC = 0;
        return sub_4BF5B2(pVideoPlayer);
      }
      switch ( this )
      {
        case 19:
          v3 = *(_DWORD *)(v2 + 40);
          break;
        case 20:
          v3 = *(_DWORD *)(v2 + 44);
          break;
        case 21:
          v3 = *(_DWORD *)(v2 + 48);
          break;
        default:
          if ( this != 22 )
            return sub_4BF5B2(pVideoPlayer);
          v3 = *(_DWORD *)(v2 + 52);
          break;
      }
    }
    goto LABEL_84;
  }
  if ( this == 24 )
  {
    v3 = *(_DWORD *)(v2 + 60);
LABEL_84:
    if ( v3 < 200 || v3 > 310 )
    {
      if ( v3 < 400 || v3 > 410 )
      {
        if ( v3 == 139 )
        {
          sub_4B1ECE();
        }
        else
        {
          if ( v3 == 311 )
          {
            sub_4BBA85();
          }
          else
          {
            dword_F8B1E8 = 0;
            dword_5C3420 = 1;
            sub_44684A_LooksLikeEventProcessor(v3, 0, 1);
            dword_5C3420 = 0;
          }
        }
      }
      else
      {
        dword_F8B1D8 = v1;
        sub_4B3EF0(v3 - 400);
      }
    }
    else
    {
      sub_4B3FE5((void *)v3);
    }
    return sub_4BF5B2(pVideoPlayer);
  }
  if ( this != 76 )
  {
    switch ( this )
    {
      case 77:
        v16 = *(_DWORD *)(v2 + 24);
        if ( byte_F8B1EC )
          v17 = (char *)(&dword_737C34)[20 * v16];
        else
          v17 = (char *)(&dword_737C2C)[20 * v16];
        dword_F8B1E8 = v17;
        v18 = (char *)sub_495461(v17, uActiveCharacter - 1, 0, 0, 0, 0);
        byte_F8B1EC ^= 1u;
        dword_F8B1E8 = v18;
        break;
      case 79:
        if ( dword_F8B1A8 )
        {
          sub_492BB6(dword_F8B1B4);
          if ( uActiveCharacter )
          {
            v12 = *((char **)(&ptr_A750C4) + uActiveCharacter) + 2 * dword_F8B1AC + 264;
            *(_WORD *)v12 &= 0x3Fu;
            switch ( dword_F8B1B0 )
            {
              case 2:
                v15 = *((char **)(&ptr_A750C4) + uActiveCharacter) + 2 * dword_F8B1AC + 264;
                *(_BYTE *)v15 |= 0x40u;
                break;
              case 3:
                v14 = *((char **)(&ptr_A750C4) + uActiveCharacter) + 2 * dword_F8B1AC + 264;
                *(_BYTE *)v14 |= 0x80u;
                break;
              case 4:
                v13 = *((char **)(&ptr_A750C4) + uActiveCharacter) + 2 * dword_F8B1AC + 264;
                *((_BYTE *)v13 + 1) |= 1u;
                break;
            }
            sub_4948B1(*(&ptr_A750C4 + uActiveCharacter), 85, 0);
          }
          if ( dword_50CBD0[0] < 40 )
          {
            dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
            dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
            dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
          }
        }
        break;
      case 82:
        if ( dword_F8B1A8 )
        {
          sub_492BB6(dword_F8B1B4);

          for (i = 0; i < 4; ++i)
            sub_44A5CB(&pParty_global->pPlayers[i], 12, dword_F8B1AC);


          switch ( dword_F8B1D8 )
          {
            case 19:
              v10 = *(_DWORD *)(v2 + 40);
              if ( v10 >= 400 )
              {
                if ( v10 <= 416 )
                  *(_DWORD *)(v2 + 40) = 0;
              }
              break;
            case 20:
              v9 = *(_DWORD *)(v2 + 44);
              if ( v9 >= 400 )
              {
                if ( v9 <= 416 )
                  *(_DWORD *)(v2 + 44) = 0;
              }
              break;
            case 21:
              v8 = *(_DWORD *)(v2 + 48);
              if ( v8 >= 400 )
              {
                if ( v8 <= 416 )
                  *(_DWORD *)(v2 + 48) = 0;
              }
              break;
            case 22:
              v7 = *(_DWORD *)(v2 + 52);
              if ( v7 >= 400 )
              {
                if ( v7 <= 416 )
                  *(_DWORD *)(v2 + 52) = 0;
              }
              break;
            case 23:
              v6 = *(_DWORD *)(v2 + 56);
              if ( v6 >= 400 )
              {
                if ( v6 <= 416 )
                  *(_DWORD *)(v2 + 56) = 0;
              }
              break;
            case 24:
              v5 = *(_DWORD *)(v2 + 60);
              if ( v5 >= 400 )
              {
                if ( v5 <= 416 )
                  *(_DWORD *)(v2 + 60) = 0;
              }
              break;
          }
          if ( dword_50CBD0[0] < 40 )
          {
            dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
            dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
            dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
          }
          v11 = uActiveCharacter;
          if ( uActiveCharacter )
          {
            v26 = 0;
            v24 = 86;
LABEL_50:
            sub_4948B1(*(&ptr_A750C4 + v11), v24, v26);
            return sub_4BF5B2(pVideoPlayer);
          }
        }
        break;
    }
    return sub_4BF5B2(pVideoPlayer);
  }
  if (pParty_global->HiredNPC[0].pNPCName && pParty_global->HiredNPC[1].pNPCName)
  {
    v19 = pGlobalTXT_LocalizationStrings[533];
LABEL_77:
    sub_44C175(v19, 2);
    return sub_4BF5B2(pVideoPlayer);
  }
  v20 = *(_DWORD *)(v2 + 24);
  if ( v20 != 51 )
  {
    v21 = dword_737C28[5 * v20];
    if ( pParty_global->uNumGold < v21 )
    {
      sub_44C175(pGlobalTXT_LocalizationStrings[155], 2);
      byte_F8B1EC = 0;
      dword_59108C = 13;
      dword_F8B1E8 = (char *)(&dword_737C34)[20 * *(_DWORD *)(v2 + 24)];
      dword_F8B1E8 = (char *)sub_495461(dword_F8B1E8, uActiveCharacter - 1, 0, 0, 0, 0);
      if ( uActiveCharacter )
        sub_4948B1(*(&ptr_A750C4 + uActiveCharacter), 38, 0);
      v19 = pGlobalTXT_LocalizationStrings[155];
      goto LABEL_77;
    }
    sub_492BB6(v21);
  }
  *(_BYTE *)(v2 + 8) |= 0x80u;
  pParty_global->byte_000709 = 0;
  sub_44A56A();
  if (pParty_global->HiredNPC[0].pNPCName)
  {
    memcpy(&pParty_global->HiredNPC[1], v2, sizeof(struct NPCData));
    v25 = *(const char **)v2;
    v23 = (char *)&unk_AE3090;
  }
  else
  {
    memcpy(&pParty_global->HiredNPC[0], v2, sizeof(struct NPCData));
    v25 = *(const char **)v2;
    v23 = byte_AE302C;
  }
  strcpy(v23, v25);
  pParty_global->byte_000709 = 0;
  sub_44A56A();
  sub_44606A(*(_DWORD *)(dword_507BC0 + 28));
  dword_F8B19C = 1;
  if ( dword_50CBD0[0] < 40 )
  {
    dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
    dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
    dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
  }
  v11 = uActiveCharacter;
  if ( uActiveCharacter )
  {
    v26 = 0;
    v24 = 61;
    goto LABEL_50;
  }
  return sub_4BF5B2(pVideoPlayer);
}

//----- (004B254D) --------------------------------------------------------
const CHAR *__thiscall sub_4B254D(void *this)
{
  int v1; // eax@1
  int v2; // ecx@1
  int v3; // edi@1
  int v4; // esi@1
  signed __int64 v5; // qtt@1
  int v6; // eax@2
  int v7; // eax@7
  int v8; // ebx@7
  int v9; // eax@7
  int v10; // eax@8
  char *v11; // ecx@8
  int v12; // ebx@8
  signed int v13; // esi@8
  char *v14; // edx@9
  int v15; // edi@9
  signed int v16; // edi@10
  signed int v18; // eax@29
  int v19; // eax@36
  char v20; // cl@46
  __int16 v21; // dx@56
  int v22; // eax@60
  int v23; // [sp-Ch] [bp-38h]@82
  int v24; // [sp-8h] [bp-34h]@21
  int v25; // [sp-8h] [bp-34h]@38
  char *v26; // [sp-8h] [bp-34h]@82
  int v27; // [sp-4h] [bp-30h]@14
  int v28; // [sp-4h] [bp-30h]@38
  int v29; // [sp-4h] [bp-30h]@82
  char v30[4]; // [sp+Ch] [bp-20h]@9
  int v31; // [sp+10h] [bp-1Ch]@13
  int v32; // [sp+14h] [bp-18h]@15
  int v33; // [sp+18h] [bp-14h]@16
  int v34; // [sp+1Ch] [bp-10h]@7
  int v35; // [sp+20h] [bp-Ch]@7
  int v36; // [sp+24h] [bp-8h]@7
  int v37; // [sp+28h] [bp-4h]@1

  v4 = (int)*(&ptr_A750C4 + uActiveCharacter);
  dword_F8B1A8 = 0;
  v5 = (signed int)((char *)this - 200);
  v2 = (signed int)((char *)this - 200) / 3;
  v3 = v5 % 3;
  v37 = dword_721A64;
  v1 = v5 % 3;
  dword_F8B1AC = v2;
  if ( v1 )
  {
    v6 = v1 - 1;
    if ( v6 )
    {
      if ( v6 == 1 )
      {
        dword_F8B1B4 = 8000;
        dword_F8B1B0 = 4;
      }
    }
    else
    {
      dword_F8B1B4 = 5000;
      dword_F8B1B0 = 3;
    }
  }
  else
  {
    dword_F8B1B4 = 2000;
    dword_F8B1B0 = 2;
  }
  v7 = *(_BYTE *)(v4 + 185);
  v35 = v7;
  v9 = (unsigned __int8)*(&byte_4ED970[37 * v7] + v2);
  v34 = *(_WORD *)(v4 + 2 * v2 + 264);
  v8 = v34 & 0x3F;
  v36 = v3 + 2;
  if ( v9 < v3 + 2 )
  {
    v12 = v35;
    v13 = 0;
    v10 = v35 - v35 % 4;
    v11 = &byte_4ED970[37 * (v35 - v35 % 4)] + v2;
    do
    {
      v15 = (unsigned __int8)*v11;
      v14 = &v30[4 * v13];
      *(_DWORD *)v14 = 0;
      if ( v15 < v36 )
      {
        v16 = 1;
      }
      else
      {
        v16 = 1;
        *(_DWORD *)v14 = 1;
      }
      ++v13;
      v11 += 37;
    }
    while ( v13 < 4 );
    if ( v31 == v16 )
    {
      v27 = aClassNames[1 + v10];
    }
    else
    {
      if ( v32 == v16 )
      {
        if ( v33 == v16 )
        {
          sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[634], aClassNames[2 + v10], aClassNames[3 + v10]);
          return &TmpBuf;
        }
        v27 = aClassNames[2 + v10];
      }
      else
      {
        if ( v33 != v16 )
        {
          v27 = (int)(aClassNames[v12]);
          v24 = pGlobalTXT_LocalizationStrings[632];
          goto LABEL_23;
        }
        v27 = aClassNames[3 + v10];
      }
    }
    v24 = pGlobalTXT_LocalizationStrings[633];
LABEL_23:
    sprintfex(&TmpBuf, (const char *)v24, v27);
    return &TmpBuf;
  }
  if ( !sub_492C0B(v4) )
    return dword_721A3C;
  if ( !v8 )
    return (const CHAR *)dword_721A84;
  v18 = sub_458244(v34);
  if ( v18 > v3 + 1 )
    return (const CHAR *)dword_721A6C[2 * v3];
  if ( v36 != 2 )
  {
    if ( v36 == 3 )
    {
      if ( v18 >= 2 && v8 >= 7 )
      {
        v19 = dword_F8B1AC;
        switch ( dword_F8B1AC )
        {
          default:
            goto LABEL_41;
          case 12:
          case 13:
          case 14:
          case 15:
          case 16:
          case 17:
          case 18:
            dword_F8B1B4 = 4000;
            goto LABEL_42;
          case 19:
            v21 = 114;
            goto LABEL_57;
          case 20:
            v21 = 110;
LABEL_57:
            if ( !(unsigned __int16)sub_449B57((int)byte_ACD71D, v21) )
              return (const CHAR *)v37;
            goto LABEL_40;
          case 22:
            v22 = Player_GetBaseWillpower(v4);
            goto LABEL_61;
          case 24:
            dword_F8B1B4 = 2500;
            v22 = Player_GetBaseEndurance(v4);
            goto LABEL_61;
          case 36:
            v22 = Player_GetBaseIntelligence(v4);
LABEL_61:
            if ( v22 < 50 )
              return (const CHAR *)v37;
            goto LABEL_40;
          case 21:
          case 23:
          case 25:
          case 26:
          case 29:
          case 32:
          case 34:
          case 35:
            dword_F8B1B4 = 2500;
            goto LABEL_42;
          case 8:
          case 9:
          case 10:
          case 11:
            dword_F8B1B4 = 3000;
            goto LABEL_42;
          case 7:
            goto LABEL_67;
        }
        goto LABEL_67;
      }
    }
    else
    {
      if ( v36 != 4 )
      {
LABEL_40:
        v19 = dword_F8B1AC;
        goto LABEL_41;
      }
      if ( v18 >= 3 && v8 >= 10 )
      {
        v19 = dword_F8B1AC;
        switch ( dword_F8B1AC )
        {
          case 19:
            if ( sub_49327B(v4, 34, 1) == 1 )
              goto LABEL_40;
            v28 = 1;
            v25 = 26;
            goto LABEL_39;
          default:
            goto LABEL_41;
          case 20:
            if ( sub_49327B(v4, 35, 1) == 1 )
              goto LABEL_40;
            v28 = 1;
            v25 = 27;
LABEL_39:
            if ( sub_49327B(v4, v25, v28) == 1 )
              goto LABEL_40;
            return (const CHAR *)v37;
          case 30:
            v20 = *(_BYTE *)(v4 + 326);
            goto LABEL_47;
          case 31:
            v20 = *(_BYTE *)(v4 + 324);
LABEL_47:
            if ( (v20 & 0x3Fu) < 0xA )
              return (const CHAR *)v37;
            goto LABEL_41;
          case 21:
          case 23:
          case 24:
          case 25:
          case 26:
          case 29:
          case 32:
          case 34:
          case 35:
            dword_F8B1B4 = 6000;
            goto LABEL_42;
          case 8:
          case 9:
          case 10:
          case 11:
            dword_F8B1B4 = 7000;
            goto LABEL_42;
          case 7:
            break;
        }
LABEL_67:
        dword_F8B1B4 = 0;
        goto LABEL_41;
      }
    }
    return (const CHAR *)v37;
  }
  if ( v8 < 4 )
    return (const CHAR *)v37;
  v19 = dword_F8B1AC;
  if ( dword_F8B1AC > 27 )
  {
    if ( dword_F8B1AC != 29 && dword_F8B1AC != 32 && (dword_F8B1AC <= 33 || dword_F8B1AC > 35) )
    {
LABEL_41:
      if ( !dword_F8B1B4 )
        goto LABEL_79;
      goto LABEL_42;
    }
LABEL_87:
    dword_F8B1B4 = 500;
    goto LABEL_41;
  }
  if ( dword_F8B1AC >= 23 )
    goto LABEL_87;
  if ( dword_F8B1AC == 7 )
  {
    dword_F8B1B4 = 0;
    goto LABEL_79;
  }
  if ( dword_F8B1AC <= 7 )
    goto LABEL_41;
  if ( dword_F8B1AC > 18 )
  {
    if ( dword_F8B1AC != 21 )
      goto LABEL_41;
    goto LABEL_87;
  }
  dword_F8B1B4 = 1000;
LABEL_42:
  if ( dword_F8B1B4 > (unsigned int)pParty_global->uNumGold )
    return (const CHAR *)dword_721A4C;
LABEL_79:
  dword_F8B1A8 = 1;
  if ( v36 == 2 )
  {
    v29 = dword_F8B1B4;
    //v26 = (&dword_AE32D0)[4 * v19];
    v26 = aSkillNames[v19];
    v23 = pGlobalTXT_LocalizationStrings[433];
    goto LABEL_90;
  }
  if ( v36 == 3 )
  {
    v29 = dword_F8B1B4;
    //v26 = (&dword_AE32D0)[4 * v19];
    v26 = aSkillNames[v19];
    v23 = pGlobalTXT_LocalizationStrings[432];
    goto LABEL_90;
  }
  if ( v36 == 4 )
  {
    v29 = dword_F8B1B4;
    //v26 = (&dword_AE32D0)[4 * v19];
    v26 = aSkillNames[v19];
    v23 = pGlobalTXT_LocalizationStrings[225];
LABEL_90:
    sprintfex(pStringBuffer, pGlobalTXT_LocalizationStrings[534], v23, v26, v29);
  }
  return pStringBuffer;
}

//----- (004B29F2) --------------------------------------------------------
int __fastcall sub_4B29F2(int a1)
{
  int v1; // edi@1
  int v2; // esi@1
  int v3; // eax@1
  int v4; // ecx@1
  int result; // eax@2

  v2 = a1;
  dword_F8B1A8 = 0;
  v1 = (int)*(&ptr_A750C4 + uActiveCharacter);
  v3 = a1 + 50;
  v4 = (int)*(&ptr_A750C4 + uActiveCharacter);
  dword_F8B1AC = v3;
  dword_F8B1B4 = dword_4F08EC[v2];
  if ( sub_492C0B(v4) )
  {
    if ( (unsigned __int16)sub_449B57(v1 + 338, dword_F8B1AC) )
    {
      result = dword_721A44;
    }
    else
    {
      if ( dword_F8B1B4 <= (unsigned int)pParty_global->uNumGold )
      {
        result = dword_7219DC[2 * v2];
        dword_F8B1A8 = 1;
      }
      else
      {
        result = dword_721A4C;
      }
    }
  }
  else
  {
    result = (int)dword_721A3C;
  }
  return result;
}

//----- (004B2A74) --------------------------------------------------------
char __cdecl sub_4B2A74()
{
  const char *v0; // eax@3
  int v1; // esi@3
  const char *v2; // ST1C_4@3
  int i; // eax@5
  const char *v4; // ST1C_4@5
  int v5; // eax@5
  int v6; // eax@6
  unsigned __int16 v7; // bx@6
  int v8; // esi@6
  int v9; // eax@11
  int v10; // ecx@12
  int v11; // eax@12
  int v12; // esi@12
  char *v13; // eax@12
  int v14; // ebx@13
  const char *v15; // esi@14
  int v16; // eax@15
  signed int v17; // ecx@15
  int v18; // ecx@17
  int v19; // ecx@18
  int v20; // ecx@19
  int v21; // ecx@20
  int v22; // ecx@21
  int v23; // ecx@23
  int v24; // ecx@35
  int v25; // ecx@36
  int v26; // ecx@37
  int v27; // ecx@38
  int v28; // ecx@39
  int *v29; // esi@42
  unsigned int v30; // ST20_4@42
  int v31; // ST1C_4@42
  unsigned int v32; // eax@42
  const CHAR *v33; // eax@43
  int v34; // edi@51
  int v35; // esi@51
  int v36; // eax@52
  signed int v37; // ecx@54
  int v38; // edi@57
  unsigned __int16 v39; // ax@60
  int v40; // ecx@60
  const char *v41; // ebx@60
  int v42; // eax@60
  int v43; // esi@60
  int v44; // eax@60
  int v45; // ebx@64
  int v46; // esi@64
  char *v47; // eax@66
  char v49; // [sp+Ch] [bp-110h]@64
  int v50; // [sp+14h] [bp-108h]@64
  int v51; // [sp+1Ch] [bp-100h]@64
  int v52; // [sp+60h] [bp-BCh]@13
  int v53; // [sp+68h] [bp-B4h]@13
  int v54; // [sp+70h] [bp-ACh]@13
  int v55; // [sp+7Ch] [bp-A0h]@43
  int v56; // [sp+88h] [bp-94h]@13
  int v57; // [sp+98h] [bp-84h]@13
  int v58; // [sp+B4h] [bp-68h]@1
  int v59; // [sp+BCh] [bp-60h]@3
  int v60; // [sp+C4h] [bp-58h]@3
  unsigned int v61; // [sp+108h] [bp-14h]@14
  __int16 v62[2]; // [sp+10Ch] [bp-10h]@6
  int v63; // [sp+110h] [bp-Ch]@13
  int v64; // [sp+114h] [bp-8h]@12
  int v65; // [sp+118h] [bp-4h]@6

  memcpy(&v58, (const void *)dword_507BBC, 0x54u);
  if ( dword_5913F0 == dword_591424 && dword_5C35D0 )
  {
   v1 = pMapStats->pMapInfos[dword_5C35D0].pLocationName;
   v2 = (const char *)pMapStats->pMapInfos[dword_5C35D0].pLocationName;
    v58 = 493;
    v59 = 126;
    v60 = 366;
    sub_44D406((int)&v58, pFontCreate, 0, 2, 0, v2, 3);
    v58 = 483;
    v59 = 148;
    v60 = 334;
    v0 = (&off_4EB080)[4 * dword_5C35D0];
    if ( !v0 )
    {
      sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[411], v1);
      v0 = &TmpBuf;
    }
    v4 = v0;
    v5 = sub_44C59D(pFontCreate, v0, (int)&v58, 0, 0);
    LOBYTE(i) = (unsigned int)sub_44D406((int)&v58, pFontCreate, 0, (212 - v5) / 2 + 101, 0, v4, 3);
    return i;
  }
  v59 -= 10;
  v60 -= 10;
  v65 = dword_5913D8[dword_5913F0 - ((dword_591080 != 0) + 1)];
  v8 = v65;
  *(_DWORD *)v62 = 0xFFE1CD23;
  v7 = 0xFF1599E9;
  v6 = *(_DWORD *)(v8 + 24);
  if ( v6 )
    //sprintfex(&TmpBuf, (const char *)dword_5E4834, *(_DWORD *)v8, dword_73C290[v6]);
    sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[429], *(_DWORD *)v8, aNPCProfessionNames[v6]);
  else
    strcpy((char *)&TmpBuf, *(const char **)v8);
  sub_44D406((int)&v58, pFontCreate, 483, 113, v7, &TmpBuf, 3);
  if ( !dword_591080 )
  {
    if ( !dword_59108C )
    {
      v9 = *(_DWORD *)(v8 + 28);
      if ( v9 )
      {
        v10 = *(_DWORD *)(v8 + 8);
        v59 = 460;
        v60 = 452;
        v64 = dword_73BA54[((v10 & 3) == 2) + 2 * v9];
        v11 = sub_44C59D(pFontArrus, (const char *)v64, (int)&v58, 13, 0);
        v12 = v11 + 7;
        sub_4A6A68(
          pD3DRenderer,
          8,
          352 - (v11 + 7),
          uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 : 0,
          *(_WORD *)(uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 + 0x1A : 26) - (v11 + 7));
        Render_DrawIndexedTexture(pD3DRenderer, 8, 347 - v12, pClass18_EndcapTexture);
        v13 = FitTextInAWindow((const char *)v64, pFontArrus, (int)&v58, 13, 0);
        FontDrawText(dword_507BBC, pFontArrus, 13, 354 - v12, v13, 0, 0, 0);
      }
    }
  }
  v14 = dword_507BBC;
  memcpy(&v52, (const void *)dword_507BBC, 0x54u);
  v52 = 483;
  v53 = 148;
  v54 = 334;
  v63 = v57;
  if ( v57 < v57 + v56 )
  {
    v15 = (const char *)v61;
    while ( 1 )
    {
      v16 = GUIWindow_GetChild((int)&v52, v63);
      v17 = *(_DWORD *)(v16 + 36);
      v64 = v16;
      if ( v17 > 24 )
      {
        v24 = v17 - 76;
        if ( !v24 )
        {
          v15 = pGlobalTXT_LocalizationStrings[406];
          goto LABEL_49;
        }
        v25 = v24 - 1;
        if ( !v25 )
        {
          v15 = pGlobalTXT_LocalizationStrings[407];
          goto LABEL_49;
        }
        v26 = v25 - 2;
        if ( !v26 )
        {
          v33 = sub_4B254D((void *)v55);
LABEL_44:
          v15 = v33;
LABEL_45:
          v16 = v64;
          goto LABEL_49;
        }
        v27 = v26 - 3;
        if ( !v27 )
        {
          v33 = (const CHAR *)sub_4B29F2(v55);
          goto LABEL_44;
        }
        v28 = v27 - 1;
        if ( !v28 )
        {
          v29 = &pMonsterStats->pMonsterInfos[word_F8B1A0];
          v30 = 0xFFFFFFFF;
          v31 = *v29;
          v32 = 0xFFFFFF9B;
          sprintfex(TmpBuf, (const char *)&unk_4F0F98, v32, v31, v30);
          sprintfex(pStringBuffer, (const char *)dword_F8B1A4, TmpBuf, 100 * *((_BYTE *)v29 + 8));
          dword_F8B1E8 = pStringBuffer;
          v15 = Class;
          goto LABEL_45;
        }
        if ( v28 != 10 )
          goto LABEL_41;
      }
      else
      {
        if ( v17 == 24 )
        {
          v23 = *(_DWORD *)(v65 + 60);
LABEL_33:
          v15 = (&dword_721660)[8 * v23];
          if ( !v15 )
          {
            *(_DWORD *)(v16 + 36) = 0;
            v15 = Class;
          }
          goto LABEL_49;
        }
        v18 = v17 - 13;
        if ( v18 )
        {
          v19 = v18 - 6;
          if ( !v19 )
          {
            v23 = *(_DWORD *)(v65 + 40);
            goto LABEL_33;
          }
          v20 = v19 - 1;
          if ( !v20 )
          {
            v15 = (&dword_721660)[8 * *(_DWORD *)(v65 + 44)];
            if ( !v15 )
            {
              *(_DWORD *)(v16 + 36) = 0;
              v15 = Class;
            }
            if ( dword_59108C != 84 )
              goto LABEL_49;
            sprintfex(TmpBuf, (const char *)&unk_4E2D80, *(_DWORD *)v62, dword_5D29EC[12 * dword_F8B1A8]);
            sprintfex(pStringBuffer, dword_F8B1E8, TmpBuf);
            dword_F8B1E8 = pStringBuffer;
            goto LABEL_45;
          }
          v21 = v20 - 1;
          if ( !v21 )
          {
            v23 = *(_DWORD *)(v65 + 48);
            goto LABEL_33;
          }
          v22 = v21 - 1;
          if ( !v22 )
          {
            v23 = *(_DWORD *)(v65 + 52);
            goto LABEL_33;
          }
          if ( v22 == 1 )
          {
            v23 = *(_DWORD *)(v65 + 56);
            goto LABEL_33;
          }
LABEL_41:
          v15 = Class;
          goto LABEL_49;
        }
        v15 = pGlobalTXT_LocalizationStrings[122];
      }
LABEL_49:
      strcpy((char *)(v16 + 85), v15);
      ++v63;
      if ( v63 >= v57 + v56 )
      {
        v14 = dword_507BBC;
        break;
      }
    }
  }
  v35 = 0;
  v61 = 0xFFFFFFFF;
  v34 = *(_DWORD *)(v14 + 56);
  *(_DWORD *)v62 = 0xFFE1CD23;
  for ( i = v34 + *(_DWORD *)(v14 + 40); v34 < i; i = *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56) )
  {
    v36 = GUIWindow_GetChild(v14, v34);
    v14 = dword_507BBC;
    v35 += sub_44C59D(pFontArrus, (const char *)(v36 + 85), (int)&v52, 0, 0);
    ++v34;
  }
  v37 = *(_DWORD *)(v14 + 40);
  if ( v37 )
  {
    v65 = (174 - v35) / v37;
    if ( v65 > 32 )
      v65 = 32;
    v64 = 2;
    v38 = (174 - v65 * v37 - v35) / 2 - v65 / 2 + 138;
    v63 = *(_DWORD *)(v14 + 56);
    i = v63;
    if ( i < i + v37 )
    {
      while ( 1 )
      {
        v42 = GUIWindow_GetChild(v14, i);
        v43 = v42;
        v41 = (const char *)(v42 + 85);
        *(_DWORD *)(v42 + 4) = v65 + v38;
        v44 = sub_44C59D(pFontArrus, (const char *)(v42 + 85), (int)&v52, 0, 0);
        v40 = *(_DWORD *)(v43 + 4);
        *(_DWORD *)(v43 + 12) = v44;
        v38 = v40 + v44 - 1;
        *(_DWORD *)(v43 + 20) = v38;
        v39 = v62[0];
        if ( *(_DWORD *)(dword_507BBC + 44) != v64 )
          v39 = v61;
        sub_44D406((int)&v52, pFontArrus, 0, v40, v39, v41, 3);
        v14 = dword_507BBC;
        ++v64;
        ++v63;
        i = *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56);
        if ( v63 >= i )
          break;
        i = v63;
      }
    }
  }
  if ( dword_F8B1E8 )
  {
    v50 = 458;
    v51 = 457;
    v45 = pFontArrus;
    v46 = sub_44C59D(pFontArrus, dword_F8B1E8, (int)&v49, 13, 0) + 7;
    if ( 352 - v46 < 8 )
    {
      v45 = pFontCreate;
      v46 = sub_44C59D(pFontCreate, dword_F8B1E8, (int)&v49, 13, 0) + 7;
    }
    sub_4A6A68(
      pD3DRenderer,
      8,
      352 - v46,
      uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 : 0,
      *(_WORD *)(uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 + 0x1A : 26) - v46);
    Render_DrawIndexedTexture(pD3DRenderer, 8, 347 - v46, pClass18_EndcapTexture);
    v47 = FitTextInAWindow(dword_F8B1E8, v45, (int)&v49, 13, 0);
    FontDrawText((int)&v58, v45, 13, 354 - v46, v47, 0, 0, 0);
  }
  return i;
}

//----- (004B3157) --------------------------------------------------------
void __thiscall sub_4B3157(const void *this)
{
  unsigned __int16 v1; // di@2
  const char *v2; // edx@4
  signed int v3; // edx@5
  int v4; // edi@9
  int v5; // eax@45
  int v6; // edi@45
  char *v7; // eax@45
  int v8; // edi@46
  int v9; // eax@50
  int v10; // [sp-10h] [bp-C8h]@53
  unsigned __int16 v11; // [sp-Ch] [bp-C4h]@53
  int v12; // [sp-Ch] [bp-C4h]@60
  int v13; // [sp-8h] [bp-C0h]@50
  int v14; // [sp-8h] [bp-C0h]@60
  int v15; // [sp-4h] [bp-BCh]@50
  int v16; // [sp-4h] [bp-BCh]@60
  char v17; // [sp+Ch] [bp-ACh]@5
  int v18; // [sp+14h] [bp-A4h]@4
  int v19; // [sp+18h] [bp-A0h]@4
  int v20; // [sp+1Ch] [bp-9Ch]@45
  char v21; // [sp+60h] [bp-58h]@2
  int v22; // [sp+68h] [bp-50h]@2
  int v23; // [sp+70h] [bp-48h]@2
  __int16 v24[2]; // [sp+B4h] [bp-4h]@2

  if ( dword_507BC0 )
  {
    memcpy(&v21, this, 0x54u);
    v22 -= 18;
    v23 -= 18;
    v1 = 0xFFFFFFFF;
    *(_DWORD *)v24 = 0xFF1599E9;
    Render_DrawIndexedTexture(pD3DRenderer, 477, 0, dword_591430);
    Render_DrawTransparentTexture(pD3DRenderer, 468, 0, dword_507B04 != -1 ? 72 * dword_507B04 + 7145548 : 0);
    if ( dword_5913F0 != dword_591424 || !dword_5C35D0 )
    {
      v18 = 130;
      v19 = 2 * *(_BYTE *)(pFontCreate + 5);
      v2 = (const char *)dword_59143C[13 * *(_DWORD *)(dword_507BC0 + 28)];
      if ( v2 )
      {
        v3 = 2 * *(_BYTE *)(pFontCreate + 5) - 6 - sub_44C59D(pFontCreate, v2, (int)&v17, 0, 0);
        if ( v3 < 0 )
          v3 = 0;
        sub_44D406(
          (int)&v21,
          pFontCreate,
          490,
          v3 / 2 + 4,
          v1,
          (const char *)dword_59143C[13 * *(_DWORD *)(dword_507BC0 + 28)],
          3);
      }
    }
    v22 += 8;
    v23 += 8;
    if ( dword_5913F0 )
    {
      v4 = dword_5913F0 - 1;
      Render_DrawIndexedTexture(
        pD3DRenderer,
        dword_4E5E50 - 4,
        dword_4E5EE0 - 4,
        dword_50795C != -1 ? 72 * dword_50795C + 7145548 : 0);
      Render_DrawIndexedTexture(pD3DRenderer, dword_4E5E50, dword_4E5EE0, dword_59140C[v4]);
      if ( dword_4E28F8 == 14 )
      {
        GameUI_DrawInventory(uActiveCharacter, 1);
        goto LABEL_58;
      }
      if ( v4 || !dword_591080 )
      {
        sub_4B2A74();
      }
      else
      {
        sprintfex(
          &TmpBuf,
          pGlobalTXT_LocalizationStrings[429],
          dword_591440[13 * *(_DWORD *)(dword_507BC0 + 28)],
          dword_591448[13 * *(_DWORD *)(dword_507BC0 + 28)]);
        sub_44D406((int)&v21, pFontCreate, 483, 113, v24[0], &TmpBuf, 3);
        if ( dword_F8B198 <= 18 )
        {
          switch ( dword_F8B198 )
          {
            case 18:
              sub_4B6478();
              break;
            case 1:
              sub_4B910F();
              break;
            case 2:
              sub_4BA928();
              break;
            case 3:
              sub_4B4FCF();
              break;
            case 4:
              sub_4B9CC6();
              break;
            default:
              if ( dword_F8B198 > 4 )
              {
                if ( dword_F8B198 <= 16 )
                {
                  sub_4B5D7C();
                }
                else
                {
                  if ( dword_F8B198 == 17 )
                    sub_4B7911();
                }
              }
              break;
          }
          goto LABEL_58;
        }
        switch ( dword_F8B198 )
        {
          case 21:
            sub_4B8285();
            break;
          case 22:
            sub_4B7D7E();
            break;
          case 23:
            sub_4B705E();
            break;
          default:
            if ( dword_F8B198 <= 26 )
              break;
            if ( dword_F8B198 <= 28 )
            {
              sub_4B6943();
            }
            else
            {
              if ( dword_F8B198 != 30 )
              {
                if ( dword_F8B198 != 31 )
                  break;
                goto LABEL_36;
              }
              sub_4B4710();
            }
            break;
        }
      }
LABEL_58:
      if ( dword_5913F0 == dword_591424 && dword_5C35D0 )
      {
        Render_DrawIndexedTexture(pD3DRenderer, 556, 451, uTextureIdx_BtnXxU != -1 ? 72 * uTextureIdx_BtnXxU + 7145548 : 0);
        v16 = uTextureIdx_BtnXokU != -1 ? 72 * uTextureIdx_BtnXokU + 7145548 : 0;
        v14 = 451;
        v12 = 476;
      }
      else
      {
        v16 = dword_506438 != -1 ? 72 * dword_506438 + 7145548 : 0;
        v14 = 445;
        v12 = 471;
      }
      Render_DrawIndexedTexture(pD3DRenderer, v12, v14, v16);
      return;
    }
    if ( dword_F8B198 == 31 )
    {
LABEL_36:
      sub_4B4F4F();
      goto LABEL_58;
    }
    if ( dword_F8B1E8 )
    {
      v18 = 458;
      v20 = 457;
      v5 = sub_44C59D(pFontArrus, dword_F8B1E8, (int)&v17, 13, 0);
      v6 = v5 + 7;
      sub_4A6A68(
        pD3DRenderer,
        8,
        352 - (v5 + 7),
        uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 : 0,
        *(_WORD *)(uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 + 0x1A : 26) - (v5 + 7));
      Render_DrawIndexedTexture(pD3DRenderer, 8, 347 - v6, pClass18_EndcapTexture);
      v7 = FitTextInAWindow(dword_F8B1E8, pFontArrus, (int)&v17, 13, 0);
      FontDrawText(dword_507BC0, pFontArrus, 13, 354 - v6, v7, 0, 0, 0);
    }
    v8 = 0;
    if ( dword_591424 <= 0 )
      goto LABEL_58;
    while ( 1 )
    {
      Render_DrawIndexedTexture(
        pD3DRenderer,
        *(&dword_4E5E50 + v8 + 6 * dword_591424 - 6) - 4,
        *(&dword_4E5EE0 + v8 + 6 * dword_591424 - 6) - 4,
        dword_50795C != -1 ? 72 * dword_50795C + 7145548 : 0);
      Render_DrawIndexedTexture(
        pD3DRenderer,
        *(&dword_4E5E50 + v8 + 6 * dword_591424 - 6),
        *(&dword_4E5EE0 + v8 + 6 * dword_591424 - 6),
        dword_59140C[v8]);
      if ( dword_591424 < 4 )
        break;
LABEL_57:
      ++v8;
      if ( v8 >= dword_591424 )
        goto LABEL_58;
    }
    if ( v8 + 1 == dword_591424 && dword_5C35D0 )
    {
      v15 = 3;
      v13 = pMapStats->pMapInfos[dword_5C35D0].pLocationName;
      v9 = 94 * v8 + 113;
    }
    else
    {
      if ( !v8 && dword_591080 )
      {
        v15 = 3;
        v13 = dword_591448[13 * *(_DWORD *)(dword_507BC0 + 28)];
        v11 = v24[0];
        v10 = 113;
LABEL_56:
        sub_44D406((int)&v21, pFontCreate, 483, v10, v11, (const char *)v13, v15);
        goto LABEL_57;
      }
      v15 = 3;
      v13 = *(_DWORD *)dword_5913D8[v8 - (dword_591080 != 0)];
      v9 = dword_4E5EC8[v8 + 6 * dword_591424] + *(_WORD *)(dword_59140C[v8] + 26) + 2;
    }
    v11 = v24[0];
    v10 = v9;
    goto LABEL_56;
  }
}

//----- (004B36CC) --------------------------------------------------------
int __fastcall sub_4B36CC(int a1, int a2)
{
  return GUIButtonCreate(dword_507BBC, 480, 30 * a1 + 146, 140, 30, 1, 0, 405, a2, 0, Class, 0);
}

//----- (004B3703) --------------------------------------------------------
int __thiscall sub_4B3703(void *this)
{
  int v1; // eax@1
  int v2; // ecx@1
  signed int v3; // ebx@1
  signed int v4; // edi@1
  int v5; // ecx@2
  int v6; // ecx@3
  int v7; // ecx@4
  int v8; // ecx@5
  int v9; // ecx@6
  signed int v10; // ebx@13
  signed int v11; // edi@14
  signed int v12; // esi@15
  int v13; // ecx@16
  int v14; // ecx@16
  int v15; // ecx@17
  int v16; // ecx@19
  int v17; // ecx@20
  int v18; // ecx@21
  signed int v19; // esi@32
  int v20; // ecx@33
  int v21; // ecx@34
  int v22; // ecx@36
  int v23; // ecx@37
  int v24; // ecx@38
  int v25; // ecx@39
  int v26; // ecx@40
  int v27; // ecx@41
  int *v28; // esi@54
  int v29; // edx@56
  int v30; // ecx@65
  int v31; // ecx@106
  int result; // eax@107
  int v33; // [sp-4h] [bp-2Ch]@23
  int v34; // [sp-4h] [bp-2Ch]@43
  int v35; // [sp+Ch] [bp-1Ch]@8
  int v36; // [sp+10h] [bp-18h]@8
  int v37; // [sp+14h] [bp-14h]@9
  int v38; // [sp+20h] [bp-8h]@1
  int v39; // [sp+24h] [bp-4h]@1

  v4 = 0;
  v1 = 0;
  v2 = (int)((char *)this - 1);
  v38 = 0;
  v39 = 0;
  dword_F8B1DC = 0;
  v3 = 2;
  if ( !v2 )
  {
    while ( 1 )
    {
      v19 = 1;
      do
      {
        v20 = v19 + 4 * *(_DWORD *)(dword_507BC0 + 28) + *(_DWORD *)(dword_507BC0 + 28);
        if ( v4 )
          v21 = word_4F063E[v20];
        else
          v21 = word_4F03FE[v20];
        v22 = v21 - 23;
        if ( v22 )
        {
          v23 = v22 - 1;
          if ( v23 )
          {
            v24 = v23 - 1;
            if ( v24 )
            {
              v25 = v24 - 1;
              if ( v25 )
              {
                v26 = v25 - 1;
                if ( v26 )
                {
                  v27 = v26 - 1;
                  if ( v27 )
                  {
                    if ( v27 != v3 )
                      goto LABEL_51;
                    v34 = 36;
                  }
                  else
                  {
                    v34 = 42;
                  }
                }
                else
                {
                  v34 = 41;
                }
              }
              else
              {
                v34 = 40;
              }
            }
            else
            {
              v34 = 39;
            }
          }
          else
          {
            v34 = 38;
          }
        }
        else
        {
          v34 = 37;
        }
        v39 = sub_4BE571(v34, (int)&v35, v39, 5);
        v1 = dword_F8B1DC;
        v3 = 2;
LABEL_51:
        ++v19;
      }
      while ( v19 <= 4 );
      ++v4;
      if ( v4 >= v3 )
        goto LABEL_53;
    }
  }
  v5 = v2 - 1;
  if ( !v5 )
  {
    v10 = 0;
    while ( 1 )
    {
      v11 = 0;
      do
      {
        v12 = 1;
        do
        {
          v14 = v11 + 2 * *(_DWORD *)(dword_507BC0 + 28) - 30;
          v13 = v12 + 4 * v14 + v14;
          if ( v10 )
            v15 = word_4F06D8[v13];
          else
            v15 = word_4F0498[v13];
          v16 = v15 - 31;
          if ( v16 )
          {
            v17 = v16 - 1;
            if ( v17 )
            {
              v18 = v17 - 1;
              if ( v18 )
              {
                if ( v18 != 1 )
                  goto LABEL_28;
                v33 = 44;
              }
              else
              {
                v33 = 47;
              }
            }
            else
            {
              v33 = 46;
            }
          }
          else
          {
            v33 = 45;
          }
          v39 = sub_4BE571(v33, (int)&v35, v39, 5);
          v1 = dword_F8B1DC;
LABEL_28:
          ++v12;
        }
        while ( v12 <= 4 );
        ++v11;
      }
      while ( v11 < 2 );
      ++v10;
      if ( v10 >= 2 )
        goto LABEL_53;
    }
  }
  v6 = v5 - 1;
  if ( v6 )
  {
    v7 = v6 - 1;
    if ( v7 )
    {
      v8 = v7 - 17;
      if ( v8 )
      {
        v9 = v8 - 2;
        if ( v9 )
        {
          if ( v9 == 7 )
          {
            v39 = 2;
            v35 = 69;
            v36 = 60;
          }
        }
        else
        {
          v39 = 3;
          v35 = 67;
          v36 = 66;
          v37 = 58;
        }
      }
      else
      {
        v39 = 3;
        v35 = 70;
        v36 = 65;
        v37 = 62;
      }
    }
    else
    {
      v39 = 2;
      v35 = 71;
      v36 = 68;
    }
  }
  else
  {
    v39 = 2;
    v35 = 57;
    v36 = 59;
  }
LABEL_53:
  if ( v39 > 0 )
  {
    v28 = &v35;
    while ( 1 )
    {
      v29 = *v28;
      if ( *v28 <= 47 )
        break;
      if ( v29 <= 66 )
      {
        if ( v29 == 66 )
        {
          //v30 = dword_AE3348;
         v30 = aSkillNames[30];
          goto LABEL_106;
        }
        if ( v29 == 57 )
        {
          //v30 = dword_AE3324;
         v30 = aSkillNames[21];
          goto LABEL_106;
        }
        if ( v29 == 58 )
        {
          //v30 = dword_AE3328;
         v30 = aSkillNames[22];
          goto LABEL_106;
        }
        if ( v29 == 60 )
        {
          //v30 = dword_AE3330;
         v30 = aSkillNames[24];
          goto LABEL_106;
        }
        if ( v29 == 62 )
        {
          //v30 = dword_AE3338;
         v30 = aSkillNames[26];
          goto LABEL_106;
        }
        if ( v29 == 65 )
        {
          //v30 = dword_AE3344;
         v30 = aSkillNames[29];
          goto LABEL_106;
        }
        goto LABEL_100;
      }
      switch ( v29 )
      {
        case 67:
          //v30 = dword_AE334C;
         v30 = aSkillNames[31];
          break;
        case 68:
          //v30 = dword_AE3350;
         v30 = aSkillNames[32];
          break;
        case 69:
          //v30 = dword_AE3354;
         v30 = aSkillNames[33];
          break;
        case 70:
          //v30 = dword_AE3358;
         v30 = aSkillNames[34];
          break;
        default:
          if ( v29 != 71 )
            goto LABEL_100;
          //v30 = dword_AE335C;
          v30 = aSkillNames[35];
          break;
      }
LABEL_106:
      dword_F8B1B8[v1] = v30;
      v31 = v38++;
      dword_F8B1DC = v1 + 1;
      sub_4B36CC(v31, v29);
      ++v28;
      if ( v38 >= v39 )
        goto LABEL_107;
      v1 = dword_F8B1DC;
    }
    if ( *v28 == 47 )
    {
      //v30 = dword_AE32FC;
     v30 = aSkillNames[11];
      goto LABEL_106;
    }
    if ( v29 > 40 )
    {
      if ( v29 == 41 )
      {
        //v30 = dword_AE32E4;
       v30 = aSkillNames[5];
        goto LABEL_106;
      }
      if ( v29 == 42 )
      {
        //v30 = dword_AE32E8;
       v30 = aSkillNames[6];
        goto LABEL_106;
      }
      if ( v29 == 44 )
      {
        //v30 = dword_AE32F0;
       v30 = aSkillNames[8];
        goto LABEL_106;
      }
      if ( v29 == 45 )
      {
        //v30 = dword_AE32F4;
       v30 = aSkillNames[9];
        goto LABEL_106;
      }
      if ( v29 == 46 )
      {
        //v30 = dword_AE32F8;
       v30 = aSkillNames[10];
        goto LABEL_106;
      }
    }
    else
    {
      if ( v29 == 40 )
      {
        //v30 = dword_AE32E0;
       v30 = aSkillNames[4];
        goto LABEL_106;
      }
      if ( v29 == 5 )
      {
        //v30 = dword_AE332C;
       v30 = aSkillNames[23];
        goto LABEL_106;
      }
      if ( v29 == 36 )
      {
        //v30 = (int)dword_AE32D0;
       v30 = aSkillNames[0];
        goto LABEL_106;
      }
      if ( v29 == 37 )
      {
        //v30 = dword_AE32D4;
       v30 = aSkillNames[1];
        goto LABEL_106;
      }
      if ( v29 == 38 )
      {
        //v30 = dword_AE32D8;
       v30 = aSkillNames[2];
        goto LABEL_106;
      }
      if ( v29 == 39 )
      {
        //v30 = dword_AE32DC;
       v30 = aSkillNames[3];
        goto LABEL_106;
      }
    }
LABEL_100:
    v30 = pGlobalTXT_LocalizationStrings[127];
    goto LABEL_106;
  }
LABEL_107:
  sub_41D08F(dword_507BBC, v38, 1, 0, 2);
  result = *(_DWORD *)(dword_507BBC + 40);
  dword_F8B1E0 = *(_DWORD *)(dword_507BBC + 40);
  return result;
}

//----- (004B3A72) --------------------------------------------------------
int __thiscall sub_4B3A72(void *this)
{
  int v1; // esi@1
  int result; // eax@4

  v1 = 0;
  if ( this == (void *)21 )
  {
    sub_4B36CC(0, 102);
    v1 = 2;
    sub_4B36CC(1, 103);
    if ( sub_493244(651) )
    {
      v1 = 3;
      sub_4B36CC(2, 104);
    }
  }
  sub_41D08F(dword_507BBC, v1, 1, 0, 2);
  result = *(_DWORD *)(dword_507BBC + 40);
  dword_F8B1E0 = *(_DWORD *)(dword_507BBC + 40);
  return result;
}

//----- (004B3AD4) --------------------------------------------------------
int __fastcall sub_4B3AD4(signed int a1)
{
  int result; // eax@7
  int v2; // [sp-10h] [bp-10h]@4
  int v3; // [sp-Ch] [bp-Ch]@4
  int v4; // [sp-8h] [bp-8h]@4
  int v5; // [sp-4h] [bp-4h]@4

  if ( a1 > 0 )
  {
    if ( a1 <= 3 )
    {
      sub_4B36CC(0, 3);
      sub_4B36CC(1, 4);
      sub_4B36CC(2, 5);
      v5 = 2;
      v4 = 0;
      v3 = 1;
      v2 = 3;
      goto LABEL_6;
    }
    if ( a1 == 4 )
    {
      sub_4B36CC(0, 3);
      sub_4B36CC(1, 4);
      v5 = 2;
      v4 = 0;
      v3 = 1;
      v2 = 2;
LABEL_6:
      sub_41D08F(dword_507BBC, v2, v3, v4, v5);
      goto LABEL_7;
    }
  }
LABEL_7:
  result = *(_DWORD *)(dword_507BBC + 40);
  dword_F8B1E0 = *(_DWORD *)(dword_507BBC + 40);
  return result;
}

//----- (004B3B42) --------------------------------------------------------
int __fastcall sub_4B3B42(signed int a1)
{
  int v1; // ecx@18
  int v2; // ecx@19
  int v3; // ecx@20
  signed int v4; // eax@22
  signed int v5; // esi@22
  int v6; // edx@24
  int v7; // ecx@24
  int result; // eax@43
  int v9; // [sp-10h] [bp-14h]@28
  int v10; // [sp-Ch] [bp-10h]@28
  int v11; // [sp-8h] [bp-Ch]@28
  int v12; // [sp-4h] [bp-8h]@4
  int v13; // [sp-4h] [bp-8h]@5
  int v14; // [sp-4h] [bp-8h]@9
  int v15; // [sp-4h] [bp-8h]@10
  int v16; // [sp-4h] [bp-8h]@14
  int v17; // [sp-4h] [bp-8h]@28

  if ( a1 > 13 )
  {
    if ( a1 > 22 )
    {
      if ( a1 == 23 )
      {
        sub_4B36CC(0, 10);
        sub_4B36CC(1, 11);
        v14 = 96;
LABEL_41:
        sub_4B36CC(2, v14);
        v17 = 2;
        v11 = 0;
        v10 = 1;
        v9 = 3;
        goto LABEL_42;
      }
      if ( a1 <= 26 )
        goto LABEL_43;
      if ( a1 > 28 )
      {
        if ( a1 != 30 )
          goto LABEL_43;
        sub_4B36CC(0, 17);
        v16 = 96;
        goto LABEL_37;
      }
      sub_4B36CC(0, 105);
      sub_4B36CC(1, 106);
      sub_4B36CC(2, 107);
      v12 = 108;
    }
    else
    {
      if ( a1 == 22 )
      {
        sub_4B36CC(0, 7);
        v16 = 8;
        goto LABEL_37;
      }
      v1 = a1 - 14;
      if ( !v1 )
      {
        sub_4B36CC(0, 18);
        sub_4B36CC(1, 48);
        sub_4B36CC(2, 49);
        sub_4B36CC(3, 50);
        sub_4B36CC(4, 51);
        v17 = 2;
        v11 = 0;
        v10 = 1;
        v9 = 5;
        goto LABEL_42;
      }
      v2 = v1 - 1;
      if ( v2 )
      {
        v3 = v2 - 2;
        if ( v3 )
        {
          if ( v3 != 4 )
            goto LABEL_43;
          sub_4B36CC(0, 15);
          sub_4B36CC(1, 16);
          v5 = 3;
          sub_4B36CC(2, 96);
          v4 = *(_DWORD *)(dword_507BC0 + 28);
          if ( v4 < 108 || v4 > 120 )
            goto LABEL_28;
          v5 = 4;
          v6 = 101;
          v7 = 3;
        }
        else
        {
          v5 = 1;
          sub_4B36CC(0, 99);
          if ( !dword_AE31E0 )
          {
LABEL_28:
            v17 = 2;
            v11 = 0;
            v10 = 1;
            v9 = v5;
LABEL_42:
            sub_41D08F(dword_507BBC, v9, v10, v11, v17);
            goto LABEL_43;
          }
          v5 = 2;
          v7 = 1;
          v6 = 100;
        }
        sub_4B36CC(v7, v6);
        goto LABEL_28;
      }
      sub_4B36CC(0, 18);
      sub_4B36CC(1, 52);
      sub_4B36CC(2, 53);
      v12 = 54;
    }
LABEL_39:
    sub_4B36CC(3, v12);
    v17 = 2;
    v11 = 0;
    v10 = 1;
    v9 = 4;
    goto LABEL_42;
  }
  if ( a1 == 13 )
  {
    sub_4B36CC(0, 18);
    v16 = 56;
LABEL_37:
    sub_4B36CC(1, v16);
    v17 = 2;
    v11 = 0;
    v10 = 1;
    v9 = 2;
    goto LABEL_42;
  }
  switch ( a1 )
  {
    case 1:
    case 2:
    case 3:
    case 4:
      sub_4B36CC(0, 2);
      sub_4B36CC(1, 95);
      sub_4B36CC(2, 94);
      v12 = 96;
      goto LABEL_39;
    case 5:
      sub_4B36CC(0, 18);
      v13 = 48;
      goto LABEL_9;
    case 6:
      sub_4B36CC(0, 18);
      v13 = 49;
      goto LABEL_9;
    case 7:
      sub_4B36CC(0, 18);
      v13 = 50;
      goto LABEL_9;
    case 8:
      sub_4B36CC(0, 18);
      v13 = 51;
LABEL_9:
      sub_4B36CC(1, v13);
      v14 = 72;
      goto LABEL_41;
    case 9:
      sub_4B36CC(0, 18);
      v15 = 52;
      goto LABEL_13;
    case 10:
      sub_4B36CC(0, 18);
      v15 = 53;
      goto LABEL_13;
    case 11:
      sub_4B36CC(0, 18);
      v15 = 54;
LABEL_13:
      sub_4B36CC(1, v15);
      v14 = 61;
      goto LABEL_41;
    case 12:
      sub_4B36CC(0, 18);
      v16 = 55;
      goto LABEL_37;
    default:
      break;
  }
LABEL_43:
  result = *(_DWORD *)(dword_507BBC + 40);
  dword_F8B1E0 = *(_DWORD *)(dword_507BBC + 40);
  return result;
}

//----- (004B3E1E) --------------------------------------------------------
int __cdecl sub_4B3E1E()
{
  int v0; // ecx@1
  signed int v1; // edi@1
  char *v2; // ST40_4@1

  v2 = sub_4459F9(dword_591090);
  v1 = 0;
  *(_DWORD *)(dword_507BBC + 24) = 1;
  GUIWindowDelete(dword_507BBC);
  v0 = GUIWindowCreate(0, 0, 640, 480, 10, 1, 0);
  dword_507BBC = v0;
  if ( (&dword_737C2C)[20 * *((_DWORD *)v2 + 6)] )
  {
    GUIButtonCreate(v0, 480, 160, 140, 30, 1, 0, 136, 77, 0, pGlobalTXT_LocalizationStrings[407], 0);
    v1 = 1;
  }
  GUIButtonCreate(dword_507BBC, 480, 30 * v1 + 160, 140, 30, 1, 0, 136, 76, 0, pGlobalTXT_LocalizationStrings[406], 0);
  return sub_41D08F(dword_507BBC, v1 + 1, 1, 0, 1);
}

//----- (004B3EF0) --------------------------------------------------------
int __fastcall sub_4B3EF0(int a1)
{
  int result; // eax@1
  int v2; // edi@1

  v2 = a1;
  dword_59108C = 81;
  dword_F8B1E8 = (char *)dword_721984[2 * a1];
  sub_4B29F2(a1);
  GUIWindowDelete(dword_507BBC);
  dword_507BBC = GUIWindowCreate(0, 0, 640, 350, 1, v2, 0);
  dword_5076F4 = GUIButtonCreate(
                   dword_507BBC,
                   471,
                   445,
                   169,
                   35,
                   1,
                   0,
                   113,
                   0,
                   0,
                   pGlobalTXT_LocalizationStrings[34],
                   dword_506438 != -1 ? 72 * dword_506438 + 7145548 : 0);
  GUIButtonCreate(dword_507BBC, 0, 0, 0, 0, 1, 0, 81, 0, 0, Class, 0);
  GUIButtonCreate(dword_507BBC, 480, 160, 140, 30, 1, 0, 175, 82, 0, pGlobalTXT_LocalizationStrings[122], 0);
  result = sub_41D08F(dword_507BBC, 1, 1, 0, 2);
  dword_F8B19C = -1;
  return result;
}

//----- (004B3FE5) --------------------------------------------------------
int __fastcall sub_4B3FE5(void *a1)
{
  const char *v1; // edi@1
  int v2; // edi@1
  int result; // eax@3

  v2 = (int)a1;
  dword_59108C = 78;
  dword_F8B1E8 = (char *)dword_721BAC[2 * (_DWORD)a1];
  sub_4B254D(a1);
  GUIWindowDelete(dword_507BBC);
  dword_507BBC = GUIWindowCreate(0, 0, 640, 350, 1, v2, 0);
  v1 = Class;
  dword_5076F4 = GUIButtonCreate(
                   dword_507BBC,
                   471,
                   445,
                   169,
                   35,
                   1,
                   0,
                   113,
                   0,
                   0,
                   pGlobalTXT_LocalizationStrings[34],
                   dword_506438 != -1 ? 72 * dword_506438 + 7145548 : 0);
  GUIButtonCreate(dword_507BBC, 0, 0, 0, 0, 1, 0, 81, 0, 0, Class, 0);
  if ( dword_F8B1A8 )
    v1 = pGlobalTXT_LocalizationStrings[535];
  GUIButtonCreate(dword_507BBC, 480, 160, 140, 30, 1, 0, 175, 79, 0, v1, 0);
  result = sub_41D08F(dword_507BBC, 1, 1, 0, 2);
  dword_F8B19C = -1;
  return result;
}

//----- (004B40E6) --------------------------------------------------------
int __cdecl sub_4B40E6()
{
  signed int v0; // ebx@1
  int v1; // edi@1
  int result; // eax@3

  v0 = 0;
  v1 = dword_5913D8[dword_5913F0 - ((dword_591080 != 0) + 1)];
  GUIWindowDelete(dword_507BBC);
  dword_507BBC = GUIWindowCreate(0, 0, 640, 350, 1, 0, 0);
  dword_5076F4 = GUIButtonCreate(
                   dword_507BBC,
                   471,
                   445,
                   169,
                   35,
                   1,
                   0,
                   113,
                   0,
                   0,
                   pGlobalTXT_LocalizationStrings[34],
                   dword_506438 != -1 ? 72 * dword_506438 + 7145548 : 0);
  GUIButtonCreate(dword_507BBC, 0, 0, 0, 0, 1, 0, 81, 0, 0, Class, 0);
  if ( (&dword_737C2C)[20 * *(_DWORD *)(v1 + 24)] )
  {
    GUIButtonCreate(dword_507BBC, 480, 160, 140, 30, 1, 0, 175, 77, 0, pGlobalTXT_LocalizationStrings[407], 0);
    v0 = 1;
  }
  GUIButtonCreate(dword_507BBC, 480, 30 * v0 + 160, 140, 30, 1, 0, 175, 76, 0, pGlobalTXT_LocalizationStrings[406], 0);
  result = sub_41D08F(dword_507BBC, v0 + 1, 1, 0, 2);
  dword_F8B19C = -1;
  return result;
}

//----- (004B4224) --------------------------------------------------------
int __thiscall sub_4B4224(void *this)
{
  int v1; // ebx@1
  int result; // eax@3
  int i; // ebp@5
  signed int v4; // ebp@9
  void *v5; // ecx@14
  bool v6; // eax@16
  void *v7; // ecx@19
  bool v8; // eax@21
  void *v9; // ecx@24
  bool v10; // eax@26
  void *v11; // ecx@29
  bool v12; // eax@31
  void *v13; // ecx@34
  bool v14; // eax@36
  void *v15; // ecx@39
  bool v16; // eax@41
  int v17; // [sp+10h] [bp-4h]@4

  v1 = 0;
  dword_5913F0 = (int)((char *)this + 1);
  if ( (char *)this + 1 == (void *)dword_591424 && dword_5C35D0 )
  {
    GUIWindowDelete(dword_507BBC);
    dword_507BBC = GUIWindowCreate(0, 0, 640, 480, 1, 0, 0);
    sprintfex(byte_591098, pGlobalTXT_LocalizationStrings[411], pMapStats->pMapInfos[dword_5C35D0].pLocationName);
    dword_5076F4 = GUIButtonCreate(
                     dword_507BBC,
                     566,
                     445,
                     75,
                     33,
                     1,
                     0,
                     113,
                     0,
                     78,
                     pGlobalTXT_LocalizationStrings[34],
                     uTextureIdx_BtnEsc2 + 1 != 0 ? 72 * (_DWORD)uTextureIdx_BtnEsc2 + 7145548 : 0);
    dword_5076FC = GUIButtonCreate(
                     dword_507BBC,
                     486,
                     445,
                     75,
                     33,
                     1,
                     0,
                     191,
                     1,
                     89,
                     byte_591098,
                     uTextureIdx_BtnYes2 != -1 ? 72 * uTextureIdx_BtnYes2 + 7145548 : 0);
    GUIButtonCreate(dword_507BBC, dword_4E5E50, dword_4E5EE0, 63, 73, 1, 0, 191, 1, 32, byte_591098, 0);
    result = GUIButtonCreate(dword_507BBC, 8, 8, 460, 344, 1, 0, 191, 1, 89, byte_591098, 0);
  }
  else
  {
    v17 = dword_5913D8[(_DWORD)((char *)this - (dword_591080 != 0))];
    if ( dword_F8B19C == -1 )
    {
      GUIWindowDelete(dword_507BBC);
    }
    else
    {
      for ( i = 0; i < dword_591424; ++i )
        sub_41D0D8(dword_5913F4[i]);
    }
    v4 = 1;
    dword_507BBC = GUIWindowCreate(0, 0, 640, 345, 1, 0, 0);
    dword_5076F4 = GUIButtonCreate(
                     dword_507BBC,
                     471,
                     445,
                     169,
                     35,
                     1,
                     0,
                     113,
                     0,
                     0,
                     pGlobalTXT_LocalizationStrings[74],
                     dword_506438 != -1 ? 72 * dword_506438 + 7145548 : 0);
    GUIButtonCreate(dword_507BBC, 8, 8, 450, 320, 1, 0, 81, 0, 0, Class, 0);
    if ( dword_5913F0 == 1 && dword_591080 )
    {
      result = sub_4B3B42(dword_F8B198);
    }
    else
    {
      if ( *(_DWORD *)(v17 + 32) )
      {
        v1 = 1;
        GUIButtonCreate(dword_507BBC, 480, 160, 140, 30, 1, 0, 175, 13, 0, Class, 0);
      }
      v5 = *(void **)(v17 + 40);
      if ( v5 )
      {
        if ( v1 < 4 )
        {
          v6 = sub_4466C4(v5);
          if ( v6 == 1 || v6 == 2 )
            GUIButtonCreate(dword_507BBC, 480, 30 * v1++ + 160, 140, 30, 1, 0, 175, 19, 0, Class, 0);
        }
      }
      v7 = *(void **)(v17 + 44);
      if ( v7 )
      {
        if ( v1 < 4 )
        {
          v8 = sub_4466C4(v7);
          if ( v8 == 1 || v8 == 2 )
            GUIButtonCreate(dword_507BBC, 480, 30 * v1++ + 160, 140, 30, 1, 0, 175, 20, 0, Class, 0);
        }
      }
      v9 = *(void **)(v17 + 48);
      if ( v9 )
      {
        if ( v1 < 4 )
        {
          v10 = sub_4466C4(v9);
          if ( v10 == 1 || v10 == 2 )
            GUIButtonCreate(dword_507BBC, 480, 30 * v1++ + 160, 140, 30, 1, 0, 175, 21, 0, Class, 0);
        }
      }
      v11 = *(void **)(v17 + 52);
      if ( v11 )
      {
        if ( v1 < 4 )
        {
          v12 = sub_4466C4(v11);
          if ( v12 == 1 || v12 == 2 )
            GUIButtonCreate(dword_507BBC, 480, 30 * v1++ + 160, 140, 30, 1, 0, 175, 22, 0, Class, 0);
        }
      }
      v13 = *(void **)(v17 + 56);
      if ( v13 )
      {
        if ( v1 < 4 )
        {
          v14 = sub_4466C4(v13);
          if ( v14 == 1 || v14 == 2 )
            GUIButtonCreate(dword_507BBC, 480, 30 * v1++ + 160, 140, 30, 1, 0, 175, 23, 0, Class, 0);
        }
      }
      v15 = *(void **)(v17 + 60);
      if ( v15 )
      {
        if ( v1 < 4 )
        {
          v16 = sub_4466C4(v15);
          if ( v16 == 1 || v16 == 2 )
            GUIButtonCreate(dword_507BBC, 480, 30 * v1++ + 160, 140, 30, 1, 0, 175, 24, 0, Class, 0);
        }
      }
      sub_41D08F(dword_507BBC, v1, 1, 0, 2);
      v4 = 1;
      result = *(_DWORD *)(dword_507BBC + 40);
      dword_F8B1E0 = *(_DWORD *)(dword_507BBC + 40);
    }
    dword_F8B19C = v4;
  }
  return result;
}

//----- (004B46A5) --------------------------------------------------------
void sub_4B46A5(const char *Str1, __int16 a2)
{
  const char *v3; // esi@1
  __int16 v4; // di@1
  int v5; // eax@1

  v3 = Str1;
  v4 = a2;//colored or white text flag
 Render_DrawRGBTexture_New(pD3DRenderer, 0, 352, uTextureID_GameUI_StatusBar);
  v5 = AlignText_Center(450, v3, pFontLucida);
  FontDrawText(pGUIWindow0, pFontLucida, v5 + 11, 357, v3, 0, 0, 0);
}

//----- (004B46F8) --------------------------------------------------------
int __fastcall sub_4B46F8(int a1)
{
  int v1; // eax@1
  int i; // edx@1

  v1 = 0;
  for ( i = 0; i < a1; ++i )
    v1 += i + 1;
  return 1000 * v1;
}

//----- (004B4710) --------------------------------------------------------
int __cdecl sub_4B4710()
{
  int v0; // eax@1
  int v1; // edx@1
  int v2; // ecx@1
  int v3; // ebx@1
  unsigned int v4; // eax@1
  __int64 v5; // qax@3
  int v6; // ecx@3
  int v7; // edi@3
  int v8; // esi@3
  int v9; // edx@6
  int v10; // ecx@8
  signed int v11; // esi@8
  double v12; // st7@8
  int result; // eax@11
  int v14; // edi@16
  signed int v15; // esi@16
  int v16; // esi@18
  int v17; // eax@18
  int v18; // eax@19
  int v19; // eax@21
  int v20; // ecx@26
  int v21; // eax@28
  int v22; // esi@28
  int v23; // eax@28
  unsigned __int16 v24; // ax@30
  int v25; // ecx@30
  const char *v26; // eax@30
  int v27; // eax@30
  int v28; // eax@30
  int v29; // eax@34
  unsigned __int16 v30; // ST14_2@36
  int v31; // eax@36
  const char *v32; // ST18_4@38
  unsigned __int16 v33; // ST14_2@38
  int v34; // eax@38
  int v35; // eax@39
  int v36; // eax@40
  int v37; // edi@40
  int v38; // ecx@41
  signed int v39; // eax@45
  int v40; // ecx@45
  int v41; // eax@49
  int v42; // eax@50
  int v43; // ecx@50
  unsigned int v44; // eax@50
  int v45; // ecx@63
  int v46; // edx@63
  const char **v47; // esi@64
  int v48; // eax@66
  int v49; // ecx@68
  int v50; // eax@74
  int v51; // ebx@75
  int v52; // edx@75
  unsigned __int8 v53; // sf@75
  const char **v54; // edi@76
  unsigned __int16 v55; // ax@77
  int v56; // ecx@77
  int v57; // eax@77
  int v58; // esi@77
  int v59; // eax@77
  int v60; // eax@77
  unsigned __int16 v61; // [sp-Ch] [bp-90h]@40
  int v62; // [sp-Ch] [bp-90h]@67
  const char *v63; // [sp-8h] [bp-8Ch]@40
  int v64; // [sp-8h] [bp-8Ch]@67
  int v65; // [sp-4h] [bp-88h]@40
  int v66; // [sp-4h] [bp-88h]@56
  int v67; // [sp-4h] [bp-88h]@67
  int v68; // [sp+Ch] [bp-78h]@1
  int v69; // [sp+14h] [bp-70h]@1
  int v70; // [sp+1Ch] [bp-68h]@1
  __int64 v71; // [sp+60h] [bp-24h]@3
  unsigned int v72; // [sp+68h] [bp-1Ch]@1
  int v73; // [sp+6Ch] [bp-18h]@3
  int v74; // [sp+70h] [bp-14h]@8
  unsigned int i; // [sp+74h] [bp-10h]@1
  __int16 v76[2]; // [sp+78h] [bp-Ch]@1
  int v77; // [sp+7Ch] [bp-8h]@18
  int v78; // [sp+80h] [bp-4h]@16

  v3 = (int)*(&ptr_A750C4 + uActiveCharacter);
  memcpy(&v68, (const void *)dword_507BC0, 0x54u);
  v68 = 483;
  v69 = 148;
  v70 = 334;
  v72 = 0xFFFFFFFF;
  v4 = 0xFFE1CD23;
  v2 = *(_WORD *)(v3 + 218);
  *(_DWORD *)v76 = v4;
  v0 = 0;
  v1 = 0;
  for ( i = v2; v1 < v2; ++v1 )
    v0 += v1 + 1;
  v7 = 1000 * v0;
  v8 = *(_DWORD *)(v3 + 164);
  v6 = *(_DWORD *)(dword_507BC0 + 28);
  v73 = (unsigned __int16)word_4F0866[v6];
  v5 = 1000 * v0;
  v71 = v5;
  if ( v8 >= HIDWORD(v5) )
  {
    if ( v8 > HIDWORD(v5) || *(_DWORD *)(v3 + 160) >= (_DWORD)v5 )
    {
      v9 = *(_BYTE *)(v3 + 185) % 4 + 1;
      if ( v9 == 4 )
        v9 = 3;
      v12 = (double)(signed int)i;
      i = 0;
      v74 = v9;
      v11 = (signed __int64)(v12 * *((float *)&unk_591458 + 13 * v6) * (double)v9);
      v10 = v11 * (100 - sub_4911F3((void *)v3)) / 100;
      if ( v10 < v11 / 3 )
        v10 = v11 / 3;
      i = v10;
    }
  }
  result = sub_4B1784();
  if ( result )
  {
    if ( dword_F8B19C != 1 )
    {
      if ( dword_F8B19C != 17 )
      {
        result = dword_F8B19C - 96;
        if ( dword_F8B19C == 96 )
        {
          result = sub_4B1784();
          if ( result )
          {
            i = 0;
            v14 = dword_507BBC;
            v15 = (signed __int64)(*((float *)&unk_59145C + 13 * *(_DWORD *)(dword_507BC0 + 28)) * 500.0);
            v78 = v15 * (100 - sub_4911F3((void *)v3)) / 100;
            if ( v78 < v15 / 3 )
              v78 = v15 / 3;
            v16 = *(_DWORD *)(v14 + 56);
            v17 = *(_DWORD *)(v14 + 40);
            v77 = 0;
            if ( v16 >= v16 + v17 )
              goto LABEL_82;
            do
            {
              v18 = *(_DWORD *)(GUIWindow_GetChild(v14, v16) + 36) - 36;
              if ( *(&byte_4ED970[37 * *(_BYTE *)(v3 + 185)] + v18) )
              {
                if ( !*(_WORD *)(v3 + 2 * v18 + 264) )
                {
                  //v19 = sub_44C59D(pFontArrus, (&dword_AE32D0)[4 * v18], (int)&v68, 0, 0);
                  v19 = sub_44C59D(pFontArrus, aSkillNames[v18], (int)&v68, 0, 0);
                  i += v19;
                  ++v77;
                }
              }
              ++v16;
            }
            while ( v16 < *(_DWORD *)(v14 + 40) + *(_DWORD *)(v14 + 56) );
            if ( v77 )
            {
              sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[401], v78);
              sub_44D406((int)&v68, pFontArrus, 0, 146, 0, &TmpBuf, 3);
              v78 = (signed int)(149 - i) / v77;
              if ( v78 > 32 )
                v78 = 32;
              result = *(_DWORD *)(v14 + 56);
              v20 = (signed int)(149 - v77 * v78 - i) / 2 - v78 / 2 + 162;
              i = result;
              v73 = v20;
              if ( result < result + *(_DWORD *)(v14 + 40) )
              {
                v77 = 2;
                do
                {
                  v23 = GUIWindow_GetChild(v14, i);
                  v22 = v23;
                  v21 = *(_DWORD *)(v23 + 36) - 36;
                  if ( !*(&byte_4ED970[37 * *(_BYTE *)(v3 + 185)] + v21) || *(_WORD *)(v3 + 2 * v21 + 264) )
                  {
                    *(_DWORD *)(v22 + 20) = 0;
                    *(_DWORD *)(v22 + 12) = 0;
                    *(_DWORD *)(v22 + 4) = 0;
                  }
                  else
                  {
                    //v26 = (&dword_AE32D0)[4 * v21];
                    v26 = aSkillNames[v21];
                    *(_DWORD *)(v22 + 4) = v78 + v73;
                    HIDWORD(v71) = v26;
                    v27 = sub_44C59D(pFontArrus, v26, (int)&v68, 0, 0);
                    v25 = *(_DWORD *)(v22 + 4);
                    *(_DWORD *)(v22 + 12) = v27;
                    v28 = v25 + v27 - 1;
                    *(_DWORD *)(v22 + 20) = v28;
                    v73 = v28;
                    v24 = v76[0];
                    if ( *(_DWORD *)(dword_507BBC + 44) != v77 )
                      v24 = v72;
                    sub_44D406((int)&v68, pFontArrus, 0, v25, v24, HIDWORD(v71), 3);
                  }
                  v29 = *(_DWORD *)(v14 + 56);
                  ++i;
                  result = *(_DWORD *)(v14 + 40) + v29;
                  ++v77;
                }
                while ( (signed int)i < result );
              }
            }
            else
            {
LABEL_82:
              sprintfex(
                &TmpBuf,
                pGlobalTXT_LocalizationStrings[544],
                v3 + 168,
                //(&dword_AE31F0)[4 * *(_BYTE *)(v3 + 185)]);
                aClassNames[*(_BYTE *)(v3 + 185)]);
              strcat((char *)&TmpBuf, "\n \n");
              strcat((char *)&TmpBuf, pGlobalTXT_LocalizationStrings[528]);
              v30 = v76[0];
              v31 = sub_44C59D(pFontArrus, &TmpBuf, (int)&v68, 0, 0);
              result = (int)sub_44D406((int)&v68, pFontArrus, 0, (174 - v31) / 2 + 138, v30, &TmpBuf, 3);
            }
          }
        }
        return result;
      }
      if ( !sub_4B1784() )
      {
        v32 = dword_721A3C;
        v33 = v76[0];
        v34 = sub_44C59D(pFontArrus, dword_721A3C, (int)&v68, 0, 0);
        sub_44D406((int)&v68, pFontArrus, 0, (212 - v34) / 2 + 101, v33, v32, 3);
        result = dword_507BBC;
        *(_DWORD *)(dword_507BBC + 40) = 0;
        return result;
      }
      v35 = *(_WORD *)(v3 + 218);
      if ( v35 < v73 )
      {
        v38 = *(_DWORD *)(v3 + 164);
        if ( v38 >= HIDWORD(v71) && (v38 > HIDWORD(v71) || *(_DWORD *)(v3 + 160) >= (_DWORD)v71) )
        {
          if ( pParty_global->uNumGold >= i )
          {
            sub_492BB6(i);
            sub_4B1E92(*(_DWORD *)(dword_507BC0 + 28), 2);
            ++*(_WORD *)(v3 + 218);
            *(_DWORD *)(v3 + 6456) += *(_WORD *)(v3 + 218) / 10 + 5;
            *(_DWORD *)(v3 + 6460) = Player_GetMaxHealth(v3);
            *(_DWORD *)(v3 + 6464) = Player_GetMaxMana(v3);
            v40 = 0;
            v39 = (signed int)&unk_F8B148;
            do
            {
              if ( *(_DWORD *)v39 > v40 )
                v40 = *(_DWORD *)v39;
              v39 += 4;
            }
            while ( v39 < (signed int)word_F8B158 );
            v41 = 4 * uActiveCharacter + 16298308;
            ++*(&dword_F8B144 + uActiveCharacter);
            if ( *(_DWORD *)v41 > v40 )
            {
              v44 = sub_494820(pParty_global->uCurrentHour);
              v43 = *(_DWORD *)(dword_507BC0 + 28);
              v42 = 60 * (v44 + 4) - pParty_global->uCurrentMinute;
              if ( v43 == 94 || v43 == 95 )
                v42 += 720;
              sub_4B1BDB(v42 + 10080);
              if ( dword_6BE360 == 2 )
                sub_489487();
            }
            sub_4948B1((void *)v3, 87, 0);
            sprintfex(
              &TmpBuf,
              pGlobalTXT_LocalizationStrings[430],
              v3 + 168,
              *(_WORD *)(v3 + 218),
              *(_WORD *)(v3 + 218) / 10 + 5);
            sub_44C175(&TmpBuf, 2);
            goto LABEL_60;
          }
          sub_44C175(pGlobalTXT_LocalizationStrings[155], 2);
          v66 = 4;
LABEL_59:
          sub_4B1E92(*(_DWORD *)(dword_507BC0 + 28), v66);
LABEL_60:
          result = dword_50CBD0[0];
          if ( dword_50CBD0[0] < 40 )
          {
            dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
            dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
            result = 3 * dword_50CBD0[0] + 3;
            dword_50CBD0[result] = 0;
            ++dword_50CBD0[0];
          }
          return result;
        }
        sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[538], v7 - *(_DWORD *)(v3 + 160), v35 + 1);
        v37 = 0;
        v65 = 3;
        v63 = &TmpBuf;
        v61 = v76[0];
        v36 = (212 - sub_44C59D(pFontArrus, &TmpBuf, (int)&v68, 0, 0)) / 2 + 88;
      }
      else
      {
        sprintfex(&TmpBuf, "%s\n \n%s", pGlobalTXT_LocalizationStrings[536], pGlobalTXT_LocalizationStrings[529]);
        v37 = 0;
        v65 = 3;
        v63 = &TmpBuf;
        v61 = v76[0];
        v36 = (212 - sub_44C59D(pFontArrus, &TmpBuf, (int)&v68, 0, 0)) / 2 + 101;
      }
      sub_44D406((int)&v68, pFontArrus, v37, v36, v61, v63, v65);
      v66 = 3;
      goto LABEL_59;
    }
    result = sub_4B1784();
    if ( result )
    {
      v45 = dword_507BBC;
      v77 = 0;
      dword_F8B1B8[0] = (int)&TmpBuf;
      dword_F8B1BC = (int)pGlobalTXT_LocalizationStrings[160];
      v46 = *(_DWORD *)(dword_507BBC + 40);
      v78 = *(_DWORD *)(dword_507BBC + 56);
      if ( v78 < v78 + v46 )
      {
        v47 = (const char **)dword_F8B1B8;
        do
        {
          if ( *(_DWORD *)(GUIWindow_GetChild(v45, v78) + 36) == 17 )
          {
            v48 = *(_WORD *)(v3 + 218);
            if ( v48 < v73 )
            {
              v49 = *(_DWORD *)(v3 + 164);
              if ( v49 < HIDWORD(v71) || v49 <= HIDWORD(v71) && *(_DWORD *)(v3 + 160) < (_DWORD)v71 )
              {
                v67 = v48 + 1;
                v64 = v7 - *(_DWORD *)(v3 + 160);
                v62 = pGlobalTXT_LocalizationStrings[538];
              }
              else
              {
                v67 = i;
                v64 = v48 + 1;
                v62 = pGlobalTXT_LocalizationStrings[537];
              }
            }
            else
            {
              v67 = pGlobalTXT_LocalizationStrings[529];
              v64 = pGlobalTXT_LocalizationStrings[536];
              v62 = (int)"%s\n \n%s";
            }
            sprintfex(*v47, (const char *)v62, v64, v67);
          }
          v50 = sub_44C59D(pFontArrus, *v47, (int)&v68, 0, 0);
          v45 = dword_507BBC;
          v77 += v50;
          ++v47;
          ++v78;
        }
        while ( v78 < *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56) );
      }
      HIDWORD(v71) = (174 - v77) / 2;
      result = *(_DWORD *)(v45 + 56);
      v52 = result + *(_DWORD *)(v45 + 40);
      v51 = (2 * (87 - (174 - v77) / 2) - v77) / 2 - (174 - v77) / 2 / 2 + 138;
      v53 = -*(_DWORD *)(v45 + 40) < 0;
      v78 = *(_DWORD *)(v45 + 56);

      compile_error;//if ( v53 ^ __SETO__(result, v52) )
      if (1)
      {
        i = 2;
        v54 = (const char **)dword_F8B1B8;
        do
        {
          v57 = GUIWindow_GetChild(v45, v78);
          v58 = v57;
          *(_DWORD *)(v57 + 4) = HIDWORD(v71) + v51;
          v59 = sub_44C59D(pFontArrus, *v54, (int)&v68, 0, 0);
          v56 = *(_DWORD *)(v58 + 4);
          *(_DWORD *)(v58 + 12) = v59;
          v60 = v59 + v56 - 1;
          *(_DWORD *)(v58 + 20) = v60;
          v51 = v60;
          v55 = v76[0];
          if ( *(_DWORD *)(dword_507BBC + 44) != i )
            v55 = v72;
          sub_44D406((int)&v68, pFontArrus, 0, v56, v55, *v54, 3);
          v45 = dword_507BBC;
          ++i;
          ++v54;
          ++v78;
          result = *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56);
        }
        while ( v78 < result );
      }
    }
  }
  return result;
}

//----- (004B4F4F) --------------------------------------------------------
char *__cdecl sub_4B4F4F()
{
  const char *v1; // esi@1
  const char *v2; // ST10_4@1
  unsigned __int16 v3; // ST0C_2@1
  int v4; // eax@1
  int v5; // [sp+8h] [bp-54h]@1
  int v6; // [sp+10h] [bp-4Ch]@1
  int v7; // [sp+18h] [bp-44h]@1

  memcpy(&v5, (const void *)dword_507BC0, 0x54u);
  v1 = pGlobalTXT_LocalizationStrings[672];
  v2 = pGlobalTXT_LocalizationStrings[672];
  v5 = 483;
  v6 = 148;
  v7 = 334;
  v3 = 0xFFFFFF9B;
  v4 = sub_44C59D(pFontArrus, v1, (int)&v5, 0, 0);
  return sub_44D406((int)&v5, pFontArrus, 0, (310 - v4) / 2 + 18, v3, v2, 3);
}

//----- (004B4FCF) --------------------------------------------------------
signed int __cdecl sub_4B4FCF()
{
  void *v0; // ebx@1
  signed int result; // eax@6
  signed int v2; // esi@8
  int v3; // ebx@10
  int v4; // eax@11
  int v5; // eax@12
  const char *v6; // eax@12
  unsigned __int8 v7; // dl@14
  int v8; // ecx@14
  int v9; // ST08_4@14
  int v10; // eax@14
  signed int v11; // esi@16
  int v12; // ST08_4@19
  int v13; // eax@19
  int v14; // edi@21
  const char **v15; // esi@21
  int v16; // eax@22
  int v17; // ecx@23
  int v18; // edi@23
  int v19; // edx@23
  unsigned __int8 v20; // sf@23
  unsigned __int16 v21; // ax@25
  int v22; // ecx@25
  int v23; // esi@25
  const char **v24; // eax@25
  int v25; // eax@25
  int v26; // edx@25
  signed int v27; // esi@30
  int v28; // ST08_4@34
  int v29; // eax@34
  const char *v30; // edx@35
  int v31; // edi@40
  signed int v32; // esi@40
  int v33; // eax@40
  int v34; // esi@42
  int v35; // eax@42
  int v36; // eax@43
  int v37; // eax@45
  int v38; // ecx@50
  int v39; // eax@52
  int v40; // esi@52
  int v41; // eax@52
  unsigned __int16 v42; // ax@54
  int v43; // ecx@54
  char *v44; // eax@54
  int v45; // eax@54
  int v46; // edx@54
  int v47; // eax@54
  int v48; // eax@58
  signed int v49; // esi@62
  int v50; // ecx@64
  int v51; // edi@64
  int v52; // esi@66
  int v53; // edx@70
  int v54; // ecx@76
  int v55; // edi@76
  int v56; // esi@76
  int v57; // edx@80
  int v58; // ecx@86
  int v59; // edi@86
  int v60; // esi@88
  int v61; // edx@92
  int v62; // ecx@98
  int v63; // edi@98
  int v64; // esi@100
  int v65; // edx@104
  signed int v66; // ecx@109
  bool v67; // eax@117
  SHORT v68; // di@117
  const char *v69; // ecx@119
  int v70; // esi@124
  int v71; // eax@125
  int v72; // ecx@125
  int v73; // esi@125
  int v74; // ecx@125
  int v75; // eax@130
  const char **v76; // edi@131
  int v77; // esi@131
  int v78; // eax@132
  int v79; // ecx@133
  int v80; // edi@133
  int v81; // edx@133
  unsigned __int8 v82; // sf@133
  unsigned __int16 v83; // ax@135
  int v84; // ecx@135
  int v85; // esi@135
  const char **v86; // eax@135
  int v87; // eax@135
  int v88; // edx@135
  int v89; // [sp-18h] [bp-110h]@35
  char v90; // [sp-14h] [bp-10Ch]@35
  int v91; // [sp-10h] [bp-108h]@14
  int v92; // [sp-10h] [bp-108h]@35
  unsigned __int16 v93; // [sp-Ch] [bp-104h]@12
  int v94; // [sp-Ch] [bp-104h]@14
  int v95; // [sp-8h] [bp-100h]@11
  const char *v96; // [sp-8h] [bp-100h]@12
  __int64 *v97; // [sp-4h] [bp-FCh]@11
  int v98; // [sp-4h] [bp-FCh]@12
  char v99; // [sp+Ch] [bp-ECh]@8
  char v100; // [sp+14h] [bp-E4h]@16
  char v101; // [sp+1Ch] [bp-DCh]@124
  char v102; // [sp+24h] [bp-D4h]@17
  char v103; // [sp+2Ch] [bp-CCh]@124
  char v104; // [sp+34h] [bp-C4h]@9
  char v105; // [sp+3Ch] [bp-BCh]@31
  char v106; // [sp+44h] [bp-B4h]@16
  char v107; // [sp+4Ch] [bp-ACh]@30
  char v108; // [sp+54h] [bp-A4h]@16
  char v109; // [sp+5Ch] [bp-9Ch]@30
  char v110; // [sp+64h] [bp-94h]@8
  char v111; // [sp+6Ch] [bp-8Ch]@30
  char v112; // [sp+74h] [bp-84h]@8
  int v113; // [sp+7Ch] [bp-7Ch]@1
  int v114; // [sp+84h] [bp-74h]@1
  int v115; // [sp+8Ch] [bp-6Ch]@1
  char *Str; // [sp+D0h] [bp-28h]@54
  int v117; // [sp+D4h] [bp-24h]@23
  __int16 v118[2]; // [sp+D8h] [bp-20h]@1
  __int16 v119[2]; // [sp+DCh] [bp-1Ch]@1
  int v120; // [sp+E0h] [bp-18h]@8
  int v121; // [sp+E4h] [bp-14h]@40
  int v122; // [sp+E8h] [bp-10h]@24
  int v123; // [sp+ECh] [bp-Ch]@1
  unsigned __int8 v124; // [sp+F3h] [bp-5h]@14
  int v125; // [sp+F4h] [bp-4h]@23

  v0 = *(&ptr_A750C4 + uActiveCharacter);
  v123 = (int)*(&ptr_A750C4 + uActiveCharacter);
  memcpy(&v113, (const void *)dword_507BC0, 0x54u);
  v113 = 483;
  v114 = 148;
  v115 = 334;
  *(_DWORD *)v119 = 0xFFFFFFFF;
  *(_DWORD *)v118 = 0xFFE1CD23;
  if ( dword_F8B19C > 5 )
  {
    if ( dword_F8B19C == 94 )
    {
      sub_41A556();
      GameUI_DrawInventory(uActiveCharacter, 1);
      dword_F8B1B8[0] = pGlobalTXT_LocalizationStrings[200];
      dword_F8B1BC = pGlobalTXT_LocalizationStrings[113];
      dword_F8B1C0 = pGlobalTXT_LocalizationStrings[179];
      v77 = 0;
      v76 = (const char **)dword_F8B1B8;
      do
      {
        v78 = sub_44C59D(pFontArrus, *v76, (int)&v113, 0, 0);
        ++v76;
        v77 += v78;
      }
      while ( (signed int)v76 < (signed int)&dword_F8B1C4 );
      v79 = dword_507BBC;
      v123 = (174 - v77) / 3;
      result = *(_DWORD *)(dword_507BBC + 56);
      v81 = result + *(_DWORD *)(dword_507BBC + 40);
      v80 = (3 * (58 - v123) - v77) / 2 - (174 - v77) / 3 / 2 + 138;
      v82 = -*(_DWORD *)(dword_507BBC + 40) < 0;
      v121 = *(_DWORD *)(dword_507BBC + 56);

      compile_error;//if ( v82 ^ __SETO__(result, v81) )
      if (1)
      {
        v125 = 2;
        v122 = (int)dword_F8B1B8;
        do
        {
          v85 = GUIWindow_GetChild(v79, v121);
          v86 = (const char **)v122;
          *(_DWORD *)(v85 + 4) = v123 + v80;
          v87 = sub_44C59D(pFontArrus, *v86, (int)&v113, 0, 0);
          v84 = *(_DWORD *)(v85 + 4);
          v88 = v125;
          *(_DWORD *)(v85 + 12) = v87;
          v80 = v87 + v84 - 1;
          *(_DWORD *)(v85 + 20) = v80;
          v83 = v118[0];
          if ( *(_DWORD *)(dword_507BBC + 44) != v88 )
            v83 = v119[0];
          sub_44D406((int)&v113, pFontArrus, 0, v84, v83, *(const char **)v122, 3);
          v79 = dword_507BBC;
          ++v125;
          v122 += 4;
          ++v121;
          result = *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56);
        }
        while ( v121 < result );
      }
      return result;
    }
    if ( dword_F8B19C != 95 )
    {
      result = dword_F8B19C - 96;
      if ( dword_F8B19C == 96 )
      {
        result = sub_4B1784();
        if ( result )
        {
          v31 = dword_507BBC;
          v3 = 0;
          v33 = *(_DWORD *)(dword_507BC0 + 28);
          v121 = 0;
          v32 = (signed __int64)(*((float *)&unk_59145C + 13 * v33) * 500.0);
          v122 = v32 * (100 - sub_4911F3((void *)v123)) / 100;
          if ( v122 < v32 / 3 )
            v122 = v32 / 3;
          v34 = *(_DWORD *)(v31 + 56);
          v35 = v34 + *(_DWORD *)(v31 + 40);
          v125 = 0;
          if ( v34 >= v35 )
            goto LABEL_140;
          do
          {
            v36 = *(_DWORD *)(GUIWindow_GetChild(v31, v34) + 36) - 36;
            if ( *(&byte_4ED970[37 * *(_BYTE *)(v123 + 185)] + v36) )
            {
              if ( !*(_WORD *)(v123 + 2 * v36 + 264) )
              {
                //v37 = sub_44C59D(pFontArrus, (&dword_AE32D0)[4 * v36], (int)&v113, 0, 0);
                v37 = sub_44C59D(pFontArrus, aSkillNames[v36], (int)&v113, 0, 0);
                v121 += v37;
                ++v125;
              }
            }
            ++v34;
          }
          while ( v34 < *(_DWORD *)(v31 + 40) + *(_DWORD *)(v31 + 56) );
          if ( !v125 )
          {
LABEL_140:
            sprintfex(
              &TmpBuf,
              pGlobalTXT_LocalizationStrings[544],
              v123 + 168,
              //(&dword_AE31F0)[4 * *(_BYTE *)(v123 + 185)]);
              aClassNames[*(_BYTE *)(v123 + 185)]);
            strcat((char *)&TmpBuf, "\n \n");
            strcat((char *)&TmpBuf, pGlobalTXT_LocalizationStrings[528]);
            v30 = &TmpBuf;
            v98 = 3;
            v96 = &TmpBuf;
            v93 = v118[0];
            v92 = 0;
            v90 = 0;
            v89 = (int)&v113;
            goto LABEL_61;
          }
          sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[401], v122);
          sub_44D406((int)&v113, pFontArrus, 0, 146, 0, &TmpBuf, 3);
          v122 = (149 - v121) / v125;
          if ( (149 - v121) / v125 > 32 )
            v122 = 32;
          result = *(_DWORD *)(v31 + 56);
          v38 = (149 - v125 * v122 - v121) / 2 - v122 / 2 + 162;
          v121 = result;
          v117 = v38;
          if ( result < result + *(_DWORD *)(v31 + 40) )
          {
            v125 = 2;
            do
            {
              v41 = GUIWindow_GetChild(v31, v121);
              v40 = v41;
              v39 = *(_DWORD *)(v41 + 36) - 36;
              if ( !*(&byte_4ED970[37 * *(_BYTE *)(v123 + 185)] + v39) || *(_WORD *)(v123 + 2 * v39 + 264) )
              {
                *(_DWORD *)(v40 + 20) = 0;
                *(_DWORD *)(v40 + 12) = 0;
                *(_DWORD *)(v40 + 4) = 0;
              }
              else
              {
                //v44 = (&dword_AE32D0)[4 * v39];
                v44 = aSkillNames[v39];
                *(_DWORD *)(v40 + 4) = v122 + v117;
                Str = v44;
                v45 = sub_44C59D(pFontArrus, v44, (int)&v113, 0, 0);
                v43 = *(_DWORD *)(v40 + 4);
                v46 = v125;
                *(_DWORD *)(v40 + 12) = v45;
                v47 = v43 + v45 - 1;
                *(_DWORD *)(v40 + 20) = v47;
                v117 = v47;
                v42 = v118[0];
                if ( *(_DWORD *)(dword_507BBC + 44) != v46 )
                  v42 = v119[0];
                sub_44D406((int)&v113, pFontArrus, 0, v43, v42, Str, 3);
              }
              v48 = *(_DWORD *)(v31 + 56);
              ++v121;
              result = *(_DWORD *)(v31 + 40) + v48;
              ++v125;
            }
            while ( v121 < result );
          }
        }
      }
      return result;
    }
  }
  else
  {
    if ( dword_F8B19C == 5 )
    {
      sub_41A556();
      GameUI_DrawInventory(uActiveCharacter, 1);
      sub_4B46A5(pGlobalTXT_LocalizationStrings[198], 0);
      result = sub_4B1784();
      if ( !result
        || (v27 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v111) - 14,
            v120 = (v27 >> 5) + 14 * ((*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v109) + 4) - 17) >> 5),
            result = class03_GetMousePos(pGame->pClass03, (int)&v107),
            *(_DWORD *)result <= 13)
        || (result = class03_GetMousePos(pGame->pClass03, (int)&v105), *(_DWORD *)result >= 462)
        || (result = sub_421E75(v0, (int)&v120), v3 = 0, !result)
        || (result *= 9, !(*(_BYTE *)(v123 + 4 * result + 516) & 2)) )
        return result;
      v97 = 0;
      v95 = 5;
      v94 = *(_DWORD *)(dword_507BC0 + 28);
      v91 = v123 + 4 * result + 496;
      v28 = *(_DWORD *)(dword_507BC0 + 28);
      v124 = uActiveCharacter - 1;
      v29 = sub_490EEE((void *)v123, v123 + 4 * result + 496, 3, v28, 5);
      v7 = v124;
      v8 = *(_DWORD *)&dword_73C3C0[4 * v29];
      goto LABEL_35;
    }
    if ( dword_F8B19C == 1 )
    {
      result = sub_4B1784();
      if ( result )
      {
        dword_F8B1B8[0] = pGlobalTXT_LocalizationStrings[134];
        dword_F8B1BC = pGlobalTXT_LocalizationStrings[152];
        dword_F8B1C0 = pGlobalTXT_LocalizationStrings[636];
        v14 = 0;
        dword_F8B1C4 = pGlobalTXT_LocalizationStrings[160];
        v15 = (const char **)dword_F8B1B8;
        do
        {
          v16 = sub_44C59D(pFontArrus, *v15, (int)&v113, 0, 0);
          ++v15;
          v14 += v16;
        }
        while ( (signed int)v15 < (signed int)&unk_F8B1C8 );
        v17 = dword_507BBC;
        v117 = (174 - v14) / 4;
        result = *(_DWORD *)(dword_507BBC + 56);
        v19 = result + *(_DWORD *)(dword_507BBC + 40);
        v18 = (174 - 4 * (174 - v14) / 4 - v14) / 2 - (174 - v14) / 4 / 2 + 138;
        v20 = -*(_DWORD *)(dword_507BBC + 40) < 0;
        v125 = *(_DWORD *)(dword_507BBC + 56);

        compile_error;//if ( v20 ^ __SETO__(result, v19) )
        if (1)
        {
          v122 = 2;
          v123 = (int)dword_F8B1B8;
          do
          {
            v23 = GUIWindow_GetChild(v17, v125);
            v24 = (const char **)v123;
            *(_DWORD *)(v23 + 4) = v117 + v18;
            v25 = sub_44C59D(pFontArrus, *v24, (int)&v113, 0, 0);
            v22 = *(_DWORD *)(v23 + 4);
            v26 = v122;
            *(_DWORD *)(v23 + 12) = v25;
            v18 = v22 + v25 - 1;
            *(_DWORD *)(v23 + 20) = v18;
            v21 = v118[0];
            if ( *(_DWORD *)(dword_507BBC + 44) != v26 )
              v21 = v119[0];
            sub_44D406((int)&v113, pFontArrus, 0, v22, v21, *(const char **)v123, 3);
            v17 = dword_507BBC;
            ++v122;
            v123 += 4;
            ++v125;
            result = *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56);
          }
          while ( v125 < result );
        }
      }
      return result;
    }
    if ( dword_F8B19C != 2 )
    {
      if ( dword_F8B19C != 3 )
      {
        result = dword_F8B19C - 4;
        if ( dword_F8B19C == 4 )
        {
          sub_41A556();
          GameUI_DrawInventory(uActiveCharacter, 1);
          sub_4B46A5(pGlobalTXT_LocalizationStrings[197], 0);
          result = sub_4B1784();
          if ( result )
          {
            v2 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v110) - 14;
            v120 = (v2 >> 5) + 14 * ((*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v99) + 4) - 17) >> 5);
            result = class03_GetMousePos(pGame->pClass03, (int)&v112);
            if ( *(_DWORD *)result > 13 )
            {
              result = class03_GetMousePos(pGame->pClass03, (int)&v104);
              if ( *(_DWORD *)result < 462 )
              {
                result = sub_421E75(v0, (int)&v120);
                v3 = 0;
                if ( result )
                {
                  v97 = 0;
                  v95 = 4;
                  v4 = v123 + 36 * result + 496;
                  if ( *(_BYTE *)(v4 + 20) & 1 )
                  {
                    v6 = sub_495461("%24", uActiveCharacter - 1, v4, *(_DWORD *)(dword_507BC0 + 28), 4, 0);
                    v98 = 3;
                    v96 = v6;
                    v93 = v119[0];
                    v5 = (212 - sub_44C59D(pFontArrus, v6, (int)&v113, 0, 0)) / 2 + 101;
                    return (signed int)sub_44D406((int)&v113, pFontArrus, v3, v5, v93, v96, v98);
                  }
                  v94 = *(_DWORD *)(dword_507BC0 + 28);
                  v91 = v4;
                  v9 = *(_DWORD *)(dword_507BC0 + 28);
                  v124 = uActiveCharacter - 1;
                  v10 = sub_490EEE((void *)v123, v4, 3, v9, 4);
                  v7 = v124;
                  v8 = dword_73C3DC[v10];
                  goto LABEL_35;
                }
              }
            }
          }
        }
        return result;
      }
      sub_41A556();
      GameUI_DrawInventory(uActiveCharacter, 1);
      sub_4B46A5(pGlobalTXT_LocalizationStrings[199], 0);
      result = sub_4B1784();
      if ( !result
        || (v11 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v108) - 14,
            v120 = (v11 >> 5) + 14 * ((*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v100) + 4) - 17) >> 5),
            result = class03_GetMousePos(pGame->pClass03, (int)&v106),
            *(_DWORD *)result <= 13)
        || (result = class03_GetMousePos(pGame->pClass03, (int)&v102), *(_DWORD *)result >= 462)
        || (result = sub_421E75(v0, (int)&v120), v3 = 0, !result) )
        return result;
      v97 = 0;
      v95 = 3;
      v94 = *(_DWORD *)(dword_507BC0 + 28);
      v91 = v123 + 36 * result + 496;
      v12 = *(_DWORD *)(dword_507BC0 + 28);
      v124 = uActiveCharacter - 1;
      v13 = sub_490EEE((void *)v123, v91, 3, v12, 3);
      v7 = v124;
      v8 = dword_73C3A4[v13];
LABEL_35:
      v30 = sub_495461((char *)v8, v7, v91, v94, v95, v97);
      v98 = 3;
      v96 = v30;
      v93 = v119[0];
      v92 = v3;
      v90 = v3;
      v89 = (int)&v113;
LABEL_61:
      v5 = (174 - sub_44C59D(pFontArrus, v30, v89, v90, v92)) / 2 + 138;
      return (signed int)sub_44D406((int)&v113, pFontArrus, v3, v5, v93, v96, v98);
    }
  }
  Render_DrawIndexedTexture(pD3DRenderer, 8, 8, dword_F8B164[0]);
  v3 = 0;
  v49 = 0;
  v125 = 0;
  if ( dword_F8B19C == 2 )
  {
    do
    {
      if ( dword_AD4734[9 * (v49 + 12 * *(_DWORD *)(dword_507BC0 + 28))] )
      {
        v50 = dword_F8B168[v49];
        v51 = 152 - *(_WORD *)(v50 + 26);
        if ( v51 < 1 )
          v51 = 0;
        v52 = 75 * v49 - *(_WORD *)(v50 + 24) / 2 + 40;
        if ( v125 )
        {
          if ( v125 == 5 )
          {
            v53 = *(_WORD *)(dword_F8B17C + 24);
            if ( v52 > 457 - v53 )
              v52 = 457 - v53;
          }
        }
        else
        {
          if ( v52 < 18 )
            v52 = 18;
        }
        Render_DrawTransparentTexture(pD3DRenderer, v52, v51, v50);
        sub_40F92A(pD3DRenderer->pActiveZBuffer + 4 * (v52 + 640 * v51), dword_F8B168[v125], v125 + 1);
        v49 = v125;
      }
      ++v49;
      v125 = v49;
    }
    while ( v49 < 6 );
    v125 = 0;
    do
    {
      if ( dword_AD480C[9 * (v125 + 12 * *(_DWORD *)(dword_507BC0 + 28))] )
      {
        v54 = dword_F8B180[v125];
        v55 = 306 - *(_WORD *)(v54 + 26);
        v56 = 75 * v125 - *(_WORD *)(v54 + 24) / 2 + 40;
        if ( v125 )
        {
          if ( v125 == 5 )
          {
            v57 = *(_WORD *)(dword_F8B194 + 24);
            if ( v56 > 457 - v57 )
              v56 = 457 - v57;
          }
        }
        else
        {
          if ( v56 < 18 )
            v56 = 18;
        }
        Render_DrawTransparentTexture(pD3DRenderer, v56, v55, v54);
        sub_40F92A(pD3DRenderer->pActiveZBuffer + 4 * (v56 + 640 * v55), dword_F8B180[v125], v125 + 7);
      }
      ++v125;
    }
    while ( v125 < 6 );
  }
  else
  {
    do
    {
      if ( *(&dword_ADA0A4 + 9 * (v49 + 12 * *(_DWORD *)(dword_507BC0 + 28))) )
      {
        v58 = dword_F8B168[v49];
        v59 = 152 - *(_WORD *)(v58 + 26);
        if ( v59 < 1 )
          v59 = 0;
        v60 = 75 * v49 - *(_WORD *)(v58 + 24) / 2 + 40;
        if ( v125 )
        {
          if ( v125 == 5 )
          {
            v61 = *(_WORD *)(dword_F8B17C + 24);
            if ( v60 > 457 - v61 )
              v60 = 457 - v61;
          }
        }
        else
        {
          if ( v60 < 18 )
            v60 = 18;
        }
        Render_DrawTransparentTexture(pD3DRenderer, v60, v59, v58);
        sub_40F92A(pD3DRenderer->pActiveZBuffer + 4 * (v60 + 640 * v59), dword_F8B168[v125], v125 + 1);
        v49 = v125;
      }
      ++v49;
      v125 = v49;
    }
    while ( v49 < 6 );
    v125 = 0;
    do
    {
      if ( dword_ADA17C[9 * (v125 + 12 * *(_DWORD *)(dword_507BC0 + 28))] )
      {
        v62 = dword_F8B180[v125];
        v63 = 306 - *(_WORD *)(v62 + 26);
        if ( v63 < 1 )
          v63 = 0;
        v64 = 75 * v125 - *(_WORD *)(v62 + 24) / 2 + 40;
        if ( v125 )
        {
          if ( v125 == 5 )
          {
            v65 = *(_WORD *)(dword_F8B194 + 24);
            if ( v64 > 457 - v65 )
              v64 = 457 - v65;
          }
        }
        else
        {
          if ( v64 < 18 )
            v64 = 18;
        }
        Render_DrawTransparentTexture(pD3DRenderer, v64, v63, v62);
        sub_40F92A(pD3DRenderer->pActiveZBuffer + 4 * (v64 + 640 * v63), dword_F8B180[v125], v125 + 7);
      }
      ++v125;
    }
    while ( v125 < 6 );
  }
  result = sub_4B1784();
  if ( result )
  {
    v66 = 0;
    v120 = 0;
    if ( dword_F8B19C == 2 )
    {
      do
      {
        if ( dword_AD4734[9 * (v66 + 12 * *(_DWORD *)(dword_507BC0 + 28))] )
          ++v120;
        ++v66;
      }
      while ( v66 < 12 );
    }
    else
    {
      do
      {
        if ( *(&dword_ADA0A4 + 9 * (v66 + 12 * *(_DWORD *)(dword_507BC0 + 28))) )
          ++v120;
        ++v66;
      }
      while ( v66 < 12 );
    }
    v68 = GetAsyncKeyState(17);
    v67 = sub_492C40((void *)v123);
    Str = (char *)v67;
    if ( v68 && v67 )
    {
      v69 = pGlobalTXT_LocalizationStrings[185];
    }
    else
    {
      v69 = pGlobalTXT_LocalizationStrings[195];
      if ( dword_F8B19C != 2 )
        v69 = pGlobalTXT_LocalizationStrings[196];
    }
    sub_4B46A5(v69, 0);
    if ( !v120 )
      compile_error;//return (signed int)sub_4B1854(
                    //       &v113,
                    //       __PAIR__(
                    //         dword_ACD048[2 * *(_DWORD *)(dword_507BC0 + 28)],
                    //         dword_ACD044[2 * *(_DWORD *)(dword_507BC0 + 28)])
                    //     - pParty_global->qword_00002C);
    v70 = class03_GetMousePos(pGame->pClass03, (int)&v103);
    result = *(_DWORD *)v70 + dword_5059A8[*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v101) + 4)];
    if ( *(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * result) & 0xFFFF )
    {
      v74 = (*(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * result) & 0xFFFF) - 1;
      v120 = v74;
      v71 = *(_DWORD *)(dword_507BC0 + 28);
      v72 = 9 * (v74 + 12 * v71);
      v73 = 4 * v72 + 11355956;
      if ( dword_F8B19C != 2 )
        v73 = 4 * v72 + 11378852;
      if ( v68 && Str )
      {
        v8 = pGlobalTXT_LocalizationStrings[181];
        v97 = 0;
        v95 = 2;
        v94 = *(_DWORD *)(dword_507BC0 + 28);
        v91 = v73;
        v7 = uActiveCharacter - 1;
      }
      else
      {
        v97 = 0;
        v95 = 2;
        v94 = *(_DWORD *)(dword_507BC0 + 28);
        v91 = v73;
        v124 = uActiveCharacter - 1;
        v75 = sub_490EEE((void *)v123, v73, 3, v71, 2);
        v7 = v124;
        v8 = *(_DWORD *)&dword_73C388[4 * v75];
      }
      goto LABEL_35;
    }
  }
  return result;
}

//----- (004B5D7C) --------------------------------------------------------
signed int __cdecl sub_4B5D7C() //buy skills in shop
{
  signed int v0; // ebx@1
  void *v1; // edi@1
  int v2; // ebx@1
  int v3; // edi@6
  signed int result; // eax@11
  int v5; // ebx@13
  int v6; // esi@13
  signed int v7; // esi@17
  int *v8; // eax@22
  signed int v9; // ecx@22
  int v10; // esi@22
  const char *v11; // ecx@26
  int v12; // ecx@30
  int v13; // esi@30
  const char *v14; // edx@31
  int v15; // ST1C_4@31
  int v16; // ST18_4@31
  int v17; // ST10_4@31
  int v18; // eax@31
  int v19; // eax@32
  int v20; // edi@35
  int v21; // esi@35
  int v22; // eax@35
  int v23; // eax@36
  int v24; // eax@39
  int v25; // eax@40
  int v26; // ecx@47
  int v27; // eax@49
  int v28; // esi@49
  int v29; // eax@49
  char *v30; // eax@52
  unsigned __int16 v31; // ax@55
  int v32; // ecx@55
  int v33; // eax@55
  int v34; // eax@55
  int v35; // eax@58
  const char *v36; // ST20_4@61
  unsigned __int16 v37; // ST1C_2@61
  int v38; // eax@61
  int v39; // [sp-18h] [bp-304h]@31
  char v40; // [sp-14h] [bp-300h]@31
  int v41; // [sp-10h] [bp-2FCh]@31
  unsigned __int16 v42; // [sp-Ch] [bp-2F8h]@31
  const char *v43; // [sp-8h] [bp-2F4h]@31
  int v44; // [sp-4h] [bp-2F0h]@31
  char Dest; // [sp+Ch] [bp-2E0h]@3
  char v46; // [sp+70h] [bp-27Ch]@3
  char v47; // [sp+D4h] [bp-218h]@3
  char v48; // [sp+138h] [bp-1B4h]@3
  char v49; // [sp+19Ch] [bp-150h]@3
  char v50; // [sp+264h] [bp-88h]@30
  char v51; // [sp+26Ch] [bp-80h]@30
  int v52; // [sp+274h] [bp-78h]@1
  int v53; // [sp+27Ch] [bp-70h]@1
  int v54; // [sp+284h] [bp-68h]@1
  int v55; // [sp+2C8h] [bp-24h]@47
  __int16 v56[2]; // [sp+2CCh] [bp-20h]@1
  __int16 v57[2]; // [sp+2D0h] [bp-1Ch]@1
  int v58; // [sp+2D4h] [bp-18h]@1
  unsigned __int8 v59; // [sp+2DBh] [bp-11h]@31
  char *Str; // [sp+2DCh] [bp-10h]@35
  int v61; // [sp+2E0h] [bp-Ch]@35
  int v62; // [sp+2E4h] [bp-8h]@13
  int v63; // [sp+2E8h] [bp-4h]@1

  v2 = dword_507BC0;
  memcpy(&v52, (const void *)dword_507BC0, 0x54u);
  v58 = (int)*(&ptr_A750C4 + uActiveCharacter);
  v1 = (void *)v58;
  v52 = 483;
  v53 = 148;
  v54 = 334;
  *(_DWORD *)v56 = 0xFFFFFFFF;
  *(_DWORD *)v57 = 0xFFFFFF9B;
  v0 = (signed __int64)(*((float *)&unk_591458 + 13 * *(_DWORD *)(v2 + 28)) * 500.0);
  v63 = v0 * (100 - sub_4911F3(v1)) / 100;
  if ( v63 < v0 / 3 )
    v63 = v0 / 3;
  strcpy(&Dest, Class);
  strcpy(&v46, Class);
  strcpy(&v47, Class);
  strcpy(&v48, Class);
  strcpy(&v49, Class);
  if ( dword_F8B19C != 1 )
  {
    if ( dword_F8B19C != 18 )
    {
      if ( sub_4B1784() )
      {
        v3 = (int)((char *)v1 + 2 * dword_F8B19C + 192);
        if ( *(_WORD *)v3 )
        {
          //sprintfex(&TmpBuf, (const char *)dword_5E47CC, (&dword_AE3240)[4 * dword_F8B19C]);
          sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[403], aClassNames[20 + dword_F8B19C]);
          sub_44C175(&TmpBuf, 2);
          AudioPlayer_sub_4AA306(pAudioPlayer, 27, 0, 0, -1, 0, 0, 0, 0);
        }
        else
        {
          if ( pParty_global->uNumGold < (unsigned int)v63 )
          {
            sub_44C175(pGlobalTXT_LocalizationStrings[155], 2);
            sub_4B1E92(*(_DWORD *)(dword_507BC0 + 28), 2);
          }
          else
          {
            sub_492BB6(v63);
            *(_WORD *)v3 = 1;
          }
        }
      }
      result = dword_50CBD0[0];
      if ( dword_50CBD0[0] < 40 )
      {
        dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
        dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
        result = 3 * dword_50CBD0[0] + 3;
        dword_50CBD0[result] = 0;
        ++dword_50CBD0[0];
      }
      return result;
    }
    Render_DrawIndexedTexture(pD3DRenderer, 8, 8, dword_F8B164[0]);
    v5 = 0;
    v6 = 0;
    v62 = 0;
    v63 = 32;
    do
    {
      if ( dword_AD0F84[9 * (v6 + 12 * *(_DWORD *)(dword_507BC0 + 28))] )
      {
        Render_DrawTransparentTexture(pD3DRenderer, v63, 90, dword_F8B168[v6]);
        array_40F89C_ActuallyFillZBuffer(v62 + pD3DRenderer->pActiveZBuffer + 230528, dword_F8B168[v6], v6 + 1);
        v1 = (void *)v58;
      }
      v63 += 70;
      v62 += 280;
      ++v6;
    }
    while ( v63 < 452 );
    v62 = 1680;
    v7 = 6;
    v63 = 32;
    do
    {
      if ( dword_AD0F84[9 * (v7 + 12 * *(_DWORD *)(dword_507BC0 + 28))] )
      {
        Render_DrawTransparentTexture(pD3DRenderer, v63, 250, dword_F8B168[v7]);
        array_40F89C_ActuallyFillZBuffer(v62 + pD3DRenderer->pActiveZBuffer + 638448, dword_F8B168[v7], v7 + 1);
        v1 = (void *)v58;
      }
      v63 += 70;
      v62 += 280;
      ++v7;
    }
    while ( v63 < 452 );
    result = sub_4B1784();
    if ( result )
    {
      v10 = 0;
      v9 = 12;
      v8 = &dword_AD0F84[108 * *(_DWORD *)(dword_507BC0 + 28)];
      do
      {
        if ( *v8 )
          ++v10;
        v8 += 9;
        --v9;
      }
      while ( v9 );
      GetAsyncKeyState(17);
      v11 = pGlobalTXT_LocalizationStrings[195];
      if ( dword_F8B19C != 2 )
        v11 = pGlobalTXT_LocalizationStrings[196];
      sub_4B46A5(v11, 0);
      if ( !v10 )
        compile_error;//return (signed int)sub_4B1854(
                      //       &v52,
                      //       __PAIR__(
                      //         dword_ACCD98[2 * *(_DWORD *)(dword_507BC0 + 28)],
                      //         dword_ACCD94[2 * *(_DWORD *)(dword_507BC0 + 28)])
                      //     - pParty_global->qword_00002C);
      v13 = class03_GetMousePos(pGame->pClass03, (int)&v51);
      result = *(_DWORD *)v13 + dword_5059A8[*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v50) + 4)];
      v12 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * result) & 0xFFFF;
      if ( *(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * result) & 0xFFFF )
      {
        v15 = *(_DWORD *)(dword_507BC0 + 28);
        v16 = 36 * (v12 + 12 * v15) + 11341664;
        v17 = *(_DWORD *)(dword_507BC0 + 28);
        v59 = uActiveCharacter - 1;
        v18 = sub_490EEE(v1, 36 * (v12 + 12 * v15) + 11341664, 3, v17, 2);
        v14 = sub_495461(*(char **)&dword_73C388[4 * v18], v59, v16, v15, 2, 0);
        v44 = 3;
        v43 = v14;
        v42 = v56[0];
        v41 = 0;
        v40 = 0;
        v39 = (int)&v52;
LABEL_32:
        v19 = sub_44C59D(pFontArrus, v14, v39, v40, v41);
        return (signed int)sub_44D406((int)&v52, pFontArrus, v5, (174 - v19) / 2 + 138, v42, v43, v44);
      }
    }
    return result;
  }
  if ( !(unsigned __int16)sub_449B57((int)((char *)v1 + 338), word_4F0704[2 * *(_DWORD *)(dword_507BC0 + 28)]) )
  {
    v36 = dword_721A34;
    v37 = v57[0];
    v38 = sub_44C59D(pFontArrus, dword_721A34, (int)&v52, 0, 0);
    sub_44D406((int)&v52, pFontArrus, 0, (212 - v38) / 2 + 101, v37, v36, 3);
    result = dword_507BBC;
    *(_DWORD *)(dword_507BBC + 40) = 0;
    return result;
  }
  result = sub_4B1784();
  if ( !result )
    return result;
  v20 = dword_507BBC;
  v5 = 0;
  v62 = 0;
  Str = 0;
  v21 = *(_DWORD *)(dword_507BBC + 56);
  v22 = v21 + *(_DWORD *)(dword_507BBC + 40);
  v61 = 0;
  if ( v21 >= v22 )
    goto LABEL_64;
  do
  {
    v23 = *(_DWORD *)(GUIWindow_GetChild(v20, v21) + 36);
    if ( v23 == 18 )
    {
      v25 = sub_44C59D(pFontArrus, pGlobalTXT_LocalizationStrings[400], (int)&v52, 0, 0);
      v62 += v25;
      ++v61;
    }
    else
    {
      if ( *(&byte_4ED94C[37 * *(_BYTE *)(v58 + 185)] + v23) )
      {
        if ( !*(_WORD *)(v58 + 2 * v23 + 192) )
        {
          //v24 = sub_44C59D(pFontArrus, (&dword_AE3240)[4 * v23], (int)&v52, 0, 0);
          v24 = sub_44C59D(pFontArrus, aClassNames[20 + v23], (int)&v52, 0, 0);
          v62 += v24;
          ++v61;
          ++Str;
        }
      }
    }
    ++v21;
  }
  while ( v21 < *(_DWORD *)(v20 + 40) + *(_DWORD *)(v20 + 56) );
  if ( !v61 )
  {
LABEL_64:
    //sprintfex(&TmpBuf, (const char *)dword_5E4A00, v58 + 168, (&dword_AE31F0)[4 * *(_BYTE *)(v58 + 185)]);
    sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[544], v58 + 168, aClassNames[*(_BYTE *)(v58 + 185)]);

    strcat((char *)&TmpBuf, "\n \n");
    strcat((char *)&TmpBuf, pGlobalTXT_LocalizationStrings[528]);
    v14 = &TmpBuf;
    v44 = 3;
    v43 = &TmpBuf;
    v42 = v57[0];
    v41 = 0;
    v40 = 0;
    v39 = (int)&v52;
    goto LABEL_32;
  }
  if ( Str )
  {
    sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[401], v63);
    sub_44D406((int)&v52, pFontArrus, 0, 146, 0, &TmpBuf, 3);
  }
  v63 = (149 - v62) / v61;
  if ( v63 > 32 )
    v63 = 32;
  result = *(_DWORD *)(v20 + 56);
  v26 = (149 - v61 * v63 - v62) / 2 - v63 / 2 + 162;
  v62 = result;
  v55 = v26;
  if ( result < result + *(_DWORD *)(v20 + 40) )
  {
    v61 = 2;
    while ( 1 )
    {
      v29 = GUIWindow_GetChild(v20, v62);
      v28 = v29;
      v27 = *(_DWORD *)(v29 + 36);
      if ( v27 == 18 )
        break;
      if ( *(&byte_4ED94C[37 * *(_BYTE *)(v58 + 185)] + v27) && !*(_WORD *)(v58 + 2 * v27 + 192) )
      {
        //v30 = (&dword_AE3240)[4 * v27];
        v30 = aClassNames[20 + v27];

LABEL_55:
        Str = v30;
        *(_DWORD *)(v28 + 4) = v63 + v55;
        v33 = sub_44C59D(pFontArrus, v30, (int)&v52, 0, 0);
        v32 = *(_DWORD *)(v28 + 4);
        *(_DWORD *)(v28 + 12) = v33;
        v34 = v32 + v33 - 1;
        *(_DWORD *)(v28 + 20) = v34;
        v55 = v34;
        v31 = v57[0];
        if ( *(_DWORD *)(dword_507BBC + 44) != v61 )
          v31 = v56[0];
        sub_44D406((int)&v52, pFontArrus, 0, v32, v31, Str, 3);
        goto LABEL_58;
      }
      *(_DWORD *)(v28 + 20) = 0;
      *(_DWORD *)(v28 + 12) = 0;
      *(_DWORD *)(v28 + 4) = 0;
LABEL_58:
      v35 = *(_DWORD *)(v20 + 56);
      ++v62;
      result = *(_DWORD *)(v20 + 40) + v35;
      ++v61;
      if ( v62 >= result )
        return result;
    }
    v30 = pGlobalTXT_LocalizationStrings[400];
    goto LABEL_55;
  }
  return result;
}

//----- (004B6478) --------------------------------------------------------
signed int __cdecl sub_4B6478()
{
  int v0; // ebx@1
  int v1; // edi@1
  signed int v2; // esi@1
  int v3; // ebx@1
  int v4; // eax@1
  int v5; // esi@5
  int v6; // edi@6
  signed int result; // eax@13
  int v8; // ebx@17
  int v9; // eax@17
  int v10; // ecx@17
  int v11; // ecx@18
  int v12; // eax@20
  int v13; // eax@21
  int v14; // ecx@27
  int v15; // esi@27
  int v16; // eax@28
  unsigned __int16 v17; // ax@29
  int v18; // ecx@29
  const char *v19; // ebx@29
  int v20; // eax@29
  int v21; // eax@29
  unsigned __int16 v22; // ST14_2@36
  int v23; // eax@36
  const char *v24; // ST18_4@37
  unsigned __int16 v25; // ST14_2@37
  int v26; // eax@37
  int v27; // [sp-4h] [bp-80h]@8
  int v28; // [sp+Ch] [bp-70h]@1
  int v29; // [sp+14h] [bp-68h]@1
  int v30; // [sp+1Ch] [bp-60h]@1
  int v31; // [sp+60h] [bp-1Ch]@17
  unsigned int v32; // [sp+64h] [bp-18h]@1
  __int16 v33[2]; // [sp+68h] [bp-14h]@1
  int v34; // [sp+6Ch] [bp-10h]@1
  int v35; // [sp+70h] [bp-Ch]@17
  int v36; // [sp+74h] [bp-8h]@17
  int v37; // [sp+78h] [bp-4h]@17

  v3 = dword_507BC0;
  memcpy(&v28, (const void *)dword_507BC0, 0x54u);
  v1 = (int)*(&ptr_A750C4 + uActiveCharacter);
  v28 = 483;
  v29 = 148;
  v30 = 334;
  v32 = 0xFFFFFFFF;
  *(_DWORD *)v33 = 0xFFFFFF9B;
  v4 = 52 * *(_DWORD *)(v3 + 28);
  v34 = (((*(__int16 *)((char *)word_591438 + v4) != 18) - 1) & 0x96) + 100;
  v2 = (signed __int64)((double)v34 * *(float *)(v4 + 5837912));
  v0 = v2 * (100 - sub_4911F3((void *)v1)) / 100;
  v34 = v0;
  if ( v0 < v2 / 3 )
  {
    v0 = v2 / 3;
    v34 = v2 / 3;
  }
  if ( dword_F8B19C != 1 )
  {
    if ( sub_4B1784() )
    {
      v5 = 0;
      if ( !*(&byte_4ED94C[37 * *(_BYTE *)(v1 + 185) / 3] + dword_F8B19C)
        || (v6 = v1 + 2 * dword_F8B19C + 192, *(_WORD *)v6) )
      {
        AudioPlayer_sub_4AA306(pAudioPlayer, 27, 0, 0, -1, 0, 0, 0, 0);
      }
      else
      {
        if ( pParty_global->uNumGold < (unsigned int)v0 )
        {
          sub_44C175(pGlobalTXT_LocalizationStrings[155], 2);
          v27 = 4;
        }
        else
        {
          sub_492BB6(v0);
          *(_WORD *)v6 = 1;
          v27 = 2;
        }
        sub_4B1E92(*(_DWORD *)(dword_507BC0 + 28), v27);
      }
    }
    else
    {
      v5 = 0;
    }
    result = dword_50CBD0[0];
    if ( dword_50CBD0[0] < 40 )
    {
      dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
      dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
      result = 3 * dword_50CBD0[0] + 3;
      dword_50CBD0[result] = v5;
      ++dword_50CBD0[0];
    }
    return result;
  }
  if ( !(unsigned __int16)sub_449B57(v1 + 338, word_4F0754[2 * *(_DWORD *)(dword_507BC0 + 28)]) )
  {
    v24 = dword_721BC4;
    v25 = v33[0];
    v26 = sub_44C59D(pFontArrus, dword_721BC4, (int)&v28, 0, 0);
    sub_44D406((int)&v28, pFontArrus, 0, (212 - v26) / 2 + 101, v25, v24, 3);
    result = dword_507BBC;
    *(_DWORD *)(dword_507BBC + 40) = 0;
    return result;
  }
  result = sub_4B1784();
  if ( !result )
    return result;
  v8 = dword_507BBC;
  v35 = 0;
  v36 = 0;
  v31 = dword_507BBC;
  v9 = *(_DWORD *)(dword_507BBC + 56);
  v10 = v9 + *(_DWORD *)(dword_507BBC + 40);
  v37 = *(_DWORD *)(dword_507BBC + 56);
  if ( v9 >= v10 )
    goto LABEL_40;
  do
  {
    v11 = *(_DWORD *)(GUIWindow_GetChild(v8, v37) + 36) - 36;
    if ( *(&byte_4ED970[37 * *(_BYTE *)(v1 + 185) / 3] + v11) )
    {
      if ( !*(_WORD *)(v1 + 2 * v11 + 264) )
      {
        //v12 = sub_44C59D(pFontArrus, (&dword_AE32D0)[4 * v11], (int)&v28, 0, 0);
        v12 = sub_44C59D(pFontArrus, aSkillNames[v11], (int)&v28, 0, 0);
        v35 += v12;
        ++v36;
      }
    }
    v13 = *(_DWORD *)(v8 + 56);
    ++v37;
  }
  while ( v37 < *(_DWORD *)(v8 + 40) + v13 );
  if ( !v36 )
  {
LABEL_40:
    //sprintfex(&TmpBuf, (const char *)dword_5E4A00, v1 + 168, (&dword_AE31F0)[4 * *(_BYTE *)(v1 + 185)]);
    sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[544], v1 + 168, aClassNames[*(_BYTE *)(v1 + 185)]);

    strcat((char *)&TmpBuf, "\n \n");
    strcat((char *)&TmpBuf, pGlobalTXT_LocalizationStrings[528]);
    v22 = v33[0];
    v23 = sub_44C59D(pFontArrus, &TmpBuf, (int)&v28, 0, 0);
    return (signed int)sub_44D406((int)&v28, pFontArrus, 0, (174 - v23) / 2 + 138, v22, &TmpBuf, 3);
  }
  sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[401], v34);
  sub_44D406((int)&v28, pFontArrus, 0, 146, 0, &TmpBuf, 3);
  v34 = (149 - v35) / v36;
  if ( (149 - v35) / v36 > 32 )
    v34 = 32;
  result = *(_DWORD *)(v8 + 56);
  v37 = result;
  v36 = (149 - v36 * v34 - v35) / 2 - v34 / 2 + 162;
  if ( result < result + *(_DWORD *)(v8 + 40) )
  {
    v35 = 2;
    do
    {
      v15 = GUIWindow_GetChild(v8, v37);
      v14 = *(_DWORD *)(v15 + 36) - 36;
      if ( *(&byte_4ED970[37 * *(_BYTE *)(v1 + 185) / 3] + v14) )
      {
        v16 = 0;
        if ( !*(_WORD *)(v1 + 2 * v14 + 264) )
        {
          //v19 = (&dword_AE32D0)[4 * v14];
          v19 = aSkillNames[v14];
          *(_DWORD *)(v15 + 4) = v34 + v36;
          v20 = sub_44C59D(pFontArrus, v19, (int)&v28, 0, 0);
          v18 = *(_DWORD *)(v15 + 4);
          *(_DWORD *)(v15 + 12) = v20;
          v21 = v18 + v20 - 1;
          *(_DWORD *)(v15 + 20) = v21;
          v36 = v21;
          v17 = v33[0];
          if ( *(_DWORD *)(dword_507BBC + 44) != v35 )
            v17 = v32;
          sub_44D406((int)&v28, pFontArrus, 0, v18, v17, v19, 3);
          goto LABEL_34;
        }
      }
      else
      {
        v16 = 0;
      }
      *(_DWORD *)(v15 + 20) = v16;
      *(_DWORD *)(v15 + 12) = v16;
      *(_DWORD *)(v15 + 4) = v16;
LABEL_34:
      v8 = v31;
      ++v37;
      ++v35;
      result = *(_DWORD *)(v31 + 40) + *(_DWORD *)(v31 + 56);
    }
    while ( v37 < result );
  }
  return result;
}

//----- (004B68EA) --------------------------------------------------------
signed int __fastcall sub_4B68EA(int a1)
{
  signed int v1; // edi@1
  int v2; // esi@1
  int v3; // ecx@2

  v1 = 0;
  v2 = 4 * a1 + 5180944;
  while ( 1 )
  {
    v3 = 32 * *(_BYTE *)(v2 + v1);
    if ( *(&byte_4F09B1[pParty_global->uDaysPlayed % 7u] + v3) )
    {
      if ( !*(_DWORD *)((char *)&unk_4F09CC + v3)
        || (unsigned __int16)sub_449B57((int)byte_ACD71D, *(_WORD *)((char *)&unk_4F09CC + v3)) )
        break;
    }
    ++v1;
    if ( v1 >= 4 )
      return 0;
  }
  return 1;
}

//----- (004B6943) --------------------------------------------------------
void __cdecl sub_4B6943()
{
  signed int v0; // ebx@1
  signed int v1; // edi@1
  int v2; // ebx@1
  void *v3; // esi@1
  int v4; // eax@1
  char *v5; // esi@7
  int v6; // eax@9
  int v7; // eax@9
  int v8; // eax@12
  int v9; // edi@12
  int v10; // edx@12
  int v11; // ecx@12
  signed int v12; // esi@13
  signed int v13; // edi@14
  int v14; // eax@15
  int v15; // eax@17
  int v16; // eax@20
  int v17; // eax@22
  DWORD v18; // eax@26
  DWORD v19; // edi@26
  int v20; // ebx@36
  int v21; // esi@36
  int v22; // eax@36
  int v23; // ecx@36
  int v24; // esi@36
  int v25; // eax@36
  int v26; // ebx@39
  void *v27; // esi@39
  int v28; // eax@39
  signed int v29; // eax@41
  int v30; // esi@44
  int v31; // eax@46
  int v32; // eax@50
  int v33; // eax@52
  int v34; // eax@55
  int v35; // eax@57
  char *v36; // eax@62
  int v37; // eax@62
  int v38; // ecx@62
  char *v39; // eax@63
  int v40; // eax@67
  char v41; // [sp-3Ch] [bp-2CCh]@62
  int v42; // [sp-38h] [bp-2C8h]@62
  int v43; // [sp-34h] [bp-2C4h]@62
  int v44; // [sp-30h] [bp-2C0h]@62
  int v45; // [sp-2Ch] [bp-2BCh]@62
  int v46; // [sp-28h] [bp-2B8h]@62
  int v47; // [sp-24h] [bp-2B4h]@62
  int v48; // [sp-20h] [bp-2B0h]@62
  int v49; // [sp-1Ch] [bp-2ACh]@62
  int v50; // [sp-18h] [bp-2A8h]@62
  int v51; // [sp-14h] [bp-2A4h]@62
  const CHAR *v52; // [sp-10h] [bp-2A0h]@62
  char *v53; // [sp-Ch] [bp-29Ch]@62
  char *v54; // [sp-8h] [bp-298h]@62
  char *v55; // [sp-4h] [bp-294h]@62
  const char *v56[5]; // [sp+0h] [bp-290h]@7
  char v57; // [sp+14h] [bp-27Ch]@37
  char v58; // [sp+78h] [bp-218h]@68
  char v59; // [sp+DCh] [bp-1B4h]@68
  char v60; // [sp+140h] [bp-150h]@68
  char Dest; // [sp+1A4h] [bp-ECh]@36
  int v62; // [sp+208h] [bp-88h]@1
  int v63; // [sp+210h] [bp-80h]@1
  int v64; // [sp+218h] [bp-78h]@1
  int v65; // [sp+25Ch] [bp-34h]@36
  int v66; // [sp+260h] [bp-30h]@36
  unsigned int v67; // [sp+264h] [bp-2Ch]@1
  __int16 v68[2]; // [sp+268h] [bp-28h]@1
  void *v69; // [sp+26Ch] [bp-24h]@36
  int v70; // [sp+270h] [bp-20h]@1
  int v71; // [sp+274h] [bp-1Ch]@36
  void *v72; // [sp+278h] [bp-18h]@1
  int v73; // [sp+27Ch] [bp-14h]@36
  int v74; // [sp+280h] [bp-10h]@14
  char *v75; // [sp+284h] [bp-Ch]@37
  int v76; // [sp+288h] [bp-8h]@1
  int v77; // [sp+28Ch] [bp-4h]@48

  v2 = dword_507BC0;
  memcpy(&v62, (const void *)dword_507BC0, 0x54u);
  v1 = 255;
  v72 = *(&ptr_A750C4 + uActiveCharacter);
  v3 = v72;
  v62 = 483;
  v63 = 148;
  v64 = 334;
  *(_DWORD *)v68 = 0xFFFFFFFF;
  v67 = 0xFFFFFF9B;
  v4 = 52 * *(_DWORD *)(v2 + 28);
  v70 = (((*(__int16 *)((char *)word_591438 + v4) != 27) - 1) & 0xFFFFFFE7) + 50;
  v0 = (signed __int64)((double)v70 * *(float *)(v4 + 5837912));
  v76 = v0 * (100 - sub_4911F3(v3)) / 100;
  if ( v76 < v0 / 3 )
    v76 = v0 / 3;
  if ( dword_F8B19C == 1 )
  {
    if ( sub_4B1784() )
    {
      v20 = dword_507BBC;
      v69 = (void *)-1;
      v73 = 0;
      v21 = *(_BYTE *)(pFontArrus + 5) - 3;
      v70 = dword_507BBC;
      v65 = v21;
      strcpy(&Dest, Class);
      sprintfex(pStringBuffer, pGlobalTXT_LocalizationStrings[405], v76);
      v22 = sub_44C59D(pFontArrus, pStringBuffer, (int)&v62, 0, 0);
      v23 = *(_DWORD *)(v20 + 40);
      v24 = v22 + v21 + 146;
      v25 = *(_DWORD *)(v20 + 56);
      v74 = v24;
      v66 = v24;
      v71 = v25;
      if ( v25 >= v25 + v23 )
        goto LABEL_71;
      v76 = 2;
      v75 = &v57;
      while ( 1 )
      {
        v56[1] = (const char *)v71;
        v28 = *(_DWORD *)(dword_507BC0 + 28);
        v27 = (void *)(unsigned __int8)*(&byte_4F0D38[4 * v28] + v73);
        v72 = (void *)(unsigned __int8)*(&byte_4F0D38[4 * v28] + v73);
        v26 = GUIWindow_GetChild(v20, v71);
        if ( v27 != v69
          && (v76 >= 6 ? (v29 = 1) : (v29 = (unsigned __int8)*(&byte_4F09B1[32 * (_DWORD)v27] + pParty_global->uDaysPlayed % 7u)),
              v29
           && ((v30 = 32 * (_DWORD)v27, !*(_DWORD *)((char *)&unk_4F09CC + v30))
            || (unsigned __int16)sub_449B57((int)byte_ACD71D, *(_WORD *)((char *)&unk_4F09CC + v30)))) )
        {
          v69 = v72;
          v31 = v67;
          if ( *(_DWORD *)(dword_507BBC + 44) != v76 )
            v31 = *(_DWORD *)v68;
          v56[1] = (const char *)v31;
          sprintfex(v75, (const char *)&unk_4E2DC8, v31);
          v77 = (unsigned __int8)byte_4F09B8[v30];
          if ( *(_DWORD *)(dword_507BC0 + 28) >= 63 )
          {
            v32 = CheckHiredNPCSpeciality(8);
            if ( v32 )
              v77 -= 2;
            v33 = CheckHiredNPCSpeciality(9);
            if ( v33 )
              v77 -= 3;
            v56[1] = (const char *)45;
          }
          else
          {
            v56[1] = (const char *)35;
          }
          v34 = CheckHiredNPCSpeciality(v56[1]);
          if ( v34 )
            v77 -= 2;
          v35 = CheckHiredNPCSpeciality(0x2C);
          if ( v35 )
            --v77;
          if ( v77 < 1 )
            v77 = 1;
          if ( v72 != (void *)v1 )
          {
            memcpy(&v41, &pMapStats->pMapInfos[(unsigned __int8)byte_4F09B0[v30]], sizeof(struct MapInfo));
            sprintfex(
              &TmpBuf,
              pGlobalTXT_LocalizationStrings[404],
              v77,
              *(_DWORD *)&v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              *(_QWORD *)v56);
            strcat(v75, &TmpBuf);
            v36 = v75;
            v75 += 100;
            ++v73;
            ++v76;
            strcat(v36, "\n \n");
            *(_DWORD *)(v26 + 4) = v74;
            v37 = sub_44C59D(pFontArrus, &TmpBuf, (int)&v62, 0, 0);
            v38 = *(_DWORD *)(v26 + 4);
            *(_DWORD *)(v26 + 12) = v37;
            v1 = 255;
            *(_DWORD *)(v26 + 20) = v38 + v37 - 1;
            v74 += v65 + v37;
          }
        }
        else
        {
          v39 = v75;
          ++v73;
          ++v76;
          v75 += 100;
          strcpy(v39, Class);
          if ( v26 )
          {
            *(_DWORD *)(v26 + 20) = 0;
            *(_DWORD *)(v26 + 12) = 0;
            *(_DWORD *)(v26 + 4) = 0;
          }
        }
        ++v71;
        if ( v71 >= *(_DWORD *)(v70 + 40) + *(_DWORD *)(v70 + 56) )
          break;
        v20 = v70;
      }
      if ( v74 != v66 )
      {
        v56[1] = &Dest;
        v56[0] = &v60;
        v55 = &v59;
        v54 = &v58;
        v53 = &v57;
        v52 = pStringBuffer;
        sprintfex(TmpBuf, "%s\n \n%s%s%s%s%s", pStringBuffer, &v57, &v58, &v59, &v60, &Dest);
        sub_44D406((int)&v62, pFontArrus, 0, 146, 0, TmpBuf, 3);
      }
      else
      {
LABEL_71:
        v56[1] = (const char *)3;
        v56[0] = pGlobalTXT_LocalizationStrings[561];
        v55 = *(char **)v68;
        v40 = sub_44C59D(pFontArrus, pGlobalTXT_LocalizationStrings[561], (int)&v62, 0, 0);
        sub_44D406((int)&v62, pFontArrus, 0, (174 - v40) / 2 + 138, (unsigned __int16)v55, v56[0], (int)v56[1]);
        AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
      }
    }
  }
  else
  {
    if ( dword_F8B19C > 104 && dword_F8B19C <= 108 )
    {
      if ( pParty_global->uNumGold < (unsigned int)v76 )
      {
        sub_44C175(pGlobalTXT_LocalizationStrings[155], 2);
        sub_4B1E92(*(_DWORD *)(dword_507BC0 + 28), 3);
        if ( dword_50CBD0[0] >= 40 )
          return;
        dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
        dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
        goto LABEL_33;
      }
      sub_492BB6(v76);
      v56[1] = (const char *)7;
      v5 = &byte_4F09B0[32 * (unsigned __int8)*(&byte_4F0CCF[4 * *(_DWORD *)(dword_507BC0 + 28)] + dword_F8B19C)];
      if ( v5[pParty_global->uDaysPlayed % 7u + 1] )
      {
        if ( _strcmpi(Str1, pMapStats->pMapInfos[(unsigned __int8)*v5].pLocationFilename))
        {
          SaveGame(1, 0);
          strcpy(Str1, pMapStats->pMapInfos[(unsigned __int8)*v5].pLocationFilename);
          v8 = *((_DWORD *)v5 + 6);
          v9 = *((_DWORD *)v5 + 5);
          v10 = *((_DWORD *)v5 + 4);
          dword_6BE364 |= 1u;
          dword_5B65B8 = 0;
          dword_5B65BC = 0;
          dword_5B65B4 = v8;
          v11 = *((_DWORD *)v5 + 3);
          dword_6A0D48 = 2;
          dword_5B65A8 = v11;
          dword_5B65AC = v10;
          dword_5B65B0 = v9;
          dword_5B65C0 = v11 | v10 | v9 | v8;
        }
        else
        {
          v6 = *((_DWORD *)v5 + 3);
          pParty_global->sRotationX = 0;
          pParty_global->sPartyPosX = v6;
          v7 = *((_DWORD *)v5 + 4);
          pCamera->sRotationY = 0;
          pParty_global->dword_007778 |= 2;
          pParty_global->sPartyPosY = v7;
          pParty_global->sPartyPosZ = *((_DWORD *)v5 + 5);
          pParty_global->dword_000700 = pParty_global->sPartyPosZ;
          pParty_global->sRotationY = *((_DWORD *)v5 + 6);
        }
        sub_4B1E92(*(_DWORD *)(dword_507BC0 + 28), 2);
        v12 = (unsigned __int8)v5[8];
        if ( *(_DWORD *)(dword_507BC0 + 28) >= 63 )
        {
          v74 = 72;
          v13 = 2500;
          v14 = CheckHiredNPCSpeciality(8);
          if ( v14 )
            v12 -= 2;
          v15 = CheckHiredNPCSpeciality(9);
          if ( v15 )
            v12 -= 3;
          v56[1] = (const char *)45;
        }
        else
        {
          v74 = 71;
          v13 = 1500;
          v56[1] = (const char *)35;
        }
        v16 = CheckHiredNPCSpeciality(v56[1]);
        if ( v16 )
          v12 -= 2;
        v17 = CheckHiredNPCSpeciality(0x2C);
        if ( v17 )
          --v12;
        if ( v12 < 1 )
          v12 = 1;
        sub_4B1BDB(1440 * v12);
        sub_4948B1(v72, v74, 0);
        v18 = GetTickCount();
        v19 = v18 + v13;
        if ( v19 < v18 )
          v19 = v18;
        while ( GetTickCount() < v19 )
          sqrt(*(double *)&byte_4D8410[1432]);
        while ( sub_4BD8B5() )
          ;
        if ( dword_50CBD0[0] < 40 )
        {
          dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
          dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
LABEL_33:
          dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
          return;
        }
      }
      else
      {
        dword_F8B19C = 1;
        AudioPlayer_sub_4AA306(pAudioPlayer, 27, 0, 0, -1, 0, 0, 0, 0);
      }
    }
  }
}

//----- (004B6FF9) --------------------------------------------------------
signed int __thiscall sub_4B6FF9(void *this)
{
  signed int v1; // eax@1
  int v2; // esi@1
  char v3; // zf@4

  v2 = (int)this;
  v1 = *(_DWORD *)(dword_507BC0 + 28);
  if ( v1 == 78 || v1 > 80 && v1 <= 82 )
  {
    if ( Player_GetConditionIdx(this) == 18 )
      goto LABEL_6;
    v3 = Player_GetConditionIdx((void *)v2) == 17;
  }
  else
  {
    v3 = Player_GetConditionIdx(this) == 18;
  }
  if ( !v3 )
    return 1;
LABEL_6:
  if ( *(_DWORD *)(v2 + 6460) < Player_GetMaxHealth(v2) || *(_DWORD *)(v2 + 6464) < Player_GetMaxMana(v2) )
    return 1;
  return 0;
}

//----- (004B705E) --------------------------------------------------------
int __cdecl sub_4B705E()
{
  int v0; // edi@1
  int v1; // esi@1
  int v2; // ebx@1
  int result; // eax@4
  int v4; // edi@6
  int v5; // eax@6
  int v6; // eax@6
  int v7; // eax@8
  int v8; // ecx@8
  int v9; // eax@9
  int v10; // eax@11
  int v11; // eax@12
  int v12; // ecx@16
  int v13; // edx@16
  int v14; // eax@19
  int v15; // edi@19
  int v16; // eax@19
  unsigned __int16 v17; // ax@21
  int v18; // ecx@21
  const char *v19; // eax@21
  int v20; // eax@21
  int v21; // eax@21
  unsigned __int16 v22; // ST14_2@27
  int v23; // eax@27
  int v24; // ebx@28
  double v25; // st7@28
  int v26; // edi@29
  signed int v27; // eax@31
  int v28; // eax@32
  int v29; // ecx@34
  int v30; // edx@36
  int v31; // edx@38
  int v32; // edx@40
  int v33; // edx@42
  int v34; // edx@44
  signed int v35; // eax@50
  int v36; // edi@50
  char v37; // al@54
  int v38; // ecx@54
  int v39; // eax@56
  char v40; // al@61
  int v41; // edi@64
  int v42; // ecx@66
  int v43; // edi@66
  int v44; // esi@66
  int v45; // eax@68
  signed int v46; // edi@69
  int v47; // edi@71
  unsigned __int16 v48; // ax@73
  int v49; // ecx@73
  int v50; // eax@73
  const char *v51; // edx@73
  int v52; // esi@73
  int v53; // eax@73
  char Dest[100]; // [sp+10h] [bp-1B4h]@64
  char v55; // [sp+74h] [bp-150h]@66
  char v56; // [sp+D8h] [bp-ECh]@66
  int v57; // [sp+13Ch] [bp-88h]@1
  int v58; // [sp+144h] [bp-80h]@1
  int v59; // [sp+14Ch] [bp-78h]@1
  __int64 v60; // [sp+190h] [bp-34h]@1
  __int64 v61; // [sp+198h] [bp-2Ch]@1
  __int64 v62; // [sp+1A0h] [bp-24h]@1
  int v63; // [sp+1ACh] [bp-18h]@6
  int v64; // [sp+1B0h] [bp-14h]@8
  unsigned __int8 v65; // [sp+1B7h] [bp-Dh]@64
  int v66; // [sp+1B8h] [bp-Ch]@6
  int v67; // [sp+1BCh] [bp-8h]@6
  const char *v68; // [sp+1C0h] [bp-4h]@6

  v2 = dword_507BC0;
  memcpy(&v57, (const void *)dword_507BC0, 0x54u);
  v57 = 483;
  v58 = 148;
  v59 = 334;
  HIDWORD(v60) = 0xFFFFFFFF;
  HIDWORD(v61) = 0xFFFFFF9B;
  v1 = (int)*(&ptr_A750C4 + uActiveCharacter);
  v0 = sub_4B807C(*(&ptr_A750C4 + uActiveCharacter), *((float *)&unk_591458 + 13 * *(_DWORD *)(v2 + 28)));
  HIDWORD(v62) = v0;
  if ( dword_F8B19C != 1 )
  {
    if ( dword_F8B19C != 10 )
    {
      if ( dword_F8B19C != 11 )
      {
        result = dword_F8B19C - 96;
        if ( dword_F8B19C == 96 )
        {
          result = sub_4B1784();
          if ( result )
          {
            v4 = dword_507BBC;
            v63 = dword_507BBC;
            v5 = *(_DWORD *)(dword_507BC0 + 28);
            v68 = 0;
            v67 = (signed __int64)(*((float *)&unk_59145C + 13 * v5) * 500.0);
            v6 = sub_4911F3((void *)v1);
            v66 = v67 * (100 - v6) / 100;
            if ( v66 < v67 / 3 )
              v66 = v67 / 3;
            v7 = *(_DWORD *)(v4 + 56);
            v8 = v7 + *(_DWORD *)(v4 + 40);
            v67 = 0;
            v64 = v7;
            if ( v7 >= v8 )
              goto LABEL_78;
            do
            {
              v9 = *(_DWORD *)(GUIWindow_GetChild(v4, v64) + 36) - 36;
              if ( *(&byte_4ED970[37 * *(_BYTE *)(v1 + 185)] + v9) )
              {
                if ( !*(_WORD *)(v1 + 2 * v9 + 264) )
                {
                  //v10 = sub_44C59D(pFontArrus, (&dword_AE32D0)[4 * v9], (int)&v57, 0, 0);
                  v10 = sub_44C59D(pFontArrus, aSkillNames[v9], (int)&v57, 0, 0);
                  v68 += v10;
                  ++v67;
                }
              }
              v11 = *(_DWORD *)(v4 + 56);
              ++v64;
            }
            while ( v64 < *(_DWORD *)(v4 + 40) + v11 );
            if ( v67 )
            {
              sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[401], v66);
              sub_44D406((int)&v57, pFontArrus, 0, 146, 0, &TmpBuf, 3);
              v66 = (149 - (_DWORD)v68) / v67;
              if ( v66 > 32 )
                v66 = 32;
              v67 = (149 - v67 * v66 - (_DWORD)v68) / 2 - v66 / 2 + 162;
              v12 = v63;
              result = *(_DWORD *)(v63 + 56);
              v13 = result + *(_DWORD *)(v63 + 40);
              v64 = *(_DWORD *)(v63 + 56);
              if ( result < v13 )
              {
                v68 = (const char *)2;
                while ( 1 )
                {
                  v16 = GUIWindow_GetChild(v12, v64);
                  v15 = v16;
                  v14 = *(_DWORD *)(v16 + 36) - 36;
                  if ( !*(&byte_4ED970[37 * *(_BYTE *)(v1 + 185)] + v14) || *(_WORD *)(v1 + 2 * v14 + 264) )
                  {
                    *(_DWORD *)(v15 + 20) = 0;
                    *(_DWORD *)(v15 + 12) = 0;
                    *(_DWORD *)(v15 + 4) = 0;
                  }
                  else
                  {
                    //v19 = (&dword_AE32D0)[4 * v14];
                    v19 = aSkillNames[v14];
                    *(_DWORD *)(v15 + 4) = v66 + v67;
                    HIDWORD(v62) = v19;
                    v20 = sub_44C59D(pFontArrus, v19, (int)&v57, 0, 0);
                    v18 = *(_DWORD *)(v15 + 4);
                    *(_DWORD *)(v15 + 12) = v20;
                    v21 = v18 + v20 - 1;
                    *(_DWORD *)(v15 + 20) = v21;
                    v67 = v21;
                    v17 = WORD2(v61);
                    if ( *(const char **)(dword_507BBC + 44) != v68 )
                      v17 = WORD2(v60);
                    sub_44D406((int)&v57, pFontArrus, 0, v18, v17, HIDWORD(v62), 3);
                  }
                  result = v63;
                  ++v64;
                  ++v68;
                  if ( v64 >= *(_DWORD *)(v63 + 40) + *(_DWORD *)(v63 + 56) )
                    break;
                  v12 = v63;
                }
              }
            }
            else
            {
LABEL_78:
              sprintfex(
                &TmpBuf,
                pGlobalTXT_LocalizationStrings[544],
                v1 + 168,
                //(&dword_AE31F0)[4 * *(_BYTE *)(v1 + 185)]);
                aClassNames[*(_BYTE *)(v1 + 185)]);
              strcat((char *)&TmpBuf, "\n \n");
              strcat((char *)&TmpBuf, pGlobalTXT_LocalizationStrings[528]);
              v22 = WORD2(v61);
              v23 = sub_44C59D(pFontArrus, &TmpBuf, (int)&v57, 0, 0);
              result = (int)sub_44D406((int)&v57, pFontArrus, 0, (174 - v23) / 2 + 138, v22, &TmpBuf, 3);
            }
          }
        }
        return result;
      }
      v25 = *((float *)&unk_591458 + 13 * *(_DWORD *)(dword_507BC0 + 28));
      v24 = 0;
      if ( pParty_global->uNumGold >= (unsigned int)(signed __int64)v25 )
      {
        sub_492BB6((signed __int64)v25);
        v26 = (int)&unk_6A12B8;
        if ( dword_6BE360 != 2 )
          v26 = (int)&unk_6BE68C;
        v27 = *(_DWORD *)(v26 + 8);
        v68 = (const char *)v26;
        if ( v27 > -5 )
        {
          v28 = v27 - 1;
          *(_DWORD *)(v26 + 8) = v28;
          if ( v28 < -5 )
            *(_DWORD *)(v26 + 8) = -5;
        }
        v29 = uActiveCharacter;
        if ( (unsigned __int8)byte_F8B1EF[uActiveCharacter] == pParty_global->uDaysPlayed % 7u )
        {
          if ( *(_DWORD *)(v26 + 8) <= -5 )
          {
            v30 = pParty_global->uDaysPlayed % 7u + 1;
            LOBYTE(v30) = v30 | 0x80;
            sub_42777D(12, uActiveCharacter - 1, v30, 48, 0);
            v29 = uActiveCharacter;
          }
          if ( *(_DWORD *)(v26 + 8) <= -10 )
          {
            v31 = pParty_global->uDaysPlayed % 7u + 1;
            LOBYTE(v31) = v31 | 0x80;
            sub_42777D(50, v29 - 1, v31, 48, 0);
            v29 = uActiveCharacter;
            v26 = (int)v68;
          }
          if ( *(_DWORD *)(v26 + 8) <= -15 )
          {
            v32 = pParty_global->uDaysPlayed % 7u + 1;
            LOBYTE(v32) = v32 | 0x80;
            sub_42777D(75, v29 - 1, v32, 48, 0);
            v29 = uActiveCharacter;
            v26 = (int)v68;
          }
          if ( *(_DWORD *)(v26 + 8) <= -20 )
          {
            v33 = pParty_global->uDaysPlayed % 7u + 1;
            LOBYTE(v33) = v33 | 0x80;
            sub_42777D(86, v29 - 1, v33, 48, 0);
            v29 = uActiveCharacter;
            v26 = (int)v68;
          }
          if ( *(_DWORD *)(v26 + 8) <= -25 )
          {
            v34 = pParty_global->uDaysPlayed % 7u + 1;
            LOBYTE(v34) = v34 | 0x80;
            sub_42777D(85, v29 - 1, v34, 48, 0);
            v29 = uActiveCharacter;
          }
        }
        ++byte_F8B1EF[v29];
        sub_4948B1((void *)v1, 83, 0);
        sub_44C175(pGlobalTXT_LocalizationStrings[527], 2);
        goto LABEL_46;
      }
      goto LABEL_55;
    }
    result = sub_4B6FF9((void *)v1);
    if ( !result )
      return result;
    v24 = 0;
    if ( pParty_global->uNumGold < (unsigned int)v0 )
    {
LABEL_55:
      sub_44C175(pGlobalTXT_LocalizationStrings[155], 2);
      sub_4B1E92(*(_DWORD *)(dword_507BC0 + 28), 2);
      goto LABEL_46;
    }
    sub_492BB6(v0);
    v36 = *(_DWORD *)(v1 + 136);
    v61 = *(_QWORD *)(v1 + 112);
    v60 = *(_QWORD *)(v1 + 120);
    v62 = *(_QWORD *)(v1 + 128);
    v63 = *(_DWORD *)(v1 + 140);
    memset((void *)v1, 0, 0xA0u);
    *(_DWORD *)(v1 + 6460) = Player_GetMaxHealth(v1);
    *(_DWORD *)(v1 + 6464) = Player_GetMaxMana(v1);
    v35 = *(_DWORD *)(dword_507BC0 + 28);
    if ( v35 == 78 || v35 > 80 && v35 <= 82 )
    {
      v39 = v63;
      if ( v63 | v36 )
      {
        *(_DWORD *)(v1 + 136) = v36;
      }
      else
      {
        if ( !v62 && !v60 && !v61 )
          goto LABEL_63;
        *(_DWORD *)(v1 + 6440) = *(_BYTE *)(v1 + 186);
        *(_DWORD *)(v1 + 6436) = *(_DWORD *)(v1 + 6432);
        Player_sub_492D65((char *)v1, 17, 1);
        *(_DWORD *)(v1 + 6432) = (Player_GetVoiceSex(v1) != 0) + 23;
        v40 = (Player_GetVoiceSex(v1) != 0) + 23;
        *(_BYTE *)(v1 + 186) = v40;
        sub_491DE7(uActiveCharacter - 1, v40);
        *(_DWORD *)(v1 + 136) = pParty_global->qword_00002C;
        v39 = HIDWORD(pParty_global->qword_00002C);
      }
      *(_DWORD *)(v1 + 140) = v39;
    }
    else
    {
      if ( v63 | v36 )
      {
        v37 = *(_BYTE *)(v1 + 6440);
        v38 = *(_DWORD *)(v1 + 6436);
        *(_BYTE *)(v1 + 186) = v37;
        *(_DWORD *)(v1 + 6432) = v38;
        sub_491DE7(uActiveCharacter - 1, v37);
      }
    }
LABEL_63:
    AudioPlayer_sub_4AA306(pAudioPlayer, 202, -1, 0, -1, 0, 0, 0, 0);
    sub_4948B1((void *)v1, 82, 0);
    sub_4418B1(20, uActiveCharacter + 99, 0, 65536);
LABEL_46:
    result = dword_50CBD0[0];
    if ( dword_50CBD0[0] < 40 )
    {
      dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
      dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
      result = 3 * dword_50CBD0[0] + 3;
      dword_50CBD0[result] = v24;
      ++dword_50CBD0[0];
    }
    return result;
  }
  v65 = 1;
  v41 = GUIWindow_GetChild(dword_507BBC, *(_DWORD *)(dword_507BBC + 56));
  strcpy(Dest, Class);
  *(_DWORD *)(v41 + 12) = 0;
  *(_DWORD *)(v41 + 4) = 0;
  if ( sub_4B6FF9((void *)v1) )
  {
    sprintfex(Dest, "%s %d %s", pGlobalTXT_LocalizationStrings[104], HIDWORD(v62), pGlobalTXT_LocalizationStrings[97]);
    v65 = 0;
  }
  strcpy(&v55, pGlobalTXT_LocalizationStrings[68]);
  strcpy(&v56, pGlobalTXT_LocalizationStrings[160]);
  v44 = v65;
  v42 = dword_507BBC;
  v43 = v65;
  v68 = 0;
  if ( (signed int)v65 < *(_DWORD *)(dword_507BBC + 40) )
  {
    v63 = (int)&Dest[100 * v65];
    do
    {
      v45 = sub_44C59D(pFontArrus, (const char *)v63, (int)&v57, 0, 0);
      v68 += v45;
      v42 = dword_507BBC;
      v63 += 100;
      ++v43;
    }
    while ( v43 < *(_DWORD *)(dword_507BBC + 40) );
  }
  v46 = *(_DWORD *)(v42 + 40) - v44;
  v66 = (174 - (_DWORD)v68) / v46;
  if ( v66 > 32 )
    v66 = 32;
  result = *(_DWORD *)(v42 + 56);
  v47 = (174 - v66 * v46 - (_DWORD)v68) / 2 - v66 / 2 + 138;
  v67 = v44 + result;
  if ( v44 + result < result + *(_DWORD *)(v42 + 40) )
  {
    v63 = v44 + 2;
    v68 = &Dest[100 * v44];
    do
    {
      v50 = GUIWindow_GetChild(v42, v67);
      v51 = v68;
      v52 = v50;
      *(_DWORD *)(v50 + 4) = v66 + v47;
      v53 = sub_44C59D(pFontArrus, v51, (int)&v57, 0, 0);
      v49 = *(_DWORD *)(v52 + 4);
      *(_DWORD *)(v52 + 12) = v53;
      v47 = v49 + v53 - 1;
      *(_DWORD *)(v52 + 20) = v47;
      v48 = WORD2(v61);
      if ( *(_DWORD *)(dword_507BBC + 44) != v63 )
        v48 = WORD2(v60);
      sub_44D406((int)&v57, pFontArrus, 0, v49, v48, v68, 3);
      v42 = dword_507BBC;
      v68 += 100;
      ++v63;
      ++v67;
      result = *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56);
    }
    while ( v67 < result );
  }
  return result;
}

//----- (004B7911) --------------------------------------------------------
void __cdecl sub_4B7911()
{
  int v0; // eax@3
  int v1; // eax@10
  unsigned int v2; // esi@10
  char v3; // sf@15
  int v4; // ST20_4@20
  int v5; // eax@20
  int v6; // esi@21
  int *v7; // edi@21
  unsigned int v8; // ST20_4@21
  int v9; // ST1C_4@21
  unsigned int v10; // eax@21
  char *v11; // eax@23
  signed int v12; // ebx@24
  signed int i; // esi@26
  int v14; // eax@27
  int v15; // ecx@28
  int v16; // ebx@28
  __int64 v17; // qax@28
  signed int v18; // ebx@28
  unsigned __int8 v19; // sf@28
  const char **v20; // edi@29
  unsigned __int16 v21; // ax@30
  int v22; // ecx@30
  int v23; // eax@30
  int v24; // esi@30
  int v25; // eax@30
  char v27; // [sp+Ch] [bp-110h]@21
  char v28; // [sp+60h] [bp-BCh]@21
  int v29; // [sp+68h] [bp-B4h]@21
  int v30; // [sp+70h] [bp-ACh]@21
  int v31; // [sp+B4h] [bp-68h]@1
  int v32; // [sp+BCh] [bp-60h]@1
  int v33; // [sp+C4h] [bp-58h]@1
  __int16 v34[2]; // [sp+108h] [bp-14h]@1
  int v35; // [sp+10Ch] [bp-10h]@28
  __int16 v36[2]; // [sp+110h] [bp-Ch]@1
  int v37; // [sp+114h] [bp-8h]@29
  int v38; // [sp+118h] [bp-4h]@21

  memcpy(&v31, (const void *)dword_507BC0, 0x54u);
  v31 = 483;
  v32 = 148;
  v33 = 334;
  *(_DWORD *)v34 = 0xFFFFFFFF;
  *(_DWORD *)v36 = 0xFFFFFF9B;
  sprintfex(&TmpBuf, "%s: %d", pGlobalTXT_LocalizationStrings[162], dword_AE31E0);
  sub_44D406((int)&v31, pFontArrus, 0, 260, v36[0], &TmpBuf, 3);
  if ( dword_F8B19C == 1 )
  {
    v12 = 1;
    v38 = 0;
    dword_F8B1B8[0] = pGlobalTXT_LocalizationStrings[161];
    if ( dword_AE31E0 )
    {
      dword_F8B1BC = pGlobalTXT_LocalizationStrings[160];
      v12 = 2;
    }
    for ( i = 0; i < v12; ++i )
    {
      v14 = sub_44C59D(pFontArrus, (const char *)dword_F8B1B8[i], (int)&v31, 0, 0);
      v38 += v14;
    }
    v35 = (100 - v38) / v12;
    v15 = dword_507BBC;
    v17 = 80 - v12 * (100 - v38) / v12 - v38;
    v18 = v17 - HIDWORD(v17);
    v0 = *(_DWORD *)(dword_507BBC + 56);
    HIDWORD(v17) = v0 + *(_DWORD *)(dword_507BBC + 40);
    v16 = (v18 >> 1) - v35 / 2 + 158;
    v19 = -*(_DWORD *)(dword_507BBC + 40) < 0;
    v38 = *(_DWORD *)(dword_507BBC + 56);

    compile_error;//if ( v19 ^ __SETO__(v0, HIDWORD(v17)) )
    if (1)
    {
      v37 = 2;
      v20 = (const char **)dword_F8B1B8;
      do
      {
        v23 = GUIWindow_GetChild(v15, v38);
        v24 = v23;
        *(_DWORD *)(v23 + 4) = v35 + v16;
        v25 = sub_44C59D(pFontArrus, *v20, (int)&v31, 0, 0);
        v22 = *(_DWORD *)(v24 + 4);
        *(_DWORD *)(v24 + 12) = v25;
        v16 = v22 + v25 - 1;
        *(_DWORD *)(v24 + 20) = v16;
        v21 = v36[0];
        if ( *(_DWORD *)(dword_507BBC + 44) != v37 )
          v21 = v34[0];
        sub_44D406((int)&v31, pFontArrus, 0, v22, v21, *v20, 3);
        v15 = dword_507BBC;
        ++v37;
        ++v20;
        ++v38;
        v0 = *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56);
      }
      while ( v38 < v0 );
    }
  }
  else
  {
    if ( dword_F8B19C != 99 )
    {
      v0 = dword_F8B19C - 100;
      if ( dword_F8B19C != 100 )
        return v0;
      v0 = dword_507BC0;
      if ( *(_DWORD *)(dword_507BC0 + 64) == 1 )
      {
        sprintfex(&TmpBuf, "%s\n%s", pGlobalTXT_LocalizationStrings[163], pGlobalTXT_LocalizationStrings[112]);
        sub_44D406((int)&v31, pFontArrus, 0, 146, v36[0], &TmpBuf, 3);
        sub_44D406((int)&v31, pFontArrus, 0, 186, v34[0], &byte_69AF00, 3);
        v4 = pFontArrus;
        v5 = sub_44C51E(pFontArrus, &byte_69AF00);
        sub_459C2B((int)&v31, v5 / 2 + 80, 185, v4);
        return;
      }
      if ( *(_DWORD *)(dword_507BC0 + 64) == 2 )
      {
        v1 = atoi(&byte_69AF00);
        v2 = v1;
        if ( v1 <= 0 )
        {
LABEL_8:
          LOBYTE(v0) = LOBYTE(dword_50CBD0[0]);
          if ( dword_50CBD0[0] < 40 )
          {
            dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
            dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
            v0 = 3 * dword_50CBD0[0] + 3;
            dword_50CBD0[v0] = 0;
            ++dword_50CBD0[0];
          }
          return v0;
        }
        if ( v1 > (unsigned int)pParty_global->uNumGold )
        {
          sub_4B1E92(*(_DWORD *)(dword_507BC0 + 28), 2);
          v2 = pParty_global->uNumGold;
        }
        if ( (signed int)v2 > dword_AE31E0 )
          v2 = dword_AE31E0;
        sub_492BB6(v2);
        v3 = (signed int)(dword_AE31E0 - v2) < 0;
        dword_AE31E0 -= v2;
        if ( v3 )
          dword_AE31E0 = 0;
        if ( uActiveCharacter )
          sub_4948B1(*(&ptr_A750C4 + uActiveCharacter), 81, 0);
        v0 = dword_507BC0;
      }
      else
      {
        if ( *(_DWORD *)(dword_507BC0 + 64) != 3 )
          return v0;
      }
      *(_DWORD *)(v0 + 64) = 0;
      goto LABEL_8;
    }
    v7 = &pMonsterStats->pMonsterInfos[word_F8B1A0];
    v8 = 0xFFFFFFFF;
    v9 = *v7;
    v10 = 0xFFFFFF9B;
    sprintfex(TmpBuf, (const char *)&unk_4F0F98, v10, v9, v8);
    sprintfex(pStringBuffer, (const char *)dword_F8B1A4, TmpBuf, 100 * *((_BYTE *)v7 + 8));
    dword_F8B1E8 = pStringBuffer;
    memcpy(&v27, (const void *)dword_507BBC, 0x54u);
    v29 = 458;
    v30 = 457;
    v38 = pFontArrus;
    v6 = sub_44C59D(pFontArrus, pStringBuffer, (int)&v28, 13, 0) + 7;
    if ( 352 - v6 < 8 )
    {
      v38 = pFontCreate;
      v6 = sub_44C59D(pFontCreate, dword_F8B1E8, (int)&v28, 13, 0) + 7;
    }
    sub_4A6A68(
      pD3DRenderer,
      8,
      352 - v6,
      uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 : 0,
      *(_WORD *)(uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 + 0x1A : 26) - v6);
    Render_DrawIndexedTexture(pD3DRenderer, 8, 347 - v6, pClass18_EndcapTexture);
    v11 = FitTextInAWindow(dword_F8B1E8, v38, (int)&v28, 13, 0);
    FontDrawText((int)&v27, v38, 13, 354 - v6, v11, 0, 0, 0);
  }
}

//----- (004B7D7E) --------------------------------------------------------
void __cdecl sub_4B7D7E()
{
  int v0; // eax@3
  int v1; // ecx@5
  int v2; // eax@6
  int v3; // esi@6
  int v4; // ST10_4@12
  int v5; // eax@12
  int v6; // eax@19
  unsigned int v7; // esi@19
  unsigned __int16 v8; // ax@27
  unsigned __int16 v9; // ax@29
  char *v11; // [sp-8h] [bp-70h]@11
  int v12; // [sp-4h] [bp-6Ch]@11
  int v13; // [sp+Ch] [bp-5Ch]@1
  int v14; // [sp+14h] [bp-54h]@1
  int v15; // [sp+1Ch] [bp-4Ch]@1
  __int16 v16[2]; // [sp+60h] [bp-8h]@1
  __int16 v17[2]; // [sp+64h] [bp-4h]@1

  memcpy(&v13, (const void *)dword_507BC0, 0x54u);
  v13 = 483;
  v14 = 148;
  v15 = 334;
  *(_DWORD *)v16 = 0xFFFFFFFF;
  *(_DWORD *)v17 = 0xFFFFFF9B;
  wsprintfA(&TmpBuf, "%s: %d", pGlobalTXT_LocalizationStrings[25], pParty_global->uNumGoldInBank);
  sub_44D406((int)&v13, pFontArrus, 0, 220, v17[0], &TmpBuf, 3);
  if ( dword_F8B19C != 1 )
  {
    if ( dword_F8B19C == 7 )
    {
      v0 = dword_507BC0;
      if ( *(_DWORD *)(dword_507BC0 + 64) != 1 )
      {
        v1 = *(_DWORD *)(dword_507BC0 + 64) - 2;
        if ( *(_DWORD *)(dword_507BC0 + 64) == 2 )
        {
          v6 = atoi(&byte_69AF00);
          v7 = v6;
          if ( !v6 )
          {
LABEL_17:
            LOBYTE(v0) = LOBYTE(dword_50CBD0[0]);
            if ( dword_50CBD0[0] < 40 )
            {
              dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
              dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
              v0 = 3 * dword_50CBD0[0] + 3;
              dword_50CBD0[v0] = 0;
              ++dword_50CBD0[0];
            }
            return v0;
          }
          if ( v6 > (unsigned int)pParty_global->uNumGold )
          {
            sub_4B1E92(*(_DWORD *)(dword_507BC0 + 28), 2);
            v7 = pParty_global->uNumGold;
          }
          if ( v7 )
          {
            sub_492BB6(v7);
            pParty_global->uNumGoldInBank += v7;
            if ( uActiveCharacter )
              sub_4948B1(*(&ptr_A750C4 + uActiveCharacter), 81, 0);
          }
          v0 = dword_507BC0;
LABEL_16:
          *(_DWORD *)(v0 + 64) = 0;
          goto LABEL_17;
        }
LABEL_15:
        if ( v1 != 1 )
          return v0;
        goto LABEL_16;
      }
      v12 = pGlobalTXT_LocalizationStrings[112];
      v11 = pGlobalTXT_LocalizationStrings[60];
    }
    else
    {
      v0 = dword_F8B19C - 8;
      if ( dword_F8B19C != 8 )
        return v0;
      v0 = dword_507BC0;
      if ( *(_DWORD *)(dword_507BC0 + 64) != 1 )
      {
        v1 = *(_DWORD *)(dword_507BC0 + 64) - 2;
        if ( *(_DWORD *)(dword_507BC0 + 64) == 2 )
        {
          *(_DWORD *)(dword_507BC0 + 64) = 0;
          v2 = atoi(&byte_69AF00);
          v3 = v2;
          if ( v2 )
          {
            if ((unsigned int)v2 > pParty_global->uNumGoldInBank)
            {
              sub_4B1E92(*(_DWORD *)(dword_507BC0 + 28), 2);
              v3 = pParty_global->uNumGoldInBank;
            }
            if (v3)
            {
              sub_492B70((void *)(pParty_global->uNumGold + v3));
              pParty_global->uNumGoldInBank -= v3;
            }
          }
          goto LABEL_17;
        }
        goto LABEL_15;
      }
      v12 = pGlobalTXT_LocalizationStrings[112];
      v11 = pGlobalTXT_LocalizationStrings[224];
    }
    sprintfex(&TmpBuf, "%s\n%s", v11, v12);
    sub_44D406((int)&v13, pFontArrus, 0, 146, v17[0], &TmpBuf, 3);
    sub_44D406((int)&v13, pFontArrus, 0, 186, v16[0], &byte_69AF00, 3);
    v4 = pFontArrus;
    v5 = sub_44C51E(pFontArrus, &byte_69AF00);
    sub_459C2B((int)&v13, v5 / 2 + 80, 185, v4);
    return;
  }
  v8 = v17[0];
  if ( *(_DWORD *)(dword_507BBC + 44) != 2 )
    v8 = v16[0];
  sub_44D406((int)&v13, pFontArrus, 0, 146, v8, pGlobalTXT_LocalizationStrings[60], 3);
  v9 = v17[0];
  if ( *(_DWORD *)(dword_507BBC + 44) != 3 )
    v9 = v16[0];
  sub_44D406((int)&v13, pFontArrus, 0, 176, v9, pGlobalTXT_LocalizationStrings[224], 3);
  return;
}

//----- (004B8040) --------------------------------------------------------
unsigned int __thiscall sub_4B8040(void *this, int a2)
{
  return (unsigned int)((signed __int64)((double)*((signed __int64 *)this + a2) * 0.234375) / 60 / 60) / 0x18 % 7 + 1;
}

//----- (004B807C) --------------------------------------------------------
int __thiscall sub_4B807C(void *this, float a2)
{
  int v2; // eax@1
  void *v3; // edi@1
  signed int v4; // esi@1
  int v5; // ebx@7
  unsigned int v6; // eax@8
  signed __int64 v7; // qax@13
  int v9; // [sp-4h] [bp-14h]@4
  signed int v10; // [sp+8h] [bp-8h]@4
  unsigned int v11; // [sp+Ch] [bp-4h]@6

  v3 = this;
  v2 = Player_GetConditionIdx(this);
  v4 = 0;
  if ( v2 >= 14 )
  {
    if ( v2 <= 15 )
    {
      v10 = 5;
      v9 = v2;
      goto LABEL_6;
    }
    if ( v2 == 16 )
    {
      v10 = 10;
      v9 = 16;
LABEL_6:
      v11 = sub_4B8040(v3, v9);
      goto LABEL_13;
    }
  }
  v10 = 1;
  v5 = 0;
  do
  {
    v6 = sub_4B8040(v3, v5);
    if ( (signed int)v6 > v4 )
      v4 = v6;
    ++v5;
  }
  while ( v5 <= 13 );
  v11 = v4;
  if ( !v4 )
    v11 = 1;
LABEL_13:
  v7 = (signed __int64)((double)(signed int)v11 * (double)v10 * a2);
  if ( (_DWORD)v7 < 1 )
    LODWORD(v7) = 1;
  return v7;
}

//----- (004B8102) --------------------------------------------------------
signed int __thiscall sub_4B8102(void *this, signed int a2, float a3)
{
  signed int v3; // esi@1
  signed int result; // eax@3

  v3 = (signed __int64)((double)a2 / (a3 + 2.0)) + a2 * sub_4911F3(this) / 100;
  if ( v3 > a2 )
    v3 = a2;
  result = 1;
  if ( v3 >= 1 )
    result = v3;
  return result;
}

//----- (004B8142) --------------------------------------------------------
int __thiscall sub_4B8142(void *this, signed int a2, float a3)
{
  int result; // eax@1

  result = (signed int)((100 - sub_4911F3(this)) * (signed __int64)((double)a2 * a3)) / 100;
  if ( result < a2 )
    result = a2;
  if ( result < 1 )
    result = 1;
  return result;
}

//----- (004B8179) --------------------------------------------------------
signed int __thiscall sub_4B8179(void *this, float a2)
{
  int v2; // ecx@1
  signed int v3; // esi@1
  signed int result; // eax@3

  v3 = (signed __int64)(a2 * 50.0);
  v2 = v3 * (100 - sub_4911F3(this)) / 100;
  if ( v2 < v3 / 3 )
    v2 = v3 / 3;
  result = 1;
  if ( v2 >= 1 )
    result = v2;
  return result;
}

//----- (004B81C3) --------------------------------------------------------
signed int __thiscall sub_4B81C3(void *this, signed int a2, float a3)
{
  int v3; // ecx@1
  signed int v4; // esi@1
  signed int result; // eax@3

  v4 = (signed __int64)((double)a2 / (6.0 - a3));
  v3 = v4 * (100 - sub_4911F3(this)) / 100;
  if ( v3 < v4 / 3 )
    v3 = v4 / 3;
  result = 1;
  if ( v3 >= 1 )
    result = v3;
  return result;
}

//----- (004B8213) --------------------------------------------------------
int __stdcall sub_4B8213(signed int a1, float a2)
{
  signed __int64 v2; // qax@1

  v2 = (signed __int64)((double)a1 / (a2 + 2.0));
  if ( (_DWORD)v2 < 1 )
    LODWORD(v2) = 1;
  return v2;
}

//----- (004B8233) --------------------------------------------------------
int __stdcall sub_4B8233(signed int a1, float a2)
{
  signed __int64 v2; // qax@1

  v2 = (signed __int64)((double)a1 * a2);
  if ( (_DWORD)v2 < 1 )
    LODWORD(v2) = 1;
  return v2;
}

//----- (004B824B) --------------------------------------------------------
int __stdcall sub_4B824B(float a1)
{
  signed __int64 v1; // qax@1

  v1 = (signed __int64)(a1 * 50.0);
  if ( (_DWORD)v1 < 1 )
    LODWORD(v1) = 1;
  return v1;
}

//----- (004B8265) --------------------------------------------------------
int __stdcall sub_4B8265(signed int a1, float a2)
{
  signed __int64 v2; // qax@1

  v2 = (signed __int64)((double)a1 / (6.0 - a2));
  if ( (_DWORD)v2 < 1 )
    LODWORD(v2) = 1;
  return v2;
}

//----- (004B8285) --------------------------------------------------------
void __cdecl sub_4B8285()
{
  int v0; // ecx@1
  signed int v1; // ebx@1
  int v2; // ebx@1
  void *v3; // edi@1
  double v4; // st7@1
  int v5; // esi@3
  int v6; // ecx@5
  signed int v7; // edi@5
  int v8; // edi@16
  signed int v9; // esi@16
  int v10; // esi@18
  int v11; // eax@18
  int v12; // eax@19
  int v13; // eax@21
  int v14; // ecx@26
  int v15; // eax@28
  int v16; // esi@28
  int v17; // eax@28
  unsigned __int16 v18; // ax@30
  int v19; // ecx@30
  char *v20; // eax@30
  int v21; // eax@30
  int v22; // edx@30
  int v23; // eax@30
  _DWORD v24; // eax@34
  int v25; // eax@34
  const char *v26; // esi@36
  int v27; // edi@46
  int v28; // eax@53
  int v29; // eax@55
  int v30; // eax@57
  signed int v31; // eax@59
  int v32; // eax@61
  int v33; // edi@64
  int v34; // esi@64
  _DWORD v35; // eax@64
  int v36; // ecx@64
  _BYTE v37; // sf@64
  int v38; // eax@65
  int v39; // ecx@69
  int v40; // edx@69
  _DWORD v41; // ecx@69
  int v42; // ecx@70
  _DWORD v43; // edx@70
  _DWORD v44; // edx@71
  int v45; // ecx@71
  _DWORD v46; // ecx@72
  _DWORD v47; // eax@74
  signed int v48; // edi@77
  signed int i; // esi@79
  int v50; // eax@80
  int v51; // ecx@81
  int v52; // edi@81
  _QWORD v53; // qax@81
  signed int v54; // edi@81
  _BYTE v55; // sf@81
  unsigned __int16 v56; // ax@83
  int v57; // ecx@83
  int v58; // esi@83
  const char **v59; // eax@83
  int v60; // eax@83
  int v61; // edx@83
  char *v62; // eax@99
  int v63; // edx@99
  int v64; // edi@99
  int v65; // eax@99
  int v66; // edi@100
  int v67; // [sp-10h] [bp-284h]@75
  unsigned __int16 v68; // [sp-Ch] [bp-280h]@75
  int v69; // [sp-Ch] [bp-280h]@99
  const char *v70; // [sp-8h] [bp-27Ch]@75
  signed int v71; // [sp-8h] [bp-27Ch]@99
  int v72; // [sp-4h] [bp-278h]@75
  const char *v73; // [sp-4h] [bp-278h]@93
  char *v74; // [sp-4h] [bp-278h]@99
  char Dest; // [sp+Ch] [bp-268h]@55
  char v76; // [sp+70h] [bp-204h]@59
  char v77; // [sp+D4h] [bp-1A0h]@57
  char v78; // [sp+138h] [bp-13Ch]@59
  char v79; // [sp+19Ch] [bp-D8h]@99
  int v80; // [sp+1A4h] [bp-D0h]@99
  int v81; // [sp+1ACh] [bp-C8h]@99
  int v82; // [sp+1F0h] [bp-84h]@1
  int v83; // [sp+1F8h] [bp-7Ch]@1
  int v84; // [sp+200h] [bp-74h]@1
  char *Str[2]; // [sp+244h] [bp-30h]@30
  unsigned int v86; // [sp+24Ch] [bp-28h]@1
  unsigned __int8 v87; // [sp+253h] [bp-21h]@59
  signed int v88; // [sp+254h] [bp-20h]@1
  __int16 v89[2]; // [sp+258h] [bp-1Ch]@1
  int v90; // [sp+25Ch] [bp-18h]@1
  int v91; // [sp+260h] [bp-14h]@18
  unsigned __int8 v92; // [sp+266h] [bp-Eh]@59
  unsigned __int8 v93; // [sp+267h] [bp-Dh]@57
  int v94; // [sp+268h] [bp-Ch]@1
  unsigned __int8 v95; // [sp+26Fh] [bp-5h]@55
  int v96; // [sp+270h] [bp-4h]@3

  v2 = dword_507BC0;
  memcpy(&v82, (const void *)dword_507BC0, 0x54u);
  v90 = (int)*(&ptr_A750C4 + uActiveCharacter);
  v3 = (void *)v90;
  v82 = 483;
  v83 = 148;
  v84 = 334;
  v86 = 0xFFFFFFFF;
  *(_DWORD *)v89 = 0xFFFFFF9B;
  v4 = *((float *)&unk_591458 + 13 * *(_DWORD *)(v2 + 28));
  *(float *)&v88 = *((float *)&unk_591458 + 13 * *(_DWORD *)(v2 + 28));
  *(float *)&v94 = v4 * v4;
  v1 = (signed __int64)(*(float *)&v94 * 0.1000000014901161);
  v0 = v1 * (100 - sub_4911F3(v3)) / 100;
  if ( v0 < v1 / 3 )
    v0 = v1 / 3;
  v5 = 1;
  v96 = v0;
  if ( v0 <= 0 )
    v96 = 1;
  v7 = (signed __int64)(*(float *)&v94 * *(float *)&v88 * 0.009999999776482582);
  v6 = v7 * (100 - sub_4911F3((void *)v90)) / 100;
  if ( v6 < v7 / 3 )
    v6 = v7 / 3;
  v88 = v6;
  if ( v6 <= 0 )
  {
    v6 = 1;
    v88 = 1;
  }
  if ( dword_F8B19C <= 101 )
  {
    if ( dword_F8B19C == 101 )
    {
      if ( sub_4B1784() )
      {
        v48 = 2;
        dword_F8B1B8[0] = pGlobalTXT_LocalizationStrings[620];
        v96 = 0;
        dword_F8B1BC = pGlobalTXT_LocalizationStrings[622];
        if ( sub_493244(651) )
        {
          dword_F8B1C0 = pGlobalTXT_LocalizationStrings[621];
          v48 = 3;
        }
        for ( i = 0; i < v48; ++i )
        {
          v50 = sub_44C59D(pFontArrus, (const char *)dword_F8B1B8[i], (int)&v82, 0, 0);
          v96 += v50;
        }
        v91 = (174 - v96) / v48;
        v51 = dword_507BBC;
        v53 = 174 - v48 * (174 - v96) / v48 - v96;
        v54 = v53 - HIDWORD(v53);
        LODWORD(v53) = *(_DWORD *)(dword_507BBC + 56);
        HIDWORD(v53) = v53 + *(_DWORD *)(dword_507BBC + 40);
        v52 = (v54 >> 1) - v91 / 2 + 138;
        v55 = -*(_DWORD *)(dword_507BBC + 40) < 0;
        v94 = *(_DWORD *)(dword_507BBC + 56);

        compile_error;//if ( v55 ^ __SETO__(v53, HIDWORD(v53)) )
        if (1)
        {
          v90 = 2;
          v96 = (int)dword_F8B1B8;
          do
          {
            v58 = GUIWindow_GetChild(v51, v94);
            v59 = (const char **)v96;
            *(_DWORD *)(v58 + 4) = v91 + v52;
            v60 = sub_44C59D(pFontArrus, *v59, (int)&v82, 0, 0);
            v57 = *(_DWORD *)(v58 + 4);
            v61 = v90;
            *(_DWORD *)(v58 + 12) = v60;
            v52 = v60 + v57 - 1;
            *(_DWORD *)(v58 + 20) = v52;
            v56 = v89[0];
            if ( *(_DWORD *)(dword_507BBC + 44) != v61 )
              v56 = v86;
            sub_44D406((int)&v82, pFontArrus, 0, v57, v56, *(const char **)v96, 3);
            v51 = dword_507BBC;
            ++v90;
            v96 += 4;
            ++v94;
          }
          while ( v94 < *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56) );
        }
      }
      return;
    }
    if ( dword_F8B19C != 1 )
    {
      if ( dword_F8B19C == 15 )
      {
        if ( pParty_global->uNumGold >= (unsigned int)v96 )
        {
          sub_492BB6(v96);
          v27 = *(_DWORD *)(dword_507BC0 + 28);
          sub_4B1E92(*(_DWORD *)(dword_507BC0 + 28), 2);
          dword_F8B19C = 0;
          while ( sub_4BD8B5() )
            ;
          sub_4B1D27();
          CVideoPlayer_UnloadAll(pVideoPlayer);
          GUIWindowDelete(dword_507BC0);
          dword_507BC0 = 0;
          if ( dword_50CBD0[0] )
            dword_50CBD0[0] = dword_50CBD0[3] != 0;
          dword_50CBD0[0 + 1] = 409;
          dword_50CBD0[0 + 2] = v27;
          dword_50CBD0[0 + 3] = 1;
LABEL_51:
          ++dword_50CBD0[0];
          return;
        }
      }
      else
      {
        if ( dword_F8B19C != 16 )
        {
          if ( dword_F8B19C == 96 && sub_4B1784() )
          {
            v8 = dword_507BBC;
            v94 = 0;
            v9 = (signed __int64)(*((float *)&unk_59145C + 13 * *(_DWORD *)(dword_507BC0 + 28)) * 500.0);
            v96 = v9 * (100 - sub_4911F3((void *)v90)) / 100;
            if ( v96 < v9 / 3 )
              v96 = v9 / 3;
            v10 = *(_DWORD *)(v8 + 56);
            v11 = v10 + *(_DWORD *)(v8 + 40);
            v91 = 0;
            if ( v10 < v11 )
            {
              do
              {
                v12 = *(_DWORD *)(GUIWindow_GetChild(v8, v10) + 36) - 36;
                if ( *(&byte_4ED970[37 * *(_BYTE *)(v90 + 185)] + v12) )
                {
                  if ( !*(_WORD *)(v90 + 2 * v12 + 264) )
                  {
                    //v13 = sub_44C59D(pFontArrus, (&dword_AE32D0)[4 * v12], (int)&v82, 0, 0);
                    v13 = sub_44C59D(pFontArrus, aSkillNames[v12], (int)&v82, 0, 0);
                    v94 += v13;
                    ++v91;
                  }
                }
                ++v10;
              }
              while ( v10 < *(_DWORD *)(v8 + 56) + *(_DWORD *)(v8 + 40) );
              if ( v91 )
              {
                sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[401], v96);
                sub_44D406((int)&v82, pFontArrus, 0, 146, 0, &TmpBuf, 3);
                v96 = (149 - v94) / v91;
                if ( (149 - v94) / v91 > 32 )
                  v96 = 32;
                v14 = (149 - v91 * v96 - v94) / 2 - v96 / 2 + 162;
                v94 = *(_DWORD *)(v8 + 56);
                v88 = v14;
                if ( v94 < v94 + *(_DWORD *)(v8 + 40) )
                {
                  v91 = 2;
                  do
                  {
                    v17 = GUIWindow_GetChild(v8, v94);
                    v16 = v17;
                    v15 = *(_DWORD *)(v17 + 36) - 36;
                    if ( !*(&byte_4ED970[37 * *(_BYTE *)(v90 + 185)] + v15) || *(_WORD *)(v90 + 2 * v15 + 264) )
                    {
                      *(_DWORD *)(v16 + 20) = 0;
                      *(_DWORD *)(v16 + 12) = 0;
                      *(_DWORD *)(v16 + 4) = 0;
                    }
                    else
                    {
                      //v20 = (&dword_AE32D0)[4 * v15];
                      v20 = aSkillNames[v15];
                      *(_DWORD *)(v16 + 4) = v96 + v88;
                      Str[1] = v20;
                      v21 = sub_44C59D(pFontArrus, v20, (int)&v82, 0, 0);
                      v19 = *(_DWORD *)(v16 + 4);
                      v22 = v91;
                      *(_DWORD *)(v16 + 12) = v21;
                      v23 = v21 + v19 - 1;
                      *(_DWORD *)(v16 + 20) = v23;
                      v88 = v23;
                      v18 = v89[0];
                      if ( *(_DWORD *)(dword_507BBC + 44) != v22 )
                        v18 = v86;
                      sub_44D406((int)&v82, pFontArrus, 0, v19, v18, Str[1], 3);
                    }
                    v24 = *(_DWORD *)(v8 + 40);
                    ++v94;
                    v25 = *(_DWORD *)(v8 + 56) + v24;
                    ++v91;
                  }
                  while ( v94 < v25 );
                }
                return;
              }
            }
            v26 = &TmpBuf;
            sprintfex(
              &TmpBuf,
              pGlobalTXT_LocalizationStrings[544],
              v90 + 168,
              //(&dword_AE31F0)[4 * *(_BYTE *)(v90 + 185)]);
              aClassNames[*(_BYTE *)(v90 + 185)]);
            strcat((char *)&TmpBuf, "\n \n");
            strcat((char *)&TmpBuf, pGlobalTXT_LocalizationStrings[528]);
            goto LABEL_97;
          }
          return;
        }
        *(_QWORD *)Str = (unsigned int)pParty_global->uNumFood;
        if ( (double)(unsigned int)pParty_global->uNumFood >= *((float *)&unk_591458 + 13 * *(_DWORD *)(dword_507BC0 + 28)) )
        {
          sub_44C175(pGlobalTXT_LocalizationStrings[140], 2);
          if ( uActiveCharacter )
            sub_4948B1(*(&ptr_A750C4 + uActiveCharacter), 67, 0);
          goto LABEL_43;
        }
        if ( pParty_global->uNumGold >= (unsigned int)v6 )
        {
          sub_492BB6(v6);
          pParty_global->uNumFood = (signed __int64)*((float *)&unk_591458 + 13 * *(_DWORD *)(dword_507BC0 + 28));
          sub_4B1E92(*(_DWORD *)(dword_507BC0 + 28), 3);
          v5 = 1;
LABEL_43:
          if ( dword_50CBD0[0] >= 40 )
            return;
          dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
          dword_50CBD0[3 * dword_50CBD0[0] + 2] = v5;
          dword_50CBD0[3 * dword_50CBD0[0] + 3] = 0;
          goto LABEL_51;
        }
      }
      sub_44C175(pGlobalTXT_LocalizationStrings[155], 2);
      sub_4B1E92(*(_DWORD *)(dword_507BC0 + 28), 4);
      goto LABEL_43;
    }
    if ( !sub_4B1784() )
      return;
    v28 = *(_DWORD *)v89;
    if ( *(_DWORD *)(dword_507BBC + 44) != 2 )
      v28 = v86;
    sprintfex(&Dest, (const char *)&unk_4E2DC8, v28);
    sprintfex(pStringBuffer, pGlobalTXT_LocalizationStrings[178], v96);
    strcat(&Dest, pStringBuffer);
    v95 = sub_44C59D(pFontArrus, &Dest, (int)&v82, 0, 0);
    strcat(&Dest, "\n \n");
    v29 = *(_DWORD *)v89;
    if ( *(_DWORD *)(dword_507BBC + 44) != 3 )
      v29 = v86;
    sprintfex(&v77, (const char *)&unk_4E2DC8, v29);
    sprintfex(
      pStringBuffer,
      pGlobalTXT_LocalizationStrings[86],
      (signed __int64)*((float *)&unk_591458 + 13 * *(_DWORD *)(dword_507BC0 + 28)),
      v88);
    strcat(&v77, pStringBuffer);
    v93 = sub_44C59D(pFontArrus, &v77, (int)&v82, 0, 0);
    strcat(&v77, "\n \n");
    v30 = *(_DWORD *)v89;
    if ( *(_DWORD *)(dword_507BBC + 44) != 4 )
      v30 = v86;
    sprintfex(&v78, (const char *)&unk_4E2DC8, v30);
    strcat(&v78, pGlobalTXT_LocalizationStrings[160]);
    v87 = sub_44C59D(pFontArrus, &v78, (int)&v82, 0, 0);
    strcat(&v78, "\n \n");
    v76 = 0;
    v92 = 0;
    v31 = *(_DWORD *)(dword_507BC0 + 28);
    if ( v31 >= 108 )
    {
      if ( v31 <= 120 )
      {
        v32 = *(_DWORD *)v89;
        if ( *(_DWORD *)(dword_507BBC + 44) != 5 )
          v32 = v86;
        sprintfex(&v76, (const char *)&unk_4E2DC8, v32);
        strcat(&v76, pGlobalTXT_LocalizationStrings[611]);
        v92 = sub_44C59D(pFontArrus, &v76, (int)&v82, 0, 0);
      }
    }
    v33 = dword_507BBC;
    Str[1] = (char *)dword_507BBC;
    v35 = *(_DWORD *)(dword_507BBC + 56);
    v36 = v35 + *(_DWORD *)(dword_507BBC + 40);
    v34 = *(_BYTE *)(pFontArrus + 5) - 3;
    v37 = -*(_DWORD *)(dword_507BBC + 40) < 0;
    v96 = *(_DWORD *)(dword_507BBC + 56);
    
    compile_error;//if ( !(v37 ^ __SETO__(v35, v36)) )
    if (1)
    {
LABEL_75:
      sprintfex(&TmpBuf, "%s%s%s%s", &Dest, &v77, &v78, &v76);
      v72 = 3;
      v70 = &TmpBuf;
      v68 = 0;
      v67 = 146;
LABEL_98:
      sub_44D406((int)&v82, pFontArrus, 0, v67, v68, v70, v72);
      return;
    }
    while ( 1 )
    {
      v38 = GUIWindow_GetChild(v33, v96);
      if ( *(_DWORD *)(v38 + 36) == 15 )
      {
        v46 = v95;
        *(_DWORD *)(v38 + 12) = v95;
        *(_DWORD *)(v38 + 4) = 146;
        v39 = v46 + 145;
        goto LABEL_73;
      }
      if ( *(_DWORD *)(v38 + 36) == 16 )
      {
        v44 = v93;
        v45 = v95 + v34 + 146;
        *(_DWORD *)(v38 + 12) = v93;
        *(_DWORD *)(v38 + 4) = v45;
        v39 = v45 + v44 - 1;
        goto LABEL_73;
      }
      if ( *(_DWORD *)(v38 + 36) == 96 )
        break;
      if ( *(_DWORD *)(v38 + 36) == 101 )
      {
        v40 = v95 + 3 * v34 + v92 + v93 + 146;
        v33 = (int)Str[1];
        v41 = v92;
        *(_DWORD *)(v38 + 12) = v92;
        *(_DWORD *)(v38 + 4) = v40;
        v39 = v40 + v41 - 1;
LABEL_73:
        *(_DWORD *)(v38 + 20) = v39;
      }
      v47 = *(_DWORD *)(v33 + 56);
      ++v96;
      if ( v96 >= *(_DWORD *)(v33 + 40) + v47 )
        goto LABEL_75;
    }
    v42 = v95 + v93 + 2 * v34 + 146;
    v43 = v87;
    *(_DWORD *)(v38 + 4) = v42;
    *(_DWORD *)(v38 + 12) = v43;
    v39 = v43 + v42 - 1;
    goto LABEL_73;
  }
  if ( dword_F8B19C == 102 )
  {
    v66 = pFontArrus;
    v96 = pFontArrus;
    strcpy((char *)&TmpBuf, dword_72217C);
    v80 = 460;
    v81 = 452;
    v64 = sub_44C59D(v66, &TmpBuf, (int)&v79, 12, 0) + 7;
    if ( 352 - v64 < 8 )
    {
      v96 = pFontCreate;
      v64 = sub_44C59D(pFontCreate, &TmpBuf, (int)&v79, 12, 0) + 7;
    }
    sub_4A6A68(
      pD3DRenderer,
      8,
      352 - v64,
      uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 : 0,
      *(_WORD *)(uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 + 0x1A : 26) - v64);
    Render_DrawIndexedTexture(pD3DRenderer, 8, 347 - v64, pClass18_EndcapTexture);
    v74 = 0;
    v71 = 0;
    v69 = 0;
    v62 = FitTextInAWindow(&TmpBuf, v96, (int)&v79, 12, 0);
    v63 = v96;
    goto LABEL_103;
  }
  if ( dword_F8B19C == 103 )
  {
    compile_error;//strcpy((char *)&TmpBuf, *(const char **)&dword_721E24[8 * *(_DWORD *)(dword_507BC0 + 28)]);
    v80 = 460;
    v81 = 452;
    v65 = sub_44C59D(pFontArrus, &TmpBuf, (int)&v79, 12, 0);
    v64 = v65 + 7;
    sub_4A6A68(
      pD3DRenderer,
      8,
      352 - (v65 + 7),
      uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 : 0,
      *(_WORD *)(uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 + 0x1A : 26) - (v65 + 7));
    Render_DrawIndexedTexture(pD3DRenderer, 8, 347 - v64, pClass18_EndcapTexture);
    v74 = 0;
    v71 = 0;
    v69 = 0;
    v62 = FitTextInAWindow(&TmpBuf, pFontArrus, (int)&v79, 12, 0);
    v63 = pFontArrus;
LABEL_103:
    FontDrawText(dword_507BC0, v63, 12, 354 - v64, v62, v69, v71, v74);
    return;
  }
  if ( dword_F8B19C == 104 && struct_505898.byte_505992 != 1 )
  {
    v26 = &TmpBuf;
    if ( struct_505898.dword_505944 )
    {
      if ( struct_505898.dword_505944 == 1 )
        v73 = pGlobalTXT_LocalizationStrings[640];
      else
        v73 = pGlobalTXT_LocalizationStrings[641];
    }
    else
    {
      v73 = pGlobalTXT_LocalizationStrings[639];
    }
    strcpy((char *)&TmpBuf, v73);
LABEL_97:
    v72 = 3;
    v70 = v26;
    v68 = v89[0];
    v67 = (174 - sub_44C59D(pFontArrus, v26, (int)&v82, 0, 0)) / 2 + 138;
    goto LABEL_98;
  }
}

//----- (004B8E3D) --------------------------------------------------------
int __cdecl sub_4B8E3D()
{
  int v0; // eax@1
  signed int v1; // edi@1
  signed int v2; // esi@1
  signed int v3; // ecx@3
  int v4; // ecx@3
  int v5; // ebx@3
  bool v6; // ebp@5
  int v7; // ecx@5
  int result; // eax@15
  signed int v9; // [sp-Ch] [bp-14h]@7

  v0 = dword_507BC0;
  v1 = 0;
  v2 = *(_DWORD *)(dword_507BC0 + 28);
  if ( byte_4F063C[word_591438[26 * *(_DWORD *)(dword_507BC0 + 28)]] )
  {
    while ( v2 > 14 )
    {
      if ( v2 <= 28 )
      {
        v6 = v1 > 3;
        v7 = v6 - 30 + 2 * v2;
        v2 = *(_DWORD *)(v0 + 28);
        v5 = word_4F0498[5 * v7];
        v3 = *(_WORD *)&aTooManyStation[2 * (5 * (v6 + 2 * v2) + rand() % 4) + 10];
        goto LABEL_13;
      }
      if ( v2 <= 41 )
      {
        v5 = word_4F0576[v2];
        v9 = 22;
        goto LABEL_12;
      }
      if ( v2 <= 53 )
      {
        if ( v1 >= 6 )
        {
          v5 = word_4F0578[v2];
          v9 = 45;
LABEL_12:
          v3 = v9;
LABEL_13:
          sub_456620(pClass40, v5, v3, 36 * (v1 + 12 * v2) + 11355956);
          v0 = dword_507BC0;
          dword_AD4748[9 * (v1 + 12 * *(_DWORD *)(dword_507BC0 + 28))] = 1;
          goto LABEL_14;
        }
        ItemGen_Reset(36 * (v1 + 12 * v2) + 11355956);
        v0 = dword_507BC0;
        dword_AD4734[9 * (v1 + 12 * *(_DWORD *)(dword_507BC0 + 28))] = 220;
      }
LABEL_14:
      v2 = *(_DWORD *)(v0 + 28);
      ++v1;
      if ( v1 >= (unsigned __int8)byte_4F063C[word_591438[26 * *(_DWORD *)(v0 + 28)]] )
        goto LABEL_15;
    }
    v4 = 5 * v2;
    v2 = *(_DWORD *)(v0 + 28);
    v5 = word_4F03FE[v4];
    v3 = word_4F0400[5 * v2 + rand() % 4];
    goto LABEL_13;
  }
LABEL_15:
  result = *(_DWORD *)(v0 + 28);
  dword_AE310C[result] = 0;
  return result;
}

//----- (004B8F94) --------------------------------------------------------
int __cdecl sub_4B8F94()
{
  int v0; // ebx@1
  signed int v1; // ebp@1
  int v2; // edi@1
  signed int v3; // esi@1
  int v4; // eax@3
  signed int v5; // ecx@3
  int v6; // ebx@3
  bool v7; // eax@5
  bool v8; // ST1C_4@5
  int v9; // eax@5
  int result; // eax@15
  signed int v11; // [sp-4h] [bp-18h]@7

  v2 = dword_507BC0;
  v1 = 0;
  v0 = dword_507BC0 + 28;
  v3 = *(_DWORD *)(dword_507BC0 + 28);
  if ( byte_4F063C[word_591438[26 * *(_DWORD *)(dword_507BC0 + 28)]] )
  {
    while ( v3 > 14 )
    {
      if ( v3 <= 28 )
      {
        v7 = v1 > 3;
        v8 = v7;
        v9 = 5 * (v7 + 2 * v3 - 30);
        v3 = *(_DWORD *)(v2 + 28);
        v6 = word_4F06D8[v9];
        v5 = word_4F05AE[5 * (v8 + 2 * v3) + rand() % 4];
        goto LABEL_13;
      }
      if ( v3 <= 41 )
      {
        v6 = word_4F07B6[v3];
        v11 = 22;
        goto LABEL_12;
      }
      if ( v3 <= 53 )
      {
        if ( v1 >= 6 )
        {
          v6 = word_4F07B8[v3];
          v11 = 44;
LABEL_12:
          v5 = v11;
LABEL_13:
          sub_456620(pClass40, v6, v5, 36 * (v1 + 12 * v3) + 11378852);
          v2 = dword_507BC0;
          v0 = dword_507BC0 + 28;
          dword_ADA0B8[9 * (v1 + 12 * *(_DWORD *)(dword_507BC0 + 28))] = 1;
          goto LABEL_14;
        }
        ItemGen_Reset(36 * (v1 + 12 * v3) + 11378852);
        v0 = v2 + 28;
        v2 = dword_507BC0;
        *(&dword_ADA0A4 + 9 * (v1 + 12 * *(_DWORD *)v0)) = rand() % 32 + 740;
      }
LABEL_14:
      v3 = *(_DWORD *)v0;
      ++v1;
      if ( v1 >= (unsigned __int8)byte_4F063C[word_591438[26 * *(_DWORD *)v0]] )
        goto LABEL_15;
    }
    v4 = 5 * v3;
    v3 = *(_DWORD *)(v2 + 28);
    v6 = word_4F063E[v4];
    v5 = word_4F0640[5 * v3 + rand() % 4];
    goto LABEL_13;
  }
LABEL_15:
  result = *(_DWORD *)(v2 + 28);
  dword_AE310C[result] = 0;
  return result;
}

//----- (004B910F) --------------------------------------------------------
int __cdecl sub_4B910F()
{
  void *v0; // ebx@1
  int result; // eax@6
  signed int v2; // esi@8
  int v3; // ebx@10
  int v4; // eax@11
  int v5; // ecx@12
  unsigned __int8 v6; // dl@13
  const char *v7; // edx@14
  int v8; // eax@15
  int v9; // ST08_4@16
  int v10; // eax@16
  signed int v11; // esi@18
  int v12; // ST08_4@21
  int v13; // eax@21
  int v14; // edi@23
  const char **v15; // esi@23
  int v16; // eax@24
  int v17; // ecx@25
  int v18; // edi@25
  int v19; // edx@25
  unsigned __int8 v20; // sf@25
  unsigned __int16 v21; // ax@27
  int v22; // ecx@27
  int v23; // esi@27
  const char **v24; // eax@27
  int v25; // eax@27
  int v26; // edx@27
  signed int v27; // esi@32
  int v28; // ST08_4@36
  int v29; // eax@36
  int v30; // edi@41
  signed int v31; // esi@41
  int v32; // eax@41
  int v33; // esi@43
  int v34; // eax@43
  int v35; // eax@44
  int v36; // eax@46
  int v37; // ecx@51
  int v38; // eax@53
  int v39; // esi@53
  int v40; // eax@53
  unsigned __int16 v41; // ax@55
  int v42; // ecx@55
  char *v43; // eax@55
  int v44; // eax@55
  int v45; // edx@55
  int v46; // eax@55
  int v47; // eax@59
  signed int v48; // eax@63
  int v49; // esi@65
  int v50; // eax@65
  int v51; // edi@65
  int v52; // esi@70
  int v53; // ST1C_4@70
  int v54; // edi@70
  signed int v55; // ecx@73
  bool v56; // eax@82
  SHORT v57; // di@82
  const char *v58; // ecx@84
  int v59; // esi@89
  int v60; // eax@90
  int v61; // ecx@90
  int v62; // esi@90
  int v63; // ecx@90
  int v64; // eax@95
  const char **v65; // edi@96
  int v66; // esi@96
  int v67; // eax@97
  int v68; // ecx@98
  int v69; // edi@98
  int v70; // edx@98
  unsigned __int8 v71; // sf@98
  unsigned __int16 v72; // ax@100
  int v73; // ecx@100
  int v74; // esi@100
  const char **v75; // eax@100
  int v76; // eax@100
  int v77; // edx@100
  int v78; // [sp-18h] [bp-110h]@14
  char v79; // [sp-14h] [bp-10Ch]@14
  int v80; // [sp-10h] [bp-108h]@12
  int v81; // [sp-10h] [bp-108h]@14
  int v82; // [sp-Ch] [bp-104h]@12
  unsigned __int16 v83; // [sp-Ch] [bp-104h]@14
  int v84; // [sp-8h] [bp-100h]@11
  const char *v85; // [sp-8h] [bp-100h]@14
  __int64 *v86; // [sp-4h] [bp-FCh]@11
  int v87; // [sp-4h] [bp-FCh]@14
  char v88; // [sp+Ch] [bp-ECh]@8
  char v89; // [sp+14h] [bp-E4h]@18
  char v90; // [sp+1Ch] [bp-DCh]@89
  char v91; // [sp+24h] [bp-D4h]@19
  char v92; // [sp+2Ch] [bp-CCh]@89
  char v93; // [sp+34h] [bp-C4h]@9
  char v94; // [sp+3Ch] [bp-BCh]@33
  char v95; // [sp+44h] [bp-B4h]@18
  char v96; // [sp+4Ch] [bp-ACh]@32
  char v97; // [sp+54h] [bp-A4h]@18
  char v98; // [sp+5Ch] [bp-9Ch]@32
  char v99; // [sp+64h] [bp-94h]@8
  char v100; // [sp+6Ch] [bp-8Ch]@32
  char v101; // [sp+74h] [bp-84h]@8
  int v102; // [sp+7Ch] [bp-7Ch]@1
  int v103; // [sp+84h] [bp-74h]@1
  int v104; // [sp+8Ch] [bp-6Ch]@1
  char *Str; // [sp+D0h] [bp-28h]@55
  int v106; // [sp+D4h] [bp-24h]@25
  __int16 v107[2]; // [sp+D8h] [bp-20h]@1
  __int16 v108[2]; // [sp+DCh] [bp-1Ch]@1
  int v109; // [sp+E0h] [bp-18h]@8
  int v110; // [sp+E4h] [bp-14h]@41
  int v111; // [sp+E8h] [bp-10h]@1
  int v112; // [sp+ECh] [bp-Ch]@26
  int v113; // [sp+F0h] [bp-8h]@26
  unsigned __int8 v114; // [sp+F7h] [bp-1h]@16

  v0 = *(&ptr_A750C4 + uActiveCharacter);
  v111 = (int)*(&ptr_A750C4 + uActiveCharacter);
  memcpy(&v102, (const void *)dword_507BC0, 0x54u);
  v102 = 483;
  v103 = 148;
  v104 = 334;
  *(_DWORD *)v108 = 0xFFFFFFFF;
  *(_DWORD *)v107 = 0xFFE1CD23;
  if ( dword_F8B19C > 5 )
  {
    if ( dword_F8B19C == 94 )
    {
      sub_41A556();
      GameUI_DrawInventory(uActiveCharacter, 1);
      dword_F8B1B8[0] = pGlobalTXT_LocalizationStrings[200];
      dword_F8B1BC = pGlobalTXT_LocalizationStrings[113];
      dword_F8B1C0 = pGlobalTXT_LocalizationStrings[179];
      v66 = 0;
      v65 = (const char **)dword_F8B1B8;
      do
      {
        v67 = sub_44C59D(pFontArrus, *v65, (int)&v102, 0, 0);
        ++v65;
        v66 += v67;
      }
      while ( (signed int)v65 < (signed int)&dword_F8B1C4 );
      v68 = dword_507BBC;
      v113 = (174 - v66) / 3;
      result = *(_DWORD *)(dword_507BBC + 56);
      v70 = result + *(_DWORD *)(dword_507BBC + 40);
      v69 = (3 * (58 - v113) - v66) / 2 - (174 - v66) / 3 / 2 + 138;
      v71 = -*(_DWORD *)(dword_507BBC + 40) < 0;
      v110 = *(_DWORD *)(dword_507BBC + 56);

      compile_error;//if ( v71 ^ __SETO__(result, v70) )
      if (1)
      {
        v111 = 2;
        v112 = (int)dword_F8B1B8;
        do
        {
          v74 = GUIWindow_GetChild(v68, v110);
          v75 = (const char **)v112;
          *(_DWORD *)(v74 + 4) = v113 + v69;
          v76 = sub_44C59D(pFontArrus, *v75, (int)&v102, 0, 0);
          v73 = *(_DWORD *)(v74 + 4);
          v77 = v111;
          *(_DWORD *)(v74 + 12) = v76;
          v69 = v76 + v73 - 1;
          *(_DWORD *)(v74 + 20) = v69;
          v72 = v107[0];
          if ( *(_DWORD *)(dword_507BBC + 44) != v77 )
            v72 = v108[0];
          sub_44D406((int)&v102, pFontArrus, 0, v73, v72, *(const char **)v112, 3);
          v68 = dword_507BBC;
          ++v111;
          v112 += 4;
          ++v110;
          result = *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56);
        }
        while ( v110 < result );
      }
      return result;
    }
    if ( dword_F8B19C != 95 )
    {
      result = dword_F8B19C - 96;
      if ( dword_F8B19C == 96 )
      {
        result = sub_4B1784();
        if ( result )
        {
          v30 = dword_507BBC;
          v3 = 0;
          v32 = *(_DWORD *)(dword_507BC0 + 28);
          v110 = 0;
          v31 = (signed __int64)(*((float *)&unk_59145C + 13 * v32) * 500.0);
          v112 = v31 * (100 - sub_4911F3((void *)v111)) / 100;
          if ( v112 < v31 / 3 )
            v112 = v31 / 3;
          v33 = *(_DWORD *)(v30 + 56);
          v34 = v33 + *(_DWORD *)(v30 + 40);
          v113 = 0;
          if ( v33 >= v34 )
            goto LABEL_105;
          do
          {
            v35 = *(_DWORD *)(GUIWindow_GetChild(v30, v33) + 36) - 36;
            if ( *(&byte_4ED970[37 * *(_BYTE *)(v111 + 185)] + v35) )
            {
              if ( !*(_WORD *)(v111 + 2 * v35 + 264) )
              {
                //v36 = sub_44C59D(pFontArrus, (&dword_AE32D0)[4 * v35], (int)&v102, 0, 0);
                v36 = sub_44C59D(pFontArrus, aSkillNames[v35], (int)&v102, 0, 0);
                v110 += v36;
                ++v113;
              }
            }
            ++v33;
          }
          while ( v33 < *(_DWORD *)(v30 + 40) + *(_DWORD *)(v30 + 56) );
          if ( !v113 )
          {
LABEL_105:
            sprintfex(
              &TmpBuf,
              pGlobalTXT_LocalizationStrings[544],
              v111 + 168,
              //(&dword_AE31F0)[4 * *(_BYTE *)(v111 + 185)]);
              aClassNames[*(_BYTE *)(v111 + 185)]);
            strcat((char *)&TmpBuf, "\n \n");
            strcat((char *)&TmpBuf, pGlobalTXT_LocalizationStrings[528]);
            v7 = &TmpBuf;
            v87 = 3;
            v85 = &TmpBuf;
            v83 = v107[0];
            v81 = 0;
            v79 = 0;
            v78 = (int)&v102;
            goto LABEL_15;
          }
          sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[401], v112);
          sub_44D406((int)&v102, pFontArrus, 0, 146, 0, &TmpBuf, 3);
          v112 = (149 - v110) / v113;
          if ( (149 - v110) / v113 > 32 )
            v112 = 32;
          result = *(_DWORD *)(v30 + 56);
          v37 = (149 - v113 * v112 - v110) / 2 - v112 / 2 + 162;
          v110 = result;
          v106 = v37;
          if ( result < result + *(_DWORD *)(v30 + 40) )
          {
            v113 = 2;
            do
            {
              v40 = GUIWindow_GetChild(v30, v110);
              v39 = v40;
              v38 = *(_DWORD *)(v40 + 36) - 36;
              if ( !*(&byte_4ED970[37 * *(_BYTE *)(v111 + 185)] + v38) || *(_WORD *)(v111 + 2 * v38 + 264) )
              {
                *(_DWORD *)(v39 + 20) = 0;
                *(_DWORD *)(v39 + 12) = 0;
                *(_DWORD *)(v39 + 4) = 0;
              }
              else
              {
                //v43 = (&dword_AE32D0)[4 * v38];
                v43 = aSkillNames[v38];
                *(_DWORD *)(v39 + 4) = v112 + v106;
                Str = v43;
                v44 = sub_44C59D(pFontArrus, v43, (int)&v102, 0, 0);
                v42 = *(_DWORD *)(v39 + 4);
                v45 = v113;
                *(_DWORD *)(v39 + 12) = v44;
                v46 = v42 + v44 - 1;
                *(_DWORD *)(v39 + 20) = v46;
                v106 = v46;
                v41 = v107[0];
                if ( *(_DWORD *)(dword_507BBC + 44) != v45 )
                  v41 = v108[0];
                sub_44D406((int)&v102, pFontArrus, 0, v42, v41, Str, 3);
              }
              v47 = *(_DWORD *)(v30 + 56);
              ++v110;
              result = *(_DWORD *)(v30 + 40) + v47;
              ++v113;
            }
            while ( v110 < result );
          }
        }
      }
      return result;
    }
  }
  else
  {
    if ( dword_F8B19C == 5 )
    {
      sub_41A556();
      GameUI_DrawInventory(uActiveCharacter, 1);
      sub_4B46A5(pGlobalTXT_LocalizationStrings[198], 0);
      result = sub_4B1784();
      if ( result )
      {
        v27 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v100) - 14;
        v109 = (v27 >> 5) + 14 * ((*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v98) + 4) - 17) >> 5);
        result = class03_GetMousePos(pGame->pClass03, (int)&v96);
        if ( *(_DWORD *)result > 13 )
        {
          result = class03_GetMousePos(pGame->pClass03, (int)&v94);
          if ( *(_DWORD *)result < 462 )
          {
            result = sub_421E75(v0, (int)&v109);
            v3 = 0;
            if ( result )
            {
              result *= 9;
              if ( *(_BYTE *)(v111 + 4 * result + 516) & 2 )
              {
                v86 = 0;
                v84 = 5;
                v82 = *(_DWORD *)(dword_507BC0 + 28);
                v80 = v111 + 4 * result + 496;
                v28 = *(_DWORD *)(dword_507BC0 + 28);
                v114 = uActiveCharacter - 1;
                v29 = sub_490EEE((void *)v111, v111 + 4 * result + 496, 1, v28, 5);
                v6 = v114;
                v5 = *(_DWORD *)&dword_73C3C0[4 * v29];
                goto LABEL_14;
              }
            }
          }
        }
      }
      return result;
    }
    if ( dword_F8B19C == 1 )
    {
      result = sub_4B1784();
      if ( result )
      {
        dword_F8B1B8[0] = pGlobalTXT_LocalizationStrings[134];
        dword_F8B1BC = pGlobalTXT_LocalizationStrings[152];
        dword_F8B1C0 = pGlobalTXT_LocalizationStrings[636];
        v14 = 0;
        dword_F8B1C4 = pGlobalTXT_LocalizationStrings[160];
        v15 = (const char **)dword_F8B1B8;
        do
        {
          v16 = sub_44C59D(pFontArrus, *v15, (int)&v102, 0, 0);
          ++v15;
          v14 += v16;
        }
        while ( (signed int)v15 < (signed int)&unk_F8B1C8 );
        v17 = dword_507BBC;
        v106 = (174 - v14) / 4;
        result = *(_DWORD *)(dword_507BBC + 56);
        v19 = result + *(_DWORD *)(dword_507BBC + 40);
        v18 = (174 - 4 * (174 - v14) / 4 - v14) / 2 - (174 - v14) / 4 / 2 + 138;
        v20 = -*(_DWORD *)(dword_507BBC + 40) < 0;
        v111 = *(_DWORD *)(dword_507BBC + 56);
        
        compile_error;//if ( v20 ^ __SETO__(result, v19) )
        if (1)
        {
          v112 = 2;
          v113 = (int)dword_F8B1B8;
          do
          {
            v23 = GUIWindow_GetChild(v17, v111);
            v24 = (const char **)v113;
            *(_DWORD *)(v23 + 4) = v106 + v18;
            v25 = sub_44C59D(pFontArrus, *v24, (int)&v102, 0, 0);
            v22 = *(_DWORD *)(v23 + 4);
            v26 = v112;
            *(_DWORD *)(v23 + 12) = v25;
            v18 = v22 + v25 - 1;
            *(_DWORD *)(v23 + 20) = v18;
            v21 = v107[0];
            if ( *(_DWORD *)(dword_507BBC + 44) != v26 )
              v21 = v108[0];
            sub_44D406((int)&v102, pFontArrus, 0, v22, v21, *(const char **)v113, 3);
            v17 = dword_507BBC;
            ++v112;
            v113 += 4;
            ++v111;
            result = *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56);
          }
          while ( v111 < result );
        }
      }
      return result;
    }
    if ( dword_F8B19C != 2 )
    {
      if ( dword_F8B19C == 3 )
      {
        sub_41A556();
        GameUI_DrawInventory(uActiveCharacter, 1);
        sub_4B46A5(pGlobalTXT_LocalizationStrings[199], 0);
        result = sub_4B1784();
        if ( result )
        {
          v11 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v97) - 14;
          v109 = (v11 >> 5) + 14 * ((*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v89) + 4) - 17) >> 5);
          result = class03_GetMousePos(pGame->pClass03, (int)&v95);
          if ( *(_DWORD *)result > 13 )
          {
            result = class03_GetMousePos(pGame->pClass03, (int)&v91);
            if ( *(_DWORD *)result < 462 )
            {
              result = sub_421E75(v0, (int)&v109);
              v3 = 0;
              if ( result )
              {
                v86 = 0;
                v84 = 3;
                v82 = *(_DWORD *)(dword_507BC0 + 28);
                v80 = v111 + 36 * result + 496;
                v12 = *(_DWORD *)(dword_507BC0 + 28);
                v114 = uActiveCharacter - 1;
                v13 = sub_490EEE((void *)v111, v80, 1, v12, 3);
                v6 = v114;
                v5 = dword_73C3A4[v13];
                goto LABEL_14;
              }
            }
          }
        }
      }
      else
      {
        result = dword_F8B19C - 4;
        if ( dword_F8B19C == 4 )
        {
          sub_41A556();
          GameUI_DrawInventory(uActiveCharacter, 1);
          sub_4B46A5(pGlobalTXT_LocalizationStrings[197], 0);
          result = sub_4B1784();
          if ( result )
          {
            v2 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v99) - 14;
            v109 = (v2 >> 5) + 14 * ((*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v88) + 4) - 17) >> 5);
            result = class03_GetMousePos(pGame->pClass03, (int)&v101);
            if ( *(_DWORD *)result > 13 )
            {
              result = class03_GetMousePos(pGame->pClass03, (int)&v93);
              if ( *(_DWORD *)result < 462 )
              {
                result = sub_421E75(v0, (int)&v109);
                v3 = 0;
                if ( result )
                {
                  v86 = 0;
                  v84 = 4;
                  v4 = v111 + 36 * result + 496;
                  if ( !(*(_BYTE *)(v4 + 20) & 1) )
                  {
                    v82 = *(_DWORD *)(dword_507BC0 + 28);
                    v80 = v4;
                    v9 = *(_DWORD *)(dword_507BC0 + 28);
                    v114 = uActiveCharacter - 1;
                    v10 = sub_490EEE((void *)v111, v4, 1, v9, 4);
                    v6 = v114;
                    v5 = dword_73C3DC[v10];
                    goto LABEL_14;
                  }
                  v82 = *(_DWORD *)(dword_507BC0 + 28);
                  v5 = (int)"%24";
                  v80 = v4;
LABEL_13:
                  v6 = uActiveCharacter - 1;
LABEL_14:
                  v7 = sub_495461((char *)v5, v6, v80, v82, v84, v86);
                  v87 = 3;
                  v85 = v7;
                  v83 = v108[0];
                  v81 = v3;
                  v79 = v3;
                  v78 = (int)&v102;
LABEL_15:
                  v8 = sub_44C59D(pFontArrus, v7, v78, v79, v81);
                  return (int)sub_44D406((int)&v102, pFontArrus, v3, (174 - v8) / 2 + 138, v83, v85, v87);
                }
              }
            }
          }
        }
      }
      return result;
    }
  }
  Render_DrawIndexedTexture(pD3DRenderer, 8, 8, dword_F8B164[0]);
  v3 = 0;
  if ( dword_F8B19C == 2 )
  {
    v48 = 0;
    v112 = 0;
    v113 = 0;
    do
    {
      if ( dword_AD4734[9 * (v48 + 12 * *(_DWORD *)(dword_507BC0 + 28))] )
      {
        v49 = word_F8B158[v48];
        v50 = dword_F8B168[v48];
        v49 += 30;
        v51 = 60 - ((signed int)*(_WORD *)(v50 + 24) >> 1);
        Render_DrawTransparentTexture(pD3DRenderer, v51 + v112, v49, v50);
        sub_40F92A(pD3DRenderer->pActiveZBuffer + 4 * (v51 + v112 + 640 * v49), dword_F8B168[v113], v113 + 1);
        v48 = v113;
      }
      v112 += 70;
      ++v48;
      v113 = v48;
    }
    while ( v48 < 6 );
  }
  else
  {
    v113 = 0;
    v112 = 0;
    do
    {
      if ( *(&dword_ADA0A4 + 9 * (v113 + 12 * *(_DWORD *)(dword_507BC0 + 28))) )
      {
        v52 = word_F8B158[v113] + 30;
        v53 = dword_F8B168[v113];
        v54 = 60 - ((signed int)*(_WORD *)(v53 + 24) >> 1);
        Render_DrawTransparentTexture(pD3DRenderer, v54 + v112, word_F8B158[v113] + 30, v53);
        sub_40F92A(pD3DRenderer->pActiveZBuffer + 4 * (v54 + v112 + 640 * v52), dword_F8B168[v113], v113 + 1);
      }
      ++v113;
      v112 += 70;
    }
    while ( v113 < 6 );
  }
  result = sub_4B1784();
  if ( result )
  {
    v55 = 0;
    v109 = 0;
    if ( dword_F8B19C == 2 )
    {
      v109 = 0;
      do
      {
        if ( dword_AD4734[9 * (v55 + 12 * *(_DWORD *)(dword_507BC0 + 28))] )
          ++v109;
        ++v55;
      }
      while ( v55 < 6 );
    }
    else
    {
      do
      {
        if ( *(&dword_ADA0A4 + 9 * (v55 + 12 * *(_DWORD *)(dword_507BC0 + 28))) )
          ++v109;
        ++v55;
      }
      while ( v55 < 6 );
    }
    v57 = GetAsyncKeyState(17);
    v56 = sub_492C40((void *)v111);
    Str = (char *)v56;
    if ( v57 && v56 )
    {
      v58 = pGlobalTXT_LocalizationStrings[185];
    }
    else
    {
      v58 = pGlobalTXT_LocalizationStrings[195];
      if ( dword_F8B19C != 2 )
        v58 = pGlobalTXT_LocalizationStrings[196];
    }
    sub_4B46A5(v58, 0);
    if ( v109 )
    {
      v59 = class03_GetMousePos(pGame->pClass03, (int)&v92);
      result = *(_DWORD *)v59 + dword_5059A8[*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v90) + 4)];
      if ( *(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * result) & 0xFFFF )
      {
        v63 = (*(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * result) & 0xFFFF) - 1;
        v109 = v63;
        v60 = *(_DWORD *)(dword_507BC0 + 28);
        v61 = 9 * (v63 + 12 * v60);
        v62 = 4 * v61 + 11355956;
        if ( dword_F8B19C != 2 )
          v62 = 4 * v61 + 11378852;
        if ( !v57 || !Str )
        {
          v86 = 0;
          v84 = 2;
          v82 = *(_DWORD *)(dword_507BC0 + 28);
          v80 = v62;
          v114 = uActiveCharacter - 1;
          v64 = sub_490EEE((void *)v111, v62, 1, v60, 2);
          v6 = v114;
          v5 = *(_DWORD *)&dword_73C388[4 * v64];
          goto LABEL_14;
        }
        v5 = pGlobalTXT_LocalizationStrings[181];
        v86 = 0;
        v84 = 2;
        v82 = *(_DWORD *)(dword_507BC0 + 28);
        v80 = v62;
        goto LABEL_13;
      }
    }
    else
    {
      compile_error;//result = (int)sub_4B1854(
                    //  &v102,
                    //  __PAIR__(
                    //    dword_ACD048[2 * *(_DWORD *)(dword_507BC0 + 28)],
                    //    dword_ACD044[2 * *(_DWORD *)(dword_507BC0 + 28)])
                    //- pParty_global->qword_00002C);
    }
  }
  return result;
}

//----- (004B9CC6) --------------------------------------------------------
signed int __cdecl sub_4B9CC6()
{
  void *v0; // ebx@1
  signed int result; // eax@7
  int v2; // ebx@9
  int v3; // edi@9
  signed int v4; // esi@9
  int v5; // eax@9
  int v6; // esi@11
  int v7; // eax@11
  int v8; // eax@12
  int v9; // eax@14
  int v10; // ecx@19
  int v11; // eax@21
  int v12; // esi@21
  int v13; // eax@21
  unsigned __int16 v14; // ax@23
  int v15; // ecx@23
  char *v16; // eax@23
  int v17; // eax@23
  int v18; // edx@23
  int v19; // eax@23
  int v20; // eax@27
  const char *v21; // edx@29
  const char **v22; // edi@30
  int v23; // esi@30
  int v24; // eax@31
  int v25; // ecx@32
  int v26; // edi@32
  int v27; // edx@32
  unsigned __int8 v28; // sf@32
  unsigned __int16 v29; // ax@34
  int v30; // ecx@34
  int v31; // esi@34
  const char **v32; // eax@34
  int v33; // eax@34
  int v34; // edx@34
  int v35; // eax@34
  signed int v36; // esi@39
  int v37; // eax@42
  int v38; // ecx@43
  unsigned __int8 v39; // dl@44
  int v40; // eax@46
  int v41; // ST08_4@47
  int v42; // eax@47
  signed int v43; // esi@49
  int v44; // ST08_4@52
  int v45; // eax@52
  int v46; // ecx@55
  int v47; // edi@55
  int v48; // esi@57
  int v49; // edx@61
  int v50; // ecx@67
  int v51; // edi@67
  int v52; // esi@69
  int v53; // edx@73
  int v54; // ecx@79
  int v55; // edi@79
  int v56; // esi@81
  int v57; // edx@85
  int v58; // ecx@91
  int v59; // edi@91
  int v60; // esi@93
  int v61; // edx@97
  signed int v62; // ecx@102
  bool v63; // eax@110
  SHORT v64; // di@110
  const char *v65; // ecx@112
  int v66; // esi@117
  int v67; // eax@118
  int v68; // ecx@118
  int v69; // esi@118
  int v70; // ecx@118
  int v71; // eax@123
  int v72; // edi@125
  const char **v73; // esi@125
  int v74; // eax@126
  int v75; // ecx@127
  int v76; // edi@127
  int v77; // edx@127
  unsigned __int8 v78; // sf@127
  unsigned __int16 v79; // ax@129
  int v80; // ecx@129
  int v81; // esi@129
  const char **v82; // eax@129
  int v83; // eax@129
  int v84; // edx@129
  int v85; // [sp-18h] [bp-F0h]@29
  char v86; // [sp-14h] [bp-ECh]@29
  int v87; // [sp-10h] [bp-E8h]@29
  int v88; // [sp-10h] [bp-E8h]@43
  unsigned __int16 v89; // [sp-Ch] [bp-E4h]@29
  int v90; // [sp-Ch] [bp-E4h]@43
  const char *v91; // [sp-8h] [bp-E0h]@29
  int v92; // [sp-8h] [bp-E0h]@42
  int v93; // [sp-4h] [bp-DCh]@29
  __int64 *v94; // [sp-4h] [bp-DCh]@42
  char v95; // [sp+Ch] [bp-CCh]@39
  char v96; // [sp+14h] [bp-C4h]@49
  char v97; // [sp+1Ch] [bp-BCh]@117
  char v98; // [sp+24h] [bp-B4h]@40
  char v99; // [sp+2Ch] [bp-ACh]@117
  char v100; // [sp+34h] [bp-A4h]@49
  char v101; // [sp+3Ch] [bp-9Ch]@50
  char v102; // [sp+44h] [bp-94h]@39
  char v103; // [sp+4Ch] [bp-8Ch]@49
  char v104; // [sp+54h] [bp-84h]@39
  int v105; // [sp+5Ch] [bp-7Ch]@1
  int v106; // [sp+64h] [bp-74h]@1
  int v107; // [sp+6Ch] [bp-6Ch]@1
  int v108; // [sp+B0h] [bp-28h]@19
  __int16 v109[2]; // [sp+B4h] [bp-24h]@1
  char *Str; // [sp+B8h] [bp-20h]@23
  __int16 v111[2]; // [sp+BCh] [bp-1Ch]@1
  int v112; // [sp+C0h] [bp-18h]@39
  int v113; // [sp+C4h] [bp-14h]@1
  int v114; // [sp+C8h] [bp-10h]@9
  int v115; // [sp+CCh] [bp-Ch]@9
  unsigned __int8 v116; // [sp+D3h] [bp-5h]@47
  int v117; // [sp+D4h] [bp-4h]@11

  v0 = *(&ptr_A750C4 + uActiveCharacter);
  v113 = (int)*(&ptr_A750C4 + uActiveCharacter);
  memcpy(&v105, (const void *)dword_507BC0, 0x54u);
  v105 = 483;
  v106 = 148;
  v107 = 334;
  *(_DWORD *)v111 = 0xFFFFFFFF;
  *(_DWORD *)v109 = 0xFFE1CD23;
  if ( dword_F8B19C == 1 )
  {
    result = sub_4B1784();
    if ( result )
    {
      dword_F8B1B8[0] = pGlobalTXT_LocalizationStrings[134];
      dword_F8B1BC = pGlobalTXT_LocalizationStrings[152];
      dword_F8B1C0 = pGlobalTXT_LocalizationStrings[636];
      v72 = 0;
      dword_F8B1C4 = pGlobalTXT_LocalizationStrings[160];
      v73 = (const char **)dword_F8B1B8;
      do
      {
        v74 = sub_44C59D(pFontArrus, *v73, (int)&v105, 0, 0);
        ++v73;
        v72 += v74;
      }
      while ( (signed int)v73 < (signed int)&unk_F8B1C8 );
      v75 = dword_507BBC;
      Str = (char *)((174 - v72) / 4);
      result = *(_DWORD *)(dword_507BBC + 56);
      v77 = result + *(_DWORD *)(dword_507BBC + 40);
      v76 = (174 - 4 * (174 - v72) / 4 - v72) / 2 - (174 - v72) / 4 / 2 + 138;
      v78 = -*(_DWORD *)(dword_507BBC + 40) < 0;
      v115 = *(_DWORD *)(dword_507BBC + 56);

      compile_error;//if ( v78 ^ __SETO__(result, v77) )
      if (1)
      {
        v113 = 2;
        v114 = (int)dword_F8B1B8;
        do
        {
          v81 = GUIWindow_GetChild(v75, v115);
          v82 = (const char **)v114;
          *(_DWORD *)(v81 + 4) = &Str[v76];
          v83 = sub_44C59D(pFontArrus, *v82, (int)&v105, 0, 0);
          v80 = *(_DWORD *)(v81 + 4);
          v84 = v113;
          *(_DWORD *)(v81 + 12) = v83;
          v76 = v80 + v83 - 1;
          *(_DWORD *)(v81 + 20) = v76;
          v79 = v109[0];
          if ( *(_DWORD *)(dword_507BBC + 44) != v84 )
            v79 = v111[0];
          sub_44D406((int)&v105, pFontArrus, 0, v80, v79, *(const char **)v114, 3);
          v75 = dword_507BBC;
          ++v113;
          v114 += 4;
          ++v115;
          result = *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56);
        }
        while ( v115 < result );
      }
    }
    return result;
  }
  if ( dword_F8B19C == 2 )
    goto LABEL_134;
  if ( dword_F8B19C == 3 )
  {
    sub_41A556();
    GameUI_DrawInventory(uActiveCharacter, 1);
    sub_4B46A5(pGlobalTXT_LocalizationStrings[199], 0);
    result = sub_4B1784();
    if ( !result
      || (v43 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v100) - 14,
          v112 = (v43 >> 5) + 14 * ((*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v96) + 4) - 17) >> 5),
          result = class03_GetMousePos(pGame->pClass03, (int)&v103),
          *(_DWORD *)result <= 13)
      || (result = class03_GetMousePos(pGame->pClass03, (int)&v101), *(_DWORD *)result >= 462)
      || (result = sub_421E75(v0, (int)&v112), v2 = 0, !result) )
      return result;
    v94 = 0;
    v92 = 3;
    v90 = *(_DWORD *)(dword_507BC0 + 28);
    v88 = v113 + 36 * result + 496;
    v44 = *(_DWORD *)(dword_507BC0 + 28);
    v116 = uActiveCharacter - 1;
    v45 = sub_490EEE((void *)v113, v88, 4, v44, 3);
    v39 = v116;
    v38 = dword_73C3A4[v45];
LABEL_45:
    v21 = sub_495461((char *)v38, v39, v88, v90, v92, v94);
    v93 = 3;
    v91 = v21;
    v89 = v111[0];
    v87 = v2;
    v86 = v2;
    v85 = (int)&v105;
    goto LABEL_46;
  }
  if ( dword_F8B19C == 4 )
  {
    sub_41A556();
    GameUI_DrawInventory(uActiveCharacter, 1);
    sub_4B46A5(pGlobalTXT_LocalizationStrings[197], 0);
    result = sub_4B1784();
    if ( !result
      || (v36 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v104) - 14,
          v112 = (v36 >> 5) + 14 * ((*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v95) + 4) - 17) >> 5),
          result = class03_GetMousePos(pGame->pClass03, (int)&v102),
          *(_DWORD *)result <= 13)
      || (result = class03_GetMousePos(pGame->pClass03, (int)&v98), *(_DWORD *)result >= 462)
      || (result = sub_421E75(v0, (int)&v112), v2 = 0, !result) )
      return result;
    v94 = 0;
    v92 = 4;
    v37 = v113 + 36 * result + 496;
    if ( !(*(_BYTE *)(v37 + 20) & 1) )
    {
      v90 = *(_DWORD *)(dword_507BC0 + 28);
      v88 = v37;
      v41 = *(_DWORD *)(dword_507BC0 + 28);
      v116 = uActiveCharacter - 1;
      v42 = sub_490EEE((void *)v113, v37, 4, v41, 4);
      v39 = v116;
      v38 = dword_73C3DC[v42];
      goto LABEL_45;
    }
    v90 = *(_DWORD *)(dword_507BC0 + 28);
    v38 = (int)"%24";
    v88 = v37;
    goto LABEL_44;
  }
  if ( dword_F8B19C == 94 )
  {
    sub_41A556();
    GameUI_DrawInventory(uActiveCharacter, 1);
    dword_F8B1B8[0] = pGlobalTXT_LocalizationStrings[200];
    dword_F8B1BC = pGlobalTXT_LocalizationStrings[113];
    v23 = 0;
    v22 = (const char **)dword_F8B1B8;
    do
    {
      v24 = sub_44C59D(pFontArrus, *v22, (int)&v105, 0, 0);
      ++v22;
      v23 += v24;
    }
    while ( (signed int)v22 < (signed int)&dword_F8B1C0 );
    Str = (char *)((174 - v23) / 2);
    v25 = dword_507BBC;
    result = *(_DWORD *)(dword_507BBC + 56);
    v27 = result + *(_DWORD *)(dword_507BBC + 40);
    v26 = (2 * (87 - (174 - v23) / 2) - v23) / 2 - (174 - v23) / 2 / 2 + 138;
    v28 = -*(_DWORD *)(dword_507BBC + 40) < 0;
    v115 = *(_DWORD *)(dword_507BBC + 56);
    
    compile_error;//if ( v28 ^ __SETO__(result, v27) )
    if (1)
    {
      v113 = 2;
      v114 = (int)dword_F8B1B8;
      do
      {
        v31 = GUIWindow_GetChild(v25, v115);
        v32 = (const char **)v114;
        *(_DWORD *)(v31 + 4) = &Str[v26];
        v33 = sub_44C59D(pFontArrus, *v32, (int)&v105, 0, 0);
        v30 = *(_DWORD *)(v31 + 4);
        v34 = v113;
        *(_DWORD *)(v31 + 12) = v33;
        v35 = v33 + v30 - 1;
        *(_DWORD *)(v31 + 20) = v35;
        v26 = v35;
        v29 = v109[0];
        if ( *(_DWORD *)(dword_507BBC + 44) != v34 )
          v29 = v111[0];
        sub_44D406((int)&v105, pFontArrus, 0, v30, v29, *(const char **)v114, 3);
        v25 = dword_507BBC;
        ++v113;
        v114 += 4;
        ++v115;
        result = *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56);
      }
      while ( v115 < result );
    }
    return result;
  }
  if ( dword_F8B19C == 95 )
  {
LABEL_134:
    Render_DrawIndexedTexture(pD3DRenderer, 8, 8, dword_F8B164[0]);
    v2 = 0;
    v117 = 0;
    if ( dword_F8B19C == 2 )
    {
      do
      {
        if ( dword_AD4734[9 * (v117 + 12 * *(_DWORD *)(dword_507BC0 + 28))] )
        {
          v46 = dword_F8B168[v117];
          v47 = 152 - *(_WORD *)(v46 + 26);
          if ( v47 < 1 )
            v47 = 0;
          v48 = 75 * v117 - *(_WORD *)(v46 + 24) / 2 + 40;
          if ( v117 )
          {
            if ( v117 == 5 )
            {
              v49 = *(_WORD *)(dword_F8B17C + 24);
              if ( v48 > 457 - v49 )
                v48 = 457 - v49;
            }
          }
          else
          {
            if ( v48 < 18 )
              v48 = 18;
          }
          Render_DrawTransparentTexture(pD3DRenderer, v48, v47, v46);
          sub_40F92A(pD3DRenderer->pActiveZBuffer + 4 * (v48 + 640 * v47), dword_F8B168[v117], v117 + 1);
        }
        ++v117;
      }
      while ( v117 < 6 );
      v117 = 0;
      do
      {
        if ( dword_AD480C[9 * (v117 + 12 * *(_DWORD *)(dword_507BC0 + 28))] )
        {
          v50 = dword_F8B180[v117];
          v51 = 308 - *(_WORD *)(v50 + 26);
          if ( v51 < 1 )
            v51 = 0;
          v52 = 75 * v117 - *(_WORD *)(v50 + 24) / 2 + 40;
          if ( v117 )
          {
            if ( v117 == 5 )
            {
              v53 = *(_WORD *)(dword_F8B194 + 24);
              if ( v52 > 457 - v53 )
                v52 = 457 - v53;
            }
          }
          else
          {
            if ( v52 < 18 )
              v52 = 18;
          }
          Render_DrawTransparentTexture(pD3DRenderer, v52, v51, v50);
          sub_40F92A(pD3DRenderer->pActiveZBuffer + 4 * (v52 + 640 * v51), dword_F8B180[v117], v117 + 7);
        }
        ++v117;
      }
      while ( v117 < 6 );
    }
    else
    {
      do
      {
        if ( *(&dword_ADA0A4 + 9 * (v117 + 12 * *(_DWORD *)(dword_507BC0 + 28))) )
        {
          v54 = dword_F8B168[v117];
          v55 = 152 - *(_WORD *)(v54 + 26);
          if ( v55 < 1 )
            v55 = 0;
          v56 = 75 * v117 - *(_WORD *)(v54 + 24) / 2 + 40;
          if ( v117 )
          {
            if ( v117 == 5 )
            {
              v57 = *(_WORD *)(dword_F8B17C + 24);
              if ( v56 > 457 - v57 )
                v56 = 457 - v57;
            }
          }
          else
          {
            if ( v56 < 18 )
              v56 = 18;
          }
          Render_DrawTransparentTexture(pD3DRenderer, v56, v55, v54);
          sub_40F92A(pD3DRenderer->pActiveZBuffer + 4 * (v56 + 640 * v55), dword_F8B168[v117], v117 + 1);
        }
        ++v117;
      }
      while ( v117 < 6 );
      v117 = 0;
      do
      {
        if ( dword_ADA17C[9 * (v117 + 12 * *(_DWORD *)(dword_507BC0 + 28))] )
        {
          v58 = dword_F8B180[v117];
          v59 = 308 - *(_WORD *)(v58 + 26);
          if ( v59 < 1 )
            v59 = 0;
          v60 = 75 * v117 - *(_WORD *)(v58 + 24) / 2 + 40;
          if ( v117 )
          {
            if ( v117 == 5 )
            {
              v61 = *(_WORD *)(dword_F8B194 + 24);
              if ( v60 > 457 - v61 )
                v60 = 457 - v61;
            }
          }
          else
          {
            if ( v60 < 18 )
              v60 = 18;
          }
          Render_DrawTransparentTexture(pD3DRenderer, v60, v59, v58);
          sub_40F92A(pD3DRenderer->pActiveZBuffer + 4 * (v60 + 640 * v59), dword_F8B180[v117], v117 + 7);
        }
        ++v117;
      }
      while ( v117 < 6 );
    }
    result = sub_4B1784();
    if ( !result )
      return result;
    v62 = 0;
    v112 = 0;
    if ( dword_F8B19C == 2 )
    {
      do
      {
        if ( dword_AD4734[9 * (v62 + 12 * *(_DWORD *)(dword_507BC0 + 28))] )
          ++v112;
        ++v62;
      }
      while ( v62 < 12 );
    }
    else
    {
      do
      {
        if ( *(&dword_ADA0A4 + 9 * (v62 + 12 * *(_DWORD *)(dword_507BC0 + 28))) )
          ++v112;
        ++v62;
      }
      while ( v62 < 12 );
    }
    v64 = GetAsyncKeyState(17);
    v63 = sub_492C40((void *)v113);
    Str = (char *)v63;
    if ( v64 && v63 )
    {
      v65 = pGlobalTXT_LocalizationStrings[185];
    }
    else
    {
      v65 = pGlobalTXT_LocalizationStrings[195];
      if ( dword_F8B19C != 2 )
        v65 = pGlobalTXT_LocalizationStrings[196];
    }
    sub_4B46A5(v65, 0);
    if ( !v112 )
      compile_error;//return (signed int)sub_4B1854(
                    //       &v105,
                    //       __PAIR__(
                    //         dword_ACD048[2 * *(_DWORD *)(dword_507BC0 + 28)],
                    //         dword_ACD044[2 * *(_DWORD *)(dword_507BC0 + 28)])
                    //     - pParty_global->qword_00002C);
    v66 = class03_GetMousePos(pGame->pClass03, (int)&v99);
    result = *(_DWORD *)v66 + dword_5059A8[*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v97) + 4)];
    if ( !(*(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * result) & 0xFFFF) )
      return result;
    v70 = (*(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * result) & 0xFFFF) - 1;
    v112 = v70;
    v67 = *(_DWORD *)(dword_507BC0 + 28);
    v68 = 9 * (v70 + 12 * v67);
    v69 = 4 * v68 + 11355956;
    if ( dword_F8B19C != 2 )
      v69 = 4 * v68 + 11378852;
    if ( !v64 || !Str )
    {
      v94 = 0;
      v92 = 2;
      v90 = *(_DWORD *)(dword_507BC0 + 28);
      v88 = v69;
      v116 = uActiveCharacter - 1;
      v71 = sub_490EEE((void *)v113, v69, 4, v67, 2);
      v39 = v116;
      v38 = *(_DWORD *)&dword_73C388[4 * v71];
      goto LABEL_45;
    }
    v38 = pGlobalTXT_LocalizationStrings[181];
    v94 = 0;
    v92 = 2;
    v90 = *(_DWORD *)(dword_507BC0 + 28);
    v88 = v69;
LABEL_44:
    v39 = uActiveCharacter - 1;
    goto LABEL_45;
  }
  result = dword_F8B19C - 96;
  if ( dword_F8B19C == 96 )
  {
    result = sub_4B1784();
    if ( result )
    {
      v3 = dword_507BBC;
      v2 = 0;
      v5 = *(_DWORD *)(dword_507BC0 + 28);
      v115 = 0;
      v4 = (signed __int64)(*((float *)&unk_59145C + 13 * v5) * 500.0);
      v114 = v4 * (100 - sub_4911F3((void *)v113)) / 100;
      if ( v114 < v4 / 3 )
        v114 = v4 / 3;
      v6 = *(_DWORD *)(v3 + 56);
      v7 = v6 + *(_DWORD *)(v3 + 40);
      v117 = 0;
      if ( v6 < v7 )
      {
        do
        {
          v8 = *(_DWORD *)(GUIWindow_GetChild(v3, v6) + 36) - 36;
          if ( *(&byte_4ED970[37 * *(_BYTE *)(v113 + 185)] + v8) )
          {
            if ( !*(_WORD *)(v113 + 2 * v8 + 264) )
            {
              //v9 = sub_44C59D(pFontArrus, (&dword_AE32D0)[4 * v8], (int)&v105, 0, 0);
              v9 = sub_44C59D(pFontArrus, aSkillNames[v8], (int)&v105, 0, 0);
              v115 += v9;
              ++v117;
            }
          }
          ++v6;
        }
        while ( v6 < *(_DWORD *)(v3 + 40) + *(_DWORD *)(v3 + 56) );
        if ( v117 )
        {
          sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[401], v114);
          sub_44D406((int)&v105, pFontArrus, 0, 146, 0, &TmpBuf, 3);
          v114 = (149 - v115) / v117;
          if ( (149 - v115) / v117 > 32 )
            v114 = 32;
          result = *(_DWORD *)(v3 + 56);
          v10 = (149 - v117 * v114 - v115) / 2 - v114 / 2 + 162;
          v115 = result;
          v108 = v10;
          if ( result < result + *(_DWORD *)(v3 + 40) )
          {
            v117 = 2;
            do
            {
              v13 = GUIWindow_GetChild(v3, v115);
              v12 = v13;
              v11 = *(_DWORD *)(v13 + 36) - 36;
              if ( !*(&byte_4ED970[37 * *(_BYTE *)(v113 + 185)] + v11) || *(_WORD *)(v113 + 2 * v11 + 264) )
              {
                *(_DWORD *)(v12 + 20) = 0;
                *(_DWORD *)(v12 + 12) = 0;
                *(_DWORD *)(v12 + 4) = 0;
              }
              else
              {
                //v16 = (&dword_AE32D0)[4 * v11];
                v16 = aSkillNames[v11];
                *(_DWORD *)(v12 + 4) = v114 + v108;
                Str = v16;
                v17 = sub_44C59D(pFontArrus, v16, (int)&v105, 0, 0);
                v15 = *(_DWORD *)(v12 + 4);
                v18 = v117;
                *(_DWORD *)(v12 + 12) = v17;
                v19 = v15 + v17 - 1;
                *(_DWORD *)(v12 + 20) = v19;
                v108 = v19;
                v14 = v109[0];
                if ( *(_DWORD *)(dword_507BBC + 44) != v18 )
                  v14 = v111[0];
                sub_44D406((int)&v105, pFontArrus, 0, v15, v14, Str, 3);
              }
              v20 = *(_DWORD *)(v3 + 56);
              ++v115;
              result = *(_DWORD *)(v3 + 40) + v20;
              ++v117;
            }
            while ( v115 < result );
          }
          return result;
        }
      }
      //sprintfex(&TmpBuf, (const char *)dword_5E4A00, v113 + 168, (&dword_AE31F0)[4 * *(_BYTE *)(v113 + 185)]);
      sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[544], v113 + 168, aClassNames[*(_BYTE *)(v113 + 185)]);
      strcat((char *)&TmpBuf, "\n \n");
      strcat((char *)&TmpBuf, pGlobalTXT_LocalizationStrings[528]);
      v21 = &TmpBuf;
      v93 = 3;
      v91 = &TmpBuf;
      v89 = v109[0];
      v87 = 0;
      v86 = 0;
      v85 = (int)&v105;
LABEL_46:
      v40 = sub_44C59D(pFontArrus, v21, v85, v86, v87);
      return (signed int)sub_44D406((int)&v105, pFontArrus, v2, (174 - v40) / 2 + 138, v89, v91, v93);
    }
  }
  return result;
}

//----- (004BA928) --------------------------------------------------------
char __cdecl sub_4BA928()
{
  int v0; // ebx@1
  signed int v1; // eax@6
  signed int v2; // esi@8
  int v3; // eax@11
  unsigned __int8 v4; // dl@12
  char *v5; // ecx@12
  const char *v6; // eax@13
  int v7; // ST08_4@15
  int v8; // eax@15
  signed int v9; // esi@17
  char *v10; // edi@19
  unsigned __int8 v11; // dl@20
  int v12; // ecx@20
  int v13; // ST08_4@20
  int v14; // eax@20
  int v15; // ebx@22
  const char **v16; // edi@22
  const char **v17; // esi@22
  int v18; // eax@23
  int v19; // ecx@24
  int v20; // ebx@24
  int v21; // edx@24
  unsigned __int8 v22; // sf@24
  unsigned __int16 v23; // ax@26
  int v24; // ecx@26
  int v25; // eax@26
  int v26; // esi@26
  int v27; // eax@26
  int v28; // edx@26
  signed int v29; // esi@31
  int v30; // ST08_4@35
  int v31; // eax@35
  const char *v32; // edx@36
  int v33; // edi@42
  signed int v34; // esi@42
  int v35; // esi@44
  int v36; // eax@44
  int v37; // eax@45
  int v38; // eax@47
  int v39; // ecx@52
  int v40; // eax@54
  int v41; // esi@54
  int v42; // eax@54
  unsigned __int16 v43; // ax@56
  int v44; // ecx@56
  char *v45; // eax@56
  int v46; // eax@56
  int v47; // edx@56
  int v48; // eax@56
  int v49; // eax@60
  signed int v50; // ebx@65
  int v51; // eax@67
  int v52; // eax@68
  int v53; // edi@68
  int v54; // ST1C_4@68
  int v55; // edi@69
  signed int v56; // ebx@73
  int v57; // eax@75
  int v58; // eax@76
  int v59; // edi@76
  int v60; // ST1C_4@76
  int v61; // ST18_4@76
  int v62; // edi@77
  signed int v63; // ecx@81
  bool v64; // eax@89
  SHORT v65; // bx@89
  const char *v66; // ecx@91
  int v67; // eax@95
  int v68; // ecx@97
  int v69; // esi@97
  int v70; // eax@98
  int v71; // ecx@98
  int v72; // ecx@99
  unsigned __int8 v73; // bl@104
  int v74; // ebx@105
  const char **v75; // edi@105
  const char **v76; // esi@105
  int v77; // eax@106
  int v78; // ecx@107
  int v79; // ebx@107
  int v80; // edx@107
  unsigned __int8 v81; // sf@107
  unsigned __int16 v82; // ax@109
  int v83; // ecx@109
  int v84; // eax@109
  int v85; // esi@109
  int v86; // eax@109
  int v87; // edx@109
  signed int v88; // edx@114
  int v89; // ecx@120
  int v90; // edi@120
  int v91; // ST14_4@122
  unsigned __int8 v92; // bl@122
  int v93; // ST10_4@122
  int v94; // eax@122
  const char *v95; // eax@122
  const char *v96; // ST18_4@122
  unsigned __int16 v97; // ST14_2@122
  int v98; // eax@122
  signed int v99; // edi@123
  int v100; // eax@125
  int v101; // eax@126
  int v102; // ebx@126
  int v103; // ST1C_4@126
  int v104; // ST18_4@126
  int v105; // ebx@127
  int v107; // [sp-18h] [bp-11Ch]@36
  int v108; // [sp-14h] [bp-118h]@13
  char v109; // [sp-14h] [bp-118h]@36
  int v110; // [sp-10h] [bp-114h]@12
  int v111; // [sp-10h] [bp-114h]@13
  int v112; // [sp-10h] [bp-114h]@20
  int v113; // [sp-10h] [bp-114h]@36
  int v114; // [sp-Ch] [bp-110h]@12
  unsigned __int16 v115; // [sp-Ch] [bp-110h]@13
  int v116; // [sp-Ch] [bp-110h]@20
  const char *v117; // [sp-8h] [bp-10Ch]@13
  int v118; // [sp-8h] [bp-10Ch]@20
  int v119; // [sp-4h] [bp-108h]@13
  __int64 *v120; // [sp-4h] [bp-108h]@20
  int v121; // [sp-4h] [bp-108h]@68
  int v122; // [sp-4h] [bp-108h]@76
  int v123; // [sp-4h] [bp-108h]@126
  char v124; // [sp+Ch] [bp-F8h]@8
  char v125; // [sp+14h] [bp-F0h]@18
  char v126; // [sp+1Ch] [bp-E8h]@120
  char v127; // [sp+24h] [bp-E0h]@8
  char v128; // [sp+2Ch] [bp-D8h]@120
  char v129; // [sp+34h] [bp-D0h]@17
  char v130; // [sp+3Ch] [bp-C8h]@97
  char v131; // [sp+44h] [bp-C0h]@31
  char v132; // [sp+4Ch] [bp-B8h]@97
  char v133; // [sp+54h] [bp-B0h]@17
  char v134; // [sp+5Ch] [bp-A8h]@32
  char v135; // [sp+64h] [bp-A0h]@17
  char v136; // [sp+6Ch] [bp-98h]@31
  char v137; // [sp+74h] [bp-90h]@8
  char v138; // [sp+7Ch] [bp-88h]@31
  char v139; // [sp+84h] [bp-80h]@9
  int v140; // [sp+8Ch] [bp-78h]@1
  int v141; // [sp+94h] [bp-70h]@1
  int v142; // [sp+9Ch] [bp-68h]@1
  char *Str; // [sp+E0h] [bp-24h]@56
  int v144; // [sp+E4h] [bp-20h]@24
  __int16 v145[2]; // [sp+E8h] [bp-1Ch]@1
  __int16 v146[2]; // [sp+ECh] [bp-18h]@1
  int v147; // [sp+F0h] [bp-14h]@8
  int v148; // [sp+F4h] [bp-10h]@1
  unsigned __int8 v149; // [sp+FBh] [bp-9h]@15
  int v150; // [sp+FCh] [bp-8h]@24
  int v151; // [sp+100h] [bp-4h]@44

  v0 = (int)*(&ptr_A750C4 + uActiveCharacter);
  v148 = (int)*(&ptr_A750C4 + uActiveCharacter);
  memcpy(&v140, (const void *)dword_507BC0, 0x54u);
  v140 = 483;
  v141 = 148;
  v142 = 334;
  *(_DWORD *)v146 = 0xFFFFFFFF;
  *(_DWORD *)v145 = 0xFFE1CD23;
  if ( dword_F8B19C > 5 )
  {
    if ( dword_F8B19C == 6 )
    {
      Render_DrawIndexedTexture(pD3DRenderer, 8, 8, dword_F8B164[0]);
      sub_4B46A5(pGlobalTXT_LocalizationStrings[195], 0);
      v1 = sub_4B1784();
      if ( !v1 )
        return v1;
      v147 = 0;
      v88 = 0;
      do
      {
        if ( *(&dword_ADA0A4 + 9 * (v88 + 12 * *(_DWORD *)(dword_507BC0 + 28))) )
          ++v147;
        ++v88;
      }
      while ( v88 < 8 );
      if ( v147 )
      {
        v90 = class03_GetMousePos(pGame->pClass03, (int)&v128);
        v147 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer
                         + 4 * (*(_DWORD *)v90 + dword_5059A8[*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v126) + 4)]));
        v89 = v147;
        if ( v147 )
        {
          if ( v147 != -65536 )
          {
            --v147;
            v91 = *(_DWORD *)(dword_507BC0 + 28);
            v92 = uActiveCharacter - 1;
            v93 = 36 * (v89 - 1 + 12 * v91) + 11378852;
            v94 = sub_490EEE((void *)v148, 36 * (v89 - 1 + 12 * v91) + 11378852, 2, *(_DWORD *)(dword_507BC0 + 28), 2);
            v95 = sub_495461(*(char **)&dword_73C388[4 * v94], v92, v93, v91, 2, 0);
            v96 = v95;
            v97 = v146[0];
            v98 = sub_44C59D(pFontArrus, v95, (int)&v140, 0, 0);
            sub_44D406((int)&v140, pFontArrus, 0, (174 - v98) / 2 + 138, v97, v96, 3);
          }
        }
        v99 = 0;
        v151 = 0;
        do
        {
          v1 = 9 * (v99 + 12 * *(_DWORD *)(dword_507BC0 + 28));
          if ( *(&dword_ADA0A4 + 9 * (v99 + 12 * *(_DWORD *)(dword_507BC0 + 28))) )
          {
            v100 = dword_F8B168[v99];
            if ( v99 >= 4 )
            {
              v105 = 90 - ((signed int)*(_WORD *)(v100 + 24) >> 1);
              Render_DrawTransparentTexture(pD3DRenderer, v151 + v105 - 420, 126, dword_F8B168[v99]);
              v123 = v99 + 1;
              v101 = v151 + v105 + 80220;
            }
            else
            {
              v102 = 98 - *(_WORD *)(v100 + 26);
              v103 = dword_F8B168[v99];
              v104 = 98 - *(_WORD *)(v100 + 26);
              v150 = 86 - ((signed int)*(_WORD *)(v100 + 24) >> 1);
              Render_DrawTransparentTexture(pD3DRenderer, v150 + v151, v104, v103);
              v123 = v99 + 1;
              v101 = v150 + v151 + 640 * v102;
            }
            array_40F89C_ActuallyFillZBuffer(pD3DRenderer->pActiveZBuffer + v101, dword_F8B168[v99], v123);
          }
          v151 += 105;
          ++v99;
        }
        while ( v99 < 8 );
        return v1;
      }
      v67 = *(_DWORD *)(dword_507BC0 + 28);
      goto LABEL_96;
    }
    if ( dword_F8B19C == 94 )
    {
      sub_41A556();
      GameUI_DrawInventory(uActiveCharacter, 1);
      v75 = (const char **)dword_F8B1B8;
      dword_F8B1B8[0] = pGlobalTXT_LocalizationStrings[200];
      dword_F8B1BC = pGlobalTXT_LocalizationStrings[113];
      dword_F8B1C0 = pGlobalTXT_LocalizationStrings[179];
      v74 = 0;
      v76 = (const char **)dword_F8B1B8;
      do
      {
        v77 = sub_44C59D(pFontArrus, *v76, (int)&v140, 0, 0);
        ++v76;
        v74 += v77;
      }
      while ( (signed int)v76 < (signed int)&dword_F8B1C4 );
      v78 = dword_507BBC;
      v150 = (174 - v74) / 3;
      v1 = *(_DWORD *)(dword_507BBC + 56);
      v80 = v1 + *(_DWORD *)(dword_507BBC + 40);
      v79 = (3 * (58 - v150) - v74) / 2 - v150 / 2 + 138;
      v81 = -*(_DWORD *)(dword_507BBC + 40) < 0;
      v148 = *(_DWORD *)(dword_507BBC + 56);
      
      compile_error;//if ( v81 ^ __SETO__(v1, v80) )
      if (1)
      {
        v151 = 2;
        do
        {
          v84 = GUIWindow_GetChild(v78, v148);
          v85 = v84;
          *(_DWORD *)(v84 + 4) = v150 + v79;
          v86 = sub_44C59D(pFontArrus, *v75, (int)&v140, 0, 0);
          v83 = *(_DWORD *)(v85 + 4);
          v87 = v151;
          *(_DWORD *)(v85 + 12) = v86;
          v79 = v83 + v86 - 1;
          *(_DWORD *)(v85 + 20) = v79;
          v82 = v145[0];
          if ( *(_DWORD *)(dword_507BBC + 44) != v87 )
            v82 = v146[0];
          sub_44D406((int)&v140, pFontArrus, 0, v83, v82, *v75, 3);
          v78 = dword_507BBC;
          ++v151;
          ++v75;
          ++v148;
          v1 = *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56);
        }
        while ( v148 < v1 );
      }
      return v1;
    }
    if ( dword_F8B19C != 95 )
    {
      v1 = dword_F8B19C - 96;
      if ( dword_F8B19C != 96 || (v1 = sub_4B1784(), !v1) )
        return v1;
      v150 = 0;
      v33 = dword_507BBC;
      v34 = (signed __int64)(*((float *)&unk_59145C + 13 * *(_DWORD *)(dword_507BC0 + 28)) * 500.0);
      v148 = v34 * (100 - sub_4911F3((void *)v0)) / 100;
      if ( v148 < v34 / 3 )
        v148 = v34 / 3;
      v35 = *(_DWORD *)(v33 + 56);
      v36 = *(_DWORD *)(v33 + 40);
      v151 = 0;
      if ( v35 < v35 + v36 )
      {
        do
        {
          v37 = *(_DWORD *)(GUIWindow_GetChild(v33, v35) + 36) - 36;
          if ( *(&byte_4ED970[37 * *(_BYTE *)(v0 + 185)] + v37) )
          {
            if ( !*(_WORD *)(v0 + 2 * v37 + 264) )
            {
              //v38 = sub_44C59D(pFontArrus, (&dword_AE32D0)[4 * v37], (int)&v140, 0, 0);
              v38 = sub_44C59D(pFontArrus, aSkillNames[v37], (int)&v140, 0, 0);
              v150 += v38;
              ++v151;
            }
          }
          ++v35;
        }
        while ( v35 < *(_DWORD *)(v33 + 40) + *(_DWORD *)(v33 + 56) );
        if ( v151 )
        {
          sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[401], v148);
          sub_44D406((int)&v140, pFontArrus, 0, 146, 0, &TmpBuf, 3);
          v148 = (149 - v150) / v151;
          if ( (149 - v150) / v151 > 32 )
            v148 = 32;
          v1 = *(_DWORD *)(v33 + 56);
          v39 = (149 - v151 * v148 - v150) / 2 - v148 / 2 + 162;
          v150 = v1;
          v144 = v39;
          if ( v1 < v1 + *(_DWORD *)(v33 + 40) )
          {
            v151 = 2;
            do
            {
              v42 = GUIWindow_GetChild(v33, v150);
              v41 = v42;
              v40 = *(_DWORD *)(v42 + 36) - 36;
              if ( !*(&byte_4ED970[37 * *(_BYTE *)(v0 + 185)] + v40) || *(_WORD *)(v0 + 2 * v40 + 264) )
              {
                *(_DWORD *)(v41 + 20) = 0;
                *(_DWORD *)(v41 + 12) = 0;
                *(_DWORD *)(v41 + 4) = 0;
              }
              else
              {
                //v45 = (&dword_AE32D0)[4 * v40];
                v45 = aSkillNames[v40];
                *(_DWORD *)(v41 + 4) = v148 + v144;
                Str = v45;
                v46 = sub_44C59D(pFontArrus, v45, (int)&v140, 0, 0);
                v44 = *(_DWORD *)(v41 + 4);
                v47 = v151;
                *(_DWORD *)(v41 + 12) = v46;
                v48 = v44 + v46 - 1;
                *(_DWORD *)(v41 + 20) = v48;
                v144 = v48;
                v43 = v145[0];
                if ( *(_DWORD *)(dword_507BBC + 44) != v47 )
                  v43 = v146[0];
                sub_44D406((int)&v140, pFontArrus, 0, v44, v43, Str, 3);
              }
              v49 = *(_DWORD *)(v33 + 56);
              ++v150;
              v1 = *(_DWORD *)(v33 + 40) + v49;
              ++v151;
            }
            while ( v150 < v1 );
          }
          return v1;
        }
      }
      //sprintfex(&TmpBuf, (const char *)dword_5E4A00, v0 + 168, (&dword_AE31F0)[4 * *(_BYTE *)(v0 + 185)]);
      sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[544], v0 + 168, aClassNames[*(_BYTE *)(v0 + 185)]);
      strcat((char *)&TmpBuf, "\n \n");
      strcat((char *)&TmpBuf, pGlobalTXT_LocalizationStrings[528]);
      v10 = 0;
      v32 = &TmpBuf;
      v119 = 3;
      v117 = &TmpBuf;
      v115 = v145[0];
      v113 = 0;
      v109 = 0;
      v107 = (int)&v140;
LABEL_63:
      v111 = (174 - sub_44C59D(pFontArrus, v32, v107, v109, v113)) / 2 + 138;
      v108 = (int)v10;
LABEL_14:
      LOBYTE(v1) = (unsigned int)sub_44D406((int)&v140, pFontArrus, v108, v111, v115, v117, v119);
      return v1;
    }
LABEL_64:
    Render_DrawIndexedTexture(pD3DRenderer, 8, 8, dword_F8B164[0]);
    if ( dword_F8B19C == 2 )
    {
      v50 = 0;
      v151 = 0;
      do
      {
        if ( dword_AD4734[9 * (v50 + 12 * *(_DWORD *)(dword_507BC0 + 28))] )
        {
          v51 = dword_F8B168[v50];
          if ( v50 >= 4 )
          {
            v55 = 90 - ((signed int)*(_WORD *)(v51 + 24) >> 1);
            Render_DrawTransparentTexture(pD3DRenderer, v55 + v151 - 420, 126, dword_F8B168[v50]);
            v121 = v50 + 1;
            v52 = v55 + v151 + 80220;
          }
          else
          {
            v53 = 98 - *(_WORD *)(v51 + 26);
            v54 = dword_F8B168[v50];
            v150 = 86 - ((signed int)*(_WORD *)(v51 + 24) >> 1);
            Render_DrawTransparentTexture(pD3DRenderer, v151 + v150, v53, v54);
            v121 = v50 + 1;
            v52 = v151 + v150 + 640 * v53;
          }
          array_40F89C_ActuallyFillZBuffer(pD3DRenderer->pActiveZBuffer + 4 * v52, dword_F8B168[v50], v121);
        }
        v151 += 105;
        ++v50;
      }
      while ( v50 < 8 );
      v10 = 0;
    }
    else
    {
      v10 = 0;
      v56 = 0;
      v151 = 0;
      do
      {
        if ( (char *)*(&dword_ADA0A4 + 9 * (v56 + 12 * *(_DWORD *)(dword_507BC0 + 28))) != v10 )
        {
          v57 = dword_F8B168[v56];
          if ( v56 >= 4 )
          {
            v62 = 90 - ((signed int)*(_WORD *)(v57 + 24) >> 1);
            Render_DrawTransparentTexture(pD3DRenderer, v151 + v62 - 420, 126, dword_F8B168[v56]);
            v122 = v56 + 1;
            v58 = v151 + v62 + 80220;
          }
          else
          {
            v59 = 98 - *(_WORD *)(v57 + 26);
            v60 = dword_F8B168[v56];
            v61 = 98 - *(_WORD *)(v57 + 26);
            v150 = 86 - ((signed int)*(_WORD *)(v57 + 24) >> 1);
            Render_DrawTransparentTexture(pD3DRenderer, v150 + v151, v61, v60);
            v122 = v56 + 1;
            v58 = v150 + v151 + 640 * v59;
          }
          array_40F89C_ActuallyFillZBuffer(pD3DRenderer->pActiveZBuffer + 4 * v58, dword_F8B168[v56], v122);
          v10 = 0;
        }
        v151 += 105;
        ++v56;
      }
      while ( v56 < 8 );
    }
    v1 = sub_4B1784();
    if ( !v1 )
      return v1;
    v63 = 0;
    v147 = (int)v10;
    if ( dword_F8B19C == 2 )
    {
      do
      {
        if ( (char *)dword_AD4734[9 * (v63 + 12 * *(_DWORD *)(dword_507BC0 + 28))] != v10 )
          ++v147;
        ++v63;
      }
      while ( v63 < 6 );
    }
    else
    {
      do
      {
        if ( (char *)*(&dword_ADA0A4 + 9 * (v63 + 12 * *(_DWORD *)(dword_507BC0 + 28))) != v10 )
          ++v147;
        ++v63;
      }
      while ( v63 < 6 );
    }
    v65 = GetAsyncKeyState(17);
    v64 = sub_492C40((void *)v148);
    Str = (char *)v64;
    if ( v65 == (_WORD)v10 || (char *)v64 == v10 )
    {
      v66 = pGlobalTXT_LocalizationStrings[195];
      if ( dword_F8B19C != 2 )
        v66 = pGlobalTXT_LocalizationStrings[196];
    }
    else
    {
      v66 = pGlobalTXT_LocalizationStrings[185];
    }
    sub_4B46A5(v66, 0);
    if ( (char *)v147 != v10 )
    {
      v69 = class03_GetMousePos(pGame->pClass03, (int)&v132);
      v1 = *(_DWORD *)v69 + dword_5059A8[*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v130) + 4)];
      v68 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * v1) & 0xFFFF;
      if ( !(*(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * v1) & 0xFFFF) )
        return v1;
      v147 = v68 - 1;
      v70 = *(_DWORD *)(dword_507BC0 + 28);
      v71 = 9 * (v68 - 1 + 12 * v70);
      if ( dword_F8B19C == 2 )
        v72 = 4 * v71 + 11355956;
      else
        v72 = 4 * v71 + 11378852;
      if ( v65 == (_WORD)v10 || Str == v10 )
      {
        v120 = (__int64 *)v10;
        v118 = 2;
        v116 = *(_DWORD *)(dword_507BC0 + 28);
        v112 = v72;
        v73 = uActiveCharacter - 1;
        v12 = *(_DWORD *)&dword_73C388[4 * sub_490EEE((void *)v148, v72, 2, v70, 2)];
        v11 = v73;
      }
      else
      {
        v120 = (__int64 *)v10;
        v118 = 2;
        v116 = *(_DWORD *)(dword_507BC0 + 28);
        v112 = v72;
        v12 = pGlobalTXT_LocalizationStrings[181];
        v11 = uActiveCharacter - 1;
      }
LABEL_36:
      v32 = sub_495461((char *)v12, v11, v112, v116, v118, v120);
      v119 = 3;
      v117 = v32;
      v115 = v146[0];
      v113 = (int)v10;
      v109 = (char)v10;
      v107 = (int)&v140;
      goto LABEL_63;
    }
    v67 = *(_DWORD *)(dword_507BC0 + 28);
LABEL_96:
    compile_error;//LOBYTE(v1) = (unsigned int)sub_4B1854(&v140, __PAIR__(dword_ACD048[2 * v67], dword_ACD044[2 * v67]) - pParty_global->qword_00002C);
    return v1;
  }
  if ( dword_F8B19C == 5 )
  {
    sub_41A556();
    GameUI_DrawInventory(uActiveCharacter, 1);
    sub_4B46A5(pGlobalTXT_LocalizationStrings[198], 0);
    v1 = sub_4B1784();
    if ( !v1
      || (v29 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v131) - 14,
          v147 = (v29 >> 5) + 14 * ((*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v138) + 4) - 17) >> 5),
          v1 = class03_GetMousePos(pGame->pClass03, (int)&v136),
          *(_DWORD *)v1 <= 13)
      || (v1 = class03_GetMousePos(pGame->pClass03, (int)&v134), *(_DWORD *)v1 >= 462)
      || (v1 = sub_421E75((void *)v0, (int)&v147), v10 = 0, !v1)
      || (v1 *= 9, !(*(_BYTE *)(v0 + 4 * v1 + 516) & 2)) )
      return v1;
    v120 = 0;
    v118 = 5;
    v116 = *(_DWORD *)(dword_507BC0 + 28);
    v112 = v0 + 4 * v1 + 496;
    v30 = *(_DWORD *)(dword_507BC0 + 28);
    v149 = uActiveCharacter - 1;
    v31 = sub_490EEE((void *)v0, v0 + 4 * v1 + 496, 2, v30, 5);
    v11 = v149;
    v12 = *(_DWORD *)&dword_73C3C0[4 * v31];
    goto LABEL_36;
  }
  if ( dword_F8B19C == 1 )
  {
    v1 = sub_4B1784();
    if ( v1 )
    {
      v16 = (const char **)dword_F8B1B8;
      dword_F8B1B8[0] = pGlobalTXT_LocalizationStrings[134];
      dword_F8B1BC = pGlobalTXT_LocalizationStrings[152];
      dword_F8B1C0 = pGlobalTXT_LocalizationStrings[636];
      v15 = 0;
      dword_F8B1C4 = pGlobalTXT_LocalizationStrings[160];
      v17 = (const char **)dword_F8B1B8;
      do
      {
        v18 = sub_44C59D(pFontArrus, *v17, (int)&v140, 0, 0);
        ++v17;
        v15 += v18;
      }
      while ( (signed int)v17 < (signed int)&unk_F8B1C8 );
      v19 = dword_507BBC;
      v144 = (174 - v15) / 4;
      v1 = *(_DWORD *)(dword_507BBC + 56);
      v21 = v1 + *(_DWORD *)(dword_507BBC + 40);
      v20 = (174 - 4 * (174 - v15) / 4 - v15) / 2 - (174 - v15) / 4 / 2 + 138;
      v22 = -*(_DWORD *)(dword_507BBC + 40) < 0;
      v150 = *(_DWORD *)(dword_507BBC + 56);
      
      compile_error;//if ( v22 ^ __SETO__(v1, v21) )
      if (1)
      {
        v148 = 2;
        do
        {
          v25 = GUIWindow_GetChild(v19, v150);
          v26 = v25;
          *(_DWORD *)(v25 + 4) = v144 + v20;
          v27 = sub_44C59D(pFontArrus, *v16, (int)&v140, 0, 0);
          v24 = *(_DWORD *)(v26 + 4);
          v28 = v148;
          *(_DWORD *)(v26 + 12) = v27;
          v20 = v24 + v27 - 1;
          *(_DWORD *)(v26 + 20) = v20;
          v23 = v145[0];
          if ( *(_DWORD *)(dword_507BBC + 44) != v28 )
            v23 = v146[0];
          sub_44D406((int)&v140, pFontArrus, 0, v24, v23, *v16, 3);
          v19 = dword_507BBC;
          ++v148;
          ++v16;
          ++v150;
          v1 = *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56);
        }
        while ( v150 < v1 );
      }
    }
    return v1;
  }
  if ( dword_F8B19C == 2 )
    goto LABEL_64;
  if ( dword_F8B19C == 3 )
  {
    sub_41A556();
    GameUI_DrawInventory(uActiveCharacter, 1);
    sub_4B46A5(pGlobalTXT_LocalizationStrings[199], 0);
    v1 = sub_4B1784();
    if ( !v1
      || (v9 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v135) - 14,
          v147 = (v9 >> 5) + 14 * ((*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v129) + 4) - 17) >> 5),
          v1 = class03_GetMousePos(pGame->pClass03, (int)&v133),
          *(_DWORD *)v1 <= 13)
      || (v1 = class03_GetMousePos(pGame->pClass03, (int)&v125), *(_DWORD *)v1 >= 462)
      || (v1 = sub_421E75((void *)v0, (int)&v147), v10 = 0, !v1) )
      return v1;
    v120 = 0;
    v118 = 3;
    v116 = *(_DWORD *)(dword_507BC0 + 28);
    v112 = v0 + 36 * v1 + 496;
    v13 = *(_DWORD *)(dword_507BC0 + 28);
    v149 = uActiveCharacter - 1;
    v14 = sub_490EEE((void *)v0, v112, 2, v13, 3);
    v11 = v149;
    v12 = dword_73C3A4[v14];
    goto LABEL_36;
  }
  v1 = dword_F8B19C - 4;
  if ( dword_F8B19C == 4 )
  {
    sub_41A556();
    GameUI_DrawInventory(uActiveCharacter, 1);
    sub_4B46A5(pGlobalTXT_LocalizationStrings[197], 0);
    v1 = sub_4B1784();
    if ( v1 )
    {
      v2 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v127) - 14;
      v147 = (v2 >> 5) + 14 * ((*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v124) + 4) - 17) >> 5);
      v1 = class03_GetMousePos(pGame->pClass03, (int)&v137);
      if ( *(_DWORD *)v1 > 13 )
      {
        v1 = class03_GetMousePos(pGame->pClass03, (int)&v139);
        if ( *(_DWORD *)v1 < 462 )
        {
          v1 = sub_421E75((void *)v0, (int)&v147);
          if ( v1 )
          {
            v3 = v0 + 36 * v1 + 496;
            if ( *(_BYTE *)(v3 + 20) & 1 )
            {
              v114 = *(_DWORD *)(dword_507BC0 + 28);
              v4 = uActiveCharacter - 1;
              v5 = "%24";
              v110 = v3;
            }
            else
            {
              v114 = *(_DWORD *)(dword_507BC0 + 28);
              v110 = v3;
              v7 = *(_DWORD *)(dword_507BC0 + 28);
              v149 = uActiveCharacter - 1;
              v8 = sub_490EEE((void *)v0, v3, 2, v7, 4);
              v4 = v149;
              v5 = (char *)dword_73C3DC[v8];
            }
            v6 = sub_495461(v5, v4, v110, v114, 4, 0);
            v119 = 3;
            v117 = v6;
            v115 = v146[0];
            v111 = (174 - sub_44C59D(pFontArrus, v6, (int)&v140, 0, 0)) / 2 + 138;
            v108 = 0;
            goto LABEL_14;
          }
        }
      }
    }
  }
  return v1;
}

//----- (004BB756) --------------------------------------------------------
signed int __fastcall sub_4BB756(signed int a1)
{
  unsigned int v1; // esi@8
  signed int v3; // ecx@10
  signed int v4; // esi@15
  int v5; // ebx@16
  int v6; // ST38_4@16
  signed int v7; // esi@18
  int v8; // ebx@19
  int v9; // ST30_4@19
  int v10; // ST44_4@19
  int v11; // ST48_4@19
  int v12; // ST4C_4@19
  int v13; // ST50_4@19
  int v14; // ST3C_4@19
  int v15; // ST40_4@19
  int v16; // ST34_4@19
  int v17; // ST38_4@19
  int v19; // eax@26
  int v20; // eax@39
  int v21; // [sp-20h] [bp-54h]@25
  signed int v22; // [sp-1Ch] [bp-50h]@25
  int v23; // [sp-18h] [bp-4Ch]@25
  signed int v24; // [sp-14h] [bp-48h]@25
  int v25; // [sp-10h] [bp-44h]@25
  int v26; // [sp-10h] [bp-44h]@32
  int v27; // [sp-Ch] [bp-40h]@25
  int v28; // [sp-Ch] [bp-40h]@32
  int v29; // [sp-8h] [bp-3Ch]@25
  __int16 v30; // [sp-8h] [bp-3Ch]@32
  int v31; // [sp-4h] [bp-38h]@25
  int v32; // [sp-4h] [bp-38h]@32
 int i;

  if ( a1 > 39 )
  {
    if ( a1 != 40 )
    {
      if ( a1 == 41 )
      {
        if ( dword_50CBD0[0] < 40 )
        {
          dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
          dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
          dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
        }
        dword_50C9DC = 195;
        dword_50C9E0 = (int)sub_4459F9(dword_591090);
        return 0;
      }
      if ( a1 == 42 )
      {
        v32 = 0;
        v30 = 0;
        v28 = 133;
        v26 = 46;
      }
      else
      {
        if ( a1 == 43 )
        {
          v32 = 0;
          v30 = 0;
          v28 = 133;
          v26 = 51;
        }
        else
        {
          if ( a1 != 52 )
            return 0;
          v32 = 0;
          v30 = 0;
          v28 = 133;
          v26 = 86;
        }
      }
      sub_42777D(v26, 0, v28, v30, v32);
      return 0;
    }
    v20 = sub_4418B1(10005, 201, 0, 65536);
    sub_4584E0((int)&qword_ACD964, pParty_global->qword_00002C + 46080, (unsigned __int64)(pParty_global->qword_00002C + 46080) >> 32, 3, 0, v20, 0);
    byte_ACD973 |= 1u;
    v31 = 0;
    v29 = 0;
    v27 = 0;
    v25 = 0;
    v24 = -1;
    v23 = 0;
    v22 = 0;
    v21 = 12040;
LABEL_40:
    AudioPlayer_sub_4AA306(pAudioPlayer, v21, v22, v23, v24, v25, v27, v29, v31);
    return 0;
  }
  if ( a1 == 39 )
  {
    if ( dword_6BE360 == 1 )
    {
      sub_44C175(pGlobalTXT_LocalizationStrings[494], 2);
      v31 = 0;
      v29 = 0;
      v27 = 0;
      v25 = 0;
      v24 = -1;
      v23 = 0;
      v22 = 0;
      v21 = 203;
    }
    else
    {
      v19 = sub_4418B1(10008, 203, 0, 65536);
      sub_4584E0((int)&qword_ACD8B4, pParty_global->qword_00002C + 30720, (unsigned __int64)(pParty_global->qword_00002C + 30720) >> 32, 3, 1, v19, 0);
      byte_ACD8C3 |= 1u;
      v31 = 0;
      v29 = 0;
      v27 = 0;
      v25 = 0;
      v24 = -1;
      v23 = 0;
      v22 = 0;
      v21 = 11090;
    }
    goto LABEL_40;
  }
  if ( a1 == 10 )
  {
    for (i = 0; i < 4; ++i)
      pParty_global->pPlayers[i].sHealth = Player_GetMaxHealth(&pParty_global->pPlayers[i]);
    return 0;
  }
  if ( a1 == 11 )
  {
    v7 = (signed int)&unk_ACD9FC;
    do
    {
      v8 = *(_DWORD *)(v7 - 8);
      v9 = *(_DWORD *)(v7 - 4);
      v10 = *(_DWORD *)v7;
      v11 = *(_DWORD *)(v7 + 4);
      v12 = *(_DWORD *)(v7 + 8);
      v13 = *(_DWORD *)(v7 + 12);
      v14 = *(_DWORD *)(v7 + 32);
      v15 = *(_DWORD *)(v7 + 36);
      v16 = *(_DWORD *)(v7 + 16);
      v17 = *(_DWORD *)(v7 + 20);
      memset((void *)(v7 - 120), 0, 0xA0u);
      *(_DWORD *)(v7 + 8) = v12;
      *(_DWORD *)(v7 + 12) = v13;
      *(_DWORD *)v7 = v10;
      *(_DWORD *)(v7 + 4) = v11;
      *(_DWORD *)(v7 - 4) = v9;
      *(_DWORD *)(v7 + 32) = v14;
      *(_DWORD *)(v7 + 36) = v15;
      *(_DWORD *)(v7 + 16) = v16;
      *(_DWORD *)(v7 - 8) = v8;
      *(_DWORD *)(v7 + 20) = v17;
      *(_DWORD *)(v7 + 6340) = Player_GetMaxHealth(v7 - 120);
      v7 += 6972;
    }
    //while ( v7 < (signed int)&unk_AD46EC );
    while (v7 < pParty_global->HiredNPC[1].dword_00002C);
    return 0;
  }
  if ( a1 == 12 )
  {
    v4 = (signed int)&unk_ACDA9C;
    do
    {
      v5 = *(_DWORD *)(v4 - 128);
      v6 = *(_DWORD *)(v4 - 124);
      memset((void *)(v4 - 280), 0, 0xA0u);
      *(_DWORD *)v4 = v5;
      *(_DWORD *)(v4 + 4) = v6;
      *(_DWORD *)(v4 + 6180) = Player_GetMaxHealth(v4 - 280);
      v4 += 6972;
    }
    while ( v4 < (signed int)&unk_AD478C );
    return 0;
  }
  if ( a1 == 33 )
  {
    v1 = 14;
    if ( (unsigned int)pParty_global->uNumFood >= 0xE )
      return 1;
    v3 = 1;
    goto LABEL_13;
  }
  if ( a1 == 34 )
  {
    v1 = 14;
    if ( (unsigned int)pParty_global->uNumFood >= 0xE )
      return 1;
    v3 = 2;
LABEL_13:
    sub_492B42((void *)v3);
    if ( pParty_global->uNumFood > v1 )
      pParty_global->uNumFood = v1;
  }
  return 0;
}

//----- (004BBA85) --------------------------------------------------------
int __cdecl sub_4BBA85()
{
  int v0; // ecx@1
  int v1; // edi@1
  int i; // eax@4
  signed __int64 v3; // qax@4
  int v4; // edx@5
  unsigned __int16 v5; // ax@16
  int v6; // edi@16
  char v7; // zf@16
  int result; // eax@21
  char v10; // zf@22

  dword_59108C = 83;
  GUIWindowDelete(dword_507BBC);
  dword_507BBC = GUIWindowCreate(0, 0, 640, 350, 1, 0, 0);
  dword_5076F4 = GUIButtonCreate(
                   dword_507BBC,
                   471,
                   445,
                   169,
                   35,
                   1,
                   0,
                   113,
                   0,
                   0,
                   pGlobalTXT_LocalizationStrings[34],
                   dword_506438 != -1 ? 72 * dword_506438 + 7145548 : 0);
  GUIButtonCreate(dword_507BBC, 0, 0, 0, 0, 1, 0, 81, 0, 0, Class, 0);
  GUIButtonCreate(dword_507BBC, 480, 160, 140, 30, 1, 0, 0, 83, 0, Class, 0);
  sub_41D08F(dword_507BBC, 1, 1, 0, 2);
  dword_F8B19C = -1;
  v1 = *(_DWORD *)(dword_507BC0 + 28) - 102;
  v0 = pParty_global->array_00003C[2 * v1 + 1];
  if ( v0 <= HIDWORD(pParty_global->qword_00002C) )
  {
    if ( v0 < HIDWORD(pParty_global->qword_00002C) || pParty_global->array_00003C[2 * v1] < (_DWORD)pParty_global->qword_00002C )
    {
      word_ACD712[v1] = 0;
      v3 = (signed __int64)((double)(309657600
                                   * ((unsigned int)pParty_global->uCurrentMonth + 12i64 * (unsigned int)pParty_global->uCurrentYear - 14015))
                          * 0.03333333507180214);
      pParty_global->array_00003C[2 * v1] = v3;
      pParty_global->array_00003C[2 * v1 + 1] = HIDWORD(v3);
      for ( i = rand(); ; i = rand() )
      {
        v4 = i % 258 + 1;
        word_ACD708[v1] = v4;
        if ( (_WORD)v4 < 0x73u || (_WORD)v4 > 0x84u )
        {
          if ( ((_WORD)v4 < 0xEBu || (_WORD)v4 > 0xFCu)
            && ((_WORD)v4 < 0x85u || (_WORD)v4 > 0x96u)
            && ((_WORD)v4 < 0x97u || (_WORD)v4 > 0xBAu)
            && ((_WORD)v4 < 0xC4u || (_WORD)v4 > 0xC6u) )
            break;
        }
      }
    }
  }
  v6 = 2 * v1;
  v5 = *(__int16 *)((char *)word_ACD708 + v6);
  v7 = *(__int16 *)((char *)word_ACD712 + v6) == 0;
  word_F8B1A0 = *(__int16 *)((char *)word_ACD708 + v6);
  if ( v7 )
  {
    v10 = v5 == 0;
    result = dword_722164;
    if ( v10 )
      result = dword_722174;
  }
  else
  {
    if ( v5 )
    {
      sub_420C05(100 * pMonsterStats->pMonsterInfos[v5].uLevel, 0);

      for (i = 0; i < 4; ++i)
        sub_44A5CB(&pParty_global->pPlayers[i], 12, 86);

      pParty_global->dword_000748 += 100 * pMonsterStats->pMonsterInfos[*(unsigned __int16 *)((char *)word_ACD708 + v6)].uLevel;
      *(__int16 *)((char *)word_ACD708 + v6) = 0;
      *(__int16 *)((char *)word_ACD712 + v6) = 0;
    }
    result = dword_72216C;
  }
  dword_F8B1A4 = result;
  return result;
}

//----- (004BBCDD) --------------------------------------------------------
void __cdecl sub_4BBCDD()
{
  signed int v0; // ebp@3
  int v1; // eax@4
  __int16 v2; // cx@5
  int v3; // esi@8
  int v6; // eax@18
  int v7; // esi@19
  size_t v8; // [sp+10h] [bp-4h]@4
 int i;

  if ( byte_ACD76D )
  {
    if ( byte_ACD76D == -1 )
    {
      dword_59108C = 92;
    }
    else
    {
      v0 = 0;
      if ( (signed int)uNumActors <= 0 )
        goto LABEL_23;
      v1 = &pActors[0].word_0000B0;
      v8 = uNumActors;
      do
      {
        v2 = *(_WORD *)v1;
        if ( *(_WORD *)v1 == 5 || v2 == 11 || v2 == 19 || (v3 = *(_DWORD *)(v1 + 636)) != 0 && (v3 & 7) == 4 )
          ++v0;
        v1 += 836;
      }
      while ( v8-- != 1 );
      if ( v0 >= (signed int)uNumActors )
      {
LABEL_23:
        dword_59108C = 91;
        ++byte_ACD719[(unsigned __int8)byte_ACD76D];

        for (i = 0; i < 4; ++i)
          sub_44A5CB(&pParty_global->pPlayers[i], 12, (unsigned __int8)byte_ACD76D + 3);

        sub_420C05(dword_F8B1B4, 0);
        AudioPlayer_sub_4AA306(pAudioPlayer, 14060, 0, 0, -1, 0, 0, 0, 0);
        byte_ACD76D = -1;
      }
      else
      {
        dword_59108C = 90;
        pParty_global->sPartyPosX = 3849;
        pParty_global->sPartyPosY = 5770;
        pParty_global->sPartyPosZ = 1;
        pParty_global->dword_000700 = 1;
        pParty_global->sRotationY = 512;
        pParty_global->sRotationX = 0;
        pParty_global->dword_0006E8 = 0;
        AudioPlayer_sub_4AA306(pAudioPlayer, 14060, 0, 0, -1, 0, 0, 0, 0);
      }
    }
  }
  else
  {
    dword_59108C = 89;
    v6 = *(_DWORD *)(dword_507BBC + 76);
    if ( v6 )
    {
      do
      {
        v7 = *(_DWORD *)(v6 + 52);
        class23_DeleteBuffer(class23_instance, v6);
        v6 = v7;
      }
      while ( v7 );
    }
    *(_DWORD *)(dword_507BBC + 76) = 0;
    *(_DWORD *)(dword_507BBC + 80) = 0;
    *(_DWORD *)(dword_507BBC + 32) = 0;
    dword_5076F4 = GUIButtonCreate(
                     dword_507BBC,
                     471,
                     445,
                     169,
                     35,
                     1,
                     0,
                     113,
                     0,
                     0,
                     pGlobalTXT_LocalizationStrings[79],
                     dword_506438 != -1 ? 72 * dword_506438 + 7145548 : 0);
    GUIButtonCreate(dword_507BBC, 480, 160, 140, 30, 1, 0, 136, 85, 0, Class, 0);
    GUIButtonCreate(dword_507BBC, 480, 190, 140, 30, 1, 0, 136, 86, 0, Class, 0);
    GUIButtonCreate(dword_507BBC, 480, 220, 140, 30, 1, 0, 136, 87, 0, Class, 0);
    GUIButtonCreate(dword_507BBC, 480, 250, 140, 30, 1, 0, 136, 88, 0, Class, 0);
    sub_41D08F(dword_507BBC, 4, 1, 0, 1);
  }
}

//----- (004BBF61) --------------------------------------------------------
void __fastcall sub_4BBF61(int a1, __int16 a2, signed int a3, int a4)
{
  int v4; // edi@1
  size_t v5; // esi@1
  int *v6; // ebx@5
  int *v7; // edi@5
  int v8; // esi@5
  int v9; // eax@5
  int v10; // ebx@5
  int v12; // ebx@7
  int v13; // eax@8
  __int16 v14; // [sp+8h] [bp-Ch]@1
  __int16 v15; // [sp+Ch] [bp-8h]@1
  __int16 v16; // [sp+10h] [bp-4h]@3
  signed int v17; // [sp+1Ch] [bp+8h]@5

  v5 = uNumActors;
  v4 = a1;
  v14 = a2;
  v15 = a1;
  if ( (signed int)uNumActors < 500 )
  {
    if ( (dword_71FFF8 >> 10) - (dword_71FFF4 >> 10) >= 2000 )
    {
      v16 = 0;
      if ( dword_6BE360 == 1 )
      {
        v5 = uNumActors;
        v16 = sub_49AC17((int)byte_6BE3C8, a2, a3, a4);
      }
      v8 = (int)((char *)pActors + 836 * v5);
      Actor_Reset(v8);
      v9 = v4;
      v7 = &pMonsterStats->pMonsterInfos[v4];
      v10 = 152 * v9 + pMonsterDescriptionList->pDescriptions - 152;
      strcpy((char *)v8, (const char *)*v7);
      *(_WORD *)(v8 + 40) = *((_WORD *)v7 + 32);
      memcpy((void *)(v8 + 44), v7, 0x58u);
      *(_WORD *)(v8 + 134) = v15;
      *(_WORD *)(v8 + 136) = *(_WORD *)(v10 + 2);
      *(_WORD *)(v8 + 138) = *(_WORD *)v10;
      *(_WORD *)(v8 + 140) = *(_WORD *)(v10 + 4);
      *(_WORD *)(v8 + 162) = v14;
      *(_WORD *)(v8 + 142) = v14;
      *(_BYTE *)(v8 + 38) |= 8u;
      *(_BYTE *)(v8 + 57) = 0;
      *(_BYTE *)(v8 + 56) = 0;
      *(_BYTE *)(v8 + 55) = 0;
      *(_BYTE *)(v8 + 54) = 0;
      *(_BYTE *)(v8 + 53) = 0;
      *(_WORD *)(v8 + 164) = a3;
      *(_WORD *)(v8 + 144) = a3;
      *(_WORD *)(v8 + 166) = a4;
      *(_WORD *)(v8 + 146) = a4;
      *(_WORD *)(v8 + 174) = 256;
      *(_WORD *)(v8 + 158) = v16;
      *(_DWORD *)(v8 + 708) = 1;
      *(_BYTE *)(v8 + 61) = 4;
      Actor_LinkSprites(v8, 0);
      v6 = (int *)(v10 + 12);
      v17 = 4;
      do
      {
        sub_4A9A67(pSoundList, *(_WORD *)v6, 0);
        v6 = (int *)((char *)v6 + 2);
      }
      while ( v17-- != 1 );
      v12 = 0;
      do
        v13 = sub_4A9A67(pSoundList, v12++ + word_4EE088[*((_BYTE *)v7 + 33)], 1);
      while ( v13 );
      ++uNumActors;
    }
  }
}

//----- (004BC109) --------------------------------------------------------
void __cdecl sub_4BC109()
{
  int v0; // edi@1
  char *v1; // eax@7
  signed int v3; // esi@10
  int v4; // eax@10
  signed __int64 v5; // qax@18
  signed int v6; // ebx@34
  signed int v7; // edi@34
  int v8; // eax@37
  int v9; // esi@43
  int v10; // eax@44
  unsigned __int8 v11; // sf@44
  unsigned __int8 v12; // of@44
  signed int v13; // eax@49
  int v14; // esi@49
  int v15; // edx@50
  int v16; // eax@51
  signed int v17; // ecx@51
  int v18; // edx@53
  int v19; // edi@55
  signed int v20; // ST18_4@56
  int v21; // eax@56
  signed int v22; // [sp-4h] [bp-144h]@51
  __int16 v23[100]; // [sp+Ch] [bp-134h]@39
  char v24; // [sp+D4h] [bp-6Ch]@1
  int v25; // [sp+DCh] [bp-64h]@1
  int v26; // [sp+E4h] [bp-5Ch]@1
  __int16 v27; // [sp+126h] [bp-1Ah]@44
  __int16 v28[6]; // [sp+128h] [bp-18h]@56
  int v29; // [sp+134h] [bp-Ch]@1
  int v30; // [sp+138h] [bp-8h]@23
  int v31; // [sp+13Ch] [bp-4h]@17
 int i;

  v29 = 0;
  byte_ACD76D = dword_59108C;
  memcpy(&v24, (const void *)dword_507BBC, 0x54u);
  v25 = 460;
  v26 = 452;
  v0 = sub_44C59D(pFontArrus, pGlobalTXT_LocalizationStrings[575], (int)&v24, 13, 0) + 7;
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
  Render_sub_4A1FE1_MaybeRenderSpecialEffects(pD3DRenderer);
  Render_BeginScene(pD3DRenderer);
  if ( pD3DRenderer->pRendererD3D3 )
    sub_4A6D87(pD3DRenderer,
      1,
      class28_global.dword_000010,
      class28_global.dword_000014,
      class28_global.dword_000018 - class28_global.dword_000010,
      class28_global.dword_00001C - class28_global.dword_000014 + 1,
      pD3DRenderer->uTargetGMask | pD3DRenderer->uTargetBMask);
  sub_4A6A68(pD3DRenderer,
    8,
    352 - v0,
    uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 : 0,
    *(_WORD *)(uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 + 0x1A : 26) - v0);
  Render_DrawIndexedTexture(pD3DRenderer, 8, 347 - v0, pClass18_EndcapTexture);
  v1 = FitTextInAWindow(pGlobalTXT_LocalizationStrings[575], pFontArrus, (int)&v24, 13, 0);
  FontDrawText(dword_507BBC, pFontArrus, 13, 354 - v0, v1, 0, 0, 0);
  Render_EndScene(pD3DRenderer);
  Render_Present(pD3DRenderer);
  pParty_global->sPartyPosX = 3849;
  pParty_global->sPartyPosY = 5770;
  pParty_global->sPartyPosZ = 1;
  pParty_global->dword_000700 = 1;
  pParty_global->sRotationY = 512;
  pParty_global->sRotationX = 0;
  pParty_global->dword_0006E8 = 0;
  if ( dword_50CBD0[0] < 40 )
  {
    dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
    dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
    dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
  }


  for (i = 0; i < 4; ++i)
  {
    v4 = Player_GetActualLevel(&pParty_global->pPlayers[i]);
    v3 = v29;
    if ( v4 > v29 )
    {
      v29 = Player_GetActualLevel(&pParty_global->pPlayers[i]);
      v3 = v29;
    }
  }

  if ( dword_59108C == 85 )
  {
    v31 = v3;
    goto LABEL_22;
  }
  if ( dword_59108C == 86 )
  {
    v5 = (signed __int64)((double)v29 * *(double *)&byte_4D8410[1448]);
    goto LABEL_20;
  }
  if ( dword_59108C == 87 )
  {
    LODWORD(v5) = 2 * v3;
LABEL_20:
    v31 = v5;
LABEL_22:
    v3 /= 2;
    goto LABEL_24;
  }
  if ( dword_59108C == 88 )
    v31 = 2 * v3;
  else
    v3 = v30;
LABEL_24:
  if ( v3 < 1 )
    v3 = 1;
  if ( v3 > 100 )
    v3 = 100;
  if ( v31 > 100 )
    v31 = 100;
  if ( v3 < 2 )
    v3 = 2;
  if ( v31 < 2 )
    v31 = 2;
  v6 = 0;
  v30 = 1;

  //v7 = (signed int)&unk_5CCEA0;
  v7 = &pMonsterStats->pMonsterInfos[1].uLevel;
  do
  {
    if ( *(_BYTE *)(v7 + 8) != 1 )
    {
      if ( !sub_438BDF(*(_WORD *)(v7 + 44), 8) )
      {
        v8 = *(_BYTE *)v7;
        if ( v8 >= v3 )
        {
          if ( v8 <= v31 )
            v23[v6++] = v30;
        }
      }
    }
    ++v30;
    v7 += 88;
  }
  //while ( v7 <= (signed int)&unk_5D26F8 );
  while (v7 <= &pMonsterStats->pMonsterInfos[102].uLevel);

  v31 = 6;
  if ( v6 < 6 )
    v31 = v6;
  v9 = 0;
  if ( v31 > 0 )
  {
    do
    {
      v10 = rand();
      ++v9;
      compile_error;//v12 = __SETO__(v9, v31);
      v11 = v9 - v31 < 0;
      *(&v27 + v9) = v23[v10 % v6];
    }
    while ( v11 ^ v12 );
  }
  if ( dword_59108C == 85 )
  {
    v16 = rand();
    v17 = 3;
    v22 = 50;
    goto LABEL_53;
  }
  if ( dword_59108C == 86 )
  {
    v16 = rand();
    v17 = 7;
    v22 = 100;
LABEL_53:
    v18 = v16 % v17;
    v13 = v22;
    v14 = v18 + 6;
    goto LABEL_55;
  }
  if ( dword_59108C == 87 )
  {
    v15 = rand() % 11;
    v13 = 200;
    v14 = v15 + 10;
  }
  else
  {
    if ( dword_59108C == 88 )
    {
      v13 = 500;
      v14 = 20;
    }
    else
    {
      v14 = v30;
      v13 = dword_F8B1B4;
    }
  }
LABEL_55:
  v19 = 0;
  for ( dword_F8B1B4 = v29 * v13; v19 < v14; ++v19 )
  {
    v20 = dword_4F0E94[2 * v19];
    v21 = rand();
    sub_4BBF61((unsigned __int16)v28[v21 % v31], dword_4F0E90[2 * v19], v20, 1);
  }
  AudioPlayer_sub_4AA306(pAudioPlayer, 14060, 0, 0, -1, 0, 0, 0, 0);
}

//----- (004BC49B) --------------------------------------------------------
void __thiscall sub_4BC49B(void *this)
{
  signed int v1; // eax@1
  char *v2; // ebp@1
  int v3; // esi@1
  int v4; // ecx@10
  int v5; // edi@14
  _UNKNOWN *v6; // esi@15
  const char *v7; // ecx@22
  int v8; // edi@37
  int v9; // eax@56
  unsigned int v10; // ecx@57
  void *v11; // [sp-Ch] [bp-1Ch]@46
  int v12; // [sp-8h] [bp-18h]@46
  char *v13; // [sp-8h] [bp-18h]@60
  size_t v14; // [sp-4h] [bp-14h]@46
  const char *v15; // [sp-4h] [bp-14h]@60

  v3 = (int)this;
  v2 = sub_4459F9(dword_591090);
  v1 = v3;
  dword_59108C = v3;
  if ( !*((_DWORD *)v2 + 2) )
  {
    *((_DWORD *)v2 + 2) = 1;
    v1 = dword_59108C;
  }
  if ( v1 > 22 )
  {
    if ( v1 == 23 )
    {
      v4 = *((_DWORD *)v2 + 14);
      goto LABEL_74;
    }
    if ( v1 == 24 )
    {
      v4 = *((_DWORD *)v2 + 15);
      goto LABEL_74;
    }
    if ( v1 != 76 )
    {
      if ( v1 == 77 )
      {
        byte_F8B1EC ^= 1u;
      }
      else
      {
        if ( v1 > 84 && v1 <= 88 )
        {
          sub_4BC109();
          return;
        }
      }
      goto LABEL_87;
    }
    if ( v2[8] & 0x80 )
    {
      v8 = 0;
      if (pNPCStats->dword_017FC4 > 0)
      {
        v6 = pNPCStats->pNPCData2;
        while ( !(*((_BYTE *)v6 + 8) & 0x80) || strcmp(*(const char **)v2, *(const char **)v6) )
        {
          ++v8;
          v6 = (char *)v6 + 76;
          if ( v8 >= pNPCStats->dword_017FC4)
            goto LABEL_44;
        }
        goto LABEL_43;
      }
LABEL_44:
      if (!pParty_global->HiredNPC[0].pNPCName || strcmpi(pParty_global->HiredNPC[0].pNPCName, *(const char **)v2))
      {
        if (!pParty_global->HiredNPC[1].pNPCName || strcmpi(pParty_global->HiredNPC[1].pNPCName, *(const char **)v2))
          goto LABEL_51;
        v14 = 76;
        v12 = 0;
        v11 = &pParty_global->HiredNPC[1];
      }
      else
      {
        v14 = 76;
        v12 = 0;
        v11 = &pParty_global->HiredNPC[0];
      }
      memset(v11, v12, v14);
LABEL_51:
      pParty_global->byte_000709 = 0;
      sub_44A56A();
      dword_591084 = 0;
      if ( dword_50CBD0[0] < 40 )
      {
        dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
        dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
        dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
      }
      goto LABEL_89;
    }
    if (pParty_global->HiredNPC[0].pNPCName && pParty_global->HiredNPC[1].pNPCName)
    {
      v7 = pGlobalTXT_LocalizationStrings[533];
LABEL_64:
      sub_44C175(v7, 2);
      goto LABEL_87;
    }
    v9 = *((_DWORD *)v2 + 6);
    if ( v9 != 51 )
    {
      v10 = dword_737C28[5 * v9];
      if ( pParty_global->uNumGold < v10 )
      {
        sub_44C175(pGlobalTXT_LocalizationStrings[155], 2);
        byte_F8B1EC = 0;
        dword_59108C = 13;
        if ( uActiveCharacter )
          sub_4948B1(*(&ptr_A750C4 + uActiveCharacter), 38, 0);
        v7 = pGlobalTXT_LocalizationStrings[155];
        goto LABEL_64;
      }
      sub_492BB6(v10);
    }
    v2[8] |= 0x80u;
    if (pParty_global->HiredNPC[0].pNPCName)
    {
      memcpy(&pParty_global->HiredNPC[1], v2, sizeof(struct NPCData));
      v15 = *(const char **)v2;
      v13 = (char *)&unk_AE3090;
    }
    else
    {
      memcpy(&pParty_global->HiredNPC[0], v2, sizeof(struct NPCData));
      v15 = *(const char **)v2;
      v13 = byte_AE302C;
    }
    strcpy(v13, v15);
    pParty_global->byte_000709 = 0;
    sub_44A56A();
    if ( dword_50CBD0[0] < 40 )
    {
      dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
      dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
      dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
    }
    if ( dword_591090 >= 0 )
      *(_WORD *)(dword_591088 + 176) = 11;
    if ( uActiveCharacter )
      sub_4948B1(*(&ptr_A750C4 + uActiveCharacter), 61, 0);
    goto LABEL_87;
  }
  if ( v1 == 22 )
  {
    v4 = *((_DWORD *)v2 + 13);
    goto LABEL_74;
  }
  if ( v1 == 9 )
  {
    if ( !sub_4BB756(*((_DWORD *)v2 + 6)) )
    {
      if ( *((_DWORD *)v2 + 6) != 41 )
        *((_DWORD *)v2 + 17) = 1;
      if ( dword_50CBD0[0] < 40 )
      {
        dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
        dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
        dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
      }
      goto LABEL_87;
    }
    v7 = pGlobalTXT_LocalizationStrings[140];
    goto LABEL_64;
  }
  if ( v1 == 13 )
  {
    if ( !(v2[8] & 0x80) )
    {
      sub_4B3E1E();
      byte_F8B1EC = 0;
      goto LABEL_87;
    }
    v5 = 0;
    if (pNPCStats->dword_017FC4 > 0)
    {
      v6 = pNPCStats->pNPCData2;
      while ( !(*((_BYTE *)v6 + 8) & 0x80) || strcmp(*(const char **)v2, *(const char **)v6) )
      {
        ++v5;
        v6 = (char *)v6 + 76;
        if ( v5 >= pNPCStats->dword_017FC4)
          goto LABEL_44;
      }
LABEL_43:
      *((_BYTE *)v6 + 8) &= 0x7Fu;
      goto LABEL_44;
    }
    goto LABEL_44;
  }
  if ( v1 == 19 )
  {
    v4 = *((_DWORD *)v2 + 10);
    goto LABEL_74;
  }
  if ( v1 == 20 )
  {
    v4 = *((_DWORD *)v2 + 11);
    goto LABEL_74;
  }
  if ( v1 == 21 )
  {
    v4 = *((_DWORD *)v2 + 12);
LABEL_74:
    if ( v4 < 200 || v4 > 310 )
    {
      if ( v4 < 400 || v4 > 410 )
      {
        switch ( v4 )
        {
          case 139:
            sub_4B1ECE();
            break;
          case 311:
            sub_4BBA85();
            break;
          case 399:
            sub_4BBCDD();
            break;
          default:
            dword_5C3420 = 1;
            dword_F8B1E8 = 0;
            sub_44684A_LooksLikeEventProcessor(v4, 0, 1);
            dword_5C3420 = 0;
            break;
        }
      }
      else
      {
        dword_F8B1D8 = v1;
        sub_4B3EF0(v4 - 400);
      }
    }
    else
    {
      sub_4B3FE5((void *)v4);
    }
  }
LABEL_87:
  if ( !dword_7241C8 )
    sub_44103C();
LABEL_89:
  dword_7241C8 = 0;
}

//----- (004BC8D5) --------------------------------------------------------
int __cdecl sub_4BC8D5()
{
  int v0; // ebx@1
  signed int v1; // edi@1
  int v2; // esi@1
  int v3; // ST18_4@1
  signed int v4; // eax@2
  int v5; // esi@7
  int result; // eax@15
  int v7; // ebp@15

  v2 = v3;
  v0 = *(_DWORD *)(dword_507BC0 + 28) - 139;
  v1 = 0;
  do
  {
    v4 = word_591438[26 * *(_DWORD *)(dword_507BC0 + 28)];
    if ( v4 < 5 )
      goto LABEL_12;
    if ( v4 <= 13 )
    {
      v2 = rand() % word_4F0F30[v0] + 11 * word_591438[26 * *(_DWORD *)(dword_507BC0 + 28)] + 345;
    }
    else
    {
      if ( v4 == 14 )
      {
        v5 = rand() % 4;
      }
      else
      {
        if ( v4 == 15 )
        {
          v5 = rand() % 3 + 4;
        }
        else
        {
          if ( v4 != 16 )
            goto LABEL_12;
          v5 = rand() % 2 + 7;
        }
      }
      v2 = rand() % word_4F0F30[v0] + 11 * v5 + 400;
    }
LABEL_12:
    if ( v2 == 487 )
    {
      if ( !(unsigned __int16)sub_449B57((int)byte_ACD71D, 239) )
        --v2;
    }
    v7 = dword_507BC0;
    ItemGen_Reset(36 * (v1 + 12 * *(_DWORD *)(dword_507BC0 + 28)) + 11341700);
    dword_AD0F84[9 * (v1 + 12 * *(_DWORD *)(v7 + 28))] = v2;
    dword_AD0F98[9 * (v1++ + 12 * *(_DWORD *)(v7 + 28))] = 1;
    result = 72 * LODFile_LoadTexture(pLODFile_Icons_LOD, pClass40->pItems[v2].pIconName, 2) + 7145548;
    dword_F8B164[v1] = result;
  }
  while ( v1 < 12 );
  return result;
}

//----- (004BCA33) --------------------------------------------------------
int __cdecl sub_4BCA33()
{
  GUIWindowDelete(dword_507BBC);
  dword_507BBC = GUIWindowCreate(0, 0, 640, 345, 1, 0, 0);
  dword_5076F4 = GUIButtonCreate(
                   dword_507BBC,
                   471,
                   445,
                   169,
                   35,
                   1,
                   0,
                   113,
                   0,
                   0,
                   pGlobalTXT_LocalizationStrings[74],
                   dword_506438 != -1 ? 72 * dword_506438 + 7145548 : 0);
  return GUIButtonCreate(dword_507BBC, 8, 8, 450, 320, 1, 0, 81, 0, 0, Class, 0);
}

//----- (004BCACC) --------------------------------------------------------
void __fastcall sub_4BCACC(signed int a1, int a2)
{
  signed int v2; // ebx@1
  int v3; // edi@1
  signed int v4; // ecx@2
  int v5; // eax@5
  signed int v6; // edx@5
  int v7; // ecx@5
  signed int v8; // esi@5
  __int64 v9; // qax@8
  int v10; // esi@8
  int v11; // esi@12
  int v12; // eax@14
  int v13; // eax@33
  int v14; // edi@33
  int v15; // esi@33
  int v16; // eax@36
  __int16 v17; // bp@36
  int v18; // esi@36
  int v19; // edx@36
  int v20; // eax@36
  int v21; // eax@37
  int v22; // eax@38
  int v23; // eax@39
  unsigned __int16 v24; // ax@41
  unsigned __int16 v25; // ax@80
  unsigned __int16 v26; // ax@111
  unsigned __int16 v27; // ax@136
  unsigned __int16 v28; // ax@167
  unsigned __int16 v29; // ax@194
  int v30; // esi@194
  char v31; // zf@194
  char *v32; // edi@196
  int v33; // eax@208
  char v34; // zf@208
  int v35; // eax@211
  int v36; // ecx@211
  int v37; // esi@214
  __int64 v38; // qax@214
  signed int v39; // edi@215
  int v40; // eax@216
  int v41; // ecx@233
  int v42; // edi@233
  signed int v43; // esi@233
  int v44; // esi@236
  int v45; // edx@241
  int v46; // eax@248
  int v47; // edx@248
  int v48; // edi@251
  __int64 v49; // qax@251
  int v50; // eax@252
  int v51; // edx@252
  signed int v52; // edi@252
  int v53; // eax@254
  int v54; // eax@255
  int v55; // eax@258
  signed int v56; // edi@258
  int v57; // eax@264
  int v58; // eax@265
  int v59; // eax@268
  signed int v60; // edi@268
  signed int v61; // [sp+10h] [bp-10h]@1
  int v62; // [sp+14h] [bp-Ch]@33
 int i;

  v3 = 0;
  v2 = a1;
  v61 = a1;
  if ( !*(_DWORD *)(dword_507BBC + 40) )
    return;
  Render_ClearZBuffer(pD3DRenderer, 0, 479);
  v4 = dword_F8B198;
  if ( dword_F8B19C != 1 )
    goto LABEL_15;
  if ( dword_F8B198 == 30 )
  {
    if ( v2 == 17 )
    {
      v5 = 0;
      v8 = 0;
      v7 = (int)*(&ptr_A750C4 + uActiveCharacter);
      v6 = *(_WORD *)(v7 + 218);
      if ( v6 > 0 )
      {
        do
          v5 += v8++ + 1;
        while ( v8 < v6 );
      }
      if ( v6 < (unsigned __int16)word_4F0866[*(_DWORD *)(dword_507BC0 + 28)] )
      {
        v10 = *(_DWORD *)(v7 + 164);
        v9 = 1000 * v5;
        if ( v10 < HIDWORD(v9) || v10 <= HIDWORD(v9) && *(_DWORD *)(v7 + 160) < (_DWORD)v9 )
          return;
      }
    }
    goto LABEL_11;
  }
  v11 = dword_507BC0;
  if ( (dword_F8B198 == 27 || dword_F8B198 == 28)
    && (v3 = 0,
        *(&byte_4F09B1[32 * (unsigned __int8)*(&byte_4F0CCF[4 * *(_DWORD *)(dword_507BC0 + 28)] + v2)]
        + pParty_global->uDaysPlayed % 7u))
    || dword_F8B198 != 23
    || v61 != 10 )
  {
LABEL_11:
    GUIWindowDelete(dword_507BBC);
    dword_507BBC = GUIWindowCreate(0, 0, 640, 345, 1, v3, v3);
    dword_5076F4 = GUIButtonCreate(
                     dword_507BBC,
                     526,
                     445,
                     75,
                     33,
                     1,
                     v3,
                     113,
                     v3,
                     v3,
                     pGlobalTXT_LocalizationStrings[74],
                     uTextureIdx_BtnEsc2 + 1 != 0 ? 72 * (_DWORD)uTextureIdx_BtnEsc2 + 7145548 : 0);
    GUIButtonCreate(dword_507BBC, 8, 8, 450, 320, 1, v3, 81, v3, v3, Class, v3);
LABEL_12:
    v4 = dword_F8B198;
    v11 = dword_507BC0;
    goto LABEL_13;
  }
  if ( uActiveCharacter != v3 )
  {
    if ( !sub_4B6FF9(*(&ptr_A750C4 + uActiveCharacter)) )
      return;
    goto LABEL_12;
  }
LABEL_13:
  dword_F8B19C = v61;
  if ( v4 < 19 )
  {
    v12 = LODFile_LoadTexture(pLODFile_Icons_LOD, (&off_4F03B8)[4 * v4], 2);
    v4 = dword_F8B198;
    dword_F8B164[0] = 72 * v12 + 7145548;
LABEL_15:
    v11 = dword_507BC0;
  }
  if ( v4 > 21 )
  {
    if ( v4 == 22 )
    {
      if ( dword_F8B19C >= 7 )
      {
        if ( dword_F8B19C <= 8 )
          sub_459E5A((int)&dword_69AE00, 1, 10, v11);
      }
      return;
    }
    if ( v4 != 23 && v4 != 30 )
      return;
  }
  else
  {
    if ( v4 != 21 )
    {
      if ( v4 <= v3 )
        return;
      if ( v4 > 4 )
      {
        if ( v4 <= 16 )
        {
          v35 = *(_DWORD *)(v11 + 28);
          v36 = dword_ACCD98[2 * v35];
          if ( v36 > HIDWORD(pParty_global->qword_00002C)
            || v36 >= HIDWORD(pParty_global->qword_00002C) && (unsigned int)dword_ACCD94[2 * v35] >= (_DWORD)pParty_global->qword_00002C )
          {
            v39 = 0;
            do
            {
              v40 = dword_AD0F84[9 * (v39 + 12 * *(_DWORD *)(v11 + 28))];
              if ( v40 )
              {
                v11 = dword_507BC0;
                dword_F8B168[v39] = 72 * LODFile_LoadTexture(pLODFile_Icons_LOD, pClass40->pItems[v40].pIconName, 2)
                                  + 7145548;
              }
              ++v39;
            }
            while ( v39 < 12 );
          }
          else
          {
            sub_4BC8D5();
            v37 = *(_DWORD *)(dword_507BC0 + 28);
            v38 = pParty_global->qword_00002C
                + (signed __int64)((double)(11059200 * (signed int)word_591454[26 * *(_DWORD *)(dword_507BC0 + 28)])
                                 * 0.03333333507180214);
            dword_ACCD94[2 * v37] = v38;
            dword_ACCD98[2 * v37] = HIDWORD(v38);
          }
          return;
        }
        if ( v4 != 17 )
          return;
        if ( v61 == 99 )
        {
          v15 = *(_DWORD *)(v11 + 28) - 102;
          v62 = v15;
          v14 = 8 * v15 + 11325428;
          v13 = pParty_global->array_00003C[2 * v15 + 1];
          if ( v13 > HIDWORD(pParty_global->qword_00002C)
            || v13 >= HIDWORD(pParty_global->qword_00002C) && pParty_global->array_00003C[2 * v15] >= (_DWORD)pParty_global->qword_00002C )
          {
            v17 = 0;
          }
          else
          {
            v18 = 2 * v15;
            v17 = 0;
            *(__int16 *)((char *)word_ACD712 + v18) = 0;
            *(_QWORD *)v14 = (signed __int64)((double)(309657600
                                                     * ((unsigned int)pParty_global->uCurrentMonth
                                                      + 12i64 * (unsigned int)pParty_global->uCurrentYear
                                                      - 14015))
                                            * 0.03333333507180214);
            v19 = rand() % 258;
            v20 = dword_507BC0;
            *(__int16 *)((char *)word_ACD708 + v18) = v19 + 1;
            v16 = *(_DWORD *)(v20 + 28) - 102;
            if ( v16 )
            {
              v21 = v16 - 1;
              if ( v21 )
              {
                v22 = v21 - 1;
                if ( v22 )
                {
                  v23 = v22 - 1;
                  if ( v23 )
                  {
                    if ( v23 == 1 )
                    {
                      while ( 1 )
                      {
                        v24 = *(__int16 *)((char *)word_ACD708 + v18);
                        if ( v24 < 0x73u || v24 > 0x84u )
                        {
                          if ( (v24 < 0xE8u || v24 > 0xF9u)
                            && (v24 < 0x85u || v24 > 0x96u)
                            && (v24 < 0x97u || v24 > 0xBAu)
                            && (v24 < 0xBEu || v24 > 0xC0u)
                            && (v24 < 0xC4u || v24 > 0xC6u)
                            && (v24 < 0x2Bu || v24 > 0x2Du)
                            && (v24 < 0x6Du || v24 > 0x6Fu)
                            && (v24 < 0x46u || v24 > 0x48u)
                            && (v24 < 0x100u || v24 > 0x102u)
                            && (v24 < 0xD9u || v24 > 0xDBu)
                            && (v24 < 0xC7u || v24 > 0xC9u)
                            && (v24 < 0xE5u || v24 > 0xE7u)
                            && (v24 < 0xDFu || v24 > 0xE1u)
                            && (v24 < 0x5Bu || v24 > 0x5Du)
                            && (v24 < 0x49u || v24 > 0x4Bu)
                            && (v24 < 0xFDu || v24 > 0xFFu)
                            && (v24 < 0x61u || v24 > 0x63u)
                            && (v24 < 0x10u || v24 > 0x12u) )
                            break;
                        }
                        *(__int16 *)((char *)word_ACD708 + v18) = rand() % 258 + 1;
                      }
                    }
                  }
                  else
                  {
                    while ( 1 )
                    {
                      v25 = *(__int16 *)((char *)word_ACD708 + v18);
                      if ( v25 < 0x73u || v25 > 0x84u )
                      {
                        if ( (v25 < 0xE8u || v25 > 0xF9u)
                          && (v25 < 0x85u || v25 > 0x96u)
                          && (v25 < 0x97u || v25 > 0xBAu)
                          && (v25 < 0xBEu || v25 > 0xC0u)
                          && (v25 < 0xC4u || v25 > 0xC6u)
                          && (v25 < 0x2Bu || v25 > 0x2Du)
                          && (v25 < 0x5Eu || v25 > 0x60u)
                          && (v25 < 0x43u || v25 > 0x45u)
                          && (v25 < 0x4Fu || v25 > 0x51u)
                          && (v25 < 0xC1u || v25 > 0xC3u)
                          && (v25 < 0x13u || v25 > 0x15u)
                          && (v25 < 0xFDu || v25 > 0xFFu)
                          && (v25 < 0x61u || v25 > 0x63u)
                          && (v25 < 0x6Au || v25 > 0x6Cu) )
                          break;
                      }
                      *(__int16 *)((char *)word_ACD708 + v18) = rand() % 258 + 1;
                    }
                  }
                }
                else
                {
                  while ( 1 )
                  {
                    v26 = *(__int16 *)((char *)word_ACD708 + v18);
                    if ( v26 < 0x73u || v26 > 0x84u )
                    {
                      if ( (v26 < 0xE8u || v26 > 0xF9u)
                        && (v26 < 0x85u || v26 > 0x96u)
                        && (v26 < 0x97u || v26 > 0xBAu)
                        && (v26 < 0xBEu || v26 > 0xC0u)
                        && (v26 < 0xC4u || v26 > 0xC6u)
                        && (v26 < 0x2Bu || v26 > 0x2Du)
                        && (v26 < 0x31u || v26 > 0x33u)
                        && (v26 < 0x34u || v26 > 0x36u)
                        && (v26 < 0xFDu || v26 > 0xFFu)
                        && (v26 < 0x61u || v26 > 0x63u)
                        && (v26 < 0x1Cu || v26 > 0x1Eu) )
                        break;
                    }
                    *(__int16 *)((char *)word_ACD708 + v18) = rand() % 258 + 1;
                  }
                }
              }
              else
              {
                while ( 1 )
                {
                  v27 = *(__int16 *)((char *)word_ACD708 + v18);
                  if ( v27 < 0x73u || v27 > 0x84u )
                  {
                    if ( (v27 < 0xE8u || v27 > 0xF9u)
                      && (v27 < 0x85u || v27 > 0x96u)
                      && (v27 < 0x97u || v27 > 0xBAu)
                      && (v27 < 0xBEu || v27 > 0xC0u)
                      && (v27 < 0xC4u || v27 > 0xC6u)
                      && (v27 < 0x2Bu || v27 > 0x2Du)
                      && (v27 < 0x52u || v27 > 0x54u)
                      && (v27 < 4u || v27 > 6u)
                      && (v27 < 0x37u || v27 > 0x39u)
                      && (v27 < 0x3Au || v27 > 0x3Cu)
                      && (v27 < 0x3Du || v27 > 0x3Fu)
                      && (v27 < 0xFDu || v27 > 0xFFu)
                      && (v27 < 0x61u || v27 > 0x63u)
                      && (v27 < 0xCDu || v27 > 0xCFu) )
                      break;
                  }
                  *(__int16 *)((char *)word_ACD708 + v18) = rand() % 258 + 1;
                }
              }
            }
            else
            {
              while ( 1 )
              {
                v28 = *(__int16 *)((char *)word_ACD708 + v18);
                if ( v28 < 0x73u || v28 > 0x84u )
                {
                  if ( (v28 < 0xEBu || v28 > 0xFCu)
                    && (v28 < 0x85u || v28 > 0x96u)
                    && (v28 < 0x97u || v28 > 0xBAu)
                    && (v28 < 0xBEu || v28 > 0xC0u)
                    && (v28 < 0xC4u || v28 > 0xC6u)
                    && (v28 < 0x2Bu || v28 > 0x2Du)
                    && (v28 < 0xCDu || v28 > 0xCFu)
                    && (v28 < 0x5Eu || v28 > 0x60u)
                    && (v28 < 0xFDu || v28 > 0xFFu)
                    && (v28 < 0x6Du || v28 > 0x6Fu)
                    && (v28 < 0x61u || v28 > 0x63u) )
                    break;
                }
                *(__int16 *)((char *)word_ACD708 + v18) = rand() % 258 + 1;
              }
            }
            v15 = v62;
          }
          v30 = 2 * v15;
          v29 = *(__int16 *)((char *)word_ACD708 + v30);
          v31 = *(__int16 *)((char *)word_ACD712 + v30) == v17;
          word_F8B1A0 = *(__int16 *)((char *)word_ACD708 + v30);
          if ( v31 )
          {
            v3 = 0;
            v34 = v29 == v17;
            v33 = dword_722164;
            if ( v34 )
              v33 = dword_722174;
            dword_F8B1A4 = v33;
          }
          else
          {
            if ( v29 != v17 )
            {
              sub_420C05(100 * pMonsterStats->pMonsterInfos[v29].uLevel, 0);

              for (i = 0; i < 4; ++i)
                sub_44A5CB(&pParty_global->pPlayers[i], 12, 86);

              pParty_global->dword_000748 += 100 * pMonsterStats->pMonsterInfos[*(unsigned __int16 *)((char *)word_ACD708 + v30)].uLevel;
              *(__int16 *)((char *)word_ACD708 + v30) = v17;
              *(__int16 *)((char *)word_ACD712 + v30) = v17;
            }
            v3 = 0;
            dword_F8B1A4 = dword_72216C;
          }
          goto LABEL_200;
        }
        if ( v61 == 100 )
        {
          sub_459E5A((int)&dword_69AE00, 1, 10, v11);
          goto LABEL_200;
        }
      }
    }
  }
  if ( v61 > 95 )
  {
LABEL_200:
    switch ( v61 )
    {
      case 96:
        *(_DWORD *)(dword_507BBC + 24) = 1;
        sub_4BCA33();
        sub_4B3703((void *)dword_F8B198);
        break;
      case 101:
        *(_DWORD *)(dword_507BBC + 24) = 1;
        sub_4BCA33();
        sub_4B3A72((void *)dword_F8B198);
        break;
      case 102:
        dword_F8B19C = 102;
        break;
      case 103:
        dword_F8B19C = 103;
        break;
      case 104:
        if ( dword_50CBD0[0] < 40 )
        {
          dword_50CBD0[3 * dword_50CBD0[0] + 1] = 29;
          dword_50CBD0[3 * dword_50CBD0[0] + 2] = v3;
          dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = v3;
        }
        dword_F8B19C = 104;
        break;
    }
    return;
  }
  if ( v61 != 95 && v61 != 2 )
  {
    if ( v61 == 3 )
    {
      dword_F8B19C = 3;
    }
    else
    {
      if ( v61 == 4 )
      {
        dword_F8B19C = 4;
      }
      else
      {
        if ( v61 != 5 )
        {
          if ( v61 > 35 )
          {
            if ( v61 <= 72 )
            {
              v42 = (int)*(&ptr_A750C4 + uActiveCharacter);
              v43 = (signed __int64)(*((float *)&unk_59145C + 13 * *(_DWORD *)(v11 + 28)) * 500.0);
              v41 = v43 * (100 - sub_4911F3(*(&ptr_A750C4 + uActiveCharacter))) / 100;
              if ( v41 < v43 / 3 )
                v41 = v43 / 3;
              if ( *(&byte_4ED94C[37 * *(_BYTE *)(v42 + 185)] + v61) )
              {
                v44 = v42 + 2 * v61 + 192;
                if ( !*(_WORD *)v44 )
                {
                  if ( pParty_global->uNumGold < (unsigned int)v41 )
                  {
                    sub_44C175(pGlobalTXT_LocalizationStrings[155], 2);
                    if ( dword_F8B198 == 30 || dword_F8B198 == 21 )
                      v45 = 4;
                    else
                      v45 = 2;
                    sub_4B1E92(*(_DWORD *)(dword_507BC0 + 28), v45);
                  }
                  else
                  {
                    sub_492BB6(v41);
                    dword_F8B1E4 = 1;
                    *(_WORD *)v44 = 1;
                    sub_4948B1((void *)v42, 78, 0);
                  }
                }
              }
            }
            else
            {
              if ( v61 == 94 )
              {
                *(_DWORD *)(dword_507BBC + 24) = 1;
                sub_4BCA33();
                sub_4B3AD4(dword_F8B198);
              }
            }
          }
          return;
        }
        dword_F8B19C = 5;
      }
    }
    sub_421B2C();
    return;
  }
  v46 = *(_DWORD *)(v11 + 28);
  v47 = pParty_global->array_00008C[2 * v46 + 1];
  if ( v47 <= HIDWORD(pParty_global->qword_00002C) )
  {
    if ( v47 < HIDWORD(pParty_global->qword_00002C) || (unsigned int)pParty_global->array_00008C[2 * v46] < (_DWORD)pParty_global->qword_00002C )
    {
      sub_4B8E3D();
      sub_4B8F94();
      v11 = dword_507BC0;
      v48 = *(_DWORD *)(dword_507BC0 + 28);
      v4 = dword_F8B198;
      v49 = pParty_global->qword_00002C
          + (signed __int64)((double)(11059200 * (signed int)word_591454[26 * *(_DWORD *)(dword_507BC0 + 28)])
                           * 0.03333333507180214);
      pParty_global->array_00008C[2 * v48] = v49;
      pParty_global->array_00008C[2 * v48 + 1] = HIDWORD(v49);
    }
  }
  v50 = *(_DWORD *)(v11 + 28);
  v52 = 0;
  v51 = word_591438[26 * *(_DWORD *)(v11 + 28)];
  if ( v61 == 2 )
  {
    if ( byte_4F063C[v51] )
    {
      do
      {
        v53 = dword_AD4734[9 * (v52 + 12 * v50)];
        if ( v53 )
        {
          v54 = LODFile_LoadTexture(pLODFile_Icons_LOD, pClass40->pItems[v53].pIconName, 2);
          v4 = dword_F8B198;
          v11 = dword_507BC0;
          dword_F8B168[v52] = 72 * v54 + 7145548;
        }
        v50 = *(_DWORD *)(v11 + 28);
        ++v52;
      }
      while ( v52 < (unsigned __int8)byte_4F063C[word_591438[26 * *(_DWORD *)(v11 + 28)]] );
    }
    if ( v4 == 1 )
    {
      v55 = *(_DWORD *)(v11 + 28);
      v56 = 0;
      if ( byte_4F063C[word_591438[26 * *(_DWORD *)(v11 + 28)]] )
      {
        do
        {
          if ( dword_AD4734[9 * (v56 + 12 * v55)] )
          {
            v11 = dword_507BC0;
            word_F8B158[v56] = rand() % (300 - *(_WORD *)(dword_F8B168[v56] + 26));
          }
          v55 = *(_DWORD *)(v11 + 28);
          ++v56;
        }
        while ( v56 < (unsigned __int8)byte_4F063C[word_591438[26 * *(_DWORD *)(v11 + 28)]] );
      }
    }
  }
  else
  {
    if ( byte_4F063C[v51] )
    {
      do
      {
        v57 = *(&dword_ADA0A4 + 9 * (v52 + 12 * v50));
        if ( v57 )
        {
          v58 = LODFile_LoadTexture(pLODFile_Icons_LOD, pClass40->pItems[v57].pIconName, 2);
          v4 = dword_F8B198;
          v11 = dword_507BC0;
          dword_F8B168[v52] = 72 * v58 + 7145548;
        }
        v50 = *(_DWORD *)(v11 + 28);
        ++v52;
      }
      while ( v52 < (unsigned __int8)byte_4F063C[word_591438[26 * *(_DWORD *)(v11 + 28)]] );
    }
    if ( v4 == 1 )
    {
      v59 = *(_DWORD *)(v11 + 28);
      v60 = 0;
      if ( byte_4F063C[word_591438[26 * *(_DWORD *)(v11 + 28)]] )
      {
        do
        {
          if ( *(&dword_ADA0A4 + 9 * (v60 + 12 * v59)) )
          {
            v11 = dword_507BC0;
            word_F8B158[v60] = rand() % (300 - *(_WORD *)(dword_F8B168[v60] + 26));
          }
          v59 = *(_DWORD *)(v11 + 28);
          ++v60;
        }
        while ( v60 < (unsigned __int8)byte_4F063C[word_591438[26 * *(_DWORD *)(v11 + 28)]] );
      }
    }
  }
}

//----- (004BD8B5) --------------------------------------------------------
signed int __cdecl sub_4BD8B5()
{
  int v0; // eax@4
  int v1; // eax@29
  int v2; // esi@30
  const char *v3; // ebx@31

  if ( dword_50CBD0[0] )
    dword_50CBD0[0] = dword_50CBD0[3] != 0;
  sub_459ED1(&dword_69AE00, 3);
  sub_459E3F();
  dword_5C3420 = 0;
  dword_F8B1E8 = 0;
  if ( dword_5913F0 )
  {
    v0 = dword_F8B19C;
    if ( dword_F8B19C != 2 )
    {
      if ( dword_F8B19C != 3 )
      {
        if ( dword_F8B19C != 97 )
        {
          if ( dword_F8B19C != 5 )
          {
            if ( dword_F8B19C != 4 )
            {
              if ( dword_F8B164[0] )
              {
                sub_40F77C(dword_F8B164[0]);
                v0 = dword_F8B19C;
                dword_F8B164[0] = 0;
              }
            }
          }
        }
      }
    }
    if ( v0 && v0 != 1 )
    {
      if ( v0 == -1 )
      {
        sub_4B4224((void *)(dword_5913F0 - 1));
LABEL_33:
        sub_4BF5B2(pVideoPlayer);
        return 1;
      }
      if ( v0 != 94 && v0 != 96 && v0 != 101 )
      {
        if ( v0 == 3 || v0 == 5 || v0 == 4 )
        {
          sub_4BCA33();
          dword_F8B19C = 94;
          sub_4B3AD4(dword_F8B198);
        }
        else
        {
          if ( v0 != 102 && v0 != 103 && v0 != 104 )
          {
            sub_4BF5B2(pVideoPlayer);
LABEL_28:
            dword_F8B19C = 1;
            sub_4B3B42(dword_F8B198);
            return 1;
          }
          sub_4BF5B2(pVideoPlayer);
          sub_4BCA33();
          dword_F8B19C = 101;
          sub_4B3A72((void *)dword_F8B198);
        }
        return 1;
      }
      sub_4BF5B2(pVideoPlayer);
      sub_4BCA33();
      goto LABEL_28;
    }
    dword_5913F0 = 0;
    GUIWindowDelete(dword_507BBC);
    dword_F8B19C = 0;
    dword_507BBC = 0;
    sub_40F9C5(pLODFile_Icons_LOD);
    v1 = dword_591424;
    if ( dword_591424 != 1 )
    {
      v2 = 0;
      dword_5076F4 = *(_DWORD *)(dword_507BC0 + 76);
      if ( dword_591424 > 0 )
      {
        v3 = byte_591180;
        do
        {
          dword_5913F4[v2] = GUIButtonCreate(
                               dword_507BC0,
                               *(&dword_4E5E50 + v2 + 6 * v1 - 6),
                               *(&dword_4E5EE0 + v2 + 6 * v1 - 6),
                               63,
                               73,
                               1,
                               0,
                               410,
                               v2,
                               0,
                               v3,
                               0);
          v1 = dword_591424;
          ++v2;
          v3 += 100;
        }
        while ( v2 < dword_591424 );
      }
      goto LABEL_33;
    }
  }
  return 0;
}

//----- (004BDAAF) --------------------------------------------------------
bool __fastcall sub_4BDAAF(int a1, int a2)
{
  int v2; // eax@1
  int v3; // edx@1
  signed int v4; // edi@1
  signed int v5; // esi@1
  int v6; // edx@8
  int v7; // edx@9
  int v8; // edx@10
  unsigned __int8 v9; // zf@16
  char v10; // sf@16
  unsigned __int8 v11; // of@16

  v3 = word_591438[26 * a2];
  v5 = *(_DWORD *)a1;
  v2 = 48 * *(_DWORD *)a1;
  v4 = (unsigned __int8)byte_5D2A00[v2];
  if ( (v3 != 4 || v5 < 740 || v5 > 771) && (v5 >= 600 || v5 >= 529 && v5 <= 599) || *(_BYTE *)(a1 + 21) & 1 )
    return 0;
  v6 = v3 - 1;
  if ( !v6 )
  {
    compile_error;//v11 = __SETO__(v4, 2);
    v9 = v4 == 2;
    v10 = v4 - 2 < 0;
    goto LABEL_23;
  }
  v7 = v6 - 1;
  if ( v7 )
  {
    v8 = v7 - 1;
    if ( !v8 )
    {
      if ( byte_5D2A00[v2 + 1] != 38 )
        return v4 == 16;
      return 1;
    }
    if ( v8 != 1 || v4 < 13 )
      return 0;
    if ( v4 <= 14 )
      return 1;
    if ( v4 != 17 || v5 < 740 )
      return 0;
    compile_error;//v11 = __SETO__(v5, 771);
    v9 = v5 == 771;
    v10 = v5 - 771 < 0;
LABEL_23:
    if ( !((unsigned __int8)(v10 ^ v11) | v9) )
      return 0;
    return 1;
  }
  if ( v4 >= 3 )
  {
    compile_error;//v11 = __SETO__(v4, 9);
    v9 = v4 == 9;
    v10 = v4 - 9 < 0;
    goto LABEL_23;
  }
  return 0;
}

//----- (004BDB56) --------------------------------------------------------
void __cdecl sub_4BDB56()
{
  int v0; // edi@1
  signed int v1; // esi@9
  int v2; // eax@11
  int v3; // esi@12
  float v4; // ST1C_4@12
  int v5; // eax@12
  signed int v6; // eax@12
  char v7; // zf@12
  int v8; // ecx@15
  int v9; // eax@15
  signed int v10; // esi@18
  int v11; // esi@20
  int v12; // esi@21
  int v13; // ecx@26
  signed int v14; // esi@31
  int v15; // eax@33
  int v16; // esi@34
  int v17; // ecx@37
  int v18; // esi@37
  int v19; // esi@38
  int v20; // eax@38
  float v21; // ST1C_4@38
  int v22; // eax@38
  int v23; // ebx@38
  int v24; // edx@39
  int v25; // eax@40
  signed int v26; // ebx@41
  void *v27; // ecx@43
  int v28; // ecx@49
  int v29; // esi@49
  int v30; // eax@50
  int v31; // ecx@50
  int v32; // esi@51
  signed int v33; // eax@53
  float v34; // ST1C_4@53
  int v35; // eax@53
  int v36; // eax@53
  bool v37; // eax@53
  int v38; // eax@55
  int v39; // eax@63
  int v40; // eax@64
  char v41; // zf@64
  int v42; // edx@66
  int v43; // ecx@74
  signed int v44; // ebx@74
  int v45; // esi@74
  int v46; // esi@77
  signed int v47; // [sp-18h] [bp-CCh]@36
  int v48; // [sp-14h] [bp-C8h]@36
  signed int v49; // [sp-10h] [bp-C4h]@36
  int v50; // [sp-Ch] [bp-C0h]@36
  int v51; // [sp-8h] [bp-BCh]@36
  int v52; // [sp-4h] [bp-B8h]@28
  int v53; // [sp-4h] [bp-B8h]@36
  int v54; // [sp+0h] [bp-B4h]@16
  int v55; // [sp+0h] [bp-B4h]@25
  int v56; // [sp+0h] [bp-B4h]@26
  int v57; // [sp+0h] [bp-B4h]@36
  char v58; // [sp+10h] [bp-A4h]@49
  char v59; // [sp+18h] [bp-9Ch]@18
  char v60; // [sp+20h] [bp-94h]@49
  char v61; // [sp+28h] [bp-8Ch]@9
  char v62; // [sp+30h] [bp-84h]@37
  char v63; // [sp+38h] [bp-7Ch]@18
  char v64; // [sp+40h] [bp-74h]@37
  char v65; // [sp+48h] [bp-6Ch]@19
  char v66; // [sp+50h] [bp-64h]@32
  char v67; // [sp+58h] [bp-5Ch]@18
  char v68; // [sp+60h] [bp-54h]@31
  char v69; // [sp+68h] [bp-4Ch]@9
  char v70; // [sp+70h] [bp-44h]@31
  char v71; // [sp+78h] [bp-3Ch]@9
  char v72; // [sp+80h] [bp-34h]@31
  char v73; // [sp+88h] [bp-2Ch]@10
  bool v74; // [sp+90h] [bp-24h]@53
  int v75; // [sp+94h] [bp-20h]@53
  int v76; // [sp+98h] [bp-1Ch]@57
  int v77; // [sp+9Ch] [bp-18h]@53
  int v78; // [sp+A0h] [bp-14h]@1
  bool v79; // [sp+A4h] [bp-10h]@53
  int v80; // [sp+A8h] [bp-Ch]@9
  int v81; // [sp+ACh] [bp-8h]@12
  int v82; // [sp+B0h] [bp-4h]@13

  v0 = (int)*(&ptr_A750C4 + uActiveCharacter);
  v78 = (int)*(&ptr_A750C4 + uActiveCharacter);
  if ( dword_4E28F8 == 14 )
    goto LABEL_73;
  if ( !sub_4B1784() )
  {
    v57 = 0;
    v53 = 0;
    v51 = 0;
    v50 = 0;
    v49 = -1;
    v48 = 0;
    v47 = 0;
    goto LABEL_87;
  }
  if ( dword_F8B19C > 18 )
  {
    if ( dword_F8B19C < 36 )
      return;
    if ( dword_F8B19C <= 72 )
    {
      v45 = dword_F8B19C - 36;
      v44 = (signed __int64)(*((float *)&unk_59145C + 13 * *(_DWORD *)(dword_507BC0 + 28)) * 500.0);
      v43 = v44 * (100 - sub_4911F3((void *)v0)) / 100;
      if ( v43 < v44 / 3 )
        v43 = v44 / 3;
      if ( *(&byte_4ED970[37 * *(_BYTE *)(v0 + 185)] + v45) )
      {
        v46 = v0 + 2 * v45 + 264;
        if ( !*(_WORD *)v46 )
        {
          if ( pParty_global->uNumGold < (unsigned int)v43 )
          {
            sub_44C175(pGlobalTXT_LocalizationStrings[155], 2);
            v13 = *(_DWORD *)(dword_507BC0 + 28);
            if ( dword_F8B198 == 30 )
              v56 = 4;
            else
              v56 = 2;
            goto LABEL_84;
          }
          sub_492BB6(v43);
          v54 = 0;
          dword_F8B1E4 = 1;
          *(_WORD *)v46 = 1;
          v52 = 78;
          goto LABEL_80;
        }
      }
      return;
    }
    if ( dword_F8B19C != 94 )
    {
      if ( dword_F8B19C != 95 )
        return;
      goto LABEL_49;
    }
    dword_506F48 = 103;
LABEL_73:
    sub_421EA6();
    return;
  }
  if ( dword_F8B19C == 18 )
  {
    v18 = class03_GetMousePos(pGame->pClass03, (int)&v64);
    v17 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer
                    + 4 * (*(_DWORD *)v18 + dword_5059A8[*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v62) + 4)])) & 0xFFFF;
    if ( !v17 )
      return;
    v20 = *(_DWORD *)(dword_507BC0 + 28);
    v19 = 36 * (v17 + 12 * v20) + 11341664;
    v21 = *((float *)&unk_591458 + 13 * v20);
    v82 = v19;
    v22 = sub_456442(v19);
    v23 = sub_4B8142((void *)v0, v22, v21);
    v81 = v23;
    GetAsyncKeyState(17);
    if ( pParty_global->uNumGold < (unsigned int)v23 )
    {
      v24 = 2;
LABEL_62:
      sub_4B1E92(*(_DWORD *)(dword_507BC0 + 28), v24);
      v8 = pGlobalTXT_LocalizationStrings[155];
      v55 = 2;
      goto LABEL_71;
    }
    v25 = CreateItemInInventory((void *)v0, -1, *(_DWORD *)v19);
    if ( v25 )
    {
      v26 = 1;
      *(_DWORD *)(v19 + 20) |= 1u;
      memcpy((void *)(v0 + 36 * v25 + 496), (const void *)v19, 0x24u);
      goto LABEL_42;
    }
    sub_4948B1((void *)v0, 15, 0);
    v55 = 5;
LABEL_70:
    v8 = pGlobalTXT_LocalizationStrings[563];
    goto LABEL_71;
  }
  if ( dword_F8B19C == 2 )
  {
LABEL_49:
    v29 = class03_GetMousePos(pGame->pClass03, (int)&v60);
    v28 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer
                    + 4 * (*(_DWORD *)v29 + dword_5059A8[*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v58) + 4)])) & 0xFFFF;
    if ( !v28 )
      return;
    v30 = *(_DWORD *)(dword_507BC0 + 28);
    v31 = 9 * (v28 - 1 + 12 * v30);
    if ( dword_F8B19C == 2 )
    {
      v32 = 4 * v31 + 11355956;
      v82 = 4 * v31 + 11355956;
    }
    else
    {
      v82 = 4 * v31 + 11378852;
      v32 = 4 * v31 + 11378852;
    }
    v34 = *((float *)&unk_591458 + 13 * v30);
    v35 = sub_456442(v32);
    v81 = sub_4B8142((void *)v0, v35, v34);
    LOWORD(v36) = GetAsyncKeyState(17);
    v75 = v36;
    v37 = sub_492C40((void *)v0);
    v79 = 0;
    v77 = 0;
    v74 = v37;
    v33 = CMapStats_FindLocation(pMapStats, Str1);
    if ( v33 )
      v77 = pMapStats->pMapInfos[v33].dword_000024;
    v38 = sub_47752B();
    v26 = 1;
    if ( v74 == 1 )
    {
      if ( (_WORD)v75 )
      {
        v79 = sub_48D76C(v0, v32, v77, v38, 0, (int)&v76);
        if ( !v79 )
        {
          sub_4B1447(*(_DWORD *)(dword_507BC0 + 28), 0, v76);
          return;
        }
      }
    }
    if ( pParty_global->uNumGold < (unsigned int)v81 )
    {
      v24 = 2;
      if ( v79 != 2 )
      {
        if ( v79 != 1 )
          goto LABEL_62;
      }
    }
    v39 = CreateItemInInventory((void *)v0, -1, *(_DWORD *)v32);
    if ( v39 )
    {
      *(_DWORD *)(v32 + 20) |= 1u;
      v41 = v74 == 1;
      v40 = v0 + 36 * v39;
      memcpy((void *)(v40 + 496), (const void *)v32, 0x24u);
      if ( v41 )
      {
        if ( (_WORD)v75 )
        {
          v42 = v79;
          if ( v79 == 1 || v79 == 2 )
          {
            *(_BYTE *)(v40 + 517) |= 1u;
            sub_4B1447(*(_DWORD *)(dword_507BC0 + 28), v42, v76);
            goto LABEL_43;
          }
        }
      }
LABEL_42:
      dword_F8B1E4 = v26;
      sub_492BB6(v81);
LABEL_43:
      struct_576FE8.dword_000044 = v26;
      ItemGen_Reset(v82);
      Render_ClearZBuffer(pD3DRenderer, 0, 479);
      v27 = (void *)v78;
      v54 = 0;
      v52 = 75;
LABEL_81:
      sub_4948B1(v27, v52, v54);
      return;
    }
    sub_4948B1((void *)v0, 15, 0);
    v55 = 2;
    goto LABEL_70;
  }
  if ( dword_F8B19C == 3 )
  {
    v14 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v72) - 14;
    v80 = (v14 >> 5) + 14 * ((*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v70) + 4) - 17) >> 5);
    if ( *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v68) <= 13
      || *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v66) >= 462
      || (v15 = sub_421E75((void *)v0, (int)&v80), v78 = v15, !v15) )
      return;
    v16 = dword_507BC0;
    if ( sub_4BDAAF(v0 + 36 * v15 + 496, *(_DWORD *)(dword_507BC0 + 28)) )
    {
      dword_F8B1E4 = 1;
      sub_4BE2DD((void *)v0, v80, v78 - 1, *(_DWORD *)(v16 + 28));
      struct_576FE8.dword_000044 = 1;
      Render_ClearZBuffer(pD3DRenderer, 0, 479);
      v54 = 0;
      v52 = 77;
      goto LABEL_80;
    }
    sub_4948B1((void *)v0, 79, 0);
    v57 = 0;
    v53 = 0;
    v51 = 0;
    v50 = 0;
    v49 = -1;
    v48 = 0;
    v47 = 0;
LABEL_87:
    AudioPlayer_sub_4AA306(pAudioPlayer, 27, v47, v48, v49, v50, v51, v53, v57);
    return;
  }
  if ( dword_F8B19C == 4 )
  {
    v10 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v63) - 14;
    v80 = (v10 >> 5) + 14 * ((*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v67) + 4) - 17) >> 5);
    if ( *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v59) > 13 )
    {
      if ( *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v65) < 462 )
      {
        v11 = sub_421E75((void *)v0, (int)&v80);
        if ( v11 )
        {
          v81 = sub_4B8179((void *)v0, *((float *)&unk_591458 + 13 * *(_DWORD *)(dword_507BC0 + 28)));
          v12 = v0 + 36 * v11 + 496;
          if ( !(*(_BYTE *)(v12 + 20) & 1) )
          {
            v82 = *(_DWORD *)(dword_507BC0 + 28);
            if ( sub_4BDAAF(v12, v82) )
            {
              if ( pParty_global->uNumGold >= (unsigned int)v81 )
              {
                dword_F8B1E4 = 1;
                sub_492BB6(v81);
                *(_DWORD *)(v12 + 20) |= 1u;
                sub_4948B1((void *)v0, 73, 0);
                v8 = pGlobalTXT_LocalizationStrings[569];
                goto LABEL_25;
              }
              goto LABEL_26;
            }
            AudioPlayer_sub_4AA306(pAudioPlayer, 27, 0, 0, -1, 0, 0, 0, 0);
            v54 = 0;
            goto LABEL_28;
          }
          v54 = 0;
LABEL_30:
          v52 = 76;
          goto LABEL_80;
        }
      }
    }
  }
  else
  {
    if ( dword_F8B19C == 5 )
    {
      v1 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v69) - 14;
      v80 = (v1 >> 5) + 14 * ((*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (int)&v71) + 4) - 17) >> 5);
      if ( *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v61) > 13 )
      {
        if ( *(_DWORD *)class03_GetMousePos(pGame->pClass03, (int)&v73) < 462 )
        {
          v2 = sub_421E75((void *)v0, (int)&v80);
          if ( v2 )
          {
            v3 = v0 + 36 * v2 + 496;
            v4 = *((float *)&unk_591458 + 13 * *(_DWORD *)(dword_507BC0 + 28));
            v5 = sub_456442(v0 + 36 * v2 + 496);
            v6 = sub_4B81C3((void *)v0, v5, v4);
            v7 = (*(_BYTE *)(v3 + 20) & 2) == 0;
            v81 = v6;
            if ( !v7 )
            {
              v82 = *(_DWORD *)(dword_507BC0 + 28);
              if ( sub_4BDAAF(v3, v82) )
              {
                if ( pParty_global->uNumGold >= (unsigned int)v81 )
                {
                  dword_F8B1E4 = 1;
                  sub_492BB6(v81);
                  v9 = *(_DWORD *)(v3 + 20);
                  LOBYTE(v9) = v9 & 0xFD;
                  *(_DWORD *)(v3 + 20) = v9 | 1;
                  sub_4948B1((void *)v0, 74, 0);
                  v8 = pGlobalTXT_LocalizationStrings[570];
LABEL_25:
                  v55 = 2;
LABEL_71:
                  sub_44C175((const char *)v8, v55);
                  return;
                }
LABEL_26:
                v13 = v82;
                v56 = 2;
LABEL_84:
                sub_4B1E92(v13, v56);
                return;
              }
              AudioPlayer_sub_4AA306(pAudioPlayer, 27, 0, 0, -1, 0, 0, 0, 0);
              v54 = 0;
LABEL_28:
              v52 = 79;
LABEL_80:
              v27 = (void *)v0;
              goto LABEL_81;
            }
            v54 = 0;
            goto LABEL_30;
          }
        }
      }
    }
  }
}

//----- (004BE2DD) --------------------------------------------------------
void __thiscall sub_4BE2DD(void *this, int a2, int a3, int a4)
{
  signed int v4; // ebx@1
  void *v5; // edi@1
  int v6; // esi@1
  float v7; // ST04_4@1
  int v8; // eax@1

  v5 = this;
  v6 = (int)((char *)this + 36 * a3);
  v7 = *((float *)&unk_591458 + 13 * a4);
  v8 = sub_456442(v6 + 532);
  v4 = sub_4B8102(v5, v8, v7);
  if ( *(_BYTE *)(v6 + 552) & 2 )
    v4 = 1;
  if ( v4 < 1 )
    v4 = 1;
  sub_492A36(v5, a2);
  sub_492B70((void *)(pParty_global->uNumGold + v4));
}

//----- (004BE386) --------------------------------------------------------
FILE *__thiscall sub_4BE386(void *this)
{
  FILE *result; // eax@1
  void *v2; // edi@1
  FILE *v3; // esi@1

  v2 = this;
  result = fopen("errorlog.txt", "a");
  v3 = result;
  if ( result )
  {
    fprintf(result, "%s\n", v2);
    fclose(v3);
    result = (FILE *)fflush(v3);
  }
  return result;
}

//----- (004BE485) --------------------------------------------------------
void *__thiscall sub_4BE485(void *this, void *a2)
{
  unsigned int v2; // eax@3
  signed int v3; // edx@3
  signed int v4; // edi@3
  char v5; // cl@4
  void *result; // eax@24
  int v7; // [sp+Ch] [bp-4h]@3

  dword_F8B5E8 = 0;
  if ( this && *(_BYTE *)this )
  {
    v2 = (unsigned int)&unk_F8B1F8;
    v4 = 0;
    v7 = (char *)this - &unk_F8B1F8;
    v3 = 1;
    while ( 1 )
    {
      v5 = *(_BYTE *)(v7 + v2);
      *(_BYTE *)v2 = v5;
      if ( !v5 )
      {
LABEL_23:
        *(_BYTE *)v2 = 0;
        break;
      }
      if ( v5 == 44 )
      {
        if ( v4 )
          goto LABEL_18;
        *(_BYTE *)v2 = 0;
      }
      else
      {
        if ( v5 != 9 )
        {
          if ( v5 == 34 )
          {
            *(_BYTE *)v2 = 0;
            v3 = 1;
            if ( v4 )
            {
              v4 = 0;
            }
            else
            {
              v4 = 1;
              if ( *(_BYTE *)(v7 + v2 + 1) == 34 )
                dword_F8B5EC[dword_F8B5E8++] = v2;
            }
            goto LABEL_21;
          }
LABEL_18:
          if ( v3 )
            dword_F8B5EC[dword_F8B5E8++] = v2;
          v3 = 0;
          goto LABEL_21;
        }
        if ( v4 )
          goto LABEL_18;
        *(_BYTE *)v2 = 0;
        if ( v3 )
          dword_F8B5EC[dword_F8B5E8++] = v2;
      }
      v3 = 1;
LABEL_21:
      if ( dword_F8B5E8 < 30 )
      {
        ++v2;
        if ( v2 < (unsigned int)&unk_F8B5E0 )
          continue;
      }
      goto LABEL_23;
    }
  }
  result = a2;
  memcpy(a2, &dword_F8B5E8, 0x7Cu);
  return result;
}

//----- (004BE571) --------------------------------------------------------
int __fastcall sub_4BE571(int a1, int a2, int a3, int a4)
{
  int result; // eax@1
  int i; // esi@3

  result = a3;
  if ( a3 < a4 )
  {
    for ( i = 0; i < a3; ++i )
    {
      if ( a1 == *(_DWORD *)(a2 + 4 * i) )
        break;
    }
    if ( i == a3 )
    {
      *(_DWORD *)(a2 + 4 * a3) = a1;
      result = a3 + 1;
    }
  }
  else
  {
    result = a4;
  }
  return result;
}

//----- (004BE59E) --------------------------------------------------------
int __thiscall sub_4BE59E(int this, int a2, int a3)
{
  int result; // eax@1

  result = a2;
  *(_DWORD *)(this + 40) = a2;
  *(_DWORD *)(this + 44) = a3 - a2;
  return result;
}

//----- (004BE5B1) --------------------------------------------------------
double __fastcall sub_4BE5B1(int a1)
{
  int v2; // esi@1
  double v3; // st7@1
  double v4; // st7@1

  v2 = a1;
  *(double *)(a1 + 24) = *(double *)(a1 + 16);
  *(double *)(a1 + 16) = *(double *)(a1 + 8);
  v3 = *(double *)a1;
  *(_QWORD *)(a1 + 8) = *(_QWORD *)&v3;
  v4 = *(double *)(a1 + 24) * *(double *)&byte_4D8410[1496]
     + *(double *)(a1 + 16) * *(double *)&byte_4D8410[1488]
     + *(double *)(a1 + 24) * *(double *)&byte_4D8410[1480]
     + v3 * *(double *)&byte_4D8410[1472]
     + *(double *)(a1 + 32);
  floor(v4);
  *(double *)v2 = v4 - v4;
  *(double *)(v2 + 32) = v4 * *(double *)&byte_4D8410[1464];
  return v4 - v4;
}

//----- (004BE623) --------------------------------------------------------
int __thiscall sub_4BE623(int this)
{
  int v1; // ecx@1
  int v2; // esi@1
  float v3; // ST10_4@1
  double v4; // ST04_8@1

  v2 = this;
  v3 = sub_4BE5B1(this) * (double)*(signed int *)(this + 44);
  v4 = v3 + 6.755399441055744e15;
  v1 = LODWORD(v4);
  if ( LODWORD(v4) >= *(_DWORD *)(v2 + 44) )
    v1 = *(_DWORD *)(v2 + 44);
  return v1 + *(_DWORD *)(v2 + 40);
}

//----- (004BE65D) --------------------------------------------------------
void __thiscall sub_4BE65D(void *this, int a2)
{
  int v2; // eax@1
  int v3; // esi@1
  signed int v4; // ecx@3
  unsigned int v5; // eax@4
  signed int v6; // edi@5

  v2 = a2;
  v3 = (int)this;
  if ( !a2 )
    v2 = -1;
  v4 = 0;
  do
  {
    v5 = (((v2 << 13) ^ (unsigned int)v2) >> 17) ^ (v2 << 13) ^ v2;
    v2 = 32 * v5 ^ v5;
    *(double *)(v3 + 8 * v4++) = (double)(unsigned int)v2 * *(double *)&byte_4D8410[1464];
  }
  while ( v4 < 5 );
  v6 = 19;
  do
  {
    sub_4BE5B1(v3);
    --v6;
  }
  while ( v6 );
}

//----- (004BE6D1) --------------------------------------------------------
void *__thiscall sub_4BE6D1(void *this)
{
  return this;
}

//----- (004BECBD) --------------------------------------------------------
function_error;//int __usercall sub_4BECBD<eax>(int a1<eax>, int a2<ecx>)
int sub_4BECBD(int a1, int a2)
{
  pVideoPlayer->dword_00006C = 0;
  pVideoPlayer->dword_000040 = 0;
  return RGBTexture_Release(pVideoPlayer);
}

//----- (004BECD5) --------------------------------------------------------
void __thiscall sub_4BECD5(int this, unsigned int a2)
{
  int v2; // eax@1
  int v3; // esi@1

  v3 = this;
  v2 = *(_DWORD *)(this + 156);
  if ( v2 == 2 )
  {
    if ( a2 )
    {
      while ( *(_DWORD *)(*(_DWORD *)(v3 + 128) + 20) < a2 )
      {
        BinkDoFrame(*(_DWORD *)(v3 + 128));
        BinkNextFrame(*(_DWORD *)(v3 + 128));
      }
    }
  }
  else
  {
    if ( v2 != 1 )
      return;
    SmackSoundOnOff(*(_DWORD *)(this + 40), 0);
    if ( a2 )
    {
      while ( *(_DWORD *)(*(_DWORD *)(v3 + 40) + 884) < a2 )
      {
        SmackDoFrame(*(_DWORD *)(v3 + 40));
        SmackNextFrame(*(_DWORD *)(v3 + 40));
      }
    }
  }
  CVideoPlayer_UnloadAll(v3);
}

//----- (004BF08B) --------------------------------------------------------
void *__thiscall sub_4BF08B(void *this, int a2)
{
  int v2; // eax@1
  int v3; // esi@1
  int v4; // ebx@1
  int v5; // edi@1
  signed int v6; // eax@1

  v3 = (int)this;
  Render_BeginScene(pD3DRenderer);
  v4 = pD3DRenderer->pTargetSurface;
  v5 = pD3DRenderer->uTargetSurfacePitch;
  v6 = VideoPlayer_Smacker_CheckSurfaceFromat();
  SmackToBuffer(*(_DWORD *)(v3 + 40), 8, 8, 2 * v5, pD3DRenderer->dword_000014, v4, v6);
  v2 = *(_DWORD *)(v3 + 40);
  if ( *(_DWORD *)(v2 + 104) )
  {
    SmackBufferNewPalette(*(_DWORD *)(v3 + 44), v2 + 108, *(_WORD *)(v2 + 880));
    SmackColorRemapWithTrans(
      *(_DWORD *)(v3 + 40),
      *(_DWORD *)(v3 + 44) + 60,
      *(_DWORD *)(*(_DWORD *)(v3 + 44) + 44),
      *(_DWORD *)(*(_DWORD *)(v3 + 44) + 1084),
      1000);
  }
  SmackDoFrame(*(_DWORD *)(v3 + 40));
  if ( *(_DWORD *)(*(_DWORD *)(v3 + 40) + 884) != *(_DWORD *)(*(_DWORD *)(v3 + 40) + 12) - 1 || *(_DWORD *)(v3 + 100) )
    SmackNextFrame(*(_DWORD *)(v3 + 40));
  else
    CVideoPlayer_UnloadAll(v3);
  return Render_EndScene(pD3DRenderer);
}

//----- (004BF28F) --------------------------------------------------------
void __thiscall sub_4BF28F(int this, char a2, int a3)
{
  int v3; // esi@1
  void *v4; // ecx@3
  int v5; // eax@4
  int v6; // ecx@7
  int v7; // eax@7
  int v8; // eax@7
  int v9; // ebx@8
  signed int v10; // eax@8
  signed __int64 v11; // qax@9
  const char *v12; // [sp-20h] [bp-54h]@3
  int v13; // [sp-1Ch] [bp-50h]@3
  char v14; // [sp-18h] [bp-4Ch]@3
  int v15; // [sp-14h] [bp-48h]@6
  int v16; // [sp-10h] [bp-44h]@6
  int v17; // [sp-Ch] [bp-40h]@6
  const char *v18; // [sp-8h] [bp-3Ch]@3
  int v19; // [sp-4h] [bp-38h]@3
  char Str2; // [sp+Ch] [bp-28h]@4
  char *v21; // [sp+3Ch] [bp+8h]@3
  char *v22; // [sp+3Ch] [bp+8h]@5
  int v23; // [sp+3Ch] [bp+8h]@8

  v3 = this;
  if ( !*(_DWORD *)(this + 84) )
  {
    CVideoPlayer_Initialize(this);
    *(_DWORD *)(v3 + 100) = a3;
    if ( *(_BYTE *)(v3 + 260) == 1 )
    {
      v19 = 925;
      v18 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Video.cpp";
      v4 = &v14;
      v21 = &v14;
      v13 = (int)(&a2 + 3);
      v12 = "Unsupported Bink playback!";
LABEL_6:
      sub_40E2C8(v4, v12, v13);
      sub_466D09(&a3, *(int *)&v14, v15, v16, v17, v18, v19);
      return;
    }
    sprintfex(&Str2, "%s.smk", a2);
    v5 = CVideoPlayer_OpenSmackMovie(v3, &Str2);
    *(_DWORD *)(v3 + 40) = v5;
    if ( !v5 )
    {
      CVideoPlayer_UnloadAll(v3);
      sprintfex(&TmpBuf, "Can't load %s", &Str2);
      v19 = 937;
      v18 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Video.cpp";
      v4 = &v14;
      v22 = &v14;
      v13 = (int)(&a2 + 3);
      v12 = &TmpBuf;
      goto LABEL_6;
    }
    v19 = a2;
    *(_DWORD *)(v3 + 156) = 1;
    strcpy((char *)(v3 + 164), (const char *)v19);
    v7 = *(_DWORD *)(v3 + 40);
    *(_DWORD *)(v3 + 160) = 1;
    v8 = SmackBufferOpen(
           *(_DWORD *)(v3 + 112),
           4,
           *(_WORD *)(v7 + 4),
           *(_WORD *)(v7 + 8),
           *(_WORD *)(v7 + 4),
           *(_WORD *)(v7 + 8));
    *(_DWORD *)(v3 + 44) = v8;
    if ( v8 )
    {
      Render_BeginScene(pD3DRenderer);
      v9 = pD3DRenderer->uTargetSurfacePitch;
      v23 = pD3DRenderer->pTargetSurface;
      v10 = VideoPlayer_Smacker_CheckSurfaceFromat();
      SmackToBuffer(*(_DWORD *)(v3 + 40), 8, 8, 2 * v9, pD3DRenderer->dword_000014, v23, v10);
      Render_EndScene(pD3DRenderer);
    }
    v19 = 32767;
    v11 = (signed __int64)(aMusicVolumeLevels[byte_6BE36F] * 32767.0);
    SmackVolumePan(v6, HIDWORD(v11), *(_DWORD *)(v3 + 40), 1040384, v11, 32767);
  }
}

//----- (004BF5B2) --------------------------------------------------------
int __thiscall sub_4BF5B2(int this)
{
  int result; // eax@1
  int v2; // esi@1
  int v3; // edi@2

  v2 = this;
  result = *(_DWORD *)(this + 156);
  if ( result == 2 )
  {
    v3 = this + 128;
    BinkGoto(*(_DWORD *)(this + 128), 1, 0);
    BinkDoFrame(*(_DWORD *)v3);
    BinkNextFrame(*(_DWORD *)v3);
  }
  else
  {
    if ( result != 1 )
      return result;
    SmackGoto(*(_DWORD *)(this + 40), 1);
    if ( dword_F79D7C != 2 || dword_F79D70 != 4 )
    {
      SmackDoFrame(*(_DWORD *)(v2 + 40));
      SmackNextFrame(*(_DWORD *)(v2 + 40));
    }
  }
  sub_469E24(pGame->pClass03);
  result = dword_507BC0;
  if ( dword_507BC0 )
  {
    if ( *(_DWORD *)(dword_507BC0 + 28) == 165 )
    {
      if ( !*(_DWORD *)(v2 + 40) )
      {
        dword_F8BC10 = 1;
        sub_4BD8B5();
        GUIWindowDelete(dword_507BC0);
        pParty_global->dword_007778 &= 0xFFFFFFFDu;
        result = sub_44622E(165);
        if ( result )
        {
          AudioPlayer_sub_4AA306(pAudioPlayer, 0, 0, 0, -1, 0, 0, 0, 0);
          dword_507BC0 = GUIWindowCreate(0, 0, 640, 480, 25, 165, 0);
          GUIButtonCreate(dword_507BC0, 61, 424, 31, 0, 2, 94, 110, 1, 49, Class, 0);
          GUIButtonCreate(dword_507BC0, 177, 424, 31, 0, 2, 94, 110, 2, 50, Class, 0);
          GUIButtonCreate(dword_507BC0, 292, 424, 31, 0, 2, 94, 110, 3, 51, Class, 0);
          result = GUIButtonCreate(dword_507BC0, 407, 424, 31, 0, 2, 94, 110, 4, 52, Class, 0);
        }
        dword_F8BC10 = 0;
      }
    }
  }
  return result;
}

//----- (004BF73A) --------------------------------------------------------
void __thiscall sub_4BF73A(int this)
{
  unsigned __int8 v1; // bl@1
  int v2; // edi@1
  int v3; // esi@1
  int v4; // edi@1
  char Source; // [sp+Ch] [bp-40h]@1

  v3 = this;
  v4 = *(_DWORD *)(this + 160);
  v1 = *(_BYTE *)(this + 100);
  strcpy(&Source, (const char *)(this + 164));
  CVideoPlayer_UnloadAll(v3);
  v2 = v4 - 1;
  if ( v2 )
  {
    if ( v2 == 1 )
      CVideoPlayer_OpenMovie(v3, &Source, v1, 1);
  }
  else
  {
    sub_4BF28F(v3, (unsigned int)&Source, v1);
  }
}

//----- (004BF8F6) --------------------------------------------------------
void PlayFirstActMovie()
{
  pVideoPlayer->dword_00006C = 0;
  pVideoPlayer->dword_000040 = 0;
  PlayMovie(4, 1);
}

//----- (004BF91E) --------------------------------------------------------
int __thiscall sub_4BF91E_GameOverMenu(void *this)
{
  int v1; // eax@1
  int v2; // eax@2
  int result; // eax@3
  int v4; // eax@7
  char *v5; // ST24_4@9
  int v6; // eax@9
  unsigned int v7; // ecx@9
  unsigned __int8 v8; // cf@9
  unsigned __int8 v9; // sf@9
  unsigned __int8 v10; // of@9
  int v11; // edx@10
  char *v12; // eax@10
  int v13; // ecx@12
  int v14; // eax@14
  BOOL v15; // eax@25
  char v16; // [sp+Ch] [bp-C4h]@1
  unsigned int v17; // [sp+30h] [bp-A0h]@1
  int v18; // [sp+34h] [bp-9Ch]@1
  int v19; // [sp+38h] [bp-98h]@1
  int v20; // [sp+3Ch] [bp-94h]@1
  int v21; // [sp+40h] [bp-90h]@1
  int v22; // [sp+44h] [bp-8Ch]@1
  int v23; // [sp+48h] [bp-88h]@1
  MSG Msg; // [sp+88h] [bp-48h]@22
  unsigned int v25; // [sp+A4h] [bp-2Ch]@5
  void *v26; // [sp+A8h] [bp-28h]@1
  const char *v27; // [sp+ACh] [bp-24h]@5
  unsigned int v28; // [sp+B0h] [bp-20h]@5
  unsigned int v29; // [sp+B4h] [bp-1Ch]@5
  unsigned int v30; // [sp+B8h] [bp-18h]@5
  int v31; // [sp+BCh] [bp-14h]@7
  int i; // [sp+C0h] [bp-10h]@7
  int v33; // [sp+C4h] [bp-Ch]@1
  __int64 v34; // [sp+C8h] [bp-8h]@5

  v26 = this;
  RGBTexture_ctor((int)&v16);
  BYTE1(dword_6BE364) &= 0xBFu;
  dword_F8BC10 = 1;
  pVideoPlayer->dword_00006C = 0;
  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  Render_BeginScene(pD3DRenderer);
  sub_49ECC4(pD3DRenderer);
  Render_EndScene(pD3DRenderer);
  Render_Present(pD3DRenderer);
  pVideoPlayer->dword_000040 = 0;
  sub_449B57((int)byte_ACD71D, 99);

  compile_error;
  /*RGBTexture_Load(&v16, "winbg.pcx", 2);
  Render_BeginScene(pD3DRenderer);
  Render_DrawRGBTexture(pD3DRenderer, 0, 0, (int)&v16);*/

  v1 = (int)Render_EndScene(pD3DRenderer);
  call_delete(v1, v17);
  v17 = 0;
  dword_507BC0 = GUIWindowCreate(0, 0, 640, 480, 1, 0, 0);
  v18 = 75;
  v19 = 60;
  v20 = 469;
  v21 = 338;
  v22 = 543;
  v23 = 397;
  v33 = LoadFont("endgame.fnt", "FONTPAL");
  if ( (unsigned __int16)sub_449B57((int)byte_ACD71D, 99) )
  {
    v2 = pGlobalTXT_LocalizationStrings[675];
  }
  else
  {
    result = sub_449B57((int)byte_ACD71D, 100);
    if ( !(_WORD)result )
      return result;
    v2 = pGlobalTXT_LocalizationStrings[676];
  }
  v27 = (const char *)v2;
  v34 = pParty_global->qword_00002C - 138240;
  v30 = (unsigned int)((signed __int64)((double)(pParty_global->qword_00002C - 138240) * 0.234375) / 60 / 60) / 0x18;
  v25 = v30 / 0x1C / 0xC;
  v29 = v30 / 0x1C % 0xC;
  v28 = v30 % 0x1C;
  if ( !v30 )
    v30 = 1;
  Render_BeginScene(pD3DRenderer);
  sub_44D406((int)&v18, v33, 1, 35, 1u, pGlobalTXT_LocalizationStrings[9], 3);
  v4 = pParty_global->pPlayers[0].sName;
  v34 = 0i64;
  v31 = 0;
  for ( i = pParty_global->pPlayers[0].sName; ; v4 = i )
  {
    //v5 = (&dword_AE31F0)[4 * *(_BYTE *)(v4 + 17)];
    v5 = aClassNames[*(_BYTE *)(v4 + 17)];

    v6 = Player_GetBaseLevel(v4 - 168);
    sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[129], i, v6, v5);
    sub_44D406((int)&v18, v33, 1, v31 * (*(_BYTE *)(v33 + 5) - 2) + *(_BYTE *)(v33 + 5) + 46, 1u, &TmpBuf, 3);
    v7 = *(_DWORD *)(i - 8);
    v8 = v7 >= -(_DWORD)v34;
    LODWORD(v34) = v7 + v34;
    HIDWORD(v34) += *(_DWORD *)(i - 4) + v8;
    ++v31;
    compile_error;//v10 = __SETO__(i + 6972, &unk_AD471C);
    v9 = i + 6972 - (_DWORD)&unk_AD471C < 0;
    i += 6972;
    if ( !(v9 ^ v10) )
      break;
  }
  v34 /= (signed __int64)v30;
  v12 = FitTextInAWindow(v27, v33, (int)&v18, 12, 0);
  sub_44D406((int)&v18, v33, 1, 5 * (*(_BYTE *)(v33 + 5) + 11), 1u, v12, 0);
  strcpy(TmpBuf, pGlobalTXT_LocalizationStrings[37]);
  v11 = pGlobalTXT_LocalizationStrings[56];
  if ( v28 != 1 )
    v11 = pGlobalTXT_LocalizationStrings[57];
  v13 = pGlobalTXT_LocalizationStrings[146];
  if ( v29 != 1 )
    v13 = pGlobalTXT_LocalizationStrings[148];
  v14 = pGlobalTXT_LocalizationStrings[245];
  if ( v25 != 1 )
    v14 = pGlobalTXT_LocalizationStrings[132];
  sprintfex(pStringBuffer, " %lu %s, %lu %s, %lu %s ", v25, v14, v29, v13, v28, v11);
  strcat(TmpBuf, pStringBuffer);
  sub_44D406((int)&v18, v33, 1, v21 - 2 * *(_BYTE *)(v33 + 5) - 5, 1u, &TmpBuf, 3);
  sprintfex(TmpBuf, pGlobalTXT_LocalizationStrings[94], v34);
  sub_44D406((int)&v18, v33, 1, v21, 1u, TmpBuf, 3);
  BYTE1(dword_6BE364) |= 0x40u;
  Render_EndScene(pD3DRenderer);
  Render_Present(pD3DRenderer);
  if ( pD3DRenderer->pRendererD3D3 )
    dword_EF52A8();
  sub_49F1BC(pD3DRenderer, "MM7_Win.Pcx");
  class23_DeleteBuffer(class23_instance, v33);
  GUIWindowDelete(dword_507BC0);
  dword_507BC0 = 0;
  if ( v26 == (void *)2 )
  {
    result = dword_50CBD0[0];
  }
  else
  {
    LODWORD(v34) = GetTickCount() + 5000;
    while ( (_DWORD)v34 > GetTickCount() )
      ;
    while ( 1 )
    {
      v15 = PeekMessageA(&Msg, 0, 0, 0, 1u);
      if ( !v15 )
        break;
      if ( Msg.message == 18 )
        sub_464761(0);
      TranslateMessage(&Msg);
      DispatchMessageA(&Msg);
    }
    if ( dword_50CBD0[0] )
    {
      LOBYTE(v15) = dword_50CBD0[3] != 0;
      dword_50CBD0[0] = v15;
    }
    sub_459E3F();
    dword_69AE00 = 0;
    do
    {
      while ( PeekMessageA(&Msg, 0, 0, 0, 1u) )
      {
        if ( Msg.message == 18 )
          sub_464761(0);
        TranslateMessage(&Msg);
        DispatchMessageA(&Msg);
      }
    }
    while ( !dword_69AE00 );
    result = dword_50CBD0[0];
    if ( dword_50CBD0[0] )
    {
      result = dword_50CBD0[3] != 0;
      dword_50CBD0[0] = dword_50CBD0[3] != 0;
    }
  }
  if ( v26 )
  {
    if ( result < 40 )
    {
      dword_50CBD0[3 * result + 1] = 132;
      goto LABEL_42;
    }
  }
  else
  {
    if ( result < 40 )
    {
      dword_50CBD0[3 * result + 1] = 197;
LABEL_42:
      dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
      result = 3 * dword_50CBD0[0] + 3;
      dword_50CBD0[result] = 0;
      ++dword_50CBD0[0];
      goto LABEL_43;
    }
  }
LABEL_43:
  dword_F8BC10 = 0;
  return result;
}

//----- (004C05BE) --------------------------------------------------------
void __thiscall sub_4C05BE(int this)
{
  *(_DWORD *)this = 5081604;
  *(_DWORD *)(this + 4) = 5081608;
}

//----- (004C05CC) --------------------------------------------------------
char __thiscall sub_4C05CC(int this, int a2, int a3, int a4)
{
  int v4; // ebx@1
  int v5; // esi@1
  float v6; // ST00_4@3
  float v8; // [sp+4h] [bp-14h]@3

  v5 = a2;
  v4 = this;
  if ( !a2 )
    v5 = this + 4;
  *(_DWORD *)(v5 + 8196) = 0;
  v6 = (double)*(signed int *)(this + 8396);
  sub_4C06F8((void *)this, v6, v5, a3);
  v8 = (double)*(signed int *)(v4 + 8396);
  if ( dword_6BE360 == 1 )
    sub_4C0D32((void *)v4, v8, v5, a4);
  else
    sub_4C0DEA((void *)v4, v8, v5, a4);
  sub_4C2591(v5, 1);
  sub_4C264A(*(_DWORD *)(v5 + 8196) - 1, v5 + 6148, 0, *(_DWORD *)(v5 + 8196) - 1);
  return 1;
}

//----- (004C0646) --------------------------------------------------------
char __thiscall sub_4C0646(int this, float a2, float a3, float a4, int a5, int a6)
{
  int v6; // esi@1
  float v7; // ST04_4@2
  float v8; // ST00_4@3
  int v10; // [sp+1Ch] [bp-60h]@1

  v6 = this;
  *(_DWORD *)(this + 8200) = 0;
  sub_4C248E((int)&v10, SLODWORD(a3), a4, a2);
  sub_4C1542((void *)v6, a2, a3, a4, v6 + 4, a5);
  if ( dword_6BE360 == 1 )
  {
    v7 = a2;
    sub_4C16B4((void *)v6, SLOBYTE(v7), (int)&v10, v6 + 4, a6);
  }
  else
  {
    v8 = a2;
    sub_4C17CF((void *)v6, SLOBYTE(v8), (int)&v10, v6 + 4, a6, 0);
  }
  sub_4C2591(v6 + 4, 0);
  sub_4C264A(v6 + 6152, v6 + 6152, 0, *(_DWORD *)(v6 + 8200) - 1);
  return 1;
}

//----- (004C06F8) --------------------------------------------------------
void __thiscall sub_4C06F8(void *this, float a2, int a3, int a4)
{
  int v4; // ST18_4@5
  int v5; // edi@5
  void *v6; // [sp+20h] [bp-Ch]@1
  int v7; // [sp+24h] [bp-8h]@2
  int v8; // [sp+28h] [bp-4h]@1

  v8 = 0;
  v6 = this;
  if ( dword_F1B418 > 0 )
  {
    v7 = (int)dword_EF5350;
    do
    {
      if ( sub_4C0791(v8, a4) )
      {
        if ( sub_4C091D(v6, a2, v8) )
        {
          v4 = array_512250[*(_DWORD *)v7].dword_000010;
          v5 = a3 + 12 * *(_DWORD *)(a3 + 8196) + 4;
          *(_DWORD *)v5 = *(_DWORD *)v7;
          v5 += 4;
          *(_DWORD *)v5 = v4;
          *(_DWORD *)(v5 + 4) = 1;
          ++*(_DWORD *)(a3 + 8196);
        }
      }
      ++v8;
      v7 += 156;
    }
    while ( v8 < dword_F1B418 );
  }
}

//----- (004C0791) --------------------------------------------------------
char __stdcall sub_4C0791(int a1, int a2)
{
  int v2; // esi@1
  int v3; // eax@2
  int v4; // edx@2
  int v5; // ecx@2
  char v6; // zf@3
  int v7; // esi@5
  void *v8; // ecx@7
  int v9; // eax@8
  signed int v10; // eax@10
  signed int v12; // eax@18
  int v13; // edi@18
  char v14; // zf@26
  int v15; // eax@26
  const char *v16; // [sp-20h] [bp-2Ch]@7
  int v17; // [sp-1Ch] [bp-28h]@7
  char v18; // [sp-18h] [bp-24h]@7
  int v19; // [sp-14h] [bp-20h]@15
  int v20; // [sp-10h] [bp-1Ch]@15
  int v21; // [sp-Ch] [bp-18h]@15
  const char *v22; // [sp-8h] [bp-14h]@7
  int v23; // [sp-4h] [bp-10h]@7
  char *v24; // [sp+14h] [bp+8h]@7
  char *v25; // [sp+14h] [bp+8h]@14

  v2 = a2;
  if ( *(_DWORD *)a2 != 1 )
  {
    if ( *(_DWORD *)a2 != 2
      || (dword_6BE360 != 1 ? (v14 = *(_WORD *)(a1 + 292) == 0, v15 = *(_DWORD *)(a1 + 28)) : (v14 = *(_WORD *)(dword_6BE64C + 36 * *(_WORD *)(a1 + 72) + 26) == 0,
                                                                                               v15 = *(_DWORD *)(a1 + 44)),
          *(_DWORD *)(a2 + 4) != 1) )
      return 1;
    if ( v14 || v15 & *(_DWORD *)(a2 + 12) )
      return 0;
    v6 = (v15 & *(_DWORD *)(a2 + 8)) == 0;
    goto LABEL_32;
  }
  v4 = *(_DWORD *)(a2 + 16);
  v3 = (array_512250[dword_EF5350[39 * a1]].dword_000010 & 0xFFFF) >> 3;
  v5 = array_512250[dword_EF5350[39 * a1]].dword_000010 & 7;
  if ( v4 & 2 )
  {
    v6 = v5 == *(_DWORD *)(a2 + 4);
    goto LABEL_32;
  }
  if ( v4 & 4 )
  {
    v7 = *(_DWORD *)(a2 + 4);
    if ( v5 != v7 )
      return 1;
    if ( v7 != 5 )
    {
      v23 = 207;
      v22 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Vis.cpp";
      v8 = &v18;
      v24 = &v18;
      v17 = (int)((char *)&a1 + 3);
      v16 = "Unsupported \"exclusion if no event\" type in CVis::is_part_of_selection";
LABEL_15:
      sub_40E2C8(v8, v16, v17);
      sub_466D09(&a2, *(int *)&v18, v19, v20, v21, v22, v23);
      return 1;
    }
    v9 = 32 * v3;
    if ( array_6836D0[v3].word_000014 || array_6836D0[v3].word_000016)
      return 1;
    v10 = sub_44C2F4((char *)array_6836D0 + v9);
    goto LABEL_11;
  }
  if ( v5 == *(_DWORD *)(a2 + 4) )
  {
    if ( v5 != 3 )
    {
      v23 = 245;
      v22 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Vis.cpp";
      v8 = &v18;
      v25 = &v18;
      v17 = (int)((char *)&a1 + 3);
      v16 = "Default case reached in VIS";
      goto LABEL_15;
    }
    v13 = (int)((char *)pActors + 836 * v3);
    v12 = 1 << *(_BYTE *)(v13 + 176);
    if ( v12 & *(_DWORD *)(a2 + 12) || !(v12 & *(_DWORD *)(a2 + 8)) || v4 & 8 && !sub_438BDF(*(_WORD *)(v13 + 96), 1) )
      return 0;
    if ( !(*(_BYTE *)(v2 + 16) & 1) )
      return 1;
    v10 = Actor_sub_40104C(v13, 0);
LABEL_11:
    v6 = v10 == 0;
LABEL_32:
    if ( v6 )
      return 0;
    return 1;
  }
  return 0;
}

//----- (004C091D) --------------------------------------------------------
char __thiscall sub_4C091D(void *this, float a2, int a3)
{
  int v3; // eax@3
  int v4; // esi@3
  signed int v5; // ecx@4
  float v6; // ST04_4@6
  float v7; // ST00_4@7
  int v8; // eax@10
  unsigned int v9; // eax@12
  int v10; // eax@17
  double v11; // st6@18
  double v12; // st7@18
  double v13; // st4@18
  float v14; // ST0C_4@22
  float v15; // ST08_4@22
  float v16; // ST04_4@23
  float v17; // ST00_4@24
  signed int v18; // eax@27
  unsigned int v19; // eax@29
  double v20; // st6@32
  double v21; // st7@32
  int v22; // eax@32
  double v23; // st7@36
  void *v24; // esi@40
  float v25; // ST08_4@40
  float v26; // ST04_4@41
  float v27; // ST00_4@42
  int v28; // eax@45
  unsigned int v29; // eax@47
  char result; // al@48
  int v31; // [sp+20h] [bp-DCh]@5
  int v32; // [sp+80h] [bp-7Ch]@22
  float v33; // [sp+E0h] [bp-1Ch]@33
  float v34; // [sp+E4h] [bp-18h]@32
  int v35; // [sp+E8h] [bp-14h]@5
  int v36; // [sp+ECh] [bp-10h]@5
  unsigned int v37; // [sp+F0h] [bp-Ch]@5
  float v38; // [sp+F4h] [bp-8h]@17
  void *v39; // [sp+F8h] [bp-4h]@1
  signed int v40; // [sp+108h] [bp+Ch]@17
  float v41; // [sp+108h] [bp+Ch]@32

  v39 = this;
  if ( !(byte_F93E18 & 1) )
  {
    byte_F93E18 |= 1u;
    class25_fn0(&class25_global);
    compile_error;//atexit(loc_4C0D27);
  }
  dword_F93E14 = 0;
  v4 = 156 * a3;
  v3 = dword_EF5350[39 * a3];
  if ( v3 == -1
    || (v5 = array_512250[v3].dword_000010,
        (double)(unsigned __int16)array_512250[v3].dword_000010 * 0.00001525902189314365 + (double)(v5 >> 16) > a2) )
  {
LABEL_49:
    result = 0;
  }
  else
  {
    LOWORD(v5) = 0;
    v37 = v5;
    sub_4C1417(v39, (char *)&unk_EF52C0 + v4, 4, (int)&v35, (int)&v36);
    sub_4C248E((int)&v31, v35, *(float *)&v36, a2);
    if ( dword_6BE360 == 1 )
    {
      v6 = a2;
      sub_4C16B4(v39, SLOBYTE(v6), (int)&v31, (int)&class25_global, (int)&dword_F93E44);
    }
    else
    {
      v7 = a2;
      sub_4C17CF(v39, SLOBYTE(v7), (int)&v31, (int)&class25_global, (int)&dword_F93E44, 0);
    }
    sub_4C2591((int)&class25_global, 0);
    sub_4C264A(dword_F93E14 - 1, (int)&dword_F93614, 0, dword_F93E14 - 1);
    if ( dword_F93E14
      && (dword_F93E14 <= 0 ? (v8 = 0) : (v8 = dword_F93614), v9 = *(_DWORD *)(v8 + 4), LOWORD(v9) = 0, v9 <= v37)
      || (double)(class28_global.dword_000000) > *(float *)&v35
      || (double)class28_global.dword_000008 < *(float *)&v35
      || (double)class28_global.dword_000004 > *(float *)&v36
      || (double)class28_global.dword_00000C < *(float *)&v36 )
    {
      v40 = 0;
      v10 = (int)((char *)dword_EF52C4 + v4);
      LODWORD(v38) = (char *)dword_EF52C4 + v4;
      while ( 1 )
      {
        v12 = *(float *)(v10 - 4);
        v11 = *(float *)v10;
        v13 = *(float *)(v10 - 4);
        dword_F93E14 = 0;
        if ( v13 >= (double)(class28_global.dword_000000))
        {
          if ( v12 <= (double)class28_global.dword_000008 )
          {
            if ( v11 >= (double)class28_global.dword_000004 )
            {
              if ( v11 <= (double)class28_global.dword_00000C )
              {
                v14 = v11;
                v15 = v12;
                sub_4C248E((int)&v32, SLODWORD(v15), v14, a2);
                if ( dword_6BE360 == 1 )
                {
                  v16 = a2;
                  sub_4C16B4(v39, SLOBYTE(v16), (int)&v32, (int)&class25_global, (int)&dword_F93E44);
                }
                else
                {
                  v17 = a2;
                  sub_4C17CF(v39, SLOBYTE(v17), (int)&v32, (int)&class25_global, (int)&dword_F93E44, 0);
                }
                sub_4C2591((int)&class25_global, 0);
                sub_4C264A(dword_F93E14 - 1, (int)&dword_F93614, 0, dword_F93E14 - 1);
                if ( !dword_F93E14 )
                  break;
                v18 = dword_F93E14 <= 0 ? 0 : dword_F93614;
                v19 = *(_DWORD *)(v18 + 4);
                LOWORD(v19) = 0;
                if ( v19 > v37 )
                  break;
              }
            }
          }
        }
        ++v40;
        v10 = LODWORD(v38) + 32;
        LODWORD(v38) += 32;
        if ( v40 >= 4 )
        {
          if ( dword_6BE360 != 2 )
            goto LABEL_49;
          v21 = *(float *)(v4 + 15684288);
          v20 = *(float *)(v4 + 15684384);
          v22 = *(int *)((char *)dword_EF52C4 + v4);
          v34 = *(float *)(v4 + 15684384);
          LODWORD(v38) = v22;
          LODWORD(v41) = *(int *)((char *)dword_EF52E4 + v4);
          if ( v21 > v20 )
          {
            v33 = v21;
            v21 = v34;
            v20 = v33;
          }
          if ( v38 > (double)v41 )
            v41 = v38;
          dword_F93E14 = 0;
          v23 = (v20 - v21) * 0.5;
          if ( v23 < (double)(class28_global.dword_000000)
            || v23 > (double)class28_global.dword_000008
            || (double)class28_global.dword_000004 > v41
            || (double)class28_global.dword_00000C < v41
            || ((v24 = v39, v25 = v23, sub_4C248E((int)&v32, SLODWORD(v25), v41, a2), dword_6BE360 != 1) ? (v27 = a2, sub_4C17CF(v24, SLOBYTE(v27), (int)&v32, (int)&class25_global, (int)&dword_F93E44, 0)) : (v26 = a2, sub_4C16B4(v24, SLOBYTE(v26), (int)&v32, (int)&class25_global, (int)&dword_F93E44)),
                (sub_4C2591((int)&class25_global, 0),
                 sub_4C264A(dword_F93E14 - 1, (int)&dword_F93614, 0, dword_F93E14 - 1),
                 dword_F93E14)
             && (dword_F93E14 <= 0 ? (v28 = 0) : (v28 = dword_F93614),
                 v29 = *(_DWORD *)(v28 + 4),
                 LOWORD(v29) = 0,
                 v29 <= v37)) )
            goto LABEL_49;
          break;
        }
      }
    }
    result = 1;
  }
  return result;
}

//----- (004C0D32) --------------------------------------------------------
int __thiscall sub_4C0D32(void *this, float a2, int a3, int a4)
{
  int result; // eax@1
  int v5; // esi@2
  int v6; // edi@4
  int v7; // eax@6
  int v8; // eax@6
  int v9; // ST18_4@7
  int v10; // ST1C_4@7
  int v11; // ecx@7
  unsigned __int8 v12; // sf@8
  unsigned __int8 v13; // of@8
  int v14; // [sp+18h] [bp-8h]@1
  void *v15; // [sp+1Ch] [bp-4h]@1

  result = 0;
  v15 = this;
  v14 = 0;
  if (class37_global0.dword_000000 > 0)
  {
    do
    {
      v5 = word_51B77C[2 * result];
      if ( v5 >= 0 )
      {
        if ( v5 < dword_6BE640 )
        {
          v6 = dword_6BE644 + 96 * v5;
          if ( !sub_436455(dword_6BE644 + 96 * v5) )
          {
            if ( sub_4C0791(v6, a4) )
            {
              v8 = 8 * v5;
              LOBYTE(v8) = 8 * v5 | 6;
              v7 = sub_4C1026(v15, v6, v8, a2);
              if ( v7 )
              {
                v9 = *(_DWORD *)(v7 + 4);
                v10 = *(_DWORD *)(v7 + 8);
                v11 = 3 * *(_DWORD *)(a3 + 8196);
                *(_DWORD *)(a3 + 12 * *(_DWORD *)(a3 + 8196) + 4) = *(_DWORD *)v7;
                *(_DWORD *)(a3 + 4 * v11 + 8) = v9;
                *(_DWORD *)(a3 + 4 * v11 + 12) = v10;
                ++*(_DWORD *)(a3 + 8196);
              }
            }
          }
        }
      }
      result = v14 + 1;
      compile_error;//v13 = __SETO__(v14 + 1, class37_global0.dword_000000);
      v12 = v14++ + 1 - class37_global0.dword_000000 < 0;
    }
    while ( v12 ^ v13 );
  }
  return result;
}

//----- (004C0DEA) --------------------------------------------------------
int __thiscall sub_4C0DEA(void *this, float a2, int a3, int a4)
{
  int result; // eax@1
  int v5; // esi@1
  int v6; // ebx@3
  int v7; // eax@3
  unsigned __int8 v8; // zf@5
  char v9; // sf@5
  unsigned __int8 v10; // of@5
  int v11; // esi@7
  int v12; // eax@8
  int v13; // eax@8
  int v14; // ecx@9
  int v15; // [sp+10h] [bp-84h]@1
  int v16; // [sp+70h] [bp-24h]@9
  int v17; // [sp+74h] [bp-20h]@9
  int v18; // [sp+78h] [bp-1Ch]@9
  int v19; // [sp+7Ch] [bp-18h]@1
  void *v20; // [sp+80h] [bp-14h]@1
  int v21; // [sp+84h] [bp-10h]@6
  int v22; // [sp+88h] [bp-Ch]@2
  int v23; // [sp+8Ch] [bp-8h]@5
  int v24; // [sp+90h] [bp-4h]@1

  v20 = this;
  result = sub_46ED02((int)&v15);
  v5 = 0;
  v19 = 0;
  v24 = 0;
  if ( pClass51_global->uNumBModels > 0 )
  {
    v22 = 0;
    do
    {
      v6 = v22 + pClass51_global->pBModels;
      LOBYTE(v7) = sub_479089(v24, (int)&v19);
      if ( v7 )
      {
        if ( v19 != v5 )
        {
          compile_error;//v10 = __SETO__(*(_DWORD *)(v6 + 76), v5);
          v8 = *(_DWORD *)(v6 + 76) == v5;
          v9 = *(_DWORD *)(v6 + 76) - v5 < 0;
          v23 = v5;
          if ( !((unsigned __int8)(v9 ^ v10) | v8) )
          {
            v21 = v5;
            do
            {
              v11 = v21 + *(_DWORD *)(v6 + 84);
              if ( sub_4C0791(v11, a4) )
              {
                sub_4C0EF2((int)&v15, v11);
                v13 = 8 * (v23 | (v24 << 6));
                LOBYTE(v13) = v13 | 6;
                v12 = sub_4C1026(v20, (int)&v15, v13, a2);
                if ( v12 )
                {
                  v16 = *(_DWORD *)v12;
                  v17 = *(_DWORD *)(v12 + 4);
                  v14 = *(_DWORD *)(a3 + 8196);
                  v18 = *(_DWORD *)(v12 + 8);
                  v14 *= 3;
                  *(_DWORD *)(a3 + 4 * v14 + 4) = v16;
                  *(_DWORD *)(a3 + 4 * v14 + 8) = v17;
                  *(_DWORD *)(a3 + 4 * v14 + 12) = v18;
                  ++*(_DWORD *)(a3 + 8196);
                }
              }
              ++v23;
              v21 += 308;
            }
            while ( v23 < *(_DWORD *)(v6 + 76) );
            v5 = 0;
          }
        }
      }
      ++v24;
      v22 += 188;
      result = v24;
    }
    while ( v24 < pClass51_global->uNumBModels );
  }
  return result;
}

//----- (004C0EF2) --------------------------------------------------------
int __thiscall sub_4C0EF2(int this, int a2)
{
  int result; // eax@1

  *(_DWORD *)(this + 16) = *(_DWORD *)a2;
  *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 12);
  *(float *)this = (double)(*(_DWORD *)a2 & 0xFFFF) * 0.00001525902189314365 + (double)(signed int)(*(_DWORD *)a2 >> 16);
  *(float *)(this + 4) = (double)(*(_DWORD *)(a2 + 4) & 0xFFFF) * 0.00001525902189314365
                       + (double)(signed int)(*(_DWORD *)(a2 + 4) >> 16);
  *(float *)(this + 8) = (double)(*(_DWORD *)(a2 + 8) & 0xFFFF) * 0.00001525902189314365
                       + (double)(signed int)(*(_DWORD *)(a2 + 8) >> 16);
  *(float *)(this + 12) = (double)(*(_DWORD *)(a2 + 12) & 0xFFFF) * 0.00001525902189314365
                        + (double)(signed int)(*(_DWORD *)(a2 + 12) >> 16);
  *(_DWORD *)(this + 44) = *(_DWORD *)(a2 + 28);
  *(_WORD *)(this + 80) = *(_WORD *)(a2 + 278);
  *(_WORD *)(this + 84) = *(_WORD *)(a2 + 282);
  *(_WORD *)(this + 88) = *(_WORD *)(a2 + 286);
  *(_WORD *)(this + 82) = *(_WORD *)(a2 + 280);
  *(_WORD *)(this + 86) = *(_WORD *)(a2 + 284);
  *(_WORD *)(this + 90) = *(_WORD *)(a2 + 288);
  *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(this + 36) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(this + 40) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(this + 52) = a2 + 152;
  *(_DWORD *)(this + 56) = a2 + 192;
  *(_DWORD *)(this + 60) = a2 + 232;
  *(_BYTE *)(this + 92) = *(_BYTE *)(a2 + 303);
  *(_BYTE *)(this + 93) = *(_BYTE *)(a2 + 302);
  result = a2 + 32;
  *(_WORD *)(this + 74) = *(_WORD *)(a2 + 272);
  *(_DWORD *)(this + 48) = a2 + 32;
  return result;
}

//----- (004C1026) --------------------------------------------------------
int __thiscall sub_4C1026(void *this, int a2, int a3, float a4)
{
  _UNKNOWN *v4; // eax@4
  signed int v5; // ecx@4
  int v6; // ecx@7
  int v7; // edi@7
  int v8; // eax@9
  _UNKNOWN *v9; // edx@9
  int v10; // esi@10
  _UNKNOWN *v11; // eax@13
  int v12; // edx@13
  double v13; // st7@14
  int v14; // ebx@14
  void *v15; // ebx@15
  float v16; // ST04_4@18
  float v17; // ST00_4@19
  int result; // eax@21
  int v19; // ecx@24
  int v20; // [sp+20h] [bp-70h]@17
  void *v21; // [sp+80h] [bp-10h]@1
  int v22; // [sp+84h] [bp-Ch]@10
  int v23; // [sp+88h] [bp-8h]@16
  int v24; // [sp+8Ch] [bp-4h]@16
  int v25; // [sp+98h] [bp+8h]@7

  v21 = this;
  if ( !(byte_F91E08 & 1) )
  {
    byte_F91E08 |= 1u;
    class25_fn0(&dword_F8FE00);
    atexit(sub_4C12B8);
  }
  dword_F91E04 = 0;
  if ( !(byte_F91E08 & 2) )
  {
    byte_F91E08 |= 2;
    v4 = &unk_F8F22C;
    v5 = 64;
    do
    {
      *(float *)v4 = 0.0;
      v4 = (char *)v4 + 48;
      --v5;
    }
    while ( v5 );
    atexit(0);
  }
  v6 = a2;
  v25 = 0;
  v7 = *(_BYTE *)(v6 + 93);
  if ( dword_6BE360 == 1 )
  {
    if ( v7 > 0 )
    {
      v8 = dword_6BE63C;
      v9 = &unk_F8F204;
      do
      {
        v10 = v25++;
        v22 = *(_WORD *)(v8 + 6 * *(_WORD *)(2 * v10 + *(_DWORD *)(v6 + 48)));
        *((float *)v9 - 1) = (double)v22;
        v22 = *(_WORD *)(v8 + 6 * *(_WORD *)(2 * v10 + *(_DWORD *)(v6 + 48)) + 2);
        *(float *)v9 = (double)v22;
        v9 = (char *)v9 + 48;
        v22 = *(_WORD *)(v8 + 6 * *(_WORD *)(2 * v10 + *(_DWORD *)(v6 + 48)) + 4);
        *((float *)v9 - 11) = (double)v22;
      }
      while ( v25 < v7 );
    }
  }
  else
  {
    if ( v7 > 0 )
    {
      v12 = 188 * ((unsigned int)a3 >> 9) + pClass51_global->pBModels + 72;
      v11 = &unk_F8F204;
      do
      {
        *((float *)v11 - 1) = (double)*(signed int *)(*(_DWORD *)v12 + 12 * *(_WORD *)(*(_DWORD *)(v6 + 48) + 2 * v25));
        v13 = (double)*(signed int *)(*(_DWORD *)v12 + 12 * *(_WORD *)(*(_DWORD *)(v6 + 48) + 2 * v25) + 4);
        v14 = v25++;
        *(float *)v11 = v13;
        v11 = (char *)v11 + 48;
        *((float *)v11 - 11) = (double)*(signed int *)(*(_DWORD *)v12
                                                     + 12 * *(_WORD *)(*(_DWORD *)(v6 + 48) + 2 * v14)
                                                     + 8);
      }
      while ( v25 < v7 );
    }
  }
  sub_436523((int)&unk_F8F200, v7);
  class08_sub_436BB7(pGame->class08_obj, (int)&unk_F8F200, v7, 1);
  v15 = v21;
  sub_4C1ABA(v21, (int)&unk_F8F200, 0, v7 - 1);
  if ( flt_F8F20C > (double)a4
    || (sub_4C1495(v21, &unk_F8F200, v7, (int)&v23, (int)&v24),
        sub_4C12C3((int)&unk_F8F200, v7, *(float *)&v23, *(float *)&v24))
    || ((sub_4C248E((int)&v20, v23, *(float *)&v24, a4), dword_6BE360 != 1) ? (v17 = a4,
                                                                               sub_4C17CF(
                                                                                 v15,
                                                                                 SLOBYTE(v17),
                                                                                 (int)&v20,
                                                                                 (int)&dword_F8FE00,
                                                                                 (int)&dword_F93E44,
                                                                                 1)) : (v16 = a4,
                                                                                        sub_4C16B4(
                                                                                          v15,
                                                                                          SLOBYTE(v16),
                                                                                          (int)&v20,
                                                                                          (int)&dword_F8FE00,
                                                                                          (int)&dword_F93E44)),
        (sub_4C2591((int)&dword_F8FE00, 0),
         sub_4C264A(dword_F91E04 - 1, (int)&dword_F91604, 0, dword_F91E04 - 1),
         !dword_F91E04)
     || (result = sub_4C2551((int)&dword_F8FE00, 2, a3), !result)
     || dword_F91E04 > 1 && (dword_F91E04 <= 0 ? (v19 = 0) : (v19 = dword_F91604), result != v19)) )
    result = 0;
  return result;
}

//----- (004C12B8) --------------------------------------------------------
void __cdecl sub_4C12B8()
{
  dword_F8FE00 = 5081608;
}

//----- (004C12C3) --------------------------------------------------------
char __stdcall sub_4C12C3(int a1, int a2, float a3, float a4)
{
  int v4; // esi@1
  int v5; // edi@2
  int v6; // edx@9
  double v7; // st7@9
  int v8; // ecx@10
  char result; // al@24
  float v10; // [sp+10h] [bp-8h]@9
  signed int v11; // [sp+14h] [bp-4h]@1
  float v12; // [sp+28h] [bp+10h]@9
  float v13; // [sp+2Ch] [bp+14h]@9

  v11 = -1;
  v4 = 0;
  if ( dword_F1B418 <= 0 )
    goto LABEL_28;
  v5 = (int)dword_EF5350;
  do
  {
    if ( sub_4C1607(v5 - 152, a3, a4) )
    {
      if ( v11 == -1 || array_512250[*(_DWORD *)v5].dword_000010 < (unsigned int)array_512250[dword_EF5350[39 * v11]].dword_000010 )
        v11 = v4;
    }
    ++v4;
    v5 += 156;
  }
  while ( v4 < dword_F1B418 );
  if ( v11 == -1 )
    goto LABEL_28;
  v7 = 3.402823466385289e38;
  v6 = a2;
  LODWORD(v13) = 2139095039;
  v12 = -3.402823466385289e38;
  v10 = -3.402823466385289e38;
  if ( a2 > 0 )
  {
    v8 = a1 + 28;
    do
    {
      if ( *(float *)(v8 - 4) < v7 )
        v7 = *(float *)(v8 - 4);
      if ( *(float *)(v8 - 4) > (double)v12 )
        v12 = *(float *)(v8 - 4);
      if ( *(float *)v8 < (double)v13 )
        v13 = *(float *)v8;
      if ( *(float *)v8 > (double)v10 )
        v10 = *(float *)v8;
      v8 += 48;
      --v6;
    }
    while ( v6 );
  }
  if ( v7 < *((float *)&unk_EF52C0 + 39 * v11)
    || *(float *)&dword_EF52C4[39 * v11] > (double)v13
    || *((float *)&unk_EF5320 + 39 * v11) < (double)v12
    || *(float *)&dword_EF52E4[39 * v11] < (double)v10 )
LABEL_28:
    result = 0;
  else
    result = 1;
  return result;
}

//----- (004C1417) --------------------------------------------------------
int __thiscall sub_4C1417(void *this, const void *Src, int a3, int a4, int a5)
{
  int result; // eax@1
  void *v6; // ST18_4@1

  v6 = this;
  memcpy(&flt_F8EA00, Src, 32 * a3);
  sub_4C26D0(v6, (int)&flt_F8EA00, 0, a3 - 1);
  *(float *)a4 = (*((float *)&unk_F8E9E0 + 8 * a3) - flt_F8EA00) * 0.5 + flt_F8EA00;
  sub_4C27AD(v6, (int)&flt_F8EA00, 0, a3 - 1);
  result = a5;
  *(float *)a5 = (*((float *)&unk_F8E9E4 + 8 * a3) - flt_F8EA04) * 0.5 + flt_F8EA04;
  return result;
}

//----- (004C1495) --------------------------------------------------------
int __thiscall sub_4C1495(void *this, const void *Src, int a3, int a4, int a5)
{
  _UNKNOWN *v5; // eax@2
  signed int v6; // ecx@2
  int result; // eax@5
  void *v8; // [sp+0h] [bp-4h]@1

  v8 = this;
  if ( !(byte_F8E9F8 & 1) )
  {
    byte_F8E9F8 |= 1u;
    v5 = &unk_F8DE24;
    v6 = 64;
    do
    {
      *(float *)v5 = 0.0;
      v5 = (char *)v5 + 48;
      --v6;
    }
    while ( v6 );
    atexit(0);
  }
  memcpy(&unk_F8DDF8, Src, 48 * a3);
  sub_4C288E(v8, (int)&unk_F8DDF8, 0, a3 - 1);
  *(float *)a4 = (*((float *)&unk_F8DDE0 + 12 * a3) - flt_F8DE10) * 0.5 + flt_F8DE10;
  sub_4C297E(v8, (int)&unk_F8DDF8, 0, a3 - 1);
  result = a5;
  *(float *)a5 = (*((float *)&unk_F8DDE4 + 12 * a3) - flt_F8DE14) * 0.5 + flt_F8DE14;
  return result;
}

//----- (004C1542) --------------------------------------------------------
void __thiscall sub_4C1542(void *this, float a2, float a3, float a4, int a5, int a6)
{
  int v6; // ST1C_4@6
  int v7; // edi@6
  void *v8; // [sp+20h] [bp-Ch]@1
  int v9; // [sp+24h] [bp-8h]@2
  int v10; // [sp+28h] [bp-4h]@1

  v10 = 0;
  v8 = this;
  if ( dword_F1B418 > 0 )
  {
    v9 = (int)dword_EF5350;
    do
    {
      if ( sub_4C0791(v10, a6) )
      {
        if ( sub_4C1607(v9 - 152, a3, a4) )
        {
          if ( sub_4C091D(v8, a2, v10) )
          {
           v6 = array_512250[*(_DWORD *)v9].dword_000010;
            v7 = a5 + 12 * *(_DWORD *)(a5 + 8196) + 4;
            *(_DWORD *)v7 = *(_DWORD *)v9;
            v7 += 4;
            *(_DWORD *)v7 = v6;
            *(_DWORD *)(v7 + 4) = 1;
            ++*(_DWORD *)(a5 + 8196);
          }
        }
      }
      ++v10;
      v9 += 156;
    }
    while ( v10 < dword_F1B418 );
  }
}

//----- (004C1607) --------------------------------------------------------
char __stdcall sub_4C1607(int a1, float a2, float a3)
{
  int v3; // eax@1
  double v4; // st7@2
  float v5; // ST00_4@3
  char result; // al@10
  float v7; // [sp+4h] [bp-8h]@2
  float v8; // [sp+8h] [bp-4h]@2
  float v9; // [sp+14h] [bp+8h]@2

  v3 = a1;
  if ( *(_DWORD *)(a1 + 152) == -1 )
    goto LABEL_14;
  v4 = *(float *)(a1 + 8);
  LODWORD(v9) = *(_DWORD *)(a1 + 104);
  LODWORD(v8) = *(_DWORD *)(v3 + 12);
  LODWORD(v7) = *(_DWORD *)(v3 + 44);
  if ( v4 > v9 )
  {
    v5 = v4;
    v4 = v9;
    v9 = v5;
  }
  if ( v8 > (double)v7 )
  {
    v7 = v8;
    LODWORD(v8) = *(_DWORD *)(v3 + 44);
  }
  if ( a2 + 1.0 < v4 || a2 - 1.0 > v9 || a3 + 1.0 < v8 || a3 - 1.0 > v7 )
LABEL_14:
    result = 0;
  else
    result = 1;
  return result;
}

//----- (004C16B4) --------------------------------------------------------
int __thiscall sub_4C16B4(void *this, char a2, int a3, int a4, int a5)
{
  int result; // eax@1
  int v6; // edi@2
  int v7; // esi@4
  int v8; // eax@7
  int v9; // eax@7
  int v10; // ecx@7
  int v11; // edi@7
  unsigned __int8 v12; // sf@8
  unsigned __int8 v13; // of@8
  char v14; // [sp+Ch] [bp-44h]@6
  float v15; // [sp+18h] [bp-38h]@7
  float v16; // [sp+38h] [bp-18h]@1
  int v17; // [sp+3Ch] [bp-14h]@7
  int v18; // [sp+40h] [bp-10h]@7
  int v19; // [sp+44h] [bp-Ch]@7
  int v20; // [sp+48h] [bp-8h]@1
  void *v21; // [sp+4Ch] [bp-4h]@1

  result = 0;
  v21 = this;
  v20 = 0;
  v16 = 0.0;
  if (class37_global0.dword_000000 > 0 )
  {
    do
    {
      v6 = word_51B77C[2 * result];
      if ( v6 >= 0 )
      {
        if ( v6 < dword_6BE640 )
        {
          v7 = 96 * v6;
          if ( sub_4C0791(96 * v6 + dword_6BE644, a5) )
          {
            if ( !sub_436455(v7 + dword_6BE644) )
            {
              if ( sub_4C1C0C(a3, a3 + 48, (int)&a2, (int)&v14, v7 + dword_6BE644, -1) )
              {
                sub_436523((int)&v14, 1);
                v8 = sub_48B561(v15);
                LOWORD(v8) = 0;
                v18 = (8 * v6 | 6) + v8;
                v9 = a4 + 8196;
                v19 = 2;
                v10 = *(_DWORD *)(a4 + 8196);
                v17 = dword_6BE644 + v7;
                v11 = a4 + 12 * v10 + 4;
                *(_DWORD *)v11 = dword_6BE644 + v7;
                v11 += 4;
                *(_DWORD *)v11 = v18;
                *(_DWORD *)(v11 + 4) = v19;
                ++*(_DWORD *)v9;
              }
            }
          }
        }
      }
      result = v20 + 1;
      compile_error;//v13 = __SETO__(v20 + 1, class37_global0.dword_000000);
      v12 = v20++ + 1 - class37_global0.dword_000000 < 0;
    }
    while ( v12 ^ v13 );
  }
  return result;
}

//----- (004C17CF) --------------------------------------------------------
char __thiscall sub_4C17CF(void *this, char a2, int a3, int a4, int a5, char a6)
{
  int v6; // eax@1
  int v7; // ecx@1
  int v8; // esi@1
  int v9; // ebx@3
  int v10; // esi@10
  int v11; // eax@12
  int v12; // eax@12
  int v13; // edi@12
  unsigned __int8 v14; // sf@15
  unsigned __int8 v15; // of@15
  char v17; // [sp+10h] [bp-B8h]@1
  char v18; // [sp+70h] [bp-58h]@11
  float v19; // [sp+7Ch] [bp-4Ch]@12
  float v20; // [sp+9Ch] [bp-2Ch]@1
  int v21; // [sp+A0h] [bp-28h]@12
  int v22; // [sp+A4h] [bp-24h]@12
  int v23; // [sp+A8h] [bp-20h]@12
  int v24; // [sp+ACh] [bp-1Ch]@8
  void *v25; // [sp+B0h] [bp-18h]@1
  int v26; // [sp+B4h] [bp-14h]@9
  int v27; // [sp+B8h] [bp-10h]@1
  int v28; // [sp+BCh] [bp-Ch]@2
  int v29; // [sp+C0h] [bp-8h]@1
  int v30; // [sp+C4h] [bp-4h]@8

  v25 = this;
  LOBYTE(v6) = sub_46ED02((int)&v17);
  v8 = 0;
  v7 = 0;
  v27 = 0;
  v29 = 0;
  v20 = 0.0;
  if ( pClass51_global->uNumBModels > 0 )
  {
    v28 = 0;
    while ( 1 )
    {
      v9 = v28 + pClass51_global->pBModels;
      LOBYTE(v6) = sub_479089(v7, (int)&v27);
      if ( a6 )
        break;
      if ( v6 )
        goto LABEL_8;
LABEL_15:
      v28 += 188;
      v7 = v29 + 1;
      compile_error;//v15 = __SETO__(v29 + 1, pClass51_global->uNumBModels);
      v14 = v29++ + 1 - pClass51_global->uNumBModels < 0;
      if ( !(v14 ^ v15) )
        return v6;
    }
    if ( !v6 || v27 == v8 )
      goto LABEL_15;
LABEL_8:
    v6 = *(_DWORD *)(v9 + 76);
    v30 = v8;
    v24 = v6;
    if ( v6 > v8 )
    {
      v26 = v8;
      do
      {
        v10 = v26 + *(_DWORD *)(v9 + 84);
        if ( sub_4C0791(v10, a5) )
        {
          sub_4C0EF2((int)&v17, v10);
          if ( sub_4C1C0C(a3, a3 + 48, (int)&a2, (int)&v18, (int)&v17, v29) )
          {
            sub_436523((int)&v18, 1);
            v21 = v10;
            v11 = sub_48B561(v19);
            LOWORD(v11) = 0;
            v23 = 2;
            v22 = (8 * (v30 | (v29 << 6)) | 6) + v11;
            v12 = a4 + 8196;
            v13 = a4 + 12 * *(_DWORD *)(a4 + 8196) + 4;
            *(_DWORD *)v13 = v21;
            v13 += 4;
            *(_DWORD *)v13 = v22;
            *(_DWORD *)(v13 + 4) = v23;
            ++*(_DWORD *)v12;
          }
        }
        ++v30;
        v26 += 308;
        LOBYTE(v6) = v30;
      }
      while ( v30 < v24 );
      v8 = 0;
    }
    goto LABEL_15;
  }
  return v6;
}

//----- (004C1930) --------------------------------------------------------
char __thiscall sub_4C1930(void *this, float a2, int a3)
{
  return sub_4C091D(this, a2, a3);
}

//----- (004C1944) --------------------------------------------------------
signed int __thiscall sub_4C1944(void *this, int a2, unsigned int a3, int a4, int a5, int a6)
{
  float v6; // ST00_4@3
  signed int result; // eax@4
  int v8; // [sp+18h] [bp-20h]@3
  int v9; // [sp+1Ch] [bp-1Ch]@3
  int v10; // [sp+20h] [bp-18h]@3
  int v11; // [sp+24h] [bp-14h]@3
  int v12; // [sp+28h] [bp-10h]@3
  __int64 v13; // [sp+2Ch] [bp-Ch]@3
  void *v14; // [sp+34h] [bp-4h]@1

  v14 = this;
  if ( !(byte_F8DDF0 & 1) )
  {
    byte_F8DDF0 |= 1u;
    class25_fn0(&dword_F8BDE8);
    compile_error;//atexit(loc_4C19F7);
  }
  v9 = a2;
  v10 = a6;
  v11 = a5;
  v12 = a4;
  v13 = a3;
  dword_F8DDEC = 0;
  v6 = (double)a3;
  v8 = 1;
  sub_4C06F8(v14, v6, (int)&dword_F8BDE8, (int)&v8);
  sub_4C2591((int)&dword_F8BDE8, 1);
  sub_4C264A(dword_F8DDEC - 1, (int)&dword_F8D5EC, 0, dword_F8DDEC - 1);
  if ( dword_F8DDEC <= 0 )
    result = -1;
  else
    result = *(_DWORD *)(dword_F8D5EC + 4);
  return result;
}

//----- (004C1A02) --------------------------------------------------------
int __thiscall sub_4C1A02(int this)
{
  int result; // eax@1
  char v2; // [sp+8h] [bp-C0h]@1
  char v3; // [sp+38h] [bp-90h]@1
  float v4; // [sp+68h] [bp-60h]@1
  float v5; // [sp+6Ch] [bp-5Ch]@1
  float v6; // [sp+70h] [bp-58h]@1
  float v7; // [sp+94h] [bp-34h]@1
  float v8; // [sp+98h] [bp-30h]@1
  float v9; // [sp+9Ch] [bp-2Ch]@1
  float v10; // [sp+A0h] [bp-28h]@1
  float v11; // [sp+C4h] [bp-4h]@1

  v11 = 0.0;
  result = this;
  v8 = 0.0;
  v9 = 65536.0;
  v10 = 0.0;
  v7 = 0.0;
  v4 = 65536.0;
  v5 = 0.0;
  v6 = 0.0;
  memcpy(&v2, &v4, 0x30u);
  v7 = 0.0;
  v4 = 0.0;
  v5 = 65536.0;
  v6 = 0.0;
  memcpy(&v3, &v8, 0x30u);
  v11 = 0.0;
  v8 = 65536.0;
  v9 = 0.0;
  v10 = 0.0;
  memcpy((void *)(this + 8204), &v2, 0x60u);
  memcpy(&v2, &v8, 0x30u);
  memcpy(&v3, &v4, 0x30u);
  memcpy((void *)(this + 8300), &v2, 0x60u);
  return result;
}

//----- (004C1ABA) --------------------------------------------------------
char __thiscall sub_4C1ABA(void *this, int a2, int a3, int a4)
{
  int v4; // edx@2
  int i; // ecx@2
  int v6; // ebx@2
  int v7; // esi@3
  int v8; // esi@5
  const void *v9; // eax@8
  char v11; // [sp+4h] [bp-6Ch]@8
  char v12; // [sp+34h] [bp-3Ch]@2
  float v13; // [sp+40h] [bp-30h]@4
  int v14; // [sp+64h] [bp-Ch]@7
  void *v15; // [sp+68h] [bp-8h]@1
  const void *v16; // [sp+6Ch] [bp-4h]@2

  v15 = this;
  if ( a4 > a3 )
  {
    v4 = a2;
    v16 = (const void *)(48 * a4 + a2);
    v6 = a3 - 1;
    memcpy(&v12, (const void *)(48 * a4 + a2), 0x30u);
    for ( i = a4; ; i = v14 )
    {
      v7 = 48 * v6 + v4 + 12;
      do
      {
        v7 += 48;
        ++v6;
      }
      while ( *(float *)v7 < (double)v13 );
      v8 = 48 * i + v4 + 12;
      do
      {
        v8 -= 48;
        --i;
      }
      while ( *(float *)v8 > (double)v13 );
      v14 = i;
      if ( v6 >= i )
        break;
      v9 = (const void *)(v4 + 48 * i);
      memcpy(&v11, (const void *)(a2 + 48 * v6), 0x30u);
      v4 = a2;
      memcpy((void *)(a2 + 48 * v6), v9, 0x30u);
      memcpy((void *)v9, &v11, 0x30u);
    }
    memcpy(&v11, (const void *)(v4 + 48 * v6), 0x30u);
    memcpy((void *)(v4 + 48 * v6), v16, 0x30u);
    memcpy((void *)v16, &v11, 0x30u);
    sub_4C1ABA(this, v4, a3, v6 - 1);
    sub_4C1ABA(this, a2, v6 + 1, a4);
  }
  return 1;
}

//----- (004C1BAA) --------------------------------------------------------
signed int __thiscall sub_4C1BAA(void *this, int a2)
{
  signed int v2; // eax@1
  signed int result; // eax@3
  char v4; // [sp-18h] [bp-1Ch]@4
  int v5; // [sp-14h] [bp-18h]@4
  int v6; // [sp-10h] [bp-14h]@4
  int v7; // [sp-Ch] [bp-10h]@4
  const char *v8; // [sp-8h] [bp-Ch]@4
  int v9; // [sp-4h] [bp-8h]@4
  void *v10; // [sp+0h] [bp-4h]@1
  char *v11; // [sp+Ch] [bp+8h]@4

  v10 = this;
  v2 = *(_DWORD *)(a2 + 8);
  if ( v2 <= 0 || v2 > 2 )
  {
    v9 = 1037;
    v8 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Vis.cpp";
    v11 = &v4;
    sub_40E2C8(&v4, "Undefined type requested for: CVis::get_object_zbuf_val()", (int)((char *)&a2 + 3));
    sub_466D09(&v10, *(int *)&v4, v5, v6, v7, v8, v9);
    result = -1;
  }
  else
  {
    result = *(_DWORD *)(a2 + 4);
  }
  return result;
}

//----- (004C1BF1) --------------------------------------------------------
signed int __thiscall sub_4C1BF1(int this)
{
  signed int result; // eax@2

  if ( *(_DWORD *)(this + 8200) <= 0 )
    result = -1;
  else
    result = sub_4C1BAA((void *)this, *(_DWORD *)(this + 6152));
  return result;
}

//----- (004C1C0C) --------------------------------------------------------
char __stdcall sub_4C1C0C(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // eax@1
  int v7; // ebx@1
  double v8; // st7@3
  double v9; // st5@6
  double v10; // st6@10
  double v11; // st7@11
  signed int v12; // ST1E_4@11
  float v14; // [sp+30h] [bp+18h]@6
  float v15; // [sp+30h] [bp+18h]@10

  v7 = a5;
  v6 = *(_DWORD *)(a5 + 44);
  if ( v6 & 1
    || BYTE1(v6) & 0x20
    || (v8 = *(float *)(a2 + 8) * *(float *)(a5 + 8)
           + *(float *)(a5 + 4) * *(float *)(a2 + 4)
           + *(float *)a2 * *(float *)a5,
        v8 == 0.0)
    || v8 > 0.0 )
    return 0;
  v9 = -(*(float *)(a5 + 4) * *(float *)(a1 + 4)
       + *(float *)a1 * *(float *)a5
       + *(float *)(a1 + 8) * *(float *)(a5 + 8)
       + *(float *)(a5 + 12));
  v14 = v9;
  if ( v8 <= 0.0 )
  {
    if ( v9 > 0.0 )
      return 0;
  }
  else
  {
    if ( v9 < 0.0 )
      return 0;
  }
  v10 = v14 / v8;
  v15 = v10;
  if ( v10 > *(float *)a3
    || (*(float *)a4 = v10 * *(float *)a2 + *(float *)a1,
        *(float *)(a4 + 4) = v10 * *(float *)(a2 + 4) + *(float *)(a1 + 4),
        v11 = v10 * *(float *)(a2 + 8) + *(float *)(a1 + 8),
        *(float *)(a4 + 8) = v11,
        LOWORD(v12) = (signed __int64)*(float *)a4,
        HIWORD(v12) = (signed __int64)*(float *)(a4 + 4),
        !sub_4C1D2B(v7, v12, (signed __int64)v11, a6)) )
    return 0;
  *(_DWORD *)a3 = LODWORD(v15);
  return 1;
}

//----- (004C1D2B) --------------------------------------------------------
signed int __stdcall sub_4C1D2B(int a1, signed int a2, __int16 a3, int a4)
{
  int v4; // esi@1
  bool v5; // edi@9
  int v6; // esi@9
  int v7; // edx@11
  int v8; // ecx@11
  int v9; // eax@12
  signed int v10; // ebx@13
  int v11; // edi@15
  signed int v12; // ST28_4@17
  signed __int64 v13; // qtt@17
  signed int result; // eax@20
  int v15; // [sp+10h] [bp-Ch]@9
  signed int v16; // [sp+18h] [bp-4h]@9

  v4 = a1;
  if ( a3 < *(_WORD *)(a1 + 88) )
    goto LABEL_24;
  if ( a3 > *(_WORD *)(a1 + 90) )
    goto LABEL_24;
  if ( (_WORD)a2 < *(_WORD *)(a1 + 80) )
    goto LABEL_24;
  compile_error;//if ( a2 < (signed int)__PAIR__(*(_WORD *)(a1 + 84), *(_WORD *)(a1 + 82)) )
    //goto LABEL_24;
  if ( HIWORD(a2) > *(_WORD *)(a1 + 86) )
    goto LABEL_24;
  if ( a4 == -1 )
    sub_4C1EE5((int)&a1, (int)&a4, (int)word_F8BC48, (int)word_F8BD18, (int)&a2, a1);
  else
    sub_4C2186((int)&a1, (int)&a4, (int)word_F8BC48, (int)word_F8BD18, (int)&a2, a1, a4);
  v6 = 2 * *(_BYTE *)(v4 + 93);
  v16 = 0;
  word_F8BC48[v6] = word_F8BC48[0];
  word_F8BD18[v6] = word_F8BD18[0];
  v15 = 0;
  v5 = word_F8BD18[0] >= a4;
  if ( v6 <= 0 )
    goto LABEL_24;
  do
  {
    if ( v16 >= 2 )
      break;
    v8 = 2 * v15;
    v7 = word_F8BD1A[v15];
    if ( v5 ^ v7 >= a4 )
    {
      v9 = *(__int16 *)((char *)&word_F8BC4A + v8);
      if ( v9 >= a1 )
        v10 = 0;
      else
        v10 = 2;
      v11 = v10 | *(__int16 *)((char *)word_F8BC48 + v8) < a1;
      if ( v11 != 3 )
      {
        if ( !v11
          || (v12 = v9 - *(__int16 *)((char *)word_F8BC48 + v8),
              LODWORD(v13) = v12 << 16,
              HIDWORD(v13) = v12 >> 16,
              *(__int16 *)((char *)word_F8BC48 + v8)
            + ((signed int)(((unsigned __int64)(v13
                                              / (v7 - *(__int16 *)((char *)word_F8BD18 + v8))
                                              * ((a4 - (signed int)*(__int16 *)((char *)word_F8BD18 + v8)) << 16)) >> 16)
                          + 32768) >> 16) >= a1) )
          ++v16;
      }
    }
    ++v15;
    v5 = v7 >= a4;
  }
  while ( v15 < v6 );
  result = 1;
  if ( v16 != 1 )
LABEL_24:
    result = 0;
  return result;
}

//----- (004C1EE5) --------------------------------------------------------
char __stdcall sub_4C1EE5(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // ecx@1
  int v7; // ecx@2
  int v8; // edx@3
  int v9; // ecx@4
  char v10; // zf@6
  int v11; // ecx@6
  int v12; // edx@7
  int v13; // edx@8
  int v14; // ecx@9
  int v15; // edx@11
  int v16; // edx@12
  int v17; // ecx@13
  int v19; // [sp+14h] [bp+8h]@3
  int v20; // [sp+14h] [bp+8h]@8
  int v21; // [sp+14h] [bp+8h]@12
  signed int v22; // [sp+24h] [bp+18h]@2
  signed int v23; // [sp+24h] [bp+18h]@7
  signed int v24; // [sp+24h] [bp+18h]@11

  v6 = *(_DWORD *)(a6 + 44);
  if ( BYTE1(v6) & 1 )
  {
    v7 = a5;
    v22 = 0;
    *(_DWORD *)a1 = *(_WORD *)v7;
    *(_DWORD *)a2 = *(_WORD *)(v7 + 2);
    if ( *(_BYTE *)(a6 + 93) )
    {
      v8 = a4 + 2;
      v19 = a3 - a4;
      do
      {
        v9 = 2 * v22;
        *(_WORD *)(a3 + 4 * v22) = *(_WORD *)(2 * v22 + *(_DWORD *)(a6 + 52))
                                 + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(2 * v22 + *(_DWORD *)(a6 + 48)));
        *(_WORD *)(v8 - 2) = *(_WORD *)(*(_DWORD *)(a6 + 56) + v9)
                           + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v9 + *(_DWORD *)(a6 + 48)) + 2);
        *(_WORD *)(v19 + v8) = *(_WORD *)(v9 + *(_DWORD *)(a6 + 52) + 2)
                             + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v9 + *(_DWORD *)(a6 + 48) + 2));
        ++v22;
        *(_WORD *)v8 = *(_WORD *)(v9 + *(_DWORD *)(a6 + 56) + 2)
                     + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v9 + *(_DWORD *)(a6 + 48) + 2) + 2);
        v8 += 4;
      }
      while ( v22 < *(_BYTE *)(a6 + 93) );
    }
  }
  else
  {
    v10 = (BYTE1(v6) & 2) == 0;
    v11 = a5;
    if ( v10 )
    {
      v15 = *(_WORD *)(a5 + 2);
      v24 = 0;
      *(_DWORD *)a1 = v15;
      *(_DWORD *)a2 = *(_WORD *)(v11 + 4);
      if ( *(_BYTE *)(a6 + 93) )
      {
        v16 = a4 + 2;
        v21 = a3 - a4;
        do
        {
          v17 = 2 * v24;
          *(_WORD *)(a3 + 4 * v24) = *(_WORD *)(2 * v24 + *(_DWORD *)(a6 + 56))
                                   + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(2 * v24 + *(_DWORD *)(a6 + 48)) + 2);
          *(_WORD *)(v16 - 2) = *(_WORD *)(*(_DWORD *)(a6 + 60) + v17)
                              + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v17 + *(_DWORD *)(a6 + 48)) + 4);
          *(_WORD *)(v21 + v16) = *(_WORD *)(*(_DWORD *)(a6 + 56) + v17 + 2)
                                + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v17 + *(_DWORD *)(a6 + 48) + 2) + 2);
          ++v24;
          *(_WORD *)v16 = *(_WORD *)(*(_DWORD *)(a6 + 60) + v17 + 2)
                        + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v17 + *(_DWORD *)(a6 + 48) + 2) + 4);
          v16 += 4;
        }
        while ( v24 < *(_BYTE *)(a6 + 93) );
      }
    }
    else
    {
      v12 = *(_WORD *)a5;
      v23 = 0;
      *(_DWORD *)a1 = v12;
      *(_DWORD *)a2 = *(_WORD *)(v11 + 4);
      if ( *(_BYTE *)(a6 + 93) )
      {
        v13 = a4 + 2;
        v20 = a3 - a4;
        do
        {
          v14 = 2 * v23;
          *(_WORD *)(a3 + 4 * v23) = *(_WORD *)(2 * v23 + *(_DWORD *)(a6 + 52))
                                   + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(2 * v23 + *(_DWORD *)(a6 + 48)));
          *(_WORD *)(v13 - 2) = *(_WORD *)(*(_DWORD *)(a6 + 60) + v14)
                              + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v14 + *(_DWORD *)(a6 + 48)) + 4);
          *(_WORD *)(v20 + v13) = *(_WORD *)(*(_DWORD *)(a6 + 52) + v14 + 2)
                                + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v14 + *(_DWORD *)(a6 + 48) + 2));
          ++v23;
          *(_WORD *)v13 = *(_WORD *)(*(_DWORD *)(a6 + 60) + v14 + 2)
                        + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v14 + *(_DWORD *)(a6 + 48) + 2) + 4);
          v13 += 4;
        }
        while ( v23 < *(_BYTE *)(a6 + 93) );
      }
    }
  }
  return 1;
}

//----- (004C2186) --------------------------------------------------------
char __stdcall sub_4C2186(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // ecx@1
  int v8; // esi@1
  int v9; // edx@3
  int v10; // ecx@4
  __int16 v11; // si@4
  int v12; // ecx@4
  int v13; // edx@8
  int v14; // ecx@9
  __int16 v15; // si@9
  int v16; // ecx@9
  int v17; // edx@12
  int v18; // ecx@13
  __int16 v19; // si@13
  int v20; // ecx@13
  signed int v22; // [sp+14h] [bp+8h]@1
  int v23; // [sp+18h] [bp+Ch]@3
  int v24; // [sp+18h] [bp+Ch]@8
  int v25; // [sp+18h] [bp+Ch]@12
  int v26; // [sp+24h] [bp+18h]@3
  int v27; // [sp+24h] [bp+18h]@8
  int v28; // [sp+24h] [bp+18h]@12

  v8 = a1;
  v7 = *(_DWORD *)(a6 + 44);
  v22 = 0;
  if ( BYTE1(v7) & 1 )
  {
    *(_DWORD *)v8 = *(_WORD *)a5;
    *(_DWORD *)a2 = *(_WORD *)(a5 + 2);
    if ( *(_BYTE *)(a6 + 93) )
    {
      v9 = 188 * a7 + 72;
      v26 = a4 + 2;
      v23 = a3 - a4;
      do
      {
        v10 = 2 * v22;
        *(_WORD *)(a3 + 4 * v22) = *(_WORD *)(*(_DWORD *)(a6 + 52) + 2 * v22)
                                 + *(_WORD *)(*(_DWORD *)(v9 + pClass51_global->pBModels)
                                            + 12 * *(_WORD *)(2 * v22 + *(_DWORD *)(a6 + 48)));
        *(_WORD *)(v26 - 2) = *(_WORD *)(*(_DWORD *)(a6 + 56) + v10)
                            + *(_WORD *)(*(_DWORD *)(v9 + pClass51_global->pBModels) + 12 * *(_WORD *)(v10 + *(_DWORD *)(a6 + 48)) + 4);
        *(_WORD *)(v23 + v26) = *(_WORD *)(v10 + *(_DWORD *)(a6 + 52) + 2)
                              + *(_WORD *)(*(_DWORD *)(v9 + pClass51_global->pBModels)
                                         + 12 * *(_WORD *)(v10 + *(_DWORD *)(a6 + 48) + 2));
        v11 = *(_WORD *)(v10 + *(_DWORD *)(a6 + 56) + 2)
            + *(_WORD *)(*(_DWORD *)(v9 + pClass51_global->pBModels) + 12 * *(_WORD *)(v10 + *(_DWORD *)(a6 + 48) + 2) + 4);
        v12 = v26;
        ++v22;
        v26 += 4;
        *(_WORD *)v12 = v11;
      }
      while ( v22 < *(_BYTE *)(a6 + 93) );
    }
  }
  else
  {
    if ( BYTE1(v7) & 2 )
    {
      *(_DWORD *)v8 = *(_WORD *)a5;
      *(_DWORD *)a2 = *(_WORD *)(a5 + 4);
      if ( *(_BYTE *)(a6 + 93) )
      {
        v13 = 188 * a7 + 72;
        v27 = a4 + 2;
        v24 = a3 - a4;
        do
        {
          v14 = 2 * v22;
          *(_WORD *)(a3 + 4 * v22) = *(_WORD *)(2 * v22 + *(_DWORD *)(a6 + 52))
                                   + *(_WORD *)(*(_DWORD *)(v13 + pClass51_global->pBModels)
                                              + 12 * *(_WORD *)(2 * v22 + *(_DWORD *)(a6 + 48)));
          *(_WORD *)(v27 - 2) = *(_WORD *)(v14 + *(_DWORD *)(a6 + 60))
                              + *(_WORD *)(*(_DWORD *)(v13 + pClass51_global->pBModels)
                                         + 12 * *(_WORD *)(v14 + *(_DWORD *)(a6 + 48))
                                         + 8);
          *(_WORD *)(v24 + v27) = *(_WORD *)(*(_DWORD *)(a6 + 52) + v14 + 2)
                                + *(_WORD *)(*(_DWORD *)(v13 + pClass51_global->pBModels)
                                           + 12 * *(_WORD *)(v14 + *(_DWORD *)(a6 + 48) + 2));
          v15 = *(_WORD *)(v14 + *(_DWORD *)(a6 + 60) + 2)
              + *(_WORD *)(*(_DWORD *)(v13 + pClass51_global->pBModels) + 12 * *(_WORD *)(v14 + *(_DWORD *)(a6 + 48) + 2) + 8);
          v16 = v27;
          ++v22;
          v27 += 4;
          *(_WORD *)v16 = v15;
        }
        while ( v22 < *(_BYTE *)(a6 + 93) );
      }
    }
    else
    {
      *(_DWORD *)v8 = *(_WORD *)(a5 + 2);
      *(_DWORD *)a2 = *(_WORD *)(a5 + 4);
      if ( *(_BYTE *)(a6 + 93) )
      {
        v17 = 188 * a7 + 72;
        v28 = a4 + 2;
        v25 = a3 - a4;
        do
        {
          v18 = 2 * v22;
          *(_WORD *)(a3 + 4 * v22) = *(_WORD *)(*(_DWORD *)(a6 + 56) + 2 * v22)
                                   + *(_WORD *)(*(_DWORD *)(v17 + pClass51_global->pBModels)
                                              + 12 * *(_WORD *)(2 * v22 + *(_DWORD *)(a6 + 48))
                                              + 4);
          *(_WORD *)(v28 - 2) = *(_WORD *)(v18 + *(_DWORD *)(a6 + 60))
                              + *(_WORD *)(*(_DWORD *)(v17 + pClass51_global->pBModels)
                                         + 12 * *(_WORD *)(v18 + *(_DWORD *)(a6 + 48))
                                         + 8);
          *(_WORD *)(v25 + v28) = *(_WORD *)(*(_DWORD *)(a6 + 56) + v18 + 2)
                                + *(_WORD *)(*(_DWORD *)(v17 + pClass51_global->pBModels)
                                           + 12 * *(_WORD *)(v18 + *(_DWORD *)(a6 + 48) + 2)
                                           + 4);
          v19 = *(_WORD *)(v18 + *(_DWORD *)(a6 + 60) + 2)
              + *(_WORD *)(*(_DWORD *)(v17 + pClass51_global->pBModels) + 12 * *(_WORD *)(v18 + *(_DWORD *)(a6 + 48) + 2) + 8);
          v20 = v28;
          ++v22;
          v28 += 4;
          *(_WORD *)v20 = v19;
        }
        while ( v22 < *(_BYTE *)(a6 + 93) );
      }
    }
  }
  return 1;
}

//----- (004C248E) --------------------------------------------------------
int __stdcall sub_4C248E(int a1, signed int a2, float a3, float a4)
{
  int result; // eax@1
  int v5; // ebx@1
  int v6; // edi@1
  int v7; // esi@1
  int v8; // ST10_4@1
  int v9; // ST04_4@1
  int v10; // eax@1
  float v11; // [sp+2Ch] [bp-74h]@1
  float v12; // [sp+30h] [bp-70h]@1
  float v13; // [sp+34h] [bp-6Ch]@1
  float v14; // [sp+58h] [bp-48h]@1
  float v15; // [sp+5Ch] [bp-44h]@1
  float v16; // [sp+60h] [bp-40h]@1
  float v17; // [sp+64h] [bp-3Ch]@1
  float v18; // [sp+88h] [bp-18h]@1
  int v19; // [sp+8Ch] [bp-14h]@1
  int v20; // [sp+90h] [bp-10h]@1
  int v21; // [sp+94h] [bp-Ch]@1
  int v22; // [sp+98h] [bp-8h]@1
  int v23; // [sp+9Ch] [bp-4h]@1

  v5 = pCamera->dword_000004;
  v6 = pCamera->dword_000000;
  v20 = pCamera->dword_000000;
  v19 = pCamera->dword_000004;
  v23 = pCamera->dword_000008;
  v7 = pCamera->sRotationY + sub_46A0A1((void *)(signed __int64)*(float *)&a2);
  v8 = v23;
  v9 = pCamera->sRotationX + sub_46A0F6((void *)(signed __int64)a3);
  v10 = sub_48B561(a4);
  sub_43AA99(v10, v7, v9, v6, v5, v8, (int)&a2, (int)&v22, (int)&v21);
  result = a1;
  v14 = 0.0;
  v11 = (double)a2;
  v12 = (double)v22;
  v13 = (double)v21;
  v18 = 0.0;
  v15 = (double)v20;
  v16 = (double)v19;
  v17 = (double)v23;
  memcpy((void *)a1, &v15, 0x30u);
  memcpy((void *)(a1 + 48), &v11, 0x30u);
  return result;
}

//----- (004C2551) --------------------------------------------------------
int __thiscall sub_4C2551(int this, int a2, int a3)
{
  int v3; // edx@1
  int v4; // esi@1
  int v5; // eax@2
  int result; // eax@6

  v4 = *(_DWORD *)(this + 8196);
  v3 = 0;
  if ( v4 <= 0 )
  {
LABEL_6:
    result = 0;
  }
  else
  {
    v5 = this + 8;
    while ( *(_DWORD *)(v5 + 4) != a2 || (*(_DWORD *)v5 & 0xFFFF) != a3 )
    {
      ++v3;
      v5 += 12;
      if ( v3 >= v4 )
        goto LABEL_6;
    }
    result = this + 12 * v3 + 4;
  }
  return result;
}

//----- (004C2591) --------------------------------------------------------
void *__thiscall sub_4C2591(int this, int a2)
{
  void *result; // eax@1
  int v3; // esi@2
  int v4; // edx@3
  unsigned __int8 v5; // zf@7
  unsigned __int8 v6; // sf@7
  int v7; // ebx@8
  int v8; // esi@8
  signed int v9; // edi@9
  int v10; // edx@10
  char v11; // [sp-18h] [bp-28h]@19
  int v12; // [sp-14h] [bp-24h]@19
  int v13; // [sp-10h] [bp-20h]@19
  int v14; // [sp-Ch] [bp-1Ch]@19
  const char *v15; // [sp-8h] [bp-18h]@19
  int v16; // [sp-4h] [bp-14h]@19
  char v17; // [sp+Ch] [bp-4h]@19
  char *v18; // [sp+18h] [bp+8h]@19

  result = 0;
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      v5 = *(_DWORD *)(this + 8196) == 0;
      v6 = *(_DWORD *)(this + 8196) < 0;
      BYTE3(a2) = 1;
      if ( !(v6 | v5) )
      {
        v7 = this + 6148;
        v8 = this + 4;
        do
        {
          v9 = 0;
          if ( (signed int)result > 0 )
          {
            v10 = this + 6148;
            while ( *(_DWORD *)v10 != v8 )
            {
              ++v9;
              v10 += 4;
              if ( v9 >= (signed int)result )
                goto LABEL_15;
            }
            BYTE3(a2) = 0;
          }
LABEL_15:
          if ( BYTE3(a2) )
            *(_DWORD *)v7 = v8;
          result = (char *)result + 1;
          v7 += 4;
          v8 += 12;
        }
        while ( (signed int)result < *(_DWORD *)(this + 8196) );
      }
    }
    else
    {
      v16 = 1358;
      v15 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Vis.cpp";
      v18 = &v11;
      sub_40E2C8(&v11, "Unknown pointer creation flag passed to ::create_object_pointers()", (int)((char *)&a2 + 3));
      result = sub_466D09(&v17, *(int *)&v11, v12, v13, v14, v15, v16);
    }
  }
  else
  {
    v3 = 0;
    if ( *(_DWORD *)(this + 8196) > 0 )
    {
      result = (void *)(this + 6148);
      v4 = this + 4;
      do
      {
        *(_DWORD *)result = v4;
        ++v3;
        result = (char *)result + 4;
        v4 += 12;
      }
      while ( v3 < *(_DWORD *)(this + 8196) );
    }
  }
  return result;
}

//----- (004C264A) --------------------------------------------------------
function_error;//int __userpurge sub_4C264A<eax>(int result<eax>, int a2, int a3, int a4)
int sub_4C264A(int result, int a2, int a3, int a4)
{
  int v4; // edx@1
  int v5; // ebx@1
  signed int i; // ecx@2
  int v7; // esi@2
  unsigned int v8; // eax@3
  unsigned int v9; // ebx@4
  unsigned int v10; // ebx@6
  int v11; // eax@7
  int v12; // [sp+14h] [bp+Ch]@2

  v4 = a3;
  v5 = a4;
  if ( a4 > a3 )
  {
    do
    {
      v7 = v4 - 1;
      v12 = *(_DWORD *)(a2 + 4 * v5);
      for ( i = v5; ; *(_DWORD *)(a2 + 4 * i) = v11 )
      {
        v8 = *(_DWORD *)(v12 + 4);
        LOWORD(v8) = 0;
        do
        {
          ++v7;
          v9 = *(_DWORD *)(*(_DWORD *)(a2 + 4 * v7) + 4);
          LOWORD(v9) = 0;
        }
        while ( v9 < v8 );
        do
        {
          if ( i < 1 )
            break;
          --i;
          v10 = *(_DWORD *)(*(_DWORD *)(a2 + 4 * i) + 4);
          LOWORD(v10) = 0;
        }
        while ( v10 > v8 );
        v11 = *(_DWORD *)(a2 + 4 * v7);
        if ( v7 >= i )
          break;
        *(_DWORD *)(a2 + 4 * v7) = *(_DWORD *)(a2 + 4 * i);
      }
      v5 = a4;
      *(_DWORD *)(a2 + 4 * v7) = *(_DWORD *)(a2 + 4 * a4);
      *(_DWORD *)(a2 + 4 * a4) = v11;
      compile_error;//result = sub_4C264A(a2, v4, v7 - 1);
      v4 = v7 + 1;
    }
    while ( a4 > v7 + 1 );
  }
  return result;
}

//----- (004C26D0) --------------------------------------------------------
char __thiscall sub_4C26D0(void *this, int a2, int a3, int a4)
{
  int v4; // edx@2
  int v5; // ebx@2
  void *v6; // edi@2
  const void *v7; // esi@2
  int v8; // ecx@3
  int v9; // ecx@5
  const void *v10; // eax@8
  char v12; // [sp+4h] [bp-4Ch]@8
  float v13; // [sp+24h] [bp-2Ch]@2
  void *v14; // [sp+44h] [bp-Ch]@1
  const void *v15; // [sp+48h] [bp-8h]@2
  int v16; // [sp+4Ch] [bp-4h]@2

  v14 = this;
  if ( a4 > a3 )
  {
    v4 = a2;
    v7 = (const void *)(32 * a4 + a2);
    v6 = &v13;
    v15 = (const void *)(32 * a4 + a2);
    v5 = a3 - 1;
    v16 = a4;
    while ( 1 )
    {
      memcpy(v6, v7, 0x20u);
      v8 = v4 + 32 * v5;
      do
      {
        v8 += 32;
        ++v5;
      }
      while ( *(float *)v8 < (double)v13 );
      v9 = v4 + 32 * v16;
      do
      {
        v9 -= 32;
        --v16;
      }
      while ( *(float *)v9 > (double)v13 );
      if ( v5 >= v16 )
        break;
      v10 = (const void *)(v4 + 32 * v16);
      memcpy(&v12, (const void *)(a2 + 32 * v5), 0x20u);
      v4 = a2;
      memcpy((void *)(a2 + 32 * v5), v10, 0x20u);
      v7 = &v12;
      v6 = (void *)v10;
    }
    memcpy(&v12, (const void *)(v4 + 32 * v5), 0x20u);
    memcpy((void *)(v4 + 32 * v5), v15, 0x20u);
    memcpy((void *)v15, &v12, 0x20u);
    sub_4C26D0(this, v4, a3, v5 - 1);
    sub_4C26D0(this, a2, v5 + 1, a4);
  }
  return 1;
}

//----- (004C27AD) --------------------------------------------------------
char __thiscall sub_4C27AD(void *this, int a2, int a3, int a4)
{
  int v4; // edx@2
  int v5; // ebx@2
  void *v6; // edi@2
  const void *v7; // esi@2
  int v8; // ecx@3
  int v9; // ecx@5
  const void *v10; // eax@8
  char v12; // [sp+4h] [bp-4Ch]@8
  char v13; // [sp+24h] [bp-2Ch]@2
  float v14; // [sp+28h] [bp-28h]@4
  void *v15; // [sp+44h] [bp-Ch]@1
  const void *v16; // [sp+48h] [bp-8h]@2
  int v17; // [sp+4Ch] [bp-4h]@2

  v15 = this;
  if ( a4 > a3 )
  {
    v4 = a2;
    v7 = (const void *)(32 * a4 + a2);
    v6 = &v13;
    v16 = (const void *)(32 * a4 + a2);
    v5 = a3 - 1;
    v17 = a4;
    while ( 1 )
    {
      memcpy(v6, v7, 0x20u);
      v8 = 32 * v5 + v4 + 4;
      do
      {
        v8 += 32;
        ++v5;
      }
      while ( *(float *)v8 < (double)v14 );
      v9 = 32 * v17 + v4 + 4;
      do
      {
        v9 -= 32;
        --v17;
      }
      while ( *(float *)v9 > (double)v14 );
      if ( v5 >= v17 )
        break;
      v10 = (const void *)(v4 + 32 * v17);
      memcpy(&v12, (const void *)(a2 + 32 * v5), 0x20u);
      v4 = a2;
      memcpy((void *)(a2 + 32 * v5), v10, 0x20u);
      v7 = &v12;
      v6 = (void *)v10;
    }
    memcpy(&v12, (const void *)(v4 + 32 * v5), 0x20u);
    memcpy((void *)(v4 + 32 * v5), v16, 0x20u);
    memcpy((void *)v16, &v12, 0x20u);
    sub_4C27AD(this, v4, a3, v5 - 1);
    sub_4C27AD(this, a2, v5 + 1, a4);
  }
  return 1;
}

//----- (004C288E) --------------------------------------------------------
char __thiscall sub_4C288E(void *this, int a2, int a3, int a4)
{
  int v4; // edx@2
  int i; // ecx@2
  int v6; // ebx@2
  int v7; // esi@3
  int v8; // esi@5
  const void *v9; // eax@8
  char v11; // [sp+4h] [bp-6Ch]@8
  char v12; // [sp+34h] [bp-3Ch]@2
  float v13; // [sp+4Ch] [bp-24h]@4
  int v14; // [sp+64h] [bp-Ch]@7
  void *v15; // [sp+68h] [bp-8h]@1
  const void *v16; // [sp+6Ch] [bp-4h]@2

  v15 = this;
  if ( a4 > a3 )
  {
    v4 = a2;
    v16 = (const void *)(48 * a4 + a2);
    v6 = a3 - 1;
    memcpy(&v12, (const void *)(48 * a4 + a2), 0x30u);
    for ( i = a4; ; i = v14 )
    {
      v7 = 48 * v6 + v4 + 24;
      do
      {
        v7 += 48;
        ++v6;
      }
      while ( *(float *)v7 < (double)v13 );
      v8 = 48 * i + v4 + 24;
      do
      {
        v8 -= 48;
        --i;
      }
      while ( *(float *)v8 > (double)v13 );
      v14 = i;
      if ( v6 >= i )
        break;
      v9 = (const void *)(v4 + 48 * i);
      memcpy(&v11, (const void *)(a2 + 48 * v6), 0x30u);
      v4 = a2;
      memcpy((void *)(a2 + 48 * v6), v9, 0x30u);
      memcpy((void *)v9, &v11, 0x30u);
    }
    memcpy(&v11, (const void *)(v4 + 48 * v6), 0x30u);
    memcpy((void *)(v4 + 48 * v6), v16, 0x30u);
    memcpy((void *)v16, &v11, 0x30u);
    sub_4C288E(this, v4, a3, v6 - 1);
    sub_4C288E(this, a2, v6 + 1, a4);
  }
  return 1;
}

//----- (004C297E) --------------------------------------------------------
char __thiscall sub_4C297E(void *this, int a2, int a3, int a4)
{
  int v4; // edx@2
  int i; // ecx@2
  int v6; // ebx@2
  int v7; // esi@3
  int v8; // esi@5
  const void *v9; // eax@8
  char v11; // [sp+4h] [bp-6Ch]@8
  char v12; // [sp+34h] [bp-3Ch]@2
  float v13; // [sp+50h] [bp-20h]@4
  int v14; // [sp+64h] [bp-Ch]@7
  void *v15; // [sp+68h] [bp-8h]@1
  const void *v16; // [sp+6Ch] [bp-4h]@2

  v15 = this;
  if ( a4 > a3 )
  {
    v4 = a2;
    v16 = (const void *)(48 * a4 + a2);
    v6 = a3 - 1;
    memcpy(&v12, (const void *)(48 * a4 + a2), 0x30u);
    for ( i = a4; ; i = v14 )
    {
      v7 = 48 * v6 + v4 + 28;
      do
      {
        v7 += 48;
        ++v6;
      }
      while ( *(float *)v7 < (double)v13 );
      v8 = 48 * i + v4 + 28;
      do
      {
        v8 -= 48;
        --i;
      }
      while ( *(float *)v8 > (double)v13 );
      v14 = i;
      if ( v6 >= i )
        break;
      v9 = (const void *)(v4 + 48 * i);
      memcpy(&v11, (const void *)(a2 + 48 * v6), 0x30u);
      v4 = a2;
      memcpy((void *)(a2 + 48 * v6), v9, 0x30u);
      memcpy((void *)v9, &v11, 0x30u);
    }
    memcpy(&v11, (const void *)(v4 + 48 * v6), 0x30u);
    memcpy((void *)(v4 + 48 * v6), v16, 0x30u);
    memcpy((void *)v16, &v11, 0x30u);
    sub_4C297E(this, v4, a3, v6 - 1);
    sub_4C297E(this, a2, v6 + 1, a4);
  }
  return 1;
}

//----- (004C2F0B) --------------------------------------------------------
signed int sub_4C2F0B(struct unnamed_6BD080 *_this, __int16 a2)
{
  int v3; // edx@3
  signed int v4; // ebx@3
  int v5; // esi@3
  int v6; // eax@5
  int v7; // edi@5
  int v8; // [sp+0h] [bp-Ch]@3
  int v9; // [sp+4h] [bp-8h]@3
  int v10; // [sp+8h] [bp-4h]@1

  v10 = _this;
  if ( *(_DWORD *)(v10 + 4004) != 1 )
    return 0;
  HIWORD(v3) = HIWORD(struct_576FE8.dword_000010);
  v4 = 0;
  v5 = struct_576FE8.dword_000018 - struct_576FE8.dword_000010;
  v8 = struct_576FE8.dword_000010;
  v9 = struct_576FE8.dword_000018 - 4;
  while ( 1 )
  {
    v6 = v10 + 4 * v4;
    *(_WORD *)v6 += a2;
    LOWORD(v3) = *(_WORD *)v6;
    v7 = *(_WORD *)v6;
    if ( v7 < v9 )
    {
      if ( v7 >= v8 )
        goto LABEL_10;
      v3 += v5;
    }
    else
    {
      v3 = v3 - v5 + 4;
    }
    *(_WORD *)v6 = v3;
LABEL_10:
    ++v4;
    if ( v4 >= 1000 )
      return 1;
  }
}

//----- (004C9BB9) --------------------------------------------------------
void __cdecl sub_4C9BB9(LPCRITICAL_SECTION lpCriticalSection)
{
  DeleteCriticalSection(lpCriticalSection);
}

//----- (004C9BC4) --------------------------------------------------------
void __cdecl sub_4C9BC4(LPCRITICAL_SECTION lpCriticalSection)
{
  EnterCriticalSection(lpCriticalSection);
}

//----- (004C9BCF) --------------------------------------------------------
void __cdecl sub_4C9BCF(LPCRITICAL_SECTION lpCriticalSection)
{
  LeaveCriticalSection(lpCriticalSection);
}

//----- (004CA32D) --------------------------------------------------------
int operator_delete(int a1, unsigned int a2)
{
  return call_delete(a1, a2);
}

//----- (004CA338) --------------------------------------------------------
void __cdecl sub_4CA338()
{
  size_t v0; // eax@1
  int v1; // [sp+4h] [bp-3Ch]@1
  char v2; // [sp+20h] [bp-20h]@1
  char v3; // [sp+33h] [bp-Dh]@1
  int v4; // [sp+3Ch] [bp-4h]@1

  v2 = v3;
  CGame_stru0_sub_40E2F6((int)&v2, 0);
  v0 = strlen(&byte_4D8410[11380]);
  sub_40E32E((int)&v2, &byte_4D8410[11380], v0);
  v4 = 0;
  sub_4CA392(&v1, (int)&v2);
  v1 = 5091448;
  _CxxThrowException(&v1, 5096840);
}

//----- (004CA392) --------------------------------------------------------
void *__thiscall sub_4CA392(void *this, int a2)
{
  void *v3; // esi@1
  int v4; // [sp+4h] [bp-10h]@1
  int v5; // [sp+10h] [bp-4h]@1

  v3 = this;
  v4 = (int)Class;
  exception__exception(&v4);
  v5 = 0;
  *((_BYTE *)v3 + 12) = *(_BYTE *)a2;
  CGame_stru0_sub_40E2F6((int)((char *)v3 + 12), 0);
  sub_4679E2((int)((char *)v3 + 12), a2, 0, *(size_t *)&byte_4D8410[11412]);
  *(_DWORD *)v3 = 5091480;
  return v3;
}

//----- (004CA479) --------------------------------------------------------
void *__thiscall sub_4CA479(void *this, int a2)
{
  void *v3; // esi@1

  v3 = this;
  exception__exception(a2);
  *((_BYTE *)v3 + 12) = *(_BYTE *)(a2 + 12);
  CGame_stru0_sub_40E2F6((int)((char *)v3 + 12), 0);
  sub_4679E2((int)((char *)v3 + 12), a2 + 12, 0, *(size_t *)&byte_4D8410[11412]);
  *(_DWORD *)v3 = 5091480;
  return v3;
}

//----- (004CA54C) --------------------------------------------------------
void *__thiscall sub_4CA54C(void *this, int a2)
{
  void *v3; // esi@1

  v3 = this;
  sub_4CA479(this, a2);
  *(_DWORD *)v3 = 5091448;
  return v3;
}