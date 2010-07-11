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

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"


//----- (004680ED) --------------------------------------------------------
void __thiscall sub_4680ED(void *this, signed int a2, int a3)
{
  int v3; // esi@1
  int v4; // ebx@4
  signed int v5; // eax@17
  int v6; // eax@26
  unsigned __int8 v7; // cf@37
  int v8; // edx@39
  int v9; // edx@40
  int v10; // edx@41
  int v11; // edx@42
  int v12; // edx@43
  int v13; // eax@45
  int v14; // ecx@62
  signed int v15; // edi@68
  int v16; // eax@73
  __int16 *v17; // edi@73
  int v18; // edx@73
  int v19; // eax@74
  int v20; // eax@75
  signed int v21; // eax@81
  int v22; // eax@84
  const char *v23; // ecx@90
  int v24; // esi@96
  int v25; // eax@109
  int v26; // eax@113
  int v27; // edi@114
  signed __int64 v28; // qax@120
  int v29; // ecx@120
  int v30; // edi@137
  int v31; // ST30_4@137
  int v32; // ST3C_4@137
  int v33; // ST40_4@137
  int v34; // ST34_4@137
  int v35; // ST38_4@137
  char v36; // al@173
  int v37; // [sp-20h] [bp-4Ch]@18
  int v38; // [sp-20h] [bp-4Ch]@174
  signed int v39; // [sp-1Ch] [bp-48h]@18
  signed int v40; // [sp-1Ch] [bp-48h]@174
  int v41; // [sp-18h] [bp-44h]@18
  int v42; // [sp-18h] [bp-44h]@174
  signed int v43; // [sp-14h] [bp-40h]@18
  signed int v44; // [sp-14h] [bp-40h]@174
  int v45; // [sp-10h] [bp-3Ch]@18
  __int16 v46; // [sp-10h] [bp-3Ch]@120
  int v47; // [sp-10h] [bp-3Ch]@174
  int v48; // [sp-Ch] [bp-38h]@18
  int v49; // [sp-Ch] [bp-38h]@33
  __int16 v50; // [sp-Ch] [bp-38h]@120
  int v51; // [sp-Ch] [bp-38h]@174
  int v52; // [sp-8h] [bp-34h]@18
  int v53; // [sp-8h] [bp-34h]@33
  int v54; // [sp-8h] [bp-34h]@34
  int v55; // [sp-8h] [bp-34h]@60
  int v56; // [sp-8h] [bp-34h]@66
  int v57; // [sp-8h] [bp-34h]@69
  int v58; // [sp-8h] [bp-34h]@89
  int v59; // [sp-8h] [bp-34h]@120
  int v60; // [sp-8h] [bp-34h]@174
  int v61; // [sp-4h] [bp-30h]@18
  int v62; // [sp-4h] [bp-30h]@33
  int v63; // [sp-4h] [bp-30h]@34
  int v64; // [sp-4h] [bp-30h]@60
  int v65; // [sp-4h] [bp-30h]@66
  int v66; // [sp-4h] [bp-30h]@69
  signed int v67; // [sp-4h] [bp-30h]@77
  int v68; // [sp-4h] [bp-30h]@89
  int v69; // [sp-4h] [bp-30h]@110
  char v70; // [sp-4h] [bp-30h]@120
  int v71; // [sp-4h] [bp-30h]@174
  int v72; // [sp+20h] [bp-Ch]@68
  signed int v73; // [sp+24h] [bp-8h]@1
  int v74; // [sp+24h] [bp-8h]@23
  int v75; // [sp+24h] [bp-8h]@73
  int v76; // [sp+28h] [bp-4h]@1
  int v77; // [sp+28h] [bp-4h]@22

  v76 = (int)this;
  v3 = &pParty_global->pPlayers[a2 - 1];
  v73 = 1;
  if ( dword_ACD834 == 1 && (dword_4F885C == 1 || dword_4F885C == 3) )
    return;
  v4 = 0;
  if ( (unsigned __int8)byte_5D2A00[48 * dword_AD470C] == 13 )
  {
    if ( dword_AD470C != 160 )
    {
      if ( dword_AD470C == 161 )
      {
        v27 = v3 + 6464;
        *(_DWORD *)v27 += 2;
LABEL_170:
        if ( *(_DWORD *)v27 > Player_GetMaxMana(v3) )
          *(_DWORD *)v27 = Player_GetMaxMana(v3);
      }
      else
      {
        if ( dword_AD470C != 162 )
        {
LABEL_167:
          v68 = sub_456499(&dword_AD470C);
          v58 = pGlobalTXT_LocalizationStrings[36];
          goto LABEL_90;
        }
        v69 = 2;
LABEL_111:
        sub_48DBB9(&pParty_global->pPlayers[a2 - 1], v69);
      }
LABEL_112:
      sub_4948B1((void *)v3, 36, 0);
      goto LABEL_173;
    }
LABEL_172:
    Player_sub_492D65(&pParty_global->pPlayers[a2 - 1], 6, 1);
    goto LABEL_173;
  }
  if ( (unsigned __int8)byte_5D2A00[48 * dword_AD470C] == 14 )
  {
    switch ( dword_AD470C )
    {
      case 222:
        v25 = dword_AD4710 + 10;
        goto LABEL_110;
      case 223:
        v26 = dword_AD4710 + 10;
        goto LABEL_114;
      case 224:
        *(_DWORD *)(v3 + 8) = 0;
        *(_DWORD *)(v3 + 12) = 0;
        goto LABEL_112;
      case 225:
        *(_DWORD *)(v3 + 88) = 0;
        *(_DWORD *)(v3 + 92) = 0;
        *(_DWORD *)(v3 + 72) = 0;
        *(_DWORD *)(v3 + 76) = 0;
        *(_DWORD *)(v3 + 56) = 0;
        *(_DWORD *)(v3 + 60) = 0;
        goto LABEL_112;
      case 226:
        *(_DWORD *)(v3 + 80) = 0;
        *(_DWORD *)(v3 + 84) = 0;
        *(_DWORD *)(v3 + 64) = 0;
        *(_DWORD *)(v3 + 68) = 0;
        *(_DWORD *)(v3 + 48) = 0;
        *(_DWORD *)(v3 + 52) = 0;
        goto LABEL_112;
      case 227:
        *(_DWORD *)(v3 + 16) = 0;
        *(_DWORD *)(v3 + 20) = 0;
        goto LABEL_112;
      case 228:
        if ( *(_QWORD *)(v3 + 8) )
          goto LABEL_173;
        v70 = 0;
        v59 = 0;
        v50 = 5;
        v46 = 3;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6160;
        goto LABEL_147;
      case 229:
        v70 = 0;
        v59 = 0;
        v50 = 5;
        v46 = 3;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6176;
        goto LABEL_147;
      case 230:
        v70 = 0;
        v59 = 0;
        v50 = 5;
        v46 = 3;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6064;
        goto LABEL_147;
      case 231:
        v70 = 0;
        v59 = 0;
        v50 = 3 * dword_AD4710;
        v46 = 0;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6224;
        goto LABEL_147;
      case 232:
        v70 = 0;
        v59 = 0;
        v50 = 3 * dword_AD4710;
        v46 = 0;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6256;
        goto LABEL_147;
      case 234:
        v70 = 0;
        v59 = 0;
        v50 = 5;
        v46 = 3;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6272;
        goto LABEL_147;
      case 235:
        sub_4584E0(
          v3 + 6416,
          pParty_global->qword_00002C + (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214),
          (unsigned __int64)(pParty_global->qword_00002C + (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214)) >> 32,
          3,
          5,
          0,
          0);
        goto LABEL_173;
      case 237:
        *(_DWORD *)(v3 + 24) = 0;
        *(_DWORD *)(v3 + 28) = 0;
        goto LABEL_112;
      case 238:
        *(_DWORD *)v3 = 0;
        *(_DWORD *)(v3 + 4) = 0;
        goto LABEL_112;
      case 239:
        *(_DWORD *)(v3 + 40) = 0;
        *(_DWORD *)(v3 + 44) = 0;
        goto LABEL_112;
      case 240:
        v70 = 0;
        v59 = 0;
        v50 = 3 * dword_AD4710;
        v46 = 0;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6352;
        goto LABEL_147;
      case 241:
        v70 = 0;
        v59 = 0;
        v50 = 3 * dword_AD4710;
        v46 = 0;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6320;
        goto LABEL_147;
      case 242:
        v70 = 0;
        v59 = 0;
        v50 = 3 * dword_AD4710;
        v46 = 0;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6368;
        goto LABEL_147;
      case 243:
        v70 = 0;
        v59 = 0;
        v50 = 3 * dword_AD4710;
        v46 = 0;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6304;
        goto LABEL_147;
      case 244:
        v70 = 0;
        v59 = 0;
        v50 = 3 * dword_AD4710;
        v46 = 0;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6384;
        goto LABEL_147;
      case 245:
        v70 = 0;
        v59 = 0;
        v50 = 3 * dword_AD4710;
        v46 = 0;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6288;
        goto LABEL_147;
      case 251:
        *(_DWORD *)(v3 + 96) = 0;
        *(_DWORD *)(v3 + 100) = 0;
        goto LABEL_112;
      case 252:
        v30 = *(_DWORD *)(v3 + 112);
        v31 = *(_DWORD *)(v3 + 116);
        v32 = *(_DWORD *)(v3 + 120);
        v33 = *(_DWORD *)(v3 + 124);
        v34 = *(_DWORD *)(v3 + 128);
        v35 = *(_DWORD *)(v3 + 132);
        memset(&pParty_global->pPlayers[a2 - 1], 0, 0xA0);
        *(_DWORD *)(v3 + 116) = v31;
        *(_DWORD *)(v3 + 120) = v32;
        *(_DWORD *)(v3 + 124) = v33;
        *(_DWORD *)(v3 + 128) = v34;
        *(_DWORD *)(v3 + 112) = v30;
        *(_DWORD *)(v3 + 132) = v35;
        goto LABEL_112;
      case 253:
        v25 = 5 * dword_AD4710;
LABEL_110:
        v69 = v25;
        goto LABEL_111;
      case 254:
        v26 = 5 * dword_AD4710;
LABEL_114:
        v27 = v3 + 6464;
        *(_DWORD *)v27 += v26;
        goto LABEL_170;
      case 255:
        v70 = 0;
        v59 = 0;
        v50 = 3 * dword_AD4710;
        v46 = 0;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6336;
        goto LABEL_147;
      case 256:
        v70 = 0;
        v59 = 0;
        v50 = 3 * dword_AD4710;
        v46 = 0;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6128;
        goto LABEL_147;
      case 257:
        v70 = 0;
        v59 = 0;
        v50 = 3 * dword_AD4710;
        v46 = 0;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6048;
        goto LABEL_147;
      case 258:
        v70 = 0;
        v59 = 0;
        v50 = 3 * dword_AD4710;
        v46 = 0;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6400;
        goto LABEL_147;
      case 259:
        v70 = 0;
        v59 = 0;
        v50 = 3 * dword_AD4710;
        v46 = 0;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6096;
        goto LABEL_147;
      case 260:
        v70 = 0;
        v59 = 0;
        v50 = 3 * dword_AD4710;
        v46 = 0;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6192;
        goto LABEL_147;
      case 261:
        v70 = 0;
        v59 = 0;
        v50 = 3 * dword_AD4710;
        v46 = 0;
        v28 = (signed __int64)((double)(230400 * dword_AD4710) * 0.03333333507180214);
        v29 = v3 + 6080;
LABEL_147:
        sub_4584E0(v29, pParty_global->qword_00002C + v28, (unsigned __int64)(pParty_global->qword_00002C + v28) >> 32, v46, v50, v59, v70);
        goto LABEL_112;
      case 262:
        *(_DWORD *)(v3 + 120) = 0;
        *(_DWORD *)(v3 + 124) = 0;
        goto LABEL_112;
      case 264:
        if ( !*(_DWORD *)(v3 + 504) )
        {
          *(_WORD *)(v3 + 212) += 50;
          *(_DWORD *)(v3 + 504) = 1;
        }
        goto LABEL_112;
      case 265:
        if ( !*(_DWORD *)(v3 + 508) )
        {
          *(_WORD *)(v3 + 204) += 50;
          *(_DWORD *)(v3 + 508) = 1;
        }
        goto LABEL_112;
      case 266:
        if ( !*(_DWORD *)(v3 + 512) )
        {
          *(_WORD *)(v3 + 192) += 50;
          *(_DWORD *)(v3 + 512) = 1;
        }
        goto LABEL_112;
      case 267:
        if ( !*(_DWORD *)(v3 + 516) )
        {
          *(_WORD *)(v3 + 200) += 50;
          *(_DWORD *)(v3 + 516) = 1;
        }
        goto LABEL_112;
      case 268:
        if ( !*(_DWORD *)(v3 + 520) )
        {
          *(_WORD *)(v3 + 196) += 50;
          *(_DWORD *)(v3 + 520) = 1;
        }
        goto LABEL_112;
      case 269:
        if ( !*(_DWORD *)(v3 + 524) )
        {
          *(_WORD *)(v3 + 208) += 50;
          *(_DWORD *)(v3 + 524) = 1;
        }
        goto LABEL_112;
      case 270:
        if ( !*(_DWORD *)(v3 + 528) )
        {
          *(_WORD *)(v3 + 188) += 50;
          *(_DWORD *)(v3 + 528) = 1;
        }
        goto LABEL_112;
      case 271:
        *(_WORD *)(v3 + 222) = 0;
        goto LABEL_112;
      default:
        goto LABEL_167;
      case 221:
        goto LABEL_172;
    }
    goto LABEL_172;
  }
  if ( (unsigned __int8)byte_5D2A00[48 * dword_AD470C] != 15 )
  {
    if ( (unsigned __int8)byte_5D2A00[48 * dword_AD470C] != 16 )
    {
      if ( (unsigned __int8)byte_5D2A00[48 * dword_AD470C] != 17 )
      {
        if ( dword_AD470C == 616 )
        {
          v77 = pParty_global->uCurrentMonthWeek + 1;
          if (pParty_global->uCurrentMonth >= 7 )
            v74 = 0;
          else
            //v74 = dword_507B78[dword_ACD6C8];
            v74 = aAttributeNames[pParty_global->uCurrentMonth / 4];
          switch (pParty_global->uCurrentMonth)
          {
            case 0:
              v6 = pParty_global->uCurrentMonthWeek + 1;
              *(_WORD *)(v3 + 188) += v77;
              goto LABEL_33;
            case 1:
              v6 = pParty_global->uCurrentMonthWeek + 1;
              *(_WORD *)(v3 + 192) += v77;
              goto LABEL_33;
            case 2:
              v6 = pParty_global->uCurrentMonthWeek + 1;
              *(_WORD *)(v3 + 196) += v77;
              goto LABEL_33;
            case 3:
              v6 = pParty_global->uCurrentMonthWeek + 1;
              *(_WORD *)(v3 + 200) += v77;
              goto LABEL_33;
            case 4:
              v6 = pParty_global->uCurrentMonthWeek + 1;
              *(_WORD *)(v3 + 208) += v77;
              goto LABEL_33;
            case 5:
              v6 = pParty_global->uCurrentMonthWeek + 1;
              *(_WORD *)(v3 + 204) += v77;
              goto LABEL_33;
            case 6:
              v6 = pParty_global->uCurrentMonthWeek + 1;
              *(_WORD *)(v3 + 212) += v77;
LABEL_33:
              v62 = pGlobalTXT_LocalizationStrings[121];
              v53 = v74;
              v49 = v6;
              goto LABEL_53;
            case 7:
              sub_420C05(1000 * v77, 0);
              v63 = pGlobalTXT_LocalizationStrings[97];
              v54 = 1000 * v77;
              goto LABEL_38;
            case 8:
              sub_492B42((void *)(5 * v77));
              v63 = pGlobalTXT_LocalizationStrings[653];
              v54 = 5 * v77;
              goto LABEL_38;
            case 9:
              v63 = pGlobalTXT_LocalizationStrings[207];
              *(_DWORD *)(v3 + 6456) += 2 * v77;
              v54 = 2 * v77;
              goto LABEL_38;
            case 10:
              v63 = pGlobalTXT_LocalizationStrings[83];
              v54 = 2500 * v77;
              v7 = 2500 * v77 >= (unsigned int)-*(_DWORD *)(v3 + 160);
              *(_DWORD *)(v3 + 160) += 2500 * v77;
              *(_DWORD *)(v3 + 164) += ((unsigned __int64)(2500 * v77) >> 32) + v7;
LABEL_38:
              sprintfex(&TmpBuf, "+%u %s", v54, v63);
              goto LABEL_54;
            case 11:
              v8 = rand() % 6;
              if ( v8 )
              {
                v9 = v8 - 1;
                if ( v9 )
                {
                  v10 = v9 - 1;
                  if ( v10 )
                  {
                    v11 = v10 - 1;
                    if ( v11 )
                    {
                      v12 = v11 - 1;
                      if ( v12 )
                      {
                        if ( v12 != 1 )
                          goto LABEL_52;
                        *(_WORD *)(v3 + 6020) += v77;
                        v13 = pGlobalTXT_LocalizationStrings[29];
                      }
                      else
                      {
                        *(_WORD *)(v3 + 6018) += v77;
                        v13 = pGlobalTXT_LocalizationStrings[142];
                      }
                    }
                    else
                    {
                      *(_WORD *)(v3 + 6010) += v77;
                      v13 = pGlobalTXT_LocalizationStrings[70];
                    }
                  }
                  else
                  {
                    *(_WORD *)(v3 + 6008) += v77;
                    v13 = pGlobalTXT_LocalizationStrings[240];
                  }
                }
                else
                {
                  *(_WORD *)(v3 + 6006) += v77;
                  v13 = pGlobalTXT_LocalizationStrings[6];
                }
              }
              else
              {
                *(_WORD *)(v3 + 6004) += v77;
                v13 = pGlobalTXT_LocalizationStrings[87];
              }
              v74 = v13;
LABEL_52:
              v62 = pGlobalTXT_LocalizationStrings[121];
              v53 = v74;
              v49 = v77;
LABEL_53:
              sprintfex(&TmpBuf, "+%u %s %s", v49, v53, v62);
LABEL_54:
              sub_44C175(&TmpBuf, 2);
              class03_sub_4698A6(pGame->pClass03);
              sub_4A89BD(pGame->class06_obj, 151, a2 - 1);
              sub_4948B1((void *)v3, 93, 0);
              AudioPlayer_sub_4AA306(pAudioPlayer, 219, 0, 0, -1, 0, 0, 0, 0);
              if ( pParty_global->uDaysPlayed == 6 || pParty_global->uDaysPlayed == 20 )
              {
                v64 = 0;
                v55 = 16;
              }
              else
              {
                if ( pParty_global->uDaysPlayed == 12 || pParty_global->uDaysPlayed == 26 )
                {
                  v64 = 0;
                  v55 = 14;
                }
                else
                {
                  if ( pParty_global->uDaysPlayed != 4 && pParty_global->uDaysPlayed != 25 )
                    return;
                  v64 = 0;
                  v55 = 15;
                }
              }
              Player_sub_492D65((char *)v3, v55, v64);
              v61 = 0;
              v52 = 0;
              v48 = 0;
              v45 = 0;
              v43 = -1;
              v41 = 0;
              v39 = 0;
              v37 = 215;
              v14 = pAudioPlayer;
              goto LABEL_63;
            default:
              goto LABEL_54;
          }
        }
        if ( dword_AD470C == 630 )
        {
          sub_492B42((void *)1);
          AudioPlayer_sub_4AA306(pAudioPlayer, 211, 0, 0, -1, 0, 0, 0, 0);
        }
        else
        {
          if ( dword_AD470C == 632 )
          {
            v61 = 0;
            v52 = 0;
            v48 = 0;
            v45 = 0;
            v43 = -1;
            v41 = 0;
            v39 = 0;
            v37 = 133;
            goto LABEL_93;
          }
          if ( dword_AD470C == 633 )
          {
            v61 = 0;
            v52 = 0;
            v48 = 0;
            v45 = 0;
            v43 = -1;
            v41 = 0;
            v39 = 0;
            v37 = 134;
            goto LABEL_93;
          }
          if ( dword_AD470C == 634 )
          {
            v61 = 0;
            v52 = 0;
            v48 = 0;
            v45 = 0;
            v43 = -1;
            v41 = 0;
            v39 = 0;
            v37 = 135;
            goto LABEL_93;
          }
          if ( dword_AD470C != 646 )
          {
            if ( dword_AD470C == 650 )
            {
              sub_44C28F();
              return;
            }
            goto LABEL_167;
          }
          sub_4A89BD(pGame->class06_obj, 151, a2 - 1);
          v5 = 8 * a2 + 392;
          LOBYTE(v5) = (8 * a2 - 120) | 4;
          AudioPlayer_sub_4AA306(pAudioPlayer, 20001, v5, 0, -1, 0, 0, 0, 0);
          sub_44AFFB((char *)v3, 243, 2);
        }
LABEL_187:
        class03_sub_4698A6(pGame->pClass03);
        return;
      }
      if ( sub_492C0B(&pParty_global->pPlayers[a2 - 1]))
      {
        sub_467F48(dword_AD470C);
        v65 = 0;
        v56 = 37;
LABEL_67:
        sub_4948B1((void *)v3, v56, v65);
        return;
      }
LABEL_89:
      //v68 = (int)(&dword_AE3280)[4 * sub_48E9F4_GetConditionNameOffset((void *)v3)];
      v68 = (int)(aCharacterConditionNames[sub_48E9F4_GetConditionNameOffset((void *)v3)]);

      v58 = pGlobalTXT_LocalizationStrings[382];
LABEL_90:
      sprintfex(&TmpBuf, (const char *)v58, v68);
      v23 = &TmpBuf;
LABEL_91:
      sub_44C175(v23, 2);
      v4 = 0;
      goto LABEL_92;
    }
    v15 = dword_AD470C - 400;
    v72 = dword_AD470C - 400 + v3 + 402;
    if ( *(_BYTE *)v72 )
    {
      v66 = sub_456499(&dword_AD470C);
      v57 = pGlobalTXT_LocalizationStrings[380];
LABEL_72:
      sprintfex(&TmpBuf, (const char *)v57, v66);
      sub_44C175(&TmpBuf, 2);
LABEL_92:
      v61 = v4;
      v52 = v4;
      v48 = v4;
      v45 = v4;
      v43 = -1;
      v41 = v4;
      v39 = v4;
      v37 = 27;
LABEL_93:
      v14 = pAudioPlayer;
LABEL_63:
      AudioPlayer_sub_4AA306(v14, v37, v39, v41, v43, v45, v48, v52, v61);
      return;
    }
    if ( !sub_492C0B(&pParty_global->pPlayers[a2 - 1]))
    {
      //v66 = (int)(&dword_AE3280)[4 * sub_48E9F4_GetConditionNameOffset((void *)v3)];
     v66 = (int)(aCharacterConditionNames[sub_48E9F4_GetConditionNameOffset((void *)v3)]);

      v57 = pGlobalTXT_LocalizationStrings[382];
      goto LABEL_72;
    }
    v18 = v15 % 11 + 1;
    v17 = (__int16 *)(v3 + 2 * v15 / 11 + 288);
    v75 = v18;
    v16 = sub_458244(*v17) - 1;
    if ( v16 )
    {
      v19 = v16 - 1;
      if ( v19 )
      {
        v20 = v19 - 1;
        if ( v20 )
        {
          if ( v20 != 1 )
          {
            v21 = a2;
LABEL_83:
            if ( v75 > v21 || !*v17 )
            {
              v22 = sub_456499(&dword_AD470C);
              sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[381], v22);
              sub_44C175(&TmpBuf, 2);
              v65 = 0;
              v56 = 20;
              goto LABEL_67;
            }
            *(_BYTE *)v72 = 1;
            sub_4948B1((void *)v3, 21, 0);
            v73 = 0;
LABEL_173:
            v36 = byte_5D2A00[48 * dword_AD470C];
            if ( v36 == 14 )
            {
              v71 = 0;
              v60 = 0;
              v51 = 0;
              v47 = 0;
              v44 = -1;
              v42 = 0;
              v40 = 0;
              v38 = 210;
            }
            else
            {
              if ( v36 != 13 )
              {
LABEL_178:
                if ( pGUIWindow_PlayerCreation && *(_DWORD *)(pGUIWindow_PlayerCreation + 24) )
                {
                  if ( !v73 )
                    goto LABEL_187;
                  if ( dword_50CBD0[0] < 40 )
                  {
                    dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
                    dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
                    dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
                  }
                }
                if ( v73 )
                {
                  if ( dword_ACD834 )
                  {
                    dword_AE30F8[a2] = 100;
                    sub_48E96A(v76, 100);
                    sub_40471C(&unk_4F8858);
                  }
                  else
                  {
                    sub_48E96A(v76, (signed __int64)(flt_6BE3A4 * *(double *)&byte_4D8410[296]));
                  }
                }
                goto LABEL_187;
              }
              v71 = 0;
              v60 = 0;
              v51 = 0;
              v47 = 0;
              v44 = -1;
              v42 = 0;
              v40 = 0;
              v38 = 211;
            }
            AudioPlayer_sub_4AA306(pAudioPlayer, v38, v40, v42, v44, v47, v51, v60, v71);
            goto LABEL_178;
          }
          v67 = 11;
        }
        else
        {
          v67 = 10;
        }
      }
      else
      {
        v67 = 7;
      }
    }
    else
    {
      v67 = 4;
    }
    v21 = v67;
    goto LABEL_83;
  }
  if ( dword_4E28F8 == 23 )
    return;
  if ( !sub_492C0B(&pParty_global->pPlayers[a2 - 1]) )
    goto LABEL_89;
  if ( byte_6BE3C4 == 1 )
  {
    v23 = pGlobalTXT_LocalizationStrings[652];
    goto LABEL_91;
  }
  dword_50C9AC = 1;
  v24 = dword_AD470C - 299;
  if ( dword_AD470C == 329 || v24 == 4 || v24 == 91 || v24 == 28 )
  {
    class03_sub_4698A6(pGame->pClass03);
    GUIWindowDelete(pGUIWindow_PlayerCreation);
    sub_4114F2(pClass17_Icons_LOD);
    dword_4E28F8 = 0;
    struct_576FE8.dword_000044 = 1;
    sub_42777D(v24, a2 - 1, 133, 1, 0);
  }
  else
  {
    dword_720984 = dword_AD470C;
    class03_sub_4698A6(pGame->pClass03);
    if ( dword_50C9E8[0] < 40 )
    {
      dword_50C9EC[3 * dword_50C9E8[0]] = 146;
      dword_50C9F0[3 * dword_50C9E8[0]] = v24;
      dword_50C9E8[3 * dword_50C9E8[0]++ + 3] = a2 - 1;
    }
    if ( dword_4E28F8 )
    {
      if ( pGUIWindow_PlayerCreation )
      {
        if ( *(_DWORD *)(pGUIWindow_PlayerCreation + 24) )
        {
          if ( dword_50CBD0[0] < 40 )
          {
            dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
            dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
            dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
          }
        }
      }
    }
  }
}

//----- (00468F8A) --------------------------------------------------------
void __cdecl sub_468F8A()
{
  int v0; // ecx@1
  int v1; // ebx@1
  int v2; // edi@1
  signed int v3; // edx@4
  signed int v4; // esi@5
  __int16 v5; // ax@7
  void *v6; // edi@19
  int v7; // esi@27
  signed int v8; // eax@29
  int v9; // edx@32
  int v10; // esi@34
  int v11; // eax@34
  int v12; // esi@38
  int v13; // eax@38
  char v14; // zf@38
  int v15; // esi@42
  int v16; // eax@42
  int v17; // eax@44
  int v18; // eax@55
  signed int v19; // ecx@55
  int v20; // esi@60
  int v21; // eax@60
  char v22; // zf@60
  int v23; // eax@61
  signed int v24; // eax@62
  int v25; // esi@65
  int v26; // eax@65
  char v27; // zf@65
  signed int v28; // eax@69
  int v29; // esi@81
  int v30; // eax@81
  int v31; // esi@84
  int v32; // eax@84
  int v33; // eax@85
  int v34; // eax@88
  int v35; // ecx@88
  int v36; // eax@90
  int v37; // eax@91
  int v38; // edi@93
  int v39; // esi@93
  int v40; // edi@93
  char v41; // zf@93
  __int16 v42; // dx@99
  signed int v43; // [sp-1Ch] [bp-68h]@80
  int v44; // [sp-18h] [bp-64h]@80
  signed int v45; // [sp-14h] [bp-60h]@80
  int v46; // [sp-10h] [bp-5Ch]@80
  int v47; // [sp-Ch] [bp-58h]@80
  int v48; // [sp-8h] [bp-54h]@80
  int v49; // [sp-4h] [bp-50h]@80
  int v50; // [sp+Ch] [bp-40h]@1
  char v51; // [sp+24h] [bp-28h]@34
  int v52; // [sp+30h] [bp-1Ch]@88
  int v53; // [sp+34h] [bp-18h]@57
  int v54; // [sp+38h] [bp-14h]@50
  int v55; // [sp+3Ch] [bp-10h]@1
  int v56; // [sp+40h] [bp-Ch]@5
  int v57; // [sp+44h] [bp-8h]@1
  int v58; // [sp+48h] [bp-4h]@1

  v55 = 0;
  sub_402F07((int)&v50);
  v1 = (int)*(&ptr_A750C4 + uMaybeSelectedCharacter);
  v0 = *(_DWORD *)(v1 + 6476);
  v2 = *(_DWORD *)(v1 + 6472);
  v58 = *(_DWORD *)(v1 + 6472);
  v57 = v0;
  if ( v0 )
  {
    if ( byte_5D2A00[48 * *(_DWORD *)(v1 + 36 * v0 + 496)] == 1 )
      v55 = v0;
  }
  v3 = dword_AD470C;
  if ( dword_AD470C )
  {
    v56 = (unsigned __int8)byte_5D2A00[48 * dword_AD470C];
    v4 = (unsigned __int8)byte_5D2A00[48 * dword_AD470C + 1];
    if ( v4 == 4 )
    {
      if ( v2 )
      {
LABEL_7:
        LOBYTE(v5) = sub_48F882((void *)v1, 4);
        if ( sub_458244(v5) < 3 )
        {
LABEL_8:
          sub_4948B1((void *)v1, 39, 0);
          return;
        }
        v3 = dword_AD470C;
        goto LABEL_16;
      }
    }
    else
    {
      if ( (v4 == 8 || v4 == 1 || v4 == 2) && v0 && byte_5D2A00[48 * *(_DWORD *)(v1 + 36 * v0 + 496) + 1] == 4 )
        goto LABEL_7;
    }
LABEL_16:
    if ( !sub_492C4E(v1, v3) )
      goto LABEL_8;
    if ( dword_AD470C == 604 )
    {
      sub_467E7F((void *)3);
      sub_43EF2B(uMaybeSelectedCharacter);
      return;
    }
    v6 = (void *)v56;
    switch ( v56 )
    {
      case 2:
      case 3:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 11:
        if ( !sub_492700((void *)v1, v4) )
          goto LABEL_8;
        if ( sub_43EE77(uMaybeSelectedCharacter) && (v6 != (void *)3 || byte_6BE3C4) )
          goto LABEL_95;
        sub_467E7F(v6);
        if ( dword_AD470C == 604 )
          sub_43F0BD(uMaybeSelectedCharacter);
        return;
      case 10:
        if ( sub_43EE77(uMaybeSelectedCharacter) )
          goto LABEL_95;
        v56 = 10;
        v7 = v1 + 6512;
        while ( 1 )
        {
          if ( !*(_DWORD *)v7 )
          {
            v8 = sub_4925E6((void *)v1);
            if ( v8 >= 0 )
              break;
          }
          ++v56;
          v7 += 4;
          if ( v56 > 15 )
            goto LABEL_33;
        }
        v9 = v56;
        byte_AD4724 = v56 + 1;
        memcpy((void *)(v1 + 36 * v8 + 532), &dword_AD470C, 0x24u);
        *(_DWORD *)(v1 + 4 * v9 + 6472) = v8 + 1;
        class03_sub_4698A6(pGame->pClass03);
LABEL_33:
        if ( v56 == 16 )
        {
          v56 = *(_DWORD *)(v1 + 6532) - 1;
          memcpy(&v50, &dword_AD470C, 0x24u);
          v10 = v1 + 36 * v56;
          *(_BYTE *)(v10 + 556) = 0;
          sub_402F07((int)&dword_AD470C);
          sub_4936E1(pParty_global, (const void *)(v10 + 532));
          v51 = 16;
          v11 = v56 + 1;
          memcpy((void *)(v10 + 532), &v50, 0x24u);
          *(_DWORD *)(v1 + 6532) = v11;
        }
        return;
      case 4:
        if ( sub_43EE77(uMaybeSelectedCharacter) )
          goto LABEL_95;
        if ( !sub_492700((void *)v1, v4) )
          goto LABEL_8;
        if ( v58 )
        {
          --v58;
          memcpy(&v50, &dword_AD470C, 0x24u);
          v12 = v1 + 36 * v58;
          *(_BYTE *)(v12 + 556) = 0;
          sub_402F07((int)&dword_AD470C);
          sub_4936E1(pParty_global, (const void *)(v12 + 532));
          v51 = 1;
          v13 = v58 + 1;
          v14 = v55 == 0;
          memcpy((void *)(v12 + 532), &v50, 0x24u);
          *(_DWORD *)(v1 + 6472) = v13;
          if ( v14 )
            return;
        }
        else
        {
          v56 = sub_4925E6((void *)v1);
          if ( v56 < 0 )
            return;
          if ( !v55 )
          {
            byte_AD4724 = 1;
            v17 = v56 + 1;
            memcpy((void *)(v1 + 36 * v56 + 532), &dword_AD470C, 0x24u);
            *(_DWORD *)(v1 + 6472) = v17;
            goto LABEL_45;
          }
          memcpy(&v50, &dword_AD470C, 0x24u);
          v15 = v1 + 36 * (v57 - 1);
          *(_BYTE *)(v15 + 556) = 0;
          sub_402F07((int)&dword_AD470C);
          sub_4936E1(pParty_global, (const void *)(v15 + 532));
          v51 = 1;
          v16 = v56 + 1;
          memcpy((void *)(v1 + 36 * v56 + 532), &v50, 0x24u);
          *(_DWORD *)(v1 + 6472) = v16;
        }
        *(_DWORD *)(v1 + 6476) = 0;
        return;
      case 0:
      case 12:
        if ( sub_43EE77(uMaybeSelectedCharacter) && dword_AD470C != 64 && dword_AD470C != 65 )
          goto LABEL_95;
        if ( !sub_492700((void *)v1, v4) )
          goto LABEL_8;
        v54 = 0;
        if ( v4 == 2 && (unsigned __int16)(*(_WORD *)(v1 + 268) & 0xFFC0)
          || v4 == 1 && sub_458244(*(_WORD *)(v1 + 266)) >= 3 )
        {
          if (dword_720010)
          {
            v19 = *(_DWORD *)(dword_720010 + 24);
            v18 = *(_DWORD *)(dword_720010 + 28);
          }
          else
          {
           v19 = pGame->pClass03->uMouseClickX;
           v18 = pGame->pClass03->uMouseClickY;
          }
          v53 = v18;
          if ( v19 >= 560 )
          {
            if ( !v55 )
            {
              if ( v58 )
              {
                --v58;
                memcpy(&v50, &dword_AD470C, 0x24u);
                v20 = v1 + 36 * v58;
                *(_BYTE *)(v20 + 556) = 0;
                sub_402F07((int)&dword_AD470C);
                sub_4936E1(pParty_global, (const void *)(v20 + 532));
                v51 = 1;
                v21 = v58 + 1;
                v22 = v56 == 12;
                memcpy((void *)(v20 + 532), &v50, 0x24u);
                *(_DWORD *)(v1 + 6472) = v21;
                if ( !v22 )
                  return;
                v23 = v50;
LABEL_73:
                v54 = v23;
                goto LABEL_74;
              }
              v24 = sub_4925E6((void *)v1);
              if ( v24 < 0 )
                return;
              byte_AD4724 = 1;
              v54 = v1 + 36 * v24 + 532;
              memcpy((void *)(v1 + 36 * v24 + 532), &dword_AD470C, 0x24u);
              *(_DWORD *)(v1 + 6472) = v24 + 1;
LABEL_71:
              class03_sub_4698A6(pGame->pClass03);
              if ( v56 != 12 )
                return;
              v23 = *(_DWORD *)v54;
              goto LABEL_73;
            }
          }
        }
        if ( !v57 )
        {
          v28 = sub_4925E6((void *)v1);
          if ( v28 < 0 )
            return;
          byte_AD4724 = 2;
          v54 = v1 + 36 * v28 + 532;
          memcpy((void *)(v1 + 36 * v28 + 532), &dword_AD470C, 0x24u);
          *(_DWORD *)(v1 + 6476) = v28 + 1;
          goto LABEL_71;
        }
        --v57;
        memcpy(&v50, &dword_AD470C, 0x24u);
        v25 = v1 + 36 * v57;
        *(_BYTE *)(v25 + 556) = 0;
        sub_402F07((int)&dword_AD470C);
        sub_4936E1(pParty_global, (const void *)(v25 + 532));
        v51 = 2;
        v26 = v57 + 1;
        v27 = v56 == 12;
        memcpy((void *)(v25 + 532), &v50, 0x24u);
        *(_DWORD *)(v1 + 6476) = v26;
        if ( v27 )
          v54 = v50;
        if ( v55 )
          *(_DWORD *)(v1 + 6472) = 0;
LABEL_74:
        if ( v54 )
          sub_494836((char *)&unk_A750F8 + 45016 * (uMaybeSelectedCharacter - 1), dword_4E421C[v54], uMaybeSelectedCharacter - 1 + 9);
        break;
      case 1:
        if ( sub_43EE77(uMaybeSelectedCharacter) )
          goto LABEL_95;
        if ( !sub_492700((void *)v1, v4) )
          goto LABEL_8;
        if ( v57 )
        {
          if ( v58 )
          {
            v49 = 0;
            v48 = 0;
            v47 = 0;
            v46 = 0;
            v45 = -1;
            v44 = 0;
            v43 = 0;
            goto LABEL_96;
          }
          --v57;
          memcpy(&v50, &dword_AD470C, 0x24u);
          v29 = v1 + 36 * v57;
          *(_BYTE *)(v29 + 556) = 0;
          sub_402F07((int)&dword_AD470C);
          sub_4936E1(pParty_global, (const void *)(v29 + 532));
          v51 = 2;
          v30 = v57 + 1;
          memcpy((void *)(v29 + 532), &v50, 0x24u);
          *(_DWORD *)(v1 + 6476) = v30;
        }
        else
        {
          v56 = sub_4925E6((void *)v1);
          if ( v56 >= 0 )
          {
            if ( v58 )
            {
              memcpy(&v50, &dword_AD470C, 0x24u);
              v31 = v1 + 36 * (v58 - 1);
              *(_BYTE *)(v31 + 556) = 0;
              sub_402F07((int)&dword_AD470C);
              sub_4936E1(pParty_global, (const void *)(v31 + 532));
              v51 = 2;
              v32 = v56 + 1;
              memcpy((void *)(v1 + 36 * v56 + 532), &v50, 0x24u);
              *(_DWORD *)(v1 + 6472) = 0;
              *(_DWORD *)(v1 + 6476) = v32;
            }
            else
            {
              byte_AD4724 = 2;
              v33 = v56 + 1;
              memcpy((void *)(v1 + 36 * v56 + 532), &dword_AD470C, 0x24u);
              *(_DWORD *)(v1 + 6476) = v33;
LABEL_45:
              class03_sub_4698A6(pGame->pClass03);
            }
          }
        }
        return;
      default:
        sub_4680ED((void *)v1, uMaybeSelectedCharacter, 0);
        return;
    }
    return;
  }
  if (dword_720010)
  {
    v35 = *(_DWORD *)(dword_720010 + 24);
    v34 = *(_DWORD *)(dword_720010 + 28);
    v53 = *(_DWORD *)(dword_720010 + 28);
    v52 = v35;
  }
  else
  {
   v35 = pGame->pClass03->uMouseClickX;
   v34 = pGame->pClass03->uMouseClickY;
  }
  v36 = v35 + dword_5059A8[v34];
  if ( !(*(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * v36) & 0xFFFF) )
  {
    v37 = *(_DWORD *)(v1 + 6480);
    if ( v37 )
    {
      sub_4936E1(pParty_global, (const void *)(v1 + 36 * v37 + 496));
      sub_402F07(v1 + 36 * *(_DWORD *)(v1 + 6480) + 496);
      *(_DWORD *)(v1 + 6480) = 0;
    }
    return;
  }
  v39 = (*(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * v36) & 0xFFFF) - 1;
  v40 = v1 + 36 * v39;
  v54 = v40;
  v38 = v40 + 532;
  v41 = *(_DWORD *)v38 == 604;
  v56 = (unsigned __int8)byte_5D2A00[48 * *(_DWORD *)v38];
  if ( v41 )
  {
    if ( byte_6BE3C4 )
    {
LABEL_95:
      v49 = 0;
      v48 = 0;
      v47 = 0;
      v46 = 0;
      v45 = -1;
      v44 = 0;
      v43 = 0;
LABEL_96:
      AudioPlayer_sub_4AA306(pAudioPlayer, 27, v43, v44, v45, v46, v47, v48, v49);
      return;
    }
    sub_43F0BD(uMaybeSelectedCharacter);
  }
  if ( dword_50C9A0 )
  {
    *(_BYTE *)(*(_DWORD *)(dword_507BD4 + 28) + 8) &= 0x7Fu;
    *(_WORD *)(*(_DWORD *)(dword_507BD4 + 28) + 4) = uMaybeSelectedCharacter - 1;
    v42 = v56;
    *(_DWORD *)(*(_DWORD *)(dword_507BD4 + 28) + 12) = v39;
    *(_WORD *)(*(_DWORD *)(dword_507BD4 + 28) + 6) = v42;
    dword_50C9A4 = v38;
    dword_50C9A0 = 0;
    if ( dword_50CBD0[0] )
      dword_50CBD0[0] = dword_50CBD0[3] != 0;
    sub_469903(pGame->pClass03, "MICON1");
    dword_50C9D4 = 0;
    dword_50C9D0 = 113;
    dword_50C9D8 = 256;
  }
  else
  {
    if ( !dword_50C9A4 )
    {
      sub_4936E1(pParty_global, (const void *)v38);
      *(_DWORD *)(v1 + 4 * *(_BYTE *)(v54 + 556) + 6468) = 0;
      sub_402F07(v38);
    }
  }
}

//----- (004698D8) --------------------------------------------------------
void __stdcall sub_4698D8(int a1)
{
  sub_469903(pGame->pClass03, pClass40->pItems[a1].pIconName);
}

//----- (004698F6) --------------------------------------------------------
void __thiscall sub_4698F6(int this)
{
  sub_469903(this, (const char *)(this + 245));
}

//----- (00469AE4) --------------------------------------------------------
LONG __thiscall sub_469AE4(int this)
{
  int v1; // esi@1
  LONG result; // eax@2
  LONG v3; // ecx@2
  struct tagPOINT Point; // [sp+Ch] [bp-8h]@2

  v1 = this;
  *(_DWORD *)(this + 8) = 1;
  if (dword_720010)
  {
    v3 = *(_DWORD *)(dword_720010 + 24);
    Point.x = *(_DWORD *)(dword_720010 + 24);
    result = *(_DWORD *)(dword_720010 + 28);
  }
  else
  {
    GetCursorPos(&Point);
    if ( pD3DRenderer->dword_040058 )
      ScreenToClient(hWnd_global, &Point);
    result = Point.y;
    v3 = Point.x;
  }
  *(_DWORD *)(v1 + 264) = v3;
  *(_DWORD *)(v1 + 268) = result;
  if ( pD3DRenderer->dword_040058 )
    goto LABEL_16;
  if (dword_720010)
    goto LABEL_24;
  if ( v3 < 0 )
    v3 = 0;
  if ( result < 0 )
    result = 0;
  if ( v3 > 639 )
    v3 = 639;
  if ( result > 479 )
  {
    result = 479;
LABEL_16:
    if (dword_720010)
      goto LABEL_24;
    if ( pD3DRenderer->dword_040058 && (v3 < 0 || result < 0 || v3 > 639 || result > 479) )
      goto LABEL_23;
  }
  if ( *(_DWORD *)(v1 + 12) )
LABEL_23:
    *(_DWORD *)(v1 + 4) = 0;
LABEL_24:
  *(_DWORD *)(v1 + 8) = 0;
  return result;
}

//----- (00469BE6) --------------------------------------------------------
void __thiscall sub_469BE6(int this)
{
  int v1; // esi@1

  v1 = this;
  *(_DWORD *)(this + 4) = 0;
  if ( !*(_DWORD *)(this + 48) )
    *(_DWORD *)(this + 48) = sub_469C0D(this);
  if ( !*(_DWORD *)(v1 + 56) )
    *(_DWORD *)(v1 + 56) = sub_469C0D(v1);
}

//----- (00469C0D) --------------------------------------------------------
void *__thiscall sub_469C0D(int this)
{
  return malloc(4 * *(_WORD *)(*(_DWORD *)(this + 36) != -1 ? 72 * *(_DWORD *)(this + 36) + 7145548 + 0x18 : 24)
                  * *(_WORD *)(*(_DWORD *)(this + 36) != -1 ? 72 * *(_DWORD *)(this + 36) + 7145548 + 0x1A : 26));
}

//----- (00469CC2) --------------------------------------------------------
void __thiscall sub_469CC2(int this)
{
  if ( *(_DWORD *)(this + 16) )
    *(_DWORD *)(this + 4) = 0;
}

//----- (00469CCD) --------------------------------------------------------
void __thiscall sub_469CCD(int this)
{
  int v1; // esi@1
  char v2; // zf@6
  signed int v3; // eax@6
  signed int v4; // ecx@6
  int v5; // edx@21
  int v6; // ebx@21
  int v7; // edi@21
  int v8; // eax@29
  char v9; // zf@29
  int v10; // eax@31

  v1 = this;
  if ( *(_DWORD *)(this + 16) )
  {
    if ( !*(_DWORD *)(this + 8) )
    {
      if ( *(_DWORD *)(this + 4) )
      {
        if ( !*(_DWORD *)(this + 12) )
          sub_469AE4(pGame->pClass03);
      }
    }
    v2 = *(_DWORD *)(v1 + 12) == 0;
    v3 = *(_DWORD *)(v1 + 264);
    v4 = *(_DWORD *)(v1 + 268);
    *(_BYTE *)(v1 + 244) = 1;
    if ( !v2 )
      goto LABEL_12;
    if ( pD3DRenderer->dword_040058 )
    {
      if ( v3 < 0 || v4 < 0 || v3 > 639 || v4 > 479 )
      {
LABEL_12:
        *(_BYTE *)(v1 + 244) = 0;
        return;
      }
    }
    else
    {
      if ( v3 < 0 )
        v3 = 0;
      if ( v4 < 0 )
        v4 = 0;
      if ( v3 > 639 )
        v3 = 639;
      if ( v4 > 479 )
        v4 = 479;
    }
    v5 = v1 + 228;
    v7 = v3 + *(_DWORD *)(v1 + 88);
    v6 = v4 + *(_DWORD *)(v1 + 92);
    *(_DWORD *)(v1 + 232) = v4;
    *(_DWORD *)(v1 + 228) = v3;
    *(_DWORD *)(v1 + 236) = v7;
    *(_DWORD *)(v1 + 240) = v6;
    if ( v3 < 0 )
      *(_DWORD *)v5 = 0;
    if ( v4 < 0 )
      *(_DWORD *)(v1 + 232) = 0;
    if ( v7 > 640 )
      *(_DWORD *)(v1 + 236) = 640;
    if ( v6 > 480 )
      *(_DWORD *)(v1 + 240) = 480;
    v8 = *(_DWORD *)(v1 + 236);
    *(_DWORD *)(v1 + 4) = 0;
    *(_DWORD *)(v1 + 204) = v8 - *(_DWORD *)v5;
    v9 = *(_DWORD *)(v1 + 20) == 0;
    *(_DWORD *)(v1 + 208) = *(_DWORD *)(v1 + 240) - *(_DWORD *)(v1 + 232);
    if ( !v9 )
    {
     if (pGame->pClass03->ptr_000090)
        v10 = 2 * *(_DWORD *)((char *)pGame->pClass03 + 88);
      else
        v10 = 0;
      sub_4A6DF5(*(_DWORD *)(v1 + 48), v10, v1 + 196, pD3DRenderer->pTargetSurface, pD3DRenderer->uTargetSurfacePitch, v1 + 228);
      *(_DWORD *)(v1 + 20) = 0;
    }
  }
}

//----- (00469E1C) --------------------------------------------------------
void __thiscall sub_469E1C(int this)
{
  *(_DWORD *)(this + 4) = 1;
}

//----- (00469E24) --------------------------------------------------------
int __thiscall sub_469E24(int this)
{
  int result; // eax@1
  int v2; // esi@1

  v2 = this;
  result = *(_DWORD *)(this + 60);
  if ( result )
  {
    result = operator_delete(result, *(_DWORD *)(this + 60));
    *(_DWORD *)(v2 + 60) = 0;
  }
  return result;
}

//----- (00469EA4) --------------------------------------------------------
void __thiscall sub_469EA4_LooksLikeDrawPickedItem(int this)
{
  int v1; // esi@1
  int v2; // edi@2
  int v3; // eax@2
  signed int v4; // eax@3
  signed int v5; // ecx@3
  int v6; // ebx@5
  int v7; // ecx@15
  int v8; // eax@22
  int v9; // ecx@25
  int v10; // eax@26
  int v11; // ebx@26
  int v12; // edx@27
  int v13; // edx@29
  int v14; // ebx@29
  int v15; // eax@37
  int v16; // [sp+Ch] [bp-1Ch]@5
  int v17; // [sp+10h] [bp-18h]@5
  int v18; // [sp+14h] [bp-14h]@25
  int v19; // [sp+18h] [bp-10h]@25
  int v20; // [sp+1Ch] [bp-Ch]@27
  int v21; // [sp+20h] [bp-8h]@15
  int v22; // [sp+20h] [bp-8h]@28
  int v23; // [sp+24h] [bp-4h]@12
  int v24; // [sp+24h] [bp-4h]@25

  v1 = this;
  if ( dword_AD470C )
  {
   v3 = class17_LoadTexture(pClass17_Icons_LOD, pClass40->pItems[12 * dword_AD470C].pIconName, 2);
    v2 = v3 != -1 ? 72 * v3 + 7145548 : 0;
    if (dword_720010)
    {
      v5 = *(_DWORD *)(dword_720010 + 24);
      v4 = *(_DWORD *)(dword_720010 + 28);
    }
    else
    {
     v5 = pGame->pClass03->uMouseClickX;
     v4 = pGame->pClass03->uMouseClickY;
    }
    v6 = v4;
    v16 = v5;
    v17 = v4;
    if ( v5 <= 639 )
    {
      if ( v4 <= 479 )
      {
        if ( v5 < 0 )
          v16 = 0;
        if ( v4 < 0 )
        {
          v6 = 0;
          v17 = 0;
        }
        if ( *(_WORD *)(v2 + 24) + v16 <= 640 )
          v23 = *(_WORD *)(v2 + 24);
        else
          v23 = 640 - v16;
        if ( *(_WORD *)(v2 + 26) + v6 <= 480 )
        {
          v21 = *(_WORD *)(v2 + 26);
          v7 = *(_WORD *)(v2 + 26);
        }
        else
        {
          v7 = 480 - v6;
          v21 = 480 - v6;
        }
        if ( !*(_DWORD *)(v1 + 60)
          || v16 != *(_DWORD *)(v1 + 64)
          || v6 != *(_DWORD *)(v1 + 68)
          || v16 + v23 != *(_DWORD *)(v1 + 72)
          || v6 + v7 != *(_DWORD *)(v1 + 76) )
        {
          v8 = *(_DWORD *)(v1 + 60);
          if ( v8 )
            operator_delete(v8, *(_DWORD *)(v1 + 60));
          compile_error;//*(_DWORD *)(v1 + 60) = operator new(2 * *(_WORD *)(v2 + 26) * *(_WORD *)(v2 + 24));
          *(_DWORD *)(v1 + 64) = v16;
          *(_DWORD *)(v1 + 72) = v16 + v23;
          *(_DWORD *)(v1 + 68) = v6;
          *(_DWORD *)(v1 + 76) = v6 + v21;
        }
        v9 = *(_DWORD *)(v1 + 68);
        v24 = *(_DWORD *)(v1 + 60);
        v19 = pD3DRenderer->pTargetSurface;
        v18 = pD3DRenderer->uTargetSurfacePitch;
        if ( v9 < *(_DWORD *)(v1 + 76) )
        {
          v11 = *(_DWORD *)(v1 + 72);
          v10 = pD3DRenderer->uTargetSurfacePitch * v9;
          do
          {
            v12 = *(_DWORD *)(v1 + 64);
            v20 = *(_DWORD *)(v1 + 64);
            if ( v12 < v11 )
            {
              v22 = v19 + 2 * (v10 + v12);
              do
              {
                v13 = v22;
                v14 = v24;
                ++v20;
                v22 += 2;
                v24 += 2;
                *(_WORD *)v14 = *(_WORD *)v13;
                v11 = *(_DWORD *)(v1 + 72);
              }
              while ( v20 < v11 );
            }
            v10 += v18;
            ++v9;
          }
          while ( v9 < *(_DWORD *)(v1 + 76) );
          v6 = v17;
        }
        if ( byte_AD4720 & 2 )
        {
          sub_4A6776(pD3DRenderer, v16, v6, v2);
        }
        else
        {
          if ( byte_AD4720 & 1 )
            CD3DRenderer_DrawTransparentTexture(pD3DRenderer, v16, v6, v2);
          else
            sub_4A68EF(pD3DRenderer, v16, v6, v2);
        }
      }
    }
  }
  else
  {
    v15 = *(_DWORD *)(this + 60);
    if ( v15 )
    {
      operator_delete(v15, *(_DWORD *)(this + 60));
      *(_DWORD *)(v1 + 60) = 0;
    }
  }
}

//----- (0046A0A1) --------------------------------------------------------
int __thiscall sub_46A0A1(void *this)
{
  double v1; // st7@3
  int v3; // [sp-4h] [bp-8h]@5

  if ( dword_6BE360 == 1 )
  {
    if ( pD3DRenderer->dword_040088 )
      v1 = *(float *)(pGame->class08_obj + 196);
    else
      v1 = pCamera->flt_00001C;
    v3 = (signed __int64)v1;
  }
  else
  {
    v3 = pStruct9_global->dword_000014;
  }
  return sub_45281E(pClass59_global, (int)((char *)this - class28_global.dword_000028), v3) - pClass59_global->uNumTableEntries;
}

//----- (0046A0F6) --------------------------------------------------------
int __thiscall sub_46A0F6(void *this)
{
  double v1; // st7@3
  int v3; // [sp-4h] [bp-8h]@5

  if ( dword_6BE360 == 1 )
  {
    if ( pD3DRenderer->dword_040088 )
      v1 = *(float *)(pGame->class08_obj + 196);
    else
      v1 = pCamera->flt_00001C;
    v3 = (signed __int64)v1;
  }
  else
  {
    v3 = pStruct9_global->dword_000014;
  }
  return sub_45281E(pClass59_global, (int)((char *)this - class28_global.dword_00002C), v3) - pClass59_global->uNumTableEntries;
}

//----- (0046A14B) --------------------------------------------------------
char __cdecl sub_46A14B()
{
  signed int v0; // eax@2
  SHORT v1; // ax@2
  int v2; // ebx@5
  int v3; // esi@5
  unsigned int v4; // edx@7
  int v5; // edi@7
  int v6; // eax@8
  int v7; // ecx@8
  int v8; // ecx@17
  signed int v10; // ebx@22
  int *v11; // esi@22
  int i; // edi@23
  int v13; // edx@24
  int v14; // ecx@24
  int j; // esi@28
  int v17; // [sp+4h] [bp-1Ch]@29
  int v18; // [sp+8h] [bp-18h]@5
  unsigned int v19; // [sp+Ch] [bp-14h]@5
  int v20; // [sp+10h] [bp-10h]@8
  int v21; // [sp+14h] [bp-Ch]@5
  int v22; // [sp+18h] [bp-8h]@7
  int v23; // [sp+1Ch] [bp-4h]@4

  if ( pD3DRenderer->dword_040088 )
  {
    v1 = GetAsyncKeyState(17);
    sub_44EB12(pGame, (v1 & 0x8001) != 0, (int)&dword_F93E6C, (int)&dword_F93E58);
    v0 = sub_4C1BF1(pGame->class05_obj);
    if ( v0 != -1 )
      LOBYTE(v0) = sub_46A334((unsigned __int16)v0, (signed int)(unsigned __int16)v0 >> 3);
    return v0;
  }
  v23 = 0;
  v0 = (struct_576FE8.dword_000018 + struct_576FE8.dword_000010) >> 1;
  if ( struct_576FE8.dword_000014 >= struct_576FE8.dword_00001C )
    goto LABEL_21;
  v2 = v0 - 50;
  v0 += 50;
  v3 = 640 * struct_576FE8.dword_000014;
  v18 = v2;
  v21 = v0;
  v19 = ((unsigned int)(struct_576FE8.dword_00001C - struct_576FE8.dword_000014 - 1) >> 1) + 1;
  do
  {
    if ( v2 >= v21 )
      goto LABEL_20;
    v0 = pD3DRenderer->pActiveZBuffer + 4 * (v3 + v2);
    v22 = pD3DRenderer->pActiveZBuffer + 4 * (v3 + v2);
    v5 = 4 * v23;
    v4 = ((unsigned int)(v21 - v2 - 1) >> 1) + 1;
    do
    {
      v7 = 0;
      v6 = *(_DWORD *)v0 & 0xFFFF;
      v20 = 0;
      if ( v5 > 0 )
      {
        do
        {
          if ( dword_7207F0[v7] == v6 )
            break;
          ++v7;
          v20 = v7;
        }
        while ( v7 < v23 );
      }
      if ( (v6 & 7) == 5 )
      {
        v17 = (unsigned int)v6 >> 3;
        if ( (*(_DWORD *)v22 >> 16)
           - (signed int)*(_WORD *)((char *)&pDecorationDescriptionList->pDescriptions[array_6836D0[((unsigned int)v6 >> 3)].uDecorationDescriptionID] + 68) > 512 )
          goto LABEL_18;
      }
      else
      {
        if ( *(_DWORD *)v22 > 0x2000000u )
          goto LABEL_18;
      }
      if ( v20 == v23 )
      {
        if ( v5 < 400 )
        {
          ++v23;
          v5 += 4;
          v8 = *(_DWORD *)v22;
          *(int *)((char *)&dword_7207EC + v5) = v6;
          *(int *)((char *)&dword_72065C + v5) = v8;
        }
      }
LABEL_18:
      v0 = v22 + 8;
      --v4;
      v22 += 8;
    }
    while ( v4 );
    v2 = v18;
LABEL_20:
    v3 += 1280;
  }
  while ( v19-- != 1 );
LABEL_21:
  if ( v23 > 0 )
  {
    v11 = dword_720660;
    v10 = 1;
    do
    {
      for ( i = v10; i < v23; ++i )
      {
        v13 = *v11;
        v14 = dword_720660[i];
        if ( v14 < *v11 )
        {
          *v11 = v14;
          dword_720660[i] = v13;
        }
      }
      ++v10;
      ++v11;
      v0 = v10 - 1;
    }
    while ( v10 - 1 < v23 );
  }
  for ( j = 0; j < v23; ++j )
  {
    LOBYTE(v0) = sub_46A334(dword_720660[j] & 0xFFFF, v17);
    if ( !(_BYTE)v0 )
      break;
  }
  return v0;
}

//----- (0046A334) --------------------------------------------------------
char __fastcall sub_46A334(int a1, int a2)
{
  int v2; // edx@1
  int v4; // eax@9
  int v5; // ecx@9
  __int16 v6; // ax@11
  int v7; // eax@16
  __int16 v8; // ax@19
  __int16 *v9; // esi@19
  int v10; // eax@22
  int v11; // ecx@22
  __int16 v12; // ax@23
  int v13; // edi@23
  int v14; // esi@23
  __int16 v15; // ax@33
  const char *v16; // eax@34
  int v17; // eax@36
  int v18; // edi@36
  int v19; // eax@39
  int v20; // esi@39
  int v21; // ecx@40
  char v22; // [sp-18h] [bp-2Ch]@5
  const CHAR *v23; // [sp-14h] [bp-28h]@5
  int v24; // [sp-10h] [bp-24h]@5
  int v25; // [sp-Ch] [bp-20h]@5
  const char *v26; // [sp-8h] [bp-1Ch]@5
  int v27; // [sp-4h] [bp-18h]@5
  char v28; // [sp+8h] [bp-Ch]@5
  char *v29; // [sp+Ch] [bp-8h]@1
  int v30; // [sp+13h] [bp-1h]@5

  v29 = (char *)a2;
  v2 = a1;
  switch ( a1 & 7 )
  {
    case 2:
      v18 = a1 >> 3;
      v29 = (char *)(a1 >> 3);
      v17 = 112 * (a1 >> 3);
      if ( *(_BYTE *)(56 * array_665230[a1 >> 3].uObjectDescriptionID + pObjectDescriptionList->pDescriptions + 38) & 0x10
        || v18 >= 1000
        || !array_665230[a1 >> 3].uObjectDescriptionID)
        return 1;
      v20 = (int)((char *)&unk_665254 + v17);
      v19 = 48 * *(_DWORD *)((char *)&unk_665254 + v17);
      if ( byte_5D2A00[v19] == 18 )
      {
        sub_420C05(*(_DWORD *)(v20 + 12), 0);
        struct_576FE8.dword_000044 = 1;
        v21 = v18;
      }
      else
      {
        if ( dword_AD470C )
          return 1;
        v27 = *(int *)((char *)dword_5D29EC + v19);
        sprintfex(pStringBuffer, pGlobalTXT_LocalizationStrings[471], v27);
        sub_44C175(pStringBuffer, 2);
        if ( *(_DWORD *)v20 == 506 )
          sub_449B7E((int)byte_ACD71D, 184, 1);
        if ( *(_DWORD *)v20 == 455 )
          sub_449B7E((int)byte_ACD71D, 185, 1);
        if ( !Party_AddItem(pParty_global, v20) )
          sub_4936E1(pParty_global, (const void *)v20);
        v21 = (int)v29;
      }
      sub_42F933(v21);
      break;
    case 3:
      v13 = a1 >> 3;
      v14 = (int)((char *)pActors + 836 * (a1 >> 3));
      v12 = *(_WORD *)(v14 + 176);
      if ( v12 == 4 || v12 == 17 )
        return 1;
      if ( v12 == 5 )
      {
        sub_426A5A((int)((char *)pActors + 836 * (a1 >> 3)));
      }
      else
      {
        if ( !Actor_sub_40104C(v14, 0) )
        {
          if ( !(*(_BYTE *)(v14 + 38) & 8) )
          {
            if ( sub_40894B(v14) )
            {
              sub_404030(v13, 4, 0, 0);
              if ( *(_WORD *)(v14 + 32) )
              {
                if ( dword_50CBD0[0] < 40 )
                {
                  dword_50CBD0[3 * dword_50CBD0[0] + 1] = 161;
                  dword_50CBD0[3 * dword_50CBD0[0] + 2] = v13;
                  dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
                }
              }
              else
              {
                v15 = pNPCStats->word_017F5A[*(_DWORD *)(v14 + 708)];
                if ( v15 )
                {
                  v16 = *(const char **)&dword_739E74[4 * (unsigned __int16)v15];
                  if ( v16 )
                  {
                    pParty_global->dword_007778 |= 2;
                    strcpy(&byte_5B0938, v16);
                    sub_4451A8(0, 0, 0);
                  }
                }
              }
            }
          }
        }
      }
      break;
    case 5:
      v9 = &array_6836D0[(a1 >> 3)];
      v8 = v9[11];
      if ( v8 )
      {
        sub_44684A_LooksLikeEventProcessor(v8, a1, 1);
        *((_BYTE *)v9 + 2) |= 8u;
      }
      else
      {
        if ( !sub_44C2F4(&array_6836D0[(a1 >> 3)]) )
          return 1;
        v10 = v9[14];
        v27 = 1;
        v11 = (unsigned __int8)global_5E4C90.byte_000000[v10];
        dword_5C3420 = (int)v9;
        sub_44684A_LooksLikeEventProcessor(v11 + 380, 0, 1);
        dword_5C3420 = 0;
      }
      break;
    default:
      if ( (a1 & 7) != 6 )
      {
        v27 = 2020;
        v26 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Mouse.cpp";
        v29 = &v22;
        sub_40E2C8(&v22, "Warning: Invalid ID reached!", (int)&v30);
        sub_467834(&v28, v22, v23, v24, v25, v26, v27);
        return 1;
      }
      if ( dword_6BE360 != 1 )
      {
        if ( a1 >> 9 >= pClass51_global->uNumBModels
          || (v7 = *(_DWORD *)(188 * (a1 >> 9) + pClass51_global->pBModels + 84) + 308 * ((a1 >> 3) & 0x3F),
              *(_BYTE *)(v7 + 30) & 0x10)
          || (v6 = *(_WORD *)(v7 + 292), !v6) )
          return 1;
LABEL_13:
        sub_44684A_LooksLikeEventProcessor(v6, v2, 1);
        return 0;
      }
      v4 = dword_6BE644 + 96 * (a1 >> 3);
      v5 = *(_DWORD *)(v4 + 44);
      if ( !(v5 & 0x2000000) )
      {
        sub_44C1D0();
        return 1;
      }
      if ( v5 & 0x100000 || (v6 = *(_WORD *)(dword_6BE64C + 36 * *(_WORD *)(v4 + 72) + 26), !v6) )
        return 1;
      if ( dword_4E28F8 != 19 )
        goto LABEL_13;
      break;
  }
  return 0;
}

//----- (0046A6AC) --------------------------------------------------------
int __fastcall sub_46A6AC(int a1, int a2, signed int a3)
{
  int result; // eax@2
  int v4; // edx@3
  unsigned int v5; // ebx@6
  int v6; // esi@6
  __int16 v7; // ax@9
  signed int v8; // edi@9
  int i; // eax@14
  int v10; // ecx@19
  int v12; // [sp+0h] [bp-18h]@1
  int v13; // [sp+4h] [bp-14h]@3
  unsigned int v14; // [sp+8h] [bp-10h]@4
  int v15; // [sp+Ch] [bp-Ch]@1
  int v16; // [sp+10h] [bp-8h]@4
  int v17; // [sp+14h] [bp-4h]@3

  v12 = a2;
  v15 = a1;
  if ( pD3DRenderer->dword_040088 )
  {
    result = sub_46A7C8(a1, a2, a3);
  }
  else
  {
    v17 = 0;
    v4 = struct_576FE8.dword_000010;
    v13 = struct_576FE8.dword_000018;
    if (struct_576FE8.dword_000014 < struct_576FE8.dword_00001C)
    {
     v16 = pD3DRenderer->pActiveZBuffer + 4 * (struct_576FE8.dword_000010 + 640 * struct_576FE8.dword_000014);
     v14 = ((unsigned int)(struct_576FE8.dword_00001C - struct_576FE8.dword_000014 - 1) >> 1) + 1;
      do
      {
        if ( v4 < v13 )
        {
          v6 = v16;
          v5 = ((unsigned int)(v13 - v4 - 1) >> 1) + 1;
          do
          {
            if ( (*(_BYTE *)v6 & 7) == 3 )
            {
              if ( *(_DWORD *)v6 <= a3 << 16 )
              {
                v8 = (signed int)(unsigned __int16)*(_DWORD *)v6 >> 3;
                v7 = pActors[v8].word_0000B0;
                if ( v7 != 5 )
                {
                  if ( v7 != 4 )
                  {
                    if ( v7 != 11 )
                    {
                      if ( v7 != 17 )
                      {
                        if ( v7 != 19 )
                        {
                          for ( i = 0; i < v17; ++i )
                          {
                            if ( *(_DWORD *)(v15 + 4 * i) == v8 )
                              break;
                          }
                          if ( i == v17 )
                          {
                            if ( i < v12 - 1 )
                            {
                              v10 = v17++;
                              *(_DWORD *)(v15 + 4 * v10) = v8;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            v6 += 8;
            --v5;
          }
          while ( v5 );
        }
        v16 += 5120;
      }
      while ( v14-- != 1 );
    }
    result = v17;
  }
  return result;
}

//----- (0046A7C8) --------------------------------------------------------
int __fastcall sub_46A7C8(int a1, int a2, signed int a3)
{
  unsigned int v3; // eax@2
  int v4; // ecx@2
  int v5; // eax@2
  __int16 v6; // ax@4
  unsigned int v7; // eax@4
  unsigned int v8; // edi@4
  float v9; // ST00_4@9
  int v10; // ecx@11
  int v12; // [sp+10h] [bp-14h]@1
  int v13; // [sp+14h] [bp-10h]@1
  int v14; // [sp+18h] [bp-Ch]@1
  int v15; // [sp+1Ch] [bp-8h]@1
  int v16; // [sp+20h] [bp-4h]@1

  v13 = a1;
  v14 = a2;
  v15 = 0;
  v16 = 0;
  v12 = sub_4A1E9D();
  if ( v12 > 0 )
  {
    do
    {
      v5 = sub_4A1EA3(v16);
      v4 = array_512250[v5].dword_000010;
      v3 = (unsigned __int16)array_512250[v5].dword_000010;
      if ( (v3 & 7) == 3 )
      {
        if ( v4 <= (unsigned int)(a3 << 16) )
        {
          v7 = v3 >> 3;
          v8 = v7;
          v6 = pActors[v7].word_0000B0;
          if ( v6 != 5 )
          {
            if ( v6 != 4 )
            {
              if ( v6 != 11 )
              {
                if ( v6 != 19 )
                {
                  if ( v6 != 17 )
                  {
                    v9 = (double)a3;
                    if ( sub_4C1930(pGame->class05_obj, v9, v16) )
                    {
                      if ( v15 < v14 - 1 )
                      {
                        v10 = v15++;
                        *(_DWORD *)(v13 + 4 * v10) = v8;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      ++v16;
    }
    while ( v16 < v12 );
  }
  return v15;
}

//----- (0046A89E) --------------------------------------------------------
int __fastcall sub_46A89E(int a1, int a2, signed int a3)
{
  signed int v3; // edi@1
  int v4; // esi@2
  int v5; // eax@3
  unsigned int v6; // ecx@3
  int v7; // ebx@3
  int v8; // ebx@3
  int v9; // edx@4
  unsigned int v10; // edx@6
  unsigned int v11; // edx@8
  __int16 v12; // ax@10
  int v13; // ecx@15
  int v15; // [sp+4h] [bp-18h]@1
  int v16; // [sp+8h] [bp-14h]@1
  int v17; // [sp+Ch] [bp-10h]@3
  int v18; // [sp+10h] [bp-Ch]@3
  int v19; // [sp+18h] [bp-4h]@1

  v3 = 0;
  v15 = a2;
  v16 = a1;
  v19 = 0;
  if ( (signed int)uNumActors > 0 )
  {
    v4 = &pActors[0].word_0000B0;
    do
    {
      v8 = abs(*(_WORD *)(v4 - 34) - pParty_global->sPartyPosX);
      v17 = abs(*(_WORD *)(v4 - 32) - pParty_global->sPartyPosY);
      v18 = abs(*(_WORD *)(v4 - 30) - pParty_global->sPartyPosZ);
      v5 = v8;
      v7 = v17;
      v6 = v18;
      if ( v5 < v17 )
      {
        v9 = v5;
        v5 = v17;
        v7 = v9;
      }
      if ( v5 < v18 )
      {
        v10 = v5;
        v5 = v18;
        v6 = v10;
      }
      if ( v7 < (signed int)v6 )
      {
        v11 = v6;
        v6 = v7;
        v7 = v11;
      }
      if ( (signed int)(((unsigned int)(11 * v7) >> 5) + (v6 >> 2) + v5) <= a3 )
      {
        v12 = *(_WORD *)v4;
        if ( *(_WORD *)v4 != 5 )
        {
          if ( v12 != 4 )
          {
            if ( v12 != 11 )
            {
              if ( v12 != 19 )
              {
                if ( v12 != 17 )
                {
                  v13 = v19++;
                  *(_DWORD *)(v16 + 4 * v13) = v3;
                  if ( v19 >= v15 - 1 )
                    break;
                }
              }
            }
          }
        }
      }
      ++v3;
      v4 += 836;
    }
    while ( v3 < (signed int)uNumActors );
  }
  return v19;
}

//----- (0046A99B) --------------------------------------------------------
int __cdecl sub_46A99B()
{
  signed int v0; // eax@1
  int v1; // edx@1
  int v2; // ebx@1
  int v3; // esi@1
  int v4; // ecx@1
  int v5; // ecx@2
  int v6; // eax@3
  int v7; // ecx@3
  int v8; // edx@5
  int v9; // edi@6
  unsigned __int8 v10; // zf@14
  char v11; // sf@14
  char v12; // of@14
  signed int v14; // ebx@19
  int v15; // esi@19
  int i; // edi@20
  int v17; // ecx@21
  int v18; // edi@26
  unsigned int v19; // ecx@27
  int v20; // esi@27
  int v21; // eax@32
  void *v22; // ecx@33
  char *v23; // eax@35
  const char *v24; // ecx@36
  __int16 v25; // ax@43
  __int16 *v26; // ecx@43
  __int16 *v27; // edi@43
  int v28; // [sp+Ch] [bp-18h]@1
  int v29; // [sp+14h] [bp-10h]@2
  int v30; // [sp+18h] [bp-Ch]@1
  signed int v31; // [sp+1Ch] [bp-8h]@3
  int v32; // [sp+20h] [bp-4h]@1

  v2 = 0;
  v4 = (struct_576FE8.dword_00001C + struct_576FE8.dword_000014) >> 1;
  v3 = (struct_576FE8.dword_000010 + struct_576FE8.dword_000018) >> 1;
  v1 = v4 - 50;
  v32 = 0;
  v0 = 100;
  v30 = v4 - 50;
  v28 = v4 + 50;
  if ( v4 - 50 >= v4 + 50 )
    return 0;
  v5 = 640 * v1;
  v29 = 640 * v1;
  while ( 2 )
  {
    v31 = 100;
    v6 = pD3DRenderer->pActiveZBuffer + 4 * (v3 + v5 - v0 / 2);
    v7 = 4 * v2;
    while ( 1 )
    {
      v8 = *(_DWORD *)v6;
      --v31;
      if ( *(_DWORD *)v6 <= 0x2000000u )
      {
        v9 = 0;
        if ( v7 > 0 )
        {
          do
          {
            if ( dword_7201B0[v9] == (unsigned __int16)v8 )
              break;
            ++v9;
          }
          while ( v9 < v2 );
        }
        if ( v9 == v2 )
        {
          if ( v8 & 7 )
          {
            *(_DWORD *)&dword_720020[v7] = v8;
            *(int *)((char *)dword_7201B0 + v7) = (unsigned __int16)v8;
            v7 += 4;
            ++v2;
            v32 = v2;
            if ( v7 == 396 )
            {
              v12 = 0;
              v10 = v2 == 0;
              v11 = v2 < 0;
              goto LABEL_18;
            }
          }
        }
      }
      if ( !v31 )
        break;
      v6 += 4;
    }
    v0 = -1;
    ++v30;
    v5 = v29 + 640;
    v29 += 640;
    if ( v30 < v28 )
      continue;
    break;
  }
  v12 = 0;
  v10 = v2 == 0;
  v11 = v2 < 0;
  if ( !v2 )
    return 0;
LABEL_18:
  if ( !((unsigned __int8)(v11 ^ v12) | v10) )
  {
    v15 = (int)dword_720020;
    v14 = 1;
    do
    {
      for ( i = v14; i < v32; ++i )
      {
        v17 = *(_DWORD *)&dword_720020[4 * i];
        if ( v17 < *(_DWORD *)v15 )
        {
          *(_DWORD *)&dword_720020[4 * i] = *(_DWORD *)v15;
          *(_DWORD *)v15 = v17;
        }
      }
      ++v14;
      v15 += 4;
    }
    while ( v14 - 1 < v32 );
    v2 = v32;
  }
  v18 = 0;
  if ( v2 <= 0 )
    return 0;
  while ( 1 )
  {
    v20 = *(_DWORD *)&dword_720020[4 * v18] & 0xFFFF;
    v19 = (*(_DWORD *)&dword_720020[4 * v18] & 0xFFFFu) >> 3;
    if ( (dword_720020[4 * v18] & 7) == 2 )
    {
      if ( v19 >= 0x3E8 )
        return 0;
      if ( !(byte_66524A[112 * v19] & 0x10) )
      {
        v23 = (char *)sub_456499((char *)&unk_665254 + 112 * v19);
LABEL_36:
        v24 = v23;
        goto LABEL_51;
      }
      goto LABEL_41;
    }
    if ( (dword_720020[4 * v18] & 7) == 3 )
    {
      if ( v19 >= 0xBB8 )
        return 0;
      v24 = (char *)pActors + 836 * v19;
      goto LABEL_51;
    }
    if ( (dword_720020[4 * v18] & 7) == 5 )
      break;
    if ( (dword_720020[4 * v18] & 7) == 6 )
    {
      if ( dword_6BE360 == 1 )
      {
        v21 = dword_6BE644 + 96 * v19;
        if ( !(*(_BYTE *)(v21 + 47) & 2) )
          goto LABEL_41;
        v22 = (void *)*(_WORD *)(dword_6BE64C + 36 * *(_WORD *)(v21 + 72) + 26);
      }
      else
      {
        if ( (*(_DWORD *)&dword_720020[4 * v18] & 0xFFFFu) >> 9 >= pClass51_global->uNumBModels )
          goto LABEL_41;
        v22 = (void *)*(_WORD *)(*(_DWORD *)(188 * ((*(_DWORD *)&dword_720020[4 * v18] & 0xFFFFu) >> 9)
                                           + pClass51_global->pBModels
                                           + 84)
                               + 308 * (((*(_DWORD *)&dword_720020[4 * v18] & 0xFFFFu) >> 3) & 0x3F)
                               + 292);
      }
      if ( v22 )
      {
        v23 = sub_444732(v22);
        if ( v23 )
          goto LABEL_36;
      }
    }
LABEL_41:
    ++v18;
    if ( v18 >= v2 )
      return 0;
  }
  v26 = &array_6836D0[v19];
  v27 = v26;
  v25 = v26[11];
  if ( v25 )
  {
    v23 = sub_444732((void *)v25);
    if ( !v23 )
      return v20;
    goto LABEL_36;
  }
  if ( sub_44C2F4(v26) )
    v24 = (const char *)dword_722240[2 * (unsigned __int8)global_5E4C90.byte_000000[v27[14]]];
  else
    v24 = (const char *)(84 * *v27 + pDecorationDescriptionList->pDescriptions + 32);
LABEL_51:
  sub_41C0B8(v24);
  return v20;
}

//----- (0046AC59) --------------------------------------------------------
int __fastcall sub_46AC59(int a1)
{
  size_t v2; // eax@1

  *(char *)(&pGame->unnamed_00097C.dword_000000) = BYTE3(a1);
  CGame_stru0_sub_40E2F6(&pGame->unnamed_00097C, 0);
  v2 = strlen("micon1");
  return sub_40E32E(&pGame->unnamed_00097C, "micon1", v2);
}

//----- (0046AC8C) --------------------------------------------------------
void __cdecl sub_46AC8C()
{
  if ( !(pGame->dword_000978 & 1) )
  {
    pGame->dword_000978 |= 1;
    CGame_stru0_sub_40E2F6(&pGame->unnamed_00097C, 1);
  }
}

//----- (0046ACA9) --------------------------------------------------------
int __thiscall sub_46ACA9(int this, int a2)
{
  int v2; // esi@1
  int v3; // eax@1
  int v4; // edi@1
  double v6; // ST14_8@3
  double v7; // ST14_8@3

  v3 = a2;
  v2 = this;
  *(_DWORD *)(this + 64) = -1;
  *(_DWORD *)(this + 12) = v3;
  LOBYTE(v3) = BYTE3(a2);
  v4 = this + 104;
  *(_DWORD *)(this + 4) = 0;
  *(_BYTE *)(this + 20) = 0;
  *(_DWORD *)(this + 68) = 0;
  *(_DWORD *)(this + 72) = 0;
  *(_BYTE *)(this + 88) = 1;
  *(_BYTE *)(this + 91) = 0;
  *(_BYTE *)(this + 93) = 0;
  *(_BYTE *)(this + 94) = 0;
  *(_BYTE *)(this + 95) = 0;
  *(_BYTE *)(this + 96) = 0;
  *(_BYTE *)(this + 97) = 0;
  *(_BYTE *)(this + 98) = 0;
  *(_BYTE *)(this + 99) = 0;
  *(_BYTE *)(this + 100) = 0;
  *(_BYTE *)(this + 101) = 0;
  *(_BYTE *)(this + 102) = 0;
  *(_BYTE *)(this + 104) = v3;
  *(_DWORD *)(this + 108) = sub_46BD09(0, 0);
  *(_DWORD *)(v4 + 8) = 0;
  *(_BYTE *)(v2 + 116) = BYTE3(a2);
  *(_DWORD *)(v2 + 120) = sub_46BD09(0, 0);
  *(_DWORD *)(v2 + 124) = 0;
  *(_DWORD *)(v2 + 128) = 0;
  *(_DWORD *)(v2 + 132) = 0;
  *(_DWORD *)v2 = 5080880;
  if ( !sub_46AE6E((LPVOID)v2) )
  {
    a2 = (int)"Could not initialize CMouseAsync object";
    _CxxThrowException(&a2, 5094804);
  }
  *(_DWORD *)(v2 + 48) = 0;
  *(_DWORD *)(v2 + 52) = 0;
  *(_DWORD *)(v2 + 56) = 0;
  *(_DWORD *)(v2 + 60) = 0;
  v6 = (float)0.0 + 6.755399441055744e15;
  *(_DWORD *)(v2 + 40) = LODWORD(v6);
  v7 = (float)0.0 + 6.755399441055744e15;
  a2 = LODWORD(v7);
  *(_DWORD *)(v2 + 128) |= 1u;
  *(_DWORD *)(v2 + 44) = LODWORD(v7);
  *(_BYTE *)(v2 + 103) = 1;
  return v2;
}

//----- (0046ADE2) --------------------------------------------------------
int __thiscall sub_46ADE2(int this)
{
  int v1; // ecx@1
  int v2; // edi@1
  int v3; // esi@1
  int v5; // eax@3
  int v6; // eax@3

  v3 = this;
  *(_DWORD *)this = 5080880;
  v2 = this + 132;
  v1 = *(_DWORD *)(this + 132);
  if ( v1 )
    (**(void (__stdcall ***)(_DWORD))v1)(1);
  *(_DWORD *)v2 = 0;
  TerminateThread(*(HANDLE *)(v3 + 16), 0xFAu);
  v5 = SetWindowPos(hWnd_global, (HWND)0xFFFFFFFE, uWindowPosX, uWindowPosY, 640, 480, 0);
  v6 = sub_46BC73(v5, v3 + 116);
  return sub_46BC73(v6, v3 + 104);
}

//----- (0046AE6E) --------------------------------------------------------
char __thiscall sub_46AE6E(LPVOID lpParameter)
{
  void *v1; // esi@1
  char result; // al@2

  v1 = lpParameter;
  if ( sub_46AF50(lpParameter) && sub_46B072((DWORD)v1) )
    result = sub_46B0A9(v1) != 0;
  else
    result = 0;
  return result;
}

//----- (0046AE97) --------------------------------------------------------
char __thiscall sub_46AE97(void *this, void *Source)
{
  void *v2; // esi@1
  int v3; // eax@1
  int v4; // eax@1
  char result; // al@3
  int v6; // [sp+8h] [bp-B0h]@1
  int v7; // [sp+58h] [bp-60h]@1
  char class18_obj[128]; // [sp+6Ch] [bp-4Ch]@1
  char v9; // [sp+B4h] [bp-4h]@1

  v2 = this;
  EnterCriticalSection(&pGame->class01_obj->cs2);
  v3 = *((_DWORD *)v2 + 1);
  v6 = 100;
  v7 = 0;
  v4 = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD, signed int, int *))(*(_DWORD *)v3 + 20))(
         v3,
         0,
         0,
         0,
         1024,
         &v6);
  CheckHRESULT(&v9, v4, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\MouseAsync.cpp", 0x81u, 0);

  class18_ctor(class18_obj);
  if ( class17_LoadPalette(pClass17_Icons_LOD, class18_obj, (int)Source, 2) != -1 && sub_46B1EC((int)struct_505898.Dest, *((_DWORD *)v2 + 1), 0) )
  {
    sub_40F77C(class18_obj);
    LeaveCriticalSection(&pGame->class01_obj->cs2);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046AF50) --------------------------------------------------------
char __thiscall sub_46AF50(void *this)
{
  void *v1; // ebx@1
  int v2; // eax@2
  int v3; // esi@4
  char result; // al@5
  void *v5; // eax@6
  char v6; // [sp-18h] [bp-12Ch]@9
  int v7; // [sp-14h] [bp-128h]@9
  int v8; // [sp-10h] [bp-124h]@9
  int v9; // [sp-Ch] [bp-120h]@9
  const char *v10; // [sp-8h] [bp-11Ch]@9
  int Dst; // [sp+Ch] [bp-108h]@1
  char v13; // [sp+54h] [bp-C0h]@2
  int v14; // [sp+88h] [bp-8Ch]@2
  int v15; // [sp+8Ch] [bp-88h]@2
  int v16; // [sp+90h] [bp-84h]@2
  int v17; // [sp+94h] [bp-80h]@2
  char v18; // [sp+D0h] [bp-44h]@2
  int v19; // [sp+F0h] [bp-24h]@2
  int v20; // [sp+104h] [bp-10h]@4
  int v21; // [sp+108h] [bp-Ch]@4
  char *v22; // [sp+10Ch] [bp-8h]@9
  int v23; // [sp+113h] [bp-1h]@9

  v1 = this;
  memset(&Dst, 0, 0x7Cu);
  Dst = 124;
  if ( (*(int (__stdcall **)(int, int *))(pD3DRenderer->pdd4 + 48))(pD3DRenderer->pdd4, &Dst)
    || (memset(&v14, 0, 0x7Cu),
        v14 = 124,
        v15 = 4103,
        v19 = 2112,
        v16 = 32,
        v17 = 32,
        v2 = *((_DWORD *)v1 + 3),
        memcpy(&v18, &v13, 0x20u),
        (*(int (__stdcall **)(_DWORD, int *, char *, _DWORD))(**(_DWORD **)v2 + 24))(
          *(_DWORD *)v2,
          &v14,
          (char *)v1 + 4,
          0))
    || (*(int (__stdcall **)(_DWORD, int *, char *, _DWORD))(***((_DWORD ***)v1 + 3) + 24))(
         **((_DWORD **)v1 + 3),
         &v14,
         (char *)v1 + 8,
         0)
    || (v3 = *((_DWORD *)v1 + 1),
        v20 = 0,
        v21 = 0,
        (*(int (__stdcall **)(int, signed int, int *))(*(_DWORD *)v3 + 116))(v3, 8, &v20)) )
  {
    result = 0;
  }
  else
  {
   v5 = pGame->unnamed_00097C.ptr_000004;
    if ( !pGame->unnamed_00097C.ptr_000004)
      v5 = byte_4D8410 + 736;
    if ( !sub_46AE97(v1, v5) )
    {
      v10 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\MouseAsync.cpp";
      v22 = &v6;
      sub_40E2C8(&v6, "Could not load async mouse cursor image", (int)&v23);
      sub_466D09(&v22, *(int *)&v6, v7, v8, v9, v10, __LINE__);
    }
    result = 1;
  }
  return result;
}

//----- (0046B072) --------------------------------------------------------
char __thiscall sub_46B072(DWORD lpParameter)
{
  HANDLE v1; // eax@1
  LPVOID v2; // esi@1
  char result; // al@2
  DWORD ThreadId; // [sp+0h] [bp-4h]@1

  ThreadId = lpParameter;
  v2 = (LPVOID)lpParameter;
  v1 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_46BC4E, (LPVOID)lpParameter, 4u, &ThreadId);
  *((_DWORD *)v2 + 4) = v1;
  if ( v1 )
    result = SetThreadPriority(v1, 15) != 0;
  else
    result = 0;
  return result;
}

//----- (0046B0A9) --------------------------------------------------------
char __thiscall sub_46B0A9(void *this)
{
  int v1; // ecx@1
  void *v2; // esi@1
  int v3; // eax@2

  v2 = this;
  //v1 = (int)operator new(0x2Cu);
  v1 = malloc(0x2C);
  if ( v1 )
    v3 = sub_43B9FF(v1);
  else
    v3 = 0;
  *((_DWORD *)v2 + 33) = v3;
  return v3 != 0;
}

//----- (0046B0ED) --------------------------------------------------------
int __thiscall sub_46B0ED(int this)
{
  int v1; // ecx@1
  int v2; // esi@1
  int result; // eax@2

  v2 = this + 132;
  v1 = *(_DWORD *)(this + 132);
  if ( v1 )
    result = (**(int (__stdcall ***)(_DWORD))v1)(1);
  *(_DWORD *)v2 = 0;
  return result;
}

//----- (0046B105) --------------------------------------------------------
void __thiscall sub_46B105(void *this)
{
  void *v1; // esi@1

  v1 = this;
  EnterCriticalSection(&pGame->class01_obj->cs3);
  sub_46B0A9(v1);
  sub_46BBD0();
  ResumeThread(*((HANDLE *)v1 + 4));
  *((_BYTE *)v1 + 88) = 0;
  LeaveCriticalSection(&pGame->class01_obj->cs3);
}

//----- (0046B14F) --------------------------------------------------------
void __thiscall Mouse_suspend(int this)
{
  int v1; // esi@1
  int v2; // eax@3
  char v3; // [sp-18h] [bp-24h]@2
  const CHAR *v4; // [sp-14h] [bp-20h]@2
  int v5; // [sp-10h] [bp-1Ch]@2
  int v6; // [sp-Ch] [bp-18h]@2
  const char *v7; // [sp-8h] [bp-14h]@2
  int v8; // [sp-4h] [bp-10h]@2
  char *v9; // [sp+4h] [bp-8h]@2
  int v10; // [sp+Bh] [bp-1h]@2

  v1 = this;
  if ( *(_DWORD *)(this + 132) )
  {
    v2 = pGame->class05_obj;
    if ( v2 )
      *(_DWORD *)(v2 + 8200) = 0;
    EnterCriticalSection(&pGame->class01_obj->cs3);
    SuspendThread(*(HANDLE *)(v1 + 16));
    sub_46B0ED(v1);
    LeaveCriticalSection(&pGame->class01_obj->cs3);
  }
  else
  {
    v8 = 233;
    v7 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\MouseAsync.cpp";
    v9 = &v3;
    sub_40E2C8(&v3, "DI_Mouse pointer invalid; bailing out from suspend()", (int)&v10);
    sub_467834(&v9, v3, v4, v5, v6, v7, v8);
  }
}

//----- (0046B1DD) --------------------------------------------------------
char __thiscall sub_46B1DD(int this)
{
  *(_BYTE *)(this + 20) = 1;
  Sleep(0x76u);
  return 1;
}

//----- (0046B1EC) --------------------------------------------------------
char __stdcall sub_46B1EC(int a1, int a2, int a3)
{
  int v3; // edx@2
  int v4; // ecx@2
  int v5; // ebx@2
  int v6; // edi@2
  int v7; // esi@2
  int v8; // ecx@5
  int Dst; // [sp+0h] [bp-84h]@1
  int v12; // [sp+10h] [bp-74h]@3
  int v13; // [sp+24h] [bp-60h]@2
  int v14; // [sp+7Ch] [bp-8h]@3
  int v15; // [sp+80h] [bp-4h]@3
  int v16; // [sp+8Ch] [bp+8h]@3

  Dst = 124;
  if ( LockSurface_DDraw4(a2, &Dst, 1) )
  {
    v5 = *(_DWORD *)(a1 + 64);
    v3 = *(_DWORD *)(a1 + 48);
    v7 = *(_WORD *)(a1 + 24);
    v4 = *(_WORD *)(a1 + 26);
    v6 = v13;
    if ( v4 > 0 )
    {
      v16 = 0;
      v14 = 2 * (v12 / 2 - v7);
      v15 = v4;
      do
      {
        if ( v7 > 0 )
        {
          v8 = v7;
          do
          {
            if ( *(_WORD *)(v5 + 2 * *(_BYTE *)v3) )
              *(_WORD *)v6 = *(_WORD *)(v5 + 2 * *(_BYTE *)v3);
            v6 += 2;
            ++v3;
            --v8;
          }
          while ( v8 );
        }
        v6 += v14;
        v3 += v16;
      }
      while ( v15-- != 1 );
    }
    (*(void (__fastcall **)(_DWORD, int, int, int))(*(_DWORD *)a2 + 128))(*(_DWORD *)a2, v3, a2, a3);
  }
  return 1;
}

//----- (0046B289) --------------------------------------------------------
char __thiscall sub_46B289(int this, int a2, char a3)
{
  char v3; // dl@1
  char v5; // [sp+2h] [bp-2h]@1
  char v6; // [sp+3h] [bp-1h]@1

  v3 = *(_BYTE *)(this + 93);
  v6 = *(_BYTE *)(this + 94);
  v5 = *(_BYTE *)(this + 95);
  if ( a3 & 1 )
  {
    *(_BYTE *)(this + 93) = 1;
  }
  else
  {
    if ( v3 )
      *(_BYTE *)(this + 99) = 1;
    else
      *(_BYTE *)(this + 99) = 0;
    *(_BYTE *)(this + 93) = 0;
  }
  if ( a3 & 2 )
  {
    *(_BYTE *)(this + 94) = 1;
  }
  else
  {
    if ( v6 )
      *(_BYTE *)(this + 100) = 1;
    else
      *(_BYTE *)(this + 100) = 0;
    *(_BYTE *)(this + 94) = 0;
  }
  if ( a3 & 4 )
  {
    *(_BYTE *)(this + 95) = 1;
  }
  else
  {
    if ( v5 )
      *(_BYTE *)(this + 101) = 1;
    else
      *(_BYTE *)(this + 101) = 0;
    *(_BYTE *)(this + 95) = 0;
  }
  *(_BYTE *)(this + 96) = v3 != *(_BYTE *)(this + 93);
  *(_BYTE *)(this + 97) = v6 != *(_BYTE *)(this + 94);
  *(_BYTE *)(this + 98) = v5 != *(_BYTE *)(this + 95);
  if ( *(_BYTE *)(this + 99) && *(_BYTE *)(this + 96) || *(_BYTE *)(this + 100) && *(_BYTE *)(this + 97) )
    *(_BYTE *)(this + 102) = 1;
  return 1;
}

//----- (0046B342) --------------------------------------------------------
int __thiscall sub_46B342(int this, float a2, float a3)
{
  int result; // eax@1
  double v4; // ST00_8@1
  double v5; // ST00_8@1

  v4 = a2 + 6.755399441055744e15;
  *(_DWORD *)(this + 40) = LODWORD(v4);
  v5 = a3 + 6.755399441055744e15;
  result = LODWORD(v5);
  *(_DWORD *)(this + 44) = LODWORD(v5);
  return result;
}

//----- (0046B37C) --------------------------------------------------------
int __thiscall update_mouse_data(int this, int a2)
{
  int v2; // edi@1
  int result; // eax@2
  int v4; // eax@3
  int v5; // esi@3
  char v6; // [sp-18h] [bp-28h]@2
  const CHAR *v7; // [sp-14h] [bp-24h]@2
  int v8; // [sp-10h] [bp-20h]@2
  int v9; // [sp-Ch] [bp-1Ch]@2
  const char *v10; // [sp-8h] [bp-18h]@2
  char *v12; // [sp+8h] [bp-8h]@2
  int v13; // [sp+Fh] [bp-1h]@2

  v2 = this;
  if ( *(_DWORD *)(this + 132) )
  {
   EnterCriticalSection(&pGame->class01_obj->cs3);
    sub_43BB89(*(_DWORD *)(v2 + 132));
    v4 = *(_DWORD *)(v2 + 132);
    v5 = v4 + 32;
    sub_46B289(v2, v4 + 32, *(_DWORD *)(v4 + 40));
    LeaveCriticalSection(&pGame->class01_obj->cs3);
    result = a2;
    *(_DWORD *)a2 = *(_DWORD *)v5;
    *(_DWORD *)(a2 + 4) = *(_DWORD *)(v5 + 4);
  }
  else
  {
    v10 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\MouseAsync.cpp";
    v12 = &v6;
    sub_40E2C8(&v6, "DI_Mouse pointer invalid bailing out from update_mouse_data()", (int)&v13);
    sub_467834(&v12, v6, v7, v8, v9, v10, __LINE__);
    result = a2;
    *(_DWORD *)a2 = 0;
    *(_DWORD *)(a2 + 4) = 0;
  }
  return result;
}

//----- (0046B420) --------------------------------------------------------
char __thiscall sub_46B420(int this)
{
  int v1; // esi@1
  char result; // al@2
  int v3; // eax@3
  int v4; // ecx@3
  int v5; // eax@3
  int v6; // ecx@3
  int v7; // [sp+4h] [bp-8h]@3
  int v8; // [sp+8h] [bp-4h]@3

  v1 = this;
  if ( *(_BYTE *)(this + 20) )
  {
    result = 0;
  }
  else
  {
    update_mouse_data(this, (int)&v7);
    sub_46BA8D((void *)v1, v7, v8);
    sub_46B958((void *)v1, v7 - *(_DWORD *)(v1 + 40), v8 - *(_DWORD *)(v1 + 44));
    sub_46B492((void *)v1, (int)&v7);
    sub_46B5D5((void *)v1, (int)&v7);
    v3 = v7;
    v4 = v8;
    *(_DWORD *)(v1 + 24) = v7;
    v5 = v3 - *(_DWORD *)(v1 + 40);
    *(_DWORD *)(v1 + 28) = v4;
    v6 = v4 - *(_DWORD *)(v1 + 44);
    *(_DWORD *)(v1 + 32) = v5;
    result = 1;
    *(_DWORD *)(v1 + 36) = v6;
  }
  return result;
}

//----- (0046B492) --------------------------------------------------------
void __thiscall sub_46B492(void *this, int a2)
{
  void *v2; // edi@1
  int v3; // esi@3
  int v4; // eax@5
  int v5; // ecx@5
  int v6; // eax@8
  int v7; // ecx@8
  int v8; // eax@11
  int v9; // esi@11
  int v10; // [sp+Ch] [bp-1Ch]@5
  int v11; // [sp+10h] [bp-18h]@5
  int v12; // [sp+14h] [bp-14h]@5
  int v13; // [sp+18h] [bp-10h]@5
  int v14; // [sp+24h] [bp-4h]@5

  v2 = this;
  EnterCriticalSection(&pGame->class01_obj->cs1);
  if ( *((_DWORD *)v2 + 28) > 0x80u )
    sub_46BCAB((int)((char *)v2 + 104));
  v3 = a2;
  if ( *((_BYTE *)v2 + 93) )
  {
    if ( *((_BYTE *)v2 + 96) )
    {
      v4 = *(_DWORD *)a2;
      v5 = *(_DWORD *)(a2 + 4);
      v13 = 1;
      v10 = 5080884;
      v11 = v4;
      v12 = v5;
      v14 = 0;
      sub_46BCD2((char *)v2 + 104, (int)&a2, *((_DWORD *)v2 + 27), (int)&v10);
      v14 = -1;
    }
  }
  if ( *((_BYTE *)v2 + 94) )
  {
    if ( *((_BYTE *)v2 + 97) )
    {
      v6 = *(_DWORD *)v3;
      v7 = *(_DWORD *)(v3 + 4);
      v13 = 2;
      v10 = 5080884;
      v11 = v6;
      v12 = v7;
      v14 = 1;
      sub_46BCD2((char *)v2 + 104, (int)&a2, *((_DWORD *)v2 + 27), (int)&v10);
      v14 = -1;
    }
  }
  if ( *((_BYTE *)v2 + 95) )
  {
    if ( *((_BYTE *)v2 + 98) )
    {
      v8 = *(_DWORD *)v3;
      v9 = *(_DWORD *)(v3 + 4);
      v13 = 4;
      v10 = 5080884;
      v11 = v8;
      v12 = v9;
      v14 = 2;
      sub_46BCD2((char *)v2 + 104, (int)&a2, *((_DWORD *)v2 + 27), (int)&v10);
    }
  }
  LeaveCriticalSection(&pGame->class01_obj->cs1);
}

//----- (0046B5D5) --------------------------------------------------------
void __thiscall sub_46B5D5(void *this, int a2)
{
  void *v2; // esi@1
  DWORD v3; // eax@3
  int v4; // edi@3
  char v5; // zf@3
  int v6; // eax@6
  int v7; // ecx@6
  int v8; // eax@11
  int v9; // ecx@11
  int v10; // eax@16
  int v11; // edi@16
  int v12; // [sp+Ch] [bp-20h]@6
  int v13; // [sp+10h] [bp-1Ch]@6
  int v14; // [sp+14h] [bp-18h]@6
  int v15; // [sp+18h] [bp-14h]@6
  DWORD v16; // [sp+1Ch] [bp-10h]@3
  int v17; // [sp+28h] [bp-4h]@6

  v2 = this;
  EnterCriticalSection(&pGame->class01_obj->cs1);
  if ( *((_DWORD *)v2 + 31) > 0x80u )
    sub_46BCAB((int)((char *)v2 + 116));
  v3 = timeGetTime();
  v5 = *((_BYTE *)v2 + 93) == 0;
  v4 = a2;
  v16 = v3;
  if ( !v5 )
  {
    if ( *((_BYTE *)v2 + 96) )
    {
      if ( v3 - *((_DWORD *)v2 + 19) < 0xFA )
      {
        v6 = *(_DWORD *)a2;
        v7 = *(_DWORD *)(a2 + 4);
        v15 = 1;
        v12 = 5080884;
        v13 = v6;
        v14 = v7;
        v17 = 0;
        sub_46BCD2((char *)v2 + 116, (int)&a2, *((_DWORD *)v2 + 30), (int)&v12);
        v17 = -1;
        v3 = v16;
      }
      *((_DWORD *)v2 + 19) = v3;
    }
  }
  if ( *((_BYTE *)v2 + 94) )
  {
    if ( *((_BYTE *)v2 + 97) )
    {
      if ( v3 - *((_DWORD *)v2 + 20) < 0xFA )
      {
        v8 = *(_DWORD *)v4;
        v9 = *(_DWORD *)(v4 + 4);
        v15 = 2;
        v12 = 5080884;
        v13 = v8;
        v14 = v9;
        v17 = 1;
        sub_46BCD2((char *)v2 + 116, (int)&a2, *((_DWORD *)v2 + 30), (int)&v12);
        v17 = -1;
        v3 = v16;
      }
      *((_DWORD *)v2 + 20) = v3;
    }
  }
  if ( *((_BYTE *)v2 + 95) )
  {
    if ( *((_BYTE *)v2 + 98) )
    {
      if ( v3 - *((_DWORD *)v2 + 21) < 0xFA )
      {
        v10 = *(_DWORD *)v4;
        v11 = *(_DWORD *)(v4 + 4);
        v15 = 4;
        v12 = 5080884;
        v13 = v10;
        v14 = v11;
        v17 = 2;
        sub_46BCD2((char *)v2 + 116, (int)&a2, *((_DWORD *)v2 + 30), (int)&v12);
        v3 = v16;
      }
      *((_DWORD *)v2 + 21) = v3;
    }
  }
  LeaveCriticalSection(&pGame->class01_obj->cs1);
}

//----- (0046B736) --------------------------------------------------------
void __thiscall sub_46B736(void *this, char a2)
{
  void *v2; // esi@1

  v2 = this;
  sub_46B76F();
  sub_46B879();
  if ( a2 )
  {
    sub_46BCAB((int)((char *)v2 + 104));
    sub_46BCAB((int)((char *)v2 + 116));
  }
  if ( *((_BYTE *)v2 + 102) )
  {
    sub_4356FF();
    *((_BYTE *)v2 + 102) = 0;
  }
}

//----- (0046B76F) --------------------------------------------------------
void __cdecl sub_46B76F()
{
  int v0; // ebx@1
  int v1; // edi@1
  int v2; // eax@1
  int v3; // eax@2
  signed int *v4; // esi@2
  signed int v5; // ST08_4@7
  signed int v6; // ST04_4@7
  float v7; // ST00_4@7
  signed int v8; // ST08_4@9
  signed int v9; // ST04_4@9
  float v10; // ST00_4@9

  EnterCriticalSection(&pGame->class01_obj->cs1);
  v0 = dword_720010 + 108;
  v2 = *(_DWORD *)(dword_720010 + 108);
  v1 = *(_DWORD *)v2;
  if ( *(_DWORD *)v2 != v2 )
  {
    do
    {
      v3 = *(_DWORD *)(v1 + 20);
      v4 = (signed int *)(v1 + 12);
      if ( v3 & 1 )
      {
        CGame_Pick(pGame, 512.0, *v4, *(_DWORD *)(v1 + 16), 0, (int)&dword_F93E6C, (int)&dword_F93E58);
        if ( sub_466CA0() == MENU_CREATEPARTY )
          sub_41CD4F(VK_SELECT);
        OnMouseLeftClick((void *)(v1 + 12));
      }
      else
      {
        if ( v3 & 2 )
        {
          v5 = *(_DWORD *)(v1 + 16);
          v6 = *v4;
          v7 = sub_43643E();
          CGame_Pick(pGame, v7, v6, v5, 0, (int)&dword_F93E30, (int)&dword_F93E44);
          sub_416D62(v1 + 12);
        }
        else
        {
          if ( v3 & 4 )
          {
            v8 = *(_DWORD *)(v1 + 16);
            v9 = *v4;
            v10 = sub_43643E();
            CGame_Pick(pGame, v10, v9, v8, 1, (int)&dword_F93E6C, (int)&dword_F93E44);
          }
        }
      }
      v1 = *(_DWORD *)v1;
    }
    while ( v1 != *(_DWORD *)v0 );
  }
  LeaveCriticalSection(&pGame->class01_obj->cs1);
}

//----- (0046B879) --------------------------------------------------------
void __cdecl sub_46B879()
{
  int v0; // ebx@1
  int v1; // edi@1
  int v2; // eax@1
  int v3; // eax@2
  signed int *v4; // esi@2
  signed int v5; // ST08_4@5
  signed int v6; // ST04_4@5
  float v7; // ST00_4@5

  EnterCriticalSection(&pGame->class01_obj->cs1);
  v0 = dword_720010 + 120;
  v2 = *(_DWORD *)(dword_720010 + 120);
  v1 = *(_DWORD *)v2;
  if ( *(_DWORD *)v2 != v2 )
  {
    do
    {
      v3 = *(_DWORD *)(v1 + 20);
      v4 = (signed int *)(v1 + 12);
      if ( v3 & 1 )
      {
        CGame_Pick(pGame, 512.0, *v4, *(_DWORD *)(v1 + 16), 0, (int)&dword_F93E6C, (int)&dword_F93E58);
        sub_4178C4();
      }
      else
      {
        if ( v3 & 2 )
        {
          v5 = *(_DWORD *)(v1 + 16);
          v6 = *v4;
          v7 = sub_43643E();
          CGame_Pick(pGame, v7, v6, v5, 0, (int)&dword_F93E30, (int)&dword_F93E58);
          sub_4178E1();
        }
        else
        {
          if ( v3 & 4 )
            compile_error;//nullsub_1(v1 + 12);
        }
      }
      v1 = *(_DWORD *)v1;
    }
    while ( v1 != *(_DWORD *)v0 );
  }
  LeaveCriticalSection(&pGame->class01_obj->cs1);
}

//----- (0046B944) --------------------------------------------------------
int __thiscall sub_46B944(int this)
{
  int v2; // esi@1

  v2 = this;
  sub_46BCAB(this + 104);
  return sub_46BCAB(v2 + 116);
}

//----- (0046B958) --------------------------------------------------------
char __thiscall sub_46B958(void *this, int a2, int a3)
{
  void *v3; // esi@1
  char result; // al@3
  int v5; // eax@6
  int v6; // edx@6
  int v7; // eax@12
  int v8; // edi@13
  int v9; // eax@19
  int v10; // ST08_4@21
  int v11; // [sp+4h] [bp-74h]@21
  int v12; // [sp+8h] [bp-70h]@21
  int v13; // [sp+68h] [bp-10h]@19
  int v14; // [sp+6Ch] [bp-Ch]@19
  int v15; // [sp+70h] [bp-8h]@19
  int v16; // [sp+74h] [bp-4h]@19

  v3 = this;
  if ( pD3DRenderer->pdds4_FrontBuffer && !(*(int (__stdcall **)(int))(pD3DRenderer->pdds4_FrontBuffer + 96))(pD3DRenderer->pdds4_FrontBuffer) )
  {
    EnterCriticalSection(&pGame->class01_obj->cs2);
    if ( *((_BYTE *)v3 + 88) )
      (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD, char *, signed int))(pD3DRenderer->pdds4_FrontBuffer + 28))(
        pD3DRenderer->pdds4_FrontBuffer,
        *((_DWORD *)v3 + 8),
        *((_DWORD *)v3 + 9),
        *((_DWORD *)v3 + 2),
        (char *)v3 + 48,
        16);
    v6 = 640 - a2;
    v5 = 640 - a2;
    if ( 640 - a2 >= 31 )
      v5 = 31;
    if ( v5 >= 0 )
    {
      if ( v6 >= 31 )
        v6 = 31;
    }
    else
    {
      v6 = 0;
    }
    v7 = 480 - a3;
    if ( 480 - a3 >= 31 )
      v8 = 31;
    else
      v8 = 480 - a3;
    if ( v8 >= 0 )
    {
      if ( v7 >= 31 )
        v7 = 31;
    }
    else
    {
      v7 = 0;
    }
    *((_DWORD *)v3 + 13) = 0;
    *((_DWORD *)v3 + 14) = v6;
    v15 = a2 + v6;
    *((_DWORD *)v3 + 12) = 0;
    *((_DWORD *)v3 + 15) = v7;
    v13 = a2;
    v16 = a3 + v7;
    v9 = *((_DWORD *)v3 + 2);
    v14 = a3;
    (*(void (__stdcall **)(int, _DWORD, _DWORD, int, int *, signed int))(*(_DWORD *)v9 + 28))(
      v9,
      0,
      0,
      pD3DRenderer->pdds4_FrontBuffer,
      &v13,
      16);
    if ( !*((_BYTE *)v3 + 90) || *((_BYTE *)v3 + 128) & 1 )
    {
      v10 = *((_DWORD *)v3 + 1);
      v11 = 100;
      v12 = 8;
      (*(void (__stdcall **)(int, int *, int, char *, signed int, int *))(pD3DRenderer->pdds4_FrontBuffer + 20))(
        pD3DRenderer->pdds4_FrontBuffer,
        &v13,
        v10,
        (char *)v3 + 48,
        16812032,
        &v11);
    }
    *((_BYTE *)v3 + 88) = 1;
    LeaveCriticalSection(&pGame->class01_obj->cs2);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046BA8D) --------------------------------------------------------
char __thiscall sub_46BA8D(void *this, int a2, int a3)
{
  DWORD v3; // eax@1
  void *v4; // esi@1

  v4 = this;
  v3 = timeGetTime();
  if ( v3 - *((_DWORD *)v4 + 16) <= 0x32 )
  {
    *((_BYTE *)v4 + 91) = *((_BYTE *)v4 + 90) == 1;
    *((_BYTE *)v4 + 90) = 0;
  }
  else
  {
    if ( *((_BYTE *)v4 + 90) )
      *((_BYTE *)v4 + 91) = 0;
    else
      *((_BYTE *)v4 + 91) = 1;
    *((_BYTE *)v4 + 90) = 1;
  }
  if ( a2 != *((_DWORD *)v4 + 17) || a3 != *((_DWORD *)v4 + 18) )
  {
    *((_DWORD *)v4 + 16) = v3;
    *((_DWORD *)v4 + 17) = a2;
    *((_DWORD *)v4 + 18) = a3;
  }
  return *((_BYTE *)v4 + 90);
}

//----- (0046BAEC) --------------------------------------------------------
void __thiscall sub_46BAEC(void *this)
{
  void *v1; // esi@1

  v1 = this;
  EnterCriticalSection(&pGame->class01_obj->cs2);
  *((_BYTE *)v1 + 88) = 0;
}

//----- (0046BB0A) --------------------------------------------------------
void __thiscall sub_46BB0A(int this)
{
  int v1; // esi@1
  int v2; // eax@1
  int v3; // edx@1
  int v4; // ecx@1
  int v5; // edx@1
  int v6; // eax@1
  char v7; // zf@1
  int v8; // ST08_4@8
  int v9; // [sp+8h] [bp-74h]@8
  int v10; // [sp+Ch] [bp-70h]@8
  int v11; // [sp+6Ch] [bp-10h]@1
  int v12; // [sp+70h] [bp-Ch]@1
  int v13; // [sp+74h] [bp-8h]@1
  int v14; // [sp+78h] [bp-4h]@1

  v1 = this;
  v2 = *(_DWORD *)(this + 68) - *(_DWORD *)(this + 40);
  v3 = *(_DWORD *)(this + 56);
  v4 = *(_DWORD *)(this + 72) - *(_DWORD *)(this + 44);
  v11 = v2;
  v5 = v2 + v3;
  v6 = *(_DWORD *)(v1 + 60);
  v12 = v4;
  v7 = *(_BYTE *)(v1 + 90) == 0;
  v13 = v5;
  v14 = v4 + v6;
  if ( v7 || *(_BYTE *)(v1 + 128) & 1 )
  {
    if ( *(_BYTE *)(v1 + 88) )
      (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD, int, signed int))(pD3DRenderer->pdds4_FrontBuffer + 28))(
        pD3DRenderer->pdds4_FrontBuffer,
        *(_DWORD *)(v1 + 32),
        *(_DWORD *)(v1 + 36),
        *(_DWORD *)(v1 + 8),
        v1 + 48,
        16);
    (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, int, int *, signed int))(**(_DWORD **)(v1 + 8) + 28))(
      *(_DWORD *)(v1 + 8),
      0,
      0,
      pD3DRenderer->pdds4_FrontBuffer,
      &v11,
      16);
  }
  if ( *(_BYTE *)(v1 + 90) )
  {
    if ( !(*(_BYTE *)(v1 + 128) & 1) )
    {
      v8 = *(_DWORD *)(v1 + 4);
      v9 = 100;
      v10 = 8;
      (*(void (__stdcall **)(int, int *, int, int, signed int, int *))(pD3DRenderer->pdds4_FrontBuffer + 20))(
        pD3DRenderer->pdds4_FrontBuffer,
        &v11,
        v8,
        v1 + 48,
        16812032,
        &v9);
    }
  }
  LeaveCriticalSection(&pGame->class01_obj->cs2);
}

//----- (0046BBD0) --------------------------------------------------------
void *__cdecl sub_46BBD0()
{
  void *result; // eax@1
  char v1; // [sp-18h] [bp-30h]@2
  int v2; // [sp-14h] [bp-2Ch]@2
  int v3; // [sp-10h] [bp-28h]@2
  int v4; // [sp-Ch] [bp-24h]@2
  const char *v5; // [sp-8h] [bp-20h]@2
  int v6; // [sp-4h] [bp-1Ch]@2
  RECT Rect; // [sp+0h] [bp-18h]@1
  char *v8; // [sp+10h] [bp-8h]@2
  int v9; // [sp+17h] [bp-1h]@2

  SetWindowPos(hWnd_global, (HWND)((unsigned int)(HWND_MESSAGE)|0x2), 320, 240, 640, 480, 0);
  Rect.left = 325;
  Rect.top = 245;
  Rect.right = 326;
  Rect.bottom = 246;
  result = (void *)ClipCursor(&Rect);
  if ( !result )
  {
    v6 = 827;
    v5 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\MouseAsync.cpp";
    v8 = &v1;
    sub_40E2C8(&v1, "Could not clip cursor to screen!", (int)&v9);
    result = sub_466D09(&v8, *(int *)&v1, v2, v3, v4, v5, v6);
  }
  return result;
}

//----- (0046BC4E) --------------------------------------------------------
void __stdcall sub_46BC4E(int a1)
{
  while ( 1 )
  {
    while ( !dword_720010 )
      ;
    if ( !sub_46B420(dword_720010) )
      ExitThread(0);
    Sleep(0x12u);
  }
}

//----- (0046BC73) --------------------------------------------------------
function_error;//int __usercall sub_46BC73<eax>(int a1<eax>, int a2<ecx>)
int __fastcall sub_46BC73(int a1, int a2)
{
  unsigned int *v2; // ebx@1
  int v3; // edi@1
  unsigned int v4; // esi@1
  unsigned int v5; // eax@2
  int result; // eax@4
  int v7; // [sp+0h] [bp-4h]@1

  v7 = a2;
  v3 = a2;
  v2 = *(unsigned int **)(a2 + 4);
  v4 = *v2;
  while ( (unsigned int *)v4 != v2 )
  {
    v5 = v4;
    v4 = *(_DWORD *)v4;
    a1 = sub_46BD2D((void *)v3, (int)&v7, v5);
  }
  result = operator_delete(a1, *(_DWORD *)(v3 + 4));
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  return result;
}

//----- (0046BCAB) --------------------------------------------------------
int __thiscall sub_46BCAB(int this)
{
  void *v1; // ebx@1
  unsigned int *v2; // edi@1
  unsigned int v3; // esi@1
  unsigned int v4; // eax@2
  int result; // eax@2
  int v6; // [sp+0h] [bp-4h]@1

  v6 = this;
  v1 = (void *)this;
  v2 = *(unsigned int **)(this + 4);
  v3 = *v2;
  while ( (unsigned int *)v3 != v2 )
  {
    v4 = v3;
    v3 = *(_DWORD *)v3;
    result = sub_46BD2D(v1, (int)&v6, v4);
  }
  return result;
}

//----- (0046BCD2) --------------------------------------------------------
int __thiscall sub_46BCD2(void *this, int a2, int a3, int a4)
{
  int result; // eax@1
  void *v5; // edi@1
  void *v6; // eax@1
  void *v7; // esi@1

  v5 = this;
  v6 = sub_46BD09((void *)a3, *(void **)(a3 + 4));
  v7 = v6;
  *(_DWORD *)(a3 + 4) = v6;
  **((_DWORD **)v6 + 1) = v6;
  sub_46BD66((int)((char *)v6 + 8), a4);
  result = a2;
  ++*((_DWORD *)v5 + 2);
  *(_DWORD *)a2 = v7;
  return result;
}

//----- (0046BD09) --------------------------------------------------------
void *__stdcall sub_46BD09(void *a1, void *a2)
{
  void *result; // eax@1
  void *v3; // ecx@1
  void *v4; // ecx@3

  compile_error;//result = operator new(0x18u);
  v3 = a1;
  if ( !a1 )
    v3 = result;
  *(_DWORD *)result = v3;
  v4 = a2;
  if ( !a2 )
    v4 = result;
  *((_DWORD *)result + 1) = v4;
  return result;
}

//----- (0046BD2D) --------------------------------------------------------
int __thiscall sub_46BD2D(void *this, int a2, unsigned int a3)
{
  int result; // eax@1
  void *v4; // edi@1
  int v5; // ebx@1
  int v6; // eax@1

  v4 = this;
  v5 = *(_DWORD *)a3;
  **(_DWORD **)(a3 + 4) = *(_DWORD *)a3;
  *(_DWORD *)(*(_DWORD *)a3 + 4) = *(_DWORD *)(a3 + 4);
  v6 = (**(int (__stdcall ***)(_DWORD))(a3 + 8))(0);
  operator_delete(v6, a3);
  result = a2;
  --*((_DWORD *)v4 + 2);
  *(_DWORD *)a2 = v5;
  return result;
}

//----- (0046BD66) --------------------------------------------------------
int __fastcall sub_46BD66(int a1, int a2)
{
  int result; // eax@2

  if ( a1 )
  {
    *(_DWORD *)(a1 + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(a1 + 8) = *(_DWORD *)(a2 + 8);
    result = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(a1 + 12) = result;
    *(_DWORD *)a1 = 5080884;
  }
  return result;
}

//----- (0046BDA8) --------------------------------------------------------
unsigned int __cdecl sub_46BDA8()
{
  int v1; // eax@1

  v1 = ~*(_BYTE *)(LODWORD(pGame) + 3620) & 8;
  LOBYTE(v1) = v1 | 2;
  return (unsigned int)v1 >> 1;
}

//----- (0046BDF1) --------------------------------------------------------
function_error;//int __usercall sub_46BDF1<eax>(unsigned int a1<ebx>)
int __fastcall sub_46BDF1(unsigned int a1)
{
  sub_47253E(a1);
  sub_472866();
  sub_46F90C();
  sub_46F228();
  return sub_46CC4B();
}

//----- (0046BEF1) --------------------------------------------------------
void __thiscall sub_46BEF1(void *this)
{
  void *v1; // edi@1
  int v2; // esi@2
  __int16 v3; // fps@4
  unsigned __int8 v4; // c0@4
  unsigned __int8 v5; // c3@4
  signed __int64 v6; // qax@6
  signed int v7; // [sp+8h] [bp-4h]@1

  v7 = 0;
  v1 = this;
  if ( (signed int)uNumActors > 0 )
  {
    v2 = &pActors[0].sActorPosY;
    do
    {
      if ( sub_40894B(v2 - 144) )
      {
        UNDEF(v3);
        if ( !(v4 | v5) )
        {
          if ( sub_427662(v2 - 144, 10) )
          {
            v6 = (signed __int64)((double)(signed int)(*((_DWORD *)v1 + 19) << 7) * 0.03333333507180214);
            sub_4584E0(
              16 * *((_DWORD *)v1 + 18) + v2 - 144 + 212,
              pParty_global->qword_00002C + v6,
              (unsigned __int64)(pParty_global->qword_00002C + (signed int)v6) >> 32,
              *((_DWORD *)v1 + 20),
              4,
              0,
              0);
            *(_BYTE *)(v2 - 106) |= 8u;
          }
        }
      }
      ++v7;
      v2 += 836;
    }
    while ( v7 < (signed int)uNumActors );
  }
}

//----- (0046BFFA) --------------------------------------------------------
signed int __fastcall sub_46BFFA(int a1, signed int a2)
{
  int v2; // ebx@1
  int v3; // esi@1
  signed int v5; // edx@14
  int v6; // eax@19
  int v7; // ebx@19
  int v8; // edi@19
  int v9; // edx@20
  __int16 v10; // ax@23
  char v11; // zf@26
  int v12; // eax@27
  int v13; // ebx@33
  __int16 v14; // ax@35
  int v15; // eax@36
  int v16; // eax@37
  int v17; // edx@37
  __int16 v18; // di@37
  unsigned __int8 v19; // zf@37
  unsigned __int8 v20; // sf@37
  int v21; // ecx@38
  __int16 v22; // ax@41
  int v23; // eax@46
  int v24; // ebx@46
  int v25; // edx@47
  int v26; // edx@54
  int v27; // edx@55
  int v28; // edx@56
  int v29; // edx@57
  int v30; // eax@60
  int v31; // ecx@60
  int v32; // edi@60
  int v33; // eax@65
  int v34; // edx@65
  unsigned __int8 v35; // zf@65
  unsigned __int8 v36; // sf@65
  int v37; // ecx@66
  __int16 v38; // ax@69
  int v39; // ST14_4@72
  int v40; // eax@72
  int v41; // ST10_4@72
  int v42; // ST0C_4@72
  int v43; // edx@76
  int v44; // edx@77
  int v45; // edx@78
  char v46; // zf@79
  int v47; // edx@79
  __int16 v48; // ax@80
  int v49; // eax@81
  int v50; // edx@87
  int v51; // edx@88
  int v52; // edx@89
  int v53; // eax@93
  int v54; // ebx@93
  int v55; // edx@94
  int v56; // eax@98
  int v57; // ecx@98
  int v58; // ebx@98
  unsigned __int8 v59; // zf@98
  unsigned __int8 v60; // sf@98
  int v61; // edx@99
  __int16 v62; // ax@102
  int v63; // eax@107
  int v64; // ecx@107
  int v65; // ebx@107
  unsigned __int8 v66; // zf@107
  unsigned __int8 v67; // sf@107
  int v68; // edx@108
  __int16 v69; // ax@111
  signed int v70; // eax@114
  int v71; // ebx@114
  char v72; // zf@114
  int v74; // edi@123
  int v75; // eax@124
  int v76; // ecx@124
  int v77; // ebx@124
  unsigned __int8 v78; // zf@124
  unsigned __int8 v79; // sf@124
  int v80; // edx@125
  __int16 v81; // ax@128
  int v82; // ebx@131
  __int16 v83; // ax@132
  int v84; // ebx@132
  int v85; // ST14_4@132
  int v86; // ST10_4@132
  int v87; // ST0C_4@132
  int v88; // eax@133
  char v89; // zf@139
  int v90; // eax@140
  int v91; // edx@140
  unsigned __int8 v92; // zf@140
  unsigned __int8 v93; // sf@140
  int v94; // ecx@141
  __int16 v95; // ax@144
  int v96; // eax@151
  int v97; // ecx@151
  int v98; // ebx@151
  unsigned __int8 v99; // zf@151
  unsigned __int8 v100; // sf@151
  int v101; // edx@152
  __int16 v102; // ax@155
  int v103; // eax@158
  int v104; // ST34_4@159
  int v105; // eax@159
  int v107; // eax@163
  int v108; // eax@177
  int v109; // ecx@178
  __int16 v110; // ax@181
  __int16 v111; // ax@184
  int v112; // eax@185
  int v113; // eax@191
  int v114; // ecx@191
  char v115; // ST18_1@198
  int v116; // ST14_4@198
  int v117; // eax@198
  int v118; // ST10_4@198
  int v119; // ST0C_4@198
  __int16 v120; // ax@200
  signed int v121; // eax@208
  int v122; // edx@220
  int v123; // ebx@225
  int v124; // eax@234
  int v125; // ebx@234
  int v126; // ecx@235
  __int16 v127; // ax@238
  __int16 v128; // si@241
  int v129; // eax@242
  signed int v130; // eax@245
  int v131; // eax@245
  int v132; // eax@251
  int v133; // ecx@251
  int v134; // ebx@251
  unsigned __int8 v135; // zf@251
  unsigned __int8 v136; // sf@251
  int v137; // edx@252
  __int16 v138; // ax@255
  int v139; // eax@260
  int v140; // edx@261
  int v141; // eax@267
  int v142; // [sp-20h] [bp-4Ch]@28
  signed int v143; // [sp-1Ch] [bp-48h]@27
  int v144; // [sp-18h] [bp-44h]@27
  signed int v145; // [sp-14h] [bp-40h]@27
  int v146; // [sp-10h] [bp-3Ch]@27
  int v147; // [sp-Ch] [bp-38h]@27
  int v148; // [sp-8h] [bp-34h]@27
  char v149; // [sp-8h] [bp-34h]@131
  int v150; // [sp-4h] [bp-30h]@27
  char v151; // [sp-4h] [bp-30h]@131
  signed int v152; // [sp-4h] [bp-30h]@217
  int v153; // [sp+Ch] [bp-20h]@208
  int v154; // [sp+10h] [bp-1Ch]@208
  signed int v155; // [sp+14h] [bp-18h]@207
  signed int v156; // [sp+18h] [bp-14h]@208
  int v157; // [sp+1Ch] [bp-10h]@61
  signed int v158; // [sp+1Ch] [bp-10h]@117
  int v159; // [sp+1Ch] [bp-10h]@158
  signed int v160; // [sp+1Ch] [bp-10h]@172
  int v161; // [sp+1Ch] [bp-10h]@192
  signed int v162; // [sp+20h] [bp-Ch]@1
  int v163; // [sp+20h] [bp-Ch]@60
  int v164; // [sp+20h] [bp-Ch]@72
  signed int v165; // [sp+20h] [bp-Ch]@158
  int v166; // [sp+20h] [bp-Ch]@198
  __int16 v167; // [sp+20h] [bp-Ch]@208
  int v168; // [sp+24h] [bp-8h]@1
  signed int v169; // [sp+24h] [bp-8h]@208
  int v170; // [sp+28h] [bp-4h]@1

  v170 = a1;
  v3 = (int)((char *)array_665230 + 112 * a1);
  v2 = pObjectDescriptionList->pDescriptions + 56 * *(_WORD *)(v3 + 2);
  v162 = a2;
  v168 = a2 & 7;
  if ( (a2 & 7) == 3 )
  {
    a1 = *(_DWORD *)(v3 + 88) & 7;
    if ( (_BYTE)a1 == 3
      && !Actor_sub_40104C(
            (int)((char *)pActors + 836 * (*(_DWORD *)(v3 + 88) >> 3)),
            (int)((char *)pActors + 836 * (a2 >> 3))) )
      return 1;
  }
  else
  {
    if ( (a2 & 7) == 4 && (*(_BYTE *)(v3 + 88) & 7) == 4 )
      return 1;
  }
  if ( dword_ACD834 == 1 )
  {
    LOWORD(a1) = *(_WORD *)(v3 + 26);
    if ( a1 & 4 )
    {
      a1 &= 0xFFFFFFFBu;
      --dword_4F8874;
      *(_WORD *)(v3 + 26) = a1;
    }
  }
  if ( v168 == 6 )
  {
    a1 = *(_DWORD *)(v3 + 88);
    if ( (*(_BYTE *)(v3 + 88) & 7) != 4 )
    {
      a1 = pActors[a1 >> 3].byte_000024;
      *(_BYTE *)(a1 + 2) |= 4u;
    }
  }
  LOWORD(a1) = *(_WORD *)v3;
  v5 = *(_WORD *)v3;
  if ( v5 > 3060 )
  {
    if ( v5 > 6090 )
    {
      if ( v5 > 8090 )
      {
        if ( v5 == 9010 )
          goto LABEL_247;
        if ( v5 != 9030 )
        {
          if ( v5 != 9040 )
          {
            if ( v5 != 9080 )
              return 0;
LABEL_191:
            v113 = a1 + 1;
            v114 = pObjectDescriptionList->uNumObjects;
            v32 = 0;
            *(_WORD *)v3 = v113;
            v163 = 0;
            if ( v114 > 0 )
            {
              v161 = pObjectDescriptionList->pDescriptions + 32;
              while ( (_WORD)v113 != *(_WORD *)v161 )
              {
                ++v163;
                v161 += 56;
                if ( v163 >= v114 )
                  goto LABEL_195;
              }
              goto LABEL_80;
            }
LABEL_195:
            v48 = 0;
            goto LABEL_196;
          }
          goto LABEL_93;
        }
LABEL_172:
        v160 = 17030;
        switch ( (_WORD)a1 )
        {
          case 0x1798:
            v160 = 15040;
            break;
          case 0xFAA:
            v160 = 13010;
            break;
          case 0x2346:
            v160 = 18030;
            break;
        }
        v155 = 1;
        if ( v168 != 3 )
        {
          if ( (_WORD)a1 != 9030 || *(_DWORD *)(v3 + 80) != 4 )
            goto LABEL_246;
          sub_46BEF1((void *)v3);
LABEL_233:
          if ( !v155 )
          {
            v124 = pObjectDescriptionList->uNumObjects;
            ++*(_WORD *)v3;
            v125 = 0;
            if ( v124 <= 0 )
            {
LABEL_238:
              v127 = 0;
            }
            else
            {
              v126 = pObjectDescriptionList->pDescriptions + 32;
              while ( *(_WORD *)v3 != *(_WORD *)v126 )
              {
                ++v125;
                v126 += 56;
                if ( v125 >= v124 )
                  goto LABEL_238;
              }
              v127 = v125;
            }
            *(_WORD *)(v3 + 2) = v127;
            if ( !v127 )
              sub_42F933(v170);
            *(_WORD *)(v3 + 20) = 0;
            *(_WORD *)(v3 + 18) = 0;
            *(_WORD *)(v3 + 16) = 0;
            *(_WORD *)(v3 + 30) = 0;
            v128 = *(_WORD *)(v3 + 24);
            if ( v128 )
              v129 = v128 + 4;
            else
              v129 = 0;
            v150 = 0;
            v148 = 0;
            v147 = v129;
            v131 = 8 * v170;
            v146 = 0;
            v145 = -1;
            LOBYTE(v131) = 8 * v170 | 2;
            v144 = 0;
            v143 = v131;
            v130 = v160;
            goto LABEL_269;
          }
LABEL_246:
          sub_42F933(v170);
          return 0;
        }
        v121 = v162;
        v167 = 0;
        v156 = v121 >> 3;
        v154 = *(_DWORD *)(v3 + 76);
        v169 = *(_DWORD *)(v3 + 80);
        v153 = *(_DWORD *)(v3 + 72);
        if ( (_WORD)a1 == 9030 )
        {
          v167 = 2;
          if ( v169 == 2 )
          {
            v167 = 3;
          }
          else
          {
            if ( v169 >= 3 )
              v167 = 4;
          }
          pActors[v156].byte_000024[2] |= 8u;
        }
        if ( v5 == 6040 )
        {
          v152 = 7;
        }
        else
        {
          if ( v5 == 8030 )
          {
            v152 = 9;
          }
          else
          {
            if ( v5 != 9030 )
            {
              v122 = v153;
LABEL_222:
              if ( (_WORD)a1 != 9030 || v169 != 4 )
              {
                v123 = 836 * v156;
                if ( sub_427662(&pActors[v156], v122) )
                {
                  v155 = 0;
                  if ( *(_WORD *)v3 == 8030 )
                  {
                    //*(__int16 *)((char *)word_5FF208 + v123) = 0;
                   pActors[v156].word_0000B0 = 0;
                    sub_45976D(&pActors[v156]);
                  }
                  sub_4584E0(
                    (int)((char *)&unk_5FF22C + 16 * v153 + v123),
                    pParty_global->qword_00002C + (signed __int64)((double)(v154 << 7) * 0.03333333507180214),
                    (unsigned __int64)(pParty_global->qword_00002C
                                     + (signed int)(signed __int64)((double)(v154 << 7) * 0.03333333507180214)) >> 32,
                    v169,
                    v167,
                    0,
                    0);
                }
              }
              else
              {
                sub_46BEF1((void *)v3);
              }
              *(_DWORD *)(v3 + 76) = 0;
              *(_DWORD *)(v3 + 80) = 0;
              *(_DWORD *)(v3 + 72) = 0;
              goto LABEL_233;
            }
            v152 = 10;
          }
        }
        v122 = v152;
        goto LABEL_222;
      }
      if ( v5 == 8090 || v5 == 7030 || v5 == 7090 || v5 == 8000 )
        goto LABEL_93;
      if ( v5 == 8010 )
      {
        if ( v168 == 3 )
        {
          if ( sub_438BDF(word_5FF1B8[418 * (v162 >> 3)], 1) )
            sub_43A97E(v170, v162);
        }
        v108 = pObjectDescriptionList->uNumObjects;
        ++*(_WORD *)v3;
        v8 = 0;
        v54 = 0;
        if ( v108 > 0 )
        {
          v109 = pObjectDescriptionList->pDescriptions + 32;
          while ( *(_WORD *)v3 != *(_WORD *)v109 )
          {
            ++v54;
            v109 += 56;
            if ( v54 >= v108 )
              goto LABEL_181;
          }
          goto LABEL_202;
        }
        goto LABEL_181;
      }
      v89 = v5 == 8030;
    }
    else
    {
      if ( v5 == 6090 )
        goto LABEL_93;
      if ( v5 <= 4070 )
      {
        if ( v5 != 4070 )
        {
          v50 = v5 - 3090;
          if ( v50 )
          {
            v51 = v50 - 2;
            if ( v51 )
            {
              v52 = v51 - 908;
              if ( !v52 )
                goto LABEL_93;
              v47 = v52 - 30;
              v46 = v47 == 0;
              goto LABEL_91;
            }
            v56 = a1 - 1;
            v57 = pObjectDescriptionList->uNumObjects;
            v8 = 0;
            v58 = 0;
            v59 = pObjectDescriptionList->uNumObjects == 0;
            v60 = pObjectDescriptionList->uNumObjects < 0;
            *(_WORD *)v3 = v56;
            if ( v60 | v59 )
            {
LABEL_102:
              v62 = 0;
            }
            else
            {
              v61 = pObjectDescriptionList->pDescriptions + 32;
              while ( (_WORD)v56 != *(_WORD *)v61 )
              {
                ++v58;
                v61 += 56;
                if ( v58 >= v57 )
                  goto LABEL_102;
              }
              v62 = v58;
            }
            *(_WORD *)(v3 + 2) = v62;
            if ( !v62 )
              sub_42F933(v170);
            v13 = v170;
            *(_WORD *)(v3 + 20) = 0;
            *(_WORD *)(v3 + 18) = 0;
            *(_WORD *)(v3 + 16) = 0;
            *(_WORD *)(v3 + 30) = 0;
            sub_43A97E(v170, v162);
LABEL_35:
            v14 = *(_WORD *)(v3 + 24);
            if ( v14 == (_WORD)v8 )
              v15 = 0;
            else
              v15 = v14 + 4;
            v150 = v8;
            v148 = v8;
            v147 = v15;
            v107 = v13;
LABEL_267:
            v141 = 8 * v107;
            v146 = v8;
            v145 = -1;
            LOBYTE(v141) = v141 | 2;
            v144 = v8;
            v143 = v141;
LABEL_268:
            v130 = word_4EE088[*(_DWORD *)(v3 + 72)];
LABEL_269:
            v142 = v130 + 1;
            goto LABEL_29;
          }
          v63 = a1 + 2;
          v64 = pObjectDescriptionList->uNumObjects;
          v8 = 0;
          v65 = 0;
          v66 = pObjectDescriptionList->uNumObjects == 0;
          v67 = pObjectDescriptionList->uNumObjects < 0;
          *(_WORD *)v3 = v63;
          if ( v67 | v66 )
          {
LABEL_111:
            v69 = 0;
          }
          else
          {
            v68 = pObjectDescriptionList->pDescriptions + 32;
            while ( (_WORD)v63 != *(_WORD *)v68 )
            {
              ++v65;
              v68 += 56;
              if ( v65 >= v64 )
                goto LABEL_111;
            }
            v69 = v65;
          }
          *(_WORD *)(v3 + 2) = v69;
          if ( !v69 )
            sub_42F933(v170);
          v71 = *(_WORD *)(v3 + 22) - pClass59_global->dword_001868;
          v72 = *(_DWORD *)(v3 + 80) == 4;
          *(_WORD *)(v3 + 20) = 0;
          *(_WORD *)(v3 + 18) = 0;
          *(_WORD *)(v3 + 16) = 0;
          v70 = 7;
          if ( v72 )
            v70 = 9;
          if ( v70 > 0 )
          {
            v158 = v70;
            do
            {
              v71 += pClass59_global->uNumTableEntries >> 1;
              sub_42F5ED(v3, v71, 0, 1000, 0);
            }
            while ( v158-- != 1 );
          }
LABEL_160:
          v13 = v170;
LABEL_34:
          sub_42F933(v13);
          goto LABEL_35;
        }
        if ( v168 == 6 || v168 == 5 || (v74 = 0, !v168) )
          return 1;
        v75 = a1 + 1;
        v76 = pObjectDescriptionList->uNumObjects;
        v77 = 0;
        v78 = pObjectDescriptionList->uNumObjects == 0;
        v79 = pObjectDescriptionList->uNumObjects < 0;
        *(_WORD *)v3 = v75;
        if ( v79 | v78 )
        {
LABEL_128:
          v81 = 0;
        }
        else
        {
          v80 = pObjectDescriptionList->pDescriptions + 32;
          while ( (_WORD)v75 != *(_WORD *)v80 )
          {
            ++v77;
            v80 += 56;
            if ( v77 >= v76 )
              goto LABEL_128;
          }
          v81 = v77;
        }
        *(_WORD *)(v3 + 2) = v81;
        if ( !v81 )
          sub_42F933(v170);
        v151 = 0;
        v82 = v170;
        v149 = 0;
LABEL_132:
        v85 = *(_DWORD *)(v3 + 12);
        v86 = *(_DWORD *)(v3 + 8);
        v84 = 8 * v82 | 2;
        *(_WORD *)(v3 + 20) = v74;
        *(_WORD *)(v3 + 18) = v74;
        v87 = *(_DWORD *)(v3 + 4);
        *(_WORD *)(v3 + 16) = v74;
        *(_WORD *)(v3 + 30) = v74;
        sub_40261D(&dword_50FE08, v84, 512, v87, v86, v85, v149, v151);
        v83 = *(_WORD *)(v3 + 24);
        if ( v83 == (_WORD)v74 )
          v88 = 0;
        else
          v88 = v83 + 4;
        v150 = v74;
        v148 = v74;
        v147 = v88;
        v146 = v74;
        v145 = -1;
        v144 = v74;
        v143 = v84;
        goto LABEL_268;
      }
      if ( v5 == 4090 )
      {
        v96 = a1 + 2;
        v97 = pObjectDescriptionList->uNumObjects;
        v8 = 0;
        v98 = 0;
        v99 = pObjectDescriptionList->uNumObjects == 0;
        v100 = pObjectDescriptionList->uNumObjects < 0;
        *(_WORD *)v3 = v96;
        if ( v100 | v99 )
        {
LABEL_155:
          v102 = 0;
        }
        else
        {
          v101 = pObjectDescriptionList->pDescriptions + 32;
          while ( (_WORD)v96 != *(_WORD *)v101 )
          {
            ++v98;
            v101 += 56;
            if ( v98 >= v97 )
              goto LABEL_155;
          }
          v102 = v98;
        }
        *(_WORD *)(v3 + 2) = v102;
        if ( !v102 )
          sub_42F933(v170);
        v103 = *(_WORD *)(v3 + 22) - pClass59_global->dword_001868;
        *(_WORD *)(v3 + 20) = 0;
        *(_WORD *)(v3 + 18) = 0;
        *(_WORD *)(v3 + 16) = 0;
        v159 = v103;
        v165 = 7;
        do
        {
          sub_4BE59E((int)&unk_F8BAD8, -128, 128);
          v104 = sub_4BE623((int)&unk_F8BAD8);
          sub_4BE59E((int)&unk_F8BAD8, 5, 500);
          v105 = sub_4BE623((int)&unk_F8BAD8);
          v159 += pClass59_global->uNumTableEntries >> 1;
          sub_42F5ED(v3, v104 + v159, 0, v105, 0);
        }
        while ( v165-- != 1 );
        goto LABEL_160;
      }
      if ( v5 == 4092 )
      {
        v90 = pObjectDescriptionList->uNumObjects;
        v74 = 0;
        v91 = 0;
        v92 = pObjectDescriptionList->uNumObjects == 0;
        v93 = pObjectDescriptionList->uNumObjects < 0;
        *(_WORD *)v3 = 4091;
        if ( v93 | v92 )
        {
LABEL_144:
          v95 = 0;
        }
        else
        {
          v94 = pObjectDescriptionList->pDescriptions + 32;
          while ( *(_WORD *)v94 != 4091 )
          {
            ++v91;
            v94 += 56;
            if ( v91 >= v90 )
              goto LABEL_144;
          }
          v95 = v91;
        }
        *(_WORD *)(v3 + 2) = v95;
        if ( !v95 )
          sub_42F933(v170);
        v151 = 0;
        v82 = v170;
        v149 = *(_BYTE *)(v3 + 97);
        goto LABEL_132;
      }
      if ( v5 == 4100 || v5 == 6010 )
        goto LABEL_93;
      v89 = v5 == 6040;
    }
    if ( !v89 )
      return 0;
    goto LABEL_172;
  }
  if ( v5 == 3060 )
    goto LABEL_93;
  if ( v5 <= 555 )
  {
    if ( v5 == 555 )
    {
      sub_43A97E(v170, v162);
      v23 = pObjectDescriptionList->uNumObjects;
      ++*(_WORD *)v3;
      v18 = 0;
      v24 = 0;
      if ( v23 <= 0 )
      {
LABEL_41:
        v22 = 0;
      }
      else
      {
        v25 = pObjectDescriptionList->pDescriptions + 32;
        while ( *(_WORD *)v3 != *(_WORD *)v25 )
        {
          ++v24;
          v25 += 56;
          if ( v24 >= v23 )
            goto LABEL_41;
        }
        v22 = v24;
      }
LABEL_42:
      *(_WORD *)(v3 + 2) = v22;
      if ( v22 == v18 )
        sub_42F933(v170);
      *(_WORD *)(v3 + 20) = v18;
      *(_WORD *)(v3 + 18) = v18;
      *(_WORD *)(v3 + 16) = v18;
      *(_WORD *)(v3 + 30) = v18;
    }
    else
    {
      switch ( v5 )
      {
        case 500:
        case 505:
        case 510:
        case 515:
        case 520:
        case 525:
        case 530:
        case 535:
        case 540:
          sub_43A97E(v170, v162);
          v6 = pObjectDescriptionList->uNumObjects;
          ++*(_WORD *)v3;
          v8 = 0;
          v7 = 0;
          if ( v6 <= 0 )
            goto LABEL_23;
          v9 = pObjectDescriptionList->pDescriptions + 32;
          break;
        case 545:
        case 550:
          if ( *(_DWORD *)(v3 + 36) != 405 && *(_DWORD *)(v3 + 48) != 3 )
          {
            v13 = v170;
            v8 = 0;
            *(_WORD *)(v3 + 20) = 0;
            *(_WORD *)(v3 + 18) = 0;
            *(_WORD *)(v3 + 16) = 0;
            *(_WORD *)(v3 + 30) = 0;
            sub_43A97E(v170, v162);
            goto LABEL_34;
          }
          v16 = pObjectDescriptionList->uNumObjects;
          v18 = 0;
          v17 = 0;
          v19 = pObjectDescriptionList->uNumObjects == 0;
          v20 = pObjectDescriptionList->uNumObjects < 0;
          *(_WORD *)v3 = 600;
          if ( v20 | v19 )
            goto LABEL_41;
          v21 = pObjectDescriptionList->pDescriptions + 32;
          while ( *(_WORD *)v21 != 600 )
          {
            ++v17;
            v21 += 56;
            if ( v17 >= v16 )
              goto LABEL_41;
          }
          v22 = v17;
          goto LABEL_42;
        default:
          return 0;
      }
      while ( *(_WORD *)v3 != *(_WORD *)v9 )
      {
        ++v7;
        v9 += 56;
        if ( v7 >= v6 )
        {
LABEL_23:
          v10 = 0;
          goto LABEL_24;
        }
      }
      v10 = v7;
LABEL_24:
      *(_WORD *)(v3 + 2) = v10;
      if ( !v10 )
        sub_42F933(v170);
      v11 = *(_WORD *)v3 == 555;
      *(_WORD *)(v3 + 20) = 0;
      *(_WORD *)(v3 + 18) = 0;
      *(_WORD *)(v3 + 16) = 0;
      *(_WORD *)(v3 + 30) = 0;
      if ( !v11 )
        goto LABEL_27;
    }
    return 0;
  }
  if ( v5 > 1100 )
  {
    v43 = v5 - 2030;
    if ( !v43 )
      goto LABEL_247;
    v44 = v43 - 30;
    if ( v44 )
    {
      v45 = v44 - 40;
      if ( !v45 )
        goto LABEL_59;
      v47 = v45 - 910;
      v46 = v47 == 0;
LABEL_91:
      if ( !v46 && v47 != 20 )
        return 0;
    }
LABEL_93:
    sub_43A97E(v170, v162);
    v53 = pObjectDescriptionList->uNumObjects;
    ++*(_WORD *)v3;
    v8 = 0;
    v54 = 0;
    if ( v53 > 0 )
    {
      v55 = pObjectDescriptionList->pDescriptions + 32;
      while ( *(_WORD *)v3 != *(_WORD *)v55 )
      {
        ++v54;
        v55 += 56;
        if ( v54 >= v53 )
          goto LABEL_181;
      }
      goto LABEL_202;
    }
LABEL_181:
    v110 = 0;
LABEL_182:
    *(_WORD *)(v3 + 2) = v110;
    if ( v110 == (_WORD)v8 )
      sub_42F933(v170);
    v111 = *(_WORD *)(v3 + 24);
    *(_WORD *)(v3 + 20) = v8;
    *(_WORD *)(v3 + 18) = v8;
    *(_WORD *)(v3 + 16) = v8;
    *(_WORD *)(v3 + 30) = v8;
    if ( v111 == (_WORD)v8 )
      v112 = 0;
    else
      v112 = v111 + 4;
    v150 = v8;
    v148 = v8;
    v147 = v112;
    v107 = v170;
    goto LABEL_267;
  }
  if ( v5 == 1100 )
    goto LABEL_93;
  v26 = v5 - 600;
  if ( !v26 )
  {
    v33 = pObjectDescriptionList->uNumObjects;
    v34 = 0;
    v35 = pObjectDescriptionList->uNumObjects == 0;
    v36 = pObjectDescriptionList->uNumObjects < 0;
    *(_WORD *)v3 = 601;
    if ( v36 | v35 )
    {
LABEL_69:
      v38 = 0;
    }
    else
    {
      v37 = pObjectDescriptionList->pDescriptions + 32;
      while ( *(_WORD *)v37 != 601 )
      {
        ++v34;
        v37 += 56;
        if ( v34 >= v33 )
          goto LABEL_69;
      }
      v38 = v34;
    }
    *(_WORD *)(v3 + 2) = v38;
    if ( !v38 )
      sub_42F933(v170);
    v39 = *(_DWORD *)(v3 + 12);
    *(_WORD *)(v3 + 20) = 0;
    v40 = 8 * v170;
    v41 = *(_DWORD *)(v3 + 8);
    LOBYTE(v40) = 8 * v170 | 2;
    *(_WORD *)(v3 + 18) = 0;
    *(_WORD *)(v3 + 16) = 0;
    v42 = *(_DWORD *)(v3 + 4);
    *(_WORD *)(v3 + 30) = 0;
    v164 = v40;
    sub_40261D(&dword_50FE08, v40, 512, v42, v41, v39, 0, 0);
    if ( *(_BYTE *)(v2 + 39) & 1 )
      sub_440E91(array_5118E8, *(_DWORD *)(v3 + 4), *(_DWORD *)(v3 + 8), *(_DWORD *)(v3 + 12), 0, *(_DWORD *)(v2 + 44));
    v150 = 0;
    v148 = 0;
    v147 = 0;
    v146 = 0;
    v145 = -1;
    v144 = 0;
    v143 = v164;
    goto LABEL_28;
  }
  v27 = v26 - 410;
  if ( !v27 )
    goto LABEL_93;
  v28 = v27 - 40;
  if ( !v28 )
    goto LABEL_191;
  v29 = v28 - 10;
  if ( v29 )
  {
    if ( v29 != 20 )
      return 0;
LABEL_59:
    if ( v168 != 3 )
    {
      v30 = a1 + 1;
      v31 = pObjectDescriptionList->uNumObjects;
      v32 = 0;
      *(_WORD *)v3 = v30;
      v163 = 0;
      if ( v31 > 0 )
      {
        v157 = pObjectDescriptionList->pDescriptions + 32;
        while ( (_WORD)v30 != *(_WORD *)v157 )
        {
          ++v163;
          v157 += 56;
          if ( v163 >= v31 )
            goto LABEL_195;
        }
LABEL_80:
        v48 = v163;
LABEL_196:
        *(_WORD *)(v3 + 2) = v48;
        if ( v48 == (_WORD)v32 )
          sub_42F933(v170);
        v115 = *(_BYTE *)(v3 + 97);
        v116 = *(_DWORD *)(v3 + 12);
        *(_WORD *)(v3 + 30) = v32;
        v117 = 8 * v170;
        v118 = *(_DWORD *)(v3 + 8);
        LOBYTE(v117) = 8 * v170 | 2;
        *(_WORD *)(v3 + 16) = v32;
        *(_WORD *)(v3 + 18) = v32;
        v119 = *(_DWORD *)(v3 + 4);
        *(_WORD *)(v3 + 20) = v32;
        v166 = v117;
        sub_40261D(&dword_50FE08, v117, 512, v119, v118, v116, v115, v32);
        if ( *(_BYTE *)(v2 + 39) & 1 )
          sub_440E91(array_5118E8,
            *(_DWORD *)(v3 + 4),
            *(_DWORD *)(v3 + 8),
            *(_DWORD *)(v3 + 12),
            v32,
            *(_DWORD *)(v2 + 44));
        v120 = *(_WORD *)(v3 + 24);
        if ( v120 == (_WORD)v32 )
          v49 = 0;
        else
          v49 = v120 + 4;
        v150 = v32;
        v148 = v32;
        v147 = v49;
        v146 = v32;
        v145 = -1;
        v144 = v32;
        v143 = v166;
        goto LABEL_268;
      }
      goto LABEL_195;
    }
    return 1;
  }
LABEL_247:
  if ( v168 == 6 || v168 == 5 || (v8 = 0, !v168) )
    return 1;
  if ( v168 != 2 )
  {
    sub_43A97E(v170, v162);
    v139 = pObjectDescriptionList->uNumObjects;
    ++*(_WORD *)v3;
    v54 = 0;
    if ( v139 > 0 )
    {
      v140 = pObjectDescriptionList->pDescriptions + 32;
      while ( *(_WORD *)v3 != *(_WORD *)v140 )
      {
        ++v54;
        v140 += 56;
        if ( v54 >= v139 )
          goto LABEL_181;
      }
LABEL_202:
      v110 = v54;
      goto LABEL_182;
    }
    goto LABEL_181;
  }
  v132 = a1 + 1;
  v133 = pObjectDescriptionList->uNumObjects;
  v134 = 0;
  v135 = pObjectDescriptionList->uNumObjects == 0;
  v136 = pObjectDescriptionList->uNumObjects < 0;
  *(_WORD *)v3 = v132;
  if ( v136 | v135 )
  {
LABEL_255:
    v138 = 0;
  }
  else
  {
    v137 = pObjectDescriptionList->pDescriptions + 32;
    while ( (_WORD)v132 != *(_WORD *)v137 )
    {
      ++v134;
      v137 += 56;
      if ( v134 >= v133 )
        goto LABEL_255;
    }
    v138 = v134;
  }
  *(_WORD *)(v3 + 2) = v138;
  if ( !v138 )
    sub_42F933(v170);
  *(_WORD *)(v3 + 20) = 0;
  *(_WORD *)(v3 + 18) = 0;
  *(_WORD *)(v3 + 16) = 0;
  *(_WORD *)(v3 + 30) = 0;
LABEL_27:
  v150 = v8;
  v148 = v8;
  v147 = v8;
  v12 = 8 * v170;
  v146 = v8;
  v145 = -1;
  LOBYTE(v12) = 8 * v170 | 2;
  v144 = v8;
  v143 = v12;
LABEL_28:
  v142 = 8;
LABEL_29:
  AudioPlayer_sub_4AA306(pAudioPlayer, v142, v143, v144, v145, v146, v147, v148, v150);
  return 0;
}

//----- (0046CC4B) --------------------------------------------------------
int __cdecl sub_46CC4B()
{
  int result; // eax@1
  int v1; // ebx@2
  signed int v2; // edi@2
  __int16 *v3; // esi@2
  int v4; // eax@3
  unsigned int v5; // ecx@3
  int v6; // ebx@3
  unsigned int v7; // edx@6
  unsigned int v8; // edx@8
  int v9; // edi@13
  int v10; // eax@14
  unsigned int v11; // ecx@14
  int v12; // ebx@14
  int v13; // ebx@14
  int v14; // edx@15
  unsigned int v15; // edx@17
  unsigned int v16; // edx@19
  int *v17; // edi@25
  int v18; // eax@26
  unsigned int v19; // ecx@26
  int v20; // ebx@26
  int v21; // ebx@26
  int v22; // edx@27
  unsigned int v23; // edx@29
  unsigned int v24; // edx@31
  unsigned __int8 v25; // sf@35
  unsigned __int8 v26; // of@35
  int v27; // [sp+0h] [bp-24h]@3
  int v28; // [sp+0h] [bp-24h]@14
  int v29; // [sp+0h] [bp-24h]@26
  int v30; // [sp+4h] [bp-20h]@3
  int v31; // [sp+4h] [bp-20h]@14
  int v32; // [sp+4h] [bp-20h]@26
  signed int v33; // [sp+8h] [bp-1Ch]@2
  int v34; // [sp+Ch] [bp-18h]@2
  int v35; // [sp+10h] [bp-14h]@2
  int v36; // [sp+14h] [bp-10h]@1
  int v37; // [sp+18h] [bp-Ch]@2
  int v38; // [sp+1Ch] [bp-8h]@3
  signed int v39; // [sp+1Ch] [bp-8h]@12
  signed int v40; // [sp+20h] [bp-4h]@24

  result = 0;
  v36 = 0;
  if ( dword_6836C8 > 0 )
  {
    do
    {
      v3 = &array_6836D0[dword_6807E8[result]];
      v2 = v3[12];
      v1 = *((_DWORD *)v3 + 2);
      v35 = *((_DWORD *)v3 + 1);
      v34 = *((_DWORD *)v3 + 2);
      v37 = *((_DWORD *)v3 + 3);
      v33 = v3[12];
      if ( *((_BYTE *)v3 + 2) & 1 )
      {
        v38 = abs(*((_DWORD *)v3 + 1) - pParty_global->sPartyPosX);
        v27 = abs(v1 - pParty_global->sPartyPosY);
        v30 = abs(v37 - pParty_global->sPartyPosZ);
        v4 = v38;
        v6 = v27;
        v5 = v30;
        if ( v38 < v27 )
        {
          v4 = v27;
          v6 = v38;
        }
        if ( v4 < v30 )
        {
          v7 = v4;
          v4 = v30;
          v5 = v7;
        }
        if ( v6 < (signed int)v5 )
        {
          v8 = v5;
          v5 = v6;
          v6 = v8;
        }
        if ( (signed int)(((unsigned int)(11 * v6) >> 5) + (v5 >> 2) + v4) < v2 )
          sub_44684A_LooksLikeEventProcessor(v3[11], 8 * v36 | 5, 1);
      }
      if ( *((_BYTE *)v3 + 2) & 2 )
      {
        v39 = 0;
        if ( (signed int)uNumActors > 0 )
        {
          v9 = &pActors[0].sActorPosY;
          do
          {
            v13 = abs(v35 - *(_WORD *)(v9 - 2));
            v31 = abs(v34 - *(_WORD *)v9);
            v28 = abs(v37 - *(_WORD *)(v9 + 2));
            v10 = v13;
            v12 = v31;
            v11 = v28;
            if ( v10 < v31 )
            {
              v14 = v10;
              v10 = v31;
              v12 = v14;
            }
            if ( v10 < v28 )
            {
              v15 = v10;
              v10 = v28;
              v11 = v15;
            }
            if ( v12 < (signed int)v11 )
            {
              v16 = v11;
              v11 = v12;
              v12 = v16;
            }
            if ( (signed int)(((unsigned int)(11 * v12) >> 5) + (v11 >> 2) + v10) < v33 )
              sub_44684A_LooksLikeEventProcessor(v3[11], 0, 1);
            ++v39;
            v9 += 836;
          }
          while ( v39 < (signed int)uNumActors );
        }
      }
      if ( *((_BYTE *)v3 + 2) & 4 )
      {
        v40 = 0;
        if ( (signed int)uNumElementsIn665230 > 0 )
        {
          v17 = &array_665230[0].sItemPosY;
          do
          {
            v21 = abs(v35 - *(v17 - 1));
            v32 = abs(v34 - *v17);
            v29 = abs(v37 - v17[1]);
            v18 = v21;
            v20 = v32;
            v19 = v29;
            if ( v18 < v32 )
            {
              v22 = v18;
              v18 = v32;
              v20 = v22;
            }
            if ( v18 < v29 )
            {
              v23 = v18;
              v18 = v29;
              v19 = v23;
            }
            if ( v20 < (signed int)v19 )
            {
              v24 = v19;
              v19 = v20;
              v20 = v24;
            }
            if ( (signed int)(((unsigned int)(11 * v20) >> 5) + (v19 >> 2) + v18) < v33 )
              sub_44684A_LooksLikeEventProcessor(v3[11], 0, 1);
            ++v40;
            v17 += 28;
          }
          while ( v40 < (signed int)uNumElementsIn665230 );
        }
      }
      result = v36 + 1;
      compile_error;//v26 = __SETO__(v36 + 1, dword_6836C8);
      v25 = v36++ + 1 - dword_6836C8 < 0;
    }
    while ( v25 ^ v26 );
  }
  return result;
}

//----- (0046CEC3) --------------------------------------------------------
int __fastcall sub_46CEC3(signed int a1, signed int a2, int a3, int a4, int a5)
{
  int v5; // edx@1
  int v6; // ecx@1
  int v7; // edi@1
  int v8; // esi@2
  int v9; // eax@8
  int v10; // edi@8
  int v11; // ecx@10
  int v12; // eax@10
  int v13; // ecx@13
  signed int v14; // ebx@14
  int v15; // eax@16
  int v16; // edx@19
  int v17; // ST18_4@19
  signed int v18; // edx@19
  signed __int64 v19; // qtt@19
  char v20; // al@25
  int v21; // eax@27
  int v22; // ecx@29
  unsigned __int8 v23; // sf@30
  unsigned __int8 v24; // of@30
  int v25; // eax@33
  int v26; // esi@39
  int v27; // edi@39
  int v28; // esi@41
  int v29; // ecx@43
  signed int v30; // eax@45
  int v31; // ebx@47
  int v32; // edx@49
  int v33; // ST10_4@49
  signed int v34; // edx@49
  signed __int64 v35; // qtt@49
  int v36; // eax@54
  signed int v37; // esi@56
  int result; // eax@57
  int v39; // edi@61
  int v40; // edx@62
  int v41; // [sp+Ch] [bp-34h]@1
  int v42; // [sp+10h] [bp-30h]@2
  int v43; // [sp+14h] [bp-2Ch]@12
  int v44; // [sp+18h] [bp-28h]@1
  int v45; // [sp+1Ch] [bp-24h]@1
  int v46; // [sp+20h] [bp-20h]@10
  int v47; // [sp+24h] [bp-1Ch]@10
  signed int v48; // [sp+24h] [bp-1Ch]@38
  bool v49; // [sp+24h] [bp-1Ch]@43
  bool v50; // [sp+28h] [bp-18h]@10
  bool v51; // [sp+28h] [bp-18h]@41
  bool v52; // [sp+2Ch] [bp-14h]@12
  int v53; // [sp+2Ch] [bp-14h]@41
  signed int v54; // [sp+30h] [bp-10h]@7
  signed int v55; // [sp+30h] [bp-10h]@10
  signed int v56; // [sp+30h] [bp-10h]@41
  signed int v57; // [sp+34h] [bp-Ch]@1
  signed int v58; // [sp+38h] [bp-8h]@1
  signed int v59; // [sp+3Ch] [bp-4h]@1
  int v60; // [sp+4Ch] [bp+Ch]@1
  signed int i; // [sp+4Ch] [bp+Ch]@32

  v7 = dword_6BE654 + 116 * a4;
  v59 = a2;
  v58 = a1;
  v6 = 0;
  v57 = 0;
  v45 = v7;
  v44 = *(_DWORD *)(v7 + 8);
  v5 = dword_6BE63C;
  v41 = *(_WORD *)(v7 + 4);
  v60 = 0;
  if ( (signed int)*(_WORD *)(v7 + 4) > 0 )
  {
    do
    {
      v42 = v44 + 2 * v6;
      v8 = dword_6BE644 + 96 * *(_WORD *)v42;
      if ( !(*(_BYTE *)(v8 + 47) & 0x20) )
      {
        if ( v58 <= *(_WORD *)(v8 + 82) )
        {
          if ( v58 >= *(_WORD *)(v8 + 80) )
          {
            if ( v59 <= *(_WORD *)(v8 + 86) )
            {
              if ( v59 >= *(_WORD *)(v8 + 84) )
              {
                v54 = 0;
                if ( *(_BYTE *)(v8 + 93) )
                {
                  do
                  {
                    v9 = 2 * v54;
                    v10 = 4 * v54;
                    word_721460[2 * v54] = *(_WORD *)(2 * v54 + *(_DWORD *)(v8 + 52))
                                         + *(_WORD *)(v5 + 6 * *(_WORD *)(*(_DWORD *)(v8 + 48) + 2 * v54));
                    word_721390[2 * v54] = *(_WORD *)(v9 + *(_DWORD *)(v8 + 56))
                                         + *(_WORD *)(v5 + 6 * *(_WORD *)(*(_DWORD *)(v8 + 48) + v9) + 2);
                    word_721462[2 * v54++] = *(_WORD *)(v9 + *(_DWORD *)(v8 + 52))
                                           + *(_WORD *)(v5 + 6 * *(_WORD *)(*(_DWORD *)(v8 + 48) + v9 + 2));
                    *(__int16 *)((char *)word_721392 + v10) = *(_WORD *)(v9 + *(_DWORD *)(v8 + 56))
                                                            + *(_WORD *)(v5
                                                                       + 6 * *(_WORD *)(*(_DWORD *)(v8 + 48) + v9 + 2)
                                                                       + 2);
                  }
                  while ( v54 < *(_BYTE *)(v8 + 93) );
                  v7 = v45;
                }
                v46 = 2 * *(_BYTE *)(v8 + 93);
                v12 = 4 * *(_BYTE *)(v8 + 93);
                *(__int16 *)((char *)word_721460 + v12) = word_721460[0];
                *(__int16 *)((char *)word_721390 + v12) = word_721390[0];
                v50 = word_721390[0] >= v59;
                v11 = 0;
                v55 = 0;
                v47 = 0;
                if ( v46 > 0 )
                {
                  do
                  {
                    if ( v55 >= 2 )
                      break;
                    v43 = word_721392[v11];
                    v52 = word_721392[v11] >= v59;
                    if ( v50 == v52 )
                    {
                      v13 = v47;
                    }
                    else
                    {
                      v13 = v47;
                      v14 = word_721462[v47] >= v58 ? 0 : 2;
                      v15 = v14 | word_721460[v47] < v58;
                      if ( v15 != 3 )
                      {
                        if ( !v15
                          || (v16 = word_721390[v47],
                              v17 = v43 - v16,
                              v18 = v59 - v16,
                              LODWORD(v19) = v18 << 16,
                              HIDWORD(v19) = v18 >> 16,
                              v5 = dword_6BE63C,
                              (signed int)(((unsigned __int64)(((signed int)word_721462[v47]
                                                              - (signed int)word_721460[v47])
                                                             * (signed int)(v19 / v17)) >> 16)
                                         + word_721460[v47]) >= v58) )
                          ++v55;
                      }
                    }
                    v11 = v13 + 1;
                    v50 = v52;
                    v47 = v11;
                  }
                  while ( v11 < v46 );
                  if ( v55 == 1 )
                  {
                    if ( v57 >= 50 )
                      break;
                    v20 = *(_BYTE *)(v8 + 92);
                    if ( v20 == 3 || v20 == 5 )
                    {
                      v21 = *(_WORD *)(v5 + 6 * **(_WORD **)(v8 + 48) + 4);
                    }
                    else
                    {
                      v5 = dword_6BE63C;
                      v21 = ((unsigned __int64)(*(_DWORD *)(v8 + 32) * v58) >> 16)
                          + ((unsigned __int64)(*(_DWORD *)(v8 + 36) * v59) >> 16)
                          + *(_WORD *)(v8 + 42);
                    }
                    v22 = 4 * v57++;
                    *(int *)((char *)dword_7212C8 + v22) = v21;
                    *(int *)((char *)dword_721200 + v22) = *(_WORD *)v42;
                  }
                }
              }
            }
          }
        }
      }
      v6 = v60 + 1;
      compile_error;//v24 = __SETO__(v60 + 1, v41);
      v23 = v60++ + 1 - v41 < 0;
    }
    while ( v23 ^ v24 );
  }
  if ( *(_BYTE *)v7 & 8 )
  {
    for ( i = 0; i < *(_WORD *)(v7 + 36); ++i )
    {
      v25 = dword_6BE644 + 96 * *(_WORD *)(*(_DWORD *)(v7 + 40) + 2 * i);
      if ( *(_BYTE *)(v25 + 92) == 3 )
      {
        if ( v58 <= *(_WORD *)(v25 + 82) )
        {
          if ( v58 >= *(_WORD *)(v25 + 80) )
          {
            if ( v59 <= *(_WORD *)(v25 + 86) )
            {
              if ( v59 >= *(_WORD *)(v25 + 84) )
              {
                v48 = 0;
                if ( *(_BYTE *)(v25 + 93) )
                {
                  do
                  {
                    v26 = 2 * v48;
                    v27 = 4 * v48;
                    word_721460[2 * v48] = *(_WORD *)(2 * v48 + *(_DWORD *)(v25 + 52))
                                         + *(_WORD *)(v5 + 6 * *(_WORD *)(2 * v48 + *(_DWORD *)(v25 + 48)));
                    word_721390[2 * v48] = *(_WORD *)(v26 + *(_DWORD *)(v25 + 56))
                                         + *(_WORD *)(v5 + 6 * *(_WORD *)(v26 + *(_DWORD *)(v25 + 48)) + 2);
                    word_721462[2 * v48++] = *(_WORD *)(v26 + *(_DWORD *)(v25 + 52) + 2)
                                           + *(_WORD *)(v5 + 6 * *(_WORD *)(*(_DWORD *)(v25 + 48) + v26 + 2));
                    *(__int16 *)((char *)word_721392 + v27) = *(_WORD *)(v26 + *(_DWORD *)(v25 + 56) + 2)
                                                            + *(_WORD *)(v5
                                                                       + 6 * *(_WORD *)(*(_DWORD *)(v25 + 48) + v26 + 2)
                                                                       + 2);
                  }
                  while ( v48 < *(_BYTE *)(v25 + 93) );
                  v7 = v45;
                }
                v28 = 2 * *(_BYTE *)(v25 + 93);
                word_721460[2 * *(_BYTE *)(v25 + 93)] = word_721460[0];
                word_721390[v28] = word_721390[0];
                v56 = 0;
                v53 = 0;
                v51 = word_721390[0] >= v59;
                if ( v28 > 0 )
                {
                  do
                  {
                    if ( v56 >= 2 )
                      break;
                    v29 = 2 * v53;
                    v49 = word_721392[v53] >= v59;
                    if ( v51 != v49 )
                    {
                      if ( *(__int16 *)((char *)word_721462 + v29) >= v58 )
                        v30 = 0;
                      else
                        v30 = 2;
                      v31 = v30 | *(__int16 *)((char *)word_721460 + v29) < v58;
                      if ( v31 != 3 )
                      {
                        if ( !v31
                          || (v32 = *(__int16 *)((char *)word_721390 + v29),
                              v33 = word_721392[v53] - v32,
                              v34 = v59 - v32,
                              LODWORD(v35) = v34 << 16,
                              HIDWORD(v35) = v34 >> 16,
                              v5 = dword_6BE63C,
                              (signed int)(((unsigned __int64)(((signed int)*(__int16 *)((char *)word_721462 + v29)
                                                              - (signed int)*(__int16 *)((char *)word_721460 + v29))
                                                             * (signed int)(v35 / v33)) >> 16)
                                         + *(__int16 *)((char *)word_721460 + v29)) >= v58) )
                          ++v56;
                      }
                    }
                    ++v53;
                    v51 = v49;
                  }
                  while ( v53 < v28 );
                  if ( v56 == 1 )
                  {
                    if ( v57 >= 50 )
                      break;
                    v36 = 4 * v57++;
                    *(int *)((char *)dword_7212C8 + v36) = -29000;
                    *(int *)((char *)dword_721200 + v36) = *(_WORD *)(*(_DWORD *)(v7 + 40) + 2 * i);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  v37 = 1;
  if ( v57 == 1 )
  {
    *(_DWORD *)a5 = dword_721200[0];
    return dword_7212C8[0];
  }
  if ( !v57 )
    return -30000;
  *(_DWORD *)a5 = dword_721200[0];
  result = dword_7212C8[0];
  if ( v57 > 1 )
  {
    v39 = a3 + 5;
    while ( 1 )
    {
      v40 = dword_7212C8[v37];
      if ( result <= v39 )
        break;
      if ( v40 < result )
        goto LABEL_67;
LABEL_68:
      ++v37;
      if ( v37 >= v57 )
        return result;
    }
    if ( v40 <= result || v40 > v39 )
      goto LABEL_68;
LABEL_67:
    result = dword_7212C8[v37];
    *(_DWORD *)a5 = dword_721200[v37];
    goto LABEL_68;
  }
  return result;
}

//----- (0046D8E3) --------------------------------------------------------
int __fastcall sub_46D8E3(signed int a1, signed int a2, int a3, int a4)
{
  int v4; // ecx@1
  signed int v5; // ebx@1
  int v6; // edi@3
  char v7; // al@10
  int v8; // esi@10
  int v9; // eax@18
  int v10; // edx@19
  int v11; // ecx@21
  int v12; // ecx@23
  signed int v13; // eax@25
  int v14; // edx@27
  int v15; // edx@29
  int v16; // ST18_4@29
  signed int v17; // edx@29
  signed __int64 v18; // qtt@29
  unsigned __int8 v19; // sf@31
  unsigned __int8 v20; // of@31
  int v21; // eax@35
  int v22; // ecx@37
  signed int v24; // ebx@42
  int v25; // esi@43
  int v26; // eax@44
  int v27; // edx@44
  int v28; // [sp+Ch] [bp-38h]@7
  int v29; // [sp+10h] [bp-34h]@21
  int v30; // [sp+18h] [bp-2Ch]@21
  int v31; // [sp+1Ch] [bp-28h]@2
  int v32; // [sp+20h] [bp-24h]@8
  signed int v33; // [sp+24h] [bp-20h]@1
  int v34; // [sp+28h] [bp-1Ch]@1
  int v35; // [sp+2Ch] [bp-18h]@7
  bool v36; // [sp+30h] [bp-14h]@21
  bool v37; // [sp+34h] [bp-10h]@23
  signed int v38; // [sp+38h] [bp-Ch]@17
  signed int v39; // [sp+38h] [bp-Ch]@21
  signed int v40; // [sp+38h] [bp-Ch]@42
  signed int v41; // [sp+3Ch] [bp-8h]@1
  signed int v42; // [sp+40h] [bp-4h]@1

  dword_720ED0[0] = -1;
  dword_720E80[0] = -1;
  v5 = a1;
  v4 = 0;
  v42 = a2;
  v33 = v5;
  v41 = 1;
  dword_720F20[0] = 10000;
  v34 = 0;
  if ( pClass51_global->uNumBModels > 0 )
  {
    v31 = 0;
    do
    {
      v6 = v31 + pClass51_global->pBModels;
      if ( v5 <= *(_DWORD *)(v31 + pClass51_global->pBModels + 136) )
      {
        if ( v5 >= *(_DWORD *)(v6 + 124) )
        {
          if ( v42 <= *(_DWORD *)(v6 + 140) )
          {
            if ( v42 >= *(_DWORD *)(v6 + 128) )
            {
              v35 = v4;
              v28 = *(_DWORD *)(v6 + 76);
              if ( *(_DWORD *)(v6 + 76) > v4 )
              {
                v32 = v4;
                while ( 1 )
                {
                  v8 = v32 + *(_DWORD *)(v6 + 84);
                  v7 = *(_BYTE *)(v8 + 303);
                  if ( v7 == 5 || v7 == 6 )
                  {
                    if ( !(*(_BYTE *)(v8 + 31) & 0x20) )
                    {
                      if ( v5 <= *(_WORD *)(v8 + 280) )
                      {
                        if ( v5 >= *(_WORD *)(v8 + 278) )
                        {
                          if ( v42 <= *(_WORD *)(v8 + 284) )
                          {
                            if ( v42 >= *(_WORD *)(v8 + 282) )
                            {
                              v38 = v4;
                              if ( *(_BYTE *)(v8 + 302) )
                              {
                                v9 = v8 + 152;
                                do
                                {
                                  v10 = 4 * v38;
                                  word_720DB0[2 * v38] = *(_WORD *)v9
                                                       + *(_WORD *)(*(_DWORD *)(v6 + 72) + 12 * *(_WORD *)(v9 - 120));
                                  word_720CE0[2 * v38] = *(_WORD *)(v9 + 40)
                                                       + *(_WORD *)(*(_DWORD *)(v6 + 72) + 12 * *(_WORD *)(v9 - 120) + 4);
                                  word_720DB2[2 * v38++] = *(_WORD *)v9
                                                         + *(_WORD *)(*(_DWORD *)(v6 + 72) + 12 * *(_WORD *)(v9 - 118));
                                  *(__int16 *)((char *)&word_720CE2 + v10) = *(_WORD *)(v9 + 40)
                                                                           + *(_WORD *)(*(_DWORD *)(v6 + 72)
                                                                                      + 12 * *(_WORD *)(v9 - 118)
                                                                                      + 4);
                                  v9 += 2;
                                }
                                while ( v38 < *(_BYTE *)(v8 + 302) );
                                v5 = v33;
                              }
                              v29 = 2 * *(_BYTE *)(v8 + 302);
                              word_720DB0[2 * *(_BYTE *)(v8 + 302)] = word_720DB0[0];
                              word_720CE0[v29] = word_720CE0[0];
                              v11 = 0;
                              v36 = word_720CE0[0] >= v42;
                              v39 = 0;
                              v30 = 0;
                              if ( v29 > 0 )
                              {
                                do
                                {
                                  if ( v39 >= 2 )
                                    break;
                                  v12 = 2 * v11;
                                  v5 = v33;
                                  v37 = *(__int16 *)((char *)&word_720CE2 + v12) >= v42;
                                  if ( v36 != v37 )
                                  {
                                    if ( *(__int16 *)((char *)word_720DB2 + v12) >= v33 )
                                      v13 = 0;
                                    else
                                      v13 = 2;
                                    v14 = v13 | *(__int16 *)((char *)word_720DB0 + v12) < v33;
                                    if ( v14 != 3 )
                                    {
                                      if ( !v14
                                        || (v15 = *(__int16 *)((char *)word_720CE0 + v12),
                                            v16 = *(__int16 *)((char *)&word_720CE2 + v12) - v15,
                                            v17 = v42 - v15,
                                            LODWORD(v18) = v17 << 16,
                                            HIDWORD(v18) = v17 >> 16,
                                            (signed int)(((unsigned __int64)(((signed int)*(__int16 *)((char *)word_720DB2 + v12)
                                                                            - (signed int)*(__int16 *)((char *)word_720DB0 + v12))
                                                                           * (signed int)(v18 / v16)) >> 16)
                                                       + *(__int16 *)((char *)word_720DB0 + v12)) >= v33) )
                                        ++v39;
                                    }
                                  }
                                  v11 = v30 + 1;
                                  v36 = v37;
                                  compile_error;//v20 = __SETO__(v30 + 1, v29);
                                  v19 = v30++ + 1 - v29 < 0;
                                }
                                while ( v19 ^ v20 );
                                if ( v39 == 1 )
                                {
                                  if ( v41 >= 20 )
                                    break;
                                  if ( *(_BYTE *)(v8 + 303) == 5 )
                                    v21 = *(_DWORD *)(*(_DWORD *)(v6 + 72) + 12 * *(_WORD *)(v8 + 32) + 8);
                                  else
                                    v21 = ((unsigned __int64)(*(_DWORD *)(v8 + 16) * v5) >> 16)
                                        + ((unsigned __int64)(*(_DWORD *)(v8 + 20) * v42) >> 16)
                                        + *(_WORD *)(v8 + 26);
                                  v22 = 4 * v41++;
                                  *(int *)((char *)dword_720F20 + v22) = v21;
                                  *(int *)((char *)dword_720ED0 + v22) = v34;
                                  *(int *)((char *)dword_720E80 + v22) = v35;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  ++v35;
                  v32 += 308;
                  if ( v35 >= v28 )
                    break;
                  v4 = 0;
                }
              }
            }
          }
        }
      }
      ++v34;
      v31 += 188;
      v4 = 0;
    }
    while ( v34 < pClass51_global->uNumBModels );
    if ( !v41 )
    {
      *(_DWORD *)a4 = 0;
      return dword_720F20[0];
    }
  }
  v24 = 0;
  v40 = v4;
  if ( v41 <= v4 )
    goto LABEL_54;
  v25 = 0;
  do
  {
    v27 = *(int *)((char *)dword_720F20 + v4);
    v26 = *(int *)((char *)dword_720F20 + v25);
    if ( v27 == v26 )
      goto LABEL_50;
    if ( v26 > a3 + 15 )
    {
      if ( v27 >= v26 )
        goto LABEL_51;
LABEL_50:
      v24 = v40;
      v25 = v4;
      goto LABEL_51;
    }
    if ( v27 > v26 && v27 <= a3 + 15 )
      goto LABEL_50;
LABEL_51:
    ++v40;
    v4 += 4;
  }
  while ( v40 < v41 );
  if ( v24 )
  {
    *(_DWORD *)a4 = dword_720E80[v24] | (dword_720ED0[v24] << 6);
    return dword_720F20[v24];
  }
LABEL_54:
  *(_DWORD *)a4 = 0;
  return dword_720F20[v24];
}

//----- (0046DCC8) --------------------------------------------------------
signed __int64 __fastcall sub_46DCC8(signed int a1, signed int a2, int a3)
{
  int v3; // edi@1
  int v4; // esi@1
  signed int v5; // ebx@1
  signed int v6; // ST4C_4@1
  int v7; // ST54_4@1
  int v8; // edi@1
  signed int v9; // ST50_4@1
  int v10; // ebx@1
  int v11; // eax@2
  int v12; // edx@2
  int v13; // ecx@2
  int v14; // ebx@2
  double v15; // st5@4
  double v16; // st7@4
  double v17; // st7@4
  double v18; // st6@4
  double v19; // st5@4
  float v20; // ST44_4@4
  float v21; // ST54_4@4
  double v22; // st4@4
  float v23; // ST44_4@6
  signed __int64 result; // qax@6
  double v25; // st7@6
  int v26; // [sp+14h] [bp-44h]@1
  int v27; // [sp+18h] [bp-40h]@1
  int v28; // [sp+20h] [bp-38h]@1
  int v29; // [sp+24h] [bp-34h]@1
  int v30; // [sp+28h] [bp-30h]@1
  int v31; // [sp+2Ch] [bp-2Ch]@1
  int v32; // [sp+30h] [bp-28h]@1
  int v33; // [sp+34h] [bp-24h]@1
  int v34; // [sp+38h] [bp-20h]@1
  int v35; // [sp+3Ch] [bp-1Ch]@1
  int v36; // [sp+40h] [bp-18h]@1
  int v37; // [sp+4Ch] [bp-Ch]@2
  float v38; // [sp+4Ch] [bp-Ch]@4
  int v39; // [sp+50h] [bp-8h]@2
  float v40; // [sp+50h] [bp-8h]@4
  int v41; // [sp+54h] [bp-4h]@2

  v5 = a1;
  v6 = a2;
  v7 = WorldPosToGridCellX(a1);
  v8 = WorldPosToGridCellZ(v6) - 1;
  v33 = sub_47F469(v7);
  v34 = sub_47F469(v7 + 1);
  v35 = sub_47F469(v7 + 1);
  v36 = sub_47F469(v7);
  v29 = sub_47F476(v8);
  v30 = sub_47F476(v8);
  v9 = v8 + 1;
  v31 = sub_47F476(v8 + 1);
  v32 = sub_47F476(v8 + 1);
  v26 = class51_sub_47EE16_ActuallyGetHeightOnTerrain(pClass51_global, v7, v8);
  v27 = class51_sub_47EE16_ActuallyGetHeightOnTerrain(pClass51_global, v7 + 1, v8);
  v3 = class51_sub_47EE16_ActuallyGetHeightOnTerrain(pClass51_global, v7 + 1, v8 + 1);
  v28 = class51_sub_47EE16_ActuallyGetHeightOnTerrain(pClass51_global, v7, v9);
  v4 = v29;
  v10 = abs(v5 - v33);
  if ( abs(v29 - v6) >= v10 )
  {
    v13 = v33;
    v37 = v28;
    v39 = v36;
    v11 = v35;
    v41 = v32;
    v12 = v31;
    v14 = v3;
    v3 = v26;
  }
  else
  {
    v13 = v35;
    v41 = v30;
    v39 = v34;
    v11 = v33;
    v12 = v29;
    v4 = v31;
    v37 = v27;
    v14 = v26;
  }
  v17 = (double)(v11 - v39);
  v18 = (double)(v12 - v41);
  v19 = (double)(v14 - v37);
  v20 = (double)(v13 - v39);
  v21 = (double)(v4 - v41);
  v22 = (double)(v3 - v37);
  v38 = v22 * v18 - v21 * v19;
  v40 = v20 * v19 - v22 * v17;
  v15 = v21 * v17 - v20 * v18;
  v16 = sqrt(v15 * v15 + v40 * v40 + v38 * v38);
  if ( v16 == 0.0 )
  {
    *(_DWORD *)(a3 + 4) = 0;
    *(_DWORD *)a3 = 0;
    *(_DWORD *)(a3 + 8) = 65536;
  }
  v25 = 1.0 / v16;
  *(_DWORD *)a3 = (signed __int64)(v25 * v38 * 65536.0);
  *(_DWORD *)(a3 + 4) = (signed __int64)(v25 * v40 * 65536.0);
  v23 = v15;
  result = (signed __int64)(v25 * v23 * 65536.0);
  *(_DWORD *)(a3 + 8) = result;
  return result;
}

//----- (0046DEF2) --------------------------------------------------------
signed int __fastcall sub_46DEF2(int a1, signed int a2)
{
  signed int result; // eax@1

  result = a2;
  if ( *(_BYTE *)(56 * array_665230[a2].uObjectDescriptionID + pObjectDescriptionList->pDescriptions + 38) & 0x10 )
    result = sub_46BFFA(a2, a1);
  return result;
}

//----- (0046DF1A) --------------------------------------------------------
signed int __fastcall sub_46DF1A(int a1, int a2)
{
  __int16 v2; // ax@1
  char *v3; // edi@1
  int v4; // esi@6
  int v5; // ecx@8
  int v6; // eax@10
  int v7; // edx@12
  int v8; // esi@14
  int v9; // ecx@14
  int v10; // eax@14
  int v11; // ebx@14
  int v12; // ebx@15
  int v13; // ebx@17
  int v14; // eax@20
  signed int result; // eax@21
  int v16; // [sp+Ch] [bp-10h]@1
  int v17; // [sp+10h] [bp-Ch]@14
  int v18; // [sp+14h] [bp-8h]@14
  int v19; // [sp+18h] [bp-4h]@14

  v16 = a1;
  v3 = (char *)pActors + 836 * a1;
  v2 = *((_WORD *)v3 + 88);
  if ( v2 == 11 )
    goto LABEL_25;
  if ( v2 == 4 )
    goto LABEL_25;
  if ( v2 == 19 )
    goto LABEL_25;
  if ( v2 == 5 )
    goto LABEL_25;
  if ( v2 == 17 )
    goto LABEL_25;
  v4 = *((_WORD *)v3 + 68);
  if ( a2 )
    v4 = a2;
  v5 = *((_WORD *)v3 + 71);
  if ( dword_7215BC > v5 + v4
    || dword_7215C0 < v5 - v4
    || (v6 = *((_WORD *)v3 + 72), dword_7215C4 > v6 + v4)
    || dword_7215C8 < v6 - v4
    || (v7 = *((_WORD *)v3 + 73), dword_7215CC > v7 + *((_WORD *)v3 + 69))
    || dword_7215D0 < v7
    || (v9 = v5 - dword_721558,
        v10 = v6 - dword_72155C,
        v11 = dword_721534 + v4,
        v17 = dword_721534 + v4,
        v8 = (v9 * dword_72158C - v10 * dword_721588) >> 16,
        v18 = v9,
        v19 = v10,
        abs((v9 * dword_72158C - v10 * dword_721588) >> 16) > v11)
    || (v12 = (v18 * dword_721588 + v19 * dword_72158C) >> 16, v12 <= 0)
    || (signed int)(((unsigned __int64)(dword_721590 * v12) >> 16) + dword_721560) < *((_WORD *)v3 + 73) )
  {
LABEL_25:
    result = 0;
  }
  else
  {
    v13 = v12 - sub_452A9E(v17 * v17 - v8 * v8);
    if ( v13 < 0 )
      v13 = 0;
    if ( v13 < dword_7215AC )
    {
      dword_7215AC = v13;
      v14 = 8 * v16;
      LOBYTE(v14) = 8 * v16 | 3;
      dword_7215A8 = v14;
    }
    result = 1;
  }
  return result;
}

//----- (0046E0B2) --------------------------------------------------------
void __cdecl sub_46E0B2()
{
  int v0; // ebp@1
  __int16 *v1; // edi@2
  int v2; // esi@3
  int v3; // eax@4
  int v4; // edx@4
  int v5; // ecx@6
  int v6; // ebx@8
  int v7; // esi@8
  int v8; // ebx@10
  int v9; // esi@11
  int v10; // eax@12
  int v11; // edi@12
  int v12; // esi@14
  int v13; // eax@17
  signed int i; // [sp+4h] [bp-14h]@1
  int v15; // [sp+8h] [bp-10h]@10
  int v16; // [sp+Ch] [bp-Ch]@10
  int v17; // [sp+10h] [bp-8h]@10
  int v18; // [sp+14h] [bp-4h]@8

  v0 = dword_6BE654 + 116 * dword_7215A4;
  for ( i = 0; i < *(_WORD *)(v0 + 68); ++i )
  {
    v1 = &array_6836D0[*(_WORD *)(*(_DWORD *)(v0 + 72) + 2 * i)];
    if ( !(*((_BYTE *)v1 + 2) & 0x20) )
    {
      v2 = 84 * *v1 + pDecorationDescriptionList->pDescriptions;
      if ( !(*(_BYTE *)(v2 + 74) & 1) )
      {
        v4 = *(_WORD *)(v2 + 68);
        v3 = *((_DWORD *)v1 + 1);
        if ( dword_7215BC <= v3 + v4 )
        {
          if ( dword_7215C0 >= v3 - v4 )
          {
            v5 = *((_DWORD *)v1 + 2);
            if ( dword_7215C4 <= v5 + v4 )
            {
              if ( dword_7215C8 >= v5 - v4 )
              {
                v6 = *(_WORD *)(v2 + 66);
                v7 = *((_DWORD *)v1 + 3);
                v18 = v6;
                if ( dword_7215CC <= v7 + v6 )
                {
                  if ( dword_7215D0 >= v7 )
                  {
                    v16 = v3 - dword_721558;
                    v15 = v5 - dword_72155C;
                    v8 = dword_721534 + v4;
                    v17 = ((v3 - dword_721558) * dword_72158C - (v5 - dword_72155C) * dword_721588) >> 16;
                    if ( abs(v17) <= dword_721534 + v4 )
                    {
                      v9 = (v16 * dword_721588 + v15 * dword_72158C) >> 16;
                      if ( v9 > 0 )
                      {
                        v11 = *((_DWORD *)v1 + 3);
                        v10 = dword_721560 + ((unsigned __int64)(dword_721590 * v9) >> 16);
                        if ( v10 >= v11 )
                        {
                          if ( v10 <= v18 + v11 )
                          {
                            v12 = v9 - sub_452A9E(v8 * v8 - v17 * v17);
                            if ( v12 < 0 )
                              v12 = 0;
                            if ( v12 < dword_7215AC )
                            {
                              dword_7215AC = v12;
                              v13 = 8 * *(_WORD *)(*(_DWORD *)(v0 + 72) + 2 * i);
                              LOBYTE(v13) = v13 | 5;
                              dword_7215A8 = v13;
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
        }
      }
    }
  }
}

//----- (0046E26D) --------------------------------------------------------
void __fastcall sub_46E26D(signed int a1, signed int a2)
{
  int v2; // eax@5
  int v3; // edx@5
  __int16 v4; // ax@6
  __int16 *v5; // edi@7
  int v6; // esi@8
  int v7; // eax@9
  int v8; // edx@9
  int v9; // ecx@11
  int v10; // ebx@13
  int v11; // esi@13
  int v12; // ebx@15
  int v13; // ebp@15
  int v14; // esi@16
  int v15; // eax@17
  int v16; // edi@17
  int v17; // esi@19
  char v18; // zf@23
  int v19; // [sp+0h] [bp-10h]@15
  int v20; // [sp+4h] [bp-Ch]@5
  int v21; // [sp+8h] [bp-8h]@15
  int v22; // [sp+Ch] [bp-4h]@13

  if ( a1 >= 0 )
  {
    if ( a1 <= 127 )
    {
      if ( a2 >= 0 )
      {
        if ( a2 <= 127 )
        {
          v3 = a1 + (a2 << 7);
          v2 = dword_6A0ED0 + 2 * *(_DWORD *)(dword_6A0ED4 + 4 * v3);
          v20 = dword_6A0ED0 + 2 * *(_DWORD *)(dword_6A0ED4 + 4 * v3);
          if ( v2 )
          {
            do
            {
              v4 = *(_WORD *)v2;
              if ( (v4 & 7) == 5 )
              {
                v5 = &array_6836D0[(v4 >> 3)];
                if ( !(*((_BYTE *)v5 + 2) & 0x20) )
                {
                  v6 = 84 * *v5 + pDecorationDescriptionList->pDescriptions;
                  if ( !(*(_BYTE *)(v6 + 74) & 1) )
                  {
                    v8 = *(_WORD *)(v6 + 68);
                    v7 = *((_DWORD *)v5 + 1);
                    if ( dword_7215BC <= v7 + v8 )
                    {
                      if ( dword_7215C0 >= v7 - v8 )
                      {
                        v9 = *((_DWORD *)v5 + 2);
                        if ( dword_7215C4 <= v9 + v8 )
                        {
                          if ( dword_7215C8 >= v9 - v8 )
                          {
                            v10 = *(_WORD *)(v6 + 66);
                            v11 = *((_DWORD *)v5 + 3);
                            v22 = v10;
                            if ( dword_7215CC <= v11 + v10 )
                            {
                              if ( dword_7215D0 >= v11 )
                              {
                                v13 = v7 - dword_721558;
                                v19 = v9 - dword_72155C;
                                v12 = dword_721534 + v8;
                                v21 = ((v7 - dword_721558) * dword_72158C - (v9 - dword_72155C) * dword_721588) >> 16;
                                if ( abs(v21) <= dword_721534 + v8 )
                                {
                                  v14 = (v13 * dword_721588 + v19 * dword_72158C) >> 16;
                                  if ( v14 > 0 )
                                  {
                                    v16 = *((_DWORD *)v5 + 3);
                                    v15 = dword_721560 + ((unsigned __int64)(dword_721590 * v14) >> 16);
                                    if ( v15 >= v16 )
                                    {
                                      if ( v15 <= v22 + v16 )
                                      {
                                        v17 = v14 - sub_452A9E(v12 * v12 - v21 * v21);
                                        if ( v17 < 0 )
                                          v17 = 0;
                                        if ( v17 < dword_7215AC )
                                        {
                                          dword_7215AC = v17;
                                          dword_7215A8 = *(_WORD *)v20;
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
                    }
                  }
                }
              }
              v2 = v20 + 2;
              v18 = *(_WORD *)v20 == 0;
              v20 += 2;
            }
            while ( !v18 );
          }
        }
      }
    }
  }
}

//----- (0046E44E) --------------------------------------------------------
int __thiscall sub_46E44E(void *this)
{
  signed int v1; // ebx@1
  int v2; // edi@1
  int v3; // esi@2
  __int16 v4; // si@10
  int v5; // ecx@12
  unsigned __int8 v6; // sf@12
  unsigned __int8 v7; // of@12
  int result; // eax@14
  int v9; // ecx@15
  int v10; // ebx@15
  int v11; // eax@16
  int v12; // ebp@16
  int v13; // eax@24
  int v14; // eax@24
  int v15; // esi@24
  int v16; // edx@25
  int v17; // eax@29
  int v18; // eax@33
  int v19; // eax@35
  int v20; // eax@35
  int v21; // edx@35
  int v22; // ecx@36
  int v23; // eax@40
  int v24; // eax@44
  unsigned __int8 v25; // sf@45
  unsigned __int8 v26; // of@45
  unsigned __int8 v27; // sf@46
  unsigned __int8 v28; // of@46
  int v29; // [sp+10h] [bp-48h]@28
  int v30; // [sp+14h] [bp-44h]@15
  int i; // [sp+18h] [bp-40h]@1
  int v32; // [sp+1Ch] [bp-3Ch]@1
  int v33; // [sp+20h] [bp-38h]@14
  int v34; // [sp+24h] [bp-34h]@35
  int v35; // [sp+28h] [bp-30h]@24
  int v36; // [sp+2Ch] [bp-2Ch]@15
  int v37[10]; // [sp+30h] [bp-28h]@1

  v2 = dword_6BE654 + 116 * dword_7215A4;
  v1 = 0;
  v32 = (int)this;
  v37[0] = dword_7215A4;
  for ( i = 1; v1 < *(_WORD *)(v2 + 36); ++v1 )
  {
    v3 = dword_6BE644 + 96 * *(_WORD *)(*(_DWORD *)(v2 + 40) + 2 * v1);
    if ( dword_7215BC <= *(_WORD *)(v3 + 82) )
    {
      if ( dword_7215C0 >= *(_WORD *)(v3 + 80) )
      {
        if ( dword_7215C4 <= *(_WORD *)(v3 + 86) )
        {
          if ( dword_7215C8 >= *(_WORD *)(v3 + 84) )
          {
            if ( dword_7215CC <= *(_WORD *)(v3 + 90) )
            {
              if ( dword_7215D0 >= *(_WORD *)(v3 + 88) )
              {
                if ( abs((*(_DWORD *)(v3 + 28)
                        + dword_721558 * *(_DWORD *)(v3 + 16)
                        + dword_72155C * *(_DWORD *)(v3 + 20)
                        + dword_721560 * *(_DWORD *)(v3 + 24)) >> 16) <= dword_72159C + 16 )
                {
                  v4 = *(_WORD *)(v3 + 76) == dword_7215A4 ? *(_WORD *)(v3 + 78) : *(_WORD *)(v3 + 76);
                  v5 = i++;
                  compile_error;//v7 = __SETO__(i, 10);
                  v6 = i - 10 < 0;
                  v37[v5] = v4;
                  if ( !(v6 ^ v7) )
                    break;
                }
              }
            }
          }
        }
      }
    }
  }
  result = 0;
  v33 = 0;
  if ( i > 0 )
  {
    while ( 1 )
    {
      v10 = dword_6BE654 + 116 * v37[result];
      v9 = 0;
      v36 = *(_WORD *)(v10 + 4) + *(_WORD *)(v10 + 12) + *(_WORD *)(v10 + 20);
      v30 = 0;
      if ( v36 > 0 )
        break;
LABEL_46:
      result = v33 + 1;
      compile_error;//v28 = __SETO__(v33 + 1, i);
      v27 = v33++ + 1 - i < 0;
      if ( !(v27 ^ v28) )
        return result;
    }
    while ( 1 )
    {
      v11 = *(_WORD *)(*(_DWORD *)(v10 + 8) + 2 * v9);
      v12 = dword_6BE644 + 96 * v11;
      if ( *(_BYTE *)(v12 + 44) & 1
        || dword_7215BC > *(_WORD *)(v12 + 82)
        || dword_7215C0 < *(_WORD *)(v12 + 80)
        || dword_7215C4 > *(_WORD *)(v12 + 86)
        || dword_7215C8 < *(_WORD *)(v12 + 84)
        || dword_7215CC > *(_WORD *)(v12 + 90)
        || dword_7215D0 < *(_WORD *)(v12 + 88)
        || v11 == dword_7215B4 )
        goto LABEL_45;
      v14 = *(_DWORD *)(v12 + 20);
      v15 = *(_DWORD *)(v12 + 28);
      v35 = v14;
      v13 = (dword_721558 * *(_DWORD *)(v12 + 16) + v15 + dword_72155C * v14 + dword_721560 * *(_DWORD *)(v12 + 24)) >> 16;
      if ( v13 > 0 )
      {
        v16 = (dword_721574 * v35
             + *(_DWORD *)(v12 + 28)
             + dword_721578 * *(_DWORD *)(v12 + 24)
             + dword_721570 * *(_DWORD *)(v12 + 16)) >> 16;
        if ( v13 <= dword_721534 || v16 <= dword_721534 )
        {
          if ( v16 <= v13 )
          {
            v29 = dword_72159C;
            if ( sub_47531C(
                   dword_721534,
                   (int)&v29,
                   dword_721558,
                   *(&dword_721558 + 1),
                   *(&dword_721558 + 2),
                   dword_721588,
                   *(&dword_721588 + 1),
                   *(&dword_721588 + 2),
                   v12,
                   v32) )
            {
              v17 = v29;
            }
            else
            {
              v29 = dword_72159C + dword_721534;
              if ( !sub_475D85((int)&dword_721558, (int)&dword_721588, (int)&v29, v12) )
                goto LABEL_34;
              v17 = v29 - dword_721534;
              v29 -= dword_721534;
            }
            if ( v17 < dword_7215AC )
            {
              dword_7215AC = v17;
              v18 = 8 * *(_WORD *)(*(_DWORD *)(v10 + 8) + 2 * v30);
              LOBYTE(v18) = v18 | 6;
              dword_7215A8 = v18;
            }
          }
        }
      }
LABEL_34:
      if ( !(dword_721530 & 1)
        || (v20 = *(_DWORD *)(v12 + 16),
            v21 = *(_DWORD *)(v12 + 20),
            v34 = v20,
            v19 = (dword_721564 * v20 + *(_DWORD *)(v12 + 28) + dword_721568 * v21 + dword_72156C
                                                                                   * *(_DWORD *)(v12 + 24)) >> 16,
            v19 <= 0)
        || (v22 = (dword_72157C * v34 + *(_DWORD *)(v12 + 28) + dword_721580 * v21 + dword_721584
                                                                                   * *(_DWORD *)(v12 + 24)) >> 16,
            v19 > dword_721534)
        && v22 > dword_721534
        || v22 > v19 )
        goto LABEL_45;
      v29 = dword_72159C;
      if ( sub_47531C(
             dword_721538,
             (int)&v29,
             dword_721564,
             *(&dword_721564 + 1),
             *(&dword_721564 + 2),
             dword_721588,
             *(&dword_721588 + 1),
             *(&dword_721588 + 2),
             v12,
             v32) )
      {
        v23 = v29;
        goto LABEL_43;
      }
      v29 = dword_72159C + dword_721538;
      if ( sub_475D85((int)&dword_721564, (int)&dword_721588, (int)&v29, v12) )
      {
        v23 = v29 - dword_721534;
        v29 -= dword_721534;
LABEL_43:
        if ( v23 < dword_7215AC )
        {
          dword_7215AC = v23;
          v24 = 8 * *(_WORD *)(*(_DWORD *)(v10 + 8) + 2 * v30);
          LOBYTE(v24) = v24 | 6;
          dword_7215A8 = v24;
        }
      }
LABEL_45:
      v9 = v30 + 1;
      compile_error;//v26 = __SETO__(v30 + 1, v36);
      v25 = v30++ + 1 - v36 < 0;
      if ( !(v25 ^ v26) )
        goto LABEL_46;
    }
  }
  return result;
}

//----- (0046E889) --------------------------------------------------------
int __thiscall sub_46E889(void *this)
{
  int result; // eax@1
  int v2; // ecx@3
  int v3; // ebx@9
  int v4; // eax@11
  int v5; // ecx@17
  int v6; // edi@17
  int v7; // esi@17
  int v8; // eax@19
  int v9; // ecx@20
  int v10; // eax@24
  int v11; // ST18_4@25
  int v12; // ST1C_4@25
  int v13; // ST0C_4@25
  int v14; // eax@28
  int v15; // eax@30
  int v16; // ecx@31
  int v17; // eax@36
  int v18; // ST18_4@41
  int v19; // ST1C_4@41
  int v20; // ST0C_4@41
  int v21; // eax@42
  unsigned __int8 v22; // sf@42
  unsigned __int8 v23; // of@42
  int v24; // eax@43
  char v25; // [sp+Ch] [bp-7Ch]@1
  int v26; // [sp+1Ch] [bp-6Ch]@17
  int v27; // [sp+20h] [bp-68h]@17
  int v28; // [sp+24h] [bp-64h]@17
  int v29; // [sp+28h] [bp-60h]@17
  int v30; // [sp+2Ch] [bp-5Ch]@17
  int v31; // [sp+30h] [bp-58h]@17
  int v32; // [sp+34h] [bp-54h]@17
  int v33; // [sp+38h] [bp-50h]@17
  int v34; // [sp+3Ch] [bp-4Ch]@17
  int v35; // [sp+40h] [bp-48h]@17
  int v36; // [sp+44h] [bp-44h]@17
  int v37; // [sp+48h] [bp-40h]@17
  __int16 v38; // [sp+56h] [bp-32h]@17
  __int16 v39; // [sp+5Ch] [bp-2Ch]@17
  __int16 v40; // [sp+5Eh] [bp-2Ah]@17
  __int16 v41; // [sp+60h] [bp-28h]@17
  __int16 v42; // [sp+62h] [bp-26h]@17
  __int16 v43; // [sp+64h] [bp-24h]@17
  __int16 v44; // [sp+66h] [bp-22h]@17
  char v45; // [sp+68h] [bp-20h]@17
  char v46; // [sp+69h] [bp-1Fh]@17
  int v47; // [sp+6Ch] [bp-1Ch]@9
  int v48; // [sp+70h] [bp-18h]@1
  int v49; // [sp+74h] [bp-14h]@2
  int v50; // [sp+78h] [bp-10h]@10
  int v51; // [sp+7Ch] [bp-Ch]@3
  int v52; // [sp+80h] [bp-8h]@1
  int v53; // [sp+84h] [bp-4h]@23

  v48 = (int)this;
  sub_46ED02((int)&v25);
  result = 0;
  v52 = 0;
  if ( pClass51_global->uNumBModels > 0 )
  {
    v49 = 0;
    while ( 1 )
    {
      v2 = pClass51_global->pBModels + v49;
      v51 = pClass51_global->pBModels + v49;
      if ( dword_7215BC <= *(_DWORD *)(pClass51_global->pBModels + v49 + 136) )
      {
        if ( dword_7215C0 >= *(_DWORD *)(v2 + 124) )
        {
          if ( dword_7215C4 <= *(_DWORD *)(v2 + 140) )
          {
            if ( dword_7215C8 >= *(_DWORD *)(v2 + 128) )
            {
              if ( dword_7215CC <= *(_DWORD *)(v2 + 144) )
              {
                if ( dword_7215D0 >= *(_DWORD *)(v2 + 132) )
                {
                  v3 = 0;
                  v47 = *(_DWORD *)(v2 + 76);
                  if ( v47 > 0 )
                    break;
                }
              }
            }
          }
        }
      }
LABEL_39:
      ++v52;
      v49 += 188;
      result = v52;
      if ( v52 >= pClass51_global->uNumBModels )
        return result;
    }
    v50 = 0;
    while ( 1 )
    {
      v4 = v50 + *(_DWORD *)(v2 + 84);
      if ( dword_7215BC > *(_WORD *)(v4 + 280)
        || dword_7215C0 < *(_WORD *)(v4 + 278)
        || dword_7215C4 > *(_WORD *)(v4 + 284)
        || dword_7215C8 < *(_WORD *)(v4 + 282)
        || dword_7215CC > *(_WORD *)(v4 + 288)
        || dword_7215D0 < *(_WORD *)(v4 + 286) )
        goto LABEL_38;
      v26 = *(_DWORD *)v4;
      v27 = *(_DWORD *)(v4 + 4);
      v6 = *(_DWORD *)(v4 + 8);
      v28 = *(_DWORD *)(v4 + 8);
      v7 = *(_DWORD *)(v4 + 12);
      v29 = *(_DWORD *)(v4 + 12);
      v5 = *(_DWORD *)(v4 + 28);
      v33 = v5;
      v39 = *(_WORD *)(v4 + 278);
      v41 = *(_WORD *)(v4 + 282);
      v43 = *(_WORD *)(v4 + 286);
      v40 = *(_WORD *)(v4 + 280);
      v42 = *(_WORD *)(v4 + 284);
      v44 = *(_WORD *)(v4 + 288);
      v30 = *(_DWORD *)(v4 + 16);
      v31 = *(_DWORD *)(v4 + 20);
      v32 = *(_DWORD *)(v4 + 24);
      v35 = v4 + 152;
      v36 = v4 + 192;
      v37 = v4 + 232;
      v45 = *(_BYTE *)(v4 + 303);
      v46 = *(_BYTE *)(v4 + 302);
      v38 = *(_WORD *)(v4 + 272);
      v34 = v4 + 32;
      if ( v5 & 0x20000000 || v5 & 1 )
        goto LABEL_37;
      v8 = (v6 * dword_721560 + v7 + v27 * dword_72155C + v26 * dword_721558) >> 16;
      if ( v8 > 0 )
      {
        v9 = (v6 * dword_721578 + v7 + v27 * dword_721574 + v26 * dword_721570) >> 16;
        if ( v8 <= dword_721534 || v9 <= dword_721534 )
        {
          if ( v9 <= v8 )
          {
            v53 = dword_72159C;
            if ( sub_4754BF(
                   dword_721534,
                   (int)&v53,
                   dword_721558,
                   *(&dword_721558 + 1),
                   *(&dword_721558 + 2),
                   dword_721588,
                   *(&dword_721588 + 1),
                   *(&dword_721588 + 2),
                   (int)&v25,
                   v52,
                   v48) )
            {
              v10 = v53;
            }
            else
            {
              v11 = *(&dword_721588 + 1);
              v12 = *(&dword_721588 + 2);
              v13 = *(&dword_721558 + 1);
              v53 = dword_721534 + dword_72159C;
              if ( !sub_475F30(
                      (int)&v53,
                      (int)&v25,
                      dword_721558,
                      v13,
                      *(&dword_721558 + 2),
                      dword_721588,
                      v11,
                      v12,
                      v52) )
                goto LABEL_29;
              v10 = v53 - dword_721534;
              v53 -= dword_721534;
            }
            if ( v10 < dword_7215AC )
            {
              dword_7215AC = v10;
              v14 = 8 * (v3 | (v52 << 6));
              LOBYTE(v14) = v14 | 6;
              dword_7215A8 = v14;
            }
          }
        }
      }
LABEL_29:
      if ( dword_721530 & 1 )
      {
        v15 = (v28 * dword_72156C + v29 + v27 * dword_721568 + v26 * dword_721564) >> 16;
        if ( v15 > 0 )
        {
          v16 = (v28 * dword_721584 + v29 + v27 * dword_721580 + v26 * dword_72157C) >> 16;
          if ( v15 <= dword_721534 || v16 <= dword_721534 )
          {
            if ( v16 <= v15 )
            {
              v53 = dword_72159C;
              if ( sub_4754BF(
                     dword_721538,
                     (int)&v53,
                     dword_721564,
                     *(&dword_721564 + 1),
                     *(&dword_721564 + 2),
                     dword_721588,
                     *(&dword_721588 + 1),
                     *(&dword_721588 + 2),
                     (int)&v25,
                     v52,
                     v48) )
              {
                if ( v53 < dword_7215AC )
                {
                  dword_7215AC = v53;
                  v17 = 8 * (v3 | (v52 << 6));
                  LOBYTE(v17) = v17 | 6;
                  dword_7215A8 = v17;
                }
              }
              else
              {
                v18 = *(&dword_721588 + 1);
                v19 = *(&dword_721588 + 2);
                v20 = *(&dword_721564 + 1);
                v53 = dword_72159C + dword_721538;
                if ( sub_475F30(
                       (int)&v53,
                       (int)&v25,
                       dword_721564,
                       v20,
                       *(&dword_721564 + 2),
                       dword_721588,
                       v18,
                       v19,
                       v52) )
                {
                  v2 = v51;
                  v21 = v53 - dword_721534;
                  compile_error;//v23 = __SETO__(v53 - dword_721534, dword_7215AC);
                  v22 = v53 - dword_721534 - dword_7215AC < 0;
                  v53 -= dword_721534;
                  if ( v22 ^ v23 )
                  {
                    dword_7215AC = v21;
                    v24 = 8 * (v3 | (v52 << 6));
                    LOBYTE(v24) = v24 | 6;
                    dword_7215A8 = v24;
                  }
                  goto LABEL_38;
                }
              }
            }
          }
        }
      }
LABEL_37:
      v2 = v51;
LABEL_38:
      v50 += 308;
      ++v3;
      if ( v3 >= v47 )
        goto LABEL_39;
    }
  }
  return result;
}

//----- (0046ED02) --------------------------------------------------------
int __thiscall sub_46ED02(int this)
{
  int result; // eax@1

  result = 0;
  *(_BYTE *)(this + 93) = 0;
  *(_DWORD *)(this + 44) = 0;
  *(_WORD *)(this + 72) = 0;
  *(_DWORD *)(this + 48) = 0;
  *(_DWORD *)(this + 60) = 0;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 52) = 0;
  return result;
}

//----- (0046ED1B) --------------------------------------------------------
int __fastcall sub_46ED1B(signed int a1, signed int a2, int a3, int *a4, int a5)
{
  int result; // eax@1
  int *v6; // edi@1
  int v7; // eax@3
  int v8; // [sp+Ch] [bp-8h]@1
  signed int v9; // [sp+10h] [bp-4h]@1

  v6 = a4;
  v9 = a2;
  v8 = a1;
  result = sub_46CEC3(a1, a2, a3, *a4, (int)&a4);
  if ( result != -30000 && result <= a3 + 50
    || (v7 = sub_49AC17((int)byte_6BE3C8, v8, v9, a3), *v6 = v7, v7)
    && (result = sub_46CEC3(v8, v9, a3, v7, (int)&a4), result != -30000) )
    *(_DWORD *)a5 = a4;
  else
    result = -30000;
  return result;
}

//----- (0046ED8A) --------------------------------------------------------
void __thiscall sub_46ED8A(void *this)
{
  int v1; // ebx@2
  int v2; // edx@4
  int v3; // ecx@5
  int v4; // esi@5
  int v5; // eax@7
  int v6; // edx@9
  int v7; // edi@9
  int v8; // ebx@11
  int v9; // edi@11
  int v10; // ecx@12
  int v11; // esi@13
  int v12; // [sp+0h] [bp-14h]@1
  int v13; // [sp+4h] [bp-10h]@9
  int v14; // [sp+8h] [bp-Ch]@2
  signed int v15; // [sp+10h] [bp-4h]@1

  v15 = 0;
  v12 = (int)this;
  if ( (signed int)uNumElementsIn665230 > 0 )
  {
   v1 = &array_665230[0].uObjectDescriptionID;
   v14 = &array_665230[0].uObjectDescriptionID;
    do
    {
      if ( *(_WORD *)v1 )
      {
        v2 = 56 * *(_WORD *)v1 + pObjectDescriptionList->pDescriptions;
        if ( !(*(_BYTE *)(v2 + 38) & 2) )
        {
          v4 = *(_WORD *)(v2 + 34);
          v3 = *(_DWORD *)(v1 + 2);
          if ( dword_7215BC <= v3 + v4 )
          {
            if ( dword_7215C0 >= v3 - v4 )
            {
              v5 = *(_DWORD *)(v1 + 6);
              if ( dword_7215C4 <= v5 + v4 )
              {
                if ( dword_7215C8 >= v5 - v4 )
                {
                  v7 = *(_WORD *)(v2 + 36);
                  v6 = *(_DWORD *)(v1 + 10);
                  v13 = v7;
                  if ( dword_7215CC <= v6 + v7 )
                  {
                    if ( dword_7215D0 >= v6 )
                    {
                      v9 = v3 - dword_721558;
                      v8 = v5 - dword_72155C;
                      if ( abs(((v3 - dword_721558) * dword_72158C - (v5 - dword_72155C) * dword_721588) >> 16) <= v4 + dword_721534 )
                      {
                        v10 = (v9 * dword_721588 + v8 * dword_72158C) >> 16;
                        if ( v10 > 0 )
                        {
                          v11 = dword_721560 + ((unsigned __int64)(dword_721590 * v10) >> 16);
                          if ( v11 >= *(_DWORD *)(v14 + 10) - dword_721534 )
                          {
                            if ( v11 <= v13 + dword_721534 + *(_DWORD *)(v14 + 10) )
                            {
                              if ( v10 < dword_7215AC )
                                sub_46DEF2(v12, v15);
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
        }
      }
      ++v15;
      v1 = v14 + 112;
      v14 += 112;
    }
    while ( v15 < (signed int)uNumElementsIn665230 );
  }
}

//----- (0046EF01) --------------------------------------------------------
int __thiscall sub_46EF01(void *this)
{
  int result; // eax@1
  int v2; // edx@1
  int v3; // ebx@7
  int v4; // esi@7
  int v5; // edi@8
  int v6; // ecx@9
  int v7; // edi@12
  void *v8; // [sp+Ch] [bp-10h]@1
  int v9; // [sp+10h] [bp-Ch]@1
  int v10; // [sp+14h] [bp-8h]@7
  int v11; // [sp+18h] [bp-4h]@7

  v8 = this;
  v2 = 2 * pParty_global->dword_000014;
  result = pParty_global->sPartyPosX;
  v9 = pParty_global->uPartyHeight;
  if ( dword_7215BC <= pParty_global->sPartyPosX + 2 * pParty_global->dword_000014 )
  {
    if ( dword_7215C0 >= pParty_global->sPartyPosX - v2 )
    {
      if ( dword_7215C4 <= pParty_global->sPartyPosY + v2 )
      {
        if ( dword_7215C8 >= pParty_global->sPartyPosY - v2 )
        {
          if ( dword_7215CC <= pParty_global->sPartyPosZ + pParty_global->uPartyHeight )
          {
            if ( dword_7215D0 >= pParty_global->sPartyPosZ )
            {
              v3 = dword_721534 + v2;
              v11 = pParty_global->sPartyPosX - dword_721558;
              v4 = ((pParty_global->sPartyPosX - dword_721558) * dword_72158C - (pParty_global->sPartyPosY - dword_72155C) * dword_721588) >> 16;
              v10 = pParty_global->sPartyPosY - dword_72155C;
              result = abs(((pParty_global->sPartyPosX - dword_721558) * dword_72158C - (pParty_global->sPartyPosY - dword_72155C) * dword_721588) >> 16);
              if ( result <= v3 )
              {
                result = v10 * dword_72158C;
                v5 = (v10 * dword_72158C + v11 * dword_721588) >> 16;
                if ( v5 > 0 )
                {
                  v6 = ((unsigned __int64)(dword_721590 * v5) >> 16) + dword_721560;
                  result = pParty_global->sPartyPosZ;
                  if ( v6 >= pParty_global->sPartyPosZ )
                  {
                    result = v9 + pParty_global->sPartyPosZ;
                    if ( v6 <= v9 + pParty_global->sPartyPosZ || v8 )
                    {
                      result = sub_452A9E(v3 * v3 - v4 * v4);
                      v7 = v5 - result;
                      if ( v7 < 0 )
                        v7 = 0;
                      if ( v7 < dword_7215AC )
                      {
                        dword_7215AC = v7;
                        dword_7215A8 = 4;
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
  }
  return result;
}

//----- (0046F04E) --------------------------------------------------------
signed int __cdecl sub_46F04E()
{
  signed int v0; // eax@1
  int v1; // ecx@1
  int v2; // eax@2
  int v3; // eax@3
  int v4; // edx@9
  int v5; // ecx@9
  signed int result; // eax@21
  int v7; // eax@22
  signed int v8; // [sp+0h] [bp-14h]@1
  int v9; // [sp+4h] [bp-10h]@1
  signed int v10; // [sp+8h] [bp-Ch]@1
  int v11; // [sp+Ch] [bp-8h]@13
  int v12; // [sp+10h] [bp-4h]@15

  v8 = 0;
  v1 = dword_6BE654 + 116 * dword_7215A4;
  v0 = 16777215;
  v10 = 16777215;
  v9 = v1;
  if ( *(_WORD *)(v1 + 36) > 0 )
  {
    do
    {
      v2 = *(_WORD *)(*(_DWORD *)(v1 + 40) + 2 * v8);
      if ( v2 != dword_7215B0 )
      {
        v3 = dword_6BE644 + 96 * v2;
        if ( dword_7215BC <= *(_WORD *)(v3 + 82) )
        {
          if ( dword_7215C0 >= *(_WORD *)(v3 + 80) )
          {
            if ( dword_7215C4 <= *(_WORD *)(v3 + 86) )
            {
              if ( dword_7215C8 >= *(_WORD *)(v3 + 84) )
              {
                if ( dword_7215CC <= *(_WORD *)(v3 + 90) )
                {
                  if ( dword_7215D0 >= *(_WORD *)(v3 + 88) )
                  {
                    v5 = (dword_721558 * *(_DWORD *)(v3 + 16)
                        + *(_DWORD *)(v3 + 28)
                        + dword_72155C * *(_DWORD *)(v3 + 20)
                        + dword_721560 * *(_DWORD *)(v3 + 24)) >> 16;
                    v4 = (dword_721578 * *(_DWORD *)(v3 + 24)
                        + *(_DWORD *)(v3 + 28)
                        + dword_721570 * *(_DWORD *)(v3 + 16)
                        + dword_721574 * *(_DWORD *)(v3 + 20)) >> 16;
                    if ( (v5 < dword_721534 || v4 < dword_721534)
                      && (v5 > -dword_721534 || v4 > -dword_721534)
                      && (v11 = dword_72159C, sub_475D85((int)&dword_721558, (int)&dword_721588, (int)&v11, v3))
                      && v11 < v10 )
                    {
                      v1 = v9;
                      v10 = v11;
                      v12 = *(_WORD *)(*(_DWORD *)(v9 + 40) + 2 * v8);
                    }
                    else
                    {
                      v1 = v9;
                    }
                  }
                }
              }
            }
          }
        }
      }
      ++v8;
    }
    while ( v8 < *(_WORD *)(v1 + 36) );
    v0 = v10;
  }
  if ( dword_7215AC >= v0 && v0 <= dword_72159C )
  {
    dword_7215B0 = v12;
    v7 = dword_6BE644 + 96 * v12;
    if ( *(_WORD *)(v7 + 76) == dword_7215A4 )
      dword_7215A4 = *(_WORD *)(v7 + 78);
    else
      dword_7215A4 = *(_WORD *)(v7 + 76);
    dword_7215AC = 268435455;
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0046F228) --------------------------------------------------------
void __cdecl sub_46F228()
{
  int v0; // ebx@1
  int v1; // edi@1
  __int16 v2; // ax@3
  char *v3; // esi@3
  int v4; // ecx@5
  int v5; // eax@8
  int v6; // ecx@8
  int v7; // eax@12
  int v8; // eax@16
  unsigned __int8 v9; // zf@18
  char v10; // sf@18
  unsigned __int8 v11; // of@18
  int v12; // edi@19
  int v13; // ecx@19
  __int16 v14; // ax@19
  unsigned __int8 v15; // zf@21
  char v16; // sf@21
  unsigned __int8 v17; // of@21
  signed int v18; // eax@24
  int v19; // ebx@24
  int v20; // ecx@24
  int v21; // esi@24
  int v22; // eax@24
  int v23; // edx@24
  int v24; // ecx@24
  signed int v25; // esi@24
  double v26; // st7@24
  int v27; // edi@25
  int v28; // esi@25
  signed __int64 v29; // qtt@27
  int v30; // esi@32
  int v31; // eax@34
  int v32; // ecx@34
  int v33; // edx@34
  unsigned __int64 v34; // qax@34
  int v35; // eax@35
  int v36; // edx@35
  int v37; // eax@35
  int v38; // eax@35
  int v39; // ecx@35
  int v40; // edx@35
  signed int v41; // eax@35
  signed int v42; // edx@35
  unsigned __int8 v43; // cf@35
  unsigned __int8 v44; // zf@35
  int v45; // ecx@36
  int v46; // edi@36
  int v47; // edi@36
  int v48; // ecx@36
  int v49; // edi@36
  int v50; // edx@44
  int v51; // ecx@44
  int v52; // ecx@46
  __int16 v53; // ax@48
  int v54; // eax@51
  __int16 v55; // ax@54
  int v56; // ecx@57
  int v57; // edx@57
  unsigned __int64 v58; // qax@57
  int v59; // ecx@58
  int v60; // eax@58
  int v61; // eax@59
  int v62; // [sp-24h] [bp-88h]@12
  signed int v63; // [sp-20h] [bp-84h]@12
  int v64; // [sp-1Ch] [bp-80h]@12
  signed int v65; // [sp-18h] [bp-7Ch]@12
  int v66; // [sp-14h] [bp-78h]@12
  int v67; // [sp-10h] [bp-74h]@12
  int v68; // [sp-Ch] [bp-70h]@12
  int v69; // [sp-8h] [bp-6Ch]@12
  int v70; // [sp+8h] [bp-5Ch]@31
  int v71; // [sp+Ch] [bp-58h]@34
  int v72; // [sp+10h] [bp-54h]@34
  int v73; // [sp+14h] [bp-50h]@31
  int v74; // [sp+18h] [bp-4Ch]@34
  int v75; // [sp+1Ch] [bp-48h]@34
  int v76; // [sp+20h] [bp-44h]@24
  __int16 v77; // [sp+24h] [bp-40h]@24
  int v78; // [sp+28h] [bp-3Ch]@36
  int v79; // [sp+2Ch] [bp-38h]@36
  int v80; // [sp+30h] [bp-34h]@36
  int v81; // [sp+34h] [bp-30h]@36
  int v82; // [sp+38h] [bp-2Ch]@19
  int v83; // [sp+3Ch] [bp-28h]@2
  int v84; // [sp+40h] [bp-24h]@1
  int v85; // [sp+44h] [bp-20h]@35
  int v86; // [sp+48h] [bp-1Ch]@34
  int v87; // [sp+4Ch] [bp-18h]@34
  int v88; // [sp+50h] [bp-14h]@19
  int v89; // [sp+54h] [bp-10h]@1
  char *v90; // [sp+58h] [bp-Ch]@3
  int v91; // [sp+5Ch] [bp-8h]@18
  int v92; // [sp+60h] [bp-4h]@6

  v0 = 0;
  v1 = 0;
  v89 = (unsigned __int16)word_4F0040[dword_6BE13C];
  v84 = 0;
  if ( dword_6BE660 > 0 )
  {
    v83 = 0;
    do
    {
      v3 = (char *)Src + v83;
      v90 = (char *)Src + v83;
      v2 = *(_WORD *)((char *)Src + v83 + 76);
      if ( v2 == (_WORD)v0 || v2 == 2 )
      {
        *(_DWORD *)v3 &= 0xFFFFFFFDu;
        goto LABEL_62;
      }
      *((_DWORD *)v3 + 2) += pClass24_global->int_00001C;
      v4 = *((_DWORD *)v3 + 2);
      if ( *((_WORD *)v3 + 38) == 1 )
      {
        v92 = v4 * *((_DWORD *)v3 + 8) / 128;
        if ( v92 >= *((_DWORD *)v3 + 6) )
        {
          v92 = *((_DWORD *)v3 + 6);
          *((_WORD *)v3 + 38) = 2;
LABEL_10:
          if ( !(*v3 & 6) && *((_WORD *)v3 + 34) != (_WORD)v0 )
          {
            v69 = v0;
            v68 = v0;
            v67 = v0;
            v7 = 8 * v1;
            v66 = v0;
            v65 = -1;
            LOBYTE(v7) = 8 * v1 | 1;
            v64 = v0;
            v63 = v7;
            v62 = v89 + 1;
LABEL_17:
            AudioPlayer_sub_4AA306(pAudioPlayer, v62, v63, v64, v65, v66, v67, v68, v69);
            goto LABEL_18;
          }
          goto LABEL_18;
        }
      }
      else
      {
        v5 = v4 * *((_DWORD *)v3 + 7) / 128;
        v6 = *((_DWORD *)v3 + 6);
        if ( v5 >= v6 )
        {
          v92 = v0;
          *((_WORD *)v3 + 38) = v0;
          goto LABEL_10;
        }
        v92 = v6 - v5;
      }
      if ( !(*v3 & 6) && *((_WORD *)v3 + 34) != (_WORD)v0 )
      {
        v69 = v0;
        v68 = v0;
        v67 = v0;
        v8 = 8 * v1;
        v66 = v0;
        v65 = -1;
        LOBYTE(v8) = 8 * v1 | 1;
        v64 = 1;
        v63 = v8;
        v62 = v89;
        goto LABEL_17;
      }
LABEL_18:
      compile_error;//v11 = __SETO__(*((_WORD *)v3 + 34), v0);
      v9 = *((_WORD *)v3 + 34) == (_WORD)v0;
      v10 = (signed __int16)(*((_WORD *)v3 + 34) - v0) < 0;
      v91 = v0;
      if ( !((unsigned __int8)(v10 ^ v11) | v9) )
      {
        do
        {
          v12 = 2 * v91;
          v13 = *(_WORD *)(2 * v91 + *((_DWORD *)v3 + 9));
          v88 = v92;
          v82 = *((_DWORD *)v3 + 3);
          v88 = (unsigned __int64)(v82 * v92) >> 16;
          v13 *= 6;
          *(_WORD *)(v13 + dword_6BE63C) = ((unsigned int)(v82 * v92) >> 16)
                                         + *(_WORD *)(2 * v91 + *((_DWORD *)v3 + 14));
          v88 = v92;
          v82 = *((_DWORD *)v3 + 4);
          v88 = (unsigned __int64)(v82 * v92) >> 16;
          *(_WORD *)(v13 + dword_6BE63C + 2) = ((unsigned int)(v82 * v92) >> 16)
                                             + *(_WORD *)(v12 + *((_DWORD *)v3 + 15));
          v88 = v92;
          v82 = *((_DWORD *)v3 + 5);
          v88 = (unsigned __int64)(v82 * v92) >> 16;
          v14 = ((unsigned int)(v82 * v92) >> 16) + *(_WORD *)(v12 + *((_DWORD *)v3 + 16));
          ++v91;
          *(_WORD *)(v13 + dword_6BE63C + 4) = v14;
        }
        while ( v91 < *((_WORD *)v3 + 34) );
        v1 = v84;
      }
      compile_error;//v17 = __SETO__(*((_WORD *)v3 + 35), v0);
      v15 = *((_WORD *)v3 + 35) == (_WORD)v0;
      v16 = (signed __int16)(*((_WORD *)v3 + 35) - v0) < 0;
      v91 = v0;
      if ( !((unsigned __int8)(v16 ^ v17) | v15) )
      {
        while ( 1 )
        {
          v19 = dword_6BE644 + 96 * *(_WORD *)(*((_DWORD *)v3 + 10) + 2 * v91);
          v20 = *(_DWORD *)(v19 + 48);
          v21 = dword_6BE63C + 6 * *(_WORD *)v20;
          v22 = *(_DWORD *)(v19 + 20);
          v76 = *(_DWORD *)v21;
          v77 = *(_WORD *)(v21 + 4);
          v23 = *(_DWORD *)(v19 + 24);
          v18 = -(v23 * v77 + (signed __int16)v76 * *(_DWORD *)(v19 + 16) + SHIWORD(v76) * v22);
          *(_DWORD *)(v19 + 28) = v18;
          v24 = dword_6BE63C + 6 * *(_WORD *)v20;
          v82 = *(_WORD *)v24;
          v25 = *(_WORD *)(v24 + 2);
          v26 = (double)v82;
          v82 = *(_WORD *)(v24 + 4);
          *(float *)(v19 + 12) = -((double)v82 * *(float *)(v19 + 8)
                                 + (double)v25 * *(float *)(v19 + 4)
                                 + v26 * *(float *)v19);
          if ( v23 )
          {
            v28 = abs(v18 >> 15);
            v27 = (int)v90;
            if ( v28 > abs(*(_DWORD *)(v19 + 24)) )
              erroneous_printf(
                "Door Error\ndoor id: %i\nfacet no: %i\n\nOverflow dividing facet->d [%i] by facet->nz [%i]",
                *((_DWORD *)v90 + 1),
                *(_WORD *)(*((_DWORD *)v90 + 10) + 2 * v91),
                *(_DWORD *)(v19 + 28),
                *(_DWORD *)(v19 + 24));
            v82 = *(_DWORD *)(v19 + 24);
            v88 = *(_DWORD *)(v19 + 28);
            LODWORD(v29) = v88 << 16;
            HIDWORD(v29) = v88 >> 16;
            v88 = v29 / v82;
            *(_DWORD *)(v19 + 40) = -(v29 / v82);
          }
          else
          {
            v27 = (int)v90;
          }
          if ( *(_BYTE *)(v19 + 46) & 4 || pD3DRenderer->dword_040088 )
            sub_498A41(v19, (int)&v73, (int)&v70);
          v30 = dword_6BE64C + 36 * *(_WORD *)(v19 + 72);
          if ( !pD3DRenderer->dword_040088 )
          {
            if ( !(*(_BYTE *)(v19 + 46) & 4) )
              goto LABEL_59;
            v82 = *(_DWORD *)(v27 + 12);
            v86 = (unsigned __int64)(v82 * v73) >> 16;
            v88 = v74;
            v82 = *(_DWORD *)(v27 + 16);
            v88 = (unsigned __int64)(v82 * v74) >> 16;
            v87 = v75;
            v82 = *(_DWORD *)(v27 + 20);
            v87 = (unsigned __int64)(v82 * v75) >> 16;
            v82 = v86 + v88 + ((unsigned __int64)(v82 * v75) >> 16);
            v32 = v92;
            v86 = (unsigned __int64)(v82 * v92) >> 16;
            *(_WORD *)(v30 + 20) = -((unsigned int)(v82 * v92) >> 16);
            v82 = *(_DWORD *)(v27 + 12);
            v88 = (unsigned __int64)(v82 * v70) >> 16;
            v86 = v71;
            v82 = *(_DWORD *)(v27 + 16);
            v86 = (unsigned __int64)(v82 * v71) >> 16;
            v87 = v72;
            v82 = *(_DWORD *)(v27 + 20);
            v87 = (unsigned __int64)(v82 * v72) >> 16;
            v33 = v86 + ((unsigned __int64)(v82 * v72) >> 16);
            v82 = v88 + v33;
            v34 = (v88 + v33) * v32;
            v86 = v34 >> 16;
            v31 = v34 >> 16;
            goto LABEL_58;
          }
          *(_WORD *)(v30 + 20) = 0;
          *(_WORD *)(v30 + 22) = 0;
          v37 = *(_DWORD *)(v19 + 48);
          v88 = 1;
          v38 = dword_6BE63C + 6 * *(_WORD *)v37;
          v39 = *(_WORD *)(v38 + 4);
          v40 = *(_WORD *)(v38 + 2);
          v85 = *(_WORD *)v38;
          v82 = v40;
          v41 = v73 * v85 + v74 * v40 + v75 * v39;
          v42 = v70 * v85 + v71 * v40 + v39 * v72;
          v35 = v41 >> 16;
          **(_WORD **)(v19 + 64) = v35;
          v36 = v42 >> 16;
          **(_WORD **)(v19 + 68) = v36;
          v43 = *(_BYTE *)(v19 + 93) < 1u;
          v44 = *(_BYTE *)(v19 + 93) == 1;
          v86 = v36;
          v87 = v35;
          v85 = v36;
          if ( !(v43 | v44) )
          {
            do
            {
              v46 = *(_DWORD *)(v19 + 48);
              v78 = 2 * v88;
              v47 = dword_6BE63C + 6 * *(_WORD *)(v46 + 2 * v88);
              v82 = *(_WORD *)(v47 + 4);
              v48 = *(_WORD *)(v47 + 2);
              v49 = *(_WORD *)v47;
              v81 = v48;
              v79 = (v75 * v82 + v73 * v49 + v74 * v48) >> 16;
              v45 = (v70 * v49 + v71 * v48 + v82 * v72) >> 16;
              v80 = v45;
              if ( v79 < v35 )
                v35 = v79;
              if ( v45 < v36 )
                v86 = v45;
              if ( v79 > v87 )
                v87 = v79;
              if ( v45 > v85 )
                v85 = v45;
              v50 = *(_DWORD *)(v19 + 64);
              v51 = v78;
              ++v88;
              *(_WORD *)(v78 + v50) = v79;
              *(_WORD *)(v51 + *(_DWORD *)(v19 + 68)) = v80;
              v36 = v86;
            }
            while ( v88 < *(_BYTE *)(v19 + 93) );
            v27 = (int)v90;
          }
          v52 = *(_DWORD *)(v19 + 44);
          if ( BYTE1(v52) & 0x10 )
            goto LABEL_50;
          if ( BYTE1(v52) < 0 )
          {
            v53 = *(_WORD *)(v19 + 74);
            if ( v53 != -1 )
            {
              LOWORD(v35) = v87 + *(_WORD *)((signed __int16)v35 != -1 ? 72 * (signed __int16)v35 + 7278780 + 0x18 : 24);
LABEL_50:
              *(_WORD *)(v30 + 20) -= v35;
              goto LABEL_51;
            }
          }
LABEL_51:
          v54 = *(_DWORD *)(v19 + 44);
          if ( v54 & 8 )
          {
            *(_WORD *)(v30 + 22) -= v36;
          }
          else
          {
            if ( v54 & 0x20000 )
            {
              v55 = *(_WORD *)(v19 + 74);
              if ( v55 != -1 )
                *(_WORD *)(v30 + 22) -= v85 + *(_WORD *)(v55 != -1 ? 72 * v55 + 7278780 + 0x1A : 26);
            }
          }
          if ( *(_BYTE *)(v19 + 46) & 4 )
          {
            v78 = *(_DWORD *)(v27 + 12);
            v87 = (unsigned __int64)(v78 * v73) >> 16;
            v85 = v74;
            v78 = *(_DWORD *)(v27 + 16);
            v85 = (unsigned __int64)(v78 * v74) >> 16;
            v86 = v75;
            v78 = *(_DWORD *)(v27 + 20);
            v86 = (unsigned __int64)(v78 * v75) >> 16;
            v78 = v87 + v85 + ((unsigned __int64)(v78 * v75) >> 16);
            v56 = v92;
            v85 = (unsigned __int64)(v78 * v92) >> 16;
            *(_WORD *)(v30 + 20) = -((unsigned int)(v78 * v92) >> 16);
            v78 = *(_DWORD *)(v27 + 12);
            v87 = (unsigned __int64)(v78 * v70) >> 16;
            v85 = v71;
            v78 = *(_DWORD *)(v27 + 16);
            v85 = (unsigned __int64)(v78 * v71) >> 16;
            v86 = v72;
            v78 = *(_DWORD *)(v27 + 20);
            v86 = (unsigned __int64)(v78 * v72) >> 16;
            v57 = v85 + ((unsigned __int64)(v78 * v72) >> 16);
            v78 = v87 + v57;
            v58 = (v87 + v57) * v56;
            v85 = v58 >> 16;
            v31 = v58 >> 16;
LABEL_58:
            v59 = v91;
            v60 = -v31;
            *(_WORD *)(v30 + 22) = v60;
            *(_WORD *)(v30 + 20) += *(_WORD *)(*(_DWORD *)(v27 + 48) + 2 * v59);
            *(_WORD *)(v30 + 22) = v60 + *(_WORD *)(*(_DWORD *)(v27 + 52) + 2 * v59);
          }
LABEL_59:
          v61 = *(_WORD *)(v27 + 70);
          ++v91;
          if ( v91 >= v61 )
          {
            v1 = v84;
            v0 = 0;
            break;
          }
          v3 = v90;
        }
      }
LABEL_62:
      v83 += 80;
      ++v1;
      v84 = v1;
    }
    while ( v1 < dword_6BE660 );
  }
}

//----- (0046F90C) --------------------------------------------------------
void __cdecl sub_46F90C()
{
  __int16 v0; // ax@2
  int v1; // esi@2
  int v2; // edi@6
  int v3; // eax@6
  int v4; // eax@8
  __int16 v5; // ax@11
  unsigned __int8 v6; // zf@14
  unsigned __int8 v7; // sf@14
  signed int v8; // ebx@14
  signed __int16 v9; // ax@17
  signed __int64 v10; // qax@18
  __int16 v11; // ax@21
  int v12; // eax@29
  unsigned __int64 v13; // qax@29
  char v14; // zf@29
  char v15; // zf@31
  int v16; // edx@33
  int v17; // ecx@33
  int v18; // ecx@33
  unsigned __int8 v19; // sf@33
  unsigned __int8 v20; // of@33
  int v21; // eax@34
  int v22; // ecx@46
  int v23; // edi@46
  int v24; // eax@46
  int v25; // eax@48
  int v26; // eax@51
  int v27; // eax@52
  int v28; // ebx@54
  int v29; // ST08_4@54
  int v30; // edi@54
  int v31; // eax@54
  unsigned __int8 v32; // sf@58
  unsigned __int8 v33; // of@58
  int v34; // eax@62
  signed int v35; // ecx@62
  signed int v36; // ebx@62
  int v37; // eax@64
  int v38; // ecx@64
  int v39; // ecx@64
  int v40; // edx@85
  int v41; // ebx@85
  int v42; // edi@89
  int v43; // ecx@90
  int v44; // ebx@90
  char v45; // al@94
  int v46; // eax@96
  __int16 v47; // dx@96
  int v48; // ecx@96
  int v49; // edi@101
  int v50; // edi@101
  unsigned __int8 v51; // zf@103
  unsigned __int8 v52; // sf@103
  unsigned __int8 v53; // of@103
  char v54; // [sp+0h] [bp-60h]@75
  char v55; // [sp+1Ch] [bp-44h]@116
  int v56; // [sp+38h] [bp-28h]@53
  int v57; // [sp+3Ch] [bp-24h]@6
  int v58; // [sp+40h] [bp-20h]@6
  void *v59; // [sp+44h] [bp-1Ch]@51
  int v60; // [sp+48h] [bp-18h]@51
  int v61; // [sp+4Ch] [bp-14h]@8
  int v62; // [sp+50h] [bp-10h]@6
  int v63; // [sp+54h] [bp-Ch]@14
  int v64; // [sp+58h] [bp-8h]@6
  int v65; // [sp+5Ch] [bp-4h]@1

  v65 = 0;
  if ( (signed int)uNumActors > 0 )
  {
    while ( 1 )
    {
      v1 = (int)((char *)pActors + 836 * v65);
      v0 = *(_WORD *)(v1 + 176);
      if ( v0 == 11 )
        goto LABEL_123;
      if ( v0 == 19 )
        goto LABEL_123;
      if ( v0 == 17 )
        goto LABEL_123;
      if ( !*(_WORD *)(v1 + 140) )
        goto LABEL_123;
      v57 = *(_WORD *)(v1 + 158);
      v2 = sub_46ED1B(*(_WORD *)(v1 + 142), *(_WORD *)(v1 + 144), *(_WORD *)(v1 + 146), &v57, (int)&v62);
      *(_WORD *)(v1 + 158) = v57;
      v3 = *(_BYTE *)(v1 + 58);
      v58 = v2;
      v64 = v3;
      if ( !sub_40894B(v1) )
        v64 = 0;
      v4 = *(_WORD *)(v1 + 146);
      v61 = 0;
      if ( v4 > v2 + 1 )
        v61 = 1;
      if ( v2 <= -30000 )
      {
        v5 = sub_49AC17((int)byte_6BE3C8, *(_WORD *)(v1 + 142), *(_WORD *)(v1 + 144), v4);
        *(_WORD *)(v1 + 158) = v5;
        if ( !v5
          || (v58 = sub_46CEC3(*(_WORD *)(v1 + 142), *(_WORD *)(v1 + 144), *(_WORD *)(v1 + 146), v5, (int)&v62),
              v58 == -30000) )
          goto LABEL_123;
      }
      if ( *(_WORD *)(v1 + 178) == 1 )
      {
        v8 = *(_WORD *)(v1 + 140);
        v6 = *(_DWORD *)(v1 + 328) == 0;
        v7 = *(_DWORD *)(v1 + 328) < 0;
        v63 = *(_WORD *)(v1 + 140);
        if ( !v7 )
        {
          if ( !(v7 | v6) || *(_DWORD *)(v1 + 324) )
          {
            v9 = *(_WORD *)(v1 + 332);
            if ( v9 )
              LODWORD(v10) = v8 / (unsigned __int16)v9;
            else
              v10 = (signed __int64)((double)v63 * memory_4D8410.d_0_5);
            v8 = v10;
            v63 = v10;
          }
        }
        v11 = *(_WORD *)(v1 + 176);
        if ( v11 == 6 || v11 == 7 )
        {
          v8 *= 2;
          v63 = v8;
        }
        if ( dword_ACD834 == 1 )
        {
          if ( dword_4F885C == 1 )
            v8 = (signed __int64)((double)v63 * flt_6BE3AC);
        }
        if ( v8 > 1000 )
          v8 = 1000;
        v12 = class59_SinCos(pClass59_global, *(_WORD *)(v1 + 154));
        v57 = v12;
        v13 = v12 * v8;
        v63 = v13 >> 16;
        *(_WORD *)(v1 + 148) = WORD1(v13);
        v57 = class59_SinCos(pClass59_global, *(_WORD *)(v1 + 154) - pClass59_global->uNumTableEntries);
        v63 = (unsigned __int64)(v57 * v8) >> 16;
        v14 = v64 == 0;
        *(_WORD *)(v1 + 150) = (unsigned int)(v57 * v8) >> 16;
        if ( !v14 )
        {
          v57 = class59_SinCos(pClass59_global, *(_WORD *)(v1 + 156) - pClass59_global->uNumTableEntries);
          v63 = (unsigned __int64)(v57 * v8) >> 16;
          *(_WORD *)(v1 + 152) = (unsigned int)(v57 * v8) >> 16;
        }
      }
      else
      {
        v63 = *(_WORD *)(v1 + 148);
        v63 = (unsigned __int64)(55000i64 * v63) >> 16;
        v57 = 55000;
        *(_WORD *)(v1 + 148) = v63;
        v63 = *(_WORD *)(v1 + 150);
        v63 = (unsigned __int64)(v57 * v63) >> 16;
        v15 = v64 == 0;
        *(_WORD *)(v1 + 150) = v63;
        if ( !v15 )
        {
          v57 = 55000;
          v63 = *(_WORD *)(v1 + 152);
          v63 = (unsigned __int64)(55000i64 * v63) >> 16;
          *(_WORD *)(v1 + 152) = v63;
        }
      }
      v18 = *(_WORD *)(v1 + 146);
      v16 = dword_6BE644;
      compile_error;//v20 = __SETO__(v18, v58);
      v19 = v18 - v58 < 0;
      v17 = v62;
      if ( v19 ^ v20 )
      {
        *(_WORD *)(v1 + 146) = v58 + 1;
        v21 = v16 + 96 * v17;
        if ( *(_BYTE *)(v21 + 92) == 3 )
        {
          if ( *(_WORD *)(v1 + 152) < 0 )
            *(_WORD *)(v1 + 152) = 0;
        }
        else
        {
          if ( *(_DWORD *)(v21 + 24) < 45000 )
            *(_WORD *)(v1 + 152) -= pClass24_global->int_00001C * sub_46BDA8();
        }
      }
      else
      {
        if ( v61 )
        {
          if ( !v64 )
            *(_WORD *)(v1 + 152) += -8 * pClass24_global->int_00001C * sub_46BDA8();
        }
      }
      if ( *(_WORD *)(v1 + 148) * (signed int)*(_WORD *)(v1 + 148)
         + *(_WORD *)(v1 + 150) * (signed int)*(_WORD *)(v1 + 150)
         + *(_WORD *)(v1 + 152) * (signed int)*(_WORD *)(v1 + 152) >= 400 )
        break;
      *(_WORD *)(v1 + 152) = 0;
      *(_WORD *)(v1 + 150) = 0;
      *(_WORD *)(v1 + 148) = 0;
      if ( *(_BYTE *)(96 * v17 + v16 + 46) & 0x40 )
      {
        if ( *(_WORD *)(v1 + 176) == 5 )
          *(_WORD *)(v1 + 176) = 11;
      }
LABEL_123:
      ++v65;
      if ( v65 >= (signed int)uNumActors )
        return;
    }
    v22 = *(_WORD *)(v1 + 136);
    v24 = *(_WORD *)(v1 + 138);
    dword_7215B4 = -1;
    dword_7215A0 = 0;
    v57 = 0;
    dword_721530 = 1;
    dword_721538 = v22;
    dword_721534 = v22;
    dword_72153C = v24;
    v23 = 0;
    while ( 1 )
    {
      dword_721564 = *(_WORD *)(v1 + 142);
      dword_721558 = dword_721564;
      dword_721568 = *(_WORD *)(v1 + 144);
      dword_72155C = dword_721568;
      v25 = *(_WORD *)(v1 + 146);
      dword_721560 = v25 + v22 + 1;
      dword_72156C = v25 - v22 + dword_72153C - 1;
      if ( dword_72156C < dword_721560 )
        dword_72156C = v25 + v22 + 1;
      dword_72154C = *(_WORD *)(v1 + 148);
      dword_721550 = *(_WORD *)(v1 + 150);
      dword_721554 = *(_WORD *)(v1 + 152);
      dword_7215A4 = *(_WORD *)(v1 + 158);
      if ( !sub_47050A((int)&dword_721530, v23) )
      {
        v60 = v23;
        v26 = 8 * v65;
        LOBYTE(v26) = 8 * v65 | 3;
        v63 = v23;
        v59 = (void *)v26;
        do
        {
          sub_46E44E((void *)1);
          sub_46E0B2();
          sub_46EF01(0);
          sub_46ED8A(v59);
          v27 = 0;
          v58 = 0;
          if ( dword_4F75D8 > v23 )
          {
            do
            {
              v56 = dword_4F7DB0[v27];
              if ( v56 != v65 )
              {
                v28 = 836 * v56;
                v29 = abs(pActors[v56].word_000092 - *(_WORD *)(v1 + 146));
                v30 = abs(pActors[v56].sActorPosY - *(_WORD *)(v1 + 144));
                v31 = abs(pActors[v56].sActorPosX - *(_WORD *)(v1 + 142));
                if ( sub_4621DA(v31, v30, v29) >= *(_WORD *)(v1 + 136) + pActors[v56].word_000088)
                {
                  if ( sub_46DF1A(v56, 40) )
                    ++v60;
                }
                v23 = 0;
              }
              v27 = v58 + 1;
              compile_error;//v33 = __SETO__(v58 + 1, dword_4F75D8);
              v32 = v58++ + 1 - dword_4F75D8 < 0;
            }
            while ( v32 ^ v33 );
          }
          if ( sub_46F04E() )
            break;
          ++v63;
        }
        while ( v63 < 100 );
        v58 = v60 > 1;
        if ( dword_7215AC >= dword_72159C )
        {
          v35 = dword_721570;
          v36 = dword_721574;
          v34 = dword_721578 - dword_721534 - 1;
        }
        else
        {
          v60 = (unsigned __int64)(dword_7215AC * dword_721588) >> 16;
          v35 = v60 + *(_WORD *)(v1 + 142);
          v60 = (unsigned __int64)(dword_7215AC * dword_72158C) >> 16;
          v36 = v60 + *(_WORD *)(v1 + 144);
          v60 = (unsigned __int64)(dword_7215AC * dword_721590) >> 16;
          v34 = v60 + *(_WORD *)(v1 + 146);
        }
        v37 = sub_46ED1B(v35, v36, v34, &dword_7215A4, (int)&v62);
        v39 = *(_DWORD *)(96 * v62 + dword_6BE644 + 44);
        v38 = v39 & 0x400000;
        if ( v38 && *(_WORD *)(v1 + 176) == 5 )
        {
          *(_WORD *)(v1 + 176) = 11;
          goto LABEL_120;
        }
        if ( v61 != v23 || v64 != v23 || v38 == v23 )
        {
          if ( v37 == -30000 )
            goto LABEL_120;
          if ( *(_WORD *)(v1 + 178) != 1 || v37 >= *(_WORD *)(v1 + 146) - 100 || v61 != v23 || v64 != v23 )
          {
            if ( dword_7215AC >= dword_72159C )
            {
              *(_WORD *)(v1 + 142) = dword_721570;
              *(_WORD *)(v1 + 144) = dword_721574;
              *(_WORD *)(v1 + 146) = dword_721578 - (_WORD)dword_721534 - 1;
              *(_WORD *)(v1 + 158) = dword_7215A4;
              goto LABEL_123;
            }
            v60 = (unsigned __int64)(dword_7215AC * dword_721588) >> 16;
            *(_WORD *)(v1 + 142) += (unsigned int)(dword_7215AC * dword_721588) >> 16;
            v60 = (unsigned __int64)(dword_7215AC * dword_72158C) >> 16;
            *(_WORD *)(v1 + 144) += (unsigned int)(dword_7215AC * dword_72158C) >> 16;
            v60 = (unsigned __int64)(dword_7215AC * dword_721590) >> 16;
            v40 = dword_7215A8;
            *(_WORD *)(v1 + 146) += (unsigned int)(dword_7215AC * dword_721590) >> 16;
            *(_WORD *)(v1 + 158) = dword_7215A4;
            dword_7215A0 += dword_7215AC;
            v41 = v40 >> 3;
            if ( (v40 & 7) != 3 )
            {
              if ( (v40 & 7) != 4 )
              {
                if ( (v40 & 7) == 5 )
                {
                  v59 = (void *)sub_452A9E(*(_WORD *)(v1 + 148) * *(_WORD *)(v1 + 148) + *(_WORD *)(v1 + 150)
                                                                                       * *(_WORD *)(v1 + 150));
                  v49 = sub_45281E(
                          pClass59_global,
                          *(_WORD *)(v1 + 142) - array_6836D0[v41].sPosX,
                          *(_WORD *)(v1 + 144) - array_6836D0[v41].sPosY);
                  v56 = class59_SinCos(pClass59_global, v49);
                  v58 = (unsigned __int64)(v56 * (signed int)v59) >> 16;
                  v50 = v49 - pClass59_global->uNumTableEntries;
                  *(_WORD *)(v1 + 148) = (unsigned int)(v56 * (_DWORD)v59) >> 16;
                  v56 = class59_SinCos(pClass59_global, v50);
                  v58 = (unsigned __int64)(v56 * (signed int)v59) >> 16;
                  *(_WORD *)(v1 + 150) = (unsigned int)(v56 * (_DWORD)v59) >> 16;
                  goto LABEL_119;
                }
                if ( (v40 & 7) == 6 )
                {
                  dword_7215B4 = v40 >> 3;
                  v42 = dword_6BE644 + 96 * v41;
                  if ( *(_BYTE *)(v42 + 92) == 3 )
                  {
                    v43 = *(_WORD *)(v1 + 148);
                    v44 = *(_WORD *)(v1 + 150) * *(_WORD *)(v1 + 150);
                    *(_WORD *)(v1 + 152) = 0;
                    *(_WORD *)(v1 + 146) = *(_WORD *)(dword_6BE63C + 6 * **(_WORD **)(v42 + 48) + 4) + 1;
                    if ( v43 * v43 + v44 < 400 )
                    {
                      *(_WORD *)(v1 + 150) = 0;
                      *(_WORD *)(v1 + 148) = 0;
                      goto LABEL_119;
                    }
                  }
                  else
                  {
                    v63 = abs(*(_DWORD *)(v42 + 16) * *(_WORD *)(v1 + 148) + *(_DWORD *)(v42 + 20)
                                                                           * *(_WORD *)(v1 + 150)
                                                                           + *(_DWORD *)(v42 + 24)
                                                                           * *(_WORD *)(v1 + 152)) >> 16;
                    if ( dword_721594 >> 3 > v63 )
                      v63 = dword_721594 >> 3;
                    v60 = *(_DWORD *)(v42 + 16);
                    v60 = (unsigned __int64)(v63 * v60) >> 16;
                    v59 = *(void **)(v42 + 20);
                    v59 = (void *)((unsigned __int64)(v63 * (signed int)v59) >> 16);
                    v58 = *(_DWORD *)(v42 + 24);
                    v58 = (unsigned __int64)(v63 * v58) >> 16;
                    *(_WORD *)(v1 + 148) += v60;
                    *(_WORD *)(v1 + 150) += (_WORD)v59;
                    *(_WORD *)(v1 + 152) += v58;
                    v45 = *(_BYTE *)(v42 + 92);
                    if ( v45 != 4 )
                    {
                      if ( v45 != 3 )
                      {
                        v46 = *(_DWORD *)(v42 + 16);
                        v47 = *(_WORD *)(v1 + 146);
                        v48 = dword_721534
                            - ((*(_DWORD *)(v42 + 28)
                              + *(_DWORD *)(v42 + 24) * (signed int)*(_WORD *)(v1 + 146)
                              + *(_DWORD *)(v42 + 20) * (signed int)*(_WORD *)(v1 + 144)
                              + v46 * *(_WORD *)(v1 + 142)) >> 16);
                        if ( v48 > 0 )
                        {
                          *(_WORD *)(v1 + 142) += v48 * v46 >> 16;
                          *(_WORD *)(v1 + 144) += v48 * *(_DWORD *)(v42 + 20) >> 16;
                          *(_WORD *)(v1 + 146) = v47 + (v48 * *(_DWORD *)(v42 + 24) >> 16);
                        }
                        *(_WORD *)(v1 + 154) = sub_45281E(pClass59_global, *(_WORD *)(v1 + 148), *(_WORD *)(v1 + 150));
                      }
                    }
                  }
                  if ( *(_BYTE *)(v42 + 47) & 8 )
                    sub_44684A_LooksLikeEventProcessor(*(_WORD *)(dword_6BE64C + 36 * *(_WORD *)(v42 + 72) + 26), 0, 1);
                }
LABEL_119:
                v58 = *(_WORD *)(v1 + 148);
                v58 = (unsigned __int64)(58500i64 * v58) >> 16;
                v56 = 58500;
                *(_WORD *)(v1 + 148) = v58;
                v58 = *(_WORD *)(v1 + 150);
                v58 = (unsigned __int64)(v56 * v58) >> 16;
                v56 = 58500;
                *(_WORD *)(v1 + 150) = v58;
                v58 = *(_WORD *)(v1 + 152);
                v58 = (unsigned __int64)(v56 * v58) >> 16;
                v23 = 0;
                *(_WORD *)(v1 + 152) = v58;
                goto LABEL_120;
              }
              if ( Actor_sub_40104C(v1, 0) )
              {
                compile_error;//v53 = __SETO__(HIDWORD(qword_ACD8F4), v23);
                v51 = HIDWORD(qword_ACD8F4) == v23;
                v52 = HIDWORD(qword_ACD8F4) - v23 < 0;
                *(_WORD *)(v1 + 150) = v23;
                *(_WORD *)(v1 + 148) = v23;
                if ( !(v52 ^ v53) )
                {
                  if ( !((unsigned __int8)(v52 ^ v53) | v51) || (_DWORD)qword_ACD8F4 > (unsigned int)v23 )
                    sub_458585((int)&qword_ACD8F4);
                }
                struct_576FE8.dword_000044 = 1;
                goto LABEL_119;
              }
              v40 = dword_7215A8;
LABEL_118:
              sub_404030(v65, v40, v23, v23);
              goto LABEL_119;
            }
            if ( dword_ACD834 == 1 && (dword_4F885C == 2 || dword_4F885C == 3) )
              goto LABEL_119;
            if ( *(_BYTE *)(v1 + 61) )
            {
              if ( v58 == v23 )
                goto LABEL_114;
            }
            else
            {
              if ( v58 == v23 )
              {
                if ( !byte_5FF195[836 * v41] )
                  goto LABEL_118;
LABEL_114:
                sub_402968(v65, v40, v23, (char *)v23);
                goto LABEL_119;
              }
            }
            sub_403F58(v65, 4, v23, (signed int)&v55);
            goto LABEL_119;
          }
          if ( *(_BYTE *)(v1 + 142) & 1 )
            *(_WORD *)(v1 + 154) += 100;
          else
            *(_WORD *)(v1 + 154) -= 100;
        }
        else
        {
          if ( dword_ACD834 == 1 && (dword_4F885C == 2 || dword_4F885C == 3) )
            goto LABEL_123;
          if ( !*(_BYTE *)(v1 + 61) || v58 != v23 )
          {
            sub_403F58(v65, 4, v23, (signed int)&v54);
            goto LABEL_123;
          }
        }
      }
LABEL_120:
      ++v57;
      if ( v57 >= 100 )
        goto LABEL_123;
      v22 = dword_721534;
    }
  }
}

//----- (0047050A) --------------------------------------------------------
signed int __thiscall sub_47050A(int this, int a2)
{
  int v2; // eax@1
  int v3; // ecx@1
  int v4; // esi@1
  signed int v5; // eax@1
  int v6; // edx@1
  int v7; // edx@1
  int v8; // eax@3
  signed int result; // eax@4
  int v10; // eax@5
  int v11; // edx@5
  int v12; // ecx@5
  int v13; // ebx@5
  int v14; // edi@5
  int v15; // eax@5
  int v16; // eax@5
  int v17; // eax@5
  int v18; // eax@7
  int v19; // eax@9
  int v20; // edx@9
  int v21; // edi@9
  int v22; // eax@11
  int v23; // eax@13
  int v24; // edx@13
  int v25; // eax@14
  int v26; // eax@16
  int v27; // eax@17
  int v28; // [sp+14h] [bp+8h]@5

  v4 = this;
  v5 = sub_452A9E(*(_DWORD *)(this + 36) * *(_DWORD *)(this + 36) + *(_DWORD *)(this + 32) * *(_DWORD *)(this + 32)
                                                                  + *(_DWORD *)(this + 28) * *(_DWORD *)(this + 28));
  v3 = v5 | 1;
  v6 = *(_DWORD *)(v4 + 28);
  *(_DWORD *)(v4 + 100) = v5 | 1;
  *(_DWORD *)(v4 + 88) = 65536 / (v5 | 1) * v6;
  *(_DWORD *)(v4 + 92) = 65536 / (v5 | 1) * *(_DWORD *)(v4 + 32);
  v7 = 65536 / (v5 | 1) * *(_DWORD *)(v4 + 36);
  *(_DWORD *)(v4 + 104) = 65536 / (v5 | 1);
  v2 = a2;
  *(_DWORD *)(v4 + 96) = v7;
  if ( !a2 )
    v2 = pClass24_global->dword_000020;
  v8 = ((unsigned __int64)(v2 * v3) >> 16) - *(_DWORD *)(v4 + 112);
  *(_DWORD *)(v4 + 108) = v8;
  if ( v8 > 0 )
  {
    v15 = ((unsigned __int64)(v8 * *(_DWORD *)(v4 + 88)) >> 16) + *(_DWORD *)(v4 + 40);
    *(_DWORD *)(v4 + 76) = v15;
    *(_DWORD *)(v4 + 64) = v15;
    v16 = ((unsigned __int64)(*(_DWORD *)(v4 + 108) * *(_DWORD *)(v4 + 92)) >> 16) + *(_DWORD *)(v4 + 44);
    *(_DWORD *)(v4 + 80) = v16;
    *(_DWORD *)(v4 + 68) = v16;
    *(_DWORD *)(v4 + 72) = ((unsigned __int64)(*(_DWORD *)(v4 + 108) * *(_DWORD *)(v4 + 96)) >> 16)
                         + *(_DWORD *)(v4 + 48);
    v13 = *(_DWORD *)(v4 + 60);
    v11 = *(_DWORD *)(v4 + 40);
    v14 = *(_DWORD *)(v4 + 64);
    v12 = *(_DWORD *)(v4 + 4);
    v17 = v13 + ((unsigned __int64)(*(_DWORD *)(v4 + 108) * *(_DWORD *)(v4 + 96)) >> 16);
    v28 = v17;
    *(_DWORD *)(v4 + 84) = v17;
    v10 = v11;
    if ( v11 >= v14 )
      v10 = v14;
    *(_DWORD *)(v4 + 140) = v10 - v12;
    v18 = v12 + v11;
    if ( v11 <= v14 )
      v18 = v12 + v14;
    v20 = *(_DWORD *)(v4 + 44);
    v21 = *(_DWORD *)(v4 + 68);
    *(_DWORD *)(v4 + 144) = v18;
    v19 = v20;
    if ( v20 >= v21 )
      v19 = v21;
    *(_DWORD *)(v4 + 148) = v19 - v12;
    v22 = v12 + v20;
    if ( v20 <= v21 )
      v22 = v21 + v12;
    v24 = *(_DWORD *)(v4 + 72);
    *(_DWORD *)(v4 + 152) = v22;
    v23 = *(_DWORD *)(v4 + 48);
    if ( v23 >= v24 )
      v25 = v24 - v12;
    else
      v25 = v23 - v12;
    *(_DWORD *)(v4 + 156) = v25;
    v26 = *(_DWORD *)(v4 + 8);
    if ( v13 <= v28 )
      v27 = v28 + v26;
    else
      v27 = v13 + v26;
    *(_DWORD *)(v4 + 120) = 0;
    *(_DWORD *)(v4 + 128) = -1;
    *(_DWORD *)(v4 + 136) = -1;
    *(_DWORD *)(v4 + 160) = v27;
    *(_DWORD *)(v4 + 124) = 16777215;
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (004706C6) --------------------------------------------------------
void __cdecl sub_4706C6()
{
  __int16 v0; // ax@2
  int v1; // esi@2
  signed int v2; // ecx@6
  int v3; // ebx@6
  int v4; // eax@8
  signed int v5; // ebx@10
  int v6; // eax@10
  int v7; // ecx@10
  unsigned __int8 v8; // zf@17
  unsigned __int8 v9; // sf@17
  signed int v10; // ebx@17
  __int16 v11; // ax@21
  int v12; // eax@29
  unsigned __int64 v13; // qax@29
  char v14; // zf@29
  int v15; // eax@33
  int v16; // edi@34
  char v17; // zf@37
  signed int v18; // edx@42
  signed int v19; // ecx@42
  __int16 v20; // ax@42
  int v21; // ebx@42
  int v22; // edi@42
  int v23; // ecx@42
  __int16 v24; // ax@42
  int v25; // eax@45
  char v26; // zf@49
  signed int v27; // ecx@50
  int v28; // eax@52
  int v29; // eax@54
  signed int i; // ebx@57
  int v31; // edi@57
  int v32; // ebx@57
  int v33; // eax@57
  int v34; // ecx@58
  int v35; // eax@64
  int v36; // ebx@64
  int v37; // edi@64
  __int16 v38; // cx@66
  int v39; // edx@71
  int v40; // edi@71
  int v41; // eax@75
  int v42; // edi@75
  int v43; // ebx@76
  int v44; // ecx@77
  int v45; // edx@77
  __int16 v46; // dx@82
  int v47; // ecx@82
  signed int v48; // ebx@85
  int v49; // edi@85
  int v50; // edi@85
  unsigned __int8 v51; // zf@87
  unsigned __int8 v52; // sf@87
  unsigned __int8 v53; // sf@104
  unsigned __int8 v54; // of@104
  signed int v55; // eax@107
  unsigned int v56; // ebx@107
  unsigned int v57; // edi@107
  int v58; // eax@107
  signed int v59; // edi@107
  signed int v60; // ST10_4@107
  int v61; // eax@124
  int v62; // [sp+Ch] [bp-44h]@42
  int v63; // [sp+10h] [bp-40h]@42
  int v64; // [sp+14h] [bp-3Ch]@42
  char v65; // [sp+18h] [bp-38h]@64
  int v66; // [sp+1Ch] [bp-34h]@64
  int v67; // [sp+20h] [bp-30h]@2
  int v68; // [sp+24h] [bp-2Ch]@2
  bool v69; // [sp+28h] [bp-28h]@10
  int v70; // [sp+2Ch] [bp-24h]@10
  int v71; // [sp+30h] [bp-20h]@6
  int v72; // [sp+34h] [bp-1Ch]@10
  int v73; // [sp+38h] [bp-18h]@62
  int v74; // [sp+3Ch] [bp-14h]@10
  int v75; // [sp+40h] [bp-10h]@17
  int v76; // [sp+44h] [bp-Ch]@8
  int v77; // [sp+48h] [bp-8h]@1
  int v78; // [sp+4Ch] [bp-4h]@10

  v77 = 0;
  if ( (signed int)uNumActors > 0 )
  {
    while ( 1 )
    {
      v1 = (int)((char *)pActors + 836 * v77);
      v68 = *(_WORD *)(v1 + 142);
      v67 = *(_WORD *)(v1 + 144);
      v0 = *(_WORD *)(v1 + 176);
      if ( v0 == 11 || v0 == 19 || v0 == 17 || !*(_WORD *)(v1 + 140) )
        goto LABEL_121;
      v2 = *(_WORD *)(v1 + 96);
      v3 = 0;
      v71 = 0;
      if ( sub_438BDF(v2, 5) )
        v3 = 1;
      v4 = *(_BYTE *)(v1 + 58);
      *(_WORD *)(v1 + 158) = 0;
      v76 = v4;
      if ( !sub_40894B(v1) )
        v76 = 0;
      v72 = sub_4823F4(*(_WORD *)(v1 + 142), *(_WORD *)(v1 + 144));
      v6 = sub_46D49E(
             *(_WORD *)(v1 + 142),
             *(_WORD *)(v1 + 144),
             *(_WORD *)(v1 + 146),
             *(_WORD *)(v1 + 138),
             (int)&v78,
             (int)&v71,
             v3);
      v7 = *(_WORD *)(v1 + 146);
      v5 = v6;
      v70 = v6;
      v74 = 0;
      v69 = v71 == 0;
      if ( v7 > v6 + 1 )
        v74 = 1;
      if ( *(_WORD *)(v1 + 176) != 5 || !v78 || v74 )
        break;
      *(_WORD *)(v1 + 176) = 11;
LABEL_121:
      ++v77;
      if ( v77 >= (signed int)uNumActors )
        return;
    }
    if ( *(_WORD *)(v1 + 178) == 1 )
    {
      v10 = *(_WORD *)(v1 + 140);
      v8 = *(_DWORD *)(v1 + 328) == 0;
      v9 = *(_DWORD *)(v1 + 328) < 0;
      v75 = *(_WORD *)(v1 + 140);
      if ( !v9 )
      {
        if ( !(v9 | v8) || *(_DWORD *)(v1 + 324) > 0u )
        {
          v10 = (signed __int64)((double)v75 * memory_4D8410.d_0_5);
          v75 = (signed __int64)((double)v75 * memory_4D8410.d_0_5);
        }
      }
      v11 = *(_WORD *)(v1 + 176);
      if ( v11 == 7 || v11 == 6 )
      {
        v10 *= 2;
        v75 = v10;
      }
      if ( dword_ACD834 == 1 )
      {
        if ( dword_4F885C == 1 )
          v10 = (signed __int64)((double)v75 * flt_6BE3AC);
      }
      if ( v10 > 1000 )
        v10 = 1000;
      v12 = class59_SinCos(pClass59_global, *(_WORD *)(v1 + 154));
      v71 = v12;
      v13 = v12 * v10;
      v75 = v13 >> 16;
      *(_WORD *)(v1 + 148) = WORD1(v13);
      v71 = class59_SinCos(pClass59_global, *(_WORD *)(v1 + 154) - pClass59_global->uNumTableEntries);
      v75 = (unsigned __int64)(v71 * v10) >> 16;
      v14 = v76 == 0;
      *(_WORD *)(v1 + 150) = (unsigned int)(v71 * v10) >> 16;
      if ( !v14 )
      {
        v71 = class59_SinCos(pClass59_global, *(_WORD *)(v1 + 156) - pClass59_global->uNumTableEntries);
        v75 = (unsigned __int64)(v71 * v10) >> 16;
        *(_WORD *)(v1 + 152) = (unsigned int)(v71 * v10) >> 16;
      }
      v5 = v70;
    }
    else
    {
      v75 = *(_WORD *)(v1 + 148);
      v75 = (unsigned __int64)(55000i64 * v75) >> 16;
      v71 = 55000;
      *(_WORD *)(v1 + 148) = v75;
      v75 = *(_WORD *)(v1 + 150);
      v75 = (unsigned __int64)(v71 * v75) >> 16;
      v17 = v76 == 0;
      *(_WORD *)(v1 + 150) = v75;
      if ( !v17 )
      {
        v71 = 55000;
        v75 = *(_WORD *)(v1 + 152);
        v75 = (unsigned __int64)(55000i64 * v75) >> 16;
        *(_WORD *)(v1 + 152) = v75;
      }
    }
    if ( *(_WORD *)(v1 + 146) < v5 )
    {
      v15 = v76;
      *(_WORD *)(v1 + 146) = v5;
      *(_WORD *)(v1 + 152) = v15 != 0 ? 0x14 : 0;
    }
    v16 = 0;
    if ( !v74 || v76 )
    {
      if ( v72 )
      {
        if ( !v74 )
        {
          if ( v69 )
          {
            v18 = *(_WORD *)(v1 + 144);
            v19 = *(_WORD *)(v1 + 142);
            *(_WORD *)(v1 + 146) = v5;
            sub_46DCC8(v19, v18, (int)&v62);
            v20 = sub_46BDA8();
            v21 = v63;
            v22 = v64;
            v23 = v63 * *(_WORD *)(v1 + 150);
            *(_WORD *)(v1 + 152) += -8 * pClass24_global->int_00001C * v20;
            v75 = abs(v62 * *(_WORD *)(v1 + 148) + v22 * *(_WORD *)(v1 + 152) + v23) >> 16;
            v74 = v21;
            *(_WORD *)(v1 + 148) += (unsigned int)(v75 * v62) >> 16;
            v74 = (unsigned __int64)(v75 * v74) >> 16;
            v24 = v74;
            v74 = v22;
            *(_WORD *)(v1 + 150) += v24;
            v74 = (unsigned __int64)(v75 * v74) >> 16;
            *(_WORD *)(v1 + 152) += v74;
            v16 = 0;
          }
        }
      }
    }
    else
    {
      *(_WORD *)(v1 + 152) -= pClass24_global->int_00001C * sub_46BDA8();
    }
    if ( dword_AE30F4 != v16 )
    {
      if ( sub_40894B(v1) )
      {
        *(_WORD *)(v1 + 148) += rand() % 100 - 50;
        *(_WORD *)(v1 + 150) += rand() % 100 - 50;
        *(_WORD *)(v1 + 152) += rand() % 100 - 20;
        v25 = rand();
        *(_WORD *)(v1 + 176) = 8;
        *(_WORD *)(v1 + 154) += v25 % 32 - 16;
        sub_45976D(v1);
      }
    }
    if ( *(_WORD *)(v1 + 148) * (signed int)*(_WORD *)(v1 + 148)
       + *(_WORD *)(v1 + 150) * (signed int)*(_WORD *)(v1 + 150) < 400 )
    {
      if ( v72 == v16 )
      {
        *(_WORD *)(v1 + 150) = v16;
        *(_WORD *)(v1 + 148) = v16;
      }
    }
    v26 = *(_BYTE *)(v1 + 58) == 0;
    dword_721530 = 1;
    if ( v26 )
      v27 = 40;
    else
      v27 = *(_WORD *)(v1 + 136);
    v28 = *(_WORD *)(v1 + 138);
    dword_7215B4 = -1;
    dword_721538 = v27;
    dword_721534 = v27;
    dword_72153C = v28;
    dword_7215A0 = v16;
    v71 = v16;
    while ( 1 )
    {
      dword_721564 = *(_WORD *)(v1 + 142);
      dword_721558 = dword_721564;
      dword_721568 = *(_WORD *)(v1 + 144);
      dword_72155C = dword_721568;
      v29 = *(_WORD *)(v1 + 146);
      dword_721560 = v29 + v27 + 1;
      dword_72156C = v29 - v27 + dword_72153C - 1;
      if ( dword_72156C < dword_721560 )
        dword_72156C = v29 + v27 + 1;
      dword_72154C = *(_WORD *)(v1 + 148);
      dword_7215A4 = 0;
      dword_721550 = *(_WORD *)(v1 + 150);
      dword_721554 = *(_WORD *)(v1 + 152);
      if ( sub_47050A((int)&dword_721530, 0) )
        goto LABEL_107;
      sub_46E889((void *)1);
      v32 = WorldPosToGridCellZ(*(_WORD *)(v1 + 144));
      v33 = WorldPosToGridCellX(*(_WORD *)(v1 + 142));
      sub_46E26D(v33, v32);
      sub_46EF01(0);
      sub_46ED8A((void *)(8 * v77 | 3));
      v31 = 0;
      for ( i = 0; v31 < dword_4F75D8; ++v31 )
      {
        v34 = dword_4F7DB0[v31];
        if ( v34 != v77 )
        {
          if ( sub_46DF1A(v34, 40) )
            ++i;
        }
      }
      v73 = i > 1;
      if ( dword_7215AC < dword_72159C )
        v72 = (unsigned __int64)(dword_7215AC * dword_721590) >> 16;
      v36 = 0;
      v37 = dword_721578 - dword_721534 - 1;
      v35 = sub_46D49E(
              dword_721570,
              dword_721574,
              dword_721578 - dword_721534 - 1,
              *(_WORD *)(v1 + 138),
              (int)&v65,
              (int)&v66,
              0);
      if ( v78 )
      {
        if ( v37 < v35 + 60 )
        {
          v38 = *(_WORD *)(v1 + 176);
          if ( v38 == 5 || v38 == 4 || v38 == 11 || v38 == 19 )
          {
            if ( v66 )
              v61 = v35 + 30;
            else
              v61 = v70 + 60;
            sub_42F960(*(_WORD *)(v1 + 142), *(_WORD *)(v1 + 144), v61);
            *(_WORD *)(v1 + 176) = 11;
            return;
          }
        }
      }
      if ( dword_7215AC >= dword_72159C )
      {
        *(_WORD *)(v1 + 142) = dword_721570;
        *(_WORD *)(v1 + 144) = dword_721574;
        *(_WORD *)(v1 + 146) = dword_721578 - (_WORD)dword_721534 - 1;
LABEL_107:
        v71 = WorldPosToGridCellX(v68);
        v58 = WorldPosToGridCellZ(v67);
        v59 = v58 - 1;
        v60 = *(_WORD *)(v1 + 142);
        v73 = v58 - 1;
        v70 = WorldPosToGridCellX(v60);
        v72 = WorldPosToGridCellZ(*(_WORD *)(v1 + 144)) - 1;
        v57 = ((unsigned int)~class51_sub_47EDB3_ActuallyGetSomeOtherTileInfo(pClass51_global, v71, v59) >> 1) & 1;
        v56 = ((unsigned int)~class51_sub_47EDB3_ActuallyGetSomeOtherTileInfo(pClass51_global, v70, v72) >> 1) & 1;
        v55 = 0;
        if ( v71 == v70 )
        {
          if ( v73 == v72 )
          {
            if ( v57 )
              v55 = 1;
          }
        }
        if ( !v69 )
          v55 = 1;
        if ( !v55 )
        {
          if ( sub_438BDF(*(_WORD *)(v1 + 96), 5) )
          {
            v57 = v57 == 0;
            v56 = v56 == 0;
          }
          if ( !v76 )
          {
            if ( v57 )
            {
              if ( !v56 )
              {
                *(_WORD *)(v1 + 142) = v68;
                *(_WORD *)(v1 + 144) = v67;
                if ( sub_40894B(v1) )
                {
                  *(_WORD *)(v1 + 154) -= 32;
                  *(_DWORD *)(v1 + 184) &= v56;
                  *(_WORD *)(v1 + 160) = 128;
                  *(_WORD *)(v1 + 176) = 7;
                }
              }
            }
          }
        }
        goto LABEL_121;
      }
      v74 = (unsigned __int64)(dword_7215AC * dword_721588) >> 16;
      *(_WORD *)(v1 + 142) += (unsigned int)(dword_7215AC * dword_721588) >> 16;
      v74 = (unsigned __int64)(dword_7215AC * dword_72158C) >> 16;
      *(_WORD *)(v1 + 144) += (unsigned int)(dword_7215AC * dword_72158C) >> 16;
      v74 = (unsigned __int64)(dword_7215AC * dword_721590) >> 16;
      v39 = dword_7215A8;
      *(_WORD *)(v1 + 146) += (unsigned int)(dword_7215AC * dword_721590) >> 16;
      dword_7215A0 += dword_7215AC;
      v40 = v39 >> 3;
      switch ( v39 & 7 )
      {
        case 3:
          if ( dword_ACD834 != 1 )
            goto LABEL_97;
          if ( dword_4F885C != 2 && dword_4F885C != 3 )
          {
            v36 = 0;
LABEL_97:
            if ( *(_BYTE *)(v1 + 61) )
            {
              if ( v73 == v36 )
                goto LABEL_99;
LABEL_101:
              sub_403F58(v77, 4, v36, v36);
              break;
            }
            if ( v73 != v36 )
              goto LABEL_101;
            if ( byte_5FF195[836 * v40] )
            {
LABEL_99:
              sub_402968(v77, v39, v36, (char *)v36);
              break;
            }
LABEL_103:
            sub_404030(v77, v39, v36, v36);
            break;
          }
          break;
        case 4:
          if ( !Actor_sub_40104C(v1, 0) )
          {
            v39 = dword_7215A8;
            goto LABEL_103;
          }
          v51 = HIDWORD(qword_ACD8F4) == 0;
          v52 = HIDWORD(qword_ACD8F4) < 0;
          *(_WORD *)(v1 + 150) = 0;
          *(_WORD *)(v1 + 148) = 0;
          if ( !v52 )
          {
            if ( !(v52 | v51) || (_DWORD)qword_ACD8F4 > 0u )
              sub_458585((int)&qword_ACD8F4);
          }
          struct_576FE8.dword_000044 = 1;
          break;
        case 5:
          v48 = sub_452A9E(*(_WORD *)(v1 + 148) * *(_WORD *)(v1 + 148) + *(_WORD *)(v1 + 150) * *(_WORD *)(v1 + 150));
          v49 = sub_45281E(
                  pClass59_global,
                  *(_WORD *)(v1 + 142) - array_6836D0[v40].sPosX,
                  *(_WORD *)(v1 + 144) - array_6836D0[v40].sPosY);
          v73 = class59_SinCos(pClass59_global, v49);
          v72 = (unsigned __int64)(v73 * v48) >> 16;
          v50 = v49 - pClass59_global->uNumTableEntries;
          *(_WORD *)(v1 + 148) = (unsigned int)(v73 * v48) >> 16;
          v73 = class59_SinCos(pClass59_global, v50);
          v72 = (unsigned __int64)(v73 * v48) >> 16;
          *(_WORD *)(v1 + 150) = (unsigned int)(v73 * v48) >> 16;
          break;
        case 6:
          v41 = pClass51_global->pBModels + 188 * (v39 >> 9);
          v42 = *(_DWORD *)(v41 + 84) + 308 * (v40 & 0x3F);
          if ( !(*(_BYTE *)(v42 + 31) & 0x20) )
          {
            v43 = *(_BYTE *)(v42 + 303);
            if ( v43 == 3 )
            {
              v44 = *(_WORD *)(v1 + 150);
              v45 = *(_WORD *)(v1 + 148);
              *(_WORD *)(v1 + 152) = 0;
              *(_WORD *)(v1 + 146) = *(_WORD *)(*(_DWORD *)(v41 + 72) + 12 * *(_WORD *)(v42 + 32) + 8) + 1;
              if ( v45 * v45 + v44 * v44 < 400 )
              {
                *(_WORD *)(v1 + 150) = 0;
                *(_WORD *)(v1 + 148) = 0;
              }
            }
            else
            {
              v74 = abs(*(_DWORD *)(v42 + 4) * *(_WORD *)(v1 + 150) + *(_DWORD *)(v42 + 8) * *(_WORD *)(v1 + 152)
                                                                    + *(_DWORD *)v42 * *(_WORD *)(v1 + 148)) >> 16;
              if ( dword_721594 >> 3 > v74 )
                v74 = dword_721594 >> 3;
              v75 = *(_DWORD *)v42;
              v75 = (unsigned __int64)(v74 * v75) >> 16;
              v73 = *(_DWORD *)(v42 + 4);
              v73 = (unsigned __int64)(v74 * v73) >> 16;
              v72 = *(_DWORD *)(v42 + 8);
              v72 = (unsigned __int64)(v74 * v72) >> 16;
              *(_WORD *)(v1 + 148) += v75;
              *(_WORD *)(v1 + 150) += v73;
              *(_WORD *)(v1 + 152) += v72;
              if ( v43 != 4 )
              {
                v46 = *(_WORD *)(v1 + 146);
                v47 = dword_721534
                    - ((*(_DWORD *)(v42 + 12)
                      + *(_DWORD *)v42 * (signed int)*(_WORD *)(v1 + 142)
                      + *(_DWORD *)(v42 + 4) * (signed int)*(_WORD *)(v1 + 144)
                      + *(_DWORD *)(v42 + 8) * (signed int)*(_WORD *)(v1 + 146)) >> 16);
                if ( v47 > 0 )
                {
                  *(_WORD *)(v1 + 142) += v47 * *(_DWORD *)v42 >> 16;
                  *(_WORD *)(v1 + 144) += v47 * *(_DWORD *)(v42 + 4) >> 16;
                  *(_WORD *)(v1 + 146) = v46 + (v47 * *(_DWORD *)(v42 + 8) >> 16);
                }
                *(_WORD *)(v1 + 154) = sub_45281E(pClass59_global, *(_WORD *)(v1 + 148), *(_WORD *)(v1 + 150));
              }
            }
          }
          break;
      }
      v72 = *(_WORD *)(v1 + 148);
      v72 = (unsigned __int64)(58500i64 * v72) >> 16;
      v73 = 58500;
      *(_WORD *)(v1 + 148) = v72;
      v72 = *(_WORD *)(v1 + 150);
      v72 = (unsigned __int64)(v73 * v72) >> 16;
      v73 = 58500;
      *(_WORD *)(v1 + 150) = v72;
      v72 = *(_WORD *)(v1 + 152);
      v72 = (unsigned __int64)(v73 * v72) >> 16;
      ++v71;
      compile_error;//v54 = __SETO__(v71, 100);
      v53 = v71 - 100 < 0;
      *(_WORD *)(v1 + 152) = v72;
      if ( !(v53 ^ v54) )
        goto LABEL_107;
      v27 = dword_721534;
    }
  }
}

//----- (0047136C) --------------------------------------------------------
void __fastcall sub_47136C(int a1)
{
  int v1; // edi@1
  char *v2; // esi@1
  int v3; // ST08_4@1
  __int16 v4; // ax@5
  __int16 v5; // ax@7
  int v6; // eax@11
  int v7; // ecx@11
  int v8; // ebx@12
  int v9; // ecx@16
  __int16 v10; // di@18
  char v11; // al@19
  int v12; // eax@25
  int v13; // eax@31
  int v14; // ebx@34
  int v15; // ebx@46
  int v16; // edi@48
  int v17; // eax@50
  int v18; // eax@52
  int v19; // ecx@52
  int v20; // ecx@53
  __int16 v21; // ax@57
  int v22; // ecx@57
  int v23; // edi@62
  int v24; // edi@62
  unsigned __int8 v25; // sf@64
  unsigned __int8 v26; // of@64
  __int16 v27; // di@67
  char v28; // al@68
  const char *v29; // [sp-8h] [bp-98h]@19
  const char *v30; // [sp-8h] [bp-98h]@68
  unsigned int v31; // [sp-4h] [bp-94h]@19
  unsigned int v32; // [sp-4h] [bp-94h]@68
  int Dst; // [sp+Ch] [bp-84h]@18
  float v34; // [sp+10h] [bp-80h]@18
  float v35; // [sp+14h] [bp-7Ch]@18
  float v36; // [sp+18h] [bp-78h]@18
  float v37; // [sp+1Ch] [bp-74h]@18
  float v38; // [sp+20h] [bp-70h]@18
  float v39; // [sp+24h] [bp-6Ch]@18
  int v40; // [sp+28h] [bp-68h]@19
  int v41; // [sp+2Ch] [bp-64h]@22
  int v42; // [sp+30h] [bp-60h]@22
  float v43; // [sp+34h] [bp-5Ch]@19
  int v44; // [sp+74h] [bp-1Ch]@1
  int v45; // [sp+78h] [bp-18h]@1
  int v46; // [sp+7Ch] [bp-14h]@4
  int v47; // [sp+80h] [bp-10h]@33
  int v48; // [sp+84h] [bp-Ch]@28
  int v49; // [sp+88h] [bp-8h]@34
  int v50; // [sp+8Ch] [bp-4h]@4

  v44 = a1;
  v2 = (char *)array_665230 + 112 * a1;
  v1 = pObjectDescriptionList->pDescriptions + 56 * *((_WORD *)v2 + 1);
  v3 = *((_DWORD *)v2 + 1);
  v45 = pObjectDescriptionList->pDescriptions + 56 * *((_WORD *)v2 + 1);
  if ( abs(v3) > 32767
    || abs(*((_DWORD *)v2 + 2)) > 32767
    || abs(*((_DWORD *)v2 + 3)) > 20000
    || (v50 = sub_46CEC3(*((_DWORD *)v2 + 1), *((_DWORD *)v2 + 2), *((_DWORD *)v2 + 3), *((_WORD *)v2 + 14), (int)&v46),
        v50 <= -30000)
    && ((v4 = sub_49AC17((int)byte_6BE3C8, *((_DWORD *)v2 + 1), *((_DWORD *)v2 + 2), *((_DWORD *)v2 + 3)),
         *((_WORD *)v2 + 14) = v4,
         !v4)
     || (v50 = sub_46CEC3(*((_DWORD *)v2 + 1), *((_DWORD *)v2 + 2), *((_DWORD *)v2 + 3), v4, (int)&v46), v50 == -30000)) )
  {
    sub_42F933(v44);
    return;
  }
  v5 = *(_WORD *)(v1 + 38);
  if ( v5 & 0x20 )
  {
LABEL_24:
    v8 = 0;
LABEL_25:
    dword_721530 = v8;
    v46 = v8;
    dword_721534 = *(_WORD *)(v1 + 34);
    v12 = *(_WORD *)(v1 + 36);
    dword_7215B4 = -1;
    dword_72153C = v12;
    dword_721538 = v8;
    dword_7215A0 = v8;
    while ( 1 )
    {
      dword_721564 = *((_DWORD *)v2 + 1);
      dword_721558 = dword_721564;
      dword_721568 = *((_DWORD *)v2 + 2);
      dword_72155C = dword_721568;
      dword_72156C = dword_721534 + *((_DWORD *)v2 + 3) + 1;
      dword_721560 = dword_72156C;
      dword_72154C = *((_WORD *)v2 + 8);
      dword_721550 = *((_WORD *)v2 + 9);
      dword_721554 = *((_WORD *)v2 + 10);
      dword_7215A4 = *((_WORD *)v2 + 14);
      if ( sub_47050A((int)&dword_721530, v8) )
        return;
      v48 = v8;
      do
      {
        sub_46E44E(0);
        sub_46E0B2();
        if ( (v2[88] & 7) != 4 )
          sub_46EF01((void *)1);
        v13 = *((_DWORD *)v2 + 22);
        v50 = v8;
        if ( (v13 & 7) == 3 )
        {
          if ( (signed int)uNumActors > v8 )
          {
            v47 = (int)&unk_5FF1DE;
            do
            {
              v49 = word_5FF1B8[418 * (*((_DWORD *)v2 + 22) >> 3)] - 1;
              v14 = (signed __int64)((double)v49 * *(double *)&byte_4D8410[640]);
              v49 = *(_WORD *)(v47 - 38) - 1;
              if ( v14 != (unsigned int)(signed __int64)((double)v49 * *(double *)&byte_4D8410[640]) )
                sub_46DF1A(v50, *(_WORD *)(152 * *(_WORD *)v47 + monster_list[1] - 146));
              ++v50;
              v47 += 836;
            }
            while ( v50 < (signed int)uNumActors );
            v8 = 0;
          }
        }
        else
        {
          if ( (signed int)uNumActors > v8 )
          {
            v47 = (int)&unk_5FF1DE;
            do
            {
              sub_46DF1A(v50++, *(_WORD *)(152 * *(_WORD *)v47 + monster_list[1] - 146));
              v47 += 836;
            }
            while ( v50 < (signed int)uNumActors );
          }
        }
        if ( sub_46F04E() )
          break;
        ++v48;
      }
      while ( v48 < 100 );
      if ( dword_7215AC >= dword_72159C )
      {
        *((_DWORD *)v2 + 1) = dword_721570;
        *((_DWORD *)v2 + 2) = dword_721574;
        *((_DWORD *)v2 + 3) = dword_721578 - dword_721534 - 1;
        *((_WORD *)v2 + 14) = dword_7215A4;
        if ( !(*(_BYTE *)(v1 + 39) & 1) )
          return;
        memset(&Dst, v8, 0x68u);
        v27 = *(_WORD *)(v1 + 38);
        v34 = (double)*((signed int *)v2 + 1);
        v35 = (double)*((signed int *)v2 + 2);
        v36 = (double)*((signed int *)v2 + 3);
        v37 = 0.0;
        v38 = 0.0;
        v39 = 0.0;
        if ( v27 & 0x200 )
        {
          Dst = 1036;
          v40 = 16727070;
          v28 = rand();
          v32 = v8;
          v30 = "effpar01";
        }
        else
        {
          if ( v27 & 0x400 )
            goto LABEL_70;
          Dst = 1032;
          v40 = rand();
          v28 = rand();
          v32 = v8;
          v30 = "effpar03";
        }
        v41 = (unsigned __int8)(v28 & 0x80) + 128;
        v42 = class17_LoadTexture(pClass17_Bitmaps_LOD, v30, v32);
        goto LABEL_71;
      }
      v48 = (unsigned __int64)(dword_7215AC * dword_721588) >> 16;
      *((_DWORD *)v2 + 1) += (unsigned __int64)(dword_7215AC * dword_721588) >> 16;
      v48 = (unsigned __int64)(dword_7215AC * dword_72158C) >> 16;
      *((_DWORD *)v2 + 2) += (unsigned __int64)(dword_7215AC * dword_72158C) >> 16;
      v48 = (unsigned __int64)(dword_7215AC * dword_721590) >> 16;
      *((_DWORD *)v2 + 3) += (unsigned __int64)(dword_7215AC * dword_721590) >> 16;
      *((_WORD *)v2 + 14) = dword_7215A4;
      dword_7215A0 += dword_7215AC;
      if ( *(_BYTE *)(v1 + 38) & 0x40 && !sub_46BFFA(v44, dword_7215A8) )
        return;
      v15 = dword_7215A8 >> 3;
      if ( (dword_7215A8 & 7) == 5 )
      {
        v48 = sub_452A9E(*((_WORD *)v2 + 8) * *((_WORD *)v2 + 8) + *((_WORD *)v2 + 9) * *((_WORD *)v2 + 9));
        v23 = sub_45281E(
                pClass59_global,
                *((_DWORD *)v2 + 1) - array_6836D0[v15].sPosX,
                *((_DWORD *)v2 + 2) - array_6836D0[v15].sPosY);
        v50 = class59_SinCos(pClass59_global, v23);
        v49 = (unsigned __int64)(v50 * v48) >> 16;
        v24 = v23 - pClass59_global->uNumTableEntries;
        *((_WORD *)v2 + 8) = (unsigned int)(v50 * v48) >> 16;
        v50 = class59_SinCos(pClass59_global, v24);
        v49 = (unsigned __int64)(v50 * v48) >> 16;
        *((_WORD *)v2 + 9) = (unsigned int)(v50 * v48) >> 16;
      }
      else
      {
        if ( (dword_7215A8 & 7) != 6 )
          goto LABEL_64;
        dword_7215B4 = dword_7215A8 >> 3;
        v16 = dword_6BE644 + 96 * v15;
        if ( *(_BYTE *)(v16 + 92) != 3 )
        {
          v50 = abs(*(_DWORD *)(v16 + 16) * *((_WORD *)v2 + 8) + *(_DWORD *)(v16 + 24) * *((_WORD *)v2 + 10)
                                                               + *(_DWORD *)(v16 + 20) * *((_WORD *)v2 + 9)) >> 16;
          if ( dword_721594 >> 3 > v50 )
            v50 = dword_721594 >> 3;
          v48 = *(_DWORD *)(v16 + 16);
          v48 = (unsigned __int64)(v50 * v48) >> 16;
          v49 = *(_DWORD *)(v16 + 20);
          v49 = (unsigned __int64)(v50 * v49) >> 16;
          v47 = *(_DWORD *)(v16 + 24);
          v47 = (unsigned __int64)(v50 * v47) >> 16;
          *((_WORD *)v2 + 8) += 2 * v48;
          *((_WORD *)v2 + 9) += 2 * v49;
          if ( *(_DWORD *)(v16 + 24) <= 32000 )
          {
            v21 = 2 * v47;
          }
          else
          {
            v22 = v47;
            v48 = 32000;
            *((_WORD *)v2 + 10) += v47;
            v49 = (unsigned __int64)(v48 * v22) >> 16;
            v21 = (unsigned int)(v48 * v22) >> 16;
          }
          *((_WORD *)v2 + 10) += v21;
          goto LABEL_60;
        }
        if ( *(_BYTE *)(v45 + 38) & 0x80 )
        {
          v17 = -*((_WORD *)v2 + 10) >> 1;
          *((_WORD *)v2 + 10) = v17;
          if ( (_WORD)v17 < 10 )
            *((_WORD *)v2 + 10) = 0;
LABEL_60:
          if ( *(_BYTE *)(v16 + 47) & 0x10 )
            sub_44684A_LooksLikeEventProcessor(*(_WORD *)(dword_6BE64C + 36 * *(_WORD *)(v16 + 72) + 26), 0, 1);
          goto LABEL_63;
        }
        v18 = *((_WORD *)v2 + 9);
        v19 = *((_WORD *)v2 + 8);
        *((_WORD *)v2 + 10) = 0;
        if ( v19 * v19 + v18 * v18 >= 400 )
          goto LABEL_60;
        v20 = dword_6BE63C;
        *((_WORD *)v2 + 10) = 0;
        *((_WORD *)v2 + 9) = 0;
        *((_WORD *)v2 + 8) = 0;
        *((_DWORD *)v2 + 3) = *(_WORD *)(v20 + 6 * **(_WORD **)(v16 + 48) + 4) + 1;
      }
LABEL_63:
      v1 = v45;
LABEL_64:
      v49 = *((_WORD *)v2 + 8);
      v49 = (unsigned __int64)(58500i64 * v49) >> 16;
      v48 = 58500;
      *((_WORD *)v2 + 8) = v49;
      v49 = *((_WORD *)v2 + 9);
      v49 = (unsigned __int64)(v48 * v49) >> 16;
      v48 = 58500;
      *((_WORD *)v2 + 9) = v49;
      v49 = *((_WORD *)v2 + 10);
      v49 = (unsigned __int64)(v48 * v49) >> 16;
      ++v46;
      compile_error;//v26 = __SETO__(v46, 100);
      v25 = v46 - 100 < 0;
      *((_WORD *)v2 + 10) = v49;
      if ( !(v25 ^ v26) )
        return;
      v8 = 0;
    }
  }
  if ( v50 <= *((_DWORD *)v2 + 3) - 3 )
  {
    *((_WORD *)v2 + 10) -= pClass24_global->int_00001C * sub_46BDA8();
    goto LABEL_24;
  }
  if ( !(v5 & 0x40) || sub_46BFFA(v44, 0) )
  {
    v7 = dword_6BE644;
    *((_DWORD *)v2 + 3) = v50 + 1;
    v6 = v7 + 96 * v46;
    if ( *(_BYTE *)(v6 + 92) == 3 )
    {
      v8 = 0;
      *((_WORD *)v2 + 10) = 0;
    }
    else
    {
      if ( *(_DWORD *)(v6 + 24) < 45000 )
        *((_WORD *)v2 + 10) -= pClass24_global->int_00001C * sub_46BDA8();
      v8 = 0;
    }
    v50 = *((_WORD *)v2 + 8);
    v50 = (unsigned __int64)(58500i64 * v50) >> 16;
    v46 = 58500;
    *((_WORD *)v2 + 8) = v50;
    v50 = *((_WORD *)v2 + 9);
    v50 = (unsigned __int64)(v46 * v50) >> 16;
    v46 = 58500;
    *((_WORD *)v2 + 9) = v50;
    v50 = *((_WORD *)v2 + 10);
    v50 = (unsigned __int64)(v46 * v50) >> 16;
    v9 = *((_WORD *)v2 + 8);
    *((_WORD *)v2 + 10) = v50;
    if ( v9 * v9 + *((_WORD *)v2 + 9) * (signed int)*((_WORD *)v2 + 9) < 400 )
    {
      *((_WORD *)v2 + 10) = v8;
      *((_WORD *)v2 + 9) = v8;
      *((_WORD *)v2 + 8) = v8;
      if ( !(*(_BYTE *)(v1 + 39) & 1) )
        return;
      memset(&Dst, v8, 0x68u);
      v10 = *(_WORD *)(v1 + 38);
      v34 = (double)*((signed int *)v2 + 1);
      v35 = (double)*((signed int *)v2 + 2);
      v36 = (double)*((signed int *)v2 + 3);
      v37 = 0.0;
      v38 = 0.0;
      v39 = 0.0;
      if ( v10 & 0x200 )
      {
        Dst = 1036;
        v40 = 16727070;
        v43 = 1.0;
        v11 = rand();
        v31 = v8;
        v29 = "effpar01";
      }
      else
      {
        if ( v10 & 0x400 )
        {
LABEL_70:
          Dst = 512;
          v40 = rand();
          v41 = 64;
          v42 = v8;
LABEL_71:
          v43 = 1.0;
          goto LABEL_72;
        }
        Dst = 1032;
        v40 = rand();
        v43 = 1.0;
        v11 = rand();
        v31 = v8;
        v29 = "effpar03";
      }
      v41 = (unsigned __int8)(v11 & 0x80) + 128;
      v42 = class17_LoadTexture(pClass17_Bitmaps_LOD, v29, v31);
LABEL_72:
      sub_48AB23(pGame->class02_obj, (int)&Dst);
      return;
    }
    goto LABEL_25;
  }
}

//----- (00471C03) --------------------------------------------------------
void __fastcall sub_471C03(int a1)
{
  int v1; // eax@1
  int v2; // ecx@1
  int v3; // ebx@1
  int v4; // edi@1
  char *v5; // esi@1
  signed int v6; // edx@1
  signed int v7; // ecx@1
  int v8; // ST04_4@1
  int v9; // eax@4
  __int16 v10; // ax@7
  signed int v11; // edx@11
  signed int v12; // ecx@11
  signed int v13; // edx@14
  signed int v14; // edx@16
  int v15; // eax@24
  int v16; // eax@25
  signed int v17; // ST10_4@25
  int v18; // eax@25
  signed int v19; // eax@28
  int v20; // edi@31
  int v21; // eax@41
  int v22; // ecx@43
  __int16 v23; // bx@45
  char v24; // al@46
  int i; // edi@50
  int v26; // eax@52
  int v27; // edi@52
  int v28; // eax@55
  __int16 v29; // cx@55
  int v30; // edi@59
  int v31; // ecx@61
  int v32; // edi@61
  int v33; // eax@62
  int v34; // ecx@62
  int v35; // eax@63
  __int16 v36; // ax@67
  int v37; // ecx@67
  int v38; // eax@72
  int v39; // eax@72
  unsigned __int64 v40; // qax@72
  int v41; // eax@72
  unsigned __int8 v42; // sf@74
  unsigned __int8 v43; // of@74
  int v44; // eax@77
  __int16 v45; // bx@81
  int v46; // eax@85
  const char *v47; // [sp-8h] [bp-B0h]@83
  unsigned int v48; // [sp-4h] [bp-ACh]@46
  char v49; // [sp+Ch] [bp-9Ch]@52
  int v50; // [sp+10h] [bp-98h]@52
  int v51; // [sp+14h] [bp-94h]@11
  int v52; // [sp+18h] [bp-90h]@11
  int v53; // [sp+1Ch] [bp-8Ch]@11
  int Dst; // [sp+20h] [bp-88h]@45
  float v55; // [sp+24h] [bp-84h]@45
  float v56; // [sp+28h] [bp-80h]@45
  float v57; // [sp+2Ch] [bp-7Ch]@45
  float v58; // [sp+30h] [bp-78h]@45
  float v59; // [sp+34h] [bp-74h]@45
  float v60; // [sp+38h] [bp-70h]@45
  int v61; // [sp+3Ch] [bp-6Ch]@46
  int v62; // [sp+40h] [bp-68h]@48
  int v63; // [sp+44h] [bp-64h]@48
  float v64; // [sp+48h] [bp-60h]@89
  int v65; // [sp+88h] [bp-20h]@1
  int v66; // [sp+8Ch] [bp-1Ch]@1
  int v67; // [sp+90h] [bp-18h]@1
  int v68; // [sp+94h] [bp-14h]@11
  int v69; // [sp+98h] [bp-10h]@1
  int v70; // [sp+9Ch] [bp-Ch]@1
  int v71; // [sp+A0h] [bp-8h]@1
  int v72; // [sp+A4h] [bp-4h]@11

  v65 = a1;
  v5 = (char *)array_665230 + 112 * a1;
  v70 = 0;
  v3 = pObjectDescriptionList->pDescriptions + 56 * *((_WORD *)v5 + 1);
  v69 = sub_4823F4(*((_DWORD *)v5 + 1), *((_DWORD *)v5 + 2));
  v6 = *((_DWORD *)v5 + 2);
  v7 = *((_DWORD *)v5 + 1);
  v8 = *(_WORD *)(v3 + 36);
  v67 = 0;
  v1 = sub_46D49E(v7, v6, *((_DWORD *)v5 + 3), v8, (int)&v71, (int)&v67, 0);
  v2 = v1;
  v66 = v1;
  v4 = v1 + 1;
  if ( *((_DWORD *)v5 + 3) <= v1 + 1 )
  {
    if ( v71 )
    {
      v9 = v1 + 60;
      if ( v67 )
        v9 = v2 + 30;
      sub_42F960(*((_DWORD *)v5 + 1), *((_DWORD *)v5 + 2), v9);
      sub_42F933(v65);
      v2 = v66;
    }
  }
  else
  {
    v70 = 1;
  }
  v10 = *(_WORD *)(v3 + 38);
  if ( !(v10 & 0x20) )
  {
    if ( v70 )
    {
      *((_WORD *)v5 + 10) -= pClass24_global->int_00001C * sub_46BDA8();
      goto LABEL_13;
    }
    if ( v69 )
    {
      v11 = *((_DWORD *)v5 + 2);
      v12 = *((_DWORD *)v5 + 1);
      *((_DWORD *)v5 + 3) = v4;
      sub_46DCC8(v12, v11, (int)&v51);
      *((_WORD *)v5 + 10) -= pClass24_global->int_00001C * sub_46BDA8();
      v68 = abs(v52 * *((_WORD *)v5 + 9) + v53 * *((_WORD *)v5 + 10) + v51 * *((_WORD *)v5 + 8)) >> 16;
      v72 = (unsigned __int64)(v68 * v51) >> 16;
      *((_WORD *)v5 + 8) += (unsigned int)(v68 * v51) >> 16;
      v72 = (unsigned __int64)(v68 * v52) >> 16;
      *((_WORD *)v5 + 9) += (unsigned int)(v68 * v52) >> 16;
      v72 = (unsigned __int64)(v68 * v53) >> 16;
      *((_WORD *)v5 + 10) += (unsigned int)(v68 * v53) >> 16;
LABEL_12:
      v2 = v66;
      goto LABEL_13;
    }
    if ( v10 & 0x40 )
    {
      if ( *((_DWORD *)v5 + 3) < v2 )
        *((_DWORD *)v5 + 3) = v4;
      if ( !sub_46BFFA(v65, 0) )
        return;
    }
    *((_DWORD *)v5 + 3) = v4;
    if ( !(*(_BYTE *)(v3 + 38) & 0x80) || (v21 = -*((_WORD *)v5 + 10) >> 1, *((_WORD *)v5 + 10) = v21, (_WORD)v21 < 10) )
      *((_WORD *)v5 + 10) = 0;
    v72 = *((_WORD *)v5 + 8);
    v72 = (unsigned __int64)(58500i64 * v72) >> 16;
    v67 = 58500;
    *((_WORD *)v5 + 8) = v72;
    v72 = *((_WORD *)v5 + 9);
    v72 = (unsigned __int64)(v67 * v72) >> 16;
    v67 = 58500;
    *((_WORD *)v5 + 9) = v72;
    v72 = *((_WORD *)v5 + 10);
    v72 = (unsigned __int64)(v67 * v72) >> 16;
    v22 = *((_WORD *)v5 + 8);
    *((_WORD *)v5 + 10) = v72;
    if ( *((_WORD *)v5 + 9) * (signed int)*((_WORD *)v5 + 9) + v22 * v22 >= 400 )
      goto LABEL_12;
    *((_WORD *)v5 + 9) = 0;
    *((_WORD *)v5 + 8) = 0;
    if ( !(*(_BYTE *)(v3 + 39) & 1) )
      return;
    memset(&Dst, 0, 0x68u);
    v23 = *(_WORD *)(v3 + 38);
    v55 = (double)*((signed int *)v5 + 1);
    v56 = (double)*((signed int *)v5 + 2);
    v57 = (double)*((signed int *)v5 + 3);
    v58 = 0.0;
    v59 = 0.0;
    v60 = 0.0;
    if ( HIBYTE(v23) & 2 )
    {
      Dst = 1036;
      v61 = 16727070;
      v24 = rand();
      v48 = 0;
LABEL_83:
      v47 = "effpar01";
    }
    else
    {
      if ( HIBYTE(v23) & 4 )
      {
        Dst = 512;
        v61 = rand();
        v62 = 64;
        v63 = 0;
LABEL_89:
        v64 = 1.0;
        sub_48AB23(pGame->class02_obj, (int)&Dst);
        return;
      }
      Dst = 1032;
      v61 = rand();
      v24 = rand();
      v48 = 0;
LABEL_87:
      v47 = "effpar03";
    }
    v62 = (unsigned __int8)(v24 & 0x80) + 128;
    v63 = class17_LoadTexture(pClass17_Bitmaps_LOD, v47, v48);
    goto LABEL_89;
  }
LABEL_13:
  if ( *((_DWORD *)v5 + 3) > v2 )
  {
    v13 = *((_DWORD *)v5 + 1);
    if ( v13 >= -32768 )
    {
      if ( v13 <= 32768 )
      {
        v14 = *((_DWORD *)v5 + 2);
        if ( v14 >= -32768 )
        {
          if ( v14 <= 32768 && *((_DWORD *)v5 + 3) <= 13000 )
            goto LABEL_92;
        }
      }
    }
  }
  if ( !(*(_BYTE *)(v3 + 38) & 0x40) )
    goto LABEL_92;
  if ( *((_DWORD *)v5 + 3) < v2 )
    *((_DWORD *)v5 + 3) = v4;
  if ( sub_46BFFA(v65, 0) )
  {
LABEL_92:
    dword_721530 = 0;
    v67 = 0;
    dword_721534 = *(_WORD *)(v3 + 34);
    dword_72153C = *(_WORD *)(v3 + 36);
    dword_721538 = 0;
    dword_7215A0 = 0;
    while ( 1 )
    {
      dword_721564 = *((_DWORD *)v5 + 1);
      dword_721558 = dword_721564;
      v15 = *((_DWORD *)v5 + 2);
      dword_7215A4 = 0;
      dword_721568 = v15;
      dword_72155C = v15;
      dword_72156C = *((_DWORD *)v5 + 3) + dword_721534 + 1;
      dword_721560 = dword_72156C;
      dword_72154C = *((_WORD *)v5 + 8);
      dword_721550 = *((_WORD *)v5 + 9);
      dword_721554 = *((_WORD *)v5 + 10);
      if ( sub_47050A((int)&dword_721530, 0) )
        return;
      sub_46E889(0);
      v16 = WorldPosToGridCellZ(*((_DWORD *)v5 + 2));
      v17 = *((_DWORD *)v5 + 1);
      v70 = v16;
      v18 = WorldPosToGridCellX(v17);
      sub_46E26D(v18, v70);
      if ( (v5[88] & 7) != 4 )
        sub_46EF01(0);
      if ( (v5[88] & 7) == 3 )
      {
        v19 = *((_DWORD *)v5 + 22) >> 3;
        if ( v19 >= 0 )
        {
          if ( v19 < (signed int)(uNumActors - 1) )
          {
            v68 = 0;
            if ( (signed int)uNumActors > 0 )
            {
              v72 = (int)pActors;
              v20 = (int)((char *)pActors + 836 * v19);
              do
              {
                if ( Actor_sub_40104C(v20, v72) )
                  sub_46DF1A(v68, 0);
                ++v68;
                v72 += 836;
              }
              while ( v68 < (signed int)uNumActors );
            }
          }
        }
      }
      else
      {
        for ( i = 0; i < (signed int)uNumActors; ++i )
          sub_46DF1A(i, 0);
      }
      v27 = dword_721578 - dword_721534 - 1;
      v26 = sub_46D49E(
              dword_721570,
              dword_721574,
              dword_721578 - dword_721534 - 1,
              *(_WORD *)(v3 + 36),
              (int)&v49,
              (int)&v50,
              0);
      if ( v71 && v27 < v26 + 60 )
      {
        if ( v50 )
          v44 = v26 + 30;
        else
          v44 = v66 + 60;
        sub_42F960(*((_DWORD *)v5 + 1), *((_DWORD *)v5 + 2), v44);
        sub_42F933(v65);
        return;
      }
      if ( dword_7215AC >= dword_72159C )
      {
        *((_DWORD *)v5 + 1) = dword_721570;
        *((_DWORD *)v5 + 2) = dword_721574;
        *((_DWORD *)v5 + 3) = dword_721578 - dword_721534 - 1;
        *((_WORD *)v5 + 14) = dword_7215A4;
        if ( !(*(_BYTE *)(v3 + 39) & 1) )
          return;
        memset(&Dst, 0, 0x68u);
        v45 = *(_WORD *)(v3 + 38);
        v55 = (double)*((signed int *)v5 + 1);
        v56 = (double)*((signed int *)v5 + 2);
        v57 = (double)*((signed int *)v5 + 3);
        v58 = 0.0;
        v59 = 0.0;
        v60 = 0.0;
        if ( HIBYTE(v45) & 2 )
        {
          Dst = 1036;
          v61 = 16727070;
          v24 = rand();
          v48 = 0;
          goto LABEL_83;
        }
        if ( HIBYTE(v45) & 4 )
        {
          Dst = 512;
          v46 = rand();
          v63 = 0;
          v61 = v46;
          v62 = 64;
          goto LABEL_89;
        }
        Dst = 1032;
        v61 = rand();
        v24 = rand();
        v48 = 0;
        goto LABEL_87;
      }
      v72 = (unsigned __int64)(dword_7215AC * dword_721588) >> 16;
      *((_DWORD *)v5 + 1) += (unsigned __int64)(dword_7215AC * dword_721588) >> 16;
      v72 = (unsigned __int64)(dword_7215AC * dword_72158C) >> 16;
      *((_DWORD *)v5 + 2) += (unsigned __int64)(dword_7215AC * dword_72158C) >> 16;
      v72 = (unsigned __int64)(dword_7215AC * dword_721590) >> 16;
      v29 = dword_7215A4;
      *((_DWORD *)v5 + 3) += (unsigned __int64)(dword_7215AC * dword_721590) >> 16;
      v28 = *((_DWORD *)v5 + 3);
      *((_WORD *)v5 + 14) = v29;
      dword_7215A0 += dword_7215AC;
      if ( *(_BYTE *)(v3 + 38) & 0x40 )
      {
        if ( v28 < v66 )
          *((_DWORD *)v5 + 3) = v66 + 1;
        if ( !sub_46BFFA(v65, dword_7215A8) )
          return;
      }
      v30 = dword_7215A8 >> 3;
      if ( (dword_7215A8 & 7) == 5 )
        break;
      if ( (dword_7215A8 & 7) == 6 )
      {
        v31 = pClass51_global->pBModels + 188 * (dword_7215A8 >> 9);
        v32 = *(_DWORD *)(v31 + 84) + 308 * (v30 & 0x3F);
        if ( *(_BYTE *)(v32 + 303) != 3 )
        {
          v68 = abs(*(_DWORD *)(v32 + 8) * *((_WORD *)v5 + 10) + *(_DWORD *)(v32 + 4) * *((_WORD *)v5 + 9)
                                                               + *(_DWORD *)v32 * *((_WORD *)v5 + 8)) >> 16;
          if ( dword_721594 >> 3 > v68 )
            v68 = dword_721594 >> 3;
          v69 = *(_DWORD *)v32;
          v69 = (unsigned __int64)(v68 * v69) >> 16;
          v70 = *(_DWORD *)(v32 + 4);
          v70 = (unsigned __int64)(v68 * v70) >> 16;
          v72 = *(_DWORD *)(v32 + 8);
          v72 = (unsigned __int64)(v68 * v72) >> 16;
          *((_WORD *)v5 + 8) += 2 * v69;
          *((_WORD *)v5 + 9) += 2 * v70;
          if ( *(_DWORD *)(v32 + 8) <= 32000 )
          {
            v36 = 2 * v72;
          }
          else
          {
            v37 = v72;
            v69 = 32000;
            *((_WORD *)v5 + 10) += v72;
            v70 = (unsigned __int64)(v69 * v37) >> 16;
            v36 = (unsigned int)(v69 * v37) >> 16;
          }
          *((_WORD *)v5 + 10) += v36;
LABEL_70:
          if ( *(_BYTE *)(v32 + 31) & 0x10 )
            sub_44684A_LooksLikeEventProcessor(*(_WORD *)(v32 + 292), 0, 1);
          goto LABEL_74;
        }
        v33 = *(_DWORD *)(*(_DWORD *)(v31 + 72) + 12 * *(_WORD *)(v32 + 32) + 8);
        v34 = *((_WORD *)v5 + 8);
        *((_DWORD *)v5 + 3) = v33 + 1;
        if ( *((_WORD *)v5 + 9) * (signed int)*((_WORD *)v5 + 9) + v34 * v34 >= 400 )
          goto LABEL_70;
        LOWORD(v35) = 0;
        *((_WORD *)v5 + 10) = 0;
        *((_WORD *)v5 + 8) = 0;
        goto LABEL_73;
      }
LABEL_74:
      v70 = *((_WORD *)v5 + 8);
      v70 = (unsigned __int64)(58500i64 * v70) >> 16;
      v69 = 58500;
      *((_WORD *)v5 + 8) = v70;
      v70 = *((_WORD *)v5 + 9);
      v70 = (unsigned __int64)(v69 * v70) >> 16;
      v69 = 58500;
      *((_WORD *)v5 + 9) = v70;
      v70 = *((_WORD *)v5 + 10);
      v70 = (unsigned __int64)(v69 * v70) >> 16;
      ++v67;
      compile_error;//v43 = __SETO__(v67, 100);
      v42 = v67 - 100 < 0;
      *((_WORD *)v5 + 10) = v70;
      if ( !(v42 ^ v43) )
        return;
    }
    v69 = sub_452A9E(*((_WORD *)v5 + 9) * *((_WORD *)v5 + 9) + *((_WORD *)v5 + 8) * *((_WORD *)v5 + 8));
    v38 = sub_45281E(
            pClass59_global,
            *((_DWORD *)v5 + 1) - array_6836D0[v30].sPosX,
            *((_DWORD *)v5 + 2) - array_6836D0[v30].sPosY);
    v68 = v38;
    v39 = class59_SinCos(pClass59_global, v38);
    v72 = v39;
    v40 = v39 * v69;
    v70 = v40 >> 16;
    *((_WORD *)v5 + 8) = WORD1(v40);
    v41 = class59_SinCos(pClass59_global, v68 - pClass59_global->uNumTableEntries);
    v72 = v41;
    v35 = (unsigned __int64)(v41 * v69) >> 16;
    v70 = v35;
LABEL_73:
    *((_WORD *)v5 + 9) = v35;
    goto LABEL_74;
  }
}

//----- (0047272C) --------------------------------------------------------
int __fastcall sub_47272C(int a1, signed int a2, int a3, int *a4, int a5)
{
  int result; // eax@1
  signed int v6; // ebx@1
  int v7; // [sp+10h] [bp-8h]@1
  signed int v8; // [sp+14h] [bp-4h]@1

  v6 = a1 - 2;
  v7 = a1;
  v8 = a2;
  *a4 = sub_49AC17((int)byte_6BE3C8, a1 - 2, a2, a3 + 40);
  result = sub_46ED1B(v6, v8, a3 + 40, a4, a5);
  if ( result == -30000 || !*a4 )
  {
    *a4 = sub_49AC17((int)byte_6BE3C8, v7 + 2, v8, a3 + 40);
    result = sub_46ED1B(v7 + 2, v8, a3 + 40, a4, a5);
    if ( result == -30000 || !*a4 )
    {
      *a4 = sub_49AC17((int)byte_6BE3C8, v7, v8 - 2, a3 + 40);
      result = sub_46ED1B(v7, v8 - 2, a3 + 40, a4, a5);
      if ( result == -30000 || !*a4 )
      {
        *a4 = sub_49AC17((int)byte_6BE3C8, v7, v8 + 2, a3 + 40);
        result = sub_46ED1B(v7, v8 + 2, a3 + 40, a4, a5);
        if ( result == -30000 || !*a4 )
        {
          *a4 = sub_49AC17((int)byte_6BE3C8, v7, v8, a3 + 140);
          result = sub_46ED1B(v7, v8, a3 + 140, a4, a5);
        }
      }
    }
  }
  return result;
}

//----- (00472866) --------------------------------------------------------
void __cdecl sub_472866()
{
  int v0; // ebx@1
  int v1; // edi@1
  int v2; // esi@1
  int v3; // esi@1
  float v4; // ST40_4@8
  void **v5; // esi@15
  int v6; // eax@18
  int *v7; // esi@24
  signed __int64 v8; // qax@27
  int v9; // eax@27
  double v10; // st7@27
  int v11; // edx@41
  int v12; // eax@49
  double v13; // st7@50
  int v14; // eax@51
  signed __int64 v15; // qax@53
  double v16; // st7@54
  double v17; // st7@62
  int v18; // ST40_4@62
  int v19; // ST40_4@62
  double v20; // st7@65
  int v21; // ST40_4@65
  int v22; // ST40_4@65
  double v23; // st7@66
  int v24; // ST40_4@66
  int v25; // ST40_4@66
  double v26; // st7@67
  int v27; // ST40_4@67
  int v28; // ST40_4@67
  double v29; // st7@69
  int v30; // ST3C_4@69
  int v31; // ST3C_4@69
  double v32; // st7@71
  int v33; // ST3C_4@71
  int v34; // ST3C_4@71
  int v35; // eax@74
  int v36; // ecx@88
  int v37; // eax@96
  int v38; // esi@96
  int v39; // eax@106
  signed int v40; // ecx@106
  int *v41; // esi@113
  int v42; // eax@120
  signed int v43; // ecx@123
  char v44; // al@126
  int v45; // esi@126
  int v46; // eax@133
  int v47; // ecx@133
  char v48; // zf@133
  int v49; // ST40_4@136
  int v50; // eax@140
  int v51; // ST40_4@140
  int v52; // eax@140
  signed int v53; // edi@146
  int v54; // ebx@146
  int v55; // ST30_4@146
  int v56; // ecx@162
  int v57; // [sp-20h] [bp-80h]@163
  signed int v58; // [sp-1Ch] [bp-7Ch]@161
  int v59; // [sp-18h] [bp-78h]@161
  signed int v60; // [sp-14h] [bp-74h]@161
  int v61; // [sp-10h] [bp-70h]@161
  int v62; // [sp-Ch] [bp-6Ch]@161
  int v63; // [sp-8h] [bp-68h]@75
  int v64; // [sp-8h] [bp-68h]@161
  int v65; // [sp-4h] [bp-64h]@75
  int v66; // [sp-4h] [bp-64h]@161
  double v67; // [sp+Ch] [bp-54h]@8
  int v68; // [sp+10h] [bp-50h]@45
  int v69; // [sp+10h] [bp-50h]@140
  int v70; // [sp+14h] [bp-4Ch]@1
  signed int v71; // [sp+18h] [bp-48h]@1
  signed int v72; // [sp+1Ch] [bp-44h]@1
  signed int v73; // [sp+20h] [bp-40h]@100
  int v74; // [sp+20h] [bp-40h]@140
  signed int v75; // [sp+24h] [bp-3Ch]@15
  bool v76; // [sp+24h] [bp-3Ch]@33
  int v77; // [sp+28h] [bp-38h]@1
  int v78; // [sp+2Ch] [bp-34h]@1
  int v79; // [sp+30h] [bp-30h]@1
  int i; // [sp+34h] [bp-2Ch]@1
  int v81; // [sp+38h] [bp-28h]@47
  int v82; // [sp+3Ch] [bp-24h]@47
  int v83; // [sp+40h] [bp-20h]@47
  int v84; // [sp+44h] [bp-1Ch]@1
  int v85; // [sp+48h] [bp-18h]@1
  int v86; // [sp+4Ch] [bp-14h]@1
  int v87; // [sp+50h] [bp-10h]@1
  float v88; // [sp+54h] [bp-Ch]@62
  int v89; // [sp+58h] [bp-8h]@1
  int v90; // [sp+5Ch] [bp-4h]@47

  v3 = pParty_global->sPartyPosZ;
  v89 = pParty_global->dword_0006E8;
  v0 = 0;
  v85 = pParty_global->sPartyPosY;
  v70 = 0;
  v1 = 0;
  v86 = pParty_global->sPartyPosX;
  v87 = pParty_global->sPartyPosZ;
  v77 = sub_49AC17((int)byte_6BE3C8, pParty_global->sPartyPosX, pParty_global->sPartyPosY, pParty_global->sPartyPosZ);
  v72 = 0;
  v78 = 0;
  v71 = 0;
  v84 = 0;
  v2 = v3 + 40;
  i = sub_46ED1B(v86, v85, v2, &v77, (int)&v79);
  if (pParty_global->dword_000704)
  {
    pParty_global->dword_000704 = 0;
    if ( qword_ACD8B4 > 0 )
      *((_BYTE *)&unk_5E4D52 + 20 * (unsigned __int16)word_ACD8C0) |= 1u;
  }
  if ( i == -30000 )
  {
    i = sub_47272C(v86, v85, v2, &v77, (int)&v79);
    if ( i == -30000 )
    {
      pParty_global->sPartyPosX = dword_721654;
      pParty_global->sPartyPosY = dword_721658;
      pParty_global->sPartyPosZ = dword_72165C;
      pParty_global->dword_000700 = dword_72165C;
      return;
    }
  }
  dword_721654 = pParty_global->sPartyPosX;
  dword_721658 = pParty_global->sPartyPosY;
  dword_72165C = pParty_global->sPartyPosZ;
  if ( dword_ACD834 != 1 )
  {
    v4 = (double)(GetTickCount() / 0x1F4);
    v67 = v4 + 6.755399441055744e15;
    if ( dword_720CDC != LODWORD(v67) )
    {
      dword_4F8584[3 * dword_4F8580[0]] = pParty_global->sPartyPosX;
      dword_4F8588[3 * dword_4F8580[0]] = pParty_global->sPartyPosY;
      dword_4F8580[3 * dword_4F8580[0]++ + 3] = pParty_global->sPartyPosZ;
      if ( dword_4F8580[0] > 60 )
        dword_4F8580[0] = 1;
    }
    dword_720CDC = LODWORD(v67);
  }
  if ( dword_ACD898 < 0 || dword_ACD898 <= 0 && unk_ACD894 <= 0u )
  {
    v75 = 0;
    v5 = (void **)pPlayers;
    while ( !sub_48D709(*v5, 536, 16) )
    {
      ++v5;
      if ( (signed int)v5 > (signed int)&dword_A750D4 )
      {
        v6 = pParty_global->dword_000700;
        goto LABEL_20;
      }
    }
  }
  v6 = i;
  v75 = 1;
  pParty_global->dword_000700 = i;
LABEL_20:
  if ( v6 - v87 > 512 )
  {
    if ( !v75 )
    {
      if ( v87 <= i + 1 )
      {
        if ( BYTE1(pParty_global->dword_007778) & 1 )
        {
          BYTE1(pParty_global->dword_007778) &= 0xFEu;
        }
        else
        {
          v7 = pPlayers;
          do
          {
            if ( !sub_48D6D0((void *)*v7, 72) )
            {
              if ( !sub_48D709((void *)*v7, 529, 8) )
              {
                v8 = (signed __int64)((double)Player_GetMaxHealth(*v7) * *(double *)&byte_4D8410[112]);
                sub_48DC1E(*v7, (pParty_global->dword_000700 - v87) * (_DWORD)v8 / 256, 4);
                v9 = Player_GetActualEndurance(*v7);
                v10 = (double)(20 - sub_48EA1B(v9)) * flt_6BE3A4 * *(double *)&byte_4D8410[40];
                sub_48E96A(*v7, (signed __int64)v10);
              }
            }
            ++v7;
          }
          while ( (signed int)v7 <= (signed int)&dword_A750D4 );
        }
      }
    }
  }
  if ( v87 > i + 1 )
    v84 = 1;
  v76 = v87 - i <= 32;
  if ( v87 - i <= 32 )
    pParty_global->dword_000700 = v87;
  if ( dword_6BE374 )
  {
    if (pParty_global->dword_0006F8 > 0)
      pParty_global->dword_0006F8 -= pClass24_global->int_00001C;
  }
  if ( v87 > i + 1 )
  {
LABEL_43:
    if ( v84 )
      goto LABEL_45;
    goto LABEL_44;
  }
  v87 = i + 1;
  pParty_global->dword_000700 = i + 1;
  if ( v84 )
    goto LABEL_45;
  if (pParty_global->dword_0006F4 != v79)
  {
    v11 = dword_6BE644 + 96 * v79;
    if ( *(_BYTE *)(v11 + 47) & 4 )
    {
      v70 = *(_WORD *)(dword_6BE64C + 36 * *(_WORD *)(v11 + 72) + 26);
      goto LABEL_43;
    }
  }
LABEL_44:
  pParty_global->dword_0006F4 = v79;
LABEL_45:
  v68 = 96 * v79;
  if ( *(_BYTE *)(96 * v79 + dword_6BE644 + 44) & 0x10 )
    v71 = 1;
  v81 = pParty_global->uWalkSpeed;
  v90 = pParty_global->sRotationY;
  v83 = pParty_global->sRotationX;
  v82 = ((unsigned __int64)(pClass24_global->dword_000020) * pParty_global->dword_000020 * pClass59_global->dword_001860 / 180) >> 16;
LABEL_87:
  while ( dword_7215D8 )
  {
    switch ( sub_4760D5((int)&dword_7215D8) )
    {
      case 1:
        v12 = dword_6BE38C;
        if ( dword_6BE38C )
          goto LABEL_58;
        v13 = (double)v82 * flt_6BE14C;
        goto LABEL_51;
      case 2:
        LODWORD(v15) = dword_6BE38C;
        if ( dword_6BE38C )
          goto LABEL_56;
        v16 = (double)v82 * flt_6BE14C;
        goto LABEL_55;
      case 18:
        v12 = dword_6BE38C;
        if ( dword_6BE38C )
        {
LABEL_58:
          v14 = v90 + v12;
        }
        else
        {
          v13 = (flt_6BE14C + flt_6BE14C) * (double)v82;
LABEL_51:
          v14 = v90 + (signed __int64)v13;
        }
        v90 = pClass59_global->dword_00186C & v14;
        goto LABEL_87;
      case 19:
        LODWORD(v15) = dword_6BE38C;
        if ( !dword_6BE38C )
        {
          v16 = (flt_6BE14C + flt_6BE14C) * (double)v82;
LABEL_55:
          v15 = (signed __int64)v16;
        }
LABEL_56:
        v90 = pClass59_global->dword_00186C & (v90 - v15);
        goto LABEL_87;
      case 3:
        v17 = (double)v81;
        v18 = class59_SinCos(pClass59_global, v90 - pClass59_global->uNumTableEntries);
        v88 = v17;
        v78 = (unsigned __int64)(v18 * ((signed int)(signed __int64)(v17 * flt_6BE144) >> 1)) >> 16;
        v1 -= v78;
        v19 = class59_SinCos(pClass59_global, v90);
        v78 = (unsigned __int64)(v19 * ((signed int)(signed __int64)(v88 * flt_6BE144) >> 1)) >> 16;
        goto LABEL_63;
      case 4:
        v20 = (double)v81;
        v21 = class59_SinCos(pClass59_global, v90 - pClass59_global->uNumTableEntries);
        v88 = v20;
        v78 = (unsigned __int64)(v21 * ((signed int)(signed __int64)(v20 * flt_6BE144) >> 1)) >> 16;
        v1 += v78;
        v22 = class59_SinCos(pClass59_global, v90);
        v78 = (unsigned __int64)(v22 * ((signed int)(signed __int64)(v88 * flt_6BE144) >> 1)) >> 16;
        goto LABEL_68;
      case 5:
        v23 = (double)v81;
        v24 = class59_SinCos(pClass59_global, v90);
        v88 = v23;
        v78 = (unsigned __int64)(v24 * (signed int)(signed __int64)(v23 * flt_6BE144)) >> 16;
        v1 += v78;
        v25 = class59_SinCos(pClass59_global, v90 - pClass59_global->uNumTableEntries);
        v78 = (unsigned __int64)(v25 * (signed int)(signed __int64)(v88 * flt_6BE144)) >> 16;
LABEL_63:
        v0 += v78;
        goto LABEL_64;
      case 6:
        v26 = (double)v81;
        v27 = class59_SinCos(pClass59_global, v90);
        v88 = v26;
        v78 = (unsigned __int64)(v27 * (signed int)(signed __int64)(v26 * flt_6BE148)) >> 16;
        v1 -= v78;
        v28 = class59_SinCos(pClass59_global, v90 - pClass59_global->uNumTableEntries);
        v78 = (unsigned __int64)(v28 * (signed int)(signed __int64)(v88 * flt_6BE148)) >> 16;
LABEL_68:
        v0 -= v78;
LABEL_64:
        v78 = 1;
        goto LABEL_87;
      case 16:
        v29 = (double)v81;
        v30 = class59_SinCos(pClass59_global, v90);
        v88 = v29;
        v1 += (unsigned __int64)(v30 * (signed int)(2 * (signed __int64)(v29 * flt_6BE144))) >> 16;
        v31 = class59_SinCos(pClass59_global, v90 - pClass59_global->uNumTableEntries);
        v0 += (unsigned __int64)(v31 * (signed int)(2 * (signed __int64)(v88 * flt_6BE144))) >> 16;
        goto LABEL_70;
      case 17:
        v32 = (double)v81;
        v33 = class59_SinCos(pClass59_global, v90);
        v88 = v32;
        v1 -= (unsigned __int64)(v33 * (signed int)(signed __int64)(v32 * flt_6BE148)) >> 16;
        v34 = class59_SinCos(pClass59_global, v90 - pClass59_global->uNumTableEntries);
        v0 -= (unsigned __int64)(v34 * (signed int)(signed __int64)(v88 * flt_6BE148)) >> 16;
LABEL_70:
        v72 = 1;
        goto LABEL_87;
      case 7:
        v83 += (signed __int64)(flt_6BE150 * 25.0);
        if ( v83 > 128 )
          v83 = 128;
        v35 = uMaybeSelectedCharacter;
        if ( !uMaybeSelectedCharacter )
          goto LABEL_87;
        v65 = 0;
        v63 = 63;
        goto LABEL_76;
      case 8:
        v83 += (signed __int64)(flt_6BE150 * -25.0);
        if ( v83 < -128 )
          v83 = -128;
        v35 = uMaybeSelectedCharacter;
        if ( uMaybeSelectedCharacter )
        {
          v65 = 0;
          v63 = 64;
LABEL_76:
          sub_4948B1(*(&ptr_A750C4 + v35), v63, v65);
        }
        break;
      case 9:
        v83 = 0;
        break;
      case 12:
        if ( !v84 || v87 <= i + 6 && v89 <= 0 )
        {
         if (pParty_global->dword_000024)
          {
            v84 = 1;
            v89 = (signed __int64)((double)(pParty_global->dword_000024 << 6) * 1.5 + (double)v89);
          }
        }
        break;
      default:
        goto LABEL_87;
    }
  }
  v36 = 0;
  pParty_global->sRotationY = v90;
  pParty_global->sRotationX = v83;
  if ( v84 )
  {
    v89 += -2 * pClass24_global->int_00001C * sub_46BDA8();
  }
  else
  {
    if ( *(_DWORD *)(v68 + dword_6BE644 + 24) < 32768 )
    {
      v89 -= pClass24_global->int_00001C * sub_46BDA8();
      goto LABEL_92;
    }
    if ( BYTE1(pParty_global->dword_007778) & 1 )
      goto LABEL_92;
    v89 = 0;
  }
  if ( v84 != v36 && v89 <= v36 )
  {
    if ( v89 < -500 )
    {
      if (!pParty_global->dword_000704)
      {
        v41 = pPlayers;
        do
        {
          if ( !sub_48D6D0((void *)*v41, 72) )
          {
            if ( !sub_48D709((void *)*v41, 529, 8) )
              sub_494A25(*v41, 46, 0);
          }
          ++v41;
        }
        while ( (signed int)v41 <= (signed int)&dword_A750D4 );
      }
    }
    goto LABEL_93;
  }
LABEL_92:
  pParty_global->dword_000700 = v87;
LABEL_93:
  if ( v1 * v1 + v0 * v0 < 400 )
  {
    v0 = 0;
    v1 = 0;
  }
  dword_7215B4 = -1;
  dword_7215A0 = 0;
  dword_721534 = pParty_global->dword_000014;
  dword_721538 = pParty_global->dword_000014 / 2;
  v83 = 0;
  dword_721530 = 1;
  dword_72153C = pParty_global->uPartyHeight - 32;
  while ( 1 )
  {
    v38 = v87;
    dword_721564 = v86;
    dword_721558 = v86;
    dword_72154C = v1;
    dword_721568 = v85;
    dword_72155C = v85;
    dword_721550 = v0;
    dword_721560 = dword_721534 + v87 + 1;
    dword_72156C = dword_72153C + v87 + 1;
    dword_721554 = v89;
    dword_7215A4 = v77;
    v37 = 0;
    if ( dword_ACD834 == 1 )
    {
      if ( dword_4F885C == 3 )
        v37 = 13312;
    }
    if ( sub_47050A((int)&dword_721530, v37) )
      break;
    v73 = 0;
    do
    {
      sub_46E44E((void *)1);
      sub_46E0B2();
      for ( i = 0; i < (signed int)uNumActors; ++i )
        sub_46DF1A(i, 0);
      if ( sub_46F04E() )
        break;
      ++v73;
    }
    while ( v73 < 100 );
    if ( dword_7215AC >= dword_72159C )
    {
      v40 = dword_721570;
      v77 = dword_721574;
      v39 = dword_721578 - dword_721534 - 1;
    }
    else
    {
      v40 = ((unsigned __int64)(dword_7215AC * dword_721588) >> 16) + v86;
      v77 = v85 + ((unsigned __int64)(dword_7215AC * dword_72158C) >> 16);
      v39 = v38 + ((unsigned __int64)(dword_7215AC * dword_721590) >> 16);
    }
    v42 = sub_46ED1B(v40, v77, v39 + 40, &dword_7215A4, (int)&v79);
    if ( v42 == -30000 || v42 - v38 > 128 )
      return;
    if ( dword_7215AC >= dword_72159C )
    {
      v86 = dword_721570;
      v85 = dword_721574;
      v38 = dword_721578 - dword_721534 - 1;
      break;
    }
    v86 += (unsigned __int64)(dword_7215AC * dword_721588) >> 16;
    v85 += (unsigned __int64)(dword_7215AC * dword_72158C) >> 16;
    v43 = dword_7215A8;
    v77 = dword_7215A4;
    dword_7215A0 += dword_7215AC;
    v87 = ((unsigned __int64)(dword_7215AC * dword_721590) >> 16) + v38;
    if ( (dword_7215A8 & 7) == 3 )
    {
      if ( HIDWORD(qword_ACD8F4) >= 0 )
      {
        if ( HIDWORD(qword_ACD8F4) > 0 || (_DWORD)qword_ACD8F4 )
          sub_458585((int)&qword_ACD8F4);
      }
      struct_576FE8.dword_000044 = 1;
      goto LABEL_152;
    }
    if ( (dword_7215A8 & 7) == 5 )
    {
      v53 = sub_452A9E(v1 * v1 + v0 * v0);
      i = v53;
      v54 = sub_45281E(
              pClass59_global,
              v86 - array_6836D0[(dword_7215A8 >> 3)].sPosX,
              v85 - array_6836D0[(dword_7215A8 >> 3)].sPosY);
      v1 = (unsigned __int64)(class59_SinCos(pClass59_global, v54) * v53) >> 16;
      v55 = class59_SinCos(pClass59_global, v54 - pClass59_global->uNumTableEntries);
      v0 = (unsigned __int64)(v55 * i) >> 16;
    }
    else
    {
      if ( (dword_7215A8 & 7) == 6 )
      {
        v45 = dword_6BE644 + 96 * (dword_7215A8 >> 3);
        v44 = *(_BYTE *)(v45 + 92);
        if ( v44 == 3 )
        {
          if ( v89 < 0 )
            v89 = 0;
          v87 = *(_WORD *)(dword_6BE63C + 6 * **(_WORD **)(v45 + 48) + 4) + 1;
          if ( pParty_global->dword_000700 - v87 < 512 )
            pParty_global->dword_000700 = v87;
          if ( v1 * v1 + v0 * v0 < 400 )
          {
            v0 = 0;
            v1 = 0;
          }
          goto LABEL_143;
        }
        v47 = v89 * *(_DWORD *)(v45 + 24);
        v48 = v44 == 4;
        v46 = *(_DWORD *)(v45 + 16);
        if ( !v48 )
        {
          i = abs(v0 * *(_DWORD *)(v45 + 20) + v47 + v1 * v46) >> 16;
          if ( dword_721594 >> 3 > i )
            i = dword_721594 >> 3;
          v51 = (unsigned __int64)(i * *(_DWORD *)(v45 + 16)) >> 16;
          v81 = *(_DWORD *)(v45 + 20);
          v81 = (unsigned __int64)(i * v81) >> 16;
          v82 = *(_DWORD *)(v45 + 24);
          v82 = (unsigned __int64)(i * v82) >> 16;
          v1 += v51;
          v89 += v82;
          v74 = *(_DWORD *)(v45 + 24);
          v52 = *(_DWORD *)(v45 + 20);
          v69 = *(_DWORD *)(v45 + 16);
          i = v52;
          v0 += v81;
          v50 = dword_721534 - ((*(_DWORD *)(v45 + 28) + v87 * v74 + v85 * v52 + v86 * v69) >> 16);
          if ( v50 > 0 )
          {
            v86 += v50 * v69 >> 16;
            v85 += v50 * i >> 16;
            v87 += v50 * v74 >> 16;
          }
LABEL_142:
          v43 = dword_7215A8;
LABEL_143:
          if (pParty_global->dword_0006F4 != v43 >> 3)
          {
            if (*(_BYTE *)(v45 + 47) & 4)
              v70 = *(_WORD *)(dword_6BE64C + 36 * *(_WORD *)(v45 + 72) + 26);
          }
          goto LABEL_152;
        }
        i = abs(v0 * *(_DWORD *)(v45 + 20) + v47 + v1 * v46) >> 16;
        if ( dword_721594 >> 3 > i )
          i = dword_721594 >> 3;
        v49 = (unsigned __int64)(i * *(_DWORD *)(v45 + 16)) >> 16;
        v81 = *(_DWORD *)(v45 + 20);
        v81 = (unsigned __int64)(i * v81) >> 16;
        v82 = *(_DWORD *)(v45 + 24);
        v82 = (unsigned __int64)(i * v82) >> 16;
        v1 += v49;
        v0 += v81;
        v89 += v82;
        if ( v1 * v1 + v0 * v0 >= 400 )
          goto LABEL_142;
        v1 = 0;
        v0 = 0;
        v89 = 0;
      }
    }
LABEL_152:
    v1 = (unsigned __int64)(58500i64 * v1) >> 16;
    v0 = (unsigned __int64)(58500i64 * v0) >> 16;
    ++v83;
    v89 = (unsigned __int64)(58500i64 * v89) >> 16;
    if ( v83 >= 100 )
    {
      v38 = v87;
      break;
    }
  }
  if ( dword_6BE374 && pParty_global->dword_0006F8 <= 0)
  {
    if ( sub_452A9E((pParty_global->sPartyPosX - v86) * (pParty_global->sPartyPosX - v86) + (pParty_global->sPartyPosY - v85) * (pParty_global->sPartyPosY - v85)
                                                                + (pParty_global->sPartyPosZ - v38) * (pParty_global->sPartyPosZ - v38)) <= 16 )
      goto LABEL_188;
    if ( v72 && (!v84 || v76) )
    {
      v66 = 0;
      v64 = 0;
      v62 = 0;
      v61 = 0;
      v60 = -1;
      v59 = 1;
      v58 = 804;
      if ( !v71 )
      {
        v56 = pAudioPlayer;
        if ( *(_BYTE *)(96 * v79 + dword_6BE644 + 46) & 0x20 )
          v57 = 50;
        else
          v57 = 64;
        goto LABEL_175;
      }
      v57 = 63;
LABEL_174:
      v56 = pAudioPlayer;
      goto LABEL_175;
    }
    if ( v78 && (!v84 || v76) )
    {
      v66 = 0;
      v64 = 0;
      v62 = 0;
      v61 = 0;
      v60 = -1;
      v59 = 1;
      v58 = 804;
      if ( v71 )
      {
        v57 = 102;
        goto LABEL_174;
      }
      v56 = pAudioPlayer;
      if ( *(_BYTE *)(96 * v79 + dword_6BE644 + 46) & 0x20 )
        v57 = 89;
      else
        v57 = 103;
LABEL_175:
      AudioPlayer_sub_4AA306(v56, v57, v58, v59, v60, v61, v62, v64, v66);
    }
    else
    {
LABEL_188:
      sub_4AA258(pAudioPlayer, 804);
      pParty_global->dword_0006F8 = 64;
    }
  }
  if ( !v84 || v76 )
    pParty_global->dword_007778 &= 0xFFFFFFF7u;
  else
    pParty_global->dword_007778 |= 8u;
  BYTE1(pParty_global->dword_007778) &= 0xFDu;
  pParty_global->sPartyPosX = v86;
  pParty_global->sPartyPosZ = v38;
  pParty_global->sPartyPosY = v85;
  pParty_global->dword_0006E8 = v89;
  if ( !v84 )
  {
    if ( *(_BYTE *)(96 * v79 + dword_6BE644 + 47) & 0x40 )
      BYTE1(pParty_global->dword_007778) |= 2;
  }
  if ( v70 )
    sub_44684A_LooksLikeEventProcessor(v70, 0, 1);
}

//----- (0047531C) --------------------------------------------------------
signed int __fastcall sub_47531C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // ebx@1
  int v11; // edi@3
  int v12; // esi@3
  int v13; // ST1C_4@3
  int v14; // edi@4
  signed __int64 v15; // qtt@6
  int v16; // esi@7
  int v18; // [sp+Ch] [bp-Ch]@1
  int v19; // [sp+10h] [bp-8h]@1
  int v20; // [sp+30h] [bp+18h]@7
  int v21; // [sp+38h] [bp+20h]@3
  int v22; // [sp+38h] [bp+20h]@3
  int v23; // [sp+3Ch] [bp+24h]@3
  signed int v24; // [sp+3Ch] [bp+24h]@4
  int v25; // [sp+3Ch] [bp+24h]@5

  v10 = a9;
  v18 = a2;
  v19 = a1;
  if ( a10 && *(_BYTE *)(a9 + 47) & 0x20 )
    return 0;
  v13 = (unsigned __int64)(a6 * *(_DWORD *)(a9 + 16)) >> 16;
  v23 = (unsigned __int64)(a7 * *(_DWORD *)(a9 + 20)) >> 16;
  v22 = (unsigned __int64)(a8 * *(_DWORD *)(a9 + 24)) >> 16;
  v11 = v13 + v22 + v23;
  v21 = v13 + v22 + v23;
  v12 = (a1 << 16)
      - a3 * *(_DWORD *)(v10 + 16)
      - a4 * *(_DWORD *)(v10 + 20)
      - a5 * *(_DWORD *)(v10 + 24)
      - *(_DWORD *)(v10 + 28);
  if ( abs((a1 << 16) - a3 * *(_DWORD *)(v10 + 16) - a4 * *(_DWORD *)(v10 + 20) - a5 * *(_DWORD *)(v10 + 24) - *(_DWORD *)(v10 + 28)) >= a1 << 16 )
  {
    v25 = abs(v12) >> 14;
    if ( v25 > abs(v11) )
      return 0;
    LODWORD(v15) = v12 << 16;
    HIDWORD(v15) = v12 >> 16;
    v14 = v19;
    v24 = v15 / v21;
  }
  else
  {
    v24 = 0;
    v14 = abs(v12) >> 16;
  }
  v16 = a4 + ((signed int)((unsigned __int64)(v24 * a7) >> 16) >> 16);
  LOWORD(v20) = a3 + ((signed int)((unsigned __int64)(v24 * a6) >> 16) >> 16) - (v14 * *(_DWORD *)(v10 + 16) >> 16);
  HIWORD(v20) = v16 - (v14 * *(_DWORD *)(v10 + 20) >> 16);
  if ( !sub_475665(
          v10,
          v20,
          a5 + ((signed int)((unsigned __int64)(v24 * a8) >> 16) >> 16) - (v14 * *(_DWORD *)(v10 + 24) >> 16)) )
    return 0;
  *(_DWORD *)v18 = v24 >> 16;
  if ( v24 >> 16 < 0 )
    *(_DWORD *)v18 = 0;
  return 1;
}

//----- (004754BF) --------------------------------------------------------
signed int __fastcall sub_4754BF(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  int v11; // ebx@1
  int v12; // edi@3
  int v13; // esi@3
  int v14; // ST1C_4@3
  int v15; // edi@4
  signed __int64 v16; // qtt@6
  int v17; // esi@7
  int v19; // [sp+Ch] [bp-Ch]@1
  int v20; // [sp+10h] [bp-8h]@1
  int v21; // [sp+30h] [bp+18h]@7
  int v22; // [sp+38h] [bp+20h]@3
  int v23; // [sp+38h] [bp+20h]@3
  int v24; // [sp+40h] [bp+28h]@3
  signed int v25; // [sp+40h] [bp+28h]@4
  int v26; // [sp+40h] [bp+28h]@5

  v11 = a9;
  v19 = a2;
  v20 = a1;
  if ( a11 && *(_BYTE *)(a9 + 47) & 0x20 )
    return 0;
  v14 = (unsigned __int64)(a6 * *(_DWORD *)(a9 + 16)) >> 16;
  v24 = (unsigned __int64)(a7 * *(_DWORD *)(a9 + 20)) >> 16;
  v23 = (unsigned __int64)(a8 * *(_DWORD *)(a9 + 24)) >> 16;
  v12 = v14 + v23 + v24;
  v22 = v14 + v23 + v24;
  v13 = (a1 << 16)
      - a3 * *(_DWORD *)(v11 + 16)
      - a4 * *(_DWORD *)(v11 + 20)
      - a5 * *(_DWORD *)(v11 + 24)
      - *(_DWORD *)(v11 + 28);
  if ( abs((a1 << 16) - a3 * *(_DWORD *)(v11 + 16) - a4 * *(_DWORD *)(v11 + 20) - a5 * *(_DWORD *)(v11 + 24) - *(_DWORD *)(v11 + 28)) >= a1 << 16 )
  {
    v26 = abs(v13) >> 14;
    if ( v26 > abs(v12) )
      return 0;
    LODWORD(v16) = v13 << 16;
    HIDWORD(v16) = v13 >> 16;
    v15 = v20;
    v25 = v16 / v22;
  }
  else
  {
    v25 = 0;
    v15 = abs(v13) >> 16;
  }
  v17 = a4 + ((signed int)((unsigned __int64)(v25 * a7) >> 16) >> 16);
  LOWORD(v21) = a3 + ((signed int)((unsigned __int64)(v25 * a6) >> 16) >> 16) - (v15 * *(_DWORD *)(v11 + 16) >> 16);
  HIWORD(v21) = v17 - (v15 * *(_DWORD *)(v11 + 20) >> 16);
  if ( !sub_4759C9(
          v11,
          a10,
          v21,
          a5 + ((signed int)((unsigned __int64)(v25 * a8) >> 16) >> 16) - (v15 * *(_DWORD *)(v11 + 24) >> 16)) )
    return 0;
  *(_DWORD *)v19 = v25 >> 16;
  if ( v25 >> 16 < 0 )
    *(_DWORD *)v19 = 0;
  return 1;
}

//----- (00475665) --------------------------------------------------------
signed int __thiscall sub_475665(int this, int a2, __int16 a3)
{
  int v3; // eax@1
  int v4; // edx@3
  int v5; // eax@4
  int v6; // esi@4
  signed int v7; // eax@7
  int v8; // edx@8
  int v9; // eax@9
  int v10; // esi@9
  signed int v11; // eax@11
  int v12; // edx@12
  int v13; // eax@13
  int v14; // esi@13
  bool v15; // edi@14
  int v16; // esi@14
  signed int v17; // edx@16
  int v18; // ecx@16
  int v19; // eax@17
  signed int v20; // ebx@18
  int v21; // edi@20
  signed int v22; // ST14_4@22
  signed __int64 v23; // qtt@22
  signed int result; // eax@25
  int v25; // [sp+14h] [bp-10h]@14
  int v26; // [sp+1Ch] [bp-8h]@2
  signed int v27; // [sp+20h] [bp-4h]@2
  signed int v28; // [sp+30h] [bp+Ch]@2
  signed int v29; // [sp+30h] [bp+Ch]@7
  signed int v30; // [sp+30h] [bp+Ch]@11
  signed int v31; // [sp+30h] [bp+Ch]@14

  v3 = *(_DWORD *)(this + 44);
  if ( BYTE1(v3) & 1 )
  {
    v28 = 0;
    v26 = (signed __int16)a2;
    v27 = SHIWORD(a2);
    if ( *(_BYTE *)(this + 93) )
    {
      v4 = dword_6BE63C;
      do
      {
        v5 = 2 * v28;
        v6 = 4 * v28;
        word_720C10[2 * v28] = *(_WORD *)(2 * v28 + *(_DWORD *)(this + 52))
                             + *(_WORD *)(v4 + 6 * *(_WORD *)(2 * v28 + *(_DWORD *)(this + 48)));
        word_720B40[2 * v28] = *(_WORD *)(*(_DWORD *)(this + 56) + v5)
                             + *(_WORD *)(v4 + 6 * *(_WORD *)(v5 + *(_DWORD *)(this + 48)) + 2);
        word_720C12[2 * v28++] = *(_WORD *)(v5 + *(_DWORD *)(this + 52) + 2)
                               + *(_WORD *)(v4 + 6 * *(_WORD *)(v5 + *(_DWORD *)(this + 48) + 2));
        *(__int16 *)((char *)word_720B42 + v6) = *(_WORD *)(v5 + *(_DWORD *)(this + 56) + 2)
                                               + *(_WORD *)(v4 + 6 * *(_WORD *)(v5 + *(_DWORD *)(this + 48) + 2) + 2);
      }
      while ( v28 < *(_BYTE *)(this + 93) );
    }
  }
  else
  {
    if ( BYTE1(v3) & 2 )
    {
      v26 = (signed __int16)a2;
      v7 = a3;
      v29 = 0;
      v27 = v7;
      if ( *(_BYTE *)(this + 93) )
      {
        v8 = dword_6BE63C;
        do
        {
          v9 = 2 * v29;
          v10 = 4 * v29;
          word_720C10[2 * v29] = *(_WORD *)(2 * v29 + *(_DWORD *)(this + 52))
                               + *(_WORD *)(v8 + 6 * *(_WORD *)(2 * v29 + *(_DWORD *)(this + 48)));
          word_720B40[2 * v29] = *(_WORD *)(v9 + *(_DWORD *)(this + 60))
                               + *(_WORD *)(v8 + 6 * *(_WORD *)(v9 + *(_DWORD *)(this + 48)) + 4);
          word_720C12[2 * v29++] = *(_WORD *)(*(_DWORD *)(this + 52) + v9 + 2)
                                 + *(_WORD *)(v8 + 6 * *(_WORD *)(*(_DWORD *)(this + 48) + v9 + 2));
          *(__int16 *)((char *)word_720B42 + v10) = *(_WORD *)(*(_DWORD *)(this + 60) + v9 + 2)
                                                  + *(_WORD *)(v8 + 6 * *(_WORD *)(*(_DWORD *)(this + 48) + v9 + 2) + 4);
        }
        while ( v29 < *(_BYTE *)(this + 93) );
      }
    }
    else
    {
      v26 = SHIWORD(a2);
      v11 = a3;
      v30 = 0;
      v27 = v11;
      if ( *(_BYTE *)(this + 93) )
      {
        v12 = dword_6BE63C;
        do
        {
          v13 = 2 * v30;
          v14 = 4 * v30;
          word_720C10[2 * v30] = *(_WORD *)(*(_DWORD *)(this + 56) + 2 * v30)
                               + *(_WORD *)(v12 + 6 * *(_WORD *)(2 * v30 + *(_DWORD *)(this + 48)) + 2);
          word_720B40[2 * v30] = *(_WORD *)(v13 + *(_DWORD *)(this + 60))
                               + *(_WORD *)(v12 + 6 * *(_WORD *)(v13 + *(_DWORD *)(this + 48)) + 4);
          word_720C12[2 * v30++] = *(_WORD *)(*(_DWORD *)(this + 56) + v13 + 2)
                                 + *(_WORD *)(v12 + 6 * *(_WORD *)(v13 + *(_DWORD *)(this + 48) + 2) + 2);
          *(__int16 *)((char *)word_720B42 + v14) = *(_WORD *)(v13 + *(_DWORD *)(this + 60) + 2)
                                                  + *(_WORD *)(v12 + 6 * *(_WORD *)(v13 + *(_DWORD *)(this + 48) + 2) + 4);
        }
        while ( v30 < *(_BYTE *)(this + 93) );
      }
    }
  }
  v16 = 2 * *(_BYTE *)(this + 93);
  v31 = 0;
  word_720C10[2 * *(_BYTE *)(this + 93)] = word_720C10[0];
  word_720B40[v16] = word_720B40[0];
  v25 = 0;
  v15 = word_720B40[0] >= v27;
  if ( v16 <= 0 )
    goto LABEL_29;
  do
  {
    if ( v31 >= 2 )
      break;
    v18 = 2 * v25;
    v17 = word_720B42[v25];
    if ( v15 ^ v17 >= v27 )
    {
      v19 = *(__int16 *)((char *)word_720C12 + v18);
      if ( v19 >= v26 )
        v20 = 0;
      else
        v20 = 2;
      v21 = v20 | *(__int16 *)((char *)word_720C10 + v18) < v26;
      if ( v21 != 3 )
      {
        if ( !v21
          || (v22 = v19 - *(__int16 *)((char *)word_720C10 + v18),
              LODWORD(v23) = v22 << 16,
              HIDWORD(v23) = v22 >> 16,
              *(__int16 *)((char *)word_720C10 + v18)
            + ((signed int)(((unsigned __int64)(v23
                                              / (v17 - *(__int16 *)((char *)word_720B40 + v18))
                                              * ((v27 - (signed int)*(__int16 *)((char *)word_720B40 + v18)) << 16)) >> 16)
                          + 32768) >> 16) >= v26) )
          ++v31;
      }
    }
    ++v25;
    v15 = v17 >= v27;
  }
  while ( v25 < v16 );
  result = 1;
  if ( v31 != 1 )
LABEL_29:
    result = 0;
  return result;
}

//----- (004759C9) --------------------------------------------------------
signed int __fastcall sub_4759C9(int a1, int a2, int a3, __int16 a4)
{
  int v4; // eax@1
  int v5; // edx@4
  __int16 v6; // si@4
  int v7; // edx@9
  __int16 v8; // si@9
  int v9; // edx@13
  __int16 v10; // si@13
  bool v11; // edi@14
  int v12; // esi@14
  signed int v13; // edx@16
  int v14; // ecx@16
  int v15; // eax@17
  signed int v16; // ebx@18
  int v17; // edi@20
  signed int v18; // ST14_4@22
  signed __int64 v19; // qtt@22
  signed int result; // eax@25
  int v21; // [sp+14h] [bp-10h]@14
  signed int v22; // [sp+18h] [bp-Ch]@1
  int v23; // [sp+1Ch] [bp-8h]@2
  signed int v24; // [sp+20h] [bp-4h]@2
  int v25; // [sp+30h] [bp+Ch]@3
  int v26; // [sp+30h] [bp+Ch]@8
  int v27; // [sp+30h] [bp+Ch]@12
  signed int v28; // [sp+30h] [bp+Ch]@14

  v4 = *(_DWORD *)(a1 + 44);
  v22 = 0;
  if ( BYTE1(v4) & 1 )
  {
    v23 = (signed __int16)a3;
    v24 = SHIWORD(a3);
    if ( *(_BYTE *)(a1 + 93) )
    {
      v25 = 188 * a2 + pClass51_global->pBModels + 72;
      do
      {
        v5 = 4 * v22;
        word_720A70[2 * v22] = *(_WORD *)(*(_DWORD *)(a1 + 52) + 2 * v22)
                             + *(_WORD *)(*(_DWORD *)v25 + 12 * *(_WORD *)(2 * v22 + *(_DWORD *)(a1 + 48)));
        word_7209A0[2 * v22] = *(_WORD *)(2 * v22 + *(_DWORD *)(a1 + 56))
                             + *(_WORD *)(*(_DWORD *)v25 + 12 * *(_WORD *)(2 * v22 + *(_DWORD *)(a1 + 48)) + 4);
        word_720A72[2 * v22] = *(_WORD *)(*(_DWORD *)(a1 + 52) + 2 * v22 + 2)
                             + *(_WORD *)(*(_DWORD *)v25 + 12 * *(_WORD *)(*(_DWORD *)(a1 + 48) + 2 * v22 + 2));
        v6 = *(_WORD *)(2 * v22 + *(_DWORD *)(a1 + 56) + 2)
           + *(_WORD *)(*(_DWORD *)v25 + 12 * *(_WORD *)(*(_DWORD *)(a1 + 48) + 2 * v22 + 2) + 4);
        ++v22;
        *(__int16 *)((char *)word_7209A2 + v5) = v6;
      }
      while ( v22 < *(_BYTE *)(a1 + 93) );
    }
  }
  else
  {
    if ( BYTE1(v4) & 2 )
    {
      v23 = (signed __int16)a3;
      v24 = a4;
      if ( *(_BYTE *)(a1 + 93) )
      {
        v26 = 188 * a2 + pClass51_global->pBModels + 72;
        do
        {
          v7 = 4 * v22;
          word_720A70[2 * v22] = *(_WORD *)(*(_DWORD *)(a1 + 52) + 2 * v22)
                               + *(_WORD *)(*(_DWORD *)v26 + 12 * *(_WORD *)(2 * v22 + *(_DWORD *)(a1 + 48)));
          word_7209A0[2 * v22] = *(_WORD *)(2 * v22 + *(_DWORD *)(a1 + 60))
                               + *(_WORD *)(*(_DWORD *)v26 + 12 * *(_WORD *)(2 * v22 + *(_DWORD *)(a1 + 48)) + 8);
          word_720A72[2 * v22] = *(_WORD *)(*(_DWORD *)(a1 + 52) + 2 * v22 + 2)
                               + *(_WORD *)(*(_DWORD *)v26 + 12 * *(_WORD *)(*(_DWORD *)(a1 + 48) + 2 * v22 + 2));
          v8 = *(_WORD *)(*(_DWORD *)(a1 + 60) + 2 * v22 + 2)
             + *(_WORD *)(*(_DWORD *)v26 + 12 * *(_WORD *)(*(_DWORD *)(a1 + 48) + 2 * v22 + 2) + 8);
          ++v22;
          *(__int16 *)((char *)word_7209A2 + v7) = v8;
        }
        while ( v22 < *(_BYTE *)(a1 + 93) );
      }
    }
    else
    {
      v23 = SHIWORD(a3);
      v24 = a4;
      if ( *(_BYTE *)(a1 + 93) )
      {
        v27 = 188 * a2 + pClass51_global->pBModels + 72;
        do
        {
          v9 = 4 * v22;
          word_720A70[2 * v22] = *(_WORD *)(2 * v22 + *(_DWORD *)(a1 + 56))
                               + *(_WORD *)(*(_DWORD *)v27 + 12 * *(_WORD *)(2 * v22 + *(_DWORD *)(a1 + 48)) + 4);
          word_7209A0[2 * v22] = *(_WORD *)(2 * v22 + *(_DWORD *)(a1 + 60))
                               + *(_WORD *)(*(_DWORD *)v27 + 12 * *(_WORD *)(2 * v22 + *(_DWORD *)(a1 + 48)) + 8);
          word_720A72[2 * v22] = *(_WORD *)(2 * v22 + *(_DWORD *)(a1 + 56) + 2)
                               + *(_WORD *)(*(_DWORD *)v27 + 12 * *(_WORD *)(2 * v22 + *(_DWORD *)(a1 + 48) + 2) + 4);
          v10 = *(_WORD *)(*(_DWORD *)(a1 + 60) + 2 * v22 + 2)
              + *(_WORD *)(*(_DWORD *)v27 + 12 * *(_WORD *)(2 * v22 + *(_DWORD *)(a1 + 48) + 2) + 8);
          ++v22;
          *(__int16 *)((char *)word_7209A2 + v9) = v10;
        }
        while ( v22 < *(_BYTE *)(a1 + 93) );
      }
    }
  }
  v12 = 2 * *(_BYTE *)(a1 + 93);
  v28 = 0;
  word_720A70[2 * *(_BYTE *)(a1 + 93)] = word_720A70[0];
  word_7209A0[v12] = word_7209A0[0];
  v21 = 0;
  v11 = word_7209A0[0] >= v24;
  if ( v12 <= 0 )
    goto LABEL_29;
  do
  {
    if ( v28 >= 2 )
      break;
    v14 = 2 * v21;
    v13 = word_7209A2[v21];
    if ( v11 ^ v13 >= v24 )
    {
      v15 = *(__int16 *)((char *)word_720A72 + v14);
      if ( v15 >= v23 )
        v16 = 0;
      else
        v16 = 2;
      v17 = v16 | *(__int16 *)((char *)word_720A70 + v14) < v23;
      if ( v17 != 3 )
      {
        if ( !v17
          || (v18 = v15 - *(__int16 *)((char *)word_720A70 + v14),
              LODWORD(v19) = v18 << 16,
              HIDWORD(v19) = v18 >> 16,
              *(__int16 *)((char *)word_720A70 + v14)
            + ((signed int)(((unsigned __int64)(v19
                                              / (v13 - *(__int16 *)((char *)word_7209A0 + v14))
                                              * ((v24 - (signed int)*(__int16 *)((char *)word_7209A0 + v14)) << 16)) >> 16)
                          + 32768) >> 16) >= v23) )
          ++v28;
      }
    }
    ++v21;
    v11 = v13 >= v24;
  }
  while ( v21 < v12 );
  result = 1;
  if ( v28 != 1 )
LABEL_29:
    result = 0;
  return result;
}

//----- (00475D85) --------------------------------------------------------
signed int __fastcall sub_475D85(int a1, int a2, int a3, int a4)
{
  int v4; // ebx@1
  int v5; // edi@2
  int v6; // ST24_4@2
  int v7; // edx@2
  int v8; // eax@5
  signed int v9; // esi@5
  signed __int64 v10; // qtt@10
  int v11; // esi@11
  int v12; // ST14_4@11
  int v14; // [sp+Ch] [bp-18h]@1
  int v15; // [sp+14h] [bp-10h]@1
  int v16; // [sp+18h] [bp-Ch]@2
  int v17; // [sp+20h] [bp-4h]@10
  int v18; // [sp+30h] [bp+Ch]@2
  int v19; // [sp+30h] [bp+Ch]@9
  signed int v20; // [sp+30h] [bp+Ch]@10

  v4 = a4;
  v15 = a2;
  v14 = a1;
  if ( *(_BYTE *)(a4 + 47) & 0x20
    || (v6 = (unsigned __int64)(*(_DWORD *)a2 * *(_DWORD *)(a4 + 16)) >> 16,
        v18 = (unsigned __int64)(*(_DWORD *)(a2 + 4) * *(_DWORD *)(a4 + 20)) >> 16,
        v7 = (unsigned __int64)(*(_DWORD *)(a2 + 8) * *(_DWORD *)(v4 + 24)) >> 16,
        v5 = v6 + v7 + v18,
        v16 = v6 + v7 + v18,
        !(v6 + v7 + v18))
    || v5 > 0 && !(*(_BYTE *)(v4 + 44) & 1) )
    return 0;
  v8 = *(_DWORD *)(v4 + 24) * *(_DWORD *)(a1 + 8);
  v9 = -(*(_DWORD *)(v4 + 28) + v8 + *(_DWORD *)(a1 + 4) * *(_DWORD *)(v4 + 20) + *(_DWORD *)a1 * *(_DWORD *)(v4 + 16));
  if ( v5 <= 0 )
  {
    if ( *(_DWORD *)(v4 + 28) + v8 + *(_DWORD *)(a1 + 4) * *(_DWORD *)(v4 + 20) + *(_DWORD *)a1 * *(_DWORD *)(v4 + 16) < 0 )
      return 0;
  }
  else
  {
    if ( v9 < 0 )
      return 0;
  }
  v19 = abs(-(*(_DWORD *)(v4 + 28)
            + v8
            + *(_DWORD *)(a1 + 4) * *(_DWORD *)(v4 + 20)
            + *(_DWORD *)a1 * *(_DWORD *)(v4 + 16))) >> 14;
  if ( v19 > abs(v5)
    || (LODWORD(v10) = v9 << 16, HIDWORD(v10) = v9 >> 16, v20 = v10 / v16, v17 = v10 / v16, v17 > *(_DWORD *)a3 << 16)
    || (v11 = v14,
        LOWORD(v12) = *(_WORD *)v14 + ((signed int)(((unsigned __int64)(v17 * *(_DWORD *)v15) >> 16) + 32768) >> 16),
        HIWORD(v12) = *(_WORD *)(v11 + 4)
                    + ((signed int)(((unsigned __int64)(v17 * *(_DWORD *)(v15 + 4)) >> 16) + 32768) >> 16),
        !sub_475665(
           v4,
           v12,
           *(_WORD *)(v11 + 8) + ((signed int)(((unsigned __int64)(v17 * *(_DWORD *)(v15 + 8)) >> 16) + 32768) >> 16))) )
    return 0;
  *(_DWORD *)a3 = v20 >> 16;
  return 1;
}

//----- (00475F30) --------------------------------------------------------
signed int __fastcall sub_475F30(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // ebx@1
  int v10; // edi@2
  int v11; // ST20_4@2
  int v12; // ST28_4@2
  int v13; // ST24_4@2
  char v14; // zf@2
  int v15; // eax@5
  signed int v16; // esi@5
  int v17; // ST20_4@9
  signed __int64 v18; // qtt@10
  int v19; // ST14_4@11
  int v21; // [sp+14h] [bp-10h]@1
  int v22; // [sp+1Ch] [bp-8h]@2
  int v23; // [sp+1Ch] [bp-8h]@10
  signed int v24; // [sp+20h] [bp-4h]@10

  v9 = a2;
  v21 = a1;
  if ( *(_BYTE *)(a2 + 47) & 0x20
    || (v11 = (unsigned __int64)(a6 * *(_DWORD *)(a2 + 16)) >> 16,
        v12 = (unsigned __int64)(a7 * *(_DWORD *)(a2 + 20)) >> 16,
        v13 = (unsigned __int64)(a8 * *(_DWORD *)(a2 + 24)) >> 16,
        v14 = v11 + v13 + v12 == 0,
        v10 = v11 + v13 + v12,
        v22 = v11 + v13 + v12,
        v14)
    || v10 > 0 && !(*(_BYTE *)(a2 + 44) & 1) )
    return 0;
  v15 = a4 * *(_DWORD *)(a2 + 20);
  v16 = -(*(_DWORD *)(a2 + 28) + v15 + a3 * *(_DWORD *)(a2 + 16) + a5 * *(_DWORD *)(a2 + 24));
  if ( v10 <= 0 )
  {
    if ( *(_DWORD *)(a2 + 28) + v15 + a3 * *(_DWORD *)(a2 + 16) + a5 * *(_DWORD *)(a2 + 24) < 0 )
      return 0;
  }
  else
  {
    if ( v16 < 0 )
      return 0;
  }
  v17 = abs(-(*(_DWORD *)(a2 + 28) + v15 + a3 * *(_DWORD *)(a2 + 16) + a5 * *(_DWORD *)(a2 + 24))) >> 14;
  if ( v17 > abs(v10)
    || (LODWORD(v18) = v16 << 16, HIDWORD(v18) = v16 >> 16, v24 = v18 / v22, v23 = v18 / v22, v23 > *(_DWORD *)v21 << 16)
    || (LOWORD(v19) = a3 + ((signed int)(((unsigned __int64)(v23 * a6) >> 16) + 32768) >> 16),
        HIWORD(v19) = a4 + ((signed int)(((unsigned __int64)(v23 * a7) >> 16) + 32768) >> 16),
        !sub_4759C9(v9, a9, v19, a5 + ((signed int)(((unsigned __int64)(v23 * a8) >> 16) + 32768) >> 16))) )
    return 0;
  *(_DWORD *)v21 = v24 >> 16;
  return 1;
}

//----- (004760C1) --------------------------------------------------------
int __thiscall sub_4760C1(void *this, int a2)
{
  int result; // eax@1

  result = *(_DWORD *)this;
  if ( *(_DWORD *)this < 30 )
  {
    *((_DWORD *)this + result + 1) = a2;
    ++*(_DWORD *)this;
  }
  return result;
}

//----- (004760D5) --------------------------------------------------------
int __thiscall sub_4760D5(int this)
{
  int result; // eax@2
  int v2; // edx@3
  int v3; // edi@3

  if ( *(_DWORD *)this )
  {
    v3 = 0;
    v2 = this + 4;
    for ( result = *(_DWORD *)(this + 4); v3 < *(_DWORD *)this - 1; v2 += 4 )
    {
      ++v3;
      *(_DWORD *)v2 = *(_DWORD *)(v2 + 4);
    }
    --*(_DWORD *)this;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00476387) --------------------------------------------------------
bool __cdecl sub_476387()
{
  return (byte_72E780 & 0x80) != 0;
}


//----- (00476395) --------------------------------------------------------
char __thiscall sub_476395(int param)
{
  int v1; // eax@2
  int v2; // esi@3
  int v3; // eax@4
  int v4; // eax@8

  if ( byte_6BE3C5 != 1 )
  {
    v2 = 0;
    if (pNPCStats->dword_017FC4 <= 0)
    {
LABEL_8:
      v4 = 0;
      if (array_AD4674[0].dword_000018 != param )
      {
       LOBYTE(v1) = array_AD4674[1].dword_000018 == param;
        return v1;
      }
    }
    else
    {
      v3 = (int)dword_72D694;
      while ( *(void **)(v3 + 16) != (void*)param || !(*(_BYTE *)v3 & 0x80) )
      {
        ++v2;
        v3 += 76;
        if ( v2 >= pNPCStats->dword_017FC4)
          goto LABEL_8;
      }
      v4 = 0;
    }
    return v4 + 1;
  }
  LOBYTE(v1) = 0;
  return v1;
}

//----- (00476590) --------------------------------------------------------
void __cdecl InitializeMerchants()
{
  signed int v1; // edi@3
  char *v2; // ecx@4
  char *v3; // eax@5
  char v4; // dl@5
  int v5; // esi@9
  int result; // eax@21
  signed int v7; // [sp+Ch] [bp-8h]@4
  char *v8; // [sp+10h] [bp-4h]@4

 if (pMerchantsTXT_Raw)
   class23_DeleteBuffer(class23_instance, pMerchantsTXT_Raw);

 pMerchantsTXT_Raw = class17_fn1(pClass17_Events_LOD, "merchant.txt", 0);
 strtok(pMerchantsTXT_Raw, "\r");

 v1 = (signed int)dword_73C3C0;
  do
  {
    v8 = 0;
    v7 = 0;
    v2 = strtok(0, "\r") + 1;
    do
    {
      v4 = *v2;
      v3 = 0;
      if ( *v2 != 9 )
      {
        do
        {
          if ( !v4 )
            break;
          ++v3;
          v4 = *(_BYTE *)((_DWORD)v3 + (_DWORD)v2);
        }
        while ( v4 != 9 );
      }
      v5 = (_DWORD)v3 + (_DWORD)v2;
      if ( *(_BYTE *)((_DWORD)v3 + (_DWORD)v2) == 0)
        v7 = 1;
      *(_BYTE *)v5 = 0;
      if ( v3 == 0)
      {
        v7 = 1;
      }
      else
      {
        if ( v8 == (char *)1 )
        {
          *(_DWORD *)(v1 - 56) = sub_452C30(v2);
        }
        else
        {
          if ( v8 == (char *)2 )
          {
            *(_DWORD *)(v1 - 28) = sub_452C30(v2);
          }
          else
          {
            if ( v8 == (char *)3 )
            {
              *(_DWORD *)v1 = sub_452C30(v2);
            }
            else
            {
              if ( v8 - 3 == (char *)1 )
                *(_DWORD *)(v1 + 28) = sub_452C30(v2);
            }
          }
        }
      }
      ++v8;
      v2 = (char *)(v5 + 1);
      result = (int)(v8 - 1);
    }
    while ( (signed int)(v8 - 1) <= 4 && !v7);
    v1 += 4;
  }
  while ( v1 < (signed int)dword_73C3DC );
}

//----- (00476682) --------------------------------------------------------
void __cdecl InitializeTransitions()
{
  char *result; // eax@4
  int v2; // edi@4
  char v3; // dl@5
  char *v4; // ecx@5
  int v5; // esi@9
  signed int v6; // [sp+10h] [bp-8h]@3
  signed int v7; // [sp+14h] [bp-4h]@4

 if (pTransitionsTXT_Raw)
   class23_DeleteBuffer(class23_instance, pTransitionsTXT_Raw);

 pTransitionsTXT_Raw = class17_fn1(pClass17_Events_LOD, "trans.txt", 0);
 strtok(pTransitionsTXT_Raw, "\r");

  //v6 = (signed int)&unk_4EB084;
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
          *(_DWORD *)(&unk_4EB084 + v6) = sub_452C30(result);
      }
      ++v2;
      result = (char *)(v5 + 1);
    }
    while ( v2 - 1 <= 1 && !v7);
    v6 += 4;
  }
  //while ( v6 < (signed int)"awards.txt" );
 while (v6 < 0x740);
}

//----- (00476C60) --------------------------------------------------------
void __thiscall sub_476C60(int this)
{
  signed int v1; // esi@1
  int v2; // eax@2
  int v3; // edx@2

  v1 = 1;
  if ( *(_DWORD *)(this + 98244) > 1 )
  {
    v3 = this + 38152;
    v2 = this + 89460;
    do
    {
      ++v1;
      *(_DWORD *)v3 = *(_DWORD *)v2;
      v2 += 4;
      v3 += 76;
    }
    while ( v1 < *(_DWORD *)(this + 98244) );
  }
  if (array_AD4674[0].pNPCName)
    array_AD4674[0].pNPCName = byte_AE302C;
  if (array_AD4674[1].pNPCName)
    array_AD4674[1].pNPCName = (char *)&unk_AE3090;
}

//----- (00477266) --------------------------------------------------------
int __thiscall sub_477266(int this)
{
  int result; // eax@1
  int v2; // esi@1
  int v3; // ST00_4@1
  int v4; // ebx@1

  v2 = this;
  class23_DeleteBuffer(class23_instance, *(_DWORD *)(this + 98280));
  v3 = *(_DWORD *)(v2 + 98284);
  *(_DWORD *)(v2 + 98276) = 0;
  class23_DeleteBuffer(class23_instance, v3);
  *(_DWORD *)(v2 + 98276) = 0;
  class23_DeleteBuffer(class23_instance, 0);
  *(_DWORD *)(v2 + 98276) = 0;
  class23_DeleteBuffer(class23_instance, *(_DWORD *)(v2 + 98272));
  *(_DWORD *)(v2 + 98272) = 0;
  class23_DeleteBuffer(class23_instance, *(_DWORD *)(v2 + 98268));
  *(_DWORD *)(v2 + 98268) = 0;
  class23_DeleteBuffer(class23_instance, *(_DWORD *)(v2 + 98264));
  *(_DWORD *)(v2 + 98264) = 0;
  class23_DeleteBuffer(class23_instance, *(_DWORD *)(v2 + 98288));
  *(_DWORD *)(v2 + 98288) = 0;
  v4 = v2 + 98292;
  class23_DeleteBuffer(class23_instance, *(_DWORD *)(v2 + 98292));
  v2 += 98296;
  *(_DWORD *)v4 = 0;
  result = class23_DeleteBuffer(class23_instance, *(_DWORD *)v2);
  *(_DWORD *)v2 = 0;
  return result;
}

//----- (0047730C) --------------------------------------------------------
signed int __stdcall sub_47730C(int a1)
{
  return 1;
}

//----- (0047732C) --------------------------------------------------------
function_error; //#error "FFFFFFFF: variables would overlap: ecx/4 and edx/8 (funcsize=165)"
long __stdcall sub_47732C(long a1, long a2, long a3, long a4)
{
 compile_error;
 return 0;
}

//----- (0047752B) --------------------------------------------------------
int __cdecl sub_47752B()
{
  _UNKNOWN *v0; // ebx@1
  signed int v1; // esi@3
  int v2; // eax@3
  int v3; // eax@5
  int v4; // eax@7
  int v5; // eax@9
  int v6; // eax@11

  v0 = &unk_6A12B8;
  if ( dword_6BE360 != 2 )
    v0 = &unk_6BE68C;
  v1 = 0;
  LOBYTE(v2) = sub_476395(0x2D);
  if ( v2 )
    v1 = 5;
  LOBYTE(v3) = sub_476395(0x33);
  if ( v3 )
    v1 += 5;
  LOBYTE(v4) = sub_476395(0x30);
  if ( v4 )
    v1 += 5;
  LOBYTE(v5) = sub_476395(0x32);
  if ( v5 )
    v1 += 5;
  LOBYTE(v6) = sub_476395(0x34);
  if ( v6 )
    v1 += 5;
  return v1 + *((_DWORD *)v0 + 2);
}

//----- (004775C4) --------------------------------------------------------
int __thiscall sub_4775C4(int this)
{
  int v1; // eax@1
  int v2; // esi@1
  int result; // eax@3

  v2 = this;
  v1 = *(_DWORD *)(this + 4);
  if ( v1 )
    operator_delete(v1, *(_DWORD *)(this + 4));
  result = *(_DWORD *)(v2 + 12);
  if ( result )
    result = operator_delete(result, *(_DWORD *)(v2 + 12));
  *(_DWORD *)(v2 + 4) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  return result;
}

//----- (004775ED) --------------------------------------------------------
int __thiscall sub_4775ED(int this, int a2)
{
  int v2; // eax@1
  int v3; // edi@1
  int v4; // edx@2
  int v5; // esi@3
  double v6; // st7@6
  int v7; // ecx@6
  signed __int64 v8; // ST84_8@6
  double v9; // ST0C_8@6
  int v10; // esi@6
  double v11; // ST44_8@6
  int v12; // ecx@6
  double v13; // ST34_8@6
  int v14; // ecx@6
  double v15; // ST14_8@6
  double v16; // st7@8
  int v17; // ecx@8
  signed __int64 v18; // ST64_8@8
  double v19; // ST24_8@8
  int v20; // edi@8
  double v21; // ST3C_8@8
  int v22; // ecx@8
  double v23; // ST2C_8@8
  int v24; // ST9C_4@8
  double v25; // ST1C_8@8
  int v26; // edi@8
  int v27; // esi@8
  int v28; // edi@10
  int v29; // esi@10
  char v30; // zf@11
  int result; // eax@12
  float v32; // [sp+ACh] [bp-2Ch]@6
  float v33; // [sp+B0h] [bp-28h]@6
  float v34; // [sp+B4h] [bp-24h]@6
  int v35; // [sp+B8h] [bp-20h]@6
  int v36; // [sp+BCh] [bp-1Ch]@2
  int v37; // [sp+C0h] [bp-18h]@1
  float v38; // [sp+C4h] [bp-14h]@6
  int v39; // [sp+C8h] [bp-10h]@6
  int v40; // [sp+CCh] [bp-Ch]@1
  float v41; // [sp+D0h] [bp-8h]@6
  int v42; // [sp+D4h] [bp-4h]@2

  v3 = 16 * *(_DWORD *)(this + 16) + this + 100;
  v40 = 0;
  *(_DWORD *)v3 = *(_DWORD *)(this + 100);
  v3 += 4;
  *(_DWORD *)v3 = *(_DWORD *)(this + 104);
  v3 += 4;
  *(_DWORD *)v3 = *(_DWORD *)(this + 108);
  *(_DWORD *)(v3 + 4) = *(_DWORD *)(this + 112);
  v2 = *(_DWORD *)(this + 16);
  v37 = this;
  if ( v2 > 0 )
  {
    v42 = this + 180;
    v4 = this + 115;
    v36 = v2;
    while ( 1 )
    {
      v5 = v4 - 15;
      if ( *(float *)(v4 - 15) <= (double)*(float *)&a2 && *(float *)(v4 + 1) <= (double)*(float *)&a2 )
        goto LABEL_11;
      if ( *(float *)v5 <= (double)*(float *)&a2 )
        break;
      if ( *(float *)(v4 + 1) <= (double)*(float *)&a2 )
      {
        v16 = (*(float *)&a2 - *(float *)v5) / (*(float *)(v4 + 1) - *(float *)v5);
        v17 = *(_BYTE *)v4;
        LODWORD(v32) = a2;
        v18 = (unsigned int)*(_BYTE *)(v4 + 16) - v17;
        v38 = v16;
        v33 = (*(float *)(v4 + 5) - *(float *)(v4 - 11)) * v16 + *(float *)(v4 - 11);
        v34 = (*(float *)(v4 + 9) - *(float *)(v4 - 7)) * v16 + *(float *)(v4 - 7);
        v41 = (double)v18 * v16;
        v19 = v41 + 6.755399441055744e15;
        v20 = *(_BYTE *)v4;
        v41 = (double)(*(_BYTE *)(v4 + 15) - (*(_BYTE *)(v4 - 1) & 0xFFu)) * v38;
        v21 = v41 + 6.755399441055744e15;
        v22 = *(_BYTE *)(v4 - 2);
        v39 = LODWORD(v21) + *(_BYTE *)(v4 - 1);
        v41 = (double)((unsigned int)*(_BYTE *)(v4 + 14) - v22) * v38;
        v23 = v41 + 6.755399441055744e15;
        v24 = LODWORD(v23) + *(_BYTE *)(v4 - 2);
        v41 = (double)((*(_DWORD *)(v4 + 13) & 0xFF) - (*(_DWORD *)(v4 - 3) & 0xFFu)) * v38;
        v25 = v41 + 6.755399441055744e15;
        v35 = (LODWORD(v25) + (*(_DWORD *)(v4 - 3) & 0xFF)) | ((v24 | ((v39 | ((LODWORD(v19) + v20) << 8)) << 8)) << 8);
        v26 = v42;
        *(_DWORD *)v42 = *(_DWORD *)v5;
        v27 = v5 + 4;
        v26 += 4;
        *(_DWORD *)v26 = *(_DWORD *)v27;
        v27 += 4;
        v26 += 4;
        ++v40;
        v42 += 16;
        *(_DWORD *)v26 = *(_DWORD *)v27;
        *(_DWORD *)(v26 + 4) = *(_DWORD *)(v27 + 4);
        goto LABEL_9;
      }
LABEL_10:
      v28 = v42;
      ++v40;
      *(_DWORD *)v42 = *(_DWORD *)v5;
      v29 = v5 + 4;
      v28 += 4;
      *(_DWORD *)v28 = *(_DWORD *)v29;
      v29 += 4;
      v28 += 4;
      v42 += 16;
      *(_DWORD *)v28 = *(_DWORD *)v29;
      *(_DWORD *)(v28 + 4) = *(_DWORD *)(v29 + 4);
LABEL_11:
      v4 += 16;
      v30 = v36-- == 1;
      if ( v30 )
        goto LABEL_12;
    }
    v6 = (*(float *)&a2 - *(float *)v5) / (*(float *)(v4 + 1) - *(float *)v5);
    v7 = *(_BYTE *)v4;
    LODWORD(v32) = a2;
    v8 = (unsigned int)*(_BYTE *)(v4 + 16) - v7;
    v38 = v6;
    v33 = (*(float *)(v4 + 5) - *(float *)(v4 - 11)) * v6 + *(float *)(v4 - 11);
    v34 = (*(float *)(v4 + 9) - *(float *)(v4 - 7)) * v6 + *(float *)(v4 - 7);
    *(float *)&v39 = (double)v8 * v6;
    v9 = *(float *)&v39 + 6.755399441055744e15;
    v10 = *(_BYTE *)v4;
    *(float *)&v39 = (double)(*(_BYTE *)(v4 + 15) - (*(_BYTE *)(v4 - 1) & 0xFFu)) * v38;
    v11 = *(float *)&v39 + 6.755399441055744e15;
    v12 = *(_BYTE *)(v4 - 2);
    v39 = LODWORD(v11) + *(_BYTE *)(v4 - 1);
    v41 = (double)((unsigned int)*(_BYTE *)(v4 + 14) - v12) * v38;
    v13 = v41 + 6.755399441055744e15;
    v14 = LODWORD(v13) + *(_BYTE *)(v4 - 2);
    v41 = (double)((*(_DWORD *)(v4 + 13) & 0xFF) - (*(_DWORD *)(v4 - 3) & 0xFFu)) * v38;
    v15 = v41 + 6.755399441055744e15;
    v35 = (LODWORD(v15) + (*(_DWORD *)(v4 - 3) & 0xFF)) | ((v14 | ((v39 | ((LODWORD(v9) + v10) << 8)) << 8)) << 8);
LABEL_9:
    this = v37;
    v5 = (int)&v32;
    goto LABEL_10;
  }
LABEL_12:
  result = v40;
  *(_DWORD *)(this + 16) = v40;
  return result;
}

//----- (00477927) --------------------------------------------------------
int __thiscall sub_477927(int this, int a2)
{
  int v2; // eax@1
  int v3; // edi@1
  int v4; // edx@2
  int v5; // esi@3
  double v6; // st7@6
  int v7; // ecx@6
  signed __int64 v8; // ST84_8@6
  double v9; // ST0C_8@6
  int v10; // esi@6
  double v11; // ST44_8@6
  int v12; // ecx@6
  double v13; // ST34_8@6
  int v14; // ecx@6
  double v15; // ST14_8@6
  double v16; // st7@8
  int v17; // ecx@8
  signed __int64 v18; // ST64_8@8
  double v19; // ST24_8@8
  int v20; // edi@8
  double v21; // ST3C_8@8
  int v22; // ecx@8
  double v23; // ST2C_8@8
  int v24; // ST9C_4@8
  double v25; // ST1C_8@8
  int v26; // edi@8
  int v27; // esi@8
  int v28; // edi@10
  int v29; // esi@10
  char v30; // zf@11
  int result; // eax@12
  float v32; // [sp+ACh] [bp-2Ch]@6
  float v33; // [sp+B0h] [bp-28h]@6
  float v34; // [sp+B4h] [bp-24h]@6
  int v35; // [sp+B8h] [bp-20h]@6
  int v36; // [sp+BCh] [bp-1Ch]@2
  int v37; // [sp+C0h] [bp-18h]@1
  float v38; // [sp+C4h] [bp-14h]@6
  int v39; // [sp+C8h] [bp-10h]@6
  int v40; // [sp+CCh] [bp-Ch]@1
  float v41; // [sp+D0h] [bp-8h]@6
  int v42; // [sp+D4h] [bp-4h]@2

  v3 = 16 * *(_DWORD *)(this + 16) + this + 100;
  v40 = 0;
  *(_DWORD *)v3 = *(_DWORD *)(this + 100);
  v3 += 4;
  *(_DWORD *)v3 = *(_DWORD *)(this + 104);
  v3 += 4;
  *(_DWORD *)v3 = *(_DWORD *)(this + 108);
  *(_DWORD *)(v3 + 4) = *(_DWORD *)(this + 112);
  v2 = *(_DWORD *)(this + 16);
  v37 = this;
  if ( v2 > 0 )
  {
    v42 = this + 180;
    v4 = this + 115;
    v36 = v2;
    while ( 1 )
    {
      v5 = v4 - 15;
      if ( *(float *)(v4 - 15) >= (double)*(float *)&a2 && *(float *)(v4 + 1) >= (double)*(float *)&a2 )
        goto LABEL_11;
      if ( *(float *)v5 >= (double)*(float *)&a2 )
        break;
      if ( *(float *)(v4 + 1) >= (double)*(float *)&a2 )
      {
        v16 = (*(float *)&a2 - *(float *)v5) / (*(float *)(v4 + 1) - *(float *)v5);
        v17 = *(_BYTE *)v4;
        LODWORD(v32) = a2;
        v18 = (unsigned int)*(_BYTE *)(v4 + 16) - v17;
        v38 = v16;
        v33 = (*(float *)(v4 + 5) - *(float *)(v4 - 11)) * v16 + *(float *)(v4 - 11);
        v34 = (*(float *)(v4 + 9) - *(float *)(v4 - 7)) * v16 + *(float *)(v4 - 7);
        v41 = (double)v18 * v16;
        v19 = v41 + 6.755399441055744e15;
        v20 = *(_BYTE *)v4;
        v41 = (double)(*(_BYTE *)(v4 + 15) - (*(_BYTE *)(v4 - 1) & 0xFFu)) * v38;
        v21 = v41 + 6.755399441055744e15;
        v22 = *(_BYTE *)(v4 - 2);
        v39 = LODWORD(v21) + *(_BYTE *)(v4 - 1);
        v41 = (double)((unsigned int)*(_BYTE *)(v4 + 14) - v22) * v38;
        v23 = v41 + 6.755399441055744e15;
        v24 = LODWORD(v23) + *(_BYTE *)(v4 - 2);
        v41 = (double)((*(_DWORD *)(v4 + 13) & 0xFF) - (*(_DWORD *)(v4 - 3) & 0xFFu)) * v38;
        v25 = v41 + 6.755399441055744e15;
        v35 = (LODWORD(v25) + (*(_DWORD *)(v4 - 3) & 0xFF)) | ((v24 | ((v39 | ((LODWORD(v19) + v20) << 8)) << 8)) << 8);
        v26 = v42;
        *(_DWORD *)v42 = *(_DWORD *)v5;
        v27 = v5 + 4;
        v26 += 4;
        *(_DWORD *)v26 = *(_DWORD *)v27;
        v27 += 4;
        v26 += 4;
        ++v40;
        v42 += 16;
        *(_DWORD *)v26 = *(_DWORD *)v27;
        *(_DWORD *)(v26 + 4) = *(_DWORD *)(v27 + 4);
        goto LABEL_9;
      }
LABEL_10:
      v28 = v42;
      ++v40;
      *(_DWORD *)v42 = *(_DWORD *)v5;
      v29 = v5 + 4;
      v28 += 4;
      *(_DWORD *)v28 = *(_DWORD *)v29;
      v29 += 4;
      v28 += 4;
      v42 += 16;
      *(_DWORD *)v28 = *(_DWORD *)v29;
      *(_DWORD *)(v28 + 4) = *(_DWORD *)(v29 + 4);
LABEL_11:
      v4 += 16;
      v30 = v36-- == 1;
      if ( v30 )
        goto LABEL_12;
    }
    v6 = (*(float *)&a2 - *(float *)v5) / (*(float *)(v4 + 1) - *(float *)v5);
    v7 = *(_BYTE *)v4;
    LODWORD(v32) = a2;
    v8 = (unsigned int)*(_BYTE *)(v4 + 16) - v7;
    v38 = v6;
    v33 = (*(float *)(v4 + 5) - *(float *)(v4 - 11)) * v6 + *(float *)(v4 - 11);
    v34 = (*(float *)(v4 + 9) - *(float *)(v4 - 7)) * v6 + *(float *)(v4 - 7);
    *(float *)&v39 = (double)v8 * v6;
    v9 = *(float *)&v39 + 6.755399441055744e15;
    v10 = *(_BYTE *)v4;
    *(float *)&v39 = (double)(*(_BYTE *)(v4 + 15) - (*(_BYTE *)(v4 - 1) & 0xFFu)) * v38;
    v11 = *(float *)&v39 + 6.755399441055744e15;
    v12 = *(_BYTE *)(v4 - 2);
    v39 = LODWORD(v11) + *(_BYTE *)(v4 - 1);
    v41 = (double)((unsigned int)*(_BYTE *)(v4 + 14) - v12) * v38;
    v13 = v41 + 6.755399441055744e15;
    v14 = LODWORD(v13) + *(_BYTE *)(v4 - 2);
    v41 = (double)((*(_DWORD *)(v4 + 13) & 0xFF) - (*(_DWORD *)(v4 - 3) & 0xFFu)) * v38;
    v15 = v41 + 6.755399441055744e15;
    v35 = (LODWORD(v15) + (*(_DWORD *)(v4 - 3) & 0xFF)) | ((v14 | ((v39 | ((LODWORD(v9) + v10) << 8)) << 8)) << 8);
LABEL_9:
    this = v37;
    v5 = (int)&v32;
    goto LABEL_10;
  }
LABEL_12:
  result = v40;
  *(_DWORD *)(this + 16) = v40;
  return result;
}

//----- (00477C61) --------------------------------------------------------
signed int __thiscall sub_477C61(void *this)
{
  void *v1; // ebx@1
  int v2; // ecx@2
  int v3; // eax@3
  double v4; // st7@4
  double v5; // st6@5
  double v6; // st7@5
  double v7; // st5@6
  double v8; // st5@8
  double v9; // st6@8
  double v10; // st7@8
  float v11; // ST30_4@8
  float v12; // ST24_4@8
  float v13; // ST24_4@13
  int v14; // esi@13
  int v15; // esi@15
  double v16; // st6@16
  __int16 v17; // fps@16
  unsigned __int8 v18; // c2@16
  unsigned __int8 v19; // c3@16
  double v20; // st6@17
  double v21; // st7@17
  float v22; // ST18_4@17
  float v23; // ST2C_4@17
  float v24; // ST34_4@17
  float v25; // ST24_4@17
  float v26; // ST34_4@18
  float v27; // ST30_4@18
  int v28; // eax@19
  signed int v31; // [sp+8h] [bp-28h]@15
  float v32; // [sp+Ch] [bp-24h]@16
  float v33; // [sp+14h] [bp-1Ch]@16
  float v34; // [sp+18h] [bp-18h]@16
  float v35; // [sp+1Ch] [bp-14h]@17
  float v36; // [sp+20h] [bp-10h]@4
  float v37; // [sp+20h] [bp-10h]@16
  float v38; // [sp+24h] [bp-Ch]@4
  float v39; // [sp+24h] [bp-Ch]@16
  float v40; // [sp+28h] [bp-8h]@9
  float v41; // [sp+28h] [bp-8h]@16
  float v42; // [sp+2Ch] [bp-4h]@6
  float v43; // [sp+2Ch] [bp-4h]@9

  v1 = this;
  if ( dword_6BE360 == 1 )
  {
    v2 = 0;
    if ( *((_DWORD *)v1 + 4) > 0 )
    {
      v3 = (int)((char *)v1 + 24);
      do
      {
        v4 = *(float *)(v3 - 4);
        LODWORD(v38) = *(_DWORD *)v3;
        LODWORD(v36) = *(_DWORD *)(v3 + 4);
        if ( dword_51B6F8 )
        {
          v6 = v4 - (double)dword_51B6E8;
          v5 = v38 - (double)dword_51B6EC;
          if ( pD3DRenderer->dword_040088 )
          {
            v42 = *(float *)&dword_51B714 * v5 + flt_51B710 * v6;
            v7 = *(float *)&dword_51B714 * v6 - flt_51B710 * v5;
          }
          else
          {
            v42 = flt_51B710 * v6 - *(float *)&dword_51B714 * v5;
            v7 = *(float *)&dword_51B714 * v6 + flt_51B710 * v5;
          }
          v11 = v7;
          v12 = v36 - (double)dword_51B6F0;
          v10 = *(float *)&dword_51B718 * v42 - *(float *)&dword_51B71C * v12;
          v9 = v11;
          v8 = *(float *)&dword_51B718 * v12 + *(float *)&dword_51B71C * v42;
        }
        else
        {
          v43 = v4 - (double)dword_51B6E8;
          v40 = v38 - (double)dword_51B6EC;
          if ( pD3DRenderer->dword_040088 )
          {
            v10 = *(float *)&dword_51B714 * v40 + flt_51B710 * v43;
            v9 = *(float *)&dword_51B714 * v43 - flt_51B710 * v40;
          }
          else
          {
            v10 = flt_51B710 * v43 - *(float *)&dword_51B714 * v40;
            v9 = *(float *)&dword_51B714 * v43 + flt_51B710 * v40;
          }
          v8 = v36 - (double)dword_51B6F0;
        }
        v13 = v8;
        ++v2;
        *(_DWORD *)(v3 + 84) = LODWORD(v13);
        v14 = *(_DWORD *)(v3 + 8);
        *(float *)(v3 + 76) = v10;
        *(_DWORD *)(v3 + 88) = v14;
        *(float *)(v3 + 80) = v9;
        v3 += 16;
      }
      while ( v2 < *((_DWORD *)v1 + 4) );
    }
  }
  else
  {
    v15 = (int)((char *)this + 24);
    v31 = 3;
    do
    {
      v41 = (double)class59_SinCos(pClass59_global, pCamera->sRotationX) * *(double *)&byte_4D8410[840];
      v32 = (double)class59_SinCos(pClass59_global, pCamera->sRotationX - pClass59_global->uNumTableEntries) * *(double *)&byte_4D8410[840];
      v34 = (double)class59_SinCos(pClass59_global, pCamera->sRotationY) * *(double *)&byte_4D8410[840];
      LODWORD(v39) = *(_DWORD *)v15;
      LODWORD(v37) = *(_DWORD *)(v15 + 4);
      v33 = (double)class59_SinCos(pClass59_global, pCamera->sRotationY - pClass59_global->uNumTableEntries) * *(double *)&byte_4D8410[840];
      UNDEF(v17);
      v16 = *(float *)(v15 - 4) - (double)pCamera->dword_000000;
      if ( v19 | v18 )
      {
        v26 = v16;
        v35 = v37;
        v27 = v39 - (double)pCamera->dword_000004;
        v21 = v33 * v27 + v34 * v26;
        v20 = v34 * v27 - v33 * v26;
      }
      else
      {
        v22 = v16;
        v23 = v39 - (double)pCamera->dword_000004;
        v24 = v33 * v23 + v34 * v22;
        v25 = v37 - (double)pCamera->dword_000008;
        v21 = v32 * v25 + v41 * v24;
        v20 = v34 * v23 - v33 * v22;
        v35 = v41 * v25 - v32 * v24;
      }
      *(_DWORD *)(v15 + 84) = LODWORD(v35);
      v28 = *(_DWORD *)(v15 + 8);
      *(float *)(v15 + 76) = v21;
      *(_DWORD *)(v15 + 88) = v28;
      *(float *)(v15 + 80) = v20;
      v15 += 16;
    }
    while ( v31-- != 1 );
  }
  *((_DWORD *)v1 + 4) = 3;
  return 1;
}

//----- (00477F63) --------------------------------------------------------
bool __fastcall sub_477F63(int a1)
{
  signed int v1; // ebx@1
  int v2; // esi@1
  double v3; // st7@2
  int v4; // edx@4
  int v5; // ecx@5
  int v6; // edi@5
  int v7; // ST08_4@13
  signed int v9; // [sp+Ch] [bp-8h]@1
  int v10; // [sp+10h] [bp-4h]@2

  v1 = 0;
  v2 = a1;
  v9 = 0;
  if ( dword_6BE360 == 1 )
  {
    v10 = 1182597120;
    v3 = (double)unk_51B720 * 0.0000152587890625;
  }
  else
  {
    *(float *)&v10 = (double)pStruct9_global->shading_dist_mist;
    v3 = 8.0;
  }
  v4 = *(_DWORD *)(a1 + 16);
  if ( v4 <= 0 )
    goto LABEL_16;
  v5 = a1 + 100;
  v6 = v4;
  do
  {
    if ( v3 >= *(float *)v5 || *(float *)v5 >= (double)*(float *)&v10 )
    {
      if ( v3 < *(float *)v5 )
        v9 = 1;
      else
        v1 = 1;
    }
    v5 += 16;
    --v6;
  }
  while ( v6 );
  if ( !v1 )
  {
    if ( v9 )
    {
      sub_477927(v2, v10);
      return *(_DWORD *)(v2 + 16) != 0;
    }
LABEL_16:
    memcpy((void *)(v2 + 180), (const void *)(v2 + 100), 16 * v4);
    return *(_DWORD *)(v2 + 16) != 0;
  }
  *(float *)&v7 = v3;
  sub_4775ED(v2, v7);
  return *(_DWORD *)(v2 + 16) != 0;
}

//----- (0047802A) --------------------------------------------------------
signed int __fastcall sub_47802A(int a1)
{
  int v1; // edx@1
  int v2; // edi@1
  int v3; // ebx@2
  int v4; // esi@3
  float v5; // eax@4
  double v6; // st7@4
  double v7; // ST30_8@5
  double v8; // st6@6
  double v9; // st5@6
  int v10; // ecx@15
  float v11; // eax@16
  double v12; // st7@16
  double v13; // st6@16
  double v14; // st5@16
  signed int v16; // [sp+38h] [bp-Ch]@1
  int v17; // [sp+3Ch] [bp-8h]@5
  int v18; // [sp+40h] [bp-4h]@5

  v1 = 0;
  v2 = a1;
  v16 = 0;
  if ( dword_6BE360 == 1 )
  {
    v3 = 0;
    if ( *(_DWORD *)(a1 + 16) > 0 )
    {
      v4 = a1 + 188;
      do
      {
        LODWORD(v5) = *(_DWORD *)(v4 - 8);
        v6 = (double)unk_51B720 * 0.0000152587890625 / *(float *)(v4 - 8);
        if ( pD3DRenderer->dword_040088 )
        {
          v7 = v5 + 6.755399441055744e15;
          compile_error;
          /*sub_436A9A(
            pGame->class08_obj,
            COERCE_UNSIGNED_INT64(v5 + 6.755399441055744e15),
            COERCE_UNSIGNED_INT64(*(float *)(v4 - 4) + 6.755399441055744e15),
            COERCE_UNSIGNED_INT64(*(float *)v4 + 6.755399441055744e15),
            (int)&v18,
            (int)&v17);*/
          *(float *)(v4 + 72) = (double)v18;
          *(float *)(v4 + 76) = (double)v17;
          *(float *)(v4 + 80) = (double)SLODWORD(v7);
        }
        else
        {
          *(float *)(v4 + 72) = (double)dword_51B754 - v6 * *(float *)(v4 - 4);
          v8 = (double)dword_51B758;
          v9 = v6 * *(float *)v4;
          *(_DWORD *)(v4 + 80) = LODWORD(v5);
          *(float *)(v4 + 76) = v8 - v9;
        }
        *(_DWORD *)(v4 + 84) = *(_DWORD *)(v4 + 4);
        if ( (double)class28_global.dword_000010 <= *(float *)(v4 + 72) )
        {
          if ( (double)class28_global.dword_000018 > *(float *)(v4 + 72) )
          {
            if ( (double)class28_global.dword_000014 <= *(float *)(v4 + 76) )
            {
              if ( (double)class28_global.dword_00001C > *(float *)(v4 + 76) )
                v16 = 1;
            }
          }
        }
        ++v3;
        v4 += 16;
      }
      while ( v3 < *(_DWORD *)(v2 + 16) );
    }
  }
  else
  {
    if ( *(_DWORD *)(a1 + 16) > 0 )
    {
      v10 = a1 + 180;
      do
      {
        LODWORD(v11) = *(_DWORD *)v10;
        v12 = (double)pStruct9_global->dword_000014 / *(float *)v10;
        *(float *)(v10 + 80) = (double)class28_global.dword_000028 - v12 * *(float *)(v10 + 4);
        v13 = (double)class28_global.dword_00002C;
        v14 = v12 * *(float *)(v10 + 8);
        *(_DWORD *)(v10 + 88) = LODWORD(v11);
        *(_DWORD *)(v10 + 92) = *(_DWORD *)(v10 + 12);
        *(float *)(v10 + 84) = v13 - v14;
        if ( (double)class28_global.dword_000010 <= *(float *)(v10 + 80) )
        {
          if ( (double)class28_global.dword_000018 > *(float *)(v10 + 80) )
          {
            if ( (double)class28_global.dword_000014 <= *(float *)(v10 + 84) )
            {
              if ( (double)class28_global.dword_00001C > *(float *)(v10 + 84) )
                v16 = 1;
            }
          }
        }
        ++v1;
        v10 += 16;
      }
      while ( v1 < *(_DWORD *)(v2 + 16) );
    }
  }
  return v16;
}

//----- (0047829F) --------------------------------------------------------
void __thiscall sub_47829F(void *this, float a2, float a3, float a4, float a5, int a6)
{
  int v6; // edi@1
  int v7; // esi@1
  int v8; // eax@2
  signed int v9; // ecx@2
  int v10; // edx@3
  int i; // [sp+8h] [bp-4h]@1

  v7 = (int)this;
  v6 = 0;
  for ( i = 0; i < *(_DWORD *)(v7 + 8); ++i )
  {
    v8 = v7 + 24;
    v9 = 3;
    do
    {
      *(float *)(v8 - 4) = a5 * *(float *)(16 * *(_DWORD *)(v6 + *(_DWORD *)(v7 + 12)) + *(_DWORD *)(v7 + 4)) + a2;
      *(float *)v8 = a5 * *(float *)(16 * *(_DWORD *)(v6 + *(_DWORD *)(v7 + 12)) + *(_DWORD *)(v7 + 4) + 4) + a3;
      v8 += 16;
      *(float *)(v8 - 12) = a5 * *(float *)(16 * *(_DWORD *)(v6 + *(_DWORD *)(v7 + 12)) + *(_DWORD *)(v7 + 4) + 8) + a4;
      v10 = *(_DWORD *)(v6 + *(_DWORD *)(v7 + 12));
      v6 += 4;
      --v9;
      *(_DWORD *)(v8 - 8) = *(_DWORD *)(16 * v10 + *(_DWORD *)(v7 + 4) + 12);
    }
    while ( v9 );
    *(_DWORD *)(v7 + 16) = 3;
    if ( sub_477C61((void *)v7) )
    {
      if ( sub_477F63(v7) )
      {
        if ( sub_47802A(v7) )
          sub_4A4CC9(v7, a6);
      }
    }
  }
}

//----- (00478389) --------------------------------------------------------
int __thiscall sub_478389(int this)
{
  int result; // eax@1
  int v2; // esi@1
  int v3; // ST00_4@1
  int v4; // ST00_4@1
  int v5; // ST00_4@1

  v2 = this;
  class23_DeleteBuffer(class23_instance, *(_DWORD *)(this + 4));
  v3 = *(_DWORD *)(v2 + 16);
  *(_DWORD *)(v2 + 4) = 0;
  class23_DeleteBuffer(class23_instance, v3);
  v4 = *(_DWORD *)(v2 + 20);
  *(_DWORD *)(v2 + 16) = 0;
  class23_DeleteBuffer(class23_instance, v4);
  v5 = *(_DWORD *)(v2 + 28);
  *(_DWORD *)(v2 + 20) = 0;
  result = class23_DeleteBuffer(class23_instance, v5);
  *(_DWORD *)(v2 + 28) = 0;
  *(_DWORD *)(v2 + 24) = 0;
  *(_DWORD *)(v2 + 8) = 0;
  *(_DWORD *)v2 = 0;
  *(_WORD *)(v2 + 12) = 0;
  return result;
}

//----- (0047840D) --------------------------------------------------------
char __cdecl RenderBuildings()
{
  char result; // al@3
  int v1; // eax@3
  int v2; // ebx@4
  int v3; // eax@5
  int v4; // esi@6
  int v5; // eax@6
  int v6; // ecx@8
  int v7; // ecx@8
  int v8; // ebx@8
  int v9; // eax@8
  int v10; // eax@8
  char v11; // zf@8
  int v12; // eax@10
  signed int v13; // ecx@10
  char v14; // zf@10
  int v15; // eax@14
  int v16; // eax@18
  unsigned int v17; // eax@22
  unsigned int v18; // edi@22
  int v19; // eax@24
  int v20; // edi@34
  _UNKNOWN *v21; // eax@35
  int v22; // ecx@35
  int v23; // edx@36
  int v24; // edx@36
  char v25; // zf@36
  _UNKNOWN *v26; // edi@37
  int v28; // eax@50
  int v29; // ecx@55
  int v30; // eax@57
  int v31; // eax@57
  int v32; // eax@58
  int v33; // edx@58
  double v34; // st7@59
  int v35; // edi@63
  int v36; // edi@63
  int v37; // eax@73
  int v38; // eax@78
  int v39; // eax@80
  char v40; // [sp-18h] [bp-70h]@2
  int v41; // [sp-14h] [bp-6Ch]@2
  int v42; // [sp-10h] [bp-68h]@2
  int v43; // [sp-Ch] [bp-64h]@2
  const char *v44; // [sp-8h] [bp-60h]@2
  int v45; // [sp-4h] [bp-5Ch]@2
  int v46; // [sp+Ch] [bp-4Ch]@2
  int v47; // [sp+10h] [bp-48h]@6
  float v48; // [sp+14h] [bp-44h]@8
  float v49; // [sp+18h] [bp-40h]@10
  float v50; // [sp+1Ch] [bp-3Ch]@10
  int v51; // [sp+20h] [bp-38h]@6
  void *v52; // [sp+24h] [bp-34h]@3
  int v53; // [sp+28h] [bp-30h]@8
  int v54; // [sp+2Ch] [bp-2Ch]@10
  int v55; // [sp+30h] [bp-28h]@34
  int v56; // [sp+34h] [bp-24h]@35
  int v57; // [sp+38h] [bp-20h]@36
  int v58; // [sp+3Ch] [bp-1Ch]@8
  int v59; // [sp+40h] [bp-18h]@6
  int v60; // [sp+44h] [bp-14h]@3
  int v61; // [sp+48h] [bp-10h]@4
  int v62; // [sp+4Ch] [bp-Ch]@34
  int v63; // [sp+50h] [bp-8h]@3
  int v64; // [sp+57h] [bp-1h]@2

  if ( !pD3DRenderer->dword_040088 )
  {
    v45 = 73;
    v44 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odbuild.cpp";
    v46 = (int)&v40;
    sub_40E2C8(&v40, "D3D version of RenderBuildings called in software!", (int)&v64);
    sub_466D09(&v46, *(int *)&v40, v41, v42, v43, v44, v45);
  }
  v63 = 0;
  v1 = pGame->class08_obj;
  v60 = 0;
  v52 = (void *)v1;
  result = pClass51_global->pBModels;
  v46 = pClass51_global->uNumBModels;
  if ( pClass51_global->uNumBModels > 0 )
  {
    v2 = pClass51_global->pBModels + 76;
    v61 = pClass51_global->pBModels + 76;
    while ( 1 )
    {
      LOBYTE(v3) = sub_479089(v60, (int)&v63);
      if ( v3 )
      {
        *(_DWORD *)(v2 - 12) |= 1u;
        v5 = *(_DWORD *)v2;
        v4 = *(_DWORD *)(v2 + 8);
        v59 = 0;
        v51 = v4;
        v47 = v5;
        if ( v5 > 0 )
          break;
      }
LABEL_86:
      ++v60;
      v2 += 188;
      result = v60;
      v61 = v2;
      if ( v60 >= v46 )
        return result;
    }
    while ( 1 )
    {
      if ( *(_DWORD *)(v4 + 28) & 0x2000 )
        goto LABEL_85;
      v7 = *(_DWORD *)(v2 - 4);
      v9 = *(_WORD *)(v4 + 32);
      v58 = 0;
      v8 = &array_77EC08[pStruct9_global->dword_00002C];
      v10 = *(_DWORD *)(v7 + 12 * v9 + 8);
      *(_DWORD *)(v8 + 48) = 0;
      LODWORD(v48) = v10;
      v6 = *(_WORD *)(v4 + 272);
      v11 = (*(_BYTE *)(v4 + 29) & 0x40) == 0;
      v53 = *(_WORD *)(v4 + 272);
      if ( !v11 )
      {
        v53 = TextureFrameTable_GetFrame(pTextureFrameTable, v6, pClass24_global->dword_000024);
        v6 = v53;
      }
      v12 = v6 != -1 ? 72 * v6 + 7278780 : 0;
      *(_DWORD *)(v8 + 60) = v12;
      v13 = *(_WORD *)(v6 != -1 ? 72 * v6 + 7278780 + 0x18 : 24);
      v54 = v13;
      v54 = *(_WORD *)(v12 + 26);
      v14 = (*(_BYTE *)(v4 + 28) & 0x10) == 0;
      v50 = 1.0 / (double)v13;
      v49 = 1.0 / (double)v54;
      if ( !v14 )
        *(_DWORD *)(v8 + 48) |= 2;
      if ( *(_BYTE *)(v4 + 30) & 0x40 )
        *(_BYTE *)(v8 + 49) |= 4u;
      v15 = *(_DWORD *)(v4 + 28);
      if ( v15 & 4 )
      {
        *(_BYTE *)(v8 + 49) |= 4u;
      }
      else
      {
        if ( v15 & 0x20 )
          *(_BYTE *)(v8 + 49) |= 8u;
      }
      v16 = *(_DWORD *)(v4 + 28);
      if ( BYTE1(v16) & 8 )
      {
        *(_DWORD *)(v8 + 48) |= 0x2000u;
      }
      else
      {
        if ( v16 & 0x40 )
          *(_BYTE *)(v8 + 49) |= 0x10u;
      }
      v17 = GetTickCount();
      *(_DWORD *)(v8 + 40) = *(_WORD *)(v4 + 274);
      *(_DWORD *)(v8 + 44) = *(_WORD *)(v4 + 276);
      v18 = v17 >> 4;
      if ( *(_DWORD *)(v4 + 8) && (v45 = *(_DWORD *)(v4 + 8), abs(v45) >= 59082) )
      {
        v19 = *(_DWORD *)(v8 + 48);
        if ( BYTE1(v19) & 4 )
          goto LABEL_29;
        if ( BYTE1(v19) & 8 )
        {
LABEL_26:
          *(_DWORD *)(v8 + 44) -= v18 & *(_WORD *)(*(_DWORD *)(v8 + 60) + 34);
          goto LABEL_30;
        }
      }
      else
      {
        v19 = *(_DWORD *)(v8 + 48);
        if ( BYTE1(v19) & 4 )
          goto LABEL_26;
        if ( BYTE1(v19) & 8 )
        {
LABEL_29:
          *(_DWORD *)(v8 + 44) += v18 & *(_WORD *)(*(_DWORD *)(v8 + 60) + 34);
          goto LABEL_30;
        }
      }
LABEL_30:
      if ( BYTE1(v19) & 0x10 )
      {
        *(_DWORD *)(v8 + 40) -= v18 & *(_WORD *)(*(_DWORD *)(v8 + 60) + 32);
      }
      else
      {
        if ( BYTE1(v19) & 0x20 )
          *(_DWORD *)(v8 + 40) += v18 & *(_WORD *)(*(_DWORD *)(v8 + 60) + 32);
      }
      v20 = *(_BYTE *)(v4 + 302);
      v55 = 0;
      v54 = 0;
      v62 = v20;
      if ( v20 > 0 )
      {
       v21 = &array_73D150[0].y;
        v22 = v4 + 72;
        v56 = v20;
        do
        {
          v23 = *(_DWORD *)(v61 - 4) + 12 * *(_WORD *)(v22 - 40);
          *((float *)v21 - 2) = (double)*(signed int *)v23;
          *((float *)v21 - 1) = (double)*(signed int *)(v23 + 4);
          *(float *)v21 = (double)*(signed int *)(v23 + 8);
          v21 = (char *)v21 + 48;
          v57 = *(_DWORD *)(v8 + 40) + *(_WORD *)v22;
          *((float *)v21 - 5) = (double)v57 * v50;
          v24 = *(_DWORD *)(v8 + 44) + *(_WORD *)(v22 + 40);
          v22 += 2;
          v25 = v56-- == 1;
          v57 = v24;
          *((float *)v21 - 4) = (double)v24 * v49;
        }
        while ( !v25 );
        v26 = &array_73D150[0].flt_00000C;
        v56 = v62;
        v48 = (double)SLODWORD(v48);
        do
        {
          if ( v48 == *((float *)v26 - 1) )
            ++v58;
          sub_436523((int)((char *)v26 - 12), 1);
          if ( *(float *)v26 < 8.0 || (double)pStruct9_global->shading_dist_mist < *(float *)v26 )
          {
            if ( *(float *)v26 >= 8.0 )
              v54 = 1;
            else
              v55 = 1;
          }
          else
          {
            class08_sub_436BB7(v52, (int)((char *)v26 - 12), 1, 0);
          }
          v26 = (char *)v26 + 48;
        }
        while ( v56-- != 1 );
        v20 = v62;
      }
      if ( v58 == v20 )
        *(_BYTE *)(v8 + 50) |= 1u;
      v28 = pClass51_global->dword_000D30;
      *(_DWORD *)(v8 + 84) = v4;
      *(_DWORD *)(v8 + 20) = v20;
      *(_BYTE *)(v8 + 89) = 5;
      LODWORD(v48) = -v28;
      v56 = *(_DWORD *)v4;
      v56 = (unsigned __int64)(-v28 * v56) >> 16;
      v58 = *(_DWORD *)(v4 + 4);
      LODWORD(v48) = -pClass51_global->dword_000D34;
      v58 = (unsigned __int64)(-pClass51_global->dword_000D34 * v58) >> 16;
      v57 = *(_DWORD *)(v4 + 8);
      v57 = (unsigned __int64)(-pClass51_global->dword_000D38 * v57) >> 16;
      LODWORD(v48) = v56 + v58 + v57;
      v56 = (unsigned __int64)(1310720i64 * SLODWORD(v48)) >> 16;
      result = 20 - ((signed int)((unsigned __int64)(1310720i64 * SLODWORD(v48)) >> 16) >> 16);
      *(_BYTE *)(v8 + 88) = result;
      if ( result < 0 )
        *(_BYTE *)(v8 + 88) = 0;
      if ( *(_BYTE *)(v8 + 88) > 31 )
        *(_BYTE *)(v8 + 88) = 31;
      if ( pStruct9_global->dword_00002C >= 1999 )
        return result;
      ++pStruct9_global->dword_00002C;
      ++pStruct9_global->dword_000044;
      if ( sub_482170(v4, array_73D150, v8) )
      {
        LOBYTE(v29) = v59;
        v30 = v60;
        *(_BYTE *)(v4 + 305) = 1;
        *(_BYTE *)(v8 + 95) = v29;
        LOWORD(v29) = (unsigned __int8)v29;
        *(_BYTE *)(v8 + 94) = v30;
        v31 = 8 * (v29 | (v30 << 6));
        LOBYTE(v31) = v31 | 6;
        *(_WORD *)(v8 + 80) = v31;
        if ( v20 > 0 )
        {
          v32 = 0;
          v33 = v20;
          do
          {
            v34 = 1.0 / (array_73D150[v32 / 48].flt_00000C + 0.0000001000000011686097);
            memcpy(&array_50AC10[v32 / 48], &array_73D150[v32 / 48], 0x30u);
            --v33;
            array_50AC10[v32 / 48].flt_000020 = v34;
            v32 += 48;
          }
          while ( v33 );
          v4 = v51;
        }
        if ( !(byte_73C84C & 1) )
        {
          byte_73C84C |= 1u;
          sub_49B001(&unk_73C834);
          compile_error;//atexit(loc_4789D4);
        }
        v45 = v4;
        LODWORD(v48) = pGame->class04_obj;
        v36 = LODWORD(v48);
        sub_45CDB7(v4, pGame->class04_obj);
        sub_49BCEB(pClass58_global, v4);
        *(_DWORD *)(v36 + 1587204) = 0;
        v35 = 0;
        if ( dword_F8ADD4 > 0 || dword_DF1BB4 > 0 )
        {
          if ( v55 )
            v35 = 3;
          else
            v35 = v54 != 0 ? 5 : 0;
          sub_49B04D(&unk_73C834, v4, v61 - 8);
          if ( dword_DF1BB4 > 0 )
          {
            v45 = -1;
            v44 = (const char *)v35;
            v43 = 0;
            v42 = array_50AC10;
            v41 = v62;
            sub_49B540(
              pClass58_global,
              31 - *(_BYTE *)(v8 + 88),
              2,
              (int)&unk_73C834,
              v62,
              array_50AC10,
              0,
              *(float *)&v35,
              -1);
          }
        }
        if ( dword_F8ADD4 > 0 )
          sub_45BC07(LODWORD(v48), (int)&dword_F8AD28, (int)&unk_73C834, v62, array_50AC10, 0.0, v35);
        if ( v55 )
        {
          v37 = sub_424CD7(v62);
          goto LABEL_76;
        }
        if ( v54 )
        {
          v37 = sub_424EE0(v62);
LABEL_76:
          *(_DWORD *)(v8 + 20) = v37;
          v62 = v37;
          sub_481E55(v37);
        }
        if ( v62 )
        {
          v38 = *(_DWORD *)(v8 + 48);
          if ( v38 & 2 )
          {
            if ( BYTE1(v38) & 0x3C )
              v39 = uTextureID_WaterTiles[0];
            else
              v39 = uTextureID_WaterTiles[dword_EF5290];
            v45 = *(_DWORD *)(pClass17_Bitmaps_LOD->dword_011BB0 + 4 * v39);
          }
          else
          {
            v45 = *(_DWORD *)(pClass17_Bitmaps_LOD->dword_011BB0 + 4 * v53);
          }
          sub_4A2050(pD3DRenderer, v62, v8, v4, v45);
        }
        goto LABEL_85;
      }
      --pStruct9_global->dword_00002C;
      --pStruct9_global->dword_000044;
LABEL_85:
      ++v59;
      v2 = v61;
      v4 += 308;
      v51 = v4;
      if ( v59 >= v47 )
        goto LABEL_86;
    }
  }
  return result;
}

//----- (00479295) --------------------------------------------------------
signed int __thiscall sub_479295(int this)
{
  int v1; // edi@1
  int v2; // esi@1
  int v3; // eax@4
  int v4; // edx@4
  int v5; // ecx@4
  int v7; // ST14_4@5
  int v8; // ST04_4@5
  int v9; // ecx@5
  int v10; // [sp+Ch] [bp-10h]@8
  int v11; // [sp+10h] [bp-Ch]@8
  int v12; // [sp+14h] [bp-8h]@8
  int v13; // [sp+18h] [bp-4h]@4

  v1 = this;
  v2 = *(_DWORD *)(this + 84);
  if ( !*(_DWORD *)(v2 + 8) )
  {
    v5 = *(_DWORD *)v2;
    v3 = -*(_DWORD *)(v2 + 4);
LABEL_9:
    v4 = 0;
    v13 = 65536;
    goto LABEL_5;
  }
  if ( (*(_DWORD *)v2 || *(_DWORD *)(v2 + 4)) && abs(*(_DWORD *)(v2 + 8)) < 59082 )
  {
    v10 = -*(_DWORD *)(v2 + 4);
    v11 = *(_DWORD *)v2;
    v12 = 0;
    sub_44C362((int)&v10);
    v3 = v10;
    v5 = v11;
    goto LABEL_9;
  }
  v5 = 0;
  v3 = 65536;
  v13 = 0;
  v4 = -65536;
LABEL_5:
  v7 = v13;
  *(_DWORD *)(v1 + 40) = *(_WORD *)(v2 + 274);
  v8 = v5;
  v9 = *(_DWORD *)(v1 + 56);
  *(_DWORD *)(v1 + 44) = *(_WORD *)(v2 + 276);
  class57_sub_48616B(v9, v3, v8, 0, 0, v4, v7);
  return 1;
}

//----- (00479332) --------------------------------------------------------
signed int __cdecl sub_479332()
{
  signed int result; // eax@1
  unsigned int v1; // edi@1
  _UNKNOWN *v2; // esi@2
  char v3; // cl@3
  double v4; // st7@4
  int v5; // eax@6
  float v6; // ST34_4@6
  double v7; // ST24_8@6
  int v8; // eax@11
  int v9; // eax@13
  int v10; // eax@14
  double v11; // st7@17
  float v12; // ST34_4@19
  double v13; // ST1C_8@19
  float v14; // [sp+4h] [bp-34h]@1
  float v15; // [sp+8h] [bp-30h]@1
  float v16; // [sp+Ch] [bp-2Ch]@1
 int i;

  v14 = (double)pClass51_global->dword_000D30 * 0.0000152587890625;
  result = 0;
  v1 = &array_77EC08[pStruct9_global->dword_00002C];
  v15 = (double)pClass51_global->dword_000D34 * 0.0000152587890625;
  v16 = (double)pClass51_global->dword_000D38 * 0.0000152587890625;
  if ( pStruct9_global->dword_00002C > 0)
  {
   i = 0;
   v2 = &array_77EC08[0].ptr_000048;
    while ( 1 )
    {
      v3 = *((_BYTE *)v2 + 5);
      if ( v3 == 5 )
        break;
      if ( v3 == 1 )
      {
        v9 = (unsigned __int16)word_75D514[((*((_DWORD *)v2 - 9) >> 15) & 1)
                                         + 2 * (*((_BYTE *)v2 + 9) + (*((_BYTE *)v2 + 8) << 7))];
        if ( v9 > uNumTerrainNormals - 1 )
          v10 = 0;
        else
          v10 = pTerrainNormals + v9;
        if ( v10 )
        {
          v11 = -(v16 * *(float *)(v10 + 8) + v15 * *(float *)(v10 + 4) + v14 * *(float *)v10);
          if ( v11 < 0.0 )
            v11 = 0.0;
          v12 = v11 * 31.0;
          v13 = v12 + 6.755399441055744e15;
          *((_BYTE *)v2 + 4) = 31 - LOBYTE(v13);
        }
        else
        {
          *((_BYTE *)v2 + 4) = 0;
        }
        if ( *((_BYTE *)v2 + 4) < 0 )
          *((_BYTE *)v2 + 4) = 0;
        goto LABEL_23;
      }
LABEL_24:
      //v2 = (char *)v2 + 268;
      //if ( (unsigned int)((char *)v2 - 84) >= v1 )
      //  return result;
      if (&array_77EC08[i++].array_0000B4[19] >= v1)
         return result;
     v2 = &array_77EC08[i].ptr_000048;
    }

    v4 = ((__int64)(*array_77EC08[i].ptr_000048)[0] * -pClass51_global->dword_000D30 / 65536 +
         (__int64)(*array_77EC08[i].ptr_000048)[1] * -pClass51_global->dword_000D34 / 65536 +
         (__int64)(*array_77EC08[i].ptr_000048)[2] * -pClass51_global->dword_000D38 / 65536) / 65536.0;
    if ( v4 < 0.0 )
      v4 = 0.0;
    v6 = v4 * 31.0;
    v7 = v6 + 6.755399441055744e15;
    v5 = (int)((char *)v2 + 4);
    *((_BYTE *)v2 + 4) = 31 - LOBYTE(v7);
    if ( (char)(31 - LOBYTE(v7)) < 0 )
      *(_BYTE *)v5 = 0;
    if ( *(_BYTE *)v5 > 31 )
      *(_BYTE *)v5 = 31;
    if ( *(_BYTE *)((char *)array_77EC08[i].ptr_000048 + 29) & 0x40 )
    {
      v8 = TextureFrameTable_GetFrame(pTextureFrameTable, *((_WORD *)v2 - 4), pClass24_global->dword_000024);
      *((_DWORD *)v2 - 6) = v8 != -1 ? 72 * v8 + 7278780 : 0;
    }
LABEL_23:
    result = 1;
    goto LABEL_24;
  }
  return result;
}

//----- (00479543) --------------------------------------------------------
void __cdecl sub_479543()
{
  int v0; // esi@1
  double v4; // st5@2
  double v5; // st4@2
  double v6; // st7@2
  float *v7; // esi@3
  int v8; // ebx@4
  int v9; // eax@4
  int v10; // eax@4
  int v11; // ecx@6
  int v12; // edi@6
  signed __int64 v13; // qax@6
  double v14; // st7@6
  int v15; // eax@8
  int v16; // eax@12
  signed int v17; // ecx@13
  signed __int64 v18; // qtt@13
  int v19; // eax@15
  double v20; // st6@15
  double v21; // st7@15
  double v22; // st6@15
  unsigned __int8 v23; // sf@15
  unsigned __int8 v24; // of@15
  char v25; // [sp+14h] [bp-150h]@1
  int v26; // [sp+28h] [bp-13Ch]@2
  int v27; // [sp+2Ch] [bp-138h]@2
  int v28; // [sp+30h] [bp-134h]@2
  int v29; // [sp+34h] [bp-130h]@2
  int v30; // [sp+38h] [bp-12Ch]@2
  int v31; // [sp+3Ch] [bp-128h]@2
  int v32; // [sp+40h] [bp-124h]@2
  int v33; // [sp+4Ch] [bp-118h]@1
  int v34; // [sp+50h] [bp-114h]@1
  __int16 v35; // [sp+60h] [bp-104h]@1
  char v36; // [sp+6Ch] [bp-F8h]@2
  double v37; // [sp+120h] [bp-44h]@4
  float v38; // [sp+128h] [bp-3Ch]@4
  float v39; // [sp+12Ch] [bp-38h]@2
  int v40; // [sp+130h] [bp-34h]@4
  int v41; // [sp+134h] [bp-30h]@1
  int v42; // [sp+138h] [bp-2Ch]@2
  int v43; // [sp+13Ch] [bp-28h]@6
  int v44; // [sp+140h] [bp-24h]@2
  int v45; // [sp+144h] [bp-20h]@1
  int v46; // [sp+148h] [bp-1Ch]@4
  double v47; // [sp+14Ch] [bp-18h]@2
  int v48; // [sp+154h] [bp-10h]@8
  int v49; // [sp+158h] [bp-Ch]@1
  int v50; // [sp+15Ch] [bp-8h]@4
  int v51; // [sp+160h] [bp-4h]@7

  v41 = (signed __int64)((double)(pStruct9_global->dword_000014 * pCamera->dword_000008) / ((double)pStruct9_global->dword_000014 + 8192.0) + (double)class28_global.dword_00002C);
  v0 = pStruct9_global->shading_dist_mist;
  *(float *)&v45 = cos((double)pCamera->sRotationX * 0.003066406352445483) * (double)pStruct9_global->shading_dist_mist;
  v49 = (signed __int64)((double)class28_global.dword_00002C
                       - (double)pStruct9_global->dword_000014
                       / (*(float *)&v45 + 0.0000001000000011686097)
                       * (sin((double)pCamera->sRotationX * 0.003066406352445483) * (double)-v0 - (double)pCamera->dword_000008));
  sub_48607B_MessWithStruct8((int)&v25, pClass57_global);
  class57_sub_48694B(v33);
  v35 = dword_6A0ED8;
  v34 = (signed __int16)dword_6A0ED8 != -1 ? 72 * (signed __int16)dword_6A0ED8 + 7278780 : 0;
  if ( v34 )
  {
    v36 = 0;
    v26 = 4;
    v27 = -class59_SinCos(pClass59_global, pCamera->sRotationX - pClass59_global->uNumTableEntries + 16);
    v28 = 0;
    v29 = -class59_SinCos(pClass59_global, pCamera->sRotationX + 16);
    array_50AC10[0].flt_000018 = class28_global.dword_000010;
    array_50AC10[0].flt_00001C = class28_global.dword_000014;
    array_50AC10[1].flt_000018 = class28_global.dword_000010;
    v4 = (double)v49;
    v31 = 224 * pClass24_global2->dword_000024;
    v32 = 224 * pClass24_global2->dword_000024;
    v39 = v4;
    array_50AC10[1].flt_00001C = v4;
    v5 = (double)class28_global.dword_000018;
    array_50AC10[2].flt_000018 = v5;
    v49 = class28_global.dword_000018 - class28_global.dword_000010;
    v30 = 33554432;
    array_50AC10[2].flt_00001C = v4;
    array_50AC10[3].flt_000018 = v5;
    array_50AC10[3].flt_00001C = class28_global.dword_000014;
    v47 = (double)(class28_global.dword_000018 - class28_global.dword_000010) * memory_4D8410.d_0_5;
    v6 = tan(*(double *)&byte_4D8410[872]);
    v42 = 0;
    v44 = 65536 / (signed int)(signed __int64)(v47 / v6 + memory_4D8410.d_0_5);
    if ( v26 <= 0 )
      goto LABEL_16;
    v7 = &array_50AC10[0].flt_00001C;
    while ( 1 )
    {
      LODWORD(v38) = *(_DWORD *)v7;
      v37 = v38 + 6.755399441055744e15;
      v40 = LODWORD(v37);
      v49 = *(_DWORD *)(v33 + 20);
      v50 = (unsigned __int64)(v49 * v44 * (v41 - LODWORD(v37))) >> 16;
      v9 = v50 + *(_DWORD *)(v33 + 12);
      v50 = v44 * (v41 - LODWORD(v37));
      v46 = v9;
      v49 = *(_DWORD *)(v33 + 32);
      v50 = (unsigned __int64)(v49 * v44 * (v41 - LODWORD(v37))) >> 16;
      HIDWORD(v47) = v50 + *(_DWORD *)(v33 + 24);
      v49 = v29;
      v10 = (unsigned __int64)(v29 * v44 * (v41 - LODWORD(v37))) >> 16;
      v8 = v27 + v10;
      v50 = v27 + v10;
      if ( v27 + v10 > 0 )
      {
        v8 = 0;
        v50 = 0;
      }
      v13 = (signed __int64)*(v7 - 1);
      v49 = v8;
      v14 = *v7 - 1.0;
      v12 = v44 * (class28_global.dword_000028 - v13);
      v45 = -v30;
      v43 = (signed __int64)v14;
      v11 = v44 * (v41 - v43);
      while ( 1 )
      {
        v51 = v11;
        if ( !v8 )
          goto LABEL_12;
        v48 = abs(v45 >> 14);
        v15 = abs(v8);
        if ( v48 <= v15 || v43 <= class28_global.dword_000014 )
        {
          if ( v50 <= 0 )
            break;
        }
        v11 = v51;
LABEL_12:
        v48 = v29;
        v16 = (unsigned __int64)(v29 * v11) >> 16;
        --v43;
        v11 += v44;
        v8 = v27 + v16;
        v50 = v27 + v16;
        v49 = v27 + v16;
      }
      LODWORD(v18) = v45 << 16;
      HIDWORD(v18) = v45 >> 16;
      v51 = v18 / v49;
      v17 = v18 / v49;
      if ( v17 < 0 )
        v17 = pStruct9_global->shading_dist_mist;
      v51 = v12;
      v48 = *(_DWORD *)(v33 + 16);
      v51 = v12;
      v48 = v46 + ((unsigned __int64)(v48 * v12) >> 16);
      v46 = *(_DWORD *)(v33 + 28);
      HIDWORD(v47) += (unsigned __int64)(v46 * v12) >> 16;
      v46 = 224 * pClass24_global2->dword_000024 + ((signed int)((unsigned __int64)(v48 * v17) >> 16) >> 3);
      v51 = (unsigned __int64)(SHIDWORD(v47) * v17) >> 16;
      v19 = v34;
      HIDWORD(v47) = *(_WORD *)(v34 + 24);
      v7 += 12;
      v20 = (double)SHIDWORD(v47) * 65536.0;
      HIDWORD(v47) = 224 * pClass24_global2->dword_000024 + (v51 >> 3);
      ++v42;
      *(v7 - 10) = (double)v46 / v20;
      v21 = (double)SHIDWORD(v47);
      HIDWORD(v47) = *(_WORD *)(v19 + 26);
      v22 = (double)SHIDWORD(v47);
      HIDWORD(v47) = v17 >> 16;
      compile_error;//v24 = __SETO__(v42, v26);
      v23 = v42 - v26 < 0;
      *(v7 - 9) = v21 / (v22 * 65536.0);
      *(v7 - 16) = (double)pStruct9_global->shading_dist_mist;
      *(v7 - 11) = 1.0 / (double)SHIDWORD(v47);
      if ( !(v23 ^ v24) )
      {
LABEL_16:
        sub_4A2DA3(pD3DRenderer, v26, (int)&v25, *(_DWORD *)(pClass17_Bitmaps_LOD->dword_011BB0 + 4 * v35));
        array_50AC10[0].flt_00001C = v39;
        array_50AC10[1].flt_00001C += 30.0;
        array_50AC10[2].flt_00001C += 30.0;
        array_50AC10[3].flt_00001C = v39;
        sub_4A2DA3(pD3DRenderer, v26, (int)&v25, *(_DWORD *)(pClass17_Bitmaps_LOD->dword_011BB0 + 4 * v35));
        return;
      }
    }
  }
}

//----- (00479A53) --------------------------------------------------------
void __fastcall sub_479A53(int a1, int a2)
{
  char v2; // al@1
  signed int v3; // edi@1
  int v4; // esi@1
  signed __int64 v5; // qax@3
  char v6; // cl@3
  double v7; // st7@3
  int v8; // esi@7
  int v9; // eax@7
  int v10; // eax@7
  double v11; // st7@7
  double v12; // st6@7
  int v13; // edx@7
  int v14; // eax@7
  _UNKNOWN *v15; // esi@8
  int v16; // ecx@9
  signed int v17; // ebx@9
  int v18; // edi@9
  int v19; // ecx@9
  int v20; // eax@9
  double v21; // st7@9
  int v22; // ebx@11
  int v23; // eax@14
  signed __int64 v24; // qtt@16
  double v25; // st7@16
  unsigned __int8 v26; // sf@16
  unsigned __int8 v27; // of@16
  int v28; // ecx@17
  _UNKNOWN *v29; // edx@20
  float *v30; // ebx@20
  double v31; // st7@20
  unsigned __int8 v32; // c0@21
  unsigned __int8 v33; // c3@21
  double v34; // st6@23
  float *v36; // esi@30
  int v37; // ecx@31
  int v38; // edi@31
  int v39; // ecx@31
  int v40; // eax@31
  signed __int64 v41; // qax@31
  int v42; // ebx@33
  int v43; // eax@36
  signed __int64 v44; // qtt@39
  int v45; // eax@39
  char v46; // zf@39
  double v47; // st7@39
  double v48; // st7@39
  signed int v49; // edx@40
  _UNKNOWN *v50; // ebx@41
  double v51; // st7@41
  void *v52; // edi@43
  _UNKNOWN *v54; // edx@46
  double v55; // st7@46
  void *v56; // edi@48
  _UNKNOWN *v58; // ebx@52
  unsigned int v59; // eax@53
  char v60; // zf@53
  int v61; // eax@55
  int v62; // ST10_4@55
  int v63; // eax@55
  signed int v64; // [sp-4h] [bp-178h]@17
  int v65; // [sp+0h] [bp-174h]@17
  int v66; // [sp+4h] [bp-170h]@17
  char v67; // [sp+14h] [bp-160h]@6
  int v68; // [sp+28h] [bp-14Ch]@7
  int v69; // [sp+2Ch] [bp-148h]@7
  int v70; // [sp+30h] [bp-144h]@7
  float v71; // [sp+34h] [bp-140h]@7
  int v72; // [sp+38h] [bp-13Ch]@7
  int v73; // [sp+4Ch] [bp-128h]@9
  int v74; // [sp+50h] [bp-124h]@6
  __int16 v75; // [sp+60h] [bp-114h]@6
  char v76; // [sp+6Ch] [bp-108h]@7
  int v77; // [sp+120h] [bp-54h]@7
  double v78; // [sp+124h] [bp-50h]@7
  int v79; // [sp+128h] [bp-4Ch]@1
  int v80; // [sp+12Ch] [bp-48h]@7
  float v81; // [sp+130h] [bp-44h]@7
  __int64 v82; // [sp+134h] [bp-40h]@3
  __int64 v83; // [sp+13Ch] [bp-38h]@3
  int v84; // [sp+144h] [bp-30h]@3
  int X; // [sp+148h] [bp-2Ch]@9
  int v86; // [sp+14Ch] [bp-28h]@7
  float v87; // [sp+150h] [bp-24h]@16
  int v88; // [sp+154h] [bp-20h]@3
  signed int v89; // [sp+158h] [bp-1Ch]@3
  float *v90; // [sp+15Ch] [bp-18h]@9
  int v91; // [sp+160h] [bp-14h]@9
  int v92; // [sp+164h] [bp-10h]@7
  void *v93; // [sp+168h] [bp-Ch]@9
  float v94; // [sp+16Ch] [bp-8h]@3
  int v95; // [sp+170h] [bp-4h]@7

  v4 = dword_6BE644 + 96 * a2;
  v79 = a2;
  v3 = a1;
  v2 = *(_BYTE *)(v4 + 92);
  if ( v2 == 4 || v2 == 3 )
  {
    if ( a1 > 0 )
    {
     v58 = &array_507D30[0].u;
      LODWORD(v94) = a1;
      do
      {
        v83 = (GetTickCount() >> 5) - dword_51B6E8;
        *(float *)v58 = (double)v83 + *(float *)v58;
        *(float *)v58 = *(float *)v58 * 0.25;
        v59 = GetTickCount();
        v58 = (char *)v58 + 48;
        v60 = LODWORD(v94)-- == 1;
        v82 = dword_51B6EC + (v59 >> 5);
        *((float *)v58 - 11) = ((double)v82 + *((float *)v58 - 11)) * 0.25;
      }
      while ( !v60 );
      a2 = v79;
    }
    v61 = 8 * a2;
    LOBYTE(v61) = 8 * a2 | 6;
    v62 = v61;
    v63 = sub_4AE5BA(v4);
    sub_4A2FC0(pD3DRenderer, v3, v4, *(_DWORD *)(pClass17_Bitmaps_LOD->dword_011BB0 + 4 * *(_WORD *)(v4 + 74)), v63, v62, -1, 0);
    return;
  }
  HIDWORD(v83) = pCamera->sRotationX;
  HIDWORD(v82) = pCamera->dword_000008;
  *(float *)&v88 = (double)dword_51B758;
  v84 = (signed __int64)((double)(unk_51B720 * dword_51B6F0) / (((double)unk_51B720 + 16192.0) * 65536.0)
                       + *(float *)&v88);
  v7 = (double)pCamera->sRotationX * 0.003066406352445483;
  *(float *)&v89 = v7;
  v94 = cos(v7) * *(double *)&byte_4D8410[896];
  v5 = (signed __int64)(*(float *)&v88
                      - (double)unk_51B720
                      / ((v94 + 0.0000001000000011686097)
                       * 65535.0)
                      * (sin(*(float *)&v89) * *(double *)&byte_4D8410[888] - (double)SHIDWORD(v82)));
  v6 = *(_BYTE *)(v4 + 92);
  if ( v6 == 4 || v6 == 3 )
    v84 = v5;
  sub_48653D(pClass57_global, 65536, 0, 0, 0, 65536, 0);
  sub_48607B_MessWithStruct8((int)&v67, pClass57_global);
  v75 = *(_WORD *)(v4 + 74);
  v74 = v75 != -1 ? 72 * v75 + 7278780 : 0;
  if ( !v74 )
    return;
  v8 = dword_51B6F8;
  v76 = 0;
  v68 = v3;
  v9 = class59_SinCos(pClass59_global, dword_51B6F8 - pClass59_global->uNumTableEntries + 16);
  v70 = 0;
  v69 = -v9;
  LODWORD(v71) = -class59_SinCos(pClass59_global, v8 + 16);
  v10 = dword_51B73C - dword_51B734;
  memcpy(&array_507D30[v3], array_507D30, sizeof(struct struct14));
  LODWORD(v94) = v10;
  v72 = 33554432;
  v78 = (double)v10 * memory_4D8410.d_0_5;
  v11 = tan(*(double *)&byte_4D8410[872]);
  v86 = 65536 / (signed int)(signed __int64)(v78 / v11 + memory_4D8410.d_0_5);
  LODWORD(v94) = *(_WORD *)(v74 + 24);
  v12 = 1.0 / (double)SLODWORD(v94);
  LODWORD(v94) = *(_WORD *)(v74 + 26);
  v13 = *(_WORD *)(v74 + 32);
  v14 = *(_WORD *)(v74 + 34);
  v81 = v12;
  v77 = 224 * pClass24_global2->dword_000024 & v14;
  v80 = 224 * pClass24_global2->dword_000024 & v13;
  v92 = 0;
  v95 = 0;
  *((float *)&v82 + 1) = 1.0 / (double)SLODWORD(v94);
  if ( v68 <= 0 )
  {
LABEL_17:
    v66 = *(_DWORD *)(pClass17_Bitmaps_LOD->dword_011BB0 + 4 * v75);
    v28 = pD3DRenderer;
    v65 = (int)&v67;
    v64 = v68;
    goto LABEL_18;
  }
  v15 = &array_507D30[0].flt_00001C;
  while ( 2 )
  {
    v19 = v86 * (v84 - (signed __int64)*(float *)v15);
    LODWORD(v94) = *(_DWORD *)(v73 + 20);
    v91 = (unsigned __int64)(SLODWORD(v94) * v19) >> 16;
    v20 = v91 + *(_DWORD *)(v73 + 12);
    v91 = v19;
    v88 = v20;
    LODWORD(v94) = *(_DWORD *)(v73 + 32);
    v91 = (unsigned __int64)(SLODWORD(v94) * v19) >> 16;
    v93 = (void *)v19;
    v89 = v91 + *(_DWORD *)(v73 + 24);
    v94 = v71;
    v93 = (void *)((unsigned __int64)(SLODWORD(v71) * v19) >> 16);
    v18 = v86 * (dword_51B754 - (signed __int64)*((float *)v15 - 1));
    v21 = *(float *)v15 - 1.0;
    v17 = -v72;
    v91 = -v72;
    X = (int)((char *)v93 + v69);
    v90 = (float *)(signed __int64)v21;
    v16 = v86 * (v84 - (_DWORD)v90);
    while ( 1 )
    {
      v93 = (void *)v16;
      if ( !X )
        goto LABEL_14;
      v22 = abs(v17 >> 14);
      if ( v22 <= abs(X) )
        break;
      if ( (signed int)v90 <= class28_global.dword_000014 )
        break;
      v17 = v91;
      v16 = (int)v93;
LABEL_14:
      v94 = v71;
      v93 = (void *)((unsigned __int64)(SLODWORD(v71) * v16) >> 16);
      v23 = (unsigned __int64)(SLODWORD(v71) * v16) >> 16;
      v90 = (float *)((char *)v90 - 1);
      v16 += v86;
      X = v23 + v69;
      v92 = 1;
    }
    if ( !v92 )
    {
      LODWORD(v24) = v91 << 16;
      HIDWORD(v24) = v91 >> 16;
      v93 = (void *)(v24 / X);
      v91 = v18;
      LODWORD(v94) = *(_DWORD *)(v73 + 16);
      v91 = v18;
      v90 = (float *)(v88 + ((unsigned __int64)(SLODWORD(v94) * v18) >> 16));
      LODWORD(v94) = *(_DWORD *)(v73 + 28);
      v89 += (unsigned __int64)(SLODWORD(v94) * v18) >> 16;
      v91 = (unsigned __int64)((signed int)v90 * (signed int)(v24 / X)) >> 16;
      LODWORD(v87) = (unsigned __int64)(v89 * (signed int)(v24 / X)) >> 16;
      v15 = (char *)v15 + 48;
      LODWORD(v94) = v80 + ((signed int)((unsigned __int64)((signed int)v90 * (signed int)(v24 / X)) >> 16) >> 4);
      ++v95;
      v25 = (double)SLODWORD(v94) * 0.00001525902189314365;
      LODWORD(v94) = v77 + ((signed int)((unsigned __int64)(v89 * (signed int)(v24 / X)) >> 16) >> 4);
      compile_error;//v27 = __SETO__(v95, v68);
      v26 = v95 - v68 < 0;
      *((float *)v15 - 10) = v25 * v81;
      *((float *)v15 - 9) = (double)SLODWORD(v94) * 0.00001525902189314365 * *((float *)&v82 + 1);
      *((float *)v15 - 11) = 65536.0 / (double)(signed int)v93;
      if ( !(v26 ^ v27) )
        goto LABEL_17;
      continue;
    }
    break;
  }
  LODWORD(v87) = 0;
  LODWORD(v94) = v90;
  if ( v68 > 0 )
  {
    v31 = (double)(signed int)v90;
    v90 = &array_50AC10[0].flt_00001C;
    v30 = &array_50AC10[0].flt_000018;
    v29 = &array_507D30[1].flt_00001C;
    v93 = array_50AC10;
    v95 = array_507D30;
    v92 = v68;
    do
    {
      v32 = v31 < *((float *)v29 - 12);
      v33 = v31 == *((float *)v29 - 12);
      ++LODWORD(v87);
      memcpy(v93, (const void *)v95, 0x30u);
      v93 = (char *)v93 + 48;
      v90 += 12;
      v30 += 12;
      if ( v32 | v33 || v31 >= *(float *)v29 )
      {
        if ( v31 >= *((float *)v29 - 12) || v31 <= *(float *)v29 )
          goto LABEL_28;
        v34 = (*((float *)v29 - 1) - *((float *)v29 - 13)) * v31 / (*(float *)v29 - *((float *)v29 - 12))
            + *((float *)v29 - 1);
      }
      else
      {
        v34 = (*((float *)v29 - 13) - *((float *)v29 - 1)) * v31 / (*((float *)v29 - 12) - *(float *)v29)
            + *((float *)v29 - 13);
      }
      *v30 = v34;
      v93 = (char *)v93 + 48;
      v30 += 12;
      ++LODWORD(v87);
      *v90 = v31;
      v90 += 12;
LABEL_28:
      v95 += 48;
      v29 = (char *)v29 + 48;
    }
    while ( v92-- != 1 );
  }
  if ( LODWORD(v87) <= 0 )
    goto LABEL_40;
  v36 = &array_50AC10[0].flt_00001C;
  v79 = v91 >> 14;
  HIDWORD(v83) = LODWORD(v87);
  do
  {
    v39 = v86 * (v84 - (signed __int64)*v36);
    v92 = *(_DWORD *)(v73 + 20);
    v95 = (unsigned __int64)(v92 * v39) >> 16;
    v40 = v95 + *(_DWORD *)(v73 + 12);
    v95 = v39;
    v88 = v40;
    v92 = *(_DWORD *)(v73 + 32);
    v95 = (unsigned __int64)(v92 * v39) >> 16;
    v92 = v39;
    v89 = v95 + *(_DWORD *)(v73 + 24);
    v95 = LODWORD(v71);
    v92 = (unsigned __int64)(SLODWORD(v71) * v39) >> 16;
    v38 = v86 * (dword_51B754 - (signed __int64)*(v36 - 1));
    v41 = (signed __int64)(*v36 - 1.0);
    v95 = 0;
    v90 = (float *)v41;
    v37 = v86 * (v84 - v41);
    while ( 1 )
    {
      v92 = v37;
      if ( !X )
        goto LABEL_36;
      v42 = abs(X);
      if ( abs(v79) <= v42 )
        break;
      if ( (signed int)v90 <= class28_global.dword_000014 )
        break;
      v37 = v92;
LABEL_36:
      v92 = LODWORD(v71);
      v43 = (unsigned __int64)(SLODWORD(v71) * v37) >> 16;
      v90 = (float *)((char *)v90 - 1);
      v37 += v86;
      X = v43 + v69;
      v95 = 1;
    }
    if ( v95 )
    {
      v93 = (void *)LODWORD(v71);
      v92 = 2 * (_DWORD)v90;
      v95 = (unsigned __int64)(SLODWORD(v71)
                             * (signed int)(signed __int64)(((double)v84 - ((double)(2 * (_DWORD)v90) - *v36))
                                                          * (double)v86)) >> 16;
      X = v95 + v69;
    }
    LODWORD(v44) = v91 << 16;
    HIDWORD(v44) = v91 >> 16;
    v93 = (void *)(v44 / X);
    v95 = v38;
    v92 = *(_DWORD *)(v73 + 16);
    v95 = (unsigned __int64)(v92 * v38) >> 16;
    v45 = v88 + ((unsigned __int64)(v92 * v38) >> 16);
    v88 = v38;
    v90 = (float *)v45;
    v92 = *(_DWORD *)(v73 + 28);
    v89 += (unsigned __int64)(v92 * v38) >> 16;
    v88 = (unsigned __int64)(v45 * (signed int)(v44 / X)) >> 16;
    v95 = (unsigned __int64)(v89 * (signed int)(v44 / X)) >> 16;
    v36 += 12;
    v92 = v80 + (v88 >> 4);
    v46 = HIDWORD(v83)-- == 1;
    v47 = (double)v92 * 0.00001525902189314365;
    v92 = v77 + ((signed int)((unsigned __int64)(v89 * (signed int)(v44 / X)) >> 16) >> 4);
    *(v36 - 10) = v47 * v81;
    *(v36 - 9) = (double)v92 * 0.00001525902189314365 * *((float *)&v82 + 1);
    v48 = (double)(signed int)v93;
    *(v36 - 16) = 0.0000152587890625 * v48;
    *(v36 - 11) = 65536.0 / v48;
  }
  while ( !v46 );
LABEL_40:
  v49 = 0;
  if ( LODWORD(v87) > 0 )
  {
    v51 = (double)SLODWORD(v94);
    v89 = array_507D30;
    v50 = array_50AC10;
    HIDWORD(v83) = LODWORD(v87);
    do
    {
      if ( v51 >= *((float *)v50 + 7) )
      {
        v52 = (void *)v89;
        ++v49;
        v89 += 48;
        memcpy(v52, v50, 0x30u);
      }
      v50 = (char *)v50 + 48;
    }
    while ( HIDWORD(v83)-- != 1 );
  }
  v68 = v49;
  sub_4A2ED5(pD3DRenderer, v49, (int)&v67, *(_DWORD *)(pClass17_Bitmaps_LOD->dword_011BB0 + 4 * v75));
  v88 = 0;
  if ( LODWORD(v87) > 0 )
  {
    v55 = (double)SLODWORD(v94);
    v89 = array_507D30;
    v54 = array_50AC10;
    v94 = v87;
    do
    {
      if ( v55 <= *((float *)v54 + 7) )
      {
        v56 = (void *)v89;
        ++v88;
        v89 += 48;
        memcpy(v56, v54, 0x30u);
      }
      v54 = (char *)v54 + 48;
    }
    while ( LODWORD(v94)-- != 1 );
  }
  v68 = v88;
  v66 = *(_DWORD *)(pClass17_Bitmaps_LOD->dword_011BB0 + 4 * v75);
  v65 = (int)&v67;
  v64 = v88;
  v28 = pD3DRenderer;
LABEL_18:
  sub_4A2ED5(v28, v64, v65, v66);
}

//----- (0047A825) --------------------------------------------------------
signed int __thiscall sub_47A825(void *this)
{
  signed int v1; // ebx@1
  void *v2; // edi@1

  v1 = 0;
  v2 = this;
  if ( (unsigned int)pParty_global->uCurrentHour >= 1 || (unsigned __int16)sub_449B57((int)byte_ACD71D, 178) )
  {
    v1 = 0;
  }
  else
  {
    if ( (unsigned __int16)sub_449B57((int)byte_ACD71D, 164)
      && (unsigned __int16)sub_449B57((int)byte_ACD71D, 165)
      && (unsigned __int16)sub_449B57((int)byte_ACD71D, 166)
      && (unsigned __int16)sub_449B57((int)byte_ACD71D, 167)
      && (unsigned __int16)sub_449B57((int)byte_ACD71D, 168)
      && (unsigned __int16)sub_449B57((int)byte_ACD71D, 169)
      && (unsigned __int16)sub_449B57((int)byte_ACD71D, 170)
      && (unsigned __int16)sub_449B57((int)byte_ACD71D, 171)
      && (unsigned __int16)sub_449B57((int)byte_ACD71D, 172)
      && (unsigned __int16)sub_449B57((int)byte_ACD71D, 173)
      && (unsigned __int16)sub_449B57((int)byte_ACD71D, 174)
      && (unsigned __int16)sub_449B57((int)byte_ACD71D, 175)
      && (unsigned __int16)sub_449B57((int)byte_ACD71D, 176)
      && (unsigned __int16)sub_449B57((int)byte_ACD71D, 177) )
    {
      v1 = 1;
      *((_BYTE *)v2 + 2) &= 0xDFu;
      return v1;
    }
  }
  *((_BYTE *)v2 + 2) |= 0x20u;
  return v1;
}

//----- (0047A95E) --------------------------------------------------------
void __cdecl sub_47A95E()
{
  int v0; // esi@2
  __int16 v1; // ax@6
  int v2; // ebx@6
  double v3; // st7@7
  int v4; // eax@9
  int v5; // ecx@9
  int v6; // edi@9
  int v7; // eax@9
  int v8; // edx@9
  int v9; // edi@9
  int v10; // eax@9
  int v11; // eax@9
  int v12; // eax@9
  int v13; // ecx@9
  signed int v14; // eax@20
  char v15; // dl@20
  int v16; // ecx@20
  int v17; // eax@23
  int v18; // ecx@24
  int v19; // ecx@24
  int v20; // eax@24
  int v21; // eax@26
  int v22; // ebx@26
  int v23; // eax@30
  int v24; // ebx@31
  signed __int64 v25; // qtt@31
  int v26; // ecx@32
  char *v27; // eax@37
  __int16 v28; // dx@37
  __int16 v29; // cx@37
  int v30; // ecx@37
  int v31; // ebx@37
  int Dst; // [sp+Ch] [bp-98h]@7
  float v33; // [sp+10h] [bp-94h]@7
  float v34; // [sp+14h] [bp-90h]@7
  float v35; // [sp+18h] [bp-8Ch]@7
  float v36; // [sp+1Ch] [bp-88h]@7
  float v37; // [sp+20h] [bp-84h]@7
  float v38; // [sp+24h] [bp-80h]@7
  int v39; // [sp+28h] [bp-7Ch]@7
  int v40; // [sp+2Ch] [bp-78h]@7
  int v41; // [sp+30h] [bp-74h]@7
  float v42; // [sp+34h] [bp-70h]@7
  int v43; // [sp+74h] [bp-30h]@9
  int v44; // [sp+78h] [bp-2Ch]@9
  int v45; // [sp+7Ch] [bp-28h]@1
  int v46; // [sp+80h] [bp-24h]@9
  int v47; // [sp+84h] [bp-20h]@9
  int v48; // [sp+88h] [bp-1Ch]@9
  int v49; // [sp+8Ch] [bp-18h]@24
  int v50; // [sp+90h] [bp-14h]@24
  int v51; // [sp+94h] [bp-10h]@24
  int v52; // [sp+98h] [bp-Ch]@9
  int v53; // [sp+9Ch] [bp-8h]@9
  int v54; // [sp+A0h] [bp-4h]@22

  v45 = 0;
  if ( (signed int)dword_69ADD0 > 0 )
  {
   v0 = (int)&array_6836D0[0].sPosY;
    do
    {
      if ( (!(*(_BYTE *)(v0 - 6) & 0x40) || sub_47A825((void *)(v0 - 8))) && !(*(_BYTE *)(v0 - 6) & 0x20) )
      {
        v2 = pDecorationDescriptionList->pDescriptions + 84 * *(_WORD *)(v0 - 8);
        v1 = *(_WORD *)(v2 + 74);
        if ( (_BYTE)v1 >= 0 )
        {
          if ( !(v1 & 0x22) )
          {
            v7 = *(_DWORD *)(v0 - 4);
            v8 = *(_DWORD *)(v0 + 4);
            v9 = pClass24_global2->dword_000024;
            v44 = *(_DWORD *)v0;
            v43 = v7;
            v46 = v8;
            v10 = abs(v7 + v44);
            v11 = CSpriteFrameTable_fn1(pSpriteFrameTable, *(_WORD *)(v2 + 72), v9 + v10);
            v6 = v11;
            v52 = *(_DWORD *)(v11 + 44);
            v53 = *(_WORD *)(v11 + 48);
            v12 = sub_45281E(pClass59_global, *(_DWORD *)(v0 - 4) - pCamera->dword_000000, *(_DWORD *)v0 - pCamera->dword_000004);
            v13 = *(_DWORD *)(v0 + 8);
            v47 = v12;
            v4 = v52;
            v48 = 0;
            v5 = ((pClass59_global->dword_001860 + (pClass59_global->dword_001860 >> 3) + v13 - v47) >> 8) & 7;
            v47 = v5;
            if ( v52 & 2 )
              v48 = 2;
            if ( (256 << v5) & v52 )
              v48 |= 4u;
            if ( v4 & 0x40000 )
              v48 |= 0x40u;
            if ( v4 & 0x20000 )
              LOBYTE(v48) = v48 | 0x80;
            if ( v53 )
            {
              if ( pD3DRenderer->dword_040088 && pD3DRenderer->bUseColoredLights )
              {
                v16 = *(_BYTE *)(v2 + 80);
                v15 = *(_BYTE *)(v2 + 81);
                v14 = *(_BYTE *)(v2 + 82);
              }
              else
              {
                v14 = 255;
                v16 = 255;
                v15 = -1;
              }
              v54 = v14;
              sub_4AD3C8_MaybePlaceStationaryLights((int)&unk_5187F0, v43, v44, v46 + *(_WORD *)(v2 + 66) / 2, v53, v16, v15, v14, byte_4E94D0);
            }
            v17 = (v43 - pCamera->dword_000000) << 16;
            if (pCamera->sRotationX)
            {
              v50 = (v44 - pCamera->dword_000004) << 16;
              v19 = ((unsigned __int64)(v17 * pStruct9_global->camera_rotation_y_int_cosine) >> 16) + ((unsigned __int64)(v50 * pStruct9_global->camera_rotation_y_int_sine) >> 16);
              v52 = v19;
              v54 = (unsigned __int64)(v17 * pStruct9_global->camera_rotation_y_int_sine) >> 16;
              v53 = (unsigned __int64)(v50 * pStruct9_global->camera_rotation_y_int_cosine) >> 16;
              v50 = (v46 - pCamera->dword_000008) << 16;
              v51 = (unsigned __int64)(v50 * pStruct9_global->camera_rotation_x_int_sine) >> 16;
              v20 = (unsigned __int64)(v19 * pStruct9_global->camera_rotation_x_int_cosine) >> 16;
              v18 = v20 + ((unsigned __int64)(v50 * pStruct9_global->camera_rotation_x_int_sine) >> 16);
              v49 = v20 + ((unsigned __int64)(v50 * pStruct9_global->camera_rotation_x_int_sine) >> 16);
              if ( v18 >= 262144 && v18 <= pStruct9_global->shading_dist_mist << 16 )
              {
                v22 = v53 - v54;
                v51 = v53 - v54;
                v53 = (unsigned __int64)(v52 * pStruct9_global->camera_rotation_x_int_sine) >> 16;
                v54 = (unsigned __int64)(v50 * pStruct9_global->camera_rotation_x_int_cosine) >> 16;
                v21 = ((unsigned __int64)(v50 * pStruct9_global->camera_rotation_x_int_cosine) >> 16) - v53;
LABEL_30:
                v52 = v21;
                v50 = 2 * abs(v18);
                v23 = abs(v22);
                if ( v50 >= v23 )
                {
                  LODWORD(v25) = 0;
                  HIDWORD(v25) = pStruct9_global->dword_000014 << 16 >> 16;
                  v53 = v25 / v49;
                  v24 = class28_global.dword_000028 - ((signed int)(((unsigned __int64)(v25 / v49 * v51) >> 16) + 32768) >> 16);
                  v54 = (unsigned __int64)(v53 * v52) >> 16;
                  v51 = v25 / v49;
                  v50 = class28_global.dword_00002C - ((signed int)(((unsigned __int64)(v53 * v52) >> 16) + 32768) >> 16);
                  v52 = *(_DWORD *)(v6 + 40);
                  v51 = (unsigned __int64)(v52 * (signed int)(v25 / v49)) >> 16;
                  v47 = v6 + 2 * v47 + 24;
                  if ( pD3DRenderer->dword_040088 )
                  {
                    v26 = v51;
                    v52 = *(_DWORD *)(pClass17_Sprites_LOD->dword_00ECB0 + 40 * *(_WORD *)v47 + 24) >> 1;
                    v54 = (unsigned __int64)(v52 * v51) >> 16;
                  }
                  else
                  {
                    v26 = v51;
                    compile_error;//v52 = pClass17_Sprites_LOD->array_00024C[20 * *(_WORD *)v47] >> 1;
                    v54 = (unsigned __int64)(v52 * v51) >> 16;
                  }
                  if ( v54 + v24 >= class28_global.dword_000010 && v24 - v54 <= class28_global.dword_000018 )
                  {
                    if ( dword_5187E0 >= 500 )
                      return;
                    v27 = &array_512250[dword_5187E0++];
                    ++dword_5187EC;
                    *((_WORD *)v27 + 12) = *(_WORD *)v47;
                    v28 = *(_WORD *)(v6 + 52);
                    *(_DWORD *)v27 = v26;
                    *((_DWORD *)v27 + 1) = v26;
                    v29 = v48;
                    *((_WORD *)v27 + 19) = v24;
                    HIBYTE(v29) |= 2;
                    *((_WORD *)v27 + 13) = v28;
                    *((_WORD *)v27 + 15) = v29;
                    *((_WORD *)v27 + 16) = v43;
                    *((_WORD *)v27 + 17) = v44;
                    *((_WORD *)v27 + 18) = v46;
                    *((_WORD *)v27 + 20) = v50;
                    HIWORD(v30) = HIWORD(v49);
                    LOWORD(v30) = 0;
                    v31 = v30 + (8 * v45 | 5);
                    *((_WORD *)v27 + 14) = 0;
                    *((_DWORD *)v27 + 4) = v31;
                    *((_WORD *)v27 + 21) = 0;
                    *((_DWORD *)v27 + 12) = v6;
                    *((_DWORD *)v27 + 11) = 0;
                  }
                }
                goto LABEL_38;
              }
            }
            else
            {
              v52 = (v43 - pCamera->dword_000000) << 16;
              v50 = (v44 - pCamera->dword_000004) << 16;
              v54 = (unsigned __int64)(v17 * pStruct9_global->camera_rotation_y_int_cosine) >> 16;
              v53 = (unsigned __int64)(v50 * pStruct9_global->camera_rotation_y_int_sine) >> 16;
              v18 = v54 + ((unsigned __int64)(v50 * pStruct9_global->camera_rotation_y_int_sine) >> 16);
              v49 = v54 + ((unsigned __int64)(v50 * pStruct9_global->camera_rotation_y_int_sine) >> 16);
              if ( v18 >= 262144 && v18 <= pStruct9_global->shading_dist_mist << 16 )
              {
                v53 = (unsigned __int64)(v52 * pStruct9_global->camera_rotation_y_int_sine) >> 16;
                v54 = (unsigned __int64)(v50 * pStruct9_global->camera_rotation_y_int_cosine) >> 16;
                v22 = ((unsigned __int64)(v50 * pStruct9_global->camera_rotation_y_int_cosine) >> 16) - v53;
                v51 = ((unsigned __int64)(v50 * pStruct9_global->camera_rotation_y_int_cosine) >> 16) - v53;
                v21 = (v46 - pCamera->dword_000008) << 16;
                goto LABEL_30;
              }
            }
          }
        }
        else
        {
          memset(&Dst, 0, 0x68u);
          v3 = (double)*(signed int *)(v0 - 4);
          Dst = 1036;
          v39 = 16727070;
          v33 = v3;
          v34 = (double)*(signed int *)v0;
          v35 = (double)*(signed int *)(v0 + 4);
          v36 = 0.0;
          v37 = 0.0;
          v38 = 0.0;
          v42 = 1.0;
          v40 = (rand() & 0x80) + 128;
          v41 = class17_LoadTexture(pClass17_Bitmaps_LOD, "effpar01", 0);
          sub_48AB23(pGame->class02_obj, (int)&Dst);
        }
      }
LABEL_38:
      ++v45;
      v0 += 32;
    }
    while ( v45 < (signed int)dword_69ADD0 );
  }
}

//----- (0047BC6F) --------------------------------------------------------
char *__fastcall sub_47BC6F(int a1, int a2, signed int a3, int a4)
{
  int v4; // ebx@1
  int v6; // edx@4
  int v7; // ecx@5
  int v8; // eax@6
  signed __int64 v9; // qtt@11
  int v10; // eax@12
  int v11; // esi@17
  signed __int64 v12; // qtt@19
  double v13; // ST10_8@19
  int v14; // edi@25
  signed int v15; // edx@26
  signed __int64 v16; // qtt@29
  signed int v17; // eax@30
  int v18; // [sp+10h] [bp-8h]@1
  float v19; // [sp+20h] [bp+8h]@19

  v4 = a2;
  v18 = a2;
  if ( dword_AE30F4 )
    return sub_47BE67(a2);
  if ( !struct_6BD080.dword_000FA4 )
  {
    if ( dword_6BE030 & 1 )
    {
      v14 = dword_6BE040 << 16;
      if ( a3 >= dword_6BE040 << 16 )
      {
        if ( a3 <= dword_6BE044 << 16 )
        {
          LODWORD(v16) = (a3 - v14) << 16;
          HIDWORD(v16) = (a3 - v14) >> 16;
          v15 = (unsigned __int64)(27 * v16 / ((dword_6BE044 - dword_6BE040) << 16)) >> 16;
        }
        else
        {
          v15 = 27;
        }
      }
      else
      {
        v15 = 0;
      }
      v17 = sub_43F55F(a1, v15);
      if ( v17 > 27 )
        v17 = 27;
      if ( !a3 )
        v17 = 27;
      v7 = v18;
      v6 = v17;
      return sub_47BE72(v7, v6, 1);
    }
    v11 = a4;
    if ( a4 < 0 )
      v11 = 0;
    LODWORD(v12) = a3 << 16;
    HIDWORD(v12) = a3 >> 16;
    v19 = (double)(signed int)(((unsigned __int64)(11 * v12 / (pStruct9_global->shading_dist_shade << 16)) >> 16) + 20) * flt_6BD074;
    v13 = v19 + 6.755399441055744e15;
    v10 = sub_43F55F(a1, LODWORD(v13) + v11);
    if ( v10 > 27 )
      v10 = 27;
    if ( v10 < a4 )
      v10 = a4;
    if ( v10 > pClass51_global->dword_000CBC )
      v10 = pClass51_global->dword_000CBC;
    return sub_41F50D(v4, v10, 1);
  }
  v6 = 0;
  if ( struct_6BD080.dword_000FA4 == 1 )
  {
    v8 = 67108864;
    if ( qword_ACD944 > 0 )
      v8 = (unsigned __int16)word_ACD94C << 26;
    if ( a3 <= v8 )
    {
      if ( a3 > 0 )
      {
        LODWORD(v9) = a3 << 16;
        HIDWORD(v9) = a3 >> 16;
        v6 = (unsigned __int64)(27 * v9 / v8) >> 16;
      }
    }
    else
    {
      v6 = 27;
    }
    v10 = sub_43F55F(a1, v6);
    if ( v10 > 27 || !a3 )
      v10 = 27;
    return sub_41F50D(v4, v10, 1);
  }
  v7 = 0;
  return sub_47BE72(v7, v6, 1);
}

//----- (0047BE67) --------------------------------------------------------
char *__fastcall sub_47BE67(int a1)
{
  return (char *)&unk_9A6798 + 16384 * a1;
}

//----- (0047BE72) --------------------------------------------------------
char *__fastcall sub_47BE72(int a1, int a2, char a3)
{
  int v3; // eax@4

  if ( a3 & 2 || byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3618) & 4 )
    v3 = 32 * a1 + a2 + 3275;
  else
    v3 = 32 * a1 + a2 + 1675;
  return (char *)&class35_obj + 512 * v3;
}

//----- (0047BEB1) --------------------------------------------------------
int __fastcall sub_47BEB1(signed int a1, int a2, int a3, int a4, int a5, int *a6, int a7, int a8)
{
  signed int v8; // edx@1
  int v9; // ebx@1
  int v10; // eax@5
  signed int v11; // eax@9
  signed int v12; // eax@15
  signed __int64 v13; // qtt@21
  int v14; // ecx@30
  int *v15; // edi@30
  int v16; // ebx@32
  signed __int64 v17; // qtt@37
  double v18; // ST10_8@37
  double v19; // ST10_8@38
  int v20; // edi@39
  int result; // eax@46
  int v22; // eax@48
  signed int v23; // edx@51
  signed __int64 v24; // qtt@51
  signed int v25; // ecx@51
  signed int v26; // [sp+14h] [bp-4h]@1
  float v27; // [sp+28h] [bp+10h]@37
  float v28; // [sp+28h] [bp+10h]@38
  int v29; // [sp+2Ch] [bp+14h]@37

  v9 = a2;
  v8 = a1;
  v26 = a1;
  if ( dword_AE30F4 )
  {
    *(_DWORD *)a5 = -1;
    *a6 = -1;
    *(_BYTE *)a7 = 1;
LABEL_46:
    result = a8;
    *(_BYTE *)a8 = 0;
    return result;
  }
  if ( a1 < 0 )
  {
    v26 = *(_DWORD *)(v9 + 52) << 16;
    v8 = *(_DWORD *)(v9 + 52) << 16;
  }
  v10 = struct_6BD080.dword_000FA4;
  if ( byte_6BE3C4 == 1 )
    v10 = 0;
  if ( !v10 )
  {
    if ( !(dword_6BE030 & 1) && !byte_6BE3C4 )
    {
      v14 = a5;
      v15 = a6;
      if ( !v8 )
      {
        *(_DWORD *)a5 = 31;
        *a6 = -1;
      }
      v16 = *(_BYTE *)(v9 + 88) - a3;
      if ( v16 >= 0 )
      {
        if ( v16 > 27 )
          v16 = 27;
      }
      else
      {
        v16 = 0;
      }
      *a6 = 27;
      if ( a4 )
      {
        v28 = flt_6BD074 * 27.0;
        v19 = v28 + 6.755399441055744e15;
        v29 = LODWORD(v19);
      }
      else
      {
        LODWORD(v17) = v8 << 16;
        HIDWORD(v17) = v8 >> 16;
        v27 = (double)(signed int)(((unsigned __int64)(v17 / (pStruct9_global->shading_dist_shade << 16) * (31 - *a6)) >> 16) + *a6)
            * flt_6BD074;
        v18 = v27 + 6.755399441055744e15;
        v29 = LODWORD(v18);
      }
      *(_DWORD *)v14 = v16 + v29;
      v20 = *v15;
      if ( v16 + v29 > v20 )
        *(_DWORD *)v14 = v20;
      if ( *(_DWORD *)v14 < v16 )
        *(_DWORD *)v14 = v16;
      if ( *(_DWORD *)v14 > pClass51_global->dword_000CBC )
        *(_DWORD *)v14 = pClass51_global->dword_000CBC;
      goto LABEL_45;
    }
    if ( v8 >= dword_6BE040 << 16 )
    {
      if ( v8 <= dword_6BE044 << 16 )
      {
        v23 = v8 - (dword_6BE040 << 16);
        LODWORD(v24) = v23 << 16;
        HIDWORD(v24) = v23 >> 16;
        v25 = (unsigned __int64)(27 * v24 / ((dword_6BE044 - dword_6BE040) << 16)) >> 16;
        v22 = a5;
        *(_DWORD *)a5 = v25;
        if ( v25 > 27 )
          goto LABEL_54;
        v8 = v26;
      }
      else
      {
        v22 = a5;
        *(_DWORD *)a5 = 27;
      }
    }
    else
    {
      v22 = a5;
      *(_DWORD *)a5 = 0;
    }
    if ( v8 )
    {
LABEL_55:
      if ( a4 )
        *(_DWORD *)v22 = 31;
      *a6 = 31;
      *(_BYTE *)a7 = 0;
      goto LABEL_59;
    }
LABEL_54:
    *(_DWORD *)v22 = 27;
    goto LABEL_55;
  }
  if ( v10 == 1 )
  {
    v11 = 1;
    if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 0x10 )
    {
      v12 = 0;
    }
    else
    {
      if ( qword_ACD944 > 0 )
      {
        if ( qword_ACD944 <= 0 )
          v11 = 0;
        else
          v11 = (unsigned __int16)word_ACD94C;
      }
      v12 = v11 << 26;
    }
    if ( a4 )
      goto LABEL_24;
    if ( v8 <= v12 )
    {
      if ( v8 > 0 )
      {
        LODWORD(v13) = v8 << 16;
        HIDWORD(v13) = v8 >> 16;
        v8 = v26;
        *(_DWORD *)a5 = (unsigned __int64)(27 * v13 / v12) >> 16;
      }
      if ( *(_DWORD *)a5 > 27 )
        goto LABEL_24;
    }
    else
    {
      *(_DWORD *)a5 = 27;
    }
    if ( v8 )
    {
LABEL_25:
      if ( *(_BYTE *)(v9 + 50) & 4 )
        *(_DWORD *)a5 = 27;
      *a6 = 27;
LABEL_45:
      *(_BYTE *)a7 = 0;
      goto LABEL_46;
    }
LABEL_24:
    *(_DWORD *)a5 = 27;
    goto LABEL_25;
  }
  *(_DWORD *)a5 = -1;
  *a6 = -1;
  *(_BYTE *)a7 = 1;
LABEL_59:
  result = a8;
  *(_BYTE *)a8 = 1;
  return result;
}

//----- (0047C178) --------------------------------------------------------
char *__fastcall sub_47C178(signed int a1, int a2, int a3, int a4)
{
  int v4; // esi@1
  char *result; // eax@2
  int v6; // [sp+4h] [bp-8h]@3
  int v7; // [sp+8h] [bp-4h]@3

  v4 = a2;
  if ( dword_AE30F4 )
  {
    result = sub_47BE67(*(_WORD *)(*(_DWORD *)(a2 + 60) + 38));
  }
  else
  {
    sub_47BEB1(a1, a2, a3, a4, (int)&v6, &v7, (int)((char *)&a3 + 3), (int)((char *)&a4 + 3));
    result = sub_47C1CA(v4, SBYTE3(a4), v6, v7);
  }
  return result;
}

//----- (0047C1CA) --------------------------------------------------------
char *__fastcall sub_47C1CA(int a1, char a2, int a3, signed int a4)
{
  int v4; // esi@1
  char *result; // eax@2
  int v6; // edx@3
  int v7; // ecx@8
  int v8; // [sp+4h] [bp-8h]@1
  char v9; // [sp+8h] [bp-4h]@1

  v9 = a2;
  v4 = a1;
  v8 = 1;
  if ( dword_AE30F4 )
  {
    result = sub_47BE67(*(_WORD *)(*(_DWORD *)(a1 + 60) + 38));
  }
  else
  {
    v6 = sub_44EC23(pGame, a1, (int)&v8, a4);
    if ( v6 == -1 )
      v6 = a3;
    if ( v9 == 1 )
    {
      if ( v6 != -1 || a4 != -1 )
      {
        v7 = *(_WORD *)(*(_DWORD *)(v4 + 60) + 38);
      }
      else
      {
        v6 = 0;
        v7 = 0;
      }
      result = sub_47BE72(v7, v6, v8);
    }
    else
    {
      result = sub_41F50D(*(_WORD *)(*(_DWORD *)(v4 + 60) + 38), v6, v8);
    }
  }
  return result;
}

//----- (0047C24C) --------------------------------------------------------
char *__fastcall sub_47C24C(int a1, int a2, int a3, char a4)
{
  int v4; // esi@1
  signed int v5; // eax@2
  int v7; // [sp+4h] [bp-4h]@1

  v4 = a2;
  v7 = 1;
  if ( a4 )
  {
    v5 = sub_44ED0A(pGame, a1, (int)&v7, 31);
    if ( v5 != -1 )
      a3 = v5;
  }
  return sub_41F50D(v4, a3, v7);
}

//----- (0047C28C) --------------------------------------------------------
char *__fastcall sub_47C28C(int a1, char a2, signed int a3, signed int a4)
{
  int v4; // esi@1
  char *result; // eax@2
  signed int v6; // eax@3
  int v7; // ecx@8
  int v8; // [sp+4h] [bp-8h]@1
  char v9; // [sp+8h] [bp-4h]@1

  v9 = a2;
  v4 = a1;
  v8 = 1;
  if ( dword_AE30F4 )
  {
    result = (char *)&unk_9A6798 + 16384 * *(_WORD *)(*(_DWORD *)(a1 + 60) + 38);
  }
  else
  {
    v6 = sub_44EC23(pGame, a1, (int)&v8, a4);
    if ( v6 != -1 )
      a3 = v6;
    if ( v9 == 1 )
    {
      if ( a3 != -1 || a4 != -1 )
        v7 = *(_WORD *)(*(_DWORD *)(v4 + 60) + 38);
      else
        v7 = 0;
      result = sub_47C30E(v7, v8);
    }
    else
    {
      result = sub_47C33F(*(_WORD *)(*(_DWORD *)(v4 + 60) + 38), v8);
    }
  }
  return result;
}

//----- (0047C30E) --------------------------------------------------------
char *__fastcall sub_47C30E(int a1, char a2)
{
  char *result; // eax@4

  if ( a2 & 2 || byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3618) & 4 )
    result = (char *)&unk_9A6798 + 16384 * a1;
  else
    result = (char *)&unk_8DE798 + 16384 * a1;
  return result;
}

//----- (0047C33F) --------------------------------------------------------
char *__fastcall sub_47C33F(int a1, char a2)
{
  char *result; // eax@4

  if ( a2 & 2 || byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3618) & 4 )
    result = (char *)&unk_9A6798 + 16384 * a1;
  else
    result = (char *)&unk_816798 + 16384 * a1;
  return result;
}

//----- (0047C370) --------------------------------------------------------
unsigned int __cdecl sub_47C370()
{
  unsigned int result; // eax@2
  signed __int64 v1; // qax@5

  if ( byte_6BE3C4 )
  {
    result = -14315684;
  }
  else
  {
    if ( dword_6BE030 & 1 )
    {
      if ( struct_6BD080.dword_000FA4 )
      {
        result = (struct_6BD080.dword_000FA4 != 1 ? (int)&unk_E0E0E1 : 0) - 14737633;
      }
      else
      {
        v1 = (signed __int64)((1.0 - flt_6BD074) * 200.0 + flt_6BD074 * 31.0);
        result = v1 | (((_DWORD)v1 | (((_DWORD)v1 | 0xFFFFFF00u) << 8)) << 8);
      }
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (0047C3D7) --------------------------------------------------------
int __fastcall sub_47C3D7(int a1, int a2, float a3)
{
  int v3; // ecx@1
  signed int v5; // esi@10
  double v6; // st7@10
  signed int v7; // ecx@11
  double v8; // st6@12
  double v9; // st7@15
  double v10; // st6@16
  float v11; // ST14_4@17
  double v12; // ST08_8@17

  v3 = struct_6BD080.dword_000FA4;
  if ( byte_6BE3C4 == 1 )
    v3 = 0;
  if ( dword_AE30F4 || !(dword_6BE030 & 1) && !byte_6BE3C4 )
    return -16777216;
  if ( v3 )
  {
    if ( v3 != 1 )
      return 0;
    v6 = (double)dword_6BE040;
    v5 = 216;
    if ( a3 < v6 )
      goto LABEL_11;
    v8 = (double)dword_6BE044;
    if ( a3 > v8 )
    {
LABEL_13:
      v7 = v5;
      goto LABEL_19;
    }
    v7 = (signed __int64)((a3 - v6) / (v8 - v6) * 216.0);
  }
  else
  {
    v9 = (double)dword_6BE040;
    v5 = 216;
    if ( a3 < v9 )
    {
LABEL_11:
      v7 = 0;
      goto LABEL_19;
    }
    v10 = (double)dword_6BE044;
    if ( a3 > v10 )
      goto LABEL_13;
    v11 = (a3 - v9) * 216.0 / (v10 - v9);
    v12 = v11 + 6.755399441055744e15;
    v7 = LODWORD(v12);
  }
  if ( v7 > v5 )
  {
LABEL_20:
    v7 = v5;
    goto LABEL_21;
  }
LABEL_19:
  if ( a3 == 0.0 )
    goto LABEL_20;
LABEL_21:
  if ( a2 )
    v7 = 248;
  return (-1 - v7) << 24;
}

//----- (0047C4FC) --------------------------------------------------------
signed int __fastcall sub_47C4FC(int a1, int a2, float a3, int a4, int a5)
{
  signed int v5; // edx@1
  int v6; // esi@1
  signed int result; // eax@2
  int v8; // eax@3
  double v9; // st7@12
  double v10; // ST0C_8@18
  int v11; // ecx@29
  signed int v12; // edi@29
  double v13; // ST0C_8@34
  double v14; // ST0C_8@35
  double v15; // st7@45
  double v16; // ST0C_8@45
  double v17; // ST0C_8@45
  int v18; // ST14_4@45
  double v19; // ST0C_8@45
  signed int v20; // [sp+10h] [bp-4h]@10
  float v21; // [sp+1Ch] [bp+8h]@34
  float v22; // [sp+1Ch] [bp+8h]@35
  float v23; // [sp+1Ch] [bp+8h]@45
  float v24; // [sp+1Ch] [bp+8h]@45
  float v25; // [sp+20h] [bp+Ch]@18
  int v26; // [sp+20h] [bp+Ch]@34
  float v27; // [sp+20h] [bp+Ch]@45
  float v28; // [sp+20h] [bp+Ch]@45
  int v29; // [sp+24h] [bp+10h]@45

  v6 = a2;
  v5 = 0;
  if ( dword_6BE360 == 1 )
    return 8 * (31 - a1) | ((8 * (31 - a1) | ((31 - a1) << 11)) << 8);
  v8 = struct_6BD080.dword_000FA4;
  if ( byte_6BE3C4 == 1 )
    v8 = 0;
  if ( dword_AE30F4 )
    return 16711680;
  if ( v8 )
  {
    if ( v8 != 1 )
      return 0;
    v20 = 1;
    if ( qword_ACD944 > 0 )
      v20 = (unsigned __int16)word_ACD94C;
    v9 = (double)v20 * 1024.0;
    if ( a4 )
      goto LABEL_20;
    if ( a3 <= v9 )
    {
      if ( a3 > 0.0 )
      {
        v25 = a3 * 216.0 / v9;
        v10 = v25 + 6.755399441055744e15;
        v5 = LODWORD(v10);
        if ( LODWORD(v10) > 216 )
          goto LABEL_20;
      }
    }
    else
    {
      v5 = 216;
    }
    if ( a3 != 0.0 )
    {
LABEL_21:
      if ( a5 )
        v5 = 8 * sub_43F55F(a5, v5 >> 3);
      if ( v5 > 216 )
        v5 = 216;
      return (255 - v5) | ((255 - v5) << 16) | ((255 - v5) << 8);
    }
LABEL_20:
    v5 = 216;
    goto LABEL_21;
  }
  if ( a3 == 0.0 )
  {
    result = (signed int)&unk_F8F8F8;
  }
  else
  {
    v11 = 8 * (a1 - v6);
    v12 = v11;
    if ( v11 >= 0 )
    {
      if ( v11 > 216 )
        v12 = 216;
    }
    else
    {
      v12 = 0;
    }
    if ( a4 )
    {
      v22 = flt_6BD074 * 216.0;
      v14 = v22 + 6.755399441055744e15;
      v26 = LODWORD(v14);
    }
    else
    {
      v21 = (a3 / (double)pStruct9_global->shading_dist_shade * 32.0 + 216.0) * flt_6BD074;
      v13 = v21 + 6.755399441055744e15;
      v26 = LODWORD(v13);
    }
    v5 = v26 + v12;
    if ( a5 )
      v5 = 8 * sub_43F55F(a5, v5 >> 3);
    if ( v5 > 216 )
      v5 = 216;
    if ( v5 < v12 )
      v5 = v12;
    if ( v5 > 8 * pClass51_global->dword_000CBC )
      v5 = 8 * pClass51_global->dword_000CBC;
    if ( !byte_6BE3C4 )
      return (255 - v5) | ((255 - v5) << 16) | ((255 - v5) << 8);
    v15 = (double)(255 - v5) * 0.003921568859368563;
    v23 = v15;
    v27 = v15 * 16.0;
    v16 = v27 + 6.755399441055744e15;
    v29 = LODWORD(v16);
    v28 = v23 * 194.0;
    v17 = v28 + 6.755399441055744e15;
    v18 = LODWORD(v17);
    v24 = v23 * 153.0;
    v19 = v24 + 6.755399441055744e15;
    result = LODWORD(v19) | ((v18 | (v29 << 8)) << 8);
  }
  return result;
}

//----- (0047C794) --------------------------------------------------------
int __thiscall sub_47C794(int this)
{
  int result; // eax@1

  result = this;
  *(_DWORD *)this = 0;
  *(_DWORD *)(this + 4) = 0;
  *(_DWORD *)(this + 12) = 0;
  *(_WORD *)(this + 16) = 0;
  *(_WORD *)(this + 18) = 0;
  return result;
}

//----- (0047CCE2) --------------------------------------------------------
signed int __thiscall sub_47CCE2(void **this)
{
  void **v2; // esi@1

  v2 = this;
  memset(*this, 0, 0x4000u);
  memset(v2[1], 90, 0x4000u);
  memset(v2[2], 0, 0x4000u);
  memset(v2[3], 0, 0x8000u);
  *((_WORD *)v2 + 9) = 128;
  *((_WORD *)v2 + 8) = 128;
  *((_WORD *)v2 + 11) = 7;
  *((_WORD *)v2 + 10) = 7;
  v2[7] = (void *)127;
  v2[6] = (void *)127;
  return 1;
}

//----- (0047CDE2) --------------------------------------------------------
int __thiscall sub_47CDE2(int Dest)
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
  class51_sub_47F420(v2);
  class51_sub_47F3EA(v2);
  class23_DeleteBuffer(class23_instance, *(_DWORD *)(v2 + 216));
  class23_DeleteBuffer(class23_instance, *(_DWORD *)(v2 + 1220));
  *(_DWORD *)(v2 + 216) = 0;
  *(_DWORD *)(v2 + 1220) = 0;
  class51_InitializeGeodata((int *)(v2 + 180));
  sub_47CCE2((void **)(v2 + 180));
  sub_47C80A((void *)(v2 + 180), 0, 0, 128, 128);
  class23_DeleteBuffer(class23_instance, *(_DWORD *)(v2 + 212));
  *(_DWORD *)(v2 + 212) = 0;
  v3 = class23_AllocatedNamedBuffer(class23_instance, 0, 32768, "CMAP");
  v4 = *(_DWORD *)(v2 + 228);
  *(_DWORD *)(v2 + 212) = v3;
  class23_DeleteBuffer(class23_instance, v4);
  *(_DWORD *)(v2 + 228) = 0;
  v5 = class23_AllocatedNamedBuffer(class23_instance, 0, 65536, "OMAP");
  *(_DWORD *)(v2 + 228) = v5;
  memset((void *)v5, 0, 0x10000u);
  v6 = *(_DWORD *)(v2 + 224);
  *(_DWORD *)(v2 + 220) = 0;
  class23_DeleteBuffer(class23_instance, v6);
  *(_DWORD *)(v2 + 224) = 0;
  v7 = class23_AllocatedNamedBuffer(class23_instance, 0, 2, "IDLIST");
  *(_DWORD *)(v2 + 224) = v7;
  *(_WORD *)v7 = 0;
  strcpy((char *)(v2 + 96), byte_6BE114);
  *(_DWORD *)(v2 + 232) = class17_LoadTexture(pClass17_Bitmaps_LOD, (const char *)(v2 + 96), 0);
  strcpy((char *)(v2 + 128), byte_6BE124);
  result = class17_LoadTexture(pClass17_Bitmaps_LOD, (const char *)(v2 + 128), 0);
  v8 = *(_DWORD *)(v2 + 232) == -1;
  *(_DWORD *)(v2 + 236) = result;
  if ( v8 )
    erroneous_printf("Invalid Sky Tex Handle");
  if ( *(_DWORD *)(v2 + 236) == -1 )
    erroneous_printf("Invalid Ground Tex Handle");
  return result;
}

//----- (0047ECC1) --------------------------------------------------------
signed int __thiscall sub_47ECC1(int this, signed int a2)
{
  signed int result; // eax@2
  int v3; // eax@3

  if ( a2 >= 90 )
  {
    v3 = (a2 - 90) / 36;
    if ( v3 && v3 != 1 && v3 != 2 )
    {
      if ( v3 == 3 )
        result = *(_WORD *)(this + 174);
      else
        result = a2;
    }
    else
    {
      result = *(_WORD *)(this + 4 * v3 + 162);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0047ED83) --------------------------------------------------------
int __thiscall sub_47ED83(int this, signed int a2, signed int a3)
{
  int result; // eax@5

  if ( a2 < 0 || a2 > 127 || a3 < 0 || a3 > 127 )
    result = 0;
  else
    result = *(_BYTE *)((a3 << 7) + *(_DWORD *)(this + 184) + a2);
  return result;
}

//----- (0047EE49) --------------------------------------------------------
int __thiscall sub_47EE49(int this, signed int a2, signed int a3, int a4)
{
  signed int v4; // eax@5
  signed int v5; // eax@7
  int v7; // eax@8
  signed int v8; // eax@9
  int v9; // eax@12
  int v10; // eax@13
  int v11; // eax@14
  int v12; // eax@16
  int v13; // eax@17
  int v14; // eax@18
  int v15; // eax@19
  int v16; // eax@20
  int v17; // eax@21
  int v18; // eax@28
  int v19; // eax@29
  int v20; // eax@30

  if ( a2 < 0 || a2 > 127 || a3 < 0 || a3 > 127 )
    v4 = 0;
  else
    v4 = *(_BYTE *)((a3 << 7) + *(_DWORD *)(this + 184) + a2);
  v5 = sub_47ECC1(this, v4);
  if ( !v5 )
  {
    v7 = -(a4 != 0);
    LOBYTE(v7) = v7 & 0xD9;
    return v7 + 92;
  }
  v8 = *(_WORD *)(26 * v5 + pTileTable->pTiles + 20);
  if ( v8 <= 6 )
  {
    if ( v8 == 6 )
    {
      v17 = -(a4 != 0);
      LOBYTE(v17) = v17 & 0xD9;
      return v17 + 88;
    }
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( !v9 )
      {
        v15 = -(a4 != 0);
        LOBYTE(v15) = v15 & 0xD9;
        return v15 + 97;
      }
      v10 = v9 - 1;
      if ( !v10 )
      {
        v14 = -(a4 != 0);
        LOBYTE(v14) = v14 & 0xD9;
        return v14 + 91;
      }
      v11 = v10 - 1;
      if ( !v11 )
      {
        v13 = -(a4 != 0);
        LOBYTE(v13) = v13 & 0xD9;
        return v13 + 90;
      }
      if ( v11 == 2 )
      {
        v12 = -(a4 != 0);
        LOBYTE(v12) = v12 & 0xD9;
        return v12 + 101;
      }
LABEL_29:
      v19 = -(a4 != 0);
      LOBYTE(v19) = v19 & 0xD9;
      return v19 + 95;
    }
    goto LABEL_20;
  }
  if ( v8 != 7 )
  {
    if ( v8 != 8 )
    {
      if ( v8 > 9 && (v8 <= 17 || v8 > 21 && v8 <= 27) )
      {
        v18 = -(a4 != 0);
        LOBYTE(v18) = v18 & 0xD9;
        return v18 + 96;
      }
      goto LABEL_29;
    }
LABEL_20:
    v16 = -(a4 != 0);
    LOBYTE(v16) = v16 & 0xD9;
    return v16 + 93;
  }
  v20 = -(a4 != 0);
  LOBYTE(v20) = v20 & 0xD9;
  return v20 + 100;
}

//----- (0047F04C) --------------------------------------------------------
bool __thiscall sub_47F04C(void *this, signed int a2, signed int a3)
{
  bool result; // eax@5

  if ( a2 < 0 || a2 >= 88 || a3 < 0 || a3 >= 88 )
    result = 0;
  else
    result = (*((_BYTE *)this + (a2 + 88 * a3) / 8 + 1320) & (unsigned __int8)(1 << (7 - (a2 + 88 * a3) % 8))) != 0;
  return result;
}

//----- (0047F097) --------------------------------------------------------
bool __thiscall sub_47F097(void *this, signed int a2, signed int a3)
{
  bool result; // eax@5

  if ( a2 < 0 || a2 >= 88 || a3 < 0 || a3 >= 88 )
    result = 0;
  else
    result = (*((_BYTE *)this + (a2 + 88 * a3) / 8 + 2288) & (unsigned __int8)(1 << (7 - (a2 + 88 * a3) % 8))) != 0;
  return result;
}

//----- (0047F44B) --------------------------------------------------------
unsigned int __stdcall WorldPosToGridCellX(signed int sWorldPosX)
{
  return (sWorldPosX / 512) + 64;
}

//----- (0047F458) --------------------------------------------------------
unsigned int __stdcall WorldPosToGridCellZ(signed int sWorldPosZ)
{
  return 64 - (sWorldPosZ / 512);
}

//----- (0047F469) --------------------------------------------------------
int __stdcall sub_47F469(int a1)
{
  return (a1 - 64) << 9;
}

//----- (0047F476) --------------------------------------------------------
int __stdcall sub_47F476(int a1)
{
  return (64 - a1) << 9;
}

//----- (0047F4D3) --------------------------------------------------------
int __fastcall sub_47F4D3(int a1, int a2, int a3)
{
  int v3; // edi@1
  int v4; // esi@1
  int result; // eax@3
  double v6; // ST2C_8@3
  double v7; // st7@3
  double v8; // [sp+18h] [bp-28h]@3
  double v9; // [sp+20h] [bp-20h]@2
  int v10; // [sp+34h] [bp-Ch]@1
  int v11; // [sp+38h] [bp-8h]@1
  signed int v12; // [sp+48h] [bp+8h]@2

  v10 = a2 << 9;
  pStruct9_global->dword_000048 = a3;
  v11 = a1 << 9;
  v3 = a3 << 9;
  pStruct9_global->dword_000000 = a3 << 9;
  //v4 = byte_76E5C8;
  v4 = 0;
  do
  {
    v12 = 256;
    v9 = (double)(v4 + 256);
    do
    {
      v6 = powf(v12, 2);
      v7 = powf(v9, 2);
      v6 = sqrt(v7 + v6);
      v8 = v6 + 6.755399441055744e15;
      result = LODWORD(v8);
      if ( LODWORD(v8) >= v11 )
      {
        if ( LODWORD(v8) >= v10 )
          byte_76E5C8[v4] = ((LODWORD(v8) >= v3) - 1) & 2;
        else
          byte_76E5C8[v4] = 2;
      }
      else
      {
        byte_76E5C8[v4] = 1;
      }
      v12 += 512;
      *(_WORD *)(&byte_76E5C8[v4] + 2) = LOWORD(v8);
      v4 += 4;
    }
    while (v12 < 65792);
  }
  while (v4 < 0x10000);
  return result;
}

//----- (0048034E) --------------------------------------------------------
void __fastcall sub_48034E(int a1, int a2, int a3)
{
  int v3; // edi@1
  int v4; // esi@1
  int v5; // ebx@2
  int v6; // eax@2
  int v7; // eax@3
  int v8; // edi@3
  char *v9; // ecx@4
  char *v10; // ebx@4
  float v11; // eax@6
  double v12; // ST5C_8@6
  double v13; // ST2C_8@6
  double v14; // st7@6
  int v15; // ebx@12
  __int16 v16; // ax@12
  int v17; // eax@13
  int v18; // eax@13
  int v19; // ecx@13
  int v20; // eax@13
  int v21; // eax@13
  int v22; // eax@15
  double v23; // st6@17
  double v24; // ST54_8@17
  unsigned __int8 v25; // sf@17
  unsigned __int8 v26; // of@17
  double v27; // st5@19
  double v28; // st5@19
  double v29; // st5@19
  double v30; // st5@19
  int v31; // esi@21
  double v32; // st7@32
  int v33; // edi@38
  int v34; // ecx@47
  int v35; // eax@50
  int v36; // eax@54
  void *v37; // ecx@55
  int v38; // eax@59
  int v39; // ebx@62
  __int16 v40; // ax@62
  int v41; // eax@63
  int v42; // eax@63
  int v43; // ecx@63
  int v44; // eax@63
  int v45; // eax@63
  int v46; // eax@63
  int v47; // eax@65
  double v48; // st6@67
  double v49; // ST4C_8@67
  double v50; // st5@71
  double v51; // st5@71
  double v52; // st5@71
  double v53; // st7@84
  int v54; // ecx@98
  int v55; // eax@101
  int v56; // eax@105
  int v57; // eax@109
  int v58; // esi@112
  __int16 v59; // ax@112
  int v60; // eax@113
  int v61; // eax@113
  int v62; // eax@114
  double v63; // st6@116
  double v64; // ST3C_8@116
  double v65; // st5@120
  double v66; // st5@120
  double v67; // st5@120
  double v68; // st7@133
  int v69; // edi@138
  int v70; // ecx@147
  int v71; // eax@150
  int v72; // eax@154
  int v73; // eax@158
  unsigned __int8 v74; // sf@162
  unsigned __int8 v75; // of@162
  int v76; // [sp-10h] [bp-E0h]@61
  int v77; // [sp-Ch] [bp-DCh]@61
  int v78; // [sp-8h] [bp-D8h]@61
  int v79; // [sp-4h] [bp-D4h]@61
  int v80; // [sp+0h] [bp-D0h]@59
  int v81; // [sp+0h] [bp-D0h]@109
  int v82; // [sp+54h] [bp-7Ch]@1
  int v83; // [sp+60h] [bp-70h]@1
  int v84; // [sp+6Ch] [bp-64h]@1
  int v85; // [sp+70h] [bp-60h]@63
  int v86; // [sp+74h] [bp-5Ch]@73
  int v87; // [sp+78h] [bp-58h]@122
  int v88; // [sp+7Ch] [bp-54h]@1
  int v89; // [sp+80h] [bp-50h]@6
  float v90; // [sp+84h] [bp-4Ch]@1
  float v91; // [sp+88h] [bp-48h]@1
  float v92; // [sp+8Ch] [bp-44h]@1
  int v93; // [sp+90h] [bp-40h]@2
  int X; // [sp+94h] [bp-3Ch]@1
  int v95; // [sp+98h] [bp-38h]@21
  int v96; // [sp+9Ch] [bp-34h]@73
  int v97; // [sp+A0h] [bp-30h]@6
  int v98; // [sp+A4h] [bp-2Ch]@6
  int v99; // [sp+A8h] [bp-28h]@73
  int v100; // [sp+ACh] [bp-24h]@122
  int v101; // [sp+B0h] [bp-20h]@6
  int v102; // [sp+B4h] [bp-1Ch]@3
  int v103; // [sp+B8h] [bp-18h]@21
  int v104; // [sp+BCh] [bp-14h]@6
  float v105; // [sp+C0h] [bp-10h]@17
  int v106; // [sp+C4h] [bp-Ch]@6
  int v107; // [sp+C8h] [bp-8h]@6
  char v108; // [sp+CFh] [bp-1h]@36
  float v109; // [sp+D8h] [bp+8h]@6
  float v110; // [sp+D8h] [bp+8h]@6
  float v111; // [sp+D8h] [bp+8h]@17
  void *v112; // [sp+D8h] [bp+8h]@23
  float v113; // [sp+D8h] [bp+8h]@67
  void *v114; // [sp+D8h] [bp+8h]@75
  float v115; // [sp+D8h] [bp+8h]@116
  void *v116; // [sp+D8h] [bp+8h]@124
  char v117; // [sp+DBh] [bp+Bh]@30
  char v118; // [sp+DBh] [bp+Bh]@82
  char v119; // [sp+DBh] [bp+Bh]@131

  v4 = a1;
  v82 = a2;
  v83 = *(_WORD *)(a3 + 4);
  X = abs(*(_WORD *)(a3 + 6));
  v3 = 0;
  v88 = 0;
  v84 = v4 - 1;
  v90 = (double)pClass51_global->dword_000D30 * 0.0000152587890625;
  v91 = (double)pClass51_global->dword_000D34 * 0.0000152587890625;
  v92 = (double)pClass51_global->dword_000D38 * 0.0000152587890625;
  if ( v4 - 1 > 0 )
  {
    while ( 1 )
    {
      v5 = abs(X);
      v6 = abs(v83);
      --X;
      v93 = 4 * ((v5 << 7) + v6) + 7792072;

      compile_error;
      /*
      if ( !byte_76E5C8[4 * ((v5 << 7) + v6)]
        || ((v7 = 48 * v3, v8 = (int)((char *)&unk_806210 + 48 * v3), v102 = v8, !v82) ? (v10 = (char *)&unk_801A10 + v7,
                                                                                          v9 = (char *)&unk_806240 + v7) : (v10 = (char *)&unk_806240 + v7, v9 = (char *)&unk_801A10 + v7),
            ((v107 = (int)v10,
              v106 = (int)((char *)&unk_801A40 + v7),
              LODWORD(v11) = *(_DWORD *)v8,
              v104 = (int)v9,
              v12 = v11 + 6.755399441055744e15,
              v98 = LODWORD(v12),
              v13 = *(float *)(v8 + 4) + 6.755399441055744e15,
              v101 = LODWORD(v13),
              v109 = (*(float *)v9 + *(float *)v8) * 0.5,
              v14 = *((float *)v10 + 1) + *(float *)(v8 + 4),
              v89 = WorldPosToGridCellX(COERCE_UNSIGNED_INT64(v109 + 6.755399441055744e15)),
              v110 = v14 * 0.5,
              v97 = WorldPosToGridCellZ(COERCE_UNSIGNED_INT64(v110 + 6.755399441055744e15)),
              WorldPosToGridCellX(v98),
              WorldPosToGridCellZ(v101),
              !byte_4D8410[572])
          || !(*(_BYTE *)(LODWORD(pGame) + 3616) & 0x80))
         && !sub_481EFA(v8, (int)v10, v104, v106, 1)) )*/
      if (0)
        goto LABEL_162;
      if ( *(float *)(v8 + 8) != *((float *)v10 + 2)
        || *((float *)v10 + 2) != *(float *)(v106 + 8)
        || *(float *)(v106 + 8) != *(float *)(v104 + 8) )
        break;
      v15 = &array_77EC08[pStruct9_global->dword_00002C];
      v16 = class51_sub_488EEF_GetSomeTileInfo(pClass51_global, v98, v101);
      *(_WORD *)(v15 + 76) = v16;
      if ( v16 != -1 )
      {
        v18 = class51_sub_488EB1_GetSomeOtherTileInfo(pClass51_global, v98, v101);
        LOWORD(v18) = v18 | 0x8010;
        v19 = v97;
        *(_DWORD *)(v15 + 48) = v18;
        v20 = v93;
        *(_BYTE *)(v15 + 89) = 1;
        *(_BYTE *)(v15 + 93) = v19;
        *(_DWORD *)(v15 + 52) = *(_WORD *)(v20 + 2);
        v21 = v89;
        *(_BYTE *)(v15 + 92) = v89;
        v17 = (unsigned __int16)word_75D514[2 * (v19 + (v21 << 7)) + 1];
        if ( v17 < 0 || v17 > uNumTerrainNormals - 1 )
          v22 = 0;
        else
          v22 = pTerrainNormals + v17;
        v23 = v92 * *(float *)(v22 + 8);
        LODWORD(v105) = v22;
        v111 = 20.0 - (-v23 - v91 * *(float *)(v22 + 4) - v90 * *(float *)v22) * 20.0;
        v24 = v111 + 6.755399441055744e15;
        compile_error;//v26 = __SETO__(pStruct9_global->dword_00002C, 1999);
        v25 = pStruct9_global->dword_00002C - 1999 < 0;
        *(_BYTE *)(v15 + 88) = LOBYTE(v24);
        if ( !(v25 ^ v26) )
          return;
        ++pStruct9_global->dword_00002C;
        if ( !sub_481FC9(v8, v107, v104, v15) )
          goto LABEL_126;

        v27 = 1.0 / (*(float *)(v102 + 12) + 0.0000001000000011686097);
        memcpy(&array_50AC10[0], v102, sizeof(struct struct14));
        array_50AC10[0].flt_000020 = v27;
        array_50AC10[0].u = 0.0;
        array_50AC10[0].v = 0.0;

        v28 = *(float *)(v107 + 12) + 0.0000001000000011686097;
        memcpy(&array_50AC10[1], v107, sizeof(struct struct14));
        array_50AC10[1].flt_000020 = 1.0 / v28;
        array_50AC10[1].u = 0.0;
        array_50AC10[1].v = 1.0;

        v29 = *(float *)(v106 + 12) + 0.0000001000000011686097;
        memcpy(&array_50AC10[2], v106, sizeof(struct struct14));
        array_50AC10[2].flt_000020 = 1.0 / v29;
        array_50AC10[2].u = 1.0;
        array_50AC10[2].v = 1.0;

        v30 = *(float *)(v104 + 12) + 0.0000001000000011686097;
        memcpy(&array_50AC10[3], v104, sizeof(struct struct14));
        array_50AC10[3].flt_000020 = 1.0 / v30;
        array_50AC10[3].u = 1.0;
        array_50AC10[3].v = 0.0;

        if ( !(byte_76D5C0 & 1) )
        {
          byte_76D5C0 |= 1u;
          sub_49B001(&unk_76D5A8);
          compile_error;//atexit(loc_481199);
        }
        v31 = array_50AC10;
        v97 = pGame->class04_obj;
        compile_error;//sub_45D036(SLODWORD(v105), (int)&v95, COERCE_FLOAT(&unk_50AC10), COERCE_FLOAT(4), 1);
        sub_49BE8A(pClass58_global, v15, v105, (int)&v95, array_50AC10, 4, 1);
        v103 = 4;
        if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3616) & 0x80 )
        {
          v112 = pGame->class08_obj;
          if ( sub_4371C3(pGame->class08_obj, array_50AC10, (int)&v103, 0) == 1 && !v103 )
            goto LABEL_162;
          sub_436523(array_50AC10, v103);
          class08_sub_436BB7(v112, array_50AC10, v103, 0);
        }
        v117 = *(float *)(v102 + 12) < 8.0
            || *(float *)(v107 + 12) < 8.0
            || *(float *)(v104 + 12) < 8.0
            || *(float *)(v106 + 12) < 8.0;
        v32 = (double)pStruct9_global->shading_dist_mist;
        v108 = v32 < *(float *)(v102 + 12)
            || v32 < *(float *)(v107 + 12)
            || v32 < *(float *)(v104 + 12)
            || v32 < *(float *)(v106 + 12);
        v33 = 0;
        *(_DWORD *)(v97 + 1587204) = 0;
        if ( dword_F8ADD4 > 0 || dword_DF1BB4 > 0 )
        {
          if ( v117 )
            v33 = 3;
          else
            v33 = v108 != 0 ? 5 : 0;
          sub_49B0C9((int)&unk_76D5A8, SLODWORD(v105), v95);
          if ( dword_DF1BB4 > 0 )
            sub_49B540(
              pClass58_global,
              31 - *(_BYTE *)(v15 + 88),
              4,
              (int)&unk_76D5A8,
              v103,
              array_50AC10,
              0,
              *(float *)&v33,
              -1);
        }
        if ( dword_F8ADD4 > 0 )
          sub_45BC07((void *)v97, (int)&dword_F8AD28, (int)&unk_76D5A8, v103, array_50AC10, 0.0, v33);
        v34 = v103;
        *(_DWORD *)(v15 + 20) = v103;
        if ( !byte_4D8410[572] || !(*(_BYTE *)(LODWORD(pGame) + 3616) & 0x80) )
        {
          if ( v117 )
          {
            v35 = sub_424CD7(v34);
            goto LABEL_53;
          }
          if ( v108 )
          {
            v35 = sub_424EE0(v34);
LABEL_53:
            *(_DWORD *)(v15 + 20) = v35;
            sub_481E55(v35);
          }
        }
        v36 = *(_DWORD *)(v15 + 48);
        if ( !(BYTE1(v36) & 1) )
        {
          if ( v36 & 2 && *(_WORD *)(v15 + 76) == dword_EF5294 )
          {
            v80 = 0;
            v38 = uTextureID_WaterTiles[dword_EF5290];
          }
          else
          {
            v38 = *(_WORD *)(v15 + 76);
            v80 = 1;
          }
          v79 = 0;
          v78 = *(_DWORD *)(pClass17_Bitmaps_LOD->dword_011BB0 + 4 * v38);
          v77 = v15;
          v76 = *(_DWORD *)(v15 + 20);
LABEL_161:
          sub_4A26BC(pD3DRenderer, v31, v76, v77, v78, v79, v80);
          goto LABEL_162;
        }
        v37 = (void *)v15;
LABEL_56:
        sub_4811A3(v37);
      }
LABEL_162:
      v3 = v88 + 1;
      compile_error;//v75 = __SETO__(v88 + 1, v84);
      v74 = v88++ + 1 - v84 < 0;
      if ( !(v74 ^ v75) )
        return;
    }
    v39 = &array_77EC08[pStruct9_global->dword_00002C];
    v40 = class51_sub_488EEF_GetSomeTileInfo(pClass51_global, v98, v101);
    *(_WORD *)(v39 + 76) = v40;
    if ( v40 == -1 )
      goto LABEL_162;
    v42 = class51_sub_488EB1_GetSomeOtherTileInfo(pClass51_global, v98, v101);
    BYTE1(v42) |= 0x80u;
    v43 = v97;
    *(_DWORD *)(v39 + 48) = v42;
    v44 = v93;
    *(_BYTE *)(v39 + 89) = 1;
    *(_BYTE *)(v39 + 93) = v43;
    *(_DWORD *)(v39 + 52) = *(_WORD *)(v44 + 2);
    v45 = v89;
    *(_BYTE *)(v39 + 92) = v89;
    v46 = 4 * (v43 + (v45 << 7));
    v85 = v46;
    v41 = *(unsigned __int16 *)((char *)word_75D514 + v46 + 2);
    if ( v41 < 0 || v41 > uNumTerrainNormals - 1 )
      v47 = 0;
    else
      v47 = pTerrainNormals + v41;
    v48 = v92 * *(float *)(v47 + 8);
    LODWORD(v105) = v47;
    v113 = 20.0 - (-v48 - v91 * *(float *)(v47 + 4) - v90 * *(float *)v47) * 20.0;
    v49 = v113 + 6.755399441055744e15;
    *(_BYTE *)(v39 + 88) = LOBYTE(v49);
    if ( LOBYTE(v49) < 0 )
      *(_BYTE *)(v39 + 88) = 0;
    if ( pStruct9_global->dword_00002C >= 1999 )
      return;
    ++pStruct9_global->dword_00002C;
    if ( !sub_481FC9(v107, v106, v8, v39) )
      goto LABEL_77;

    v50 = 1.0 / (*(float *)(v102 + 12) + 0.0000001000000011686097);
    memcpy(&array_50AC10[0], v102, sizeof(struct struct14));
    array_50AC10[0].flt_000020 = v50;
    array_50AC10[0].u = 0.0;
    array_50AC10[0].v = 0.0;

    v51 = *(float *)(v107 + 12) + 0.0000001000000011686097;
    memcpy(&array_50AC10[1], v107, sizeof(struct struct14));
    array_50AC10[1].flt_000020 = 1.0 / v51;
    array_50AC10[1].u = 0.0;
    array_50AC10[1].v = 1.0;

    v52 = *(float *)(v106 + 12) + 0.0000001000000011686097;
    memcpy(&array_50AC10[2], v106, sizeof(struct struct14));
    array_50AC10[2].flt_000020 = 1.0 / v52;
    array_50AC10[2].u = 1.0;
    array_50AC10[2].v = 1.0;

    if ( !(byte_76D5C0 & 2) )
    {
      byte_76D5C0 |= 2;
      sub_49B001(&unk_76D590);
      compile_error;//atexit(loc_48118F);
    }
    v96 = pGame->class04_obj;
    compile_error;//sub_45D036(SLODWORD(v105), (int)&v86, COERCE_FLOAT(&unk_50AC10), COERCE_FLOAT(3), 0);
    sub_49BE8A(pClass58_global, v39, v105, (int)&v86, array_50AC10, 3, 0);
    v99 = 3;
    if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3616) & 0x80 )
    {
      v114 = pGame->class08_obj;
      if ( sub_4371C3(pGame->class08_obj, array_50AC10, (int)&v99, 0) == 1 && !v99 )
      {
LABEL_77:
        --pStruct9_global->dword_00002C;
        goto LABEL_112;
      }
      sub_436523(array_50AC10, v99);
      class08_sub_436BB7(v114, array_50AC10, v99, 0);
    }
    v118 = *(float *)(v102 + 12) < 8.0 || *(float *)(v107 + 12) < 8.0 || *(float *)(v106 + 12) < 8.0;
    v53 = (double)pStruct9_global->shading_dist_mist;
    v108 = v53 < *(float *)(v102 + 12) || v53 < *(float *)(v107 + 12) || v53 < *(float *)(v106 + 12);
    v107 = 0;
    *(_DWORD *)(v96 + 1587204) = 0;
    if ( dword_F8ADD4 > 0 || dword_DF1BB4 > 0 )
    {
      if ( v118 )
        v107 = 3;
      else
        v107 = v108 != 0 ? 5 : 0;
      sub_49B0C9((int)&unk_76D590, SLODWORD(v105), v86);
      if ( dword_DF1BB4 > 0 )
        sub_49B540(
          pClass58_global,
          31 - *(_BYTE *)(v39 + 88),
          4,
          (int)&unk_76D590,
          v99,
          array_50AC10,
          0,
          *(float *)&v107,
          -1);
    }
    if ( dword_F8ADD4 > 0 )
      sub_45BC07((void *)v96, (int)&dword_F8AD28, (int)&unk_76D590, v99, array_50AC10, 0.0, v107);
    v54 = v99;
    *(_DWORD *)(v39 + 20) = v99;
    if ( !byte_4D8410[572] || !(*(_BYTE *)(LODWORD(pGame) + 3616) & 0x80) )
    {
      if ( v118 )
      {
        v55 = sub_424CD7(v54);
      }
      else
      {
        if ( !v108 )
          goto LABEL_105;
        v55 = sub_424EE0(v54);
      }
      *(_DWORD *)(v39 + 20) = v55;
      sub_481E55(v55);
    }
LABEL_105:
    v56 = *(_DWORD *)(v39 + 48);
    if ( BYTE1(v56) & 1 )
    {
      sub_4811A3((void *)v39);
    }
    else
    {
      if ( v56 & 2 && *(_WORD *)(v39 + 76) == dword_EF5294 )
      {
        v81 = 0;
        v57 = uTextureID_WaterTiles[dword_EF5290];
      }
      else
      {
        v57 = *(_WORD *)(v39 + 76);
        v81 = 1;
      }
      sub_4A26BC(
        pD3DRenderer,
        array_50AC10,
        *(_DWORD *)(v39 + 20),
        v39,
        *(_DWORD *)(pClass17_Bitmaps_LOD->dword_011BB0 + 4 * v57),
        0,
        v81);
    }
LABEL_112:
    v58 = &array_77EC08[pStruct9_global->dword_00002C];
    v107 = &array_77EC08[pStruct9_global->dword_00002C];
    v59 = class51_sub_488EEF_GetSomeTileInfo(pClass51_global, v98, v101);
    *(_WORD *)(v58 + 76) = v59;
    if ( v59 == -1 )
      goto LABEL_162;
    *(_DWORD *)(v58 + 48) = class51_sub_488EB1_GetSomeOtherTileInfo(pClass51_global, v98, v101);
    v61 = v93;
    *(_BYTE *)(v58 + 89) = 1;
    *(_DWORD *)(v58 + 52) = *(_WORD *)(v61 + 2);
    *(_BYTE *)(v58 + 92) = v89;
    *(_BYTE *)(v58 + 93) = v97;
    v60 = *(unsigned __int16 *)((char *)word_75D514 + v85);
    if ( v60 > uNumTerrainNormals - 1 )
      v62 = 0;
    else
      v62 = pTerrainNormals + v60;
    v63 = v92 * *(float *)(v62 + 8);
    LODWORD(v105) = v62;
    v115 = 20.0 - (-v63 - v91 * *(float *)(v62 + 4) - v90 * *(float *)v62) * 20.0;
    v64 = v115 + 6.755399441055744e15;
    *(_BYTE *)(v58 + 88) = LOBYTE(v64);
    if ( LOBYTE(v64) < 0 )
      *(_BYTE *)(v58 + 88) = 0;
    if ( pStruct9_global->dword_00002C >= 1999 )
      return;
    ++pStruct9_global->dword_00002C;
    if ( !sub_481FC9(v104, v102, v106, v58) )
    {
LABEL_126:
      --pStruct9_global->dword_00002C;
      goto LABEL_162;
    }

    v65 = 1.0 / (*(float *)(v102 + 12) + 0.0000001000000011686097);
    memcpy(&array_50AC10[0], v102, sizeof(struct struct14));
    array_50AC10[0].flt_000020 = v65;
    array_50AC10[0].u = 0.0;
    array_50AC10[0].v = 0.0;

    v66 = *(float *)(v106 + 12) + 0.0000001000000011686097;
    memcpy(&array_50AC10[1], v106, sizeof(struct struct14));
    array_50AC10[1].flt_000020 = 1.0 / v66;
    array_50AC10[1].u = 1.0;
    array_50AC10[1].v = 1.0;

    v67 = *(float *)(v104 + 12) + 0.0000001000000011686097;
    memcpy(&array_50AC10[2], v104, sizeof(struct struct14));
    array_50AC10[2].flt_000020 = 1.0 / v67;
    array_50AC10[2].u = 1.0;
    array_50AC10[2].v = 0.0;

    if ( !(byte_76D5C0 & 4) )
    {
      byte_76D5C0 |= 4u;
      sub_49B001(&unk_76D578);
      compile_error;//atexit(loc_481185);
    }
    v96 = pGame->class04_obj;
    compile_error;//sub_45D036(SLODWORD(v105), (int)&v87, COERCE_FLOAT(&unk_50AC10), COERCE_FLOAT(3), 1);
    sub_49BE8A(pClass58_global, v39, v105, (int)&v87, array_50AC10, 3, 1);
    v100 = 3;
    if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3616) & 0x80 )
    {
      v116 = pGame->class08_obj;
      if ( sub_4371C3(pGame->class08_obj, array_50AC10, (int)&v100, 0) == 1 && !v100 )
        goto LABEL_126;
      sub_436523(array_50AC10, v100);
      class08_sub_436BB7(v116, array_50AC10, v100, 0);
    }
    v119 = *(float *)(v102 + 12) < 8.0 || *(float *)(v106 + 12) < 8.0 || *(float *)(v104 + 12) < 8.0;
    v68 = (double)pStruct9_global->shading_dist_mist;
    v108 = v68 < *(float *)(v102 + 12) || v68 < *(float *)(v106 + 12) || v68 < *(float *)(v104 + 12);
    v69 = 0;
    *(_DWORD *)(v96 + 1587204) = 0;
    if ( dword_F8ADD4 > 0 || dword_DF1BB4 > 0 )
    {
      if ( v119 )
        v69 = 3;
      else
        v69 = v108 != 0 ? 5 : 0;
      sub_49B0C9((int)&unk_76D578, SLODWORD(v105), v87);
      if ( dword_DF1BB4 > 0 )
        sub_49B540(
          pClass58_global,
          31 - *(_BYTE *)(v39 + 88),
          4,
          (int)&unk_76D578,
          v100,
          array_50AC10,
          0,
          *(float *)&v69,
          -1);
    }
    if ( dword_F8ADD4 > 0 )
      sub_45BC07((void *)v96, (int)&dword_F8AD28, (int)&unk_76D578, v100, array_50AC10, 0.0, v69);
    v31 = v107;
    v70 = v100;
    *(_DWORD *)(v107 + 20) = v100;
    if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3616) & 0x80 )
      goto LABEL_154;
    if ( v119 )
    {
      v71 = sub_424CD7(v70);
    }
    else
    {
      if ( !v108 )
      {
LABEL_154:
        v72 = *(_DWORD *)(v31 + 48);
        if ( !(BYTE1(v72) & 1) )
        {
          if ( v72 & 2 && *(_WORD *)(v31 + 76) == dword_EF5294 )
          {
            v80 = 0;
            v73 = uTextureID_WaterTiles[dword_EF5290];
          }
          else
          {
            v73 = *(_WORD *)(v31 + 76);
            v80 = 1;
          }
          v79 = 0;
          v78 = *(_DWORD *)(pClass17_Bitmaps_LOD->dword_011BB0 + 4 * v73);
          v77 = v31;
          v76 = *(_DWORD *)(v31 + 20);
          goto LABEL_161;
        }
        v37 = (void *)v31;
        goto LABEL_56;
      }
      v71 = sub_424EE0(v70);
    }
    *(_DWORD *)(v31 + 20) = v71;
    sub_481E55(v71);
    goto LABEL_154;
  }
}

//----- (004811A3) --------------------------------------------------------
void __thiscall sub_4811A3(void *this)
{
  int v1; // esi@1

  v1 = (int)this;
  (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(pD3DRenderer->dword_040088 + 56) + 88))(
    *(_DWORD *)(pD3DRenderer->dword_040088 + 56),
    14,
    0);
  sub_4A26BC(
    pD3DRenderer,
    v1,
    *(_DWORD *)(v1 + 20),
    v1,
    *(_DWORD *)(pClass17_Bitmaps_LOD->dword_011BB0 + 4 * uTextureID_WaterTiles[dword_EF5290]),
    0,
    0);
  (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(pD3DRenderer->dword_040088 + 56) + 88))(
    *(_DWORD *)(pD3DRenderer->dword_040088 + 56),
    14,
    1);
  sub_4A26BC(
    pD3DRenderer,
    v1,
    *(_DWORD *)(v1 + 20),
    v1,
    *(_DWORD *)(pClass17_Bitmaps_LOD->dword_011BB0 + 4 * *(_WORD *)(v1 + 76)),
    1,
    1);
}

//----- (00481CCE) --------------------------------------------------------
void sub_481CCE(struct struct14 *a1)
{
  double v2; // st4@1
  double v5; // st7@1
  float v6; // ST04_4@3
  float v7; // [sp+0h] [bp-14h]@1
  float v8; // [sp+8h] [bp-Ch]@1
  float v9; // [sp+Ch] [bp-8h]@1
  float v10; // [sp+10h] [bp-4h]@1

  v8 = pCamera->fRotationXCosine;
  LODWORD(v7) = *(int *)&pCamera->fRotationXSine;
  v9 = a1->x - (double)pCamera->dword_000000;
  v10 = a1->z - (double)pCamera->dword_000004;
  v5 = a1->y - (double)pCamera->dword_000008;

  v2 = v10 * pCamera->fRotationYSine + pCamera->fRotationYCosine * v9;
  if (pCamera->sRotationX)
  {
    v6 = v2;
    a1->flt_00000C = v2 * pCamera->fRotationXCosine + pCamera->fRotationXSine * v5;
    a1->flt_000010 = pCamera->fRotationYCosine * v10 - pCamera->fRotationYSine * v9;
    a1->flt_000014 = v8 * v5 - v6 * v7;
  }
  else
  {
    a1->flt_00000C = v2;
    a1->flt_000010 = pCamera->fRotationYCosine * v10 - pCamera->fRotationYSine * v9;
    a1->flt_000014 = v5;
  }
}

//----- (00481D77) --------------------------------------------------------
void sub_481D77(struct struct14 *_this)
{
 double v1; // st7@1
 double v2; // st7@1

 v1 = 1.0 / (_this->flt_00000C + 0.0000001000000011686097);
 _this->flt_000020 = v1;
 v2 = v1 * (double)pStruct9_global->dword_000014;
 _this->flt_000018 = class28_global.dword_000028 - v2 * _this->flt_000010;
 _this->flt_00001C = class28_global.dword_00002C - v2 * _this->flt_000014;
}

//----- (00481DB2) --------------------------------------------------------
void __fastcall sub_481DB2(int a1, signed int a2, int a3)
{
  int v3; // esi@2
  int v4; // eax@2
  int v5; // esi@2
  _UNKNOWN *v6; // edi@3
  double v7; // ST14_8@4
  double v8; // ST0C_8@4
  char result; // al@5

  if ( a2 >= 3 )
  {
    v4 = *(_WORD *)(a3 + 76);
    v5 = *(_WORD *)(a3 + 76);
    *(_DWORD *)(a3 + 56) = pClass57_global;
    *(_DWORD *)(a3 + 60) = v5 != -1 ? 72 * v4 + 0x6F10BC : 0;
    v3 = 0;
    if ( *(_DWORD *)(a3 + 20) > 0 )
    {
      v6 = &array_508690[0].flt_00001C;
      do
      {
        v7 = *((float *)v6 - 1) + 6.755399441055744e15;
        dword_50B638[v3] = LODWORD(v7);
        v8 = *(float *)v6 + 6.755399441055744e15;
        v6 = (char *)v6 + 48;
        dword_50B570[v3++] = LODWORD(v8);
      }
      while ( v3 < *(_DWORD *)(a3 + 20) );
    }
    sub_486B4E(a1, (int)dword_50B638, dword_50B570, a3);
  }
}

//----- (00481EFA) --------------------------------------------------------
bool sub_481EFA(struct struct14 *a1, struct struct14 *a2, struct struct14 *a3, struct struct14 *a4, int a5)
{
 double v11; // st7@14

 v11 = pStruct9_global->shading_dist_mist;
 return (a1->flt_00000C >= 8.0 || a2->flt_00000C >= 8.0 || a3->flt_00000C >= 8.0 || a4->flt_00000C >= 8.0) &&
        (a1->flt_00000C <= v11 || a2->flt_00000C <= v11 || a3->flt_00000C <= v11 || a4->flt_00000C <= v11);
}

//----- (00481FC9) --------------------------------------------------------
bool sub_481FC9(struct struct14 *a1, struct struct14 *a2, struct struct14 *a3, struct struct8 *a4)
{
 float arg_0, arg_4, var_4, var_8, var_c, var_10, var_14;

  /*
  fld     a1->y
  _ESI = a2;
  _EDX = a3;
  fcomp   a2->y
  _EDI = a4;
  fnstsw  ax
  test ah, 44h
  jnp block
  {
      fld     a2->y
      fcomp   a3->y
      fnstsw  ax
      test ah, 44h
      jnp block
      {
       *(_DWORD *)(a4 + 48) |= 0x10u;
      }

  }
  */
  if (a1->y == a2->y && a2->y == a3->y)
    a4->dword_000030 |= 0x10;

  
    //fld     a1->flt_00000C
    //fsub    a2->flt_00000C
    //fstp    [ebp+var_C]
  var_c = a1->flt_00000C - a2->flt_00000C;

    //fld     a1->flt_000010
    //fsub    a2->flt_000010
    //fstp    [ebp+var_14]
  var_14 = a1->flt_000010 - a2->flt_000010;

    //fld     dword ptr [ecx+14h]
    //fsub    dword ptr [esi+14h]
    //fstp    [ebp+arg_0]
  arg_0 = a1->flt_000014 - a2->flt_000014;

    //fld     dword ptr [edx+0Ch]
    //fsub    dword ptr [esi+0Ch]
    //fstp    [ebp+var_10]
  var_10 = a3->flt_00000C - a2->flt_00000C;

    //fld     dword ptr [edx+10h]
    //fsub    dword ptr [esi+10h]
    //fstp    [ebp+var_8]
  var_8 = a3->flt_000010 - a2->flt_000010;

    //fld     dword ptr [edx+14h]
    //fsub    dword ptr [esi+14h]
    //fstp    [ebp+var_4]
  var_4 = a3->flt_000014 - a2->flt_000014;

  /*
    fld     dword ptr [ecx]     //a1->x
    fsub    dword ptr [esi]     //(a1->x - a2->x)

    fld     dword ptr [ecx+4]   //a1->z			(a1->x - a2->x)
    fsub    dword ptr [esi+4]   //(a1->z - a2->z)	(a1->x - a2->x)

    fld     dword ptr [ecx+8]   //a1->y			(a1->z - a2->z)		(a1->x - a2->x)
    fsub    dword ptr [esi+8]   //(a1->y - a2->y)	(a1->z - a2->z)		(a1->x - a2->x)

    fld     dword ptr [edx]     //a3->x			(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fsub    dword ptr [esi]     //(a3->x - a2->x)	(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)

    fld     dword ptr [edx+4]   //a3->z			(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fsub    dword ptr [esi+4]   //(a3->z - a2->z)	(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)

    fld     dword ptr [edx+8]   //a3->y			(a3->z - a2->z)		(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fsub    dword ptr [esi+8]   //(a3->y - a2->y)	(a3->z - a2->z)		(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fstp    [ebp+arg_4]         //(a3->z - a2->z)	(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
  */
  arg_4 = a3->y - a2->y;

  /*
    fld     st                            //(a3->z - a2->z)													(a3->z - a2->z)														(a3->x - a2->x)														(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fmul    st, st(3)                     //(a3->z - a2->z)*(a1->y - a2->y)											(a3->z - a2->z)														(a3->x - a2->x)														(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fld     [ebp+arg_4]                   //(a3->y - a2->y)													(a3->z - a2->z)*(a1->y - a2->y)												(a3->z - a2->z)														(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fmul    st, st(5)                     //(a3->y - a2->y)*(a1->z - a2->z)											(a3->z - a2->z)*(a1->y - a2->y)												(a3->z - a2->z)														(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fsubp   st(1), st                     //(a3->z - a2->z)*(a1->y - a2->y)-(a3->y - a2->y)*(a1->z - a2->z)							(a3->z - a2->z)														(a3->x - a2->x)														(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fild    pCamera->dword_000000 //pCamera->dword_000000    											(a3->z - a2->z)*(a1->y - a2->y)-(a3->y - a2->y)*(a1->z - a2->z)								(a3->z - a2->z)														(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fsub    dword ptr [esi]               //(pCamera->dword_000000 - a2->x)										(a3->z - a2->z)*(a1->y - a2->y)-(a3->y - a2->y)*(a1->z - a2->z)								(a3->z - a2->z)														(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fmulp   st(1), st                     //((a3->z - a2->z)*(a1->y - a2->y)-(a3->y - a2->y)*(a1->z - a2->z))*(pCamera->dword_000000 - a2->x)		(a3->z - a2->z)														(a3->x - a2->x)														(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fld     [ebp+arg_4]                   //(a3->y - a2->y)													((a3->z - a2->z)*(a1->y - a2->y)-(a3->y - a2->y)*(a1->z - a2->z))*(pCamera->dword_000000 - a2->x)		(a3->z - a2->z)														(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fmul    st, st(6)                     //(a3->y - a2->y)*(a1->x - a2->x)											((a3->z - a2->z)*(a1->y - a2->y)-(a3->y - a2->y)*(a1->z - a2->z))*(pCamera->dword_000000 - a2->x)		(a3->z - a2->z)														(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fld     st(3)                         //(a3->x - a2->x)													(a3->y - a2->y)*(a1->x - a2->x)												((a3->z - a2->z)*(a1->y - a2->y)-(a3->y - a2->y)*(a1->z - a2->z))*(pCamera->dword_000000 - a2->x)		(a3->z - a2->z)		(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fmul    st, st(5)                     //(a3->x - a2->x)*(a1->y - a2->y)											(a3->y - a2->y)*(a1->x - a2->x)												((a3->z - a2->z)*(a1->y - a2->y)-(a3->y - a2->y)*(a1->z - a2->z))*(pCamera->dword_000000 - a2->x)		(a3->z - a2->z)		(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fsubp   st(1), st                     //(a3->y - a2->y)*(a1->x - a2->x)-(a3->x - a2->x)*(a1->y - a2->y)							((a3->z - a2->z)*(a1->y - a2->y)-(a3->y - a2->y)*(a1->z - a2->z))*(pCamera->dword_000000 - a2->x)		(a3->z - a2->z)														(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fild    pCamera->dword_000004 //pCamera->dword_000004											(a3->y - a2->y)*(a1->x - a2->x)-(a3->x - a2->x)*(a1->y - a2->y)								((a3->z - a2->z)*(a1->y - a2->y)-(a3->y - a2->y)*(a1->z - a2->z))*(pCamera->dword_000000 - a2->x)		(a3->z - a2->z)		(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fsub    dword ptr [esi+4]             //(pCamera->dword_000004 - a2->z)										(a3->y - a2->y)*(a1->x - a2->x)-(a3->x - a2->x)*(a1->y - a2->y)								((a3->z - a2->z)*(a1->y - a2->y)-(a3->y - a2->y)*(a1->z - a2->z))*(pCamera->dword_000000 - a2->x)		(a3->z - a2->z)		(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fmulp   st(1), st                     //((a3->y - a2->y)*(a1->x - a2->x)-(a3->x - a2->x)*(a1->y - a2->y))*(pCamera->dword_000004 - a2->z)		((a3->z - a2->z)*(a1->y - a2->y)-(a3->y - a2->y)*(a1->z - a2->z))*(pCamera->dword_000000 - a2->x)		(a3->z - a2->z)														(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
//@1 = ((a3->y - a2->y)*(a1->x - a2->x)-(a3->x - a2->x)*(a1->y - a2->y))*(pCamera->dword_000004 - a2->z) + ((a3->z - a2->z)*(a1->y - a2->y)-(a3->y - a2->y)*(a1->z - a2->z))*(pCamera->dword_000000 - a2->x)

    faddp   st(1), st                     //@1															(a3->z - a2->z)								(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fld     st(2)                         //(a3->x - a2->x)													@1									(a3->z - a2->z)		(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fmul    st, st(5)                     //(a3->x - a2->x)*(a1->z - a2->z)											@1									(a3->z - a2->z)		(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fld     st(2)                         //(a3->z - a2->z)													(a3->x - a2->x)*(a1->z - a2->z)						@1			(a3->z - a2->z)		(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fmul    st, st(7)                     //(a3->z - a2->z)*(a1->x - a2->x)											(a3->x - a2->x)*(a1->z - a2->z)						@1			(a3->z - a2->z)		(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fsubp   st(1), st                     //(a3->x - a2->x)*(a1->z - a2->z)-(a3->z - a2->z)*(a1->x - a2->x)							@1									(a3->z - a2->z)		(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fild    pCamera->dword_000008 //pCamera->dword_000008											(a3->x - a2->x)*(a1->z - a2->z)-(a3->z - a2->z)*(a1->x - a2->x)		@1			(a3->z - a2->z)		(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fsub    dword ptr [esi+8]             //(pCamera->dword_000008 - a2->y)										(a3->x - a2->x)*(a1->z - a2->z)-(a3->z - a2->z)*(a1->x - a2->x)		@1			(a3->z - a2->z)		(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fmulp   st(1), st                     //((a3->x - a2->x)*(a1->z - a2->z)-(a3->z - a2->z)*(a1->x - a2->x))*(pCamera->dword_000008 - a2->y)		@1									(a3->z - a2->z)		(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
//@2 = @1 + ((a3->x - a2->x)*(a1->z - a2->z)-(a3->z - a2->z)*(a1->x - a2->x))*(pCamera->dword_000008 - a2->y)

    faddp   st(1), st                     //@2			(a3->z - a2->z)		(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fcomp   0.0f                          //(a3->z - a2->z)	(a3->x - a2->x)		(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fstp    st                            //(a3->x - a2->x)	(a1->y - a2->y)		(a1->z - a2->z)		(a1->x - a2->x)
    fstp    st                            //(a1->y - a2->y)	(a1->z - a2->z)		(a1->x - a2->x)
    fstp    st                            //(a1->z - a2->z)	(a1->x - a2->x)
    fnstsw  ax
    fstp    st                            //(a1->x - a2->x)
    fstp    st                            //empty
    */
  if (((a3->y - a2->y) * (a1->x - a2->x) - (a3->x - a2->x) * (a1->y - a2->y)) * (pCamera->dword_000004 - a2->z) +
      ((a3->z - a2->z) * (a1->y - a2->y) - (a3->y - a2->y) * (a1->z - a2->z)) * (pCamera->dword_000000 - a2->x) +
      ((a3->x - a2->x) * (a1->z - a2->z) - (a3->z - a2->z) * (a1->x - a2->x)) * (pCamera->dword_000008 - a2->y) < 0)
  {
   /*
      fld     [ebp+var_4]                    //var_4
      fmul    [ebp+var_14]                   //var_4 * var_14
      fld     [ebp+var_8]                    //var_8					var_4 * var_14
      fmul    [ebp+arg_0]                    //var_8 * arg_0				var_4 * var_14
      fsubp   st(1), st                      //(var_4 * var_14 - var_8 * arg_0)
      fstp    [ebp+arg_4]                    //empty
   */
   arg_4 = var_4 * var_14 - var_8 * arg_0;

   /*
   //arg_4 rounding
      fld     [ebp+arg_4]                    //arg_4
      fadd    dword ptr ds:byte_4D8410+3C0h  //arg_4 + const
      fstp    [ebp+var_20]                   //empty
   */
   a4->dword_000018 = floorf(arg_4 + 0.5f);

   /*
      fld     [ebp+var_10]                   //var_10
      fmul    [ebp+arg_0]                    //var_10 * arg_0
      fld     [ebp+var_4]                    //var_4		var_10 * arg_0
      fmul    [ebp+var_C]                    //var_4 * var_c	var_10 * arg_0

      fsubp   st(1), st                      //(var_10 * arg_0 - var_4 * var_c)
      fstp    [ebp+arg_4]                    //empty
   */
   arg_4 = var_10 * arg_0 - var_4 * var_c;

   /*
      fld     [ebp+arg_4]
      fadd    dword ptr ds:byte_4D8410+3C0h
      fstp    [ebp+var_20]
   */
   a4->dword_00001C = floorf(arg_4 + 0.5f);

   /*
      fld     [ebp+var_8]                   //var_8
      fmul    [ebp+var_C]                   //var_8 * var_c
      fld     [ebp+var_10]                  //var_10				var_8 * var_c
      fmul    [ebp+var_14]                  //var_10 * var_14			var_8 * var_c
      fsubp   st(1), st                     //(var_8 * var_c - var_10 * var_14)
      fstp    [ebp+arg_4]
   */
   arg_4 = var_8 * var_c - var_10 * var_14;

   /*
      fld     [ebp+arg_4]
      fadd    dword ptr ds:byte_4D8410+3C0h
      fstp    [ebp+var_20]
   */
   a4->dword_000020 = floorf(arg_4 + 0.5f);

   sub_486089_NormalizeVector(a4);

   /*
      fild    dword ptr [edi+18h]           //a4->dword_000018
      fmul    dword ptr [esi+0Ch]           //a4->dword_000018 * a2->float_00000C
      fchs                                  //-(a4->dword_000018 * a2->flt_00000C)
      fild    dword ptr [edi+1Ch]           //a4->dword_00001C														-(a4->dword_000018 * a2->flt_00000C)
      fmul    dword ptr [esi+10h]           //a4->dword_00001C * a2->float_000010											-(a4->dword_000018 * a2->flt_00000C)
      fsubp   st(1), st                     //-(a4->dword_000018 * a2->flt_00000C) - a4->dword_00001C * a2->flt_000010
      fild    dword ptr [edi+20h]           //a4->dword_000020														-(a4->dword_000018 * a2->flt_00000C) - a4->dword_00001C * a2->flt_000010
      fmul    dword ptr [esi+14h]           //a4->dword_000020 * a2->float_000014											-(a4->dword_000018 * a2->flt_00000C) - a4->dword_00001C * a2->flt_000010
      fsubp   st(1), st                     //-(a4->dword_000018 * a2->flt_00000C) - a4->dword_00001C * a2->flt_000010 - a4->dword_000020 * a2->flt_000014
      fstp    [ebp+arg_4]                   //empty
   */
   arg_4 = -(a4->dword_000018 * a2->flt_00000C) - a4->dword_00001C * a2->flt_000010 - a4->dword_000020 * a2->flt_000014;

   /*
      fld     [ebp+arg_4]
      fadd    dword ptr ds:byte_4D8410+3C0h
      fstp    [ebp+var_20]
   */
   a4->dword_000024 = floorf(arg_4 + 0.5f);
   return true;
  }
  else
    return false;
}

//----- (004823F4) --------------------------------------------------------
bool __fastcall sub_4823F4(signed int a1, signed int a2)
{
  int v2; // eax@1
  int v3; // ebx@1
  int v4; // edi@1
  int v6; // esi@5
  int v7; // eax@6
  int v8; // edx@6
  int v9; // ecx@6
  int v10; // esi@10
  signed int v11; // [sp+14h] [bp-8h]@1
  signed int v12; // [sp+18h] [bp-4h]@1

  v12 = a1;
  v11 = a2;
  v3 = WorldPosToGridCellX(a1);
  v4 = WorldPosToGridCellZ(v11) - 1;
  dword_76D568 = sub_47F469(v3);
  dword_76D56C = sub_47F469(v3 + 1);
  dword_76D570 = sub_47F469(v3 + 1);
  dword_76D574 = sub_47F469(v3);
  dword_76D558 = sub_47F476(v4);
  dword_76D55C = sub_47F476(v4);
  dword_76D560 = sub_47F476(v4 + 1);
  dword_76D564 = sub_47F476(v4 + 1);
  dword_76D548 = class51_sub_47EE16_ActuallyGetHeightOnTerrain(pClass51_global, v3, v4);
  dword_76D54C = class51_sub_47EE16_ActuallyGetHeightOnTerrain(pClass51_global, v3 + 1, v4);
  dword_76D550 = class51_sub_47EE16_ActuallyGetHeightOnTerrain(pClass51_global, v3 + 1, v4 + 1);
  v2 = class51_sub_47EE16_ActuallyGetHeightOnTerrain(pClass51_global, v3, v4 + 1);
  dword_76D554 = v2;
  if ( dword_76D548 == dword_76D54C && dword_76D54C == dword_76D550 && dword_76D550 == v2 )
    return 0;
  v6 = abs(v12 - dword_76D568);
  if ( abs(dword_76D558 - v11) >= v6 )
  {
    v9 = dword_76D554;
    v8 = dword_76D550;
    v7 = dword_76D548;
  }
  else
  {
    v9 = dword_76D54C;
    v8 = dword_76D548;
    v7 = dword_76D550;
  }
  if ( v9 >= v8 )
  {
    v10 = v8;
    if ( v8 < v7 )
      goto LABEL_13;
LABEL_12:
    v10 = v7;
    goto LABEL_13;
  }
  if ( v9 >= v7 )
    goto LABEL_12;
  v10 = v9;
LABEL_13:
  if ( v9 <= v8 )
  {
    if ( v8 > v7 )
      v7 = v8;
  }
  else
  {
    if ( v9 > v7 )
      v7 = v9;
  }
  return v7 - v10 > 512;
}

//----- (00482A90) --------------------------------------------------------
signed int __cdecl sub_482A90()
{
  return 1;
}

//----- (00482A94) --------------------------------------------------------
signed int __thiscall sub_482A94(int this)
{
  signed int v1; // ebx@1
  int ebp0; // ebp@0
  int v3; // edi@1
  int v4; // esi@1
  int v5; // ecx@1
  int v6; // eax@1
  int v7; // eax@1
  int v8; // edx@1
  int v9; // eax@1
  int v10; // ecx@1
  int v11; // edx@1
  int v12; // ebx@1
  int v13; // eax@1
  int v14; // ebx@2
  signed int v15; // ebx@3
  signed __int64 v16; // qtt@3
  int v17; // eax@3
  int v18; // eax@14
  int v19; // eax@15
  int v20; // eax@21
  signed int v21; // eax@21
  int v22; // ecx@21
  int v23; // eax@21
  int v24; // edx@21
  int v25; // eax@21
  signed int v27; // [sp-4h] [bp-A4h]@8
  int v28; // [sp+Ch] [bp-94h]@1
  int v29; // [sp+10h] [bp-90h]@1
  char v30; // [sp+14h] [bp-8Ch]@21
  int v31; // [sp+3Ch] [bp-64h]@21
  int v32; // [sp+40h] [bp-60h]@21
  int v33; // [sp+44h] [bp-5Ch]@21
  int v34; // [sp+48h] [bp-58h]@21
  int v35; // [sp+4Ch] [bp-54h]@21
  int v36; // [sp+60h] [bp-40h]@21
  int v37; // [sp+64h] [bp-3Ch]@1
  int v38; // [sp+68h] [bp-38h]@21
  int v39; // [sp+6Ch] [bp-34h]@21
  char *v40; // [sp+70h] [bp-30h]@21
  int v41; // [sp+74h] [bp-2Ch]@3
  int v42; // [sp+78h] [bp-28h]@21
  int v43; // [sp+7Ch] [bp-24h]@21
  int v44; // [sp+80h] [bp-20h]@1
  int v45; // [sp+84h] [bp-1Ch]@1
  int v46; // [sp+88h] [bp-18h]@1
  int v47; // [sp+8Ch] [bp-14h]@1
  int v48; // [sp+90h] [bp-10h]@1
  int v49; // [sp+94h] [bp-Ch]@1
  int v50; // [sp+98h] [bp-8h]@1
  int X; // [sp+9Ch] [bp-4h]@1

  v3 = this;
  v4 = *(_DWORD *)(this + 4);
  v5 = pStruct9_global->dword_000018 * (class28_global.dword_00002C - *(_WORD *)(this + 10));
  v6 = *(_DWORD *)(v4 + 56);
  v50 = v5;
  v49 = *(_DWORD *)(v6 + 20);
  v50 = (unsigned __int64)(v49 * v5) >> 16;
  v7 = *(_DWORD *)(v4 + 56);
  v8 = v50 + *(_DWORD *)(v7 + 12);
  v49 = *(_DWORD *)(v7 + 32);
  v45 = v8;
  v9 = ((unsigned __int64)(v49 * v5) >> 16) + *(_DWORD *)(*(_DWORD *)(v4 + 56) + 24);
  v50 = v5;
  v46 = v9;
  v49 = *(_DWORD *)(v4 + 32);
  v50 = (unsigned __int64)(v49 * v5) >> 16;
  v10 = *(_DWORD *)(v4 + 24);
  v28 = *(_DWORD *)(v4 + 40) << 16;
  v47 = *(_DWORD *)(v4 + 44) << 16;
  v11 = *(_WORD *)(v3 + 8);
  v29 = pStruct9_global->camera_rotation_y_int_sine;
  v44 = pStruct9_global->camera_rotation_y_int_cosine;
  v37 = *(_WORD *)(v3 + 12);
  v12 = *(_DWORD *)(v4 + 36);
  v49 = pStruct9_global->dword_000018 * (class28_global.dword_000028 - v11);
  v13 = *(_DWORD *)(v4 + 28);
  v1 = -v12;
  v48 = v1;
  X = ((unsigned __int64)(v49 * v13) >> 16) + v50 + v10;
  if ( !X || (v14 = abs(v1 >> 14), v14 > abs(X)) )
    return 0;
  LODWORD(v16) = v48 << 16;
  HIDWORD(v16) = v48 >> 16;
  v50 = v16 / X;
  v17 = *(_DWORD *)(v4 + 56);
  X = v49;
  v48 = *(_DWORD *)(v17 + 16);
  X = v49;
  v48 = v45 + ((unsigned __int64)(v48 * v49) >> 16);
  v45 = *(_DWORD *)(*(_DWORD *)(v4 + 56) + 28);
  X = (unsigned __int64)(v45 * v49) >> 16;
  v46 += (unsigned __int64)(v45 * v49) >> 16;
  v15 = 2;
  v41 = *(_DWORD *)(*(_DWORD *)(v4 + 60) + 56);
  if ( v50 >= dword_6BE0E4 << 16 )
  {
    if ( v50 >= dword_6BE0E8 << 16 )
    {
      if ( v50 >= dword_6BE0EC << 16 )
      {
        if ( bUseLoResSprites )
          goto LABEL_12;
        v27 = 3;
      }
      else
      {
        v27 = 2;
      }
      v15 = v27;
      goto LABEL_12;
    }
    v15 = 1;
  }
  else
  {
    v15 = 0;
  }
LABEL_12:
  if ( v15 < *(_DWORD *)(v4 + 72) )
    v15 = *(_DWORD *)(v4 + 72);
  v18 = *(_DWORD *)(v4 + 60);
  if ( v15 )
  {
    if ( v15 == 1 )
    {
      v19 = *(_DWORD *)(v18 + 52);
    }
    else
    {
      if ( v15 == 2 )
        v19 = *(_DWORD *)(v18 + 56);
      else
        v19 = *(_DWORD *)(v18 + 60);
    }
  }
  else
  {
    v19 = *(_DWORD *)(v18 + 48);
  }
  v41 = v19;
  X = (unsigned __int64)(v48 * v50) >> 16;
  v20 = *(_DWORD *)(v4 + 56);
  X = v50;
  v39 = v28 + ((unsigned __int64)(v48 * v50) >> 16) - *(_DWORD *)(v20 + 36);
  X = (unsigned __int64)(v46 * v50) >> 16;
  v21 = X - *(_DWORD *)(*(_DWORD *)(v4 + 56) + 40) - v47;
  v22 = v15 + (unsigned __int8)bUseLoResSprites;
  v39 >>= v22;
  v38 = v21 >> v22;
  v47 = pStruct9_global->dword_000018;
  v49 = (signed int)((unsigned __int64)(pStruct9_global->dword_000018 * v50) >> 16) >> v22;
  v32 = (unsigned __int64)(v49 * v29) >> 16;
  X = (unsigned __int64)(v49 * v44) >> 16;
  v31 = -(signed int)((unsigned __int64)(v49 * v44) >> 16);
  v23 = *(_WORD *)(v3 + 10);
  v43 = pD3DRenderer->pTargetSurface + (*(_WORD *)(v3 + 8) + pD3DRenderer->uTargetSurfacePitch * *(_WORD *)(v3 + 10));
  HIWORD(v22) = HIWORD(v50);
  v42 = pD3DRenderer->pActiveZBuffer + 4 * (*(_WORD *)(v3 + 8) + 640 * v23);
  LOWORD(v22) = 0;
  v36 = v22 | *(_WORD *)(v4 + 80);
  v24 = *(_DWORD *)(v4 + 60);
  v44 = (signed int)*(_WORD *)(v24 + 24) >> v15;
  v25 = ((signed int)*(_WORD *)(v24 + 26) >> v15 << 16) - 65536;
  v35 = v15 - *(_WORD *)(v24 + 28) + 16;
  v34 = v44 - 1;
  v33 = v25;
  v40 = sub_485E1F((int)&v30, v3, v50, v4, dword_6BE0DC, 1u, 1);
  if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
    sub_485975((int)&v31, (int)&v30);
  else
    sub_4D6FB0(ebp0);
  return 1;
}

//----- (00482E07) --------------------------------------------------------
signed int __fastcall sub_482E07(int a1, int a2)
{
  int v2; // eax@1
  int ebp0; // ebp@0
  int v4; // edi@1
  int v5; // esi@1
  int v6; // edi@1
  int v7; // edi@1
  int v8; // eax@1
  int v9; // eax@1
  int v10; // edx@1
  int v11; // eax@1
  int v12; // eax@1
  unsigned __int64 v13; // qax@1
  signed __int64 v14; // qtt@3
  int v15; // ebx@4
  int v16; // eax@5
  signed __int64 v17; // qtt@5
  int v18; // eax@7
  int v19; // eax@8
  int v20; // eax@10
  int v21; // eax@12
  int v22; // eax@14
  int v23; // ebx@17
  int v24; // ecx@17
  int v25; // ebx@17
  signed int v26; // edx@17
  signed int v27; // eax@17
  int v28; // eax@18
  int v29; // eax@18
  int v30; // eax@18
  int v31; // eax@18
  int v32; // edx@18
  int v33; // edi@21
  signed int v34; // ecx@22
  signed __int64 v35; // qtt@22
  int v36; // eax@24
  int v37; // eax@24
  int v38; // edi@24
  int v39; // eax@24
  int v41; // edi@35
  signed __int64 v42; // qtt@36
  int v43; // edx@36
  int v44; // eax@36
  int v45; // edi@36
  int v46; // eax@36
  int v47; // edi@44
  int v48; // eax@44
  int v49; // eax@44
  int v50; // eax@44
  int v51; // ecx@44
  int v52; // edx@44
  int v53; // edi@46
  signed int v54; // ecx@47
  signed __int64 v55; // qtt@47
  int v56; // eax@49
  int v57; // eax@49
  int v58; // edi@49
  int v59; // eax@49
  int v61; // edi@60
  signed __int64 v62; // qtt@61
  int v63; // edx@61
  int v64; // eax@61
  int v65; // edi@61
  int v66; // eax@61
  int v68; // [sp+Ch] [bp-B8h]@1
  int v69; // [sp+10h] [bp-B4h]@1
  int v70; // [sp+14h] [bp-B0h]@1
  int v71; // [sp+18h] [bp-ACh]@1
  int v72; // [sp+1Ch] [bp-A8h]@5
  int v73; // [sp+20h] [bp-A4h]@1
  signed int v74; // [sp+24h] [bp-A0h]@1
  char v75; // [sp+28h] [bp-9Ch]@18
  int v76; // [sp+50h] [bp-74h]@17
  float v77; // [sp+54h] [bp-70h]@24
  int v78; // [sp+58h] [bp-6Ch]@24
  int v79; // [sp+5Ch] [bp-68h]@17
  int v80; // [sp+60h] [bp-64h]@17
  int v81; // [sp+64h] [bp-60h]@17
  int v82; // [sp+68h] [bp-5Ch]@18
  int v83; // [sp+6Ch] [bp-58h]@18
  int v84; // [sp+70h] [bp-54h]@18
  int v85; // [sp+74h] [bp-50h]@18
  int v86; // [sp+78h] [bp-4Ch]@5
  int v87; // [sp+7Ch] [bp-48h]@24
  int v88; // [sp+80h] [bp-44h]@18
  int v89; // [sp+84h] [bp-40h]@18
  char *v90; // [sp+88h] [bp-3Ch]@18
  int v91; // [sp+8Ch] [bp-38h]@7
  int v92; // [sp+90h] [bp-34h]@18
  int v93; // [sp+94h] [bp-30h]@18
  int v94; // [sp+98h] [bp-2Ch]@1
  int v95; // [sp+9Ch] [bp-28h]@1
  int v96; // [sp+A0h] [bp-24h]@17
  int v97; // [sp+A4h] [bp-20h]@3
  int v98; // [sp+A8h] [bp-1Ch]@3
  int v99; // [sp+ACh] [bp-18h]@1
  int X; // [sp+B0h] [bp-14h]@2
  int v101; // [sp+B4h] [bp-10h]@1
  int v102; // [sp+B8h] [bp-Ch]@1
  int v103; // [sp+BCh] [bp-8h]@1
  int v104; // [sp+C0h] [bp-4h]@18

  v103 = *(_WORD *)(a1 + 12);
  v5 = *(_DWORD *)(a1 + 4);
  v6 = class28_global.dword_00002C - *(_WORD *)(a1 + 10);
  v95 = a2;
  v7 = pStruct9_global->dword_000018 * v6;
  v8 = *(_DWORD *)(v5 + 56);
  v94 = a1;
  v99 = v7;
  v101 = *(_DWORD *)(v8 + 20);
  v99 = (unsigned __int64)(v101 * v7) >> 16;
  v9 = *(_DWORD *)(v5 + 56);
  v10 = v99 + *(_DWORD *)(v9 + 12);
  v101 = *(_DWORD *)(v9 + 32);
  v69 = v10;
  v11 = ((unsigned __int64)(v101 * v7) >> 16) + *(_DWORD *)(*(_DWORD *)(v5 + 56) + 24);
  v99 = v7;
  v73 = v11;
  v101 = *(_DWORD *)(v5 + 32);
  v99 = (unsigned __int64)(v101 * v7) >> 16;
  v70 = *(_DWORD *)(v5 + 40) << 16;
  v71 = *(_DWORD *)(v5 + 44) << 16;
  v74 = -*(_DWORD *)(v5 + 36);
  v4 = pStruct9_global->dword_000018 * (class28_global.dword_000028 - *(_WORD *)(a1 + 8));
  v12 = *(_DWORD *)(v5 + 28);
  v68 = v99 + *(_DWORD *)(v5 + 24);
  v101 = v4;
  v13 = v4 * v12;
  v99 = v13 >> 16;
  v2 = v68 + (v13 >> 16);
  v102 = v2;
  if ( !v2
    || (X = v74 >> 15, v101 = abs(v2), abs(v74 >> 15) >= v101)
    || (LODWORD(v14) = v74 << 16,
        HIDWORD(v14) = v74 >> 16,
        v97 = v14 / v102,
        v98 = v4 - v103 * pStruct9_global->dword_000018,
        v99 = (unsigned __int64)(v98 * *(_DWORD *)(v5 + 28)) >> 16,
        v102 = v68 + v99,
        !(v68 + v99))
    || (v15 = abs(v68 + v99), abs(X) >= v15) )
    return 0;
  LODWORD(v17) = v74 << 16;
  HIDWORD(v17) = v74 >> 16;
  v72 = v17 / v102;
  v16 = v17 / v102;
  v86 = v97;
  if ( v97 >= v16 )
    v86 = v16;
  v18 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 56);
  v91 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 56);
  v102 = 2;
  if ( v86 >= dword_6BE0E4 << 16 )
  {
    if ( v86 >= dword_6BE0E8 << 16 )
    {
      if ( v86 >= dword_6BE0EC << 16 )
      {
        if ( bUseLoResSprites )
          goto LABEL_16;
        v22 = *(_DWORD *)(v5 + 60);
        v102 = 3;
        v18 = *(_DWORD *)(v22 + 60);
      }
      else
      {
        v21 = *(_DWORD *)(v5 + 60);
        v102 = 2;
        v18 = *(_DWORD *)(v21 + 56);
      }
    }
    else
    {
      v20 = *(_DWORD *)(v5 + 60);
      v102 = 1;
      v18 = *(_DWORD *)(v20 + 52);
    }
  }
  else
  {
    v19 = *(_DWORD *)(v5 + 60);
    v102 = 0;
    v18 = *(_DWORD *)(v19 + 48);
  }
  v91 = v18;
LABEL_16:
  if ( v18 )
  {
    v24 = *(_BYTE *)(v5 + 90);
    v101 = *(_WORD *)(v5 + 82);
    v25 = *(_DWORD *)(v5 + 60);
    v76 = v24;
    v96 = v103 >> v24;
    v26 = *(_WORD *)(v25 + 24);
    v99 = v103 - (v103 >> v24 << v24);
    v27 = (signed int)*(_WORD *)(v25 + 26) >> v102;
    v81 = v102 - *(_WORD *)(v25 + 28) + 16;
    v23 = v102 + (unsigned __int8)bUseLoResSprites;
    v79 = (v27 << 16) - 65536;
    v80 = (v26 >> v102) - 1;
    if ( v97 >= v72 )
    {
      v47 = v94;
      v90 = sub_485E1F((int)&v75, v94, v72, v5, dword_6BE0DC, 0, 1);
      v48 = *(_DWORD *)(v5 + 56);
      v97 = v98;
      v104 = *(_DWORD *)(v48 + 16);
      v97 = v98;
      v102 = v69 + ((unsigned __int64)(v104 * v98) >> 16);
      v104 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 28);
      v104 = v73 + ((unsigned __int64)(v104 * v98) >> 16);
      v97 = (unsigned __int64)(v102 * v72) >> 16;
      v49 = *(_DWORD *)(v5 + 56);
      v97 = v72;
      v89 = v70 + ((unsigned __int64)(v102 * v72) >> 16) - *(_DWORD *)(v49 + 36);
      v97 = (unsigned __int64)(v104 * v72) >> 16;
      v50 = ((unsigned __int64)(v104 * v72) >> 16) - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40);
      v89 >>= v23;
      v88 = (v71 + v50) >> v23;
      v82 = dword_80AA20 >> v23;
      v83 = dword_80AA1C >> v23;
      v84 = dword_80AA18 >> v23;
      v51 = *(_WORD *)(v47 + 8);
      v85 = dword_80AA14 >> v23;
      v52 = v51 + pD3DRenderer->uTargetSurfacePitch * *(_WORD *)(v47 + 10);
      v92 = pD3DRenderer->pActiveZBuffer + 4 * (v103 + v51 + 640 * *(_WORD *)(v47 + 10)) - 4;
      v93 = v95 + 2 * (v103 + v52) - 2;
      v98 += pStruct9_global->dword_000018 << v76;
      if ( v96 > 0 )
      {
        do
        {
          v95 = *(_DWORD *)(v5 + 28);
          v104 = (unsigned __int64)(v95 * v98) >> 16;
          v102 = v68 + ((unsigned __int64)(v95 * v98) >> 16);
          if ( v68 + (unsigned int)((unsigned __int64)(v95 * v98) >> 16)
            && (v53 = abs(v68 + ((unsigned __int64)(v95 * v98) >> 16)), abs(X) < v53) )
          {
            LODWORD(v55) = v74 << 16;
            HIDWORD(v55) = v74 >> 16;
            v104 = v55 / v102;
            v54 = v55 / v102;
            v102 = v55 / v102;
          }
          else
          {
            v102 = 1073741824;
            v54 = 1073741824;
          }
          HIWORD(v56) = HIWORD(v54);
          LOWORD(v56) = 0;
          v86 = *(_WORD *)(v5 + 80) | v56;
          v95 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 16);
          v95 = v69 + ((unsigned __int64)(v95 * v98) >> 16);
          v104 = (unsigned __int64)(v95 * v54) >> 16;
          v57 = *(_DWORD *)(v5 + 56);
          v58 = ((unsigned __int64)(v95 * v54) >> 16) - *(_DWORD *)(v57 + 36);
          v95 = *(_DWORD *)(v57 + 28);
          v95 = v73 + ((unsigned __int64)(v95 * v98) >> 16);
          v104 = (unsigned __int64)(v95 * v54) >> 16;
          v59 = (((v71 + v104 - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40)) >> v23) - v88) >> v76;
          v78 = (((v70 + v58) >> v23) - v89) >> v76;
          LODWORD(v77) = v59;
          v87 = v101;
          if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
          {
            if ( *(_BYTE *)(*(_DWORD *)(v5 + 84) + 303) == 1 )
              sub_485BAE((int)&v77, (int)&v75);
            else
              sub_485AFF((int)&v77, (int)&v75);
          }
          else
          {
            if ( *(_BYTE *)(*(_DWORD *)(v5 + 84) + 303) == 1 )
              sub_4D71F8(ebp0);
            else
              sub_4D714C(ebp0);
          }
          v90 = sub_485E1F((int)&v75, v94, v102, v5, dword_6BE0DC, 0, 0);
          v98 += pStruct9_global->dword_000018 << v76;
        }
        while ( v96-- != 1 );
      }
      if ( !v99 )
        return 1;
      v101 = *(_DWORD *)(v5 + 28);
      v104 = (unsigned __int64)(v101 * v98) >> 16;
      v102 = v68 + ((unsigned __int64)(v101 * v98) >> 16);
      if ( v68 + (unsigned int)((unsigned __int64)(v101 * v98) >> 16) )
      {
        v61 = abs(v68 + ((unsigned __int64)(v101 * v98) >> 16));
        if ( abs(X) < v61 )
        {
          LODWORD(v62) = v74 << 16;
          HIDWORD(v62) = v74 >> 16;
          v104 = v62 / v102;
          HIWORD(v63) = (unsigned int)(v62 / v102) >> 16;
          LOWORD(v63) = 0;
          v86 = v63 | *(_WORD *)(v5 + 80);
          v101 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 16);
          v101 = v69 + ((unsigned __int64)(v101 * v98) >> 16);
          v104 = (unsigned __int64)(v101 * (signed int)(v62 / v102)) >> 16;
          v64 = *(_DWORD *)(v5 + 56);
          v65 = ((unsigned __int64)(v101 * (signed int)(v62 / v102)) >> 16) - *(_DWORD *)(v64 + 36);
          v101 = *(_DWORD *)(v64 + 28);
          v101 = v73 + ((unsigned __int64)(v101 * v98) >> 16);
          v104 = (unsigned __int64)(v101 * (signed int)(v62 / v102)) >> 16;
          v66 = (((signed int)(v71
                             + ((unsigned __int64)(v101 * (signed int)(v62 / v102)) >> 16)
                             - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40)) >> v23)
               - v88) >> v76;
          v78 = (((v70 + v65) >> v23) - v89) >> v76;
          LODWORD(v77) = v66;
          v87 = v99;
          if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
          {
            if ( *(_BYTE *)(*(_DWORD *)(v5 + 84) + 303) == 1 )
              sub_485BAE((int)&v77, (int)&v75);
            else
              sub_485AFF((int)&v77, (int)&v75);
          }
          else
          {
            if ( *(_BYTE *)(*(_DWORD *)(v5 + 84) + 303) == 1 )
              sub_4D71F8(ebp0);
            else
              sub_4D714C(ebp0);
          }
          return 1;
        }
      }
    }
    else
    {
      v90 = sub_485E1F((int)&v75, v94, v97, v5, dword_6BE0DC, 1u, 1);
      v28 = *(_DWORD *)(v5 + 56);
      v103 = v4;
      v104 = *(_DWORD *)(v28 + 16);
      v103 = v4;
      v102 = v69 + ((unsigned __int64)(v104 * v4) >> 16);
      v104 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 28);
      v104 = v73 + ((unsigned __int64)(v104 * v4) >> 16);
      v103 = (unsigned __int64)(v102 * v97) >> 16;
      v29 = *(_DWORD *)(v5 + 56);
      v103 = v97;
      v89 = v70 + ((unsigned __int64)(v102 * v97) >> 16) - *(_DWORD *)(v29 + 36);
      v103 = (unsigned __int64)(v104 * v97) >> 16;
      v30 = ((unsigned __int64)(v104 * v97) >> 16) - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40);
      v89 >>= v23;
      v88 = (v71 + v30) >> v23;
      v82 = dword_80AA20 >> v23;
      v83 = dword_80AA1C >> v23;
      v84 = dword_80AA18 >> v23;
      v85 = dword_80AA14 >> v23;
      v31 = *(_WORD *)(v94 + 10);
      v32 = pD3DRenderer->uTargetSurfacePitch * *(_WORD *)(v94 + 10);
      v104 = *(_WORD *)(v94 + 8);
      v93 = v95 + 2 * (v104 + v32);
      v92 = pD3DRenderer->pActiveZBuffer + 4 * (v104 + 640 * v31);
      v98 = v4 - (pStruct9_global->dword_000018 << v76);
      if ( v96 > 0 )
      {
        v104 = v96;
        do
        {
          v96 = *(_DWORD *)(v5 + 28);
          v103 = (unsigned __int64)(v96 * v98) >> 16;
          v102 = v68 + ((unsigned __int64)(v96 * v98) >> 16);
          if ( v68 + (unsigned int)((unsigned __int64)(v96 * v98) >> 16)
            && (v33 = abs(v68 + ((unsigned __int64)(v96 * v98) >> 16)), abs(X) < v33) )
          {
            LODWORD(v35) = v74 << 16;
            HIDWORD(v35) = v74 >> 16;
            v103 = v35 / v102;
            v34 = v35 / v102;
            v102 = v35 / v102;
          }
          else
          {
            v102 = 1073741824;
            v34 = 1073741824;
          }
          HIWORD(v36) = HIWORD(v34);
          LOWORD(v36) = 0;
          v86 = *(_WORD *)(v5 + 80) | v36;
          v96 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 16);
          v96 = v69 + ((unsigned __int64)(v96 * v98) >> 16);
          v103 = (unsigned __int64)(v96 * v34) >> 16;
          v37 = *(_DWORD *)(v5 + 56);
          v38 = ((unsigned __int64)(v96 * v34) >> 16) - *(_DWORD *)(v37 + 36);
          v96 = *(_DWORD *)(v37 + 28);
          v96 = v73 + ((unsigned __int64)(v96 * v98) >> 16);
          v103 = (unsigned __int64)(v96 * v34) >> 16;
          v39 = (((v71 + v103 - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40)) >> v23) - v88) >> v76;
          v78 = (((v70 + v38) >> v23) - v89) >> v76;
          LODWORD(v77) = v39;
          v87 = v101;
          if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
          {
            if ( *(_BYTE *)(*(_DWORD *)(v5 + 84) + 303) == 1 )
              sub_485A24((int)&v77, (int)&v75);
            else
              sub_485975((int)&v77, (int)&v75);
          }
          else
          {
            if ( *(_BYTE *)(*(_DWORD *)(v5 + 84) + 303) == 1 )
              sub_4D705A(ebp0);
            else
              sub_4D6FB0(ebp0);
          }
          v90 = sub_485E1F((int)&v75, v94, v102, v5, dword_6BE0DC, 1u, 0);
          v98 -= pStruct9_global->dword_000018 << v76;
        }
        while ( v104-- != 1 );
      }
      if ( !v99 )
        return 1;
      v101 = *(_DWORD *)(v5 + 28);
      v94 = (unsigned __int64)(v101 * v98) >> 16;
      v102 = v68 + ((unsigned __int64)(v101 * v98) >> 16);
      if ( v68 + (unsigned int)((unsigned __int64)(v101 * v98) >> 16) )
      {
        v41 = abs(v68 + ((unsigned __int64)(v101 * v98) >> 16));
        if ( abs(X) < v41 )
        {
          LODWORD(v42) = v74 << 16;
          HIDWORD(v42) = v74 >> 16;
          X = v42 / v102;
          HIWORD(v43) = (unsigned int)(v42 / v102) >> 16;
          LOWORD(v43) = 0;
          v86 = v43 | *(_WORD *)(v5 + 80);
          v101 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 16);
          v101 = v69 + ((unsigned __int64)(v101 * v98) >> 16);
          X = (unsigned __int64)(v101 * (signed int)(v42 / v102)) >> 16;
          v44 = *(_DWORD *)(v5 + 56);
          v45 = ((unsigned __int64)(v101 * (signed int)(v42 / v102)) >> 16) - *(_DWORD *)(v44 + 36);
          v101 = *(_DWORD *)(v44 + 28);
          v101 = v73 + ((unsigned __int64)(v101 * v98) >> 16);
          X = (unsigned __int64)(v101 * (signed int)(v42 / v102)) >> 16;
          v46 = (((signed int)(v71
                             + ((unsigned __int64)(v101 * (signed int)(v42 / v102)) >> 16)
                             - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40)) >> v23)
               - v88) >> v76;
          v78 = (((v70 + v45) >> v23) - v89) >> v76;
          LODWORD(v77) = v46;
          v87 = v99;
          if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
          {
            if ( *(_BYTE *)(*(_DWORD *)(v5 + 84) + 303) == 1 )
              sub_485A24((int)&v77, (int)&v75);
            else
              sub_485975((int)&v77, (int)&v75);
          }
          else
          {
            if ( *(_BYTE *)(*(_DWORD *)(v5 + 84) + 303) == 1 )
              sub_4D705A(ebp0);
            else
              sub_4D6FB0(ebp0);
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

//----- (004839BD) --------------------------------------------------------
signed int __fastcall sub_4839BD(int a1, int a2)
{
  int v2; // ebx@1
  int ebp0; // ebp@0
  signed int v4; // edi@1
  int v5; // esi@1
  int v6; // eax@1
  int v7; // edi@1
  int v8; // ebx@1
  int v9; // ecx@1
  int v10; // ecx@1
  int v11; // eax@1
  int v12; // eax@1
  int v13; // edx@1
  int v14; // eax@1
  int v15; // edi@1
  int v16; // ecx@1
  int v17; // eax@1
  int v18; // edi@2
  int v19; // eax@3
  signed int v20; // edi@3
  signed __int64 v21; // qtt@3
  int v22; // eax@4
  int v23; // eax@6
  int v24; // eax@8
  int v25; // eax@10
  signed int v26; // edx@13
  int v27; // edi@13
  int v28; // eax@13
  int v29; // edi@13
  signed int v30; // edx@13
  int v31; // ebx@13
  signed int v32; // eax@13
  signed int v33; // eax@13
  int v34; // ebx@13
  int v35; // ebx@15
  int v36; // eax@15
  int v37; // eax@16
  int v38; // ecx@17
  signed __int64 v39; // qtt@17
  int v40; // eax@19
  int v41; // ebx@21
  int v42; // eax@21
  int v43; // ebx@21
  int v44; // eax@21
  char v45; // zf@25
  int v46; // ebx@28
  int v47; // eax@28
  int v48; // eax@28
  int v49; // eax@29
  int v50; // eax@30
  int v51; // ecx@30
  signed __int64 v52; // qtt@30
  int v53; // edx@31
  int v54; // eax@33
  int v55; // ebx@33
  signed int v56; // ebx@33
  int v57; // eax@33
  unsigned __int64 v58; // qax@33
  int v60; // [sp+Ch] [bp-BCh]@1
  int v61; // [sp+10h] [bp-B8h]@1
  int v62; // [sp+14h] [bp-B4h]@2
  int v63; // [sp+18h] [bp-B0h]@1
  int v64; // [sp+1Ch] [bp-ACh]@21
  int v65; // [sp+20h] [bp-A8h]@21
  int v66; // [sp+24h] [bp-A4h]@13
  int v67; // [sp+28h] [bp-A0h]@13
  int v68; // [sp+2Ch] [bp-9Ch]@13
  int v69; // [sp+40h] [bp-88h]@21
  int v70; // [sp+44h] [bp-84h]@13
  int v71; // [sp+48h] [bp-80h]@21
  int v72; // [sp+4Ch] [bp-7Ch]@21
  char *v73; // [sp+50h] [bp-78h]@13
  int v74; // [sp+54h] [bp-74h]@3
  int v75; // [sp+58h] [bp-70h]@1
  int v76; // [sp+5Ch] [bp-6Ch]@1
  char v77; // [sp+60h] [bp-68h]@13
  int v78; // [sp+88h] [bp-40h]@13
  int v79; // [sp+8Ch] [bp-3Ch]@1
  int v80; // [sp+90h] [bp-38h]@13
  int v81; // [sp+94h] [bp-34h]@3
  int v82; // [sp+98h] [bp-30h]@1
  int v83; // [sp+9Ch] [bp-2Ch]@1
  int v84; // [sp+A0h] [bp-28h]@1
  int v85; // [sp+A4h] [bp-24h]@13
  int v86; // [sp+A8h] [bp-20h]@1
  int v87; // [sp+ACh] [bp-1Ch]@3
  int v88; // [sp+B0h] [bp-18h]@1
  int v89; // [sp+B4h] [bp-14h]@1
  int X; // [sp+B8h] [bp-10h]@1
  int v91; // [sp+BCh] [bp-Ch]@21
  int v92; // [sp+C0h] [bp-8h]@13
  int v93; // [sp+C4h] [bp-4h]@1

  v6 = *(_WORD *)(a1 + 10);
  v7 = *(_WORD *)(a1 + 8);
  v5 = *(_DWORD *)(a1 + 4);
  v8 = v7 + pD3DRenderer->uTargetSurfacePitch * *(_WORD *)(a1 + 10);
  v61 = a1;
  v9 = *(_WORD *)(a1 + 12);
  v76 = a2 + 2 * v8;
  v86 = v9;
  v75 = pD3DRenderer->pActiveZBuffer + 4 * (v7 + 640 * v6);
  v2 = pStruct9_global->dword_000018 * (class28_global.dword_000028 - v7);
  v10 = pStruct9_global->dword_000018 * (class28_global.dword_00002C - v6);
  v11 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 20);
  v88 = pStruct9_global->dword_000018 * (class28_global.dword_000028 - v7);
  v84 = v11;
  v93 = (unsigned __int64)(v11 * v10) >> 16;
  v12 = *(_DWORD *)(v5 + 56);
  v13 = v93 + *(_DWORD *)(v12 + 12);
  v84 = *(_DWORD *)(v12 + 32);
  v79 = v13;
  v14 = ((unsigned __int64)(v84 * v10) >> 16) + *(_DWORD *)(*(_DWORD *)(v5 + 56) + 24);
  v93 = v10;
  v82 = v14;
  v84 = *(_DWORD *)(v5 + 32);
  v93 = (unsigned __int64)(v84 * v10) >> 16;
  v15 = *(_DWORD *)(v5 + 36);
  v16 = v93 + *(_DWORD *)(v5 + 24);
  v83 = *(_DWORD *)(v5 + 40) << 16;
  v63 = *(_DWORD *)(v5 + 44) << 16;
  v17 = *(_DWORD *)(v5 + 28);
  v4 = -v15;
  v60 = v16;
  v89 = v4;
  v93 = (unsigned __int64)(v88 * v17) >> 16;
  X = v93 + v16;
  if ( !(v93 + v16) || (v62 = v4 >> 14, v18 = abs(v4 >> 14), v18 > abs(X)) )
    return 0;
  LODWORD(v21) = v89 << 16;
  HIDWORD(v21) = v89 >> 16;
  v81 = v21 / X;
  v20 = v21 / X;
  v19 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 56);
  v74 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 56);
  v87 = 2;
  if ( v20 >= dword_6BE0E4 << 16 )
  {
    if ( v20 >= dword_6BE0E8 << 16 )
    {
      if ( v20 >= dword_6BE0EC << 16 )
      {
        if ( bUseLoResSprites )
          goto LABEL_12;
        v25 = *(_DWORD *)(v5 + 60);
        v87 = 3;
        v19 = *(_DWORD *)(v25 + 60);
      }
      else
      {
        v24 = *(_DWORD *)(v5 + 60);
        v87 = 2;
        v19 = *(_DWORD *)(v24 + 56);
      }
    }
    else
    {
      v23 = *(_DWORD *)(v5 + 60);
      v87 = 1;
      v19 = *(_DWORD *)(v23 + 52);
    }
  }
  else
  {
    v22 = *(_DWORD *)(v5 + 60);
    v87 = 0;
    v19 = *(_DWORD *)(v22 + 48);
  }
  v74 = v19;
LABEL_12:
  if ( v19 )
  {
    v73 = sub_485E1F((int)&v77, v61, v20, v5, dword_6BE0DC, 1u, 1);
    v70 = 16;
    v78 = v86 >> 4;
    v93 = v2;
    v28 = *(_DWORD *)(v5 + 56);
    v84 = v86 - 16 * (v86 >> 4);
    v88 = *(_DWORD *)(v28 + 16);
    v93 = v2;
    v86 = v79 + ((unsigned __int64)(v88 * v2) >> 16);
    v88 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 28);
    v88 = v82 + ((unsigned __int64)(v88 * v2) >> 16);
    v93 = (unsigned __int64)(v86 * v20) >> 16;
    v29 = ((unsigned __int64)(v86 * v20) >> 16) - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 36);
    v93 = (unsigned __int64)(v88 * v81) >> 16;
    v30 = v63 + ((unsigned __int64)(v88 * v81) >> 16) - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40);
    v88 = v87 + (unsigned __int8)bUseLoResSprites;
    v85 = v2 - 16 * pStruct9_global->dword_000018;
    v31 = *(_DWORD *)(v5 + 60);
    v27 = (v83 + v29) >> v88;
    v26 = v30 >> v88;
    v32 = (signed int)*(_WORD *)(v31 + 24) >> v87;
    v86 = (signed __int16)v87;
    v80 = v26;
    v92 = v32;
    v33 = (signed int)*(_WORD *)(v31 + 26) >> v87;
    v34 = v87 - *(_WORD *)(v31 + 28);
    v66 = (v33 << 16) - 65536;
    v93 = 2 * pClass24_global2->dword_000024;
    v68 = v34 + 16;
    v67 = v92 - 1;
    if ( v78 > 0 )
    {
      v86 = v78;
      v78 = 12 - v87;
      do
      {
        v92 = *(_DWORD *)(v5 + 28);
        v36 = (unsigned __int64)(v92 * v85) >> 16;
        v35 = v36 + v60;
        X = v36 + v60;
        if ( v36 + v60 && (v92 = abs(v62), v37 = abs(v35), v92 <= v37) )
        {
          LODWORD(v39) = v89 << 16;
          HIDWORD(v39) = v89 >> 16;
          v92 = v39 / X;
          v38 = v39 / X;
          X = v39 / X;
        }
        else
        {
          X = 1073741824;
          v38 = 1073741824;
        }
        HIWORD(v40) = HIWORD(v38);
        if ( v38 <= v81 )
          HIWORD(v40) = HIWORD(v81);
        LOWORD(v40) = 0;
        v69 = *(_WORD *)(v5 + 80) | v40;
        v91 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 16);
        v91 = v79 + ((unsigned __int64)(v91 * v85) >> 16);
        v92 = (unsigned __int64)(v91 * v38) >> 16;
        v42 = *(_DWORD *)(v5 + 56);
        v43 = ((unsigned __int64)(v91 * v38) >> 16) - *(_DWORD *)(v42 + 36);
        v91 = *(_DWORD *)(v42 + 28);
        v91 = v82 + ((unsigned __int64)(v91 * v85) >> 16);
        v92 = (unsigned __int64)(v91 * v38) >> 16;
        v41 = (v83 + v43) >> v88;
        v91 = (signed int)(v63 + ((unsigned __int64)(v91 * v38) >> 16) - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40)) >> v88;
        v65 = (v41 - v27) >> 4;
        v64 = (v91 - v80) >> 4;
        v72 = v27 + 4 * class59_SinCos(pClass59_global, v93 + (v80 >> v78));
        v44 = class59_SinCos(pClass59_global, v93 + (v27 >> v78) - pClass59_global->uNumTableEntries);
        v71 = v80 + 4 * v44;
        if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
          sub_485975((int)&v64, (int)&v77);
        else
          sub_4D6FB0(ebp0);
        v73 = sub_485E1F((int)&v77, v61, X, v5, dword_6BE0DC, 1u, 0);
        v85 -= 16 * pStruct9_global->dword_000018;
        v45 = v86-- == 1;
        v70 = 16;
        v27 = v41;
        v80 = v91;
      }
      while ( !v45 );
      v26 = v91;
    }
    if ( !v84 )
      return 1;
    v78 = 12 - v87;
    v72 = v27 + 4 * class59_SinCos(pClass59_global, v93 + (v26 >> (12 - v87)));
    v47 = class59_SinCos(pClass59_global, v93 + (v27 >> v78) - pClass59_global->uNumTableEntries);
    v71 = v80 + 4 * v47;
    v91 = *(_DWORD *)(v5 + 28);
    v92 = (unsigned __int64)(v91 * v85) >> 16;
    v48 = (unsigned __int64)(v91 * v85) >> 16;
    v46 = v48 + v60;
    X = v48 + v60;
    if ( v48 + v60 )
    {
      v91 = abs(v62);
      v49 = abs(v46);
      if ( v91 <= v49 )
      {
        LODWORD(v52) = v89 << 16;
        HIDWORD(v52) = v89 >> 16;
        v89 = v52 / X;
        v51 = v52 / X;
        HIWORD(v50) = HIWORD(v81);
        if ( v51 <= v81 )
        {
          LOWORD(v50) = 0;
          v69 = v50 | *(_WORD *)(v5 + 80);
        }
        else
        {
          HIWORD(v53) = HIWORD(v51);
          LOWORD(v53) = 0;
          v69 = v53 | *(_WORD *)(v5 + 80);
        }
        v91 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 16);
        v89 = (unsigned __int64)(v91 * v85) >> 16;
        v91 = v79 + ((unsigned __int64)(v91 * v85) >> 16);
        v79 = (unsigned __int64)(v91 * v51) >> 16;
        v54 = *(_DWORD *)(v5 + 56);
        v55 = v79 - *(_DWORD *)(v54 + 36);
        v91 = *(_DWORD *)(v54 + 28);
        v56 = v83 + v55;
        v83 = (unsigned __int64)(v91 * v85) >> 16;
        v57 = v82 + ((unsigned __int64)(v91 * v85) >> 16);
        v91 = v57;
        v58 = v57 * v51;
        v82 = v58 >> 16;
        LODWORD(v58) = (signed int)(v63 + (v58 >> 16) - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40)) >> v88;
        v65 = ((v56 >> v88) - v27) >> 4;
        v64 = ((_DWORD)v58 - v80) >> 4;
        v70 = v84;
        if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
          sub_485975((int)&v64, (int)&v77);
        else
          sub_4D6FB0(ebp0);
        return 1;
      }
    }
  }
  return 0;
}

//----- (0048408A) --------------------------------------------------------
signed int __thiscall sub_48408A(int this)
{
  signed int v1; // ecx@1
  int v2; // ebx@1
  int ebp0; // ebp@0
  int v4; // edi@1
  int v5; // esi@1
  int v6; // ecx@1
  int v7; // eax@1
  int v8; // eax@1
  int v9; // edx@1
  int v10; // eax@1
  int v11; // ebx@1
  int v12; // eax@1
  int v13; // ecx@1
  int v14; // eax@1
  int v15; // ecx@1
  int v16; // eax@1
  int v17; // ebx@3
  signed __int64 v18; // qtt@3
  int v19; // eax@3
  int v20; // eax@4
  int v21; // eax@4
  int v22; // eax@6
  int v23; // ecx@8
  int v24; // eax@10
  int v25; // ecx@12
  int v26; // eax@12
  signed int v27; // eax@12
  int v28; // eax@14
  int v29; // edx@14
  int v30; // ecx@14
  int v31; // esi@14
  int v32; // edx@14
  int v33; // eax@14
  int v35; // [sp+Ch] [bp-8Ch]@1
  int v36; // [sp+10h] [bp-88h]@1
  char v37; // [sp+14h] [bp-84h]@14
  int v38; // [sp+3Ch] [bp-5Ch]@14
  int v39; // [sp+40h] [bp-58h]@14
  int v40; // [sp+44h] [bp-54h]@14
  int v41; // [sp+48h] [bp-50h]@14
  int v42; // [sp+4Ch] [bp-4Ch]@14
  int v43; // [sp+50h] [bp-48h]@13
  int v44; // [sp+54h] [bp-44h]@13
  int v45; // [sp+58h] [bp-40h]@13
  int v46; // [sp+5Ch] [bp-3Ch]@13
  int v47; // [sp+60h] [bp-38h]@14
  int v48; // [sp+64h] [bp-34h]@1
  int v49; // [sp+68h] [bp-30h]@12
  int v50; // [sp+6Ch] [bp-2Ch]@12
  char *v51; // [sp+70h] [bp-28h]@14
  int v52; // [sp+74h] [bp-24h]@3
  int v53; // [sp+78h] [bp-20h]@14
  int v54; // [sp+7Ch] [bp-1Ch]@14
  int v55; // [sp+80h] [bp-18h]@1
  int v56; // [sp+84h] [bp-14h]@1
  int v57; // [sp+88h] [bp-10h]@1
  int v58; // [sp+8Ch] [bp-Ch]@1
  int v59; // [sp+90h] [bp-8h]@2
  int v60; // [sp+94h] [bp-4h]@1

  v4 = this;
  v5 = *(_DWORD *)(this + 4);
  v6 = pStruct9_global->dword_000018 * (class28_global.dword_00002C - *(_WORD *)(this + 10));
  v7 = *(_DWORD *)(v5 + 56);
  v60 = v6;
  v58 = *(_DWORD *)(v7 + 20);
  v60 = (unsigned __int64)(v58 * v6) >> 16;
  v8 = *(_DWORD *)(v5 + 56);
  v9 = v60 + *(_DWORD *)(v8 + 12);
  v58 = *(_DWORD *)(v8 + 32);
  v55 = v9;
  v10 = ((unsigned __int64)(v58 * v6) >> 16) + *(_DWORD *)(*(_DWORD *)(v5 + 56) + 24);
  v60 = v6;
  v57 = v10;
  v58 = *(_DWORD *)(v5 + 32);
  v60 = (unsigned __int64)(v58 * v6) >> 16;
  v11 = v60 + *(_DWORD *)(v5 + 24);
  v35 = class59_SinCos(pClass59_global, pCamera->sRotationY - pClass59_global->uNumTableEntries);
  v12 = class59_SinCos(pClass59_global, pCamera->sRotationY);
  v13 = *(_WORD *)(v4 + 8);
  v36 = v12;
  v48 = *(_WORD *)(v4 + 12);
  v14 = class28_global.dword_000028 - v13;
  v15 = *(_DWORD *)(v5 + 36);
  v58 = pStruct9_global->dword_000018 * v14;
  v16 = *(_DWORD *)(v5 + 28);
  v1 = -v15;
  v56 = v1;
  v2 = ((unsigned __int64)(v58 * v16) >> 16) + v11;
  v60 = v2;
  if ( !v2 || (v59 = abs(v1 >> 14), v59 > abs(v2)) )
    return 0;
  LODWORD(v18) = v56 << 16;
  HIDWORD(v18) = v56 >> 16;
  v59 = v18 / v60;
  v19 = *(_DWORD *)(v5 + 56);
  v60 = v58;
  v56 = *(_DWORD *)(v19 + 16);
  v60 = v58;
  v56 = v55 + ((unsigned __int64)(v56 * v58) >> 16);
  v55 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 28);
  v60 = (unsigned __int64)(v55 * v58) >> 16;
  v17 = v59;
  v57 += (unsigned __int64)(v55 * v58) >> 16;
  v52 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 56);
  v60 = 2;
  if ( v59 < dword_6BE0F0 << 16 )
  {
    v21 = *(_DWORD *)(v5 + 60);
    v60 = 0;
    v20 = *(_DWORD *)(v21 + 48);
LABEL_11:
    v52 = v20;
    goto LABEL_12;
  }
  if ( v59 < dword_6BE0F4 << 16 )
  {
    v22 = *(_DWORD *)(v5 + 60);
    v60 = 1;
    v20 = *(_DWORD *)(v22 + 52);
    goto LABEL_11;
  }
  if ( v59 >= dword_6BE0F8 << 16 )
  {
    if ( !bUseLoResSprites )
    {
      v24 = *(_DWORD *)(v5 + 60);
      v60 = 3;
      v20 = *(_DWORD *)(v24 + 60);
      goto LABEL_11;
    }
  }
  else
  {
    v23 = *(_DWORD *)(v5 + 60);
    v60 = 2;
    v52 = *(_DWORD *)(v23 + 56);
  }
LABEL_12:
  v59 = (unsigned __int64)(v56 * v59) >> 16;
  v26 = *(_DWORD *)(v5 + 56);
  v59 = v17;
  v50 = ((unsigned __int64)(v56 * v17) >> 16) - *(_DWORD *)(v26 + 36);
  v59 = (unsigned __int64)(v57 * v17) >> 16;
  v27 = ((unsigned __int64)(v57 * v17) >> 16) - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40);
  v25 = (unsigned __int8)bUseLoResSprites + v60 + 2;
  v50 >>= v25;
  v57 = (unsigned __int8)bUseLoResSprites + v60 + 2;
  v49 = v27 >> v25;
  if ( byte_80AA10 )
  {
    v43 = dword_80AA20 >> v25;
    v44 = dword_80AA1C >> v25;
    v45 = dword_80AA18 >> v25;
    v46 = dword_80AA14 >> v25;
  }
  v57 = pStruct9_global->dword_000018;
  v58 = (signed int)((unsigned __int64)(pStruct9_global->dword_000018 * v17) >> 16) >> v25;
  v39 = (unsigned __int64)(v58 * v35) >> 16;
  v59 = (unsigned __int64)(v58 * v36) >> 16;
  v38 = (unsigned __int64)(v58 * v36) >> 16;
  v51 = sub_485E1F((int)&v37, v4, v17, v5, dword_6BE0E0, 1u, 1);
  LOWORD(v17) = 0;
  v28 = *(_WORD *)(v4 + 10);
  v29 = *(_WORD *)(v4 + 10);
  v47 = v17;
  v30 = *(_WORD *)(v4 + 8);
  v54 = pD3DRenderer->pTargetSurface + (v30 + pD3DRenderer->uTargetSurfacePitch * v29);
  v53 = pD3DRenderer->pActiveZBuffer + 4 * (v30 + 640 * v28);
  v31 = *(_DWORD *)(v5 + 60);
  v32 = ((signed int)*(_WORD *)(v31 + 24) >> v60) - 1;
  v33 = ((signed int)*(_WORD *)(v31 + 26) >> v60 << 16) - 65536;
  v42 = v60 - *(_WORD *)(v31 + 28) + 16;
  v41 = v32;
  v40 = v33;
  if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
  {
    if ( byte_80AA10 )
      sub_485A24((int)&v38, (int)&v37);
    else
      sub_485975((int)&v38, (int)&v37);
  }
  else
  {
    if ( byte_80AA10 )
      sub_4D705A(ebp0);
    else
      sub_4D6FB0(ebp0);
  }
  return 1;
}

//----- (00484442) --------------------------------------------------------
signed int __thiscall sub_484442(int this)
{
  signed int v1; // ecx@1
  int v2; // ebx@1
  int ebp0; // ebp@0
  int v4; // edi@1
  int v5; // esi@1
  int v6; // ecx@1
  int v7; // eax@1
  int v8; // eax@1
  int v9; // edx@1
  int v10; // eax@1
  int v11; // ebx@1
  int v12; // eax@1
  int v13; // ecx@1
  int v14; // eax@1
  int v15; // ecx@1
  int v16; // ecx@3
  signed int v17; // ebx@3
  signed __int64 v18; // qtt@3
  int v19; // ebx@3
  int v20; // eax@3
  int v21; // eax@3
  int v22; // eax@4
  int v23; // ecx@12
  int v24; // eax@12
  signed int v25; // eax@12
  int v26; // ecx@14
  int v27; // eax@14
  int v28; // esi@14
  signed int v29; // edi@14
  signed int v30; // eax@14
  signed int v32; // [sp+Ch] [bp-90h]@1
  int v33; // [sp+10h] [bp-8Ch]@1
  int v34; // [sp+14h] [bp-88h]@1
  char v35; // [sp+18h] [bp-84h]@14
  int v36; // [sp+40h] [bp-5Ch]@14
  int v37; // [sp+44h] [bp-58h]@14
  int v38; // [sp+48h] [bp-54h]@14
  int v39; // [sp+4Ch] [bp-50h]@14
  int v40; // [sp+50h] [bp-4Ch]@14
  int v41; // [sp+54h] [bp-48h]@13
  int v42; // [sp+58h] [bp-44h]@13
  int v43; // [sp+5Ch] [bp-40h]@13
  int v44; // [sp+60h] [bp-3Ch]@13
  int v45; // [sp+64h] [bp-38h]@3
  int v46; // [sp+68h] [bp-34h]@1
  int v47; // [sp+6Ch] [bp-30h]@12
  int v48; // [sp+70h] [bp-2Ch]@12
  char *v49; // [sp+74h] [bp-28h]@14
  int v50; // [sp+78h] [bp-24h]@3
  int v51; // [sp+7Ch] [bp-20h]@14
  int v52; // [sp+80h] [bp-1Ch]@14
  int v53; // [sp+84h] [bp-18h]@1
  int v54; // [sp+88h] [bp-14h]@1
  int v55; // [sp+8Ch] [bp-10h]@1
  int v56; // [sp+90h] [bp-Ch]@1
  int v57; // [sp+94h] [bp-8h]@1
  int v58; // [sp+98h] [bp-4h]@1

  v4 = this;
  v5 = *(_DWORD *)(this + 4);
  v6 = pStruct9_global->dword_000018 * (class28_global.dword_00002C - *(_WORD *)(this + 10));
  v7 = *(_DWORD *)(v5 + 56);
  v57 = v6;
  v56 = *(_DWORD *)(v7 + 20);
  v57 = (unsigned __int64)(v56 * v6) >> 16;
  v8 = *(_DWORD *)(v5 + 56);
  v9 = v57 + *(_DWORD *)(v8 + 12);
  v56 = *(_DWORD *)(v8 + 32);
  v53 = v9;
  v10 = ((unsigned __int64)(v56 * v6) >> 16) + *(_DWORD *)(*(_DWORD *)(v5 + 56) + 24);
  v57 = v6;
  v55 = v10;
  v56 = *(_DWORD *)(v5 + 32);
  v57 = (unsigned __int64)(v56 * v6) >> 16;
  v11 = v57 + *(_DWORD *)(v5 + 24);
  v33 = class59_SinCos(pClass59_global, pCamera->sRotationY - pClass59_global->uNumTableEntries);
  v12 = class59_SinCos(pClass59_global, pCamera->sRotationY);
  v13 = *(_WORD *)(v4 + 8);
  v34 = v12;
  v46 = *(_WORD *)(v4 + 12);
  v14 = class28_global.dword_000028 - v13;
  v15 = *(_DWORD *)(v5 + 36);
  v58 = pStruct9_global->dword_000018 * v14;
  v1 = -v15;
  v32 = v1;
  v2 = ((unsigned __int64)(pStruct9_global->dword_000018 * v14 * *(_DWORD *)(v5 + 28)) >> 16) + v11;
  v54 = v2;
  if ( !v2 || (v56 = abs(v1 >> 14), v56 > abs(v2)) )
    return 0;
  LODWORD(v18) = v32 << 16;
  HIDWORD(v18) = v32 >> 16;
  v57 = v18 / v54;
  v16 = v18 / v54;
  v19 = v58;
  HIWORD(v20) = (unsigned int)(v18 / v54) >> 16;
  LOWORD(v20) = 0;
  v45 = v20;
  v21 = v53 + ((unsigned __int64)(*(_DWORD *)(*(_DWORD *)(v5 + 56) + 16) * v58) >> 16);
  v58 = v19;
  v54 = v21;
  v53 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 28);
  v58 = (unsigned __int64)(v53 * v19) >> 16;
  v55 += (unsigned __int64)(v53 * v19) >> 16;
  v17 = 2;
  v50 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 56);
  if ( v16 < dword_6BE0F0 << 16 )
  {
    v17 = 0;
    v22 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 48);
LABEL_11:
    v50 = v22;
    goto LABEL_12;
  }
  if ( v16 < dword_6BE0F4 << 16 )
  {
    v17 = 1;
    v22 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 52);
    goto LABEL_11;
  }
  if ( v16 < dword_6BE0F8 << 16 )
  {
    v22 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 56);
    goto LABEL_11;
  }
  if ( !bUseLoResSprites )
  {
    v17 = 3;
    v22 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 60);
    goto LABEL_11;
  }
LABEL_12:
  v58 = (unsigned __int64)(v54 * v16) >> 16;
  v24 = *(_DWORD *)(v5 + 56);
  v58 = v16;
  v48 = ((unsigned __int64)(v54 * v16) >> 16) - *(_DWORD *)(v24 + 36);
  v25 = ((unsigned __int64)(v55 * v16) >> 16) - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40);
  v23 = (unsigned __int8)bUseLoResSprites + v17 + 2;
  v48 >>= v23;
  v55 = (unsigned __int8)bUseLoResSprites + v17 + 2;
  v47 = v25 >> v23;
  if ( byte_80AA10 )
  {
    v41 = dword_80AA20 >> v23;
    v42 = dword_80AA1C >> v23;
    v43 = dword_80AA18 >> v23;
    v44 = dword_80AA14 >> v23;
  }
  v55 = pStruct9_global->dword_000018;
  v56 = (signed int)((unsigned __int64)(pStruct9_global->dword_000018 * v57) >> 16) >> v23;
  v37 = (unsigned __int64)(v56 * v33) >> 16;
  v58 = (unsigned __int64)(v56 * v34) >> 16;
  v36 = (unsigned __int64)(v56 * v34) >> 16;
  v49 = sub_485E1F((int)&v35, v4, v57, v5, dword_6BE0E0, 1u, 1);
  v26 = *(_WORD *)(v4 + 8);
  v27 = pD3DRenderer->pActiveZBuffer + 4 * (v26 + 640 * *(_WORD *)(v4 + 10));
  v52 = pD3DRenderer->pTargetSurface + (v26 + pD3DRenderer->uTargetSurfacePitch * *(_WORD *)(v4 + 10));
  v51 = v27;
  v28 = *(_DWORD *)(v5 + 60);
  v29 = (signed int)*(_WORD *)(v28 + 24) >> v17;
  v30 = (signed int)*(_WORD *)(v28 + 26) >> v17;
  v40 = v17 - *(_WORD *)(v28 + 28) + 16;
  v39 = v29 - 1;
  v38 = (v30 << 16) - 65536;
  if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
  {
    if ( byte_80AA10 )
      sub_485D3E((int)&v36, (int)&v35);
    else
      sub_485C89((int)&v36, (int)&v35);
  }
  else
  {
    if ( byte_80AA10 )
      sub_4D72EC(ebp0);
    else
      sub_4D73DF(ebp0);
  }
  return 1;
}

//----- (004847EB) --------------------------------------------------------
signed int __thiscall sub_4847EB(int this)
{
  int v1; // eax@1
  int v2; // edx@1
  int v3; // ebx@1
  int ebp0; // ebp@0
  int v5; // esi@1
  signed int v6; // eax@3
  signed int v7; // ebx@3
  int v8; // edi@3
  int v9; // eax@3
  int v10; // eax@3
  int v11; // edx@3
  int v12; // eax@3
  int v13; // ebx@4
  signed int v14; // eax@5
  signed int v15; // ebx@5
  signed __int64 v16; // qtt@5
  int v17; // ecx@6
  int v18; // ecx@14
  int v19; // eax@14
  int v20; // eax@14
  signed int v21; // eax@14
  int v22; // edx@16
  signed int v23; // eax@16
  int v24; // ebx@16
  int v25; // ebx@17
  int v26; // edi@17
  int v27; // edi@17
  int v28; // eax@17
  int v29; // eax@18
  int v30; // eax@19
  int v31; // ecx@19
  signed __int64 v32; // qtt@19
  int v33; // eax@21
  signed int v34; // edi@21
  int v35; // ebx@21
  signed int v36; // edi@21
  signed __int64 v37; // qtt@21
  signed int v38; // ebx@21
  int v39; // ebx@29
  int v40; // eax@32
  int v41; // edi@32
  unsigned __int64 v42; // qax@32
  int v43; // eax@33
  int v44; // eax@34
  int v45; // ecx@34
  signed __int64 v46; // qtt@34
  int v47; // eax@36
  signed int v48; // edi@36
  int v49; // eax@36
  int v50; // eax@47
  int v51; // edi@47
  unsigned __int64 v52; // qax@47
  int v53; // eax@48
  int v54; // eax@49
  int v55; // ecx@49
  signed __int64 v56; // qtt@49
  int v57; // eax@51
  signed int v58; // edi@51
  int v59; // eax@51
  int v61; // [sp+Ch] [bp-B0h]@1
  int v62; // [sp+10h] [bp-ACh]@3
  int v63; // [sp+14h] [bp-A8h]@3
  int v64; // [sp+18h] [bp-A4h]@3
  int v65; // [sp+1Ch] [bp-A0h]@3
  signed int v66; // [sp+20h] [bp-9Ch]@3
  signed int v67; // [sp+24h] [bp-98h]@3
  int v68; // [sp+28h] [bp-94h]@1
  char v69; // [sp+2Ch] [bp-90h]@1
  int v70; // [sp+30h] [bp-8Ch]@21
  int v71; // [sp+34h] [bp-88h]@21
  int v72; // [sp+38h] [bp-84h]@16
  int v73; // [sp+3Ch] [bp-80h]@16
  int v74; // [sp+40h] [bp-7Ch]@16
  int v75; // [sp+44h] [bp-78h]@15
  int v76; // [sp+48h] [bp-74h]@15
  int v77; // [sp+4Ch] [bp-70h]@15
  int v78; // [sp+50h] [bp-6Ch]@15
  int v79; // [sp+54h] [bp-68h]@21
  int v80; // [sp+58h] [bp-64h]@21
  int v81; // [sp+5Ch] [bp-60h]@14
  int v82; // [sp+60h] [bp-5Ch]@14
  char *v83; // [sp+64h] [bp-58h]@14
  int v84; // [sp+68h] [bp-54h]@5
  int v85; // [sp+6Ch] [bp-50h]@1
  int v86; // [sp+70h] [bp-4Ch]@1
  char v87; // [sp+74h] [bp-48h]@14
  int v88; // [sp+9Ch] [bp-20h]@5
  int v89; // [sp+A0h] [bp-1Ch]@1
  int X; // [sp+A4h] [bp-18h]@3
  int v91; // [sp+A8h] [bp-14h]@21
  int v92; // [sp+ACh] [bp-10h]@1
  int v93; // [sp+B0h] [bp-Ch]@14
  int v94; // [sp+B4h] [bp-8h]@3
  int v95; // [sp+B8h] [bp-4h]@3

  v3 = *(_WORD *)(this + 10);
  v2 = *(_WORD *)(this + 8);
  v5 = *(_DWORD *)(this + 4);
  v89 = 0;
  v61 = this;
  v85 = pD3DRenderer->pActiveZBuffer + 4 * (v2 + 640 * v3);
  v92 = v2;
  v1 = *(_WORD *)(this + 12);
  v86 = pD3DRenderer->pTargetSurface + (v2 + pD3DRenderer->uTargetSurfacePitch * v3);
  v68 = dword_6BE050;
  v69 = dword_6BE054;
  if ( v1 >= dword_6BE050 )
    v89 = dword_6BE050 - (v2 & (dword_6BE050 - 1));
  v6 = v1 - v89;
  v67 = v6 >> dword_6BE054;
  v62 = v6 - (v6 >> dword_6BE054 << dword_6BE054);
  v8 = pStruct9_global->dword_000018 * (class28_global.dword_000028 - v92);
  v9 = *(_DWORD *)(v5 + 56);
  v95 = pStruct9_global->dword_000018 * (class28_global.dword_000028 - v92);
  v94 = pStruct9_global->dword_000018 * (class28_global.dword_00002C - v3);
  v92 = *(_DWORD *)(v9 + 20);
  v94 = (unsigned __int64)(v92 * pStruct9_global->dword_000018 * (class28_global.dword_00002C - v3)) >> 16;
  v10 = *(_DWORD *)(v5 + 56);
  v11 = v94 + *(_DWORD *)(v10 + 12);
  v92 = *(_DWORD *)(v10 + 32);
  v65 = v11;
  v12 = ((unsigned __int64)(v92 * pStruct9_global->dword_000018 * (class28_global.dword_00002C - v3)) >> 16) + *(_DWORD *)(*(_DWORD *)(v5 + 56) + 24);
  v94 = pStruct9_global->dword_000018 * (class28_global.dword_00002C - v3);
  v64 = v12;
  v92 = *(_DWORD *)(v5 + 32);
  v94 = (unsigned __int64)(v92 * pStruct9_global->dword_000018 * (class28_global.dword_00002C - v3)) >> 16;
  v7 = -*(_DWORD *)(v5 + 36);
  v63 = v94 + *(_DWORD *)(v5 + 24);
  v66 = -*(_DWORD *)(v5 + 36);
  v94 = (unsigned __int64)(v95 * *(_DWORD *)(v5 + 28)) >> 16;
  X = v94 + v63;
  if ( !(v94 + v63) || (v92 = v7 >> 14, v13 = abs(v7 >> 14), v13 > abs(X)) )
    return 0;
  LODWORD(v16) = v66 << 16;
  HIDWORD(v16) = v66 >> 16;
  v88 = v16 / X;
  v84 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 56);
  v14 = v16 / X;
  v15 = 2;
  if ( v14 >= dword_6BE0F0 << 16 )
  {
    if ( v14 >= dword_6BE0F4 << 16 )
    {
      if ( v14 >= dword_6BE0F8 << 16 )
      {
        if ( bUseLoResSprites )
          goto LABEL_14;
        v15 = 3;
        v17 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 60);
      }
      else
      {
        v17 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 56);
      }
    }
    else
    {
      v15 = 1;
      v17 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 52);
    }
  }
  else
  {
    v15 = 0;
    v17 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 48);
  }
  v84 = v17;
LABEL_14:
  v83 = sub_485E1F((int)&v87, v61, v14, v5, dword_6BE0E0, 1u, 1);
  v19 = *(_DWORD *)(v5 + 56);
  v94 = v8;
  v95 = *(_DWORD *)(v19 + 16);
  v94 = v8;
  v93 = v65 + ((unsigned __int64)(v95 * v8) >> 16);
  v95 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 28);
  v95 = v64 + ((unsigned __int64)(v95 * v8) >> 16);
  v94 = (unsigned __int64)(v93 * v88) >> 16;
  v20 = *(_DWORD *)(v5 + 56);
  v94 = v88;
  v82 = ((unsigned __int64)(v93 * v88) >> 16) - *(_DWORD *)(v20 + 36);
  v94 = (unsigned __int64)(v95 * v88) >> 16;
  v21 = ((unsigned __int64)(v95 * v88) >> 16) - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40);
  v18 = (unsigned __int8)bUseLoResSprites + v15 + 2;
  v82 >>= v18;
  v94 = (unsigned __int8)bUseLoResSprites + v15 + 2;
  v81 = v21 >> v18;
  if ( byte_80AA10 )
  {
    v75 = dword_80AA20 >> v18;
    v76 = dword_80AA1C >> v18;
    v77 = dword_80AA18 >> v18;
    v78 = dword_80AA14 >> v18;
  }
  v22 = *(_DWORD *)(v5 + 60);
  v95 = (signed int)*(_WORD *)(v22 + 24) >> v15;
  v23 = (signed int)*(_WORD *)(v22 + 26) >> v15;
  v24 = v15 - *(_WORD *)(v22 + 28) + 16;
  v72 = (v23 << 16) - 65536;
  v74 = v24;
  v73 = v95 - 1;
  if ( v89 )
  {
    v27 = v8 - v89 * pStruct9_global->dword_000018;
    v25 = v27;
    v93 = *(_DWORD *)(v5 + 28);
    v95 = v27;
    v28 = (unsigned __int64)(v93 * v27) >> 16;
    v26 = v28 + v63;
    X = v28 + v63;
    if ( !(v28 + v63) || (v93 = abs(v92), v29 = abs(v26), v93 > v29) )
      return 0;
    LODWORD(v32) = v66 << 16;
    HIDWORD(v32) = v66 >> 16;
    v93 = v32 / X;
    v31 = v32 / X;
    HIWORD(v30) = HIWORD(v88);
    if ( v88 <= v31 )
      HIWORD(v30) = HIWORD(v31);
    LOWORD(v30) = 0;
    v93 = v25;
    v79 = v30;
    X = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 16);
    X = v65 + ((unsigned __int64)(X * v25) >> 16);
    v93 = (unsigned __int64)(X * v31) >> 16;
    v33 = *(_DWORD *)(v5 + 56);
    v93 = v25;
    v34 = ((unsigned __int64)(X * v31) >> 16) - *(_DWORD *)(v33 + 36);
    X = *(_DWORD *)(v33 + 28);
    X = v64 + ((unsigned __int64)(X * v25) >> 16);
    v93 = (unsigned __int64)(X * v31) >> 16;
    v35 = (v93 - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40)) >> v94;
    X = v89 << 16;
    v36 = (v34 >> v94) - v82;
    LODWORD(v37) = v36 << 16;
    HIDWORD(v37) = v36 >> 16;
    v38 = v35 - v81;
    v71 = v37 / (v89 << 16);
    v91 = v89 << 16;
    LODWORD(v37) = v38 << 16;
    HIDWORD(v37) = v38 >> 16;
    v93 = v37 / (v89 << 16);
    v70 = v37 / (v89 << 16);
    v80 = v89;
    if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
    {
      if ( byte_80AA10 )
        sub_485A24((int)&v70, (int)&v87);
      else
        sub_485975((int)&v70, (int)&v87);
    }
    else
    {
      if ( byte_80AA10 )
        sub_4D705A(ebp0);
      else
        sub_4D6FB0(ebp0);
    }
    v39 = v95 - (pStruct9_global->dword_000018 << v69);
  }
  else
  {
    v95 = v8 - (pStruct9_global->dword_000018 << v69);
    v39 = v8 - (pStruct9_global->dword_000018 << v69);
  }
  v80 = v68;
  while ( v67 > 0 )
  {
    v40 = *(_DWORD *)(v5 + 28);
    --v67;
    v91 = v40;
    v42 = v40 * v39;
    v95 = v42 >> 16;
    LODWORD(v42) = v42 >> 16;
    v41 = v42 + v63;
    X = v42 + v63;
    if ( !((_DWORD)v42 + v63) || (v91 = abs(v92), v43 = abs(v41), v91 > v43) )
      return 0;
    LODWORD(v46) = v66 << 16;
    HIDWORD(v46) = v66 >> 16;
    v89 = v46 / X;
    v45 = v46 / X;
    HIWORD(v44) = HIWORD(v88);
    if ( v88 <= v45 )
      HIWORD(v44) = HIWORD(v45);
    LOWORD(v44) = 0;
    v95 = v39;
    v79 = v44;
    v91 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 16);
    v91 = v65 + ((unsigned __int64)(v91 * v39) >> 16);
    v95 = (unsigned __int64)(v91 * v45) >> 16;
    v47 = *(_DWORD *)(v5 + 56);
    v95 = v39;
    v48 = ((unsigned __int64)(v91 * v45) >> 16) - *(_DWORD *)(v47 + 36);
    v91 = *(_DWORD *)(v47 + 28);
    v91 = v64 + ((unsigned __int64)(v91 * v39) >> 16);
    v95 = (unsigned __int64)(v91 * v45) >> 16;
    v49 = (((v95 - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40)) >> v94) - v81) >> v69;
    v71 = ((v48 >> v94) - v82) >> v69;
    v70 = v49;
    if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
    {
      if ( byte_80AA10 )
        sub_485A24((int)&v70, (int)&v87);
      else
        sub_485975((int)&v70, (int)&v87);
    }
    else
    {
      if ( byte_80AA10 )
        sub_4D705A(ebp0);
      else
        sub_4D6FB0(ebp0);
    }
    v83 = sub_485E1F((int)&v87, v61, v89, v5, dword_6BE0E0, 1u, 0);
    v80 = v68;
    v39 -= pStruct9_global->dword_000018 << v69;
  }
  if ( !v62 )
    return 1;
  v50 = *(_DWORD *)(v5 + 28);
  v91 = v50;
  v52 = v50 * v39;
  v95 = v52 >> 16;
  LODWORD(v52) = v52 >> 16;
  v51 = v52 + v63;
  X = v52 + v63;
  if ( (_DWORD)v52 + v63 )
  {
    v91 = abs(v92);
    v53 = abs(v51);
    if ( v91 <= v53 )
    {
      LODWORD(v56) = v66 << 16;
      HIDWORD(v56) = v66 >> 16;
      v92 = v56 / X;
      v55 = v56 / X;
      HIWORD(v54) = HIWORD(v88);
      if ( v88 <= v55 )
        HIWORD(v54) = HIWORD(v55);
      LOWORD(v54) = 0;
      v92 = v39;
      v79 = v54;
      v91 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 16);
      v91 = v65 + ((unsigned __int64)(v91 * v39) >> 16);
      v92 = (unsigned __int64)(v91 * v55) >> 16;
      v57 = *(_DWORD *)(v5 + 56);
      v92 = v39;
      v58 = ((unsigned __int64)(v91 * v55) >> 16) - *(_DWORD *)(v57 + 36);
      v91 = *(_DWORD *)(v57 + 28);
      v91 = v64 + ((unsigned __int64)(v91 * v39) >> 16);
      v92 = (unsigned __int64)(v91 * v55) >> 16;
      v59 = (((v92 - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40)) >> v94) - v81) >> v69;
      v71 = ((v58 >> v94) - v82) >> v69;
      v70 = v59;
      v80 = v62;
      if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
      {
        if ( byte_80AA10 )
          sub_485A24((int)&v70, (int)&v87);
        else
          sub_485975((int)&v70, (int)&v87);
      }
      else
      {
        if ( byte_80AA10 )
          sub_4D705A(ebp0);
        else
          sub_4D6FB0(ebp0);
      }
      return 1;
    }
  }
  return 0;
}

//----- (00485044) --------------------------------------------------------
signed int __fastcall sub_485044(int a1, int a2, int a3)
{
  int v3; // edi@1
  int v4; // esi@1
  float v5; // ST2C_4@1
  signed int result; // eax@2
  int v7; // eax@3
  int v8; // edx@3
  int v9; // ecx@3
  int v10; // ebx@3
  int v11; // ST40_4@3
  int v12; // eax@3
  int v13; // ST28_4@5
  int v14; // eax@5
  int v15; // eax@11
  int v16; // edi@11
  unsigned int v17; // esi@11
  signed __int64 v18; // qtt@11
  int v19; // ST28_4@11
  int v20; // eax@11
  signed int v21; // ecx@11
  int v22; // ST40_4@11
  int v23; // ST3C_4@11
  int v24; // ST30_4@11
  char *v25; // eax@11
  int v26; // esi@11
  int v27; // ecx@11
  int v28; // ebx@12
  int v29; // edx@13
  __int16 v30; // cx@13
  int v31; // edx@14
  __int16 v32; // cx@14
  unsigned __int8 v33; // sf@15
  unsigned __int8 v34; // of@15
  double v35; // [sp+14h] [bp-38h]@1
  int v36; // [sp+18h] [bp-34h]@3
  signed int v37; // [sp+18h] [bp-34h]@11
  int v38; // [sp+1Ch] [bp-30h]@3
  signed int v39; // [sp+1Ch] [bp-30h]@11
  int v40; // [sp+20h] [bp-2Ch]@3
  char *v41; // [sp+20h] [bp-2Ch]@11
  int v42; // [sp+24h] [bp-28h]@3
  int v43; // [sp+24h] [bp-28h]@11
  int v44; // [sp+28h] [bp-24h]@11
  int v45; // [sp+2Ch] [bp-20h]@3
  signed int v46; // [sp+30h] [bp-1Ch]@3
  int v47; // [sp+30h] [bp-1Ch]@11
  signed int v48; // [sp+34h] [bp-18h]@3
  int v49; // [sp+34h] [bp-18h]@11
  int v50; // [sp+38h] [bp-14h]@3
  int v51; // [sp+38h] [bp-14h]@11
  int v52; // [sp+3Ch] [bp-10h]@4
  int v53; // [sp+40h] [bp-Ch]@3
  int v54; // [sp+44h] [bp-8h]@3
  int v55; // [sp+48h] [bp-4h]@3
  int v56; // [sp+54h] [bp+8h]@11
  int v57; // [sp+54h] [bp+8h]@11

  v4 = a2;
  v3 = a1;
  v5 = (double)(class28_global.dword_000018 - class28_global.dword_000010) * 0.5 / tan(*(double *)&byte_4D8410[872])
     + memory_4D8410.d_0_5;
  v35 = v5 + 6.755399441055744e15;
  if ( LODWORD(v35) )
  {
    v55 = 65536 / LODWORD(v35);
    v11 = 65536 / LODWORD(v35) * (a3 - *(_WORD *)(v3 + 10));
    v12 = *(_DWORD *)(v4 + 56);
    v42 = ((unsigned __int64)(*(_DWORD *)(*(_DWORD *)(v4 + 56) + 20) * v11) >> 16) + *(_DWORD *)(v12 + 12);
    v40 = ((unsigned __int64)(*(_DWORD *)(v12 + 32) * v11) >> 16) + *(_DWORD *)(*(_DWORD *)(v4 + 56) + 24);
    v38 = pStruct9_global->camera_rotation_y_int_sine;
    HIDWORD(v35) = pStruct9_global->camera_rotation_y_int_cosine;
    v45 = *(_WORD *)(v3 + 12);
    v10 = ((unsigned __int64)(*(_DWORD *)(v4 + 32) * v11) >> 16) + *(_DWORD *)(v4 + 24);
    v9 = 65536 / LODWORD(v35) * (class28_global.dword_000028 - *(_WORD *)(v3 + 8));
    v48 = 0;
    v50 = 65536 / LODWORD(v35) * (class28_global.dword_000028 - *(_WORD *)(v3 + 8));
    v46 = -*(_DWORD *)(v4 + 36);
    v8 = *(_WORD *)(v3 + 10) - 1;
    v54 = v8;
    v7 = 65536 / LODWORD(v35) * (a3 - v8);
    v53 = 65536 / LODWORD(v35) * (a3 - v8);
    while ( 1 )
    {
      v52 = v10;
      if ( v10 )
      {
        v13 = abs(v46 >> 14);
        v14 = abs(v10);
        v8 = v54;
        v9 = v50;
        if ( v13 <= v14 )
          break;
        v7 = v53;
      }
      if ( v8 <= class28_global.dword_000014 )
        break;
      v10 = ((unsigned __int64)(*(_DWORD *)(v4 + 32) * v7) >> 16) + *(_DWORD *)(v4 + 24);
      --v54;
      v53 += v55;
      v7 = v53;
      v8 = v54;
      v48 = 1;
    }
    if ( v48 )
      v52 = ((unsigned __int64)(*(_DWORD *)(v4 + 32) * v55 * (a3 + (signed int)*(_WORD *)(v3 + 10) - 2 * v8)) >> 16)
          + *(_DWORD *)(v4 + 24);
    LODWORD(v18) = v46 << 16;
    HIDWORD(v18) = v46 >> 16;
    v19 = v42 + ((unsigned __int64)(*(_DWORD *)(*(_DWORD *)(v4 + 56) + 16) * v9) >> 16);
    v20 = v40 + ((unsigned __int64)(*(_DWORD *)(*(_DWORD *)(v4 + 56) + 28) * v9) >> 16);
    v21 = v18 / v52;
    v43 = *(_DWORD *)(*(_DWORD *)(v4 + 60) + 48);
    v22 = *(_DWORD *)(v4 + 40) + ((signed int)((unsigned __int64)(v19 * (signed int)(v18 / v52)) >> 16) >> 3);
    v57 = v18 / v52;
    v23 = *(_DWORD *)(v4 + 44) + ((signed int)((unsigned __int64)(v20 * (signed int)(v18 / v52)) >> 16) >> 3);
    v24 = (unsigned __int64)(v55 * v57) >> 16;
    v39 = (signed int)((unsigned __int64)(v24 * v38) >> 16) >> 3;
    v37 = (signed int)((unsigned __int64)(v24 * v36) >> 16) >> 3;
    v25 = sub_47C178(v21, v4, 0, 1);
    v26 = *(_DWORD *)(v4 + 60);
    v41 = v25;
    v47 = 16 - *(_WORD *)(v26 + 28);
    v44 = *(_WORD *)(v26 + 24) - 1;
    v49 = (*(_WORD *)(v26 + 26) << 16) - 65536;
    v27 = *(_WORD *)(v3 + 8);
    v51 = pD3DRenderer->pTargetSurface + (v27 + pD3DRenderer->uTargetSurfacePitch * *(_WORD *)(v3 + 10));
    v56 = pD3DRenderer->pActiveZBuffer + 4 * (v27 + 640 * *(_WORD *)(v3 + 10));
    v17 = v22;
    v16 = v23;
    v15 = v51;
    if ( !(v45 & 1) )
      goto LABEL_15;
    --v45;
    v15 = v51 - 2;
    v28 = v56;
    v56 += 4;
    while ( 1 )
    {
      *(_DWORD *)v28 = -65536;
      v31 = v44 & (v17 >> 16);
      v15 += 4;
      v17 += v39;
      v32 = *(_WORD *)&v41[2 * *(_BYTE *)(v43 + v31 + ((v49 & (unsigned int)v16) >> v47))];
      v16 += v37;
      *(_WORD *)(v15 - 2) = v32;
LABEL_15:
      compile_error;//v34 = __SETO__(v45, 2);
      v33 = v45 - 2 < 0;
      v45 -= 2;
      if ( v33 ^ v34 )
        break;
      v29 = v44 & (v17 >> 16);
      v17 += v39;
      v30 = *(_WORD *)&v41[2 * *(_BYTE *)(v43 + v29 + ((v49 & (unsigned int)v16) >> v47))];
      v16 += v37;
      v28 = v56;
      *(_WORD *)v15 = v30;
      v56 += 8;
      *(_DWORD *)(v28 + 4) = -65536;
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00485407) --------------------------------------------------------
signed int __fastcall sub_485407(int a1)
{
  int v1; // ebx@1
  int ebp0; // ebp@0
  signed int v3; // edi@1
  int v4; // esi@1
  int v5; // eax@1
  int v6; // edx@1
  int v7; // edi@1
  int v8; // ecx@1
  int v9; // ecx@1
  int v10; // eax@1
  int v11; // eax@1
  int v12; // edx@1
  int v13; // eax@1
  int v14; // eax@1
  int v15; // ecx@1
  int v16; // edi@2
  int v17; // eax@3
  signed int v18; // edi@3
  signed __int64 v19; // qtt@3
  int v20; // eax@3
  int v21; // eax@4
  int v22; // eax@6
  int v23; // eax@8
  int v24; // eax@10
  signed int v25; // ebx@13
  signed int v26; // edi@13
  int v27; // eax@13
  int v28; // eax@13
  signed int v29; // ebx@13
  int v30; // eax@13
  int v31; // esi@13
  signed int v32; // edx@13
  signed int v33; // eax@13
  int v34; // esi@13
  int v35; // eax@13
  unsigned __int64 v36; // qax@13
  int v37; // eax@13
  unsigned __int64 v38; // qax@13
  int v39; // ecx@14
  char v40; // zf@20
  char v42; // [sp+Ch] [bp-90h]@13
  int v43; // [sp+34h] [bp-68h]@13
  int v44; // [sp+38h] [bp-64h]@13
  int v45; // [sp+3Ch] [bp-60h]@13
  int v46; // [sp+40h] [bp-5Ch]@13
  int v47; // [sp+44h] [bp-58h]@13
  int v48; // [sp+58h] [bp-44h]@3
  int v49; // [sp+5Ch] [bp-40h]@13
  int v50; // [sp+60h] [bp-3Ch]@16
  int v51; // [sp+64h] [bp-38h]@16
  char *v52; // [sp+68h] [bp-34h]@13
  int v53; // [sp+6Ch] [bp-30h]@3
  int v54; // [sp+70h] [bp-2Ch]@1
  int v55; // [sp+74h] [bp-28h]@1
  int v56; // [sp+78h] [bp-24h]@1
  int v57; // [sp+7Ch] [bp-20h]@1
  int v58; // [sp+80h] [bp-1Ch]@1
  int v59; // [sp+84h] [bp-18h]@1
  int v60; // [sp+88h] [bp-14h]@1
  int v61; // [sp+8Ch] [bp-10h]@1
  int v62; // [sp+90h] [bp-Ch]@3
  int i; // [sp+94h] [bp-8h]@3
  int X; // [sp+98h] [bp-4h]@1

  v5 = *(_WORD *)(a1 + 10);
  v6 = *(_WORD *)(a1 + 8);
  v7 = v6 + pD3DRenderer->uTargetSurfacePitch * *(_WORD *)(a1 + 10);
  v4 = *(_DWORD *)(a1 + 4);
  v56 = a1;
  v8 = *(_WORD *)(a1 + 12);
  v55 = pD3DRenderer->pTargetSurface + v7;
  v59 = v8;
  v1 = pStruct9_global->dword_000018 * (class28_global.dword_000028 - v6);
  v9 = pStruct9_global->dword_000018 * (class28_global.dword_00002C - v5);
  v54 = pD3DRenderer->pActiveZBuffer + 4 * (v6 + 640 * v5);
  v10 = *(_DWORD *)(v4 + 56);
  v60 = v1;
  X = v9;
  v61 = *(_DWORD *)(v10 + 20);
  X = (unsigned __int64)(v61 * v9) >> 16;
  v11 = *(_DWORD *)(v4 + 56);
  v12 = X + *(_DWORD *)(v11 + 12);
  v61 = *(_DWORD *)(v11 + 32);
  v57 = v12;
  v13 = ((unsigned __int64)(v61 * v9) >> 16) + *(_DWORD *)(*(_DWORD *)(v4 + 56) + 24);
  X = v9;
  v58 = v13;
  v61 = *(_DWORD *)(v4 + 32);
  X = (unsigned __int64)(v61 * v9) >> 16;
  v14 = *(_DWORD *)(v4 + 28);
  v15 = X + *(_DWORD *)(v4 + 24);
  v3 = -*(_DWORD *)(v4 + 36);
  v61 = -*(_DWORD *)(v4 + 36);
  X = ((unsigned __int64)(v1 * v14) >> 16) + v15;
  if ( !X || (v16 = abs(v3 >> 14), v16 > abs(X)) )
    return 0;
  LODWORD(v19) = v61 << 16;
  HIDWORD(v19) = v61 >> 16;
  i = v19 / X;
  v18 = v19 / X;
  HIWORD(v20) = (unsigned int)(v19 / X) >> 16;
  LOWORD(v20) = 0;
  v48 = v20;
  v17 = *(_DWORD *)(*(_DWORD *)(v4 + 60) + 56);
  v53 = *(_DWORD *)(*(_DWORD *)(v4 + 60) + 56);
  v62 = 2;
  if ( v18 >= dword_6BE0F0 << 16 )
  {
    if ( v18 >= dword_6BE0F4 << 16 )
    {
      if ( v18 >= dword_6BE0F8 << 16 )
      {
        if ( bUseLoResSprites )
          goto LABEL_12;
        v24 = *(_DWORD *)(v4 + 60);
        v62 = 3;
        v17 = *(_DWORD *)(v24 + 60);
      }
      else
      {
        v23 = *(_DWORD *)(v4 + 60);
        v62 = 2;
        v17 = *(_DWORD *)(v23 + 56);
      }
    }
    else
    {
      v22 = *(_DWORD *)(v4 + 60);
      v62 = 1;
      v17 = *(_DWORD *)(v22 + 52);
    }
  }
  else
  {
    v21 = *(_DWORD *)(v4 + 60);
    v62 = 0;
    v17 = *(_DWORD *)(v21 + 48);
  }
  v53 = v17;
LABEL_12:
  if ( !v17 )
    return 0;
  v52 = sub_485E1F((int)&v42, v56, v18, v4, dword_6BE0E0, 1u, 1);
  v49 = 16;
  v56 = v59 >> 4;
  X = v1;
  v27 = *(_DWORD *)(v4 + 56);
  v61 = v59 - 16 * (v59 >> 4);
  v59 = *(_DWORD *)(v27 + 16);
  X = v1;
  v59 = v57 + ((unsigned __int64)(v59 * v1) >> 16);
  v57 = *(_DWORD *)(*(_DWORD *)(v4 + 56) + 28);
  v58 += (unsigned __int64)(v57 * v1) >> 16;
  X = (unsigned __int64)(v59 * v18) >> 16;
  v28 = *(_DWORD *)(v4 + 56);
  X = v18;
  v29 = ((unsigned __int64)(v59 * v18) >> 16) - *(_DWORD *)(v28 + 36);
  X = (unsigned __int64)(v58 * v18) >> 16;
  v30 = *(_DWORD *)(v4 + 56);
  v31 = *(_DWORD *)(v4 + 60);
  v57 = (unsigned __int8)bUseLoResSprites + v62 + 2;
  v25 = v29 >> v57;
  v26 = (signed int)(((unsigned __int64)(v58 * v18) >> 16) - *(_DWORD *)(v30 + 40)) >> v57;
  v32 = (signed int)*(_WORD *)(v31 + 24) >> v62;
  v33 = (signed int)*(_WORD *)(v31 + 26) >> v62;
  v34 = v62 - *(_WORD *)(v31 + 28);
  v45 = (v33 << 16) - 65536;
  X = 2 * pClass24_global2->dword_000024;
  v58 = pStruct9_global->dword_000018;
  v47 = v34 + 16;
  v46 = v32 - 1;
  i = (unsigned __int64)(pStruct9_global->dword_000018 * i) >> 16;
  v60 = i >> v57;
  v35 = class59_SinCos(pClass59_global, pCamera->sRotationY - pClass59_global->uNumTableEntries);
  v36 = v60 * v35;
  i = v36 >> 16;
  v44 = v36 >> 16;
  v37 = class59_SinCos(pClass59_global, pCamera->sRotationY);
  v38 = v60 * v37;
  i = v38 >> 16;
  v43 = v38 >> 16;
  if ( v56 > 0 )
  {
    v60 = v56;
    v39 = 12 - v62;
    for ( i = 12 - v62; ; LOBYTE(v39) = i )
    {
      v51 = v25 + 4 * class59_SinCos(pClass59_global, X + (v26 >> v39));
      v50 = v26 + 4 * class59_SinCos(pClass59_global, X + (v25 >> i) - pClass59_global->uNumTableEntries);
      if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
        sub_485975((int)&v43, (int)&v42);
      else
        sub_4D6FB0(ebp0);
      v49 = 16;
      v25 += 16 * v44;
      v26 += 16 * v43;
      v40 = v60-- == 1;
      if ( v40 )
        break;
    }
  }
  if ( v61 )
  {
    i = 12 - v62;
    v51 = v25 + 4 * class59_SinCos(pClass59_global, X + (v26 >> (12 - v62)));
    v50 = v26 + 4 * class59_SinCos(pClass59_global, X + (v25 >> i) - pClass59_global->uNumTableEntries);
    v49 = v61;
    if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
      sub_485975((int)&v43, (int)&v42);
    else
      sub_4D6FB0(ebp0);
  }
  return 1;
}

//----- (0048585C) --------------------------------------------------------
signed int __fastcall sub_48585C(int a1, int a2, int a3)
{
  int v3; // edi@1
  int v4; // esi@1
  int v5; // ebx@2
  signed int v6; // ecx@3
  int v7; // ebx@3
  signed __int64 v8; // qtt@3
  char *v10; // eax@5
  int v11; // ecx@5
  int v12; // [sp+Ch] [bp-14h]@1
  signed int v13; // [sp+10h] [bp-10h]@1
  int v14; // [sp+18h] [bp-8h]@1

  v4 = a1;
  v12 = a2;
  v3 = *(_DWORD *)(a1 + 4);
  v13 = -*(_DWORD *)(v3 + 36);
  v14 = ((unsigned __int64)(pStruct9_global->dword_000018 * (class28_global.dword_000028 - (signed int)*(_WORD *)(a1 + 8)) * *(_DWORD *)(v3 + 28)) >> 16)
      + ((unsigned __int64)(*(_DWORD *)(v3 + 32) * pStruct9_global->dword_000018 * (class28_global.dword_00002C - (signed int)*(_WORD *)(a1 + 10))) >> 16)
      + *(_DWORD *)(v3 + 24);
  if ( v14 && (v5 = abs(-*(_DWORD *)(v3 + 36) >> 14), v5 <= abs(v14)) )
  {
    LODWORD(v8) = v13 << 16;
    HIDWORD(v8) = v13 >> 16;
    v7 = v8 / v14;
    v6 = v8 / v14;
  }
  else
  {
    v7 = pStruct9_global->shading_dist_mist << 16;
    v6 = pStruct9_global->shading_dist_mist << 16;
  }
  v10 = sub_47C178(v6, v3, dword_6BE0E0, a3);
  sub_452AF3(*(_WORD *)&v10[2 * *(_DWORD *)(*(_DWORD *)(v3 + 60) + 40)], v12, *(_WORD *)(v4 + 12));
  HIWORD(v11) = HIWORD(v7);
  LOWORD(v11) = 0;
  sub_452B58(v11, (void *)(pD3DRenderer->pActiveZBuffer + 4 * (*(_WORD *)(v4 + 8) + 640 * *(_WORD *)(v4 + 10))), *(_WORD *)(v4 + 12));
  return 1;
}

//----- (00485975) --------------------------------------------------------
int __fastcall sub_485975(int a1, int a2)
{
  int result; // eax@1
  int i; // ecx@1
  int v4; // ecx@2
  int v5; // esi@2
  int v6; // esi@2
  int v7; // ebx@3
  int v8; // edi@3
  int v9; // esi@3
  int v10; // ecx@8
  int v11; // esi@10
  int v12; // ecx@12
  int v13; // esi@12
  int v14; // [sp+0h] [bp-4h]@2

  result = a1;
  for ( i = *(_DWORD *)(a1 + 40); i; i = *(_DWORD *)(result + 40) )
  {
    v5 = *(_DWORD *)(result + 8) & *(_DWORD *)(result + 44);
    *(_DWORD *)(result + 40) = i - 1;
    v6 = (*(_DWORD *)(result + 12) & *(_WORD *)(result + 50)) + (v5 >> *(_DWORD *)(result + 16));
    v4 = *(_BYTE *)(v6 + *(_DWORD *)(result + 56));
    v14 = *(_BYTE *)(v6 + *(_DWORD *)(result + 56));
    if ( *(_DWORD *)(a2 + 32) )
    {
      v9 = *(_WORD *)(a2 + 18);
      v8 = *(_DWORD *)(a2 + 12);
      v7 = v9;
      if ( v9 >= v8 )
        v7 = *(_DWORD *)(a2 + 12);
      if ( *(_DWORD *)(a2 + 8) - v7 <= 0 )
      {
        v10 = 0;
      }
      else
      {
        if ( v9 >= v8 )
          v9 = *(_DWORD *)(a2 + 12);
        v10 = *(_DWORD *)(a2 + 8) - v9;
      }
      v11 = *(_DWORD *)(a2 + 36);
      v4 = v14 + (v10 << 8);
    }
    else
    {
      v11 = *(_DWORD *)(result + 52);
    }
    **(_WORD **)(result + 64) = *(_WORD *)(v11 + 2 * v4);
    v12 = *(_DWORD *)(result + 60);
    v13 = *(_DWORD *)(result + 36);
    *(_DWORD *)(result + 64) += 2;
    *(_DWORD *)v12 = v13;
    *(_DWORD *)(result + 60) += 4;
    *(_DWORD *)(a2 + 16) += *(_DWORD *)(a2 + 24);
    *(_DWORD *)(result + 48) += *(_DWORD *)(result + 4);
    *(_DWORD *)(result + 44) += *(_DWORD *)result;
  }
  --*(_DWORD *)(result + 40);
  return result;
}

//----- (00485A24) --------------------------------------------------------
int __fastcall sub_485A24(int a1, int a2)
{
  int result; // eax@1
  int i; // ecx@1
  int v4; // ecx@2
  int v5; // ecx@4
  int v6; // ecx@6
  int v7; // ecx@8
  int v8; // ecx@10
  int v9; // esi@10
  int v10; // ebx@11
  int v11; // edi@11
  int v12; // esi@11
  int v13; // ecx@16
  int v14; // esi@18
  int v15; // ecx@20
  int v16; // esi@20
  int v17; // [sp+0h] [bp-4h]@10

  result = a1;
  for ( i = *(_DWORD *)(a1 + 40); i; i = *(_DWORD *)(result + 40) )
  {
    *(_DWORD *)(result + 40) = i - 1;
    v4 = *(_DWORD *)(result + 24);
    if ( *(_DWORD *)(result + 48) > v4 )
      *(_DWORD *)(result + 48) = v4;
    v5 = *(_DWORD *)(result + 32);
    if ( *(_DWORD *)(result + 44) > v5 )
      *(_DWORD *)(result + 44) = v5;
    v6 = *(_DWORD *)(result + 20);
    if ( *(_DWORD *)(result + 48) < v6 )
      *(_DWORD *)(result + 48) = v6;
    v7 = *(_DWORD *)(result + 28);
    if ( *(_DWORD *)(result + 44) < v7 )
      *(_DWORD *)(result + 44) = v7;
    v9 = (*(_DWORD *)(result + 12) & *(_WORD *)(result + 50))
       + ((*(_DWORD *)(result + 44) & *(_DWORD *)(result + 8)) >> *(_DWORD *)(result + 16));
    v8 = *(_BYTE *)(v9 + *(_DWORD *)(result + 56));
    v17 = *(_BYTE *)(v9 + *(_DWORD *)(result + 56));
    if ( *(_DWORD *)(a2 + 32) )
    {
      v12 = *(_WORD *)(a2 + 18);
      v11 = *(_DWORD *)(a2 + 12);
      v10 = v12;
      if ( v12 >= v11 )
        v10 = *(_DWORD *)(a2 + 12);
      if ( *(_DWORD *)(a2 + 8) - v10 <= 0 )
      {
        v13 = 0;
      }
      else
      {
        if ( v12 >= v11 )
          v12 = *(_DWORD *)(a2 + 12);
        v13 = *(_DWORD *)(a2 + 8) - v12;
      }
      v14 = *(_DWORD *)(a2 + 36);
      v8 = v17 + (v13 << 8);
    }
    else
    {
      v14 = *(_DWORD *)(result + 52);
    }
    **(_WORD **)(result + 64) = *(_WORD *)(v14 + 2 * v8);
    v15 = *(_DWORD *)(result + 60);
    v16 = *(_DWORD *)(result + 36);
    *(_DWORD *)(result + 64) += 2;
    *(_DWORD *)v15 = v16;
    *(_DWORD *)(result + 60) += 4;
    *(_DWORD *)(a2 + 16) += *(_DWORD *)(a2 + 24);
    *(_DWORD *)(result + 48) += *(_DWORD *)(result + 4);
    *(_DWORD *)(result + 44) += *(_DWORD *)result;
  }
  --*(_DWORD *)(result + 40);
  return result;
}

//----- (00485AFF) --------------------------------------------------------
int __fastcall sub_485AFF(int a1, int a2)
{
  int result; // eax@1
  int i; // ecx@1
  int v4; // ecx@2
  int v5; // esi@2
  int v6; // esi@2
  int v7; // ebx@3
  int v8; // edi@3
  int v9; // esi@3
  int v10; // ecx@8
  int v11; // esi@10
  int v12; // ecx@12
  int v13; // esi@12
  int v14; // [sp+0h] [bp-4h]@2

  result = a1;
  for ( i = *(_DWORD *)(a1 + 40); i; i = *(_DWORD *)(result + 40) )
  {
    v5 = *(_DWORD *)(result + 8) & *(_DWORD *)(result + 44);
    *(_DWORD *)(result + 40) = i - 1;
    v6 = (*(_DWORD *)(result + 12) & *(_WORD *)(result + 50)) + (v5 >> *(_DWORD *)(result + 16));
    v4 = *(_BYTE *)(v6 + *(_DWORD *)(result + 56));
    v14 = *(_BYTE *)(v6 + *(_DWORD *)(result + 56));
    if ( *(_DWORD *)(a2 + 32) )
    {
      v9 = *(_WORD *)(a2 + 22);
      v8 = *(_DWORD *)(a2 + 12);
      v7 = v9;
      if ( v9 >= v8 )
        v7 = *(_DWORD *)(a2 + 12);
      if ( *(_DWORD *)(a2 + 8) - v7 <= 0 )
      {
        v10 = 0;
      }
      else
      {
        if ( v9 >= v8 )
          v9 = *(_DWORD *)(a2 + 12);
        v10 = *(_DWORD *)(a2 + 8) - v9;
      }
      v11 = *(_DWORD *)(a2 + 36);
      v4 = v14 + (v10 << 8);
    }
    else
    {
      v11 = *(_DWORD *)(result + 52);
    }
    **(_WORD **)(result + 64) = *(_WORD *)(v11 + 2 * v4);
    v12 = *(_DWORD *)(result + 60);
    v13 = *(_DWORD *)(result + 36);
    *(_DWORD *)(result + 64) -= 2;
    *(_DWORD *)v12 = v13;
    *(_DWORD *)(result + 60) -= 4;
    *(_DWORD *)(a2 + 20) -= *(_DWORD *)(a2 + 24);
    *(_DWORD *)(result + 48) += *(_DWORD *)(result + 4);
    *(_DWORD *)(result + 44) += *(_DWORD *)result;
  }
  --*(_DWORD *)(result + 40);
  return result;
}

//----- (00485BAE) --------------------------------------------------------
int __fastcall sub_485BAE(int a1, int a2)
{
  int result; // eax@1
  int i; // ecx@1
  int v4; // ecx@2
  int v5; // ecx@4
  int v6; // ecx@6
  int v7; // ecx@8
  int v8; // ecx@10
  int v9; // esi@10
  int v10; // ebx@11
  int v11; // edi@11
  int v12; // esi@11
  int v13; // ecx@16
  int v14; // esi@18
  int v15; // ecx@20
  int v16; // esi@20
  int v17; // [sp+0h] [bp-4h]@10

  result = a1;
  for ( i = *(_DWORD *)(a1 + 40); i; i = *(_DWORD *)(result + 40) )
  {
    *(_DWORD *)(result + 40) = i - 1;
    v4 = *(_DWORD *)(result + 24);
    if ( *(_DWORD *)(result + 48) > v4 )
      *(_DWORD *)(result + 48) = v4;
    v5 = *(_DWORD *)(result + 32);
    if ( *(_DWORD *)(result + 44) > v5 )
      *(_DWORD *)(result + 44) = v5;
    v6 = *(_DWORD *)(result + 20);
    if ( *(_DWORD *)(result + 48) < v6 )
      *(_DWORD *)(result + 48) = v6;
    v7 = *(_DWORD *)(result + 28);
    if ( *(_DWORD *)(result + 44) < v7 )
      *(_DWORD *)(result + 44) = v7;
    v9 = (*(_DWORD *)(result + 12) & *(_WORD *)(result + 50))
       + ((*(_DWORD *)(result + 44) & *(_DWORD *)(result + 8)) >> *(_DWORD *)(result + 16));
    v8 = *(_BYTE *)(v9 + *(_DWORD *)(result + 56));
    v17 = *(_BYTE *)(v9 + *(_DWORD *)(result + 56));
    if ( *(_DWORD *)(a2 + 32) )
    {
      v12 = *(_WORD *)(a2 + 22);
      v11 = *(_DWORD *)(a2 + 12);
      v10 = v12;
      if ( v12 >= v11 )
        v10 = *(_DWORD *)(a2 + 12);
      if ( *(_DWORD *)(a2 + 8) - v10 <= 0 )
      {
        v13 = 0;
      }
      else
      {
        if ( v12 >= v11 )
          v12 = *(_DWORD *)(a2 + 12);
        v13 = *(_DWORD *)(a2 + 8) - v12;
      }
      v14 = *(_DWORD *)(a2 + 36);
      v8 = v17 + (v13 << 8);
    }
    else
    {
      v14 = *(_DWORD *)(result + 52);
    }
    **(_WORD **)(result + 64) = *(_WORD *)(v14 + 2 * v8);
    v15 = *(_DWORD *)(result + 60);
    v16 = *(_DWORD *)(result + 36);
    *(_DWORD *)(result + 64) -= 2;
    *(_DWORD *)v15 = v16;
    *(_DWORD *)(result + 60) -= 4;
    *(_DWORD *)(a2 + 20) -= *(_DWORD *)(a2 + 24);
    *(_DWORD *)(result + 48) += *(_DWORD *)(result + 4);
    *(_DWORD *)(result + 44) += *(_DWORD *)result;
  }
  --*(_DWORD *)(result + 40);
  return result;
}

//----- (00485C89) --------------------------------------------------------
int __fastcall sub_485C89(int a1, int a2)
{
  int result; // eax@1
  int i; // ecx@1
  int v4; // ecx@2
  int v5; // esi@2
  int v6; // esi@2
  int v7; // edi@4
  int v8; // esi@4
  int v9; // ecx@9
  int v10; // esi@11
  int v11; // ecx@14
  int v12; // esi@14
  int v13; // [sp+0h] [bp-4h]@2

  result = a1;
  for ( i = *(_DWORD *)(a1 + 40); i; i = *(_DWORD *)(result + 40) )
  {
    v5 = *(_DWORD *)(result + 8) & *(_DWORD *)(result + 44);
    *(_DWORD *)(result + 40) = i - 1;
    v6 = (*(_DWORD *)(result + 12) & *(_WORD *)(result + 50)) + (v5 >> *(_DWORD *)(result + 16));
    v4 = *(_BYTE *)(v6 + *(_DWORD *)(result + 56));
    v13 = *(_BYTE *)(v6 + *(_DWORD *)(result + 56));
    if ( *(_BYTE *)(v6 + *(_DWORD *)(result + 56)) )
    {
      if ( *(_DWORD *)(a2 + 32) )
      {
        v8 = *(_WORD *)(a2 + 18);
        v7 = v8;
        if ( v8 >= *(_DWORD *)(a2 + 12) )
          v7 = *(_DWORD *)(a2 + 12);
        if ( *(_DWORD *)(a2 + 8) - v7 <= 0 )
        {
          v9 = 0;
        }
        else
        {
          if ( v8 >= *(_DWORD *)(a2 + 12) )
            v8 = *(_DWORD *)(a2 + 12);
          v9 = *(_DWORD *)(a2 + 8) - v8;
        }
        v10 = *(_DWORD *)(a2 + 36);
        v4 = v13 + (v9 << 8);
      }
      else
      {
        v10 = *(_DWORD *)(result + 52);
      }
      **(_WORD **)(result + 64) = *(_WORD *)(v10 + 2 * v4);
    }
    v11 = *(_DWORD *)(result + 60);
    v12 = *(_DWORD *)(result + 36);
    *(_DWORD *)(result + 64) += 2;
    *(_DWORD *)v11 = v12;
    *(_DWORD *)(result + 60) += 4;
    *(_DWORD *)(a2 + 16) += *(_DWORD *)(a2 + 24);
    *(_DWORD *)(result + 48) += *(_DWORD *)(result + 4);
    *(_DWORD *)(result + 44) += *(_DWORD *)result;
  }
  --*(_DWORD *)(result + 40);
  return result;
}

//----- (00485D3E) --------------------------------------------------------
int __fastcall sub_485D3E(int a1, int a2)
{
  int result; // eax@1
  int i; // ecx@1
  int v4; // ecx@2
  int v5; // ecx@4
  int v6; // ecx@6
  int v7; // ecx@8
  int v8; // ecx@10
  int v9; // esi@10
  int v10; // edi@12
  int v11; // esi@12
  int v12; // ecx@17
  int v13; // esi@19
  int v14; // ecx@22
  int v15; // esi@22
  int v16; // [sp+0h] [bp-4h]@10

  result = a1;
  for ( i = *(_DWORD *)(a1 + 40); i; i = *(_DWORD *)(result + 40) )
  {
    *(_DWORD *)(result + 40) = i - 1;
    v4 = *(_DWORD *)(result + 24);
    if ( *(_DWORD *)(result + 48) > v4 )
      *(_DWORD *)(result + 48) = v4;
    v5 = *(_DWORD *)(result + 32);
    if ( *(_DWORD *)(result + 44) > v5 )
      *(_DWORD *)(result + 44) = v5;
    v6 = *(_DWORD *)(result + 20);
    if ( *(_DWORD *)(result + 48) < v6 )
      *(_DWORD *)(result + 48) = v6;
    v7 = *(_DWORD *)(result + 28);
    if ( *(_DWORD *)(result + 44) < v7 )
      *(_DWORD *)(result + 44) = v7;
    v9 = (*(_DWORD *)(result + 12) & *(_WORD *)(result + 50))
       + ((*(_DWORD *)(result + 44) & *(_DWORD *)(result + 8)) >> *(_DWORD *)(result + 16));
    v8 = *(_BYTE *)(v9 + *(_DWORD *)(result + 56));
    v16 = *(_BYTE *)(v9 + *(_DWORD *)(result + 56));
    if ( *(_BYTE *)(v9 + *(_DWORD *)(result + 56)) )
    {
      if ( *(_DWORD *)(a2 + 32) )
      {
        v11 = *(_WORD *)(a2 + 18);
        v10 = v11;
        if ( v11 >= *(_DWORD *)(a2 + 12) )
          v10 = *(_DWORD *)(a2 + 12);
        if ( *(_DWORD *)(a2 + 8) - v10 <= 0 )
        {
          v12 = 0;
        }
        else
        {
          if ( v11 >= *(_DWORD *)(a2 + 12) )
            v11 = *(_DWORD *)(a2 + 12);
          v12 = *(_DWORD *)(a2 + 8) - v11;
        }
        v13 = *(_DWORD *)(a2 + 36);
        v8 = v16 + (v12 << 8);
      }
      else
      {
        v13 = *(_DWORD *)(result + 52);
      }
      **(_WORD **)(result + 64) = *(_WORD *)(v13 + 2 * v8);
    }
    v14 = *(_DWORD *)(result + 60);
    v15 = *(_DWORD *)(result + 36);
    *(_DWORD *)(result + 64) += 2;
    *(_DWORD *)v14 = v15;
    *(_DWORD *)(result + 60) += 4;
    *(_DWORD *)(a2 + 16) += *(_DWORD *)(a2 + 24);
    *(_DWORD *)(result + 48) += *(_DWORD *)(result + 4);
    *(_DWORD *)(result + 44) += *(_DWORD *)result;
  }
  --*(_DWORD *)(result + 40);
  return result;
}

//----- (00485E1F) --------------------------------------------------------
char *__fastcall sub_485E1F(int a1, int a2, signed int a3, int a4, int a5, unsigned __int8 a6, char a7)
{
  signed int *v7; // ebx@1
  signed int *v8; // edi@1
  int v9; // esi@1
  char v10; // zf@1
  int v11; // eax@1
  int v12; // ecx@3
  double v13; // ST24_8@3
  double v14; // ST24_8@3
  int v15; // eax@3
  char *v16; // eax@4
  signed int v17; // ST14_4@4
  char v18; // dl@4
  signed int v19; // ST10_4@4
  signed int v20; // ST14_4@5
  char v21; // dl@5
  int v22; // ST10_4@5
  signed int v24; // ST14_4@6
  char v25; // dl@6
  int v26; // [sp+10h] [bp-8h]@1
  char v27; // [sp+16h] [bp-2h]@1
  char v28; // [sp+17h] [bp-1h]@1
  float v29; // [sp+30h] [bp+18h]@3
  float v30; // [sp+30h] [bp+18h]@3

  v9 = a1;
  v26 = a2;
  v8 = (signed int *)(a1 + 12);
  v7 = (signed int *)(a1 + 8);
  v10 = *(_DWORD *)a1 == 0;
  v27 = *(_DWORD *)(a1 + 4) != 0;
  v28 = !v10;
  sub_47BEB1(a3, a4, a5, 0, a1 + 8, (int *)(a1 + 12), (int)&v27, (int)&v28);
  *(_DWORD *)(v9 + 36) = sub_47C28C(a4, v28, *v7, *v8);
  v11 = *(_BYTE *)(a4 + 264);
  *(_DWORD *)(v9 + 32) = v11;
  if ( v11 )
  {
    if ( a7 )
    {
      v12 = v26;
      v29 = *(float *)(v26 + 16) * 31.0;
      v13 = v29 + 6.755399441055744e15;
      *(_DWORD *)(v9 + 16) = LODWORD(v13) << 16;
      v30 = *(float *)(v12 + 20) * 31.0;
      v14 = v30 + 6.755399441055744e15;
      v15 = *(_DWORD *)(v9 + 16);
      *(_DWORD *)(v9 + 20) = LODWORD(v14) << 16;
      *(_DWORD *)(v9 + 24) = -((v15 - (LODWORD(v14) << 16)) / *(_WORD *)(v12 + 12));
    }
    v17 = *v8;
    v18 = v28;
    v19 = *v7;
    *(_DWORD *)(v9 + 28) = a6;
    v16 = sub_47C28C(a4, v18, v19, v17);
  }
  else
  {
    v20 = *v8;
    v21 = v28;
    *(_DWORD *)(v9 + 16) = 0;
    *(_DWORD *)(v9 + 20) = 0;
    v22 = *v7;
    *(_DWORD *)(v9 + 24) = 0;
    *(_DWORD *)(v9 + 28) = 0;
    v16 = sub_47C1CA(a4, v21, v22, v20);
  }
  v24 = *v8;
  v25 = v28;
  *(_DWORD *)(v9 + 36) = v16;
  return sub_47C1CA(a4, v25, *v7, v24);
}

//----- (0048653D) --------------------------------------------------------
int __thiscall sub_48653D(void *this, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // eax@1
  int v8; // edx@1
  int v9; // ecx@1
  int v10; // edi@1
  void *v11; // esi@1
  int v12; // eax@1
  int v13; // eax@2
  int v14; // ecx@2
  int v15; // ebx@2
  int v16; // ST14_4@3
  int v17; // ST10_4@3
  int v18; // eax@5
  int v19; // ST10_4@6
  int v20; // eax@8
  int v21; // ST10_4@9
  int result; // eax@10
  int v23; // eax@10
  int v24; // ecx@10
  int v25; // eax@10
  int v26; // [sp+14h] [bp-14h]@1
  int v27; // [sp+18h] [bp-10h]@1
  int v28; // [sp+1Ch] [bp-Ch]@1
  int v29; // [sp+24h] [bp-4h]@1
  int v30; // [sp+30h] [bp+8h]@7
  int v31; // [sp+30h] [bp+8h]@10
  int v32; // [sp+3Ch] [bp+14h]@10

  v11 = this;
  v10 = class59_SinCos(pClass59_global, dword_51B6F4);
  v29 = class59_SinCos(pClass59_global, dword_51B6F4 - pClass59_global->uNumTableEntries);
  v28 = class59_SinCos(pClass59_global, dword_51B6F8);
  v12 = class59_SinCos(pClass59_global, dword_51B6F8 - pClass59_global->uNumTableEntries);
  v9 = -dword_51B6EC;
  v26 = -dword_51B6E8;
  v27 = v12;
  v7 = -dword_51B6F0;
  if ( dword_51B6F8 )
  {
    v16 = v10 * -dword_51B6E8 + v29 * -dword_51B6EC;
    v15 = v28;
    v17 = -65536 * dword_51B6F0;
    *(_DWORD *)v11 = ((unsigned __int64)(v16 * v28) >> 16) + ((unsigned __int64)(-65536 * dword_51B6F0 * v27) >> 16);
    *((_DWORD *)v11 + 1) = v10 * v9 - v29 * v26;
    v14 = v27;
    v13 = ((unsigned __int64)(v17 * v28) >> 16) - ((unsigned __int64)(v16 * v27) >> 16);
  }
  else
  {
    *(_DWORD *)v11 = v8 + v29 * -dword_51B6EC;
    v15 = v28;
    *((_DWORD *)v11 + 1) = v10 * v9 - v29 * v26;
    v14 = v27;
    v13 = v7 << 16;
  }
  *((_DWORD *)v11 + 2) = v13;
  if ( dword_51B6F8 )
  {
    v19 = ((unsigned __int64)(a2 * v10) >> 16) + ((unsigned __int64)(a3 * v29) >> 16);
    *((_DWORD *)v11 + 3) = ((unsigned __int64)(v19 * v15) >> 16) + ((unsigned __int64)(a4 * v14) >> 16);
    *((_DWORD *)v11 + 4) = ((unsigned __int64)(a3 * v10) >> 16) - ((unsigned __int64)(a2 * v29) >> 16);
    v18 = ((unsigned __int64)(a4 * v15) >> 16) - ((unsigned __int64)(v19 * v14) >> 16);
  }
  else
  {
    *((_DWORD *)v11 + 3) = ((unsigned __int64)(a2 * v10) >> 16) + ((unsigned __int64)(a3 * v29) >> 16);
    *((_DWORD *)v11 + 4) = ((unsigned __int64)(a3 * v10) >> 16) - ((unsigned __int64)(a2 * v29) >> 16);
    v18 = a4;
  }
  *((_DWORD *)v11 + 5) = v18;
  v30 = v10;
  if ( dword_51B6F8 )
  {
    v21 = ((unsigned __int64)(a5 * v30) >> 16) + ((unsigned __int64)(a6 * v29) >> 16);
    *((_DWORD *)v11 + 6) = ((unsigned __int64)(v21 * v15) >> 16) + ((unsigned __int64)(a7 * v14) >> 16);
    *((_DWORD *)v11 + 7) = ((unsigned __int64)(a6 * v10) >> 16) - ((unsigned __int64)(a5 * v29) >> 16);
    v20 = ((unsigned __int64)(a7 * v15) >> 16) - ((unsigned __int64)(v21 * v14) >> 16);
  }
  else
  {
    *((_DWORD *)v11 + 6) = ((unsigned __int64)(a5 * v30) >> 16) + ((unsigned __int64)(a6 * v29) >> 16);
    *((_DWORD *)v11 + 7) = ((unsigned __int64)(a6 * v10) >> 16) - ((unsigned __int64)(a5 * v29) >> 16);
    v20 = a7;
  }
  *((_DWORD *)v11 + 6) = -*((_DWORD *)v11 + 6);
  *((_DWORD *)v11 + 7) = -*((_DWORD *)v11 + 7);
  *((_DWORD *)v11 + 8) = v20;
  v23 = *((_DWORD *)v11 + 3);
  *((_DWORD *)v11 + 8) = -*((_DWORD *)v11 + 8);
  v24 = ((unsigned __int64)(v23 * *(_DWORD *)v11) >> 16)
      + ((unsigned __int64)(*((_DWORD *)v11 + 4) * *((_DWORD *)v11 + 1)) >> 16)
      + ((unsigned __int64)(*((_DWORD *)v11 + 5) * *((_DWORD *)v11 + 2)) >> 16);
  v31 = *((_DWORD *)v11 + 6);
  v25 = *(_DWORD *)v11;
  *((_DWORD *)v11 + 9) = v24;
  v32 = (unsigned __int64)(v31 * v25) >> 16;
  result = (unsigned __int64)(*((_DWORD *)v11 + 7) * *((_DWORD *)v11 + 1)) >> 16;
  *((_DWORD *)v11 + 10) = v32 + result + ((unsigned __int64)(*((_DWORD *)v11 + 8) * *((_DWORD *)v11 + 2)) >> 16);
  return result;
}

//----- (00487E1D) --------------------------------------------------------
int __thiscall sub_487E1D(int this)
{
  int result; // eax@1
  int v2; // esi@1

  v2 = this;
  result = *(_DWORD *)(this + 4);
  if ( result )
  {
    result = class23_DeleteBuffer(class23_instance, *(_DWORD *)(this + 4));
    *(_DWORD *)(v2 + 4) = 0;
  }
  *(_DWORD *)v2 = 0;
  return result;
}

//----- (0048901B) --------------------------------------------------------
signed int __thiscall sub_48901B(char *this)
{
  sub_47CF9C(this);
  sub_486009(pStruct9_global);
  return 1;
}

//----- (0048902E) --------------------------------------------------------
signed int __thiscall sub_48902E(const char *Str, signed int a2, signed int a3, char *a4, signed int a5)
{
  const char *v5; // esi@1
  int v6; // eax@3
  int v7; // edx@3
  char *v8; // eax@3
  signed int v9; // esi@7
  signed int v10; // eax@23
  int v11; // esi@23
  int v12; // ST14_4@25
  signed int v14; // [sp-4h] [bp-84h]@6
  char String; // [sp+8h] [bp-78h]@3
  int v16; // [sp+94h] [bp+14h]@3

  v5 = Str;
  if ( a5 < 10
    || strlen(Str) != 9
    || (strcpy(&String, v5),
        _strlwr(&String),
        v8 = strtok(&String, "out"),
        v8[2] = 0,
        v6 = atoi(v8),
        v7 = v6,
        v16 = v6,
        v6 < 1)
    || v6 > 15 )
    return 0;
  if ( a2 < -22528 )
  {
    v14 = 4;
LABEL_7:
    v9 = v14;
    goto LABEL_14;
  }
  if ( a2 > 22528 )
  {
    v14 = 3;
    goto LABEL_7;
  }
  if ( a3 < -22528 )
  {
    v14 = 2;
    goto LABEL_7;
  }
  if ( a3 <= 22528 )
    return 0;
  v9 = 1;
LABEL_14:
  if ( v6 == 14 )
  {
    if ( v9 == 4 )
    {
      if ( sub_43EE77(0) )
      {
        dword_6BD07C = 1;
        strcpy(a4, "out15.odm");
        dword_6BE35C = 3;
LABEL_18:
        LOWORD(pParty_global->dword_007778) = pParty_global->dword_007778 & 0xFD7B;
        return 1;
      }
      v7 = v16;
    }
  }
  else
  {
    if ( v6 == 15 && v9 == 3 )
    {
      dword_6BD07C = 1;
      strcpy(a4, "out14.odm");
      dword_6BE35C = 4;
      goto LABEL_18;
    }
  }
  v11 = v9 + 4 * v7;
  v10 = *(_BYTE *)(v11 + 5163607);
  if ( v10 >= 1 && v10 <= 15 )
  {
    v12 = *(_BYTE *)(v11 + 5163607);
    dword_6BD07C = (unsigned __int8)byte_4ECA93[v11];
    sprintfex(a4, "out%02d.odm", v12);
    dword_6BE35C = (unsigned __int8)byte_4ECACF[v11];
    return 1;
  }
  return 0;
}

//----- (0048917E) --------------------------------------------------------
void __thiscall sub_48917E(int this)
{
  signed int v1; // ebx@1
  int *v2; // ebp@1
  int v3; // esi@1
  int v4; // eax@1
  __int16 v5; // ax@1

  v3 = this;
  v2 = (int *)(this + 3268);
  *(_DWORD *)(this + 3268) = -1;
  *(_DWORD *)(this + 3276) = CSpriteFrameTable_fn5(pSpriteFrameTable, "LUN1-4");
  *(_DWORD *)(v3 + 3284) = CSpriteFrameTable_fn5(pSpriteFrameTable, "LUN1-2");
  *(_DWORD *)(v3 + 3292) = CSpriteFrameTable_fn5(pSpriteFrameTable, "LUN3-4");
  *(_DWORD *)(v3 + 3300) = CSpriteFrameTable_fn5(pSpriteFrameTable, "LUNFULL");
  *(_DWORD *)(v3 + 3308) = CSpriteFrameTable_fn5(pSpriteFrameTable, "LUN3-4");
  *(_DWORD *)(v3 + 3316) = CSpriteFrameTable_fn5(pSpriteFrameTable, "LUN1-2");
  v4 = CSpriteFrameTable_fn5(pSpriteFrameTable, "LUN1-4");
  *(_DWORD *)(v3 + 3424) = -1;
  *(_DWORD *)(v3 + 3324) = v4;
  *(_DWORD *)(v3 + 3312) = 4;
  *(_DWORD *)(v3 + 3320) = 4;
  *(_DWORD *)(v3 + 3328) = 4;
  LOWORD(v4) = *(_WORD *)v2;
  *(_DWORD *)(v3 + 3272) = 0;
  *(_DWORD *)(v3 + 3280) = 0;
  *(_DWORD *)(v3 + 3288) = 0;
  *(_DWORD *)(v3 + 3296) = 0;
  *(_DWORD *)(v3 + 3304) = 0;
  *(_WORD *)(v3 + 3388) = v4;
  *(_DWORD *)(v3 + 3392) = 0;
  *(_DWORD *)(v3 + 3396) = 0;
  *(_DWORD *)(v3 + 3400) = 0;
  *(_DWORD *)(v3 + 3404) = 131072;
  *(_DWORD *)(v3 + 3420) = 0;
  *(_DWORD *)(v3 + 3428) = 0;
  v5 = CSpriteFrameTable_fn5(pSpriteFrameTable, "LUN-SUN");
  *(_DWORD *)(v3 + 3368) = -1;
  *(_DWORD *)(v3 + 3336) = 0;
  *(_DWORD *)(v3 + 3340) = 0;
  *(_DWORD *)(v3 + 3344) = 0;
  *(_DWORD *)(v3 + 3364) = 0;
  *(_DWORD *)(v3 + 3372) = 0;
  *(_WORD *)(v3 + 3332) = v5;
  *(_DWORD *)(v3 + 3348) = -131072;
  v1 = 8;
  do
  {
    CSpriteFrameTable_fn4(pSpriteFrameTable, *v2);
    v2 += 2;
    --v1;
  }
  while ( v1 );
  CSpriteFrameTable_fn4(pSpriteFrameTable, *(_WORD *)(v3 + 3332));
}

//----- (004893CF) --------------------------------------------------------
signed int __thiscall sub_4893CF(void *this, signed int a2, signed int a3, int a4)
{
  int v4; // ebx@1
  int v5; // eax@4
  int v6; // edi@4
  int v7; // eax@4
  int v8; // eax@4
  int v9; // eax@5
  int v10; // eax@6
  int v11; // eax@7
  int v12; // eax@8
  int v15; // [sp+8h] [bp-8h]@2
  int v16; // [sp+Ch] [bp-4h]@2

  v4 = (int)this;
  if ( pParty_global->dword_007778 & 8 || (v15 = 0, v16 = 0, sub_46D49E(a2, a3, a4, pParty_global->uDefaultPartyHeight, (int)&v15, (int)&v16, 0), v16) || v15 )
    return 2;
  v6 = WorldPosToGridCellX(pParty_global->sPartyPosX);
  v7 = WorldPosToGridCellZ(pParty_global->sPartyPosY);
  v8 = sub_47ED83(v4, v6, v7 - 1);
  v5 = *(_WORD *)(26 * sub_47ECC1(v4, v8) + pTileTable->pTiles + 20);
  if ( v5 )
  {
    v9 = v5 - 1;
    if ( !v9 )
      return 3;
    v10 = v9 - 1;
    if ( !v10 )
      return 5;
    v11 = v10 - 1;
    if ( !v11 || (v12 = v11 - 3, !v12) )
      return 4;
    if ( v12 == 1 )
      return 3;
    return 2;
  }
  return 1;
}

//----- (00489487) --------------------------------------------------------
signed int __cdecl sub_489487()
{
  signed int result; // eax@1
  signed int v1; // esi@1
  int v2; // eax@5
  int v3; // edx@5
  int v4; // ecx@5
  int v5; // esi@7
  unsigned __int8 v6; // al@9

  strcpy(pClass51_global->string_000000, Str1);
  result = CMapStats_FindLocation(pMapStats, Str1);
  v1 = result;
  if ( result >= 1 && result != 7 && result != 8 && result <= 15 )
  {
    dword_6BE030 &= 0xFFFFFFFEu;
    v3 = rand() % 100;
    v2 = 4 * v1 + 5163788;
    v4 = byte_4ECB0C[4 * v1];
    if ( v3 >= v4 )
    {
      v5 = byte_4ECB0C[4 * v1 + 1];
      if ( v3 >= v5 + v4 )
      {
        v6 = *(_BYTE *)(v2 + 2);
        if ( !v6 || v3 >= v4 + v5 + v6 )
          goto LABEL_14;
        dword_6BE044 = 2048;
      }
      else
      {
        dword_6BE044 = 4096;
      }
      dword_6BE040 = 0;
    }
    else
    {
      dword_6BE040 = 4096;
      dword_6BE044 = 8192;
    }
    dword_6BE030 |= 1u;
LABEL_14:
    if ( sub_464839() )
      sub_464851();
    dword_6A12F8 = dword_6BE040;
    dword_6A12FC = dword_6BE044;
    result = dword_6BE030;
    dword_6A12F4 = dword_6BE030;
  }
  return result;
}

//----- (00489810) --------------------------------------------------------
function_error;//int __usercall sub_489810<eax>(int result<eax>, int a2<ecx>)
int __fastcall sub_489810(int result, int a2)
{
  unsigned int v2; // ecx@1
  int v3; // esi@1
  unsigned int v4; // ecx@3
  unsigned int v5; // ecx@5
  unsigned int v6; // ecx@7
  unsigned int v7; // ecx@9
  unsigned int v8; // ecx@11
  unsigned int v9; // ecx@13
  unsigned int v10; // ecx@15
  unsigned int v11; // ecx@17
  unsigned int v12; // ecx@19
  unsigned int v13; // ecx@21
  unsigned int v14; // ecx@23

  v3 = a2;
  v2 = *(_DWORD *)(a2 + 92);
  if ( v2 )
    result = sub_4898BF(result, v2, 1);
  v4 = *(_DWORD *)(v3 + 96);
  if ( v4 )
    result = sub_4898BF(result, v4, 1);
  v5 = *(_DWORD *)(v3 + 100);
  if ( v5 )
    result = sub_4898BF(result, v5, 1);
  v6 = *(_DWORD *)(v3 + 104);
  if ( v6 )
    result = sub_4898BF(result, v6, 1);
  v7 = *(_DWORD *)(v3 + 108);
  if ( v7 )
    result = sub_4898BF(result, v7, 1);
  v8 = *(_DWORD *)(v3 + 112);
  if ( v8 )
    result = sub_4898BF(result, v8, 1);
  v9 = *(_DWORD *)(v3 + 116);
  if ( v9 )
    result = sub_4898BF(result, v9, 1);
  v10 = *(_DWORD *)(v3 + 120);
  if ( v10 )
    result = sub_4898BF(result, v10, 1);
  v11 = *(_DWORD *)(v3 + 124);
  if ( v11 )
    result = sub_4898BF(result, v11, 1);
  v12 = *(_DWORD *)(v3 + 128);
  if ( v12 )
    result = sub_4898BF(result, v12, 1);
  v13 = *(_DWORD *)(v3 + 132);
  if ( v13 )
    result = sub_4898BF(result, v13, 1);
  v14 = *(_DWORD *)(v3 + 136);
  if ( v14 )
    result = sub_4898BF(result, v14, 1);
  return result;
}

//----- (004898BF) --------------------------------------------------------
function_error;//unsigned int __userpurge sub_4898BF<eax>(int a1<eax>, unsigned int a2<ecx>, char a3)
unsigned int __fastcall sub_4898BF(int a1, unsigned int a2, char a3)
{
  int v3; // eax@1
  unsigned int v4; // esi@1
  unsigned int v5; // ST00_4@1

  v4 = a2;
  v5 = *(_DWORD *)(a2 + 4);
  *(_DWORD *)a2 = 0;
  v3 = operator_delete(a1, v5);
  *(_DWORD *)(v4 + 4) = 0;
  if ( a3 & 1 )
    operator_delete(v3, v4);
  return v4;
}

//----- (004898E6) --------------------------------------------------------
int __thiscall sub_4898E6(int this)
{
  int result; // eax@1
  int v2; // edx@1
  int v3; // ebx@2
  int v4; // edi@2
  double v5; // st7@2
  int v6; // esi@3
  double v7; // st3@3
  double v8; // st4@3
  double v9; // st5@3
  double v10; // st6@3
  float v11; // ST34_4@5
  double v12; // st6@10
  double v13; // ST0C_8@10
  int v14; // [sp+14h] [bp-44h]@2
  int v15; // [sp+18h] [bp-40h]@2
  int v16; // [sp+1Ch] [bp-3Ch]@2
  int v17; // [sp+20h] [bp-38h]@2
  int v18; // [sp+24h] [bp-34h]@2
  float v19; // [sp+30h] [bp-28h]@3
  float v20; // [sp+38h] [bp-20h]@3
  int v21; // [sp+3Ch] [bp-1Ch]@2
  int v22; // [sp+40h] [bp-18h]@1
  int v23; // [sp+44h] [bp-14h]@2
  int v24; // [sp+48h] [bp-10h]@2
  int v25; // [sp+4Ch] [bp-Ch]@2
  float v26; // [sp+50h] [bp-8h]@3
  float v27; // [sp+54h] [bp-4h]@3

  v22 = 0;
  result = **(_DWORD **)(this + 96);
  v2 = **(_DWORD **)(this + 116);
  if ( *(_DWORD *)(this + 140) > 0 )
  {
    v24 = **(_DWORD **)(this + 92) - result;
    v23 = **(_DWORD **)(this + 100) - result;
    v18 = **(_DWORD **)(this + 120) - v2;
    v17 = **(_DWORD **)(this + 124) - v2;
    v25 = result - v2;
    v16 = **(_DWORD **)(this + 128) - v2;
    v4 = **(_DWORD **)(this + 108) - v2;
    v15 = **(_DWORD **)(this + 132) - v2;
    v5 = 1.0;
    v3 = **(_DWORD **)(this + 112) - v2;
    v21 = **(_DWORD **)(this + 104) - v2;
    v14 = **(_DWORD **)(this + 136) - v2;
    do
    {
      v26 = *(float *)(v2 + v25 + v24) - (double)pCamera->dword_000000;
      v27 = *(float *)(v2 + v25) - (double)pCamera->dword_000004;
      v10 = *(float *)(v2 + v25 + v23) - (double)pCamera->dword_000008;
      v9 = pCamera->fRotationYCosine;
      v8 = pCamera->fRotationYSine;
      v20 = pCamera->fRotationXCosine;
      LODWORD(v19) = *(int *)&pCamera->fRotationXSine;
      v6 = v21 + v2;
      v7 = v27 * pCamera->fRotationYSine + pCamera->fRotationYCosine * v26;
      if (pCamera->sRotationX)
      {
        v11 = v7;
        *(float *)v6 = v11 * pCamera->fRotationXCosine + pCamera->fRotationXSine * v10;
        *(float *)(v4 + v2) = v9 * v27 - v8 * v26;
        *(float *)(v3 + v2) = v20 * v10 - v11 * v19;
      }
      else
      {
        *(float *)v6 = v7;
        *(float *)(v4 + v2) = v9 * v27 - v8 * v26;
        *(float *)(v3 + v2) = v10;
      }
      if ( *(float *)v6 >= 8.0 )
      {
        if ( (double)pStruct9_global->shading_dist_mist >= *(float *)v6 )
        {
          *(_DWORD *)v2 = 0;
          v12 = v5 / (*(float *)v6 + 0.0000001000000011686097) * (double)pStruct9_global->dword_000014;
          *(float *)(v18 + v2) = (double)class28_global.dword_000028 - v12 * *(float *)(v4 + v2);
          *(float *)(v17 + v2) = (double)class28_global.dword_00002C - v12 * *(float *)(v3 + v2);
          *(float *)(v16 + v2) = v5 - v5 / (*(float *)v6 * 1000.0 / (double)pStruct9_global->shading_dist_mist);
          *(float *)(v15 + v2) = v5 / (*(float *)v6 + 0.0000001000000011686097);
          v13 = *(float *)v6 + 6.755399441055744e15;
          v5 = 1.0;
          *(_DWORD *)(v14 + v2) = LODWORD(v13);
        }
        else
        {
          *(_DWORD *)v2 = 2;
        }
      }
      else
      {
        *(_DWORD *)v2 = 1;
      }
      ++v22;
      v2 += 4;
      result = v22;
    }
    while ( v22 < *(_DWORD *)(this + 140) );
  }
  *(_DWORD *)(this + 140) = 0;
  return result;
}

//----- (00489B60) --------------------------------------------------------
int __thiscall sub_489B60(int this)
{
  int result; // eax@1

  result = this;
  *(float *)(this + 4) = 0.0;
  *(float *)(this + 8) = 0.0;
  *(float *)(this + 12) = 0.0;
  *(float *)(this + 16) = 0.0;
  *(float *)(this + 20) = 0.0;
  *(float *)(this + 24) = 0.0;
  *(float *)(this + 28) = 0.0;
  *(float *)(this + 32) = 0.0;
  *(float *)(this + 36) = 0.0;
  *(_DWORD *)this = 5081116;
  return result;
}

//----- (0048A379) --------------------------------------------------------
signed int __thiscall sub_48A379(void *this)
{
  int v1; // eax@1
  signed int v2; // ecx@1
  int v3; // esi@1
  signed int result; // eax@3
  void *v5; // edi@4
  int v6; // ecx@4

  v3 = (int)this;
  v2 = 0;
  v1 = v3 + 1;
  do
  {
    *(_BYTE *)(v1 + 1) = v2;
    *(_BYTE *)v1 = v2;
    *(_BYTE *)(v1 - 1) = v2++;
    v1 += 3;
  }
  while ( v2 < 256 );
  class35_sub_489BE0(v3, 0);
  result = *(_DWORD *)(v3 + 2521804);
  if ( result < 50 )
  {
    v5 = (void *)(v3 + 4 * result + 2521600);
    v6 = 50 - result;
    result = 0;
    memset(v5, 0, 4 * v6);
  }
  return result;
}

//----- (0048A5A4) --------------------------------------------------------
signed int __thiscall sub_48A5A4(void *this, int a2, int a3)
{
  signed int result; // eax@1
  int v4; // ecx@1
  int v5; // edi@1
  int v6; // eax@4
  int v7; // esi@4
  int v8; // eax@9
  int v9; // edx@9
  signed int v10; // ecx@9

  v5 = (int)this;
  result = 0;
  v4 = (int)((char *)this + 2521600);
  while ( *(_DWORD *)v4 != a2 )
  {
    ++result;
    v4 += 4;
    if ( result >= 50 )
    {
      v6 = v5 + 2521604;
      v7 = 1;
      while ( *(_DWORD *)v6 )
      {
        ++v7;
        v6 += 4;
        if ( v7 >= 50 )
          return 0;
      }
      v8 = v5 + 768 * v7;
      v10 = 768;
      v9 = a3 - v8;
      do
      {
        *(_BYTE *)v8 = *(_BYTE *)(v9 + v8);
        ++v8;
        --v10;
      }
      while ( v10 );
      *(_DWORD *)(v5 + 4 * v7 + 2521600) = a2;
      class35_sub_489BE0(v5, v7);
      return v7;
    }
  }
  return result;
}

//----- (0048A643) --------------------------------------------------------
signed int __fastcall sub_48A643(int a1, int a2, int a3, float a4, float a5, float a6)
{
  int v6; // ebx@1
  int v7; // edi@1
  int v8; // esi@1
  signed __int64 v9; // qax@5
  double v10; // st5@5
  double v11; // st7@5
  double v12; // st7@5
  int v13; // eax@6
  int v14; // eax@7
  int v15; // eax@8
  int v16; // eax@9
  float v17; // eax@11
  float v19; // [sp+1Ch] [bp+8h]@5
  float v20; // [sp+20h] [bp+Ch]@5
  float v21; // [sp+20h] [bp+Ch]@5
  float v22; // [sp+20h] [bp+Ch]@5

  v6 = a3;
  v7 = a2;
  v8 = a1;
  if ( a5 == 0.0 )
  {
    *(float *)a3 = a6;
    *(float *)a2 = a6;
    *(float *)a1 = a6;
    goto LABEL_20;
  }
  if ( a4 == 360.0 )
    a4 = 0.0;
  v12 = a4 * *(double *)&byte_4D8410[1120];
  v21 = v12;
  floor(v12);
  v9 = (signed __int64)v12;
  v22 = v21 - (double)(signed int)(signed __int64)v12;
  v11 = (1.0 - a5) * a6;
  v10 = (1.0 - v22 * a5) * a6;
  v19 = v10;
  v20 = (1.0 - (1.0 - v22) * a5) * a6;
  if ( (_DWORD)v9 )
  {
    v13 = v9 - 1;
    if ( v13 )
    {
      v14 = v13 - 1;
      if ( v14 )
      {
        v15 = v14 - 1;
        if ( v15 )
        {
          v16 = v15 - 1;
          if ( v16 )
          {
            if ( v16 != 1 )
              goto LABEL_20;
            *(float *)v8 = a6;
            v17 = v19;
            *(float *)v7 = v11;
            goto LABEL_12;
          }
          *(_DWORD *)v8 = LODWORD(v20);
          *(float *)v7 = v11;
        }
        else
        {
          *(float *)v8 = v11;
          *(_DWORD *)v7 = LODWORD(v19);
        }
        v17 = a6;
      }
      else
      {
        *(float *)v8 = v11;
        *(_DWORD *)v7 = LODWORD(a6);
        v17 = v20;
      }
LABEL_12:
      *(_DWORD *)v6 = LODWORD(v17);
      goto LABEL_20;
    }
    *(float *)v8 = v10;
    *(float *)v7 = a6;
  }
  else
  {
    *(float *)v8 = a6;
    *(_DWORD *)v7 = LODWORD(v20);
  }
  *(float *)v6 = v11;
LABEL_20:
  if ( *(float *)v8 > memory_4D8410.f1_0 )
    *(float *)v8 = 1.0;
  if ( *(float *)v7 > memory_4D8410.f1_0 )
    *(float *)v7 = 1.0;
  if ( *(float *)v6 > memory_4D8410.f1_0 )
    *(float *)v6 = 1.0;
  if ( *(float *)v8 < *(double *)&byte_4D8410[176] )
    *(float *)v8 = 0.0;
  if ( *(float *)v7 < *(double *)&byte_4D8410[176] )
    *(float *)v7 = 0.0;
  if ( *(float *)v6 < *(double *)&byte_4D8410[176] )
    *(float *)v6 = 0.0;
  return 1;
}

//----- (0048A8CC) --------------------------------------------------------
int __thiscall sub_48A8CC(int this)
{
  signed int v1; // eax@1
  int v2; // edx@1

  v2 = this + 2521604;
  v1 = 1;
  do
  {
    if ( *(_DWORD *)v2 )
      *(_DWORD *)(this + 2521804) = v1 + 1;
    ++v1;
    v2 += 4;
  }
  while ( v1 < 50 );
  return *(_DWORD *)(this + 2521804);
}

//----- (0048A959) --------------------------------------------------------
int __thiscall sub_48A959(void *this, float a2, int a3, int a4)
{
  void *v4; // esi@1
  signed __int64 v5; // ST14_8@1
  double v6; // st6@1
  signed __int64 v7; // ST14_8@1
  double v8; // st6@1
  signed __int64 v9; // ST14_8@1
  double v11; // ST14_8@7
  double v12; // ST14_8@7
  __int64 v13; // [sp+14h] [bp-20h]@1
  double v14; // [sp+1Ch] [bp-18h]@7
  float v15; // [sp+20h] [bp-14h]@1
  int v16; // [sp+24h] [bp-10h]@1
  int v17; // [sp+28h] [bp-Ch]@1
  float v18; // [sp+2Ch] [bp-8h]@1
  float v19; // [sp+30h] [bp-4h]@1
  float v20; // [sp+3Ch] [bp+8h]@7
  float v21; // [sp+3Ch] [bp+8h]@7
  float v22; // [sp+3Ch] [bp+8h]@7
  int v23; // [sp+40h] [bp+Ch]@7

  v4 = this;
  v5 = ((unsigned int)this >> 16) & 0xFFi64;
  v6 = (double)v5;
  v7 = (unsigned __int16)((_WORD)this >> 8);
  v19 = v6 * 0.003921568859368563;
  v8 = (double)v7;
  v9 = (unsigned int)this & 0xFFi64;
  v18 = v8 * 0.003921568859368563;
  *(float *)&v17 = (double)v9 * 0.003921568859368563;
  sub_48A7AA((int)((char *)&v13 + 4), (int)&v15, v19, v18, *(float *)&v17, (int)&v16);
  if ( a2 != -1.0 )
    HIDWORD(v13) = LODWORD(a2);
  if ( *(float *)&a3 != -1.0 )
    LODWORD(v15) = a3;
  if ( *(float *)&a4 != -1.0 )
    v16 = a4;
  sub_48A643((int)&v19, (int)&v18, (int)&v17, *((float *)&v13 + 1), v15, *(float *)&v16);
  v20 = v19 * 255.0;
  v11 = v20 + 6.755399441055744e15;
  v23 = LODWORD(v11);
  v21 = v18 * 255.0;
  v12 = v21 + 6.755399441055744e15;
  v22 = *(float *)&v17 * 255.0;
  v14 = v22 + 6.755399441055744e15;
  return LODWORD(v14) | (unsigned int)v4 & 0xFF000000 | ((LODWORD(v12) | (v23 << 8)) << 8);
}

//----- (0048AB23) --------------------------------------------------------
void __thiscall sub_48AB23(int this, int a2)
{
  signed int v2; // eax@2
  int v3; // edx@2
  int v4; // esi@10
  int v5; // ecx@10
  char v6; // zf@10

  if ( !pClass24_global2->dword_000004)
  {
    v2 = 0;
    v3 = this;
    do
    {
      if ( !*(_DWORD *)v3 )
        break;
      ++v2;
      v3 += 104;
    }
    while ( v2 < 500 );
    if ( v2 < 500 )
    {
      if ( v2 < *(_DWORD *)(this + 58404) )
        *(_DWORD *)(this + 58404) = v2;
      if ( v2 > *(_DWORD *)(this + 58408) )
        *(_DWORD *)(this + 58408) = v2;
      v4 = 104 * v2 + this;
      *(_DWORD *)v4 = *(_DWORD *)a2;
      *(_DWORD *)(v4 + 4) = *(_DWORD *)(a2 + 4);
      *(_DWORD *)(v4 + 8) = *(_DWORD *)(a2 + 8);
      *(_DWORD *)(v4 + 12) = *(_DWORD *)(a2 + 12);
      *(_DWORD *)(v4 + 44) = *(_DWORD *)(a2 + 4);
      *(_DWORD *)(v4 + 48) = *(_DWORD *)(a2 + 8);
      *(_DWORD *)(v4 + 52) = *(_DWORD *)(a2 + 12);
      *(_DWORD *)(v4 + 16) = *(_DWORD *)(a2 + 16);
      *(_DWORD *)(v4 + 20) = *(_DWORD *)(a2 + 20);
      *(_DWORD *)(v4 + 24) = *(_DWORD *)(a2 + 24);
      v5 = *(_DWORD *)(a2 + 28);
      *(_DWORD *)(v4 + 28) = v5;
      *(_DWORD *)(v4 + 100) = v5;
      v6 = (*(_BYTE *)v4 & 4) == 0;
      *(_DWORD *)(v4 + 32) = *(_DWORD *)(a2 + 32);
      *(_DWORD *)(v4 + 36) = *(_DWORD *)(a2 + 36);
      *(_DWORD *)(v4 + 40) = *(_DWORD *)(a2 + 40);
      if ( v6 )
      {
        *(_DWORD *)(v4 + 56) = 0;
        *(_DWORD *)(v4 + 60) = 0;
      }
      else
      {
        *(_DWORD *)(v4 + 56) = (unsigned __int8)rand() - 128;
        *(_DWORD *)(v4 + 60) = rand();
      }
    }
  }
}

//----- (0048AE74) --------------------------------------------------------
signed int __thiscall sub_48AE74(void *this, float a2)
{
  int v2; // esi@1
  double v3; // ST28_8@2
  int v4; // eax@4
  float v5; // eax@4
  double v6; // ST34_8@4
  signed __int64 v7; // qtt@4
  double v8; // st7@4
  float v9; // ST18_4@4
  double v10; // ST44_8@7
  double v11; // ST4C_8@7
  double v12; // ST4C_8@7
  int v13; // ecx@7
  signed __int64 v14; // qtt@7
  int v15; // eax@7
  int v16; // edx@7
  int v17; // edx@7
  int v18; // eax@7
  int v19; // edx@7
  int v20; // ebx@8
  int v21; // ST50_4@8
  int v22; // ecx@10
  int v23; // edi@10
  double v24; // ST44_8@12
  double v25; // ST4C_8@12
  int v26; // edi@12
  int v27; // ST40_4@12
  int v28; // ecx@12
  signed __int64 v29; // qtt@12
  int v30; // eax@12
  int v31; // edx@12
  int v32; // edx@12
  int v33; // eax@12
  int v34; // ecx@12
  int v35; // ST38_4@13
  int v36; // ST30_4@15
  int v37; // eax@16
  signed __int64 v39; // qtt@18
  int v40; // eax@18
  int v41; // ecx@18
  int v42; // eax@18
  unsigned __int64 v43; // qax@18
  double v44; // st7@18
  float v45; // ST18_4@18
  double v46; // [sp+10h] [bp-40h]@2
  int v47; // [sp+18h] [bp-38h]@10
  int v48; // [sp+20h] [bp-30h]@2
  double v49; // [sp+24h] [bp-2Ch]@2
  int v50; // [sp+28h] [bp-28h]@8
  int v51; // [sp+3Ch] [bp-14h]@3
  double v52; // [sp+40h] [bp-10h]@12
  int v53; // [sp+44h] [bp-Ch]@4
  int v54; // [sp+48h] [bp-8h]@4
  int v55; // [sp+4Ch] [bp-4h]@3

  v2 = (int)((char *)this + 104 * LODWORD(a2));
  if ( !*(_DWORD *)v2 )
    return 0;
  LODWORD(a2) = *(_DWORD *)(v2 + 4);
  v3 = a2 + 6.755399441055744e15;
  v48 = LODWORD(v3);
  LODWORD(a2) = *(_DWORD *)(v2 + 8);
  v46 = a2 + 6.755399441055744e15;
  LODWORD(a2) = *(_DWORD *)(v2 + 12);
  v49 = a2 + 6.755399441055744e15;
  if ( !pD3DRenderer->dword_040088 )
  {
    if ( dword_51B6F8 )
    {
      if ( *(_BYTE *)(v2 + 1) & 2 )
      {
        v10 = *(float *)(v2 + 44) + 6.755399441055744e15;
        LODWORD(a2) = (LODWORD(v10) - dword_51B6E8) << 16;
        v11 = *(float *)(v2 + 48) + 6.755399441055744e15;
        v55 = (LODWORD(v11) - dword_51B6EC) << 16;
        v51 = (unsigned __int64)(v55 * dword_51B704) >> 16;
        v53 = ((unsigned __int64)(SLODWORD(a2) * dword_51B700) >> 16) - v51;
        v54 = (unsigned __int64)(SLODWORD(a2) * dword_51B704) >> 16;
        v12 = *(float *)(v2 + 52) + 6.755399441055744e15;
        LODWORD(a2) = (LODWORD(v12) - dword_51B6F0) << 16;
        v51 = ((unsigned __int64)(v53 * dword_51B708) >> 16) - ((unsigned __int64)(SLODWORD(a2) * dword_51B70C) >> 16);
        v13 = v51;
        HIDWORD(v12) = (unsigned __int64)(v53 * dword_51B70C) >> 16;
        v53 = (unsigned __int64)(SLODWORD(a2) * dword_51B708) >> 16;
        LODWORD(v14) = unk_51B720 << 16;
        HIDWORD(v14) = unk_51B720 >> 16;
        v15 = v14 / v51;
        v16 = (unsigned __int64)(v55 * dword_51B700) >> 16;
        *(_DWORD *)(v2 + 88) = v15;
        LODWORD(a2) = (unsigned __int64)(v15 * (v54 + v16)) >> 16;
        v17 = dword_51B754 - ((signed int)((unsigned __int64)(v15 * (v54 + v16)) >> 16) >> 16);
        v18 = *(_DWORD *)(v2 + 88);
        *(_DWORD *)(v2 + 72) = v17;
        v19 = dword_51B758 - ((signed int)((unsigned __int64)(v18 * (HIDWORD(v12) + v53)) >> 16) >> 16);
        *(_DWORD *)(v2 + 84) = v13;
        *(_DWORD *)(v2 + 76) = v19;
      }
      LODWORD(a2) = (v48 - dword_51B6E8) << 16;
      v55 = (LODWORD(v46) - dword_51B6EC) << 16;
      v53 = ((unsigned __int64)(SLODWORD(a2) * dword_51B700) >> 16) - ((unsigned __int64)(v55 * dword_51B704) >> 16);
      v54 = (unsigned __int64)(SLODWORD(a2) * dword_51B704) >> 16;
      HIDWORD(v49) = (unsigned __int64)(v55 * dword_51B700) >> 16;
      LODWORD(a2) = (LODWORD(v49) - dword_51B6F0) << 16;
      v21 = (unsigned __int64)(SLODWORD(a2) * dword_51B70C) >> 16;
      v20 = ((unsigned __int64)(v53 * dword_51B708) >> 16) - v21;
      v51 = ((unsigned __int64)(v53 * dword_51B708) >> 16) - v21;
      if ( v20 < 262144 || v20 > 524288000 )
        return 0;
      v22 = v54 + v50;
      v47 = v54 + v50;
      v23 = ((unsigned __int64)(SLODWORD(a2) * dword_51B708) >> 16) + ((unsigned __int64)(v53 * dword_51B70C) >> 16);
    }
    else
    {
      if ( *(_BYTE *)(v2 + 1) & 2 )
      {
        v24 = *(float *)(v2 + 44) + 6.755399441055744e15;
        LODWORD(a2) = (LODWORD(v24) - dword_51B6E8) << 16;
        v25 = *(float *)(v2 + 48) + 6.755399441055744e15;
        v55 = (LODWORD(v25) - dword_51B6EC) << 16;
        HIDWORD(v24) = (unsigned __int64)(v55 * dword_51B704) >> 16;
        v26 = ((unsigned __int64)(SLODWORD(a2) * dword_51B700) >> 16) - HIDWORD(v24);
        v51 = ((unsigned __int64)(SLODWORD(a2) * dword_51B700) >> 16) - HIDWORD(v24);
        v27 = (unsigned __int64)(SLODWORD(a2) * dword_51B704) >> 16;
        v52 = *(float *)(v2 + 52) + 6.755399441055744e15;
        v28 = (LODWORD(v52) - dword_51B6F0) << 16;
        LODWORD(v29) = unk_51B720 << 16;
        HIDWORD(v29) = unk_51B720 >> 16;
        v30 = v29 / v51;
        v31 = (unsigned __int64)(v55 * dword_51B700) >> 16;
        *(_DWORD *)(v2 + 88) = v30;
        LODWORD(a2) = (unsigned __int64)(v30 * (v27 + v31)) >> 16;
        v32 = dword_51B754 - ((signed int)((unsigned __int64)(v30 * (v27 + v31)) >> 16) >> 16);
        v33 = *(_DWORD *)(v2 + 88);
        *(_DWORD *)(v2 + 72) = v32;
        v34 = dword_51B758 - ((signed int)((unsigned __int64)(v33 * v28) >> 16) >> 16);
        *(_DWORD *)(v2 + 84) = v26;
        *(_DWORD *)(v2 + 76) = v34;
      }
      LODWORD(a2) = (v48 - dword_51B6E8) << 16;
      v55 = (LODWORD(v46) - dword_51B6EC) << 16;
      v35 = (unsigned __int64)(v55 * dword_51B704) >> 16;
      v20 = ((unsigned __int64)(SLODWORD(a2) * dword_51B700) >> 16) - v35;
      v51 = ((unsigned __int64)(SLODWORD(a2) * dword_51B700) >> 16) - v35;
      if ( v20 < 262144 || v20 > 524288000 )
        return 0;
      v36 = (unsigned __int64)(SLODWORD(a2) * dword_51B704) >> 16;
      LODWORD(a2) = (unsigned __int64)(v55 * dword_51B700) >> 16;
      v22 = v36 + ((unsigned __int64)(v55 * dword_51B700) >> 16);
      v47 = v36 + ((unsigned __int64)(v55 * dword_51B700) >> 16);
      v23 = (LODWORD(v49) - dword_51B6F0) << 16;
    }
    LODWORD(a2) = abs(v22);
    v37 = abs(v20);
    if ( v37 >= LODWORD(a2) )
    {
      LODWORD(v39) = unk_51B720 << 16;
      HIDWORD(v39) = unk_51B720 >> 16;
      v40 = v39 / v51;
      *(_DWORD *)(v2 + 88) = v40;
      LODWORD(a2) = (unsigned __int64)(v40 * v47) >> 16;
      v41 = dword_51B754 - ((signed int)((unsigned __int64)(v40 * v47) >> 16) >> 16);
      v42 = *(_DWORD *)(v2 + 88);
      *(_DWORD *)(v2 + 64) = v41;
      v43 = v42 * v23;
      LODWORD(a2) = v43 >> 16;
      v44 = *(float *)(v2 + 40);
      *(_DWORD *)(v2 + 68) = dword_51B758 - ((signed int)(v43 >> 16) >> 16);
      v45 = v44;
      *(_DWORD *)(v2 + 88) = (unsigned __int64)(sub_48B561(v45) * *(_DWORD *)(v2 + 88)) >> 16;
      v4 = v51;
      goto LABEL_19;
    }
    return 0;
  }

  compile_error;
  /*
  if ( !sub_43669D(
          v48,
          SLODWORD(v46),
          COERCE_UNSIGNED_INT64(a2 + 6.755399441055744e15),
          (signed int *)&a2,
          (int)&v55,
          (int)&v51,
          1) )*/
  if (0)
    return 0;
  sub_436A9A(pGame->class08_obj, SLODWORD(a2), v55, v51, (int)&v53, (int)&v54);
  *(float *)(v2 + 92) = *(float *)(pGame->class08_obj + 208);
  LODWORD(v5) = *(_DWORD *)(v2 + 92);
  *(float *)(v2 + 96) = *(float *)(pGame->class08_obj + 212);
  v6 = v5 + 6.755399441055744e15;
  LODWORD(v7) = 0;
  HIDWORD(v7) = LODWORD(v6) << 16 >> 16;
  v8 = *(float *)(v2 + 40);
  *(_DWORD *)(v2 + 88) = v7 / SLODWORD(a2);
  v9 = v8;
  *(_DWORD *)(v2 + 64) = v53;
  *(_DWORD *)(v2 + 68) = v54;
  *(_DWORD *)(v2 + 88) = (unsigned __int64)(sub_48B561(v9) * *(_DWORD *)(v2 + 88)) >> 16;
  v4 = LODWORD(a2);
LABEL_19:
  *(_DWORD *)(v2 + 80) = v4;
  return 1;
}

//----- (0048B561) --------------------------------------------------------
int __stdcall sub_48B561(float a1)
{
  float v2; // ST08_4@1
  double v3; // ST00_8@1
  int v4; // ST0C_4@1
  double v5; // ST00_8@1
  float v6; // [sp+18h] [bp+8h]@1

  v2 = a1 - memory_4D8410.d_0_5;
  v3 = v2 + 6.755399441055744e15;
  v4 = LODWORD(v3);
  v6 = (a1 - (double)SLODWORD(v3)) * 65536.0;
  v5 = v6 + 6.755399441055744e15;
  return LODWORD(v5) | (v4 << 16);
}

//----- (0048B5B3) --------------------------------------------------------
signed int __thiscall sub_48B5B3(void *this, int a2)
{
  int v2; // ecx@1
  int v3; // ebx@1
  int v4; // edi@1
  int v5; // esi@1
  void *v6; // ST18_4@1
  double v7; // ST14_8@2
  double v8; // ST34_8@4
  double v9; // ST3C_8@4
  int v10; // ST50_4@4
  int v11; // ST44_4@4
  double v12; // ST48_8@4
  signed __int64 v13; // qtt@4
  int v14; // eax@4
  int v15; // ST28_4@4
  int v16; // eax@6
  int v17; // edi@6
  double v18; // ST2C_8@8
  double v19; // ST34_8@8
  int v20; // ST50_4@8
  double v21; // ST34_8@8
  signed __int64 v22; // qtt@8
  int v23; // eax@8
  int v24; // ST28_4@8
  int v25; // edx@8
  int v26; // eax@9
  int v27; // edx@9
  int v28; // ebx@12
  int v29; // eax@13
  signed __int64 v30; // qtt@13
  int v31; // eax@13
  int v32; // ST1C_4@13
  double v33; // st7@13
  float v34; // ST04_4@13
  int v35; // esi@15
  double v37; // [sp+10h] [bp-40h]@2
  int v38; // [sp+14h] [bp-3Ch]@12
  int v39; // [sp+1Ch] [bp-34h]@2
  double v40; // [sp+20h] [bp-30h]@2
  int v41; // [sp+24h] [bp-2Ch]@5
  int v42; // [sp+2Ch] [bp-24h]@1
  int v43; // [sp+40h] [bp-10h]@5
  int v44; // [sp+48h] [bp-8h]@5
  int v45; // [sp+4Ch] [bp-4h]@5
  int v46; // [sp+4Ch] [bp-4h]@9
  int v47; // [sp+58h] [bp+8h]@4
  int v48; // [sp+58h] [bp+8h]@4
  int v49; // [sp+58h] [bp+8h]@5
  int v50; // [sp+58h] [bp+8h]@5
  int v51; // [sp+58h] [bp+8h]@8
  int v52; // [sp+58h] [bp+8h]@9

  v6 = this;
  v3 = class59_SinCos(pClass59_global, pCamera->sRotationX);
  v42 = class59_SinCos(pClass59_global, pCamera->sRotationX - pClass59_global->uNumTableEntries);
  v4 = class59_SinCos(pClass59_global, pCamera->sRotationY);
  v2 = class59_SinCos(pClass59_global, pCamera->sRotationY - pClass59_global->uNumTableEntries);
  v5 = (int)((char *)v6 + 104 * a2);
  if ( !*(_DWORD *)v5 )
    return 0;
  v7 = *(float *)(v5 + 4) + 6.755399441055744e15;
  v39 = LODWORD(v7);
  v37 = *(float *)(v5 + 8) + 6.755399441055744e15;
  v40 = *(float *)(v5 + 12) + 6.755399441055744e15;
  if ( v3 )
  {
    if ( *(_BYTE *)(v5 + 1) & 2 )
    {
      v8 = *(float *)(v5 + 44) + 6.755399441055744e15;
      v47 = (LODWORD(v8) - pCamera->dword_000000) << 16;
      v9 = *(float *)(v5 + 48) + 6.755399441055744e15;
      v10 = (LODWORD(v9) - pCamera->dword_000004) << 16;
      v11 = ((unsigned __int64)(v47 * v4) >> 16) + ((unsigned __int64)(v10 * v2) >> 16);
      HIDWORD(v8) = (unsigned __int64)(v47 * v2) >> 16;
      v12 = *(float *)(v5 + 52) + 6.755399441055744e15;
      v48 = (LODWORD(v12) - pCamera->dword_000008) << 16;
      HIDWORD(v12) = ((unsigned __int64)(v11 * v3) >> 16) + ((unsigned __int64)(v48 * v42) >> 16);
      LODWORD(v13) = 0;
      HIDWORD(v13) = pStruct9_global->dword_000014 << 16 >> 16;
      v14 = v13 / SHIDWORD(v12);
      *(_DWORD *)(v5 + 88) = v14;
      v15 = *(_DWORD *)(v5 + 88);
      *(_DWORD *)(v5 + 64) = class28_global.dword_000028
                           - ((signed int)((unsigned __int64)(v14
                                                            * (signed int)(((unsigned __int64)(v10 * v4) >> 16)
                                                                         - HIDWORD(v8))) >> 16) >> 16);
      *(_DWORD *)(v5 + 68) = class28_global.dword_00002C
                           - ((signed int)((unsigned __int64)(v15
                                                            * (signed int)(((unsigned __int64)(v48 * v3) >> 16)
                                                                         - ((unsigned __int64)(v11 * v42) >> 16))) >> 16) >> 16);
      *(_DWORD *)(v5 + 80) = HIDWORD(v12);
    }
    v50 = (v39 - pCamera->dword_000000) << 16;
    v45 = (LODWORD(v37) - pCamera->dword_000004) << 16;
    v43 = ((unsigned __int64)(v50 * v4) >> 16) + ((unsigned __int64)(v45 * v2) >> 16);
    HIDWORD(v40) = (unsigned __int64)(v50 * v2) >> 16;
    v49 = (LODWORD(v40) - pCamera->dword_000008) << 16;
    v44 = ((unsigned __int64)(v49 * v42) >> 16) + ((unsigned __int64)(v43 * v3) >> 16);
    if ( v44 < 262144 )
      return 0;
    v17 = ((unsigned __int64)(v45 * v4) >> 16) - v41;
    v16 = ((unsigned __int64)(v49 * v3) >> 16) - ((unsigned __int64)(v43 * v42) >> 16);
  }
  else
  {
    if ( *(_BYTE *)(v5 + 1) & 2 )
    {
      v18 = *(float *)(v5 + 44) + 6.755399441055744e15;
      v51 = (LODWORD(v18) - pCamera->dword_000000) << 16;
      v19 = *(float *)(v5 + 48) + 6.755399441055744e15;
      v20 = (LODWORD(v19) - pCamera->dword_000004) << 16;
      v21 = *(float *)(v5 + 52) + 6.755399441055744e15;
      LODWORD(v22) = 0;
      HIDWORD(v22) = pStruct9_global->dword_000014 << 16 >> 16;
      v23 = v22 / (signed int)(((unsigned __int64)(v20 * v2) >> 16) + ((unsigned __int64)(v51 * v4) >> 16));
      *(_DWORD *)(v5 + 88) = v23;
      v24 = *(_DWORD *)(v5 + 88);
      *(_DWORD *)(v5 + 64) = class28_global.dword_000028
                           - ((signed int)((unsigned __int64)(v23
                                                            * (signed int)(((unsigned __int64)(v20 * v4) >> 16)
                                                                         - ((unsigned __int64)(v51 * v2) >> 16))) >> 16) >> 16);
      v25 = class28_global.dword_00002C - ((signed int)((unsigned __int64)(v24 * SLODWORD(v21)) >> 16) >> 16);
      *(_DWORD *)(v5 + 80) = ((unsigned __int64)(v20 * v2) >> 16) + ((unsigned __int64)(v51 * v4) >> 16);
      *(_DWORD *)(v5 + 68) = v25;
    }
    v52 = (v39 - pCamera->dword_000000) << 16;
    v46 = (LODWORD(v37) - pCamera->dword_000004) << 16;
    v27 = (unsigned __int64)(v46 * v2) >> 16;
    v26 = v27 + ((unsigned __int64)(v52 * v4) >> 16);
    v44 = v27 + ((unsigned __int64)(v52 * v4) >> 16);
    if ( v26 < 262144 || v26 > (pStruct9_global->dword_000000 - 1000) << 16 )
      return 0;
    v16 = LODWORD(v40);
    v17 = ((unsigned __int64)(v46 * v4) >> 16) - ((unsigned __int64)(v52 * v2) >> 16);
  }
  v38 = v16;
  v28 = abs(v17);
  if ( abs(v44) >= v28 )
  {
    LODWORD(v30) = 0;
    HIDWORD(v30) = pStruct9_global->dword_000014 << 16 >> 16;
    v31 = v30 / v44;
    *(_DWORD *)(v5 + 88) = v31;
    v32 = *(_DWORD *)(v5 + 88);
    *(_DWORD *)(v5 + 64) = class28_global.dword_000028 - ((signed int)((unsigned __int64)(v31 * v17) >> 16) >> 16);
    v33 = *(float *)(v5 + 40);
    *(_DWORD *)(v5 + 68) = class28_global.dword_00002C - ((signed int)((unsigned __int64)(v32 * v38) >> 16) >> 16);
    v34 = v33;
    *(_DWORD *)(v5 + 88) = (unsigned __int64)(sub_48B561(v34) * *(_DWORD *)(v5 + 88)) >> 16;
    *(_DWORD *)(v5 + 80) = v44;
    v29 = *(_DWORD *)(v5 + 64);
    if ( v29 >= class28_global.dword_000010 )
    {
      if ( v29 < class28_global.dword_000018 )
      {
        v35 = *(_DWORD *)(v5 + 68);
        if ( v35 >= class28_global.dword_000014 )
        {
          if ( v35 < class28_global.dword_00001C )
            return 1;
        }
      }
    }
  }
  return 0;
}

//----- (0048C6AF) --------------------------------------------------------
void *__thiscall sub_48C6AF(void *this)
{
  signed int v1; // ebx@1
  int v2; // edi@1
  void *v3; // esi@1
  int v4; // eax@3
  signed int v5; // edx@3

  v3 = this;
  v1 = 138;
  v2 = (int)((char *)this + 532);
  do
  {
    sub_402F07(v2);
    v2 += 36;
    --v1;
  }
  while ( v1 );
  v4 = (int)((char *)v3 + 6048);
  v5 = 24;
  do
  {
    *(_WORD *)(v4 + 10) = 0;
    *(_WORD *)(v4 + 8) = 0;
    *(_DWORD *)v4 = 0;
    *(_DWORD *)(v4 + 4) = 0;
    *(_BYTE *)(v4 + 14) = 0;
    *(_BYTE *)(v4 + 15) = 0;
    v4 += 16;
    --v5;
  }
  while ( v5 );
  return v3;
}