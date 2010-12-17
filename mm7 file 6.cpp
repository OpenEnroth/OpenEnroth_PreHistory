#include <ddraw.h>
//#include <dinput.h>

#include "defs.h"
#include "localization_defs.h"
#include "font.h"

#include "AIL.h"
#include "clock.h"
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



int __fastcall ReadWindowsRegistryString(char const *,unsigned char *,unsigned int,unsigned char const *)
{
 __asm int 3 ; who-wo
 return 0;
}

//----- (0048D1FE) --------------------------------------------------------
bool __thiscall sub_48D1FE(void *_this, signed int a2)
{
  bool result; // eax@1
  void *v3; // ebx@1
  int v4; // ebx@2
  int v5; // edi@2
  int v6; // esi@2
  int v7; // edx@4
  char v8; // zf@4
  int v9; // esi@5
  int v10; // ebx@6
  int v11; // edx@7
  __int16 v12; // ax@19
  signed int v13; // [sp-Ch] [bp-20h]@13
  void *v14; // [sp+4h] [bp-10h]@1
  signed int v15; // [sp+8h] [bp-Ch]@2
  int v16; // [sp+Ch] [bp-8h]@3
  int v17; // [sp+10h] [bp-4h]@1

  v17 = 0;
  v3 = _this;
  v14 = _this;
  result = Player_sub_48D6AA((Player *)_this, 2);
  if ( result )
  {
    v4 = (int)((char *)v3 + 36 * *((_DWORD *)v3 + 1620) + 496);
    v5 = *(_DWORD *)v4;
    v6 = 48 * *(_DWORD *)v4;
    //v15 = (unsigned __int8)byte_5D2A00[v6 + 3];
    v15 = pClass40->pItems[*(_DWORD *)v4 - 1].uDamageRoll;
    //if ( (signed int)(unsigned __int8)byte_5D2A00[v6 + 2] > 0 )
    if ((signed)pClass40->pItems[*(_DWORD *)v4 - 1].uDamageDice > 0)
    {
      //v16 = (unsigned __int8)byte_5D2A00[v6 + 2];
     v16 = pClass40->pItems[*(_DWORD *)v4 - 1].uDamageDice;
      do
      {
        v7 = rand() % v15;
        v8 = v16-- == 1;
        v17 += v7 + 1;
      }
      while ( !v8 );
    }
    //v9 = (unsigned __int8)byte_5D2A00[v6 + 4] + v17;
    v9 = pClass40->pItems[*(_DWORD *)v4 - 1].uDamageModifier + v17;
    if ( !a2 )
      goto LABEL_19;
    v10 = *(_DWORD *)(v4 + 12);
    if ( v10 == 64 )
    {
      v11 = 1;
    }
    else
    {
      if ( v10 == 39 || v5 == 508 )
      {
        v13 = 2;
      }
      else
      {
        if ( v10 == 40 )
        {
          v13 = 3;
        }
        else
        {
          if ( v10 != 63 && v5 != 517 )
            goto LABEL_19;
          v13 = 4;
        }
      }
      v11 = v13;
    }
    if ( sub_438BDF(a2, v11) )
      v9 *= 2;
LABEL_19:
    v12 = *((_WORD *)v14 + 137);
    if ( v12 )
    {
      if ( sub_458244_GetSkillMasteryLevel(v12) >= 4 )
        v9 += *((_BYTE *)v14 + 274) & 0x3F;
    }
    result = v9;
  }
  return result;
}

//----- (0048D45A) --------------------------------------------------------
bool __thiscall sub_48D45A(int _this)
{
  int v1; // eax@1
  int v2; // edx@1
  int i; // esi@1
  __int64 v4; // qax@3
  int v5; // esi@3

  v2 = *(_WORD *)(_this + 218);
  v1 = 0;
  for ( i = 0; i < v2; ++i )
    v1 += i + 1;
  v5 = *(_DWORD *)(_this + 164);
  v4 = 1000 * v1;
  return v5 >= HIDWORD(v4) && (v5 > HIDWORD(v4) || *(_DWORD *)(_this + 160) >= (_DWORD)v4);
}

//----- (0048D498) --------------------------------------------------------
unsigned int __thiscall Player_sub_48D498(int _this)
{
  unsigned int result; // eax@2

  if ( sub_48D45A(_this) )
    result = 0xFF00FF00;
  else
    result = 0;
  return result;
}

//----- (0048D4B3) --------------------------------------------------------
signed int __thiscall Player_sub_48D4B3(struct Player *_this, int a2, signed int a3)
{
  int v3; // esi@1
  int v4; // edi@8
  int v6; // eax@21
  signed int v7; // ebx@21
  int v8; // eax@22
  signed int v9; // ebx@22
  int v10; // eax@23
  signed int v11; // ebx@23
  int v12; // eax@24
  signed int v13; // edi@24
  int v14; // eax@27
  int v15; // eax@29
  double v16; // st7@32
  signed int v17; // [sp-4h] [bp-10h]@9
  signed int v18; // [sp+8h] [bp-4h]@17

  v3 = (int)_this;
  if ( !a2 )
  {
    v17 = 10;
    goto LABEL_16;
  }
  if ( a2 == 1 )
  {
    v17 = 11;
    goto LABEL_16;
  }
  if ( a2 == 2 )
  {
    v17 = 12;
    goto LABEL_16;
  }
  if ( a2 == 3 )
  {
    v17 = 13;
    goto LABEL_16;
  }
  if ( a2 == 6 )
  {
    v17 = 33;
    goto LABEL_16;
  }
  if ( a2 == 7 )
  {
    v17 = 14;
    goto LABEL_16;
  }
  if ( a2 == 8 )
  {
    v17 = 15;
LABEL_16:
    v4 = Player_GetActualResistance(_this, v17);
    goto LABEL_17;
  }
  v4 = 0;
LABEL_17:
  v18 = a3;
  if ( *(_BYTE *)(v3 + 185) == 35 && v4 >= 200 )
    return 0;
  if ( v4 )
  {
    v6 = Player_GetActualLuck(_this);
    v7 = sub_48EA1B(v6) + v4 + 30;
    if ( rand() % v7 >= 30 )
    {
      v18 = a3 >> 1;
      v8 = Player_GetActualLuck(_this);
      v9 = sub_48EA1B(v8) + v4 + 30;
      if ( rand() % v9 >= 30 )
      {
        v18 = a3 >> 2;
        v10 = Player_GetActualLuck(_this);
        v11 = sub_48EA1B(v10) + v4 + 30;
        if ( rand() % v11 >= 30 )
        {
          v18 = a3 >> 3;
          v12 = Player_GetActualLuck(_this);
          v13 = sub_48EA1B(v12) + v4 + 30;
          if ( rand() % v13 >= 30 )
            v18 = a3 >> 4;
        }
      }
    }
  }
  if ( a2 == 4 )
  {
    v14 = *(_DWORD *)(v3 + 6484);
    if ( v14 )
    {
      if ( !(*(_BYTE *)(v3 + 36 * v14 + 516) & 2) )
      {
        v15 = sub_48D651_GetSomeItemSkillType((Player *)v3, 3) - 10;
        if ( v15 )
        {
          if ( v15 != 1 || sub_458244_GetSkillMasteryLevel(*(_WORD *)(v3 + 286)) < 3 )
            return v18;
          v16 = (double)v18 * 0.5;
          return (signed __int64)v16;
        }
        if ( sub_458244_GetSkillMasteryLevel(*(_WORD *)(v3 + 284)) >= 4 )
        {
          v16 = (double)v18 * 0.666700005531311;
          return (signed __int64)v16;
        }
      }
    }
  }
  return v18;
}

//----- (0048D62C) --------------------------------------------------------
int __thiscall sub_48D62C_GetSomeItemEquipType(Player *_this, int a2)
{
  //return (unsigned __int8)byte_5D2A00[48 * *((_DWORD *)_this + 9 * *((_DWORD *)_this + a2 + 1618) + 124)];
 return pClass40->pItems[*((_DWORD *)_this + 9 * *((_DWORD *)_this + a2 + 1618) + 124)].uEquipType;
}

//----- (0048D651) --------------------------------------------------------
int __thiscall sub_48D651_GetSomeItemSkillType(Player *_this, int a2)
{
  return pClass40->pItems[*((_DWORD *)_this + 9 * *((_DWORD *)_this + a2 + 1618) + 124)].uSkillType;
}

//----- (0048D676) --------------------------------------------------------
bool __thiscall Player_sub_48D676(Player *_this)
{
  return Player_sub_48D6AA(_this, 1) != 1 &&
         (Player_sub_48D6AA(_this, 0) != 1 || sub_48D62C_GetSomeItemEquipType(_this, 0) == 4);
}

//----- (0048D709) --------------------------------------------------------
signed int Player_sub_48D709(struct Player *_this, int a2, int a3)
{
  int v3; // edx@2
  int v4; // ecx@2
  int v6; // esi@5
  int v7; // edx@6

  if ( a3 >= 16 )
  {
    v6 = 0;
    while (!Player_sub_48D6AA(_this, v6) || _this->cInventorySlots[a3 - 1].uItemID != a2 )
    {
      ++v6;
      if ( v6 >= 16 )
        return false;
    }
    return true;
  }
  if ( Player_sub_48D6AA(_this, a3) && *(_DWORD *)(v4 + 36 * *(_DWORD *)(v4 + 4 * v3 + 6472) + 496) == a2 )
    return true;
  return false;
}

//----- (0048D76C) --------------------------------------------------------
bool __thiscall sub_48D76C(int _this, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // eax@8
  __int16 v7; // cx@8
  signed int v8; // ebx@8
  int v9; // edi@8
  int v10; // esi@8
  int v11; // edi@12
  bool result; // eax@13

  if ( !a2
    || *(_QWORD *)(_this + 128)
    || *(_QWORD *)(_this + 112)
    || *(_QWORD *)(_this + 120)
    || *(_QWORD *)(_this + 32)
    || *(_QWORD *)(_this + 104)
    || *(_QWORD *)(_this + 16) )
  {
    result = 0;
  }
  else
  {
    v7 = *(_WORD *)(_this + 332);
    v9 = v7 & 0x3F;
    v8 = sub_458244_GetSkillMasteryLevel(v7);
    v10 = ItemGen_sub_456442((ItemGen *)a2);
    v6 = pClass40->pItems[*(_DWORD *)a2 - 1].uEquipType;
    if ( !pClass40->pItems[*(_DWORD *)a2 - 1].uEquipType || v6 == 1 || v6 == 2 )
      v10 *= 3;
    v11 = dword_4EDEB4[rand() % 100 / 20] + v9 * dword_4EDEA4[v8-1];
    *(_DWORD *)a6 = 100 * (a4 + a3) + v10 + (a5 != 0 ? 0x1F4 : 0);
    if ( rand() % 100 >= 5 )
    {
      if ( *(_DWORD *)a6 > v11 )
        result = *(_DWORD *)a6 - v11 < 500;
      else
        result = 2;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (0048D88B) --------------------------------------------------------
signed int __thiscall sub_48D88B(int _this, int a2, int a3, int a4)
{
  char *v4; // edi@1
  int v5; // esi@1
  __int16 v6; // cx@10
  int v7; // ebx@10
  int v8; // esi@10
  signed int v9; // esi@10
  int v10; // eax@13
  signed int v11; // edx@15
  int v12; // ecx@15
  signed int v13; // ebx@15
  __int16 v14; // si@21
  int v15; // ebx@24
  int v16; // esi@24
  int v17; // eax@29
  int v18; // esi@31
  int v19; // eax@34
  char v20; // zf@36
  const char *v21; // esi@39
  int v22; // ST0C_4@39
  int v24; // [sp-Ch] [bp-48h]@40
  int v25; // [sp-8h] [bp-44h]@40

  struct ItemGen local_08;
  //int v26; // [sp+8h] [bp-34h]@15
  //int v27; // [sp+Ch] [bp-30h]@28
  //int v28; // [sp+18h] [bp-24h]@25

  int v29; // [sp+2Ch] [bp-10h]@10
  int v30; // [sp+30h] [bp-Ch]@10
  int v31; // [sp+34h] [bp-8h]@10
  int v32; // [sp+38h] [bp-4h]@1
  signed int v33; // [sp+48h] [bp+Ch]@12

  v5 = _this;
  v4 = (char *)pActors + 836 * a2;
  v32 = _this;
  if ( (_UNKNOWN *)((char *)pActors + 836 * a2)
    && !*(_QWORD *)(_this + 128)
    && !*(_QWORD *)(_this + 112)
    && !*(_QWORD *)(_this + 120)
    && !*(_QWORD *)(_this + 32)
    && !*(_QWORD *)(_this + 104)
    && !*(_QWORD *)(_this + 16) )
  {
    if ( !(v4[38] & 0x80) )
      sub_4086E9((int)((char *)pActors + 836 * a2));
    v6 = *(_WORD *)(v5 + 332);
    v7 = v6 & 0x3F;
    v9 = sub_458244_GetSkillMasteryLevel(v6);
    v29 = 4 * v9;
    v31 = dword_4EDEA4[v9-1];
    v30 = dword_4EDEB4[rand() % 100 / 20];
    v8 = (unsigned __int8)v4[52] + 100 * (a3 + a4);
    if ( rand() % 100 < 5 || v8 > v30 + v7 * v31 || (v33 = 2, v4[38] & 8) )
    {
      sub_43AC45(a2, 1);
      v33 = 0;
      v25 = v32 + 168;
      v24 = (int)pGlobalTXT_LocalizationStrings[376];
    }
    else
    {
      v10 = rand();
      if ( v10 % 100 >= 40 )
      {
        if ( v10 % 100 >= 70 )
        {
          v18 = 0;
          if ( v7 > 0 )
          {
            do
            {
              --v7;
              v18 += rand() % *(int *)((char *)&dword_4EDEC4 + v29) + 1;
            }
            while ( v7 );
          }
          if (pClass40->pItems[*((_DWORD *)v4 + 168) - 1].uEquipType != 18 )
            return v33;
          v19 = (int)(v4 + 684);
          if ( v18 > *((_DWORD *)v4 + 171) )
            v18 = *((_DWORD *)v4 + 171);
          v20 = *(_DWORD *)v19 == v18;
          *(_DWORD *)v19 -= v18;
          if ( v20 )
            *((_DWORD *)v4 + 168) = 0;
          if ( v18 )
          {
            sub_420C05(v18, 2);
            v22 = v18;
            v21 = (char *)pStringBuffer;
            wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[302], v32 + 168, v22);
LABEL_43:
            sub_44C175(v21, 2);
            return v33;
          }
        }
        else
        {
          ItemGen_Reset(&local_08);
          v13 = 0;
          v11 = 0;
          v12 = (int)(v4 + 564);
          while ( !*(_DWORD *)v12 || pClass40->pItems[*(_DWORD *)v12 - 1].uEquipType == 18 )
          {
            ++v11;
            v12 += 36;
            if ( v11 >= 4 )
              goto LABEL_21;
          }
          v13 = 1;
LABEL_21:
          v14 = *((_WORD *)v4 + 90);
          if ( v14 || v13 )
          {
            ItemGen_Reset(&local_08);
            if ( v14 )
            {
              v15 = v14;
              *((_WORD *)v4 + 90) = 0;
              local_08.uItemID = v14;
              v16 = 48 * v14;
              if (pClass40->pItems[v14 - 1].uEquipType == 12 )
               local_08.dword_000010 = rand() % 6 + pClass40->pItems[v14 - 1].uDamageModifier + 1;
              if (pClass40->pItems[v14 - 1].uEquipType == 14 )
              {
                if ( v15 != 220 )
                 local_08.dword_000004 = 2 * rand() % 4 + 2;
              }
            }
            else
            {
              v17 = (int)&v4[36 * rand() % 4 + 564];
              memcpy(&local_08, (const void *)v17, 0x24u);
              ItemGen_Reset((ItemGen *)v17);
              v15 = local_08.uItemID;
            }
            sub_421B2C();
            wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[304], v32 + 168, dword_5D29EC[12 * v15]);
            sub_44C175((char *)pStringBuffer, 2);
            sub_421B2C();
            memcpy(&pParty_global->pickedItem, &local_08, sizeof(struct ItemGen));
            SetCursorBitmapFromItemID(v15);
            return v33;
          }
        }
      }
      v25 = v32 + 168;
      v24 = (int)pGlobalTXT_LocalizationStrings[377];
    }
    v21 = (char *)pStringBuffer;
    wsprintfA((char *)pStringBuffer, (const char *)v24, v25);
    goto LABEL_43;
  }
  return 0;
}

//----- (0048DBB9) --------------------------------------------------------
int __thiscall Player_sub_48DBB9(int _this, int a2)
{
  int result; // eax@1
  int v3; // esi@1
  signed int v4; // eax@3

  v3 = _this;
  result = *(_DWORD *)(_this + 132) | *(_DWORD *)(_this + 128);
  if ( !*(_QWORD *)(_this + 128) )
  {
    result = *(_DWORD *)(_this + 116) | *(_DWORD *)(_this + 112);
    if ( !*(_QWORD *)(_this + 112) )
    {
      v4 = Player_GetMaxHealth((Player *)_this);
      if ( *(_QWORD *)(v3 + 136) )
        v4 /= 2;
      *(_DWORD *)(v3 + 6460) += a2;
      if ( *(_DWORD *)(v3 + 6460) > v4 )
        *(_DWORD *)(v3 + 6460) = v4;
      result = *(_DWORD *)(v3 + 108) | *(_DWORD *)(v3 + 104);
      if ( *(_QWORD *)(v3 + 104) )
      {
        result = 0;
        if ( *(_DWORD *)(v3 + 6460) > 0 )
        {
          *(_DWORD *)(v3 + 104) = 0;
          *(_DWORD *)(v3 + 108) = 0;
        }
      }
    }
  }
  return result;
}

//----- (0048DC1E) --------------------------------------------------------
signed int __thiscall Player_sub_48DC1E(struct Player *_this, signed int a2, int a3)
{
  bool v3; // ebx@1
  signed int v5; // eax@1
  int v7; // eax@8
  int v8; // eax@9
  int v9; // ecx@9
  signed int v11; // [sp+14h] [bp+8h]@1

 _this->pConditions[2] = 0;
  v5 = Player_sub_48D4B3(_this, a3, a2);
 _this->sHealth -= v5;
  v11 = v5;

  v3 = _this->sHealth < -10;
  LOBYTE(v3) = _this->sHealth <= -10;
  if (_this->sHealth < 1 )
  {
    if (_this->sHealth + _this->uEndurance + Player_MaybeGetWearItemsBonus(_this, 3, 0) >= 1
      || *(_QWORD *)((char *)_this + 6224) > 0i64 )
    {
      Player_sub_492D65(_this, 13, 0);
    }
    else
    {
      Player_sub_492D65(_this, 14, 0);
      v3 = pParty_global->qword_00002C;
      if (_this->sHealth > 0 )
        _this->sHealth = 0;
    }
    if ( v3 )
    {
      v7 = _this->pEquppedItemIndices[3];
      if ( v7 )
      {
        v9 = (int)((char *)&_this->cInventorySlots[v7] - 0x10);
        v8 = *(_DWORD *)v9;
        if ( !(BYTE1(v8) & 2) )
        {
          LOBYTE(v8) = v8 | 2;
          *(_DWORD *)v9 = v8;
        }
      }
    }
  }
  if ( v11 )
  {
    if (Player_sub_492C0B_MaybeIfPlayerConscious(_this))
      Player_PlaySound(_this, 24, 0);
  }
  return v11;
}

//----- (0048DCF6) --------------------------------------------------------
signed int __thiscall sub_48DCF6(char *Dst, int a2, int a3)
{
  signed int v3; // ebx@1
  signed int v4; // edi@1
  int v5; // esi@1
  int v6; // eax@2
  int v7; // eax@5
  int v8; // ebx@8
  int v9; // eax@8
  int v10; // ebx@8
  int v11; // eax@8
  char *v12; // eax@9
  signed int v13; // edx@9
  int v14; // edx@16
  int v15; // edx@17
  int v16; // edx@26
  int v17; // edx@27
  void *v18; // ecx@32
  signed int v19; // edx@38
  char *v20; // ecx@38
  signed int v21; // eax@40
  int v22; // eax@49
  signed int v23; // ebx@49
  int v24; // eax@60
  int v25; // ecx@61
  int v26; // ebx@74
  int v27; // ecx@76
  int v28; // ebx@78
  signed int result; // eax@86
  int v30; // [sp-20h] [bp-C0h]@56
  signed int v31; // [sp-1Ch] [bp-BCh]@56
  int v32; // [sp-18h] [bp-B8h]@56
  signed int v33; // [sp-14h] [bp-B4h]@56
  int v34; // [sp-10h] [bp-B0h]@56
  int v35; // [sp-Ch] [bp-ACh]@56
  int v36; // [sp-8h] [bp-A8h]@51
  int v37; // [sp-8h] [bp-A8h]@56
  int v38; // [sp-8h] [bp-A8h]@57
  int v39; // [sp-8h] [bp-A8h]@68
  signed int v40; // [sp-4h] [bp-A4h]@4
  int v41; // [sp-4h] [bp-A4h]@51
  int v42; // [sp-4h] [bp-A4h]@56
  int v43; // [sp-4h] [bp-A4h]@57
  signed int v44; // [sp-4h] [bp-A4h]@59
  int v45; // [sp-4h] [bp-A4h]@68
  char v46[140]; // [sp+Ch] [bp-94h]@13
  int v47; // [sp+98h] [bp-8h]@1
  int v48; // [sp+9Ch] [bp-4h]@1

  v4 = 0;
  v3 = 0;
  v5 = (int)Dst;
  v47 = 0;
  v48 = 0;
  switch ( a2 )
  {
    case 1:
      v6 = Player_GetActualWillpower((Player *)Dst);
      goto LABEL_46;
    case 2:
    case 3:
    case 4:
    case 9:
    case 10:
    case 11:
    case 13:
    case 21:
      v6 = Player_GetActualEndurance((Player *)Dst);
      goto LABEL_46;
    case 5:
    case 12:
    case 23:
      v40 = 14;
      goto LABEL_5;
    case 15:
      v40 = 13;
      goto LABEL_5;
    case 6:
    case 7:
    case 8:
    case 14:
    case 16:
      v40 = 15;
LABEL_5:
      v7 = Player_GetActualResistance((Player *)Dst, v40);
      goto LABEL_47;
    case 22:
      v9 = Player_GetActualWillpower((Player *)Dst);
      v10 = sub_48EA1B(v9);
      v11 = Player_GetActualIntelligence((Player *)v5);
      v8 = (sub_48EA1B(v11) + v10) >> 1;
      break;
    case 17:
      v13 = 0;
      v12 = Dst + 532;
      do
      {
        if ( *(_DWORD *)v12 > 0 )
        {
          if ( *(_DWORD *)v12 <= 134 )
          {
            if ( !(v12[20] & 2) )
              v46[v3++] = v13;
          }
        }
        ++v13;
        v12 += 36;
      }
      while ( v13 < 138 );
      goto LABEL_36;
    case 18:
      v14 = 0;
      do
      {
        if ( Player_sub_48D6AA((Player *)v5, v14) )
        {
          if ( v15 == 3 )
            v46[v3++] = *(_BYTE *)(v5 + 6484) - 1;
          if ( !v15 || v15 == 1 )
          {
            if ( sub_48D62C_GetSomeItemEquipType((Player *)v5, v15) == 4 )
              v46[v3++] = *(_BYTE *)(v5 + 4 * v15 + 6472) - 1;
          }
        }
        v14 = v15 + 1;
      }
      while ( v14 < 16 );
      goto LABEL_36;
    case 19:
      v16 = 0;
      do
      {
        if ( Player_sub_48D6AA((Player *)v5, v16) )
        {
          if ( v17 == 2 )
            v46[v3++] = *(_BYTE *)(v5 + 6480) - 1;
          if ( !v17 || v17 == 1 )
          {
            if ( !sub_48D62C_GetSomeItemEquipType((Player *)v5, v17) || sub_48D62C_GetSomeItemEquipType((Player *)v18, v17) == 1 )
              v46[v3++] = *(_BYTE *)(v5 + 4 * v17 + 6472) - 1;
          }
        }
        v16 = v17 + 1;
      }
      while ( v16 < 16 );
LABEL_36:
      if ( !v3 )
        goto LABEL_87;
      v48 = v5 + 36 * (unsigned __int8)v46[rand() % v3] + 532;
      v8 = 3 * (pClass40->pItems[*(_DWORD *)v48 - 1].uMaterial + pClass40->pItems[*(_DWORD *)v48 - 1].uDamageModifier);
      break;
    case 20:
      v19 = 0;
      v20 = Dst + 5500;
      do
      {
        if ( *(_DWORD *)v20 > 0 )
        {
          v21 = *(_DWORD *)(v5 + 36 * *(_DWORD *)v20 + 496);
          if ( v21 > 0 )
          {
            if ( v21 <= 134 )
              v46[v3++] = v19;
          }
        }
        ++v19;
        v20 += 4;
      }
      while ( v19 < 126 );
      if ( !v3 )
        goto LABEL_87;
      v47 = (unsigned __int8)v46[rand() % v3];
      v6 = Player_GetActualAccuracy((Player *)v5);
LABEL_46:
      v7 = sub_48EA1B(v6);
LABEL_47:
      v8 = v7;
      break;
    default:
      v8 = 0;
      break;
  }
  v22 = Player_GetActualLuck((Player *)v5);
  v23 = sub_48EA1B(v22) + v8 + 30;
  if ( rand() % v23 >= 30 )
  {
LABEL_87:
    result = 0;
  }
  else
  {
    switch ( a2 )
    {
      case 1:
        v41 = 1;
        v36 = 0;
        goto LABEL_56;
      case 2:
        v41 = 1;
        v36 = 1;
        goto LABEL_56;
      case 3:
        v41 = 1;
        v36 = 2;
        goto LABEL_56;
      case 23:
        v41 = 1;
        v36 = 3;
        goto LABEL_56;
      case 4:
        v41 = 1;
        v36 = 4;
LABEL_56:
        Player_sub_492D65((Player *)v5, v36, v41);
        v42 = 0;
        v37 = 0;
        v35 = 0;
        v34 = 0;
        v33 = -1;
        v32 = 0;
        v31 = 0;
        v30 = 221;
        goto LABEL_83;
      case 5:
        v43 = 1;
        v38 = 5;
        goto LABEL_70;
      case 6:
      case 7:
      case 8:
        if ( a2 == 6 )
        {
          v44 = 6;
          goto LABEL_60;
        }
        v25 = 2 * (a2 != 8) + 8;
        goto LABEL_65;
      case 9:
        if ( a2 == 6 )
        {
          v44 = 7;
LABEL_60:
          v24 = v44;
        }
        else
        {
          v25 = 2 * (a2 != 8) + 9;
LABEL_65:
          v24 = v25;
        }
        Player_sub_492D65((Player *)v5, v24, 1);
        v42 = 0;
        v37 = 0;
        v35 = 0;
        v34 = 0;
        v33 = -1;
        v32 = 0;
        v31 = 0;
        v30 = 222;
LABEL_83:
        AudioPlayer_sub_4AA306(pAudioPlayer, v30, v31, v32, v33, v34, v35, v37, v42);
        do
        {
LABEL_84:
          if ((Player *)v5 == pPlayers[v4] )
            break;
          ++v4;
        }
        while ( v4 < 4 );
        sub_4A89BD(pGame->class06_obj, 153, v4);
        result = 1;
        break;
      case 12:
        v43 = 1;
        v38 = 12;
        goto LABEL_70;
      case 15:
        v45 = 1;
        v39 = 15;
        goto LABEL_73;
      case 13:
        v43 = 1;
        v38 = 13;
LABEL_70:
        Player_sub_492D65((Player *)v5, v38, v43);
        v42 = 0;
        v37 = 0;
        v35 = 0;
        v34 = 0;
        v33 = -1;
        v32 = 0;
        v31 = 0;
        v30 = 224;
        goto LABEL_83;
      case 14:
        v45 = 1;
        v39 = 14;
        goto LABEL_73;
      case 16:
        v45 = 1;
        v39 = 16;
LABEL_73:
        Player_sub_492D65((Player *)v5, v39, v45);
        v42 = 0;
        v37 = 0;
        v35 = 0;
        v34 = 0;
        v33 = -1;
        v32 = 0;
        v31 = 0;
        v30 = 225;
        goto LABEL_83;
      case 17:
      case 18:
      case 19:
        v26 = v48;
        if ( *(_BYTE *)(v48 + 21) & 2 )
          goto LABEL_84;
        Player_PlaySound((Player *)v5, 40, 0);
        *(_DWORD *)(v26 + 20) |= 2;
        goto LABEL_79;
      case 20:
        Player_PlaySound((Player *)v5, 40, 0);
        v27 = a3 + 564;
        if ( *(_DWORD *)(a3 + 564) )
        {
          v27 = a3 + 600;
          if ( *(_DWORD *)(a3 + 600) )
            goto LABEL_84;
        }
        v28 = v47;
        memcpy((void *)v27, (const void *)(v5 + 36 * *(_DWORD *)(v5 + 4 * v47 + 5500) + 496), 0x24u);
        Player_sub_492A36_RemoveItemFromIndexMatrix((struct Player *)v5, v28);
LABEL_79:
        v42 = 0;
        v37 = 0;
        v35 = 0;
        v34 = 0;
        v33 = -1;
        v32 = 0;
        v31 = 0;
        v30 = 47;
        goto LABEL_83;
      case 21:
        Player_PlaySound((Player *)v5, 42, 0);
        ++*(_WORD *)(v5 + 222);
        goto LABEL_82;
      case 22:
        Player_PlaySound((Player *)v5, 41, 0);
        *(_DWORD *)(v5 + 6464) = 0;
LABEL_82:
        v42 = 0;
        v37 = 0;
        v35 = 0;
        v34 = 0;
        v33 = -1;
        v32 = 0;
        v31 = 0;
        v30 = 226;
        goto LABEL_83;
      default:
        goto LABEL_87;
    }
  }
  return result;
}

//----- (0048E1A3) --------------------------------------------------------
int __stdcall sub_48E1A3(int a1)
{
  //return (unsigned __int8)byte_5CC04C[36 * a1];
 return pSpellStats->pSpellInfos[a1].uSpellSchool;
}

//----- (0048E1B5) --------------------------------------------------------
int __thiscall Player_sub_GetAttackRecoveryTime(Player *_this, int a2)
{
  int v2; // ebx@1
  int *v3; // edi@1
  int v4; // esi@1
  int v5; // eax@3
  int v6; // eax@3
  int v7; // eax@6
  int v8; // eax@9
  int v9; // eax@9
  int v10; // eax@10
  int v11; // edx@13
  int v12; // ecx@14
  int v13; // eax@15
  int v14; // ebx@18
  int v15; // eax@18
  double v16; // st7@21
  double v17; // st7@22
  __int16 v18; // cx@27
  void *v19; // ecx@28
  int v20; // eax@30
  int v21; // eax@30
  int v22; // eax@30
  int v23; // ecx@30
  signed int v24; // eax@30
  int v25; // eax@31
  int v26; // ebx@32
  int v27; // eax@32
  __int16 *v28; // ebx@36
  int v29; // eax@42
  int v30; // edi@43
  signed int v31; // eax@49
  int v32; // ecx@50
  int result; // eax@54
  float v34; // [sp+8h] [bp-38h]@27
  float v35; // [sp+Ch] [bp-34h]@18
  signed int v36; // [sp+10h] [bp-30h]@21
  float v37; // [sp+14h] [bp-2Ch]@21
  float v38; // [sp+18h] [bp-28h]@27
  int v39; // [sp+1Ch] [bp-24h]@31
  int v40; // [sp+20h] [bp-20h]@1
  int v41; // [sp+24h] [bp-1Ch]@1
  int v42; // [sp+28h] [bp-18h]@14
  int v43; // [sp+2Ch] [bp-14h]@1
  int v44; // [sp+30h] [bp-10h]@1
  int v45; // [sp+34h] [bp-Ch]@1
  int v46; // [sp+38h] [bp-8h]@1
  int v47; // [sp+3Ch] [bp-4h]@1

  v2 = 0;
  v3 = 0;
  v4 = (int)_this;
  v47 = (unsigned __int16)word_4EDED8[0];
  v43 = 0;
  v45 = 0;
  v40 = 0;
  v41 = 0;
  v44 = 0;
  v46 = 0;
  if ( a2 )
  {
    if ( !Player_sub_48D6AA((Player *)_this, 2) )
      goto LABEL_17;
    v6 = v4 + 36 * *(_DWORD *)(v4 + 6480) + 496;
    v46 = v6;
    v3 = (int *)&pClass40->pItems[*(_DWORD *)v6].pIconName;
    v5 = (unsigned __int16)word_4EDED8[*((_BYTE *)v3 + 29)];
    goto LABEL_4;
  }
  if ( Player_sub_48D676(_this) == 1 )
  {
    LOBYTE(v7) = Player_sub_48F882((Player *)v4, 31);
    if ( v7 )
    {
      v5 = (unsigned __int16)word_4EDEDC;
LABEL_4:
      v47 = v5;
      goto LABEL_17;
    }
  }
  if ( Player_sub_48D6AA((Player *)v4, 1) )
  {
    v9 = v4 + 36 * *(_DWORD *)(v4 + 6476) + 496;
    v46 = v9;
    v8 = *(_DWORD *)v9;
    v3 = (int *)&pClass40->pItems[v8].pIconName;
    if ( *((_BYTE *)v3 + 28) == 12 )
      v10 = (unsigned __int16)word_4E3C68[ dword_4E421C[v8]].word0A;
    else
      v10 = (unsigned __int16)word_4EDED8[*((_BYTE *)v3 + 29)];
    v47 = v10;
  }
  if ( Player_sub_48D6AA((Player *)v4, 0) )
  {
    v12 = v4 + 36 * *(_DWORD *)(v4 + 6472) + 496;
    v42 = (unsigned __int16)word_4EDED8[pClass40->pItems[*(_DWORD *)v12 - 1].uSkillType];
    if ( v42 > v47 )
    {
      v13 = *(_DWORD *)v12;
      v46 = v12;
      v3 = (int *)(v11 + 48 * v13);
      v47 = v42;
    }
    v2 = 0;
  }
LABEL_17:
  if ( !Player_sub_48D6AA((Player *)v4, 3) )
    goto LABEL_28;
  v14 = pClass40->pItems[*(_DWORD *)(v4 + 36 * *(_DWORD *)(v4 + 6484) + 496) - 1].uSkillType;
  sub_458244_GetSkillMasteryLevel(*(_WORD *)(v4 + 282));
  v15 = (unsigned __int16)word_4EDED8[v14];
  v35 = 1.0;
  v43 = v15;
  if ( v14 == 9 )
  {
    *(float *)&v36 = 0.0;
    goto LABEL_25;
  }
  if ( v14 == 10 )
  {
    v36 = 1056964608;
LABEL_25:
    v17 = 0.0;
    goto LABEL_26;
  }
  if ( v14 == 11 )
  {
    v17 = 0.5;
    *(float *)&v36 = 0.5;
LABEL_26:
    v37 = v17;
    v16 = 0.0;
    goto LABEL_27;
  }
  *(float *)&v36 = 1.0;
  v37 = 1.0;
  v16 = 1.0;
LABEL_27:
  v18 = *(_WORD *)(v4 + 2 * v14 + 264);
  v38 = v16;
  v43 = (signed __int64)((double)v43 * *(&v34 + sub_458244_GetSkillMasteryLevel(v18)));
  v2 = 0;
LABEL_28:
  if ( Player_sub_48D6AA((Player *)v4, v2) )
  {
    if ( sub_48D62C_GetSomeItemEquipType((Player *)v19, v2) == 4 )
    {
      v20 = 9 * *(_DWORD *)(v4 + 6472);
      v35 = 1.0;
      v21 = 3 * *(_DWORD *)(v4 + 4 * v20 + 496);
      *(float *)&v36 = 0.0;
      v22 = pClass40->pItems[v21 / 3 - 1].uSkillType;
      v37 = 0.0;
      v23 = (unsigned __int16)word_4EDED8[v22];
      v38 = 0.0;
      v45 = v23;
      v24 = sub_458244_GetSkillMasteryLevel(*(_WORD *)(v4 + 2 * v22 + 264));
      v45 = (signed __int64)((double)v45 * *(&v34 + v24));
    }
  }
  v25 = Player_GetActualSpeed((Player *)v4);
  v39 = sub_48EA1B(v25);
  v42 = v2;
  if ( v3 != (int *)v2 )
  {
    v26 = *((_BYTE *)v3 + 29);
    LOBYTE(v27) = Player_sub_48F882((Player *)v4, *((_BYTE *)v3 + 29));
    if ( v27 )
    {
      if ( v26 == 1 || v26 == 3 || v26 == 5 )
      {
        v28 = (__int16 *)(v4 + 2 * v26 + 264);
        if ( sub_458244_GetSkillMasteryLevel(*v28) >= 2 )
          v40 = *(_BYTE *)v28 & 0x3F;
      }
    }
    v2 = 0;
    if ( *((_BYTE *)v3 + 29) == 7 )
      v42 = 1;
  }
  if ( a2 == v2 )
  {
    if ( v42 == v2 )
    {
      LOBYTE(v29) = Player_sub_48F882((Player *)v4, 33);
      if ( v29 != v2 )
      {
        v30 = v29 & 0x3F;
        v44 = v29 & 0x3F;
        if ( sub_458244_GetSkillMasteryLevel(v29) >= 4 )
          v44 += v30;
      }
    }
  }
  if ( *(_DWORD *)(v4 + 6164) >= v2 )
  {
    if ( *(_DWORD *)(v4 + 6164) > v2 || *(_DWORD *)(v4 + 6160) > (unsigned int)v2 )
      v41 = 25;
  }
  v31 = 0;
  if ( v46 != v2 )
  {
    v32 = *(_DWORD *)(v46 + 12);
    if ( v32 == 59 || v32 == 41 || *(_DWORD *)v46 == 500 )
      v31 = 20;
  }
  result = v47 + v43 + v45 - v44 - v31 - v41 - v40 - v39;
  if ( result < 0 )
    result = 0;
  return result;
}

//----- (004901FC) --------------------------------------------------------
int __thiscall sub_4901FC(int _this)
{
  __int64 v1; // qax@1

  v1 = *(_DWORD *)(_this + 6432);
  switch ( (_DWORD)v1 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 8:
    case 9:
    case 0xC:
    case 0xD:
    case 0x10:
    case 0x11:
    case 0x14:
    case 0x17:
      BYTE4(v1) = 0;
      break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 0xA:
    case 0xB:
    case 0xE:
    case 0xF:
    case 0x12:
    case 0x13:
    case 0x15:
    case 0x18:
      BYTE4(v1) = 1;
      break;
    default:
      break;
  }
  *(_BYTE *)(_this + 184) = BYTE4(v1);
  return v1;
}

//----- (0049070F) --------------------------------------------------------
void *__thiscall sub_49070F(int _this)
{
  void *result; // eax@1
  int v2; // esi@1

  v2 = _this;
  *(_WORD *)(_this + 220) = 0;
  *(_WORD *)(_this + 216) = 0;
  *(_WORD *)(_this + 214) = 0;
  *(_WORD *)(_this + 210) = 0;
  *(_WORD *)(_this + 206) = 0;
  *(_WORD *)(_this + 202) = 0;
  *(_WORD *)(_this + 198) = 0;
  *(_WORD *)(_this + 194) = 0;
  *(_WORD *)(_this + 190) = 0;
  *(_DWORD *)(_this + 256) = 0;
  *(_DWORD *)(_this + 252) = 0;
  *(_DWORD *)(_this + 248) = 0;
  *(_DWORD *)(_this + 244) = 0;
  *(_DWORD *)(_this + 240) = 0;
  *(_DWORD *)(_this + 236) = 0;
  *(_DWORD *)(_this + 232) = 0;
  *(_DWORD *)(_this + 228) = 0;
  *(_DWORD *)(_this + 224) = 0;
  result = memset((void *)(_this + 6026), 0, 0x16u);
  *(_BYTE *)(v2 + 6807) = 0;
  *(_BYTE *)(v2 + 6806) = 0;
  *(_BYTE *)(v2 + 6805) = 0;
  *(_BYTE *)(v2 + 6804) = 0;
  *(_BYTE *)(v2 + 6803) = 0;
  *(_BYTE *)(v2 + 6802) = 0;
  *(_BYTE *)(v2 + 6801) = 0;
  *(_BYTE *)(v2 + 6800) = 0;
  *(_BYTE *)(v2 + 6811) = 0;
  *(_BYTE *)(v2 + 6810) = 0;
  *(_BYTE *)(v2 + 6809) = 0;
  *(_BYTE *)(v2 + 6808) = 0;
  return result;
}

//----- (004908A8) --------------------------------------------------------
char __thiscall sub_4908A8(void *_this, int a2, __int64 a3)
{
  int v3; // eax@1
  char result; // al@3

  v3 = (int)((char *)_this + 8 * a2);
  if ( *(_QWORD *)v3 && a3 < *(_QWORD *)v3 )
  {
    *(_DWORD *)v3 = 0;
    *(_DWORD *)(v3 + 4) = 0;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004909F4) --------------------------------------------------------
void __thiscall sub_4909F4(void *_this)
{
  int v1; // esi@2
  int v2; // eax@3
  __int16 v3; // cx@5
  int v4; // edx@27
  int v5; // eax@52
  int v6; // edx@53
  int v9; // ebp@61
  int v10; // ebx@62
  int v11; // edi@62
  signed int v12; // [sp+0h] [bp-4h]@2
 int i;

  if ( dword_A75070 != dword_510774 )
  {
    dword_A75070 = dword_510774;
    v1 = (int)((char *)_this + 9320);
    v12 = 4;
    do
    {
      v2 = Player_GetConditionIdx((Player *)(v1 - 6812));
      if ( v2 == 18 || v2 == 17 )
      {
        *(_WORD *)(v1 + 2) += cClock2.int_00001C;
        if ( *(_WORD *)(v1 + 2) >= *(_WORD *)(v1 + 4) )
        {
          if ( *(_WORD *)v1 != 1 || rand() % 5 )
          {
            *(_WORD *)(v1 + 2) = 0;
            *(_WORD *)v1 = 1;
            *(_WORD *)(v1 + 4) = rand() % 256 + 32;
          }
          else
          {
            v4 = rand() % 100;
            if ( v4 >= 25 )
            {
              if ( v4 >= 31 )
              {
                if ( v4 >= 37 )
                {
                  if ( v4 >= 43 )
                  {
                    if ( v4 >= 46 )
                    {
                      if ( v4 >= 52 )
                      {
                        if ( v4 >= 58 )
                        {
                          if ( v4 >= 64 )
                          {
                            if ( v4 >= 70 )
                            {
                              if ( v4 >= 76 )
                              {
                                if ( v4 >= 82 )
                                {
                                  if ( v4 >= 88 )
                                    *(_WORD *)v1 = (v4 >= 94) + 29;
                                  else
                                    *(_WORD *)v1 = 57;
                                }
                                else
                                {
                                  *(_WORD *)v1 = 56;
                                }
                              }
                              else
                              {
                                *(_WORD *)v1 = 55;
                              }
                            }
                            else
                            {
                              *(_WORD *)v1 = 54;
                            }
                          }
                          else
                          {
                            *(_WORD *)v1 = 20;
                          }
                        }
                        else
                        {
                          *(_WORD *)v1 = 19;
                        }
                      }
                      else
                      {
                        *(_WORD *)v1 = 18;
                      }
                    }
                    else
                    {
                      *(_WORD *)v1 = 17;
                    }
                  }
                  else
                  {
                    *(_WORD *)v1 = 16;
                  }
                }
                else
                {
                  *(_WORD *)v1 = 15;
                }
              }
              else
              {
                *(_WORD *)v1 = 14;
              }
            }
            else
            {
              *(_WORD *)v1 = 13;
            }
            v5 = 0;
            *(_WORD *)(v1 + 2) = 0;
            if ( pPlayerFrameTable->uNumFrames <= 0 )
            {
LABEL_56:
              v5 = 0;
            }
            else
            {
              v6 = (int)pPlayerFrameTable->pFrames;
              while ( *(_WORD *)v6 != *(_WORD *)v1 )
              {
                ++v5;
                v6 += 10;
                if ( v5 >= pPlayerFrameTable->uNumFrames )
                  goto LABEL_56;
              }
            }
            *(_WORD *)(v1 - 6812 + 6816) = 8 * *(_WORD *)(pPlayerFrameTable->pFrames + 10 * v5 + 6);
          }
        }
      }
      else
      {
        v3 = *(_WORD *)v1;
        if ( *(_WORD *)v1 != 34 && v3 != 35 && v3 != 36 || cClock2.int_00001C + *(_WORD *)(v1 + 2) >= *(_WORD *)(v1 + 4) )
        {
          *(_WORD *)(v1 + 4) = 0;
          *(_WORD *)(v1 + 2) = 0;
          switch ( v2 )
          {
            case 14:
              *(_WORD *)v1 = 98;
              break;
            case 15:
              *(_WORD *)v1 = 12;
              break;
            case 16:
              *(_WORD *)v1 = 99;
              break;
            case 0:
              *(_WORD *)v1 = 2;
              break;
            case 1:
              *(_WORD *)v1 = 3;
              break;
            case 2:
              *(_WORD *)v1 = 4;
              break;
            case 3:
              *(_WORD *)v1 = 5;
              break;
            case 4:
              *(_WORD *)v1 = 6;
              break;
            case 5:
              *(_WORD *)v1 = 7;
              break;
            case 6:
            case 8:
            case 10:
              *(_WORD *)v1 = 8;
              break;
            case 7:
            case 9:
            case 11:
              *(_WORD *)v1 = 9;
              break;
            case 12:
              *(_WORD *)v1 = 10;
              break;
            case 13:
              *(_WORD *)v1 = 11;
              break;
            default:
              break;
          }
        }
        else
        {
          *(_WORD *)(v1 + 2) += cClock2.int_00001C;
        }
      }
      v1 += 6972;
    }
    while ( v12-- != 1 );



    for (i = 0; i < 2; ++i)
    {
      v9 = pParty_global->pHiredNPCs[i].dword_000030;
      if ( v9 )
      {
        v10 = pParty_global->pHiredNPCs[i].dword_000028;
        v11 = cClock2.int_00001C + pParty_global->pHiredNPCs[i].dword_00002C;
        if ( v11 >= v9 )
        {
          v10 = 0;
          v9 = 0;
          v11 = 0;
          memset(&pParty_global->pHiredNPCs[i], 0, sizeof(struct NPCData));
          pParty_global->byte_000709 = 0;
          sub_44A56A();
          struct_576FE8.dword_000044 = 1;
        }

        pParty_global->pHiredNPCs[i].dword_000028 = v10;
        pParty_global->pHiredNPCs[i].dword_00002C = v11;
        pParty_global->pHiredNPCs[i].dword_000030 = v9;
      }
    }
  }
}

//----- (00490D02) --------------------------------------------------------
void __thiscall sub_490D02(void *_this)
{
  int v1; // esi@1
  signed int v2; // ebx@4
  int v3; // edi@4
  int v4; // esi@4
  int v5; // eax@9
  char v6; // zf@9
  int v7; // eax@10
  signed int v8; // ecx@10
  signed int v9; // eax@18
  int v10; // eax@25
  signed int v11; // ecx@26
  signed int v12; // [sp-4h] [bp-1Ch]@26
  void *v13; // [sp+Ch] [bp-Ch]@1
  signed int v14; // [sp+10h] [bp-8h]@10
  signed int v15; // [sp+14h] [bp-4h]@3

  v13 = _this;
  v1 = (int)pParty_global->pPartyBuffs;
  do
  {
    SpellBuff_sub_458585((SpellBuff *)v1);
    v1 += 16;
  }
  while ( v1 < (signed int)&pParty_global->pPlayers[0] );
  v15 = 0;
  do
  {
    v4 = (int)&pParty_global->pPlayers[1743 * v15];
    v2 = 20;
    v3 = v4 + 6048;
    do
    {
      SpellBuff_sub_458585((SpellBuff *)v3);
      v3 += 16;
      --v2;
    }
    while ( v2 );
    sub_49070F(v4);
    if ( !*(_QWORD *)(v4 + 112) && !*(_QWORD *)(v4 + 120) && !*(_QWORD *)(v4 + 128) )
    {
      *(_DWORD *)(v4 + 104) = 0;
      *(_DWORD *)(v4 + 108) = 0;
      *(_DWORD *)(v4 + 32) = 0;
      *(_DWORD *)(v4 + 36) = 0;
      *(_DWORD *)(v4 + 16) = 0;
      *(_DWORD *)(v4 + 20) = 0;
      *(_DWORD *)(v4 + 24) = 0;
      *(_DWORD *)(v4 + 28) = 0;
      *(_DWORD *)(v4 + 8) = 0;
      *(_DWORD *)(v4 + 12) = 0;
      *(_WORD *)(v4 + 6452) = 0;
      *(_DWORD *)(v4 + 6460) = Player_GetMaxHealth((Player *)v4);
      v5 = Player_GetMaxMana((Player *)v4);
      v6 = *(_BYTE *)(v4 + 185) == 35;
      *(_DWORD *)(v4 + 6464) = v5;
      if ( v6 )
      {
        v14 = 0;
        v7 = v4 + 558;
        v8 = 138;
        do
        {
          if ( *(_DWORD *)(v7 - 26) == 601 )
          {
            if ( *(_BYTE *)v7 == v15 + 1 )
              v14 = 1;
          }
          v7 += 36;
          --v8;
        }
        while ( v8 );
        if ( !v14 )
        {
          *(_DWORD *)(v4 + 6460) = Player_GetMaxHealth((Player *)v4) / 2;
          *(_DWORD *)(v4 + 6464) = Player_GetMaxMana((Player *)v4) / 2;
        }
      }
      if ( *(_QWORD *)(v4 + 136) )
      {
        v9 = *(_DWORD *)(v4 + 6460);
        *(_DWORD *)(v4 + 6464) = 0;
        *(_DWORD *)(v4 + 6460) = v9 / 2;
LABEL_30:
        if ( *(_QWORD *)(v4 + 40) )
          *(_DWORD *)(v4 + 6464) = 0;
        sub_4909F4(v13);
        goto LABEL_33;
      }
      if ( *(_QWORD *)(v4 + 80) || *(_QWORD *)(v4 + 88) )
      {
        v11 = 4;
        v12 = 4;
      }
      else
      {
        if ( !*(_QWORD *)(v4 + 64) && !*(_QWORD *)(v4 + 72) )
        {
          if ( !*(_QWORD *)(v4 + 48) && !*(_QWORD *)(v4 + 56) )
            goto LABEL_30;
          *(_DWORD *)(v4 + 6460) /= 2;
          v10 = *(_DWORD *)(v4 + 6464) / 2;
          goto LABEL_29;
        }
        v11 = 3;
        v12 = 3;
      }
      *(_DWORD *)(v4 + 6460) /= v11;
      v10 = *(_DWORD *)(v4 + 6464) / v12;
LABEL_29:
      *(_DWORD *)(v4 + 6464) = v10;
      goto LABEL_30;
    }
LABEL_33:
    ++v15;
  }
  while ( v15 < 4 );
  pParty_global->unk_000764[0] = 0;
}

//----- (00490EEE) --------------------------------------------------------
int __thiscall Player_sub_490EEE(Player *_this, int a2, int a3, int a4, int a5)
{
  int result; // eax@1
  signed int v6; // edx@1
  int v7; // ecx@1
  signed int v8; // esi@1
  int v9; // eax@1
  char v10; // zf@14
  unsigned __int8 v11; // zf@22
  char v12; // sf@22
  unsigned __int8 v13; // of@22
  int v14; // edi@26
  float *v15; // esi@26
  float v16; // ST04_4@26
  int v17; // eax@26
  float v18; // ST04_4@30
  int v19; // eax@30
  signed int v20; // eax@34
  float v21; // ST04_4@34
  int v22; // eax@34
  float v23; // ST04_4@37
  int v24; // eax@37
  int v26; // [sp+10h] [bp-8h]@1
  void *v27; // [sp+14h] [bp-4h]@1

  v27 = _this;
  LOBYTE(v9) = Player_sub_48F882(_this, 22);
  v26 = v9;
  result = 4;
  v6 = *(_DWORD *)a2;
  v7 = 48 * *(_DWORD *)a2;
  v8 = pClass40->pItems[*(_DWORD *)a2 - 1].uEquipType;
  if ( (a3 != 4 || v6 < 740 || v6 > 771) && (v6 >= 600 || v6 >= 529 && v6 <= 599) )
    return 5;
  if ( a3 == 1 )
  {
    compile_error;//v13 = __SETO__(v8, 2);
    v11 = v8 == 2;
    v12 = v8 - 2 < 0;
    goto LABEL_24;
  }
  if ( a3 == 2 )
  {
    if ( v8 < 3 )
      return result;
    compile_error;//v13 = __SETO__(v8, 9);
    v11 = v8 == 9;
    v12 = v8 - 9 < 0;
LABEL_24:
    if ( !((unsigned __int8)(v12 ^ v13) | v11) )
      return result;
    goto LABEL_16;
  }
  if ( a3 == 3 )
  {
   if (pClass40->pItems[v7/48 - 1].uSkillType == 38 )
      goto LABEL_16;
    v10 = v8 == 16;
    goto LABEL_15;
  }
  if ( a3 != 4 )
    goto LABEL_26;
  if ( v8 < 13 )
    return result;
  if ( v8 > 14 )
  {
    v10 = v8 == 17;
LABEL_15:
    if ( !v10 )
      return result;
  }
LABEL_16:
  if ( *(_BYTE *)(a2 + 21) & 1 )
    return 6;
LABEL_26:
  v15 = (float *)((char *)&unk_591458 + 52 * a4);
  v16 = *v15;
  v17 = ItemGen_sub_456442((ItemGen *)a2);
  v14 = Player_sub_4B8142((Player *)v27, v17, v16);
  if ( a5 == 3 )
  {
    v23 = *v15;
    v24 = ItemGen_sub_456442((ItemGen *)a2);
    v14 = Player_sub_4B8102((Player *)v27, v24, v23);
    if ( !(*(_BYTE *)(a2 + 20) & 2) )
      goto LABEL_39;
    goto LABEL_38;
  }
  if ( a5 == 4 )
  {
    v20 = Player_sub_4B8179((Player *)v27, *v15);
    goto LABEL_35;
  }
  if ( a5 == 5 )
  {
    v21 = *v15;
    v22 = ItemGen_sub_456442((ItemGen *)a2);
    v20 = Player_sub_4B81C3((Player *)v27, v22, v21);
LABEL_35:
    v14 = v20;
    goto LABEL_39;
  }
  if ( a5 != 6 )
    goto LABEL_39;
  v18 = *v15;
  v19 = ItemGen_sub_456442((ItemGen *)a2);
  v14 = Player_sub_4B8102((Player *)v27, v19, v18) / 2;
  if ( *(_BYTE *)(a2 + 20) & 2 )
    v14 = 1;
  if ( v14 >= 1 )
    goto LABEL_39;
LABEL_38:
  v14 = 1;
LABEL_39:
  if ( v26 )
    result = (v14 == ItemGen_sub_456442((ItemGen *)a2)) + 2;
  else
    result = 1;
  return result;
}

//----- (004910A8) --------------------------------------------------------
int __thiscall Player_sub_4910A8(Player *_this)
{
  int v1; // al@1
  int v2; // ecx@1
  int v4; // eax@3
  signed int v6; // [sp-4h] [bp-4h]@2

  v1 = Player_sub_48F882(_this, 25);
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

//----- (004910D3) --------------------------------------------------------
signed int __stdcall sub_4910D3(int a1)
{
  __int16 v1; // ax@1
  __int16 v2; // bx@1
  int v3; // eax@3
  signed int v4; // ebp@7
  int v5; // edi@7
  int *v6; // esi@7
  int v7; // eax@7
  signed int v9; // [sp-4h] [bp-14h]@2

  LOBYTE(v1) = Player_sub_48F882(pPlayers[uActiveCharacter], 21);
  v2 = v1;
  if ( HIBYTE(v1) & 1 )
  {
    v9 = 5;
  }
  else
  {
    if ( (_BYTE)v1 >= 0 )
    {
      v3 = ((v1 & 0x40) != 0) + 1;
      goto LABEL_7;
    }
    v9 = 3;
  }
  v3 = v9;
LABEL_7:
  v5 = v3 * (v2 & 0x3F);
  v4 = 0;
  v6 = (int *)&pClass40->pItems[*(_DWORD *)a1].pIconName;
  v7 = CheckHiredNPCSpeciality(4);
  if ( v7 )
    goto LABEL_15;
  if ( sub_458244_GetSkillMasteryLevel(v2) >= 4 )
    v4 = 1;
  if ( v5 >= *((_BYTE *)v6 + 46) )
LABEL_15:
    v4 = 1;
  return v4;
}

//----- (00491151) --------------------------------------------------------
signed int __thiscall Player_sub_491151(Player *_this, int a2)
{
  __int16 v2; // ax@1
  __int16 v3; // bx@1
  int v4; // eax@3
  signed int v5; // ebp@7
  int v6; // edi@7
  int *v7; // esi@7
  int v8; // eax@7
  int v9; // eax@9
  unsigned __int8 v10; // al@10
  int v11; // eax@12
  signed int v13; // [sp-4h] [bp-14h]@2

  LOBYTE(v2) = Player_sub_48F882(_this, 23);
  v3 = v2;
  if ( HIBYTE(v2) & 1 )
  {
    v13 = 5;
LABEL_3:
    v4 = v13;
    goto LABEL_7;
  }
  if ( (_BYTE)v2 < 0 )
  {
    v13 = 3;
    goto LABEL_3;
  }
  v4 = ((v2 & 0x40) != 0) + 1;
LABEL_7:
  v6 = v4 * (v3 & 0x3F);
  v5 = 0;
  v7 = (int *)&pClass40->pItems[*(_DWORD *)a2].pIconName;
  v8 = CheckHiredNPCSpeciality(1);
  if ( v8 && *((_BYTE *)v7 + 28) <= 2 )
    goto LABEL_21;
  v9 = CheckHiredNPCSpeciality(2);
  if ( v9 )
  {
    v10 = *((_BYTE *)v7 + 28);
    if ( v10 >= 3u )
    {
      if ( v10 <= 9u )
        goto LABEL_21;
    }
  }
  v11 = CheckHiredNPCSpeciality(3);
  if ( v11 )
  {
    if ( *((_BYTE *)v7 + 28) >= 9u )
      goto LABEL_21;
  }
  if ( sub_458244_GetSkillMasteryLevel(v3) >= 4 )
    v5 = 1;
  if ( v6 >= *((_BYTE *)v7 + 46) )
LABEL_21:
    v5 = 1;
  return v5;
}

//----- (004911F3) --------------------------------------------------------
int __thiscall Player_sub_4911F3(Player *_this)
{
  __int16 v1; // bx@1
  int v2; // edi@1
  int v3; // esi@1
  void *v4; // edi@1
  __int16 v5; // ax@1
  int v7; // eax@3
  int v8; // ecx@7
  signed int v9; // [sp-4h] [bp-10h]@6

  v4 = _this;
  LOBYTE(v5) = Player_sub_48F882(_this, 22);
  v1 = *((_WORD *)v4 + 154);
  v3 = v5 & 0x3F;
  v2 = *((_WORD *)v4 + 154) & 0x3F;
  if ( sub_458244_GetSkillMasteryLevel(v5) >= 4 )
    return 10000;
  v7 = sub_47752B();
  if ( !v3 )
    return -v7;
  if ( HIBYTE(v1) & 1 )
  {
    v9 = 5;
  }
  else
  {
    if ( (_BYTE)v1 >= 0 )
    {
      v8 = ((v1 & 0x40) != 0) + 1;
      return v2 * (v8 - 1) - v7 + v3 + 7;
    }
    v9 = 3;
  }
  v8 = v9;
  return v2 * (v8 - 1) - v7 + v3 + 7;
}

//----- (0049125A) --------------------------------------------------------
signed int __thiscall Player_sub_49125A(Player *_this)
{
  __int16 v1; // bx@1
  int v2; // edi@1
  int v3; // esi@1
  void *v4; // edi@1
  __int16 v5; // ax@1
  int v7; // eax@5
  signed int v8; // [sp-4h] [bp-10h]@4

  v4 = _this;
  LOBYTE(v5) = Player_sub_48F882(_this, 26);
  v1 = *((_WORD *)v4 + 158);
  v3 = v5 & 0x3F;
  v2 = *((_WORD *)v4 + 158) & 0x3F;
  if ( sub_458244_GetSkillMasteryLevel(v5) >= 4 )
    return 10000;
  if ( HIBYTE(v1) & 1 )
  {
    v8 = 5;
  }
  else
  {
    if ( (_BYTE)v1 >= 0 )
    {
      v7 = ((v1 & 0x40) != 0) + 1;
      return v3 + v2 * (v7 - 1);
    }
    v8 = 3;
  }
  v7 = v8;
  return v3 + v2 * (v7 - 1);
}

//----- (004912B0) --------------------------------------------------------
signed int __thiscall Player_sub_4912B0(Player *_this)
{
  __int16 v1; // bx@1
  void *v2; // ebp@1
  int v3; // edi@1
  int v4; // esi@1
  __int16 v5; // ax@1
  int v7; // eax@7
  signed int v8; // [sp-4h] [bp-14h]@6

  v2 = _this;
  LOBYTE(v5) = Player_sub_48F882(_this, 29);
  v1 = *((_WORD *)v2 + 161);
  v4 = v5 & 0x3F;
  v3 = *((_WORD *)v2 + 161) & 0x3F;
  if ( sub_458244_GetSkillMasteryLevel(v5) >= 4 )
    return 10000;
  if ( Player_sub_48D6D0((Player *)v2, 35) )
    v4 *= 2;
  if ( HIBYTE(v1) & 1 )
  {
    v8 = 5;
  }
  else
  {
    if ( (_BYTE)v1 >= 0 )
    {
      v7 = ((v1 & 0x40) != 0) + 1;
      return v4 + v3 * (v7 - 1);
    }
    v8 = 3;
  }
  v7 = v8;
  return v4 + v3 * (v7 - 1);
}

//----- (00491317) --------------------------------------------------------
char __thiscall Player_sub_491317(Player *_this)
{
  int v1; // eax@1
  int v2; // ecx@1
  __int16 v3; // bx@1
  void *v4; // esi@1
  int v5; // eax@4
  signed int v7; // [sp-4h] [bp-Ch]@3

  v4 = _this;
  LOBYTE(v1) = Player_sub_48F882(_this, 36);
  v3 = *((_WORD *)v4 + 168);
  v2 = v1 & 0x3F;
  if ( v1 )
  {
    if ( HIBYTE(v3) & 1 )
    {
      v7 = 5;
    }
    else
    {
      if ( (_BYTE)v3 >= 0 )
      {
        v5 = ((v3 & 0x40) != 0) + 1;
        goto LABEL_8;
      }
      v7 = 3;
    }
    v5 = v7;
LABEL_8:
    v1 = (*((_WORD *)v4 + 168) & 0x3F) * (v5 - 1) + v2 + 9;
  }
  return v1;
}

//----- (0049135E) --------------------------------------------------------
int Party_sub_49135E_GetAllPartyExpDiv1000(struct Party *_this)
{
  signed int v1; // eax@1
 int i;

 v1 = 0;
 for (i = 0; i < 4; ++i)
   v1 += (unsigned int)(_this->pPlayers[i].uExperience);
 return v1 / 1000;
}




//----- (00491E3A) --------------------------------------------------------
int __cdecl sub_491E3A()
{
  signed int v0; // ebx@1
  int v1; // esi@3
  int v2; // eax@4
  int v3; // eax@7
  int v4; // edx@8
  int v5; // ecx@9
  int v6; // edi@17
  int v7; // ebx@18
  int v8; // eax@19
  int v9; // eax@20
  int v10; // eax@22
  int v11; // eax@23
  int result; // eax@26
 int i;

  for (i = 0; i < 4; ++i)
  {
   v0 = (int)&pParty_global->pPlayers[i];

    if ( byte_4ED498 )
    {
      v1 = 0;
      if ( pSoundList->uNumSounds <= 0 )
      {
LABEL_7:
        v3 = 0;
      }
      else
      {
        v2 = (int)((char *)pSoundList->pDescriptions + 32);
        while ( *(_DWORD *)v2 != 2 * ((unsigned __int8)byte_4ED498 + 50 * *(_DWORD *)(v0 + 6432)) + 4998 )
        {
          ++v1;
          v2 += 120;
          if ( v1 >= pSoundList->uNumSounds )
            goto LABEL_7;
        }
        v3 = v1;
      }
      SoundList_sub_4A9DCD((int)pSoundList, v3, 1);
      v4 = 0;
      if ( pSoundList->uNumSounds <= 0 )
      {
LABEL_12:
        v4 = 0;
      }
      else
      {
        v5 = (int)((char *)pSoundList->pDescriptions + 32);
        while ( *(_DWORD *)v5 != 2 * ((unsigned __int8)byte_4ED498 + 50 * *(_DWORD *)(v0 + 6432)) + 4999 )
        {
          ++v4;
          v5 += 120;
          if ( v4 >= pSoundList->uNumSounds )
            goto LABEL_12;
        }
      }
      SoundList_sub_4A9DCD((int)pSoundList, v4, 1);
    }
  }

 // strange code very 
  //v6 = LODFile_Icons_LOD.dword_0046DF/*((_DWORD *)LODFile_Icons_LOD + 18143)*/ - 1;
  //if ( v6 >= *((_DWORD *)LODFile_Icons_LOD.word_0046E8 /*+ 18152*/) )
  //{
  //  v7 = (int)((char *)LODFile_Icons_LOD.aLODHeaders + 72 * v6);
  //  do
  //  {
  //    cTexture_Free((cTexture *)v7);
  //    v8 = *((_DWORD *)LODFile_Icons_LOD.dword_0046EC /*+ 18156*/);
  //    if ( v8 )
  //    {
  //      v9 = *(_DWORD *)(v8 + 4 * v6);
  //      if ( v9 )
  //      {
  //        (*(void (__cdecl **)(int))(*(_DWORD *)v9 + 8))(v9);
  //        *(_DWORD *)(*((_DWORD *)LODFile_Icons_LOD.dword_0046EC/* + 18156*/) + 4 * v6) = 0;
  //      }
  //    }
  //    v10 = *((_DWORD *)LODFile_Icons_LOD.char_0046EB /*+ 18155*/);
  //    if ( v10 )
  //    {
  //      v11 = *(_DWORD *)(v10 + 4 * v6);
  //      if ( v11 )
  //      {
  //        (*(void (__cdecl **)(int))(*(_DWORD *)v11 + 8))(v11);
  //        *(_DWORD *)(*((_DWORD *)LODFile_Icons_LOD.char_0046EB /*+ 18155*/) + 4 * v6) = 0;
  //      }
  //    }
  //    --v6;
  //    v7 -= 72;
  //  }
  //  while ( v6 >= *((_DWORD *)LODFile_Icons_LOD.word_0046E8 /*+ 18152*/) );
  //}
  //result = *((_DWORD *)LODFile_Icons_LOD.word_0046E8 /*+ 18152*/);
  //*((_DWORD *)LODFile_Icons_LOD.word_0046E8 /*+ 18152*/) = 0;
  //*((_DWORD *)LODFile_Icons_LOD.dword_0046DF /*+ 18143*/) = result;
  return result;
}

//----- (004925E6) --------------------------------------------------------
unsigned int Player_FindNextFreeInventorySlotIndex(Player *_this)
{
 for (unsigned int i = 0; i < 126; ++i)
   if (_this->cInventorySlots[i].uItemID == -1)
     return i;

 return -1;
}

//----- (00492700) --------------------------------------------------------
bool Player_CheckIfHasSkill(Player *_this, unsigned int uSkillType)
{
 if (uSkillType >= 37 || _this->pActiveSkills[uSkillType])
   return true;
 else
 {
  wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[67], _this->sName);
  sub_44C175((char *)TmpBuf, 2);
  return false;
 }
}

//----- (0049298B) --------------------------------------------------------
signed int __thiscall sub_49298B(void *_this, struct ItemGen *a2, int a3, int a4)
{
  void *v4; // ebx@1
  cTexture* v5; // esi@1
  int v6; // eax@1
  void *v7; // esi@4
  int v10; // [sp+Ch] [bp-4h]@1
  int v11; // [sp+18h] [bp+8h]@1

  v4 = _this;
  v6 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)pClass40->pItems[a2->uItemID].pIconName, 2);
  v5 = v6 != -1 ? &LODFile_Icons_LOD.aLODHeaders[v6] : 0;
  v10 = GetSizeInInventorySlots((v6 != -1 ? LODFile_Icons_LOD.aLODHeaders[v6].uTextureHeight : 24));
  v11 = GetSizeInInventorySlots((v5->uTextureWidth));
  if ( !bTextureLoading )
  {
    cTexture_Free((cTexture *)v5);
    LODFile_Icons_LOD.LODFile_sub_40F9C5();
  }
  if ( v11 > 0 )
  {
    v7 = (char *)v4 + 4 * a4 + 5500;
    do
    {
      if ( v10 > 0 )
        memset(v7, -1 - a4, 4 * v10);
      v7 = (char *)v7 + 56;
    }
    while ( v11-- != 1 );
  }
  *((_DWORD *)v4 + a4 + 1375) = a3 + 1;
  return 1;
}

//----- (00492A36) --------------------------------------------------------
void Player_sub_492A36_RemoveItemFromIndexMatrix(struct Player *_this, unsigned int uInventorySlot)
{
  //int result; // eax@1
  //int v3; // ebp@1
  int v4; // edi@1
  cTexture* v5; // esi@1
  ItemGen * v6; // ecx@1
  int v7; // esi@1
  int v8; // eax@1
  void *v9; // edx@4
  //int v10; // [sp+14h] [bp+4h]@1
 unsigned int uItemSlotsWidth,
              uItemSlotsHeight;

  v4 = _this->pInventoryIndices[uInventorySlot];
 // v6 = (int)((char *)_this + 36 * *(_DWORD *)v4 + 496);
  v6 = &_this->cInventorySlots[v4];
  v7 = v6->uItemID;
  ItemGen_Reset(&_this->cInventorySlots[v4]);
#ifndef OLD_CODE
  wchar_t pTextureNameW[256];
  wsprintfW(pTextureNameW, L"%S", pClass40->pItems[v7].pIconName);

  v8 = LODFile_Icons_LOD.LODFile_LoadTexture_New(pTextureNameW);
#else
  v8 = LODFile_Icons_LOD.LODFile_LoadTexture((char *)pClass40->pItems[v7].pIconName, 2);
#endif

  v5 = v8 != -1 ? &LODFile_Icons_LOD.aLODHeaders[v8]: 0;
  uItemSlotsWidth = GetSizeInInventorySlots(v5->uTextureWidth);
  uItemSlotsHeight = GetSizeInInventorySlots(v5->uTextureHeight);

  if ( !bTextureLoading )
  {
    cTexture_Free((cTexture *)v5);
    LODFile_Icons_LOD.LODFile_sub_40F9C5();
  }

 unsigned int uInventorySlotX = uInventorySlot % 14,
              uInventorySlotY = uInventorySlot / 14;
 while (~_this->pInventoryIndices[uInventorySlotY * 14 + uInventorySlotX] & 0x80000000) // heading for the left-topmost corner cell
 {
  if (uInventorySlotX > 0 &&
      (_this->pInventoryIndices[uInventorySlotY * 14 + uInventorySlotX - 1] | 0x80000000) == _this->pInventoryIndices[uInventorySlotY * 14 + uInventorySlotX])
    --uInventorySlotX;
  if (uInventorySlotY > 0 &&
      (_this->pInventoryIndices[(uInventorySlotY - 1) * 14 + uInventorySlotX] | 0x80000000) == _this->pInventoryIndices[(uInventorySlotY - 1) * 14 + uInventorySlotX])
    --uInventorySlotY;
 }

 for (unsigned int y = uInventorySlotY; y < uInventorySlotY + uItemSlotsHeight; ++y)
   for (unsigned int x = uInventorySlotX; x < uInventorySlotX + uItemSlotsWidth; ++x)
     _this->pInventoryIndices[y * 14 + x] = -1;
  /*
  if (uItemSlotsHeight > 0 )
  {
    v9 = &_this->pInventoryIndices[sItemID];
    do
    {
      if (uItemSlotsWidth > 0 )
      {
        memset(v9, 0, 4 * uItemSlotsWidth);
      }
      v9 = (char *)v9 + 56;
      --uItemSlotsHeight;
    }
    while ( uItemSlotsHeight );
  }*/
}

//----- (00492AD5) --------------------------------------------------------
__int16 __thiscall sub_492AD5(void *_this)
{
  __int16 result; // ax@1

  array_6A0D14[0].word_000004 = 0;
  pParty_global->uNumFood = (int)_this;
  //result = 8 * pIconFrameTable->pIcons[array_6A0D14[0].uIconIdx].word_00001A;
  result = 8 * pIconFrameTable->GetImage(array_6A0D14[0].uIconIdx)->word_00001A;
  //array_6A0D14[0].word_000006 = 8 * pIconFrameTable->pIcons[array_6A0D14[0].uIconIdx].word_00001A;
  array_6A0D14[0].word_000006 = 8 * pIconFrameTable->GetImage(array_6A0D14[0].uIconIdx)->word_00001A;
  return result;
}

//----- (00492B03) --------------------------------------------------------
__int16 __thiscall sub_492B03(void *_this)
{
  __int16 result; // ax@4

  if ( pParty_global->uNumFood - (_DWORD)_this >= 0 )
    pParty_global->uNumFood -= (signed int)_this;
  else
    pParty_global->uNumFood = 0;
  array_6A0D14[0].word_000004 = 0;
  //result = 8 * pIconFrameTable->pIcons[array_6A0D14[0].uIconIdx].word_00001A;
  result = 8 * pIconFrameTable->GetImage(array_6A0D14[0].uIconIdx)->word_00001A;
  //array_6A0D14[0].word_000006 = 8 * pIconFrameTable->pIcons[array_6A0D14[0].uIconIdx].word_00001A;
  array_6A0D14[0].word_000006 = 8 * pIconFrameTable->GetImage(array_6A0D14[0].uIconIdx)->word_00001A;
  return result;
}

//----- (00492B42) --------------------------------------------------------
__int16 __thiscall sub_492B42(void *_this)
{
  __int16 result; // ax@1

  pParty_global->uNumFood += (int)_this;
  array_6A0D14[0].word_000004 = 0;
  //result = 8 * pIconFrameTable->pIcons[array_6A0D14[0].uIconIdx].word_00001A;
  result = 8 * pIconFrameTable->GetImage(array_6A0D14[0].uIconIdx)->word_00001A;
  //array_6A0D14[0].word_000006 = 8 * pIconFrameTable->pIcons[array_6A0D14[0].uIconIdx].word_00001A;
  array_6A0D14[0].word_000006 = 8 * pIconFrameTable->GetImage(array_6A0D14[0].uIconIdx)->word_00001A;
  return result;
}

//----- (00492B70) --------------------------------------------------------
void __thiscall sub_492B70(void *_this)
{
  pParty_global->uNumGold = (int)_this;
  array_6A0D14[1].word_000004 = 0;
  //array_6A0D14[1].word_000006 = 8 * pIconFrameTable->pIcons[array_6A0D14[1].uIconIdx].word_00001A;
  array_6A0D14[1].word_000006 = 8 * pIconFrameTable->GetImage(array_6A0D14[1].uIconIdx)->word_00001A;
  AudioPlayer_sub_4AA306(pAudioPlayer, 200, 0, 0, -1, 0, 0, 0, 0);
}

//----- (00492BB6) --------------------------------------------------------
void __fastcall sub_492BB6(unsigned int a1)
{
  if ( a1 <= pParty_global->uNumGold )
    pParty_global->uNumGold -= a1;
  else
    pParty_global->uNumGold = 0;
  array_6A0D14[1].word_000004 = 0;
  //array_6A0D14[1].word_000006 = 8 * pIconFrameTable->pIcons[array_6A0D14[1].uIconIdx].word_00001A;
  array_6A0D14[1].word_000006 = 8 * pIconFrameTable->GetImage(array_6A0D14[1].uIconIdx)->word_00001A;
  AudioPlayer_sub_4AA306(pAudioPlayer, 200, 0, 0, -1, 0, 0, 0, 0);
}

//----- (00492C40) --------------------------------------------------------
bool __thiscall Player_sub_492C40(Player *_this)
{
  int v2; // eax@1

  LOBYTE(v2) = Player_sub_48F882(_this, 34);
  return v2 != 0;
}

//----- (00492C4E) --------------------------------------------------------
bool Player_CanEquip_RacialAndAlignmentCheck(Player *_this, unsigned int uItemID)
{
  char v2; // zf@9
  __int16 v4; // dx@13
  char v5; // zf@15

 if (uItemID == 514 ||                       // item233  Посох Этрика              артефакт, зло
     uItemID == 516 ||                       // item221  Старый Ник                артефакт, зло
     uItemID == 524)                         // item325  Сумрак                    реликвия, зло
   return sub_449B57((unsigned char *)pParty_global->unk_000764 + 1, 100) != 0;

 if (uItemID == 521 ||                       // item239  Шлем Таледона             артефакт, добро
     uItemID == 526)                         // item230  Справедливость            реликвия, добро
   return sub_449B57((unsigned char *)pParty_global->unk_000764 + 1, 99) != 0;
 
 if (uItemID == 530)                         // item093  Гибель Эльфа              артефакт, гоблин
   return Player_GetRace(_this) == Character::Race::Goblin;
 
 if (uItemID == 531)                         // item093  Око Мысли                 артефакт, человек
   return Player_GetRace(_this) == Character::Race::Human;

 if (uItemID == 532)                         // item073  Эльфийская Кольчуга       артефакт, эльф
   return Player_GetRace(_this) == Character::Race::Elf;
 
 if (uItemID == 533)                         // item113  Кованые Латные Рукавицы   артефакт, гном
   return Player_GetRace(_this) == Character::Race::Dwarf;

 if (uItemID == 534)                         // item104  Пояс Героя                артефакт, мужчина
   return Player_GetSex(_this) == Character::Sex::Male;

 if (uItemID == 535)                         // item129  Эскорт Леди               артефакт, женщина
   return Player_GetSex(_this) == Character::Sex::Female;


 if (uItemID > 531)
 {
  if (uItemID != 603)
    return true;

  v5 = Player_sub_43EEF3(_this) == 0;
  if ( !v5 )
    return true;
  return false;
 }
 return true;
}

//----- (00493244) --------------------------------------------------------
signed int __stdcall sub_493244(int a1)
{
  signed int v1; // edx@1
  signed int v2; // eax@2
  signed int v3; // ecx@2

  v1 = (signed int)&unk_ACDB98;
  while ( 2 )
  {
    v3 = 0;
    v2 = v1;
    do
    {
      if ( *(_DWORD *)v2 == a1 )
        return 1;
      ++v3;
      v2 += 36;
    }
    while ( v3 < 138 );
    v1 += 6972;
    if ( v1 < (signed int)&unk_AD4888 )
      continue;
    break;
  }
  return 0;
}

//----- (0049327B) --------------------------------------------------------
signed int __thiscall sub_49327B(int _this, int a2, int a3)
{
  int v3; // esi@1
  char v4; // zf@4
  __int16 v5; // dx@9
  signed int result; // eax@84
  signed int v7; // [sp-8h] [bp-10h]@3
  int v8; // [sp-4h] [bp-Ch]@3

  v3 = _this;
  if ( *(_BYTE *)(_this + 185) == a2 )
  {
LABEL_84:
    result = 1;
  }
  else
  {
    switch ( a2 )
    {
      case 0:
        v8 = a3;
        v7 = 1;
        goto LABEL_4;
      case 1:
        if ( a3 && (unsigned __int16)sub_449B57((unsigned char *)_this + 338, 17) || sub_49327B(_this, 2, a3) )
          goto LABEL_84;
        v8 = a3;
        v7 = 3;
        goto LABEL_4;
      case 2:
        v5 = 19;
        goto LABEL_82;
      case 3:
        v5 = 21;
        goto LABEL_82;
      case 4:
        v8 = a3;
        v7 = 5;
        goto LABEL_4;
      case 5:
        if ( a3 && (unsigned __int16)sub_449B57((unsigned char *)_this + 338, 11) || sub_49327B(_this, 6, a3) )
          goto LABEL_84;
        v8 = a3;
        v7 = 7;
        goto LABEL_4;
      case 6:
        if ( !a3 )
          break;
        v5 = 13;
        goto LABEL_82;
      case 7:
        if ( !a3 )
          break;
        v5 = 15;
        goto LABEL_82;
      case 8:
        v8 = a3;
        v7 = 9;
        goto LABEL_4;
      case 9:
        if ( a3 && (unsigned __int16)sub_449B57((unsigned char *)_this + 338, 23) || sub_49327B(_this, 10, a3) )
          goto LABEL_84;
        v8 = a3;
        v7 = 11;
        goto LABEL_4;
      case 10:
        if ( !a3 )
          break;
        v5 = 25;
        goto LABEL_82;
      case 11:
        if ( !a3 )
          break;
        v5 = 27;
        goto LABEL_82;
      case 12:
        v8 = a3;
        v7 = 13;
        goto LABEL_4;
      case 13:
        if ( a3 && (unsigned __int16)sub_449B57((unsigned char *)_this + 338, 41) || sub_49327B(_this, 14, a3) )
          goto LABEL_84;
        v8 = a3;
        v7 = 15;
        goto LABEL_4;
      case 14:
        if ( !a3 )
          break;
        v5 = 43;
        goto LABEL_82;
      case 15:
        if ( !a3 )
          break;
        v5 = 45;
        goto LABEL_82;
      case 16:
        v8 = a3;
        v7 = 17;
        goto LABEL_4;
      case 17:
        if ( a3 && (unsigned __int16)sub_449B57((unsigned char *)_this + 338, 35) || sub_49327B(_this, 18, a3) )
          goto LABEL_84;
        v8 = a3;
        v7 = 19;
        goto LABEL_4;
      case 18:
        if ( !a3 )
          break;
        v5 = 37;
        goto LABEL_82;
      case 19:
        v5 = 39;
        goto LABEL_82;
      case 20:
        v8 = a3;
        v7 = 21;
        goto LABEL_4;
      case 21:
        if ( a3 && (unsigned __int16)sub_449B57((unsigned char *)_this + 338, 29) || sub_49327B(_this, 22, a3) )
          goto LABEL_84;
        v8 = a3;
        v7 = 23;
        goto LABEL_4;
      case 22:
        if ( !a3 )
          break;
        v5 = 31;
        goto LABEL_82;
      case 23:
        if ( !a3 )
          break;
        v5 = 33;
        goto LABEL_82;
      case 24:
        if ( !sub_49327B(_this, 25, a3) )
          goto LABEL_56;
        break;
      case 25:
LABEL_56:
        if ( a3 && (unsigned __int16)sub_449B57((unsigned char *)v3 + 338, 63) || sub_49327B(_this, 26, a3) )
          goto LABEL_84;
        v8 = a3;
        v7 = 27;
        goto LABEL_4;
      case 26:
        if ( !a3 )
          break;
        v5 = 65;
        goto LABEL_82;
      case 27:
        if ( !a3 )
          break;
        v5 = 67;
        goto LABEL_82;
      case 28:
        v8 = a3;
        v7 = 29;
        goto LABEL_4;
      case 29:
        if ( a3 && (unsigned __int16)sub_449B57((unsigned char *)_this + 338, 69) || sub_49327B(_this, 30, a3) )
          goto LABEL_84;
        v8 = a3;
        v7 = 31;
        goto LABEL_4;
      case 30:
        if ( !a3 )
          break;
        v5 = 71;
        goto LABEL_82;
      case 31:
        if ( !a3 )
          break;
        v5 = 73;
        goto LABEL_82;
      case 32:
        v8 = a3;
        v7 = 33;
        goto LABEL_4;
      case 33:
        if ( a3 && (unsigned __int16)sub_449B57((unsigned char *)_this + 338, 73) || sub_49327B(_this, 34, a3) )
          goto LABEL_84;
        v8 = a3;
        v7 = 35;
LABEL_4:
        v4 = sub_49327B(_this, v7, v8) == 0;
        goto LABEL_83;
      case 34:
        if ( !a3 )
          break;
        v5 = 77;
        goto LABEL_82;
      case 35:
        if ( a3 )
        {
          v5 = 79;
LABEL_82:
          v4 = (unsigned __int16)sub_449B57((unsigned char *)_this + 338, v5) == 0;
LABEL_83:
          if ( !v4 )
            goto LABEL_84;
        }
        break;
      default:
        break;
    }
    result = 0;
  }
  return result;
}

//----- (004936E1) --------------------------------------------------------
void Party_sub_4936E1(Party *_this, const struct ItemGen *pItem)
{
 sub_421B2C();
 memcpy(&_this->pickedItem, pItem, sizeof(struct ItemGen));
 SetCursorBitmapFromItemID(_this->pickedItem.uItemID);
}

//----- (0049387A) --------------------------------------------------------
signed int __thiscall sub_49387A(void *_this)
{
  signed int result; // eax@1
  signed int v2; // ecx@2
  signed int v3; // ecx@8

  result = uActiveCharacter;
  if ( _this )
  {
    v2 = 0;
    while ( 1 )
    {
      --result;
      if ( result < 1 )
        result = 4;
      if ( !*((_WORD *)pPlayers[result - 1] + 3226) )
        break;
      ++v2;
      if ( v2 >= 4 )
        return uActiveCharacter;
    }
  }
  else
  {
    v3 = 0;
    while ( 1 )
    {
      ++result;
      if ( result > 4 )
        result = 1;
      if ( !*((_WORD *)pPlayers[result - 1] + 3226) ) // pPlayer[result]->cInventorySlots[74].uItemID
        break;
      ++v3;
      if ( v3 >= 4 )
        return uActiveCharacter;
    }
  }
  return result;
}

//----- (004938D1) --------------------------------------------------------
int __fastcall sub_4938D1(unsigned int a1)
{
  unsigned int v1; // esi@1
  Player *v2; // esi@3
  double v3; // st7@3

  v1 = a1;
  if ( a1 > 0xF0 )
    UpdateActors();
  v3 = (double)(7680 * v1) * 0.03333333507180214;
  pParty_global->qword_00002C += (signed __int64)v3;
  for(int i=1; i<5; i++) 
  {
    v2 = pPlayers[i];
    Player_sub_48E8F5(v2, (signed __int64)v3);
    //++v2;
  }
 // while ( (signed int)v2 <= (signed int)&dword_A750D4 );
  return sub_494035();
}

//----- (00493F79) --------------------------------------------------------
unsigned int __thiscall sub_493F79(int _this, __int64 a2)
{
  unsigned int result; // eax@1
  signed __int64 v3; // ST2C_8@1
  signed __int64 v4; // qax@1
  unsigned int v5; // ebx@1

  v3 = (signed __int64)((double)a2 * 0.234375);
  v4 = v3 / 60 / 60;
  v5 = (_DWORD)v4 / 0x18u / 0x1C;
  *(_DWORD *)_this = v3 % 60;
  *(_DWORD *)(_this + 4) = v3 / 60 % 60;
  *(_DWORD *)(_this + 8) = v3 / 60 / 60 % 24;
  *(_DWORD *)(_this + 16) = (_DWORD)v4 / 0x18u / 7 & 3;
  *(_DWORD *)(_this + 12) = (_DWORD)v4 / 0x18u % 0x1C;
  result = v5 / 0xC + 1168;
  *(_DWORD *)(_this + 20) = v5 % 0xC;
  *(_DWORD *)(_this + 24) = result;
  return result;
}

//----- (00494820) --------------------------------------------------------
unsigned int __fastcall sub_494820(unsigned int a1)
{
  signed int v1; // eax@1

  v1 = 5;
  if ( a1 % 0x18 >= 5 )
    v1 = 29;
  return v1 - a1 % 0x18;
}

//----- (00494836) --------------------------------------------------------
int __thiscall sub_494836(void *_this, int a2, int a3)
{
  int result; // eax@1
  void *v4; // ebx@1
  int v5; // esi@1
  int v6; // edi@2
  signed int v7; // eax@3
  int v8; // [sp+Ch] [bp-8h]@3
  int v9; // [sp+10h] [bp-4h]@2
  int v10; // [sp+1Ch] [bp+8h]@1

  v5 = 0;
  result = word_4EE088[a2];
  v4 = _this;
  v10 = word_4EE088[a2];
  if ( result )
  {
    v9 = 0;
    v6 = (int)((char *)_this + 45008);
    do
    {
      v7 = v10++;
      result = sub_4A9BBD(pSoundList, v7, (char *)v4 + v5, 44744 - v5, (int)&v8, a3);
      if ( !result )
        break;
      a3 += 4;
      result = v8 + 256;
      *(_DWORD *)v6 = v5;
      v5 += result;
      ++v9;
      *(_DWORD *)(v6 - 8) = result;
      v6 += 4;
    }
    while ( v9 < 2 );
  }
  return result;
}

//----- (00494A25) --------------------------------------------------------
__int16 __thiscall Player_sub_494A25(int _this, int a2, int a3)
{
  signed int v3; // eax@1
  __int16 v4; // dx@1
  int v5; // edi@15
  int v6; // esi@17
  int v7; // eax@20

  LOWORD(v3) = *(_WORD *)(_this + 6812);
  v4 = a2;
  if ( (_WORD)v3 != 4 && (_WORD)v3 != 12 || a2 != 58 )
  {
    v3 = (unsigned __int16)v3;
    if ( (signed int)(unsigned __int16)v3 >= 2 )
    {
      if ( v3 <= 7 )
        goto LABEL_12;
      if ( v3 > 8 )
      {
        if ( v3 > 11 )
        {
          if ( v3 == 12 || v3 > 97 && v3 <= 99 )
            return v3;
          goto LABEL_15;
        }
LABEL_12:
        if ( a2 != 34 && a2 != 35 && a2 != 36 )
          return v3;
        goto LABEL_15;
      }
    }
  }
LABEL_15:
  LOWORD(v3) = a3;
  v5 = 0;
  *(_WORD *)(_this + 6816) = a3;
  *(_WORD *)(_this + 6814) = 0;
  if ( !a3 )
  {
    if ( pPlayerFrameTable->uNumFrames <= 0 )
    {
LABEL_20:
      v7 = 0;
    }
    else
    {
     v6 = (int)pPlayerFrameTable->pFrames;
      while ( *(_WORD *)v6 != a2 )
      {
        ++v5;
        v6 += 10;
        if ( v5 >= pPlayerFrameTable->uNumFrames )
          goto LABEL_20;
      }
      v7 = v5;
    }
    v4 = a2;
    LOWORD(v3) = 8 * *(_WORD *)(pPlayerFrameTable->pFrames + 10 * v3 + 6);
    *(_WORD *)(_this + 6816) = v3;
  }
  *(_WORD *)(_this + 6812) = v4;
  struct_576FE8.dword_000044 = 1;
  return v3;
}


//----- (00495366) --------------------------------------------------------
int __fastcall sub_495366(unsigned __int8 a1, unsigned __int8 a2)
{
  int v2; // edi@1
  int v3; // edx@2
  int v4; // esi@3
  int v5; // ebx@5
  int v7; // [sp+Ch] [bp-14h]@1
  int v8; // [sp+10h] [bp-10h]@1
  int **v9; // [sp+14h] [bp-Ch]@4
  int v10; // [sp+18h] [bp-8h]@3
  unsigned __int8 v11; // [sp+1Ch] [bp-4h]@1

  v2 = a1;
  v11 = a2;
  v8 = 0;
  v7 = 0;
  if ( dword_AE336C == a1 )
  {
    v3 = dword_AE3370;
  }
  else
  {
    v4 = 4 * a2;
    dword_AE336C = a1;
    v10 = 0;
    compile_error;
    //if ( *(int *)((char *)dword_73C1A0 + v4) <= 0 )
     //dword_73C1A0 == pNPCStats->dword_017FD0
      goto LABEL_17;
    //v9 = (int **)&dword_736B48[v4];
      //dword_736B48 == pNPCStats->pNPCNames
      compile_error;
    do
    {
      v5 = tolower(*(_BYTE *)*v9);
      if ( v5 == tolower(v2) )
      {
        if ( v8 )
          v7 = v10;
        else
          v8 = v10;
      }
      ++v10;
      v9 += 2;
    }
    //while ( v10 < *(int *)((char *)dword_73C1A0 + v4) );
    while(0);
    //dword_73C1A0 == pNPCStats->dword_017FD0
    compile_error;

    if ( v8 && v8 != v7 )
      v3 = v8 + rand() % (v7 - v8);
    else
LABEL_17:
      //v3 = rand() % *(int *)((char *)dword_73C1A0 + v4);
     //dword_73C1A0 == pNPCStats->dword_017FD0
    compile_error;
  }
  dword_AE3370 = v3;
  //return *(_DWORD *)&dword_736B48[4 * (v11 + 2 * v3)];
  //dword_736B48 == pNPCStats->pNPCNames
  compile_error;
  return 0;
}

//----- (00495430) --------------------------------------------------------
int __fastcall sub_495430(signed int a1)
{
 
  if ( a1 >25 )
 	 return (int)pGlobalTXT_LocalizationStrings[LOCSTR_HATED];
  else if ( a1 > 6 )
     return  (int)pGlobalTXT_LocalizationStrings[LOCSTR_UNFRENDLY];
  else if ( a1 > -5)
	 return (int)pGlobalTXT_LocalizationStrings[LOCSTR_NEITRAL];
  else if ( a1 < -5)
     return (int)pGlobalTXT_LocalizationStrings[LOCSTR_FRENDLY];
  else if ( a1 < -24)
     return  (int)pGlobalTXT_LocalizationStrings[LOCSTR_LIKED];
}

//----- (00495461) --------------------------------------------------------
const CHAR *__fastcall sub_495461_DrawAn_AreYouSureWishTo_Join_Dismiss_ThisNPC_Dialogue(char *lpsz, unsigned __int8 a2, int a3, int a4, int a5, __int64 *a6)
{
  unsigned __int8 v6; // bl@1
  int v8; // ebx@3
  int v9; // eax@4
  size_t v10; // eax@6
  int v11; // edx@7
  int v12; // edi@7
  int v13; // esi@7
  CHAR v14; // cl@8
  int v15; // eax@10
  int v16; // edx@10
  char *v17; // ecx@10
  signed __int64 v18; // qax@18
  int v19; // ebx@32
  unsigned int v20; // edi@32
  int v21; // ecx@34
  __int16 v22; // ax@34
  int v23; // eax@39
  int v24; // edx@39
  int v25; // eax@45
  int v26; // eax@68
  char *v27; // esi@68
  float v28; // ST18_4@68
  int v29; // eax@68
  float v30; // ST18_4@72
  int v31; // eax@72
  float v32; // ST18_4@74
  int v33; // eax@74
  double v34; // st7@75
  float v35; // ST18_4@76
  int v36; // eax@76
  float *v37; // esi@78
  float v38; // ST18_4@78
  int v39; // eax@78
  float v40; // ST18_4@82
  int v41; // eax@82
  float v42; // ST18_4@83
  int v43; // eax@83
  float v44; // ST18_4@85
  int v45; // eax@85
  int v46; // eax@86
  signed int v47; // eax@87
  float v48; // ST18_4@97
  int v49; // eax@107
  __int64 v50; // ST14_8@107
  int v51; // eax@108
  int v52; // eax@109
  int v53; // [sp-4h] [bp-13Ch]@107
  int v54; // [sp+0h] [bp-138h]@107
  __int16 v55[56]; // [sp+10h] [bp-128h]@34
  char v56; // [sp+80h] [bp-B8h]@107
  int v57; // [sp+8Ch] [bp-ACh]@107
  int v58; // [sp+94h] [bp-A4h]@107
  int v59; // [sp+98h] [bp-A0h]@107
  char v60; // [sp+9Ch] [bp-9Ch]@115
  int v61; // [sp+A8h] [bp-90h]@115
  int v62; // [sp+B0h] [bp-88h]@115
  int v63; // [sp+B4h] [bp-84h]@115
  char Dest[100]; // [sp+B8h] [bp-80h]@3
  unsigned int v65; // [sp+11Ch] [bp-1Ch]@3
  size_t v66; // [sp+120h] [bp-18h]@3
  int v67; // [sp+124h] [bp-14h]@3
  char *Str; // [sp+128h] [bp-10h]@1
  int v69; // [sp+12Ch] [bp-Ch]@32
  int v70; // [sp+130h] [bp-8h]@6
  int v71; // [sp+134h] [bp-4h]@6

  v6 = a2;
  Str = lpsz;
  if ( IsBadStringPtrA(lpsz, 1) )
    return "Invalid String Passed";
  v66 = strlen(Str);
  Dest[0] = 0;
  v8 = (int)pPlayers[v6];
  v65 = 0xFFFF9B;
  v67 = v8;
  memset((char *)pStringBuffer, 0, 0x7D0u);
  if ( dword_5C35D4 )
    v9 = dword_5913D8[dword_5913F0 - ((dword_591080 != 0) + 1)];
  else
    v9 = (int)sub_4459F9_GetNPCData(uDialogue_SpeakingActorID);
  v71 = v9;
  v10 = 0;
  v70 = 0;
  if ( (signed int)v66 > 0 )
  {
    v13 = a4;
    v11 = v70;
    v12 = a3;
    while ( 1 )
    {
      v14 = Str[v11];
      if ( v14 == 37 )
        break;
      pStringBuffer[v10++] = v14;
LABEL_119:
      ++v11;
      v70 = v11;
      if ( v11 >= (signed int)v66 )
        return (char *)pStringBuffer;
    }
    v17 = &Str[v11 + 1];
    v16 = (unsigned __int8)Str[v11 + 2];
    v15 = v16 + 10 * (unsigned __int8)*v17 - 528;
    if ( v15 <= 15 )
    {
      if ( v15 != 15 )
      {
        switch ( v16 + 10 * (unsigned __int8)*v17 )
        {
          case 0x211:
            v13 = *(_DWORD *)v71;
            goto LABEL_118;
          case 0x212:
            v13 = v8 + 168;
            goto LABEL_118;
          case 0x213:
          case 0x219:
            if ( *(_DWORD *)(v71 + 64) )
              v13 = (int)pGlobalTXT_LocalizationStrings[384];
            else
              v13 = (int)pGlobalTXT_LocalizationStrings[383];
            goto LABEL_118;
          case 0x215:
            v18 = (signed __int64)((double)pParty_global->qword_00002C * 0.234375) / 60 / 60 % 24;
            v13 = (int)pGlobalTXT_LocalizationStrings[397];
            if ( HIDWORD(v18) <= 0 )
            {
              if ( HIDWORD(v18) >= 0 )
              {
                if ( (_DWORD)v18 >= 5u )
                {
                  if ( HIDWORD(v18) <= 0 )
                  {
                    if ( HIDWORD(v18) >= 0 && (_DWORD)v18 >= 0xBu )
                    {
                      if ( v18 < 20 )
                        v13 = (int)pGlobalTXT_LocalizationStrings[396];
                    }
                    else
                    {
                      v13 = (int)pGlobalTXT_LocalizationStrings[395];
                    }
                  }
                }
              }
            }
            goto LABEL_118;
          case 0x216:
            if ( *(_BYTE *)(v8 + 184) )
              v13 = (int)pGlobalTXT_LocalizationStrings[387];
            else
              v13 = (int)pGlobalTXT_LocalizationStrings[385];
            goto LABEL_118;
          case 0x217:
            if ( *(_BYTE *)(v8 + 184) )
              goto LABEL_43;
            v13 = (int)pGlobalTXT_LocalizationStrings[386];
            goto LABEL_118;
          case 0x218:
            v20 = 0;
            v69 = 0;
            v19 = v67 + 338;
            do
            {
              if ( (unsigned __int16)sub_449B57((unsigned char *)v19, *(_WORD *)((char *)&unk_4EE150 + v20)) )
              {
                v21 = v69;
                v22 = *(_WORD *)((char *)&unk_4EE150 + v20);
                ++v69;
                v55[v21] = v22;
              }
              v20 += 2;
            }
            while ( v20 < 0x38 );
            if ( v69 )
            {
              v24 = rand() % v69;
              v23 = dword_A74CDC;
              if ( dword_A74CDC == -1 )
              {
                v23 = v24;
                dword_A74CDC = v24;
              }
              v13 = dword_723E80[2 * v55[v23]];
            }
            else
            {
              v13 = dword_721824;
            }
            v8 = v67;
            v12 = a3;
            goto LABEL_118;
          case 0x21A:
            if ( *(_BYTE *)(v8 + 184) )
LABEL_43:
              v13 = (int)pGlobalTXT_LocalizationStrings[389];
            else
              v13 = (int)pGlobalTXT_LocalizationStrings[388];
            goto LABEL_118;
          case 0x21B:
            v25 = sub_47752B();
            goto LABEL_46;
          case 0x21C:
            v25 = *(_DWORD *)(v71 + 16);
LABEL_46:
            if ( v25 >= 25 )
            {
              v13 = (int)pGlobalTXT_LocalizationStrings[379];
            }
            else
            {
              if ( v25 < 6 )
              {
                if ( v25 >= -5 )
                {
                  v13 = (int)pGlobalTXT_LocalizationStrings[399];
                }
                else
                {
                  if ( v25 < -24 )
                    v13 = (int)pGlobalTXT_LocalizationStrings[434];
                  else
                    v13 = (int)pGlobalTXT_LocalizationStrings[402];
                }
              }
              else
              {
                v13 = (int)pGlobalTXT_LocalizationStrings[392];
              }
            }
            goto LABEL_118;
          case 0x21D:
            v13 = sub_495366(*(_BYTE *)(v8 + 168), *(_BYTE *)(v8 + 184));
            goto LABEL_118;
          case 0x21E:
            goto LABEL_93;
          case 0x214:
            goto LABEL_117;
          default:
            goto LABEL_108;
        }
        goto LABEL_108;
      }
      v13 = (int)pGlobalTXT_LocalizationStrings[393];
      goto LABEL_118;
    }
    if ( v15 <= 29 )
    {
      if ( v15 == 29 )
      {
        v34 = *((float *)&unk_591458 + 13 * a4);
      }
      else
      {
        if ( v16 + 10 * (unsigned __int8)*v17 == 544 )
        {
LABEL_93:
          if ( *(_DWORD *)(v71 + 64) )
            v13 = (int)pGlobalTXT_LocalizationStrings[391];
          else
            v13 = (int)pGlobalTXT_LocalizationStrings[390];
          goto LABEL_118;
        }
        if ( v16 + 10 * (unsigned __int8)*v17 == 545 )
        {
          v26 = dword_737C28[5 * *(_DWORD *)(v71 + 24)] / 100;
          goto LABEL_91;
        }
        if ( v16 + 10 * (unsigned __int8)*v17 == 551 )
        {
          v47 = CMapStats_FindLocation(pMapStats, CurrentLevelName);
          if ( v47 )
           v13 = (int)pMapStats->pMapInfos[v47].pLocationName;
          else
            v13 = (int)pGlobalTXT_LocalizationStrings[394];
          goto LABEL_118;
        }
        if ( v16 + 10 * (unsigned __int8)*v17 == 552 )
        {
          v46 = ItemGen_sub_456499((ItemGen *)v12);
          wsprintfA(Dest, "\f%06x%s\f000000", v65, v46);
LABEL_117:
          v13 = (int)Dest;
          goto LABEL_118;
        }
        if ( v16 + 10 * (unsigned __int8)*v17 == 553 )
        {
          v37 = (float *)((char *)&unk_591458 + 52 * a4);
          v38 = *v37;
          v39 = ItemGen_sub_456442((ItemGen *)v12);
          v26 = sub_4B8233(v39, v38);
          switch ( a5 )
          {
            case 3:
              v44 = *v37;
              v45 = ItemGen_sub_456442((ItemGen *)v12);
              v26 = sub_4B8213(v45, v44);
              break;
            case 4:
              v26 = sub_4B824B(*v37);
              break;
            case 5:
              v42 = *v37;
              v43 = ItemGen_sub_456442((ItemGen *)v12);
              v26 = sub_4B8265(v43, v42);
              break;
            case 6:
              v40 = *v37;
              v41 = ItemGen_sub_456442((ItemGen *)v12);
              v26 = sub_4B8213(v41, v40) / 2;
              break;
          }
          goto LABEL_98;
        }
        if ( v16 + 10 * (unsigned __int8)*v17 != 555 )
        {
          if ( v16 + 10 * (unsigned __int8)*v17 != 556 )
          {
LABEL_108:
            strncpy(Dest, v17, 2);
            v51 = atoi(Dest);
            wsprintfA(Dest, "%lu", v51);
            goto LABEL_117;
          }
          v13 = dword_591448[13 * a4];
LABEL_118:
          strcat((char *)pStringBuffer, (const char *)v13);
          v10 = strlen((char *)pStringBuffer);
          v70 += 2;
          v11 = v70;
          goto LABEL_119;
        }
        v27 = (char *)&unk_591458 + 52 * a4;
        v28 = *(float *)v27;
        v29 = ItemGen_sub_456442((ItemGen *)v12);
        v26 = Player_sub_4B8142((Player *)v8, v29, v28);
        if ( a5 == 3 )
        {
          v35 = *(float *)v27;
          v36 = ItemGen_sub_456442((ItemGen *)v12);
          v26 = Player_sub_4B8102((Player *)v8, v36, v35);
          if ( *(_BYTE *)(v12 + 20) & 2 )
          {
LABEL_77:
            v26 = 1;
            goto LABEL_98;
          }
          goto LABEL_98;
        }
        if ( a5 != 4 )
        {
          if ( a5 == 5 )
          {
            v32 = *(float *)v27;
            v33 = ItemGen_sub_456442((ItemGen *)v12);
            v26 = Player_sub_4B81C3((Player *)v8, v33, v32);
          }
          else
          {
            if ( a5 == 6 )
            {
              v30 = *(float *)v27;
              v31 = ItemGen_sub_456442((ItemGen *)v12);
              v26 = Player_sub_4B8102((Player *)v8, v31, v30) / 2;
              if ( *(_BYTE *)(v12 + 20) & 2 )
                v26 = 1;
LABEL_91:
              if ( v26 >= 1 )
                goto LABEL_98;
              goto LABEL_77;
            }
          }
LABEL_98:
          wsprintfA(Dest, "%lu", v26);
          goto LABEL_117;
        }
        v34 = *(float *)v27;
      }
      v48 = v34;
      v26 = Player_sub_4B8179((Player *)v8, v48);
      goto LABEL_98;
    }
    if ( v15 != 30 )
    {
      switch ( v15 )
      {
        case 31:
          v52 = (int)pPlayers[1];
          break;
        case 32:
          v52 = (int)pPlayers[2];
          break;
        case 33:
          v52 = (int)pPlayers[3];
          break;
        default:
          if ( v15 != 34 )
          {
            if ( v15 <= 50 || v15 > 70 )
              goto LABEL_108;
            if ( v16 + 10 * (unsigned __int8)*v17 - 579 >= 20 )
              goto LABEL_118;
            HIDWORD(v50) = pParty_global->Abc.array_00047C[2 * v15 + 1];
            LODWORD(v50) = pParty_global->Abc.array_00047C[2 * v15];
            sub_493F79((int)&v56, v50);
            v54 = v59;
            v53 = v57 + 1;
            v49 = v58;
LABEL_116:
            wsprintfA(Dest, (char *)pGlobalTXT_LocalizationStrings[378], aMonthNames[v49], v53, v54);
            goto LABEL_117;
          }
          v52 = (int)pPlayers[4];
          break;
      }
      v13 = v52 + 168;
      goto LABEL_118;
    }
    if ( !a6 )
      goto LABEL_118;
    sub_493F79((int)&v60, *a6);
    v54 = v63;
    v53 = v61 + 1;
    v49 = v62;
    goto LABEL_116;
  }
  return (char *)pStringBuffer;
}

//----- (004979D2) -----.text:00499660  ---------------------------------------------------
int CreditsMenuLoop()
{
  FILE *v0; // eax@5
  char *v1; // edi@5
  int v2; // eax@5
  int v3; // esi@7
  Font *v4; // dl@9
  Font *v5; // ecx@9
  __int16 v6; // ax@9
  unsigned int v8; // ST2C_4@9
  int v9; // eax@9
  int v10; // eax@9
  unsigned int v11; // ST2C_4@19
  int v12; // eax@19
  int v14; // eax@24
  int v15; // eax@24
  cTexture cTexture_obj;//[128]; // [sp+Ch] [bp-130h]@5
  int v17; // [sp+20h] [bp-11Ch]@8
  size_t Count; // [sp+34h] [bp-108h]@7
  class cPCXTexture cBackGround;
  //char v19; // [sp+54h] [bp-E8h]@1
  double v20; // [sp+7Ch] [bp-C0h]@9
  MSG Msg; // [sp+84h] [bp-B8h]@10
  int v22; // [sp+A0h] [bp-9Ch]@9
 // int v23; // [sp+A4h] [bp-98h]@9
 // int v24; // [sp+A8h] [bp-94h]@9
  //int v25; // [sp+ACh] [bp-90h]@9
  //int v26; // [sp+B0h] [bp-8Ch]@9
  int v27; // [sp+F8h] [bp-44h]@9
  int v28; // [sp+FCh] [bp-40h]@9
  //char v29; // [sp+100h] [bp-3Ch]@1
 class cPCXTexture v29;
  //unsigned int v30; // [sp+110h] [bp-2Ch]@9
  //__int16 v31; // [sp+114h] [bp-28h]@9
  //__int16 v32; // [sp+116h] [bp-26h]@9
  //int v33; // [sp+120h] [bp-1Ch]@9
  //int v34; // [sp+124h] [bp-18h]@9
  int v35; // [sp+128h] [bp-14h]@1
  char *Dest; // [sp+12Ch] [bp-10h]@9
  char *Source; // [sp+130h] [bp-Ch]@5
  Font *v38; // [sp+134h] [bp-8h]@1
  Font *v39; // [sp+138h] [bp-4h]@1
  GUIWindow stCreditsWindow;

  cBackGround.PCXTexture_Zero();
  v29.PCXTexture_Zero();
  v35 = 0;
  v38 = LoadFont("quick.fnt", "FONTPAL");
  v39 = LoadFont("cchar.fnt", "FONTPAL");
 //if ( dword_50CBD0.msg_count )
	//		   if  (dword_50CBD0.prm[0].msg_param3)
        //                  dword_50CBD0.msg_count = 1;
  dword_50CBD0.CutQueueTail();
  ++LODFile_Icons_LOD.uTexturePacksCount;
  if ( !LODFile_Icons_LOD.uPrevLoadedFiles )
    LODFile_Icons_LOD.uPrevLoadedFiles = LODFile_Icons_LOD.uNumLoadedFiles;
  dword_A74C88 = 0;
  sub_4AA13F((int)pAudioPlayer, 15);
  cBackGround.LODPCXLoad("mm6title.pcx", 0);
  v1 = (char *)LODFile_Events_LOD.LODFile_LoadRaw( "credits.txt", 0);
 // v1 = (const char *)v2;
 // Source = (char *)v1;
  cTexture_obj.cTexture_Zero();
  v0 = LODFile_Events_LOD.Find_Container( "credits.txt", 0);
  if ( !v0 )
    erroneous_printf((char *)pGlobalTXT_LocalizationStrings[LOCSTR_TROUBLE_LOAD]);
  locked_fread(&cTexture_obj, 1, 48, v0);
  v3 = cTexture_obj.uDecompressedSize;
  if ( !cTexture_obj.uDecompressedSize )
    v3 = cTexture_obj.uTextureSize;
  memset(&cTexture_obj, 0, 72);
  v4 = v39;
  v5 = v38;
  v1[v3] = 0;
  stCreditsWindow.uFrameX=389;
  stCreditsWindow.uFrameY=19;
  stCreditsWindow.uFrameWidth=250;
  stCreditsWindow.uFrameHeight=440;
  //v25 = 250;
//  v26 = 440;
 // v23 = 389;
//  v24 = 19;
  v29.uWidth = 250;
  v6 = sub_44C62E(v5, v4, v1,&stCreditsWindow , 0, true);
  v29.uHeight = v6 + 2 * stCreditsWindow.uFrameHeight;
  v29.uNumPixels = v29.uWidth * v29.uHeight;
  v29.pPixels = (unsigned int *)mem_mng.AllocatedNamedBuffer( v29.pPixels, 4 * v29.uNumPixels, "scrollermap");
  v8 = v29.uNumPixels;
  v9 = 0xFF00FFFF;
 // sub_452AF3(v9, v29.pPixels, v29.uNumPixels);
  memset(v29.pPixels,v9,v29.uNumPixels*4);
  v29.word_000020 = 0;
  v29.word_000022 = 0;
  v28 = 0x708FFE;
  v27 = 0xECE69C;
  Dest = new char [2 * v3];
  strncpy(Dest, v1, v3);
  sub_44D2FD(v38, v39, 1, 440 + 1, v29.uWidth, v29.uHeight, 1u, 1u, Dest, (int)v29.pPixels, v29.uWidth);
  strncpy(Dest, v1, v3);
  sub_44D2FD(v38, v39, 0, 440, v29.uWidth, v29.uHeight, v28, v27, Dest, (int)v29.pPixels, v29.uWidth);
  delete(Dest);

  pGUIWindow_MainMenu = GUIWindowCreate(0, 0, 640, 480, 1, 0, (int)v1);
  GUIButtonCreate(pGUIWindow_MainMenu, 0, 0, 0, 0, 1, 0, 113, 0, 27, (unsigned char *)"", 0);
  dword_4E28F8 = 9;
  SetCurrentMenu(8);
  pD3DRenderer->BeginScene();
  Render_DrawRGBTexture(pD3DRenderer, 0, 0, &cBackGround);
  Render_Set2DClippingRect(pD3DRenderer, 389, 19, 389 + 250, 19 + 440);
  sub_4A5D33((int)pD3DRenderer, 389, 19, 0, 0, (int)&v29);
  Render_Reset2DClippingRect(pD3DRenderer);
  pD3DRenderer->EndScene();
  Dest = (char *)1148846080;
  v20 = 1000.0 + 6.755399441055744e15;
  v22 = LODWORD(v20);
  GetTickCount();
  pD3DRenderer->Present();
  do
  {
    while ( PeekMessageA(&Msg, 0, 0, 0, 1) )
    {
      if ( Msg.message == 18 )
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
      if (dword_720010)
        sub_46B736((void *)dword_720010, 1);
      if ( dword_A74C88 )
      {
        cBackGround.LODPCXLoad("mm6title.pcx", 1);
        v11 = v29.uNumPixels;
        v12 = 0xFF00FFFF;
        sub_452AF3(v12, v29.pPixels, v11);
        strncpy((char*)TmpBuf, v1, 2000);
        sub_44D2FD(v38, v39, 1, 440 + 1, v29.uWidth, v29.uHeight, 1u, 1u, (char *)TmpBuf, (int)v29.pPixels, v29.uWidth);
        strncpy((char *)TmpBuf, v1,2000);
        sub_44D2FD(v38, v39, 0, 440, v29.uWidth, v29.uHeight, v28, v27, (char *)TmpBuf, (int)v29.pPixels, v29.uWidth);
        dword_A74C88 = 0;
        pD3DRenderer->BeginScene();
        Render_DrawRGBTexture(pD3DRenderer, 0, 0, &cBackGround);
        Render_Set2DClippingRect(pD3DRenderer, 389, 19, 389 + 250, 389 +440);
        sub_4A5D33((int)pD3DRenderer, 389, 19, 0, v35, (int)&v29);
        Render_Reset2DClippingRect(pD3DRenderer);
        pD3DRenderer->EndScene();
        pD3DRenderer->Present();
      }
      timeGetTime();
      pD3DRenderer->BeginScene();
      Render_DrawRGBTexture(pD3DRenderer, 0, 0, &cBackGround);
      Render_Set2DClippingRect(pD3DRenderer, 389, 19, 389 + 250, 19 + 440);
      sub_4A5D33((int)pD3DRenderer, 389, 19, 0, v35, (int)&v29);
      Render_Reset2DClippingRect(pD3DRenderer);
      pD3DRenderer->EndScene();
      ++v35;
      if ( v35 >= v29.uHeight )
        SetCurrentMenu(MENU_MAIN);
      timeGetTime();
      pD3DRenderer->Present();
      sub_435748();
    }
  }
  while ( sub_466CA0() == 8 );
  sub_435748();
  pD3DRenderer->BeginScene();
  sub_4156F0_LooksLike_UI_ProcessCallbacks();
  pD3DRenderer->EndScene();
  pD3DRenderer->Present();
  AudioPlayer_sub_4AA258((int)pAudioPlayer, 1);
  mem_mng.DeleteBuffer( v29.pPixels);
  mem_mng.DeleteBuffer( v38);
  mem_mng.DeleteBuffer( v39);
  GUIWindowDelete(pGUIWindow_MainMenu);
 // v14 = LODFile_Icons_LOD.LODFile_sub_4114F2();
  cBackGround.PCXTexture_Release();
  v29.PCXTexture_Release();
  return sub_466CA0() - 8;
}

void sub_498069(struct class26_placeholder *_this)
{
 _this->detor_ptr = class26_placeholder_detor;
 _this->objClass26.detor_ptr = class26_detor;
}

//----- (0049804D) --------------------------------------------------------
void __fastcall class26_placeholder_detor(struct class26_placeholder *_this, unsigned int a2)
{
 sub_498069(_this);
 if (a2 & 1)
   operator_delete(_this);
}

//----- (00498069) --------------------------------------------------------
void __fastcall class26_placeholder_default_ctor(struct class26_placeholder *_this)
{
 _this->detor_ptr = class26_placeholder_detor;
 class26_default_ctor(&_this->objClass26);
}

//----- (004980B9) --------------------------------------------------------
char __stdcall sub_4980B9(int a1, signed int a2, float a3, float a4, float a5, int a6, int a7)
{
  int v7; // eax@7
  int v8; // ebx@7
  int v9; // edi@8
  int v10; // ecx@9
  int v11; // esi@9
  int v12; // eax@12
  double v13; // st7@12
  double v14; // st6@12
  double v15; // st5@12
  int v16; // edi@13
  unsigned __int8 v17; // sf@20
  unsigned __int8 v18; // of@20
  int v19; // ecx@25
  int v20; // eax@26
  _UNKNOWN *v21; // edx@26
  char *i; // ecx@26
  int v24; // [sp+0h] [bp-24h]@9
  int v25; // [sp+Ch] [bp-18h]@8
  int v26; // [sp+10h] [bp-14h]@22
  int v27; // [sp+14h] [bp-10h]@15
  signed int v28; // [sp+18h] [bp-Ch]@7
  int v29; // [sp+1Ch] [bp-8h]@12
  int v30; // [sp+1Ch] [bp-8h]@25

  if ( !(byte_AE4C2C & 1) )
  {
    byte_AE4C2C |= 1u;
    flt_AE4C28 = 0.0;
    atexit(0);
  }
  if ( !(byte_AE4C2C & 2) )
  {
    byte_AE4C2C |= 2;
    sub_4BE6D1(&flt_AE4BEC);
    atexit(0);
  }
  if ( !(byte_AE4C2C & 4) )
  {
    byte_AE4C2C |= 4u;
    sub_49835A((int)&unk_AE3FE8);
    atexit(0);
  }
  v7 = 0;
  v8 = a7;
  v28 = 0;
  if ( a2 <= 0 )
    goto LABEL_32;
  v9 = a1 + 8;
  v25 = a1 + 8;
  do
  {
    v11 = v9 - 8;
    v24 = v7 + 1;
    v10 = a1 + 48 * (v7 + 1) % a2;
    if ( *(float *)(v9 - 8) != *(float *)v10
      || *(float *)(v9 - 4) != *(float *)(v10 + 4)
      || *(float *)v9 != *(float *)(v10 + 8) )
    {
      v13 = *(float *)v10 - *(float *)v11;
      v14 = *(float *)(v10 + 4) - *(float *)(v9 - 4);
      v15 = *(float *)(v10 + 8) - *(float *)v9;
      ++v28;
      v12 = 0;
      dword_AE4BE8 = 0;
      v29 = 0;
      flt_AE4BEC = a4 * v15 - v14 * a5;
      flt_AE4BF0 = v13 * a5 - v15 * a3;
      flt_AE4BF4 = v14 * a3 - v13 * a4;
      if ( *(_DWORD *)v8 <= 0 )
        goto LABEL_32;
      do
      {
        v16 = a6 + 48 * v12;
        if ( v12 )
        {
          if ( sub_4989E1(v27, a6 + 48 * v12, v11, (int)&flt_AE4BEC) )
          {
            if ( sub_498774(v27, v16, v11, (int)&flt_AE4BEC, (int)&unk_AE4BFC) )
              sub_498737((int)&unk_AE3FE8, (int)&unk_AE4BFC);
          }
        }
        else
        {
          v26 = a6 + 48 * v12;
        }
        v27 = v16;
        if ( sub_49895A(v16, v11, (int)&flt_AE4BEC) )
          sub_498737((int)&unk_AE3FE8, v16);
        v8 = a7;
        v12 = v29 + 1;
        compile_error;//v18 = __SETO__(v29 + 1, *(_DWORD *)a7);
        v17 = v29++ + 1 - *(_DWORD *)a7 < 0;
      }
      while ( v17 ^ v18 );
      if ( !dword_AE4BE8 )
        goto LABEL_32;
      if ( sub_4989E1(v16, v26, v11, (int)&flt_AE4BEC) )
      {
        if ( sub_498774(v16, v26, v11, (int)&flt_AE4BEC, (int)&unk_AE4BFC) )
          sub_498737((int)&unk_AE3FE8, (int)&unk_AE4BFC);
      }
      v19 = dword_AE4BE8;
      v30 = 0;
      if ( dword_AE4BE8 > 0 )
      {
        v21 = &unk_AE3FE8;
        v20 = a6 + 4;
        for ( i = (char *)&unk_AE4008 - a6; ; i = (char *)&unk_AE4008 - a6 )
        {
          ++v30;
          *(_DWORD *)(v20 - 4) = *(_DWORD *)v21;
          v21 = (char *)v21 + 48;
          *(float *)v20 = *(float *)((char *)&unk_AE3FE8 + v20 - a6);
          *(float *)(v20 + 4) = *(float *)((char *)&unk_AE3FEC + v20 - a6);
          *(float *)(v20 + 32) = *(float *)&i[v20];
          *(float *)(v20 + 36) = *(float *)((char *)&unk_AE400C + v20 - a6);
          v19 = dword_AE4BE8;
          v20 += 48;
          if ( v30 >= dword_AE4BE8 )
            break;
        }
      }
      v8 = a7;
      v9 = v25;
      *(_DWORD *)a7 = v19;
    }
    v7 = v24;
    v9 += 48;
    v25 = v9;
  }
  while ( v24 < a2 );
  if ( v28 < 3 )
LABEL_32:
    *(_DWORD *)v8 = 0;
  return 1;
}

//----- (0049835A) --------------------------------------------------------
__int64 __fastcall sub_49835A(int a1)
{
  __int64 result; // qax@1
  signed int v2; // ecx@1

  LODWORD(result) = a1;
  v2 = 64;
  HIDWORD(result) = result + 44;
  do
  {
    compile_error;//*HIDWORD(result) = 0.0;
    result += 206158430208i64;
    --v2;
  }
  while ( v2 );
  *(_DWORD *)(result + 3072) = 0;
  return result;
}

//----- (00498377) --------------------------------------------------------
char __stdcall sub_498377(int a1, signed int a2, int a3, int a4, int a5)
{
  int v5; // eax@7
  int v6; // ebx@7
  int v7; // esi@8
  int v8; // ecx@9
  int v9; // eax@12
  double v10; // st7@12
  double v11; // st6@12
  int v12; // esi@13
  unsigned __int8 v13; // sf@20
  unsigned __int8 v14; // of@20
  int v15; // ecx@25
  int v16; // eax@26
  _UNKNOWN *v17; // edx@26
  char *i; // ecx@26
  int v20; // [sp+0h] [bp-28h]@9
  int v21; // [sp+10h] [bp-18h]@8
  int v22; // [sp+14h] [bp-14h]@22
  int v23; // [sp+18h] [bp-10h]@15
  signed int v24; // [sp+1Ch] [bp-Ch]@7
  int v25; // [sp+20h] [bp-8h]@8
  int v26; // [sp+38h] [bp+10h]@12
  int v27; // [sp+38h] [bp+10h]@25

  if ( !(byte_AE3FE4 & 1) )
  {
    byte_AE3FE4 |= 1u;
    flt_AE3FE0 = 0.0;
    atexit(0);
  }
  if ( !(byte_AE3FE4 & 2) )
  {
    byte_AE3FE4 |= 2;
    sub_4BE6D1(&flt_AE3FA4);
    atexit(0);
  }
  if ( !(byte_AE3FE4 & 4) )
  {
    byte_AE3FE4 |= 4u;
    sub_49835A((int)&unk_AE33A0);
    atexit(0);
  }
  v5 = 0;
  v6 = a5;
  v24 = 0;
  if ( a2 <= 0 )
    goto LABEL_32;
  v25 = a1;
  v7 = a3 + 12;
  v21 = a3 + 12;
  do
  {
    v20 = v5 + 1;
    v8 = a1 + 48 * (v5 + 1) % a2;
    if ( *(float *)v25 != *(float *)v8
      || *(float *)(v25 + 4) != *(float *)(v8 + 4)
      || *(float *)(v25 + 8) != *(float *)(v8 + 8) )
    {
      v10 = *(float *)(v7 + 4);
      v11 = *(float *)v7;
      ++v24;
      v9 = 0;
      flt_AE3FA4 = *(float *)(v7 - 4);
      dword_AE3FA0 = 0;
      v26 = 0;
      flt_AE3FA8 = v11;
      flt_AE3FAC = v10;
      if ( *(_DWORD *)v6 <= 0 )
        goto LABEL_32;
      do
      {
        v12 = a4 + 48 * v9;
        if ( v9 )
        {
          if ( sub_4989E1(v23, a4 + 48 * v9, v25, (int)&flt_AE3FA4) )
          {
            if ( sub_498774(v23, v12, v25, (int)&flt_AE3FA4, (int)&unk_AE3FB4) )
              sub_498737((int)&unk_AE33A0, (int)&unk_AE3FB4);
          }
        }
        else
        {
          v22 = a4 + 48 * v9;
        }
        v23 = v12;
        if ( sub_49895A(v12, v25, (int)&flt_AE3FA4) )
          sub_498737((int)&unk_AE33A0, v12);
        v6 = a5;
        v9 = v26 + 1;
        compile_error;//v14 = __SETO__(v26 + 1, *(_DWORD *)a5);
        v13 = v26++ + 1 - *(_DWORD *)a5 < 0;
      }
      while ( v13 ^ v14 );
      if ( !dword_AE3FA0 )
        goto LABEL_32;
      if ( sub_4989E1(v12, v22, v25, (int)&flt_AE3FA4) )
      {
        if ( sub_498774(v12, v22, v25, (int)&flt_AE3FA4, (int)&unk_AE3FB4) )
          sub_498737((int)&unk_AE33A0, (int)&unk_AE3FB4);
      }
      v15 = dword_AE3FA0;
      v27 = 0;
      if ( dword_AE3FA0 > 0 )
      {
        v17 = &unk_AE33A0;
        v16 = a4 + 4;
        for ( i = (char *)&unk_AE33A4 - a4; ; i = (char *)&unk_AE33A4 - a4 )
        {
          ++v27;
          *(_DWORD *)(v16 - 4) = *(_DWORD *)v17;
          v17 = (char *)v17 + 48;
          *(float *)v16 = *(float *)((char *)&unk_AE33A0 + v16 - a4);
          *(float *)(v16 + 4) = *(float *)&i[v16];
          *(float *)(v16 + 32) = *(float *)((char *)&unk_AE33C0 + v16 - a4);
          *(float *)(v16 + 36) = *(float *)((char *)&unk_AE33C4 + v16 - a4);
          v15 = dword_AE3FA0;
          v16 += 48;
          if ( v27 >= dword_AE3FA0 )
            break;
        }
      }
      v6 = a5;
      v7 = v21;
      *(_DWORD *)a5 = v15;
    }
    v5 = v20;
    v25 += 48;
    v7 += 24;
    v21 = v7;
  }
  while ( v20 < a2 );
  if ( v24 < 3 )
LABEL_32:
    *(_DWORD *)v6 = 0;
  return 1;
}

//----- (004985FB) --------------------------------------------------------
char __stdcall sub_4985FB(int a1, signed int a2, void *a3, int a4, int a5, float a6, int a7, int a8)
{
  int v8; // ecx@1
  int v9; // ebx@1
  void *v10; // edi@1
  int v11; // esi@1
  double v12; // st7@1
  int v13; // eax@4
  signed int v14; // edx@9
  int v15; // ecx@9
  double v16; // st7@9
  double v17; // st6@12
  char result; // al@15
  int v19; // [sp+Ch] [bp-Ch]@7
  float v20; // [sp+10h] [bp-8h]@1
  bool v21; // [sp+14h] [bp-4h]@2

  v8 = a1;
  v11 = a5;
  v9 = a1 + 8;
  v10 = a3;
  v12 = *(float *)(a1 + 4) * *(float *)(a5 + 4) + *(float *)a5 * *(float *)a1 + *(float *)(a1 + 8) * *(float *)(a5 + 8);
  v20 = v12;
  v21 = v12 >= a6;
  v13 = 0;
  *(_DWORD *)a4 = 0;
  if ( a2 <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    v19 = v13 + 1;
    if ( v21 )
    {
      a3 = (char *)a3 + 48;
      memcpy(v10, (const void *)(v9 - 8), 0x30u);
      ++*(_DWORD *)a4;
      v11 = a5;
      v10 = a3;
      v8 = a1;
    }
    v14 = 0;
    v15 = 48 * (v13 + 1) % a2 + v8;
    v16 = *(float *)(v15 + 8) * *(float *)(v11 + 8)
        + *(float *)(v15 + 4) * *(float *)(v11 + 4)
        + *(float *)v11 * *(float *)v15;
    if ( v16 >= a6 )
      v14 = 1;
    if ( v21 != v14 )
    {
      v17 = (a6 - v20) / (v16 - v20);
      *(float *)v10 = (*(float *)v15 - *(float *)(v9 - 8)) * v17 + *(float *)(v9 - 8);
      v10 = (char *)v10 + 48;
      a3 = v10;
      *((float *)v10 - 11) = (*(float *)(v15 + 4) - *(float *)(v9 - 4)) * v17 + *(float *)(v9 - 4);
      *((float *)v10 - 10) = (*(float *)(v15 + 8) - *(float *)v9) * v17 + *(float *)v9;
      *((float *)v10 - 3) = (*(float *)(v15 + 36) - *(float *)(v9 + 28)) * v17 + *(float *)(v9 + 28);
      *((float *)v10 - 2) = (*(float *)(v15 + 40) - *(float *)(v9 + 32)) * v17 + *(float *)(v9 + 32);
      ++*(_DWORD *)a4;
      *(_BYTE *)a7 = 1;
    }
    ++v13;
    v9 += 48;
    v21 = v14;
    v20 = v16;
    if ( v19 >= a2 )
      break;
    v8 = a1;
  }
  if ( *(_DWORD *)a4 >= 3 )
    result = 1;
  else
LABEL_19:
    result = 0;
  return result;
}

//----- (00498737) --------------------------------------------------------
int __stdcall sub_498737(int a1, int a2)
{
  int result; // eax@1

  result = a1 + 48 * *(_DWORD *)(a1 + 3072);
  *(_DWORD *)result = *(_DWORD *)a2;
  *(_DWORD *)(result + 4) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(result + 36) = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(result + 40) = *(_DWORD *)(a2 + 40);
  ++*(_DWORD *)(a1 + 3072);
  return result;
}

//----- (00498774) --------------------------------------------------------
char __stdcall sub_498774(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // ecx@5
  double v6; // st7@5
  double v7; // st7@6
  double v8; // st6@8
  double v10; // st6@18
  float v11; // [sp+10h] [bp+8h]@5

  if ( !(byte_AE3398 & 1) )
  {
    byte_AE3398 |= 1u;
    sub_4BE6D1(&flt_AE3388);
    atexit(0);
  }
  if ( !(byte_AE3398 & 2) )
  {
    byte_AE3398 |= 2;
    sub_4BE6D1(&flt_AE3378);
    atexit(0);
  }
  v5 = a1;
  flt_AE3378 = *(float *)a1 - *(float *)a3;
  flt_AE337C = *(float *)(a1 + 4) - *(float *)(a3 + 4);
  flt_AE3380 = *(float *)(a1 + 8) - *(float *)(a3 + 8);
  flt_AE3388 = *(float *)a2 - *(float *)a1;
  flt_AE338C = *(float *)(a2 + 4) - *(float *)(a1 + 4);
  flt_AE3390 = *(float *)(a2 + 8) - *(float *)(a1 + 8);
  v11 = flt_AE3388 * *(float *)a4 + flt_AE3390 * *(float *)(a4 + 8) + flt_AE338C * *(float *)(a4 + 4);
  v6 = flt_AE3378 * *(float *)a4 + flt_AE3380 * *(float *)(a4 + 8) + flt_AE337C * *(float *)(a4 + 4);
  if ( v11 != 0.0 )
  {
    v7 = -(v6 / v11);
    if ( v11 <= 0.0 )
    {
      if ( v7 <= 0.0 )
        v10 = 0.0;
      else
        v10 = v7;
      if ( v10 <= 1.0 )
      {
        if ( v7 <= 0.0 )
          v7 = (float)0.0;
      }
      else
      {
        v7 = 1.0;
      }
    }
    else
    {
      if ( v7 >= 1.0 )
        v8 = 1.0;
      else
        v8 = v7;
      if ( v8 >= 0.0 )
      {
        if ( v7 >= 1.0 )
          v7 = (float)1.0;
      }
      else
      {
        v7 = 0.0;
      }
    }
    *(float *)a5 = (*(float *)a2 - *(float *)v5) * v7 + *(float *)v5;
    *(float *)(a5 + 4) = (*(float *)(a2 + 4) - *(float *)(v5 + 4)) * v7 + *(float *)(v5 + 4);
    *(float *)(a5 + 8) = (*(float *)(a2 + 8) - *(float *)(v5 + 8)) * v7 + *(float *)(v5 + 8);
    *(float *)(a5 + 36) = (*(float *)(a2 + 36) - *(float *)(v5 + 36)) * v7 + *(float *)(v5 + 36);
    *(float *)(a5 + 40) = (*(float *)(a2 + 40) - *(float *)(v5 + 40)) * v7 + *(float *)(v5 + 40);
    return 1;
  }
  if ( v6 < 0.0 )
    return 1;
  return 0;
}

//----- (0049895A) --------------------------------------------------------
char __stdcall sub_49895A(int a1, int a2, int a3)
{
  double v3; // st7@3
  double v4; // st7@3

  if ( !(byte_F94298 & 1) )
  {
    byte_F94298 |= 1u;
    sub_4BE6D1(&flt_F942A0);
    atexit(0);
  }
  flt_F942A0 = *(float *)a1 - *(float *)a2;
  flt_F942A4 = *(float *)(a1 + 4) - *(float *)(a2 + 4);
  v3 = *(float *)(a1 + 8) - *(float *)(a2 + 8);
  flt_F942A8 = v3;
  v4 = v3 * *(float *)(a3 + 8) + flt_F942A4 * *(float *)(a3 + 4) + flt_F942A0 * *(float *)a3;
  flt_F942B0 = v4;
  return v4 >= 0.0;
}

//----- (004989E1) --------------------------------------------------------
char __stdcall sub_4989E1(int a1, int a2, int a3, int a4)
{
  char v4; // al@1
  char v5; // bl@1

  v5 = sub_49895A(a1, a3, a4);
  v4 = sub_49895A(a2, a3, a4);
  return !v5 && v4 == 1 || v5 == 1 && !v4;
}

//----- (00498A41) --------------------------------------------------------
char __thiscall sub_498A41(int _this, int a2, int a3)
{
  int v3; // eax@1
  int v4; // ebx@1
  signed __int64 v5; // qax@2
  double v6; // st7@8
  float v8; // [sp+Ch] [bp-Ch]@8
  float v9; // [sp+10h] [bp-8h]@8
  float v10; // [sp+14h] [bp-4h]@8

  v4 = _this;
  LOBYTE(v3) = *(_BYTE *)(_this + 92);
  if ( (_BYTE)v3 == 1 )
  {
    *(_DWORD *)a2 = -*(_DWORD *)(_this + 20);
    LODWORD(v5) = *(_DWORD *)(_this + 16);
LABEL_9:
    *(_DWORD *)(a2 + 4) = v5;
    v3 = 0;
    *(_DWORD *)(a2 + 8) = 0;
    *(_DWORD *)(a3 + 4) = 0;
    *(_DWORD *)(a3 + 8) = -65536;
LABEL_11:
    *(_DWORD *)a3 = v3;
    goto LABEL_12;
  }
  if ( (_BYTE)v3 == 3 || (_BYTE)v3 == 5 )
  {
LABEL_10:
    v3 = 0;
    *(_DWORD *)a2 = 65536;
    *(_DWORD *)(a2 + 8) = 0;
    *(_DWORD *)(a2 + 4) = 0;
    *(_DWORD *)(a3 + 4) = -65536;
    *(_DWORD *)(a3 + 8) = 0;
    goto LABEL_11;
  }
  if ( (_BYTE)v3 == 4 || (_BYTE)v3 == 6 )
  {
    if ( abs(*(_DWORD *)(_this + 24)) < 46441 )
    {
      v8 = (double)-*(_DWORD *)(v4 + 20);
      v9 = (double)*(signed int *)(v4 + 16);
      v10 = 0.0;
      sub_4369DB((int)&v8);
      v6 = v9 * 65536.0;
      *(_DWORD *)a2 = (signed __int64)(v8 * 65536.0);
      v5 = (signed __int64)v6;
      goto LABEL_9;
    }
    goto LABEL_10;
  }
LABEL_12:
  if ( *(_BYTE *)(v4 + 46) & 0x80 )
  {
    *(_DWORD *)a2 = -*(_DWORD *)a2;
    *(_DWORD *)(a2 + 4) = -*(_DWORD *)(a2 + 4);
    *(_DWORD *)(a2 + 8) = -*(_DWORD *)(a2 + 8);
  }
  if ( *(_BYTE *)(v4 + 47) & 1 )
  {
    *(_DWORD *)a3 = -*(_DWORD *)a3;
    *(_DWORD *)(a3 + 4) = -*(_DWORD *)(a3 + 4);
    *(_DWORD *)(a3 + 8) = -*(_DWORD *)(a3 + 8);
  }
  return v3;
}

//----- (00498B15) --------------------------------------------------------
int __thiscall sub_498B15(int _this)
{
  int result; // eax@1
  int v2; // esi@1
  int v3; // ebp@1
  int v4; // ST00_4@1

  v2 = _this;
  v3 = _this + 692;
  mem_mng.DeleteBuffer( (void *)*(_DWORD *)(_this + 692));
  *(_DWORD *)v3 = 0;
  mem_mng.DeleteBuffer( (void *)*(_DWORD *)(v2 + 688));
  *(_DWORD *)(v2 + 688) = 0;
  mem_mng.DeleteBuffer( (void *)*(_DWORD *)(v2 + 696));
  *(_DWORD *)(v2 + 696) = 0;
  mem_mng.DeleteBuffer( (void *)*(_DWORD *)(v2 + 684));
  *(_DWORD *)(v2 + 684) = 0;
  mem_mng.DeleteBuffer( (void *)*(_DWORD *)(v2 + 704));
  v4 = *(_DWORD *)(v2 + 628);
  *(_DWORD *)(v2 + 704) = 0;
  *(_DWORD *)(v2 + 648) = 0;
  *(_DWORD *)(v2 + 632) = 0;
  *(_DWORD *)(v2 + 624) = 0;
  *(_DWORD *)(v2 + 672) = 0;
  *(_DWORD *)(v2 + 664) = 0;
  *(_DWORD *)(v2 + 656) = 0;
  mem_mng.DeleteBuffer( (void *)v4);
  mem_mng.DeleteBuffer( (void *)*(_DWORD *)(v2 + 636));
  mem_mng.DeleteBuffer( (void *)*(_DWORD *)(v2 + 644));
  mem_mng.DeleteBuffer( (void *)*(_DWORD *)(v2 + 652));
  mem_mng.DeleteBuffer( (void *)*(_DWORD *)(v2 + 660));
  mem_mng.DeleteBuffer( (void *)*(_DWORD *)(v2 + 668));
  mem_mng.DeleteBuffer( (void *)*(_DWORD *)(v2 + 676));
  mem_mng.DeleteBuffer( (void *)*(_DWORD *)(v2 + 680));
  *(_DWORD *)(v2 + 628) = 0;
  *(_DWORD *)(v2 + 636) = 0;
  *(_DWORD *)(v2 + 644) = 0;
  *(_DWORD *)(v2 + 652) = 0;
  *(_DWORD *)(v2 + 660) = 0;
  *(_DWORD *)(v2 + 668) = 0;
  *(_DWORD *)(v2 + 676) = 0;
  *(_DWORD *)(v2 + 680) = 0;
  *(_DWORD *)(v2 + 80) = 0;
  return result;
}

//----- (00498C45) --------------------------------------------------------
signed int __thiscall sub_498C45(int _this)
{
  int v1; // eax@1
  void *v2; // ecx@1
  int v3; // esi@1
  int v4; // eax@1
  int v5; // ST3C_4@1
  int v6; // eax@1
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

  v3 = _this;
  v4 = (int)mem_mng.AllocatedNamedBuffer((void*) *(_DWORD *)(_this + 628), 90000, "L.V");
  v5 = *(_DWORD *)(v3 + 636);
  *(_DWORD *)(v3 + 628) = v4;
  v6 = (int)mem_mng.AllocatedNamedBuffer(  (void*)v5, 960000, "L.F");
  v7 = *(_DWORD *)(v3 + 644);
  *(_DWORD *)(v3 + 636) = v6;
  v8 = (int)mem_mng.AllocatedNamedBuffer(  (void*)v7, 180000, "L.FX");
  v9 = *(_DWORD *)(v3 + 652);
  *(_DWORD *)(v3 + 644) = v8;
  v10 = (int)mem_mng.AllocatedNamedBuffer( (void*) v9, 59392, "L.R");
  v11 = *(_DWORD *)(v3 + 660);
  *(_DWORD *)(v3 + 652) = v10;
  v12 = (int)mem_mng.AllocatedNamedBuffer( (void*) v11, 6400, "L.L");
  v13 = *(_DWORD *)(v3 + 668);
  *(_DWORD *)(v3 + 660) = v12;
  v14 = (int)mem_mng.AllocatedNamedBuffer(  (void*)v13, 16000, "L.D");
  v15 = *(_DWORD *)(v3 + 676);
  *(_DWORD *)(v3 + 668) = v14;
  v16 = (int)mem_mng.AllocatedNamedBuffer(  (void*)v15, 40000, "L.BSP");
  v17 = *(_DWORD *)(v3 + 680);
  *(_DWORD *)(v3 + 676) = v16;
  v1 = (int)mem_mng.AllocatedNamedBuffer(  (void*)v17, 84004, "L.Map");
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
  return result;
}

//----- (00498E0A) --------------------------------------------------------
signed int __thiscall sub_498E0A(void *Dest, const char *Args, int a3, int i, int a5)
{
 compile_error;
 //load ddm?
 return 0;
/*
  int v5; // ebx@1
  int v6; // esi@1
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
  size_t v90; // eax@56
  int v91; // eax@56
  char v92; // zf@56
  void *v93; // eax@67
  int v94; // ebx@67
  size_t v95; // edi@67
  int v96; // eax@71
  int v97; // eax@72
  const void *v98; // ebx@72
  const void *v99; // ebx@72
  const void *v100; // ebx@72
  const void *v101; // ebx@72
  int v102; // eax@72
  size_t v103; // ecx@72
  unsigned __int8 v104; // zf@72
  unsigned __int8 v105; // sf@72
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
  size_t v172; // eax@103
  size_t v173; // ebx@109
  int v174; // eax@114
  int v175; // ecx@116
  int v176; // eax@117
  size_t v177; // ebx@126
  int v178; // eax@130
  char v179; // zf@132
  size_t v180; // ebx@134
  int v181; // eax@138
  size_t v182; // eax@140
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
  int v230; // [sp-14h] [bp-67Ch]@66
  int v231; // [sp-10h] [bp-678h]@66
  int v232; // [sp-Ch] [bp-674h]@66
  int v233; // [sp-8h] [bp-670h]@4
  int v234; // [sp-4h] [bp-66Ch]@4
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
  char *v270; // [sp+634h] [bp-34h]@38
  int v271; // [sp+638h] [bp-30h]@61
  char v272; // [sp+63Ch] [bp-2Ch]@61
  char v273; // [sp+63Dh] [bp-2Bh]@61
  char v274; // [sp+63Eh] [bp-2Ah]@61
  char v275; // [sp+63Fh] [bp-29h]@61
  size_t v276; // [sp+640h] [bp-28h]@61
  size_t Size; // [sp+644h] [bp-24h]@61
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
  v6 = (int)Dest;
  dword_6807E0 = 0;
  wsprintfA(&FileName, "levels\\%s", Args);
  if ( _access(&FileName, 4) != -1 )
  {
    sub_498B15(v6);
    if ( sub_498C45(v6) )
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
              v26 = LODFile_LoadTexture((int)&unk_6F0E80, &Dst, 0);
              v27 = a5;
              *(_WORD *)(a5 + *(_DWORD *)(v6 + 636) + 74) = v26;
              *(_BYTE *)(v27 + *(_DWORD *)(v6 + 636) + 45) &= 0xBFu;
            }
          }
          else
          {
            *(_WORD *)(a5 + *(_DWORD *)(v6 + 636) + 74) = LODFile_LoadTexture((int)&unk_6F0E80, &Dst, 0);
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
          v28 = LODFile_LoadTexture((int)&unk_6F0E80, &Dst, 0);
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
          v79 = sub_4488B6(pDecorationDescriptionList, &Str1);
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
  }
  if ( !LODFile_Games_LOD_FindLeveL((int)&unk_6A0A60, Args) )
    erroneous_printf("Unable to find %s in Games.LOD", Args);
  v270 = (char *)(Args - 4);
  v90 = strlen(Args);
  strcpy(&v270[v90], ".blv");
  v91 = LODFile_FindContainer(unk_6A0A60, Args, 1);
  v92 = *(_DWORD *)(v6 + 80) == 0;
  File = (FILE *)v91;
  if ( !v92 )
    return 3;
  sub_498B15(v6);
  if ( !sub_498C45(v6) )
    return 4;
  v272 = 109;
  v271 = 91969;
  v273 = 118;
  v274 = 105;
  v275 = 105;
  v276 = 0;
  Size = 0;
  locked_fread(&v271, 0x10u, 1u, File);
  if ( v271 != 91969 || v272 != 109 || v273 != 118 || v274 != 105 || v275 != 105 )
  {
    v234 = 792;
    v233 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Polydata.cpp";
    v278 = (unsigned int)&v229;
    Game_sub_40E2C8(&v229, "Can't load file!", (int)((char *)&v280 + 3));
    sub_466D09(&v278, *(int *)&v229, v230, v231, v232, (const char *)v233, v234);
  }
  v95 = v276;
  ElementSize = Size;
  v93 = malloc(Size);
  v94 = (int)v93;
  v278 = (unsigned int)v93;
  if ( v95 <= ElementSize )
  {
    if ( v95 == ElementSize )
    {
      locked_fread(v93, ElementSize, 1u, File);
    }
    else
    {
      HIDWORD(v280) = malloc(v95);
      locked_fread(HIDWORD(v280), v95, 1u, File);
      v96 = MemUnzip(v94, (int *)&ElementSize, SHIDWORD(v280), v95);
      free(v96, HIDWORD(v280));
    }
  }
  else
  {
    v234 = 803;
    v233 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Polydata.cpp";
    File = (FILE *)&v229;
    Game_sub_40E2C8(&v229, "Can't load file!", (int)((char *)&v280 + 3));
    sub_466D09(&File, *(int *)&v229, v230, v231, v232, (const char *)v233, v234);
  }
  strcpy((char *)v6, Args);
  v232 = 136;
  v231 = v94;
  v230 = v6 + 488;
  *(_DWORD *)(v6 + 80) = 1;
  memcpy((void *)v230, (const void *)v231, v232);
  v99 = (const void *)(v94 + 136);
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  memcpy((void *)(v6 + 624), v99, 4u);
  v99 = (char *)v99 + 4;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v234 = 6 * *(_DWORD *)(v6 + 624);
  v233 = (int)v99;
  v232 = *(_DWORD *)(v6 + 628);
  v283 = v234;
  memcpy((void *)v232, v99, v234);
  v100 = (char *)v99 + v283;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  memcpy((void *)(v6 + 632), v100, 4u);
  v100 = (char *)v100 + 4;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v234 = 96 * *(_DWORD *)(v6 + 632);
  v233 = (int)v100;
  v232 = *(_DWORD *)(v6 + 636);
  v283 = v234;
  memcpy((void *)v232, v100, v234);
  v101 = (char *)v100 + v283;
  v234 = (int)"L.FData";
  v233 = *(_DWORD *)(v6 + 592);
  v232 = *(_DWORD *)(v6 + 684);
  v102 = mem_mng.AllocatedNamedBuffer( v232, v233, "L.FData");
  v103 = *(_DWORD *)(v6 + 592);
  *(_DWORD *)(v6 + 684) = v102;
  v283 = v103;
  memcpy((void *)v102, v101, v103);
  v98 = (char *)v101 + v283;
  v97 = 0;
  v104 = *(_DWORD *)(v6 + 632) == 0;
  v105 = *(_DWORD *)(v6 + 632) < 0;
  v282 = 0;
  v283 = 0;
  if ( !(v105 | v104) )
  {
    do
    {
      *(_DWORD *)(*(_DWORD *)(v6 + 636) + v97 + 48) = v282 + *(_DWORD *)(v6 + 684);
      v106 = v97 + *(_DWORD *)(v6 + 636);
      Src = (void *)v106;
      v107 = v282 + 2 * *(_BYTE *)(v106 + 93) + 2;
      v108 = v107 + *(_DWORD *)(v6 + 684);
      v282 = v107;
      *((_DWORD *)Src + 13) = v108;
      v109 = v97 + *(_DWORD *)(v6 + 636);
      Src = (void *)v109;
      v110 = v282 + 2 * *(_BYTE *)(v109 + 93) + 2;
      v111 = v110 + *(_DWORD *)(v6 + 684);
      v282 = v110;
      *((_DWORD *)Src + 14) = v111;
      Src = (void *)(v97 + *(_DWORD *)(v6 + 636));
      v112 = *(_DWORD *)(v6 + 684);
      v282 += 2 * *((_BYTE *)Src + 93) + 2;
      *((_DWORD *)Src + 15) = v282 + v112;
      Src = (void *)(v97 + *(_DWORD *)(v6 + 636));
      v113 = *(_DWORD *)(v6 + 684);
      v282 += 2 * *((_BYTE *)Src + 93) + 2;
      *((_DWORD *)Src + 16) = v282 + v113;
      Src = (void *)(v97 + *(_DWORD *)(v6 + 636));
      v97 += 96;
      v114 = *(_DWORD *)(v6 + 684);
      v282 += 2 * *((_BYTE *)Src + 93) + 2;
      ++v283;
      *((_DWORD *)Src + 17) = v282 + v114;
      v282 += 2 * *(_BYTE *)(*(_DWORD *)(v6 + 636) + v97 - 3) + 2;
    }
    while ( v283 < *(_DWORD *)(v6 + 632) );
  }
  v115 = *(_DWORD *)(v6 + 632) == 0;
  v116 = *(_DWORD *)(v6 + 632) < 0;
  v283 = 0;
  if ( !(v116 | v115) )
  {
    v282 = 0;
    do
    {
      memcpy(&Dst, v98, 0xAu);
      v98 = (char *)v98 + 10;
      if ( *(_BYTE *)(v282 + *(_DWORD *)(v6 + 636) + 45) & 0x40 )
      {
        v118 = TextureFrameTable_sub_44E163(pTextureFrameTable, &Dst);
        v119 = v282;
        *(_WORD *)(v282 + *(_DWORD *)(v6 + 636) + 74) = v118;
        v117 = *(_WORD *)(v119 + *(_DWORD *)(v6 + 636) + 74);
        if ( v117 )
        {
          TextureFrameTable_sub_44E0ED(pTextureFrameTable, v117);
        }
        else
        {
          v120 = LODFile_LoadTexture((int)&unk_6F0E80, &Dst, 0);
          v121 = v282;
          *(_WORD *)(v282 + *(_DWORD *)(v6 + 636) + 74) = v120;
          *(_BYTE *)(v121 + *(_DWORD *)(v6 + 636) + 45) &= 0xBFu;
        }
      }
      else
      {
        *(_WORD *)(v282 + *(_DWORD *)(v6 + 636) + 74) = LODFile_LoadTexture((int)&unk_6F0E80, &Dst, 0);
      }
      ++v283;
      v282 += 96;
    }
    while ( v283 < *(_DWORD *)(v6 + 632) );
  }
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  memcpy((void *)(v6 + 640), v98, 4u);
  v123 = (char *)v98 + 4;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v234 = 36 * *(_DWORD *)(v6 + 640);
  v233 = (int)v123;
  v232 = *(_DWORD *)(v6 + 644);
  v283 = v234;
  memcpy((void *)v232, v123, v234);
  v122 = (char *)v123 + v283;
  v283 = 0;
  if ( *(_DWORD *)(v6 + 640) > 0 )
  {
    HIDWORD(v280) = 0;
    do
    {
      memcpy(&Dst, v122, 0xAu);
      v122 = (char *)v122 + 10;
      if ( !_strcmpi(&Dst, Class) )
        *(_WORD *)(HIDWORD(v280) + *(_DWORD *)(v6 + 644) + 14) = -1;
      v124 = LODFile_LoadTexture((int)&unk_6F0E80, &Dst, 0);
      v125 = *(_DWORD *)(v6 + 644);
      v126 = HIDWORD(v280);
      ++v283;
      v280 += 154618822656i64;
      *(_WORD *)(v126 + v125 + 14) = v124;
    }
    while ( v283 < *(_DWORD *)(v6 + 640) );
  }
  v127 = *(_DWORD *)(v6 + 632) == 0;
  v128 = *(_DWORD *)(v6 + 632) < 0;
  v283 = 0;
  if ( !(v128 | v127) )
  {
    v282 = 0;
    do
    {
      v129 = *(_DWORD *)(v6 + 644) + 36 * *(_WORD *)(v282 + *(_DWORD *)(v6 + 636) + 72);
      if ( *(_WORD *)(v129 + 26) )
      {
        if ( sub_44C23B(v129) )
          *(_BYTE *)(v282 + *(_DWORD *)(v6 + 636) + 46) |= 0x10u;
        else
          *(_BYTE *)(v282 + *(_DWORD *)(v6 + 636) + 46) &= 0xEFu;
      }
      ++v283;
      v282 += 96;
    }
    while ( v283 < *(_DWORD *)(v6 + 632) );
  }
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  memcpy((void *)(v6 + 648), v122, 4u);
  v132 = (char *)v122 + 4;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v234 = 116 * *(_DWORD *)(v6 + 648);
  v233 = (int)v132;
  v232 = *(_DWORD *)(v6 + 652);
  v283 = v234;
  memcpy((void *)v232, v132, v234);
  v133 = (char *)v132 + v283;
  v234 = (int)"L.RData";
  v233 = *(_DWORD *)(v6 + 596);
  v232 = *(_DWORD *)(v6 + 688);
  v134 = mem_mng.AllocatedNamedBuffer( v232, v233, "L.RData");
  v135 = *(_DWORD *)(v6 + 596);
  *(_DWORD *)(v6 + 688) = v134;
  v283 = v135;
  memcpy((void *)v134, v133, v135);
  v131 = (char *)v133 + v283;
  v130 = 0;
  v136 = *(_DWORD *)(v6 + 648) == 0;
  v137 = *(_DWORD *)(v6 + 648) < 0;
  Src = 0;
  v283 = 0;
  if ( !(v137 | v136) )
  {
    do
    {
      *(_DWORD *)(*(_DWORD *)(v6 + 652) + v130 + 8) = (char *)Src + *(_DWORD *)(v6 + 688);
      v282 = v130 + *(_DWORD *)(v6 + 652);
      v138 = *(_DWORD *)(v6 + 688);
      Src = (char *)Src + 2 * *(_WORD *)(v282 + 4);
      *(_DWORD *)(v282 + 16) = (char *)Src + v138;
      v139 = v130 + *(_DWORD *)(v6 + 652);
      v282 = v139;
      v140 = (char *)Src + 2 * *(_WORD *)(v139 + 12);
      v141 = (int)((char *)v140 + *(_DWORD *)(v6 + 688));
      Src = v140;
      *(_DWORD *)(v282 + 24) = v141;
      v142 = v130 + *(_DWORD *)(v6 + 652);
      v282 = v142;
      v143 = (char *)Src + 2 * *(_WORD *)(v142 + 20);
      v144 = (int)((char *)v143 + *(_DWORD *)(v6 + 688));
      Src = v143;
      *(_DWORD *)(v282 + 32) = v144;
      v282 = v130 + *(_DWORD *)(v6 + 652);
      v145 = *(_DWORD *)(v6 + 688);
      Src = (char *)Src + 2 * *(_WORD *)(v282 + 28);
      *(_DWORD *)(v282 + 40) = (char *)Src + v145;
      v282 = v130 + *(_DWORD *)(v6 + 652);
      v146 = *(_DWORD *)(v6 + 688);
      Src = (char *)Src + 2 * *(_WORD *)(v282 + 36);
      *(_DWORD *)(v282 + 48) = (char *)Src + v146;
      v282 = v130 + *(_DWORD *)(v6 + 652);
      v147 = *(_DWORD *)(v6 + 688);
      Src = (char *)Src + 2 * *(_WORD *)(v282 + 44);
      *(_DWORD *)(v282 + 64) = (char *)Src + v147;
      v282 = v130 + *(_DWORD *)(v6 + 652);
      v148 = *(_DWORD *)(v6 + 688);
      Src = (char *)Src + 2 * *(_WORD *)(v282 + 60);
      *(_DWORD *)(v282 + 72) = (char *)Src + v148;
      v149 = v130 + *(_DWORD *)(v6 + 652);
      v130 += 116;
      v282 = v149;
      v150 = *(_DWORD *)(v6 + 688);
      Src = (char *)Src + 2 * *(_WORD *)(v149 + 68);
      ++v283;
      *(_DWORD *)(v149 + 80) = (char *)Src + v150;
      Src = (char *)Src + 2 * *(_WORD *)(*(_DWORD *)(v6 + 652) + v130 - 40);
    }
    while ( v283 < *(_DWORD *)(v6 + 648) );
  }
  v234 = (int)"L.RLData";
  v233 = *(_DWORD *)(v6 + 600);
  v232 = *(_DWORD *)(v6 + 696);
  v152 = mem_mng.AllocatedNamedBuffer( v232, v233, "L.RLData");
  v153 = *(_DWORD *)(v6 + 600);
  *(_DWORD *)(v6 + 696) = v152;
  v283 = v153;
  memcpy((void *)v152, v131, v153);
  v151 = (char *)v131 + v283;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v154 = *(_DWORD *)(v6 + 648) == 0;
  v155 = *(_DWORD *)(v6 + 648) < 0;
  Src = 0;
  v283 = 0;
  if ( !(v155 | v154) )
  {
    v156 = *(_DWORD *)(v6 + 652);
    v157 = 0;
    for ( File = 0; ; v157 = File )
    {
      v158 = *(_DWORD *)(v6 + 696);
      File = (FILE *)((char *)File + 116);
      ++v283;
      *(int *)((char *)&v157[2]._bufsiz + v156) = (int)((char *)Src + v158);
      v156 = *(_DWORD *)(v6 + 652);
      Src = (char *)Src + 2 * *(_WORD *)((char *)&v157[2]._charbuf + v156);
      if ( v283 >= *(_DWORD *)(v6 + 648) )
        break;
    }
  }
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  memcpy((void *)(v6 + 664), v151, 4u);
  v160 = (char *)v151 + 4;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  memcpy(&uNumLevelDecorations, v160, 4u);
  v160 = (char *)v160 + 4;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v283 = 32 * uNumLevelDecorations;
  memcpy(word_6836D0, v160, 32 * uNumLevelDecorations);
  v159 = (char *)v160 + v283;
  v283 = 0;
  if ( (signed int)uNumLevelDecorations > 0 )
  {
    File = (FILE *)word_6836D0;
    do
    {
      memcpy(&Str1, v159, 0x20u);
      v159 = (char *)v159 + 32;
      v161 = sub_4488B6(pDecorationDescriptionList, &Str1);
      v162 = File;
      ++v283;
      ++File;
      LOWORD(v162->_ptr) = v161;
    }
    while ( v283 < (signed int)uNumLevelDecorations );
  }
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  memcpy((void *)(v6 + 656), v159, 4u);
  v163 = (char *)v159 + 4;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v234 = 16 * *(_DWORD *)(v6 + 656);
  v233 = (int)v163;
  v232 = *(_DWORD *)(v6 + 660);
  v283 = v234;
  memcpy((void *)v232, v163, v234);
  v164 = (char *)v163 + v283;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  memcpy((void *)(v6 + 672), v164, 4u);
  v164 = (char *)v164 + 4;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v234 = 8 * *(_DWORD *)(v6 + 672);
  v233 = (int)v164;
  v232 = *(_DWORD *)(v6 + 676);
  v283 = v234;
  memcpy((void *)v232, v164, v234);
  v165 = (char *)v164 + v283;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  memcpy((void *)(v6 + 700), v165, 4u);
  v165 = (char *)v165 + 4;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v166 = *(_DWORD *)(v6 + 700);
  v234 = (int)"Spawn";
  v233 = 24 * v166;
  v232 = *(_DWORD *)(v6 + 704);
  v167 = mem_mng.AllocatedNamedBuffer( v232, 24 * v166, "Spawn");
  v168 = *(_DWORD *)(v6 + 700);
  *(_DWORD *)(v6 + 704) = v167;
  v283 = 24 * v168;
  memcpy((void *)v167, v165, 24 * v168);
  v169 = (int)((char *)v165 + v283);
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v234 = 4;
  v233 = v169;
  v232 = *(_DWORD *)(v6 + 680);
  memcpy((void *)v232, (const void *)v169, 4u);
  v170 = *(_DWORD *)(v6 + 680);
  v231 = 12 * *(_DWORD *)v170;
  v171 = (int)memcpy((void *)(v170 + 4), (const void *)(v169 + 4), v231);
  free(v171, v278);
  v234 = (int)".dlv";
  v172 = strlen(Args);
  strcpy(&v270[v172], (const char *)v234);
  v283 = LODFile_FindContainer(unk_6A0820, Args, 1);
  locked_fread(&v271, 0x10u, 1u, (FILE *)v283);
  v282 = 0;
  if ( v271 != 91969 || v272 != 109 || v273 != 118 || v274 != 105 || v275 != 105 )
  {
    v234 = 1090;
    v233 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Polydata.cpp";
    v278 = (unsigned int)&v229;
    Game_sub_40E2C8(&v229, "Can't load file!", (int)((char *)&v280 + 3));
    sub_466D09(&v278, *(int *)&v229, v230, v231, v232, (const char *)v233, v234);
    v282 = 1;
  }
  v173 = v276;
  Count = Size;
  Src = 0;
  File = 0;
  if ( !v282 )
  {
    Src = malloc(Size);
    File = (FILE *)Src;
    if ( v173 <= Count )
    {
      if ( v173 == Count )
      {
        locked_fread(Src, 1u, Count, (FILE *)v283);
      }
      else
      {
        HIDWORD(v280) = malloc(v173);
        locked_fread(HIDWORD(v280), v173, 1u, (FILE *)v283);
        v174 = MemUnzip((int)Src, (int *)&Count, SHIDWORD(v280), v173);
        free(v174, HIDWORD(v280));
      }
    }
    else
    {
      v234 = 1108;
      v233 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Polydata.cpp";
      v278 = (unsigned int)&v229;
      Game_sub_40E2C8(&v229, "Can't load file!", (int)((char *)&v280 + 3));
      sub_466D09(&v278, *(int *)&v229, v230, v231, v232, (const char *)v233, v234);
    }
    memcpy((void *)(v6 + 708), Src, 0x28u);
    Src = (char *)Src + 40;
  }
  v175 = *(_DWORD *)(v6 + 724);
  if ( v175 )
  {
    v176 = *(_DWORD *)(v6 + 728);
    if ( v176 )
    {
      if ( v175 != dword_6BE640 || v176 != uNumLevelDecorations )
        v282 = 1;
    }
  }
  if ( BYTE1(dword_6BE364) & 0x20 )
    i = 29030400;
  HIDWORD(v280) = 0;
  if ( a3 - *(_DWORD *)(v6 + 712) >= (unsigned int)i )
  {
    if ( _strcmpi(::Str1, "d29.dlv") )
      HIDWORD(v280) = 1;
  }
  v177 = 875;
  if ( v282 )
  {
    v178 = (int)memset(&v235, 0, 0x36Bu);
    goto LABEL_132;
  }
  if ( HIDWORD(v280) || !*(_DWORD *)(v6 + 712) )
  {
    v178 = (int)memcpy(&v235, Src, 0x36Bu);
LABEL_132:
    free(v178, (unsigned int)File);
    v179 = v282 == 1;
    *(_DWORD *)(v6 + 712) = a3;
    if ( v179 )
      ++*(_DWORD *)(v6 + 708);
    v234 = 0;
    v233 = (int)Args;
    *(_DWORD *)a5 = 1;
    v283 = LODFile_FindContainer(unk_6A0A60, (const char *)v233, v234);
    locked_fread(&v271, 0x10u, 1u, (FILE *)v283);
    v180 = v276;
    Count = Size;
    Src = malloc(Size);
    File = (FILE *)Src;
    if ( v180 <= Count )
    {
      if ( v180 == Count )
      {
        locked_fread(Src, 1u, Count, (FILE *)v283);
      }
      else
      {
        HIDWORD(v280) = malloc(v180);
        locked_fread(HIDWORD(v280), v180, 1u, (FILE *)v283);
        v181 = MemUnzip((int)Src, (int *)&Count, SHIDWORD(v280), v180);
        free(v181, HIDWORD(v280));
      }
    }
    else
    {
      v234 = 1195;
      v233 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Polydata.cpp";
      i = (int)&v229;
      Game_sub_40E2C8(&v229, "Can't load file!", (int)((char *)&i + 3));
      sub_466D09(&a3, *(int *)&v229, v230, v231, v232, (const char *)v233, v234);
    }
    Src = (char *)Src + 40;
    v177 = 875;
    goto LABEL_140;
  }
  *(_DWORD *)a5 = 0;
LABEL_140:
  v234 = (int)".blv";
  v182 = strlen(Args);
  strcpy(&v270[v182], (const char *)v234);
  memcpy((void *)(v6 + 804), Src, v177);
  Src = (char *)Src + v177;
  if ( *(_DWORD *)a5 )
    memcpy((void *)(v6 + 804), &v235, v177);
  v183 = 0;
  if ( *(_DWORD *)dword_6BE670 > 0 )
  {
    v295 = 0;
    do
    {
      if ( (unsigned __int8)(1 << (7 - v183 % 8)) & *(_BYTE *)(v183 / 8 + v6 + 804) )
        *(_BYTE *)(*(_DWORD *)(v6 + 680) + v295 + 14) |= 1u;
      v295 += 12;
      ++v183;
    }
    while ( v183 < *(_DWORD *)dword_6BE670 );
  }
  v283 = 0;
  if ( *(_DWORD *)(v6 + 632) > 0 )
  {
    v184 = 0;
    do
    {
      v232 = v184 + *(_DWORD *)(v6 + 636) + 44;
      memcpy((void *)v232, Src, 4u);
      v186 = *(_DWORD *)(v6 + 636);
      v187 = *(_DWORD *)(v6 + 644);
      Src = (char *)Src + 4;
      v185 = v187 + 36 * *(_WORD *)(v184 + v186 + 72);
      if ( *(_WORD *)(v185 + 26) )
      {
        if ( sub_44C23B(v185) )
          *(_BYTE *)(v184 + *(_DWORD *)(v6 + 636) + 46) |= 0x10u;
        else
          *(_BYTE *)(v184 + *(_DWORD *)(v6 + 636) + 46) &= 0xEFu;
      }
      ++v283;
      v184 += 96;
    }
    while ( v283 < *(_DWORD *)(v6 + 632) );
  }
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
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
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  memcpy(&uNumActors, Src, 4u);
  Src = (char *)Src + 4;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v189 = 836 * uNumActors;
  memcpy(pActors, Src, 836 * uNumActors);
  Src = (char *)Src + v189;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  memcpy(&::Count, Src, 4u);
  Src = (char *)Src + 4;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v190 = 112 * ::Count;
  memcpy(pLayingItemsList, Src, 112 * ::Count);
  Src = (char *)Src + v190;
  if ( (signed int)::Count > 0 )
  {
    v191 = pObjectDescriptionList->uNumObjects;
    v192 = &unk_665254;
    i = ::Count;
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
          a5 = pObjectDescriptionList->pDescriptions + 32;
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
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  memcpy(&dword_5FF140, Src, 4u);
  Src = (char *)Src + 4;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v197 = 5324 * dword_5FF140;
  memcpy(array_5E5150, Src, 5324 * dword_5FF140);
  Src = (char *)Src + v197;
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v234 = 16000;
  v233 = (int)Src;
  v232 = *(_DWORD *)(v6 + 668);
  memcpy((void *)v232, Src, 0x3E80u);
  Src = (char *)Src + 16000;
  v234 = (int)"L.DData";
  v233 = *(_DWORD *)(v6 + 604);
  v232 = *(_DWORD *)(v6 + 692);
  v198 = mem_mng.AllocatedNamedBuffer( v232, v233, "L.DData");
  v199 = *(_DWORD *)(v6 + 604);
  *(_DWORD *)(v6 + 692) = v198;
  memcpy((void *)v198, Src, v199);
  Src = (char *)Src + v199;
  v196 = 0;
  v200 = *(_DWORD *)(v6 + 664) == 0;
  v201 = *(_DWORD *)(v6 + 664) < 0;
  v283 = 0;
  if ( !(v201 | v200) )
  {
    v203 = *(_DWORD *)(v6 + 668);
    v202 = 0;
    while ( 1 )
    {
      *(_DWORD *)(v203 + v202 + 36) = v196 + *(_DWORD *)(v6 + 692);
      v204 = v202 + *(_DWORD *)(v6 + 668);
      v205 = v196 + 2 * *(_WORD *)(v204 + 68);
      *(_DWORD *)(v204 + 40) = v205 + *(_DWORD *)(v6 + 692);
      v206 = v202 + *(_DWORD *)(v6 + 668);
      v207 = v205 + 2 * *(_WORD *)(v206 + 70);
      *(_DWORD *)(v206 + 44) = v207 + *(_DWORD *)(v6 + 692);
      v208 = v202 + *(_DWORD *)(v6 + 668);
      v209 = v207 + 2 * *(_WORD *)(v208 + 72);
      *(_DWORD *)(v208 + 48) = v209 + *(_DWORD *)(v6 + 692);
      v210 = v202 + *(_DWORD *)(v6 + 668);
      v211 = v209 + 2 * *(_WORD *)(v210 + 70);
      *(_DWORD *)(v210 + 52) = v211 + *(_DWORD *)(v6 + 692);
      v212 = v202 + *(_DWORD *)(v6 + 668);
      v213 = v211 + 2 * *(_WORD *)(v212 + 70);
      *(_DWORD *)(v212 + 56) = v213 + *(_DWORD *)(v6 + 692);
      v214 = v202 + *(_DWORD *)(v6 + 668);
      v215 = v213 + 2 * *(_WORD *)(v214 + 74);
      *(_DWORD *)(v214 + 60) = v215 + *(_DWORD *)(v6 + 692);
      v216 = v202 + *(_DWORD *)(v6 + 668);
      v202 += 80;
      v217 = v215 + 2 * *(_WORD *)(v216 + 74);
      v218 = v217 + *(_DWORD *)(v6 + 692);
      ++v283;
      *(_DWORD *)(v216 + 64) = v218;
      v203 = *(_DWORD *)(v6 + 668);
      v298 = v217 + 2 * *(_WORD *)(v203 + v202 - 6);
      if ( v283 >= *(_DWORD *)(v6 + 664) )
        break;
      v196 = v298;
    }
  }
  v219 = 0;
  v220 = *(_DWORD *)(v6 + 664) == 0;
  v221 = *(_DWORD *)(v6 + 664) < 0;
  v283 = 0;
  if ( !(v221 | v220) )
  {
    v222 = *(_DWORD *)(v6 + 668);
    a5 = 0;
    do
    {
      v299 = 0;
      for ( l = v222 + v219; v299 < *(_WORD *)(v222 + v219 + 70); l = v222 + v219 )
      {
        v224 = 2 * v299;
        v225 = 96 * *(_WORD *)(*(_DWORD *)(l + 40) + 2 * v299++);
        v226 = *(_DWORD *)(v6 + 644) + 36 * *(_WORD *)(v225 + *(_DWORD *)(v6 + 636) + 72);
        *(_WORD *)(v224 + *(_DWORD *)(l + 48)) = *(_WORD *)(v226 + 20);
        v219 = a5;
        *(_WORD *)(v224 + *(_DWORD *)(a5 + *(_DWORD *)(v6 + 668) + 52)) = *(_WORD *)(v226 + 22);
        v222 = *(_DWORD *)(v6 + 668);
      }
      ++v283;
      v219 += 80;
      a5 = v219;
    }
    while ( v283 < *(_DWORD *)(v6 + 664) );
  }
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v227 = Src;
  memcpy(byte_5E4C90, Src, 0xC8u);
  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
  v228 = (int)memcpy((void *)(v6 + 748), (char *)v227 + 200, 0x38u);
  free(v228, (unsigned int)File);
  v5 = 0;
LABEL_179:
  sub_4A9A67(pSoundList, 64, v5);
  sub_4A9A67(pSoundList, 103, v5);
  sub_4A9A67(pSoundList, 63, v5);
  sub_4A9A67(pSoundList, 102, v5);
  sub_4A9A67(pSoundList, 50, v5);
  sub_4A9A67(pSoundList, 89, v5);*/
  return 0;

}

//----- (0049AC17) --------------------------------------------------------
int __thiscall sub_49AC17(int _this, int a2, signed int a3, int a4)
{
  int v4; // esi@1
  unsigned __int8 v5; // zf@1
  char v6; // sf@1
  unsigned __int8 v7; // of@1
  int v8; // eax@3
  int v9; // edx@9
  int v10; // edi@9
  int v11; // eax@9
  int v12; // eax@10
  __int16 v13; // ax@12
  char v14; // al@14
  int v15; // edi@14
  int v16; // edi@14
  int v17; // eax@14
  int v18; // eax@16
  int v19; // esi@16
  signed int v20; // edx@16
  char v21; // zf@16
  int v22; // esi@17
  signed int v23; // edi@19
  int v24; // edi@20
  int v25; // edx@20
  signed int v26; // edx@21
  int v27; // ebx@23
  int v28; // edx@26
  int v29; // edx@26
  signed __int64 v30; // qtt@26
  int v31; // eax@26
  int v32; // edx@26
  signed int v33; // edi@27
  signed __int64 v34; // qtt@27
  int v35; // edx@27
  int v36; // edx@32
  unsigned __int8 v37; // sf@33
  unsigned __int8 v38; // of@33
  int v40; // edi@38
  int v41; // ebx@40
  int v42; // eax@41
  char v43; // dl@42
  int v44; // esi@42
  int v45; // edx@43
  int v46[50]; // [sp+Ch] [bp-108h]@1
  int v47; // [sp+D4h] [bp-40h]@9
  int v48; // [sp+D8h] [bp-3Ch]@14
  int v49; // [sp+DCh] [bp-38h]@14
  int v50; // [sp+E0h] [bp-34h]@19
  int v51; // [sp+E4h] [bp-30h]@9
  int v52; // [sp+E8h] [bp-2Ch]@19
  bool v53; // [sp+ECh] [bp-28h]@19
  int v54; // [sp+F0h] [bp-24h]@9
  int v55; // [sp+F4h] [bp-20h]@2
  int v56; // [sp+F8h] [bp-1Ch]@10
  int v57; // [sp+FCh] [bp-18h]@16
  int v58; // [sp+100h] [bp-14h]@1
  int v59; // [sp+104h] [bp-10h]@1
  int v60; // [sp+108h] [bp-Ch]@16
  int v61; // [sp+10Ch] [bp-8h]@20
  int v62; // [sp+110h] [bp-4h]@16

  v4 = 0;
  compile_error;//v7 = __SETO__(*(_DWORD *)(_this + 648), 1);
  v5 = *(_DWORD *)(_this + 648) == 1;
  v6 = *(_DWORD *)(_this + 648) - 1 < 0;
  v58 = 0;
  v46[0] = 0;
  v59 = 1;
  if ( (unsigned __int8)(v6 ^ v7) | v5 )
    return 0;
  v55 = 116;
  do
  {
    v8 = v55 + *(_DWORD *)(_this + 652);
    if ( *(_WORD *)(v8 + 104) <= a2 )
    {
      if ( *(_WORD *)(v8 + 106) >= a2 )
      {
        if ( *(_WORD *)(v8 + 108) <= a3 )
        {
          if ( *(_WORD *)(v8 + 110) >= a3 )
          {
            if ( *(_WORD *)(v8 + 112) - 64 <= a4 )
            {
              if ( *(_WORD *)(v8 + 114) + 64 >= a4 )
              {
                v10 = *(_WORD *)(v8 + 4);
                v11 = v10 + *(_WORD *)(v8 + 36);
                v9 = 0;
                v47 = v10;
                v54 = v11;
                v51 = 0;
                if ( v11 > 0 )
                {
                  v12 = -2 * v10;
                  v56 = -2 * v10;
                  do
                  {
                    if ( v9 < v47 )
                      v13 = *(_WORD *)(*(_DWORD *)(v55 + *(_DWORD *)(_this + 652) + 8) + 2 * v9);
                    else
                      v13 = *(_WORD *)(v12 + *(_DWORD *)(v55 + *(_DWORD *)(_this + 652) + 40));
                    v16 = v13;
                    v17 = *(_DWORD *)(_this + 636);
                    v49 = v16;
                    v16 *= 96;
                    v48 = v16;
                    v15 = v17 + v16;
                    v14 = *(_BYTE *)(v15 + 92);
                    if ( v14 == 3 || v14 == 4 )
                    {
                      v19 = *(_DWORD *)(v15 + 48);
                      v18 = *(_DWORD *)(_this + 628);
                      v20 = *(_WORD *)(v18 + 6 * *(_WORD *)v19 + 2);
                      v57 = 0;
                      v60 = 0;
                      v21 = *(_BYTE *)(v15 + 93) == 0;
                      v62 = v20 >= a3;
                      if ( !v21 )
                      {
                        v22 = v19 + 2;
                        do
                        {
                          if ( v57 >= 2 )
                            break;
                          v52 = v18 + 6 * *(_WORD *)v22;
                          v23 = *(_WORD *)(v52 + 2);
                          v50 = *(_WORD *)(v52 + 2);
                          v53 = v23 >= a3;
                          if ( v62 ^ v53 )
                          {
                            v61 = v18 + 6 * *(_WORD *)(v22 - 2);
                            v24 = *(_WORD *)v61;
                            HIWORD(v25) = HIWORD(v52);
                            LOWORD(v25) = *(_WORD *)v52;
                            v52 = v25;
                            v62 = (signed __int16)v25;
                            if ( (signed __int16)v25 >= a2 )
                              v26 = 0;
                            else
                              v26 = 2;
                            v27 = v26 | v24 < a2;
                            if ( v27 != 3 )
                            {
                              if ( !v27
                                || (*(_WORD *)v61 >= (_WORD)v52 ? (v33 = v24 - v62,
                                                                   v61 = *(_WORD *)(v61 + 2) - v50,
                                                                   LODWORD(v34) = v33 << 16,
                                                                   HIDWORD(v34) = v33 >> 16,
                                                                   v62 = v34 / v61,
                                                                   v35 = *(_DWORD *)(_this + 628),
                                                                   v61 = v34 / v61,
                                                                   v62 = a3 - *(_WORD *)(v35 + 6 * *(_WORD *)v22 + 2),
                                                                   v62 = (unsigned __int64)(v61 * v62) >> 16,
                                                                   v28 = *(_WORD *)v22) : (v29 = *(_WORD *)(v61 + 2),
                                                                                           v62 -= v24,
                                                                                           v61 = v50 - v29,
                                                                                           LODWORD(v30) = v62 << 16,
                                                                                           HIDWORD(v30) = v62 >> 16,
                                                                                           v62 = v30 / (v50 - v29),
                                                                                           v31 = v30 / (v50 - v29),
                                                                                           v32 = *(_DWORD *)(_this + 628),
                                                                                           v61 = v31,
                                                                                           v62 = a3
                                                                                               - *(_WORD *)(v32 + 6 * *(_WORD *)(v22 - 2) + 2),
                                                                                           v62 = (unsigned __int64)(v31 * v62) >> 16,
                                                                                           v28 = *(_WORD *)(v22 - 2)),
                                    v18 = *(_DWORD *)(_this + 628),
                                    v62 + *(_WORD *)(v18 + 6 * v28) > a2) )
                                ++v57;
                            }
                          }
                          ++v60;
                          v62 = v53;
                          v22 += 2;
                        }
                        while ( v60 < *(_BYTE *)(v48 + *(_DWORD *)(_this + 636) + 93) );
                        if ( v57 == 1 )
                        {
                          v36 = v58++;
                          v46[v36] = v49;
                        }
                      }
                    }
                    v9 = v51 + 1;
                    v12 = v56 + 2;
                    compile_error;//v38 = __SETO__(v51 + 1, v54);
                    v37 = v51++ + 1 - v54 < 0;
                    v56 += 2;
                  }
                  while ( v37 ^ v38 );
                  v4 = v46[0];
                }
              }
            }
          }
        }
      }
    }
    ++v59;
    v55 += 116;
  }
  while ( v59 < *(_DWORD *)(_this + 648) );
  if ( v58 == 1 )
    return *(_WORD *)(*(_DWORD *)(_this + 636) + 96 * v4 + 76);
  v40 = 0;
  if ( !v58 )
    return 0;
  v41 = 0;
  v56 = 16777215;
  if ( v58 > 0 )
  {
    v42 = a3;
    while ( 1 )
    {
      v44 = *(_DWORD *)(_this + 636) + 96 * v46[v40];
      v43 = *(_BYTE *)(v44 + 92);
      if ( v43 == 3 )
        break;
      if ( v43 == 4 )
      {
        v54 = *(_DWORD *)(v44 + 32);
        v60 = (unsigned __int64)(v54 * (a2 << 16)) >> 16;
        v59 = a3 << 16;
        v54 = *(_DWORD *)(v44 + 36);
        v59 = (unsigned __int64)(v54 * (a3 << 16)) >> 16;
        v45 = (v59 + *(_DWORD *)(v44 + 40) + v60 + 32768) >> 16;
        goto LABEL_46;
      }
LABEL_47:
      if ( v42 >= 0 )
      {
        if ( v42 < v56 )
        {
          v41 = *(_WORD *)(v44 + 76);
          v56 = v42;
        }
      }
      ++v40;
      if ( v40 >= v58 )
        return v41;
    }
    v45 = *(_WORD *)(*(_DWORD *)(_this + 628) + 6 * **(_WORD **)(v44 + 48) + 4);
LABEL_46:
    v42 = a4 - v45;
    goto LABEL_47;
  }
  return v41;
}

//----- (0049B001) --------------------------------------------------------
void *__thiscall sub_49B001(void *_this)
{
  void *result; // eax@1

  result = _this;
  *(_DWORD *)_this = 5081252;
  return result;
}

//----- (0049B02E) --------------------------------------------------------
int __fastcall sub_49B02E(int a1, int a2, int a3)
{
  int result; // eax@1

  result = a3;
  *(float *)a3 = -(*(float *)(a1 + 8) * *(float *)(a2 + 8)
                 + *(float *)(a1 + 4) * *(float *)(a2 + 4)
                 + *(float *)a1 * *(float *)a2);
  return result;
}

//----- (0049B04D) --------------------------------------------------------
signed int __thiscall sub_49B04D(void *_this, int a2, int a3)
{
  signed int v3; // eax@1
  void *v4; // edi@1
  signed int result; // eax@9
  signed int v6; // [sp-8h] [bp-18h]@8
  struct
  {
   float v7; // [sp+4h] [bp-Ch]@1
   float v8; // [sp+8h] [bp-8h]@1
   float v9; // [sp+Ch] [bp-4h]@1
  } local_04;

  local_04.v7 = 0.0;
  local_04.v8 = 0.0;
  local_04.v9 = 0.0;
  v4 = _this;
  sub_49B13D(a2, a3, (int)&local_04, (int)&a3);
  v3 = 2;
  if ( *(_DWORD *)(a2 + 8) )
  {
    if ( !*(_DWORD *)a2 )
    {
      if ( !*(_DWORD *)(a2 + 4) )
        v3 = 1;
    }
  }
  else
  {
    v3 = 0;
  }
  if ( v3 )
  {
    if ( v3 == 1 )
      v6 = 3;
    else
      v6 = 4;
    result = v6;
  }
  else
  {
    result = 1;
  }
  *((float *)v4 + 1) = local_04.v7;
  *((float *)v4 + 2) = local_04.v8;
  *((float *)v4 + 3) = local_04.v9;
  *((float *)v4 + 4) = *(float *)&a3;
  *((_BYTE *)v4 + 20) = result;
  return result;
}

//----- (0049B0C9) --------------------------------------------------------
signed int __thiscall sub_49B0C9(int _this, int a2, int a3)
{
  signed int v3; // esi@1
  signed int result; // eax@9
  double v5; // st7@12
  double v6; // st6@12
  double v7; // st5@12
  signed int v8; // [sp+0h] [bp-4h]@8

  v3 = 2;
  if ( *(float *)(a2 + 8) == 0.0 )
  {
    v3 = 0;
  }
  else
  {
    if ( *(float *)a2 == 0.0 )
    {
      if ( *(float *)(a2 + 4) == 0.0 )
        v3 = 1;
    }
  }
  if ( v3 )
  {
    if ( v3 == 1 )
      v8 = 3;
    else
      v8 = 4;
    result = v8;
  }
  else
  {
    result = 1;
  }
  v5 = *(float *)(a2 + 8);
  v6 = *(float *)(a2 + 4);
  v7 = *(float *)a2;
  *(_BYTE *)(_this + 20) = result;
  *(float *)(_this + 4) = v7;
  *(_DWORD *)(_this + 16) = a3;
  *(float *)(_this + 8) = v6;
  *(float *)(_this + 12) = v5;
  return result;
}

//----- (0049B13D) --------------------------------------------------------
int __stdcall sub_49B13D(int a1, int a2, int a3, int a4)
{
  int v4; // ebx@1
  int v5; // eax@1
  int v6; // ebx@2
  int v7; // eax@3
  int v8; // ecx@3
  double v9; // st7@3
  int v10; // ecx@3
  int v11; // ecx@3
  double v12; // st7@3
  double v13; // st6@3
  double v14; // st5@3
  int v15; // ecx@3
  int v16; // eax@3
  double v17; // st5@3
  int v18; // eax@3
  int result; // eax@8
  float v20; // ecx@10
  double v21; // st7@10
  double v22; // st6@10
  struct
  {
   float v23; // [sp+4h] [bp-64h]@3
   float v24; // [sp+18h] [bp-50h]@3
   float v25; // [sp+1Ch] [bp-4Ch]@3
  } local_04;
  float v26; // [sp+20h] [bp-48h]@3
  float v27; // [sp+24h] [bp-44h]@3
  float v28; // [sp+2Ch] [bp-3Ch]@3
  float v29; // [sp+30h] [bp-38h]@3
  float v30; // [sp+34h] [bp-34h]@3
  float v31; // [sp+38h] [bp-30h]@3
  float v32; // [sp+3Ch] [bp-2Ch]@3
  float v33; // [sp+40h] [bp-28h]@1
  float v34; // [sp+44h] [bp-24h]@1
  float v35; // [sp+48h] [bp-20h]@1
  float v36; // [sp+4Ch] [bp-1Ch]@3
  float v37; // [sp+50h] [bp-18h]@3
  float v38; // [sp+54h] [bp-14h]@3
  struct
  {
   float v39; // [sp+58h] [bp-10h]@3
   float v40; // [sp+5Ch] [bp-Ch]@3
   float v41; // [sp+60h] [bp-8h]@3
  } local_58;
  int v42; // [sp+64h] [bp-4h]@1

  v42 = 0;
  v33 = 0.0;
  v4 = a1;
  v5 = *(_BYTE *)(a1 + 302);
  v34 = 0.0;
  v35 = 0.0;
  if ( v5 - 1 <= 0 )
  {
LABEL_8:
    *(float *)a3 = (double)(*(_DWORD *)v4 & 0xFFFF) * 0.00001525902189314365 + (double)(signed int)(*(_DWORD *)v4 >> 16);
    *(float *)(a3 + 4) = (double)(*(_DWORD *)(v4 + 4) & 0xFFFF) * 0.00001525902189314365
                       + (double)(signed int)(*(_DWORD *)(v4 + 4) >> 16);
    *(float *)(a3 + 8) = (double)(*(_DWORD *)(v4 + 8) & 0xFFFF) * 0.00001525902189314365
                       + (double)(signed int)(*(_DWORD *)(v4 + 8) >> 16);
    result = a4;
    *(float *)a4 = (double)(*(_DWORD *)(v4 + 12) & 0xFFFF) * 0.00001525902189314365
                 + (double)(signed int)(*(_DWORD *)(v4 + 12) >> 16);
  }
  else
  {
    v6 = a1 + 34;
    while ( 1 )
    {
      v7 = *(_DWORD *)(a2 + 4);
      v8 = v7 + 12 * *(_WORD *)(v6 - 2);
      v36 = (double)*(signed int *)v8;
      v37 = (double)*(signed int *)(v8 + 4);
      v9 = (double)*(signed int *)(v8 + 8);
      v10 = *(_WORD *)v6;
      v38 = v9;
      v11 = v7 + 12 * v10;
      v12 = (double)*(signed int *)v11;
      v13 = (double)*(signed int *)(v11 + 4);
      v14 = (double)*(signed int *)(v11 + 8);
      v15 = *(_WORD *)(v6 + 2);
      local_04.v24 = v14;
      v16 = v7 + 12 * v15;
      v17 = (double)*(signed int *)v16;
      v28 = (double)*(signed int *)(v16 + 4);
      v29 = (double)*(signed int *)(v16 + 8);
      v30 = v12 - v36;
      v31 = v13 - v37;
      v32 = local_04.v24 - v38;
      v33 = v30;
      local_04.v25 = v17 - v12;
      v34 = v31;
      v26 = v28 - v13;
      v35 = v32;
      v27 = v29 - local_04.v24;
      v18 = sub_49B32D((int)&v33, (int)&local_04, local_04.v25, v26, v27);
      LODWORD(local_58.v39) = *(_DWORD *)v18;
      LODWORD(local_58.v40) = *(_DWORD *)(v18 + 4);
      LODWORD(local_58.v41) = *(_DWORD *)(v18 + 8);
      if (local_58.v39 != 0.0 || local_58.v40 != 0.0 || local_58.v41 != 0.0 )
        break;
      ++v42;
      v6 += 2;
      if ( v42 >= *(_BYTE *)(a1 + 302) - 1 )
      {
        v4 = a1;
        goto LABEL_8;
      }
    }
    sub_4369DB((int)&local_58);
    v20 = local_58.v40;
    *(float *)a3 = local_58.v39;
    v21 = v38 * local_58.v41;
    v22 = v37 * local_58.v40;
    *(_DWORD *)(a3 + 4) = LODWORD(v20);
    *(_DWORD *)(a3 + 8) = LODWORD(local_58.v41);
    result = a4;
    *(float *)a4 = -(v21 + v22 + v36 * local_58.v39);
  }
  return result;
}

//----- (0049B32D) --------------------------------------------------------
int __thiscall sub_49B32D(int _this, int a2, float a3, float a4, float a5)
{
  int result; // eax@1
  double v6; // st7@1
  double v7; // st6@1

  result = a2;
  v6 = a3 * *(float *)(_this + 8) - a5 * *(float *)_this;
  v7 = a4 * *(float *)_this - a3 * *(float *)(_this + 4);
  *(float *)a2 = a5 * *(float *)(_this + 4) - a4 * *(float *)(_this + 8);
  *(float *)(a2 + 4) = v6;
  *(float *)(a2 + 8) = v7;
  return result;
}

//----- (0049B3B8) --------------------------------------------------------
int __fastcall sub_49B3B8(int a1)
{
  size_t v2; // eax@1

  byte_AE5B94 = BYTE3(a1);
  CGame_stru0_sub_40E2F6((CGame_stru0 *)&byte_AE5B94, 0);
  v2 = strlen("hwsplat04");
  return sub_40E32E((int)&byte_AE5B94, "hwsplat04", v2);
}

//----- (0049B3EB) --------------------------------------------------------
void __cdecl sub_49B3EB()
{
  if ( !(byte_AE5B91 & 1) )
  {
    byte_AE5B91 |= 1u;
    CGame_stru0_sub_40E2F6((CGame_stru0 *)&byte_AE5B94, 1);
  }
}

//----- (0049B408) --------------------------------------------------------
void *__thiscall sub_49B408(void *_this)
{
  int v1; // eax@1
  signed int v2; // ecx@1
  void *v3; // esi@1

  v3 = _this;
  _eh_vector_constructor_iterator_((int)_this + 4, 3104, 1024, sub_43B60C, sub_43B641);
  *((_DWORD *)v3 + 794625) = 0;
  *((_DWORD *)v3 + 794626) = 0;
  v1 = (int)((char *)v3 + 3178552);
  v2 = 256;
  do
  {
    *(float *)v1 = 0.0;
    v1 += 48;
    --v2;
  }
  while ( v2 );
  *(_DWORD *)v3 = 5081264;
  return v3;
}

//----- (0049B471) --------------------------------------------------------
void __fastcall sub_49B471(void *_this)
{
  *(_DWORD *)_this = 5081264;
  _eh_vector_destructor_iterator_((int)_this + 4, 3104, 1024, sub_43B641);
}

//----- (0049B490) --------------------------------------------------------
char __stdcall sub_49B490(int a1, int a2, int a3, float a4, float a5, float a6, int a7, int a8, int a9)
{
  double v10; // ST1C_8@1
  char v11; // ST24_1@1
  double v12; // ST1C_8@1
  double v13; // ST1C_8@1
  int v14; // [sp+40h] [bp+18h]@1
  float v15; // [sp+44h] [bp+1Ch]@1
  float v16; // [sp+44h] [bp+1Ch]@1
  float v17; // [sp+44h] [bp+1Ch]@1

  v15 = a6 * 255.0;
  v10 = v15 + 6.755399441055744e15;
  v11 = LOBYTE(v10);
  v16 = a5 * 255.0;
  v12 = v16 + 6.755399441055744e15;
  v14 = LODWORD(v12);
  v17 = a4 * 255.0;
  v13 = v17 + 6.755399441055744e15;
  return class36_sub_43B6EF(&class36_global0, a1, a2, a3, a7, SLOBYTE(v13), v14, v11);
}

//----- (0049B540) --------------------------------------------------------
char __thiscall sub_49B540(void *_this, signed int a2, char a3, int a4, signed int a5, int a6, int a7, float a8, int a9)
{
  _UNKNOWN *v9; // eax@3
  signed int v10; // ecx@3
  _UNKNOWN *v11; // eax@10
  int v12; // edx@10
  const void *v13; // esi@11
  void *v14; // edi@11
  char v15; // zf@11
  int v16; // esi@12
  double v18; // st7@17
  double v19; // st6@17
  int v20; // eax@17
  int v21; // esi@21
  int v22; // esi@21
  int v23; // eax@21
  int v24; // ecx@21
  double v25; // st7@21
  int v26; // ebx@21
  double v27; // st7@21
  int v28; // edi@21
  double v29; // st7@21
  int v30; // ST10_4@21
  int v31; // ST08_4@21
  char v32; // [sp+4h] [bp-44h]@18
  int v33; // [sp+8h] [bp-40h]@18
  int v34; // [sp+Ch] [bp-3Ch]@18
  int v35; // [sp+10h] [bp-38h]@18
  int v36; // [sp+14h] [bp-34h]@17
  int v37; // [sp+18h] [bp-30h]@17
  int v38; // [sp+28h] [bp-20h]@21
  int v39; // [sp+2Ch] [bp-1Ch]@21
  int v40; // [sp+30h] [bp-18h]@21
  int v41; // [sp+34h] [bp-14h]@22
  int v42; // [sp+38h] [bp-10h]@21
  int v43; // [sp+3Ch] [bp-Ch]@21
  int v44; // [sp+40h] [bp-8h]@1
  int v45; // [sp+44h] [bp-4h]@8
  char *v46; // [sp+58h] [bp+10h]@18

  v44 = (int)_this;
  if ( !a5 )
    return 0;
  if ( !(byte_AE5B90 & 1) )
  {
    byte_AE5B90 |= 1u;
    v9 = &unk_AE4FBC;
    v10 = 64;
    do
    {
      *(float *)v9 = 0.0;
      v9 = (char *)v9 + 48;
      --v10;
    }
    while ( v10 );
    atexit(0);
  }
  if ( !(byte_AE5B90 & 2) )
  {
    byte_AE5B90 |= 2;
    sub_489B60((int)&unk_AE4F60);
    compile_error;//atexit(loc_49B785);
  }
  v45 = a6;
  if ( a7 )
  {
    if ( a5 > 0 )
    {
      v11 = &unk_AE4F90;
      v12 = a6 - (_DWORD)&unk_AE4F90;
      a6 = a5;
      do
      {
        v13 = (char *)v11 + v12;
        v14 = v11;
        v11 = (char *)v11 + 48;
        v15 = a6-- == 1;
        memcpy(v14, v13, 0x30u);
      }
      while ( !v15 );
    }
    v16 = a4;
    if ( sub_437376(a4, &unk_AE4F90, &a5) == 1 )
    {
      if ( !a5 )
        return 0;
      v45 = (int)&unk_AE4F90;
    }
  }
  else
  {
    v16 = a4;
  }
  v18 = *(float *)(v16 + 12);
  v19 = *(float *)(v16 + 8);
  v20 = *(_DWORD *)(v16 + 4);
  v37 = (int)&unk_AE4F7C;
  flt_AE4F68 = v19;
  dword_AE4F64 = v20;
  v36 = (int)&unk_AE4F70;
  flt_AE4F6C = v18;
  dword_AE4F88 = *(_DWORD *)(v16 + 16);
  if ( !sub_436932_GetFacetOrientation(*(_BYTE *)(v16 + 20), (int)&dword_AE4F64, (int)&unk_AE4F70, (int)&unk_AE4F7C) )
  {
    v37 = 101;
    v36 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp";
    v46 = &v32;
    Game_sub_40E2C8(&v32, "Error: Failed to get the facet orientation", (int)((char *)&a4 + 3));
    sub_466D09(&a6, *(int *)&v32, v33, v34, v35, (const char *)v36, v37);
  }
  a7 = 0;
  if ( *(_DWORD *)(v44 + 3194892) > 0 )
  {
    a6 = v44 + 3190796;
    do
    {
      v22 = 40 * *(_DWORD *)a6 + 0x005107AC;

      //*(float *)&v37 = flt_5107B8[10 * *(_DWORD *)a6];
      *(float *)&v37 = class36_global0.std__vector_000004[*(_DWORD *)a6].flt_00000C;

      *(float *)&v36 = *(float *)(v22 + 8);
      *(float *)&v35 = *(float *)(v22 + 4);
      v23 = sub_43F5C8(a2, a9, *(float *)&v35, *(float *)&v36, *(float *)&v37);
      v24 = *(_BYTE *)(v22 + 26);
      v25 = *(float *)(v22 + 4);
      v42 = v23;
      BYTE3(v23) = 0;
      *(_WORD *)((char *)&v23 + 1) = *(_BYTE *)(v22 + 24);
      LOBYTE(v23) = *(_BYTE *)(v22 + 25);
      v43 = v24 | (v23 << 8);
      v26 = (signed __int64)v25;
      v27 = *(float *)(v22 + 12);
      v28 = (signed __int64)*(float *)(v22 + 8);
      v37 = LODWORD(a8);
      v40 = (signed __int64)v27;
      v29 = *(float *)(v22 + 20);
      v36 = v45;
      v38 = v26;
      v39 = v28;
      v35 = a5;
      v34 = (int)&unk_AE4F60;
      *(float *)&v33 = v29;
      *(_DWORD *)&v32 = v24 | (v23 << 8);
      *(float *)&v30 = *(float *)(v22 + 16);
      v31 = v22;
      v21 = v44;
      if ( !sub_49B790(v44, v42, a3, v31, (int)&v38, v30, v43, v33, (int)&unk_AE4F60, a5, v45, SLOBYTE(a8)) )
      {
        v37 = 114;
        v36 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp";
        v42 = (int)&v32;
        Game_sub_40E2C8(&v32, "Error: Failed to build decal geometry", (int)((char *)&a4 + 3));
        sub_466D09(&v41, *(int *)&v32, v33, v34, v35, (const char *)v36, v37);
        v41 = 5080748;
      }
      ++a7;
      a6 += 4;
    }
    while ( a7 < *(_DWORD *)(v21 + 3194892) );
  }
  return 1;
}

//----- (0049B790) --------------------------------------------------------
char __thiscall sub_49B790(int _this, int a2, char a3, int a4, int a5, int a6, int a7, int a8, int a9, signed int a10, int a11, char a12)
{
  int v12; // esi@1
  int v13; // eax@2
  int v14; // edi@2
  int v15; // eax@4
  signed int v16; // ecx@4
  int v17; // ebx@4
  double v18; // st7@4
  double v19; // st7@4
  int v20; // eax@4
  double v21; // st7@4
  double v22; // st7@4
  double v23; // st7@4
  double v24; // st6@4
  double v25; // st6@4
  double v26; // st5@4
  double v27; // st5@4
  double v28; // st7@5
  char result; // al@6
  double v30; // st7@6
  int v31; // edi@7
  int v32; // ebx@8
  void *v33; // ecx@15
  int v34; // eax@19
  const char *v35; // [sp-Ch] [bp-2Ch]@15
  int v36; // [sp-8h] [bp-28h]@15
  char v37; // [sp-4h] [bp-24h]@15
  int v38; // [sp+0h] [bp-20h]@17
  int v39; // [sp+4h] [bp-1Ch]@17
  int v40; // [sp+8h] [bp-18h]@6
  const char *v41[5]; // [sp+Ch] [bp-14h]@6

  v12 = _this;
  if ( *(float *)&a6 == 0.0 )
    goto LABEL_24;
  v14 = 3104 * *(_DWORD *)(_this + 3178504) + _this + 4;
  v13 = 3104 * *(_DWORD *)(_this + 3178504) + _this + 3104;
  *(_DWORD *)(3104 * *(_DWORD *)(_this + 3178504) + _this + 3100) = a4;
  *(_DWORD *)v13 = 0;
  if ( a3 & 2 )
    *(_DWORD *)v13 = 1;
  v18 = *(float *)&a6 - *(float *)&a8;
  *(float *)(_this + 3194920) = v18;
  v19 = sqrt((*(float *)&a6 + *(float *)&a6 - v18) * v18);
  *(float *)(v12 + 3194924) = v19;
  v20 = a5;
  v17 = a9;
  *(float *)(v12 + 3194928) = 1.0 - (*(float *)&a6 - v19) / *(float *)&a6;
  *(_WORD *)(v14 + 3080) = (signed __int64)((double)*(signed int *)v20 - *(float *)&a8 * *(float *)(v17 + 4));
  *(_WORD *)(v14 + 3082) = (signed __int64)((double)*(signed int *)(a5 + 4) - *(float *)&a8 * *(float *)(v17 + 8));
  v21 = *(float *)&a6;
  *(_WORD *)(v14 + 3084) = (signed __int64)((double)*(signed int *)(a5 + 8) - *(float *)&a8 * *(float *)(v17 + 12));
  v22 = v21 * *(float *)(v12 + 3194928);
  a8 = v14 + 8;
  *(float *)(v12 + 3194932) = v22;
  *(float *)(v12 + 3194896) = v22 * *(float *)(v17 + 16);
  *(float *)(v12 + 3194900) = v22 * *(float *)(v17 + 20);
  *(float *)(v12 + 3194904) = v22 * *(float *)(v17 + 24);
  *(float *)(v12 + 3194908) = v22 * *(float *)(v17 + 28);
  *(float *)(v12 + 3194912) = v22 * *(float *)(v17 + 32);
  *(float *)(v12 + 3194916) = v22 * *(float *)(v17 + 36);
  a6 = *(_WORD *)(v14 + 3080);
  v23 = (double)a6;
  v24 = v23 - *(float *)(v12 + 3194908);
  a6 = *(_WORD *)(v14 + 3082);
  *(float *)(v14 + 8) = v24 + *(float *)(v12 + 3194896);
  v25 = (double)a6;
  v26 = v25 - *(float *)(v12 + 3194912) + *(float *)(v12 + 3194900);
  v15 = v14 + 12;
  a6 = *(_WORD *)(v14 + 3084);
  v16 = 4;
  *(float *)(v14 + 12) = v26;
  v27 = (double)a6;
  *(float *)&a6 = v27;
  *(float *)(v14 + 16) = v27 - *(float *)(v12 + 3194916) + *(float *)(v12 + 3194904);
  *(float *)(v14 + 44) = 0.0;
  *(float *)(v14 + 48) = 0.0;
  *(float *)(v14 + 56) = v23 - *(float *)(v12 + 3194908) - *(float *)(v12 + 3194896);
  *(float *)(v14 + 60) = v25 - *(float *)(v12 + 3194912) - *(float *)(v12 + 3194900);
  *(float *)(v14 + 64) = v27 - *(float *)(v12 + 3194916) - *(float *)(v12 + 3194904);
  *(float *)(v14 + 92) = 0.0;
  *(float *)(v14 + 96) = 1.0;
  *(float *)(v14 + 104) = v23 + *(float *)(v12 + 3194908) - *(float *)(v12 + 3194896);
  *(float *)(v14 + 108) = v25 + *(float *)(v12 + 3194912) - *(float *)(v12 + 3194900);
  *(float *)(v14 + 112) = v27 + *(float *)(v12 + 3194916) - *(float *)(v12 + 3194904);
  *(float *)(v14 + 140) = 1.0;
  *(float *)(v14 + 144) = 1.0;
  *(float *)(v14 + 152) = v23 + *(float *)(v12 + 3194908) + *(float *)(v12 + 3194896);
  *(float *)(v14 + 156) = v25 + *(float *)(v12 + 3194912) + *(float *)(v12 + 3194900);
  *(float *)(v14 + 160) = *(float *)&a6 + *(float *)(v12 + 3194916) + *(float *)(v12 + 3194904);
  *(float *)(v14 + 188) = 1.0;
  *(float *)(v14 + 192) = 0.0;
  do
  {
    v28 = *(float *)(v17 + 8) * *(float *)v15
        + *(float *)(v15 - 4) * *(float *)(v17 + 4)
        + *(float *)(v15 + 4) * *(float *)(v17 + 12)
        + *(float *)(v17 + 40);
    *(float *)(v15 - 4) = *(float *)(v15 - 4) - v28 * *(float *)(v17 + 4);
    *(float *)v15 = *(float *)v15 - v28 * *(float *)(v17 + 8);
    v15 += 48;
    --v16;
    *(float *)(v15 - 44) = *(float *)(v15 - 44) - v28 * *(float *)(v17 + 12);
  }
  while ( v16 );
  *(_DWORD *)(v14 + 3088) = a7;
  v41[1] = (const char *)(v14 + 4);
  v41[0] = (const char *)(v14 + 8);
  *(_DWORD *)(v14 + 4) = 4;
  *(_DWORD *)(v14 + 3092) = a2;
  v30 = *(float *)(v17 + 12);
  a6 = v14 + 4;
  *(float *)&v40 = v30;
  result = sub_4980B9(a11, a10, *(float *)(v17 + 4), *(float *)(v17 + 8), *(float *)&v40, (int)v41[0], (int)v41[1]);
  if ( result )
  {
    v31 = a6;
    if ( !*(_DWORD *)a6 )
      goto LABEL_24;
    v32 = a8;
    sub_436523((RenderVertex *)a8, *(_DWORD *)a6);
    class08_sub_436BB7(pGame->class08_obj, (RenderVertex *)v32, *(_DWORD *)v31, 0);
    if ( !(a12 & 1) )
    {
LABEL_19:
      ++*(_DWORD *)(v12 + 3178504);
      v34 = 1024;
      if ( *(_DWORD *)(v12 + 3178504) == 1024 )
        *(_DWORD *)(v12 + 3178504) = 0;
      if ( *(_DWORD *)(v12 + 3178500) + 1 <= 1024 )
        v34 = *(_DWORD *)(v12 + 3178500) + 1;
      *(_DWORD *)(v12 + 3178500) = v34;
      goto LABEL_24;
    }
    if ( dword_6BE360 == 2 )
    {
      if ( a12 & 2 )
      {
        v41[1] = (const char *)&a8;
        v41[0] = (const char *)(v12 + 3178508);
        sub_436CDC(v32, *(_DWORD *)v31, v12 + 3178508, (int)&a8);
LABEL_14:
        sub_437143(a8, v32, v12 + 3178508, v31);
        goto LABEL_18;
      }
      if ( a12 & 4 )
      {
        v41[1] = (const char *)&a8;
        v41[0] = (const char *)(v12 + 3178508);
        sub_436F09(v32, *(_DWORD *)v31, v12 + 3178508, (int)&a8);
        goto LABEL_14;
      }
      v41[1] = (const char *)258;
      v41[0] = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp";
      v33 = &v37;
      a6 = (int)&v37;
      v36 = (int)((char *)&a6 + 3);
      v35 = "Undefined clip flag specified";
    }
    else
    {
      v41[1] = (const char *)263;
      v41[0] = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp";
      v33 = &v37;
      a6 = (int)&v37;
      v36 = (int)((char *)&a6 + 3);
      v35 = "Lightpoly builder native indoor clipping not implemented";
    }
    Game_sub_40E2C8(v33, v35, v36);
    sub_466D09(&a5, *(int *)&v37, v38, v39, v40, v41[0], (int)v41[1]);
LABEL_18:
    if ( a8 )
      goto LABEL_19;
LABEL_24:
    result = 1;
  }
  return result;
}

//----- (0049BBBD) --------------------------------------------------------
char __thiscall sub_49BBBD(int _this, int a2)
{
  int v2; // ebx@1
  int v3; // edi@1
  int v4; // eax@2
  int v5; // esi@2
  _UNKNOWN *v6; // edx@5
  double v7; // st7@12

  v3 = 0;
  *(_DWORD *)(_this + 3194892) = 0;
  v2 = class36_global0.std__vector_000004_size;
  if ( class36_global0.std__vector_000004_size )
  {
    v5 = dword_6BE644 + 96 * a2;
    v4 = *(_DWORD *)(v5 + 44);
    if ( !(v4 & 0x400000) )
    {
      if ( !(v4 & 0x10) )
      {
        if ( class36_global0.std__vector_000004_size > 0 )
        {
          v6 = (char *)&class36_global0.std__vector_000004[0].flt_000004;
          do
          {
            if ( (double)*(_WORD *)(v5 + 80) - *((float *)v6 + 2) < *((float *)v6 - 1) )
            {
              if ( (double)*(_WORD *)(v5 + 82) + *((float *)v6 + 2) > *((float *)v6 - 1) )
              {
                if ( (double)*(_WORD *)(v5 + 84) - *((float *)v6 + 2) < *(float *)v6 )
                {
                  if ( (double)*(_WORD *)(v5 + 86) + *((float *)v6 + 2) > *(float *)v6 )
                  {
                    if ( (double)*(_WORD *)(v5 + 88) - *((float *)v6 + 2) < *((float *)v6 + 1) )
                    {
                      if ( (double)*(_WORD *)(v5 + 90) + *((float *)v6 + 2) > *((float *)v6 + 1) )
                      {
                        v7 = *(float *)(v5 + 8) * *((float *)v6 + 1)
                           + *(float *)(v5 + 4) * *(float *)v6
                           + *(float *)v5 * *((float *)v6 - 1)
                           + *(float *)(v5 + 12);
                        if ( v7 <= *((float *)v6 + 2) )
                        {
                          *((float *)v6 + 3) = v7;
                          compile_error;//*(_DWORD *)(_this + 4 * *(_DWORD *)(_this + 3194892)++ + 3190796) = v3;
                        }
                      }
                    }
                  }
                }
              }
            }
            ++v3;
            v6 = (char *)v6 + 40;
          }
          while ( v3 < v2 );
        }
      }
    }
  }
  return 1;
}

//----- (0049BCEB) --------------------------------------------------------
bool __thiscall sub_49BCEB(struct class58 *_this, struct class51_stru2 *a2)
{
  double v5; // st7@12
 int i;

 _this->std__vector_30B00C_size = 0; // ::clear();
 if (~a2->byte_000010[14] & 0x40 ||
     ~a2->byte_000010[12] & 0x10)
   return true;
 
 for (i = 0; i < class36_global0.std__vector_000004_size; ++i)
 {
  if (a2->sSomeX1 - class36_global0.std__vector_000004[i].flt_00000C < class36_global0.std__vector_000004[i].flt_000000 &&
      a2->sSomeX2 + class36_global0.std__vector_000004[i].flt_00000C > class36_global0.std__vector_000004[i].flt_000000)
  {
   if (a2->sSomeY1 - class36_global0.std__vector_000004[i].flt_00000C < class36_global0.std__vector_000004[i].flt_000004 &&
       a2->sSomeY2 + class36_global0.std__vector_000004[i].flt_00000C > class36_global0.std__vector_000004[i].flt_000004)
   {
    if (a2->sSomeZ1 - class36_global0.std__vector_000004[i].flt_00000C < class36_global0.std__vector_000004[i].flt_000008 &&
        a2->sSomeZ2 + class36_global0.std__vector_000004[i].flt_00000C > class36_global0.std__vector_000004[i].flt_000008)
    {
     __int64 v0 = a2->dword_00000C +
                  a2->dword_000000 * floorf(class36_global0.std__vector_000004[i].flt_000000 + 0.5f) +
                  a2->dword_000004 * floorf(class36_global0.std__vector_000004[i].flt_000004 + 0.5f) +
                  a2->dword_000008 * floorf(class36_global0.std__vector_000004[i].flt_000008 + 0.5f);

     v5 = (double)(v0 / 65536);
     if (v5 <= class36_global0.std__vector_000004[i].flt_00000C)
     {
      class36_global0.std__vector_000004[i].flt_000010 = v5;
        _this->std__vector_30B00C[_this->std__vector_30B00C_size++] = i;  // ::push_back(i);
      }
    }
   }
  }
 }

 return true;
}

//----- (0049BE8A) --------------------------------------------------------
bool __thiscall class58_sub_49BE8A(struct class58 *_this, int a2, struct Normal *pNormal, int a4, int a5, int a6, char a7)
{
  int v7; // ebx@3
  int v8; // edi@3
  _UNKNOWN *v9; // esi@3
  int v10; // eax@5
  int v11; // eax@6
  double v12; // st7@19
  int v13; // eax@20
  int v14; // eax@22
  int v15; // edx@24
  int v16; // eax@24
  char v18; // [sp-18h] [bp-54h]@12
  int v19; // [sp-14h] [bp-50h]@12
  int v20; // [sp-10h] [bp-4Ch]@12
  int v21; // [sp-Ch] [bp-48h]@12
  const char *v22; // [sp-8h] [bp-44h]@12
  int v23; // [sp-4h] [bp-40h]@12
  double v24; // [sp+Ch] [bp-30h]@19
  int v25; // [sp+14h] [bp-28h]@1
  int v26; // [sp+18h] [bp-24h]@1
  int v27; // [sp+1Ch] [bp-20h]@19
  float v28; // [sp+20h] [bp-1Ch]@12
  int v29; // [sp+24h] [bp-18h]@12
  float v30; // [sp+28h] [bp-14h]@13
  float v31; // [sp+2Ch] [bp-10h]@7
  float v32; // [sp+30h] [bp-Ch]@6
  float v33; // [sp+34h] [bp-8h]@6
  int v34; // [sp+38h] [bp-4h]@2

  _this->std__vector_30B00C_size = 0;
  v26 = (int)_this;
  v25 = class36_global0.std__vector_000004_size;
  if ( class36_global0.std__vector_000004_size )
  {
    v34 = 0;
    if ( class36_global0.std__vector_000004_size > 0 )
    {
      v8 = a5;
      v7 = (int)pNormal;
      v9 = (char *)&class36_global0.std__vector_000004[0].flt_000004;
      do
      {
        if ( a6 == 4 )
        {
          LODWORD(pNormal) = *(_DWORD *)v8;
          v10 = *(_DWORD *)(v8 + 144);
        }
        else
        {
          if ( a6 != 3 )
          {
            LODWORD(v28) = (int)&v18;
            Game_sub_40E2C8(&v18, "Uknown strip type detected!", (int)((char *)&a5 + 3));
            sub_466D09(&v29, *(int *)&v18, v19, v20, v21, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp", __LINE__);
            v29 = 5080748;
            goto LABEL_13;
          }
          if ( a7 )
          {
            LODWORD(pNormal) = *(_DWORD *)v8;
            LODWORD(v33) = *(_DWORD *)(v8 + 96);
            LODWORD(v32) = *(_DWORD *)(v8 + 52);
            v11 = *(_DWORD *)(v8 + 100);
            goto LABEL_7;
          }
          LODWORD(pNormal) = *(_DWORD *)(v8 + 48);
          v10 = *(_DWORD *)(v8 + 96);
        }
        LODWORD(v33) = v10;
        LODWORD(v32) = *(_DWORD *)(v8 + 52);
        v11 = *(_DWORD *)(v8 + 4);
LABEL_7:
        LODWORD(v31) = v11;
LABEL_13:
        v30 = sub_436A6D(v8, a6);
        v28 = sub_436A40(v8, a6);
        if ( (int)pNormal - *((float *)v9 + 2) < *((float *)v9 - 1) )
        {
          if ( v33 + *((float *)v9 + 2) > *((float *)v9 - 1) )
          {
            if ( v32 - *((float *)v9 + 2) < *(float *)v9 )
            {
              if ( v31 + *((float *)v9 + 2) > *(float *)v9 )
              {
                if ( v30 - *((float *)v9 + 2) < *((float *)v9 + 1) )
                {
                  if ( v28 + *((float *)v9 + 2) > *((float *)v9 + 1) )
                  {
                    sub_49B02E(v8, v7, a4);
                    v28 = *(float *)(v7 + 4) * *(float *)v9
                        + *(float *)(v7 + 8) * *((float *)v9 + 1)
                        + *(float *)v7 * *((float *)v9 - 1)
                        + *(float *)a4;
                    v24 = v28 + 6.755399441055744e15;
                    v27 = LODWORD(v24);
                    v12 = (double)SLODWORD(v24);
                    v30 = v12;
                    if ( v12 <= *((float *)v9 + 2) )
                    {
                      v13 = *(_DWORD *)(a2 + 48);
                      if ( v13 & 2 || BYTE1(v13) & 1 )
                      {
                        v14 = *((_DWORD *)v9 + 5);
                        if ( !(v14 & 1) )
                        {
                          LOBYTE(v14) = v14 | 1;
                          *((_DWORD *)v9 + 5) = v14;
                          *((_QWORD *)v9 + 3) = cClock1.clock_fn2();
                        }
                      }
                      v15 = v34;
                      *((_DWORD *)v9 + 3) = LODWORD(v30);
                      v16 = v26;
                      *(_DWORD *)(v26 + 4 * *(_DWORD *)(v26 + 3194892) + 3190796) = v15;
                      ++*(_DWORD *)(v16 + 3194892);
                    }
                  }
                }
              }
            }
          }
        }
        ++v34;
        v9 = (char *)v9 + 40;
      }
      while ( v34 < v25 );
    }
  }
  return true;
}

//----- (0049C095) --------------------------------------------------------
void __stdcall sub_49C095(int a1, float a2)
{
  int v2; // edi@1
  double v3; // st7@3
  int v4; // eax@5
  double v5; // st7@5
  unsigned __int8 v6; // zf@5
  unsigned __int8 v7; // sf@5
  int v8; // ebx@6
  char *v9; // esi@6
  int v10; // ecx@8
  unsigned int v11; // eax@8
  int v12; // edx@8
  int v13; // eax@8
  double v14; // st7@9
  int v15; // eax@12
  double v16; // st7@12
  int v17; // eax@12
  unsigned __int8 v18; // sf@12
  unsigned __int8 v19; // of@12
  int v20; // eax@17
  signed int v21; // [sp+Ch] [bp-864h]@15
  const char *v22; // [sp+10h] [bp-860h]@15
  unsigned int v23; // [sp+14h] [bp-85Ch]@15
  int v24; // [sp+18h] [bp-858h]@14
  char v25; // [sp+20h] [bp-850h]@17
  char v26; // [sp+24h] [bp-84Ch]@6
  double v27; // [sp+820h] [bp-50h]@8
  double v28; // [sp+828h] [bp-48h]@8
  double v29; // [sp+830h] [bp-40h]@8
  int v30; // [sp+838h] [bp-38h]@8
  int v31; // [sp+83Ch] [bp-34h]@8
  __int64 v32; // [sp+840h] [bp-30h]@8
  __int64 v33; // [sp+848h] [bp-28h]@8
  __int64 v34; // [sp+850h] [bp-20h]@8
  int v35; // [sp+858h] [bp-18h]@8
  int v36; // [sp+85Ch] [bp-14h]@8
  int v37; // [sp+860h] [bp-10h]@8
  float v38; // [sp+864h] [bp-Ch]@6
  int v39; // [sp+868h] [bp-8h]@5
  float v40; // [sp+86Ch] [bp-4h]@8
  float v41; // [sp+878h] [bp+8h]@5

  v2 = a1;
  if ( *(_DWORD *)(a1 + 4) >= 3 )
  {
    if ( *(_BYTE *)(a1 + 3100) & 1 )
      v3 = 1.0;
    else
      v3 = sub_43B570(*(_DWORD *)(a1 + 3096));
    v41 = v3;
    v5 = sub_436427();
    v4 = 0;
    v6 = *(_DWORD *)(v2 + 4) == 0;
    v7 = *(_DWORD *)(v2 + 4) < 0;
    v39 = 0;
    if ( !(v7 | v6) )
    {
      v9 = &v26;
      v8 = v2 + 20;
      v38 = 1.0 / v5;
      while ( 1 )
      {
        v11 = sub_4A2031(*(float *)v8, *(_DWORD *)(v2 + 3092), v4, v4, v4);
        LOBYTE(v12) = v11;
        v34 = (v11 >> 16) & 0xFFi64;
        LOBYTE(v40) = *(_BYTE *)(v2 + 3090);
        v40 = (double)v34 * 0.003921568859368563 * v41 * (double)LOBYTE(v40);
        v29 = v40 + 6.755399441055744e15;
        v37 = LODWORD(v29);
        v32 = (unsigned __int16)((_WORD)v11 >> 8);
        LODWORD(v40) = *(_BYTE *)(v2 + 3089);
        v40 = (double)v32 * 0.003921568859368563 * v41 * (double)SLODWORD(v40);
        v27 = v40 + 6.755399441055744e15;
        v36 = LODWORD(v27);
        v13 = *(_DWORD *)(v2 + 3088);
        v33 = v12 & 0xFFi64;
        v30 = (unsigned __int8)v13;
        v31 = 0;
        v40 = (double)v33 * 0.003921568859368563 * v41 * (double)(unsigned __int8)v13;
        v28 = v40 + 6.755399441055744e15;
        v35 = LODWORD(v28);
        v10 = LODWORD(v28) | ((LODWORD(v27) | (LODWORD(v29) << 8)) << 8);
        if ( a2 == 0.0 )
        {
          v14 = 1.0 - 1.0 / (v38 * *(float *)v8 * 1000.0);
        }
        else
        {
          v14 = 1.0 - 1.0 / (v38 * *(float *)v8 * 1000.0) - a2;
          if ( v14 < 0.00009999999747378752 )
            v14 = 0.00009999999747378752;
        }
        *((float *)v9 + 1) = v14;
        v15 = *(_DWORD *)(v8 + 12);
        ++v39;
        v16 = 1.0 / *(float *)v8;
        *((_DWORD *)v9 - 1) = v15;
        *(_DWORD *)v9 = *(_DWORD *)(v8 + 16);
        *((_DWORD *)v9 + 5) = *(_DWORD *)(v8 + 24);
        *((_DWORD *)v9 + 6) = *(_DWORD *)(v8 + 28);
        v17 = v39;
        *((_DWORD *)v9 + 3) = v10;
        *((_DWORD *)v9 + 4) = 0;
        v8 += 48;
        v9 += 32;
        compile_error;//v19 = __SETO__(v17, *(_DWORD *)(v2 + 4));
        v18 = v17 - *(_DWORD *)(v2 + 4) < 0;
        *((float *)v9 - 6) = v16;
        if ( !(v18 ^ v19) )
          break;
        v4 = 0;
      }
      v4 = 0;
    }
    v24 = v4;
    if ( dword_6BE360 == 1 )
    {
      v23 = 529;
      v22 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp";
      v21 = 28;
    }
    else
    {
      v23 = 537;
      v22 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp";
      v21 = 16;
    }
    v20 = (*(int (__stdcall **)(_DWORD, signed int, signed int, char *, _DWORD, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56)
                                                                                           + 112))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            6,
            452,
            &v25,
            *(_DWORD *)(v2 + 4),
            v21);
    CheckHRESULT((void **)&a2, v20, v22, v23, v24);
  }
}

//----- (0049C2CD) --------------------------------------------------------
void __thiscall sub_49C2CD(int _this, float a2)
{
  int v2; // edi@1
  int v3; // esi@1
  int v4; // ebx@2

  v3 = _this;
  v2 = 0;
  if ( *(_DWORD *)(_this + 3178500) > 0 )
  {
    v4 = _this + 4;
    do
    {
      sub_49C095(v4, a2);
      ++v2;
      v4 += 3104;
    }
    while ( v2 < *(_DWORD *)(v3 + 3178500) );
  }
}

//----- (0049C304) --------------------------------------------------------
void class58_sub_49C304(struct class58 *_this, int a2, unsigned int a3)
{
  char v3; // zf@1
  const char *v4; // eax@4
  int v5; // eax@4
  int v6; // eax@4
  int v7; // eax@4
  int v8; // eax@4
  int v9; // eax@4
  int v10; // eax@4
  int v11; // eax@4
  int v12; // ebx@6
  int v13; // ST6C_4@6
  int v14; // eax@6
  int v15; // eax@6
  int v16; // eax@6
  int v17; // eax@6
  int v18; // eax@6
  int v19; // eax@6
  char v20; // [sp+80h] [bp-8h]@4
  int v21; // [sp+84h] [bp-4h]@1

  v3 = _this->dword_308004 == 0;
  v21 = (int)_this;
  if ( !v3 )
  {
    if ( pD3DRenderer->bUsingSpecular )
      (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        28,
        0);
    v5 = (*(int (__stdcall **)(_DWORD, _DWORD, signed int, signed int, _DWORD, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56)
                                                                                          + 160))(
           *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
           0,
           12,
           3,
           (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp",
           560);
    CheckHRESULT((void **)&v20, v5, 0, a3, a2);
    v6 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
           *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
           27,
           1);
    CheckHRESULT((void **)&v20, v6, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp", 0x231u, 0);
    v7 = (*(int (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
           *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
           14,
           0);
    CheckHRESULT((void **)&v20, v7, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp", 0x232u, 0);
    v8 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
           *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
           22,
           1);
    CheckHRESULT((void **)&v20, v8, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp", 0x233u, 0);
    v9 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
           *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
           19,
           2);
    CheckHRESULT((void **)&v20, v9, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp", 0x234u, 0);
    v10 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            20,
            2);
    CheckHRESULT((void **)&v20, v10, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp", 0x235u, 0);
    v11 = (*(int (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            26,
            0);
    CheckHRESULT((void **)&v20, v11, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp", 0x236u, 0);
    v4 = dword_AE5B98;
    if ( !dword_AE5B98 )
      v4 = (char *)byte_4D8410 + 736;
    v12 = **(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56);
    v13 = sub_436A24(v4);
    v14 = (*(int (__stdcall **)(_DWORD))(v12 + 152))(*(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56));
    CheckHRESULT((void **)&v20, v14, 0, v13, (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp");
    sub_49C2CD(v21, 0.0003999999898951501);
    v15 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            22,
            2);
    CheckHRESULT((void **)&v20, v15, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp", 0x23Bu, 0);
    v16 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            14,
            1);
    CheckHRESULT((void **)&v20, v16, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp", 0x23Cu, 0);
    v17 = (*(int (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            27,
            0);
    CheckHRESULT((void **)&v20, v17, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp", 0x23Du, 0);
    v18 = (*(int (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            19,
            2);
    CheckHRESULT((void **)&v20, v18, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp", 0x23Eu, 0);
    v19 = (*(int (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            20,
            1);
    CheckHRESULT((void **)&v20, v19, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\PolyProjector.cpp", 0x23Fu, 0);
    if ( pD3DRenderer->bUsingSpecular )
      (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        28,
        1);
  }
}

//----- (0049C550) --------------------------------------------------------
char __thiscall sub_49C550(int _this)
{
  int v1; // ebx@1
  int v2; // esi@1
  int v3; // edi@2
  char result; // al@3

  v2 = _this;
  v1 = 0;
  if ( *(_DWORD *)(_this + 3178500) > 0 )
  {
    v3 = _this + 12;
    do
    {
      result = sub_4379EE(pGame->class08_obj, v3, *(_DWORD *)(v3 - 4), (int)pClass58_global->unk_1A0858, 0.0);
      ++v1;
      v3 += 3104;
    }
    while ( v1 < *(_DWORD *)(v2 + 3178500) );
  }
  return result;
}

//----- (0049C5DA) --------------------------------------------------------
char __thiscall sub_49C5DA(void *_this, int a2, int a3, signed int *a4, int a5, int a6)
{
  char *v6; // eax@1
  signed int v7; // ecx@1
  void *v8; // edi@1
  void *v9; // esi@3
  char result; // al@6
  int v11; // [sp+Ch] [bp-C0h]@3
  char v12; // [sp+38h] [bp-94h]@1

  v8 = _this;
  v6 = &v12;
  v7 = 4;
  do
  {
    *(float *)v6 = 0.0;
    v6 += 48;
    --v7;
  }
  while ( v7 );
  v9 = pGame->class08_obj;
  sub_49CE9E(a2, a3, *a4, (int)&v11);
  if ( byte_4D8410[572] )
  {
    if ( *(_BYTE *)(LODWORD(pGame) + 3616) & 8 )
      sub_4379EE(v9, (int)&v11, 4, 16719390, 0.00009999999747378752);
  }
  result = sub_49C9E3(v8, a2, (int)&v11, 4, a6);
  if ( result )
    result = sub_49C720(v8, a6, a5);
  return result;
}

//----- (0049C681) --------------------------------------------------------
char __thiscall sub_49C681(void *_this, int a2, int a3, int a4)
{
  char *v4; // eax@1
  signed int v5; // ecx@1
  void *v6; // edi@1
  void *v7; // esi@3
  char result; // al@6
  int v9; // [sp+Ch] [bp-C0h]@3
  char v10; // [sp+38h] [bp-94h]@1

  v6 = _this;
  v4 = &v10;
  v5 = 4;
  do
  {
    *(float *)v4 = 0.0;
    v4 += 48;
    --v5;
  }
  while ( v5 );
  v7 = pGame->class08_obj;
  sub_49D379(a2, (int)&v9);
  if ( byte_4D8410[572] )
  {
    if ( *(_BYTE *)(LODWORD(pGame) + 3616) & 8 )
      sub_4379EE(v7, (int)&v9, 4, 16719390, 0.00009999999747378752);
  }
  result = sub_49C9E3(v6, a2, (int)&v9, 4, a4);
  if ( result )
    result = sub_49C720(v6, a4, a3);
  return result;
}

//----- (0049C720) --------------------------------------------------------
char __thiscall sub_49C720(void *_this, int a2, int a3)
{
  int v3; // esi@1
  char result; // al@2
  float v5; // [sp+4h] [bp-34h]@1
  float v6; // [sp+8h] [bp-30h]@1
  float v7; // [sp+Ch] [bp-2Ch]@1
  float v8; // [sp+30h] [bp-8h]@1
  void *v9; // [sp+34h] [bp-4h]@1
  int v10; // [sp+40h] [bp+8h]@4

  v3 = a2;
  v8 = 0.0;
  v5 = (double)dword_51B6E8;
  v6 = (double)dword_51B6EC;
  v9 = _this;
  v7 = (double)dword_51B6F0;
  if ( sub_49C7C5(a2, a2 + 48, (int)&v5, a3)
    && sub_49C7C5(a2 + 48, a2 + 96, (int)&v5, a3 + 24)
    && (v10 = a2 + 144, sub_49C7C5(v3 + 96, v3 + 144, (int)&v5, a3 + 48)) )
    result = sub_49C7C5(v10, v3, (int)&v5, a3 + 72) != 0;
  else
    result = 0;
  return result;
}

//----- (0049C7C5) --------------------------------------------------------
char __stdcall sub_49C7C5(int a1, int a2, int a3, int a4)
{
  double v4; // st7@1
  double v5; // st6@1
  double v6; // st5@1
  int v7; // eax@1
  char result; // al@4
  float v9; // ecx@5
  double v10; // st7@5
  double v11; // st6@5
  float v12; // [sp+4h] [bp-48h]@1
  float v13; // [sp+8h] [bp-44h]@1
  float v14; // [sp+Ch] [bp-40h]@1
  int v15; // [sp+10h] [bp-3Ch]@1
  float v16; // [sp+18h] [bp-34h]@1
  float v17; // [sp+20h] [bp-2Ch]@1
  float v18; // [sp+24h] [bp-28h]@1
  float v19; // [sp+28h] [bp-24h]@1
  float v20; // [sp+2Ch] [bp-20h]@1
  float v21; // [sp+30h] [bp-1Ch]@1
  float v22; // [sp+34h] [bp-18h]@1
  float v23; // [sp+38h] [bp-14h]@1
  float v24; // [sp+3Ch] [bp-10h]@1
  float v25; // [sp+40h] [bp-Ch]@1
  float v26; // [sp+44h] [bp-8h]@1
  float v27; // [sp+48h] [bp-4h]@1

  v25 = 0.0;
  v26 = 0.0;
  v27 = 0.0;
  v22 = *(float *)a3;
  v23 = *(float *)(a3 + 4);
  v24 = *(float *)(a3 + 8);
  v4 = *(float *)a1;
  v5 = *(float *)(a1 + 4);
  v16 = *(float *)(a1 + 8);
  v6 = *(float *)a2;
  v17 = *(float *)(a2 + 4);
  v18 = *(float *)(a2 + 8);
  v19 = v4 - v22;
  v20 = v5 - v23;
  v21 = v16 - v24;
  v12 = v19;
  v13 = v20;
  v14 = v21;
  v19 = v6 - v4;
  v20 = v17 - v5;
  v21 = v18 - v16;
  v7 = sub_49B32D((int)&v12, (int)&v15, v19, v20, v21);
  LODWORD(v25) = *(_DWORD *)v7;
  LODWORD(v26) = *(_DWORD *)(v7 + 4);
  LODWORD(v27) = *(_DWORD *)(v7 + 8);
  if ( v25 != 0.0 || v26 != 0.0 || v27 != 0.0 )
  {
    sub_4369DB((int)&v25);
    v9 = v26;
    *(float *)(a4 + 8) = v25;
    v10 = v24 * v27;
    v11 = v23 * v26;
    *(_DWORD *)(a4 + 12) = LODWORD(v9);
    *(_DWORD *)(a4 + 16) = LODWORD(v27);
    *(float *)(a4 + 20) = v10 + v11 + v22 * v25;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0049C8DC) --------------------------------------------------------
char __stdcall sub_49C8DC(int a1, int a2, int a3)
{
  double v3; // st7@1
  double v4; // st6@1
  double v5; // st5@1
  int v6; // eax@1
  char result; // al@4
  float v8; // ecx@5
  double v9; // st7@5
  double v10; // st6@5
  float v11; // [sp+8h] [bp-3Ch]@1
  float v12; // [sp+Ch] [bp-38h]@1
  float v13; // [sp+10h] [bp-34h]@1
  int v14; // [sp+14h] [bp-30h]@1
  float v15; // [sp+1Ch] [bp-28h]@1
  float v16; // [sp+24h] [bp-20h]@1
  float v17; // [sp+28h] [bp-1Ch]@1
  float v18; // [sp+2Ch] [bp-18h]@1
  float v19; // [sp+30h] [bp-14h]@1
  float v20; // [sp+34h] [bp-10h]@1
  float v21; // [sp+38h] [bp-Ch]@1
  float v22; // [sp+3Ch] [bp-8h]@1
  float v23; // [sp+40h] [bp-4h]@1

  v18 = *(float *)a1;
  v19 = *(float *)(a1 + 4);
  v20 = *(float *)(a1 + 8);
  v3 = *(float *)(a1 + 48);
  v4 = *(float *)(a1 + 52);
  v15 = *(float *)(a1 + 56);
  v5 = *(float *)(a1 + 96);
  v16 = *(float *)(a1 + 100);
  v17 = *(float *)(a1 + 104);
  v21 = v3 - v18;
  v22 = v4 - v19;
  v23 = v15 - v20;
  v11 = v21;
  v12 = v22;
  v13 = v23;
  v21 = v5 - v3;
  v22 = v16 - v4;
  v23 = v17 - v15;
  v6 = sub_49B32D((int)&v11, (int)&v14, v21, v22, v23);
  LODWORD(v21) = *(_DWORD *)v6;
  LODWORD(v22) = *(_DWORD *)(v6 + 4);
  LODWORD(v23) = *(_DWORD *)(v6 + 8);
  if ( v21 != 0.0 || v22 != 0.0 || v23 != 0.0 )
  {
    sub_4369DB((int)&v21);
    v8 = v22;
    *(float *)a2 = v21;
    v9 = v20 * v23;
    v10 = v19 * v22;
    *(_DWORD *)(a2 + 4) = LODWORD(v8);
    *(_DWORD *)(a2 + 8) = LODWORD(v23);
    *(float *)a3 = -(v9 + v10 + v18 * v21);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0049C9E3) --------------------------------------------------------
char __thiscall sub_49C9E3(void *_this, int a2, int a3, int a4, int a5)
{
  char v5; // al@1
  void *v6; // edi@1
  int v8; // edx@7
  char v10; // zf@10
  char v12; // zf@14
  float v14; // ST14_4@20
  char result; // al@21
  void *v17; // ecx@24
  float v18; // ST14_4@24
  int v20; // edi@29
  void *v21; // ecx@30
  float v22; // ST14_4@30
  float v23; // ST14_4@30
  float v24; // ST14_4@30
  float v25; // ST14_4@30
  void *v26; // ecx@31
  float v27; // ST14_4@31
  int v28; // [sp+10h] [bp-90h]@24
  float v29; // [sp+14h] [bp-8Ch]@24
  float v30; // [sp+18h] [bp-88h]@24
  int v32; // [sp+40h] [bp-60h]@20
  float v33; // [sp+44h] [bp-5Ch]@20
  float v34; // [sp+48h] [bp-58h]@20
  void *v36; // [sp+70h] [bp-30h]@1
  int v40; // [sp+84h] [bp-1Ch]@1
  int v41; // [sp+88h] [bp-18h]@8
  float v42; // [sp+8Ch] [bp-14h]@1
  int v46; // [sp+9Ch] [bp-4h]@8

  compile_error;//_ESI = a2;
  v40 = (int)_this;
  __asm
  {
    fld     dword ptr [esi]
    fld     dword ptr [esi+4]
    fldz
  }
  v6 = pGame->class08_obj;
  v5 = *(_BYTE *)(a2 + 92);
  __asm
  {
   int 3
    //fstp    [ebp+var_28]
    fldz
  }
  v36 = v6;
  __asm
  {
   int 3
    //fstp    [ebp+var_24]
    fldz
    //fstp    [ebp+var_14]
    fldz
    //fstp    [ebp+var_10]
    fldz
    //fstp    [ebp+var_C]
  }
  if ( v5 == 1 )
  {
    __asm
    {
     int 3
      fchs
      //fstp    [ebp+var_14]
      //fstp    [ebp+var_10]
      fldz
      //fstp    [ebp+var_C]
    }
    sub_4369DB((int)&v42);
    __asm
    {
     int 3
      fldz
      //fstp    [ebp+var_28]
      fld1
    }
LABEL_6:
    __asm {
     int 3
      //fstp    [ebp+var_24]
    }
    goto LABEL_7;
  }
  __asm
  {
    fstp    st
    fstp    st
  }
  if ( v5 == 3 || v5 == 5 )
  {
    __asm
    {
     int 3
      fld1
      //fstp    [ebp+var_14]
      fldz
      //fstp    [ebp+var_10]
      fldz
      //fstp    [ebp+var_C]
      fld1
      //fstp    [ebp+var_28]
      fldz
    }
    goto LABEL_6;
  }
LABEL_7:
  compile_error;//v8 = *(_DWORD *)(_ESI + 44);
  compile_error;//_ECX = a3;
  __asm { fld     dword ptr ds:byte_4D8410+0E0h }
  if ( BYTE1(v8) & 1 )
  {
    __asm
    {
     int 3
      fld     dword ptr [ecx+60h]
      fadd    dword ptr [ecx]
      fmul    st, st(1)
      //fstp    [ebp+arg_4]
      fld     dword ptr [ecx+94h]
      fadd    dword ptr [ecx+34h]
      fmul    st, st(1)
      //fstp    [ebp+var_18]
      fld     dword ptr [ecx+68h]
      fadd    dword ptr [ecx+8]
      fmul    st, st(1)
      //fstp    [ebp+var_4]
      //fld     [ebp+arg_4]
      fsub    dword ptr [ecx]
      //fstp    [ebp+arg_0]
      //fld     [ebp+var_18]
      fsub    dword ptr [ecx+34h]
      //fstp    [ebp+var_8]
    }
  }
  if ( BYTE1(v8) & 2 )
  {
    __asm
    {
      fld     dword ptr [ecx+60h]
      fadd    dword ptr [ecx]
    }
    compile_error;//v10 = *(_BYTE *)(_ESI + 92) == 1;
    __asm
    {
     int 3
      fmul    st, st(1)
      //fstp    [ebp+arg_4]
      fld     dword ptr [ecx+64h]
      fadd    dword ptr [ecx+4]
      fmul    st, st(1)
      //fstp    [ebp+var_18]
      fld     dword ptr [ecx+98h]
      fadd    dword ptr [ecx+38h]
      fmul    st, st(1)
      //fstp    [ebp+var_4]
      //fld     [ebp+arg_4]
      fsub    dword ptr [ecx]
      //fstp    [ebp+arg_0]
      //fld     [ebp+var_4]
      fsub    dword ptr [ecx+38h]
      //fstp    [ebp+var_8]
    }
    if ( v10 )
    {
      __asm
      {
       int 3
        //fld     [ebp+var_14]
        fcomp   dword ptr ds:byte_4D8410+98h
        fnstsw  ax
      }

      compile_error;//if ( __SETP__(HIBYTE(_AX) & 0x44, 0) )
      if (0)
      {
        __asm
        {
         int 3
          //fld     [ebp+arg_0]
          //fdiv    [ebp+var_14]
          //fstp    [ebp+arg_0]
        }
      }
    }
  }
  if ( BYTE1(v8) & 4 )
  {
    __asm
    {
      fld     dword ptr [ecx+60h]
      fadd    dword ptr [ecx]
    }
    compile_error;//v12 = *(_BYTE *)(_ESI + 92) == 1;
    __asm
    {
     int 3
      fmul    st, st(1)
      //fstp    [ebp+arg_4]
      fld     dword ptr [ecx+64h]
      fadd    dword ptr [ecx+4]
      fmul    st, st(1)
      //fstp    [ebp+var_18]
      fld     dword ptr [ecx+98h]
      fadd    dword ptr [ecx+38h]
      fmul    st, st(1)
      //fstp    [ebp+var_4]
      fstp    st
      //fld     [ebp+var_18]
      fsub    dword ptr [ecx+4]
      //fstp    [ebp+arg_0]
      //fld     [ebp+var_4]
      fsub    dword ptr [ecx+38h]
      //fstp    [ebp+var_8]
    }
    if ( v12 )
    {
      __asm
      {
       int 3
        //fld     [ebp+var_14]
        fcomp   dword ptr ds:byte_4D8410+98h
        fnstsw  ax
      }

      compile_error;//if ( __SETP__(HIBYTE(_AX) & 0x44, 0) )
      if (0)
      {
        __asm
        {
         int 3
          //fld     [ebp+arg_0]
          //fdiv    [ebp+var_10]
          //fstp    [ebp+arg_0]
        }
      }
    }
  }
  else
  {
    __asm { fstp    st }
  }
  if ( byte_4D8410[572] )
  {
    if ( *(_BYTE *)(LODWORD(pGame) + 3616) & 8 )
    {
      __asm { fldz }
      v32 = a3;
      __asm {
       int 3
        //fstp    [ebp+var_34]
      }
      LODWORD(v33) = v41;
      __asm { fldz }
      LODWORD(v34) = v46;
      __asm {
       int 3
       //fstp    [esp+0A0h+var_A0]
      }
      compile_error;//sub_437AB5(v6, _ECX, 65280, (int)&v32, 16711680, 0, v14);
    }
  }
  __asm
  {
   int 3
    //fld     [ebp+var_8]
    fmul    dword ptr ds:byte_4D8410+0D8h
    //fld     [ebp+var_8]
    //fmul    [ebp+var_28]
    //fld     [ebp+var_8]
    //fmul    [ebp+var_24]
  }
  compile_error;//_EBX = a5;
  __asm
  {
   int 3
    //fst     [ebp+var_20]
    //fld     [ebp+arg_0]
    //fmul    [ebp+var_14]
    //fld     [ebp+arg_0]
    //fmul    [ebp+var_10]
    //fld     [ebp+arg_0]
    //fmul    [ebp+var_C]
    //fstp    [ebp+var_8]
    //fld     [ebp+arg_4]
    fsub    st, st(2)
    fld     st
    fadd    st, st(6)
    fstp    dword ptr [ebx]
    //fld     [ebp+var_18]
    fsub    st, st(2)
    fld     st
    fadd    st, st(6)
    fstp    dword ptr [ebx+4]
    //fld     [ebp+var_4]
    //fsub    [ebp+var_8]
    //fst     [ebp+arg_0]
    fadd    st, st(5)
    fstp    dword ptr [ebx+8]
    fld     st(1)
    fsub    st, st(7)
    fstp    dword ptr [ebx+30h]
    fsub    st, st(5)
    fstp    dword ptr [ebx+34h]
    fstp    st
    //fld     [ebp+arg_0]
    fsub    st, st(3)
    fstp    dword ptr [ebx+38h]
    fld     st(1)
    //fadd    [ebp+arg_4]
    //fst     [ebp+arg_0]
    fsub    st, st(5)
    fstp    dword ptr [ebx+60h]
    //fadd    [ebp+var_18]
    fstp    st(2)
    fstp    st
    fld     st
    fsub    st, st(2)
    fstp    dword ptr [ebx+64h]
    //fld     [ebp+var_8]
    //fadd    [ebp+var_4]
    //fst     [ebp+arg_C]
    //fsub    [ebp+var_20]
    fstp    dword ptr [ebx+68h]
    //fld     [ebp+arg_0]
    fadd    st, st(3)
    fstp    dword ptr [ebx+90h]
    fadd    st, st(1)
    fstp    dword ptr [ebx+94h]
    fstp    st
    fstp    st
    //fld     [ebp+arg_C]
    //fadd    [ebp+var_20]
    fstp    dword ptr [ebx+98h]
    fldz
    //fstp    [ebp+var_14]
    fldz
    //fstp    [ebp+var_10]
    fldz
    //fstp    [ebp+var_C]
  }
  compile_error;//result = sub_49C8DC(_EBX, (int)&v42, (int)&a2);
  if ( result )
  {
    if ( byte_4D8410[572] )
    {
      if ( *(_BYTE *)(LODWORD(pGame) + 3616) & 8 )
      {
        __asm
        {
         int 3
          fldz
          //fstp    [ebp+var_34]
          fld     dword ptr ds:byte_4D8410+360h
          //fld     [ebp+var_14]
          fmul    st, st(1)
        }
        v28 = a3;
        LODWORD(v29) = v41;
        __asm
        {
         int 3
          //fstp    [ebp+var_60]
          //fld     [ebp+var_10]
          fmul    st, st(1)
        }
        LODWORD(v30) = v46;
        v17 = v6;
        __asm
        {
         int 3
          //fstp    [ebp+var_5C]
          //fld     [ebp+var_C]
          fmul    st, st(1)
          //fstp    [ebp+var_58]
          fstp    st
          fldz
          //fstp    [ebp+var_64]
          fldz
          //fstp    [esp+0A0h+var_A0]
        }
        sub_437AB5(v17, (int)&v28, -1, (int)&v32, 16776960, 0, v18);
      }
    }
    __asm { fild    dword_51B6F0 }
    compile_error;//memcpy(&v28, (const void *)_EBX, 0x30u);
    __asm
    {
     int 3
      //fsubr   [ebp+var_88]
      //fmul    [ebp+var_C]
      fild    dword_51B6EC
      //fsubr   [ebp+var_8C]
      //fmul    [ebp+var_10]
      faddp   st(1), st
      fild    dword_51B6E8
      //fsubr   [ebp+var_90]
      //fmul    [ebp+var_14]
      faddp   st(1), st
      fcomp   dword ptr ds:byte_4D8410+0D8h
      fnstsw  ax
    }

    compile_error;
    /*if ( !__SETP__(HIBYTE(_AX) & 5, 0) )
    if (0)
    {
      memcpy(&v28, (const void *)(_EBX + 48), 0x30u);
      memcpy((void *)(_EBX + 48), (const void *)(_EBX + 144), 0x30u);
      memcpy((void *)(_EBX + 144), &v28, 0x30u);
    }*/

    if ( byte_4D8410[572] )
    {
      if ( *(_BYTE *)(LODWORD(pGame) + 3616) & 8 )
      {
        v20 = v40;
        if ( !*(_BYTE *)(v40 + 4) )
        {
          __asm
          {
            fldz
             int 3
            //fstp    [ebp+var_34]
            //fild    pParty_global->sPartyPosX
          }
          a2 = pParty_global->sPartyPosZ + pParty_global->uEyelevel;
          __asm
          {
           int 3
            //fstp    [ebp+var_60]
            //fild    pParty_global->sPartyPosY
            //fstp    [ebp+var_5C]
            //fild    [ebp+arg_0]
            //fstp    [ebp+var_58]
            fldz
          }
          v21 = pGame->class08_obj;
          __asm {
           int 3
           //fstp    [esp+0A0h+var_A0]
          }
          compile_error;//sub_437AB5(v21, (int)&v32, 16711680, _EBX, 16711680, 0, v22);
          __asm
          {
            fldz
             int 3
            //fstp    [esp+0A0h+var_A0]
          }
          compile_error;//sub_437AB5(pGame->class08_obj, (int)&v32, 65280, _EBX + 48, 65280, 0, v23);
          __asm
          {
            fldz
             int 3
            //fstp    [esp+0A0h+var_A0]
          }
          compile_error;//sub_437AB5(pGame->class08_obj, (int)&v32, 255, _EBX + 96, 255, 0, v24);
          __asm
          {
            fldz
             int 3
            //fstp    [esp+0A0h+var_A0]
          }
          compile_error;//sub_437AB5(pGame->class08_obj, (int)&v32, 16777215, _EBX + 144, 16777215, 0, v25);
          *(_BYTE *)(v20 + 4) = 1;
        }
        __asm { fld     dword ptr ds:byte_4D8410+2D8h }
        v26 = v36;
        __asm { int 3
        // fstp    [esp+0A0h+var_A0]
        }
        compile_error;//sub_4379EE(v26, _EBX, a4, 2031390, v27);
      }
    }
    result = 1;
  }
  return result;
}

//----- (0049CE9E) --------------------------------------------------------
void __stdcall sub_49CE9E(int a1, int a2, signed int a3, int a4)
{
  char *v4; // eax@1
  signed int v5; // edx@1
  int v6; // eax@3
  signed int v7; // ecx@11
  signed int v8; // esi@11
  int v9; // edx@12
  double v10; // st6@14
  int v11; // edx@19
  signed int v12; // ecx@19
  signed int v13; // esi@19
  int v14; // edi@20
  double v15; // st6@22
  signed int v16; // ecx@27
  signed int v17; // edi@27
  int v18; // esi@28
  double v19; // st6@30
  signed int v20; // ecx@35
  signed int v21; // edi@35
  int v22; // esi@36
  double v23; // st7@38
  signed int v24; // ecx@45
  signed int v25; // esi@45
  int v26; // edx@46
  double v27; // st6@48
  signed int v28; // ecx@53
  signed int v29; // esi@53
  int v30; // edi@54
  double v31; // st6@56
  signed int v32; // ecx@61
  signed int v33; // edi@61
  int v34; // esi@62
  double v35; // st6@64
  signed int v36; // edi@69
  int v37; // esi@70
  double v38; // st7@72
  int v39; // esi@77
  signed int v40; // ecx@79
  signed int v41; // esi@79
  int v42; // edx@80
  double v43; // st6@82
  int v44; // eax@87
  signed int v45; // ecx@87
  signed int v46; // edi@87
  int v47; // esi@88
  double v48; // st6@90
  signed int v49; // ecx@96
  signed int v50; // edi@96
  int v51; // esi@97
  double v52; // st6@99
  signed int v53; // ecx@105
  signed int v54; // edi@105
  int v55; // esi@106
  double v56; // st7@108
  float v57; // [sp+0h] [bp-C18h]@3
  float v58; // [sp+4h] [bp-C14h]@8
  char v59; // [sp+2Ch] [bp-BECh]@1
  float v60; // [sp+34h] [bp-BE4h]@4
  float v61; // [sp+38h] [bp-BE0h]@9
  float v62; // [sp+60h] [bp-BB8h]@4
  float v63; // [sp+64h] [bp-BB4h]@8
  float v64; // [sp+94h] [bp-B84h]@4
  float v65; // [sp+98h] [bp-B80h]@9
  float v66; // [sp+C00h] [bp-18h]@4
  float v67; // [sp+C04h] [bp-14h]@9
  float v68; // [sp+C08h] [bp-10h]@4
  float v69; // [sp+C0Ch] [bp-Ch]@9
  float v70; // [sp+C10h] [bp-8h]@4
  float v71; // [sp+C14h] [bp-4h]@4
  float v72; // [sp+C20h] [bp+8h]@11
  float v73; // [sp+C20h] [bp+8h]@19
  float v74; // [sp+C20h] [bp+8h]@27
  float v75; // [sp+C20h] [bp+8h]@35
  float v76; // [sp+C20h] [bp+8h]@45
  float v77; // [sp+C20h] [bp+8h]@53
  float v78; // [sp+C20h] [bp+8h]@61
  float v79; // [sp+C20h] [bp+8h]@69
  float v80; // [sp+C20h] [bp+8h]@79
  float v81; // [sp+C20h] [bp+8h]@87
  float v82; // [sp+C20h] [bp+8h]@96
  float v83; // [sp+C20h] [bp+8h]@105

  v4 = &v59;
  v5 = 64;
  do
  {
    *(float *)v4 = 0.0;
    v4 += 48;
    --v5;
  }
  while ( v5 );
  sub_49D379(a1, (int)&v57);
  v6 = *(_DWORD *)(a1 + 44);
  if ( v6 & 0x100 )
  {
    v70 = v57;
    v66 = v62;
    v68 = v60;
    v71 = v64;
    goto LABEL_10;
  }
  if ( v6 & 0x200 )
  {
    v70 = v57;
    v66 = v62;
  }
  else
  {
    if ( !(v6 & 0x400) )
      goto LABEL_10;
    v68 = v58;
    v71 = v63;
  }
  v69 = v61;
  v67 = v65;
LABEL_10:
  if ( v6 & 0x100 )
  {
    v7 = -1;
    v72 = 3.402823466385289e38;
    v8 = 0;
    if ( a3 > 0 )
    {
      v9 = a2;
      do
      {
        if ( *(float *)v9 <= (double)v70 )
          v10 = v70 - *(float *)v9;
        else
          v10 = *(float *)v9 - v70;
        if ( v10 < v72 )
        {
          v72 = v10;
          v7 = v8;
        }
        ++v8;
        v9 += 48;
      }
      while ( v8 < a3 );
    }
    v11 = a4;
    v73 = 3.402823466385289e38;
    memcpy((void *)a4, (const void *)(a2 + 48 * v7), 0x30u);
    v12 = -1;
    v13 = 0;
    if ( a3 > 0 )
    {
      v14 = a2;
      do
      {
        if ( *(float *)v14 <= (double)v66 )
          v15 = v66 - *(float *)v14;
        else
          v15 = *(float *)v14 - v66;
        if ( v15 < v73 )
        {
          v73 = v15;
          v12 = v13;
        }
        ++v13;
        v14 += 48;
      }
      while ( v13 < a3 );
    }
    v74 = 3.402823466385289e38;
    memcpy((void *)(a4 + 96), (const void *)(a2 + 48 * v12), 0x30u);
    v16 = -1;
    v17 = 0;
    if ( a3 > 0 )
    {
      v18 = a2 + 4;
      do
      {
        if ( *(float *)v18 <= (double)v68 )
          v19 = v68 - *(float *)v18;
        else
          v19 = *(float *)v18 - v68;
        if ( v19 < v74 )
        {
          v74 = v19;
          v16 = v17;
        }
        ++v17;
        v18 += 48;
      }
      while ( v17 < a3 );
    }
    v75 = 3.402823466385289e38;
    memcpy((void *)(a4 + 48), (const void *)(a2 + 48 * v16), 0x30u);
    v20 = -1;
    v21 = 0;
    if ( a3 > 0 )
    {
      v22 = a2 + 4;
      do
      {
        if ( *(float *)v22 <= (double)v71 )
          v23 = v71 - *(float *)v22;
        else
          v23 = *(float *)v22 - v71;
        if ( v23 < v75 )
        {
          v75 = v23;
          v20 = v21;
        }
        ++v21;
        v22 += 48;
      }
      while ( v21 < a3 );
    }
LABEL_77:
    v39 = a2 + 48 * v20;
    goto LABEL_115;
  }
  if ( v6 & 0x200 )
  {
    v24 = -1;
    v76 = 3.402823466385289e38;
    v25 = 0;
    if ( a3 > 0 )
    {
      v26 = a2;
      do
      {
        if ( *(float *)v26 <= (double)v70 )
          v27 = v70 - *(float *)v26;
        else
          v27 = *(float *)v26 - v70;
        if ( v27 < v76 )
        {
          v76 = v27;
          v24 = v25;
        }
        ++v25;
        v26 += 48;
      }
      while ( v25 < a3 );
    }
    v11 = a4;
    v77 = 3.402823466385289e38;
    memcpy((void *)a4, (const void *)(a2 + 48 * v24), 0x30u);
    v28 = -1;
    v29 = 0;
    if ( a3 > 0 )
    {
      v30 = a2;
      do
      {
        if ( *(float *)v30 <= (double)v66 )
          v31 = v66 - *(float *)v30;
        else
          v31 = *(float *)v30 - v66;
        if ( v31 < v77 )
        {
          v77 = v31;
          v28 = v29;
        }
        ++v29;
        v30 += 48;
      }
      while ( v29 < a3 );
    }
    v78 = 3.402823466385289e38;
    memcpy((void *)(a4 + 96), (const void *)(a2 + 48 * v28), 0x30u);
    v32 = -1;
    v33 = 0;
    if ( a3 > 0 )
    {
      v34 = a2 + 8;
      do
      {
        if ( *(float *)v34 <= (double)v69 )
          v35 = v69 - *(float *)v34;
        else
          v35 = *(float *)v34 - v69;
        if ( v35 < v78 )
        {
          v78 = v35;
          v32 = v33;
        }
        ++v33;
        v34 += 48;
      }
      while ( v33 < a3 );
    }
    v79 = 3.402823466385289e38;
    memcpy((void *)(a4 + 48), (const void *)(a2 + 48 * v32), 0x30u);
    v20 = -1;
    v36 = 0;
    if ( a3 > 0 )
    {
      v37 = a2 + 8;
      do
      {
        if ( *(float *)v37 <= (double)v67 )
          v38 = v67 - *(float *)v37;
        else
          v38 = *(float *)v37 - v67;
        if ( v38 < v79 )
        {
          v79 = v38;
          v20 = v36;
        }
        ++v36;
        v37 += 48;
      }
      while ( v36 < a3 );
    }
    goto LABEL_77;
  }
  if ( !(v6 & 0x400) )
    return;
  v40 = -1;
  v80 = 3.402823466385289e38;
  v41 = 0;
  if ( a3 > 0 )
  {
    v42 = a2 + 4;
    do
    {
      if ( *(float *)v42 <= (double)v68 )
        v43 = v68 - *(float *)v42;
      else
        v43 = *(float *)v42 - v68;
      if ( v43 < v80 )
      {
        v80 = v43;
        v40 = v41;
      }
      ++v41;
      v42 += 48;
    }
    while ( v41 < a3 );
  }
  v44 = a2;
  v11 = a4;
  v81 = 3.402823466385289e38;
  memcpy((void *)a4, (const void *)(a2 + 48 * v40), 0x30u);
  v45 = -1;
  v46 = 0;
  if ( a3 > 0 )
  {
    v47 = a2 + 4;
    do
    {
      if ( *(float *)v47 <= (double)v71 )
        v48 = v71 - *(float *)v47;
      else
        v48 = *(float *)v47 - v71;
      if ( v48 < v81 )
      {
        v81 = v48;
        v45 = v46;
      }
      ++v46;
      v47 += 48;
    }
    while ( v46 < a3 );
    v44 = a2;
  }
  v82 = 3.402823466385289e38;
  memcpy((void *)(a4 + 96), (const void *)(v44 + 48 * v45), 0x30u);
  v49 = -1;
  v50 = 0;
  if ( a3 > 0 )
  {
    v51 = v44 + 8;
    do
    {
      if ( *(float *)v51 <= (double)v69 )
        v52 = v69 - *(float *)v51;
      else
        v52 = *(float *)v51 - v69;
      if ( v52 < v82 )
      {
        v82 = v52;
        v49 = v50;
      }
      ++v50;
      v51 += 48;
    }
    while ( v50 < a3 );
    v44 = a2;
  }
  v83 = 3.402823466385289e38;
  memcpy((void *)(a4 + 48), (const void *)(v44 + 48 * v49), 0x30u);
  v53 = -1;
  v54 = 0;
  if ( a3 > 0 )
  {
    v55 = v44 + 8;
    do
    {
      if ( *(float *)v55 <= (double)v67 )
        v56 = v67 - *(float *)v55;
      else
        v56 = *(float *)v55 - v67;
      if ( v56 < v83 )
      {
        v83 = v56;
        v53 = v54;
      }
      ++v54;
      v55 += 48;
    }
    while ( v54 < a3 );
    v44 = a2;
  }
  v39 = v44 + 48 * v53;
LABEL_115:
  memcpy((void *)(v11 + 144), (const void *)v39, 0x30u);
}

//----- (0049D379) --------------------------------------------------------
signed int __stdcall sub_49D379(int a1, int a2)
{
  int v2; // edx@1
  int v3; // ecx@1
  int v4; // eax@2
  char *v5; // eax@3
  int v6; // esi@3
  int v7; // ebx@4
  int v8; // edi@4
  int v9; // ebx@4
  int v10; // edi@4
  double v11; // st7@4
  int v12; // edi@4
  char *v13; // eax@7
  int v14; // esi@7
  int v15; // ebx@8
  int v16; // edi@8
  int v17; // ebx@8
  int v18; // edi@8
  double v19; // st7@8
  int v20; // edi@8
  char *v21; // eax@11
  int v22; // esi@11
  int v23; // ebx@12
  int v24; // edi@12
  int v25; // ebx@12
  int v26; // edi@12
  double v27; // st7@12
  int v28; // edi@12
  int v29; // eax@13
  double v30; // st7@13
  int v31; // edi@14
  char *v32; // esi@14
  signed int result; // eax@24
  int v34; // eax@24
  int v35; // eax@24
  signed int v36; // ecx@24
  signed int v37; // eax@24
  int v38; // eax@24
  signed int v39; // ecx@24
  signed int v40; // eax@24
  int v41; // eax@24
  signed int v42; // ecx@24
  signed int v43; // eax@24
  int v44; // eax@24
  signed int v45; // ecx@24
  char v46; // [sp+10h] [bp-350h]@3
  float v47; // [sp+30Ch] [bp-54h]@24
  float v48; // [sp+310h] [bp-50h]@24
  float v49; // [sp+314h] [bp-4Ch]@24
  float v50; // [sp+338h] [bp-28h]@24
  int v51; // [sp+33Ch] [bp-24h]@16
  int v52; // [sp+340h] [bp-20h]@20
  int v53; // [sp+344h] [bp-1Ch]@18
  int v54; // [sp+348h] [bp-18h]@22
  int v55; // [sp+34Ch] [bp-14h]@3
  int v56; // [sp+350h] [bp-10h]@3
  float v57; // [sp+354h] [bp-Ch]@1
  float v58; // [sp+358h] [bp-8h]@4
  int v59; // [sp+35Ch] [bp-4h]@4
  int v60; // [sp+368h] [bp+8h]@2
  int v61; // [sp+368h] [bp+8h]@6
  int v62; // [sp+368h] [bp+8h]@10
  float v63; // [sp+368h] [bp+8h]@13
  signed int v64; // [sp+368h] [bp+8h]@24
  signed int v65; // [sp+368h] [bp+8h]@24
  signed int v66; // [sp+368h] [bp+8h]@24
  signed int v67; // [sp+368h] [bp+8h]@24

  v2 = a1;
  v3 = dword_6BE63C;
  LODWORD(v57) = *(_DWORD *)(a1 + 44);
  if ( BYTE1(v57) & 1 )
  {
    v4 = *(_BYTE *)(a1 + 93);
    v60 = 0;
    if ( v4 > 0 )
    {
      v6 = *(_DWORD *)(v2 + 48);
      v5 = &v46;
      v55 = *(_DWORD *)(v2 + 52) - v6;
      v56 = *(_DWORD *)(v2 + 56) - v6;
      do
      {
        v7 = *(_WORD *)(v6 + v55);
        v59 = v3 + 6 * *(_WORD *)v6;
        LODWORD(v58) = *(_WORD *)v59 + v7;
        v8 = *(_WORD *)(v6 + v56);
        v9 = *(_WORD *)(v59 + 2);
        *((float *)v5 - 1) = (double)SLODWORD(v58);
        v59 = v9 + v8;
        v10 = v60;
        v11 = (double)v59;
        ++v60;
        *((_DWORD *)v5 + 1) = v10;
        v12 = *(_BYTE *)(v2 + 93);
        *(float *)v5 = v11;
        v5 += 12;
        v6 += 2;
      }
      while ( v60 < v12 );
    }
  }
  if ( BYTE1(v57) & 2 )
  {
    v61 = 0;
    if ( (signed int)*(_BYTE *)(v2 + 93) > 0 )
    {
      v14 = *(_DWORD *)(v2 + 48);
      v13 = &v46;
      v55 = *(_DWORD *)(v2 + 52) - v14;
      LODWORD(v58) = *(_DWORD *)(v2 + 60) - v14;
      do
      {
        v15 = *(_WORD *)(v14 + v55);
        v56 = v3 + 6 * *(_WORD *)v14;
        v59 = *(_WORD *)v56 + v15;
        v16 = *(_WORD *)(LODWORD(v58) + v14);
        v17 = *(_WORD *)(v56 + 4);
        *((float *)v13 - 1) = (double)v59;
        v59 = v17 + v16;
        v18 = v61;
        v19 = (double)v59;
        ++v61;
        *((_DWORD *)v13 + 1) = v18;
        v20 = *(_BYTE *)(v2 + 93);
        *(float *)v13 = v19;
        v13 += 12;
        v14 += 2;
      }
      while ( v61 < v20 );
    }
  }
  if ( BYTE1(v57) & 4 )
  {
    v62 = 0;
    if ( (signed int)*(_BYTE *)(v2 + 93) > 0 )
    {
      v22 = *(_DWORD *)(v2 + 48);
      v21 = &v46;
      v56 = *(_DWORD *)(v2 + 56) - v22;
      LODWORD(v58) = *(_DWORD *)(v2 + 60) - v22;
      do
      {
        v23 = *(_WORD *)(v22 + v56);
        LODWORD(v57) = v3 + 6 * *(_WORD *)v22;
        v59 = *(_WORD *)(LODWORD(v57) + 2) + v23;
        v24 = *(_WORD *)(v22 + LODWORD(v58));
        v25 = *(_WORD *)(LODWORD(v57) + 4);
        *((float *)v21 - 1) = (double)v59;
        v59 = v25 + v24;
        v26 = v62;
        v27 = (double)v59;
        ++v62;
        *((_DWORD *)v21 + 1) = v26;
        v28 = *(_BYTE *)(v2 + 93);
        *(float *)v21 = v27;
        v21 += 12;
        v22 += 2;
      }
      while ( v62 < v28 );
    }
  }
  v29 = *(_BYTE *)(v2 + 93);
  v63 = 3.402823466385289e38;
  v58 = 3.402823466385289e38;
  v30 = -3.402823466385289e38;
  LODWORD(v57) = -8388609;
  if ( v29 > 0 )
  {
    v32 = &v46;
    v31 = v29;
    do
    {
      if ( *((float *)v32 - 1) < (double)v63 )
      {
        LODWORD(v63) = *((_DWORD *)v32 - 1);
        v51 = *((_DWORD *)v32 + 1);
      }
      if ( *((float *)v32 - 1) > (double)v57 )
      {
        LODWORD(v57) = *((_DWORD *)v32 - 1);
        v53 = *((_DWORD *)v32 + 1);
      }
      if ( *(float *)v32 < (double)v58 )
      {
        LODWORD(v58) = *(_DWORD *)v32;
        v52 = *((_DWORD *)v32 + 1);
      }
      if ( v30 < *(float *)v32 )
      {
        v30 = *(float *)v32;
        v54 = *((_DWORD *)v32 + 1);
      }
      v32 += 12;
      --v31;
    }
    while ( v31 );
  }
  v34 = *(_WORD *)(*(_DWORD *)(v2 + 48) + 2 * v51);
  v50 = 0.0;
  v35 = v3 + 6 * v34;
  v64 = *(_WORD *)v35;
  v36 = *(_WORD *)(v35 + 2);
  v37 = *(_WORD *)(v35 + 4);
  v47 = (double)v64;
  v48 = (double)v36;
  v49 = (double)v37;
  memcpy((void *)a2, &v47, 0x30u);
  v50 = 0.0;
  v38 = dword_6BE63C + 6 * *(_WORD *)(*(_DWORD *)(v2 + 48) + 2 * v52);
  v65 = *(_WORD *)v38;
  v39 = *(_WORD *)(v38 + 2);
  v40 = *(_WORD *)(v38 + 4);
  v47 = (double)v65;
  v48 = (double)v39;
  v49 = (double)v40;
  memcpy((void *)(a2 + 48), &v47, 0x30u);
  v50 = 0.0;
  v41 = dword_6BE63C + 6 * *(_WORD *)(*(_DWORD *)(v2 + 48) + 2 * v53);
  v66 = *(_WORD *)v41;
  v42 = *(_WORD *)(v41 + 2);
  v43 = *(_WORD *)(v41 + 4);
  v47 = (double)v66;
  v48 = (double)v42;
  v49 = (double)v43;
  memcpy((void *)(a2 + 96), &v47, 0x30u);
  v50 = 0.0;
  v44 = dword_6BE63C + 6 * *(_WORD *)(*(_DWORD *)(v2 + 48) + 2 * v54);
  v67 = *(_WORD *)v44;
  v45 = *(_WORD *)(v44 + 2);
  result = *(_WORD *)(v44 + 4);
  v47 = (double)v67;
  v48 = (double)v45;
  v49 = (double)result;
  memcpy((void *)(a2 + 144), &v47, 0x30u);
  return result;
}



//----- (0049DC28) --------------------------------------------------------
HRESULT __stdcall sub_49DC28(LPVOID *a1)
{
 return S_OK;
}

//----- (0049DC90) --------------------------------------------------------
int __thiscall sub_49DC90(int _this)
{
  int v1; // esi@1
  int v2; // eax@2
  signed int v3; // edi@4
  int v4; // eax@5
  int v5; // eax@7
  int v6; // eax@9
  int v7; // eax@11
  int v8; // eax@13
  int v9; // eax@15
  int v10; // eax@17
  int v11; // eax@20
  int v12; // eax@22
  int v13; // eax@24
  int v14; // eax@26
  int v15; // eax@28
  int v16; // eax@30
  int v17; // eax@32
  int v18; // eax@34
  int result; // eax@36

  v1 = _this;
  if ( !*(_DWORD *)_this )
  {
    v2 = *(_DWORD *)(_this + 32);
    if ( v2 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 76))(*(_DWORD *)(_this + 32));
      (*(void (__stdcall **)(_DWORD, _DWORD, signed int))(**(_DWORD **)(v1 + 32) + 80))(
        *(_DWORD *)(v1 + 32),
        *(_DWORD *)(v1 + 12),
        8);
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v1 + 32) + 40))(*(_DWORD *)(v1 + 32));
    }
  }
  v3 = 0;
  do
  {
    v4 = *(_DWORD *)(*(_DWORD *)(v1 + 28) + v3 + 20);
    if ( v4 )
    {
      operator_delete(*(_DWORD **)(*(_DWORD *)(v1 + 28) + v3 + 20));
      *(_DWORD *)(*(_DWORD *)(v1 + 28) + v3 + 20) = 0;
    }
    v5 = *(_DWORD *)(*(_DWORD *)(v1 + 28) + v3 + 24);
    if ( v5 )
    {
      operator_delete(*(_DWORD **)(*(_DWORD *)(v1 + 28) + v3 + 24));
      *(_DWORD *)(*(_DWORD *)(v1 + 28) + v3 + 24) = 0;
    }
    v6 = *(_DWORD *)(*(_DWORD *)(v1 + 28) + v3 + 28);
    if ( v6 )
    {
      operator_delete(*(_DWORD **)(*(_DWORD *)(v1 + 28) + v3 + 28));
      *(_DWORD *)(*(_DWORD *)(v1 + 28) + v3 + 28) = 0;
    }
    v7 = *(_DWORD *)(*(_DWORD *)(v1 + 28) + v3 + 32);
    if ( v7 )
    {
      operator_delete(*(_DWORD **)(*(_DWORD *)(v1 + 28) + v3 + 32));
      *(_DWORD *)(*(_DWORD *)(v1 + 28) + v3 + 32) = 0;
    }
    v8 = *(_DWORD *)(*(_DWORD *)(v1 + 28) + v3 + 4);
    if ( v8 )
    {
      operator_delete(*(_DWORD **)(*(_DWORD *)(v1 + 28) + v3 + 4));
      *(_DWORD *)(*(_DWORD *)(v1 + 28) + v3 + 4) = 0;
    }
    v9 = *(_DWORD *)(*(_DWORD *)(v1 + 28) + v3 + 8);
    if ( v9 )
    {
      operator_delete(*(_DWORD **)(*(_DWORD *)(v1 + 28) + v3 + 8));
      *(_DWORD *)(*(_DWORD *)(v1 + 28) + v3 + 8) = 0;
    }
    v10 = *(_DWORD *)(*(_DWORD *)(v1 + 28) + v3 + 12);
    if ( v10 )
    {
      operator_delete(*(_DWORD **)(*(_DWORD *)(v1 + 28) + v3 + 12));
      *(_DWORD *)(*(_DWORD *)(v1 + 28) + v3 + 12) = 0;
    }
    v3 += 40;
  }
  while ( v3 < 160 );
  v11 = *(_DWORD *)(v1 + 28);
  if ( v11 )
  {
    operator_delete(*(_DWORD **)(v1 + 28));
    *(_DWORD *)(v1 + 28) = 0;
  }
  v12 = *(_DWORD *)(v1 + 60);
  if ( v12 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v12 + 8))(*(_DWORD *)(v1 + 60));
    *(_DWORD *)(v1 + 60) = 0;
  }
  v13 = *(_DWORD *)(v1 + 40);
  if ( v13 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v13 + 8))(*(_DWORD *)(v1 + 40));
    *(_DWORD *)(v1 + 40) = 0;
  }
  v14 = *(_DWORD *)(v1 + 52);
  if ( v14 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v14 + 8))(*(_DWORD *)(v1 + 52));
    *(_DWORD *)(v1 + 52) = 0;
  }
  v15 = *(_DWORD *)(v1 + 56);
  if ( v15 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v15 + 8))(*(_DWORD *)(v1 + 56));
    *(_DWORD *)(v1 + 56) = 0;
  }
  v16 = *(_DWORD *)(v1 + 36);
  if ( v16 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v16 + 8))(*(_DWORD *)(v1 + 36));
    *(_DWORD *)(v1 + 36) = 0;
  }
  v17 = *(_DWORD *)(v1 + 44);
  if ( v17 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v17 + 8))(*(_DWORD *)(v1 + 44));
    *(_DWORD *)(v1 + 44) = 0;
  }
  v18 = *(_DWORD *)(v1 + 48);
  if ( v18 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v18 + 8))(*(_DWORD *)(v1 + 48));
    *(_DWORD *)(v1 + 48) = 0;
  }
  result = *(_DWORD *)(v1 + 32);
  if ( result )
  {
    result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)result + 8))(*(_DWORD *)(v1 + 32));
    *(_DWORD *)(v1 + 32) = 0;
  }
  return result;
}

//----- (0049EB79) --------------------------------------------------------
int __thiscall sub_49EB79(int _this)
{
  int v2; // esi@1
  int v3; // eax@1

  v2 = _this;
  mem_mng.DeleteBuffer( (void *)*(_DWORD *)(_this + 262200));
  sub_45271F(v2 + 262420);
  v3 = sub_45271F(v2 + 662444);
  sub_49FE05((BaseRender *)v2);//sub_49FE05(v3, v2);
  *(_DWORD *)(v2 + 262232) = 1;
  compile_error;//nullsub_1(v2 + 662444);
  compile_error;//return nullsub_1(v2 + 262420);
  return 0;
}

//----- (0049ECC4) --------------------------------------------------------
int __thiscall Render_sub_49ECC4(int _this)
{
  int v2; // ecx@1
  int v3; // ecx@4

  v2 = *(_DWORD *)(_this + 262280);
  if ( v2 )
  {
    if ( *(_DWORD *)(_this + 262416) )
      RenderD3D3_ClearTarget((RenderD3D3 *)v2, 1, 0, 0, 0.0);
  }
  else
  {
    v3 = *(_DWORD *)(_this + 16) * *(_DWORD *)(_this + 20) >> 1;
    memset((void *)pD3DRenderer->pTargetSurface, 0, 4 * v3);
  }
  return 0;
}

//----- (0049EDB6) --------------------------------------------------------
void __thiscall Render_sub_49EDB6(int _this)
{
  __int16 v1; // di@1
  int v2; // esi@1
  int v3; // eax@4
  int v4; // ecx@4
  int v5; // eax@8
  FILE *v6; // edi@10
  int v7; // eax@11
  int v8; // ecx@11
  int v9; // eax@13
  int v10; // ecx@15
  unsigned __int8 v11; // dl@15
  signed int v12; // eax@18
  char v13; // zf@27
  int v14; // eax@29
  char v15; // [sp+Ch] [bp-158h]@10
  __int16 v16; // [sp+44h] [bp-120h]@10
  int Dst; // [sp+48h] [bp-11Ch]@7
  int v18; // [sp+58h] [bp-10Ch]@8
  int v19; // [sp+6Ch] [bp-F8h]@8
  char v20; // [sp+C4h] [bp-A0h]@10
  char Filename[40]; // [sp+F4h] [bp-70h]@3
  int v22; // [sp+11Ch] [bp-48h]@14
  int v23; // [sp+120h] [bp-44h]@14
  int v24; // [sp+124h] [bp-40h]@11
  FILE *File; // [sp+128h] [bp-3Ch]@3
  int v26; // [sp+12Ch] [bp-38h]@4
  char Str; // [sp+130h] [bp-34h]@10
  char v28; // [sp+131h] [bp-33h]@10
  char v29; // [sp+132h] [bp-32h]@10
  char v30; // [sp+133h] [bp-31h]@10
  __int16 v31; // [sp+134h] [bp-30h]@10
  __int16 v32; // [sp+136h] [bp-2Eh]@10
  __int16 v33; // [sp+138h] [bp-2Ch]@10
  __int16 v34; // [sp+13Ah] [bp-2Ah]@10
  __int16 v35; // [sp+13Ch] [bp-28h]@10
  __int16 v36; // [sp+13Eh] [bp-26h]@10
  char v37; // [sp+140h] [bp-24h]@10
  char v38; // [sp+141h] [bp-23h]@10
  __int16 v39; // [sp+142h] [bp-22h]@10
  __int16 v40; // [sp+144h] [bp-20h]@10
  int v41; // [sp+148h] [bp-1Ch]@10
  int v42; // [sp+14Ch] [bp-18h]@8
  int v43; // [sp+150h] [bp-14h]@4
  int v44; // [sp+154h] [bp-10h]@4
  char v45; // [sp+15Ah] [bp-Ah]@25
  unsigned __int8 v46; // [sp+15Bh] [bp-9h]@17
  int i; // [sp+15Ch] [bp-8h]@10
  unsigned __int8 v48; // [sp+163h] [bp-1h]@17

  v2 = _this;
  v1 = 0;
  if ( !*(_DWORD *)(_this + 262280) || *(_DWORD *)(_this + 262416) )
  {
    wsprintfA(Filename, "screen%0.2i.pcx", dword_4EFA80++ % 100);
    File = fopen(Filename, "wb");
    if ( File )
    {
      v3 = *(_DWORD *)(v2 + 16);
      v4 = *(_DWORD *)(v2 + 20);
      v26 = v3;
      v43 = v4;
      v44 = v3;
      if ( v3 & 1 )
        v44 = v3 + 1;
      if ( *(_DWORD *)(v2 + 262280) )
      {
        memset(&Dst, 0, 0x7Cu);
        Dst = 124;
        if ( !LockSurface_DDraw4(pD3DRenderer->pdds4_BackBuffer, (DDSURFACEDESC2 *)&Dst, 1) )
          return;
        v42 = v19;
        v5 = v18 >> 1;
        v1 = 0;
      }
      else
      {
        pD3DRenderer->BeginScene();
        v42 = (int)pD3DRenderer->pTargetSurface;
        v5 = pD3DRenderer->uTargetSurfacePitch;
      }
      i = v5;
      v33 = v26 - 1;
      v31 = v1;
      v34 = v43 - 1;
      v32 = v1;
      v39 = v44;
      memset(&v20, 0, 0x30u);
      memset(&v15, 0, 0x38u);
      v37 = 0;
      Str = 10;
      v16 = 0;
      v6 = File;
      v28 = 5;
      v29 = 1;
      v30 = 8;
      v35 = 75;
      v36 = 75;
      v38 = 3;
      v40 = 1;
      locked_fwrite(&Str, 1u, 1u, File);
      locked_fwrite(&v28, 1u, 1u, v6);
      locked_fwrite(&v29, 1u, 1u, v6);
      locked_fwrite(&v30, 1u, 1u, v6);
      locked_fwrite(&v31, 2, 1u, v6);
      locked_fwrite(&v32, 2, 1u, v6);
      locked_fwrite(&v33, 2, 1u, v6);
      locked_fwrite(&v34, 2, 1u, v6);
      locked_fwrite(&v35, 2, 1u, v6);
      locked_fwrite(&v36, 2, 1u, v6);
      locked_fwrite(&v20, 0x30u, 1u, v6);
      locked_fwrite(&v37, 1u, 1u, v6);
      locked_fwrite(&v38, 1u, 1u, v6);
      locked_fwrite(&v39, 2, 1u, v6);
      locked_fwrite(&v40, 2, 1u, v6);
      locked_fwrite(&v15, 0x3Au, 1u, v6);
      v41 = (int)mem_mng.AllocatedNamedBuffer( 0, 3 * v26 + 6, 0);
      if ( v43 > 0 )
      {
        v8 = v44;
        File = (FILE *)v43;
        v43 = 3 * v44;
        v24 = 2 * i;
        v7 = v42;
        while ( 1 )
        {
          i = v7;
          v9 = 0;
          if ( v26 > 0 )
          {
            v23 = v41 + v8;
            v22 = v41 + 2 * v44;
            do
            {
              *(_BYTE *)(v9 + v41) = (*(_DWORD *)(v2 + 262360) & *(_WORD *)i) >> (*(_BYTE *)(v2 + 262352)
                                                                                + *(_BYTE *)(v2 + 262356)
                                                                                + (unsigned __int8)*(_DWORD *)(v2 + 262348)
                                                                                - 8);
              *(_BYTE *)(v23 + v9) = (*(_DWORD *)(v2 + 262364) & *(_WORD *)i) >> (*(_BYTE *)(v2 + 262356)
                                                                                + *(_BYTE *)(v2 + 262352)
                                                                                - 8);
              v10 = i;
              v11 = *(_BYTE *)(v2 + 262368);
              i += 2;
              *(_BYTE *)(v22 + v9++) = (*(_BYTE *)v10 & v11) << (8 - *(_BYTE *)(v2 + 262356));
            }
            while ( v9 < v26 );
          }
          for ( i = 0; i < v43; i += v48 )
          {
            v48 = 1;
            v46 = *(_BYTE *)(i + v41);
            do
            {
              v12 = i + v48;
              if ( *(_BYTE *)(v12 + v41) != v46 )
                break;
              if ( !(v12 % v44) )
                break;
              ++v48;
            }
            while ( v48 < 0x3Fu );
            if ( i + v48 > v43 )
              v48 = 3 * v44 - i;
            if ( v48 > 1u || v46 >= 0xC0u )
            {
              v45 = v48 | 0xC0;
              locked_fwrite(&v45, 1u, 1u, v6);
            }
            locked_fwrite(&v46, 1u, 1u, v6);
          }
          v7 = v24 + v42;
          v13 = File == (FILE *)1;
          File = (FILE *)((char *)File - 1);
          v42 += v24;
          if ( v13 )
            break;
          v8 = v44;
        }
      }
      if ( *(_DWORD *)(v2 + 262280) )
      {
        v14 = (*(int (__stdcall **)(int, _DWORD))(*(_DWORD *)pD3DRenderer->pdds4_BackBuffer + 128))((int)pD3DRenderer->pdds4_BackBuffer, 0);
        CheckHRESULT((void **)&v24, v14, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 0x23Fu, 0);
      }
      else
      {
        pD3DRenderer->EndScene();
      }
      mem_mng.DeleteBuffer( (void *)(void *)v41);
      fclose(v6);
    }
  }
}

//----- (0049F1BC) --------------------------------------------------------
void __thiscall Render_sub_49F1BC(int _this, const char *Filename)
{
  __int16 v2; // di@1
  int v3; // esi@1
  int v4; // eax@4
  char *v5; // ecx@4
  int v6; // eax@8
  FILE *v7; // edi@10
  int v8; // eax@11
  int v9; // ecx@11
  int v10; // eax@13
  char *v11; // ecx@15
  unsigned __int8 v12; // dl@15
  signed int v13; // eax@18
  char v14; // zf@27
  int v15; // eax@29
  char v16; // [sp+Ch] [bp-12Ch]@10
  __int16 v17; // [sp+44h] [bp-F4h]@10
  int Dst; // [sp+48h] [bp-F0h]@7
  int v19; // [sp+58h] [bp-E0h]@8
  int v20; // [sp+6Ch] [bp-CCh]@8
  char v21; // [sp+C4h] [bp-74h]@10
  int v22; // [sp+F4h] [bp-44h]@11
  int v23; // [sp+F8h] [bp-40h]@14
  int v24; // [sp+FCh] [bp-3Ch]@11
  int v25; // [sp+100h] [bp-38h]@4
  FILE *File; // [sp+104h] [bp-34h]@3
  char Str; // [sp+108h] [bp-30h]@10
  char v28; // [sp+109h] [bp-2Fh]@10
  char v29; // [sp+10Ah] [bp-2Eh]@10
  char v30; // [sp+10Bh] [bp-2Dh]@10
  __int16 v31; // [sp+10Ch] [bp-2Ch]@10
  __int16 v32; // [sp+10Eh] [bp-2Ah]@10
  __int16 v33; // [sp+110h] [bp-28h]@10
  __int16 v34; // [sp+112h] [bp-26h]@10
  __int16 v35; // [sp+114h] [bp-24h]@10
  __int16 v36; // [sp+116h] [bp-22h]@10
  char v37; // [sp+118h] [bp-20h]@10
  char v38; // [sp+119h] [bp-1Fh]@10
  __int16 v39; // [sp+11Ah] [bp-1Eh]@10
  __int16 v40; // [sp+11Ch] [bp-1Ch]@10
  int v41; // [sp+120h] [bp-18h]@10
  int v42; // [sp+124h] [bp-14h]@8
  int v43; // [sp+128h] [bp-10h]@4
  char v44; // [sp+12Fh] [bp-9h]@25
  int i; // [sp+130h] [bp-8h]@10
  unsigned __int8 v46; // [sp+137h] [bp-1h]@17

  v3 = _this;
  v2 = 0;
  if ( !*(_DWORD *)(_this + 262280) || *(_DWORD *)(_this + 262416) )
  {
    ++dword_4EFA84;
    File = fopen(Filename, "wb");
    if ( File )
    {
      v4 = *(_DWORD *)(v3 + 16);
      v5 = *(char **)(v3 + 20);
      v25 = v4;
      Filename = v5;
      v43 = v4;
      if ( v4 & 1 )
        v43 = v4 + 1;
      if ( *(_DWORD *)(v3 + 262280) )
      {
        memset(&Dst, 0, 0x7Cu);
        Dst = 124;
        if ( !LockSurface_DDraw4(pD3DRenderer->pdds4_BackBuffer, (DDSURFACEDESC2 *)&Dst, 1) )
          return;
        v42 = v20;
        v6 = v19 >> 1;
        v2 = 0;
      }
      else
      {
        pD3DRenderer->BeginScene();
        v42 = (int)pD3DRenderer->pTargetSurface;
        v6 = pD3DRenderer->uTargetSurfacePitch;
      }
      i = v6;
      v33 = v25 - 1;
      v31 = v2;
      v34 = (_WORD)Filename - 1;
      v32 = v2;
      v39 = v43;
      memset(&v21, 0, 0x30u);
      memset(&v16, 0, 0x38u);
      v37 = 0;
      Str = 10;
      v17 = 0;
      v7 = File;
      v28 = 5;
      v29 = 1;
      v30 = 8;
      v35 = 75;
      v36 = 75;
      v38 = 3;
      v40 = 1;
      locked_fwrite(&Str, 1u, 1u, File);
      locked_fwrite(&v28, 1u, 1u, v7);
      locked_fwrite(&v29, 1u, 1u, v7);
      locked_fwrite(&v30, 1u, 1u, v7);
      locked_fwrite(&v31, 2, 1u, v7);
      locked_fwrite(&v32, 2, 1u, v7);
      locked_fwrite(&v33, 2, 1u, v7);
      locked_fwrite(&v34, 2, 1u, v7);
      locked_fwrite(&v35, 2, 1u, v7);
      locked_fwrite(&v36, 2, 1u, v7);
      locked_fwrite(&v21, 0x30u, 1u, v7);
      locked_fwrite(&v37, 1u, 1u, v7);
      locked_fwrite(&v38, 1u, 1u, v7);
      locked_fwrite(&v39, 2, 1u, v7);
      locked_fwrite(&v40, 2, 1u, v7);
      locked_fwrite(&v16, 0x3Au, 1u, v7);
      v41 = (int)mem_mng.AllocatedNamedBuffer( 0, 3 * v25 + 6, 0);
      if ( (signed int)Filename > 0 )
      {
        v9 = v43;
        File = (FILE *)Filename;
        v24 = 3 * v43;
        v22 = 2 * i;
        v8 = v42;
        while ( 1 )
        {
          Filename = (const char *)v8;
          v10 = 0;
          if ( v25 > 0 )
          {
            i = v41 + v9;
            v23 = v41 + 2 * v43;
            do
            {
              *(_BYTE *)(v10 + v41) = (*(_DWORD *)(v3 + 262360) & *(_WORD *)Filename) >> (*(_BYTE *)(v3 + 262352)
                                                                                        + *(_BYTE *)(v3 + 262356)
                                                                                        + (unsigned __int8)*(_DWORD *)(v3 + 262348)
                                                                                        - 8);
              *(_BYTE *)(i + v10) = (*(_DWORD *)(v3 + 262364) & *(_WORD *)Filename) >> (*(_BYTE *)(v3 + 262356)
                                                                                      + *(_BYTE *)(v3 + 262352)
                                                                                      - 8);
              v11 = (char *)Filename;
              v12 = *(_BYTE *)(v3 + 262368);
              Filename += 2;
              *(_BYTE *)(v23 + v10++) = ((unsigned __int8)*v11 & v12) << (8 - *(_BYTE *)(v3 + 262356));
            }
            while ( v10 < v25 );
          }
          for ( i = 0; i < v24; i += BYTE3(Filename) )
          {
            BYTE3(Filename) = 1;
            v46 = *(_BYTE *)(i + v41);
            do
            {
              v13 = i + BYTE3(Filename);
              if ( *(_BYTE *)(v13 + v41) != v46 )
                break;
              if ( !(v13 % v43) )
                break;
              Filename += 16777216;
            }
            while ( BYTE3(Filename) < 0x3Fu );
            if ( i + BYTE3(Filename) > v24 )
              BYTE3(Filename) = 3 * v43 - i;
            if ( BYTE3(Filename) > 1u || v46 >= 0xC0u )
            {
              v44 = BYTE3(Filename) | 0xC0;
              locked_fwrite(&v44, 1u, 1u, v7);
            }
            locked_fwrite(&v46, 1u, 1u, v7);
          }
          v8 = v22 + v42;
          v14 = File == (FILE *)1;
          File = (FILE *)((char *)File - 1);
          v42 += v22;
          if ( v14 )
            break;
          v9 = v43;
        }
      }
      if ( *(_DWORD *)(v3 + 262280) )
      {
        v15 = (*(int (__stdcall **)(int, _DWORD))(*(_DWORD *)pD3DRenderer->pdds4_BackBuffer + 128))((int)pD3DRenderer->pdds4_BackBuffer, 0);
        CheckHRESULT((void **)&Filename, v15, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Screen16.cpp", 0x2E3u, 0);
      }
      else
      {
        pD3DRenderer->EndScene();
      }
      mem_mng.DeleteBuffer( (void *)(void *)v41);
      fclose(v7);
    }
  }
}

//----- (0049F8B5) --------------------------------------------------------
FILE *__thiscall sub_49F8B5(void *_this, char *Filename, int a3, int a4, int a5)
{
  FILE *result; // eax@1
  void *v6; // esi@1
  FILE *v7; // edi@4
  int v8; // eax@5
  int v9; // ecx@5
  int v10; // eax@7
  int v11; // ecx@9
  signed int v12; // eax@12
  char v13; // zf@21
  char v14; // [sp+4h] [bp-A0h]@4
  __int16 v15; // [sp+3Ch] [bp-68h]@4
  char v16; // [sp+40h] [bp-64h]@4
  int v17; // [sp+70h] [bp-34h]@5
  int v18; // [sp+74h] [bp-30h]@5
  int v19; // [sp+78h] [bp-2Ch]@5
  int v20; // [sp+7Ch] [bp-28h]@5
  char Str; // [sp+80h] [bp-24h]@4
  char v22; // [sp+81h] [bp-23h]@4
  char v23; // [sp+82h] [bp-22h]@4
  char v24; // [sp+83h] [bp-21h]@4
  __int16 v25; // [sp+84h] [bp-20h]@4
  __int16 v26; // [sp+86h] [bp-1Eh]@4
  __int16 v27; // [sp+88h] [bp-1Ch]@4
  __int16 v28; // [sp+8Ah] [bp-1Ah]@4
  __int16 v29; // [sp+8Ch] [bp-18h]@4
  __int16 v30; // [sp+8Eh] [bp-16h]@4
  char v31; // [sp+90h] [bp-14h]@4
  char v32; // [sp+91h] [bp-13h]@4
  __int16 v33; // [sp+92h] [bp-12h]@4
  __int16 v34; // [sp+94h] [bp-10h]@4
  int v35; // [sp+98h] [bp-Ch]@4
  int v36; // [sp+9Ch] [bp-8h]@2
  int i; // [sp+A0h] [bp-4h]@8
  FILE *v38; // [sp+ACh] [bp+8h]@1
  FILE *v39; // [sp+ACh] [bp+8h]@4

  v6 = _this;
  result = fopen(Filename, "wb");
  v38 = result;
  if ( result )
  {
    v36 = a4;
    if ( a4 & 1 )
      v36 = a4 + 1;
    v25 = 0;
    v26 = 0;
    v27 = a4 - 1;
    v28 = a5 - 1;
    v33 = v36;
    memset(&v16, 0, 0x30u);
    v31 = 0;
    memset(&v14, 0, 0x38u);
    v15 = 0;
    Str = 10;
    v22 = 5;
    v23 = 1;
    v24 = 8;
    v29 = 75;
    v30 = 75;
    v32 = 3;
    v34 = 1;
    locked_fwrite(&Str, 1u, 1u, v39);
    v7 = v39;
    locked_fwrite(&v22, 1u, 1u, v39);
    locked_fwrite(&v23, 1u, 1u, v7);
    locked_fwrite(&v24, 1u, 1u, v7);
    locked_fwrite(&v25, 2, 1u, v7);
    locked_fwrite(&v26, 2, 1u, v7);
    locked_fwrite(&v27, 2, 1u, v7);
    locked_fwrite(&v28, 2, 1u, v7);
    locked_fwrite(&v29, 2, 1u, v7);
    locked_fwrite(&v30, 2, 1u, v7);
    locked_fwrite(&v16, 0x30u, 1u, v7);
    locked_fwrite(&v31, 1u, 1u, v7);
    locked_fwrite(&v32, 1u, 1u, v7);
    locked_fwrite(&v33, 2, 1u, v7);
    locked_fwrite(&v34, 2, 1u, v7);
    locked_fwrite(&v14, 0x3Au, 1u, v7);
    v35 = (int)mem_mng.AllocatedNamedBuffer( 0, 3 * a4 + 6, 0);
    if ( a5 > 0 )
    {
      v9 = v36;
      v18 = a5;
      v20 = 3 * v36;
      v17 = 2 * a4;
      v8 = a3;
      v19 = a3;
      while ( 1 )
      {
        a5 = v8;
        v10 = 0;
        if ( a4 > 0 )
        {
          a3 = v35 + v9;
          i = v35 + 2 * v36;
          do
          {
            *(_BYTE *)(v10 + v35) = (*((_DWORD *)v6 + 65590) & *(_WORD *)a5) >> (*((_BYTE *)v6 + 262352)
                                                                               + *((_BYTE *)v6 + 262356)
                                                                               + (unsigned __int8)*((_DWORD *)v6 + 65587)
                                                                               - 8);
            *(_BYTE *)(a3 + v10) = (*((_DWORD *)v6 + 65591) & *(_WORD *)a5) >> (*((_BYTE *)v6 + 262356)
                                                                              + *((_BYTE *)v6 + 262352)
                                                                              - 8);
            v11 = a5;
            a5 += 2;
            *(_BYTE *)(i + v10++) = (*((_BYTE *)v6 + 262368) & *(_BYTE *)v11) << (8 - *((_BYTE *)v6 + 262356));
          }
          while ( v10 < a4 );
        }
        for ( i = 0; i < v20; i += BYTE3(a5) )
        {
          BYTE3(a5) = 1;
          BYTE3(Filename) = *(_BYTE *)(i + v35);
          do
          {
            v12 = i + BYTE3(a5);
            if ( *(_BYTE *)(v12 + v35) != BYTE3(Filename) )
              break;
            if ( !(v12 % v36) )
              break;
            a5 += 16777216;
          }
          while ( BYTE3(a5) < 0x3Fu );
          if ( i + BYTE3(a5) > v20 )
            BYTE3(a5) = 3 * v36 - i;
          if ( BYTE3(a5) > 1u || BYTE3(Filename) >= 0xC0u )
          {
            BYTE3(a3) = BYTE3(a5) | 0xC0;
            locked_fwrite((char *)&a3 + 3, 1u, 1u, v7);
          }
          locked_fwrite((char *)&Filename + 3, 1u, 1u, v7);
        }
        v8 = v17 + v19;
        v13 = v18-- == 1;
        v19 += v17;
        if ( v13 )
          break;
        v9 = v36;
      }
    }
    mem_mng.DeleteBuffer( (void *)(void *)v35);
    result = (FILE *)fclose(v7);
  }
  return result;
}

//----- (0049FC23) --------------------------------------------------------
function_error;//int __usercall sub_49FC23<eax>(int a1<eax>, int a2<ecx>)
int sub_49FC23(int a1, int a2)
{
  int result = 0; // eax@1
  int v3; // esi@1

  v3 = a2;
//  sub_49FE05((BaseRender *)a2);
  *(_DWORD *)(v3 + 262232) = 1;
  return result;
}

//----- (0049FD3A) --------------------------------------------------------
function_error;//void __usercall Render_sub_49FD3A(int a1<ecx>, int a2<edi>)
void Render_sub_49FD3A(int a1, int a2)
{
  int v2; // esi@1
  int v3; // eax@6
  int v4; // ST0C_4@6
  int v5; // [sp+8h] [bp-10h]@6
  int v6; // [sp+Ch] [bp-Ch]@6
  int v7; // [sp+10h] [bp-8h]@6
  int v8; // [sp+14h] [bp-4h]@6

  v2 = a1;
  if ( *(_DWORD *)(a1 + 262280) )
  {
    if ( (*(int (__stdcall **)(_DWORD, int))(**(_DWORD **)(a1 + 262288) + 96))(*(_DWORD *)(a1 + 262288), a2) == -2005532222 )
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v2 + 262288) + 108))(*(_DWORD *)(v2 + 262288));
    if ( (*(int (__cdecl **)(_DWORD))(**(_DWORD **)(v2 + 262292) + 96))(*(_DWORD *)(v2 + 262292)) == -2005532222 )
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v2 + 262292) + 108))(*(_DWORD *)(v2 + 262292));
    v3 = *(_DWORD *)(v2 + 262292);
    v4 = *(_DWORD *)(v2 + 262288);
    v6 = 0;
    v8 = 480;
    v5 = 0;
    v7 = 640;
    (*(void (__stdcall **)(int, _DWORD, _DWORD, int, int *, signed int))(*(_DWORD *)v3 + 28))(v3, 0, 0, v4, &v5, 16);
  }
}

//----- (004A169E) --------------------------------------------------------
char __thiscall sub_4A169E(void *_this)
{
  return *(_DWORD *)_this == 0;
}

//----- (004A16A5) --------------------------------------------------------
char __cdecl sub_4A16A5()
{
  char v0; // zf@4

  if ( dword_F79D7C != 2 || dword_F79D70 != 4 )
  {
    if ( !pD3DRenderer->pdds4_BackBuffer )
      return 0;
    v0 = pD3DRenderer->pdds4_FrontBuffer == 0;
  }
  else
  {
    if ( !pD3DRenderer->pdds2_BackBuffer )
      return 0;
    v0 = pD3DRenderer->pdds2_FrontBuffer == 0;
  }
  if ( !v0 )
    return 1;
  return 0;
}

//----- (004A184C) --------------------------------------------------------
int __thiscall Render_sub_4A184C(void *_this)
{
  int v1; // esi@2
  int result; // eax@4
  int v3; // [sp-4h] [bp-8h]@4

  if ( dword_F79D7C != 2 || (v1 = (int)((char *)_this + 262308), dword_F79D70 != 4) )
    v1 = (int)((char *)_this + 262292);
  result = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)v1 + 96))(*(_DWORD *)v1);
  if ( result == -2005532222 )
    result = (*(int (__stdcall **)(int))(**(_DWORD **)v1 + 108))(v3);
  return result;
}

//----- (004A19D8) --------------------------------------------------------
int __fastcall sub_4A19D8(unsigned int a1, unsigned int a2)
{
  float v3; // ST24_4@1
  double v4; // ST10_8@1
  int v5; // ST1C_4@1
  float v6; // ST24_4@1
  double v7; // ST10_8@1
  unsigned __int8 v8; // ST20_1@1
  float v9; // ST24_4@1
  double v10; // ST10_8@1
  float v11; // ST24_4@1
  double v12; // ST08_8@1

  v3 = (double)(a1 >> 24) * 0.003921568859368563 * (double)(a2 >> 24) * 0.003921568859368563 * 255.0;
  v4 = v3 + 6.755399441055744e15;
  v5 = LODWORD(v4);
  v6 = (double)((a1 >> 16) & 0xFFi64)
     * 0.003921568859368563
     * (double)((a2 >> 16) & 0xFFi64)
     * 0.003921568859368563
     * 255.0;
  v7 = v6 + 6.755399441055744e15;
  v8 = LOBYTE(v7);
  v9 = (double)(unsigned __int16)((_WORD)a1 >> 8)
     * 0.003921568859368563
     * (double)(unsigned __int16)((_WORD)a2 >> 8)
     * 0.003921568859368563
     * 255.0;
  v10 = v9 + 6.755399441055744e15;
  v11 = (double)(a1 & 0xFFi64) * 0.003921568859368563 * (double)(unsigned __int8)a2 * 0.003921568859368563 * 255.0;
  v12 = v11 + 6.755399441055744e15;
  return LOBYTE(v12) | ((LOBYTE(v10) | (((v5 << 8) | v8) << 8)) << 8);
}

//----- (004A1B22) --------------------------------------------------------
int __stdcall sub_4A1B22_Billboard_ProbablyAddToListAndSortByZOrder(float a1)
{
  int v1; // ebx@1
  int v3; // ecx@5
  int v4; // esi@5
  double v5; // st7@5
  int v6; // edx@6
  int *v7; // ecx@12
  int v8; // eax@16
  int v10; // eax@21
  struct RenderBillboardD3D3 *v11; // edi@21

 v1 = pD3DRenderer->uNumBillboardsToDraw;
 if (pD3DRenderer->uNumBillboardsToDraw >= 999)
   return 0;

 if (!pD3DRenderer->uNumBillboardsToDraw)
 {
  pD3DRenderer->uNumBillboardsToDraw = 1;
  return 0;
 }

  v5 = a1;
  v4 = pD3DRenderer->uNumBillboardsToDraw;
  v3 = 0;
  if ( pD3DRenderer->uNumBillboardsToDraw <= 0 )
  {
    v6 = a1;
  }
  else
  {
    do
    {
      v6 = v3 + (v4 - v3) / 2;
      if ( v5 <= pBillboardRenderListD3D3[(v3 + (v4 - v3) / 2)].flt_000088)
        v4 = v3 + (v4 - v3) / 2;
      else
        v3 = v6 + 1;
    }
    while ( v3 < v4 );
  }
  v7 = (int *)&pBillboardRenderListD3D3[v6].flt_000088;
  if ( v5 > *(float *)v7 )
  {
    if ( v6 == pD3DRenderer->uNumBillboardsToDraw - 1 )
    {
      v6 = pD3DRenderer->uNumBillboardsToDraw;
    }
    else
    {
      if ( pD3DRenderer->uNumBillboardsToDraw > v6 )
      {
        v11 = &pBillboardRenderListD3D3[pD3DRenderer->uNumBillboardsToDraw];
        v8 = pD3DRenderer->uNumBillboardsToDraw - v6;
        do
        {
        memcpy(v11, v11 - 1, sizeof(struct RenderBillboardD3D3));
          v11--;
          --v8;
        }
        while ( v8 );
      }
      ++v6;
    }
LABEL_23:
    pD3DRenderer->uNumBillboardsToDraw = v1 + 1;
    return v6;
  }
  if ( v5 <= *(float *)v7 )
  {
    if ( pD3DRenderer->uNumBillboardsToDraw > v6 )
    {
      v11 = &pBillboardRenderListD3D3[pD3DRenderer->uNumBillboardsToDraw];
      v10 = pD3DRenderer->uNumBillboardsToDraw - v6;
      do
      {
        memcpy(v11, v11 - 1, sizeof(struct RenderBillboardD3D3));
        v11--;
        --v10;
      }
      while ( v10 );
    }
    goto LABEL_23;
  }
  return v6;
}

//----- (004A1C1E) --------------------------------------------------------
void D3D_DoRenderBillboards()
{
 int v0;
 struct RenderBillboardD3D3 *v1;
  unsigned int v4; // eax@7
 int i;

 pD3DRenderer->pRenderD3D3->pDevice->SetTextureStageState(0, D3DTSS_ADDRESS, 3);
 //
 runtime_warning(alpha blend was previously set to true but didnt work. investigate)
 pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, true);
 pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_ZWRITEENABLE, false);
 pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_CULLMODE, D3DCULL_NONE);
  
 v0 = -1;
 for (i = 1; i <= pD3DRenderer->uNumBillboardsToDraw; ++i)
 {
  v1 = &pBillboardRenderListD3D3[pD3DRenderer->uNumBillboardsToDraw - i];

  pD3DRenderer->pRenderD3D3->pDevice->SetTexture(0, v1->pTexture);
  if (v1->int_00008C != v0)
  {
   v0 = v1->int_00008C;
   sub_4A1DA8_SetupBillboardBlendOptions(v0);
  }

  pD3DRenderer->pRenderD3D3->pDevice->DrawPrimitive(D3DPT_TRIANGLEFAN, D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1, v1->pQuad, v1->uNumVertices, D3DDP_DONOTUPDATEEXTENTS | D3DDP_DONOTLIGHT);
 }

 if ( dword_EF52B0 )
 {
  dword_EF52B0 = 0;
  pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_FOGENABLE, true);
  v4 = sub_47C370();
  pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_FOGCOLOR, v4 & 0xFFFFFF);
  pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_FOGTABLEMODE, 0);
 }

 pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_CULLMODE, 2);
 pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_ZWRITEENABLE, 1);
 pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, 0);
 pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_SRCBLEND, 2);
 pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_DESTBLEND, 1);
 pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_DITHERENABLE, 1);
}

//----- (004A1DA8) --------------------------------------------------------
void __fastcall sub_4A1DA8_SetupBillboardBlendOptions(signed int a1)
{
  unsigned int v3; // eax@9

  if ( !a1 )
  {
    if ( dword_EF52B0 )
    {
      dword_EF52B0 = 0;
      pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_FOGENABLE, 1);
      v3 = sub_47C370();
      pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_FOGCOLOR, v3 & 0xFFFFFF);
      pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_FOGTABLEMODE, 0);
    }

    pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_SRCBLEND, D3DBLEND_SRCALPHA);
    pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_DESTBLEND, D3DBLEND_INVSRCALPHA);
    pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_DITHERENABLE, false);
  }
  if ( a1 > 0 && a1 <= 3 )
  {
    if ( pD3DRenderer->bUsingSpecular )
    {
      if ( !dword_EF52B0 )
      {
        dword_EF52B0 = 1;
        pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_FOGENABLE, 0);
      }
    }
    pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_SRCBLEND, D3DBLEND_ONE);
    pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_DESTBLEND, D3DBLEND_ONE);
    pD3DRenderer->pRenderD3D3->pDevice->SetRenderState(D3DRENDERSTATE_DITHERENABLE, true);
  }
}

//----- (004A1E9D) --------------------------------------------------------
/*int __cdecl sub_4A1E9D()
{
  return pD3DRenderer->uNumBillboardsToDraw;
}*/

//----- (004A1EA3) --------------------------------------------------------
int __stdcall sub_4A1EA3(int a1)
{
  return pBillboardRenderListD3D3[a1].uParentBillboardID;
}

//----- (004A2031) --------------------------------------------------------
signed int __stdcall sub_4A2031(float a1, int a2, int a3, int a4, int a5)
{
  return sub_47C4FC_GetActorTintColor(a2, a3, a1, a4, a5);
}

//----- (004A2ED5) --------------------------------------------------------
void __thiscall Render_sub_4A2ED5(int _this, signed int a2, int a3, int a4)
{
  signed int v4; // edi@2
  int v5; // eax@3
  int v6; // edx@5
  _UNKNOWN *v7; // eax@6
  _UNKNOWN *v8; // ecx@6
  double v9; // st6@7
  int v10; // ebx@7
  int v11; // ebx@7

  if ( *(_DWORD *)(_this + 262412) )
  {
    v4 = a2;
    if ( a2 >= 3 )
    {
      (*(void (__stdcall **)(_DWORD, _DWORD, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(_this + 262280) + 56)
                                                                    + 160))(
        *(_DWORD *)(*(_DWORD *)(_this + 262280) + 56),
        0,
        12,
        1);
      v5 = 31 - (*(_BYTE *)(a3 + 88) & 0x1F);
      if ( v5 < pClass51_global->dword_000CBC )
        v5 = pClass51_global->dword_000CBC;
      v6 = 8 * v5 | ((8 * v5 | (v5 << 11)) << 8);
      if ( a2 > 0 )
      {
        v7 = (char *)&pVertices->y;
        v8 = (char *)&array_507D30[0].flt_00001C;
        do
        {
          v9 = *((float *)v8 - 4) * 0.06175889447331429;
          v10 = *((_DWORD *)v8 - 1);
          *((_DWORD *)v7 + 4) = 0;
          *((_DWORD *)v7 - 1) = v10;
          *(_DWORD *)v7 = *(_DWORD *)v8;
          *((_DWORD *)v7 + 2) = *((_DWORD *)v8 + 1);
          *((_DWORD *)v7 + 5) = *((_DWORD *)v8 + 2);
          v11 = *((_DWORD *)v8 + 3);
          *((_DWORD *)v7 + 3) = v6;
          *((_DWORD *)v7 + 6) = v11;
          v8 = (char *)v8 + 48;
          v7 = (char *)v7 + 32;
          --v4;
          *((float *)v7 - 7) = 1.0 - 1.0 / v9;
        }
        while ( v4 );
      }
      (*(void (__fastcall **)(_DWORD, int, _DWORD, _DWORD, int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 152))(
        **(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56),
        v6,
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        0,
        a4);
      (*(void (__stdcall **)(_DWORD, signed int, signed int, _UNKNOWN *, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56)
                                                                                                + 112))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        6,
        452,
        (char *)pVertices,
        a2,
        28);
    }
  }
}

//----- (004A2FC0) --------------------------------------------------------
void __thiscall Render_sub_4A2FC0(int _this, signed int a2, int a3, signed int a4, signed int a5, int a6, signed int a7, int a8)
{
  int v8; // edi@1
  int v9; // esi@3
  signed int v10; // edx@8
  int v11; // eax@8
  int v12; // eax@8
  _UNKNOWN *v13; // eax@9
  _UNKNOWN *v14; // ecx@9
  double v15; // st6@10
  int v16; // edx@10
  signed int v17; // edx@10
  double v18; // st6@10
  char v19; // zf@10
  signed int v20; // edx@10
  int v21; // ecx@11
  int v22; // eax@11
  int v23; // eax@11
  int v24; // eax@11
  _UNKNOWN *v25; // eax@16
  signed int v26; // edx@16
  _UNKNOWN *v27; // ecx@16
  double v28; // st6@17
  int v29; // esi@17
  double v30; // st6@17
  char v31; // zf@17
  int v32; // edx@18
  signed int v33; // ecx@18
  int v34; // eax@18
  const char *v35; // ST24_4@18
  unsigned int v36; // ST28_4@18
  int v37; // ST2C_4@18
  int v38; // eax@18
  int v39; // eax@18
  int v40; // eax@18
  _UNKNOWN *v41; // eax@19
  int v42; // eax@21
  int v43; // ecx@21
  int v44; // eax@21
  int v45; // eax@21
  int v46; // eax@21
  int v47; // eax@21
  int v48; // eax@21
  int v49; // eax@21
  int v50; // eax@21
  int v51; // eax@21
  int v52; // eax@21
  _UNKNOWN *v53; // eax@23
  signed int v54; // edx@23
  _UNKNOWN *v55; // ecx@23
  double v56; // st6@24
  int v57; // esi@24
  double v58; // st6@24
  char v59; // zf@24
  int v60; // eax@25
  int v61; // eax@25
  const char *v62; // [sp-Ch] [bp-20h]@21
  unsigned int v63; // [sp-8h] [bp-1Ch]@21
  int v64; // [sp-4h] [bp-18h]@21
  float v65; // [sp+Ch] [bp-8h]@3
  int v66; // [sp+10h] [bp-4h]@4

  v8 = _this;
  if ( *(_DWORD *)(_this + 262412) )
  {
    if ( a2 >= 3 )
    {
      LODWORD(v65) = (int)pGame->class04_obj;
      v9 = *(_DWORD *)(LODWORD(v65) + 1587204);
      if ( v9 )
        v66 = -1;
      else
        v66 = a7;
      Game_sub_44EDE4((int)pGame, a3, (void **)&v66);
      if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3616) & 1 )
      {
        v11 = (*(int (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56) + 88))(
                *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                14,
                0);
        CheckHRESULT((void **)&a7, v11, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x5A3u, 0);
        v12 = (*(int (__stdcall **)(_DWORD, _DWORD, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56)
                                                                           + 160))(
                *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                0,
                12,
                1);
        CheckHRESULT((void **)&a7, v12, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x5A4u, 0);
        v10 = a2;
        if ( a2 > 0 )
        {
         v14 = (char *)&array_507D30[0].flt_00000C;
          v13 = (char *)&pVertices->y;
          a7 = a2;
          do
          {
            v15 = *(float *)v14 * 0.06175889447331429;
            v16 = *((_DWORD *)v14 + 3);
            *((_DWORD *)v13 + 4) = 0;
            *((_DWORD *)v13 - 1) = v16;
            *(_DWORD *)v13 = *((_DWORD *)v14 + 4);
            *((_DWORD *)v13 + 3) = v66;
            v17 = a5;
            v13 = (char *)v13 + 32;
            *((float *)v13 - 7) = 1.0 - 1.0 / v15;
            v18 = 1.0 / *(float *)v14;
            v14 = (char *)v14 + 48;
            v19 = a7-- == 1;
            *((float *)v13 - 6) = v18;
            a4 = *(_WORD *)(v17 + 24);
            v20 = a5;
            *((float *)v13 - 3) = *((float *)v14 - 6) / (double)a4;
            v10 = *(_WORD *)(v20 + 26);
            a4 = v10;
            *((float *)v13 - 2) = *((float *)v14 - 5) / (double)v10;
          }
          while ( !v19 );
        }
        v21 = **(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56);
        v22 = (*(int (__fastcall **)(int, signed int, _DWORD, _DWORD, signed int, signed int))(v21 + 160))(
                v21,
                v10,
                *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                0,
                12,
                1);
        CheckHRESULT((void **)&a5, v22, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x5B2u, 0);
        v23 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56) + 152))(
                *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                0,
                0);
        CheckHRESULT((void **)&a5, v23, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x5B3u, 0);
        v24 = (*(int (__stdcall **)(_DWORD, signed int, signed int, _UNKNOWN *, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56) + 112))(
                *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                6,
                452,
                (char *)pVertices,
                a2,
                28);
        CheckHRESULT((void **)&a2, v24, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x5B9u, 0);
        sub_45D74F_MessWithLight(pGame->class04_obj, -1, 0);
      }
      else
      {
        if ( !v9 || byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3616) & 2 )
        {
          if ( a2 > 0 )
          {
            v54 = a5;
            v55 = (char *)&array_507D30[0].flt_00000C;
            v53 = (char *)&pVertices->y;
            a5 = a2;
            do
            {
              v56 = *(float *)v55 * 0.06175889447331429;
              v57 = *((_DWORD *)v55 + 3);
              *((_DWORD *)v53 + 4) = 0;
              *((_DWORD *)v53 - 1) = v57;
              *(_DWORD *)v53 = *((_DWORD *)v55 + 4);
              *((_DWORD *)v53 + 3) = v66;
              v53 = (char *)v53 + 32;
              *((float *)v53 - 7) = 1.0 - 1.0 / v56;
              v58 = 1.0 / *(float *)v55;
              v55 = (char *)v55 + 48;
              v59 = a5-- == 1;
              *((float *)v53 - 6) = v58;
              a7 = *(_WORD *)(v54 + 24);
              *((float *)v53 - 3) = *((float *)v55 - 6) / (double)a7;
              a7 = *(_WORD *)(v54 + 26);
              *((float *)v53 - 2) = *((float *)v55 - 5) / (double)a7;
            }
            while ( !v59 );
          }
          v60 = (*(int (__stdcall **)(_DWORD, _DWORD, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v8 + 262280)
                                                                                           + 56)
                                                                             + 160))(
                  *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                  0,
                  12,
                  1);
          CheckHRESULT((void **)&a5, v60, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x5CBu, 0);
          v61 = (*(int (__stdcall **)(_DWORD, _DWORD, signed int))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56) + 152))(
                  *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                  0,
                  a4);
          CheckHRESULT((void **)&a5, v61, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x5CCu, 0);
          v64 = 0;
          v63 = 1490;
          v62 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp";
          v42 = (*(int (__stdcall **)(_DWORD, signed int, signed int, _UNKNOWN *, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56) + 112))(
                  *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                  6,
                  452,
                  (char *)pVertices,
                  a2,
                  28);
        }
        else
        {
          if ( a2 > 0 )
          {
            v26 = a5;
            v27 = (char *)&array_507D30[0].flt_00000C;
            v25 = (char *)&pVertices->y;
            a5 = a2;
            do
            {
              v28 = *(float *)v27 * 0.06175889447331429;
              v29 = *((_DWORD *)v27 + 3);
              *((_DWORD *)v25 + 4) = 0;
              *((_DWORD *)v25 - 1) = v29;
              *(_DWORD *)v25 = *((_DWORD *)v27 + 4);
              *((_DWORD *)v25 + 3) = a7;
              v25 = (char *)v25 + 32;
              *((float *)v25 - 7) = 1.0 - 1.0 / v28;
              v30 = 1.0 / *(float *)v27;
              v27 = (char *)v27 + 48;
              v31 = a5-- == 1;
              *((float *)v25 - 6) = v30;
              a3 = *(_WORD *)(v26 + 24);
              *((float *)v25 - 3) = *((float *)v27 - 6) / (double)a3;
              a3 = *(_WORD *)(v26 + 26);
              *((float *)v25 - 2) = *((float *)v27 - 5) / (double)a3;
            }
            while ( !v31 );
          }
          v34 = (*(int (__stdcall **)(_DWORD, signed int, _DWORD, _DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56)
                                                                                             + 88))(
                  *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                  14,
                  0,
                  (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp",
                  1508,
                  0);
          CheckHRESULT((void **)&a5, v34, v35, v36, v37);
          v38 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56) + 160))(
                  *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                  0,
                  12,
                  1);
          CheckHRESULT((void **)&a5, v38, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x5E5u, 0);
          v39 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56) + 152))(
                  *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                  0,
                  0);
          CheckHRESULT((void **)&a5, v39, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x5E8u, 0);
          v40 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56)
                                                                                     + 112))(
                  *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                  6,
                  452,
                  (int)pVertices,
                  a2,
                  28);
          CheckHRESULT((void **)&a5, v40, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x5EDu, 0);
          (*(void (__cdecl **)(_DWORD, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56) + 88))(
            *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
            22,
            1);
          sub_45D74F_MessWithLight(pGame->class04_obj, -1, 0);
          v33 = a2;
          if ( a2 > 0 )
          {
            v41 = (char *)&pVertices->diffuse;
            do
            {
              v32 = v66;
              *(_DWORD *)v41 = v66;
              v41 = (char *)v41 + 32;
              --v33;
            }
            while ( v33 );
          }
          v43 = **(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56);
          v44 = (*(int (__fastcall **)(int, int, _DWORD, _DWORD, signed int))(v43 + 152))(
                  v43,
                  v32,
                  *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                  0,
                  a4);
          CheckHRESULT((void **)&a5, v44, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x5F8u, 0);
          v45 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56) + 160))(
                  *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                  0,
                  12,
                  1);
          CheckHRESULT((void **)&a5, v45, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x5F9u, 0);
          v46 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56) + 88))(
                  *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                  14,
                  1);
          CheckHRESULT((void **)&a5, v46, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x5FAu, 0);
          v47 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56) + 88))(
                  *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                  27,
                  1);
          CheckHRESULT((void **)&a5, v47, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x5FCu, 0);
          v48 = (*(int (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56) + 88))(
                  *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                  19,
                  1);
          CheckHRESULT((void **)&a5, v48, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x5FDu, 0);
          v49 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56) + 88))(
                  *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                  20,
                  3);
          CheckHRESULT((void **)&a5, v49, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x5FEu, 0);
          v50 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56)
                                                                                     + 112))(
                  *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                  6,
                  452,
                  (int)pVertices,
                  a2,
                  28);
          CheckHRESULT((void **)&a2, v50, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x604u, 0);
          v51 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
                  *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
                  19,
                  2);
          CheckHRESULT((void **)&a2, v51, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x606u, 0);
          v52 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
                  *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
                  20,
                  1);
          CheckHRESULT((void **)&a2, v52, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp", 0x607u, 0);
          v64 = 0;
          v63 = 1544;
          v62 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16_3d.cpp";
          v42 = (*(int (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(*(_DWORD *)(v8 + 262280) + 56) + 88))(
                  *(_DWORD *)(*(_DWORD *)(v8 + 262280) + 56),
                  27,
                  0);
        }
        CheckHRESULT((void **)&a2, v42, v62, v63, v64);
      }
    }
  }
}

//----- (004A354F) --------------------------------------------------------
void __thiscall sub_4A354F(int _this, int a2, IDirect3DTexture2 *pTexture, unsigned int uDiffuseColor, int a5)
{
  double v5; // st7@3
  float v6; // ST20_4@3
  int v7; // ST00_4@3
  int v8; // esi@3
  signed int v9; // eax@3
  int v10; // ebx@3
  float v11; // ST28_4@3
  double v12; // st7@3
  float v13; // ST24_4@3
  double v14; // st6@3
  float v15; // ST1C_4@3
  float v16; // ST2C_4@3
  float v17; // ST30_4@3
  int v18; // ST18_4@3
  int v19; // ST14_4@3
  int v20; // ST10_4@3
  int v21; // eax@3
  double v22; // st6@3
  float v23; // ST2C_4@3
  float v24; // ST30_4@3
  int v25; // ST10_4@3
  int v26; // ST14_4@3
  int v27; // ST18_4@3
  int v28; // eax@3
  double v29; // st6@3
  float v31; // ST2C_4@3
  float v32; // ST30_4@3
  int v33; // ST10_4@3
  int v34; // ST14_4@3
  int v35; // ST18_4@3
  int v36; // eax@3
  double v38; // st6@3
  float v39; // ST2C_4@3
  float v40; // ST30_4@3
  int v41; // ST10_4@3
  int v42; // ST14_4@3
  int v43; // ST18_4@3
  int v44; // eax@3
  double v45; // st6@3

  if ( *(_DWORD *)(_this + 262412) )
  {
    if ( *(_WORD *)(a2 + 42) )
    {
      v5 = (double)*(_WORD *)(a2 + 42);
      v6 = v5;
      *(float *)&v7 = v5;
      v8 = 156 * sub_4A1B22_Billboard_ProbablyAddToListAndSortByZOrder(v7);
      pBillboardRenderListD3D3[v8/156].int_00008C = 1;
      pBillboardRenderListD3D3[v8/156].dword_000090 = *(_DWORD *)(a2 + 68);
      pBillboardRenderListD3D3[v8/156].dword_000094 = *(_DWORD *)(a2 + 40);
      pBillboardRenderListD3D3[v8/156].uParentBillboardID = *(_DWORD *)(a2 + 72);
      v9 = *(_DWORD *)(a2 + 8);
      v10 = *(_DWORD *)(a2 + 12);
      v11 = (double)(*(_DWORD *)(a2 + 16) & 0xFFFF) * 0.00001526018604636192 + (double)*(_WORD *)(a2 + 18);
      v12 = (double)v9;
      v13 = v12;
      v14 = (double)(v10 - 12);
      v15 = v14;
      v16 = (double)(v9 - 12) - v12;
      v17 = (double)(v10 - 25) - v14;
      v18 = class59_SinCos(pClass59_global, a5);
      v19 = class59_SinCos(pClass59_global, a5 - pClass59_global->uIntegerHalfPi);
      v20 = class59_SinCos(pClass59_global, a5 - pClass59_global->uIntegerHalfPi);
      v21 = class59_SinCos(pClass59_global, a5);
      pBillboardRenderListD3D3[v8/156].pQuad[0].x = (((double)(unsigned __int16)v18 * 0.00001525902189314365 + (double)(v18 >> 16)) * v16
                                 - ((double)(unsigned __int16)v19 * 0.00001525902189314365 + (double)(v19 >> 16)) * v17)
                                * v11
                                + v13;
      v22 = (((double)(unsigned __int16)v21 * 0.00001525902189314365 + (double)(v21 >> 16)) * v17
           + ((double)(unsigned __int16)v20 * 0.00001525902189314365 + (double)(v20 >> 16)) * v16
           - 12.0)
          * v11
          + (double)*(signed int *)(a2 + 12);
      
      pBillboardRenderListD3D3[v8/156].pQuad[0].y = v22;
      pBillboardRenderListD3D3[v8/156].pQuad[0].z = 1.0 - 1.0 / (v6 * 0.06175889447331429);
      pBillboardRenderListD3D3[v8/156].pQuad[0].rhw = 1.0 / v6;
      pBillboardRenderListD3D3[v8/156].pQuad[0].diffuse = uDiffuseColor;
      pBillboardRenderListD3D3[v8/156].pQuad[0].specular = 0;
      pBillboardRenderListD3D3[v8/156].pQuad[0].u = 0.0;
      pBillboardRenderListD3D3[v8/156].pQuad[0].v = 0.0;

      v23 = (double)(*(_DWORD *)(a2 + 8) - 12) - v13;
      v24 = (double)*(signed int *)(a2 + 12) - v15;
      v25 = class59_SinCos(pClass59_global, a5);
      v26 = class59_SinCos(pClass59_global, a5 - pClass59_global->uIntegerHalfPi);
      v27 = class59_SinCos(pClass59_global, a5 - pClass59_global->uIntegerHalfPi);
      v28 = class59_SinCos(pClass59_global, a5);

      pBillboardRenderListD3D3[v8/156].pQuad[1].x = (((double)(unsigned __int16)v25 * 0.00001525902189314365 + (double)(v25 >> 16)) * v23
                                 - ((double)(unsigned __int16)v26 * 0.00001525902189314365 + (double)(v26 >> 16)) * v24)
                                * v11
                                + v13;
      v29 = (((double)(unsigned __int16)v28 * 0.00001525902189314365 + (double)(v28 >> 16)) * v24
           + ((double)(unsigned __int16)v27 * 0.00001525902189314365 + (double)(v27 >> 16)) * v23
           - 12.0)
          * v11
          + (double)*(signed int *)(a2 + 12);
      
      pBillboardRenderListD3D3[v8/156].pQuad[1].y = v29;
      pBillboardRenderListD3D3[v8/156].pQuad[1].z = pBillboardRenderListD3D3[v8/156].pQuad[0].z;
      pBillboardRenderListD3D3[v8/156].pQuad[1].rhw = pBillboardRenderListD3D3[v8/156].pQuad[0].rhw;
      pBillboardRenderListD3D3[v8/156].pQuad[1].diffuse = uDiffuseColor;
      pBillboardRenderListD3D3[v8/156].pQuad[1].specular = 0;
      pBillboardRenderListD3D3[v8/156].pQuad[1].u = 0.0;
      pBillboardRenderListD3D3[v8/156].pQuad[1].v = 1.0;

      v31 = (double)(*(_DWORD *)(a2 + 8) + 12) - v13;
      v32 = (double)*(signed int *)(a2 + 12) - v15;
      v33 = class59_SinCos(pClass59_global, a5);
      v34 = class59_SinCos(pClass59_global, a5 - pClass59_global->uIntegerHalfPi);
      v35 = class59_SinCos(pClass59_global, a5 - pClass59_global->uIntegerHalfPi);
      v36 = class59_SinCos(pClass59_global, a5);

      pBillboardRenderListD3D3[v8/156].pQuad[2].x = (((double)(unsigned __int16)v33 * 0.00001525902189314365 + (double)(v33 >> 16)) * v31
                                 - ((double)(unsigned __int16)v34 * 0.00001525902189314365 + (double)(v34 >> 16)) * v32)
                                * v11
                                + v13;
      v38 = (((double)(unsigned __int16)v36 * 0.00001525902189314365 + (double)(v36 >> 16)) * v32
           + ((double)(unsigned __int16)v35 * 0.00001525902189314365 + (double)(v35 >> 16)) * v31
           - 12.0)
          * v11
          + (double)*(signed int *)(a2 + 12);
      
      pBillboardRenderListD3D3[v8/156].pQuad[2].y = v38;
      pBillboardRenderListD3D3[v8/156].pQuad[2].z = pBillboardRenderListD3D3[v8/156].pQuad[0].z;
      pBillboardRenderListD3D3[v8/156].pQuad[2].rhw = pBillboardRenderListD3D3[v8/156].pQuad[0].rhw;
      pBillboardRenderListD3D3[v8/156].pQuad[2].diffuse = uDiffuseColor;
      pBillboardRenderListD3D3[v8/156].pQuad[2].specular = 0;
      pBillboardRenderListD3D3[v8/156].pQuad[2].u = 1.0;
      pBillboardRenderListD3D3[v8/156].pQuad[2].v = 1.0;

      v39 = (double)(*(_DWORD *)(a2 + 8) + 12) - v13;
      v40 = (double)(*(_DWORD *)(a2 + 12) - 25) - v15;
      v41 = class59_SinCos(pClass59_global, a5);
      v42 = class59_SinCos(pClass59_global, a5 - pClass59_global->uIntegerHalfPi);
      v43 = class59_SinCos(pClass59_global, a5 - pClass59_global->uIntegerHalfPi);
      v44 = class59_SinCos(pClass59_global, a5);

      pBillboardRenderListD3D3[v8/156].pQuad[3].x = (((double)(unsigned __int16)v41 * 0.00001525902189314365 + (double)(v41 >> 16)) * v39
                                 - ((double)(unsigned __int16)v42 * 0.00001525902189314365 + (double)(v42 >> 16)) * v40)
                                * v11
                                + v13;
      v45 = (((double)(unsigned __int16)v44 * 0.00001525902189314365 + (double)(v44 >> 16)) * v40
           + ((double)(unsigned __int16)v43 * 0.00001525902189314365 + (double)(v43 >> 16)) * v39
           - 12.0)
          * v11
          + (double)*(signed int *)(a2 + 12);
      
      pBillboardRenderListD3D3[v8/156].pQuad[3].y = v45;
      pBillboardRenderListD3D3[v8/156].pQuad[3].z = pBillboardRenderListD3D3[v8/156].pQuad[0].z;
      pBillboardRenderListD3D3[v8/156].pQuad[3].rhw = pBillboardRenderListD3D3[v8/156].pQuad[0].rhw;
      pBillboardRenderListD3D3[v8/156].pQuad[3].diffuse = uDiffuseColor;
      pBillboardRenderListD3D3[v8/156].pQuad[3].specular = 0;
      pBillboardRenderListD3D3[v8/156].pQuad[3].u = 1.0;
      pBillboardRenderListD3D3[v8/156].pQuad[3].v = 0.0;

      pBillboardRenderListD3D3[v8/156].pTexture = pTexture;
      pBillboardRenderListD3D3[v8/156].uNumVertices = 4;
      pBillboardRenderListD3D3[v8/156].flt_000088 = v6;
    }
  }
}

//----- (004A3AD9) --------------------------------------------------------
void __thiscall sub_4A3AD9(int _this, int a2, IDirect3DTexture2 *pTexture, unsigned int uDiffuseColor, int a5)
{
  double v5; // st7@2
  float v6; // ST28_4@2
  int v7; // ST00_4@2
  int v8; // esi@2
  signed int v9; // eax@2
  int v10; // ebx@2
  float v11; // ST34_4@2
  double v12; // st7@2
  float v13; // ST2C_4@2
  double v14; // st6@2
  float v15; // ST24_4@2
  float v16; // ST38_4@2
  float v17; // ST3C_4@2
  int v18; // ST1C_4@2
  int v19; // ST30_4@2
  int v20; // ST20_4@2
  int v21; // ST18_4@2
  int v22; // eax@2
  double v23; // st6@2
  float v24; // ST20_4@2
  float v25; // ST1C_4@2
  float v26; // ST38_4@2
  float v27; // ST3C_4@2
  int v28; // ST18_4@2
  int v29; // ST14_4@2
  int v30; // ST10_4@2
  int v31; // eax@2
  double v32; // st6@2
  float v33; // ST38_4@2
  float v34; // ST3C_4@2
  int v35; // ST10_4@2
  int v36; // ST14_4@2
  int v37; // ST18_4@2
  int v38; // eax@2
  double v39; // st6@2
  float v40; // ST38_4@2
  float v41; // ST3C_4@2
  int v42; // ST10_4@2
  int v43; // ST14_4@2
  int v44; // ST18_4@2
  int v45; // eax@2
  double v46; // st6@2

  if ( *(_DWORD *)(_this + 262412) )
  {
    v5 = (double)*(_WORD *)(a2 + 42);
    v6 = v5;
    *(float *)&v7 = v5;
    v8 = 156 * sub_4A1B22_Billboard_ProbablyAddToListAndSortByZOrder(v7);

    pBillboardRenderListD3D3[v8/156].int_00008C = 1;
    pBillboardRenderListD3D3[v8/156].dword_000090 = *(_DWORD *)(a2 + 68);
    pBillboardRenderListD3D3[v8/156].dword_000094 = *(_DWORD *)(a2 + 40);
    pBillboardRenderListD3D3[v8/156].uParentBillboardID = *(_DWORD *)(a2 + 72);

    v9 = *(_DWORD *)(a2 + 8);
    v10 = *(_DWORD *)(a2 + 12);
    v11 = (double)(*(_DWORD *)(a2 + 16) & 0xFFFF) * 0.00001526018604636192 + (double)*(_WORD *)(a2 + 18);
    v12 = (double)v9;
    v13 = v12;
    v14 = (double)(v10 - 12);
    v15 = v14;
    v16 = (double)(v9 - 12) - v12;
    v17 = (double)(v10 - 25) - v14;
    v18 = class59_SinCos(pClass59_global, a5);
    v19 = a5 - pClass59_global->uIntegerHalfPi;
    v20 = class59_SinCos(pClass59_global, a5 - pClass59_global->uIntegerHalfPi);
    v21 = class59_SinCos(pClass59_global, v19);
    v22 = class59_SinCos(pClass59_global, a5);

    pBillboardRenderListD3D3[v8/156].pQuad[0].x = (((double)(unsigned __int16)v18 * 0.00001525902189314365 + (double)(v18 >> 16)) * v16
                               - ((double)(unsigned __int16)v20 * 0.00001525902189314365 + (double)(v20 >> 16)) * v17)
                              * v11
                              + v13;
    v23 = (((double)(unsigned __int16)v22 * 0.00001525902189314365 + (double)(v22 >> 16)) * v17
         + ((double)(unsigned __int16)v21 * 0.00001525902189314365 + (double)(v21 >> 16)) * v16
         - 12.0)
        * v11
        + (double)*(signed int *)(a2 + 12);
    
    v24 = 1.0 - 1.0 / (v6 * 1000.0 / (double)pStruct9_global->shading_dist_mist);
    v25 = 1.0 / v6;

    pBillboardRenderListD3D3[v8/156].pQuad[0].y = v23;
    pBillboardRenderListD3D3[v8/156].pQuad[0].z = v24;
    pBillboardRenderListD3D3[v8/156].pQuad[0].rhw = v25;
    pBillboardRenderListD3D3[v8/156].pQuad[0].diffuse = uDiffuseColor;
    pBillboardRenderListD3D3[v8/156].pQuad[0].specular = 0;
    pBillboardRenderListD3D3[v8/156].pQuad[0].u = 0.0;
    pBillboardRenderListD3D3[v8/156].pQuad[0].v = 0.0;

    v26 = (double)(*(_DWORD *)(a2 + 8) - 12) - v13;
    v27 = (double)*(signed int *)(a2 + 12) - v15;
    v28 = class59_SinCos(pClass59_global, a5);
    v29 = class59_SinCos(pClass59_global, v19);
    v30 = class59_SinCos(pClass59_global, v19);
    v31 = class59_SinCos(pClass59_global, a5);

    pBillboardRenderListD3D3[v8/156].pQuad[1].x = (((double)(unsigned __int16)v28 * 0.00001525902189314365 + (double)(v28 >> 16)) * v26
                               - ((double)(unsigned __int16)v29 * 0.00001525902189314365 + (double)(v29 >> 16)) * v27)
                              * v11
                              + v13;
    v32 = (((double)(unsigned __int16)v31 * 0.00001525902189314365 + (double)(v31 >> 16)) * v27
         + ((double)(unsigned __int16)v30 * 0.00001525902189314365 + (double)(v30 >> 16)) * v26
         - 12.0)
        * v11
        + (double)*(signed int *)(a2 + 12);

    pBillboardRenderListD3D3[v8/156].pQuad[1].y = v32;
    pBillboardRenderListD3D3[v8/156].pQuad[1].z = v24;
    pBillboardRenderListD3D3[v8/156].pQuad[1].rhw = v25;
    pBillboardRenderListD3D3[v8/156].pQuad[1].diffuse = uDiffuseColor;
    pBillboardRenderListD3D3[v8/156].pQuad[1].specular = 0;
    pBillboardRenderListD3D3[v8/156].pQuad[1].u = 0.0;
    pBillboardRenderListD3D3[v8/156].pQuad[1].v = 1.0;

    v33 = (double)(*(_DWORD *)(a2 + 8) + 12) - v13;
    v34 = (double)*(signed int *)(a2 + 12) - v15;
    v35 = class59_SinCos(pClass59_global, a5);
    v36 = class59_SinCos(pClass59_global, v19);
    v37 = class59_SinCos(pClass59_global, v19);
    v38 = class59_SinCos(pClass59_global, a5);

    pBillboardRenderListD3D3[v8/156].pQuad[2].x = (((double)(unsigned __int16)v35 * 0.00001525902189314365 + (double)(v35 >> 16)) * v33
                               - ((double)(unsigned __int16)v36 * 0.00001525902189314365 + (double)(v36 >> 16)) * v34)
                              * v11
                              + v13;
    v39 = (((double)(unsigned __int16)v38 * 0.00001525902189314365 + (double)(v38 >> 16)) * v34
         + ((double)(unsigned __int16)v37 * 0.00001525902189314365 + (double)(v37 >> 16)) * v33
         - 12.0)
        * v11
        + (double)*(signed int *)(a2 + 12);

    pBillboardRenderListD3D3[v8/156].pQuad[2].y = v39;
    pBillboardRenderListD3D3[v8/156].pQuad[2].z = v24;
    pBillboardRenderListD3D3[v8/156].pQuad[2].rhw = v25;
    pBillboardRenderListD3D3[v8/156].pQuad[2].diffuse = uDiffuseColor;
    pBillboardRenderListD3D3[v8/156].pQuad[2].specular = 0;
    pBillboardRenderListD3D3[v8/156].pQuad[2].u = 1.0;
    pBillboardRenderListD3D3[v8/156].pQuad[2].v = 1.0;

    v40 = (double)(*(_DWORD *)(a2 + 8) + 12) - v13;
    v41 = (double)(*(_DWORD *)(a2 + 12) - 25) - v15;
    v42 = class59_SinCos(pClass59_global, a5);
    v43 = class59_SinCos(pClass59_global, v19);
    v44 = class59_SinCos(pClass59_global, v19);
    v45 = class59_SinCos(pClass59_global, a5);

    pBillboardRenderListD3D3[v8/156].pQuad[3].x = (((double)(unsigned __int16)v42 * 0.00001525902189314365 + (double)(v42 >> 16)) * v40
                               - ((double)(unsigned __int16)v43 * 0.00001525902189314365 + (double)(v43 >> 16)) * v41)
                              * v11
                              + v13;
    v46 = (((double)(unsigned __int16)v45 * 0.00001525902189314365 + (double)(v45 >> 16)) * v41
         + ((double)(unsigned __int16)v44 * 0.00001525902189314365 + (double)(v44 >> 16)) * v40
         - 12.0)
        * v11
        + (double)*(signed int *)(a2 + 12);

    pBillboardRenderListD3D3[v8/156].pQuad[3].y = v46;
    pBillboardRenderListD3D3[v8/156].pQuad[3].z = v24;
    pBillboardRenderListD3D3[v8/156].pQuad[3].rhw = v25;
    pBillboardRenderListD3D3[v8/156].pQuad[3].diffuse = uDiffuseColor;
    pBillboardRenderListD3D3[v8/156].pQuad[3].specular = 0;
    pBillboardRenderListD3D3[v8/156].pQuad[3].u = 1.0;
    pBillboardRenderListD3D3[v8/156].pQuad[3].v = 0.0;

    pBillboardRenderListD3D3[v8/156].pTexture = pTexture;
    pBillboardRenderListD3D3[v8/156].uNumVertices = 4;
    pBillboardRenderListD3D3[v8/156].flt_000088 = v6;
  }
}

//----- (004A4023) --------------------------------------------------------
void Render_BillboardTransform(struct BaseRender *_this, struct Render_BillboardTransform_stru0 *a2, struct HardwareSprite *pSprite, int a4, struct RenderBillboard *pBillboard)
{
  signed int v10; // eax@9
  signed int v11; // eax@9
  int v12; // eax@12
  double v13; // st7@12
  double v14; // st5@14
  double v15; // st6@14
  double v17; // st4@16
  double v18; // st5@16
  double v19; // st7@16
  double v20; // st4@18
  double v21; // st5@18
  signed int v23; // [sp+18h] [bp-18h]@5
  signed int v24; // [sp+1Ch] [bp-14h]@5
  float v25; // [sp+1Ch] [bp-14h]@12
  float v26; // [sp+20h] [bp-10h]@5
  float v27; // [sp+20h] [bp-10h]@12
  float v29; // [sp+28h] [bp-8h]@5
  float v30; // [sp+2Ch] [bp-4h]@5
  float v31; // [sp+38h] [bp+8h]@2
  float v32; // [sp+3Ch] [bp+Ch]@5
  int v33; // [sp+3Ch] [bp+Ch]@14
  float v34; // [sp+40h] [bp+10h]@12
  float v35; // [sp+44h] [bp+14h]@12
 unsigned int i;

  if (!_this->uD3D3SceneBegun)
    return;

    v31 = (double)a2->word_00002A;
    i = sub_4A1B22_Billboard_ProbablyAddToListAndSortByZOrder(a2->word_00002A);
    if (a2->dword_00004C & 0xFF000000)
      pBillboardRenderListD3D3[i].int_00008C = 3;
    else
      pBillboardRenderListD3D3[i].int_00008C = 0;

    pBillboardRenderListD3D3[i].dword_000090 = a2->dword_000044;
    pBillboardRenderListD3D3[i].dword_000094 = a2->dword_000028;
    pBillboardRenderListD3D3[i].uParentBillboardID = a2->dword_000048;

    v24 = a2->dword_000008;
    v23 = a2->dword_00000C;
    v30 = (double)(a2->dword_000010 & 0xFFFF) * 0.00001526018604636192 + (double)a2->word_000012;
    v29 = (double)(a2->dword_000014 & 0xFFFF) * 0.00001526018604636192 + (double)a2->word_000016;
    v32 = (double)((pSprite->dword_000018 / 2) - pSprite->dword_000010);
    v26 = (double)(pSprite->dword_00001C - pSprite->dword_000014);
    if (a2->dword_00002C & 0x04)
      v32 = -v32;
    if (a2->dword_00004C & 0x00FFFFFF && _this->bTinting)
    {
      v11 = sub_47C4FC_GetActorTintColor(a4, 0, v31, 0, (int)pBillboard);
      v10 = sub_4A19D8(a2->dword_00004C, v11);
      if (a2->dword_00004C & 0xFF000000)
        v10 = 0x7F7F7F & ((unsigned int)v10 >> 1);
    }
    else
    {
      v10 = sub_47C4FC_GetActorTintColor(a4, 0, v31, 0, (int)pBillboard);
    }


    v12 = 0;
    if (_this->bUsingSpecular)
    {
      v12 = sub_47C3D7(0, 0, v31);
      v13 = 1.0;
    }

    v35 = (double)v24;
    pBillboardRenderListD3D3[i].pQuad[0].x = v35 - v32 * v30;
    v34 = (double)v23;
    pBillboardRenderListD3D3[i].pQuad[0].y = v34 - v26 * v29;
    v27 = v31 * 1000.0;
    v13 = 1.0;
    pBillboardRenderListD3D3[i].pQuad[0].z = 1.0 - 1.0 / (v27 / (double)pStruct9_global->shading_dist_mist);
    v25 = 1.0 / v31;
    pBillboardRenderListD3D3[i].pQuad[0].rhw = v25;
    pBillboardRenderListD3D3[i].pQuad[0].diffuse = v10;
    pBillboardRenderListD3D3[i].pQuad[0].specular = v12;
    v33 = v12;
    pBillboardRenderListD3D3[i].pQuad[0].u = 0.0;
    pBillboardRenderListD3D3[i].pQuad[0].v = 0.0;

    v15 = (double)((pSprite->dword_000018 / 2) - pSprite->dword_000010);
    v14 = (double)(pSprite->dword_00001C - pSprite->dword_000024 - pSprite->dword_000014);
    if (a2->dword_00002C & 0x04)
      v15 = v15 * -1.0;

    pBillboardRenderListD3D3[i].pQuad[1].x = v35 - v15 * v30;
    pBillboardRenderListD3D3[i].pQuad[1].y = v34 - v14 * v29;
    v19 = v13 - v13 / (v27 / (double)pStruct9_global->shading_dist_mist);
    pBillboardRenderListD3D3[i].pQuad[1].z = v19;
    pBillboardRenderListD3D3[i].pQuad[1].rhw = v25;
    pBillboardRenderListD3D3[i].pQuad[1].specular = v12;
    pBillboardRenderListD3D3[i].pQuad[1].diffuse = pBillboardRenderListD3D3[i].pQuad[0].diffuse;
    pBillboardRenderListD3D3[i].pQuad[1].u = 0.0;
    pBillboardRenderListD3D3[i].pQuad[1].v = 1.0;
    v18 = (double)(pSprite->dword_000020 + pSprite->dword_000010 + (pSprite->dword_000018 / 2) - pSprite->dword_000018);
    v17 = (double)(pSprite->dword_00001C - pSprite->dword_000024 - pSprite->dword_000014);
    if (a2->dword_00002C & 0x04)
      v18 = v18 * -1.0;

    pBillboardRenderListD3D3[i].pQuad[2].x = v18 * v30 + v35;
    pBillboardRenderListD3D3[i].pQuad[2].y = v34 - v17 * v29;
    pBillboardRenderListD3D3[i].pQuad[2].z = v19;
    pBillboardRenderListD3D3[i].pQuad[2].rhw = v25;
    pBillboardRenderListD3D3[i].pQuad[2].diffuse = pBillboardRenderListD3D3[i].pQuad[0].diffuse;
    pBillboardRenderListD3D3[i].pQuad[2].specular = v33;
    pBillboardRenderListD3D3[i].pQuad[2].u = 1.0;
    pBillboardRenderListD3D3[i].pQuad[2].v = 1.0;

    v21 = (double)(pSprite->dword_000020 + pSprite->dword_000010 + (pSprite->dword_000018 / 2) - pSprite->dword_000018);
    v20 = (double)(pSprite->dword_00001C - pSprite->dword_000014);
    if (a2->dword_00002C & 0x04)
      v21 = v21 * -1.0;

    pBillboardRenderListD3D3[i].pQuad[3].x = v21 * v30 + v35;
    pBillboardRenderListD3D3[i].pQuad[3].y = v34 - v20 * v29;
    pBillboardRenderListD3D3[i].pQuad[3].z = v19;
    pBillboardRenderListD3D3[i].pQuad[3].rhw = v25;
    pBillboardRenderListD3D3[i].pQuad[3].diffuse = pBillboardRenderListD3D3[i].pQuad[0].diffuse;
    pBillboardRenderListD3D3[i].pQuad[3].specular = v33;
    pBillboardRenderListD3D3[i].pQuad[3].u = 1.0;
    pBillboardRenderListD3D3[i].pQuad[3].v = 0.0;

    pBillboardRenderListD3D3[i].pTexture = pSprite->pTexture;
    pBillboardRenderListD3D3[i].uNumVertices = 4;
    pBillboardRenderListD3D3[i].flt_000088 = v31;
}

//----- (004A43B1) --------------------------------------------------------
void __thiscall Render_sub_4A43B1(int _this, int a2, int a3, int a4)
{
  int v4; // ecx@2
  int v5; // ebx@2
  int v6; // esi@2
  double v7; // st7@2
  int v8; // ST08_4@2
  int v9; // eax@2
  int v10; // edi@5
  signed int v11; // eax@9
  signed int v12; // eax@9
  double v13; // st2@12
  double v14; // st3@12
  double v15; // st4@12
  double v16; // st5@12
  double v17; // st7@12
  double v18; // st6@12
  int v19; // ecx@14
  double v20; // st3@14
  int v21; // ecx@16
  double v22; // st3@16
  signed int v24; // [sp+18h] [bp-18h]@5
  signed int v25; // [sp+1Ch] [bp-14h]@5
  int v26; // [sp+20h] [bp-10h]@1
  float v27; // [sp+24h] [bp-Ch]@5
  int v28; // [sp+28h] [bp-8h]@2
  float v29; // [sp+2Ch] [bp-4h]@5
  float v30; // [sp+38h] [bp+8h]@2
  float v31; // [sp+3Ch] [bp+Ch]@5
  float v32; // [sp+3Ch] [bp+Ch]@12
  float v33; // [sp+40h] [bp+10h]@5

  v26 = _this;
  if ( *(_DWORD *)(_this + 262412) )
  {
    v5 = a2;
    v7 = (double)*(_WORD *)(a2 + 42);
    v30 = v7;
    *(float *)&v8 = v7;
    v9 = sub_4A1B22_Billboard_ProbablyAddToListAndSortByZOrder(v8);
    v4 = a4;
    v6 = 156 * v9;
    v28 = a4 & 0xFF000000;
    if ( a4 & 0xFF000000 )
      pBillboardRenderListD3D3[v6/156].int_00008C = 3;
    else
      pBillboardRenderListD3D3[v6/156].int_00008C = 0;

    v10 = a3;
    pBillboardRenderListD3D3[v6/156].dword_000090 = *(_DWORD *)(v5 + 68);
    pBillboardRenderListD3D3[v6/156].dword_000094 = *(_DWORD *)(v5 + 40);
    pBillboardRenderListD3D3[v6/156].uParentBillboardID = *(_DWORD *)(v5 + 72);

    v25 = *(_DWORD *)(v5 + 8);
    v24 = *(_DWORD *)(v5 + 12);
    v33 = (double)(*(_DWORD *)(v5 + 16) & 0xFFFF) * 0.00001526018604636192 + (double)*(_WORD *)(v5 + 18);
    v29 = (double)(*(_DWORD *)(v5 + 20) & 0xFFFF) * 0.00001526018604636192 + (double)*(_WORD *)(v5 + 22);
    v31 = (double)((*(_DWORD *)(v10 + 24) >> 1) - *(_DWORD *)(v10 + 16));
    v27 = (double)(*(_DWORD *)(v10 + 28) - *(_DWORD *)(v10 + 20));
    if ( *(_BYTE *)(v5 + 44) & 4 )
      v31 = v31 * -1.0;
    if ( *(_DWORD *)(v5 + 76) && *(_DWORD *)(v26 + 1062476) )
    {
      v12 = sub_47C4FC_GetActorTintColor(v4, 0, v30, 0, 0);
      v11 = sub_4A19D8(*(_DWORD *)(v5 + 76), v12);
      if ( v28 )
        v11 = 0x7F7F7F & ((unsigned int)v11 >> 1);
    }
    else
    {
      v11 = sub_47C4FC_GetActorTintColor(v4, 0, v30, 0, 0);
    }
    v17 = (double)v25;
 
    pBillboardRenderListD3D3[v6/156].pQuad[0].diffuse = v11;
    pBillboardRenderListD3D3[v6/156].pQuad[0].specular = 0;
    pBillboardRenderListD3D3[v6/156].pQuad[0].x = v17 - v31 * v33;
    v18 = (double)v24;
    v32 = v18;
    pBillboardRenderListD3D3[v6/156].pQuad[0].y = v18 - v27 * v29;
    v16 = 1.0 - 1.0 / (v30 * 0.06175889447331429);
    pBillboardRenderListD3D3[v6/156].pQuad[0].z = v16;
    v15 = 1.0 / v30;
    pBillboardRenderListD3D3[v6/156].pQuad[0].rhw = 1.0 / v30;
    pBillboardRenderListD3D3[v6/156].pQuad[0].u = 0.0;
    pBillboardRenderListD3D3[v6/156].pQuad[0].v = 0.0;
    v14 = (double)((*(_DWORD *)(v10 + 24) >> 1) - *(_DWORD *)(v10 + 16));
    v13 = (double)(*(_DWORD *)(v10 + 28) - *(_DWORD *)(v10 + 20) - *(_DWORD *)(v10 + 36));
    if ( *(_BYTE *)(v5 + 44) & 4 )
      v14 = v14 * -1.0;

    pBillboardRenderListD3D3[v6/156].pQuad[1].diffuse = v11;
    pBillboardRenderListD3D3[v6/156].pQuad[1].specular = 0;
    pBillboardRenderListD3D3[v6/156].pQuad[1].x = v17 - v14 * v33;
    pBillboardRenderListD3D3[v6/156].pQuad[1].y = v32 - v13 * v29;
    pBillboardRenderListD3D3[v6/156].pQuad[1].z = v16;
    pBillboardRenderListD3D3[v6/156].pQuad[1].rhw = v15;
    pBillboardRenderListD3D3[v6/156].pQuad[1].u = 0.0;
    pBillboardRenderListD3D3[v6/156].pQuad[1].v = 1.0;
    v19 = *(_DWORD *)(v10 + 28) - *(_DWORD *)(v10 + 20) - *(_DWORD *)(v10 + 36);
    v20 = (double)(*(_DWORD *)(v10 + 16) + *(_DWORD *)(v10 + 32) + (*(_DWORD *)(v10 + 24) >> 1) - *(_DWORD *)(v10 + 24));
    if ( *(_BYTE *)(v5 + 44) & 4 )
      v20 = v20 * -1.0;

    pBillboardRenderListD3D3[v6/156].pQuad[2].diffuse = v11;
    pBillboardRenderListD3D3[v6/156].pQuad[2].specular = 0;
    pBillboardRenderListD3D3[v6/156].pQuad[2].x = v20 * v33 + v17;
    pBillboardRenderListD3D3[v6/156].pQuad[2].y = v32 - (double)v19 * v29;
    pBillboardRenderListD3D3[v6/156].pQuad[2].z = v16;
    pBillboardRenderListD3D3[v6/156].pQuad[2].rhw = v15;
    pBillboardRenderListD3D3[v6/156].pQuad[2].u = 1.0;
    pBillboardRenderListD3D3[v6/156].pQuad[2].v = 1.0;
    v21 = *(_DWORD *)(v10 + 28) - *(_DWORD *)(v10 + 20);
    v22 = (double)(*(_DWORD *)(v10 + 16) + *(_DWORD *)(v10 + 32) + (*(_DWORD *)(v10 + 24) >> 1) - *(_DWORD *)(v10 + 24));
    if ( *(_BYTE *)(v5 + 44) & 4 )
      v22 = v22 * -1.0;

    pBillboardRenderListD3D3[v6/156].pQuad[3].diffuse = v11;
    pBillboardRenderListD3D3[v6/156].pQuad[3].specular = 0;
    pBillboardRenderListD3D3[v6/156].pQuad[3].x = v22 * v33 + v17;
    pBillboardRenderListD3D3[v6/156].pQuad[3].y = v32 - (double)v21 * v29;
    pBillboardRenderListD3D3[v6/156].pQuad[3].z = v16;
    pBillboardRenderListD3D3[v6/156].pQuad[3].rhw = v15;
    pBillboardRenderListD3D3[v6/156].pQuad[3].u = 1.0;
    pBillboardRenderListD3D3[v6/156].pQuad[3].v = 0.0;

    pBillboardRenderListD3D3[v6/156].pTexture = *(IDirect3DTexture2 **)(v10 + 12);
    pBillboardRenderListD3D3[v6/156].uNumVertices = 4;
    pBillboardRenderListD3D3[v6/156].flt_000088 = v30;
  }
}

//----- (004A46E6) --------------------------------------------------------
int __fastcall sub_4A46E6(int a1, int a2, signed int a3, int a4, unsigned int a5)
{
  int result; // eax@1
  int v6; // eax@9
  int v7; // ecx@9
  unsigned int v8; // edx@10
  signed int v9; // ecx@10
  int v10; // edi@10
  int v11; // esi@10
  unsigned int v12; // edx@22
  signed int v13; // ecx@22
  int v14; // edi@22
  int v15; // esi@22
  int v16; // eax@1
  unsigned int v17; // eax@9
  int v18; // [sp+Ch] [bp-8h]@9
  int v19; // [sp+10h] [bp-4h]@9

  v16 = a4;
  a4 = a3 >> 16;
  result = a1 + v16;
  if ( result >= pOldViewport->uGameX && a1 <= pOldViewport->uGameZ && a2 >= pOldViewport->uGameY && a2 <= pOldViewport->uGameW )
  {
    if ( a1 < pOldViewport->uGameX )
      a1 = pOldViewport->uGameX;
    if ( result > pOldViewport->uGameZ )
      result = pOldViewport->uGameZ;
    v18 = (int)(pD3DRenderer->pTargetSurface + (a1 + a2 * pD3DRenderer->uTargetSurfacePitch));
    a3 = result - a1;
    v19 = (int)(pD3DRenderer->pActiveZBuffer + (a1 + 640 * a2));
    v17 = a5 >> 3;
    v7 = a5 & 0xF0;
    v6 = v17 & 0x1E0000;
    if (pD3DRenderer->uNumTargetGBits == 5 )
    {
      a5 = ((v7 | ((a5 & 0xF000 | v6) >> 3)) >> 4 << 16) | ((v7 | ((a5 & 0xF000 | v6) >> 3)) >> 4);
      v11 = v18;
      v10 = v19;
      v9 = a3;
      v8 = a5;
      result = v18 & 2;
      if ( v18 & 2 )
      {
        result = *(_DWORD *)v19 >> 16;
        if ( result > a4 )
        {
          result = a5 + ((*(_WORD *)v18 & 0x7BDEu) >> 1);
          *(_WORD *)v18 = result;
        }
        --v9;
        v11 = v18 + 2;
        v10 += 4;
      }
      while ( v9 != 1 )
      {
        if ( v9 < 1 )
          return result;
        result = *(_DWORD *)v10 >> 16;
        if ( result <= a4 )
        {
          v9 -= 2;
          v11 += 4;
          v10 += 8;
        }
        else
        {
          v10 += 8;
          result = v8 + ((*(_DWORD *)v11 & 0x7BDE7BDEu) >> 1);
          v9 -= 2;
          *(_DWORD *)v11 = result;
          v11 += 4;
        }
      }
      result = *(_DWORD *)v10 >> 16;
      if ( result > a4 )
      {
        result = v8 + ((*(_WORD *)v11 & 0x7BDEu) >> 1);
        *(_WORD *)v11 = result;
      }
    }
    else
    {
      a5 = ((v7 | ((a5 & 0xF800 | v6) >> 2)) >> 4 << 16) | ((v7 | ((a5 & 0xF800 | v6) >> 2)) >> 4);
      v15 = v18;
      v14 = v19;
      v13 = a3;
      v12 = a5;
      result = v18 & 2;
      if ( v18 & 2 )
      {
        result = *(_DWORD *)v19 >> 16;
        if ( result > a4 )
        {
          result = a5 + ((*(_WORD *)v18 & 0xF7DEu) >> 1);
          *(_WORD *)v18 = result;
        }
        --v13;
        v15 = v18 + 2;
        v14 += 4;
      }
      while ( v13 != 1 )
      {
        if ( v13 < 1 )
          return result;
        result = *(_DWORD *)v14 >> 16;
        if ( result <= a4 )
        {
          v13 -= 2;
          v15 += 4;
          v14 += 8;
        }
        else
        {
          v14 += 8;
          result = v12 + ((*(_DWORD *)v15 & 0xF7DEF7DEu) >> 1);
          v13 -= 2;
          *(_DWORD *)v15 = result;
          v15 += 4;
        }
      }
      result = *(_DWORD *)v14 >> 16;
      if ( result > a4 )
      {
        result = v12 + ((*(_WORD *)v15 & 0xF7DEu) >> 1);
        *(_WORD *)v15 = result;
      }
    }
  }
  return result;
}

//----- (004A48E4) --------------------------------------------------------
signed int __stdcall sub_4A48E4(int a1, int a2, int a3, int a4, signed int a5)
{
  int v5; // edi@1
  int v6; // esi@1
  int v7; // ecx@1
  int v8; // ecx@1
  int v9; // edx@1
  signed int result; // eax@8
  int v11; // [sp+Ch] [bp-10h]@1
  int v12; // [sp+10h] [bp-Ch]@1
  int v13; // [sp+14h] [bp-8h]@1
  int v14; // [sp+24h] [bp+8h]@1
  int v15; // [sp+28h] [bp+Ch]@1
  signed int v16; // [sp+34h] [bp+18h]@1

  v7 = a1;
  v14 = 0;
  v13 = 0;
  v8 = (a5 >> 1) + v7;
  v12 = (a5 >> 1) * (a5 >> 1);
  v9 = 2 * (a5 >> 1);
  v5 = (a5 >> 1) * ((a5 >> 1) - 1);
  v6 = v8 - (a5 >> 1);
  v16 = a5 >> 1;
  v11 = v9;
  v15 = v8;
  do
  {
   compile_error;
   /*
    sub_4A46E6(a3, 2 * v16, a4);
    if ( v13 )
      sub_4A46E6(a3, 2 * v16, a4);
    v12 -= v13;
    if ( v12 <= v5 )
    {
      if ( v16 != v14 )
      {
        sub_4A46E6(a3, 2 * v14, a4);
        sub_4A46E6(a3, 2 * v14, a4);
      }
      --v16;
      v11 -= 2;
      ++v6;
      v5 -= v11;
    }
    result = v14++;
    v13 += 2;
    --v15;*/
  }
  while ( result < v16 );
  return result;
}

//----- (004A49D0) --------------------------------------------------------
int __stdcall sub_4A49D0(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, int a9)
{
  int v9; // eax@1
  unsigned int v10; // ecx@1
  unsigned int v11; // ebx@1
  int v12; // edx@2
  int v13; // edx@4
  unsigned int v14; // edx@6
  double v15; // st4@7
  double v16; // st6@7
  double v17; // st7@7
  double v18; // st7@7
  double v19; // st4@8
  double v20; // st4@10
  double v21; // st4@10
  double v22; // st4@10
  double v23; // st4@10
  double v24; // st4@11
  double v26; // st4@13
  double v27; // st5@13
  double v28; // st4@13
  float v29; // [sp+0h] [bp-94h]@7
  float v30; // [sp+4h] [bp-90h]@7
  int v31; // [sp+8h] [bp-8Ch]@10
  float v32; // [sp+Ch] [bp-88h]@10
  int v33; // [sp+10h] [bp-84h]@10
  int v34; // [sp+14h] [bp-80h]@10
  float v35; // [sp+18h] [bp-7Ch]@10
  float v36; // [sp+1Ch] [bp-78h]@10
  float v37; // [sp+20h] [bp-74h]@10
  float v38; // [sp+24h] [bp-70h]@10
  float v39; // [sp+28h] [bp-6Ch]@13
  float v40; // [sp+2Ch] [bp-68h]@13
  int v41; // [sp+30h] [bp-64h]@13
  int v42; // [sp+34h] [bp-60h]@13
  float v43; // [sp+38h] [bp-5Ch]@13
  float v44; // [sp+3Ch] [bp-58h]@13
  float v45; // [sp+40h] [bp-54h]@13
  float v46; // [sp+44h] [bp-50h]@13
  float v47; // [sp+48h] [bp-4Ch]@13
  float v48; // [sp+4Ch] [bp-48h]@13
  int v49; // [sp+50h] [bp-44h]@13
  int v50; // [sp+54h] [bp-40h]@13
  float v51; // [sp+58h] [bp-3Ch]@13
  float v52; // [sp+5Ch] [bp-38h]@13
  float v53; // [sp+60h] [bp-34h]@13
  float v54; // [sp+64h] [bp-30h]@13
  float v55; // [sp+68h] [bp-2Ch]@13
  int v56; // [sp+6Ch] [bp-28h]@13
  int v57; // [sp+70h] [bp-24h]@13
  int v58; // [sp+74h] [bp-20h]@13
  float v59; // [sp+78h] [bp-1Ch]@13
  float v60; // [sp+7Ch] [bp-18h]@13
  double v61; // [sp+80h] [bp-14h]@1
  int v62; // [sp+88h] [bp-Ch]@1
  signed int v63; // [sp+8Ch] [bp-8h]@1
  int X; // [sp+90h] [bp-4h]@1
  float v65; // [sp+A4h] [bp+10h]@10
  float v66; // [sp+A8h] [bp+14h]@10

  *(float *)&X = a5 - a1;
  v61 = *(float *)&X + 6.755399441055744e15;
  v62 = LODWORD(v61);
  *(float *)&v63 = a6 - a2;
  v61 = *(float *)&v63 + 6.755399441055744e15;
  X = LODWORD(v61);
  compile_error;//HIDWORD(v61) = abs(COERCE_UNSIGNED_INT64(*(float *)&v63 + 6.755399441055744e15));
  v9 = abs(v62);
  v63 = v9;
  v11 = HIDWORD(v61);
  v10 = 0;
  if ( v9 < HIDWORD(v61) )
  {
    v12 = v9;
    v9 = HIDWORD(v61);
    v11 = v12;
  }
  if ( v9 < 0 )
  {
    v13 = v9;
    v9 = 0;
    v10 = v13;
  }
  if ( (signed int)v11 < (signed int)v10 )
  {
    v14 = v10;
    v10 = v11;
    v11 = v14;
  }
  v63 = (11 * v11 >> 5) + (v10 >> 2) + v9;
  v18 = 1.0 / (double)v63;
  *(float *)&v62 = (double)v62 * v18;
  *(float *)&X = (double)X * v18;
  v17 = *(float *)&X * a4;
  v29 = a1 + v17;
  v16 = *(float *)&v62 * a4;
  v30 = a2 - v16;
  v15 = a3;
  if ( dword_6BE360 == 2 )
    v19 = v15 * 1000.0 / (double)pStruct9_global->shading_dist_mist;
  else
    v19 = v15 * 0.06175889447331429;
  v33 = -1;
  v34 = 0;
  *(float *)&v31 = 1.0 - 1.0 / v19;
  v21 = 1.0 / a3;
  *((float *)&v61 + 1) = v21;
  v32 = v21;
  v35 = 1.0;
  v36 = 0.0;
  v22 = *(float *)&X * a8;
  v65 = v22;
  v37 = v22 + a5;
  v23 = *(float *)&v62 * a8;
  v66 = v23;
  v38 = a6 - v23;
  v20 = a7;
  if ( dword_6BE360 == 2 )
    v24 = v20 * 1000.0 / (double)pStruct9_global->shading_dist_mist;
  else
    v24 = v20 * 0.06175889447331429;
  v49 = -1;
  v57 = -1;
  LODWORD(v55) = v31;
  v41 = -16711936;
  v56 = HIDWORD(v61);
  v42 = 0;
  v50 = 0;
  v58 = 0;
  v26 = 1.0 - 1.0 / v24;
  v39 = v26;
  v27 = v26;
  v28 = 1.0 / a7;
  v40 = v28;
  v43 = 1.0;
  v44 = 1.0;
  v45 = a5 - v65;
  v46 = v66 + a6;
  v47 = v27;
  v48 = v28;
  v51 = 0.0;
  v52 = 1.0;
  v53 = a1 - v17;
  v54 = v16 + a2;
  v59 = 0.0;
  v60 = 0.0;
  (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
    *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
    27,
    1);
  (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
    *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
    19,
    2);
  (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
    *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
    20,
    2);
  (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
    *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
    26,
    0);
  (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
    *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
    14,
    0);
  (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
    *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
    22,
    1);
  (*(void (__stdcall **)(_DWORD, _DWORD, int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 152))(
    *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
    0,
    a9);
  (*(void (__stdcall **)(_DWORD, signed int, signed int, float *, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56)
                                                                                         + 112))(
    *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
    6,
    452,
    &v29,
    4,
    24);
  (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
    *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
    27,
    0);
  (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
    *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
    19,
    2);
  (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
    *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
    20,
    1);
  (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
    *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
    26,
    1);
  (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
    *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
    14,
    1);
  return (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
           *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
           22,
           2);
}

//----- (004A4CC9) --------------------------------------------------------
int __stdcall sub_4A4CC9(int a1, int a2)
{
  int result; // eax@1
  int v3; // esi@1
  int v4; // edx@3
  int v5; // ecx@3
  int v6; // edi@7
  int v7; // edx@8
  char *v8; // ecx@8
  double v9; // st6@9
  char v10; // zf@9
  double v11; // st6@10
  int v12; // ebx@13
  int v13; // ecx@16
  int v14; // [sp+Ch] [bp-4h]@1
  int v15; // [sp+18h] [bp+8h]@8

  v3 = a1;
  v14 = 1232348160;
  result = *(_DWORD *)(a1 + 16);
  if ( result >= 3 )
  {
    if ( result > 0 )
    {
      v5 = a1 + 268;
      v4 = *(_DWORD *)(a1 + 16);
      do
      {
        if ( *(float *)v5 < (double)*(float *)&v14 )
          v14 = *(_DWORD *)v5;
        v5 += 16;
        --v4;
      }
      while ( v4 );
    }
    result = 156 * sub_4A1B22_Billboard_ProbablyAddToListAndSortByZOrder(v14);
    v6 = 0;
    pBillboardRenderListD3D3[result/156].dword_000090 = 0;
    pBillboardRenderListD3D3[result/156].uParentBillboardID = -1;
    pBillboardRenderListD3D3[result/156].int_00008C = 2;
    if ( *(_DWORD *)(a1 + 16) > 0 )
    {
      v7 = a1 + 268;
      v15 = a2 & 0xFF000000;
      v8 = (char *)&pBillboardRenderListD3D3[result/156].pQuad[0].z;
      do
      {
        v10 = dword_6BE360 == 1;
        *((_DWORD *)v8 - 2) = *(_DWORD *)(v7 - 8);
        *((_DWORD *)v8 - 1) = *(_DWORD *)(v7 - 4);
        v9 = *(float *)v7;
        if ( v10 )
          v11 = v9 * 0.06175889447331429;
        else
          v11 = v9 * 1000.0 / (double)pStruct9_global->shading_dist_mist;
        *(float *)v8 = 1.0 - 1.0 / v11;
        *((float *)v8 + 1) = 1.0 / *(float *)v7;
        if ( v15 )
          v12 = *(_DWORD *)(v7 + 4);
        else
          v12 = a2;
        *((_DWORD *)v8 + 3) = 0;
        *((_DWORD *)v8 + 2) = v12;
        ++v6;
        v7 += 16;
        *((float *)v8 + 4) = 0.0;
        *((float *)v8 + 5) = 0.0;
        v8 += 32;
      }
      while ( v6 < *(_DWORD *)(v3 + 16) );
    }
    v13 = *(_DWORD *)(v3 + 16);

    pBillboardRenderListD3D3[result/156].pTexture = 0;
    pBillboardRenderListD3D3[result/156].uNumVertices = v13;
    pBillboardRenderListD3D3[result/156].flt_000088 = v14;
  }
  return result;
}



//----- (004A5190) --------------------------------------------------------
void __cdecl sub_4A5190()
{
  LODFile_Bitmaps_LOD.sub_41033D();
  LODFile_Bitmaps_LOD.sub_410423();
  LODFile_Sprites_LOD.sub_4ACADA();
}

//----- (004A52F1) --------------------------------------------------------
int __thiscall Render_sub_4A52F1(int _this, int a2, float a3)
{
  unsigned int v3; // esi@1
  double v4; // st7@2
  int result; // eax@6
  double v6; // st7@6
  double v7; // st6@6
  int v8; // eax@6
  double v9; // st5@6
  double v10; // st4@6
  int v11; // eax@6
  const char *v12; // ST18_4@6
  unsigned int v13; // ST1C_4@6
  int v14; // ST20_4@6
  int v15; // eax@6
  signed int v16; // eax@7
  int v17; // eax@7
  int v18; // ecx@7
  unsigned int v19; // ecx@8
  __int16 v20; // ax@10
  int v21; // edx@10
  int v22; // edi@10
  void *v23; // esi@10
  int v24; // esi@10
  int v25; // ecx@11
  int v26; // edx@12
  __int16 v27; // ax@15
  int v28; // edx@15
  int v29; // edi@15
  void *v30; // esi@15
  int v31; // esi@15
  int v32; // ecx@16
  int v33; // edx@17
  int v34; // [sp-Ch] [bp-ACh]@11
  int v35; // [sp-Ch] [bp-ACh]@16
  float v36; // [sp+Ch] [bp-94h]@6
  float v37; // [sp+10h] [bp-90h]@6
  float v38; // [sp+14h] [bp-8Ch]@6
  float v39; // [sp+18h] [bp-88h]@6
  int v40; // [sp+1Ch] [bp-84h]@6
  int v41; // [sp+20h] [bp-80h]@6
  float v42; // [sp+24h] [bp-7Ch]@6
  float v43; // [sp+28h] [bp-78h]@6
  float v44; // [sp+2Ch] [bp-74h]@6
  float v45; // [sp+30h] [bp-70h]@6
  float v46; // [sp+34h] [bp-6Ch]@6
  float v47; // [sp+38h] [bp-68h]@6
  int v48; // [sp+3Ch] [bp-64h]@6
  int v49; // [sp+40h] [bp-60h]@6
  float v50; // [sp+44h] [bp-5Ch]@6
  float v51; // [sp+48h] [bp-58h]@6
  float v52; // [sp+4Ch] [bp-54h]@6
  float v53; // [sp+50h] [bp-50h]@6
  float v54; // [sp+54h] [bp-4Ch]@6
  float v55; // [sp+58h] [bp-48h]@6
  int v56; // [sp+5Ch] [bp-44h]@6
  int v57; // [sp+60h] [bp-40h]@6
  float v58; // [sp+64h] [bp-3Ch]@6
  float v59; // [sp+68h] [bp-38h]@6
  float v60; // [sp+6Ch] [bp-34h]@6
  float v61; // [sp+70h] [bp-30h]@6
  float v62; // [sp+74h] [bp-2Ch]@6
  float v63; // [sp+78h] [bp-28h]@6
  int v64; // [sp+7Ch] [bp-24h]@6
  int v65; // [sp+80h] [bp-20h]@6
  float v66; // [sp+84h] [bp-1Ch]@6
  float v67; // [sp+88h] [bp-18h]@6
  int v68; // [sp+8Ch] [bp-14h]@7
  int v69; // [sp+90h] [bp-10h]@7
  double v70; // [sp+94h] [bp-Ch]@6
  float v71; // [sp+9Ch] [bp-4h]@6

  v3 = 0;
  if ( *(_DWORD *)(_this + 262280) )
  {
    v4 = a3;
    if ( a3 <= memory_4D8410.d1_0 )
    {
      if ( v4 < 0.0 )
        v4 = 0.0;
    }
    else
    {
      v4 = 1.0;
    }
    a3 = v4 * 255.0;
    v70 = a3 + 6.755399441055744e15;
    LODWORD(v71) = LODWORD(v70);
    v6 = (double)pOldViewport->uGameX;
    v36 = v6;
    v7 = (double)pOldViewport->uGameY;
    v8 = a2 | (LODWORD(v70) << 24);
    a2 = pOldViewport->uGameW + 1;
    v41 = 0;
    v37 = v7;
    v40 = v8;
    v48 = v8;
    v38 = 0.0;
    v56 = v8;
    v64 = v8;
    v39 = 1.0;
    v49 = 0;
    v42 = 0.0;
    v57 = 0;
    v65 = 0;
    v43 = 0.0;
    v44 = v6;
    v9 = (double)(pOldViewport->uGameW + 1);
    v45 = v9;
    v46 = 0.0;
    v47 = 1.0;
    v50 = 0.0;
    v51 = 0.0;
    v10 = (double)pOldViewport->uGameZ;
    v52 = v10;
    v53 = v9;
    v54 = 0.0;
    v55 = 1.0;
    v58 = 0.0;
    v59 = 0.0;
    v60 = v10;
    v61 = v7;
    v62 = 0.0;
    v63 = 1.0;
    v66 = 0.0;
    v67 = 0.0;
    (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 152))(
      *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
      0,
      0);
    (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
      *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
      28,
      0);
    (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
      *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
      27,
      1);
    (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
      *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
      14,
      0);
    (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
      *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
      19,
      5);
    (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
      *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
      20,
      6);
    (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
      *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
      26,
      0);
    (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
      *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
      23,
      8);
    (*(void (__stdcall **)(_DWORD, signed int, signed int, float *, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56)
                                                                                           + 112))(
      *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
      6,
      452,
      &v36,
      4,
      28);
    v11 = (*(int (__stdcall **)(_DWORD, signed int, signed int, _DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56)
                                                                                           + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            19,
            2,
            (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16blt.cpp",
            297,
            0);
    CheckHRESULT((void **)&a2, v11, v12, v13, v14);
    v15 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            20,
            1);
    CheckHRESULT((void **)&a2, v15, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16blt.cpp", 0x12Au, 0);
    (*(void (__cdecl **)(_DWORD, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int, _DWORD, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
      *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
      27,
      0,
      LODWORD(v36),
      LODWORD(v37),
      LODWORD(v38),
      LODWORD(v39),
      v40,
      v41,
      LODWORD(v42),
      LODWORD(v43),
      LODWORD(v44),
      LODWORD(v45),
      LODWORD(v46),
      LODWORD(v47),
      v48,
      v49,
      LODWORD(v50),
      LODWORD(v51),
      LODWORD(v52),
      LODWORD(v53),
      LODWORD(v54),
      LODWORD(v55),
      v56,
      v57,
      LODWORD(v58),
      LODWORD(v59),
      LODWORD(v60),
      LODWORD(v61),
      LODWORD(v62),
      LODWORD(v63),
      v64,
      v65,
      LODWORD(v66),
      LODWORD(v67));
    (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
      *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
      14,
      1);
    (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
      *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
      26,
      1);
    result = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
               *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
               23,
               2);
  }
  else
  {
    v71 = (memory_4D8410.d1_0 - a3) * 65536.0;
    v70 = v71 + 6.755399441055744e15;
    LODWORD(a3) = LODWORD(v70);
    v69 = (pOldViewport->uGameZ - pOldViewport->uGameX) >> 1;
    HIDWORD(v70) = pOldViewport->uGameW - pOldViewport->uGameY + 1;
    v17 = pOldViewport->uGameX + *(_DWORD *)(_this + 262384) - pOldViewport->uGameZ;
    v18 = *(_DWORD *)(_this + 262380) + 2 * (pOldViewport->uGameX + pOldViewport->uGameY * *(_DWORD *)(_this + 262384));
    v68 = 2 * v17;
    LODWORD(v71) = v18;
    v16 = (signed int)&unk_F1B430;
    do
    {
      v19 = v3;
      v3 += LODWORD(a3);
      *(_DWORD *)v16 = v19 >> 16;
      v16 += 4;
    }
    while ( v16 < (signed int)&dword_F1B4B0 );
    if ( pD3DRenderer->uNumTargetGBits == 6 )
    {
      v20 = sub_42690D(a2);
      v24 = (65536 - LODWORD(a3)) * (v20 & 0x1F);
      a2 = (((65536 - LODWORD(a3)) * (unsigned __int16)(v20 & 0xF800) & 0xF800FFFF | v24 & 0x1F0000 | (65536 - LODWORD(a3)) * (v20 & 0x7E0) & 0x7E00000u) >> 16 << 16) | (((65536 - LODWORD(a3)) * (unsigned __int16)(v20 & 0xF800) & 0xF800FFFF | v24 & 0x1F0000 | (65536 - LODWORD(a3)) * (v20 & 0x7E0) & 0x7E00000u) >> 16);
      v22 = LODWORD(v71);
      v23 = off_4EFDB0;
      v21 = HIDWORD(v70);
      do
      {
        v25 = v69;
        v34 = v21;
        do
        {
          v26 = (*(_DWORD *)((char *)v23
                           + ((((unsigned __int16)(*(_WORD *)((char *)v23 + ((*(_DWORD *)v22 & 0xF800u) >> 9)) << 11) | *(_WORD *)v22 & 0x7FF) & 0x7C0u) >> 4)) << 6) | (*(_DWORD *)((char *)v23 + ((((*(_DWORD *)((char *)v23 + ((*(_DWORD *)v22 & 0xF800u) >> 9)) << 11) | (*(_DWORD *)((char *)v23 + ((*(_DWORD *)v22 & 0xF8000000u) >> 25)) << 27) | *(_DWORD *)v22 & 0x7FF07FF) & 0x7C00000u) >> 20)) << 22) | ((*(_DWORD *)((char *)v23 + ((*(_DWORD *)v22 & 0xF800u) >> 9)) << 11) | (*(_DWORD *)((char *)v23 + ((*(_DWORD *)v22 & 0xF8000000u) >> 25)) << 27) | *(_DWORD *)v22 & 0x7FF07FF) & 0xF81FF81F;
          result = a2
                 + (*((_DWORD *)v23
                    + (((unsigned __int8)(*((_BYTE *)v23
                                          + ((((unsigned __int16)(*(_WORD *)((char *)v23
                                                                           + ((*(_DWORD *)v22 & 0xF800u) >> 9)) << 11) | *(_WORD *)v22 & 0x7FF) & 0x7C0u) >> 4)) << 6) | *(_BYTE *)v22 & 0x1F) & 0x1F)) | (*(_DWORD *)((char *)v23 + ((v26 & 0x1F0000u) >> 14)) << 16) | ((*(_DWORD *)((char *)v23 + ((((unsigned __int16)(*(_WORD *)((char *)v23 + ((*(_DWORD *)v22 & 0xF800u) >> 9)) << 11) | *(_WORD *)v22 & 0x7FF) & 0x7C0u) >> 4)) << 6) | (*(_DWORD *)((char *)v23 + ((((*(_DWORD *)((char *)v23 + ((*(_DWORD *)v22 & 0xF800u) >> 9)) << 11) | (*(_DWORD *)((char *)v23 + ((*(_DWORD *)v22 & 0xF8000000u) >> 25)) << 27) | *(_DWORD *)v22 & 0x7FF07FF) & 0x7C00000u) >> 20)) << 22) | ((*(_DWORD *)((char *)v23 + ((*(_DWORD *)v22 & 0xF800u) >> 9)) << 11) | (*(_DWORD *)((char *)v23 + ((*(_DWORD *)v22 & 0xF8000000u) >> 25)) << 27) | *(_DWORD *)v22 & 0x7FF07FF) & 0xF81FF81F) & 0xFFE0FFE0);
          *(_DWORD *)v22 = result;
          v22 += 4;
          --v25;
        }
        while ( v25 );
        v22 += v68;
        v21 = v34 - 1;
      }
      while ( v34 != 1 );
    }
    else
    {
      v27 = sub_4268E3(a2);
      v31 = (65536 - LODWORD(a3)) * (v27 & 0x1F);
      a2 = (((65536 - LODWORD(a3)) * (v27 & 0x7C00) & 0x7C000000 | v31 & 0x1F0000 | (65536 - LODWORD(a3))
                                                                                  * (v27 & 0x3E0) & 0x3E00000u) >> 16 << 16) | (((65536 - LODWORD(a3)) * (v27 & 0x7C00) & 0x7C000000 | v31 & 0x1F0000 | (65536 - LODWORD(a3)) * (v27 & 0x3E0) & 0x3E00000u) >> 16);
      v29 = LODWORD(v71);
      v30 = off_4EFDB0;
      v28 = HIDWORD(v70);
      do
      {
        v32 = v69;
        v35 = v28;
        do
        {
          v33 = 32
              * *(_DWORD *)((char *)v30
                          + ((((unsigned __int16)(*(_WORD *)((char *)v30 + ((*(_DWORD *)v29 & 0x7C00u) >> 8)) << 10) | *(_WORD *)v29 & 0x3FF) & 0x3E0u) >> 3)) | (*(_DWORD *)((char *)v30 + ((((*(_DWORD *)((char *)v30 + ((*(_DWORD *)v29 & 0x7C00u) >> 8)) << 10) | (*(_DWORD *)((char *)v30 + ((*(_DWORD *)v29 & 0x7C000000u) >> 24)) << 26) | *(_DWORD *)v29 & 0x3FF03FF) & 0x3E00000u) >> 19)) << 21) | ((*(_DWORD *)((char *)v30 + ((*(_DWORD *)v29 & 0x7C00u) >> 8)) << 10) | (*(_DWORD *)((char *)v30 + ((*(_DWORD *)v29 & 0x7C000000u) >> 24)) << 26) | *(_DWORD *)v29 & 0x3FF03FF) & 0x7C1F7C1F;
          result = a2
                 + (*((_DWORD *)v30
                    + (((unsigned __int8)(32
                                        * *((_BYTE *)v30
                                          + ((((unsigned __int16)(*(_WORD *)((char *)v30
                                                                           + ((*(_DWORD *)v29 & 0x7C00u) >> 8)) << 10) | *(_WORD *)v29 & 0x3FF) & 0x3E0u) >> 3))) | *(_BYTE *)v29 & 0x1F) & 0x1F)) | (*(_DWORD *)((char *)v30 + ((v33 & 0x1F0000u) >> 14)) << 16) | (32 * *(_DWORD *)((char *)v30 + ((((unsigned __int16)(*(_WORD *)((char *)v30 + ((*(_DWORD *)v29 & 0x7C00u) >> 8)) << 10) | *(_WORD *)v29 & 0x3FF) & 0x3E0u) >> 3)) | (*(_DWORD *)((char *)v30 + ((((*(_DWORD *)((char *)v30 + ((*(_DWORD *)v29 & 0x7C00u) >> 8)) << 10) | (*(_DWORD *)((char *)v30 + ((*(_DWORD *)v29 & 0x7C000000u) >> 24)) << 26) | *(_DWORD *)v29 & 0x3FF03FF) & 0x3E00000u) >> 19)) << 21) | ((*(_DWORD *)((char *)v30 + ((*(_DWORD *)v29 & 0x7C00u) >> 8)) << 10) | (*(_DWORD *)((char *)v30 + ((*(_DWORD *)v29 & 0x7C000000u) >> 24)) << 26) | *(_DWORD *)v29 & 0x3FF03FF) & 0x7C1F7C1F) & 0xFFE0FFE0);
          *(_DWORD *)v29 = result;
          v29 += 4;
          --v32;
        }
        while ( v32 );
        v29 += v68;
        v28 = v35 - 1;
      }
      while ( v35 != 1 );
    }
  }
  return result;
}

//----- (004A57E9) --------------------------------------------------------
void __cdecl sub_4A57E9()
{
  int v0; // eax@3
  int v1; // eax@3
  int v2; // eax@3
  int v3; // eax@3
  int v4; // eax@3
  int v5; // [sp+4h] [bp-14h]@3
  __int64 v6; // [sp+8h] [bp-10h]@3
  int v7; // [sp+10h] [bp-8h]@3
  char v8; // [sp+14h] [bp-4h]@3

  if ( !pD3DRenderer->bSceneBegun)
  {
    if ( pD3DRenderer->dword_040110 )
    {
      v7 = pOldViewport->uGameY;
      v5 = 0;
      v6 = 2748779069440i64;
      v0 = (*(int (__stdcall **)(int, _DWORD, _DWORD, int, int *, signed int))(*(_DWORD *)pD3DRenderer->pdds4_BackBuffer + 28))(
             (int)pD3DRenderer->pdds4_BackBuffer,
             0,
             0,
             (int)pD3DRenderer->dword_040098,
             &v5,
             16);
      CheckHRESULT((void **)&v8, v0, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16blt.cpp", 0x39Eu, 0);
      HIDWORD(v6) = 640;
      v5 = 0;
      LODWORD(v6) = pOldViewport->uGameW + 1;
      v7 = 480;
      v1 = (*(int (__stdcall **)(int, _DWORD, int, int, int *, signed int))(*(_DWORD *)pD3DRenderer->pdds4_BackBuffer + 28))(
             (int)pD3DRenderer->pdds4_BackBuffer,
             0,
             pOldViewport->uGameW + 1,
             (int)pD3DRenderer->dword_040098,
             &v5,
             16);
      CheckHRESULT((void **)&v8, v1, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16blt.cpp", 0x3A9u, 0);
      HIDWORD(v6) = pOldViewport->uGameX;
      v7 = pOldViewport->uGameW + 1;
      v5 = 0;
      LODWORD(v6) = pOldViewport->uGameY;
      v2 = (*(int (__stdcall **)(int, _DWORD, _DWORD, int, int *, signed int))(*(_DWORD *)pD3DRenderer->pdds4_BackBuffer + 28))(
             (int)pD3DRenderer->pdds4_BackBuffer,
             0,
             pOldViewport->uGameY,
             (int)pD3DRenderer->dword_040098,
             &v5,
             16);
      CheckHRESULT((void **)&v8, v2, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16blt.cpp", 0x3B4u, 0);
      v5 = pOldViewport->uGameZ;
      LODWORD(v6) = pOldViewport->uGameY;
      HIDWORD(v6) = 640;
      v7 = pOldViewport->uGameW + 1;
      v3 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)pD3DRenderer->pdds4_BackBuffer + 28))(
             (int)pD3DRenderer->pdds4_BackBuffer,
             pOldViewport->uGameZ,
             pOldViewport->uGameY,
             (int)pD3DRenderer->dword_040098,
             (int)&v5,
             16);
      CheckHRESULT((void **)&v8, v3, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16blt.cpp", 0x3BFu, 0);
      v7 = pOldViewport->uGameW + 1;
      v5 = pOldViewport->uGameX;
      v6 = pOldViewport->uGameY;
      v4 = (*(int (__stdcall **)(int, int, _DWORD, int, int *, signed int))(*(_DWORD *)pD3DRenderer->pdds4_BackBuffer + 28))(
             (int)pD3DRenderer->pdds4_BackBuffer,
             pOldViewport->uGameX,
             pOldViewport->uGameY,
             (int)pD3DRenderer->dword_040098,
             &v5,
             17);
      CheckHRESULT((void **)&v8, v4, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16blt.cpp", 0x3CAu, 0);
    }
  }
}

//----- (004A5D33) --------------------------------------------------------
void __thiscall sub_4A5D33(int _this, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // esi@1
  int v7; // ecx@3
  int v8; // ebx@3
  int v9; // edi@3
  int v10; // ecx@3
  int v11; // edx@3
  int v12; // eax@4
  int v13; // eax@5
  int v14; // eax@6
  int v15; // eax@7
  int v16; // edx@8
  int v17; // eax@10
  int v18; // ecx@11
  int v19; // ecx@14
  int v20; // eax@16
  int v21; // ecx@17
  int v22; // eax@21
  int v23; // edi@23
  int v25; // [sp+Ch] [bp-4h]@3
  int v26; // [sp+18h] [bp+8h]@21
  unsigned int v27; // [sp+1Ch] [bp+Ch]@20
  int v28; // [sp+20h] [bp+10h]@3
  int v29; // [sp+20h] [bp+10h]@21
  int v30; // [sp+28h] [bp+18h]@3

  v6 = _this;
  if ( *(_DWORD *)(_this + 262372) )
  {
    if ( a6 )
    {
      v8 = *(_DWORD *)(_this + 262380) + 2 * (a2 + a3 * *(_DWORD *)(_this + 262384));
      v10 = *(_WORD *)(a6 + 20);
      v25 = *(_WORD *)(a6 + 20);
      v11 = a4 + a5 * v10;
      v7 = v10 - a4;
      v28 = v7;
      v9 = *(_WORD *)(a6 + 22) - a5;
      v30 = *(_DWORD *)(a6 + 36) + 2 * v11;
      if ( *(_DWORD *)(v6 + 262404) )
      {
        v12 = *(_DWORD *)(v6 + 262392);
        if ( a2 < v12 )
        {
          v13 = 2 * (v12 - a2);
          v30 += v13;
          v7 += a2 - *(_DWORD *)(v6 + 262392);
          v8 += v13;
          v28 = v7;
        }
        v14 = *(_DWORD *)(v6 + 262388);
        if ( a3 < v14 )
        {
          v15 = v14 - a3;
          v30 += 2 * v25 * v15;
          v9 += a3 - *(_DWORD *)(v6 + 262388);
          v7 = v28;
          v8 += 2 * *(_DWORD *)(v6 + 262384) * v15;
        }
        v16 = *(_DWORD *)(v6 + 262392);
        if ( v16 < a2 )
          v16 = a2;
        v17 = *(_DWORD *)(v6 + 262400);
        if ( v7 + v16 > v17 )
        {
          v18 = *(_DWORD *)(v6 + 262392);
          if ( v18 < a2 )
            v18 = a2;
          v28 = v17 - v18;
        }
        v19 = *(_DWORD *)(v6 + 262388);
        if ( v19 < a3 )
          v19 = a3;
        v20 = *(_DWORD *)(v6 + 262396);
        if ( v9 + v19 > v20 )
        {
          v21 = *(_DWORD *)(v6 + 262388);
          if ( v21 < a3 )
            v21 = a3;
          v9 = v20 - v21;
        }
      }
      v27 = 0xFF00FFFF;
      if ( v9 > 0 )
      {
        v22 = v28;
        v26 = v9;
        v29 = 2 * (v25 - v28);
        do
        {
          if ( v22 > 0 )
          {
            v23 = v22;
            do
            {
              if ( *(_WORD *)v30 != v27 )
                *(_WORD *)v8 = *(_WORD *)v30;
              v30 += 2;
              v8 += 2;
              --v23;
            }
            while ( v23 );
          }
          v8 += 2 * (*(_DWORD *)(v6 + 262384) - v22);
          v30 += v29;
        }
        while ( v26-- != 1 );
      }
    }
  }
}

//----- (004A601E) --------------------------------------------------------
void __thiscall Render_sub_4A601E(struct BaseRender* _this, int a2, int a3, cTexture *a4, int a5)
{
  int v5; // edx@3
  int v6; // ebx@3
  void *v7; // esi@3
  int v8; // esi@3
  int v9; // eax@4
  int v10; // eax@6
  int v11; // edi@8
  int v12; // eax@10
  int v13; // edi@11
  int v14; // edi@14
  int v15; // eax@16
  int v16; // ecx@17
  int v17; // [sp+18h] [bp+Ch]@3
  int v18; // [sp+1Ch] [bp+10h]@3

  if ( *(_DWORD *)(_this + 262372) )
  {
    if ( a4 )
    {
      v5 = a3;
      v6 = *(_WORD *)(a4 + 26);
      v8 = 5 * a3;
      v17 = *(_WORD *)(a4 + 26);
      v7 = (void *)(*(_DWORD *)(_this + 262196) + 4 * (a2 + (v8 << 7)));
      v18 = *(_WORD *)(a4 + 24);
      if ( *(_DWORD *)(_this + 262404) )
      {
        v9 = *(_DWORD *)(_this + 262392);
        if ( a2 < v9 )
        {
          v18 += a2 - v9;
          v7 = (char *)v7 + 4 * (v9 - a2);
        }
        v10 = *(_DWORD *)(_this + 262388);
        if ( v5 < v10 )
        {
          v17 += v5 - v10;
          v7 = (char *)v7 + 2560 * (v10 - v5);
        }
        v11 = *(_DWORD *)(_this + 262392);
        if ( v11 < a2 )
          v11 = a2;
        v12 = *(_DWORD *)(_this + 262400);
        if ( v18 + v11 > v12 )
        {
          v13 = *(_DWORD *)(_this + 262392);
          if ( v13 < a2 )
            v13 = a2;
          v18 = v12 - v13;
        }
        v14 = *(_DWORD *)(_this + 262388);
        if ( v14 < v5 )
          v14 = v5;
        v6 = v17;
        v15 = *(_DWORD *)(_this + 262396);
        if ( v17 + v14 > v15 )
        {
          v16 = *(_DWORD *)(_this + 262388);
          if ( v16 < v5 )
            v16 = v5;
          v6 = v15 - v16;
        }
      }
      if ( v6 > 0 )
      {
        do
        {
          if ( v18 > 0 )
          {
            memset(v7, a5, 4 * v18);
            v7 = (char *)v7 + 4 * v18;
          }
          v7 = (char *)v7 + 4 * (640 - v18);
          --v6;
        }
        while ( v6 );
      }
    }
  }
}

//----- (004A612A) --------------------------------------------------------
void Render_DrawTextureToZBuffer(struct BaseRender *_this, unsigned int uOutX, unsigned int uOutY, cTexture *pTexture, int sZValue)
{
  //int v5; // eax@2
  int v6; // edx@3
  int v7; // ebx@3
  int v8; // edi@3
  int v9; // eax@4
  int v10; // eax@5
  int v11; // esi@6
  int v12; // esi@8
  int v13; // eax@10
  int v14; // esi@11
  int v15; // esi@14
  int v16; // eax@16
  int v17; // ecx@17
  int v18; // edx@23
  int v20; // [sp+Ch] [bp-Ch]@3
  int v21; // [sp+10h] [bp-8h]@3
  int v22; // [sp+20h] [bp+8h]@21

  unsigned int *pTexturePixels; // [sp+24h] [bp+Ch]@3

  int *v24; // [sp+28h] [bp+10h]@3

  if (!_this->bSceneBegun || !pTexture)
    return;

      v6 = uOutY;
      v7 = pTexture->uTextureHeight;
      v24 = _this->pActiveZBuffer + (uOutX + 640 * uOutY);

      pTexturePixels = pTexture->pTruecolorPixels;

      v8 = pTexture->uTextureWidth;
      v21 = pTexture->uTextureWidth;
      v20 = pTexture->uTextureWidth;
      if (_this->dword_040104)
      {
        v9 = _this->uClipRectX;
        if (uOutX < v9)
        {
          v10 = v9 - uOutX;
          pTexturePixels += v10;
          v8 += uOutX - _this->uClipRectX;
          v21 = v8;
          v24 += v10;
        }
        v11 = _this->uClipRectY;
        if ( v6 < v11 )
        {
          pTexturePixels += v20 * (v11 - v6);
          v7 += v6 - v11;
          v24 += 640 * (v11 - v6);
          v8 = v21;
        }
        v12 = _this->uClipRectX;
        if ( v12 < uOutX)
          v12 = uOutX;
        v13 = _this->uClipRectZ;
        if ( v8 + v12 > v13 )
        {
          v14 = _this->uClipRectX;
          if ( v14 < uOutX)
            v14 = uOutX;
          v8 = v13 - v14;
        }
        v15 = _this->uClipRectY;
        if ( v15 < v6 )
          v15 = v6;
        v16 = _this->uClipRectW;
        if ( v7 + v15 > v16 )
        {
          v17 = _this->uClipRectY;
          if ( v17 >= v6 )
            v6 = v17;
          v7 = v16 - v6;
        }
      }

      if ( v7 > 0 )
      {
        v22 = v7;
        do
        {
          if ( v8 > 0 )
          {
            v18 = v8;
            do
            {

             if (*pTexturePixels++)

                *v24 = sZValue;
              v24++;
              --v18;
            }
            while ( v18 );
          }
          v24 += (640 - v8);
          pTexturePixels += v20 - v8;
        }
        while ( v22-- != 1 );
      }
}

//----- (004A63E6) --------------------------------------------------------
void __thiscall Render_sub_4A63E6(int _this, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // eax@2
  int v9; // ebx@4
  int v10; // esi@6
  int v11; // edi@7
  int v12; // eax@9
  int v13; // eax@10
  int v14; // edx@11
  int v15; // eax@13
  int v16; // edx@14
  int v17; // edx@17
  int v18; // eax@19
  int v19; // edx@20
  int v20; // eax@27
  int v21; // edx@29
  int v22; // [sp+Ch] [bp-Ch]@6
  int v23; // [sp+Ch] [bp-Ch]@24
  int v24; // [sp+10h] [bp-8h]@6
  int v25; // [sp+14h] [bp-4h]@6
  int i; // [sp+20h] [bp+8h]@25
  int v27; // [sp+24h] [bp+Ch]@23
  int v28; // [sp+28h] [bp+10h]@6

  if ( *(_DWORD *)(_this + 262372) )
  {
    v8 = a4;
    if ( a4 )
    {
      if ( *(_DWORD *)(a4 + 64) )
      {
        v9 = a5;
        if ( a5 )
        {
          if ( *(_DWORD *)(a5 + 64) )
          {
            v10 = *(_DWORD *)(_this + 262380) + 2 * (a2 + a3 * *(_DWORD *)(_this + 262384));
            v28 = *(_DWORD *)(a4 + 48);
            v25 = *(_WORD *)(v8 + 24);
            v24 = *(_WORD *)(v8 + 26);
            v22 = *(_WORD *)(v8 + 24);
            if ( *(_DWORD *)(_this + 262404) )
            {
              v11 = *(_DWORD *)(_this + 262392);
              if ( a2 < v11 )
              {
                v28 += v11 - a2;
                v25 += a2 - v11;
                v9 = a5;
                v10 += 2 * (v11 - a2);
              }
              v12 = *(_DWORD *)(_this + 262388);
              if ( a3 < v12 )
              {
                v13 = v12 - a3;
                v9 = a5;
                v28 += v22 * v13;
                v24 += a3 - *(_DWORD *)(_this + 262388);
                v10 += 2 * *(_DWORD *)(_this + 262384) * v13;
              }
              v14 = *(_DWORD *)(_this + 262392);
              if ( v14 < a2 )
                v14 = a2;
              v15 = *(_DWORD *)(_this + 262400);
              if ( v25 + v14 > v15 )
              {
                v16 = *(_DWORD *)(_this + 262392);
                if ( v16 < a2 )
                  v16 = a2;
                v25 = v15 - v16;
              }
              v17 = *(_DWORD *)(_this + 262388);
              if ( v17 < a3 )
                v17 = a3;
              v18 = *(_DWORD *)(_this + 262396);
              if ( v24 + v17 > v18 )
              {
                v19 = *(_DWORD *)(_this + 262388);
                if ( v19 < a3 )
                  v19 = a3;
                v24 = v18 - v19;
              }
            }
            v27 = 0;
            if ( v24 > 0 )
            {
              v23 = v22 - v25;
              do
              {
                for ( i = 0; i < v25; ++v28 )
                {
                  if ( *(_BYTE *)v28 )
                  {
                    v20 = *(_BYTE *)((i & *(_WORD *)(v9 + 32))
                                   + *(_WORD *)(v9 + 24) * (v27 & *(_WORD *)(v9 + 34))
                                   + *(_DWORD *)(v9 + 48));
                    if ( v20 >= a7 )
                    {
                      if ( v20 <= a8 )
                      {
                        v21 = a7 + (a6 + v20) % (2 * (a8 - a7));
                        if ( (a6 + v20) % (2 * (a8 - a7)) >= a8 - a7 )
                          v21 = 2 * a8 - v21 - a7;
                        v9 = a5;
                        *(_WORD *)v10 = *(_WORD *)(*(_DWORD *)(a5 + 64) + 2 * v21);
                      }
                    }
                  }
                  ++i;
                  v10 += 2;
                }
                ++v27;
                v10 += 2 * (*(_DWORD *)(_this + 262384) - v25);
                v28 += v23;
              }
              while ( v27 < v24 );
            }
          }
        }
      }
    }
  }
}

//----- (004A65CC) --------------------------------------------------------
void __thiscall Render_sub_4A65CC(int _this, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // edi@6
  int v9; // esi@6
  int v10; // eax@7
  int v11; // eax@8
  int v12; // eax@9
  int v13; // eax@10
  int v14; // edx@11
  int v15; // eax@13
  int v16; // edx@14
  int v17; // edx@17
  int v18; // eax@19
  int v19; // edx@20
  int v20; // eax@27
  int v21; // edx@29
  int v24; // [sp+Ch] [bp-Ch]@6
  int v25; // [sp+Ch] [bp-Ch]@24
  int v26; // [sp+14h] [bp-4h]@6
  int v27; // [sp+20h] [bp+8h]@26
  int v28; // [sp+24h] [bp+Ch]@24
  int v29; // [sp+2Ch] [bp+14h]@6

  if ( *(_DWORD *)(_this + 262372) )
  {
    if ( a4 )
    {
      if ( *(_DWORD *)(a4 + 64) )
      {
        if ( a5 )
        {
          if ( *(_DWORD *)(a5 + 64) )
          {
            v9 = *(_DWORD *)(_this + 262380) + 2 * (a2 + a3 * *(_DWORD *)(_this + 262384));
            v26 = *(_DWORD *)(a4 + 48);
            v29 = *(_WORD *)(a4 + 24);
            v8 = *(_WORD *)(a4 + 26);
            v24 = *(_WORD *)(a4 + 24);
            if ( *(_DWORD *)(_this + 262404) )
            {
              v10 = *(_DWORD *)(_this + 262392);
              if ( a2 < v10 )
              {
                v11 = v10 - a2;
                v26 += v11;
                v29 += a2 - *(_DWORD *)(_this + 262392);
                v9 += 2 * v11;
              }
              v12 = *(_DWORD *)(_this + 262388);
              if ( a3 < v12 )
              {
                v13 = v12 - a3;
                v26 += v24 * v13;
                v8 = a3 - *(_DWORD *)(_this + 262388) + *(_WORD *)(a4 + 26);
                v9 += 2 * *(_DWORD *)(_this + 262384) * v13;
              }
              v14 = *(_DWORD *)(_this + 262392);
              if ( v14 < a2 )
                v14 = a2;
              v15 = *(_DWORD *)(_this + 262400);
              if ( v29 + v14 > v15 )
              {
                v16 = *(_DWORD *)(_this + 262392);
                if ( v16 < a2 )
                  v16 = a2;
                v29 = v15 - v16;
              }
              v17 = *(_DWORD *)(_this + 262388);
              if ( v17 < a3 )
                v17 = a3;
              v18 = *(_DWORD *)(_this + 262396);
              if ( v8 + v17 > v18 )
              {
                v19 = *(_DWORD *)(_this + 262388);
                if ( v19 < a3 )
                  v19 = a3;
                v8 = v18 - v19;
              }
            }
            if ( v8 > 0 )
            {
              v28 = v8;
              v25 = v24 - v29;
              do
              {
                if ( v29 > 0 )
                {
                  v27 = v29;
                  do
                  {
                    v20 = *(_BYTE *)v26;
                    if ( v20 >= a7 )
                    {
                      if ( v20 <= a8 )
                      {
                        v21 = a7 + (a6 + v20) % (2 * (a8 - a7));
                        if ( (a6 + v20) % (2 * (a8 - a7)) >= a8 - a7 )
                          v21 = 2 * a8 - v21 - a7;
                        *(_WORD *)v9 = *(_WORD *)(*(_DWORD *)(a4 + 64) + 2 * v21);
                      }
                    }
                    v9 += 2;
                    ++v26;
                  }
                  while ( v27-- != 1 );
                }
                v9 += 2 * (*(_DWORD *)(_this + 262384) - v29);
                v26 += v25;
              }
              while ( v28-- != 1 );
            }
          }
        }
      }
    }
  }
}

//----- (004A6776) --------------------------------------------------------
void __thiscall Render_sub_4A6776(struct BaseRender* _this, int a2, int a3, cTexture *a4)
{
  int v4; // edi@2
  int v5; // eax@4
  int v6; // ebx@4
  int v7; // edx@5
  int v8; // edx@6
  int v9; // edx@7
  int v10; // edx@8
  int v11; // edx@9
  int v12; // esi@12
  int v13; // esi@15
  int v14; // edx@17
  int v15; // esi@18
  int v16; // ebx@22
  char v18; // zf@28
  int v19; // [sp+10h] [bp-10h]@4
  int v20; // [sp+18h] [bp-8h]@4
  int v21; // [sp+1Ch] [bp-4h]@4
  int v22; // [sp+28h] [bp+8h]@24
  int v23; // [sp+2Ch] [bp+Ch]@22
  int v24; // [sp+30h] [bp+10h]@11
  int v25; // [sp+30h] [bp+10h]@22

  if ( *(_DWORD *)(_this + 262372) )
  {
    v4 = (int)a4;
    if ( a4 )
    {
      if ( *(_DWORD *)(a4 + 64) )
      {
        v6 = *(_WORD *)(a4 + 26);
        v5 = *(_DWORD *)(_this + 262380) + 2 * (a2 + a3 * *(_DWORD *)(_this + 262384));
        v20 = *(_DWORD *)(a4 + 48);
        v21 = *(_WORD *)(a4 + 24);
        v19 = *(_WORD *)(a4 + 24);
        if ( *(_DWORD *)(_this + 262404) )
        {
          v7 = *(_DWORD *)(_this + 262392);
          if ( a2 < v7 )
          {
            v8 = v7 - a2;
            v20 += v8;
            v21 += a2 - *(_DWORD *)(_this + 262392);
            v5 += 2 * v8;
          }
          v9 = *(_DWORD *)(_this + 262388);
          v6 = *(_WORD *)(a4 + 26);
          if ( a3 < v9 )
          {
            v10 = v9 - a3;
            v20 += v19 * v10;
            v6 = a3 - *(_DWORD *)(_this + 262388) + *(_WORD *)(a4 + 26);
            v4 = (int)a4;
            v5 += 2 * *(_DWORD *)(_this + 262384) * v10;
          }
          v11 = *(_DWORD *)(_this + 262392);
          if ( v11 < a2 )
            v11 = a2;
          v24 = *(_DWORD *)(_this + 262400);
          if ( v11 + v21 > v24 )
          {
            v12 = *(_DWORD *)(_this + 262392);
            if ( v12 < a2 )
              v12 = a2;
            v21 = v24 - v12;
          }
          v13 = *(_DWORD *)(_this + 262388);
          if ( v13 < a3 )
            v13 = a3;
          v14 = *(_DWORD *)(_this + 262396);
          if ( v6 + v13 > v14 )
          {
            v15 = *(_DWORD *)(_this + 262388);
            if ( v15 < a3 )
              v15 = a3;
            v6 = v14 - v15;
          }
        }
        if ( v6 > 0 )
        {
          v23 = v6;
          v16 = v20;
          v25 = v19 - v21;
          do
          {
            if ( v21 > 0 )
            {
              v22 = v21;
              do
              {
                if ( *(_BYTE *)v16 )
                  *(_WORD *)v5 = *(_WORD *)(_this + 262360) & *(_WORD *)(*(_DWORD *)(v4 + 64) + 2 * *(_BYTE *)v16);
                v5 += 2;
                ++v16;
              }
              while ( v22-- != 1 );
            }
            v16 += v25;
            v18 = v23-- == 1;
            v5 += 2 * (*(_DWORD *)(_this + 262384) - v21);
          }
          while ( !v18 );
        }
      }
    }
  }
}

//----- (004A68EF) --------------------------------------------------------
void Render_DrawTransparentGreenChannel(struct BaseRender* _this, unsigned int uOutX, unsigned int uOutY, cTexture *pTexture)
{
  //int v4; // edi@2
  unsigned int *v5; // eax@4
  int v6; // ebx@4
  int v7; // edx@5
  int v8; // edx@6
  int v9; // edx@7
  int v10; // edx@8
  int v11; // edx@9
  int v12; // esi@12
  int v13; // esi@15
  int v14; // edx@17
  int v15; // esi@18
  int v16; // ebx@22
  char v18; // zf@28
  int v19; // [sp+10h] [bp-10h]@4
  //int v20; // [sp+18h] [bp-8h]@4
  int v21; // [sp+1Ch] [bp-4h]@4
  int v22; // [sp+28h] [bp+8h]@24
  int v23; // [sp+2Ch] [bp+Ch]@22
  int v24; // [sp+30h] [bp+10h]@11
  int v25; // [sp+30h] [bp+10h]@22

  if (!_this->bSceneBegun ||
      !pTexture)
    return;

      //if (pTexture->pPalette)
      //{
  v6 = pTexture->uTextureHeight;
        v5 = _this->pTargetSurface + (uOutX + uOutY * _this->uTargetSurfacePitch);
        //v20 = pTexture->pIndexedPixels;
        v21 = pTexture->uTextureWidth;
        v19 = pTexture->uTextureWidth;

        v16 = 0;
        if (_this->dword_040104)
        {
          v7 = _this->uClipRectX;
          if (uOutX < v7)
          {
            v8 = v7 - uOutX;
            v16 += v8;
            v21 += uOutX - _this->uClipRectX;
            v5 += v8;
          }
          v9 = _this->uClipRectY;
          v6 = pTexture->uTextureHeight;
          if (uOutY < v9)
          {
            v10 = v9 - uOutY;
            v16 += v19 * v10;
            v6 = uOutY - _this->uClipRectY + pTexture->uTextureHeight;
            v5 += _this->uTargetSurfacePitch * v10;
          }
          v11 = _this->uClipRectX;
          if ( v11 < uOutX)
            v11 = uOutX;
          v24 = _this->uClipRectZ;
          if ( v11 + v21 > v24 )
          {
            v12 = _this->uClipRectX;
            if ( v12 < uOutX)
              v12 = uOutX;
            v21 = v24 - v12;
          }
          v13 = _this->uClipRectY;
          if ( v13 < uOutY)
            v13 = uOutY;
          v14 = _this->uClipRectW;
          if ( v6 + v13 > v14 )
          {
            v15 = _this->uClipRectY;
            if ( v15 < uOutY)
              v15 = uOutY;
            v6 = v14 - v15;
          }
        }


        if ( v6 > 0 )
        {
          v23 = v6;
          //v16 = v20;
          v25 = v19 - v21;
          do
          {
            if ( v21 > 0 )
            {
              v22 = v21;
              do
              {
                //if ( *(_BYTE *)v16 )
                  //*v5 = _this->uTargetGMask & *(_WORD *)((int)pTexture->pPalette + 2 * *(_BYTE *)v16);
               if (pTexture->pTruecolorPixels[v16] & 0xFF000000)
                  *v5 = (0xFF000000 | _this->uTargetGMask) & pTexture->pTruecolorPixels[v16];
                v5++;
                ++v16;
              }
              while ( v22-- != 1 );
            }
            v16 += v25;
            v18 = v23-- == 1;
            v5 += (_this->uTargetSurfacePitch - v21);
          }
          while ( !v18 );
        }
}

//----- (004A6A68) --------------------------------------------------------
void __thiscall Render_sub_4A6A68(void *_this, int a2, int a3, int a4, __int16 a5)
{
  int v5; // ebx@1
  __int16 v6; // ax@1
  cTexture cTexture_obj; // [sp+Ch] [bp-48h]@1
  __int16 v8; // [sp+26h] [bp-2Eh]@1

  v5 = (int)_this;
  cTexture_obj.cTexture_Zero();
  v6 = *(_WORD *)(a4 + 26) - a5;
  memcpy(&cTexture_obj, (const void *)a4, sizeof(cTexture));
  v8 = v6;
  if ( v6 > 0 )
    Render_DrawIndexedTexture((BaseRender *)v5, a2, a3, (cTexture *)a4);
}

//----- (004A6DF5) --------------------------------------------------------
void __stdcall sub_4A6DF5(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // ecx@3
  int v7; // ebx@4
  int v8; // edi@4
  int v9; // esi@4
  int v10; // edx@4
  int v11; // eax@6
  int v12; // [sp+14h] [bp+8h]@3
  int v13; // [sp+18h] [bp+Ch]@4
  int v14; // [sp+1Ch] [bp+10h]@4
  int v15; // [sp+20h] [bp+14h]@3

  if ( a1 )
  {
    if ( a4 )
    {
      v12 = a1 + 2 * (*(_DWORD *)a3 + a2 * *(_DWORD *)(a3 + 4));
      v15 = a4 + 2 * (*(_DWORD *)a6 + a5 * *(_DWORD *)(a6 + 4));
      v6 = *(_DWORD *)(a6 + 8) - *(_DWORD *)a6;
      if ( *(_DWORD *)(a6 + 12) - *(_DWORD *)(a6 + 4) > 0 )
      {
        v8 = v12;
        v7 = v15;
        v10 = 2 * (a2 - v6);
        v13 = 2 * (a5 - v6);
        v14 = v10;
        v9 = *(_DWORD *)(a6 + 12) - *(_DWORD *)(a6 + 4);
        do
        {
          if ( v6 > 0 )
          {
            v11 = v6;
            do
            {
              *(_WORD *)v8 = *(_WORD *)v7;
              v8 += 2;
              v7 += 2;
              --v11;
            }
            while ( v11 );
          }
          v8 += v14;
          v7 += v13;
          --v9;
        }
        while ( v9 );
      }
    }
  }
}

//----- (004A6E7E) --------------------------------------------------------
void __thiscall sub_4A6E7E(int _this, int a2, int a3, int a4)
{
  int v4; // eax@4
  int v5; // edx@4
  int v6; // edi@4
  int v7; // edx@5
  int v8; // edx@6
  int v9; // edx@7
  int v10; // edx@8
  int v11; // ebx@9
  int v12; // esi@11
  int v13; // edx@12
  int v14; // ebx@15
  int v15; // esi@17
  int v16; // edi@18
  char v18; // zf@29
  char v20; // zf@38
  int v21; // [sp+14h] [bp-Ch]@4
  int v22; // [sp+18h] [bp-8h]@4
  int v23; // [sp+1Ch] [bp-4h]@4
  int v24; // [sp+28h] [bp+8h]@25
  int v25; // [sp+28h] [bp+8h]@34
  int v26; // [sp+2Ch] [bp+Ch]@23
  int v27; // [sp+2Ch] [bp+Ch]@32

  if ( *(_DWORD *)(_this + 262372) )
  {
    if ( a4 )
    {
      if ( *(_DWORD *)(a4 + 64) )
      {
        v4 = *(_DWORD *)(_this + 262380) + 2 * (a2 + a3 * *(_DWORD *)(_this + 262384));
        v23 = *(_DWORD *)(a4 + 48);
        v5 = *(_WORD *)(a4 + 24);
        v6 = *(_WORD *)(a4 + 26);
        v22 = *(_WORD *)(a4 + 24);
        v21 = *(_WORD *)(a4 + 24);
        if ( *(_DWORD *)(_this + 262404) )
        {
          v7 = *(_DWORD *)(_this + 262392);
          if ( a2 < v7 )
          {
            v8 = v7 - a2;
            v23 += v8;
            v22 += a2 - *(_DWORD *)(_this + 262392);
            v4 += 2 * v8;
          }
          v9 = *(_DWORD *)(_this + 262388);
          if ( a3 < v9 )
          {
            v10 = v9 - a3;
            v23 += v21 * v10;
            v6 = a3 - *(_DWORD *)(_this + 262388) + *(_WORD *)(a4 + 26);
            v4 += 2 * *(_DWORD *)(_this + 262384) * v10;
          }
          v11 = *(_DWORD *)(_this + 262392);
          v5 = v22;
          if ( v11 < a2 )
            v11 = a2;
          v12 = *(_DWORD *)(_this + 262400);
          if ( v22 + v11 > v12 )
          {
            v13 = *(_DWORD *)(_this + 262392);
            if ( v13 < a2 )
              v13 = a2;
            v5 = v12 - v13;
          }
          v14 = *(_DWORD *)(_this + 262388);
          if ( v14 < a3 )
            v14 = a3;
          v15 = *(_DWORD *)(_this + 262396);
          if ( v6 + v14 > v15 )
          {
            v16 = *(_DWORD *)(_this + 262388);
            if ( v16 < a3 )
              v16 = a3;
            v6 = v15 - v16;
          }
        }
        if ( pD3DRenderer->uNumTargetGBits == 5 )
        {
          if ( v6 > 0 )
          {
            v26 = v6;
            do
            {
              if ( v5 > 0 )
              {
                v24 = v5;
                do
                {
                  if ( *(_BYTE *)v23 )
                    *(_WORD *)v4 = ((unsigned int)*(_WORD *)(*(_DWORD *)(a4 + 64) + 2 * *(_BYTE *)v23) >> 1) & 0x3DEF;
                  v4 += 2;
                  ++v23;
                }
                while ( v24-- != 1 );
              }
              v23 += v21 - v5;
              v18 = v26-- == 1;
              v4 += 2 * (*(_DWORD *)(_this + 262384) - v5);
            }
            while ( !v18 );
          }
        }
        else
        {
          if ( v6 > 0 )
          {
            v27 = v6;
            do
            {
              if ( v5 > 0 )
              {
                v25 = v5;
                do
                {
                  if ( *(_BYTE *)v23 )
                    *(_WORD *)v4 = ((unsigned int)*(_WORD *)(*(_DWORD *)(a4 + 64) + 2 * *(_BYTE *)v23) >> 1) & 0x7BEF;
                  v4 += 2;
                  ++v23;
                }
                while ( v25-- != 1 );
              }
              v23 += v21 - v5;
              v20 = v27-- == 1;
              v4 += 2 * (*(_DWORD *)(_this + 262384) - v5);
            }
            while ( !v20 );
          }
        }
      }
    }
  }
}

//----- (004A7063) --------------------------------------------------------
int __thiscall sub_4A7063(void *_this, float a2)
{
  signed int v2; // ecx@1
  signed int v3; // ebx@1
  signed int v4; // edi@1
  signed int v5; // esi@1
  float v6; // ST1C_4@1
  double v7; // ST14_8@1
  float v8; // ST1C_4@1
  double v9; // ST0C_8@1
  double v10; // ST0C_8@1
  double v12; // [sp+10h] [bp-10h]@1
  signed int v13; // [sp+18h] [bp-8h]@1
  signed int v14; // [sp+28h] [bp+8h]@1

  v6 = (double)((unsigned int)_this >> 24) * a2;
  v7 = v6 + 6.755399441055744e15;
  v3 = LODWORD(v7);
  v8 = (double)(((unsigned int)_this >> 16) & 0xFF) * a2;
  v12 = v8 + 6.755399441055744e15;
  v4 = LODWORD(v12);
  *((float *)&v12 + 1) = (double)(unsigned __int16)((_WORD)_this >> 8) * a2;
  v9 = *((float *)&v12 + 1) + 6.755399441055744e15;
  v13 = LODWORD(v9);
  v5 = LODWORD(v9);
  *((float *)&v12 + 1) = (double)(unsigned __int8)_this * a2;
  v10 = *((float *)&v12 + 1) + 6.755399441055744e15;
  v14 = LODWORD(v10);
  v2 = LODWORD(v10);
  if ( v3 > 255 )
    v3 = 255;
  if ( v3 < 0 )
    v3 = 0;
  if ( LODWORD(v12) > 255 )
    v4 = 255;
  if ( v4 < 0 )
    v4 = 0;
  if ( v13 > 255 )
    v5 = 255;
  if ( v5 < 0 )
    v5 = 0;
  if ( v14 > 255 )
    v2 = 255;
  if ( v2 < 0 )
    v2 = 0;
  return v2 | ((v5 | ((v4 | (v3 << 8)) << 8)) << 8);
}

//----- (004A71DC) --------------------------------------------------------
void __thiscall sub_4A71DC(int _this)
{
  unsigned int v1; // edi@1
  int v2; // esi@1
  int v3; // eax@2

  v2 = _this + 1484;
  v1 = *(_DWORD *)(_this + 1484);
  if ( v1 )
  {
    v3 = sub_4775C4(*(_DWORD *)(_this + 1484));
    operator_delete((void *)v1);
  }
  *(_DWORD *)v2 = 0;
}

//----- (004A71FE) --------------------------------------------------------
int __thiscall sub_4A71FE(int _this, float a2, float a3, float a4, float a5, float a6, float a7, int a8)
{
  int result; // eax@1

  result = *(_DWORD *)(_this + 1480);
  if ( result != 32 )
  {
    *(float *)(28 * result + _this + 584) = a2;
    *(float *)(28 * (*(_DWORD *)(_this + 1480) + 21) + _this) = a3;
    *(float *)(28 * *(_DWORD *)(_this + 1480) + _this + 592) = a4;
    *(float *)(28 * *(_DWORD *)(_this + 1480) + _this + 596) = a5;
    *(float *)(28 * *(_DWORD *)(_this + 1480) + _this + 600) = a6;
    *(float *)(28 * *(_DWORD *)(_this + 1480) + _this + 604) = a7;
    result = 28 * *(_DWORD *)(_this + 1480);
    *(_DWORD *)(result + _this + 608) = a8;
    ++*(_DWORD *)(_this + 1480);
  }
  return result;
}

//----- (004A73AA) --------------------------------------------------------
void __thiscall sub_4A73AA(void *_this, int a2, int a3, int a4)
{
  int v4; // eax@1
  void *v5; // edi@1
  int v6; // esi@1
  int v7; // eax@2
  double v8; // st7@2
  double v9; // st6@2
  double v10; // st7@3
  int Dst; // [sp+8h] [bp-68h]@1
  float v12; // [sp+Ch] [bp-64h]@2
  float v13; // [sp+10h] [bp-60h]@2
  float v14; // [sp+14h] [bp-5Ch]@2
  float v15; // [sp+18h] [bp-58h]@2
  float v16; // [sp+1Ch] [bp-54h]@2
  float v17; // [sp+20h] [bp-50h]@2
  int v18; // [sp+24h] [bp-4Ch]@2
  int v19; // [sp+28h] [bp-48h]@2
  int v20; // [sp+2Ch] [bp-44h]@2
  float v21; // [sp+30h] [bp-40h]@2
  float v22; // [sp+78h] [bp+8h]@2

  v5 = _this;
  memset(&Dst, 0, 0x68u);
  v6 = a2;
  v4 = *(_DWORD *)(a2 + 84);
  if ( v4 )
  {
    v7 = (int)((char *)v5 + 16 * (v4 & 0x1F));
    v22 = ((double)*(signed int *)(a2 + 4) - *(float *)(v7 + 4)) * 0.5 + *(float *)(v7 + 4);
    v8 = ((double)*(signed int *)(v6 + 8) - *(float *)(v7 + 8)) * 0.5 + *(float *)(v7 + 8);
    v9 = ((double)*(signed int *)(v6 + 12) - *(float *)(v7 + 12)) * 0.5 + *(float *)(v7 + 12);
    Dst = 1036;
    v18 = a3;
    v12 = v22 + 4.0;
    v13 = v8;
    v14 = v9;
    v15 = 0.0;
    v16 = 0.0;
    v17 = 0.0;
    v19 = (rand() & 0x40) + 96;
    v20 = a4;
    v21 = 1.0;
    class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
    v12 = v22 - 4.0;
    class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
    v12 = (double)*(signed int *)(v6 + 4) + 4.0;
    v13 = (double)*(signed int *)(v6 + 8);
    v14 = (double)*(signed int *)(v6 + 12);
    class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
    v12 = (double)*(signed int *)(v6 + 4) - 4.0;
    class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
    *((float *)v5 + 4 * (*(_DWORD *)(v6 + 84) & 0x1F) + 1) = (double)*(signed int *)(v6 + 4);
    *((float *)v5 + 4 * (*(_DWORD *)(v6 + 84) & 0x1F) + 2) = (double)*(signed int *)(v6 + 8);
    *((float *)v5 + 4 * (*(_DWORD *)(v6 + 84) & 0x1F) + 3) = (double)*(signed int *)(v6 + 12);
  }
  else
  {
    compile_error;//*(_DWORD *)(a2 + 84) = *(_DWORD *)v5++;
    *((float *)v5 + 4 * (*(_DWORD *)(a2 + 84) & 0x1F) + 1) = (double)*(signed int *)(a2 + 4);
    *((float *)v5 + 4 * (*(_DWORD *)(a2 + 84) & 0x1F) + 2) = (double)*(signed int *)(a2 + 8);
    *((float *)v5 + 4 * (*(_DWORD *)(a2 + 84) & 0x1F) + 3) = (double)*(signed int *)(a2 + 12);
    v10 = (double)*(signed int *)(a2 + 4);
    Dst = 1036;
    v18 = a3;
    v12 = v10 + 4.0;
    v13 = (double)*(signed int *)(a2 + 8);
    v14 = (double)*(signed int *)(a2 + 12);
    v15 = 0.0;
    v16 = 0.0;
    v17 = 0.0;
    v21 = 1.0;
    v19 = (rand() & 0x7F) + 128;
    v20 = a4;
    class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
    v12 = (double)*(signed int *)(a2 + 4) - 4.0;
    class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
  }
}

//----- (004A75CC) --------------------------------------------------------
void __stdcall sub_4A75CC(int a1, int a2, int a3)
{
  signed int v3; // edi@1
  double v4; // st7@1
  int Dst; // [sp+8h] [bp-68h]@1
  float v6; // [sp+Ch] [bp-64h]@1
  float v7; // [sp+10h] [bp-60h]@1
  float v8; // [sp+14h] [bp-5Ch]@1
  float v9; // [sp+18h] [bp-58h]@2
  float v10; // [sp+1Ch] [bp-54h]@2
  float v11; // [sp+20h] [bp-50h]@2
  int v12; // [sp+24h] [bp-4Ch]@1
  int v13; // [sp+28h] [bp-48h]@1
  int v14; // [sp+2Ch] [bp-44h]@1
  float v15; // [sp+30h] [bp-40h]@1

  memset(&Dst, 0, 0x68u);
  Dst = 1029;
  v6 = (double)*(signed int *)(a1 + 4);
  v7 = (double)*(signed int *)(a1 + 8);
  v4 = (double)*(signed int *)(a1 + 12);
  v12 = a2;
  v8 = v4;
  v3 = 10;
  v13 = (rand() & 0x7F) + 128;
  v14 = a3;
  v15 = 1.0;
  do
  {
    v9 = (double)(rand() & 0x1FF) - 255.0;
    v10 = (double)(rand() & 0x1FF) - 255.0;
    v11 = (double)(rand() & 0x1FF) - 255.0;
    class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
    --v3;
  }
  while ( v3 );
}

//----- (004A7688) --------------------------------------------------------
void __thiscall sub_4A7688(void *_this, int a2)
{
  int v2; // esi@1
  double v3; // st7@1
  double v4; // st7@2
  double v5; // st7@4
  int v7; // eax@6
  float v8; // ST0C_4@6
  float v9; // ST08_4@6
  float v10; // ST04_4@6
  float v11; // ST00_4@6
  int Dst; // [sp+1Ch] [bp-7Ch]@1
  float v13; // [sp+20h] [bp-78h]@4
  float v14; // [sp+24h] [bp-74h]@4
  float v15; // [sp+28h] [bp-70h]@4
  float v16; // [sp+2Ch] [bp-6Ch]@5
  float v17; // [sp+30h] [bp-68h]@5
  float v18; // [sp+34h] [bp-64h]@5
  int v19; // [sp+38h] [bp-60h]@4
  int v20; // [sp+3Ch] [bp-5Ch]@4
  int v21; // [sp+40h] [bp-58h]@4
  float v22; // [sp+44h] [bp-54h]@4
  void *v23; // [sp+84h] [bp-14h]@1
  float v24; // [sp+88h] [bp-10h]@1
  double v25; // [sp+8Ch] [bp-Ch]@5
  float v26; // [sp+94h] [bp-4h]@4
  signed int v27; // [sp+A0h] [bp+8h]@4
  signed int v28; // [sp+A0h] [bp+8h]@6

  v23 = _this;
  memset(&Dst, 0, 0x68u);
  v2 = a2;
  v3 = (double)*(_WORD *)(a2 + 30) / (double)*(_WORD *)(56 * *(_WORD *)(a2 + 2) + pObjectDescriptionList->pDescriptions + 42);
  v24 = 512.0 * v3;
  if ( v3 >= 0.75 )
    v4 = (memory_4D8410.d1_0 - v3) * 4.0;
  else
    v4 = v3 * 1.3333333333333333;
  v26 = v4;
  v5 = (double)*(signed int *)(a2 + 4);
  Dst = 1029;
  v19 = 16727070;
  v13 = v5;
  v14 = (double)*(signed int *)(a2 + 8);
  v15 = (double)*(signed int *)(a2 + 12);
  v20 = (rand() & 0x7F) + 128;
  v21 = LODFile_Bitmaps_LOD.LODFile_LoadTexture( "effpar01", 2);
  v27 = 10;
  v22 = 1.0;
  do
  {
    HIDWORD(v25) = rand() & 0x1FF;
    v16 = (double)SHIDWORD(v25) - 255.0;
    HIDWORD(v25) = rand() & 0x1FF;
    v17 = (double)SHIDWORD(v25) - 255.0;
    WORD2(v25) = rand() & 0x1FF;
    HIDWORD(v25) = WORD2(v25);
    v18 = (double)WORD2(v25) - 255.0;
    class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
  }
  while ( v27-- != 1 );
  v25 = v24 + 6.755399441055744e15;
  v28 = LODWORD(v25);
  v7 = sub_4A7063((void *)0xFF3C1E, v26);
  v8 = (double)v28;
  v9 = (double)*(signed int *)(v2 + 12);
  v10 = (double)*(signed int *)(v2 + 8);
  v11 = (double)*(signed int *)(v2 + 4);
  sub_47829F(*((void **)v23 + 371), v11, v10, v9, v8, v7);
}

//----- (004A77FD) --------------------------------------------------------
void __thiscall sub_4A77FD(void *_this, int a2)
{
  void *v2; // edi@1
  int v3; // esi@1
  double v4; // st7@1
  double v5; // st7@2
  double v6; // ST1C_8@4
  int v7; // eax@4
  float v8; // ST0C_4@4
  float v9; // ST08_4@4
  float v10; // ST04_4@4
  float v11; // ST00_4@4
  float v12; // [sp+28h] [bp-4h]@1
  float v13; // [sp+34h] [bp+8h]@4

  v3 = a2;
  v2 = _this;
  v4 = (double)*(_WORD *)(a2 + 30) / (double)*(_WORD *)(56 * *(_WORD *)(a2 + 2) + pObjectDescriptionList->pDescriptions + 42);
  v12 = 512.0 - v4 * 512.0;
  if ( v4 >= 0.75 )
    v5 = v4 * 4.0;
  else
    v5 = v4 * 1.3333333333333333;
  v13 = v5;
  v6 = v12 + 6.755399441055744e15;
  v7 = sub_4A7063((void *)0x7E7E7E, v13);
  v8 = (double)SLODWORD(v6);
  v9 = (double)*(signed int *)(v3 + 12);
  v10 = (double)*(signed int *)(v3 + 8);
  v11 = (double)*(signed int *)(v3 + 4);
  sub_47829F(*((void **)v2 + 371), v11, v10, v9, v8, v7);
}

//----- (004A78AE) --------------------------------------------------------
void __stdcall sub_4A78AE(int a1)
{
  int v1; // esi@1
  signed int v2; // eax@1
  double v3; // st7@1
  int Dst; // [sp+8h] [bp-68h]@1
  float v5; // [sp+Ch] [bp-64h]@1
  float v6; // [sp+10h] [bp-60h]@1
  float v7; // [sp+14h] [bp-5Ch]@1
  float v8; // [sp+18h] [bp-58h]@1
  float v9; // [sp+1Ch] [bp-54h]@1
  float v10; // [sp+20h] [bp-50h]@1
  int v11; // [sp+24h] [bp-4Ch]@1
  int v12; // [sp+28h] [bp-48h]@1
  int v13; // [sp+2Ch] [bp-44h]@1
  int v14; // [sp+30h] [bp-40h]@1

  v1 = (int)&pObjectDescriptionList->pDescriptions[*(_WORD *)(a1 + 2)];
  memset(&Dst, 0, 0x68u);
  v2 = *(_WORD *)(a1 + 30);
  v5 = (double)*(signed int *)(a1 + 4);
  v3 = (double)*(signed int *)(a1 + 8);
  Dst = 2048;
  v11 = 0x7F7F7F;
  v12 = 1;
  v6 = v3;
  v7 = (double)*(signed int *)(a1 + 12);
  v8 = 0.0;
  v9 = 0.0;
  v10 = 0.0;
  v13 = *(_WORD *)(CSpriteFrameTable_fn1(pSpriteFrameTable, *(_WORD *)(v1 + 40), v2) + 24);
  v14 = 1073741824;
  class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
}

//----- (004A7948) --------------------------------------------------------
void __stdcall sub_4A7948(int a1)
{
  signed int v1; // edi@1
  int v2; // esi@1
  signed int v3; // eax@1
  double v4; // st7@1
  char v5; // al@1
  int Dst; // [sp+8h] [bp-68h]@1
  float v7; // [sp+Ch] [bp-64h]@1
  float v8; // [sp+10h] [bp-60h]@1
  float v9; // [sp+14h] [bp-5Ch]@1
  float v10; // [sp+18h] [bp-58h]@2
  float v11; // [sp+1Ch] [bp-54h]@2
  float v12; // [sp+20h] [bp-50h]@2
  int v13; // [sp+24h] [bp-4Ch]@1
  int v14; // [sp+28h] [bp-48h]@1
  int v15; // [sp+2Ch] [bp-44h]@1
  float v16; // [sp+30h] [bp-40h]@1

  v2 = (int)&pObjectDescriptionList->pDescriptions[*(_WORD *)(a1 + 2)];
  memset(&Dst, 0, 0x68u);
  v3 = *(_WORD *)(a1 + 30);
  v7 = (double)*(signed int *)(a1 + 4);
  v4 = (double)*(signed int *)(a1 + 8);
  Dst = 2053;
  v13 = 0x7F7F7F;
  v8 = v4;
  v9 = (double)*(signed int *)(a1 + 12);
  v15 = *(_WORD *)(CSpriteFrameTable_fn1(pSpriteFrameTable, *(_WORD *)(v2 + 40), v3) + 24);
  v5 = rand();
  v1 = 10;
  v16 = 1.0;
  v14 = (v5 & 0x7F) + 128;
  do
  {
    v10 = (double)(rand() & 0x1FF) - 255.0;
    v11 = (double)(rand() & 0x1FF) - 255.0;
    v12 = (double)(rand() & 0x1FF) - 255.0;
    class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
    --v1;
  }
  while ( v1 );
}

//----- (004A7A27) --------------------------------------------------------
char __stdcall sub_4A7A27(int a1, unsigned int a2, int a3)
{
  return sub_467D88(
           (int)&unk_519AB8,
           *(_DWORD *)(a1 + 4),
           *(_DWORD *)(a1 + 8),
           *(_DWORD *)(a1 + 12),
           *(_WORD *)(a1 + 28),
           a3,
           a2 >> 16,
           SBYTE1(a2),
           a2 != 0,
           (char *)byte_4E94D3);
}

//----- (004A7A66) --------------------------------------------------------
void __stdcall sub_4A7A66(int a1, int a2, int a3, float a4)
{
  int v4; // eax@1
  char v5; // al@1
  double v6; // st6@1
  double v7; // st6@1
  double v8; // st7@1
  double v9; // st6@1
  int Dst; // [sp+0h] [bp-6Ch]@1
  float v11; // [sp+4h] [bp-68h]@1
  float v12; // [sp+8h] [bp-64h]@1
  float v13; // [sp+Ch] [bp-60h]@1
  float v14; // [sp+10h] [bp-5Ch]@1
  float v15; // [sp+14h] [bp-58h]@1
  float v16; // [sp+18h] [bp-54h]@1
  int v17; // [sp+1Ch] [bp-50h]@1
  int v18; // [sp+20h] [bp-4Ch]@1
  int v19; // [sp+24h] [bp-48h]@1
  float v20; // [sp+28h] [bp-44h]@1
  float v21; // [sp+68h] [bp-4h]@1
  float v22; // [sp+74h] [bp+8h]@1
  float v23; // [sp+78h] [bp+Ch]@1
  float v24; // [sp+7Ch] [bp+10h]@1

  memset(&Dst, 0, 0x68u);
  Dst = 1029;
  v11 = (double)*(signed int *)(a1 + 4);
  v4 = *(_DWORD *)(a1 + 12);
  v12 = (double)*(signed int *)(a1 + 8);
  v17 = a2;
  v13 = (double)(v4 + 32);
  v5 = rand();
  v20 = 1.0;
  v6 = 0.0 * a4;
  v18 = (v5 & 0x7F) + 128;
  v19 = a3;
  v22 = v6;
  v14 = v6;
  v15 = a4;
  v16 = a4;
  class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
  v7 = 0.7071067690849304 * a4;
  v23 = v7;
  v14 = v7;
  v15 = v7;
  v16 = a4;
  class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
  v15 = v22;
  v14 = a4;
  v16 = a4;
  class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
  v14 = v23;
  v16 = a4;
  v8 = -v23;
  v24 = v8;
  v15 = v8;
  class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
  v9 = -1.0 * a4;
  v14 = v22;
  v21 = v9;
  v15 = v9;
  v16 = a4;
  class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
  v16 = a4;
  v14 = v24;
  v15 = v24;
  class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
  v14 = v21;
  v15 = v22;
  v16 = a4;
  class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
  v14 = v24;
  v15 = v23;
  v16 = a4;
  class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
}

//----- (004A7C07) --------------------------------------------------------
void __thiscall sub_4A7C07(void *_this, int a2)
{
  int v2; // eax@1
  int v3; // ebx@1
  void *v4; // edi@1
  int v5; // esi@1
  int v6; // eax@2
  double v7; // st6@2
  double v8; // st5@2
  double v9; // st4@2
  char v10; // al@2
  double v11; // st7@2
  double v12; // st7@3
  int Dst; // [sp+Ch] [bp-68h]@1
  float v14; // [sp+10h] [bp-64h]@2
  float v15; // [sp+14h] [bp-60h]@2
  float v16; // [sp+18h] [bp-5Ch]@2
  float v17; // [sp+1Ch] [bp-58h]@2
  float v18; // [sp+20h] [bp-54h]@2
  float v19; // [sp+24h] [bp-50h]@2
  int v20; // [sp+28h] [bp-4Ch]@2
  int v21; // [sp+2Ch] [bp-48h]@2
  int v22; // [sp+30h] [bp-44h]@2
  int v23; // [sp+34h] [bp-40h]@2
  int v24; // [sp+7Ch] [bp+8h]@2

  v4 = _this;
  memset(&Dst, 0, 0x68u);
  v5 = a2;
  v2 = *(_DWORD *)(a2 + 84);
  v3 = (int)&pObjectDescriptionList->pDescriptions[*(_WORD *)(a2 + 2)];
  if ( v2 )
  {
    v6 = (int)((char *)v4 + 16 * (v2 & 0x1F));
    v7 = ((double)*(signed int *)(a2 + 4) - *(float *)(v6 + 4)) * 0.5 + *(float *)(v6 + 4);
    v8 = ((double)*(signed int *)(a2 + 8) - *(float *)(v6 + 8)) * 0.5 + *(float *)(v6 + 8);
    v9 = ((double)*(signed int *)(a2 + 12) - *(float *)(v6 + 12)) * 0.5 + *(float *)(v6 + 12);
    Dst = 2048;
    v20 = 16777215;
    *(float *)&v24 = v9;
    v14 = v7;
    LODWORD(v16) = v24;
    v15 = v8;
    v17 = 0.0;
    v18 = 0.0;
    v19 = 0.0;
    v10 = rand();
    v23 = 1077936128;
    v21 = (v10 & 0x3F) + 64;
    v22 = *(_WORD *)(CSpriteFrameTable_fn1(pSpriteFrameTable, *(_WORD *)(v3 + 40), *(_WORD *)(v5 + 30)) + 24);
    class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
    v11 = (double)*(signed int *)(v5 + 4);
    v23 = 1082130432;
    v14 = v11;
    v15 = (double)*(signed int *)(v5 + 8);
    v16 = (double)*(signed int *)(v5 + 12);
    v21 = (rand() & 0x3F) + 64;
    class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
    *((float *)v4 + 4 * (*(_DWORD *)(v5 + 84) & 0x1F) + 1) = (double)*(signed int *)(v5 + 4);
    *((float *)v4 + 4 * (*(_DWORD *)(v5 + 84) & 0x1F) + 2) = (double)*(signed int *)(v5 + 8);
    *((float *)v4 + 4 * (*(_DWORD *)(v5 + 84) & 0x1F) + 3) = (double)*(signed int *)(v5 + 12);
  }
  else
  {
    compile_error;//*(_DWORD *)(a2 + 84) = *(_DWORD *)v4++;
    *((float *)v4 + 4 * (*(_DWORD *)(a2 + 84) & 0x1F) + 1) = (double)*(signed int *)(a2 + 4);
    *((float *)v4 + 4 * (*(_DWORD *)(a2 + 84) & 0x1F) + 2) = (double)*(signed int *)(a2 + 8);
    *((float *)v4 + 4 * (*(_DWORD *)(a2 + 84) & 0x1F) + 3) = (double)*(signed int *)(a2 + 12);
    v12 = (double)*(signed int *)(a2 + 4);
    Dst = 2048;
    v20 = 16777215;
    v23 = 1073741824;
    v14 = v12;
    v15 = (double)*(signed int *)(a2 + 8);
    v16 = (double)*(signed int *)(a2 + 12);
    v17 = 0.0;
    v18 = 0.0;
    v19 = 0.0;
    v21 = (rand() & 0x3F) + 64;
    v22 = *(_WORD *)(CSpriteFrameTable_fn1(pSpriteFrameTable, *(_WORD *)(v3 + 40), *(_WORD *)(a2 + 30)) + 24);
    class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
  }
}

//----- (004A7E05) --------------------------------------------------------
int __thiscall sub_4A7E05(void *_this, int a2, int a3, int a4)
{
  int v4; // edx@1
  int result; // eax@2
  float v6; // ST14_4@2
  float v7; // ST10_4@2
  float v8; // ST0C_4@2

  v4 = *(_DWORD *)(a2 + 84);
  if ( v4 )
  {
    v6 = (double)*(signed int *)(a2 + 12);
    v7 = (double)*(signed int *)(a2 + 8);
    v8 = (double)*(signed int *)(a2 + 4);
    result = sub_4A71FE(
               (int)_this,
               *((float *)_this + 4 * (v4 & 0x1F) + 1),
               *((float *)_this + 4 * (v4 & 0x1F) + 2),
               *((float *)_this + 4 * (v4 & 0x1F) + 3),
               v8,
               v7,
               v6,
               a4);
  }
  else
  {
    compile_error;//*(_DWORD *)(a2 + 84) = *(_DWORD *)_this++;
    *((float *)_this + 4 * (*(_DWORD *)(a2 + 84) & 0x1F) + 1) = (double)*(signed int *)(a2 + 4);
    *((float *)_this + 4 * (*(_DWORD *)(a2 + 84) & 0x1F) + 2) = (double)*(signed int *)(a2 + 8);
    result = 16 * (*(_DWORD *)(a2 + 84) & 0x1F);
    compile_error;//*(float *)(_this + result + 12) = (double)*(signed int *)(a2 + 12);
  }
  return result;
}

//----- (004A7E89) --------------------------------------------------------
void __stdcall sub_4A7E89(int a1, int a2)
{
  int v2; // edi@1
  int v3; // ebx@3
  int Dst; // [sp+Ch] [bp-6Ch]@1
  float v6; // [sp+10h] [bp-68h]@2
  float v7; // [sp+14h] [bp-64h]@2
  float v8; // [sp+18h] [bp-60h]@2
  int v9; // [sp+28h] [bp-50h]@3
  int v10; // [sp+2Ch] [bp-4Ch]@1
  int v11; // [sp+30h] [bp-48h]@1
  float v12; // [sp+34h] [bp-44h]@1
  int v13; // [sp+74h] [bp-4h]@2
  signed int v14; // [sp+80h] [bp+8h]@1

  memset(&Dst, 0, 0x68u);
  Dst = 1036;
  v10 = (rand() & 0x7F) + 128;
  v2 = a1;
  v11 = LODFile_Bitmaps_LOD.LODFile_LoadTexture( "effpar02", 2);
  v14 = 50;
  v12 = 1.0;
  do
  {
    v13 = (unsigned __int8)rand() + *(_WORD *)(v2 + 142) - 127;
    v6 = (double)v13;
    v13 = (unsigned __int8)rand() + *(_WORD *)(v2 + 144) - 127;
    v7 = (double)v13;
    v13 = *(_WORD *)(v2 + 146) + (unsigned __int8)rand();
    v8 = (double)v13;
    if ( a2 )
    {
      v9 = a2;
    }
    else
    {
      v3 = rand() << 16;
      v9 = rand() | v3;
    }
    class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
  }
  while ( v14-- != 1 );
}

//----- (004A7F74) --------------------------------------------------------
void __thiscall sub_4A7F74(void *_this, signed int a2, signed int a3, signed int a4)
{
  signed int v4; // edi@1
  void *v5; // esi@1
  char v6; // al@1
  int v7; // eax@1
  double v8; // st7@2
  double v9; // st7@2
  int Dst; // [sp+8h] [bp-78h]@1
  float v11; // [sp+Ch] [bp-74h]@2
  float v12; // [sp+10h] [bp-70h]@2
  float v13; // [sp+14h] [bp-6Ch]@2
  float v14; // [sp+18h] [bp-68h]@2
  float v15; // [sp+1Ch] [bp-64h]@2
  float v16; // [sp+20h] [bp-60h]@2
  int v17; // [sp+24h] [bp-5Ch]@1
  int v18; // [sp+28h] [bp-58h]@1
  int v19; // [sp+2Ch] [bp-54h]@1
  float v20; // [sp+30h] [bp-50h]@1
  double v21; // [sp+70h] [bp-10h]@1
  double v22; // [sp+78h] [bp-8h]@1
  float v23; // [sp+88h] [bp+8h]@1

  v5 = _this;
  memset(&Dst, 0, 0x68u);
  Dst = 1029;
  v17 = 0x7E7E7E;
  v6 = rand();
  v20 = 1.0;
  v4 = 8;
  v18 = (v6 & 0x7F) + 128;
  v7 = *((_DWORD *)v5 + 377);
  v22 = (double)a2;
  v19 = v7;
  v21 = (double)a3;
  v23 = (double)a4;
  do
  {
    v8 = sub_4BE5B1((int)&unk_F8BAD8);
    v11 = v8 * 40.0 - 20.0 + v22;
    v9 = sub_4BE5B1((int)&unk_F8BAD8);
    v13 = v23;
    v12 = v9 * 40.0 - 20.0 + v21;
    v14 = sub_4BE5B1((int)&unk_F8BAD8) * 400.0 - 200.0;
    v15 = sub_4BE5B1((int)&unk_F8BAD8) * 400.0 - 200.0;
    v16 = sub_4BE5B1((int)&unk_F8BAD8) * 150.0 + 50.0;
    class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
    --v4;
  }
  while ( v4 );
}

//----- (004A806F) --------------------------------------------------------
int __stdcall sub_4A806F(int a1)
{
  int v1; // eax@1
  double v2; // st7@2
  float v4; // ST00_4@6

  v1 = *(_DWORD *)(a1 + 372) - cClock2.dword_000024;
  if ( v1 <= 64 )
  {
    if ( v1 < 0 )
    {
      *(_DWORD *)(a1 + 372) = 0;
      *(_DWORD *)(a1 + 376) = 0;
      v2 = 1.0;
    }
    else
    {
      v2 = 1.0 - (double)(v1 * v1) * 0.000195312502910383;
    }
  }
  else
  {
    v2 = (double)((v1 - 64) * (v1 - 64)) * 0.000195312502910383 + 0.2000000029802322;
  }
  v4 = v2;
  return sub_48B561(v4);
}

//----- (004A80DC) --------------------------------------------------------
void __thiscall sub_4A80DC(void *_this, int a2)
{
  signed int v2; // ebx@1
  void *v3; // esi@1
  int Dst; // [sp+Ch] [bp-68h]@1
  float v5; // [sp+10h] [bp-64h]@2
  float v6; // [sp+14h] [bp-60h]@2
  float v7; // [sp+18h] [bp-5Ch]@2
  float v8; // [sp+1Ch] [bp-58h]@2
  float v9; // [sp+20h] [bp-54h]@2
  float v10; // [sp+24h] [bp-50h]@2
  int v11; // [sp+28h] [bp-4Ch]@1
  int v12; // [sp+2Ch] [bp-48h]@1
  int v13; // [sp+30h] [bp-44h]@1
  float v14; // [sp+34h] [bp-40h]@1

  v3 = _this;
  memset(&Dst, 0, 0x68u);
  Dst = 1029;
  v11 = 0x7E7E7E;
  v12 = (rand() & 0x7F) + 128;
  v13 = *((_DWORD *)v3 + 377);
  v2 = 8;
  v14 = 1.0;
  do
  {
    v5 = sub_4BE5B1((int)&unk_F8BAD8) * 40.0
       + (double)*(signed int *)(a2 + 4)
       - 20.0;
    v6 = sub_4BE5B1((int)&unk_F8BAD8) * 40.0
       + (double)*(signed int *)(a2 + 8)
       - 20.0;
    v7 = (double)*(signed int *)(a2 + 12);
    v8 = sub_4BE5B1((int)&unk_F8BAD8) * 800.0 - 400.0;
    v9 = sub_4BE5B1((int)&unk_F8BAD8) * 800.0 - 400.0;
    v10 = sub_4BE5B1((int)&unk_F8BAD8) * 350.0 + 50.0;
    class02_sub_48AB23((int)pGame->class02_obj, (int)&Dst);
    --v2;
  }
  while ( v2 );
}

//----- (004A89BD) --------------------------------------------------------
int __thiscall sub_4A89BD(void *_this, __int16 a2, __int16 a3)
{
  int result; // eax@1
  void *v4; // edi@1
  int v5; // esi@1
  const char *v6; // [sp-4h] [bp-10h]@2

  v4 = _this;
  v5 = (int)((char *)_this + 16 * a3);
  *(_DWORD *)(v5 + 524) = 0;
  *(_WORD *)(v5 + 520) = a2;
  result = a2 - 3;
  switch ( a2 )
  {
    case 153:
      v6 = "zapp";
      goto LABEL_24;
    case 13:
    case 45:
    case 47:
    case 150:
      v6 = "spboost1";
      goto LABEL_24;
    case 19:
    case 27:
    case 50:
    case 151:
      v6 = "spboost2";
      goto LABEL_24;
    case 83:
    case 85:
    case 86:
    case 88:
    case 152:
      v6 = "spboost3";
      goto LABEL_24;
    case 49:
    case 56:
    case 67:
      v6 = "spheal1";
      goto LABEL_24;
    case 54:
    case 61:
    case 64:
    case 68:
    case 72:
    case 74:
    case 96:
      v6 = "spheal2";
      goto LABEL_24;
    case 77:
    case 99:
      v6 = "spheal3";
      goto LABEL_24;
    case 3:
    case 8:
      v6 = "spell03";
      goto LABEL_24;
    case 5:
      v6 = "spell05";
      goto LABEL_24;
    case 14:
      v6 = "spell14";
      goto LABEL_24;
    case 17:
      v6 = "spell17";
      goto LABEL_24;
    case 25:
      v6 = "spell25";
      goto LABEL_24;
    case 36:
      v6 = "spell36";
      goto LABEL_24;
    case 38:
      v6 = "spell38";
      goto LABEL_24;
    case 46:
      v6 = "spell46";
      goto LABEL_24;
    case 51:
      v6 = "spell51";
      goto LABEL_24;
    case 55:
      v6 = "spell55";
      goto LABEL_24;
    case 58:
      v6 = "spell58";
      goto LABEL_24;
    case 69:
      v6 = "spell69";
      goto LABEL_24;
    case 71:
      v6 = "spell71";
      goto LABEL_24;
    case 73:
      v6 = "spell73";
      goto LABEL_24;
    case 75:
      v6 = "spell75";
LABEL_24:
      //result = CIconFrameTable_FindIcon(pIconFrameTable, v6);
      result = pIconFrameTable->FindAnimation(v6);
      *(_DWORD *)(v5 + 532) = result;
      break;
    default:
      *(_WORD *)(v5 + 520) = 0;
      break;
  }
  if ( *(_WORD *)(v5 + 520) )
  {
   //result = 8 * pIconFrameTable->pIcons[*(_DWORD *)(v5 + 532)].word_00001A;
   result = 8 * pIconFrameTable->GetImage(*(_DWORD *)(v5 + 532))->word_00001A;
    *((_DWORD *)v4 + 4 * (a3 + 33)) = result;
  }
  return result;
}

//----- (004A8BDF) --------------------------------------------------------
int __thiscall sub_4A8BDF(int _this, int a2, int a3)
{
  int result; // eax@1

  *(_DWORD *)(_this + 1496) = a3;
  *(_DWORD *)(_this + 1500) = a3;
  result = a2;
  *(_DWORD *)(_this + 1504) = a2;
  return result;
}

//----- (004A8BFC) --------------------------------------------------------
int __thiscall sub_4A8BFC(void *_this)
{
  int result; // eax@1
  void *v2; // esi@1

  v2 = _this;
  result = 8 * *(_WORD *)(60 * SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell84") + (unsigned int)(pSpriteFrameTable->pSpriteSFrames) + 56);

  *((_DWORD *)v2 + 373) = result;
  return result;
}

//----- (004A96BE) --------------------------------------------------------
void *__thiscall sub_4A96BE(void *_this)
{
  void *result; // eax@1
  int v2; // esi@1

  v2 = 0;
  result = &struct_F1B4D8[0].dword_00007C;
  while ( *(void **)result != _this )
  {
    result = (char *)result + 128;
    ++v2;
    if ( (signed int)result >= (signed int)&unk_F79154 )
      return result;
  }
  mem_mng.DeleteBuffer( (void *)(int)_this);
  return memset(&struct_F1B4D8[v2], 0, sizeof(struct unnamed_F1B4D8));
}

//----- (004A96FF) --------------------------------------------------------
int __fastcall sub_4A96FF(int a1, int a2, const char *Str1)
{
  int v3; // ebx@1
  int v4; // esi@1
  int result; // eax@2
  signed int v6; // ebx@11
  int v7; // eax@11
  char v8; // zf@11
  int v9; // edi@13
  int v10; // esi@14
  int v11; // esi@20
  int v12; // [sp+Ch] [bp-4h]@1

  v3 = a2;
  v12 = a2;
  v4 = a1;
  while ( 1 )
  {
    v6 = v3 - v4;
    v7 = 52 * (v6 / 2 + v4);
    v8 = pAudioPlayer->pSoundHeaders + v7 == 0;
    result = (int)pAudioPlayer->pSoundHeaders + v7;
    if ( v8 )
      return result;
    result = _strcmpi(Str1, (const char *)result);
    if ( !result )
      dword_F1B4C8 = v6 / 2 + v4;
    if ( v4 == v12 )
      goto LABEL_17;
    if ( result < 0 )
      break;
    if ( v6 <= 4 )
    {
      v9 = v4;
      if ( v4 < v12 )
      {
        v11 = 52 * v4;
        do
        {
          result = _strcmpi(Str1, (const char *)(v11 + pAudioPlayer->pSoundHeaders));
          if ( !result )
            goto LABEL_24;
          ++v9;
          v11 += 52;
        }
        while ( v9 < v12 );
      }
LABEL_17:
      dword_F1B4C8 = -1;
      return result;
    }
    v4 += v6 / 2;
LABEL_10:
    v3 = v12;
  }
  if ( v6 > 4 )
  {
    v12 = v6 / 2 + v4;
    goto LABEL_10;
  }
  v9 = v4;
  if ( v4 >= v12 )
    goto LABEL_17;
  v10 = 52 * v4;
  while ( 1 )
  {
    result = _strcmpi(Str1, (const char *)(v10 + pAudioPlayer->pSoundHeaders));
    if ( !result )
      break;
    ++v9;
    v10 += 52;
    if ( v9 >= v12 )
      goto LABEL_17;
  }
LABEL_24:
  dword_F1B4C8 = v9;
  return result;
}

//----- (004A9BBD) --------------------------------------------------------
int __thiscall sub_4A9BBD(void *_this, signed int a2, LPVOID lpBuffer, signed int a4, int a5, int a6)
{
  void *v6; // edi@1
  int v7; // esi@1
  unsigned __int8 v8; // zf@1
  unsigned __int8 v9; // sf@1
  int v10; // eax@3
  DWORD v11; // ecx@3
  int v12; // ebx@7
  int result; // eax@13
  signed int v14; // ebx@16
  DWORD *v15; // edi@16
  int v16; // esi@16
  signed int v17; // eax@18
  void *v18; // ebx@19
  int v19; // eax@19
  char v20; // [sp-18h] [bp-38h]@22
  int v21; // [sp-14h] [bp-34h]@22
  int v22; // [sp-10h] [bp-30h]@22
  int v23; // [sp-Ch] [bp-2Ch]@22
  const char *v24; // [sp-8h] [bp-28h]@22
  int v25; // [sp-4h] [bp-24h]@22
  void *v26; // [sp+Ch] [bp-14h]@1
  DWORD Args; // [sp+10h] [bp-10h]@3
  int v28; // [sp+14h] [bp-Ch]@2
  int v29; // [sp+18h] [bp-8h]@2
  int v30; // [sp+1Ch] [bp-4h]@1

  v6 = _this;
  v7 = 0;
  v26 = _this;
  v8 = *(_DWORD *)_this == 0;
  v9 = *(_DWORD *)_this < 0;
  v30 = 0;
  if ( v9 | v8 )
  {
LABEL_13:
    result = 0;
  }
  else
  {
    v28 = 0;
    v29 = 44;
    while ( 1 )
    {
      v10 = *((_DWORD *)v6 + 1);
      v11 = v10 + v28;
      Args = v10 + v28;
      if ( a2 == *(_DWORD *)(v10 + v28 + 32) )
      {
        if ( a6 == v7 && *(_DWORD *)(v29 + v10) != v7 )
          return v30;
        if ( pAudioPlayer->uNumSounds > v7 )
          break;
      }
LABEL_12:
      ++v30;
      v29 += 120;
      v28 += 120;
      if ( v30 >= *(_DWORD *)v6 )
        goto LABEL_13;
    }
    v12 = 0;
    while ( _strcmpi((const char *)(v12 + pAudioPlayer->pSoundHeaders), (const char *)v11) )
    {
      ++v7;
      v12 += 52;
      if ( v7 >= pAudioPlayer->uNumSounds )
      {
        v7 = 0;
        goto LABEL_12;
      }
      v11 = Args;
    }
    v16 = (int)&pAudioPlayer->pSoundHeaders[v7];
    v15 = (DWORD *)(v16 + 48);
    a2 = *(_DWORD *)(v16 + 48);
    v14 = a2;
    if ( a2 > a4 )
      erroneous_printf("Sound %s is size %i bytes, sound buffer size is %i bytes", Args, a2, a4);
    SetFilePointer(pAudioPlayer->hSoundsSource, *(_DWORD *)(v16 + 40), 0, 0);
    v17 = *(_DWORD *)(v16 + 44);
    if ( v17 >= (signed int)*v15 )
    {
      if ( v17 == *v15 )
      {
        ReadFile(pAudioPlayer->hSoundsSource, lpBuffer, *v15, &Args, 0);
      }
      else
      {
        v25 = 666;
        v24 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Sound.cpp";
        a4 = (signed int)&v20;
        Game_sub_40E2C8(&v20, "Can't load sound file!", (int)((char *)&a4 + 3));
        sub_466D09(&a2, *(int *)&v20, v21, v22, v23, v24, v25);
      }
    }
    else
    {
      v18 = malloc(*(_DWORD *)(v16 + 44));
      ReadFile(pAudioPlayer->hSoundsSource, v18, *(_DWORD *)(v16 + 44), &Args, 0);
      MemUnzip(lpBuffer, (unsigned int *)(v16 + 48), v18, *(_DWORD *)(v16 + 44));
      free(v18);
      v14 = a2;
    }
    result = v30;
    *(_DWORD *)(*((_DWORD *)v26 + 1) + 4 * (a6 + 30 * v30) + 44) = (int)lpBuffer;
    *(_DWORD *)a5 = v14;
  }
  return result;
}

//----- (004A9D3E) --------------------------------------------------------
int __thiscall sub_4A9D3E(void *_this)
{
  int v1; // ebx@1
  void *v2; // esi@1
  int v3; // edi@2
  int result; // eax@3
  void *v5; // ecx@3

  v2 = _this;
  v1 = 0;
  if ( *(_DWORD *)_this > 0 )
  {
    v3 = 0;
    do
    {
      result = *((_DWORD *)v2 + 1);
      v5 = *(void **)(v3 + result + 44);
      if ( v5 )
      {
        sub_4A96BE(v5);
        *(_DWORD *)(v3 + *((_DWORD *)v2 + 1) + 44) = 0;
        result = v3 + *((_DWORD *)v2 + 1) + 40;
        *(_DWORD *)result &= 0xFFFFFFFEu;
      }
      ++v1;
      v3 += 120;
    }
    while ( v1 < *(_DWORD *)v2 );
  }
  return result;
}

//----- (004A9DCD) --------------------------------------------------------
int __thiscall SoundList_sub_4A9DCD(int _this, int a2, char a3)
{
  int result; // eax@1
  int v4; // edi@1
  int v5; // esi@1
  void *v6; // ecx@8

  v5 = 120 * a2;
  v4 = _this;
  result = 120 * a2 + *(_DWORD *)(_this + 4);
  if ( *(_DWORD *)(result + 36) != 1 )
  {
    if ( *(_BYTE *)(result + 40) & 2 )
    {
      if ( *(_DWORD *)(result + 112) )
      {
        if ( a3 )
        {
          if ( *(_BYTE *)(result + 116) )
            AIL_mem_free_lock(*(_DWORD *)(result + 112));
          *(_DWORD *)(*(_DWORD *)(v4 + 4) + v5 + 112) = 0;
          *(_DWORD *)(*(_DWORD *)(v4 + 4) + v5 + 40) &= 0xFFFFFFFEu;
        }
      }
    }
    result = *(_DWORD *)(v4 + 4);
    v6 = *(void **)(result + v5 + 44);
    if ( v6 )
    {
      sub_4A96BE(v6);
      *(_DWORD *)(*(_DWORD *)(v4 + 4) + v5 + 44) = 0;
      result = *(_DWORD *)(v4 + 4) + v5 + 40;
      *(_DWORD *)result &= 0xFFFFFFFEu;
    }
  }
  return result;
}

//----- (004AA13F) --------------------------------------------------------
char __thiscall sub_4AA13F(int _this, int a2)
{
  int v2; // esi@1
  unsigned int v3; // eax@3
  int v4; // edi@5
  signed __int64 v5; // qax@6

  v2 = _this;
  if ( !(dword_6BE364 & 0x10) )
  {
    if ( pAudioPlayer->hAILRedbook )
    {
      LOBYTE(v3) = uMusicVolimeMultiplier;
      if ( uMusicVolimeMultiplier )
      {
        if ( *(_DWORD *)(_this + 668) )
        {
          v4 = *(_DWORD *)(_this + 676);
          if ( v4 )
          {
            v5 = (signed __int64)(aMusicVolumeLevels[uMusicVolimeMultiplier] * 64.0);
            //AIL_redbook_set_volume(_this, HIDWORD(v5), v4, v5);
            AIL_redbook_set_volume((HREDBOOK)_this, HIDWORD(v5));
          }
        }
        AIL_redbook_stop(pAudioPlayer->hAILRedbook);
        AIL_redbook_track_info(pAudioPlayer->hAILRedbook, a2, (unsigned int *)(v2 + 736), (unsigned int *)(v2 + 740));
        AIL_redbook_play(pAudioPlayer->hAILRedbook, *(_DWORD *)(v2 + 736) + 1, *(_DWORD *)(v2 + 740));
        v3 = ((*(_DWORD *)(v2 + 740) - *(_DWORD *)(v2 + 736)) << 7) / 0x3E8u;
        *(_DWORD *)(v2 + 728) = ((*(_DWORD *)(v2 + 740) - *(_DWORD *)(v2 + 736)) << 7) / 0x3E8u;
      }
    }
  }
  return v3;
}

//----- (004AA258) --------------------------------------------------------
void __thiscall AudioPlayer_sub_4AA258(int _this, int a2)
{
  int v2; // esi@1
  int v3; // edi@4
  int v4; // ebx@5
  int v5; // ebx@11
  int v6; // edi@12

  v2 = _this;
  if ( *(_DWORD *)(_this + 668) )
  {
    if ( *(_DWORD *)(_this + 4) && a2 && (v3 = 0, *(_DWORD *)(_this + 16) > 0) )
    {
      v4 = _this + 20;
      while ( *(_DWORD *)(v4 + 4) != a2 || AIL_3D_sample_status(*(_DWORD *)v4) != 4 )
      {
        ++v3;
        v4 += 16;
        if ( v3 >= *(_DWORD *)(v2 + 16) )
          goto LABEL_9;
      }
      AIL_end_3D_sample(*(_DWORD *)(16 * v3 + v2 + 20));
    }
    else
    {
LABEL_9:
      if ( *(_DWORD *)(v2 + 680) )
      {
        if ( a2 )
        {
          v5 = 0;
          if ( *(_DWORD *)(v2 + 1000) > 0 )
          {
            v6 = v2 + 744;
            do
            {
              if ( *(_DWORD *)(v6 + 4) == a2 )
              {
                if ( AIL_sample_status(*(_DWORD *)v6) == 4 )
                {
                  AIL_end_sample(*(_DWORD *)v6);
                  sub_4ABE55(v2, v6);
                }
              }
              ++v5;
              v6 += 16;
            }
            while ( v5 < *(_DWORD *)(v2 + 1000) );
          }
        }
      }
    }
  }
}

//----- (004AAEA6) --------------------------------------------------------
int __fastcall sub_4AAEA6(int a1)
{
  int result; // eax@1
  double v2; // st6@1
  double v3; // st7@1
  double v4; // st5@2
  double v5; // st3@3
  double v6; // st4@3
  double v7; // st7@6
  double v8; // st6@7
  float v9; // [sp+0h] [bp-10h]@1
  float v10; // [sp+4h] [bp-Ch]@1
  float v11; // [sp+8h] [bp-8h]@2
  float v12; // [sp+8h] [bp-8h]@6
  float v13; // [sp+Ch] [bp-4h]@2
  float v14; // [sp+Ch] [bp-4h]@6

  v3 = *(float *)&dword_51B718;
  v2 = *(float *)&dword_51B71C;
  v9 = flt_51B710;
  LODWORD(v10) = dword_51B714;
  result = 0;
  if ( dword_51B6F8 )
  {
    v13 = *(float *)a1 - (double)pParty_global->sPartyPosX;
    v11 = *(float *)(a1 + 4) - (double)pParty_global->sPartyPosY;
    v4 = *(float *)(a1 + 8) - (double)pParty_global->sPartyPosZ;
    if ( pD3DRenderer->pRenderD3D3 )
    {
      v6 = v11 * *(float *)&dword_51B714 + v13 * flt_51B710;
      v5 = v13 * *(float *)&dword_51B714 - v11 * flt_51B710;
    }
    else
    {
      v6 = v13 * flt_51B710 - v11 * *(float *)&dword_51B714;
      v5 = v13 * *(float *)&dword_51B714 + v11 * flt_51B710;
    }
    *(float *)(a1 + 12) = v6 * v3 - v4 * v2;
    *(float *)(a1 + 16) = v5;
    *(float *)(a1 + 20) = v6 * v2 + v4 * v3;
  }
  else
  {
    v14 = *(float *)a1 - (double)pParty_global->sPartyPosX;
    v12 = *(float *)(a1 + 4) - (double)pParty_global->sPartyPosY;
    v7 = *(float *)(a1 + 8) - (double)pParty_global->sPartyPosZ;
    if ( pD3DRenderer->pRenderD3D3 )
    {
      *(float *)(a1 + 12) = v12 * *(float *)&dword_51B714 + v14 * flt_51B710;
      v8 = v14 * v10 - v12 * v9;
    }
    else
    {
      *(float *)(a1 + 12) = v14 * flt_51B710 - v12 * *(float *)&dword_51B714;
      v8 = v14 * v10 + v12 * v9;
    }
    *(float *)(a1 + 16) = v8;
    *(float *)(a1 + 20) = v7;
  }
  return result;
}

//----- (004AB66C) --------------------------------------------------------
int __fastcall sub_4AB66C(int a1, int a2)
{
  int v2; // eax@1

  v2 = pClass59_global->uDoublePiMask & (class59_Atan2(pClass59_global, a1 - pParty_global->sPartyPosX, a2 - pParty_global->sPartyPosY) - pClass59_global->uIntegerHalfPi - pParty_global->sRotationY);
  if ( v2 > pClass59_global->uIntegerPi )
    v2 = 2 * pClass59_global->uIntegerPi - v2;
  return (v2 >> 3) - (v2 >> 10);
}

//----- (004AB6B1) --------------------------------------------------------
int __fastcall sub_4AB6B1(int a1, int a2, int a3)
{
  int v3; // esi@1
  int v4; // edi@1
  int v5; // ST08_4@1
  int v6; // esi@1
  int v7; // eax@1
  int result; // eax@2
  int v9; // [sp+10h] [bp+8h]@1

  v3 = a2;
  v4 = a1;
  v5 = abs(a3 - pParty_global->sPartyPosZ);
  v6 = abs(v3 - pParty_global->sPartyPosY);
  v7 = abs(v4 - pParty_global->sPartyPosX);
  v9 = sub_4621DA(v7, v6, v5);
  if ( v9 <= 8192 )
    result = 114 - (signed __int64)((double)v9 * (1.0 / 8192.0) * 100.0);
  else
    result = 0;
  return result;
}

//----- (004ABC9B) --------------------------------------------------------
LSTATUS __stdcall sub_4ABC9B(char a1)
{
  LSTATUS result; // eax@1
  DWORD cbData; // [sp+8h] [bp-Ch]@1
  BYTE Data[4]; // [sp+Ch] [bp-8h]@1
  HKEY hKey; // [sp+10h] [bp-4h]@1

  hKey = 0;
  cbData = 4;
  *(_DWORD *)Data = 0;
  result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Aureal\\A3D", 0, 0x2001Fu, &hKey);
  if ( !result )
  {
    if ( a1 )
      compile_error;//RegQueryValueExA(hKey, "SplashAudio", 0, 0, &::Data, &cbData);
    else
      compile_error;//*(_DWORD *)Data = *(_DWORD *)&::Data;
    RegSetValueExA(hKey, "SplashAudio", 0, 4u, Data, 4u);
    *(_DWORD *)Data = 0;
    if ( a1 )
      RegQueryValueExA(hKey, "SplashScreen", 0, 0, &dword_F1B4B0, &cbData);
    else
      *(_DWORD *)Data = *(_DWORD *)&dword_F1B4B0;
    RegSetValueExA(hKey, "SplashScreen", 0, 4u, Data, 4u);
    result = RegCloseKey(hKey);
  }
  return result;
}

//----- (004ABD5B) --------------------------------------------------------
void __thiscall AudioPlayer_sub_4ABD5B(int _this)
{
  int v1; // edi@1
  int v2; // esi@1
  int v3; // ebx@3
  int v4; // ebx@6
  int v5; // edi@7
  int v6; // edi@13
  int v7; // edx@14
  int v8; // ecx@14
  void *v9; // ecx@15

  v2 = _this;
  v1 = 0;
  if ( *(_DWORD *)(_this + 668) )
  {
    CloseHandle(pVideoPlayer->hMightVid);
    CloseHandle(pVideoPlayer->hMagicVid);
    AudioPlayer_sub_4AB71F((AudioPlayer *)v2, -1, -1);
    if ( *(_DWORD *)(v2 + 1000) > 0 )
    {
      v3 = v2 + 744;
      do
      {
        AIL_release_sample_handle(*(_DWORD *)v3);
        ++v1;
        v3 += 16;
      }
      while ( v1 < *(_DWORD *)(v2 + 1000) );
    }
    if ( ReadWindowsRegistry("Disable3DSound", 0) != 1 )
    {
      v4 = 0;
      sub_4ABC9B(0);
      if ( *(_DWORD *)(v2 + 16) > 0 )
      {
        v5 = v2 + 20;
        do
        {
          if ( *(_DWORD *)v5 )
          {
            AIL_release_3D_sample_handle(*(_DWORD *)v5);
            *(_DWORD *)v5 = 0;
          }
          ++v4;
          v5 += 16;
        }
        while ( v4 < *(_DWORD *)(v2 + 16) );
      }
      if ( *(_DWORD *)(v2 + 12) )
      {
        AIL_close_3D_provider(*(_DWORD *)(v2 + 12));
        *(_DWORD *)(v2 + 12) = 0;
      }
    }
    v6 = v2 + 676;
    if ( *(_DWORD *)(v2 + 676) )
    {
      AIL_redbook_stop(*(HREDBOOK *)(v2 + 676));
      //AIL_redbook_set_volume((HREDBOOK)v8, v7, *(_DWORD *)v6, *(_DWORD *)(v2 + 536));
      AIL_redbook_set_volume((HREDBOOK)v8, v7);
      AIL_redbook_close(*(_DWORD *)v6);
    }
    AIL_shutdown();
    sub_4A9D3E(pSoundList);
    v9 = *(void **)(v2 + 3192);
    if ( v9 )
      sub_4A96BE(v9);
    CloseHandle(*(HANDLE *)(v2 + 700));
  }
}

//----- (004ABE55) --------------------------------------------------------
int __thiscall sub_4ABE55(int _this, int a2)
{
  int result; // eax@1
  int v3; // ebx@1
  int v4; // esi@1
  unsigned __int8 v5; // zf@5
  unsigned __int8 v6; // sf@5
  int v7; // edi@6
  int v8; // eax@8
  int v9; // ST04_4@8
  int v10; // ecx@12
  int v11; // edi@13
  unsigned __int8 v12; // sf@13
  unsigned __int8 v13; // of@13
  int v14[16]; // [sp+Ch] [bp-48h]@8
  int v15; // [sp+4Ch] [bp-8h]@5
  int v16; // [sp+50h] [bp-4h]@5

  result = (int)pSoundList->pDescriptions;
  v3 = 0;
  v4 = _this;
  if ( pSoundList->pDescriptions )
  {
    result = 120 * *(_DWORD *)(a2 + 8) + (int)pSoundList->pDescriptions;
    if ( *(_DWORD *)(result + 36) == 2 )
    {
      if ( *(_DWORD *)(result + 44) )
      {
        if ( !(*(_BYTE *)(result + 40) & 1) )
        {
          v5 = *(_DWORD *)(_this + 1000) == 0;
          v6 = *(_DWORD *)(_this + 1000) < 0;
          v15 = 0;
          v16 = 0;
          if ( v6 | v5 )
            goto LABEL_16;
          v7 = _this + 744;
          do
          {
            result = *(_DWORD *)(a2 + 12);
            if ( result == *(_DWORD *)(v7 + 12) )
            {
              v8 = v16;
              v9 = *(_DWORD *)v7;
              ++v16;
              v14[v8] = v3;
              result = AIL_sample_status(v9);
              if ( result == 4 )
                ++v15;
            }
            ++v3;
            v7 += 16;
          }
          while ( v3 < *(_DWORD *)(v4 + 1000) );
          if ( !v15 )
          {
LABEL_16:
            result = SoundList_sub_4A9DCD((int)pSoundList, *(_DWORD *)(a2 + 8), 1);
            v10 = 0;
            if ( v16 > 0 )
            {
              do
              {
                v11 = 16 * v14[v10];
                result = 16 * (v14[v10++] + 47);
                *(_DWORD *)(v11 + v4 + 756) = 0;
                compile_error;//v13 = __SETO__(v10, v16);
                v12 = v10 - v16 < 0;
                *(_DWORD *)(result + v4) = 0;
              }
              while ( v12 ^ v13 );
            }
          }
        }
      }
    }
  }
  return result;
}

//----- (004ABF23) --------------------------------------------------------
int __thiscall sub_4ABF23(int _this, int a2)
{
  int result; // eax@1
  int v3; // ebx@1
  int v4; // esi@1
  unsigned __int8 v5; // zf@5
  unsigned __int8 v6; // sf@5
  int v7; // edi@6
  int v8; // eax@8
  int v9; // ST04_4@8
  int v10; // ecx@12
  int v11; // eax@13
  int v12; // edi@13
  unsigned __int8 v13; // sf@13
  unsigned __int8 v14; // of@13
  int v15[16]; // [sp+Ch] [bp-48h]@8
  int v16; // [sp+4Ch] [bp-8h]@5
  int v17; // [sp+50h] [bp-4h]@5

  result = (int)pSoundList->pDescriptions;
  v3 = 0;
  v4 = _this;
  if ( pSoundList->pDescriptions )
  {
    result = 120 * *(_DWORD *)(a2 + 8) + (int)pSoundList->pDescriptions;
    if ( *(_DWORD *)(result + 36) == 2 )
    {
      if ( *(_DWORD *)(result + 112) )
      {
        if ( !(*(_BYTE *)(result + 40) & 1) )
        {
          v5 = *(_DWORD *)(_this + 16) == 0;
          v6 = *(_DWORD *)(_this + 16) < 0;
          v16 = 0;
          v17 = 0;
          if ( v6 | v5 )
            goto LABEL_16;
          v7 = _this + 20;
          do
          {
            result = *(_DWORD *)(a2 + 12);
            if ( result == *(_DWORD *)(v7 + 12) )
            {
              v8 = v17;
              v9 = *(_DWORD *)v7;
              ++v17;
              v15[v8] = v3;
              result = AIL_3D_sample_status(v9);
              if ( result == 4 )
                ++v16;
            }
            ++v3;
            v7 += 16;
          }
          while ( v3 < *(_DWORD *)(v4 + 16) );
          if ( !v16 )
          {
LABEL_16:
            result = SoundList_sub_4A9DCD((int)pSoundList, *(_DWORD *)(a2 + 8), 1);
            v10 = 0;
            if ( v17 > 0 )
            {
              do
              {
                v11 = v15[v10];
                v12 = 16 * (v11 + 2);
                result = 16 * v11;
                ++v10;
                *(_DWORD *)(v12 + v4) = 0;
                compile_error;//v14 = __SETO__(v10, v17);
                v13 = v10 - v17 < 0;
                *(_DWORD *)(result + v4 + 28) = 0;
              }
              while ( v13 ^ v14 );
            }
          }
        }
      }
    }
  }
  return result;
}

//----- (004ABFDB) --------------------------------------------------------
char __cdecl LoadLevel_InitializeMusic()
{
  signed int v0; // eax@1

  v0 = CMapStats_FindLocation(pMapStats, CurrentLevelName);
  if ( v0 )
    LOBYTE(v0) = sub_4AA13F((int)pAudioPlayer, pMapStats->pMapInfos[v0].uRedbookTrackNum);
  return v0;
}

//----- (004AC004) --------------------------------------------------------
int __thiscall AudioPlayer_sub_4AC004(int _this)
{
  int v1; // edi@1
  int result; // eax@2
  int v3; // ST00_4@2
  int v4; // ST00_4@2
  float v5; // [sp+4h] [bp-4h]@2

  v1 = _this;
  if ( *(_DWORD *)_this )
  {
    v3 = *(_DWORD *)(_this + 12);
    v5 = 0.0;
    AIL_set_3D_provider_preference(v3, (int)"EAX effect volume", (int)&v5);
    v4 = *(_DWORD *)(v1 + 12);
    v5 = 1.0;
    result = AIL_set_3D_provider_preference(v4, (int)"EAX damping", (int)&v5);
  }
  return result;
}

//----- (004AC0A2) --------------------------------------------------------
signed int __thiscall sub_4AC0A2(void *_this)
{
  int v1; // ebx@1
  int v2; // esi@1
  signed int v3; // eax@1
  char v4; // zf@1
  int v5; // edi@2
  int v6; // eax@4
  int v8; // ebx@7
  int v9; // eax@8
  int v10; // ebx@14
  unsigned int v11; // eax@14
  int v12; // [sp+1Ch] [bp-8h]@1
  int v13; // [sp+20h] [bp-4h]@6

  v2 = (int)_this;
  v3 = CMapStats_FindLocation(pMapStats,CurrentLevelName);
  v4 = *(_DWORD *)(v2 + 4) == 0;
  v1 = v3;
  v12 = v3;
  if ( !v4 )
  {
    v5 = v2 + 16;
    AIL_3D_provider_attribute(*(_DWORD *)(v2 + 12), (int)"Maximum supported samples", v2 + 16);
    if ( *(_DWORD *)(v2 + 16) > 32 )
      *(_DWORD *)v5 = 32;
    v6 = *(_DWORD *)v5;
    if ( !*(_DWORD *)v5 )
    {
      *(_DWORD *)(v2 + 4) &= v6;
      return -1;
    }
    v13 = 0;
    if ( v6 > 0 )
    {
      v8 = v2 + 20;
      while ( 1 )
      {
        v9 = AIL_allocate_3D_sample_handle(*(_DWORD *)(v2 + 12));
        *(_DWORD *)v8 = v9;
        if ( !v9 )
          break;
        AIL_set_3D_sample_float_distances(v9, 4096.0, 256.0, 4096.0, 256.0);
        AIL_set_3D_sample_volume(*(_DWORD *)v8, *(_DWORD *)(v2 + 8));
        ++v13;
        v8 += 16;
        if ( v13 >= *(_DWORD *)v5 )
          goto LABEL_12;
      }
      *(_DWORD *)v5 = v13;
LABEL_12:
      v1 = v12;
    }
    if ( *(_DWORD *)v2 )
    {
      v10 = 68 * v1;
      v11 = pMapStats->pMapInfos[v1].uEAXEnv;
      v12 = pMapStats->pMapInfos[v1].uEAXEnv;
      if ( v11 >= 0x1A )
      {
        AudioPlayer_sub_4AC004(v2);
        *(_DWORD *)(v2 + 532) = -1;
      }
      else
      {
        AIL_set_3D_provider_preference(*(_DWORD *)(v2 + 12), (int)"EAX environment selection", (int)&v12);
        *(_DWORD *)(v2 + 532) = v12;
      }
    }
  }
  return 1;
}


//----- (004AC277) --------------------------------------------------------
int __thiscall sub_4AC277(void *_this, int a2)
{
  signed int v2; // esi@1
  signed __int16 v4; // bx@3
  unsigned int v11; // esi@8
  unsigned int v12; // ett@8
  unsigned int v13; // eax@10
  int result; // eax@13
  unsigned int Dst; // [sp+8h] [bp-30h]@1
  unsigned int v16; // [sp+Ch] [bp-2Ch]@12
  unsigned int v17; // [sp+10h] [bp-28h]@10
  unsigned int v18; // [sp+14h] [bp-24h]@12
  LARGE_INTEGER Frequency; // [sp+18h] [bp-20h]@1
  LARGE_INTEGER PerformanceCount; // [sp+20h] [bp-18h]@3
  LARGE_INTEGER v21; // [sp+28h] [bp-10h]@5
  unsigned int v22; // [sp+30h] [bp-8h]@1
  int v23; // [sp+34h] [bp-4h]@2

  v22 = (unsigned int)_this;
  v2 = -1;
  memset(&Dst, 0, 0x10u);
  if ( QueryPerformanceFrequency(&Frequency) )
  {
    v23 = 10;
    do
    {
      QueryPerformanceCounter(&PerformanceCount);
      compile_error;//_EAX = -2147483648;
      v4 = 4000;
      do
      {
        __asm { bsf     ecx, eax }
        --v4;
      }
      while ( v4 );
      QueryPerformanceCounter(&v21);
      if ( (_DWORD)v21.LowPart - (_DWORD)PerformanceCount.LowPart < (unsigned int)v2 )
        v2 = v21.LowPart - PerformanceCount.LowPart;
    }
    while ( v23-- != 1 );
    v12 = 100000 * v2;
    v11 = 100000 * v2 / (Frequency.LowPart / 0xA);
    if ( v12 / (Frequency.LowPart / 0xA) % Frequency.LowPart > (_DWORD)Frequency.LowPart >> 1 )
      ++v11;
    v13 = v22 / v11;
    v17 = v22 / v11;
    if ( v22 % v11 > v11 >> 1 )
      ++v13;
    Dst = v22;
    v16 = v11;
    v18 = v13;
  }
  result = a2;
  *(_DWORD *)a2 = Dst;
  *(_DWORD *)(a2 + 4) = v16;
  *(_DWORD *)(a2 + 8) = v17;
  *(_DWORD *)(a2 + 12) = v18;
  return result;
}

//----- (004AC33A) --------------------------------------------------------
int __stdcall sub_4AC33A(int a1)
{
  int v1; // ebx@1
  int v2; // esi@1
  unsigned __int64 v3; // qax@4
  DWORD v4; // eax@7
  DWORD v5; // edi@7
  unsigned __int64 v6; // qax@7
  unsigned int v7; // ecx@10
  unsigned int v8; // edi@10
  unsigned int v9; // edi@10
  unsigned int v10; // ett@10
  int v11; // eax@14
  unsigned int v12; // ecx@19
  int result; // eax@24
  unsigned int Dst[4]; // [sp+Ch] [bp-4Ch]@1
  //unsigned int v15; // [sp+10h] [bp-48h]@23
  //unsigned int v16; // [sp+14h] [bp-44h]@21
  //unsigned int v17; // [sp+18h] [bp-40h]@21
  LARGE_INTEGER Frequency; // [sp+1Ch] [bp-3Ch]@1
  LARGE_INTEGER PerformanceCount; // [sp+24h] [bp-34h]@2
  LARGE_INTEGER v20; // [sp+2Ch] [bp-2Ch]@2
  int v21; // [sp+34h] [bp-24h]@2
  int v22; // [sp+38h] [bp-20h]@2
  int v23; // [sp+3Ch] [bp-1Ch]@4
  int v24; // [sp+40h] [bp-18h]@7
  int nPriority; // [sp+44h] [bp-14h]@2
  unsigned int v26; // [sp+48h] [bp-10h]@1
  unsigned int v27; // [sp+4Ch] [bp-Ch]@1
  HANDLE hThread; // [sp+50h] [bp-8h]@1
  int v29; // [sp+54h] [bp-4h]@1

  v2 = 0;
  v1 = 0;
  v29 = 0;
  v27 = 0;
  v26 = 0;
  hThread = GetCurrentThread();
  memset(Dst, 0, 0x10u);
  if ( QueryPerformanceFrequency(&Frequency) )
  {
    do
    {
      ++v29;
      v22 = v2;
      v21 = v1;
      QueryPerformanceCounter(&PerformanceCount);
      v20 = PerformanceCount;
      nPriority = GetThreadPriority(hThread);
      if ( nPriority != 2147483647 )
        SetThreadPriority(hThread, 15);
      while ( v20.LowPart - PerformanceCount.LowPart < 0x32 )
      {
        QueryPerformanceCounter(&v20);
        //v3 = RDTSC();
        __asm
        {
         rdtsc
         mov dword ptr [v3], eax
        }
        v23 = v3;
      }
      PerformanceCount = v20;
      do
      {
        QueryPerformanceCounter(&v20);
        //v6 = RDTSC();
        __asm
        {
         rdtsc
         mov dword ptr [v6], eax
        }
        v24 = v6;
        v5 = v20.LowPart;
        v4 = PerformanceCount.LowPart;
      }
      while ( v20.LowPart - PerformanceCount.LowPart < 0x3E8 );
      if ( nPriority != 2147483647 )
      {
        SetThreadPriority(hThread, nPriority);
        v4 = PerformanceCount.LowPart;
        v5 = v20.LowPart;
      }
      v9 = 100000 * v5 - 100000 * v4;
      v7 = v24 - v23;
      v27 += v24 - v23;
      v10 = v9;
      v8 = v9 / (Frequency.LowPart / 0xA);
      v26 += v8;
      if ( v10 / (Frequency.LowPart / 0xA) % Frequency.LowPart > (_DWORD)Frequency.LowPart >> 1 )
        ++v8;
      v1 = v7 / v8;
      if ( v7 % v8 > v8 >> 1 )
        v1 = v7 / v8 + 1;
      v2 = v21;
      v11 = v1 + v22 + v21;
    }
    while ( v29 < 3
         || v29 < 20
         && ((unsigned int)(3 * v1 - v11) > 3 || (unsigned int)(3 * v21 - v11) > 3 || (unsigned int)(3 * v22 - v11) > 3) );
    v12 = 10 * v27 / v26;
    if ( 100 * v27 / v26 - 10 * v12 >= 6 )
      ++v12;
    Dst[2] = v27 / v26;
    Dst[3] = v27 / v26;
    if ( v12 - 10 * v27 / v26 >= 6 )
      Dst[3] = v27 / v26 + 1;
    Dst[1] = v26;
    Dst[0] = v27;
  }
  result = a1;
  *(_DWORD *)a1 = Dst[0];
  *(_DWORD *)(a1 + 4) = Dst[1];
  *(_DWORD *)(a1 + 8) = Dst[2];
  *(_DWORD *)(a1 + 12) = Dst[3];
  return result;
}

//----- (004AC4FD) --------------------------------------------------------
int __stdcall sub_4AC4FD(int a1)
{
  int v1; // eax@1
  int v3; // eax@4
  bool v5; // eax@5
  unsigned __int64 v6; // qax@8
  int v7; // eax@9
  int v8; // edi@9
  bool v10; // eax@10
  unsigned __int64 v11; // qax@13
  unsigned int v12; // eax@15
  int result; // eax@17
  int Dst; // [sp+Ch] [bp-2Ch]@1
  int v15; // [sp+10h] [bp-28h]@17
  unsigned int v16; // [sp+14h] [bp-24h]@15
  unsigned int v17; // [sp+18h] [bp-20h]@17
  unsigned int v18; // [sp+1Ch] [bp-1Ch]@8
  unsigned int v19; // [sp+20h] [bp-18h]@8
  unsigned int v20; // [sp+24h] [bp-14h]@13
  int nPriority; // [sp+28h] [bp-10h]@1
  int v22; // [sp+2Ch] [bp-Ch]@4
  unsigned __int64 hThread; // [sp+30h] [bp-8h]@1

  LODWORD(hThread) = (int)GetCurrentThread();
  memset(&Dst, 0, 0x10u);
  v1 = GetThreadPriority((HANDLE)hThread);
  nPriority = v1;
  if ( v1 != 2147483647 )
    SetThreadPriority((HANDLE)hThread, v1 + 1);
  HIDWORD(hThread) = 0;
  compile_error;//_AX = 0;
  __asm
  {
    out     70h, al         // CMOS Memory:
    in      al, 71h         // CMOS Memory
  }
  compile_error;//WORD2(hThread) = _AX;
  do
  {
    v22 = 0;
    compile_error;//_AX = 0;
    __asm
    {
      out     70h, al         // CMOS Memory:
      in      al, 71h         // CMOS Memory
    }
    compile_error;//LOWORD(v22) = _AX;
    v3 = v22 - HIDWORD(hThread);
    if ( v22 >= HIDWORD(hThread) )
      v5 = v3 > 0;
    else
      v5 = v3 + 10;
  }
  while ( !v5 );
  compile_error;//v6 = RDTSC();
  v19 = v6;
  v18 = HIDWORD(v6);
  do
  {
    HIDWORD(hThread) = 0;
    compile_error;//_AX = 0;
    __asm
    {
      out     70h, al         // CMOS Memory:
      in      al, 71h         // CMOS Memory
    }
    compile_error;//WORD2(hThread) = _AX;
    v8 = HIDWORD(hThread);
    v7 = HIDWORD(hThread) - v22;
    if ( HIDWORD(hThread) >= v22 )
      v10 = v7 > 0;
    else
      v10 = v7 + 10;
  }
  while ( !v10 );
  compile_error;//v11 = RDTSC();
  HIDWORD(hThread) = v11;
  v20 = HIDWORD(v11);
  if ( nPriority != 2147483647 )
    SetThreadPriority((HANDLE)hThread, nPriority);
  nPriority = HIDWORD(hThread);
  compile_error;//hThread = __PAIR__(v20, HIDWORD(hThread)) - __PAIR__(v18, v19);
  Dst = hThread;
  v12 = (_DWORD)hThread / 0xF4240u;
  v16 = (_DWORD)hThread / 0xF4240u;
  if ( (_DWORD)hThread / 0x186A0u - 10 * (_DWORD)hThread / 0xF4240u >= 6 )
    ++v12;
  v17 = v12;
  result = a1;
  v15 = 1000000 * v8 - 1000000 * v22;
  *(_DWORD *)a1 = Dst;
  *(_DWORD *)(a1 + 4) = v15;
  *(_DWORD *)(a1 + 8) = v16;
  *(_DWORD *)(a1 + 12) = v17;
  return result;
}




//----- (004ACC38) --------------------------------------------------------
int __thiscall sub_4ACC38(int _this, struct Render_BillboardTransform_stru0 *a2, char a3)
{
  int result; // eax@1
  int v4; // edi@1
  int v5; // ecx@2
  int v6; // ebx@2
  int v7; // esi@2
  signed int v8; // esi@2
  int v9; // ST18_4@2
  signed int v10; // eax@2
  signed int v11; // ebx@2
  int v12; // edx@4
  int v13; // esi@13
  int v14; // edx@17
  int v15; // ecx@17
  int v16; // esi@17
  int v17; // esi@17
  int v18; // ecx@18
  int v19; // esi@18
  int v20; // edx@21
  int v21; // eax@22
  int v22; // esi@22
  int v23; // ecx@25
  int v24; // eax@25
  int v25; // eax@27
  signed __int64 v26; // qtt@27
  int v27; // eax@29
  int v28; // edx@29
  signed int v29; // ecx@30
  int v30; // ecx@37
  int v31; // ecx@38
  signed int v32; // ecx@41
  int v33; // ecx@47
  char v34; // zf@54
  int v35; // ecx@56
  __int16 v36; // ax@58
  int v37; // esi@58
  int v38; // eax@59
  int v39; // ecx@59
  int v40; // ecx@62
  int v41; // ecx@64
  signed int v42; // ST30_4@64
  signed __int64 v43; // qtt@64
  int v44; // eax@66
  int v45; // ecx@66
  int v46; // edx@69
  int v47; // edx@77
  char v48; // zf@85
  int v49; // [sp+Ch] [bp-50h]@2
  signed int v50; // [sp+10h] [bp-4Ch]@2
  signed int v51; // [sp+14h] [bp-48h]@2
  int v52; // [sp+14h] [bp-48h]@13
  int v53; // [sp+14h] [bp-48h]@19
  int v54; // [sp+14h] [bp-48h]@57
  int v55; // [sp+18h] [bp-44h]@13
  int v56; // [sp+1Ch] [bp-40h]@2
  int v57; // [sp+1Ch] [bp-40h]@22
  int v58; // [sp+1Ch] [bp-40h]@32
  int v59; // [sp+1Ch] [bp-40h]@69
  unsigned int v60; // [sp+20h] [bp-3Ch]@2
  int v61; // [sp+24h] [bp-38h]@1
  int v62; // [sp+28h] [bp-34h]@2
  int v63; // [sp+28h] [bp-34h]@13
  int v64; // [sp+2Ch] [bp-30h]@2
  int v65; // [sp+30h] [bp-2Ch]@2
  int v66; // [sp+30h] [bp-2Ch]@29
  int v67; // [sp+30h] [bp-2Ch]@66
  int v68; // [sp+34h] [bp-28h]@2
  int v69; // [sp+34h] [bp-28h]@22
  int v70; // [sp+34h] [bp-28h]@59
  int v71; // [sp+38h] [bp-24h]@13
  int v72; // [sp+3Ch] [bp-20h]@2
  int v73; // [sp+40h] [bp-1Ch]@2
  signed int v74; // [sp+40h] [bp-1Ch]@15
  int v75; // [sp+44h] [bp-18h]@2
  int v76; // [sp+44h] [bp-18h]@29
  int v77; // [sp+44h] [bp-18h]@66
  int v78; // [sp+48h] [bp-14h]@4
  int v79; // [sp+48h] [bp-14h]@22
  int v80; // [sp+48h] [bp-14h]@59
  int v81; // [sp+4Ch] [bp-10h]@1
  int v82; // [sp+50h] [bp-Ch]@4
  int v83; // [sp+50h] [bp-Ch]@21
  int v84; // [sp+50h] [bp-Ch]@62
  int v85; // [sp+50h] [bp-Ch]@67
  int v86; // [sp+50h] [bp-Ch]@75
  int v87; // [sp+54h] [bp-8h]@4
  int v88; // [sp+58h] [bp-4h]@18
  int v89; // [sp+58h] [bp-4h]@56
  signed int v90; // [sp+64h] [bp+8h]@2
  int v91; // [sp+68h] [bp+Ch]@18
  int v92; // [sp+68h] [bp+Ch]@56

  v4 = (int)a2;
  v81 = _this;
  result = *(_DWORD *)(a2 + 16);
  v61 = *(_DWORD *)(a2 + 16);
  if ( result <= 0 )
    return result;
  v8 = *(_DWORD *)(a2 + 20);
  v9 = *(_DWORD *)(a2 + 16);
  v90 = 4294967296i64 / result;
  v50 = 4294967296i64 / result;
  v65 = 4294967296i64 / v8;
  v10 = *(_WORD *)(_this + 18);
  v11 = (signed int)(4294967296i64 / v8) >> 1;
  v56 = v11;
  v73 = (*(_WORD *)(_this + 18) << 16) - v11;
  v51 = v10;
  v72 = *(_DWORD *)(v4 + 48);
  v49 = *(_DWORD *)v4;
  v60 = *(_DWORD *)(v4 + 40);
  v64 = *(_DWORD *)(v4 + 32);
  v6 = (v9 * *(_WORD *)(_this + 16) + 32768) >> 16;
  v75 = *(_DWORD *)(v4 + 12);
  result = (v8 * v10 + 32768) >> 16;
  v5 = v75 - result + 1;
  v7 = *(_DWORD *)(v4 + 8) - (v6 >> 1) + 1;
  v68 = v75 - result + 1;
  v62 = v7 + v6 - 1;
  if ( *(_BYTE *)(v4 + 45) & 8 )
  {
    v5 += v51 >> 1;
    v75 += v51 >> 1;
    v68 = v5;
  }
  v12 = v75;
  v87 = v5;
  v78 = *(_DWORD *)(v4 + 8) - (v6 >> 1) + 1;
  v82 = v7 + v6 - 1;
  if ( !(*(_BYTE *)(v4 + 44) & 8) )
  {
    if ( v68 < *(_DWORD *)(v4 + 56) )
      v87 = *(_DWORD *)(v4 + 56);
    if ( v75 > *(_DWORD *)(v4 + 64) )
      v12 = *(_DWORD *)(v4 + 64);
    if ( v7 < *(_DWORD *)(v4 + 52) )
      v78 = *(_DWORD *)(v4 + 52);
    if ( v62 > *(_DWORD *)(v4 + 60) )
      v82 = *(_DWORD *)(v4 + 60);
  }
  v71 = v78 - v7;
  v13 = -v65;
  v63 = v62 - v82;
  v55 = -v65;
  v52 = *(_DWORD *)(v4 + 44);
  if ( *(_DWORD *)(v4 + 44) & 1 )
  {
    v13 = v65;
    v73 = v56;
    v55 = v65;
  }
  v74 = v13 * (v75 - v12) + v73;
  if (struct_576FE8.dword_000020)
  {
    if ( a3 )
      return result;
  }
  v17 = 5 * v12;
  v15 = v72 * v12;
  result = v12 - v75 + result - 1;
  v14 = v87 - v68;
  v16 = v17 << 7;
  if ( v52 & 4 )
  {
    v35 = v82 + v15;
    v92 = v35;
    v89 = v82 + v16;
    if ( result < v14 )
      return result;
    v54 = result - v14 + 1;
    while ( 1 )
    {
      v37 = 8 * (v74 >> 16);
      v36 = *(_WORD *)(v37 + *(_DWORD *)(v81 + 32));
      if ( v36 == -1 )
      {
        v35 -= v72;
        v92 = v35;
        goto LABEL_84;
      }
      v39 = v6 - ((unsigned __int64)(v36 * v61) >> 16);
      v70 = v90 * ((unsigned __int64)(*(_WORD *)(v37 + *(_DWORD *)(v81 + 32)) * v61) >> 16);
      v38 = v6 - v63;
      v80 = v6 - v63;
      if ( v6 - v63 <= (signed int)(v6 - ((unsigned __int64)(*(_WORD *)(v37 + *(_DWORD *)(v81 + 32) + 2) * v61) >> 16))
        || v71 >= v39 )
      {
        v92 -= v72;
        v35 = v92;
LABEL_84:
        v89 -= 640;
        goto LABEL_85;
      }
      if ( v38 < v39 )
      {
        v84 = (v90 >> 1) + v90 * (v39 - v38);
      }
      else
      {
        v80 = v39;
        v84 = v90 >> 1;
        v40 = v39 - v6;
        v92 += v40 + v63;
        v89 += v63 + v40;
      }
      v42 = ((*(_WORD *)(v37 + *(_DWORD *)(v81 + 32) + 2) + 1) << 16) - v84 - v70;
      LODWORD(v43) = v42 << 16;
      HIDWORD(v43) = v42 >> 16;
      v41 = v80 - (((signed int)(v43 / v50 - 32768) >> 16) + 1);
      if ( v71 >= v41 )
        v41 = v71;
      v44 = v49 + 2 * v92;
      v77 = v44 + 2 * (v41 - v80) + 2;
      v45 = v37 + *(_DWORD *)(v81 + 32);
      v67 = *(_DWORD *)(v45 + 4);
      if ( !v60 )
      {
        v86 = v70 + v84;
        if ( ((v86 - (*(_WORD *)v45 << 16)) & 0xFFFF0000) < 0 )
        {
          v86 += v90;
          v44 -= 2;
          v87 -= 4;
        }
        while ( v44 >= (unsigned int)v77 )
        {
          v47 = (v86 - ((signed int)*(_WORD *)(v37 + *(_DWORD *)(v81 + 32)) << 16)) >> 16;
          if ( *(_BYTE *)(v47 + v67) )
            *(_WORD *)v44 = *(_WORD *)(v64 + 2 * *(_BYTE *)(v47 + v67));
          v86 += v90;
          v44 -= 2;
        }
        goto LABEL_81;
      }
      v87 = *(_DWORD *)(v4 + 4) + 4 * v89;
      v85 = v70 + v84;
      if ( ((v85 - (*(_WORD *)v45 << 16)) & 0xFFFF0000) < 0 )
        goto LABEL_72;
      while ( 2 )
      {
        if ( v44 >= (unsigned int)v77 )
        {
          v46 = (v85 - ((signed int)*(_WORD *)(v37 + *(_DWORD *)(v81 + 32)) << 16)) >> 16;
          v59 = *(_BYTE *)(v46 + v67);
          if ( *(_BYTE *)(v46 + v67) )
          {
            if ( v60 <= *(_DWORD *)v87 )
            {
              *(_DWORD *)v87 = v60;
              *(_WORD *)v44 = *(_WORD *)(v64 + 2 * v59);
            }
          }
LABEL_72:
          v85 += v90;
          v44 -= 2;
          v87 -= 4;
          continue;
        }
        break;
      }
LABEL_81:
      v92 += v6 - v80 - v63 - v72;
      v35 = v92;
      v89 = v89 + v6 - v80 - v63 - 640;
LABEL_85:
      result = v55;
      v74 += v55;
      v48 = v54-- == 1;
      if ( v48 )
        return result;
    }
  }
  v18 = v78 + v15;
  v19 = v78 + v16;
  v91 = v18;
  v88 = v19;
  if ( result >= v14 )
  {
    v53 = result - v14 + 1;
    while ( 1 )
    {
      v20 = 8 * (v74 >> 16) + *(_DWORD *)(v81 + 32);
      v83 = 8 * (v74 >> 16);
      if ( *(_WORD *)v20 != -1 )
        break;
      v18 -= v72;
      v88 = v19 - 640;
      v91 = v18;
LABEL_54:
      result = v55;
      v74 += v55;
      v34 = v53-- == 1;
      if ( v34 )
        return result;
      v19 = v88;
    }
    v21 = (v61 * *(_WORD *)v20 + 32768) >> 16;
    v69 = v21 * v90;
    v79 = v71;
    v57 = *(_WORD *)(v20 + 2);
    v22 = v6 - v63;
    if ( v71 >= (v61 * v57 + 32768) >> 16 || v22 <= v21 )
    {
      v91 -= v72;
      v88 -= 640;
      goto LABEL_51;
    }
    if ( v71 > v21 )
    {
      v23 = (v90 >> 1) + v90 * (v71 - v21);
    }
    else
    {
      v79 = (v61 * *(_WORD *)v20 + 32768) >> 16;
      v24 = v21 - v71;
      v91 += v24;
      v23 = v90 >> 1;
      v88 += v24;
    }
    LODWORD(v26) = (((v57 + 1) << 16) - v23 - v69) << 16;
    HIDWORD(v26) = (((v57 + 1) << 16) - v23 - v69) >> 16;
    v25 = v79 + ((signed int)(v26 / v50) >> 16) + 1;
    if ( v22 > v25 )
      v22 = v25;
    v27 = v49 + 2 * v91;
    v76 = v27 + 2 * (v22 - v79) - 2;
    v28 = v83 + *(_DWORD *)(v81 + 32);
    v66 = *(_DWORD *)(v28 + 4);
    if ( v60 )
    {
      v87 = *(_DWORD *)(v4 + 4) + 4 * v88;
      v29 = v69 - (*(_WORD *)v28 << 16) + v23;
      if ( (v29 & 0xFFFF0000) >= 0 )
        goto LABEL_36;
      while ( 1 )
      {
        v29 += v90;
        v27 += 2;
        v87 += 4;
LABEL_36:
        if ( v27 >= (unsigned int)v76 )
          break;
        v58 = *(_BYTE *)((v29 >> 16) + v66);
        if ( *(_BYTE *)((v29 >> 16) + v66) )
        {
          if ( v60 <= *(_DWORD *)v87 )
          {
            *(_DWORD *)v87 = v60;
            *(_WORD *)v27 = *(_WORD *)(v64 + 2 * v58);
          }
        }
      }
      v30 = v29 >> 16;
      if ( v30 > *(_WORD *)(v83 + *(_DWORD *)(v81 + 32) + 2) - (signed int)*(_WORD *)(v83 + *(_DWORD *)(v81 + 32))
        || (v31 = *(_BYTE *)(v30 + v66), !v31)
        || v60 > *(_DWORD *)v87 )
        goto LABEL_50;
      *(_DWORD *)v87 = v60;
    }
    else
    {
      v32 = v69 - (*(_WORD *)v28 << 16) + v23;
      if ( (v32 & 0xFFFF0000) < 0 )
      {
        v32 += v90;
        v27 += 2;
        v87 += 4;
      }
      while ( v27 < (unsigned int)v76 )
      {
        if ( *(_BYTE *)((v32 >> 16) + v66) )
          *(_WORD *)v27 = *(_WORD *)(v64 + 2 * *(_BYTE *)((v32 >> 16) + v66));
        v32 += v90;
        v27 += 2;
      }
      v33 = v32 >> 16;
      if ( v33 > *(_WORD *)(v83 + *(_DWORD *)(v81 + 32) + 2) - (signed int)*(_WORD *)(v83 + *(_DWORD *)(v81 + 32))
        || (v31 = *(_BYTE *)(v33 + v66), !v31) )
        goto LABEL_50;
    }
    *(_WORD *)v27 = *(_WORD *)(v64 + 2 * v31);
LABEL_50:
    v91 += v71 - v79 - v72;
    v88 = v88 + v71 - v79 - 640;
LABEL_51:
    v18 = v91;
    goto LABEL_54;
  }
  return result;
}

//----- (004AD2D1) --------------------------------------------------------
int __thiscall sub_4AD2D1(int _this, int a2, int a3)
{
  int result; // eax@1
  int v4; // edi@1
  int v5; // esi@1
  int v6; // edx@2
  __int16 v7; // bx@2
  int v8; // edx@3
  int v9; // ecx@3
  int v10; // esi@3
  int v11; // ecx@3
  int v12; // ebx@3
  int v13; // ebx@4
  int v14; // [sp+8h] [bp-10h]@1
  int v15; // [sp+10h] [bp-8h]@1
  int v16; // [sp+14h] [bp-4h]@1
  int i; // [sp+20h] [bp+8h]@1

  result = a2;
  v14 = _this;
  v5 = *(_DWORD *)(a2 + 48);
  v16 = *(_DWORD *)a2;
  v15 = *(_DWORD *)(a2 + 32);
  v4 = *(_WORD *)(_this + 18) - 1;
  for ( i = v5 * *(_DWORD *)(a2 + 12) - ((signed int)*(_WORD *)(_this + 16) >> 1) + *(_DWORD *)(a2 + 8) + 1; v4 >= 0; --v4 )
  {
    v6 = *(_DWORD *)(_this + 32) + 8 * v4;
    v7 = *(_WORD *)v6;
    if ( *(_WORD *)v6 != -1 )
    {
      v11 = v7;
      v10 = v16 + 2 * (v7 + i);
      v12 = *(_WORD *)(v6 + 2);
      v8 = *(_DWORD *)(v6 + 4);
      v9 = v10 + 2 * (v12 - v11);
      while ( v10 <= (unsigned int)v9 )
      {
        v13 = *(_BYTE *)v8++;
        if ( v13 )
          *(_WORD *)v10 = *(_WORD *)(v15 + 2 * v13);
        v10 += 2;
      }
      v5 = *(_DWORD *)(result + 48);
      _this = v14;
    }
    i -= v5;
  }
  return result;
}

//----- (004AD385) --------------------------------------------------------
int __thiscall sub_4AD385(int _this)
{
  int result; // eax@1

  result = _this;
  *(_DWORD *)(_this + 4804) = 0;
  *(_DWORD *)_this = 5081456;
  return result;
}

//----- (004AD3C8) --------------------------------------------------------
bool StationaryLightsStack_AddLight(struct StationaryLightsStack *_this, int sLightPosX, int sLightPosY, int sLightPosZ, __int16 a5, unsigned int uLightColorRed, unsigned char uLightColorGreen, unsigned char uLightColorBlue, char a9)
{
  char result; // al@2
 struct StationaryLight *pLight; // eax@2
  char v12; // [sp-18h] [bp-18h]@3
  const CHAR *v13; // [sp-14h] [bp-14h]@3
  int v14; // [sp-10h] [bp-10h]@3
  int v15; // [sp-Ch] [bp-Ch]@3
  char *v18; // [sp+18h] [bp+18h]@3

  if (_this->uNumStationaryLightsActive >= 400)
  {
    v18 = &v12;
    Game_sub_40E2C8(&v12, "Too many stationary lights!", (int)((char *)&uLightColorRed + 3));
    sub_467834(&uLightColorGreen, v12, v13, v14, v15, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\StationaryLightStack.cpp", __LINE__);
    return false;
  }
  else
  {
   pLight = &_this->pLights[_this->uNumStationaryLightsActive++];
   pLight->sLightPosX = sLightPosX;
   pLight->sLightPosY = sLightPosY;
   pLight->sLightPosZ = sLightPosZ;
   pLight->word_000006 = a5;
   pLight->uLightColorRed = uLightColorRed;
   pLight->uLightColorGreen = uLightColorGreen;
   pLight->uLightColorBlue = uLightColorBlue;
   pLight->byte_00000B = a9;
   return true;
  }
}

//----- (004AD48F) --------------------------------------------------------
int __thiscall sub_4AD48F(int _this)
{
  int v2; // esi@1
  int v3; // edi@1

  v2 = _this;
  v3 = _this + 152;
  *(_DWORD *)_this = 5081468;
  *(_DWORD *)(_this + 152) = 0;
  *(_DWORD *)(_this + 4) = 148;
  GetVersionExA((LPOSVERSIONINFOA)(_this + 4));
  *(_DWORD *)v3 |= 1u;
  return v2;
}