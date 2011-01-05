#include <ddraw.h>
//#include <dinput.h>
#include "localization_defs.h"
#include "data.h"
#include "AudioPlayer.h"
#include "VideoPlayer.h"
#include "FrameTables.h"
#include "UserInput.h"

#include "GUI\GUI.h"

#include "Environment\Outdoor.h"
#include "Actor.h"
  #include "_lod.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "Game.h"

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
    if ( a1 < pIndoor->uNumFaces )
    {
      v3 = (int)&pIndoor->pFaces[a1];
      v91 = (int)&pIndoor->pFaces[a1];
      if ( !pD3DRenderer->pRenderD3D3 )
      {
        result = sub_423B5D(a1);
        if ( result )
        {
          result = sub_424829(result, (int)&dword_F8A590, stru_51B6E0.dword_00007C, v2);
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
              ++stru_51B6E0.dword_000084;
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
              v104 = 2 * stru_51B6E0.dword_000000;
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
                    v15 = v95 * (v12 - stru_51B6E0.uViewportY);
                    v119 = (int)stru_51B6E0.pZTarget + 4
                         * (2 * (*(__int16 *)((char *)word_F8A5A8 + v12) + 320 * (v12 - stru_51B6E0.uViewportY)) - stru_51B6E0.uViewportX);
                    v16 = (int)stru_51B6E0.pRenderTarget + 4 * (v15 + 2 * *(__int16 *)((char *)word_F8A5A8 + v12) - stru_51B6E0.uViewportX);
                    v13 = (int)stru_51B6E0.pRenderTarget + 4 * (v15 + 2 * *(__int16 *)((char *)word_F8A968 + v12) - stru_51B6E0.uViewportX);
                    v123 = v16;
                  }
                  else
                  {
                    v14 = *(__int16 *)((char *)word_F8A5A8 + v12);
                    v119 = (int)stru_51B6E0.pZTarget + 4 * (v14 + v99);
                    v123 = (int)stru_51B6E0.pRenderTarget + 4 * (v14 + v11);
                    v13 = (int)stru_51B6E0.pRenderTarget + 4 *(v11 + *(__int16 *)((char *)word_F8A968 + v12));
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
                  v17 = (int)pClass59_global;
                  v122 = (char *)v21;
                  v121 = (unk_F8101C >> i) + 4 * class59_SinCos(pClass59_global, v104 + v22);
                  v23 = class59_SinCos(pClass59_global, v104 + (v20 >> (char)v122) - pClass59_global->uIntegerHalfPi);
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
                      v116 = v31 + 4 * class59_SinCos((class59 *)v17, v104 + (v32 >> (11 - v28)));
                      v90 = v32 + 4 * class59_SinCos((class59 *)v17, v104 + (v31 >> (char)v122) - pClass59_global->uIntegerHalfPi);
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
                      v17 = (int)pClass59_global;
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
    if ( a1 < pIndoor->uNumFaces )
    {
      v2 = (int)&pIndoor->pFaces[a1];
      if ( pD3DRenderer->pRenderD3D3 )
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
        if ( pD3DRenderer->pRenderD3D3 || sub_424829(v3, (int)&dword_F8A590, stru_51B6E0.dword_00007C, v1) )
        {
          v5 = sub_4AE5BA(v2);
          v4 = 0;
          if ( v5 )
          {
            if ( pD3DRenderer->pRenderD3D3 )
            {
              if ( v3 > 0 )
              {
                v57 = v3;
                v46 = v3;
                v6 = (char *)&array_507D30[0].v;
                do
                {
                  *((float *)v6 - 1) = (double)((GetTickCount() >> 5) - stru_51B6E0.vPosition.x) + *((float *)v6 - 1);
                  *(float *)v6 = (double)(stru_51B6E0.vPosition.y + (GetTickCount() >> 5)) + *(float *)v6;
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
                v9 = TextureFrameTable_GetFrame(pTextureFrameTable, *(_WORD *)(v2 + 74), stru_51B6E0.dword_000000);
              }
              else
              {
                v43 = sub_4AE5BA(v2);
                v9 = *(_WORD *)(v2 + 74);
              }
              Render_sub_4A2FC0((int)pD3DRenderer, v3, v2, (int)LODFile_Bitmaps_LOD.pHardwareTextures[v9], v43, v44, -1, 0);
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
              ++stru_51B6E0.dword_000080;
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
                  *v15 += (GetTickCount() << 11) - (stru_51B6E0.vPosition.x << 16);
                  v17 = GetTickCount();
                  v18 = *v15;
                  v15[1] += (32 * stru_51B6E0.vPosition.y + v17) << 11;
                  v48 = v15[1] >> 3;
                  v47 = v18 >> 3;
                  v19 = (signed int)((unsigned __int64)(stru_51B6E0.dword_000044 * v15[10]) >> 16) >> 3;
                  v55 = (unsigned __int64)(v19 * -stru_51B6E0.sSineY) >> 16;
                  v56 = (unsigned __int64)(v19 * stru_51B6E0.sCosineY) >> 16;
                  v20 = v15[10];
                  v16 = *(__int16 *)((char *)word_F8A5A8 + v14);
                  LOWORD(v20) = 0;
                  v49 = dword_F8AD28 | v20;
                  v64 = *(__int16 *)((char *)word_F8A968 + v14) - v16;
                  if (struct_576FE8.dword_000020)
                  {
                    v66 = (int)stru_51B6E0.pZTarget + 4 * (2 * (v16 + 320 * (v14 - stru_51B6E0.uViewportY)) - stru_51B6E0.uViewportX);
                    v34 = v47;
                    v33 = v48;
                    v32 = (int)stru_51B6E0.pRenderTarget + 4 * (v45 * (v14 - stru_51B6E0.uViewportY) + 2 * v16 - stru_51B6E0.uViewportX);
                    if ( v64 & 1 )
                    {
                      --v64;
                      v32 = (int)stru_51B6E0.pRenderTarget + 4 * (v45 * (v14 - stru_51B6E0.uViewportY) + 2 * v16 - stru_51B6E0.uViewportX) - 4;
                      v36 = (int)stru_51B6E0.pZTarget + 4 * (2 * (v16 + 320 * (v14 - stru_51B6E0.uViewportY)) - stru_51B6E0.uViewportX);
                      v35 = v49;
                      v66 += 8;
                      goto LABEL_32;
                    }
                    while ( 1 )
                    {
                      compile_error();//v42 = __SETO__(v64, 2);
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
                    v61 = (int)stru_51B6E0.pRenderTarget + 4 * (v16 + v10 * pD3DRenderer->uTargetSurfacePitch);
                    v65 = (int)stru_51B6E0.pZTarget + 4 * (v59 + v16);
                    v23 = v47;
                    v22 = v48;
                    v21 = v61;
                    if ( v64 & 1 )
                    {
                      --v64;
                      v21 = v61 - 2;
                      v25 = (int)stru_51B6E0.pZTarget + 4 * (v59 + v16);
                      v24 = v49;
                      v65 += 4;
                      goto LABEL_26;
                    }
                    while ( 1 )
                    {
                      compile_error();//v31 = __SETO__(v64, 2);
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

  v3 = stru_51B6E0.dword_000078 - a3;
  v4 = stru_51B6E0.dword_000074 - a2;
  v6 = (stru_51B6E0.dword_000074 - a2) * dword_F8ADA8;
  v14 = a1;
  v7 = (stru_51B6E0.dword_000078 - a3) * dword_F8ADAC + dword_F8ADA4;
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
  dword_F83B80[14 * v14 + 1] = v13;
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

  v3 = stru_51B6E0.dword_000078 - a2;
  v4 = stru_51B6E0.dword_000074 - a1;
  ++stru_51B6E0.dword_000088;
  v6 = (stru_51B6E0.dword_000078 - a2) * dword_F8ADAC + dword_F8ADA4;
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
  result = abs((int)((unsigned __int64)(stru_51B6E0.dword_000044 * v8) >> 16));
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
  ++stru_51B6E0.dword_00008C;
  return v17;
}

//----- (004AE5BA) --------------------------------------------------------
int __thiscall sub_4AE5BA(int _this)
{
  int v1; // ecx@2

  if ( *(_BYTE *)(_this + 45) & 0x40 )
    v1 = TextureFrameTable_GetFrame(pTextureFrameTable, *(_WORD *)(_this + 74), stru_51B6E0.dword_000000);
  else
    v1 = *(_WORD *)(_this + 74);
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

  v5 = (int)&pIndoor->pFaces[a1];
  v3 = (int)pIndoor->pFaceExtras + 36 * *(_WORD *)(v5 + 72);
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
  sub_498A41((BLVFace *)v5, (Vec3<int> *)&v72, (Vec3<int> *)&v69);
  dword_F8AD3C = v72;
  dword_F8AD40 = v73;
  dword_F8AD44 = v74;
  dword_F8AD48 = v69;
  dword_F8AD4C = v70;
  dword_F8AD50 = v71;
  dword_F8B120 = *(_WORD *)(v3 + 34);
  if ( stru_51B6E0.sRotationX )
  {
    v81 = (unsigned __int64)(dword_F8AD30 * stru_51B6E0.sSineY) >> 16;
    v81 = ((unsigned __int64)(dword_F8AD2C * stru_51B6E0.sCosineY) >> 16) - v81;
    X = (unsigned __int64)(dword_F8AD34 * stru_51B6E0.sSineMinusX) >> 16;
    dword_F8AD7C = ((unsigned __int64)(v81 * stru_51B6E0.sCosineMinusX) >> 16) - X;
    dword_F8AD80 = ((unsigned __int64)(dword_F8AD2C * stru_51B6E0.sSineY) >> 16)
                 + ((unsigned __int64)(dword_F8AD30 * stru_51B6E0.sCosineY) >> 16);
    dword_F8AD84 = ((unsigned __int64)(v81 * stru_51B6E0.sSineMinusX) >> 16)
                 + ((unsigned __int64)(dword_F8AD34 * stru_51B6E0.sCosineMinusX) >> 16);
    v77 = (unsigned __int64)(dword_F8AD40 * stru_51B6E0.sSineY) >> 16;
    v81 = ((unsigned __int64)(dword_F8AD3C * stru_51B6E0.sCosineY) >> 16) - v77;
    v77 = (unsigned __int64)(dword_F8AD44 * stru_51B6E0.sSineMinusX) >> 16;
    dword_F8AD8C = ((unsigned __int64)(v81 * stru_51B6E0.sCosineMinusX) >> 16) - v77;
    dword_F8AD90 = ((unsigned __int64)(dword_F8AD3C * stru_51B6E0.sSineY) >> 16)
                 + ((unsigned __int64)(dword_F8AD40 * stru_51B6E0.sCosineY) >> 16);
    dword_F8AD94 = ((unsigned __int64)(v81 * stru_51B6E0.sSineMinusX) >> 16)
                 + ((unsigned __int64)(dword_F8AD44 * stru_51B6E0.sCosineMinusX) >> 16);
    v77 = (unsigned __int64)(dword_F8AD4C * stru_51B6E0.sSineY) >> 16;
    v81 = ((unsigned __int64)(dword_F8AD48 * stru_51B6E0.sCosineY) >> 16) - v77;
    X = (unsigned __int64)(dword_F8AD48 * stru_51B6E0.sSineY) >> 16;
    v79 = (unsigned __int64)(dword_F8AD4C * stru_51B6E0.sCosineY) >> 16;
    v77 = (unsigned __int64)(dword_F8AD50 * stru_51B6E0.sSineMinusX) >> 16;
    dword_F8AD98 = ((unsigned __int64)(v81 * stru_51B6E0.sCosineMinusX) >> 16) - v77;
    dword_F8AD9C = ((unsigned __int64)(dword_F8AD48 * stru_51B6E0.sSineY) >> 16)
                 + ((unsigned __int64)(dword_F8AD4C * stru_51B6E0.sCosineY) >> 16);
    dword_F8ADA0 = ((unsigned __int64)(v81 * stru_51B6E0.sSineMinusX) >> 16)
                 + ((unsigned __int64)(dword_F8AD50 * stru_51B6E0.sCosineMinusX) >> 16);
    v81 = stru_51B6E0.sSineY * stru_51B6E0.vPosition.y - stru_51B6E0.sCosineY * stru_51B6E0.vPosition.x;
    v14 = -(stru_51B6E0.sCosineY * stru_51B6E0.vPosition.y + stru_51B6E0.sSineY * stru_51B6E0.vPosition.x);
    v80 = -65536 * stru_51B6E0.vPosition.z;
    v77 = (unsigned __int64)(-65536 * stru_51B6E0.vPosition.z * stru_51B6E0.sSineMinusX) >> 16;
    v13 = ((unsigned __int64)(v81 * stru_51B6E0.sCosineMinusX) >> 16) - v77;
    v76 = (unsigned __int64)(v81 * stru_51B6E0.sSineMinusX) >> 16;
    v11 = stru_51B6E0.vPosition.y;
    v77 = ((unsigned __int64)(v81 * stru_51B6E0.sSineMinusX) >> 16)
        + ((unsigned __int64)(-65536 * stru_51B6E0.vPosition.z * stru_51B6E0.sCosineMinusX) >> 16);
    v12 = stru_51B6E0.vPosition.x;
  }
  else
  {
    v77 = (unsigned __int64)(dword_F8AD30 * stru_51B6E0.sSineY) >> 16;
    dword_F8AD7C = ((unsigned __int64)(dword_F8AD2C * stru_51B6E0.sCosineY) >> 16) - v77;
    dword_F8AD84 = dword_F8AD34;
    dword_F8AD80 = ((unsigned __int64)(dword_F8AD2C * stru_51B6E0.sSineY) >> 16)
                 + ((unsigned __int64)(dword_F8AD30 * stru_51B6E0.sCosineY) >> 16);
    v77 = (unsigned __int64)(dword_F8AD40 * stru_51B6E0.sSineY) >> 16;
    dword_F8AD8C = ((unsigned __int64)(dword_F8AD3C * stru_51B6E0.sCosineY) >> 16) - v77;
    dword_F8AD94 = dword_F8AD44;
    dword_F8AD90 = ((unsigned __int64)(dword_F8AD3C * stru_51B6E0.sSineY) >> 16)
                 + ((unsigned __int64)(dword_F8AD40 * stru_51B6E0.sCosineY) >> 16);
    v77 = (unsigned __int64)(dword_F8AD4C * stru_51B6E0.sSineY) >> 16;
    dword_F8AD98 = ((unsigned __int64)(dword_F8AD48 * stru_51B6E0.sCosineY) >> 16) - v77;
    v76 = (unsigned __int64)(dword_F8AD48 * stru_51B6E0.sSineY) >> 16;
    v12 = stru_51B6E0.vPosition.x;
    dword_F8ADA0 = dword_F8AD50;
    v11 = stru_51B6E0.vPosition.y;
    dword_F8AD9C = ((unsigned __int64)(dword_F8AD48 * stru_51B6E0.sSineY) >> 16)
                 + ((unsigned __int64)(dword_F8AD4C * stru_51B6E0.sCosineY) >> 16);
    v13 = stru_51B6E0.sSineY * stru_51B6E0.vPosition.y - stru_51B6E0.sCosineY * stru_51B6E0.vPosition.x;
    v14 = -(stru_51B6E0.sCosineY * stru_51B6E0.vPosition.y + stru_51B6E0.sSineY * stru_51B6E0.vPosition.x);
    v77 = -65536 * stru_51B6E0.vPosition.z;
  }
  dword_F8ADA4 = dword_F8AD7C;
  dword_F8AD88 = dword_F8AD34 * stru_51B6E0.vPosition.z + dword_F8AD38 + dword_F8AD30 * v11 + dword_F8AD2C * v12;
  dword_F8ADA8 = (unsigned __int64)(stru_51B6E0.dword_000044 * dword_F8AD80) >> 16;
  dword_F8ADAC = (unsigned __int64)(stru_51B6E0.dword_000044 * dword_F8AD84) >> 16;
  dword_F8ADB0 = -dword_F8AD88;
  dword_F8ADB4 = dword_F8AD8C;
  dword_F8ADB8 = (unsigned __int64)(stru_51B6E0.dword_000044 * dword_F8AD90) >> 16;
  dword_F8ADBC = (unsigned __int64)(stru_51B6E0.dword_000044 * dword_F8AD94) >> 16;
  X = (unsigned __int64)(dword_F8AD8C * v13) >> 16;
  v15 = v77;
  v77 = (unsigned __int64)(dword_F8AD94 * v77) >> 16;
  dword_F8ADC4 = dword_F8AD98;
  dword_F8ADC0 = -(X + ((unsigned __int64)(dword_F8AD90 * v14) >> 16) + v77);
  dword_F8ADC8 = (unsigned __int64)(stru_51B6E0.dword_000044 * dword_F8AD9C) >> 16;
  dword_F8ADCC = (unsigned __int64)(stru_51B6E0.dword_000044 * dword_F8ADA0) >> 16;
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
  dword_F8AD54 = (dword_F8B120 + *(_WORD *)((int)pIndoor->pSectors + v16 + 98)) << 16;
  v77 = pMobileLightsStack->uNumLightsActive;
  if ( pMobileLightsStack->uNumLightsActive > 0 )
  {
   v18 = (char *)&pMobileLightsStack->pLights[0].vPosition.y;
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
  v31 = *(_WORD *)((int)pIndoor->pSectors + v16 + 84);
  v77 = *(_WORD *)((int)pIndoor->pSectors + v16 + 84);
  if ( v31 > 0 )
  {
    while ( v81 < 20 )
    {
      v32 = (int)pIndoor->pLights + 16 * *(_WORD *)(*(_DWORD *)((int)pIndoor->pSectors + v16 + 88) + 2 * v30);
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
      compile_error();//v42 = __SETO__(v80 + 1, v77);
      v41 = v80++ + 1 - v77 < 0;
      if ( !(v41 ^ v42) )
        break;
      v16 = v76;
    }
  }
  v80 = 0;
  if ( pStationaryLightsStack->uNumLightsActive > 0 )
  {
   v43 = (char *)&pStationaryLightsStack->pLights[0].vPosition.y;
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
    while ( v80 < pStationaryLightsStack->uNumLightsActive );
  }
  dword_F8ADD4 = v81;
  v55 = *(_WORD *)(v5 + 82);
  if ( stru_51B6E0.vPosition.x <= v55 )
  {
    v57 = *(_WORD *)(v5 + 80);
    if ( stru_51B6E0.vPosition.x >= v57 )
      v56 = 0;
    else
      v56 = v57 - stru_51B6E0.vPosition.x;
  }
  else
  {
    v56 = stru_51B6E0.vPosition.x - v55;
  }
  v58 = *(_WORD *)(v5 + 86);
  v59 = v56 * v56;
  if ( stru_51B6E0.vPosition.y <= v58 )
  {
    v61 = *(_WORD *)(v5 + 84);
    if ( stru_51B6E0.vPosition.y >= v61 )
      v60 = 0;
    else
      v60 = v61 - stru_51B6E0.vPosition.y;
  }
  else
  {
    v60 = stru_51B6E0.vPosition.y - v58;
  }
  v63 = v60 * v60 + v59;
  v62 = *(_WORD *)(v5 + 90);
  if ( stru_51B6E0.vPosition.z <= v62 )
  {
    v65 = *(_WORD *)(v5 + 88);
    if ( stru_51B6E0.vPosition.z >= v65 )
      v64 = 0;
    else
      v64 = v65 - stru_51B6E0.vPosition.z;
  }
  else
  {
    v64 = stru_51B6E0.vPosition.z - v62;
  }
  v67 = v64 * v64 + v63 == 0;
  v66 = v64 * v64 + v63;
  if ( v67 )
    dword_F8AD5C = 0;
  else
    dword_F8AD5C = sub_452A9E(v66) << 16;
  v75 = abs(dword_F8AD80);
  v68 = (double)v75;
  if ( v68 >= 655.36000000000001 )
  {
    if ( v68 >= 26214.400000000001 )
    {
      if ( v68 >= 45875.199999999997 )
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
  dword_F8AD38 = (stru_51B6E0.vPosition.z + 800) << 16;
  dword_F8AD3C = 65536;
  dword_F8AD40 = 0;
  dword_F8AD44 = 0;
  dword_F8AD48 = 0;
  dword_F8AD50 = 0;
  dword_F8B120 = 0;
  if ( stru_51B6E0.sRotationX )
  {
    v6 = ((unsigned __int64)(dword_F8AD2C * stru_51B6E0.sCosineY) >> 16)
       - ((unsigned __int64)(dword_F8AD30 * stru_51B6E0.sSineY) >> 16);
    dword_F8AD7C = ((unsigned __int64)(v6 * stru_51B6E0.sCosineMinusX) >> 16)
                 - ((unsigned __int64)(dword_F8AD34 * stru_51B6E0.sSineMinusX) >> 16);
    dword_F8AD80 = ((unsigned __int64)(dword_F8AD2C * stru_51B6E0.sSineY) >> 16)
                 + ((unsigned __int64)(dword_F8AD30 * stru_51B6E0.sCosineY) >> 16);
    dword_F8AD84 = ((unsigned __int64)(v6 * stru_51B6E0.sSineMinusX) >> 16)
                 + ((unsigned __int64)(dword_F8AD34 * stru_51B6E0.sCosineMinusX) >> 16);
    v7 = ((unsigned __int64)(dword_F8AD3C * stru_51B6E0.sCosineY) >> 16)
       - ((unsigned __int64)(dword_F8AD40 * stru_51B6E0.sSineY) >> 16);
    dword_F8AD8C = ((unsigned __int64)(v7 * stru_51B6E0.sCosineMinusX) >> 16)
                 - ((unsigned __int64)(dword_F8AD44 * stru_51B6E0.sSineMinusX) >> 16);
    dword_F8AD90 = ((unsigned __int64)(dword_F8AD3C * stru_51B6E0.sSineY) >> 16)
                 + ((unsigned __int64)(dword_F8AD40 * stru_51B6E0.sCosineY) >> 16);
    dword_F8AD94 = ((unsigned __int64)(v7 * stru_51B6E0.sSineMinusX) >> 16)
                 + ((unsigned __int64)(dword_F8AD44 * stru_51B6E0.sCosineMinusX) >> 16);
    v8 = ((unsigned __int64)(dword_F8AD48 * stru_51B6E0.sCosineY) >> 16)
       - ((unsigned __int64)(dword_F8AD4C * stru_51B6E0.sSineY) >> 16);
    dword_F8AD98 = ((unsigned __int64)(v8 * stru_51B6E0.sCosineMinusX) >> 16)
                 - ((unsigned __int64)(dword_F8AD50 * stru_51B6E0.sSineMinusX) >> 16);
    dword_F8AD9C = ((unsigned __int64)(dword_F8AD48 * stru_51B6E0.sSineY) >> 16)
                 + ((unsigned __int64)(dword_F8AD4C * stru_51B6E0.sCosineY) >> 16);
    dword_F8ADA0 = ((unsigned __int64)(v8 * stru_51B6E0.sSineMinusX) >> 16)
                 + ((unsigned __int64)(dword_F8AD50 * stru_51B6E0.sCosineMinusX) >> 16);
    v5 = -(stru_51B6E0.sCosineY * stru_51B6E0.vPosition.y + stru_51B6E0.sSineY * stru_51B6E0.vPosition.x);
    v9 = stru_51B6E0.sSineY * stru_51B6E0.vPosition.y - stru_51B6E0.sCosineY * stru_51B6E0.vPosition.x;
    v2 = ((unsigned __int64)(v9 * stru_51B6E0.sCosineMinusX) >> 16)
       - ((unsigned __int64)(-65536 * stru_51B6E0.vPosition.z * stru_51B6E0.sSineMinusX) >> 16);
    v3 = stru_51B6E0.vPosition.z;
    v4 = ((unsigned __int64)(-65536 * stru_51B6E0.vPosition.z * stru_51B6E0.sCosineMinusX) >> 16)
       + ((unsigned __int64)(v9 * stru_51B6E0.sSineMinusX) >> 16);
    v1 = stru_51B6E0.vPosition.y;
    v0 = stru_51B6E0.vPosition.x;
  }
  else
  {
    dword_F8AD7C = ((unsigned __int64)(dword_F8AD2C * stru_51B6E0.sCosineY) >> 16)
                 - ((unsigned __int64)(dword_F8AD30 * stru_51B6E0.sSineY) >> 16);
    dword_F8AD84 = dword_F8AD34;
    dword_F8AD80 = ((unsigned __int64)(dword_F8AD2C * stru_51B6E0.sSineY) >> 16)
                 + ((unsigned __int64)(dword_F8AD30 * stru_51B6E0.sCosineY) >> 16);
    dword_F8AD8C = ((unsigned __int64)(dword_F8AD3C * stru_51B6E0.sCosineY) >> 16)
                 - ((unsigned __int64)(dword_F8AD40 * stru_51B6E0.sSineY) >> 16);
    dword_F8AD94 = dword_F8AD44;
    dword_F8AD90 = ((unsigned __int64)(dword_F8AD3C * stru_51B6E0.sSineY) >> 16)
                 + ((unsigned __int64)(dword_F8AD40 * stru_51B6E0.sCosineY) >> 16);
    dword_F8AD98 = ((unsigned __int64)(dword_F8AD48 * stru_51B6E0.sCosineY) >> 16)
                 - ((unsigned __int64)(dword_F8AD4C * stru_51B6E0.sSineY) >> 16);
    v1 = stru_51B6E0.vPosition.y;
    dword_F8AD9C = ((unsigned __int64)(dword_F8AD48 * stru_51B6E0.sSineY) >> 16)
                 + ((unsigned __int64)(dword_F8AD4C * stru_51B6E0.sCosineY) >> 16);
    dword_F8ADA0 = dword_F8AD50;
    v0 = stru_51B6E0.vPosition.x;
    v2 = stru_51B6E0.sSineY * stru_51B6E0.vPosition.y - stru_51B6E0.sCosineY * stru_51B6E0.vPosition.x;
    v3 = stru_51B6E0.vPosition.z;
    v5 = -(stru_51B6E0.sCosineY * stru_51B6E0.vPosition.y + stru_51B6E0.sSineY * stru_51B6E0.vPosition.x);
    v4 = -65536 * stru_51B6E0.vPosition.z;
  }
  dword_F8ADA4 = dword_F8AD7C;
  dword_F8AD88 = dword_F8AD30 * v1 + dword_F8AD38 + dword_F8AD2C * v0 + dword_F8AD34 * v3;
  dword_F8ADA8 = (unsigned __int64)(stru_51B6E0.dword_000044 * dword_F8AD80) >> 16;
  dword_F8ADAC = (unsigned __int64)(stru_51B6E0.dword_000044 * dword_F8AD84) >> 16;
  dword_F8ADB0 = -dword_F8AD88;
  dword_F8ADB4 = dword_F8AD8C;
  dword_F8ADB8 = (unsigned __int64)(stru_51B6E0.dword_000044 * dword_F8AD90) >> 16;
  dword_F8ADBC = (unsigned __int64)(stru_51B6E0.dword_000044 * dword_F8AD94) >> 16;
  dword_F8ADC4 = dword_F8AD98;
  dword_F8ADC0 = -(((unsigned __int64)(dword_F8AD8C * v2) >> 16)
                 + ((unsigned __int64)(dword_F8AD90 * v5) >> 16)
                 + ((unsigned __int64)(dword_F8AD94 * v4) >> 16));
  dword_F8ADC8 = (unsigned __int64)(stru_51B6E0.dword_000044 * dword_F8AD9C) >> 16;
  dword_F8ADCC = (unsigned __int64)(stru_51B6E0.dword_000044 * dword_F8ADA0) >> 16;
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
char __thiscall class37_sub_4AFB86(void *_this, int a2, int a3)
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

  v4 = _this;
  v3 = (int)pIndoor->pFaces + a3;
  v21 = v3;
  if ( *(_BYTE *)(v3 + 44) & 1 )
  {
    v5 = (char *)_this + 2252 * a2;
    v20 = v5;
    if ( a3 != *((_WORD *)v5 + 2982) )
    {
      if ( !a2
        && stru_51B6E0.vPosition.x >= *(_WORD *)(v3 + 80) - 16
        && stru_51B6E0.vPosition.x <= *(_WORD *)(v3 + 82) + 16
        && stru_51B6E0.vPosition.y >= *(_WORD *)(v3 + 84) - 16
        && stru_51B6E0.vPosition.y <= *(_WORD *)(v3 + 86) + 16
        && stru_51B6E0.vPosition.z >= *(_WORD *)(v3 + 88) - 16
        && stru_51B6E0.vPosition.z <= *(_WORD *)(v3 + 90) + 16 )
      {
        if ( abs(*(_DWORD *)(v3 + 28) + stru_51B6E0.vPosition.x * *(_DWORD *)(v3 + 16)
                                      + stru_51B6E0.vPosition.y * *(_DWORD *)(v3 + 20)
                                      + stru_51B6E0.vPosition.z * *(_DWORD *)(v3 + 24)) <= 589824 )
        {
          v6 = *(_WORD *)(v21 + 76);
          if ( *((_WORD *)v4 + 2004) == v6 )
            v6 = *(_WORD *)(v21 + 78);
          *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2004) = v6;
          *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2982) = a3;
          *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2005) = stru_51B6E0.uViewportX;
          *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2007) = stru_51B6E0.uViewportZ;
          *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2006) = stru_51B6E0.uViewportY;
          *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2008) = stru_51B6E0.uViewportW;
          compile_error();
          /*
          sub_43F9E1(
            (int)(v4 + 2252 * *((_DWORD *)v4 + 1001)++ + 4020),
            stru_51B6E0.dword_000054,
            stru_51B6E0.dword_000058,
            stru_51B6E0.dword_00005C,
            stru_51B6E0.dword_000060);*/
          v8 = *((_DWORD *)v4 + 1001) - 1;
          goto LABEL_14;
        }
        v3 = v21;
        v5 = v20;
      }
      v10 = (int)pIndoor->pVertices + 6 * **(_WORD **)(v3 + 48);
      v9 = *(_DWORD *)(v3 + 16) * ((signed __int16)*(_DWORD *)v10 - stru_51B6E0.vPosition.x)
         + *(_DWORD *)(v3 + 20) * ((signed __int16)(*(_DWORD *)v10 >> 16) - stru_51B6E0.vPosition.y)
         + *(_DWORD *)(v3 + 24) * (*(_WORD *)(v10 + 4) - stru_51B6E0.vPosition.z);
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
                  compile_error();//v3 = sub_424829(v3, (int)(v4 + 2252 * *((_DWORD *)v4 + 1001) + 4020), (int)(v20 + 4020), a3);
                  if ( v3 )
                  {
                    v16 = *(_WORD *)(v21 + 76);
                    if ( *((_WORD *)v20 + 2004) == v16 )
                      v16 = *(_WORD *)(v21 + 78);
                    *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2004) = v16;
                    *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2982) = a3;
                    *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2005) = stru_51B6E0.uViewportX;
                    *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2007) = stru_51B6E0.uViewportZ;
                    *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2006) = stru_51B6E0.uViewportY;
                    *((_WORD *)v4 + 1126 * *((_DWORD *)v4 + 1001) + 2008) = stru_51B6E0.uViewportW;
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
    v3 = *(_DWORD *)_this;
    if ( *(_DWORD *)_this < 1000 )
    {
      *((_WORD *)_this + 2 * v3 + 2) = a3;
      v3 = *(_DWORD *)_this;
      *((_WORD *)_this + 2 * *(_DWORD *)_this + 3) = a2;
      *(_DWORD *)_this += 1;
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
    if ( a1 < pIndoor->uNumFaces )
    {
      v3 = (int)&pIndoor->pFaces[a1];
      v103 = v3;
      v2 = *(_DWORD *)(v3 + 44);
      if ( !(BYTE1(v2) & 0x20) )
      {
        if ( v2 & 0x400000 )
        {
          sub_4ADD1D(a1);
          return;
        }
        if ( !(v2 & 0x10) || (sub_4AD504(a1), pD3DRenderer->pRenderD3D3) )
        {
          v4 = sub_4AE5BA(v3);
          ++stru_51B6E0.dword_000080;
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
              if ( sub_424829(v6, (int)&dword_F8A590, stru_51B6E0.dword_00007C, v1) )
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
                Game_sub_44ED0A(pGame, (struct8 *)v3, &v135, 31);
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
                      v27 = v111 * (v24 - stru_51B6E0.uViewportY);
                      v129 = (int)stru_51B6E0.pZTarget
                           + 4
                           * (2 * (*(__int16 *)((char *)word_F8A5A8 + v24) + 320 * (v24 - stru_51B6E0.uViewportY)) - stru_51B6E0.uViewportX);
                      v132 = (int)stru_51B6E0.pRenderTarget + 4 * (v27 + 2 * *(__int16 *)((char *)word_F8A5A8 + v24) - stru_51B6E0.uViewportX);
                      v25 = (int)stru_51B6E0.pRenderTarget + 4 * (v27 + 2 * *(__int16 *)((char *)word_F8A968 + v24) - stru_51B6E0.uViewportX);
                      v22 = v119;
                    }
                    else
                    {
                      v26 = *(__int16 *)((char *)word_F8A5A8 + v24);
                      v129 = (int)stru_51B6E0.pZTarget + 4 * (v26 + v22);
                      v132 = (int)stru_51B6E0.pRenderTarget + 4 * (v26 + v110);
                      v25 = (int)stru_51B6E0.pRenderTarget + 4 * (v110 + *(__int16 *)((char *)word_F8A968 + v24));
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
      if ( v1 < pIndoor->uNumFaces )
      {
        v3 = word_51B77C[2 * i];
        stru_51B6E0.dword_00007C = (int)((char *)&unk_51C72C + 2252 * word_51B77C[2 * i + 1]);
        v2 = sub_423B5D(v3);
        if ( v2 )
        {
          if ( sub_424829(v2, (int)&dword_F8A590, stru_51B6E0.dword_00007C, v1) )
          {
            v4 = dword_F8A590;
            v5 = (int)stru_51B6E0.pRenderTarget;
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
    if ( a1 < pIndoor->uNumFaces )
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
        compile_error();//atexit(loc_4B0DFB);
      }
      v9 = (int)pIndoor->pFaces + v4;
      if ( *(_BYTE *)(v9 + 93) >= 3u )
      {
        if ( !(*(_BYTE *)(v9 + 45) & 0x20) )
        {
          ++stru_51B6E0.dword_000080;
          *(_BYTE *)(v9 + 44) |= 0x80u;
          v29 = sub_4AE5BA(v9);
          if ( v29 )
          {
            v10 = pGame->class08_obj;
            v32 = pGame->class08_obj;
            v31 = (int)pGame->class04_obj;
            if ( !sub_436455((BLVFace *)v9) )
            {
              v11 = 0;
              v35 = *(_BYTE *)(v9 + 93);
              if ( v35 > 0 )
              {
                v13 = (int)pIndoor->pVertices;
                v12 = &unk_F7C230;
                do
                {
                  v14 = 2 * v11++;
                  *((float *)v12 - 2) = (double)*(_WORD *)(v13 + 6 * *(_WORD *)(*(_DWORD *)(v9 + 48) + v14));
                  *((float *)v12 - 1) = (double)*(_WORD *)(v13 + 6 * *(_WORD *)(*(_DWORD *)(v9 + 48) + v14) + 2);
                  *(float *)v12 = (double)*(_WORD *)(v13 + 6 * *(_WORD *)(*(_DWORD *)(v9 + 48) + v14) + 4);
                  v12 = (char *)v12 + 48;
                  compile_error();//v16 = __SETO__(v11, v35);
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
                  sub_49BBBD((int)pClass58_global, v34);
                  sub_4364C5((int)&unk_F7B628, v35, (int)array_507D30, (int)&dword_F8AD28);
                  class08_sub_436BB7_PrimitiveApplyProjectionMatrix((class08 *)v32, array_507D30, v35, 0);
                  *(_DWORD *)(v31 + 1587204) = 0;
                  if ( dword_F8ADD4 > 0 || pClass58_global->std__vector_30B00C_size > 0 )
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
                        (int)array_507D30,
                        *(float *)&v33,
                        0);
                  }
                  if ( pClass58_global->std__vector_30B00C_size > 0 )
                    sub_49B540(
                      pClass58_global,
                      v36,
                      1,
                      (int)&unk_F7B60C,
                      v35,
                      (int)array_507D30,
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
                      v25 = v24 - pClass59_global->uIntegerHalfPi;
                      v26 = (char *)&array_507D30[0].v;
                      v37 = v35;
                      for ( i = v25; ; v25 = i )
                      {
                       compile_error();
                        //*(float *)v26 = (double)(LODFile_Bitmaps_LOD.array_00024C[9 + 36 * *(_WORD *)(v9 + 74)] & (class59_class59_sub_402CAE(
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
                      v23 = TextureFrameTable_GetFrame(pTextureFrameTable, *(_WORD *)(v9 + 74), stru_51B6E0.dword_000000);
LABEL_42:
                      v28 = (int)LODFile_Bitmaps_LOD.pHardwareTextures[v23];
                      if ( *(_BYTE *)(v9 + 46) & 0x40 )
                        sub_479A53(v35, v34);
                      else
                        Render_sub_4A2FC0((int)pD3DRenderer, v35, v9, v28, v29, 8 * v34 | 6, v17, 0);
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

  v3 = (int)&pIndoor->pFaces[a1];
  v5 = (int)pIndoor->pFaceExtras + 36 * *(_WORD *)(v3 + 72);
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
char __thiscall class37_sub_4B0EA8(int _this, signed int a2, int a3)
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
  v5 = _this;
  v3 = (int)pIndoor->pFaces + a3;
  *(_DWORD *)(2252 * *(_DWORD *)(_this + 4004) + _this + 5968) = -1;
  v38 = v3;
  if ( *(_BYTE *)(v3 + 44) & 1 )
  {
    v6 = _this + 2252 * a2;
    v34 = v6;
    if ( v4 == *(_WORD *)(v6 + 5964) )
      return v3;
    if ( !a2
      && stru_51B6E0.vPosition.x >= *(_WORD *)(v3 + 80) - 16
      && stru_51B6E0.vPosition.x <= *(_WORD *)(v3 + 82) + 16
      && stru_51B6E0.vPosition.y >= *(_WORD *)(v3 + 84) - 16
      && stru_51B6E0.vPosition.y <= *(_WORD *)(v3 + 86) + 16
      && stru_51B6E0.vPosition.z >= *(_WORD *)(v3 + 88) - 16
      && stru_51B6E0.vPosition.z <= *(_WORD *)(v3 + 90) + 16 )
    {
      if ( abs(*(_DWORD *)(v3 + 28) + stru_51B6E0.vPosition.x * *(_DWORD *)(v3 + 16)
                                    + stru_51B6E0.vPosition.y * *(_DWORD *)(v3 + 20)
                                    + stru_51B6E0.vPosition.z * *(_DWORD *)(v3 + 24)) <= 589824 )
      {
        v7 = *(_WORD *)(v38 + 76);
        if ( *(_WORD *)(v5 + 4008) == v7 )
          v7 = *(_WORD *)(v38 + 78);
        *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4008) = v7;
        *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 5964) = a3;
        *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4010) = stru_51B6E0.uViewportX;
        *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4014) = stru_51B6E0.uViewportZ;
        *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4012) = stru_51B6E0.uViewportY;
        *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4016) = stru_51B6E0.uViewportW;
        compile_error();//sub_43F9E1(2252 * *(_DWORD *)(v5 + 4004)++ + v5 + 4020, stru_51B6E0.dword_000054, stru_51B6E0.dword_000058, stru_51B6E0.dword_00005C, stru_51B6E0.dword_000060);
        LOBYTE(v3) = sub_440639(*(_DWORD *)(v5 + 4004) - 1, v8);
        return v3;
      }
      v3 = v38;
      v6 = v34;
    }
    v10 = (int)pIndoor->pVertices + 6 * **(_WORD **)(v3 + 48);
    v9 = *(_DWORD *)(v3 + 16) * ((signed __int16)*(_DWORD *)v10 - stru_51B6E0.vPosition.x)
       + *(_DWORD *)(v3 + 20) * ((signed __int16)(*(_DWORD *)v10 >> 16) - stru_51B6E0.vPosition.y)
       + *(_DWORD *)(v3 + 24) * (*(_WORD *)(v10 + 4) - stru_51B6E0.vPosition.z);
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
                  *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4010) = stru_51B6E0.uViewportX;
                  *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4014) = stru_51B6E0.uViewportZ;
                  *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4012) = stru_51B6E0.uViewportY;
                  *(_WORD *)(2252 * *(_DWORD *)(v5 + 4004) + v5 + 4016) = stru_51B6E0.uViewportW;
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
                        v26 = (int)pIndoor->pVertices + 6 * v25;
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
                  if ( stru_51B6E0.dword_000004 & 1 )
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
    v3 = *(_DWORD *)_this;
    if ( *(_DWORD *)_this < 1000 )
    {
      v31 = a2;
      *(_WORD *)(v5 + 4 * v3 + 4) = v4;
      v3 = *(_DWORD *)v5;
      *(_WORD *)(v5 + 4 * *(_DWORD *)v5 + 6) = v31;
      *(_DWORD *)v5 += 1;
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
  Player *v8; // edi@18
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
  pParty_global->Abc.array_000334[2 * a1] = pParty_global->qword_00002C + 368640;
  pParty_global->Abc.array_000334[2 * a1 + 1] = HIDWORD(v6);
LABEL_13:
  dword_AE310C[a1] = 1;
  if ( v3 )
  {
    v7 = (char *)&pOutdoor->cDDMHeader;
    if ( uCurrentlyLoadedLevelType != 2 )
      v7 = (char *)&pIndoor->cDLVHeader;

    *((_DWORD *)v7 + 2) += v3;
    if ( *((_DWORD *)v7 + 2) > 10000 )
      *((_DWORD *)v7 + 2) = 10000;
  }
   for(int i=1; i<5; i++) 
          { 
    v8 = pPlayers[i];
    result = *(_DWORD *)v8;
    if ( dword_AE31E0 )
    {
      v10 = result + 338;
      result = sub_449B57((unsigned char *)result + 338, 1);
      if ( !(_WORD)result )
        result = sub_449B7E(v10, 1, 1);
    }
    //v8 += 4;
  }
 // while ( v8 <= (signed int)&dword_A750D4 );
  return result;
}

//----- (004B1523) --------------------------------------------------------
void __thiscall sub_4B1523(void *_this)
{
  int v1; // esi@1
  int v2; // edx@1
  int v3; // eax@2
  int v4; // eax@4
  int v5; // ecx@4
  int v6; // eax@10
  const char *v8; // ST44_4@12
  unsigned __int16 v9; // ax@12

  GUI::Window local_0C;
  //int v10; // [sp+Ch] [bp-68h]@4
  //int v11; // [sp+10h] [bp-64h]@4
  //int v12; // [sp+14h] [bp-60h]@4
  //int v13; // [sp+18h] [bp-5Ch]@4
  //int v14; // [sp+1Ch] [bp-58h]@4
  //int v15; // [sp+20h] [bp-54h]@4
  //int v16; // [sp+54h] [bp-20h]@4

  int v17; // [sp+60h] [bp-14h]@1
  char v18; // [sp+64h] [bp-10h]@1
  int v19; // [sp+68h] [bp-Ch]@4
  int v20; // [sp+6Ch] [bp-8h]@4
  int v21; // [sp+70h] [bp-4h]@4

  v1 = *(_DWORD *)_this - 399;
  v2 = (*(_DWORD *)_this - 400) % 11 + 1;
  v17 = 4 * (*(_DWORD *)_this - 400) / 11;
  wsprintfA((char *)TmpBuf, "%s%03d", *(wchar_t **)((char *)&off_4E1D18 + v17), v2);
  if ( *(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v18) + 4) <= 320 )
    v3 = *(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v18) + 4) + 30;
  else
    v3 = 30;
  local_0C.ptr_000048 = 0;
  local_0C.uFrameY = v3;
  local_0C.uFrameWidth = 328;
  local_0C.uFrameHeight = 68;
  local_0C.uFrameX = 90;
  local_0C.uFrameZ = 417;
  local_0C.uFrameW = v3 + 67;
  v19 = GUIFont_GetLineWidth(pFontSmallnum, pGlobalTXT_LocalizationStrings[431]);
  v21 = GUIFont_GetLineWidth(pFontSmallnum, pGlobalTXT_LocalizationStrings[433]);
  v20 = GUIFont_GetLineWidth(pFontSmallnum, pGlobalTXT_LocalizationStrings[432]);
  v4 = GUIFont_GetLineWidth(pFontSmallnum, pGlobalTXT_LocalizationStrings[96]);
  v5 = v19;
  if ( v21 > v19 )
    v5 = v21;
  if ( v20 > v5 )
    v5 = v20;
  if ( v4 > v5 )
    v5 = v4;
  wsprintfA((char *)pStringBuffer,
    "%s\n\n%s\t%03d:\t%03d%s\t000\n%s\t%03d:\t%03d%s\t000\n%s\t%03d:\t%03d%s\t000\n%s\t%03d:\t%03d%s",
    pSpellStats->pSpellInfos[v1].pSpellDescription,//*((_DWORD *)&unk_5CC038 + 9 * v1),
    pGlobalTXT_LocalizationStrings[431],
    v5 + 3,
    v5 + 10,
    pSpellStats->pSpellInfos[v1].pSpellBasicSkillDesc,//*((_DWORD *)&unk_5CC03C + 9 * v1),
    pGlobalTXT_LocalizationStrings[433],
    v5 + 3,
    v5 + 10,
    pSpellStats->pSpellInfos[v1].pSpellExpertSkillDesc,//*((_DWORD *)&unk_5CC040 + 9 * v1),
    pGlobalTXT_LocalizationStrings[432],
    v5 + 3,
    v5 + 10,
    pSpellStats->pSpellInfos[v1].pSpellMasterSkillDesc,//*((_DWORD *)&unk_5CC044 + 9 * v1),
    pGlobalTXT_LocalizationStrings[96],
    v5 + 3,
    v5 + 10,
    pSpellStats->pSpellInfos[v1].pSpellGrandmasterSkillDesc);//*((_DWORD *)&unk_5CC048 + 9 * v1));
  v6 = GUIFont_CalculateTextHeight(pFontSmallnum, pStringBuffer, &local_0C, 0, 0);
  local_0C.uFrameHeight += v6;
  if (local_0C.uFrameHeight < 150)
    local_0C.uFrameHeight = 150;
  local_0C.uFrameWidth = 460;
  GUIWindow_sub_415551(&local_0C, 0);
  local_0C.uFrameWidth -= 12;
  local_0C.uFrameHeight -= 12;

  //dword_5CC030 == pSpellStats
  v8 = (char*)pSpellStats->pSpellInfos[v1].pSpellName;
  
  local_0C.uFrameZ = local_0C.uFrameX + local_0C.uFrameWidth - 1;
  local_0C.uFrameW = local_0C.uFrameHeight + local_0C.uFrameY - 1;
  v9 = 0xFFFF9B;
  GUIWindow_DrawText(&local_0C, pFontArrus, 120, 12, v9, v8, 3);
  FontDrawText(&local_0C, pFontSmallnum, 120, 44, (char *)pStringBuffer, 0, 0, 0);
  local_0C.uFrameZ = local_0C.uFrameX + 107;
  local_0C.uFrameWidth = 108;
  //GUIWindow_DrawText((int)&v10, pFontComic, 12, 75, 0, (&dword_AE3300)[v17], 3);
  GUIWindow_DrawText(&local_0C, pFontComic, 12, 75, 0, (char *)aSkillNames[12 + v17 / 4], 3);
  wsprintfA((char *)TmpBuf, "%s\n%d", pGlobalTXT_LocalizationStrings[LOCSTR_SP_COST], word_4E3C68[v1].uNormalLevelMana);
  GUIWindow_DrawText(&local_0C, pFontComic, 12, local_0C.uFrameHeight - pFontComic->uFontHeight - 16, 0, (char *)TmpBuf, 3);
}

//----- (004B1784) --------------------------------------------------------
signed int __cdecl sub_4B1784()
{
  int v0; // ebx@1
  signed int result; // eax@2
  unsigned __int16 v2; // ST0C_2@3
  int v3; // eax@3

  GUI::Window local_04;
  //int v4; // [sp+4h] [bp-54h]@3
  //int v5; // [sp+Ch] [bp-4Ch]@3
  //int v6; // [sp+14h] [bp-44h]@3

  v0 = (int)pPlayers[uActiveCharacter - 1];
  if ( Player_sub_492C0B_MaybeIfPlayerConscious(pPlayers[uActiveCharacter - 1]) )
  {
    pDialogueWindow->dword_000028 = dword_F8B1E0;
    result = 1;
  }
  else
  {
    pDialogueWindow->dword_000028 = 0;
    memcpy(&local_04, pGUIWindow0, sizeof(GUI::Window));
    local_04.uFrameX = 483;
    local_04.uFrameWidth = 148;
    local_04.uFrameZ = 334;
    wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[427], v0 + 168, pGlobalTXT_LocalizationStrings[562]);
    v2 = 0xFFFFFF9B;
    v3 = GUIFont_CalculateTextHeight(pFontArrus, TmpBuf, &local_04, 0, 0);
    GUIWindow_DrawText(&local_04, pFontArrus, 0, (212 - v3) / 2 + 101, v2, (char *)TmpBuf, 3);
    result = 0;
  }
  return result;
}

//----- (004B1854) --------------------------------------------------------
void __thiscall sub_4B1854(void *_this, __int64 a2)
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

  v15 = (int)_this;
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
  strcpy((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[532]);
  if ( (_DWORD)v5 / 0x18u )
  {
    v8 = (int)pGlobalTXT_LocalizationStrings[57];
    if ( v19 <= 1 )
      v8 = (int)pGlobalTXT_LocalizationStrings[56];
    wsprintfA((char *)pStringBuffer, "%d %s ", v19, v8);
    strcat((char *)TmpBuf, (char *)pStringBuffer);
  }
  if ( v16 | v2 )
  {
    if ( v16 < 0 || v16 <= 0 && v2 <= 1 )
      v9 = (int)pGlobalTXT_LocalizationStrings[109];
    else
      v9 = (int)pGlobalTXT_LocalizationStrings[110];
    wsprintfA((char *)pStringBuffer, "%d %s ", v2, v9);
    strcat((char *)TmpBuf, (char *)pStringBuffer);
  }
  if ( v17 )
  {
    if ( !v19 )
    {
      if ( v17 <= 1 )
        v10 = (int)pGlobalTXT_LocalizationStrings[437];
      else
        v10 = (int)pGlobalTXT_LocalizationStrings[436];
      wsprintfA((char *)pStringBuffer, "%d %s ", v17, v10);
      strcat((char *)TmpBuf, (char *)pStringBuffer);
    }
  }
  if ( v18 )
  {
    if ( !(v16 | v2) )
    {
      if ( v18 <= 1 )
        v11 = (int)pGlobalTXT_LocalizationStrings[439];
      else
        v11 = (int)pGlobalTXT_LocalizationStrings[438];
      wsprintfA((char *)pStringBuffer, "%d %s ", v18, v11);
      strcat((char *)TmpBuf, (char *)pStringBuffer);
    }
  }
  v13 = 0xFFFFFF9B;
  v14 = GUIFont_CalculateTextHeight(pFontArrus, TmpBuf, (GUI::Window *)v15, 0, 0);
  GUIWindow_DrawText((GUI::Window *)v15, pFontArrus, 0, (212 - v14) / 2 + 101, v13, (char *)TmpBuf, 3);
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

  v0 = pPlayers[uActiveCharacter - 1];
  if ( dword_F8B198 > 0 )
  {
    if ( dword_F8B198 > 4 )
    {
      if ( dword_F8B198 <= 16 )
      {
        if ( dword_F8B19C == 18 )
        {
          v2 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v18);
          v3 = *(_DWORD *)v2 + dword_5059A8[*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v17) + 4)];
          v1 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * v3) & 0xFFFF;
          v4 = (*(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * v3) & 0xFFFF) == 0;
          v19 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * v3) & 0xFFFF;
          if ( !v4 )
           sub_4B1523((void *)(36 * (v1 + 12 * ptr_507BC0->dword_00001C) + 11341664));
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
      v6 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v12);
      v5 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer
                     + 4 * (*(_DWORD *)v6 + dword_5059A8[*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v11) + 4)])) & 0xFFFF;
      v19 = v5;
      if ( !v5 )
        return;
      v7 = 9 * (v5 + 12 * ptr_507BC0->dword_00001C);
      v8 = 4 * v7 + 11355920;
      if ( dword_F8B19C != 2 )
        v8 = 4 * v7 + 11378816;
      goto LABEL_15;
    }
    v9 = *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v16) - 14;
    v19 = (v9 >> 5) + 14 * ((*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v15) + 4) - 17) >> 5);
    if ( *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v14) > 13 )
    {
      if ( *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v13) < 462 )
      {
        v10 = Player_sub_421E75_GetItemAtInventoryIndex((Player *)v0, &v19);
        if ( v10 )
        {
          v8 = (int)((char *)v0 + 36 * v10 + 496);
LABEL_15:
          GameUI_DrawItemInfo((ItemGen *)v8);
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

  pParty_global->pHiredNPCs[0].dword_000044 = 0;
  pParty_global->pHiredNPCs[1].dword_000044 = 0;
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
      v1 = ptr_507BC0->dword_00001C;
LABEL_30:
      sub_4B1E92(v1, v0);
      return;
    }
    v1 = (int)ptr_507BC0->dword_00001C;
    v2 = pParty_global->Abc.array_000334[2 * v1 + 1];
    if ( v2 < HIDWORD(pParty_global->qword_00002C)
      || v2 <= HIDWORD(pParty_global->qword_00002C) && (unsigned int)pParty_global->Abc.array_000334[2 * v1] <= (_DWORD)pParty_global->qword_00002C )
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
            if ( Player_sub_492C0B_MaybeIfPlayerConscious(pPlayers[v7]) )
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
          if ( Player_sub_492C0B_MaybeIfPlayerConscious(pPlayers[v4]) )
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
    pAudioPlayer->sub_4AA306(a2 + 100 * ((unsigned __int8)byte_4E5F7D[16 * word_59143A[26 * a1]] + 300),
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
  uDialogueType = 84;
  dword_F8B1E8 = dword_722B44;
  v0 = (signed int)&off_4F0882;
  while ( 1 )
  {
    if ( (unsigned __int16)sub_449B57((unsigned char *)pParty_global->unk_000764 + 1, *(_WORD *)(v0 - 2)) )
    {
      v1 = 0;
      for (i = 1; i < 5; ++i)
      {
        LOBYTE(v3) = Player_sub_449BB4((int)&pParty_global->pPlayers[i], 17, (void *)*(_WORD *)v0);
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
  dword_F8B1E8 = dword_722B3C;
  v4 = *((_WORD *)&off_4F0882 + 2 * v11);
  dword_F8B1A8 = *((_WORD *)&off_4F0882 + 2 * v11);
  sub_44AFFB((char *)&pParty_global->pPlayers[0], 17, v4);
LABEL_10:
  if ( dword_F8B1A8 == 601 )
  {
    v5 = 0;
    v12 = (int)&pParty_global->pPlayers[0].uClass;
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

      compile_error();
      //if ( v12 >= (signed int)&unk_AD472D )
      //  return;
      return; // phail

    }
    if ( v9 )
      *(_BYTE *)(v9 + 26) = v5;
  }
}

//----- (004B2001) --------------------------------------------------------
int __fastcall sub_4B2001(int _this)
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
  unsigned char *v17; // ecx@63
  unsigned char *v18; // eax@65
  const char *v19; // ecx@68
  int v20; // eax@69
  unsigned int v21; // ecx@70
  char *v23; // [sp-Ch] [bp-18h]@73
  int v24; // [sp-8h] [bp-14h]@49
  const char *v25; // [sp-8h] [bp-14h]@73
  int v26; // [sp-4h] [bp-10h]@49
 int i;

  v1 = _this;
  uDialogueType = _this + 1;
  v2 = dword_5913D8[dword_5913F0 - ((dword_591080 != 0) + 1)];
  if ( _this <= 23 )
  {
    if ( _this == 23 )
    {
      v3 = *(_DWORD *)(v2 + 56);
    }
    else
    {
      if ( _this == 13 )
      {
        dword_F8B1E8 = pNPCStats->pProfessions[*(_DWORD *)(v2 + 24)].pJoinText;
        dword_F8B1E8 = sub_495461_DrawAn_AreYouSureWishTo_Join_Dismiss_ThisNPC_Dialogue(dword_F8B1E8, uActiveCharacter, 0, 0, 0, 0);
        sub_4B40E6();
        byte_F8B1EC = 0;
        return pVideoPlayer->sub_4BF5B2();
      }
      switch ( _this )
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
          if ( _this != 22 )
            return pVideoPlayer->sub_4BF5B2();
          v3 = *(_DWORD *)(v2 + 52);
          break;
      }
    }
    goto LABEL_84;
  }
  if ( _this == 24 )
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
    return pVideoPlayer->sub_4BF5B2();
  }
  if ( _this != 76 )
  {
    switch ( _this )
    {
      case 77:
        v16 = *(_DWORD *)(v2 + 24);
        if ( byte_F8B1EC )
          v17 = pNPCStats->pProfessions[v16].pJoinText;
        else
          v17 = pNPCStats->pProfessions[v16].pBenefits;
        dword_F8B1E8 = v17;
        v18 = sub_495461_DrawAn_AreYouSureWishTo_Join_Dismiss_ThisNPC_Dialogue(v17, uActiveCharacter, 0, 0, 0, 0);
        byte_F8B1EC ^= 1u;
        dword_F8B1E8 = v18;
        break;
      case 79:
        if ( dword_F8B1A8 )
        {
          sub_492BB6(uArenaReward);
          if ( uActiveCharacter )
          {
            v12 = (char *)pPlayers[uActiveCharacter - 1] + 2 * dword_F8B1AC + 264;
            *(_WORD *)v12 &= 0x3Fu;
            switch ( dword_F8B1B0 )
            {
              case 2:
                v15 = (char *)pPlayers[uActiveCharacter - 1] + 2 * dword_F8B1AC + 264;
                *(_BYTE *)v15 |= 0x40u;
                break;
              case 3:
                v14 = (char *)pPlayers[uActiveCharacter - 1] + 2 * dword_F8B1AC + 264;
                *(_BYTE *)v14 |= 0x80u;
                break;
              case 4:
                v13 = (char *)pPlayers[uActiveCharacter ] + 2 * dword_F8B1AC + 264;
                *((_BYTE *)v13 + 1) |= 1u;
                break;
            }
            Player_PlaySound(pPlayers[uActiveCharacter - 1], 85, 0);
          }
        /*  if ( dword_50CBD0[0] < 40 )
          {
            dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
            dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
            dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
          }	 */
		  dword_50CBD0.PutMessageToQueue(113,1,0);
        }
        break;
      case 82:
        if ( dword_F8B1A8 )
        {
          sub_492BB6(uArenaReward);

          for (i = 0; i < 4; ++i)
            Player_sub_44A5CB((char *)&pParty_global->pPlayers[i], 12, dword_F8B1AC);


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
        /*  if ( dword_50CBD0[0] < 40 )
          {
            dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
            dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
            dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
          }	   */
		  dword_50CBD0.PutMessageToQueue(113,1,0);
          v11 = uActiveCharacter;
          if ( uActiveCharacter )
          {
            v26 = 0;
            v24 = 86;
LABEL_50:
            Player_PlaySound(pPlayers[v11], v24, v26);
            return pVideoPlayer->sub_4BF5B2();
          }
        }
        break;
    }
    return pVideoPlayer->sub_4BF5B2();
  }
  if (pParty_global->pHiredNPCs[0].pNPCName && pParty_global->pHiredNPCs[1].pNPCName)
  {
    v19 = (char *)pGlobalTXT_LocalizationStrings[533];
LABEL_77:
    sub_44C175(v19, 2);
    return pVideoPlayer->sub_4BF5B2();
  }
  v20 = *(_DWORD *)(v2 + 24);
  if ( v20 != 51 )
  {
    v21 = dword_737C28[5 * v20];
    if ( pParty_global->uNumGold < v21 )
    {
      sub_44C175((char *)pGlobalTXT_LocalizationStrings[155], 2);
      byte_F8B1EC = 0;
      uDialogueType = 13;
      dword_F8B1E8 = pNPCStats->pProfessions[*(_DWORD *)(v2 + 24)].pJoinText;
      dword_F8B1E8 = sub_495461_DrawAn_AreYouSureWishTo_Join_Dismiss_ThisNPC_Dialogue(dword_F8B1E8, uActiveCharacter, 0, 0, 0, 0);
      if ( uActiveCharacter )
        Player_PlaySound(pPlayers[uActiveCharacter - 1], 38, 0);
      v19 = (char *)pGlobalTXT_LocalizationStrings[155];
      goto LABEL_77;
    }
    sub_492BB6(v21);
  }
  *(_BYTE *)(v2 + 8) |= 0x80u;
  pParty_global->byte_000709 = 0;
  sub_44A56A();
  if (pParty_global->pHiredNPCs[0].pNPCName)
  {
    memcpy(&pParty_global->pHiredNPCs[1], (void *)v2, sizeof(struct NPCData));
    v25 = *(const char **)v2;
    v23 = (char *)&unk_AE3090;
  }
  else
  {
    memcpy(&pParty_global->pHiredNPCs[0], (void *)v2, sizeof(struct NPCData));
    v25 = *(const char **)v2;
    v23 = byte_AE302C;
  }
  strcpy(v23, v25);
  pParty_global->byte_000709 = 0;
  sub_44A56A();
  sub_44606A((int)ptr_507BC0->dword_00001C);
  dword_F8B19C = 1;
 /* if ( dword_50CBD0[0] < 40 )
  {
    dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
    dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
    dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
  }	   */
  dword_50CBD0.PutMessageToQueue(113,1,0);
  v11 = uActiveCharacter;
  if ( uActiveCharacter )
  {
    v26 = 0;
    v24 = 61;
    goto LABEL_50;
  }
  return pVideoPlayer->sub_4BF5B2();
}

