#include "_audio.h"
#include "_video.h"
#include "AIL.h"

#include <stdio.h>

#include "classes.h"

#include "data.h"

extern char off_4E7ECC[];
extern int dword_4E800C;
extern float flt_6BE3A0;
extern int dword_AD4730;
extern int dword_E31C7C;
extern char byte_6BE371;
extern int dword_4F00DC;
extern char unk_F79CC8[];
extern char byte_F79448[];

extern char unk_4EB8BC;
extern char unk_4EBBD0;
extern char byte_6BE36F;

extern int dword_4F00E4;
extern short word_F1B4C4;
extern int dword_4F00E4;
extern int dword_4F00E0;
extern short word_F1B4C6;
extern int dword_4F00E0;
extern int dword_4F00E4;
extern int dword_4F00E0;

extern char byte_4D8410[];

extern int *dword_4F2688;

extern int dword_51B6E8;
extern int dword_51B6EC;
extern int dword_51B6F0;

extern int dword_6A0CA4;

extern int dword_720010;

extern int dword_720018;

extern int dword_E31C70;

extern int dword_F792F0;

extern int dword_F79D70;
extern int dword_F79D7C;
extern struct CSoundList *pSoundList;




extern int (__cdecl *sprintfex)(char *, const char *, ...);
void class31_ctor(struct class31 *_this)
{
 char pCurrentDirectory[256];
 char pIniFile[256];

 memset(_this, 0, sizeof(struct class31));

 _this->cGameCDDriveLetter = cGameCDDriveLetter;

 _getcwd(pCurrentDirectory, 120);
 (sprintfex)(pIniFile, "%s\\mm6.ini", pCurrentDirectory);

 _this->iMixerChannels = GetPrivateProfileIntA("settings", "mixerchannels", 16, pIniFile);
 if (_this->iMixerChannels <= 16)
 {
  if (_this->iMixerChannels < 0)
    _this->iMixerChannels = 0;
 }
 else _this->iMixerChannels = 16;
}


