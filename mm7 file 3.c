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
//#include "codec.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"




//----- (00438B54) --------------------------------------------------------
void __thiscall sub_438B54(int this)
{
  int v1; // esi@1

  v1 = this;
  *(_DWORD *)this = 5080528;
  DeleteCriticalSection((LPCRITICAL_SECTION)(this + 76));
  DeleteCriticalSection((LPCRITICAL_SECTION)(v1 + 52));
  DeleteCriticalSection((LPCRITICAL_SECTION)(v1 + 28));
  DeleteCriticalSection((LPCRITICAL_SECTION)(v1 + 4));
}

//----- (00438B9B) --------------------------------------------------------
char __thiscall sub_438B9B(int this)
{
  int v1; // eax@1

  v1 = *(_DWORD *)(this + 712);
  if ( !v1 )
    v1 = (*(_WORD *)(this + 96) - 1) / 3 + 1;
  return v1 >= 39 && v1 <= 44 || v1 >= 45 && v1 <= 50 || v1 >= 51 && v1 <= 62 || v1 >= 78 && v1 <= 83;
}

//----- (00438BDF) --------------------------------------------------------
signed int __fastcall sub_438BDF(signed int a1, int a2)
{
  unsigned __int8 v2; // zf@15
  char v3; // sf@15
  unsigned __int8 v4; // of@15
  signed int result; // eax@33

  switch ( a2 )
  {
    case 1:
      if ( a1 >= 70 && a1 <= 72
        || a1 >= 91 && a1 <= 93
        || a1 >= 199 && a1 <= 201
        || a1 >= 217 && a1 <= 219
        || a1 >= 223 && a1 <= 225
        || a1 >= 229 && a1 <= 231 )
        goto LABEL_33;
      if ( a1 < 256 )
        goto LABEL_34;
      compile_error;//v4 = __SETO__(a1, 258);
      v2 = a1 == 258;
      v3 = a1 - 258 < 0;
      goto LABEL_32;
    case 2:
      if ( a1 < 22 )
        goto LABEL_34;
      compile_error;//v4 = __SETO__(a1, 24);
      v2 = a1 == 24;
      v3 = a1 - 24 < 0;
      goto LABEL_32;
    case 4:
      if ( a1 >= 133 && a1 <= 150 || a1 >= 49 && a1 <= 51 )
        goto LABEL_33;
      if ( a1 < 52 )
        goto LABEL_34;
      compile_error;//v4 = __SETO__(a1, 54);
      v2 = a1 == 54;
      v3 = a1 - 54 < 0;
      goto LABEL_32;
    case 3:
      if ( a1 < 25 )
        goto LABEL_34;
      compile_error;//v4 = __SETO__(a1, 27);
      v2 = a1 == 27;
      v3 = a1 - 27 < 0;
      goto LABEL_32;
    case 5:
      //if (a1 < 46)
      //  goto LABEL_34;
      //v4 = __SETO__(a1, 48);
      //v2 = a1 == 48;
      //v3 = a1 - 48 < 0;
      //goto LABEL_32;
      if (a1 < 46 || a1 > 48)
        return 0;
      return 1;
    case 6:
      if ( a1 < 253 )
        goto LABEL_34;
      compile_error;//v4 = __SETO__(a1, 255);
      v2 = a1 == 255;
      v3 = a1 - 255 < 0;
      goto LABEL_32;
    case 7:
      if ( a1 < 211 )
        goto LABEL_34;
      compile_error;//v4 = __SETO__(a1, 213);
      v2 = a1 == 213;
      v3 = a1 - 213 < 0;
LABEL_32:
      if ( !((unsigned __int8)(v3 ^ v4) | v2) )
        goto LABEL_34;
LABEL_33:
      result = 1;
      break;
    default:
LABEL_34:
      result = 0;
      break;
  }
  return result;
}

//----- (00438CF3) --------------------------------------------------------
void __fastcall sub_438CF3(int a1)
{
  int v1; // esi@1
  int v2; // edi@2
  char v3; // bl@3
  int v4; // eax@12
  char v5; // sf@12
  _UNKNOWN *v6; // ecx@16
  signed int v7; // eax@18
  signed int v8; // esi@20

  v1 = uLevelMapStatsID;
  if ( uLevelMapStatsID )
  {
    v2 = 836 * a1;
    if ( sub_438B9B((int)((char *)pActors + 836 * a1)) )
    {
      v3 = 1;
      if ( v1 != 5 )
      {
        if ( v1 == 6 || v1 == 7 )
        {
          sub_449B57((int)byte_ACD71D, 99);
          if ( (unsigned __int16)sub_449B57((int)byte_ACD71D, 100) )
            return;
          goto LABEL_12;
        }
        if ( v1 != 8 )
          goto LABEL_12;
      }
      if ( (unsigned __int16)sub_449B57((int)byte_ACD71D, 99) )
        v3 = 0;
      if ( (unsigned __int16)sub_449B57((int)byte_ACD71D, 100) )
        v3 = 1;
      if ( v3 )
      {
LABEL_12:
        v4 = 100 * (pMapStats->pMapInfos[uLevelMapStatsID].dword_000024 + (unsigned __int8)byte_5FF18C[v2] + sub_47752B());
        v5 = v4 + dword_AE31E0 < 0;
        dword_AE31E0 += v4;
        if ( v5 )
          dword_AE31E0 = 0;
        if ( dword_AE31E0 > 4000000 )
          dword_AE31E0 = 4000000;
        v6 = &unk_6A12B8;
        if ( dword_6BE360 != 2 )
          v6 = &unk_6BE68C;
        v7 = *((_DWORD *)v6 + 2);
        if ( v7 < 10000 )
          *((_DWORD *)v6 + 2) = v7 + 1;
        v8 = (signed int)pPlayers;
        do
        {
          if ( dword_AE31E0 )
          {
            if ( !(unsigned __int16)sub_449B57(*(_DWORD *)v8 + 338, 1) )
              sub_449B7E(*(_DWORD *)v8 + 338, 1, 1);
          }
          v8 += 4;
        }
        while ( v8 <= (signed int)&dword_A750D4 );
        return;
      }
    }
  }
}

//----- (00438E35) --------------------------------------------------------
__int16 __thiscall sub_438E35(void *this)
{
  int v1; // eax@1
  unsigned int v2; // ecx@1
  int v3; // ebx@1
  void *v4; // edi@1
  int *v5; // esi@1
  int v6; // ebx@1
  int v7; // edx@2
  unsigned int v8; // edx@4
  unsigned int v9; // edx@6
  unsigned int v10; // eax@7
  signed int v11; // ebx@8
  void **v12; // esi@18
  signed int v13; // edi@20
  int v15; // [sp+Ch] [bp-Ch]@1
  int v16; // [sp+10h] [bp-8h]@1
  signed int v17; // [sp+14h] [bp-4h]@8
  int v18; // [sp+14h] [bp-4h]@14

  v4 = this;
  v5 = &pMapStats->pMapInfos[CMapStats_FindLocation(pMapStats, Str1)];
  v6 = abs(pParty_global->sPartyPosX - *((_DWORD *)v4 + 1));
  v15 = abs(pParty_global->sPartyPosY - *((_DWORD *)v4 + 2));
  v16 = abs(pParty_global->sPartyPosZ + pParty_global->uEyelevel - *((_DWORD *)v4 + 3));
  v1 = v6;
  v3 = v15;
  v2 = v16;
  if ( v1 < v15 )
  {
    v7 = v1;
    v1 = v15;
    v3 = v7;
  }
  if ( v1 < v16 )
  {
    v8 = v1;
    v1 = v16;
    v2 = v8;
  }
  if ( v3 < (signed int)v2 )
  {
    v9 = v2;
    v2 = v3;
    v3 = v9;
  }
  v10 = ((unsigned int)(11 * v3) >> 5) + (v2 >> 2) + v1;
  if ( (signed int)v10 <= 768 )
  {
    v17 = 0;
    v11 = 5;
    if ( *((_BYTE *)v5 + 46) )
    {
      do
      {
        ++v17;
        v11 += rand() % 20 + 1;
      }
      while ( v17 < *((_BYTE *)v5 + 46) );
    }
    switch ( *(_WORD *)v4 )
    {
      case 0x32B:
        v18 = 0;
        break;
      case 0x32C:
        v18 = 1;
        break;
      case 0x32D:
        v18 = 2;
        break;
      default:
        v10 = *(_WORD *)v4 - 814;
        if ( *(_WORD *)v4 != 814 )
          return v10;
        v18 = 8;
        break;
    }
    v12 = (void **)pPlayers;
    do
    {
      if ( sub_492C0B((int)*v12) && (v13 = sub_49125A(*v12) + 20, rand() % v13 > 20) )
        LOWORD(v10) = sub_4948B1(*v12, 6, 0);
      else
        LOWORD(v10) = sub_48DC1E((int)*v12, v11, v18);
      ++v12;
    }
    while ( (signed int)v12 <= (signed int)&dword_A750D4 );
  }
  return v10;
}

//----- (00439474) --------------------------------------------------------
__int16 __fastcall DamageMonsterFromParty(signed int a1, int a2, int a3)
{
  signed int v3; // eax@1
  int v4; // ebx@1
  unsigned int v5; // eax@3
  int v6; // edx@3
  int v7; // edi@4
  int v8; // esi@7
  char v9; // zf@11
  int v10; // eax@12
  unsigned int v11; // ecx@12
  int v12; // ebx@12
  int v13; // ebx@12
  int v14; // edx@15
  int v15; // edx@17
  int v16; // eax@24
  __int16 v17; // cx@25
  bool v18; // eax@29
  char v19; // zf@29
  unsigned __int8 v20; // zf@38
  unsigned __int8 v21; // sf@38
  bool v22; // eax@38
  unsigned __int8 v23; // zf@44
  unsigned __int8 v24; // sf@44
  int v25; // edx@44
  int v26; // eax@44
  signed int v27; // eax@51
  int v28; // edx@51
  int v29; // ecx@51
  signed int v30; // eax@53
  signed int v31; // eax@78
  signed int v32; // eax@86
  signed int v33; // eax@94
  int v34; // eax@96
  int v35; // eax@102
  int v36; // eax@106
  signed int v37; // eax@106
  double v38; // st7@106
  int v39; // ST08_4@106
  int v40; // ST04_4@106
  int v41; // ST00_4@106
  int v42; // ebx@109
  unsigned int v43; // ebx@111
  signed __int64 v44; // qax@127
  __int16 v45; // ax@134
  char v46; // bl@134
  __int16 v47; // ax@134
  int v49; // [sp+Ch] [bp-60h]@6
  int v50; // [sp+10h] [bp-5Ch]@6
  int v51; // [sp+14h] [bp-58h]@6
  int v52; // [sp+18h] [bp-54h]@6
  int v53; // [sp+1Ch] [bp-50h]@6
  int v54; // [sp+20h] [bp-4Ch]@6
  int *v55; // [sp+30h] [bp-3Ch]@6
  int v56; // [sp+34h] [bp-38h]@12
  int v57; // [sp+38h] [bp-34h]@10
  int v58; // [sp+3Ch] [bp-30h]@1
  int v59; // [sp+40h] [bp-2Ch]@12
  int v60; // [sp+44h] [bp-28h]@1
  int v61; // [sp+48h] [bp-24h]@10
  int v62; // [sp+4Ch] [bp-20h]@10
  int v63; // [sp+50h] [bp-1Ch]@1
  int v64; // [sp+54h] [bp-18h]@1
  int v65; // [sp+58h] [bp-14h]@1
  int v66; // [sp+5Ch] [bp-10h]@1
  int v67; // [sp+60h] [bp-Ch]@1
  int v68; // [sp+64h] [bp-8h]@27
  int v69; // [sp+6Bh] [bp-1h]@6

  v3 = a1;
  v4 = 0;
  v64 = a2;
  v58 = a1;
  v67 = 0;
  v60 = 0;
  v65 = 0;
  v63 = 0;
  v66 = 0;
  if ( (a1 & 7) == 2 )
  {
    v4 = (int)((char *)array_665230 + 112 * (a1 >> 3));
    v67 = v4;
    v65 = *(_BYTE *)(v4 + 96);
    v3 = *(_DWORD *)(v4 + 88);
    v58 = *(_DWORD *)(v4 + 88);
  }
  v6 = v3 & 7;
  v5 = v3 >> 3;
  if ( v6 != 4 )
    return v5;

  v7 = &pParty_global->pPlayers[v5];
  if ( (signed int)v5 < 0 )
  {
    if ( (signed int)v5 > 3 )
    {
      v53 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Damage.cpp";
      v55 = &v49;
      sub_40E2C8(&v49, "Invalid player in damageMonsterFromParty!", (int)&v69);
      sub_466D09(&v55, v49, v50, v51, v52, (const char *)v53, __LINE__);
    }
  }
  v8 = &pActors[v64];
  v5 = sub_4089C7(&pActors[v64]);
  if ( v5 )
    return v5;
  *(_BYTE *)(v8 + 37) |= 0xC0u;
  if ( *(_WORD *)(v8 + 176) == 7 )
    *(_DWORD *)(v8 + 36) |= 0x20000u;
  v62 = 0;
  v57 = 0;
  v61 = 0;
  if ( !v4 )
  {
    v55 = *(int **)(v7 + 6476);
    v63 = 1;
    if ( sub_48D6AA((void *)v7, 1) )
    {
      v59 = (unsigned __int8)byte_5D2A00[48 * *(_DWORD *)(v7 + 36 * (_DWORD)v55 + 496) + 1];
      v30 = sub_458244(*(_WORD *)(v7 + 2 * v59 + 264));
      v67 = v30;
      if ( v59 )
      {
        if ( v59 == 6 )
        {
          if ( v30 >= 3 )
          {
            LOBYTE(v55) = sub_48F882((void *)v7, 6) & 0x3F;
            v55 = (int *)(unsigned __int8)v55;
            if ( rand() % 100 < (unsigned __int8)v55 )
              v62 = 1;
          }
          if ( v67 >= 4 )
          {
            LOBYTE(v55) = sub_48F882((void *)v7, 6) & 0x3F;
            v55 = (int *)(unsigned __int8)v55;
            if ( rand() % 100 < (unsigned __int8)v55 )
              v57 = 1;
          }
        }
      }
      else
      {
        if ( v67 >= 3 )
        {
          LOBYTE(v55) = sub_48F882((void *)v7, 0) & 0x3F;
          v55 = (int *)(unsigned __int8)v55;
          if ( rand() % 100 < (unsigned __int8)v55 )
            v62 = 1;
        }
      }
    }
    v54 = *(_WORD *)(v8 + 96);
    v68 = 4;
    v27 = sub_48CDDB((void *)v7, 0, 0, v54);
    goto LABEL_65;
  }
  v9 = *(_DWORD *)(v4 + 72) == 99;
  v65 = *(_BYTE *)(v4 + 96);
  if ( !v9 )
  {
    v13 = v67;
    v54 = pParty_global->sPartyPosX - *(_DWORD *)(v67 + 4);
    v59 = abs(v54);
    v53 = pParty_global->sPartyPosY - *(_DWORD *)(v13 + 8);
    v55 = (int *)abs(v53);
    v52 = pParty_global->sPartyPosZ - *(_DWORD *)(v13 + 12);
    v56 = abs(v52);
    v65 = v59;
    v10 = v59;
    v12 = (int)v55;
    v11 = v56;
    if ( v59 < (signed int)v55 )
    {
      v10 = (int)v55;
      v12 = v59;
    }
    if ( v10 < v56 )
    {
      v14 = v10;
      v10 = v56;
      v11 = v14;
    }
    if ( v12 < (signed int)v11 )
    {
      v15 = v11;
      v11 = v12;
      v12 = v15;
    }
    v5 = ((unsigned int)(11 * v12) >> 5) + (v11 >> 2) + v10;
    v65 = v5;
    if ( (signed int)v5 >= 2560 )
    {
      if ( v65 >= 5120 && !(*(_BYTE *)(v8 + 37) & 4) )
        return v5;
      v65 = 2;
    }
    else
    {
      v65 = 1;
    }
    v4 = v67;
  }
  v16 = *(_DWORD *)(v4 + 72);
  if ( v16 == 102 )
  {
    v17 = *(_WORD *)(v7 + 278);
    v65 = 1;
    if ( sub_458244(v17) >= 3 )
      v60 = *(_BYTE *)(v7 + 278) & 0x3F;
    v68 = 4;
    v67 = sub_48CDDB((void *)v7, 1, 1, 0);
    goto LABEL_67;
  }
  if ( v16 != 100 )
  {
    if ( v16 == 101 )
    {
      v68 = 0;
      v22 = sub_48D1FE((void *)v7, 0);
      v20 = *(_DWORD *)(v8 + 456) == 0;
      v21 = *(_DWORD *)(v8 + 456) < 0;
      v67 = v22;
      if ( !v21 )
      {
        if ( !(v21 | v20) || *(_DWORD *)(v8 + 452) )
          v67 >>= 1;
      }
      v63 = 1;
      goto LABEL_67;
    }
    if ( v16 == 39 )
    {
      v60 = 5 * *(_DWORD *)(v4 + 76);
      v68 = sub_48E1A3(39);
      v25 = *(_DWORD *)(v4 + 76);
      v54 = *(_WORD *)(v8 + 40);
      v53 = *(_DWORD *)(v4 + 80);
      v26 = sub_43AFE3(39, v25, v53, v54);
      v23 = *(_DWORD *)(v8 + 456) == 0;
      v24 = *(_DWORD *)(v8 + 456) < 0;
      v67 = v26;
      if ( !v24 )
      {
        if ( !(v24 | v23) || *(_DWORD *)(v8 + 452) )
          v67 >>= 1;
      }
      v63 = 0;
LABEL_67:
      if ( !sub_4272F5(v7, v8, v65, v60) )
      {
LABEL_68:
        LOWORD(v5) = sub_4948B1((void *)v7, 52, 0);
        return v5;
      }
      goto LABEL_69;
    }
    if ( v16 == 34 )
    {
      v67 = 0;
      v68 = 4;
      v62 = 1;
      goto LABEL_67;
    }
    v54 = *(_DWORD *)(v4 + 72);
    v68 = sub_48E1A3(v54);
    v28 = *(_DWORD *)(v4 + 76);
    v29 = *(_DWORD *)(v4 + 72);
    v54 = *(_WORD *)(v8 + 40);
    v53 = *(_DWORD *)(v4 + 80);
    v27 = sub_43AFE3(v29, v28, v53, v54);
    v63 = 0;
    v61 = 1;
LABEL_65:
    v67 = v27;
    goto LABEL_66;
  }
  v54 = *(_WORD *)(v8 + 134);
  v68 = 4;
  v18 = sub_48D1FE((void *)v7, v54);
  v19 = *(_DWORD *)(v4 + 36) == 0;
  v67 = v18;
  if ( !v19 )
  {
    if ( *(_DWORD *)(v4 + 48) == 3 )
    {
      v68 = 0;
      v61 = 1;
    }
  }
  if ( *(_DWORD *)(v8 + 456) >= 0 )
  {
    if ( *(_DWORD *)(v8 + 456) > 0 || *(_DWORD *)(v8 + 452) )
      v67 >>= 1;
  }
  v63 = 1;
LABEL_66:
  if ( !v61 )
    goto LABEL_67;
LABEL_69:
  if ( *(_QWORD *)(v7 + 8) )
    v67 >>= 1;
  if ( *(_QWORD *)(v8 + 292) > 0i64 )
    v67 = 0;
  v65 = sub_42756B(v8, v68, v67);
  if ( !v4 )
  {
    if ( sub_48D676((void *)v7) )
    {
      if ( *(_DWORD *)(v7 + 6148) >= v4 )
      {
        if ( *(_DWORD *)(v7 + 6148) > v4 || *(_DWORD *)(v7 + 6144) > (unsigned int)v4 )
        {
          v54 = *(_WORD *)(v7 + 6152);
          v31 = sub_42756B(v8, 8, v54);
          v65 += v31;
        }
      }
    }
  }
  v67 = v65;
  if ( v63 )
  {
    if ( v4 )
    {
      v60 = sub_439DF3(v4 + 36, (int)&v68, (int)&v66);
      if ( v66 )
      {
        if ( *(_WORD *)(v8 + 40) > 0 )
        {
          *(_DWORD *)(v7 + 6460) += v65 / 5;
          if ( *(_DWORD *)(v7 + 6460) > Player_GetMaxHealth(v7) )
            *(_DWORD *)(v7 + 6460) = Player_GetMaxHealth(v7);
          v66 = 0;
        }
      }
      v32 = sub_42756B(v8, v68, v60);
      v67 = v65 + v32;
    }
    else
    {
      v63 = 0;
      v61 = v7 + 6472;
      do
      {
        if ( sub_48D6AA((void *)v7, v63) )
        {
          v60 = sub_439DF3(v7 + 36 * *(_DWORD *)v61 + 496, (int)&v68, (int)&v66);
          if ( v66 )
          {
            if ( *(_WORD *)(v8 + 40) > 0 )
            {
              *(_DWORD *)(v7 + 6460) += v65 / 5;
              if ( *(_DWORD *)(v7 + 6460) > Player_GetMaxHealth(v7) )
                *(_DWORD *)(v7 + 6460) = Player_GetMaxHealth(v7);
              v66 = 0;
            }
          }
          v33 = sub_42756B(v8, v68, v60);
          v67 += v33;
        }
        ++v63;
        v61 += 4;
      }
      while ( v63 <= 1 );
    }
  }
  v34 = v67;
  *(_WORD *)(v8 + 40) -= v67;
  if ( !v34 && !v62 )
    goto LABEL_68;
  if ( *(_WORD *)(v8 + 40) > 0 )
  {
    sub_4030AD(v64, v58, 0);
    sub_43AC45(v64, 1);
    if ( dword_6BE378 )
    {
      v54 = v67;
      v53 = v8;
      v52 = v7 + 168;
      if ( v4 )
        v51 = pGlobalTXT_LocalizationStrings[189];
      else
        v51 = pGlobalTXT_LocalizationStrings[164];
      sprintfex(&TmpBuf, (const char *)v51, v52, v53, v54);
      sub_44C175(&TmpBuf, 2);
    }
    v43 = 0;
  }
  else
  {
    if ( pMonsterStats->pMonsterInfos[*(_WORD *)(v8 + 96)].bQuestMonster & 1 )
    {
      if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3618) & 8 )
        v35 = 10 * *(_WORD *)(v8 + 136);
      else
        v35 = *(_WORD *)(v8 + 136);
      v59 = v35;
      if ( pD3DRenderer->dword_040088 )
      {
        if ( *(_BYTE *)(LODWORD(pGame) + 3620) & 0x20 )
        {
          v54 = 0;
          v53 = 0;
          v36 = *(_WORD *)(v8 + 146);
          *(float *)&v52 = (double)v59;
          v55 = (int *)v36;
          *(float *)&v51 = 0.0;
          v37 = *(_WORD *)(v8 + 144);
          *(float *)&v50 = 0.0;
          *(float *)&v49 = 1.0;
          v38 = (double)(signed int)v55;
          v55 = (int *)v37;
          *(float *)&v39 = v38;
          v55 = (int *)*(_WORD *)(v8 + 142);
          *(float *)&v40 = (double)v37;
          *(float *)&v41 = (double)(signed int)v55;
          sub_49B490(v41, v40, v39, 1.0, 0.0, 0.0, v52, 0, 0);
        }
      }
    }
    sub_402D6E(v64);
    sub_438CF3(v64);
    sub_43AC45(v64, 1);
    if ( *(_DWORD *)(v8 + 116) )
      sub_4269A2(pMonsterStats->pMonsterInfos[*(_WORD *)(v8 + 96)].uExp);
    v42 = 51;
    if ( rand() % 100 < 20 )
      v42 = (*(_DWORD *)(v8 + 108) >= 100) + 1;
    sub_4948B1((void *)v7, v42, 0);
    v43 = 0;
    if ( dword_6BE378 )
    {
      v54 = v8;
      v53 = v67;
      v52 = v7 + 168;
      sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[175], v7 + 168, v67, v8);
      sub_44C175(&TmpBuf, 2);
    }
  }
  if ( *(_DWORD *)(v8 + 536) >= (signed int)v43 )
  {
    if ( *(_DWORD *)(v8 + 536) > (signed int)v43 || *(_DWORD *)(v8 + 532) > v43 )
    {
      if ( v67 != v43 )
        sub_48DC1E(v7, v67, v68);
    }
  }
  v54 = 24;
  v63 = 20 * v65 / *(_DWORD *)(v8 + 108);
  if ( Player_sub_48EA46((void *)v7, 24) || v62 != v43 )
  {
    if ( sub_427662(v8, 3) )
    {
      LODWORD(v44) = 20;
      v63 = 10;
      if ( dword_ACD834 == v43 )
        v44 = (signed __int64)(flt_6BE3A8 * *(double *)&byte_4D8410[456]);
      *(_DWORD *)(v8 + 124) += v44;
      if ( dword_6BE378 != v43 )
      {
        v54 = v8;
        v53 = v7 + 168;
        sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[635], v7 + 168, v8);
        sub_44C175(&TmpBuf, 2);
      }
    }
  }
  if ( v57 != v43 )
  {
    if ( sub_40894B(v8) )
    {
      if ( sub_427662(v8, 3) )
      {
        LOBYTE(v45) = sub_48F882((void *)v7, 6);
        v46 = v45;
        v47 = sub_458244(v45);
        v55 = (int *)(7680 * (v46 & 0x3F));
        sub_4584E0(
          v8 + 308,
          pParty_global->qword_00002C + (signed __int64)((double)(signed int)v55 * 0.03333333507180214),
          (unsigned __int64)(pParty_global->qword_00002C + (signed int)(signed __int64)((double)(signed int)v55 * 0.03333333507180214)) >> 32,
          v47,
          0,
          0,
          0);
        if ( dword_6BE378 )
        {
          v54 = v8;
          v53 = v7 + 168;
          sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[636], v7 + 168, v8);
          sub_44C175(&TmpBuf, 2);
        }
      }
    }
  }
  if ( v63 > 10 )
    v63 = 10;
  if ( !sub_438BDF(*(_WORD *)(v8 + 96), 6) )
  {
    *(_DWORD *)a3 = (unsigned __int64)(v63 * *(_DWORD *)a3) >> 16;
    *(_DWORD *)(a3 + 4) = (unsigned __int64)(v63 * *(_DWORD *)(a3 + 4)) >> 16;
    *(_DWORD *)(a3 + 8) = (unsigned __int64)(v63 * *(_DWORD *)(a3 + 8)) >> 16;
    *(_WORD *)(v8 + 148) = 50 * *(_WORD *)a3;
    *(_WORD *)(v8 + 150) = 50 * *(_WORD *)(a3 + 4);
    *(_WORD *)(v8 + 152) = 50 * *(_WORD *)(a3 + 8);
  }
  LOWORD(v5) = sub_43AE80(v64, 1, v65);
  return v5;
}

//----- (00439DF3) --------------------------------------------------------
int __fastcall sub_439DF3(int a1, int a2, int a3)
{
  int v3; // ebx@1
  int v4; // edi@1
  signed int v5; // esi@1
  int v7; // ecx@5
  signed int v8; // ebx@7
  int v9; // edx@22
  int v10; // eax@24
  int v11; // edx@25
  int v12; // ebx@28
  int v13; // ebx@29
  int v14; // ebx@30
  int v15; // ebx@31
  int v16; // ebx@32
  signed int v17; // [sp-4h] [bp-10h]@24

  v4 = a2;
  v3 = a1;
  v5 = 0;
  *(_DWORD *)a2 = 0;
  if ( !*(_DWORD *)a1 )
    return 0;
  sub_458260(a1, pParty_global->qword_00002C);
  if ( *(_DWORD *)v3 == 501 )
  {
LABEL_45:
    *(_DWORD *)v4 = 1;
    v10 = rand();
    v17 = 10;
    return v10 % v17 + 6;
  }
  if ( *(_DWORD *)v3 == 507 )
  {
    *(_DWORD *)v4 = 0;
    v11 = rand() % 16;
    return v11 + 3;
  }
  v7 = 3;
  if ( *(_DWORD *)v3 == 510 )
  {
    *(_DWORD *)v4 = 2;
    v9 = rand() % 4;
    return v9 + 9;
  }
  if ( *(_DWORD *)v3 == 517 )
    goto LABEL_36;
  v8 = *(_DWORD *)(v3 + 12);
  if ( v8 > 46 )
  {
LABEL_42:
    v5 = 0;
    goto LABEL_37;
  }
  if ( v8 == 46 )
  {
    *(_DWORD *)v4 = 0;
    return rand() % 11 + 10;
  }
  if ( v8 > 11 )
  {
    v12 = v8 - 12;
    if ( !v12 )
    {
      *(_DWORD *)v4 = 0;
      return sub_452B2E(v7, 6);
    }
    v13 = v12 - 1;
    if ( !v13 )
    {
      *(_DWORD *)v4 = 8;
      return 5;
    }
    v14 = v13 - 1;
    if ( v14 )
    {
      v15 = v14 - 1;
      if ( v15 )
      {
        v16 = v15 - 1;
        if ( !v16 || v16 == 25 )
        {
          *(_DWORD *)v4 = 10;
          *(_DWORD *)a3 = 1;
          return v5;
        }
        goto LABEL_42;
      }
      *(_DWORD *)v4 = 2;
      return 12;
    }
LABEL_36:
    v5 = 8;
LABEL_37:
    *(_DWORD *)v4 = v5;
    return v5;
  }
  if ( v8 == 11 )
  {
    *(_DWORD *)v4 = 0;
    v7 = 2;
    return sub_452B2E(v7, 6);
  }
  if ( v8 == 4 )
  {
    *(_DWORD *)v4 = 2;
    v11 = rand() % 2;
    return v11 + 3;
  }
  if ( v8 == 5 )
  {
    *(_DWORD *)v4 = 2;
    v10 = rand();
    v17 = 3;
    return v10 % v17 + 6;
  }
  if ( v8 == 6 )
  {
    *(_DWORD *)v4 = 2;
    v9 = rand() % 4;
    return v9 + 9;
  }
  if ( v8 == 7 )
  {
    *(_DWORD *)v4 = 1;
    return rand() % 4 + 2;
  }
  if ( v8 == 8 )
  {
    *(_DWORD *)v4 = 1;
    return rand() % 7 + 4;
  }
  if ( v8 == 9 )
    goto LABEL_45;
  if ( v8 != 10 )
    goto LABEL_42;
  *(_DWORD *)v4 = 0;
  v7 = 1;
  return sub_452B2E(v7, 6);
}

//----- (00439FCB) --------------------------------------------------------
void __fastcall sub_439FCB(signed int a1, int a2, int a3, int a4)
{
  int v4; // ecx@1
  int v5; // esi@1
  int v6; // ebx@3
  int v7; // esi@3
  int v8; // eax@4
  int v9; // eax@5
  signed int v10; // eax@6
  int v11; // edx@8
  int v12; // edx@9
  int v13; // edx@10
  int v14; // edx@16
  int v15; // edx@17
  int v16; // edx@18
  int v17; // eax@24
  unsigned __int8 v18; // zf@26
  unsigned __int8 v19; // sf@26
  int v20; // eax@26
  unsigned __int16 v21; // ax@29
  int v22; // edi@36
  int v23; // eax@38
  signed int v24; // eax@44
  __int16 v25; // cx@47
  signed int v26; // eax@49
  int v27; // eax@54
  int v28; // ST18_4@58
  double v29; // st7@58
  int v30; // ST08_4@58
  double v31; // st7@58
  int v32; // ST04_4@58
  int v33; // ST00_4@58
  int v34; // edi@61
  int v35; // eax@70
  double v36; // st7@70
  int v37; // eax@77
  char *v38; // ebx@77
  int v39; // edi@77
  int v40; // esi@77
  int v41; // eax@77
  int v42; // eax@78
  char *v43; // eax@81
  int v44; // esi@82
  __int16 v45; // ax@84
  int v46; // edi@84
  int v47; // ebx@105
  int v48; // eax@107
  unsigned __int16 v49; // ax@116
  int v50; // ebx@123
  char v51; // bl@124
  __int16 v52; // ax@124
  int v53; // eax@128
  signed int v54; // eax@134
  __int16 v55; // cx@137
  signed int v56; // eax@139
  int v57; // eax@144
  int v58; // ST18_4@148
  double v59; // st7@148
  int v60; // ST08_4@148
  double v61; // st7@148
  int v62; // ST04_4@148
  int v63; // ST00_4@148
  int v64; // ebx@151
  int v65; // eax@161
  double v66; // st7@161
  int v67; // ecx@164
  signed int v68; // eax@170
  int v69; // ecx@170
  int v70; // eax@171
  signed int v71; // [sp+20h] [bp-34h]@12
  int v72[5]; // [sp+30h] [bp-24h]@164
  double v73; // [sp+40h] [bp-14h]@72
  int v74; // [sp+44h] [bp-10h]@1
  int v75; // [sp+48h] [bp-Ch]@3
  int v76; // [sp+4Ch] [bp-8h]@1
  int v77; // [sp+50h] [bp-4h]@26
  signed int v78; // [sp+60h] [bp+Ch]@73
  int v79; // [sp+60h] [bp+Ch]@162
  int v80; // [sp+60h] [bp+Ch]@168

  v5 = a1 >> 3;
  v4 = (a1 & 7) - 2;
  v74 = a2;
  v76 = v5;
  if ( !v4 )
  {
    v38 = (char *)array_665230 + 112 * v76;
    v39 = *((_DWORD *)v38 + 22) & 7;
    v40 = *((_DWORD *)v38 + 22) >> 3;
    v41 = *((_DWORD *)v38 + 22) & 7;
    v76 = *((_DWORD *)v38 + 22) >> 3;
    v37 = v41 - 2;
    if ( !v37 )
      goto LABEL_80;
    v42 = v37 - 1;
    if ( v42 )
    {
      if ( v42 != 1 )
        return;
LABEL_80:
      if ( a4 == -1 )
      {
        v74 = 0;
        v79 = 1;
        do
        {
          if ( sub_492C0B((int)*(&ptr_A750C4 + v79)) )
          {
            v67 = v74++;
            v72[v67] = v79;
          }
          ++v79;
        }
        while ( v79 <= 4 );
        if ( !v74 )
          return;
        v43 = &pParty_global->pPlayers[v72[rand() % v74] - 1];
      }
      else
      {
        v43 = (char *)&pParty_global->pPlayers[1743 * a4];
      }
      v80 = (int)v43;
      if ( v39 != 4 || *((_DWORD *)v38 + 18) != 100 )
      {
        v70 = Player_GetMaxHealth(v80);
        v68 = sub_43AFE3(*((_DWORD *)v38 + 18), *((_DWORD *)v38 + 19), *((_DWORD *)v38 + 20), v70);
        v69 = pSpellStats->pSpellInfos[*((_DWORD *)v38 + 18)].uSpellSchool;
      }
      else
      {
        v68 = sub_48D1FE(&pParty_global->pPlayers[1743 * v76], 0);
        v69 = 0;
      }
      sub_48DC1E(v80, v68, v69);
      if ( v39 == 4 )
      {
        if ( !qword_A750D8 )
        {
          qword_A750D8 = 256i64;
          word_A750E0 = 44;
          word_A750E2 = v76 + 1;
        }
      }
      return;
    }
    v44 = (int)((char *)pActors + 836 * v40);
    if ( a4 == -1 )
      a4 = sub_426E10(v44);
    v46 = &pParty_global->pPlayers[1743 * a4];
    v77 = sub_43B3E0(v44, v74);
    v45 = *(_WORD *)v38;
    if ( *(_WORD *)v38 == 545 )
    {
      LOBYTE(v52) = sub_48F882((void *)v46, 31);
      v51 = v52;
      if ( sub_458244(v52) >= 4 && rand() % 100 < (v51 & 0x3F) )
      {
        sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[637], v46 + 168);
        sub_44C175(&TmpBuf, 2);
        sub_4948B1((void *)v46, 6, 0);
        return;
      }
    }
    else
    {
      if ( v45 != 555
        && v45 != 510
        && v45 != 500
        && v45 != 515
        && v45 != 505
        && v45 != 530
        && v45 != 525
        && v45 != 520
        && v45 != 535
        && v45 != 540 )
        goto LABEL_115;
    }
    if ( !sub_4274AD(v44, v46) )
      return;
    if ( *(_QWORD *)(v46 + 6256) > 0i64 )
      v77 >>= 1;
    if ( sub_48D6D0((void *)v46, 36) )
      v77 >>= 1;
    if ( sub_48D6D0((void *)v46, 69) )
      v77 >>= 1;
    if ( sub_48D6AA((void *)v46, 3) )
    {
      if ( *(_DWORD *)(v46 + 36 * *(_DWORD *)(v46 + 6484) + 496) == 504 )
        v77 >>= 1;
    }
    v75 = 0;
    v47 = v46 + 6472;
    do
    {
      if ( sub_48D6AA((void *)v46, v75) )
      {
        v48 = *(_DWORD *)(v46 + 36 * *(_DWORD *)v47 + 496);
        if ( v48 == 520 )
          v77 >>= 1;
        if ( v48 == 531 )
          v77 >>= 1;
        if ( sub_48D62C((void *)v46, v75) == 4 )
        {
          if ( sub_458244(*(_WORD *)(v46 + 280)) == 4 )
            v77 >>= 1;
        }
      }
      ++v75;
      v47 += 4;
    }
    while ( v75 <= 1 );
LABEL_115:
    if ( *(_QWORD *)(v44 + 260) > 0i64 )
    {
      v49 = *(_WORD *)(v44 + 268);
      if ( v49 )
        v77 /= (signed int)v49;
    }
    if ( v74 )
    {
      if ( v74 == 1 )
      {
        v50 = *(_BYTE *)(v44 + 71);
      }
      else
      {
        if ( v74 == 2 )
        {
          v53 = *(_BYTE *)(v44 + 77);
        }
        else
        {
          if ( v74 != 3 )
          {
            if ( v74 == 4 )
              v50 = *(_WORD *)(v44 + 104);
            else
              v50 = 4;
            goto LABEL_133;
          }
          v53 = *(_BYTE *)(v44 + 79);
        }
        //v50 = (unsigned __int8)byte_5CC04C[36 * v53];
        v50 = pSpellStats->pSpellInfos[v53].uSpellSchool;
      }
    }
    else
    {
      v50 = *(_BYTE *)(v44 + 65);
    }
LABEL_133:
    if ( !(dword_6BE368 & 0x10) )
    {
      v54 = sub_48DC1E(v46, v77, v50);
      if ( *(_DWORD *)(v46 + 6212) >= 0 )
      {
        if ( *(_DWORD *)(v46 + 6212) > 0 || *(_DWORD *)(v46 + 6208) )
        {
          v55 = *(_WORD *)(v44 + 176);
          if ( v55 != 5 )
          {
            if ( v55 != 4 )
            {
              v56 = sub_42756B(v44, v50, v54);
              *(_WORD *)(v44 + 40) -= v56;
              if ( v56 )
              {
                if ( *(_WORD *)(v44 + 40) >= 1 )
                {
                  sub_4030AD(v76, 8 * a4 | 4, 0);
                  sub_43AC45(v76, 1);
                }
                else
                {
                  if (pMonsterStats->pMonsterInfos[*(_WORD *)(v44 + 96)].bQuestMonster & 1 )
                  {
                    if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3618) & 8 )
                      v57 = 10 * *(_WORD *)(v44 + 136);
                    else
                      v57 = *(_WORD *)(v44 + 136);
                    v75 = v57;
                    if ( pD3DRenderer->dword_040088 )
                    {
                      if ( *(_BYTE *)(LODWORD(pGame) + 3620) & 0x20 )
                      {
                        *(float *)&v58 = (double)v75;
                        v75 = *(_WORD *)(v44 + 146);
                        v59 = (double)v75;
                        v75 = *(_WORD *)(v44 + 144);
                        *(float *)&v60 = v59;
                        v61 = (double)v75;
                        v75 = *(_WORD *)(v44 + 142);
                        *(float *)&v62 = v61;
                        *(float *)&v63 = (double)v75;
                        sub_49B490(v63, v62, v60, 1.0, 0.0, 0.0, v58, 0, 0);
                      }
                    }
                  }
                  sub_402D6E(v76);
                  sub_438CF3(v76);
                  sub_43AC45(v76, 1);
                  if ( *(_DWORD *)(v44 + 116) )
                    sub_4269A2(pMonsterStats->pMonsterInfos[*(_WORD *)(v44 + 96)].uExp);
                  v64 = 51;
                  if ( rand() % 100 < 20 )
                    v64 = (*(_DWORD *)(v44 + 108) >= 100) + 1;
                  sub_4948B1((void *)v46, v64, 0);
                }
              }
            }
          }
        }
      }
    }
    if ( !v74 )
    {
      if ( !(dword_6BE368 & 0x10) )
      {
        if ( *(_BYTE *)(v44 + 63) )
        {
          if ( rand() % 100 < *(_BYTE *)(v44 + 52) * *(_BYTE *)(v44 + 64) )
            sub_48DCF6((char *)v46, *(_BYTE *)(v44 + 63), v44);
        }
      }
    }
    if ( !dword_ACD834 )
    {
      v65 = Player_GetActualEndurance(v46);
      v66 = (double)(20 - sub_48EA1B(v65)) * flt_6BE3A4 * *(double *)&byte_4D8410[40];
      sub_48E96A(v46, (signed __int64)v66);
    }
    return;
  }
  if ( v4 == 1 )
  {
    v6 = &pParty_global->pPlayers[1743 * a4];
    v7 = (int)((char *)pActors + 836 * v5);
    v75 = *(_DWORD *)(v6 + 6460);
    if ( sub_4274AD(v7, v6) )
    {
      v8 = *(_DWORD *)(v6 + 6484);
      if ( !v8
        || (v9 = v6 + 36 * v8, *(_BYTE *)(v9 + 516) & 2)
        || (v10 = (unsigned __int8)byte_5D2A00[48 * *(_DWORD *)(v9 + 496) + 1], v10 < 10)
        || v10 > 11 )
      {
        v14 = rand() % 4;
        if ( !v14 )
        {
          v71 = 108;
          goto LABEL_24;
        }
        v15 = v14 - 1;
        if ( !v15 )
        {
          v71 = 109;
          goto LABEL_24;
        }
        v16 = v15 - 1;
        if ( !v16 )
        {
          v71 = 110;
          goto LABEL_24;
        }
        if ( v16 == 1 )
        {
          v71 = 44;
          goto LABEL_24;
        }
      }
      else
      {
        v11 = rand() % 4;
        if ( !v11 )
        {
          v71 = 105;
          goto LABEL_24;
        }
        v12 = v11 - 1;
        if ( !v12 )
        {
          v71 = 106;
          goto LABEL_24;
        }
        v13 = v12 - 1;
        if ( !v13 )
        {
          v71 = 107;
          goto LABEL_24;
        }
        if ( v13 == 1 )
        {
          v71 = 45;
LABEL_24:
          v17 = v71;
          goto LABEL_26;
        }
      }
      v17 = a4;
LABEL_26:
      AudioPlayer_sub_4AA306(pAudioPlayer, v17, (8 * a4 + 80) | 4, 0, -1, 0, 0, 0, 0);
      v20 = sub_43B3E0(v7, v74);
      v18 = *(_DWORD *)(v7 + 264) == 0;
      v19 = *(_DWORD *)(v7 + 264) < 0;
      v77 = v20;
      if ( !v19 )
      {
        if ( !(v19 | v18) || *(_DWORD *)(v7 + 260) > 0u )
        {
          v21 = *(_WORD *)(v7 + 268);
          if ( v21 )
            v77 /= (signed int)v21;
        }
      }
      if ( v74 )
      {
        if ( v74 == 1 )
        {
          v22 = *(_BYTE *)(v7 + 71);
        }
        else
        {
          if ( v74 == 2 )
          {
            v23 = *(_BYTE *)(v7 + 77);
          }
          else
          {
            if ( v74 != 3 )
            {
              if ( v74 == 4 )
                v22 = *(_WORD *)(v7 + 104);
              else
                v22 = 4;
              goto LABEL_43;
            }
            v23 = *(_BYTE *)(v7 + 79);
          }
          //v22 = (unsigned __int8)byte_5CC04C[36 * v23];
          v22 = pSpellStats->pSpellInfos[v23].uSpellSchool;
        }
      }
      else
      {
        v22 = *(_BYTE *)(v7 + 65);
      }
LABEL_43:
      if ( !(dword_6BE368 & 0x10) )
      {
        v24 = sub_48DC1E(v6, v77, v22);
        if ( *(_DWORD *)(v6 + 6212) >= 0 )
        {
          if ( *(_DWORD *)(v6 + 6212) > 0 || *(_DWORD *)(v6 + 6208) )
          {
            v25 = *(_WORD *)(v7 + 176);
            if ( v25 != 5 )
            {
              if ( v25 != 4 )
              {
                v26 = sub_42756B(v7, v22, v24);
                *(_WORD *)(v7 + 40) -= v26;
                if ( v26 )
                {
                  if ( *(_WORD *)(v7 + 40) >= 1 )
                  {
                    sub_4030AD(v76, 8 * a4 | 4, 0);
                    sub_43AC45(v76, 1);
                  }
                  else
                  {
                    if (pMonsterStats->pMonsterInfos[*(_WORD *)(v7 + 96)].bQuestMonster & 1 )
                    {
                      if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3618) & 8 )
                        v27 = 10 * *(_WORD *)(v7 + 136);
                      else
                        v27 = *(_WORD *)(v7 + 136);
                      v74 = v27;
                      if ( pD3DRenderer->dword_040088 )
                      {
                        if ( *(_BYTE *)(LODWORD(pGame) + 3620) & 0x20 )
                        {
                          *(float *)&v28 = (double)v74;
                          v74 = *(_WORD *)(v7 + 146);
                          v29 = (double)v74;
                          v74 = *(_WORD *)(v7 + 144);
                          *(float *)&v30 = v29;
                          v31 = (double)v74;
                          v74 = *(_WORD *)(v7 + 142);
                          *(float *)&v32 = v31;
                          *(float *)&v33 = (double)v74;
                          sub_49B490(v33, v32, v30, 1.0, 0.0, 0.0, v28, 0, 0);
                        }
                      }
                    }
                    sub_402D6E(v76);
                    sub_438CF3(v76);
                    sub_43AC45(v76, 1);
                    if ( *(_DWORD *)(v7 + 116) )
                      sub_4269A2(pMonsterStats->pMonsterInfos[*(_WORD *)(v7 + 96)].uExp);
                    v34 = 51;
                    if ( rand() % 100 < 20 )
                      v34 = (*(_DWORD *)(v7 + 108) >= 100) + 1;
                    sub_4948B1((void *)v6, v34, 0);
                  }
                }
              }
            }
          }
        }
        if ( !(dword_6BE368 & 0x10) )
        {
          if ( *(_BYTE *)(v7 + 63) )
          {
            if ( rand() % 100 < *(_BYTE *)(v7 + 52) * *(_BYTE *)(v7 + 64) )
              sub_48DCF6((char *)v6, *(_BYTE *)(v7 + 63), v7);
          }
        }
      }
      if ( !dword_ACD834 )
      {
        v35 = Player_GetActualEndurance(v6);
        v36 = (double)(20 - sub_48EA1B(v35)) * flt_6BE3A4 * *(double *)&byte_4D8410[40];
        sub_48E96A(v6, (signed __int64)v36);
      }
      if ( v77 )
      {
        v73 = (double)v75;
        if ( (double)Player_GetMaxHealth(v6) * *(double *)&byte_4D8410[464] < v73 )
        {
          v78 = *(_DWORD *)(v6 + 6460);
          if ( *(_DWORD *)(v6 + 6460) > 0 )
          {
            if ( (double)Player_GetMaxHealth(v6) * *(double *)&byte_4D8410[464] >= (double)v78 )
              sub_4948B1((void *)v6, 48, 0);
          }
        }
      }
      struct_576FE8.dword_000044 = 1;
      return;
    }
  }
}

//----- (0043A97E) --------------------------------------------------------
void __fastcall sub_43A97E(int a1, signed int a2)
{
  int v2; // edx@1
  int v3; // ebx@1
  int v4; // edi@1
  int v5; // esi@1
  int v6; // [sp+10h] [bp-4h]@1

  v6 = a1;
  v5 = 112 * a1;
  v3 = a2 >> 3;
  v4 = dword_665288[28 * a1] & 7;
  v2 = (a2 & 7) - 3;
  if ( v2 )
  {
    if ( v2 == 1 )
    {
      dword_50FDFC = *(__int16 *)((char *)&word_665240 + v5);
      dword_50FE00 = *(__int16 *)((char *)&word_665242 + v5);
      dword_50FE04 = *(__int16 *)((char *)&word_665244 + v5);
      sub_43AB61((int)&dword_50FDFC, (int)&dword_50FE00, (int)&dword_50FE04);
      sub_439FCB(8 * v6 | 2, (unsigned __int8)byte_665291[v5], (int)&dword_50FDFC, -1);
    }
  }
  else
  {
    dword_50FDFC = *(__int16 *)((char *)&word_665240 + v5);
    dword_50FE00 = *(__int16 *)((char *)&word_665242 + v5);
    dword_50FE04 = *(__int16 *)((char *)&word_665244 + v5);
    sub_43AB61((int)&dword_50FDFC, (int)&dword_50FE00, (int)&dword_50FE04);
    switch ( v4 )
    {
      case 3:
        sub_43B1B0(8 * v6 | 2, v3, (int)&dword_50FDFC, (unsigned __int8)byte_665291[v5]);
        break;
      case 4:
        DamageMonsterFromParty(8 * v6 | 2, v3, (int)&dword_50FDFC);
        break;
      case 2:
        sub_43B057(8 * v6 | 2, v3, (int)&dword_50FDFC);
        break;
    }
  }
}

//----- (0043AA99) --------------------------------------------------------
int __fastcall sub_43AA99(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int result; // eax@1
  int v10; // ebx@1
  int v11; // ST14_4@1
  int v12; // edi@1
  int v13; // [sp+20h] [bp+8h]@1
  int v14; // [sp+20h] [bp+8h]@1

  v10 = a3;
  v11 = a1;
  v12 = a2;
  v13 = (unsigned __int64)(class59_SinCos(pClass59_global, a3) * a1) >> 16;
  *(_DWORD *)a7 = a4 + ((unsigned __int64)(class59_SinCos(pClass59_global, v12) * v13) >> 16);
  *(_DWORD *)a8 = a5 + ((unsigned __int64)(class59_SinCos(pClass59_global, v12 - pClass59_global->uNumTableEntries) * v13) >> 16);
  v14 = (unsigned __int64)(class59_SinCos(pClass59_global, v10 - pClass59_global->uNumTableEntries) * v11) >> 16;
  result = a9;
  *(_DWORD *)a9 = a6 + v14;
  return result;
}

//----- (0043AB61) --------------------------------------------------------
int __fastcall sub_43AB61(int a1, int a2, int a3)
{
  int result; // eax@1
  int v4; // edi@1
  int v5; // esi@1

  v4 = a1;
  v5 = a2;
  result = 65536
         / (sub_452A9E(*(_DWORD *)a2 * *(_DWORD *)a2 + *(_DWORD *)a3 * *(_DWORD *)a3 + *(_DWORD *)a1 * *(_DWORD *)a1) | 1);
  *(_DWORD *)v4 *= result;
  *(_DWORD *)v5 *= result;
  *(_DWORD *)a3 *= result;
  return result;
}

//----- (0043ABB0) --------------------------------------------------------
bool __fastcall sub_43ABB0(int a1, int a2)
{
  int v2; // edi@1
  int v3; // esi@1
  bool result; // eax@9

  v3 = *(_DWORD *)(a1 + 712);
  v2 = *(_DWORD *)(a2 + 712);
  if ( !v3 )
    v3 = (*(_WORD *)(a1 + 96) - 1) / 3 + 1;
  if ( !v2 )
    v2 = (*(_WORD *)(a2 + 96) - 1) / 3 + 1;
  if ( v3 >= 39 && v3 <= 44 && v2 >= 39 && v2 <= 44
    || v3 >= 45 && v3 <= 50 && v2 >= 45 && v2 <= 50
    || v3 >= 51 && v3 <= 62 && v2 >= 51 && v2 <= 62
    || v3 >= 78 && v3 <= 83 && v2 >= 78 && v2 <= 83 )
    result = 1;
  else
    result = v3 == v2;
  return result;
}

//----- (0043AC45) --------------------------------------------------------
void __fastcall sub_43AC45(int a1, int a2)
{
  int v2; // esi@1
  int v3; // edi@4
  int v4; // ebx@8
  int v5; // ST1C_4@8
  int v6; // eax@8
  int v7; // [sp+4h] [bp-10h]@1
  int v8; // [sp+Ch] [bp-8h]@1
  signed int v9; // [sp+10h] [bp-4h]@3

  v8 = a1;
  v2 = (int)((char *)pActors + 836 * a1);
  v7 = a2;
  if ( a2 == 1 )
    *(_BYTE *)(v2 + 38) |= 8u;
  v9 = 0;
  if ( (signed int)uNumActors > 0 )
  {
    v3 = &pActors[0].sActorPosY;
    do
    {
      if ( sub_40894B(v3 - 144) )
      {
        if ( v9 != v8 )
        {
          if ( sub_43ABB0(v2, v3 - 144) )
          {
            v4 = abs(*(_WORD *)(v3 - 2) - *(_WORD *)(v2 + 142));
            v5 = abs(*(_WORD *)v3 - *(_WORD *)(v2 + 144));
            v6 = abs(*(_WORD *)(v3 + 2) - *(_WORD *)(v2 + 146));
            if ( (double)sub_4621DA(v4, v5, v6) < 4096.0 )
            {
              *(_BYTE *)(v3 - 83) = 4;
              if ( v7 == 1 )
                *(_BYTE *)(v3 - 106) |= 8u;
            }
          }
        }
      }
      ++v9;
      v3 += 836;
    }
    while ( v9 < (signed int)uNumActors );
  }
}

//----- (0043AD34) --------------------------------------------------------
void __cdecl sub_43AD34()
{
  int v0; // esi@5
  int v1; // edi@9
  int v2; // ebx@9
  int v3; // eax@9
  int v4; // [sp+8h] [bp-4h]@4

  if ( qword_ACD8F4 > 0 )
    sub_458585((int)&qword_ACD8F4);
  if ( dword_ACD834 != 1 )
  {
    v4 = 0;
    if ( (signed int)uNumActors > 0 )
    {
      v0 = (int)byte_5FF193;
      do
      {
        if ( sub_40894B(v0 - 59) )
        {
          if ( *(_BYTE *)(v0 + 2) != 4 )
          {
            if ( *(_BYTE *)v0 != 5 )
            {
              v1 = abs(*(_WORD *)(v0 + 83) - pParty_global->sPartyPosX);
              v2 = abs(*(_WORD *)(v0 + 85) - pParty_global->sPartyPosY);
              v3 = abs(*(_WORD *)(v0 + 87) - pParty_global->sPartyPosZ);
              if ( (double)sub_4621DA(v1, v2, v3) < 512.0 )
                sub_402968(v4, 4, 0, 0);
            }
          }
        }
        ++v4;
        v0 += 836;
      }
      while ( v4 < (signed int)uNumActors );
    }
  }
}

//----- (0043AE12) --------------------------------------------------------
double __fastcall sub_43AE12(signed int a1)
{
  signed int v1; // ecx@1
  double v2; // st7@1
  signed int v3; // ST00_4@1
  double result; // st7@6

  v3 = a1;
  v1 = 0;
  v2 = (double)v3;
  do
  {
    if ( v2 < flt_4E4A94[v1] )
      break;
    ++v1;
  }
  while ( v1 < 5 );
  if ( v1 <= 0 || v1 >= 5 )
  {
    if ( v1 )
      result = flt_4E4A90;
    else
      result = flt_4E4A80[0];
  }
  else
  {
    result = (flt_4E4A80[v1] - *(float *)&"AuthenticAMD"[4 * v1 + 12])
           * (v2 - flt_4E4A94[v1 - 1])
           / (flt_4E4A94[v1] - flt_4E4A94[v1 - 1])
           + flt_4E4A80[v1];
  }
  return result;
}

//----- (0043AE80) --------------------------------------------------------
signed int __fastcall sub_43AE80(int a1, int a2, signed int a3)
{
  signed int result; // eax@1
  int v4; // esi@1
  int v5; // [sp-14h] [bp-18h]@3
  int v6; // [sp-10h] [bp-14h]@3
  int v7; // [sp-Ch] [bp-10h]@3
  int v8; // [sp-8h] [bp-Ch]@3
  __int16 v9; // [sp-4h] [bp-8h]@3

  result = a2 - 1;
  v4 = 8 * a1 | 3;
  switch ( a2 )
  {
    case 1:
      if ( a3 )
      {
        v9 = 0;
        v8 = (signed __int64)(sub_43AE12(a3) * 65536.0);
        v7 = 0;
        LOWORD(v6) = v4;
        v5 = 904;
        goto LABEL_16;
      }
      return result;
    case 2:
      if ( a3 )
      {
        v9 = 0;
        v8 = (signed __int64)(sub_43AE12(a3) * 65536.0);
        v7 = 0;
        LOWORD(v6) = v4;
        v5 = 905;
        goto LABEL_16;
      }
      return result;
    case 3:
      if ( a3 )
      {
        v9 = 0;
        v8 = (signed __int64)(sub_43AE12(a3) * 65536.0);
        v7 = 0;
        LOWORD(v6) = v4;
        v5 = 906;
        goto LABEL_16;
      }
      return result;
    case 4:
      if ( a3 )
      {
        v9 = 0;
        v8 = (signed __int64)(sub_43AE12(a3) * 65536.0);
        v7 = 0;
        LOWORD(v6) = v4;
        v5 = 907;
        goto LABEL_16;
      }
      return result;
    case 5:
      v9 = 4;
      v8 = 65536;
      v7 = 0;
      v6 = 8 * a1 | 3;
      v5 = 901;
      goto LABEL_16;
    case 6:
      v9 = 4;
      v8 = 65536;
      v7 = 0;
      v6 = 8 * a1 | 3;
      v5 = 902;
      goto LABEL_16;
    case 7:
      v9 = 4;
      v8 = 65536;
      v7 = 0;
      v6 = 8 * a1 | 3;
      v5 = 903;
      goto LABEL_16;
    case 8:
      v9 = 4;
      v8 = 65536;
      v7 = 0;
      v6 = 8 * a1 | 3;
      v5 = 900;
      goto LABEL_16;
    case 9:
      v9 = 4;
      v8 = 65536;
      v7 = 0;
      v6 = 8 * a1 | 3;
      v5 = 909;
      goto LABEL_16;
    case 10:
      v9 = 4;
      v8 = 65536;
      v7 = 0;
      v6 = 8 * a1 | 3;
      v5 = 908;
LABEL_16:
      result = sub_4418B6(array_5E4D58, v5, v6, v7, v8, v9);
      break;
    default:
      return result;
  }
  return result;
}

//----- (0043AFE3) --------------------------------------------------------
int __fastcall sub_43AFE3(int a1, int a2, signed int a3, int a4)
{
  int result; // eax@1
  signed int v5; // [sp-4h] [bp-8h]@9

  result = 0;
  if ( a1 == 7 )
  {
    if ( a3 <= 0 )
      return result;
    if ( a3 <= 2 )
    {
      v5 = 6;
    }
    else
    {
      if ( a3 == 3 )
      {
        v5 = 8;
      }
      else
      {
        if ( a3 != 4 )
          return result;
        v5 = 10;
      }
    }
    result = sub_452B2E(a2, v5);
  }
  else
  {
    if ( a1 == 44 )
      result = a4 * ((unsigned __int8)byte_4E3FE8 + 2 * a2) / 100;
    else
      result = (unsigned __int8)byte_4E3C78[20 * a1] + sub_452B2E(a2, (unsigned __int8)byte_4E3C79[20 * a1]);
  }
  return result;
}

//----- (0043B057) --------------------------------------------------------
__int16 __fastcall sub_43B057(int a1, int a2, int a3)
{
  bool v3; // eax@1
  int v4; // esi@1
  int v5; // ecx@3
  signed int v6; // edi@4
  int v7; // eax@4
  int v9; // [sp+8h] [bp-8h]@1
  int v10; // [sp+Ch] [bp-4h]@1
  int v11; // [sp+Ch] [bp-4h]@8

  v9 = a2;
  v4 = (int)((char *)pActors + 836 * a2);
  v10 = a1;
  v3 = sub_4089C7((int)((char *)pActors + 836 * a2));
  if ( !v3 )
  {
    LOWORD(v3) = v10 & 7;
    if ( v3 == 2 )
    {
      v3 = (bool)((char *)array_665230 + 112 * (v10 >> 3));
      v5 = *(_DWORD *)(v3 + 72);
      if ( v5 )
      {
        v7 = sub_43AFE3(v5, *(_DWORD *)(v3 + 76), *(_DWORD *)(v3 + 80), *(_WORD *)(v4 + 40));
        v6 = sub_42756B(v4, 0, v7);
        *(_WORD *)(v4 + 40) -= v6;
        if ( v6 )
        {
          if ( *(_WORD *)(v4 + 40) > 0 )
            sub_4030AD(v9, v10, 0);
          else
            sub_402D6E(v9);
          v11 = 20 * v6 / *(_DWORD *)(v4 + 108);
          if ( 20 * v6 / *(_DWORD *)(v4 + 108) > 10 )
            v11 = 10;
          if ( !sub_438BDF(*(_WORD *)(v4 + 96), 6) )
          {
            *(_DWORD *)a3 = (unsigned __int64)(v11 * *(_DWORD *)a3) >> 16;
            *(_DWORD *)(a3 + 4) = (unsigned __int64)(v11 * *(_DWORD *)(a3 + 4)) >> 16;
            *(_DWORD *)(a3 + 8) = (unsigned __int64)(v11 * *(_DWORD *)(a3 + 8)) >> 16;
            *(_WORD *)(v4 + 148) = 50 * *(_WORD *)a3;
            *(_WORD *)(v4 + 150) = 50 * *(_WORD *)(a3 + 4);
            *(_WORD *)(v4 + 152) = 50 * *(_WORD *)(a3 + 8);
          }
          LOWORD(v3) = sub_43AE80(v9, 1, v6);
        }
        else
        {
          LOWORD(v3) = sub_4030AD(v9, v10, 0);
        }
      }
    }
  }
  return v3;
}

//----- (0043B1B0) --------------------------------------------------------
__int16 __fastcall sub_43B1B0(signed int a1, int a2, int a3, signed int a4)
{
  int v4; // ebx@1
  char *v5; // eax@2
  bool v6; // eax@3
  int v7; // edi@4
  int v8; // esi@4
  char v9; // zf@5
  __int64 v10; // qax@8
  unsigned __int16 v11; // cx@9
  int v12; // ecx@20
  int v13; // ecx@22
  signed int v14; // edi@30
  int v16; // [sp+Ch] [bp-8h]@1
  int v17; // [sp+10h] [bp-4h]@1
  int v18; // [sp+20h] [bp+Ch]@34

  v4 = 0;
  v16 = a2;
  v17 = a1;
  if ( (a1 & 7) == 2 )
  {
    v5 = (char *)array_665230 + 112 * (a1 >> 3);
    v4 = (unsigned __int8)v5[96];
    v17 = *((_DWORD *)v5 + 22);
  }
  LOWORD(v6) = v17 & 7;
  if ( v6 == 3 )
  {
    v8 = (int)((char *)pActors + 836 * a2);
    v7 = (int)((char *)pActors + 836 * (v17 >> 3));
    v6 = sub_4089C7((int)((char *)pActors + 836 * a2));
    if ( !v6 )
    {
      v9 = *(_WORD *)(v8 + 176) == 7;
      *(_DWORD *)(v8 + 816) = v17;
      if ( v9 )
        *(_BYTE *)(v8 + 38) |= 2;
      v6 = sub_4273BB(v7, v8, v4, 0);
      if ( v6 )
      {
        v10 = (unsigned int)sub_43B3E0(v7, a4);
        if ( *(_QWORD *)(v7 + 260) > 0i64 )
        {
          v11 = *(_WORD *)(v7 + 268);
          if ( v11 )
            v10 = (_DWORD)v10 / (signed int)v11;
        }
        if ( *(_DWORD *)(v8 + 296) >= HIDWORD(v10) )
        {
          if ( *(_DWORD *)(v8 + 296) > HIDWORD(v10) || *(_DWORD *)(v8 + 292) > HIDWORD(v10) )
            LODWORD(v10) = 0;
        }
        if ( a4 == HIDWORD(v10) )
        {
          v12 = *(_BYTE *)(v7 + 65);
        }
        else
        {
          if ( a4 - HIDWORD(v10) == 1 )
          {
            v12 = *(_BYTE *)(v7 + 71);
            if ( *(_DWORD *)(v8 + 456) >= HIDWORD(v10) )
            {
              if ( *(_DWORD *)(v8 + 456) > HIDWORD(v10) || *(_DWORD *)(v8 + 452) > HIDWORD(v10) )
                LODWORD(v10) = (_DWORD)v10 >> 1;
            }
            goto LABEL_30;
          }
          if ( a4 - HIDWORD(v10) == 2 )
          {
            v13 = *(_BYTE *)(v8 + 77);
          }
          else
          {
            if ( a4 - HIDWORD(v10) != 3 )
            {
              if ( a4 - HIDWORD(v10) == 4 )
                v12 = *(_WORD *)(v7 + 104);
              else
                v12 = 4;
              goto LABEL_30;
            }
            v13 = *(_BYTE *)(v8 + 79);
          }
          //v12 = (unsigned __int8)byte_5CC04C[36 * v13];
          v12 = pSpellStats->pSpellInfos[v13].uSpellSchool;
        }
LABEL_30:
        v14 = sub_42756B(v8, v12, v10);
        *(_WORD *)(v8 + 40) -= v14;
        if ( v14 )
        {
          if ( *(_WORD *)(v8 + 40) > 0 )
            sub_4030AD(v16, v17, 0);
          else
            sub_402D6E(v16);
          sub_43AC45(v16, 0);
          v18 = 20 * v14 / *(_DWORD *)(v8 + 108);
          if ( 20 * v14 / *(_DWORD *)(v8 + 108) > 10 )
            v18 = 10;
          if ( !sub_438BDF(*(_WORD *)(v8 + 96), 6) )
          {
            *(_DWORD *)a3 = (unsigned __int64)(v18 * *(_DWORD *)a3) >> 16;
            *(_DWORD *)(a3 + 4) = (unsigned __int64)(v18 * *(_DWORD *)(a3 + 4)) >> 16;
            *(_DWORD *)(a3 + 8) = (unsigned __int64)(v18 * *(_DWORD *)(a3 + 8)) >> 16;
            *(_WORD *)(v8 + 148) = 50 * *(_WORD *)a3;
            *(_WORD *)(v8 + 150) = 50 * *(_WORD *)(a3 + 4);
            *(_WORD *)(v8 + 152) = 50 * *(_WORD *)(a3 + 8);
          }
          LOWORD(v6) = sub_43AE80(v16, 1, v14);
        }
        else
        {
          LOWORD(v6) = sub_4030AD(v16, v17, 0);
        }
        return v6;
      }
    }
  }
  return v6;
}

//----- (0043B3E0) --------------------------------------------------------
int __fastcall sub_43B3E0(int a1, signed int a2)
{
  signed int v2; // ebp@1
  int v3; // eax@9
  signed int v4; // edi@9
  int v5; // esi@9
  int v6; // ebx@11
  int v8; // edi@21
  __int16 v9; // si@21
  signed int v10; // eax@23
  int v11; // [sp+10h] [bp-4h]@1

  v2 = 0;
  v11 = 0;
  if ( !a2 )
  {
    if ( *(_QWORD *)(a1 + 436) > 0i64 )
      v2 = *(_WORD *)(a1 + 444);
    if ( *(_QWORD *)(a1 + 500) > 0i64 )
    {
      if ( *(_WORD *)(a1 + 508) > v2 )
        v2 = *(_WORD *)(a1 + 508);
    }
    if ( *(_QWORD *)(a1 + 548) > 0i64 )
      v2 += *(_WORD *)(a1 + 556);
    v3 = *(_BYTE *)(a1 + 66);
    v4 = *(_BYTE *)(a1 + 67);
    v5 = *(_BYTE *)(a1 + 68);
    goto LABEL_10;
  }
  if ( a2 == 1 )
  {
    v3 = *(_BYTE *)(a1 + 72);
    v4 = *(_BYTE *)(a1 + 73);
    v5 = *(_BYTE *)(a1 + 74);
    goto LABEL_10;
  }
  if ( a2 <= 1 )
    return 0;
  if ( a2 > 3 )
  {
    if ( a2 == 4 )
    {
      v3 = *(_BYTE *)(a1 + 91);
      v4 = *(_BYTE *)(a1 + 92);
      v5 = *(_BYTE *)(a1 + 93);
LABEL_10:
      if ( v3 > 0 )
      {
        v6 = v3;
        do
        {
          --v6;
          v11 += rand() % v4 + 1;
        }
        while ( v6 );
      }
      return v11 + v5 + v2;
    }
    return 0;
  }
  if ( a2 == 2 )
  {
    v9 = *(_WORD *)(a1 + 100);
    v8 = *(_BYTE *)(a1 + 77);
  }
  else
  {
    v9 = *(_WORD *)(a1 + 102);
    v8 = *(_BYTE *)(a1 + 79);
  }
  v10 = sub_458244(v9);
  return sub_43AFE3(v8, v9 & 0x3F, v10, 0);
}

//----- (0043B570) --------------------------------------------------------
double __thiscall sub_43B570(int this)
{
  int v1; // esi@1
  __int64 v2; // qax@2
  unsigned int v3; // ecx@2
  unsigned __int8 v4; // cf@2
  unsigned int v5; // ecx@2
  signed __int64 v6; // ST0C_8@2
  double result; // st7@3
  __int64 v8; // qax@4
  unsigned int v9; // ecx@4
  unsigned __int8 v10; // cf@4
  unsigned int v11; // ecx@4
  signed __int64 v12; // ST0C_8@4

  v1 = this;
  if ( *(_BYTE *)(this + 28) & 1 )
  {
    v2 = class24_fn2(pClass24_global);
    v3 = *(_DWORD *)(v1 + 32);
    v4 = v3 < (_DWORD)v2;
    v5 = v3 - v2;
    LODWORD(v6) = v5 + 384;
    HIDWORD(v6) = (v5 >= 0xFFFFFE80) + *(_DWORD *)(v1 + 36) - (v4 + HIDWORD(v2));
    if ( (double)v6 * 0.002604166744276881 >= 0.0 )
    {
      v8 = class24_fn2(pClass24_global);
      v9 = *(_DWORD *)(v1 + 32);
      v10 = v9 < (_DWORD)v8;
      v11 = v9 - v8;
      LODWORD(v12) = v11 + 384;
      HIDWORD(v12) = (v11 >= 0xFFFFFE80) + *(_DWORD *)(v1 + 36) - (v10 + HIDWORD(v8));
      result = (double)v12 * 0.002604166744276881;
    }
    else
    {
      result = 0.0;
    }
  }
  else
  {
    result = 1.0;
  }
  return result;
}

void __fastcall class26_placeholder_ctor(struct class26_placeholder *_this)
{
 _this->ptr_000000 = 0x4D8894;
 class26_ctor(&_this->objClass26);
}

//----- (0043B538) --------------------------------------------------------
void __fastcall sub_43B538(char *this)
{
  *(_DWORD *)(this + 28) = 0;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = 0;
  *(_DWORD *)this = 5080564;
}

//----- (0043B641) --------------------------------------------------------
void __fastcall sub_43B641(void *this)
{
  *(_DWORD *)this = 5080572;
  *(_DWORD *)this = 5080236;
}

//----- (0043B6D6) --------------------------------------------------------
int __thiscall sub_43B6D6(void *this)
{
  *(_DWORD *)this = 5080576;
  _eh_vector_destructor_iterator_((char *)this + 4, 40, 64, sub_43B569);
}

//----- (0043B76D) --------------------------------------------------------
int __thiscall sub_43B76D(int this)
{
  int v1; // esi@1
  int v3; // eax@5
  signed int v4; // [sp-18h] [bp-20h]@3
  int v5; // [sp-14h] [bp-1Ch]@3
  int v6; // [sp-10h] [bp-18h]@3
  const char *v7; // [sp-Ch] [bp-14h]@3
  unsigned int v8; // [sp-8h] [bp-10h]@3
  int v9; // [sp-4h] [bp-Ch]@3
  char v10; // [sp+4h] [bp-4h]@5

  v1 = this;
  *(_DWORD *)(this + 8) = 0;
  *(_BYTE *)(this + 28) = 0;
  *(_DWORD *)this = 5080580;
  if ( dword_F79D7C != 2 || dword_F79D70 != 4 )
  {
    v9 = 1;
    v8 = 28;
    v7 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputKeyboard.cpp";
    v6 = 0;
    v5 = this + 4;
    v4 = 1280;
  }
  else
  {
    v9 = 1;
    v8 = 26;
    v7 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputKeyboard.cpp";
    v6 = 0;
    v5 = this + 4;
    v4 = 768;
  }
  compile_error;//v3 = DirectInputCreateA(hInstance, v4, v5, v6);
  CheckHRESULT(&v10, v3, v7, v8, v9);
  sub_43B831(v1);
  sub_43B87B(v1);
  return v1;
}

//----- (0043B7FF) --------------------------------------------------------
int __thiscall sub_43B7FF(int this)
{
  int v1; // eax@1
  int v2; // esi@1
  int result; // eax@3

  v2 = this;
  v1 = *(_DWORD *)(this + 8);
  *(_DWORD *)this = 5080580;
  if ( v1 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v1 + 32))(v1);
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v2 + 8) + 8))(*(_DWORD *)(v2 + 8));
    *(_DWORD *)(v2 + 8) = 0;
  }
  result = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(v2 + 4) + 8))(*(_DWORD *)(v2 + 4));
  *(_DWORD *)(v2 + 4) = 0;
  return result;
}

//----- (0043B831) --------------------------------------------------------
void *__thiscall sub_43B831(int this)
{
  void *result; // eax@1
  int v2; // esi@1
  int v3; // eax@1
  int v4; // [sp+4h] [bp-4h]@1

  v2 = this;
  v3 = (*(int (__stdcall **)(_DWORD, signed int, signed int (__stdcall *)(int, int), int, signed int))(**(_DWORD **)(this + 4) + 16))(
         *(_DWORD *)(this + 4),
         3,
         sub_43B9B9,
         this,
         1);
  result = CheckHRESULT(&v4, v3, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputKeyboard.cpp", 0x34u, 1);
  if ( !*(_BYTE *)(v2 + 28) )
  {
    v4 = (int)"Error: No keyboard found";
    _CxxThrowException(&v4, 5094804);
  }
  return result;
}

//----- (0043B87B) --------------------------------------------------------
int __thiscall sub_43B87B(int this)
{
  int v2; // esi@1
  int v3; // eax@1
  int v4; // ST1C_4@1
  int v5; // eax@1
  int v6; // eax@1
  char v7; // [sp+8h] [bp-4h]@1

  v2 = this + 8;
  v3 = (*(int (__stdcall **)(_DWORD, int, int, _DWORD, _DWORD))(**(_DWORD **)(this + 4) + 12))(
         *(_DWORD *)(this + 4),
         this + 12,
         this + 8,
         0,
         "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputKeyboard.cpp");
  CheckHRESULT(&v7, v3, (const char *)0x3C, 1u, v4);
  v5 = (*(int (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)v2 + 44))(*(_DWORD *)v2, dword_4C9890);
  CheckHRESULT(&v7, v5, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputKeyboard.cpp", 0x3Fu, 1);
  v6 = (*(int (__stdcall **)(_DWORD, HWND, signed int))(**(_DWORD **)v2 + 52))(*(_DWORD *)v2, hWnd_global, 6);
  CheckHRESULT(&v7, v6, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputKeyboard.cpp", 0x40u, 1);
  return (*(int (**)(void))(**(_DWORD **)v2 + 28))();
}

//----- (0043B8EC) --------------------------------------------------------
char __thiscall update_data(int this)
{
  int v1; // eax@1
  int v2; // esi@1
  char result; // al@2
  int v4; // ebx@3
  int v5; // esi@5
  int v6; // eax@5
  char v7; // [sp-18h] [bp-2Ch]@2
  const CHAR *v8; // [sp-14h] [bp-28h]@2
  int v9; // [sp-10h] [bp-24h]@2
  int v10; // [sp-Ch] [bp-20h]@2
  const char *v11; // [sp-8h] [bp-1Ch]@2
  int v12; // [sp-4h] [bp-18h]@2
  char *v13; // [sp+Ch] [bp-8h]@2
  int v14; // [sp+13h] [bp-1h]@2

  v2 = this;
  v1 = *(_DWORD *)(this + 8);
  if ( v1 )
  {
    v4 = this + 29;
    if ( (*(int (__stdcall **)(int, signed int, int))(*(_DWORD *)v1 + 36))(v1, 256, this + 29) == -2147024866 )
    {
      if ( !(*(int (__stdcall **)(_DWORD))(**(_DWORD **)(v2 + 8) + 28))(*(_DWORD *)(v2 + 8)) )
      {
        v5 = *(_DWORD *)(v2 + 8);
        v12 = 1;
        v11 = (const char *)79;
        v10 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputKeyboard.cpp";
        v6 = (*(int (__stdcall **)(int, signed int, int))(*(_DWORD *)v5 + 36))(v5, 256, v4);
        CheckHRESULT(&v13, v6, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputKeyboard.cpp", 0x4Fu, 1);
      }
    }
    result = 1;
  }
  else
  {
    v12 = 72;
    v11 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputKeyboard.cpp";
    v13 = &v7;
    sub_40E2C8(&v7, "Invalid Device pointer, bailing out of update_data()", (int)&v14);
    sub_467834(&v13, v7, v8, v9, v10, v11, v12);
    result = 0;
  }
  return result;
}

//----- (0043B96E) --------------------------------------------------------
char __thiscall set_acquire(int this, int a2)
{
  int v2; // eax@1
  char result; // al@2
  int v4; // ecx@3
  char v5; // [sp-18h] [bp-1Ch]@2
  const CHAR *v6; // [sp-14h] [bp-18h]@2
  int v7; // [sp-10h] [bp-14h]@2
  int v8; // [sp-Ch] [bp-10h]@2
  const char *v9; // [sp-8h] [bp-Ch]@2
  int v10; // [sp-4h] [bp-8h]@2
  int v11; // [sp+0h] [bp-4h]@1
  char *v12; // [sp+Ch] [bp+8h]@2

  v11 = this;
  v2 = *(_DWORD *)(this + 8);
  if ( v2 )
  {
    v4 = *(_DWORD *)v2;
    v10 = v2;
    if ( (_BYTE)a2 )
      (*(void (__stdcall **)(int))(v4 + 28))(v10);
    else
      (*(void (__stdcall **)(int))(v4 + 32))(v10);
    result = 1;
  }
  else
  {
    v10 = 89;
    v9 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputKeyboard.cpp";
    v12 = &v5;
    sub_40E2C8(&v5, "Invalid Device pointer, bailing out of set_acquire()", (int)((char *)&a2 + 3));
    sub_467834(&v11, v5, v6, v7, v8, v9, v10);
    result = 0;
  }
  return result;
}

//----- (0043B9B9) --------------------------------------------------------
signed int __stdcall sub_43B9B9(int a1, int a2)
{
  signed int result; // eax@2

  if ( *(_BYTE *)(a1 + 36) & 3 )
  {
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(a1 + 4);
    *(_DWORD *)(a2 + 16) = *(_DWORD *)(a1 + 8);
    *(_DWORD *)(a2 + 20) = *(_DWORD *)(a1 + 12);
    *(_DWORD *)(a2 + 24) = *(_DWORD *)(a1 + 16);
    *(_BYTE *)(a2 + 28) = 1;
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0043B9FF) --------------------------------------------------------
int __thiscall sub_43B9FF(int this)
{
  int v1; // esi@1
  int v3; // eax@5
  signed int v4; // [sp-18h] [bp-24h]@3
  int v5; // [sp-14h] [bp-20h]@3
  int v6; // [sp-10h] [bp-1Ch]@3
  const char *v7; // [sp-Ch] [bp-18h]@3
  unsigned int v8; // [sp-8h] [bp-14h]@3
  int v9; // [sp-4h] [bp-10h]@3
  char v10; // [sp+8h] [bp-4h]@5

  v1 = this;
  *(_DWORD *)(this + 8) = 0;
  *(_BYTE *)(this + 28) = 0;
  *(_DWORD *)(this + 40) = 0;
  *(_DWORD *)this = 5080584;
  if ( dword_F79D7C != 2 || dword_F79D70 != 4 )
  {
    v9 = 1;
    v8 = 30;
    v7 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputMouse.cpp";
    v6 = 0;
    v5 = this + 4;
    v4 = 1280;
  }
  else
  {
    v9 = 1;
    v8 = 28;
    v7 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputMouse.cpp";
    v6 = 0;
    v5 = this + 4;
    v4 = 768;
  }
  compile_error;//v3 = DirectInputCreateA(hInstance, v4, v5, v6);
  CheckHRESULT(&v10, v3, v7, v8, v9);
  sub_43BACE(v1);
  sub_43BB18(v1);
  *(_DWORD *)(v1 + 32) = 0;
  *(_DWORD *)(v1 + 36) = 0;
  return v1;
}

//----- (0043BA9C) --------------------------------------------------------
int __thiscall sub_43BA9C(int this)
{
  int v1; // eax@1
  int v2; // esi@1
  int result; // eax@3

  v2 = this;
  v1 = *(_DWORD *)(this + 8);
  *(_DWORD *)this = 5080584;
  if ( v1 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v1 + 32))(v1);
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v2 + 8) + 8))(*(_DWORD *)(v2 + 8));
    *(_DWORD *)(v2 + 8) = 0;
  }
  result = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(v2 + 4) + 8))(*(_DWORD *)(v2 + 4));
  *(_DWORD *)(v2 + 4) = 0;
  return result;
}

//----- (0043BACE) --------------------------------------------------------
void *__thiscall sub_43BACE(int this)
{
  void *result; // eax@1
  int v2; // esi@1
  int v3; // eax@1
  int v4; // [sp+4h] [bp-4h]@1

  v2 = this;
  v3 = (*(int (__stdcall **)(_DWORD, signed int, signed int (__stdcall *)(int, int), int, signed int))(**(_DWORD **)(this + 4) + 16))(
         *(_DWORD *)(this + 4),
         2,
         sub_43BC61,
         this,
         1);
  result = CheckHRESULT(&v4, v3, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputMouse.cpp", 0x39u, 1);
  if ( !*(_BYTE *)(v2 + 28) )
  {
    v4 = (int)"Error: No mouse found";
    _CxxThrowException(&v4, 5094804);
  }
  return result;
}

//----- (0043BB18) --------------------------------------------------------
int __thiscall sub_43BB18(int this)
{
  int v2; // esi@1
  int v3; // eax@1
  int v4; // ST1C_4@1
  int v5; // eax@1
  int v6; // eax@1
  char v7; // [sp+8h] [bp-4h]@1

  v2 = this + 8;
  v3 = (*(int (__stdcall **)(_DWORD, int, int, _DWORD, _DWORD))(**(_DWORD **)(this + 4) + 12))(
         *(_DWORD *)(this + 4),
         this + 12,
         this + 8,
         0,
         "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputMouse.cpp");
  CheckHRESULT(&v7, v3, (const char *)0x40, 1u, v4);
  v5 = (*(int (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)v2 + 44))(*(_DWORD *)v2, dword_4C9920);
  CheckHRESULT(&v7, v5, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputMouse.cpp", 0x41u, 1);
  v6 = (*(int (__stdcall **)(_DWORD, HWND, signed int))(**(_DWORD **)v2 + 52))(*(_DWORD *)v2, hWnd_global, 6);
  CheckHRESULT(&v7, v6, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputMouse.cpp", 0x42u, 1);
  return (*(int (**)(void))(**(_DWORD **)v2 + 28))();
}

//----- (0043BB89) --------------------------------------------------------
char __thiscall sub_43BB89(int this)
{
  int v1; // eax@1
  int v2; // esi@1
  char result; // al@2
  int v4; // eax@5
  int v5; // eax@6
  int v6; // edx@6
  int v7; // ecx@6
  signed int v8; // eax@12
  signed int v9; // edx@12
  int v10; // ecx@12
  int v11; // ecx@12
  int v12; // [sp+4h] [bp-14h]@3
  int v13; // [sp+8h] [bp-10h]@12
  char v14; // [sp+10h] [bp-8h]@18
  char v15; // [sp+11h] [bp-7h]@20
  char v16; // [sp+12h] [bp-6h]@22
  char v17; // [sp+13h] [bp-5h]@24
  char v18; // [sp+14h] [bp-4h]@5

  v2 = this;
  v1 = *(_DWORD *)(this + 8);
  if ( v1 )
  {
    if ( (*(int (__stdcall **)(int, signed int, int *))(*(_DWORD *)v1 + 36))(v1, 16, &v12) == -2147024866 )
    {
      if ( !(*(int (__stdcall **)(_DWORD))(**(_DWORD **)(v2 + 8) + 28))(*(_DWORD *)(v2 + 8)) )
      {
        v4 = (*(int (__stdcall **)(_DWORD, signed int, int *))(**(_DWORD **)(v2 + 8) + 36))(
               *(_DWORD *)(v2 + 8),
               16,
               &v12);
        CheckHRESULT(&v18, v4, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputMouse.cpp", 0x50u, 1);
      }
    }
    v7 = *(_DWORD *)(v2 + 32) + v12;
    v5 = 640;
    v6 = *(_DWORD *)(v2 + 32) + v12;
    if ( v7 >= 640 )
      v6 = 640;
    if ( v6 >= 0 )
    {
      if ( v7 < 640 )
        v5 = *(_DWORD *)(v2 + 32) + v12;
    }
    else
    {
      v5 = 0;
    }
    v11 = v13;
    *(_DWORD *)(v2 + 32) = v5;
    v10 = *(_DWORD *)(v2 + 36) + v11;
    v8 = 480;
    v9 = v10;
    if ( v10 >= 480 )
      v9 = 480;
    if ( v9 >= 0 )
    {
      if ( v10 < 480 )
        v8 = v10;
    }
    else
    {
      v8 = 0;
    }
    *(_DWORD *)(v2 + 40) = 0;
    *(_DWORD *)(v2 + 36) = v8;
    if ( v14 & 0x80 )
      *(_DWORD *)(v2 + 40) = 1;
    if ( v15 & 0x80 )
      *(_DWORD *)(v2 + 40) |= 2;
    if ( v16 & 0x80 )
      *(_DWORD *)(v2 + 40) |= 4u;
    if ( v17 & 0x80 )
      *(_DWORD *)(v2 + 40) |= 8u;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0043BC61) --------------------------------------------------------
signed int __stdcall sub_43BC61(int a1, int a2)
{
  signed int result; // eax@2

  if ( *(_BYTE *)(a1 + 36) & 2 )
  {
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(a1 + 4);
    *(_DWORD *)(a2 + 16) = *(_DWORD *)(a1 + 8);
    *(_DWORD *)(a2 + 20) = *(_DWORD *)(a1 + 12);
    *(_DWORD *)(a2 + 24) = *(_DWORD *)(a1 + 16);
    *(_BYTE *)(a2 + 28) = 1;
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0043BCA7) --------------------------------------------------------
int __cdecl GameUI_DrawPaperdoll()
{
  signed int v0; // eax@7
  signed int v1; // ebx@7
  int v2; // edi@7
  int v3; // ebx@10
  char v4; // cl@12
  int v5; // edi@12
  char v6; // al@16
  int v7; // ebx@16
  int v8; // edi@16
  int v9; // ebx@16
  signed int v10; // edi@21
  int v12; // ebp@29
  _UNKNOWN *v14; // edi@65
  signed int v15; // ebx@66
  int v16; // eax@67
  int v17; // ecx@67
  int v18; // ebx@68
  _UNKNOWN *v19; // ebp@73
  int v20; // edi@73
  int v21; // eax@76
  int v22; // ecx@76
  int v23; // eax@78
  int v24; // ecx@78
  int v25; // ebx@79
  int v26; // eax@80
  int v27; // ecx@80
  int result; // eax@83
  int v29; // [sp+10h] [bp-28h]@5
  signed int v30; // [sp+10h] [bp-28h]@68
  signed int v31; // [sp+10h] [bp-28h]@75
  signed int v32; // [sp+10h] [bp-28h]@77
  int v33; // [sp+10h] [bp-28h]@79
  _UNKNOWN *v34; // [sp+14h] [bp-24h]@65
  int v35; // [sp+14h] [bp-24h]@75
  int v36; // [sp+14h] [bp-24h]@77
  signed int v37; // [sp+14h] [bp-24h]@79
  int v38; // [sp+18h] [bp-20h]@66
  int v39; // [sp+18h] [bp-20h]@73
  _UNKNOWN *v40; // [sp+1Ch] [bp-1Ch]@73
  int v41; // [sp+20h] [bp-18h]@6
  int v42; // [sp+20h] [bp-18h]@73
  CHAR Str1; // [sp+24h] [bp-14h]@12
 int i;

  dword_5118CC = class17_LoadTexture(pClass17_Icons_LOD, "MAGNIF-B", 2);
  if (pParty_global->uAlignment == 0 || pParty_global->uAlignment == 1 || pParty_global->uAlignment == 2 )
    dword_5118D8 = class17_LoadTexture(pClass17_Icons_LOD, "BACKDOLL", 2);
  dword_507B04 = dword_5079E4;
  v29 = 0;
  dword_5118DC = class17_LoadTexture(pClass17_Icons_LOD, "BACKHAND", 2);
  dword_5118C8 = dword_506438;
  do
  {
    v41 = v29 + 1;
    if ( sub_43EE77(v29 + 1) )
    {
      v2 = 4 * v29;
      v1 = GetRaceByFace(pPlayers[v29]);
      v0 = Player_GetVoiceSex(pPlayers[v29]);
      if ( v1 && v1 != 1 && v1 != 2 )
        v3 = (v0 != 0) + 3;
      else
        v3 = (v0 != 0) + 1;
      wsprintfA(&Str1, "pc23v%dBod", v3);
      *(int *)((char *)dword_51127C + v2) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      wsprintfA(&Str1, "pc23v%dlad", v3);
      *(int *)((char *)dword_5115D0 + v2) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      wsprintfA(&Str1, "pc23v%dlau", v3);
      *(int *)((char *)dword_5115C0 + v2) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      wsprintfA(&Str1, "pc23v%drh", v3);
      *(int *)((char *)dword_51124C + v2) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      wsprintfA(&Str1, "pc23v%dlh", v3);
      *(int *)((char *)dword_51126C + v2) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      wsprintfA(&Str1, "pc23v%dlhu", v3);
      *(int *)((char *)dword_51125C + v2) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      v5 = *(int *)((char *)pPlayers + v2);
      v4 = *(_BYTE *)(v5 + 186);
      if ( v4 == 12 || v4 == 13 )
        dword_511208[v4] = 0;
      dword_5115E0[*(_BYTE *)(v5 + 186)] = 0;
      byte_5111B9[v29] = 1;
    }
    else
    {
      v8 = 4 * v29;
      dword_51127C[v29] = class17_LoadTexture(pClass17_Icons_LOD, (&off_4ECD68)[4 * *(_BYTE *)(pPlayers[v29] + 186)], 2);
      dword_5115D0[v29] = class17_LoadTexture(pClass17_Icons_LOD, (&off_4ECC98)[4 * *(_BYTE *)(pPlayers[v29] + 186)], 2);
      dword_5115C0[v29] = class17_LoadTexture(pClass17_Icons_LOD, (&off_4ECD00)[4 * *(_BYTE *)(pPlayers[v29] + 186)], 2);
      dword_51124C[v29] = class17_LoadTexture(pClass17_Icons_LOD, (&off_4ECDD0)[4 * *(_BYTE *)(pPlayers[v29] + 186)], 2);
      dword_51126C[v29] = class17_LoadTexture(pClass17_Icons_LOD, (&off_4ECE38)[4 * *(_BYTE *)(pPlayers[v29] + 186)], 2);
      v9 = pPlayers[v29];
      dword_51125C[v29] = class17_LoadTexture(pClass17_Icons_LOD, (&off_4ECEA0)[4 * *(_BYTE *)(pPlayers[v29] + 186)], 2);
      v7 = v9 + 186;
      v6 = *(_BYTE *)v7;
      if ( *(_BYTE *)v7 == 12 || v6 == 13 )
      {
        wsprintfA(&Str1, "pc%02dbrd", v6 + 1);
        v7 = *(int *)((char *)pPlayers + v8) + 186;
        dword_511208[*(_BYTE *)v7] = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      }
      wsprintfA(&Str1, "item281pc%02d", *(_BYTE *)v7 + 1);
      dword_5115E0[*(_BYTE *)(*(int *)((char *)pPlayers + v8) + 186)] = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      byte_5111B9[v29] = 0;
    }
    ++v29;
  }
  while ( v41 < 4 );
  dword_507674 = class17_LoadTexture(pClass17_Icons_LOD, "ar_up_up", 2);
  dword_507670 = class17_LoadTexture(pClass17_Icons_LOD, "ar_up_dn", 2);
  dword_50766C = class17_LoadTexture(pClass17_Icons_LOD, "ar_dn_up", 2);
  dword_507668 = class17_LoadTexture(pClass17_Icons_LOD, "ar_dn_dn", 2);
  dword_51122C = class17_LoadTexture(pClass17_Icons_LOD, "ib-cd1-d", 2);
  dword_511224 = class17_LoadTexture(pClass17_Icons_LOD, "ib-cd2-d", 2);
  dword_51121C = class17_LoadTexture(pClass17_Icons_LOD, "ib-cd3-d", 2);
  dword_511214 = class17_LoadTexture(pClass17_Icons_LOD, "ib-cd4-d", 2);
  dword_51120C = class17_LoadTexture(pClass17_Icons_LOD, "ib-cd5-d", 2);
  v10 = 0;
  do
  {
    byte_5111C0[v10] = 0;
    if ( dword_AD470C != v10 + 66 )
    {
     i = 0;
      while ( !sub_43EE15(v10 + 66, &pParty_global->pPlayers[i], 0) )
      {
        if ( i >= 4)
          goto LABEL_28;
      }
    }
    byte_5111C0[v10] = 1;
LABEL_28:
    ++v10;
  }
  while ( v10 < 54 );
  *(_DWORD *)&byte_5111F6 = 0;
  *((_DWORD *)&byte_5111F6 + 1) = 0;
  *((_DWORD *)&byte_5111F6 + 2) = 0;
  *((_DWORD *)&byte_5111F6 + 3) = 0;
  *((_DWORD *)&byte_5111F6 + 4) = 0;

  v12 = 1;
  for (i = 0; i < 4; ++i)
  {
    if ( sub_43EE15(516, &pParty_global->pPlayers[i], 1) )
      byte_5111F8 = 1;
    if ( sub_43EE15(504, &pParty_global->pPlayers[i], 1) )
      byte_5111F6 = 1;
    if ( sub_43EE15(505, &pParty_global->pPlayers[i], 1) )
      byte_5111F7 = 1;
    if ( sub_43EE15(533, &pParty_global->pPlayers[i], 1) )
      byte_511206 = 1;
    if ( sub_43EE15(512, &pParty_global->pPlayers[i], 1) )
      byte_5111F9 = 1;
    if ( sub_43EE15(521, &pParty_global->pPlayers[i], 1) )
      byte_5111FA = 1;
    if ( sub_43EE15(522, &pParty_global->pPlayers[i], 1) )
      byte_5111FB = 1;
    if ( sub_43EE15(523, &pParty_global->pPlayers[i], 1) )
      byte_5111FC = 1;
    if ( sub_43EE15(532, &pParty_global->pPlayers[i], 1) )
      byte_5111FD = 1;
    if ( sub_43EE15(544, &pParty_global->pPlayers[i], 1) )
      byte_5111FE = 1;
    if ( sub_43EE15(524, &pParty_global->pPlayers[i], 1) )
      byte_5111FF = 1;
    if ( sub_43EE15(535, &pParty_global->pPlayers[i], 1) )
      byte_511200 = 1;
    if ( sub_43EE15(525, &pParty_global->pPlayers[i], 1) )
      byte_511201 = 1;
    if ( sub_43EE15(530, &pParty_global->pPlayers[i], 1) )
      byte_511202 = 1;
    if ( sub_43EE15(547, &pParty_global->pPlayers[i], 1) )
      byte_511203 = 1;
    if ( sub_43EE15(548, &pParty_global->pPlayers[i], 1) )
      byte_511204 = 1;
    if ( sub_43EE15(550, &pParty_global->pPlayers[i], 1) )
      byte_511205 = 1;
  }

  v14 = &unk_5116C4;
  v34 = &unk_511730;
  do
  {
    v15 = 0;
    v38 = (int)((char *)v34 - 24);
    do
    {
      sub_43C91D((int)&Str1, v15 + 100, v12, 0);
      v16 = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      ++v15;
      v17 = v38;
      v38 += 4;
      *(_DWORD *)v17 = v16;
    }
    while ( v15 < 5 );
    sub_43C91D((int)&Str1, 535, v12, 0);
    v30 = 0;
    v18 = (int)((char *)v14 - 44);
    *(_DWORD *)v34 = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
    do
    {
      sub_43C91D((int)&Str1, v30++ + 89, v12, 0);
      *(_DWORD *)v18 = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      v18 += 4;
    }
    while ( v30 < 11 );
    sub_43C91D((int)&Str1, 521, v12, 0);
    *(_DWORD *)v14 = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
    sub_43C91D((int)&Str1, 522, v12, 0);
    *((_DWORD *)v14 + 1) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
    sub_43C91D((int)&Str1, 523, v12, 0);
    *((_DWORD *)v14 + 2) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
    sub_43C91D((int)&Str1, 532, v12, 0);
    *((_DWORD *)v14 + 3) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
    sub_43C91D((int)&Str1, 544, v12, 0);
    *((_DWORD *)v14 + 4) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
    if ( sub_43ED6F((void *)1) )
      dword_511234 = class17_LoadTexture(pClass17_Icons_LOD, "item092v3", 2);
    v34 = (char *)v34 + 28;
    ++v12;
    v14 = (char *)v14 + 64;
  }
  while ( v12 - 1 < 2 );
  v42 = 0;
  v20 = 1;
  v39 = (int)dword_51164C;
  v19 = &unk_51132C;
  v40 = &unk_51172C;
  do
  {
    if ( sub_43EDB9((void *)(v20 - 1)) )
    {
      sub_43C91D((int)&Str1, 524, v20, 0);
      v31 = 66;
      *(_DWORD *)v40 = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      v35 = (int)((char *)v19 - 152);
      do
      {
        sub_43C91D((int)&Str1, v31, v20, 0);
        *(_DWORD *)(v35 - 4) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
        sub_43C91D((int)&Str1, v31, v20, 1);
        *(_DWORD *)v35 = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
        sub_43C91D((int)&Str1, v31, v20, 2);
        v21 = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
        v22 = v35;
        v35 += 12;
        ++v31;
        *(_DWORD *)(v22 + 4) = v21;
      }
      while ( v31 - 66 < 13 );
      sub_43C91D((int)&Str1, 516, v20, 0);
      *(_DWORD *)v19 = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 516, v20, 1);
      *((_DWORD *)v19 + 1) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 516, v20, 2);
      *((_DWORD *)v19 + 2) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 505, v20, 0);
      *((_DWORD *)v19 + 3) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 505, v20, 1);
      *((_DWORD *)v19 + 4) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 505, v20, 2);
      *((_DWORD *)v19 + 5) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 504, v20, 0);
      *((_DWORD *)v19 + 6) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 504, v20, 1);
      *((_DWORD *)v19 + 7) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 504, v20, 2);
      *((_DWORD *)v19 + 8) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 533, v20, 0);
      *((_DWORD *)v19 + 9) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 533, v20, 1);
      *((_DWORD *)v19 + 10) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 533, v20, 2);
      *((_DWORD *)v19 + 11) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      v32 = 0;
      v36 = v39 - 20;
      do
      {
        sub_43C91D((int)&Str1, v32 + 115, v20, 0);
        v23 = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
        ++v32;
        v24 = v36;
        v36 += 4;
        *(_DWORD *)v24 = v23;
      }
      while ( v32 < 5 );
      sub_43C91D((int)&Str1, 512, v20, 0);
      v25 = v42;
      v37 = 105;
      v33 = v42;
      *(_DWORD *)v39 = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      do
      {
        sub_43C91D((int)&Str1, v37, v20, 0);
        *(int *)((char *)dword_511828 + v33) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
        sub_43C91D((int)&Str1, v37, v20, 1);
        v26 = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
        v27 = v33;
        v33 += 4;
        ++v37;
        *(int *)((char *)dword_511788 + v27) = v26;
      }
      while ( v37 - 105 < 5 );
      sub_43C91D((int)&Str1, 525, v20, 0);
      *(int *)((char *)&dword_51183C + v42) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 530, v20, 0);
      *(int *)((char *)&dword_511840 + v42) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 547, v20, 0);
      *(int *)((char *)&dword_511844 + v42) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 548, v20, 0);
      *(int *)((char *)&dword_511848 + v42) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 550, v20, 0);
      *(int *)((char *)&dword_51184C + v42) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 525, v20, 1);
      *(int *)((char *)&dword_51179C + v42) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 530, v20, 1);
      *(int *)((char *)&dword_5117A0 + v42) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 547, v20, 1);
      *(int *)((char *)&dword_5117A4 + v42) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 548, v20, 1);
      *(int *)((char *)&dword_5117A8 + v42) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      sub_43C91D((int)&Str1, 550, v20, 1);
      *(int *)((char *)&dword_5117AC + v42) = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
    }
    else
    {
      v25 = v42;
    }
    v40 = (char *)v40 + 28;
    v39 += 24;
    v19 = (char *)v19 + 204;
    ++v20;
    result = v20 - 1;
    v42 = v25 + 40;
  }
  while ( v20 - 1 < 4 );
  return result;
}

//----- (0043C91D) --------------------------------------------------------
int __fastcall sub_43C91D(int a1, signed int a2, int a3, int a4)
{
  int result; // eax@2
  char v5; // zf@3
  const char *v6; // [sp-Ch] [bp-18h]@88
  signed int v7; // [sp-8h] [bp-14h]@61
  int v8; // [sp-4h] [bp-10h]@61
  signed int v9; // [sp-4h] [bp-10h]@69

  if ( a2 > 500 )
  {
    result = a2 - 504;
    switch ( a2 )
    {
      case 516:
        v5 = byte_5111F8 == 0;
        goto LABEL_21;
      case 505:
        v5 = byte_5111F7 == 0;
        goto LABEL_21;
      case 504:
        v5 = byte_5111F6 == 0;
        goto LABEL_21;
      case 533:
        v5 = byte_511206 == 0;
        goto LABEL_21;
      case 512:
        v5 = byte_5111F9 == 0;
        goto LABEL_21;
      case 521:
        v5 = byte_5111FA == 0;
        goto LABEL_21;
      case 522:
        v5 = byte_5111FB == 0;
        goto LABEL_21;
      case 523:
        v5 = byte_5111FC == 0;
        goto LABEL_21;
      case 532:
        v5 = byte_5111FD == 0;
        goto LABEL_21;
      case 544:
        v5 = byte_5111FE == 0;
        goto LABEL_21;
      case 524:
        v5 = byte_5111FF == 0;
        goto LABEL_21;
      case 535:
        v5 = byte_511200 == 0;
        goto LABEL_21;
      case 525:
        v5 = byte_511201 == 0;
        goto LABEL_21;
      case 530:
        v5 = byte_511202 == 0;
        goto LABEL_21;
      case 547:
        v5 = byte_511203 == 0;
        goto LABEL_21;
      case 548:
        v5 = byte_511204 == 0;
        goto LABEL_21;
      case 550:
        v5 = byte_511205 == 0;
        goto LABEL_21;
      default:
        return result;
    }
    return result;
  }
  v5 = byte_51117E[a2] == 0;
LABEL_21:
  if ( !v5 )
  {
    result = 516;
    if ( a2 < 66 || a2 > 78 )
    {
      if ( a2 == 516 )
        goto LABEL_79;
      if ( a2 != 504 && a2 != 505 && a2 != 533 )
      {
        if ( (a2 < 100 || a2 > 104) && a2 != 524 && a2 != 535 )
        {
          if ( a2 >= 115 && a2 <= 119 || a2 == 512 )
          {
            if ( a2 == 512 )
              a2 = 312;
            goto LABEL_87;
          }
          if ( (a2 < 89 || a2 > 99) && a2 != 521 && a2 != 522 && a2 != 523 && a2 != 532 && a2 != 544 )
          {
            result = 525;
            if ( (a2 < 105 || a2 > 109) && a2 != 525 && a2 != 530 && a2 != 547 && a2 != 548 && a2 != 550 )
              return result;
            switch ( a2 )
            {
              case 525:
                a2 = 325;
                break;
              case 530:
                a2 = 330;
                break;
              case 547:
                a2 = 347;
                break;
              case 548:
                a2 = 348;
                break;
              case 550:
                a2 = 350;
                break;
            }
            v8 = a3;
            v7 = a2;
            if ( !a4 )
              goto LABEL_88;
LABEL_91:
            v6 = "item%3.3dv%da1";
            return sprintfex(a1, v6, v7, v8);
          }
          if ( a2 == 521 )
          {
            a2 = 239;
            goto LABEL_87;
          }
          if ( a2 == 522 )
          {
            a2 = 240;
            goto LABEL_87;
          }
          if ( a2 == 523 )
          {
            a2 = 241;
            goto LABEL_87;
          }
          if ( a2 != 532 )
          {
            if ( a2 == 544 )
              a2 = 344;
            goto LABEL_87;
          }
          v9 = 93;
          goto LABEL_70;
        }
        if ( a2 == 524 )
        {
          a2 = 324;
          goto LABEL_87;
        }
        if ( a2 == 535 )
        {
          v9 = 104;
LABEL_70:
          a2 = v9;
        }
LABEL_87:
        v8 = a3;
        v7 = a2;
LABEL_88:
        v6 = "item%3.3dv%d";
        return sprintfex(a1, v6, v7, v8);
      }
    }
    if ( a2 != 516 )
    {
      switch ( a2 )
      {
        case 504:
          a2 = 235;
          break;
        case 505:
          a2 = 236;
          break;
        case 533:
          a2 = 73;
          break;
      }
LABEL_86:
      if ( a4 )
      {
        if ( a4 != 1 )
        {
          if ( a4 != 2 )
            return result;
          v8 = a3;
          v7 = a2;
          v6 = "item%3.3dv%da2";
          return sprintfex(a1, v6, v7, v8);
        }
        v8 = a3;
        v7 = a2;
        goto LABEL_91;
      }
      goto LABEL_87;
    }
LABEL_79:
    a2 = 234;
    goto LABEL_86;
  }
  return result;
}

//----- (0043CC7C) --------------------------------------------------------
void __fastcall sub_43CC7C(int a1)
{
  signed int v1; // eax@1
  int v2; // ebx@1
  signed int v3; // edi@1
  int v4; // esi@1
  bool v5; // edi@4
  int v6; // ecx@9
  int v7; // ecx@10
  int v8; // eax@14
  int v9; // eax@15
  int v10; // edi@15
  int v11; // eax@15
  bool v12; // edx@15
  int v13; // ecx@15
  int v14; // ecx@18
  int v15; // ebx@18
  int v16; // ebp@27
  unsigned __int8 v17; // zf@27
  unsigned __int8 v18; // sf@27
  double v19; // st7@29
  int v20; // eax@30
  int v21; // edi@30
  int v22; // edi@31
  int v23; // eax@37
  int v24; // eax@38
  int v25; // ebx@38
  int v26; // edi@38
  int v27; // eax@38
  int v28; // ecx@42
  unsigned __int8 v29; // zf@49
  unsigned __int8 v30; // sf@49
  int v31; // edi@51
  double v32; // st7@51
  char v33; // zf@54
  int v34; // eax@54
  int v35; // eax@59
  int v36; // edx@60
  int v37; // eax@65
  int v38; // eax@74
  int v39; // ecx@74
  int v40; // ebx@74
  int v41; // eax@74
  int v42; // ecx@78
  int v43; // edi@85
  unsigned __int8 v44; // zf@85
  unsigned __int8 v45; // sf@85
  double v46; // st7@87
  int v47; // edi@88
  int v48; // edi@89
  int v49; // eax@93
  int v50; // edx@94
  int v51; // eax@98
  int v52; // eax@106
  int v53; // ecx@106
  int v54; // ebx@106
  int v55; // eax@106
  int v56; // ecx@110
  int v57; // edi@117
  unsigned __int8 v58; // zf@117
  unsigned __int8 v59; // sf@117
  double v60; // st7@119
  int v61; // edi@120
  int v62; // edi@121
  char v63; // zf@122
  int v64; // eax@122
  int v65; // eax@127
  int v66; // ecx@128
  int v67; // edi@128
  int v68; // ebx@129
  int v69; // ecx@132
  int v70; // eax@134
  int v71; // ecx@136
  int v72; // edi@145
  unsigned __int8 v73; // zf@145
  unsigned __int8 v74; // sf@145
  double v75; // st7@147
  int v76; // eax@148
  int v77; // edi@148
  int v78; // edi@149
  int v79; // edx@155
  int v80; // ebx@155
  int v81; // edx@156
  int v82; // eax@160
  int v83; // edi@161
  int v84; // edx@163
  int v85; // ecx@168
  int v86; // ebx@170
  int v87; // ecx@172
  int v88; // edi@181
  unsigned __int8 v89; // zf@181
  unsigned __int8 v90; // sf@181
  double v91; // st7@183
  int v92; // eax@184
  int v93; // edi@184
  int v94; // edi@185
  int v95; // eax@192
  int v96; // eax@193
  int v97; // eax@197
  int v98; // eax@197
  int v99; // ecx@197
  int v100; // eax@197
  int v101; // eax@198
  int v102; // eax@199
  int v103; // edi@201
  int v104; // ebx@213
  int v105; // edi@213
  int v106; // eax@214
  int v107; // ebx@214
  int v108; // edi@214
  int v109; // ecx@217
  int v110; // edi@226
  unsigned __int8 v111; // zf@226
  unsigned __int8 v112; // sf@226
  double v113; // st7@228
  int v114; // eax@229
  int v115; // ecx@229
  int v116; // edi@229
  char v117; // zf@229
  int v118; // edi@230
  int v119; // edi@236
  int v120; // eax@237
  int v121; // edx@237
  int v122; // ecx@237
  int v123; // edx@238
  int v124; // edx@239
  int v125; // edx@240
  unsigned __int8 v126; // zf@246
  unsigned __int8 v127; // sf@246
  int v128; // edx@250
  int v129; // edi@250
  int v130; // eax@259
  int v131; // eax@260
  int v132; // eax@260
  int v133; // eax@265
  int v134; // ebx@274
  int v135; // edi@274
  int v136; // eax@274
  int v137; // ecx@275
  unsigned __int8 v138; // zf@284
  unsigned __int8 v139; // sf@284
  double v140; // st7@286
  int v141; // eax@287
  int v142; // edi@287
  int v143; // edi@288
  int v144; // edi@295
  int v145; // ebx@297
  int v146; // edi@298
  int v147; // ecx@303
  int v148; // eax@312
  int v149; // ebx@314
  int v150; // ecx@316
  int v151; // edi@325
  unsigned __int8 v152; // zf@325
  unsigned __int8 v153; // sf@325
  double v154; // st7@327
  int v155; // eax@328
  int v156; // edi@328
  int v157; // edi@329
  int v158; // eax@335
  int v159; // eax@336
  int v160; // eax@336
  int v161; // edx@336
  int v162; // ecx@339
  int v163; // ebx@339
  int v164; // edi@348
  unsigned __int8 v165; // zf@348
  unsigned __int8 v166; // sf@348
  double v167; // st7@350
  int v168; // eax@351
  int v169; // edi@351
  int v170; // edi@352
  int v171; // eax@358
  int v172; // eax@359
  int v173; // edx@359
  int v174; // ecx@359
  int v175; // eax@359
  int v176; // ebx@362
  int v177; // ecx@363
  int v178; // ecx@364
  int v179; // eax@370
  int v180; // edi@370
  int v181; // eax@370
  int v182; // ecx@374
  int v183; // ebp@381
  unsigned __int8 v184; // zf@381
  unsigned __int8 v185; // sf@381
  double v186; // st7@383
  int v187; // edi@385
  char v188; // zf@386
  int v189; // eax@386
  int v190; // eax@393
  int v191; // eax@394
  int v192; // [sp-Ch] [bp-58h]@230
  int v193; // [sp-Ch] [bp-58h]@233
  int v194; // [sp-Ch] [bp-58h]@235
  const char *v195; // [sp-8h] [bp-54h]@16
  const char *v196; // [sp-8h] [bp-54h]@23
  const char *v197; // [sp-8h] [bp-54h]@43
  const char *v198; // [sp-8h] [bp-54h]@79
  const char *v199; // [sp-8h] [bp-54h]@111
  const char *v200; // [sp-8h] [bp-54h]@141
  const char *v201; // [sp-8h] [bp-54h]@177
  const char *v202; // [sp-8h] [bp-54h]@222
  int v203; // [sp-8h] [bp-54h]@228
  int v204; // [sp-8h] [bp-54h]@230
  int v205; // [sp-8h] [bp-54h]@233
  int v206; // [sp-8h] [bp-54h]@235
  const char *v207; // [sp-8h] [bp-54h]@242
  const char *v208; // [sp-8h] [bp-54h]@280
  const char *v209; // [sp-8h] [bp-54h]@321
  const char *v210; // [sp-8h] [bp-54h]@337
  const char *v211; // [sp-8h] [bp-54h]@344
  const char *v212; // [sp-8h] [bp-54h]@375
  signed int v213; // [sp-4h] [bp-50h]@66
  signed int v214; // [sp-4h] [bp-50h]@99
  signed int v215; // [sp-4h] [bp-50h]@202
  int v216; // [sp-4h] [bp-50h]@228
  int v217; // [sp-4h] [bp-50h]@230
  int v218; // [sp-4h] [bp-50h]@233
  int v219; // [sp-4h] [bp-50h]@235
  signed int v220; // [sp-4h] [bp-50h]@266
  signed int v221; // [sp-4h] [bp-50h]@304
  int v222; // [sp+10h] [bp-3Ch]@7
  int v223; // [sp+10h] [bp-3Ch]@15
  int v224; // [sp+10h] [bp-3Ch]@38
  int v225; // [sp+10h] [bp-3Ch]@74
  int v226; // [sp+10h] [bp-3Ch]@106
  int v227; // [sp+10h] [bp-3Ch]@129
  int v228; // [sp+10h] [bp-3Ch]@168
  int v229; // [sp+10h] [bp-3Ch]@216
  int v230; // [sp+10h] [bp-3Ch]@274
  int v231; // [sp+10h] [bp-3Ch]@312
  int v232; // [sp+10h] [bp-3Ch]@336
  int v233; // [sp+10h] [bp-3Ch]@362
  int v234; // [sp+14h] [bp-38h]@7
  int v235; // [sp+14h] [bp-38h]@15
  int v236; // [sp+14h] [bp-38h]@49
  int v237; // [sp+14h] [bp-38h]@74
  int v238; // [sp+14h] [bp-38h]@106
  int v239; // [sp+14h] [bp-38h]@129
  int v240; // [sp+14h] [bp-38h]@168
  int v241; // [sp+14h] [bp-38h]@214
  int v242; // [sp+14h] [bp-38h]@274
  int v243; // [sp+14h] [bp-38h]@284
  int v244; // [sp+14h] [bp-38h]@312
  int v245; // [sp+14h] [bp-38h]@336
  int v246; // [sp+18h] [bp-34h]@1
  int v247; // [sp+1Ch] [bp-30h]@15
  int v248; // [sp+1Ch] [bp-30h]@60
  int v249; // [sp+1Ch] [bp-30h]@94
  int v250; // [sp+1Ch] [bp-30h]@128
  int v251; // [sp+1Ch] [bp-30h]@161
  int v252; // [sp+1Ch] [bp-30h]@213
  char v253; // [sp+1Ch] [bp-30h]@237
  int v254; // [sp+1Ch] [bp-30h]@260
  int v255; // [sp+1Ch] [bp-30h]@298
  int v256; // [sp+1Ch] [bp-30h]@336
  int v257; // [sp+1Ch] [bp-30h]@359
  int v258; // [sp+20h] [bp-2Ch]@15
  int v259; // [sp+20h] [bp-2Ch]@38
  int v260; // [sp+20h] [bp-2Ch]@60
  int v261; // [sp+20h] [bp-2Ch]@94
  int v262; // [sp+20h] [bp-2Ch]@128
  int v263; // [sp+20h] [bp-2Ch]@161
  int v264; // [sp+20h] [bp-2Ch]@197
  int v265; // [sp+20h] [bp-2Ch]@260
  int v266; // [sp+20h] [bp-2Ch]@298
  int v267; // [sp+20h] [bp-2Ch]@336
  bool v268; // [sp+24h] [bp-28h]@6
  int v269; // [sp+28h] [bp-24h]@7
  int v270; // [sp+2Ch] [bp-20h]@38
  int v271; // [sp+2Ch] [bp-20h]@197
  int v272; // [sp+2Ch] [bp-20h]@370
  int v273; // [sp+34h] [bp-18h]@6
  signed int v274; // [sp+34h] [bp-18h]@361
  int v275; // [sp+38h] [bp-14h]@1
  int v276; // [sp+38h] [bp-14h]@9
  signed int v277; // [sp+40h] [bp-Ch]@4
  int v278; // [sp+40h] [bp-Ch]@358
  signed int v279; // [sp+44h] [bp-8h]@1

  v4 = 4 * a1 + 10965188;
  v2 = (int)*(&ptr_A750C4 + a1);
  v275 = a1;
  v246 = (int)*(&ptr_A750C4 + a1);
  class17_LoadTexture(pClass17_Icons_LOD, "sptext01", 2);
  v3 = GetRaceByFace(v2);
  v1 = Player_GetVoiceSex(v2);
  v279 = v1;
  if ( v3 && v3 != 1 && v3 != 2 )
  {
    v277 = 1;
    v5 = (v1 != 0) + 2;
  }
  else
  {
    v277 = 0;
    v5 = v1 != 0;
  }
  v268 = v5;
  v273 = *(_BYTE *)(*(_DWORD *)v4 + 186);
  CD3DRenderer_Reset2DClippingRect(pD3DRenderer);
  CD3DRenderer_DrawIndexedTexture(pD3DRenderer, 467, 0, dword_5118D8 != -1 ? 72 * dword_5118D8 + 7145548 : 0);
  if ( !byte_5111B8[v275] )
  {
    v23 = *(_DWORD *)(v2 + 6480);
    if ( !v23 )
      goto LABEL_59;
    v259 = *(_DWORD *)(v2 + 6480);
    v26 = v246 + 36 * v23 + 496;
    v27 = 48 * *(_DWORD *)v26;
    v25 = dword_4E4C28 + dword_4E4C40[32 * v268] - *(__int16 *)((char *)&word_5D29FC + v27);
    v224 = dword_4E4C2C + dword_4E4C44[32 * v268] - *(__int16 *)((char *)&word_5D29FE + v27);
    v270 = class17_LoadTexture(pClass17_Icons_LOD, *(const char **)(pClass40->pItems[0].pIconName + v27), 2);
    v24 = *(_DWORD *)(v26 + 20);
    if ( !(*(_DWORD *)(v26 + 20) & 0xF0) )
    {
      if ( v24 & 2 )
      {
        v31 = v270 != -1 ? 72 * v270 + 7145548 : 0;
        sub_4A6776(pD3DRenderer, v25, v224, v31);
      }
      else
      {
        v33 = (v24 & 1) == 0;
        v34 = 72 * v270 + 7145548;
        if ( v33 )
        {
          v31 = v270 != -1 ? v34 : 0;
          sub_4A68EF(pD3DRenderer, v25, v224, v270 != -1 ? v34 : 0);
        }
        else
        {
          v31 = v270 != -1 ? v34 : 0;
          CD3DRenderer_DrawTransparentTexture(pD3DRenderer, v25, v224, v270 != -1 ? v34 : 0);
        }
      }
      goto LABEL_57;
    }
    if ( (*(_DWORD *)(v26 + 20) & 0xF0) != 16 )
    {
      if ( (*(_DWORD *)(v26 + 20) & 0xF0) == 32 )
      {
        v197 = "sp28a";
      }
      else
      {
        if ( (*(_DWORD *)(v26 + 20) & 0xF0) != 64 )
        {
          v28 = pClass17_Icons_LOD;
          if ( (*(_DWORD *)(v26 + 20) & 0xF0) == 128 )
          {
            v197 = "sp91a";
LABEL_49:
            v236 = 72 * class17_LoadTexture(v28, v197, 2) + 7145548;
            v29 = dword_50C9A8 == pClass24_global->int_00001C;
            v30 = dword_50C9A8 - pClass24_global->int_00001C < 0;
            dword_50C9A8 -= pClass24_global->int_00001C;
            if ( v30 | v29 )
            {
              dword_50C9A8 = 0;
              *(_BYTE *)(v26 + 20) &= 0xFu;
              dword_50C9A4 = 0;
            }
            v31 = v270 != -1 ? 72 * v270 + 7145548 : 0;
            v32 = (double)GetTickCount() * 0.1000000014901161;
            sub_4A63E6(pD3DRenderer, v25, v224, v31, v236, (signed __int64)v32, 0, 255);
LABEL_57:
            if ( !dword_5118E0 )
              sub_4A612A(pD3DRenderer, v25, v224, v31, v259);
LABEL_59:
            v35 = *(_DWORD *)(v246 + 6496);
            if ( !v35 )
              goto LABEL_93;
            v260 = *(_DWORD *)(v246 + 6496);
            v36 = v246 + 36 * v35 + 496;
            v248 = v36;
            if ( *(_DWORD *)v36 != 525 )
            {
              switch ( *(_DWORD *)v36 )
              {
                case 0x212:
                  v213 = 6;
                  break;
                case 0x223:
                  v213 = 7;
                  break;
                case 0x224:
                  v213 = 8;
                  break;
                default:
                  if ( *(_DWORD *)v36 != 550 )
                  {
                    v37 = *(_DWORD *)v36 - 105;
LABEL_72:
                    if ( v37 < 0 || v37 >= 10 )
                      goto LABEL_93;
                    goto LABEL_74;
                  }
                  v213 = 9;
                  break;
              }
              v37 = v213;
LABEL_74:
              v41 = v37 + 10 * v268;
              v40 = dword_511828[v41];
              v237 = dword_4E4C28 + dword_4E5570[2 * v41];
              v39 = dword_4E4C2C + dword_4E5574[2 * v41];
              v38 = *(_DWORD *)(v36 + 20);
              v225 = v39;
              if ( v38 & 0xF0 )
              {
                if ( (*(_DWORD *)(v36 + 20) & 0xF0) != 16 )
                {
                  if ( (*(_DWORD *)(v36 + 20) & 0xF0) == 32 )
                  {
                    v198 = "sp28a";
                  }
                  else
                  {
                    if ( (*(_DWORD *)(v36 + 20) & 0xF0) != 64 )
                    {
                      v42 = pClass17_Icons_LOD;
                      if ( (*(_DWORD *)(v36 + 20) & 0xF0) == 128 )
                      {
                        v198 = "sp91a";
LABEL_85:
                        v43 = 72 * class17_LoadTexture(v42, v198, 2) + 7145548;
                        v44 = dword_50C9A8 == pClass24_global->int_00001C;
                        v45 = dword_50C9A8 - pClass24_global->int_00001C < 0;
                        dword_50C9A8 -= pClass24_global->int_00001C;
                        if ( v45 | v44 )
                        {
                          dword_50C9A8 = 0;
                          *(_BYTE *)(v248 + 20) &= 0xFu;
                          dword_50C9A4 = 0;
                        }
                        v46 = (double)GetTickCount() * 0.1000000014901161;
                        sub_4A63E6(
                          pD3DRenderer,
                          v237,
                          v225,
                          v40 != -1 ? 72 * v40 + 7145548 : 0,
                          v43,
                          (signed __int64)v46,
                          0,
                          255);
                        goto LABEL_93;
                      }
LABEL_84:
                      v198 = "sptext01";
                      goto LABEL_85;
                    }
                    v198 = "sp30a";
                  }
                  v42 = pClass17_Icons_LOD;
                  goto LABEL_85;
                }
                v42 = pClass17_Icons_LOD;
                goto LABEL_84;
              }
              v47 = v40 + 1;
              if ( v38 & 2 )
              {
                v48 = v47 != 0 ? 72 * v40 + 7145548 : 0;
                sub_4A6776(pD3DRenderer, v237, v39, v48);
              }
              else
              {
                v48 = v47 != 0 ? 72 * v40 + 7145548 : 0;
                CD3DRenderer_DrawTransparentTexture(pD3DRenderer, v237, v39, v48);
              }
              if ( !dword_5118E0 )
                sub_4A612A(pD3DRenderer, v237, v225, v48, v260);
LABEL_93:
              v269 = 4 * v275 - 4;
              CD3DRenderer_DrawTransparentTexture(
                pD3DRenderer,
                dword_4E4C28,
                dword_4E4C2C,
                *(int *)((char *)dword_51127C + v269) != -1 ? 72 * *(int *)((char *)dword_51127C + v269) + 7145548 : 0);
              v49 = *(_DWORD *)(v246 + 6484);
              if ( !v49 )
                goto LABEL_127;
              v261 = *(_DWORD *)(v246 + 6484);
              v50 = v246 + 36 * v49 + 496;
              v249 = v50;
              if ( *(_DWORD *)v50 != 504 )
              {
                if ( *(_DWORD *)v50 == 505 )
                {
                  v214 = 14;
                }
                else
                {
                  if ( *(_DWORD *)v50 == 516 )
                  {
                    v214 = 13;
                  }
                  else
                  {
                    if ( *(_DWORD *)v50 != 533 )
                    {
                      v51 = *(_DWORD *)v50 - 66;
LABEL_104:
                      if ( v51 < 0 || v51 >= 17 )
                        goto LABEL_127;
                      goto LABEL_106;
                    }
                    v214 = 16;
                  }
                }
                v51 = v214;
LABEL_106:
                v55 = 17 * v268 + v51;
                v238 = dword_4E4C28 + dword_4E4E30[2 * v55];
                v53 = dword_4E4C2C + dword_4E4E34[2 * v55];
                v54 = dword_511290[3 * v55];
                v52 = *(_DWORD *)(v50 + 20);
                v226 = v53;
                if ( v52 & 0xF0 )
                {
                  if ( (*(_DWORD *)(v50 + 20) & 0xF0) != 16 )
                  {
                    if ( (*(_DWORD *)(v50 + 20) & 0xF0) == 32 )
                    {
                      v199 = "sp28a";
                    }
                    else
                    {
                      if ( (*(_DWORD *)(v50 + 20) & 0xF0) != 64 )
                      {
                        v56 = pClass17_Icons_LOD;
                        if ( (*(_DWORD *)(v50 + 20) & 0xF0) == 128 )
                        {
                          v199 = "sp91a";
LABEL_117:
                          v57 = 72 * class17_LoadTexture(v56, v199, 2) + 7145548;
                          v58 = dword_50C9A8 == pClass24_global->int_00001C;
                          v59 = dword_50C9A8 - pClass24_global->int_00001C < 0;
                          dword_50C9A8 -= pClass24_global->int_00001C;
                          if ( v59 | v58 )
                          {
                            dword_50C9A8 = 0;
                            *(_BYTE *)(v249 + 20) &= 0xFu;
                            dword_50C9A4 = 0;
                          }
                          v60 = (double)GetTickCount() * 0.1000000014901161;
                          sub_4A63E6(
                            pD3DRenderer,
                            v238,
                            v226,
                            v54 != -1 ? 72 * v54 + 7145548 : 0,
                            v57,
                            (signed __int64)v60,
                            0,
                            255);
                          goto LABEL_127;
                        }
LABEL_116:
                        v199 = "sptext01";
                        goto LABEL_117;
                      }
                      v199 = "sp30a";
                    }
                    v56 = pClass17_Icons_LOD;
                    goto LABEL_117;
                  }
                  v56 = pClass17_Icons_LOD;
                  goto LABEL_116;
                }
                v61 = v54 + 1;
                if ( v52 & 2 )
                {
                  v62 = v61 != 0 ? 72 * v54 + 7145548 : 0;
                  sub_4A6776(pD3DRenderer, v238, v53, v62);
                }
                else
                {
                  v63 = (v52 & 1) == 0;
                  v64 = 72 * v54 + 7145548;
                  if ( v63 )
                  {
                    v62 = v61 != 0 ? v64 : 0;
                    sub_4A68EF(pD3DRenderer, v238, v53, v62);
                  }
                  else
                  {
                    v62 = v61 != 0 ? v64 : 0;
                    CD3DRenderer_DrawTransparentTexture(pD3DRenderer, v238, v53, v62);
                  }
                }
                if ( !dword_5118E0 )
                  sub_4A612A(pD3DRenderer, v238, v226, v62, v261);
LABEL_127:
                v65 = *(_DWORD *)(v246 + 6504);
                if ( !v65 )
                  goto LABEL_155;
                v262 = *(_DWORD *)(v246 + 6504);
                v67 = v246 + 36 * v65 + 496;
                v250 = v67;
                v66 = *(_DWORD *)v67;
                if ( *(_DWORD *)v67 == 529 )
                {
                  v227 = dword_4E4C2C + dword_4E54BC[14 * v268];
                  v239 = dword_4E4C28 + dword_4E54B8[14 * v268];
                  v68 = dword_5115E0[v273];
                }
                else
                {
                  if ( v66 == 512 )
                  {
                    v227 = dword_4E4C2C + dword_4E54C4[14 * v268];
                    v239 = dword_4E4C28 + dword_4E54C0[14 * v268];
                    v68 = dword_51164C[6 * v268];
                  }
                  else
                  {
                    v69 = v66 - 115;
                    if ( v69 < 0 || v69 >= 5 )
                    {
                      v239 = 0;
                      v227 = 0;
                      v68 = dword_511638[6 * v268];
                    }
                    else
                    {
                      v70 = 8 * (v69 + 7 * v268);
                      v227 = dword_4E4C2C + *(int *)((char *)&dword_4E5494 + v70);
                      v239 = dword_4E4C28 + *(int *)((char *)&dword_4E5490 + v70);
                      v68 = dword_511638[v69 + 6 * v268];
                    }
                  }
                }
                v71 = *(_DWORD *)(v67 + 20);
                if ( !(*(_DWORD *)(v67 + 20) & 0xF0) )
                {
                  v77 = v68 + 1;
                  v76 = 72 * v68 + 7145548;
                  if ( v71 & 2 )
                  {
                    v78 = v77 != 0 ? v76 : 0;
                    sub_4A6776(pD3DRenderer, v239, v227, v78);
                  }
                  else
                  {
                    if ( v71 & 1 )
                    {
                      v78 = v77 != 0 ? v76 : 0;
                      CD3DRenderer_DrawTransparentTexture(pD3DRenderer, v239, v227, v78);
                    }
                    else
                    {
                      v78 = v77 != 0 ? v76 : 0;
                      sub_4A68EF(pD3DRenderer, v239, v227, v78);
                    }
                  }
                  if ( !dword_5118E0 )
                    sub_4A612A(pD3DRenderer, v239, v227, v78, v262);
LABEL_155:
                  v80 = v246;
                  v79 = *(_DWORD *)(v246 + 6476);
                  v276 = 8 * v268;
                  if ( !v79
                    || (v81 = 48 * *(_DWORD *)(v246 + 36 * v79 + 496), byte_5D2A00[v81] != 1)
                    && (byte_5D2A00[v81 + 1] != 4 || *(_DWORD *)(v246 + 6472)) )
                    CD3DRenderer_DrawTransparentTexture(
                      pD3DRenderer,
                      dword_4E4C28 + dword_4E5AE0[2 * v268],
                      dword_4E4C2C + dword_4E5AE4[2 * v268],
                      *(int *)((char *)dword_5115D0 + v269) != -1 ? 72 * *(int *)((char *)dword_5115D0 + v269) + 7145548 : 0);
                  v82 = *(_DWORD *)(v246 + 6492);
                  if ( v82 )
                  {
                    v263 = *(_DWORD *)(v246 + 6492);
                    v83 = v246 + 36 * v82 + 496;
                    v251 = v83;
                    if ( *(_DWORD *)v83 == 524 )
                    {
                      v84 = 5;
                    }
                    else
                    {
                      if ( *(_DWORD *)v83 == 535 )
                      {
                        v84 = 6;
                        goto LABEL_168;
                      }
                      v84 = *(_DWORD *)v83 - 100;
                    }
                    if ( v84 >= 0 && v84 < 7 )
                    {
LABEL_168:
                      v85 = 7 * v268 + v84;
                      v240 = dword_4E4C28 + dword_4E57F0[2 * v85];
                      v228 = dword_4E4C2C + dword_4E57F4[2 * v85];
                      if ( v277 != 1 || v84 == 5 )
                        v86 = dword_511718[v85];
                      else
                        v86 = dword_511718[v84 + 7 * (v268 - 2)];
                      v87 = *(_DWORD *)(v246 + 36 * v82 + 516);
                      if ( !(*(_DWORD *)(v246 + 36 * v82 + 516) & 0xF0) )
                      {
                        v93 = v86 + 1;
                        v92 = 72 * v86 + 7145548;
                        if ( v87 & 2 )
                        {
                          v94 = v93 != 0 ? v92 : 0;
                          sub_4A6776(pD3DRenderer, v240, v228, v94);
                        }
                        else
                        {
                          if ( v87 & 1 )
                          {
                            v94 = v93 != 0 ? v92 : 0;
                            CD3DRenderer_DrawTransparentTexture(pD3DRenderer, v240, v228, v94);
                          }
                          else
                          {
                            v94 = v93 != 0 ? v92 : 0;
                            sub_4A68EF(pD3DRenderer, v240, v228, v94);
                          }
                        }
                        if ( !dword_5118E0 )
                          sub_4A612A(pD3DRenderer, v240, v228, v94, v263);
                        goto LABEL_191;
                      }
                      if ( (*(_DWORD *)(v246 + 36 * v82 + 516) & 0xF0) != 16 )
                      {
                        if ( (*(_DWORD *)(v246 + 36 * v82 + 516) & 0xF0) == 32 )
                        {
                          v201 = "sp28a";
                          goto LABEL_181;
                        }
                        if ( (*(_DWORD *)(v246 + 36 * v82 + 516) & 0xF0) == 64 )
                        {
                          v201 = "sp30a";
                          goto LABEL_181;
                        }
                        if ( (*(_DWORD *)(v246 + 36 * v82 + 516) & 0xF0) == 128 )
                        {
                          v201 = "sp91a";
LABEL_181:
                          v88 = 72 * class17_LoadTexture(pClass17_Icons_LOD, v201, 2) + 7145548;
                          v89 = dword_50C9A8 == pClass24_global->int_00001C;
                          v90 = dword_50C9A8 - pClass24_global->int_00001C < 0;
                          dword_50C9A8 -= pClass24_global->int_00001C;
                          if ( v90 | v89 )
                          {
                            dword_50C9A8 = 0;
                            *(_BYTE *)(v251 + 20) &= 0xFu;
                            dword_50C9A4 = 0;
                          }
                          v91 = (double)GetTickCount() * 0.1000000014901161;
                          sub_4A63E6(
                            pD3DRenderer,
                            v240,
                            v228,
                            v86 != -1 ? 72 * v86 + 7145548 : 0,
                            v88,
                            (signed __int64)v91,
                            0,
                            255);
LABEL_191:
                          v80 = v246;
                          goto LABEL_192;
                        }
                      }
                      v201 = "sptext01";
                      goto LABEL_181;
                    }
                  }
LABEL_192:
                  v95 = *(_DWORD *)(v80 + 6476);
                  if ( v95 )
                  {
                    v96 = 48 * *(_DWORD *)(v80 + 36 * v95 + 496);
                    if ( byte_5D2A00[v96] == 1 || byte_5D2A00[v96 + 1] == 4 && !*(_DWORD *)(v80 + 6472) )
                      CD3DRenderer_DrawTransparentTexture(
                        pD3DRenderer,
                        dword_4E4C28 + *(int *)((char *)&dword_4E5B00 + v276),
                        dword_4E4C2C + *(int *)((char *)&dword_4E5B04 + v276),
                        *(int *)((char *)dword_5115C0 + v269) != -1 ? 72 * *(int *)((char *)dword_5115C0 + v269)
                                                                    + 7145548 : 0);
                  }
                  v98 = *(_DWORD *)(v80 + 6484);
                  v264 = v98;
                  v100 = v80 + 36 * v98;
                  v271 = v100;
                  v99 = *(_DWORD *)(v100 + 496);
                  v97 = *(_DWORD *)(v100 + 496) - 504;
                  if ( v97 )
                  {
                    v101 = v97 - 1;
                    if ( v101 )
                    {
                      v102 = v101 - 11;
                      if ( v102 )
                      {
                        if ( v102 != 17 )
                        {
                          v103 = v99 - 66;
LABEL_207:
                          if ( v103 < 0 || v103 > 17 )
                          {
LABEL_259:
                            v130 = *(_DWORD *)(v80 + 6496);
                            if ( !v130 )
                              goto LABEL_293;
                            v265 = *(_DWORD *)(v80 + 6496);
                            v132 = v80 + 36 * v130 + 496;
                            v254 = v132;
                            v131 = *(_DWORD *)v132;
                            if ( v131 != 525 )
                            {
                              switch ( v131 )
                              {
                                case 530:
                                  v220 = 6;
                                  break;
                                case 547:
                                  v220 = 7;
                                  break;
                                case 548:
                                  v220 = 8;
                                  break;
                                default:
                                  if ( v131 != 550 )
                                  {
                                    v133 = v131 - 105;
LABEL_272:
                                    if ( v133 >= 0 && v133 < 10 )
                                    {
LABEL_274:
                                      v136 = v133 + 10 * v268;
                                      v134 = dword_511788[v136];
                                      v136 *= 8;
                                      v135 = dword_4E4C28 + *(int *)((char *)&dword_4E56B0 + v136);
                                      v242 = dword_4E4C28 + *(int *)((char *)&dword_4E56B0 + v136);
                                      v230 = dword_4E4C2C + *(int *)((char *)&dword_4E56B4 + v136);
                                      if ( v134 == sub_40F9F0(pClass17_Icons_LOD, "pending") )
                                      {
LABEL_292:
                                        v80 = v246;
                                        goto LABEL_293;
                                      }
                                      v137 = *(_DWORD *)(v254 + 20);
                                      if ( !(*(_DWORD *)(v254 + 20) & 0xF0) )
                                      {
                                        v142 = v134 + 1;
                                        v141 = 72 * v134 + 7145548;
                                        if ( v137 & 2 )
                                        {
                                          v143 = v142 != 0 ? v141 : 0;
                                          sub_4A6776(pD3DRenderer, v242, v230, v143);
                                        }
                                        else
                                        {
                                          v143 = v142 != 0 ? v141 : 0;
                                          CD3DRenderer_DrawTransparentTexture(pD3DRenderer, v242, v230, v143);
                                        }
                                        if ( !dword_5118E0 )
                                          sub_4A612A(pD3DRenderer, v242, v230, v143, v265);
                                        goto LABEL_292;
                                      }
                                      if ( (*(_DWORD *)(v254 + 20) & 0xF0) != 16 )
                                      {
                                        if ( (*(_DWORD *)(v254 + 20) & 0xF0) == 32 )
                                        {
                                          v208 = "sp28a";
                                          goto LABEL_284;
                                        }
                                        if ( (*(_DWORD *)(v254 + 20) & 0xF0) == 64 )
                                        {
                                          v208 = "sp30a";
                                          goto LABEL_284;
                                        }
                                        if ( (*(_DWORD *)(v254 + 20) & 0xF0) == 128 )
                                        {
                                          v208 = "sp91a";
LABEL_284:
                                          v243 = 72 * class17_LoadTexture(pClass17_Icons_LOD, v208, 2) + 7145548;
                                          v138 = dword_50C9A8 == pClass24_global->int_00001C;
                                          v139 = dword_50C9A8 - pClass24_global->int_00001C < 0;
                                          dword_50C9A8 -= pClass24_global->int_00001C;
                                          if ( v139 | v138 )
                                          {
                                            dword_50C9A8 = 0;
                                            *(_BYTE *)(v254 + 20) &= 0xFu;
                                            dword_50C9A4 = 0;
                                          }
                                          v140 = (double)GetTickCount() * 0.1000000014901161;
                                          sub_4A63E6(
                                            pD3DRenderer,
                                            v135,
                                            v230,
                                            v134 != -1 ? 72 * v134 + 7145548 : 0,
                                            v243,
                                            (signed __int64)v140,
                                            0,
                                            255);
                                          goto LABEL_292;
                                        }
                                      }
                                      v208 = "sptext01";
                                      goto LABEL_284;
                                    }
LABEL_293:
                                    if ( v273 == 12 || v273 == 13 )
                                    {
                                      v144 = dword_511208[v273];
                                      if ( v144 != sub_40F9F0(pClass17_Icons_LOD, "Pending") )
                                        CD3DRenderer_DrawTransparentTexture(
                                          pD3DRenderer,
                                          dword_4E4C28 + dword_4E5AD0[2 * v273 - 24],
                                          dword_4E4C2C + dword_4E5AD4[2 * v273 - 24],
                                          v144 != -1 ? 72 * v144 + 7145548 : 0);
                                    }
                                    v145 = *(_DWORD *)(v80 + 6488);
                                    if ( !v145 )
                                      goto LABEL_335;
                                    v266 = v145;
                                    v146 = v246 + 36 * v145 + 496;
                                    v255 = v146;
                                    if ( *(_DWORD *)v146 != 521 )
                                    {
                                      switch ( *(_DWORD *)v146 )
                                      {
                                        case 0x20A:
                                          v221 = 12;
                                          break;
                                        case 0x20B:
                                          v221 = 13;
                                          break;
                                        case 0x214:
                                          v221 = 14;
                                          break;
                                        default:
                                          if ( *(_DWORD *)v146 != 544 )
                                          {
                                            v147 = *(_DWORD *)v146 - 89;
LABEL_310:
                                            if ( v147 < 0 || v147 >= 16 )
                                              goto LABEL_335;
                                            goto LABEL_312;
                                          }
                                          v221 = 15;
                                          break;
                                      }
                                      v147 = v221;
LABEL_312:
                                      v148 = 8 * (v147 + 16 * v268);
                                      v244 = dword_4E4C28 + *(int *)((char *)&dword_4E58D0 + v148);
                                      v231 = dword_4E4C2C + *(int *)((char *)&dword_4E58D4 + v148);
                                      if ( v277 != 1 || *(_DWORD *)v146 != 92 )
                                        v149 = dword_511698[v147 + 16 * v279];
                                      else
                                        v149 = dword_511234;
                                      v150 = *(_DWORD *)(v146 + 20);
                                      if ( *(_DWORD *)(v146 + 20) & 0xF0 )
                                      {
                                        if ( (*(_DWORD *)(v146 + 20) & 0xF0) != 16 )
                                        {
                                          if ( (*(_DWORD *)(v146 + 20) & 0xF0) == 32 )
                                          {
                                            v209 = "sp28a";
                                            goto LABEL_325;
                                          }
                                          if ( (*(_DWORD *)(v146 + 20) & 0xF0) == 64 )
                                          {
                                            v209 = "sp30a";
                                            goto LABEL_325;
                                          }
                                          if ( (*(_DWORD *)(v146 + 20) & 0xF0) == 128 )
                                          {
                                            v209 = "sp91a";
LABEL_325:
                                            v151 = 72 * class17_LoadTexture(pClass17_Icons_LOD, v209, 2) + 7145548;
                                            v152 = dword_50C9A8 == pClass24_global->int_00001C;
                                            v153 = dword_50C9A8 - pClass24_global->int_00001C < 0;
                                            dword_50C9A8 -= pClass24_global->int_00001C;
                                            if ( v153 | v152 )
                                            {
                                              dword_50C9A8 = 0;
                                              *(_BYTE *)(v255 + 20) &= 0xFu;
                                              dword_50C9A4 = 0;
                                            }
                                            v154 = (double)GetTickCount() * 0.1000000014901161;
                                            sub_4A63E6(
                                              pD3DRenderer,
                                              v244,
                                              v231,
                                              v149 != -1 ? 72 * v149 + 7145548 : 0,
                                              v151,
                                              (signed __int64)v154,
                                              0,
                                              255);
                                            goto LABEL_335;
                                          }
                                        }
                                        v209 = "sptext01";
                                        goto LABEL_325;
                                      }
                                      v156 = v149 + 1;
                                      v155 = 72 * v149 + 7145548;
                                      if ( v150 & 2 )
                                      {
                                        v157 = v156 != 0 ? v155 : 0;
                                        sub_4A6776(pD3DRenderer, v244, v231, v157);
                                      }
                                      else
                                      {
                                        if ( v150 & 1 )
                                        {
                                          v157 = v156 != 0 ? v155 : 0;
                                          CD3DRenderer_DrawTransparentTexture(pD3DRenderer, v244, v231, v157);
                                        }
                                        else
                                        {
                                          v157 = v156 != 0 ? v155 : 0;
                                          sub_4A68EF(pD3DRenderer, v244, v231, v157);
                                        }
                                      }
                                      if ( !dword_5118E0 )
                                        sub_4A612A(pD3DRenderer, v244, v231, v157, v266);
LABEL_335:
                                      v158 = *(_DWORD *)(v246 + 6476);
                                      if ( !v158 )
                                        goto LABEL_358;
                                      v267 = *(_DWORD *)(v246 + 6476);
                                      v160 = v246 + 36 * v158 + 496;
                                      v256 = v160;
                                      v161 = *(_DWORD *)v160;
                                      v159 = 48 * *(_DWORD *)v160;
                                      v245 = dword_4E4C28
                                           + dword_4E4C38[32 * v268]
                                           - *(__int16 *)((char *)&word_5D29FC + v159);
                                      v232 = dword_4E4C2C
                                           + dword_4E4C3C[32 * v268]
                                           - *(__int16 *)((char *)&word_5D29FE + v159);
                                      if ( v161 == 64 )
                                        v210 = "item64v1";
                                      else
                                       v210 = *(const char **)(pClass40->pItems[0].pIconName + v159);
                                      v163 = class17_LoadTexture(pClass17_Icons_LOD, v210, 2);
                                      v162 = *(_DWORD *)(v256 + 20);
                                      if ( !(*(_DWORD *)(v256 + 20) & 0xF0) )
                                      {
                                        v169 = v163 + 1;
                                        v168 = 72 * v163 + 7145548;
                                        if ( v162 & 2 )
                                        {
                                          v170 = v169 != 0 ? v168 : 0;
                                          sub_4A6776(pD3DRenderer, v245, v232, v170);
                                        }
                                        else
                                        {
                                          if ( v162 & 1 )
                                          {
                                            v170 = v169 != 0 ? v168 : 0;
                                            CD3DRenderer_DrawTransparentTexture(pD3DRenderer, v245, v232, v170);
                                          }
                                          else
                                          {
                                            v170 = v169 != 0 ? v168 : 0;
                                            sub_4A68EF(pD3DRenderer, v245, v232, v170);
                                          }
                                        }
                                        if ( !dword_5118E0 )
                                          sub_4A612A(pD3DRenderer, v245, v232, v170, v267);
LABEL_358:
                                        v171 = *(_DWORD *)(v246 + 6472);
                                        v278 = *(_DWORD *)(v246 + 6472);
                                        if ( !v171 )
                                          goto LABEL_393;
                                        v175 = v246 + 36 * v171 + 496;
                                        v257 = v175;
                                        v174 = *(_DWORD *)v175;
                                        v172 = 48 * *(_DWORD *)v175;
                                        v173 = (unsigned __int8)byte_5D2A00[v172 + 1];
                                        if ( v173 != 2 && v173 != 1 )
                                        {
                                          v274 = 0;
LABEL_362:
                                          v176 = dword_4E4C28
                                               + dword_4E4C30[32 * v268]
                                               - *(__int16 *)((char *)&word_5D29FC + v172);
                                          v233 = dword_4E4C2C
                                               + dword_4E4C34[32 * v268]
                                               - *(__int16 *)((char *)&word_5D29FE + v172);
                                          goto LABEL_370;
                                        }
                                        v177 = v174 - 400;
                                        v274 = 1;
                                        if ( v177 )
                                        {
                                          v178 = v177 - 3;
                                          if ( v178 )
                                          {
                                            if ( v178 != 12 )
                                              goto LABEL_362;
                                            v176 = 595;
                                            v233 = 33;
LABEL_370:
                                            v181 = class17_LoadTexture(
                                                     pClass17_Icons_LOD,
                                                     *(const char **)(pClass40->pItems[0].pIconName + v172),
                                                     2);
                                            v180 = v181;
                                            v272 = v181;
                                            v179 = *(_DWORD *)(v257 + 20);
                                            if ( !(*(_DWORD *)(v257 + 20) & 0xF0) )
                                            {
                                              if ( v179 & 2 )
                                              {
                                                v187 = v272 != -1 ? 72 * v272 + 7145548 : 0;
                                                sub_4A6776(pD3DRenderer, v176, v233, v187);
                                              }
                                              else
                                              {
                                                v188 = (v179 & 1) == 0;
                                                v189 = 72 * v272 + 7145548;
                                                if ( v188 )
                                                {
                                                  v187 = v272 != -1 ? v189 : 0;
                                                  sub_4A68EF(pD3DRenderer, v176, v233, v272 != -1 ? v189 : 0);
                                                }
                                                else
                                                {
                                                  v187 = v272 != -1 ? v189 : 0;
                                                  CD3DRenderer_DrawTransparentTexture(pD3DRenderer, v176, v233, v272 != -1 ? v189 : 0);
                                                }
                                              }
                                              if ( !dword_5118E0 )
                                                sub_4A612A(pD3DRenderer, v176, v233, v187, v278);
                                              goto LABEL_391;
                                            }
                                            if ( (*(_DWORD *)(v257 + 20) & 0xF0) != 16 )
                                            {
                                              if ( (*(_DWORD *)(v257 + 20) & 0xF0) == 32 )
                                              {
                                                v212 = "sp28a";
                                              }
                                              else
                                              {
                                                if ( (*(_DWORD *)(v257 + 20) & 0xF0) != 64 )
                                                {
                                                  v182 = pClass17_Icons_LOD;
                                                  if ( (*(_DWORD *)(v257 + 20) & 0xF0) == 128 )
                                                  {
                                                    v212 = "sp91a";
LABEL_381:
                                                    v183 = 72 * class17_LoadTexture(v182, v212, 2) + 7145548;
                                                    v184 = dword_50C9A8 == pClass24_global->int_00001C;
                                                    v185 = dword_50C9A8 - pClass24_global->int_00001C < 0;
                                                    dword_50C9A8 -= pClass24_global->int_00001C;
                                                    if ( v185 | v184 )
                                                    {
                                                      dword_50C9A8 = 0;
                                                      *(_BYTE *)(v257 + 20) &= 0xFu;
                                                      dword_50C9A4 = 0;
                                                    }
                                                    v186 = (double)GetTickCount() * 0.1000000014901161;
                                                    sub_4A63E6(
                                                      pD3DRenderer,
                                                      v176,
                                                      v233,
                                                      v180 != -1 ? 72 * v180 + 7145548 : 0,
                                                      v183,
                                                      (signed __int64)v186,
                                                      0,
                                                      255);
LABEL_391:
                                                    if ( v274 )
                                                      CD3DRenderer_DrawTransparentTexture(
                                                        pD3DRenderer,
                                                        dword_4E4C28 + *(int *)((char *)&dword_4E5B40 + v276),
                                                        dword_4E4C2C + *(int *)((char *)&dword_4E5B44 + v276),
                                                        *(int *)((char *)dword_51126C + v269) != -1 ? 72 * *(int *)((char *)dword_51126C + v269) + 7145548 : 0);
                                                    goto LABEL_393;
                                                  }
LABEL_380:
                                                  v212 = "sptext01";
                                                  goto LABEL_381;
                                                }
                                                v212 = "sp30a";
                                              }
                                              v182 = pClass17_Icons_LOD;
                                              goto LABEL_381;
                                            }
                                            v182 = pClass17_Icons_LOD;
                                            goto LABEL_380;
                                          }
                                          v233 = 28;
                                        }
                                        else
                                        {
                                          v233 = 86;
                                        }
                                        v176 = 596;
                                        goto LABEL_370;
                                      }
                                      if ( (*(_DWORD *)(v256 + 20) & 0xF0) != 16 )
                                      {
                                        if ( (*(_DWORD *)(v256 + 20) & 0xF0) == 32 )
                                        {
                                          v211 = "sp28a";
                                          goto LABEL_348;
                                        }
                                        if ( (*(_DWORD *)(v256 + 20) & 0xF0) == 64 )
                                        {
                                          v211 = "sp30a";
                                          goto LABEL_348;
                                        }
                                        if ( (*(_DWORD *)(v256 + 20) & 0xF0) == 128 )
                                        {
                                          v211 = "sp91a";
LABEL_348:
                                          v164 = 72 * class17_LoadTexture(pClass17_Icons_LOD, v211, 2) + 7145548;
                                          v165 = dword_50C9A8 == pClass24_global->int_00001C;
                                          v166 = dword_50C9A8 - pClass24_global->int_00001C < 0;
                                          dword_50C9A8 -= pClass24_global->int_00001C;
                                          if ( v166 | v165 )
                                          {
                                            dword_50C9A8 = 0;
                                            *(_BYTE *)(v256 + 20) &= 0xFu;
                                            dword_50C9A4 = 0;
                                          }
                                          v167 = (double)GetTickCount() * 0.1000000014901161;
                                          sub_4A63E6(
                                            pD3DRenderer,
                                            v245,
                                            v232,
                                            v163 != -1 ? 72 * v163 + 7145548 : 0,
                                            v164,
                                            (signed __int64)v167,
                                            0,
                                            255);
                                          goto LABEL_358;
                                        }
                                      }
                                      v211 = "sptext01";
                                      goto LABEL_348;
                                    }
                                    v147 = 11;
                                    goto LABEL_310;
                                  }
                                  v220 = 9;
                                  break;
                              }
                              v133 = v220;
                              goto LABEL_274;
                            }
                            v133 = 5;
                            goto LABEL_272;
                          }
LABEL_209:
                          if ( *(_DWORD *)(v80 + 6476)
                            && (sub_48D62C((void *)v80, 1) == 1
                             || sub_48D651((void *)v80, 1) == 4 && !*(_DWORD *)(v80 + 6472)) )
                          {
                            v105 = 17 * v268 + v103;
                            v104 = 12 * v105;
                            v252 = dword_511298[3 * v105];
                            if ( v252 == sub_40F9F0(pClass17_Icons_LOD, "pending") )
                            {
                              v108 = 8 * v105;
                              v107 = *(int *)((char *)dword_511294 + v104);
                              v241 = dword_4E4C28 + *(int *)((char *)dword_4E5050 + v108);
                              v106 = *(int *)((char *)dword_4E5054 + v108);
                            }
                            else
                            {
                              v107 = v252;
                              v241 = dword_4E4C28 + dword_4E5270[2 * v105];
                              v106 = dword_4E5274[2 * v105];
                            }
                            v229 = dword_4E4C2C + v106;
                            if ( v107 == sub_40F9F0(pClass17_Icons_LOD, "pending") )
                              goto LABEL_258;
                            v109 = *(_DWORD *)(v271 + 516);
                            if ( *(_DWORD *)(v271 + 516) & 0xF0 )
                            {
                              if ( (*(_DWORD *)(v271 + 516) & 0xF0) != 16 )
                              {
                                if ( (*(_DWORD *)(v271 + 516) & 0xF0) == 32 )
                                {
                                  v202 = "sp28a";
                                  goto LABEL_226;
                                }
                                if ( (*(_DWORD *)(v271 + 516) & 0xF0) == 64 )
                                {
                                  v202 = "sp30a";
                                  goto LABEL_226;
                                }
                                if ( (*(_DWORD *)(v271 + 516) & 0xF0) == 128 )
                                {
                                  v202 = "sp91a";
LABEL_226:
                                  v110 = 72 * class17_LoadTexture(pClass17_Icons_LOD, v202, 2) + 7145548;
                                  v111 = dword_50C9A8 == pClass24_global->int_00001C;
                                  v112 = dword_50C9A8 - pClass24_global->int_00001C < 0;
                                  dword_50C9A8 -= pClass24_global->int_00001C;
                                  if ( v112 | v111 )
                                  {
                                    dword_50C9A8 = 0;
                                    *(_BYTE *)(v271 + 516) &= 0xFu;
                                    dword_50C9A4 = 0;
                                  }
                                  v216 = 255;
                                  v203 = 0;
                                  v113 = (double)GetTickCount();
LABEL_249:
                                  sub_4A63E6(
                                    pD3DRenderer,
                                    v241,
                                    v229,
                                    v107 != -1 ? 72 * v107 + 7145548 : 0,
                                    v110,
                                    (signed __int64)(v113 * 0.1000000014901161),
                                    v203,
                                    v216);
                                  goto LABEL_258;
                                }
                              }
                              v202 = "sptext01";
                              goto LABEL_226;
                            }
                            v116 = v107 + 1;
                            v117 = (v109 & 2) == 0;
                            v114 = 72 * v107 + 7145548;
                            v115 = pD3DRenderer;
                            if ( !v117 )
                            {
                              v118 = v116 != 0 ? v114 : 0;
                              v217 = v118;
                              v204 = v229;
                              v192 = v241;
LABEL_231:
                              sub_4A6776(v115, v192, v204, v217);
                              goto LABEL_256;
                            }
                            if ( *(_BYTE *)(v271 + 516) & 1 )
                            {
                              v118 = v116 != 0 ? v114 : 0;
                              v218 = v118;
                              v205 = v229;
                              v193 = v241;
LABEL_234:
                              CD3DRenderer_DrawTransparentTexture(v115, v193, v205, v218);
                              goto LABEL_256;
                            }
                            v118 = v116 != 0 ? v114 : 0;
                            v219 = v118;
                            v206 = v229;
                            v194 = v241;
                            goto LABEL_255;
                          }
                          v119 = 17 * v268 + v103;
                          v107 = dword_511294[3 * v119];
                          if ( v107 == sub_40F9F0(pClass17_Icons_LOD, "pending") )
                          {
LABEL_258:
                            v80 = v246;
                            goto LABEL_259;
                          }
                          v120 = dword_4E4C28 + dword_4E5050[2 * v119];
                          v122 = dword_4E4C2C + dword_4E5054[2 * v119];
                          v253 = *(_DWORD *)(v271 + 516);
                          v121 = *(_DWORD *)(v271 + 516) & 0xF0;
                          v241 = dword_4E4C28 + dword_4E5050[2 * v119];
                          v229 = dword_4E4C2C + dword_4E5054[2 * v119];
                          if ( !v121 )
                          {
                            v129 = v107 + 1;
                            v128 = 72 * v107 + 7145548;
                            if ( v253 & 2 )
                            {
                              v118 = v129 != 0 ? v128 : 0;
                              v217 = v118;
                              v204 = v122;
                              v192 = v120;
                              v115 = pD3DRenderer;
                              goto LABEL_231;
                            }
                            if ( v253 & 1 )
                            {
                              v118 = v129 != 0 ? v128 : 0;
                              v218 = v118;
                              v205 = v122;
                              v193 = v120;
                              v115 = pD3DRenderer;
                              goto LABEL_234;
                            }
                            v118 = v129 != 0 ? v128 : 0;
                            v219 = v118;
                            v206 = v122;
                            v194 = v120;
                            v115 = pD3DRenderer;
LABEL_255:
                            sub_4A68EF(v115, v194, v206, v219);
LABEL_256:
                            if ( !dword_5118E0 )
                              sub_4A612A(pD3DRenderer, v241, v229, v118, v264);
                            goto LABEL_258;
                          }
                          v123 = v121 - 16;
                          if ( v123 )
                          {
                            v124 = v123 - 16;
                            if ( !v124 )
                            {
                              v207 = "sp28a";
                              goto LABEL_246;
                            }
                            v125 = v124 - 32;
                            if ( !v125 )
                            {
                              v207 = "sp30a";
                              goto LABEL_246;
                            }
                            if ( v125 == 64 )
                            {
                              v207 = "sp91a";
LABEL_246:
                              v110 = 72 * class17_LoadTexture(pClass17_Icons_LOD, v207, 2) + 7145548;
                              v126 = dword_50C9A8 == pClass24_global->int_00001C;
                              v127 = dword_50C9A8 - pClass24_global->int_00001C < 0;
                              dword_50C9A8 -= pClass24_global->int_00001C;
                              if ( v127 | v126 )
                              {
                                dword_50C9A8 = 0;
                                *(_BYTE *)(v271 + 516) &= 0xFu;
                                dword_50C9A4 = 0;
                              }
                              v216 = 255;
                              v203 = 0;
                              v113 = (double)GetTickCount();
                              goto LABEL_249;
                            }
                          }
                          v207 = "sptext01";
                          goto LABEL_246;
                        }
                        v215 = 16;
                      }
                      else
                      {
                        v215 = 13;
                      }
                    }
                    else
                    {
                      v215 = 14;
                    }
                    v103 = v215;
                    goto LABEL_209;
                  }
                  v103 = 15;
                  goto LABEL_207;
                }
                if ( (*(_DWORD *)(v67 + 20) & 0xF0) != 16 )
                {
                  if ( (*(_DWORD *)(v67 + 20) & 0xF0) == 32 )
                  {
                    v200 = "sp28a";
                    goto LABEL_145;
                  }
                  if ( (*(_DWORD *)(v67 + 20) & 0xF0) == 64 )
                  {
                    v200 = "sp30a";
                    goto LABEL_145;
                  }
                  if ( (*(_DWORD *)(v67 + 20) & 0xF0) == 128 )
                  {
                    v200 = "sp91a";
LABEL_145:
                    v72 = 72 * class17_LoadTexture(pClass17_Icons_LOD, v200, 2) + 7145548;
                    v73 = dword_50C9A8 == pClass24_global->int_00001C;
                    v74 = dword_50C9A8 - pClass24_global->int_00001C < 0;
                    dword_50C9A8 -= pClass24_global->int_00001C;
                    if ( v74 | v73 )
                    {
                      dword_50C9A8 = 0;
                      *(_BYTE *)(v250 + 20) &= 0xFu;
                      dword_50C9A4 = 0;
                    }
                    v75 = (double)GetTickCount() * 0.1000000014901161;
                    sub_4A63E6(
                      pD3DRenderer,
                      v239,
                      v227,
                      v68 != -1 ? 72 * v68 + 7145548 : 0,
                      v72,
                      (signed __int64)v75,
                      0,
                      255);
                    goto LABEL_155;
                  }
                }
                v200 = "sptext01";
                goto LABEL_145;
              }
              v51 = 15;
              goto LABEL_104;
            }
            v37 = 5;
            goto LABEL_72;
          }
LABEL_48:
          v197 = "sptext01";
          goto LABEL_49;
        }
        v197 = "sp30a";
      }
      v28 = pClass17_Icons_LOD;
      goto LABEL_49;
    }
    v28 = pClass17_Icons_LOD;
    goto LABEL_48;
  }
  v222 = dword_4E4C2C;
  v234 = dword_4E4C28;
  v269 = 4 * v275 - 4;
  CD3DRenderer_DrawTransparentTexture(
    pD3DRenderer,
    dword_4E4C28,
    dword_4E4C2C,
    *(int *)((char *)dword_51127C + v269) != -1 ? 72 * *(int *)((char *)dword_51127C + v269) + 7145548 : 0);
  if ( !dword_5118E0 )
    sub_4A612A(pD3DRenderer,
      v234,
      v222,
      *(int *)((char *)dword_51127C + v269) != -1 ? 72 * *(int *)((char *)dword_51127C + v269) + 7145548 : 0,
      *(_DWORD *)(v2 + 6484));
  v276 = 8 * v5;
  v6 = *(_DWORD *)(v2 + 6476);
  if ( !v6
    || (v7 = 48 * *(_DWORD *)(v2 + 36 * v6 + 496), byte_5D2A00[v7] != 1)
    && (byte_5D2A00[v7 + 1] != 4 || *(_DWORD *)(v2 + 6472)) )
    CD3DRenderer_DrawTransparentTexture(
      pD3DRenderer,
      dword_4E4C28 + dword_4E5AE0[2 * v5],
      dword_4E4C2C + dword_4E5AE4[2 * v5],
      *(int *)((char *)dword_5115D0 + v269) != -1 ? 72 * *(int *)((char *)dword_5115D0 + v269) + 7145548 : 0);
  v8 = *(_DWORD *)(v2 + 6476);
  if ( v8 )
  {
    v258 = *(_DWORD *)(v2 + 6476);
    v11 = v246 + 36 * v8 + 496;
    v12 = v5 << 7;
    v247 = v11;
    v13 = *(_DWORD *)v11;
    v9 = 48 * *(_DWORD *)v11;
    v10 = dword_4E4C28 + dword_4E4C38[32 * v5] - *(__int16 *)((char *)&word_5D29FC + v9);
    v235 = v10;
    v223 = dword_4E4C2C + *(int *)((char *)dword_4E4C3C + v12) - *(__int16 *)((char *)&word_5D29FE + v9);
    if ( v13 == 64 )
      v195 = "item64v1";
    else
      v195 = *(const char **)(pClass40->pItems[0].pIconName + v9);
    v15 = class17_LoadTexture(pClass17_Icons_LOD, v195, 2);
    v14 = *(_DWORD *)(v247 + 20);
    if ( *(_DWORD *)(v247 + 20) & 0xF0 )
    {
      if ( (*(_DWORD *)(v247 + 20) & 0xF0) != 16 )
      {
        if ( (*(_DWORD *)(v247 + 20) & 0xF0) == 32 )
        {
          v196 = "sp28a";
          goto LABEL_27;
        }
        if ( (*(_DWORD *)(v247 + 20) & 0xF0) == 64 )
        {
          v196 = "sp30a";
          goto LABEL_27;
        }
        if ( (*(_DWORD *)(v247 + 20) & 0xF0) == 128 )
        {
          v196 = "sp91a";
LABEL_27:
          v16 = 72 * class17_LoadTexture(pClass17_Icons_LOD, v196, 2) + 7145548;
          v17 = dword_50C9A8 == pClass24_global->int_00001C;
          v18 = dword_50C9A8 - pClass24_global->int_00001C < 0;
          dword_50C9A8 -= pClass24_global->int_00001C;
          if ( v18 | v17 )
          {
            dword_50C9A8 = 0;
            *(_BYTE *)(v247 + 20) &= 0xFu;
            dword_50C9A4 = 0;
          }
          v19 = (double)GetTickCount() * 0.1000000014901161;
          sub_4A63E6(
            pD3DRenderer,
            v10,
            v223,
            v15 != -1 ? 72 * v15 + 7145548 : 0,
            v16,
            (signed __int64)v19,
            0,
            255);
          goto LABEL_393;
        }
      }
      v196 = "sptext01";
      goto LABEL_27;
    }
    v21 = v15 + 1;
    v20 = 72 * v15 + 7145548;
    if ( v14 & 2 )
    {
      v22 = v21 != 0 ? v20 : 0;
      sub_4A6776(pD3DRenderer, v235, v223, v22);
    }
    else
    {
      if ( v14 & 1 )
      {
        v22 = v21 != 0 ? v20 : 0;
        CD3DRenderer_DrawTransparentTexture(pD3DRenderer, v235, v223, v22);
      }
      else
      {
        v22 = v21 != 0 ? v20 : 0;
        sub_4A68EF(pD3DRenderer, v235, v223, v22);
      }
    }
    if ( !dword_5118E0 )
      sub_4A612A(pD3DRenderer, v235, v223, v22, v258);
  }
LABEL_393:
  CD3DRenderer_DrawTransparentTexture(
    pD3DRenderer,
    dword_4E4C28 + *(int *)((char *)&dword_4E5B20 + v276),
    dword_4E4C2C + *(int *)((char *)&dword_4E5B24 + v276),
    *(int *)((char *)dword_51124C + v269) != -1 ? 72 * *(int *)((char *)dword_51124C + v269) + 7145548 : 0);
  v190 = *(_DWORD *)(v246 + 6476);
  if ( v190 )
  {
    v191 = 48 * *(_DWORD *)(v246 + 36 * v190 + 496);
    if ( byte_5D2A00[v191] == 1 || byte_5D2A00[v191 + 1] == 4 && !*(_DWORD *)(v246 + 6472) )
      CD3DRenderer_DrawTransparentTexture(
        pD3DRenderer,
        dword_4E4C28 + *(int *)((char *)&dword_4E5B00 + v276),
        dword_4E4C2C + *(int *)((char *)&dword_4E5B04 + v276),
        *(int *)((char *)dword_51125C + v269) != -1 ? 72 * *(int *)((char *)dword_51125C + v269) + 7145548 : 0);
  }
  if ( !dword_5118E0 )
    CD3DRenderer_DrawTransparentTexture(pD3DRenderer, 603, 299, dword_5118CC != -1 ? 72 * dword_5118CC + 7145548 : 0);
  CD3DRenderer_DrawTransparentTexture(pD3DRenderer, 468, 0, dword_507B04 != -1 ? 72 * dword_507B04 + 7145548 : 0);
}

//----- (0043E825) --------------------------------------------------------
void __fastcall sub_43E825(int a1)
{
  int v1; // ecx@1
  int v2; // edi@1
  int v3; // ebx@1
  int v4; // eax@3
  int v5; // ebx@3
  int v6; // edi@3
  int v7; // ecx@7
  unsigned __int8 v8; // zf@14
  unsigned __int8 v9; // sf@14
  double v10; // st7@16
  int v11; // edi@17
  int v12; // edi@18
  char v13; // zf@19
  int v14; // eax@19
  unsigned __int8 v15; // zf@24
  char v16; // sf@24
  unsigned __int8 v17; // of@24
  int v18; // eax@25
  int v19; // eax@26
  int v20; // ebx@26
  int v21; // ecx@30
  unsigned __int8 v22; // zf@37
  unsigned __int8 v23; // sf@37
  double v24; // st7@39
  int v25; // edi@40
  int v26; // eax@41
  int v27; // ebx@41
  int v28; // edi@41
  char v29; // zf@42
  int v30; // eax@42
  int v31; // eax@42
  int v32; // eax@46
  int v33; // eax@47
  int v34; // ebx@47
  int v35; // edi@47
  int v36; // ecx@51
  int v37; // esi@58
  unsigned __int8 v38; // zf@58
  unsigned __int8 v39; // sf@58
  double v40; // st7@60
  int v41; // esi@61
  int v42; // esi@62
  char v43; // zf@63
  int v44; // eax@63
  const char *v45; // [sp-8h] [bp-38h]@8
  const char *v46; // [sp-8h] [bp-38h]@31
  const char *v47; // [sp-8h] [bp-38h]@52
  int v48; // [sp+10h] [bp-20h]@3
  int v49; // [sp+10h] [bp-20h]@14
  int v50; // [sp+10h] [bp-20h]@26
  int v51; // [sp+10h] [bp-20h]@37
  int v52; // [sp+10h] [bp-20h]@47
  int v53; // [sp+14h] [bp-1Ch]@3
  int v54; // [sp+18h] [bp-18h]@3
  int v55; // [sp+1Ch] [bp-14h]@1
  int v56; // [sp+20h] [bp-10h]@1
  int v57; // [sp+24h] [bp-Ch]@1
  int v58; // [sp+24h] [bp-Ch]@26

  v3 = a1;
  v2 = (int)*(&ptr_A750C4 + a1);
  v56 = (int)*(&ptr_A750C4 + a1);
  class17_LoadTexture(pClass17_Icons_LOD, "sptext01", 2);
  sub_43CC7C(v3);
  CD3DRenderer_DrawTransparentTexture(pD3DRenderer, 473, 0, dword_5118DC != -1 ? 72 * dword_5118DC + 7145548 : 0);
  CD3DRenderer_DrawTransparentTexture(pD3DRenderer, 468, 0, dword_507B04 != -1 ? 72 * dword_507B04 + 7145548 : 0);
  CD3DRenderer_DrawIndexedTexture(
    pD3DRenderer,
    *(_DWORD *)dword_507694,
    *(_DWORD *)(dword_507694 + 4),
    dword_5118C8 != -1 ? 72 * dword_5118C8 + 7145548 : 0);
  v1 = 0;
  v55 = v2 + 6512;
  v57 = 0;
  do
  {
    if ( !*(_DWORD *)v55 )
      goto LABEL_24;
    v48 = *(_DWORD *)v55;
    v6 = v2 + 36 * *(_DWORD *)v55 + 496;
    v53 = *(int *)((char *)&dword_4E5C34 + v1);
    v54 = *(int *)((char *)&dword_4E5C1C + v1);
    v5 = class17_LoadTexture(pClass17_Icons_LOD, pClass40->pItems[12 * *(_DWORD *)v6].pIconName, 2);
    v4 = *(_DWORD *)(v6 + 20);
    if ( !(*(_DWORD *)(v6 + 20) & 0xF0) )
    {
      v11 = v5 + 1;
      if ( v4 & 2 )
      {
        v12 = v11 != 0 ? 72 * v5 + 7145548 : 0;
        sub_4A6776(pD3DRenderer, v54, v53, v12);
      }
      else
      {
        v13 = (v4 & 1) == 0;
        v14 = 72 * v5 + 7145548;
        if ( v13 )
        {
          v12 = v11 != 0 ? v14 : 0;
          sub_4A68EF(pD3DRenderer, v54, v53, v12);
        }
        else
        {
          v12 = v11 != 0 ? v14 : 0;
          CD3DRenderer_DrawTransparentTexture(pD3DRenderer, v54, v53, v12);
        }
      }
      sub_4A601E(pD3DRenderer, v54, v53, v12, v48);
      goto LABEL_23;
    }
    if ( (*(_DWORD *)(v6 + 20) & 0xF0) == 16 )
    {
      v7 = pClass17_Icons_LOD;
LABEL_13:
      v45 = "sptext01";
      goto LABEL_14;
    }
    if ( (*(_DWORD *)(v6 + 20) & 0xF0) == 32 )
    {
      v45 = "sp28a";
      goto LABEL_11;
    }
    if ( (*(_DWORD *)(v6 + 20) & 0xF0) == 64 )
    {
      v45 = "sp30a";
LABEL_11:
      v7 = pClass17_Icons_LOD;
      goto LABEL_14;
    }
    v7 = pClass17_Icons_LOD;
    if ( (*(_DWORD *)(v6 + 20) & 0xF0) != 128 )
      goto LABEL_13;
    v45 = "sp91a";
LABEL_14:
    v49 = 72 * class17_LoadTexture(v7, v45, 2) + 7145548;
    v8 = dword_50C9A8 == pClass24_global->int_00001C;
    v9 = dword_50C9A8 - pClass24_global->int_00001C < 0;
    dword_50C9A8 -= pClass24_global->int_00001C;
    if ( v9 | v8 )
    {
      dword_50C9A8 = 0;
      *(_BYTE *)(v6 + 20) &= 0xFu;
      dword_50C9A4 = 0;
    }
    v10 = (double)GetTickCount() * 0.1000000014901161;
    sub_4A63E6(pD3DRenderer, v54, v53, v5 != -1 ? 72 * v5 + 7145548 : 0, v49, (signed __int64)v10, 0, 255);
LABEL_23:
    v2 = v56;
LABEL_24:
    v55 += 4;
    v1 = v57 + 4;
    compile_error;//v17 = __SETO__(v57 + 4, 20);
    v15 = v57 == 16;
    v16 = v57 - 16 < 0;
    v57 += 4;
  }
  while ( (unsigned __int8)(v16 ^ v17) | v15 );
  v18 = *(_DWORD *)(v2 + 6508);
  if ( !v18 )
    goto LABEL_46;
  v50 = *(_DWORD *)(v2 + 6508);
  v58 = v2 + 36 * v18 + 496;
  v20 = class17_LoadTexture(pClass17_Icons_LOD, pClass40->pItems[12 * *(_DWORD *)v58].pIconName, 2);
  v19 = *(_DWORD *)(v58 + 20);
  if ( !(*(_DWORD *)(v58 + 20) & 0xF0) )
  {
    v25 = v20 + 1;
    if ( v19 & 2 )
    {
      v26 = 9 * v20;
      v27 = 493;
      v28 = v25 != 0 ? 8 * v26 + 7145548 : 0;
      sub_4A6776(pD3DRenderer, 493, 91, v28);
    }
    else
    {
      v29 = (v19 & 1) == 0;
      v31 = 9 * v20;
      v27 = 493;
      v30 = 8 * v31 + 7145548;
      if ( v29 )
      {
        v28 = v25 != 0 ? v30 : 0;
        sub_4A68EF(pD3DRenderer, 493, 91, v28);
      }
      else
      {
        v28 = v25 != 0 ? v30 : 0;
        CD3DRenderer_DrawTransparentTexture(pD3DRenderer, 493, 91, v28);
      }
    }
    sub_4A601E(pD3DRenderer, v27, 91, v28, v50);
    v2 = v56;
    goto LABEL_46;
  }
  if ( (*(_DWORD *)(v58 + 20) & 0xF0) == 16 )
  {
    v21 = pClass17_Icons_LOD;
    goto LABEL_36;
  }
  if ( (*(_DWORD *)(v58 + 20) & 0xF0) == 32 )
  {
    v46 = "sp28a";
    goto LABEL_34;
  }
  if ( (*(_DWORD *)(v58 + 20) & 0xF0) == 64 )
  {
    v46 = "sp30a";
LABEL_34:
    v21 = pClass17_Icons_LOD;
    goto LABEL_37;
  }
  v21 = pClass17_Icons_LOD;
  if ( (*(_DWORD *)(v58 + 20) & 0xF0) == 128 )
  {
    v46 = "sp91a";
    goto LABEL_37;
  }
LABEL_36:
  v46 = "sptext01";
LABEL_37:
  v51 = 72 * class17_LoadTexture(v21, v46, 2) + 7145548;
  v22 = dword_50C9A8 == pClass24_global->int_00001C;
  v23 = dword_50C9A8 - pClass24_global->int_00001C < 0;
  dword_50C9A8 -= pClass24_global->int_00001C;
  if ( v23 | v22 )
  {
    dword_50C9A8 = 0;
    *(_BYTE *)(v58 + 20) &= 0xFu;
    dword_50C9A4 = 0;
  }
  v24 = (double)GetTickCount() * 0.1000000014901161;
  sub_4A63E6(pD3DRenderer, 493, 91, v20 != -1 ? 72 * v20 + 7145548 : 0, v51, (signed __int64)v24, 0, 255);
LABEL_46:
  v32 = *(_DWORD *)(v2 + 6500);
  if ( !v32 )
    return;
  v52 = *(_DWORD *)(v2 + 6500);
  v35 = v2 + 36 * v32 + 496;
  v34 = class17_LoadTexture(pClass17_Icons_LOD, pClass40->pItems[12 * *(_DWORD *)v35].pIconName, 2);
  v33 = *(_DWORD *)(v35 + 20);
  if ( !(*(_DWORD *)(v35 + 20) & 0xF0) )
  {
    v41 = v34 + 1;
    if ( v33 & 2 )
    {
      v42 = v41 != 0 ? 72 * v34 + 7145548 : 0;
      sub_4A6776(pD3DRenderer, 586, 88, v42);
    }
    else
    {
      v43 = (v33 & 1) == 0;
      v44 = 72 * v34 + 7145548;
      if ( v43 )
      {
        v42 = v41 != 0 ? v44 : 0;
        sub_4A68EF(pD3DRenderer, 586, 88, v42);
      }
      else
      {
        v42 = v41 != 0 ? v44 : 0;
        CD3DRenderer_DrawTransparentTexture(pD3DRenderer, 586, 88, v42);
      }
    }
    sub_4A601E(pD3DRenderer, 586, 88, v42, v52);
    return;
  }
  if ( (*(_DWORD *)(v35 + 20) & 0xF0) == 16 )
  {
    v36 = pClass17_Icons_LOD;
    goto LABEL_57;
  }
  if ( (*(_DWORD *)(v35 + 20) & 0xF0) == 32 )
  {
    v47 = "sp28a";
    goto LABEL_55;
  }
  if ( (*(_DWORD *)(v35 + 20) & 0xF0) == 64 )
  {
    v47 = "sp30a";
LABEL_55:
    v36 = pClass17_Icons_LOD;
    goto LABEL_58;
  }
  v36 = pClass17_Icons_LOD;
  if ( (*(_DWORD *)(v35 + 20) & 0xF0) == 128 )
  {
    v47 = "sp91a";
    goto LABEL_58;
  }
LABEL_57:
  v47 = "sptext01";
LABEL_58:
  v37 = 72 * class17_LoadTexture(v36, v47, 2) + 7145548;
  v38 = dword_50C9A8 == pClass24_global->int_00001C;
  v39 = dword_50C9A8 - pClass24_global->int_00001C < 0;
  dword_50C9A8 -= pClass24_global->int_00001C;
  if ( v39 | v38 )
  {
    dword_50C9A8 = 0;
    *(_BYTE *)(v35 + 20) &= 0xFu;
    dword_50C9A4 = 0;
  }
  v40 = (double)GetTickCount() * 0.1000000014901161;
  sub_4A63E6(pD3DRenderer, 586, 88, v34 != -1 ? 72 * v34 + 7145548 : 0, v37, (signed __int64)v40, 0, 255);
}

//----- (0043ED6F) --------------------------------------------------------
char __thiscall sub_43ED6F(void *this)
{
  int *v1; // ebx@1
  void *v2; // ebp@1
  signed int v3; // edi@2
  int v4; // esi@2
  char v5; // zf@5

  v2 = this;
  v1 = pPlayers;
  while ( 1 )
  {
    v4 = *v1;
    v3 = GetRaceByFace(*v1);
    Player_GetVoiceSex(v4);   // result not interested?
    if ( v3 && v3 != 1 && v3 != 2 )
      v5 = v2 == (void *)1;
    else
      v5 = v2 == 0;
    if ( v5 )
      break;
    ++v1;

    compile_error;//if ( (signed int)v1 >= (signed int)&dword_A750D8 )
    if (0)
      return 0;
  }
  return 1;
}

//----- (0043EDB9) --------------------------------------------------------
char __thiscall sub_43EDB9(void *this)
{
  int *v1; // ebx@1
  void *v2; // ebp@1
  signed int v3; // eax@2
  signed int v4; // edi@2
  int v5; // esi@2
  char v6; // zf@7

  v2 = this;
  v1 = pPlayers;
  while ( 1 )
  {
    v5 = *v1;
    v4 = GetRaceByFace(*v1);
    v3 = Player_GetVoiceSex(v5);
    if ( !v4 )
      break;
    if ( v4 == 1 || v4 == 2 )
      break;
    if ( !v3 && v2 == (void *)2 )
      return 1;
    v6 = v2 == (void *)3;
LABEL_11:
    if ( v6 )
      return 1;
    ++v1;

    compile_error;//if ( (signed int)v1 >= (signed int)&dword_A750D8 )
    if (0)
      return 0;
  }
  if ( v3 || v2 )
  {
    v6 = v2 == (void *)1;
    goto LABEL_11;
  }
  return 1;
}

//----- (0043EE15) --------------------------------------------------------
char __fastcall sub_43EE15(int a1, int a2, char a3)
{
  signed int v3; // edi@3
  int v4; // esi@3
  signed int v5; // edi@7
  int v6; // esi@7

  if ( !a3 || dword_AD470C != a1 )
  {
    v3 = 0;
    v4 = a2 + 5500;
    while ( !*(_DWORD *)v4 || *(_DWORD *)(a2 + 36 * *(_DWORD *)v4 + 496) != a1 )
    {
      ++v3;
      v4 += 4;
      if ( v3 >= 126 )
      {
        v5 = 0;
        v6 = a2 + 6472;
        while ( !*(_DWORD *)v6 || *(_DWORD *)(a2 + 36 * *(_DWORD *)v6 + 496) != a1 )
        {
          ++v5;
          v6 += 4;
          if ( v5 >= 16 )
            return 0;
        }
        return 1;
      }
    }
  }
  return 1;
}

//----- (0043EE77) --------------------------------------------------------
char __fastcall sub_43EE77(signed int a1)
{
  int v1; // edx@3
  int v2; // ecx@3
  int v3; // eax@4
  int v5; // ecx@8
  int *v6; // esi@8
  int v7; // edx@9
  int v8; // eax@10

  if ( a1 < 1 || a1 > 4 )
  {
    if ( !a1 )
    {
      v6 = pPlayers;
      v5 = 604;
      while ( sub_43EE15(v5, *v6, 0) )
      {
        v8 = *(_DWORD *)(v7 + 6484);
        if ( !v8 )
          break;
        if ( *(_DWORD *)(v7 + 36 * v8 + 496) != v5 )
          break;
        ++v6;

        compile_error;//if ( (signed int)v6 >= (signed int)&dword_A750D8 )
        if (0)
          return 1;
      }
    }
    return 0;
  }
  if ( !sub_43EE15(604, (int)*(&ptr_A750C4 + a1), 0)
    || (v3 = *(_DWORD *)(v1 + 6484), !v3)
    || *(_DWORD *)(v1 + 36 * v3 + 496) != v2 )
    return 0;
  return 1;
}

//----- (0043EEF3) --------------------------------------------------------
char __thiscall sub_43EEF3(void *this)
{
  int v1; // edx@1
  signed int v2; // esi@1
  int v3; // eax@3

  v2 = 0;
  v1 = (int)((char *)this + 6472);
  while ( 1 )
  {
    if ( *(_DWORD *)v1 )
    {
      v3 = *((_DWORD *)this + 9 * *(_DWORD *)v1 + 124);
      if ( v3 )
      {
        if ( v3 != 64 && v3 != 65 )
          break;
      }
    }
    ++v2;
    v1 += 4;
    if ( v2 >= 16 )
      return 1;
  }
  return 0;
}

//----- (0043EF2B) --------------------------------------------------------
void __fastcall sub_43EF2B(int a1)
{
  int v1; // ebx@1
  signed int v2; // eax@2
  signed int v3; // edi@2
  int *v4; // esi@2
  int v5; // ecx@5
  char v6; // al@7
  CHAR Str1; // [sp+4h] [bp-1Ch]@7
  int v8; // [sp+18h] [bp-8h]@1
  int v9; // [sp+1Ch] [bp-4h]@7

  v1 = a1 - 1;
  v8 = a1;
  if ( a1 - 1 >= 0 )
  {
    v4 = (int *)(4 * a1 + 10965188);
    v3 = GetRaceByFace((int)*(&ptr_A750C4 + a1));
    v2 = Player_GetVoiceSex(*v4);
    if ( v3 && v3 != 1 && v3 != 2 )
      v5 = (v2 != 0) + 3;
    else
      v5 = (v2 != 0) + 1;
    v9 = v5;
    wsprintfA(&Str1, "pc23v%dBod", v5);
    dword_51127C[v1] = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
    wsprintfA(&Str1, "pc23v%dlad", v9);
    dword_5115D0[v1] = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
    wsprintfA(&Str1, "pc23v%dlau", v9);
    dword_5115C0[v1] = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
    wsprintfA(&Str1, "pc23v%drh", v9);
    dword_51124C[v1] = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
    wsprintfA(&Str1, "pc23v%dlh", v9);
    dword_51126C[v1] = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
    wsprintfA(&Str1, "pc23v%dlhu", v9);
    dword_51125C[v1] = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
    v6 = *(_BYTE *)(pPlayers[v1] + 186);
    if ( v6 == 12 || v6 == 13 )
      dword_511208[*((_BYTE *)*(&ptr_A750C4 + v8) + 186)] = 0;
    dword_5115E0[*((_BYTE *)*(&ptr_A750C4 + v8) + 186)] = 0;
    byte_5111B8[v8] = 1;
  }
}

//----- (0043F0BD) --------------------------------------------------------
int __fastcall sub_43F0BD(int a1)
{
  int result; // eax@1
  char v2; // al@2
  int v3; // ebx@2
  int v4; // edi@2
  int v5; // ebx@2
  CHAR Str1; // [sp+0h] [bp-18h]@4
  int v7; // [sp+14h] [bp-4h]@1

  result = a1 - 1;
  v7 = a1;
  if ( a1 - 1 >= 0 )
  {
    v4 = 4 * a1 + 10965188;
    v5 = 4 * (a1 - 1);
    *(int *)((char *)dword_51127C + v5) = class17_LoadTexture(
                                            pClass17_Icons_LOD,
                                            (&off_4ECD68)[4 * *((_BYTE *)*(&ptr_A750C4 + a1) + 186)],
                                            2);
    *(int *)((char *)dword_5115D0 + v5) = class17_LoadTexture(
                                            pClass17_Icons_LOD,
                                            (&off_4ECC98)[4 * *(_BYTE *)(*(_DWORD *)v4 + 186)],
                                            2);
    *(int *)((char *)dword_5115C0 + v5) = class17_LoadTexture(
                                            pClass17_Icons_LOD,
                                            (&off_4ECD00)[4 * *(_BYTE *)(*(_DWORD *)v4 + 186)],
                                            2);
    *(int *)((char *)dword_51124C + v5) = class17_LoadTexture(
                                            pClass17_Icons_LOD,
                                            (&off_4ECDD0)[4 * *(_BYTE *)(*(_DWORD *)v4 + 186)],
                                            2);
    *(int *)((char *)dword_51126C + v5) = class17_LoadTexture(
                                            pClass17_Icons_LOD,
                                            (&off_4ECE38)[4 * *(_BYTE *)(*(_DWORD *)v4 + 186)],
                                            2);
    *(int *)((char *)dword_51125C + v5) = class17_LoadTexture(
                                            pClass17_Icons_LOD,
                                            (&off_4ECEA0)[4 * *(_BYTE *)(*(_DWORD *)v4 + 186)],
                                            2);
    v3 = *(_DWORD *)v4 + 186;
    v2 = *(_BYTE *)v3;
    if ( *(_BYTE *)v3 == 12 || v2 == 13 )
    {
      wsprintfA(&Str1, "pc%02dbrd", v2 + 1);
      v3 = *(_DWORD *)v4 + 186;
      dword_511208[*(_BYTE *)v3] = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
    }
    wsprintfA(&Str1, "item281pc%02d", *(_BYTE *)v3 + 1);
    dword_5115E0[*(_BYTE *)(*(_DWORD *)v4 + 186)] = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
    result = v7;
    byte_5111B8[v7] = 0;
  }
  return result;
}

//----- (0043F333) --------------------------------------------------------
int __thiscall sub_43F333(int this)
{
  int result; // eax@1
  unsigned __int8 v2; // zf@1
  unsigned __int8 v3; // sf@1
  int v4; // edx@2
  int v5; // eax@3
  int v6; // ebx@3
  int v7; // esi@4
  int v8; // [sp+0h] [bp-4h]@1

  result = 0;
  v2 = *(_DWORD *)(this + 4004) == 0;
  v3 = *(_DWORD *)(this + 4004) < 0;
  *(_DWORD *)(this + 341808) = 0;
  v8 = 0;
  if ( !(v3 | v2) )
  {
    v4 = this + 4008;
    do
    {
      v5 = *(_DWORD *)(this + 341808);
      v6 = 0;
      if ( v5 <= 0 )
      {
LABEL_7:
        *(_WORD *)(this + 2 * v5 + 341812) = *(_WORD *)v4;
        ++*(_DWORD *)(this + 341808);
      }
      else
      {
        v7 = this + 341812;
        while ( *(_WORD *)v7 != *(_WORD *)v4 )
        {
          ++v6;
          v7 += 2;
          if ( v6 >= v5 )
            goto LABEL_7;
        }
      }
      ++v8;
      v4 += 2252;
      result = v8;
    }
    while ( v8 < *(_DWORD *)(this + 4004) );
  }
  return result;
}

//----- (0043F39E) --------------------------------------------------------
void __thiscall sub_43F39E(int this)
{
  char *v1; // ecx@1
  double v2; // ST30_8@3
  double v3; // ST30_8@6
  double v4; // ST28_8@6
  int v5; // eax@4
  int v6; // eax@7
  int v7; // ebx@8
  int v8; // edi@8
  int v9; // esi@8
  unsigned __int8 v10; // sf@10
  unsigned __int8 v11; // of@10
  int v12; // [sp+18h] [bp-8h]@7
  char v13; // [sp+1Ch] [bp-4h]@3
  signed int v14; // [sp+1Ch] [bp-4h]@8

  sub_4407D9((int)&dword_51B6E0, this);
  dword_51B6DC = 0;
  dword_5187EC = 0;
  dword_5187E8 = 0;
  dword_5187E4 = 0;
  dword_5187E0 = 0;
  if ( !byte_4D8410[572] || !(*(_BYTE *)(LODWORD(pGame) + 3617) & 0x10) )
  {
    v2 = *(float *)&dword_AE31EC + 6.755399441055744e15;
    v13 = LOBYTE(v2);
    if ( qword_ACD944 <= 0 )
      v5 = 800;
    else
      v5 = 800 * (unsigned __int16)word_ACD94C;
    LOBYTE(v1) = byte_4E94D0;
    v4 = *(float *)&dword_AE31E4 + 6.755399441055744e15;
    v3 = *(float *)&dword_AE31E8 + 6.755399441055744e15;
    sub_467D88(
      (int)&unk_519AB8,
      dword_51B6E8,
      dword_51B6EC,
      dword_51B6F0,
      dword_51B6FC,
      v5,
      SLOBYTE(v4),
      SLOBYTE(v3),
      v13,
      v1);
  }
  sub_43F953();
  sub_44028F();
  sub_43FDED(0);
  v6 = 0;
  v12 = 0;
  if ( dword_56EEA8 > 0 )
  {
    do
    {
      v7 = word_56EEAC[v6];
      v14 = 0;
      v9 = dword_6BE654 + 116 * word_56EEAC[v6];
      v8 = *(_DWORD *)(v9 + 72);
      if ( *(_WORD *)(v9 + 68) > 0 )
      {
        do
          sub_43FA33(*(_WORD *)(v8 + 2 * v14++), v7);
        while ( v14 < *(_WORD *)(v9 + 68) );
      }
      v6 = v12 + 1;
      compile_error;//v11 = __SETO__(v12 + 1, dword_56EEA8);
      v10 = v12++ + 1 - dword_56EEA8 < 0;
    }
    while ( v10 ^ v11 );
  }
  sub_43F515();
  CGame_sub_44F192(pGame);
}

//----- (0043F515) --------------------------------------------------------
void __cdecl sub_43F515()
{
  int v0; // edi@1
  _UNKNOWN *v1; // esi@2

  v0 = 0;
  if ( dword_5187E0 > 0 )
  {
    v1 = &unk_51227A;
    do
    {
      if ( *((_BYTE *)v1 - 12) & 2 || dword_6BE360 == 1 && !*((_WORD *)v1 - 7) )
        *(_WORD *)v1 = 0;
      else
        *(_WORD *)v1 = sub_43F55F((int)((char *)v1 - 42), -1);
      ++v0;
      v1 = (char *)v1 + 52;
    }
    while ( v0 < dword_5187E0 );
  }
}

//----- (0043F55F) --------------------------------------------------------
signed int __fastcall sub_43F55F(int a1, signed int a2)
{
  int v2; // eax@1
  signed int v3; // ecx@2
  float v5; // ST08_4@6
  float v6; // ST04_4@6
  float v7; // ST00_4@6

  v2 = a1;
  if ( dword_6BE360 == 1 )
  {
    v3 = *(_WORD *)(116 * *(_WORD *)(a1 + 28) + dword_6BE654 + 98);
  }
  else
  {
    if ( a2 == -1 )
      v3 = *(_WORD *)(a1 + 42);
    else
      v3 = a2;
  }
  v5 = (double)*(_WORD *)(v2 + 36);
  v6 = (double)*(_WORD *)(v2 + 34);
  v7 = (double)*(_WORD *)(v2 + 32);
  return sub_43F5C8(v3, *(_WORD *)(v2 + 28), v7, v6, v5);
}

//----- (0043F5C8) --------------------------------------------------------
signed int __fastcall sub_43F5C8(signed int a1, int a2, float a3, float a4, float a5)
{
  signed int v5; // edi@1
  int v6; // esi@1
  signed int *v7; // ebx@2
  int v8; // eax@6
  unsigned int v9; // ecx@6
  int v10; // ebx@6
  unsigned int v11; // edx@9
  unsigned int v12; // edx@11
  signed int v13; // ecx@12
  int v14; // ecx@17
  int v15; // esi@17
  int v16; // esi@20
  int v17; // ebx@21
  int v18; // eax@24
  unsigned int v19; // ecx@24
  int v20; // ebx@24
  int v21; // edx@25
  unsigned int v22; // edx@27
  unsigned int v23; // edx@29
  signed int v24; // ecx@30
  unsigned __int8 v25; // sf@32
  unsigned __int8 v26; // of@32
  _UNKNOWN *v27; // esi@34
  int v28; // ebx@35
  int v29; // eax@38
  unsigned int v30; // ecx@38
  int v31; // ebx@38
  int v32; // edx@39
  unsigned int v33; // edx@41
  unsigned int v34; // edx@43
  signed int v35; // ecx@44
  int v37; // [sp+Ch] [bp-18h]@4
  int v38; // [sp+Ch] [bp-18h]@17
  int v39; // [sp+Ch] [bp-18h]@37
  int v40; // [sp+10h] [bp-14h]@5
  int v41; // [sp+10h] [bp-14h]@23
  int v42; // [sp+10h] [bp-14h]@36
  int v43; // [sp+14h] [bp-10h]@3
  int v44; // [sp+14h] [bp-10h]@22
  unsigned int v45; // [sp+18h] [bp-Ch]@12
  unsigned int v46; // [sp+18h] [bp-Ch]@30
  unsigned int v47; // [sp+18h] [bp-Ch]@44
  signed int *v48; // [sp+1Ch] [bp-8h]@2
  int v49; // [sp+1Ch] [bp-8h]@17
  int v50; // [sp+20h] [bp-4h]@1
  int v51; // [sp+20h] [bp-4h]@17
  int v52; // [sp+20h] [bp-4h]@33

  v50 = 0;
  v6 = a2;
  v5 = a1;
  if ( dword_51B6DC > 0 )
  {
   v7 = (signed int *)&array_519ABC[0].word_000006;
    v48 = (signed int *)&array_519ABC[0].word_000006;
    do
    {
      v43 = abs((signed __int64)((double)*((_WORD *)v7 - 3) - a3));
      if ( v43 <= *(_WORD *)v7 )
      {
        v37 = abs((signed __int64)((double)*((_WORD *)v7 - 2) - a4));
        if ( v37 <= *(_WORD *)v7 )
        {
          v40 = abs((signed __int64)((double)*((_WORD *)v7 - 1) - a5));
          if ( v40 <= *(_WORD *)v7 )
          {
            v8 = v43;
            v10 = v37;
            v9 = v40;
            if ( v43 < v37 )
            {
              v8 = v37;
              v10 = v43;
            }
            if ( v8 < v40 )
            {
              v11 = v8;
              v8 = v40;
              v9 = v11;
            }
            if ( v10 < (signed int)v9 )
            {
              v12 = v9;
              v9 = v10;
              v10 = v12;
            }
            v45 = ((unsigned int)(11 * v10) >> 5) + (v9 >> 2) + v8;
            v13 = *(_WORD *)v48;
            if ( (signed int)v45 < v13 )
              v5 = v5 + ((unsigned __int64)(30i64 * (signed int)(v45 << 16) / v13) >> 16) - 30;
            v7 = v48;
          }
        }
      }
      ++v50;
      v7 = (signed int *)((char *)v7 + 18);
      v48 = v7;
    }
    while ( v50 < dword_51B6DC );
  }
  if ( dword_6BE360 == 1 )
  {
    v15 = dword_6BE654 + 116 * v6;
    v14 = 0;
    v51 = 0;
    v38 = v15;
    v49 = *(_WORD *)(v15 + 84);
    if ( (signed int)*(_WORD *)(v15 + 84) > 0 )
    {
      while ( 1 )
      {
        v16 = dword_6BE65C + 16 * *(_WORD *)(*(_DWORD *)(v15 + 88) + 2 * v14);
        if ( !(*(_BYTE *)(v16 + 12) & 8) )
        {
          v17 = abs((signed __int64)((double)*(_WORD *)v16 - a3));
          if ( v17 <= *(_WORD *)(v16 + 6) )
          {
            v44 = abs((signed __int64)((double)*(_WORD *)(v16 + 2) - a4));
            if ( v44 <= *(_WORD *)(v16 + 6) )
            {
              v41 = abs((signed __int64)((double)*(_WORD *)(v16 + 4) - a5));
              if ( v41 <= *(_WORD *)(v16 + 6) )
              {
                v18 = v17;
                v20 = v44;
                v19 = v41;
                if ( v18 < v44 )
                {
                  v21 = v18;
                  v18 = v44;
                  v20 = v21;
                }
                if ( v18 < v41 )
                {
                  v22 = v18;
                  v18 = v41;
                  v19 = v22;
                }
                if ( v20 < (signed int)v19 )
                {
                  v23 = v19;
                  v19 = v20;
                  v20 = v23;
                }
                v46 = ((unsigned int)(11 * v20) >> 5) + (v19 >> 2) + v18;
                v24 = *(_WORD *)(v16 + 6);
                if ( (signed int)v46 < v24 )
                  v5 = v5 + ((unsigned __int64)(30i64 * (signed int)(v46 << 16) / v24) >> 16) - 30;
              }
            }
          }
        }
        v14 = v51 + 1;
        compile_error;//v26 = __SETO__(v51 + 1, v49);
        v25 = v51++ + 1 - v49 < 0;
        if ( !(v25 ^ v26) )
          break;
        v15 = v38;
      }
    }
  }
  v52 = 0;
  if ( dword_519AB4 > 0 )
  {
   v27 = &array_5187F4[0].word_000004;
    do
    {
      v28 = abs((signed __int64)((double)*((_WORD *)v27 - 3) - a3));
      if ( v28 <= *(_WORD *)v27 )
      {
        v42 = abs((signed __int64)((double)*((_WORD *)v27 - 2) - a4));
        if ( v42 <= *(_WORD *)v27 )
        {
          v39 = abs((signed __int64)((double)*((_WORD *)v27 - 1) - a5));
          if ( v39 <= *(_WORD *)v27 )
          {
            v29 = v28;
            v31 = v42;
            v30 = v39;
            if ( v29 < v42 )
            {
              v32 = v29;
              v29 = v42;
              v31 = v32;
            }
            if ( v29 < v39 )
            {
              v33 = v29;
              v29 = v39;
              v30 = v33;
            }
            if ( v31 < (signed int)v30 )
            {
              v34 = v30;
              v30 = v31;
              v31 = v34;
            }
            v47 = ((unsigned int)(11 * v31) >> 5) + (v30 >> 2) + v29;
            v35 = *(_WORD *)v27;
            if ( (signed int)v47 < v35 )
              v5 = v5 + ((unsigned __int64)(30i64 * (signed int)(v47 << 16) / v35) >> 16) - 30;
          }
        }
      }
      ++v52;
      v27 = (char *)v27 + 12;
    }
    while ( v52 < dword_519AB4 );
  }
  if ( v5 <= 31 )
  {
    if ( v5 < 0 )
      v5 = 0;
  }
  else
  {
    v5 = 31;
  }
  return v5;
}

//----- (0043F953) --------------------------------------------------------
int __cdecl sub_43F953()
{
  int v1; // edx@2

  class37_global0.dword_000000 = 0;
  if ( dword_51B6FC )
  {
    word_51C720[0] = dword_51B6FC;
    word_51C728 = dword_51B740;
    word_51C726 = dword_51B73C;
    word_51C724 = dword_51B738;
    word_51C722 = dword_51B734;
    sub_43F9E1((int)&unk_51C72C, dword_51B734, (signed __int16)dword_51B738, dword_51B73C, (signed __int16)dword_51B740);
    word_51CEC4 = -1;
    dword_51CEC8 = -1;
    dword_51C71C = 1;
    sub_440639(0, v1);
  }
  return sub_43F333(&class37_global0);
}

//----- (0043F9E1) --------------------------------------------------------
int __thiscall sub_43F9E1(int this, __int16 a2, signed int a3, __int16 a4, signed int a5)
{
  int result; // eax@1
  signed int v6; // edx@1

  *(_DWORD *)this = a3;
  *(_DWORD *)(this + 4) = a5;
  v6 = 0;
  result = this + 984;
  do
  {
    if ( v6 < a3 || v6 > a5 )
    {
      *(_WORD *)result = -1;
      *(_WORD *)(result - 960) = 640;
    }
    else
    {
      *(_WORD *)(result - 960) = a2;
      *(_WORD *)result = a4;
    }
    ++v6;
    result += 2;
  }
  while ( v6 < 480 );
  return result;
}

//----- (0043FA33) --------------------------------------------------------
void __fastcall sub_43FA33(int a1, int a2)
{
  __int16 *v2; // esi@1
  __int16 v3; // ax@2
  int v4; // ebx@2
  double v5; // st7@3
  int v6; // edi@5
  int v7; // eax@5
  int v8; // edx@5
  int v9; // edi@5
  int v10; // eax@7
  int v11; // esi@7
  int v12; // eax@7
  int v13; // eax@7
  int v14; // ebx@16
  char *v15; // ecx@17
  char v16; // zf@18
  int v17; // eax@19
  double v18; // st7@19
  float v19; // eax@19
  signed __int64 v20; // qtt@19
  signed __int64 v21; // qtt@20
  int v22; // edx@21
  int v23; // eax@21
  int Dst; // [sp+Ch] [bp-A0h]@3
  float v25; // [sp+10h] [bp-9Ch]@3
  float v26; // [sp+14h] [bp-98h]@3
  float v27; // [sp+18h] [bp-94h]@3
  float v28; // [sp+1Ch] [bp-90h]@3
  float v29; // [sp+20h] [bp-8Ch]@3
  float v30; // [sp+24h] [bp-88h]@3
  int v31; // [sp+28h] [bp-84h]@3
  int v32; // [sp+2Ch] [bp-80h]@3
  int v33; // [sp+30h] [bp-7Ch]@3
  float v34; // [sp+34h] [bp-78h]@3
  double v35; // [sp+74h] [bp-38h]@19
  int v36; // [sp+7Ch] [bp-30h]@1
  int v37; // [sp+80h] [bp-2Ch]@5
  int v38; // [sp+84h] [bp-28h]@5
  int v39; // [sp+88h] [bp-24h]@5
  int v40; // [sp+8Ch] [bp-20h]@7
  float v41; // [sp+90h] [bp-1Ch]@1
  __int16 v42; // [sp+94h] [bp-18h]@17
  int v43; // [sp+98h] [bp-14h]@15
  __int16 v44; // [sp+9Ch] [bp-10h]@17
  int v45; // [sp+A0h] [bp-Ch]@15
  int X; // [sp+A4h] [bp-8h]@15
  int v47; // [sp+A8h] [bp-4h]@5

  v36 = a1;
  LODWORD(v41) = a2;
  v2 = &array_6836D0[a1];
  if ( !(*((_BYTE *)v2 + 2) & 0x20) )
  {
    v4 = pDecorationDescriptionList->pDescriptions + 84 * *v2;
    v3 = *(_WORD *)(v4 + 74);
    if ( (_BYTE)v3 >= 0 )
    {
      if ( !(v3 & 2) )
      {
        v7 = *((_DWORD *)v2 + 1);
        v8 = *((_DWORD *)v2 + 3);
        v37 = *((_DWORD *)v2 + 2);
        v39 = v7;
        v38 = v8;
        v9 = *((_DWORD *)v2 + 4)
           + (pClass59_global->dword_001860 >> 3)
           - sub_45281E(pClass59_global, v7 - dword_51B6E8, v37 - dword_51B6EC);
        v47 = dword_51B6E0;
        v6 = ((pClass59_global->dword_001860 + v9) >> 8) & 7;
        if ( dword_ACD834 == 1 )
          v47 = pClass24_global2->dword_000024;
        v12 = abs(*((_DWORD *)v2 + 1) + *((_DWORD *)v2 + 2));
        v13 = CSpriteFrameTable_fn1(pSpriteFrameTable, *(_WORD *)(v4 + 72), v47 + v12);
        v40 = 0;
        v11 = v13;
        v10 = *(_DWORD *)(v13 + 44);
        if ( v10 & 2 )
          v40 = 2;
        if ( v10 & 0x40000 )
          v40 |= 0x40u;
        if ( v10 & 0x20000 )
          LOBYTE(v40) = v40 | 0x80;
        if ( (256 << v6) & v10 )
          v40 |= 4u;
        if ( sub_43669D(v39, v37, v38, &X, (int)&v45, (int)&v43, 1) )
        {
          v14 = abs(X);
          if ( v14 >= abs(v45) )
          {
            sub_436A9A(pGame->class08_obj, X, v45, v43, (int)&v42, (int)&v44);
            v15 = &array_512250[dword_5187E0];
            if ( dword_5187E0 < 500 )
            {
              ++dword_5187E0;
              ++dword_5187EC;
              v16 = pD3DRenderer->dword_040088 == 0;
              *((_WORD *)v15 + 12) = *(_WORD *)(v11 + 2 * v6 + 24);
              *((_WORD *)v15 + 13) = *(_WORD *)(v11 + 52);
              *((_WORD *)v15 + 14) = LOWORD(v41);
              if ( v16 )
              {
                LODWORD(v21) = unk_51B720 << 16;
                HIDWORD(v21) = unk_51B720 >> 16;
                v47 = v21 / X;
                LODWORD(v41) = *(_DWORD *)(v11 + 40);
                v47 = v21 / X;
                *(_DWORD *)v15 = (unsigned __int64)(SLODWORD(v41) * (signed int)(v21 / X)) >> 16;
                v47 = (unsigned __int64)(*(_DWORD *)(v11 + 40) * v47) >> 16;
              }
              else
              {
                v17 = &pGame->class08_obj;
                *((float *)v15 + 2) = *(float *)(pGame->class08_obj + 208);
                v18 = *(float *)(*(_DWORD *)v17 + 212);
                LODWORD(v19) = *((_DWORD *)v15 + 2);
                *((float *)v15 + 3) = v18;
                v41 = v19;
                v35 = v19 + 6.755399441055744e15;
                LODWORD(v20) = 0;
                HIDWORD(v20) = LODWORD(v35) << 16 >> 16;
                v47 = v20 / X;
                LODWORD(v41) = *(_DWORD *)(v11 + 40);
                v47 = (unsigned __int64)(SLODWORD(v41) * (signed int)(v20 / X)) >> 16;
                *(_DWORD *)v15 = (unsigned __int64)(SLODWORD(v41) * (signed int)(v20 / X)) >> 16;
                LODWORD(v41) = *((_DWORD *)v15 + 3);
                v35 = v41 + 6.755399441055744e15;
                LODWORD(v20) = 0;
                HIDWORD(v20) = LODWORD(v35) << 16 >> 16;
                v47 = v20 / X;
                v47 = (unsigned __int64)(*(_DWORD *)(v11 + 40) * (signed int)(v20 / X)) >> 16;
              }
              HIWORD(v22) = HIWORD(X);
              *((_DWORD *)v15 + 1) = v47;
              *((_WORD *)v15 + 15) = v40;
              *((_WORD *)v15 + 16) = v39;
              *((_WORD *)v15 + 17) = v37;
              *((_WORD *)v15 + 18) = v38;
              *((_WORD *)v15 + 19) = v42;
              *((_WORD *)v15 + 20) = v44;
              v23 = 8 * v36;
              LOBYTE(v23) = 8 * v36 | 5;
              LOWORD(v22) = 0;
              *((_DWORD *)v15 + 11) = 0;
              *((_DWORD *)v15 + 4) = v22 + v23;
              *((_DWORD *)v15 + 12) = v11;
            }
          }
        }
      }
    }
    else
    {
      memset(&Dst, 0, 0x68u);
      v5 = (double)*((signed int *)v2 + 1);
      Dst = 1036;
      v31 = 16727070;
      v25 = v5;
      v26 = (double)*((signed int *)v2 + 2);
      v27 = (double)*((signed int *)v2 + 3);
      v28 = 0.0;
      v29 = 0.0;
      v30 = 0.0;
      v34 = 1.0;
      v32 = (rand() & 0x80) + 128;
      v33 = class17_LoadTexture(pClass17_Bitmaps_LOD, "effpar01", 0);
      sub_48AB23(pGame->class02_obj, (int)&Dst);
    }
  }
}

//----- (0043FDED) --------------------------------------------------------
function_error;//int __usercall sub_43FDED<eax>(int a1<esi>)
int __fastcall sub_43FDED(int a1)
{
  int result; // eax@1
  _UNKNOWN *v2; // edi@2
  __int16 v3; // ax@3
  __int16 v4; // cx@5
  int v5; // esi@5
  int v6; // eax@5
  int v7; // eax@7
  signed int v8; // eax@10
  int v9; // eax@16
  char *v10; // eax@18
  int v11; // ebx@18
  int v12; // ecx@28
  int v13; // ecx@35
  char v14; // zf@35
  int v15; // eax@36
  double v16; // st7@36
  float v17; // eax@36
  double v18; // ST30_8@36
  signed __int64 v19; // qtt@36
  int v20; // ST5C_4@36
  signed __int64 v21; // qtt@37
  int v22; // ST5C_4@37
  signed __int16 v23; // cx@39
  int v24; // ST50_4@40
  signed int v25; // ecx@40
  unsigned __int8 v26; // zf@44
  unsigned __int8 v27; // sf@44
  int v28; // edx@44
  int v29; // edx@44
  int v30; // ecx@44
  int v31; // [sp-8h] [bp-5Ch]@15
  int v32; // [sp+1Ch] [bp-38h]@5
  int v33; // [sp+20h] [bp-34h]@5
  int v34; // [sp+24h] [bp-30h]@5
  int v35; // [sp+28h] [bp-2Ch]@5
  __int16 v36; // [sp+2Ch] [bp-28h]@5
  int v37; // [sp+2Ch] [bp-28h]@36
  int v38; // [sp+2Ch] [bp-28h]@40
  signed int v39; // [sp+30h] [bp-24h]@1
  int v40; // [sp+34h] [bp-20h]@2
  signed __int16 v41; // [sp+3Ch] [bp-18h]@18
  __int16 v42; // [sp+40h] [bp-14h]@34
  __int16 v43; // [sp+44h] [bp-10h]@34
  int v44; // [sp+48h] [bp-Ch]@32
  int v45; // [sp+4Ch] [bp-8h]@32
  int X; // [sp+50h] [bp-4h]@32

  result = 0;
  v39 = 0;
  if ( (signed int)uNumActors > 0 )
  {
    v40 = 0;
    v2 = pActors->byte_000024;
    do
    {
      v3 = *((_WORD *)v2 + 70);
      *(_DWORD *)v2 &= 0xFFFFFFF7u;
      if ( v3 == 11 || v3 == 19 )
        goto LABEL_48;
      v36 = *((_WORD *)v2 + 61);
      v34 = *((_WORD *)v2 + 54);
      v35 = *((_WORD *)v2 + 53);
      v33 = *((_WORD *)v2 + 55);
      v6 = sub_45281E(pClass59_global, v35 - dword_51B6E8, v34 - dword_51B6EC);
      LOWORD(a1) = *((_WORD *)v2 + 59);
      v4 = *((_WORD *)v2 + 71);
      v5 = ((pClass59_global->dword_001860 + (pClass59_global->dword_001860 >> 3) + a1 - v6) >> 8) & 7;
      v32 = v5;
      if ( dword_ACD834 )
      {
        if ( v4 == 1 )
        {
          v7 = pClass24_global2->dword_000024;
          goto LABEL_10;
        }
      }
      else
      {
        if ( v4 == 1 )
        {
          v7 = dword_51B6E0;
LABEL_10:
          v8 = v40 + v7;
          goto LABEL_12;
        }
      }
      v8 = *((_DWORD *)v2 + 37);
LABEL_12:
      if ( *((_QWORD *)v2 + 32) > 0i64 || *((_QWORD *)v2 + 34) > 0i64 )
        v8 = 0;
      v31 = *((_WORD *)v2 + v4 + 76);
      if ( *((_WORD *)v2 + 70) == 16 )
        v9 = CSpriteFrameTable_fn2(pSpriteFrameTable, v31, v8);
      else
        v9 = CSpriteFrameTable_fn1(pSpriteFrameTable, v31, v8);
      v41 = 0;
      v11 = v9;
      v10 = *(char **)(v9 + 44);
      if ( (_BYTE)v10 & 2 )
        v41 = 2;
      if ( (unsigned int)v10 & 0x40000 )
        v41 |= 0x40u;
      if ( (unsigned int)v10 & 0x20000 )
        LOBYTE(v41) = v41 | 0x80;
      a1 = 256 << v5;
      if ( a1 & (unsigned int)v10 )
        v41 |= 4u;
      if ( *(_WORD *)(v11 + 48) )
      {
        LOBYTE(v10) = byte_4E94D3;
        sub_467D88((int)&unk_519AB8, v35, v34, v33, v36, *(_WORD *)(v11 + 48), -1, -1, -1, v10);
      }
      v12 = 0;
      if ( dword_56EEA8 <= 0 )
        goto LABEL_48;
      while ( word_56EEAC[v12] != *((_WORD *)v2 + 61) )
      {
        ++v12;
        if ( v12 >= dword_56EEA8 )
          goto LABEL_48;
      }
      if ( !sub_43669D(v35, v34, v33, &X, (int)&v45, (int)&v44, 1) || (a1 = abs(X), a1 < abs(v45)) )
        goto LABEL_48;
      sub_436A9A(pGame->class08_obj, X, v45, v44, (int)&v43, (int)&v42);
      result = dword_5187E0;
      a1 = &array_512250[dword_5187E0];
      if ( dword_5187E0 >= 500 )
        return result;
      ++dword_5187E0;
      ++dword_5187E4;
      v13 = (int)((char *)v2 - 36);
      *(_DWORD *)v2 |= 8u;
      v14 = pD3DRenderer->dword_040088 == 0;
      *(_WORD *)(a1 + 24) = *(_WORD *)(v11 + 2 * v32 + 24);
      *(_WORD *)(a1 + 26) = *(_WORD *)(v11 + 52);
      *(_WORD *)(a1 + 28) = v36;
      if ( v14 )
      {
        LODWORD(v21) = unk_51B720 << 16;
        HIDWORD(v21) = unk_51B720 >> 16;
        v22 = v21 / X;
        *(_DWORD *)a1 = (unsigned __int64)(*(_DWORD *)(v11 + 40) * (signed int)(v21 / X)) >> 16;
        v37 = (unsigned __int64)(*(_DWORD *)(v11 + 40) * v22) >> 16;
      }
      else
      {
        v15 = &pGame->class08_obj;
        *(float *)(a1 + 8) = *(float *)(pGame->class08_obj + 208);
        v16 = *(float *)(*(_DWORD *)v15 + 212);
        LODWORD(v17) = *(_DWORD *)(a1 + 8);
        *(float *)(a1 + 12) = v16;
        v18 = v17 + 6.755399441055744e15;
        LODWORD(v19) = 0;
        HIDWORD(v19) = LODWORD(v18) << 16 >> 16;
        v20 = v19 / X;
        *(_DWORD *)a1 = (unsigned __int64)(*(_DWORD *)(v11 + 40) * (signed int)(v19 / X)) >> 16;
        v37 = (unsigned __int64)(*(_DWORD *)(v11 + 40) * v20) >> 16;
      }
      *(_DWORD *)(a1 + 4) = v37;
      if ( *(_QWORD *)(v13 + 260) <= 0i64 )
      {
        if ( *(_QWORD *)(v13 + 372) <= 0i64 )
          goto LABEL_44;
        v38 = (unsigned __int64)(sub_4A806F((int)((char *)v2 - 36)) * *(_DWORD *)(a1 + 4)) >> 16;
      }
      else
      {
        v23 = *(_WORD *)(v13 + 268);
        if ( !v23 )
          goto LABEL_44;
        v24 = (unsigned __int64)(65536 / (unsigned __int16)v23 * *(_DWORD *)a1) >> 16;
        v25 = *((_WORD *)v2 + 116);
        *(_DWORD *)a1 = v24;
        v38 = (unsigned __int64)(65536 / v25 * *(_DWORD *)(a1 + 4)) >> 16;
      }
      *(_DWORD *)(a1 + 4) = v38;
LABEL_44:
      HIWORD(v28) = HIWORD(X);
      *(_WORD *)(a1 + 32) = v35;
      *(_WORD *)(a1 + 34) = v34;
      *(_WORD *)(a1 + 36) = v33;
      *(_WORD *)(a1 + 38) = v43;
      *(_WORD *)(a1 + 40) = v42;
      LOWORD(v28) = 0;
      *(_DWORD *)(a1 + 16) = v28 + (8 * v39 | 3);
      v29 = monster_list[1];
      v30 = 152 * *((_WORD *)v2 + 30);
      v26 = *((_DWORD *)v2 + 65) == 0;
      v27 = *((_DWORD *)v2 + 65) < 0;
      *(_WORD *)(a1 + 30) = v41;
      *(_DWORD *)(a1 + 48) = v11;
      *(_DWORD *)(a1 + 44) = *(_DWORD *)(v30 + v29 - 144);
      if ( !v27 )
      {
        if ( !(v27 | v26) || *((_DWORD *)v2 + 64) )
          *(_WORD *)(a1 + 30) = v41;
      }
LABEL_48:
      ++v39;
      v40 += 32;
      result = v39;
      v2 = (char *)v2 + 836;
    }
    while ( v39 < (signed int)uNumActors );
  }
  return result;
}

//----- (0044028F) --------------------------------------------------------
void __cdecl sub_44028F()
{
  __int16 *v0; // edi@2
  int v1; // ebx@4
  __int16 v2; // ax@5
  __int16 v3; // ax@12
  int v4; // edx@12
  int v5; // ecx@12
  int v6; // ebx@12
  char *v7; // esi@12
  int v8; // eax@12
  int v9; // eax@12
  int v10; // ecx@12
  char *v11; // eax@20
  char v12; // zf@26
  int v13; // eax@27
  double v14; // st7@27
  float v15; // eax@27
  double v16; // ST30_8@27
  signed __int64 v17; // qtt@27
  int v18; // ST5C_4@27
  signed __int64 v19; // qtt@28
  int v20; // ST5C_4@28
  int v21; // edx@29
  __int16 v22; // ax@29
  int v23; // eax@29
  char v24; // zf@29
  int v25; // [sp+1Ch] [bp-40h]@12
  int v26; // [sp+20h] [bp-3Ch]@4
  __int16 v27; // [sp+28h] [bp-34h]@12
  int v28; // [sp+2Ch] [bp-30h]@12
  int v29; // [sp+30h] [bp-2Ch]@12
  int v30; // [sp+34h] [bp-28h]@12
  int v31; // [sp+38h] [bp-24h]@12
  int v32; // [sp+38h] [bp-24h]@27
  int v34; // [sp+40h] [bp-1Ch]@12
  signed __int16 v35; // [sp+44h] [bp-18h]@14
  __int16 v36; // [sp+48h] [bp-14h]@25
  __int16 v37; // [sp+4Ch] [bp-10h]@25
  int v38; // [sp+50h] [bp-Ch]@24
  int v39; // [sp+54h] [bp-8h]@24
  int v40; // [sp+58h] [bp-4h]@24
 int i;

  for (i = 0; i < uNumElementsIn665230; ++i)
  {
   v0 = &array_665230[i].word_00001C;

      if ( *(v0 - 13) )
      {
        v1 = pObjectDescriptionList->pDescriptions + 56 * *(v0 - 13);
        v26 = v1;
        if ( !(*(_BYTE *)(v1 + 38) & 1) )
        {
          if ( ((v2 = *(v0 - 14), v2 < 1000) || v2 >= 10000) && (v2 < 500 || v2 >= 600) && (v2 < 811 || v2 >= 815)
            || class06_sub_4A81CA(pGame->class06_obj, (int)(v0 - 14)) )
          {
            v27 = *v0;
            v30 = *((_DWORD *)v0 - 6);
            v29 = *((_DWORD *)v0 - 5);
            v34 = *((_DWORD *)v0 - 4);
            v7 = &array_512250[dword_5187E0];
            v8 = CSpriteFrameTable_fn1(pSpriteFrameTable, *(_WORD *)(v1 + 40), v0[1]);
            v6 = v8;
            v25 = v8;
            v31 = *(_DWORD *)(v8 + 44);
            v28 = *(_WORD *)(v8 + 48) * v0[3];
            v9 = sub_45281E(pClass59_global, *((_DWORD *)v0 - 6) - dword_51B6E8, *((_DWORD *)v0 - 5) - dword_51B6EC);
            LOWORD(v10) = *(v0 - 3);
            v4 = v31;
            v5 = ((pClass59_global->dword_001860 + (pClass59_global->dword_001860 >> 3) + v10 - v9) >> 8) & 7;
            v3 = *(_WORD *)(v6 + 2 * v5 + 24);
            *((_WORD *)v7 + 12) = v3;
            if ( v31 & 0x20 )
            {
              v4 = v31;
              compile_error;//v34 -= (signed int)((unsigned __int64)(*(_DWORD *)(v6 + 40) * pClass17_Sprites_LOD->array_00024C[1 + 20 * v3]) >> 16) >> 1;
            }
            v35 = 0;
            if ( v4 & 2 )
              v35 = 2;
            if ( v4 & 0x40000 )
              v35 |= 0x40u;
            if ( v4 & 0x20000 )
              LOBYTE(v35) = v35 | 0x80;
            v11 = (char *)(256 << v5);
            if ( (256 << v5) & v4 )
              v35 |= 4u;
            if ( v28 )
            {
              LOBYTE(v11) = byte_4E94D3;
              sub_467D88(
                (int)&unk_519AB8,
                v30,
                v29,
                v34,
                v27,
                v28,
                *(_BYTE *)(v26 + 50),
                *(_BYTE *)(v26 + 51),
                *(_BYTE *)(v26 + 52),
                v11);
            }
            if ( sub_43669D(v30, v29, v34, &v40, (int)&v39, (int)&v38, 1) )
            {
              sub_436A9A(pGame->class08_obj, v40, v39, v38, (int)&v37, (int)&v36);
              if ( dword_5187E0 >= 500 )
                return;
              ++dword_5187E0;
              ++dword_5187E4;
              *((_BYTE *)v0 - 2) |= 1u;
              v12 = pD3DRenderer->dword_040088 == 0;
              *((_WORD *)v7 + 13) = *(_WORD *)(v25 + 52);
              *((_WORD *)v7 + 14) = v27;
              if ( v12 )
              {
                LODWORD(v19) = unk_51B720 << 16;
                HIDWORD(v19) = unk_51B720 >> 16;
                v20 = v19 / v40;
                *(_DWORD *)v7 = (unsigned __int64)(*(_DWORD *)(v25 + 40) * (signed int)(v19 / v40)) >> 16;
                v32 = (unsigned __int64)(*(_DWORD *)(v25 + 40) * v20) >> 16;
              }
              else
              {
                v13 = &pGame->class08_obj;
                *((float *)v7 + 2) = *(float *)(pGame->class08_obj + 208);
                v14 = *(float *)(*(_DWORD *)v13 + 212);
                LODWORD(v15) = *((_DWORD *)v7 + 2);
                *((float *)v7 + 3) = v14;
                v16 = v15 + 6.755399441055744e15;
                LODWORD(v17) = 0;
                HIDWORD(v17) = LODWORD(v16) << 16 >> 16;
                v18 = v17 / v40;
                *(_DWORD *)v7 = (unsigned __int64)(*(_DWORD *)(v25 + 40) * (signed int)(v17 / v40)) >> 16;
                v32 = (unsigned __int64)(*(_DWORD *)(v25 + 40) * v18) >> 16;
              }
              HIWORD(v21) = HIWORD(v40);
              *((_DWORD *)v7 + 1) = v32;
              *((_WORD *)v7 + 15) = v35;
              *((_WORD *)v7 + 16) = v30;
              *((_WORD *)v7 + 17) = v29;
              *((_WORD *)v7 + 18) = v34;
              *((_WORD *)v7 + 19) = v37;
              v22 = v36;
              *((_DWORD *)v7 + 11) = 0;
              *((_WORD *)v7 + 20) = v22;
              LOWORD(v21) = 0;
              v23 = 8 * i;
              LOBYTE(v23) = 8 * i | 2;
              *((_DWORD *)v7 + 12) = v25;
              v24 = (*((_BYTE *)v0 - 2) & 0x20) == 0;
              *((_DWORD *)v7 + 4) = v21 + v23;
              if ( !v24 )
              {
                if ( !pD3DRenderer->dword_040088 )
                  *((_DWORD *)v7 + 4) = 0;
              }
            }
          }
        }
      }
      v0 += 56;
  }
}

//----- (00440639) --------------------------------------------------------
char __fastcall sub_440639(signed int a1, int a2)
{
  int v2; // eax@1
  signed int v3; // ebx@1
  int v4; // edi@1
  int v5; // esi@1

  v3 = a1;
  LOBYTE(v2) = -52 * a1;
  v4 = 0;
  v5 = dword_6BE654 + 116 * word_51C720[1126 * a1];
  if ( pD3DRenderer->dword_040088 )
  {
    if ( *(_WORD *)(v5 + 46) > 0 )
    {
      do
      {
        sub_4B0EA8(&class37_global0, v3, *(_WORD *)(*(_DWORD *)(v5 + 48) + 2 * v4));
        v2 = *(_WORD *)(v5 + 46);
        ++v4;
      }
      while ( v4 < v2 );
    }
  }
  else
  {
    if ( *(_WORD *)(v5 + 46) > 0 )
    {
      do
      {
        sub_4AFB86(&class37_global0, v3, *(_WORD *)(*(_DWORD *)(v5 + 48) + 2 * v4));
        v2 = *(_WORD *)(v5 + 46);
        ++v4;
      }
      while ( v4 < v2 );
    }
  }
  if ( *(_BYTE *)v5 & 0x10 )
    LOBYTE(v2) = sub_4406BC(v3, *(_WORD *)(v5 + 100));
  return v2;
}

//----- (004406BC) --------------------------------------------------------
char __fastcall sub_4406BC(signed int a1, int a2)
{
  int v2; // eax@2
  int v3; // ecx@2
  int v4; // edi@2
  int v5; // esi@2
  __int16 v6; // ax@6
  int v7; // ebx@10
  int v8; // ebp@10
  __int16 v9; // di@18
  signed int v11; // [sp+10h] [bp-Ch]@1
  bool v12; // [sp+14h] [bp-8h]@5
  __int16 *v13; // [sp+18h] [bp-4h]@1

  v11 = a1;
  v13 = &word_51C720[1126 * a1];
  while ( 1 )
  {
    v5 = dword_6BE654 + 116 * *v13;
    v4 = dword_6BE66C + 8 * a2;
    v2 = dword_6BE644 + 96 * *(_WORD *)(*(_DWORD *)(v5 + 48) + 2 * *(_WORD *)(v4 + 4));
    v3 = *(_DWORD *)(v2 + 28)
       + dword_51B6E8 * *(_DWORD *)(v2 + 16)
       + dword_51B6EC * *(_DWORD *)(v2 + 20)
       + dword_51B6F0 * *(_DWORD *)(v2 + 24);
    if ( *(_BYTE *)(v2 + 44) & 1 )
    {
      if ( *(_WORD *)(v2 + 76) != *v13 )
        v3 = -v3;
    }
    v12 = v3 > 0;
    v6 = v3 > 0 ? *(_WORD *)(v4 + 2) : *(_WORD *)v4;
    if ( v6 != -1 )
      LOBYTE(v6) = sub_4406BC(v11, v6);
    v8 = *(_WORD *)(v4 + 4);
    v7 = v8 + *(_WORD *)(v4 + 6);
    if ( pD3DRenderer->dword_040088 )
    {
      while ( v8 < v7 )
        LOBYTE(v6) = sub_4B0EA8(&class37_global0, v11, *(_WORD *)(*(_DWORD *)(v5 + 48) + 2 * v8++));
    }
    else
    {
      while ( v8 < v7 )
        LOBYTE(v6) = sub_4AFB86(&class37_global0, v11, *(_WORD *)(*(_DWORD *)(v5 + 48) + 2 * v8++));
    }
    v9 = v12 ? *(_WORD *)v4 : *(_WORD *)(v4 + 2);
    if ( v9 == -1 )
      break;
    a2 = v9;
  }
  return v6;
}

//----- (004407D9) --------------------------------------------------------
int __thiscall sub_4407D9(int this, int a2)
{
  int v2; // ebx@1
  int v3; // esi@1
  int v4; // ST08_4@1
  signed int v5; // ST04_4@1
  int v6; // ST00_4@1
  int v7; // eax@1
  int v8; // ST08_4@2
  signed int v9; // ST04_4@2
  int v10; // ST00_4@2
  int v11; // edi@4
  int v12; // ecx@4
  int v13; // edx@4
  signed int v14; // ecx@4
  int v15; // edx@4
  int v16; // eax@4
  double v17; // st7@5
  int v18; // eax@5
  double v19; // st7@5
  int v20; // eax@5
  double v21; // st7@5
  int v22; // eax@5
  int v23; // edx@5
  int v24; // ecx@5
  int v25; // eax@5
  int v26; // eax@5
  int result; // eax@6
  signed int v28; // eax@6
  int v29; // [sp+24h] [bp+8h]@5

  v2 = a2;
  v3 = this;
  *(_DWORD *)this = *(_DWORD *)a2;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
  v4 = *(_DWORD *)(this + 16);
  v5 = *(_DWORD *)(this + 12);
  *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
  v6 = *(_DWORD *)(this + 8);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  v7 = sub_49AC17((int)byte_6BE3C8, v6, v5, v4);
  *(_DWORD *)(v3 + 28) = v7;
  if ( !v7 )
  {
    v8 = *(_DWORD *)(v3 + 16);
    *(_DWORD *)(v3 + 8) = pParty_global->sPartyPosX;
    v9 = pParty_global->sPartyPosY;
    v10 = *(_DWORD *)(v3 + 8);
    *(_DWORD *)(v3 + 12) = pParty_global->sPartyPosY;
    *(_DWORD *)(v3 + 28) = sub_49AC17((int)byte_6BE3C8, v10, v9, v8);
  }
  if ( pD3DRenderer->dword_040088 )
  {
    *(_DWORD *)(v3 + 32) = class59_SinCos(pClass59_global, *(_DWORD *)(v3 + 20));
    *(_DWORD *)(v3 + 36) = class59_SinCos(pClass59_global, *(_DWORD *)(v3 + 20) - pClass59_global->uNumTableEntries);
    *(_DWORD *)(v3 + 40) = class59_SinCos(pClass59_global, -*(_DWORD *)(v3 + 24));
    *(_DWORD *)(v3 + 44) = class59_SinCos(pClass59_global, -*(_DWORD *)(v3 + 24) - pClass59_global->uNumTableEntries);
    *(float *)(v3 + 48) = cos((*(double *)&byte_4D8410[376] + *(double *)&byte_4D8410[376])
                            * (double)*(signed int *)(v3 + 20) * *(double *)&byte_4D8410[264]);
    *(float *)(v3 + 52) = sin((*(double *)&byte_4D8410[376] + *(double *)&byte_4D8410[376])
                            * (double)*(signed int *)(v3 + 20) * *(double *)&byte_4D8410[264]);
    *(float *)(v3 + 56) = cos((*(double *)&byte_4D8410[376] + *(double *)&byte_4D8410[376])
                            * (double)-*(_DWORD *)(v3 + 24) * *(double *)&byte_4D8410[264]);
    *(float *)(v3 + 60) = sin((*(double *)&byte_4D8410[376] + *(double *)&byte_4D8410[376])
                            * (double)-*(_DWORD *)(v3 + 24) * *(double *)&byte_4D8410[264]);
    *(_DWORD *)(v3 + 100) = *(_DWORD *)(a2 + 60);
    v11 = *(_DWORD *)(v3 + 96);
    v12 = *(_DWORD *)(v3 + 84);
    v13 = *(_DWORD *)(v3 + 92) - v12;
    v14 = *(_DWORD *)(v3 + 92) + v12;
    *(_DWORD *)(v3 + 112) = v13 + 1;
    v15 = *(_DWORD *)(v3 + 88);
    *(_DWORD *)(v3 + 108) = v11 - v15 + 1;
    v16 = *(_DWORD *)(v3 + 96);
    *(_DWORD *)(v3 + 116) = v14 >> 1;
    *(_DWORD *)(v3 + 120) = (v16 + v15) >> 1;
  }
  else
  {
    *(_DWORD *)(v3 + 32) = class59_SinCos(pClass59_global, -*(_DWORD *)(v3 + 20));
    *(_DWORD *)(v3 + 36) = class59_SinCos(pClass59_global, -*(_DWORD *)(v3 + 20) - pClass59_global->uNumTableEntries);
    *(_DWORD *)(v3 + 40) = class59_SinCos(pClass59_global, -*(_DWORD *)(v3 + 24));
    *(_DWORD *)(v3 + 44) = class59_SinCos(pClass59_global, -*(_DWORD *)(v3 + 24) - pClass59_global->uNumTableEntries);
    v17 = cos((double)-*(_DWORD *)(v3 + 20) * 0.003066406352445483);
    v18 = *(_DWORD *)(v3 + 20);
    *(float *)(v3 + 48) = v17;
    v19 = sin((double)-v18 * 0.003066406352445483);
    v20 = *(_DWORD *)(v3 + 24);
    *(float *)(v3 + 52) = v19;
    v21 = cos((double)-v20 * 0.003066406352445483);
    v22 = *(_DWORD *)(v3 + 24);
    *(float *)(v3 + 56) = v21;
    *(float *)(v3 + 60) = sin((double)-v22 * 0.003066406352445483);
    v23 = *(_DWORD *)(v3 + 84);
    *(_DWORD *)(v3 + 100) = *(_DWORD *)(a2 + 60);
    v24 = *(_DWORD *)(v3 + 92);
    *(_DWORD *)(v3 + 112) = *(_DWORD *)(v3 + 92) - v23 + 1;
    v25 = *(_DWORD *)(v3 + 96) - *(_DWORD *)(v3 + 88) + 1;
    *(_DWORD *)(v3 + 108) = v25;
    v29 = v25;
    v26 = *(_DWORD *)(v3 + 100);
    *(_DWORD *)(v3 + 116) = (v24 + v23) >> 1;
    *(_DWORD *)(v3 + 120) = *(_DWORD *)(v3 + 96) - ((unsigned __int64)(v26 * v29) >> 16);
  }
  v28 = (unsigned int)(signed __int64)((double)*(signed int *)(v3 + 112)
                                     * memory_4D8410.d_0_5
                                     / tan((double)(signed int)(*(_DWORD *)(v2 + 28) >> 1) * memory_4D8410.double_0000F8)
                                     + memory_4D8410.d_0_5) << 16;
  *(_DWORD *)(v3 + 64) = v28;
  *(_DWORD *)(v3 + 68) = 4294967296i64 / v28;
  *(_DWORD *)(v3 + 72) = *(_DWORD *)(v2 + 32);
  *(_DWORD *)(v3 + 76) = *(_DWORD *)(v2 + 36);
  *(_DWORD *)(v3 + 80) = *(_DWORD *)(v2 + 40);
  *(_DWORD *)(v3 + 84) = *(_DWORD *)(v2 + 44);
  *(_DWORD *)(v3 + 88) = *(_DWORD *)(v2 + 48);
  *(_DWORD *)(v3 + 92) = *(_DWORD *)(v2 + 52);
  *(_DWORD *)(v3 + 96) = *(_DWORD *)(v2 + 56);
  *(_DWORD *)(v3 + 104) = *(_DWORD *)(v2 + 64);
  result = 0;
  *(_DWORD *)(v3 + 140) = 0;
  *(_DWORD *)(v3 + 132) = 0;
  *(_DWORD *)(v3 + 128) = 0;
  *(_DWORD *)(v3 + 136) = 0;
  dword_51B770 = 64;
  dword_51B774 = 6;
  return result;
}

//----- (00440B44) --------------------------------------------------------
void __fastcall sub_440B44(char a1)
{
  int i; // esi@2
  int v2; // eax@3
  int v3; // edx@4
  int j; // esi@8
  int v5; // ecx@9
  int v6; // [sp-4h] [bp-8h]@4

  if ( a1 )
  {
    sub_49AC17((int)byte_6BE3C8, pParty_global->sPartyPosX, pParty_global->sPartyPosY, pParty_global->sPartyPosZ);
    for ( i = 0; i < class37_global0.dword_000000; ++i )
    {
      v2 = 2252 * word_51B77E[2 * i];
      if ( *(int *)((char *)&dword_51CEC8 + v2) == -1 )
      {
        v6 = 0;
        v3 = 0;
      }
      else
      {
        v3 = (int)((char *)&unk_51CECC + v2);
        v6 = (int)((char *)&unk_51CF2C + v2);
      }
      sub_4B0A25(word_51B77C[2 * i], v3, 4, v6);
    }
  }
  else
  {
    for ( j = 0; j < class37_global0.dword_000000; ++j )
    {
      v5 = word_51B77C[2 * j];
      dword_51B75C = (int)((char *)&unk_51C72C + 2252 * word_51B77E[2 * j]);
      sub_4AFF79(v5);
    }
  }
}

//----- (00440BED) --------------------------------------------------------
void __thiscall sub_440BED(int this)
{
  int v1; // edi@7
  _UNKNOWN *v2; // esi@8
  int v3; // edx@9
  int v4; // ecx@9
  int v5; // eax@10
  int v6; // [sp+8h] [bp-8h]@7
  int v7; // [sp+Ch] [bp-4h]@8

  sub_43F39E(this);
  if ( dword_51B6FC )
    sub_440B44(pD3DRenderer->dword_040088 != 0);
  sub_440CB8();
  if ( !pD3DRenderer->dword_040088 )
  {
    if ( byte_51B6E4 & 2 )
      sub_4B0967();
    if ( byte_51B6E4 & 1 )
    {
      v1 = dword_51B728;
      v6 = 0;
      if ( dword_51C71C > 0 )
      {
        v7 = 0;
        v2 = &unk_51C730;
        do
        {
          v4 = *((_DWORD *)v2 - 1);
          v3 = pD3DRenderer->uTargetSurfacePitch * *((_DWORD *)v2 - 1);
          if ( v4 <= *(_DWORD *)v2 )
          {
            v5 = 2 * (v4 + v7) + 5360388;
            do
            {
              *(_WORD *)(v1 + 2 * (v3 + *(_WORD *)(v5 - 960))) = 255;
              ++v4;
              *(_WORD *)(v1 + 2 * (v3 + *(_WORD *)v5)) = 255;
              v3 += pD3DRenderer->uTargetSurfacePitch;
              v5 += 2;
            }
            while ( v4 <= *(_DWORD *)v2 );
          }
          ++v6;
          v7 += 1126;
          v2 = (char *)v2 + 2252;
        }
        while ( v6 < dword_51C71C );
      }
    }
  }
}

//----- (00440CB8) --------------------------------------------------------
void __cdecl sub_440CB8()
{
  _UNKNOWN *v1; // esi@2
  __int16 v2; // ax@3
  char *v3; // eax@6
  char v4; // zf@6
  int v5; // eax@11
  int v6; // [sp+4h] [bp-50h]@1
  int v7; // [sp+8h] [bp-4Ch]@1
  int v8; // [sp+Ch] [bp-48h]@3
  int v9; // [sp+10h] [bp-44h]@3
  int v10; // [sp+14h] [bp-40h]@3
  int v11; // [sp+18h] [bp-3Ch]@3
  char *v12; // [sp+24h] [bp-30h]@6
  char *v13; // [sp+28h] [bp-2Ch]@10
  int v14; // [sp+2Ch] [bp-28h]@3
  int v15; // [sp+30h] [bp-24h]@3
  int v16; // [sp+34h] [bp-20h]@1
  int v17; // [sp+38h] [bp-1Ch]@1
  int v18; // [sp+3Ch] [bp-18h]@1
  int v19; // [sp+40h] [bp-14h]@1
  int v20; // [sp+44h] [bp-10h]@1
  int v22; // [sp+50h] [bp-4h]@3
 int i;

  v6 = dword_51B728;
  v7 = dword_51B748;
  v16 = pD3DRenderer->uTargetSurfacePitch;
  v17 = dword_51B734;
  v18 = dword_51B738;
  v19 = dword_51B73C - 1;
  v20 = dword_51B740;
  pStruct9_global->dword_00003C = dword_5187E0;

 for (i = 0; i < dword_5187E0; ++i)
  {
    v1 = &array_512250[i].byte_000014[20];

      v8 = *((_WORD *)v1 - 1);
      v9 = *(_WORD *)v1;
      v10 = *((_DWORD *)v1 - 10);
      v11 = *((_DWORD *)v1 - 9);
      v14 = *((_DWORD *)v1 - 6);
      v15 = *((_WORD *)v1 - 5);
      v22 = *((_DWORD *)v1 + 1);
      v2 = *((_WORD *)v1 - 8);
      if ( v2 != -1 )
      {
        if ( pD3DRenderer->dword_040088 )
        {
          sub_4A43B1(pD3DRenderer, (int)&v6, pClass17_Sprites_LOD->dword_00ECB0 + 40 * v2, *((_WORD *)v1 + 1));
        }
        else
        {
          v3 = sub_41F50D(*((_WORD *)v1 - 7), *((_WORD *)v1 + 1), 1);
          v4 = (*((_BYTE *)v1 - 9) & 1) == 0;
          v12 = v3;
          if ( !v4 )
            v12 = (char *)&unk_A6E798 + 512 * *((_WORD *)v1 - 7);
          if ( !(v15 & 0x40) )
          {
            if ( v15 & 0x80 )
              v13 = sub_41F50D(*((_WORD *)v1 - 7), 0, 1);
          }
          v5 = *((_WORD *)v1 - 8);
          if ( v5 >= 0 )
            sub_4ACC38(40 * v5 + 7218180, (int)&v6, 1);
        }
      }
      v1 = (char *)v1 + 52;
  }
}

//----- (00440DF5) --------------------------------------------------------
int __thiscall sub_440DF5(int this, __int16 a2, __int16 a3, __int16 a4, int a5, __int16 a6)
{
  int result; // eax@1
  int v7; // esi@1

  v7 = this;
  *(_WORD *)(v7 + 24 * *(_DWORD *)(v7 + 2400) + 6) = a2;
  *(_WORD *)(this + 24 * *(_DWORD *)(this + 2400) + 8) = a3;
  *(_WORD *)(this + 24 * *(_DWORD *)(this + 2400) + 10) = a4;
  *(_WORD *)(v7 + 24 * *(_DWORD *)(v7 + 2400) + 12) = rand() % 64 + 256;
  *(_WORD *)(v7 + 24 * *(_DWORD *)(v7 + 2400) + 14) = *(_WORD *)(v7 + 24 * *(_DWORD *)(v7 + 2400) + 12);
  result = 3 * *(_DWORD *)(v7 + 2400);
  compile_error;//*(_WORD *)(v7 + 24 * *(_DWORD *)(v7 + 2400)++ + 20) = a6;
  if ( *(_DWORD *)(v7 + 2400) >= 100 )
    *(_DWORD *)(v7 + 2400) = 0;
  return result;
}

//----- (00440E91) --------------------------------------------------------
int __thiscall sub_440E91(void *this, __int16 a2, int a3, int a4, int a5, __int16 a6)
{
  int result; // eax@1
  int v7; // edi@1
  signed int v8; // esi@1
  int v9; // eax@1
  signed __int64 v10; // qtt@1
  int v11; // ST08_4@2
  int v12; // ST04_4@2
  int v13; // eax@2
  int v14; // eax@2
  signed __int64 v15; // qtt@2

  v7 = (int)this;
  v8 = 0;
  v9 = rand();
  v10 = v9;
  result = v9 / 6;
  if ( (signed int)(v10 % 6 + 5) > 0 )
  {
    do
    {
      v11 = a4 + rand() % 33;
      v12 = rand() % 33 + a3 - 16;
      v13 = rand();
      sub_440DF5(v7, v13 % 33 + a2 - 16, v12, v11, a5, a6);
      ++v8;
      v14 = rand();
      v15 = v14;
      result = v14 / 6;
    }
    while ( v8 < (signed int)(v15 % 6 + 5) );
  }
  return result;
}

//----- (0044100D) --------------------------------------------------------
bool __cdecl sub_44100D()
{
  return dword_4E28F8 == 4
      || dword_4E28F8 == 7
      || dword_4E28F8 > 12 && (dword_4E28F8 <= 14 || dword_4E28F8 > 16 && (dword_4E28F8 <= 18 || dword_4E28F8 == 23));
}

//----- (00441498) --------------------------------------------------------
void __cdecl GameUI_DrawTorchlightAndWizardEye()
{
  signed int v0; // eax@15
  int v1; // eax@15
  signed int v2; // eax@19
  int v3; // eax@19

  if ( !dword_4E28F8
    || dword_4E28F8 == 1
    || dword_4E28F8 == 2
    || dword_4E28F8 == 5
    || dword_4E28F8 == 8
    || dword_4E28F8 == 10
    || dword_4E28F8 == 11
    || dword_4E28F8 == 12
    || dword_4E28F8 == 15
    || dword_4E28F8 == 3
    || dword_4E28F8 == 19 )
  {
    if ( HIDWORD(qword_ACD944) >= 0 )
    {
      if ( HIDWORD(qword_ACD944) > 0 || (_DWORD)qword_ACD944 )
      {
        v0 = class24_fn2(pClass24_global);
        v1 = CIconFrameTable_GetFrame(pIconFrameTable, array_6A0D14[2].uIconIdx, v0);
        CD3DRenderer_DrawTransparentTexture(pD3DRenderer, array_6A0D14[2].word_000008, array_6A0D14[2].word_00000A, 72 * *(_WORD *)(v1 + 30) + 0x6D084C);
      }
    }
    if ( HIDWORD(qword_ACD974) >= 0 )
    {
      if (HIDWORD(qword_ACD974) > 0 || LODWORD(qword_ACD974))
      {
        v2 = class24_fn2(pClass24_global);
        v3 = CIconFrameTable_GetFrame(pIconFrameTable, array_6A0D14[3].uIconIdx, v2);
        CD3DRenderer_DrawTransparentTexture(pD3DRenderer, array_6A0D14[3].word_000008, array_6A0D14[3].word_00000A, 72 * *(_WORD *)(v3 + 30) + 0x6D084C);
      }
    }
  }
}

//----- (004418B1) --------------------------------------------------------
int __stdcall sub_4418B1(int a1, int a2, int a3, int a4)
{
  return 0;
}

//----- (004418B6) --------------------------------------------------------
signed int __thiscall sub_4418B6(int this, int a2, __int16 a3, int a4, int a5, __int16 a6)
{
  int v6; // eax@1
  signed int v7; // edx@1
  signed int result; // eax@4
  int v9; // esi@6
  __int16 v10; // dx@9
  __int16 v11; // dx@11

  v7 = 0;
  v6 = this;
  while ( *(_WORD *)(v6 + 6) > 0 )
  {
    ++v7;
    v6 += 20;
    if ( v7 >= 50 )
      return 0;
  }
  *(_WORD *)v6 = 0;
  *(_WORD *)(v6 + 10) = 0;
  *(_WORD *)(v6 + 8) = 0;
  *(_WORD *)(v6 + 12) = a3;
  v9 = 0;
  if ( pOverlayDescriptionList->uNumOverlays <= 0 )
  {
LABEL_9:
    v10 = 0;
  }
  else
  {
    while ( a2 != pOverlayDescriptionList->pDescriptions[v9].word_000000)
    {
      ++v9;
      if ( v9 >= pOverlayDescriptionList->uNumOverlays )
        goto LABEL_9;
    }
    v10 = v9;
  }
  *(_WORD *)(v6 + 2) = v10;
  *(_WORD *)(v6 + 4) = 0;
  if ( a4 )
    v11 = a4;
  else
    //v11 = 8 * *(_WORD *)(60 * *(_WORD *)(dword_5E514C + 8 * v10 + 4) + dword_5C6DCC + 56);
    v11 = 8 * pSpriteFrameTable->pSpriteSFrames[pOverlayDescriptionList->pDescriptions[v10].word_000004].word_000038;

  *(_WORD *)(v6 + 6) = v11;
  *(_DWORD *)(v6 + 16) = a5;
  *(_WORD *)(v6 + 14) = a6;
  result = 1;
  *(_DWORD *)(this + 1004) = 1;
  return result;
}

//----- (00441964) --------------------------------------------------------
int __thiscall sub_441964(void *this, int a2)
{
  int result; // eax@1
  int v3; // ecx@6
  int v4; // eax@12
  int v5; // [sp-8h] [bp-Ch]@4
  signed int v6; // [sp-4h] [bp-8h]@4
  int v7; // [sp-4h] [bp-8h]@14

  result = dword_4E28F8;
  if ( !dword_4E28F8 && dword_ACD834 == 1 )
  {
    if ( dword_4F885C == 3 )
    {
      v6 = pClass24_global->dword_00000C;
      v5 = dword_50C96C[5 - dword_4F886C / 26];
    }
    else
    {
      if ( dword_4F885C == 1 )
      {
        v6 = dword_50C994;
        v3 = pIconFrameTable;
        if ( dword_50C998 )
          v5 = dword_50C990;
        else
          v5 = dword_50C984;
        goto LABEL_12;
      }
      if ( dword_4F885C != 2 )
      {
        v4 = (int)this;
        goto LABEL_14;
      }
      v6 = pClass24_global->dword_00000C;
      v5 = dword_50C980;
    }
    v3 = pIconFrameTable;
LABEL_12:
    v4 = CIconFrameTable_GetFrame(v3, v5, v6);
LABEL_14:
    v7 = 72 * *(_WORD *)(v4 + 30) + 7145548;
    if ( pD3DRenderer->dword_040088 )
      CD3DRenderer_DrawIndexedTexture(pD3DRenderer, 394, 288, v7);
    else
      CD3DRenderer_DrawTransparentTexture(pD3DRenderer, 394, 288, v7);
    result = dword_50C994;
    if ( dword_50C994 < dword_50C998 )
    {
      result = pClass24_global->int_00001C + dword_50C994;
      dword_50C994 = result;
      if ( result >= dword_50C998 )
        dword_50C998 = 0;
    }
  }
  return result;
}

//----- (00441BD4) --------------------------------------------------------
void __cdecl sub_441BD4()
{
  signed int v0; // eax@1
  int v1; // [sp+0h] [bp-4Ch]@5
  int v2; // [sp+4h] [bp-48h]@5
  int v3; // [sp+8h] [bp-44h]@5
  int v4; // [sp+Ch] [bp-40h]@5
  int v5; // [sp+10h] [bp-3Ch]@5
  int v6; // [sp+14h] [bp-38h]@5
  int v7; // [sp+18h] [bp-34h]@5
  int v8; // [sp+1Ch] [bp-30h]@5
  int v9; // [sp+20h] [bp-2Ch]@5
  int v10; // [sp+24h] [bp-28h]@5
  int v11; // [sp+28h] [bp-24h]@5
  int v12; // [sp+2Ch] [bp-20h]@5
  int v13; // [sp+30h] [bp-1Ch]@5
  int v14; // [sp+34h] [bp-18h]@5
  int v15; // [sp+38h] [bp-14h]@5
  int v16; // [sp+3Ch] [bp-10h]@5
  int v17; // [sp+40h] [bp-Ch]@5
  int v18; // [sp+44h] [bp-8h]@5
  int v19; // [sp+48h] [bp-4h]@5

  v0 = 0;
  if ( struct_576FE8.dword_000050 )
    v0 = 1;
  if ( struct_576FE8.dword_000054 )
    LOBYTE(v0) = v0 | 2;
  v1 = pClass24_global->dword_000024;
  v2 = v0;
  v3 = pParty_global->sPartyPosX - ((unsigned __int64)(class59_SinCos(pClass59_global, pParty_global->sRotationY) * pParty_global->dword_000018) >> 16);
  v18 = class59_SinCos(pClass59_global, pParty_global->sRotationY - pClass59_global->uNumTableEntries);
  v19 = (unsigned __int64)(v18 * pParty_global->dword_000018) >> 16;
  v8 = 65;
  v4 = pParty_global->sPartyPosY - v19;
  v6 = pParty_global->sRotationY;
  v7 = pParty_global->sRotationX;
  v9 = pD3DRenderer->pTargetSurface;
  v12 = class28_global.dword_000000;
  v13 = class28_global.dword_000004;
  v14 = class28_global.dword_000008;
  v15 = class28_global.dword_00000C;
  v16 = class28_global.dword_000030;
  v5 = pParty_global->sPartyPosZ + pParty_global->uEyelevel;
  v10 = 640;
  v11 = 480;
  v17 = pD3DRenderer->pActiveZBuffer;
  sub_440BED((int)&v1);
  pParty_global->dword_007778 &= 0xFFFFFFFDu;
  sub_47A815();
  sub_440F07(array_5118E8);
}

//----- (00442955) --------------------------------------------------------
unsigned int __fastcall sub_442955(int a1, int a2, int a3, int a4, int a5)
{
  signed int v5; // ebx@1
  int v6; // edi@1
  int v7; // eax@8
  unsigned __int8 v8; // zf@8
  unsigned __int8 v9; // sf@8
  int v10; // esi@10
  int v11; // edx@11
  __int16 v12; // cx@12
  signed int v13; // eax@15
  int v14; // eax@16
  int v15; // ecx@16
  int v16; // edx@16
  int v17; // ecx@16
  int v18; // eax@16
  int v19; // ecx@16
  int v20; // eax@16
  int v21; // esi@18
  int v22; // ecx@21
  int v23; // ecx@21
  int v24; // edx@21
  int v25; // eax@21
  int v26; // ecx@21
  int v27; // edi@21
  int v28; // edx@21
  int v29; // eax@21
  signed int v30; // eax@23
  char *v31; // edx@23
  signed int v32; // ecx@23
  double v33; // st7@23
  signed __int64 v34; // qax@23
  int v35; // esi@23
  int v36; // ecx@27
  int v37; // esi@27
  int v40; // edx@31
  int v41; // eax@33
  int v42; // ecx@33
  int v43; // edi@33
  int v44; // esi@33
  int v45; // esi@33
  int v46; // edi@33
  unsigned __int8 v47; // cf@33
  unsigned int v48; // ecx@33
  int v50; // eax@38
  signed int v51; // ecx@38
  int v52; // esi@38
  signed int v53; // edx@55
  int v54; // ecx@55
  unsigned int result; // eax@72
  int v56; // eax@75
  int v57; // esi@75
  int v58; // eax@75
  signed int v59; // ebx@85
  signed int v60; // edi@85
  int v61; // esi@85
  __int16 v62; // si@85
  double v63; // st7@85
  int v64; // ebx@85
  signed __int64 v65; // qax@85
  signed __int64 v66; // qax@85
  int v67; // eax@87
  char *v68; // edx@95
  int v69; // ebx@95
  int v70; // esi@96
  int v71; // edi@98
  __int16 v72; // cx@99
  int v73; // [sp-10h] [bp-48074h]@80
  int v74; // [sp-Ch] [bp-48070h]@80
  int v75; // [sp-8h] [bp-4806Ch]@80
  signed int v76; // [sp-4h] [bp-48068h]@59
  __int16 v77; // [sp-4h] [bp-48068h]@79
  char v78; // [sp+Ch] [bp-48058h]@23
  int v79; // [sp+4800Ch] [bp-58h]@23
  int v80; // [sp+48010h] [bp-54h]@27
  int v81; // [sp+48014h] [bp-50h]@23
  int v82; // [sp+48018h] [bp-4Ch]@1
  int v83; // [sp+4801Ch] [bp-48h]@1
  int v84; // [sp+48020h] [bp-44h]@23
  int v85; // [sp+48024h] [bp-40h]@1
  unsigned int v86; // [sp+48028h] [bp-3Ch]@8
  int v87; // [sp+4802Ch] [bp-38h]@1
  int v88; // [sp+48030h] [bp-34h]@1
  unsigned int v89; // [sp+48034h] [bp-30h]@1
  int v90; // [sp+48038h] [bp-2Ch]@16
  int v91; // [sp+4803Ch] [bp-28h]@16
  int v92; // [sp+48040h] [bp-24h]@8
  int v93; // [sp+48044h] [bp-20h]@1
  int i; // [sp+48048h] [bp-1Ch]@9
  int v95; // [sp+4804Ch] [bp-18h]@16
  int v96; // [sp+48050h] [bp-14h]@16
  int v97; // [sp+48054h] [bp-10h]@8
  int v98; // [sp+48058h] [bp-Ch]@16
  int v99; // [sp+4805Ch] [bp-8h]@10
  const void *v100; // [sp+48060h] [bp-4h]@16
  char *v101; // [sp+4806Ch] [bp+8h]@85
  int v102; // [sp+48070h] [bp+Ch]@86

  v85 = a1;
  v83 = a2;
  v88 = (a1 + a3) >> 1;
  v93 = (a2 + a4) >> 1;
  v82 = pD3DRenderer->uTargetSurfacePitch;
  CD3DRenderer_sub_4A0E97(pD3DRenderer, a1, a2, a3, a4);
  v5 = struct_576FE8.dword_00002C;
  v6 = struct_576FE8.dword_000030;
  v89 = struct_576FE8.dword_000030;
  v87 = struct_576FE8.dword_000034;
  if ( struct_576FE8.dword_00002C != 384 )
  {
   if ( struct_576FE8.dword_00002C == 768 )
    {
      if ( dword_6BE360 != 1 )
        goto LABEL_23;
      v5 = 680;
    }
    if ( dword_6BE360 == 1 )
      goto LABEL_8;
LABEL_23:
    v97 = a3 - v85 + 1;
    v95 = a4 - v83 + 1;
    v96 = pD3DRenderer->pTargetSurface + (v85 + v83 * v82);
    compile_error;//v98 = *(_DWORD *)pClass17_Icons_LOD->byte_00023C[72 * uTextureID_LocationMap + 48];
    compile_error;//v81 = *(_DWORD *)pClass17_Icons_LOD->byte_00023C[72 * uTextureID_LocationMap + 64];
    compile_error;//v90 = (1 << ((unsigned __int8)*(_WORD *)pClass17_Icons_LOD->byte_00023C[72 * uTextureID_LocationMap + 28] + 16)) / v5;
    compile_error;//v33 = (double)(1 << (16 - (unsigned __int8)*(_WORD *)pClass17_Icons_LOD->byte_00023C[72 * uTextureID_LocationMap + 28]));
    v92 = 22528 / (v5 / 384);
    v86 = (unsigned int)(signed __int64)((double)(v6 - 22528 / (v5 / 384) + 32768) / v33) << 16;
    v100 = (const void *)((unsigned int)(signed __int64)((double)(v6 - 22528 / (v5 / 384) + 32768) / v33) << 16);
    v99 = 32768 - v92 - v87;
    v34 = (signed __int64)((double)v99 / v33);
    v31 = &v78;
    compile_error;//v35 = *(_WORD *)pClass17_Icons_LOD->byte_00023C[72 * uTextureID_LocationMap + 24];
    v30 = (_DWORD)v34 << 16;
    v84 = (signed int)v86 >> 16;
    v92 = (signed int)v86 >> 16;
    v79 = v35;
    v32 = v30 >> 16;
    if ( v98 )
    {
      if ( v95 > 0 )
      {
        v99 = v95;
        do
        {
          v91 = 0;
          if ( v97 > 0 )
          {
            v37 = v98 + v32 * v79;
            i = v97;
            v91 = v97;
            v36 = v92;
            v80 = v37;
            do
            {
              *(_WORD *)v31 = *(_WORD *)(v81 + 2 * *(_BYTE *)(v80 + v36));
              v31 += 2;
              v100 = (char *)v100 + v90;
              v36 = (signed int)v100 >> 16;
            }
            while ( i-- != 1 );
          }
          v30 += v90;
          v100 = (const void *)v86;
          v92 = v84;
          v31 += 2 * (v97 - v91);
          v32 = v30 >> 16;
        }
        while ( v99-- != 1 );
      }
    }
    v100 = &v78;
    if ( v95 > 0 )
    {
      v99 = v95;
      v40 = 2 * (v82 - v97);
      do
      {
        if ( v97 > 0 )
        {
          v41 = v97;
          v45 = (int)v100;
          v46 = v96;
          v47 = v97 & 1;
          v48 = (unsigned int)v97 >> 1;
          memcpy((void *)v96, v100, 4 * ((unsigned int)v97 >> 1));
          v44 = v45 + 4 * v48;
          v43 = v46 + 4 * v48;
          v42 = 2 * v47;
          v41 *= 2;
          v96 += v41;
          v100 = (char *)v100 + v41;
          while ( v42 )
          {
            *(_WORD *)v43 = *(_WORD *)v44;
            v44 += 2;
            v43 += 2;
            --v42;
          }
          v6 = v89;
        }
        v96 += v40;
      }
      while ( v99-- != 1 );
    }
    goto LABEL_38;
  }
  v6 = struct_576FE8.word_000038;
  v89 = struct_576FE8.word_000038;
  v87 = struct_576FE8.word_00003A;
  if ( dword_6BE360 != 1 )
    goto LABEL_23;
  v5 = struct_576FE8.dword_00002C - 34;
LABEL_8:
  v92 = 0xFF000000;
  v86 = 0xFF00FFFF;
  v7 = dword_6BE670;
  dword_576D14 = 0;
  v8 = *(_DWORD *)dword_6BE670 == 0;
  v9 = *(_DWORD *)dword_6BE670 < 0;
  v97 = 0;
  if ( !(v9 | v8) )
  {
    i = 0;
    do
    {
      v10 = i + v7 + 4;
      v99 = *(_DWORD *)(96 * *(_WORD *)(i + v7 + 8) + dword_6BE644 + 44);
      if ( BYTE1(v99) & 0x20 || (v11 = *(_DWORD *)(96 * *(_WORD *)(i + v7 + 10) + dword_6BE644 + 44), BYTE1(v11) & 0x20) )
        goto LABEL_17;
      v12 = *(_WORD *)(i + v7 + 14);
      if ( !(v12 & 1) )
      {
        if ( !(v99 & 0x80) && (_BYTE)v11 >= 0 )
          goto LABEL_17;
        v99 = v97 >> 3;
        v13 = v97;
        *(_WORD *)(v10 + 10) = v12 | 1;
        byte_6BE6EC[v99] |= 1 << (7 - v13 % 8);
      }
      v14 = *(_WORD *)v10;
      v91 = v5;
      v15 = dword_6BE63C + 6 * v14;
      v16 = *(_WORD *)v15;
      v17 = *(_WORD *)(v15 + 2) - v87;
      v96 = v16 - v6;
      v95 = v17;
      v18 = dword_6BE63C + 6 * *(_WORD *)(v10 + 2);
      v19 = *(_WORD *)v18;
      v20 = *(_WORD *)(v18 + 2) - v87;
      v98 = v19 - v6;
      v100 = (const void *)v20;
      v91 = (unsigned __int64)((v16 - v6) * v5) >> 16;
      v90 = (unsigned __int64)(v95 * v5) >> 16;
      v96 = (unsigned __int64)((v19 - v6) * v5) >> 16;
      v95 = (unsigned __int64)(v20 * v5) >> 16;
      CD3DRenderer_FillRect(
        pD3DRenderer,
        v88 + v91,
        v93 - v90,
        v88 + ((unsigned __int64)((v19 - v6) * v5) >> 16),
        v93 - v95,
        v92);
      v7 = dword_6BE670;
LABEL_17:
      ++v97;
      i += 12;
    }
    while ( v97 < *(_DWORD *)v7 );
  }
  v21 = 0;
  if ( dword_576D14 > 0 )
  {
    while ( 1 )
    {
      v22 = (unsigned __int16)word_576D80[v21];
      v90 = v5;
      v23 = v7 + 12 * v22 + 4;
      v24 = dword_6BE63C + 6 * *(_WORD *)v23;
      v25 = dword_6BE63C + 6 * *(_WORD *)(v23 + 2);
      v26 = *(_WORD *)v25;
      v27 = *(_WORD *)v24 - v89;
      v28 = *(_WORD *)(v24 + 2) - v87;
      v29 = *(_WORD *)(v25 + 2) - v87;
      v96 = v27;
      v95 = v28;
      v100 = (const void *)v29;
      v90 = (unsigned __int64)(v27 * v5) >> 16;
      v91 = (unsigned __int64)(v28 * v5) >> 16;
      i = (unsigned __int64)((signed int)(v26 - v89) * v5) >> 16;
      v98 = (unsigned __int64)(v29 * v5) >> 16;
      CD3DRenderer_FillRect(
        pD3DRenderer,
        v88 + ((unsigned __int64)(v27 * v5) >> 16),
        v93 - v91,
        v88 + ((unsigned __int64)((signed int)(v26 - v89) * v5) >> 16),
        v93 - v98,
        v86);
      ++v21;
      if ( v21 >= dword_576D14 )
        break;
      v7 = dword_6BE670;
    }
    v6 = v89;
  }
LABEL_38:
  v52 = ((unsigned __int64)((pParty_global->sPartyPosX - v6) * v5) >> 16) + v88 - 3;
  v84 = pParty_global->sPartyPosY - v87;
  v100 = (const void *)((unsigned __int64)((pParty_global->sPartyPosY - v87) * v5) >> 16);
  v51 = 1;
  v50 = v93 - (_DWORD)v100 - 3;
  if ( v52 >= v85 )
  {
    if ( v52 > a3 )
    {
      if ( (signed int)(((unsigned __int64)((pParty_global->sPartyPosX - v6) * v5) >> 16) + v88 - 6) > a3 )
        v51 = 0;
      v52 = a3;
    }
  }
  else
  {
    if ( (signed int)(((unsigned __int64)((pParty_global->sPartyPosX - v6) * v5) >> 16) + v88) < v85 )
      v51 = 0;
    v52 = v85;
  }
  if ( v50 >= v83 )
  {
    if ( v50 > a4 )
    {
      if ( v93 - (_DWORD)v100 - 6 > a4 )
        v51 = 0;
      v50 = a4;
    }
  }
  else
  {
    if ( v93 - (_DWORD)v100 < v83 )
      v51 = 0;
    v50 = v83;
  }
  if ( v51 == 1 )
  {
    v53 = 0;
    v54 = pParty_global->sRotationY & pClass59_global->dword_00186C;
    if ( (pParty_global->sRotationY & pClass59_global->dword_00186C) >= 128 )
    {
      if ( v54 > 384 )
      {
        if ( v54 >= 640 )
        {
          if ( v54 > 896 )
          {
            if ( v54 >= 1152 )
            {
              if ( v54 > 1408 )
              {
                if ( v54 >= 1664 )
                {
                  if ( v54 > 1920 )
                    goto LABEL_71;
                  v76 = 7;
                }
                else
                {
                  v76 = 6;
                }
              }
              else
              {
                v76 = 5;
              }
            }
            else
            {
              v76 = 4;
            }
          }
          else
          {
            v76 = 3;
          }
        }
        else
        {
          v76 = 2;
        }
        v53 = v76;
        goto LABEL_71;
      }
      v53 = 1;
    }
LABEL_71:
    sub_4A6776(pD3DRenderer, v52, v50, uTextureIdx_MapDirs[v53] != -1 ? 72 * uTextureIdx_MapDirs[v53] + 7145548 : 0);
  }
  result = 0xFFFFFFFF;
  v98 = 0;
  v89 = result;
  if ( (signed int)dword_69ADD0 > 0 )
  {
   v97 = (int)&array_6836D0[0].sPosX;
    do
    {
      if ( *(_BYTE *)(v97 - 2) & 8 )
      {
        v58 = *(_DWORD *)(v97 + 4) - v87;
        v96 = *(_DWORD *)v97 - v6;
        v95 = v58;
        v57 = ((unsigned __int64)(v96 * v5) >> 16) + v88;
        v100 = (const void *)((unsigned __int64)(v58 * v5) >> 16);
        v56 = v93 - (_DWORD)v100;
        if ( v57 >= pD3DRenderer->dword_00001C)
        {
          if ( v57 <= pD3DRenderer->dword_000024 )
          {
            if ( v56 >= pD3DRenderer->dword_000020 )
            {
              if ( v56 <= pD3DRenderer->dword_000028 )
              {
                v77 = v89;
                if ( v5 > 512 )
                {
                  v99 = v56 + 1;
                  v92 = v56 - 1;
                  CD3DRenderer_FillRect(pD3DRenderer, v57 - 1, v56 - 1, v57 - 1, v56 + 1, v89);
                  CD3DRenderer_FillRect(pD3DRenderer, v57, v92, v57, v99, v89);
                  ++v57;
                  v77 = v89;
                  v75 = v99;
                  v74 = v57;
                  v73 = v92;
                }
                else
                {
                  v75 = v93 - (_DWORD)v100;
                  v74 = ((unsigned __int64)(v96 * v5) >> 16) + v88;
                  v73 = v93 - (_DWORD)v100;
                }
                CD3DRenderer_FillRect(pD3DRenderer, v57, v73, v74, v75, v77);
              }
            }
          }
        }
      }
      ++v98;
      result = v98;
      v97 += 32;
    }
    while ( v98 < (signed int)dword_69ADD0 );
  }
  if ( dword_6BE360 == 2 )
  {
    v93 = a3 - v85 + 1;
    v98 = a4 - v83 + 1;
    v80 = pD3DRenderer->pTargetSurface + (v85 + v83 * v82);
    compile_error;//v62 = *(_WORD *)pClass17_Icons_LOD->byte_00023C[72 * uTextureID_LocationMap + 28];
    v92 = (1 << (v62 + 16)) / v5;
    v63 = (double)(1 << (16 - (_BYTE)v62));
    v64 = 22528 / (v5 / 384);
    v65 = (signed __int64)((double)(v6 - v64 + 32768) / v63);
    v60 = (_DWORD)v65 << 16;
    v100 = (const void *)((_DWORD)v65 << 16);
    v66 = (signed __int64)((double)(32768 - v64 - v87) / v63);
    v81 = v60 >> 16;
    v59 = (_DWORD)v66 << 16;
    v86 = v60 >> 16;
    v61 = (_DWORD)v66 << 16 >> 16;
    v101 = &v78;
    result = 0xFF0C0C0C;
    v88 = 0;
    for ( i = result; v88 < v98; result = v88 )
    {
      v102 = 0;
      if ( v93 > 0 )
      {
        v99 = (v61 - 80) / 4;
        v67 = v86;
        do
        {
          v84 = (v67 - 80) / 4;
          if ( !sub_47F04C(pClass51_global, v84, v99) )
          {
            if ( sub_47F097(pClass51_global, v84, v99) )
            {
              if ( !((v102 + v88) % 2) )
                *(_WORD *)v101 = i;
            }
            else
            {
              *(_WORD *)v101 = 0;
            }
          }
          v101 += 2;
          v100 = (char *)v100 + v92;
          v67 = (signed int)v100 >> 16;
          ++v102;
        }
        while ( v102 < v93 );
      }
      v59 += v92;
      v100 = (const void *)v60;
      v101 += 2 * (v93 - v102);
      v61 = v59 >> 16;
      ++v88;
      v86 = v81;
    }
    v69 = v98;
    v68 = &v78;
    if ( v98 > 0 )
    {
      v70 = v80;
      result = 2 * (v82 - v93);
      do
      {
        if ( v93 > 0 )
        {
          v71 = v93;
          do
          {
            v72 = *(_WORD *)v68;
            if ( !*(_WORD *)v68 || v72 == (_WORD)i )
              *(_WORD *)v70 = v72;
            v68 += 2;
            v70 += 2;
            --v71;
          }
          while ( v71 );
        }
        v70 += result;
        --v69;
      }
      while ( v69 );
    }
  }
  return result;
}

//----- (00443219) --------------------------------------------------------
int __thiscall sub_443219(int this)
{
  *(_DWORD *)(this + 52) += 512;
  return sub_4432E7(this);
}

//----- (00443225) --------------------------------------------------------
int __thiscall sub_443225(int this)
{
  *(_DWORD *)(this + 48) -= 512;
  return sub_4432E7(this);
}

//----- (00443231) --------------------------------------------------------
int __thiscall sub_443231(int this)
{
  *(_DWORD *)(this + 52) -= 512;
  return sub_4432E7(this);
}

//----- (0044323D) --------------------------------------------------------
int __thiscall sub_44323D(int this)
{
  *(_DWORD *)(this + 48) += 512;
  return sub_4432E7(this);
}

//----- (00443249) --------------------------------------------------------
int __thiscall sub_443249(int this)
{
  signed int v1; // edx@1

  v1 = (unsigned __int64)((signed __int64)*(_DWORD *)(this + 44) << 15) >> 16;
  *(_DWORD *)(this + 44) = v1;
  if ( v1 < 384 )
    *(_DWORD *)(this + 44) = 384;
  *(_DWORD *)(this + 48) = pParty_global->sPartyPosX;
  *(_DWORD *)(this + 52) = pParty_global->sPartyPosY;
  return sub_4432E7(this);
}

//----- (00443291) --------------------------------------------------------
int __thiscall sub_443291(int this)
{
  signed int v1; // eax@1
  signed int v2; // edx@1

  v2 = (unsigned __int64)((signed __int64)*(_DWORD *)(this + 44) << 17) >> 16;
  v1 = 1536;
  *(_DWORD *)(this + 44) = v2;
  if ( dword_6BE360 != 2 )
    v1 = 3072;
  if ( v2 > v1 )
    *(_DWORD *)(this + 44) = v1;
  *(_DWORD *)(this + 48) = pParty_global->sPartyPosX;
  *(_DWORD *)(this + 52) = pParty_global->sPartyPosY;
  return sub_4432E7(this);
}

//----- (004432E7) --------------------------------------------------------
int __thiscall sub_4432E7(int this)
{
  signed int v1; // edx@1
  int v2; // ecx@1
  int v3; // ebx@1
  int v4; // esi@1
  int v5; // eax@3
  int v6; // edi@3
  int v7; // eax@5
  int result; // eax@7

  v4 = this;
  v3 = *(_WORD *)(this + 58);
  v1 = 88 >> *(_DWORD *)(this + 44) / 384;
  v2 = (44 - v1) << 9;
  if ( *(_DWORD *)(v4 + 52) > v3 + v2 )
    *(_DWORD *)(v4 + 52) = v3 + v2;
  v6 = *(_WORD *)(v4 + 56);
  v5 = (v1 - 44) << 9;
  if ( *(_DWORD *)(v4 + 48) < v6 + v5 )
    *(_DWORD *)(v4 + 48) = v6 + v5;
  v7 = v3 + v5;
  if ( *(_DWORD *)(v4 + 52) < v7 )
    *(_DWORD *)(v4 + 52) = v7;
  result = v6 + v2;
  if ( *(_DWORD *)(v4 + 48) > v6 + v2 )
    *(_DWORD *)(v4 + 48) = result;
  return result;
}

//----- (00443343) --------------------------------------------------------
void sub_443343_GenerateSomeColorTable(struct unnamed_576FE8 *_this)
{
 unsigned int i;

 for (i = 0; i < 256; ++i)
   _this->pSomeColorTable[i] = 0xFF000000 | (i << 16) | (i << 8) | i;
}

//----- (00443F95) --------------------------------------------------------
void __cdecl sub_443F95()
{
  int v0; // edi@1
  _UNKNOWN *v1; // esi@2
  int v2; // ecx@4

  v0 = 0;
  if ( uLevelEVT_NumEvents > 0 )
  {
    v1 = &pLevelEVT_Events[0].dword_000004;
    do
    {
      if ( byte_5B3524[*((_WORD *)v1 + 2)] == 53 )
      {
        v2 = *((_DWORD *)v1 - 1);
        dword_597F18 = *(_DWORD *)v1;
        sub_44684A_LooksLikeEventProcessor(v2, 0, 1);
        dword_597F18 = 0;
      }
      ++v0;
      v1 = (char *)v1 + 12;
    }
    while ( v0 < uLevelEVT_NumEvents );
  }
}

//----- (004443D5) --------------------------------------------------------
int __cdecl sub_4443D5()
{
  signed int v0; // ebx@1
  int v1; // esi@1
  signed int v2; // ST20_4@1
  double v3; // st7@1
  int v4; // esi@3
  int v5; // ecx@4
  int v6; // edi@4
  int v7; // eax@4
  int v8; // eax@4
  unsigned __int8 v9; // zf@5
  char v10; // sf@5
  unsigned __int8 v11; // of@5
  int v12; // eax@6
  __int16 v13; // cx@6
  char *v14; // eax@8
  char *v15; // edi@8
  int result; // eax@12
  signed int v17; // eax@14
  int v18; // [sp+Ch] [bp-20h]@1
  int v19; // [sp+10h] [bp-1Ch]@1
  int v20; // [sp+14h] [bp-18h]@1
  int v21; // [sp+18h] [bp-14h]@1
  int v22; // [sp+1Ch] [bp-10h]@1
  int v23; // [sp+20h] [bp-Ch]@1
  int v24; // [sp+24h] [bp-8h]@1
  int X; // [sp+28h] [bp-4h]@1

  v24 = pParty_global->sPartyPosX;
  v2 = pParty_global->sPartyPosY;
  v1 = pClass51_global->uNumBModels;
  *(float *)&v23 = (double)struct_576FE8.dword_000024 * 0.0000152587890625;
  v0 = 0;
  v18 = pClass51_global->uNumBModels;
  v21 = 0;
  class03_GetMouseClickPos(pGame->pClass03, (int)&X, (int)&v22);
  v3 = 1.0 / *(float *)&v23;
  v23 = X - 557;
  v19 = (signed __int64)((double)(X - 557) * v3 + (double)v24);
  v20 = (signed __int64)((double)v2 - (double)(v22 - 74) * v3);
  if ( dword_6BE360 != 2 || (v23 = 0, v1 <= 0) )
  {
LABEL_14:
    v17 = CMapStats_FindLocation(pMapStats, Str1);
    if ( v17 == v0 )
      result = (int)"No Maze Info for this maze on file!";
    else
     result = pMapStats->pMapInfos[v17].pLocationName;
  }
  else
  {
    v4 = 0;
    while ( 1 )
    {
      X = *(_DWORD *)(v4 + pClass51_global->pBModels + 172) - v19;
      v22 = *(_DWORD *)(v4 + pClass51_global->pBModels + 176) - v20;
      v6 = abs(v22);
      v7 = abs(X);
      v8 = sub_4621DA(v7, v6, v0);
      v5 = pClass51_global->pBModels;
      if ( v8 < 2 * *(_DWORD *)(v4 + pClass51_global->pBModels + 184) )
      {
        compile_error;//v11 = __SETO__(*(_DWORD *)(v4 + pClass51_global->pBModels + 76), v0);
        v9 = *(_DWORD *)(v4 + pClass51_global->pBModels + 76) == v0;
        v10 = *(_DWORD *)(v4 + pClass51_global->pBModels + 76) - v0 < 0;
        v24 = v0;
        if ( !((unsigned __int8)(v10 ^ v11) | v9) )
        {
          do
          {
            v12 = v0 + *(_DWORD *)(v4 + v5 + 84);
            v13 = *(_WORD *)(v12 + 292);
            if ( v13 )
            {
              if ( !(*(_BYTE *)(v12 + 30) & 0x10) )
              {
                v14 = sub_444732((void *)v13);
                v15 = v14;
                if ( v14 )
                {
                  if ( _strcmpi(v14, Class) )
                    v21 = (int)v15;
                }
              }
            }
            ++v24;
            v5 = pClass51_global->pBModels;
            v0 += 308;
          }
          while ( v24 < *(_DWORD *)(v4 + pClass51_global->pBModels + 76) );
        }
        result = v21;
        v0 = 0;
        if ( v21 )
          break;
      }
      ++v23;
      v4 += 188;
      if ( v23 >= v18 )
        goto LABEL_14;
    }
  }
  return result;
}

//----- (00444564) --------------------------------------------------------
char *__cdecl sub_444564()
{
  int v0; // ebx@3
  double v1; // st7@3
  int v2; // edi@3
  int v3; // eax@3
  int v4; // esi@5
  int v5; // ecx@6
  int v6; // edi@6
  int v7; // eax@6
  int v8; // eax@6
  unsigned __int8 v9; // zf@7
  unsigned __int8 v10; // sf@7
  int v11; // eax@9
  __int16 v12; // cx@9
  char *v13; // eax@11
  char *v14; // edi@11
  char *result; // eax@15
  int v16; // [sp+0h] [bp-20h]@3
  char *v17; // [sp+4h] [bp-1Ch]@3
  int v18; // [sp+8h] [bp-18h]@3
  float v19; // [sp+Ch] [bp-14h]@1
  int v20; // [sp+10h] [bp-10h]@1
  int v21; // [sp+14h] [bp-Ch]@1
  int v22; // [sp+18h] [bp-8h]@8
  int X; // [sp+1Ch] [bp-4h]@3

  v20 = struct_576FE8.dword_000030;
  v21 = struct_576FE8.dword_000034;
  v19 = (double)struct_576FE8.dword_00002C * 0.0000152587890625;
  if ( struct_576FE8.dword_00002C == 384 )
  {
   v20 = struct_576FE8.word_000038;
   v21 = struct_576FE8.word_00003A;
  }
  v17 = 0;
  v16 = pClass51_global->uNumBModels;
  class03_GetMouseClickPos(pGame->pClass03, &X, &v18);
  v1 = 1.0 / v19;
  v0 = (signed __int64)((double)(X - 229) * v1 + (double)v20);
  LODWORD(v19) = (signed __int64)((double)v21 - (double)(v18 - 181) * v1);
  v2 = abs(v0 + 22528) / 512;
  v3 = abs(LODWORD(v19) - 22528);
  if ( sub_47F04C(pClass51_global, v2, v3 / 512) && dword_6BE360 == 2 && (v4 = 0, v20 = 0, v16 > 0) )
  {
    while ( 1 )
    {
      X = *(_DWORD *)(v4 + pClass51_global->pBModels + 172) - v0;
      v18 = *(_DWORD *)(v4 + pClass51_global->pBModels + 176) - LODWORD(v19);
      v6 = abs(v18);
      v7 = abs(X);
      v8 = sub_4621DA(v7, v6, 0);
      v5 = pClass51_global->pBModels;
      if ( v8 < *(_DWORD *)(v4 + pClass51_global->pBModels + 184) )
      {
        v9 = *(_DWORD *)(v4 + pClass51_global->pBModels + 76) == 0;
        v10 = *(_DWORD *)(v4 + pClass51_global->pBModels + 76) < 0;
        v21 = 0;
        if ( !(v10 | v9) )
        {
          v22 = 0;
          do
          {
            v11 = v22 + *(_DWORD *)(v4 + v5 + 84);
            v12 = *(_WORD *)(v11 + 292);
            if ( v12 )
            {
              if ( !(*(_BYTE *)(v11 + 30) & 0x10) )
              {
                v13 = sub_444732((void *)v12);
                v14 = v13;
                if ( v13 )
                {
                  if ( _strcmpi(v13, Class) )
                    v17 = v14;
                }
              }
            }
            ++v21;
            v5 = pClass51_global->pBModels;
            v22 += 308;
          }
          while ( v21 < *(_DWORD *)(v4 + pClass51_global->pBModels + 76) );
        }
        result = v17;
        if ( v17 )
          break;
      }
      ++v20;
      v4 += 188;
      if ( v20 >= v16 )
        goto LABEL_17;
    }
  }
  else
  {
LABEL_17:
    result = 0;
  }
  return result;
}

//----- (00444732) --------------------------------------------------------
char *__thiscall sub_444732(void *this)
{
  int v1; // edx@1
  int *v2; // eax@2
  int v3; // ebx@4
  int v4; // esi@4
  char *result; // eax@6
  int v6; // eax@9
  int i; // esi@11
  int v8; // edx@12

  v1 = 0;
  if ( uLevelEVT_NumEvents <= 0 )
  {
LABEL_6:
    result = 0;
  }
  else
  {
   v2 = &pLevelEVT_Events[0].dword_000008;
    while ( 1 )
    {
      if ( (void *)*(v2 - 2) == this )
      {
        v3 = *v2;
        v4 = v2[3];
        if ( byte_5B3524[*v2] == 4 )
          break;
      }
      ++v1;
      v2 += 3;
      if ( v1 >= uLevelEVT_NumEvents )
        goto LABEL_6;
    }
    if ( byte_5B3524[v4] == 2 )
    {
      v6 = (unsigned __int8)byte_5B3525[v4]
         + (((unsigned __int8)byte_5B3526[v4]
           + (((unsigned __int8)byte_5B3527[v4] + ((unsigned __int8)byte_5B3528[v4] << 8)) << 8)) << 8);
LABEL_10:
      result = (char *)dword_59143C[13 * v6];
    }
    else
    {
      for ( i = 4 * (3 * v1 + 3) + 5989848; *(void **)i == this; i += 12 )
      {
        v8 = *(_DWORD *)(i + 8);
        if ( byte_5B3524[v8] == 2 )
        {
          v6 = (unsigned __int8)byte_5B3525[v8]
             + (((unsigned __int8)byte_5B3526[v8]
               + (((unsigned __int8)byte_5B3527[v8] + ((unsigned __int8)byte_5B3528[v8] << 8)) << 8)) << 8);
          if ( (unsigned int)v6 < 0x258 )
            goto LABEL_10;
        }
      }
      result = &pLevelStr[uLevelStrOffsets[(unsigned __int8)byte_5B3525[v3]]];
    }
  }
  return result;
}

//----- (00444810) --------------------------------------------------------
int __thiscall sub_444810(void *Str1)
{
  const char *v1; // edi@1
  signed int v2; // esi@1

  v1 = (const char *)Str1;
  v2 = 0;
  while ( _strcmpi(v1, (&off_4E6BDC)[4 * v2]) )
  {
    ++v2;
    if ( v2 >= 11 )
      return 0;
  }
  return v2 + 1;
}

//----- (00444839) --------------------------------------------------------
int __fastcall sub_444839(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, void *Str2)
{
  int v9; // ebx@1
  int v10; // edi@1
  signed int v11; // eax@1
  int v12; // eax@6
  const char *v13; // ST0C_4@6
  signed int v14; // eax@8
  const char *v15; // eax@14
  signed int v16; // eax@16
  int result; // eax@26
  int v18; // [sp-8h] [bp-40h]@9
  const char *v19; // [sp-4h] [bp-3Ch]@2
  int v20; // [sp-4h] [bp-3Ch]@9
  const char *v21; // [sp-4h] [bp-3Ch]@11
  char Str1; // [sp+Ch] [bp-2Ch]@1
  int v23; // [sp+34h] [bp-4h]@1

  v9 = a1;
  v10 = a2;
  v23 = sub_444810(Str2);
  dword_59117C = a3;
  dword_591178 = a4;
  dword_591174 = a5;
  dword_591170 = a6;
  dword_59116C = a7;
  dword_591168 = a8;
  dword_591164 = (char *)Str2;
  dword_591160 = v9;
  class24_fn1(pClass24_global);
  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  v11 = sub_44C28B();
  sprintfex(&Str1, "evt%02d", v11);
  if ( pParty_global->uAlignment )
  {
    if ( pParty_global->uAlignment != 2 )
      goto LABEL_6;
    v19 = "-c";
  }
  else
  {
    v19 = "-b";
  }
  strcat(&Str1, v19);
LABEL_6:
  v12 = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
  v13 = (&off_4E6BB0)[4 * v10];
  dword_591430 = 72 * v12 + 7145548;
  dword_59142C = 72 * class17_LoadTexture(pClass17_Icons_LOD, v13, 2) + 7145548;
  if ( v9 )
  {
    if ( !v23 )
      sub_4BF28F(pVideoPlayer, (unsigned int)*(&off_4E5F70 + 4 * word_59143A[26 * v9]), 1);
  }
  else
  {
    if ( !v23 )
    {
      v14 = CMapStats_FindLocation(pMapStats, Str1);
      if ( v14 )
      {
       v20 = pMapStats->pMapInfos[v14].pLocationName;
        v18 = pGlobalTXT_LocalizationStrings[410];
LABEL_10:
        sprintfex(byte_591098, (const char *)v18, v20);
        goto LABEL_20;
      }
      v21 = pGlobalTXT_LocalizationStrings[79];
      goto LABEL_19;
    }
  }
  v15 = (const char *)Str2;
  if ( *(_BYTE *)Str2 == 48 )
    v15 = Str1;
  v16 = CMapStats_FindLocation(pMapStats, v15);
  if ( v16 )
  {
    v20 = pMapStats->pMapInfos[v16].pLocationName;
    v18 = pGlobalTXT_LocalizationStrings[411];
    goto LABEL_10;
  }
  v21 = pGlobalTXT_LocalizationStrings[73];
LABEL_19:
  strcpy(byte_591098, v21);
LABEL_20:
  dword_507BBC = GUIWindowCreate(0, 0, 640, 480, 26, 0, (int)byte_591098);
  if ( byte_4E5F7D[16 * word_59143A[26 * v9]] )
    sub_4B1E92(v9, 1);
  if ( dword_6BE360 == 1 )
  {
    if ( uMaybeSelectedCharacter )
    {
      if ( pParty_global->dword_007778 & 0x30 )
        sub_4948B1(*(&ptr_A750C4 + uMaybeSelectedCharacter), 47, 0);
    }
  }
  result = v23;
  if ( v23 )
    dword_591160 = v23;
  return result;
}

//----- (00444A51) --------------------------------------------------------
char *__cdecl sub_444A51()
{
  const char **v0; // esi@5
  const char *v1; // eax@6
  char *result; // eax@12
  int v3; // eax@12
  char v4; // [sp-18h] [bp-84h]@11
  int v5; // [sp-14h] [bp-80h]@11
  int v6; // [sp-10h] [bp-7Ch]@11
  int v7; // [sp-Ch] [bp-78h]@11
  const char *v8; // [sp-8h] [bp-74h]@11
  int v9; // [sp-4h] [bp-70h]@11
  int v10; // [sp+Ch] [bp-60h]@1
  int v11; // [sp+14h] [bp-58h]@5
  int v12; // [sp+1Ch] [bp-50h]@5
  int v13; // [sp+60h] [bp-Ch]@1
  int v14; // [sp+64h] [bp-8h]@1
  int v15; // [sp+6Bh] [bp-1h]@11

  memcpy(&v10, pGUIWindow0, sizeof(struct GUIWindow));
  v14 = CMapStats_FindLocation(pMapStats, Str1);
  v13 = sub_444810(dword_591164);
  CD3DRenderer_DrawIndexedTexture(pD3DRenderer, 477, 0, dword_591430);
  CD3DRenderer_DrawIndexedTexture(
    pD3DRenderer,
    dword_4E5E50 - 4,
    dword_4E5EE0 - 4,
    dword_50795C != -1 ? 72 * dword_50795C + 7145548 : 0);
  CD3DRenderer_DrawIndexedTexture(pD3DRenderer, dword_4E5E50, dword_4E5EE0, dword_59142C);
  dword_507B04 = dword_5079E4;
  CD3DRenderer_DrawTransparentTexture(pD3DRenderer, 468, 0, dword_5079E4 != -1 ? 72 * dword_5079E4 + 7145548 : 0);
  CD3DRenderer_DrawIndexedTexture(pD3DRenderer, 556, 451, uTextureIdx_BtnXxU != -1 ? 72 * uTextureIdx_BtnXxU + 7145548 : 0);
  CD3DRenderer_DrawIndexedTexture(pD3DRenderer, 476, 451, uTextureIdx_BtnXokU != -1 ? 72 * uTextureIdx_BtnXokU + 7145548 : 0);
  if ( CVideoPlayer_IsAnyMovieLoaded(pVideoPlayer) || v13 )
  {
    if ( *dword_591164 != 48 )
      v14 = CMapStats_FindLocation(pMapStats, dword_591164);
  }
  v0 = (const char **)&pMapStats->pMapInfos[v14];
  v10 = 493;
  v11 = 126;
  v12 = 366;
  sub_44D406((int)&v10, pFontCreate, 0, 5, 0, *v0, 3);
  v10 = 483;
  v11 = 148;
  v12 = 334;
  if ( dword_591160 )
  {
    v1 = (&off_4EB080)[4 * dword_591160];
  }
  else
  {
    if ( v14 )
    {
      sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[409], *v0);
      v1 = &TmpBuf;
      goto LABEL_12;
    }
    v1 = Class;
  }
  if ( !v1 )
  {
    v9 = 1410;
    v8 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Events.cpp";
    v13 = (int)&v4;
    sub_40E2C8(&v4, "No transition text found!", (int)&v15);
    sub_466D09(&v13, *(int *)&v4, v5, v6, v7, v8, v9);
    v1 = Class;
  }
LABEL_12:
  v9 = 3;
  v8 = v1;
  v7 = 0;
  v3 = sub_44C59D(pFontCreate, v1, (int)&v10, 0, 0);
  result = sub_44D406((int)&v10, pFontCreate, 0, (212 - v3) / 2 + 101, v7, v8, v9);
  dword_5B5924 = 1;
  return result;
}

//----- (00444C8F) --------------------------------------------------------
int __cdecl sub_444C8F()
{
  signed int v0; // eax@1
  signed int v1; // eax@6
  int result; // eax@9
  const char *v3; // [sp-4h] [bp-2Ch]@2
  char Str1; // [sp+0h] [bp-28h]@1

  class24_fn1(pClass24_global);
  v0 = sub_44C28B();
  sprintfex(&Str1, "evt%02d", v0);
  if ( pParty_global->uAlignment )
  {
    if ( pParty_global->uAlignment != 2 )
      goto LABEL_6;
    v3 = "-c";
  }
  else
  {
    v3 = "-b";
  }
  strcat(&Str1, v3);
LABEL_6:
  dword_591430 = 72 * class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2) + 7145548;
  dword_59142C = 72 * class17_LoadTexture(pClass17_Icons_LOD, "outside", 2) + 7145548;
  v1 = CMapStats_FindLocation(pMapStats, Str1);
  if ( v1 )
    sprintfex(byte_591098, pGlobalTXT_LocalizationStrings[410], pMapStats->pMapInfos[v1].pLocationName);
  else
    strcpy(byte_591098, pGlobalTXT_LocalizationStrings[79]);
  result = GUIWindowCreate(0, 0, 640, 480, 17, 0, (int)byte_591098);
  dword_507BBC = result;
  return result;
}

//----- (00444D80) --------------------------------------------------------
signed int __cdecl sub_444D80()
{
  signed int v0; // esi@1
  int v1; // eax@1
  int v2; // eax@3
  int v3; // eax@5
  int v4; // eax@7

  v0 = dword_6BD07C;
  LOBYTE(v1) = sub_476395(5);
  if ( v1 )
    --v0;
  LOBYTE(v2) = sub_476395(6);
  if ( v2 )
    v0 -= 2;
  LOBYTE(v3) = sub_476395(7);
  if ( v3 )
    v0 -= 3;
  LOBYTE(v4) = sub_476395(0x2C);
  if ( v4 )
    --v0;
  if ( v0 < 1 )
    v0 = 1;
  return v0;
}

//----- (00444DCA) --------------------------------------------------------
void __cdecl sub_444DCA()
{
  signed int v0; // edi@1
  signed int v1; // eax@2
  int *v2; // edi@2
  const char *v3; // ST14_4@2
  int v4; // eax@5
  int v5; // [sp-Ch] [bp-90h]@3
  signed int v6; // [sp-8h] [bp-8Ch]@3
  int v7; // [sp+Ch] [bp-78h]@1
  int v8; // [sp+14h] [bp-70h]@2
  int v9; // [sp+1Ch] [bp-68h]@2
  char Str2; // [sp+60h] [bp-24h]@1
  int v11; // [sp+80h] [bp-4h]@1

  memcpy(&v7, pGUIWindow0, sizeof(struct GUIWindow));
  v11 = CMapStats_FindLocation(pMapStats, Str1);
  sub_48902E(pClass51_global->string_000000, pParty_global->sPartyPosX, pParty_global->sPartyPosY, &Str2, 20);
  v0 = CMapStats_FindLocation(pMapStats, &Str2);
  CD3DRenderer_DrawIndexedTexture(pD3DRenderer, 477, 0, dword_591430);
  CD3DRenderer_DrawTransparentTexture(pD3DRenderer, 468, 0, dword_507B04 != -1 ? 72 * dword_507B04 + 7145548 : 0);
  CD3DRenderer_DrawIndexedTexture(pD3DRenderer, dword_4E5E50, dword_4E5EE0, dword_59142C);
  CD3DRenderer_DrawIndexedTexture(pD3DRenderer, 556, 451, uTextureIdx_BtnXxU != -1 ? 72 * uTextureIdx_BtnXxU + 7145548 : 0);
  CD3DRenderer_DrawIndexedTexture(pD3DRenderer, 476, 451, uTextureIdx_BtnXokU != -1 ? 72 * uTextureIdx_BtnXokU + 7145548 : 0);
  if ( v0 )
  {
   v2 = &pMapStats->pMapInfos[v0];
    v7 = 493;
    v8 = 126;
    v3 = (const char *)*v2;
    v9 = 366;
    sub_44D406((int)&v7, pFontCreate, 0, 4, 0, v3, 3);
    v7 = 483;
    v8 = 148;
    v9 = 334;
    v1 = sub_444D80();
    if ( v1 == 1 )
    {
      v6 = 1;
      v5 = pGlobalTXT_LocalizationStrings[663];
    }
    else
    {
      v6 = v1;
      v5 = pGlobalTXT_LocalizationStrings[128];
    }
    sprintfex(TmpBuf, (const char *)v5, v6, *v2);
    strcat(TmpBuf, "\n \n");
    sprintfex(pStringBuffer, pGlobalTXT_LocalizationStrings[126], pMapStats->pMapInfos[v11].pLocationName);
    strcat(TmpBuf, pStringBuffer);
    v4 = sub_44C59D(pFontCreate, &TmpBuf, (int)&v7, 0, 0);
    sub_44D406((int)&v7, pFontCreate, 0, (212 - v4) / 2 + 101, 0, &TmpBuf, 3);
    dword_5B5924 = 1;
  }
}

//----- (00444FBE) --------------------------------------------------------
void __cdecl sub_444FBE()
{
  int v0; // esi@1
  int v1; // esi@4
  char *v2; // eax@6
  int v3; // edi@12
  char Str1; // [sp+Ch] [bp-120h]@12
  char v5; // [sp+D4h] [bp-58h]@4
  int v6; // [sp+DCh] [bp-50h]@4
  int v7; // [sp+E4h] [bp-48h]@4
  int v8; // [sp+128h] [bp-4h]@1

  v0 = pFontArrus;
  v8 = pFontArrus;
  if ( dword_F8B1E8 )
  {
    if ( !byte_5B0938 )
      strcpy(&byte_5B0938, dword_F8B1E8);
  }
  v6 = 460;
  v7 = 452;
  v1 = sub_44C59D(v0, &byte_5B0938, (int)&v5, 12, 0) + 7;
  if ( 352 - v1 < 8 )
  {
    v8 = pFontCreate;
    v1 = sub_44C59D(pFontCreate, &byte_5B0938, (int)&v5, 12, 0) + 7;
  }
  sub_4A6A68(
    pD3DRenderer,
    8,
    352 - v1,
    uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 : 0,
    *(_WORD *)(uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 + 0x1A : 26) - v1);
  CD3DRenderer_DrawIndexedTexture(pD3DRenderer, 8, 347 - v1, pClass18_EndcapTexture);
  v2 = FitTextInAWindow(&byte_5B0938, v8, (int)&v5, 12, 0);
  FontDrawText(pGUIWindow2, v8, 12, 354 - v1, v2, 0, 0, 0);
  CD3DRenderer_DrawRGBTexture(pD3DRenderer, 0, 352, pTexture_StatusBar);
  if ( *(_DWORD *)(pGUIWindow2 + 64) != 1 )
  {
    if ( *(_DWORD *)(pGUIWindow2 + 64) == 2 )
    {
      *(_DWORD *)(pGUIWindow2 + 64) = 0;
      strcpy(&byte_5C3428, &byte_69AF00);
LABEL_16:
      sub_4452BB();
      return;
    }
    if ( *(_DWORD *)(pGUIWindow2 + 64) != 3 )
      return;
    *(_DWORD *)(pGUIWindow2 + 64) = 0;
LABEL_15:
    memset(&byte_5C3428, 0, 0xC8u);
    goto LABEL_16;
  }
  if ( *(_DWORD *)(pGUIWindow2 + 28) == 26 )
  {
    wsprintfA(&Str1, "%s %s", &byte_5C3428, &byte_69AF00);
    v3 = sub_44C51E(pFontLucida, &Str1);
    FontDrawText(pGUIWindow2, pFontLucida, 13, 357, &Str1, 0, 0, 0);
    sub_459C2B(pGUIWindow2, v3 + 13, 357, pFontLucida);
    return;
  }
  if ( byte_69AF00 )
  {
    sub_459ED1(&dword_69AE00, 0);
    goto LABEL_15;
  }
}

//----- (004451A8) --------------------------------------------------------
void __fastcall sub_4451A8(int a1, int a2, int a3)
{
  int v3; // edi@1
  int v4; // esi@1

  v4 = a2;
  v3 = a1;
  if ( !pGUIWindow2 )
  {
    if ( pParty_global->dword_007778 & 2 )
      sub_44103C();
    if ( !dword_597F18 )
      AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
    class24_fn1(pClass24_global2);
    class24_fn1(pClass24_global);
    dword_5C3418 = v3;
    dword_5C341C = v4;
    dword_591094 = dword_5C3420;
    pGUIWindow2 = GUIWindowCreate(0, 0, 640, 480, 19, a3, 0);
    GUIButtonCreate(pGUIWindow2, 61, 424, 31, 40, 2, 94, 110, 1, 49, "", 0);
    GUIButtonCreate(pGUIWindow2, 177, 424, 31, 40, 2, 94, 110, 2, 50, "", 0);
    GUIButtonCreate(pGUIWindow2, 292, 424, 31, 40, 2, 94, 110, 3, 51, "", 0);
    GUIButtonCreate(pGUIWindow2, 407, 424, 31, 40, 2, 94, 110, 4, 52, "", 0);
  }
}

//----- (004452BB) --------------------------------------------------------
void __cdecl sub_4452BB()
{
  GUIWindowDelete(pGUIWindow2);
  pGUIWindow2 = 0;
  dword_5C3420 = dword_591094;
  dword_597F18 = dword_5C341C;
  sub_44684A_LooksLikeEventProcessor(dword_5C3418, 0, 1);
  dword_597F18 = 0;
  dword_5C3420 = 0;
  sub_426363(pClass24_global);
}

//----- (00445308) --------------------------------------------------------
int __fastcall sub_445308(int a1)
{
  int result; // eax@12

  if ( a1 == 10
    || a1 == 11
    || a1 == 12
    || a1 == 33
    || a1 == 34
    || a1 == 39
    || a1 == 40
    || a1 == 41
    || a1 == 42
    || a1 == 43
    || a1 == 52 )
    result = dword_737C30[5 * a1];
  else
    result = dword_722320;
  return result;
}

//----- (00445350) --------------------------------------------------------
void __cdecl sub_445350()
{
  int v0; // eax@2
  char *v1; // ebx@2
  unsigned __int16 v2; // di@2
  int v3; // eax@2
  const char *v4; // esi@3
  int v5; // eax@11
  char *v6; // ecx@13
  int v7; // eax@16
  int v8; // edi@19
  char *v9; // ecx@27
  int v10; // eax@29
  int v11; // eax@30
  int v12; // esi@39
  char *v13; // eax@41
  int v14; // eax@43
  int v15; // edi@43
  signed int v16; // eax@44
  int v17; // eax@46
  int v18; // eax@47
  int v19; // eax@48
  int v20; // eax@49
  int v21; // eax@50
  int v22; // eax@51
  int v23; // eax@53
  int v24; // eax@59
  int v25; // eax@65
  int v26; // eax@66
  int v27; // eax@67
  int v28; // eax@68
  int v29; // eax@69
  __int16 v30; // cx@83
  int v31; // ecx@86
  int j; // eax@93
  int v34; // ecx@93
  int v35; // ebx@93
  int v36; // esi@93
  unsigned int v37; // eax@93
  int v38; // eax@94
  int v39; // eax@95
  signed int v40; // esi@99
  int v41; // ebx@102
  int v42; // edi@102
  signed int v43; // eax@102
  int v44; // esi@103
  unsigned __int16 v45; // ax@104
  int v46; // ecx@104
  int v47; // eax@104
  int v48; // edx@104
  char v49; // [sp+4h] [bp-110h]@39
  int v50; // [sp+Ch] [bp-108h]@39
  int v51; // [sp+14h] [bp-100h]@39
  char v52; // [sp+58h] [bp-BCh]@2
  int v53; // [sp+60h] [bp-B4h]@2
  int v54; // [sp+68h] [bp-ACh]@2
  int v55; // [sp+ACh] [bp-68h]@42
  int v56; // [sp+B4h] [bp-60h]@42
  int v57; // [sp+BCh] [bp-58h]@42
  int v58; // [sp+D4h] [bp-40h]@42
  int v59; // [sp+E4h] [bp-30h]@42
  char *Str; // [sp+100h] [bp-14h]@104
  __int16 v61[2]; // [sp+104h] [bp-10h]@2
  int v62; // [sp+108h] [bp-Ch]@82
  int i; // [sp+10Ch] [bp-8h]@39
  const char *v64; // [sp+110h] [bp-4h]@32

  if ( !dword_507BBC )
    return;
  memcpy(&v52, (const void *)dword_507BBC, 0x54u);
  v1 = sub_4459F9(dword_591090);
  v3 = sub_445C8B(dword_591090);
  v53 -= 10;
  v54 -= 10;
  *(_DWORD *)v61 = v3;
  0xFFFFFFFF;
  0xFFE1CD23;
  v2 = 0xFF1599E9;
  CD3DRenderer_DrawIndexedTexture(pD3DRenderer, 477, 0, dword_591430);
  CD3DRenderer_DrawTransparentTexture(pD3DRenderer, 468, 0, dword_507B04 != -1 ? 72 * dword_507B04 + 7145548 : 0);
  CD3DRenderer_DrawIndexedTexture(
    pD3DRenderer,
    dword_4E5E50 - 4,
    dword_4E5EE0 - 4,
    dword_50795C != -1 ? 72 * dword_50795C + 7145548 : 0);
  CD3DRenderer_DrawIndexedTexture(pD3DRenderer, dword_4E5E50, dword_4E5EE0, dword_59140C[0]);
  v0 = *((_DWORD *)v1 + 6);
  if ( v0 )
  {
    v4 = &TmpBuf;
    //sprintfex(&TmpBuf, (const char *)dword_5E4834, *(_DWORD *)v1, dword_73C290[v0]);
    sprintfex(TmpBuf, pGlobalTXT_LocalizationStrings[429], *(_DWORD *)v1, aNPCProfessionNames[v0]);
  }
  else
  {
    strcpy((char *)&TmpBuf, *(const char **)v1);
    v4 = &TmpBuf;
  }
  sub_44D406((int)&v52, pFontArrus, 483, 112, v2, v4, 3);
  sub_49135E(pParty_global);
  if ( dword_59108C > 89 )
  {
    if ( dword_59108C == 90 )
    {
      v7 = pGlobalTXT_LocalizationStrings[577];
      goto LABEL_37;
    }
    if ( dword_59108C == 91 )
    {
      sprintfex(v4, pGlobalTXT_LocalizationStrings[576], dword_F8B1B4);
      v64 = v4;
      v8 = 0;
      goto LABEL_39;
    }
    if ( dword_59108C == 92 )
    {
      v7 = pGlobalTXT_LocalizationStrings[582];
      goto LABEL_37;
    }
  }
  else
  {
    if ( dword_59108C == 89 )
    {
      v7 = pGlobalTXT_LocalizationStrings[574];
      goto LABEL_37;
    }
    if ( dword_59108C == 13 )
    {
      v5 = 5 * *((_DWORD *)v1 + 6);
      goto LABEL_18;
    }
    if ( dword_59108C > 18 )
    {
      if ( dword_59108C > 24 )
      {
        if ( dword_59108C == 77 )
        {
          v5 = 5 * *((_DWORD *)v1 + 6);
          if ( byte_F8B1EC )
          {
            v6 = (char *)(&dword_737C2C)[20 * *((_DWORD *)v1 + 6)];
            goto LABEL_19;
          }
          if ( v1[8] & 0x80 )
          {
            v6 = (char *)dword_737C38[5 * *((_DWORD *)v1 + 6)];
LABEL_19:
            v8 = 0;
            v7 = (int)sub_495461(v6, uMaybeSelectedCharacter - 1, 0, 0, 0, 0);
LABEL_38:
            v64 = (const char *)v7;
            goto LABEL_39;
          }
LABEL_18:
          v6 = (char *)(&dword_737C34)[4 * v5];
          goto LABEL_19;
        }
        goto LABEL_24;
      }
      if ( byte_5B0938 )
        goto LABEL_24;
      v7 = (int)dword_F8B1E8;
LABEL_37:
      v8 = 0;
      goto LABEL_38;
    }
  }
LABEL_24:
  if ( *(_DWORD *)v61 == 1 )
  {
    v11 = *((_DWORD *)v1 + 7);
    v8 = 0;
    if ( v11 )
    {
      v10 = dword_73BA54[((*((_DWORD *)v1 + 2) & 3) == 2) + 2 * v11];
      goto LABEL_32;
    }
  }
  else
  {
    if ( *(_DWORD *)v61 == 2 )
    {
      v8 = 0;
      if ( v1[8] & 0x80 )
        v9 = (char *)dword_737C38[5 * *((_DWORD *)v1 + 6)];
      else
        v9 = (char *)(&dword_737C34)[20 * *((_DWORD *)v1 + 6)];
      v10 = (int)sub_495461(v9, uMaybeSelectedCharacter - 1, 0, 0, 0, 0);
LABEL_32:
      v64 = (const char *)v10;
      if ( v10 == v8 )
        goto LABEL_42;
LABEL_39:
      v50 = 460;
      v51 = 452;
      i = pFontArrus;
      v12 = sub_44C59D(pFontArrus, v64, (int)&v49, 13, v8) + 7;
      if ( 352 - v12 < 8 )
      {
        i = pFontCreate;
        v12 = sub_44C59D(pFontCreate, v64, (int)&v49, 13, v8) + 7;
      }
      sub_4A6A68(pD3DRenderer,
        8,
        352 - v12,
        uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 : 0,
        *(_WORD *)(uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 + 0x1A : 26) - v12);
      CD3DRenderer_DrawIndexedTexture(pD3DRenderer, 8, 347 - v12, pClass18_EndcapTexture);
      v13 = FitTextInAWindow(v64, i, (int)&v49, 13, v8);
      FontDrawText(dword_507BBC, i, 13, 354 - v12, v13, v8, v8, (char *)v8);
      goto LABEL_42;
    }
  }
LABEL_42:
  memcpy(&v55, (const void *)dword_507BBC, 0x54u);
  v55 = 483;
  v56 = 148;
  v57 = 334;
  for ( i = v59; i < v59 + v58; ++i )
  {
    v14 = GUIWindow_GetChild((int)&v55, i);
    v15 = v14;
    if ( !v14 )
      break;
    v16 = *(_DWORD *)(v14 + 36);
    if ( v16 > 24 )
    {
      v25 = v16 - 76;
      if ( v25 )
      {
        v26 = v25 - 1;
        if ( !v26 )
        {
          v24 = pGlobalTXT_LocalizationStrings[407];
          goto LABEL_79;
        }
        v27 = v26 - 8;
        if ( !v27 )
        {
          v24 = pGlobalTXT_LocalizationStrings[578];
          goto LABEL_79;
        }
        v28 = v27 - 1;
        if ( !v28 )
        {
          v24 = pGlobalTXT_LocalizationStrings[579];
          goto LABEL_79;
        }
        v29 = v28 - 1;
        if ( !v29 )
        {
          v24 = pGlobalTXT_LocalizationStrings[580];
          goto LABEL_79;
        }
        if ( v29 == 1 )
        {
          v24 = pGlobalTXT_LocalizationStrings[581];
          goto LABEL_79;
        }
        goto LABEL_71;
      }
      if ( !(v1[8] & 0x80) )
      {
        v24 = pGlobalTXT_LocalizationStrings[406];
        goto LABEL_79;
      }
    }
    else
    {
      if ( v16 == 24 )
      {
        v23 = *((_DWORD *)v1 + 15);
LABEL_63:
        v24 = (int)(&dword_721660)[8 * v23];
        if ( !v24 )
        {
          v24 = (int)Class;
          *(_DWORD *)(v15 + 36) = 0;
        }
        goto LABEL_79;
      }
      v17 = v16 - 9;
      if ( !v17 )
      {
        v24 = sub_445308(*((_DWORD *)v1 + 6));
        goto LABEL_79;
      }
      v18 = v17 - 4;
      if ( v18 )
      {
        v19 = v18 - 6;
        if ( !v19 )
        {
          v23 = *((_DWORD *)v1 + 10);
          goto LABEL_63;
        }
        v20 = v19 - 1;
        if ( !v20 )
        {
          v23 = *((_DWORD *)v1 + 11);
          goto LABEL_63;
        }
        v21 = v20 - 1;
        if ( !v21 )
        {
          v23 = *((_DWORD *)v1 + 12);
          goto LABEL_63;
        }
        v22 = v21 - 1;
        if ( !v22 )
        {
          v23 = *((_DWORD *)v1 + 13);
          goto LABEL_63;
        }
        if ( v22 == 1 )
        {
          v23 = *((_DWORD *)v1 + 14);
          goto LABEL_63;
        }
LABEL_71:
        v24 = (int)Class;
        goto LABEL_79;
      }
      if ( !(v1[8] & 0x80) )
      {
        v24 = pGlobalTXT_LocalizationStrings[122];
        goto LABEL_79;
      }
    }
    sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[408], *(_DWORD *)v1);
    v24 = (int)&TmpBuf;
LABEL_79:
    if ( byte_ACD76D )
    {
      if ( byte_ACD76D != -1 )
      {
        v64 = 0;
        if ( (signed int)uNumActors > 0 )
        {
          v62 = &pActors[0].word_0000B0;
          *(_DWORD *)v61 = uNumActors;
          do
          {
            v30 = *(_WORD *)v62;
            if ( *(_WORD *)v62 == 5 || v30 == 11 || v30 == 19 || (v31 = *(_DWORD *)(v62 + 636)) != 0 && (v31 & 7) == 4 )
              ++v64;
            v62 += 836;
          }
          while (0);
          compile_error;//while ( *(_DWORD *)v61-- != 1 );
        }
        if ( v64 == (const char *)uNumActors )
          v24 = pGlobalTXT_LocalizationStrings[658];
      }
    }
    strcpy((char *)(v15 + 85), (const char *)v24);
  }
  v35 = 0;
  v64 = 0xFFFFFFFF;
  v37 = 0xFFE1CD23;
  v34 = dword_507BBC;
  *(_DWORD *)v61 = v37;
  v36 = *(_DWORD *)(dword_507BBC + 56);
  for ( j = v36 + *(_DWORD *)(dword_507BBC + 40);
        v36 < j;
        j = *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56) )
  {
    v38 = GUIWindow_GetChild(v34, v36);
    if ( !v38 )
    {
      v34 = dword_507BBC;
      break;
    }
    v39 = sub_44C59D(pFontArrus, (const char *)(v38 + 85), (int)&v55, 0, 0);
    v34 = dword_507BBC;
    v35 += v39;
    ++v36;
  }
  v40 = *(_DWORD *)(v34 + 40);
  if ( v40 )
  {
    i = (174 - v35) / v40;
    if ( (174 - v35) / v40 > 32 )
      i = 32;
    v62 = 1;
    v43 = 174 - i * v40 - v35;
    v41 = *(_DWORD *)(v34 + 56);
    v42 = v43 / 2 - i / 2 + 138;
    if ( v41 < v41 + v40 )
    {
      do
      {
        v44 = GUIWindow_GetChild(v34, v41);
        if ( !v44 )
          break;
        *(_DWORD *)(v44 + 4) = i + v42;
        Str = (char *)(v44 + 85);
        v47 = sub_44C59D(pFontArrus, (const char *)(v44 + 85), (int)&v55, 0, 0);
        v46 = *(_DWORD *)(v44 + 4);
        v48 = v62;
        *(_DWORD *)(v44 + 12) = v47;
        v42 = v46 + v47 - 1;
        *(_DWORD *)(v44 + 20) = v42;
        v45 = v61[0];
        if ( *(_DWORD *)(dword_507BBC + 44) != v48 )
          v45 = (unsigned __int16)v64;
        sub_44D406((int)&v55, pFontArrus, 0, v46, v45, Str, 3);
        v34 = dword_507BBC;
        ++v62;
        ++v41;
      }
      while ( v41 < *(_DWORD *)(dword_507BBC + 40) + *(_DWORD *)(dword_507BBC + 56) );
    }
  }
  CD3DRenderer_DrawIndexedTexture(pD3DRenderer, 471, 445, dword_506438 != -1 ? 72 * dword_506438 + 7145548 : 0);
}

//----- (004459F9) --------------------------------------------------------
char *__fastcall sub_4459F9(signed int a1)
{
  signed int v1; // esi@1
  char *result; // eax@5
  int v5; // ecx@9
  int v6; // esi@9
  CHAR *v7; // ebx@14
  _UNKNOWN *v8; // edi@14
  unsigned __int8 v9; // al@22
  char v10; // [sp-18h] [bp-2Ch]@4
  int v11; // [sp-14h] [bp-28h]@4
  int v12; // [sp-10h] [bp-24h]@4
  int v13; // [sp-Ch] [bp-20h]@4
  char *v16; // [sp+Ch] [bp-8h]@4
  int v17; // [sp+13h] [bp-1h]@4
 int i;

  v1 = a1;
  if ( a1 >= 0 )
  {
    if ( a1 < 5000 )
    {
      if ( a1 >= 501 )
      {
        v16 = &v10;
        sub_40E2C8(&v10, "NPC id exceeds MAX_DATA!", (int)&v17);
        sub_466D09(&v16, *(int *)&v10, v11, v12, v13, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Events.cpp", __LINE__);
      }
      return &pNPCStats->pNPCData2[v1];
    }
    return &pNPCStats->array_0013EF4[a1 - 5000];
  }
  if ( a1 >= 5000 )
    return &pNPCStats->array_0013EF4[a1 - 5000];
  if ( dword_591090 >= 0 )
  {
    result = 0;
  }
  else
  {
    v6 = abs(dword_591090) - 1;
    v5 = 0;

    for (i = 0; i < 4; ++i)
    {
      if (array_AD4674[i].pNPCName)
        TmpBuf[v5++] = i;
    }


    v16 = 0;
    if (pNPCStats->dword_017FC4 > 0)
    {
      v7 = TmpBuf + v5;
      v8 = pNPCStats->pNPCData2;
      do
      {
        if ( *((_BYTE *)v8 + 8) & 0x80 )
        {
         if (!array_AD4674[0].pNPCName || strcmp(*(const char **)v8, array_AD4674[0].pNPCName))
          {
           if (!array_AD4674[1].pNPCName || strcmp(*(const char **)v8, array_AD4674[1].pNPCName))
              *v7++ = (_BYTE)v16 + 2;
          }
        }
        ++v16;
        v8 = (char *)v8 + 76;
      }
      while ( (signed int)v16 < pNPCStats->dword_017FC4);
    }
    v9 = TmpBuf[v6];
    if ( v9 >= 2 )
     result = &pNPCStats->pNPCData[499 + v9];
    else
      result = &array_AD4674[v9];
  }
  return result;
}

//----- (00445B2C) --------------------------------------------------------
char *__fastcall sub_445B2C(signed int a1, int a2)
{
  int v2; // edi@1
  signed int v3; // esi@1
  char *result; // eax@5
  int v7; // ecx@9
  int v8; // esi@9
  _UNKNOWN *v9; // edi@14
  int v10; // ecx@20
  unsigned __int8 v11; // al@23
  char v12; // [sp-18h] [bp-34h]@4
  int v13; // [sp-14h] [bp-30h]@4
  int v14; // [sp-10h] [bp-2Ch]@4
  int v15; // [sp-Ch] [bp-28h]@4
  int v18; // [sp+Ch] [bp-10h]@1
  CHAR *v19; // [sp+10h] [bp-Ch]@14
  int v20; // [sp+14h] [bp-8h]@13
  int v21; // [sp+1Bh] [bp-1h]@4
 int i;

  v3 = a1;
  v2 = a2;
  v18 = a2;
  if ( a1 >= 0 )
  {
    if ( a1 < 5000 )
    {
      if ( a1 >= 501 )
      {
        v18 = (int)&v12;
        sub_40E2C8(&v12, "NPC id exceeds MAX_DATA!", (int)&v21);
        sub_466D09(&v18, *(int *)&v12, v13, v14, v15, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Events.cpp", __LINE__);
      }
      *(_DWORD *)v2 = v3;
      return &pNPCStats->pNPCData2[v3];
    }
LABEL_7:
    *(_DWORD *)a2 = a1 - 5000;
    return &pNPCStats->array_0013EF4[a1 - 5000];
  }
  if ( a1 >= 5000 )
    goto LABEL_7;
  if ( dword_591090 >= 0 )
  {
    *(_DWORD *)a2 = 0;
    result = 0;
  }
  else
  {
    v8 = abs(dword_591090) - 1;
    v7 = 0;

    for (i = 0; i < 2; ++i)
    {
      if (array_AD4674[i].pNPCName)
        TmpBuf[v7++] = i;
    }

    v20 = 0;
    if (pNPCStats->dword_017FC4 > 0)
    {
      v9 = pNPCStats->pNPCData2;
      v19 = TmpBuf + v7;
      do
      {
        if ( *((_BYTE *)v9 + 8) & 0x80 )
        {
         if (!array_AD4674[0].pNPCName || strcmp(*(const char **)v9, array_AD4674[0].pNPCName))
          {
           if (!array_AD4674[1].pNPCName || strcmp(*(const char **)v9, array_AD4674[1].pNPCName))
            {
              v10 = (int)v19++;
              *(_BYTE *)v10 = v20 + 2;
            }
          }
        }
        ++v20;
        v9 = (char *)v9 + 76;
      }
      while ( v20 < pNPCStats->dword_017FC4);
      v2 = v18;
    }
    v11 = TmpBuf[v8];
    if ( v11 >= 2 )
    {
      *(_DWORD *)v2 = v11 - 2;
      result = &pNPCStats->pNPCData[499 + (unsigned __int8)TmpBuf[v8]];
    }
    else
    {
      *(_DWORD *)v2 = v11;
      result = &array_AD4674[(unsigned __int8)TmpBuf[v8]];
    }
  }
  return result;
}

//----- (00445C8B) --------------------------------------------------------
int __fastcall sub_445C8B(signed int a1)
{
  int v1; // ebx@1
  int v5; // ecx@6
  int v6; // edi@6
  CHAR *v7; // ebp@11
  _UNKNOWN *v8; // esi@11
 int i;

  v1 = 0;
  if ( a1 >= 0 )
  {
    if ( a1 < 5000 )
      return 1;
    return 2;
  }
  if ( a1 >= 5000 )
    return 2;
  v6 = abs(dword_591090) - 1;
  v5 = 0;

  for (i = 0; i < 2; ++i)
  {
   if (array_AD4674[i].pNPCName)
      TmpBuf[v5++] = i;
  }

  if (pNPCStats->dword_017FC4 > 0)
  {
    v7 = TmpBuf + v5;
    v8 = pNPCStats->pNPCData2;
    do
    {
      if ( *((_BYTE *)v8 + 8) & 0x80 )
      {
       if (!array_AD4674[0].pNPCName || strcmp(*(const char **)v8, array_AD4674[0].pNPCName))
        {
         if (!array_AD4674[1].pNPCName || strcmp(*(const char **)v8, array_AD4674[1].pNPCName))
            *v7++ = v1 + 2;
        }
      }
      ++v1;
      v8 = (char *)v8 + 76;
    }
    while ( v1 < pNPCStats->dword_017FC4);
  }
  return ((unsigned __int8)TmpBuf[v6] < 2) + 1;
}

//----- (00445D4A) --------------------------------------------------------
__int16 __fastcall sub_445D4A(int a1, int a2)
{
  int v2; // eax@1
  char *v3; // ebp@1
  int v4; // esi@1
  signed int v5; // ecx@1
  char *v6; // eax@1
  signed int v7; // eax@3
  int v8; // esi@8
  int v9; // eax@8
  int v10; // eax@11
  int v11; // ecx@19
  signed int v12; // eax@21
  __int16 result; // ax@29
  int v14; // [sp-8h] [bp-44h]@34
  const char *v15; // [sp-4h] [bp-40h]@4
  int v16; // [sp-4h] [bp-40h]@34
  signed int v17; // [sp-4h] [bp-40h]@35
  int v18; // [sp+10h] [bp-2Ch]@1
  char Str1; // [sp+14h] [bp-28h]@3

  v4 = a1;
  v18 = a2;
  dword_A74CDC = -1;
  dword_AE336C = -1;
  class24_fn1(pClass24_global);
  class24_fn1(pClass24_global2);
  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  dword_59108C = 0;
  v5 = *(_WORD *)(v4 + 32);
  dword_591090 = *(_WORD *)(v4 + 32);
  dword_591088 = v4;
  v6 = sub_4459F9(v5);
  v3 = v6;
  v2 = *((_DWORD *)v6 + 2);
  if ( (v2 & 3) != 2 )
    *((_DWORD *)v3 + 2) = v2 + 1;
  v7 = sub_44C28B();
  sprintfex(&Str1, "evt%02d", v7);
  if ( !pParty_global->uAlignment )
  {
    v15 = "-b";
LABEL_7:
    strcat(&Str1, v15);
    goto LABEL_8;
  }
  if ( pParty_global->uAlignment == 2 )
  {
    v15 = "-c";
    goto LABEL_7;
  }
LABEL_8:
  v9 = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
  dword_5913F0 = 0;
  dword_591424 = 1;
  dword_591430 = 72 * v9 + 7145548;
  sprintfex(&Str1, "npc%03u", *((_DWORD *)v3 + 1));
  v8 = 0;
  dword_59140C[0] = 72 * class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2) + 7145548;
  dword_591084 = dword_506128;
  dword_507B04 = dword_5079E4;
  if ( !(v3[8] & 0x80) && *((_DWORD *)v3 + 5) >= 0 )
  {
    if ( sub_49135E(pParty_global) <= *((_DWORD *)v3 + 3)
      || (v10 = *((_DWORD *)v3 + 2) & 0xFFFFFF7F, (*((_DWORD *)v3 + 2) & 0xFFFFFF7F) < 0) )
    {
LABEL_16:
      v8 = 1;
      goto LABEL_17;
    }
    if ( v10 > 1 )
    {
      if ( v10 == 2 )
      {
        v17 = 3;
        goto LABEL_36;
      }
      if ( v10 != 3 )
      {
        if ( v10 == 4 )
          goto LABEL_17;
        goto LABEL_16;
      }
LABEL_35:
      v17 = 2;
LABEL_36:
      v8 = v17;
      goto LABEL_17;
    }
    if ( *((_DWORD *)v3 + 4) )
      goto LABEL_35;
  }
LABEL_17:
  if ( dword_591090 < 0 )
    v8 = 4;
  v11 = GUIWindowCreate(0, 0, 640, 480, 10, v8, 0);
  dword_507BBC = v11;
  if ( v3[8] & 0x80 )
  {
    if ( !*((_DWORD *)v3 + 17) )
    {
      v12 = *((_DWORD *)v3 + 6);
      if ( v12 >= 10 )
      {
        if ( v12 <= 12 || v12 > 32 && (v12 <= 34 || v12 > 38 && (v12 <= 43 || v12 == 52)) )
        {
          GUIButtonCreate(v11, 480, 250, 140, *(_BYTE *)(pFontArrus + 5) - 3, 1, 0, 136, 9, 0, Class, 0);
          sub_41D08F(dword_507BBC, 4, 1, 0, 1);
        }
      }
    }
  }
  GUIButtonCreate(dword_507BBC, 61, 424, 31, 40, 2, 94, 110, 1, 49, Class, 0);
  GUIButtonCreate(dword_507BBC, 177, 424, 31, 40, 2, 94, 110, 2, 50, Class, 0);
  GUIButtonCreate(dword_507BBC, 292, 424, 31, 40, 2, 94, 110, 3, 51, Class, 0);
  result = GUIButtonCreate(dword_507BBC, 407, 424, 31, 40, 2, 94, 110, 4, 52, Class, 0);
  if ( v18 )
  {
    result = uMaybeSelectedCharacter;
    if ( uMaybeSelectedCharacter )
    {
      if ( !(v3[8] & 0x80) )
      {
        if ( (unsigned int)pParty_global->dword_00071C < 5 || (unsigned int)pParty_global->dword_00071C > 0x15 )
        {
          v16 = 0;
          v14 = 23;
        }
        else
        {
          v16 = 0;
          v14 = 22;
        }
        result = sub_4948B1(*(&ptr_A750C4 + uMaybeSelectedCharacter), v14, v16);
      }
    }
  }
  return result;
}

//----- (0044603D) --------------------------------------------------------
void __cdecl sub_44603D()
{
  dword_591090 = 0;
  GUIWindowDelete(dword_507BBC);
  dword_507BBC = 0;
  sub_426363(pClass24_global2);
  sub_426363(pClass24_global);
}

//----- (0044606A) --------------------------------------------------------
int __fastcall sub_44606A(int a1)
{
  int v1; // ebx@1
  int v2; // edi@1
  signed int v3; // esi@1
  __int16 v4; // ax@2
  int result; // eax@5
  int v6; // ecx@8
  int v7; // ebx@11
  int v8; // esi@16
  int v9; // eax@16
  int v10; // eax@19
  int v11; // ecx@19
  char Str1; // [sp+Ch] [bp-54h]@16
  int v13; // [sp+30h] [bp-30h]@11
  int Dst[6]; // [sp+34h] [bp-2Ch]@1
  int v15; // [sp+4Ch] [bp-14h]@1
  int v16; // [sp+50h] [bp-10h]@1
  int v17; // [sp+54h] [bp-Ch]@3
  int v18; // [sp+58h] [bp-8h]@1
  int v19; // [sp+5Ch] [bp-4h]@7

  v15 = a1;
  v1 = 52 * a1;
  v16 = word_59143A[26 * a1];
  v3 = 0;
  v18 = 52 * a1;
  memset(Dst, 0, 0x18u);
  v2 = *(__int16 *)((char *)&word_591464 + v1);
  dword_591424 = 0;
  dword_5C35D0 = v2;
  if ( v2 )
  {
    v4 = *(__int16 *)((char *)word_591468 + v1);
    if ( v4 > 0 )
    {
      v17 = v4 - 1;
      if ( !((unsigned __int8)(0x80u >> v17 % 8) & (unsigned __int8)byte_ACD71D[(v4 - 1) >> 3]) )
      {
        v2 = 0;
        dword_5C35D0 = 0;
      }
    }
  }
  dword_591080 = dword_4E5F78[4 * v16];
  result = dword_591080;
  if ( dword_591080 )
  {
    v3 = 1;
    Dst[0] = dword_591080;
    dword_591424 = 1;
  }
  v19 = 1;
  if (pNPCStats->dword_017FC4 > 1)
  {
    v6 = (int)&unk_72D6E0;
    v17 = (int)&unk_72D6E0;
    do
    {
      if ( *(_DWORD *)(v6 + 12) == v15 )
      {
        if ( !(*(_BYTE *)v6 & 0x80) )
        {
          v7 = v3++ - (result != 0);
          dword_5913D8[v7] = v6 - 8;
          v6 = v17;
          *(&v13 + v3) = *(_DWORD *)(v17 - 4);
          v1 = v18;
          if ( (*(_DWORD *)v6 & 3) != 2 )
            ++*(_DWORD *)v6;
        }
      }
      ++v19;
      v6 += 76;
      v17 = v6;
    }
    while ( v19 < pNPCStats->dword_017FC4);
    dword_591424 = v3;
  }
  v19 = 0;
  if ( v3 > 0 )
  {
    do
    {
      v8 = 4 * v19;
      sprintfex(&Str1, "npc%03u", Dst[v19]);
      v9 = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
      ++v19;
      *(int *)((char *)dword_59140C + v8) = 72 * v9 + 7145548;
      result = v19;
    }
    while ( v19 < dword_591424 );
    v2 = dword_5C35D0;
  }
  if ( v2 )
  {
    v10 = class17_LoadTexture(pClass17_Icons_LOD, (&off_4E6BB0)[4 * v2], 2);
    v11 = dword_591424++;
    dword_59140C[v11] = 72 * v10 + 7145548;
    result = *(__int16 *)((char *)&word_591466 + v1);
    dword_5C35D0 = *(__int16 *)((char *)&word_591466 + v1);
  }
  return result;
}

//----- (0044622E) --------------------------------------------------------
int __fastcall sub_44622E(int a1)
{
  int v1; // edi@1
  int v2; // edx@5
  int v3; // edi@5
  int v4; // esi@5
  int v5; // eax@5
  int v6; // esi@5
  signed int v7; // eax@10
  signed int v8; // ecx@10
  int v9; // esi@10
  int v10; // esi@16
  int v11; // ecx@17
  void *v12; // esi@27
  unsigned __int8 v13; // cf@27
  int v14; // eax@27
  signed int v16; // eax@34
  int v17; // edi@39
  int v18; // eax@39
  int v19; // ecx@43
  signed int v20; // edi@43
  const char *v22; // [sp-4h] [bp-40h]@35
  char Str1; // [sp+Ch] [bp-30h]@34
  unsigned int v24; // [sp+34h] [bp-8h]@5
  int v25; // [sp+38h] [bp-4h]@1
 int i;

  v1 = a1;
  v25 = a1;
  byte_5C3428 = 0;
  pStatusBarString[0] = 0;
  sub_44C175(Class, 2);
  if ( dword_50CBD0[0] )
    dword_50CBD0[0] = dword_50CBDC != 0;
  struct_576FE8.dword_000044 = 1;
  dword_59108C = 0;
  sub_459ED1(&dword_69AE00, 3);
  sub_459E3F();
  if ( v1 == 600 || v1 == 601 )
  {
    sub_4BF91E(0);
    return 0;
  }
  v3 = 52 * v1;
  v5 = *(__int16 *)((char *)&word_591460 + v3);
  v6 = *(__int16 *)((char *)&word_591462 + v3);
  dword_F8B1E8 = 0;
  v24 = v5;
  v4 = v6 - 1;
  dword_F8B1E4 = 0;
  dword_F8B1F4 = 0;
  memset(&unk_F8B1F0, 0, 4u);
  memset(&unk_F8B148, 0, 0x10u);
  CD3DRenderer_ClearZBuffer(pD3DRenderer, 0, 479);
  v2 = v24;
  if ( v4 <= (signed int)v24 )
  {
    if ( pParty_global->dword_00071C >= v24 )
      goto LABEL_16;
  }
  else
  {
    if ( pParty_global->dword_00071C < v24 )
    {
LABEL_10:
      v8 = 0;
      v7 = 0;
      v9 = v4 + 1;
      if ( (signed int)v24 > 12 )
      {
        v2 = v24 - 12;
        v8 = 1;
      }
      if ( v9 > 12 )
      {
        v9 -= 12;
        v7 = 1;
      }
      //sprintfex(&TmpBuf, (const char *)dword_5E47F8, v2, dword_5C35D8[v8], v9, dword_5C35D8[v7]);
      wsprintfA(&TmpBuf, pGlobalTXT_LocalizationStrings[414], v2, aAMPMNames[v8], v9, aAMPMNames[v7]);
      sub_44C175(&TmpBuf, 2);
      if ( uMaybeSelectedCharacter )
        sub_4948B1(*(&ptr_A750C4 + uMaybeSelectedCharacter), 3, 0);
      return 0;
    }
  }
  if ( pParty_global->dword_00071C > (unsigned int)v4 )
    goto LABEL_10;
LABEL_16:
  v10 = v25;
  if ( v25 >= 53 )
    goto LABEL_23;
  v11 = pParty_global->array_000334[2 * v25 + 1];
  if ( !(v11 | pParty_global->array_000334[2 * v25])
    || v11 < HIDWORD(pParty_global->qword_00002C)
    || v11 <= HIDWORD(pParty_global->qword_00002C) && (unsigned int)pParty_global->array_000334[2 * v25] <= (_DWORD)pParty_global->qword_00002C )
  {
    pParty_global->array_000334[2 * v25] = 0;
    pParty_global->array_000334[2 * v10 + 1] = 0;
LABEL_23:
    if ( !dword_597F18 )
      AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
    dword_591160 = *(__int16 *)((char *)word_59143A + v3);
    dword_F8B198 = (unsigned __int8)byte_4E5F7C[16 * dword_591160];
    if ( dword_F8B198 == 20 )
    {
      if ( dword_AE31E0 )
      {
        dword_591160 = word_593A36;
        v25 = 187;
        v13 = (_DWORD)pParty_global->qword_00002C >= 0xF89E0000u;
        LODWORD(pParty_global->qword_00002C) = pParty_global->qword_00002C + 123863040;
        //v12 = &unk_ACF4BC;
        v12 = &pParty_global->pPlayers[0].dword_001B38;
        v14 = (unsigned __int8)byte_4E5F7C[16 * word_593A36];
        HIDWORD(pParty_global->qword_00002C) += v13;
        dword_F8B198 = v14;
        do
        {
          *((_WORD *)v12 - 258) = 0;
          memset(v12, 0, 4u);
          v12 = (char *)v12 + 6972;
        }
        while ( (signed int)v12 < (signed int)&unk_AD61AC );
        ++pParty_global->dword_000744;
        dword_AE31E0 = 0;

        for (i = 0; i < 4; ++i)
          sub_44A5CB(&pParty_global->pPlayers[i], 12, 87);

        v10 = v25;
      }
    }
    ++pClass17_Icons_LOD->dword_011B9C;
    if ( !pClass17_Icons_LOD->dword_011B98 )
      pClass17_Icons_LOD->dword_011B98 = pClass17_Icons_LOD->uNumLoadedFiles;
    v16 = sub_44C28B();
    wsprintfA(&Str1, "evt%02d", v16);
    if ( pParty_global->uAlignment )
    {
      if ( pParty_global->uAlignment != 2 )
        goto LABEL_39;
      v22 = "-c";
    }
    else
    {
      v22 = "-b";
    }
    strcat(&Str1, v22);
LABEL_39:
    v18 = class17_LoadTexture(pClass17_Icons_LOD, &Str1, 2);
    dword_5913F0 = 0;
    dword_591430 = 72 * v18 + 7145548;
    dword_507B04 = dword_5079E4;
    sub_44606A(v10);
    v17 = 1;
    dword_507B04 = dword_5079E4;
    if ( dword_591424 == 1 )
      dword_5913F0 = 1;
    sub_4BF28F(pVideoPlayer, (unsigned int)*(&off_4E5F70 + 4 * dword_591160), 1);
    if ( v10 < 139 || v10 > 172 )
    {
      if ( v10 >= 54 && v10 <= 73 && !sub_4B68EA(v10 - 54) )
        goto LABEL_51;
      v19 = v10;
    }
    else
    {
      v20 = word_4F0704[2 * v10] - 1;
      v19 = v10;
      if ( !((unsigned __int8)(0x80u >> v20 % 8) & *((_BYTE *)*(&ptr_A750C4 + uMaybeSelectedCharacter) + (v20 >> 3) + 338)) )
      {
        sub_4B1E92(v10, 3);
        v17 = 1;
LABEL_51:
        dword_5C35D4 = v17;
        return v17;
      }
      v17 = 1;
    }
    sub_4B1E92(v19, v17);
    goto LABEL_51;
  }
  sub_44C175(pGlobalTXT_LocalizationStrings[191], 2);
  return 0;
}

//----- (004465DF) --------------------------------------------------------
signed int __thiscall sub_4465DF(void *this)
{
  int v1; // eax@1
  int v2; // edx@1
  int v3; // ecx@2
  int v4; // ecx@3
  char v6; // zf@9

  v1 = pParty_global->dword_000710 + 1;
  v2 = pParty_global->dword_000718 + 1;
  if ( this )
  {
    v3 = (int)((char *)this - 1);
    if ( v3 )
    {
      v4 = v3 - 1;
      if ( v4 )
      {
        if ( v4 != 1 )
          return 0;
        if ( v1 != 12 )
        {
          if ( v1 >= 1 && v1 <= 2 )
            return 1;
          v6 = v1 == 3;
LABEL_24:
          if ( !v6 || v2 >= 21 )
            return 0;
          return 1;
        }
      }
      else
      {
        if ( v1 != 9 )
        {
          if ( v1 >= 10 && v1 <= 11 )
            return 1;
          v6 = v1 == 12;
          goto LABEL_24;
        }
      }
    }
    else
    {
      if ( v1 != 6 )
      {
        if ( v1 >= 7 && v1 <= 8 )
          return 1;
        v6 = v1 == 9;
        goto LABEL_24;
      }
    }
  }
  else
  {
    if ( v1 != 3 )
    {
      if ( v1 >= 4 && v1 <= 5 )
        return 1;
      v6 = v1 == 6;
      goto LABEL_24;
    }
  }
  if ( v2 >= 21 )
    return 1;
  return 0;
}

//----- (0044665D) --------------------------------------------------------
int __fastcall sub_44665D(int a1, int a2, int a3)
{
  int v4; // eax@6
  int v5; // ecx@10
  int v6; // [sp+0h] [bp-4h]@1

  v6 = 0;
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      v4 = sub_408AE7((int)&v6, a2);
    }
    else
    {
      if ( a1 == 2 )
      {
        v4 = sub_408A7E((int)&v6, a2);
      }
      else
      {
        if ( a1 != 3 )
          return 0;
        v4 = sub_408B54((int)&v6, a2);
      }
    }
  }
  else
  {
    v4 = sub_408A27(&v6);
  }
  v5 = 0;
  if ( a3 )
    LOBYTE(v5) = v4 >= a3;
  else
    LOBYTE(v5) = v6 == v4;
  return v5;
}

//----- (004466C4) --------------------------------------------------------
bool __thiscall sub_4466C4(void *this)
{
  signed int v1; // ebp@1
  bool result; // eax@2
  signed int v3; // edx@3
  int v4; // esi@3
  int v5; // eax@4
  int v6; // eax@6
  int v7; // ebx@6
  void *v8; // edi@18
  int v9; // eax@19
  signed int v11; // [sp+Ch] [bp-Ch]@3
  signed int v12; // [sp+10h] [bp-8h]@3
  void *v13; // [sp+14h] [bp-4h]@1
 int i;

  v1 = 0;
  v13 = this;
  if ( !this )
    return 0;
  v4 = dword_597F18;
  pSomeOtherEVT = pGlobalEVT;
  uSomeOtherEVT_NumEvents = uGlobalEVT_NumEvents;
  memcpy(pSomeOtherEVT_Events, pGlobalEVT_Events, 4400 * sizeof(struct Event));
  v3 = 1;
  v12 = 1;
  v11 = 0;
  if ( uSomeOtherEVT_NumEvents <= 0 )
    goto LABEL_16;
  do
  {
    v5 = 12 * v1;
    if (pSomeOtherEVT_Events[v1].dword_000000 == v13 && *(int *)((char *)&pSomeOtherEVT_Events[0].dword_000004 + v5) == v4 )
    {
     v7 = *(int *)((char *)&pSomeOtherEVT_Events[0].dword_000008+ v5);
      v6 = v7 + pSomeOtherEVT;
      if ( *(_BYTE *)(v7 + pSomeOtherEVT + 4) == 1 )
        break;
      if ( *(_BYTE *)(v7 + pSomeOtherEVT + 4) == 44 )
      {
        v11 = v3;
        v8 = (void *)(*(_BYTE *)(v6 + 7)
                    + ((*(_BYTE *)(v6 + 8) + ((*(_BYTE *)(v6 + 9) + (*(_BYTE *)(v6 + 10) << 8)) << 8)) << 8));
        i = 0;
        while ( 1 )
        {
          LOBYTE(v9) = sub_449BB4(&pParty_global->pPlayers[i++], *(_BYTE *)(v7 + pSomeOtherEVT + 5) + (*(_BYTE *)(v7 + pSomeOtherEVT + 6) << 8), v8);
          if ( v9 )
            break;

          if (i >= 4)
            goto LABEL_13;
        }
      }
      else
      {
        if ( *(_BYTE *)(v7 + pSomeOtherEVT + 4) == 45 )
          break;
        if ( *(_BYTE *)(v7 + pSomeOtherEVT + 4) == 46 )
        {
          v11 = v3;
          v12 = *(_BYTE *)(v6 + 5);
          goto LABEL_13;
        }
        if ( *(_BYTE *)(v7 + pSomeOtherEVT + 4) != 52
          || !sub_44665D(
                *(_BYTE *)(v6 + 5),
                *(_BYTE *)(v6 + 6)
              + ((*(_BYTE *)(v6 + 7) + ((*(_BYTE *)(v6 + 8) + (*(_BYTE *)(v6 + 9) << 8)) << 8)) << 8),
                *(_BYTE *)(v6 + 10)) )
          goto LABEL_13;
      }
      v1 = -1;
      v4 = *(_BYTE *)(pSomeOtherEVT + v7 + 11) - 1;
LABEL_13:
      ++v4;
      v3 = 1;
    }
    ++v1;
  }
  while ( v1 < uSomeOtherEVT_NumEvents );
  if ( v11 )
    result = v12 != 0;
  else
LABEL_16:
    result = 2;
  return result;
}

//----- (0044684A) --------------------------------------------------------
void __fastcall sub_44684A_LooksLikeEventProcessor(int a1, int a2, int a3)
{
  int v4; // esi@7
  int v5; // eax@8
  int *v6; // ecx@8
  const char *v7; // ebp@8
  //int v9; // edx@10
  int v10; // edi@12
  int v11; // esi@12
  int v12; // eax@14
  char *v13; // eax@15
  int v14; // edi@21
  char *v15; // esi@21
  int v16; // edi@21
  int v17; // ebp@21
  int v18; // ecx@22
  int v19; // ebp@36
  int v20; // eax@40
  signed int v21; // ecx@40
  int v22; // eax@40
  int v23; // edx@40
  __int16 v24; // ax@45
  int v25; // eax@54
  int v26; // ecx@54
  int v27; // eax@54
  char v28; // zf@54
  int v29; // eax@55
  int v30; // eax@57
  int v31; // ecx@57
  int v32; // eax@58
  int v33; // edx@58
  char *v34; // ecx@58
  int v35; // esi@58
  int v36; // ecx@58
  int v37; // esi@59
  int v38; // esi@60
  int v39; // esi@61
  int v40; // esi@62
  int v41; // eax@78
  size_t v42; // edx@78
  int v43; // ecx@78
  int v44; // esi@79
  int v45; // eax@84
  size_t v46; // edx@84
  int v47; // ecx@84
  _UNKNOWN *v48; // esi@85
  int v49; // eax@91
  int v50; // eax@93
  int v51; // ecx@93
  int v52; // esi@94
  unsigned __int8 v53; // al@100
  int v55; // ecx@106
  int v56; // ecx@107
  unsigned __int8 v57; // al@111
  void *v59; // ecx@117
  int v60; // ecx@118
  void *v61; // ebp@124
  int v63; // eax@126
  int v64; // edx@133
  int v65; // eax@139
  signed int v66; // ebp@145
  signed int v67; // edi@146
  int v68; // edx@148
  void *v69; // ecx@148
  int v70; // esi@148
  signed int v71; // eax@151
  int v72; // esi@151
  void *v73; // ecx@158
  int v74; // eax@159
  int v75; // esi@159
  signed int v76; // eax@162
  int v77; // esi@162
  int v78; // edx@172
  int v80; // edx@186
  signed int v81; // ebp@186
  int v83; // edx@200
  signed int v84; // ebp@200
  int v86; // eax@212
  int v87; // ebp@220
  unsigned __int8 v88; // al@224
  signed int v89; // ebp@224
  int v91; // ecx@231
  int v92; // ecx@232
  int v93; // eax@243
  const char *v94; // ecx@247
  int v95; // eax@251
  char *v96; // eax@252
  __int64 v97; // ST4C_8@254
  int v98; // eax@262
  int v99; // ecx@262
  int v100; // ebp@262
  int v101; // edx@262
  int v102; // edx@265
  int v103; // edx@267
  const char *v104; // esi@267
  int v105; // esi@281
  int v106; // edi@281
  int v107; // edi@284
  int v108; // eax@288
  int v109; // edx@294
  int v110; // [sp-20h] [bp-4C8h]@278
  signed int v111; // [sp-1Ch] [bp-4C4h]@278
  int v112; // [sp-18h] [bp-4C0h]@278
  signed int v113; // [sp-14h] [bp-4BCh]@278
  int v114; // [sp-10h] [bp-4B8h]@278
  int v115; // [sp-Ch] [bp-4B4h]@278
  int v117; // [sp-8h] [bp-4B0h]@106
  int v118; // [sp-8h] [bp-4B0h]@117
  signed int v119; // [sp-8h] [bp-4B0h]@231
  int v120; // [sp-8h] [bp-4B0h]@278
  int v121; // [sp-4h] [bp-4ACh]@106
  int v122; // [sp-4h] [bp-4ACh]@117
  int v123; // [sp-4h] [bp-4ACh]@231
  int v124; // [sp-4h] [bp-4ACh]@278
  int v125; // [sp-4h] [bp-4ACh]@294
  int v126; // [sp+10h] [bp-498h]@4
  int *v127; // [sp+14h] [bp-494h]@291
  signed int v128; // [sp+18h] [bp-490h]@7
  signed int v129; // [sp+1Ch] [bp-48Ch]@155
  int v130; // [sp+1Ch] [bp-48Ch]@262
  int v131; // [sp+20h] [bp-488h]@4
  int v132; // [sp+24h] [bp-484h]@21
  int v133; // [sp+24h] [bp-484h]@262
  signed int v134; // [sp+28h] [bp-480h]@40
  int v135; // [sp+2Ch] [bp-47Ch]@1
  int v136; // [sp+30h] [bp-478h]@262
  signed int v137; // [sp+34h] [bp-474h]@1
  int v138; // [sp+38h] [bp-470h]@262
  int v139; // [sp+3Ch] [bp-46Ch]@262
  int v140; // [sp+40h] [bp-468h]@40
  int v141; // [sp+44h] [bp-464h]@40
  int v142; // [sp+48h] [bp-460h]@40
  int v143; // [sp+4Ch] [bp-45Ch]@40
  int v144; // [sp+50h] [bp-458h]@281
  char v145; // [sp+73h] [bp-435h]@15
  char Str; // [sp+74h] [bp-434h]@15
  char v147; // [sp+ECh] [bp-3BCh]@21
  char Dst; // [sp+164h] [bp-344h]@53
  __int16 v149; // [sp+184h] [bp-324h]@53
 int i;

  v135 = a1;
  v137 = 0;
  dword_5B5920 = a2;
  dword_5B65C4 = 0;
  if ( !a1 )
  {
    if ( !dword_5C35B8 )
      sub_44C175(pGlobalTXT_LocalizationStrings[521], 2);
    return;
  }
  v131 = 2 * (uMaybeSelectedCharacter == 0) + 4;
  v126 = dword_597F18;

 if (dword_5C3420)
 {
  uSomeEVT_NumEvents = uGlobalEVT_NumEvents;
  pSomeEVT = pGlobalEVT;
  memcpy(pSomeEVT_Events, pGlobalEVT_Events, 4400 * sizeof(struct Event));
 }
 else
 {
  uSomeEVT_NumEvents = uLevelEVT_NumEvents;
  pSomeEVT = pLevelEVT;
  memcpy(pSomeEVT_Events, pLevelEVT_Events, 4400 * sizeof(struct Event));
 }

  v4 = 0;
  v128 = 0;
  if ( uSomeEVT_NumEvents > 0 )
  {
    v5 = pSomeEVT;

    //v6 = v8;
    runtime_warning(v6 and v8 here access random location in stack according to disasm, so are not decompiled properly);

    v7 = Class;
    while ( 1 )
    {
      if ( dword_5B65C4 )
        goto LABEL_301;

      if ( pSomeEVT_Events[v4].dword_000000 == v135 && &pSomeEVT_Events[v4].dword_000004 == v126 )
      {
       v10 = pSomeEVT_Events[v4].dword_000008;
        v11 = v5 + v10;
        switch ( *(_BYTE *)(v5 + v10 + 4) )
        {
          case 0x38:
            if ( !sub_4465DF((void *)*(_BYTE *)(v11 + 5)) )
              goto LABEL_291;
            v12 = *(_BYTE *)(v11 + 6);
            goto LABEL_130;
          case 0xC:
            strcpy(&Str, (const char *)(v11 + 7));
            v13 = &v145 + strlen(&Str);
            if ( *v13 == 32 )
              *v13 = 0;
            if ( pVideoPlayer->dword_000054 )
              CVideoPlayer_UnloadAll(pVideoPlayer);
            pVideoPlayer->dword_00006C = 0;
            pVideoPlayer->dword_000040 = 0;
            if (dword_720010)
              Mouse_suspend(dword_720010);
            v132 = dword_4E28F8;
            v16 = pSomeEVT + v10;
            v17 = *(_BYTE *)(v16 + 5);
            v14 = *(_BYTE *)(v16 + 6);
            strcpy(&v147, &Str);
            v15 = sub_452C30(&v147);
            MoviePlayerLoop(v15, 0, v17, 1);
            if ( !_strcmpi(v15, "arbiter good") )
            {
              pParty_global->uAlignment = 0;
              v18 = 0;
LABEL_23:
              LoadInterfaceTextures(v18, 1);
              goto LABEL_28;
            }
            if ( !_strcmpi(v15, "arbiter evil") )
            {
              v18 = 2;
              pParty_global->uAlignment = 2;
              goto LABEL_23;
            }
            if ( !_strcmpi(v15, "pcout01") )
            {
              sub_4938D1(0x2760u);
              sub_490D02(pParty_global);
              byte_ACD71C = 0;
            }
LABEL_28:
            if ( !v14 || v132 == 3 )
            {
              dword_4E28F8 = v132;
              if ( v132 == 3 )
                pLoadingUI->uProgressBarType = 1;
              if ( v132 == 13 )
                sub_4BF28F(pVideoPlayer, (unsigned int)*(&off_4E5F70 + 4 * dword_591160), 1);
            }
            if (dword_720010)
              sub_46B105(dword_720010);
            goto LABEL_291;
          case 0x2B:
            v19 = *(_BYTE *)(v11 + 7)
                + ((*(_BYTE *)(v11 + 8) + ((*(_BYTE *)(v11 + 9) + (*(_BYTE *)(v11 + 10) << 8)) << 8)) << 8);
            if ( v131 < 0 )
              goto LABEL_47;
            if ( v131 <= 3 )
            {
              v24 = pParty_global->pPlayers[v131].ActiveSkills[*(_BYTE *)(v11 + 5)];
            }
            else
            {
              if ( v131 == 4 )
              {
                v24 = *((_WORD *)*(&ptr_A750C4 + uMaybeSelectedCharacter) + *(_BYTE *)(v11 + 5) + 132);
              }
              else
              {
                if ( v131 == 5 )
                {
                  v21 = 0;
                  v22 = 3486 * v134 + *(_BYTE *)(v11 + 5);
                  v140 = 1;
                  LOWORD(v22) = pParty_global->pPlayers[v134].ActiveSkills[*(_BYTE *)(v11 + 5)];
                  v141 = v22 & 0x40;
                  v142 = v22 & 0x80;
                  v23 = v22 & 0x100;
                  v20 = v22 & 0x3F;
                  v143 = v23;
                  while ( v20 < v19 || !*(&v140 + *(_BYTE *)(v11 + 6)) )
                  {
                    ++v21;
                    if ( v21 >= 4 )
                      goto LABEL_291;
                  }
LABEL_50:
                  v12 = *(_BYTE *)(v11 + 11);
                  goto LABEL_130;
                }
LABEL_47:
                v11 = v5 + v10;
                v24 = pParty_global->pPlayers[rand() % 4].ActiveSkills[*(_BYTE *)(v5 + v10 + 5)];
              }
            }
            v140 = 1;
            v141 = v24 & 0x40;
            v142 = v24 & 0x80;
            v143 = v24 & 0x100;
            if ( (v24 & 0x3F) >= v19 && *(&v140 + *(_BYTE *)(v11 + 6)) )
              goto LABEL_50;
            goto LABEL_291;
          case 0x16:
            if ( a3 )
            {
              sub_41F4C1(&Dst);
              memset(&Dst, 0, 0x344u);
              dword_5B65D0 = *(_BYTE *)(pSomeEVT + v10 + 5)
                           + ((*(_BYTE *)(pSomeEVT + v10 + 6)
                             + ((*(_BYTE *)(pSomeEVT + v10 + 7) + (*(_BYTE *)(pSomeEVT + v10 + 8) << 8)) << 8)) << 8);
              v149 = dword_5B65D0;
              sub_445D4A((int)&Dst, 0);
            }
            else
            {
              dword_5C35C4 = *(_BYTE *)(v11 + 5)
                           + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8);
            }
            goto LABEL_291;
          case 0x2A:
            v26 = *(_BYTE *)(v11 + 5);
            v27 = (*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8;
            v28 = v26 + v27 == 0;
            v25 = v26 + v27;
            if ( v28 )
            {
              v29 = dword_5C3420;
              global_5E4C90.byte_000000[*(_WORD *)(dword_5C3420 + 28)] = 0;
              *(_BYTE *)(v29 + 2) |= 0x20u;
            }
            else
            {
              global_5E4C90.byte_000000[*(_WORD *)(dword_5C3420 + 28)] = v25 - 124;
            }
            goto LABEL_291;
          case 0x32:
            v30 = 76
                * (*(_BYTE *)(v11 + 5)
                 + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8));
            v31 = *(_BYTE *)(v11 + 9)
                + ((*(_BYTE *)(v11 + 10) + ((*(_BYTE *)(v11 + 11) + (*(_BYTE *)(v11 + 12) << 8)) << 8)) << 8);
            *(int *)((char *)dword_72D694 + v30) &= 0xFFFFFFFCu;
            *(int *)((char *)&dword_72D6A8 + v30) = v31;
            goto LABEL_291;
          case 0x27:
            v33 = *(_BYTE *)(v11 + 5)
                + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8);
            v32 = *(_BYTE *)(v11 + 10)
                + ((*(_BYTE *)(v11 + 11) + ((*(_BYTE *)(v11 + 12) + (*(_BYTE *)(v11 + 13) << 8)) << 8)) << 8);
            v36 = 76
                * (*(_BYTE *)(v11 + 5)
                 + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8));
            v35 = *(_BYTE *)(v11 + 9);
            v34 = &pNPCStats->pNPCData2[v36 / 76];
            if ( v35 )
            {
              v37 = v35 - 1;
              if ( v37 )
              {
                v38 = v37 - 1;
                if ( v38 )
                {
                  v39 = v38 - 1;
                  if ( v39 )
                  {
                    v40 = v39 - 1;
                    if ( v40 )
                    {
                      if ( v40 == 1 )
                        *((_DWORD *)v34 + 15) = v32;
                    }
                    else
                    {
                      *((_DWORD *)v34 + 14) = v32;
                    }
                  }
                  else
                  {
                    *((_DWORD *)v34 + 13) = v32;
                  }
                }
                else
                {
                  *((_DWORD *)v34 + 12) = v32;
                }
              }
              else
              {
                *((_DWORD *)v34 + 11) = v32;
              }
            }
            else
            {
              *((_DWORD *)v34 + 10) = v32;
            }
            if ( v33 == 8 )
            {
              if ( v32 == 78 )
              {
                sub_4BD8B5();
                GUIWindowDelete(dword_507BC0);
                pParty_global->dword_007778 &= 0xFFFFFFFDu;
                if ( sub_44622E(170) )
                {
                  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
                  dword_507BC0 = GUIWindowCreate(0, 0, 640, 480, 25, 170, 0);
                  GUIButtonCreate(dword_507BC0, 61, 424, 31, 0, 2, 94, 110, 1, 49, v7, 0);
                  GUIButtonCreate(dword_507BC0, 177, 424, 31, 0, 2, 94, 110, 2, 50, v7, 0);
                  GUIButtonCreate(dword_507BC0, 292, 424, 31, 0, 2, 94, 110, 3, 51, v7, 0);
                  GUIButtonCreate(dword_507BC0, 407, 424, 31, 0, 2, 94, 110, 4, 52, v7, 0);
                  GUIButtonCreate(dword_507BC0, 0, 0, 0, 0, 1, 0, 176, 0, 9, v7, 0);
                  dword_F8B1E8 = (char *)dword_72193C;
                }
              }
            }
            goto LABEL_291;
          case 0x31:
            sub_448518(
              *(_BYTE *)(v11 + 5)
            + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 9)
            + ((*(_BYTE *)(v11 + 10) + ((*(_BYTE *)(v11 + 11) + (*(_BYTE *)(v11 + 12) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 13));
            goto LABEL_291;
          case 0x3C:
            sub_4485A7(
              *(_BYTE *)(v11 + 5)
            + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 9)
            + ((*(_BYTE *)(v11 + 10) + ((*(_BYTE *)(v11 + 11) + (*(_BYTE *)(v11 + 12) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 13));
            goto LABEL_291;
          case 0x2F:
            pNPCStats->word_017F5A[*(_BYTE *)(v11 + 5)
                      + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8)] = *(_BYTE *)(v11 + 9) + (*(_BYTE *)(v11 + 10) << 8);
            goto LABEL_291;
          case 0x30:
            *(int *)((char *)&dword_5FF41C[285212672 * *(_BYTE *)(v11 + 8)]
                   + 836 * (*(_BYTE *)(v11 + 5) + ((*(_BYTE *)(v11 + 6) + (*(_BYTE *)(v11 + 7) << 8)) << 8))) = *(_BYTE *)(v11 + 9) + ((*(_BYTE *)(v11 + 10) + ((*(_BYTE *)(v11 + 11) + (*(_BYTE *)(v11 + 12) << 8)) << 8)) << 8);
            goto LABEL_291;
          case 0x36:
            v41 = *(_BYTE *)(v11 + 5)
                + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8);
            v43 = *(_BYTE *)(v11 + 9)
                + ((*(_BYTE *)(v11 + 10) + ((*(_BYTE *)(v11 + 11) + (*(_BYTE *)(v11 + 12) << 8)) << 8)) << 8);
            v42 = uNumActors;
            if ( (signed int)uNumActors > 0 )
            {
              v44 = (int)dword_5FF41C;
              do
              {
                if ( *(_DWORD *)v44 == v41 )
                  *(_DWORD *)v44 = v43;
                v44 += 836;
                --v42;
              }
              while ( v42 );
            }
            goto LABEL_291;
          case 0x37:
            v45 = *(_BYTE *)(v11 + 5)
                + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8);
            v47 = *(_BYTE *)(v11 + 9)
                + ((*(_BYTE *)(v11 + 10) + ((*(_BYTE *)(v11 + 11) + (*(_BYTE *)(v11 + 12) << 8)) << 8)) << 8);
            v46 = uNumActors;
            if ( (signed int)uNumActors > 0 )
            {
              v48 = &unk_5FF420;
              do
              {
                if ( *((_DWORD *)v48 - 1) == v45 )
                  *(_DWORD *)v48 = v47;
                v48 = (char *)v48 + 836;
                --v46;
              }
              while ( v46 );
            }
            goto LABEL_291;
          case 0x28:
            dword_72D6A0[19
                       * (*(_BYTE *)(v11 + 5)
                        + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8))] = *(_BYTE *)(v11 + 9) + ((*(_BYTE *)(v11 + 10) + ((*(_BYTE *)(v11 + 11) + (*(_BYTE *)(v11 + 12) << 8)) << 8)) << 8);
            if ( dword_507BC0 )
            {
              v49 = *(_DWORD *)(dword_507BC0 + 28);
              if ( v49 == 165 )
              {
                sub_4BD8B5();
                CVideoPlayer_UnloadAll(pVideoPlayer);
                GUIWindowDelete(dword_507BC0);
                pParty_global->dword_007778 &= 0xFFFFFFFDu;
                dword_5C3420 = 1;
                if ( sub_44622E(165) )
                {
                  AudioPlayer_sub_4AA306(pAudioPlayer, 0, 0, 0, -1, 0, 0, 0, 0);
                  v50 = GUIWindowCreate(0, 0, 640, 480, 25, 165, 0);
                  dword_507BC0 = v50;
                  v51 = *(_DWORD *)(v50 + 76);
                  if ( v51 )
                  {
                    do
                    {
                      v52 = *(_DWORD *)(v51 + 52);
                      class23_DeleteBuffer(class23_instance, v51);
                      v51 = v52;
                    }
                    while ( v52 );
                    v50 = dword_507BC0;
                  }
                  *(_DWORD *)(v50 + 76) = 0;
                  *(_DWORD *)(dword_507BC0 + 80) = 0;
                  *(_DWORD *)(dword_507BC0 + 32) = 0;
                }
              }
              else
              {
                if ( v49 == 553 )
                  pVideoPlayer->dword_000064 = 0;
              }
            }
            goto LABEL_291;
          case 0x24:
            v128 = -1;
            v126 = *(_BYTE *)(v11 + 5) - 1;
            goto LABEL_291;
          case 8:
            v53 = *(_BYTE *)(v11 + 5);
            if ( v53 <= 3u )
            {
              v121 = 0;
              v117 = *(_BYTE *)(v11 + 6);
              v56 = v53;
              goto LABEL_108;
            }
            if ( v53 == 4 )
            {
              v121 = 0;
              v117 = *(_BYTE *)(v11 + 6);
              v55 = (int)*(&ptr_A750C4 + uMaybeSelectedCharacter);
              goto LABEL_109;
            }
            if ( v53 != 5 )
            {
              v121 = 0;
              v117 = *(_BYTE *)(v11 + 6);
              v56 = rand() % 4;
LABEL_108:
              v55 = &pParty_global->pPlayers[1743 * v56];
LABEL_109:
              sub_494A25(v55, v117, v121);
              goto LABEL_291;
            }

            for (i = 0; i < 4; ++i)
              sub_494A25(&pParty_global->pPlayers[i], *(_BYTE *)(v10 + pSomeEVT + 6), 0);

LABEL_291:
            ++v126;
            v4 = v128;
            v5 = pSomeEVT;
            v6 = v127;
            v7 = Class;
            break;
          case 0x3B:
            v57 = *(_BYTE *)(v11 + 5);
            if ( v57 <= 3u )
            {
              v122 = 0;
              v118 = *(_BYTE *)(v11 + 6);
              v60 = v57;
              goto LABEL_119;
            }
            if ( v57 == 4 )
            {
              v122 = 0;
              v118 = *(_BYTE *)(v11 + 6);
              v59 = *(&ptr_A750C4 + uMaybeSelectedCharacter);
              goto LABEL_120;
            }
            if ( v57 != 5 )
            {
              v122 = 0;
              v118 = *(_BYTE *)(v11 + 6);
              v60 = rand() % 4;
LABEL_119:
              v59 = &pParty_global->pPlayers[1743 * v60];
LABEL_120:
              sub_4948B1(v59, v118, v122);
              goto LABEL_291;
            }

            for (i = 0; i < 4; ++i)
              sub_4948B1(&pParty_global->pPlayers[i], *(_BYTE *)(v10 + pSomeEVT + 6), 0);

            goto LABEL_291;
          case 0x23:
            v131 = *(_BYTE *)(v11 + 5);
            goto LABEL_291;
          case 0x22:
            sub_42F7EB(
              *(_BYTE *)(v11 + 5)
            + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 9)
            + ((*(_BYTE *)(v11 + 10) + ((*(_BYTE *)(v11 + 11) + (*(_BYTE *)(v11 + 12) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 13)
            + ((*(_BYTE *)(v11 + 14) + ((*(_BYTE *)(v11 + 15) + (*(_BYTE *)(v11 + 16) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 17)
            + ((*(_BYTE *)(v11 + 18) + ((*(_BYTE *)(v11 + 19) + (*(_BYTE *)(v11 + 20) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 21)
            + ((*(_BYTE *)(v11 + 22) + ((*(_BYTE *)(v11 + 23) + (*(_BYTE *)(v11 + 24) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 25),
              *(_BYTE *)(v11 + 26),
              0,
              0);
            goto LABEL_291;
          case 0xE:
            v61 = (void *)(*(_BYTE *)(v11 + 7)
                         + ((*(_BYTE *)(v11 + 8) + ((*(_BYTE *)(v11 + 9) + (*(_BYTE *)(v11 + 10) << 8)) << 8)) << 8));
            if ( v131 == 5 )
            {
              v134 = 0;
              i = 0;
              while ( 1 )
              {
                LOBYTE(v63) = sub_449BB4(&pParty_global->pPlayers[i++],
                                *(_BYTE *)(v10 + pSomeEVT + 5) + (*(_BYTE *)(v10 + pSomeEVT + 6) << 8),
                                v61);
                if ( v63 )
                  break;
                ++v134;
                if (i >= 4)
                  goto LABEL_291;
              }
LABEL_129:
              v12 = *(_BYTE *)(pSomeEVT + v10 + 11);
              goto LABEL_130;
            }
            if ( v131 < 0 )
              goto LABEL_139;
            v64 = v131;
            if ( v131 <= 3 )
              goto LABEL_137;
            if ( v131 == 4 )
            {
              if ( uMaybeSelectedCharacter )
              {
                v6 = (int *)*(&ptr_A750C4 + uMaybeSelectedCharacter);
                goto LABEL_138;
              }
            }
            else
            {
              if ( v131 != 6 )
                goto LABEL_139;
            }
            v64 = rand() % 4;
            v5 = pSomeEVT;
LABEL_137:
            v6 = &pParty_global->pPlayers[1743 * v64];
LABEL_138:
            v127 = v6;
LABEL_139:
            LOBYTE(v65) = sub_449BB4((int)v6, *(_BYTE *)(v10 + v5 + 5) + (*(_BYTE *)(v10 + v5 + 6) << 8), v61);
LABEL_140:
            if ( v65 )
              goto LABEL_129;
            goto LABEL_291;
          case 0x33:
            v65 = sub_44665D(
                    *(_BYTE *)(v11 + 5),
                    *(_BYTE *)(v11 + 6)
                  + ((*(_BYTE *)(v11 + 7) + ((*(_BYTE *)(v11 + 8) + (*(_BYTE *)(v11 + 9) << 8)) << 8)) << 8),
                    *(_BYTE *)(v11 + 10));
            goto LABEL_140;
          case 0x11:
            v66 = *(_BYTE *)(v11 + 7)
                + ((*(_BYTE *)(v11 + 8) + ((*(_BYTE *)(v11 + 9) + (*(_BYTE *)(v11 + 10) << 8)) << 8)) << 8);
            if ( *(_BYTE *)(v11 + 5) + (*(_BYTE *)(v11 + 6) << 8) == 17 )
            {
              v67 = 0;
              if ( dword_AD470C == v66 )
              {
                class03_sub_4698A6(pGame->pClass03);
                goto LABEL_291;
              }
              v68 = 0;
              v69 = *(&ptr_A750C4 + uMaybeSelectedCharacter);
              v70 = (int)((char *)v69 + 5500);
              do
              {
                if ( *((_DWORD *)v69 + 9 * *(_DWORD *)v70 + 124) == v66 )
                {
                  sub_492A36(v69, v68);
                  goto LABEL_291;
                }
                ++v68;
                v70 += 4;
              }
              while ( v68 < 126 );
              v71 = 0;
              v72 = (int)((char *)v69 + 6472);
              do
              {
                if ( *(_DWORD *)v72 && *((_DWORD *)v69 + 9 * *(_DWORD *)v72 + 124) == v66 )
                {
                  *((_DWORD *)v69 + v71 + 1618) = 0;
                  goto LABEL_291;
                }
                ++v71;
                v72 += 4;
              }
              while ( v71 < 16 );
              v129 = (signed int)pPlayers;
              while ( 1 )
              {
                v73 = *(void **)v129;
                if ( !v67 )
                {
                  v74 = 0;
                  v75 = (int)((char *)v73 + 5500);
                  do
                  {
                    if ( *((_DWORD *)v73 + 9 * *(_DWORD *)v75 + 124) == v66 )
                    {
                      sub_492A36(v73, v74);
                      goto LABEL_169;
                    }
                    ++v74;
                    v75 += 4;
                  }
                  while ( v74 < 126 );
                  v76 = 0;
                  v77 = (int)((char *)v73 + 6472);
                  while ( !*(_DWORD *)v77 || *((_DWORD *)v73 + 9 * *(_DWORD *)v77 + 124) != v66 )
                  {
                    ++v76;
                    v77 += 4;
                    if ( v76 >= 16 )
                      goto LABEL_170;
                  }
                  *((_DWORD *)v73 + v76 + 1618) = 0;
LABEL_169:
                  v67 = 1;
                }
LABEL_170:
                v129 += 4;
                if ( v129 > (signed int)&dword_A750D4 )
                  goto LABEL_291;
              }
            }
            v78 = v131;
            if ( v131 != 5 )
            {
              if ( v131 < 0 )
                goto LABEL_183;
              if ( v131 > 3 )
              {
                if ( v131 != 4 )
                {
                  if ( v131 == 6 )
                    goto LABEL_180;
LABEL_183:
                  sub_44B9C4((int)v6, *(_BYTE *)(v5 + v10 + 5) + (*(_BYTE *)(v5 + v10 + 6) << 8), v66);
                  goto LABEL_291;
                }
                if ( uMaybeSelectedCharacter )
                {
                  v6 = (int *)*(&ptr_A750C4 + uMaybeSelectedCharacter);
                  goto LABEL_182;
                }
LABEL_180:
                v78 = rand() % 4;
                v5 = pSomeEVT;
              }
              v6 = &pParty_global->pPlayers[1743 * v78];
LABEL_182:
              v127 = v6;
              goto LABEL_183;
            }

            v134 = 4;
            for (i = 0; i < 4; ++i)
              sub_44B9C4(&pParty_global->pPlayers[i], *(_BYTE *)(v10 + pSomeEVT + 5) + (*(_BYTE *)(v10 + pSomeEVT + 6) << 8), v66);

            goto LABEL_291;
          case 0x12:
            v81 = *(_BYTE *)(v11 + 7)
                + ((*(_BYTE *)(v11 + 8) + ((*(_BYTE *)(v11 + 9) + (*(_BYTE *)(v11 + 10) << 8)) << 8)) << 8);
            v80 = v131;
            if ( v131 != 5 )
            {
              if ( v131 < 0 )
                goto LABEL_197;
              if ( v131 > 3 )
              {
                if ( v131 != 4 )
                {
                  if ( v131 == 6 )
                    goto LABEL_194;
LABEL_197:
                  sub_44A5CB((char *)v6, *(_BYTE *)(v5 + v10 + 5) + (*(_BYTE *)(v5 + v10 + 6) << 8), v81);
                  goto LABEL_291;
                }
                if ( uMaybeSelectedCharacter )
                {
                  v6 = (int *)*(&ptr_A750C4 + uMaybeSelectedCharacter);
                  goto LABEL_196;
                }
LABEL_194:
                v80 = rand() % 4;
                v5 = pSomeEVT;
              }
              v6 = &pParty_global->pPlayers[1743 * v80];
LABEL_196:
              v127 = v6;
              goto LABEL_197;
            }

            v134 = 4;
            for (i = 0; i < 4; ++i)
              sub_44A5CB(&pParty_global->pPlayers[i], *(_BYTE *)(v10 + pSomeEVT + 5) + (*(_BYTE *)(v10 + pSomeEVT + 6) << 8), v81);


            goto LABEL_291;
          case 0x10:
            v84 = *(_BYTE *)(v11 + 7)
                + ((*(_BYTE *)(v11 + 8) + ((*(_BYTE *)(v11 + 9) + (*(_BYTE *)(v11 + 10) << 8)) << 8)) << 8);
            v83 = v131;
            if ( v131 != 5 )
            {
              if ( v131 < 0 )
                goto LABEL_211;
              if ( v131 > 3 )
              {
                if ( v131 != 4 )
                {
                  if ( v131 == 6 )
                    goto LABEL_208;
LABEL_211:
                  sub_44AFFB((char *)v6, *(_BYTE *)(v10 + v5 + 5) + (*(_BYTE *)(v10 + v5 + 6) << 8), v84);
                  goto LABEL_212;
                }
                if ( uMaybeSelectedCharacter )
                {
                  v6 = (int *)*(&ptr_A750C4 + uMaybeSelectedCharacter);
                  goto LABEL_210;
                }
LABEL_208:
                v83 = rand() % 4;
                v5 = pSomeEVT;
              }
              v6 = &pParty_global->pPlayers[1743 * v83];
LABEL_210:
              v127 = v6;
              goto LABEL_211;
            }

            v134 = 4;
            for (i = 0; i < 4; ++i)
              sub_44AFFB(&pParty_global->pPlayers[i], *(_BYTE *)(v10 + pSomeEVT + 5) + (*(_BYTE *)(v10 + pSomeEVT + 6) << 8), v84);

LABEL_212:
            v86 = *(_BYTE *)(pSomeEVT + v10 + 5) + (*(_BYTE *)(pSomeEVT + v10 + 6) << 8);
            if ( v86 == 21 || v86 == 22 || v86 == 23 || v86 == 24 )
              struct_576FE8.dword_000044 = 1;
            goto LABEL_291;
          case 0x1A:
            if ( !dword_597F18 )
            {
              strcpy(
                &byte_5C3428,
                &pLevelStr[uLevelStrOffsets[*(_BYTE *)(v5 + v10 + 5)
                                        + ((*(_BYTE *)(v5 + v10 + 6)
                                          + ((*(_BYTE *)(v5 + v10 + 7) + (*(_BYTE *)(v5 + v10 + 8) << 8)) << 8)) << 8)]]);
              v109 = v126;
              v125 = 26;
LABEL_295:
              sub_4451A8(v135, v109, v125);
LABEL_301:
              if ( v137 == 1 )
LABEL_302:
                sub_443F95();
              return;
            }
            v87 = *(_BYTE *)(v11 + 13)
                + ((*(_BYTE *)(v11 + 14) + ((*(_BYTE *)(v11 + 15) + (*(_BYTE *)(v11 + 16) << 8)) << 8)) << 8);
            if ( !_strcmpi(
                    &byte_5C3428,
                    &pLevelStr[uLevelStrOffsets[*(_BYTE *)(v11 + 9)
                                            + ((*(_BYTE *)(v11 + 10)
                                              + ((*(_BYTE *)(v11 + 11) + (*(_BYTE *)(v11 + 12) << 8)) << 8)) << 8)]])
              || !_strcmpi(&byte_5C3428, &pLevelStr[uLevelStrOffsets[v87]]) )
            {
              v12 = *(_BYTE *)(pSomeEVT + v10 + 17);
LABEL_130:
              v128 = -1;
LABEL_131:
              v126 = v12 - 1;
            }
            goto LABEL_291;
          case 0x19:
            v128 = -1;
            v12 = *(_BYTE *)(rand()
                           % ((*(_BYTE *)(v11 + 5) != 0)
                            + (*(_BYTE *)(v11 + 6) != 0)
                            + (*(_BYTE *)(v11 + 7) != 0)
                            + (*(_BYTE *)(v11 + 8) != 0)
                            + (*(_BYTE *)(v11 + 9) != 0)
                            + (*(_BYTE *)(v11 + 10) != 0))
                           + pSomeEVT
                           + v10
                           + 5);
            goto LABEL_131;
          case 9:
            v89 = *(_BYTE *)(v11 + 7)
                + ((*(_BYTE *)(v11 + 8) + ((*(_BYTE *)(v11 + 9) + (*(_BYTE *)(v11 + 10) << 8)) << 8)) << 8);
            v88 = *(_BYTE *)(v11 + 5);
            if ( v88 <= 3u )
            {
              v123 = *(_BYTE *)(v11 + 6);
              v119 = *(_BYTE *)(v11 + 7)
                   + ((*(_BYTE *)(v11 + 8) + ((*(_BYTE *)(v11 + 9) + (*(_BYTE *)(v11 + 10) << 8)) << 8)) << 8);
              v92 = v88;
              goto LABEL_233;
            }
            if ( v88 == 4 )
            {
              if ( !uMaybeSelectedCharacter )
                goto LABEL_291;
              v123 = *(_BYTE *)(v11 + 6);
              v91 = (int)*(&ptr_A750C4 + uMaybeSelectedCharacter);
              v119 = *(_BYTE *)(v11 + 7)
                   + ((*(_BYTE *)(v11 + 8) + ((*(_BYTE *)(v11 + 9) + (*(_BYTE *)(v11 + 10) << 8)) << 8)) << 8);
              goto LABEL_234;
            }
            if ( v88 != 5 )
            {
              v123 = *(_BYTE *)(v11 + 6);
              v119 = *(_BYTE *)(v11 + 7)
                   + ((*(_BYTE *)(v11 + 8) + ((*(_BYTE *)(v11 + 9) + (*(_BYTE *)(v11 + 10) << 8)) << 8)) << 8);
              v92 = rand() % 4;
LABEL_233:
              v91 = &pParty_global->pPlayers[1743 * v92];
LABEL_234:
              sub_48DC1E(v91, v119, v123);
              goto LABEL_291;
            }

            for (i = 0; i < 4; ++i)
              sub_48DC1E(&pParty_global->pPlayers[i], v89, *(_BYTE *)(v10 + pSomeEVT + 6));

            goto LABEL_291;
          case 0x20:
            sub_4488F7(
              *(_BYTE *)(v11 + 5)
            + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 9));
            goto LABEL_291;
          case 0x17:
            sub_44892E(
              *(_BYTE *)(v11 + 5)
            + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 9)
            + ((*(_BYTE *)(v11 + 10) + ((*(_BYTE *)(v11 + 11) + (*(_BYTE *)(v11 + 12) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 13));
            goto LABEL_291;
          case 0x3A:
            sub_448A17(
              *(_BYTE *)(v11 + 5)
            + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 9)
            + ((*(_BYTE *)(v11 + 10) + ((*(_BYTE *)(v11 + 11) + (*(_BYTE *)(v11 + 12) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 13));
            goto LABEL_291;
          case 0x18:
            sub_448A40(
              *(_BYTE *)(v11 + 5)
            + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 9)
            + ((*(_BYTE *)(v11 + 10) + ((*(_BYTE *)(v11 + 11) + (*(_BYTE *)(v11 + 12) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 13));
            goto LABEL_291;
          case 0x39:
            sub_448A98(
              *(_BYTE *)(v11 + 5)
            + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 9)
            + ((*(_BYTE *)(v11 + 10) + ((*(_BYTE *)(v11 + 11) + (*(_BYTE *)(v11 + 12) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 13));
            goto LABEL_291;
          case 0xA:
            if ( !*(_BYTE *)(v11 + 5) )
              dword_6BE024 = *(_BYTE *)(v11 + 6) != 0;
            goto LABEL_291;
          case 0x1D:
            v93 = *(_BYTE *)(v11 + 5)
                + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8);
            if ( dword_5C3420 )
            {
              if ( dword_5C3420 == 1 )
              {
                dword_F8B1E8 = (&dword_721664)[8 * v93];
                goto LABEL_291;
              }
              if ( a3 == 1 )
              {
                v94 = (&dword_721664)[8 * v93];
LABEL_248:
                sub_44C175(v94, 2);
                goto LABEL_291;
              }
            }
            else
            {
              if ( a3 == 1 )
              {
                v94 = &pLevelStr[uLevelStrOffsets[v93]];
                goto LABEL_248;
              }
            }
            goto LABEL_291;
          case 0x1E:
            v95 = *(_BYTE *)(v11 + 5)
                + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8);
            if ( dword_5C3420 )
            {
              v96 = (&dword_721664)[8 * v95];
              byte_5B0938 = 0;
              dword_F8B1E8 = v96;
            }
            else
            {
              strcpy(&byte_5B0938, &pLevelStr[uLevelStrOffsets[v95]]);
            }
            goto LABEL_291;
          case 0x15:
            HIDWORD(v97) = *(_BYTE *)(v11 + 16)
                         + ((*(_BYTE *)(v11 + 17) + ((*(_BYTE *)(v11 + 18) + (*(_BYTE *)(v11 + 19) << 8)) << 8)) << 8);
            LODWORD(v97) = *(_BYTE *)(v11 + 12)
                         + ((*(_BYTE *)(v11 + 13) + ((*(_BYTE *)(v11 + 14) + (*(_BYTE *)(v11 + 15) << 8)) << 8)) << 8);
            sub_448DF8(
              *(_BYTE *)(v11 + 5),
              *(_BYTE *)(v11 + 6),
              *(_BYTE *)(v11 + 7),
              *(_BYTE *)(v11 + 8)
            + ((*(_BYTE *)(v11 + 9) + ((*(_BYTE *)(v11 + 10) + (*(_BYTE *)(v11 + 11) << 8)) << 8)) << 8),
              v97,
              *(_BYTE *)(v11 + 20)
            + ((*(_BYTE *)(v11 + 21) + ((*(_BYTE *)(v11 + 22) + (*(_BYTE *)(v11 + 23) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 24)
            + ((*(_BYTE *)(v11 + 25) + ((*(_BYTE *)(v11 + 26) + (*(_BYTE *)(v11 + 27) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 28)
            + ((*(_BYTE *)(v11 + 29) + ((*(_BYTE *)(v11 + 30) + (*(_BYTE *)(v11 + 31) << 8)) << 8)) << 8));
            goto LABEL_291;
          case 0xB:
            sub_44861E(
              *(_BYTE *)(v11 + 5)
            + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8),
              (const char *)(v11 + 9));
            goto LABEL_291;
          case 0xD:
            sub_44882F(
              *(_BYTE *)(v11 + 5)
            + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 9),
              (const char *)(v11 + 10));
            goto LABEL_291;
          case 0x13:
            sub_448CF4(
              *(_BYTE *)(v11 + 5),
              *(_BYTE *)(v11 + 6),
              *(_BYTE *)(v11 + 7),
              *(_BYTE *)(v11 + 8)
            + ((*(_BYTE *)(v11 + 9) + ((*(_BYTE *)(v11 + 10) + (*(_BYTE *)(v11 + 11) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 12)
            + ((*(_BYTE *)(v11 + 13) + ((*(_BYTE *)(v11 + 14) + (*(_BYTE *)(v11 + 15) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 16)
            + ((*(_BYTE *)(v11 + 17) + ((*(_BYTE *)(v11 + 18) + (*(_BYTE *)(v11 + 19) << 8)) << 8)) << 8),
              *(_BYTE *)(v11 + 20)
            + ((*(_BYTE *)(v11 + 21) + ((*(_BYTE *)(v11 + 22) + (*(_BYTE *)(v11 + 23) << 8)) << 8)) << 8),
              (const void *)(*(_BYTE *)(v11 + 24)
                           + ((*(_BYTE *)(v11 + 25) + ((*(_BYTE *)(v11 + 26) + (*(_BYTE *)(v11 + 27) << 8)) << 8)) << 8)));
            goto LABEL_291;
          case 4:
          case 5:
            --v126;
            goto LABEL_291;
          case 0xF:
            sub_449A49(*(_BYTE *)(v11 + 5), *(_BYTE *)(v11 + 6));
            goto LABEL_291;
          case 7:
            if ( !sub_42041E(*(_BYTE *)(v11 + 5)) )
              goto LABEL_301;
            goto LABEL_291;
          case 6:
            v99 = *(_BYTE *)(v11 + 5)
                + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8);
            v139 = *(_BYTE *)(v11 + 5)
                 + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8);
            v136 = *(_BYTE *)(v11 + 9)
                 + ((*(_BYTE *)(v11 + 10) + ((*(_BYTE *)(v11 + 11) + (*(_BYTE *)(v11 + 12) << 8)) << 8)) << 8);
            v130 = *(_BYTE *)(v11 + 13)
                 + ((*(_BYTE *)(v11 + 14) + ((*(_BYTE *)(v11 + 15) + (*(_BYTE *)(v11 + 16) << 8)) << 8)) << 8);
            v133 = *(_BYTE *)(v11 + 17)
                 + ((*(_BYTE *)(v11 + 18) + ((*(_BYTE *)(v11 + 19) + (*(_BYTE *)(v11 + 20) << 8)) << 8)) << 8);
            v100 = *(_BYTE *)(v11 + 21)
                 + ((*(_BYTE *)(v11 + 22) + ((*(_BYTE *)(v11 + 23) + (*(_BYTE *)(v11 + 24) << 8)) << 8)) << 8);
            v101 = *(_BYTE *)(v11 + 25);
            v98 = v101 + ((*(_BYTE *)(v11 + 26) + ((*(_BYTE *)(v11 + 27) + (*(_BYTE *)(v11 + 28) << 8)) << 8)) << 8);
            v138 = v101 + ((*(_BYTE *)(v11 + 26) + ((*(_BYTE *)(v11 + 27) + (*(_BYTE *)(v11 + 28) << 8)) << 8)) << 8);
            if ( *(_BYTE *)(v11 + 29) || *(_BYTE *)(v11 + 30) )
            {
              if ( pD3DRenderer->dword_040088 )
              {
                if ( !pD3DRenderer->dword_040058 )
                  sub_49FD3A(pD3DRenderer, v10);
              }
              sub_444839(
                *(_BYTE *)(pSomeEVT + v10 + 29),
                *(_BYTE *)(pSomeEVT + v10 + 30),
                v139,
                v136,
                v130,
                v133,
                v100,
                v138,
                (void *)(pSomeEVT + v10 + 31));
              dword_5C3418 = v135;
              dword_5C341C = v126 + 1;
              goto LABEL_301;
            }
            dword_5B65AC = *(_BYTE *)(v11 + 9)
                         + ((*(_BYTE *)(v11 + 10) + ((*(_BYTE *)(v11 + 11) + (*(_BYTE *)(v11 + 12) << 8)) << 8)) << 8);
            dword_5B65A8 = v99;
            dword_5B65B0 = v130;
            if ( v133 == -1 )
            {
              v102 = dword_5B65B4;
            }
            else
            {
              v102 = v133 & pClass59_global->dword_00186C;
              dword_5B65B4 = v133 & pClass59_global->dword_00186C;
            }
            v104 = (const char *)(v11 + 31);
            dword_5B65B8 = v100;
            dword_5B65BC = v98;
            v103 = v99 | v136 | v130 | v100 | v98 | v102;
            dword_5B65C0 = v103;
            if ( *v104 == 48 )
            {
              if ( v103 )
              {
                pParty_global->sPartyPosX = v139;
                pParty_global->sPartyPosY = v136;
                pParty_global->sPartyPosZ = v130;
                pParty_global->dword_000700 = v130;
                if ( dword_5B65B4 != -1 )
                  pParty_global->sRotationY = dword_5B65B4;
                dword_5B65B4 = -1;
                v124 = 0;
                v120 = 0;
                v115 = 0;
                v114 = 0;
                v113 = -1;
                v112 = 0;
                v111 = 0;
                pParty_global->sRotationX = v100;
                pParty_global->dword_0006E8 = v138;
                dword_5B65C0 = 0;
                dword_5B65BC = 0;
                dword_5B65B8 = 0;
                dword_5B65B0 = 0;
                dword_5B65AC = 0;
                dword_5B65A8 = 0;
                v110 = 232;
LABEL_280:
                AudioPlayer_sub_4AA306(pAudioPlayer, v110, v111, v112, v113, v114, v115, v120, v124);
              }
            }
            else
            {
              pLoadingUI->uProgressBarType = (dword_5C3420 == 0) + 1;
              sub_44987B(v104, 0);
              v137 = 1;
              if ( dword_4E28F8 == 13 )
              {
                if ( dword_6A0D48 == 2 )
                {
                  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
                  dword_F8B19C = 0;
                  while ( sub_4BD8B5() )
                    ;
                  CVideoPlayer_UnloadAll(pVideoPlayer);
                  GUIWindowDelete(dword_507BC0);
                  dword_507BC0 = 0;
                  if ( dword_50CBD0[0] )
                    dword_50CBD0[0] = dword_50CBDC != 0;
                  dword_4E28F8 = 0;
                  struct_576FE8.dword_000044 = 1;
                  dword_5913F0 = 0;
                  GUIWindowDelete(dword_507BBC);
                  dword_F8B19C = 0;
                  dword_507BBC = 0;
                  sub_40F9C5(pClass17_Icons_LOD);
                }
                goto LABEL_302;
              }
            }
            goto LABEL_291;
          case 3:
            v124 = 0;
            v120 = 0;
            v115 = 0;
            v114 = *(_BYTE *)(v11 + 13)
                 + ((*(_BYTE *)(v11 + 14) + ((*(_BYTE *)(v11 + 15) + (*(_BYTE *)(v11 + 16) << 8)) << 8)) << 8);
            v113 = *(_BYTE *)(v11 + 9)
                 + ((*(_BYTE *)(v11 + 10) + ((*(_BYTE *)(v11 + 11) + (*(_BYTE *)(v11 + 12) << 8)) << 8)) << 8);
            v112 = 0;
            v111 = 0;
            v110 = *(_BYTE *)(v11 + 5)
                 + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8);
            goto LABEL_280;
          case 0x29:
            sub_402F07((int)&v144);
            v106 = pSomeEVT + v10;
            v105 = *(_BYTE *)(v106 + 7)
                 + ((*(_BYTE *)(v106 + 8) + ((*(_BYTE *)(v106 + 9) + (*(_BYTE *)(v106 + 10) << 8)) << 8)) << 8);
            sub_456620(pClass40, *(_BYTE *)(v106 + 5), *(_BYTE *)(v106 + 6), (int)&v144);
            if ( v105 )
              v144 = v105;
            sub_4936E1(pParty_global, &v144);
            goto LABEL_291;
          case 2:
            v107 = *(_BYTE *)(v11 + 5)
                 + ((*(_BYTE *)(v11 + 6) + ((*(_BYTE *)(v11 + 7) + (*(_BYTE *)(v11 + 8) << 8)) << 8)) << 8);
            if ( sub_44622E(v107) )
            {
              if ( pD3DRenderer->dword_040088 )
              {
                if ( !pD3DRenderer->dword_040058 )
                  sub_49FD3A(pD3DRenderer, v107);
              }
              AudioPlayer_sub_4AA306(pAudioPlayer, 0, 0, 0, -1, 0, 0, 0, 0);
              AudioPlayer_sub_4AA306(pAudioPlayer, 6, 814, 0, -1, 0, 0, 0, 0);
              v108 = 187;
              if ( dword_591160 != 167 )
                v108 = v107;
              dword_507BC0 = GUIWindowCreate(0, 0, 640, 480, 25, v108, 0);
              GUIButtonCreate(dword_507BC0, 61, 424, 31, 0, 2, 94, 110, 1, 49, v7, 0);
              GUIButtonCreate(dword_507BC0, 177, 424, 31, 0, 2, 94, 110, 2, 50, v7, 0);
              GUIButtonCreate(dword_507BC0, 292, 424, 31, 0, 2, 94, 110, 3, 51, v7, 0);
              GUIButtonCreate(dword_507BC0, 407, 424, 31, 0, 2, 94, 110, 4, 52, v7, 0);
              GUIButtonCreate(dword_507BC0, 0, 0, 0, 0, 1, 0, 176, 0, 9, v7, 0);
            }
            goto LABEL_291;
          default:
            goto LABEL_291;
          case 0x21:
            v125 = 33;
            v109 = v126 + 1;
            goto LABEL_295;
          case 1:
            goto LABEL_301;
        }
      }
      ++v4;
      v128 = v4;
      if ( v4 >= uSomeEVT_NumEvents )
        goto LABEL_301;
    }
  }
}

//----- (00448518) --------------------------------------------------------
int __fastcall sub_448518(int a1, int a2, int a3)
{
  int result; // eax@1
  int v4; // edi@2
  char *v5; // ecx@6
  char *v6; // ecx@15

  result = 0;
  if ( (signed int)uNumActors > 0 )
  {
    v4 = (int)&pActors->word_000020;
    while ( *(_WORD *)v4 != a1 )
    {
      ++result;
      v4 += 836;
      if ( result >= (signed int)uNumActors )
        return result;
    }
    result *= 836;
    v5 = (char *)&unk_5FF20C + result;
    if ( a3 )
    {
      if ( *(_WORD *)v5 )
      {
        if ( *(_DWORD *)((char *)&unk_5FF38C + result) )
        {
          result += (int)&unk_5FF3B0;
          if ( !*(_DWORD *)result )
            *(_DWORD *)result = a2;
        }
        else
        {
          *(_DWORD *)((char *)&unk_5FF38C + result) = a2;
        }
      }
      else
      {
        *(_WORD *)v5 = a2;
      }
    }
    else
    {
      if ( *(_WORD *)v5 == a2 )
      {
        *(_WORD *)v5 = 0;
      }
      else
      {
        v6 = (char *)&unk_5FF38C + result;
        if ( *(_DWORD *)((char *)&unk_5FF38C + result) == a2
          || (v6 = (char *)&unk_5FF3B0 + result, *(_DWORD *)((char *)&unk_5FF3B0 + result) == a2) )
        {
          sub_402F07((int)v6);
          result = v6;
        }
      }
    }
  }
  return result;
}

//----- (004485A7) --------------------------------------------------------
int __fastcall sub_4485A7(signed int a1, int a2, int a3)
{
  int result; // eax@1
  char *v4; // ecx@3
  char *v5; // ecx@12

  result = a1;
  if ( a1 >= 0 )
  {
    if ( a1 <= (signed int)(uNumActors - 1) )
    {
      result = 836 * a1;
      v4 = (char *)&unk_5FF20C + 836 * a1;
      if ( a3 )
      {
        if ( *(_WORD *)v4 )
        {
          if ( *(_DWORD *)((char *)&unk_5FF38C + result) )
          {
            result += (int)&unk_5FF3B0;
            if ( !*(_DWORD *)result )
              *(_DWORD *)result = a2;
          }
          else
          {
            *(_DWORD *)((char *)&unk_5FF38C + result) = a2;
          }
        }
        else
        {
          *(_WORD *)v4 = a2;
        }
      }
      else
      {
        if ( *(_WORD *)v4 == a2 )
        {
          *(_WORD *)v4 = 0;
        }
        else
        {
          v5 = (char *)&unk_5FF38C + result;
          if ( *(_DWORD *)((char *)&unk_5FF38C + result) == a2
            || (v5 = (char *)&unk_5FF3B0 + result, *(_DWORD *)((char *)&unk_5FF3B0 + result) == a2) )
          {
           sub_402F07((int)v5);
           result = v5;
          }
        }
      }
    }
  }
  return result;
}

//----- (0044861E) --------------------------------------------------------
void __fastcall sub_44861E(int a1, const char *a2)
{
  int v2; // eax@2
  __int16 v3; // di@2
  signed int v4; // esi@5
  int v5; // eax@7
  int *v6; // eax@8
  int v7; // eax@9
  int v8; // edi@16
  int v9; // esi@16
  int v10; // eax@17
  int *v11; // eax@19
  __int16 v12; // [sp+Ch] [bp-18h]@2
  const char *v13; // [sp+10h] [bp-14h]@1
  int v14; // [sp+14h] [bp-10h]@1
  int v15; // [sp+18h] [bp-Ch]@14
  int v16; // [sp+1Ch] [bp-8h]@15
  signed int v17; // [sp+20h] [bp-4h]@4
  int v18; // [sp+20h] [bp-4h]@16

  v13 = a2;
  v14 = a1;
  if ( a1 )
  {
    v2 = class17_LoadTexture(pClass17_Bitmaps_LOD, a2, 0);
    v3 = v2;
    v12 = v2;
    if ( v2 != -1 ? 72 * v2 + 7278780 : 0 )
    {
      *(_WORD *)(v2 != -1 ? 72 * v2 + 7278780 + 0x26 : 38) = class35_sub_48A3BC(
                                                               &class35_obj,
                                                               *(_WORD *)(v2 != -1 ? 72 * v2 + 7278780 + 0x24 : 36));
      if ( dword_6BE360 == 1 )
      {
        v17 = 1;
        if ( dword_6BE648 > 1 )
        {
          v4 = 36;
          do
          {
            if ( *(_WORD *)(v4 + dword_6BE64C + 24) == v14 )
            {
              v5 = dword_6BE644 + 96 * *(_WORD *)(v4 + dword_6BE64C + 12);
              if ( *(_BYTE *)(v5 + 45) & 0x40 )
              {
                *(_WORD *)(96 * *(_WORD *)(v4 + dword_6BE64C + 12) + dword_6BE644 + 74) = sub_44E163(pTextureFrameTable, v13);
                v6 = (int *)(96 * *(_WORD *)(v4 + dword_6BE64C + 12) + dword_6BE644 + 74);
                if ( *(_WORD *)v6 )
                {
                  sub_44E0ED(pTextureFrameTable, *(_WORD *)v6);
                }
                else
                {
                  *(_WORD *)v6 = v3;
                  v7 = 96 * *(_WORD *)(v4 + dword_6BE64C + 12) + dword_6BE644 + 44;
                  *(_BYTE *)(v7 + 1) &= 0xBFu;
                }
              }
              else
              {
                *(_WORD *)(v5 + 74) = v3;
              }
            }
            ++v17;
            v4 += 36;
          }
          while ( v17 < dword_6BE648 );
        }
        pParty_global->dword_007778 |= 2;
      }
      else
      {
        v15 = 0;
        if ( pClass51_global->uNumBModels > 0 )
        {
          v16 = 0;
          do
          {
            v8 = 0;
            v9 = v16 + pClass51_global->pBModels + 68;
            v18 = 0;
            if ( *(_DWORD *)(v16 + pClass51_global->pBModels + 76) > 0 )
            {
              do
              {
                v10 = v8 + *(_DWORD *)(v9 + 16);
                if ( *(_WORD *)(v10 + 290) == v14 )
                {
                  if ( *(_BYTE *)(v10 + 29) & 0x40 )
                  {
                    *(_WORD *)(*(_DWORD *)(v9 + 16) + v8 + 272) = sub_44E163(pTextureFrameTable, v13);
                    v11 = (int *)(*(_DWORD *)(v9 + 16) + v8 + 272);
                    if ( *(_WORD *)v11 )
                    {
                      sub_44E0ED(pTextureFrameTable, *(_WORD *)v11);
                    }
                    else
                    {
                      *(_WORD *)v11 = v12;
                      *(_BYTE *)(*(_DWORD *)(v9 + 16) + v8 + 29) &= 0xBFu;
                    }
                  }
                  else
                  {
                    *(_WORD *)(v10 + 272) = v12;
                  }
                }
                ++v18;
                v8 += 308;
              }
              while ( v18 < *(_DWORD *)(v9 + 8) );
            }
            ++v15;
            v16 += 188;
          }
          while ( v15 < pClass51_global->uNumBModels );
        }
      }
      pParty_global->dword_007778 |= 2;
    }
  }
}

//----- (0044882F) --------------------------------------------------------
void __fastcall sub_44882F(int a1, int a2, const char *Str1)
{
  signed int v3; // ebp@1
  _UNKNOWN *v4; // esi@2
  __int16 v5; // ax@6
  int v6; // [sp+4h] [bp-8h]@1
  int v7; // [sp+8h] [bp-4h]@1

  v3 = 0;
  v7 = a2;
  v6 = a1;
  if ( (signed int)dword_69ADD0 > 0 )
  {
   v4 = &array_6836D0[0].word_000002;
    do
    {
      if ( *((_WORD *)v4 + 9) == v6 )
      {
        if ( Str1 )
        {
          if ( _strcmpi(Str1, L"0") )
          {
            v5 = sub_4488B6(pDecorationDescriptionList, Str1);
            *((_WORD *)v4 - 1) = v5;
            sub_458693(pDecorationDescriptionList, v5);
          }
        }
        if ( v7 )
          *(_BYTE *)v4 &= 0xDFu;
        else
          *(_BYTE *)v4 |= 0x20u;
        pParty_global->dword_007778 |= 2;
      }
      ++v3;
      v4 = (char *)v4 + 32;
    }
    while ( v3 < (signed int)dword_69ADD0 );
  }
}

//----- (004488F7) --------------------------------------------------------
void __fastcall sub_4488F7(int a1, int a2)
{
  int v2; // eax@4

  if ( dword_6BE360 == 1 )
  {
    if ( a1 <= dword_6BE658 - 1 )
    {
      if ( a1 >= 0 )
      {
        v2 = 16 * a1 + dword_6BE65C + 12;
        if ( a2 )
          *(_BYTE *)v2 &= 0xF7u;
        else
          *(_BYTE *)v2 |= 8u;
        pParty_global->dword_007778 |= 2;
      }
    }
  }
}

//----- (0044892E) --------------------------------------------------------
int __fastcall sub_44892E(int a1, int a2, int a3)
{
  int result; // eax@1
  signed int v4; // esi@2
  signed int v5; // ecx@4
  int v6; // ecx@13
  int v7; // edi@13
  int v8; // esi@13
  int v9; // eax@14
  int v10; // [sp+0h] [bp-Ch]@1
  int v11; // [sp+4h] [bp-8h]@11
  int v12; // [sp+8h] [bp-4h]@12

  result = 0;
  v10 = a1;
  if ( a1 )
  {
    v4 = 1;
    if ( dword_6BE360 == 1 )
    {
      if ( dword_6BE648 > 1 )
      {
        v5 = 36;
        do
        {
          result = v5 + dword_6BE64C;
          if ( *(_WORD *)(v5 + dword_6BE64C + 24) == v10 )
          {
            result = 96 * *(_WORD *)(result + 12) + dword_6BE644 + 44;
            if ( a3 )
              *(_DWORD *)result |= a2;
            else
              *(_DWORD *)result &= ~a2;
          }
          ++v4;
          v5 += 36;
        }
        while ( v4 < dword_6BE648 );
      }
      pParty_global->dword_007778 |= 2;
    }
    else
    {
      v11 = 0;
      if ( pClass51_global->uNumBModels > 0 )
      {
        v12 = 0;
        do
        {
          v7 = 0;
          v8 = v12 + pClass51_global->pBModels + 68;
          v6 = 0;
          if ( *(_DWORD *)(v12 + pClass51_global->pBModels + 76) > 0 )
          {
            do
            {
              v9 = v7 + *(_DWORD *)(v8 + 16);
              if ( *(_WORD *)(v9 + 290) == v10 )
              {
                if ( a3 )
                  *(_DWORD *)(v9 + 28) |= a2;
                else
                  *(_DWORD *)(v9 + 28) &= ~a2;
              }
              ++v6;
              v7 += 308;
            }
            while ( v6 < *(_DWORD *)(v8 + 8) );
          }
          ++v11;
          result = pClass51_global->uNumBModels;
          v12 += 188;
        }
        while ( v11 < pClass51_global->uNumBModels );
      }
    }
    pParty_global->dword_007778 |= 2;
  }
  return result;
}

//----- (00448A17) --------------------------------------------------------
void __fastcall sub_448A17(signed int a1, __int16 a2, int a3)
{
  char *v3; // eax@3

  if ( a1 >= 0 )
  {
    if ( a1 <= 19 )
    {
      v3 = &byte_5E5152[5324 * a1];
      if ( a3 )
        *(_WORD *)v3 |= a2;
      else
        *(_WORD *)v3 &= ~a2;
    }
  }
}

//----- (00448A40) --------------------------------------------------------
void __fastcall sub_448A40(signed int a1, int a2, int a3)
{
  __int16 *v3; // eax@6

  if ( a1 >= 0 )
  {
    if ( a1 <= (signed int)(uNumActors - 1) )
    {
      if ( a3 )
      {
       *(int *)pActors[a1].byte_000024 | a2;
      }
      else
      {
        if ( a2 == 65536 )
        {
          v3 = &pActors[a1].word_0000B0;
          if ( *v3 == 19 )
            *v3 = 0;
        }
        *(int *)pActors[a1].byte_000024 &= ~a2;
      }
    }
  }
}

//----- (00448A98) --------------------------------------------------------
void __fastcall sub_448A98(int a1, int a2, int a3)
{
  int v3; // ebx@1
  int v4; // ebp@1
  signed int v5; // edi@1
  _UNKNOWN *v6; // esi@4
  size_t v7; // ecx@10
  int v8; // eax@11
  __int16 v9; // dx@14

  v4 = a1;
  v5 = 0;
  v3 = a2;
  if ( a1 )
  {
    if ( a3 )
    {
      if ( (signed int)uNumActors > 0 )
      {
       v6 = pActors->byte_000024;
        do
        {
          if ( *((_DWORD *)v6 + 168) == v4 )
          {
            *(_DWORD *)v6 |= v3;
            if ( v3 == 65536 )
            {
              *((_WORD *)v6 + 70) = 19;
              sub_45976D((int)((char *)v6 - 36));
            }
          }
          ++v5;
          v6 = (char *)v6 + 836;
        }
        while ( v5 < (signed int)uNumActors );
      }
    }
    else
    {
      v7 = uNumActors;
      if ( (signed int)uNumActors > 0 )
      {
        v8 = &pActors[0].word_0000B0;
        do
        {
          if ( *(_DWORD *)(v8 + 532) == v4 )
          {
            if ( v3 == 65536 )
            {
              v9 = *(_WORD *)v8;
              if ( *(_WORD *)v8 != 5 )
              {
                if ( v9 != 4 )
                {
                  if ( v9 != 11 )
                    *(_WORD *)v8 = 0;
                }
              }
            }
            *(_DWORD *)(v8 - 140) &= ~v3;
          }
          v8 += 836;
          --v7;
        }
        while ( v7 );
      }
    }
  }
}

//----- (00448CF4) --------------------------------------------------------
const void *__fastcall sub_448CF4(__int16 a1, __int16 a2, signed int a3, int a4, int a5, int a6, int a7, const void *a8)
{
  const void *result; // eax@1
  __int16 v9; // di@1
  __int16 v10; // si@1
  signed int v11; // ebx@2
  signed int v12; // esi@2
  char *v13; // ebx@3
  char v14; // [sp+Ch] [bp-50h]@2
  char v15; // [sp+28h] [bp-34h]@2
  __int16 v16; // [sp+3Ch] [bp-20h]@4
  int v17; // [sp+44h] [bp-18h]@1
  int v18; // [sp+48h] [bp-14h]@1
  int v19; // [sp+4Ch] [bp-10h]@1
  __int16 v20; // [sp+50h] [bp-Ch]@1
  __int16 v21; // [sp+52h] [bp-Ah]@1
  __int16 v22; // [sp+54h] [bp-8h]@1
  int v23; // [sp+58h] [bp-4h]@1

  v9 = a1;
  v10 = a2;
  sub_448DD6((int)&v17);
  v17 = a4;
  v18 = a5;
  v19 = a6;
  v23 = a7;
  v20 = 32;
  v21 = 3;
  v22 = v9 + 2 * v10 + v10;
  result = (const void *)CMapStats_FindLocation(pMapStats, Str1);
  if ( result )
  {
    v11 = uNumActors;
    sub_44F57C((int)&pMapStats->pMapInfos[(_DWORD)result], (int)&v17, 0, a3, 0);
    result = sub_4040E9(8 * v11 | 3, 4, &v14, 1);
    memcpy(&v15, result, 0x1Cu);
    v12 = v11;
    if ( v11 < (signed int)uNumActors )
    {
      v13 = (char *)&unk_5FF1F2 + 836 * v11;
      do
      {
        sub_45959A((int)(v13 - 154), 0);
        ++v12;
        *(_WORD *)v13 = v16;
        result = a8;
        *(_DWORD *)(v13 + 666) = a8;
        v13 += 836;
      }
      while ( v12 < (signed int)uNumActors );
    }
  }
  return result;
}

//----- (00448DD6) --------------------------------------------------------
int __thiscall sub_448DD6(int this)
{
  int result; // eax@1

  result = this;
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 4) = 0;
  *(_DWORD *)this = 0;
  *(_WORD *)(this + 12) = 32;
  *(_WORD *)(this + 18) = 0;
  *(_WORD *)(this + 16) = 0;
  *(_WORD *)(this + 14) = 0;
  *(_DWORD *)(this + 20) = 0;
  return result;
}

//----- (00448DF8) --------------------------------------------------------
void __fastcall sub_448DF8(int a1, int a2, signed int a3, int a4, __int64 a5, signed int a6, signed int a7, signed int a8)
{
  int v8; // esi@1
  double v9; // st5@4
  double v10; // st6@4
  double v11; // st7@4
  double v12; // st7@6
  int v13; // ST44_4@7
  signed int v14; // ebx@9
  int v15; // edx@15
  int v16; // ecx@16
  __int16 v17; // ax@20
  int v18; // ecx@31
  int v19; // edx@35
  int v20; // edx@37
  int v21; // ecx@38
  __int16 v22; // ax@41
  int i; // esi@42
  int v24; // edx@55
  int v25; // ecx@56
  __int16 v26; // ax@59
  int j; // esi@60
  int v28; // edx@66
  int v29; // ecx@67
  __int16 v30; // ax@70
  signed int v31; // eax@80
  __int16 v32; // si@85
  int v33; // eax@96
  int v34; // eax@97
  __int64 v35; // qax@99
  int *v36; // ecx@99
  int v37; // esi@103
  signed __int64 v38; // qax@105
  int v39; // ebx@108
  int v40; // ebx@109
  int v41; // ebx@111
  int v42; // esi@111
  int v43; // eax@117
  __int16 v44; // si@137
  __int16 v45; // [sp-8h] [bp-BCh]@99
  int v46; // [sp-4h] [bp-B8h]@35
  __int16 v47; // [sp-4h] [bp-B8h]@99
  int v48; // [sp+0h] [bp-B4h]@35
  int v49[5]; // [sp+0h] [bp-B4h]@99
  int v50; // [sp+4h] [bp-B0h]@35
  char v51; // [sp+4h] [bp-B0h]@99
  float v52; // [sp+14h] [bp-A0h]@4
  float v53; // [sp+18h] [bp-9Ch]@4
  int v54; // [sp+28h] [bp-8Ch]@7
  int v55; // [sp+30h] [bp-84h]@7
  int v56; // [sp+34h] [bp-80h]@7
  __int16 v57; // [sp+38h] [bp-7Ch]@12
  __int16 v58; // [sp+3Ah] [bp-7Ah]@35
  int v59; // [sp+3Ch] [bp-78h]@35
  __int64 v60; // [sp+40h] [bp-74h]@35
  __int16 v61; // [sp+4Eh] [bp-66h]@35
  __int16 v62; // [sp+50h] [bp-64h]@35
  __int16 v63; // [sp+52h] [bp-62h]@35
  __int16 v64; // [sp+54h] [bp-60h]@35
  __int16 v65; // [sp+56h] [bp-5Eh]@35
  char v66; // [sp+5Ch] [bp-58h]@15
  int v67; // [sp+80h] [bp-34h]@15
  int v68; // [sp+84h] [bp-30h]@15
  int v69; // [sp+88h] [bp-2Ch]@15
  int v70; // [sp+90h] [bp-24h]@35
  int v71; // [sp+94h] [bp-20h]@35
  char v72; // [sp+98h] [bp-1Ch]@35
  int v73; // [sp+A8h] [bp-Ch]@1
  int v74; // [sp+ACh] [bp-8h]@1
  int v75; // [sp+B0h] [bp-4h]@1
  signed int v76; // [sp+BCh] [bp+8h]@80
  int v77; // [sp+C8h] [bp+14h]@117
  float v78; // [sp+CCh] [bp+18h]@6
  signed int v79; // [sp+CCh] [bp+18h]@12
  int v80; // [sp+CCh] [bp+18h]@29
  int v81; // [sp+CCh] [bp+18h]@55
  float v82; // [sp+D0h] [bp+1Ch]@6
  int v83; // [sp+D0h] [bp+1Ch]@37
  int v84; // [sp+D0h] [bp+1Ch]@55
  float v85; // [sp+D4h] [bp+20h]@6

  v8 = 0;
  v73 = a2 + 1;
  v75 = a1;
  v74 = 0;
  if ( a6 || a7 || a8 )
  {
    v11 = (double)a6 - (double)a4;
    v52 = v11;
    v10 = (double)a7 - (double)(signed int)a5;
    v53 = v10;
    v9 = (double)a8;
  }
  else
  {
    v11 = (double)pParty_global->sPartyPosX - (double)a4;
    v52 = v11;
    v10 = (double)pParty_global->sPartyPosY - (double)(signed int)a5;
    v53 = v10;
    v9 = (double)(pParty_global->sPartyPosZ + pParty_global->uEyelevel);
  }
  v78 = v9 - (double)SHIDWORD(a5);
  v85 = v10 * v10;
  v82 = v11 * v11;
  v12 = sqrt(v78 * v78 + v82 + v85);
  if ( v12 <= memory_4D8410.f1_0 )
  {
    LOBYTE(v54) = 1;
    v55 = 0;
    v56 = 0;
  }
  else
  {
    v54 = (signed __int64)v12;
    v13 = (signed __int64)sqrt(v82 + v85);
    v55 = sub_45281E(pClass59_global, (signed __int64)v52, (signed __int64)v53);
    v56 = sub_45281E(pClass59_global, v13, (signed __int64)v78);
  }
  v14 = v73;
  if ( v73 <= 0 || v73 > 4 )
    v14 = 1;
  v79 = v14;
  sub_404828(&v57);
  v57 = word_4E3ACC[2 * v75];
  if ( v75 > 58 )
  {
    if ( v75 == 69 )
      goto LABEL_117;
    if ( v75 != 83 )
      return;
    v39 = v14 - 2;
    if ( v39 )
    {
      v40 = v39 - 1;
      if ( !v40 )
      {
        v42 = 14400 * a3;
        v41 = 4 * a3 + 10;
        goto LABEL_114;
      }
      if ( v40 == 1 )
      {
        v42 = 18000 * a3;
        v41 = 5 * a3 + 10;
        goto LABEL_114;
      }
    }
    v42 = 10800 * a3;
    v41 = 3 * a3 + 10;
LABEL_114:
    sub_4A89BD(pGame->class06_obj, 83, 0);
    sub_4A89BD(pGame->class06_obj, 83, 1);
    sub_4A89BD(pGame->class06_obj, 83, 2);
    sub_4A89BD(pGame->class06_obj, 83, 3);
    v51 = 0;
    v49[0] = 0;
    v47 = v41;
    v45 = v79;
    v38 = (signed __int64)((double)(v42 << 7) * 0.03333333507180214);
    v36 = (int *)&unk_ACD864;
LABEL_115:
    v35 = pParty_global->qword_00002C + v38;
LABEL_116:
    sub_4584E0((int)v36, v35, SHIDWORD(v35), v45, v47, v49[0], v51);
    goto LABEL_139;
  }
  if ( v75 != 58 )
  {
    switch ( v75 )
    {
      case 2:
      case 6:
      case 18:
      case 26:
      case 29:
      case 32:
      case 39:
      case 41:
        sub_402F07((int)&v66);
        v15 = 0;
        v67 = v75;
        v68 = a3;
        v69 = v14;
        if ( pObjectDescriptionList->uNumObjects <= 0 )
          goto LABEL_34;
        v16 = pObjectDescriptionList->pDescriptions + 32;
        while ( v57 != *(_WORD *)v16 )
        {
          ++v15;
          v16 += 56;
          if ( v15 >= pObjectDescriptionList->uNumObjects )
            goto LABEL_34;
        }
LABEL_20:
        v17 = v15;
        goto LABEL_35;
      case 24:
        switch ( v14 )
        {
          case 1:
            v74 = 1;
            break;
          case 2:
            v74 = 3;
            break;
          case 3:
            v74 = 5;
            break;
          case 4:
            v74 = 7;
            break;
        }
        v80 = 60 * pClass59_global->dword_001868 / 360;
        if ( v74 != 1 )
        {
          v83 = v80 / (v74 - 1);
          sub_402F07((int)&v66);
          v20 = 0;
          v67 = v75;
          v68 = a3;
          v69 = v14;
          if ( pObjectDescriptionList->uNumObjects <= 0 )
          {
LABEL_41:
            v22 = 0;
          }
          else
          {
            v21 = pObjectDescriptionList->pDescriptions + 32;
            while ( v57 != *(_WORD *)v21 )
            {
              ++v20;
              v21 += 56;
              if ( v20 >= pObjectDescriptionList->uNumObjects )
                goto LABEL_41;
            }
            v22 = v20;
          }
          v58 = v22;
          v60 = a5;
          v59 = a4;
          v63 = 16;
          v64 = sub_49AC17((int)byte_6BE3C8, a4, a5, SHIDWORD(a5));
          v72 = v54;
          v65 = 0;
          v70 = 8002;
          v71 = 4;
          v62 = 0;
          for ( i = v80 / -2; i <= v80 / 2; i += v83 )
          {
            v61 = i + v55;
            sub_42F5ED(
              (int)&v57,
              (signed __int16)(i + (_WORD)v55),
              v56,
              *(_WORD *)(56 * v58 + pObjectDescriptionList->pDescriptions + 48),
              0);
          }
          goto LABEL_139;
        }
        sub_402F07((int)&v66);
        v15 = 0;
        v67 = v75;
        v68 = a3;
        v69 = v14;
        if ( pObjectDescriptionList->uNumObjects <= 0 )
          goto LABEL_34;
        v18 = pObjectDescriptionList->pDescriptions + 32;
        do
        {
          if ( v57 == *(_WORD *)v18 )
            goto LABEL_20;
          ++v15;
          v18 += 56;
        }
        while ( v15 < pObjectDescriptionList->uNumObjects );
LABEL_34:
        v17 = 0;
LABEL_35:
        v58 = v17;
        v60 = a5;
        v59 = a4;
        v63 = 16;
        v64 = sub_49AC17((int)byte_6BE3C8, a4, a5, SHIDWORD(a5));
        v72 = v54;
        v19 = v55;
        v65 = 0;
        v70 = 8002;
        v71 = 0;
        v61 = v55;
        v62 = 0;
        v50 = 0;
        v48 = *(_WORD *)(56 * v58 + pObjectDescriptionList->pDescriptions + 48);
        v46 = v56;
        goto LABEL_36;
      case 15:
        switch ( v14 )
        {
          case 1:
            v74 = 3;
            break;
          case 2:
            v74 = 5;
            break;
          case 3:
            v74 = 7;
            break;
          case 4:
            v74 = 9;
            break;
        }
        v81 = 60 * pClass59_global->dword_001868 / 360;
        v84 = 60 * pClass59_global->dword_001868 / 360 / (v74 - 1);
        sub_402F07((int)&v66);
        v24 = 0;
        v67 = v75;
        v68 = a3;
        v69 = v14;
        if ( pObjectDescriptionList->uNumObjects <= 0 )
          goto LABEL_59;
        v25 = pObjectDescriptionList->pDescriptions + 32;
        while ( v57 != *(_WORD *)v25 )
        {
          ++v24;
          v25 += 56;
          if ( v24 >= pObjectDescriptionList->uNumObjects )
          {
LABEL_59:
            v26 = 0;
            goto LABEL_60;
          }
        }
        v26 = v24;
LABEL_60:
        v58 = v26;
        v60 = a5;
        v59 = a4;
        v63 = 16;
        v64 = sub_49AC17((int)byte_6BE3C8, a4, a5, SHIDWORD(a5));
        v72 = v54;
        v65 = 0;
        v70 = 8002;
        v71 = 4;
        v62 = 0;
        for ( j = v81 / -2; j <= v81 / 2; j += v84 )
        {
          v61 = j + v55;
          sub_42F5ED(
            (int)&v57,
            (signed __int16)(j + (_WORD)v55),
            v56,
            *(_WORD *)(56 * v58 + pObjectDescriptionList->pDescriptions + 48),
            0);
        }
        goto LABEL_139;
      case 43:
        if ( dword_6BE360 == 1 )
          return;
        sub_402F07((int)&v66);
        v28 = 0;
        v67 = v75;
        v68 = a3;
        v69 = v14;
        if ( pObjectDescriptionList->uNumObjects <= 0 )
          goto LABEL_70;
        v29 = pObjectDescriptionList->pDescriptions + 32;
        break;
      case 5:
        if ( v14 > 0 )
        {
          if ( v14 <= 2 )
          {
            v8 = 60 * (a3 + 60);
          }
          else
          {
            if ( v14 == 3 )
            {
              v8 = 180 * (a3 + 20);
            }
            else
            {
              if ( v14 == 4 )
                v8 = 240 * (a3 + 15);
            }
          }
        }
        v76 = 1;
        v31 = (signed int)&dword_ACD98C;
        do
        {
          if ( *(_QWORD *)v31 )
            v76 = 0;
          v31 += 6972;
        }
        //while ( v31 < (signed int)&unk_AD467C );
        while (v31 < &array_AD4674[0].dword_000008);

        if ( !v76 )
          return;
        sub_4584E0(&qword_ACD8C4,
          pParty_global->qword_00002C + (signed __int64)((double)(v8 << 7) * 0.03333333507180214),
          (unsigned __int64)(pParty_global->qword_00002C + (signed int)(signed __int64)((double)(v8 << 7) * 0.03333333507180214)) >> 32,
          v14,
          0,
          0,
          0);
        v32 = v75;
        sub_4A89BD(pGame->class06_obj, v75, 0);
        sub_4A89BD(pGame->class06_obj, v32, 1);
        sub_4A89BD(pGame->class06_obj, v32, 2);
        sub_4A89BD(pGame->class06_obj, v32, 3);
        goto LABEL_138;
      case 17:
      case 38:
      case 51:
        switch ( v14 )
        {
          case 1:
          case 2:
            v8 = 300 * (a3 + 12);
            break;
          case 3:
            v8 = 900 * (a3 + 4);
            break;
          case 4:
            v8 = 3600 * (a3 + 1);
            break;
        }
        switch ( v75 )
        {
          case 17:
            v74 = 0;
            a3 = 14;
            break;
          case 38:
            v34 = a3 + 5;
            a3 = 15;
            v74 = v34;
            break;
          case 51:
            v33 = a3 + 5;
            a3 = 9;
            v74 = v33;
            break;
        }
        sub_4A89BD(pGame->class06_obj, v75, 0);
        sub_4A89BD(pGame->class06_obj, v75, 1);
        sub_4A89BD(pGame->class06_obj, v75, 2);
        sub_4A89BD(pGame->class06_obj, v75, 3);
        v51 = 0;
        v49[0] = 0;
        v47 = v74;
        v45 = v14;
        v35 = pParty_global->qword_00002C + (signed int)(signed __int64)((double)(v8 << 7) * 0.03333333507180214);
        v36 = pParty_global->array_00088C[a3];
        goto LABEL_116;
      case 8:
        if ( v14 == 2 || v14 == 3 || v14 != 4 )
          v37 = 60 * a3;
        else
          v37 = 600 * a3;
        sub_4A89BD(pGame->class06_obj, v75, 0);
        sub_4A89BD(pGame->class06_obj, v75, 1);
        sub_4A89BD(pGame->class06_obj, v75, 2);
        sub_4A89BD(pGame->class06_obj, v75, 3);
        v51 = 0;
        v49[0] = 0;
        v47 = a3;
        v45 = v14;
        v38 = (signed __int64)((double)(v37 << 7) * 0.03333333507180214);
        v36 = &dword_ACD8E4;
        goto LABEL_115;
      case 3:
      case 14:
      case 25:
      case 36:
        goto LABEL_117;
      default:
        return;
    }
    while ( v57 != *(_WORD *)v29 )
    {
      ++v28;
      v29 += 56;
      if ( v28 >= pObjectDescriptionList->uNumObjects )
      {
LABEL_70:
        v30 = 0;
        goto LABEL_71;
      }
    }
    v30 = v28;
LABEL_71:
    v58 = v30;
    v60 = a5;
    v59 = a4;
    v63 = 16;
    v64 = sub_49AC17((int)byte_6BE3C8, a4, a5, SHIDWORD(a5));
    v72 = v54;
    v65 = 0;
    v70 = 8002;
    v71 = 4;
    v62 = 0;
    v50 = 0;
    v48 = *(_WORD *)(56 * v58 + pObjectDescriptionList->pDescriptions + 48);
    v19 = v55;
    v46 = pClass59_global->uNumTableEntries / 2;
LABEL_36:
    sub_42F5ED((int)&v57, v19, v46, v48, v50);
    goto LABEL_139;
  }
LABEL_117:
  v43 = a3;
  v77 = 3600 * a3;
  if ( v14 == 1 )
  {
LABEL_124:
    v74 = v43;
    goto LABEL_125;
  }
  if ( v14 == 2 )
  {
    v43 = 2 * a3;
    goto LABEL_124;
  }
  if ( v14 == 3 )
  {
    v43 = 3 * a3;
    goto LABEL_124;
  }
  if ( v14 == 4 )
  {
    v43 = 4 * a3;
    goto LABEL_124;
  }
LABEL_125:
  switch ( v75 )
  {
    case 3:
      a3 = 6;
      break;
    case 14:
      a3 = 0;
      break;
    case 25:
      a3 = 17;
      break;
    case 36:
      a3 = 4;
      break;
    case 58:
      a3 = 12;
      break;
    case 69:
      a3 = 1;
      break;
  }
  v44 = v75;
  sub_4A89BD(pGame->class06_obj, v75, 0);
  sub_4A89BD(pGame->class06_obj, v44, 1);
  sub_4A89BD(pGame->class06_obj, v44, 2);
  sub_4A89BD(pGame->class06_obj, v44, 3);
  sub_4584E0((int)pParty_global->array_00088C[a3],
    pParty_global->qword_00002C + (signed __int64)((double)v77 * 4.266666889190674),
    (unsigned __int64)(pParty_global->qword_00002C + (signed int)(signed __int64)((double)v77 * 4.266666889190674)) >> 32,
    v14,
    v74,
    0,
    0);
  v76 = 1;
LABEL_138:
  if ( v76 )
LABEL_139:
    AudioPlayer_sub_4AA306(pAudioPlayer, word_4EE088[v75], 0, 0, a4, a5, 0, 0, 0);
}

//----- (0044987B) --------------------------------------------------------
char *__fastcall sub_44987B(const char *Source, int a2)
{
  int v2; // ebx@1
  const char *v3; // edi@1
  char *result; // eax@3

  v3 = Source;
  v2 = a2;
  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  LevelLoadingUI_Initialize(pLoadingUI, 0);
  if ( _strcmpi(Str1, v3) )
    SaveGame(1, 0);
  dword_6A0D48 = 2;
  result = strcpy(Str1, v3);
  dword_6BE35C = v2;
  return result;
}

//----- (00449A49) --------------------------------------------------------
__int16 __fastcall sub_449A49(int a1, int a2)
{
  int v2; // eax@1
  int v3; // ebx@1
  char *v4; // edx@2
  signed int v5; // esi@2
  char *v6; // ecx@8
  int v7; // edx@18
  int v8; // eax@19
  signed int v9; // esi@19
  char Args; // [sp+Ch] [bp-78h]@6

  LOWORD(v2) = (_WORD)Src;
  v3 = a2;
  if ( !Src )
    return v2;
  v5 = 0;
  v4 = (char *)Src + 4;
  do
  {
    if ( *(_DWORD *)v4 == a1 )
      break;
    ++v5;
    v4 += 80;
  }
  while ( v5 < 200 );
  if ( v5 >= 200 )
  {
    sprintfex(&Args, "Unable to find Door ID: %i!", a1);
    erroneous_printf(&Args);
  }
  v6 = (char *)Src + 80 * v5;
  if ( v3 == 2 )
  {
    LOWORD(v2) = *((_WORD *)v6 + 38);
    if ( (_WORD)v2 == 3 || (_WORD)v2 == 1 )
      return v2;
    if ( (_WORD)v2 )
      goto LABEL_14;
  }
  else
  {
    if ( !v3 )
    {
LABEL_14:
      LOWORD(v2) = *((_WORD *)v6 + 38);
      if ( (_WORD)v2 && (_WORD)v2 != 3 )
      {
        *((_WORD *)v6 + 38) = 3;
        if ( (_WORD)v2 == 2 )
        {
LABEL_17:
          *((_DWORD *)v6 + 2) = 0;
          return v2;
        }
        v7 = *((_DWORD *)v6 + 2);
        v2 = 15360;
        if ( v7 != 15360 )
        {
          v9 = *((_DWORD *)v6 + 7);
          v8 = *((_DWORD *)v6 + 8);
LABEL_26:
          v2 = (*((_DWORD *)v6 + 6) << 7) / v9 - (v7 * v8 / 128 << 7) / v9;
          goto LABEL_27;
        }
        goto LABEL_27;
      }
      return v2;
    }
    if ( v3 != 1 )
      return v2;
  }
  LOWORD(v2) = *((_WORD *)v6 + 38);
  if ( (_WORD)v2 != 2 && (_WORD)v2 != 1 )
  {
    *((_WORD *)v6 + 38) = 1;
    if ( !(_WORD)v2 )
      goto LABEL_17;
    v7 = *((_DWORD *)v6 + 2);
    v2 = 15360;
    if ( v7 != 15360 )
    {
      v9 = *((_DWORD *)v6 + 8);
      v8 = *((_DWORD *)v6 + 7);
      goto LABEL_26;
    }
LABEL_27:
    *((_DWORD *)v6 + 2) = v2;
  }
  return v2;
}

//----- (00449B57) --------------------------------------------------------
unsigned int __fastcall sub_449B57(int a1, __int16 a2)
{
  return *(_BYTE *)(((a2 - 1) >> 3) + a1) & (0x80u >> (a2 - 1) % 8);
}

//----- (00449BB4) --------------------------------------------------------
char __thiscall sub_449BB4(int this, signed int a2, void *a3)
{
  int v3; // edi@1
  int v4; // esi@1
  unsigned int v5; // eax@8
  int v6; // eax@9
  signed int v7; // eax@11
  unsigned __int8 v8; // sf@17
  unsigned __int8 v9; // of@17
  signed int v10; // eax@17
  int v11; // eax@19
  int v12; // eax@20
  unsigned int v13; // eax@25
  char v14; // cl@25
  int v15; // eax@28
  signed int v16; // ecx@28
  char v17; // zf@31
  int v18; // edi@90
  _UNKNOWN *v19; // eax@122
  char v20; // cl@124
  _UNKNOWN *v21; // eax@126
  int v22; // edi@129
  signed __int64 v23; // qax@131
  signed int v24; // esi@134
  signed int v25; // edx@135
  signed int v26; // ecx@135
  int v27; // ebx@155
  int v28; // edi@155
  int v29; // eax@161
  int v30; // ebx@161

  v4 = this;
  v3 = -1;
  if ( a2 > 223 )
  {
    switch ( a2 )
    {
      case 314:
        compile_error;//if ( dword_ACD8F8 >= 0 && (dword_ACD8F8 > 0 || (unsigned int)dword_ACD8F4 > 0) )
          goto LABEL_132;
        goto LABEL_170;
      case 307:
       v3 = pParty_global->dword_00073C;
        goto LABEL_170;
      case 308:
        v3 = pParty_global->dword_000748;
        goto LABEL_170;
      case 309:
        v3 = pParty_global->dword_000744;
        goto LABEL_170;
      case 310:
        v3 = (unsigned __int8)byte_ACD76E;
        goto LABEL_170;
      case 311:
        v3 = (unsigned __int8)byte_ACD76F;
        goto LABEL_170;
      case 312:
        v3 = (unsigned __int8)byte_ACD770;
        goto LABEL_170;
      case 313:
        v3 = (unsigned __int8)byte_ACD771;
        goto LABEL_170;
      case 275:
        v19 = &unk_6A12B8;
        if ( dword_6BE360 != 2 )
          v19 = &unk_6BE68C;
        v20 = *((_DWORD *)v19 + 2) >= (signed int)a3;
        goto LABEL_125;
      case 305:
        v21 = &unk_6A12B8;
        if ( dword_6BE360 != 2 )
          v21 = &unk_6BE68C;
        v20 = *((_DWORD *)v21 + 3) == (_DWORD)a3;
LABEL_125:
        LOBYTE(v6) = v20;
        return v6;
      case 245:
      case 246:
      case 247:
      case 248:
      case 249:
      case 250:
      case 251:
      case 252:
      case 253:
      case 254:
        v22 = dword_ACCCF0[2 * a2];
        if ( v22 | dword_ACCCEC[2 * a2] )
        {
          v23 = (unsigned int)dword_ACCCEC[2 * a2]
              + (signed __int64)((double)(460800 * (_DWORD)a3) * 0.03333333507180214);
          HIDWORD(v23) += v22;
          if ( v23 <= pParty_global->qword_00002C )
            goto LABEL_132;
        }
        goto LABEL_130;
      case 243:
        v3 = *(_DWORD *)(this + 6456);
        goto LABEL_170;
      case 242:
        v3 = 0;
        v24 = (signed int)&unk_ACDB98;
        do
        {
          v26 = v24;
          v25 = 138;
          do
          {
            switch ( *(_DWORD *)v26 )
            {
              case 0x1D6:
                ++v3;
                break;
              case 0x1D7:
                v3 += 3;
                break;
              case 0x1DD:
                v3 += 5;
                break;
            }
            v26 += 36;
            --v25;
          }
          while ( v25 );
          v24 += 6972;
        }
        while ( v24 < (signed int)&unk_AD4888 );
        goto LABEL_170;
      case 244:
        v17 = pParty_global->dword_000710 == (_DWORD)a3;
        goto LABEL_146;
      case 240:
        compile_error;//if ( dword_ACD6BC && dword_ACD8B8 >= 0 && (dword_ACD8B8 > 0 || (unsigned int)dword_ACD8B4 > 0) )
        if (1)
          goto LABEL_132;
        goto LABEL_130;
      case 241:
        LOBYTE(v6) = sub_476395(a3);
        return v6;
      case 232:
        return dword_72D694[19 * (_DWORD)a3] & 0x80;
      case 231:
        v13 = 0x80u >> ((signed __int16)a3 - 1) % 8;
        v14 = *(_BYTE *)((((signed __int16)a3 - 1) >> 3) + this + 6736);
        goto LABEL_108;
      case 315:
        v27 = 0;
        v28 = this + 6472;
        break;
      case 306:
        v3 = pParty_global->uNumGoldInBank;
        goto LABEL_170;
      case 224:
        v30 = Player_GetActualStrength(this);
        v29 = Player_GetBaseStrength(v4);
        goto LABEL_168;
      case 225:
        v30 = Player_GetActualIntelligence(this);
        v29 = Player_GetBaseIntelligence(v4);
        goto LABEL_168;
      case 226:
        v30 = Player_GetActualWillpower(this);
        v29 = Player_GetBaseWillpower(v4);
        goto LABEL_168;
      case 227:
        v30 = Player_GetActualEndurance(this);
        v29 = Player_GetBaseEndurance(v4);
        goto LABEL_168;
      case 228:
        v30 = Player_GetActualSpeed(this);
        v29 = Player_GetBaseSpeed(v4);
        goto LABEL_168;
      case 229:
        v30 = Player_GetActualAccuracy(this);
        v29 = Player_GetBaseAccuracy(v4);
        goto LABEL_168;
      case 230:
        v30 = Player_GetActualLuck((void *)this);
        v29 = Player_GetBaseLuck(v4);
LABEL_168:
        compile_error;//v9 = __SETO__(v30, v29);
        v8 = v30 - v29 < 0;
LABEL_169:
        if ( v8 ^ v9 )
          goto LABEL_170;
        goto LABEL_132;
      default:
        goto LABEL_170;
    }
    while ( !sub_48D6AA((void *)v4, v27) || *(void **)(v4 + 36 * *(_DWORD *)v28 + 496) != a3 )
    {
      ++v27;
      v28 += 4;
      if ( v27 >= 16 )
      {
LABEL_130:
        LOBYTE(v6) = 0;
        return v6;
      }
    }
    goto LABEL_132;
  }
  if ( a2 == 223 )
  {
    v13 = 0x80u >> ((signed __int16)((_WORD)a3 - 1) - 1) % 8;
    v14 = byte_ACD7B6[((signed __int16)((_WORD)a3 - 1) - 1) >> 3];
LABEL_108:
    if ( !((_BYTE)v13 & (unsigned __int8)v14) )
      goto LABEL_170;
    goto LABEL_109;
  }
  if ( a2 <= 38 )
  {
    if ( a2 != 38 )
    {
      switch ( a2 )
      {
        case 18:
          if ( (signed __int64)((double)pParty_global->qword_00002C * 0.234375) / 60 / 60 % 24 == (signed int)a3 )
            goto LABEL_132;
          goto LABEL_130;
        case 19:
          v5 = (unsigned int)((signed __int64)((double)pParty_global->qword_00002C * 0.234375) / 60 / 60) / 0x18 % 0x150 + 1;
          goto LABEL_9;
        case 20:
          v5 = (unsigned int)((signed __int64)((double)pParty_global->qword_00002C * 0.234375) / 60 / 60) / 0x18 % 7;
LABEL_9:
          LOBYTE(v6) = v5 == (_DWORD)a3;
          return v6;
        case 1:
          v7 = *(_BYTE *)(this + 184);
          goto LABEL_14;
        case 2:
          v7 = *(_BYTE *)(this + 185);
          goto LABEL_14;
        case 14:
          v7 = GetRaceByFace(this);
LABEL_14:
          if ( a3 == (void *)v7 )
            goto LABEL_132;
          goto LABEL_170;
        case 3:
          v3 = *(_DWORD *)(this + 6460);
          goto LABEL_170;
        case 4:
          v10 = Player_GetMaxHealth(this);
          compile_error;//v9 = __SETO__(*(_DWORD *)(v4 + 6460), v10);
          v8 = *(_DWORD *)(v4 + 6460) - v10 < 0;
          goto LABEL_169;
        case 5:
          v3 = *(_DWORD *)(this + 6464);
          goto LABEL_170;
        case 6:
          v11 = Player_GetMaxMana(this);
          compile_error;//v9 = __SETO__(*(_DWORD *)(v4 + 6464), v11);
          v8 = *(_DWORD *)(v4 + 6464) - v11 < 0;
          goto LABEL_169;
        case 7:
          v12 = sub_48E68F(this);
          goto LABEL_67;
        case 8:
          v3 = *(_WORD *)(this + 216);
          goto LABEL_170;
        case 9:
          v3 = *(_WORD *)(this + 218);
          goto LABEL_170;
        case 10:
          v3 = *(_WORD *)(this + 220);
          goto LABEL_170;
        case 11:
          v12 = Player_GetActualAge(this);
          goto LABEL_67;
        case 12:
          v13 = 0x80u >> ((signed __int16)a3 - 1) % 8;
          v14 = *(_BYTE *)((((signed __int16)a3 - 1) >> 3) + this + 338);
          goto LABEL_108;
        case 13:
          v3 = *(_DWORD *)(this + 160);
          goto LABEL_170;
        case 16:
          v13 = 0x80u >> ((signed __int16)a3 - 1) % 8;
          v14 = byte_ACD71D[((signed __int16)a3 - 1) >> 3];
          goto LABEL_108;
        case 17:
          v16 = 0;
          v15 = v4 + 532;
          break;
        case 21:
          v3 = pParty_global->uNumGold;
          goto LABEL_170;
        case 25:
          v3 = *(_WORD *)(this + 190);
          goto LABEL_170;
        case 26:
          v3 = *(_WORD *)(this + 194);
          goto LABEL_170;
        case 27:
          v3 = *(_WORD *)(this + 198);
          goto LABEL_170;
        case 28:
          v3 = *(_WORD *)(this + 202);
          goto LABEL_170;
        case 29:
          v3 = *(_WORD *)(this + 206);
          goto LABEL_170;
        case 30:
          v3 = *(_WORD *)(this + 210);
          goto LABEL_170;
        case 31:
          v3 = *(_WORD *)(this + 214);
          goto LABEL_170;
        case 32:
          v3 = *(_WORD *)(this + 188);
          goto LABEL_170;
        case 33:
          v3 = *(_WORD *)(this + 192);
          goto LABEL_170;
        case 34:
          v3 = *(_WORD *)(this + 196);
          goto LABEL_170;
        case 35:
          v3 = *(_WORD *)(this + 200);
          goto LABEL_170;
        case 36:
          v3 = *(_WORD *)(this + 204);
          goto LABEL_170;
        case 37:
          v3 = *(_WORD *)(this + 208);
          goto LABEL_170;
        case 23:
          v3 = pParty_global->uNumFood;
          goto LABEL_170;
        default:
          goto LABEL_170;
      }
      while ( *(void **)v15 != a3 )
      {
        ++v16;
        v15 += 36;
        if ( v16 >= 138 )
        {
          v17 = dword_AD470C == (_DWORD)a3;
LABEL_146:
          LOBYTE(v6) = v17;
          return v6;
        }
      }
LABEL_132:
      LOBYTE(v6) = 1;
      return v6;
    }
    v3 = *(_WORD *)(this + 212);
    goto LABEL_170;
  }
  if ( a2 <= 56 )
  {
    if ( a2 == 56 )
    {
      v3 = *(_WORD *)(this + 6014);
    }
    else
    {
      switch ( a2 )
      {
        case 46:
          v3 = *(_WORD *)(this + 6004);
          goto LABEL_170;
        case 47:
          v3 = *(_WORD *)(this + 6006);
          goto LABEL_170;
        case 48:
          v3 = *(_WORD *)(this + 6008);
          goto LABEL_170;
        case 49:
          v3 = *(_WORD *)(this + 6010);
          goto LABEL_170;
        case 50:
          v3 = *(_WORD *)(this + 6016);
          goto LABEL_170;
        case 51:
          v3 = *(_WORD *)(this + 6018);
          goto LABEL_170;
        case 52:
          v3 = *(_WORD *)(this + 6020);
          goto LABEL_170;
        case 53:
          v3 = *(_WORD *)(this + 6022);
          goto LABEL_170;
        case 54:
          v3 = *(_WORD *)(this + 6024);
          goto LABEL_170;
        case 39:
          v12 = Player_GetActualStrength(this);
          goto LABEL_67;
        case 40:
          v12 = Player_GetActualIntelligence(this);
          goto LABEL_67;
        case 41:
          v12 = Player_GetActualWillpower(this);
          goto LABEL_67;
        case 42:
          v12 = Player_GetActualEndurance(this);
          goto LABEL_67;
        case 43:
          v12 = Player_GetActualSpeed(this);
          goto LABEL_67;
        case 44:
          v12 = Player_GetActualAccuracy(this);
          goto LABEL_67;
        case 45:
          v12 = Player_GetActualLuck((void *)this);
LABEL_67:
          v3 = v12;
          break;
        default:
          goto LABEL_170;
      }
    }
    goto LABEL_170;
  }
  if ( a2 <= 97 )
  {
    if ( a2 != 97 )
    {
      if ( a2 <= 62 )
      {
        switch ( a2 )
        {
          case 62:
            v3 = *(_WORD *)(this + 6040);
            break;
          case 57:
            v3 = *(_WORD *)(this + 6026);
            break;
          case 58:
            v3 = *(_WORD *)(this + 6028);
            break;
          case 59:
            v3 = *(_WORD *)(this + 6030);
            break;
          case 60:
            v3 = *(_WORD *)(this + 6032);
            break;
          case 61:
            v3 = *(_WORD *)(this + 6038);
            break;
        }
        goto LABEL_170;
      }
      if ( a2 == 63 )
      {
        v3 = *(_WORD *)(this + 6042);
        goto LABEL_170;
      }
      if ( a2 == 64 )
      {
        v3 = *(_WORD *)(this + 6044);
        goto LABEL_170;
      }
      if ( a2 == 65 )
      {
        v3 = *(_WORD *)(this + 6046);
        goto LABEL_170;
      }
      if ( a2 == 67 )
      {
        v3 = *(_WORD *)(this + 6036);
        goto LABEL_170;
      }
      if ( a2 <= 67 || a2 > 95 )
        goto LABEL_170;
    }
LABEL_90:
    v18 = *(_WORD *)(this + 2 * a2 + 128);
    if ( (signed int)a3 <= 63 )
      v3 = v18 & 0x3F;
    else
      v3 = (unsigned int)a3 & v18;
    goto LABEL_170;
  }
  if ( a2 == 104 )
    goto LABEL_90;
  if ( a2 <= 104 )
    goto LABEL_170;
  if ( a2 > 121 )
  {
    if ( a2 != 122 )
    {
      if ( a2 > 122 )
      {
        if ( a2 <= 222 )
          v3 = (unsigned __int8)byte_5E4C15[a2];
      }
      goto LABEL_170;
    }
    v3 = sub_48E9F4((void *)this);
    if ( v3 != 18 )
    {
LABEL_170:
      LOBYTE(v6) = v3 >= (signed int)a3;
      return v6;
    }
LABEL_109:
    v3 = (int)a3;
    goto LABEL_170;
  }
  return *(_DWORD *)(this + 8 * a2 - 840);
}

//----- (0044A56A) --------------------------------------------------------
void __cdecl sub_44A56A()
{
  int v0; // edi@1
  _UNKNOWN *v1; // esi@2

  pParty_global->byte_00070A = 0;
  v0 = 0;
  if (pNPCStats->dword_017FC4 > 0)
  {
    v1 = pNPCStats->pNPCData2;
    do
    {
      if ( *((_BYTE *)v1 + 8) & 0x80 )
      {
       if (!array_AD4674[0].pNPCName || strcmp(*(const char **)v1, array_AD4674[0].pNPCName))
        {
         if (!array_AD4674[1].pNPCName || strcmp(*(const char **)v1, array_AD4674[1].pNPCName))
            ++pParty_global->byte_00070A;
        }
      }
      ++v0;
      v1 = (char *)v1 + 76;
    }
    while ( v0 < pNPCStats->dword_017FC4);
  }
}

//----- (0044A5CB) --------------------------------------------------------
void __thiscall sub_44A5CB(char *Dst, signed int a2, signed int a3)
{
  signed int v3; // ebx@1
  int v4; // edi@1
  int v5; // esi@1
  void *v6; // esi@13
  void *v7; // esi@14
  signed int v8; // eax@17
  char *v9; // ecx@17
  int v10; // eax@21
  signed int v11; // eax@30
  void *v12; // ecx@44
  int v13; // ecx@45
  void *v14; // ecx@49
  char v15; // al@106
  void *v16; // esi@106
  int v17; // eax@107
  void *v18; // ecx@112
  void *v19; // ecx@127
  int v20; // eax@127
  int v21; // eax@145
  char v22; // zf@146
  _UNKNOWN *v23; // ecx@148
  signed int v24; // eax@172
  int v25; // [sp-8h] [bp-3Ch]@84
  signed int v26; // [sp-4h] [bp-38h]@4
  int v27; // [sp-4h] [bp-38h]@84
  int v28; // [sp+Ch] [bp-28h]@52
  int v29; // [sp+20h] [bp-14h]@52
  char v30; // [sp+32h] [bp-2h]@1
  char v31; // [sp+33h] [bp-1h]@1

  v3 = 0;
  v30 = 0;
  v31 = 0;
  v5 = (int)Dst;
  v4 = 0;
  if ( Dst == (char *)pPlayers[1] )
  {
    v3 = 1;
    goto LABEL_8;
  }
  if ( Dst == (char *)pPlayers[2] )
  {
    v26 = 2;
  }
  else
  {
    if ( Dst != (char *)pPlayers[3] )
      goto LABEL_8;
    v26 = 3;
  }
  v3 = v26;
LABEL_8:
  if ( a2 > 223 )
  {
    if ( a2 <= 306 )
    {
      if ( a2 == 306 )
      {
        pParty_global->uNumGoldInBank = a3;
        return;
      }
      if ( a2 <= 254 )
      {
        if ( a2 >= 245 )
        {
          dword_ACCCEC[2 * a2] = pParty_global->qword_00002C;
          dword_ACCCF0[2 * a2] = HIDWORD(pParty_global->qword_00002C);
        }
        else
        {
          switch ( a2 )
          {
            case 231:
              sub_449B7E((int)(Dst + 6736), a3, 1);
              break;
            case 232:
              pParty_global->byte_000709 = 0;
              LOBYTE(dword_72D694[19 * a3]) |= 0x80u;
              sub_44A56A();
              struct_576FE8.dword_000044 = 1;
              break;
            case 243:
              *((_DWORD *)Dst + 1614) = a3;
              break;
          }
        }
        return;
      }
      if ( a2 < 255 )
        return;
      if ( a2 <= 274 )
      {
        dword_ACCDD4[2 * a2] = pParty_global->qword_00002C;
        dword_ACCDD8[2 * a2] = HIDWORD(pParty_global->qword_00002C);
      }
      else
      {
        if ( a2 == 275 )
        {
          v23 = &unk_6A12B8;
          if ( dword_6BE360 != 2 )
            v23 = &unk_6BE68C;
          *((_DWORD *)v23 + 2) = a3;
          if ( a3 > 10000 )
            *((_DWORD *)v23 + 2) = 10000;
          return;
        }
        if ( a2 <= 275
          || a2 > 304
          || (v21 = a2 - 276, pParty_global->array_00052C[2 * v21 + 1] | pParty_global->array_00052C[2 * v21])
          || (pParty_global->array_00052C[2 * (a2 - 276)] = pParty_global->qword_00002C,
              v22 = ((char *)(pStorylineText))[12 * v21] == 0,
              pParty_global->array_00052C[2 * (a2 - 276) + 1] = HIDWORD(pParty_global->qword_00002C),
              v22) )
          return;
        byte_507948 = 1;
      }
LABEL_172:
      v24 = 8 * v3 + 400;
      LOBYTE(v24) = (8 * v3 - 112) | 4;
      AudioPlayer_sub_4AA306(pAudioPlayer, 20001, v24, v4, -1, v4, v4, v4, v4);
      return;
    }
    if ( a2 != 307 )
    {
      switch ( a2 )
      {
        case 308:
          pParty_global->dword_000748 = a3;
          break;
        case 309:
          pParty_global->dword_000744 = a3;
          break;
        case 310:
          byte_ACD76E = a3;
          break;
        case 311:
          byte_ACD76F = a3;
          break;
        case 312:
          byte_ACD770 = a3;
          break;
        case 313:
          byte_ACD771 = a3;
          break;
      }
      return;
    }
    pParty_global->dword_00073C = a3;
LABEL_168:
    if ( v30 != 1 )
    {
LABEL_170:
      if ( v31 != 1 )
        return;
      v4 = 0;
      goto LABEL_172;
    }
LABEL_169:
    sub_4A89BD(pGame->class06_obj, 150, v3);
    goto LABEL_170;
  }
  if ( a2 == 223 )
  {
    if ( !((unsigned __int8)(0x80u >> ((signed __int16)a3 - 1) % 8) & (unsigned __int8)byte_ACD7B6[((signed __int16)a3
                                                                                                  - 1) >> 3]) )
    {
      if ( (&dword_723718)[8 * a3] )
      {
        v19 = (void *)pPlayers[v3];
        v30 = 1;
        sub_4948B1(v19, 96, 0);
        v20 = dword_72371C[2 * a3];
        byte_507949 = 1;
        dword_506568 = v20;
      }
    }
    sub_449B7E((int)byte_ACD7B6, a3, 1);
    v31 = 1;
    goto LABEL_168;
  }
  if ( a2 <= 39 )
  {
    if ( a2 != 39 )
    {
      switch ( a2 )
      {
        case 22:
          v6 = (void *)(rand() % a3 + 1);
          sub_492B70(v6);
          sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[500], v6);
          sub_44C175(&TmpBuf, 2);
          GameUI_DrawFoodAndGold();
          return;
        case 24:
          v7 = (void *)(rand() % a3 + 1);
          sub_492AD5(v7);
          sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[501], v7);
          sub_44C175(&TmpBuf, 2);
          GameUI_DrawFoodAndGold();
          goto LABEL_124;
        case 1:
          Dst[184] = a3;
          goto LABEL_124;
        case 2:
          Dst[185] = a3;
          if ( (_BYTE)a3 != 35 )
            goto LABEL_124;
          v8 = 0;
          v9 = Dst + 532;
          break;
        case 3:
          *((_DWORD *)Dst + 1615) = a3;
          goto LABEL_124;
        case 4:
          *((_DWORD *)Dst + 1615) = Player_GetMaxHealth((int)Dst);
          return;
        case 5:
          *((_DWORD *)Dst + 1616) = a3;
          goto LABEL_124;
        case 6:
          *((_DWORD *)Dst + 1616) = Player_GetMaxMana((int)Dst);
          return;
        case 8:
          *((_WORD *)Dst + 108) = (unsigned __int8)a3;
          goto LABEL_124;
        case 9:
          *((_WORD *)Dst + 109) = (unsigned __int8)a3;
          goto LABEL_124;
        case 10:
          *((_WORD *)Dst + 110) = (unsigned __int8)a3;
          goto LABEL_124;
        case 11:
          *((_WORD *)Dst + 111) = a3;
          return;
        case 12:
          if ( !((unsigned __int8)(0x80u >> ((signed __int16)a3 - 1) % 8) & *(_BYTE *)((((signed __int16)a3 - 1) >> 3)
                                                                                     + pPlayers[v3]
                                                                                     + 338)) )
          {
            if ( dword_723E80[2 * a3] )
            {
              v12 = (void *)pPlayers[v3];
              v30 = 1;
              v31 = 1;
              sub_4948B1(v12, 96, 0);
            }
          }
          v13 = v5 + 338;
          goto LABEL_51;
        case 13:
          *((_QWORD *)Dst + 20) = a3;
          goto LABEL_124;
        case 16:
          if ( !((unsigned __int8)(0x80u >> ((signed __int16)a3 - 1) % 8) & (unsigned __int8)byte_ACD71D[((signed __int16)a3 - 1) >> 3]) )
          {
            if ( (&dword_722F10)[4 * a3] )
            {
              v14 = (void *)pPlayers[v3];
              byte_50794A = 1;
              v30 = 1;
              v31 = 1;
              sub_4948B1(v14, 93, 0);
            }
          }
          v13 = (int)byte_ACD71D;
LABEL_51:
          sub_449B7E(v13, a3, 1);
          goto LABEL_168;
        case 17:
          sub_402F07((int)&v28);
          sub_402F07((int)&v28);
          v28 = a3;
          v29 = 1;
          sub_4936E1(pParty_global, &v28);
          if ( a3 >= 500 )
          {
            if ( a3 <= 528 )
              pParty_global->byte_0005C6[a3] = 1;
          }
          return;
        case 21:
          sub_492B70((void *)a3);
          return;
        case 32:
          *((_WORD *)Dst + 94) = (unsigned __int8)a3;
          goto LABEL_84;
        case 33:
          *((_WORD *)Dst + 96) = (unsigned __int8)a3;
          goto LABEL_84;
        case 34:
          *((_WORD *)Dst + 98) = (unsigned __int8)a3;
          goto LABEL_84;
        case 35:
          *((_WORD *)Dst + 100) = (unsigned __int8)a3;
          goto LABEL_84;
        case 36:
          *((_WORD *)Dst + 102) = (unsigned __int8)a3;
          goto LABEL_84;
        case 37:
          *((_WORD *)Dst + 104) = (unsigned __int8)a3;
          goto LABEL_84;
        case 38:
          *((_WORD *)Dst + 106) = (unsigned __int8)a3;
          goto LABEL_84;
        case 23:
          sub_492AD5((void *)a3);
          goto LABEL_124;
        case 25:
          goto LABEL_64;
        case 26:
          goto LABEL_68;
        case 27:
          goto LABEL_69;
        case 28:
          goto LABEL_70;
        case 29:
          goto LABEL_71;
        case 30:
          goto LABEL_72;
        case 31:
          goto LABEL_73;
        default:
          return;
      }
      while ( *(_DWORD *)v9 != 615 )
      {
        ++v8;
        v9 += 36;
        if ( v8 >= 138 )
          goto LABEL_22;
      }
      v10 = v5 + 36 * v8;
      *(_DWORD *)(v10 + 532) = 601;
      *(_BYTE *)(v10 + 558) = v3 + 1;
LABEL_22:
      if ( *(_WORD *)(v5 + 6004) < 20 )
        *(_WORD *)(v5 + 6004) = 20;
      if ( *(_WORD *)(v5 + 6006) < 20 )
        *(_WORD *)(v5 + 6006) = 20;
      if ( *(_WORD *)(v5 + 6008) < 20 )
        *(_WORD *)(v5 + 6008) = 20;
      if ( *(_WORD *)(v5 + 6010) < 20 )
        *(_WORD *)(v5 + 6010) = 20;
      *(_WORD *)(v5 + 6018) = 200;
      *(_WORD *)(v5 + 6020) = 200;
      v11 = Player_GetVoiceSex(v5);
      *(_DWORD *)(v5 + 6436) = *(_DWORD *)(v5 + 6432);
      *(_DWORD *)(v5 + 6440) = *(_BYTE *)(v5 + 186);
      if ( v11 )
      {
        *(_BYTE *)(v5 + 186) = 21;
        *(_DWORD *)(v5 + 6432) = 21;
      }
      else
      {
        *(_BYTE *)(v5 + 186) = 20;
        *(_DWORD *)(v5 + 6432) = 20;
      }
      sub_491DE7(v3, *(_BYTE *)(v5 + 186));
      goto LABEL_124;
    }
LABEL_64:
    *((_WORD *)Dst + 95) = (unsigned __int8)a3;
LABEL_111:
    v27 = 0;
    v25 = 91;
LABEL_112:
    v18 = (void *)pPlayers[v3];
    v31 = 1;
    sub_4948B1(v18, v25, v27);
    goto LABEL_169;
  }
  if ( a2 <= 57 )
  {
    if ( a2 == 57 )
    {
      *((_WORD *)Dst + 3013) = (unsigned __int8)a3;
      goto LABEL_111;
    }
    switch ( a2 )
    {
      case 40:
LABEL_68:
        *((_WORD *)Dst + 97) = (unsigned __int8)a3;
        goto LABEL_111;
      case 41:
LABEL_69:
        *((_WORD *)Dst + 99) = (unsigned __int8)a3;
        goto LABEL_111;
      case 42:
LABEL_70:
        *((_WORD *)Dst + 101) = (unsigned __int8)a3;
        goto LABEL_111;
      case 43:
LABEL_71:
        *((_WORD *)Dst + 103) = (unsigned __int8)a3;
        goto LABEL_111;
      case 44:
LABEL_72:
        *((_WORD *)Dst + 105) = (unsigned __int8)a3;
        goto LABEL_111;
      case 45:
LABEL_73:
        *((_WORD *)Dst + 107) = (unsigned __int8)a3;
        goto LABEL_111;
      case 46:
        *((_WORD *)Dst + 3002) = (unsigned __int8)a3;
        goto LABEL_84;
      case 47:
        *((_WORD *)Dst + 3003) = (unsigned __int8)a3;
        goto LABEL_84;
      case 48:
        *((_WORD *)Dst + 3004) = (unsigned __int8)a3;
        goto LABEL_84;
      case 49:
        *((_WORD *)Dst + 3005) = (unsigned __int8)a3;
        goto LABEL_84;
      case 50:
        *((_WORD *)Dst + 3008) = (unsigned __int8)a3;
        goto LABEL_84;
      case 51:
        *((_WORD *)Dst + 3009) = (unsigned __int8)a3;
        goto LABEL_84;
      case 52:
        *((_WORD *)Dst + 3010) = (unsigned __int8)a3;
        goto LABEL_84;
      case 53:
        *((_WORD *)Dst + 3011) = (unsigned __int8)a3;
        goto LABEL_84;
      case 54:
        *((_WORD *)Dst + 3012) = (unsigned __int8)a3;
        goto LABEL_84;
      case 56:
        *((_WORD *)Dst + 3007) = (unsigned __int8)a3;
LABEL_84:
        v27 = 0;
        v25 = 92;
        goto LABEL_112;
      default:
        return;
    }
    return;
  }
  if ( a2 > 97 )
  {
    if ( a2 != 104 )
    {
      if ( a2 <= 104 )
        return;
      if ( a2 <= 121 )
      {
        Player_sub_492D65(Dst, a2 - 105, 1);
      }
      else
      {
        if ( a2 != 122 )
        {
          if ( a2 > 122 )
          {
            if ( a2 <= 222 )
              byte_5E4C15[a2] = a3;
          }
          return;
        }
        memset(Dst, 0, 0xA0u);
      }
LABEL_124:
      v31 = 1;
      goto LABEL_169;
    }
LABEL_106:
    v16 = &Dst[2 * a2 + 128];
    v15 = *(_BYTE *)v16;
    if ( a3 <= 63 )
      v17 = v15 & 0x3F | 0x3F;
    else
      LOWORD(v17) = (unsigned __int8)(a3 | v15 & 0xC0);
    *(_WORD *)v16 = v17;
    goto LABEL_124;
  }
  if ( a2 == 97 )
    goto LABEL_106;
  if ( a2 <= 63 )
  {
    switch ( a2 )
    {
      case 63:
        *((_WORD *)Dst + 3021) = (unsigned __int8)a3;
        break;
      case 58:
        *((_WORD *)Dst + 3014) = (unsigned __int8)a3;
        break;
      case 59:
        *((_WORD *)Dst + 3015) = (unsigned __int8)a3;
        break;
      case 60:
        *((_WORD *)Dst + 3016) = (unsigned __int8)a3;
        break;
      case 61:
        *((_WORD *)Dst + 3019) = (unsigned __int8)a3;
        break;
      default:
        if ( a2 != 62 )
          return;
        *((_WORD *)Dst + 3020) = (unsigned __int8)a3;
        break;
    }
    goto LABEL_111;
  }
  if ( a2 == 64 )
  {
    *((_WORD *)Dst + 3022) = (unsigned __int8)a3;
    goto LABEL_111;
  }
  if ( a2 == 65 )
  {
    *((_WORD *)Dst + 3023) = (unsigned __int8)a3;
    goto LABEL_111;
  }
  if ( a2 == 67 )
  {
    *((_WORD *)Dst + 3018) = (unsigned __int8)a3;
    goto LABEL_111;
  }
  if ( a2 > 67 && a2 <= 95 )
    goto LABEL_106;
}

//----- (0044AFFB) --------------------------------------------------------
void __thiscall sub_44AFFB(char *Dst, signed int a2, signed int a3)
{
  char v3; // bl@1
  signed int v4; // edi@1
  int v5; // esi@1
  int v6; // eax@15
  void *v7; // esi@18
  char *v8; // ebx@21
  signed int v9; // eax@22
  signed int v10; // eax@24
  int v11; // eax@27
  char *v12; // esi@28
  int v13; // ecx@34
  void *v14; // ecx@36
  int v15; // ecx@37
  unsigned __int8 v16; // cf@38
  void *v17; // ecx@42
  char *v18; // esi@53
  char *v19; // esi@62
  __int16 v20; // dx@107
  int v21; // ecx@107
  void *v22; // esi@107
  void *v23; // ecx@132
  int v24; // eax@132
  int v25; // eax@150
  char v26; // zf@151
  _UNKNOWN *v27; // eax@153
  signed int v28; // eax@176
  int v29; // [sp-8h] [bp-40h]@84
  signed int v30; // [sp-4h] [bp-3Ch]@4
  int v31; // [sp-4h] [bp-3Ch]@84
  int v32; // [sp+Ch] [bp-2Ch]@45
  int v33; // [sp+1Ch] [bp-1Ch]@50
  int v34; // [sp+20h] [bp-18h]@45
  char v35; // [sp+25h] [bp-13h]@50
  unsigned int v36; // [sp+30h] [bp-8h]@34
  char v37; // [sp+37h] [bp-1h]@1

  v3 = 0;
  v37 = 0;
  v5 = (int)Dst;
  v4 = 0;
  if ( Dst == (char *)pPlayers[1] )
  {
    v4 = 1;
    goto LABEL_8;
  }
  if ( Dst == (char *)pPlayers[2] )
  {
    v30 = 2;
  }
  else
  {
    if ( Dst != (char *)pPlayers[3] )
      goto LABEL_8;
    v30 = 3;
  }
  v4 = v30;
LABEL_8:
  if ( a2 > 223 )
  {
    if ( a2 <= 306 )
    {
      if ( a2 == 306 )
      {
        pParty_global->uNumGoldInBank += a3;
        return;
      }
      if ( a2 <= 254 )
      {
        if ( a2 >= 245 )
        {
          dword_ACCCEC[2 * a2] = pParty_global->qword_00002C;
          dword_ACCCF0[2 * a2] = HIDWORD(pParty_global->qword_00002C);
        }
        else
        {
          switch ( a2 )
          {
            case 231:
              sub_449B7E((int)(Dst + 6736), a3, 1);
              break;
            case 232:
              pParty_global->byte_000709 = 0;
              LOBYTE(dword_72D694[19 * a3]) |= 0x80u;
              sub_44A56A();
              struct_576FE8.dword_000044 = 1;
              break;
            case 243:
              *((_DWORD *)Dst + 1614) += a3;
              break;
          }
        }
        return;
      }
      if ( a2 < 255 )
        return;
      if ( a2 <= 274 )
      {
        dword_ACCDD4[2 * a2] = pParty_global->qword_00002C;
        dword_ACCDD8[2 * a2] = HIDWORD(pParty_global->qword_00002C);
      }
      else
      {
        if ( a2 == 275 )
        {
          v27 = &unk_6A12B8;
          if ( dword_6BE360 != 2 )
            v27 = &unk_6BE68C;
          *((_DWORD *)v27 + 2) += a3;
          if ( *((_DWORD *)v27 + 2) > 10000 )
            *((_DWORD *)v27 + 2) = 10000;
          return;
        }
        if ( a2 <= 275
          || a2 > 304
          || (v25 = a2 - 276, pParty_global->array_00052C[2 * v25 + 1] | pParty_global->array_00052C[2 * v25])
          || (pParty_global->array_00052C[2 * (a2 - 276)] = pParty_global->qword_00002C,
              v26 = ((char *)(pStorylineText))[12 * v25] == 0,
              pParty_global->array_00052C[2 * (a2 - 276) + 1] = HIDWORD(pParty_global->qword_00002C),
              v26) )
          return;
        byte_507948 = 1;
      }
LABEL_176:
      v28 = 8 * v4 + 400;
      LOBYTE(v28) = (8 * v4 - 112) | 4;
      AudioPlayer_sub_4AA306(pAudioPlayer, 20001, v28, 0, -1, 0, 0, 0, 0);
      return;
    }
    if ( a2 != 307 )
    {
      switch ( a2 )
      {
        case 308:
          pParty_global->dword_000748 += a3;
          break;
        case 309:
          pParty_global->dword_000744 += a3;
          break;
        case 310:
          byte_ACD76E += a3;
          break;
        case 311:
          byte_ACD76F += a3;
          break;
        case 312:
          byte_ACD770 += a3;
          break;
        case 313:
          byte_ACD771 += a3;
          break;
      }
      return;
    }
    pParty_global->dword_00073C += a3;
LABEL_173:
    if ( v37 != 1 )
      goto LABEL_175;
    goto LABEL_174;
  }
  if ( a2 == 223 )
  {
    if ( !((unsigned __int8)(0x80u >> ((signed __int16)a3 - 1) % 8) & (unsigned __int8)byte_ACD7B6[((signed __int16)a3
                                                                                                  - 1) >> 3]) )
    {
      if ( (&dword_723718)[8 * a3] )
      {
        v23 = (void *)pPlayers[v4];
        v37 = 1;
        sub_4948B1(v23, 96, 0);
        v24 = dword_72371C[2 * a3];
        byte_507949 = 1;
        dword_506568 = v24;
      }
    }
    sub_449B7E((int)byte_ACD7B6, a3, 1);
    v3 = 1;
    goto LABEL_173;
  }
  if ( a2 <= 39 )
  {
    if ( a2 != 39 )
    {
      switch ( a2 )
      {
        case 22:
          if ( !a3 )
            a3 = 1;
          v6 = rand();
          sub_420C05(v6 % a3 + 1, 1);
          GameUI_DrawFoodAndGold();
          return;
        case 24:
          if ( !a3 )
            a3 = 1;
          v7 = (void *)(rand() % a3 + 1);
          sub_492B42(v7);
          sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[502], v7);
          sub_44C175(&TmpBuf, 2);
          GameUI_DrawFoodAndGold();
          goto LABEL_176;
        case 1:
          Dst[184] = a3;
          goto LABEL_129;
        case 2:
          Dst[185] = a3;
          goto LABEL_129;
        case 3:
          v8 = Dst + 6460;
          *(_DWORD *)v8 += a3;
          if ( *((_DWORD *)Dst + 1615) <= Player_GetMaxHealth((int)Dst) )
            goto LABEL_129;
          v9 = Player_GetMaxHealth(v5);
          goto LABEL_23;
        case 4:
          v10 = Player_GetMaxHealth((int)Dst);
          *(_BYTE *)(v5 + 6809) = 0;
          *(_BYTE *)(v5 + 6808) = 0;
          *(_DWORD *)(v5 + 6460) = v10;
          return;
        case 5:
          v8 = Dst + 6464;
          *(_DWORD *)v8 += a3;
          if ( *((_DWORD *)Dst + 1616) > Player_GetMaxMana((int)Dst) )
          {
            v9 = Player_GetMaxMana(v5);
LABEL_23:
            *(_DWORD *)v8 = v9;
          }
          goto LABEL_129;
        case 6:
          v11 = Player_GetMaxMana((int)Dst);
          *(_BYTE *)(v5 + 6811) = 0;
          *(_BYTE *)(v5 + 6810) = 0;
          *(_DWORD *)(v5 + 6464) = v11;
          return;
        case 8:
          v12 = Dst + 216;
          goto LABEL_29;
        case 9:
          v12 = Dst + 218;
          goto LABEL_29;
        case 10:
          v12 = Dst + 220;
LABEL_29:
          *(_WORD *)v12 += a3;
          if ( *(_WORD *)v12 > 255 )
            *(_WORD *)v12 = 255;
          goto LABEL_129;
        case 11:
          *((_WORD *)Dst + 111) += a3;
          return;
        case 12:
          v13 = pPlayers[v4];
          v36 = 0x80u >> ((signed __int16)a3 - 1) % 8;
          if ( !((unsigned __int8)(0x80u >> ((signed __int16)a3 - 1) % 8) & *(_BYTE *)((((signed __int16)a3 - 1) >> 3)
                                                                                     + v13
                                                                                     + 338)) )
          {
            if ( dword_723E80[2 * a3] )
            {
              v14 = (void *)pPlayers[v4];
              v37 = 1;
              v3 = 1;
              sub_4948B1(v14, 96, 0);
            }
          }
          v15 = v5 + 338;
          goto LABEL_44;
        case 13:
          v16 = a3 >= (unsigned int)-*((_DWORD *)Dst + 40);
          *((_DWORD *)Dst + 40) += a3;
          *((_DWORD *)Dst + 41) += ((unsigned __int64)a3 >> 32) + v16;
          if ( *((_QWORD *)Dst + 20) > 4000000000i64 )
          {
            *((_DWORD *)Dst + 41) = 0;
            *((_DWORD *)Dst + 40) = -294967296;
          }
          goto LABEL_129;
        case 16:
          if ( !((unsigned __int8)(0x80u >> ((signed __int16)a3 - 1) % 8) & (unsigned __int8)byte_ACD71D[((signed __int16)a3 - 1) >> 3]) )
          {
            if ( (&dword_722F10)[4 * a3] )
            {
              v17 = (void *)pPlayers[v4];
              byte_50794A = 1;
              v37 = 1;
              v3 = 1;
              sub_4948B1(v17, 93, 0);
            }
          }
          v15 = (int)byte_ACD71D;
LABEL_44:
          sub_449B7E(v15, a3, 1);
          goto LABEL_173;
        case 17:
          sub_402F07((int)&v32);
          sub_402F07((int)&v32);
          v34 = 1;
          v32 = a3;
          if ( a3 >= 500 )
          {
            if ( a3 <= 528 )
              pParty_global->byte_0005C6[a3] = 1;
          }
          if ( a3 >= 135 )
          {
            if ( a3 <= 159 )
            {
              v33 = rand() % 6 + (unsigned __int8)byte_5D2A00[48 * v32 + 4] + 1;
              v35 = v33;
            }
          }
          sub_4936E1(pParty_global, &v32);
          return;
        case 21:
          sub_420C05(a3, 1);
          return;
        case 32:
          v18 = Dst + 188;
          goto LABEL_82;
        case 33:
          v18 = Dst + 192;
          goto LABEL_82;
        case 34:
          v18 = Dst + 196;
          goto LABEL_82;
        case 35:
          v18 = Dst + 200;
          goto LABEL_82;
        case 36:
          v18 = Dst + 204;
          goto LABEL_82;
        case 37:
          v18 = Dst + 208;
          goto LABEL_82;
        case 38:
          v18 = Dst + 212;
          goto LABEL_82;
        case 23:
          sub_492B42((void *)a3);
          sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[502], a3);
          sub_44C175(&TmpBuf, 2);
          if ( (unsigned int)pParty_global->uNumFood > 0xFFFF )
            sub_492AD5((void *)0xFFFF);
          goto LABEL_176;
        case 25:
          goto LABEL_62;
        case 26:
          goto LABEL_66;
        case 27:
          goto LABEL_67;
        case 28:
          goto LABEL_68;
        case 29:
          goto LABEL_69;
        case 30:
          goto LABEL_70;
        case 31:
          goto LABEL_71;
        default:
          return;
      }
      return;
    }
LABEL_62:
    v19 = Dst + 190;
    goto LABEL_113;
  }
  if ( a2 <= 57 )
  {
    if ( a2 != 57 )
    {
      switch ( a2 )
      {
        case 40:
LABEL_66:
          v19 = Dst + 194;
          goto LABEL_113;
        case 41:
LABEL_67:
          v19 = Dst + 198;
          goto LABEL_113;
        case 42:
LABEL_68:
          v19 = Dst + 202;
          goto LABEL_113;
        case 43:
LABEL_69:
          v19 = Dst + 206;
          goto LABEL_113;
        case 44:
LABEL_70:
          v19 = Dst + 210;
          goto LABEL_113;
        case 45:
LABEL_71:
          v19 = Dst + 214;
          goto LABEL_113;
        case 46:
          v18 = Dst + 6004;
          goto LABEL_82;
        case 47:
          v18 = Dst + 6006;
          goto LABEL_82;
        case 48:
          v18 = Dst + 6008;
          goto LABEL_82;
        case 49:
          v18 = Dst + 6010;
          goto LABEL_82;
        case 50:
          v18 = Dst + 6016;
          goto LABEL_82;
        case 51:
          v18 = Dst + 6018;
          goto LABEL_82;
        case 52:
          v18 = Dst + 6020;
          goto LABEL_82;
        case 53:
          v18 = Dst + 6022;
          goto LABEL_82;
        case 54:
          v18 = Dst + 6024;
          goto LABEL_82;
        case 56:
          v18 = Dst + 6014;
LABEL_82:
          *(_WORD *)v18 += a3;
          if ( *(_WORD *)v18 > 255 )
            *(_WORD *)v18 = 255;
          v31 = 0;
          v29 = 92;
          goto LABEL_116;
        default:
          return;
      }
      return;
    }
    v19 = Dst + 6026;
LABEL_113:
    *(_WORD *)v19 += a3;
    if ( *(_WORD *)v19 > 255 )
      *(_WORD *)v19 = 255;
    v31 = 0;
    v29 = 91;
LABEL_116:
    v3 = 1;
    sub_4948B1((void *)pPlayers[v4], v29, v31);
    goto LABEL_174;
  }
  if ( a2 > 97 )
  {
    if ( a2 == 104 )
    {
LABEL_106:
      if ( a3 <= 63 )
      {
        *(_WORD *)&Dst[2 * a2 + 128] = (unsigned __int8)a3 | Dst[2 * a2 + 128] & 0x3F;
      }
      else
      {
        v22 = &Dst[2 * a2 + 128];
        v20 = *(_WORD *)v22;
        v21 = (unsigned __int8)a3 + (v20 & 0x3F);
        if ( v21 > 60 )
          LOWORD(v21) = 60;
        LOBYTE(v20) = v20 & 0xC0;
        *(_WORD *)v22 = v21 | v20;
      }
      goto LABEL_129;
    }
    if ( a2 <= 104 )
      return;
    if ( a2 <= 121 )
    {
      Player_sub_492D65(Dst, a2 - 105, 0);
    }
    else
    {
      if ( a2 != 122 )
      {
        if ( a2 > 122 )
        {
          if ( a2 <= 222 )
          {
            if ( (unsigned __int8)a3 + (unsigned __int8)byte_5E4C15[a2] <= 255 )
              byte_5E4C15[a2] += a3;
            else
              byte_5E4C15[a2] = -1;
          }
        }
        return;
      }
      memset(Dst, 0, 0xA0u);
    }
LABEL_129:
    v3 = 1;
LABEL_174:
    sub_4A89BD(pGame->class06_obj, 151, v4);
LABEL_175:
    if ( v3 != 1 )
      return;
    goto LABEL_176;
  }
  if ( a2 == 97 )
    goto LABEL_106;
  if ( a2 <= 63 )
  {
    switch ( a2 )
    {
      case 63:
        v19 = Dst + 6042;
        break;
      case 58:
        v19 = Dst + 6028;
        break;
      case 59:
        v19 = Dst + 6030;
        break;
      case 60:
        v19 = Dst + 6032;
        break;
      case 61:
        v19 = Dst + 6038;
        break;
      default:
        if ( a2 != 62 )
          return;
        v19 = Dst + 6040;
        break;
    }
    goto LABEL_113;
  }
  if ( a2 == 64 )
  {
    v19 = Dst + 6044;
    goto LABEL_113;
  }
  if ( a2 == 65 )
  {
    v19 = Dst + 6046;
    goto LABEL_113;
  }
  if ( a2 == 67 )
  {
    v19 = Dst + 6036;
    goto LABEL_113;
  }
  if ( a2 > 67 && a2 <= 95 )
    goto LABEL_106;
}

//----- (0044B9C4) --------------------------------------------------------
void __thiscall sub_44B9C4(int this, signed int a2, signed int a3)
{
  int v3; // ebx@1
  signed int v4; // esi@1
  signed int v5; // eax@8
  unsigned int v6; // esi@11
  int v7; // edi@14
  signed int v8; // eax@17
  int v9; // eax@20
  char v10; // sf@20
  int v11; // ecx@26
  int v12; // ecx@27
  __int64 v13; // qax@27
  unsigned __int8 v14; // cf@27
  int v15; // edx@29
  _UNKNOWN *v16; // eax@90
  int v17; // ecx@94
  int v18; // edx@97
  signed int v19; // esi@97
  int v20; // ecx@98
  int v21; // eax@100
  int v22; // edx@112
  int v23; // [sp-8h] [bp-14h]@45
  signed int v24; // [sp-4h] [bp-10h]@4
  int v25; // [sp-4h] [bp-10h]@45

  v3 = 0;
  v4 = 0;
  if ( this == pPlayers[1] )
  {
    v4 = 1;
    goto LABEL_8;
  }
  if ( this == pPlayers[2] )
  {
    v24 = 2;
  }
  else
  {
    if ( this != pPlayers[3] )
      goto LABEL_8;
    v24 = 3;
  }
  v4 = v24;
LABEL_8:
  v5 = a2;
  if ( a2 > 222 )
  {
    if ( a2 <= 307 )
    {
      if ( a2 == 307 )
      {
        pParty_global->dword_00073C -= a3;
        return;
      }
      if ( a2 == 223 )
      {
        v11 = (int)byte_ACD7B6;
        v22 = a3 - 1;
      }
      else
      {
        if ( a2 != 231 )
        {
          switch ( a2 )
          {
            case 232:
              a2 = 0;
              sub_445B2C(dword_591090, (int)&a2);
              dword_5B65CC = 0;
              if ( a2 == a3 )
              {
                dword_5B65CC = a3;
              }
              else
              {
                pParty_global->byte_000709 = 0;
                LOBYTE(dword_72D694[19 * a3]) &= 0x7Fu;
                sub_44A56A();
                struct_576FE8.dword_000044 = 1;
              }
              break;
            case 241:
              v19 = a3;
              v18 = 0;
              if (pNPCStats->dword_017FC4 > 0)
              {
                v20 = (int)dword_72D694;
                do
                {
                  if ( *(_DWORD *)(v20 + 16) == v19 )
                  {
                    v21 = *(_DWORD *)v20;
                    if ( (char)*(_DWORD *)v20 < 0 )
                    {
                      LOBYTE(v21) = v21 & 0x7F;
                      *(_DWORD *)v20 = v21;
                    }
                  }
                  ++v18;
                  v20 += 76;
                }
                while ( v18 < pNPCStats->dword_017FC4);
              }
              if (array_AD4674[0].dword_000018 == v19 )
                memset(&array_AD4674[0], 0, sizeof(struct NPCData));
              if (array_AD4674[1].dword_000018 == v19 )
                memset(&array_AD4674[1], 0, sizeof(struct NPCData));
              pParty_global->byte_000709 = 0;
              sub_44A56A();
              break;
            case 243:
              v17 = this + 6456;
              if ( (unsigned int)a3 <= *(_DWORD *)v17 )
                *(_DWORD *)v17 -= a3;
              else
                *(_DWORD *)v17 = 0;
              break;
            case 275:
              v16 = &unk_6A12B8;
              if ( dword_6BE360 != 2 )
                v16 = &unk_6BE68C;
              *((_DWORD *)v16 + 2) -= a3;
              if ( *((_DWORD *)v16 + 2) < -10000 )
                *((_DWORD *)v16 + 2) = -10000;
              break;
            case 306:
              if ((unsigned int)a3 <= pParty_global->uNumGoldInBank)
                pParty_global->uNumGoldInBank -= a3;
              else
LABEL_88:
                dword_5B65C4 = 1;
              break;
          }
          return;
        }
        v11 = this + 6736;
LABEL_112:
        LOWORD(v22) = a3;
      }
      sub_449B7E(v11, v22, 0);
      return;
    }
    switch ( a2 )
    {
      case 308:
        pParty_global->dword_000748 -= a3;
        break;
      case 309:
        pParty_global->dword_000744 -= a3;
        break;
      case 310:
        byte_ACD76E -= a3;
        break;
      case 311:
        byte_ACD76F -= a3;
        break;
      case 312:
        byte_ACD770 -= a3;
        break;
      case 313:
        byte_ACD771 -= a3;
        break;
    }
  }
  else
  {
    if ( a2 >= 123 )
    {
      byte_5E4C15[a2] -= a3;
    }
    else
    {
      switch ( a2 )
      {
        case 22:
          v6 = rand() % a3 + 1;
          if ( v6 > pParty_global->uNumGold )
            v6 = pParty_global->uNumGold;
          sub_492BB6(v6);
          sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[503], v6);
          sub_44C175(&TmpBuf, 2);
          GameUI_DrawFoodAndGold();
          return;
        case 24:
          v7 = rand() % a3 + 1;
          if ( v7 > (unsigned int)pParty_global->uNumFood )
            v7 = pParty_global->uNumFood;
          sub_492B03((void *)v7);
          sprintfex(&TmpBuf, pGlobalTXT_LocalizationStrings[504], v7);
          sub_44C175(&TmpBuf, 2);
          GameUI_DrawFoodAndGold();
          goto LABEL_17;
        default:
          return;
        case 3:
          sub_48DC1E(this, a3, 4);
          goto LABEL_17;
        case 5:
          v9 = this + 6464;
          v10 = *(_DWORD *)(this + 6464) - a3 < 0;
          *(_DWORD *)v9 -= a3;
          if ( v10 )
            *(_DWORD *)v9 = 0;
          goto LABEL_17;
        case 8:
          *(_WORD *)(this + 216) -= (unsigned __int8)a3;
          goto LABEL_17;
        case 9:
          *(_WORD *)(this + 218) -= (unsigned __int8)a3;
          goto LABEL_17;
        case 10:
          *(_WORD *)(this + 220) -= (unsigned __int8)a3;
          goto LABEL_17;
        case 11:
          *(_WORD *)(this + 222) -= a3;
          return;
        case 12:
          v11 = this + 338;
          goto LABEL_112;
        case 13:
          v12 = this + 160;
          v13 = a3;
          v14 = *(_DWORD *)v12 < (unsigned int)a3;
          *(_DWORD *)v12 -= a3;
          *(_DWORD *)(v12 + 4) -= v14 + HIDWORD(v13);
          goto LABEL_17;
        case 16:
          sub_449B7E((int)byte_ACD71D, a3, 0);
          sub_4948B1((void *)pPlayers[v4], 96, 0);
          return;
        case 17:
          v15 = this + 5500;
          break;
        case 21:
          if ( a3 > (unsigned int)pParty_global->uNumGold )
            goto LABEL_88;
          sub_492BB6(a3);
          return;
        case 25:
        case 39:
          *(_WORD *)(this + 190) -= a3;
          goto LABEL_72;
        case 26:
        case 40:
          *(_WORD *)(this + 194) -= a3;
          goto LABEL_72;
        case 27:
        case 41:
          *(_WORD *)(this + 198) -= a3;
          goto LABEL_72;
        case 28:
        case 42:
          *(_WORD *)(this + 202) -= a3;
          goto LABEL_72;
        case 29:
        case 43:
          *(_WORD *)(this + 206) -= a3;
          goto LABEL_72;
        case 30:
        case 44:
          *(_WORD *)(this + 210) -= a3;
          goto LABEL_72;
        case 31:
        case 45:
          *(_WORD *)(this + 214) -= a3;
          goto LABEL_72;
        case 32:
          *(_WORD *)(this + 188) -= a3;
          goto LABEL_45;
        case 33:
          *(_WORD *)(this + 192) -= a3;
          goto LABEL_45;
        case 34:
          *(_WORD *)(this + 196) -= a3;
          goto LABEL_45;
        case 35:
          *(_WORD *)(this + 200) -= a3;
          goto LABEL_45;
        case 36:
          *(_WORD *)(this + 204) -= a3;
          goto LABEL_45;
        case 37:
          *(_WORD *)(this + 208) -= a3;
          goto LABEL_45;
        case 38:
          *(_WORD *)(this + 212) -= a3;
          goto LABEL_45;
        case 46:
          *(_WORD *)(this + 6004) -= a3;
          goto LABEL_45;
        case 47:
          *(_WORD *)(this + 6006) -= a3;
          goto LABEL_45;
        case 48:
          *(_WORD *)(this + 6008) -= a3;
          goto LABEL_45;
        case 49:
          *(_WORD *)(this + 6010) -= a3;
          goto LABEL_45;
        case 50:
          *(_WORD *)(this + 6016) -= a3;
          goto LABEL_45;
        case 51:
          *(_WORD *)(this + 6018) -= a3;
          goto LABEL_45;
        case 52:
          *(_WORD *)(this + 6020) -= a3;
          goto LABEL_45;
        case 53:
          *(_WORD *)(this + 6022) -= a3;
          goto LABEL_45;
        case 54:
          *(_WORD *)(this + 6024) -= a3;
          goto LABEL_45;
        case 56:
          *(_WORD *)(this + 6014) -= a3;
          goto LABEL_45;
        case 57:
          *(_WORD *)(this + 6026) -= a3;
          goto LABEL_45;
        case 58:
          *(_WORD *)(this + 6028) -= a3;
LABEL_45:
          v25 = 0;
          v23 = 92;
          goto LABEL_73;
        case 59:
          *(_WORD *)(this + 6030) -= a3;
          goto LABEL_72;
        case 60:
          *(_WORD *)(this + 6032) -= a3;
          goto LABEL_72;
        case 61:
          *(_WORD *)(this + 6038) -= a3;
          goto LABEL_72;
        case 62:
          *(_WORD *)(this + 6040) -= a3;
          goto LABEL_72;
        case 63:
          *(_WORD *)(this + 6042) -= a3;
          goto LABEL_72;
        case 64:
          *(_WORD *)(this + 6044) -= a3;
          goto LABEL_72;
        case 65:
          *(_WORD *)(this + 6046) -= a3;
          goto LABEL_72;
        case 67:
          *(_WORD *)(this + 6036) -= a3;
LABEL_72:
          v25 = 0;
          v23 = 91;
LABEL_73:
          sub_4948B1((void *)pPlayers[v4], v23, v25);
          goto LABEL_17;
        case 23:
          sub_492B03((void *)a3);
          goto LABEL_17;
        case 68:
        case 69:
        case 70:
        case 71:
        case 72:
        case 73:
        case 74:
        case 75:
        case 76:
        case 77:
        case 78:
        case 79:
        case 80:
        case 81:
        case 82:
        case 83:
        case 84:
        case 85:
        case 86:
        case 87:
        case 88:
        case 89:
        case 90:
        case 91:
        case 92:
        case 93:
        case 94:
        case 95:
        case 97:
        case 104:
          *(_WORD *)(this + 2 * a2 + 128) -= (unsigned __int8)a3;
          goto LABEL_17;
        case 105:
        case 106:
        case 107:
        case 108:
        case 109:
        case 110:
        case 111:
        case 112:
        case 113:
        case 114:
        case 115:
        case 116:
        case 117:
        case 118:
        case 119:
        case 120:
        case 121:
          *(_DWORD *)(this + 8 * a2 - 840) = 0;
          *(_DWORD *)(this + 8 * v5 - 836) = 0;
LABEL_17:
          sub_4A89BD(pGame->class06_obj, 152, v4);
          v8 = 8 * v4 + 400;
          LOBYTE(v8) = (8 * v4 - 112) | 4;
          AudioPlayer_sub_4AA306(pAudioPlayer, 20001, v8, 0, -1, 0, 0, 0, 0);
          return;
      }
      do
      {
        if ( *(_DWORD *)(this + 36 * *(_DWORD *)v15 + 496) == a3 )
        {
          sub_492A36((void *)this, v3);
          return;
        }
        ++v3;
        v15 += 4;
      }
      while ( v3 < 126 );
      if ( dword_AD470C == a3 )
        class03_sub_4698A6(pGame->pClass03);
    }
  }
}

//----- (0044C175) --------------------------------------------------------
int __fastcall sub_44C175(const char *Source, int a2)
{
  int result; // eax@1
  int v3; // esi@1

  v3 = a2;
  strcpy(&byte_5C3428, Source);
  dword_5C35B8 = 1000 * v3 + GetTickCount();
  for ( result = sub_44C51E(pFontLucida, &byte_5C3428); result > 450; result = sub_44C51E(pFontLucida, &byte_5C3428) )
    byte_5C3427[strlen(&byte_5C3428)] = 0;
  return result;
}

//----- (0044C1D0) --------------------------------------------------------
int __cdecl sub_44C1D0()
{
  int result; // eax@2

  if ( !dword_5C35B8 )
    result = sub_44C175(pGlobalTXT_LocalizationStrings[521], 2);
  return result;
}

//----- (0044C23B) --------------------------------------------------------
signed int __thiscall sub_44C23B(int this)
{
  int v1; // eax@1
  _UNKNOWN *v2; // esi@2
  signed int result; // eax@5
  int v4; // eax@6

  v1 = 0;
  if ( uLevelEVT_NumEvents - 1 <= 0 )
    goto LABEL_5;
  v2 = pLevelEVT_Events;
  while ( *(_DWORD *)v2 != *(_WORD *)(this + 26) )
  {
    ++v1;
    v2 = (char *)v2 + 12;
    if ( v1 >= uLevelEVT_NumEvents - 1 )
      goto LABEL_5;
  }
  v4 = 12 * v1;
  if ( byte_5B3524[*(int *)((char *)&pLevelEVT_Events[1].dword_000008 + v4)] != 1 || byte_5B3524[*(int *)((char *)&pLevelEVT_Events[0].dword_000008 + v4)] != 4 )
LABEL_5:
    result = 0;
  else
    result = 1;
  return result;
}

//----- (0044C28B) --------------------------------------------------------
signed int __cdecl sub_44C28B()
{
  return 2;
}

//----- (0044C28F) --------------------------------------------------------
int __cdecl sub_44C28F()
{
  int result; // eax@1

  result = _strcmpi("nwc.blv", Str1);
  if ( result )
  {
    dword_5B65A8 = 0;
    dword_5B65AC = 0;
    dword_5B65B0 = 0;
    dword_5B65B4 = 0;
    dword_5B65B8 = 0;
    dword_5B65BC = 0;
    dword_5B65C0 = 0;
    pLoadingUI->uProgressBarType = 1;
    sub_44987B("nwc.blv", 0);
    dword_4E28F8 = 0;
    result = 1;
  }
  return result;
}

//----- (0044C2F4) --------------------------------------------------------
signed int __thiscall sub_44C2F4(void *this)
{
  signed int v1; // eax@1

  v1 = *(_WORD *)this;
  if ( v1 > 34 )
  {
    if ( v1 == 184 || v1 == 187 || v1 == 190 || v1 > 205 && v1 <= 221 )
      return 1;
  }
  else
  {
    if ( v1 == 34 || v1 >= 4 && (v1 <= 6 || v1 == 11 || v1 > 12 && (v1 <= 14 || v1 == 24)) )
      return 1;
  }
  return 0;
}

//----- (0044C362) --------------------------------------------------------
int __thiscall sub_44C362(int this)
{
  int result; // eax@1
  int v2; // esi@1
  double v3; // st6@1
  float v4; // ST20_4@1
  double v5; // st5@1
  float v6; // ST18_4@1
  double v7; // st4@1
  float v8; // ST14_4@1
  float v9; // ST24_4@1
  float v10; // ST20_4@1
  double v11; // ST0C_8@1
  float v12; // ST18_4@1
  double v13; // ST0C_8@1
  float v14; // ST14_4@1
  double v15; // ST0C_8@1

  v2 = this;
  v3 = (double)*(signed int *)this * 0.0000152587890625;
  v4 = v3;
  v5 = (double)*(signed int *)(this + 4) * 0.0000152587890625;
  v6 = v5;
  v7 = (double)*(signed int *)(this + 8) * 0.0000152587890625;
  v8 = v7;
  v9 = 1.0 / sqrt(v7 * v7 + v5 * v5 + v3 * v3);
  v10 = v9 * v4 * 65536.0;
  v11 = v10 + 6.755399441055744e15;
  *(_DWORD *)v2 = LODWORD(v11);
  v12 = v9 * v6 * 65536.0;
  v13 = v12 + 6.755399441055744e15;
  *(_DWORD *)(v2 + 4) = LODWORD(v13);
  v14 = v9 * v8 * 65536.0;
  v15 = v14 + 6.755399441055744e15;
  result = LODWORD(v15);
  *(_DWORD *)(v2 + 8) = LODWORD(v15);
  return result;
}

//----- (0044C62E) --------------------------------------------------------
int __fastcall sub_44C62E(int a1, char a2, const char *Str, int a4, int a5, int a6)
{
  int v6; // edi@1
  unsigned __int8 *v8; // ebx@3
  int v9; // esi@3
  size_t v10; // eax@3
  unsigned __int8 v11; // cl@4
  signed int v12; // [sp+Ch] [bp+8h]@3
  size_t v13; // [sp+14h] [bp+10h]@3

  v6 = a1;
  if ( !Str )
    return 0;
  v9 = *(_BYTE *)(a1 + 5) - 3;
  v8 = (unsigned __int8 *)sub_44C933(Str, a1, a2, a4, a5, 0);
  v10 = strlen(Str);
  v12 = 0;
  v13 = v10;
  while ( v12 < (signed int)v13 )
  {
    if ( sub_44C4DE(*v8, v6) )
    {
      if ( v11 == 9 )
        goto LABEL_9;
      switch ( v11 )
      {
        case 0xAu:
          v9 = v9 + *(_BYTE *)(v6 + 5) - 3;
          break;
        case 0xCu:
          v8 += 5;
          v12 += 5;
          break;
        case 0xDu:
LABEL_9:
          if ( a6 != 1 )
          {
            v8 += 3;
            v12 += 3;
          }
          break;
      }
    }
    ++v12;
    ++v8;
  }
  return v9;
}

//----- (0044C6C2) --------------------------------------------------------
int __fastcall sub_44C6C2(int a1, const char *a2, int a3, char a4, int a5)
{
  int v5; // edi@1
  const char *v6; // esi@1
  unsigned __int8 *v8; // ebx@3
  signed int v9; // esi@3
  size_t v10; // eax@3
  int v11; // edx@4
  unsigned __int8 v12; // cl@4
  int v13; // [sp+Ch] [bp-4h]@1
  size_t v14; // [sp+1Ch] [bp+Ch]@3

  v6 = a2;
  v5 = 0;
  v13 = a1;
  if ( !a2 )
    return 0;
  v8 = (unsigned __int8 *)FitTextInAWindow(a2, a1, a3, a4, 0);
  v10 = strlen(v6);
  v9 = 0;
  v14 = v10;
  if ( (signed int)v10 > 0 )
  {
    while ( !sub_44C4DE(*v8, v13) )
    {
LABEL_11:
      ++v9;
      ++v8;
      if ( v9 >= (signed int)v14 )
        return (int)v8;
    }
    if ( v12 != 9 )
    {
      if ( v12 == 10 )
      {
        v5 = v5 + *(_BYTE *)(v11 + 5) - 3;
        if ( v5 >= a5 * *(_DWORD *)(a3 + 12) )
          return (int)(v8 + 1);
        goto LABEL_10;
      }
      if ( v12 == 12 )
      {
        v8 += 5;
        v9 += 5;
LABEL_10:
        if ( v5 >= a5 * *(_DWORD *)(a3 + 12) )
          return (int)v8;
        goto LABEL_11;
      }
      if ( v12 != 13 )
        goto LABEL_10;
    }
    v8 += 3;
    v9 += 3;
    goto LABEL_10;
  }
  return (int)v8;
}

//----- (0044C933) --------------------------------------------------------
char *__fastcall sub_44C933(const char *a1, int a2, char a3, int a4, int a5, int a6)
{
  const char *v6; // esi@1
  int v8; // eax@3
  int v9; // ebx@3
  size_t v10; // edi@3
  int v11; // esi@3
  size_t v12; // eax@3
  unsigned __int8 v13; // cl@5
  int v14; // edx@11
  int v15; // ecx@11
  int v16; // edx@12
  int v17; // edx@13
  int v18; // edx@14
  int v19; // edx@15
  int v20; // edx@17
  int v21; // ecx@17
  int v22; // edi@17
  int v23; // edi@18
  char v24; // zf@18
  int v25; // eax@19
  int v26; // ecx@19
  unsigned __int8 v27; // dl@24
  int v28; // eax@46
  char v29; // [sp-18h] [bp-48h]@2
  int v30; // [sp-14h] [bp-44h]@2
  int v31; // [sp-10h] [bp-40h]@2
  int v32; // [sp-Ch] [bp-3Ch]@2
  const char *v33; // [sp-8h] [bp-38h]@2
  int v34; // [sp-4h] [bp-34h]@2
  const char *v35; // [sp+Ch] [bp-24h]@1
  char Dest; // [sp+10h] [bp-20h]@46
  char v37; // [sp+13h] [bp-1Dh]@46
  int v38; // [sp+14h] [bp-1Ch]@1
  int v39; // [sp+18h] [bp-18h]@3
  int v40; // [sp+1Ch] [bp-14h]@3
  int v41; // [sp+20h] [bp-10h]@4
  int v42; // [sp+24h] [bp-Ch]@3
  int v43; // [sp+28h] [bp-8h]@3
  int i; // [sp+2Ch] [bp-4h]@17
  char *v45; // [sp+38h] [bp+8h]@2

  v6 = a1;
  v38 = a2;
  v35 = a1;
  if ( !a1 )
  {
    v34 = 558;
    v33 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Font.cpp";
    v45 = &v29;
    sub_40E2C8(&v29, "Invalid string passed !", (int)(&a3 + 3));
    sub_466D09(&a5, *(int *)&v29, v30, v31, v32, v33, v34);
    return 0;
  }
  v12 = strlen(a1);
  v10 = v12;
  v42 = v12;
  strcpy(&byte_5C45B0, v6);
  v8 = a5;
  v11 = v38;
  v9 = 0;
  v43 = 0;
  v40 = a5;
  v39 = 0;
  if ( (signed int)v10 > 0 )
  {
    v41 = v10 - 1;
    do
    {
      v13 = *(&byte_5C45B0 + v9);
      if ( v13 >= *(_BYTE *)v11 && v13 <= *(_BYTE *)(v11 + 1) || v13 == 12 || v13 == 13 || v13 == 9 || v13 == 10 )
      {
        v14 = v13 - 9;
        v15 = v11 + 12 * v13 + 32;
        if ( v14 )
        {
          v16 = v14 - 1;
          if ( v16 )
          {
            v17 = v16 - 2;
            if ( v17 )
            {
              v18 = v17 - 1;
              if ( v18 )
              {
                v19 = v18 - 19;
                if ( v19 )
                {
                  if ( v19 == 63 )
                  {
                    v11 = a3;
                  }
                  else
                  {
                    v22 = *(_DWORD *)(v15 + 8);
                    v20 = *(_DWORD *)(v15 + 4);
                    v21 = *(_DWORD *)v15;
                    i = v22;
                    if ( (unsigned int)(v8 + v22 + v21 + v20) < *(_DWORD *)(a4 + 8) )
                    {
                      v9 = v39;
                      if ( v39 > v43 )
                        v8 += v21;
                      v8 += v20;
                      if ( v39 < v42 )
                        v8 += i;
                    }
                    else
                    {
                      v23 = v43;
                      v24 = v11 == a3;
                      *(byte_5C45B0 + v43) = 10;
                      if ( v24 )
                      {
                        v26 = v41;
                        v25 = v23 + 1;
                        while ( v26 >= v25 )
                        {
                          *(byte_5C45B0 + v26) = byte_5C45AF[v26];
                          --v26;
                        }
                        ++v42;
                        ++v41;
                        byte_5C45B0[1 + v23++] = 95;
                        v43 = v25;
                      }
                      v9 = v39;
                      v8 = v40;
                      for ( i = v23; i <= v39; ++i )
                      {
                        v27 = *(&byte_5C45B0 + i);
                        if ( v27 >= *(_BYTE *)v11 && v27 <= *(_BYTE *)(v11 + 1)
                          || v27 == 12
                          || v27 == 13
                          || v27 == 9
                          || v27 == 10 )
                        {
                          if ( i > v23 )
                            v8 += *(_DWORD *)(v11 + 12 * v27 + 32);
                          v8 += *(_DWORD *)(v11 + 4 * (3 * v27 + 9));
                          if ( i < v39 )
                            v8 += *(_DWORD *)(v11 + 12 * v27 + 40);
                        }
                      }
                    }
                  }
                }
                else
                {
                  v8 += *(_DWORD *)(v15 + 4);
                  v43 = v9;
                }
              }
              else
              {
                if ( !a6 )
                  return (char *)v35;
              }
            }
            else
            {
              v9 += 5;
            }
          }
          else
          {
            v8 = v40;
            v11 = v38;
            v43 = v9;
          }
        }
        else
        {
          strncpy(&Dest, &byte_5C45B0[v9 + 1], 3u);
          v37 = 0;
          v28 = atoi(&Dest);
          v8 = a5 + v28;
          v9 += 3;
          v40 = v8;
        }
      }
      ++v9;
      v39 = v9;
    }
    while ( v9 < v42 );
  }
  return &byte_5C45B0;
}

//----- (0044D0B5) --------------------------------------------------------
void __fastcall sub_44D0B5(int a1, int a2, int a3, int a4, const char *Str, int a6)
{
  int v6; // ebx@1
  int v7; // esi@1
  int v8; // edi@3
  unsigned __int8 v9; // cl@4
  int v10; // eax@5
  int v11; // ecx@5
  int v12; // ecx@6
  int v13; // ecx@7
  int v14; // ecx@8
  int v15; // ebx@10
  __int16 v16; // ax@13
  int v17; // edx@13
  unsigned __int8 v18; // sf@18
  unsigned __int8 v19; // of@18
  char Dest; // [sp+Ch] [bp-20h]@17
  char v21; // [sp+11h] [bp-1Bh]@17
  size_t v22; // [sp+20h] [bp-Ch]@2
  int v23; // [sp+24h] [bp-8h]@1
  int v24; // [sp+28h] [bp-4h]@2
  char *v25; // [sp+38h] [bp+Ch]@4

  v6 = 0;
  v23 = a2;
  v7 = a1;
  if ( Str )
  {
    v23 = dword_5C6DB4;
    v22 = strlen(Str);
    v24 = 0;
    if ( (signed int)v22 > 0 )
    {
      v8 = a4;
      do
      {
        v25 = (char *)&Str[v6];
        if ( sub_44C4DE(Str[v6], v7) )
        {
          v10 = v9;
          v11 = v9 - 9;
          if ( v11 )
          {
            v12 = v11 - 1;
            if ( !v12 )
              return;
            v13 = v12 - 2;
            if ( v13 )
            {
              v14 = v13 - 1;
              if ( v14 )
              {
                if ( v14 != 82 )
                {
                  v15 = *(_DWORD *)(v7 + 4 * (3 * v10 + 9));
                  if ( v15 )
                  {
                    if ( v24 > 0 )
                      v8 += 2 * *(_DWORD *)(v7 + 12 * v10 + 32);
                    v17 = *(_DWORD *)(v7 + 4 * v10 + 3104) + v7 + 4128;
                    v16 = v23;
                    if ( !v23 )
                      v16 = -1;
                    sub_40F845(v8, v17, v15, *(_BYTE *)(v7 + 5), *(_DWORD *)(v7 + 12), v16, 2 * a6);
                    v8 += 2 * v15;
                    if ( v24 < (signed int)v22 )
                      v8 += 2 * *(_DWORD *)(v7 + 12 * (unsigned __int8)*v25 + 40);
                  }
                }
              }
            }
            else
            {
              strncpy(&Dest, &Str[v6 + 1], 5u);
              v21 = 0;
              v23 = atoi(&Dest);
              dword_5C6DB4 = v23;
              v24 = v6 + 5;
            }
          }
        }
        v6 = v24 + 1;
        compile_error;//v19 = __SETO__(v24 + 1, v22);
        v18 = (signed int)(v24++ + 1 - v22) < 0;
      }
      while ( v18 ^ v19 );
    }
  }
}

//----- (0044D2FD) --------------------------------------------------------
char *__fastcall sub_44D2FD(int a1, int a2, int Str, int a4, int a5, int a6, unsigned __int16 a7, unsigned __int16 a8, const char *a9, int a10, int a11)
{
  char *result; // eax@1
  int v12; // ebx@1
  signed int v13; // edi@1
  int v14; // esi@1
  char *v15; // eax@1
  signed int v16; // ecx@4
  int v17; // edi@4
  int v18; // eax@6
  char *v19; // [sp+Ch] [bp-5Ch]@1
  int v20; // [sp+10h] [bp-58h]@1
  int v21; // [sp+14h] [bp-54h]@1
  int v22; // [sp+18h] [bp-50h]@1
  char *v23; // [sp+1Ch] [bp-4Ch]@1
  int v24; // [sp+20h] [bp-48h]@1
  int v25; // [sp+60h] [bp-8h]@1
  int v26; // [sp+64h] [bp-4h]@1
  const char *v27; // [sp+70h] [bp+8h]@1
  int v28; // [sp+74h] [bp+Ch]@4
  signed int v29; // [sp+80h] [bp+18h]@2

  v12 = a7;
  v22 = a6;
  v13 = Str;
  v26 = a1;
  v24 = a4 + a6 - 1;
  v21 = a5;
  v25 = a2;
  v23 = (char *)(Str + a5 - 1);
  dword_5C6DB4 = a7;
  v19 = (char *)Str;
  v20 = a4;
  v15 = sub_44C933(a9, a1, a2, (int)&v19, 0, 1);
  result = strtok(v15, L"\n");
  v27 = result;
  v14 = a10 + 2 * a11 * a4;
  if ( result )
  {
    v29 = v13 >> 1;
    while ( 1 )
    {
      v17 = v26;
      dword_5C6DB4 = v12;
      v16 = 0;
      v28 = v12;
      if ( *result == 95 )
      {
        v17 = v25;
        v28 = a8;
        dword_5C6DB4 = a8;
        v16 = 1;
      }
      v18 = (a5 - sub_44C51E(v17, &result[v16])) >> 1;
      if ( v18 < 0 )
        v18 = 0;
      sub_44D0B5(v17, v28, a8, v14 + 2 * (v18 + v29), v27, a11);
      v14 += 2 * a11 * (*(_BYTE *)(v17 + 5) - 3);
      result = strtok(0, L"\n");
      v27 = result;
      if ( !result )
        break;
      result = (char *)v27;
    }
  }
  return result;
}

//----- (0044D83A) --------------------------------------------------------
int __thiscall sub_44D83A(void *this, int a2, int a3, const char *Str1)
{
  int v4; // ebx@1
  void *v5; // edi@1
  int result; // eax@2
  int v7; // esi@2
  int v8; // [sp+14h] [bp+8h]@2

  v4 = a2;
  v5 = this;
  while ( 1 )
  {
    v8 = a3 - v4;
    v7 = (a3 - v4) / 2 + v4;
    result = _strcmpi(Str1, *(const char **)(*((_DWORD *)v5 + 4) + 4 * v7));
    if ( !result )
      *((_DWORD *)v5 + 2) = v7;
    if ( v4 == a3 )
      break;
    if ( result >= 0 )
    {
      if ( v8 <= 4 )
      {
        while ( v4 < a3 )
        {
          result = _strcmpi(Str1, *(const char **)(*((_DWORD *)v5 + 4) + 4 * v4));
          if ( !result )
          {
LABEL_19:
            *((_DWORD *)v5 + 2) = v4;
            return result;
          }
          ++v4;
        }
        break;
      }
      v4 += (a3 - v4) / 2;
    }
    else
    {
      if ( v8 <= 4 )
      {
        while ( v4 < a3 )
        {
          result = _strcmpi(Str1, *(const char **)(*((_DWORD *)v5 + 4) + 4 * v4));
          if ( !result )
            goto LABEL_19;
          ++v4;
        }
        break;
      }
      a3 = (a3 - v4) / 2 + v4;
    }
  }
  *((_DWORD *)v5 + 2) = -1;
  return result;
}

//----- (0044E054) --------------------------------------------------------
int __thiscall sub_44E054(void *Str)
{
  FILE *v1; // eax@1
  FILE *v2; // edi@1
  void *v3; // esi@1

  v3 = Str;
  v1 = fopen("data\\dtft.bin", "wb");
  v2 = v1;
  if ( !v1 )
    erroneous_printf("Unable to save dtft.bin!");
  locked_fwrite(v3, 4u, 1u, v1);
  locked_fwrite(*((const void **)v3 + 1), 0x14u, *(_DWORD *)v3, v2);
  return fclose(v2);
}

//----- (0044E0ED) --------------------------------------------------------
int __thiscall sub_44E0ED(void *this, int a2)
{
  int result; // eax@1
  void *v3; // ebx@1
  int i; // edi@3

  result = a2;
  v3 = this;
  if ( a2 <= *(_DWORD *)this )
  {
    if ( a2 >= 0 )
    {
      for ( i = 20 * a2; ; i += 20 )
      {
        *(_WORD *)(*((_DWORD *)v3 + 1) + i + 12) = class17_LoadTexture(
                                                     pClass17_Bitmaps_LOD,
                                                     (const char *)(i + *((_DWORD *)v3 + 1)),
                                                     0);
        if ( *(_WORD *)(*((_DWORD *)v3 + 1) + i + 12) != -1 ? 72 * *(_WORD *)(*((_DWORD *)v3 + 1) + i + 12) + 7278780 : 0 )
          *(_WORD *)(*(_WORD *)(*((_DWORD *)v3 + 1) + i + 12) != -1 ? 72 * *(_WORD *)(*((_DWORD *)v3 + 1) + i + 12)
                                                                    + 7278780
                                                                    + 0x26 : 38) = class35_sub_48A3BC(
                                                                                     &class35_obj,
                                                                                     *(_WORD *)(*(_WORD *)(*((_DWORD *)v3 + 1) + i + 12) != -1 ? 72 * *(_WORD *)(*((_DWORD *)v3 + 1) + i + 12) + 7278780 + 0x24 : 36));
        result = *((_DWORD *)v3 + 1);
        if ( !(*(_BYTE *)(result + i + 18) & 1) )
          break;
      }
    }
  }
  return result;
}

//----- (0044E163) --------------------------------------------------------
signed int __thiscall sub_44E163(void *this, const char *Str2)
{
  int v2; // ebx@1
  signed int v3; // edi@1
  void *v4; // esi@1
  signed int result; // eax@4

  v4 = this;
  v2 = 0;
  v3 = 0;
  if ( *(_DWORD *)this <= 0 )
  {
LABEL_4:
    result = -1;
  }
  else
  {
    while ( _strcmpi((const char *)(v2 + *((_DWORD *)v4 + 1)), Str2) )
    {
      ++v3;
      v2 += 20;
      if ( v3 >= *(_DWORD *)v4 )
        goto LABEL_4;
    }
    result = v3;
  }
  return result;
}

//----- (0044E19A) --------------------------------------------------------
int __thiscall TextureFrameTable_GetFrame(int this, int a2, signed int a3)
{
  int v3; // ecx@1
  int v4; // edi@1
  int v5; // esi@1
  signed __int16 v6; // dx@2
  int i; // eax@3
  int v8; // edx@3
  int v9; // ecx@5
  int result; // eax@6

  v5 = a2;
  v4 = *(_DWORD *)(this + 4);
  v3 = v4 + 20 * a2;
  if ( *(_BYTE *)(v3 + 18) & 1 && (v6 = *(_WORD *)(v3 + 16)) != 0 )
  {
    v8 = (a3 >> 3) % v6;
    for ( i = v3 + 14; ; i += 20 )
    {
      v9 = *(_WORD *)i;
      if ( v8 <= v9 )
        break;
      v8 -= v9;
      ++v5;
    }
    result = *(_WORD *)(v4 + 20 * v5 + 12);
  }
  else
  {
    result = *(_WORD *)(v3 + 12);
  }
  return result;
}

//----- (0044E7F3) --------------------------------------------------------
function_error;//int __usercall sub_44E7F3<eax>(int result<eax>, int a2<ecx>)
int __fastcall sub_44E7F3(int result, int a2)
{
  int v2; // ecx@1
  int v3; // esi@1
  int v4; // ecx@3
  int v5; // ecx@5
  unsigned int v6; // edi@7
  int v7; // eax@8
  unsigned int v8; // edi@9
  int v9; // eax@10
  int v10; // ecx@11
  int v11; // ecx@13
  int v12; // ecx@15
  unsigned int v13; // edi@17
  int v14; // eax@18
  int v15; // ecx@19
  int v16; // ecx@21
  unsigned int v17; // edi@23
  int v18; // eax@24
  unsigned int v19; // edi@25
  int v20; // eax@26
  int v21; // ecx@27

  v3 = a2;
  v2 = *(_DWORD *)(a2 + 3696);
  *(_DWORD *)v3 = 5080668;
  if ( v2 )
    result = (**(int (__stdcall ***)(_DWORD))v2)(1);
  v4 = *(_DWORD *)(v3 + 3692);
  if ( v4 )
    result = (**(int (__stdcall ***)(_DWORD))v4)(1);
  v5 = *(_DWORD *)(v3 + 3688);
  if ( v5 )
    result = (**(int (__stdcall ***)(_DWORD))v5)(1);
  v6 = *(_DWORD *)(v3 + 3684);
  if ( v6 )
  {
    v7 = sub_489810(result, *(_DWORD *)(v3 + 3684));
    result = operator_delete(v7, v6);
  }
  v8 = *(_DWORD *)(v3 + 3680);
  if ( v8 )
  {
    compile_error;//v9 = nullsub_1(*(_DWORD *)(v3 + 3680));
    result = operator_delete(v9, v8);
  }
  v10 = *(_DWORD *)(v3 + 3676);
  if ( v10 )
    result = (**(int (__stdcall ***)(_DWORD))v10)(1);
  v11 = *(_DWORD *)(v3 + 3672);
  if ( v11 )
    result = (**(int (__stdcall ***)(_DWORD))v11)(1);
  v12 = *(_DWORD *)(v3 + 3668);
  if ( v12 )
    result = (**(int (__stdcall ***)(_DWORD))v12)(1);
  v13 = *(_DWORD *)(v3 + 3664);
  if ( v13 )
  {
    sub_4A71DC(*(_DWORD *)(v3 + 3664));
    result = operator_delete(v14, v13);
  }
  v15 = *(_DWORD *)(v3 + 3660);
  if ( v15 )
    result = (**(int (__stdcall ***)(_DWORD))v15)(1);
  v16 = *(_DWORD *)(v3 + 3656);
  if ( v16 )
    result = (**(int (__stdcall ***)(_DWORD))v16)(1);
  v17 = *(_DWORD *)(v3 + 3652);
  if ( v17 )
  {
    v18 = sub_467E7A(*(_DWORD *)(v3 + 3652));
    result = operator_delete(v18, v17);
  }
  v19 = *(_DWORD *)(v3 + 3648);
  if ( v19 )
  {
    v20 = sub_48AAF1(*(_DWORD *)(v3 + 3648));
    result = operator_delete(v20, v19);
  }
  v21 = *(_DWORD *)(v3 + 3644);
  if ( v21 )
    result = (**(int (__stdcall ***)(_DWORD))v21)(1);
  return result;
}

//----- (0044E904) --------------------------------------------------------
void __thiscall sub_44E904(void *this)
{
  __int64 v1; // qax@1
  unsigned int v2; // ecx@1
  int v3; // edi@1
  void *v4; // esi@1
  unsigned __int8 v5; // cf@7
  unsigned int v6; // eax@13
  unsigned __int8 v7; // cf@14
  signed __int64 v8; // qax@14
  double v9; // st7@14
  double v10; // st7@16
  signed __int64 v11; // [sp+Ch] [bp-8h]@1

  v4 = this;
  v1 = class24_fn2(pClass24_global);
  v2 = v1 - *((_DWORD *)v4 + 907);
  v3 = (unsigned __int64)(v1 - *(_QWORD *)((char *)v4 + 3628)) >> 32;
  v11 = v1 - *(_QWORD *)((char *)v4 + 3628);
  if ( (signed int)((unsigned __int64)(v1 - *(_QWORD *)((char *)v4 + 3628)) >> 32) >= 0
    && (HIDWORD(v1) > ((_DWORD)v1 < *((_DWORD *)v4 + 907)) + *((_DWORD *)v4 + 908) || v2 > 0x80) )
  {
    if ( *(_QWORD *)((char *)v4 + 3636) )
    {
      *((_DWORD *)v4 + 909) = 0;
      *((_DWORD *)v4 + 910) = 0;
    }
    else
    {
      *((_DWORD *)v4 + 909) = v2;
      *((_DWORD *)v4 + 910) = v3;
    }
    v5 = v2 >= 0x80;
    v2 -= 128;
    v3 = v5 + v3 - 1;
    goto LABEL_12;
  }
  if ( v3 <= 0 && v3 < 0 )
  {
    v2 = 0;
    v3 = 0;
LABEL_12:
    *(_QWORD *)((char *)v4 + 3628) = v1;
    LODWORD(v11) = v2;
    HIDWORD(v11) = v3;
  }
  v6 = *((_DWORD *)v4 + 909);
  if ( *(_QWORD *)((char *)v4 + 3636) )
  {
    v7 = v6 < v2;
    LODWORD(v8) = v6 - v2;
    HIDWORD(v8) = *((_DWORD *)v4 + 910) - (v7 + v3);
    v9 = (double)v8;
  }
  else
  {
    v9 = (double)v11;
  }
  v10 = v9 * 0.0078125;
  if ( v10 < 0.0 || v10 <= 1.0 )
  {
    if ( v10 < 0.0 )
      v10 = 0.0;
  }
  else
  {
    v10 = 1.0;
  }
  if ( pD3DRenderer->dword_040088 )
    *((float *)v4 + 906) = v10;
  else
    *((float *)v4 + 906) = (1.0 - 0.5) * v10 + 0.5;
}

//----- (0044EB12) --------------------------------------------------------
char __thiscall sub_44EB12(int this, char a2, int a3, int a4)
{
  int v4; // esi@1
  int v5; // ecx@2
  char result; // al@4

  v4 = this;
  if ( !dword_4E28F8 && (v5 = *(_DWORD *)(this + 3660)) != 0 && pD3DRenderer->dword_040088 )
  {
    sub_4C05CC(v5, v5 + 4, a3, a4);
    if ( a2 )
      CGame_outline_selection(v4);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0044EB5A) --------------------------------------------------------
void *__thiscall CGame_outline_selection(int this)
{
  void *result; // eax@1
  int v2; // edx@9
  int v3; // eax@10
  int v4; // eax@14
  char v5; // [sp-18h] [bp-24h]@8
  int v6; // [sp-14h] [bp-20h]@8
  int v7; // [sp-10h] [bp-1Ch]@8
  int v8; // [sp-Ch] [bp-18h]@8
  const char *v9; // [sp-8h] [bp-14h]@8
  int v10; // [sp-4h] [bp-10h]@8
  char v11; // [sp+0h] [bp-Ch]@18
  char *v12; // [sp+4h] [bp-8h]@8
  int v13; // [sp+Ah] [bp-2h]@8

  result = *(void **)(this + 3660);
  if ( result )
  {
    if ( *((_DWORD *)result + 2050) <= 0 )
      result = 0;
    else
      result = (void *)*((_DWORD *)result + 1538);
    if ( result )
    {
      if ( *((_DWORD *)result + 2) == 1 )
      {
        v10 = 293;
        v9 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Game.cpp";
        v12 = &v5;
        sub_40E2C8(&v5, "Sprite outline currently Unsupported", (int)&v13);
        result = sub_467834(&v11, v5, (const CHAR *)v6, v7, v8, v9, v10);
      }
      else
      {
        if ( *((_DWORD *)result + 2) == 2 )
        {
          v2 = *(_DWORD *)result;
          if ( dword_6BE360 == 1 )
          {
            v3 = *(_DWORD *)(v2 + 44);
            if ( v3 & 0x10000 )
              result = (void *)(v3 & 0xFFFEFFFF);
            else
              result = (void *)(v3 | 0x10000);
            *(_DWORD *)(v2 + 44) = result;
          }
          else
          {
            v4 = *(_DWORD *)(v2 + 28);
            if ( v4 & 0x10000 )
              result = (void *)(v4 & 0xFFFEFFFF);
            else
              result = (void *)(v4 | 0x10000);
            *(_DWORD *)(v2 + 28) = result;
          }
        }
        else
        {
          v10 = 302;
          v9 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Game.cpp";
          v12 = &v5;
          sub_40E2C8(&v5, "Undefined CObjectInfo type requested in CGame::outline_selection()", (int)((char *)&v13 + 1));
          result = sub_466D09(&v12, *(int *)&v5, v6, v7, v8, v9, v10);
        }
      }
    }
  }
  return result;
}

//----- (0044EC20) --------------------------------------------------------
char __cdecl sub_44EC20()
{
  return 1;
}

//----- (0044EC23) --------------------------------------------------------
signed int __thiscall sub_44EC23(int this, int a2, int a3, signed int a4)
{
  double v4; // st7@4
  double v5; // ST00_8@4
  signed int v6; // eax@5
  double v7; // ST00_8@6
  signed int result; // eax@8
  double v9; // ST00_8@9
  double v10; // ST00_8@11
  float v11; // [sp+14h] [bp+8h]@4
  float v12; // [sp+18h] [bp+Ch]@4
  float v13; // [sp+18h] [bp+Ch]@6
  float v14; // [sp+1Ch] [bp+10h]@9
  float v15; // [sp+1Ch] [bp+10h]@11

  if ( *(_BYTE *)(this + 3620) & 2 && *(_BYTE *)(a2 + 89) == 5 && *(_BYTE *)(*(_DWORD *)(a2 + 84) + 28) & 2 )
  {
    v4 = (double)a4;
    v11 = v4;
    *(_DWORD *)a3 |= 2;
    v12 = (1.0 - *(float *)(this + 3624)) * v4;
    v5 = v12 + 6.755399441055744e15;
    if ( LODWORD(v5) >= 0 )
    {
      v13 = (1.0 - *(float *)(this + 3624)) * v11;
      v7 = v13 + 6.755399441055744e15;
      v6 = LODWORD(v7);
    }
    else
    {
      v6 = 0;
    }
    if ( a4 >= v6 )
    {
      v14 = (1.0 - *(float *)(this + 3624)) * v11;
      v9 = v14 + 6.755399441055744e15;
      if ( LODWORD(v9) >= 0 )
      {
        v15 = (1.0 - *(float *)(this + 3624)) * v11;
        v10 = v15 + 6.755399441055744e15;
        result = LODWORD(v10);
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = a4;
    }
  }
  else
  {
    result = -1;
  }
  return result;
}

//----- (0044ED0A) --------------------------------------------------------
signed int __thiscall sub_44ED0A(int this, int a2, int a3, signed int a4)
{
  double v4; // st7@3
  double v5; // ST00_8@3
  signed int v6; // eax@4
  double v7; // ST00_8@5
  signed int result; // eax@7
  double v9; // ST00_8@8
  double v10; // ST00_8@10
  float v11; // [sp+14h] [bp+8h]@3
  float v12; // [sp+18h] [bp+Ch]@3
  float v13; // [sp+18h] [bp+Ch]@5
  float v14; // [sp+1Ch] [bp+10h]@8
  float v15; // [sp+1Ch] [bp+10h]@10

  if ( *(_BYTE *)(this + 3620) & 2 && *(_BYTE *)(a2 + 44) & 2 )
  {
    v4 = (double)a4;
    v11 = v4;
    *(_DWORD *)a3 |= 2;
    v12 = (1.0 - *(float *)(this + 3624)) * v4;
    v5 = v12 + 6.755399441055744e15;
    if ( LODWORD(v5) >= 0 )
    {
      v13 = (1.0 - *(float *)(this + 3624)) * v11;
      v7 = v13 + 6.755399441055744e15;
      v6 = LODWORD(v7);
    }
    else
    {
      v6 = 0;
    }
    if ( a4 >= v6 )
    {
      v14 = (1.0 - *(float *)(this + 3624)) * v11;
      v9 = v14 + 6.755399441055744e15;
      if ( LODWORD(v9) >= 0 )
      {
        v15 = (1.0 - *(float *)(this + 3624)) * v11;
        v10 = v15 + 6.755399441055744e15;
        result = LODWORD(v10);
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = a4;
    }
  }
  else
  {
    result = -1;
  }
  return result;
}

//----- (0044EDE4) --------------------------------------------------------
char __thiscall sub_44EDE4(int this, int a2, void **a3)
{
  char result; // al@3

  if ( *(_BYTE *)(LODWORD(pGame) + 3620) & 2 && *(_BYTE *)(a2 + 44) & 2 )
  {
    compile_error;//*a3 = (void *)sub_48A959(*a3, 1.0, COERCE_INT(*(float *)(this + 3624)), COERCE_INT(-1.0));
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0044EE30) --------------------------------------------------------
char __thiscall sub_44EE30(int this, int a2, void **a3)
{
  char result; // al@3

  if ( *(_BYTE *)(LODWORD(pGame) + 3620) & 2 && *(_BYTE *)(a2 + 28) & 2 )
  {
    compile_error;//*a3 = (void *)sub_48A959(*a3, 1.0, COERCE_INT(*(float *)(this + 3624)), COERCE_INT(-1.0));
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0044EE7C) --------------------------------------------------------
char __cdecl sub_44EE7C()
{
  if ( *(_BYTE *)(LODWORD(pGame) + 3616) & 4 )
  {
    sub_45D698(pGame->class04_obj, -1);
    sub_49C550(pClass58_global);
  }
  return 1;
}

//----- (0044F408) --------------------------------------------------------
void *__thiscall sub_44F408(int this, char *a2)
{
  int v2; // eax@1
  void *result; // eax@2
  int v4; // ecx@3
  int v5; // eax@3
  char v6; // [sp-18h] [bp-1Ch]@2
  const CHAR *v7; // [sp-14h] [bp-18h]@2
  int v8; // [sp-10h] [bp-14h]@2
  int v9; // [sp-Ch] [bp-10h]@2
  const char *v10; // [sp-8h] [bp-Ch]@2
  int v11; // [sp-4h] [bp-8h]@2
  int v12; // [sp+0h] [bp-4h]@1

  v12 = this;
  v2 = *(_DWORD *)(this + 8);
  if ( v2 )
  {
    v4 = *(_DWORD *)v2;
    v11 = 0;
    v10 = (const char *)125;
    v9 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\GammaControl.cpp";
    v5 = (*(int (__stdcall **)(int, _DWORD, char *))(v4 + 16))(v2, 0, a2);
    result = CheckHRESULT(&a2, v5, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\GammaControl.cpp", 0x7Du, 0);
  }
  else
  {
    v11 = 120;
    v10 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\GammaControl.cpp";
    a2 = &v6;
    sub_40E2C8(&v6, "Gamma control not active", (int)((char *)&a2 + 3));
    result = sub_467834(&v12, v6, v7, v8, v9, v10, v11);
  }
  return result;
}

//----- (0044F45B) --------------------------------------------------------
int __thiscall sub_44F45B(int this, int a2)
{
  int v2; // esi@1
  double v3; // st7@2
  signed __int64 v4; // qax@4
  signed int v6; // [sp+Ch] [bp-4h]@1

  v6 = 0;
  v2 = a2 + 512;
  do
  {
    v3 = (double)v6 * 0.003921568859368563 * *(float *)(this + 3084);
    if ( v3 >= 1.0 || (v4 = (signed __int64)(v3 * 65535.0), (_DWORD)v4 > 65535) )
      goto LABEL_13;
    if ( (_DWORD)v4 < 0 )
    {
      LODWORD(v4) = 0;
      goto LABEL_9;
    }
    if ( (_DWORD)v4 > 65535 )
LABEL_13:
      LODWORD(v4) = 65535;
LABEL_9:
    ++v6;
    *(_WORD *)(v2 + 512) = v4;
    *(_WORD *)v2 = v4;
    *(_WORD *)(v2 - 512) = v4;
    v2 += 2;
  }
  while ( v6 < 256 );
  return v4;
}

//----- (0044F57C) --------------------------------------------------------
int __fastcall sub_44F57C(int a1, int a2, int a3, signed int a4, int a5)
{
  int v5; // ebx@1
  int v6; // esi@1
  int result; // eax@2
  char v8; // zf@5
  int v9; // eax@9
  int v10; // edx@9
  int v11; // edi@9
  int v12; // eax@9
  int v13; // ecx@9
  int v14; // eax@14
  int v15; // ecx@14
  int v16; // eax@19
  int v17; // ecx@19
  unsigned __int8 v18; // zf@27
  char v19; // sf@27
  unsigned __int8 v20; // of@27
  int v21; // esi@31
  int v22; // eax@32
  signed int v23; // edx@32
  int v24; // ecx@32
  int v25; // esi@35
  int v26; // edx@36
  int v27; // ecx@36
  signed int v28; // edi@36
  signed __int16 v29; // ax@47
  signed int v30; // eax@48
  int v31; // edi@48
  int v32; // eax@50
  __int16 v33; // cx@50
  __int16 v34; // ax@50
  __int16 v35; // ax@50
  int v36; // eax@50
  int v37; // edi@50
  int v38; // eax@50
  int v39; // eax@50
  int v40; // eax@51
  int v41; // eax@52
  int v42; // edi@52
  char v43; // [sp-18h] [bp-100h]@60
  int v44; // [sp-14h] [bp-FCh]@50
  void *v45; // [sp-10h] [bp-F8h]@50
  signed int v46; // [sp-Ch] [bp-F4h]@50
  const char *v47; // [sp-8h] [bp-F0h]@13
  signed int v48; // [sp-4h] [bp-ECh]@9
  char Str; // [sp+Ch] [bp-DCh]@60
  char Str2; // [sp+2Ch] [bp-BCh]@29
  char v51; // [sp+A4h] [bp-44h]@52
  void *Src; // [sp+A8h] [bp-40h]@50
  int v53; // [sp+ACh] [bp-3Ch]@47
  char Source; // [sp+B0h] [bp-38h]@20
  int v55; // [sp+D0h] [bp-18h]@34
  int v56; // [sp+D4h] [bp-14h]@34
  int v57; // [sp+D8h] [bp-10h]@32
  int v58; // [sp+DCh] [bp-Ch]@32
  int v59; // [sp+E0h] [bp-8h]@8
  int v60; // [sp+E4h] [bp-4h]@1
  int v61; // [sp+F0h] [bp+8h]@32
  __int16 v62; // [sp+F0h] [bp+8h]@50
  int v63; // [sp+F0h] [bp+8h]@50
  int v64; // [sp+F0h] [bp+8h]@50
  int v65; // [sp+F0h] [bp+8h]@50
  int v66; // [sp+F0h] [bp+8h]@52
  int v67; // [sp+F0h] [bp+8h]@53
  int v68; // [sp+F0h] [bp+8h]@54
  char *v69; // [sp+F0h] [bp+8h]@60

  v60 = 0;
  v6 = a1;
  v5 = a2;
  if ( dword_6BE360 == 1 )
    result = dword_6A12C4;
  else
    result = dword_6BE360 == 2 ? dword_6BE698 : 0;
  if ( result )
  {
    v8 = (*(_BYTE *)(a2 + 18) & 1) == 0;
  }
  else
  {
    result = *(_BYTE *)(a2 + 18) & 1;
    v8 = (_BYTE)result == 1;
  }
  if ( !v8 )
  {
    result = *(_WORD *)(a2 + 16) - 1;
    v59 = 1;
    switch ( result )
    {
      case 0:
        v11 = *(_BYTE *)(a1 + 53);
        v12 = rand();
        v13 = *(_BYTE *)(v6 + 54);
        v48 = *(_DWORD *)(v6 + 8);
        v10 = v12 % (v13 - v11 + 1);
        v9 = *(_BYTE *)(v6 + 52);
        goto LABEL_20;
      case 3:
        v48 = *(_DWORD *)(a1 + 8);
        goto LABEL_13;
      case 4:
        v48 = *(_DWORD *)(a1 + 12);
        goto LABEL_13;
      case 5:
        v48 = *(_DWORD *)(a1 + 16);
LABEL_13:
        v47 = "%s A";
        goto LABEL_25;
      case 1:
        v11 = *(_BYTE *)(a1 + 56);
        v14 = rand();
        v15 = *(_BYTE *)(v6 + 57);
        v48 = *(_DWORD *)(v6 + 12);
        v10 = v14 % (v15 - v11 + 1);
        v9 = *(_BYTE *)(v6 + 55);
        goto LABEL_20;
      case 6:
        v48 = *(_DWORD *)(a1 + 8);
        goto LABEL_18;
      case 7:
        v48 = *(_DWORD *)(a1 + 12);
        goto LABEL_18;
      case 8:
        v48 = *(_DWORD *)(a1 + 16);
LABEL_18:
        v47 = "%s B";
        goto LABEL_25;
      case 2:
        v11 = *(_BYTE *)(a1 + 59);
        v16 = rand();
        v17 = *(_BYTE *)(v6 + 60);
        v48 = *(_DWORD *)(v6 + 16);
        v10 = v16 % (v17 - v11 + 1);
        v9 = *(_BYTE *)(v6 + 58);
LABEL_20:
        v60 = v9;
        v59 = v11 + v10;
        result = (int)strcpy(&Source, (const char *)v48);
        goto LABEL_26;
      case 9:
        v48 = *(_DWORD *)(a1 + 8);
        goto LABEL_24;
      case 10:
        v48 = *(_DWORD *)(a1 + 12);
        goto LABEL_24;
      case 11:
        v48 = *(_DWORD *)(a1 + 16);
LABEL_24:
        v47 = "%s C";
LABEL_25:
        result = sprintfex(&Source, v47, v48);
LABEL_26:
        if ( Source == 48 )
          return result;
        compile_error;//v20 = __SETO__(a3 + v60, 4);
        v18 = a3 + v60 == 4;
        v19 = a3 + v60 - 4 < 0;
        v60 += a3;
        if ( !((unsigned __int8)(v19 ^ v20) | v18) )
          v60 = 4;
        strcpy(&Str2, &Source);
        if ( a4 )
          v59 = a4;
        v21 = v59;
        result = v59 + uNumActors;
        if ( (signed int)(v59 + uNumActors) >= 500 )
          return result;
        v24 = *(_DWORD *)v5;
        v23 = *(_DWORD *)(v5 + 4);
        v22 = *(_DWORD *)(v5 + 8);
        v57 = 0;
        v58 = v24;
        a4 = v23;
        v61 = v22;
        if ( dword_6BE360 == 1 )
          v57 = sub_49AC17((int)byte_6BE3C8, v24, v23, v22);
        v56 = 0;
        result = (((dword_6BE360 != 2) - 1) & 0x40) + 64;
        v55 = (((dword_6BE360 != 2) - 1) & 0x40) + 64;
        if ( v21 <= 0 )
          return result;
        break;
      default:
        return result;
    }
    do
    {
      v25 = (int)((char *)pActors + 836 * uNumActors);
      sub_459671((int)((char *)pActors + 836 * uNumActors));
      if ( v60 )
      {
        v26 = rand() % 100;
        v28 = 3;
        v27 = word_4E8152[3 * v60];
        if ( v26 >= v27 )
        {
          if ( v26 < v27 + word_4E8152[3 * v60 + 1] )
            v28 = 2;
        }
        else
        {
          v28 = 1;
        }
        if ( v28 == 1 )
        {
          v48 = (signed int)&Source;
          v47 = "%s A";
        }
        else
        {
          if ( v28 == 2 )
          {
            v48 = (signed int)&Source;
            v47 = "%s B";
          }
          else
          {
            if ( v28 != 3 )
              goto LABEL_58;
            v48 = (signed int)&Source;
            v47 = "%s C";
          }
        }
        sprintfex(&Str2, v47, v48);
      }
      v29 = sub_44FA08(monster_list, &Str2);
      v53 = v29;
      v48 = (signed int)&Str2;
      if ( v29 == -1 )
      {
        sprintfex(&Str, "Can't create random monster: '%s'! See MapStats.txt and Monsters.txt!", v48);
        v48 = 216;
        v47 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Generate.cpp";
        v69 = &v43;
        sub_40E2C8(&v43, &Str, (int)((char *)&a3 + 3));
        return (int)sub_466D09(&a4, *(int *)&v43, v44, (int)v45, v46, v47, v48);
      }
      v31 = monster_list[1] + 152 * v29;
      v30 = sub_4563FF(pMonsterStats->pMonsterInfos, (const char *)v48);
      if ( !v30 )
        v30 = 1;
      Src = &pMonsterStats->pMonsterInfos[v30];
      strcpy((char *)v25, *(const char **)Src);
      v46 = 88;
      v45 = Src;
      v33 = *((_WORD *)Src + 32);
      v44 = v25 + 44;
      *(_WORD *)(v25 + 40) = v33;
      memcpy((void *)v44, v45, v46);
      *(_WORD *)(v25 + 134) = v53 + 1;
      *(_WORD *)(v25 + 136) = *(_WORD *)(v31 + 2);
      *(_WORD *)(v25 + 138) = *(_WORD *)v31;
      *(_WORD *)(v25 + 140) = *(_WORD *)(v31 + 4);
      v34 = v58;
      *(_WORD *)(v25 + 162) = v58;
      *(_WORD *)(v25 + 142) = v34;
      v35 = a4;
      *(_WORD *)(v25 + 174) = 256;
      *(_WORD *)(v25 + 164) = v35;
      *(_WORD *)(v25 + 144) = v35;
      v48 = 0;
      *(_WORD *)(v25 + 166) = v62;
      *(_WORD *)(v25 + 146) = v62;
      *(_WORD *)(v25 + 158) = v57;
      *(_DWORD *)(v25 + 708) = *(_DWORD *)(v5 + 20);
      sub_45959A(v25, v48);
      *(_BYTE *)(v25 + 61) = 0;
      v36 = rand();
      v37 = v36 % 2048;
      v38 = class59_SinCos(pClass59_global, v36 % 2048);
      a4 = v38;
      v63 = (unsigned __int64)(v38 * v55) >> 16;
      v58 = v63 + *(_DWORD *)v5;
      v39 = class59_SinCos(pClass59_global, v37 - pClass59_global->uNumTableEntries);
      a4 = v39;
      v64 = (unsigned __int64)(v39 * v55) >> 16;
      a4 = v64 + *(_DWORD *)(v5 + 4);
      v32 = *(_DWORD *)(v5 + 8);
      v65 = *(_DWORD *)(v5 + 8);
      if ( dword_6BE360 != 2 )
      {
        v40 = sub_49AC17((int)byte_6BE3C8, v58, a4, v32);
        if ( v40 != v57
          || (v41 = sub_46CEC3(v58, a4, v66, v40, (int)&v51), v42 = v41, v41 == -30000)
          || abs(v41 - v67) > 1024 )
          goto LABEL_58;
        v68 = v42;
      }
      if ( a5 )
        *(_BYTE *)(v25 + 38) |= 8u;
      ++uNumActors;
LABEL_58:
      ++v56;
      result = v56;
    }
    while ( v56 < v59 );
  }
  return result;
}

//----- (0044FA08) --------------------------------------------------------
signed __int16 __thiscall sub_44FA08(void *this, const char *Str1)
{
  int v2; // ebx@1
  void *v3; // esi@1
  int v4; // edi@3
  signed __int16 result; // ax@6

  v2 = 0;
  v3 = this;
  if ( Str1 && *(_DWORD *)this > 0 )
  {
    v4 = 0;
    while ( _strcmpi(Str1, (const char *)(*((_DWORD *)v3 + 1) + v4 + 20)) )
    {
      ++v2;
      v4 += 152;
      if ( v2 >= *(_DWORD *)v3 )
        goto LABEL_6;
    }
    result = v2;
  }
  else
  {
LABEL_6:
    result = -1;
  }
  return result;
}

//----- (0044FA4C) --------------------------------------------------------
int __fastcall sub_44FA4C(int a1, int a2, int a3)
{
  signed int v3; // ecx@6
  int v4; // edx@7
  int result; // eax@13
  signed int v6; // ebx@16
  int v7; // edi@16
  int v8; // esi@16
  char *v9; // ebx@16
  int v10; // edi@16
  __int16 v11; // ax@16
  int v12; // ebx@16
  int v13; // eax@16
  int v14; // ecx@16
  const char *v15; // [sp-4h] [bp-24h]@2
  __int16 v16; // [sp+0h] [bp-20h]@1
  int v17; // [sp+4h] [bp-1Ch]@1
  int v18; // [sp+8h] [bp-18h]@16
  int v19; // [sp+Ch] [bp-14h]@16
  size_t v20; // [sp+10h] [bp-10h]@6
  int v21; // [sp+14h] [bp-Ch]@14
  int v22; // [sp+18h] [bp-8h]@14
  int v23; // [sp+1Ch] [bp-4h]@6

  v16 = a2;
  v17 = a1;
  if ( a2 == 4 )
  {
    v15 = "Elemental Light C";
  }
  else
  {
    if ( a2 == 3 )
      v15 = "Elemental Light B";
    else
      v15 = "Elemental Light A";
  }
  v23 = sub_44FA08(monster_list, v15);
  v3 = 0;
  v20 = uNumActors;
  if ( (signed int)uNumActors > 0 )
  {
    v4 = &pActors[0].word_0000B0;
    while ( *(_WORD *)v4 != 11 )
    {
      ++v3;
      v4 += 836;
      if ( v3 >= (signed int)uNumActors )
        goto LABEL_12;
    }
    v20 = v3;
  }
LABEL_12:
  if ( v20 != uNumActors || (result = uNumActors + 1, (signed int)(uNumActors + 1) < 500) )
  {
    v21 = 0;
    v22 = pParty_global->sPartyPosZ;
    if ( dword_6BE360 == 1 )
      v21 = sub_49AC17((int)byte_6BE3C8, pParty_global->sPartyPosX, pParty_global->sPartyPosY, pParty_global->sPartyPosZ);
    v8 = (int)((char *)pActors + 836 * v20);
    //v9 = (char *)&unk_5CCE98 + 88 * v23;
    v9 = &pMonsterStats->pMonsterInfos[v23 + 1];
    v19 = (((dword_6BE360 != 2) - 1) & 0x40) + 64;
    sub_459671(v8);
    v10 = monster_list[1] + 152 * v23;
    strcpy((char *)v8, *(const char **)v9);
    *(_WORD *)(v8 + 40) = *((_WORD *)v9 + 32);
    memcpy((void *)(v8 + 44), v9, 0x58u);
    *(_WORD *)(v8 + 134) = v23 + 1;
    *(_WORD *)(v8 + 136) = *(_WORD *)(v10 + 2);
    *(_WORD *)(v8 + 138) = *(_WORD *)v10;
    v11 = *(_WORD *)(v10 + 4);
    *(_BYTE *)(v8 + 54) = 0;
    *(_BYTE *)(v8 + 57) = 0;
    *(_DWORD *)(v8 + 116) = 0;
    *(_WORD *)(v8 + 140) = v11;
    v12 = rand() % 2048;
    v7 = ((unsigned __int64)(class59_SinCos(pClass59_global, v12) * v19) >> 16) + pParty_global->sPartyPosX;
    v18 = class59_SinCos(pClass59_global, v12 - pClass59_global->uNumTableEntries);
    v23 = (unsigned __int64)(v18 * v19) >> 16;
    v13 = pParty_global->sPartyPosY;
    v14 = (unsigned __int64)(v18 * v19) >> 16;
    *(_WORD *)(v8 + 162) = v7;
    v6 = v14 + v13;
    LOWORD(v13) = v22;
    *(_WORD *)(v8 + 166) = v22;
    *(_WORD *)(v8 + 146) = v13;
    LOWORD(v13) = v21;
    *(_WORD *)(v8 + 142) = v7;
    *(_WORD *)(v8 + 164) = v6;
    *(_WORD *)(v8 + 144) = v6;
    *(_WORD *)(v8 + 174) = 256;
    *(_WORD *)(v8 + 158) = v13;
    sub_45959A(v8, 0);
    *(_BYTE *)(v8 + 61) = 0;
    *(_DWORD *)(v8 + 712) = 9999;
    *(_DWORD *)(v8 + 708) = 0;
    *(_DWORD *)(v8 + 184) = 0;
    *(_WORD *)(v8 + 176) = 17;
    *(_WORD *)(v8 + 160) = 256;
    sub_45976D(v8);
    if ( dword_6BE360 == 2
      || (v22 = pParty_global->sPartyPosZ, result = sub_49AC17((int)byte_6BE3C8, v7, v6, pParty_global->sPartyPosZ), result == v21)
      && (result = sub_46CEC3(v7, v6, v22, result, (int)&v18), result != -30000)
      && (result = abs(result - v22), result <= 1024) )
    {
      if ( v20 == uNumActors )
        ++uNumActors;
      *(_DWORD *)(v8 + 812) = 8 * v17 | 4;
      result = sub_4584E0(
                 v8 + 244,
                 pParty_global->qword_00002C + (signed __int64)((double)(a3 << 7) * 0.03333333507180214),
                 (unsigned __int64)(pParty_global->qword_00002C + (signed __int64)((double)(a3 << 7) * 0.03333333507180214)) >> 32,
                 v16,
                 v17,
                 0,
                 0);
    }
  }
  return result;
}

//----- (0044FD29) --------------------------------------------------------
int __fastcall sub_44FD29(int a1, int a2)
{
  unsigned __int8 v2; // al@1
  int v3; // edi@1
  int v4; // esi@1
  int v5; // edx@2
  int v6; // eax@8
  signed __int64 v7; // qax@10
  int v8; // ecx@10
  signed int v9; // ebx@10
  int v10; // edi@10
  int v11; // esi@10
  int v12; // edi@10
  char *v13; // ebx@10
  int v14; // edi@10
  __int16 v15; // ax@10
  int v16; // eax@10
  int v17; // ebx@10
  int v18; // eax@10
  int v19; // eax@10
  int v20; // eax@12
  int result; // eax@13
  int v22; // eax@13
  int v23; // eax@16
  int v24; // [sp+Ch] [bp-1Ch]@1
  int v25; // [sp+10h] [bp-18h]@8
  int v26; // [sp+14h] [bp-14h]@10
  int v27; // [sp+18h] [bp-10h]@10
  int v28; // [sp+1Ch] [bp-Ch]@8
  int v29; // [sp+20h] [bp-8h]@10
  int v30; // [sp+24h] [bp-4h]@1

  v3 = a1;
  v24 = a2;
  v30 = a1;
  v2 = *(_BYTE *)(a1 + 91);
  v4 = *(_WORD *)(a1 + 104);
  if ( v2 )
  {
    if ( v2 >= 1u )
    {
      if ( v2 <= 3u )
        v4 = v4 + v2 - 1;
    }
  }
  else
  {
    v5 = rand() % 100;
    if ( v5 >= 60 )
    {
      ++v4;
      if ( v5 >= 90 )
        ++v4;
    }
  }
  v6 = *(_WORD *)(v3 + 146);
  v28 = 0;
  v25 = v6;
  if ( dword_6BE360 == 1 )
    v28 = sub_49AC17((int)byte_6BE3C8, *(_WORD *)(v3 + 142), *(_WORD *)(v3 + 144), v6);
  v12 = v4 - 1;
  v11 = (int)((char *)pActors + 836 * uNumActors);
  v27 = (((dword_6BE360 != 2) - 1) & 0x40) + 64;
  v29 = v12;
  //v13 = (char *)&unk_5CCE98 + 88 * v12;
  v13 = &pMonsterStats->pMonsterInfos[v12 + 1];
  sub_459671((int)((char *)pActors + 836 * uNumActors));
  v14 = monster_list[1] + 152 * v12;
  strcpy((char *)v11, *(const char **)v13);
  *(_WORD *)(v11 + 40) = *((_WORD *)v13 + 32);
  memcpy((void *)(v11 + 44), v13, 0x58u);
  *(_WORD *)(v11 + 134) = v29 + 1;
  *(_WORD *)(v11 + 136) = *(_WORD *)(v14 + 2);
  *(_WORD *)(v11 + 138) = *(_WORD *)v14;
  v15 = *(_WORD *)(v14 + 4);
  *(_BYTE *)(v11 + 54) = 0;
  *(_BYTE *)(v11 + 57) = 0;
  *(_DWORD *)(v11 + 116) = 0;
  *(_WORD *)(v11 + 140) = v15;
  v16 = rand();
  v17 = v16 % 2048;
  v18 = class59_SinCos(pClass59_global, v16 % 2048);
  v26 = v18;
  v10 = ((unsigned __int64)(v18 * v27) >> 16) + *(_WORD *)(v30 + 142);
  v19 = class59_SinCos(pClass59_global, v17 - pClass59_global->uNumTableEntries);
  v26 = v19;
  v29 = (unsigned __int64)(v19 * v27) >> 16;
  LOWORD(v19) = v25;
  v9 = v29 + *(_WORD *)(v30 + 144);
  *(_WORD *)(v11 + 166) = v25;
  *(_WORD *)(v11 + 146) = v19;
  LOWORD(v19) = v28;
  *(_WORD *)(v11 + 162) = v10;
  *(_WORD *)(v11 + 142) = v10;
  *(_WORD *)(v11 + 164) = v9;
  *(_WORD *)(v11 + 144) = v9;
  *(_WORD *)(v11 + 174) = 256;
  *(_WORD *)(v11 + 158) = v19;
  sub_45959A(v11, 0);
  v8 = v30;
  *(_BYTE *)(v11 + 61) = 0;
  LODWORD(v7) = *(_DWORD *)(v8 + 712);
  if ( !(_DWORD)v7 )
  {
    v25 = *(_WORD *)(v8 + 96) - 1;
    v7 = (signed __int64)((double)v25 * 0.3333333432674408);
    v8 = v30;
  }
  *(_DWORD *)(v11 + 712) = v7;
  v20 = *(_DWORD *)(v8 + 708);
  *(_DWORD *)(v11 + 184) = 0;
  *(_DWORD *)(v11 + 708) = v20;
  *(_WORD *)(v11 + 176) = 17;
  *(_WORD *)(v11 + 160) = 256;
  sub_45976D(v11);
  if ( dword_6BE360 == 2
    || (v22 = *(_WORD *)(v30 + 146),
        v27 = *(_WORD *)(v30 + 146),
        result = sub_49AC17((int)byte_6BE3C8, v10, v9, v22),
        result == v28)
    && (result = sub_46CEC3(v10, v9, v27, result, (int)&v25), result != -30000)
    && (result = abs(result - v27), result <= 1024) )
  {
    v23 = v30;
    ++uNumActors;
    ++*(_BYTE *)(v23 + 93);
    if ( *(_DWORD *)(v23 + 36) & 0x80000 )
      *(_DWORD *)(v11 + 36) |= 0x80000u;
    result = 8 * v24;
    LOBYTE(result) = 8 * v24 | 3;
    *(_DWORD *)(v11 + 812) = result;
  }
  return result;
}

//----- (0044FFD8) --------------------------------------------------------
int __fastcall sub_44FFD8(int a1, int a2)
{
  int result; // eax@1
  int v3; // ebx@1
  int v4; // esi@1
  int v5; // ebx@1
  int v6; // eax@1
  int v7; // edx@1
  int v8; // eax@1
  int v9; // ecx@1
  int v10; // ebx@1
  int v11; // eax@1
  signed int v12; // ebx@1
  signed __int64 v13; // qtt@1
  int v14; // edx@10
  __int16 v15; // dx@20
  int v16; // ebx@20
  int v17; // ecx@21
  __int16 v18; // ax@24
  int v19; // ST0C_4@27
  signed int v20; // ST08_4@27
  int v21; // ST04_4@27
  int v22; // eax@27
  __int16 v23; // dx@29
  int v24; // ebx@29
  int v25; // ecx@30
  __int16 v26; // ax@33
  signed int v27; // ecx@35
  int v28; // eax@35
  int v29; // esi@35
  __int16 v30; // ax@35
  __int16 v31; // [sp+Ch] [bp-7Ch]@1
  __int16 v32; // [sp+Eh] [bp-7Ah]@25
  int v33; // [sp+10h] [bp-78h]@35
  int v34; // [sp+14h] [bp-74h]@35
  int v35; // [sp+18h] [bp-70h]@35
  __int16 v36; // [sp+22h] [bp-66h]@35
  int v37; // [sp+24h] [bp-64h]@35
  __int16 v38; // [sp+28h] [bp-60h]@35
  __int16 v39; // [sp+2Ah] [bp-5Eh]@35
  int v40; // [sp+30h] [bp-58h]@1
  int v41; // [sp+3Ch] [bp-4Ch]@25
  int v42; // [sp+44h] [bp-44h]@25
  int v43; // [sp+54h] [bp-34h]@35
  int v44; // [sp+58h] [bp-30h]@35
  int v45; // [sp+5Ch] [bp-2Ch]@35
  int v46; // [sp+64h] [bp-24h]@35
  int v47; // [sp+68h] [bp-20h]@35
  int v48; // [sp+7Ch] [bp-Ch]@1
  int v49; // [sp+80h] [bp-8h]@1
  int v50; // [sp+84h] [bp-4h]@1

  v5 = a1;
  v4 = a2;
  sub_404828(&v31);
  sub_402F07((int)&v40);
  v6 = rand();
  v50 = 0;
  v7 = v6 % 100;
  v8 = 2 * (*(_BYTE *)(v5 + 47) + 7 * *(_WORD *)(v4 + 16)) - 14;
  v9 = data_4E7168[v8 + 16];
  v10 = data_4E7168[v8 + 17];
  v48 = v7;
  v49 = v9;
  v11 = rand();
  v12 = v10 - v49 + 1;
  v13 = v11;
  result = v11 / v12;
  v3 = v49 + v13 % v12;
  if ( v3 < 7 )
  {
    if ( v48 < 20 )
      return result;
    if ( v48 >= 60 )
    {
      v19 = *(_DWORD *)(v4 + 8);
      v20 = *(_DWORD *)(v4 + 4);
      v21 = *(_DWORD *)v4;
      v22 = rand();
      return sub_450521(v3, v22 % 27 + 20, v21, v20, v19, 0);
    }
    if ( *(_WORD *)(v4 + 16) == 1 )
    {
      v14 = rand() % 51 + 50;
    }
    else
    {
      if ( *(_WORD *)(v4 + 16) != 2 )
      {
        if ( *(_WORD *)(v4 + 16) == 3 )
        {
          v14 = rand() % 301 + 200;
        }
        else
        {
          if ( *(_WORD *)(v4 + 16) != 4 )
          {
            if ( *(_WORD *)(v4 + 16) == 5 )
            {
              v14 = rand() % 1001 + 1000;
            }
            else
            {
              if ( *(_WORD *)(v4 + 16) != 6 )
              {
LABEL_20:
                v16 = 0;
                v15 = word_5D29F8[24 * v40];
                v31 = word_5D29F8[24 * v40];
                if ( pObjectDescriptionList->uNumObjects <= 0 )
                {
LABEL_24:
                  v18 = 0;
                }
                else
                {
                  v17 = pObjectDescriptionList->pDescriptions + 32;
                  while ( v15 != *(_WORD *)v17 )
                  {
                    ++v16;
                    v17 += 56;
                    if ( v16 >= pObjectDescriptionList->uNumObjects )
                      goto LABEL_24;
                  }
                  v18 = v16;
                }
                v42 |= 1u;
                v32 = v18;
                v41 = v50;
                goto LABEL_35;
              }
              v14 = rand() % 3001 + 2000;
            }
            v40 = 199;
LABEL_19:
            v50 = v14;
            goto LABEL_20;
          }
          v14 = rand() % 501 + 500;
        }
        v40 = 198;
        goto LABEL_19;
      }
      v14 = rand() % 101 + 100;
    }
    v40 = 197;
    goto LABEL_19;
  }
  result = sub_4505CC(&v40);
  if ( !result )
    return result;
  v24 = 0;
  v23 = word_5D29F8[24 * v40];
  v31 = word_5D29F8[24 * v40];
  if ( pObjectDescriptionList->uNumObjects <= 0 )
  {
LABEL_33:
    v26 = 0;
  }
  else
  {
    v25 = pObjectDescriptionList->pDescriptions + 32;
    while ( v23 != *(_WORD *)v25 )
    {
      ++v24;
      v25 += 56;
      if ( v24 >= pObjectDescriptionList->uNumObjects )
        goto LABEL_33;
    }
    v26 = v24;
  }
  v32 = v26;
  sub_402F07((int)&v40);
LABEL_35:
  v27 = *(_DWORD *)(v4 + 4);
  v28 = *(_DWORD *)v4;
  v29 = *(_DWORD *)(v4 + 8);
  v34 = v27;
  v37 = 0;
  v36 = 0;
  v35 = v29;
  v33 = v28;
  v45 = 0;
  v44 = 0;
  v43 = 0;
  v30 = sub_49AC17((int)byte_6BE3C8, v28, v27, v29);
  v47 = 0;
  v46 = 0;
  v39 = 0;
  v38 = v30;
  return sub_42F5ED((int)&v31, 0, 0, 0, 0);
}

//----- (00450521) --------------------------------------------------------
signed int __fastcall sub_450521(int a1, signed int a2, int a3, signed int a4, int a5, __int16 a6)
{
  __int16 v6; // cx@1
  int v7; // edi@1
  int v8; // edi@1
  signed int v9; // esi@1
  int v10; // edx@2
  __int16 v11; // ax@5
  __int16 v13; // [sp+8h] [bp-70h]@1
  __int16 v14; // [sp+Ah] [bp-6Eh]@6
  int v15; // [sp+Ch] [bp-6Ch]@6
  int v16; // [sp+10h] [bp-68h]@6
  int v17; // [sp+14h] [bp-64h]@6
  __int16 v18; // [sp+1Eh] [bp-5Ah]@6
  __int16 v19; // [sp+22h] [bp-56h]@6
  __int16 v20; // [sp+24h] [bp-54h]@6
  __int16 v21; // [sp+26h] [bp-52h]@6
  int Dst; // [sp+2Ch] [bp-4Ch]@1

  v8 = a1;
  v9 = a2;
  sub_404828(&v13);
  sub_456620(pClass40, v8, v9, (int)&Dst);
  v7 = 0;
  v6 = word_5D29F8[24 * Dst];
  v13 = word_5D29F8[24 * Dst];
  if ( pObjectDescriptionList->uNumObjects <= 0 )
  {
LABEL_5:
    v11 = 0;
  }
  else
  {
    v10 = pObjectDescriptionList->pDescriptions + 32;
    while ( v6 != *(_WORD *)v10 )
    {
      ++v7;
      v10 += 56;
      if ( v7 >= pObjectDescriptionList->uNumObjects )
        goto LABEL_5;
    }
    v11 = v7;
  }
  v14 = v11;
  v16 = a4;
  v15 = a3;
  v17 = a5;
  v18 = a6;
  v19 = 0;
  v20 = sub_49AC17((int)byte_6BE3C8, a3, a4, a5);
  v21 = 0;
  return sub_42F5ED((int)&v13, 0, 0, 0, 0);
}

//----- (004505CC) --------------------------------------------------------
signed int __thiscall sub_4505CC(void *this)
{
  int v1; // eax@1
  int v2; // edi@1
  signed int v3; // esi@1
  signed int result; // eax@6
  int v5[32]; // [sp+8h] [bp-A0h]@3
  char Dst; // [sp+88h] [bp-20h]@1

  v2 = (int)this;
  memset(&Dst, 0, 0x20u);
  v3 = 0;
  v1 = 500;
  do
  {
    if ( !pParty_global->byte_0005C6[v1] )
      v5[v3++] = v1;
    ++v1;
  }
  while ( v1 < 529 );
  sub_402F07(v2);
  if ( v3 )
  {
    *(_DWORD *)v2 = v5[rand() % v3];
    sub_456D17(pClass40, v2);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0045063B) --------------------------------------------------------
int __fastcall sub_45063B(int a1, int a2)
{
  signed int v2; // edi@1
  int v3; // esi@2
  signed __int64 v4; // qax@3
  int result; // eax@8
  int v6; // edi@11
  int v7; // edi@11
  int v8; // ebx@11
  int v9; // ebx@12
  int v10; // eax@12
  char v11; // zf@16
  int v12; // eax@20
  int v13; // edi@20
  int v14; // eax@20
  int v15; // ebx@20
  int v16; // eax@20
  int v17; // eax@20
  int v18; // eax@21
  int v19; // [sp+Ch] [bp-38h]@1
  int v20; // [sp+10h] [bp-34h]@11
  int v21; // [sp+14h] [bp-30h]@11
  __int16 v22; // [sp+1Ch] [bp-28h]@11
  int v23; // [sp+24h] [bp-20h]@11
  int v24; // [sp+28h] [bp-1Ch]@1
  int v25; // [sp+2Ch] [bp-18h]@3
  int v26; // [sp+30h] [bp-14h]@11
  int v27; // [sp+34h] [bp-10h]@1
  int v28; // [sp+38h] [bp-Ch]@10
  int v29; // [sp+3Ch] [bp-8h]@11
  int v30; // [sp+40h] [bp-4h]@11

  v24 = a1;
  v27 = a2;
  sub_448DD6((int)&v19);
  v2 = 0;
  if ( (signed int)uNumActors <= 0 )
    goto LABEL_8;
  v3 = (int)pActors;
  while ( 1 )
  {
    v25 = *(_WORD *)(v3 + 96) - 1;
    v4 = (signed __int64)((double)v25 * *(double *)&byte_4D8410[640]);
    if ( (_DWORD)v4 != 40 )
    {
      if ( (_DWORD)v4 != 41 && (_DWORD)v4 != 44 && sub_40894B(v3) )
        break;
    }
    ++v2;
    v3 += 836;
    if ( v2 >= (signed int)uNumActors )
      goto LABEL_8;
  }
  if ( dword_6BE360 == 2 )
  {
    v25 = 0;
    v28 = 0;
    while ( 1 )
    {
      ++v28;
      v7 = rand() % 1024 + 512;
      v8 = rand() % pClass59_global->dword_001868;
      v23 = class59_SinCos(pClass59_global, v8);
      v26 = (unsigned __int64)(v23 * v7) >> 16;
      v19 = pParty_global->sPartyPosX + v26;
      v23 = class59_SinCos(pClass59_global, v8 - pClass59_global->uNumTableEntries);
      v26 = (unsigned __int64)(v23 * v7) >> 16;
      v6 = 0;
      v22 = v27;
      v20 = v26 + pParty_global->sPartyPosY;
      v21 = pParty_global->sPartyPosZ;
      v29 = 0;
      v30 = 0;
      v21 = sub_46D49E(v19, v26 + pParty_global->sPartyPosY, pParty_global->sPartyPosZ, 0, (int)&v29, (int)&v30, 0);
      v26 = 0;
      if ( pClass51_global->uNumBModels > 0 )
      {
        while ( 1 )
        {
          v9 = abs(v20 - *(_DWORD *)(v6 + pClass51_global->pBModels + 176));
          v10 = abs(v19 - *(_DWORD *)(v6 + pClass51_global->pBModels + 172));
          if ( sub_4621DA(v10, v9, 0) < *(_DWORD *)(v6 + pClass51_global->pBModels + 184) + 256 )
            break;
          ++v26;
          v6 += 188;
          if ( v26 >= pClass51_global->uNumBModels )
            goto LABEL_16;
        }
        v25 = 1;
      }
LABEL_16:
      v11 = v28 == 100;
      if ( v28 >= 100 )
        break;
      if ( v25 )
      {
        v11 = v28 == 100;
        break;
      }
    }
  }
  else
  {
    v29 = 0;
    v25 = sub_49AC17((int)byte_6BE3C8, pParty_global->sPartyPosX, pParty_global->sPartyPosY, pParty_global->sPartyPosZ);
    do
    {
      ++v29;
      v13 = rand() % 512 + 256;
      v14 = rand();
      v15 = v14 % pClass59_global->dword_001868;
      v16 = class59_SinCos(pClass59_global, v14 % pClass59_global->dword_001868);
      v23 = v16;
      v26 = (unsigned __int64)(v16 * v13) >> 16;
      v19 = pParty_global->sPartyPosX + v26;
      v17 = class59_SinCos(pClass59_global, v15 - pClass59_global->uNumTableEntries);
      v23 = v17;
      v26 = (unsigned __int64)(v17 * v13) >> 16;
      v20 = v26 + pParty_global->sPartyPosY;
      v21 = pParty_global->sPartyPosZ;
      v22 = v27;
      v12 = sub_49AC17((int)byte_6BE3C8, v19, v26 + pParty_global->sPartyPosY, pParty_global->sPartyPosZ);
      if ( v12 == v25 )
      {
        v18 = sub_46CEC3(v19, v20, v21, v12, (int)&v28);
        v21 = v18;
        if ( v18 != -30000 )
        {
          if ( abs(v18 - pParty_global->sPartyPosZ) <= 1024 )
            break;
        }
      }
    }
    while ( v29 < 100 );
    v11 = v29 == 100;
  }
  if ( v11 )
  {
LABEL_8:
    result = 0;
  }
  else
  {
    sub_44F57C(v24, (int)&v19, 0, 0, 1);
    result = v27;
  }
  return result;
}

//----- (00450929) --------------------------------------------------------
int __thiscall sub_450929(void *this)
{
  signed int v1; // eax@1
  void *v2; // esi@1
  int v3; // eax@5
  int v4; // eax@6
  int v5; // eax@7
  int v6; // eax@8
  int v7; // eax@9
  int result; // eax@14
  int v9; // eax@18
  int v10; // eax@19
  int v11; // eax@20
  int v12; // eax@21
  int v13; // eax@22

  v2 = this;
  rand();
  v1 = *(_WORD *)v2;
  if ( v1 > 208 )
  {
    switch ( v1 )
    {
      case 209:
        result = rand() % 7 + 183;
        break;
      case 210:
        result = 150;
        break;
      case 211:
        result = 151;
        break;
      case 212:
        result = 152;
        break;
      case 213:
        result = 153;
        break;
      case 214:
        result = 154;
        break;
      case 215:
        result = 155;
        break;
      case 216:
        result = 156;
        break;
      case 217:
        result = 157;
        break;
      case 218:
        result = 158;
        break;
      case 219:
        result = 159;
        break;
      case 220:
        result = 160;
        break;
      case 221:
        result = 161;
        break;
      default:
        goto LABEL_45;
    }
  }
  else
  {
    if ( v1 == 208 )
    {
      result = rand() % 7 + 176;
    }
    else
    {
      if ( v1 > 24 )
      {
        v9 = v1 - 34;
        if ( !v9 )
          return rand() % 6 + 4;
        v10 = v9 - 150;
        if ( !v10 )
          return 33;
        v11 = v10 - 3;
        if ( !v11 || (v12 = v11 - 3, !v12) )
          return 37;
        v13 = v12 - 16;
        if ( !v13 )
          return rand() % 7 + 162;
        if ( v13 == 1 )
          return rand() % 7 + 169;
      }
      else
      {
        if ( v1 == 24 )
          return 36;
        v3 = v1 - 4;
        if ( !v3 )
          return 16;
        v4 = v3 - 1;
        if ( !v4 )
          return 32;
        v5 = v4 - 1;
        if ( !v5 )
          return rand() % 4 + 12;
        v6 = v5 - 5;
        if ( !v6 )
          return 34;
        v7 = v6 - 2;
        if ( !v7 )
          return 17;
        if ( v7 == 1 )
          return 18;
      }
LABEL_45:
      result = 0;
    }
  }
  return result;
}

//----- (00450AAA) --------------------------------------------------------
void *__cdecl sub_450AAA()
{
  void *result; // eax@1
  signed int v1; // ebx@1
  signed int v2; // edi@1
  int v3; // esi@2

  v2 = 0;
  result = memset(global_5E4C90.byte_000000 + 75, 0, 125);
  v1 = 0;
  if ( (signed int)dword_69ADD0 > 0 )
  {
    v3 = (int)array_6836D0;
    do
    {
      if ( !*(_WORD *)(v3 + 22) )
      {
        result = (void *)sub_44C2F4((void *)v3);
        if ( result )
        {
          if ( v2 < 124 )
          {
            *(_WORD *)(v3 + 28) = v2 + 75;
            result = (void *)sub_450929((void *)v3);
            global_5E4C90.byte_000000[v2++ + 75] = (char)result;
          }
        }
      }
      ++v1;
      v3 += 32;
    }
    while ( v1 < (signed int)dword_69ADD0 );
  }
  return result;
}

//----- (00450B0A) --------------------------------------------------------
signed int __fastcall sub_450B0A(int a1)
{
  int v1; // ebx@1
  signed int result; // eax@2
  unsigned int v3; // ecx@5
  int v4; // esi@5
  char *v5; // edi@5
  void *v6; // eax@7
  char Dest; // [sp+4h] [bp-350h]@5
  __int16 v8; // [sp+2Ch] [bp-328h]@5
  char Dst; // [sp+30h] [bp-324h]@5
  __int16 v10; // [sp+8Ah] [bp-2CAh]@5
  __int16 v11; // [sp+8Ch] [bp-2C8h]@5
  __int16 v12; // [sp+8Eh] [bp-2C6h]@5
  __int16 v13; // [sp+90h] [bp-2C4h]@5
  __int16 v14; // [sp+92h] [bp-2C2h]@5
  __int16 v15; // [sp+94h] [bp-2C0h]@5
  __int16 v16; // [sp+96h] [bp-2BEh]@5
  __int16 v17; // [sp+A6h] [bp-2AEh]@5
  __int16 v18; // [sp+A8h] [bp-2ACh]@5
  __int16 v19; // [sp+AAh] [bp-2AAh]@5
  __int16 v20; // [sp+B2h] [bp-2A2h]@5
  int v21; // [sp+348h] [bp-Ch]@5
  int v22; // [sp+34Ch] [bp-8h]@5
  int v23; // [sp+350h] [bp-4h]@5

  v1 = a1;
  if ( uNumActors == 499 )
  {
    result = 0;
  }
  else
  {
    if ( a1 >= monster_list[0] )
      v1 = 0;
    v4 = monster_list[1] + 152 * v1;
    //v5 = (char *)&unk_5CCE98 + 88 * v1;
    v5 = &pMonsterStats->pMonsterInfos[v1 + 1];
    sub_41F4C1(&Dest);
    memset(&Dest, 0, 0x344u);
    strcpy(&Dest, *(const char **)v5);
    v8 = *((_WORD *)v5 + 32);
    //memcpy(&Dst, (char *)&unk_5CCE98 + 88 * v1, 0x58u);
    memcpy(&Dst, &pMonsterStats->pMonsterInfos[v1 + 1], sizeof(struct MonsterInfo));
    v10 = v1 + 1;
    v11 = *(_WORD *)(v4 + 2);
    v12 = *(_WORD *)v4;
    v13 = *(_WORD *)(v4 + 4);
    sub_43AA99(200, pParty_global->sRotationY, 0, pParty_global->sPartyPosX, pParty_global->sPartyPosY, pParty_global->sPartyPosZ, (int)&v21, (int)&v23, (int)&v22);
    v17 = v21;
    v14 = v21;
    v20 = 256;
    v18 = v23;
    v15 = v23;
    v19 = v22;
    v16 = v22;
    sub_450C8B(pClass17_Sprites_LOD);
    sub_48A379(&class35_obj);
    v3 = uNumActors - 1;
    if ( dword_5C6DF8 == 1 )
    {
      dword_5C6DF8 = 0;
      v3 = uNumActors++;
    }
    v6 = (char *)pActors + 836 * v3;
    memcpy(v6, &Dest, 0x344u);
    sub_45959A((int)v6, 1);
    result = 1;
  }
  return result;
}

//----- (00450C8B) --------------------------------------------------------
int __thiscall sub_450C8B(int this)
{
  int result; // eax@1
  int v2; // esi@1
  int v3; // edi@1

  v2 = this + 60572;
  v3 = this + 60584;
  sub_450CA9(this, *(_DWORD *)(this + 60584), *(_DWORD *)(this + 60572));
  result = *(_DWORD *)v3;
  *(_DWORD *)v2 = *(_DWORD *)v3;
  return result;
}

//----- (00450CA9) --------------------------------------------------------
int __thiscall sub_450CA9(int this, int a2, int a3)
{
  int result; // eax@1
  int v4; // edi@1
  int v5; // ebx@3
  int v6; // esi@3
  int v8; // edi@7
  int v9; // esi@7
  int v10; // [sp+10h] [bp+8h]@3

  result = a2;
  v4 = this;
  if ( *(_DWORD *)(this + 60592) )
  {
    if ( a2 < a3 )
    {
      v6 = 40 * a2;
      v5 = 40 * a2 + this + 572;
      v10 = a3 - a2;
      do
      {
        sub_450D1D(v5);
        result = sub_450D68((void *)(v6 + *(_DWORD *)(v4 + 60592)));
        v6 += 40;
        v5 += 40;
      }
      while ( v10-- != 1 );
    }
  }
  else
  {
    if ( a2 < a3 )
    {
      v9 = this + 40 * a2 + 572;
      v8 = a3 - a2;
      do
      {
        result = sub_450D1D(v9);
        v9 += 40;
        --v8;
      }
      while ( v8 );
    }
  }
  return result;
}

//----- (00450D1D) --------------------------------------------------------
int __thiscall sub_450D1D(int this)
{
  int v1; // esi@1
  int result; // eax@3

  v1 = this;
  if ( !(*(_BYTE *)(this + 27) & 4) )
  {
    class23_DeleteBuffer(class23_instance, *(_DWORD *)(this + 36));
    class23_DeleteBuffer(class23_instance, *(_DWORD *)(v1 + 32));
  }
  result = 0;
  *(_WORD *)(v1 + 26) = 0;
  *(_DWORD *)(v1 + 36) = 0;
  *(_DWORD *)(v1 + 32) = 0;
  *(_BYTE *)v1 = 0;
  *(_WORD *)(v1 + 22) = 0;
  *(_WORD *)(v1 + 20) = 0;
  *(_WORD *)(v1 + 24) = 0;
  *(_WORD *)(v1 + 18) = 0;
  *(_WORD *)(v1 + 16) = 0;
  *(_DWORD *)(v1 + 12) = 0;
  return result;
}

//----- (00450D68) --------------------------------------------------------
int __thiscall sub_450D68(void *this)
{
  void *v1; // esi@1
  int v2; // eax@3
  int result; // eax@5

  v1 = this;
  if ( *(_DWORD *)this )
    class23_DeleteBuffer(class23_instance, *(_DWORD *)this);
  v2 = *((_DWORD *)v1 + 2);
  if ( v2 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(*((_DWORD *)v1 + 2));
  result = *((_DWORD *)v1 + 3);
  if ( result )
    result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)result + 8))(*((_DWORD *)v1 + 3));
  *(_DWORD *)v1 = 0;
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 3) = 0;
  return result;
}

//----- (00450DA3) --------------------------------------------------------
int __cdecl sub_450DA3()
{
  int result; // eax@2

  if ( dword_6BE360 == 1 )
    result = dword_6A12C4;
  else
    result = dword_6BE360 == 2 ? dword_6BE698 : 0;
  return result;
}

//----- (00450DDE) --------------------------------------------------------
void *__thiscall sub_450DDE(void *this)
{
  void *v2; // esi@1

  v2 = this;
  sub_450DF1(this, L" ", L" ");
  return v2;
}

//----- (00450DF1) --------------------------------------------------------
void *__thiscall sub_450DF1(void *Dst, const void *Src, const void *a3)
{
  void *result; // eax@1
  void *v4; // esi@1
  int v5; // edx@2
  unsigned int v6; // ecx@2
  int v7; // edi@2
  int v8; // edx@8
  unsigned int v9; // ecx@8
  int v10; // edi@8
  int v11; // edx@12
  unsigned int v12; // ecx@12
  int v13; // edi@12
  int v14; // ecx@12
  unsigned int v15; // edx@16
  int v16; // ecx@16
  int v17; // edi@16
  int v18; // ecx@16
  char v19; // zf@20
  int v20; // edx@21
  unsigned int v21; // ecx@21
  int v22; // edi@21
  int v23; // edx@27
  unsigned int v24; // ecx@27
  int v25; // edi@27
  int v26; // edx@31
  unsigned int v27; // ecx@31
  int v28; // edi@31
  int v29; // ecx@31
  int v30; // edx@35
  unsigned int i; // ecx@35
  int v32; // ebx@35
  unsigned int v33; // edi@35
  int v34; // ecx@35
  unsigned int v35; // edx@39
  int v36; // ecx@39
  int v37; // ebx@39
  int v38; // ecx@39

  v4 = Dst;
  memcpy(Dst, Src, 0x20u);
  result = memcpy((char *)v4 + 32, a3, 0x20u);
  LOBYTE(result) = 1;
  if ( *((_BYTE *)v4 + 4) & 1 )
  {
    v6 = *((_DWORD *)v4 + 7);
    v7 = 0;
    v5 = 0;
    while ( !(v6 & 1) )
    {
      ++v7;
      v6 >>= 1;
    }
    do
    {
      v6 >>= 1;
      ++v5;
    }
    while ( v6 & 1 );
    *((_DWORD *)v4 + 16) = 32 - v5 - v7;
  }
  else
  {
    *((_DWORD *)v4 + 16) = 0;
  }
  v9 = *((_DWORD *)v4 + 4);
  v10 = 0;
  v8 = 0;
  while ( !(v9 & 1) )
  {
    ++v10;
    v9 >>= 1;
  }
  do
  {
    v9 >>= 1;
    ++v8;
  }
  while ( v9 & 1 );
  v14 = 24 - v8 - v10;
  v13 = 0;
  *((_DWORD *)v4 + 18) = v14;
  v12 = *((_DWORD *)v4 + 5);
  v11 = 0;
  while ( !(v12 & 1) )
  {
    ++v13;
    v12 >>= 1;
  }
  do
  {
    v12 >>= 1;
    ++v11;
  }
  while ( v12 & 1 );
  v18 = 16 - v11;
  v15 = *((_DWORD *)v4 + 6);
  *((_DWORD *)v4 + 20) = v18 - v13;
  v16 = 0;
  v17 = 0;
  while ( !(v15 & 1) )
  {
    ++v16;
    v15 >>= 1;
  }
  do
  {
    v15 >>= 1;
    ++v17;
  }
  while ( v15 & 1 );
  v19 = (*((_BYTE *)v4 + 36) & 1) == 0;
  *((_DWORD *)v4 + 22) = v16 - v17 + 8;
  if ( v19 )
  {
    *((_DWORD *)v4 + 17) = 0;
  }
  else
  {
    v21 = *((_DWORD *)v4 + 15);
    v22 = 0;
    v20 = 0;
    while ( !(v21 & 1) )
    {
      ++v22;
      v21 >>= 1;
    }
    do
    {
      v21 >>= 1;
      ++v20;
    }
    while ( v21 & 1 );
    *((_DWORD *)v4 + 17) = 32 - v20 - v22;
  }
  v24 = *((_DWORD *)v4 + 12);
  v25 = 0;
  v23 = 0;
  while ( !(v24 & 1) )
  {
    ++v25;
    v24 >>= 1;
  }
  do
  {
    v24 >>= 1;
    ++v23;
  }
  while ( v24 & 1 );
  v29 = 24 - v23 - v25;
  v28 = 0;
  *((_DWORD *)v4 + 19) = v29;
  v27 = *((_DWORD *)v4 + 13);
  v26 = 0;
  while ( !(v27 & 1) )
  {
    ++v28;
    v27 >>= 1;
  }
  do
  {
    v27 >>= 1;
    ++v26;
  }
  while ( v27 & 1 );
  v32 = 0;
  v34 = 16 - v26 - v28;
  v33 = *((_DWORD *)v4 + 14);
  *((_DWORD *)v4 + 21) = v34;
  v30 = 0;
  for ( i = v33; !(i & 1); i >>= 1 )
    ++v32;
  do
  {
    i >>= 1;
    ++v30;
  }
  while ( i & 1 );
  v38 = 32 - v30;
  v35 = v33;
  *((_DWORD *)v4 + 23) = v38 - v32;
  v36 = 0;
  v37 = 0;
  while ( !(v35 & 1) )
  {
    ++v36;
    v35 >>= 1;
  }
  do
  {
    v35 >>= 1;
    ++v37;
  }
  while ( v35 & 1 );
  *((_DWORD *)v4 + 23) = v36 - v37 + 8;
  return result;
}

//----- (00450F55) --------------------------------------------------------
unsigned int __thiscall sub_450F55(int this, int a2)
{
  int v2; // ebx@1

  v2 = a2 & dword_4E82C0;
  if ( *(_BYTE *)(this + 36) & 1 )
    v2 = (unsigned int)v2 >> *(_DWORD *)(this + 68);
  return v2 & *(_DWORD *)(this + 60) | *(_DWORD *)(this + 48) & ((a2 & (unsigned int)dword_4E82B4) >> *(_DWORD *)(this + 76)) | *(_DWORD *)(this + 52) & ((a2 & (unsigned int)dword_4E82B8) >> *(_DWORD *)(this + 84)) | *(_DWORD *)(this + 56) & ((a2 & (unsigned int)dword_4E82BC) >> *(_DWORD *)(this + 92));
}

//----- (00450FB1) --------------------------------------------------------
int __thiscall sub_450FB1(int this, int a2)
{
  int v2; // ebx@2

  if ( *(_DWORD *)(this + 4) & 1 )
    v2 = a2 & *(_DWORD *)(this + 28);
  else
    v2 = 0;
  if ( *(_DWORD *)(this + 4) & 1 )
    v2 <<= *(_DWORD *)(this + 64);
  return v2 | ((a2 & *(_DWORD *)(this + 16)) << *(_DWORD *)(this + 72)) | ((a2 & *(_DWORD *)(this + 20)) << *(_DWORD *)(this + 80)) | ((a2 & *(_DWORD *)(this + 24)) << *(_DWORD *)(this + 88));
}