//----- (004B254D) --------------------------------------------------------
const unsigned char *__thiscall sub_4B254D(void *_this)
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
  unsigned char *v37; // [sp+28h] [bp-4h]@1

  v4 = (int)pPlayers[uActiveCharacter - 1];
  dword_F8B1A8 = 0;
  v5 = (signed int)((char *)_this - 200);
  v2 = (signed int)((char *)_this - 200) / 3;
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
        uArenaReward = 8000;
        dword_F8B1B0 = 4;
      }
    }
    else
    {
      uArenaReward = 5000;
      dword_F8B1B0 = 3;
    }
  }
  else
  {
    uArenaReward = 2000;
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
    v11 = (char*)&byte_4ED970[37 * (v35 - v35 % 4)] + v2;
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
      v27 = (int)aClassNames[1 + v10];
    }
    else
    {
      if ( v32 == v16 )
      {
        if ( v33 == v16 )
        {
          wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[634], aClassNames[2 + v10], aClassNames[3 + v10]);
          return TmpBuf;
        }
        v27 = (int)aClassNames[2 + v10];
      }
      else
      {
        if ( v33 != v16 )
        {
          v27 = (int)(aClassNames[v12]);
          v24 = (int)pGlobalTXT_LocalizationStrings[632];
          goto LABEL_23;
        }
        v27 = (int)aClassNames[3 + v10];
      }
    }
    v24 = (int)pGlobalTXT_LocalizationStrings[633];
LABEL_23:
    wsprintfA((char *)TmpBuf, (const char *)v24, v27);
    return TmpBuf;
  }
  if ( !Player_sub_492C0B_MaybeIfPlayerConscious((Player *)v4) )
    return dword_721A3C;
  if ( !v8 )
    return dword_721A84;
  v18 = sub_458244_GetSkillMasteryLevel(v34);
  if ( v18 > v3 + 1 )
    return dword_721A6C[2 * v3];
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
            uArenaReward = 4000;
            goto LABEL_42;
          case 19:
            v21 = 114;
            goto LABEL_57;
          case 20:
            v21 = 110;
LABEL_57:
            if ( !(unsigned __int16)sub_449B57((unsigned char *)pParty_global->unk_000764 + 1, v21) )
              return v37;
            goto LABEL_40;
          case 22:
            v22 = Player_GetBaseWillpower((Player *)v4);
            goto LABEL_61;
          case 24:
            uArenaReward = 2500;
            v22 = Player_GetBaseEndurance((Player *)v4);
            goto LABEL_61;
          case 36:
            v22 = Player_GetBaseIntelligence((Player *)v4);
LABEL_61:
            if ( v22 < 50 )
              return v37;
            goto LABEL_40;
          case 21:
          case 23:
          case 25:
          case 26:
          case 29:
          case 32:
          case 34:
          case 35:
            uArenaReward = 2500;
            goto LABEL_42;
          case 8:
          case 9:
          case 10:
          case 11:
            uArenaReward = 3000;
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
            return v37;
          case 30:
            v20 = *(_BYTE *)(v4 + 326);
            goto LABEL_47;
          case 31:
            v20 = *(_BYTE *)(v4 + 324);
LABEL_47:
            if ( (v20 & 0x3Fu) < 0xA )
              return v37;
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
            uArenaReward = 6000;
            goto LABEL_42;
          case 8:
          case 9:
          case 10:
          case 11:
            uArenaReward = 7000;
            goto LABEL_42;
          case 7:
            break;
        }
LABEL_67:
        uArenaReward = 0;
        goto LABEL_41;
      }
    }
    return v37;
  }
  if ( v8 < 4 )
    return v37;
  v19 = dword_F8B1AC;
  if ( dword_F8B1AC > 27 )
  {
    if ( dword_F8B1AC != 29 && dword_F8B1AC != 32 && (dword_F8B1AC <= 33 || dword_F8B1AC > 35) )
    {
LABEL_41:
      if ( !uArenaReward )
        goto LABEL_79;
      goto LABEL_42;
    }
LABEL_87:
    uArenaReward = 500;
    goto LABEL_41;
  }
  if ( dword_F8B1AC >= 23 )
    goto LABEL_87;
  if ( dword_F8B1AC == 7 )
  {
    uArenaReward = 0;
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
  uArenaReward = 1000;
LABEL_42:
  if ( uArenaReward > (unsigned int)pParty_global->uNumGold )
    return dword_721A4C;
LABEL_79:
  dword_F8B1A8 = 1;
  if ( v36 == 2 )
  {
    v29 = uArenaReward;
    v26 = (char *)aSkillNames[v19];
    v23 = (int)pGlobalTXT_LocalizationStrings[433];
    goto LABEL_90;
  }
  if ( v36 == 3 )
  {
    v29 = uArenaReward;
    v26 = (char *)aSkillNames[v19];
    v23 = (int)pGlobalTXT_LocalizationStrings[432];
    goto LABEL_90;
  }
  if ( v36 == 4 )
  {
    v29 = uArenaReward;
    v26 = (char *)aSkillNames[v19];
    v23 = (int)pGlobalTXT_LocalizationStrings[225];
LABEL_90:
    wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[534], v23, v26, v29);
  }
  return pStringBuffer;
}

//----- (004B29F2) --------------------------------------------------------
unsigned char *__fastcall sub_4B29F2(int a1)
{
  int v1; // edi@1
  int v2; // esi@1
  int v3; // eax@1
  int v4; // ecx@1
  unsigned char *result; // eax@2

  v2 = a1;
  dword_F8B1A8 = 0;
  v1 = (int)pPlayers[uActiveCharacter - 1];
  v3 = a1 + 50;
  v4 = (int)pPlayers[uActiveCharacter - 1];
  dword_F8B1AC = v3;
  uArenaReward = dword_4F08EC[v2];
  if ( Player_sub_492C0B_MaybeIfPlayerConscious((Player *)v4) )
  {
    if ( (unsigned __int16)sub_449B57((unsigned char *)v1 + 338, dword_F8B1AC) )
    {
      return dword_721A44;
    }
    else
    {
      if ( uArenaReward <= (unsigned int)pParty_global->uNumGold )
      {
        result = dword_7219DC[2 * v2];
        dword_F8B1A8 = 1;
      }
      else
      {
        return dword_721A4C;
      }
    }
  }
  else
  {
    return dword_721A3C;
  }
  return result;
}