//----- (004AA306) --------------------------------------------------------
extern int dword_6BE360;
extern int dword_ACCFC4;
extern int dword_F1B4D4;
extern char unk_665230;
extern char unk_5FF158;
extern char *Src;
extern short word_6836D0[];
extern struct Party *pParty_global;
int __fastcall sub_4621DA(signed int a1, signed int a2, signed int a3);
void __stdcall sub_436523(int a1, int a2);
int __fastcall sub_4AAEA6(int a1);
int __fastcall sub_4AB6B1(int a1, int a2, int a3);
int __fastcall sub_4AB66C(int a1, int a2);
void class31_sub_4AA306(struct class31 *_this, int a2, signed int a3, int a4, signed int a5, int a6, int a7, int a8, int a9)
{
  int v9; // esi@1
  char v10; // zf@1
  int v11; // edx@5
  int v12; // ecx@6
  int v13; // edi@13
  signed int v14; // ecx@17
  signed int v15; // eax@20
  int v16; // eax@24
  signed int v17; // eax@25
  char *v18; // eax@28
  signed int v19; // eax@29
  double v20; // st7@32
  char *v21; // eax@32
  signed int v22; // ecx@32
  signed int v23; // ecx@33
  int v24; // esi@53
  int v25; // esi@61
  int v26; // esi@67
  double v27; // st7@68
  int v28; // ST18_4@68
  int v29; // ebx@68
  int v30; // eax@68
  int v31; // ecx@69
  int v32; // esi@69
  char v33; // zf@70
  int v34; // eax@70
  int v35; // ST18_4@70
  int v36; // ebx@70
  int v37; // eax@70
  signed int v38; // ebx@74
  int v39; // edi@79
  int v40; // esi@79
  int v41; // ebx@80
  int v42; // edi@82
  int v43; // esi@82
  double v44; // st7@91
  char *v45; // eax@92
  double v46; // st7@93
  char *v47; // eax@93
  signed int v48; // ecx@93
  char *v49; // eax@97
  double v50; // st7@104
  int v51; // ST18_4@104
  int v52; // ebx@104
  int v53; // eax@104
  float v54; // ST0C_4@106
  float v55; // ST04_4@106
  int v56; // edx@106
  char *v57; // eax@114
  int v58; // edx@115
  int v59; // ecx@115
  char *v60; // eax@118
  int v61; // esi@126
  int v62; // ebx@133
  signed int v63; // esi@133
  int v64; // edi@134
  int v65; // ebx@141
  int v66; // ecx@142
  int v67; // edi@142
  int v68; // eax@143
  int v69; // edi@149
  int v70; // eax@153
  int v71; // edi@156
  int v72; // eax@157
  int v73; // esi@157
  int v74; // ebx@159
  signed int v75; // ebx@160
  char *v76; // edi@164
  int v77; // edx@166
  int v78; // ecx@166
  int v79; // eax@167
  char *v80; // edi@168
  char *v81; // edi@173
  int v82; // eax@183
  int v83; // eax@183
  int v84; // ST18_4@186
  int v85; // [sp+14h] [bp-60h]@84
  int v86; // [sp+14h] [bp-60h]@115
  float v87; // [sp+24h] [bp-50h]@32
  float v88; // [sp+28h] [bp-4Ch]@32
  float v89; // [sp+2Ch] [bp-48h]@47
  float v90; // [sp+30h] [bp-44h]@68
  float v91; // [sp+34h] [bp-40h]@68
  float v92; // [sp+50h] [bp-24h]@1
  int v93; // [sp+54h] [bp-20h]@12
  int v94; // [sp+58h] [bp-1Ch]@68
  int v95; // [sp+5Ch] [bp-18h]@68
  int v96; // [sp+60h] [bp-14h]@10
  float v97; // [sp+64h] [bp-10h]@1
  signed int v98; // [sp+68h] [bp-Ch]@68
  int v99; // [sp+6Ch] [bp-8h]@1
  int v100; // [sp+70h] [bp-4h]@19
  signed int v101; // [sp+84h] [bp+10h]@93
  float v102; // [sp+84h] [bp+10h]@104
  float v103; // [sp+8Ch] [bp+18h]@104
  signed int v104; // [sp+90h] [bp+1Ch]@32
  int v105; // [sp+90h] [bp+1Ch]@52
  int v106; // [sp+90h] [bp+1Ch]@60
  int v107; // [sp+90h] [bp+1Ch]@68

  runtime_warning;
  return;

  v9 = _this;
  v10 = _this->dword_00029C == 0;
  v99 = _this;
  v92 = 0.0;
  LODWORD(v97) = 10000;
  if ( v10 || !byte_6BE36F || !_this->hDigDriver || !a2 )
    return;
  v11 = 0;
  if ( pSoundList->uNumSounds <= 0 )
  {
LABEL_9:
    v11 = 0;
  }
  else
  {
    v12 = (char *)pSoundList->pDescriptions + 32;
    while ( *(_DWORD *)v12 != a2 )
    {
      ++v11;
      v12 += 120;
      if ( v11 >= pSoundList->uNumSounds )
        goto LABEL_9;
    }
  }
  v96 = v11;
  if ( !v11 )
    return;
  if ( !*(_DWORD *)(v9 + 4) || (v93 = 120 * v11, !(*(_BYTE *)(120 * v11 + pSoundList->pDescriptions + 40) & 2)) )
  {
    if ( a3 < 0 )
    {
      if ( a3 == -1 )
      {
        v98 = 13;
        v100 = 13;
        goto LABEL_133;
      }
      v98 = 14;
      v100 = 14;
LABEL_123:
      if ( a3 )
      {
        if ( a3 != -1 )
        {
          v95 = 0;
          if ( *(_DWORD *)(v99 + 1000) > 0 )
          {
            v61 = v99 + 744;
            do
            {
              if ( AIL_sample_status(*(_DWORD *)v61) == 4
                && *(_DWORD *)(v61 + 4) == a3
                && AIL_sample_status(*(_DWORD *)v61) == 4 )
              {
                if ( *(_DWORD *)(v61 + 8) == v96 )
                  return;
                AIL_end_sample(*(_DWORD *)v61);
                sub_4ABE55(v99, v61);
              }
              ++v95;
              v61 += 16;
            }
            while ( v95 < *(_DWORD *)(v99 + 1000) );
          }
        }
      }
LABEL_133:
      v63 = v98;
      v62 = v99;
      if ( v98 <= v100 )
      {
        v64 = 16 * v98 + v99 + 744;
        while ( AIL_sample_status(*(_DWORD *)v64) != 2 )
        {
          ++v63;
          v64 += 16;
          if ( v63 > v100 )
            goto LABEL_140;
        }
        AIL_end_sample(*(_DWORD *)v64);
        if ( *(_DWORD *)(v64 + 8) )
          sub_4ABE55(v99, v64);
      }
LABEL_140:
      if ( v63 != v100 + 1 )
      {
LABEL_150:
        if ( LODWORD(v97) == 10000 )
          LODWORD(v97) = *(_DWORD *)(v62 + 708);
        if ( !a7 )
        {
          v70 = pSoundList->pDescriptions + 120 * v96;
          if ( !*(_DWORD *)(v70 + 44) )
          {
            if ( *(_DWORD *)(v70 + 36) == 2 )
              sub_4A9A67(pSoundList, a2, 0);
          }
        }
        v71 = 4 * (a7 + 30 * v96) + 44;
        if ( !*(_DWORD *)(v71 + pSoundList->pDescriptions) )
          return;
        v73 = 16 * v63 + v62 + 744;
        AIL_init_sample(*(_DWORD *)v73);
        AIL_set_sample_file(*(_DWORD *)v73, *(_DWORD *)(v71 + pSoundList->pDescriptions) + 4 * (a7 == 0), -1);
        v72 = a8;
        if ( !a8 )
          v72 = LODWORD(v97);
        AIL_set_sample_volume(*(_DWORD *)v73, v72);
        v74 = a5;
        if ( a5 != -1 )
        {
          if ( !a5 )
            v74 = pParty_global->dword_0006B4;
          if ( !a6 )
            a6 = pParty_global->dword_0006B8;
          if ( a4 )
            AIL_set_sample_loop_count(*(_DWORD *)v73, a4 - 1);
          v82 = sub_4AB66C(v74, a6);
          AIL_set_sample_pan(*(_DWORD *)v73, v82);
          v83 = sub_4AB6B1(v74, a6, pParty_global->dword_0006BC);
          AIL_set_sample_volume(*(_DWORD *)v73, v83);
          v75 = a3;
          goto LABEL_184;
        }
        v75 = a3;
        if ( (a3 & 7) == 1 )
        {
          if ( dword_6BE360 != 1 )
            goto LABEL_184;
          v81 = (char *)Src + 80 * (a3 >> 3);
          if ( !*((_DWORD *)v81 + 1) )
            return;
          if ( !sub_4AB6B1(**((_WORD **)v81 + 14), **((_WORD **)v81 + 15), **((_WORD **)v81 + 16)) )
          {
            AIL_end_sample(*(_DWORD *)v73);
            sub_4ABE55(v99, v73);
            return;
          }
          v77 = **((_WORD **)v81 + 15);
          v78 = **((_WORD **)v81 + 14);
          goto LABEL_167;
        }
        if ( (a3 & 7) == 2 )
        {
          v76 = (char *)&unk_665230 + 112 * (a3 >> 3);
          if ( !sub_4AB6B1(*((_DWORD *)v76 + 1), *((_DWORD *)v76 + 2), *((_DWORD *)v76 + 3)) )
            return;
        }
        else
        {
          if ( (a3 & 7) == 3 )
          {
            v80 = (char *)&unk_5FF158 + 836 * (a3 >> 3);
            if ( !sub_4AB6B1(*((_WORD *)v80 + 71), *((_WORD *)v80 + 72), *((_WORD *)v80 + 73)) )
              return;
            v77 = *((_WORD *)v80 + 72);
            v78 = *((_WORD *)v80 + 71);
            goto LABEL_167;
          }
          if ( (a3 & 7) != 5 )
          {
LABEL_184:
            if ( a4 )
              AIL_set_sample_loop_count(*(_DWORD *)v73, a4 - 1);
            v84 = *(_DWORD *)v73;
            *(_DWORD *)(v73 + 8) = v96;
            *(_DWORD *)(v73 + 4) = v75;
            *(_DWORD *)(v73 + 12) = a2;
            AIL_start_sample(v84);
            if ( a9 )
              AIL_set_sample_playback_rate(*(_DWORD *)v73, a9);
            if ( (v75 & 7) == 4 )
              AIL_sample_ms_position(*(_DWORD *)v73, &dword_F1B4D4, 0);
            return;
          }
          v76 = (char *)&word_6836D0[16 * (a3 >> 3)];
          if ( !sub_4AB6B1(*((_DWORD *)v76 + 1), *((_DWORD *)v76 + 2), *((_DWORD *)v76 + 3)) )
            return;
          AIL_set_sample_loop_count(*(_DWORD *)v73, a4 - 1);
        }
        v77 = *((_DWORD *)v76 + 2);
        v78 = *((_DWORD *)v76 + 1);
LABEL_167:
        v79 = sub_4AB66C(v78, v77);
        AIL_set_sample_pan(*(_DWORD *)v73, v79);
        goto LABEL_184;
      }
      v65 = v98;
      v63 = -1;
      v95 = LODWORD(v97);
      if ( v98 <= v100 )
      {
        v66 = v99;
        v67 = 16 * v98 + v99 + 744;
        do
        {
          v68 = AIL_sample_volume(v66, *(_DWORD *)v67);
          if ( v68 < v95 )
          {
            v95 = v68;
            v63 = v65;
          }
          ++v65;
          v67 += 16;
        }
        while ( v65 <= v100 );
        if ( v63 != -1 )
        {
LABEL_149:
          v62 = v99;
          v69 = 16 * v63 + v99 + 744;
          AIL_end_sample(*(_DWORD *)v69);
          sub_4ABE55(v99, v69);
          goto LABEL_150;
        }
        v65 = v98;
      }
      v63 = 13;
      if ( v65 != 13 )
        return;
      goto LABEL_149;
    }
    if ( (a3 & 7) == 2 )
    {
      v98 = 5;
      v100 = 7;
      v57 = (char *)&unk_665230 + 112 * (a3 >> 3);
    }
    else
    {
      if ( (a3 & 7) == 3 )
      {
        v98 = 0;
        v60 = (char *)&unk_5FF158 + 836 * (a3 >> 3);
        v100 = 3;
        v58 = *((_WORD *)v60 + 72);
        v86 = *((_WORD *)v60 + 73);
        v59 = *((_WORD *)v60 + 71);
LABEL_116:
        LODWORD(v97) = sub_4AB6B1(v59, v58, v86);
        if ( !LODWORD(v97) )
          return;
        goto LABEL_123;
      }
      if ( (a3 & 7) != 5 )
      {
        if ( (a3 & 7) == 6 )
        {
          v98 = 8;
          v100 = 9;
        }
        else
        {
          v98 = 10;
          v100 = 12;
        }
        goto LABEL_123;
      }
      v98 = 4;
      v100 = 4;
      v57 = (char *)&word_6836D0[16 * (a3 >> 3)];
    }
    v86 = *((_DWORD *)v57 + 3);
    v58 = *((_DWORD *)v57 + 2);
    v59 = *((_DWORD *)v57 + 1);
    goto LABEL_116;
  }
  v13 = 13;
  if ( a3 < 0 )
  {
    v16 = *(_DWORD *)(v9 + 16);
    if ( a3 == -1 )
    {
      if ( v16 < 16 )
        v13 = v16 - 1;
      v100 = v13;
      goto LABEL_46;
    }
    if ( v16 >= 16 )
      v16 = 14;
    v13 = v16;
    goto LABEL_45;
  }
  if ( (a3 & 7) == 2 )
  {
    v23 = *(_DWORD *)(v9 + 16);
    if ( v23 < 16 )
    {
      v13 = 5 * v23 / 16;
      v100 = 7 * v23 / 16;
    }
    else
    {
      v100 = 7;
      v13 = 5;
    }
    v18 = (char *)&unk_665230 + 112 * (a3 >> 3);
  }
  else
  {
    if ( (a3 & 7) == 3 )
    {
      v19 = *(_DWORD *)(v9 + 16);
      v13 = 0;
      if ( v19 < 16 )
        v100 = 3 * v19 / 16;
      else
        v100 = 3;
      v21 = (char *)&unk_5FF158 + 836 * (a3 >> 3);
      v22 = *((_WORD *)v21 + 72);
      v87 = (double)*((_WORD *)v21 + 71);
      v104 = *((_WORD *)v21 + 73);
      v88 = (double)v22;
      v20 = (double)v104;
      goto LABEL_47;
    }
    if ( (a3 & 7) != 5 )
    {
      v14 = *(_DWORD *)(v9 + 16);
      if ( (a3 & 7) == 6 )
      {
        if ( v14 >= 16 )
        {
          v100 = 9;
          v13 = 8;
          goto LABEL_46;
        }
        v13 = 8 * v14 / 16;
        v15 = 9 * v14;
      }
      else
      {
        if ( v14 >= 16 )
        {
          v100 = 12;
          v13 = 10;
LABEL_46:
          v87 = (double)pParty_global->dword_0006B4;
          v88 = (double)pParty_global->dword_0006B8;
          v20 = (double)dword_ACCFC4 + (double)pParty_global->dword_0006BC;
          goto LABEL_47;
        }
        v13 = 10 * v14 / 16;
        v15 = 12 * v14;
      }
      v16 = v15 / 16;
LABEL_45:
      v100 = v16;
      goto LABEL_46;
    }
    v17 = *(_DWORD *)(v9 + 16);
    if ( v17 < 16 )
    {
      v13 = v17 / 4;
      v100 = v17 / 4;
    }
    else
    {
      v13 = 4;
      v100 = 4;
    }
    v18 = (char *)&word_6836D0[16 * (a3 >> 3)];
  }
  v87 = (double)*((signed int *)v18 + 1);
  v88 = (double)*((signed int *)v18 + 2);
  v20 = (double)*((signed int *)v18 + 3);
LABEL_47:
  v89 = v20;
  if ( dword_6BE360 == 1 )
    sub_4AAEA6((int)&v87);
  else
    sub_436523((int)&v87, 1);
  if ( a3 )
  {
    if ( a3 != -1 )
    {
      v105 = 0;
      if ( *(_DWORD *)(v9 + 16) > 0 )
      {
        v24 = v99 + 20;
        do
        {
          if ( AIL_3D_sample_status(*(_DWORD *)v24) == 4
            && *(_DWORD *)(v24 + 4) == a3
            && AIL_3D_sample_status(*(_DWORD *)v24) == 4 )
          {
            if ( *(_DWORD *)(v24 + 8) == v96 )
              return;
            AIL_end_3D_sample(*(_DWORD *)v24);
            sub_4ABF23(v99, v24);
          }
          ++v105;
          v24 += 16;
        }
        while ( v105 < *(_DWORD *)(v99 + 16) );
      }
    }
  }
  v106 = v13;
  if ( v13 <= v100 )
  {
    v25 = 16 * v13 + v99 + 20;
    while ( AIL_3D_sample_status(*(_DWORD *)v25) != 2 )
    {
      ++v106;
      v25 += 16;
      if ( v106 > v100 )
        goto LABEL_67;
    }
    AIL_end_3D_sample(*(_DWORD *)v25);
    if ( *(_DWORD *)(v25 + 8) )
      sub_4ABF23(v99, v25);
  }
LABEL_67:
  v26 = v100;
  if ( v106 == v100 + 1 )
  {
    v95 = -1;
    v107 = 0;
    *(float *)&v98 = v91 * -0.01220703125;
    v97 = 0.0;
    v27 = v90 * 0.01220703125;
    *(float *)&a8 = v27;
    v28 = abs((signed __int64)v27);
    v29 = abs((signed __int64)v97);
    v30 = abs((signed __int64)*(float *)&v98);
    v94 = sub_4621DA(v30, v29, v28);
    a9 = v13;
    if ( v13 > v26 )
      goto LABEL_192;
    v31 = v99;
    v32 = 16 * v13 + v99 + 20;
    do
    {
      AIL_3D_position(v31, *(_DWORD *)v32, &v98, &v97, &a8);
      v35 = abs((signed __int64)*(float *)&a8);
      v36 = abs((signed __int64)v97);
      v37 = abs((signed __int64)*(float *)&v98);
      v34 = sub_4621DA(v37, v36, v35);
      v33 = v107 == v34;
      if ( v107 < v34 )
      {
        v107 = v34;
        v33 = 1;
      }
      if ( v33 && v94 < v107 )
      {
        v38 = a9;
        v95 = a9;
      }
      else
      {
        v38 = v95;
      }
      ++a9;
      v32 += 16;
    }
    while ( a9 <= v100 );
    if ( v38 == -1 )
    {
LABEL_192:
      v38 = 13;
      if ( v13 != 13 )
        return;
    }
    v39 = v99;
    v40 = 16 * v38 + v99 + 20;
    AIL_end_3D_sample(*(_DWORD *)v40);
    sub_4ABF23(v39, v40);
    v106 = v38;
  }
  v41 = v93;
  if ( *(_DWORD *)(v93 + pSoundList->pDescriptions + 112) || sub_4A9A67(pSoundList, a2, 0) )
  {
    v42 = 16 * v106 + v99;
    v43 = v42 + 20;
    if ( AIL_set_3D_sample_file(v99, *(_DWORD *)(v42 + 20), *(_DWORD *)(v41 + pSoundList->pDescriptions + 112)) )
    {
      if ( a4 )
        v85 = a4 - 1;
      else
        v85 = 1;
      AIL_set_3D_sample_loop_count(*(_DWORD *)v43, v85);
      if ( a5 == -1 )
      {
        if ( (a3 & 7) == 1 )
        {
          if ( dword_6BE360 != 1 )
            goto LABEL_103;
          v49 = (char *)Src + 80 * (a3 >> 3);
          if ( !*((_DWORD *)v49 + 1) )
            return;
          v87 = (double)**((_WORD **)v49 + 14);
          v88 = (double)**((_WORD **)v49 + 15);
          v46 = (double)**((_WORD **)v49 + 16);
LABEL_101:
          v89 = v46;
          if ( dword_6BE360 == 1 )
          {
            sub_4AAEA6((int)&v87);
            goto LABEL_104;
          }
LABEL_103:
          sub_436523((int)&v87, 1);
LABEL_104:
          AIL_start_3D_sample(*(_DWORD *)v43);
          AIL_set_3D_sample_float_distances(*(_DWORD *)v43, 100.0, 20.0, 100.0, 20.0);
          AIL_set_3D_sample_volume(*(_DWORD *)v43, *(_DWORD *)(v99 + 8));
          v103 = v91 * -0.01220703125;
          v50 = v90 * 0.01220703125;
          v102 = v50;
          v51 = abs((signed __int64)v50);
          v52 = abs(0);
          v53 = abs((signed __int64)v103);
          if ( sub_4621DA(v53, v52, v51) <= 100 )
          {
            AIL_set_3D_position(*(_DWORD *)v43, LODWORD(v103), 0.0, LODWORD(v102));
            v54 = -v102;
            v55 = -v103;
            AIL_set_3D_orientation(*(_DWORD *)v43, LODWORD(v55), 0.0, LODWORD(v54), 0.0, 1.0, 0.0);
            v56 = v99;
            *(_DWORD *)(v42 + 24) = a3;
            *(_DWORD *)(v42 + 28) = v96;
            *(_DWORD *)(16 * (v106 + 2) + v56) = a2;
          }
          else
          {
            AIL_end_3D_sample(*(_DWORD *)v43);
            sub_4ABF23(v99, v42 + 20);
          }
          return;
        }
        if ( (a3 & 7) == 2 )
        {
          v45 = (char *)&unk_665230 + 112 * (a3 >> 3);
        }
        else
        {
          if ( (a3 & 7) == 3 )
          {
            v47 = (char *)&unk_5FF158 + 836 * (a3 >> 3);
            v48 = *((_WORD *)v47 + 72);
            v87 = (double)*((_WORD *)v47 + 71);
            v101 = *((_WORD *)v47 + 73);
            v88 = (double)v48;
            v46 = (double)v101;
            goto LABEL_101;
          }
          if ( (a3 & 7) != 5 )
          {
            v87 = (double)pParty_global->dword_0006B4;
            v44 = (double)pParty_global->dword_0006B8;
LABEL_100:
            v88 = v44;
            v46 = (double)dword_ACCFC4 + (double)pParty_global->dword_0006BC;
            goto LABEL_101;
          }
          v45 = (char *)&word_6836D0[16 * (a3 >> 3)];
        }
        v87 = (double)*((signed int *)v45 + 1);
        v88 = (double)*((signed int *)v45 + 2);
        v46 = (double)*((signed int *)v45 + 3);
        goto LABEL_101;
      }
      v87 = (double)a5;
      v44 = (double)a6;
      goto LABEL_100;
    }
  }
}

