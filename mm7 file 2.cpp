#include <ddraw.h>
//#include <dinput.h>
#include <stdlib.h>
#include "font.h"
#include "AIL.h"
#include "font.h"
#include "classes.h"
#include "data.h"
#include "_audio.h"
#include "_video.h"
#include "FrameTables.h"
#include "GUI.h"
#include "Level.h"
#include "Actor.h"
  #include "_lod.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"






void KeyboardController_ctor(struct KeyboardController *_this)
{
 unsigned int i;

 _this->uLastKeyPressed = 0;

 KeyboardController_InitalizeKeys(_this);
 KeyboardController_ReadKeyMapping(_this);

 for (i = 0; i < 30; ++i)
   GetAsyncKeyState(_this->array_00000C_vkeys[i]);

 dword_506E68 = -1;
}




//----- (0040BCFB) --------------------------------------------------------
char __fastcall sub_40BCFB(int a1, signed int a2)
{
  int *v2; // eax@2
  signed int v3; // edi@2
  int v4; // esi@2
  int v5; // ebx@7
  int v6; // ecx@7
  int v7; // eax@8
  int v8; // ecx@8
  int v9; // esi@8
  int v10; // eax@8
  int v11; // esi@8
  int v12; // eax@8
  signed int v13; // edx@9
  char result; // al@12
  int v15; // eax@12

  if ( a2 <= -1 )
    goto LABEL_16;
  v4 = 0;
  v3 = 0;
  v2 = &dword_50574C[47 * a1];
  do
  {
    if ( *v2 != -1 )
    {
      if ( a2 == v4 )
        break;
      ++v4;
    }
    ++v3;
    ++v2;
  }
  while ( v3 < 10 );
  v6 = v3 + 47 * a1;
  v5 = 4 * v6 + 5265228;
  if ( byte_4DF3D3[108 * dword_50574C[v6]] )
  {
    sub_40DDC9((void *)0x16);
    v9 = dword_4FAA6C;
    v10 = sub_40BB49(dword_4FAA6C);
    v11 = 188 * v9 + 8 * v3;
    v8 = 96 * v3 + *(int *)((char *)&dword_505774 + v11) + (640 - 96 * v10) / (v10 + 1);
    v12 = *(int *)((char *)dword_505778 + v11) + 327;
    dword_4FAA5C = v8;
    dword_4FAA60 = v12;
    v7 = 0;
    compile_error;//if ( !byte_4FAA75 )
    if (1)
    {
      v13 = (signed int)dword_4FAA78;
      do
      {
        if ( *(_DWORD *)v13 == -1 )
          break;
        v13 += 32;
        ++v7;
      }
      while ( v13 < (signed int)&dword_4FABB8 );
    }
    struct_505898.byte_50598E = 1;
    dword_4FAA54 = (dword_4FAA80[8 * v7] - v8) / 10;
    dword_4FAA58 = (dword_4FAA84[8 * v7] - 327) / 10;
    v15 = *(_DWORD *)v5;
    *(_DWORD *)v5 = -1;
    byte_4FAA77 = 0;
    dword_4FAA50 = v15;
    result = 1;
  }
  else
  {
LABEL_16:
    result = 0;
  }
  return result;
}

//----- (0040BE0E) --------------------------------------------------------
char __fastcall sub_40BE0E(int a1, signed int a2)
{
  int v2; // ebp@1
  int v3; // eax@2
  int v4; // ecx@2
  int v5; // edi@2
  char *v6; // esi@2
  char result; // al@8
  int v8; // ebx@8
  int v9; // eax@8
  int v10; // ebx@8
  int v11; // ebp@8
  int v12; // ecx@8
  int v13; // eax@8
  char *v14; // eax@8
  int v15; // ecx@8
  int v16; // ecx@8

  v2 = a1;
  if ( a2 <= -1 )
    goto LABEL_12;
  v4 = 0;
  v6 = &byte_505708[188 * v2];
  v5 = 0;
  v3 = (int)(v6 + 68);
  do
  {
    if ( *(_DWORD *)v3 != -1 )
    {
      if ( a2 == v4 )
        break;
      ++v4;
    }
    ++v5;
    v3 += 4;
  }
  while ( v5 < 10 );
  if ( sub_40BF15(v2, v5) )
  {
    sub_40DDC9((void *)0x17);
    v8 = dword_4FAA6C;
    v9 = sub_40BB49(dword_4FAA6C);
    v10 = 188 * v8 + 8 * v5;
    v11 = v5 + 47 * v2;
    dword_4FAA58 = -30;
    struct_505898.byte_50598E = 1;
    v12 = 96 * v5 + *(int *)((char *)&dword_505774 + v10) + (640 - 96 * v9) / (v9 + 1);
    v13 = *(int *)((char *)dword_505778 + v10) + 327;
    dword_4FAA5C = v12;
    dword_4FAA60 = v13;
    dword_4FAA54 = (272 - v12) / 5;
    v14 = &aBrickShortage[108 * *(_DWORD *)&v6[4 * v5 + 68]];
    *((_DWORD *)v6 + 14) -= v14[40];
    v15 = v14[41];
    *((_DWORD *)v6 + 16) -= v14[42];
    *((_DWORD *)v6 + 15) -= v15;
    v16 = dword_50574C[v11];
    dword_50574C[v11] = -1;
    dword_4FABC0 = v16;
    result = 1;
  }
  else
  {
LABEL_12:
    result = 0;
  }
  return result;
}

//----- (0040BF15) --------------------------------------------------------
char __fastcall sub_40BF15(int a1, int a2)
{
  char result; // al@1
  char *v3; // ecx@1
  char *v4; // esi@1

  v4 = &byte_505708[188 * a1];
  result = 1;
  v3 = &aBrickShortage[108 * *(_DWORD *)&v4[4 * a2 + 68]];
  if ( (signed int)v3[37] > *((_DWORD *)v4 + 11) )
    result = 0;
  if ( (signed int)v3[38] > *((_DWORD *)v4 + 12) )
    result = 0;
  if ( (signed int)v3[39] > *((_DWORD *)v4 + 13) )
    result = 0;
  if ( (signed int)v3[40] > *((_DWORD *)v4 + 14) )
    result = 0;
  if ( (signed int)v3[41] > *((_DWORD *)v4 + 15) )
    result = 0;
  if ( (signed int)v3[42] > *((_DWORD *)v4 + 16) )
    result = 0;
  return result;
}

//----- (0048A7AA) --------------------------------------------------------
void __fastcall sub_48A7AA(float *a1, float *a2, float a3, float a4, float a5, float *a6)
{
  double v6; // st7@2
  double v7; // st6@7
  double v8; // st5@12
  double v9; // st7@15
  double v10; // st7@17
  double v11; // st7@21
  __int16 v12; // fps@21
  unsigned __int8 v13; // c0@21
  unsigned __int8 v14; // c2@21
  float v15; // [sp+14h] [bp+14h]@16

 v6 = max(a3, a4);
 if (v6 < a5)
   v6 = a5;

 v7 = min(a3, a4);
 if (v7 > a5)
   v7 = a5;

 *a6 = v6;

 if ( v6 == 0.0)
   v8 = 0.0;
 else
   v8 = (v6 - v7) / v6;
 *a2 = v8;

  if ( v8 == 0.0)
  {
    v9 = 0.0;
LABEL_23:
    *a1 = v9;
    return;
  }
  v15 = v6 - v7;
  if ( a3 == v6 )
  {
    v10 = (a4 - a5) / v15;
  }
  else
  {
    if ( a4 == v6 )
      v10 = (a5 - a3) / v15 + 2.0;
    else
      v10 = (a3 - a4) / v15 + 4.0;
  }
  *(float *)a1 = v10;
  v11 = *(float *)a1 * 60.0;
  UNDEF(v12);
  *(float *)a1 = v11;

  runtime_warning();//if ( v13 | v14 )  some float comparison
  if (0)
  {
    v9 = v11 + 360.0;
    goto LABEL_23;
  }
}

//----- (00443365) --------------------------------------------------------
int __thiscall sub_443365(struct unnamed_576FE8 *_this)
{
  void *v1; // esi@1
  int v2; // edi@3
  int v3; // eax@4
  signed int v4; // edx@4
  signed int v5; // eax@8
  int v6; // eax@12
  signed int v7; // edi@12
  signed int v8; // eax@16
  char v9; // zf@20
  int result; // eax@21
  int v11; // [sp+4h] [bp-1Ch]@3
  int v12; // [sp+8h] [bp-18h]@3
  signed int v13; // [sp+Ch] [bp-14h]@8
  signed int v14; // [sp+10h] [bp-10h]@2
  signed int v15; // [sp+14h] [bp-Ch]@2
  signed int v16; // [sp+18h] [bp-8h]@2
  signed int v17; // [sp+1Ch] [bp-4h]@2

  v1 = _this;
  sub_443343_GenerateSomeColorTable(_this);
  if ( dword_6BE360 == 1 )
  {
    v16 = 0x40000000;
    v14 = 0x40000000;
    v17 = 0xC0000000;
    v15 = 0xC0000000;
    if ( *(_DWORD *)dword_6BE670 > 0 )
    {
      v2 = dword_6BE670 + 4;
      v11 = *(_DWORD *)dword_6BE670;
      v12 = dword_6BE670 + 4;
      do
      {
        v3 = dword_6BE63C + 6 * *(_WORD *)v2;
        v4 = *(_WORD *)v3;
        if ( v4 < v16 )
          v16 = *(_WORD *)v3;
        if ( v4 > v17 )
          v17 = *(_WORD *)v3;
        v5 = *(_WORD *)(v3 + 2);
        v13 = v5;
        if ( v5 < v14 )
          v14 = v4;
        if ( v5 > v15 )
          v15 = v4;
        v6 = dword_6BE63C + 6 * *(_WORD *)(v2 + 2);
        v7 = *(_WORD *)v6;
        if ( v7 < v16 )
          v16 = v4;
        if ( v7 > v17 )
          v17 = v4;
        v8 = *(_WORD *)(v6 + 2);
        if ( v8 < v14 )
          v14 = v13;
        if ( v8 > v15 )
          v15 = v13;
        v2 = v12 + 12;
        v9 = v11-- == 1;
        v12 += 12;
      }
      while ( !v9 );
    }
    _this->uMinimapZoom = 1024;
    _this->dword_000028 = 10;
    _this->word_000038 = (v16 + v17) / 2;
    _this->word_00003A = (v14 + v15) / 2;
    result = (v14 + v15) / 2;
  }
  else
  {
    _this->word_000038 = 0;
    _this->word_00003A = 0;
    _this->uMinimapZoom = dword_576E2C;
    _this->dword_000028 = dword_576E28;
    result = dword_576E28;
  }
 _this->dword_00002C = 384;
 return result;
}

//----- (00414D24) --------------------------------------------------------
unsigned int __thiscall sub_414D24(void *_this)
{
  unsigned int result; // eax@1
  unsigned int v2; // ebx@1
  unsigned int v3; // edi@1
  void *v4; // esi@1

  v4 = _this;
  v3 = 0xFFE1CD23;
  v2 = 0xFF0F0000;
  result = 0xFFFFFFFF;
  if ( (void *)dword_506E68 == v4 )
  {
    if ( GetTickCount() % 0x3E8 <= 0x1F4 )
      result = v2;
    else
      result = v3;
  }
  else
  {
    if ( *(_BYTE *)((_DWORD)byte_506E6C + (_DWORD)v4) )
      result = dword_507C08;
  }
  return result;
}

//----- (0048F882) --------------------------------------------------------
char __thiscall Player_sub_48F882(void *_this, signed int a2)
{
  signed int v2; // esi@1
  int v3; // eax@9
  int v4; // eax@11
  int v5; // eax@14
  int v6; // eax@19
  int v7; // eax@21
  int v8; // eax@24
  int v9; // eax@26
  int v10; // eax@31
  int v11; // eax@33
  int v12; // eax@36
  int v13; // eax@38
  int v14; // eax@40
  int v15; // eax@42
  int v16; // eax@44
  int v17; // eax@47
  int v18; // eax@49
  int v19; // eax@58
  int v20; // eax@60
  int v21; // eax@62
  int v22; // eax@69
  int v23; // eax@71
  int v24; // eax@73
  int v25; // eax@75
  int v26; // eax@77
  int v27; // eax@79
  int v28; // eax@81
  int v29; // eax@84
  int v30; // eax@126
  int v31; // eax@127
  signed int v33; // [sp-4h] [bp-14h]@13
  signed int v34; // [sp-4h] [bp-14h]@27
  signed int v35; // [sp-4h] [bp-14h]@35
  signed int v36; // [sp-4h] [bp-14h]@68
  void *v37; // [sp+Ch] [bp-4h]@1

  v2 = 0;
  v37 = _this;
  if ( a2 > 30 )
  {
    if ( a2 != 31 )
    {
      if ( a2 == 32 )
      {
        v27 = CheckHiredNPCSpeciality(0x3A);
        if ( v27 )
          v2 = 6;
        v28 = CheckHiredNPCSpeciality(0x39);
        if ( v28 )
          v2 += 6;
        goto LABEL_83;
      }
      if ( a2 == 33 )
      {
        v25 = CheckHiredNPCSpeciality(0xF);
        if ( v25 )
          v2 = 2;
        v26 = CheckHiredNPCSpeciality(0x10);
        if ( v26 )
          v2 += 3;
        goto LABEL_64;
      }
      if ( a2 == 34 )
      {
        v24 = CheckHiredNPCSpeciality(0x33);
        if ( v24 )
          v2 = 8;
        goto LABEL_64;
      }
      if ( a2 == 35 )
      {
        v22 = CheckHiredNPCSpeciality(0x17);
        if ( v22 )
          v2 = 4;
        v23 = CheckHiredNPCSpeciality(0x18);
        if ( v23 )
          v2 += 8;
        goto LABEL_64;
      }
      if ( a2 == 36 )
      {
        v19 = CheckHiredNPCSpeciality(0xD);
        if ( v19 )
          v2 = 10;
        v20 = CheckHiredNPCSpeciality(0xE);
        if ( v20 )
          v2 += 15;
        v21 = CheckHiredNPCSpeciality(4);
        if ( v21 )
          v2 += 5;
        goto LABEL_64;
      }
      goto LABEL_86;
    }
    v29 = CheckHiredNPCSpeciality(0x38);
    if ( !v29 )
      goto LABEL_112;
LABEL_85:
    v2 = 2;
    goto LABEL_86;
  }
  if ( a2 == 30 )
  {
    v18 = CheckHiredNPCSpeciality(0x38);
    if ( !v18 )
      goto LABEL_112;
    v34 = 2;
    goto LABEL_51;
  }
  if ( a2 <= 21 )
  {
    if ( a2 != 21 )
    {
      if ( a2 < 0 )
        goto LABEL_86;
      if ( a2 > 11 )
      {
        if ( a2 <= 15 )
        {
          v6 = CheckHiredNPCSpeciality(0x11);
          if ( v6 )
            v2 = 2;
          v7 = CheckHiredNPCSpeciality(0x12);
          if ( v7 )
            v2 += 3;
          v33 = 19;
        }
        else
        {
          if ( a2 > 18 )
            goto LABEL_86;
          v3 = CheckHiredNPCSpeciality(0x35);
          if ( v3 )
            v2 = 2;
          v4 = CheckHiredNPCSpeciality(0x36);
          if ( v4 )
            v2 += 3;
          v33 = 55;
        }
        v5 = CheckHiredNPCSpeciality(v33);
        if ( v5 )
          v2 += 4;
        if ( *((_BYTE *)v37 + 185) == 31 )
        {
          if ( sub_476387() )
            v2 += 3;
        }
LABEL_86:
        if ( a2 <= 20 )
        {
          if ( a2 == 20 )
          {
            v36 = 42;
          }
          else
          {
            if ( a2 > 15 )
            {
              switch ( a2 )
              {
                case 16:
                  v36 = 38;
                  break;
                case 17:
                  v36 = 39;
                  break;
                case 18:
                  v36 = 40;
                  break;
                default:
                  if ( a2 != 19 )
                    goto LABEL_126;
                  v36 = 41;
                  break;
              }
            }
            else
            {
              switch ( a2 )
              {
                case 15:
                  v36 = 37;
                  break;
                case 5:
                  v36 = 44;
                  break;
                case 8:
                  v36 = 45;
                  break;
                case 12:
                  v36 = 34;
                  break;
                case 13:
                  v36 = 35;
                  break;
                default:
                  if ( a2 != 14 )
                    goto LABEL_126;
                  v36 = 36;
                  break;
              }
            }
          }
          goto LABEL_125;
        }
        if ( a2 <= 32 )
        {
          if ( a2 != 32 )
            goto LABEL_112;
LABEL_83:
          v36 = 20;
          goto LABEL_125;
        }
LABEL_64:
        switch ( a2 )
        {
          case 33:
            v36 = 21;
            break;
          case 34:
            v36 = 17;
            break;
          case 35:
            v36 = 16;
            break;
          default:
            if ( a2 != 36 )
              goto LABEL_126;
            v36 = 46;
            break;
        }
        goto LABEL_125;
      }
      v8 = CheckHiredNPCSpeciality(0x2E);
      if ( !v8 )
        goto LABEL_86;
      goto LABEL_85;
    }
    v9 = CheckHiredNPCSpeciality(0x39);
    if ( !v9 )
      goto LABEL_112;
    v34 = 6;
LABEL_51:
    v2 = v34;
    goto LABEL_112;
  }
  if ( a2 == 22 )
  {
    v14 = CheckHiredNPCSpeciality(0x14);
    if ( v14 )
      v2 = 4;
    v15 = CheckHiredNPCSpeciality(0x15);
    if ( v15 )
      v2 += 6;
    v16 = CheckHiredNPCSpeciality(0x30);
    if ( v16 )
      v2 += 3;
    v35 = 50;
LABEL_47:
    v17 = CheckHiredNPCSpeciality(v35);
    if ( v17 )
      v2 += 8;
    goto LABEL_112;
  }
  if ( a2 != 26 )
  {
    if ( a2 != 29 )
      goto LABEL_86;
    v10 = CheckHiredNPCSpeciality(0x19);
    if ( v10 )
      v2 = 4;
    v11 = CheckHiredNPCSpeciality(0x1A);
    if ( v11 )
      v2 += 6;
    v35 = 51;
    goto LABEL_47;
  }
  v12 = CheckHiredNPCSpeciality(0x16);
  if ( v12 )
    v2 = 6;
  v13 = CheckHiredNPCSpeciality(0x2F);
  if ( v13 )
    v2 += 5;
LABEL_112:
  switch ( a2 )
  {
    case 21:
      v36 = 19;
      break;
    case 25:
      v36 = 43;
      break;
    case 29:
      v36 = 18;
      break;
    case 30:
      v36 = 22;
      break;
    default:
      if ( a2 != 31 )
        goto LABEL_126;
      v36 = 23;
      break;
  }
LABEL_125:
  v2 += Player_MaybeGetWearItemsBonus((Player *)v37, v36, 0);
LABEL_126:
  v30 = *((_WORD *)v37 + a2 + 132);
  if ( v2 + (*((_WORD *)v37 + a2 + 132) & 0x3F) < 60 )
    v31 = v2 + v30;
  else
    LOBYTE(v31) = v30 & 0xFC | 0x3C;
  return v31;
}

//----- (004908DE) --------------------------------------------------------
signed int __cdecl sub_4908DE()
{
  signed int v0; // esi@1
  signed int v1; // eax@2
  signed int v2; // edx@2
  signed int v3; // ecx@2

  v0 = (signed int)pParty_global->pPlayers[0].pActiveSkills;
  while ( 1 )
  {
    v2 = 0;
    v1 = v0;
    v3 = 37;
    do
    {
      if ( *(_WORD *)v1 )
        ++v2;
      v1 += 2;
      --v3;
    }
    while ( v3 );
    if ( v2 < 4 )
      break;
    v0 += 6972;
    if ( v0 >= (signed int)&unk_AD477C )
      return 1;
  }
  return 0;
}

//----- (0042F933) --------------------------------------------------------
void __fastcall sub_42F933(int a1)
{
  __int16 v2; // ax@2
  char *v3; // ecx@2

  pLayingItemsList[a1].uObjectDescriptionID = 0;
  if (pParty_global->dword_00087C == 1)
  {
   v3 = (char *)&pLayingItemsList[a1].word_00001A;
    v2 = *(_WORD *)v3;
    if ( *(_WORD *)v3 & 4 )
    {
      LOBYTE(v2) = v2 & 0xFB;
      --dword_4F8874;
      *(_WORD *)v3 = v2;
    }
  }
}

void Game_Process_cpp();
//----- (00463149) --------------------------------------------------------
int __cdecl sub_463149()
{
  signed int v0; // ebp@3
  signed int v1; // esi@4
  int v2; // edi@7
  int v5; // eax@46
  int v6; // ecx@58
  signed int v9; // edi@67
  int v10; // esi@67
  int v11; // edi@69
  signed int v12; // esi@71
  signed int v13; // esi@78
  int v14; // eax@83
  const char *v16; // [sp-4h] [bp-68h]@74
  int v17; // [sp+10h] [bp-54h]@1
  signed int v18; // [sp+10h] [bp-54h]@19
  signed int v19; // [sp+14h] [bp-50h]@8
  int v20[4]; // [sp+18h] [bp-4Ch]@80
  MSG Msg; // [sp+28h] [bp-3Ch]@20
  char Source; // [sp+44h] [bp-20h]@76
 int i;

  v17 = uCurrentMenuID == 9;
  SetCurrentMenu(0xFFFFFFFF);
  if (uCurrentMenuID == 9)
  {
    Party_Reset(pParty_global);
    dword_6BE340 = 0;
    dword_6A0D48 = 0;
    sub_45EE8A(dword_6A0CA0);
  }
  v0 = 1;

  LoadPlayerPortraintsAndVoices();
  LODFile_Icons_LOD.lod_IB_dword_011B84 = LODFile_Icons_LOD.uNumLoadedFiles;

  AudioPlayer_SetVolume(pAudioPlayer, aMusicVolumeLevels[uMusicVolimeMultiplier] * 64.0);

  v2 = (int)pD3DRenderer;
  while (true)
  {
    v19 = 1;
    if ( dword_50CBD0[0] )
      dword_50CBD0[0] = dword_50CBD0[3] != 0;
    stru_7215D8.uNumActions = 0;
    if (pParty_global->dword_00087C == 1)
    {
      sub_405CFF((int)&unk_4F8858, 0);
      pParty_global->dword_00087C = 0;
    }

    sub_464866(v17, 1);
    class24_sub_426363(pClass24_global);
    dword_6BE364 |= 0x80;
    dword_6BE340 = 2;
    dword_4E28F8 = 0;

    if (dword_720010)
      sub_46B105((void *)dword_720010);

    if (pGame->class14_obj->dword_000004 && 0xFF)
    {
      if (pAsyncKeyboard)
        CAsyncKeyboard_Resume(pAsyncKeyboard);
    }
    if (pD3DRenderer->pRenderD3D3)
      Vis_sub_4C1A02(pGame->pVis);
    v18 = 0;


    do
    {
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
        continue;
      }

      CGame_sub_44EEA7(pGame);
      GameUI_Update();
      sub_42FC4E_ProcessPressedKeys();
      GameUI_Process();
      if ( struct_505898.byte_505992 )
      {
        sub_409E6A();
LABEL_89:
        ((BaseRender *)v2)->Present();
        continue;
      }
      if ( dword_720010)
        sub_46B736((void *)dword_720010, 1);
      if ( pVideoPlayer->pSmackerMovie )
      {
        if ( !SmackWait(pVideoPlayer->pSmackerMovie) )
        {
         ((BaseRender *)v2)->BeginScene();
          ckass03_sub_469E3B(pGame->pClass03);
          sub_4BF08B((void *)pVideoPlayer->dword_00006C, (int)pVideoPlayer->hWnd);
          class03_sub_469EA4_LooksLikeDrawPickedItem((int)pGame->pClass03);
          ((BaseRender *)v2)->EndScene();
        }
      }
      if ( pVideoPlayer->pBinkMovie )
      {
        if ( !BinkWait(pVideoPlayer->pBinkMovie) )
        {
          ((BaseRender *)v2)->BeginScene();
          ckass03_sub_469E3B(pGame->pClass03);
          compile_error;//nullsub_2(dword_F8BB78);
          class03_sub_469EA4_LooksLikeDrawPickedItem((int)pGame->pClass03);
          ((BaseRender *)v2)->EndScene();
        }
      }

      class24_sub_4263B7(pClass24_global);
      class24_sub_4263B7(pClass24_global2);
      sub_448B67(false);
      sub_448B45_LooksLikeResetSomeTimer(false);
      if (pClass24_global2->dword_000004)
      {
        if ( !pClass24_global->dword_000004 )
          class24_sub_426363(pClass24_global2);
      }
      if ( pClass24_global->dword_000008 )
      {
        if (!pParty_global->dword_00087C)
          pClass24_global->dword_000008 = 0;
      }
      if ( !pClass24_global->dword_000004 )
      {
        if ( !dword_6A0D48 )
        {
          if ( !pClass24_global->dword_000008 )
            sub_494035();
          if ( dword_6BE364 & 1 )
          {
            dword_6BE364 &= 0xFFFFFFFEu;
          }
          else
          {
            sub_401A91();
            sub_46BDC0(v5, 0);
          }
        }
      }
      if ( v19 )
      {
        v19 = 0;
        struct_576FE8.dword_000044 = 1;
      }
      AudioPlayer_sub_4AAFCF(pAudioPlayer);
      if ( dword_6A0D48 == 1 )
        goto LABEL_96;
      else if ( dword_6A0D48 == 2 )
      {
        AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
        sub_4646F0(0);
        dword_6A0D48 = 0;
        continue;
      }
      if ( dword_6A0D48 <= 2 )
        goto LABEL_85;
      if ( dword_6A0D48 <= 5 || dword_6A0D48 == 7 )
      {
LABEL_96:
        v18 = 1;
        continue;
      }
      if ( dword_6A0D48 != 8 )
      {
        if ( dword_6A0D48 != 9 )
        {
LABEL_85:
          sub_44103C();
          continue;
        }
        ((BaseRender *)v2)->BeginScene();
        sub_4156F0_LooksLike_UI_ProcessCallbacks();
        ((BaseRender *)v2)->EndScene();
        goto LABEL_89;
      }
      AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
      memset(&pParty_global->pHiredNPCs[0], 0, sizeof(struct NPCData));
      memset(&pParty_global->pHiredNPCs[1], 0, sizeof(struct NPCData));
      v6 = 0;
      if (pNPCStats->dword_017FC4 > 0)
      {
        do
        {
         if ( pNPCStats->pNPCData2[v6].dword_000020 )
            pNPCStats->pNPCData2[v6].dword_000008 &= 0x7Fu;
          ++v6;
        }
        while ( v6 < pNPCStats->dword_017FC4);
      }

      if (!bSkipVideo)
      {
       PlayFirstActMovie();
       if ( CVideoPlayer_IsAnyMovieLoaded(pVideoPlayer) )
         CVideoPlayer_UnloadAll(pVideoPlayer);
      }

      SaveGame(0, 0);
      ++pParty_global->dword_00073C;

      for (i = 0; i < 4; ++i)
        Player_sub_44A5CB((char *)&pParty_global->pPlayers[i], 12, 85);

      pParty_global->unk_000764[0] = 0;
      pParty_global->qword_00002C += 2580480i64;
      LOWORD(pParty_global->dword_007778) = pParty_global->dword_007778 & 0xFDFB;
      sub_492B70(0);
      v10 = (int)array_5E4D58;
      v9 = 50;
      do
      {
        sub_45855F((void *)v10);
        v10 += 20;
        --v9;
      }
      while ( v9 );
      memset(pParty_global->pPartyBuffs, 0, 20 * 16);
      v11 = 1;
      if (pParty_global->dword_00087C == 1)
      {
        sub_405CFF((int)&unk_4F8858, 1);
        pParty_global->dword_00087C = 0;
      }
      v12 = (signed int)dword_ACF2C0;
      do
      {
        memset((void *)(v12 - 6460), 0, 0xA0u);
        memset((void *)(v12 - 412), 0, 0x180u);
        *(_DWORD *)v12 = 1;
        v12 += 6972;
        uActiveCharacter = 1;
      }
      while ( v12 < (signed int)&unk_AD5FB0 );
      if ( (unsigned __int16)sub_449B57((int)pParty_global->unk_000764 + 1, 136) )
      {
        pParty_global->sPartyPosX = -17331;
        pParty_global->sPartyPosY = 12547;
        pParty_global->sPartyPosZ = 465;
        pParty_global->sRotationY = 0;
        v16 = "out02.odm";
      }
      else
      {
        pParty_global->sPartyPosX = 12552;
        pParty_global->sPartyPosY = 1816;
        pParty_global->sPartyPosZ = 0;
        pParty_global->sRotationY = 512;
        v16 = "out01.odm";
      }
      strcpy(&Source, v16);
      pParty_global->dword_000700 = pParty_global->sPartyPosZ;
      pParty_global->sRotationX = 0;
      pParty_global->dword_0006E8 = 0;
      pParty_global->dword_0006E4 = 0;
      pParty_global->dword_0006E0 = 0;
      if ( _strcmpi(&Source, Str1) )
      {
        strcpy(Str1, &Source);
        dword_5B65A8 = pParty_global->sPartyPosX;
        dword_5B65AC = pParty_global->sPartyPosY;
        dword_5B65B0 = pParty_global->sPartyPosZ;
        dword_5B65B4 = pParty_global->sRotationY;
        dword_5B65B8 = pParty_global->sRotationX;
        dword_5B65C0 = 1;
        sub_4646F0(1);
      }
      UpdateActors();
      v13 = 0;
      do
      {
        if ( Player_sub_492C0B((int)*(&ptr_A750C4 + v11)) )
          v20[v13++] = v11;
        ++v11;
      }
      while ( v11 <= 4 );
      if ( v13 )
      {
        v14 = rand();
        Player_PlaySound(*(&ptr_A750C4 + v20[v14 % v13]), 99, 0);
      }
      sub_44C175((char *)pGlobalTXT_LocalizationStrings[524], 2);
      dword_6A0D48 = 0;
      v2 = (int)pD3DRenderer;
    }
    while ( !v18 );
    dword_6BE340 = 0;
    class24_fn1(pClass24_global);
    sub_464479();
    if ( dword_6A0D48 == 3 )
    {
      sub_491E3A();
      LoadPlayerPortraintsAndVoices();
      dword_6A0D48 = 0;
      LODFile_Icons_LOD.lod_IB_dword_011B84 = LODFile_Icons_LOD.uNumLoadedFiles;
      v17 = 1;
      continue;
    }
    break;
  }
  dword_4E28F8 = 16;
  return sub_491E3A();
}

//----- (0040BF77) --------------------------------------------------------
void __fastcall sub_40BF77(int a1, int a2)
{
  char *v2; // edi@1
  char *v3; // esi@1
  int v4; // eax@1
  char v5; // sf@2
  unsigned __int8 v6; // of@2
  int v7; // eax@2
  int v8; // eax@3
  int v9; // eax@4
  char v10; // zf@5
  unsigned __int8 v11; // zf@8
  char v12; // sf@8
  unsigned __int8 v13; // of@8
  int v14; // eax@8
  int v15; // eax@9
  int v16; // eax@10
  char v17; // zf@12
  char v18; // al@15
  int v19; // eax@16
  int v20; // eax@17
  int v21; // eax@22
  int v22; // eax@23
  signed int v23; // ebx@26
  int v24; // eax@26
  int v25; // eax@28
  int v26; // ebx@28
  char v27; // sf@30
  int v28; // eax@33
  int v29; // edx@33
  int v30; // eax@35
  char v31; // sf@37
  int v32; // eax@40
  int v33; // edx@40
  int v34; // eax@42
  char v35; // sf@44
  int v36; // eax@47
  int v37; // edx@47
  int v38; // eax@49
  char v39; // sf@51
  int v40; // eax@54
  int v41; // edx@54
  int v42; // eax@56
  char v43; // sf@58
  int v44; // eax@61
  int v45; // edx@61
  int v46; // eax@63
  char v47; // sf@65
  int v48; // eax@68
  int v49; // edx@68
  char v50; // al@70
  int v51; // eax@72
  char v52; // sf@74
  int v53; // eax@77
  int v54; // edx@77
  int v55; // eax@79
  char v56; // sf@81
  int v57; // eax@84
  int v58; // edx@84
  int v59; // eax@86
  char v60; // sf@88
  int v61; // eax@91
  int v62; // edx@91
  int v63; // eax@93
  char v64; // sf@95
  int v65; // eax@98
  int v66; // edx@98
  int v67; // eax@100
  char v68; // sf@102
  int v69; // eax@105
  int v70; // edx@105
  int v71; // eax@107
  char v72; // sf@109
  int v73; // eax@112
  int v74; // edx@112
  int v75; // eax@114
  char v76; // sf@116
  int v77; // eax@119
  int v78; // edx@119
  int v79; // eax@121
  char v80; // sf@123
  int v81; // eax@126
  int v82; // edx@126
  char v83; // al@128
  int v84; // eax@130
  char v85; // sf@132
  int v86; // eax@135
  int v87; // edx@135
  int v88; // eax@137
  char v89; // sf@139
  int v90; // eax@142
  int v91; // edx@142
  int v92; // eax@144
  int v93; // eax@151
  int v94; // ecx@151
  int v95; // eax@155
  int v96; // eax@162
  int v97; // ecx@162
  int v98; // eax@166
  int v99; // eax@173
  int v100; // ecx@173
  int v101; // eax@177
  int v102; // eax@184
  int v103; // ecx@184
  int v104; // eax@188
  int v105; // eax@195
  int v106; // ecx@195
  int v107; // eax@199
  int v108; // eax@206
  int v109; // ecx@206
  char v110; // al@210
  int v111; // eax@211
  int v112; // edx@211
  int v113; // eax@211
  int v114; // eax@211
  int v115; // eax@212
  int v116; // eax@219
  int v117; // ecx@219
  int v118; // eax@223
  signed int v119; // ebx@231
  int v120; // eax@231
  int v121; // eax@233
  int v122; // ebx@233
  char v123; // sf@235
  int v124; // eax@238
  int v125; // edx@238
  int v126; // eax@240
  char v127; // sf@242
  int v128; // eax@245
  int v129; // edx@245
  int v130; // eax@247
  char v131; // sf@249
  int v132; // eax@252
  int v133; // edx@252
  int v134; // eax@254
  char v135; // sf@256
  int v136; // eax@259
  int v137; // edx@259
  int v138; // eax@261
  char v139; // sf@263
  int v140; // eax@266
  int v141; // edx@266
  int v142; // eax@268
  char v143; // sf@270
  int v144; // eax@273
  int v145; // edx@273
  char v146; // al@275
  int v147; // eax@277
  char v148; // sf@279
  int v149; // eax@282
  int v150; // edx@282
  int v151; // eax@284
  char v152; // sf@286
  int v153; // eax@289
  int v154; // edx@289
  int v155; // eax@291
  char v156; // sf@293
  int v157; // eax@296
  int v158; // edx@296
  int v159; // eax@298
  char v160; // sf@300
  int v161; // eax@303
  int v162; // edx@303
  int v163; // eax@305
  char v164; // sf@307
  int v165; // eax@310
  int v166; // edx@310
  int v167; // eax@312
  char v168; // sf@314
  int v169; // eax@317
  int v170; // edx@317
  int v171; // eax@319
  char v172; // sf@321
  int v173; // eax@324
  int v174; // edx@324
  int v175; // eax@326
  char v176; // sf@328
  int v177; // eax@331
  int v178; // edx@331
  char v179; // al@333
  int v180; // eax@335
  char v181; // sf@337
  int v182; // eax@340
  int v183; // edx@340
  int v184; // eax@342
  char v185; // sf@344
  int v186; // eax@347
  int v187; // edx@347
  int v188; // eax@349
  int v189; // eax@356
  int v190; // ecx@356
  int v191; // eax@360
  int v192; // eax@367
  int v193; // ecx@367
  int v194; // eax@371
  int v195; // eax@378
  int v196; // ecx@378
  int v197; // eax@382
  int v198; // eax@389
  int v199; // ecx@389
  int v200; // eax@393
  int v201; // eax@400
  int v202; // ecx@400
  int v203; // eax@404
  int v204; // eax@411
  int v205; // ecx@411
  char v206; // al@415
  int v207; // eax@416
  int v208; // edx@416
  int v209; // eax@416
  int v210; // eax@416
  int v211; // eax@417
  int v212; // eax@424
  int v213; // ecx@424
  int v214; // eax@429
  int v215; // ecx@429
  signed int v216; // esi@511
  int v217; // [sp+Ch] [bp-64h]@488
  int v218; // [sp+10h] [bp-60h]@488
  int v219; // [sp+14h] [bp-5Ch]@1
  char *v220; // [sp+18h] [bp-58h]@1
  int v221; // [sp+1Ch] [bp-54h]@1
  int v222; // [sp+20h] [bp-50h]@1
  int v223; // [sp+24h] [bp-4Ch]@1
  int v224; // [sp+28h] [bp-48h]@1
  int v225; // [sp+2Ch] [bp-44h]@1
  int v226; // [sp+30h] [bp-40h]@1
  int v227; // [sp+34h] [bp-3Ch]@1
  int v228; // [sp+38h] [bp-38h]@1
  int v229; // [sp+3Ch] [bp-34h]@1
  int v230; // [sp+40h] [bp-30h]@1
  int v231; // [sp+44h] [bp-2Ch]@1
  int v232; // [sp+48h] [bp-28h]@1
  int v233; // [sp+4Ch] [bp-24h]@1
  int v234; // [sp+50h] [bp-20h]@1
  int v235; // [sp+54h] [bp-1Ch]@1
  int v236; // [sp+58h] [bp-18h]@1
  int v237; // [sp+5Ch] [bp-14h]@1
  int v238; // [sp+60h] [bp-10h]@1
  int v239; // [sp+64h] [bp-Ch]@1
  int v240; // [sp+68h] [bp-8h]@1
  int v241; // [sp+6Ch] [bp-4h]@1

  v224 = 0;
  v240 = 0;
  v238 = 0;
  v227 = 0;
  v235 = 0;
  v233 = 0;
  v231 = 0;
  v229 = 0;
  v222 = 0;
  v226 = 0;
  v241 = 0;
  v239 = 0;
  v237 = 0;
  v236 = 0;
  v234 = 0;
  v232 = 0;
  v230 = 0;
  v228 = 0;
  v221 = 0;
  v225 = 0;
  v223 = a1;
  v3 = &byte_505708[188 * a1];
  v220 = &aBrickShortage[108 * a2];
  v4 = *((_DWORD *)v220 + 11);
  v219 = (a1 + 1) % 2;
  v2 = &byte_505708[188 * v219];
  switch ( v4 )
  {
    case 2:
      v7 = *((_DWORD *)v3 + 11);
      compile_error;//v6 = __SETO__(v7, *((_DWORD *)v2 + 11));
      v5 = v7 - *((_DWORD *)v2 + 11) < 0;
      goto LABEL_18;
    case 3:
      v8 = *((_DWORD *)v3 + 12);
      compile_error;//v6 = __SETO__(v8, *((_DWORD *)v2 + 12));
      v5 = v8 - *((_DWORD *)v2 + 12) < 0;
      goto LABEL_18;
    case 4:
      v9 = *((_DWORD *)v3 + 13);
      compile_error;//v6 = __SETO__(v9, *((_DWORD *)v2 + 13));
      v5 = v9 - *((_DWORD *)v2 + 13) < 0;
      goto LABEL_18;
    case 5:
      v10 = *((_DWORD *)v3 + 11) == *((_DWORD *)v2 + 11);
      goto LABEL_21;
    case 6:
      v10 = *((_DWORD *)v3 + 12) == *((_DWORD *)v2 + 12);
      goto LABEL_21;
    case 7:
      v10 = *((_DWORD *)v3 + 13) == *((_DWORD *)v2 + 13);
      goto LABEL_21;
    case 8:
      v14 = *((_DWORD *)v3 + 11);
      compile_error;//v13 = __SETO__(v14, *((_DWORD *)v2 + 11));
      v11 = v14 == *((_DWORD *)v2 + 11);
      v12 = v14 - *((_DWORD *)v2 + 11) < 0;
      goto LABEL_24;
    case 9:
      v15 = *((_DWORD *)v3 + 12);
      compile_error;//v13 = __SETO__(v15, *((_DWORD *)v2 + 12));
      v11 = v15 == *((_DWORD *)v2 + 12);
      v12 = v15 - *((_DWORD *)v2 + 12) < 0;
      goto LABEL_24;
    case 10:
      v16 = *((_DWORD *)v3 + 13);
      compile_error;//v13 = __SETO__(v16, *((_DWORD *)v2 + 13));
      v11 = v16 == *((_DWORD *)v2 + 13);
      v12 = v16 - *((_DWORD *)v2 + 13) < 0;
      goto LABEL_24;
    case 11:
      v10 = *((_DWORD *)v3 + 10) == 0;
      goto LABEL_21;
    case 12:
      v17 = *((_DWORD *)v3 + 10) == 0;
      goto LABEL_15;
    case 13:
      v10 = *((_DWORD *)v2 + 10) == 0;
      goto LABEL_21;
    case 14:
      v17 = *((_DWORD *)v2 + 10) == 0;
LABEL_15:
      v18 = !v17;
      goto LABEL_25;
    case 15:
      v19 = *((_DWORD *)v3 + 10);
      compile_error;//v6 = __SETO__(v19, *((_DWORD *)v2 + 10));
      v5 = v19 - *((_DWORD *)v2 + 10) < 0;
      goto LABEL_18;
    case 16:
      v20 = *((_DWORD *)v3 + 9);
      compile_error;//v6 = __SETO__(v20, *((_DWORD *)v2 + 9));
      v5 = v20 - *((_DWORD *)v2 + 9) < 0;
LABEL_18:
      v18 = v5 ^ v6;
      goto LABEL_25;
    case 17:
      v10 = *((_DWORD *)v3 + 10) == *((_DWORD *)v2 + 10);
      goto LABEL_21;
    case 18:
      v10 = *((_DWORD *)v3 + 9) == *((_DWORD *)v2 + 9);
LABEL_21:
      v18 = v10;
      goto LABEL_25;
    case 19:
      v21 = *((_DWORD *)v3 + 10);
      compile_error;//v13 = __SETO__(v21, *((_DWORD *)v2 + 10));
      v11 = v21 == *((_DWORD *)v2 + 10);
      v12 = v21 - *((_DWORD *)v2 + 10) < 0;
      goto LABEL_24;
    case 20:
      v22 = *((_DWORD *)v3 + 9);
      compile_error;//v13 = __SETO__(v22, *((_DWORD *)v2 + 9));
      v11 = v22 == *((_DWORD *)v2 + 9);
      v12 = v22 - *((_DWORD *)v2 + 9) < 0;
LABEL_24:
      v18 = !((unsigned __int8)(v12 ^ v13) | v11);
LABEL_25:
      if ( v18 )
        goto LABEL_26;
      goto LABEL_231;
    default:
LABEL_26:
      v24 = v220[49];
      v23 = 0;
      dword_4FAA68 = v24 + (v220[48] == 1);
      dword_4FAA64 = v24;
      if ( v24 > 0 )
      {
        do
        {
          sub_40A283(v223);
          ++v23;
        }
        while ( v23 < v220[49] );
      }
      v26 = (int)v220;
      byte_4FAA77 = sub_40BB49(v223) > dword_4E1874;
      LOBYTE(v25) = v220[50];
      if ( (_BYTE)v25 )
      {
        if ( (_BYTE)v25 == 99 )
        {
          v29 = *((_DWORD *)v3 + 11);
          v28 = *((_DWORD *)v2 + 11);
          if ( v29 < v28 )
          {
            *((_DWORD *)v3 + 11) = v28;
            v224 = v28 - v29;
          }
        }
        else
        {
          v25 = (char)v25;
          v27 = (signed int)(char)v25 + *((_DWORD *)v3 + 11) < 0;
          *((_DWORD *)v3 + 11) += (char)v25;
          if ( v27 )
            *((_DWORD *)v3 + 11) = 0;
          v224 = v25;
        }
      }
      LOBYTE(v30) = *(_BYTE *)(v26 + 51);
      if ( (_BYTE)v30 )
      {
        if ( (_BYTE)v30 == 99 )
        {
          v33 = *((_DWORD *)v3 + 12);
          v32 = *((_DWORD *)v2 + 12);
          if ( v33 < v32 )
          {
            *((_DWORD *)v3 + 12) = v32;
            v240 = v32 - v33;
          }
        }
        else
        {
          v30 = (char)v30;
          v31 = (signed int)(char)v30 + *((_DWORD *)v3 + 12) < 0;
          *((_DWORD *)v3 + 12) += (char)v30;
          if ( v31 )
            *((_DWORD *)v3 + 12) = 0;
          v240 = v30;
        }
      }
      LOBYTE(v34) = *(_BYTE *)(v26 + 52);
      if ( (_BYTE)v34 )
      {
        if ( (_BYTE)v34 == 99 )
        {
          v37 = *((_DWORD *)v3 + 13);
          v36 = *((_DWORD *)v2 + 13);
          if ( v37 < v36 )
          {
            *((_DWORD *)v3 + 13) = v36;
            v238 = v36 - v37;
          }
        }
        else
        {
          v34 = (char)v34;
          v35 = (signed int)(char)v34 + *((_DWORD *)v3 + 13) < 0;
          *((_DWORD *)v3 + 13) += (char)v34;
          if ( v35 )
            *((_DWORD *)v3 + 13) = 0;
          v238 = v34;
        }
      }
      LOBYTE(v38) = *(_BYTE *)(v26 + 53);
      if ( (_BYTE)v38 )
      {
        if ( (_BYTE)v38 == 99 )
        {
          v41 = *((_DWORD *)v3 + 14);
          v40 = *((_DWORD *)v2 + 14);
          if ( v41 < v40 )
          {
            *((_DWORD *)v3 + 14) = v40;
            v227 = v40 - v41;
          }
        }
        else
        {
          v38 = (char)v38;
          v39 = (signed int)(char)v38 + *((_DWORD *)v3 + 14) < 0;
          *((_DWORD *)v3 + 14) += (char)v38;
          if ( v39 )
            *((_DWORD *)v3 + 14) = 0;
          v227 = v38;
        }
      }
      LOBYTE(v42) = *(_BYTE *)(v26 + 54);
      if ( (_BYTE)v42 )
      {
        if ( (_BYTE)v42 == 99 )
        {
          v45 = *((_DWORD *)v3 + 15);
          v44 = *((_DWORD *)v2 + 15);
          if ( v45 < v44 )
          {
            *((_DWORD *)v3 + 15) = v44;
            v235 = v44 - v45;
          }
        }
        else
        {
          v42 = (char)v42;
          v43 = (signed int)(char)v42 + *((_DWORD *)v3 + 15) < 0;
          *((_DWORD *)v3 + 15) += (char)v42;
          if ( v43 )
            *((_DWORD *)v3 + 15) = 0;
          v235 = v42;
        }
      }
      LOBYTE(v46) = *(_BYTE *)(v26 + 55);
      if ( (_BYTE)v46 )
      {
        if ( (_BYTE)v46 == 99 )
        {
          v49 = *((_DWORD *)v3 + 16);
          v48 = *((_DWORD *)v2 + 16);
          if ( v49 < v48 )
          {
            *((_DWORD *)v3 + 16) = v48;
            v233 = v48 - v49;
          }
        }
        else
        {
          v46 = (char)v46;
          v47 = (signed int)(char)v46 + *((_DWORD *)v3 + 16) < 0;
          *((_DWORD *)v3 + 16) += (char)v46;
          if ( v47 )
            *((_DWORD *)v3 + 16) = 0;
          v233 = v46;
        }
      }
      v50 = *(_BYTE *)(v26 + 56);
      if ( v50 )
      {
        v226 = sub_40D402(v223, v50);
        v222 = *(_BYTE *)(v26 + 56) - v226;
      }
      LOBYTE(v51) = *(_BYTE *)(v26 + 57);
      if ( (_BYTE)v51 )
      {
        if ( (_BYTE)v51 == 99 )
        {
          v54 = *((_DWORD *)v3 + 10);
          v53 = *((_DWORD *)v2 + 10);
          if ( v54 < v53 )
          {
            *((_DWORD *)v3 + 10) = v53;
            v231 = v53 - v54;
          }
        }
        else
        {
          v51 = (char)v51;
          v52 = (signed int)(char)v51 + *((_DWORD *)v3 + 10) < 0;
          *((_DWORD *)v3 + 10) += (char)v51;
          if ( v52 )
            *((_DWORD *)v3 + 10) = 0;
          v231 = v51;
        }
      }
      LOBYTE(v55) = *(_BYTE *)(v26 + 58);
      if ( (_BYTE)v55 )
      {
        if ( (_BYTE)v55 == 99 )
        {
          v58 = *((_DWORD *)v3 + 9);
          v57 = *((_DWORD *)v2 + 9);
          if ( v58 < v57 )
          {
            *((_DWORD *)v3 + 9) = v57;
            v229 = v57 - v58;
          }
        }
        else
        {
          v55 = (char)v55;
          v56 = (signed int)(char)v55 + *((_DWORD *)v3 + 9) < 0;
          *((_DWORD *)v3 + 9) += (char)v55;
          if ( v56 )
            *((_DWORD *)v3 + 9) = 0;
          v229 = v55;
        }
      }
      LOBYTE(v59) = *(_BYTE *)(v26 + 59);
      if ( (_BYTE)v59 )
      {
        if ( (_BYTE)v59 == 99 )
        {
          v61 = *((_DWORD *)v3 + 11);
          v62 = *((_DWORD *)v2 + 11);
          if ( v61 > v62 )
          {
            *((_DWORD *)v2 + 11) = v61;
            v241 = v61 - v62;
          }
        }
        else
        {
          v59 = (char)v59;
          v60 = (signed int)(char)v59 + *((_DWORD *)v2 + 11) < 0;
          *((_DWORD *)v2 + 11) += (char)v59;
          if ( v60 )
            *((_DWORD *)v2 + 11) = 0;
          v241 = v59;
        }
      }
      LOBYTE(v63) = *(_BYTE *)(v26 + 60);
      if ( (_BYTE)v63 )
      {
        if ( (_BYTE)v63 == 99 )
        {
          v65 = *((_DWORD *)v3 + 12);
          v66 = *((_DWORD *)v2 + 12);
          if ( v65 > v66 )
          {
            *((_DWORD *)v2 + 12) = v65;
            v239 = v65 - v66;
          }
        }
        else
        {
          v63 = (char)v63;
          v64 = (signed int)(char)v63 + *((_DWORD *)v2 + 12) < 0;
          *((_DWORD *)v2 + 12) += (char)v63;
          if ( v64 )
            *((_DWORD *)v2 + 12) = 0;
          v239 = v63;
        }
      }
      LOBYTE(v67) = *(_BYTE *)(v26 + 61);
      if ( (_BYTE)v67 )
      {
        if ( (_BYTE)v67 == 99 )
        {
          v69 = *((_DWORD *)v3 + 13);
          v70 = *((_DWORD *)v2 + 13);
          if ( v69 > v70 )
          {
            *((_DWORD *)v2 + 13) = v69;
            v237 = v69 - v70;
          }
        }
        else
        {
          v67 = (char)v67;
          v68 = (signed int)(char)v67 + *((_DWORD *)v2 + 13) < 0;
          *((_DWORD *)v2 + 13) += (char)v67;
          if ( v68 )
            *((_DWORD *)v2 + 13) = 0;
          v237 = v67;
        }
      }
      LOBYTE(v71) = *(_BYTE *)(v26 + 62);
      if ( (_BYTE)v71 )
      {
        if ( (_BYTE)v71 == 99 )
        {
          v73 = *((_DWORD *)v3 + 14);
          v74 = *((_DWORD *)v2 + 14);
          if ( v73 > v74 )
          {
            *((_DWORD *)v2 + 14) = v73;
            v236 = v73 - v74;
          }
        }
        else
        {
          v71 = (char)v71;
          v72 = (signed int)(char)v71 + *((_DWORD *)v2 + 14) < 0;
          *((_DWORD *)v2 + 14) += (char)v71;
          if ( v72 )
            *((_DWORD *)v2 + 14) = 0;
          v236 = v71;
        }
      }
      LOBYTE(v75) = *(_BYTE *)(v26 + 63);
      if ( (_BYTE)v75 )
      {
        if ( (_BYTE)v75 == 99 )
        {
          v77 = *((_DWORD *)v3 + 15);
          v78 = *((_DWORD *)v2 + 15);
          if ( v77 > v78 )
          {
            *((_DWORD *)v2 + 15) = v77;
            v234 = v77 - v78;
          }
        }
        else
        {
          v75 = (char)v75;
          v76 = (signed int)(char)v75 + *((_DWORD *)v2 + 15) < 0;
          *((_DWORD *)v2 + 15) += (char)v75;
          if ( v76 )
            *((_DWORD *)v2 + 15) = 0;
          v234 = v75;
        }
      }
      LOBYTE(v79) = *(_BYTE *)(v26 + 64);
      if ( (_BYTE)v79 )
      {
        if ( (_BYTE)v79 == 99 )
        {
          v81 = *((_DWORD *)v3 + 16);
          v82 = *((_DWORD *)v2 + 16);
          if ( v81 > v82 )
          {
            *((_DWORD *)v2 + 16) = v81;
            v232 = v81 - v82;
          }
        }
        else
        {
          v79 = (char)v79;
          v80 = (signed int)(char)v79 + *((_DWORD *)v2 + 16) < 0;
          *((_DWORD *)v2 + 16) += (char)v79;
          if ( v80 )
            *((_DWORD *)v2 + 16) = 0;
          v232 = v79;
        }
      }
      v83 = *(_BYTE *)(v26 + 65);
      if ( v83 )
      {
        v225 = sub_40D402(v219, v83);
        v221 = *(_BYTE *)(v26 + 65) - v225;
      }
      LOBYTE(v84) = *(_BYTE *)(v26 + 66);
      if ( (_BYTE)v84 )
      {
        if ( (_BYTE)v84 == 99 )
        {
          v86 = *((_DWORD *)v3 + 10);
          v87 = *((_DWORD *)v2 + 10);
          if ( v86 > v87 )
          {
            *((_DWORD *)v2 + 10) = v86;
            v230 = v86 - v87;
          }
        }
        else
        {
          v84 = (char)v84;
          v85 = (signed int)(char)v84 + *((_DWORD *)v2 + 10) < 0;
          *((_DWORD *)v2 + 10) += (char)v84;
          if ( v85 )
            *((_DWORD *)v2 + 10) = 0;
          v230 = v84;
        }
      }
      LOBYTE(v88) = *(_BYTE *)(v26 + 67);
      if ( (_BYTE)v88 )
      {
        if ( (_BYTE)v88 == 99 )
        {
          v90 = *((_DWORD *)v3 + 9);
          v91 = *((_DWORD *)v2 + 9);
          if ( v90 > v91 )
          {
            *((_DWORD *)v2 + 9) = v90;
            v228 = v90 - v91;
          }
        }
        else
        {
          v88 = (char)v88;
          v89 = (signed int)(char)v88 + *((_DWORD *)v2 + 9) < 0;
          *((_DWORD *)v2 + 9) += (char)v88;
          if ( v89 )
            *((_DWORD *)v2 + 9) = 0;
          v228 = v88;
        }
      }
      LOBYTE(v92) = *(_BYTE *)(v26 + 68);
      if ( (_BYTE)v92 )
      {
        if ( (_BYTE)v92 == 99 )
        {
          v93 = *((_DWORD *)v3 + 11);
          v94 = *((_DWORD *)v2 + 11);
          if ( v93 != v94 )
          {
            if ( v93 <= v94 )
            {
              *((_DWORD *)v3 + 11) = v94;
              v224 = v94 - v93;
            }
            else
            {
              *((_DWORD *)v2 + 11) = v93;
              v241 = v93 - v94;
            }
          }
        }
        else
        {
          v92 = (char)v92;
          *((_DWORD *)v3 + 11) += (char)v92;
          *((_DWORD *)v2 + 11) += (char)v92;
          if ( *((_DWORD *)v3 + 11) < 0 )
            *((_DWORD *)v3 + 11) = 0;
          if ( *((_DWORD *)v2 + 11) < 0 )
            *((_DWORD *)v2 + 11) = 0;
          v224 = v92;
          v241 = v92;
        }
      }
      LOBYTE(v95) = *(_BYTE *)(v26 + 69);
      if ( (_BYTE)v95 )
      {
        if ( (_BYTE)v95 == 99 )
        {
          v96 = *((_DWORD *)v3 + 12);
          v97 = *((_DWORD *)v2 + 12);
          if ( v96 != v97 )
          {
            if ( v96 <= v97 )
            {
              *((_DWORD *)v3 + 12) = v97;
              v240 = v97 - v96;
            }
            else
            {
              *((_DWORD *)v2 + 12) = v96;
              v239 = v96 - v97;
            }
          }
        }
        else
        {
          v95 = (char)v95;
          *((_DWORD *)v3 + 12) += (char)v95;
          *((_DWORD *)v2 + 12) += (char)v95;
          if ( *((_DWORD *)v3 + 12) < 0 )
            *((_DWORD *)v3 + 12) = 0;
          if ( *((_DWORD *)v2 + 12) < 0 )
            *((_DWORD *)v2 + 12) = 0;
          v239 = v95;
          v240 = v95;
        }
      }
      LOBYTE(v98) = *(_BYTE *)(v26 + 70);
      if ( (_BYTE)v98 )
      {
        if ( (_BYTE)v98 == 99 )
        {
          v99 = *((_DWORD *)v3 + 13);
          v100 = *((_DWORD *)v2 + 13);
          if ( v99 != v100 )
          {
            if ( v99 <= v100 )
            {
              *((_DWORD *)v3 + 13) = v100;
              v238 = v100 - v99;
            }
            else
            {
              *((_DWORD *)v2 + 13) = v99;
              v237 = v99 - v100;
            }
          }
        }
        else
        {
          v98 = (char)v98;
          *((_DWORD *)v3 + 13) += (char)v98;
          *((_DWORD *)v2 + 13) += (char)v98;
          if ( *((_DWORD *)v3 + 13) < 0 )
            *((_DWORD *)v3 + 13) = 0;
          if ( *((_DWORD *)v2 + 13) < 0 )
            *((_DWORD *)v2 + 13) = 0;
          v238 = v98;
          v237 = v98;
        }
      }
      LOBYTE(v101) = *(_BYTE *)(v26 + 71);
      if ( (_BYTE)v101 )
      {
        if ( (_BYTE)v101 == 99 )
        {
          v102 = *((_DWORD *)v3 + 14);
          v103 = *((_DWORD *)v2 + 14);
          if ( v102 != v103 )
          {
            if ( v102 <= v103 )
            {
              *((_DWORD *)v3 + 14) = v103;
              v227 = v103 - v102;
            }
            else
            {
              *((_DWORD *)v2 + 14) = v102;
              v236 = v102 - v103;
            }
          }
        }
        else
        {
          v101 = (char)v101;
          *((_DWORD *)v3 + 14) += (char)v101;
          *((_DWORD *)v2 + 14) += (char)v101;
          if ( *((_DWORD *)v3 + 14) < 0 )
            *((_DWORD *)v3 + 14) = 0;
          if ( *((_DWORD *)v2 + 14) < 0 )
            *((_DWORD *)v2 + 14) = 0;
          v227 = v101;
          v236 = v101;
        }
      }
      LOBYTE(v104) = *(_BYTE *)(v26 + 72);
      if ( (_BYTE)v104 )
      {
        if ( (_BYTE)v104 == 99 )
        {
          v105 = *((_DWORD *)v3 + 15);
          v106 = *((_DWORD *)v2 + 15);
          if ( v105 != v106 )
          {
            if ( v105 <= v106 )
            {
              v235 = v106 > v105;
              *((_DWORD *)v3 + 15) = v106;
            }
            else
            {
              v234 = 1;
              *((_DWORD *)v2 + 15) = v105;
            }
          }
        }
        else
        {
          v104 = (char)v104;
          *((_DWORD *)v3 + 15) += (char)v104;
          *((_DWORD *)v2 + 15) += (char)v104;
          if ( *((_DWORD *)v3 + 15) < 0 )
            *((_DWORD *)v3 + 15) = 0;
          if ( *((_DWORD *)v2 + 15) < 0 )
            *((_DWORD *)v2 + 15) = 0;
          v235 = v104;
          v234 = v104;
        }
      }
      LOBYTE(v107) = *(_BYTE *)(v26 + 73);
      if ( (_BYTE)v107 )
      {
        if ( (_BYTE)v107 == 99 )
        {
          v108 = *((_DWORD *)v3 + 16);
          v109 = *((_DWORD *)v2 + 16);
          if ( v108 != v109 )
          {
            if ( v108 <= v109 )
            {
              *((_DWORD *)v3 + 16) = v109;
              v233 = v109 - v108;
            }
            else
            {
              *((_DWORD *)v2 + 16) = v108;
              v232 = v108 - v109;
            }
          }
        }
        else
        {
          v107 = (char)v107;
          *((_DWORD *)v3 + 16) += (char)v107;
          *((_DWORD *)v2 + 16) += (char)v107;
          if ( *((_DWORD *)v3 + 16) < 0 )
            *((_DWORD *)v3 + 16) = 0;
          if ( *((_DWORD *)v2 + 16) < 0 )
            *((_DWORD *)v2 + 16) = 0;
          v233 = v107;
          v232 = v107;
        }
      }
      v110 = *(_BYTE *)(v26 + 74);
      if ( v110 )
      {
        v111 = sub_40D402(v223, v110);
        v112 = *(_BYTE *)(v26 + 74);
        v226 = v111;
        v113 = sub_40D402(v219, v112);
        v225 = v113;
        v114 = *(_BYTE *)(v26 + 74) - v113;
        v222 = *(_BYTE *)(v26 + 74) - v226;
        v221 = v114;
      }
      LOBYTE(v115) = *(_BYTE *)(v26 + 75);
      if ( (_BYTE)v115 )
      {
        if ( (_BYTE)v115 == 99 )
        {
          v116 = *((_DWORD *)v3 + 10);
          v117 = *((_DWORD *)v2 + 10);
          if ( v116 != v117 )
          {
            if ( v116 <= v117 )
            {
              *((_DWORD *)v3 + 10) = v117;
              v231 = v117 - v116;
            }
            else
            {
              *((_DWORD *)v2 + 10) = v116;
              v230 = v116 - v117;
            }
          }
        }
        else
        {
          v115 = (char)v115;
          *((_DWORD *)v3 + 10) += (char)v115;
          *((_DWORD *)v2 + 10) += (char)v115;
          if ( *((_DWORD *)v3 + 10) < 0 )
            *((_DWORD *)v3 + 10) = 0;
          if ( *((_DWORD *)v2 + 10) < 0 )
            *((_DWORD *)v2 + 10) = 0;
          v231 = v115;
          v230 = v115;
        }
      }
      LOBYTE(v118) = *(_BYTE *)(v26 + 76);
      break;
    case 0:
LABEL_231:
      v120 = v220[78];
      v119 = 0;
      dword_4FAA68 = v120 + (v220[77] == 1);
      dword_4FAA64 = v120;
      if ( v120 > 0 )
      {
        do
        {
          sub_40A283(v223);
          ++v119;
        }
        while ( v119 < v220[78] );
      }
      v122 = (int)v220;
      byte_4FAA77 = sub_40BB49(v223) > dword_4E1874;
      LOBYTE(v121) = v220[79];
      if ( (_BYTE)v121 )
      {
        if ( (_BYTE)v121 == 99 )
        {
          v125 = *((_DWORD *)v3 + 11);
          v124 = *((_DWORD *)v2 + 11);
          if ( v125 < v124 )
          {
            *((_DWORD *)v3 + 11) = v124;
            v224 = v124 - v125;
          }
        }
        else
        {
          v121 = (char)v121;
          v123 = (signed int)(char)v121 + *((_DWORD *)v3 + 11) < 0;
          *((_DWORD *)v3 + 11) += (char)v121;
          if ( v123 )
            *((_DWORD *)v3 + 11) = 0;
          v224 = v121;
        }
      }
      LOBYTE(v126) = *(_BYTE *)(v122 + 80);
      if ( (_BYTE)v126 )
      {
        if ( (_BYTE)v126 == 99 )
        {
          v129 = *((_DWORD *)v3 + 12);
          v128 = *((_DWORD *)v2 + 12);
          if ( v129 < v128 )
          {
            *((_DWORD *)v3 + 12) = v128;
            v240 = v128 - v129;
          }
        }
        else
        {
          v126 = (char)v126;
          v127 = (signed int)(char)v126 + *((_DWORD *)v3 + 12) < 0;
          *((_DWORD *)v3 + 12) += (char)v126;
          if ( v127 )
            *((_DWORD *)v3 + 12) = 0;
          v240 = v126;
        }
      }
      LOBYTE(v130) = *(_BYTE *)(v122 + 81);
      if ( (_BYTE)v130 )
      {
        if ( (_BYTE)v130 == 99 )
        {
          v133 = *((_DWORD *)v3 + 13);
          v132 = *((_DWORD *)v2 + 13);
          if ( v133 < v132 )
          {
            *((_DWORD *)v3 + 13) = v132;
            v238 = v132 - v133;
          }
        }
        else
        {
          v130 = (char)v130;
          v131 = (signed int)(char)v130 + *((_DWORD *)v3 + 13) < 0;
          *((_DWORD *)v3 + 13) += (char)v130;
          if ( v131 )
            *((_DWORD *)v3 + 13) = 0;
          v238 = v130;
        }
      }
      LOBYTE(v134) = *(_BYTE *)(v122 + 82);
      if ( (_BYTE)v134 )
      {
        if ( (_BYTE)v134 == 99 )
        {
          v137 = *((_DWORD *)v3 + 14);
          v136 = *((_DWORD *)v2 + 14);
          if ( v137 < v136 )
          {
            *((_DWORD *)v3 + 14) = v136;
            v227 = v136 - v137;
          }
        }
        else
        {
          v134 = (char)v134;
          v135 = (signed int)(char)v134 + *((_DWORD *)v3 + 14) < 0;
          *((_DWORD *)v3 + 14) += (char)v134;
          if ( v135 )
            *((_DWORD *)v3 + 14) = 0;
          v227 = v134;
        }
      }
      LOBYTE(v138) = *(_BYTE *)(v122 + 83);
      if ( (_BYTE)v138 )
      {
        if ( (_BYTE)v138 == 99 )
        {
          v141 = *((_DWORD *)v3 + 15);
          v140 = *((_DWORD *)v2 + 15);
          if ( v141 < v140 )
          {
            *((_DWORD *)v3 + 15) = v140;
            v235 = v140 - v141;
          }
        }
        else
        {
          v138 = (char)v138;
          v139 = (signed int)(char)v138 + *((_DWORD *)v3 + 15) < 0;
          *((_DWORD *)v3 + 15) += (char)v138;
          if ( v139 )
            *((_DWORD *)v3 + 15) = 0;
          v235 = v138;
        }
      }
      LOBYTE(v142) = *(_BYTE *)(v122 + 84);
      if ( (_BYTE)v142 )
      {
        if ( (_BYTE)v142 == 99 )
        {
          v145 = *((_DWORD *)v3 + 16);
          v144 = *((_DWORD *)v2 + 16);
          if ( v145 < v144 )
          {
            *((_DWORD *)v3 + 16) = v144;
            v233 = v144 - v145;
          }
        }
        else
        {
          v142 = (char)v142;
          v143 = (signed int)(char)v142 + *((_DWORD *)v3 + 16) < 0;
          *((_DWORD *)v3 + 16) += (char)v142;
          if ( v143 )
            *((_DWORD *)v3 + 16) = 0;
          v233 = v142;
        }
      }
      v146 = *(_BYTE *)(v122 + 85);
      if ( v146 )
      {
        v226 = sub_40D402(v223, v146);
        v222 = *(_BYTE *)(v122 + 85) - v226;
      }
      LOBYTE(v147) = *(_BYTE *)(v122 + 86);
      if ( (_BYTE)v147 )
      {
        if ( (_BYTE)v147 == 99 )
        {
          v150 = *((_DWORD *)v3 + 10);
          v149 = *((_DWORD *)v2 + 10);
          if ( v150 < v149 )
          {
            *((_DWORD *)v3 + 10) = v149;
            v231 = v149 - v150;
          }
        }
        else
        {
          v147 = (char)v147;
          v148 = (signed int)(char)v147 + *((_DWORD *)v3 + 10) < 0;
          *((_DWORD *)v3 + 10) += (char)v147;
          if ( v148 )
            *((_DWORD *)v3 + 10) = 0;
          v231 = v147;
        }
      }
      LOBYTE(v151) = *(_BYTE *)(v122 + 87);
      if ( (_BYTE)v151 )
      {
        if ( (_BYTE)v151 == 99 )
        {
          v154 = *((_DWORD *)v3 + 9);
          v153 = *((_DWORD *)v2 + 9);
          if ( v154 < v153 )
          {
            *((_DWORD *)v3 + 9) = v153;
            v229 = v153 - v154;
          }
        }
        else
        {
          v151 = (char)v151;
          v152 = (signed int)(char)v151 + *((_DWORD *)v3 + 9) < 0;
          *((_DWORD *)v3 + 9) += (char)v151;
          if ( v152 )
            *((_DWORD *)v3 + 9) = 0;
          v229 = v151;
        }
      }
      LOBYTE(v155) = *(_BYTE *)(v122 + 88);
      if ( (_BYTE)v155 )
      {
        if ( (_BYTE)v155 == 99 )
        {
          v157 = *((_DWORD *)v3 + 11);
          v158 = *((_DWORD *)v2 + 11);
          if ( v157 > v158 )
          {
            *((_DWORD *)v2 + 11) = v157;
            v241 = v157 - v158;
          }
        }
        else
        {
          v155 = (char)v155;
          v156 = (signed int)(char)v155 + *((_DWORD *)v2 + 11) < 0;
          *((_DWORD *)v2 + 11) += (char)v155;
          if ( v156 )
            *((_DWORD *)v2 + 11) = 0;
          v241 = v155;
        }
      }
      LOBYTE(v159) = *(_BYTE *)(v122 + 89);
      if ( (_BYTE)v159 )
      {
        if ( (_BYTE)v159 == 99 )
        {
          v161 = *((_DWORD *)v3 + 12);
          v162 = *((_DWORD *)v2 + 12);
          if ( v161 > v162 )
          {
            *((_DWORD *)v2 + 12) = v161;
            v239 = v161 - v162;
          }
        }
        else
        {
          v159 = (char)v159;
          v160 = (signed int)(char)v159 + *((_DWORD *)v2 + 12) < 0;
          *((_DWORD *)v2 + 12) += (char)v159;
          if ( v160 )
            *((_DWORD *)v2 + 12) = 0;
          v239 = v159;
        }
      }
      LOBYTE(v163) = *(_BYTE *)(v122 + 90);
      if ( (_BYTE)v163 )
      {
        if ( (_BYTE)v163 == 99 )
        {
          v165 = *((_DWORD *)v3 + 13);
          v166 = *((_DWORD *)v2 + 13);
          if ( v165 > v166 )
          {
            *((_DWORD *)v2 + 13) = v165;
            v237 = v165 - v166;
          }
        }
        else
        {
          v163 = (char)v163;
          v164 = (signed int)(char)v163 + *((_DWORD *)v2 + 13) < 0;
          *((_DWORD *)v2 + 13) += (char)v163;
          if ( v164 )
            *((_DWORD *)v2 + 13) = 0;
          v237 = v163;
        }
      }
      LOBYTE(v167) = *(_BYTE *)(v122 + 91);
      if ( (_BYTE)v167 )
      {
        if ( (_BYTE)v167 == 99 )
        {
          v169 = *((_DWORD *)v3 + 14);
          v170 = *((_DWORD *)v2 + 14);
          if ( v169 > v170 )
          {
            *((_DWORD *)v2 + 14) = v169;
            v236 = v169 - v170;
          }
        }
        else
        {
          v167 = (char)v167;
          v168 = (signed int)(char)v167 + *((_DWORD *)v2 + 14) < 0;
          *((_DWORD *)v2 + 14) += (char)v167;
          if ( v168 )
            *((_DWORD *)v2 + 14) = 0;
          v236 = v167;
        }
      }
      LOBYTE(v171) = *(_BYTE *)(v122 + 92);
      if ( (_BYTE)v171 )
      {
        if ( (_BYTE)v171 == 99 )
        {
          v173 = *((_DWORD *)v3 + 15);
          v174 = *((_DWORD *)v2 + 15);
          if ( v173 > v174 )
          {
            *((_DWORD *)v2 + 15) = v173;
            v234 = v173 - v174;
          }
        }
        else
        {
          v171 = (char)v171;
          v172 = (signed int)(char)v171 + *((_DWORD *)v2 + 15) < 0;
          *((_DWORD *)v2 + 15) += (char)v171;
          if ( v172 )
            *((_DWORD *)v2 + 15) = 0;
          v234 = v171;
        }
      }
      LOBYTE(v175) = *(_BYTE *)(v122 + 93);
      if ( (_BYTE)v175 )
      {
        if ( (_BYTE)v175 == 99 )
        {
          v177 = *((_DWORD *)v3 + 16);
          v178 = *((_DWORD *)v2 + 16);
          if ( v177 > v178 )
          {
            *((_DWORD *)v2 + 16) = v177;
            v232 = v177 - v178;
          }
        }
        else
        {
          v175 = (char)v175;
          v176 = (signed int)(char)v175 + *((_DWORD *)v2 + 16) < 0;
          *((_DWORD *)v2 + 16) += (char)v175;
          if ( v176 )
            *((_DWORD *)v2 + 16) = 0;
          v232 = v175;
        }
      }
      v179 = *(_BYTE *)(v122 + 94);
      if ( v179 )
      {
        v225 = sub_40D402(v219, v179);
        v221 = *(_BYTE *)(v122 + 94) - v225;
      }
      LOBYTE(v180) = *(_BYTE *)(v122 + 95);
      if ( (_BYTE)v180 )
      {
        if ( (_BYTE)v180 == 99 )
        {
          v182 = *((_DWORD *)v3 + 10);
          v183 = *((_DWORD *)v2 + 10);
          if ( v182 > v183 )
          {
            *((_DWORD *)v2 + 10) = v182;
            v230 = v182 - v183;
          }
        }
        else
        {
          v180 = (char)v180;
          v181 = (signed int)(char)v180 + *((_DWORD *)v2 + 10) < 0;
          *((_DWORD *)v2 + 10) += (char)v180;
          if ( v181 )
            *((_DWORD *)v2 + 10) = 0;
          v230 = v180;
        }
      }
      LOBYTE(v184) = *(_BYTE *)(v122 + 96);
      if ( (_BYTE)v184 )
      {
        if ( (_BYTE)v184 == 99 )
        {
          v186 = *((_DWORD *)v3 + 9);
          v187 = *((_DWORD *)v2 + 9);
          if ( v186 > v187 )
          {
            *((_DWORD *)v2 + 9) = v186;
            v228 = v186 - v187;
          }
        }
        else
        {
          v184 = (char)v184;
          v185 = (signed int)(char)v184 + *((_DWORD *)v2 + 9) < 0;
          *((_DWORD *)v2 + 9) += (char)v184;
          if ( v185 )
            *((_DWORD *)v2 + 9) = 0;
          v228 = v184;
        }
      }
      LOBYTE(v188) = *(_BYTE *)(v122 + 97);
      if ( (_BYTE)v188 )
      {
        if ( (_BYTE)v188 == 99 )
        {
          v189 = *((_DWORD *)v3 + 11);
          v190 = *((_DWORD *)v2 + 11);
          if ( v189 != v190 )
          {
            if ( v189 <= v190 )
            {
              *((_DWORD *)v3 + 11) = v190;
              v224 = v190 - v189;
            }
            else
            {
              *((_DWORD *)v2 + 11) = v189;
              v241 = v189 - v190;
            }
          }
        }
        else
        {
          v188 = (char)v188;
          *((_DWORD *)v3 + 11) += (char)v188;
          *((_DWORD *)v2 + 11) += (char)v188;
          if ( *((_DWORD *)v3 + 11) < 0 )
            *((_DWORD *)v3 + 11) = 0;
          if ( *((_DWORD *)v2 + 11) < 0 )
            *((_DWORD *)v2 + 11) = 0;
          v224 = v188;
          v241 = v188;
        }
      }
      LOBYTE(v191) = *(_BYTE *)(v122 + 98);
      if ( (_BYTE)v191 )
      {
        if ( (_BYTE)v191 == 99 )
        {
          v192 = *((_DWORD *)v3 + 12);
          v193 = *((_DWORD *)v2 + 12);
          if ( v192 != v193 )
          {
            if ( v192 <= v193 )
            {
              *((_DWORD *)v3 + 12) = v193;
              v240 = v193 - v192;
            }
            else
            {
              *((_DWORD *)v2 + 12) = v192;
              v239 = v192 - v193;
            }
          }
        }
        else
        {
          v191 = (char)v191;
          *((_DWORD *)v3 + 12) += (char)v191;
          *((_DWORD *)v2 + 12) += (char)v191;
          if ( *((_DWORD *)v3 + 12) < 0 )
            *((_DWORD *)v3 + 12) = 0;
          if ( *((_DWORD *)v2 + 12) < 0 )
            *((_DWORD *)v2 + 12) = 0;
          v239 = v191;
          v240 = v191;
        }
      }
      LOBYTE(v194) = *(_BYTE *)(v122 + 99);
      if ( (_BYTE)v194 )
      {
        if ( (_BYTE)v194 == 99 )
        {
          v195 = *((_DWORD *)v3 + 13);
          v196 = *((_DWORD *)v2 + 13);
          if ( v195 != v196 )
          {
            if ( v195 <= v196 )
            {
              *((_DWORD *)v3 + 13) = v196;
              v238 = v196 - v195;
            }
            else
            {
              *((_DWORD *)v2 + 13) = v195;
              v237 = v195 - v196;
            }
          }
        }
        else
        {
          v194 = (char)v194;
          *((_DWORD *)v3 + 13) += (char)v194;
          *((_DWORD *)v2 + 13) += (char)v194;
          if ( *((_DWORD *)v3 + 13) < 0 )
            *((_DWORD *)v3 + 13) = 0;
          if ( *((_DWORD *)v2 + 13) < 0 )
            *((_DWORD *)v2 + 13) = 0;
          v238 = v194;
          v237 = v194;
        }
      }
      LOBYTE(v197) = *(_BYTE *)(v122 + 100);
      if ( (_BYTE)v197 )
      {
        if ( (_BYTE)v197 == 99 )
        {
          v198 = *((_DWORD *)v3 + 14);
          v199 = *((_DWORD *)v2 + 14);
          if ( v198 != v199 )
          {
            if ( v198 <= v199 )
            {
              *((_DWORD *)v3 + 14) = v199;
              v227 = v199 - v198;
            }
            else
            {
              *((_DWORD *)v2 + 14) = v198;
              v236 = v198 - v199;
            }
          }
        }
        else
        {
          v197 = (char)v197;
          *((_DWORD *)v3 + 14) += (char)v197;
          *((_DWORD *)v2 + 14) += (char)v197;
          if ( *((_DWORD *)v3 + 14) < 0 )
            *((_DWORD *)v3 + 14) = 0;
          if ( *((_DWORD *)v2 + 14) < 0 )
            *((_DWORD *)v2 + 14) = 0;
          v227 = v197;
          v236 = v197;
        }
      }
      LOBYTE(v200) = *(_BYTE *)(v122 + 101);
      if ( (_BYTE)v200 )
      {
        if ( (_BYTE)v200 == 99 )
        {
          v201 = *((_DWORD *)v3 + 15);
          v202 = *((_DWORD *)v2 + 15);
          if ( v201 != v202 )
          {
            if ( v201 <= v202 )
            {
              v235 = v202 > v201;
              *((_DWORD *)v3 + 15) = v202;
            }
            else
            {
              v234 = 1;
              *((_DWORD *)v2 + 15) = v201;
            }
          }
        }
        else
        {
          v200 = (char)v200;
          *((_DWORD *)v3 + 15) += (char)v200;
          *((_DWORD *)v2 + 15) += (char)v200;
          if ( *((_DWORD *)v3 + 15) < 0 )
            *((_DWORD *)v3 + 15) = 0;
          if ( *((_DWORD *)v2 + 15) < 0 )
            *((_DWORD *)v2 + 15) = 0;
          v235 = v200;
          v234 = v200;
        }
      }
      LOBYTE(v203) = *(_BYTE *)(v122 + 102);
      if ( (_BYTE)v203 )
      {
        if ( (_BYTE)v203 == 99 )
        {
          v204 = *((_DWORD *)v3 + 16);
          v205 = *((_DWORD *)v2 + 16);
          if ( v204 != v205 )
          {
            if ( v204 <= v205 )
            {
              *((_DWORD *)v3 + 16) = v205;
              v233 = v205 - v204;
            }
            else
            {
              *((_DWORD *)v2 + 16) = v204;
              v232 = v204 - v205;
            }
          }
        }
        else
        {
          v203 = (char)v203;
          *((_DWORD *)v3 + 16) += (char)v203;
          *((_DWORD *)v2 + 16) += (char)v203;
          if ( *((_DWORD *)v3 + 16) < 0 )
            *((_DWORD *)v3 + 16) = 0;
          if ( *((_DWORD *)v2 + 16) < 0 )
            *((_DWORD *)v2 + 16) = 0;
          v233 = v203;
          v232 = v203;
        }
      }
      v206 = *(_BYTE *)(v122 + 103);
      if ( v206 )
      {
        v207 = sub_40D402(v223, v206);
        v208 = *(_BYTE *)(v122 + 103);
        v226 = v207;
        v209 = sub_40D402(v219, v208);
        v225 = v209;
        v210 = *(_BYTE *)(v122 + 103) - v209;
        v222 = *(_BYTE *)(v122 + 103) - v226;
        v221 = v210;
      }
      LOBYTE(v211) = *(_BYTE *)(v122 + 104);
      if ( (_BYTE)v211 )
      {
        if ( (_BYTE)v211 == 99 )
        {
          v212 = *((_DWORD *)v3 + 10);
          v213 = *((_DWORD *)v2 + 10);
          if ( v212 != v213 )
          {
            if ( v212 <= v213 )
            {
              *((_DWORD *)v3 + 10) = v213;
              v231 = v213 - v212;
            }
            else
            {
              *((_DWORD *)v2 + 10) = v212;
              v230 = v212 - v213;
            }
          }
        }
        else
        {
          v211 = (char)v211;
          *((_DWORD *)v3 + 10) += (char)v211;
          *((_DWORD *)v2 + 10) += (char)v211;
          if ( *((_DWORD *)v3 + 10) < 0 )
            *((_DWORD *)v3 + 10) = 0;
          if ( *((_DWORD *)v2 + 10) < 0 )
            *((_DWORD *)v2 + 10) = 0;
          v231 = v211;
          v230 = v211;
        }
      }
      LOBYTE(v118) = *(_BYTE *)(v122 + 105);
      break;
  }
  if ( (_BYTE)v118 )
  {
    if ( (_BYTE)v118 == 99 )
    {
      v214 = *((_DWORD *)v3 + 9);
      v215 = *((_DWORD *)v2 + 9);
      if ( v214 != v215 )
      {
        if ( v214 <= v215 )
        {
          *((_DWORD *)v3 + 9) = v215;
          v229 = v215 - v214;
        }
        else
        {
          *((_DWORD *)v2 + 9) = v214;
          v228 = v214 - v215;
        }
      }
    }
    else
    {
      v118 = (char)v118;
      *((_DWORD *)v3 + 9) += (char)v118;
      *((_DWORD *)v2 + 9) += (char)v118;
      if ( *((_DWORD *)v3 + 9) < 0 )
        *((_DWORD *)v3 + 9) = 0;
      if ( *((_DWORD *)v2 + 9) < 0 )
        *((_DWORD *)v2 + 9) = 0;
      v229 = v118;
      v228 = v118;
    }
  }
  if ( v224 > 0 || v241 > 0 )
    sub_40DDC9((void *)0x1E);
  if ( v224 < 0 || v241 < 0 )
    sub_40DDC9((void *)0x1F);
  if ( v240 > 0 || v239 > 0 )
    sub_40DDC9((void *)0x21);
  if ( v240 < 0 || v239 < 0 )
    sub_40DDC9((void *)0x22);
  if ( v238 > 0 || v237 > 0 )
    sub_40DDC9((void *)0x24);
  if ( v238 < 0 || v237 < 0 )
    sub_40DDC9((void *)0x25);
  if ( v227 > 0 || v236 > 0 )
    sub_40DDC9((void *)0x27);
  if ( v227 < 0 || v236 < 0 )
    sub_40DDC9((void *)0x28);
  if ( v235 > 0 || v234 > 0 )
    sub_40DDC9((void *)0x2A);
  if ( v235 < 0 || v234 < 0 )
    sub_40DDC9((void *)0x2B);
  if ( v233 > 0 || v232 > 0 )
    sub_40DDC9((void *)0x2D);
  if ( v233 < 0 || v232 < 0 )
    sub_40DDC9((void *)0x2E);
  if ( v222 || v221 || v226 || v225 )
    sub_40DDC9((void *)0x30);
  if ( v231 > 0 || v230 > 0 )
    sub_40DDC9((void *)0x31);
  if ( v231 < 0 || v230 < 0 )
    sub_40DDC9((void *)0x32);
  if ( v229 > 0 || v228 > 0 )
    sub_40DDC9((void *)0x34);
  if ( v229 < 0 || v228 < 0 )
    sub_40DDC9((void *)0x35);
  if ( v223 )
  {
    if ( v224 )
    {
      v217 = 573;
      v218 = 92;
      sub_40D2B4((int)&v217, v224);
    }
    if ( v241 )
    {
      v217 = 26;
      v218 = 92;
      sub_40D2B4((int)&v217, v241);
    }
    if ( v240 )
    {
      v217 = 573;
      v218 = 164;
      sub_40D2B4((int)&v217, v240);
    }
    if ( v239 )
    {
      v217 = 26;
      v218 = 164;
      sub_40D2B4((int)&v217, v239);
    }
    if ( v238 )
    {
      v217 = 573;
      v218 = 236;
      sub_40D2B4((int)&v217, v238);
    }
    if ( v237 )
    {
      v217 = 26;
      v218 = 236;
      sub_40D2B4((int)&v217, v237);
    }
    if ( v227 )
    {
      v217 = 563;
      v218 = 114;
      sub_40D2B4((int)&v217, v227);
    }
    if ( v236 )
    {
      v217 = 16;
      v218 = 114;
      sub_40D2B4((int)&v217, v236);
    }
    if ( v235 )
    {
      v217 = 563;
      v218 = 186;
      sub_40D2B4((int)&v217, v235);
    }
    if ( v234 )
    {
      v217 = 16;
      v218 = 186;
      sub_40D2B4((int)&v217, v234);
    }
    if ( v233 )
    {
      v217 = 563;
      v218 = 258;
      sub_40D2B4((int)&v217, v233);
    }
    if ( v232 )
    {
      v217 = 16;
      v218 = 258;
      sub_40D2B4((int)&v217, v232);
    }
    v216 = 296;
    if ( v231 )
    {
      v217 = 442;
      v218 = 296;
      sub_40D2B4((int)&v217, v231);
    }
    if ( v230 )
    {
      v217 = 180;
      v218 = 296;
      sub_40D2B4((int)&v217, v230);
    }
    if ( v229 )
    {
      v217 = 514;
      v218 = 296;
      sub_40D2B4((int)&v217, v229);
    }
    if ( v228 )
    {
      v217 = 122;
      v218 = 296;
      sub_40D2B4((int)&v217, v228);
    }
    if ( v226 )
    {
      v217 = 442;
      v218 = 296;
      sub_40D2B4((int)&v217, v226);
    }
    if ( v222 )
    {
      v217 = 514;
      v218 = 296;
      sub_40D2B4((int)&v217, v222);
    }
    if ( v225 )
    {
      v217 = 180;
      v218 = 296;
      sub_40D2B4((int)&v217, v225);
    }
    if ( v221 )
    {
      v217 = 122;
      goto LABEL_567;
    }
  }
  else
  {
    if ( v224 )
    {
      v217 = 26;
      v218 = 92;
      sub_40D2B4((int)&v217, v224);
    }
    if ( v241 )
    {
      v217 = 573;
      v218 = 92;
      sub_40D2B4((int)&v217, v241);
    }
    if ( v240 )
    {
      v217 = 26;
      v218 = 164;
      sub_40D2B4((int)&v217, v240);
    }
    if ( v239 )
    {
      v217 = 573;
      v218 = 164;
      sub_40D2B4((int)&v217, v239);
    }
    if ( v238 )
    {
      v217 = 26;
      v218 = 236;
      sub_40D2B4((int)&v217, v238);
    }
    if ( v237 )
    {
      v217 = 573;
      v218 = 236;
      sub_40D2B4((int)&v217, v237);
    }
    if ( v227 )
    {
      v217 = 16;
      v218 = 114;
      sub_40D2B4((int)&v217, v227);
    }
    if ( v236 )
    {
      v217 = 563;
      v218 = 114;
      sub_40D2B4((int)&v217, v236);
    }
    if ( v235 )
    {
      v217 = 16;
      v218 = 186;
      sub_40D2B4((int)&v217, v235);
    }
    if ( v234 )
    {
      v217 = 563;
      v218 = 186;
      sub_40D2B4((int)&v217, v234);
    }
    if ( v233 )
    {
      v217 = 16;
      v218 = 258;
      sub_40D2B4((int)&v217, v233);
    }
    if ( v232 )
    {
      v217 = 563;
      v218 = 258;
      sub_40D2B4((int)&v217, v232);
    }
    v216 = 296;
    if ( v231 )
    {
      v217 = 180;
      v218 = 296;
      sub_40D2B4((int)&v217, v231);
    }
    if ( v230 )
    {
      v217 = 442;
      v218 = 296;
      sub_40D2B4((int)&v217, v230);
    }
    if ( v229 )
    {
      v217 = 122;
      v218 = 296;
      sub_40D2B4((int)&v217, v229);
    }
    if ( v228 )
    {
      v217 = 514;
      v218 = 296;
      sub_40D2B4((int)&v217, v228);
    }
    if ( v226 )
    {
      v217 = 180;
      v218 = 296;
      sub_40D2B4((int)&v217, v226);
    }
    if ( v222 )
    {
      v217 = 122;
      v218 = 296;
      sub_40D2B4((int)&v217, v222);
    }
    if ( v225 )
    {
      v217 = 442;
      v218 = 296;
      sub_40D2B4((int)&v217, v225);
    }
    if ( v221 )
    {
      v217 = 514;
LABEL_567:
      v218 = v216;
      sub_40D2B4((int)&v217, v221);
      return;
    }
  }
}

//----- (00443801) --------------------------------------------------------
int __cdecl sub_443801()
{
  signed int v0; // edi@3
  int v2; // edx@5
  char *v3; // esi@5
  int v4; // eax@6
  char v5; // cl@6
  int v6; // ebx@10
  int v7; // eax@60
  int result; // eax@78
  signed int v9; // [sp+10h] [bp-8h]@5
  signed int v10; // [sp+14h] [bp-4h]@5

 if (p2DEventsTXT_Raw)
   mem_mng.DeleteBuffer( (void *)p2DEventsTXT_Raw);

  p2DEventsTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "2dEvents.txt", 0);
  strtok((char *)p2DEventsTXT_Raw, "\r");
  strtok(0, "\r");
  v0 = (signed int)&unk_59146C;
  while ( 1 )
  {
    v3 = strtok(0, "\r") + 1;
    v10 = 0;
    v2 = -2;
    v9 = -2;
    do
    {
      v5 = *v3;
      v4 = 0;
      while ( v5 != 9 && v5 )
      {
        ++v4;
        v5 = v3[v4];
      }
      v6 = (int)&v3[v4];
      if ( !v3[v4] )
        v10 = 1;
      *(_BYTE *)v6 = 0;
      if ( v4 )
      {
        switch ( v2 )
        {
          case 0:
            if ( _strnicmp(v3, "wea", 3u) )
            {
              if ( _strnicmp(v3, "arm", 3u) )
              {
                if ( _strnicmp(v3, "mag", 3u) )
                {
                 if ( _strnicmp(v3, "alc", 3u) )
                  {
                    if ( _strnicmp(v3, "sta", 3u) )
                    {
                      if ( _strnicmp(v3, "boa", 3u) )
                      {
                        if ( _strnicmp(v3, "tem", 3u) )
                        {
                          if ( _strnicmp(v3, "tra", 3u) )
                          {
                            if ( _strnicmp(v3, "tow", 3u) )
                            {
                              if ( _strnicmp(v3, "tav", 3u) )
                              {
                                if ( _strnicmp(v3, "ban", 3u) )
                                {
                                  if ( _strnicmp(v3, "fir", 3u) )
                                  {
                                    if ( _strnicmp(v3, "air", 3u) )
                                    {
                                      if ( _strnicmp(v3, "wat", 3u) )
                                      {
                                        if ( _strnicmp(v3, "ear", 3u) )
                                        {
                                          if ( _strnicmp(v3, "spi", 3u) )
                                          {
                                            if ( _strnicmp(v3, "min", 3u) )
                                            {
                                              if ( _strnicmp(v3, "bod", 3u) )
                                              {
                                               if ( _strnicmp(v3, "lig", 3u) )
                                                {
                                                  if ( _strnicmp(v3, "dar", 3u) )
                                                  {
                                                    if ( _strnicmp(v3, "ele", 3u) )
                                                    {
                                                      if ( _strnicmp(v3, "sel", 3u) )
                                                      {
                                                        if ( _strnicmp(v3, "mir", 3u) )
                                                        {
                                                          v7 = -(_strnicmp(v3, "mer", 3u) != 0);
                                                          LOBYTE(v7) = v7 & 0xEE;
                                                          *(_WORD *)v0 = v7 + 18;
                                                        }
                                                        else
                                                        {
                                                          *(_WORD *)v0 = 16;
                                                        }
                                                      }
                                                      else
                                                      {
                                                        *(_WORD *)v0 = 15;
                                                      }
                                                    }
                                                    else
                                                    {
                                                      *(_WORD *)v0 = 14;
                                                    }
                                                  }
                                                  else
                                                  {
                                                    *(_WORD *)v0 = 13;
                                                  }
                                                }
                                                else
                                                {
                                                  *(_WORD *)v0 = 12;
                                                }
                                              }
                                              else
                                              {
                                                *(_WORD *)v0 = 11;
                                              }
                                            }
                                            else
                                            {
                                              *(_WORD *)v0 = 10;
                                            }
                                          }
                                          else
                                          {
                                            *(_WORD *)v0 = 9;
                                          }
                                        }
                                        else
                                        {
                                          *(_WORD *)v0 = 8;
                                        }
                                      }
                                      else
                                      {
                                        *(_WORD *)v0 = 7;
                                      }
                                    }
                                    else
                                    {
                                      *(_WORD *)v0 = 6;
                                    }
                                  }
                                  else
                                  {
                                    *(_WORD *)v0 = 5;
                                  }
                                }
                                else
                                {
                                  *(_WORD *)v0 = 22;
                                }
                              }
                              else
                              {
                                *(_WORD *)v0 = 21;
                              }
                            }
                            else
                            {
                              *(_WORD *)v0 = 17;
                            }
                          }
                          else
                          {
                            *(_WORD *)v0 = 30;
                          }
                        }
                        else
                        {
                          *(_WORD *)v0 = 23;
                        }
                      }
                      else
                      {
                        *(_WORD *)v0 = 28;
                      }
                    }
                    else
                    {
                      *(_WORD *)v0 = 27;
                    }
                  }
                  else
                  {
                    *(_WORD *)v0 = 4;
                  }
                }
                else
                {
                  *(_WORD *)v0 = 3;
                }
              }
              else
              {
                *(_WORD *)v0 = 2;
              }
            }
            else
            {
              *(_WORD *)v0 = 1;
            }
            break;
          case 2:
            *(_WORD *)(v0 + 2) = atoi(v3);
            break;
          case 3:
            *(_DWORD *)(v0 + 4) = (int)RemoveQuote(v3);
            break;
          case 4:
            *(_DWORD *)(v0 + 8) = (int)RemoveQuote(v3);
            break;
          case 5:
            *(_DWORD *)(v0 + 16) = (int)RemoveQuote(v3);
            break;
          case 6:
            *(_WORD *)(v0 + 20) = atoi(v3);
            break;
          case 7:
            *(_WORD *)(v0 + 22) = atoi(v3);
            break;
          case 8:
            *(_WORD *)(v0 + 24) = atoi(v3);
            break;
          case 9:
            *(_WORD *)(v0 + 26) = atoi(v3);
            break;
          case 10:
            *(float *)(v0 + 32) = atof(v3);
            break;
          case 11:
            *(float *)(v0 + 36) = atof(v3);
            break;
          case 13:
            *(_WORD *)(v0 + 28) = atoi(v3);
            break;
          case 16:
            *(_WORD *)(v0 + 40) = atoi(v3);
            break;
          case 17:
            *(_WORD *)(v0 + 42) = atoi(v3);
            break;
          case 18:
            *(_WORD *)(v0 + 44) = atoi(v3);
            break;
          case 19:
            *(_WORD *)(v0 + 46) = atoi(v3);
            break;
          case 20:
            *(_WORD *)(v0 + 48) = atoi(v3);
            break;
          case 21:
            *(_DWORD *)(v0 + 12) = (int)RemoveQuote(v3);
            break;
          default:
            break;
        }
      }
      v3 = (char *)(v6 + 1);
      v2 = v9 + 1;
      v9 = v2;
      result = v2 + 1;
    }
    while ( v2 + 1 <= 23 && !v10 );
    v0 += 52;
    if ( v0 >= (signed int)&unk_597F10 )
      return result;
  }
}

//----- (004A90A0) --------------------------------------------------------
void class06_sub_4A90A0(struct class06 *_this)
{
#ifndef OLD_CODE
	_this->dword_0005E4 = LODFile_Bitmaps_LOD.LODFile_LoadTexture_New( L"effpar01");
 _this->dword_0005E8 = LODFile_Bitmaps_LOD.LODFile_LoadTexture_New( L"effpar02");
 _this->dword_0005EC = LODFile_Bitmaps_LOD.LODFile_LoadTexture_New( L"effpar03");
#endif
#ifdef OLD_CODE
	_this->dword_0005E4 = LODFile_Bitmaps_LOD.LODFile_LoadTexture( "effpar01",2);
 _this->dword_0005E8 = LODFile_Bitmaps_LOD.LODFile_LoadTexture( "effpar02",2);
 _this->dword_0005EC = LODFile_Bitmaps_LOD.LODFile_LoadTexture( "effpar03",2);
#endif
 

 _this->dword_0005F0 = LODFile_Sprites_LOD.LODFile_LoadSprite( "sp57c", 6);

 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("zapp"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spheal1"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spheal2"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spheal3"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spboost1"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spboost2"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spboost3"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell03"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell05"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell14"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell17"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell21"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell25"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell27"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell36"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell38"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell46"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell51"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell55"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell58"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell69"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell71"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell73"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell75"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("spell96"));

 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell02"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell03"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell09"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell11"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell18"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell22"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell26"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell29"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell39"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell39c"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell41"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell57c"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell62"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell65"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell66"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell70"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell76"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell84"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell90"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell92"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell93"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell97"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell97c"));
 SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell97c"));
}

void CreateRegistryWString(const wchar_t *pName, const wchar_t *pValue, unsigned int uSize)
{
 HKEY hSoftware = 0,
      hNewWorldComputing = 0,
      hVer10 = 0,
      hValue = 0;
 if (!RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE", 0, 0x2001Fu, &hSoftware))
 {
  if (!RegCreateKeyExW(hSoftware, L"New World Computing", 0, L"", 0, 983103u, 0, &hNewWorldComputing, 0))
  {
   if (!RegCreateKeyExW(hNewWorldComputing,L"Might and Magic VII", 0, L"", 0, 0xF003Fu, 0, &hVer10, 0))
   {
    if (!RegCreateKeyExW(hVer10, L"1.0", 0, L"", 0, 0xF003Fu, 0, &hValue, 0) )
    {
     RegSetValueExW(hValue, pName, 0, 0, (BYTE *)pValue, uSize * sizeof(wchar_t));
     RegCloseKey(hValue);
    }
    RegCloseKey(hVer10);
   }
   RegCloseKey(hNewWorldComputing);
  }
  RegCloseKey(hSoftware);
 }
}


//----- (mm7.exe::00464B02) --------------------------------------------------------
void CreateRegistryKey(const char *pName, const char *pValue)
{
 HKEY hSoftware = 0,
      hNewWorldComputing = 0,
      hVer10 = 0,
      hValue = 0;
 if (!RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE", 0, 0x2001Fu, &hSoftware))
 {
  if (!RegCreateKeyExW(hSoftware, L"New World Computing", 0, L"", 0, 983103u, 0, &hNewWorldComputing, 0))
  {
   if (!RegCreateKeyExW(hNewWorldComputing, L"Might and Magic VII", 0, L"", 0, 0xF003Fu, 0, &hVer10, 0))
   {
    if (!RegCreateKeyExW(hVer10, L"1.0", 0, L"", 0, 0xF003Fu, 0, &hValue, 0))
    {
     RegSetValueExA(hValue, pName, 0, REG_SZ, (BYTE *)pValue, lstrlenA(pValue) + 1);
     RegCloseKey(hValue);
    }
    RegCloseKey(hVer10);
   }
   RegCloseKey(hNewWorldComputing);
  }
  RegCloseKey(hSoftware);
 }
}

//----- (0040D2B4) --------------------------------------------------------
int __fastcall sub_40D2B4(int a1, int a2)
{
  int v2; // ebx@1
  int v3; // ebp@1
  int v4; // edi@1
  int result; // eax@3
  int v6; // esi@7
  int v7; // ecx@10
  int v8; // ecx@12
  int v9; // edx@17
  int v10; // ecx@17
  signed int v11; // [sp+10h] [bp-8h]@1
  int *v12; // [sp+14h] [bp-4h]@1

  v11 = 0;
  v3 = a2;
  v4 = a1;
  v2 = (int)byte_4FABD0;
  v12 = &dword_4FAC10;
  while ( *(_BYTE *)v2 )
  {
    result = sub_40E2A7(*v12);
    if ( !result )
    {
      *(_BYTE *)v2 = 0;
      --v11;
      v12 -= 1067;
      v2 -= 4268;
    }
    ++v11;
    v12 += 1067;
    v2 += 4268;
    if ( v11 >= 10 )
      return result;
  }
  v6 = 4268 * v11;
  byte_4FABD0[4268 * v11] = 1;
  if ( v3 <= 0 )
  {
    byte_4FABD1[v6] = 0;
    v3 = -v3;
  }
  else
  {
    byte_4FABD1[v6] = 1;
  }
  *(_DWORD *)((char *)&unk_4FABD4 + v6) = *(_DWORD *)v4 - 20;
  *(int *)((char *)&dword_4FABDC + v6) = *(_DWORD *)v4 + 20;
  *(int *)((char *)&dword_4FABD8 + v6) = *(_DWORD *)(v4 + 4) - 20;
  *(int *)((char *)&dword_4FABE0 + v6) = *(_DWORD *)(v4 + 4) + 20;
  v7 = *(int *)((char *)&dword_4FAC10 + v6);
  *(int *)((char *)&dword_4FABE4 + v6) = -60;
  *(int *)((char *)&dword_4FABE8 + v6) = 60;
  *(int *)((char *)&dword_4FABEC + v6) = 180;
  *(int *)((char *)&dword_4FABF0 + v6) = 1056964608;
  *(int *)((char *)&dword_4FABF4 + v6) = 150;
  *(int *)((char *)&dword_4FABF8 + v6) = 1112014848;
  *(int *)((char *)&dword_4FABFC + v6) = 1077936128;
  *(int *)((char *)&dword_4FAC00 + v6) = 1090519040;
  *(int *)((char *)&dword_4FAC04 + v6) = 5;
  *(int *)((char *)&dword_4FAC08 + v6) = 15;
  *(int *)((char *)&dword_4FAC0C + v6) = (int)((char *)&unk_4FAC14 + v6);
  sub_40E01A(v7, (int)((char *)&unk_4FABD4 + v6));
  if ( 10 * v3 > 150 )
    v3 = 15;
  v8 = *(int *)((char *)&dword_4FAC10 + v6);
  if ( *(_DWORD *)v8 != 1735422580 )
    return 2;
  if ( !*(_BYTE *)(v8 + 89) )
    return 3;
  *(_DWORD *)(v8 + 8) = 10 * v3;
  v9 = *(_DWORD *)(v8 + 4);
  *(float *)(v8 + 48) = 0.0;
  *(_BYTE *)(v8 + 88) = 0;
  *(_DWORD *)(v8 + 68) = 0;
  *(_DWORD *)(v8 + 76) = 0;
  *(_DWORD *)(v8 + 72) = 0;
  *(_DWORD *)(v8 + 80) = 0;
  v10 = *(_DWORD *)(v8 + 84);
  do
  {
    *(_DWORD *)v10 = 0;
    v10 += 28;
    --v9;
  }
  while ( v9 );
  return 0;
}

//----- (0040D402) --------------------------------------------------------
int __fastcall sub_40D402(int a1, int a2)
{
  char *v2; // ecx@1
  int v3; // esi@1
  int result; // eax@3

  v2 = &byte_505708[188 * a1];
  v3 = *((_DWORD *)v2 + 10);
  if ( v3 <= 0 )
  {
    result = 0;
  }
  else
  {
    if ( v3 >= -a2 )
    {
      result = a2;
      *((_DWORD *)v2 + 10) = a2 + v3;
      goto LABEL_7;
    }
    a2 += v3;
    result = -v3;
    *((_DWORD *)v2 + 10) = 0;
  }
  *((_DWORD *)v2 + 9) += a2;
LABEL_7:
  if ( *((_DWORD *)v2 + 9) < 0 )
    *((_DWORD *)v2 + 9) = 0;
  return result;
}

//----- (0040D444) --------------------------------------------------------
int __cdecl sub_40D444()
{
  signed int v0; // edi@1
  int v1; // esi@1
  int v2; // eax@1
  int v3; // eax@23
  int v4; // edx@25
  int v5; // eax@28
  int v6; // ecx@28
  signed int v7; // eax@50
  int v8; // ecx@50
  char *v9; // eax@52
  signed int v10; // eax@54
  int v11; // esi@59
  int v12; // esi@65
  signed int v14; // [sp-4h] [bp-58h]@46
  char Dest; // [sp+Ch] [bp-48h]@1
  int v16; // [sp+4Ch] [bp-8h]@1
  int v17; // [sp+50h] [bp-4h]@1

  v1 = -1;
  v0 = -1;
  compile_error;//nullsub_1(0);
  v16 = 0;
  v17 = 0;
  sub_40DEBE("Ïîáåäè", &Dest);
  v2 = sub_40DED8();
  v17 = 160;
  v16 = 320 - 12 * v2 / 2;
  sub_40D75D(-1, &Dest, (int)&v16);
  if ( dword_50572C[0] < dword_4E1884 )
  {
    if ( dword_5057E8 < dword_4E1884 )
      goto LABEL_10;
    v1 = 2;
  }
  else
  {
    if ( dword_5057E8 < dword_4E1884 )
    {
      v1 = 1;
    }
    else
    {
      if ( dword_50572C[0] == dword_5057E8 )
      {
        v1 = 0;
        v0 = 4;
        goto LABEL_10;
      }
      v1 = (dword_50572C[0] <= dword_5057E8) + 1;
    }
  }
  v0 = 0;
LABEL_10:
  if ( dword_50572C[0] <= 0 )
  {
    if ( dword_5057E8 > 0 )
    {
      v1 = 2;
    }
    else
    {
      if ( dword_50572C[0] == dword_5057E8 )
      {
LABEL_20:
        if ( dword_505730[0] == dword_5057EC )
        {
          v1 = 0;
          v0 = 4;
        }
        else
        {
          v1 = (dword_505730[0] <= dword_5057EC) + 1;
          v0 = 1;
        }
        goto LABEL_23;
      }
      v1 = (dword_50572C[0] <= dword_5057E8) + 1;
    }
    goto LABEL_17;
  }
  if ( dword_5057E8 <= 0 )
  {
    v1 = 1;
LABEL_17:
    v0 = 2;
  }
  if ( !v1 && v0 == 4 )
    goto LABEL_20;
LABEL_23:
  v3 = dword_505740[0];
  if ( dword_505740[0] <= dword_505744[0] )
  {
    v3 = dword_505748[0];
    v4 = dword_505744[0];
    if ( dword_505744[0] > dword_505748[0] )
      goto LABEL_28;
  }
  else
  {
    if ( dword_505740[0] <= dword_505748[0] )
    {
      v4 = dword_505748[0];
      goto LABEL_28;
    }
  }
  v4 = v3;
LABEL_28:
  v6 = dword_5057FC;
  v5 = dword_505800;
  if ( dword_5057FC <= dword_505800 )
  {
    v6 = dword_505804;
    if ( dword_505800 > dword_505804 )
      goto LABEL_33;
    goto LABEL_32;
  }
  v5 = dword_505804;
  if ( dword_5057FC > dword_505804 )
LABEL_32:
    v5 = v6;
LABEL_33:
  if ( v1 == -1 )
  {
    if ( v0 != -1 )
      goto LABEL_49;
    if ( v4 < dword_4E1888 )
    {
      if ( v5 < dword_4E1888 )
        goto LABEL_49;
      v1 = 2;
    }
    else
    {
      if ( v5 < dword_4E1888 )
      {
        v1 = 1;
      }
      else
      {
        if ( v4 == v5 )
          goto LABEL_46;
        v1 = (v4 <= v5) + 1;
      }
    }
    v0 = 3;
  }
  if ( !v1 && v0 == 4 )
  {
    if ( v4 != v5 )
    {
      v14 = 5;
      v1 = (v4 <= v5) + 1;
      goto LABEL_48;
    }
LABEL_46:
    v1 = 0;
    v14 = 4;
LABEL_48:
    v0 = v14;
  }
LABEL_49:
  struct_505898.dword_505948 = v0;
  struct_505898.dword_505944 = v1;
  if ( v1 == 1 )
  {
    v8 = (int)ptr_507BC0;
    v7 = ptr_507BC0->dword_00001C;
    if ( v7 >= 108 )
    {
      if ( v7 <= 120 )
      {
       v9 = (char *)&pParty_global->uNumGoldInBank + v7 + 1;
        if ( !*v9 )
        {
          *v9 = 1;
          sub_420C05((signed __int64)(*((float *)&unk_591458 + 13 * *(_DWORD *)(v8 + 28)) * 100.0), 0);
        }
      }
    }
    v10 = 108;
    do
    {
      if ( !*((char *)&pParty_global->uNumGoldInBank + v10 + 1) )
        break;
      ++v10;
    }
    while ( v10 <= 120 );
    if ( v10 == 121 )
      sub_449B7E((int)pParty_global->unk_000764 + 1, 238, 1);
    v11 = (int)&unk_ACDAD6;
    do
    {
      if ( !(unsigned __int16)sub_449B57(v11, 1) )
        sub_449B7E(v11, 103, 1);
      v11 += 6972;
    }
    while ( v11 < (signed int)&unk_AD47C6 );
    ++dword_ACD82C;
    if ( dword_ACD82C > 1000000 )
      dword_ACD82C = 1000000;
  }
  else
  {
    v12 = (int)&unk_ACDAD6;
    do
    {
      if ( !(unsigned __int16)sub_449B57(v12, 1) )
        sub_449B7E(v12, 104, 1);
      v12 += 6972;
    }
    while ( v12 < (signed int)&unk_AD47C6 );
    ++dword_ACD830;
    if ( dword_ACD830 > 1000000 )
      dword_ACD830 = 1000000;
  }
  return 0;
}

//----- (0040D75D) --------------------------------------------------------
void sub_40D75D(int a1, const char *a2, int a3)
{
  const char *v4; // ST0C_4@1
  __int64 v5; // qax@1

  v4 = a2;
  v5 = *(_BYTE *)(pFontComic + 5) - 3;
  FontDrawText(pGUIWindow0,
           pFontComic,
           *(_DWORD *)a3,
           *(_DWORD *)(a3 + 4) - (((_DWORD)v5 - HIDWORD(v5)) >> 1) + 3,
           v4,
           0,
           0,
           0);
}

//----- (0040D799) --------------------------------------------------------
char __cdecl sub_40D799()
{
  Class33_global0.LODPCXLoad( "layout.pcx", 2);
  struct_505898.dword_5058D4 = (int)Class33_global0.pPixels;
  return 1;
}

//----- (0040D7B7) --------------------------------------------------------
char __cdecl sub_40D7B7()
{
  Class33_global1.LODPCXLoad("sprites.pcx", 2);
  struct_505898.dword_5058D8 = (int)Class33_global1.pPixels;
  return 1;
}

//----- (0040D7D5) --------------------------------------------------------
char __thiscall sub_40D7D5(void *_this, int a2, int a3)
{
  char result; // al@1
  int v4; // esi@1

  v4 = (int)_this;
  result = pD3DRenderer->BeginScene();
  struct_505898.dword_5058DC = v4;
  return result;
}

//----- (0040D7EC) --------------------------------------------------------
void __fastcall sub_40D7EC(int a1, int a2, int a3, int a4)
{
  int v4; // edx@1
  int v5; // ecx@1
  int v6; // esi@1
  int v7; // eax@2
  int v8; // edi@3
  int v9; // ecx@4
  unsigned int v10; // esi@9
  int v11; // edx@11
  int v12; // ebx@11
  char v14; // zf@17
  int v15; // ecx@20
  int v16; // ebx@20
  int v17; // eax@20
  unsigned int v18; // eax@23
  char v20; // zf@26
  char v21; // [sp-18h] [bp-3Ch]@8
  int v22; // [sp-14h] [bp-38h]@8
  int v23; // [sp-10h] [bp-34h]@8
  int v24; // [sp-Ch] [bp-30h]@8
  const char *v25; // [sp-8h] [bp-2Ch]@8
  int v26; // [sp-4h] [bp-28h]@8
  int v27; // [sp+Ch] [bp-18h]@8
  int v28; // [sp+10h] [bp-14h]@9
  int v29; // [sp+14h] [bp-10h]@3
  int v30; // [sp+18h] [bp-Ch]@3
  int v31; // [sp+1Ch] [bp-8h]@5
  int v32; // [sp+23h] [bp-1h]@8
  int v33; // [sp+30h] [bp+Ch]@13

  v6 = a1;
  v5 = *(_DWORD *)a2;
  v4 = *(_DWORD *)(a2 + 4);
  if (pD3DRenderer->bSceneBegun)
  {
    v7 = struct_505898.dword_5058DC;
    if (struct_505898.dword_5058DC)
    {
     v8 = (int)&pD3DRenderer->pTargetSurface[v5 + v4 * pD3DRenderer->uTargetSurfacePitch];
      v29 = *(_DWORD *)(v6 + 8) - *(_DWORD *)v6;
      v30 = *(_DWORD *)(v6 + 12) - *(_DWORD *)(v6 + 4);
      if ( struct_505898.dword_5058DC == struct_505898.dword_5058D4 )
      {
       v9 = Class33_global0.uWidth;
      }
      else
      {
        if ( struct_505898.dword_5058DC != struct_505898.dword_5058D8 )
        {
          v26 = 157;
          v25 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\am_nw.cpp";
          v27 = (int)&v21;
          Game_sub_40E2C8(&v21, "Problem in Blit_Chroma", (int)&v32);
          sub_466D09(&v27, *(int *)&v21, v22, v23, v24, v25, v26);
          v7 = struct_505898.dword_5058DC;
LABEL_9:
          v28 = v7 + 2 * (*(_DWORD *)v6 + v31 * *(_DWORD *)(v6 + 4));
          v10 = 0xFFu >> (8 - pD3DRenderer->uNumTargetBBits);
          v27 = (((pD3DRenderer->uNumTargetGBits != 6) - 1) & 0x4A00) + 12783;
          if ( a4 == 2 )
          {
            if ( v30 > 0 )
            {
              v12 = v29;
              v11 = v28;
              v31 = 2 * (v31 - v29);
              do
              {
                if ( v12 > 0 )
                {
                  v33 = v12;
                  do
                  {
                    if ( *(_WORD *)v11 != v10 )
                      *(_WORD *)v8 = *(_WORD *)v11;
                    v8 += 2;
                    v11 += 2;
                  }
                  while ( v33-- != 1 );
                }
                v11 += v31;
                v14 = v30-- == 1;
                v8 += 2 * (pD3DRenderer->uTargetSurfacePitch - v12);
              }
              while ( !v14 );
            }
          }
          else
          {
            if ( v30 > 0 )
            {
              v16 = v29;
              v17 = v31 - v29;
              v29 = v30;
              v15 = v28;
              v31 = 2 * v17;
              do
              {
                if ( v16 > 0 )
                {
                  v28 = v16;
                  do
                  {
                    v18 = *(_WORD *)v15;
                    if ( v18 != v10 )
                    {
                      v30 = *(_WORD *)v8;
                      *(_WORD *)v8 = (v27 & ((unsigned int)v30 >> 1)) + (v27 & (v18 >> 1));
                    }
                    v8 += 2;
                    v15 += 2;
                  }
                  while ( v28-- != 1 );
                }
                v15 += v31;
                v20 = v29-- == 1;
                v8 += 2 * (pD3DRenderer->uTargetSurfacePitch - v16);
              }
              while ( !v20 );
            }
          }
          return;
        }
        v9 = Class33_global1.uWidth;
      }
      v31 = v9;
      goto LABEL_9;
    }
  }
}

//----- (0040D9B1) --------------------------------------------------------
void __fastcall sub_40D9B1(int a1, int a2, int a3)
{
  int v3; // edx@1
  int v4; // ecx@1
  int v5; // esi@1
  int v6; // eax@2
  int v7; // ebx@3
  int v8; // edi@3
  int v9; // ecx@4
  int v10; // esi@8
  int v11; // edx@9
  int v12; // eax@12
  int v13; // ecx@19
  char v14; // zf@21
  char v15; // [sp-18h] [bp-38h]@7
  int v16; // [sp-14h] [bp-34h]@7
  int v17; // [sp-10h] [bp-30h]@7
  int v18; // [sp-Ch] [bp-2Ch]@7
  const char *v19; // [sp-8h] [bp-28h]@7
  int v20; // [sp-4h] [bp-24h]@7
  unsigned int v21; // [sp+Ch] [bp-14h]@7
  int v22; // [sp+10h] [bp-10h]@8
  int v23; // [sp+14h] [bp-Ch]@17
  int v24; // [sp+18h] [bp-8h]@3
  int v25; // [sp+1Fh] [bp-1h]@7

  v5 = a1;
  v4 = *(_DWORD *)a2;
  v3 = *(_DWORD *)(a2 + 4);
  if ( pD3DRenderer->bSceneBegun)
  {
    v6 = struct_505898.dword_5058DC;
    if ( struct_505898.dword_5058DC )
    {
     v8 = (int)&pD3DRenderer->pTargetSurface[v4 + v3 * pD3DRenderer->uTargetSurfacePitch];
      v7 = *(_DWORD *)(v5 + 8) - *(_DWORD *)v5;
      v24 = *(_DWORD *)(v5 + 12) - *(_DWORD *)(v5 + 4);
      if ( struct_505898.dword_5058DC == struct_505898.dword_5058D4 )
      {
       v9 = Class33_global0.uWidth;
      }
      else
      {
        if ( struct_505898.dword_5058DC == struct_505898.dword_5058D8 )
        {
         v9 = Class33_global1.uWidth;
        }
        else
        {
          v20 = 246;
          v19 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\am_nw.cpp";
          v21 = (unsigned int)&v15;
          Game_sub_40E2C8(&v15, "Problem in Blit_Copy", (int)&v25);
          sub_466D09(&v21, *(int *)&v15, v16, v17, v18, v19, v20);
          v9 = a3;
          v6 = struct_505898.dword_5058DC;
        }
      }
      v10 = v6 + 2 * (*(_DWORD *)v5 + v9 * *(_DWORD *)(v5 + 4));
      v22 = (((pD3DRenderer->uNumTargetGBits != 6) - 1) & 0x4A00) + 12783;
      if ( a3 == 2 )
      {
        v11 = v24;
        if ( v24 > 0 )
        {
          v24 = 2 * (v9 - v7);
          do
          {
            if ( v7 > 0 )
            {
              v12 = v7;
              do
              {
                *(_WORD *)v8 = *(_WORD *)v10;
                v8 += 2;
                v10 += 2;
                --v12;
              }
              while ( v12 );
            }
            v10 += v24;
            --v11;
            v8 += 2 * (pD3DRenderer->uTargetSurfacePitch - v7);
          }
          while ( v11 );
        }
      }
      else
      {
        if ( v24 > 0 )
        {
          v23 = v24;
          v24 = 2 * (v9 - v7);
          do
          {
            if ( v7 > 0 )
            {
              v13 = v7;
              do
              {
                v21 = *(_WORD *)v8;
                *(_WORD *)v8 = (v22 & (v21 >> 1)) + (v22 & ((unsigned int)*(_WORD *)v10 >> 1));
                v8 += 2;
                v10 += 2;
                --v13;
              }
              while ( v13 );
            }
            v10 += v24;
            v14 = v23-- == 1;
            v8 += 2 * (pD3DRenderer->uTargetSurfacePitch - v7);
          }
          while ( !v14 );
        }
      }
    }
  }
}

//----- (0040DB10) --------------------------------------------------------
void *__cdecl sub_40DB10()
{
  void *result; // eax@1

  result = (void *)pD3DRenderer->EndScene();
  struct_505898.dword_5058DC = 0;
  return result;
}

//----- (0040DB22) --------------------------------------------------------
int __stdcall sub_40DB22(int a1, int a2)
{
  return 0;
}

//----- (0040DB27) --------------------------------------------------------
void *__fastcall sub_40DB27(int a1, __int16 a2, char a3)
{
  __int16 v3; // bp@1
  int v4; // esi@1
  int i; // ebx@3

  v4 = a1;
  v3 = a2;
  pD3DRenderer->BeginScene();
  Render_sub_4A0E97(pD3DRenderer, 0, 0, 639, 479);
  if ( a3 )
  {
    for ( i = *(_DWORD *)(v4 + 4); i <= *(_DWORD *)(v4 + 12); ++i )
      Render_FillRect(pD3DRenderer, *(_DWORD *)v4, i, *(_DWORD *)(v4 + 8), i, v3);
  }
  else
  {
    Render_FillRect(pD3DRenderer, *(_DWORD *)v4, *(_DWORD *)(v4 + 4), *(_DWORD *)(v4 + 8), *(_DWORD *)(v4 + 4), v3);
    Render_FillRect(
      pD3DRenderer,
      *(_DWORD *)(v4 + 8),
      *(_DWORD *)(v4 + 4),
      *(_DWORD *)(v4 + 8),
      *(_DWORD *)(v4 + 12),
      v3);
    Render_FillRect(pD3DRenderer, *(_DWORD *)(v4 + 8), *(_DWORD *)(v4 + 12), *(_DWORD *)v4, *(_DWORD *)(v4 + 12), v3);
    Render_FillRect(pD3DRenderer, *(_DWORD *)v4, *(_DWORD *)(v4 + 12), *(_DWORD *)v4, *(_DWORD *)(v4 + 4), v3);
  }
  return (void *)pD3DRenderer->EndScene();
}



//----- (0040DBD3) --------------------------------------------------------
char __fastcall sub_40DBD3(int _this, __int16 a2)
{
  char result; // al@1
  __int16 v3; // di@1
  int v4; // esi@1
  signed int v5; // ecx@2
  signed int v6; // eax@4

  v4 = _this;
  v3 = a2;
  result = pD3DRenderer->BeginScene();
  if ( pD3DRenderer->bSceneBegun)
  {
    v5 = *(_DWORD *)v4;
    if ( *(_DWORD *)v4 >= 0 )
    {
      if ( v5 <= 639 )
      {
        v6 = *(_DWORD *)(v4 + 4);
        if ( v6 >= 0 )
        {
          if ( v6 <= 479 )
            pD3DRenderer->pTargetSurface[v5 + pD3DRenderer->uTargetSurfacePitch * v6] = v3;
        }
      }
    }
    result = (unsigned int)pD3DRenderer->EndScene();
  }
  return result;
}

//----- (00490913) --------------------------------------------------------
signed int __cdecl PlayerCreation_ComputeAttributeBonus()
{
  signed int vStat; // edi@1
  signed int v1; // esi@1
  int r; // ebx@2
  signed int v3; // eax@17
  int v4; // ecx@17
  int v5; // edx@18
  signed int v6; // ecx@18
  signed int v8; // [sp+Ch] [bp-8h]@1
  signed int v9; // [sp+10h] [bp-4h]@2

  v8 = 50;
  vStat = 50;
  for(v1 = 0;v1 < 4; v1 ++)
  {    
    r = Player_GetRace(&pParty_global->pPlayers[v1]);
    for(v9 = 0; v9 <= 6; v9++)
    {
      switch ( v9 )
      {
          case 1:
            vStat = pParty_global->pPlayers[v1].uIntelligence;
            break;
          case 2:
            vStat = pParty_global->pPlayers[v1].uWillpower;
            break;
          case 3:
            vStat = pParty_global->pPlayers[v1].uEndurance;
            break;
          case 4:
            vStat = pParty_global->pPlayers[v1].uAccuracy;
            break;
          case 5:
            vStat = pParty_global->pPlayers[v1].uSpeed;
            break;
          case 6:
            vStat = pParty_global->pPlayers[v1].uLuck;
            break;
          case 0:
          default:
            vStat = pParty_global->pPlayers[v1].uStrength;
            break;
      }
      v3 = g_StatTable[r][v9].InitialStat;
      if ( vStat >= v3 )
      {
        v5 = g_StatTable[r][v9].Ratio1;
        v6 = g_StatTable[r][v9].Ratio2;
      }
      else
      {
        v5 = g_StatTable[r][v9].Ratio2;
        v6 = g_StatTable[r][v9].Ratio1;
      }
      v8 += v5 * (v3 - vStat) / v6;
    }
  }
  return v8;
}

//----- (0045855F) --------------------------------------------------------
int __thiscall sub_45855F(void *_this)
{
  int result; // eax@1

  result = 0;
  *((_DWORD *)_this + 4) = 65536;
  *((_WORD *)_this + 5) = 0;
  *((_WORD *)_this + 4) = 0;
  *((_WORD *)_this + 3) = 0;
  *((_WORD *)_this + 2) = 0;
  *((_WORD *)_this + 1) = 0;
  *((_WORD *)_this + 6) = 0;
  *((_WORD *)_this + 7) = 0;
  return result;
}

//----- (0040DC2D) --------------------------------------------------------
bool __fastcall sub_40DC2D(int a1, void *a2)
{
  BOOL v2; // eax@1
  void *v3; // ebp@1
  int v4; // eax@6
  int v5; // edx@6
  int v6; // edx@6
  int v7; // edx@7

  v3 = a2;
  struct_505898.byte_505898 = 0;
  struct_505898.dword_5058A0 = 0;
  v2 = PeekMessageA(&struct_505898.Msg_global, 0, 0, 0, 1u);
  if ( struct_505898.Msg_global.message == 18 )
    sub_464761(0);
  if ( v2 > 0 )
  {
    TranslateMessage(&struct_505898.Msg_global);
    DispatchMessageA(&struct_505898.Msg_global);
  }
  if (dword_720010)
  {
    EnterCriticalSection(&pGame->class01_obj->cs1);
    v5 = *(_DWORD *)(dword_720010 + 28);
    struct_505898.dword_5058C8 = *(_DWORD *)(dword_720010 + 24);
    struct_505898.dword_5058CC = v5;
    v6 = *(_DWORD *)(dword_720010 + 108);
    v4 = *(_DWORD *)v6;
    if ( *(_DWORD *)v6 != v6 )
    {
      do
      {
        v7 = *(_DWORD *)(v4 + 20);
        if ( v7 & 1 )
        {
          struct_505898.dword_5058A0 = 7;
        }
        else
        {
          if ( v7 & 2 )
            struct_505898.dword_5058A0 = 8;
        }
        v4 = *(_DWORD *)v4;
      }
      while ( v4 != *(_DWORD *)(dword_720010 + 108) );
    }
    sub_46B944(dword_720010);
    if ( !*(_BYTE *)(dword_720010 + 90) )
      struct_505898.byte_50598E = 1;
    LeaveCriticalSection(&pGame->class01_obj->cs1);
  }
  memcpy(v3, &struct_505898.dword_5058A0, 0xCu);
  return struct_505898.dword_5058A0 != 0;
}

//----- (0040DD2C) --------------------------------------------------------
char __cdecl sub_40DD2C()
{
  return 0;
}

//----- (0040DD2F) --------------------------------------------------------
char __thiscall sub_40DD2F(int _this)
{
  *(_DWORD *)_this = struct_505898.dword_5058C8;
  *(_DWORD *)(_this + 4) = struct_505898.dword_5058CC;
  *(_BYTE *)(_this + 8) = struct_505898.byte_5058D0;
  *(_BYTE *)(_this + 9) = struct_505898.byte_5058D0 == struct_505898.byte_50598F;
  *(_BYTE *)(_this + 8) = struct_505898.byte_5058D0;
  *(_BYTE *)(_this + 11) = struct_505898.byte_5058D2 == struct_505898.byte_505990;
  struct_505898.byte_50598F = struct_505898.byte_5058D0;
  struct_505898.byte_505990 = struct_505898.byte_5058D2;
  return 1;
}

//----- (0040DD93) --------------------------------------------------------
char __fastcall sub_40DD93(int a1, int a2)
{
  int v2; // eax@3

  return *(_DWORD *)a1 >= *(_DWORD *)a2
      && *(_DWORD *)a1 <= *(_DWORD *)(a2 + 8)
      && (v2 = *(_DWORD *)(a1 + 4), v2 >= *(_DWORD *)(a2 + 4))
      && v2 <= *(_DWORD *)(a2 + 12);
}

//----- (0040DDB1) --------------------------------------------------------
int __fastcall sub_40DDB1(int a1, int a2)
{
  return a1 + rand() % (a2 - a1 + 1);
}

//----- (0040DDC9) --------------------------------------------------------
void __thiscall sub_40DDC9(void *_this)
{
  int v1; // eax@10
  signed int v2; // [sp-4h] [bp-4h]@2

  switch ((unsigned long)(_this))
  {
    case 0x28u:
    case 0x2Bu:
    case 0x2Eu:
      v2 = 120;
      goto LABEL_10;
    case 0x27u:
    case 0x29u:
    case 0x2Au:
    case 0x2Cu:
    case 0x2Du:
    case 0x2Fu:
      v2 = 121;
      goto LABEL_10;
    case 0u:
    case 0xCu:
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x30u:
    case 0x32u:
    case 0x35u:
      v2 = 122;
      goto LABEL_10;
    case 0x15u:
    case 0x16u:
    case 0x17u:
      v2 = 123;
      goto LABEL_10;
    case 0x38u:
      v2 = 124;
      goto LABEL_10;
    case 0x1Fu:
    case 0x22u:
    case 0x25u:
      v2 = 125;
      goto LABEL_10;
    case 1u:
    case 0x1Eu:
    case 0x20u:
    case 0x21u:
    case 0x23u:
    case 0x24u:
    case 0x26u:
      v2 = 126;
      goto LABEL_10;
    case 0x14u:
      v2 = 127;
LABEL_10:
      v1 = v2;
      goto LABEL_16;
    case 3u:
      v1 = 128;
      goto LABEL_16;
    case 0x34u:
    case 0x36u:
      v1 = 129;
      goto LABEL_16;
    case 0xAu:
    case 0xBu:
    case 0xDu:
      v1 = 130;
      goto LABEL_16;
    case 0x37u:
      v1 = 131;
      goto LABEL_16;
    case 0x31u:
    case 0x33u:
      v1 = 132;
LABEL_16:
      AudioPlayer_sub_4AA306(pAudioPlayer, v1, 0, 0, -1, 0, 0, 0, 0);
      break;
    default:
      return;
  }
}

//----- (0040DEA5) --------------------------------------------------------
int __cdecl sub_40DEA5()
{
  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  return 0;
}

//----- (0040DEB4) --------------------------------------------------------
char *__fastcall sub_40DEB4(const char *Source, char *Dest)
{
  return strcat(Dest, Source);
}

//----- (0040DEBE) --------------------------------------------------------
char *__fastcall sub_40DEBE(const char *Source, char *Dest)
{
  return strcpy(Dest, Source);
}

//----- (0040DEC8) --------------------------------------------------------
int __fastcall sub_40DEC8(int a1, int a2)
{
  return wsprintfA((char *)a2, "%d", a1);
}

//----- (0040DED8) --------------------------------------------------------
int __cdecl sub_40DED8()
{
  return 0;
}

//----- (0040DEDB) --------------------------------------------------------
unsigned int __stdcall sub_40DEDB(int a1)
{
  //return sub_40DEF3_LooksLikeGenerateColorAsCloseAsPossibleToR8G8B8InDstFormat((unsigned __int8)a1, BYTE1(a1), BYTE2(a1));
 return 0xFF000000 | ((a1 & 0x000000FF) << 16) | (a1 & 0x0000FF00) | ((a1 & 0x00FF0000) >> 16);
}


//----- (0040DF3D) --------------------------------------------------------
signed int __cdecl sub_40DF3D()
{
  return pD3DRenderer->Present();
}

//----- (0040DF47) --------------------------------------------------------
void *__thiscall sub_40DF47(void *_this)
{
  void *result; // eax@1
  int v2; // ebx@1
  int v3; // [sp+Ch] [bp-18h]@1
  int v4; // [sp+10h] [bp-14h]@1
  int v5; // [sp+14h] [bp-10h]@1
  int v6; // [sp+18h] [bp-Ch]@1
  int v7; // [sp+1Ch] [bp-8h]@1
  int v8; // [sp+20h] [bp-4h]@1

  v2 = (int)_this;
  pD3DRenderer->Present();
  v7 = 0;
  v8 = 0;
  v3 = 0;
  v5 = 640;
  v4 = 0;
  v6 = 480;
  pD3DRenderer->BeginScene();
  struct_505898.dword_5058DC = v2;
  sub_40D9B1((int)&v3, (int)&v7, 2);
  result = (void *)pD3DRenderer->EndScene();
  struct_505898.dword_5058DC = 0;
  return result;
}

//----- (0040DFA7) --------------------------------------------------------
int __stdcall sub_40DFA7(int a1)
{
  return 0;
}

//----- (0040DFAF) --------------------------------------------------------
__int64 __fastcall sub_40DFAF(__int64 result, char a2)
{
  if ( a2 )
    struct_505898.byte_5058D2 = BYTE4(result);
  else
    struct_505898.byte_5058D0 = BYTE4(result);
  return result;
}

//----- (0040DFC1) --------------------------------------------------------
int __thiscall sub_40DFC1(int _this)
{
  int result; // eax@1

  struct_505898.dword_5058C8 = *(_DWORD *)_this;
  result = *(_DWORD *)(_this + 4);
  struct_505898.dword_5058CC = *(_DWORD *)(_this + 4);
  return result;
}

//----- (0040DFD1) --------------------------------------------------------
int __thiscall sub_40DFD1(void *_this)
{
  int result; // eax@1
  void *v2; // esi@1
  void *v3; // eax@1

  v2 = _this;
  v3 = malloc(0x5Cu);
  *(_DWORD *)v2 = (int)v3;
  *(_DWORD *)v3 = 1735422580;
  result = 0;
  *(_DWORD *)(*(_DWORD *)v2 + 8) = 0;
  *(float *)(*(_DWORD *)v2 + 48) = 0.0;
  *(_BYTE *)(*(_DWORD *)v2 + 88) = 0;
  *(_BYTE *)(*(_DWORD *)v2 + 89) = 0;
  return result;
}

//----- (0040DFFE) --------------------------------------------------------
function_error;//signed int __usercall sub_40DFFE<eax>(int a1<eax>, unsigned int a2<ecx>)
//a1 is not passed here at all
signed int __fastcall sub_40DFFE(int a1, unsigned int a2)
{
  signed int result; // eax@2

  if ( *(_DWORD *)a2 == 1735422580 )
  {
    *(_DWORD *)a2 = 0x78787878;
    free((void *)a2);
    result = 0;
  }
  else
  {
    result = 2;
  }
  return result;
}

//----- (0040E01A) --------------------------------------------------------
signed int __fastcall sub_40E01A(int a1, int a2)
{
  signed int result; // eax@2

  if ( *(_DWORD *)a1 == 1735422580 )
  {
    *(_DWORD *)(a1 + 4) = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(a1 + 12) = *(_DWORD *)a2 << 16;
    *(_DWORD *)(a1 + 16) = *(_DWORD *)(a2 + 4) << 16;
    *(_DWORD *)(a1 + 20) = *(_DWORD *)(a2 + 8) << 16;
    *(_DWORD *)(a1 + 24) = *(_DWORD *)(a2 + 12) << 16;
    *(_DWORD *)(a1 + 28) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(a1 + 32) = *(_DWORD *)(a2 + 20);
    *(_DWORD *)(a1 + 36) = *(_DWORD *)(a2 + 24);
    *(float *)(a1 + 40) = *(float *)(a2 + 28) * 65536.0;
    *(_DWORD *)(a1 + 44) = *(_DWORD *)(a2 + 36);
    *(_DWORD *)(a1 + 52) = (signed __int64)(*(float *)(a2 + 40) * 65536.0);
    *(_DWORD *)(a1 + 56) = (signed __int64)(*(float *)(a2 + 44) * 65536.0);
    *(_DWORD *)(a1 + 60) = *(_DWORD *)(a2 + 48);
    *(_DWORD *)(a1 + 64) = *(_DWORD *)(a2 + 52);
    *(_DWORD *)(a1 + 84) = *(_DWORD *)(a2 + 56);
    *(_BYTE *)(a1 + 89) = 1;
    result = 0;
  }
  else
  {
    result = 2;
  }
  return result;
}

//----- (0040E0F5) --------------------------------------------------------
signed int __fastcall sub_40E0F5(int a1, char a2, char a3)
{
  signed int result; // eax@2
  int v4; // eax@7
  int v5; // edx@7

  if ( *(_DWORD *)a1 == 1735422580 )
  {
    if ( a2 )
    {
      *(_DWORD *)(a1 + 8) = 0;
      *(float *)(a1 + 48) = 0.0;
    }
    if ( *(_BYTE *)(a1 + 89) )
    {
      if ( a3 )
      {
        v5 = *(_DWORD *)(a1 + 4);
        v4 = *(_DWORD *)(a1 + 84);
        do
        {
          *(_DWORD *)v4 = 0;
          v4 += 28;
          --v5;
        }
        while ( v5 );
        *(_BYTE *)(a1 + 88) = 0;
      }
    }
    result = 0;
  }
  else
  {
    result = 2;
  }
  return result;
}

//----- (0040E133) --------------------------------------------------------
signed int __thiscall sub_40E133(int _this)
{
  int v1; // edi@1
  double v3; // st7@3
  signed int v4; // ST18_4@3
  double v5; // st6@4
  char v6; // bl@8
  int v7; // esi@8
  int v8; // ecx@10
  signed int v9; // eax@10
  int v10; // ecx@10
  signed int v11; // eax@10
  signed int v12; // edx@12
  signed int v13; // edx@12
  char v14; // zf@14
  int v15; // [sp+8h] [bp-10h]@8
  int v16; // [sp+Ch] [bp-Ch]@8
  float v17; // [sp+14h] [bp-4h]@3

  v1 = _this;
  if ( *(_DWORD *)_this != 1735422580 )
    return 2;
  v4 = *(_DWORD *)(_this + 8);
  LODWORD(v17) = *(_DWORD *)(_this + 48);
  v3 = (double)v4;
  if ( v4 > 0 )
  {
    v5 = v17 + *(float *)(_this + 44);
    v17 = v5;
    if ( v5 > v3 )
      v17 = v3;
  }
  if ( v17 >= 1.0 || *(_BYTE *)(_this + 88) )
  {
    v6 = 0;
    v7 = *(_DWORD *)(_this + 84);
    v15 = (signed __int64)*(float *)(_this + 40);
    v16 = *(_DWORD *)(_this + 4);
    while ( *(_DWORD *)v7 <= 0 )
    {
      if ( v17 >= 1.0 )
      {
        *(_DWORD *)v7 = *(_DWORD *)(v1 + 60) + rand() % (*(_DWORD *)(v1 + 64) - *(_DWORD *)(v1 + 60) + 1);
        *(_DWORD *)(v7 + 20) = (rand() % 17 - 8) << 16;
        *(_DWORD *)(v7 + 24) = (rand() % 17 - 8) << 16;
        v12 = *(_DWORD *)(v1 + 12) + rand() % (*(_DWORD *)(v1 + 20) - 1 - *(_DWORD *)(v1 + 12) + 1);
        *(_DWORD *)(v7 + 12) = v12;
        *(_DWORD *)(v7 + 4) = v12 >> 16;
        v17 = v17 - 1.0;
        v13 = *(_DWORD *)(v1 + 16) + rand() % (*(_DWORD *)(v1 + 24) - 1 - *(_DWORD *)(v1 + 16) + 1);
        *(_DWORD *)(v7 + 16) = v13;
        *(_DWORD *)(v7 + 8) = v13 >> 16;
        --*(_DWORD *)(v1 + 8);
        goto LABEL_13;
      }
LABEL_14:
      v7 += 28;
      v14 = v16-- == 1;
      if ( v14 )
      {
        *(_BYTE *)(v1 + 88) = v6;
        *(_DWORD *)(v1 + 48) = LODWORD(v17);
        return 0;
      }
    }
    v8 = *(_DWORD *)(v7 + 20);
    --*(_DWORD *)v7;
    v9 = v8 + *(_DWORD *)(v7 + 12);
    v10 = v15 + *(_DWORD *)(v7 + 24);
    *(_DWORD *)(v7 + 12) = v9;
    *(_DWORD *)(v7 + 4) = v9 >> 16;
    v11 = v10 + *(_DWORD *)(v7 + 16);
    *(_DWORD *)(v7 + 24) = v10;
    *(_DWORD *)(v7 + 16) = v11;
    *(_DWORD *)(v7 + 8) = v11 >> 16;
LABEL_13:
    v6 = 1;
    goto LABEL_14;
  }
  return 0;
}

//----- (0040E2A7) --------------------------------------------------------
int __thiscall sub_40E2A7(int _this)
{
  int result; // eax@2

  if ( *(_DWORD *)_this == 1735422580 )
  {
    if ( *(_DWORD *)(_this + 8) <= 0 )
      result = *(_BYTE *)(_this + 88) != 0 ? 2 : 0;
    else
      result = 1;
  }
  else
  {
    result = 3;
  }
  return result;
}

//----- (0040E2C8) --------------------------------------------------------
int __thiscall Game_sub_40E2C8(void *_this, const char *Src, int a3)
{
  int v4; // esi@1
  size_t v5; // eax@1

  v4 = (int)_this;
  *(_BYTE *)_this = *(_BYTE *)a3;
  CGame_stru0_sub_40E2F6((CGame_stru0 *)_this, 0);
  v5 = strlen(Src);
  sub_40E32E(v4, Src, v5);
  return v4;
}

//----- (0040E32E) --------------------------------------------------------
int __thiscall sub_40E32E(int _this, const void *Src, size_t Size)
{
  int v3; // esi@1
  int v4; // eax@2

  v3 = _this;
  if ( sub_40E363(_this, Size, 1) )
  {
    memcpy(*(void **)(v3 + 4), Src, Size);
    v4 = *(_DWORD *)(v3 + 4);
    *(_DWORD *)(v3 + 8) = Size;
    *(_BYTE *)(Size + v4) = 0;
  }
  return v3;
}

//----- (0040E363) --------------------------------------------------------
char __thiscall sub_40E363(int _this, unsigned int a2, char a3)
{
  int v3; // esi@1
  int v4; // eax@3
  char v5; // cl@4
  int v6; // ecx@6
  unsigned int v8; // eax@16
  char v9; // [sp-4h] [bp-Ch]@7

  v3 = _this;
  if ( a2 > 0xFFFFFFFD )
    sub_4CA338();
  v4 = *(_DWORD *)(_this + 4);
  if ( v4 )
  {
    v5 = *(_BYTE *)(v4 - 1);
    if ( v5 )
    {
      if ( v5 != -1 )
      {
        v6 = v3;
        if ( !a2 )
        {
          --*(_BYTE *)(v4 - 1);
          v9 = 0;
          goto LABEL_8;
        }
        goto LABEL_20;
      }
    }
  }
  if ( !a2 )
  {
    if ( !a3 )
    {
      if ( v4 )
      {
        *(_DWORD *)(v3 + 8) = 0;
        *(_BYTE *)v4 = 0;
      }
      return 0;
    }
    v9 = 1;
    v6 = v3;
LABEL_8:
    CGame_stru0_sub_40E2F6((CGame_stru0 *)v6, v9);
    return 0;
  }
  if ( a3 )
  {
    v8 = *(_DWORD *)(v3 + 12);
    if ( v8 <= 0x1F && v8 >= a2 )
      return 1;
    CGame_stru0_sub_40E2F6((CGame_stru0 *)v3, 1);
    goto LABEL_20;
  }
  if ( *(_DWORD *)(v3 + 12) < a2 )
LABEL_20:
    std__basic_string_char_std__char_traits_char__std__allocator_char_____Copy(a2);
  return 1;
}

//----- (0040E4C2) --------------------------------------------------------
void sub_40E4C2(struct class04_stru0 *_this)
{
 int i;

 _this->dword_000004 = -1;
 for (i = 0; i < 64; ++i)
   _this->unk_000018[i][0] = 0;

 _this->ptr_000000 = (char *)0x4D84AC;
}



//----- (004637E0) --------------------------------------------------------
char __cdecl sub_4637E0()
{
  return dword_507BF0 == 1;
}

//----- (0040E55E) --------------------------------------------------------
signed int __thiscall sub_40E55E(void *Source, unsigned int Filename, unsigned int a3)
{
  char *v3; // esi@1
  signed int result; // eax@2
  char *v5; // eax@3
  int v6; // edx@3
  FILE *v7; // edi@3
  char v8; // cl@4
  int v9; // eax@9
  int v10; // ecx@9
  int v11; // eax@9
  char v12; // zf@9
  int v13; // eax@12
  signed int v14; // ecx@19
  signed int v15; // ecx@24
  int v16; // edi@57
  int v17; // eax@57
  int v18; // ecx@57
  signed int v19; // eax@59
  int v20; // edi@64
  signed int v21; // eax@66
  int v22; // edi@71
  signed int v23; // eax@73
  int v24; // eax@78
  char v25; // [sp+Ch] [bp-54h]@3
  char DstBuf; // [sp+3Ch] [bp-24h]@3
  char v27; // [sp+3Dh] [bp-23h]@3
  char v28; // [sp+3Eh] [bp-22h]@3
  char v29; // [sp+3Fh] [bp-21h]@3
  int v30; // [sp+40h] [bp-20h]@3
  int v31; // [sp+44h] [bp-1Ch]@3
  char v32; // [sp+48h] [bp-18h]@3
  char v33; // [sp+4Ah] [bp-16h]@3
  char v34; // [sp+4Ch] [bp-14h]@3
  char v35; // [sp+4Dh] [bp-13h]@3
  unsigned __int16 v36; // [sp+4Eh] [bp-12h]@3
  int v37; // [sp+54h] [bp-Ch]@3
  int v38; // [sp+58h] [bp-8h]@57
  FILE *File; // [sp+5Ch] [bp-4h]@1

  v3 = (char *)Source;
  File = fopen((const char *)Filename, "rb");
  if ( !File )
    return 1;
  v7 = File;
  locked_fread(&DstBuf, 1u, 1u, File);
  locked_fread(&v27, 1u, 1u, v7);
  locked_fread(&v28, 1u, 1u, v7);
  locked_fread(&v29, 1u, 1u, v7);
  locked_fread(&v30, 2, 1u, v7);
  locked_fread((char *)&v30 + 2, 2, 1u, File);
  locked_fread(&v31, 2, 1u, File);
  locked_fread((char *)&v31 + 2, 2, 1u, File);
  locked_fread(&v32, 2, 1u, File);
  locked_fread(&v33, 2, 1u, File);
  locked_fread(&v25, 0x30u, 1u, File);
  locked_fread(&v34, 1u, 1u, File);
  locked_fread(&v35, 1u, 1u, File);
  locked_fread(&v36, 2, 1u, File);
  v5 = (char *)Filename;
  v37 = 0;
  v6 = (int)&v3[-Filename];
  do
  {
    v8 = *v5;
    if ( !*v5 )
      break;
    if ( v8 == 46 )
      break;
    ++v37;
    (v5++)[v6] = v8;
  }
  while ( v37 < 15 );
  v3[v37] = 0;
  if ( v29 != 8 )
    return 3;
  v10 = v31 - v30 + 1;
  v11 = *(int *)((char *)&v31 + 2) - *(int *)((char *)&v30 + 2);
  *((_WORD *)v3 + 10) = v10;
  ++v11;
  *((_WORD *)v3 + 11) = v11;
  v9 = (signed __int16)v10 * (signed __int16)v11;
  v12 = a3 == 0;
  *((_DWORD *)v3 + 4) = v9;
  if ( v12 )
  {
    if ( *((_DWORD *)v3 + 9) )
      mem_mng.DeleteBuffer( (void *)*((_DWORD *)v3 + 9));
    v13 = (int)mem_mng.AllocatedNamedBuffer( (void*) *((_DWORD *)v3 + 9), 2 * *((_DWORD *)v3 + 4) + 4, v3);
    goto LABEL_16;
  }
  if ( a3 != 1 && a3 == 2 )
  {
    compile_error;//v13 = (int)operator new(4 * v9 + 8);
    *((_DWORD *)v3 + 8) |= 1u;
LABEL_16:
    *((_DWORD *)v3 + 9) = v13;
  }
  if ( *((_DWORD *)v3 + 9) )
  {
    v14 = 1;
    while ( 1 << v14 != *((_WORD *)v3 + 10) )
    {
      ++v14;
      if ( v14 >= 15 )
        goto LABEL_24;
    }
    *((_WORD *)v3 + 12) = v14;
LABEL_24:
    v15 = 1;
    while ( 1 << v15 != *((_WORD *)v3 + 11) )
    {
      ++v15;
      if ( v15 >= 15 )
        goto LABEL_29;
    }
    *((_WORD *)v3 + 13) = v15;
LABEL_29:
    switch ( *((_WORD *)v3 + 12) )
    {
      case 2:
        *((_WORD *)v3 + 14) = 3;
        break;
      case 3:
        *((_WORD *)v3 + 14) = 7;
        break;
      case 4:
        *((_WORD *)v3 + 14) = 15;
        break;
      case 5:
        *((_WORD *)v3 + 14) = 31;
        break;
      case 6:
        *((_WORD *)v3 + 14) = 63;
        break;
      case 7:
        *((_WORD *)v3 + 14) = 127;
        break;
      case 8:
        *((_WORD *)v3 + 14) = 255;
        break;
      case 9:
        *((_WORD *)v3 + 14) = 511;
        break;
      case 10:
        *((_WORD *)v3 + 14) = 1023;
        break;
      case 11:
        *((_WORD *)v3 + 14) = 2047;
        break;
      case 12:
        *((_WORD *)v3 + 14) = 4095;
        break;
      default:
        break;
    }
    switch ( *((_WORD *)v3 + 13) )
    {
      case 2:
        *((_WORD *)v3 + 15) = 3;
        break;
      case 3:
        *((_WORD *)v3 + 15) = 7;
        break;
      case 4:
        *((_WORD *)v3 + 15) = 15;
        break;
      case 5:
        *((_WORD *)v3 + 15) = 31;
        break;
      case 6:
        *((_WORD *)v3 + 15) = 63;
        break;
      case 7:
        *((_WORD *)v3 + 15) = 127;
        break;
      case 8:
        *((_WORD *)v3 + 15) = 255;
        break;
      case 9:
        *((_WORD *)v3 + 15) = 511;
        break;
      case 10:
        *((_WORD *)v3 + 15) = 1023;
        break;
      case 11:
        *((_WORD *)v3 + 15) = 2047;
        break;
      case 12:
        *((_WORD *)v3 + 15) = 4095;
        break;
      default:
        break;
    }
    fseek(File, 128, 0);
    ftell(File);
    if ( v35 == 1 )
      erroneous_printf("24bit PCX Only!");
    if ( v35 == 3 )
    {
      v37 = 0;
      if ( *((_WORD *)v3 + 11) > 0 )
      {
        do
        {
          v17 = v37 * *((_WORD *)v3 + 10);
          v18 = *((_DWORD *)v3 + 9);
          v38 = 0;
          v16 = v18 + 2 * v17;
          if ( v36 )
          {
            do
            {
              locked_fread((char *)&Filename + 3, 1u, 1u, File);
              if ( (BYTE3(Filename) & 0xC0) == -64 )
              {
                BYTE3(Filename) &= 0x3Fu;
                locked_fread((char *)&a3 + 3, 1u, 1u, File);
                v19 = 0;
                if ( BYTE3(Filename) )
                {
                  do
                  {
                    ++v38;
                    *(_WORD *)v16 = pD3DRenderer->uTargetRMask & (BYTE3(a3) << (pD3DRenderer->uNumTargetGBits
                                                                + (_BYTE)pD3DRenderer->uNumTargetRBits
                                                                + (_BYTE)pD3DRenderer->uNumTargetBBits
                                                                - 8));
                    v16 += 2;
                    ++v19;
                  }
                  while ( v19 < BYTE3(Filename) );
                }
              }
              else
              {
                ++v38;
                *(_WORD *)v16 = pD3DRenderer->uTargetRMask & (BYTE3(Filename) << (pD3DRenderer->uNumTargetGBits
                                                                  + (_BYTE)pD3DRenderer->uNumTargetRBits
                                                                  + (_BYTE)pD3DRenderer->uNumTargetBBits
                                                                  - 8));
                v16 += 2;
              }
            }
            while ( v38 < v36 );
          }
          v20 = *((_DWORD *)v3 + 9) + 2 * v37 * *((_WORD *)v3 + 10);
          while ( v38 < 2 * v36 )
          {
            locked_fread((char *)&Filename + 3, 1u, 1u, File);
            if ( (BYTE3(Filename) & 0xC0) == -64 )
            {
              BYTE3(Filename) &= 0x3Fu;
              locked_fread((char *)&a3 + 3, 1u, 1u, File);
              v21 = 0;
              if ( BYTE3(Filename) )
              {
                do
                {
                  *(_WORD *)v20 |= (_WORD)pD3DRenderer->uTargetGMask & (unsigned __int16)(BYTE3(a3) << (pD3DRenderer->uNumTargetGBits
                                                                                        + (_BYTE)pD3DRenderer->uNumTargetBBits
                                                                                        - 8));
                  ++v38;
                  v20 += 2;
                  ++v21;
                }
                while ( v21 < BYTE3(Filename) );
              }
            }
            else
            {
              *(_WORD *)v20 |= (_WORD)pD3DRenderer->uTargetGMask & (unsigned __int16)(BYTE3(Filename) << (pD3DRenderer->uNumTargetGBits
                                                                                          + (_BYTE)pD3DRenderer->uNumTargetBBits
                                                                                          - 8));
              ++v38;
              v20 += 2;
            }
          }
          v22 = *((_DWORD *)v3 + 9) + 2 * v37 * *((_WORD *)v3 + 10);
          while ( v38 < 3 * v36 )
          {
            locked_fread((char *)&Filename + 3, 1u, 1u, File);
            if ( (BYTE3(Filename) & 0xC0) == -64 )
            {
              BYTE3(Filename) &= 0x3Fu;
              locked_fread((char *)&a3 + 3, 1u, 1u, File);
              v23 = 0;
              if ( BYTE3(Filename) )
              {
                do
                {
                  *(_WORD *)v22 |= BYTE3(a3) >> (8 - pD3DRenderer->uNumTargetBBits);
                  ++v38;
                  v22 += 2;
                  ++v23;
                }
                while ( v23 < BYTE3(Filename) );
              }
            }
            else
            {
              *(_WORD *)v22 |= BYTE3(Filename) >> (8 - pD3DRenderer->uNumTargetBBits);
              ++v38;
              v22 += 2;
            }
          }
          v24 = *((_WORD *)v3 + 11);
          ++v37;
        }
        while ( v37 < v24 );
      }
    }
    fclose(File);
    result = 0;
  }
  else
  {
    result = 2;
  }
  return result;
}

//----- (0040EAD8) --------------------------------------------------------
signed int __thiscall sub_40EAD8(void *Source, FILE *File, unsigned int a3, int a4)
{
  void *v4; // esi@1
  signed int result; // eax@2
  signed int v6; // ebx@3
  int v7; // eax@5
  int v8; // ecx@5
  int v9; // eax@5
  char v10; // zf@5
  signed int v11; // ecx@14
  signed int v12; // ecx@19
  int v13; // ebx@19
  int v14; // ebx@52
  int v15; // edi@52
  __int16 v16; // ax@54
  int v17; // edi@59
  __int16 v18; // ax@61
  int v19; // edi@66
  unsigned __int16 v20; // ax@68
  int v21; // eax@73
  char v22; // [sp+Ch] [bp-90h]@3
  char v23; // [sp+48h] [bp-54h]@3
  char DstBuf; // [sp+78h] [bp-24h]@3
  char v25; // [sp+79h] [bp-23h]@3
  char v26; // [sp+7Ah] [bp-22h]@3
  char v27; // [sp+7Bh] [bp-21h]@3
  int v28; // [sp+7Ch] [bp-20h]@3
  int v29; // [sp+80h] [bp-1Ch]@3
  char v30; // [sp+84h] [bp-18h]@3
  char v31; // [sp+86h] [bp-16h]@3
  char v32; // [sp+88h] [bp-14h]@3
  char v33; // [sp+89h] [bp-13h]@3
  unsigned __int16 v34; // [sp+8Ah] [bp-12h]@3
  char v35; // [sp+8Ch] [bp-10h]@3
  int v36; // [sp+90h] [bp-Ch]@51
  int v37; // [sp+94h] [bp-8h]@54
  unsigned __int8 v38; // [sp+9Bh] [bp-1h]@54

  v4 = Source;
  if ( File )
  {
    locked_fread(&DstBuf, 1u, 1u, File);
    locked_fread(&v25, 1u, 1u, File);
    locked_fread(&v26, 1u, 1u, File);
    locked_fread(&v27, 1u, 1u, File);
    v6 = 2;
    locked_fread(&v28, 2, 1u, File);
    locked_fread((char *)&v28 + 2, 2, 1u, File);
    locked_fread(&v29, 2, 1u, File);
    locked_fread((char *)&v29 + 2, 2, 1u, File);
    locked_fread(&v30, 2, 1u, File);
    locked_fread(&v31, 2, 1u, File);
    locked_fread(&v23, 0x30u, 1u, File);
    locked_fread(&v32, 1u, 1u, File);
    locked_fread(&v33, 1u, 1u, File);
    locked_fread(&v34, 2, 1u, File);
    locked_fread(&v35, 2, 1u, File);
    locked_fread(&v22, 0x3Au, 1u, File);
    if ( v27 == 8 )
    {
      v8 = v29 - v28 + 1;
      v9 = *(int *)((char *)&v29 + 2) - *(int *)((char *)&v28 + 2);
      *((_WORD *)v4 + 10) = v8;
      ++v9;
      *((_WORD *)v4 + 11) = v9;
      v7 = (signed __int16)v8 * (signed __int16)v9;
      v10 = a3 == 0;
      *((_DWORD *)v4 + 4) = v7;
      if ( v10 )
      {
        if ( *((_DWORD *)v4 + 9) )
        {
          mem_mng.DeleteBuffer( (void *)*((_DWORD *)v4 + 9));
          *((_DWORD *)v4 + 9) = 0;
        }
        *((_DWORD *)v4 + 9) = (int)mem_mng.AllocatedNamedBuffer(
                                ((_DWORD *)v4 + 9),
                                2 * *((_DWORD *)v4 + 4) + 4,
                                (const char *)v4);
        v6 = 2;
      }
      else
      {
        if ( a3 != 1 )
        {
          if ( a3 == 2 )
          {
            compile_error;//operator new(2 * v7 + 4);
            *((_DWORD *)v4 + 9) = 0;
            *((_DWORD *)v4 + 8) |= 1u;
          }
        }
      }
      if ( *((_DWORD *)v4 + 9) )
      {
        v11 = 1;
        while ( 1 << v11 != *((_WORD *)v4 + 10) )
        {
          ++v11;
          if ( v11 >= 15 )
            goto LABEL_19;
        }
        *((_WORD *)v4 + 12) = v11;
LABEL_19:
        v13 = *((_WORD *)v4 + 11);
        v12 = 1;
        while ( 1 << v12 != v13 )
        {
          ++v12;
          if ( v12 >= 15 )
            goto LABEL_24;
        }
        *((_WORD *)v4 + 13) = v12;
LABEL_24:
        switch ( *((_WORD *)v4 + 12) )
        {
          case 2:
            *((_WORD *)v4 + 14) = 3;
            break;
          case 3:
            *((_WORD *)v4 + 14) = 7;
            break;
          case 4:
            *((_WORD *)v4 + 14) = 15;
            break;
          case 5:
            *((_WORD *)v4 + 14) = 31;
            break;
          case 6:
            *((_WORD *)v4 + 14) = 63;
            break;
          case 7:
            *((_WORD *)v4 + 14) = 127;
            break;
          case 8:
            *((_WORD *)v4 + 14) = 255;
            break;
          case 9:
            *((_WORD *)v4 + 14) = 511;
            break;
          case 10:
            *((_WORD *)v4 + 14) = 1023;
            break;
          case 11:
            *((_WORD *)v4 + 14) = 2047;
            break;
          case 12:
            *((_WORD *)v4 + 14) = 4095;
            break;
          default:
            break;
        }
        switch ( *((_WORD *)v4 + 13) )
        {
          case 2:
            *((_WORD *)v4 + 15) = 3;
            break;
          case 3:
            *((_WORD *)v4 + 15) = 7;
            break;
          case 4:
            *((_WORD *)v4 + 15) = 15;
            break;
          case 5:
            *((_WORD *)v4 + 15) = 31;
            break;
          case 6:
            *((_WORD *)v4 + 15) = 63;
            break;
          case 7:
            *((_WORD *)v4 + 15) = 127;
            break;
          case 8:
            *((_WORD *)v4 + 15) = 255;
            break;
          case 9:
            *((_WORD *)v4 + 15) = 511;
            break;
          case 10:
            *((_WORD *)v4 + 15) = 1023;
            break;
          case 11:
            *((_WORD *)v4 + 15) = 2047;
            break;
          case 12:
            *((_WORD *)v4 + 15) = 4095;
            break;
          default:
            break;
        }
        if ( v33 == 1 )
          erroneous_printf("24bit PCX Only!");
        if ( v33 == 3 )
        {
          v36 = 0;
          if ( v13 > 0 )
          {
            do
            {
              v14 = 0;
              v15 = *((_DWORD *)v4 + 9) + 2 * v36 * *((_WORD *)v4 + 10);
              if ( v34 )
              {
                do
                {
                  locked_fread((char *)&a3 + 3, 1u, 1u, File);
                  if ( (BYTE3(a3) & 0xC0) == -64 )
                  {
                    BYTE3(a3) &= 0x3Fu;
                    locked_fread(&v38, 1u, 1u, File);
                    v37 = 0;
                    v16 = v38;
                    if ( BYTE3(a3) )
                    {
                      do
                      {
                        ++v14;
                        *(_WORD *)v15 = pD3DRenderer->uTargetRMask & (v16 << (pD3DRenderer->uNumTargetGBits
                                                              + (_BYTE)pD3DRenderer->uNumTargetRBits
                                                              + (_BYTE)pD3DRenderer->uNumTargetBBits
                                                              - 8));
                        v15 += 2;
                        ++v37;
                      }
                      while ( v37 < BYTE3(a3) );
                    }
                  }
                  else
                  {
                    ++v14;
                    *(_WORD *)v15 = pD3DRenderer->uTargetRMask & (BYTE3(a3) << (pD3DRenderer->uNumTargetGBits
                                                                + (_BYTE)pD3DRenderer->uNumTargetRBits
                                                                + (_BYTE)pD3DRenderer->uNumTargetBBits
                                                                - 8));
                    v15 += 2;
                  }
                }
                while ( v14 < v34 );
              }
              v17 = *((_DWORD *)v4 + 9) + 2 * v36 * *((_WORD *)v4 + 10);
              while ( v14 < 2 * v34 )
              {
                locked_fread((char *)&a3 + 3, 1u, 1u, File);
                if ( (BYTE3(a3) & 0xC0) == -64 )
                {
                  BYTE3(a3) &= 0x3Fu;
                  locked_fread(&v38, 1u, 1u, File);
                  v37 = 0;
                  v18 = v38;
                  if ( BYTE3(a3) )
                  {
                    do
                    {
                      *(_WORD *)v17 |= (_WORD)pD3DRenderer->uTargetGMask & (unsigned __int16)(v18 << (pD3DRenderer->uNumTargetGBits
                                                                                      + (_BYTE)pD3DRenderer->uNumTargetBBits
                                                                                      - 8));
                      ++v14;
                      v17 += 2;
                      ++v37;
                    }
                    while ( v37 < BYTE3(a3) );
                  }
                }
                else
                {
                  *(_WORD *)v17 |= (_WORD)pD3DRenderer->uTargetGMask & (unsigned __int16)(BYTE3(a3) << (pD3DRenderer->uNumTargetGBits
                                                                                        + (_BYTE)pD3DRenderer->uNumTargetBBits
                                                                                        - 8));
                  ++v14;
                  v17 += 2;
                }
              }
              v19 = *((_DWORD *)v4 + 9) + 2 * v36 * *((_WORD *)v4 + 10);
              while ( v14 < 3 * v34 )
              {
                locked_fread((char *)&a3 + 3, 1u, 1u, File);
                if ( (BYTE3(a3) & 0xC0) == -64 )
                {
                  BYTE3(a3) &= 0x3Fu;
                  locked_fread(&v38, 1u, 1u, File);
                  v37 = 0;
                  v20 = v38;
                  if ( BYTE3(a3) )
                  {
                    do
                    {
                      *(_WORD *)v19 |= v20 >> (8 - pD3DRenderer->uNumTargetBBits);
                      ++v14;
                      v19 += 2;
                      ++v37;
                    }
                    while ( v37 < BYTE3(a3) );
                  }
                }
                else
                {
                  *(_WORD *)v19 |= BYTE3(a3) >> (8 - pD3DRenderer->uNumTargetBBits);
                  ++v14;
                  v19 += 2;
                }
              }
              v21 = *((_WORD *)v4 + 11);
              ++v36;
            }
            while ( v36 < v21 );
          }
        }
        if ( a4 )
          fclose(File);
        result = 0;
      }
      else
      {
        result = v6;
      }
    }
    else
    {
      result = 3;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}


//----- (0040F82D) --------------------------------------------------------
void array_AD4674_FillZBuffer(int *pZBuffer, unsigned int uTextureID, unsigned int uZFill)
{
  array_40F89C_ActuallyFillZBuffer(pZBuffer, &LODFile_Icons_LOD.aLODHeaders[uTextureID], uZFill);
}



//----- (0040F89C) --------------------------------------------------------
void array_40F89C_ActuallyFillZBuffer(int *pZBuffer, cTexture *pTexture, int uZFill)
{
 unsigned int *pPixels;
 int x, y;


 pPixels = pTexture->pTruecolorPixels;

 for (y = 0; y < pTexture->uTextureHeight; ++y)
 {
  for (x = 0; x < pTexture->uTextureWidth; ++x)
  {
   if (!(*pPixels++ & 0xFF000000)) // on zbuffer place only non-transparent pixels
     *pZBuffer = uZFill;
   pZBuffer++;
  }

  pZBuffer += 640 - pTexture->uTextureWidth;
 }
}

//----- (0040F92A) --------------------------------------------------------
int __fastcall sub_40F92A(int a1, int a2, int a3)
{
  int v3; // esi@1
  int v4; // eax@3
  int result; // eax@5
  int v6; // edi@5
  int v7; // ecx@6
  int v9; // [sp+Ch] [bp-10h]@1
  int v10; // [sp+10h] [bp-Ch]@1
  unsigned int v11; // [sp+14h] [bp-8h]@5
  int v12; // [sp+18h] [bp-4h]@1

  v3 = a2;
  v9 = a1;
  v10 = *(_WORD *)(a2 + 24);
  v12 = *(_WORD *)(a2 + 26);
  if ( LODFile_Icons_LOD.lod_IB_dword_011BA4 && *(_DWORD *)(a2 + 40) )
    v4 = cTexture_UnzipPalette((cTexture *)a2);
  else
    v4 = *(_DWORD *)(a2 + 48);
  v11 = v4;
  v6 = v9;
  result = 0;
  do
  {
    v7 = v10;
    do
    {
      *(_DWORD *)v6 = a3;
      v6 += 4;
      --v7;
    }
    while ( v7 );
    v6 += 4 * (640 - v10);
  }
  while ( v12-- != 1 );
  if ( LODFile_Icons_LOD.lod_IB_dword_011BA4 )
  {
    if ( *(_DWORD *)(v3 + 40) )
      /*result = */operator_delete((void *)v11);
  }
  return result;
}



//----- (004649EF) --------------------------------------------------------
int __fastcall ReadWindowsRegistry(const char *pKeyName, int iDefaultValue)
{
  //int v3; // [sp+4h] [bp-24h]@1
  DWORD cbData; // [sp+8h] [bp-20h]@1
  LPCSTR lpValueName; // [sp+Ch] [bp-1Ch]@1
  DWORD dwDisposition; // [sp+10h] [bp-18h]@2
  BYTE Data[4]; // [sp+14h] [bp-14h]@5
  HKEY hKey; // [sp+18h] [bp-10h]@1
  HKEY phkResult; // [sp+1Ch] [bp-Ch]@1
  HKEY v10; // [sp+20h] [bp-8h]@1
  HKEY v11; // [sp+24h] [bp-4h]@1

  lpValueName = pKeyName;
  v11 = 0;
  v10 = 0;
  hKey = 0;
  phkResult = 0;
  cbData = 4;

  if (!RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE", 0, KEY_READ | KEY_WRITE, &hKey))
  {
    if ( !RegCreateKeyExA(hKey, "New World Computing", 0, "", 0, 983103u, 0, &phkResult, &dwDisposition) )
    {
      if ( !RegCreateKeyExA(phkResult, "Might and Magic VII", 0, "", 0, 0xF003Fu, 0, &v10, &dwDisposition) )
      {
        if ( !RegCreateKeyExA(v10, "1.0", 0, "", 0, 0xF003Fu, 0, &v11, &dwDisposition) )
        {
          if (RegQueryValueExA(v11, lpValueName, 0, 0, Data, &cbData) )
          {
            *(_DWORD *)&Data = iDefaultValue;
            RegSetValueExA(v11, lpValueName, 0, 4u, (unsigned char *)&Data, 4u);
          }
          RegCloseKey(v11);
        }
        RegCloseKey(v10);
      }
      RegCloseKey(phkResult);
    }
    RegCloseKey(hKey);
  }
  return *(_DWORD *)&Data;
}





//----- (00443DA1) --------------------------------------------------------
int Initialize_GlobalEVT()
{
 int result;
  int v1; // esi@1
 struct Event *pEvent;

 uGlobalEVT_Size = LoadFileToBuffer("global.evt", pGlobalEVT, 46080);

 uGlobalEVT_NumEvents = 0;
 memset(pGlobalEVT_Events, 128, 4400 * sizeof(struct Event));
 pEvent = pGlobalEVT_Events + uGlobalEVT_NumEvents; //result = 12 * uGlobalEVT_NumEvents + (pGlobalEVT_Events + 4);
 for (v1 = 0; v1 < uGlobalEVT_Size; v1 += pGlobalEVT[v1] + 1)
 {
      uGlobalEVT_NumEvents++;
      pEvent->dword_000000 /**(_DWORD *)(result - 4)*/ = pGlobalEVT[v1 + 1] + (pGlobalEVT[v1 + 2] << 8);
      pEvent->dword_000004 /**(_DWORD *)result*/ = pGlobalEVT[v1 + 3];
      pEvent->uEventOffsetInEVT /**(_DWORD *)(result + 4)*/ = v1;
      pEvent++;//result += 12;
 }
 return uGlobalEVT_Size;
}



//----- (00410B28) --------------------------------------------------------
char *__thiscall sub_410B28(void *_this)
{
  int v1; // edi@1
  int v2; // esi@1
  int v3; // eax@2
  int v4; // eax@4
  int v5; // ecx@4
  int v6; // eax@10
  char *result; // eax@12
  const char *v8; // ST44_4@12
  unsigned __int16 v9; // ax@12

  GUIWindow local_0C;
  //int v10; // [sp+Ch] [bp-68h]@4
  //int v11; // [sp+10h] [bp-64h]@4
  //int v12; // [sp+14h] [bp-60h]@4
  //int v13; // [sp+18h] [bp-5Ch]@4
  //int v14; // [sp+1Ch] [bp-58h]@4
  //int v15; // [sp+20h] [bp-54h]@4
  //int v16; // [sp+54h] [bp-20h]@4

  void *v17; // [sp+60h] [bp-14h]@1
  char v18; // [sp+64h] [bp-10h]@1
  int v19; // [sp+68h] [bp-Ch]@4
  int v20; // [sp+6Ch] [bp-8h]@4
  int v21; // [sp+70h] [bp-4h]@4

  v1 = (int)pPlayers[uActiveCharacter - 1];
  v17 = _this;
  v2 = 36 * (_DWORD)((char *)_this + 11 * *(_BYTE *)(v1 + 6734)) + 6078548;
  if ( *(_DWORD *)(class03_GetMousePos(pGame->pClass03, (POINT *)&v18) + 4) <= 250 )
    v3 = *(_DWORD *)(class03_GetMousePos(pGame->pClass03, (POINT *)&v18) + 4) + 30;
  else
    v3 = 30;
  local_0C.uFrameY = v3;
  local_0C.uFrameWidth = 328;
  local_0C.uFrameHeight = 68;
  local_0C.uFrameX = 90;
  local_0C.uFrameZ = 417;
  local_0C.uFrameW = v3 + 67;
  local_0C.ptr_000048 = 0;
  v19 = GetStringWidth(pFontSmallnum, (char *)pGlobalTXT_LocalizationStrings[431]);
  v21 = GetStringWidth(pFontSmallnum, (char *)pGlobalTXT_LocalizationStrings[433]);
  v20 = GetStringWidth(pFontSmallnum, (char *)pGlobalTXT_LocalizationStrings[432]);
  v4 = GetStringWidth(pFontSmallnum, (char *)pGlobalTXT_LocalizationStrings[96]);
  v5 = v19;
  if ( v21 > v19 )
    v5 = v21;
  if ( v20 > v5 )
    v5 = v20;
  if ( v4 > v5 )
    v5 = v4;
  wsprintfA((char *)pStringBuffer,
    "%s\n\n%s\t%03d:\t%03d%s\t000\n%s\t%03d:\t%03d%s\t000\n%s\t%03d:\t%03d%s\t000\n%s\t%03d:\t%03d%s",
    *(_DWORD *)(v2 + 8),
    pGlobalTXT_LocalizationStrings[431],
    v5 + 3,
    v5 + 10,
    *(_DWORD *)(v2 + 12),
    pGlobalTXT_LocalizationStrings[433],
    v5 + 3,
    v5 + 10,
    *(_DWORD *)(v2 + 16),
    pGlobalTXT_LocalizationStrings[432],
    v5 + 3,
    v5 + 10,
    *(_DWORD *)(v2 + 20),
    pGlobalTXT_LocalizationStrings[96],
    v5 + 3,
    v5 + 10,
    *(_DWORD *)(v2 + 24));
  v6 = CalculateTextHeght(pFontSmallnum, (char *)pStringBuffer, &local_0C, 0, 0);
  local_0C.uFrameHeight += v6;
  if (local_0C.uFrameHeight < 150)
    local_0C.uFrameHeight = 150;
  local_0C.uFrameWidth = 460;
  GUIWindow_sub_415551(&local_0C, 0);
  local_0C.uFrameWidth -= 12;
  local_0C.uFrameHeight -= 12;
  v8 = *(const char **)v2;
  local_0C.uFrameZ = local_0C.uFrameX + local_0C.uFrameWidth - 1;
  local_0C.uFrameW = local_0C.uFrameHeight + local_0C.uFrameY - 1;
  v9 = 0xFFFFFF9B;
  GUIWindow_sub_44D406(&local_0C, pFontArrus, 120, 12, v9, v8, 3);
  FontDrawText(&local_0C, pFontSmallnum, 120, 44, (char *)pStringBuffer, 0, 0, 0);
  local_0C.uFrameWidth = 108;
  local_0C.uFrameZ = local_0C.uFrameX + 107;
  GUIWindow_sub_44D406(&local_0C, pFontComic, 12, 75, 0, (char *)aSkillNames[12 + *(_BYTE *)(v1 + 6734)], 3);
  wsprintfA((char *)TmpBuf,
    "%s\n%d",
    pGlobalTXT_LocalizationStrings[522],
    (unsigned __int16)word_4E3C7C[((unsigned int)*(_BYTE *)(v1 + 2 * *(_BYTE *)(v1 + 6734) + 288) >> 6)
                                + 10 * (_DWORD)((char *)v17 + 11 * *(_BYTE *)(v1 + 6734))]);
  result = GUIWindow_sub_44D406(&local_0C, pFontComic, 12, local_0C.uFrameHeight - *(_BYTE *)(pFontComic + 5) - 16, 0, (char *)TmpBuf, 3);
  dword_507B00 = 0;
  return result;
}

//----- (00410D99) --------------------------------------------------------
signed int __fastcall sub_410D99(int a1)
{
  signed int v1; // ebp@1
  int v2; // edi@1
  char **v3; // ebx@2
  const char **v4; // esi@2

  v2 = 32 * a1;
  v1 = 1;
  if ( _strcmpi((char *)pMapStats->pMapInfos[1].pLocationFilename, LODFile_Games_LOD.pLODSubIndexNamedBuffer[v2 / 32].pFilename) )
  {
    v4 = (const char **)&pMapStats->pMapInfos[1].pLocationFilename;
    v3 = (char **)&pMapStats->pMapInfos[1].pLocationFilename;
    do
    {
      if ( !*v3 )
        break;
      v4 += 17;
      ++v1;
      v3 = (char **)v4;
    }
    while ( _strcmpi(*v4, LODFile_Games_LOD.pLODSubIndexNamedBuffer[v2 / 32].pFilename) );
  }
  return v1;
}

//----- (00410DEC) --------------------------------------------------------
int __cdecl sub_410DEC()
{
  char *v0; // eax@1
  int *v1; // esi@1
  __int16 v2; // ax@6
  int result; // eax@11
  int v4; // esi@13
  int v5; // ecx@13
  char v6; // zf@13
  unsigned int v7; // eax@14
  unsigned int v8; // esi@14
  int v9; // esi@14
  int v10; // eax@14
  __int64 v11; // edx@15
  int v12; // eax@19
  int v13; // ecx@22
  int v14; // eax@27
  unsigned __int8 v15; // sf@29
  unsigned __int8 v16; // of@29
  int v17; // [sp-10h] [bp-98h]@25
  unsigned __int16 v18; // [sp-Ch] [bp-94h]@25
  int v19; // [sp-8h] [bp-90h]@21
  const char *v20; // [sp-8h] [bp-90h]@25
  class cTexture* v21; // [sp-4h] [bp-8Ch]@4
  int v22; // [sp-4h] [bp-8Ch]@21
  int v23; // [sp-4h] [bp-8Ch]@25

  GUIWindow local_0C;
  //int v24; // [sp+Ch] [bp-7Ch]@1
  //int v25; // [sp+10h] [bp-78h]@1
  //int v26; // [sp+14h] [bp-74h]@1
  //int v27; // [sp+18h] [bp-70h]@1
  //int v28; // [sp+1Ch] [bp-6Ch]@1
  //int v29; // [sp+20h] [bp-68h]@1

  int v30; // [sp+64h] [bp-24h]@14
  __int64 v31; // [sp+68h] [bp-20h]@14
  int v32; // [sp+70h] [bp-18h]@13
  char *Str; // [sp+74h] [bp-14h]@14
  int v34; // [sp+78h] [bp-10h]@11
  int v35; // [sp+7Ch] [bp-Ch]@12
  int v36; // [sp+80h] [bp-8h]@12
  int v37; // [sp+84h] [bp-4h]@6

  v1 = (int *)&pParty_global->pPlayers[dword_506348];
  Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (cTexture *)dword_506358[(unsigned __int8)byte_50656C]);
  v0 = (char *)pGlobalTXT_LocalizationStrings[523];
  local_0C.uFrameX = 8;
  local_0C.uFrameY = 8;
  local_0C.uFrameWidth = 428;
  local_0C.uFrameHeight = 344;
  local_0C.uFrameZ = 435;
  local_0C.uFrameW = 351;
  if ( !byte_50656C )
    v0 = (char *)pGlobalTXT_LocalizationStrings[375];
  wsprintfA((char *)TmpBuf, "%s", v0);
  GUIWindow_sub_44D406(&local_0C, ptr_5C35F0, 0, 22, 0, (char *)TmpBuf, 3);
  if ( byte_50656C )
  {
   Render_DrawTransparentTexture(pD3DRenderer, *(_DWORD *)dword_506518, *(_DWORD *)(dword_506518 + 4), uTextureID_tab_an_6b__zoom_on);
    v21 = uTextureID_tab_an_6a__zoom_off;
  }
  else
  {
    Render_DrawTransparentTexture(pD3DRenderer, *(_DWORD *)dword_506518, *(_DWORD *)(dword_506518 + 4), uTextureID_tab_an_6a__zoom_off);
    v21 = uTextureID_tab_an_6b__zoom_on;
  }
  Render_DrawTransparentTexture(pD3DRenderer, *(_DWORD *)dword_506514, *(_DWORD *)(dword_506514 + 4), (cTexture *)v21);
  v2 = *((_WORD *)v1 + 146);
  v37 = 1;
  if ( HIBYTE(v2) & 1 || (_BYTE)v2 < 0 )
  {
    v37 = 5;
  }
  else
  {
    if ( v2 & 0x40 )
      v37 = 3;
  }
  result = 0;
  v34 = 0;
  if ( v37 > 0 )
  {
    v36 = (int)&unk_6A0118;
    v35 = (int)(v1 + 1707);
    while ( 1 )
    {
      local_0C.uFrameWidth = 92;
      v4 = 4 * result;
      local_0C.uFrameHeight = 68;
      v5 = *(&dword_4E249C + result);
      local_0C.uFrameY = *(&dword_4E24B0 + result);
      v32 = local_0C.uFrameY;
      local_0C.uFrameX = v5;
      local_0C.uFrameW = local_0C.uFrameY + 67;
      v6 = *(_DWORD *)(v36 + 36) == 0;
      local_0C.uFrameZ = v5 + 91;
      if ( !v6 )
        break;
      if ( !byte_50656C )
      {
        Render_DrawTransparentTexture(
          pD3DRenderer,
          *(int *)((char *)&dword_4E24C4 + v4),
          *(int *)((char *)&dword_4E24D8 + v4),
          uTextureID_lb_bordr__townport__sbquicknot);
        v23 = 3;
        v20 = (char *)pGlobalTXT_LocalizationStrings[19];
        v18 = 1;
        v14 = CalculateTextHeght(ptr_5C35E4, (char *)pGlobalTXT_LocalizationStrings[19], &local_0C, 0, 0);
        v17 = local_0C.uFrameHeight / 2 - v14 / 2;
        goto LABEL_28;
      }
LABEL_29:
      v36 += 40;
      v35 += 28;
      result = v34 + 1;
      compile_error;//v16 = __SETO__(v34 + 1, v37);
      v15 = v34++ + 1 - v37 < 0;
      if ( !(v15 ^ v16) )
        goto LABEL_30;
    }
    Render_DrawTransparentTexture(
      pD3DRenderer,
      *(int *)((char *)&dword_4E24C4 + v4),
      *(int *)((char *)&dword_4E24D8 + v4),
      uTextureID_lb_bordr__townport__sbquicknot);
    Render_DrawRGBTexture(pD3DRenderer, *(int *)((char *)&dword_4E249C + v4), *(int *)((char *)&dword_4E24B0 + v4), (cPCXTexture *)v36);
    v9 = v35;
    Str = (char *)pMapStats->pMapInfos[sub_410D99(*(_WORD *)(v35 + 26))].pLocationName;
    v10 = CalculateTextHeght(ptr_5C35E4, Str, &local_0C, 0, 0);
    local_0C.uFrameY += -6 - v10;
    GUIWindow_sub_44D406(&local_0C, ptr_5C35E4, 0, 0, 1u, Str, 3);
    v31 = *(_QWORD *)v9 - pParty_global->qword_00002C;
    v30 = (unsigned __int64)((signed __int64)((double)v31 * 0.234375) / 60 / 60) >> 32;
    v8 = (signed __int64)((double)v31 * 0.234375) / 60 / 60;
    v7 = v8 / 0x18;
    if ( (unsigned int)((signed __int64)((double)v31 * 0.234375) / 60 / 60) / 0x18 )
    {
      v13 = (int)pGlobalTXT_LocalizationStrings[57];
      if ( v7 > 1 )
      {
LABEL_24:
        v22 = v13;
        v19 = v7 + 1;
LABEL_25:
        wsprintfA((char *)TmpBuf, "%lu %s", v19, v22);
        v23 = 3;
        v20 = (char *)TmpBuf;
        v18 = 1;
        local_0C.uFrameY = v32 + local_0C.uFrameHeight + 4;
        v17 = 0;
LABEL_28:
        GUIWindow_sub_44D406(&local_0C, ptr_5C35E4, 0, v17, v18, v20, v23);
        goto LABEL_29;
      }
    }
    else
    {
      HIDWORD(v11) = v30;
      LODWORD(v11) = (signed __int64)((double)v31 * 0.234375) / 60 / 60;
      if ( v11 + 1 <= 23 )
      {
        if ( v30 < 0 || v30 <= 0 && v8 <= 1 )
          v12 = (int)pGlobalTXT_LocalizationStrings[109];
        else
          v12 = (int)pGlobalTXT_LocalizationStrings[110];
        v22 = v12;
        v19 = v8 + 1;
        goto LABEL_25;
      }
    }
    v13 = (int)pGlobalTXT_LocalizationStrings[56];
    goto LABEL_24;
  }
LABEL_30:
  if ( byte_506360 )
  {
    result = dword_50CBD0[0];
    if ( dword_50CBD0[0] < 40 )
    {
      dword_50CBD0[3 * dword_50CBD0[0] + 1] = 181;
      dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
      result = 3 * dword_50CBD0[0] + 3;
      dword_50CBD0[3 * dword_50CBD0[0] + 3] = 0;
      ++dword_50CBD0[0];
    }
  }
  return result;
}



//----- (00411300) --------------------------------------------------------
int __fastcall sub_411300(int a1)
{
  char v1; // al@1
  int v2; // ecx@1
  int v3; // esi@1
  int v4; // edi@5
  int result; // eax@6
  char *v6; // edi@7
  int v7; // eax@7
  char Str1[20]; // [sp+Ch] [bp-1Ch]@7
  int v11; // [sp+20h] [bp-8h]@5
  int v12; // [sp+24h] [bp-4h]@5

  byte_506550 = 0;
  v3 = a1;
  v2 = (int)pPlayers[uActiveCharacter - 1];
  v1 = *(_BYTE *)(v2 + 6735);
  if ( v1 && (unsigned __int8)v1 / 11 == v3 )
    dword_50654C = (unsigned __int8)v1 - 11 * v3;
  else
    dword_50654C = 0;
  v4 = 1;
  v12 = 1;
  v11 = 11 * v3 + v2 + 401;
  do
  {
    result = v11;
    if ( *(_BYTE *)(v11 + v4) )
    {
      v6 = &byte_4E2430[12 * v3] + v4;
      wsprintfA(Str1, "SB%sS%02d", (&off_4E1D18)[2 * v3], (unsigned __int8)*v6);
      v7 = LODFile_Icons_LOD.LODFile_LoadTexture( Str1, 2);
      dword_506408[v12] = 72 * v7 + 7145548;
      wsprintfA(Str1, "SB%sC%02d", (&off_4E1D18)[2 * v3], (unsigned __int8)*v6);
      result = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( Str1, 2)];
      dword_5063D8[v12] = result;
    }
    v4 = v12 + 1;
    //v9 = __SETO__(v12 + 1, 12);
    //v8 = v12++ - 11 < 0;
  }
  while (v12 < 12);
  return result;
}

//----- (0041140B) --------------------------------------------------------
int __cdecl sub_41140B()
{
  signed int v0; // esi@1
  int v1; // eax@3
  int v2; // esi@4
  int result; // eax@5

  v0 = 0;
  do
  {
   cTexture_Free(*(cTexture **)((char *)&dword_506404 + v0));
    cTexture_Free(*(cTexture **)((char *)&dword_506434 + v0));
    v0 -= 4;
  }
  while ( v0 >= -44 );
  LODFile_Icons_LOD.LODFile_sub_40F9C5();
  v1 = *(_DWORD *)(pGUIWindow_CurrentMenu + 76);
  if ( v1 )
  {
    do
    {
      v2 = *(_DWORD *)(v1 + 52);
      mem_mng.DeleteBuffer( (void *)v1);
      v1 = v2;
    }
    while ( v2 );
  }
  *(_DWORD *)(pGUIWindow_CurrentMenu + 76) = 0;
  *(_DWORD *)(pGUIWindow_CurrentMenu + 80) = 0;
  result = (int)pGUIWindow_CurrentMenu;
  *(_DWORD *)(pGUIWindow_CurrentMenu + 32) = 0;
  return result;
}

//----- (00411473) --------------------------------------------------------
int __cdecl sub_411473()
{
  int *v0; // edi@1
  int *v1; // esi@1
  int v2; // ecx@2
  int v3; // ecx@2

  cTexture_Free((cTexture *)dword_50649C[0]);
  cTexture_Free((cTexture *)dword_506448);
  cTexture_Free((cTexture *)dword_50643C);
  v1 = dword_506454;
  v0 = dword_5064A0;
  do
  {
    cTexture_Free((cTexture *)*v0);
    v2 = *(v1 - 1);
    *v0 = 0;
    cTexture_Free((cTexture *)v2);
    v3 = *v1;
    *(v1 - 1) = 0;
    cTexture_Free((cTexture *)v3);
    *v1 = 0;
    ++v0;
    v1 += 2;
  }
  while ( (signed int)v0 < (signed int)&dword_5064C4 );
  AudioPlayer_sub_4AA306(pAudioPlayer, 231, 0, 0, -1, 0, 0, 0, 0);
  return LODFile_Icons_LOD.LODFile_sub_4114F2();
}

//----- (00411597) --------------------------------------------------------
int __cdecl sub_411597()
{
  int result; // eax@1

  mem_mng.DeleteBuffer(ptr_5C35E4);
  ptr_5C35E4 = 0;
  mem_mng.DeleteBuffer(ptr_5C35F4);
  ptr_5C35F4 = 0;
  mem_mng.DeleteBuffer(ptr_5C35F0);
  ptr_5C35F0 = 0;
  mem_mng.DeleteBuffer(ptr_5C35E0);
  ptr_5C35E0 = 0;

  cTexture_Free((cTexture *)dword_506498_uTextureID_MapBrdr);
  AudioPlayer_sub_4AA306(pAudioPlayer, 231, 0, 0, -1, 0, 0, 0, 0);
  result = LODFile_Icons_LOD.LODFile_sub_4114F2();
  dword_506364 = 0;
  return result;
}

//----- (00411621) --------------------------------------------------------
int __thiscall sub_411621(void *_this)
{
  int v1; // ebp@1
  int v2; // edi@1
  int v3; // esi@1
  int v4; // eax@3
  int result; // eax@25
  int v6; // [sp+10h] [bp-8h]@1
  int v7; // [sp+14h] [bp-4h]@1

  v2 = (int)pPlayers[uActiveCharacter - 1];
  v3 = (int)_this;
  sub_411300(*(_BYTE *)(v2 + 6734));
  v1 = 0;
  v6 = 0;
  v7 = 11 * *(_BYTE *)(v2 + 6734) + v2 + 402;
  do
  {
    if ( *(_BYTE *)(v7 + v1) )
    {
      v4 = 8 * (12 * *(_BYTE *)(v2 + 6734) + (unsigned __int8)*(&byte_4E2431[12 * *(_BYTE *)(v2 + 6734)] + v1));
      GUIButtonCreate((GUIWindow *)v3,
        pOldViewport->uGameX + *(int *)((char *)&dword_4E20D0 + v4),
        pOldViewport->uGameY + *(int *)((char *)&dword_4E20D4 + v4),
        *(_WORD *)(dword_50640C[v1] + 24),
        *(_WORD *)(dword_50640C[v1] + 26),
        1,
        79,
        86,
        v1,
        0,
        (unsigned char *)"",
        0);
      ++v6;
    }
    ++v1;
  }
  while ( v1 < 11 );
  GUIButtonCreate((GUIWindow *)v3, 0, 0, 0, 0, 1, 0, 51, 0, 9, (unsigned char *)"", 0);
  if ( v6 )
    GUIWindow_sub_41D08F((GUIWindow *)v3, v6, 0, 0, 0);
  if ( *(_WORD *)(v2 + 288) )
    GUIButtonCreate((GUIWindow *)v3, 399, 10, 50, 36, 1, 0, 87, 0, 0, aSpellSchoolNames[0], 0);
  if ( *(_WORD *)(v2 + 290) )
    GUIButtonCreate((GUIWindow *)v3, 399, 46, 50, 36, 1, 0, 87, 1, 0, aSpellSchoolNames[1], 0);
  if ( *(_WORD *)(v2 + 292) )
    GUIButtonCreate((GUIWindow *)v3, 399, 83, 50, 36, 1, 0, 87, 2, 0, aSpellSchoolNames[2], 0);
  if ( *(_WORD *)(v2 + 294) )
    GUIButtonCreate((GUIWindow *)v3, 399, 121, 50, 36, 1, 0, 87, 3, 0, aSpellSchoolNames[3], 0);
  if ( *(_WORD *)(v2 + 296) )
    GUIButtonCreate((GUIWindow *)v3, 399, 158, 50, 36, 1, 0, 87, 4, 0, aSpellSchoolNames[4], 0);
  if ( *(_WORD *)(v2 + 298) )
    GUIButtonCreate((GUIWindow *)v3, 400, 196, 50, 36, 1, 0, 87, 5, 0, aSpellSchoolNames[5], 0);
  if ( *(_WORD *)(v2 + 300) )
    GUIButtonCreate((GUIWindow *)v3, 400, 234, 50, 36, 1, 0, 87, 6, 0, aSpellSchoolNames[6], 0);
  if ( *(_WORD *)(v2 + 302) )
    GUIButtonCreate((GUIWindow *)v3, 400, 271, 50, 36, 1, 0, 87, 7, 0, aSpellSchoolNames[7], 0);
  if ( *(_WORD *)(v2 + 304) )
    GUIButtonCreate((GUIWindow *)v3, 400, 307, 50, 36, 1, 0, 87, 8, 0, aSpellSchoolNames[8], 0);
  GUIButtonCreate((GUIWindow *)v3, 476, 450, *(_WORD *)(dword_506444 + 24), *(_WORD *)(dword_506444 + 26), 1, 78, 88, 0, 0, (unsigned char *)"", 0);
  dword_5064F8 = (int)GUIButtonCreate((GUIWindow *)v3, 476, 450, 48, 32, 1, 78, 88, 0, 0, (unsigned char *)"",  &LODFile_Icons_LOD.aLODHeaders[dword_506444],0);
  GUIButtonCreate((GUIWindow *)v3,
    561,
    450,
    *(_WORD *)(dword_506440 + 24),
    *(_WORD *)(dword_506440 + 26),
    1,
    0,
    113,
    0,
    0,
    pGlobalTXT_LocalizationStrings[79],
    0);
  result = (int)GUIButtonCreate((GUIWindow *)v3, 561, 450, 48, 32, 1, 0, 113, 0, 0, pGlobalTXT_LocalizationStrings[79],  &LODFile_Icons_LOD.aLODHeaders[dword_506440],0);
  dword_5064F4 = result;
  return result;
}

//----- (0041192C) --------------------------------------------------------
int __cdecl sub_41192C()
{
  signed int v0; // ebx@3
  signed int v1; // ebp@3
  int result; // eax@4

  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  ++LODFile_Icons_LOD.lod_IB_dword_011B9C;
  if ( !LODFile_Icons_LOD.lod_IB_dword_011B98 )
    LODFile_Icons_LOD.lod_IB_dword_011B98 = LODFile_Icons_LOD.uNumLoadedFiles;
  AudioPlayer_sub_4AA306(pAudioPlayer, 230, 0, 0, -1, 0, 0, 0, 0);
  dword_5064C4 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "book", 2)];
  dword_50649C[0] =(int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "pagemask", 2)];
  dword_506448 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "ib-m5-u", 2) ];
  dword_506440 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "ib-m5-d", 2)];
  dword_50643C = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "ib-m6-u", 2)];
  v1 = 1;
  v0 = (signed int)dword_506454;
  dword_506444 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "ib-m6-d", 2)];
  do
  {
    dword_50649C[v1] = (int)&LODFile_Icons_LOD.aLODHeaders[ LODFile_Icons_LOD.LODFile_LoadTexture( (&dword_4E24E8)[4 * v1], 2)];
    wsprintfA((char *)TmpBuf, "tab%da", v1);
    *(_DWORD *)(v0 - 4) = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( (char *)TmpBuf, 2)];
    wsprintfA((char *)TmpBuf, "tab%db", v1++);
    result =(int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( (char *)TmpBuf, 2)];
    *(_DWORD *)v0 = result;
    v0 += 8;
  }
  while ( v0 <= (signed int)&unk_506494 );
  return result;
}

//----- (00411AAA) --------------------------------------------------------
void sub_411AAA()
{
  int result; // eax@3

  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  ++LODFile_Icons_LOD.lod_IB_dword_011B9C;
  if ( !LODFile_Icons_LOD.lod_IB_dword_011B98 )
    LODFile_Icons_LOD.lod_IB_dword_011B98 = LODFile_Icons_LOD.uNumLoadedFiles;
  AudioPlayer_sub_4AA306(pAudioPlayer, 230, 0, 0, -1, 0, 0, 0, 0);
#ifndef OLD_CODE 
  dword_506498_uTextureID_MapBrdr = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"mapbordr");
#endif
#ifdef OLD_CODE 
  dword_506498_uTextureID_MapBrdr = LODFile_Icons_LOD.LODFile_LoadTexture("mapbordr",2);
#endif
  ptr_5C35F4 = LoadFont("book.fnt", "FONTPAL");
  ptr_5C35F0 = LoadFont("book2.fnt", "FONTPAL");
  ptr_5C35E0 = LoadFont("autonote.fnt", "FONTPAL");
  ptr_5C35E4 = LoadFont("spell.fnt", "FONTPAL");
}

//----- (00411B59) --------------------------------------------------------
int __fastcall sub_411B59(int a1, int a2)
{
  FILE *v2; // ebx@1
  int v3; // edi@1
  int v4; // esi@1
  FILE *v5; // eax@2
  int result; // eax@3
  char Str1[64]; // [sp+Ch] [bp-44h]@1
  int v8; // [sp+4Ch] [bp-4h]@1

  v4 = a1;
  v8 = a2;
  v3 = a1 + 1;
  wsprintfA(Str1, "data\\lloyd%d%d.pcx", a2, a1 + 1);
  v2 = fopen(Str1, "rb");
  if ( v2 )
  {
    sub_40EAD8((void *)(40 * v4 + 6947096), v2, 0, 1);
    result = fclose(v2);
  }
  else
  {
    wsprintfA(Str1, "lloyd%d%d.pcx", v8, v3);
    v5 = LODFile_New_LOD.Find_Container( Str1, 1);
    if ( v5 )
    {
      result = sub_40EAD8((void *)(40 * v4 + 6947096), v5, 0, 0);
    }
    else
    {
      result = 5 * v4;
      dword_6A013C[10 * v4] = 0;
    }
  }
  return result;
}

//----- (00411BFC) --------------------------------------------------------
int __thiscall GUIWindow_sub_411BFC(GUIWindow *_this)
{
  int v1; // ebp@1
  int result; // eax@7
  signed int v3; // ecx@8
  __int64 *v4; // ebp@9
  char *v5; // ecx@10
  __int64 v6; // qax@12
  int v7; // esi@12
  const char *v8; // eax@12
  int v9; // eax@12
  signed int v10; // esi@19
  int v11; // eax@24
  int j; // esi@28
  char *v13; // ebp@29
  int v14; // eax@31
  int v15; // esi@35
  __int16 v16; // ax@38
  int *v17; // esi@38
  int i; // edi@43
  int v19; // edi@45
  int v20; // esi@45
  int v21; // eax@46
  int v22; // [sp+10h] [bp-5Ch]@9
  signed int v23; // [sp+10h] [bp-5Ch]@38
  int v24; // [sp+14h] [bp-58h]@9
  char *v25; // [sp+14h] [bp-58h]@21
  int v26; // [sp+18h] [bp-54h]@8
  int v27; // [sp+1Ch] [bp-50h]@8
  int v28; // [sp+20h] [bp-4Ch]@8
  int v29; // [sp+24h] [bp-48h]@8
  int v30; // [sp+28h] [bp-44h]@8
  int v31; // [sp+2Ch] [bp-40h]@8

  v1 = (int)_this;
  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  sub_411AAA();
  GUIButtonCreate(_this, 475, 445, 158, 34, 1, 0, 113, 0, 0, pGlobalTXT_LocalizationStrings[79], 0);
  dword_4E28F8 = 3;
  dword_506524 = 0;
  dword_506528 = 0;
  dword_50651C = 0;
  dword_506520 = 0;
  if ( *(_DWORD *)(v1 + 28) == 177 )
  {
    byte_506360 = 0;
    uTextureID_lb_bordr__townport__sbquicknot =&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "lb_bordr", 2)];
    dword_506358[0] = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "sbmap", 2)];
    dword_50635C = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "sbmap", 2)];
 #ifndef OLD_CODE
    uTextureID_tab_an_6b__zoom_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"tab-an-6b")];
    uTextureID_tab_an_6a__zoom_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"tab-an-6a")];
 #endif
#ifdef OLD_CODE 
	 uTextureID_tab_an_6b__zoom_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("tab-an-6b",2)];
    uTextureID_tab_an_6a__zoom_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("tab-an-6a",2)];
 #endif
    dword_506518 = GUIButtonCreate((GUIWindow *)v1, 415, 13, 39, 36, 1, 0, 178, 0, 0, pGlobalTXT_LocalizationStrings[375], 0);
    dword_506514 = GUIButtonCreate((GUIWindow *)v1, 415, 48, 39, 36, 1, 0, 178, 1, 0, pGlobalTXT_LocalizationStrings[523], 0);
    v17 = (int *)&pParty_global->pPlayers[1743 * dword_506348];
    v23 = 1;
    v16 = *((_WORD *)v17 + 146);
    if ( HIBYTE(v16) & 1 || (_BYTE)v16 < 0 )
    {
      v23 = 5;
    }
    else
    {
      if ( v16 & 0x40 )
        v23 = 3;
    }
    for ( i = 0; i < v23; ++i )
      GUIButtonCreate((GUIWindow *)v1, *(&dword_4E249C + i), *(&dword_4E24B0 + i), 92, 68, 1, 180, 179, i, 0, (unsigned char *)"", 0);
    v19 = 0;
    v20 = (int)(v17 + 1707);
    do
    {
      v21 = *(_DWORD *)(v20 + 4);
      if ( v21 > HIDWORD(pParty_global->qword_00002C) || v21 >= HIDWORD(pParty_global->qword_00002C) && *(_DWORD *)v20 >= (_DWORD)pParty_global->qword_00002C )
        result = sub_411B59(v19, dword_506348 + 1);
      else
        result = (int)memset((void *)v20, 0, 0x1Cu);
      ++v19;
      v20 += 28;
    }
    while ( v19 < 5 );
  }
  else
  {
    if ( *(_DWORD *)(v1 + 28) == 195 )
    {
      uTextureID_lb_bordr__townport__sbquicknot = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "townport", 2) ];
      dword_5063A8[0] = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tpharmndy", 2)];
      dword_5063AC = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tpelf", 2)];
      dword_5063B0 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tpwarlock", 2)];
      dword_5063B4 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tpisland", 2) ];
      dword_5063B8 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tpheaven", 2)];
      v15 = 0;
      dword_5063BC = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tphell", 2)];
      do
      {
        result = (int)GUIButtonCreate((GUIWindow *)v1,
                   word_4E1D3C[v15],
                   word_4E1D48[v15],
                   word_4E1D54[v15],
                   word_4E1D60[v15],
                   1,
                   182,
                   183,
                   v15,
                   0,
                   (unsigned char *)"",
                   0);
        ++v15;
      }
      while ( v15 < 6 );
    }
    else
    {
      if ( *(_DWORD *)(v1 + 28) == 200 )
      {
 #ifndef OLD_CODE 
        uTextureID_lb_bordr__townport__sbquicknot = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"sbquiknot")];
        uTextureID_divbar = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"divbar")];
        uTextureID_tab_an_6b__zoom_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"tab-an-6b")];
        uTextureID_tab_an_7b__zoot_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"tab-an-7b")];
        uTextureID_tab_an_6a__zoom_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"tab-an-6a")];
        uTextureID_tab_an_7a__zoot_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"tab-an-7a")];
		#endif

#ifdef OLD_CODE 
		 uTextureID_lb_bordr__townport__sbquicknot = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("sbquiknot",2)];
        uTextureID_divbar = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("divbar",2)];
        uTextureID_tab_an_6b__zoom_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("tab-an-6b",2)];
        uTextureID_tab_an_7b__zoot_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("tab-an-7b",2)];
        uTextureID_tab_an_6a__zoom_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("tab-an-6a",2)];
        uTextureID_tab_an_7a__zoot_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("tab-an-7a",2)];
#endif
        dword_506518 = GUIButtonCreate((GUIWindow *)v1,
                         pOldViewport->uGameX + 398,
                         pOldViewport->uGameY + 1,
                         uTextureID_tab_an_6b__zoom_on->uTextureWidth,
                         uTextureID_tab_an_6b__zoom_on->uTextureHeight,
                         1,
                         0,
                         71,
                         11,
                         0,
                         pGlobalTXT_LocalizationStrings[192],
                          uTextureID_tab_an_6b__zoom_on,0);
        dword_506514 = GUIButtonCreate((GUIWindow *)v1,
                         pOldViewport->uGameX + 398,
                         pOldViewport->uGameY + 38,
                         uTextureID_tab_an_7b__zoot_on->uTextureWidth,
                         uTextureID_tab_an_7b__zoot_on->uTextureHeight,
                         1,
                         0,
                         71,
                         10,
                         0,
                         pGlobalTXT_LocalizationStrings[193],
                          uTextureID_tab_an_7b__zoot_on,0);
        dword_506520 = 0;
        memset(&stru_5C3610, 0, sizeof(struct unnamed_5C3610));
        for ( j = dword_506528; j < 512; ++j )
        {
          v13 = (&dword_722F10)[4 * j];
          if ( (unsigned __int16)sub_449B57((int)pParty_global->unk_000764 + 1, j) )
          {
            if ( v13 )
            {
              v14 = dword_506520++;
              stru_5C3610.array_000000[v14] = j;
            }
          }
        }
      }
      else
      {
        if ( *(_DWORD *)(v1 + 28) == 201 )
        {//autonotes

#ifndef OLD_CODE 
          uTextureID_sbAutonotes = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"sbautnot")];
          uTextureID_divbar = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"divbar")];
          uTextureID_tab_an_6b__zoom_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"tab-an-6b")];
          uTextureID_tab_an_7b__zoot_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"tab-an-7b")];
          uTextureID_tab_an_6a__zoom_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"tab-an-6a")];
          uTextureID_tab_an_7a__zoot_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"tab-an-7a")];
  #endif
 #ifdef OLD_CODE
		  uTextureID_sbAutonotes = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("sbautnot",2)];
          uTextureID_divbar = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("divbar",2)];
          uTextureID_tab_an_6b__zoom_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("tab-an-6b",2)];
          uTextureID_tab_an_7b__zoot_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("tab-an-7b",2)];
          uTextureID_tab_an_6a__zoom_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("tab-an-6a",2)];
          uTextureID_tab_an_7a__zoot_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("tab-an-7a",2)];
  #endif
          dword_506394 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tab-an-1b", 2)];
          dword_506390 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tab-an-1a", 2)];
          dword_50638C = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tab-an-2b", 2)];
          dword_506388 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tab-an-2a", 2)];
          dword_506384 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tab-an-3b", 2)];
          dword_506380 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tab-an-3a", 2)];
          dword_50637C = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tab-an-5b", 2)];
          dword_506378 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tab-an-5a", 2)];
          dword_506374 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tab-an-4b", 2)];
          dword_506370 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tab-an-4a", 2)];
          dword_50636C = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tab-an-8b", 2)];
          dword_506368 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tab-an-8a", 2)];
          dword_506518 = GUIButtonCreate((GUIWindow *)v1,
                           pOldViewport->uGameX + 398,
                           pOldViewport->uGameY + 1,
                           50,
                           34,
                           1,
                           0,
                           71,
                           11,
                           0,
                           pGlobalTXT_LocalizationStrings[193],
                            uTextureID_tab_an_6b__zoom_on,0);
          dword_506514 = GUIButtonCreate((GUIWindow *)v1,
                           pOldViewport->uGameX + 398,
                           pOldViewport->uGameY + 38,
                           50,
                           34,
                           1,
                           0,
                           71,
                           10,
                           0,
                           pGlobalTXT_LocalizationStrings[192],
                            uTextureID_tab_an_7b__zoot_on,0);
          dword_506510 = GUIButtonCreate((GUIWindow *)v1,
                           pOldViewport->uGameX + 398,
                           pOldViewport->uGameY + 113,
                           50,
                           34,
                           1,
                           0,
                           71,
                           2,
                           0,
                           pGlobalTXT_LocalizationStrings[85],
                            dword_506394,0);
          dword_50650C = GUIButtonCreate((GUIWindow *)v1,
                           pOldViewport->uGameX + 399,
                           pOldViewport->uGameY + 150,
                           50,
                           34,
                           1,
                           0,
                           71,
                           3,
                           0,
                           pGlobalTXT_LocalizationStrings[137],
                            dword_50638C,0);
          dword_506508 = GUIButtonCreate((GUIWindow *)v1,
                           pOldViewport->uGameX + 397,
                           pOldViewport->uGameY + 188,
                           50,
                           34,
                           1,
                           0,
                           71,
                           4,
                           0,
                           pGlobalTXT_LocalizationStrings[8],
                            dword_506384,0);
          dword_506504 = GUIButtonCreate((GUIWindow *)v1,
                           pOldViewport->uGameX + 397,
                           pOldViewport->uGameY + 226,
                           50,
                           34,
                           1,
                           0,
                           71,
                           5,
                           0,
                           pGlobalTXT_LocalizationStrings[141],
                            dword_50637C,0);
          dword_506500 = GUIButtonCreate((GUIWindow *)v1,
                           pOldViewport->uGameX + 397,
                           pOldViewport->uGameY + 264,
                           50,
                           34,
                           1,
                           0,
                           71,
                           6,
                           0,
                           pGlobalTXT_LocalizationStrings[123],
                           dword_506374,0);
          v10 = dword_506528;
          dword_5064FC = GUIButtonCreate((GUIWindow *)v1,
                           pOldViewport->uGameX + 397,
                           pOldViewport->uGameY + 302,
                           50,
                           34,
                           1,
                           0,
                           71,
                           7,
                           0,
                           pGlobalTXT_LocalizationStrings[662],
                           dword_50636C,0);
          dword_506520 = 0;
          while ( v10 < 196 )
          {
            if ( dword_506568 == dword_72371C[2 * v10] )
            {
              v25 = (&dword_723718)[8 * (signed __int16)v10];
              if ( (_WORD)v10 )
              {
                if ( (unsigned __int16)sub_449B57((int)pParty_global->unk_000764 + 0x9A, v10) )
                {
                  if ( v25 )
                  {
                    v11 = dword_506520++;
                    stru_5C3610.array_000000[v11] = (signed __int16)v10;
                  }
                }
              }
            }
            ++v10;
          }
        }
        else
        {
          if ( *(_DWORD *)(v1 + 28) == 202 )
          {
            dword_506364 = 1;
            dword_5064D0 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "sbmap", 2)];
    #ifndef OLD_CODE
            uTextureID_tab_an_6b__zoom_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"zoom-on")];
            uTextureID_tab_an_7b__zoot_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"zoot-on")];
            uTextureID_tab_an_6a__zoom_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"zoom-off")];
            uTextureID_tab_an_7a__zoot_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"zoot-off")];
     #endif
 #ifdef OLD_CODE
		   uTextureID_tab_an_6b__zoom_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("zoom-on",2)];
            uTextureID_tab_an_7b__zoot_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("zoot-on",2)];
            uTextureID_tab_an_6a__zoom_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("zoom-off",2)];
            uTextureID_tab_an_7a__zoot_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("zoot-off",2)];
	   #endif
            dword_506394 = &LODFile_Icons_LOD.aLODHeaders[ LODFile_Icons_LOD.LODFile_LoadTexture( "tabNon", 2)];
            dword_506390 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tabNoff", 2)];
            dword_50638C = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tabSon", 2)];
            dword_506388 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tabSoff", 2)];
            dword_506384 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tabEon", 2)];
            dword_506380 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tabEoff", 2)];
            dword_50637C = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "tabWon", 2)];
            dword_506378 = &LODFile_Icons_LOD.aLODHeaders[ LODFile_Icons_LOD.LODFile_LoadTexture( "tabWoff", 2)];
            dword_506518 = GUIButtonCreate((GUIWindow *)v1,
                             pOldViewport->uGameX + 398,
                             pOldViewport->uGameY + 1,
                             50,
                             34,
                             1,
                             0,
                             71,
                             0,
                             0,
                             pGlobalTXT_LocalizationStrings[251],
                              uTextureID_tab_an_6b__zoom_on,0);
            dword_506514 = GUIButtonCreate((GUIWindow *)v1,
                             pOldViewport->uGameX + 398,
                             pOldViewport->uGameY + 38,
                             50,
                             34,
                             1,
                             0,
                             71,
                             1,
                             0,
                             pGlobalTXT_LocalizationStrings[252],
                              uTextureID_tab_an_7b__zoot_on,0);
            dword_506510 = GUIButtonCreate((GUIWindow *)v1,
                             pOldViewport->uGameX + 397,
                             pOldViewport->uGameY + 113,
                             50,
                             34,
                             1,
                             0,
                             71,
                             2,
                             0,
                             pGlobalTXT_LocalizationStrings[192],
                             0);
            dword_50650C = GUIButtonCreate((GUIWindow *)v1,
                             pOldViewport->uGameX + 397,
                             pOldViewport->uGameY + 150,
                             50,
                             34,
                             1,
                             0,
                             71,
                             3,
                             0,
                             pGlobalTXT_LocalizationStrings[193],
                             0);
            dword_506508 = GUIButtonCreate((GUIWindow *)v1,
                             pOldViewport->uGameX + 397,
                             pOldViewport->uGameY + 188,
                             50,
                             34,
                             1,
                             0,
                             71,
                             4,
                             0,
                             pGlobalTXT_LocalizationStrings[573],
                             0);
            dword_506504 = GUIButtonCreate((GUIWindow *)v1,
                       pOldViewport->uGameX + 397,
                       pOldViewport->uGameY + 226,
                       50,
                       34,
                       1,
                       0,
                       71,
                       5,
                       0,
                       pGlobalTXT_LocalizationStrings[572],
                       0);
            return (int)dword_506504;
          }
          if ( *(_DWORD *)(v1 + 28) == 203 )
          {
            dword_5064D4 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "sbdate-time", 2)];
            dword_5064E0 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "moon_new", 2)];
            dword_5064E4 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "moon_4", 2)];
            dword_5064E8 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "moon_2", 2)];
            dword_5064EC = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "moon_2", 2)];
            dword_5064F0 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "moon_ful", 2)];
            
            return 0;
          }
          result = *(_DWORD *)(v1 + 28) - 224;
          if ( *(_DWORD *)(v1 + 28) != 224 )
            return result;
          dword_5064CC = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "sbplayrnot", 2)];
  #ifndef OLD_CODE
          uTextureID_tab_an_6b__zoom_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"tab-an-6b")];
          uTextureID_tab_an_7b__zoot_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"tab-an-7b")];
          uTextureID_tab_an_6a__zoom_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"tab-an-6a")];
          uTextureID_tab_an_7a__zoot_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"tab-an-7a")];
     #endif
 #ifdef OLD_CODE
		 uTextureID_tab_an_6b__zoom_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("tab-an-6b",2)];
          uTextureID_tab_an_7b__zoot_on = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("tab-an-7b",2)];
          uTextureID_tab_an_6a__zoom_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("tab-an-6a",2)];
          uTextureID_tab_an_7a__zoot_off = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("tab-an-7a",2)];
     #endif
          dword_506518 = GUIButtonCreate((GUIWindow *)v1,
                           pOldViewport->uGameX + 398,
                           pOldViewport->uGameY + 1,
                           uTextureID_tab_an_6b__zoom_on->uTextureWidth,
                           uTextureID_tab_an_6b__zoom_on->uTextureHeight,
                           1,
                           0,
                           71,
                           11,
                           0,
                           pGlobalTXT_LocalizationStrings[192],
                           uTextureID_tab_an_6b__zoom_on,0);
          dword_506514 = GUIButtonCreate((GUIWindow *)v1,
                           pOldViewport->uGameX + 398,
                           pOldViewport->uGameY + 38,
                           uTextureID_tab_an_7b__zoot_on->uTextureWidth,
                           uTextureID_tab_an_7b__zoot_on->uTextureHeight,
                           1,
                           0,
                           71,
                           10,
                           0,
                           pGlobalTXT_LocalizationStrings[193],
                            uTextureID_tab_an_7b__zoot_on,0);
          dword_506520 = 0;
          v26 = 48;
          v27 = 70;
          v28 = 360;
          v29 = 264;
          v3 = *(_BYTE *)((char *)ptr_5C35E0 + 5) - 3;
          v30 = 407;
          v29 = v3 * 264 / v3;
          v31 = v29 + 69;
          memset(&stru_5C3610, 0, sizeof(struct unnamed_5C3610));
          memset(byte_5C6D50, 0, 0x64u);
          if ( dword_506528 < 29 )
          {
            v4 = (__int64 *)(8 * dword_506528 + 11326692);
            v24 = dword_506528 + 1;
            v22 = 12 * dword_506528 + 6065004;
            do
            {
              v5 = *(char **)v22;
              if ( *v4 )
              {
                if ( v5 )
                {
                  v8 = sub_495461_DrawAn_AreYouSureWishTo_Join_Dismiss_ThisNPC_Dialogue(v5, uActiveCharacter - 1, 0, 0, 0, v4);
                  v9 = CalculateTextHeght(ptr_5C35E0, v8, (GUIWindow *)&v26, 1, 0);
                  v6 = (v9 - 3) / v29;
                  v7 = v6 + 1;
                  if ( (_DWORD)v6 + 1 > 0 )
                  {
                    memset_dw(&stru_5C3610.array_000000[dword_506520], v24, 4 * v7);
                    do
                    {
                      LODWORD(v6) = dword_506520++;
                      byte_5C6D50[(_DWORD)v6] = BYTE4(v6);
                      v6 += 4294967296i64;
                    }
                    while ( HIDWORD(v6) < v7 );
                  }
                }
              }
              v22 += 12;
              ++v4;
              ++v24;
            }
            while ( v22 < (signed int)&unk_5C8CC8 );
          }
        }
      }
      result = dword_506520;
      dword_506520 = 0;
      dword_506524 = result;
    }
  }
  return result;
}

//----- (00412AF9) --------------------------------------------------------
void __cdecl sub_412AF9()
{
  int v0; // ecx@1

  v0 = 0;
  compile_error;
  //some ill-defined player indexing
  //looks like pointing to the first element in Players[uActiveCharacter] or uActiveCharacter +/- 1
  //if ( uActiveCharacter )
  //  v0 = (unsigned __int8)byte_ACD896[6972 * uActiveCharacter];
  Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (cTexture *)dword_5064A0[v0]);
  Render_DrawIndexedTexture(pD3DRenderer, 476, 450, (cTexture *)dword_50643C);
  Render_DrawIndexedTexture(pD3DRenderer, 561, 450, (cTexture *)dword_506448);
}

//----- (00412B58) --------------------------------------------------------
void __cdecl sub_412B58()
{
  int v0; // ebx@1
  int v1; // ebp@1
  int v2; // edi@1
  int v3; // esi@1
  signed int v4; // eax@1
  int v5; // eax@3
  int v6; // edx@5
  int v7; // eax@8
  int v8; // eax@11
  int v9; // eax@13
  int v10; // esi@13
  int v11; // edx@14
  int v12; // eax@15
  signed int v13; // ecx@18
  int v14; // edi@18
  int v15; // esi@18
  int v16; // eax@21
  int v17; // [sp-Ch] [bp-2Ch]@8
  int v18; // [sp-Ch] [bp-2Ch]@15
  int v19; // [sp-8h] [bp-28h]@8
  int v20; // [sp-8h] [bp-28h]@15
  int v21; // [sp-4h] [bp-24h]@15
  signed int v22; // [sp-4h] [bp-24h]@22
  int v23; // [sp+10h] [bp-10h]@5
  int v24; // [sp+18h] [bp-8h]@13

  sub_412AF9();
  v0 = (int)pPlayers[uActiveCharacter - 1];
  v1 = 11 * *(_BYTE *)(v0 + 6734);
  v4 = LODFile_Icons_LOD.LODFile_sub_40F9F0( "Pending");
  v2 = v4 != -1 ? 72 * v4 + 7145548 : 0;
  Render_ClearZBuffer(pD3DRenderer, 0, 479);
  v3 = 1;

  compile_error;//if ( __SETO__(v1, v1 + 11) ^ 1 )
  if (!v1)
  {
    do
    {
      if ( *(_BYTE *)(v1 + 401 + v0 + v3) )
      {
        v5 = dword_506408[v3];
        if ( v5 != v2 )
        {
          if ( dword_50654C == v3 )
          {
            v6 = dword_5063D8[v3];
            v23 = dword_5063D8[v3];
          }
          else
          {
            v23 = dword_506408[v3];
            v6 = v5;
          }
          if ( *(_DWORD *)(v6 + 48) )
          {
            v7 = 8 * (12 * *(_BYTE *)(v0 + 6734) + (unsigned __int8)*(&byte_4E2430[12 * *(_BYTE *)(v0 + 6734)] + v3));
            v19 = pOldViewport->uGameY + *(int *)((char *)&dword_4E20D4 + v7);
            v17 = pOldViewport->uGameX + *(int *)((char *)&dword_4E20D0 + v7);
            if ( *(_BYTE *)(v6 + 45) & 2 )
              Render_DrawTransparentTexture(pD3DRenderer, v17, v19, (cTexture *)v6);
            else
              Render_DrawIndexedTexture(pD3DRenderer, v17, v19, (cTexture *)v6);
            v8 = 8 * (12 * *(_BYTE *)(v0 + 6734) + (unsigned __int8)*(&byte_4E2430[12 * *(_BYTE *)(v0 + 6734)] + v3));
            Render_sub_4A612A(
              (int)pD3DRenderer,
              *(int *)((char *)&dword_4E20D0 + v8),
              *(int *)((char *)&dword_4E20D4 + v8),
              v23,
              v3);
          }
        }
      }
      ++v3;
    }
    while ( v1 - 1 + v3 < v1 + 11 );
  }
  v10 = (int)class03_GetMousePos(pGame->pClass03, (POINT *)&v24);
  v9 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer
                 + 4 * (*(_DWORD *)v10 + dword_5059A8[*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (POINT *)&v23) + 4)])) & 0xFFFF;
  if ( v9 )
  {
    v11 = dword_5063D8[v9];
    if ( *(_DWORD *)(v11 + 48) )
    {
      v21 = dword_5063D8[v9];
      v12 = 8 * (12 * *(_BYTE *)(v0 + 6734) + (unsigned __int8)*(&byte_4E2430[12 * *(_BYTE *)(v0 + 6734)] + v9));
      v20 = pOldViewport->uGameY + *(int *)((char *)&dword_4E20D4 + v12);
      v18 = pOldViewport->uGameX + *(int *)((char *)&dword_4E20D0 + v12);
      if ( *(_BYTE *)(v11 + 45) & 2 )
        Render_DrawTransparentTexture(pD3DRenderer, v18, v20, (cTexture *)v21);
      else
        Render_DrawIndexedTexture(pD3DRenderer, v18, v20, (cTexture *)v21);
    }
  }
  v13 = 0;
  v24 = v0 + 288;
  v15 = v0 + 288;
  v14 = v0 + 288;
  v23 = 0;
  do
  {
    if ( *(_WORD *)v24 )
    {
      if ( *(_BYTE *)(v0 + 6734) == v13 )
      {
        v16 = dword_506454[2 * v13];
        switch ( v13 )
        {
          case 0:
            v15 = 406;
            v22 = 9;
            goto LABEL_27;
          case 1:
            v15 = 406;
            goto LABEL_38;
          case 2:
            v15 = 406;
            v22 = 84;
            goto LABEL_27;
          case 3:
            v15 = 406;
            goto LABEL_26;
          case 4:
            v15 = 407;
            goto LABEL_29;
          case 5:
            v14 = 196;
            goto LABEL_34;
          case 6:
            v14 = 234;
            goto LABEL_34;
          case 7:
            v14 = 272;
            goto LABEL_34;
          case 8:
            v14 = 309;
LABEL_34:
            v15 = 405;
            break;
          default:
            break;
        }
      }
      else
      {
        v16 = dword_506450[2 * v13];
        switch ( v13 )
        {
          case 0:
            v15 = 415;
            v22 = 10;
            goto LABEL_27;
          case 1:
            v15 = 415;
LABEL_38:
            v22 = 46;
            goto LABEL_27;
          case 2:
            v15 = 415;
            v22 = 83;
            goto LABEL_27;
          case 3:
            v15 = 415;
LABEL_26:
            v22 = 121;
LABEL_27:
            v14 = v22;
            break;
          case 4:
            v15 = 415;
LABEL_29:
            v14 = 158;
            break;
          case 5:
            v14 = 196;
            goto LABEL_46;
          case 6:
            v14 = 234;
            goto LABEL_46;
          case 7:
            v14 = 271;
            goto LABEL_46;
          case 8:
            v14 = 307;
LABEL_46:
            v15 = 416;
            break;
          default:
            break;
        }
      }
      Render_DrawTransparentTexture(pD3DRenderer, v15, v14, (cTexture *)v16);
      v13 = v23;
    }
    v24 += 2;
    ++v13;
    v23 = v13;
  }
  while ( v13 < 9 );
}

//----- (00412E85) --------------------------------------------------------
void __cdecl sub_412E85()
{
  int v0; // eax@3
  int v1; // eax@7
  const char *v2; // eax@10
  int v3; // eax@10
  signed int v4; // ecx@12
  int v5; // ecx@14
  const char *v6; // eax@21
  int v7; // eax@21
  LPCSTR v8; // esi@21
  int v9; // eax@22
  int v11; // [sp-8h] [bp-64h]@3
  int v12; // [sp-8h] [bp-64h]@7
  class cTexture* v13; // [sp-4h] [bp-60h]@3
  class cTexture* v14; // [sp-4h] [bp-60h]@7

  GUIWindow local_08;
  //int v15; // [sp+8h] [bp-54h]@10
  //int v16; // [sp+Ch] [bp-50h]@10
  //int v17; // [sp+10h] [bp-4Ch]@10
  //int v18; // [sp+14h] [bp-48h]@10
  //int v19; // [sp+18h] [bp-44h]@10
  //int v20; // [sp+1Ch] [bp-40h]@10

  Render_DrawIndexedTexture(pD3DRenderer, pOldViewport->uGameX, pOldViewport->uGameY, (cTexture *)dword_5064CC);
  if ( dword_506548 || !dword_506528 )
  {
    v13 = uTextureID_tab_an_6a__zoom_off;
    v11 = pOldViewport->uGameY + 2;
    v0 = pOldViewport->uGameX + 407;
  }
  else
  {
    v13 = uTextureID_tab_an_6b__zoom_on;
    v11 = pOldViewport->uGameY + 1;
    v0 = pOldViewport->uGameX + 398;
  }
  Render_DrawTransparentTexture(pD3DRenderer, v0, v11, (cTexture *)v13);
  if ( dword_506544 || dword_506528 + dword_506520 >= dword_506524 )
  {
    v14 = uTextureID_tab_an_7a__zoot_off;
    v12 = pOldViewport->uGameY + 38;
    v1 = pOldViewport->uGameX + 407;
  }
  else
  {
    v14 = uTextureID_tab_an_7b__zoot_on;
    v12 = pOldViewport->uGameY + 38;
    v1 = pOldViewport->uGameX + 398;
  }
  Render_DrawTransparentTexture(pD3DRenderer, v1, v12, (cTexture *)v14);
  if ( !byte_5C6D50[dword_506528] )
  {
    v3 = stru_5C3610.array_000000[dword_506528];
    local_08.uFrameWidth = 460;
    local_08.uFrameX = 8;
    local_08.uFrameY = 8;
    local_08.uFrameHeight = 344;
    v2 = (const char *)dword_5C8B64[3 * v3];
    local_08.uFrameZ = 467;
    local_08.uFrameW = 351;
    if ( v2 )
      GUIWindow_sub_44D406(&local_08, ptr_5C35F0, 0, 22, 0, v2, 3);
  }
  local_08.uFrameX = 48;
  local_08.uFrameY = 70;
  local_08.uFrameWidth = 360;
  local_08.uFrameHeight = 264;
  v4 = *(_BYTE *)((char *)ptr_5C35E0 + 5) - 3;
  local_08.uFrameZ = 407;
  local_08.uFrameHeight = v4 * 264 / v4;
  local_08.uFrameW = local_08.uFrameHeight + 69;
  if ( dword_506544 )
  {
    if ( dword_506528 + dword_506520 < dword_506524 )
    {
      AudioPlayer_sub_4AA306(pAudioPlayer, 230, 0, 0, -1, 0, 0, 0, 0);
      v5 = dword_50651C++;
      dword_506528 += dword_506520;
      byte_506130[v5] = dword_506520;
    }
  }
  if ( dword_506548 )
  {
    if ( dword_50651C )
    {
      AudioPlayer_sub_4AA306(pAudioPlayer, 230, 0, 0, -1, 0, 0, 0, 0);
      --dword_50651C;
      dword_506528 -= (unsigned __int8)byte_506130[dword_50651C];
    }
  }
  if ( !dword_506520 || dword_506528 < 1 )
  {
    dword_506528 = 0;
    dword_50651C = 0;
  }
  dword_506544 = 0;
  v7 = stru_5C3610.array_000000[dword_506528];
  dword_506548 = 0;
  dword_506520 = 0;
  v8 = (char *)(((char *)(pStorylineText))[12 * v7]);
  v6 = sub_495461_DrawAn_AreYouSureWishTo_Join_Dismiss_ThisNPC_Dialogue((char *)(((char *)(pStorylineText))[12 * v7]), uActiveCharacter - 1, 0, 0, 0, (__int64 *)(8 * v7 + 11326684));
  if ( v8 )
  {
    v9 = Font_sub_44C6C2(ptr_5C35E0, v6, &local_08, 1, (unsigned __int8)byte_5C6D50[dword_506528]);
    FontDrawText(&local_08, ptr_5C35E0, 1, 0, (const char *)v9, 0, local_08.uFrameY + local_08.uFrameHeight, 0);
    ++dword_506520;
  }
}

//----- (00413126) --------------------------------------------------------
void __cdecl sub_413126_DrawSpellbook_Quests()
{
  int v0; // eax@3
  int v1; // eax@7
  int v2; // ecx@11
  int v3; // ebx@16
  int v4; // eax@19
  int v5; // edi@19
  const char *v6; // edi@19
  int v7; // eax@19
  int v8; // [sp-8h] [bp-68h]@3
  int v9; // [sp-8h] [bp-68h]@7
  class cTexture* v10; // [sp-4h] [bp-64h]@3
  class cTexture* v11; // [sp-4h] [bp-64h]@7

  GUIWindow local_0C;
  //int v12; // [sp+Ch] [bp-54h]@9
  //int v13; // [sp+10h] [bp-50h]@9
  //int v14; // [sp+14h] [bp-4Ch]@9
  //int v15; // [sp+18h] [bp-48h]@9
  //int v16; // [sp+1Ch] [bp-44h]@9
  //int v17; // [sp+20h] [bp-40h]@9

  Render_DrawIndexedTexture(pD3DRenderer, pOldViewport->uGameX, pOldViewport->uGameY, uTextureID_lb_bordr__townport__sbquicknot);
  if ( dword_506548 || !dword_506528 )
  {
    v10 = uTextureID_tab_an_6a__zoom_off;
    v8 = pOldViewport->uGameY + 2;
    v0 = pOldViewport->uGameX + 407;
  }
  else
  {
    v10 = uTextureID_tab_an_6b__zoom_on;
    v8 = pOldViewport->uGameY + 1;
    v0 = pOldViewport->uGameX + 398;
  }
  Render_DrawTransparentTexture(pD3DRenderer, v0, v8, v10);
  if ( dword_506544 || dword_506528 + dword_506520 >= dword_506524 )
  {
    v11 = uTextureID_tab_an_7a__zoot_off;
    v9 = pOldViewport->uGameY + 38;
    v1 = pOldViewport->uGameX + 407;
  }
  else
  {
    v11 = uTextureID_tab_an_7b__zoot_on;
    v9 = pOldViewport->uGameY + 38;
    v1 = pOldViewport->uGameX + 398;
  }
  Render_DrawTransparentTexture(pD3DRenderer, v1, v9, v11);
  local_0C.uFrameWidth = 460;
  local_0C.uFrameHeight = 344;
  local_0C.uFrameX = 8;
  local_0C.uFrameY = 8;
  local_0C.uFrameZ = 467;
  local_0C.uFrameW = 351;
  GUIWindow_sub_44D406(&local_0C, ptr_5C35F0, 0, 22, 0, (char *)pGlobalTXT_LocalizationStrings[174], 3);
  local_0C.uFrameX = 48;
  local_0C.uFrameY = 70;
  local_0C.uFrameWidth = 360;
  local_0C.uFrameHeight = 264;
  local_0C.uFrameZ = 407;
  local_0C.uFrameW = 333;
  if ( dword_506544 )
  {
    if ( dword_506528 + dword_506520 < dword_506524 )
    {
      AudioPlayer_sub_4AA306(pAudioPlayer, 230, 0, 0, -1, 0, 0, 0, 0);
      v2 = dword_50651C++;
      dword_506528 += dword_506520;
      byte_506130[v2] = dword_506520;
    }
  }
  if ( dword_506548 )
  {
    if ( dword_50651C )
    {
      AudioPlayer_sub_4AA306(pAudioPlayer, 230, 0, 0, -1, 0, 0, 0, 0);
      --dword_50651C;
      dword_506528 -= (unsigned __int8)byte_506130[dword_50651C];
    }
  }
  if ( !dword_506520 || (v3 = dword_506528, dword_506528 < 1) )
  {
    v3 = 0;
    dword_50651C = 0;
    dword_506528 = 0;
  }
  dword_506544 = 0;
  dword_506548 = 0;
  dword_506520 = 0;
  while ( v3 < dword_506524 )
  {
    v4 = stru_5C3610.array_000000[v3];
    ++dword_506520;
    v6 = (&dword_722F10)[4 * v4];
    FontDrawText(&local_0C, ptr_5C35E0, 1, 0, (&dword_722F10)[4 * v4], 0, 0, 0);
    v7 = CalculateTextHeght(ptr_5C35E0, v6, &local_0C, 1, 0);
    v5 = local_0C.uFrameY + v7;
    if (local_0C.uFrameY + v7 > local_0C.uFrameHeight)
      break;
    Render_DrawTransparentTexture(pD3DRenderer, 100, v5 + 12, uTextureID_divbar);
    ++v3;
    local_0C.uFrameY = v5 + 24;
  }
}

//----- (0041338E) --------------------------------------------------------
void __cdecl sub_41338E_DrawSpellbook_Autonotes()
{
  int v0; // eax@3
  int v1; // eax@7
  signed int v2; // ebp@11
  int v3; // eax@18
  int v4; // eax@24
  int v5; // eax@30
  int v6; // eax@36
  int v7; // eax@42
  signed int v8; // ebp@47
  int v9; // eax@52
  int v10; // eax@56
  int v11; // edx@57
  int v12; // ebp@64
  int v13; // eax@65
  int v14; // edi@65
  const char *v15; // edi@65
  int v16; // eax@65
  int v17; // [sp-8h] [bp-70h]@3
  int v18; // [sp-8h] [bp-70h]@7
  int v19; // [sp-8h] [bp-70h]@18
  int v20; // [sp-8h] [bp-70h]@24
  int v21; // [sp-8h] [bp-70h]@30
  int v22; // [sp-8h] [bp-70h]@36
  int v23; // [sp-8h] [bp-70h]@42
  cTexture* v24; // [sp-4h] [bp-6Ch]@3
  cTexture* v25; // [sp-4h] [bp-6Ch]@7
  cTexture* v26; // [sp-4h] [bp-6Ch]@18
  cTexture* v27; // [sp-4h] [bp-6Ch]@24
  cTexture* v28; // [sp-4h] [bp-6Ch]@30
  cTexture* v29; // [sp-4h] [bp-6Ch]@36
  cTexture* v30; // [sp-4h] [bp-6Ch]@42
  signed __int16 v31; // [sp+10h] [bp-58h]@1
  char *v32; // [sp+10h] [bp-58h]@49

  GUIWindow local_14;
  //int v33; // [sp+14h] [bp-54h]@46
  //int v34; // [sp+18h] [bp-50h]@46
  //int v35; // [sp+1Ch] [bp-4Ch]@46
  //int v36; // [sp+20h] [bp-48h]@46
  //int v37; // [sp+24h] [bp-44h]@46
  //int v38; // [sp+28h] [bp-40h]@46

  v31 = 0;
  Render_DrawIndexedTexture(pD3DRenderer, pOldViewport->uGameX, pOldViewport->uGameY, uTextureID_sbAutonotes);
  if ( dword_506548 || !dword_506528 )
  {
    v24 = uTextureID_tab_an_6a__zoom_off;
    v17 = pOldViewport->uGameY + 2;
    v0 = pOldViewport->uGameX + 407;
  }
  else
  {
    v24 = uTextureID_tab_an_6b__zoom_on;
    v17 = pOldViewport->uGameY + 1;
    v0 = pOldViewport->uGameX + 398;
  }
  Render_DrawTransparentTexture(pD3DRenderer, v0, v17, v24);
  if ( dword_506544 || dword_506528 + dword_506520 >= dword_506524 )
  {
    v25 = uTextureID_tab_an_7a__zoot_off;
    v18 = pOldViewport->uGameY + 38;
    v1 = pOldViewport->uGameX + 407;
  }
  else
  {
    v25 = uTextureID_tab_an_7b__zoot_on;
    v18 = pOldViewport->uGameY + 38;
    v1 = pOldViewport->uGameX + 398;
  }
  Render_DrawTransparentTexture(pD3DRenderer, v1, v18, v25);
  if ( !dword_506540 )
  {
    if ( dword_506568 )
    {
      Render_DrawTransparentTexture(pD3DRenderer, pOldViewport->uGameX + 408, pOldViewport->uGameY + 113, (cTexture *)dword_506390);
      v2 = 1;
      goto LABEL_16;
    }
    goto LABEL_14;
  }
  if ( !dword_506568 )
  {
LABEL_14:
    v2 = 1;
    goto LABEL_15;
  }
  v2 = 1;
  v31 = 1;
  AudioPlayer_sub_4AA306(pAudioPlayer, 75, 0, 0, -1, 0, 0, 0, 0);
LABEL_15:
  dword_506568 = 0;
  Render_DrawTransparentTexture(pD3DRenderer, pOldViewport->uGameX + 398, pOldViewport->uGameY + 113, (cTexture *)dword_506394);
LABEL_16:
  if ( dword_50653C )
  {
    if ( dword_506568 != v2 )
    {
      v31 = v2;
      AudioPlayer_sub_4AA306(pAudioPlayer, 75, 0, 0, -1, 0, 0, 0, 0);
    }
  }
  else
  {
    if ( dword_506568 != v2 )
    {
      v26 = dword_506388;
      v19 = pOldViewport->uGameY + 150;
      v3 = pOldViewport->uGameX + 408;
      goto LABEL_22;
    }
  }
  v26 = dword_50638C;
  dword_506568 = v2;
  v19 = pOldViewport->uGameY + 150;
  v3 = pOldViewport->uGameX + 399;
LABEL_22:
  Render_DrawTransparentTexture(pD3DRenderer, v3, v19, (cTexture *)v26);
  if ( dword_506538 )
  {
    if ( dword_506568 != 2 )
    {
      v31 = v2;
      AudioPlayer_sub_4AA306(pAudioPlayer, 75, 0, 0, -1, 0, 0, 0, 0);
    }
  }
  else
  {
    if ( dword_506568 != 2 )
    {
      v27 = dword_506380;
      v20 = pOldViewport->uGameY + 188;
      v4 = pOldViewport->uGameX + 408;
      goto LABEL_28;
    }
  }
  v27 = dword_506384;
  dword_506568 = 2;
  v20 = pOldViewport->uGameY + 188;
  v4 = pOldViewport->uGameX + 397;
LABEL_28:
  Render_DrawTransparentTexture(pD3DRenderer, v4, v20, (cTexture *)v27);
  if ( dword_506534 )
  {
    if ( dword_506568 != 3 )
    {
      v31 = v2;
      AudioPlayer_sub_4AA306(pAudioPlayer, 75, 0, 0, -1, 0, 0, 0, 0);
    }
  }
  else
  {
    if ( dword_506568 != 3 )
    {
      v28 = dword_506378;
      v21 = pOldViewport->uGameY + 226;
      v5 = pOldViewport->uGameX + 408;
      goto LABEL_34;
    }
  }
  v28 = dword_50637C;
  dword_506568 = 3;
  v21 = pOldViewport->uGameY + 226;
  v5 = pOldViewport->uGameX + 397;
LABEL_34:
  Render_DrawTransparentTexture(pD3DRenderer, v5, v21, (cTexture *)v28);
  if ( dword_506530 )
  {
    if ( dword_506568 != 4 )
    {
      v31 = v2;
      AudioPlayer_sub_4AA306(pAudioPlayer, 75, 0, 0, -1, 0, 0, 0, 0);
    }
  }
  else
  {
    if ( dword_506568 != 4 )
    {
      v29 = dword_506370;
      v22 = pOldViewport->uGameY + 263;
      v6 = pOldViewport->uGameX + 408;
      goto LABEL_40;
    }
  }
  v29 = dword_506374;
  dword_506568 = 4;
  v22 = pOldViewport->uGameY + 264;
  v6 = pOldViewport->uGameX + 397;
LABEL_40:
  Render_DrawTransparentTexture(pD3DRenderer, v6, v22, (cTexture *)v29);
  if ( dword_50652C )
  {
    if ( dword_506568 != 5 )
    {
      v31 = v2;
      AudioPlayer_sub_4AA306(pAudioPlayer, 75, 0, 0, -1, 0, 0, 0, 0);
    }
  }
  else
  {
    if ( dword_506568 != 5 )
    {
      v30 = dword_506368;
      v23 = pOldViewport->uGameY + 302;
      v7 = pOldViewport->uGameX + 408;
      goto LABEL_46;
    }
  }
  v30 = dword_50636C;
  dword_506568 = 5;
  v23 = pOldViewport->uGameY + 302;
  v7 = pOldViewport->uGameX + 397;
LABEL_46:
  Render_DrawTransparentTexture(pD3DRenderer, v7, v23, (cTexture *)v30);
  local_14.uFrameWidth = 460;
  local_14.uFrameHeight = 344;
  local_14.uFrameX = 8;
  local_14.uFrameY = 8;
  local_14.uFrameZ = 467;
  local_14.uFrameW = 467;
  GUIWindow_sub_44D406(&local_14, ptr_5C35F0, 0, 22, 0, (char *)pGlobalTXT_LocalizationStrings[154], 3);

  local_14.uFrameX = 48;
  local_14.uFrameY = 70;
  local_14.uFrameWidth = 360;
  local_14.uFrameHeight = 264;
  local_14.uFrameZ = 407;
  local_14.uFrameW = 333;
  if ( v31 )
  {
    dword_506524 = 0;
    dword_506528 = 0;
    dword_50651C = 0;
    dword_506520 = 0;
    v8 = 0;
    do
    {
      if ( dword_72371C[2 * v8] == dword_506568 )
      {
        v32 = (&dword_723718)[8 * (signed __int16)v8];
        if ( (_WORD)v8 )
        {
          if ( (unsigned __int16)sub_449B57((int)pParty_global->unk_000764 + 0x9A, v8) )
          {
            if ( v32 )
            {
              v9 = dword_506520++;
              stru_5C3610.array_000000[v9] = (signed __int16)v8;
            }
          }
        }
      }
      ++v8;
    }
    while ( v8 < 196 );
    dword_506524 = dword_506520;
  }
  else
  {
    if ( dword_506544 )
    {
      v10 = dword_506520 + dword_506528;
      if ( dword_506520 + dword_506528 < dword_506524 )
      {
        v11 = dword_50651C++;
        byte_506130[v11] = dword_506520;
        dword_506528 = v10;
        AudioPlayer_sub_4AA306(pAudioPlayer, 230, 0, 0, -1, 0, 0, 0, 0);
      }
    }
    if ( dword_506548 )
    {
      if ( dword_50651C )
      {
        --dword_50651C;
        dword_506528 -= (unsigned __int8)byte_506130[dword_50651C];
        AudioPlayer_sub_4AA306(pAudioPlayer, 230, 0, 0, -1, 0, 0, 0, 0);
      }
    }
    if ( !dword_506520 || dword_506528 < 1 )
    {
      dword_506528 = 0;
      dword_50651C = 0;
    }
  }
  v12 = dword_506528;
  dword_50652C = 0;
  dword_506544 = 0;
  dword_506548 = 0;
  dword_506520 = 0;
  dword_506530 = 0;
  dword_506534 = 0;
  dword_506538 = 0;
  dword_50653C = 0;
  dword_506540 = 0;
  while ( v12 < dword_506524 )
  {
    v13 = stru_5C3610.array_000000[v12];
    ++dword_506520;
    v15 = (&dword_723718)[8 * v13];
    FontDrawText(&local_14, ptr_5C35E0, 1, 0, (&dword_723718)[8 * v13], 0, 0, 0);
    v16 = CalculateTextHeght(ptr_5C35E0, v15, &local_14, 1, 0);
    v14 = local_14.uFrameY + v16;
    if (local_14.uFrameY + v16 > local_14.uFrameHeight)
      break;
    Render_DrawTransparentTexture(pD3DRenderer, 100, v14 + 12, uTextureID_divbar);
    ++v12;
    local_14.uFrameY = v14 + 24;
  }
}

//----- (00413980) --------------------------------------------------------
char *__cdecl sub_413980()
{
  int v0; // eax@3
  int v1; // eax@7
  int v2; // eax@10
  int v3; // eax@13
  int v4; // eax@16
  int v5; // eax@19
  int v6; // eax@31
  signed int v7; // eax@35
  int v9; // [sp-8h] [bp-E0h]@3
  int v10; // [sp-8h] [bp-E0h]@7
  int v11; // [sp-8h] [bp-E0h]@10
  int v12; // [sp-8h] [bp-E0h]@13
  int v13; // [sp-8h] [bp-E0h]@16
  int v14; // [sp-8h] [bp-E0h]@19
  class cTexture* v15; // [sp-4h] [bp-DCh]@3
  class cTexture* v16; // [sp-4h] [bp-DCh]@7
  class cTexture* v17; // [sp-4h] [bp-DCh]@10
  class cTexture* v18; // [sp-4h] [bp-DCh]@13
  class cTexture* v19; // [sp-4h] [bp-DCh]@16
  class cTexture* v20; // [sp-4h] [bp-DCh]@19
  char Str; // [sp+Ch] [bp-CCh]@37

  GUIWindow local_84;
  //int v22; // [sp+84h] [bp-54h]@35
  //int v23; // [sp+88h] [bp-50h]@35
  //int v24; // [sp+8Ch] [bp-4Ch]@35
  //int v25; // [sp+90h] [bp-48h]@35
  //int v26; // [sp+94h] [bp-44h]@35
  //int v27; // [sp+98h] [bp-40h]@35

  Render_DrawIndexedTexture(pD3DRenderer, pOldViewport->uGameX, pOldViewport->uGameY, (cTexture *)dword_5064D0);
  if ( dword_506548 || struct_576FE8.dword_00002C / 128 >= 12 )
  {
    v15 = uTextureID_tab_an_6a__zoom_off;
    v9 = pOldViewport->uGameY + 2;
    v0 = pOldViewport->uGameX + 408;
  }
  else
  {
    v15 = uTextureID_tab_an_6b__zoom_on;
    v9 = pOldViewport->uGameY + 1;
    v0 = pOldViewport->uGameX + 398;
  }
  Render_DrawTransparentTexture(pD3DRenderer, v0, v9, (cTexture *)v15);
  if ( dword_506544 || struct_576FE8.dword_00002C / 128 <= 3 )
  {
    v16 = uTextureID_tab_an_7a__zoot_off;
    v10 = pOldViewport->uGameY + 38;
    v1 = pOldViewport->uGameX + 408;
  }
  else
  {
    v16 = uTextureID_tab_an_7b__zoot_on;
    v10 = pOldViewport->uGameY + 38;
    v1 = pOldViewport->uGameX + 398;
  }
  Render_DrawTransparentTexture(pD3DRenderer, v1, v10, (cTexture *)v16);
  if ( dword_506540 )
  {
    v17 = dword_506390;
    v11 = pOldViewport->uGameY + 113;
    v2 = pOldViewport->uGameX + 408;
  }
  else
  {
    v17 = dword_506394;
    v11 = pOldViewport->uGameY + 113;
    v2 = pOldViewport->uGameX + 398;
  }
  Render_DrawTransparentTexture(pD3DRenderer, v2, v11, (cTexture *)v17);
  if ( dword_50653C )
  {
    v18 = dword_506388;
    v12 = pOldViewport->uGameX + 150;
    v3 = pOldViewport->uGameY + 408;
  }
  else
  {
    v18 = dword_50638C;
    v12 = pOldViewport->uGameX + 150;
    v3 = pOldViewport->uGameY + 399;
  }
  Render_DrawTransparentTexture(pD3DRenderer, v3, v12, (cTexture *)v18);
  if ( dword_506538 )
  {
    v19 = dword_506380;
    v13 = pOldViewport->uGameY + 188;
    v4 = pOldViewport->uGameX + 408;
  }
  else
  {
    v19 = dword_506384;
    v13 = pOldViewport->uGameY + 188;
    v4 = pOldViewport->uGameX + 397;
  }
  Render_DrawTransparentTexture(pD3DRenderer, v4, v13, (cTexture *)v19);
  if ( dword_506534 )
  {
    v20 = dword_506378;
    v14 = pOldViewport->uGameY + 226;
    v5 = pOldViewport->uGameX + 408;
  }
  else
  {
    v20 = dword_50637C;
    v14 = pOldViewport->uGameY + 226;
    v5 = pOldViewport->uGameX + 397;
  }
  Render_DrawTransparentTexture(pD3DRenderer, v5, v14, (cTexture *)v20);
  if ( dword_506544 )
    sub_443291((int)&struct_576FE8);
  if ( dword_506548 )
    sub_443249((int)&struct_576FE8);
  if ( dword_506540 )
    sub_443219((int)&struct_576FE8);
  if ( dword_50653C )
    sub_443231((int)&struct_576FE8);
  if ( dword_506538 )
    sub_44323D((int)&struct_576FE8);
  v6 = dword_506534;
  if ( dword_506534 )
  {
    sub_443225((int)&struct_576FE8);
    v6 = dword_506534;
  }
  if ( dword_506548 | dword_506544 | dword_506540 | dword_50653C | dword_506538 | v6 )
    AudioPlayer_sub_4AA306(pAudioPlayer, 75, 0, 0, -1, 0, 0, 0, 0);
  dword_506548 = 0;
  dword_506544 = 0;
  dword_506534 = 0;
  dword_506538 = 0;
  dword_50653C = 0;
  dword_506540 = 0;
  sub_442955(97, 49, 361, 313, 0);
  Render_DrawTransparentTexture(pD3DRenderer, 75, 22, &LODFile_Icons_LOD.aLODHeaders[dword_506498_uTextureID_MapBrdr]);
  local_84.uFrameWidth = 460;
  local_84.uFrameHeight = 344;
  local_84.uFrameX = 8;
  local_84.uFrameY = 8;
  local_84.uFrameZ = 467;
  local_84.uFrameW = 467;
  v7 = CMapStats_FindLocation(pMapStats, Str1);
  if ( v7 )
   GUIWindow_sub_44D406(&local_84, ptr_5C35F0, -14, 12, 0, (const char *)&pMapStats->pMapInfos[v7], 3);
  local_84.uFrameX = 0;
  wsprintfA(&Str, (char *)pGlobalTXT_LocalizationStrings[659], pParty_global->sPartyPosX, pParty_global->sPartyPosY);
  return GUIWindow_sub_44D406(&local_84, pFontComic, 0, 320, 0, &Str, 0);
}

//----- (00413CC6) --------------------------------------------------------
void __thiscall sub_413CC6_DrawSpellbook(void *_this)
{
  void *v1; // esi@1

  v1 = _this;
  Render_DrawTransparentTexture(pD3DRenderer, 471, 445, &LODFile_Icons_LOD.aLODHeaders[uTextureID_right_backgr]);
  if ( v1 == (void *)177 )
  {
    sub_410DEC();
  }
  else
  {
    if ( v1 == (void *)195 )
    {
      sub_411150();
    }
    else
    {
      if ( v1 == (void *)200 )
        sub_413126_DrawSpellbook_Quests();
      else
      {
        if ( v1 == (void *)201 )
          sub_41338E_DrawSpellbook_Autonotes();
        else
        {
          if ( v1 == (void *)202 )
          {
            sub_413980();
          }
          else
          {
            if ( v1 == (void *)203 )
            {
              sub_413D6F();
            }
            else
            {
              if ( (char *)v1 - 203 == (void *)21 )
                sub_412E85();
            }
          }
        }
      }
    }
  }
}

//----- (00413D3C) --------------------------------------------------------
int __cdecl sub_413D3C()
{
  if ( (unsigned int)pParty_global->uCurrentHour > 4 )
  {
    if ( pParty_global->uCurrentHour == 5 )
      return (int)pGlobalTXT_LocalizationStrings[55];
    if ( pParty_global->uCurrentHour == 20 )
      return (int)pGlobalTXT_LocalizationStrings[566];
    if ( (unsigned int)pParty_global->uCurrentHour <= 0x14 || (unsigned int)pParty_global->uCurrentHour > 0x17 )
      return (int)pGlobalTXT_LocalizationStrings[56];
  }
  return (int)pGlobalTXT_LocalizationStrings[567];
}

//----- (00413D6F) --------------------------------------------------------
void __cdecl sub_413D6F()
{
  signed int v0; // esi@1
  int v1; // eax@5
  int v2; // ecx@5
  int v3; // eax@6

  GUIWindow local_0C;
  //int v5; // [sp+Ch] [bp-60h]@5
  //int v6; // [sp+10h] [bp-5Ch]@5
  //int v7; // [sp+14h] [bp-58h]@5
  //int v8; // [sp+18h] [bp-54h]@5
  //int v9; // [sp+1Ch] [bp-50h]@5
  //int v10; // [sp+20h] [bp-4Ch]@5

  int v11; // [sp+60h] [bp-Ch]@1
  int v12; // [sp+64h] [bp-8h]@1
  int v13; // [sp+68h] [bp-4h]@1

  v0 = pParty_global->uCurrentHour;
  v11 = CMapStats_FindLocation(pMapStats, Str1);
  v13 = 0xFF4B4B4B; //colored or white text flag
  Render_DrawIndexedTexture(pD3DRenderer, pOldViewport->uGameX, pOldViewport->uGameY, (cTexture *)dword_5064D4);
  v12 = (unsigned __int8)byte_4E1B18[pParty_global->uDaysPlayed];
  if ( v0 <= 12 )
  {
    if ( !v0 )
      v0 = 12;
  }
  else
  {
    v0 -= 12;
  }
  local_0C.uFrameX = 8;
  local_0C.uFrameY = 8;
  local_0C.uFrameWidth = 460;
  local_0C.uFrameHeight = 344;
  local_0C.uFrameZ = 467;
  local_0C.uFrameW = 467;
  GUIWindow_sub_44D406(&local_0C, ptr_5C35F0, 0, 22, 0, (char *)pGlobalTXT_LocalizationStrings[186], 3);
  v1 = sub_413D3C();
  wsprintfA((char *)TmpBuf, "%s\t100:\t110%d:%02d %s - %s", pGlobalTXT_LocalizationStrings[526], v0, pParty_global->uCurrentMinute, aAMPMNames[v2], v1);
  FontDrawText(&local_0C, ptr_5C35F4, 70, 55, (char *)TmpBuf, 0, 0, 0);
  wsprintfA((char *)TmpBuf, "%s\t100:\t110%d - %s", pGlobalTXT_LocalizationStrings[56], pParty_global->uDaysPlayed + 1, aDayNames[pParty_global->uDaysPlayed % 7]);
  FontDrawText(&local_0C, ptr_5C35F4, 70, 2 * *(_BYTE *)((char *)ptr_5C35F4 + 5) + 49, (char *)TmpBuf, 0, 0, 0);
  wsprintfA((char *)TmpBuf, "%s\t100:\t110%d - %s", pGlobalTXT_LocalizationStrings[146], pParty_global->uCurrentMonth + 1, aMonthNames[pParty_global->uCurrentMonth]);
  FontDrawText(&local_0C, ptr_5C35F4, 70, 4 * *(_BYTE *)((char *)ptr_5C35F4 + 5) + 43, (char *)TmpBuf, 0, 0, 0);
  wsprintfA((char *)TmpBuf, "%s\t100:\t110%d", pGlobalTXT_LocalizationStrings[245], pParty_global->uCurrentYear);
  FontDrawText(&local_0C, ptr_5C35F4, 70, 6 * *(_BYTE *)((char *)ptr_5C35F4 + 5) + 37, (char *)TmpBuf, 0, 0, 0);
  wsprintfA((char *)TmpBuf, "%s\t100:\t110%s", pGlobalTXT_LocalizationStrings[530], aMoonPhaseNames[v12]);
  FontDrawText(&local_0C, ptr_5C35F4, 70, 8 * *(_BYTE *)((char *)ptr_5C35F4 + 5) + 31, (char *)TmpBuf, 0, 0, 0);
  if ( v11 )
    v3 = (int)pMapStats->pMapInfos[v11].pLocationName;
  else
    v3 = (int)"Unknown";
  wsprintfA((char *)TmpBuf, "%s\t100:\t110%s", pGlobalTXT_LocalizationStrings[531], v3);
  FontDrawText(&local_0C, ptr_5C35F4, 70, 10 * *(_BYTE *)((char *)ptr_5C35F4 + 5) + 25, (char *)TmpBuf, 0, 0, 0);
}

//----- (004141CA) --------------------------------------------------------
int __fastcall sub_4141CA(int a1, int a2)
{
  int result; // eax@1
  int v3; // edi@1
  int v4; // esi@1

  v3 = a1;
  v4 = a2;
  class24_fn1(pClass24_global);
  dword_506F0C = dword_4E28F8;
  result = (int)GUIWindowCreate(0, 0, 640, 480, 70, v4, v3);
  dword_507BDC = result;
  dword_4E28F8 = 22;
  return result;
}

//----- (0041420D) --------------------------------------------------------
void __cdecl sub_41420D()
{
  int v0; // [sp+4h] [bp-54h]@1
  int v1; // [sp+8h] [bp-50h]@1
  int v2; // [sp+Ch] [bp-4Ch]@1
  int v3; // [sp+10h] [bp-48h]@1
  int v4; // [sp+14h] [bp-44h]@1
  int v5; // [sp+18h] [bp-40h]@1
  const CHAR *v6; // [sp+4Ch] [bp-Ch]@1

  wsprintfA((char *)pStringBuffer, "%s\n \n%s", *(_DWORD *)(dword_507BDC + 72), pGlobalTXT_LocalizationStrings[61]);
  v6 = (char *)pStringBuffer;
  v2 = 400;
  v3 = 100;
  v0 = 120;
  v1 = 140;
  v4 = 519;
  v5 = 239;
  GUIWindow_sub_415551((GUIWindow *)&v0, 0);
}

//----- (0041426F) --------------------------------------------------------
void __cdecl sub_41426F()
{
  int v1; // ecx@1

  v1 = dword_507BDC;
  if ( dword_50CBD0[0] < 40 )
  {
    dword_50CBD0[3 * dword_50CBD0[0] + 1] = *(_DWORD *)(dword_507BDC + 28);
    dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
    dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
  }
  GUIWindowDelete((GUIWindow *)v1);
  dword_507BDC = 0;
  dword_4E28F8 = dword_506F0C;
  class24_sub_426363(pClass24_global);
}

//----- (004142D3) --------------------------------------------------------
void __cdecl sub_4142D3()
{
  __int16 v0; // bp@1
  int v1; // ecx@2
  int v2; // edx@6
  unsigned int v3; // eax@6
  signed int v4; // ecx@7
  signed int v5; // eax@8
  signed int v6; // ebp@16
  char *v7; // ST0C_4@16
  __int16 v8; // ax@16
  char *v9; // ST0C_4@16
  __int16 v10; // ax@16
  char *v11; // ST0C_4@16
  __int16 v12; // ax@16
  char *v13; // ST0C_4@16
  __int16 v14; // ax@16
  char *v15; // ST0C_4@16
  __int16 v16; // ax@16
  char *v17; // ST0C_4@16
  __int16 v18; // ax@16
  char *v19; // ST0C_4@16
  __int16 v20; // ax@16
  char *v21; // ST0C_4@16
  __int16 v22; // ax@16
  char *v23; // ST0C_4@16
  __int16 v24; // ax@16
  char *v25; // ST0C_4@16
  __int16 v26; // ax@16
  char *v27; // ST0C_4@16
  __int16 v28; // ax@16
  char *v29; // ST0C_4@16
  __int16 v30; // ax@16
  char *v31; // ST0C_4@16
  __int16 v32; // ax@16
  char *v33; // ST0C_4@17
  __int16 v34; // ax@17
  char *v35; // ST0C_4@17
  __int16 v36; // ax@17
  char *v37; // ST0C_4@17
  __int16 v38; // ax@17
  char *v39; // ST0C_4@17
  __int16 v40; // ax@17
  char *v41; // ST0C_4@17
  __int16 v42; // ax@17
  char *v43; // ST0C_4@17
  __int16 v44; // ax@17
  char *v45; // ST0C_4@17
  __int16 v46; // ax@17
  char *v47; // ST0C_4@17
  __int16 v48; // ax@17
  char *v49; // ST0C_4@17
  __int16 v50; // ax@17
  char *v51; // ST0C_4@17
  __int16 v52; // ax@17
  char *v53; // ST0C_4@17
  __int16 v54; // ax@17
  char *v55; // ST0C_4@17
  __int16 v56; // ax@17
  char *v57; // ST0C_4@17
  __int16 v58; // ax@17
  __int16 v60; // ax@18
  signed int v61; // [sp-14h] [bp-28h]@16
  char *v62; // [sp-10h] [bp-24h]@16
  int v63; // [sp-Ch] [bp-20h]@16
  signed int v64; // [sp-8h] [bp-1Ch]@16
  char *v65; // [sp-4h] [bp-18h]@16
  __int16 v66; // [sp+10h] [bp-4h]@1

  v0 = 0xFFFFFFFF;//colored or white text flag
  v66 = v0;
  if ( byte_4E28FC )
  {
    v1 = dword_507C0C + 15;
    dword_507C0C = v1;
    if ( v1 == 255 )
      byte_4E28FC = 0;
  }
  else
  {
    v1 = dword_507C0C - 15;
    dword_507C0C = v1;
    if ( v1 == 15 )
      byte_4E28FC = 1;
  }
  v3 = 0xFF000000 | ((v1 & 0x000000FF) << 16);
  v2 = (int)pGUIWindow_CurrentMenu;
  dword_507C08 = v3;
  if ( *(_DWORD *)(pGUIWindow_CurrentMenu + 64) == 2 )
  {
    dword_506E90[dword_506E68] = pKeyboardController->pPressedKeysBuffer[0];
    memset(byte_506E6C, 0, 0x1Cu);
    v4 = 0;
    do
    {
      v5 = 0;
      do
      {
        if ( v4 != v5 )
        {
          if ( dword_506E90[v4] == dword_506E90[v5] )
          {
            byte_506E6C[v4] = 1;
            byte_506E6C[v5] = 1;
          }
        }
        ++v5;
      }
      while ( v5 < 28 );
      ++v4;
    }
    while ( v4 < 28 );
    dword_506E68 = -1;
    *(_DWORD *)(v2 + 64) = 0;
  }
  Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (cTexture *)(dword_507BF4 != -1 ? &LODFile_Icons_LOD.aLODHeaders[dword_507BF4] : 0));
  if ( dword_506F08 == 1 )
  {
    Render_DrawIndexedTexture(pD3DRenderer, 19, 302, (cTexture *)(dword_507C00 != -1 ? 72 * dword_507C00 + 7145548 : 0));
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 23, 142, "ÂÏÅÐÅÄ", 0, 0, 0);
    v7 = sub_45AE2C(dword_506E90[0]);
    v8 = sub_414D24(0);//colored or white text flag
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 127, 142, v7, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 23, 163, "ÍÀÇÀÄ", 0, 0, 0);
    v9 = sub_45AE2C(dword_506E90[1]);
    v10 = sub_414D24((void *)1);//colored or white text flag
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 127, 163, v9, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 23, 184, "ÂËÅÂÎ", 0, 0, 0);
    v11 = sub_45AE2C(dword_506E90[2]);
    v12 = sub_414D24((void *)2);//colored or white text flag
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 127, 184, v11, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 23, 205, "ÂÏÐÀÂÎ", 0, 0, 0);
    v13 = sub_45AE2C(dword_506E90[3]);
    v14 = sub_414D24((void *)3);//colored or white text flag
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 127, 205, v13, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 23, 226, "ÊÐÈÊ", 0, 0, 0);
    v15 = sub_45AE2C(dword_506E90[4]);
    v16 = sub_414D24((void *)4);//colored or white text flag
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 127, 226, v15, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 23, 247, "ÏÐÛÆÎÊ", 0, 0, 0);
    v17 = sub_45AE2C(dword_506E90[5]);
    v18 = sub_414D24((void *)5);//colored or white text flag
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 127, 247, v17, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 23, 268, "Ï.ÐÅÆÈÌ", 0, 0, 0);
    v19 = sub_45AE2C(dword_506E90[6]);
    v20 = sub_414D24((void *)6);//colored or white text flag
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 127, 268, v19, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 247, 142, "ÏÐÈÌ. ÇÀÊË.", 0, 0, 0);
    v21 = sub_45AE2C(dword_506E90[7]);
    v22 = sub_414D24((void *)7);//etc
    v6 = 350;
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 350, 142, v21, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 247, 163, "ÀÒÀÊÀ", 0, 0, 0);
    v23 = sub_45AE2C(dword_506E90[8]);
    v24 = sub_414D24((void *)8);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 350, 163, v23, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 247, 184, "ÄÅÉÑÒÂ.", 0, 0, 0);
    v25 = sub_45AE2C(dword_506E90[9]);
    v26 = sub_414D24((void *)9);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 350, 184, v25, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 247, 205, "ÇÀÊËÈÍ.", 0, 0, 0);
    v27 = sub_45AE2C(dword_506E90[10]);
    v28 = sub_414D24((void *)10);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 350, 205, v27, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 247, 226, "ÈÃÐÎÊ", 0, 0, 0);
    v29 = sub_45AE2C(dword_506E90[11]);
    v30 = sub_414D24((void *)11);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 350, 226, v29, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 247, 247, "ÑËÅÄ. ÈÃÐÎÊ", 0, 0, 0);
    v31 = sub_45AE2C(dword_506E90[12]);
    v32 = sub_414D24((void *)12);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 350, 247, v31, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 247, 268, "ÇÀÄÀÍÈß", 0, 0, 0);
    v65 = 0;
    v64 = 0;
    v63 = 0;
    v62 = sub_45AE2C(dword_506E90[13]);
    v61 = 13;
  }
  else
  {
    Render_DrawIndexedTexture(pD3DRenderer, 127, 302, (cTexture *)(dword_507C04 != -1 ? &LODFile_Icons_LOD.aLODHeaders[dword_507C04] : 0));
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 23, 142, "Á. ÑÏÐÀÂÊÀ", 0, 0, 0);
    v33 = sub_45AE2C(dword_506E90[14]);
    v34 = sub_414D24((void *)14);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 127, 142, v33, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 23, 163, "ÎÒÄÛÕ", 0, 0, 0);
    v35 = sub_45AE2C(dword_506E90[15]);
    v36 = sub_414D24((void *)15);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 127, 163, v35, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 23, 184, "ÒÅÊ. ÂÐÅÌß", 0, 0, 0);
    v37 = sub_45AE2C(dword_506E90[16]);
    v38 = sub_414D24((void *)16);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 127, 184, v37, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 23, 205, "ÀÂÒÎÇÀÌÅÒÊÈ", 0, 0, 0);
    v39 = sub_45AE2C(dword_506E90[17]);
    v40 = sub_414D24((void *)17);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 127, 205, v39, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 23, 226, "ÊÀÐÒÀ", 0, 0, 0);
    v41 = sub_45AE2C(dword_506E90[18]);
    v42 = sub_414D24((void *)18);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 127, 226, v41, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 23, 247, "ÁÅÆÀÒÜ", 0, 0, 0);
    v43 = sub_45AE2C(dword_506E90[19]);
    v44 = sub_414D24((void *)19);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 127, 247, v43, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 23, 268, "Ñ.ÂÂÅÐÕ", 0, 0, 0);
    v45 = sub_45AE2C(dword_506E90[20]);
    v46 = sub_414D24((void *)20);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 127, 268, v45, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 247, 142, "ÑÌ.ÂÍÈÇ", 0, 0, 0);
    v47 = sub_45AE2C(dword_506E90[21]);
    v48 = sub_414D24((void *)21);
    v6 = 350;
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 350, 142, v47, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 247, 163, "ÑÌ. ÂÏÅÐÅÄ", 0, 0, 0);
    v49 = sub_45AE2C(dword_506E90[22]);
    v50 = sub_414D24((void *)22);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 350, 163, v49, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 247, 184, "ÏÐÈÁËÈÇ", 0, 0, 0);
    v51 = sub_45AE2C(dword_506E90[23]);
    v52 = sub_414D24((void *)23);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 350, 184, v51, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 247, 205, "ÎÒÄÀËÈÒÜ", 0, 0, 0);
    v53 = sub_45AE2C(dword_506E90[24]);
    v54 = sub_414D24((void *)24);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 350, 205, v53, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 247, 226, "Ï.ÂÂÅÐÕ", 0, 0, 0);
    v55 = sub_45AE2C(dword_506E90[25]);
    v56 = sub_414D24((void *)25);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 350, 226, v55, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 247, 247, "Ï.ÂÍÈÇ", 0, 0, 0);
    v57 = sub_45AE2C(dword_506E90[26]);
    v58 = sub_414D24((void *)26);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 350, 247, v57, 0, 0, 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 247, 268, "ÇÅÌËß", 0, 0, 0);
    v65 = 0;
    v64 = 0;
    v63 = 0;
    v62 = sub_45AE2C(dword_506E90[27]);
    v61 = 27;
  }
  v60 = sub_414D24((void *)v61);
  FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, v6, 268, v62, v63, v64, (unsigned int)v65);
}

//----- (00414D9A) --------------------------------------------------------
void __cdecl sub_414D9A()
{
  const char *v0; // ST0C_4@3
  unsigned __int16 v1; // ax@3
  int v2; // eax@10

  GUIWindow local_08;
  //int v3; // [sp+8h] [bp-54h]@3
  //int v4; // [sp+Ch] [bp-50h]@3
  //int v5; // [sp+10h] [bp-4Ch]@3
  //int v6; // [sp+14h] [bp-48h]@3
  //int v7; // [sp+18h] [bp-44h]@3
  //int v8; // [sp+1Ch] [bp-40h]@3

  Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (cTexture *)(dword_507C10 != -1 ? 72 * dword_507C10 + 7145548 : 0));
  if ( !pD3DRenderer->dword_040058 )
  {
    if (pD3DRenderer->IsGammaControlSupported())
    {
      Render_DrawIndexedTexture(pD3DRenderer,
        17 * dword_4E2900_GammaPos + 42,
        162,
        &LODFile_Icons_LOD.aLODHeaders[uTextureID_GammaPositions[dword_4E2900_GammaPos]]);
      Render_DrawRGBTexture(pD3DRenderer, 274, 169, &Class33_global3);
      local_08.uFrameX = 22;
      v0 = (char *)pGlobalTXT_LocalizationStrings[226];
      local_08.uFrameY = 190;
      local_08.uFrameWidth = 211;
      local_08.uFrameHeight = 79;
      local_08.uFrameZ = 232;
      local_08.uFrameW = 268;
      v1 = 0xFFFFFF9B;
      GUIWindow_sub_44D406(&local_08, pFontSmallnum, 0, 0, v1, v0, 3);
    }
  }
  if ( !pD3DRenderer->pRenderD3D3 )
  {
    Render_DrawIndexedTexture(pD3DRenderer, 20, 281, (cTexture *)(dword_507C50 != -1 ? 72 * dword_507C50 + 7145548 : 0));
    Render_DrawIndexedTexture(pD3DRenderer, 20, 303, (cTexture *)(dword_507C54 != -1 ? 72 * dword_507C54 + 7145548 : 0));
    v2 = dword_507C58;
    goto LABEL_12;
  }
  if ( *(_BYTE *)(LODWORD(pGame) + 3620) & 0x20 )
    Render_DrawIndexedTexture(pD3DRenderer, 20, 281, (cTexture *)(dword_507C14 != -1 ? 72 * dword_507C14 + 7145548 : 0));
  if ( pD3DRenderer->bUseColoredLights )
    Render_DrawIndexedTexture(pD3DRenderer, 20, 303, (cTexture *)(dword_507C18 != -1 ? 72 * dword_507C18 + 7145548 : 0));
  if ( pD3DRenderer->bTinting )
  {
    v2 = dword_507C1C;
LABEL_12:
    Render_DrawIndexedTexture(pD3DRenderer, 20, 325, (cTexture *)(v2 != -1 ? 72 * v2 + 7145548 : 0));
  }
}

//----- (004A97C6) --------------------------------------------------------
int __fastcall sub_4A97C6(char *a1, int a2, _DWORD a3)
{
  int v5; // edi@1
  _DWORD v6; // eax@5
  int v7; // ebx@5
  int v8; // esi@5
  DWORD v9; // eax@7
  int v10; // eax@8
  int result; // eax@9
  int v12; // eax@15
  int v13; // esi@15
  _DWORD v14; // ecx@16
  int v15; // eax@19
  _BYTE v16; // [sp-18h] [bp-34h]@12
  int v17; // [sp-14h] [bp-30h]@12
  int v18; // [sp-10h] [bp-2Ch]@12
  int v19; // [sp-Ch] [bp-28h]@12
  const char *v20; // [sp-8h] [bp-24h]@12
  int v21; // [sp-4h] [bp-20h]@12
  char v22; // [sp+Ch] [bp-10h]@12
  int v23; // [sp+10h] [bp-Ch]@5
  DWORD NumberOfBytesRead; // [sp+14h] [bp-8h]@8
  char *Source; // [sp+18h] [bp-4h]@1
  void *v26; // [sp+24h] [bp+8h]@8
  _BYTE *v27; // [sp+24h] [bp+8h]@12
 int i;

  Source = a1;
  v5 = a2;

  for (i = 0; i < 3000; ++i)
  {
   if (struct_F1B4D8[i].dword_000000 == a3)
     return struct_F1B4D8[i].dword_00007C;
  }

  sub_4A96FF(0, pAudioPlayer->uNumSounds, Source);
  if ( dword_F1B4C8 == -1 )
    goto LABEL_22;
  v8 = (int)&pAudioPlayer->pSoundHeaders[dword_F1B4C8];
  v7 = v8 + 48;
  v6 = *(_DWORD *)(v8 + 48);
  v23 = *(_DWORD *)(v8 + 48);
  if ( v5 == -1 )
    v5 = (int)mem_mng.AllocatedNamedBuffer( 0, v6 + 4, Source);
  SetFilePointer(pAudioPlayer->hSoundsSource, *(_DWORD *)(v8 + 40), 0, 0);
  v9 = *(_DWORD *)v7;
  if ( *(_DWORD *)(v8 + 44) >= *(_DWORD *)v7 )
  {
    *(_DWORD *)(v8 + 44) = v9;
    if ( v9 )
    {
      ReadFile(pAudioPlayer->hSoundsSource, (LPVOID)(v5 + 4), v9, &NumberOfBytesRead, 0);
    }
    else
    {
      v21 = 448;
      v20 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Sound.cpp";
      v27 = &v16;
      Game_sub_40E2C8(&v16, "Can't load sound file!", (int)((char *)&a3 + 3));
      sub_466D09(&v22, *(int *)&v16, v17, v18, v19, v20, __LINE__);
    }
  }
  else
  {
    v26 = malloc(*(_DWORD *)(v8 + 44));
    ReadFile(pAudioPlayer->hSoundsSource, v26, *(_DWORD *)(v8 + 44), &NumberOfBytesRead, 0);
    MemUnzip((char *)v5 + 4, (unsigned int *)(v8 + 48), v26, *(_DWORD *)(v8 + 44));
    free(v26);
  }
  if ( v5 )
  {
    v13 = v23;
    v12 = 0;
    *(_DWORD *)v5 = v23;
    dword_F1B4D0 = 0;
    if ( struct_F1B4D8[0].dword_00007C )
    {
      v14 = (int)&struct_F1B4D8[0].dword_00007C;
      do
      {
        v14 += 128;
        ++v12;
      }
      while ( *(_DWORD *)v14 );
      dword_F1B4D0 = v12;
    }
    strcpy((char *)struct_F1B4D8[v12].string_000004, Source);
    v15 = dword_F1B4D0++ << 7;
    dword_F79D64 += v13;
    struct_F1B4D8[v15 / 128].dword_00007C = v5;
    result = v5;
  }
  else
  {
LABEL_22:
    result = 0;
  }
  return result;
}

//----- (00414F82) --------------------------------------------------------
void __cdecl sub_414F82_DrawGameOptions()
{
  signed int v0; // eax@1

  Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (cTexture *)(dword_507944 != -1 ? 72 * dword_507944 + 7145548 : 0));
  Render_DrawIndexedTexture(pD3DRenderer, 8, 132, (cTexture *)(dword_507C60 != -1 ? 72 * dword_507C60 + 7145548 : 0));
  v0 = 0;
  if ( uTurnSpeed == 128 )
  {
    v0 = 2;
  }
  else
  {
    if ( uTurnSpeed == 64 )
      v0 = 1;
  }
  Render_DrawIndexedTexture(pD3DRenderer, dword_4E2910[v0], 270, &LODFile_Icons_LOD.aLODHeaders[dword_507C64_TextureID[v0]]);
  if ( dword_6BE374_WalkSoundFlag )
    Render_DrawIndexedTexture(pD3DRenderer, 20, 303, (cTexture *)(dword_507CB4 != -1 ? 72 * dword_507CB4 + 7145548 : 0));
  if ( dword_6BE378_ShowDamageFlag )
    Render_DrawIndexedTexture(pD3DRenderer, 128, 303, (cTexture *)(dword_507CB8 != -1 ? 72 * dword_507CB8 + 7145548 : 0));
  if ( dword_6BE380 )
    Render_DrawIndexedTexture(pD3DRenderer, 128, 325, (cTexture *)(dword_507C84 != -1 ? 72 * dword_507C84 + 7145548 : 0));
  if ( dword_6BE37C )
    Render_DrawIndexedTexture(pD3DRenderer, 20, 325, (cTexture *)(dword_507CB0 != -1 ? 72 * dword_507CB0 + 7145548 : 0));
  Render_DrawIndexedTexture(pD3DRenderer, 17 * uSoundVolumeMultiplier + 265, 162, &LODFile_Icons_LOD.aLODHeaders[uTextureID_SoundLevels[uSoundVolumeMultiplier]]);
  Render_DrawIndexedTexture(pD3DRenderer, 17 * uMusicVolimeMultiplier + 265, 216, &LODFile_Icons_LOD.aLODHeaders[uTextureID_SoundLevels[uMusicVolimeMultiplier]]);
  Render_DrawIndexedTexture(pD3DRenderer, 17 * uVoicesVolumeMultiplier + 265, 270, &LODFile_Icons_LOD.aLODHeaders[uTextureID_SoundLevels[uVoicesVolumeMultiplier]]);
}



//----- (0045F469) --------------------------------------------------------
int __fastcall SaveGame(int a1, int a2)
{
  int result; // eax@1
  int v5; // eax@6
  int v6; // eax@6
  int v7; // eax@6
  int v8; // edi@8
  int v9; // eax@24
  FILE *v10; // edi@24
  unsigned int v11; // edi@30
  void *v12; // esi@31
  void *v13; // esi@31
  int v14; // esi@37
  void *v15; // esi@37
  void *v16; // esi@37
  void *v17; // esi@37
  void *v18; // esi@37
  void *v19; // esi@37
  int v20; // ecx@38
  int v21; // edx@39
  int v22; // esi@39
  void *v23; // esi@41
  void *v24; // esi@41
  int v25; // eax@42
  signed int v26; // edi@42
  unsigned __int8 v27; // zf@43
  unsigned __int8 v28; // sf@43
  signed int v29; // edi@47
  void *v30; // esi@50
  void *v31; // esi@50
  void *v32; // esi@50
  void *v33; // esi@50
  int v34; // esi@51
  int v35; // eax@51
  int  v36; // eax@54
  DWORD v37; // eax@59
  char v38; // [sp-18h] [bp-288h]@8
  int v39; // [sp-14h] [bp-284h]@8
  const char *v40; // [sp-10h] [bp-280h]@6
  const char *v41; // [sp-Ch] [bp-27Ch]@6
  int v42; // [sp-8] [bp-278]@6
  CHAR Buffer; // [sp+Ch] [bp-264h]@59
  char Dir; // [sp+8Ch] [bp-1E4h]@51
  char Drive; // [sp+ACh] [bp-1C4h]@51

  int v47; // [sp+CCh] [bp-1A4h]@10
  char v48[20]; // [sp+E0h] [bp-190h]@10
  __int64 v49; // [sp+F4h] [bp-17Ch]@10
  char v50; // [sp+130h] [bp-140h]@51
  char Ext; // [sp+150h] [bp-120h]@51
  char v52; // [sp+151h] [bp-11Fh]@51
  char FullPath[32]; // [sp+170h] [bp-100h]@51
  char Str[120]; // [sp+190h] [bp-E0h]@8

  int v55; // [sp+208h] [bp-68h]@2
  int v56; // [sp+20Ch] [bp-64h]@2
  int v57; // [sp+210h] [bp-60h]@2
  int v58; // [sp+214h] [bp-5Ch]@2
  int Src; // [sp+218h] [bp-58h]@30
  char v60; // [sp+21Ch] [bp-54h]@30
  char v61; // [sp+21Dh] [bp-53h]@30
  char v62; // [sp+21Eh] [bp-52h]@30
  char v63; // [sp+21Fh] [bp-51h]@30
  int v64; // [sp+220h] [bp-50h]@30
  int v65; // [sp+224h] [bp-4Ch]@30
  int v66; // [sp+228h] [bp-48h]@2

  //local struct
  LODIndex St2; // [sp+22Ch] [bp-44h]@2
  int ElementSize; // [sp+240h] [bp-30h]@5
  int v69; // [sp+24Ch] [bp-24h]@1
  size_t Size; // [sp+250h] [bp-20h]@26
  int v71; // [sp+254h] [bp-1Ch]@1
  void *DstBuf; // [sp+258h] [bp-18h]@2
  const void *v73; // [sp+25Ch] [bp-14h]@32
  int v74; // [sp+260h] [bp-10h]@23
  int v75; // [sp+264h] [bp-Ch]@22
  unsigned int v76; // [sp+268h] [bp-8h]@8
  int v77; // [sp+26Fh] [bp-1h]@8

  v71 = a2;
  v69 = a1;
  strcpy(byte_6BE3B0, Str1);
  result = stricmp(Str1, "d05.blv");
  if ( result )
  {
    DstBuf = malloc(0xF4240);//DstBuf = operator new(0xF4240u);
    Reset_LODIndex(&St2);
    v56 = pParty_global->sPartyPosX;
    v55 = pParty_global->sPartyPosY;
    v66 = pParty_global->sPartyPosZ;
    v57 = pParty_global->sRotationY;
    v58 = pParty_global->sRotationX;
    pParty_global->sPartyPosX = pParty_global->sOldPosX;
    pParty_global->sPartyPosY = pParty_global->sOldPosY;
    pParty_global->sPartyPosZ = pParty_global->sOldPosZ;
    pParty_global->sRotationY = pParty_global->sOldRotationY;
    pParty_global->sRotationX = pParty_global->sOldRotationX;
    pParty_global->dword_000700 = pParty_global->sOldPosZ;

    if (dword_6BE360 == 1)
      qword_6BE6B4 = pParty_global->qword_00002C;
    else
      qword_6A12E0 = pParty_global->qword_00002C;

    runtime_warning(aint workin);
    //v3 = sub_45E03A_SomethingLikeCaptureAScreenshot(150, 112);
    //sub_49F5A2(pD3DRenderer, v3, 150, 112, DstBuf, 1000000, (int)&ElementSize);
    //operator_delete(0, v3);

    strcpy(St2.pFilename, "image.pcx");
    if ( dword_4E28F8 == 11 )
    {
      Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (cTexture *)(dword_69CF20 != -1 ? 72 * dword_69CF20 + 7145548 : 0));
      Render_DrawIndexedTexture(pD3DRenderer, 18, 141, (cTexture *)(dword_69CF18 != -1 ? 72 * dword_69CF18 + 7145548 : 0));
      v40 = (char *)pGlobalTXT_LocalizationStrings[190];
      v5 = AlignText_Center(186, (char *)pGlobalTXT_LocalizationStrings[190], pFontSmallnum);
      FontDrawText(pGUIWindow_CurrentMenu, pFontSmallnum, v5 + 25, 219, v40, 0, 0, 0);
      v41 = (char *)&unk_69BD68 + 100 * dword_6A0CA0;
      v6 = AlignText_Center(186, (const char *)&unk_69BD68 + 100 * dword_6A0CA0, pFontSmallnum);
      GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontSmallnum, v6 + 25, 259, 0, v41, 185, 0);
      v40 = (char *)pGlobalTXT_LocalizationStrings[165];
      v7 = AlignText_Center(186, (char *)pGlobalTXT_LocalizationStrings[165], pFontSmallnum);
      FontDrawText(pGUIWindow_CurrentMenu, pFontSmallnum, v7 + 25, 299, v40, 0, 0, 0);
      pD3DRenderer->Present();
    }
   if ( LODFile_New_LOD.Add_Container_to_File( &St2, DstBuf, 0) )
    {
      wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[612], 200);
      v76 = (unsigned int)&v38;
      Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
      sub_466D09(&v76, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    } 

    strcpy(v48, Str1);
    v49 = pParty_global->qword_00002C;
    strcpy(&St2.pFilename[0], "header.bin");
    St2.size_data = 100;
    if (LODFile_New_LOD.Add_Container_to_File( &St2, &v47, 0) )
    {
      wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[612], 201);
      v76 = (unsigned int)&v38;
      Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
      sub_466D09(&v76, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }

    strcpy(&St2.pFilename[0], "party.bin");
    St2.size_data = 90680;
    if (LODFile_New_LOD.Add_Container_to_File( &St2, pParty_global, 0) )
    {
      wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[612], 202);
      v76 = (unsigned int)&v38;
      Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
      sub_466D09(&v76, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }

    strcpy(&St2.pFilename[0], "clock.bin");
    St2.size_data = 40;
    if (LODFile_New_LOD.Add_Container_to_File( &St2, pClass24_global, 0) )
    {
      wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[612], 203);
      v76 = (unsigned int)&v38;
      Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
      sub_466D09(&v76, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }

    strcpy(&St2.pFilename[0], "overlay.bin");
    St2.size_data = 1008;
    if (LODFile_New_LOD.Add_Container_to_File(&St2, array_5E4D58, 0) )
    {
      wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[612], 204);
      v76 = (unsigned int)&v38;
      Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
      sub_466D09(&v76, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }

    strcpy(&St2.pFilename[0], "npcdata.bin");
    St2.size_data = 38076;
    if (LODFile_New_LOD.Add_Container_to_File(&St2, pNPCStats->pNPCData2, 0) )
    {
      wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[165], 205);
      v76 = (unsigned int)&v38;
      Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
      sub_466D09(&v76, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }

    strcpy(&St2.pFilename[0], "npcgroup.bin");
    St2.size_data = 102;
    if (LODFile_New_LOD.Add_Container_to_File( &St2, pNPCStats->word_017F5A, 0) )
    {
      wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[165], 206);
      v76 = (unsigned int)&v38;
      Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
      sub_466D09(&v76, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }
	   
    v75 = 1;
    do
    {
      v74 = 1;
      do
      {
        v42 = v75;
        wsprintfA(Str, "data\\lloyd%d%d.pcx", v75, v74);
        v10 = fopen(Str, "rb");
        //v10 = (FILE *)v9;
        if ( v10 )
        {
          v42 = v75;
          wsprintfA(St2.pFilename, "lloyd%d%d.pcx", v75, v74);
          fseek(v10, 0, 2);
          St2.size_data = ftell(v10);
          rewind(v10);
          locked_fread(DstBuf, ElementSize, 1u, v10);
          strcpy(Str2, Str);
          fclose(v10);
          remove(Str);
          v9 =LODFile_New_LOD.Add_Container_to_File( &St2, DstBuf, 0);
          if ( v9 )
          {
            wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[165], 207);
            v76 = (unsigned int)&v38;
            Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
            //v9 = 
			sub_466D09(&Size, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
            Size = 5080748;
          }
        }
        ++v74;
      }
      while ( v74 <= 5 );
      ++v75;
    }
    while ( v75 <= 4 );

    if ( !a2 )
    {
      sub_42FA22();
      v11 = (unsigned int)malloc(0xF4240u);
      v76 = v11;
      Src = 91969;
      v60 = 109;
      v61 = 118;
      v62 = 105;
      v63 = 105;
      v64 = 0;
      v65 = 0;
      memcpy((void *)v11, &Src, 0x10u);
      if ( dword_6BE360 == 1 )
      {
        v13 = DstBuf;
        dword_6BE69C = dword_6BE640;
        dword_6BE6A4 = 0;
        dword_6BE6A0 = uNumLevelDecorations;
        memcpy(DstBuf, &unk_6BE68C, 0x28u);
        v13 = (char *)v13 + 40;
        memcpy(v13, byte_6BE6EC, 0x36Bu);
        v12 = (char *)v13 + 875;
        v75 = 0;
        if ( dword_6BE640 > 0 )
        {
          v73 = 0;
          do
          {
            v42 = (int)((char *)v73 + dword_6BE644 + 44);
            memcpy(v12, (const void *)v42, 4u);
            v73 = (char *)v73 + 96;
            v12 = (char *)v12 + 4;
            ++v75;
          }
          while ( v75 < dword_6BE640 );
        }
        v75 = 0;
        if ( (signed int)uNumLevelDecorations > 0 )
        {
         v73 = &pLevelDecorations[0].word_000002;
          do
          {
            memcpy(v12, v73, 2);
            v73 = (char *)v73 + 32;
            v12 = (char *)v12 + 2;
            ++v75;
          }
          while ( v75 < (signed int)uNumLevelDecorations );
        }
        memcpy(v12, &uNumActors, 4u);
        v15 = (char *)v12 + 4;
        memcpy(v15, pActors, 836 * uNumActors);
        v16 = (char *)v15 + 836 * uNumActors;
        memcpy(v16, &uNumLayingItems, 4);
        v16 = (char *)v16 + 4;
        memcpy(v16, pLayingItemsList, 112 * uNumLayingItems);
        v17 = (char *)v16 + 112 * uNumLayingItems;
        memcpy(v17, &dword_5FF140, 4u);
        v17 = (char *)v17 + 4;
        memcpy(v17, array_5E5150, 0x14CC * dword_5FF140);
        v18 = (char *)v17 + 5324 * dword_5FF140;
        compile_error;//memcpy(v18, ::Src, 0x3E80u);
        v18 = (char *)v18 + 16000;
        compile_error;//memcpy(v18, dword_6BE67C, ::Size);
        compile_error;//v19 = (char *)v18 + ::Size;
        memcpy(v19, &global_5E4C90, sizeof(struct struct4));
        v14 = (int)((char *)v19 + 200);
        memcpy((void *)v14, &qword_6BE6B4, 0x38u);
      }
      else
      {
        v20 = 0;
        dword_6A12C8 = 0;
        if ( pClass51_global->uNumBModels > 0 )
        {
          v22 = pClass51_global->uNumBModels;
          v21 = (int)pClass51_global->pBModels + 76;
          do
          {
            v20 += *(_DWORD *)v21;
            v21 += 188;
            --v22;
            dword_6A12C8 = v20;
          }
          while ( v22 );
        }
        v24 = DstBuf;
        dword_6A12D0 = pClass51_global->uNumBModels;
        dword_6A12CC = uNumLevelDecorations;
        memcpy(DstBuf, &unk_6A12B8, 0x28u);
        v24 = (char *)v24 + 40;
        memcpy(v24, &unk_6A1318, 0x3C8u);
        v24 = (char *)v24 + 968;
        memcpy(v24, &unk_6A16E0, 0x3C8u);
        v23 = (char *)v24 + 968;
        v75 = 0;
        if ( pClass51_global->uNumBModels > 0 )
        {
          v25 = (int)pClass51_global->pBModels;
          v26 = 76;
          do
          {
            v27 = *(_DWORD *)(v26 + v25) == 0;
            v28 = *(_DWORD *)(v26 + v25) < 0;
            v71 = 0;
            if ( !(v28 | v27) )
            {
              v73 = 0;
              do
              {
                v42 = (int)((char *)v73 + *(_DWORD *)(v25 + v26 + 8) + 28);
                memcpy(v23, (const void *)v42, 4);
                v25 = (int)pClass51_global->pBModels;
                v73 = (char *)v73 + 308;
                v23 = (char *)v23 + 4;
                ++v71;
              }
              while ( v71 < *(_DWORD *)(v26 + pClass51_global->pBModels) );
            }
            ++v75;
            v26 += 188;
          }
          while ( v75 < pClass51_global->uNumBModels );
        }
        v29 = 0;
        if ( (signed int)uNumLevelDecorations > 0 )
        {
         v71 = (int)&pLevelDecorations[0].word_000002;
          do
          {
            memcpy(v23, (const void *)v71, 2);
            v71 += 32;
            v23 = (char *)v23 + 2;
            ++v29;
          }
          while ( v29 < (signed int)uNumLevelDecorations );
        }
        memcpy(v23, &uNumActors, 4u);
        v30 = (char *)v23 + 4;
        memcpy(v30, pActors, 836 * uNumActors);
        v31 = (char *)v30 + 836 * uNumActors;
        memcpy(v31, &uNumLayingItems, 4u);
        v31 = (char *)v31 + 4;
        memcpy(v31, pLayingItemsList, 112 * uNumLayingItems);
        v32 = (char *)v31 + 112 * uNumLayingItems;
        memcpy(v32, &dword_5FF140, 4u);
        v32 = (char *)v32 + 4;
        memcpy(v32, array_5E5150, 5324 * dword_5FF140);
        v33 = (char *)v32 + 5324 * dword_5FF140;
        memcpy(v33, &global_5E4C90, sizeof(struct struct4));
        v14 = (int)((char *)v33 + 200);
        memcpy((void *)v14, &qword_6A12E0, 0x38u);
        v11 = v76;
      }
      v34 = v14 + 56;
      strcpy(FullPath, Str1);
      _splitpath(FullPath, &Drive, &Dir, &v50, &Ext);
      v52 = 100;
      Size = v34 - (_DWORD)DstBuf;
      v74 = 999984;
      LOBYTE(v35) = compress((void *)(v11 + 16), (unsigned int *)&v74, DstBuf, v34 - (_DWORD)DstBuf);
      if ( v35 || v74 > (signed int)Size )
      {
        memcpy((void *)(v11 + 16), DstBuf, Size);
        v74 = Size;
      }
      v74 += 16;
      memcpy((void *)(v11 + 8), &v74, 4u);
      memcpy((void *)(v11 + 12), &Size, 4u);
      wsprintfA(FullPath, "%s%s", &v50, &Ext);
      strcpy(St2.pFilename, FullPath);
      St2.size_data = v74;
      v36 = LODFile_New_LOD.Add_Container_to_File( &St2, (const void *)v11, 0);
      if ( v36 )
      {
        wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[165], 208);
        v76 = (unsigned int)&v38;
        Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
       // v36 = 
		sub_466D09(&v76, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
      }
     // v9 = (void *)free();
	  free((void *)v11);
    }

    operator_delete(DstBuf);
    if ( v69 )
    {
      if ( !CopyFileA("data\\new.lod", "saves\\autosave.mm7", 0) )
      {
        v37 = GetLastError();
        FormatMessageA(0x1000u, 0, v37, 0x400u, &Buffer, 0x80u, 0);
        wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[612], 300);
        v69 = (int)&v38;
        Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
        sub_466D09(&v69, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
      }
    }
    pParty_global->sPartyPosX = v56;
    pParty_global->sPartyPosY = v55;
    pParty_global->sPartyPosZ = v66;
    pParty_global->dword_000700 = v66;
    pParty_global->sRotationY = v57;
    result = v58;
    pParty_global->sRotationX = v58;
  }
  return result;
}



//----- (004160CA) --------------------------------------------------------
char __fastcall sub_4160CA(int a1, int a2)
{
  int v2; // eax@1
  signed int v3; // edx@1
  signed int v4; // ebx@1
  int v5; // esi@1
  int v6; // edi@2
  signed int i; // edx@8
  int v8; // ecx@9
  __int16 v10; // [sp+Ch] [bp-118h]@1
  char v11; // [sp+Eh] [bp-116h]@1
  __int16 v12; // [sp+11Eh] [bp-6h]@1
  int v13; // [sp+120h] [bp-4h]@1

  v13 = a2;
  v5 = a1;
  v3 = 0;
  v10 = 0;
  v4 = 0;
  memset(&v11, 0, 0x110u);
  v12 = 0;
  v2 = a1 + 532;
  do
  {
    v6 = 0;
    if ( *(_DWORD *)v2 > 0 )
    {
      if ( *(_DWORD *)v2 <= 134 )
        *(&v10 + v4++) = v3;
    }
    ++v3;
    v2 += 36;
  }
  while ( v3 < 138 );
  if ( v4 )
  {
    if ( v13 )
    {
      if ( v13 > 0 )
      {
        do
        {
          LOWORD(v2) = 9 * *(&v10 + v6);
          if ( !(*(_BYTE *)(v5 + 36 * *(&v10 + v6) + 553) & 2) )
          {
            v2 = v5 + 36 * *(&v10 + rand() % v4) + 552;
            *(_DWORD *)v2 |= 2;
          }
          ++v6;
        }
        while ( v6 < v13 );
      }
    }
    else
    {
      for ( i = 0; i < v4; ++i )
      {
        v8 = v5 + 36 * *(&v10 + i) + 552;
        v2 = *(_DWORD *)v8;
        if ( !(BYTE1(v2) & 2) )
        {
          LOBYTE(v2) = v2 | 2;
          *(_DWORD *)v8 = v2;
        }
      }
    }
  }
  return v2;
}

//----- (00416196) --------------------------------------------------------
void __cdecl sub_416196()
{
  int v0; // esi@2
  int v1; // edi@2
  int v2; // eax@5
  signed int v3; // ecx@5
  signed int v4; // eax@5
  int v5; // eax@5
  char v6; // sf@5
  int v7; // eax@7
  int v8; // eax@10
  int v9; // edi@10
  __int16 v10; // ax@10
  int v11; // edx@13
  signed int v12; // edx@23
  int v13; // edx@23
  int v14; // edx@25
  int v15; // edi@25
  signed int v16; // edx@27
  int v17; // eax@54
  int v18; // edx@57
  int v19; // eax@65
  int v20; // edi@67
  int v21; // eax@72
  int v22; // ecx@74
  int v23; // edx@78
  int v24; // eax@79
  int v25; // eax@80
  int v26; // eax@84
  signed int v27; // eax@98
  int v28; // edi@98
  int v29; // esi@98
  signed int v30; // ecx@103
  double v31; // st7@112
  __int64 v32; // qax@113
  signed int v33; // ecx@117
  int v34; // eax@126
  int v35; // ecx@127
  double v36; // st7@132
  signed __int64 v37; // qax@135
  int v38; // eax@138
  int v39; // [sp-10h] [bp-A0h]@83
  int v40; // [sp-Ch] [bp-9Ch]@83
  int v41; // [sp-8h] [bp-98h]@83
  int v42; // [sp-4h] [bp-94h]@83
  int v43; // [sp+Ch] [bp-84h]@140
  int v44; // [sp+10h] [bp-80h]@137
  int v45; // [sp+14h] [bp-7Ch]@137
  int v46; // [sp+18h] [bp-78h]@137
  const CHAR *v47; // [sp+54h] [bp-3Ch]@137
  int v48; // [sp+60h] [bp-30h]@2
  int v49; // [sp+64h] [bp-2Ch]@10
  int v50; // [sp+68h] [bp-28h]@2
  int v51; // [sp+6Ch] [bp-24h]@25
  char v52; // [sp+70h] [bp-20h]@2
  int v53; // [sp+74h] [bp-1Ch]@25
  char v54; // [sp+78h] [bp-18h]@2
  int v55; // [sp+7Ch] [bp-14h]@23
  int v56; // [sp+80h] [bp-10h]@54
  int v57; // [sp+84h] [bp-Ch]@10
  int v58; // [sp+88h] [bp-8h]@2
  int v59; // [sp+8Ch] [bp-4h]@23

  if ( !dword_50CDCC )
  {
    v0 = (int)pPlayers[uActiveCharacter - 1];
    v1 = (int)class03_GetMousePos(pGame->pClass03, (POINT *)&v54);
    v58 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer
                    + 4 * (*(_DWORD *)v1 + dword_5059A8[*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (POINT *)&v52) + 4)])) & 0xFFFF;
    class03_GetMousePos(pGame->pClass03, (POINT *)&v50); //, &v48);
    if ( !v58 )
    {
      if ( v50 <= 13
        || v50 >= 462
        || (v3 = v50 - 14,
            v4 = v48 - 17,
            v50 = v3,
            v48 = v4,
            v5 = 14 * (v4 >> 5),
            v3 >>= 5,
            v6 = v3 + v5 < 0,
            v2 = v3 + v5,
            v58 = v2,
            v6)
        || v2 > 126
        || (v7 = sub_421E75((void *)v0, (int)&v58), !v7) )
        return;
      v58 = v7;
    }
    if ( Player_sub_492C0B(v0) )
    {
      --v58;
      LOBYTE(v10) = Player_sub_48F882((void *)v0, 35);
      v9 = v10 & 0x3F;
      v49 = v10 & 0x3F;
      v57 = sub_458244(v10);
      v8 = v58;
      if (pParty_global->stru_007754.uItemID == 220)
      {
LABEL_116:
        sub_41D895((void *)(v0 + 36 * v8 + 532));
        return;
      }
      if (pParty_global->stru_007754.uItemID >= 200)
      {
        if (pParty_global->stru_007754.uItemID <= 219)
        {
          v11 = v0 + 36 * v58;
          if ( *(_DWORD *)(v11 + 532) == 220 )
          {
           *(_DWORD *)(v11 + 536) = v9 + pClass40->pItems[pParty_global->stru_007754.uItemID - 1].uDamageDice;
            switch (pParty_global->stru_007754.uItemID)
            {
              case 200:
              case 201:
              case 202:
              case 203:
              case 204:
                *(_DWORD *)(v0 + 36 * v58 + 532) = 222;
                break;
              case 205:
              case 206:
              case 207:
              case 208:
              case 209:
                *(_DWORD *)(v0 + 36 * v58 + 532) = 223;
                break;
              case 210:
              case 211:
              case 212:
              case 213:
              case 214:
                *(_DWORD *)(v0 + 36 * v58 + 532) = 224;
                break;
              case 215:
              case 216:
              case 217:
              case 218:
              case 219:
                *(_DWORD *)(v0 + 36 * v58 + 532) = 221;
                break;
              default:
                break;
            }
            class03_sub_4698A6(pGame->pClass03);
            dword_50CDCC = 1;
            if ( dword_4E455C )
            {
              Player_PlaySound((Player *)v0, 16, 0);
              dword_4E455C = 0;
            }
            return;
          }
        }
      }
      if (pParty_global->stru_007754.uItemID < 221 ||
          pParty_global->stru_007754.uItemID > 271 ||
          (v13 = v0 + 36 * v58, v55 = v13, v12 = *(_DWORD *)(v13 + 532), v59 = v12, v12 < 221)
         || v12 > 271 )
      {
        if (pParty_global->stru_007754.uItemID != 236
          && (pParty_global->stru_007754.uItemID < 246 || pParty_global->stru_007754.uItemID > 250)
          && pParty_global->stru_007754.uItemID != 263
          && pParty_global->stru_007754.uItemID != 233 )
          goto LABEL_116;
        v29 = v0 + 36 * v58 + 532;
        v27 = *(_DWORD *)v29;
        v59 = pClass40->pItems[*(_DWORD *)v29 - 1].uEquipType;
        v28 = 1800 * pParty_global->stru_007754.dword_000004;
        if (pParty_global->stru_007754.uItemID != 233)
        {
          if (pParty_global->stru_007754.uItemID == 236)
          {
            v35 = *(_DWORD *)(v29 + 20);
            if ( v35 & 2 || v59 < 0 || v59 > 12 || v27 >= 500 )
              goto LABEL_92;
            LOWORD(v35) = v35 | 0x210;
            *(_DWORD *)(v29 + 20) = v35;
          }
          else
          {
            if (pParty_global->stru_007754.uItemID <= 245)
              goto LABEL_92;
            if (pParty_global->stru_007754.uItemID <= 250)
            {
              sub_458260(v29, pParty_global->qword_00002C);
              v33 = *(_DWORD *)v29;
              if ( *(_DWORD *)v29 >= 64 && v33 <= 65
                || (v57 = *(_DWORD *)(v29 + 20), v57 & 2)
                || *(_DWORD *)(v29 + 12)
                || *(_DWORD *)(v29 + 4)
                || v59 && v59 != 1 && v59 != 2
                || v33 >= 500 )
                goto LABEL_92;
              v34 = dword_4E2544[pParty_global->stru_007754.uItemID];
              v55 = v28 << 7;
              v31 = (double)(v28 << 7);
              *(_DWORD *)(v29 + 12) = v34;
            }
            else
            {
              if (pParty_global->stru_007754.uItemID != 263
                || (sub_458260(v29, pParty_global->qword_00002C), v30 = *(_DWORD *)v29, *(_DWORD *)v29 >= 64) && v30 <= 65
                || (v57 = *(_DWORD *)(v29 + 20), v57 & 2)
                || *(_DWORD *)(v29 + 12)
                || *(_DWORD *)(v29 + 4)
                || v59 && v59 != 1 && v59 != 2
                || v30 >= 500 )
                goto LABEL_92;
              v55 = v28 << 7;
              *(_DWORD *)(v29 + 12) = 40;
              v31 = (double)v55;
            }
            v32 = pParty_global->qword_00002C + (signed int)(signed __int64)(v31 * 0.03333333507180214);
            *(_DWORD *)(v29 + 28) = v32;
            LODWORD(v32) = v57;
            LOBYTE(v32) = v57 | 0x18;
            *(_DWORD *)(v29 + 32) = HIDWORD(v32);
            *(_DWORD *)(v29 + 20) = v32;
          }
          dword_50C9A8 = 256;
          goto LABEL_92;
        }
        v36 = (70.0 - (double)pParty_global->stru_007754.dword_000004) * memory_4D8410.d0_01;
        if ( v36 < 0.0 )
          v36 = 0.0;
        if ( v59 != 12 )
        {
          AudioPlayer_sub_4AA306(pAudioPlayer, 27, 0, 0, -1, 0, 0, 0, 0);
          return;
        }
        v55 = *(_BYTE *)(v29 + 25);
        v37 = (signed __int64)((double)v55 - v36 * (double)v55);
        *(_BYTE *)(v29 + 25) = v37;
        *(_DWORD *)(v29 + 16) = (unsigned __int8)v37;
        goto LABEL_92;
      }
      v14 = v12 - 222;
      v15 = pParty_global->stru_007754.uItemID - 222;
      v51 = v14;
      v53 = 0;
      if (pParty_global->stru_007754.uItemID == 221 || v59 == 221)
      {
        v16 = 5;
      }
      else
      {
        v16 = word_5E1944[v14 + 50 * v15];
        v8 = v58;
      }
      v59 = v16;
      if ( v49 )
      {
        if ( v16 < 225 || v16 > 227 )
        {
          if ( v16 < 228 || v16 > 239 )
          {
            if ( v16 < 240 || v16 > 261 )
            {
              if ( v16 >= 262 && v57 != 4 )
              {
LABEL_53:
                v59 = 4;
                goto LABEL_54;
              }
            }
            else
            {
              if ( v57 <= 2 )
              {
LABEL_38:
                v59 = 3;
                goto LABEL_54;
              }
            }
          }
          else
          {
            if ( v57 == 1 )
            {
LABEL_35:
              v59 = 2;
              goto LABEL_54;
            }
          }
        }
      }
      else
      {
        if ( v16 >= 225 && v16 <= 227 )
        {
          v59 = 1;
          goto LABEL_54;
        }
        if ( v16 >= 228 && v16 <= 239 )
          goto LABEL_35;
        if ( v16 >= 240 && v16 <= 261 )
          goto LABEL_38;
        if ( v16 >= 262 )
          goto LABEL_53;
      }
LABEL_54:
      v57 = 0;
      v56 = v8 + 1;
      v17 = v0 + 5500;
      while ( *(_DWORD *)v17 != v56 )
      {
        ++v57;
        v17 += 4;
        if ( v57 >= 126 )
        {
          v18 = v53;
          goto LABEL_59;
        }
      }
      v18 = v57;
LABEL_59:
      if ( !v59 )
      {
LABEL_115:
        v8 = v58;
        goto LABEL_116;
      }
      if ( v59 == 1 )
      {
        Player_sub_492A36((Player *)v0, v18);
        v26 = rand();
        Player_sub_48DC1E((Player *)v0, v26 % 11 + 10, 0);
        AudioPlayer_sub_4AA306(pAudioPlayer, 8, 0, 0, -1, 0, 0, 0, 0);
        if ( dword_50CBD0[0] < 40 )
        {
          dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
          dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
          dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
        }
        v42 = (int)&v55;
        v41 = (int)&v53;
        v40 = (int)&v56;
        v39 = pParty_global->sPartyPosZ + pParty_global->uEyelevel;
      }
      else
      {
        if ( v59 == 2 )
        {
          Player_sub_492A36((Player *)v0, v18);
          v25 = rand();
          Player_sub_48DC1E((Player *)v0, v25 % 71 + 30, 0);
          v23 = 1;
        }
        else
        {
          if ( v59 == 3 )
          {
            Player_sub_492A36((Player *)v0, v18);
            v24 = rand();
            Player_sub_48DC1E((Player *)v0, v24 % 201 + 50, 0);
            v23 = 5;
          }
          else
          {
            if ( v59 != 4 )
            {
              if ( v59 != 5 )
              {
                v19 = CreateItemInInventory((Player *)v0, -1, 220);
                if ( v19 )
                  *(_DWORD *)(v0 + 36 * v19 + 516) = 1;
                v20 = v51 + 50 * v15;
                *(_DWORD *)(v0 + 36 * v58 + 532) = v59;
                *(_DWORD *)(v0 + 36 * v58 + 536) = (pParty_global->stru_007754.dword_000004 + *(_DWORD *)(v0 + 36 * v58 + 536)) / 2;
                Player_sub_44A5CB((char *)v0, 223, word_5E2CCC[v20]);
LABEL_74:
                v22 = v0 + 36 * v58;
                if ( !*(&pClass40->pItems[*(_DWORD *)(v22 + 532) - 1].uEquipType + 18))
                  *(_DWORD *)(v22 + 552) |= 1u;
                if ( !dword_4E455C )
                  goto LABEL_92;
                Player_PlaySound((Player *)v0, 16, 0);
                goto LABEL_91;
              }
              if ( v49 )
              {
                if ( *(_DWORD *)(v55 + 532) == 221 )
                  *(_DWORD *)(v55 + 532) = pParty_global->stru_007754.uItemID;
                else
                  *(_DWORD *)(v55 + 536) = pParty_global->stru_007754.dword_000004;
                v21 = CreateItemInInventory((Player *)v0, -1, 220);
                if ( v21 )
                  *(_DWORD *)(v0 + 36 * v21 + 516) = 1;
                goto LABEL_74;
              }
              goto LABEL_115;
            }
            Player_sub_492A36((struct Player *)v0, v18);
            Player_sub_492D65((Player *)v0, 16, 0);
            v23 = 0;
          }
        }
        sub_4160CA(v0, v23);
        AudioPlayer_sub_4AA306(pAudioPlayer, 8, 0, 0, -1, 0, 0, 0, 0);
        if ( dword_50CBD0[0] < 40 )
        {
          dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
          dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
          dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
        }
        v42 = (int)&v55;
        v41 = (int)&v53;
        v40 = (int)&v56;
        v39 = pParty_global->sPartyPosZ + pParty_global->uEyelevel;
      }
      sub_43AA99(64, pParty_global->sRotationY, pParty_global->sRotationX, pParty_global->sPartyPosX, pParty_global->sPartyPosY, v39, v40, v41, v42);
      sub_42F7EB(1051, v56, v53, v55, 0, 1, 0, 0, 0);
      if ( dword_4E455C )
      {
        if ( Player_sub_492C0B(v0) )
          Player_PlaySound((Player *)v0, 17, 0);
        sub_44C175((char *)pGlobalTXT_LocalizationStrings[444], 2);
LABEL_91:
        dword_4E455C = 0;
      }
LABEL_92:
      class03_sub_4698A6(pGame->pClass03);
      dword_50CDCC = 1;
      return;
    }
    wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[427], v0 + 168, pGlobalTXT_LocalizationStrings[541]);
    v47 = (char *)TmpBuf;
    v45 = 384;
    v46 = 180;
    v44 = 40;
    if ( *(_DWORD *)class03_GetMousePos(pGame->pClass03, (POINT *)&v54) <= 320 )
      v38 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (POINT *)&v54) + 30;
    else
      v38 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (POINT *)&v54) - 414;
    v43 = v38;
    GUIWindow_sub_415551((GUIWindow *)&v43, 0);
  }
}

//----- (00416B01) --------------------------------------------------------
void __thiscall sub_416B01(void *_this)
{
  int v3; // edi@2
  _UNKNOWN *v4; // esi@7
  char *v5; // eax@16
  char *v6; // esi@16
  const CHAR *v7; // eax@18
  int v8; // eax@25
  int v9; // eax@25
  const char *v10; // esi@26
  const char *v11; // ST14_4@26
  const char *v12; // ST18_4@27
  unsigned __int16 v13; // ax@28
  const char *v14; // eax@28

  GUIWindow local_0C;
  //int v15; // [sp+Ch] [bp-60h]@23
  //int v16; // [sp+10h] [bp-5Ch]@23
  //int v17; // [sp+14h] [bp-58h]@23
  //int v18; // [sp+18h] [bp-54h]@23
  //int v19; // [sp+1Ch] [bp-50h]@23
  //int v20; // [sp+54h] [bp-18h]@23
  int v21; // [sp+60h] [bp-Ch]@16
  void *v22; // [sp+64h] [bp-8h]@1
  LPCSTR lpsz; // [sp+68h] [bp-4h]@6
 int i;

  v22 = _this;
  if ( byte_6BE3C5 != 1 )
  {
    v3 = 0;

    for (i = 0; i < 2; ++i)
    {
     if (pParty_global->pHiredNPCs[i].pNPCName)
        TmpBuf[v3++] = i;
    }

    lpsz = 0;
    if (pNPCStats->dword_017FC4 > 0)
    {
      for (i = 0; i < pNPCStats->dword_017FC4; ++i)
      {
        if (pNPCStats->pNPCData2[i].dword_000008 & 0x80)
        {
          if (!pParty_global->pHiredNPCs[0].pNPCName || strcmp((char *)pNPCStats->pNPCData2[i].pNPCName, (char *)pParty_global->pHiredNPCs[0].pNPCName))
          {
            if (!pParty_global->pHiredNPCs[1].pNPCName || strcmp((char *)pNPCStats->pNPCData2[i].pNPCName, (char *)pParty_global->pHiredNPCs[1].pNPCName))
              TmpBuf[v3++] = i + 2;
          }
        }
      }
    }
    if ( (signed int)((char *)v22 + (unsigned __int8)pParty_global->byte_000709) < v3 )
    {
      uDialogue_SpeakingActorID = -1 - (unsigned __int8)pParty_global->byte_000709 - (_DWORD)v22;
      v5 = sub_445B2C(uDialogue_SpeakingActorID, (int)&v21);
      v6 = v5;
      if ( v5 )
      {
        if ( v21 == 57 )
          v7 = (const CHAR *)dword_72266C;
        else
          //v7 = (&dword_737C2C)[20 * *((_DWORD *)v5 + 6)];
          v7 = (char *)pNPCStats->pProfessions[*((_DWORD *)v5 + 6) - 1].pBenefits;
        lpsz = v7;
        if ( !v7 )
        {
          lpsz = (char *)pNPCStats->pProfessions[*((_DWORD *)v6 + 6) - 1].pJoinText;
          if ( !lpsz )
            lpsz = "";
        }
        local_0C.ptr_000048 = 0;
        local_0C.uFrameX = 38;
        local_0C.uFrameY = 60;
        local_0C.uFrameWidth = 276;
        local_0C.uFrameZ = 313;
        local_0C.uFrameHeight = CalculateTextHeght(pFontArrus, lpsz, &local_0C, 0, 0) + 2 * *(_BYTE *)(pFontArrus + 5) + 24;
        if (local_0C.uFrameHeight < 130)
          local_0C.uFrameHeight = 130;
        local_0C.uFrameWidth = 400;
        local_0C.uFrameZ = local_0C.uFrameX + 399;
        GUIWindow_sub_415551(&local_0C, 0);
        wsprintfA((char *)pStringBuffer, "NPC%03d", *((_DWORD *)v6 + 1));
        v9 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)pStringBuffer, 2);
        Render_DrawIndexedTexture(pD3DRenderer, local_0C.uFrameX + 22, local_0C.uFrameY + 36, (cTexture *)(v9 != -1 ? 72 * v9 + 7145548 : 0));
        v8 = *((_DWORD *)v6 + 6);
        if ( v8 )
        {
          v11 = *(const char **)v6;
          v10 = (char *)TmpBuf;
          wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[429], v11, aNPCProfessionNames[v8]);
        }
        else
        {
          v12 = *(const char **)v6;
          v10 = (char *)TmpBuf;
          strcpy((char *)(char *)TmpBuf, v12);
        }
        v13 = 0xFFFFFF9B;
        GUIWindow_sub_44D406(&local_0C, pFontArrus, 0, 12, v13, v10, 3);
        local_0C.uFrameWidth -= 24;
        local_0C.uFrameZ = local_0C.uFrameX + local_0C.uFrameWidth - 1;
        v14 = sub_495461_DrawAn_AreYouSureWishTo_Join_Dismiss_ThisNPC_Dialogue((char *)lpsz, uActiveCharacter - 1, 0, 0, 0, 0);
        FontDrawText(&local_0C, pFontArrus, 100, 36, v14, 0, 0, 0);
      }
    }
  }
}

//----- (00449B7E) --------------------------------------------------------
int __fastcall sub_449B7E(int a1, __int16 a2, __int16 a3)
{
  int result; // eax@1
  unsigned int v4; // edx@1
  signed int v5; // esi@1

  v5 = a2 - 1;
  result = a1 + (signed __int16)(v5 >> 3);
  v4 = 0x80u >> v5 % 8;
  if ( a3 )
    *(_BYTE *)result |= v4;
  else
    *(_BYTE *)result &= ~(_BYTE)v4;
  return result;
}

//----- (00416D62) --------------------------------------------------------
void __thiscall sub_416D62_ShowMonsterRecord(int _this)
{
  signed int v1; // eax@12
  char *v2; // eax@32
  void *v3; // ecx@52
  int v4; // eax@59
  int v5; // esi@62
  signed int v6; // esi@64
  int v7; // esi@69
  void *v8; // ecx@70
  int v9; // eax@72
  int v10; // eax@76
  char v11; // zf@83
  int v12; // esi@84
  int v13; // ecx@85
  int v14; // edi@85
  signed int v15; // eax@92
  int v16; // eax@95
  int v17; // eax@96
  int v18; // eax@98
  int v19; // eax@99
  int v20; // eax@108
  int v21; // eax@109
  const char *v22; // eax@111
  char *v23; // ebx@112
  char *v24; // edx@113
  unsigned int v25; // eax@113

  GUIWindow local_04;
  //int v26; // [sp+4h] [bp-74h]@33
  //int v27; // [sp+8h] [bp-70h]@33
  //int v28; // [sp+Ch] [bp-6Ch]@33
  //int v29; // [sp+10h] [bp-68h]@37
  //int v30; // [sp+14h] [bp-64h]@113
  //int v31; // [sp+18h] [bp-60h]@113
  //int v32; // [sp+20h] [bp-58h]@36
  //char *Str1; // [sp+4Ch] [bp-2Ch]@32

  double v34; // [sp+58h] [bp-20h]@33
  struct tagPOINT Point; // [sp+60h] [bp-18h]@6
  int v36; // [sp+68h] [bp-10h]@33
  float v37; // [sp+6Ch] [bp-Ch]@33
  int v38; // [sp+70h] [bp-8h]@3
  int v39; // [sp+74h] [bp-4h]@3

  if ( dword_4E28F8 == 16 )
    return;
  if ( _this )
  {
    v38 = *(_DWORD *)_this;
    v39 = *(_DWORD *)(_this + 4);
  }
  else
  {
    class03_GetMouseClickPos(pGame->pClass03, &v38, &v39);
  }
  if ( pD3DRenderer->dword_040058 )
  {
    GetCursorPos(&Point);
    ScreenToClient(pAppWindow->GetAPIHandle(), &Point);
    if ( (_DWORD)Point.x < 1 || Point.y < 1 || (_DWORD)Point.x > 638 || Point.y > 478 )
    {
      sub_4356FF();
      return;
    }
  }
  if (pParty_global->stru_007754.uItemID)
  {
    v1 = 0;
    do
    {
      if ( v38 > word_4E2930[v1] && v38 < word_4E2938[v1] && v39 > 375 && v39 < 466 )
      {
        sub_4680ED(pPlayers[uActiveCharacter - 1], v1 + 1, 1);
        return;
      }
      ++v1;
    }
    while ( v1 < 4 );
  }
  class24_fn1(pClass24_global);
  if ( dword_4E28F8 <= 10 )
  {
    if ( dword_4E28F8 == 10 )
    {
      if ( !Player_sub_492C0B((int)pPlayers[uActiveCharacter - 1]) )
      {
        wsprintfA((char *)TmpBuf,
          (char *)pGlobalTXT_LocalizationStrings[427],
          (char *)pPlayers[uActiveCharacter - 1] + 0xA8,
          pGlobalTXT_LocalizationStrings[541]);
        local_04.ptr_000048 = TmpBuf;
        local_04.uFrameWidth = 384;
        local_04.uFrameHeight = 180;
        local_04.uFrameY = 40;
        if ( v38 <= 320 )
          v10 = v38 + 30;
        else
          v10 = v38 - 414;
        local_04.uFrameX = v10;
        goto LABEL_42;
      }
      v9 = v38 + dword_5059A8[v39];
      if ( !(pD3DRenderer->pActiveZBuffer[v9] & 0xFFFF) )
        goto LABEL_132;
      v8 = (char *)&dword_5E5130[1331 * *(_DWORD *)(dword_507BB8 + 28)] +
        //36 * word_5E6502[(*(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * v9) & 0xFFFF) + 2662 * *(_DWORD *)(dword_507BB8 + 28)];
          36 * ((short *)((char *)&array_5E5150[*(_DWORD *)(dword_507BB8 + 28)] + 0x13B2))[(pD3DRenderer->pActiveZBuffer[v9] & 0xFFFF)];


          
    }
    else
    {
      if ( dword_4E28F8 )
      {
        if ( dword_4E28F8 != 3 )
        {
          if ( dword_4E28F8 != 7 )
          {
            if ( dword_4E28F8 == 8 )
            {
              if ( dword_507B00 )
                sub_410B28((void *)(dword_507B00 - 1));
            }
            goto LABEL_132;
          }
LABEL_119:
          if ( v38 > 467 && dword_4E28F8 != 14 )
          {
LABEL_126:
            sub_416196();
            goto LABEL_132;
          }
          if ( v39 >= 345 )
            goto LABEL_132;
          if ( dword_506F48 == 100 )
          {
            CharacterUI_StatsTab_ShowHint();
            goto LABEL_132;
          }
          if ( dword_506F48 == 101 )
          {
            CharacterUI_SkillsTab_ShowHint();
            goto LABEL_132;
          }
          v11 = dword_506F48 == 103;
LABEL_125:
          if ( !v11 )
            goto LABEL_132;
          goto LABEL_126;
        }
        if ( !dword_506364
          || v38 < pOldViewport->uGameX
          || v38 > pOldViewport->uGameZ
          || v39 < pOldViewport->uGameY
          || v39 > pOldViewport->uGameW
          || (v2 = sub_444564(), local_04.ptr_000048 = (unsigned char *)v2, !v2) )
          goto LABEL_132;
        v37 = (double)(GetStringWidth(pFontArrus, v2) + 32);
        v34 = v37 + 6.755399441055744e15;
        v36 = LODWORD(v34);
        local_04.uFrameWidth = LODWORD(v34);
        local_04.uFrameX = v38 + 5;
        local_04.uFrameY = v39 + 5;
        goto LABEL_41;
      }
      if ( sub_466CA0() >= 0 )
        goto LABEL_132;
      if ( v39 > pOldViewport->uGameW )
      {
       local_04.dword_00001C = v38 / 118;
        if ( v38 / 118 < 4 )
        {
          local_04.ptr_000048 = 0;
          local_04.uFrameWidth = 400;
          local_04.uFrameHeight = 200;
          local_04.uFrameX = 38;
          local_04.uFrameY = 60;
          AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
          GUIWindow_sub_41D3B7(&local_04);
        }
        goto LABEL_132;
      }
      if ( v38 > pOldViewport->uGameZ )
      {
        if ( v39 >= 130 )
        {
          if ( v38 >= 476 && v38 <= 636 && v39 >= 240 && v39 <= 300 )
          {
            local_04.ptr_000048 = 0;
            local_04.uFrameWidth = 400;
            local_04.uFrameHeight = 200;
            local_04.uFrameX = 38;
            local_04.uFrameY = 60;
            AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
            GUIWindow_sub_41D73D((int)&local_04);
            goto LABEL_132;
          }
          if ( v38 < 485 || v38 > 548 || v39 < 156 || v39 > 229 )
          {
            if ( v38 < 566 || v38 > 629 || v39 < 156 || v39 > 229 )
              goto LABEL_132;
            AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
            v3 = (void *)1;
          }
          else
          {
            AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
            v3 = 0;
          }
          sub_416B01(v3);
          goto LABEL_132;
        }
        local_04.ptr_000048 = (unsigned char *)sub_4443D5();
        local_04.uFrameWidth = 256;
        local_04.uFrameX = 130;
        local_04.uFrameY = 140;
LABEL_41:
        local_04.uFrameHeight = 64;
        AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
LABEL_42:
        GUIWindow_sub_415551(&local_04, 0);
        goto LABEL_132;
      }
      local_04.ptr_000048 = 0;
      local_04.uFrameWidth = 320;
      local_04.uFrameHeight = 320;
      v4 = v38 - 350;
      if ( v38 <= 320 )
        v4 = v38 + 30;
      local_04.uFrameX = v4;
      local_04.uFrameY = 40;
      if ( pD3DRenderer->pRenderD3D3 )
        LOWORD(v5) = sub_4C1BF1_Vis_LooksLikeFindTopmostZObject(pGame->pVis);
      else
        v5 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * (v38 + dword_5059A8[v39]));
      v6 = (unsigned __int16)v5;
      if ( (v6 & 7) != 2 )
      {
        if ( (v6 & 7) == 3 )
        {
          if ( pD3DRenderer->bSceneBegun)
          {
            GUIWindow_sub_415551(&local_04, 1);
            sub_41E360(v6 >> 3, (int)&local_04);
          }
          else
          {
            pD3DRenderer->BeginScene();
            GUIWindow_sub_415551(&local_04, 1);
            sub_41E360(v6 >> 3, (int)&local_04);
            pD3DRenderer->EndScene();
          }
        }
        goto LABEL_132;
      }
      v7 = 112 * (v6 >> 3);
      if ( *(_BYTE *)(56 * pLayingItemsList[v6 >> 3].uObjectDescriptionID + pObjectDescriptionList->pDescriptions + 38) & 0x10 )
        goto LABEL_132;
      v8 = &pLayingItemsList[v7/112].stru_000024;
    }
    sub_41D895(v8);
    goto LABEL_132;
  }
  if ( dword_4E28F8 == 13 )
  {
    if ( v39 < 345 )
    {
      if ( v38 < 469 )
        sub_4B1A2D();
    }
    goto LABEL_132;
  }
  if ( dword_4E28F8 <= 13 )
    goto LABEL_132;
  if ( dword_4E28F8 <= 15 )
    goto LABEL_119;
  if ( dword_4E28F8 != 21 )
  {
    v11 = dword_4E28F8 == 23;
    goto LABEL_125;
  }
  local_04.ptr_000048 = 0;
  v12 = *(_DWORD *)(pGUIWindow_CurrentMenu + 76);
  if ( !v12 )
    goto LABEL_132;
  v13 = v39;
  v14 = v36;
  while ( 1 )
  {
    if ( *(_DWORD *)(v12 + 24) != 1 && *(_DWORD *)(v12 + 24) != 3
      || v38 < *(_DWORD *)v12
      || v38 > *(_DWORD *)(v12 + 16)
      || v13 < *(_DWORD *)(v12 + 4)
      || v13 > *(_DWORD *)(v12 + 20) )
      goto LABEL_117;
    v15 = *(_DWORD *)(v12 + 32);
    if ( v15 <= 65 )
    {
      if ( v15 == 65 )
      {
        local_04.ptr_000048 = pClassDescriptions[*(_DWORD *)(v12 + 36)];
        v14 = (int)(aClassNames[*(_DWORD *)(v12 + 36)]);
      }
      else
      {
        if ( v15 )
        {
          v16 = v15 - 62;
          if ( v16 )
          {
            v17 = v16 - 1;
            if ( v17 )
            {
              if ( v17 == 1 )
              {
                v18 = 4 * GetSkillIdxByOrder(&pParty_global->pPlayers[1743 * uPlayerCreationUI_SelectedCharacter], *(_DWORD *)(v12 + 36) + 4);
                v14 = (int)aSkillNames[v18 / 4];
                local_04.ptr_000048 = array_5C8A70[v18 / 4];
                v13 = v39;
              }
              goto LABEL_117;
            }
            v14 = (int)pGlobalTXT_LocalizationStrings[668];
            v19 = (int)pGlobalTXT_LocalizationStrings[669];
          }
          else
          {
            v14 = (int)pGlobalTXT_LocalizationStrings[670];
            v19 = (int)pGlobalTXT_LocalizationStrings[671];
          }
          goto LABEL_116;
        }
        local_04.ptr_000048 = pAttributeDescriptions[*(_DWORD *)(v12 + 36) % 7];
        v14 = (int)aAttributeNames[*(_DWORD *)(v12 + 36) % 7];
      }
      goto LABEL_117;
    }
    if ( v15 == 66 )
    {
      v19 = (int)pGlobalTXT_LocalizationStrings[664];
      v14 = (int)pGlobalTXT_LocalizationStrings[665];
      goto LABEL_116;
    }
    if ( v15 == 67 )
    {
      v19 = (int)pGlobalTXT_LocalizationStrings[666];
      v14 = (int)pGlobalTXT_LocalizationStrings[667];
      goto LABEL_116;
    }
    if ( v15 > 71 )
      break;
LABEL_117:
    v12 = *(_DWORD *)(v12 + 52);
    if ( !v12 )
      goto LABEL_112;
  }
  if ( v15 > 75 )
  {
    if ( v15 == 118 )
    {
      v20 = 6972 * *(_DWORD *)(v12 + 36);
      v14 = (int)(pParty_global->pPlayers[0].sName + v20);
      v19 = (int)pClassDescriptions[pParty_global->pPlayers[0].uClass + v20];
LABEL_116:
      local_04.ptr_000048 = (unsigned char *)v19;
      goto LABEL_117;
    }
    goto LABEL_117;
  }
  v21 = GetSkillIdxByOrder(&pParty_global->pPlayers[*(_DWORD *)(v12 + 36)], v15 - 72);
  v13 = v21;
  v39 = v21;
  if ( v21 < 0 || v21 >= 37 )
    goto LABEL_117;
  v22 = (const char *)sub_417BB5(*(_DWORD *)(v12 + 36), v21);
  strcpy((char *)pStringBuffer, v22);
  local_04.ptr_000048 = pStringBuffer;
  v14 = (int)aSkillNames[v39];
LABEL_112:
  v23 = Str1;
  if ( Str1 )
  {
    v24 = (char *)local_04.ptr_000048;
    local_04.ptr_000048 = 0;
    local_04.uFrameWidth = 384;
    local_04.uFrameHeight = 256;
    local_04.uFrameX = 128;
    local_04.uFrameY = 40;
    local_04.uFrameHeight = CalculateTextHeght(pFontSmallnum, v24, &local_04, 24, 0) + 2 * *(_BYTE *)(pFontLucida + 5) + 24;
    local_04.uFrameZ = local_04.uFrameX + local_04.uFrameWidth - 1;
    local_04.uFrameW = local_04.uFrameY + local_04.uFrameHeight - 1;
    GUIWindow_sub_415551(&local_04, 0);
    local_04.uFrameX += 12;
    local_04.uFrameWidth -= 24;
    local_04.uFrameY += 12;
    local_04.uFrameHeight -= 12;
    local_04.uFrameZ = local_04.uFrameX + local_04.uFrameWidth - 1;
    local_04.uFrameW = local_04.uFrameY + local_04.uFrameHeight - 1;
    v25 = 0xFFFFFF9B;
    wsprintfA((char *)TmpBuf, "\x0C%05d%s\x0C\x30\x30\x30\x30\x30", v25, v14);
    GUIWindow_sub_44D406(&local_04, pFontCreate, 0, 0, 0, (char *)TmpBuf, 3);
    FontDrawText(&local_04, pFontSmallnum, 1, *(_BYTE *)(pFontLucida + 5), v23, 0, 0, 0);
  }
LABEL_132:
  dword_507BF0 = 1;
  struct_576FE8.dword_000044 = 1;
}

//----- (004175C0) --------------------------------------------------------
void __thiscall OnMouseLeftClick(void *_this)
{
  void *v1; // esi@1
  unsigned int click_x; // eax@7
  unsigned int click_y; // ecx@7
  int v4; // eax@11
  signed int v5; // eax@17
  signed int v6; // esi@19
  int v7; // esi@30
  struct GUIWindow *v8; // edx@31
  struct GUIButton *i; // esi@37
  bool v10; // eax@50
  int v11; // ecx@52
  int v12;
  int v13;

  v1 = _this;
  if ( dword_4E28F8 != 16 && !sub_4637E0() )
  {
    if (pGUIWindow2 && pGUIWindow2->dword_00001C == 33)
    {
      sub_4452BB();
      return;
    }
    if (_this)
    {
      click_x = *(_DWORD *)v1;
      click_y = *((_DWORD *)v1 + 1);
      v12 = *(_DWORD *)v1;
      v13 = click_y;
    }
    else
    {
      class03_GetMouseClickPos(pGame->pClass03, (int *)&click_x, (int *)&click_y);
      v13 = click_y;
      v12 = click_x;
    }
    if ( !dword_4E28F8 && dword_507B98_bCtrlPressed )
    {
      v4 = sub_466CA0();
      click_x = v12;
      if ( v4 >= 0 || v12 < pOldViewport->uGameX || v12 > pOldViewport->uGameZ )
      {
        click_y = v13;
      }
      else
      {
        click_y = v13;
        if ( v13 >= pOldViewport->uGameY && v13 <= pOldViewport->uGameW )
        {
          if ( pD3DRenderer->pRenderD3D3 )
            v5 = sub_4C1BF1_Vis_LooksLikeFindTopmostZObject(pGame->pVis);
          else
            v5 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * (v12 + dword_5059A8[v13]));
          v6 = (unsigned __int16)v5;
          if ( (v5 & 7) == 3 )
          {
            if ( uActiveCharacter )
            {
              if ( v5 < 33554432 )
              {
                if ( Player_sub_492C0B((int)*(&ptr_A750C4 + uActiveCharacter)) )
                {
                  if ( sub_492C40(pPlayers[uActiveCharacter - 1]) )
                  {
                    if ( dword_50CBD0[0] < 40 )
                    {
                      dword_50CBD0[3 * dword_50CBD0[0] + 1] = 27;
                      dword_50CBD0[3 * dword_50CBD0[0] + 2] = v6 >> 3;
                      dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
                    }
                    if (pParty_global->dword_00087C == 1)
                    {
                      if ( dword_4F885C == 3 )
                        dword_4F8870 |= 8u;
                    }
                  }
                }
              }
            }
          }
          return;
        }
      }
    }
    v7 = sLastGUIWindowIdx;
    if ( sLastGUIWindowIdx < 0 )
      return;
    while ( 1 )
    {
      v8 = &GUIWindow_List[array_5075E0[v7] - 1];
      if (click_x >= v8->uFrameX && click_x <= v8->uFrameZ &&
          click_y >= v8->uFrameY && click_y <= v8->uFrameW)
          break;

      --v7;
      if ( v7 < 0 )
        return;
    }
    for ( i = v8->pControlsHead; ; i = i->pNext)
    {
      if ( !i )
        return;
      if (i->dword_000018 == 1 )
        goto LABEL_41;
      if (i->dword_000018 != 2 )
      {
        if (i->dword_000018 != 3 )
          continue;
LABEL_41:
        if (click_x >= i->uX && click_x <= i->uZ &&
            click_y >= i->uY && click_y <= i->uW)
        {
LABEL_50:
          i->dword_00002C = 1;
          v10 = dword_50CBD0[0];
          if ( dword_50CBD0[0] )
          {
            v10 = dword_50CBD0[3] != 0;
            dword_50CBD0[0] = dword_50CBD0[3] != 0;
          }
          v11 = i->dword_000024;
          if ( v10 < 40 )
          {
            dword_50CBD0[3 * v10 + 1] = i->dword_000020;
            dword_50CBD0[3 * dword_50CBD0[0] + 2] = v11;
            dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
          }
          return;
        }
        continue;
      }
      if ( (signed int)(signed __int64)sqrt((double)((click_x - i->uX) * (click_x - i->uX)
                                                   + (click_y - i->uY) * (click_y - i->uY))) < i->uWidth )
        goto LABEL_50;
      click_y = v13;
      click_x = v12;
    }
  }
}

//----- (00417871) --------------------------------------------------------
int __thiscall sub_417871(int _this)
{
  int result; // eax@5
  char v2; // [sp+0h] [bp-18h]@5
  char v3; // [sp+8h] [bp-10h]@5
  int v4; // [sp+10h] [bp-8h]@3
  int v5; // [sp+14h] [bp-4h]@3

  if ( !pD3DRenderer->pRenderD3D3 )
  {
    if ( _this )
    {
      v5 = *(_DWORD *)_this;
      v4 = *(_DWORD *)(_this + 4);
    }
    else
    {
      class03_GetMouseClickPos(pGame->pClass03, &v5, &v4);
    }
    class03_GetMousePos(pGame->pClass03, (POINT *)&v3);
    result = (int)class03_GetMousePos(pGame->pClass03, (POINT *)&v2);
  }
  return result;
}

//----- (004178C4) --------------------------------------------------------
void __cdecl sub_4178C4()
{
  if ( struct_505898.byte_505992 == 1 )
  {
    if (dword_720010)
      struct_505898.dword_5058A0 = 7;
  }
}

//----- (004178E1) --------------------------------------------------------
void __cdecl sub_4178E1()
{
  if ( struct_505898.byte_505992 == 1 )
  {
    if (dword_720010)
      struct_505898.dword_5058A0 = 8;
  }
}

//----- (004178FE) --------------------------------------------------------
unsigned int __fastcall sub_4178FE_GetColor(signed int a1, signed int a2)
{
  unsigned __int16 v2; // dx@2
  unsigned __int16 v3; // cx@2
  int v5; // eax@5
  unsigned __int16 v6; // [sp-4h] [bp-8h]@2

  if ( a1 <= a2 )
  {
    if ( a1 == a2 )
      return 0;
    v5 = 100 * a1 / a2;
    v3 = 255;
    if ( v5 >= 25 )
    {
      v6 = 100;
      v2 = 255;
    }
    else
    {
      v6 = 0;
      v2 = 0;
    }
  }
  else
  {
    v6 = 0;
    v2 = 255;
    v3 = 0;
  }
  return RGB_MAKE(v3, v2, v6);
}

//----- (00417939) --------------------------------------------------------
signed int __thiscall sub_417939(void *_this)
{
  unsigned int v1; // eax@1
  signed int v2; // edi@1
  unsigned int v3; // esi@1
  void *v4; // ebx@1
  unsigned int v6; // [sp+Ch] [bp-4h]@1

  v4 = _this;
  v2 = 65535;
  v3 = 0xFFE1CD23;
  v6 = 0xFFFF2300;
  v1 = 0xFF00FF00;
  switch ( (unsigned int)(v4) )
  {
    case 0u:
    case 1u:
    case 3u:
    case 4u:
    case 5u:
    case 6u:
    case 7u:
      v2 = v1;
      break;
    case 2:
    case 8u:
    case 9u:
    case 0xCu:
    case 0xDu:
      v2 = v3;
      break;
    case 0xAu:
    case 0xBu:
    case 0xEu:
    case 0xFu:
    case 0x10u:
      v2 = v6;
      break;
    default:
      return v2;
  }
  return v2;
}

//----- (004179BC) --------------------------------------------------------
void sub_4179BC(int a1, const char *a2)
{
  const char *v3; // ebx@1
  int v4; // edi@1
  unsigned int v5; // eax@1

  GUIWindow local_0C;
  //int Dst; // [sp+Ch] [bp-5Ch]@1
  //int v7; // [sp+10h] [bp-58h]@1
  //int v8; // [sp+14h] [bp-54h]@1
  //int v9; // [sp+18h] [bp-50h]@1
  //int v10; // [sp+1Ch] [bp-4Ch]@1
  //int v11; // [sp+20h] [bp-48h]@1

  char v12; // [sp+60h] [bp-8h]@1

  v3 = a2;
  v4 = a1;
  memset(&local_0C, 0, sizeof(GUIWindow));
  local_0C.uFrameWidth = 384;
  local_0C.uFrameHeight = 256;
  local_0C.uFrameX = 128;
  local_0C.uFrameY = *(_DWORD *)(class03_GetMousePos(pGame->pClass03, (POINT *)&v12) + 4) + 30;
  local_0C.uFrameHeight = CalculateTextHeght(pFontSmallnum, v3, &local_0C, 24, 0) + 2 * *(_BYTE *)(pFontLucida + 5) + 24;
  local_0C.uFrameZ = local_0C.uFrameX + local_0C.uFrameWidth - 1;
  local_0C.uFrameW = local_0C.uFrameY + local_0C.uFrameHeight - 1;
  GUIWindow_sub_415551(&local_0C, 0);

  local_0C.uFrameX += 12;
  local_0C.uFrameWidth -= 24;
  local_0C.uFrameY += 12;
  local_0C.uFrameHeight -= 12;
  local_0C.uFrameZ = local_0C.uFrameX + local_0C.uFrameWidth - 1;
  local_0C.uFrameW = local_0C.uFrameY + local_0C.uFrameHeight - 1;
  v5 = 0xFFFFFF9B;
  wsprintfA((char *)TmpBuf, "\x0C%05d%s\x0C\x30\x30\x30\x30\x30", v5, v4);
  GUIWindow_sub_44D406(&local_0C, pFontCreate, 0, 0, 0, (char *)TmpBuf, 3);
  FontDrawText(&local_0C, pFontSmallnum, 1, *(_BYTE *)(pFontLucida + 5), v3, 0, 0, 0);
}

//----- (00417AD4) --------------------------------------------------------
unsigned int __fastcall sub_417AD4(signed int a1, int a2, signed int a3)
{
  int v3; // edx@1
  unsigned int v4; // ecx@1
  int v5; // ebx@1
  signed int v6; // edi@1
  int v7; // eax@7
  unsigned __int8 v8; // sf@10
  unsigned __int8 v9; // of@10
  int v10; // eax@10
  int v11; // eax@11
  int v12; // eax@14
  unsigned int v14; // [sp+Ch] [bp-Ch]@1
  unsigned int v15; // [sp+10h] [bp-8h]@1
  unsigned int v16; // [sp+14h] [bp-4h]@1

  v5 = a2;
  v6 = a1;
  v16 = 0xFFFFFFFF;
  v15 = 0xFFFF0000;
  v14 = 0xFFFFFF00;
  v4 = 0;
  v3 = v6 % 4;
  if ( !(v6 % 4) )
  {
    v11 = 37 * v6 + v5;
    if ( (unsigned __int8)byte_4ED970[v11] >= a3 )
      goto LABEL_8;
    if ( (unsigned __int8)byte_4ED995[v11] < a3 && (unsigned __int8)byte_4ED9BA[v11] < a3 )
    {
      v12 = (unsigned __int8)byte_4ED9DF[v11];
      compile_error;//v9 = __SETO__(v12, a3);
      v8 = v12 - a3 < 0;
LABEL_15:
      v4 = v15;
      if ( v8 ^ v9 )
        return v4;
    }
    return v14;
  }
  if ( v3 == 1 )
  {
    v7 = 37 * v6 + v5;
    if ( (unsigned __int8)byte_4ED970[v7] >= a3 )
      goto LABEL_8;
    if ( (unsigned __int8)byte_4ED995[v7] < a3 )
    {
      v10 = (unsigned __int8)byte_4ED9BA[v7];
      compile_error;//v9 = __SETO__(v10, a3);
      v8 = v10 - a3 < 0;
      goto LABEL_15;
    }
    return v14;
  }
  if ( v3 > 1 && v3 <= 3 )
  {
    if ( (unsigned __int8)*(&byte_4ED970[37 * v6] + v5) < a3 )
      return v15;
LABEL_8:
    v4 = v16;
  }
  return v4;
}

//----- (00417BB5) --------------------------------------------------------
_UNKNOWN *__fastcall sub_417BB5(int a1, int a2)
{
  int v2; // eax@1
  int v3; // ebx@1
  signed int v4; // esi@1
  int v5; // edi@1
  int *v6; // ebx@7
  char v7; // al@7
  char v8; // cl@7
  _UNKNOWN *v9; // esi@8
  unsigned int v10; // eax@8
  unsigned int v11; // eax@8
  unsigned int v12; // eax@8
  int v13; // edi@8
  unsigned int v14; // eax@8
  unsigned int v15; // eax@8
  int v16; // esi@8
  int v17; // edi@8
  char v18; // al@8
  int v19; // ST5C_4@8
  int v20; // ST4C_4@8
  int v21; // ST3C_4@8
  int v22; // ST2C_4@8
  int v23; // ST1C_4@8
  unsigned int v24; // eax@9
  unsigned int v25; // eax@9
  unsigned int v26; // eax@9
  signed int v27; // ecx@9
  int v28; // ebx@9
  unsigned int v29; // eax@9
  char Dest[1200]; // [sp+Ch] [bp-538h]@7
  char Source[120]; // [sp+4BCh] [bp-88h]@7
  int v33; // [sp+534h] [bp-10h]@1
  int v34; // [sp+538h] [bp-Ch]@1
  int v35; // [sp+53Ch] [bp-8h]@1
  int v36; // [sp+540h] [bp-4h]@1

  v4 = a2;
  v3 = a1;
  v36 = a2;
  v5 = GetStringWidth(pFontSmallnum, (char *)pGlobalTXT_LocalizationStrings[431]);
  v34 = GetStringWidth(pFontSmallnum, (char *)pGlobalTXT_LocalizationStrings[433]);
  v33 = GetStringWidth(pFontSmallnum, (char *)pGlobalTXT_LocalizationStrings[432]);
  v2 = GetStringWidth(pFontSmallnum, (char *)pGlobalTXT_LocalizationStrings[96]);
  v35 = v5;
  if ( v34 > v5 )
    v35 = v34;
  if ( v33 > v35 )
    v35 = v33;
  if ( v2 > v35 )
    v35 = v2;
  v6 = (int *)&pParty_global->pPlayers[v3];
  v33 = (int)((char *)v6 + 2 * v4 + 264);
  v7 = Player_sub_48F882(v6, v4);
  v8 = *((_BYTE *)v6 + 2 * v4 + 264);
  Dest[0] = 0;
  Source[0] = 0;
  if ( (v8 & 0x3F) == (v7 & 0x3F) )
  {
    strcpy(Dest, "%s\n\n");
    v24 = sub_417AD4(*((_BYTE *)v6 + 185), v4, 1);
    wsprintfA(Source, "\x0C%05d", v24);
    strcat(Dest, Source);
    strcat(Dest, "%s\t%03d:\t%03d%s\t000\n");
    v25 = sub_417AD4(*((_BYTE *)v6 + 185), v36, 2);
    wsprintfA(Source, "\x0C%05d", v25);
    strcat(Dest, Source);
    strcat(Dest, "%s\t%03d:\t%03d%s\t000\n");
    v26 = sub_417AD4(*((_BYTE *)v6 + 185), v36, 3);
    wsprintfA(Source, "\x0C%05d", v26);
    strcat(Dest, Source);
    strcat(Dest, "%s\t%03d:\t%03d%s\t000\n");
    v27 = *((_BYTE *)v6 + 185);
    v28 = v36;
    v29 = sub_417AD4(v27, v36, 4);
    wsprintfA(Source, "\x0C%05d", v29);
    strcat(Dest, Source);
    strcat(Dest, "%s\t%03d:\t%03d%s\t000\n");
    v9 = &unk_506990;
    wsprintfA(&unk_506990,
      Dest,
      array_5C8A70[v28],
      pGlobalTXT_LocalizationStrings[431],
      v35 + 3,
      v35 + 10,
      array_5C89D8[v28],
      pGlobalTXT_LocalizationStrings[433],
      v35 + 3,
      v35 + 10,
      array_5C8940[v28],
      pGlobalTXT_LocalizationStrings[432],
      v35 + 3,
      v35 + 10,
      array_5C88A8[v28],
      pGlobalTXT_LocalizationStrings[96],
      v35 + 3,
      v35 + 10,
      array_5C8810[v28]);
  }
  else
  {
    strcpy(Dest, "%s\n\n");
    v10 = sub_417AD4(*((_BYTE *)v6 + 185), v4, 1);
    wsprintfA(Source, "\x0C%05d", v10);
    strcat(Dest, Source);
    strcat(Dest, "%s\t%03d:\t%03d%s\t000\n");
    v11 = sub_417AD4(*((_BYTE *)v6 + 185), v36, 2);
    wsprintfA(Source, "\x0C%05d", v11);
    strcat(Dest, Source);
    strcat(Dest, "%s\t%03d:\t%03d%s\t000\n");
    v12 = sub_417AD4(*((_BYTE *)v6 + 185), v36, 3);
    wsprintfA(Source, "\x0C%05d", v12);
    strcat(Dest, Source);
    strcat(Dest, "%s\t%03d:\t%03d%s\t000\n");
    v13 = v36;
    v14 = sub_417AD4(*((_BYTE *)v6 + 185), v36, 4);
    wsprintfA(Source, "\x0C%05d", v14);
    strcat(Dest, Source);
    strcat(Dest, "%s\t%03d:\t%03d%s\t000\n\n");
    v15 = 0xFFFFFFFF;
    wsprintfA(Source, "\x0C%05d", v15);
    strcat(Dest, Source);
    strcat(Dest, "%s: +%d");
    v16 = v13;
    v17 = v35 + 10;
    v16 *= 4;
    v34 = v35 + 3;
    v18 = Player_sub_48F882(v6, v36);
    v19 = (int)array_5C8810[v16 / 4];
    v20 = (int)array_5C88A8[v16 / 4];
    v21 = (int)array_5C8940[v16 / 4];
    v22 = (int)array_5C89D8[v16 / 4];
    v23 = (int)array_5C8A70[v16 / 4];
    v9 = &unk_506990;
    wsprintfA(&unk_506990,
      Dest,
      v23,
      pGlobalTXT_LocalizationStrings[431],
      v34,
      v17,
      v22,
      pGlobalTXT_LocalizationStrings[433],
      v34,
      v17,
      v21,
      pGlobalTXT_LocalizationStrings[432],
      v34,
      v17,
      v20,
      pGlobalTXT_LocalizationStrings[96],
      v34,
      v17,
      v19,
      pGlobalTXT_LocalizationStrings[623],
      (v18 & 0x3F) - (*(_BYTE *)v33 & 0x3F));
  }
  return v9;
}

//----- (00458585) --------------------------------------------------------
unsigned __int16 SpellBuff_sub_458585(struct SpellBuff *_this)
{
  unsigned __int16 result; // ax@1
  int v2; // esi@1

  v2 = (int)_this;
  result = *(_WORD *)(_this + 12);
  *(_DWORD *)_this = 0;
  *(_DWORD *)(_this + 4) = 0;
  *(_WORD *)(_this + 8) = 0;
  *(_WORD *)(_this + 10) = 0;
  *(_BYTE *)(_this + 14) = 0;
  *(_BYTE *)(_this + 15) = 0;
  if ( result )
  {
    //result = sub_45855F((void *)(20 * result + 0x5E4D44));
   result = sub_45855F(array_5E4D58[result - 1]);
    dword_5E5144 = 1;
    *(_WORD *)(v2 + 12) = 0;
  }
  return result;
}

//----- (00419100) --------------------------------------------------------
int __cdecl sub_419100()
{
  int v0; // ebx@1
  int v1; // esi@1
  int v3; // eax@4
  int result; // eax@6
  int v5; // esi@6
  unsigned __int8 v6; // zf@6
  unsigned __int8 v7; // sf@6
  int v8; // edx@7
  int v9; // ecx@7
  unsigned __int8 v10; // sf@7
  unsigned __int8 v11; // of@7
  int v12; // edi@9
  int v13; // edx@11
  int v14; // [sp+Ch] [bp-8h]@2
  signed int v15; // [sp+Ch] [bp-8h]@9
  int i; // [sp+10h] [bp-4h]@10
 struct Player *pPlayer;

  pPlayer = pPlayers[uActiveCharacter - 1];
  memset(&stru_5C3610, 0, sizeof(unnamed_5C3610));
  memset(pStringBuffer, 0, 0x7D0u);
  v0 = 0;
  dword_506544 = 0;
  dword_506548 = 0;
  dword_506520 = 0;
  dword_50651C = 0;
  dword_506528 = 0;

  do
  {
    v14 = dword_723E80[2 * v0];
    if ( (unsigned __int16)sub_449B57((int)pPlayer->array_000152, v0) )
    {
      if ( v14 )
      {
        v3 = dword_506520++;
        stru_5C3610.array_000000[v3] = v0;
      }
    }
    ++v0;
  }
  while ( v0 < 105 );


  result = dword_506520;
  v5 = 0;
  v6 = dword_506520 == 0;
  v7 = dword_506520 < 0;
  dword_506524 = dword_506520;
  dword_506520 = 0;
  if ( !(v7 | v6) )
  {
    do
    {
      v8 = rand() % 16;
      result = dword_506524;
      v9 = dword_506524 + v5++;
      compile_error;//v11 = __SETO__(v5, dword_506524);
      v10 = v5 - dword_506524 < 0;
      stru_5C3610.array_000000[v9] = v8;
    }
    while ( v10 ^ v11 );
    if ( result > 0 )
    {
      v15 = 1;
      v12 = (int)stru_5C3610.array_000000;
      do
      {
        for ( i = v15; i < result; ++i )
        {
          v13 = stru_5C3610.array_000000[i];
          if ( dword_723E84[2 * v13] < dword_723E84[2 * *(_DWORD *)v12] )
          {
            stru_5C3610.array_000000[i] = *(_DWORD *)v12;
            *(_DWORD *)v12 = v13;
          }
        }
        ++v15;
        v12 += 4;
      }
      while ( v15 - 1 < result );
    }
  }
  return result;
}

//----- (00419220) --------------------------------------------------------
void __cdecl sub_419220()
{
  struct GUIButton *pControl;

  if ( !dword_507CBC )
  {
    dword_507CBC = 1;
    for ( pControl = pGUIWindow_CurrentMenu->pControlsHead; pControl; pControl = pControl->pNext)
    {
      if ( pControl->dword_000020 == 120 )
      {
        dword_50698C = pControl->uX;
        dword_506988 = pControl->uY;
        dword_506984 = pControl->uZ;
        dword_506980 = pControl->uW;

        pControl->uX = 0;
        pControl->uY = 0;
        pControl->uZ = 0;
        pControl->uW = 0;
      }
    }
    dword_507B9C = GUIButtonCreate(pGUIWindow_CurrentMenu,
                     438,
                     46,
                     LODFile_Icons_LOD.aLODHeaders[dword_507674].uTextureWidth,//24,
                     LODFile_Icons_LOD.aLODHeaders[dword_507674].uTextureHeight, //26
                     1,
                     0,
                     169,
                     0,
                     0,
                     (unsigned char *)"",
                      &LODFile_Icons_LOD.aLODHeaders[dword_507674]);
    dword_507BA0 = GUIButtonCreate(pGUIWindow_CurrentMenu,
                     438,
                     292,
                     LODFile_Icons_LOD.aLODHeaders[dword_50766C].uTextureWidth,//24,
                     LODFile_Icons_LOD.aLODHeaders[dword_50766C].uTextureHeight, //26
                     1,
                     0,
                     170,
                     0,
                     0,
                     (unsigned char *)"",
                      &LODFile_Icons_LOD.aLODHeaders[dword_50766C]);
    dword_507BA4 = GUIButtonCreate(pGUIWindow_CurrentMenu, 440, 62, 16, 232, 1, 0, 192, 0, 0, (unsigned char *)"", 0);
  }
}

//----- (00419379) --------------------------------------------------------
void __cdecl sub_419379()
{
  struct GUIButton *pControl;

  if ( dword_507CBC )
  {
    dword_507CBC = 0;
    GUIButton_sub_41D0D8(dword_507BA4);
    GUIButton_sub_41D0D8(dword_507B9C);
    GUIButton_sub_41D0D8(dword_507BA0);
    dword_507BA0 = 0;
    dword_507B9C = 0;
    for ( pControl = pGUIWindow_CurrentMenu->pControlsHead; pControl; pControl = pControl->pNext)
    {
      if ( pControl->dword_000020 == 120 )
      {
        pControl->uX = dword_50698C;
        pControl->uY = dword_506988;
        pControl->uZ = dword_506984;
        pControl->uW = dword_506980;
        GUIWindow_sub_41D08F(pGUIWindow_CurrentMenu, 1, 0, 0, 0);
      }
    }
  }
}



//----- (00419401) --------------------------------------------------------
int __cdecl sub_419401()
{
  int v1; // ecx@3
  int result; // eax@8
  int v3; // esi@8
  int v4; // eax@10
  int v5; // esi@14
  int v6; // eax@17
  int v7; // esi@19
  int v8; // eax@21
  int v9; // esi@25
  int v10; // eax@27
  int v11; // [sp+10h] [bp-14h]@1
  int v12; // [sp+14h] [bp-10h]@8
  int v13; // [sp+14h] [bp-10h]@19
  int i; // [sp+18h] [bp-Ch]@8
  char *v18; // [sp+1Ch] [bp-8h]@8
  int v19; // [sp+20h] [bp-4h]@8
  struct GUIButton *pControl;

  v11 = 0;
  if ( dword_507CC0 )
    sub_4196A0();
  v1 = uActiveCharacter;
  dword_507CC0 = uActiveCharacter;
  for ( pControl = pGUIWindow_CurrentMenu->pControlsHead; pControl; pControl = pControl->pNext)
  {
    if ( pControl->dword_000020 == 120 )
    {
      dword_50698C = pControl->uX;
      dword_506988 = pControl->uY;
      dword_506984 = pControl->uZ;
      dword_506980 = pControl->uW;
      pControl->uX = 0;
      pControl->uY = 0;
      pControl->uZ = 0;
      pControl->uW = 0;
      v1 = uActiveCharacter;
    }
  }
  v12 = 0;
  v19 = pGUIWindow_CurrentMenu->uNumControls;
  v18 = (char *)&pParty_global->pPlayers[v1 - 1];
  result = (int)pFontLucida;
  v3 = 2 * pFontLucida->uFontHeight + 13;
  for(i = 0; i < 9; i++)
  {
    if ( v18[2 * dword_4E2A2C[i] + 264] & 0x3F )
    {
      v4 = pFontLucida->uFontHeight;
      v3 = v3 + v4 - 3;
      ++v11;
      ++v12;
      GUIButtonCreate(pGUIWindow_CurrentMenu, 24, v3, 204, v4 - 3, 3, dword_4E2A2C[i] | 0x8000, 121, dword_4E2A2C[i], 0, (unsigned char *)"", 0);
      result = (int)pFontLucida;
    }
  }
  if ( !v12 )
    v3 = v3 + pFontLucida->uFontHeight - 3;
  v5 = v3 + 2 * pFontLucida->uFontHeight - 6;
  for(i = 0; i < 9; i++)
  {
    if ( v18[2 * dword_4E2A80[i] + 264] & 0x3F )
    {
      if ( v11 < 15 )
      {
        v6 = pFontLucida->uFontHeight;
        v5 = v5 + v6 - 3;
        ++v11;
        GUIButtonCreate(pGUIWindow_CurrentMenu, 24, v5, 204, v6 - 3, 3, dword_4E2A80[i] | 0x8000, 121, dword_4E2A80[i], 0, (unsigned char *)"", 0);
        result = (int)pFontLucida;
      }
    }
  }

  v13 = 0;
  v7 = 2 * pFontLucida->uFontHeight + 13;
  for(i = 0; i < 5; i++) 
  {
    if ( v18[2 * dword_4E2A18[i] + 264] & 0x3F )
    {
      v8 = pFontLucida->uFontHeight;
      v7 = v7 + v8 - 3;
      ++v11;
      ++v13;
      GUIButtonCreate(pGUIWindow_CurrentMenu, 246, v7, 204, v8 - 3, 3, dword_4E2A18[i] | 0x8000, 121, dword_4E2A18[i], 0, (unsigned char *)"", 0);
      result = (int)pFontLucida;
    }
  }
  if ( !v13 )
    v7 = v7 + pFontLucida->uFontHeight - 3;
  v9 = v7 + 2 * pFontLucida->uFontHeight - 6;
  for(i = 0; i < 12; i++) 
  {
    if ( v18[2 * dword_4E2A50[i] + 264] & 0x3F )
    {
      v10 = pFontLucida->uFontHeight;
      v9 = v9 + v10 - 3;
      ++v11;
      GUIButtonCreate(pGUIWindow_CurrentMenu, 246, v9, 204, v10 - 3, 3, dword_4E2A50[i] | 0x8000, 121, dword_4E2A50[i], 0, (unsigned char *)"", 0);
      result = (int)pFontLucida;
    }
  }
  if ( v11 )
    result = GUIWindow_sub_41D08F(pGUIWindow_CurrentMenu, v11, 1, 0, v19);
  return result;
}

//----- (004196A0) --------------------------------------------------------
void __cdecl sub_4196A0()
{
  struct GUIButton *pControl;

  if ( dword_507CC0 )
  {
    dword_507CC0 = 0;
    for ( pControl = pGUIWindow_CurrentMenu->pControlsHead; pControl; pControl = pControl->pNext)
    {
      if ( *(_BYTE *)((char *)pControl + 29) & 0x80 )
        GUIButton_sub_41D0D8(pControl);
    }
    for ( pControl = pGUIWindow_CurrentMenu->pControlsHead; pControl; pControl = pControl->pNext)
    {
      if ( pControl->dword_000020 == 120 )
      {
        pControl->uX = dword_50698C;
        pControl->uY = dword_506988;
        pControl->uZ = dword_506984;
        pControl->uW = dword_506980;
        GUIWindow_sub_41D08F(pGUIWindow_CurrentMenu, 1, 0, 0, 0);
      }
    }
  }
}

//----- (004948B1) --------------------------------------------------------
__int16 __thiscall Player_PlaySound(struct Player *_this, int a2, int a3)
{
  void *v3; // edi@1
  int v4; // eax@4
  int v5; // ebx@4
  signed int v6; // esi@4
  signed int v7; // ecx@5
  unsigned __int8 v8; // al@6
  int v9; // eax@10
  int v10; // ecx@10
  int v11; // esi@10
  signed int v12; // eax@11
  int v13; // eax@12
  signed int v14; // esi@12
  int v15; // eax@17
  int v16; // ebx@17
  int v17; // ecx@19
  int v18; // edi@20
  int v20[5]; // [sp+Ch] [bp-1Ch]@7
  int v21; // [sp+20h] [bp-8h]@1
  int v22; // [sp+24h] [bp-4h]@1
  int v23; // [sp+30h] [bp+8h]@4

  v3 = _this;
  v21 = (int)_this;
  v22 = 1;
  do
  {
    if (_this == pPlayers[v22 - 1])
      break;
    ++v22;
  }
  while ( v22 <= 4 );

  v4 = a2;
  v6 = 0;
  v23 = 0;
  v5 = (int)byte_4ED3D8 + 8 * v4; // + 5166040;
  if ( uVoicesVolumeMultiplier )
  {
    v7 = 0;
    do
    {
      v8 = *(_BYTE *)(v5 + v7);
      if ( v8 )
        v20[v6++] = v8;
      ++v7;
    }
    while ( v7 < 2 );
    if ( v6 )
    {
      v9 = rand();
      v10 = _this->dword_001920;
      v11 = v20[v9 % v6];
      if ( *(&byte_4ECEEF[25 * v11] + v10) )
      {
        v23 = rand() % (unsigned __int8)*(&byte_4ECEEF[25 * v11] + v10)
            + 2 * (v11 + 50 * *(_DWORD *)(v21 + 6432))
            + 4998;
        v12 = 8 * v22 + 312;
        LOBYTE(v12) = v12 | 4;
        AudioPlayer_sub_4AA306(pAudioPlayer, v23, v12, 0, -1, 0, 0, (signed __int64)(aMusicVolumeLevels[uVoicesVolumeMultiplier] * 128.0), 0);
      }
    }
  }
  v14 = 0;
  v13 = v5 + 3;
  do
  {
    if ( *(_BYTE *)v13 )
      v20[v14++] = *(_BYTE *)v13;
    ++v13;
  }
  while ( -3 - v5 + v13 < 5 );
  if ( v14 )
  {
    v15 = rand();
    v22 = 0;
    v16 = v20[v15 % v14];
    if ( v16 == 21 && v23 )
    {
      v17 = 0;
      if ( pSoundList->uNumSounds <= 0 )
      {
LABEL_23:
        v17 = 0;
      }
      else
      {
        v18 = (int)pSoundList->pDescriptions + 32;
        while ( *(_DWORD *)v18 != v23 )
        {
          ++v17;
          v18 += 120;
          if ( v17 >= pSoundList->uNumSounds )
            goto LABEL_23;
        }
      }
      if ( *(_DWORD *)(120 * v17 + pSoundList->pDescriptions + 44) )
        v22 = (dword_F1B4D4 << 7) / 1000;
    }
    LOWORD(v13) = Player_sub_494A25(v21, v16, v22);
  }
  return v13;
}

//----- (0041A2C1) --------------------------------------------------------
int __fastcall GetSizeInInventorySlots(unsigned int uNumPixels)
{
  if ( uNumPixels < 14 )
    uNumPixels = 14;
  return ((uNumPixels - 14) >> 5) + 1;
}

//----- (0041A556) --------------------------------------------------------
void __cdecl sub_41A556()
{
  Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (cTexture *)(uTextureIdx_Leather != -1 ? 72 * uTextureIdx_Leather + 7145548 : 0));
}

//----- (0041A57E) --------------------------------------------------------
void __cdecl sub_41A57E()
{
  int v0; // ebx@1
  int v1; // eax@1
  int v2; // ebp@2
  int v3; // eax@6
  int v4; // edi@6
  __int16 v5; // ax@7
  int v6; // edi@9
  int v7; // edi@11
  int v8; // edi@13
  signed int v9; // eax@13
  __int16 v10; // ax@13
  int v11; // edi@15
  int v12; // eax@15
  __int16 v13; // ax@15
  int v14; // edi@17
  int v15; // eax@17
  int v16; // ST18_4@17
  int v17; // ebx@17
  int v18; // eax@17
  __int16 v19; // ax@17
  int v20; // edi@19
  int v21; // eax@19
  int v22; // edi@21
  char *v23; // eax@21
  int v24; // edi@23
  int v25; // eax@23
  int v26; // edi@25
  char *v27; // eax@25
  int v28; // eax@27
  signed int v29; // edx@27
  int v30; // ecx@27
  int v31; // edi@31
  int v32; // edi@33
  int v33; // edi@35
  const char *v34; // ST10_4@35
  __int16 v35; // ax@35
  unsigned __int8 v36; // al@37
  const char *v37; // eax@38
  int v38; // eax@41
  signed int v39; // edi@42
  int v41; // eax@45
  int v42; // eax@45
  signed int v43; // [sp+10h] [bp-1Ch]@1
  signed int v44; // [sp+14h] [bp-18h]@2
  int v45; // [sp+18h] [bp-14h]@1
  unsigned int v46; // [sp+1Ch] [bp-10h]@1
  __int16 v47; // [sp+20h] [bp-Ch]@1
  int v48; // [sp+24h] [bp-8h]@33
  unsigned int v49; // [sp+28h] [bp-4h]@1

  v0 = 0;
  v47 = 0xFFFFFF9B;
  v49 = 0xFFFF0000;
  v46 = 0xFF00FF00;
  #ifndef OLD_CODE
	 v1 = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"quikref");
#endif
#ifdef OLD_CODE
	v1 = LODFile_Icons_LOD.LODFile_LoadTexture("quikref",2);
#endif
  
  Render_DrawIndexedTextureHandle(pD3DRenderer, 8, 8, v1);
  v43 = 0;
  v45 = *(_BYTE *)(pFontArrus + 5) + 1;
  do
  {
    v2 = (int)&pParty_global->pPlayers[v43];
    v44 = 94 * v43 + 89;
    if ( v43 == v0 )
      GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, 22, 18, v0, (char *)pGlobalTXT_LocalizationStrings[149], 60, v0);
    GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, 94 * v43 + 89, 18, v47, (const char *)(v2 + 168), 84, v0);
    if ( v43 == v0 )
      GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, 22, 47, v0, (char *)pGlobalTXT_LocalizationStrings[131], 60, v0);
    v3 = Player_GetActualLevel((Player *)v2);
    wsprintfA((char *)TmpBuf, "%lu", v3);
    v4 = Player_GetBaseLevel((Player *)v2);
    if ( Player_GetActualLevel((Player *)v2) <= v4 )
      v5 = Player_sub_48D498(v2);
    else
      v5 = 0xFF00FF00 | (unsigned char)v0;
    GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, v44, 47, v5, (char *)TmpBuf, 84, v0);
    v6 = v45 + 47;
    if ( v43 == v0 )
      GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, 22, v45 + 47, v0, (char *)pGlobalTXT_LocalizationStrings[41], 60, v0);
    //GUIWindow_sub_44CB4F(pGUIWindow_CurrentMenu, pFontArrus, v44, v6, v0, (&dword_AE31F0)[4 * *(_BYTE *)(v2 + 185)], 84, v0);
    GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, v44, v6, v0, (char *)aClassNames[*(_BYTE *)(v2 + 185)], 84, v0);

    v7 = v45 + v6;
    if ( v43 == v0 )
      GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, 22, v7, v0, (char *)pGlobalTXT_LocalizationStrings[107], 60, v0);
    wsprintfA((char *)TmpBuf, "%d", *(_DWORD *)(v2 + 6460));
    v9 = Player_GetMaxHealth((Player *)v2);
    v10 = sub_4178FE_GetColor(*(_DWORD *)(v2 + 6460), v9);
    GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, v44, v7, v10, (char *)TmpBuf, 84, v0);
    v8 = v45 + v7;
    if ( v43 == v0 )
      GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, 22, v8, v0, (char *)pGlobalTXT_LocalizationStrings[209], 60, v0);
    wsprintfA((char *)TmpBuf, "%d", *(_DWORD *)(v2 + 6464));
    v12 = Player_GetMaxMana((Player *)v2);
    v13 = sub_4178FE_GetColor(*(_DWORD *)(v2 + 6464), v12);
    GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, v44, v8, v13, (char *)TmpBuf, 84, v0);
    v11 = v45 + v8;
    if ( v43 == v0 )
      GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, 22, v11, v0, (char *)pGlobalTXT_LocalizationStrings, 60, v0);
    v15 = Player_sub_48E68F(v2);
    wsprintfA((char *)TmpBuf, "%d", v15);
    v16 = v0;
    v17 = Player_sub_48E656(v2);
    v18 = Player_sub_48E68F(v2);
    v19 = sub_4178FE_GetColor(v18, v17);
    GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, v44, v11, v19, (char *)TmpBuf, 84, v16);
    v0 = 0;
    v14 = v45 + v11;
    if ( !v43 )
      GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, 22, v14, 0, (char *)pGlobalTXT_LocalizationStrings[18], 60, 0);
    v21 = sub_48CCF5(v2, 0);
    wsprintfA((char *)TmpBuf, (const char *)&off_4E3044, v21);
    GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, v44, v14, 0, (char *)TmpBuf, 84, 0);
    v20 = v45 + v14;
    if ( !v43 )
      GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, 22, v20, 0, (char *)pGlobalTXT_LocalizationStrings[66], 60, 0);
    v23 = sub_48D2EA(v2);
    GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, v44, v20, 0, v23, 84, 0);
    v22 = v45 + v20;
    if ( !v43 )
      GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, 22, v22, 0, (char *)pGlobalTXT_LocalizationStrings[203], 60, 0);
    v25 = Player_sub_48D0B9(v2);
    wsprintfA((char *)TmpBuf, (const char *)&off_4E3044, v25);
    GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, v44, v22, 0, (char *)TmpBuf, 84, 0);
    v24 = v45 + v22;
    if ( !v43 )
      GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, 22, v24, 0, (char *)pGlobalTXT_LocalizationStrings[66], 60, 0);
    v27 = Player_sub_48D396(v2);
    GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, v44, v24, 0, v27, 84, 0);
    v26 = v45 + v24;
    if ( !v43 )
      GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, 22, v26, 0, (char *)pGlobalTXT_LocalizationStrings[205], 60, 0);
    v30 = 0;
    v28 = v2 + 264;
    v29 = 36;
    do
    {
      if ( *(_WORD *)v28 )
        ++v30;
      v28 += 2;
      --v29;
    }
    while ( v29 );
    wsprintfA((char *)TmpBuf, "%lu", v30);
    GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, v44, v26, 0, (char *)TmpBuf, 84, 0);
    v31 = v45 + v26;
    if ( !v43 )
      GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, 22, v31, 0, (char *)pGlobalTXT_LocalizationStrings[168], 60, 0);
    wsprintfA((char *)TmpBuf, "%lu", *(_DWORD *)(v2 + 6456));
    GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, v44, v31, *(_DWORD *)(v2 + 6456) != 0 ? v46 : 0, (char *)TmpBuf, 84, 0);
    v32 = v45 + v31;
    v48 = Player_GetConditionIdx((Player *)v2);
    if ( !v43 )
      GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, 22, v32, 0, (char *)pGlobalTXT_LocalizationStrings[45], 60, 0);
    //v34 = (&dword_AE3280)[4 * v48];
    v34 = (char *)aCharacterConditionNames[v48];

    v35 = sub_417939((void *)v48);
    GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, v44, v32, v35, v34, 84, 0);
    v33 = v45 + v32;
    if ( !v43 )
      GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, 22, v33, 0, (char *)pGlobalTXT_LocalizationStrings[170], 60, 0);
    v36 = *(_BYTE *)(v2 + 6735);
    if ( v36 )
      //v37 = (&dword_5CC034)[36 * v36];
      v37 = (char *)pSpellStats->pSpellInfos[v36].pSpellNameShort;
    else
      v37 = (char *)pGlobalTXT_LocalizationStrings[153];
    GUIWindow_sub_44CB4F((int)pGUIWindow_CurrentMenu, (int)pFontArrus, v44, v33, 0, v37, 84, 0);
    ++v43;
  }
  while ( v43 < 4 );
  v38 = sub_47752B();
  if ( v38 >= 0 )
  {
    v39 = v49;
    if ( v38 <= 5 )
      v39 = 65535;
  }
  else
  {
    v39 = v46;
  }
  v41 = sub_495430(v38);

  wsprintfA((char *)TmpBuf, "%s: \x0C%05d%s\x0C\x30\x30\x30\x30\x30", pGlobalTXT_LocalizationStrings[180], v39, v41);

  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 22, 323, (char *)TmpBuf, 0, 0, 0);
  v42 = Party_sub_49135E_GetAllPartyExpDiv1000(pParty_global);
  wsprintfA((char *)TmpBuf, "\r261%s: %d", pGlobalTXT_LocalizationStrings[84], v42);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 0, 323, (char *)TmpBuf, 0, 0, 0);
}

//----- (0041AF52) --------------------------------------------------------
void __fastcall sub_41AF52(int a1, int a2)
{
  signed int v2; // eax@1
  int v3; // edi@1
  signed int v4; // esi@1
  signed int v5; // ebx@4
  double v6; // st7@5
  int v7; // eax@6
  int v8; // ebx@10
  int v9; // [sp+14h] [bp-Ch]@4
  signed int v10; // [sp+1Ch] [bp-4h]@4

  v2 = *(_DWORD *)(a1 + 108);
  v3 = a2;
  v4 = 25;
  if ( v2 > 25 )
  {
    v4 = 200;
    if ( v2 < 200 )
      v4 = *(_DWORD *)(a1 + 108);
  }
  v5 = *(_WORD *)(a1 + 40);
  v10 = v4;
  v9 = uTextureIdx_MonsterHP_BarGreen;
  if ( v5 < v2 )
  {
    v6 = (double)v2;
    v10 = (signed __int64)((double)v4 / (double)v2 * (double)*(_WORD *)(a1 + 40));
    if ( v5 <= (signed int)(signed __int64)(0.34000000000000002 * v6) )
    {
      v7 = uTextureIdx_MonsterHP_BarRed;
LABEL_9:
      v9 = v7;
      goto LABEL_10;
    }
    if ( v5 <= (signed int)(signed __int64)(v6 * 0.67000000000000004) )
    {
      v7 = uTextureIdx_MonsterHP_BarYellow;
      goto LABEL_9;
    }
  }
LABEL_10:
  v8 = *(_DWORD *)a2 + (*(_DWORD *)(a2 + 8) - v4) / 2;
  Render_Set2DClippingRect(pD3DRenderer, v8, *(_DWORD *)(a2 + 4) + 32, v8 + v4, *(_DWORD *)(a2 + 4) + 52);
  Render_DrawIndexedTexture(pD3DRenderer, v8, *(_DWORD *)(v3 + 4) + 32, &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_MonsterHP_Bg]);
  Render_Set2DClippingRect(pD3DRenderer, v8, *(_DWORD *)(v3 + 4) + 32, v8 + v10, *(_DWORD *)(v3 + 4) + 52);
  Render_DrawIndexedTexture(pD3DRenderer, v8, *(_DWORD *)(v3 + 4) + 34, &LODFile_Icons_LOD.aLODHeaders[v9]);
  Render_Reset2DClippingRect(pD3DRenderer);
  Render_DrawIndexedTexture(pD3DRenderer, v8 - 5, *(_DWORD *)(v3 + 4) + 32, &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_MonsterHP_CapLeft]);
  Render_DrawIndexedTexture(pD3DRenderer, v8 + v4, *(_DWORD *)(v3 + 4) + 32, &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_MonsterHP_CapRight]);
}

//----- (004763E0) --------------------------------------------------------
void __cdecl InitializeAwards()
{
  char *result; // eax@4
  char v2; // dl@5
  char *v3; // ecx@5
  int v4; // esi@9
  signed int v5; // [sp+Ch] [bp-Ch]@4
  char *v6; // [sp+10h] [bp-8h]@4
  signed int v7; // [sp+14h] [bp-4h]@3

 if (pAwardsTXT_Raw)
   mem_mng.DeleteBuffer( (void *)pAwardsTXT_Raw);

 pAwardsTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "awards.txt", 0);
 strtok((char *)pAwardsTXT_Raw, "\r");

 //v7 = (signed int)&unk_723E88;
 v7 = 0;
  do
  {
    result = strtok(0, "\r") + 1;
    v6 = 0;
    v5 = 0;
    do
    {
      v2 = *result;
      v3 = 0;
      if ( *result != 9 )
      {
        do
        {
          if ( !v2 )
            break;
          ++v3;
          v2 = *(_BYTE *)((_DWORD)v3 + (_DWORD)result);
        }
        while ( v2 != 9 );
      }
      v4 = (_DWORD)v3 + (_DWORD)result;
      if ( *(_BYTE *)((_DWORD)v3 + (_DWORD)result) == 0)
        v5 = 1;
      *(_BYTE *)v4 = 0;
      if ( v3 == 0)
      {
        v5 = 1;
      }
      else
      {
        if ( v6 == (char *)1 )
        {
          *(_DWORD *)(unk_723E88 + v7) = (int)RemoveQuote(result);
        }
        else
        {
          if ( v6 == (char *)2 )
            *(_DWORD *)(unk_723E88 + v7 + 4) = atoi(result);
        }
      }
      ++v6;
      result = (char *)(v4 + 1);
    }
    while ( (signed int)(v6 - 1) <= 2 && !v5);
    v7 += 8;
  }
  //while ( v7 < (signed int)&dword_7241C8 );
  while (v7 < 0x340);
}

//----- (0041B3B6) --------------------------------------------------------
void __cdecl sub_41B3B6() // draw hud
{
  Render_DrawTransparentTexture(pD3DRenderer, pOldViewport->uGameZ, 0, &LODFile_Icons_LOD.aLODHeaders[uTextureID_5079E4]);
}

//----- (0041B438) --------------------------------------------------------
int __fastcall sub_41B438(unsigned __int8 a1)
{
  char v1; // dl@1
  int v2; // esi@1
  int result; // eax@2
  int *v4; // ecx@2
  int v5; // edx@12

  v2 = sLastGUIWindowIdx;
  v1 = toupper(a1);
  if ( sLastGUIWindowIdx >= 0 )
  {
    while ( 2 )
    {
      v4 = (int *)&GUIWindow_List[array_5075E0[v2] - 1];
      for ( result = v4[19]; result; result = *(_DWORD *)(result + 52) )
      {
        if ( *(_BYTE *)(result + 84) == v1 )
        {
          v5 = *(_DWORD *)(result + 36);
          if ( dword_50CBD0[0] < 40 )
          {
            dword_50CBD0[3 * dword_50CBD0[0] + 1] = *(_DWORD *)(result + 32);
            dword_50CBD0[3 * dword_50CBD0[0] + 2] = v5;
            dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
          }
          return result;
        }
      }
      if ( *v4 || v4[1] != result || !(v4[2] == 640 & v4[3] == 480) )
      {
        --v2;
        if ( v2 >= 0 )
          continue;
      }
      break;
    }
  }
  return 0;
}

//----- (0041B4E1) --------------------------------------------------------
int __fastcall sub_41B4E1(unsigned __int8 a1, unsigned __int8 a2, char a3)
{
  int result; // eax@1
  unsigned __int8 v4; // bl@1
  int i; // edx@2
  int j; // ecx@3
  int k; // edx@7
  int l; // ecx@8
  char v9; // [sp+4h] [bp-8h]@1
  char v10; // [sp+8h] [bp-4h]@1

  v4 = a2;
  v10 = toupper(a1);
  result = toupper(v4);
  v9 = result;
  if ( a3 )
  {
    for ( i = sLastGUIWindowIdx; i >= 0; --i )
    {
      result = 84 * array_5075E0[i];
      for ( j = *(int *)((char *)&dword_506F48 + result); j; j = *(_DWORD *)(j + 52) )
        *(_DWORD *)(j + 40) = 0;
    }
  }
  for ( k = sLastGUIWindowIdx; k >= 0; --k )
  {
    result = 84 * array_5075E0[k];
    for ( l = *(int *)((char *)&dword_506F48 + result); l; l = *(_DWORD *)(l + 52) )
    {
      LOBYTE(result) = v10;
      if ( *(_BYTE *)(l + 84) == v10 )
      {
        if ( !*(_DWORD *)(l + 40) )
        {
          LOBYTE(result) = v9;
          *(_DWORD *)(l + 40) = 1;
          *(_BYTE *)(l + 84) = v9;
        }
      }
    }
  }
  return result;
}

//----- (0041B578) --------------------------------------------------------
int __cdecl MenuUI_LoadFontsAndSomeStuff()
{
  signed int v3; // edx@3
 int i;

 LODFile_Icons_LOD.SetupPalettes(5,6,5); //pD3DRenderer->uNumTargetRBits, pD3DRenderer->uNumTargetGBits, pD3DRenderer->uNumTargetBBits);
 class35_SetColorChannelInfo(&class35_obj, pD3DRenderer->uNumTargetRBits, pD3DRenderer->uNumTargetGBits, pD3DRenderer->uNumTargetBBits);
 class35_sub_48A614(&class35_obj);

 for (i = 0; i < 480; ++i)
   dword_5059A8[i] = i * 640;


 Render_Reset2DClippingRect(pD3DRenderer);

 dword_507988 = LODFile_Icons_LOD.LODFile_LoadTexture( "FONTPAL", 2);

 pFontArrus = LoadFont("arrus.fnt", "FONTPAL");
 pFontArrus->byte_000002[0] = 0;

 pFontLucida = LoadFont("lucida.fnt", "FONTPAL");
 pFontLucida->byte_000002[0] = 0;

 pFontCreate = LoadFont("create.fnt", "FONTPAL");
 pFontCreate->byte_000002[0] = 0;

 pFontComic = LoadFont("comic.fnt", "FONTPAL");
 pFontSmallnum = LoadFont("smallnum.fnt", "FONTPAL");

 sLastGUIWindowIdx = -1;
 memset(array_5075E0, 0, 20 * sizeof(int));
 for (i = 0; i < 20; ++i)
   GUIWindow_List[i].bSlotUsed = false;

 return 0;
}


//----- (0041C047) --------------------------------------------------------
void __cdecl sub_41C047()
{
  char *v0; // eax@1
  const char *v1; // edx@2
  char *v2; // ST18_4@5
  const char *v3; // ST0C_4@5
  __int16 v4; // ST08_2@5
  int v5; // eax@5
#ifndef	OLD_CODE
  //Render_DrawRGBTexture(pD3DRenderer, 0, 352, pTexture_StatusBar);
  Render_DrawRGBTexture_New(pD3DRenderer, 0, 352, uTextureID_GameUI_StatusBar);
#endif
#ifdef	OLD_CODE
  Render_DrawRGBTexture(pD3DRenderer, 0, 352, &cPCXID_GameUI_StatusBar);

#endif
  if ( dword_5C35B8 )
  {
    v1 = (char *)&byte_5C3428;
  }
  else
  {
    if ( !pStatusBarString[0] )
      return;
    v1 = (char *)pStatusBarString;
  }
  LOWORD(v0) = dword_507AF8;
  v2 = v0;
  v3 = v1;
  v4 = dword_507AFC;//colored or white text flag
  v5 = AlignText_Center(450, v1, pFontLucida);
  FontDrawText(pGUIWindow0, pFontLucida, v5 + 11, 357, v3, 0, 0, (unsigned int)v2);
}

//----- (0041C0B8) --------------------------------------------------------
void __thiscall sub_41C0B8(const char *Str1)
{
  const char *v1; // esi@1
  int i; // eax@7
  int j; // eax@11

  v1 = Str1;
  if ( Str1 )
  {
    if ( strcmp(Str1, "test") )
    {
      if ( !IsBadStringPtrA(v1, 1u) )
      {
        if ( *v1 || dword_5C35B8 )
        {
          if ( dword_5C35B8 )
          {
            for ( i = GetStringWidth(pFontLucida, (char *)&byte_5C3428); i > 450; i = GetStringWidth(pFontLucida, (char *)&byte_5C3428) )
              byte_5C3427[strlen((char *)&byte_5C3428)] = 0;
          }
          else
          {
            strcpy((char *)pStatusBarString, v1);
            for ( j = GetStringWidth(pFontLucida, (char *)pStatusBarString); j > 450; j = GetStringWidth(pFontLucida, (char *)pStatusBarString) )
              pStatusBarString[strlen((char *)pStatusBarString) - 1] = 0;
          }
        }
      }
    }
  }
}

//----- (0041CD4F) --------------------------------------------------------
signed int __thiscall sub_41CD4F_MaybeOnlyUI_OnKeyDown(unsigned char Key)
{
  signed int v1; // edi@1
  int v2; // eax@2
  int wndIdx; // esi@3
  int v4; // ecx@10
  struct GUIButton *v5; // eax@11
  int v6; // edx@12
  int v7; // ecx@20
  char v8; // zf@21
  struct GUIButton *v9; // ecx@24
  signed int v10; // esi@24
  int v11; // edx@26
  int v12; // edx@28
  char v13; // zf@29
  signed int v14; // esi@32
  struct GUIButton *v15; // eax@37
  int v16; // edx@38
  char v17; // sf@47
  int v19; // edx@50
  int v20; // ecx@50
  struct GUIButton *v21; // ecx@54
  signed int v22; // esi@54
  int v23; // edx@56
  int v24; // edx@59
  int v25; // ecx@59
  int v26; // ecx@60
  char v27; // zf@62
  signed int v28; // esi@63
  void *v29; // [sp+Ch] [bp-14h]@1
  int v30; // [sp+10h] [bp-10h]@1
  int v31; // [sp+14h] [bp-Ch]@10
  int v32; // [sp+14h] [bp-Ch]@36
  int v33; // [sp+18h] [bp-8h]@10
  int v34; // [sp+1Ch] [bp-4h]@10

  v1 = 0;
  v30 = sLastGUIWindowIdx;
  if ( sLastGUIWindowIdx < 0 )
    return 0;
  v2 = dword_50CBD0[0];
  while ( 1 )
  {
    wndIdx = array_5075E0[v30] - 1;
    //if ( *(int *)((char *)array_506F68 + 44 + v3) == v1 )
    if (GUIWindow_List[wndIdx].dword_000044 == v1)
      goto LABEL_47;
    if ( Key != VK_NEXT )
      break;
    //if ( *(int *)((char *)array_506F68 + 24 + v3) != v1 )
    if (GUIWindow_List[wndIdx].dword_000030 != v1)
    {
      class03_GetMouseClickPos(pGame->pClass03, &v33, &v34);
      //v4 = *(int *)((char *)array_506F68 + 32 + v3);
      v4 = GUIWindow_List[wndIdx].dword_000038;
      //v32 = v4 + *(int *)((char *)array_506F68 + 16 + v3);
      v32 = v4 + GUIWindow_List[wndIdx].dword_000028;
      //if ( v4 < v4 + *(int *)((char *)array_506F68 + 16 + v3) )
      if (v4 < v4 + GUIWindow_List[wndIdx].dword_000028)
      {
        while ( 1 )
        {
          //v15 = *(int *)((char *)array_506F68 + 52 + v3);
         v15 = GUIWindow_List[wndIdx].pControlsHead;
          if ( v4 > 0 )
          {
            v16 = v4;
            do
            {
              v15 = v15->pNext;
              --v16;
            }
            while ( v16 );
          }
          if ( v33 >= *(_DWORD *)v15
            && v33 <= *(_DWORD *)((char*)v15 + 16)
            && v34 >= *(_DWORD *)((char*)v15 + 4)
            && v34 <= *(_DWORD *)((char*)v15 + 20) )
            goto LABEL_66;
          ++v4;
          if ( v4 >= v32 )
          {
LABEL_45:
            v1 = 0;
            goto LABEL_46;
          }
        }
      }
      goto LABEL_46;
    }
LABEL_47:
    v17 = v30-- - 1 < 0;
    if ( v17 )
      return 0;
  }
  if ( Key == VK_LEFT )
  {
    //v12 = *(int *)((char *)array_506F68 + 28 + v3);
   v12 = GUIWindow_List[wndIdx].dword_000034;
    //if ( *(int *)((char *)array_506F68 + 20 + v3) - *(int *)((char *)array_506F68 + 32 + v3) - v12 >= 0 )
   if (GUIWindow_List[wndIdx].dword_00002C - GUIWindow_List[wndIdx].dword_000038 - v12 >= 0)
    {
      v13 = dword_4E28F8 == 21;
      //*(int *)((char *)array_506F68 + 20 + v3) -= v12;
      GUIWindow_List[wndIdx].dword_00002C -= v12;
      if ( v13 )
      {
        AudioPlayer_sub_4AA306(pAudioPlayer, 66, v1, v1, -1, v1, v1, v1, v1);
        v2 = dword_50CBD0[0];
      }
    }
    //if ( *(int *)((char *)array_506F68 + 24 + v3) != v1 )
   if (GUIWindow_List[wndIdx].dword_000030 != v1)
      goto LABEL_47;
    //v9 = *(int *)((char *)array_506F68 + 52 + v3);
    //v14 = *(int *)((char *)array_506F68 + 20 + v3);
   v9 = GUIWindow_List[wndIdx].pControlsHead;
   v14 = GUIWindow_List[wndIdx].dword_00002C;
    if ( v14 > v1 )
    {
      do
      {
        v9 = v9->pNext;
        --v14;
      }
      while ( v14 );
    }
LABEL_26:
    v11 = *(_DWORD *)((char*)v9 + 36);
    if ( v2 < 40 )
    {
      dword_50CBD0[3 * v2 + 1] = *(_DWORD *)((char*)v9 + 32);
      dword_50CBD0[3 * dword_50CBD0[0] + 2] = v11;
      dword_50CBD0[3 * dword_50CBD0[0] + 3] = v1;
      v2 = dword_50CBD0[0]++ + 1;
    }
    goto LABEL_47;
  }
  if ( Key != VK_UP )
  {
    if ( Key == VK_RIGHT )
    {
      //v7 = *(int *)((char *)array_506F68 + 20 + v3) + *(int *)((char *)array_506F68 + 28 + v3);
     v7 = GUIWindow_List[wndIdx].dword_00002C + GUIWindow_List[wndIdx].dword_000034;
      //if ( v7 < *(int *)((char *)array_506F68 + 16 + v3) + *(int *)((char *)array_506F68 + 32 + v3) )
     if (v7 < GUIWindow_List[wndIdx].dword_000028 + GUIWindow_List[wndIdx].dword_000038)
      {
        v8 = dword_4E28F8 == 21;
        //*(int *)((char *)array_506F68 + 20 + v3) = v7;
        GUIWindow_List[wndIdx].dword_00002C = v7;
        if ( v8 )
        {
          AudioPlayer_sub_4AA306(pAudioPlayer, 66, v1, v1, -1, v1, v1, v1, v1);
          v2 = dword_50CBD0[0];
        }
      }
      //if ( *(int *)((char *)array_506F68 + 24 + v3) != v1 )
     if (GUIWindow_List[wndIdx].dword_000030 != v1)
        goto LABEL_47;
      //v9 = *(int *)((char *)array_506F68 + 52 + v3);
      //v10 = *(int *)((char *)array_506F68 + 20 + v3);
     v9 = GUIWindow_List[wndIdx].pControlsHead;
     v10 = GUIWindow_List[wndIdx].dword_00002C;
      if ( v10 > v1 )
      {
        do
        {
          v9 = v9->pNext;
          --v10;
        }
        while ( v10 );
      }
      goto LABEL_26;
    }
    if ( Key == VK_DOWN )
    {
      //v20 = *(int *)((char *)array_506F68 + 32 + v3);
      //v19 = *(int *)((char *)array_506F68 + 20 + v3);
     v19 = GUIWindow_List[wndIdx].dword_00002C;
     v20 = GUIWindow_List[wndIdx].dword_000038;
      //if ( v19 >= *(int *)((char *)array_506F68 + 16 + v3) + v20 - 1 )
     if (v19 >= GUIWindow_List[wndIdx].dword_000028 + v20 - 1)
        //*(int *)((char *)array_506F68 + 20 + v3) = v20;
        GUIWindow_List[wndIdx].dword_00002C = v20;
      else
        //*(int *)((char *)array_506F68 + 20 + v3) = v19 + 1;
        GUIWindow_List[wndIdx].dword_00002C = v19 + 1;

      //if ( *(int *)((char *)array_506F68 + 24 + v3) == v1 )
     if (GUIWindow_List[wndIdx].dword_000030 == v1)
      {
        //v21 = *(int *)((char *)array_506F68 + 52 + v3);
        //v22 = *(int *)((char *)array_506F68 + 20 + v3);
       v21 = GUIWindow_List[wndIdx].pControlsHead;
       v22 = GUIWindow_List[wndIdx].dword_00002C;
        if ( v22 > v1 )
        {
          do
          {
            v21 = v21->pNext;
            --v22;
          }
          while ( v22 );
        }
LABEL_56:
        v23 = *(_DWORD *)((char*)v21 + 36);
        if ( v2 < 40 )
        {
          dword_50CBD0[3 * v2 + 1] = *(_DWORD *)((char*)v21 + 32);
          dword_50CBD0[3 * dword_50CBD0[0] + 2] = v23;
          dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = v1;
        }
        return 1;
      }
      return 1;
    }
    if ( Key == VK_SELECT )
    {
      class03_GetMouseClickPos(pGame->pClass03, &v33, &v34);
      //v4 = *(int *)((char *)array_506F68 + 32 + v3);
      v4 = GUIWindow_List[wndIdx].dword_000038;
      //v31 = v4 + *(int *)((char *)array_506F68 + 16 + v3);
      v31 = v4 + GUIWindow_List[wndIdx].dword_000028;
      //if ( v4 < v4 + *(int *)((char *)array_506F68 + 16 + v3) )
      if (v4 < v4 + GUIWindow_List[wndIdx].dword_000028)
      {
        while ( 1 )
        {
          //v5 = *(int *)((char *)array_506F68 + 52 + v3);
         v5 = GUIWindow_List[wndIdx].pControlsHead;
          if ( v4 > 0 )
          {
            v6 = v4;
            do
            {
              v5 = v5->pNext;
              --v6;
            }
            while ( v6 );
          }
          if ( v33 >= v5->uX
            && v33 <= v5->uZ
            && v34 >= v5->uY
            && v34 <= v5->uW)
            break;
          ++v4;
          if ( v4 >= v31 )
            goto LABEL_45;
        }
LABEL_66:
        //*(int *)((char *)array_506F68 + 20 + v3) = v4;
        GUIWindow_List[wndIdx].dword_00002C = v4;
        return 1;
      }
LABEL_46:
      v2 = dword_50CBD0[0];
      goto LABEL_47;
    }
    goto LABEL_47;
  }
  //v25 = *(int *)((char *)array_506F68 + 20 + v3);
  //v24 = *(int *)((char *)array_506F68 + 32 + v3);
  v24 = GUIWindow_List[wndIdx].dword_000038;
  v25 = GUIWindow_List[wndIdx].dword_00002C;
  if ( v25 <= v24 )
    //v26 = *(int *)((char *)array_506F68 + 16 + v3) + v24 - 1;
    v26 = GUIWindow_List[wndIdx].dword_000028 + v24 - 1;
  else
    v26 = v25 - 1;
  //v27 = *(int *)((char *)array_506F68 + 24 + v3) == v1;
  v27 = GUIWindow_List[wndIdx].dword_000030 == v1;
  //*(int *)((char *)array_506F68 + 20 + v3) = v26;
  GUIWindow_List[wndIdx].dword_00002C = v26;
  if ( v27 )
  {
    //v21 = *(int *)((char *)array_506F68 + 52 + v3);
    //v28 = *(int *)((char *)array_506F68 + 20 + v3);
   v21 = GUIWindow_List[wndIdx].pControlsHead;
   v28 = GUIWindow_List[wndIdx].dword_00002C;
    if ( v28 > v1 )
    {
      do
      {
        v21 = v21->pNext;
        --v28;
      }
      while ( v28 );
    }
    goto LABEL_56;
  }
  return 1;
}

//----- (0041D08F) --------------------------------------------------------
int __thiscall GUIWindow_sub_41D08F(struct GUIWindow *_this, int a2, int a3, int a4, int a5)
{
  int result; // eax@2

  if ( a2 )
  {
   _this->dword_000028 = a2;
   _this->dword_000030 = a3;
   _this->dword_000034 = a4;
    result = a5;
   _this->dword_00002C = a5;
   _this->dword_000038 = a5;
    _this->dword_000044 = 1;
  }
  else
  {
    _this->dword_000028 = 0;
    _this->dword_000030 = a3;
    result = a4;
    _this->dword_000034 = a4;
    _this->dword_00002C = 0;
    _this->dword_000038 = 0;
   _this->dword_000044 = 0;
  }
  return result;
}

//----- (0041D0D8) --------------------------------------------------------
void __thiscall GUIButton_sub_41D0D8(struct GUIButton *_this)
{
  int v1; // eax@2
  int v2; // edx@2
  int v3; // eax@6

  if ( _this )
  {
   v1 = (int)_this->pParentWindow;
    v2 = (int)_this->pNext;
    if (_this == _this->pParentWindow->pControlsHead)
    {
      if ( v2 )
      {
        *(_DWORD *)(v1 + 76) = v2;
        *(_DWORD *)(*(_DWORD *)((char*)_this + 52) + 48) = 0;
      }
      else
      {
        *(_DWORD *)(v1 + 76) = 0;
        *(_DWORD *)(*(_DWORD *)((char*)_this + 56) + 80) = 0;
      }
    }
    else
    {
      v3 = (int)_this->pPrev;
      if ( v2 )
      {
        *(_DWORD *)(v3 + 52) = v2;
        *(_DWORD *)(*(_DWORD *)((char*)_this + 52) + 48) = v3;
      }
      else
      {
        *(_DWORD *)(v3 + 52) = 0;
        *(_DWORD *)(*(_DWORD *)((char*)_this + 56) + 80) = v3;
      }
    }
    --*(_DWORD *)(*(_DWORD *)((char*)_this + 56) + 32);
    mem_mng.DeleteBuffer( (void *)_this);
  }
}

//----- (0041D20D) --------------------------------------------------------
void sub_41D20D(int a1, int a2, __int64 a3, int a4)
{
  unsigned int v4; // ebp@1
  int v5; // ebp@1
  int v6; // ebx@1
  signed __int64 v7; // ST34_8@1
  signed __int64 v8; // ST0C_8@1
  signed __int64 v9; // qax@1
  int v10; // eax@2
  int v11; // eax@9
  int v12; // eax@15
  int v13; // eax@21
  int v15; // [sp+0h] [bp-20h]@1
  int v16; // [sp+4h] [bp-1Ch]@1
  int v17; // [sp+Ch] [bp-14h]@1
  signed __int64 v18; // [sp+10h] [bp-10h]@1
  signed __int64 v19; // [sp+18h] [bp-8h]@1
  unsigned int v20; // [sp+24h] [bp+4h]@1

  v16 = a2;
  v15 = a1;
  v5 = (unsigned __int64)((signed __int64)((double)a3 * 0.234375) / 60) >> 32;
  v6 = (signed __int64)((double)a3 * 0.234375) / 60;
  v7 = (signed __int64)((double)a3 * 0.234375) / 60 / 60;
  v8 = (signed __int64)((double)a3 * 0.234375);
  v20 = (_DWORD)v7 / 0x18u;
  v9 = v8 % 60;
  HIDWORD(v8) = v5;
  LODWORD(v8) = v6;
  v19 = v9;
  v18 = v8 % 60;
  v4 = v7 % 24;
  v17 = (unsigned __int64)(v7 % 24) >> 32;
  strcpy((char *)TmpBuf, "\r020");
  if ( (_DWORD)v7 / 0x18u )
  {
    v10 = (int)pGlobalTXT_LocalizationStrings[57];
    if ( v20 <= 1 )
      v10 = (int)pGlobalTXT_LocalizationStrings[56];
    wsprintfA((char *)pStringBuffer, "%d %s ", v20, v10);
    strcat((char *)TmpBuf, (char *)pStringBuffer);
  }
  if ( v17 | v4 )
  {
    if ( v17 < 0 || v17 <= 0 && v4 <= 1 )
      v11 = (int)pGlobalTXT_LocalizationStrings[109];
    else
      v11 = (int)pGlobalTXT_LocalizationStrings[110];
    wsprintfA((char *)pStringBuffer, "%d %s ", v4, v11);
    strcat((char *)TmpBuf, (char *)pStringBuffer);
  }
  if ( v18 )
  {
    if ( !v20 )
    {
      if ( v18 <= 1 )
        v12 = (int)pGlobalTXT_LocalizationStrings[437];
      else
        v12 = (int)pGlobalTXT_LocalizationStrings[436];
      wsprintfA((char *)pStringBuffer, "%d %s ", v18, v12);
      strcat((char *)TmpBuf, (char *)pStringBuffer);
    }
  }
  if ( v19 )
  {
    if ( !(v17 | v4) )
    {
      if ( v19 <= 1 )
        v13 = (int)pGlobalTXT_LocalizationStrings[439];
      else
        v13 = (int)pGlobalTXT_LocalizationStrings[438];
      wsprintfA((char *)pStringBuffer, "%d %s ", v19, v13);
      strcat((char *)TmpBuf, (char *)pStringBuffer);
    }
  }
  FontDrawText((GUIWindow *)v16, (Font *)a4, 32, v15, (char *)TmpBuf, 0, 0, 0);
}

//----- (0041D3B7) --------------------------------------------------------
void GUIWindow_sub_41D3B7(GUIWindow *_this)
{
  int v1; // eax@1
  int v2; // ecx@1
  signed int v3; // ebx@1
  int v4; // edi@1
  int v6; // eax@5
  int v7; // ebx@5
  int v8; // ecx@5
  int v9; // ebx@5
  int v10; // eax@5
  int v11; // eax@5
  int v12; // ecx@5
  int v13; // eax@6
  PlayerFrame *v14; // eax@12
  signed int v15; // eax@12
  unsigned __int8 v16; // al@15
  unsigned int v17; // eax@15
  signed int v20; // eax@15
  unsigned int v21; // eax@15
  int v24; // eax@15
  unsigned int v25; // eax@15
  int v26; // eax@15
  char *v27; // ST28_4@15
  signed int v28; // eax@15
  char *v29; // eax@16
  int v30; // edx@18
  _UNKNOWN *v31; // edi@18
  int v32; // esi@18
  unsigned int v33; // eax@19
  int v34; // ecx@19
  __int64 v35; // ST38_8@22
  int v36; // esi@22
  const char *v37; // ST1C_4@22
  __int16 v38; // ax@22
  char *v39; // eax@24
  int v41; // [sp+14h] [bp-14h]@1
  int v42; // [sp+18h] [bp-10h]@1
  int v43; // [sp+1Ch] [bp-Ch]@1
  signed int v44; // [sp+20h] [bp-8h]@9
  int v45; // [sp+20h] [bp-8h]@18
  signed int v46; // [sp+24h] [bp-4h]@18

  v4 = (int)_this;
  v42 = (int)pFontComic;
 Player *pPlayer = &pParty_global->pPlayers[_this->dword_00001C];
  v43 = v4;
  v2 = 0;
  v1 = (int)pParty_global->pPlayers[_this->dword_00001C].pPlayerBuffs;
  v3 = 24;
  v41 = (int)pParty_global->pPlayers[_this->dword_00001C].pPlayerBuffs;
  do
  {
    if ( *(_QWORD *)v1 > 0i64 )
      ++v2;
    v1 += 16;
    --v3;
  }
  while ( v3 );
  v6 = *(_BYTE *)((char *)pFontArrus + 5) + 162;
  *(_DWORD *)(v4 + 12) = v6;
  v7 = (v2 - 1) * *(_BYTE *)((char *)pFontArrus + 5);
  v8 = *(_DWORD *)v4;
  v9 = v6 + v7;
  v10 = *(_DWORD *)(v4 + 8);
  *(_DWORD *)(v4 + 12) = v9;
  v11 = v10 + v8 - 1;
  v12 = *(_DWORD *)(v4 + 4);
  *(_DWORD *)(v4 + 16) = v11;
  *(_DWORD *)(v4 + 20) = v9 + v12 - 1;
  GUIWindow_sub_415551((GUIWindow *)v4, 0);
  if (pPlayer->pConditions[16])
  {
    v13 = uTextureIdx_PlayerFaceDead;
  }
  else if (pPlayer->pConditions[14])
  {
      v13 = uTextureIdx_PlayerFaceEradicated;
  }
  else
  {
      v44 = pPlayerFrameTable->GetFrameByNum(pPlayer->uDefaultFaceID);
      if ( !v44 )
        v44 = 1;
      if (pPlayer->uDefaultFaceID == 21)
      {
       v14 = pPlayerFrameTable->PlayerFrameTable_sub_494B5E( (int)&pPlayer->dword_001AA8, (int)&pPlayer->dword_001AA4, pClass24_global2->int_00001C);
      }
      else
      {
        v15 = class24_fn2(pClass24_global2);
        v14 = pPlayerFrameTable->GetFrameFromFrameset( v44, v15);
      }
      pPlayer->word_001AA2 = *(_WORD *)(v14 + 2) - 1;
      v13 = dword_A74CEC[*(_WORD *)(v14 + 2) + 56 * *(_DWORD *)(v4 + 28)];
  }


  Render_DrawTransparentTexture(pD3DRenderer, *(_DWORD *)v4 + 24, *(_DWORD *)(v4 + 4) + 24, (cTexture *)v13);
  v17 = 0xFFFFFF9B;
  wsprintfA((char *)TmpBuf, "\x0C%05d", v17);
  wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[429], pPlayer->sName, aClassNames[pPlayer->uClass]);


  strcat((char *)TmpBuf, (char *)pStringBuffer);
  strcat((char *)TmpBuf, "\x0C\x30\x30\x30\x30\x30\n");
  v20 = Player_GetMaxHealth(pPlayer);
  v21 = sub_4178FE_GetColor(pPlayer->sHealth, v20);


  wsprintfA((char *)pStringBuffer, "%s : \x0C%05u%d\x0C\x30\x30\x30\x30\x30 / %d\n", pGlobalTXT_LocalizationStrings[108], v21, pPlayer->sHealth, v20);
  strcat((char *)TmpBuf, (char *)pStringBuffer);
  v24 = Player_GetMaxMana(pPlayer);
  v25 = sub_4178FE_GetColor(pPlayer->sMana, v24);
  wsprintfA((char *)pStringBuffer, "%s : \x0C%05u%d\x0C\x30\x30\x30\x30\x30 / %d\n", pGlobalTXT_LocalizationStrings[212], v25, pPlayer->sMana, v24);
  strcat((char *)TmpBuf, (char *)pStringBuffer);
  v26 = Player_GetConditionIdx(pPlayer);
  v27 = (char *)aCharacterConditionNames[v26];

  

  v28 = sub_417939((void *)v26);
  wsprintfA((char *)pStringBuffer, "%s: \x0C%05d%s\0x0C\0x30\0x30\0x30\0x30\0x30\n", pGlobalTXT_LocalizationStrings[47], v28, v27);
  strcat((char *)TmpBuf, (char *)pStringBuffer);
  v16 = pPlayer->uQuickSpell;
  if ( v16 )
    v29 = (char *)pSpellStats->pSpellInfos[v16].pSpellNameShort;
  else
    v29 = (char *)pGlobalTXT_LocalizationStrings[153];
  wsprintfA((char *)pStringBuffer, "%s: %s", pGlobalTXT_LocalizationStrings[172], v29);
  strcat((char *)TmpBuf, (char *)pStringBuffer);
  v32 = 0;
  FontDrawText((GUIWindow *)v43, pFontArrus, 120, 22, (char *)TmpBuf, 0, 0, 0);
  v30 = v41;
  v45 = 0;
  v31 = &unk_4E2AD9;

  v46 = (int)&aSpellNames[20];

  int i = 0;
  do
  {
    v34 = *(_DWORD *)(v30 + 4);
    v33 = *(_DWORD *)v30;
    if ( v34 >= v32 )
    {
      if ( v34 > v32 || v33 > v32 )
      {
        //v35 = __PAIR__(v34, v33) - pParty_global->qword_00002C;
        v35 = *(_QWORD *)v30 - pParty_global->qword_00002C;

        v36 = v45++ * *(_BYTE *)(v42 + 5) + 134;
        v37 = *(const char **)v46;
        v38 = 0xFF000000 | ((unsigned int)(*((_BYTE *)v31 - 1)) << 16) | ((unsigned int)(*(_BYTE *)v31) << 8) | *((_BYTE *)v31 + 1);//colored or white text flag
        FontDrawText((GUIWindow *)v43, (Font *)v42, 52, v36, v37, 0, 0, 0);
        sub_41D20D(v36, v43, v35, v42);
        v30 = v41;
        v32 = 0;
      }
    }
    v46 += 4;
    v30 += 16;
    v31 = (char *)v31 + 3;
    v41 = v30;
  }
  //while ( v46 < (signed int)&dword_506978 );
  while (++i < 44 - 20);

  v39 = "";
  if ( v45 == v32 )
    v39 = (char *)pGlobalTXT_LocalizationStrings[153];
  wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[450], v39);
  FontDrawText((GUIWindow *)v43, pFontArrus, 14, 114, (char *)TmpBuf, v32, v32, (unsigned int)v32);
}

//----- (0041D73D) --------------------------------------------------------
void GUIWindow_sub_41D73D(int _this)
{
  signed int v1; // eax@1
  int v2; // edi@1
  int v3; // esi@1
  int v4; // eax@5
  int v5; // ecx@5
  int v6; // eax@5
  int v7; // ecx@5
  _UNKNOWN *v8; // ebx@7
  unsigned int v9; // eax@8
  unsigned int v10; // ecx@8
  __int64 v11; // ST28_8@11
  int v12; // esi@11
  const char *v13; // ST0C_4@11
  __int16 v14; // ax@11
  int *v16; // [sp+14h] [bp-10h]@7
  int v17; // [sp+18h] [bp-Ch]@1
  signed int v18; // [sp+1Ch] [bp-8h]@7
  int v19; // [sp+20h] [bp-4h]@1
  int v20; // [sp+20h] [bp-4h]@7

  v3 = (int)pFontComic;
  v2 = _this;
  v17 = (int)pFontComic;
  v19 = 0;
  v1 = (signed int)pParty_global->pPartyBuffs;
  do
  {
    if ( *(_QWORD *)v1 > 0i64 )
      ++v19;
    v1 += 16;
  }
  while ( v1 < (signed int)&pParty_global->pPlayers[0] );
  v4 = *(_BYTE *)(pFontArrus + 5) + 72;
  *(_DWORD *)(_this + 12) = v4;
  v5 = v4 + (v19 - 1) * *(_BYTE *)(pFontArrus + 5);
  v6 = *(_DWORD *)(v2 + 8);
  *(_DWORD *)(v2 + 12) = v5;
  v7 = *(_DWORD *)(v2 + 12);
  *(_DWORD *)(v2 + 16) = v6 + *(_DWORD *)v2 - 1;
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(v2 + 4) + v7 - 1;
  GUIWindow_sub_415551((GUIWindow *)v2, 0);
  GUIWindow_sub_44D406((GUIWindow *)v2, pFontArrus, 0, 12, 0, (char *)pGlobalTXT_LocalizationStrings[451], 3);
  if ( !v19 )
    GUIWindow_sub_44D406((GUIWindow *)v2, (Font *)v3, 0, 40, 0, (char *)pGlobalTXT_LocalizationStrings[153], 3);
  v20 = 0;
  GetTickCount();
  v8 = &unk_4E2B21;
  //v16 = &dword_5068C8;
  v16 = (int *)aSpellNames;
  v18 = (signed int)pParty_global->pPartyBuffs;
  do
  {
    v9 = *(_DWORD *)v18;
    v10 = *(_DWORD *)(v18 + 4);
    if ( (signed int)v10 >= 0 )
    {
      if ( (signed int)v10 > 0 || v9 )
      {
        compile_error;//v11 = __PAIR__(v10, v9) - pParty_global->qword_00002C;
        v12 = v20 * *(_BYTE *)(v3 + 5) + 40;
        v13 = (const char *)*v16;
        ++v20;
        v14 = 0xFF000000 | ((unsigned int)(*((_BYTE *)v8 - 1)) << 16) | ((unsigned int)(*(_BYTE *)v8) << 8) | *((_BYTE *)v8 + 1);//colored or white text flag
        FontDrawText((GUIWindow *)v2, (Font *)v17, 52, v12, v13, 0, 0, 0);
        sub_41D20D(v12, v2, v11, v17);
        v3 = v17;
      }
    }
    v18 += 16;
    ++v16;
    v8 = (char *)v8 + 3;
  }
  while ( v18 < (signed int)&pParty_global->pPlayers[0] );
}

//----- (0041D895) --------------------------------------------------------
void __thiscall sub_41D895(void *_this)
{
  void *v1; // esi@1
  int v2; // eax@3
  signed int v3; // eax@5
  int *v4; // edi@5
  int v5; // esi@5
  int v6; // eax@5
  int v7; // edx@5
  int v8; // ecx@10
  int v9; // eax@12
  int v10; // eax@16
  char v11; // zf@16
  char v12; // zf@18
  int v13; // eax@25
  char v14; // zf@25
  char v15; // zf@27
  int v16; // eax@32
  int v17; // ecx@32
  int v18; // edi@33
  int v19; // eax@34
  int v20; // eax@36
  int v21; // esi@37
  unsigned __int16 v22; // ax@37
  unsigned __int8 v23; // al@40
  unsigned __int8 v24; // al@44
  unsigned __int8 v25; // al@48
  char v26; // al@51
  int v27; // eax@52
  int v28; // eax@57
  int v29; // eax@60
  int v30; // eax@67
  const char *v32; // edi@69
  int v33; // eax@70
  signed int v34; // edi@78
  int v35; // eax@78
  int v36; // esi@81
  int v37; // ecx@81
  int v38; // eax@81
  const char *v40; // eax@85
  int v41; // eax@87
  int v42; // eax@109
  int v43; // eax@109
  int v44; // edx@113
  int v45; // eax@113
  signed int v46; // [sp-20h] [bp-298h]@113
  int v47; // [sp-1Ch] [bp-294h]@113
  char *v48; // [sp-18h] [bp-290h]@46
  __int16 v49; // [sp-18h] [bp-290h]@113
  int v50; // [sp-14h] [bp-28Ch]@46
  const char *v51; // [sp-14h] [bp-28Ch]@58
  const char *v52; // [sp-14h] [bp-28Ch]@110
  int v53; // [sp-10h] [bp-288h]@46
  const char *v54; // [sp-10h] [bp-288h]@56
  int v55; // [sp-10h] [bp-288h]@58
  int v56; // [sp-10h] [bp-288h]@110
  const char *v57; // [sp-Ch] [bp-284h]@36
  int v58; // [sp-Ch] [bp-284h]@46
  int v59; // [sp-Ch] [bp-284h]@56
  int v60; // [sp-Ch] [bp-284h]@58
  signed int v61; // [sp-Ch] [bp-284h]@110
  int v62; // [sp-8h] [bp-280h]@36
  int v63; // [sp-8h] [bp-280h]@46
  int v64; // [sp-8h] [bp-280h]@56
  int v65; // [sp-8h] [bp-280h]@58
  char *v66; // [sp-8h] [bp-280h]@110
  char v67[100]; // [sp+8h] [bp-270h]@40
  char Dest[100]; // [sp+6Ch] [bp-20Ch]@40
  char v69[100]; // [sp+D0h] [bp-1A8h]@40
  char v70; // [sp+134h] [bp-144h]@92
  char Source[40]; // [sp+1ACh] [bp-CCh]@49
  char v72; // [sp+1D4h] [bp-A4h]@91
  int v73; // [sp+1D8h] [bp-A0h]@106
  int v74; // [sp+1DCh] [bp-9Ch]@101
  int v75; // [sp+1E0h] [bp-98h]@97
  int v76; // [sp+1E8h] [bp-90h]@93
  int v77; // [sp+1ECh] [bp-8Ch]@91
  __int16 v78[2]; // [sp+1F0h] [bp-88h]@1
  int v79; // [sp+1F4h] [bp-84h]@5
  int v80; // [sp+1F8h] [bp-80h]@5
  int *v81; // [sp+1FCh] [bp-7Ch]@5
  int v82; // [sp+200h] [bp-78h]@12
  int v83; // [sp+204h] [bp-74h]@5

  GUIWindow local_208;
  //int v84; // [sp+208h] [bp-70h]@5
  //int v85; // [sp+20Ch] [bp-6Ch]@2
  //int v86; // [sp+210h] [bp-68h]@2
  //int v87; // [sp+214h] [bp-64h]@2
  //int v88; // [sp+218h] [bp-60h]@33
  //int v89; // [sp+21Ch] [bp-5Ch]@33
  //int v90; // [sp+250h] [bp-28h]@2

  char v91; // [sp+25Ch] [bp-1Ch]@2
  int v92; // [sp+260h] [bp-18h]@12
  int v93; // [sp+264h] [bp-14h]@5
  int v94; // [sp+268h] [bp-10h]@1
  int v95; // [sp+26Ch] [bp-Ch]@18
  char *Str1; // [sp+270h] [bp-8h]@65
  int v97; // [sp+274h] [bp-4h]@1

  v1 = _this;
  v97 = (int)_this;
  *(_DWORD *)v78 = 0xFFFFFF9B;
  v94 = (int)pFontComic;
  if ( *(_DWORD *)v1 )
  {
   local_208.ptr_000048 = 0;
    local_208.uFrameWidth = 384;
    local_208.uFrameHeight = 180;
    local_208.uFrameY = 40;
    if ( *(_DWORD *)class03_GetMousePos(pGame->pClass03, (POINT *)&v91) <= 320 )
      v2 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (POINT *)&v91) + 30;
    else
      v2 = *(_DWORD *)class03_GetMousePos(pGame->pClass03, (POINT *)&v91) - local_208.uFrameWidth - 30;
    local_208.uFrameX = v2;
    v4 = (int *)&pClass40->pItems[*(_DWORD *)v97].pIconName;
    v81 = v4;
    v6 = LODFile_Icons_LOD.LODFile_LoadTexture( (const char *)*v4, 2);
    v5 = v6;
    v6 *= 72;
    v80 = v6;
    v79 = (int)LODFile_Icons_LOD.aLODHeaders + v6;
    compile_error;//v3 = 100 - *(_WORD *)LODFile_Icons_LOD.array_000032C[v6 + 24];
    v7 = *(_WORD *)(v79 + 26);
    v83 = v3;
    v93 = 144 - v7;
    if ( v3 > 0 )
      v83 = v3 >> 1;
    if ( v93 <= 0 )
      v93 = 0;
    else
      v93 >>= 1;
    v8 = v97;
    if ( !*((_BYTE *)v4 + 46) )
      *(_DWORD *)(v97 + 20) |= 1u;
    v9 = *(_DWORD *)(v8 + 20);
    v82 = 0;
    v92 = v9 & 2;
    if (pClass40->pItems[*(_DWORD *)v8 - 1].uEquipType == 18 )
      v82 = *(_DWORD *)(v8 + 12);
    if ( uActiveCharacter )
    {
      if ( !(v9 & 1) )
      {
        v11 = sub_4910D3(v97) == 1;
        v10 = v97;
        if ( v11 )
          *(_DWORD *)(v97 + 20) |= 1u;
        v12 = (*(_BYTE *)(v10 + 20) & 1) == 0;
        v95 = 9;
        if ( v12 )
        {
          sub_44C175((char *)pGlobalTXT_LocalizationStrings[446], 2);
        }
        else
        {
          v95 = 8;
          if ( sub_456442(v97) < (unsigned int)(100 * (*((_WORD *)*(&ptr_A750C4 + uActiveCharacter) + 109) + 5)) )
            v95 = 7;
        }
        if ( dword_4E455C )
        {
          Player_PlaySound(*(&ptr_A750C4 + uActiveCharacter), v95, 0);
          dword_4E455C = 0;
        }
      }
      sub_458260(v97, pParty_global->qword_00002C);
      if ( v92 )
      {
        v14 = sub_491151(*(&ptr_A750C4 + uActiveCharacter), v97) == 1;
        v13 = v97;
        if ( v14 )
          *(_DWORD *)(v97 + 20) = *(_DWORD *)(v97 + 20) & 0xFFFFFFFD | 1;
        v15 = (*(_BYTE *)(v13 + 20) & 2) == 0;
        v95 = 11;
        if ( v15 )
          v95 = 10;
        else
          sub_44C175((char *)pGlobalTXT_LocalizationStrings[448], 2);
        if ( dword_4E455C )
        {
          Player_PlaySound(*(&ptr_A750C4 + uActiveCharacter), v95, 0);
          dword_4E455C = 0;
        }
      }
    }
    v17 = *(_DWORD *)(v97 + 20);
    v16 = *(_DWORD *)(v97 + 20) & 1;
    v92 = *(_DWORD *)(v97 + 20) & 1;
    if ( v17 & 2 )
    {
      GUIWindow_sub_415551(&local_208, 0);
      v18 = (int)pD3DRenderer;
      Render_Set2DClippingRect(pD3DRenderer, local_208.uFrameX + 12, local_208.uFrameY + 12, local_208.uFrameX + local_208.uFrameWidth - 12, local_208.uFrameY + local_208.uFrameHeight - 12);
      local_208.uFrameWidth -= 24;
      local_208.uFrameHeight -= 12;
      local_208.uFrameZ = local_208.uFrameX + local_208.uFrameWidth - 1;
      local_208.uFrameW = local_208.uFrameY + local_208.uFrameHeight - 1;
      Render_sub_4A6776((int)pD3DRenderer, local_208.uFrameX + v83, v93 + local_208.uFrameY + 30, (int)(v5 != -1 ? (char *)LODFile_Icons_LOD.aLODHeaders + v80 : 0));
      if ( v92 )
        v19 = sub_4564B3((void *)v97);
      else
        v19 = v81[2];
      GUIWindow_sub_44D406(&local_208, pFontArrus, 0, 12, v78[0], (const char *)v19, 3);
      v20 = CalculateTextHeght(pFontArrus, (char *)pGlobalTXT_LocalizationStrings[32], &local_208, 0, 0);
      v62 = 3;
      v57 = (char *)pGlobalTXT_LocalizationStrings[32];
      goto LABEL_37;
    }
    if ( !v16 )
    {
      GUIWindow_sub_415551(&local_208, 0);
      v18 = (int)pD3DRenderer;
      Render_Set2DClippingRect(pD3DRenderer, local_208.uFrameX + 12, local_208.uFrameY + 12, local_208.uFrameX + local_208.uFrameWidth - 12, local_208.uFrameY + local_208.uFrameHeight - 12);
      local_208.uFrameWidth -= 24;
      local_208.uFrameHeight -= 12;
      local_208.uFrameZ = local_208.uFrameX + local_208.uFrameWidth - 1;
      local_208.uFrameW = local_208.uFrameY + local_208.uFrameHeight - 1;
      Render_DrawTransparentTexture(pD3DRenderer, local_208.uFrameX + v83, v93 + local_208.uFrameY + 30, (cTexture *)(v5 != -1 ? (char *)LODFile_Icons_LOD.aLODHeaders + v80 : 0));
      GUIWindow_sub_44D406(&local_208, pFontArrus, 0, 12, v78[0], (const char *)v81[2], 3);
      v20 = CalculateTextHeght(pFontArrus, (char *)pGlobalTXT_LocalizationStrings[232], &local_208, 0, 0);
      v62 = 3;
      v57 = (char *)pGlobalTXT_LocalizationStrings[232];
LABEL_37:
      v21 = v20 >> 1;
      v22 = 0xFFFF1919;
      GUIWindow_sub_44D406(&local_208, pFontArrus, 100, (local_208.uFrameHeight / 2) - v21, v22, v57, v62);
      goto LABEL_116;
    }
    wsprintfA(v67, (char *)pGlobalTXT_LocalizationStrings[463], v4[2]);
    strcpy(Dest, "");
    strcpy(v69, "");
    v23 = *((_BYTE *)v4 + 28);
    if ( v23 <= 1u )
    {
      v63 = *((_BYTE *)v4 + 31);
      v58 = *((_BYTE *)v4 + 30);
      v53 = (int)pGlobalTXT_LocalizationStrings[53];
      v50 = *((_BYTE *)v4 + 32);
      v48 = (char *)pGlobalTXT_LocalizationStrings[18];
    }
    else
    {
      if ( v23 != 2 )
      {
        if ( v23 > 2 )
        {
          if ( v23 <= 0xBu )
          {
            v24 = *((_BYTE *)v4 + 30);
            if ( v24 )
              wsprintfA(Dest, "%s: +%d", pGlobalTXT_LocalizationStrings[11], v24 + *((_BYTE *)v4 + 32));
          }
        }
        goto LABEL_50;
      }
      v63 = *((_BYTE *)v4 + 31);
      v58 = *((_BYTE *)v4 + 30);
      v53 = (int)pGlobalTXT_LocalizationStrings[53];
      v50 = *((_BYTE *)v4 + 32);
      v48 = (char *)pGlobalTXT_LocalizationStrings[203];
    }
    wsprintfA(Dest, "%s: +%d   %s: %dd%d", v48, v50, v53, v58, v63);
    v25 = *((_BYTE *)v4 + 32);
    if ( v25 )
    {
      wsprintfA(Source, " +%d", v25);
      strcat(Dest, Source);
    }
LABEL_50:
    if ( v82 )
      goto LABEL_65;
    v26 = *((_BYTE *)v4 + 28);
    if ( v26 == 14 )
    {
      v27 = *(_DWORD *)(v97 + 4);
      if ( v27 )
        goto LABEL_56;
LABEL_65:
      local_208.uFrameWidth -= 12;
      v92 = 3;
      local_208.uFrameZ = local_208.uFrameX + local_208.uFrameWidth - 1;
      local_208.uFrameW = local_208.uFrameY + local_208.uFrameHeight - 1;
      Str1 = (char *)(3 * (*(_BYTE *)(pFontArrus + 5) + 8));
      v95 = (int)v67;
      do
      {
        if ( *(_BYTE *)v95 )
        {
          v30 = CalculateTextHeght((Font *)v94, (const char *)v95, &local_208, 100, 0);
          Str1 += v30 + 3;
        }
        v95 += 100;
      }
      while ( v92-- != 1 );
      v32 = (const char *)v4[3];
      if ( *v32 )
      {
        v33 = CalculateTextHeght(pFontSmallnum, v32, &local_208, 100, 0);
        Str1 += v33;
      }
      local_208.uFrameHeight = *(_WORD *)(v79 + 26) + v93 + 54;
      if ( (signed int)Str1 > local_208.uFrameHeight)
        local_208.uFrameHeight = (int)Str1;
      if ( *(_BYTE *)(v97 + 20) & 8 )
      {
        if ( *(_DWORD *)(v97 + 12) || *(_DWORD *)(v97 + 4) )
          local_208.uFrameHeight += *(_BYTE *)(v94 + 5);
      }
      v95 = 0;
      if ( *(_BYTE *)(pFontArrus + 5) )
      {
        local_208.uFrameWidth -= 24;
        v34 = *(_BYTE *)(pFontArrus + 5);
        v35 = sub_4564B3((void *)v97);
        if ( CalculateTextHeght(pFontArrus, (const char *)v35, &local_208, 0, 0) / v34 )
          v95 = v34;
        local_208.uFrameWidth += 24;
      }
      local_208.uFrameWidth += 12;
      local_208.uFrameHeight += v95;
      local_208.uFrameW = local_208.uFrameY + local_208.uFrameHeight - 1;
      local_208.uFrameZ = local_208.uFrameX + local_208.uFrameWidth - 1;
      GUIWindow_sub_415551(&local_208, 0);
      v18 = (int)pD3DRenderer;
      Render_Set2DClippingRect(pD3DRenderer, local_208.uFrameX + 12, local_208.uFrameY + 12, local_208.uFrameX + local_208.uFrameWidth - 12, local_208.uFrameY + local_208.uFrameHeight - 12);
      local_208.uFrameWidth -= 12;
      v37 = *(_WORD *)(v79 + 26);
      v38 = local_208.uFrameHeight;
      local_208.uFrameHeight -= 12;
      local_208.uFrameZ = local_208.uFrameX + local_208.uFrameWidth - 1;
      local_208.uFrameW = local_208.uFrameX + local_208.uFrameHeight - 1;
      Render_DrawTransparentTexture(pD3DRenderer, local_208.uFrameX + v83, local_208.uFrameY + (v38 - v37) / 2, v5 != -1 ? (cTexture *)LODFile_Icons_LOD.aLODHeaders + v80 : 0);
      v92 = 3;
      v36 = v95 + 35;
      Str1 = v67;
      do
      {
        if ( *Str1 )
        {
          FontDrawText(&local_208, (Font *)v94, 100, v36, Str1, 0, 0, 0);
          v36 += CalculateTextHeght((Font *)v94, Str1, &local_208, 100, 0) + 3;
        }
        Str1 += 100;
      }
      while ( v92-- != 1 );
      v40 = (const char *)v81[3];
      if ( *v40 )
        FontDrawText(&local_208, pFontSmallnum, 100, v36, v40, 0, 0, 0);
      local_208.uFrameX += 12;
      local_208.uFrameWidth -= 24;
      v41 = sub_4564B3((void *)v97);
      GUIWindow_sub_44D406(&local_208, pFontArrus, 0, 12, v78[0], (const char *)v41, 3);
      local_208.uFrameWidth += 24;
      local_208.uFrameX -= 12;
      if ( v82 )
      {
        wsprintfA((char *)TmpBuf, "%s: %lu", pGlobalTXT_LocalizationStrings[465], v82);
        v44 = v94;
        v66 = 0;
        v61 = 0;
        v56 = 0;
        v52 = (char *)TmpBuf;
        v49 = 0;
        v47 = local_208.uFrameHeight - *(_BYTE *)(v94 + 5);
        v46 = 100;
      }
      else
      {
        if ( *(_BYTE *)(v97 + 20) & 8 )
        {
          if ( *(_DWORD *)(v97 + 12) || *(_DWORD *)(v97 + 4) )
          {
            sub_493F79((int)&v72, *(_QWORD *)(v97 + 28) - pParty_global->qword_00002C);
            strcpy((char *)TmpBuf, "Duration:");
            Str1 = (char *)(v77 - 1168);
            if ( v77 != 1168 )
            {
              wsprintfA(&v70, " %d:yr", v77 - 1168);
              strcat((char *)(char *)TmpBuf, &v70);
            }
            if ( (((v76 || Str1)
                && ((wsprintfA(&v70, " %d:mo", v76), strcat((char *)TmpBuf, &v70), v76) || Str1)
                || v75)
               && ((wsprintfA(&v70, " %d:dy", v75), strcat((char *)TmpBuf, &v70), v76) || Str1 || v75)
               || v74)
              && ((wsprintfA(&v70, " %d:hr", v74), strcat((char *)TmpBuf, &v70), v76) || Str1 || v75 || v74)
              || v73 )
            {
              wsprintfA(&v70, " %d:mn", v73);
              strcat((char *)(char *)TmpBuf, &v70);
            }
            FontDrawText(&local_208, (Font *)v94, 100, local_208.uFrameHeight - 2 * *(_BYTE *)(v94 + 5), (char *)TmpBuf, 0, 0, 0);
          }
        }
        v43 = sub_456442(v97);
        wsprintfA((char *)TmpBuf, "%s: %lu", pGlobalTXT_LocalizationStrings[465], v43);
        FontDrawText(&local_208, (Font *)v94, 100, local_208.uFrameHeight - *(_BYTE *)(v94 + 5), (char *)TmpBuf, 0, 0, 0);
        v42 = *(_DWORD *)(v97 + 20);
        if ( BYTE1(v42) & 1 )
        {
          v66 = 0;
          v61 = 0;
          v56 = 0;
          v52 = (char *)pGlobalTXT_LocalizationStrings[187];
        }
        else
        {
          if ( !(BYTE1(v42) & 2) )
            goto LABEL_116;
          v66 = 0;
          v61 = 0;
          v56 = 0;
          v52 = (char *)pGlobalTXT_LocalizationStrings[651];
        }
        v49 = pD3DRenderer->uTargetRMask;
        v47 = local_208.uFrameHeight - *(_BYTE *)(v94 + 5);
        v45 = GetStringWidth((Font *)v94, (char *)TmpBuf);
        v44 = v94;
        v46 = v45 + 132;
      }
      FontDrawText(&local_208, (Font *)v44, v46, v47, v52, v56, v61, (unsigned int)v66);
LABEL_116:
      Render_Reset2DClippingRect((BaseRender *)v18);
      if ( !bTextureLoading )
      {
        cTexture_Free((cTexture *)v79);
        LODFile_Icons_LOD.LODFile_sub_40F9C5();
      }
      return;
    }
    if ( v26 == 13 )
    {
     v27 = pClass40->pItems[*(_DWORD *)v97 - 1].uDamageDice;
LABEL_56:
      v64 = v27;
      v59 = (int)pGlobalTXT_LocalizationStrings[449];
      v54 = "%s: %d";
LABEL_64:
      wsprintfA(v69, v54, v59, v64);
      goto LABEL_65;
    }
    v28 = *(_DWORD *)(v97 + 4);
    if ( v28 )
    {
      v65 = *(_DWORD *)(v97 + 8);
      v60 = dword_5DBFD0[5 * v28 + 1];
      v55 = (int)pGlobalTXT_LocalizationStrings[210];
      v51 = "%s: %s +%d";
    }
    else
    {
      v29 = *(_DWORD *)(v97 + 12);
      if ( !v29 )
      {
        if ( *(_DWORD *)(v97 + 16) )
        {
          v64 = *(_DWORD *)(v97 + 16);
          v59 = (int)pGlobalTXT_LocalizationStrings[464];
          v54 = "%s: %lu";
          goto LABEL_64;
        }
        goto LABEL_65;
      }
      v65 = *(_DWORD *)(v97 + 8);
      v60 = dword_5DC1A8[7 * v29 + 1];
      v55 = (int)pGlobalTXT_LocalizationStrings[210];
      v51 = "%s: %s";
    }
    wsprintfA(v69, v51, v55, v60, v65);
    goto LABEL_65;
  }
}

//----- (0041E360) --------------------------------------------------------
char *__fastcall sub_41E360(int a1, int a2)
{
  int v2; // esi@1
  int v3; // esi@3
  int v4; // eax@3
  signed int v5; // ecx@3
  char *v6; // eax@3
  __int16 v7; // cx@3
  int v8; // edx@4
  int v9; // eax@4
  int v10; // edi@17
  int v11; // esi@17
  int v12; // ecx@17
  int v13; // edi@18
  int v14; // ecx@18
  int v15; // edx@18
  int v16; // edx@18
  int v17; // eax@18
  int v18; // ecx@19
  int v19; // eax@21
  unsigned int v20; // edx@28
  int v21; // esi@28
  int v22; // eax@29
  int v23; // ecx@29
  int v24; // eax@32
  int v25; // esi@32
  unsigned __int8 v26; // sf@36
  unsigned __int8 v27; // of@36
  int v28; // eax@40
  int v29; // ecx@40
  int v30; // esi@40
  int v31; // esi@43
  __int16 v32; // ax@45
  int v33; // edx@45
  int v34; // eax@45
  int v35; // eax@49
  int v36; // eax@52
  int v37; // eax@55
  unsigned __int16 v38; // ax@59
  int v39; // eax@60
  int v40; // eax@61
  int v41; // edi@61
  int v42; // eax@62
  int v43; // eax@63
  signed int v44; // edi@65
  __int16 v45; // ax@73
  int v46; // ecx@77
  int v47; // eax@85
  int v49; // edi@90
  int v50; // edi@90
  int v51; // eax@91
  int v52; // ecx@98
  int v53; // ecx@101
  char *v54; // ST0C_4@118
  __int16 v55; // ax@118
  int v56; // edi@124
  unsigned __int8 v57; // al@128
  int v58; // eax@132
  int v59; // ecx@133
  unsigned __int8 v60; // dl@138
  int v61; // eax@145
  int v62; // eax@147
  char *result; // eax@152
  int v64; // eax@152
  int v65; // eax@155
  const char *v66; // [sp-10h] [bp-1FCh]@121
  const char *v67; // [sp-10h] [bp-1FCh]@125
  const char *v68; // [sp-10h] [bp-1FCh]@142
  int v69; // [sp-Ch] [bp-1F8h]@121
  int v70; // [sp-Ch] [bp-1F8h]@125
  int v71; // [sp-Ch] [bp-1F8h]@142
  int v72; // [sp-8h] [bp-1F4h]@54
  int v73; // [sp-8h] [bp-1F4h]@79
  signed int v74; // [sp-8h] [bp-1F4h]@121
  int v75; // [sp-8h] [bp-1F4h]@125
  int v76; // [sp-8h] [bp-1F4h]@142
  size_t v77; // [sp-4h] [bp-1F0h]@54
  char *v78; // [sp-4h] [bp-1F0h]@121
  char *v79; // [sp-4h] [bp-1F0h]@125
  char *v80; // [sp-4h] [bp-1F0h]@142
  int v81; // [sp-4h] [bp-1F0h]@148

  DDBLTFX local_0C;
  //int Dst; // [sp+Ch] [bp-1E0h]@18
  //int v83; // [sp+5Ch] [bp-190h]@18

  DDSURFACEDESC2 local_70;
  //int v84; // [sp+70h] [bp-17Ch]@18
  //int v85; // [sp+78h] [bp-174h]@34
  //int v86; // [sp+7Ch] [bp-170h]@34
  //int v87; // [sp+80h] [bp-16Ch]@34
  //unsigned int v88; // [sp+94h] [bp-158h]@28

  //int v89; // [sp+ECh] [bp-100h]@26
  //int v90; // [sp+F0h] [bp-FCh]@26
  //int v91; // [sp+F4h] [bp-F8h]@26
  //int v92; // [sp+F8h] [bp-F4h]@26

  int v93; // [sp+FCh] [bp-F0h]@145
  int v94; // [sp+100h] [bp-ECh]@145
  int v95; // [sp+104h] [bp-E8h]@145
  int v96; // [sp+108h] [bp-E4h]@145
  int v97; // [sp+10Ch] [bp-E0h]@145
  int v98; // [sp+110h] [bp-DCh]@145
  int v99; // [sp+114h] [bp-D8h]@145
  int v100; // [sp+118h] [bp-D4h]@145
  int v101; // [sp+11Ch] [bp-D0h]@145
  int v102; // [sp+120h] [bp-CCh]@145
  int v103; // [sp+124h] [bp-C8h]@127
  int v104; // [sp+128h] [bp-C4h]@127
  int v105; // [sp+12Ch] [bp-C0h]@127
  int v106; // [sp+130h] [bp-BCh]@127
  int v107; // [sp+134h] [bp-B8h]@127
  int v108; // [sp+138h] [bp-B4h]@127
  int v109; // [sp+13Ch] [bp-B0h]@127
  int v110; // [sp+140h] [bp-ACh]@127
  int v111; // [sp+144h] [bp-A8h]@127
  int v112; // [sp+148h] [bp-A4h]@127
  int v113; // [sp+14Ch] [bp-A0h]@127
  int v114; // [sp+150h] [bp-9Ch]@17
  int v115; // [sp+154h] [bp-98h]@17
  int v116; // [sp+158h] [bp-94h]@17
  int v117; // [sp+15Ch] [bp-90h]@17
  int v118; // [sp+160h] [bp-8Ch]@17
  int v119; // [sp+164h] [bp-88h]@17
  char *v120; // [sp+170h] [bp-7Ch]@17
  int v121; // [sp+178h] [bp-74h]@17
  int v122; // [sp+17Ch] [bp-70h]@17
  int v123; // [sp+180h] [bp-6Ch]@17
  int v124; // [sp+184h] [bp-68h]@17
  int v125; // [sp+188h] [bp-64h]@17
  int v126; // [sp+18Ch] [bp-60h]@17
  int v127; // [sp+190h] [bp-5Ch]@17
  int v128; // [sp+198h] [bp-54h]@3
  int v129; // [sp+1A0h] [bp-4Ch]@18
  unsigned int v130; // [sp+1A4h] [bp-48h]@34
  int v131; // [sp+1A8h] [bp-44h]@32
  unsigned int v132; // [sp+1ACh] [bp-40h]@28
  int v133; // [sp+1B0h] [bp-3Ch]@29
  int *v134; // [sp+1B4h] [bp-38h]@3
  int v135; // [sp+1B8h] [bp-34h]@18
  unsigned __int8 v136; // [sp+1BFh] [bp-2Dh]@133
  int v137; // [sp+1C0h] [bp-2Ch]@3
  int v138; // [sp+1C4h] [bp-28h]@18
  int i; // [sp+1C8h] [bp-24h]@18
  int v140; // [sp+1CCh] [bp-20h]@28
  int v141; // [sp+1D0h] [bp-1Ch]@18
  int v142; // [sp+1D4h] [bp-18h]@18
  int v143; // [sp+1D8h] [bp-14h]@3
  int v144; // [sp+1DCh] [bp-10h]@3
  int v145; // [sp+1E0h] [bp-Ch]@1
  int v146; // [sp+1E4h] [bp-8h]@18
  char *Str1; // [sp+1E8h] [bp-4h]@18
 int j;

  v145 = a2;
  v2 = a1;
  if ( !(stru_506580_MonsterInfoUI_bDollInitialized & 1) )
  {
    stru_506580_MonsterInfoUI_bDollInitialized |= 1u;
    Actor_TotalReset(&stru_506580_MonsterInfoUI_Doll);
    atexit(0);
  }
  v128 = -1;
  v3 = (int)&pActors[v2];
  v143 = v3;
  v4 = 0xFFFFFF9B;
  v5 = *(_WORD *)(v3 + 32);
  v144 = v4;
  v6 = (char *)sub_4459F9_GetNPCData(v5);
  v7 = *(_WORD *)(v3 + 96);
  v134 = (int *)v6;
  v137 = byte_4E2B70[(v7 - 1) / 3] - 40;
  if (v7 == stru_506580_MonsterInfoUI_Doll.uMonsterID)
  {
    LOWORD(v8) = stru_506580_MonsterInfoUI_Doll.word_0000A0;
  }
  else
  {
    memcpy(&stru_506580_MonsterInfoUI_Doll, (const void *)v3, sizeof(Actor));
    stru_506580_MonsterInfoUI_Doll.word_0000B2_looks_like_current_sprite_frame = 7;
    stru_506580_MonsterInfoUI_Doll.dword_0000B8 = 0;
    v9 = rand();
    v3 = v143;
    v8 = v9 % 256 + 128;
    stru_506580_MonsterInfoUI_Doll.word_0000A0 = v9 % 256 + 128;
  }
  if (stru_506580_MonsterInfoUI_Doll.dword_0000B8 > (signed __int16)v8 )
  {
    stru_506580_MonsterInfoUI_Doll.dword_0000B8 = 0;
    if (stru_506580_MonsterInfoUI_Doll.word_0000B2_looks_like_current_sprite_frame == 7 ||
        stru_506580_MonsterInfoUI_Doll.word_0000B2_looks_like_current_sprite_frame == 2)
    {
      stru_506580_MonsterInfoUI_Doll.word_0000B2_looks_like_current_sprite_frame = 0;
      stru_506580_MonsterInfoUI_Doll.word_0000A0 = rand() % 128 + 128;
    }
    else
    {
      rand();
      stru_506580_MonsterInfoUI_Doll.word_0000B2_looks_like_current_sprite_frame = 7;
      if (stru_506580_MonsterInfoUI_Doll.uMonsterID < 115 || stru_506580_MonsterInfoUI_Doll.uMonsterID > 186)
      {
        if (stru_506580_MonsterInfoUI_Doll.uMonsterID < 232 || stru_506580_MonsterInfoUI_Doll.uMonsterID > 249)
        {
          if ( rand() % 30 < 100 )
            stru_506580_MonsterInfoUI_Doll.word_0000B2_looks_like_current_sprite_frame = 2;
        }
      }
      //word_506620 = 8 * *(_WORD *)(60 * *(_WORD *)(v3 + 2 * word_506632 + 188) + dword_5C6DCC + 56);
      stru_506580_MonsterInfoUI_Doll.word_0000A0 = 8 * *(_WORD *)(60 * *(_WORD *)(v3 + 2 * stru_506580_MonsterInfoUI_Doll.word_0000B2_looks_like_current_sprite_frame + 188) + (unsigned int)(pSpriteFrameTable->pSpriteSFrames) + 56);
    }
  }
  v10 = (int)CSpriteFrameTable_fn1(pSpriteFrameTable, *(_WORD *)(v3 + 2 * stru_506580_MonsterInfoUI_Doll.word_0000B2_looks_like_current_sprite_frame + 188), stru_506580_MonsterInfoUI_Doll.dword_0000B8);

  //v11 = 40 * *(_WORD *)(v10 + 24) + (int)LODFile_Sprites_LOD.aLODHeaders;
  v11 = (int)&LODFile_Sprites_LOD.pHardwareSprites[*(_WORD *)(v10 + 24)];

  v114 = (int)pD3DRenderer->pTargetSurface;
  v115 = (int)pD3DRenderer->pActiveZBuffer;
  v123 = (int)pD3DRenderer->uTargetSurfacePitch;
  v12 = *(_DWORD *)(v145 + 4) + 52;
  v124 = *(_DWORD *)v145 + 13;
  v125 = v12;
  v127 = v12 + 128;
  v126 = v124 + 128;
  v116 = (v124 + 128 + v124) / 2;
  v118 = 65536;
  v119 = 65536;
  v117 = v137 + v12 + *(_WORD *)(v11 + 18);
  v120 = sub_41F50D(*(_WORD *)(v10 + 52), 0, 1);
  v121 = 0;
  v122 = 0;
  Render_sub_4A0E97(pD3DRenderer, 0, 0, 639, 479);
  Render_FillRect(pD3DRenderer, v124 - 1, v125 - 1, v124 + 129, v125 - 1, v144);
  Render_FillRect(pD3DRenderer, v124 + 129, v125 - 1, v124 + 129, v127 + 1, v144);
  Render_FillRect(pD3DRenderer, v124 + 129, v127 + 1, v124 - 1, v127 + 1, v144);
  Render_FillRect(pD3DRenderer, v124 - 1, v127 + 1, v124 - 1, v125 - 1, v144);
  if ( pD3DRenderer->pRenderD3D3 )
  {
    v13 = (int)&LODFile_Sprites_LOD.pHardwareSprites[*(_WORD *)(v10 + 24)];
    v117 = v137 + v125 + *(_DWORD *)(v13 + 28);
    v135 = *(_DWORD *)(v13 + 8);

    memset(&local_0C, 0, sizeof(DDBLTFX));
    local_0C.dwSize = sizeof(DDBLTFX);
    local_0C.dwFillColor = 0;

    memset(&local_70, 0, sizeof(DDSURFACEDESC2));
    local_70.dwSize = sizeof(DDSURFACEDESC2);
    (*(void (__stdcall **)(int, int *))(*(_DWORD *)v135 + 88))(v135, (int *)&local_70);
    v14 = *(_DWORD *)(v13 + 28);
    v142 = *(_DWORD *)(v13 + 24);
    v129 = 0;
    v15 = *(_DWORD *)(v13 + 16);
    v141 = v142 / 2;
    i = 0;
    Str1 = (char *)(v116 + v15 - v142 / 2);
    v137 = *(_DWORD *)(v13 + 20);
    v16 = *(_DWORD *)(v13 + 32) + v142 / 2 + v15 - v142;
    v146 = v117 + v137 - v14;
    v17 = *(_DWORD *)(v13 + 36) + v137 - v14;
    v138 = v116 + v16;
    v141 = v117 + v17;
    if ( (signed int)Str1 < v124 )
    {
      v18 = v124 - (_DWORD)Str1;
      Str1 = (char *)v124;
      v129 = v18;
    }
    if ( v146 < v125 )
    {
      v19 = v125 - v146;
      v146 = v125;
      i = v19;
    }
    if ( v138 > v126 )
      v138 = v126;
    if ( v141 > v127 )
      v141 = v127;
    Render_FillRect2(pD3DRenderer, v124, v125, v126 - v124, v127 - v125, pD3DRenderer->uTargetBMask | pD3DRenderer->uTargetGMask);


    RECT v89 = {v124, v125, v124, v127};
    pD3DRenderer->pdds4_BackBuffer->Blt(&v89, 0, 0, 0x1000400, &local_0C);
    /*(*(void (__stdcall **)(int, int *, _DWORD, _DWORD, signed int, int *))(*(_DWORD *)pD3DRenderer->pdds4_BackBuffer + 20))(
      pD3DRenderer->pdds4_BackBuffer,
      &v89,
      0,
      0,
      16778240,
      &Dst);*/
    if ( pD3DRenderer->uNumTargetGBits == 5 )
    {
      memset(&local_70, 0, sizeof(DDSURFACEDESC2));
      local_70.dwSize = sizeof(DDSURFACEDESC2);
      if ( !LockSurface_DDraw4((IDirectDrawSurface4 *)v135, &local_70, 1) )
        goto LABEL_51;
      v21 = v146;
      v20 = v146;
      v132 = (int)local_70.lpSurface;
      v140 = v146;
      if ( v146 < v141 )
      {
        v133 = 2 * pD3DRenderer->uTargetSurfacePitch;
        v20 = (unsigned int)Str1;
        v23 = (int)(pD3DRenderer->pTargetSurface + (_DWORD)&Str1[v146 * pD3DRenderer->uTargetSurfacePitch]);
        v22 = i - v146;
        v142 = (int)(pD3DRenderer->pTargetSurface + (_DWORD)&Str1[v146 * pD3DRenderer->uTargetSurfacePitch]);
        v137 = i - v146;
        while ( 1 )
        {
          v146 = v20;
          if ( (signed int)v20 < v138 )
          {
            v24 = v21 + v22;
            v25 = v129 - v20;
            v131 = v24;
            for ( i = v129 - v20; ; v25 = i )
            {
              v130 = (local_70.lPitch >> 1) * (unsigned int)(local_70.dwHeight * v131) / *(_DWORD *)(v13 + 36);
              v20 = (unsigned int)(local_70.dwWidth * (v25 + v146++)) / *(_DWORD *)(v13 + 32) + v130;
              *(_WORD *)v23 = *(_WORD *)(v132 + 2 * v20);
              v23 += 2;
              if ( v146 >= v138 )
                break;
            }
            v22 = v137;
          }
          v23 = v133 + v142;
          v21 = v140 + 1;
          compile_error;//v27 = __SETO__(v140 + 1, v141);
          v26 = v140++ + 1 - v141 < 0;
          v142 += v133;
          if ( !(v26 ^ v27) )
            break;
          v20 = (unsigned int)Str1;
        }
      }
      goto LABEL_37;
    }
    memset(&local_70, 0, sizeof(DDSURFACEDESC2));
    local_70.dwSize = sizeof(DDSURFACEDESC2);
    if ( LockSurface_DDraw4((IDirectDrawSurface4 *)v135, &local_70, 1) )
    {
      v20 = v146;
      v130 = (int)local_70.lpSurface;
      v140 = v146;
      if ( v146 < v141 )
      {
        v131 = pD3DRenderer->uTargetSurfacePitch;
        v30 = (int)Str1;
        v29 = (int)(pD3DRenderer->pTargetSurface + (_DWORD)&Str1[v146 * pD3DRenderer->uTargetSurfacePitch]);
        v28 = i - v146;
        v142 = (int)(pD3DRenderer->pTargetSurface + (_DWORD)&Str1[v146 * pD3DRenderer->uTargetSurfacePitch]);
        v137 = i - v146;
        while ( 1 )
        {
          v146 = v30;
          if ( v30 < v138 )
          {
            v31 = v129 - (_DWORD)Str1;
            v133 = v140 + v28;
            for ( i = v129 - (_DWORD)Str1; ; v31 = i )
            {
              v132 = (local_70.lPitch >> 1) * (unsigned int)(local_70.dwHeight * v133) / *(_DWORD *)(v13 + 36);
              v32 = *(_WORD *)(v130 + 2 * ((unsigned int)(local_70.dwWidth * (v31 + v146)) / *(_DWORD *)(v13 + 32) + v132));
              v33 = v32 & 0x1F | 2
                               * (unsigned __int16)(*(_WORD *)(v130
                                                             + 2
                                                             * ((unsigned int)(local_70.dwWidth * (v31 + v146++))
                                                              / *(_DWORD *)(v13 + 32)
                                                              + v132)) & 0xFFE0);
              v34 = v146;
              *(_WORD *)v29 = v33;
              v29 += 2;
              if ( v34 >= v138 )
                break;
            }
            v28 = v137;
          }
          ++v140;
          v29 = v131 + v142;
          v20 = v140;
          v142 += v131;
          if ( v140 >= v141 )
            break;
          v30 = (int)Str1;
        }
      }
LABEL_37:
      (*(void (__fastcall **)(_DWORD, unsigned int, int, _DWORD))(*(_DWORD *)v135 + 128))(*(_DWORD *)v135, v20, v135, 0);
      goto LABEL_51;
    }
  }
  else
  {
    compile_error;//Render_FillRect2(pD3DRenderer, 0, v124, v125, v126 - v124, v127 - v125, 0);
    v35 = *(_WORD *)(v10 + 24);
    if ( v35 >= 0 )
      sub_4ACC38(40 * v35 + 7218180, (Render_BillboardTransform_stru0 *)&v114, 0);
  }
LABEL_51:
  if ( *(_WORD *)(v143 + 32) )
  {
    v36 = v134[6];
    if ( v36 )
    {
      wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[429], *v134, aNPCProfessionNames[v36]);
      goto LABEL_59;
    }
    v77 = 2000;
    v72 = *v134;
  }
  else
  {
    v37 = *(_DWORD *)(v143 + 820);
    v77 = 2000;
    if ( v37 )
      //v72 = dword_5D2958[v37];
      v72 = (int)pMonsterStats->sPlacements.pSubstrings[v37 - 1];
    else
      v72 = (int)pMonsterStats->pMonsterInfos[*(_WORD *)(v143 + 96)].pName;
  }
  strncpy((char *)(char *)TmpBuf, (const char *)v72, v77);
LABEL_59:
  v38 = 0xFFFFFF9B;
  GUIWindow_sub_44D406((GUIWindow *)v145, pFontComic, 0, 12, v38, (char *)TmpBuf, 3);
  sub_41AF52(v143, v145);
  v141 = 0;
  stru_506580_MonsterInfoUI_Doll.dword_0000B8 += pClass24_global2->int_00001C;
  v137 = 0;
  v138 = 0;
  i = 0;
  v134 = 0;
  if ( !uActiveCharacter )
  {
    v44 = 1;
    goto LABEL_84;
  }
  LOBYTE(v39) = Player_sub_48F882(pPlayers[uActiveCharacter - 1], 32);
  v142 = v39;
  if ( v39 )
  {
    v41 = v39 & 0x3F;
    v40 = sub_458244(v39) - 1;
    if ( v40 )
    {
      v42 = v40 - 1;
      if ( v42 )
      {
        v43 = v42 - 1;
        if ( v43 )
        {
          if ( v43 == 1 )
          {
            v44 = 1;
            v141 = 1;
            v138 = 1;
            i = 1;
            v134 = (int *)1;
            goto LABEL_73;
          }
        }
        else
        {
          if ( 3 * v41 + 10 >= *(_BYTE *)(v143 + 52) )
          {
            v44 = 1;
            v141 = 1;
            v138 = 1;
            i = 1;
            goto LABEL_73;
          }
        }
      }
      else
      {
        if ( 2 * v41 + 10 >= *(_BYTE *)(v143 + 52) )
        {
          v44 = 1;
          v141 = 1;
          v138 = 1;
          goto LABEL_73;
        }
      }
    }
    else
    {
      if ( v41 + 10 >= *(_BYTE *)(v143 + 52) )
      {
        v44 = 1;
        v141 = 1;
        goto LABEL_73;
      }
    }
  }
  v44 = 1;
LABEL_73:
  v45 = *(_WORD *)(v143 + 176);
  if ( v45 != 5 )
  {
    if ( v45 != 4 )
    {
      if ( !dword_507BF0 )
      {
        if ( v142 )
        {
          v46 = (int)pPlayers[uActiveCharacter - 1];
          if ( v141 | v138 | i | (unsigned int)v134 )
          {
            if ( *(_BYTE *)(v143 + 52) >= *(_WORD *)(v46 + 218) - 5 )
              v73 = 105;
            else
              v73 = 104;
          }
          else
          {
            v73 = 106;
          }
          Player_PlaySound((Player *)v46, v73, 0);
        }
      }
    }
  }

LABEL_84:
  for (j = 0; j < 4; ++j)
  {
    LOBYTE(v47) = Player_sub_48F882(&pParty_global->pPlayers[j], 32);
    v133 = v47;
    v142 = 138;
    do
    {
      if ( sub_458244(v133) >= 3 )
        v137 = v44;
    }
    while ( v142-- != 1 );
  }

  v50 = (int)pFontSmallnum;
  v140 = (int)pFontSmallnum;
  FontDrawText((GUIWindow *)v145, pFontSmallnum, 12, 196, (char *)pGlobalTXT_LocalizationStrings[631], 0, 0, 0);
  v49 = *(_BYTE *)(v50 + 5) + 193;
  if ( !v137 )
  {
    v78 = 0;
    v74 = 0;
    v69 = 0;
    v66 = (char *)pGlobalTXT_LocalizationStrings[630];
    goto LABEL_123;
  }
  Str1 = 0;
  v51 = v143 + 228;
  v135 = 0;
  v142 = v143 + 228;
  do
  {
    if ( *(_QWORD *)v51 > 0i64 )
    {
      switch ( v51 )
      {
        case 0:
          v146 = 60;
          Str1 = (char *)pGlobalTXT_LocalizationStrings[591];
          break;
        case 1:
          v146 = 82;
          Str1 = (char *)pGlobalTXT_LocalizationStrings[649];
          break;
        case 2:
          v146 = 92;
          Str1 = (char *)pGlobalTXT_LocalizationStrings[592];
          break;
        case 3:
          v146 = 63;
          Str1 = (char *)pGlobalTXT_LocalizationStrings[4];
          break;
        case 4:
          v52 = (int)pGlobalTXT_LocalizationStrings[220];
          goto LABEL_100;
        case 5:
          v52 = (int)pGlobalTXT_LocalizationStrings[162];
LABEL_100:
          Str1 = (char *)v52;
          v146 = 81;
          break;
        case 6:
          v53 = (int)pGlobalTXT_LocalizationStrings[593];
          v146 = 35;
          goto LABEL_103;
        case 8:
          v53 = (int)pGlobalTXT_LocalizationStrings[608];
          v146 = 62;
LABEL_103:
          Str1 = (char *)v53;
          break;
        case 7:
        case 9:
          Str1 = 0;
          v146 = 0;
          goto LABEL_119;
        case 10:
          v146 = 47;
          Str1 = (char *)pGlobalTXT_LocalizationStrings[221];
          break;
        case 11:
          v146 = 66;
          Str1 = (char *)pGlobalTXT_LocalizationStrings[164];
          break;
        case 12:
          v146 = 85;
          Str1 = (char *)pGlobalTXT_LocalizationStrings[610];
          break;
        case 13:
          v146 = 86;
          Str1 = (char *)pGlobalTXT_LocalizationStrings[609];
          break;
        case 14:
          v146 = 17;
          Str1 = (char *)pGlobalTXT_LocalizationStrings[279];
          break;
        case 15:
          v146 = 38;
          Str1 = (char *)pGlobalTXT_LocalizationStrings[442];
          break;
        case 16:
          v146 = 46;
          Str1 = (char *)pGlobalTXT_LocalizationStrings[443];
          break;
        case 17:
          v146 = 51;
          Str1 = (char *)pGlobalTXT_LocalizationStrings[440];
          break;
        case 18:
          v146 = 5;
          Str1 = (char *)pGlobalTXT_LocalizationStrings[441];
          break;
        case 19:
          v146 = 95;
          Str1 = (char *)pGlobalTXT_LocalizationStrings[229];
          break;
        case 20:
          v146 = 73;
          Str1 = (char *)pGlobalTXT_LocalizationStrings[228];
          break;
        default:
          Str1 = 0;
          break;
      }
      if ( Str1 )
      {
        v54 = Str1;
        v55 = sub_45828B(v146);
        FontDrawText((GUIWindow *)v145, (Font *)v140, 28, v49, v54, 0, 0, 0);
        v49 = v49 + *(_BYTE *)(v140 + 5) - 3;
        v51 = v142;
      }
    }
LABEL_119:
    v51 += 16;
    ++v135;
    v142 = v51;
  }
  while ( v135 + 1 < 22 );
  if ( !Str1 )
  {
    v78 = 0;
    v74 = 0;
    v69 = 0;
    v66 = (char *)pGlobalTXT_LocalizationStrings[153];
LABEL_123:
    FontDrawText((GUIWindow *)v145, (Font *)v140, 28, v49, v66, v69, v74, (unsigned int)v78);
  }
  v56 = (int)pFontSmallnum;
  Str1 = (char *)v125;
  if ( v141 )
  {
    wsprintfA((char *)TmpBuf, (const char *)&unk_4E3384, pGlobalTXT_LocalizationStrings[108], 0, *(_DWORD *)(v143 + 108));
    FontDrawText((GUIWindow *)v145, (Font *)v56, 150, (int)Str1, (char *)TmpBuf, 0, 0, 0);
    Str1 = &Str1[*(_BYTE *)(v56 + 5) - 3];
    v79 = *(char **)(v143 + 112);
    v75 = 0;
    v70 = (int)pGlobalTXT_LocalizationStrings[12];
    v67 = (const char *)&unk_4E3384;
  }
  else
  {
    wsprintfA((char *)TmpBuf, (const char *)&unk_4E3374, pGlobalTXT_LocalizationStrings[108], 0, pGlobalTXT_LocalizationStrings[630]);
    FontDrawText((GUIWindow *)v145, (Font *)v56, 150, (int)Str1, (char *)TmpBuf, 0, 0, 0);
    v79 = (char *)pGlobalTXT_LocalizationStrings[630];
    v75 = 0;
    v70 = (int)pGlobalTXT_LocalizationStrings[12];
    Str1 = &Str1[*(_BYTE *)(v56 + 5) - 3];
    v67 = (const char *)&unk_4E3374;
  }
  wsprintfA((char *)TmpBuf, v67, v70, v75, v79);
  FontDrawText((GUIWindow *)v145, (Font *)v56, 150, (int)Str1, (char *)TmpBuf, 0, 0, 0);
  Str1 = &Str1[*(_BYTE *)(v56 + 5) - 6] + *(_BYTE *)(v56 + 5);
  v103 = (int)pGlobalTXT_LocalizationStrings[87];
  v104 = (int)pGlobalTXT_LocalizationStrings[6];
  v105 = (int)pGlobalTXT_LocalizationStrings[240];
  v106 = (int)pGlobalTXT_LocalizationStrings[70];
  v107 = (int)pGlobalTXT_LocalizationStrings[624];
  v108 = (int)pGlobalTXT_LocalizationStrings[138];
  v109 = (int)pGlobalTXT_LocalizationStrings[214];
  v110 = (int)pGlobalTXT_LocalizationStrings[142];
  v111 = (int)pGlobalTXT_LocalizationStrings[29];
  v112 = (int)pGlobalTXT_LocalizationStrings[133];
  v113 = (int)pGlobalTXT_LocalizationStrings[54];
  if ( v138 )
  {
    wsprintfA((char *)TmpBuf, (const char *)&unk_4E3364, pGlobalTXT_LocalizationStrings[18], 0, *(&v103 + *(_BYTE *)(v143 + 65)));
    FontDrawText((GUIWindow *)v145, (Font *)v56, 150, (int)Str1, (char *)TmpBuf, 0, 0, 0);
    Str1 = &Str1[*(_BYTE *)(v56 + 5) - 3];
    v57 = *(_BYTE *)(v143 + 68);
    if ( v57 )
      wsprintfA((char *)TmpBuf,
        (const char *)&unk_4E334C,
        pGlobalTXT_LocalizationStrings[53],
        0,
        *(_BYTE *)(v143 + 66),
        *(_BYTE *)(v143 + 67),
        v57);
    else
      wsprintfA((char *)TmpBuf,
        (const char *)&unk_4E3338,
        pGlobalTXT_LocalizationStrings[53],
        0,
        *(_BYTE *)(v143 + 66),
        *(_BYTE *)(v143 + 67));
  }
  else
  {
    wsprintfA((char *)TmpBuf, (const char *)&unk_4E3364, pGlobalTXT_LocalizationStrings[18], 0, pGlobalTXT_LocalizationStrings[630]);
    FontDrawText((GUIWindow *)v145, (Font *)v56, 150, (int)Str1, (char *)TmpBuf, 0, 0, 0);
    Str1 = &Str1[*(_BYTE *)(v56 + 5) - 3];
    wsprintfA((char *)TmpBuf, (const char *)&unk_4E3364, pGlobalTXT_LocalizationStrings[53], 0, pGlobalTXT_LocalizationStrings[630]);
  }
  FontDrawText((GUIWindow *)v145, (Font *)v56, 150, (int)Str1, (char *)TmpBuf, 0, 0, 0);
  v58 = *(_BYTE *)(v56 + 5);
  Str1 = &Str1[v58 - 6] + v58;
  if ( !i )
  {
    v80 = (char *)pGlobalTXT_LocalizationStrings[630];
    v76 = 0;
    v71 = (int)pGlobalTXT_LocalizationStrings[628];
    v68 = (const char *)&unk_4E3364;
    goto LABEL_144;
  }
  v142 = (int)pGlobalTXT_LocalizationStrings[628];
  v59 = v143;
  v136 = *(_BYTE *)(v143 + 77);
  if ( v136 )
  {
    if ( *(_BYTE *)(v143 + 79) )
      v142 = (int)pGlobalTXT_LocalizationStrings[629];
  }
  if ( v136 )
  {
    wsprintfA((char *)TmpBuf, (const char *)&unk_4E3328, v142, 0, pSpellStats->pSpellInfos[v136].pSpellNameShort);
    FontDrawText((GUIWindow *)v145, (Font *)v56, 150, (int)Str1, (char *)TmpBuf, 0, 0, 0);
    v58 = *(_BYTE *)(v56 + 5);
    Str1 = &Str1[v58 - 3];
    v59 = v143;
  }
  v60 = *(_BYTE *)(v59 + 79);
  if ( v60 )
  {
    wsprintfA((char *)TmpBuf, (const char *)&unk_4E3318, 0, pSpellStats->pSpellInfos[v60].pSpellNameShort);
    FontDrawText((GUIWindow *)v145, (Font *)v56, 150, (int)Str1, (char *)TmpBuf, 0, 0, 0);
    v58 = *(_BYTE *)(v56 + 5);
    Str1 = &Str1[v58 - 3];
    v59 = v143;
  }
  if ( !*(_BYTE *)(v59 + 77) && !*(_BYTE *)(v59 + 79) )
  {
    v80 = (char *)pGlobalTXT_LocalizationStrings[153];
    v76 = 0;
    v71 = (int)pGlobalTXT_LocalizationStrings[628];
    v68 = (const char *)&unk_4E3328;
LABEL_144:
    wsprintfA((char *)TmpBuf, v68, v71, v76, v80);
    FontDrawText((GUIWindow *)v145, (Font *)v56, 150, (int)Str1, (char *)TmpBuf, 0, 0, 0);
    v58 = *(_BYTE *)(v56 + 5);
    Str1 = &Str1[v58 - 3];
  }
  Str1 = &Str1[v58 - 3];
  FontDrawText((GUIWindow *)v145, (Font *)v56, 150, (int)Str1, (char *)pGlobalTXT_LocalizationStrings[626], 0, 0, 0);
  Str1 = &Str1[*(_BYTE *)(v56 + 5) - 3];
  v93 = (int)pGlobalTXT_LocalizationStrings[87];
  v94 = (int)pGlobalTXT_LocalizationStrings[6];
  v95 = (int)pGlobalTXT_LocalizationStrings[240];
  v96 = (int)pGlobalTXT_LocalizationStrings[70];
  v97 = (int)pGlobalTXT_LocalizationStrings[142];
  v98 = (int)pGlobalTXT_LocalizationStrings[214];
  v99 = (int)pGlobalTXT_LocalizationStrings[29];
  v100 = (int)pGlobalTXT_LocalizationStrings[133];
  v101 = (int)pGlobalTXT_LocalizationStrings[54];
  v102 = (int)pGlobalTXT_LocalizationStrings[624];
  v104 = *(_BYTE *)(v143 + 80);
  v105 = *(_BYTE *)(v143 + 81);
  v106 = *(_BYTE *)(v143 + 82);
  v107 = *(_BYTE *)(v143 + 83);
  v108 = *(_BYTE *)(v143 + 84);
  v109 = *(_BYTE *)(v143 + 85);
  v110 = *(_BYTE *)(v143 + 86);
  v111 = *(_BYTE *)(v143 + 87);
  v61 = *(_BYTE *)(v143 + 89);
  v112 = *(_BYTE *)(v143 + 88);
  v113 = v61;
  if ( v134 )
  {
    v146 = 0;
    do
    {
      v62 = *(int *)((char *)&v104 + v146);
      if ( v62 == 200 )
      {
        v81 = (int)pGlobalTXT_LocalizationStrings[625];
      }
      else
      {
        if ( v62 )
          v81 = (int)pGlobalTXT_LocalizationStrings[627];
        else
          v81 = (int)pGlobalTXT_LocalizationStrings[153];
      }
      wsprintfA((char *)TmpBuf, (const char *)&unk_4E3308, *(int *)((char *)&v93 + v146), 0, v81);
      FontDrawText((GUIWindow *)v145, (Font *)v56, 170, (int)Str1, (char *)TmpBuf, 0, 0, 0);
      v64 = *(_BYTE *)(v56 + 5);
      v146 += 4;
      result = &Str1[v64 - 3];
      Str1 = result;
    }
    while ( v146 < 40 );
  }
  else
  {
    i = 0;
    do
    {
      wsprintfA((char *)TmpBuf, (const char *)&unk_4E3308, *(&v93 + i), 0, pGlobalTXT_LocalizationStrings[630]);
      FontDrawText((GUIWindow *)v145, (Font *)v56, 170, (int)Str1, (char *)TmpBuf, 0, 0, 0);
      v65 = *(_BYTE *)(v56 + 5);
      ++i;
      result = &Str1[v65 - 3];
      Str1 = result;
    }
    while ( i < 10 );
  }
  if (pParty_global->pPartyBuffs[3].qword_000000 > 0 )
  {
    wsprintfA((char *)TmpBuf, "%s: %d", pGlobalTXT_LocalizationStrings[650], *(_WORD *)(v143 + 40));
    GetStringWidth(pFontSmallnum, (char *)TmpBuf);
    result = GUIWindow_sub_44D406(
               (GUIWindow *)v145,
               pFontSmallnum,
               0,
               *(_DWORD *)(v145 + 12) - *(_BYTE *)(pFontSmallnum + 5) - 12,
               0,
               (char *)TmpBuf,
               3);
  }
  return result;
}

//----- (0041F50D) --------------------------------------------------------
char *__fastcall sub_41F50D(int a1, int a2, char a3)
{
  int v3; // eax@4

  if (a3 & 2 || byte_4D8410[572] && pGame->uSomeFlags & 0x040000)
  {
   v3 = 32 * a1 + a2 + 0xCCB;
   return (char *)&class35_obj + 512 * v3;
  }
  else
  {
   v3 = 32 * a1 + a2 + 0x4B;
   return (char *)&class35_obj + 512 * v3;
  }
}

//----- (0041F54A) --------------------------------------------------------
int __cdecl sub_41F54A()
{
  int result; // eax@5

  if ( dword_507BAC )
    cTexture_Free((cTexture *)dword_507BAC);
  if ( dword_507BB0 )
    cTexture_Free((cTexture *)dword_507BB0);
  LODFile_Icons_LOD.LODFile_sub_40F9C5();
  wsprintfA((char *)TmpBuf, "TERRA%03d", pParty_global->uCurrentMinute / 6u + 10 * pParty_global->uCurrentHour);
  result = 72 * LODFile_Icons_LOD.LODFile_LoadTexture( (char *)TmpBuf, 2) + 7145548;
  dword_507BAC = result;
  return result;
}

//----- (0041F5BE) --------------------------------------------------------
void __cdecl sub_41F5BE()
{
  if ( dword_506F18 < 6 )
  {
    compile_error;//dword_AD2B48 = 0;
    compile_error;//dword_AD2B4C = 0;
    compile_error;//dword_AD100C = 0;
    compile_error;//dword_AD1010 = 0;
    compile_error;//dword_ACF4D0 = 0;
    compile_error;//dword_ACF4D4 = 0;
    compile_error;//dword_ACD994 = 0;
    compile_error;//dword_ACD998 = 0;
    if ( dword_506F18 )
    {
      sub_4938D1(dword_506F18);
      dword_506F18 = 0;
      sub_41F54A();
    }
    if ( dword_506F14 == 2 )
    {
      GUIWindowDelete(pGUIWindow_CurrentMenu);
      class24_sub_426363(pClass24_global);
      if ( dword_507BAC )
        cTexture_Free((cTexture *)dword_507BAC);
      if ( dword_507BB0 )
        cTexture_Free((cTexture *)dword_507BB0);
      dword_507BB0 = 0;
      dword_507BAC = 0;
      LODFile_Icons_LOD.LODFile_sub_4114F2();
      LODFile_Icons_LOD.LODFile_sub_40F9C5();
      dword_4E28F8 = 0;
      struct_576FE8.dword_000044 = 1;
      if ( dword_6BE360 == 2 )
      {
        class51_sub_4892E6(pClass51_global);
        class51_sub_4893C1(pClass51_global);
      }
    }
    dword_506F14 = 0;
  }
  else
  {
    sub_4938D1(6u);
    dword_506F18 -= 6;
    sub_41F54A();
  }
  struct_576FE8.dword_000044 = 1;
}

//----- (0041F6C1) --------------------------------------------------------
int __cdecl sub_41F6C1()
{
  signed int v0; // eax@10
  int v1; // eax@15
  int v2; // eax@17
  int v3; // eax@19
  int result; // eax@28

  if ( !dword_506F14 )
    AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  if ( dword_4E28F8 )
  {
    GUIWindowDelete(pGUIWindow_CurrentMenu);
    dword_4E28F8 = 0;
    struct_576FE8.dword_000044 = 1;
  }
  class24_fn1(pClass24_global);
  if ( dword_506F14 != 2 )
    GUIWindowCreate(518, 450, 0, 0, 90, (int)pBtn_Game_Rest, 0);
  dword_506F18 = 0;
  dword_506F14 = 0;
  dword_506F10 = 2;
  if ( dword_6BE360 == 2 )
    dword_506F10 = sub_4893CF(pClass51_global, pParty_global->sPartyPosX, pParty_global->sPartyPosY, pParty_global->sPartyPosZ);
  if ( sub_476387() )
  {
    v0 = pParty_global->pPlayers[0].uClass;
    while ( *(_BYTE *)v0 != 31 )
    {
      v0 += 6972;
      //if ( v0 >= (signed int)&unk_AD472D )
      //  goto LABEL_15;
      compile_error; // phail
    }
    ++dword_506F10;
  }
LABEL_15:
  v1 = CheckHiredNPCSpeciality(0x1D);
  if ( v1 )
    --dword_506F10;
  v2 = CheckHiredNPCSpeciality(0x1E);
  if ( v2 )
    dword_506F10 -= 2;
  v3 = CheckHiredNPCSpeciality(0x30);
  if ( v3 )
    --dword_506F10;
  if ( dword_506F10 < 1 )
    dword_506F10 = 1;
  if ( !_strcmpi(Str1, "d29.blv") )
  {
    if ( (unsigned __int16)sub_449B57((int)pParty_global->unk_000764 + 1, 98) )
      dword_506F10 = 0;
  }
  ++LODFile_Icons_LOD.lod_IB_dword_011B9C;
  if ( !LODFile_Icons_LOD.lod_IB_dword_011B98 )
    LODFile_Icons_LOD.lod_IB_dword_011B98 = LODFile_Icons_LOD.uNumLoadedFiles;
  dword_4E28F8 = 5;
  dword_507CD4 = 0;
  dword_50765C = LODFile_Icons_LOD.LODFile_LoadTexture( "restmain", 2);
  dword_507654 = LODFile_Icons_LOD.LODFile_LoadTexture( "restb1", 2);
  dword_507658 = LODFile_Icons_LOD.LODFile_LoadTexture( "restb2", 2);
  dword_507650 = LODFile_Icons_LOD.LODFile_LoadTexture( "restb3", 2);
  dword_507648 = LODFile_Icons_LOD.LODFile_LoadTexture( "restb4", 2);
  dword_50764C = LODFile_Icons_LOD.LODFile_LoadTexture( "restexit", 2);
  sub_41F54A();
  pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 16, 0, 0);
  dword_507638 = GUIButtonCreate(pGUIWindow_CurrentMenu,
                   280,
                   297,
                   154,
                   37,
                   1,
                   0,
                   167,
                   0,
                   0,
                   (unsigned char *)"",
                   dword_50764C != -1 ? &LODFile_Icons_LOD.aLODHeaders[dword_50764C] : 0);
  dword_507634 = GUIButtonCreate(pGUIWindow_CurrentMenu,
                   24,
                   154,
                   225,
                   37,
                   1,
                   0,
                   97,
                   0,
                   82,
                   (unsigned char *)"",
                   dword_507648 != -1 ?  &LODFile_Icons_LOD.aLODHeaders[dword_507648] : 0);
  dword_507640 = GUIButtonCreate(pGUIWindow_CurrentMenu,
                   61,
                   232,
                   154,
                   33,
                   1,
                   0,
                   109,
                   0,
                   68,
                   (unsigned char *)"",
                   dword_507654 != -1 ?  &LODFile_Icons_LOD.aLODHeaders[dword_507654] : 0);
  dword_507644 = GUIButtonCreate(pGUIWindow_CurrentMenu,
                   61,
                   264,
                   154,
                   33,
                   1,
                   0,
                   96,
                   0,
                   72,
                   (unsigned char *)"",
                   dword_507658 != -1 ?  &LODFile_Icons_LOD.aLODHeaders[dword_507658] : 0);
  result = (int)GUIButtonCreate(
             pGUIWindow_CurrentMenu,
             61,
             296,
             154,
             33,
             1,
             0,
             95,
             0,
             77,
             (unsigned char *)"",
             dword_507650 != -1 ?  &LODFile_Icons_LOD.aLODHeaders[dword_507650] : 0);
  dword_50763C = (GUIButton *)result;
  return result;
}

//----- (0041FA01) --------------------------------------------------------
void __cdecl sub_41FA01()
{
  signed int v0; // ecx@1
  int v1; // esi@1
  int v2; // eax@2
  int v3; // eax@15
  char v4; // cf@15
  char v5; // al@17
  bool v6; // eax@21

  struct GUIButton local_08;
  //int Dst; // [sp+8h] [bp-DCh]@19
  //int v8; // [sp+Ch] [bp-D8h]@19
  //int v9; // [sp+10h] [bp-D4h]@19
  //int v10; // [sp+14h] [bp-D0h]@19
  //int v11; // [sp+18h] [bp-CCh]@19
  //int v12; // [sp+1Ch] [bp-C8h]@19
  //int v13; // [sp+40h] [bp-A4h]@19

  double v14; // [sp+C4h] [bp-20h]@17
  float v15; // [sp+CCh] [bp-18h]@17
  __int64 v16; // [sp+D0h] [bp-14h]@17
  int v17; // [sp+D8h] [bp-Ch]@9
  __int16 v18[2]; // [sp+DCh] [bp-8h]@1
  int v19; // [sp+E0h] [bp-4h]@1

  v1 = 0;
  v19 = 0xFF0A0000;
  *(_DWORD *)v18 = 0xFFE6D6C1;
  v0 = (signed int)pPlayers;
  do
  {
    v2 = *(_DWORD *)v0;
    if ( !*(_QWORD *)(*(_DWORD *)v0 + 112) )
    {
      if ( !*(_QWORD *)(v2 + 128) )
      {
        if ( *(_DWORD *)(v2 + 6460) > 0 )
          ++v1;
      }
    }
    v0 += 4;
  }
  while ( v0 <= (signed int)&dword_A750D4 );
  if ( v1 )
  {
    Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (cTexture *)(dword_50765C != -1 ? 72 * dword_50765C + 7145548 : 0));
    v17 = pParty_global->uCurrentHour;
    dword_506F1C = *(_DWORD *)(pGUIWindow_CurrentMenu + 44);
    if ( pParty_global->uCurrentHour <= 12 )
    {
      if ( !v17 )
        v17 = 12;
    }
    else
    {
      v17 -= 12;
    }
    Render_DrawIndexedTexture(pD3DRenderer, 16, 26, (cTexture *)dword_507BAC);
    if ( dword_507BB0 )
    {
      cTexture_Free((cTexture *)dword_507BB0);
      LODFile_Icons_LOD.LODFile_sub_40F9C5();
    }
    v3 = pClass24_global->int_00001C + dword_507CD4;
    v4 = (unsigned int)(pClass24_global->int_00001C + dword_507CD4) < 0x200;
    dword_507CD4 += pClass24_global->int_00001C;
    if ( !v4 )
    {
      v3 = 0;
      dword_507CD4 = 0;
    }
    v16 = (unsigned int)v3;
    v15 = (double)(unsigned int)v3 * 0.001953125 * 120.0;
    v14 = v15 + 6.755399441055744e15;
    HIDWORD(v16) = LODWORD(v14);
    v5 = LOBYTE(v14) + 1;
    byte_4E2BC8 = LOBYTE(v14) + 1;
    if ( (unsigned __int8)(LOBYTE(v14) + 1) >= 0x78u )
    {
      v5 = 1;
      byte_4E2BC8 = 1;
    }
    wsprintfA((char *)TmpBuf, "hglas%03d", (unsigned __int8)v5);
    dword_507BB0 =(int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( (char *)TmpBuf, 2)];
    Render_DrawIndexedTexture(pD3DRenderer, 267, 159, (cTexture *)dword_507BB0);

    memset(&local_08, 0, sizeof(GUIButton));
    local_08.uX = 24;
    local_08.uY = 154;
    local_08.uWidth = 171;
    local_08.uHeight = 37;
    local_08.uZ = 194;
    local_08.uW = 190;
    local_08.pParentWindow = dword_507640->pParentWindow;
    GUIButton_sub_415180(&local_08, pGlobalTXT_LocalizationStrings[183], pFontCreate, v19, *(char **)v18);
    local_08.pParentWindow = 0;

    wsprintfA((char *)TmpBuf, "\r408%d", dword_506F10);
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, 0, 164, (char *)TmpBuf, 0, 0, *(unsigned int *)v18);
    GUIButton_sub_415180(dword_507640, pGlobalTXT_LocalizationStrings[237], pFontCreate, v19, *(char **)v18);
    GUIButton_sub_415180(dword_507644, pGlobalTXT_LocalizationStrings[239], pFontCreate, v19, *(char **)v18);
    GUIButton_sub_415180(dword_50763C, pGlobalTXT_LocalizationStrings[238], pFontCreate, v19, *(char **)v18);
    GUIButton_sub_415180(dword_507638, pGlobalTXT_LocalizationStrings[81], pFontCreate, v19, *(char **)v18);

    memset(&local_08, 0, sizeof(GUIButton));
    local_08.uX = 45;
    local_08.uY = 199;
    local_08.uWidth = 185;
    local_08.uHeight = 30;
    local_08.uZ = 229;
    local_08.uW = 228;
    local_08.pParentWindow = dword_507640->pParentWindow;
    GUIButton_sub_415180(&local_08, pGlobalTXT_LocalizationStrings[236], pFontCreate, v19, *(char **)v18);
    local_08.pParentWindow = 0;

    v6 = (unsigned int)pParty_global->uCurrentHour >= 0xC && (unsigned int)pParty_global->uCurrentHour < 0x18;
    wsprintfA((char *)TmpBuf, "%d:%02d %s", v17, pParty_global->uCurrentMinute, aAMPMNames[v6]);
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, 368, 168, (char *)TmpBuf, 0, 0, *(unsigned int *)v18);
    wsprintfA((char *)TmpBuf, "%s\r190%d", pGlobalTXT_LocalizationStrings[56], pParty_global->uDaysPlayed + 1);
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, 350, 190, (char *)TmpBuf, 0, 0, *(unsigned int *)v18);
    wsprintfA((char *)TmpBuf, "%s\r190%d", pGlobalTXT_LocalizationStrings[146], pParty_global->uCurrentMonth + 1);
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, 350, 222, (char *)TmpBuf, 0, 0, *(unsigned int *)v18);
    wsprintfA((char *)TmpBuf, "%s\r190%d", pGlobalTXT_LocalizationStrings[245], pParty_global->uCurrentYear);
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, 350, 254, (char *)TmpBuf, 0, 0, *(unsigned int *)v18);
    if ( dword_506F14 )
      sub_41F5BE();
  }
  else
  {
    GUIWindowCreate(*(_DWORD *)dword_507638, *(_DWORD *)(dword_507638 + 4), 0, 0, 96, (int)dword_507638, (int)pGlobalTXT_LocalizationStrings[81]);
  }
}

//----- (0041FE71) --------------------------------------------------------
signed int __fastcall sub_41FE71(signed int a1, int a2, int a3)
{
  signed int v3; // eax@1
  int v4; // ecx@1
  int v5; // eax@1
  int v6; // eax@1
  signed int v7; // eax@3
  int v8; // edi@3
  signed int v9; // edi@3
  int v10; // ebx@5
  int v11; // esi@9
  int v12; // edx@10
  int v13; // ecx@11
  int v14; // eax@12
  int v16; // [sp+Ch] [bp-Ch]@1
  signed int v17; // [sp+10h] [bp-8h]@1
  signed int v18; // [sp+14h] [bp-4h]@1

  v17 = a1;
  v5 = 4 * array_5E5150[a3].word_000000;
  v16 = *(int *)((char *)dword_4E2C2C + v5);
  v18 = *(int *)((char *)dword_4E2C0C + v5);
  v6 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)pClass40->pItems[a2].pIconName, 2);
  v4 = v6 != -1 ? 72 * v6 + 7145548 : 0;
  v3 = *(_WORD *)(v6 != -1 ? 72 * v6 + 7145548 + 0x18 : 24);
  if ( v3 < 14 )
    v3 = 14;
  v9 = v3 - 14;
  v7 = *(_WORD *)(v4 + 26);
  v8 = (v9 >> 5) + 1;
  if ( v7 < 14 )
    v7 = 14;
  v10 = ((v7 - 14) >> 5) + 1;
  if ( !bTextureLoading )
  {
    cTexture_Free((cTexture *)v4);
    LODFile_Icons_LOD.LODFile_sub_40F9C5();
  }
  if ( v8 + v17 % v18 <= v18 && v10 + v17 / v18 <= v16 )
  {
    v11 = 0;
    if ( v10 <= 0 )
      return 1;
    v12 = 0;
    while ( 1 )
    {
      v13 = 0;
      if ( v8 > 0 )
        break;
LABEL_15:
      v12 += v18;
      ++v11;
      if ( v11 >= v10 )
        return 1;
    }
    v14 = 2 * (v17 + v12 + 2662 * a3) + 6186244;
    while ( !*(_WORD *)v14 )
    {
      ++v13;
      v14 += 2;
      if ( v13 >= v8 )
        goto LABEL_15;
    }
  }
  return 0;
}

//----- (0041FF64) --------------------------------------------------------
signed int __fastcall sub_41FF64(int a1)
{
  signed int result; // eax@1
  int v2; // edx@1
  int v3; // ecx@1
  char *v4; // ecx@2

  v3 = 5324 * a1;
  result = 0;
  v2 = dword_4E2C0C[*(__int16 *)((char *)array_5E5150 + v3)] * dword_4E2C2C[*(__int16 *)((char *)array_5E5150 + v3)];
  if ( v2 <= 0 )
  {
LABEL_5:
    result = -1;
  }
  else
  {
   v4 = (char *)array_5E5150[a1].array_000004;
    while ( *(_DWORD *)v4 )
    {
      ++result;
      v4 += 36;
      if ( result >= v2 )
        goto LABEL_5;
    }
  }
  return result;
}

//----- (0047A384) --------------------------------------------------------
void sub_47A384(const char *pLevelFilename, void *a2)
{
  signed int v2; // eax@3
  int v3; // ebx@3
  int v4; // edi@4
  int v5; // eax@8
  int v6; // edx@14
  size_t v8; // eax@19
  char Source[120]; // [sp+Ch] [bp-84h]@19
  int v13; // [sp+88h] [bp-8h]@12
  int v14; // [sp+8Ch] [bp-4h]@11
 int i;

  AllocateDrawBuffers(a2);
  sub_485F64(pStruct9_global);
  dword_6BE024 = 0;
  Render_ClearZBuffer(pD3DRenderer, 0, 479);
  a2 = (void *)1;
  sub_450DA3();
  if ( qword_A750D8 )
    qword_A750D8 = 0i64;
  v3 = CMapStats_FindLocation(pMapStats, Str1);

  if ( v3 )
  {
   v4 = (int)&pMapStats->pMapInfos[v3];
   v2 = pMapStats->pMapInfos[v3].uRespawnInterval;
  }
  else
  {
   v4 = 1;
   v2 = 0;
  }
  dword_6BE030 &= 0xFFFFFFFEu;
  dword_6BE13C = v3;

  memset(pClass51_global, 0, sizeof(struct class51));
  LoadLevel(pClass51_global,
    pLevelFilename,
    (unsigned int)(signed __int64)((double)pParty_global->qword_00002C * 0.234375) / 0x3C / 0x3C / 0x18 + 1,
    v2,
    (int)&a2);

  if ( !(dword_6BE364 & 0x2000) )
  {
    UpdateActors();
    sub_408896();
  }
  dword_6BE364 &= 0xFFFFDFFF; //clear 0x4000 flag
  v5 = 0;
  if ( !v3 )
    a2 = 0;
  if ( a2 == (void *)1 )
  {
    v14 = 0;
    if ( dword_6A12B0 > 0 )
    {
      v13 = 0;
      while ( 1 )
      {
        v6 = dword_6A12B4 + v13;
        if ( *(_WORD *)(dword_6A12B4 + v13 + 14) == 3 )
          sub_44F57C_MaybeCreateRandomMonster(v4, v6, v5, v5, v5);
        else
          sub_44FFD8(v4, v6);
        ++v14;
        v13 += 24;
        if ( v14 >= dword_6A12B0 )
          break;
        v5 = 0;
      }
    }
    sub_450AAA();
  }



  sub_47F138();
  sub_47F223_LooksLikeGenerateMonsterLoot(pClass51_global);
  InitializeActors(v3);
  class51_sub_48917E((int)pClass51_global);
  v8 = strlen("levels\\");
  strcpy(Source, &pLevelFilename[v8]);
  strcpy((char *)pClass51_global->string_000000, Source);
  sub_4C2EA0(&struct_6BD080);

  pOldCamera->sRotationX = pParty_global->sRotationX;
  pOldCamera->sRotationY = pParty_global->sRotationY;

  struct9_sub_47A59E_ComputeSinCos(pStruct9_global);
  class51_sub_4892E6(pClass51_global);
  pStruct9_global->dword_000014 = pOldCamera->flt_00001C;
  pStruct9_global->dword_000018 = pOldCamera->flt_000020;

 pClass57_global = new class57;
 memset(pClass57_global, 0, sizeof(struct class57));

 for (i = 0; i < 2000; ++i)
 {
  array_77EC08[i].word_000030 = 0;
  array_77EC08[i].word_000032 = 0;
  array_77EC08[i].ptr_000038 = pClass57_global;
  array_77EC08[i].ptr_000040 = 0;
  array_77EC08[i].ptr_000044 = 0;
 }

 sub_4666D5();
}

//----- (0041FFA2) --------------------------------------------------------
int __fastcall sub_41FFA2(int a1, struct ItemGen *a2, int a3)
{
  int *v3; // edi@1
  int v4; // esi@1
  int v5; // eax@1
  int result; // eax@11
  signed int v7; // eax@12
  int v8; // edx@12
  int v9; // ecx@12
  int v10; // eax@12
  signed int v11; // edi@14
  unsigned int v12; // esi@14
  int v13; // edi@16
  int i; // ecx@21
  int v15; // edi@21
  void *v16; // edi@21
  const void *v18; // [sp+Ch] [bp-18h]@1
  signed int v19; // [sp+10h] [bp-14h]@2
  int v20; // [sp+14h] [bp-10h]@1
  int v21; // [sp+18h] [bp-Ch]@19
  signed int v22; // [sp+1Ch] [bp-8h]@1
  signed int v23; // [sp+20h] [bp-4h]@3
  int v24; // [sp+20h] [bp-4h]@19

  v22 = 0;
  v5 = 4 * array_5E5150[a3].word_000000;
  v3 = (int *)a2;
  v4 = *(int *)((char *)dword_4E2C0C + v5) * *(int *)((char *)dword_4E2C2C + v5);
  v18 = a2;
  v20 = *(int *)((char *)dword_4E2C0C + v5);
  if ( a1 == -1 )
  {
    v19 = sub_41FF64(a3);
    if ( v19 == -1 )
      return 0;
    v23 = 0;
    if ( v4 > 0 )
    {
      while ( !sub_41FE71(v23, *v3, *(_DWORD *)(dword_507BB8 + 28)) )
      {
        ++v23;
        if ( v23 >= v4 )
          goto LABEL_8;
      }
      v22 = v23;
    }
LABEL_8:
    if ( v23 == v4 )
    {
      if ( uActiveCharacter )
        Player_PlaySound(*(&ptr_A750C4 + uActiveCharacter), 15, 0);
      return 0;
    }
    v10 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)pClass40->pItems[*v3].pIconName, 2);
    HIWORD(v8) = 0;
    v9 = v10 != -1 ? 72 * v10 + 7145548 : 0;
    v7 = *(_WORD *)(v10 != -1 ? 72 * v10 + 7145548 + 0x18 : 24);
    if ( v7 < 14 )
      v7 = 14;
    v11 = *(_WORD *)(v9 + 26);
    v12 = ((v7 - 14) >> 5) + 1;
    if ( v11 < 14 )
      v11 = 14;
    v13 = ((v11 - 14) >> 5) + 1;
    if ( !bTextureLoading )
    {
      cTexture_Free((cTexture *)v9);
      LODFile_Icons_LOD.LODFile_sub_40F9C5();
    }
    if ( v13 > 0 )
    {
      v24 = 0;
      v21 = v13;
      do
      {
        if ( (signed int)v12 > 0 )
        {
          v16 = (void *)(2 * (v22 + v24 + 2662 * a3) + 6186244);
          LOWORD(v8) = -1 - v22;
          v8 <<= 16;
          LOWORD(v8) = -1 - v22;
          memset_dw(v16, v8, 4 * (v12 >> 1));
          v15 = (int)((char *)v16 + 4 * (v12 >> 1));
          for ( i = 2 * (v12 & 1); i; --i )
          {
            *(_WORD *)v15 = v8;
            v15 += 2;
          }
        }
        v24 += v20;
      }
      while ( v21-- != 1 );
    }
    //word_5E6504[v22 + 2662 * a3] = v19 + 1;
    ((short *)((char *)&array_5E5150[a3] + 0x13B4))[v22] = v19 + 1;

    memcpy(&array_5E5150[a3].array_000004[v19], v18, sizeof(struct ItemGen));
    result = v22 + 1;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0046080D) --------------------------------------------------------
int __cdecl sub_46080D()
{
  int result; // eax@1
    result=0;
  mem_mng.DeleteBuffer( (void *)dword_6A0D08);
  dword_6A0D08 = 0;
  dword_6A0D0C = 0;
  return result;
}

//----- (0042013E) --------------------------------------------------------
int __fastcall sub_42013E(int a1, int a2, int a3)
{
  int v3; // ebx@1
  signed int v4; // edi@1
  int v5; // esi@1
  int v6; // edx@4
  signed int v7; // eax@5
  int v8; // ecx@5
  int v9; // eax@5
  unsigned int v10; // ebx@7
  signed int v11; // edi@7
  int v12; // edi@9
  int v13; // edx@12
  int i; // ecx@14
  int v15; // edi@14
  void *v16; // edi@14
  int result; // eax@18
  __int16 v19; // [sp+Ch] [bp-10h]@1
  int v20; // [sp+10h] [bp-Ch]@11
  int v21; // [sp+14h] [bp-8h]@12
  int v22; // [sp+18h] [bp-4h]@1

  v5 = 5324 * a3;
  v22 = a1;
  v3 = 5324 * a3 + 36 * a2;
  v19 = a2;
  v4 = array_5E5150[a3].array_000004[a2].uItemID;
  class40_sub_456D17(pClass40, &array_5E5150[a3].array_000004[a2]);
  if ( v4 >= 135 )
  {
    if ( v4 <= 159 )
    {
      //if ( !*(int *)((char *)&dword_5E5164 + v3) )
      if (!array_5E5150[a3].array_000004[a2].dword_000010)
      {
        v6 = rand() % 21 + 10;
        //*(int *)((char *)&dword_5E5164 + v3) = v6;
        array_5E5150[a3].array_000004[a2].dword_000010 = v6;
        *((char *)&array_5E5150[v3/5324] + 0x1D) = v6;
      }
    }
  }
  v9 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)pClass40->pItems[v4].pIconName, 2);
  v8 = v9 != -1 ? 72 * v9 + 7145548 : 0;
  v7 = *(_WORD *)(v9 != -1 ? 72 * v9 + 7145548 + 0x18 : 24);
  if ( v7 < 14 )
    v7 = 14;
  v11 = *(_WORD *)(v8 + 26);
  v10 = ((v7 - 14) >> 5) + 1;
  if ( v11 < 14 )
    v11 = 14;
  v12 = ((v11 - 14) >> 5) + 1;
  if ( !bTextureLoading )
  {
    cTexture_Free((cTexture *)v8);
    LODFile_Icons_LOD.LODFile_sub_40F9C5();
  }
  v20 = dword_4E2C0C[*(__int16 *)((char *)array_5E5150 + v5)];
  if ( v12 > 0 )
  {
    v13 = 0;
    v21 = v12;
    do
    {
      if ( (signed int)v10 > 0 )
      {
        v16 = (void *)(2 * (v22 + v13 + 2662 * a3) + 6186244);
        LOWORD(v5) = -1 - v22;
        v5 <<= 16;
        LOWORD(v5) = -1 - v22;
        memset_dw(v16, v5, 4 * (v10 >> 1));
        v15 = (int)((char *)v16 + 4 * (v10 >> 1));
        for ( i = 2 * (v10 & 1); i; --i )
        {
          *(_WORD *)v15 = v5;
          v15 += 2;
        }
      }
      v13 += v20;
    }
    while ( v21-- != 1 );
  }
  result = v22 + 2662 * a3;
  //word_5E6504[result] = v19 + 1;
    ((short *)((char *)&array_5E5150[a3] + 0x13B4))[v22] = v19 + 1;
  return result;
}

//----- (00420284) --------------------------------------------------------
char *__fastcall sub_420284(int a1)
{
  int v1; // ebx@1
  int v2; // edi@1
  int v3; // esi@1
  int v4; // esi@1
  int v5; // eax@2
  int v6; // ebx@11
  char *result; // eax@18
  char Dst[144]; // [sp+Ch] [bp-A0h]@1
  int v9; // [sp+9Ch] [bp-10h]@10
  int v10; // [sp+A0h] [bp-Ch]@1
  int v11; // [sp+A4h] [bp-8h]@8
  int v12; // [sp+A8h] [bp-4h]@9

  v1 = 0;
  v4 = a1;
  v10 = a1;
  Render_ClearZBuffer(pD3DRenderer, 0, 479);
  v3 = 5324 * v4;
  v2 = dword_4E2C0C[*(__int16 *)((char *)array_5E5150 + v3)] * dword_4E2C2C[*(__int16 *)((char *)array_5E5150 + v3)];
  memset(Dst, 0, 0x90u);
  if ( v2 > 0 )
  {
    do
    {
      do
        v5 = (unsigned __int8)rand();
      while ( v5 >= v2 );
      while ( Dst[v5] )
      {
        ++v5;
        if ( v5 == v2 )
          v5 = 0;
      }
      Dst[v5] = v1++;
    }
    while ( v1 < v2 );
  }
  v11 = 0;
  if ( v2 > 0 )
  {
   v12 = array_5E5150[v4].array_000004[0].dword_000014;//(int)((char *)&unk_5E5168 + v3);
    do
    {
      v9 = *(_DWORD *)(v12 - 20);
      if ( v9 )
      {
        v6 = 0;
        while ( !sub_41FE71((unsigned __int8)Dst[v6], v9, v10) )
        {
          ++v6;
          if ( v6 >= v2 )
            goto LABEL_17;
        }
        sub_42013E((unsigned __int8)Dst[v6], v11, v10);
        if (array_5E5150[v3/5324].word_000002 & 0x0004)
          *(_DWORD *)v12 |= 1u;
      }
LABEL_17:
      ++v11;
      v12 += 36;
    }
    while ( v11 < v2 );
  }
  result = (char *)&array_5E5150[v3/5324].word_000002;
  array_5E5150[v3/5324].word_000002 = array_5E5150[v3/5324].word_000002 & 0xFFFB | 2;
  return result;
}

//----- (0042038D) --------------------------------------------------------
void __cdecl sub_42038D()
{
  int v0; // ecx@2
  int v1; // esi@2
  int v2; // eax@3
  char v3; // [sp+0h] [bp-10h]@2
  char v4; // [sp+8h] [bp-8h]@1

  if ( *(_DWORD *)(class03_GetMousePos(pGame->pClass03, (POINT *)&v4) + 4) < 350 )
  {
    v1 = (int)class03_GetMousePos(pGame->pClass03, (POINT *)&v4);
    v0 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer
                   + 4 * (*(_DWORD *)v1 + dword_5059A8[*(_DWORD *)(class03_GetMousePos(pGame->pClass03, (POINT *)&v3) + 4)]));
    if ( v0 )
    {
      v2 = ItemGen_sub_456499((char *)&dword_5E5130[1331 * *(_DWORD *)(dword_507BB8 + 28)] +
                      //36 * word_5E6502[v0 + 2662 * *(_DWORD *)(dword_507BB8 + 28)]);
                      36 * ((short *)((char *)&array_5E5150[*(_DWORD *)(dword_507BB8 + 28)] + 0x13B2))[v0]);

      sub_41C0B8((const char *)v2);
    }
  }
}

//----- (0042041E) --------------------------------------------------------
signed int __fastcall sub_42041E(int a1)
{
  char *v1; // edi@5
  signed int v2; // eax@8
  int v4; // eax@15
  int v5; // eax@16
  int v6; // edx@16
  int v7; // eax@19
  int v8; // edx@19
  int v9; // ecx@19
  signed int v10; // ebx@19
  int v11; // edi@19
  int v12; // eax@19
  int v13; // eax@20
  int v14; // ebx@21
  int v15; // edi@21
  int v16; // ecx@22
  __int64 v17; // qax@22
  double v18; // st7@23
  double v19; // st6@23
  double v20; // st7@23
  int v21; // ecx@26
  int v22; // ecx@28
  __int16 v23; // di@28
  int *v24; // edi@28
  int v25; // edx@29
  __int16 v26; // ax@32
  __int16 v27; // [sp+14h] [bp-B0h]@28
  __int16 v28; // [sp+16h] [bp-AEh]@33
  int v29; // [sp+18h] [bp-ACh]@33
  int v30; // [sp+1Ch] [bp-A8h]@33
  int v31; // [sp+20h] [bp-A4h]@33
  __int16 v32; // [sp+2Ah] [bp-9Ah]@33
  __int16 v33; // [sp+2Ch] [bp-98h]@33
  __int16 v34; // [sp+2Eh] [bp-96h]@33
  __int16 v35; // [sp+30h] [bp-94h]@33
  __int16 v36; // [sp+32h] [bp-92h]@33
  char v37; // [sp+38h] [bp-8Ch]@28
  int v38; // [sp+5Ch] [bp-68h]@28
  int v39; // [sp+60h] [bp-64h]@28
  int v40; // [sp+64h] [bp-60h]@28
  int v41; // [sp+68h] [bp-5Ch]@28
  int v42; // [sp+6Ch] [bp-58h]@33
  int v43; // [sp+70h] [bp-54h]@33
  int v44; // [sp+84h] [bp-40h]@16
  int v45; // [sp+88h] [bp-3Ch]@16
  int v46; // [sp+8Ch] [bp-38h]@16
  int v47; // [sp+90h] [bp-34h]@16
  float v48; // [sp+94h] [bp-30h]@23
  char *v49; // [sp+98h] [bp-2Ch]@5
  int v50; // [sp+9Ch] [bp-28h]@16
  int v51; // [sp+A0h] [bp-24h]@28
  int v52; // [sp+A4h] [bp-20h]@28
  int v53; // [sp+A8h] [bp-1Ch]@28
  float v54; // [sp+ACh] [bp-18h]@1
  int v55; // [sp+B0h] [bp-14h]@21
  int v56; // [sp+B4h] [bp-10h]@23
  float v57; // [sp+B8h] [bp-Ch]@23
  float v58; // [sp+BCh] [bp-8h]@23
  int X; // [sp+C0h] [bp-4h]@8

  LODWORD(v54) = a1;
  if ( a1 < 0 )
    return 0;
  if ( a1 >= 20 )
    return 0;
  ++LODFile_Icons_LOD.lod_IB_dword_011B9C;
  if ( !LODFile_Icons_LOD.lod_IB_dword_011B98 )
    LODFile_Icons_LOD.lod_IB_dword_011B98 = LODFile_Icons_LOD.uNumLoadedFiles;
  v1 = (char *)&array_5E5150[a1].word_000002;
  v49 = v1;
  if ( !(*v1 & 2) )
    sub_420284(a1);
  if ( !uActiveCharacter )
    return 0;
  X = 0;
  v2 = CMapStats_FindLocation(pMapStats, Str1);
  if ( !(*v1 & 1) || !v2 )
    goto LABEL_12;
  if ( sub_4912B0(*(&ptr_A750C4 + uActiveCharacter)) < 2 * pMapStats->pMapInfos[v2].byte_00002C)
  {
    v44 = 811;
    v45 = 812;
    v46 = 813;
    v47 = 814;
    v6 = rand() % 4;
    v5 = dword_5B5920 >> 3;
    v50 = v6;
    if ( (dword_5B5920 & 7) == 5 )
    {
      v16 = 32 * v5;
      v14 = pLevelDecorations[v5].sPosX;
      v55 = pLevelDecorations[v5].sPosY;
      v17 = *(_WORD *)((char *)&pDecorationDescriptionList->pDescriptions[pLevelDecorations[v5].uDecorationDescriptionID] + 66);
      v15 = pLevelDecorations[v5].sPosZ + (((_DWORD)v17 - HIDWORD(v17)) >> 1);
    }
    else
    {
      if ( (dword_5B5920 & 7) != 6 )
        goto LABEL_12;
      if ( dword_6BE360 == 2 )
      {
        v12 = *(_DWORD *)(188 * (dword_5B5920 >> 9) + pClass51_global->pBModels + 84) + 308 * ((dword_5B5920 >> 3) & 0x3F);
        v8 = *(_WORD *)(v12 + 282);
        v11 = *(_WORD *)(v12 + 288);
        v10 = *(_WORD *)(v12 + 278) + *(_WORD *)(v12 + 280);
        v9 = *(_WORD *)(v12 + 284);
        v7 = *(_WORD *)(v12 + 286);
      }
      else
      {
        v13 = dword_6BE644 + 96 * v5;
        v8 = *(_WORD *)(v13 + 84);
        v11 = *(_WORD *)(v13 + 90);
        v10 = *(_WORD *)(v13 + 80) + *(_WORD *)(v13 + 82);
        v9 = *(_WORD *)(v13 + 86);
        v7 = *(_WORD *)(v13 + 88);
      }
      v14 = v10 >> 1;
      v55 = (v8 + v9) >> 1;
      v15 = (v7 + v11) >> 1;
    }
    v18 = (double)pParty_global->sPartyPosX - (double)v14;
    v54 = v18;
    v19 = (double)pParty_global->sPartyPosY - (double)v55;
    v48 = v19;
    v58 = (double)pParty_global->uEyelevel + (double)pParty_global->sPartyPosZ - (double)v15;
    *(float *)&X = v19 * v19;
    *(float *)&v56 = v18 * v18;
    v20 = sqrt(v58 * v58 + *(float *)&v56 + *(float *)&X);
    v57 = v20;
    if ( v20 <= memory_4D8410.d1_0 )
    {
      v56 = 0;
      X = 0;
    }
    else
    {
      X = (signed __int64)sqrt(*(float *)&v56 + *(float *)&X);
      v56 = class59_Atan2(pClass59_global, (signed __int64)v54, (signed __int64)v48);
      X = class59_Atan2(pClass59_global, X, (signed __int64)v58);
    }
    v21 = 256;
    if ( v57 < 256.0 )
      v21 = (signed __int64)v57 / 4;
    sub_43AA99(v21, v56, X, v14, v55, v15, (int)&v51, (int)&v53, (int)&v52);
    v24 = &v44 + v50;
    sub_42F7EB(*v24, v51, v53, v52, 0, 1, 0, 48, 0);
    sub_404828(&v27);
    ItemGen_Reset((ItemGen *)&v37);
    v23 = *(_WORD *)v24;
    v22 = 0;
    v40 = 0;
    v39 = 0;
    v38 = 0;
    v41 = 0;
    v27 = v23;
    if ( pObjectDescriptionList->uNumObjects <= 0 )
    {
LABEL_32:
      v26 = 0;
    }
    else
    {
      v25 = (int)pObjectDescriptionList->pDescriptions + 32;
      while ( v23 != *(_WORD *)v25 )
      {
        ++v22;
        v25 += 56;
        if ( v22 >= pObjectDescriptionList->uNumObjects )
          goto LABEL_32;
      }
      v26 = v22;
    }
    v28 = v26;
    v30 = v53;
    v29 = v51;
    v31 = v52;
    v33 = 0;
    v34 = 48;
    v35 = sub_49AC17((int)byte_6BE3C8, v51, v53, v52);
    v36 = 0;
    v42 = 0;
    v43 = 0;
    v32 = 0;
    sub_42F5ED((int)&v27, 0, 0, 0, 0);
    AudioPlayer_sub_4AA306(pAudioPlayer, 8, 0, 0, -1, 0, 0, 0, 0);
    sub_438E35(&v27);
    *v49 &= 0xFEu;
    if ( uActiveCharacter )
    {
      if ( !qword_A750D8 )
      {
        if ( !dword_507CD8 )
        {
          qword_A750D8 = 256i64;
          word_A750E0 = 5;
          word_A750E2 = uActiveCharacter;
        }
      }
    }
    LODFile_Icons_LOD.LODFile_sub_4114F2();
    dword_507CD8 = 0;
    return 0;
  }
  *v1 &= 0xFEu;
  X = 1;
LABEL_12:
  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  AudioPlayer_sub_4AA306(pAudioPlayer, 208, 0, 0, -1, 0, 0, 0, 0);
  if ( X )
  {
    if ( !dword_507CD8 )
      Player_PlaySound(*(&ptr_A750C4 + uActiveCharacter), 4, 0);
  }
  dword_507CD8 = 0;
  v4 = (int)GUIWindowCreate(0, 0, 640, 480, 20, SLODWORD(v54), 0);
  pGUIWindow_CurrentMenu = (GUIWindow *)v4;
  dword_507BB8 = v4;
  dword_5076F4 = GUIButtonCreate(
                   (GUIWindow *)v4,
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
  GUIButtonCreate((GUIWindow *)dword_507BB8, 7, 8, 460, 343, 1, 0, 12, 0, 0, (unsigned char *)"", 0);
  dword_4E28F8 = 10;
  class24_fn1(pClass24_global);
  return 1;
}

//----- (0042092D) --------------------------------------------------------
void __fastcall sub_42092D(int a1)
{
  int v1; // ebx@1
  int v2; // edi@1
  int v3; // ebx@1
  int v4; // eax@1
  int v5; // eax@1
  int v6; // ecx@3
  signed int v7; // eax@4
  signed int v8; // edx@4
  signed int v9; // ecx@4
  int v10; // esi@4
  int v11; // eax@4
  int v12; // eax@6
  int v13; // eax@6
  int v14; // ST34_4@8
  int v15; // edi@8
  int v16; // [sp+Ch] [bp-28h]@1
  int v17; // [sp+14h] [bp-20h]@1
  signed int v18; // [sp+18h] [bp-1Ch]@1
  int v19; // [sp+1Ch] [bp-18h]@1
  signed int v20; // [sp+20h] [bp-14h]@1
  char *v21; // [sp+2Ch] [bp-8h]@2
  signed int v22; // [sp+30h] [bp-4h]@1

  v2 = (int)pD3DRenderer;
  v3 = a1;
  v16 = (int)pD3DRenderer->pActiveZBuffer;
  Render_ClearZBuffer(pD3DRenderer, 0, 479);
  v1 = 5324 * v3;
  v4 = 4 * *(__int16 *)((char *)array_5E5150 + v1);
  v19 = *(int *)((char *)&dword_4E2BCC + v4);
  v17 = *(int *)((char *)&dword_4E2BEC + v4);
  v20 = *(int *)((char *)dword_4E2C0C + v4);
  v18 = *(int *)((char *)dword_4E2C2C + v4);
  wsprintfA((char *)TmpBuf, "chest%02d", *(_WORD *)(chest_descriptor[1] + 36 * *(__int16 *)((char *)array_5E5150 + v1) + 34));
  v5 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)TmpBuf, 2);
  Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (cTexture *)(v5 != -1 ? 72 * v5 + 7145548 : 0));
  v22 = 0;
  if ( v20 * v18 > 0 )
  {
    //v21 = (char *)word_5E6504 + v1;
    v21 = (char *)&array_5E5150[v3] + 0x13B4;
    do
    {
      v6 = *(_WORD *)v21;
      if ( v6 > 0 )
      {
        v11 = LODFile_Icons_LOD.LODFile_LoadTexture(
                (char *)pClass40->pItems[12 * *(int *)((char *)&dword_5E5130[9 * v6] + v1)].pIconName,
                2);
        v10 = v11 != -1 ? 72 * v11 + 7145548 : 0;
        v9 = *(_WORD *)(v11 != -1 ? 72 * v11 + 7145548 + 0x18 : 24);
        v8 = *(_WORD *)(v11 != -1 ? 72 * v11 + 7145548 + 0x1A : 26);
        v7 = *(_WORD *)(v11 != -1 ? 72 * v11 + 7145548 + 0x18 : 24);
        if ( v9 < 14 )
          v7 = 14;
        v13 = v7 - 14;
        LOBYTE(v13) = v13 & 0xE0;
        v12 = v13 + 32;
        if ( (signed int)*(_WORD *)(v10 + 26) < 14 )
          v8 = 14;
        v14 = v19 + 32 * v22 % v20 + ((v12 - v9) >> 1);
        v15 = v17 + 32 * v22 / v18 + ((((v8 - 14) & 0xFFFFFFE0) - *(_WORD *)(v10 + 26) + 32) >> 1);
        Render_DrawTransparentTexture(pD3DRenderer, v14, v15, (cTexture *)v10);
        sub_40F92A(v16 + 4 * (v14 + dword_5059A8[v15]), v10, v22 + 1);
        v2 = (int)pD3DRenderer;
      }
      ++v22;
      v21 += 2;
    }
    while ( v22 < v20 * v18 );
  }
  Render_DrawIndexedTexture(
    (BaseRender *)v2,
    *(_DWORD *)dword_5076F4,
    *(_DWORD *)(dword_5076F4 + 4),
    uTextureID_right_backgr != -1 ? &LODFile_Icons_LOD.aLODHeaders[uTextureID_right_backgr]: 0);
}

//----- (00420B13) --------------------------------------------------------
int __fastcall sub_420B13(int a1, int a2)
{
  signed int v2; // eax@1
  int v3; // ecx@1
  int v4; // ebx@1
  int v5; // eax@1
  int v6; // eax@1
  signed int v7; // eax@3
  int v8; // edi@3
  signed int v9; // edi@3
  int v10; // eax@5
  int v11; // esi@8
  int i; // ecx@10
  int v13; // edi@10
  unsigned int v14; // ecx@10
  void *v15; // edi@10
  unsigned __int8 v16; // cf@10
  int v19; // [sp+Ch] [bp-14h]@1
  int v20; // [sp+10h] [bp-10h]@3
  int v21; // [sp+14h] [bp-Ch]@1
  int v22; // [sp+18h] [bp-8h]@1
  int v23; // [sp+1Ch] [bp-4h]@5
  int v24; // [sp+1Ch] [bp-4h]@8

  v21 = a2;
  v5 = *(_DWORD *)(dword_507BB8 + 28);
  v22 = v5;
  v5 *= 5324;
  v4 = (int)&array_5E5150[v5/5324].array_000004[a1];
  v19 = dword_4E2C0C[*(__int16 *)((char *)array_5E5150 + v5)];
  v6 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)pClass40->pItems[12 * *(_DWORD *)v4].pName, 2);
  v3 = v6 != -1 ? 72 * v6 + 7145548 : 0;
  v2 = *(_WORD *)(v6 != -1 ? 72 * v6 + 7145548 + 0x18 : 24);
  if ( v2 < 14 )
    v2 = 14;
  v9 = v2 - 14;
  v7 = *(_WORD *)(v3 + 26);
  v8 = (v9 >> 5) + 1;
  v20 = v8;
  if ( v7 < 14 )
    v7 = 14;
  v10 = ((v7 - 14) >> 5) + 1;
  v23 = v10;
  if ( !bTextureLoading )
  {
    cTexture_Free((cTexture *)v3);
    LODFile_Icons_LOD.LODFile_sub_40F9C5();
    v10 = v23;
  }
  if ( v10 > 0 )
  {
    v11 = 0;
    v24 = v10;
    do
    {
      if ( v8 > 0 )
      {
        v14 = v8;
        v15 = (void *)(2 * (v21 + v11 + 2662 * v22) + 6186244);
        v16 = v14 & 1;
        v14 >>= 1;
        memset(v15, 0, 4 * v14);
        v13 = (int)((char *)v15 + 4 * v14);
        for ( i = 2 * v16; i; --i )
        {
          *(_WORD *)v13 = 0;
          v13 += 2;
        }
        v8 = v20;
      }
      v11 += v19;
    }
    while ( v24-- != 1 );
  }
  ItemGen_Reset((ItemGen *)v4);
  return v4;
}

//----- (00420C05) --------------------------------------------------------
void __fastcall sub_420C05(int a1, int a2)
{
  int v2; // ebp@1
  signed int v3; // edi@1
  int v4; // esi@1
  signed int v7; // edx@8
  int v8; // ebx@10
  _UNKNOWN *v9; // edi@11
  signed int v10; // ecx@17
  int v11; // eax@21
  char *v12; // ecx@21
  int v13; // ecx@23
  int v14; // eax@26
  int v15; // eax@28
  int v16; // eax@30
  signed int v17; // [sp+Ch] [bp-4h]@6
 int i;

  v3 = 0;
  v2 = 0;
  v4 = a1;
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[467], a1);
    }
    else
    {
      if ( a2 == 2 )
        pStringBuffer[0] = 0;
    }
  }
  else
  {
    v17 = 0;
    for (i = 0; i < 2; ++i)
    {
      if (pParty_global->pHiredNPCs[i].pNPCName)
      {
        v7 = v17++;
        TmpBuf[v7] = i;
      }
    }


    v8 = 0;
    if (pNPCStats->dword_017FC4 > 0)
    {
      v9 = (char *)&pNPCStats->pNPCData2;
      do
      {
        if ( *((_BYTE *)v9 + 8) & 0x80 )
        {
         if (!pParty_global->pHiredNPCs[0].pNPCName || strcmp(*(const char **)v9, (char *)pParty_global->pHiredNPCs[0].pNPCName))
          {
           if (!pParty_global->pHiredNPCs[1].pNPCName || strcmp(*(const char **)v9, (char *)pParty_global->pHiredNPCs[1].pNPCName))
            {
              v10 = v17++;
              TmpBuf[v10] = v8 + 2;
            }
          }
        }
        ++v8;
        v9 = (char *)v9 + 76;
      }
      while ( v8 < pNPCStats->dword_017FC4);
      v3 = 0;
    }
    if ( v17 > 0 )
    {
      do
      {
        v11 = 76 * TmpBuf[v3];
        v12 = (char *)&pNPCStats->pNPCData[499 + v11 / 76];
        if (TmpBuf[v3] < 2 )
         v12 = (char *)&(&pParty_global->pHiredNPCs[0].pNPCName)[v11];
        v13 = *((_DWORD *)v12 + 6);
        if ( v13 )
          v2 += dword_737C28[5 * v13];
        ++v3;
      }
      while ( v3 < v17 );
    }
    v14 = CheckHiredNPCSpeciality(0x1F);
    if ( v14 )
      v4 += 10 * v4 / 100;
    v15 = CheckHiredNPCSpeciality(0x20);
    if ( v15 )
      v4 += 20 * v4 / 100;
    v16 = CheckHiredNPCSpeciality(0x2D);
    if ( v16 )
      v4 += 10 * v4 / 100;
    if ( v2 )
    {
      v2 = v4 * v2 / 100 / 100;
      if ( v2 < 1 )
        v2 = 1;
      wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[466], v4, v2);
    }
    else
    {
      wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[467], v4);
    }
    v3 = 0;
  }
  pParty_global->uNumGold += v4 - v2;
  array_6A0D14[1].word_000004 = v3;
  //array_6A0D14[1].word_000006 = 8 * pIconFrameTable->pIcons[array_6A0D14[1].uIconIdx].word_00001A;
  array_6A0D14[1].word_000006 = 8 * pIconFrameTable->GetImage(array_6A0D14[1].uIconIdx)->word_00001A;
  if ( (char *)pStringBuffer[0] )
    sub_44C175((char *)pStringBuffer, 2);
  AudioPlayer_sub_4AA306(pAudioPlayer, 200, v3, v3, -1, v3, v3, v3, v3);
}

//----- (00420E01) --------------------------------------------------------
void __cdecl sub_420E01()
{
  int v0; // edi@1
  int v1; // eax@2
  int v2; // esi@2
  int v3; // ebx@4
  int v4; // ecx@6
  int v5; // esi@6
  char v6[0x70]; // [sp+Ch] [bp-80h]@1
  POINT v7; // [sp+7Ch] [bp-10h]@2
  POINT v8; // [sp+84h] [bp-8h]@2

  sub_404828(&v6);
  v0 = *(_DWORD *)(pGUIWindow_CurrentMenu + 28);
  if (pParty_global->stru_007754.uItemID)
  {
    if ( sub_41FFA2(-1, &pParty_global->stru_007754, *(_DWORD *)(pGUIWindow_CurrentMenu + 28)) )
      class03_sub_4698A6(pGame->pClass03);
  }
  else
  {
    v2 = (int)class03_GetMousePos(pGame->pClass03, &v8);
    v1 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer
                   + 4 * (*(_DWORD *)v2 + dword_5059A8[*(_DWORD *)(class03_GetMousePos(pGame->pClass03, &v7) + 4)])) & 0xFFFF;
    if ( v1 )
    {
      if ( v1 )
        v3 = v1 - 1;
      else
        v3 = -1;
      //v5 = word_5E6504[v3 + 2662 * v0] - 1;
      v5 = ((short *)((char *)&array_5E5150[v0] + 0x13B4))[v3] - 1;

      v4 = 5324 * v0 + 36 * v5;
      //if ( byte_5D2A00[48 * *(_DWORD *)((char *)&unk_5E5154 + v4)] == 18 )
      if (pClass40->pItems[array_5E5150[v0].array_000004[v5].uItemID].uEquipType == 18)
      {
        //sub_420C05(*(int *)((char *)&dword_5E5160 + v4), 0);
        sub_420C05(array_5E5150[v0].array_000004[v5].dword_00000C, 0);
        struct_576FE8.dword_000044 = 1;
      }
      else
      {
        sub_4936E1(pParty_global, &array_5E5150[v0].array_000004[v5]);
      }
      sub_420B13(v5, v3);
    }
  }
}

//----- (004219BE) --------------------------------------------------------
int __thiscall sub_4219BE(void *_this)
{
  int v2; // esi@1
  int v3; // ebx@1

  v2 = (int)_this;
  class24_fn1(pClass24_global);
  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  dword_5118E0 = 0;
  CharacterUI_LoadPaperdollTextures();
  dword_4E28F8 = 23;
  v3 = (int)GUIWindowCreate(0, 0, 640, 480, 31, v2, 0);
  pCharacterUI_BtnExit = GUIButtonCreate(
                   (GUIWindow *)v3,
                   394,
                   318,
                   75,
                   33,
                   1,
                   0,
                   168,
                   0,
                   0,
                   pGlobalTXT_LocalizationStrings[79],
                    &LODFile_Icons_LOD.aLODHeaders[uTextureID_ButtExit1]);
  GUIButtonCreate((GUIWindow *)v3, 0, 0, 476, 345, 1, 122, 120, 0, 0, (unsigned char *)"", 0);
  dword_507690 = GUIButtonCreate((GUIWindow *)v3, 476, 0, 164, 345, 1, 0, 133, 0, 0, (unsigned char *)"", 0);
  GUIButtonCreate((GUIWindow *)v3, 61, 424, 31, 0, 2, 94, 110, 1, 49, (unsigned char *)"", 0);
  GUIButtonCreate((GUIWindow *)v3, 177, 424, 31, 0, 2, 94, 110, 2, 50, (unsigned char *)"", 0);
  GUIButtonCreate((GUIWindow *)v3, 292, 424, 31, 0, 2, 94, 110, 3, 51, (unsigned char *)"", 0);
  GUIButtonCreate((GUIWindow *)v3, 407, 424, 31, 0, 2, 94, 110, 4, 52, (unsigned char *)"", 0);
  return v3;
}

//----- (00421B2C) --------------------------------------------------------
signed int __cdecl sub_421B2C()
{
  int v0; // ebx@2
  int v1; // eax@2
  int v2; // eax@3
  int v4; // eax@6
  int v5; // eax@11
  __int16 v6; // dx@11
  int v7; // edi@12
  __int16 v8; // ax@16
  __int16 v10; // [sp+4h] [bp-78h]@11
  __int16 v11; // [sp+6h] [bp-76h]@16
  int v12; // [sp+8h] [bp-74h]@16
  int v13; // [sp+Ch] [bp-70h]@16
  int v14; // [sp+10h] [bp-6Ch]@16
  __int16 v15; // [sp+1Ah] [bp-62h]@16
  __int16 v16; // [sp+1Ch] [bp-60h]@16
  __int16 v17; // [sp+1Eh] [bp-5Eh]@16
  __int16 v18; // [sp+20h] [bp-5Ch]@16
  __int16 v19; // [sp+22h] [bp-5Ah]@16

  struct ItemGen local_28;
  //char v20; // [sp+28h] [bp-54h]@16

  int v21; // [sp+5Ch] [bp-20h]@16
  int v22; // [sp+74h] [bp-8h]@2
  int v23; // [sp+78h] [bp-4h]@5
 int i;

  if (pParty_global->stru_007754.uItemID)
  {
   v1 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)pClass40->pItems[12 * pParty_global->stru_007754.uItemID].pIconName, 2);
    v0 = v1 != -1 ? 72 * v1 + 7145548 : 0;
    v22 = bTextureLoading;
    if ( uActiveCharacter && (v2 = CreateItemInInventory(pPlayers[uActiveCharacter - 1], -1, pParty_global->stru_007754.uItemID)) != 0 )
    {
     memcpy(&pPlayers[uActiveCharacter - 1]->cInventorySlots[v2], &pParty_global->stru_007754, sizeof(struct ItemGen));
    }
    else
    {
      v23 = 0;
      i = 0;
      while ( 1 )
      {
        v4 = CreateItemInInventory(&pParty_global->pPlayers[i++], -1, pParty_global->stru_007754.uItemID);
        if ( v4 )
          break;
        ++v23;
        if (i >= 4)
          goto LABEL_10;
      }
      memcpy(&pParty_global->pPlayers[v23].cInventorySlots[v4], &pParty_global->stru_007754, sizeof(struct ItemGen));
      class03_sub_4698A6(pGame->pClass03);
LABEL_10:
      if ( v23 != 4 )
        goto LABEL_18;
      sub_404828(&v10);
      v6 = word_5D29F8[24 * pParty_global->stru_007754.uItemID];
      v5 = 0;
      v10 = word_5D29F8[24 * pParty_global->stru_007754.uItemID];
      if ( pObjectDescriptionList->uNumObjects <= 0 )
      {
LABEL_15:
        LOWORD(v5) = 0;
      }
      else
      {
        v7 = (int)pObjectDescriptionList->pDescriptions + 32;
        while ( v6 != *(_WORD *)v7 )
        {
          ++v5;
          v7 += 56;
          if ( v5 >= pObjectDescriptionList->uNumObjects )
            goto LABEL_15;
        }
      }
      v21 = 4;
      v11 = v5;
      v13 = pParty_global->sPartyPosY;
      v12 = pParty_global->sPartyPosX;
      v14 = pParty_global->uEyelevel + pParty_global->sPartyPosZ;
      v16 = 0;
      v15 = 0;
      v17 = 8;
      v8 = sub_49AC17((int)byte_6BE3C8, pParty_global->sPartyPosX, pParty_global->sPartyPosY, pParty_global->uEyelevel + pParty_global->sPartyPosZ);
      v19 = 0;
      v18 = v8;
      memcpy(&local_28, &pParty_global->stru_007754, sizeof(struct ItemGen));
      sub_42F5ED((int)&v10, pParty_global->sRotationY, 184, 200, 0);
    }
    class03_sub_4698A6(pGame->pClass03);
LABEL_18:
    if ( !v22 )
    {
      cTexture_Free((cTexture *)v0);
      LODFile_Icons_LOD.LODFile_sub_40F9C5();
    }
  }
  return 1;
}

//----- (00421D00) --------------------------------------------------------
void GameUI_OnPlayerPortraitLeftClick(unsigned int uCharacter)
{
  int v2; // eax@2
  int v3; // ecx@2
  void *v4; // ecx@5

  if (pParty_global->stru_007754.uItemID)
  {
    v2 = CreateItemInInventory(pPlayers[uCharacter - 1], -1, pParty_global->stru_007754.uItemID);
    v3 = (int)pPlayers[uCharacter - 1];
    if ( v2 )
    {
      memcpy((void *)(v3 + 36 * v2 + 496), &pParty_global->stru_007754, sizeof(struct ItemGen));
      struct_576FE8.dword_000044 = 1;
      class03_sub_4698A6(pGame->pClass03);
      return;
    }
    if ( Player_sub_492C0B(v3) )
    {
      v4 = pPlayers[uCharacter - 1];
    }
    else
    {
      if ( !Player_sub_492C0B((int)pPlayers[uActiveCharacter - 1]) )
        goto LABEL_9;
      v4 = pPlayers[uActiveCharacter - 1];
    }
    Player_PlaySound((Player *)v4, 15, 0);
  }

LABEL_9:
  if ( !dword_4E28F8 )
  {
    struct_576FE8.dword_000044 = 1;
    if (uActiveCharacter != uCharacter)
    {
     if (pPlayers[uCharacter - 1]->uTimeToRecovery)
       return;

     uActiveCharacter = uCharacter;
     return;
    }

    pGUIWindow_CurrentMenu = GameUI_InitializeCharacterWindow(7);
    return;
  }
  if ( dword_4E28F8 == 8 )
    return;
  if ( dword_4E28F8 == 10 )
  {
LABEL_23:
    struct_576FE8.dword_000044 = 1;
    if (uActiveCharacter == uCharacter )
    {
      dword_506F48 = 103;
      dword_4E28F8 = 15;
      goto LABEL_28;
    }

    if (pPlayers[uCharacter - 1]->uTimeToRecovery)
      return;
    uActiveCharacter = uCharacter;
    return;
  }
  if ( dword_4E28F8 != 13 )
  {
    if ( dword_4E28F8 == 14 )
    {
LABEL_28:
      uActiveCharacter = uCharacter;
      return;
    }
    if ( dword_4E28F8 != 15 )
    {
      struct_576FE8.dword_000044 = 1;
      uActiveCharacter = uCharacter;
      if ( dword_506F48 == 102 )
        sub_419100();
      return;
    }
    goto LABEL_23;
  }
  if (ptr_507BC0->dword_000040 == 1)
    return;
  struct_576FE8.dword_000044 = 1;
  if (uActiveCharacter != uCharacter)
    goto LABEL_28;
  if ( dword_F8B19C == 2 || dword_F8B19C == 6 )
  {
    dword_506F48 = 103;
    pGUIWindow_CurrentMenu = GameUI_InitializeCharacterWindow(14);
  }
}

//----- (00421E75) --------------------------------------------------------
int __thiscall sub_421E75(void *_this, int a2)
{
  int v2; // eax@1
  int result; // eax@3

  v2 = *(_DWORD *)a2;
  if ( *(_DWORD *)a2 >= 126 || v2 < 0 )
  {
    result = 0;
  }
  else
  {
    result = *((_DWORD *)_this + v2 + 1375);
    if ( result < 0 )
    {
      *(_DWORD *)a2 = -1 - result;
      result = *((_DWORD *)_this + -1 - result + 1375);
    }
  }
  return result;
}

//----- (00421EA6) -------------------.text:00422608 -------------------------------------
void __cdecl sub_421EA6()
{
  void *v0; // ebx@1
  int v1; // eax@2
  signed int v2; // eax@2
  signed int v3; // ecx@2
  int v4; // eax@2
  char v5; // sf@2
  int v6; // eax@7
  int v7; // eax@12
  int v8; // esi@12
  int v9; // eax@16
  int v10; // eax@18

  struct ItemGen local_0C;
  //int v11; // [sp+Ch] [bp-3Ch]@1

  POINT v12; // [sp+30h] [bp-18h]@4
  const void *v13; // [sp+34h] [bp-14h]@14
  int v14; // [sp+38h] [bp-10h]@13
  int v15; // [sp+3Ch] [bp-Ch]@2
  int v16; // [sp+40h] [bp-8h]@2
  int v17; // [sp+44h] [bp-4h]@2

  int pointX, pointY;

  ItemGen_Reset(&local_0C);
  v0 = pPlayers[uActiveCharacter - 1];
  if ( dword_506F48 == 103 )
  {
    class03_GetMouseClickPos(pGame->pClass03, &pointX, &pointY);

	pointX-=17;
	pointY-=14;
  //  v2 = v15 - 17;
 //   v3 = v16 - 14;
 //   v15 = v2;
//    v16 = v3;
	v5=	(pointX>>5)*14+pointY>>5;
  //  v4 = 14 * (v2 >> 5);  
 //   v3 >>= 5;
  //  v5 = v3 + v4 < 0;
 //   v1 = v3 + v4;
  //  v17 = v1;
	
    if ( v5>=0 )
    {
	  class03_GetMousePos(pGame->pClass03, &v12);
      if ( (v5 <= 126)
       // && *(_DWORD *)class03_GetMousePos(pGame->pClass03, &v12) < 462
      //  && *(_DWORD *)class03_GetMousePos(pGame->pClass03, &v12) >= 14 )
	  &&v12.x<462&&v12.x>=14)
      {
        if ( dword_50C9A0 )
        {
          v6 = sub_421E75(v0, (int)&v5);
          if ( v6 )
          {
            *(_BYTE *)(*(_DWORD *)(ptr_507BD4->dword_00001C) + 8) &= 0x7Fu;
            *(_WORD *)(*(_DWORD *)(ptr_507BD4->dword_00001C) + 4) = uActiveCharacter - 1;
            *(_DWORD *)(*(_DWORD *)(ptr_507BD4->dword_00001C) + 12) = v6 - 1;
            *(_WORD *)(*(_DWORD *)(ptr_507BD4->dword_00001C) + 6) = v17;
            dword_50C9A4 = (int)((char *)v0 + 36 * v6 + 496);
            dword_50C9A0 = 0;
            if ( dword_50CBD0[0] )
              dword_50CBD0[0] = dword_50CBD0[3] != 0;
            sub_469903(pGame->pClass03, "MICON1");
            dword_50C9D0 = 113;
            dword_50C9D4 = 0;
            dword_50C9D8 = 256;
          }
          return;
        }
        if ( dword_50C9A4 )
          return;
        v8 = pParty_global->stru_007754.uItemID;
        v7 = sub_421E75(v0, (int)&v17);
        if ( !v8 )
        {
          if ( !v7 )
            return;
          memcpy(&pParty_global->stru_007754, (char *)v0 + 36 * v7 + 496, sizeof(struct ItemGen));
          Player_sub_492A36((struct Player *)v0, v17);
          v9 = pParty_global->stru_007754.uItemID;
          goto LABEL_24;
        }
        v14 = v7;
        if ( v7 )
        {
          v13 = (char *)v0 + 36 * v7 + 496;
          memcpy(&local_0C, v13, 0x24u);
          Player_sub_492A36((struct Player *)v0, v17);
          v16 = Player_sub_492826((Player *)v0, v17, &pParty_global->stru_007754);
          if ( !v16 )
          {
            v16 = Player_sub_492826((Player *)v0, -1, &pParty_global->stru_007754);
            if ( !v16 )
            {
              sub_49298B(v0, &local_0C, v14 - 1, v17);
              memcpy((void *)v13, &local_0C, sizeof(struct ItemGen));
              return;
            }
          }
          v9 = local_0C.uItemID;
          memcpy(&pParty_global->stru_007754, &local_0C, sizeof(struct ItemGen));
LABEL_24:
          sub_469903(pGame->pClass03, (char *)pClass40->pItems[v9].pIconName);
          return;
        }
        v10 = CreateItemInInventory((Player *)v0, v17, v8);
        v16 = v10;
        if ( v10 || (v10 = CreateItemInInventory((Player *)v0, -1, pParty_global->stru_007754.uItemID), v16 = v10, v10) )
        {
          memcpy((char *)v0 + 36 * v10 + 496, &pParty_global->stru_007754, sizeof(struct ItemGen));
          class03_sub_4698A6(pGame->pClass03);
        }
      }
    }
  }
}

//----- (0042213C) --------------------------------------------------------
void __cdecl sub_42213C()
{
  signed int v0; // ebx@2
  signed int v2; // eax@9
  int v3; // eax@10
  int v4; // eax@11
  int v5; // eax@14
  __int16 v6; // dx@14
  int v7; // esi@15
  int v8; // eax@19
  int v9; // eax@19
  int v10; // eax@19
  int v11; // ecx@21
  int v12; // eax@22
  __int16 *v13; // esi@24
  __int16 v14; // ax@25
  int v15; // ecx@29
  signed int v16; // edx@30
  int v17; // esi@30
  int v18; // ebx@47
  __int16 v19; // ax@50
  const char *v20; // eax@51
  int v21; // eax@58
  int v22; // eax@62
  int v23; // esi@62

  struct
  {
   __int16 v24; // [sp+Ch] [bp-80h]@1
   __int16 v25; // [sp+Eh] [bp-7Eh]@19
   int v26; // [sp+10h] [bp-7Ch]@19
   int v27; // [sp+14h] [bp-78h]@19
   int v28; // [sp+18h] [bp-74h]@19

   int unk2;
   short unk3;

   int v29; // [sp+22h] [bp-6Ah]@19
   __int16 v30; // [sp+26h] [bp-66h]@19
   __int16 v31; // [sp+28h] [bp-64h]@19
   __int16 v32; // [sp+2Ah] [bp-62h]@19

   short unk4[2];

   //char Dst[0x24]; // [sp+30h] [bp-5Ch]@19
   ItemGen local_30;

   char unk[12];
   int unk_60;
   int v34; // [sp+64h] [bp-28h]@19
  } v24;
  //char v35; // [sp+7Ch] [bp-10h]@3
  POINT v35;
  char v36; // [sp+84h] [bp-8h]@3
  int v37; // [sp+88h] [bp-4h]@30
 POINT pt;

  sub_404828(&v24);
  if ( pD3DRenderer->pRenderD3D3 )
  {
    v0 = sub_4C1BF1_Vis_LooksLikeFindTopmostZObject(pGame->pVis);
  }
  else
  {
   class03_GetMousePos(pGame->pClass03, &pt);
   v0 = pD3DRenderer->pActiveZBuffer[pt.x + dword_5059A8[pt.y]];
  }

  if ( (v0 & 7) == 2 )
  {
    v37 = (signed int)(unsigned __int16)v0 >> 3;
    v21 = 112 * ((signed int)(unsigned __int16)v0 >> 3);
    if ( !(*(_BYTE *)(56 * pLayingItemsList[(unsigned __int16)v0 >> 3].uObjectDescriptionID + pObjectDescriptionList->pDescriptions + 38) & 0x10)
      && v37 < 1000
      && pLayingItemsList[(unsigned __int16)v0 >> 3].uObjectDescriptionID
      && (unsigned int)v0 < 0x2000000 )
    {
      v23 = (int)&pLayingItemsList[v21/112].stru_000024;
      v22 = 48 * pLayingItemsList[v21/112].stru_000024.uItemID;
      if (pClass40->pItems[v22/48].uEquipType == 18 )
      {
        sub_420C05(*(_DWORD *)(v23 + 12), 0);
        struct_576FE8.dword_000044 = 1;
      }
      else
      {
        wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[471], *(int *)((char *)dword_5D29EC + v22));
        sub_44C175((char *)pStringBuffer, 2);
        if ( *(_DWORD *)v23 == 506 )
          sub_449B7E((int)pParty_global->unk_000764 + 1, 184, 1);
        if ( *(_DWORD *)v23 == 455 )
          sub_449B7E((int)pParty_global->unk_000764 + 1, 185, 1);
        if ( !Party_AddItem(pParty_global, (ItemGen *)v23) )
          sub_4936E1(pParty_global, (ItemGen *)v23);
      }
      sub_42F933(v37);
      return;
    }
    goto LABEL_13;
  }
  if ( (v0 & 7) != 3 )
  {
    if ( (v0 & 7) == 5 )
    {
      v13 = (short *)&pLevelDecorations[((signed int)(unsigned __int16)v0 >> 3)];
      if ( (signed int)(((unsigned int)v0 >> 16) - *(_WORD *)(84 * *v13 + pDecorationDescriptionList->pDescriptions + 68)) >= 512 )
        goto LABEL_13;
      v14 = v13[11];
      if ( !v14 )
      {
        if ( sub_44C2F4_SomeDecorationTypeCheck(&pLevelDecorations[((signed int)(unsigned __int16)v0 >> 3)]) )
        {
          v15 = (unsigned __int8)global_5E4C90.byte_000000[v13[14]];
          dword_5C3420 = (int)&pLevelDecorations[((signed int)(unsigned __int16)v0 >> 3)];
          sub_44684A_LooksLikeEventProcessor(v15 + 380, 0, 1);
          dword_5C3420 = 0;
        }
        return;
      }
      v11 = v14;
    }
    else
    {
      if ( (v0 & 7) != 6 || (unsigned int)v0 >= 0x2000000 )
        goto LABEL_13;
      v2 = (signed int)(unsigned __int16)v0 >> 3;
      if ( dword_6BE360 == 1 )
      {
        v3 = dword_6BE644 + 96 * v2;
        if ( !(*(_DWORD *)(v3 + 44) & 0x2000000) )
        {
LABEL_11:
          v4 = pParty_global->stru_007754.uItemID;
          if (pParty_global->stru_007754.uItemID)
          {
LABEL_14:
            v6 = word_5D29F8[24 * v4];
            v5 = 0;
            v24.v24 = v6;
            if ( pObjectDescriptionList->uNumObjects <= 0 )
            {
LABEL_18:
              LOWORD(v5) = 0;
            }
            else
            {
              v7 = (int)pObjectDescriptionList->pDescriptions + 32;
              while ( v6 != *(_WORD *)v7 )
              {
                ++v5;
                v7 += 56;
                if ( v5 >= pObjectDescriptionList->uNumObjects )
                  goto LABEL_18;
              }
            }
            v24.v25 = v5;
            v24.v27 = pParty_global->sPartyPosY;
            v24.v34 = 4;
            v24.v26 = pParty_global->sPartyPosX;
            v24.v28 = pParty_global->uEyelevel + pParty_global->sPartyPosZ;
            v24.v29 = 0;
            v24.v30 = 8;
            v24.v31 = sub_49AC17((int)byte_6BE3C8, pParty_global->sPartyPosX, pParty_global->sPartyPosY, pParty_global->uEyelevel + pParty_global->sPartyPosZ);
            v24.v32 = 0;
            memcpy(&v24.local_30, &pParty_global->stru_007754, sizeof(struct ItemGen));
            v8 = (int)class03_GetMousePos(pGame->pClass03, &v35);
            v9 = sub_46A0A1(v35.x);
            sub_42F5ED((int)&v24, pParty_global->sRotationY + v9, 184, 200, 0);
            v10 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)pClass40->pItems[12 * pParty_global->stru_007754.uItemID].pIconName, 2);
            cTexture_Free((cTexture *)(v10 != -1 ? 72 * v10 + 7145548 : 0));
            class03_sub_4698A6(pGame->pClass03);
            LODFile_Icons_LOD.LODFile_sub_40F9C5();
            return;
          }
          sub_44C1D0();
LABEL_13:
          v4 = pParty_global->stru_007754.uItemID;
          if (!pParty_global->stru_007754.uItemID)
            return;
          goto LABEL_14;
        }
        v11 = *(_WORD *)(dword_6BE64C + 36 * *(_WORD *)(v3 + 72) + 26);
      }
      else
      {
        v12 = *(_DWORD *)(188 * ((signed int)(unsigned __int16)v0 >> 9) + pClass51_global->pBModels + 84) + 308 * (v2 & 0x3F);
        if ( !(*(_DWORD *)(v12 + 28) & 0x2000000) )
          goto LABEL_11;
        v11 = *(_WORD *)(v12 + 292);
      }
    }
    sub_44684A_LooksLikeEventProcessor(v11, (unsigned __int16)v0, 1);
    return;
  }
  v16 = (signed int)(unsigned __int16)v0 >> 3;
  v37 = v16;
  v17 = (int)((char *)pActors + 836 * v16);
  if ( *(_WORD *)(v17 + 176) == 5 )
  {
    if ( (unsigned int)v0 < 0x2000000 )
    {
      sub_426A5A((int)((char *)pActors + 836 * v16));
      return;
    }
    goto LABEL_13;
  }
  if ( GetAsyncKeyState(16) >= 0 )
  {
    if ( !Actor_GetActorsRelation((Actor *)v17, 0) && !(*(_BYTE *)(v17 + 38) & 8) )
    {
      if ( (unsigned int)v0 >= 0x2000000 )
        goto LABEL_13;
      if ( !Actor_sub_40894B((Actor *) v17) )
        return;
      v18 = v37;
      Actor_ProbablyForceToFaceParty(v37, 4, 0, 0);
      if ( !*(_WORD *)(v17 + 32) )
      {
        v19 = pNPCStats->word_017F5A[*(_DWORD *)(v17 + 708)];
        if ( v19 )
        {
          v20 = (char *)pNPCStats->pCatchPhrases[(unsigned __int16)v19];
          if ( v20 )
          {
            pParty_global->dword_007778 |= 2;
            strcpy((char *)&byte_5B0938, v20);
            sub_4451A8(0, 0, 0);
          }
        }
        return;
      }
      if ( dword_50CBD0[0] >= 40 )
        return;
      dword_50CBD0[3 * dword_50CBD0[0] + 1] = 161;
      dword_50CBD0[3 * dword_50CBD0[0] + 2] = v18;
LABEL_42:
      dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
      return;
    }
    if (pParty_global->dword_00087C == 1 && dword_4F885C == 3)
    {
      dword_4F8870 |= 8u;
      return;
    }
    if ( dword_50CBD0[0] < 40 )
    {
      dword_50CBD0[3 * dword_50CBD0[0] + 1] = 23;
      goto LABEL_41;
    }
  }
  else
  {
    if (pParty_global->dword_00087C == 1 && dword_4F885C == 3)
    {
      pParty_global->dword_007778 |= 8u;
      return;
    }
    if ( uActiveCharacter && sub_427769(*((_BYTE *)pPlayers[uActiveCharacter - 1] + 6735)) && dword_50CBD0[0] < 40 )
    {
      dword_50CBD0[3 * dword_50CBD0[0] + 1] = 25;
LABEL_41:
      dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
      goto LABEL_42;
    }
  }
}

//----- (004226C2) --------------------------------------------------------
bool __cdecl sub_4226C2()
{
 if (dword_4E28F8 && dword_4E28F8 != 4 && dword_4E28F8 != 17)
 {
  if (dword_4E28F8 == 18)
    return pVideoPlayer->pSmackerMovie != 0;
  else if (dword_4E28F8 != 19)
    return true;
 }
 return false;
}

//----- (00423B5D) --------------------------------------------------------
int __fastcall sub_423B5D(int a1)
{
  int v1; // ebx@1
  signed int v2; // esi@1
  int v3; // esi@1
  int v4; // ST28_4@1
  __int16 v5; // ST2C_2@1
  int v6; // eax@4
  signed int v7; // eax@5
  signed int v8; // edi@5
  int v9; // eax@10
  int v10; // ecx@10
  int v11; // edx@11
  char *v12; // ebx@12
  int v13; // ST28_4@12
  signed int v14; // edx@12
  signed __int64 v15; // qtt@12
  int v16; // ST28_4@14
  signed int v17; // eax@14
  signed __int64 v18; // qtt@14
  signed int v19; // edx@15
  int v20; // edx@17
  int v21; // ebx@19
  int v22; // esi@20
  int v23; // eax@21
  int v24; // edi@21
  int v25; // eax@22
  signed int v26; // ST30_4@24
  signed __int64 v27; // qtt@24
  int v28; // ST18_4@25
  int v29; // eax@26
  int v30; // eax@27
  signed int v31; // ST30_4@29
  signed __int64 v32; // qtt@29
  int v33; // ST30_4@30
  int v34; // eax@31
  bool v35; // edx@31
  int v36; // ecx@31
  signed int v37; // edi@31
  int v38; // ecx@32
  int v39; // esi@32
  int v40; // eax@34
  unsigned __int8 v41; // zf@39
  char v42; // sf@39
  unsigned __int8 v43; // of@39
  int v44; // eax@41
  signed int v45; // ebx@41
  int v46; // ecx@42
  int v47; // esi@42
  int v48; // eax@44
  int v49; // eax@51
  bool v50; // edx@51
  int v51; // ecx@51
  signed int v52; // edi@51
  int v53; // ecx@52
  int v54; // esi@52
  int v55; // eax@54
  unsigned __int8 v56; // zf@59
  char v57; // sf@59
  unsigned __int8 v58; // of@59
  int v59; // eax@61
  int v60; // ebx@61
  int v61; // ecx@62
  int v62; // esi@62
  int v63; // eax@64
  char v65; // zf@72
  signed int v66; // edx@75
  int v67; // ecx@76
  int v68; // esi@76
  int v69; // ecx@83
  signed int v70; // [sp+14h] [bp-14h]@3
  int v71; // [sp+14h] [bp-14h]@34
  int v72; // [sp+14h] [bp-14h]@44
  int v73; // [sp+14h] [bp-14h]@54
  int v74; // [sp+14h] [bp-14h]@64
  signed int v75; // [sp+14h] [bp-14h]@75
  bool v76; // [sp+18h] [bp-10h]@9
  int v77; // [sp+18h] [bp-10h]@12
  int v78; // [sp+18h] [bp-10h]@20
  bool v79; // [sp+18h] [bp-10h]@41
  bool v80; // [sp+18h] [bp-10h]@61
  int v81; // [sp+18h] [bp-10h]@74
  signed int v82; // [sp+1Ch] [bp-Ch]@9
  int v83; // [sp+1Ch] [bp-Ch]@76
  bool v84; // [sp+20h] [bp-8h]@10
  bool v85; // [sp+20h] [bp-8h]@32
  bool v86; // [sp+20h] [bp-8h]@42
  bool v87; // [sp+20h] [bp-8h]@52
  bool v88; // [sp+20h] [bp-8h]@62
  signed int v89; // [sp+24h] [bp-4h]@9
  signed int v90; // [sp+24h] [bp-4h]@19
  signed int v91; // [sp+24h] [bp-4h]@31
  signed int v92; // [sp+24h] [bp-4h]@41
  signed int v93; // [sp+24h] [bp-4h]@51
  signed int v94; // [sp+24h] [bp-4h]@61

  v1 = dword_6BE644 + 96 * a1;
  v3 = dword_6BE63C + 6 * **(_WORD **)(v1 + 48);
  v4 = *(_DWORD *)v3;
  v5 = *(_WORD *)(v3 + 4);
  v2 = 0;
  if ( *(_DWORD *)(v1 + 16) * ((signed __int16)v4 - dword_51B6E8)
     + *(_DWORD *)(v1 + 20) * (SHIWORD(v4) - dword_51B6EC)
     + *(_DWORD *)(v1 + 24) * (v5 - dword_51B6F0) < 0 )
  {
    dword_50B700 = 1;
  }
  else
  {
    dword_50B700 = 0;
    if ( !(*(_BYTE *)(v1 + 44) & 1) )
      return 0;
  }
  v70 = *(_BYTE *)(v1 + 93);
  if ( (signed int)*(_BYTE *)(v1 + 93) > 0 )
  {
    do
    {
      v6 = dword_6BE63C + 6 * *(_WORD *)(*(_DWORD *)(v1 + 48) + 2 * v2);
      sub_43669D(
        *(_WORD *)v6,
        *(_WORD *)(v6 + 2),
        *(_WORD *)(v6 + 4),
        (signed int *)(4 * v2 + 5290276),
        4 * v2 + 5290036,
        4 * v2 + 5289796,
        0);
      ++v2;
    }
    while ( v2 < v70 );
  }
  v8 = v70;
  v7 = 0;
  if ( v70 <= 0 )
    return 0;
  do
  {
    if ( dword_50B924[v7] >= 524288 )
      break;
    ++v7;
  }
  while ( v7 < v70 );
  if ( v7 >= v70 )
    return 0;
  v82 = 0;
  dword_50B924[v70] = dword_50B924[0];
  dword_50B834[v70] = dword_50B834[0];
  dword_50B744[v70] = dword_50B744[0];
  v76 = dword_50B924[0] >= 524288;
  v89 = 1;
  if ( v70 >= 1 )
  {
    do
    {
      v10 = 4 * v89;
      v9 = dword_50B924[v89];
      v84 = v9 >= 524288;
      if ( v76 ^ v84 )
      {
        v11 = *(int *)((char *)&dword_50B920 + v10);
        if ( v9 >= 524288 )
        {
          v13 = v9 - v11;
          v14 = 524288 - v11;
          LODWORD(v15) = v14 << 16;
          HIDWORD(v15) = v14 >> 16;
          v12 = (char *)&dword_50B740 + v10;
          dword_50B828[v82] = ((unsigned __int64)((*(int *)((char *)dword_50B834 + v10)
                                                 - *(int *)((char *)&dword_50B830 + v10))
                                                * (signed int)(v15 / v13)) >> 16)
                            + *(int *)((char *)&dword_50B830 + v10);
          v77 = (unsigned __int64)((*(int *)((char *)dword_50B744 + v10) - *(int *)((char *)&dword_50B740 + v10))
                                 * (signed int)(v15 / v13)) >> 16;
        }
        else
        {
          v16 = v11 - v9;
          v17 = 524288 - v9;
          LODWORD(v18) = v17 << 16;
          HIDWORD(v18) = v17 >> 16;
          v12 = (char *)dword_50B744 + v10;
          dword_50B828[v82] = ((unsigned __int64)((*(int *)((char *)&dword_50B830 + v10)
                                                 - *(int *)((char *)dword_50B834 + v10))
                                                * (signed int)(v18 / v16)) >> 16)
                            + *(int *)((char *)dword_50B834 + v10);
          v77 = (unsigned __int64)((*(int *)((char *)&dword_50B740 + v10) - *(int *)((char *)dword_50B744 + v10))
                                 * (signed int)(v18 / v16)) >> 16;
        }
        v19 = v82++;
        v8 = v70;
        dword_50B738[v19] = v77 + *(_DWORD *)v12;
        dword_50B918[v19] = 524288;
      }
      if ( v84 )
      {
        v20 = 4 * v82++;
        *(int *)((char *)dword_50B918 + v20) = *(int *)((char *)dword_50B924 + v10);
        *(int *)((char *)dword_50B828 + v20) = *(int *)((char *)dword_50B834 + v10);
        *(int *)((char *)dword_50B738 + v20) = *(int *)((char *)dword_50B744 + v10);
      }
      ++v89;
      v76 = v84;
    }
    while ( v89 <= v8 );
  }
  v90 = 0;
  v21 = 4 * v82;
  dword_50B918[v82] = dword_50B918[0];
  dword_50B828[v82] = dword_50B828[0];
  for ( dword_50B738[v82] = dword_50B738[0]; v90 < v82; *(int *)((char *)&dword_50BA08 + v22) = dword_51B758 - v33 )
  {
    v22 = 4 * v90;
    v78 = abs(dword_50B918[v90]);
    if ( abs(dword_50B828[v90]) >> 13 <= v78 )
    {
      v26 = *(int *)((char *)dword_50B828 + v22);
      LODWORD(v27) = v26 << 16;
      HIDWORD(v27) = v26 >> 16;
      v25 = v27 / *(int *)((char *)dword_50B918 + v22);
      v24 = 0;
    }
    else
    {
      v24 = 0;
      v23 = 0;
      if ( *(int *)((char *)dword_50B828 + v22) >= 0 )
      {
        LOBYTE(v23) = *(int *)((char *)dword_50B918 + v22) >= 0;
        v25 = ((v23 - 1) & 0xFF800000) + 4194304;
      }
      else
      {
        LOBYTE(v23) = *(int *)((char *)dword_50B918 + v22) >= 0;
        v25 = (0x00800000 & (v23 - 1)) - 4194304;
      }
    }
    v28 = *(int *)((char *)dword_50B738 + v22);
    *(int *)((char *)&dword_50BAF8 + v22) = v25;
    if ( abs(v28) >> 13 <= v78 )
    {
      v31 = *(int *)((char *)dword_50B738 + v22);
      LODWORD(v32) = v31 << 16;
      HIDWORD(v32) = v31 >> 16;
      v30 = v32 / *(int *)((char *)dword_50B918 + v22);
    }
    else
    {
      v29 = 0;
      if ( *(int *)((char *)dword_50B738 + v22) >= v24 )
      {
        LOBYTE(v29) = *(int *)((char *)dword_50B918 + v22) >= v24;
        v30 = ((v29 - 1) & 0xFF800000) + 4194304;
      }
      else
      {
        LOBYTE(v29) = *(int *)((char *)dword_50B918 + v22) >= v24;
        v30 = (0x00800000 & (v29 - 1)) - 4194304;
      }
    }
    *(int *)((char *)&dword_50BA08 + v22) = v30;
    *(int *)((char *)&dword_50BAF8 + v22) = (unsigned __int64)(word_51B722 * *(int *)((char *)&dword_50BAF8 + v22)) >> 16;
    v33 = (unsigned __int64)(word_51B722 * *(int *)((char *)&dword_50BA08 + v22)) >> 16;
    *(int *)((char *)&dword_50BAF8 + v22) = dword_51B754 - *(int *)((char *)&dword_50BAF8 + v22);
    ++v90;
  }
  v37 = 0;
  *(int *)((char *)&dword_50BAF8 + v21) = dword_50BAF8;
  *(int *)((char *)&dword_50BA08 + v21) = dword_50BA08;
  v34 = dword_51B734;
  v35 = dword_50BAF8 < dword_51B734;
  LOBYTE(v35) = dword_50BAF8 >= dword_51B734;
  v36 = 1;
  v91 = 1;
  if ( v82 < 1 )
    return 0;
  do
  {
    v38 = 4 * v36;
    v39 = *(int *)((char *)&dword_50BAF8 + v38);
    v85 = v39 >= v34;
    if ( v35 ^ v85 )
    {
      if ( v39 >= v34 )
      {
        v71 = (v34 - *(int *)((char *)&dword_50BAF4 + v38))
            * (signed __int64)(*(int *)((char *)&dword_50BA08 + v38) - *(int *)((char *)&dword_50BA04 + v38))
            / (v39 - *(int *)((char *)&dword_50BAF4 + v38));
        v40 = *(int *)((char *)&dword_50BA04 + v38);
      }
      else
      {
        v71 = (v34 - v39)
            * (signed __int64)(*(int *)((char *)&dword_50BA04 + v38) - *(int *)((char *)&dword_50BA08 + v38))
            / (*(int *)((char *)&dword_50BAF4 + v38) - v39);
        v40 = *(int *)((char *)&dword_50BA08 + v38);
      }
      ++v37;
      dword_50B9F8[v37] = v71 + v40;
      v34 = dword_51B734;
      dword_50BAE8[v37] = dword_51B734;
    }
    v35 = v85;
    if ( v85 )
    {
      dword_50BAEC[v37] = *(int *)((char *)&dword_50BAF8 + v38);
      dword_50B9FC[v37++] = *(int *)((char *)&dword_50BA08 + v38);
    }
    v36 = v91 + 1;
    compile_error;//v43 = __SETO__(v91 + 1, v82);
    v41 = v91 + 1 == v82;
    v42 = v91++ + 1 - v82 < 0;
  }
  while ( (unsigned __int8)(v42 ^ v43) | v41 );
  if ( !v37 )
    return 0;
  v45 = 0;
  dword_50BAEC[v37] = dword_50BAEC[0];
  dword_50B9FC[v37] = dword_50B9FC[0];
  v44 = dword_51B73C;
  v79 = dword_50BAEC[0] <= dword_51B73C;
  v92 = 1;
  if ( v37 < 1 )
    return 0;
  do
  {
    v46 = 4 * v92;
    v47 = dword_50BAEC[v92];
    v86 = v47 <= v44;
    if ( v79 ^ v86 )
    {
      if ( v47 <= v44 )
      {
        v72 = (v44 - *(int *)((char *)dword_50BAE8 + v46))
            * (signed __int64)(*(int *)((char *)dword_50B9FC + v46) - *(int *)((char *)dword_50B9F8 + v46))
            / (v47 - *(int *)((char *)dword_50BAE8 + v46));
        v48 = *(int *)((char *)dword_50B9F8 + v46);
      }
      else
      {
        v72 = (v44 - v47)
            * (signed __int64)(*(int *)((char *)dword_50B9F8 + v46) - *(int *)((char *)dword_50B9FC + v46))
            / (*(int *)((char *)dword_50BAE8 + v46) - v47);
        v48 = *(int *)((char *)dword_50B9FC + v46);
      }
      ++v45;
      dword_50B9EC[v45] = v72 + v48;
      v44 = dword_51B73C;
      dword_50BADC[v45] = dword_51B73C;
    }
    if ( v86 )
    {
      dword_50BAE0[v45] = *(int *)((char *)dword_50BAEC + v46);
      dword_50B9F0[v45++] = *(int *)((char *)dword_50B9FC + v46);
    }
    ++v92;
    v79 = v86;
  }
  while ( v92 <= v37 );
  if ( !v45 )
    return 0;
  v52 = 0;
  dword_50BAE0[v45] = dword_50BAE0[0];
  dword_50B9F0[v45] = dword_50B9F0[0];
  v49 = dword_51B738;
  v50 = dword_50B9F0[0] < dword_51B738;
  LOBYTE(v50) = dword_50B9F0[0] >= dword_51B738;
  v51 = 1;
  v93 = 1;
  if ( v45 < 1 )
    return 0;
  do
  {
    v53 = 4 * v51;
    v54 = *(int *)((char *)dword_50B9F0 + v53);
    v87 = v54 >= v49;
    if ( v50 ^ v87 )
    {
      if ( v54 >= v49 )
      {
        v73 = (v49 - *(int *)((char *)dword_50B9EC + v53))
            * (signed __int64)(*(int *)((char *)dword_50BAE0 + v53) - *(int *)((char *)dword_50BADC + v53))
            / (v54 - *(int *)((char *)dword_50B9EC + v53));
        v55 = *(int *)((char *)dword_50BADC + v53);
      }
      else
      {
        v73 = (v49 - v54)
            * (signed __int64)(*(int *)((char *)dword_50BADC + v53) - *(int *)((char *)dword_50BAE0 + v53))
            / (*(int *)((char *)dword_50B9EC + v53) - v54);
        v55 = *(int *)((char *)dword_50BAE0 + v53);
      }
      ++v52;
      dword_50BAD0[v52] = v73 + v55;
      v49 = dword_51B738;
      dword_50B9E0[v52] = dword_51B738;
    }
    v50 = v87;
    if ( v87 )
    {
      dword_50BAD4[v52] = *(int *)((char *)dword_50BAE0 + v53);
      dword_50B9E4[v52++] = *(int *)((char *)dword_50B9F0 + v53);
    }
    v51 = v93 + 1;
    compile_error;//v58 = __SETO__(v93 + 1, v45);
    v56 = v93 + 1 == v45;
    v57 = v93++ + 1 - v45 < 0;
  }
  while ( (unsigned __int8)(v57 ^ v58) | v56 );
  if ( !v52 )
    return 0;
  v60 = 0;
  dword_50BAD4[v52] = dword_50BAD4[0];
  dword_50B9E4[v52] = dword_50B9E4[0];
  v59 = dword_51B740;
  v80 = dword_50B9E4[0] <= dword_51B740;
  v94 = 1;
  if ( v52 < 1 )
    return 0;
  do
  {
    v61 = 4 * v94;
    v62 = dword_50B9E4[v94];
    v88 = v62 <= v59;
    if ( v80 ^ v88 )
    {
      if ( v62 <= v59 )
      {
        v74 = (v59 - *(int *)((char *)dword_50B9E0 + v61))
            * (signed __int64)(*(int *)((char *)dword_50BAD4 + v61) - *(int *)((char *)dword_50BAD0 + v61))
            / (v62 - *(int *)((char *)dword_50B9E0 + v61));
        v63 = *(int *)((char *)dword_50BAD0 + v61);
      }
      else
      {
        v74 = (v59 - v62)
            * (signed __int64)(*(int *)((char *)dword_50BAD0 + v61) - *(int *)((char *)dword_50BAD4 + v61))
            / (*(int *)((char *)dword_50B9E0 + v61) - v62);
        v63 = *(int *)((char *)dword_50BAD4 + v61);
      }
      ++v60;
      dword_50BAC4[v60] = v74 + v63;
      v59 = dword_51B740;
      dword_50B9D4[v60] = dword_51B740;
    }
    if ( v88 )
    {
      dword_50BAC8[v60] = *(int *)((char *)dword_50BAD4 + v61);
      dword_50B9D8[v60++] = *(int *)((char *)dword_50B9E4 + v61);
    }
    ++v94;
    v80 = v88;
  }
  while ( v94 <= v52 );
  if ( !v60 )
    return 0;
  v65 = pD3DRenderer->pRenderD3D3 == 0;
  dword_50BAC8[v60] = dword_50BAC8[0];
  dword_50B9D8[v60] = dword_50B9D8[0];
  if ( v65 )
  {
    if ( v60 > 3 )
    {
      dword_50BACC[v60] = dword_50BACC[0];
      dword_50B9DC[v60] = dword_50B9DC[0];
      v81 = 2 * (dword_50B700 != 0) - 1;
      if ( v60 > 0 )
      {
        v66 = 1;
        v75 = 1;
        do
        {
          v67 = v66 - 1;
          v68 = v66 + 1;
          v83 = v66 + 1;
          if ( v66 - 1 >= v60 )
            v67 -= v60;
          if ( v66 >= v60 )
            v66 -= v60;
          if ( v68 >= v60 )
            v68 -= v60;
          if ( v81
             * ((dword_50B9D8[v68] - dword_50B9D8[v67]) * (dword_50BAC8[v66] - dword_50BAC8[v67])
              - (dword_50B9D8[v66] - dword_50B9D8[v67]) * (dword_50BAC8[v68] - dword_50BAC8[v67])) < 0 )
          {
            v66 = v83;
            v75 = v83;
          }
          else
          {
            v66 = v75;
            v69 = v75;
            if ( v75 < v60 || (v69 = v75 - v60, v75 - v60 < v60) )
            {
              memcpy(&dword_50B9D8[v69], &dword_50B9DC[v69], 4 * ((unsigned int)(4 * (v60 - v69)) >> 2));
              memcpy(&dword_50BAC8[v69], &dword_50BACC[v69], 4 * ((unsigned int)(4 * (v60 - v69)) >> 2));
            }
            --v60;
          }
        }
        while ( v66 - 1 < v60 );
      }
      dword_50BAC8[v60] = dword_50BAC8[0];
      dword_50B9D8[v60] = dword_50B9D8[0];
    }
  }
  return v60;
}

//----- (00424579) --------------------------------------------------------
signed int __fastcall sub_424579(int a1, int a2)
{
  int v2; // eax@1
  int v3; // ebx@1
  int v4; // esi@1
  int v5; // esi@3
  int v7; // ST1C_4@5
  int v8; // ST1C_4@5
  int v9; // ST1C_4@5
  int v10; // ST1C_4@5
  int v11; // esi@5
  int v12; // ST1C_4@5
  int v15; // ecx@8
  int v19; // ecx@13
  int v20; // ecx@16
  signed int result; // eax@20
  signed int v23; // edx@22
  int v25; // [sp+Ch] [bp-1Ch]@3
  int v26; // [sp+14h] [bp-14h]@3
  int v27; // [sp+1Ch] [bp-Ch]@3
  int v28; // [sp+20h] [bp-8h]@3
  int v29; // [sp+24h] [bp-4h]@3

  v2 = dword_6BE644 + 96 * a1;
  v3 = dword_6BE63C;
  v4 = dword_6BE63C + 6 * **(_WORD **)(v2 + 48);
  if ( *(_DWORD *)(v2 + 16) * ((signed __int16)*(_DWORD *)v4 - dword_51B6E8)
     + *(_DWORD *)(v2 + 20) * ((signed __int16)(*(_DWORD *)v4 >> 16) - dword_51B6EC)
     + *(_DWORD *)(v2 + 24) * (*(_WORD *)(v4 + 4) - dword_51B6F0) < 0 )
  {
    dword_50B700 = 1;
  }
  else
  {
    dword_50B700 = 0;
    if ( !(*(_BYTE *)(v2 + 44) & 1) )
      return 0;
  }
  v29 = 0;
  v5 = *(_BYTE *)(v2 + 93);
  __asm { fld     flt_51B710 }
  v28 = dword_51B714;
  v26 = dword_51B718;
  v27 = dword_51B71C;
  v25 = v5;
  if ( v5 > 0 )
  {
    compile_error;//_ECX = &unk_50AC18;
    do
    {
      v7 = *(_WORD *)(v3 + 6 * *(_WORD *)(*(_DWORD *)(v2 + 48) + 2 * v29));
      __asm
      {
       int 3
        //fild    [ebp+var_10]
        fstp    dword ptr [ecx-8]
      }
      v8 = *(_WORD *)(v3 + 6 * *(_WORD *)(*(_DWORD *)(v2 + 48) + 2 * v29) + 2);
      __asm
      {
       int 3
        //fild    [ebp+var_10]
        fstp    dword ptr [ecx-4]
      }
      v9 = *(_WORD *)(v3 + 6 * *(_WORD *)(*(_DWORD *)(v2 + 48) + 2 * v29) + 4);
      __asm
      {
       int 3
        //fild    [ebp+var_10]
        fstp    dword ptr [ecx]

        add ecx, 48
      }
      v10 = *(_DWORD *)(a2 + 60) + *(_WORD *)(*(_DWORD *)(v2 + 64) + 2 * v29);
      __asm
      {
       int 3
        //fild    [ebp+var_10]
        fstp    dword ptr [ecx-14h]
      }
      v11 = *(_DWORD *)(a2 + 64) + *(_WORD *)(2 * v29++ + *(_DWORD *)(v2 + 68));
      v12 = v11;
      v5 = v25;
      __asm
      {
       int 3
        //fild    [ebp+var_10]
        fstp    dword ptr [ecx-10h]
      }
    }
    while ( v29 < v25 );
  }
  compile_error;//_EDX = &flt_50AC1C;
  if ( dword_51B6F8 )
  {
    if ( v5 > 0 )
    {
      __asm
      {
        fild    dword_51B6E8
        fild    dword_51B6EC
        fild    dword_51B6F0
      }
      compile_error;//_EAX = &unk_50AC18;
      v15 = v5;
      do
      {
        __asm
        {
         int 3

          fld     dword ptr [eax-8]
          fsub    st, st(3)
          fld     dword ptr [eax-4]
          fsub    st, st(3)
          fld     st(1)
          fmul    st, st(6)
          fld     st(1)
          //fmul    [ebp+var_8]
          fsubp   st(1), st
          //fstp    [ebp+var_4]
          fld     dword ptr [eax]
          fsub    st, st(3)

           add eax, 48
        }
        --v15;
        __asm
        {
          int 3
          //fstp    [ebp+var_10]
          //fld     [ebp+var_4]
          //fmul    [ebp+var_14]
          //fld     [ebp+var_10]
          //fmul    [ebp+var_C]

          fsubp   st(1), st
          fstp    dword ptr [eax-2Ch]
          fld     st(1)

          int 3
          //fmul    [ebp+var_8]

          fld     st(1)
          fmul    st, st(7)
          faddp   st(1), st
          fstp    dword ptr [eax-28h]
          fstp    st
          fstp    st

          int 3
          //fld     [ebp+var_4]
          //fmul    [ebp+var_C]
          //fld     [ebp+var_10]
          //fmul    [ebp+var_14]
          faddp   st(1), st
          fstp    dword ptr [eax-24h]
        }
      }
      while ( v15 );
LABEL_15:
      __asm
      {
        fstp    st
        fstp    st
        fstp    st
      }
      goto LABEL_16;
    }
  }
  else
  {
    if ( v5 > 0 )
    {
      __asm
      {
        fild    dword_51B6E8
        fild    dword_51B6EC
        fild    dword_51B6F0
      }
      compile_error;//_EAX = &flt_50AC1C;
      v19 = v5;
      do
      {
        __asm
        {
         int 3
          fld     dword ptr [eax-0Ch]
          fsub    st, st(3)
          fld     dword ptr [eax-8]
          fsub    st, st(3)
          fld     st(1)
          fmul    st, st(6)
          fld     st(1)
          //fmul    [ebp+var_8]
          fsubp   st(1), st
          fstp    dword ptr [eax]
          fld     st(1)
          //fmul    [ebp+var_8]
          fld     st(1)
          fmul    st, st(7)

          add eax, 12
        }
        --v19;
        __asm
        {
          faddp   st(1), st
          fstp    dword ptr [eax-2Ch]
          fstp    st
          fstp    st
          fld     dword ptr [eax-34h]
          fsub    st, st(1)
          fstp    dword ptr [eax-28h]
        }
      }
      while ( v19 );
      goto LABEL_15;
    }
  }
LABEL_16:
  v20 = 0;
  __asm { fstp    st }
  if ( v5 <= 0 )
    return 0;
  do
  {
    __asm
    {
      fld     dword ptr [edx]
      fcomp   dword ptr ds:byte_4D8410+114h
      fnstsw  ax
    }
    compile_error;//if ( !(HIBYTE(_AX) & 1) )
      break;
    ++v20;
    compile_error;//_EDX += 12;
  }
  while ( v20 < v5 );
  if ( v20 >= v5 )
    return 0;
  result = sub_424CD7(v5);
  if ( result > 0 )
  {
    __asm
    {
     fild    dword ptr unk_51B720
     //lea ecx, dword ptr [array_507D30[0].flt_00000C]
    }
    v23 = result;
    __asm
    {
      fmul    dword ptr ds:byte_4D8410+94h
      fild    dword_51B754
      fild    dword_51B758
    }
    do
    {
      __asm
      {
        fld1
        fdiv    dword ptr [ecx]

        add ecx, 48
      }
      --v23;
      __asm
      {
        fld     st
        fmul    dword ptr [ecx-2Ch]
        fmul    st, st(4)
        fsubr   st, st(3)
        fstp    dword ptr [ecx-24h]
        fmul    dword ptr [ecx-28h]
        fmul    st, st(3)
        fsubr   st, st(1)
        fstp    dword ptr [ecx-20h]
      }
    }
    while ( v23 );
    __asm
    {
      fstp    st
      fstp    st
      fstp    st
    }
  }
  memcpy(&array_507D30[result], array_507D30, sizeof(struct RenderVertex));
  return result;
}

//----- (00424829) --------------------------------------------------------
signed int __fastcall sub_424829(int a1, int a2, int a3, int a4)
{
  int v4; // ebx@1
  signed int v5; // edi@1
  signed int v6; // eax@3
  int v7; // edx@5
  int v8; // esi@5
  int v9; // ecx@6
  signed int v10; // eax@12
  int v11; // edi@13
  int v12; // edx@18
  int v13; // eax@22
  int v14; // edi@28
  signed int v15; // ecx@29
  int v16; // edi@30
  int v17; // edx@35
  int v18; // eax@39
  int v19; // eax@44
  int v20; // ecx@44
  int v21; // edi@45
  int v22; // edi@46
  int v23; // ecx@47
  int v24; // edx@48
  int v25; // eax@50
  int v26; // eax@55
  signed int v27; // edi@55
  int v28; // edx@56
  int v29; // edx@57
  int v30; // eax@59
  unsigned __int8 v31; // sf@59
  unsigned __int8 v32; // of@59
  int v33; // eax@64
  signed int v34; // edi@64
  int v35; // edx@65
  int v36; // eax@66
  __int16 v37; // dx@66
  __int16 v38; // dx@67
  __int16 v39; // di@67
  __int16 v40; // dx@67
  unsigned __int8 v41; // zf@68
  char v42; // sf@68
  unsigned __int8 v43; // of@68
  int v44; // edx@69
  int v45; // ecx@69
  int v46; // edi@70
  int v47; // eax@76
  int v48; // eax@81
  int v50; // eax@87
  int v51; // edx@87
  __int16 v52; // cx@88
  int v53; // esi@93
  int v54; // eax@93
  int v55; // ecx@94
  int v56; // eax@95
  int v57; // eax@97
  int v58; // [sp+Ch] [bp-34h]@44
  int v59; // [sp+10h] [bp-30h]@68
  signed int v60; // [sp+14h] [bp-2Ch]@12
  int v61; // [sp+14h] [bp-2Ch]@47
  int v62; // [sp+14h] [bp-2Ch]@76
  int v63; // [sp+14h] [bp-2Ch]@81
  int v64; // [sp+14h] [bp-2Ch]@87
  int v65; // [sp+18h] [bp-28h]@1
  signed int v66; // [sp+1Ch] [bp-24h]@29
  signed int v67; // [sp+20h] [bp-20h]@66
  signed int v68; // [sp+24h] [bp-1Ch]@3
  signed int v69; // [sp+28h] [bp-18h]@3
  signed int v70; // [sp+2Ch] [bp-14h]@5
  int v71; // [sp+2Ch] [bp-14h]@39
  int v72; // [sp+30h] [bp-10h]@22
  int v73; // [sp+34h] [bp-Ch]@12
  int v74; // [sp+34h] [bp-Ch]@29
  int v75; // [sp+34h] [bp-Ch]@46
  int v76; // [sp+34h] [bp-Ch]@75
  int v77; // [sp+34h] [bp-Ch]@80
  int v78; // [sp+38h] [bp-8h]@11
  int v79; // [sp+3Ch] [bp-4h]@1
  int v80; // [sp+48h] [bp+8h]@76
  int v81; // [sp+48h] [bp+8h]@81
  int v82; // [sp+48h] [bp+8h]@87

  v5 = a1;
  v4 = a2;
  v79 = a1;
  v65 = a2;
  if ( !a1 )
    return 0;
  if ( dword_50B700 )
  {
    v6 = 1;
    v68 = -1;
    v69 = 1;
  }
  else
  {
    v69 = -1;
    v6 = 1;
    v68 = 1;
  }
  v8 = dword_50B9D8[0];
  v70 = 0;
  v7 = dword_50B9D8[0];
  if ( a1 <= v6 )
    return 0;
  do
  {
    v9 = dword_50B9D8[v6];
    if ( v9 >= v8 )
    {
      if ( v9 > v7 )
        v7 = dword_50B9D8[v6];
    }
    else
    {
      v70 = v6;
      v8 = dword_50B9D8[v6];
    }
    ++v6;
  }
  while ( v6 < v5 );
  v78 = v7;
  if ( v7 == v8 )
    return 0;
  v10 = v70;
  v73 = 0;
  *(_DWORD *)v4 = v8;
  *(_DWORD *)(v4 + 4) = v7;
  v60 = v70;
  if ( v5 > 0 )
  {
    v11 = 4 * v70;
    do
    {
      v10 += v69;
      if ( v10 < v79 )
      {
        if ( v10 < 0 )
          v10 += v79;
      }
      else
      {
        v10 -= v79;
      }
      v12 = dword_50B9D8[v10];
      if ( v12 <= *(int *)((char *)dword_50B9D8 + v11) )
      {
        v60 = v10;
        v11 = 4 * v10;
      }
      if ( v12 == v78 )
        break;
      ++v73;
    }
    while ( v73 < v79 );
  }
  v13 = v60 + v69;
  v72 = v60 + v69;
  if ( v60 + v69 < v79 )
  {
    if ( v13 >= 0 )
      goto LABEL_27;
    v13 += v79;
  }
  else
  {
    v13 -= v79;
  }
  v72 = v13;
LABEL_27:
  if ( dword_50B9D8[v13] != dword_50B9D8[v60] )
  {
    v14 = dword_50BAC8[v60];
    v67 = v14 << 16;
    v59 = ((dword_50BAC8[v13] - v14) << 16) / (dword_50B9D8[v13] - dword_50B9D8[v60]);
    *(_WORD *)(v4 + 24 + 2 * v8) = LOWORD(dword_50BAC8[v60]);
  }
  v15 = v70;
  v74 = 0;
  v66 = v70;
  if ( v79 > 0 )
  {
    v16 = 4 * v70;
    do
    {
      v15 += v68;
      if ( v15 < v79 )
      {
        if ( v15 < 0 )
          v15 += v79;
      }
      else
      {
        v15 -= v79;
      }
      v17 = dword_50B9D8[v15];
      if ( v17 <= *(int *)((char *)dword_50B9D8 + v16) )
      {
        v66 = v15;
        v16 = 4 * v15;
      }
      if ( v17 == v78 )
        break;
      ++v74;
    }
    while ( v74 < v79 );
  }
  v18 = v68 + v66;
  v71 = v68 + v66;
  if ( v68 + v66 < v79 )
  {
    if ( v18 >= 0 )
      goto LABEL_44;
    v18 += v79;
  }
  else
  {
    v18 -= v79;
  }
  v71 = v18;
LABEL_44:
  v19 = 4 * v18;
  v20 = 4 * v66;
  v58 = *(int *)((char *)dword_50B9D8 + v19) - dword_50B9D8[v66];
  if ( *(int *)((char *)dword_50B9D8 + v19) != dword_50B9D8[v66] )
  {
    v21 = *(int *)((char *)dword_50BAC8 + v20);
    v4 = v65;
    v66 = v21 << 16;
    v58 = ((*(int *)((char *)dword_50BAC8 + v19) - v21) << 16) / v58;
    *(_WORD *)(v65 + 984 + 2 * v78) = *(_WORD *)((char *)dword_50BAC8 + v20);
  }
  v22 = v8;
  v75 = v8;
  if ( v8 <= v78 )
  {
    v61 = v4 + 984 + 2 * v8;
    v23 = v4 + 2 * v8 + 24;
    while ( 1 )
    {
      v24 = 4 * v72;
      if ( v22 >= dword_50B9D8[v72] )
      {
        if ( v22 != v78 )
          break;
      }
LABEL_57:
      v29 = 4 * v71;
      if ( v75 < dword_50B9D8[v71] || v75 == v78 )
        goto LABEL_66;
      v30 = v68 + v71;
      compile_error;//v32 = __SETO__(v68 + v71, v79);
      v31 = v68 + v71 - v79 < 0;
      v71 += v68;
      if ( v31 ^ v32 )
      {
        if ( v30 >= 0 )
          goto LABEL_64;
        v30 += v79;
      }
      else
      {
        v30 -= v79;
      }
      v71 = v30;
LABEL_64:
      v33 = 4 * v30;
      v34 = *(int *)((char *)dword_50B9D8 + v33) - *(int *)((char *)dword_50B9D8 + v29);
      if ( *(int *)((char *)dword_50B9D8 + v33) - *(int *)((char *)dword_50B9D8 + v29) > 0 )
      {
        v35 = *(int *)((char *)dword_50BAC8 + v29);
        v58 = ((*(int *)((char *)dword_50BAC8 + v33) - v35) << 16) / v34;
        v66 = v35 << 16;
      }
LABEL_66:
      *(_WORD *)(v4 + 24 - (v4 + 984) + v61) = v67 >> 16;
      *(_WORD *)v61 = v66 >> 16;
      v36 = v23 + 960;
      v37 = *(_WORD *)(v23 + 960);
      if ( *(_WORD *)v23 > v37 )
      {
        v38 = *(_WORD *)v23 ^ v37;
        v39 = *(_WORD *)v36;
        *(_WORD *)v23 = v38;
        v40 = v39 ^ v38;
        *(_WORD *)v23 ^= v40;
        *(_WORD *)v36 = v40;
      }
      v61 += 2;
      v67 += v59;
      v22 = v75 + 1;
      v66 += v58;
      v23 += 2;
      compile_error;//v43 = __SETO__(v75 + 1, v78);
      v41 = v75 + 1 == v78;
      v42 = v75++ + 1 - v78 < 0;
      if ( !((unsigned __int8)(v42 ^ v43) | v41) )
        goto LABEL_69;
    }
    v25 = v69 + v72;
    v72 = v25;
    if ( v25 < v79 )
    {
      if ( v25 >= 0 )
        goto LABEL_55;
      v25 += v79;
    }
    else
    {
      v25 -= v79;
    }
    v72 = v25;
LABEL_55:
    v26 = 4 * v25;
    v27 = *(int *)((char *)dword_50B9D8 + v26) - *(int *)((char *)dword_50B9D8 + v24);
    if ( *(int *)((char *)dword_50B9D8 + v26) - *(int *)((char *)dword_50B9D8 + v24) > 0 )
    {
      v28 = *(int *)((char *)dword_50BAC8 + v24);
      v59 = ((*(int *)((char *)dword_50BAC8 + v26) - v28) << 16) / v27;
      v67 = v28 << 16;
    }
    goto LABEL_57;
  }
LABEL_69:
  v45 = a3;
  v44 = v78;
  if ( v78 < *(_DWORD *)a3 )
    return 0;
  v46 = *(_DWORD *)(a3 + 4);
  if ( v8 > v46 )
    return 0;
  if ( v8 < *(_DWORD *)a3 )
    v8 = *(_DWORD *)a3;
  if ( v78 > v46 )
  {
    v44 = *(_DWORD *)(a3 + 4);
    v78 = *(_DWORD *)(a3 + 4);
  }
  v76 = v8;
  if ( v8 <= v44 )
  {
    v80 = v4 - a3;
    v62 = v4 + 2 * v8 + 24;
    v47 = v45 + 2 * v8 + 984;
    do
    {
      if ( *(_WORD *)(v80 + v47) >= *(_WORD *)(v47 - 960) && *(_WORD *)v62 <= *(_WORD *)v47 )
        break;
      v62 += 2;
      ++v8;
      ++v76;
      v47 += 2;
    }
    while ( v76 <= v44 );
  }
  v77 = v44;
  if ( v44 < v8 )
    return 0;
  v81 = v4 - v45;
  v63 = v4 + 2 * v44 + 24;
  v48 = v45 + 2 * v44 + 984;
  do
  {
    if ( *(_WORD *)(v48 + v81) >= *(_WORD *)(v48 - 960) && *(_WORD *)v63 <= *(_WORD *)v48 )
      break;
    v63 -= 2;
    --v44;
    --v77;
    v48 -= 2;
    v78 = v44;
  }
  while ( v77 >= v8 );
  if ( v8 >= v44 )
    return 0;
  v82 = v45 - v4;
  v64 = v45 + 2 * v8 + 984;
  v50 = v4 + 2 * v8 + 24;
  v51 = v78 - v8 + 1;
  do
  {
    v52 = *(_WORD *)(v82 + v50);
    if ( *(_WORD *)v50 < v52 )
      *(_WORD *)v50 = v52;
    if ( *(_WORD *)(v50 + 960) > *(_WORD *)v64 )
      *(_WORD *)(v50 + 960) = *(_WORD *)v64;
    v64 += 2;
    v50 += 2;
    --v51;
  }
  while ( v51 );
  *(_DWORD *)v4 = v8;
  *(_DWORD *)(v4 + 4) = v78;
  *(_DWORD *)(v4 + 8) = *(_WORD *)(v4 + 2 * v8 + 24);
  v54 = *(_WORD *)(v4 + 2 * v8 + 984);
  *(_DWORD *)(v4 + 16) = v8;
  *(_DWORD *)(v4 + 20) = v8;
  v53 = v8 + 1;
  *(_DWORD *)(v4 + 12) = v54;
  if ( v53 <= v78 )
  {
    v55 = v4 + 2 * v53 + 984;
    do
    {
      v56 = *(_WORD *)(v55 - 960);
      if ( v56 < *(_DWORD *)(v4 + 8) )
      {
        *(_DWORD *)(v4 + 8) = v56;
        *(_DWORD *)(v4 + 16) = v53;
      }
      v57 = *(_WORD *)v55;
      if ( v57 > *(_DWORD *)(v4 + 12) )
      {
        *(_DWORD *)(v4 + 12) = v57;
        *(_DWORD *)(v4 + 20) = v53;
      }
      ++v53;
      v55 += 2;
    }
    while ( v53 <= v78 );
  }
  return 1;
}

//----- (00424CD7) --------------------------------------------------------
signed int __fastcall sub_424CD7(int a1)
{
  int v1; // edx@1
  signed int v2; // edi@1
  float *v3; // edx@4
  _UNKNOWN *v4; // ecx@4
  _UNKNOWN *v5; // esi@4
  int v6; // eax@4
  double v7; // st5@10
  double v8; // st6@10
  double v9; // st6@11
  unsigned __int8 v10; // c2@15
  unsigned __int8 v11; // c3@15
  void *v12; // edi@22
  _UNKNOWN *v13; // eax@22
  double v14; // st6@22
  signed int result; // eax@24
  int v17; // [sp+8h] [bp-28h]@4
  bool v18; // [sp+Ch] [bp-24h]@6
  _UNKNOWN *v19; // [sp+10h] [bp-20h]@4
  _UNKNOWN *v20; // [sp+14h] [bp-1Ch]@4
  signed int v21; // [sp+18h] [bp-18h]@1
  _UNKNOWN *v22; // [sp+1Ch] [bp-14h]@4
  _UNKNOWN *v23; // [sp+20h] [bp-10h]@4
  _UNKNOWN *v24; // [sp+24h] [bp-Ch]@4
  _UNKNOWN *v25; // [sp+28h] [bp-8h]@4
  _UNKNOWN *v26; // [sp+2Ch] [bp-4h]@4

  v1 = a1;
  memcpy(&array_50AC10[a1], array_50AC10, sizeof(struct RenderVertex));
  v2 = 0;
  v21 = 0;
  if ( array_50AC10[0].flt_00000C >= 8.0 )
    v2 = 1;
  if ( a1 + 1 <= 1 )
    return 0;
  v5 = (char *)&array_507D30[0].flt_000014;
  v4 = (char *)&array_507D30[0].flt_000010;
  v6 = v1;
  v24 = (char *)&array_507D30[0].flt_000020;
  v22 = (char *)array_507D30;
  v19 = (char *)&array_507D30[0].flt_000014;
  v20 = (char *)&array_507D30[0].flt_000010;
  v23 = (char *)&array_507D30[0].flt_00000C;
  v25 = (char *)&array_507D30[0].v;
  v26 = (char *)&array_507D30[0].u;
  v3 = &array_50AC10[0].v;
  v17 = v6;
  do
  {
    v18 = v3[5] >= 8.0;
    if ( v2 != v18 )
    {
      if ( v18 )
      {
        v8 = (8.0 - *(v3 - 7)) / (v3[5] - *(v3 - 7));
        *(float *)v4 = (v3[6] - *(v3 - 6)) * v8 + *(v3 - 6);
        *(float *)v5 = (v3[7] - *(v3 - 5)) * v8 + *(v3 - 5);
        *(float *)v26 = (v3[11] - *(v3 - 1)) * v8 + *(v3 - 1);
        v7 = (v3[12] - *v3) * v8 + *v3;
      }
      else
      {
        v9 = (8.0 - v3[5]) / (*(v3 - 7) - v3[5]);
        *(float *)v4 = (*(v3 - 6) - v3[6]) * v9 + v3[6];
        *(float *)v5 = (*(v3 - 5) - v3[7]) * v9 + v3[7];
        *(float *)v26 = (*(v3 - 1) - v3[11]) * v9 + v3[11];
        v7 = (*v3 - v3[12]) * v9 + v3[12];
      }
      *(float *)v25 = v7;
      *(float *)v23 = 8.0;
      *(_DWORD *)v24 = 1040187392;
      if ( v2 )
      {
        if ( 8.0 == *(v3 - 7) && *(float *)v4 == *(v3 - 6) )
        {
          v10 = 0;
          v11 = *(float *)v5 == *(v3 - 5);
          goto LABEL_19;
        }
      }
      else
      {
        if ( 8.0 == v3[5] && *(float *)v4 == v3[6] )
        {
          v10 = 0;
          v11 = *(float *)v5 == v3[7];
LABEL_19:
          if ( v11 | v10 )
            goto LABEL_21;
          goto LABEL_20;
        }
      }
LABEL_20:
      v22 = (char *)v22 + 48;
      v23 = (char *)v23 + 48;
      v25 = (char *)v25 + 48;
      v26 = (char *)v26 + 48;
      v4 = (char *)v4 + 48;
      v5 = (char *)v5 + 48;
      ++v21;
      v24 = (char *)v24 + 48;
      v20 = v4;
      v19 = v5;
    }
LABEL_21:
    if ( v18 )
    {
      v12 = v22;
      v13 = v24;
      v20 = (char *)v20 + 48;
      v19 = (char *)v19 + 48;
      v14 = 1.0 / (v3[5] + 0.0000001000000011686097);
      ++v21;
      v26 = (char *)v26 + 48;
      v25 = (char *)v25 + 48;
      v23 = (char *)v23 + 48;
      v22 = (char *)v22 + 48;
      v24 = (char *)v24 + 48;
      memcpy(v12, v3 + 2, 0x30u);
      v4 = v20;
      v5 = v19;
      *(float *)v13 = v14;
    }
    v2 = v18;
    v3 += 12;
  }
  while ( v17-- != 1 );
  result = v21;
  if ( v21 < 3 )
    return 0;
  return result;
}