//----- (004B2A74) --------------------------------------------------------
void __cdecl sub_4B2A74()
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
  const unsigned char *v15; // esi@14
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
  const unsigned char *v33; // eax@43
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

  GUI::Window local_60;
  //int v52; // [sp+60h] [bp-BCh]@13
  //int v53; // [sp+68h] [bp-B4h]@13
  //int v54; // [sp+70h] [bp-ACh]@13
  //int v55; // [sp+7Ch] [bp-A0h]@43
  //int v56; // [sp+88h] [bp-94h]@13
  //int v57; // [sp+98h] [bp-84h]@13

  GUI::Window local_B4;
  //int v58; // [sp+B4h] [bp-68h]@1
  //int v59; // [sp+BCh] [bp-60h]@3
  //int v60; // [sp+C4h] [bp-58h]@3

  unsigned int v61; // [sp+108h] [bp-14h]@14
  __int16 v62[2]; // [sp+10Ch] [bp-10h]@6
  int v63; // [sp+110h] [bp-Ch]@13
  int v64; // [sp+114h] [bp-8h]@12
  int v65; // [sp+118h] [bp-4h]@6

  memcpy(&local_B4, pDialogueWindow, sizeof(GUI::Window));
  if ( dword_5913F0 == dword_591424 && dword_5C35D0 )
  {
   v1 = (int)pMapStats->pMapInfos[dword_5C35D0].pLocationName;
   v2 = (const char *)pMapStats->pMapInfos[dword_5C35D0].pLocationName;

    local_B4.uFrameX = 493;
    local_B4.uFrameWidth = 126;
    local_B4.uFrameZ = 366;

    GUIWindow_DrawText(&local_B4, pFontCreate, 0, 2, 0, v2, 3);
    local_B4.uFrameX = 483;
    local_B4.uFrameWidth = 148;
    local_B4.uFrameZ = 334;

    v0 = (&off_4EB080)[4 * dword_5C35D0];
    if ( !v0 )
    {
      wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[411], v1);
      v0 = (char *)TmpBuf;
    }
    v4 = v0;
    v5 = GUIFont_CalculateTextHeight(pFontCreate, (unsigned char *)v0, &local_B4, 0, 0);
    /*LOBYTE(i) = (unsigned int)*/GUIWindow_DrawText(&local_B4, pFontCreate, 0, (212 - v5) / 2 + 101, 0, v4, 3);
    return;// i;
  }
  local_B4.uFrameWidth -= 10;
  local_B4.uFrameZ -= 10;
  v65 = dword_5913D8[dword_5913F0 - ((dword_591080 != 0) + 1)];
  v8 = v65;
  *(_DWORD *)v62 = 0xFFE1CD23;
  v7 = 0xFF1599E9;
  v6 = *(_DWORD *)(v8 + 24);
  if ( v6 )
    wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[429], *(_DWORD *)v8, aNPCProfessionNames[v6]);
  else
    strcpy((char *)TmpBuf, *(const char **)v8);
  GUIWindow_DrawText(&local_B4, pFontCreate, 483, 113, v7, (char *)TmpBuf, 3);
  if ( !dword_591080 )
  {
    if ( !uDialogueType )
    {
      v9 = *(_DWORD *)(v8 + 28);
      if ( v9 )
      {
        v10 = *(_DWORD *)(v8 + 8);
        local_B4.uFrameWidth = 460;
        local_B4.uFrameZ = 452;
        v64 = dword_73BA54[((v10 & 3) == 2) + 2 * v9];
        v11 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v64, &local_B4, 13, 0);
        v12 = v11 + 7;
        Render_sub_4A6A68(
          pD3DRenderer,
          8,
          352 - (v11 + 7),
          uTextureIdx_Leather != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[uTextureIdx_Leather] : 0,
          *(_WORD *)(uTextureIdx_Leather != -1 ? LODFile_Icons_LOD.aLODHeaders[uTextureIdx_Leather].uTextureHeight : 26) - (v11 + 7));
        Render_DrawIndexedTexture(pD3DRenderer, 8, 347 - v12, pcTexture_EndcapTexture);

        unsigned char pOutString[2048];
        v13 = (char *)FitTextInAWindow((unsigned char *)v64, pOutString, pFontArrus, &local_B4, 13, 0);
        FontDrawText(pDialogueWindow, pFontArrus, 13, 354 - v12, v13, 0, 0, 0);
      }
    }
  }
  v14 = (int)pDialogueWindow;

  memcpy(&local_60, pDialogueWindow, sizeof(GUI::Window));
  local_60.uFrameX = 483;
  local_60.uFrameWidth = 148;
  local_60.uFrameZ = 334;

  v63 = local_60.dword_000038;
  if (local_60.dword_000038 < local_60.dword_000038 + local_60.dword_000028)
  {
    v15 = (const unsigned char *)v61;
    while ( 1 )
    {
      v16 = (int)GUIWindow_GetChild(&local_60, v63);
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
          v33 = sub_4B254D((void *)local_60.dword_00001C);
LABEL_44:
          v15 = v33;
LABEL_45:
          v16 = v64;
          goto LABEL_49;
        }
        v27 = v26 - 3;
        if ( !v27 )
        {
          v33 = sub_4B29F2(local_60.dword_00001C);
          goto LABEL_44;
        }
        v28 = v27 - 1;
        if ( !v28 )
        {
          v29 = (int *)&pMonsterStats->pMonsterInfos[word_F8B1A0];
          v30 = 0xFFFFFF;
          v31 = *v29;
          v32 = 0xFFFF9B;

          wsprintfA((char *)TmpBuf, "\x0C%05d%s\x0C%05d", v32, v31, v30);
          wsprintfA((char *)pStringBuffer, (const char *)dword_F8B1A4, (char *)TmpBuf, 100 * *((_BYTE *)v29 + 8));
          dword_F8B1E8 = pStringBuffer;
          v15 = NULL;
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
          v15 = dword_721660[8 * v23 - 1];
          if ( !v15 )
          {
            *(_DWORD *)(v16 + 36) = 0;
            v15 = NULL;
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
            v15 = dword_721660[8 * *(_DWORD *)(v65 + 44) - 1];
            if ( !v15 )
            {
              *(_DWORD *)(v16 + 36) = 0;
              v15 = NULL;
            }
            if ( uDialogueType != 84 )
              goto LABEL_49;
            wsprintfA((char *)TmpBuf, "\f%06x%s\f000000", *(_DWORD *)v62, dword_5D29EC[12 * dword_F8B1A8]);
            wsprintfA((char *)pStringBuffer, (char *)dword_F8B1E8, TmpBuf);
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
          v15 = NULL;
          goto LABEL_49;
        }
        v15 = pGlobalTXT_LocalizationStrings[122];
      }
LABEL_49:
      strcpy((char *)(v16 + 85), (char *)v15);
      ++v63;
      if ( v63 >= local_60.dword_000038 + local_60.dword_000028 )
      {
        v14 = (int)pDialogueWindow;
        break;
      }
    }
  }
  v35 = 0;
  v61 = 0xFFFFFF;
  v34 = *(_DWORD *)(v14 + 56);
  *(_DWORD *)v62 = 0xE1CD23;
  for ( i = v34 + *(_DWORD *)(v14 + 40); v34 < i; i = pDialogueWindow->dword_000028 + pDialogueWindow->dword_000038)
  {
    v36 = (int)GUIWindow_GetChild((GUI::Window *)v14, v34);
    v14 = (int)pDialogueWindow;
    v35 += GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)(v36 + 85), &local_60, 0, 0);
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
        v42 = (int)GUIWindow_GetChild((GUI::Window *)v14, i);
        v43 = v42;
        v41 = (const char *)(v42 + 85);
        *(_DWORD *)(v42 + 4) = v65 + v38;
        v44 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)(v42 + 85), &local_60, 0, 0);
        v40 = *(_DWORD *)(v43 + 4);
        *(_DWORD *)(v43 + 12) = v44;
        v38 = v40 + v44 - 1;
        *(_DWORD *)(v43 + 20) = v38;
        v39 = v62[0];
        if (pDialogueWindow->dword_00002C != v64 )
          v39 = v61;
        GUIWindow_DrawText(&local_60, pFontArrus, 0, v40, v39, v41, 3);
        v14 = (int)pDialogueWindow;
        ++v64;
        ++v63;
        i = pDialogueWindow->dword_000028 + pDialogueWindow->dword_000038;
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
    v45 = (int)pFontArrus;
    v46 = GUIFont_CalculateTextHeight(pFontArrus, dword_F8B1E8, (GUI::Window *)&v49, 13, 0) + 7;
    if ( 352 - v46 < 8 )
    {
      v45 = (int)pFontCreate;
      v46 = GUIFont_CalculateTextHeight(pFontCreate, dword_F8B1E8, (GUI::Window *)&v49, 13, 0) + 7;
    }
    Render_sub_4A6A68( pD3DRenderer,  8,   352 - v46,
      uTextureIdx_Leather != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[uTextureIdx_Leather] : 0,
      (uTextureIdx_Leather != -1 ? LODFile_Icons_LOD.aLODHeaders[uTextureIdx_Leather].uTextureHeight : 26) - v46);
    Render_DrawIndexedTexture(pD3DRenderer, 8, 347 - v46, pcTexture_EndcapTexture);

    unsigned char pOutString[2048];
    v47 = (char *)FitTextInAWindow(dword_F8B1E8, pOutString, (Font *)v45, (GUI::Window *)&v49, 13, 0);
    FontDrawText(&local_B4, (Font *)v45, 13, 354 - v46, v47, 0, 0, 0);
  }
}


//----- (004B36CC) --------------------------------------------------------
int __fastcall sub_4B36CC(int a1, int a2)
{
  return (int)GUIButtonCreate(pDialogueWindow, 480, 30 * a1 + 146, 140, 30, 1, 0, 405, a2, 0, NULL, 0);
}

//----- (004B3703) --------------------------------------------------------
int __thiscall sub_4B3703(void *_this)
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
  v2 = (int)((char *)_this - 1);
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
       v20 = v19 + 4 * (int)ptr_507BC0->dword_00001C + ptr_507BC0->dword_00001C;
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
         v14 = v11 + 2 * ptr_507BC0->dword_00001C - 30;
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
         v30 = (int)aSkillNames[30];
          goto LABEL_106;
        }
        if ( v29 == 57 )
        {
         v30 = (int)aSkillNames[21];
          goto LABEL_106;
        }
        if ( v29 == 58 )
        {
         v30 = (int)aSkillNames[22];
          goto LABEL_106;
        }
        if ( v29 == 60 )
        {
         v30 = (int)aSkillNames[24];
          goto LABEL_106;
        }
        if ( v29 == 62 )
        {
         v30 = (int)aSkillNames[26];
          goto LABEL_106;
        }
        if ( v29 == 65 )
        {
         v30 = (int)aSkillNames[29];
          goto LABEL_106;
        }
        goto LABEL_100;
      }
      switch ( v29 )
      {
        case 67:
         v30 = (int)aSkillNames[31];
          break;
        case 68:
         v30 = (int)aSkillNames[32];
          break;
        case 69:
         v30 = (int)aSkillNames[33];
          break;
        case 70:
         v30 = (int)aSkillNames[34];
          break;
        default:
          if ( v29 != 71 )
            goto LABEL_100;
          v30 = (int)aSkillNames[35];
          break;
      }
LABEL_106:
      dword_F8B1B8[v1] = (unsigned char *)v30;
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
     v30 = (int)aSkillNames[11];
      goto LABEL_106;
    }
    if ( v29 > 40 )
    {
      if ( v29 == 41 )
      {
       v30 = (int)aSkillNames[5];
        goto LABEL_106;
      }
      if ( v29 == 42 )
      {
       v30 = (int)aSkillNames[6];
        goto LABEL_106;
      }
      if ( v29 == 44 )
      {
       v30 = (int)aSkillNames[8];
        goto LABEL_106;
      }
      if ( v29 == 45 )
      {
       v30 = (int)aSkillNames[9];
        goto LABEL_106;
      }
      if ( v29 == 46 )
      {
       v30 = (int)aSkillNames[10];
        goto LABEL_106;
      }
    }
    else
    {
      if ( v29 == 40 )
      {
       v30 = (int)aSkillNames[4];
        goto LABEL_106;
      }
      if ( v29 == 5 )
      {
       v30 = (int)aSkillNames[23];
        goto LABEL_106;
      }
      if ( v29 == 36 )
      {
       v30 = (int)aSkillNames[0];
        goto LABEL_106;
      }
      if ( v29 == 37 )
      {
       v30 = (int)aSkillNames[1];
        goto LABEL_106;
      }
      if ( v29 == 38 )
      {
       v30 = (int)aSkillNames[2];
        goto LABEL_106;
      }
      if ( v29 == 39 )
      {
       v30 = (int)aSkillNames[3];
        goto LABEL_106;
      }
    }
LABEL_100:
    v30 = (int)pGlobalTXT_LocalizationStrings[127];
    goto LABEL_106;
  }
LABEL_107:
  GUIWindow_sub_41D08F(pDialogueWindow, v38, 1, 0, 2);
  result = pDialogueWindow->dword_000028;
  dword_F8B1E0 = pDialogueWindow->dword_000028;
  return result;
}

//----- (004B3A72) --------------------------------------------------------
int __thiscall sub_4B3A72(void *_this)
{
  int v1; // esi@1
  int result; // eax@4

  v1 = 0;
  if ( _this == (void *)21 )
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
  GUIWindow_sub_41D08F(pDialogueWindow, v1, 1, 0, 2);
  result = pDialogueWindow->dword_000028;
  dword_F8B1E0 = pDialogueWindow->dword_000028;
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
      GUIWindow_sub_41D08F(pDialogueWindow, v2, v3, v4, v5);
      goto LABEL_7;
    }
  }
LABEL_7:
  result = pDialogueWindow->dword_000028;
  dword_F8B1E0 = pDialogueWindow->dword_000028;
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
          v4 = ptr_507BC0->dword_00001C;
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
            GUIWindow_sub_41D08F(pDialogueWindow, v9, v10, v11, v17);
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
  result = pDialogueWindow->dword_000028;
  dword_F8B1E0 = pDialogueWindow->dword_000028;
  return result;
}

//----- (004B3E1E) --------------------------------------------------------
int __cdecl sub_4B3E1E()
{
  int v0; // ecx@1
  signed int v1; // edi@1
  char *v2; // ST40_4@1

  v2 = (char *)sub_4459F9_GetNPCData(uDialogue_SpeakingActorID);
  v1 = 0;
  pDialogueWindow->uWindowType = 1;
  GUIWindowDelete(pDialogueWindow);
  v0 = (int)GUIWindowCreate(0, 0, 640, 480, 10, (GUIButton *)1, 0);
  pDialogueWindow = (GUI::Window *)v0;
  //if ( (&dword_737C2C)[20 * *((_DWORD *)v2 + 6)] )
  if (pNPCStats->pProfessions[*((_DWORD *)v2 + 6)].pBenefits)
  {
    GUIButtonCreate(pDialogueWindow, 480, 160, 140, 30, 1, 0, 136, 77, 0, pGlobalTXT_LocalizationStrings[407], 0);
    v1 = 1;
  }
  GUIButtonCreate(pDialogueWindow, 480, 30 * v1 + 160, 140, 30, 1, 0, 136, 76, 0, pGlobalTXT_LocalizationStrings[406], 0);
  return GUIWindow_sub_41D08F(pDialogueWindow, v1 + 1, 1, 0, 1);
}

//----- (004B3EF0) --------------------------------------------------------
int __fastcall sub_4B3EF0(int a1)
{
  int result; // eax@1
  int v2; // edi@1

  v2 = a1;
  uDialogueType = 81;
  dword_F8B1E8 = dword_721984[2 * a1];
  sub_4B29F2(a1);
  GUIWindowDelete(pDialogueWindow);
  pDialogueWindow = GUIWindowCreate(0, 0, 640, 350, 1, (GUIButton*)v2, 0);
  dword_5076F4 = GUIButtonCreate(pDialogueWindow,
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
                   uTextureID_right_backgr != -1 ?  &LODFile_Icons_LOD.aLODHeaders[uTextureID_right_backgr] : 0);
  GUIButtonCreate(pDialogueWindow, 0, 0, 0, 0, 1, 0, 81, 0, 0, NULL, 0);
  GUIButtonCreate(pDialogueWindow, 480, 160, 140, 30, 1, 0, 175, 82, 0, pGlobalTXT_LocalizationStrings[122], 0);
  result = GUIWindow_sub_41D08F(pDialogueWindow, 1, 1, 0, 2);
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
  uDialogueType = 78;
  dword_F8B1E8 = dword_721BAC[2 * (_DWORD)a1];
  sub_4B254D(a1);
  GUIWindowDelete(pDialogueWindow);
  pDialogueWindow = GUIWindowCreate(0, 0, 640, 350, 1, (GUIButton*)v2, 0);
  v1 = "";
  dword_5076F4 = GUIButtonCreate(pDialogueWindow,
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
                   uTextureID_right_backgr != -1 ?  &LODFile_Icons_LOD.aLODHeaders[uTextureID_right_backgr] : 0);
  GUIButtonCreate(pDialogueWindow, 0, 0, 0, 0, 1, 0, 81, 0, 0, NULL, 0);
  if ( dword_F8B1A8 )
    v1 = (char *)pGlobalTXT_LocalizationStrings[535];
  GUIButtonCreate(pDialogueWindow, 480, 160, 140, 30, 1, 0, 175, 79, 0, (unsigned char *)v1, 0);
  result = GUIWindow_sub_41D08F(pDialogueWindow, 1, 1, 0, 2);
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
  GUIWindowDelete(pDialogueWindow);
  pDialogueWindow = GUIWindowCreate(0, 0, 640, 350, 1, 0, 0);
  dword_5076F4 = GUIButtonCreate(pDialogueWindow, 471, 445,	169, 35, 1, 0, 113,	0, 0,
                   pGlobalTXT_LocalizationStrings[34],
                   uTextureID_right_backgr != -1 ?  &LODFile_Icons_LOD.aLODHeaders[uTextureID_right_backgr] : 0);
  GUIButtonCreate(pDialogueWindow, 0, 0, 0, 0, 1, 0, 81, 0, 0, NULL, 0);

  if (pNPCStats->pProfessions[*(_DWORD *)(v1 + 24)].pBenefits)
  {
    GUIButtonCreate(pDialogueWindow, 480, 160, 140, 30, 1, 0, 175, 77, 0, pGlobalTXT_LocalizationStrings[407], 0);
    v0 = 1;
  }
  GUIButtonCreate(pDialogueWindow, 480, 30 * v0 + 160, 140, 30, 1, 0, 175, 76, 0, pGlobalTXT_LocalizationStrings[406], 0);
  result = GUIWindow_sub_41D08F(pDialogueWindow, v0 + 1, 1, 0, 2);
  dword_F8B19C = -1;
  return result;
}

//----- (004B4224) --------------------------------------------------------
int __thiscall sub_4B4224(void *_this)
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
  dword_5913F0 = (int)((char *)_this + 1);
  if ( (char *)_this + 1 == (void *)dword_591424 && dword_5C35D0 )
  {
    GUIWindowDelete(pDialogueWindow);
    pDialogueWindow = GUIWindowCreate(0, 0, 640, 480, 1, 0, 0);
    wsprintfA(byte_591098, (char *)pGlobalTXT_LocalizationStrings[411], pMapStats->pMapInfos[dword_5C35D0].pLocationName);
    dword_5076F4 = GUIButtonCreate(pDialogueWindow,
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
                     uTextureIdx_BtnEsc2 != -1 ?  &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_BtnEsc2] : 0,0);
    dword_5076FC = GUIButtonCreate(pDialogueWindow,
                     486,
                     445,
                     75,
                     33,
                     1,
                     0,
                     191,
                     1,
                     89,
                     (unsigned char *)byte_591098,
                     uTextureIdx_BtnYes2 != -1 ?  &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_BtnYes2] : 0,0);
    GUIButtonCreate(pDialogueWindow, uDialogueUIIconsOffsetX, uDialogueUIIconsOffsetY, 63, 73, 1, 0, 191, 1, 32, (unsigned char *)byte_591098, 0);
    result = (int)GUIButtonCreate(pDialogueWindow, 8, 8, 460, 344, 1, 0, 191, 1, 89, (unsigned char *)byte_591098, 0);
  }
  else
  {
    v17 = dword_5913D8[(_DWORD)((char *)_this - (dword_591080 != 0))];
    if ( dword_F8B19C == -1 )
    {
      GUIWindowDelete(pDialogueWindow);
    }
    else
    {
      for ( i = 0; i < dword_591424; ++i )
        GUIButton_sub_41D0D8(dword_5913F4[i]);
    }
    v4 = 1;
    pDialogueWindow = GUIWindowCreate(0, 0, 640, 345, 1, 0, 0);
    dword_5076F4 = GUIButtonCreate(pDialogueWindow,
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
                     uTextureID_right_backgr != -1 ?  &LODFile_Icons_LOD.aLODHeaders[uTextureID_right_backgr] : 0,0);
    GUIButtonCreate(pDialogueWindow, 8, 8, 450, 320, 1, 0, 81, 0, 0, NULL, 0);
    if ( dword_5913F0 == 1 && dword_591080 )
    {
      result = sub_4B3B42(dword_F8B198);
    }
    else
    {
      if ( *(_DWORD *)(v17 + 32) )
      {
        v1 = 1;
        GUIButtonCreate(pDialogueWindow, 480, 160, 140, 30, 1, 0, 175, 13, 0, NULL, 0);
      }
      v5 = *(void **)(v17 + 40);
      if ( v5 )
      {
        if ( v1 < 4 )
        {
          v6 = sub_4466C4(v5);
          if ( v6 == 1 || v6 == 2 )
            GUIButtonCreate(pDialogueWindow, 480, 30 * v1++ + 160, 140, 30, 1, 0, 175, 19, 0, NULL, 0);
        }
      }
      v7 = *(void **)(v17 + 44);
      if ( v7 )
      {
        if ( v1 < 4 )
        {
          v8 = sub_4466C4(v7);
          if ( v8 == 1 || v8 == 2 )
            GUIButtonCreate(pDialogueWindow, 480, 30 * v1++ + 160, 140, 30, 1, 0, 175, 20, 0, NULL, 0);
        }
      }
      v9 = *(void **)(v17 + 48);
      if ( v9 )
      {
        if ( v1 < 4 )
        {
          v10 = sub_4466C4(v9);
          if ( v10 == 1 || v10 == 2 )
            GUIButtonCreate(pDialogueWindow, 480, 30 * v1++ + 160, 140, 30, 1, 0, 175, 21, 0, NULL, 0);
        }
      }
      v11 = *(void **)(v17 + 52);
      if ( v11 )
      {
        if ( v1 < 4 )
        {
          v12 = sub_4466C4(v11);
          if ( v12 == 1 || v12 == 2 )
            GUIButtonCreate(pDialogueWindow, 480, 30 * v1++ + 160, 140, 30, 1, 0, 175, 22, 0, NULL, 0);
        }
      }
      v13 = *(void **)(v17 + 56);
      if ( v13 )
      {
        if ( v1 < 4 )
        {
          v14 = sub_4466C4(v13);
          if ( v14 == 1 || v14 == 2 )
            GUIButtonCreate(pDialogueWindow, 480, 30 * v1++ + 160, 140, 30, 1, 0, 175, 23, 0, NULL, 0);
        }
      }
      v15 = *(void **)(v17 + 60);
      if ( v15 )
      {
        if ( v1 < 4 )
        {
          v16 = sub_4466C4(v15);
          if ( v16 == 1 || v16 == 2 )
            GUIButtonCreate(pDialogueWindow, 480, 30 * v1++ + 160, 140, 30, 1, 0, 175, 24, 0, NULL, 0);
        }
      }
      GUIWindow_sub_41D08F(pDialogueWindow, v1, 1, 0, 2);
      v4 = 1;
      result = pDialogueWindow->dword_000028;
      dword_F8B1E0 = pDialogueWindow->dword_000028;
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
 #ifndef OLD_CODE
           
            Render_DrawRGBTexture_New(pD3DRenderer, 0, 352, uTextureID_GameUI_StatusBar);
#endif
#ifdef OLD_CODE
		   Render_DrawRGBTexture(pD3DRenderer, 0, 352, &cPCXID_GameUI_StatusBar);
#endif
  v5 = AlignText_Center(450, v3, pFontLucida);
  FontDrawText(pGUIWindow0, pFontLucida, v5 + 11, 357, v3, 0, 0, 0);
}

//----- (004B46F8) --------------------------------------------------------
int __fastcall sub_4B46F8(int a1)
{
  int v1; // eax@1
  int i; // edx@1

  v1 = 0;
  for ( i = 1; i <= a1; ++i )
    v1 += i;
  return 1000 * v1;
}

//----- (004B4710) --------------------------------------------------------
void __cdecl sub_4B4710()
{
 int result;
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
  const unsigned char *v32; // ST18_4@38
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

  GUI::Window local_0C;
  //int v68; // [sp+Ch] [bp-78h]@1
  //int v69; // [sp+14h] [bp-70h]@1
  //int v70; // [sp+1Ch] [bp-68h]@1

  __int64 v71; // [sp+60h] [bp-24h]@3
  unsigned int v72; // [sp+68h] [bp-1Ch]@1
  int v73; // [sp+6Ch] [bp-18h]@3
  int v74; // [sp+70h] [bp-14h]@8
  unsigned int i; // [sp+74h] [bp-10h]@1
  __int16 v76[2]; // [sp+78h] [bp-Ch]@1
  int v77; // [sp+7Ch] [bp-8h]@18
  int v78; // [sp+80h] [bp-4h]@16

  v3 = (int)pPlayers[uActiveCharacter - 1];
  memcpy(&local_0C, ptr_507BC0, sizeof(GUI::Window));
  local_0C.uFrameX = 483;
  local_0C.uFrameWidth = 148;
  local_0C.uFrameZ = 334;
  v72 = 0xFFFFFF;
  v4 = 0xE1CD23;
  v2 = *(_WORD *)(v3 + 218);
  *(_DWORD *)v76 = v4;
  v0 = 0;
  v1 = 0;
  for ( i = v2; v1 < v2; ++v1 )
    v0 += v1 + 1;
  v7 = 1000 * v0;
  v8 = *(_DWORD *)(v3 + 164);
  v6 = ptr_507BC0->dword_00001C;
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
      v10 = v11 * (100 - Player_sub_4911F3((Player *)v3)) / 100;
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
            v14 = (int)pDialogueWindow;
            v15 = (signed __int64)(*((float *)&unk_59145C + 13 * ptr_507BC0->dword_00001C) * 500.0);
            v78 = v15 * (100 - Player_sub_4911F3((Player *)v3)) / 100;
            if ( v78 < v15 / 3 )
              v78 = v15 / 3;
            v16 = *(_DWORD *)(v14 + 56);
            v17 = *(_DWORD *)(v14 + 40);
            v77 = 0;
            if ( v16 >= v16 + v17 )
              goto LABEL_82;
            do
            {
              v18 = *(_DWORD *)(GUIWindow_GetChild((GUI::Window *)v14, v16) + 36) - 36;
              if ( *(&byte_4ED970[37 * *(_BYTE *)(v3 + 185)] + v18) )
              {
                if ( !*(_WORD *)(v3 + 2 * v18 + 264) )
                {
                  v19 = GUIFont_CalculateTextHeight(pFontArrus, aSkillNames[v18], &local_0C, 0, 0);
                  i += v19;
                  ++v77;
                }
              }
              ++v16;
            }
            while ( v16 < *(_DWORD *)(v14 + 40) + *(_DWORD *)(v14 + 56) );
            if ( v77 )
            {
              wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[401], v78);
              GUIWindow_DrawText(&local_0C, pFontArrus, 0, 146, 0, (char *)TmpBuf, 3);
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
                  v23 = (int)GUIWindow_GetChild((GUI::Window *)v14, i);
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
                    v26 = (char *)aSkillNames[v21];
                    *(_DWORD *)(v22 + 4) = v78 + v73;
                    HIDWORD(v71) = (int)v26;
                    v27 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v26, &local_0C, 0, 0);
                    v25 = *(_DWORD *)(v22 + 4);
                    *(_DWORD *)(v22 + 12) = v27;
                    v28 = v25 + v27 - 1;
                    *(_DWORD *)(v22 + 20) = v28;
                    v73 = v28;
                    v24 = v76[0];
                    if (pDialogueWindow->dword_00002C != v77 )
                      v24 = v72;
                    GUIWindow_DrawText(&local_0C, pFontArrus, 0, v25, v24, (char *)HIDWORD(v71), 3);
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
              wsprintfA((char *)TmpBuf,
                (char *)pGlobalTXT_LocalizationStrings[544],
                v3 + 168,
                aClassNames[*(_BYTE *)(v3 + 185)]);
              strcat((char *)(char *)TmpBuf, "\n \n");
              strcat((char *)(char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[528]);
              v30 = v76[0];
              v31 = GUIFont_CalculateTextHeight(pFontArrus, TmpBuf, &local_0C, 0, 0);
              GUIWindow_DrawText(&local_0C, pFontArrus, 0, (174 - v31) / 2 + 138, v30, (char *)TmpBuf, 3);
            }
          }
        }
        return;
      }
      if ( !sub_4B1784() )
      {
        v32 = dword_721A3C;
        v33 = v76[0];
        v34 = GUIFont_CalculateTextHeight(pFontArrus, dword_721A3C, &local_0C, 0, 0);
        GUIWindow_DrawText(&local_0C, pFontArrus, 0, (212 - v34) / 2 + 101, v33, (char *)v32, 3);
        //result = (int)pDialogueWindow;
        pDialogueWindow->dword_000028 = 0;
        return;// result;
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
            sub_4B1E92(ptr_507BC0->dword_00001C, 2);
            ++*(_WORD *)(v3 + 218);
            *(_DWORD *)(v3 + 6456) += *(_WORD *)(v3 + 218) / 10 + 5;
            *(_DWORD *)(v3 + 6460) = Player_GetMaxHealth((Player *)v3);
            *(_DWORD *)(v3 + 6464) = Player_GetMaxMana((Player *)v3);
            v40 = 0;
            v39 = (signed int)&unk_F8B148;
            do
            {
              if ( *(_DWORD *)v39 > v40 )
                v40 = *(_DWORD *)v39;
              v39 += 4;
            }
            while ( v39 < (signed int)word_F8B158 );
            v41 = (int)pPlayers[uActiveCharacter - 1];
            ++*(&dword_F8B144 + uActiveCharacter);
            if ( *(_DWORD *)v41 > v40 )
            {
              v44 = sub_494820(pParty_global->uCurrentHour);
              v43 = ptr_507BC0->dword_00001C;
              v42 = 60 * (v44 + 4) - pParty_global->uCurrentMinute;
              if ( v43 == 94 || v43 == 95 )
                v42 += 720;
              sub_4B1BDB(v42 + 10080);
              if ( uCurrentlyLoadedLevelType == 2 )
                sub_489487();
            }
            Player_PlaySound((Player *)v3, 87, 0);
            wsprintfA((char *)TmpBuf,
              (char *)pGlobalTXT_LocalizationStrings[430],
              v3 + 168,
              *(_WORD *)(v3 + 218),
              *(_WORD *)(v3 + 218) / 10 + 5);
            sub_44C175((char *)TmpBuf, 2);
            goto LABEL_60;
          }
          sub_44C175((char *)pGlobalTXT_LocalizationStrings[155], 2);
          v66 = 4;
LABEL_59:
          sub_4B1E92(ptr_507BC0->dword_00001C, v66);
LABEL_60:
          //result = dword_50CBD0[0];
         /* if ( dword_50CBD0[0] < 40 )
          {
            dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
            dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
            result = 3 * dword_50CBD0[0] + 3;
            dword_50CBD0[result] = 0;
            ++dword_50CBD0[0];
          }	   */
		  dword_50CBD0.PutMessageToQueue(113,1,0);
          return;// result;
        }
        wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[538], v7 - *(_DWORD *)(v3 + 160), v35 + 1);
        v37 = 0;
        v65 = 3;
        v63 = (char *)TmpBuf;
        v61 = v76[0];
        v36 = (212 - GUIFont_CalculateTextHeight(pFontArrus, TmpBuf, &local_0C, 0, 0)) / 2 + 88;
      }
      else
      {
        wsprintfA((char *)TmpBuf, "%s\n \n%s", (char *)pGlobalTXT_LocalizationStrings[536], pGlobalTXT_LocalizationStrings[529]);
        v37 = 0;
        v65 = 3;
        v63 = (char *)TmpBuf;
        v61 = v76[0];
        v36 = (212 - GUIFont_CalculateTextHeight(pFontArrus, TmpBuf, &local_0C, 0, 0)) / 2 + 101;
      }
      GUIWindow_DrawText(&local_0C, pFontArrus, v37, v36, v61, v63, v65);
      v66 = 3;
      goto LABEL_59;
    }
    result = sub_4B1784();
    if ( result )
    {
      v45 = (int)pDialogueWindow;
      v77 = 0;
      dword_F8B1B8[0] = TmpBuf;
      dword_F8B1B8[1] = pGlobalTXT_LocalizationStrings[160];
      v46 = pDialogueWindow->dword_000028;
      v78 = pDialogueWindow->dword_000038;
      if ( v78 < v78 + v46 )
      {
        v47 = (const char **)dword_F8B1B8;
        do
        {
          if ( *(_DWORD *)(GUIWindow_GetChild((GUI::Window *)v45, v78) + 36) == 17 )
          {
            v48 = *(_WORD *)(v3 + 218);
            if ( v48 < v73 )
            {
              v49 = *(_DWORD *)(v3 + 164);
              if ( v49 < HIDWORD(v71) || v49 <= HIDWORD(v71) && *(_DWORD *)(v3 + 160) < (_DWORD)v71 )
              {
                v67 = v48 + 1;
                v64 = v7 - *(_DWORD *)(v3 + 160);
                v62 = (int)pGlobalTXT_LocalizationStrings[538];
              }
              else
              {
                v67 = i;
                v64 = v48 + 1;
                v62 = (int)pGlobalTXT_LocalizationStrings[537];
              }
            }
            else
            {
              v67 = (int)pGlobalTXT_LocalizationStrings[529];
              v64 = (int)pGlobalTXT_LocalizationStrings[536];
              v62 = (int)"%s\n \n%s";
            }
            wsprintfA((char *)*v47, (const char *)v62, v64, v67);
          }
          v50 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v47, &local_0C, 0, 0);
          v45 = (int)pDialogueWindow;
          v77 += v50;
          ++v47;
          ++v78;
        }
        while ( v78 < pDialogueWindow->dword_000028 + pDialogueWindow->dword_000038);
      }
      HIDWORD(v71) = (174 - v77) / 2;
      result = *(_DWORD *)(v45 + 56);
      v52 = result + *(_DWORD *)(v45 + 40);
      v51 = (2 * (87 - (174 - v77) / 2) - v77) / 2 - (174 - v77) / 2 / 2 + 138;
      v53 = -*(_DWORD *)(v45 + 40) < 0;
      v78 = *(_DWORD *)(v45 + 56);

      compile_error();//if ( v53 ^ __SETO__(result, v52) )
      if (1)
      {
        i = 2;
        v54 = (const char **)dword_F8B1B8;
        do
        {
          v57 = (int)GUIWindow_GetChild((GUI::Window *)v45, v78);
          v58 = v57;
          *(_DWORD *)(v57 + 4) = HIDWORD(v71) + v51;
          v59 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v54, &local_0C, 0, 0);
          v56 = *(_DWORD *)(v58 + 4);
          *(_DWORD *)(v58 + 12) = v59;
          v60 = v59 + v56 - 1;
          *(_DWORD *)(v58 + 20) = v60;
          v51 = v60;
          v55 = v76[0];
          if (pDialogueWindow->dword_00002C != i)
            v55 = v72;
          GUIWindow_DrawText(&local_0C, pFontArrus, 0, v56, v55, *v54, 3);
          v45 = (int)pDialogueWindow;
          ++i;
          ++v54;
          ++v78;
          result = pDialogueWindow->dword_000028 + pDialogueWindow->dword_000038;
        }
        while ( v78 < result );
      }
    }
  }
}