//----- (004AA1F3) --------------------------------------------------------
int SetVolume(struct class31 *_this, float fVolume)
{
 if (_this->dword_00029C)
 {
  if (_this->hAILRedbook)
    return AIL_redbook_set_volume(_this->hAILRedbook, fVolume);
 }
 return 0;
}

//----- (MM7.exe::004AB8CE) --------------------------------------------------------
int __thiscall class31_Initialize(struct class31 *_this, HWND hWnd)
{
  int v5; // eax@9
  int v6; // ST00_4@9
  HSAMPLE hSample; // eax@15
  int v13; // [sp-4h] [bp-1Ch]@7
  int v14; // [sp+Ch] [bp-Ch]@9
  char *Str1; // [sp+10h] [bp-8h]@6
  int v16; // [sp+14h] [bp-4h]@5
  int i;

 _this->hWnd = hWnd;
 _this->hAILRedbook = 0;
 _this->hDigDriver = 0;
 _this->dword_0002AC = 0;
 _this->dword_0002B0 = 0;
 _this->dword_0002C4 = 127;
 _this->dword_0002C8 = 64;
 _this->dword_0002CC = 2;

 MSS32_DLL_Initialize();
 SMACKW32_DLL_Initialize();

 AIL_startup();

 _this->hAILRedbook = AIL_redbook_open_drive(_this->cGameCDDriveLetter);
 _this->hDigDriver = sub_4ABAF7();
 if (_this->hDigDriver)
   SmackSoundUseMSS(_this->hDigDriver);

 if (ReadWindowsRegistry("Disable3DSound", 0) != 1 && dword_F79D7C != 2)
 {
  v16 = 0;
    *(_DWORD *)_this = 0;
    *(_DWORD *)(_this + 4) = 0;
    ReadWindowsRegistry("3DSoundProvider", (BYTE *)(_this + 540), 0x80u, "NONE");
    sub_4ABC9B(1);
    while ( AIL_enumerate_3D_providers(&v16, &hWnd, &Str1) )
    {
      if ( !strcmp(Str1, (const char *)(_this + 540)) )
      {
        if ( AIL_open_3D_provider(v13, hWnd) )
        {
          *(_DWORD *)_this = 0;
          *(_DWORD *)(_this + 4) = 0;
          *(_DWORD *)(_this + 12) = 0;
        }
        else
        {
          v5 = hWnd;
          v6 = hWnd;
          *(_DWORD *)(_this + 4) = 1;
          *(_DWORD *)(_this + 12) = v5;
          *(_DWORD *)(_this + 16) = 4;
          AIL_3D_provider_attribute(v6, "EAX environment selection", &v14);
          if ( v14 != -1 )
            *(_DWORD *)_this = 1;
        }
        sub_4AC0A2(_this);
        break;
      }
    }
  }

 if (_this->iMixerChannels > 0)
 {
  for (i = 0; i < _this->iMixerChannels; ++i)
  {
   hSample = AIL_allocate_sample_handle(_this->hDigDriver);
   _this->array_0002E8[i * 4] = hSample;

   if (!hSample)
     break;
  }
 }

 if (_this->dword_00029C)
   sub_4AB71F(_this, -1, -1);
 _this->dword_00029C = 1;

 if (_this->hAILRedbook)
 {
  AIL_redbook_stop(_this->hAILRedbook);
  _this->dword_0002DC = AIL_redbook_tracks(_this->hAILRedbook);
 }

 //dword_F792F0 = AIL_redbook_volume(dword_F7937C);
 pClass31_global->dword_000218 = AIL_redbook_volume(pClass31_global->hAILRedbook);

 sub_4AA214(pClass31_global, 128.0 * aMusicVolumeLevels[byte_6BE36F]);
 if (pClass31_global->dword_00029C)
 {
  if (pClass31_global->hAILRedbook)
    AIL_redbook_set_volume(pClass31_global->hAILRedbook, 64.0 * aMusicVolumeLevels[byte_6BE371]);
 }
 class31_LoadSoundHeaders(_this);

 pVideoPlayer = malloc(sizeof(struct CVideoPlayer));
 CVideoPlayer_ctor(pVideoPlayer);
 return CVideoPlayer_LoadVideoHeaders(pVideoPlayer);
}

