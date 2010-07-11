#include "_audio.h"
#include "_video.h"
#include "AIL.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "FrameTables.h"

#include "mm7DDrawRenderer.h"

#include "data.h"


extern int (__cdecl *sprintfex)(char *, const char *, ...);
void AudioPlayer_ctor(struct AudioPlayer *_this)
{
 char pCurrentDirectory[256];
 char pIniFile[256];

 memset(_this, 0, sizeof(struct AudioPlayer));

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
void AudioPlayer_sub_4AA306(struct AudioPlayer *_this, int a2, signed int a3, int a4, signed int a5, int a6, int a7, int a8, int a9)
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

  runtime_warning(crashes in AIL);
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
            v74 = pParty_global->sPartyPosX;
          if ( !a6 )
            a6 = pParty_global->sPartyPosY;
          if ( a4 )
            AIL_set_sample_loop_count(*(_DWORD *)v73, a4 - 1);
          v82 = sub_4AB66C(v74, a6);
          AIL_set_sample_pan(*(_DWORD *)v73, v82);
          v83 = sub_4AB6B1(v74, a6, pParty_global->sPartyPosZ);
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
          v76 = (char *)array_665230 + 112 * (a3 >> 3);
          if ( !sub_4AB6B1(*((_DWORD *)v76 + 1), *((_DWORD *)v76 + 2), *((_DWORD *)v76 + 3)) )
            return;
        }
        else
        {
          if ( (a3 & 7) == 3 )
          {
            v80 = (char *)pActors + 836 * (a3 >> 3);
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
          v76 = (char *)&array_6836D0[(a3 >> 3)];
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
      v57 = (char *)array_665230 + 112 * (a3 >> 3);
    }
    else
    {
      if ( (a3 & 7) == 3 )
      {
        v98 = 0;
        v60 = (char *)pActors + 836 * (a3 >> 3);
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
      v57 = (char *)&array_6836D0[(a3 >> 3)];
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
    v18 = (char *)array_665230 + 112 * (a3 >> 3);
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
      v21 = (char *)pActors + 836 * (a3 >> 3);
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
          v87 = (double)pParty_global->sPartyPosX;
          v88 = (double)pParty_global->sPartyPosY;
          v20 = (double)pParty_global->uEyelevel + (double)pParty_global->sPartyPosZ;
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
    v18 = (char *)&array_6836D0[(a3 >> 3)];
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
          v45 = (char *)array_665230 + 112 * (a3 >> 3);
        }
        else
        {
          if ( (a3 & 7) == 3 )
          {
            v47 = (char *)pActors + 836 * (a3 >> 3);
            v48 = *((_WORD *)v47 + 72);
            v87 = (double)*((_WORD *)v47 + 71);
            v101 = *((_WORD *)v47 + 73);
            v88 = (double)v48;
            v46 = (double)v101;
            goto LABEL_101;
          }
          if ( (a3 & 7) != 5 )
          {
            v87 = (double)pParty_global->sPartyPosX;
            v44 = (double)pParty_global->sPartyPosY;
LABEL_100:
            v88 = v44;
            v46 = (double)pParty_global->uEyelevel + (double)pParty_global->sPartyPosZ;
            goto LABEL_101;
          }
          v45 = (char *)&array_6836D0[(a3 >> 3)];
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
int AudioPlayer_SetVolume(struct AudioPlayer *_this, float fVolume)
{
 if (_this->dword_00029C)
 {
  if (_this->hAILRedbook)
    return AIL_redbook_set_volume(_this->hAILRedbook, fVolume);
 }
 return 0;
}

//----- (MM7.exe::004AB8CE) --------------------------------------------------------
int AudioPlayer_Initialize(struct AudioPlayer *_this, HWND hWnd)
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
   AudioPlayer_sub_4AB71F(_this, -1, -1);
 _this->dword_00029C = 1;

 if (_this->hAILRedbook)
 {
  AIL_redbook_stop(_this->hAILRedbook);
  _this->dword_0002DC = AIL_redbook_tracks(_this->hAILRedbook);
 }

 pAudioPlayer->dword_000218 = AIL_redbook_volume(pAudioPlayer->hAILRedbook);

 AudioPlayer_sub_4AA214(pAudioPlayer, 128.0 * aMusicVolumeLevels[byte_6BE36F]);
 if (pAudioPlayer->dword_00029C)
 {
  if (pAudioPlayer->hAILRedbook)
    AIL_redbook_set_volume(pAudioPlayer->hAILRedbook, 64.0 * aMusicVolumeLevels[byte_6BE371]);
 }
 AudioPlayer_LoadSoundHeaders(_this);

 pVideoPlayer = malloc(sizeof(struct CVideoPlayer));
 CVideoPlayer_ctor(pVideoPlayer);
 return CVideoPlayer_LoadVideoHeaders(pVideoPlayer);
}

//----- (MM7.exe::004AB818) --------------------------------------------------------
int AudioPlayer_LoadSoundHeaders(struct AudioPlayer *_this)
{
 DWORD w;

 strcpy(TmpBuf, "Sounds\\Audio.snd");
 _this->hSoundsSource = CreateFileA("Sounds\\Audio.snd", GENERIC_READ, 1u, 0, 3u, 0x8000080u, 0);
 if (_this->hSoundsSource == INVALID_HANDLE_VALUE)
 {
  sprintfex(pStringBuffer, "Can't open file - %s", TmpBuf);
  return MessageBoxA(0, pStringBuffer, "Sound File Error", 0);
 }

 ReadFile(_this->hSoundsSource, &_this->uNumSounds, 4, &w, 0);

 _this->pSoundHeaders = class23_AllocatedNamedBuffer(class23_instance, 0, _this->uNumSounds * sizeof(struct AudioPlayer_sound_header_struct) + 2, 0);

 return ReadFile(_this->hSoundsSource, _this->pSoundHeaders, _this->uNumSounds * sizeof(struct AudioPlayer_sound_header_struct), &w, 0);
}

//----- (MM7.exe::004AA214) --------------------------------------------------------
void AudioPlayer_sub_4AA214(struct AudioPlayer *_this, signed int a2)
{
 if (_this->dword_00029C)
 {
  _this->dword_0002C4 = a2;
  if (_this->hDigDriver)
    AIL_set_digital_master_volume(_this->hDigDriver, a2);

  if (_this->dword_000004)
    _this->dword_000008 = (signed __int64)((double)a2 * memory_4D8410.d_0_5);
 }
}

//----- (004AB71F) --------------------------------------------------------
void AudioPlayer_sub_4AB71F(struct AudioPlayer *_this, int a2, int a3)
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
  pAudioPlayer->aDeviceNames[0][0] = 0;
  pAudioPlayer->uNumDevices = 0;
  if (dword_4F00DC < 11025)
    return 0;
 v5 = pAudioPlayer->array_000BF0;
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
    strcpy(&pAudioPlayer->aDeviceNames[i], "Device: ");
    v2 = strlen(&pAudioPlayer->aDeviceNames[i]);

    AIL_digital_configuration(hDrv, v5, v5 + 16, &pAudioPlayer->aDeviceNames[i][v2]);

    v5++;
    pAudioPlayer->uNumDevices = ++i;

    if (AIL_get_preference(15))
      return hDrv;
    if (!strstr(pAudioPlayer->aDeviceNames[i - 1], "Emulated"))
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

     if (_this->pDescriptions[i].dword_000024 != 1 || !pAudioPlayer->dword_000004 ||
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




//----- (004A9A67) --------------------------------------------------------
int sub_4A9A67(struct CSoundList *_this, int a2, int a3)
{
  int v3; // edi@1
  signed int v4; // edx@2
  struct SoundDescription *v9; // eax@3
  int v12; // eax@8
  int v13; // esi@8
  int v14; // eax@12
  int v15; // eax@14
  int v16; // eax@18
  int v17; // eax@20
  int v18; // ebx@20
  int v19; // ebx@20
  int v20; // eax@20
  int v21; // eax@21
  int v22; // ST04_4@26
  char v23[0x78]; // [sp+Ch] [bp-A0h]@12
  char v24; // [sp+84h] [bp-28h]@23
  int v25; // [sp+98h] [bp-14h]@24
  int v26; // [sp+A8h] [bp-4h]@2
 int i;

  v3 = (int)_this;
  v4 = _this->uNumSounds;
  v26 = 1;
  if ( dword_6BE364 & 0x10 || _this->uNumSounds <= 0) // if (nosound)
    return 0;

  v9 = _this->pDescriptions;
  i = 1;
  while ( a2 != v9[i].dword_000014)
  {
    v26 = ++i;
    if ( i >= _this->uNumSounds)
      return 0;
  }
  v13 = 120 * i;
  v12 = &_this->pDescriptions[i];
  if ( *(_DWORD *)(v12 + 40) & 2 && *(_DWORD *)(v12 + 112) || !(*(_DWORD *)(v12 + 40) & 2) && *(_DWORD *)(v12 + 44) )
    return v26;
  sprintfex(v23, "%s", v12);
  v14 = v13 + *(_DWORD *)(v3 + 4);
  if ( !*(_DWORD *)(v14 + 44) )
    *(_DWORD *)(*(_DWORD *)(v3 + 4) + v13 + 44) = sub_4A97C6(v23, -1, *(_DWORD *)(v14 + 32));
  v15 = v13 + *(_DWORD *)(v3 + 4);
  if ( !*(_DWORD *)(v15 + 44) )
    return 0;
  if ( a3 )
    *(_DWORD *)(v15 + 40) |= 1u;
  if ( !pAudioPlayer->dword_000004 || (v16 = v13 + *(_DWORD *)(v3 + 4), !(*(_BYTE *)(v16 + 40) & 2)) || !*(_DWORD *)(v16 + 44) )
    return v26;
  v19 = *(_DWORD *)(v16 + 44);
  v20 = *(_DWORD *)v19;
  v18 = v19 + 4;
  v17 = AIL_file_type(v18, v20);
  if ( !v17 )
  {
LABEL_29:
    *(_BYTE *)(*(_DWORD *)(v3 + 4) + v13 + 116) = 0;
    return 0;
  }
  v21 = v17 - 1;
  if ( v21 )
  {
    if ( v21 == 1 )
    {
      if ( AIL_WAV_info(v18, &v24) )
      {
        if ( v25 != 2 )
        {
          if ( !AIL_decompress_ADPCM(&v24, *(_DWORD *)(v3 + 4) + v13 + 112, &a2) )
          {
            v22 = v26;
            *(_DWORD *)(*(_DWORD *)(v3 + 4) + v13 + 112) = 0;
            *(_BYTE *)(*(_DWORD *)(v3 + 4) + v13 + 116) = 1;
            sub_4A9DCD(v3, v22, 0);
          }
        }
      }
      return v26;
    }
    goto LABEL_29;
  }
  *(_DWORD *)(*(_DWORD *)(v3 + 4) + v13 + 112) = *(_DWORD *)(*(_DWORD *)(v3 + 4) + v13 + 44);
  return v26;
}






//----- (004AAFCF) --------------------------------------------------------
void AudioPlayer_sub_4AAFCF(struct AudioPlayer *_this)
{
  int v1; // ebx@1
  int v2; // edi@1
  char v3; // zf@1
  int v4; // eax@2
  char v5; // zf@3
  unsigned __int8 v6; // zf@4
  unsigned __int8 v7; // sf@4
  int v8; // esi@5
  int v9; // ebx@6
  int v10; // ebx@9
  int v11; // ebx@10
  int v12; // ebx@11
  double v13; // st7@13
  char *v14; // eax@14
  char *v15; // eax@15
  signed int v16; // edx@15
  char *v17; // eax@19
  double v18; // st6@22
  double v19; // st7@22
  double v20; // st5@23
  double v21; // st3@24
  double v22; // st4@24
  double v23; // st6@28
  double v24; // st7@32
  int v25; // ST1C_4@32
  int v26; // ebx@32
  int v27; // eax@32
  float v28; // ST10_4@34
  float v29; // ST08_4@34
  int v30; // esi@38
  unsigned __int8 v31; // zf@43
  char v32; // sf@43
  unsigned __int8 v33; // of@43
  int v34; // esi@44
  signed int v35; // eax@45
  char *v36; // eax@49
  int v37; // eax@50
  char *v38; // edi@50
  int v39; // edx@51
  int v40; // ecx@51
  int v41; // eax@53
  char *v42; // edi@53
  char *v43; // edi@56
  int v44; // eax@57
  int v45; // eax@60
  int v46; // edi@65
  int v47; // eax@68
  int v48; // ebx@68
  __int16 *v49; // esi@68
  int v50; // ST1C_4@68
  int v51; // edi@68
  int v52; // eax@68
  int v53; // edi@69
  __int16 v54; // ax@69
  int v55; // eax@71
  __int16 v56; // ax@73
  signed int v57; // eax@88
  float v58; // [sp+24h] [bp-48h]@13
  float v59; // [sp+28h] [bp-44h]@13
  float v60; // [sp+2Ch] [bp-40h]@21
  float v61; // [sp+30h] [bp-3Ch]@26
  float v62; // [sp+34h] [bp-38h]@26
  float v63; // [sp+38h] [bp-34h]@26
  float v64; // [sp+50h] [bp-1Ch]@1
  float v65; // [sp+54h] [bp-18h]@22
  float v66; // [sp+58h] [bp-14h]@22
  int v67; // [sp+5Ch] [bp-10h]@15
  float v68; // [sp+60h] [bp-Ch]@23
  int v69; // [sp+64h] [bp-8h]@4
  int v70; // [sp+68h] [bp-4h]@1

  runtime_warning();
  return;

  v2 = _this;
  v1 = 0;
  v70 = _this;
  v3 = *(_DWORD *)(v2 + 668) == 0;
  v64 = 0.0;
  if ( !v3 )
  {
    v4 = v2 + 720;
    *(_DWORD *)v4 -= pClass24_global->int_00001C;
    if ( *(_DWORD *)(v2 + 720) <= 0 )
    {
      v5 = *(_DWORD *)(v2 + 4) == 0;
      *(_DWORD *)v4 = 32;
      if ( !v5 )
      {
        v6 = *(_DWORD *)(v2 + 16) == 0;
        v7 = *(_DWORD *)(v2 + 16) < 0;
        v69 = 0;
        if ( !(v7 | v6) )
        {
          v8 = v2 + 20;
          while ( 1 )
          {
            v9 = *(_DWORD *)(v8 + 4) & 7;
            if ( AIL_3D_sample_status(*(_DWORD *)v8) == 2 )
            {
              AIL_end_3D_sample(*(_DWORD *)v8);
              sub_4ABF23(v2, v8);
            }
            if ( AIL_3D_sample_status(*(_DWORD *)v8) != 4 )
              goto LABEL_35;
            v10 = v9 - 1;
            if ( v10 )
              break;
            if ( dword_6BE360 != 1 )
              goto LABEL_31;
            v17 = (char *)Src + 80 * (*(_DWORD *)(v8 + 4) >> 3);
            if ( *((_DWORD *)v17 + 1) )
            {
              v67 = **((_WORD **)v17 + 14);
              v58 = (double)v67;
              v67 = **((_WORD **)v17 + 15);
              v59 = (double)v67;
              v67 = **((_WORD **)v17 + 16);
              v13 = (double)v67;
              goto LABEL_21;
            }
LABEL_35:
            ++v69;
            v8 += 16;
            if ( v69 >= *(_DWORD *)(v2 + 16) )
            {
              v1 = 0;
              goto LABEL_37;
            }
          }
          v11 = v10 - 1;
          if ( v11 )
          {
            v12 = v11 - 1;
            if ( !v12 )
            {
              v15 = (char *)pActors + 836 * (*(_DWORD *)(v8 + 4) >> 3);
              v67 = *((_WORD *)v15 + 71);
              v16 = *((_WORD *)v15 + 72);
              v58 = (double)v67;
              v67 = *((_WORD *)v15 + 73);
              v59 = (double)v16;
              v13 = (double)v67;
              goto LABEL_21;
            }
            if ( v12 != 2 )
            {
              v58 = (double)pParty_global->sPartyPosX;
              v59 = (double)pParty_global->sPartyPosY;
              v13 = (double)pParty_global->uEyelevel + (double)pParty_global->sPartyPosZ;
              goto LABEL_21;
            }
            v14 = (char *)&array_6836D0[(*(_DWORD *)(v8 + 4) >> 3)];
          }
          else
          {
            v14 = (char *)array_665230 + 112 * (*(_DWORD *)(v8 + 4) >> 3);
          }
          v58 = (double)*((signed int *)v14 + 1);
          v59 = (double)*((signed int *)v14 + 2);
          v13 = (double)*((signed int *)v14 + 3);
LABEL_21:
          v60 = v13;
          if ( dword_6BE360 == 1 )
          {
            v19 = *(float *)&dword_51B718;
            v18 = *(float *)&dword_51B71C;
            v65 = flt_51B710;
            LODWORD(v66) = dword_51B714;
            if ( dword_51B6F8 )
            {
              v68 = v58 - (double)pParty_global->sPartyPosX;
              *(float *)&v67 = v59 - (double)pParty_global->sPartyPosY;
              v20 = v60 - (double)pParty_global->sPartyPosZ;
              if ( pD3DRenderer->dword_040088 )
              {
                v22 = *(float *)&v67 * v66 + v68 * v65;
                v21 = v68 * v66 - *(float *)&v67 * v65;
              }
              else
              {
                v22 = v68 * v65 - *(float *)&v67 * v66;
                v21 = v68 * v66 + *(float *)&v67 * v65;
              }
              v61 = v22 * v19 - v20 * v18;
              v62 = v21;
              v63 = v22 * v18 + v20 * v19;
            }
            else
            {
              v68 = v58 - (double)pParty_global->sPartyPosX;
              *(float *)&v67 = v59 - (double)pParty_global->sPartyPosY;
              if ( pD3DRenderer->dword_040088 )
              {
                v61 = *(float *)&v67 * v66 + v68 * v65;
                v23 = v68 * v66 - *(float *)&v67 * v65;
              }
              else
              {
                v61 = v68 * v65 - *(float *)&v67 * v66;
                v23 = v68 * v66 + *(float *)&v67 * v65;
              }
              v62 = v23;
              v63 = v60 - (double)pParty_global->sPartyPosZ;
            }
          }
          else
          {
LABEL_31:
            sub_436523((int)&v58, 1);
          }
          v68 = v62 * -0.01220703125;
          v24 = v61 * 0.01220703125;
          *(float *)&v67 = v24;
          v25 = abs((signed __int64)v24);
          v26 = abs(0);
          v27 = abs((signed __int64)v68);
          if ( sub_4621DA(v27, v26, v25) <= 100 )
          {
            AIL_set_3D_position(*(_DWORD *)v8, LODWORD(v68), 0.0, v67);
            v28 = -*(float *)&v67;
            v29 = -v68;
            AIL_set_3D_orientation(*(_DWORD *)v8, LODWORD(v29), 0.0, LODWORD(v28), 0.0, 1.0, 0.0);
          }
          else
          {
            AIL_end_3D_sample(*(_DWORD *)v8);
            sub_4ABF23(v2, v8);
          }
          goto LABEL_35;
        }
      }
LABEL_37:
      if ( *(_DWORD *)(v2 + 1000) > v1 )
      {
        v30 = v2 + 744;
        do
        {
          if ( AIL_sample_status(*(_DWORD *)v30) == 2 )
          {
            AIL_end_sample(*(_DWORD *)v30);
            sub_4ABE55(v2, v30);
          }
          ++v1;
          v30 += 16;
        }
        while ( v1 < *(_DWORD *)(v2 + 1000) );
        v1 = 0;
      }
      compile_error;//v33 = __SETO__(*(_DWORD *)(v2 + 1000), v1);
      v31 = *(_DWORD *)(v2 + 1000) == v1;
      v32 = *(_DWORD *)(v2 + 1000) - v1 < 0;
      v69 = v1;
      if ( !((unsigned __int8)(v32 ^ v33) | v31) )
      {
        v34 = v2 + 744;
        while ( 1 )
        {
          v35 = *(_DWORD *)(v34 + 4);
          if ( (*(_DWORD *)(v34 + 4) & 7) == 1 )
          {
            if ( dword_6BE360 == 1 )
            {
              v43 = (char *)Src + 80 * (v35 >> 3);
              if ( !*((_DWORD *)v43 + 1) )
              {
LABEL_61:
                v2 = v70;
                goto LABEL_62;
              }
              v44 = sub_4AB6B1(**((_WORD **)v43 + 14), **((_WORD **)v43 + 15), **((_WORD **)v43 + 16));
              if ( !v44 )
              {
LABEL_58:
                AIL_end_sample(*(_DWORD *)v34);
                sub_4ABE55(v70, v34);
                goto LABEL_61;
              }
              AIL_set_sample_volume(*(_DWORD *)v34, v44);
              v39 = **((_WORD **)v43 + 15);
              v40 = **((_WORD **)v43 + 14);
LABEL_60:
              v45 = sub_4AB66C(v40, v39);
              AIL_set_sample_pan(*(_DWORD *)v34, v45);
              goto LABEL_61;
            }
          }
          else
          {
            if ( (*(_DWORD *)(v34 + 4) & 7) == 2 )
            {
              v36 = (char *)array_665230 + 112 * (v35 >> 3);
              goto LABEL_53;
            }
            if ( (*(_DWORD *)(v34 + 4) & 7) == 3 )
            {
              v38 = (char *)pActors + 836 * (v35 >> 3);
              v37 = sub_4AB6B1(*((_WORD *)v38 + 71), *((_WORD *)v38 + 72), *((_WORD *)v38 + 73));
              if ( !v37 )
                goto LABEL_58;
              AIL_set_sample_volume(*(_DWORD *)v34, v37);
              v39 = *((_WORD *)v38 + 72);
              v40 = *((_WORD *)v38 + 71);
              goto LABEL_60;
            }
            if ( (*(_DWORD *)(v34 + 4) & 7) == 5 )
            {
              v36 = (char *)&array_6836D0[(v35 >> 3)];
LABEL_53:
              v42 = v36;
              v41 = sub_4AB6B1(*((_DWORD *)v36 + 1), *((_DWORD *)v36 + 2), *((_DWORD *)v36 + 3));
              if ( !v41 )
                goto LABEL_58;
              AIL_set_sample_volume(*(_DWORD *)v34, v41);
              v39 = *((_DWORD *)v42 + 2);
              v40 = *((_DWORD *)v42 + 1);
              goto LABEL_60;
            }
          }
LABEL_62:
          ++v69;
          v34 += 16;
          if ( v69 >= *(_DWORD *)(v2 + 1000) )
          {
            v1 = 0;
            break;
          }
        }
      }
      if ( dword_4E28F8 != v1 )
      {
        v46 = v2 + 808;
        if ( AIL_sample_status(*(_DWORD *)v46) == 4 )
          AIL_end_sample(*(_DWORD *)v46);
        return;
      }
      v69 = v1;
      if ( dword_6807E0 <= v1 )
        return;
      while ( 1 )
      {
        LODWORD(v66) = 1;
        v48 = 4 * v69 + 6817720;
        v49 = &array_6836D0[dword_6807B8[v69]];
        v50 = abs(*((_DWORD *)v49 + 3) - pParty_global->sPartyPosZ);
        v51 = abs(*((_DWORD *)v49 + 2) - pParty_global->sPartyPosY);
        v52 = abs(*((_DWORD *)v49 + 1) - pParty_global->sPartyPosX);
        v47 = sub_4621DA(v52, v51, v50);
        if ( v47 <= 8192 )
          break;
LABEL_89:
        ++v69;
        if ( v69 >= dword_6807E0 )
          return;
      }
      v53 = pDecorationDescriptionList->pDescriptions + 84 * *v49;
      v54 = *(_WORD *)(v53 + 74);
      v67 = (~(unsigned __int8)*(_WORD *)(v53 + 74) & 0x40) >> 6;
      if ( HIBYTE(v54) & 3 )
      {
        LOWORD(v47) = v49[13];
        LODWORD(v65) = 0;
        v67 = 2;
        if ( (_WORD)v47 )
        {
          v55 = v47 - 32;
          v49[13] = v55;
          if ( (_WORD)v55 < 0 )
            v49[13] = 0;
        }
      }
      v56 = *(_WORD *)(v53 + 74);
      if ( !(HIBYTE(v56) & 1) )
      {
        if ( !(HIBYTE(v56) & 2) )
          goto LABEL_84;
        if ( LODWORD(v65) )
          goto LABEL_85;
      }
      LODWORD(v66) = 0;
      if ( (unsigned int)pParty_global->uCurrentHour >= 5 && (unsigned int)pParty_global->uCurrentHour < 6
        || (unsigned int)pParty_global->uCurrentHour >= 0x14 && (unsigned int)pParty_global->uCurrentHour < 0x15 )
      {
        if ( !v49[13] )
        {
          if ( rand() % 100 < 100 )
            LODWORD(v66) = 1;
        }
        LODWORD(v65) = 1;
      }
LABEL_84:
      if ( !LODWORD(v65) )
      {
LABEL_87:
        if ( LODWORD(v66) )
        {
          v57 = 8 * *(_DWORD *)v48;
          LOBYTE(v57) = v57 | 5;
          AudioPlayer_sub_4AA306(v70, *(_WORD *)(v53 + 76), v57, v67, -1, 0, 0, 0, 0);
        }
        goto LABEL_89;
      }
LABEL_85:
      if ( !v49[13] )
        v49[13] = (rand() % 15 + 1) << 7;
      goto LABEL_87;
    }
  }
}

//----- (004AC041) --------------------------------------------------------
signed int AudioPlayer_sub_4AC041(struct AudioPlayer *_this)
{
  signed int result; // eax@1
  int v2; // esi@1
  unsigned int v3; // [sp+4h] [bp-4h]@3

  v2 = (int)_this;
  result = CMapStats_FindLocation(pMapStats, Str1);
  if ( *(_DWORD *)(v2 + 4) )
  {
    if ( *(_DWORD *)v2 )
    {
     v3 = pMapStats->pMapInfos[result].uEAXEnv;
      if ( v3 >= 0x1A )
      {
        result = sub_4AC004(_this);
        *(_DWORD *)(v2 + 532) = -1;
      }
      else
      {
        AIL_set_3D_provider_preference(*(_DWORD *)(v2 + 12), "EAX environment selection", &v3);
        result = v3;
        *(_DWORD *)(v2 + 532) = v3;
      }
    }
  }
  return result;
}