//----- (004B4F4F) --------------------------------------------------------
void __cdecl sub_4B4F4F()
{
  const char *v2; // ST10_4@1
  unsigned __int16 v3; // ST0C_2@1
  int v4; // eax@1

  GUI::Window local_08;
  //int v5; // [sp+8h] [bp-54h]@1
  //int v6; // [sp+10h] [bp-4Ch]@1
  //int v7; // [sp+18h] [bp-44h]@1

  memcpy(&local_08, ptr_507BC0, sizeof(GUI::Window));
  v2 = (char *)pGlobalTXT_LocalizationStrings[672];
  local_08.uFrameX = 483;
  local_08.uFrameWidth = 148;
  local_08.uFrameZ = 334;
  v3 = 0xFFFFFF9B;
  v4 = GUIFont_CalculateTextHeight(pFontArrus, pGlobalTXT_LocalizationStrings[672], &local_08, 0, 0);
  GUIWindow_DrawText(&local_08, pFontArrus, 0, (310 - v4) / 2 + 18, v3, v2, 3);
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

  GUI::Window local_7C;
  //int v113; // [sp+7Ch] [bp-7Ch]@1
  //int v114; // [sp+84h] [bp-74h]@1
  //int v115; // [sp+8Ch] [bp-6Ch]@1

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

  v0 = pPlayers[uActiveCharacter - 1];
  v123 = (int)pPlayers[uActiveCharacter - 1];
  memcpy(&local_7C, ptr_507BC0, sizeof(GUI::Window));
  local_7C.uFrameX = 483;
  local_7C.uFrameWidth = 148;
  local_7C.uFrameZ = 334;
  *(_DWORD *)v119 = 0xFFFFFF;
  *(_DWORD *)v118 = 0xE1CD23;
  if ( dword_F8B19C > 5 )
  {
    if ( dword_F8B19C == 94 )
    {
      sub_41A556();
      CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
      dword_F8B1B8[0] = pGlobalTXT_LocalizationStrings[200];
      dword_F8B1B8[1] = pGlobalTXT_LocalizationStrings[113];
      dword_F8B1B8[2] = pGlobalTXT_LocalizationStrings[179];
      v77 = 0;
      v76 = (const char **)dword_F8B1B8;
      do
      {
        v78 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v76, &local_7C, 0, 0);
        ++v76;
        v77 += v78;
      }
      while ( (signed int)v76 < (signed int)&dword_F8B1B8[3] );
      v79 = (int)pDialogueWindow;
      v123 = (174 - v77) / 3;
      result = pDialogueWindow->dword_000038;
      v81 = result + pDialogueWindow->dword_000028;
      v80 = (3 * (58 - v123) - v77) / 2 - (174 - v77) / 3 / 2 + 138;
      v82 = -pDialogueWindow->dword_000028 < 0;
      v121 = pDialogueWindow->dword_000038;

      compile_error();//if ( v82 ^ __SETO__(result, v81) )
      if (1)
      {
        v125 = 2;
        v122 = (int)dword_F8B1B8;
        do
        {
          v85 = (int)GUIWindow_GetChild((GUI::Window *)v79, v121);
          v86 = (const char **)v122;
          *(_DWORD *)(v85 + 4) = v123 + v80;
          v87 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v86, &local_7C, 0, 0);
          v84 = *(_DWORD *)(v85 + 4);
          v88 = v125;
          *(_DWORD *)(v85 + 12) = v87;
          v80 = v87 + v84 - 1;
          *(_DWORD *)(v85 + 20) = v80;
          v83 = v118[0];
          if (pDialogueWindow->dword_00002C != v88 )
            v83 = v119[0];
          GUIWindow_DrawText(&local_7C, pFontArrus, 0, v84, v83, *(const char **)v122, 3);
          v79 = (int)pDialogueWindow;
          ++v125;
          v122 += 4;
          ++v121;
          result = pDialogueWindow->dword_000028 + pDialogueWindow->dword_000038;
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
          v31 = (int)pDialogueWindow;
          v3 = 0;
          v33 = ptr_507BC0->dword_00001C;
          v121 = 0;
          v32 = (signed __int64)(*((float *)&unk_59145C + 13 * v33) * 500.0);
          v122 = v32 * (100 - Player_sub_4911F3((Player *)v123)) / 100;
          if ( v122 < v32 / 3 )
            v122 = v32 / 3;
          v34 = *(_DWORD *)(v31 + 56);
          v35 = v34 + *(_DWORD *)(v31 + 40);
          v125 = 0;
          if ( v34 >= v35 )
            goto LABEL_140;
          do
          {
            v36 = *(_DWORD *)(GUIWindow_GetChild((GUI::Window *)v31, v34) + 36) - 36;
            if ( *(&byte_4ED970[37 * *(_BYTE *)(v123 + 185)] + v36) )
            {
              if ( !*(_WORD *)(v123 + 2 * v36 + 264) )
              {
                v37 = GUIFont_CalculateTextHeight(pFontArrus, aSkillNames[v36], &local_7C, 0, 0);
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
            wsprintfA((char *)TmpBuf,
              (char *)pGlobalTXT_LocalizationStrings[544],
              v123 + 168,
              aClassNames[*(_BYTE *)(v123 + 185)]);
            strcat((char *)TmpBuf, "\n \n");
            strcat((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[528]);
            v30 = (char *)TmpBuf;
            v98 = 3;
            v96 = (char *)TmpBuf;
            v93 = v118[0];
            v92 = 0;
            v90 = 0;
            v89 = (int)&local_7C;
            goto LABEL_61;
          }
          wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[401], v122);
          GUIWindow_DrawText(&local_7C, pFontArrus, 0, 146, 0, (char *)TmpBuf, 3);
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
              v41 = (int)GUIWindow_GetChild((GUI::Window *)v31, v121);
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
                v44 = (char *)aSkillNames[v39];
                *(_DWORD *)(v40 + 4) = v122 + v117;
                Str = v44;
                v45 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v44, &local_7C, 0, 0);
                v43 = *(_DWORD *)(v40 + 4);
                v46 = v125;
                *(_DWORD *)(v40 + 12) = v45;
                v47 = v43 + v45 - 1;
                *(_DWORD *)(v40 + 20) = v47;
                v117 = v47;
                v42 = v118[0];
                if (pDialogueWindow->dword_00002C != v46 )
                  v42 = v119[0];
                GUIWindow_DrawText(&local_7C, pFontArrus, 0, v43, v42, Str, 3);
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
      CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
      sub_4B46A5((char *)pGlobalTXT_LocalizationStrings[198], 0);
      result = sub_4B1784();
      if ( !result
        || (v27 = *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v111) - 14,
            v120 = (v27 >> 5) + 14 * ((*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v109) + 4) - 17) >> 5),
            result = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v107),
            *(_DWORD *)result <= 13)
        || (result = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v105), *(_DWORD *)result >= 462)
        || (result = Player_sub_421E75_GetItemAtInventoryIndex((Player *)v0, &v120), v3 = 0, !result)
        || (result *= 9, !(*(_BYTE *)(v123 + 4 * result + 516) & 2)) )
        return result;
      v97 = 0;
      v95 = 5;
      v94 = ptr_507BC0->dword_00001C;
      v91 = v123 + 4 * result + 496;
      v28 = ptr_507BC0->dword_00001C;
      v124 = uActiveCharacter;
      v29 = Player_sub_490EEE((Player *)v123, v123 + 4 * result + 496, 3, v28, 5);
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
        dword_F8B1B8[1] = pGlobalTXT_LocalizationStrings[152];
        dword_F8B1B8[2] = pGlobalTXT_LocalizationStrings[636];
        v14 = 0;
        dword_F8B1B8[3] = pGlobalTXT_LocalizationStrings[160];
        v15 = (const char **)dword_F8B1B8;
        do
        {
          v16 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v15, &local_7C, 0, 0);
          ++v15;
          v14 += v16;
        }
        while ( (signed int)v15 < (signed int)&unk_F8B1C8 );
        v17 = (int)pDialogueWindow;
        v117 = (174 - v14) / 4;
        result = pDialogueWindow->dword_000038;
        v19 = result + pDialogueWindow->dword_000028;
        v18 = (174 - 4 * (174 - v14) / 4 - v14) / 2 - (174 - v14) / 4 / 2 + 138;
        v20 = -pDialogueWindow->dword_000028 < 0;
        v125 = pDialogueWindow->dword_000038;

        compile_error();//if ( v20 ^ __SETO__(result, v19) )
        if (1)
        {
          v122 = 2;
          v123 = (int)dword_F8B1B8;
          do
          {
            v23 = (int)GUIWindow_GetChild((GUI::Window *)v17, v125);
            v24 = (const char **)v123;
            *(_DWORD *)(v23 + 4) = v117 + v18;
            v25 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v24, &local_7C, 0, 0);
            v22 = *(_DWORD *)(v23 + 4);
            v26 = v122;
            *(_DWORD *)(v23 + 12) = v25;
            v18 = v22 + v25 - 1;
            *(_DWORD *)(v23 + 20) = v18;
            v21 = v118[0];
            if (pDialogueWindow->dword_00002C != v26 )
              v21 = v119[0];
            GUIWindow_DrawText(&local_7C, pFontArrus, 0, v22, v21, *(const char **)v123, 3);
            v17 = (int)pDialogueWindow;
            ++v122;
            v123 += 4;
            ++v125;
            result = pDialogueWindow->dword_000028 + pDialogueWindow->dword_000038;
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
          CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
          sub_4B46A5((char *)pGlobalTXT_LocalizationStrings[197], 0);
          result = sub_4B1784();
          if ( result )
          {
            v2 = *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v110) - 14;
            v120 = (v2 >> 5) + 14 * ((*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v99) + 4) - 17) >> 5);
            result = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v112);
            if ( *(_DWORD *)result > 13 )
            {
              result = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v104);
              if ( *(_DWORD *)result < 462 )
              {
                result = Player_sub_421E75_GetItemAtInventoryIndex((Player *)v0, &v120);
                v3 = 0;
                if ( result )
                {
                  v97 = 0;
                  v95 = 4;
                  v4 = v123 + 36 * result + 496;
                  if ( *(_BYTE *)(v4 + 20) & 1 )
                  {
                    v6 = (char *)sub_495461_DrawAn_AreYouSureWishTo_Join_Dismiss_ThisNPC_Dialogue((unsigned char *)"%24", uActiveCharacter, v4, ptr_507BC0->dword_00001C, 4, 0);
                    v98 = 3;
                    v96 = v6;
                    v93 = v119[0];
                    v5 = (212 - GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v6, &local_7C, 0, 0)) / 2 + 101;
                    GUIWindow_DrawText(&local_7C, pFontArrus, v3, v5, v93, v96, v98);
                    return result;
                  }
                  v94 = ptr_507BC0->dword_00001C;
                  v91 = v4;
                  v9 = ptr_507BC0->dword_00001C;
                  v124 = uActiveCharacter;
                  v10 = Player_sub_490EEE((Player *)v123, v4, 3, v9, 4);
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
      CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
      sub_4B46A5((char *)pGlobalTXT_LocalizationStrings[199], 0);
      result = sub_4B1784();
      if ( !result
        || (v11 = *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v108) - 14,
            v120 = (v11 >> 5) + 14 * ((*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v100) + 4) - 17) >> 5),
            result = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v106),
            *(_DWORD *)result <= 13)
        || (result = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v102), *(_DWORD *)result >= 462)
        || (result = Player_sub_421E75_GetItemAtInventoryIndex((Player *)v0, &v120), v3 = 0, !result) )
        return result;
      v97 = 0;
      v95 = 3;
      v94 = ptr_507BC0->dword_00001C;
      v91 = v123 + 36 * result + 496;
      v12 = ptr_507BC0->dword_00001C;
      v124 = uActiveCharacter;
      v13 = Player_sub_490EEE((Player *)v123, v91, 3, v12, 3);
      v7 = v124;
      v8 = dword_73C3A4[v13];
LABEL_35:
      v30 = (char *)sub_495461_DrawAn_AreYouSureWishTo_Join_Dismiss_ThisNPC_Dialogue((unsigned char *)v8, v7, v91, v94, v95, v97);
      v98 = 3;
      v96 = v30;
      v93 = v119[0];
      v92 = v3;
      v90 = v3;
      v89 = (int)&local_7C;
LABEL_61:
      v5 = (174 - GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v30, (GUI::Window *)v89, v90, v92)) / 2 + 138;
      GUIWindow_DrawText(&local_7C, pFontArrus, v3, v5, v93, v96, v98);
      return result;
    }
  }
  Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (cTexture *)dword_F8B164[0]);
  v3 = 0;
  v49 = 0;
  v125 = 0;
  if ( dword_F8B19C == 2 )
  {
    do
    {
      if ( dword_AD4734[9 * (v49 + 12 * ptr_507BC0->dword_00001C)] )
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
        Render_DrawTransparentTexture(pD3DRenderer, v52, v51, (cTexture *)v50);
        sub_40F92A((int)&pD3DRenderer->pActiveZBuffer[v52 + 640 * v51], dword_F8B168[v125], v125 + 1);
        v49 = v125;
      }
      ++v49;
      v125 = v49;
    }
    while ( v49 < 6 );
    v125 = 0;
    do
    {
      if ( dword_AD480C[9 * (v125 + 12 * ptr_507BC0->dword_00001C)] )
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
        Render_DrawTransparentTexture(pD3DRenderer, v56, v55, (cTexture *)v54);
        sub_40F92A((int)&pD3DRenderer->pActiveZBuffer[v56 + 640 * v55], dword_F8B180[v125], v125 + 7);
      }
      ++v125;
    }
    while ( v125 < 6 );
  }
  else
  {
    do
    {
      if ( *(&dword_ADA0A4 + 9 * (v49 + 12 * ptr_507BC0->dword_00001C)) )
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
        Render_DrawTransparentTexture(pD3DRenderer, v60, v59, (cTexture *)v58);
        sub_40F92A((int)&pD3DRenderer->pActiveZBuffer[v60 + 640 * v59], dword_F8B168[v125], v125 + 1);
        v49 = v125;
      }
      ++v49;
      v125 = v49;
    }
    while ( v49 < 6 );
    v125 = 0;
    do
    {
      if ( dword_ADA17C[9 * (v125 + 12 * ptr_507BC0->dword_00001C)] )
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
        Render_DrawTransparentTexture(pD3DRenderer, v64, v63, (cTexture *)v62);
        sub_40F92A((int)&pD3DRenderer->pActiveZBuffer[v64 + 640 * v63], dword_F8B180[v125], v125 + 7);
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
        if ( dword_AD4734[9 * (v66 + 12 * ptr_507BC0->dword_00001C)] )
          ++v120;
        ++v66;
      }
      while ( v66 < 12 );
    }
    else
    {
      do
      {
        if ( *(&dword_ADA0A4 + 9 * (v66 + 12 * ptr_507BC0->dword_00001C)) )
          ++v120;
        ++v66;
      }
      while ( v66 < 12 );
    }
    v68 = GetAsyncKeyState(VK_CONTROL);
    v67 = Player_sub_492C40((Player *)v123);
    Str = (char *)v67;
    if ( v68 && v67 )
    {
      v69 = (char *)pGlobalTXT_LocalizationStrings[185];
    }
    else
    {
      v69 = (char *)pGlobalTXT_LocalizationStrings[195];
      if ( dword_F8B19C != 2 )
        v69 = (char *)pGlobalTXT_LocalizationStrings[196];
    }
    sub_4B46A5(v69, 0);
    if ( !v120 )
      compile_error();//return (signed int)sub_4B1854(
                    //       &v113,
                    //       __PAIR__(
                    //         dword_ACD048[2 * *(_DWORD *)(dword_507BC0 + 28)],
                    //         dword_ACD044[2 * *(_DWORD *)(dword_507BC0 + 28)])
                    //     - pParty_global->qword_00002C);
    v70 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v103);
    result = *(_DWORD *)v70 + dword_5059A8[*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v101) + 4)];
    if ( *(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * result) & 0xFFFF )
    {
      v74 = (*(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * result) & 0xFFFF) - 1;
      v120 = v74;
      v71 = ptr_507BC0->dword_00001C;
      v72 = 9 * (v74 + 12 * v71);
      v73 = 4 * v72 + 11355956;
      if ( dword_F8B19C != 2 )
        v73 = 4 * v72 + 11378852;
      if ( v68 && Str )
      {
        v8 = (int)pGlobalTXT_LocalizationStrings[181];
        v97 = 0;
        v95 = 2;
        v94 = ptr_507BC0->dword_00001C;
        v91 = v73;
        v7 = uActiveCharacter;
      }
      else
      {
        v97 = 0;
        v95 = 2;
        v94 = ptr_507BC0->dword_00001C;
        v91 = v73;
        v124 = uActiveCharacter;
        v75 = Player_sub_490EEE((Player *)v123, v73, 3, v71, 2);
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

  GUI::Window local_274;
  //int v52; // [sp+274h] [bp-78h]@1
  //int v53; // [sp+27Ch] [bp-70h]@1
  //int v54; // [sp+284h] [bp-68h]@1

  int v55; // [sp+2C8h] [bp-24h]@47
  __int16 v56[2]; // [sp+2CCh] [bp-20h]@1
  __int16 v57[2]; // [sp+2D0h] [bp-1Ch]@1
  int v58; // [sp+2D4h] [bp-18h]@1
  unsigned __int8 v59; // [sp+2DBh] [bp-11h]@31
  char *Str; // [sp+2DCh] [bp-10h]@35
  int v61; // [sp+2E0h] [bp-Ch]@35
  int v62; // [sp+2E4h] [bp-8h]@13
  int v63; // [sp+2E8h] [bp-4h]@1

  v2 = (int)ptr_507BC0;
  memcpy(&local_274, ptr_507BC0, sizeof(GUI::Window));
  v58 = (int)pPlayers[uActiveCharacter - 1];
  v1 = (void *)v58;
  local_274.uFrameX = 483;
  local_274.uFrameWidth = 148;
  local_274.uFrameZ = 334;
  *(_DWORD *)v56 = 0xFFFFFF;
  *(_DWORD *)v57 = 0xFFFF9B;
  v0 = (signed __int64)(*((float *)&unk_591458 + 13 * *(_DWORD *)(v2 + 28)) * 500.0);
  v63 = v0 * (100 - Player_sub_4911F3((Player *)v1)) / 100;
  if ( v63 < v0 / 3 )
    v63 = v0 / 3;
  strcpy(&Dest, "");
  strcpy(&v46, "");
  strcpy(&v47, "");
  strcpy(&v48, "");
  strcpy(&v49, "");
  if ( dword_F8B19C != 1 )
  {
    if ( dword_F8B19C != 18 )
    {
      if ( sub_4B1784() )
      {
        v3 = (int)((char *)v1 + 2 * dword_F8B19C + 192);
        if ( *(_WORD *)v3 )
        {
          wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[403], aClassNames[20 + dword_F8B19C]);
          sub_44C175((char *)TmpBuf, 2);
          pAudioPlayer->sub_4AA306(27, 0, 0, -1, 0, 0, 0, 0);
        }
        else
        {
          if ( pParty_global->uNumGold < (unsigned int)v63 )
          {
            sub_44C175((char *)pGlobalTXT_LocalizationStrings[155], 2);
            sub_4B1E92(ptr_507BC0->dword_00001C, 2);
          }
          else
          {
            sub_492BB6(v63);
            *(_WORD *)v3 = 1;
          }
        }
      }
      result = 0;// dword_50CBD0[0];
    /*  if ( dword_50CBD0[0] < 40 )
      {
        dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
        dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
        result = 3 * dword_50CBD0[0] + 3;
        dword_50CBD0[result] = 0;
        ++dword_50CBD0[0];
      }	   */
	  dword_50CBD0.PutMessageToQueue(113,1,0);
      return result;
    }
    Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (cTexture *)dword_F8B164[0]);
    v5 = 0;
    v6 = 0;
    v62 = 0;
    v63 = 32;
    do
    {
      if ( dword_AD0F84[9 * (v6 + 12 * ptr_507BC0->dword_00001C)] )
      {
        Render_DrawTransparentTexture(pD3DRenderer, v63, 90, (cTexture *)dword_F8B168[v6]);
        array_40F89C_ActuallyFillZBuffer(v62 + pD3DRenderer->pActiveZBuffer + 230528, (cTexture *)dword_F8B168[v6], v6 + 1);
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
      if ( dword_AD0F84[9 * (v7 + 12 * ptr_507BC0->dword_00001C)] )
      {
        Render_DrawTransparentTexture(pD3DRenderer, v63, 250, (cTexture *)dword_F8B168[v7]);
        array_40F89C_ActuallyFillZBuffer(v62 + pD3DRenderer->pActiveZBuffer + 638448, (cTexture *)dword_F8B168[v7], v7 + 1);
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
      v8 = &dword_AD0F84[108 * ptr_507BC0->dword_00001C];
      do
      {
        if ( *v8 )
          ++v10;
        v8 += 9;
        --v9;
      }
      while ( v9 );
      GetAsyncKeyState(VK_CONTROL);
      v11 = (char *)pGlobalTXT_LocalizationStrings[195];
      if ( dword_F8B19C != 2 )
        v11 = (char *)pGlobalTXT_LocalizationStrings[196];
      sub_4B46A5(v11, 0);
      if ( !v10 )
        compile_error();//return (signed int)sub_4B1854(
                      //       &v52,
                      //       __PAIR__(
                      //         dword_ACCD98[2 * *(_DWORD *)(dword_507BC0 + 28)],
                      //         dword_ACCD94[2 * *(_DWORD *)(dword_507BC0 + 28)])
                      //     - pParty_global->qword_00002C);
      v13 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v51);
      result = *(_DWORD *)v13 + dword_5059A8[*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v50) + 4)];
      v12 = pD3DRenderer->pActiveZBuffer[result] & 0xFFFF;
      if ( pD3DRenderer->pActiveZBuffer[result] & 0xFFFF )
      {
        v15 = ptr_507BC0->dword_00001C;
        v16 = 36 * (v12 + 12 * v15) + 11341664;
        v17 = ptr_507BC0->dword_00001C;
        v59 = uActiveCharacter;
        v18 = Player_sub_490EEE((Player *)v1, 36 * (v12 + 12 * v15) + 11341664, 3, v17, 2);
        v14 = (char *)sub_495461_DrawAn_AreYouSureWishTo_Join_Dismiss_ThisNPC_Dialogue(&dword_73C388[v18 * 4], v59, v16, v15, 2, 0);
        v44 = 3;
        v43 = v14;
        v42 = v56[0];
        v41 = 0;
        v40 = 0;
        v39 = (int)&local_274;
LABEL_32:
        v19 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v14, (GUI::Window *)v39, v40, v41);
        GUIWindow_DrawText(&local_274, pFontArrus, v5, (174 - v19) / 2 + 138, v42, v43, v44);
        return result;
      }
    }
    return result;
  }
  if ( !(unsigned __int16)sub_449B57((unsigned char *)((char *)v1 + 338), word_4F0704[2 * ptr_507BC0->dword_00001C]) )
  {
    v36 = (char *)dword_721A34;
    v37 = v57[0];
    v38 = GUIFont_CalculateTextHeight(pFontArrus, dword_721A34, &local_274, 0, 0);
    GUIWindow_DrawText(&local_274, pFontArrus, 0, (212 - v38) / 2 + 101, v37, v36, 3);
    result = (int)pDialogueWindow;
    pDialogueWindow->dword_000028 = 0;
    return result;
  }
  result = sub_4B1784();
  if ( !result )
    return result;
  v20 = (int)pDialogueWindow;
  v5 = 0;
  v62 = 0;
  Str = 0;
  v21 = pDialogueWindow->dword_000038;
  v22 = v21 + pDialogueWindow->dword_000028;
  v61 = 0;
  if ( v21 >= v22 )
    goto LABEL_64;
  do
  {
    v23 = *(_DWORD *)(GUIWindow_GetChild((GUI::Window *)v20, v21) + 36);
    if ( v23 == 18 )
    {
      v25 = GUIFont_CalculateTextHeight(pFontArrus, pGlobalTXT_LocalizationStrings[400], &local_274, 0, 0);
      v62 += v25;
      ++v61;
    }
    else
    {
      if ( *(&byte_4ED94C[37 * *(_BYTE *)(v58 + 185)] + v23) )
      {
        if ( !*(_WORD *)(v58 + 2 * v23 + 192) )
        {
          v24 = GUIFont_CalculateTextHeight(pFontArrus, aClassNames[20 + v23], &local_274, 0, 0);
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
    wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[544], v58 + 168, aClassNames[*(_BYTE *)(v58 + 185)]);

    strcat((char *)TmpBuf, "\n \n");
    strcat((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[528]);
    v14 = (char *)TmpBuf;
    v44 = 3;
    v43 = (char *)TmpBuf;
    v42 = v57[0];
    v41 = 0;
    v40 = 0;
    v39 = (int)&local_274;
    goto LABEL_32;
  }
  if ( Str )
  {
    wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[401], v63);
    GUIWindow_DrawText(&local_274, pFontArrus, 0, 146, 0, (char *)TmpBuf, 3);
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
      v29 = (int)GUIWindow_GetChild((GUI::Window *)v20, v62);
      v28 = v29;
      v27 = *(_DWORD *)(v29 + 36);
      if ( v27 == 18 )
        break;
      if ( *(&byte_4ED94C[37 * *(_BYTE *)(v58 + 185)] + v27) && !*(_WORD *)(v58 + 2 * v27 + 192) )
      {
        v30 = (char *)aClassNames[20 + v27];

LABEL_55:
        Str = v30;
        *(_DWORD *)(v28 + 4) = v63 + v55;
        v33 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v30, &local_274, 0, 0);
        v32 = *(_DWORD *)(v28 + 4);
        *(_DWORD *)(v28 + 12) = v33;
        v34 = v32 + v33 - 1;
        *(_DWORD *)(v28 + 20) = v34;
        v55 = v34;
        v31 = v57[0];
        if (pDialogueWindow->dword_00002C != v61 )
          v31 = v56[0];
        GUIWindow_DrawText(&local_274, pFontArrus, 0, v32, v31, Str, 3);
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
    v30 = (char *)pGlobalTXT_LocalizationStrings[400];
    goto LABEL_55;
  }
  return result;
}

//----- (004B6478) --------------------------------------------------------
void __cdecl sub_4B6478()
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

  GUI::Window local_0C;
  //int v28; // [sp+Ch] [bp-70h]@1
  //int v29; // [sp+14h] [bp-68h]@1
  //int v30; // [sp+1Ch] [bp-60h]@1

  int v31; // [sp+60h] [bp-1Ch]@17
  unsigned int v32; // [sp+64h] [bp-18h]@1
  __int16 v33[2]; // [sp+68h] [bp-14h]@1
  int v34; // [sp+6Ch] [bp-10h]@1
  int v35; // [sp+70h] [bp-Ch]@17
  int v36; // [sp+74h] [bp-8h]@17
  int v37; // [sp+78h] [bp-4h]@17

  v3 = (int)ptr_507BC0;
  memcpy(&local_0C, ptr_507BC0, sizeof(GUI::Window));
  v1 = (int)pPlayers[uActiveCharacter - 1];
  local_0C.uFrameX = 483;
  local_0C.uFrameWidth = 148;
  local_0C.uFrameZ = 334;
  v32 = 0xFFFFFFFF;
  *(_DWORD *)v33 = 0xFFFFFF9B;
  v4 = 52 * *(_DWORD *)(v3 + 28);
  v34 = (((*(__int16 *)((char *)word_591438 + v4) != 18) - 1) & 0x96) + 100;
  v2 = (signed __int64)((double)v34 * *(float *)(v4 + 5837912));
  v0 = v2 * (100 - Player_sub_4911F3((Player *)v1)) / 100;
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
        pAudioPlayer->sub_4AA306(27, 0, 0, -1, 0, 0, 0, 0);
      }
      else
      {
        if ( pParty_global->uNumGold < (unsigned int)v0 )
        {
          sub_44C175((char *)pGlobalTXT_LocalizationStrings[155], 2);
          v27 = 4;
        }
        else
        {
          sub_492BB6(v0);
          *(_WORD *)v6 = 1;
          v27 = 2;
        }
        sub_4B1E92(ptr_507BC0->dword_00001C, v27);
      }
    }
    else
    {
      v5 = 0;
    }
    result = 0;//dword_50CBD0[0];
   /* if ( dword_50CBD0[0] < 40 )
    {
      dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
      dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
      result = 3 * dword_50CBD0[0] + 3;
      dword_50CBD0[result] = v5;
      ++dword_50CBD0[0];
    }  */
	dword_50CBD0.PutMessageToQueue(113,1,0);
    return;// result;
  }
  if ( !(unsigned __int16)sub_449B57((unsigned char *)v1 + 338, word_4F0754[2 * (int)ptr_507BC0->dword_00001C]) )
  {
    v24 = (char *)dword_721BC4;
    v25 = v33[0];
    v26 = GUIFont_CalculateTextHeight(pFontArrus, dword_721BC4, &local_0C, 0, 0);
    GUIWindow_DrawText(&local_0C, pFontArrus, 0, (212 - v26) / 2 + 101, v25, v24, 3);
    result = (int)pDialogueWindow;
    pDialogueWindow->dword_000028 = 0;
    return;// result;
  }
  result = sub_4B1784();
  if ( !result )
    return;// result;
  v8 = (int)pDialogueWindow;
  v35 = 0;
  v36 = 0;
  v31 = (int)pDialogueWindow;
  v9 = pDialogueWindow->dword_000038;
  v10 = v9 + pDialogueWindow->dword_000028;
  v37 = pDialogueWindow->dword_000038;
  if ( v9 >= v10 )
    goto LABEL_40;
  do
  {
    v11 = *(_DWORD *)(GUIWindow_GetChild((GUI::Window *)v8, v37) + 36) - 36;
    if ( *(&byte_4ED970[37 * *(_BYTE *)(v1 + 185) / 3] + v11) )
    {
      if ( !*(_WORD *)(v1 + 2 * v11 + 264) )
      {
        v12 = GUIFont_CalculateTextHeight(pFontArrus, aSkillNames[v11], &local_0C, 0, 0);
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
    wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[544], v1 + 168, aClassNames[*(_BYTE *)(v1 + 185)]);

    strcat((char *)TmpBuf, "\n \n");
    strcat((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[528]);
    v22 = v33[0];
    v23 = GUIFont_CalculateTextHeight(pFontArrus, TmpBuf, &local_0C, 0, 0);
    GUIWindow_DrawText(&local_0C, pFontArrus, 0, (174 - v23) / 2 + 138, v22, (char *)TmpBuf, 3);
        return;
  }
  wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[401], v34);
  GUIWindow_DrawText(&local_0C, pFontArrus, 0, 146, 0, (char *)TmpBuf, 3);
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
      v15 = (int)GUIWindow_GetChild((GUI::Window *)v8, v37);
      v14 = *(_DWORD *)(v15 + 36) - 36;
      if ( *(&byte_4ED970[37 * *(_BYTE *)(v1 + 185) / 3] + v14) )
      {
        v16 = 0;
        if ( !*(_WORD *)(v1 + 2 * v14 + 264) )
        {
          v19 = (char *)aSkillNames[v14];
          *(_DWORD *)(v15 + 4) = v34 + v36;
          v20 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v19, &local_0C, 0, 0);
          v18 = *(_DWORD *)(v15 + 4);
          *(_DWORD *)(v15 + 12) = v20;
          v21 = v18 + v20 - 1;
          *(_DWORD *)(v15 + 20) = v21;
          v36 = v21;
          v17 = v33[0];
          if (pDialogueWindow->dword_00002C != v35 )
            v17 = v32;
          GUIWindow_DrawText(&local_0C, pFontArrus, 0, v18, v17, v19, 3);
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
        || (unsigned __int16)sub_449B57((unsigned char *)pParty_global->unk_000764 + 1, *(_WORD *)((char *)&unk_4F09CC + v3)) )
        break;
    }
    ++v1;
    if ( v1 >= 4 )
      return 0;
  }
  return 1;
}



//----- (004B6FF9) --------------------------------------------------------
signed int __thiscall Player_sub_4B6FF9(Player *_this)
{
  signed int v1; // eax@1
  int v2; // esi@1
  char v3; // zf@4

  v2 = (int)_this;
  v1 = ptr_507BC0->dword_00001C;
  if ( v1 == 78 || v1 > 80 && v1 <= 82 )
  {
    if ( Player_GetConditionIdx(_this) == 18 )
      goto LABEL_6;
    v3 = Player_GetConditionIdx(_this) == 17;
  }
  else
  {
    v3 = Player_GetConditionIdx(_this) == 18;
  }
  if ( !v3 )
    return 1;
LABEL_6:
  if ( *(_DWORD *)(v2 + 6460) < Player_GetMaxHealth(_this) || *(_DWORD *)(v2 + 6464) < Player_GetMaxMana(_this) )
    return 1;
  return 0;
}

//----- (004B705E) --------------------------------------------------------
void sub_4B705E()
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

  GUI::Window local_13C;
  //int v57; // [sp+13Ch] [bp-88h]@1
  //int v58; // [sp+144h] [bp-80h]@1
  //int v59; // [sp+14Ch] [bp-78h]@1

  __int64 v60; // [sp+190h] [bp-34h]@1
  __int64 v61; // [sp+198h] [bp-2Ch]@1
  __int64 v62; // [sp+1A0h] [bp-24h]@1
  int v63; // [sp+1ACh] [bp-18h]@6
  int v64; // [sp+1B0h] [bp-14h]@8
  unsigned __int8 v65; // [sp+1B7h] [bp-Dh]@64
  int v66; // [sp+1B8h] [bp-Ch]@6
  int v67; // [sp+1BCh] [bp-8h]@6
  const char *v68; // [sp+1C0h] [bp-4h]@6

  v2 = (int)ptr_507BC0;
  memcpy(&local_13C, ptr_507BC0, sizeof(GUI::Window));
  local_13C.uFrameX = 483;
  local_13C.uFrameWidth = 148;
  local_13C.uFrameZ = 334;
  HIDWORD(v60) = 0xFFFFFF;
  HIDWORD(v61) = 0xFFFF9B;
  v1 = (int)pPlayers[uActiveCharacter - 1];
  v0 = Player_sub_4B807C(pPlayers[uActiveCharacter - 1], *((float *)&unk_591458 + 13 * *(_DWORD *)(v2 + 28)));
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
            v4 = (int)pDialogueWindow;
            v63 = (int)pDialogueWindow;
            v5 = ptr_507BC0->dword_00001C;
            v68 = 0;
            v67 = (signed __int64)(*((float *)&unk_59145C + 13 * v5) * 500.0);
            v6 = Player_sub_4911F3((Player *)v1);
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
              v9 = *(_DWORD *)(GUIWindow_GetChild((GUI::Window *)v4, v64) + 36) - 36;
              if ( *(&byte_4ED970[37 * *(_BYTE *)(v1 + 185)] + v9) )
              {
                if ( !*(_WORD *)(v1 + 2 * v9 + 264) )
                {
                  v10 = GUIFont_CalculateTextHeight(pFontArrus, aSkillNames[v9], &local_13C, 0, 0);
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
              wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[401], v66);
              GUIWindow_DrawText(&local_13C, pFontArrus, 0, 146, 0, (char *)TmpBuf, 3);
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
                  v16 = (int)GUIWindow_GetChild((GUI::Window *)v12, v64);
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
                    v19 = (char *)aSkillNames[v14];
                    *(_DWORD *)(v15 + 4) = v66 + v67;
                    HIDWORD(v62) = (int)v19;
                    v20 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v19, &local_13C, 0, 0);
                    v18 = *(_DWORD *)(v15 + 4);
                    *(_DWORD *)(v15 + 12) = v20;
                    v21 = v18 + v20 - 1;
                    *(_DWORD *)(v15 + 20) = v21;
                    v67 = v21;
                    v17 = WORD2(v61);
                    if (pDialogueWindow->dword_00002C != (int)v68 )
                      v17 = WORD2(v60);
                    GUIWindow_DrawText(&local_13C, pFontArrus, 0, v18, v17, (char *)HIDWORD(v62), 3);
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
              wsprintfA((char *)TmpBuf,
                (char *)pGlobalTXT_LocalizationStrings[544],
                v1 + 168,
                aClassNames[*(_BYTE *)(v1 + 185)]);
              strcat((char *)TmpBuf, "\n \n");
              strcat((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[528]);
              v22 = WORD2(v61);
              v23 = GUIFont_CalculateTextHeight(pFontArrus, TmpBuf, &local_13C, 0, 0);
              GUIWindow_DrawText(&local_13C, pFontArrus, 0, (174 - v23) / 2 + 138, v22, (char *)TmpBuf, 3);
            }
          }
        }
        return;
      }
      v25 = *((float *)&unk_591458 + 13 * ptr_507BC0->dword_00001C);
      v24 = 0;
      if ( pParty_global->uNumGold >= (unsigned int)(signed __int64)v25 )
      {
        sub_492BB6((signed __int64)v25);
        v26 = (int)&pOutdoor->cDDMHeader;
        if ( uCurrentlyLoadedLevelType != 2 )
          v26 = (int)&pIndoor->cDLVHeader;
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
            sub_42777D_CastSpell(12, uActiveCharacter, v30, 48, 0);
            v29 = uActiveCharacter;
          }
          if ( *(_DWORD *)(v26 + 8) <= -10 )
          {
            v31 = pParty_global->uDaysPlayed % 7u + 1;
            LOBYTE(v31) = v31 | 0x80;
            sub_42777D_CastSpell(50, v29 - 1, v31, 48, 0);
            v29 = uActiveCharacter;
            v26 = (int)v68;
          }
          if ( *(_DWORD *)(v26 + 8) <= -15 )
          {
            v32 = pParty_global->uDaysPlayed % 7u + 1;
            LOBYTE(v32) = v32 | 0x80;
            sub_42777D_CastSpell(75, v29 - 1, v32, 48, 0);
            v29 = uActiveCharacter;
            v26 = (int)v68;
          }
          if ( *(_DWORD *)(v26 + 8) <= -20 )
          {
            v33 = pParty_global->uDaysPlayed % 7u + 1;
            LOBYTE(v33) = v33 | 0x80;
            sub_42777D_CastSpell(86, v29 - 1, v33, 48, 0);
            v29 = uActiveCharacter;
            v26 = (int)v68;
          }
          if ( *(_DWORD *)(v26 + 8) <= -25 )
          {
            v34 = pParty_global->uDaysPlayed % 7u + 1;
            LOBYTE(v34) = v34 | 0x80;
            sub_42777D_CastSpell(85, v29 - 1, v34, 48, 0);
            v29 = uActiveCharacter;
          }
        }
        ++byte_F8B1EF[v29];
        Player_PlaySound((Player *)v1, 83, 0);
        sub_44C175((char *)pGlobalTXT_LocalizationStrings[527], 2);
        goto LABEL_46;
      }
      goto LABEL_55;
    }
    result = Player_sub_4B6FF9((Player *)v1);
    if ( !result )
      return;// result;
    v24 = 0;
    if ( pParty_global->uNumGold < (unsigned int)v0 )
    {
LABEL_55:
      sub_44C175((char *)pGlobalTXT_LocalizationStrings[155], 2);
      sub_4B1E92(ptr_507BC0->dword_00001C, 2);
      goto LABEL_46;
    }
    sub_492BB6(v0);
    v36 = *(_DWORD *)(v1 + 136);
    v61 = *(_QWORD *)(v1 + 112);
    v60 = *(_QWORD *)(v1 + 120);
    v62 = *(_QWORD *)(v1 + 128);
    v63 = *(_DWORD *)(v1 + 140);
    memset((void *)v1, 0, 0xA0u);
    *(_DWORD *)(v1 + 6460) = Player_GetMaxHealth((Player *)v1);
    *(_DWORD *)(v1 + 6464) = Player_GetMaxMana((Player *)v1);
    v35 = ptr_507BC0->dword_00001C;
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
        Player_sub_492D65((Player *)v1, 17, 1);
        *(_DWORD *)(v1 + 6432) = (Player_GetSexByVoice((Player *)v1) != 0) + 23;
        v40 = (Player_GetSexByVoice((Player *)v1) != 0) + 23;
        *(_BYTE *)(v1 + 186) = v40;
        sub_491DE7(uActiveCharacter, v40);
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
        sub_491DE7(uActiveCharacter, v37);
      }
    }
LABEL_63:
    pAudioPlayer->sub_4AA306(202, -1, 0, -1, 0, 0, 0, 0);
    Player_PlaySound((Player *)v1, 82, 0);
    sub_4418B1(20, uActiveCharacter + 99, 0, 65536);