//----- (MM7.exe::004AB818) --------------------------------------------------------
int class31_LoadSoundHeaders(struct class31 *_this)
{
 DWORD w;

 strcpy(ExistingFileName, "Sounds\\Audio.snd");
 _this->hSoundsSource = CreateFileA("Sounds\\Audio.snd", GENERIC_READ, 1u, 0, 3u, 0x8000080u, 0);
 if (_this->hSoundsSource == INVALID_HANDLE_VALUE)
 {
  sprintfex(pStringBuffer, "Can't open file - %s", ExistingFileName);
  return MessageBoxA(0, pStringBuffer, "Sound File Error", 0);
 }

 ReadFile(_this->hSoundsSource, &_this->uNumSounds, 4, &w, 0);

 _this->pSoundHeaders = class23_AllocatedNamedBuffer(class23_instance, 0, _this->uNumSounds * sizeof(struct class31_sound_header_struct) + 2, 0);

 return ReadFile(_this->hSoundsSource, _this->pSoundHeaders, _this->uNumSounds * sizeof(struct class31_sound_header_struct), &w, 0);
}

//----- (MM7.exe::004AA214) --------------------------------------------------------
void sub_4AA214(struct class31 *_this, signed int a2)
{
 if (_this->dword_00029C)
 {
  _this->dword_0002C4 = a2;
  if (_this->hDigDriver)
    AIL_set_digital_master_volume(_this->hDigDriver, a2);

  if (_this->dword_000004)
    _this->dword_000008 = (signed __int64)((double)a2 * *(double *)&byte_4D8410[256]);
 }
}