LABEL_46:
    result = 0;//dword_50CBD0[0];
   /* if ( dword_50CBD0[0] < 40 )
    {
      dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
      dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
      result = 3 * dword_50CBD0[0] + 3;
      dword_50CBD0[result] = v24;
      ++dword_50CBD0[0];
    } */
	dword_50CBD0.PutMessageToQueue(113,1,0);
    return;// result;
  }
  v65 = 1;
  v41 = (int)GUIWindow_GetChild(pDialogueWindow, pDialogueWindow->dword_000038);
  strcpy(Dest, "");
  *(_DWORD *)(v41 + 12) = 0;
  *(_DWORD *)(v41 + 4) = 0;
  if ( Player_sub_4B6FF9((Player *)v1) )
  {
    wsprintfA(Dest, "%s %d %s", pGlobalTXT_LocalizationStrings[104], HIDWORD(v62), pGlobalTXT_LocalizationStrings[97]);
    v65 = 0;
  }
  strcpy(&v55, (char *)pGlobalTXT_LocalizationStrings[68]);
  strcpy(&v56, (char *)pGlobalTXT_LocalizationStrings[160]);
  v44 = v65;
  v42 = (int)pDialogueWindow;
  v43 = v65;
  v68 = 0;
  if ( (signed int)v65 < pDialogueWindow->dword_000028 )
  {
    v63 = (int)&Dest[100 * v65];
    do
    {
      v45 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v63, &local_13C, 0, 0);
      v68 += v45;
      v42 = (int)pDialogueWindow;
      v63 += 100;
      ++v43;
    }
    while ( v43 < pDialogueWindow->dword_000028 );
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
      v50 = (int)GUIWindow_GetChild((GUI::Window *)v42, v67);
      v51 = v68;
      v52 = v50;
      *(_DWORD *)(v50 + 4) = v66 + v47;
      v53 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v51, &local_13C, 0, 0);
      v49 = *(_DWORD *)(v52 + 4);
      *(_DWORD *)(v52 + 12) = v53;
      v47 = v49 + v53 - 1;
      *(_DWORD *)(v52 + 20) = v47;
      v48 = WORD2(v61);
      if (pDialogueWindow->dword_00002C != v63 )
        v48 = WORD2(v60);
      GUIWindow_DrawText(&local_13C, pFontArrus, 0, v49, v48, v68, 3);
      v42 = (int)pDialogueWindow;
      v68 += 100;
      ++v63;
      ++v67;
      result = pDialogueWindow->dword_000028 + pDialogueWindow->dword_000038;
    }
    while ( v67 < result );
  }
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

  GUI::Window local_0C;
  //char v27; // [sp+Ch] [bp-110h]@21

  GUI::Window local_60;
  //char v28; // [sp+60h] [bp-BCh]@21
  //int v29; // [sp+68h] [bp-B4h]@21
  //int v30; // [sp+70h] [bp-ACh]@21

  GUI::Window local_B4;
  //int v31; // [sp+B4h] [bp-68h]@1
  //int v32; // [sp+BCh] [bp-60h]@1
  //int v33; // [sp+C4h] [bp-58h]@1

  __int16 v34[2]; // [sp+108h] [bp-14h]@1
  int v35; // [sp+10Ch] [bp-10h]@28
  __int16 v36[2]; // [sp+110h] [bp-Ch]@1
  int v37; // [sp+114h] [bp-8h]@29
  int v38; // [sp+118h] [bp-4h]@21

  memcpy(&local_B4, ptr_507BC0, sizeof(GUI::Window));
  local_B4.uFrameX = 483;
  local_B4.uFrameWidth = 148;
  local_B4.uFrameZ = 334;

  *(_DWORD *)v34 = 0xFFFFFFFF;
  *(_DWORD *)v36 = 0xFFFFFF9B;
  wsprintfA((char *)TmpBuf, "%s: %d", pGlobalTXT_LocalizationStrings[162], dword_AE31E0);
  GUIWindow_DrawText(&local_B4, pFontArrus, 0, 260, v36[0], (char *)TmpBuf, 3);
  if ( dword_F8B19C == 1 )
  {
    v12 = 1;
    v38 = 0;
    dword_F8B1B8[0] = pGlobalTXT_LocalizationStrings[161];
    if ( dword_AE31E0 )
    {
      dword_F8B1B8[1] = pGlobalTXT_LocalizationStrings[160];
      v12 = 2;
    }
    for ( i = 0; i < v12; ++i )
    {
      v14 = GUIFont_CalculateTextHeight(pFontArrus, dword_F8B1B8[i], &local_B4, 0, 0);
      v38 += v14;
    }
    v35 = (100 - v38) / v12;
    v15 = (int)pDialogueWindow;
    v17 = 80 - v12 * (100 - v38) / v12 - v38;
    v18 = v17 - HIDWORD(v17);
    v0 = pDialogueWindow->dword_000038;
    HIDWORD(v17) = v0 + pDialogueWindow->dword_000028;
    v16 = (v18 >> 1) - v35 / 2 + 158;
    v19 = -pDialogueWindow->dword_000028 < 0;
    v38 = pDialogueWindow->dword_000038;

    compile_error();//if ( v19 ^ __SETO__(v0, HIDWORD(v17)) )
    if (1)
    {
      v37 = 2;
      v20 = (const char **)dword_F8B1B8;
      do
      {
        v23 = (int)GUIWindow_GetChild((GUI::Window *)v15, v38);
        v24 = v23;
        *(_DWORD *)(v23 + 4) = v35 + v16;
        v25 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v20, &local_B4, 0, 0);
        v22 = *(_DWORD *)(v24 + 4);
        *(_DWORD *)(v24 + 12) = v25;
        v16 = v22 + v25 - 1;
        *(_DWORD *)(v24 + 20) = v16;
        v21 = v36[0];
        if (pDialogueWindow->dword_00002C != v37 )
          v21 = v34[0];
        GUIWindow_DrawText(&local_B4, pFontArrus, 0, v22, v21, *v20, 3);
        v15 = (int)pDialogueWindow;
        ++v37;
        ++v20;
        ++v38;
        v0 = pDialogueWindow->dword_000028 + pDialogueWindow->dword_000038;
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
        return;
      v0 = (int)ptr_507BC0;
      if (ptr_507BC0->dword_000040 == 1)
      {
        wsprintfA((char *)TmpBuf, "%s\n%s", pGlobalTXT_LocalizationStrings[163], pGlobalTXT_LocalizationStrings[112]);
        GUIWindow_DrawText(&local_B4, pFontArrus, 0, 146, v36[0], (char *)TmpBuf, 3);
        GUIWindow_DrawText(&local_B4, pFontArrus, 0, 186, v34[0], (char *)pUserInput->pPressedKeysBuffer, 3);
        v4 = (int)pFontArrus;
        v5 = GUIFont_GetLineWidth(pFontArrus, pUserInput->pPressedKeysBuffer);
        GUIWindow_sub_459C2B(&local_B4, v5 / 2 + 80, 185, v4);
        return;
      }
      if (ptr_507BC0->dword_000040 == 2)
      {
        v1 = atoi((char *)pUserInput->pPressedKeysBuffer);
        v2 = v1;
        if ( v1 <= 0 )
        {
LABEL_8:
       /*   LOBYTE(v0) = LOBYTE(dword_50CBD0[0]);
          if ( dword_50CBD0[0] < 40 )
          {
            dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
            dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
            v0 = 3 * dword_50CBD0[0] + 3;
            dword_50CBD0[v0] = 0;
            ++dword_50CBD0[0];
          }	  */
		dword_50CBD0.PutMessageToQueue(113,1,0);
          return;
        }
        if ( v1 > (unsigned int)pParty_global->uNumGold )
        {
         sub_4B1E92(ptr_507BC0->dword_00001C, 2);
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
          Player_PlaySound(pPlayers[uActiveCharacter - 1], 81, 0);
        v0 = (int)ptr_507BC0;
      }
      else
      {
       if (ptr_507BC0->dword_000040 != 3)
          return;
      }
      *(_DWORD *)(v0 + 64) = 0;
      goto LABEL_8;
    }
    v7 = (int *)&pMonsterStats->pMonsterInfos[word_F8B1A0];
    v8 = 0xFFFFFFFF;
    v9 = *v7;
    v10 = 0xFFFFFF9B;
    wsprintfA((char *)TmpBuf, "\x0C%05d%s\x0C%05d", v10, v9, v8);
    wsprintfA((char *)pStringBuffer, (const char *)dword_F8B1A4, TmpBuf, 100 * *((_BYTE *)v7 + 8));
    dword_F8B1E8 = pStringBuffer;

    memcpy(&local_0C, pDialogueWindow, sizeof(GUI::Window));
    local_60.uFrameWidth = 458;
    local_60.uFrameZ = 457;
    v38 = (int)pFontArrus;
    v6 = GUIFont_CalculateTextHeight(pFontArrus, pStringBuffer, &local_60, 13, 0) + 7;
    if ( 352 - v6 < 8 )
    {
      v38 = (int)pFontCreate;
      v6 = GUIFont_CalculateTextHeight(pFontCreate, dword_F8B1E8, &local_60, 13, 0) + 7;
    }
    Render_sub_4A6A68(
      pD3DRenderer,
      8,
      352 - v6,
      uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 : 0,
      *(_WORD *)(uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 + 0x1A : 26) - v6);
    Render_DrawIndexedTexture(pD3DRenderer, 8, 347 - v6, pcTexture_EndcapTexture);

    unsigned char pOutString[2048];
    v11 = (char *)FitTextInAWindow(dword_F8B1E8, pOutString, (Font *)v38, &local_60, 13, 0);
    FontDrawText(&local_0C, (Font *)v38, 13, 354 - v6, v11, 0, 0, 0);
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

  GUI::Window local_0C;
  //int v13; // [sp+Ch] [bp-5Ch]@1
  //int v14; // [sp+14h] [bp-54h]@1
  //int v15; // [sp+1Ch] [bp-4Ch]@1

  __int16 v16[2]; // [sp+60h] [bp-8h]@1
  __int16 v17[2]; // [sp+64h] [bp-4h]@1

  memcpy(&local_0C, ptr_507BC0, sizeof(GUI::Window));
  local_0C.uFrameX = 483;
  local_0C.uFrameWidth = 148;
  local_0C.uFrameZ = 334;
  *(_DWORD *)v16 = 0xFFFFFFFF;
  *(_DWORD *)v17 = 0xFFFFFF9B;
  wsprintfA((char *)TmpBuf, "%s: %d", pGlobalTXT_LocalizationStrings[25], pParty_global->uNumGoldInBank);
  GUIWindow_DrawText(&local_0C, pFontArrus, 0, 220, v17[0], (char *)TmpBuf, 3);
  if ( dword_F8B19C != 1 )
  {
    if ( dword_F8B19C == 7 )
    {
      v0 = (int)ptr_507BC0;
      if (ptr_507BC0->dword_000040 != 1)
      {
       v1 = ptr_507BC0->dword_000040 - 2;
       if (ptr_507BC0->dword_000040 == 2)
        {
          v6 = atoi((char *)pUserInput->pPressedKeysBuffer);
          v7 = v6;
          if ( !v6 )
          {
LABEL_17:
         /*   LOBYTE(v0) = LOBYTE(dword_50CBD0[0]);
            if ( dword_50CBD0[0] < 40 )
            {
              dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
              dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
              v0 = 3 * dword_50CBD0[0] + 3;
              dword_50CBD0[v0] = 0;
              ++dword_50CBD0[0];
            }	*/
		  dword_50CBD0.PutMessageToQueue(113,1,0);
            return;
          }
          if ( v6 > (unsigned int)pParty_global->uNumGold )
          {
           sub_4B1E92(ptr_507BC0->dword_00001C, 2);
            v7 = pParty_global->uNumGold;
          }
          if ( v7 )
          {
            sub_492BB6(v7);
            pParty_global->uNumGoldInBank += v7;
            if ( uActiveCharacter )
              Player_PlaySound(pPlayers[uActiveCharacter - 1], 81, 0);
          }
          v0 = (int)ptr_507BC0;
LABEL_16:
          *(_DWORD *)(v0 + 64) = 0;
          goto LABEL_17;
        }
LABEL_15:
        if ( v1 != 1 )
          return;
        goto LABEL_16;
      }
      v12 = (int)pGlobalTXT_LocalizationStrings[112];
      v11 = (char *)pGlobalTXT_LocalizationStrings[60];
    }
    else
    {
      v0 = dword_F8B19C - 8;
      if ( dword_F8B19C != 8 )
        return;
      v0 = (int)ptr_507BC0;
      if (ptr_507BC0->dword_000040 != 1)
      {
        v1 = ptr_507BC0->dword_000040 - 2;
        if (ptr_507BC0->dword_000040 == 2)
        {
         ptr_507BC0->dword_000040 = 0;
          v2 = atoi((char *)pUserInput->pPressedKeysBuffer);
          v3 = v2;
          if ( v2 )
          {
            if ((unsigned int)v2 > pParty_global->uNumGoldInBank)
            {
              sub_4B1E92(ptr_507BC0->dword_00001C, 2);
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
      v12 = (int)pGlobalTXT_LocalizationStrings[112];
      v11 = (char *)pGlobalTXT_LocalizationStrings[224];
    }
    wsprintfA((char *)TmpBuf, "%s\n%s", v11, v12);
    GUIWindow_DrawText(&local_0C, pFontArrus, 0, 146, v17[0], (char *)TmpBuf, 3);
    GUIWindow_DrawText(&local_0C, pFontArrus, 0, 186, v16[0], (char *)pUserInput->pPressedKeysBuffer, 3);
    v4 = (int)pFontArrus;
    v5 = GUIFont_GetLineWidth(pFontArrus, pUserInput->pPressedKeysBuffer);
    GUIWindow_sub_459C2B(&local_0C, v5 / 2 + 80, 185, v4);
    return;
  }
  v8 = v17[0];
  if (pDialogueWindow->dword_00002C != 2 )
    v8 = v16[0];
  GUIWindow_DrawText(&local_0C, pFontArrus, 0, 146, v8, (char *)pGlobalTXT_LocalizationStrings[60], 3);
  v9 = v17[0];
  if (pDialogueWindow->dword_00002C != 3 )
    v9 = v16[0];
  GUIWindow_DrawText(&local_0C, pFontArrus, 0, 176, v9, (char *)pGlobalTXT_LocalizationStrings[224], 3);
  return;
}

//----- (004B8040) --------------------------------------------------------
unsigned int __thiscall sub_4B8040(void *_this, int a2)
{
  return (unsigned int)((signed __int64)((double)*((signed __int64 *)_this + a2) * 0.234375) / 60 / 60) / 0x18 % 7 + 1;
}

//----- (004B807C) --------------------------------------------------------
int __thiscall Player_sub_4B807C(Player *_this, float a2)
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

  v3 = _this;
  v2 = Player_GetConditionIdx(_this);
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
signed int __thiscall Player_sub_4B8102(Player *_this, signed int a2, float a3)
{
  signed int v3; // esi@1
  signed int result; // eax@3

  v3 = (signed __int64)((double)a2 / (a3 + 2.0)) + a2 * Player_sub_4911F3(_this) / 100;
  if ( v3 > a2 )
    v3 = a2;
  result = 1;
  if ( v3 >= 1 )
    result = v3;
  return result;
}

//----- (004B8142) --------------------------------------------------------
int __thiscall Player_sub_4B8142(Player *_this, signed int a2, float a3)
{
  int result; // eax@1

  result = (signed int)((100 - Player_sub_4911F3(_this)) * (signed __int64)((double)a2 * a3)) / 100;
  if ( result < a2 )
    result = a2;
  if ( result < 1 )
    result = 1;
  return result;
}

//----- (004B8179) --------------------------------------------------------
signed int __thiscall Player_sub_4B8179(Player *_this, float a2)
{
  int v2; // ecx@1
  signed int v3; // esi@1
  signed int result; // eax@3

  v3 = (signed __int64)(a2 * 50.0);
  v2 = v3 * (100 - Player_sub_4911F3(_this)) / 100;
  if ( v2 < v3 / 3 )
    v2 = v3 / 3;
  result = 1;
  if ( v2 >= 1 )
    result = v2;
  return result;
}

//----- (004B81C3) --------------------------------------------------------
signed int __thiscall Player_sub_4B81C3(Player *_this, signed int a2, float a3)
{
  int v3; // ecx@1
  signed int v4; // esi@1
  signed int result; // eax@3

  v4 = (signed __int64)((double)a2 / (6.0 - a3));
  v3 = v4 * (100 - Player_sub_4911F3(_this)) / 100;
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
  char Dest[100]; // [sp+Ch] [bp-268h]@55
  char v76; // [sp+70h] [bp-204h]@59
  char v77; // [sp+D4h] [bp-1A0h]@57
  char v78; // [sp+138h] [bp-13Ch]@59

  GUI::Window local_19C;
  //char v79; // [sp+19Ch] [bp-D8h]@99
  //int v80; // [sp+1A4h] [bp-D0h]@99
  //int v81; // [sp+1ACh] [bp-C8h]@99

  GUI::Window local_1F0;
  //int v82; // [sp+1F0h] [bp-84h]@1
  //int v83; // [sp+1F8h] [bp-7Ch]@1
  //int v84; // [sp+200h] [bp-74h]@1

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

  v2 = (int)ptr_507BC0;
  memcpy(&local_1F0, ptr_507BC0, sizeof(GUI::Window));
  v90 = (int)pPlayers[uActiveCharacter - 1];
  v3 = (void *)v90;
  local_1F0.uFrameX = 483;
  local_1F0.uFrameWidth = 148;
  local_1F0.uFrameZ = 334;
  v86 = 0xFFFFFFFF;
  *(_DWORD *)v89 = 0xFFFFFF9B;
  v4 = *((float *)&unk_591458 + 13 * *(_DWORD *)(v2 + 28));
  *(float *)&v88 = *((float *)&unk_591458 + 13 * *(_DWORD *)(v2 + 28));
  *(float *)&v94 = v4 * v4;
  v1 = (signed __int64)(*(float *)&v94 * 0.1000000014901161);
  v0 = v1 * (100 - Player_sub_4911F3((Player *)v3)) / 100;
  if ( v0 < v1 / 3 )
    v0 = v1 / 3;
  v5 = 1;
  v96 = v0;
  if ( v0 <= 0 )
    v96 = 1;
  v7 = (signed __int64)(*(float *)&v94 * *(float *)&v88 * 0.009999999776482582);
  v6 = v7 * (100 - Player_sub_4911F3((Player *)v90)) / 100;
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
        dword_F8B1B8[1] = pGlobalTXT_LocalizationStrings[622];
        if ( sub_493244(651) )
        {
          dword_F8B1B8[2] = pGlobalTXT_LocalizationStrings[621];
          v48 = 3;
        }
        for ( i = 0; i < v48; ++i )
        {
          v50 = GUIFont_CalculateTextHeight(pFontArrus, dword_F8B1B8[i], &local_1F0, 0, 0);
          v96 += v50;
        }
        v91 = (174 - v96) / v48;
        v51 = (int)pDialogueWindow;
        v53 = 174 - v48 * (174 - v96) / v48 - v96;
        v54 = v53 - HIDWORD(v53);
        LODWORD(v53) = pDialogueWindow->dword_000038;
        HIDWORD(v53) = v53 + pDialogueWindow->dword_000028;
        v52 = (v54 >> 1) - v91 / 2 + 138;
        v55 = -pDialogueWindow->dword_000028 < 0;
        v94 = pDialogueWindow->dword_000038;

        compile_error();//if ( v55 ^ __SETO__(v53, HIDWORD(v53)) )
        if (1)
        {
          v90 = 2;
          v96 = (int)dword_F8B1B8;
          do
          {
            v58 = (int)GUIWindow_GetChild((GUI::Window *)v51, v94);
            v59 = (const char **)v96;
            *(_DWORD *)(v58 + 4) = v91 + v52;
            v60 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v59, &local_1F0, 0, 0);
            v57 = *(_DWORD *)(v58 + 4);
            v61 = v90;
            *(_DWORD *)(v58 + 12) = v60;
            v52 = v60 + v57 - 1;
            *(_DWORD *)(v58 + 20) = v52;
            v56 = v89[0];
            if (pDialogueWindow->dword_00002C != v61 )
              v56 = v86;
            GUIWindow_DrawText(&local_1F0, pFontArrus, 0, v57, v56, *(const char **)v96, 3);
            v51 = (int)pDialogueWindow;
            ++v90;
            v96 += 4;
            ++v94;
          }
          while ( v94 < pDialogueWindow->dword_000028 + pDialogueWindow->dword_000038 );
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
          v27 = ptr_507BC0->dword_00001C;
          sub_4B1E92(ptr_507BC0->dword_00001C, 2);
          dword_F8B19C = 0;
          while ( sub_4BD8B5() )
            ;
          sub_4B1D27();
          pVideoPlayer->UnloadAll();
          GUIWindowDelete(ptr_507BC0);
          ptr_507BC0 = 0;
		  dword_50CBD0.CutQueueTail();
      /*    if ( dword_50CBD0.msg_count )
			   if  (dword_50CBD0.prm[0].msg_param3)
                          dword_50CBD0.msg_count = 1;
          dword_50CBD0[0 + 1] = 409;
          dword_50CBD0[0 + 2] = v27;
          dword_50CBD0[0 + 3] = 1;
LABEL_51:
          ++dword_50CBD0[0];  */
		  dword_50CBD0.PutMessageToQueue(409,v27,1);
          return;
        }
      }
      else
      {
        if ( dword_F8B19C != 16 )
        {
          if ( dword_F8B19C == 96 && sub_4B1784() )
          {
            v8 = (int)pDialogueWindow;
            v94 = 0;
            v9 = (signed __int64)(*((float *)&unk_59145C + 13 * ptr_507BC0->dword_00001C) * 500.0);
            v96 = v9 * (100 - Player_sub_4911F3((Player *)v90)) / 100;
            if ( v96 < v9 / 3 )
              v96 = v9 / 3;
            v10 = *(_DWORD *)(v8 + 56);
            v11 = v10 + *(_DWORD *)(v8 + 40);
            v91 = 0;
            if ( v10 < v11 )
            {
              do
              {
                v12 = *(_DWORD *)(GUIWindow_GetChild((GUI::Window *)v8, v10) + 36) - 36;
                if ( *(&byte_4ED970[37 * *(_BYTE *)(v90 + 185)] + v12) )
                {
                  if ( !*(_WORD *)(v90 + 2 * v12 + 264) )
                  {
                    v13 = GUIFont_CalculateTextHeight(pFontArrus, aSkillNames[v12], &local_1F0, 0, 0);
                    v94 += v13;
                    ++v91;
                  }
                }
                ++v10;
              }
              while ( v10 < *(_DWORD *)(v8 + 56) + *(_DWORD *)(v8 + 40) );
              if ( v91 )
              {
                wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[401], v96);
                GUIWindow_DrawText(&local_1F0, pFontArrus, 0, 146, 0, (char *)TmpBuf, 3);
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
                    v17 = (int)GUIWindow_GetChild((GUI::Window *)v8, v94);
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
                      v20 = (char *)aSkillNames[v15];
                      *(_DWORD *)(v16 + 4) = v96 + v88;
                      Str[1] = v20;
                      v21 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v20, &local_1F0, 0, 0);
                      v19 = *(_DWORD *)(v16 + 4);
                      v22 = v91;
                      *(_DWORD *)(v16 + 12) = v21;
                      v23 = v21 + v19 - 1;
                      *(_DWORD *)(v16 + 20) = v23;
                      v88 = v23;
                      v18 = v89[0];
                      if (pDialogueWindow->dword_00002C != v22 )
                        v18 = v86;
                      GUIWindow_DrawText(&local_1F0, pFontArrus, 0, v19, v18, Str[1], 3);
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
            v26 = (char *)TmpBuf;
            wsprintfA((char *)TmpBuf,
              (char *)pGlobalTXT_LocalizationStrings[544],
              v90 + 168,
              aClassNames[*(_BYTE *)(v90 + 185)]);
            strcat((char *)TmpBuf, "\n \n");
            strcat((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[528]);
            goto LABEL_97;
          }
          return;
        }
        *(_QWORD *)Str = (unsigned int)pParty_global->uNumFood;
        if ( (double)(unsigned int)pParty_global->uNumFood >= *((float *)&unk_591458 + 13 * ptr_507BC0->dword_00001C) )
        {
          sub_44C175((char *)pGlobalTXT_LocalizationStrings[140], 2);
          if ( uActiveCharacter )
            Player_PlaySound(pPlayers[uActiveCharacter - 1], 67, 0);
          goto LABEL_43;
        }
        if ( pParty_global->uNumGold >= (unsigned int)v6 )
        {
          sub_492BB6(v6);
          pParty_global->uNumFood = (signed __int64)*((float *)&unk_591458 + 13 * ptr_507BC0->dword_00001C);
          sub_4B1E92(ptr_507BC0->dword_00001C, 3);
          v5 = 1;
LABEL_43:
        /*  if ( dword_50CBD0[0] >= 40 )
            return;
          dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
          dword_50CBD0[3 * dword_50CBD0[0] + 2] = v5;
          dword_50CBD0[3 * dword_50CBD0[0] + 3] = 0;
          goto LABEL_51;*/
		  dword_50CBD0.PutMessageToQueue(113,v5,0);
		  return;
        }
      }
      sub_44C175((char *)pGlobalTXT_LocalizationStrings[155], 2);
      sub_4B1E92(ptr_507BC0->dword_00001C, 4);
      goto LABEL_43;
    }
    if ( !sub_4B1784() )
      return;
    v28 = *(_DWORD *)v89;
    if (pDialogueWindow->dword_00002C != 2 )
      v28 = v86;
    wsprintfA(Dest, "\f%06x", v28);
    wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[178], v96);
    strcat(Dest, (char *)pStringBuffer);
    v95 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)Dest, &local_1F0, 0, 0);
    strcat(Dest, "\n \n");
    v29 = *(_DWORD *)v89;
    if (pDialogueWindow->dword_00002C != 3 )
      v29 = v86;
    wsprintfA(&v77, "\f%06x", v29);
    wsprintfA((char *)pStringBuffer,
      (char *)pGlobalTXT_LocalizationStrings[86],
      (signed __int64)*((float *)&unk_591458 + 13 * ptr_507BC0->dword_00001C),
      v88);
    strcat(&v77, (char *)pStringBuffer);
    v93 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)&v77, &local_1F0, 0, 0);
    strcat(&v77, "\n \n");
    v30 = *(_DWORD *)v89;
    if (pDialogueWindow->dword_00002C != 4 )
      v30 = v86;
    wsprintfA(&v78, "\f%06x", v30);
    strcat(&v78, (char *)pGlobalTXT_LocalizationStrings[160]);
    v87 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)&v78, &local_1F0, 0, 0);
    strcat(&v78, "\n \n");
    v76 = 0;
    v92 = 0;
    v31 = ptr_507BC0->dword_00001C;
    if ( v31 >= 108 )
    {
      if ( v31 <= 120 )
      {
        v32 = *(_DWORD *)v89;
        if (pDialogueWindow->dword_00002C != 5 )
          v32 = v86;
        wsprintfA(&v76, "\f%06x", v32);
        strcat(&v76, (char *)pGlobalTXT_LocalizationStrings[611]);
        v92 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)&v76, &local_1F0, 0, 0);
      }
    }
    v33 = (int)pDialogueWindow;
    Str[1] = (char *)pDialogueWindow;
    v35 = pDialogueWindow->dword_000038;
    v36 = v35 + pDialogueWindow->dword_000028;
    v34 = pFontArrus->uFontHeight - 3;
    v37 = -pDialogueWindow->dword_000028 < 0;
    v96 = pDialogueWindow->dword_000038;
    
    compile_error();//if ( !(v37 ^ __SETO__(v35, v36)) )
    if (1)
    {
LABEL_75:
      wsprintfA((char *)TmpBuf, "%s%s%s%s", &Dest, &v77, &v78, &v76);
      v72 = 3;
      v70 = (char *)TmpBuf;
      v68 = 0;
      v67 = 146;
LABEL_98:
      GUIWindow_DrawText(&local_1F0, pFontArrus, 0, v67, v68, v70, v72);
      return;
    }
    while ( 1 )
    {
      v38 = (int)GUIWindow_GetChild((GUI::Window *)v33, v96);
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
    v66 = (int)pFontArrus;
    v96 = (int)pFontArrus;
    strcpy((char *)(char *)TmpBuf, dword_72217C);
    local_19C.uFrameWidth = 460;
    local_19C.uFrameZ = 452;
    v64 = GUIFont_CalculateTextHeight((Font *)v66, TmpBuf, &local_19C, 12, 0) + 7;
    if ( 352 - v64 < 8 )
    {
      v96 = (int)pFontCreate;
      v64 = GUIFont_CalculateTextHeight(pFontCreate, TmpBuf, &local_19C, 12, 0) + 7;
    }
    Render_sub_4A6A68(
      pD3DRenderer,
      8,
      352 - v64,
      uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 : 0,
      *(_WORD *)(uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 + 0x1A : 26) - v64);
    Render_DrawIndexedTexture(pD3DRenderer, 8, 347 - v64, pcTexture_EndcapTexture);
    v74 = 0;
    v71 = 0;
    v69 = 0;

    unsigned char pOutString[2048];
    v62 = (char *)FitTextInAWindow(TmpBuf, pOutString, (Font *)v96, &local_19C, 12, 0);
    v63 = v96;
    goto LABEL_103;
  }
  if ( dword_F8B19C == 103 )
  {
    compile_error();//strcpy((char *)(char *)TmpBuf, *(const char **)&dword_721E24[8 * *(_DWORD *)(dword_507BC0 + 28)]);
    local_19C.uFrameWidth = 460;
    local_19C.uFrameZ = 452;
    v65 = GUIFont_CalculateTextHeight(pFontArrus, TmpBuf, &local_19C, 12, 0);
    v64 = v65 + 7;
    Render_sub_4A6A68(
      pD3DRenderer,
      8,
      352 - (v65 + 7),
      uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 : 0,
      *(_WORD *)(uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 + 0x1A : 26) - (v65 + 7));
    Render_DrawIndexedTexture(pD3DRenderer, 8, 347 - v64, pcTexture_EndcapTexture);
    v74 = 0;
    v71 = 0;
    v69 = 0;

    unsigned char pOutString[2048];
    v62 = (char *)FitTextInAWindow(TmpBuf, pOutString, pFontArrus, &local_19C, 12, 0);
    v63 = (int)pFontArrus;
LABEL_103:
    FontDrawText(ptr_507BC0, (Font *)v63, 12, 354 - v64, v62, v69, v71, (unsigned int)v74);
    return;
  }
  if ( dword_F8B19C == 104 && struct_505898.byte_505992 != 1 )
  {
    v26 = (char *)TmpBuf;
    if ( struct_505898.dword_505944 )
    {
      if ( struct_505898.dword_505944 == 1 )
        v73 = (char *)pGlobalTXT_LocalizationStrings[640];
      else
        v73 = (char *)pGlobalTXT_LocalizationStrings[641];
    }
    else
    {
      v73 = (char *)pGlobalTXT_LocalizationStrings[639];
    }
    strcpy((char *)TmpBuf, v73);
LABEL_97:
    v72 = 3;
    v70 = v26;
    v68 = v89[0];
    v67 = (174 - GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v26, &local_1F0, 0, 0)) / 2 + 138;
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

  v0 = (int)ptr_507BC0;
  v1 = 0;
  v2 = ptr_507BC0->dword_00001C;
  if ( byte_4F063C[word_591438[26 * ptr_507BC0->dword_00001C]] )
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
          class40_sub_456620_CreateSomeSemirandomItem(pClass40, v5, v3, (ItemGen *)(36 * (v1 + 12 * v2) + 0xAD4734));
          v0 = (int)ptr_507BC0;
          dword_AD4748[9 * (v1 + 12 * ptr_507BC0->dword_00001C)] = 1;
          goto LABEL_14;
        }
        ItemGen_Reset((ItemGen *)(36 * (v1 + 12 * v2) + 0xAD4734));
        v0 = (int)ptr_507BC0;
        dword_AD4734[9 * (v1 + 12 * ptr_507BC0->dword_00001C)] = 220;
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

  v2 = (int)ptr_507BC0;
  v1 = 0;
  v0 = (int)&ptr_507BC0->dword_00001C;
  v3 = ptr_507BC0->dword_00001C;
  if ( byte_4F063C[word_591438[26 * ptr_507BC0->dword_00001C]] )
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
          class40_sub_456620_CreateSomeSemirandomItem(pClass40, v6, v5, (ItemGen *)(36 * (v1 + 12 * v3) + 0xADA0A4));
          v2 = (int)ptr_507BC0;
          v0 = (int)&ptr_507BC0->dword_00001C;
          dword_ADA0B8[9 * (v1 + 12 * ptr_507BC0->dword_00001C)] = 1;
          goto LABEL_14;
        }
        ItemGen_Reset((ItemGen *)(36 * (v1 + 12 * v3) + 0xADA0A4));
        v0 = v2 + 28;
        v2 = (int)ptr_507BC0;
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

  GUI::Window local_7C;
  //int v102; // [sp+7Ch] [bp-7Ch]@1
  //int v103; // [sp+84h] [bp-74h]@1
  //int v104; // [sp+8Ch] [bp-6Ch]@1

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

  v0 = pPlayers[uActiveCharacter - 1];
  v111 = (int)pPlayers[uActiveCharacter - 1];
  memcpy(&local_7C, ptr_507BC0, sizeof(GUI::Window));
  local_7C.uFrameX = 483;
  local_7C.uFrameWidth = 148;
  local_7C.uFrameZ = 334;
  *(_DWORD *)v108 = 0xFFFFFFFF;
  *(_DWORD *)v107 = 0xFFE1CD23;
  if ( dword_F8B19C > 5 )
  {
    if ( dword_F8B19C == 94 )
    {
      sub_41A556();
      CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
      dword_F8B1B8[0] = pGlobalTXT_LocalizationStrings[200];
      dword_F8B1B8[1] = pGlobalTXT_LocalizationStrings[113];
      dword_F8B1B8[2] = pGlobalTXT_LocalizationStrings[179];
      v66 = 0;
      v65 = (const char **)dword_F8B1B8;
      do
      {
        v67 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v65, &local_7C, 0, 0);
        ++v65;
        v66 += v67;
      }
      while ( (signed int)v65 < (signed int)&dword_F8B1B8[3] );
      v68 = (int)pDialogueWindow;
      v113 = (174 - v66) / 3;
      result = pDialogueWindow->dword_000038;
      v70 = result + pDialogueWindow->dword_000028;
      v69 = (3 * (58 - v113) - v66) / 2 - (174 - v66) / 3 / 2 + 138;
      v71 = -pDialogueWindow->dword_000028 < 0;
      v110 = pDialogueWindow->dword_000038;

      compile_error();//if ( v71 ^ __SETO__(result, v70) )
      if (1)
      {
        v111 = 2;
        v112 = (int)dword_F8B1B8;
        do
        {
          v74 = (int)GUIWindow_GetChild((GUI::Window *)v68, v110);
          v75 = (const char **)v112;
          *(_DWORD *)(v74 + 4) = v113 + v69;
          v76 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v75, &local_7C, 0, 0);
          v73 = *(_DWORD *)(v74 + 4);
          v77 = v111;
          *(_DWORD *)(v74 + 12) = v76;
          v69 = v76 + v73 - 1;
          *(_DWORD *)(v74 + 20) = v69;
          v72 = v107[0];
          if (pDialogueWindow->dword_00002C != v77 )
            v72 = v108[0];
          GUIWindow_DrawText(&local_7C, pFontArrus, 0, v73, v72, *(const char **)v112, 3);
          v68 = (int)pDialogueWindow;
          ++v111;
          v112 += 4;
          ++v110;
          result = pDialogueWindow->dword_000028 + pDialogueWindow->dword_000038;
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
          v30 = (int)pDialogueWindow;
          v3 = 0;
          v32 = ptr_507BC0->dword_00001C;
          v110 = 0;
          v31 = (signed __int64)(*((float *)&unk_59145C + 13 * v32) * 500.0);
          v112 = v31 * (100 - Player_sub_4911F3((Player *)v111)) / 100;
          if ( v112 < v31 / 3 )
            v112 = v31 / 3;
          v33 = *(_DWORD *)(v30 + 56);
          v34 = v33 + *(_DWORD *)(v30 + 40);
          v113 = 0;
          if ( v33 >= v34 )
            goto LABEL_105;
          do
          {
            v35 = *(_DWORD *)(GUIWindow_GetChild((GUI::Window *)v30, v33) + 36) - 36;
            if ( *(&byte_4ED970[37 * *(_BYTE *)(v111 + 185)] + v35) )
            {
              if ( !*(_WORD *)(v111 + 2 * v35 + 264) )
              {
                v36 = GUIFont_CalculateTextHeight(pFontArrus, aSkillNames[v35], &local_7C, 0, 0);
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
            wsprintfA((char *)TmpBuf,
              (char *)pGlobalTXT_LocalizationStrings[544],
              v111 + 168,
              aClassNames[*(_BYTE *)(v111 + 185)]);
            strcat((char *)TmpBuf, "\n \n");
            strcat((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[528]);
            v7 = (char *)TmpBuf;
            v87 = 3;
            v85 = (char *)TmpBuf;
            v83 = v107[0];
            v81 = 0;
            v79 = 0;
            v78 = (int)&local_7C;
            goto LABEL_15;
          }
          wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[401], v112);
          GUIWindow_DrawText(&local_7C, pFontArrus, 0, 146, 0, (char *)TmpBuf, 3);
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
              v40 = (int)GUIWindow_GetChild((GUI::Window *)v30, v110);
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
                v43 = (char *)aSkillNames[v38];
                *(_DWORD *)(v39 + 4) = v112 + v106;
                Str = v43;
                v44 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v43, &local_7C, 0, 0);
                v42 = *(_DWORD *)(v39 + 4);
                v45 = v113;
                *(_DWORD *)(v39 + 12) = v44;
                v46 = v42 + v44 - 1;
                *(_DWORD *)(v39 + 20) = v46;
                v106 = v46;
                v41 = v107[0];
                if (pDialogueWindow->dword_00002C != v45 )
                  v41 = v108[0];
                GUIWindow_DrawText(&local_7C, pFontArrus, 0, v42, v41, Str, 3);
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
      CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
      sub_4B46A5((char *)pGlobalTXT_LocalizationStrings[198], 0);
      result = sub_4B1784();
      if ( result )
      {
        v27 = *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v100) - 14;
        v109 = (v27 >> 5) + 14 * ((*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v98) + 4) - 17) >> 5);
        result = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v96);
        if ( *(_DWORD *)result > 13 )
        {
          result = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v94);
          if ( *(_DWORD *)result < 462 )
          {
            result = Player_sub_421E75_GetItemAtInventoryIndex((Player *)v0, &v109);
            v3 = 0;
            if ( result )
            {
              result *= 9;
              if ( *(_BYTE *)(v111 + 4 * result + 516) & 2 )
              {
                v86 = 0;
                v84 = 5;
                v82 = ptr_507BC0->dword_00001C;
                v80 = v111 + 4 * result + 496;
                v28 = ptr_507BC0->dword_00001C;
                v114 = uActiveCharacter;
                v29 = Player_sub_490EEE((Player *)v111, v111 + 4 * result + 496, 1, v28, 5);
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
        dword_F8B1B8[1] = pGlobalTXT_LocalizationStrings[152];
        dword_F8B1B8[2] = pGlobalTXT_LocalizationStrings[636];
        v14 = 0;
        dword_F8B1B8[3] = pGlobalTXT_LocalizationStrings[160];
        v15 = (const char **)dword_F8B1B8;
        do
        {
          v16 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v15, &local_7C, 0, 0);
          ++v15;
          v14 += v16;
        }
        while ( (signed int)v15 < (signed int)&unk_F8B1C8 );
        v17 = (int)pDialogueWindow;
        v106 = (174 - v14) / 4;
        result = pDialogueWindow->dword_000038;
        v19 = result + pDialogueWindow->dword_000028;
        v18 = (174 - 4 * (174 - v14) / 4 - v14) / 2 - (174 - v14) / 4 / 2 + 138;
        v20 = -pDialogueWindow->dword_000028 < 0;
        v111 = pDialogueWindow->dword_000038;
        
        compile_error();//if ( v20 ^ __SETO__(result, v19) )
        if (1)
        {
          v112 = 2;
          v113 = (int)dword_F8B1B8;
          do
          {
            v23 = (int)GUIWindow_GetChild((GUI::Window *)v17, v111);
            v24 = (const char **)v113;
            *(_DWORD *)(v23 + 4) = v106 + v18;
            v25 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v24, &local_7C, 0, 0);
            v22 = *(_DWORD *)(v23 + 4);
            v26 = v112;
            *(_DWORD *)(v23 + 12) = v25;
            v18 = v22 + v25 - 1;
            *(_DWORD *)(v23 + 20) = v18;
            v21 = v107[0];
            if (pDialogueWindow->dword_00002C != v26 )
              v21 = v108[0];
            GUIWindow_DrawText(&local_7C, pFontArrus, 0, v22, v21, *(const char **)v113, 3);
            v17 = (int)pDialogueWindow;
            ++v112;
            v113 += 4;
            ++v111;
            result = pDialogueWindow->dword_000028 + pDialogueWindow->dword_000038;
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
        CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
        sub_4B46A5((char *)pGlobalTXT_LocalizationStrings[199], 0);
        result = sub_4B1784();
        if ( result )
        {
          v11 = *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v97) - 14;
          v109 = (v11 >> 5) + 14 * ((*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v89) + 4) - 17) >> 5);
          result = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v95);
          if ( *(_DWORD *)result > 13 )
          {
            result = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v91);
            if ( *(_DWORD *)result < 462 )
            {
              result = Player_sub_421E75_GetItemAtInventoryIndex((Player *)v0, &v109);
              v3 = 0;
              if ( result )
              {
                v86 = 0;
                v84 = 3;
                v82 = ptr_507BC0->dword_00001C;
                v80 = v111 + 36 * result + 496;
                v12 = ptr_507BC0->dword_00001C;
                v114 = uActiveCharacter;
                v13 = Player_sub_490EEE((Player *)v111, v80, 1, v12, 3);
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
          CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
          sub_4B46A5((char *)pGlobalTXT_LocalizationStrings[197], 0);
          result = sub_4B1784();
          if ( result )
          {
            v2 = *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v99) - 14;
            v109 = (v2 >> 5) + 14 * ((*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v88) + 4) - 17) >> 5);
            result = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v101);
            if ( *(_DWORD *)result > 13 )
            {
              result = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v93);
              if ( *(_DWORD *)result < 462 )
              {
                result = Player_sub_421E75_GetItemAtInventoryIndex((Player *)v0, &v109);
                v3 = 0;
                if ( result )
                {
                  v86 = 0;
                  v84 = 4;
                  v4 = v111 + 36 * result + 496;
                  if ( !(*(_BYTE *)(v4 + 20) & 1) )
                  {
                    v82 = ptr_507BC0->dword_00001C;
                    v80 = v4;
                    v9 = ptr_507BC0->dword_00001C;
                    v114 = uActiveCharacter;
                    v10 = Player_sub_490EEE((Player *)v111, v4, 1, v9, 4);
                    v6 = v114;
                    v5 = dword_73C3DC[v10];
                    goto LABEL_14;
                  }
                  v82 = ptr_507BC0->dword_00001C;
                  v5 = (int)"%24";
                  v80 = v4;
LABEL_13:
                  v6 = uActiveCharacter;
LABEL_14:
                  v7 = (char *)sub_495461_DrawAn_AreYouSureWishTo_Join_Dismiss_ThisNPC_Dialogue((unsigned char *)v5, v6, v80, v82, v84, v86);
                  v87 = 3;
                  v85 = v7;
                  v83 = v108[0];
                  v81 = v3;
                  v79 = v3;
                  v78 = (int)&local_7C;
LABEL_15:
                  v8 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v7, (GUI::Window *)v78, v79, v81);
                  GUIWindow_DrawText(&local_7C, pFontArrus, v3, (174 - v8) / 2 + 138, v83, v85, v87);
                  return result;
                }
              }
            }
          }
        }
      }
      return result;
    }
  }
  Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (cTexture *)dword_F8B164[0]);
  v3 = 0;
  if ( dword_F8B19C == 2 )
  {
    v48 = 0;
    v112 = 0;
    v113 = 0;
    do
    {
     if ( dword_AD4734[9 * (v48 + 12 * ptr_507BC0->dword_00001C)] )
      {
        v49 = word_F8B158[v48];
        v50 = dword_F8B168[v48];
        v49 += 30;
        v51 = 60 - ((signed int)*(_WORD *)(v50 + 24) >> 1);
        Render_DrawTransparentTexture(pD3DRenderer, v51 + v112, v49, (cTexture *)v50);
        sub_40F92A((int)&pD3DRenderer->pActiveZBuffer[v51 + v112 + 640 * v49], dword_F8B168[v113], v113 + 1);
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
      if ( *(&dword_ADA0A4 + 9 * (v113 + 12 * ptr_507BC0->dword_00001C)) )
      {
        v52 = word_F8B158[v113] + 30;
        v53 = dword_F8B168[v113];
        v54 = 60 - ((signed int)*(_WORD *)(v53 + 24) >> 1);
        Render_DrawTransparentTexture(pD3DRenderer, v54 + v112, word_F8B158[v113] + 30, (cTexture *)v53);
        sub_40F92A((int)&pD3DRenderer->pActiveZBuffer[v54 + v112 + 640 * v52], dword_F8B168[v113], v113 + 1);
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
        if ( dword_AD4734[9 * (v55 + 12 * ptr_507BC0->dword_00001C)] )
          ++v109;
        ++v55;
      }
      while ( v55 < 6 );
    }
    else
    {
      do
      {
        if ( *(&dword_ADA0A4 + 9 * (v55 + 12 * ptr_507BC0->dword_00001C)) )
          ++v109;
        ++v55;
      }
      while ( v55 < 6 );
    }
    v57 = GetAsyncKeyState(VK_CONTROL);
    v56 = Player_sub_492C40((Player *)v111);
    Str = (char *)v56;
    if ( v57 && v56 )
    {
      v58 = (char *)pGlobalTXT_LocalizationStrings[185];
    }
    else
    {
      v58 = (char *)pGlobalTXT_LocalizationStrings[195];
      if ( dword_F8B19C != 2 )
        v58 = (char *)pGlobalTXT_LocalizationStrings[196];
    }
    sub_4B46A5(v58, 0);
    if ( v109 )
    {
      v59 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v92);
      result = *(_DWORD *)v59 + dword_5059A8[*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v90) + 4)];
      if (pD3DRenderer->pActiveZBuffer[result] & 0xFFFF )
      {
        v63 = (pD3DRenderer->pActiveZBuffer[result] & 0xFFFF) - 1;
        v109 = v63;
        v60 = ptr_507BC0->dword_00001C;
        v61 = 9 * (v63 + 12 * v60);
        v62 = 4 * v61 + 11355956;
        if ( dword_F8B19C != 2 )
          v62 = 4 * v61 + 11378852;
        if ( !v57 || !Str )
        {
          v86 = 0;
          v84 = 2;
          v82 = ptr_507BC0->dword_00001C;
          v80 = v62;
          v114 = uActiveCharacter;
          v64 = Player_sub_490EEE((Player *)v111, v62, 1, v60, 2);
          v6 = v114;
          v5 = *(_DWORD *)&dword_73C388[4 * v64];
          goto LABEL_14;
        }
        v5 = (int)pGlobalTXT_LocalizationStrings[181];
        v86 = 0;
        v84 = 2;
        v82 = ptr_507BC0->dword_00001C;
        v80 = v62;
        goto LABEL_13;
      }
    }
    else
    {
      compile_error();//result = (int)sub_4B1854(
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

  GUI::Window local_5C;
  //int v105; // [sp+5Ch] [bp-7Ch]@1
  //int v106; // [sp+64h] [bp-74h]@1
  //int v107; // [sp+6Ch] [bp-6Ch]@1

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

  v0 = pPlayers[uActiveCharacter - 1];
  v113 = (int)pPlayers[uActiveCharacter - 1];
  memcpy(&local_5C, ptr_507BC0, sizeof(GUI::Window));
  local_5C.uFrameX = 483;
  local_5C.uFrameWidth = 148;
  local_5C.uFrameZ = 334;
  *(_DWORD *)v111 = 0xFFFFFFFF;
  *(_DWORD *)v109 = 0xFFE1CD23;
  if ( dword_F8B19C == 1 )
  {
    result = sub_4B1784();
    if ( result )
    {
      dword_F8B1B8[0] = pGlobalTXT_LocalizationStrings[134];
      dword_F8B1B8[1] = pGlobalTXT_LocalizationStrings[152];
      dword_F8B1B8[2] = pGlobalTXT_LocalizationStrings[636];
      v72 = 0;
      dword_F8B1B8[3] = pGlobalTXT_LocalizationStrings[160];
      v73 = (const char **)dword_F8B1B8;
      do
      {
        v74 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v73, &local_5C, 0, 0);
        ++v73;
        v72 += v74;
      }
      while ( (signed int)v73 < (signed int)&unk_F8B1C8 );
      v75 = (int)pDialogueWindow;
      Str = (char *)((174 - v72) / 4);
      result = pDialogueWindow->dword_000038;
      v77 = result + pDialogueWindow->dword_000028;
      v76 = (174 - 4 * (174 - v72) / 4 - v72) / 2 - (174 - v72) / 4 / 2 + 138;
      v78 = -pDialogueWindow->dword_000028 < 0;
      v115 = pDialogueWindow->dword_000038;

      compile_error();//if ( v78 ^ __SETO__(result, v77) )
      if (1)
      {
        v113 = 2;
        v114 = (int)dword_F8B1B8;
        do
        {
          v81 = (int)GUIWindow_GetChild((GUI::Window *)v75, v115);
          v82 = (const char **)v114;
          *(_DWORD *)(v81 + 4) = (int)&Str[v76];
          v83 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v82, &local_5C, 0, 0);
          v80 = *(_DWORD *)(v81 + 4);
          v84 = v113;
          *(_DWORD *)(v81 + 12) = v83;
          v76 = v80 + v83 - 1;
          *(_DWORD *)(v81 + 20) = v76;
          v79 = v109[0];
          if (pDialogueWindow->dword_00002C != v84 )
            v79 = v111[0];
          GUIWindow_DrawText(&local_5C, pFontArrus, 0, v80, v79, *(const char **)v114, 3);
          v75 = (int)pDialogueWindow;
          ++v113;
          v114 += 4;
          ++v115;
          result = pDialogueWindow->dword_000028 + pDialogueWindow->dword_000038;
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
    CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
    sub_4B46A5((char *)pGlobalTXT_LocalizationStrings[199], 0);
    result = sub_4B1784();
    if ( !result
      || (v43 = *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v100) - 14,
          v112 = (v43 >> 5) + 14 * ((*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v96) + 4) - 17) >> 5),
          result = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v103),
          *(_DWORD *)result <= 13)
      || (result = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v101), *(_DWORD *)result >= 462)
      || (result = Player_sub_421E75_GetItemAtInventoryIndex((Player *)v0, &v112), v2 = 0, !result) )
      return result;
    v94 = 0;
    v92 = 3;
    v90 = ptr_507BC0->dword_00001C;
    v88 = v113 + 36 * result + 496;
    v44 = ptr_507BC0->dword_00001C;
    v116 = uActiveCharacter;
    v45 = Player_sub_490EEE((Player *)v113, v88, 4, v44, 3);
    v39 = v116;
    v38 = dword_73C3A4[v45];
LABEL_45:
    v21 = (char *)sub_495461_DrawAn_AreYouSureWishTo_Join_Dismiss_ThisNPC_Dialogue((unsigned char *)v38, v39, v88, v90, v92, v94);
    v93 = 3;
    v91 = v21;
    v89 = v111[0];
    v87 = v2;
    v86 = v2;
    v85 = (int)&local_5C;
    goto LABEL_46;
  }
  if ( dword_F8B19C == 4 )
  {
    sub_41A556();
    CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
    sub_4B46A5((char *)pGlobalTXT_LocalizationStrings[197], 0);
    result = sub_4B1784();
    if ( !result
      || (v36 = *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v104) - 14,
          v112 = (v36 >> 5) + 14 * ((*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v95) + 4) - 17) >> 5),
          result = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v102),
          *(_DWORD *)result <= 13)
      || (result = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v98), *(_DWORD *)result >= 462)
      || (result = Player_sub_421E75_GetItemAtInventoryIndex((Player *)v0, &v112), v2 = 0, !result) )
      return result;
    v94 = 0;
    v92 = 4;
    v37 = v113 + 36 * result + 496;
    if ( !(*(_BYTE *)(v37 + 20) & 1) )
    {
     v90 = ptr_507BC0->dword_00001C;
      v88 = v37;
      v41 = ptr_507BC0->dword_00001C;
      v116 = uActiveCharacter;
      v42 = Player_sub_490EEE((Player *)v113, v37, 4, v41, 4);
      v39 = v116;
      v38 = dword_73C3DC[v42];
      goto LABEL_45;
    }
    v90 = ptr_507BC0->dword_00001C;
    v38 = (int)"%24";
    v88 = v37;
    goto LABEL_44;
  }
  if ( dword_F8B19C == 94 )
  {
    sub_41A556();
    CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
    dword_F8B1B8[0] = pGlobalTXT_LocalizationStrings[200];
    dword_F8B1B8[1] = pGlobalTXT_LocalizationStrings[113];
    v23 = 0;
    v22 = (const char **)dword_F8B1B8;
    do
    {
      v24 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v22, &local_5C, 0, 0);
      ++v22;
      v23 += v24;
    }
    while ( (signed int)v22 < (signed int)&dword_F8B1B8[2] );
    Str = (char *)((174 - v23) / 2);
    v25 = (int)pDialogueWindow;
    result = pDialogueWindow->dword_000038;
    v27 = result + pDialogueWindow->dword_000028;
    v26 = (2 * (87 - (174 - v23) / 2) - v23) / 2 - (174 - v23) / 2 / 2 + 138;
    v28 = -pDialogueWindow->dword_000028 < 0;
    v115 = pDialogueWindow->dword_000038;
    
    compile_error();//if ( v28 ^ __SETO__(result, v27) )
    if (1)
    {
      v113 = 2;
      v114 = (int)dword_F8B1B8;
      do
      {
        v31 = (int)GUIWindow_GetChild((GUI::Window *)v25, v115);
        v32 = (const char **)v114;
        *(_DWORD *)(v31 + 4) = (int)&Str[v26];
        v33 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v32, &local_5C, 0, 0);
        v30 = *(_DWORD *)(v31 + 4);
        v34 = v113;
        *(_DWORD *)(v31 + 12) = v33;
        v35 = v33 + v30 - 1;
        *(_DWORD *)(v31 + 20) = v35;
        v26 = v35;
        v29 = v109[0];
        if (pDialogueWindow->dword_00002C != v34 )
          v29 = v111[0];
        GUIWindow_DrawText(&local_5C, pFontArrus, 0, v30, v29, *(const char **)v114, 3);
        v25 = (int)pDialogueWindow;
        ++v113;
        v114 += 4;
        ++v115;
        result = pDialogueWindow->dword_000028 + pDialogueWindow->dword_000038;
      }
      while ( v115 < result );
    }
    return result;
  }
  if ( dword_F8B19C == 95 )
  {
LABEL_134:
    Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (cTexture *)dword_F8B164[0]);
    v2 = 0;
    v117 = 0;
    if ( dword_F8B19C == 2 )
    {
      do
      {
        if ( dword_AD4734[9 * (v117 + 12 * ptr_507BC0->dword_00001C)] )
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
          Render_DrawTransparentTexture(pD3DRenderer, v48, v47, (cTexture *)v46);
          sub_40F92A((int)&pD3DRenderer->pActiveZBuffer[v48 + 640 * v47], dword_F8B168[v117], v117 + 1);
        }
        ++v117;
      }
      while ( v117 < 6 );
      v117 = 0;
      do
      {
        if ( dword_AD480C[9 * (v117 + 12 * ptr_507BC0->dword_00001C)] )
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
          Render_DrawTransparentTexture(pD3DRenderer, v52, v51, (cTexture *)v50);
          sub_40F92A((int)&pD3DRenderer->pActiveZBuffer[v52 + 640 * v51], dword_F8B180[v117], v117 + 7);
        }
        ++v117;
      }
      while ( v117 < 6 );
    }
    else
    {
      do
      {
        if ( *(&dword_ADA0A4 + 9 * (v117 + 12 * ptr_507BC0->dword_00001C)) )
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
          Render_DrawTransparentTexture(pD3DRenderer, v56, v55, (cTexture *)v54);
          sub_40F92A((int)&pD3DRenderer->pActiveZBuffer[v56 + 640 * v55], dword_F8B168[v117], v117 + 1);
        }
        ++v117;
      }
      while ( v117 < 6 );
      v117 = 0;
      do
      {
        if ( dword_ADA17C[9 * (v117 + 12 * ptr_507BC0->dword_00001C)] )
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
          Render_DrawTransparentTexture(pD3DRenderer, v60, v59, (cTexture *)v58);
          sub_40F92A((int)&pD3DRenderer->pActiveZBuffer[v60 + 640 * v59], dword_F8B180[v117], v117 + 7);
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
        if ( dword_AD4734[9 * (v62 + 12 * ptr_507BC0->dword_00001C)] )
          ++v112;
        ++v62;
      }
      while ( v62 < 12 );
    }
    else
    {
      do
      {
        if ( *(&dword_ADA0A4 + 9 * (v62 + 12 * ptr_507BC0->dword_00001C)) )
          ++v112;
        ++v62;
      }
      while ( v62 < 12 );
    }
    v64 = GetAsyncKeyState(VK_CONTROL);
    v63 = Player_sub_492C40((Player *)v113);
    Str = (char *)v63;
    if ( v64 && v63 )
    {
      v65 = (char *)pGlobalTXT_LocalizationStrings[185];
    }
    else
    {
      v65 = (char *)pGlobalTXT_LocalizationStrings[195];
      if ( dword_F8B19C != 2 )
        v65 = (char *)pGlobalTXT_LocalizationStrings[196];
    }
    sub_4B46A5(v65, 0);
    if ( !v112 )
      compile_error();//return (signed int)sub_4B1854(
                    //       &v105,
                    //       __PAIR__(
                    //         dword_ACD048[2 * *(_DWORD *)(dword_507BC0 + 28)],
                    //         dword_ACD044[2 * *(_DWORD *)(dword_507BC0 + 28)])
                    //     - pParty_global->qword_00002C);
    v66 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v99);
    result = *(_DWORD *)v66 + dword_5059A8[*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v97) + 4)];
    if ( !(pD3DRenderer->pActiveZBuffer[result] & 0xFFFF) )
      return result;
    v70 = (pD3DRenderer->pActiveZBuffer[result] & 0xFFFF) - 1;
    v112 = v70;
    v67 = ptr_507BC0->dword_00001C;
    v68 = 9 * (v70 + 12 * v67);
    v69 = 4 * v68 + 11355956;
    if ( dword_F8B19C != 2 )
      v69 = 4 * v68 + 11378852;
    if ( !v64 || !Str )
    {
      v94 = 0;
      v92 = 2;
      v90 = ptr_507BC0->dword_00001C;
      v88 = v69;
      v116 = uActiveCharacter;
      v71 = Player_sub_490EEE((Player *)v113, v69, 4, v67, 2);
      v39 = v116;
      v38 = *(_DWORD *)&dword_73C388[4 * v71];
      goto LABEL_45;
    }
    v38 = (int)pGlobalTXT_LocalizationStrings[181];
    v94 = 0;
    v92 = 2;
    v90 = ptr_507BC0->dword_00001C;
    v88 = v69;
LABEL_44:
    v39 = uActiveCharacter;
    goto LABEL_45;
  }
  result = dword_F8B19C - 96;
  if ( dword_F8B19C == 96 )
  {
    result = sub_4B1784();
    if ( result )
    {
      v3 = (int)pDialogueWindow;
      v2 = 0;
      v5 = ptr_507BC0->dword_00001C;
      v115 = 0;
      v4 = (signed __int64)(*((float *)&unk_59145C + 13 * v5) * 500.0);
      v114 = v4 * (100 - Player_sub_4911F3((Player *)v113)) / 100;
      if ( v114 < v4 / 3 )
        v114 = v4 / 3;
      v6 = *(_DWORD *)(v3 + 56);
      v7 = v6 + *(_DWORD *)(v3 + 40);
      v117 = 0;
      if ( v6 < v7 )
      {
        do
        {
          v8 = *(_DWORD *)(GUIWindow_GetChild((GUI::Window *)v3, v6) + 36) - 36;
          if ( *(&byte_4ED970[37 * *(_BYTE *)(v113 + 185)] + v8) )
          {
            if ( !*(_WORD *)(v113 + 2 * v8 + 264) )
            {
              //v9 = GUIFont_CalculateTextHeight(pFontArrus, (&dword_AE32D0)[4 * v8], (int)&v105, 0, 0);
              v9 = GUIFont_CalculateTextHeight(pFontArrus, aSkillNames[v8], &local_5C, 0, 0);
              v115 += v9;
              ++v117;
            }
          }
          ++v6;
        }
        while ( v6 < *(_DWORD *)(v3 + 40) + *(_DWORD *)(v3 + 56) );
        if ( v117 )
        {
          wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[401], v114);
          GUIWindow_DrawText(&local_5C, pFontArrus, 0, 146, 0, (char *)TmpBuf, 3);
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
              v13 = (int)GUIWindow_GetChild((GUI::Window *)v3, v115);
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
                v16 = (char *)aSkillNames[v11];
                *(_DWORD *)(v12 + 4) = v114 + v108;
                Str = v16;
                v17 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v16, &local_5C, 0, 0);
                v15 = *(_DWORD *)(v12 + 4);
                v18 = v117;
                *(_DWORD *)(v12 + 12) = v17;
                v19 = v15 + v17 - 1;
                *(_DWORD *)(v12 + 20) = v19;
                v108 = v19;
                v14 = v109[0];
                if (pDialogueWindow->dword_00002C != v18 )
                  v14 = v111[0];
                GUIWindow_DrawText(&local_5C, pFontArrus, 0, v15, v14, Str, 3);
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
      wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[544], v113 + 168, aClassNames[*(_BYTE *)(v113 + 185)]);
      strcat((char *)TmpBuf, "\n \n");
      strcat((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[528]);
      v21 = (char *)TmpBuf;
      v93 = 3;
      v91 = (char *)TmpBuf;
      v89 = v109[0];
      v87 = 0;
      v86 = 0;
      v85 = (int)&local_5C;
LABEL_46:
      v40 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v21, (GUI::Window *)v85, v86, v87);
      GUIWindow_DrawText(&local_5C, pFontArrus, v2, (174 - v40) / 2 + 138, v89, v91, v93);
      return result;
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

  GUI::Window local_8C;
  //int v140; // [sp+8Ch] [bp-78h]@1
  //int v141; // [sp+94h] [bp-70h]@1
  //int v142; // [sp+9Ch] [bp-68h]@1

  char *Str; // [sp+E0h] [bp-24h]@56
  int v144; // [sp+E4h] [bp-20h]@24
  __int16 v145[2]; // [sp+E8h] [bp-1Ch]@1
  __int16 v146[2]; // [sp+ECh] [bp-18h]@1
  int v147; // [sp+F0h] [bp-14h]@8
  int v148; // [sp+F4h] [bp-10h]@1
  unsigned __int8 v149; // [sp+FBh] [bp-9h]@15
  int v150; // [sp+FCh] [bp-8h]@24
  int v151; // [sp+100h] [bp-4h]@44

  v0 = (int)pPlayers[uActiveCharacter - 1];
  v148 = (int)pPlayers[uActiveCharacter - 1];
  memcpy(&local_8C, ptr_507BC0, sizeof(GUI::Window));
  local_8C.uFrameX = 483;
  local_8C.uFrameWidth = 148;
  local_8C.uFrameZ = 334;
  *(_DWORD *)v146 = 0xFFFFFFFF;
  *(_DWORD *)v145 = 0xFFE1CD23;
  if ( dword_F8B19C > 5 )
  {
    if ( dword_F8B19C == 6 )
    {
      Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (cTexture *)dword_F8B164[0]);
      sub_4B46A5((char *)pGlobalTXT_LocalizationStrings[195], 0);
      v1 = sub_4B1784();
      if ( !v1 )
        return v1;
      v147 = 0;
      v88 = 0;
      do
      {
       if ( *(&dword_ADA0A4 + 9 * (v88 + 12 * ptr_507BC0->dword_00001C)) )
          ++v147;
        ++v88;
      }
      while ( v88 < 8 );
      if ( v147 )
      {
        v90 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v128);
        v147 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer
                         + 4 * (*(_DWORD *)v90 + dword_5059A8[*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v126) + 4)]));
        v89 = v147;
        if ( v147 )
        {
          if ( v147 != -65536 )
          {
            --v147;
            v91 = ptr_507BC0->dword_00001C;
            v92 = uActiveCharacter;
            v93 = 36 * (v89 - 1 + 12 * v91) + 11378852;
            v94 = Player_sub_490EEE((Player *)v148, 36 * (v89 - 1 + 12 * v91) + 11378852, 2, ptr_507BC0->dword_00001C, 2);
            v95 = (char *)sub_495461_DrawAn_AreYouSureWishTo_Join_Dismiss_ThisNPC_Dialogue(&dword_73C388[4 * v94], v92, v93, v91, 2, 0);
            v96 = v95;
            v97 = v146[0];
            v98 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v95, &local_8C, 0, 0);
            GUIWindow_DrawText(&local_8C, pFontArrus, 0, (174 - v98) / 2 + 138, v97, v96, 3);
          }
        }
        v99 = 0;
        v151 = 0;
        do
        {
          v1 = 9 * (v99 + 12 * ptr_507BC0->dword_00001C);
          if ( *(&dword_ADA0A4 + 9 * (v99 + 12 * ptr_507BC0->dword_00001C)) )
          {
            v100 = dword_F8B168[v99];
            if ( v99 >= 4 )
            {
              v105 = 90 - ((signed int)*(_WORD *)(v100 + 24) >> 1);
              Render_DrawTransparentTexture(pD3DRenderer, v151 + v105 - 420, 126, (cTexture *)dword_F8B168[v99]);
              v123 = v99 + 1;
              v101 = v151 + v105 + 80220;
            }
            else
            {
              v102 = 98 - *(_WORD *)(v100 + 26);
              v103 = dword_F8B168[v99];
              v104 = 98 - *(_WORD *)(v100 + 26);
              v150 = 86 - ((signed int)*(_WORD *)(v100 + 24) >> 1);
              Render_DrawTransparentTexture(pD3DRenderer, v150 + v151, v104, (cTexture *)v103);
              v123 = v99 + 1;
              v101 = v150 + v151 + 640 * v102;
            }
            array_40F89C_ActuallyFillZBuffer(pD3DRenderer->pActiveZBuffer + v101, (cTexture *)dword_F8B168[v99], v123);
          }
          v151 += 105;
          ++v99;
        }
        while ( v99 < 8 );
        return v1;
      }
      v67 = ptr_507BC0->dword_00001C;
      goto LABEL_96;
    }
    if ( dword_F8B19C == 94 )
    {
      sub_41A556();
      CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
      v75 = (const char **)dword_F8B1B8;
      dword_F8B1B8[0] = pGlobalTXT_LocalizationStrings[200];
      dword_F8B1B8[1] = pGlobalTXT_LocalizationStrings[113];
      dword_F8B1B8[2] = pGlobalTXT_LocalizationStrings[179];
      v74 = 0;
      v76 = (const char **)dword_F8B1B8;
      do
      {
        v77 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v76, &local_8C, 0, 0);
        ++v76;
        v74 += v77;
      }
      while ( (signed int)v76 < (signed int)&dword_F8B1B8[3] );
      v78 = (int)pDialogueWindow;
      v150 = (174 - v74) / 3;
      v1 = pDialogueWindow->dword_000038;
      v80 = v1 + pDialogueWindow->dword_000028;
      v79 = (3 * (58 - v150) - v74) / 2 - v150 / 2 + 138;
      v81 = -pDialogueWindow->dword_000028 < 0;
      v148 = pDialogueWindow->dword_000038;
      
      compile_error();//if ( v81 ^ __SETO__(v1, v80) )
      if (1)
      {
        v151 = 2;
        do
        {
          v84 = (int)GUIWindow_GetChild((GUI::Window *)v78, v148);
          v85 = v84;
          *(_DWORD *)(v84 + 4) = v150 + v79;
          v86 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v75, &local_8C, 0, 0);
          v83 = *(_DWORD *)(v85 + 4);
          v87 = v151;
          *(_DWORD *)(v85 + 12) = v86;
          v79 = v83 + v86 - 1;
          *(_DWORD *)(v85 + 20) = v79;
          v82 = v145[0];
          if (pDialogueWindow->dword_00002C != v87 )
            v82 = v146[0];
          GUIWindow_DrawText(&local_8C, pFontArrus, 0, v83, v82, *v75, 3);
          v78 = (int)pDialogueWindow;
          ++v151;
          ++v75;
          ++v148;
          v1 = pDialogueWindow->dword_000028 + pDialogueWindow->dword_000038;
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
      v33 = (int)pDialogueWindow;
      v34 = (signed __int64)(*((float *)&unk_59145C + 13 * ptr_507BC0->dword_00001C) * 500.0);
      v148 = v34 * (100 - Player_sub_4911F3((Player *)v0)) / 100;
      if ( v148 < v34 / 3 )
        v148 = v34 / 3;
      v35 = *(_DWORD *)(v33 + 56);
      v36 = *(_DWORD *)(v33 + 40);
      v151 = 0;
      if ( v35 < v35 + v36 )
      {
        do
        {
          v37 = *(_DWORD *)(GUIWindow_GetChild((GUI::Window *)v33, v35) + 36) - 36;
          if ( *(&byte_4ED970[37 * *(_BYTE *)(v0 + 185)] + v37) )
          {
            if ( !*(_WORD *)(v0 + 2 * v37 + 264) )
            {
              v38 = GUIFont_CalculateTextHeight(pFontArrus, aSkillNames[v37], &local_8C, 0, 0);
              v150 += v38;
              ++v151;
            }
          }
          ++v35;
        }
        while ( v35 < *(_DWORD *)(v33 + 40) + *(_DWORD *)(v33 + 56) );
        if ( v151 )
        {
          wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[401], v148);
          GUIWindow_DrawText(&local_8C, pFontArrus, 0, 146, 0, (char *)TmpBuf, 3);
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
              v42 = (int)GUIWindow_GetChild((GUI::Window *)v33, v150);
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
                v45 = (char *)aSkillNames[v40];
                *(_DWORD *)(v41 + 4) = v148 + v144;
                Str = v45;
                v46 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v45, &local_8C, 0, 0);
                v44 = *(_DWORD *)(v41 + 4);
                v47 = v151;
                *(_DWORD *)(v41 + 12) = v46;
                v48 = v44 + v46 - 1;
                *(_DWORD *)(v41 + 20) = v48;
                v144 = v48;
                v43 = v145[0];
                if (pDialogueWindow->dword_00002C != v47 )
                  v43 = v146[0];
                GUIWindow_DrawText(&local_8C, pFontArrus, 0, v44, v43, Str, 3);
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
      wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[544], v0 + 168, aClassNames[*(_BYTE *)(v0 + 185)]);
      strcat((char *)TmpBuf, "\n \n");
      strcat((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[528]);
      v10 = 0;
      v32 = (char *)TmpBuf;
      v119 = 3;
      v117 = (char *)TmpBuf;
      v115 = v145[0];
      v113 = 0;
      v109 = 0;
      v107 = (int)&local_8C;
LABEL_63:
      v111 = (174 - GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v32, (GUI::Window *)v107, v109, v113)) / 2 + 138;
      v108 = (int)v10;
LABEL_14:
      /*LOBYTE(v1) = (unsigned int)*/GUIWindow_DrawText(&local_8C, pFontArrus, v108, v111, v115, v117, v119);
      return 0;// v1;
    }