//----- (004AB71F) --------------------------------------------------------
void sub_4AB71F(struct class31 *_this, int a2, int a3)
{
  int v3; // ecx@1
  int v4; // esi@1
 int i;

  int v10; // [sp+4h] [bp-4h]@3

  v4 = (int)_this;
  v3 = 0;

 if (!_this->dword_00029C)
   return;

 if (_this->dword_000004)
 {
  v10 = 0;
  if (_this->num_structs_0 > 0)
  {
   do
   {
    if (a2 == -1 || v3 < a2 || v3 > a3 )
    {
     if (_this->struct_0[v3].a[2])
     {
      if (pSoundList->pDescriptions[_this->struct_0[v3].a[2]].dword_000024 != 1 )
      {
       AIL_end_3D_sample(_this->struct_0[v3].a[0]);
       sub_4ABF23(v4, &_this->struct_0[v3]);
      _this->struct_0[v3].a[2] = 0;
       v3 = v10;
      }
     }
    }
    ++v3;
    v10 = v3;
   }
   while ( v3 < _this->num_structs_0 );
  }
 }


 if (_this->hDigDriver && _this->iMixerChannels > 0)
 {
  for (i = 0; i < _this->iMixerChannels; ++i)
  {
   if ( a2 == -1 || i < a2 || i > a3 )
   {
    if (pSoundList->pDescriptions[_this->array_0002E8[i * 4 + 2]].dword_000024 != 1 )
    {
     AIL_end_sample(_this->array_0002E8[i * 4 + 0]);
     sub_4ABE55(v4, &_this->array_0002E8[i * 4]);
     _this->array_0002E8[i * 4 + 1] = 0;
    }
   }
  }
 }

 if (_this->dword_0002B0)
   AIL_end_sequence(_this->dword_0002B0);
 if (_this->dword_000C74)
   AIL_pause_stream(_this->dword_000C74, 1);
}