LABEL_64:
    Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (cTexture *)dword_F8B164[0]);
    if ( dword_F8B19C == 2 )
    {
      v50 = 0;
      v151 = 0;
      do
      {
        if ( dword_AD4734[9 * (v50 + 12 * ptr_507BC0->dword_00001C)] )
        {
          v51 = dword_F8B168[v50];
          if ( v50 >= 4 )
          {
            v55 = 90 - ((signed int)*(_WORD *)(v51 + 24) >> 1);
            Render_DrawTransparentTexture(pD3DRenderer, v55 + v151 - 420, 126, (cTexture *)dword_F8B168[v50]);
            v121 = v50 + 1;
            v52 = v55 + v151 + 80220;
          }
          else
          {
            v53 = 98 - *(_WORD *)(v51 + 26);
            v54 = dword_F8B168[v50];
            v150 = 86 - ((signed int)*(_WORD *)(v51 + 24) >> 1);
            Render_DrawTransparentTexture(pD3DRenderer, v151 + v150, v53, (cTexture *)v54);
            v121 = v50 + 1;
            v52 = v151 + v150 + 640 * v53;
          }
          array_40F89C_ActuallyFillZBuffer(pD3DRenderer->pActiveZBuffer + 4 * v52, (cTexture *)dword_F8B168[v50], v121);
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
        if ( (char *)*(&dword_ADA0A4 + 9 * (v56 + 12 * ptr_507BC0->dword_00001C)) != v10 )
        {
          v57 = dword_F8B168[v56];
          if ( v56 >= 4 )
          {
            v62 = 90 - ((signed int)*(_WORD *)(v57 + 24) >> 1);
            Render_DrawTransparentTexture(pD3DRenderer, v151 + v62 - 420, 126, (cTexture *)dword_F8B168[v56]);
            v122 = v56 + 1;
            v58 = v151 + v62 + 80220;
          }
          else
          {
            v59 = 98 - *(_WORD *)(v57 + 26);
            v60 = dword_F8B168[v56];
            v61 = 98 - *(_WORD *)(v57 + 26);
            v150 = 86 - ((signed int)*(_WORD *)(v57 + 24) >> 1);
            Render_DrawTransparentTexture(pD3DRenderer, v150 + v151, v61, (cTexture *)v60);
            v122 = v56 + 1;
            v58 = v150 + v151 + 640 * v59;
          }
          array_40F89C_ActuallyFillZBuffer(pD3DRenderer->pActiveZBuffer + 4 * v58, (cTexture *)dword_F8B168[v56], v122);
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
        if ( (char *)dword_AD4734[9 * (v63 + 12 * ptr_507BC0->dword_00001C)] != v10 )
          ++v147;
        ++v63;
      }
      while ( v63 < 6 );
    }
    else
    {
      do
      {
        if ( (char *)*(&dword_ADA0A4 + 9 * (v63 + 12 * ptr_507BC0->dword_00001C)) != v10 )
          ++v147;
        ++v63;
      }
      while ( v63 < 6 );
    }
    v65 = GetAsyncKeyState(VK_CONTROL);
    v64 = Player_sub_492C40((Player *)v148);
    Str = (char *)v64;
    if ( v65 == (_WORD)v10 || (char *)v64 == v10 )
    {
      v66 = (char *)pGlobalTXT_LocalizationStrings[195];
      if ( dword_F8B19C != 2 )
        v66 = (char *)pGlobalTXT_LocalizationStrings[196];
    }
    else
    {
      v66 = (char *)pGlobalTXT_LocalizationStrings[185];
    }
    sub_4B46A5(v66, 0);
    if ( (char *)v147 != v10 )
    {
      v69 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v132);
      v1 = *(_DWORD *)v69 + dword_5059A8[*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v130) + 4)];
      v68 = pD3DRenderer->pActiveZBuffer[v1] & 0xFFFF;
      if ( !(pD3DRenderer->pActiveZBuffer[v1] & 0xFFFF) )
        return v1;
      v147 = v68 - 1;
      v70 = ptr_507BC0->dword_00001C;
      v71 = 9 * (v68 - 1 + 12 * v70);
      if ( dword_F8B19C == 2 )
        v72 = 4 * v71 + 11355956;
      else
        v72 = 4 * v71 + 11378852;
      if ( v65 == (_WORD)v10 || Str == v10 )
      {
        v120 = (__int64 *)v10;
        v118 = 2;
        v116 = ptr_507BC0->dword_00001C;
        v112 = v72;
        v73 = uActiveCharacter;
        v12 = *(_DWORD *)&dword_73C388[4 * Player_sub_490EEE((Player *)v148, v72, 2, v70, 2)];
        v11 = v73;
      }
      else
      {
        v120 = (__int64 *)v10;
        v118 = 2;
        v116 = ptr_507BC0->dword_00001C;
        v112 = v72;
        v12 = (int)pGlobalTXT_LocalizationStrings[181];
        v11 = uActiveCharacter;
      }
LABEL_36:
      v32 = (char *)sub_495461_DrawAn_AreYouSureWishTo_Join_Dismiss_ThisNPC_Dialogue((unsigned char *)v12, v11, v112, v116, v118, v120);
      v119 = 3;
      v117 = v32;
      v115 = v146[0];
      v113 = (int)v10;
      v109 = (char)v10;
      v107 = (int)&local_8C;
      goto LABEL_63;
    }
    v67 = ptr_507BC0->dword_00001C;
LABEL_96:
    compile_error();//LOBYTE(v1) = (unsigned int)sub_4B1854(&v140, __PAIR__(dword_ACD048[2 * v67], dword_ACD044[2 * v67]) - pParty_global->qword_00002C);
    return v1;
  }
  if ( dword_F8B19C == 5 )
  {
    sub_41A556();
    CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
    sub_4B46A5((char *)pGlobalTXT_LocalizationStrings[198], 0);
    v1 = sub_4B1784();
    if ( !v1
      || (v29 = *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v131) - 14,
          v147 = (v29 >> 5) + 14 * ((*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v138) + 4) - 17) >> 5),
          v1 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v136),
          *(_DWORD *)v1 <= 13)
      || (v1 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v134), *(_DWORD *)v1 >= 462)
      || (v1 = Player_sub_421E75_GetItemAtInventoryIndex((Player *)v0, &v147), v10 = 0, !v1)
      || (v1 *= 9, !(*(_BYTE *)(v0 + 4 * v1 + 516) & 2)) )
      return v1;
    v120 = 0;
    v118 = 5;
    v116 = ptr_507BC0->dword_00001C;
    v112 = v0 + 4 * v1 + 496;
    v30 = ptr_507BC0->dword_00001C;
    v149 = uActiveCharacter;
    v31 = Player_sub_490EEE((Player *)v0, v0 + 4 * v1 + 496, 2, v30, 5);
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
      dword_F8B1B8[1] = pGlobalTXT_LocalizationStrings[152];
      dword_F8B1B8[2] = pGlobalTXT_LocalizationStrings[636];
      v15 = 0;
      dword_F8B1B8[3] = pGlobalTXT_LocalizationStrings[160];
      v17 = (const char **)dword_F8B1B8;
      do
      {
        v18 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v17, &local_8C, 0, 0);
        ++v17;
        v15 += v18;
      }
      while ( (signed int)v17 < (signed int)&unk_F8B1C8 );
      v19 = (int)pDialogueWindow;
      v144 = (174 - v15) / 4;
      v1 = pDialogueWindow->dword_000038;
      v21 = v1 + pDialogueWindow->dword_000028;
      v20 = (174 - 4 * (174 - v15) / 4 - v15) / 2 - (174 - v15) / 4 / 2 + 138;
      v22 = -pDialogueWindow->dword_000028 < 0;
      v150 = pDialogueWindow->dword_000038;
      
      compile_error();//if ( v22 ^ __SETO__(v1, v21) )
      if (1)
      {
        v148 = 2;
        do
        {
          v25 = (int)GUIWindow_GetChild((GUI::Window *)v19, v150);
          v26 = v25;
          *(_DWORD *)(v25 + 4) = v144 + v20;
          v27 = GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)*v16, &local_8C, 0, 0);
          v24 = *(_DWORD *)(v26 + 4);
          v28 = v148;
          *(_DWORD *)(v26 + 12) = v27;
          v20 = v24 + v27 - 1;
          *(_DWORD *)(v26 + 20) = v20;
          v23 = v145[0];
          if (pDialogueWindow->dword_00002C != v28 )
            v23 = v146[0];
          GUIWindow_DrawText(&local_8C, pFontArrus, 0, v24, v23, *v16, 3);
          v19 = (int)pDialogueWindow;
          ++v148;
          ++v16;
          ++v150;
          v1 = pDialogueWindow->dword_000028 + pDialogueWindow->dword_000038;
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
    CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
    sub_4B46A5((char *)pGlobalTXT_LocalizationStrings[199], 0);
    v1 = sub_4B1784();
    if ( !v1
      || (v9 = *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v135) - 14,
          v147 = (v9 >> 5) + 14 * ((*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v129) + 4) - 17) >> 5),
          v1 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v133),
          *(_DWORD *)v1 <= 13)
      || (v1 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v125), *(_DWORD *)v1 >= 462)
      || (v1 = Player_sub_421E75_GetItemAtInventoryIndex((Player *)v0, &v147), v10 = 0, !v1) )
      return v1;
    v120 = 0;
    v118 = 3;
    v116 = ptr_507BC0->dword_00001C;
    v112 = v0 + 36 * v1 + 496;
    v13 = ptr_507BC0->dword_00001C;
    v149 = uActiveCharacter;
    v14 = Player_sub_490EEE((Player *)v0, v112, 2, v13, 3);
    v11 = v149;
    v12 = dword_73C3A4[v14];
    goto LABEL_36;
  }
  v1 = dword_F8B19C - 4;
  if ( dword_F8B19C == 4 )
  {
    sub_41A556();
    CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
    sub_4B46A5((char *)pGlobalTXT_LocalizationStrings[197], 0);
    v1 = sub_4B1784();
    if ( v1 )
    {
      v2 = *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v127) - 14;
      v147 = (v2 >> 5) + 14 * ((*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v124) + 4) - 17) >> 5);
      v1 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v137);
      if ( *(_DWORD *)v1 > 13 )
      {
        v1 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v139);
        if ( *(_DWORD *)v1 < 462 )
        {
          v1 = Player_sub_421E75_GetItemAtInventoryIndex((Player *)v0, &v147);
          if ( v1 )
          {
            v3 = v0 + 36 * v1 + 496;
            if ( *(_BYTE *)(v3 + 20) & 1 )
            {
              v114 = ptr_507BC0->dword_00001C;
              v4 = uActiveCharacter;
              v5 = "%24";
              v110 = v3;
            }
            else
            {
              v114 = ptr_507BC0->dword_00001C;
              v110 = v3;
              v7 = ptr_507BC0->dword_00001C;
              v149 = uActiveCharacter;
              v8 = Player_sub_490EEE((Player *)v0, v3, 2, v7, 4);
              v4 = v149;
              v5 = (char *)dword_73C3DC[v8];
            }
            v6 = (char *)sub_495461_DrawAn_AreYouSureWishTo_Join_Dismiss_ThisNPC_Dialogue((unsigned char *)v5, v4, v110, v114, 4, 0);
            v119 = 3;
            v117 = v6;
            v115 = v146[0];
            v111 = (174 - GUIFont_CalculateTextHeight(pFontArrus, (unsigned char *)v6, &local_8C, 0, 0)) / 2 + 138;
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
       /* if ( dword_50CBD0[0] < 40 )
        {
          dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
          dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
          dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
        }	*/
	  dword_50CBD0.PutMessageToQueue(113,0,0);
        dword_50C9DC = 195;
        dword_50C9E0 = sub_4459F9_GetNPCData(uDialogue_SpeakingActorID);
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
      sub_42777D_CastSpell(v26, 0, v28, v30, v32);
      return 0;
    }
    v20 = sub_4418B1(10005, 201, 0, 65536);
    SpellBuf_sub_4584E0(&pParty_global->pPartyBuffs[SPELLBUFF_WATERWALK], pParty_global->qword_00002C + 46080, (unsigned __int64)(pParty_global->qword_00002C + 46080) >> 32, 3, 0, v20, 0);
    pParty_global->pPartyBuffs[SPELLBUFF_WATERWALK].byte_00000F |= 0x01;
    v31 = 0;
    v29 = 0;
    v27 = 0;
    v25 = 0;
    v24 = -1;
    v23 = 0;
    v22 = 0;
    v21 = 12040;
LABEL_40:
    pAudioPlayer->sub_4AA306(v21, v22, v23, v24, v25, v27, v29, v31);
    return 0;
  }
  if ( a1 == 39 )
  {
    if ( uCurrentlyLoadedLevelType == 1 )
    {
      sub_44C175((char *)pGlobalTXT_LocalizationStrings[494], 2);
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
      SpellBuf_sub_4584E0(&pParty_global->pPartyBuffs[SPELLBUFF_FLY], pParty_global->qword_00002C + 30720, (unsigned __int64)(pParty_global->qword_00002C + 30720) >> 32, 3, 1, v19, 0);
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
      *(_DWORD *)(v7 + 6340) = Player_GetMaxHealth((Player *)(v7 - 120));
      v7 += 6972;
    }
    //while ( v7 < (signed int)&unk_AD46EC );
    while (v7 < pParty_global->pHiredNPCs[1].dword_00002C);
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
      *(_DWORD *)(v4 + 6180) = Player_GetMaxHealth((Player *)(v4 - 280));
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

  uDialogueType = 83;
  GUIWindowDelete(pDialogueWindow);
  pDialogueWindow = GUIWindowCreate(0, 0, 640, 350, 1, 0, 0);
  dword_5076F4 = GUIButtonCreate(pDialogueWindow,
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
                   uTextureID_right_backgr != -1 ?  &LODFile_Icons_LOD.aLODHeaders[uTextureID_right_backgr] : 0);
  GUIButtonCreate(pDialogueWindow, 0, 0, 0, 0, 1, 0, 81, 0, 0, NULL, 0);
  GUIButtonCreate(pDialogueWindow, 480, 160, 140, 30, 1, 0, 0, 83, 0, NULL, 0);
  GUIWindow_sub_41D08F(pDialogueWindow, 1, 1, 0, 2);
  dword_F8B19C = -1;
  v1 = ptr_507BC0->dword_00001C - 102;
  v0 = pParty_global->Abc.array_00003C[2 * v1 + 1];
  if ( v0 <= HIDWORD(pParty_global->qword_00002C) )
  {
    if ( v0 < HIDWORD(pParty_global->qword_00002C) || pParty_global->Abc.array_00003C[2 * v1] < (_DWORD)pParty_global->qword_00002C )
    {
      pParty_global->array_00075A[v1] = 0;
      v3 = (signed __int64)((double)(309657600
                                   * ((unsigned int)pParty_global->uCurrentMonth + 12i64 * (unsigned int)pParty_global->uCurrentYear - 14015))
                          * 0.03333333507180214);
      pParty_global->Abc.array_00003C[2 * v1] = v3;
      pParty_global->Abc.array_00003C[2 * v1 + 1] = HIDWORD(v3);
      for ( i = rand(); ; i = rand() )
      {
        v4 = i % 258 + 1;
        pParty_global->array_000750[v1] = v4;

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
  v5 = *(__int16 *)((char *)pParty_global->array_000750 + v6);
  v7 = *(__int16 *)((char *)pParty_global->array_00075A + v6) == 0;
  word_F8B1A0 = *(__int16 *)((char *)pParty_global->array_000750 + v6);
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
        Player_sub_44A5CB((char *)&pParty_global->pPlayers[i], 12, 86);

      pParty_global->uNumBountiesCollected += 100 * pMonsterStats->pMonsterInfos[*(unsigned __int16 *)((char *)pParty_global->array_000750 + v6)].uLevel;
      *(__int16 *)((char *)pParty_global->array_000750 + v6) = 0;
      *(__int16 *)((char *)pParty_global->array_00075A + v6) = 0;
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
      uDialogueType = 92;
    }
    else
    {
      v0 = 0;
      if ( (signed int)uNumActors <= 0 )
        goto LABEL_23;
      v1 = (int)&pActors[0].uAIState;
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
        uDialogueType = 91;
        ++byte_ACD719[(unsigned __int8)byte_ACD76D];

        for (i = 0; i < 4; ++i)
          Player_sub_44A5CB((char *)&pParty_global->pPlayers[i], 12, (unsigned __int8)byte_ACD76D + 3);

        sub_420C05(uArenaReward, 0);
        pAudioPlayer->sub_4AA306(14060, 0, 0, -1, 0, 0, 0, 0);
        byte_ACD76D = -1;
      }
      else
      {
        uDialogueType = 90;
        pParty_global->vPosition = Vec3<int>(3849, 5770, 1);
        pParty_global->dword_000700 = 1;
        pParty_global->sRotationY = 512;
        pParty_global->sRotationX = 0;
        pParty_global->dword_0006E8 = 0;
        pAudioPlayer->sub_4AA306(14060, 0, 0, -1, 0, 0, 0, 0);
      }
    }
  }
  else
  {
    uDialogueType = 89;
    v6 = (int)pDialogueWindow->pControlsHead;
    if ( v6 )
    {
      do
      {
        v7 = *(_DWORD *)(v6 + 52);
        //MemFree( (void *)(void *)v6);
        MemFree((void *)v6);
        v6 = v7;
      }
      while ( v7 );
    }
    pDialogueWindow->pControlsHead = 0;
    pDialogueWindow->pControlsTail = 0;
    pDialogueWindow->uNumControls = 0;
    dword_5076F4 = GUIButtonCreate(pDialogueWindow,
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
                     uTextureID_right_backgr != -1 ?  &LODFile_Icons_LOD.aLODHeaders[uTextureID_right_backgr] : 0);
    GUIButtonCreate(pDialogueWindow, 480, 160, 140, 30, 1, 0, 136, 85, 0, NULL, 0);
    GUIButtonCreate(pDialogueWindow, 480, 190, 140, 30, 1, 0, 136, 86, 0, NULL, 0);
    GUIButtonCreate(pDialogueWindow, 480, 220, 140, 30, 1, 0, 136, 87, 0, NULL, 0);
    GUIButtonCreate(pDialogueWindow, 480, 250, 140, 30, 1, 0, 136, 88, 0, NULL, 0);
    GUIWindow_sub_41D08F(pDialogueWindow, 4, 1, 0, 1);
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

    //if ( (dword_71FFF8 >> 10) - (dword_71FFF4 >> 10) >= 2000 )
    //if ( (memory_manager.uBigBufferSizeAligned >> 10) - (memory_manager.uNextFreeOffsetInBigBuffer >> 10) >= 2000)
    //{
      v16 = 0;
      if ( uCurrentlyLoadedLevelType == 1 )
      {
        v5 = uNumActors;
        v16 = IndoorLocation_sub_49AC17(pIndoor, a2, a3, a4);
      }
      v8 = (int)&pActors[v5];
      Actor_Reset((Actor *)v8);
      v9 = v4;
      v7 = (int *)&pMonsterStats->pMonsterInfos[v4];
      v10 = 152 * v9 + (int)pMonsterDescriptionList->pDescriptions - 152;
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
      Actor_LinkSprites((Actor *)v8, 0);
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
    //}
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

  GUI::Window local_D4;
  //char v24; // [sp+D4h] [bp-6Ch]@1
  //int v25; // [sp+DCh] [bp-64h]@1
  //int v26; // [sp+E4h] [bp-5Ch]@1
  //__int16 v27; // [sp+126h] [bp-1Ah]@44

  __int16 v28[6]; // [sp+128h] [bp-18h]@56
  int v29; // [sp+134h] [bp-Ch]@1
  int v30; // [sp+138h] [bp-8h]@23
  int v31; // [sp+13Ch] [bp-4h]@17
 int i;

  v29 = 0;
  byte_ACD76D = uDialogueType;

  memcpy(&local_D4, pDialogueWindow, sizeof(GUI::Window));

  local_D4.uFrameWidth = 460;
  local_D4.uFrameZ = 452;
  v0 = GUIFont_CalculateTextHeight(pFontArrus, pGlobalTXT_LocalizationStrings[575], &local_D4, 13, 0) + 7;
  pD3DRenderer->BeginScene();
  if ( uCurrentlyLoadedLevelType == 1 )
  {
    sub_441BD4_DrawIndoor();
  }
  else
  {
    if ( uCurrentlyLoadedLevelType == 2 )
    {
     // sub_441CFF_DrawOutdoor();
     pParty_global->dword_007778 |= 2;
     sub_47A59E_LooksLikeMessWithRenderListAndMaybeDraw();

     sub_47A815_DrawClass02Lines();
     sub_4C2EFA(&struct_6BD080);
     sub_440F07(array_5118E8);
    }
  }
  //RenderD3D3_DrawBillboards_And_MaybeRenderSpecialEffects_And_EndScene(pD3DRenderer);
  pD3DRenderer->EndScene();

  pD3DRenderer->BeginScene();
  if ( pD3DRenderer->pRenderD3D3 )
    Render_FillRect2(pD3DRenderer,
      pOldViewport->uGameX,
      pOldViewport->uGameY,
      pOldViewport->uGameZ - pOldViewport->uGameX,
      pOldViewport->uGameW - pOldViewport->uGameY + 1,
      pD3DRenderer->uTargetGMask | pD3DRenderer->uTargetBMask);
  Render_sub_4A6A68(pD3DRenderer,
    8,
    352 - v0,
    uTextureIdx_Leather != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[uTextureIdx_Leather] : 0,
    (uTextureIdx_Leather != -1 ? LODFile_Icons_LOD.aLODHeaders[uTextureIdx_Leather].uTextureHeight : 26) - v0);
  Render_DrawIndexedTexture(pD3DRenderer, 8, 347 - v0, pcTexture_EndcapTexture);

  unsigned char pOutString[2048];
  v1 = (char *)FitTextInAWindow(pGlobalTXT_LocalizationStrings[575], pOutString, pFontArrus, &local_D4, 13, 0);
  FontDrawText(pDialogueWindow, pFontArrus, 13, 354 - v0, v1, 0, 0, 0);
  pD3DRenderer->EndScene();
  pD3DRenderer->Present();
  pParty_global->vPosition = Vec3<int>(3849, 5770, 1);
  pParty_global->dword_000700 = 1;
  pParty_global->sRotationY = 512;
  pParty_global->sRotationX = 0;
  pParty_global->dword_0006E8 = 0;
 /* if ( dword_50CBD0[0] < 40 )
  {
    dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
    dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
    dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
  }	*/
  dword_50CBD0.PutMessageToQueue(113,1,0);


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

  if ( uDialogueType == 85 )
  {
    v31 = v3;
    goto LABEL_22;
  }
  if ( uDialogueType == 86 )
  {
    v5 = (signed __int64)((double)v29 * 1.5);
    goto LABEL_20;
  }
  if ( uDialogueType == 87 )
  {
    LODWORD(v5) = 2 * v3;
LABEL_20:
    v31 = v5;
LABEL_22:
    v3 /= 2;
    goto LABEL_24;
  }
  if ( uDialogueType == 88 )
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
  v7 = (int)&pMonsterStats->pMonsterInfos[1].uLevel;
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
  while (v7 <= (int)&pMonsterStats->pMonsterInfos[102].uLevel);

  v31 = 6;
  if ( v6 < 6 )
    v31 = v6;
  v9 = 0;
  if ( v31 > 0 )
  {
    do
    {
      v10 = rand();
      v28[v9++] = v23[v10 % v6];
    }
    while (v9 < v31);
  }
  if ( uDialogueType == 85 )
  {
    v16 = rand();
    v17 = 3;
    v22 = 50;
    goto LABEL_53;
  }
  if ( uDialogueType == 86 )
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
  if ( uDialogueType == 87 )
  {
    v15 = rand() % 11;
    v13 = 200;
    v14 = v15 + 10;
  }
  else
  {
    if ( uDialogueType == 88 )
    {
      v13 = 500;
      v14 = 20;
    }
    else
    {
      v14 = v30;
      v13 = uArenaReward;
    }
  }
LABEL_55:
  v19 = 0;
  for ( uArenaReward = v29 * v13; v19 < v14; ++v19 )
  {
    v20 = dword_4F0E94[2 * v19];
    v21 = rand();
    sub_4BBF61((unsigned __int16)v28[v21 % v31], dword_4F0E90[2 * v19], v20, 1);
  }
  pAudioPlayer->sub_4AA306(14060, 0, 0, -1, 0, 0, 0, 0);
}

//----- (004BC49B) --------------------------------------------------------
void __thiscall sub_4BC49B(void *_this)
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

  v3 = (int)_this;
  v2 = (char *)sub_4459F9_GetNPCData(uDialogue_SpeakingActorID);
  v1 = v3;
  uDialogueType = v3;
  if ( !*((_DWORD *)v2 + 2) )
  {
    *((_DWORD *)v2 + 2) = 1;
    v1 = uDialogueType;
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
        v6 = (char *)pNPCStats->pNPCData2;
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
      if (!pParty_global->pHiredNPCs[0].pNPCName || strcmpi((char *)pParty_global->pHiredNPCs[0].pNPCName, *(const char **)v2))
      {
        if (!pParty_global->pHiredNPCs[1].pNPCName || strcmpi((char *)pParty_global->pHiredNPCs[1].pNPCName, *(const char **)v2))
          goto LABEL_51;
        v14 = 76;
        v12 = 0;
        v11 = &pParty_global->pHiredNPCs[1];
      }
      else
      {
        v14 = 76;
        v12 = 0;
        v11 = &pParty_global->pHiredNPCs[0];
      }
      memset(v11, v12, v14);
LABEL_51:
      pParty_global->byte_000709 = 0;
      sub_44A56A();
      dword_591084 = 0;
    /*  if ( dword_50CBD0[0] < 40 )
      {
        dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
        dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
        dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
      }	*/
	  dword_50CBD0.PutMessageToQueue(113,1,0);
      goto LABEL_89;
    }
    if (pParty_global->pHiredNPCs[0].pNPCName && pParty_global->pHiredNPCs[1].pNPCName)
    {
      v7 = (char *)pGlobalTXT_LocalizationStrings[533];
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
        sub_44C175((char *)pGlobalTXT_LocalizationStrings[155], 2);
        byte_F8B1EC = 0;
        uDialogueType = 13;
        if ( uActiveCharacter )
          Player_PlaySound(pPlayers[uActiveCharacter - 1], 38, 0);
        v7 = (char *)pGlobalTXT_LocalizationStrings[155];
        goto LABEL_64;
      }
      sub_492BB6(v10);
    }
    v2[8] |= 0x80u;
    if (pParty_global->pHiredNPCs[0].pNPCName)
    {
      memcpy(&pParty_global->pHiredNPCs[1], v2, sizeof(struct NPCData));
      v15 = *(const char **)v2;
      v13 = (char *)&unk_AE3090;
    }
    else
    {
      memcpy(&pParty_global->pHiredNPCs[0], v2, sizeof(struct NPCData));
      v15 = *(const char **)v2;
      v13 = byte_AE302C;
    }
    strcpy(v13, v15);
    pParty_global->byte_000709 = 0;
    sub_44A56A();
    /*if ( dword_50CBD0[0] < 40 )
    {
      dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
      dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
      dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
    }  */
	dword_50CBD0.PutMessageToQueue(113,1,0);
    if (uDialogue_SpeakingActorID >= 0)
      pDialogue_SpeakingActor->uAIState = AI::State::Removed;
    if (uActiveCharacter)
      Player_PlaySound(pPlayers[uActiveCharacter - 1], 61, 0);
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
     /* if ( dword_50CBD0[0] < 40 )
      {
        dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
        dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
        dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
      }	 */
	  dword_50CBD0.PutMessageToQueue(113,1,0);
      goto LABEL_87;
    }
    v7 = (char *)pGlobalTXT_LocalizationStrings[140];
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
      v6 = (char *)pNPCStats->pNPCData2;
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
    sub_44103C_Draw();
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
  v0 = ptr_507BC0->dword_00001C - 139;
  v1 = 0;
  do
  {
    v4 = word_591438[26 * ptr_507BC0->dword_00001C];
    if ( v4 < 5 )
      goto LABEL_12;
    if ( v4 <= 13 )
    {
      v2 = rand() % word_4F0F30[v0] + 11 * word_591438[26 * ptr_507BC0->dword_00001C] + 345;
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
      if ( !(unsigned __int16)sub_449B57((unsigned char *)pParty_global->unk_000764 + 1, 239) )
        --v2;
    }
    v7 = (int)ptr_507BC0;
    ItemGen_Reset((ItemGen *)(36 * (v1 + 12 * ptr_507BC0->dword_00001C) + 11341700));
    dword_AD0F84[9 * (v1 + 12 * *(_DWORD *)(v7 + 28))] = v2;
    dword_AD0F98[9 * (v1++ + 12 * *(_DWORD *)(v7 + 28))] = 1;
    result = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( (char *)pClass40->pItems[v2].pIconName, 2)];
    dword_F8B164[v1] = result;
  }
  while ( v1 < 12 );
  return result;
}

//----- (004BCA33) --------------------------------------------------------
int __cdecl sub_4BCA33()
{
  GUIWindowDelete(pDialogueWindow);
  pDialogueWindow = GUIWindowCreate(0, 0, 640, 345, 1, 0, 0);
  dword_5076F4 = GUIButtonCreate(pDialogueWindow,
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
                   uTextureID_right_backgr != -1 ? &LODFile_Icons_LOD.aLODHeaders[uTextureID_right_backgr] : 0);
  return (int)GUIButtonCreate(pDialogueWindow, 8, 8, 450, 320, 1, 0, 81, 0, 0, NULL, 0);
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
  if ( !pDialogueWindow->dword_000028 )
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
      v7 = (int)pPlayers[uActiveCharacter - 1];
      v6 = *(_WORD *)(v7 + 218);
      if ( v6 > 0 )
      {
        do
          v5 += v8++ + 1;
        while ( v8 < v6 );
      }
      if ( v6 < (unsigned __int16)word_4F0866[ptr_507BC0->dword_00001C] )
      {
        v10 = *(_DWORD *)(v7 + 164);
        v9 = 1000 * v5;
        if ( v10 < HIDWORD(v9) || v10 <= HIDWORD(v9) && *(_DWORD *)(v7 + 160) < (_DWORD)v9 )
          return;
      }
    }
    goto LABEL_11;
  }
  v11 = (int)ptr_507BC0;
  if ( (dword_F8B198 == 27 || dword_F8B198 == 28)
    && (v3 = 0,
        *(&byte_4F09B1[32 * (unsigned __int8)*(&byte_4F0CCF[4 * ptr_507BC0->dword_00001C] + v2)]
        + pParty_global->uDaysPlayed % 7u))
    || dword_F8B198 != 23
    || v61 != 10 )
  {
LABEL_11:
    GUIWindowDelete(pDialogueWindow);
    pDialogueWindow = GUIWindowCreate(0, 0, 640, 345, 1, 0, 0);
    dword_5076F4 = GUIButtonCreate(pDialogueWindow,
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
                     uTextureIdx_BtnEsc2  != -1 ?  &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_BtnEsc2] : 0);
    GUIButtonCreate(pDialogueWindow, 8, 8, 450, 320, 1, v3, 81, v3, v3, NULL,  0);
LABEL_12:
    v4 = dword_F8B198;
    v11 = (int)ptr_507BC0;
    goto LABEL_13;
  }
  if ( uActiveCharacter != v3 )
  {
    if ( !Player_sub_4B6FF9(pPlayers[uActiveCharacter - 1]))
      return;
    goto LABEL_12;
  }
LABEL_13:
  dword_F8B19C = v61;
  if ( v4 < 19 )
  {
    v12 = LODFile_Icons_LOD.LODFile_LoadTexture( (&off_4F03B8)[4 * v4], 2);
    v4 = dword_F8B198;
    dword_F8B164[0] = 72 * v12 + 7145548;
LABEL_15:
    v11 = (int)ptr_507BC0;
  }
  if ( v4 > 21 )
  {
    if ( v4 == 22 )
    {
      if ( dword_F8B19C >= 7 )
      {
        if ( dword_F8B19C <= 8 )
          pUserInput->sub_459E5A(1, 10, v11);
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
          v36 = dword_ACCD94[2 * v35 + 1];
          if ( v36 > HIDWORD(pParty_global->qword_00002C)
            || v36 >= HIDWORD(pParty_global->qword_00002C) && (unsigned int)dword_ACCD94[2 * v35] >= (_DWORD)pParty_global->qword_00002C )
          {
            v39 = 0;
            do
            {
              v40 = dword_AD0F84[9 * (v39 + 12 * *(_DWORD *)(v11 + 28))];
              if ( v40 )
              {
                v11 = (int)ptr_507BC0;
                dword_F8B168[v39] = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( (char *)pClass40->pItems[v40].pIconName, 2)];
              }
              ++v39;
            }
            while ( v39 < 12 );
          }
          else
          {
            sub_4BC8D5();
            v37 = ptr_507BC0->dword_00001C;
            v38 = pParty_global->qword_00002C
                + (signed __int64)((double)(11059200 * (signed int)word_591454[26 * ptr_507BC0->dword_00001C])
                                 * 0.03333333507180214);
            dword_ACCD94[2 * v37] = v38;
            dword_ACCD94[2 * v37 + 1] = HIDWORD(v38);
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
          v13 = pParty_global->Abc.array_00003C[2 * v15 + 1];
          if ( v13 > HIDWORD(pParty_global->qword_00002C)
            || v13 >= HIDWORD(pParty_global->qword_00002C) && pParty_global->Abc.array_00003C[2 * v15] >= (_DWORD)pParty_global->qword_00002C )
          {
            v17 = 0;
          }
          else
          {
            v18 = 2 * v15;
            v17 = 0;
            *(__int16 *)((char *)pParty_global->array_00075A + v18) = 0;
            *(_QWORD *)v14 = (signed __int64)((double)(309657600
                                                     * ((unsigned int)pParty_global->uCurrentMonth
                                                      + 12i64 * (unsigned int)pParty_global->uCurrentYear
                                                      - 14015))
                                            * 0.03333333507180214);
            v19 = rand() % 258;
            v20 = (int)ptr_507BC0;
            *(__int16 *)((char *)pParty_global->array_000750 + v18) = v19 + 1;
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
                        v24 = *(__int16 *)((char *)pParty_global->array_000750 + v18);
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
                        *(__int16 *)((char *)pParty_global->array_000750 + v18) = rand() % 258 + 1;
                      }
                    }
                  }
                  else
                  {
                    while ( 1 )
                    {
                      v25 = *(__int16 *)((char *)pParty_global->array_000750 + v18);
                      if ( v25 < 0x73u || v25 > 0x84u )
                      {
                        if ( (v25 < 0xE8 || v25 > 0xF9)
                          && (v25 < 0x85 || v25 > 0x96)
                          && (v25 < 0x97 || v25 > 0xBA)
                          && (v25 < 0xBE || v25 > 0xC0)
                          && (v25 < 0xC4 || v25 > 0xC6)
                          && (v25 < 0x2B || v25 > 0x2D)
                          && (v25 < 0x5E || v25 > 0x60)
                          && (v25 < 0x43 || v25 > 0x45)
                          && (v25 < 0x4F || v25 > 0x51)
                          && (v25 < 0xC1 || v25 > 0xC3)
                          && (v25 < 0x13 || v25 > 0x15)
                          && (v25 < 0xFD || v25 > 0xFF)
                          && (v25 < 0x61 || v25 > 0x63)
                          && (v25 < 0x6A || v25 > 0x6C))
                          break;
                      }
                      *(__int16 *)((char *)pParty_global->array_000750 + v18) = rand() % 258 + 1;
                    }
                  }
                }
                else
                {
                  while ( 1 )
                  {
                    v26 = *(__int16 *)((char *)pParty_global->array_000750 + v18);
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
                    *(__int16 *)((char *)pParty_global->array_000750 + v18) = rand() % 258 + 1;
                  }
                }
              }
              else
              {
                while ( 1 )
                {
                  v27 = *(__int16 *)((char *)pParty_global->array_000750 + v18);
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
                  *(__int16 *)((char *)pParty_global->array_000750 + v18) = rand() % 258 + 1;
                }
              }
            }
            else
            {
              while ( 1 )
              {
                v28 = *(__int16 *)((char *)pParty_global->array_000750 + v18);
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
                *(__int16 *)((char *)pParty_global->array_000750 + v18) = rand() % 258 + 1;
              }
            }
            v15 = v62;
          }
          v30 = 2 * v15;
          v29 = *(__int16 *)((char *)pParty_global->array_000750 + v30);
          v31 = *(__int16 *)((char *)pParty_global->array_00075A + v30) == v17;
          word_F8B1A0 = *(__int16 *)((char *)pParty_global->array_000750 + v30);
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
                Player_sub_44A5CB((char *)&pParty_global->pPlayers[i], 12, 86);

              pParty_global->uNumBountiesCollected += 100 * pMonsterStats->pMonsterInfos[*(unsigned __int16 *)((char *)pParty_global->array_000750 + v30)].uLevel;
              *(__int16 *)((char *)pParty_global->array_000750 + v30) = v17;
              *(__int16 *)((char *)pParty_global->array_00075A + v30) = v17;
            }
            v3 = 0;
            dword_F8B1A4 = dword_72216C;
          }
          goto LABEL_200;
        }
        if ( v61 == 100 )
        {
          pUserInput->sub_459E5A(1, 10, v11);
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
        pDialogueWindow->uWindowType = 1;
        sub_4BCA33();
        sub_4B3703((void *)dword_F8B198);
        break;
      case 101:
        pDialogueWindow->uWindowType = 1;
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
       /* if ( dword_50CBD0[0] < 40 )
        {
          dword_50CBD0[3 * dword_50CBD0[0] + 1] = 29;
          dword_50CBD0[3 * dword_50CBD0[0] + 2] = v3;
          dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = v3;
        }	 */
		dword_50CBD0.PutMessageToQueue(29,0,0);
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
              v42 = (int)pPlayers[uActiveCharacter - 1];
              v43 = (signed __int64)(*((float *)&unk_59145C + 13 * *(_DWORD *)(v11 + 28)) * 500.0);
              v41 = v43 * (100 - Player_sub_4911F3(pPlayers[uActiveCharacter - 1])) / 100;
              if ( v41 < v43 / 3 )
                v41 = v43 / 3;
              if ( *(&byte_4ED94C[37 * *(_BYTE *)(v42 + 185)] + v61) )
              {
                v44 = v42 + 2 * v61 + 192;
                if ( !*(_WORD *)v44 )
                {
                  if ( pParty_global->uNumGold < (unsigned int)v41 )
                  {
                    sub_44C175((char *)pGlobalTXT_LocalizationStrings[155], 2);
                    if ( dword_F8B198 == 30 || dword_F8B198 == 21 )
                      v45 = 4;
                    else
                      v45 = 2;
                    sub_4B1E92(ptr_507BC0->dword_00001C, v45);
                  }
                  else
                  {
                    sub_492BB6(v41);
                    dword_F8B1E4 = 1;
                    *(_WORD *)v44 = 1;
                    Player_PlaySound((Player *)v42, 78, 0);
                  }
                }
              }
            }
            else
            {
              if ( v61 == 94 )
              {
                pDialogueWindow->uWindowType = 1;
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
    sub_421B2C_DropPickedItem();
    return;
  }
  v46 = *(_DWORD *)(v11 + 28);
  v47 = pParty_global->Abc.array_00008C[2 * v46 + 1];
  if ( v47 <= HIDWORD(pParty_global->qword_00002C) )
  {
    if ( v47 < HIDWORD(pParty_global->qword_00002C) || (unsigned int)pParty_global->Abc.array_00008C[2 * v46] < (_DWORD)pParty_global->qword_00002C )
    {
      sub_4B8E3D();
      sub_4B8F94();
      v11 = (int)ptr_507BC0;
      v48 = ptr_507BC0->dword_00001C;
      v4 = dword_F8B198;
      v49 = pParty_global->qword_00002C
          + (signed __int64)((double)(11059200 * (signed int)word_591454[26 * ptr_507BC0->dword_00001C])
                           * 0.03333333507180214);
      pParty_global->Abc.array_00008C[2 * v48] = v49;
      pParty_global->Abc.array_00008C[2 * v48 + 1] = HIDWORD(v49);
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
          v54 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)pClass40->pItems[v53].pIconName, 2);
          v4 = dword_F8B198;
          v11 = (int)ptr_507BC0;
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
            v11 = (int)ptr_507BC0;
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
          v58 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)pClass40->pItems[v57].pIconName, 2);
          v4 = dword_F8B198;
          v11 = (int)ptr_507BC0;
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
            v11 = (int)ptr_507BC0;
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

  if ( dword_50CBD0.msg_count )
			   if  (dword_50CBD0.prm[0].msg_param3)
                          dword_50CBD0.msg_count = 1;
  pUserInput->sub_459ED1(3);
  pUserInput->ResetKeyboard();
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
                cTexture_Free((cTexture *)dword_F8B164[0]);
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
        pVideoPlayer->sub_4BF5B2();
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
            pVideoPlayer->sub_4BF5B2();
LABEL_28:
            dword_F8B19C = 1;
            sub_4B3B42(dword_F8B198);
            return 1;
          }
          pVideoPlayer->sub_4BF5B2();
          sub_4BCA33();
          dword_F8B19C = 101;
          sub_4B3A72((void *)dword_F8B198);
        }
        return 1;
      }
      pVideoPlayer->sub_4BF5B2();
      sub_4BCA33();
      goto LABEL_28;
    }
    dword_5913F0 = 0;
    GUIWindowDelete(pDialogueWindow);
    dword_F8B19C = 0;
    pDialogueWindow = 0;
    LODFile_Icons_LOD.LODFile_sub_40F9C5();
    v1 = dword_591424;
    if ( dword_591424 != 1 )
    {
      v2 = 0;
      dword_5076F4 = ptr_507BC0->pControlsHead;
      if ( dword_591424 > 0 )
      {
        v3 = byte_591180;
        do
        {
          dword_5913F4[v2] = GUIButtonCreate(ptr_507BC0,
                               *(&uDialogueUIIconsOffsetX + v2 + 6 * v1 - 6),
                               *(&uDialogueUIIconsOffsetY + v2 + 6 * v1 - 6),
                               63,
                               73,
                               1,
                               0,
                               410,
                               v2,
                               0,
                               (unsigned char *)v3,
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
  v4 = pClass40->pItems[*(_DWORD *)a1 - 1].uEquipType;
  if ( (v3 != 4 || v5 < 740 || v5 > 771) && (v5 >= 600 || v5 >= 529 && v5 <= 599) || *(_BYTE *)(a1 + 21) & 1 )
    return 0;
  v6 = v3 - 1;
  if ( !v6 )
  {
    compile_error();//v11 = __SETO__(v4, 2);
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
      //if ( byte_5D2A00[v2 + 1] != 38 )
      if (pClass40->pItems[v2].uEquipType != 38)
        return v4 == 16;
      return 1;
    }
    if ( v8 != 1 || v4 < 13 )
      return 0;
    if ( v4 <= 14 )
      return 1;
    if ( v4 != 17 || v5 < 740 )
      return 0;
    compile_error();//v11 = __SETO__(v5, 771);
    v9 = v5 == 771;
    v10 = v5 - 771 < 0;
LABEL_23:
    if ( !((unsigned __int8)(v10 ^ v11) | v9) )
      return 0;
    return 1;
  }
  if ( v4 >= 3 )
  {
    compile_error();//v11 = __SETO__(v4, 9);
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

  v0 = (int)pPlayers[uActiveCharacter - 1];
  v78 = (int)pPlayers[uActiveCharacter - 1];
  if ( dword_4E28F8_PartyCantJumpIfTrue == 14 )
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
      v44 = (signed __int64)(*((float *)&unk_59145C + 13 * ptr_507BC0->dword_00001C) * 500.0);
      v43 = v44 * (100 - Player_sub_4911F3((Player *)v0)) / 100;
      if ( v43 < v44 / 3 )
        v43 = v44 / 3;
      if ( *(&byte_4ED970[37 * *(_BYTE *)(v0 + 185)] + v45) )
      {
        v46 = v0 + 2 * v45 + 264;
        if ( !*(_WORD *)v46 )
        {
          if ( pParty_global->uNumGold < (unsigned int)v43 )
          {
            sub_44C175((char *)pGlobalTXT_LocalizationStrings[155], 2);
            v13 = ptr_507BC0->dword_00001C;
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
    sub_421EA6_OnInventoryLeftClick();
    return;
  }
  if ( dword_F8B19C == 18 )
  {
    v18 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v64);
    v17 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer
                    + 4 * (*(_DWORD *)v18 + dword_5059A8[*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v62) + 4)])) & 0xFFFF;
    if ( !v17 )
      return;
    v20 = ptr_507BC0->dword_00001C;
    v19 = 36 * (v17 + 12 * v20) + 11341664;
    v21 = *((float *)&unk_591458 + 13 * v20);
    v82 = v19;
    v22 = ItemGen_sub_456442((ItemGen *)v19);
    v23 = Player_sub_4B8142((Player *)v0, v22, v21);
    v81 = v23;
    GetAsyncKeyState(VK_CONTROL);
    if ( pParty_global->uNumGold < (unsigned int)v23 )
    {
      v24 = 2;
LABEL_62:
      sub_4B1E92(ptr_507BC0->dword_00001C, v24);
      v8 = (int)pGlobalTXT_LocalizationStrings[155];
      v55 = 2;
      goto LABEL_71;
    }
    v25 = AddItem((Player *)v0, -1, *(_DWORD *)v19);
    if ( v25 )
    {
      v26 = 1;
      *(_DWORD *)(v19 + 20) |= 1u;
      memcpy((void *)(v0 + 36 * v25 + 496), (const void *)v19, 0x24u);
      goto LABEL_42;
    }
    Player_PlaySound((Player *)v0, Character::Voice::NoRoom, 0);
    v55 = 5;
LABEL_70:
    v8 = (int)pGlobalTXT_LocalizationStrings[563];
    goto LABEL_71;
  }
  if ( dword_F8B19C == 2 )
  {
LABEL_49:
    v29 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v60);
    v28 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer
                    + 4 * (*(_DWORD *)v29 + dword_5059A8[*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v58) + 4)])) & 0xFFFF;
    if ( !v28 )
      return;
    v30 = ptr_507BC0->dword_00001C;
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
    v35 = ItemGen_sub_456442((ItemGen *)v32);
    v81 = Player_sub_4B8142((Player *)v0, v35, v34);
    LOWORD(v36) = GetAsyncKeyState(VK_CONTROL);
    v75 = v36;
    v37 = Player_sub_492C40((Player *)v0);
    v79 = 0;
    v77 = 0;
    v74 = v37;

    compile_error(file name should not be global);
    //v33 = CMapStats_FindLocation(pMapStats, CurrentLevelName);
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
          sub_4B1447(ptr_507BC0->dword_00001C, 0, v76);
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
    v39 = AddItem((Player *)v0, -1, *(_DWORD *)v32);
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
            sub_4B1447(ptr_507BC0->dword_00001C, v42, v76);
            goto LABEL_43;
          }
        }
      }
LABEL_42:
      dword_F8B1E4 = v26;
      sub_492BB6(v81);
LABEL_43:
      struct_576FE8.dword_000044 = v26;
      ItemGen_Reset((ItemGen *)v82);
      Render_ClearZBuffer(pD3DRenderer, 0, 479);
      v27 = (void *)v78;
      v54 = 0;
      v52 = 75;
LABEL_81:
      Player_PlaySound((Player *)v27, v52, v54);
      return;
    }
    Player_PlaySound((Player *)v0, Character::Voice::NoRoom, 0);
    v55 = 2;
    goto LABEL_70;
  }
  if ( dword_F8B19C == 3 )
  {
    v14 = *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v72) - 14;
    v80 = (v14 >> 5) + 14 * ((*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v70) + 4) - 17) >> 5);
    if ( *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v68) <= 13
      || *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v66) >= 462
      || (v15 = Player_sub_421E75_GetItemAtInventoryIndex((Player *)v0, &v80), v78 = v15, !v15) )
      return;
    v16 = (int)ptr_507BC0;
    if ( sub_4BDAAF(v0 + 36 * v15 + 496, ptr_507BC0->dword_00001C) )
    {
      dword_F8B1E4 = 1;
      Player_sub_4BE2DD((Player *)v0, v80, v78 - 1, *(_DWORD *)(v16 + 28));
      struct_576FE8.dword_000044 = 1;
      Render_ClearZBuffer(pD3DRenderer, 0, 479);
      v54 = 0;
      v52 = 77;
      goto LABEL_80;
    }
    Player_PlaySound((Player *)v0, 79, 0);
    v57 = 0;
    v53 = 0;
    v51 = 0;
    v50 = 0;
    v49 = -1;
    v48 = 0;
    v47 = 0;
LABEL_87:
    pAudioPlayer->sub_4AA306(27, v47, v48, v49, v50, v51, v53, v57);
    return;
  }
  if ( dword_F8B19C == 4 )
  {
    v10 = *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v63) - 14;
    v80 = (v10 >> 5) + 14 * ((*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v67) + 4) - 17) >> 5);
    if ( *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v59) > 13 )
    {
      if ( *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v65) < 462 )
      {
        v11 = Player_sub_421E75_GetItemAtInventoryIndex((Player *)v0, &v80);
        if ( v11 )
        {
          v81 = Player_sub_4B8179((Player *)v0, *((float *)&unk_591458 + 13 * ptr_507BC0->dword_00001C));
          v12 = v0 + 36 * v11 + 496;
          if ( !(*(_BYTE *)(v12 + 20) & 1) )
          {
            v82 = ptr_507BC0->dword_00001C;
            if ( sub_4BDAAF(v12, v82) )
            {
              if ( pParty_global->uNumGold >= (unsigned int)v81 )
              {
                dword_F8B1E4 = 1;
                sub_492BB6(v81);
                *(_DWORD *)(v12 + 20) |= 1u;
                Player_PlaySound((Player *)v0, 73, 0);
                v8 = (int)pGlobalTXT_LocalizationStrings[569];
                goto LABEL_25;
              }
              goto LABEL_26;
            }
            pAudioPlayer->sub_4AA306(27, 0, 0, -1, 0, 0, 0, 0);
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
      v1 = *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v69) - 14;
      v80 = (v1 >> 5) + 14 * ((*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v71) + 4) - 17) >> 5);
      if ( *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v61) > 13 )
      {
        if ( *(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v73) < 462 )
        {
          v2 = Player_sub_421E75_GetItemAtInventoryIndex((Player *)v0, &v80);
          if ( v2 )
          {
            v3 = v0 + 36 * v2 + 496;
            v4 = *((float *)&unk_591458 + 13 * ptr_507BC0->dword_00001C);
            v5 = ItemGen_sub_456442((ItemGen *)(v0 + 36 * v2 + 496));
            v6 = Player_sub_4B81C3((Player *)v0, v5, v4);
            v7 = (*(_BYTE *)(v3 + 20) & 2) == 0;
            v81 = v6;
            if ( !v7 )
            {
              v82 = ptr_507BC0->dword_00001C;
              if ( sub_4BDAAF(v3, v82) )
              {
                if ( pParty_global->uNumGold >= (unsigned int)v81 )
                {
                  dword_F8B1E4 = 1;
                  sub_492BB6(v81);
                  v9 = *(_DWORD *)(v3 + 20);
                  LOBYTE(v9) = v9 & 0xFD;
                  *(_DWORD *)(v3 + 20) = v9 | 1;
                  Player_PlaySound((Player *)v0, 74, 0);
                  v8 = (int)pGlobalTXT_LocalizationStrings[570];
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
              pAudioPlayer->sub_4AA306(27, 0, 0, -1, 0, 0, 0, 0);
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
void __thiscall Player_sub_4BE2DD(Player *_this, int a2, int a3, int a4)
{
  signed int v4; // ebx@1
  void *v5; // edi@1
  int v6; // esi@1
  float v7; // ST04_4@1
  int v8; // eax@1

  v5 = _this;
  v6 = (int)((char *)_this + 36 * a3);
  v7 = *((float *)&unk_591458 + 13 * a4);
  v8 = ItemGen_sub_456442(&_this->pInventorySlots[a3]);
  v4 = Player_sub_4B8102(_this, v8, v7);
  if ( *(_BYTE *)(v6 + 552) & 2 )
    v4 = 1;
  if ( v4 < 1 )
    v4 = 1;
  Player_sub_492A36_RemoveItemFromIndexMatrix(_this, a2);
  sub_492B70((void *)(pParty_global->uNumGold + v4));
}

//----- (004BE386) --------------------------------------------------------
FILE *__thiscall sub_4BE386(char *text)
{
  FILE *result; // eax@1
  void *v2; // edi@1
  FILE *v3; // esi@1

  result = fopen("errorlog.txt", "a");
  v3 = result;
  if ( result )
  {
    fprintf(result, "%s\n", text);
    fclose(v3);
    result = (FILE *)fflush(v3);
  }
  return result;
}

//----- (004BE485) --------------------------------------------------------
void *__thiscall sub_4BE485(void *_this, void *a2)
{
  unsigned int v2; // eax@3
  signed int v3; // edx@3
  signed int v4; // edi@3
  char v5; // cl@4
  void *result; // eax@24
  int v7; // [sp+Ch] [bp-4h]@3

  dword_F8B5E8 = 0;
  if ( _this && *(_BYTE *)_this )
  {
    v2 = (unsigned int)&unk_F8B1F8;
    v4 = 0;
    v7 = (char *)_this - &unk_F8B1F8;
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
int __thiscall sub_4BE59E(int _this, int a2, int a3)
{
  int result; // eax@1

  result = a2;
  *(_DWORD *)(_this + 40) = a2;
  *(_DWORD *)(_this + 44) = a3 - a2;
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
  v4 = *(double *)(a1 + 24) * 1492.0
     + *(double *)(a1 + 16) * 1776.0
     + *(double *)(a1 + 24) * 2111111111.0
     + v3 * 5115.0
     + *(double *)(a1 + 32);
  floor(v4);
  *(double *)v2 = v4 - v4;
  *(double *)(v2 + 32) = v4 * (1.0 / (double)0xFFFFFFFF);
  return v4 - v4;
}

//----- (004BE623) --------------------------------------------------------
int __thiscall sub_4BE623(int _this)
{
  int v1; // ecx@1
  int v2; // esi@1
  float v3; // ST10_4@1
  double v4; // ST04_8@1

  v2 = _this;
  v3 = sub_4BE5B1(_this) * (double)*(signed int *)(_this + 44);
  v4 = v3 + 6.755399441055744e15;
  v1 = LODWORD(v4);
  if (LODWORD(v4) >= *(_DWORD *)(v2 + 44) )
    v1 = *(_DWORD *)(v2 + 44);
  return v1 + *(_DWORD *)(v2 + 40);
}

//----- (004BE65D) --------------------------------------------------------
void __thiscall sub_4BE65D(void *_this, int a2)
{
  int v2; // eax@1
  int v3; // esi@1
  signed int v4; // ecx@3
  unsigned int v5; // eax@4
  signed int v6; // edi@5

  v2 = a2;
  v3 = (int)_this;
  if ( !a2 )
    v2 = -1;
  v4 = 0;
  do
  {
    v5 = (((v2 << 13) ^ (unsigned int)v2) >> 17) ^ (v2 << 13) ^ v2;
    v2 = 32 * v5 ^ v5;
    *(double *)(v3 + 8 * v4++) = (double)(unsigned int)v2 * (1.0 / (double)0xFFFFFFFF);
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
void *__thiscall sub_4BE6D1(void *_this)
{
  return _this;
}

//----- (004BF91E) --------------------------------------------------------
int __thiscall sub_4BF91E_GameOverMenu(void *_this)
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
  cPCXTexture v16; // [sp+Ch] [bp-C4h]@1
  //unsigned int v17; // [sp+30h] [bp-A0h]@1

  GUI::Window local_34;
  //int v18; // [sp+34h] [bp-9Ch]@1
  //int v19; // [sp+38h] [bp-98h]@1
  //int v20; // [sp+3Ch] [bp-94h]@1
  //int v21; // [sp+40h] [bp-90h]@1
  //int v22; // [sp+44h] [bp-8Ch]@1
  //int v23; // [sp+48h] [bp-88h]@1

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

  v26 = _this;
 
  v16.PCXTexture_Zero();
  BYTE1(dword_6BE364) &= 0xBFu;
  dword_F8BC10 = 1;

  pAudioPlayer->MessWithChannels(&Range<unsigned int>(0, 16));;
  pD3DRenderer->BeginScene();
  Render_sub_49ECC4((int)pD3DRenderer);
  pD3DRenderer->EndScene();
  pD3DRenderer->Present();

  sub_449B57((unsigned char *)pParty_global->unk_000764 + 1, 99);

  v16.LODPCXLoad("winbg.pcx", 2);
  pD3DRenderer->BeginScene();
  Render_DrawRGBTexture(pD3DRenderer, 0, 0, &v16);

  v1 = (int)pD3DRenderer->EndScene();
  MemFree(v16.pPixels);
  v16.pPixels=NULL;
  //free((char *)v17);
  //v17 = 0;
  ptr_507BC0 = GUIWindowCreate(0, 0, 640, 480, 1, 0, 0);
  local_34.uFrameX = 75;
  local_34.uFrameY = 60;
  local_34.uFrameWidth = 469;
  local_34.uFrameHeight = 338;
  local_34.uFrameZ = 543;
  local_34.uFrameW = 397;
  v33 = (int)LoadFont("endgame.fnt", "FONTPAL");
  if ( (unsigned __int16)sub_449B57((unsigned char *)pParty_global->unk_000764 + 1, 99) )
  {
    v2 = (int)pGlobalTXT_LocalizationStrings[675];
  }
  else
  {
    result = sub_449B57((unsigned char *)pParty_global->unk_000764 + 1, 100);
    if ( !(_WORD)result )
      return result;
    v2 = (int)pGlobalTXT_LocalizationStrings[676];
  }
  v27 = (const char *)v2;
  v34 = pParty_global->qword_00002C - 138240;
  v30 = (unsigned int)((signed __int64)((double)(pParty_global->qword_00002C - 138240) * 0.234375) / 60 / 60) / 0x18;
  v25 = v30 / 0x1C / 0xC;
  v29 = v30 / 0x1C % 0xC;
  v28 = v30 % 0x1C;
  if ( !v30 )
    v30 = 1;
  pD3DRenderer->BeginScene();
  GUIWindow_DrawText(&local_34, (Font *)v33, 1, 35, 1u, (char *)pGlobalTXT_LocalizationStrings[9], 3);
  v4 = (int)pParty_global->pPlayers[0].sName;
  v34 = 0i64;
  v31 = 0;
  for ( i = (int)pParty_global->pPlayers[0].sName; ; v4 = i )
  {
    v5 = (char *)aClassNames[*(_BYTE *)(v4 + 17)];

    v6 = Player_GetBaseLevel((Player *)(v4 - 168));
    wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[129], i, v6, v5);
    GUIWindow_DrawText(&local_34, (Font *)v33, 1, v31 * (*(_BYTE *)(v33 + 5) - 2) + *(_BYTE *)(v33 + 5) + 46, 1u, (char *)TmpBuf, 3);
    v7 = *(_DWORD *)(i - 8);
    v8 = v7 >= -(_DWORD)v34;
    LODWORD(v34) = v7 + v34;
    HIDWORD(v34) += *(_DWORD *)(i - 4) + v8;
    ++v31;
    compile_error();//v10 = __SETO__(i + 6972, &unk_AD471C);
    compile_error();//v9 = i + 6972 - (_DWORD)&unk_AD471C < 0;
    //phail
    i += 6972;
    if ( !(v9 ^ v10) )
      break;
  }
  v34 /= (signed __int64)v30;

  unsigned char pOutString[2048];
  v12 = (char *)FitTextInAWindow((unsigned char *)v27, pOutString, (Font *)v33, &local_34, 12, 0);
  GUIWindow_DrawText(&local_34, (Font *)v33, 1, 5 * (*(_BYTE *)(v33 + 5) + 11), 1u, v12, 0);
  strcpy((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[37]);
  v11 = (int)pGlobalTXT_LocalizationStrings[56];
  if ( v28 != 1 )
    v11 = (int)pGlobalTXT_LocalizationStrings[57];
  v13 = (int)pGlobalTXT_LocalizationStrings[146];
  if ( v29 != 1 )
    v13 = (int)pGlobalTXT_LocalizationStrings[148];
  v14 = (int)pGlobalTXT_LocalizationStrings[245];
  if ( v25 != 1 )
    v14 = (int)pGlobalTXT_LocalizationStrings[132];
  wsprintfA((char *)pStringBuffer, " %lu %s, %lu %s, %lu %s ", v25, v14, v29, v13, v28, v11);
  strcat((char *)TmpBuf, (char *)pStringBuffer);
  GUIWindow_DrawText(&local_34, (Font *)v33, 1, local_34.uFrameHeight - 2 * *(_BYTE *)(v33 + 5) - 5, 1u, (char *)TmpBuf, 3);
  wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[94], v34);
  GUIWindow_DrawText(&local_34, (Font *)v33, 1, local_34.uFrameHeight, 1u, (char *)TmpBuf, 3);
  BYTE1(dword_6BE364) |= 0x40u;
  pD3DRenderer->EndScene();
  pD3DRenderer->Present();
  if ( pD3DRenderer->pRenderD3D3 )
    dword_EF52A8();
  Render_sub_49F1BC((int)pD3DRenderer, "MM7_Win.Pcx");

  //MemFree( (void *)(int *)v33);
  MemFree((void *)v33);

  GUIWindowDelete(ptr_507BC0);
  ptr_507BC0 = 0;
  if ( v26 == (void *)2 )
  {
    result = dword_50CBD0.msg_count;
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
        Game_DeinitializeAndTerminate(0);
      TranslateMessage(&Msg);
      DispatchMessageA(&Msg);
    }
    if ( dword_50CBD0.msg_count )
			   if  (dword_50CBD0.prm[0].msg_param3)
                          dword_50CBD0.msg_count = 1;
    pUserInput->ResetKeyboard();
    do
    {
      while ( PeekMessageA(&Msg, 0, 0, 0, 1u) )
      {
        if ( Msg.message == 18 )
          Game_DeinitializeAndTerminate(0);
        TranslateMessage(&Msg);
        DispatchMessageA(&Msg);
      }
    }
    while ( !pUserInput->uLastKeyPressed );
  /*  result = dword_50CBD0[0];
    if ( dword_50CBD0[0] )
    {
      result = dword_50CBD0[3] != 0;
      dword_50CBD0[0] = dword_50CBD0[3] != 0;
    } */
	dword_50CBD0.CutQueueTail();
  }
  if ( v26 )
  {
  /*  if ( result < 40 )
    {
      dword_50CBD0[3 * result + 1] = 132;
      goto LABEL_42;
    } */
	dword_50CBD0.PutMessageToQueue(132,1,0);
  }
  else
  {
  /*  if ( result < 40 )
    {
      dword_50CBD0[3 * result + 1] = 197;
LABEL_42:
      dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
      result = 3 * dword_50CBD0[0] + 3;
      dword_50CBD0[result] = 0;
      ++dword_50CBD0[0];*/

    //  goto LABEL_43;
   // }
	 dword_50CBD0.PutMessageToQueue(197,1,0);
  }
//LABEL_43:
  dword_F8BC10 = 0;
  return result;
}



//----- (004C1607) --------------------------------------------------------
bool IsPointInsideD3DBillboard(struct RenderBillboardD3D3 *pBillboard, float fX, float fY)
{
  double v4; // st7@2
  float v5; // ST00_4@3
  float v7; // [sp+4h] [bp-8h]@2
  float v8; // [sp+8h] [bp-4h]@2
  float v9; // [sp+14h] [bp+8h]@2

 if (pBillboard->uParentBillboardID == -1 )
   return false;

 v4 = pBillboard->pQuad[0].x;
 v8 = pBillboard->pQuad[0].y;
 v7 = pBillboard->pQuad[1].y;
 v9 = pBillboard->pQuad[3].x;

  if ( v4 > v9 )
  {
    v5 = v4;
    v4 = v9;
    v9 = v5;
  }
  if ( v8 > (double)v7 )
  {
    v7 = v8;
    v8 = pBillboard->pQuad[1].y;
  }

 if (fX + 1.0 < v4 || fX - 1.0 > v9 ||
     fY + 1.0 < v8 || fY - 1.0 > v7)
   return false;
 else return true;
}


//----- (004C1D2B) --------------------------------------------------------
int __stdcall sub_4C1D2B(BLVFace *a1, Vec3<short> a2, unsigned int uModelID)
{
  int v4; // esi@1
  bool v5; // edi@9
  int v7; // edx@11
  int v9; // eax@12
  signed int v10; // ebx@13
  int v11; // edi@15
  signed int v12; // ST28_4@17
  signed __int64 v13; // qtt@17
  signed int result; // eax@20
  signed int v16; // [sp+18h] [bp-4h]@9

  v4 = (int)a1;

 if (a2.x < a1->cBoundingBoxX.min || a2.x > a1->cBoundingBoxX.max ||
     a2.y < a1->cBoundingBoxY.min || a2.y > a1->cBoundingBoxY.max ||
     a2.z < a1->cBoundingBoxZ.min || a2.z > a1->cBoundingBoxZ.max)
   return false;

 if (!a1->uNumVertices)
   return false;

 int intersect_a, intersect_b;
 if (uModelID == -1)
   sub_4C1EE5_IntersectBModel(&intersect_a, &intersect_b,
                              word_F8BC48_displaced_face_intersect_plane_coords_a, word_F8BD18_displaced_face_intersect_plane_coords_b, &a2, a1);
 else
   sub_4C2186_IntersectBModel(&intersect_a, &intersect_b,
                              word_F8BC48_displaced_face_intersect_plane_coords_a, word_F8BD18_displaced_face_intersect_plane_coords_b, &a2, a1, uModelID);

  v16 = 0;
  word_F8BC48_displaced_face_intersect_plane_coords_a[a1->uNumVertices] = word_F8BC48_displaced_face_intersect_plane_coords_a[0];
  word_F8BD18_displaced_face_intersect_plane_coords_b[a1->uNumVertices] = word_F8BD18_displaced_face_intersect_plane_coords_b[0];
  v5 = word_F8BD18_displaced_face_intersect_plane_coords_b[0] >= intersect_b;

 for (unsigned int i = 0; i < a1->uNumVertices; ++i)
 {
    if ( v16 >= 2 )
      break;

    v7 = word_F8BD18_displaced_face_intersect_plane_coords_b[i + 1];
    if ( v5 ^ v7 >= intersect_b )
    {
      v9 = word_F8BC48_displaced_face_intersect_plane_coords_a[i + 2];
      if ( v9 >= intersect_a )
        v10 = 0;
      else
        v10 = 2;
      v11 = v10 | word_F8BC48_displaced_face_intersect_plane_coords_a[i] < intersect_a;
      if ( v11 != 3 )
      {
       v12 = v9 - word_F8BC48_displaced_face_intersect_plane_coords_a[i];
       LODWORD(v13) = v12 << 16;
       HIDWORD(v13) = v12 >> 16;

       int local_1 = ((intersect_b - (signed int)word_F8BD18_displaced_face_intersect_plane_coords_b[i]) << 16);
       int local_2 = (v7 - word_F8BD18_displaced_face_intersect_plane_coords_b[i]);

       int local_3 = word_F8BC48_displaced_face_intersect_plane_coords_a[i] + ((signed int)(((unsigned __int64)(v13 / local_2 * local_1) >> 16) + 0x8000) >> 16);

        if (!v11 || local_3 >= intersect_a)
          ++v16;
      }
    }
    v5 = v7 >= intersect_b;
  }

  result = 1;
  if ( v16 != 1 )
LABEL_24:
    result = 0;
  return result;
}

//----- (004C2551) --------------------------------------------------------
int __thiscall sub_4C2551(int _this, int a2, int a3)
{
  int v3; // edx@1
  int v4; // esi@1
  int v5; // eax@2
  int result; // eax@6

  v4 = *(_DWORD *)(_this + 8196);
  v3 = 0;
  if ( v4 <= 0 )
  {
LABEL_6:
    result = 0;
  }
  else
  {
    v5 = _this + 8;
    while ( *(_DWORD *)(v5 + 4) != a2 || (*(_DWORD *)v5 & 0xFFFF) != a3 )
    {
      ++v3;
      v5 += 12;
      if ( v3 >= v4 )
        goto LABEL_6;
    }
    result = _this + 12 * v3 + 4;
  }
  return result;
}

//----- (004C2591) --------------------------------------------------------
void class25_create_object_pointers(struct class25 *_this, int a2)
{
 int v0;
  int v4; // edx@3
  char v11; // [sp-18h] [bp-28h]@19
  int v12; // [sp-14h] [bp-24h]@19
  int v13; // [sp-10h] [bp-20h]@19
  int v14; // [sp-Ch] [bp-1Ch]@19
  char v17; // [sp+Ch] [bp-4h]@19
  char *v18; // [sp+18h] [bp+8h]@19
 int i, j;

  if (!a2)
  {
   for (i = 0; i < _this->uNumPointers; ++i)
     _this->array_001804[i] = &_this->array_000004[i];
  }
  else if (a2 == 1)
  {
   v0 = 1;
      
   for (i = 0; i < _this->uNumPointers; ++i)
   {
       for (j = 0; j < i; ++j)
         if (_this->array_001804[j] == &_this->array_000004[i])
         {
             v0 = 0;
             break;
         }

       if (v0)
         _this->array_001804[i] = &_this->array_000004[i];
   }
  }
  else
  {
      v18 = &v11;
      Game_sub_40E2C8(&v11, "Unknown pointer creation flag passed to ::create_object_pointers()", (int)((char *)&a2 + 3));
      sub_466D09(&v17, *(int *)&v11, v12, v13, v14, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Vis.cpp", __LINE__);
  }
}

//----- (004C264A) --------------------------------------------------------
void class25_sort_object_pointers(struct class25_stru0 **pPointers, int sLeft, int sRight)
{
  int v4; // edx@1
  int v5; // ebx@1
  signed int i; // ecx@2
  int v7; // esi@2
  unsigned int v8; // eax@3
  unsigned int v9; // ebx@4
  unsigned int v10; // ebx@6
  int v11; // eax@7
 struct class25_stru0 *v12; // [sp+14h] [bp+Ch]@2

  v4 = sLeft;
  v5 = sRight;
  if (sRight <= sLeft)
    return;

    do
    {
      v7 = v4 - 1;
      v12 = pPointers[v5];
      for ( i = v5; ; pPointers[i] = (class25_stru0 *)v11 )
      {
        v8 = v12->sZValue;
        LOWORD(v8) = 0;

        do
        {
          ++v7;
          v9 = pPointers[v7]->sZValue;
          LOWORD(v9) = 0;
        }
        while ( v9 < v8 );

        do
        {
          if ( i < 1 )
            break;
          --i;
          v10 = pPointers[i]->sZValue;
          LOWORD(v10) = 0;
        }
        while ( v10 > v8 );

        v11 = (int)pPointers[v7];
        if ( v7 >= i )
          break;
        pPointers[v7] = pPointers[i];
      }

      v5 = sRight;
      pPointers[v7] = pPointers[sRight];
      pPointers[sRight] = (class25_stru0 *)v11;

      class25_sort_object_pointers(pPointers, v4, v7 - 1);
      v4 = v7 + 1;
    }
    while (sRight > v7 + 1 );
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

  v10 = (int)_this;
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
void operator_delete(void *a2)
{
  MemFree(a2);
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
  Game_stru0_sub_40E2F6((Game_stru0 *)&v2, 0);
  v0 = strlen((char *)&byte_4D8410[11380]);
  sub_40E32E((int)&v2, &byte_4D8410[11380], v0);
  v4 = 0;
  sub_4CA392(&v1, (int)&v2);
  v1 = 5091448;
  _CxxThrowException((int)&v1, 5096840);
}

//----- (004CA392) --------------------------------------------------------
void *__thiscall sub_4CA392(void *_this, int a2)
{
  void *v3; // esi@1
  int v4; // [sp+4h] [bp-10h]@1
  int v5; // [sp+10h] [bp-4h]@1

  v3 = _this;
  v4 = (int)"";
  exception__exception((int)&v4);
  v5 = 0;
  *((_BYTE *)v3 + 12) = *(_BYTE *)a2;
  Game_stru0_sub_40E2F6((Game_stru0 *)((char *)v3 + 12), 0);
  sub_4679E2((int)((char *)v3 + 12), a2, 0, *(size_t *)&byte_4D8410[11412]);
  *(_DWORD *)v3 = 5091480;
  return v3;
}

//----- (004CA479) --------------------------------------------------------
void *__thiscall sub_4CA479(void *_this, int a2)
{
  void *v3; // esi@1

  v3 = _this;
  exception__exception(a2);
  *((_BYTE *)v3 + 12) = *(_BYTE *)(a2 + 12);
  Game_stru0_sub_40E2F6((Game_stru0 *)((char *)v3 + 12), 0);
  sub_4679E2((int)((char *)v3 + 12), a2 + 12, 0, *(size_t *)&byte_4D8410[11412]);
  *(_DWORD *)v3 = 5091480;
  return v3;
}

//----- (004CA54C) --------------------------------------------------------
void *__thiscall sub_4CA54C(void *_this, int a2)
{
  void *v3; // esi@1

  v3 = _this;
  sub_4CA479(_this, a2);
  *(_DWORD *)v3 = 5091448;
  return v3;
}