//----- (MM7.exe::004ABAF7) --------------------------------------------------------
HDIGDRIVER __cdecl sub_4ABAF7()
{
  int v0; // ecx@1
  int i;
  size_t v2; // eax@4
  int v4; // [sp-4h] [bp-20h]@5
  int *v5; // [sp+10h] [bp-Ch]@2
  HDIGDRIVER hDrv;

  AIL_set_preference(15, 0);
  AIL_set_preference(33, 1);

  v0 = dword_4F00DC;
  pClass31_global->aDeviceNames[0][0] = 0;
  pClass31_global->uNumDevices = 0;
  if (dword_4F00DC < 11025)
    return 0;
 v5 = pClass31_global->array_000BF0;
 i = 0;
 while (true)
 {
  while (true)
  {
   sPCMWaveFormat.wf.wFormatTag = 1;
   sPCMWaveFormat.wf.nChannels = dword_4F00E4;
   sPCMWaveFormat.wf.nSamplesPerSec = v0;
   sPCMWaveFormat.wf.nBlockAlign = dword_4F00E4 * dword_4F00E0 / 8;
   sPCMWaveFormat.wf.nAvgBytesPerSec = v0 * dword_4F00E4 * dword_4F00E0 / 8;
   sPCMWaveFormat.wBitsPerSample = dword_4F00E0;

   if (!AIL_waveOutOpen(&hDrv, 0, -1, &sPCMWaveFormat))
     break;

      if ( !AIL_get_preference(15) )
        goto LABEL_8;
      v0 = dword_4F00DC / 2;
      dword_4F00DC /= 2;
      if ( dword_4F00DC < 11025 )
      {
        if ( dword_4F00E0 == 8 )
        {
          v0 = 22050;
          dword_4F00E0 = 8;
          dword_4F00DC = 22050;
        }
        goto LABEL_12;
      }
    }
    //strcpy(&byte_F794C8[v1], "Device: ");
    //v2 = strlen(&byte_F794C8[v1]);
    strcpy(&pClass31_global->aDeviceNames[i], "Device: ");
    v2 = strlen(&pClass31_global->aDeviceNames[i]);

    //AIL_digital_configuration(v7, v5, (char *)v5 + 64, &byte_F794C8[v2] + v1);
    AIL_digital_configuration(hDrv, v5, v5 + 16, &pClass31_global->aDeviceNames[i][v2]);

    v5++;
    pClass31_global->uNumDevices = ++i;

    if (AIL_get_preference(15))
      return hDrv;
    if (!strstr(pClass31_global->aDeviceNames[i - 1], "Emulated"))
      return hDrv;
    AIL_waveOutClose(v4, hDrv);
    AIL_set_preference(15, 1);
LABEL_8:
    AIL_set_preference(15, 1);
    v0 = dword_4F00DC;
LABEL_12:
    if ( v0 < 11025 )
      return 0;
  }
}
















void CSoundList_ctor(struct CSoundList *_this)
{
 memset(_this, 0, sizeof(struct CSoundList));
}

//----- (004A9E89) --------------------------------------------------------
void *CSoundList_Initialize(struct CSoundList *_this, unsigned char *pSrc)
{
 _this->uNumSounds = *(int *)(pSrc);

 _this->pDescriptions = class23_AllocatedNamedBuffer(class23_instance, _this->pDescriptions, _this->uNumSounds * sizeof(struct SoundDescription), "Snd Des.");
 memcpy(_this->pDescriptions, pSrc + 4, _this->uNumSounds * sizeof(struct SoundDescription));
 return 0;
}

//----- (004A9953) --------------------------------------------------------
int __fastcall sub_4A97C6(char *a1, int a2, _DWORD a3);
int sub_4A9953(struct CSoundList *_this)
{
  int v2; // esi@1
  signed int v3; // edi@2
  int v5; // eax@7
  int v6; // ebx@7
  int v8; // eax@7
  int v9; // eax@8
  struct SoundDescription sdesc;//char v10; // [sp+4h] [bp-A4h]@4
  char v11; // [sp+7Ch] [bp-2Ch]@10
  int v12; // [sp+90h] [bp-18h]@11
  char v13; // [sp+A0h] [bp-8h]@12
  int v14; // [sp+A4h] [bp-4h]@1
 int i;

  v2 = (int)_this;
  v14 = 1;

  for (i = 1; i < _this->uNumSounds; ++i)
  {
     lstrcpyA(sdesc.sSoundName, _this->pDescriptions[i].sSoundName);
     _this->pDescriptions[i].ptr_00002C = sub_4A97C6(&sdesc, -1, _this->pDescriptions[i].dword_000020);

     if (_this->pDescriptions[i].dword_000024 != 1 || !pClass31_global->dword_000004 ||
         !(_this->pDescriptions[i].dword_000028 & 2) || !_this->pDescriptions[i].ptr_00002C)
        continue;

      v8 = _this->pDescriptions[i].ptr_00002C[0];
      v6 = _this->pDescriptions[i].ptr_00002C + 1;
      v5 = AIL_file_type(v6, v8);
      if ( !v5 )
        goto LABEL_15;
      v9 = v5 - 1;
      if ( v9 )
      {
        if ( v9 == 1 )
        {
          if ( AIL_WAV_info(v6, &v11) )
          {
            if ( v12 != 2 )
            {
              if ( !AIL_decompress_ADPCM(&v11, v3 + *(_DWORD *)(v2 + 4) + 112, &v13) )
              {
                *(_DWORD *)(v3 + *(_DWORD *)(v2 + 4) + 112) = 0;
                *(_BYTE *)(v3 + *(_DWORD *)(v2 + 4) + 116) = 1;
              }
            }
          }
          goto LABEL_16;
        }
LABEL_15:
        *(_BYTE *)(v3 + *(_DWORD *)(v2 + 4) + 116) = 0;
        goto LABEL_16;
      }
      *(_DWORD *)(v3 + *(_DWORD *)(v2 + 4) + 112) = *(_DWORD *)(v3 + *(_DWORD *)(v2 + 4) + 44);
LABEL_16:
      sub_4A9DCD(v2, v14, 1);
  }

  return i;
}


//----- (004A9D79) --------------------------------------------------------
void sub_4A9D79(struct CSoundList *_this, int a2)
{
  int i; // ebx@1
  int v3; // edi@1
  void *v4; // esi@1
  int v5; // eax@2
  int v6; // ecx@2
  void *v7; // eax@5

  v4 = _this;
  v3 = 0;
  for ( i = 0; i < *(_DWORD *)v4; v3 += 120 )
  {
    v5 = v3 + *((_DWORD *)v4 + 1);
    v6 = *(_DWORD *)(v5 + 36);
    if ( v6 != 1 )
    {
      if ( a2 || v6 != 4 )
      {
        v7 = *(void **)(v5 + 44);
        if ( v7 )
        {
          sub_4A96BE(v7);
          *(_DWORD *)(v3 + *((_DWORD *)v4 + 1) + 44) = 0;
        }
        *(_DWORD *)(v3 + *((_DWORD *)v4 + 1) + 40) &= 0xFFFFFFFEu;
      }
    }
    ++i;
  }
}