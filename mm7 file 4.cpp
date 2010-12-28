#include <ddraw.h>
//#include <dinput.h>
#include <io.h>
#include "localization_defs.h"
#include "defs.h"
#include "menus.h"
#include "clock.h"

#include "_lod.h"
#include "data.h"
#include "AudioPlayer.h"
#include "VideoPlayer.h"
#include "FrameTables.h"
#include "UserInput.h"

#include "GUI\GUI.h"

#include "Level.h"
#include "Actor.h"
 
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "Game.h"

//----- (00424EE0) --------------------------------------------------------
signed int __fastcall sub_424EE0_MakeFanFromTriangle(int a1)
{
  int v1; // edx@1
  signed int v2; // edi@1
  double v3; // st7@1
 struct RenderVertex *v5; // ecx@4
  int v7; // eax@4
  double v9; // st6@10
  double v10; // st6@11
  unsigned __int8 v12; // c3@15
  double v15; // st6@22
  signed int result; // eax@24
  int v20; // [sp+Ch] [bp-28h]@6
  signed int v23; // [sp+18h] [bp-1Ch]@1
 int i;

  v1 = a1;
  v3 = (double)pStruct9_global->shading_dist_mist;
  memcpy(&array_50AC10[a1], array_50AC10, sizeof(struct RenderVertex));
  v2 = 0;
  v23 = 0;
  if ( array_50AC10[0].flt_00000C <= v3 )
    v2 = 1;
  if ( a1 + 1 <= 1 )
    return 0;
  
  v7 = v1;
  v5 = array_507D30;
  for (i = 0; i < a1 - 1; ++i)
  {
    v20 = v3 >= array_50AC10[i + 1].flt_00000C;
    if ( v2 == v20 )
      goto LABEL_21;

      if ( v20 )
      {
       v9 = (v3 - array_50AC10[i].flt_00000C) /
            (array_50AC10[i + 1].flt_00000C - array_50AC10[i].flt_00000C);
       v5->flt_000010 = (array_50AC10[i + 1].flt_000010 - array_50AC10[i].flt_000010) * v9 + array_50AC10[i].flt_000010;
       v5->flt_000014 = (array_50AC10[i + 1].flt_000014 - array_50AC10[i].flt_000014) * v9 + array_50AC10[i].flt_000014;
       v5->u = (array_50AC10[i + 1].u - array_50AC10[i].u) * v9 + array_50AC10[i].u;
       v5->v  = (array_50AC10[i + 1].v - array_50AC10[i].v) * v9 + array_50AC10[i].v;
      }
      else
      {
        v10 = (v3 - array_50AC10[i + 1].flt_00000C) / (array_50AC10[i].flt_00000C - array_50AC10[i + 1].flt_00000C);
       v5->flt_000010 = (array_50AC10[i].flt_000010 - array_50AC10[i + 1].flt_000010) * v10 + array_50AC10[i + 1].flt_000010;
       v5->flt_000014 = (array_50AC10[i].flt_000014 - array_50AC10[i + 1].flt_000014) * v10 + array_50AC10[i + 1].flt_000014;
       v5->u = (array_50AC10[i].u - array_50AC10[i + 1].u) * v10 + array_50AC10[i + 1].u;
       v5->v  = (array_50AC10[i].v - array_50AC10[i + 1].v) * v10 + array_50AC10[i + 1].v;
      }

      v5->flt_00000C = v3;
      v5->flt_000020 = 1.0 / v3;
      if ( v2 )
      {
        if (v3 != array_50AC10[i].flt_00000C || v5->flt_000010 != array_50AC10[i].flt_000010 ||
            v5->flt_000014 == array_50AC10[i].flt_000014)
        {
      v5++;
      ++v23;
        }
      }
      else if (v3 != array_50AC10[i + 1].flt_00000C || v5->flt_000010 != array_50AC10[i + 1].flt_000010 ||
               v5->flt_000014 == array_50AC10[i + 1].flt_000014)
      {
      v5++;
      ++v23;
      }

LABEL_21:
    if ( v20 )
    {
      v15 = 1.0 / (array_50AC10[i + 1].flt_00000C + 0.0000001000000011686097);
      ++v23;
      memcpy(v5, &array_50AC10[i + 1], sizeof(struct RenderVertex));
      v5->flt_000020 = v15;
      v5->flt_00002C = array_50AC10[i + 1].flt_00002C;
      v5++;
    }
    v2 = v20;
  }

  result = v23;
  if ( v23 < 3 )
    return 0;
  return result;
}

//----- (004250FE) --------------------------------------------------------
signed int __fastcall sub_4250FE(int a1)
{
  int v1; // edx@1
  struct RenderVertex *v3; // edi@5
  double v7; // st6@11
  double v8; // st6@12
  double v12; // st6@23
  signed int result; // eax@25
  bool v17; // [sp+Ch] [bp-24h]@2
  bool v18; // [sp+10h] [bp-20h]@7
  signed int v21; // [sp+1Ch] [bp-14h]@1
 int i;

  memcpy(&array_50AC10[a1], array_50AC10, sizeof(struct RenderVertex));
  v21 = 0;
  v17 = array_50AC10[0].flt_00000C >= 8.0;
  if ( a1 + 1 <= 1 )
    return 0;
  v3 = array_507D30;

 for (i = 0; i < a1; ++i)
 {
    v18 = array_50AC10[i + 1].flt_00000C >= 8.0;
    if ( v17 == v18 )
      goto LABEL_22;

    if ( v18 )
      {
        v7 = (8.0 - array_50AC10[i].flt_00000C) /
             (array_50AC10[i + 1].flt_00000C - array_50AC10[i].flt_00000C);
        v3->flt_000010 = (array_50AC10[i + 1].flt_000010 - array_50AC10[i].flt_000010) * v7 + array_50AC10[i].flt_000010;
        v3->flt_000014 = (array_50AC10[i + 1].flt_000014 - array_50AC10[i].flt_000014) * v7 + array_50AC10[i].flt_000014;
        v3->flt_00002C = (array_50AC10[i + 1].flt_00002C - array_50AC10[i].flt_00002C) * v7 + array_50AC10[i].flt_00002C;
      }
      else
      {
        v8 = (8.0 - array_50AC10[i + 1].flt_00000C) /
             (array_50AC10[i].flt_00000C - array_50AC10[i + 1].flt_00000C);
        v3->flt_000010 = (array_50AC10[i].flt_000010 - array_50AC10[i + 1].flt_000010) * v8 + array_50AC10[i + 1].flt_000010;
        v3->flt_000014 = (array_50AC10[i].flt_000014 - array_50AC10[i + 1].flt_000014) * v8 + array_50AC10[i + 1].flt_000014;
        v3->flt_00002C = (array_50AC10[i].flt_00002C - array_50AC10[i + 1].flt_00002C) * v8 + array_50AC10[i + 1].flt_00002C;
      }

      v3->flt_00000C = 8.0;
      v3->flt_000020 = 0.12500000;

      if (v17)
      {
        if (array_50AC10[i].flt_00000C != 8.0 ||
            v3->flt_000010 != array_50AC10[i].flt_000010 ||
            v3->flt_000014 != array_50AC10[i].flt_000014)
        {
         v3++;
         ++v21;
        }
      }
      else if (array_50AC10[i + 1].flt_00000C != 8.0 ||
            v3->flt_000010 != array_50AC10[i + 1].flt_000010 ||
            v3->flt_000014 != array_50AC10[i + 1].flt_000014)
        {
         v3++;
         ++v21;
        }

LABEL_22:
    if (v18)
    {
     v12 = 1.0 / (array_50AC10[i + 1].flt_00000C + 0.0000001000000011686097);
      ++v21;
      memcpy(v3, &array_50AC10[i + 1], sizeof(struct RenderVertex));
      v3->flt_000020 = v12;
      v3++;
    }

    v17 = v18;
  }

  result = v21;
  if ( v21 < 3 )
    return 0;
  return result;
}

//----- (004252E8) --------------------------------------------------------
signed int __fastcall sub_4252E8(int a1)
{
  int v1; // edx@1
  struct RenderVertex *v5; // esi@5
  double v8; // st6@11
  double v9; // st6@12
  double v13; // st6@23
  char v15; // zf@24
  signed int result; // eax@25
  bool v18; // [sp+Ch] [bp-24h]@2
  bool v19; // [sp+10h] [bp-20h]@7
  signed int v22; // [sp+1Ch] [bp-14h]@1
 int i;

  v1 = a1;
  memcpy(&array_50AC10[a1], array_50AC10, sizeof(struct RenderVertex));
  v22 = 0;
  v18 = array_50AC10[0].flt_00000C <= pStruct9_global->shading_dist_mist;
  if ( a1 + 1 <= 1 )
    return 0;

 v5 = array_507D30;
 for (i = 0; i < a1; ++i)
 {
  v19 = pStruct9_global->shading_dist_mist >= array_50AC10[i + 1].flt_00000C;
  if (v18 == v19)
    goto LABEL_22;


  if (v19)
  {
   v8 = (pStruct9_global->shading_dist_mist - array_50AC10[i].flt_00000C) /
        (array_50AC10[i + 1].flt_00000C - array_50AC10[i].flt_00000C);
   v5->flt_000010 = (array_50AC10[i + 1].flt_000010 - array_50AC10[i].flt_000010) * v8 + array_50AC10[i].flt_000010;
   v5->flt_000014 = (array_50AC10[i + 1].flt_000014 - array_50AC10[i].flt_000014) * v8 + array_50AC10[i].flt_000014;
   v5->flt_00002C = (array_50AC10[i + 1].flt_00002C - array_50AC10[i].flt_00002C) * v8 + array_50AC10[i].flt_00002C;
  }
  else
  {
   v9 = (pStruct9_global->shading_dist_mist - array_50AC10[i + 1].flt_00000C) /
        (array_50AC10[i].flt_00000C - array_50AC10[i + 1].flt_00000C);
   v5->flt_000010 = (array_50AC10[i].flt_000010 - array_50AC10[i + 1].flt_000010) * v9 + array_50AC10[i + 1].flt_000010;
   v5->flt_000014 = (array_50AC10[i].flt_000014 - array_50AC10[i + 1].flt_000014) * v9 + array_50AC10[i + 1].flt_000014;
   v5->flt_00002C = (array_50AC10[i].flt_00002C - array_50AC10[i + 1].flt_00002C) * v9 + array_50AC10[i + 1].flt_00002C;
  }

  v5->flt_00000C = pStruct9_global->shading_dist_mist;
  v5->flt_000020 = 1.0 / (float)pStruct9_global->shading_dist_mist;

  //if vertices are identical, count them as one?
  if (v18)
  {
   if (pStruct9_global->shading_dist_mist != array_50AC10[i].flt_00000C ||
       v5->flt_000010 != array_50AC10[i].flt_000010 ||
       v5->flt_000014 != array_50AC10[i].flt_000014)
   {
    v5++;
    ++v22;
   }
  }
  else if (pStruct9_global->shading_dist_mist != array_50AC10[i + 1].flt_00000C ||
           v5->flt_000010 != array_50AC10[i + 1].flt_000010 ||
           v5->flt_000014 != array_50AC10[i + 1].flt_000014)
  {
   v5++;
   ++v22;
  }


LABEL_22:
    if (v19)
    {
      v13 = 1.0 / (array_50AC10[i + 1].flt_00000C + 0.0000001000000011686097);
      ++v22;
      memcpy(v5, &array_50AC10[i + 1], sizeof(struct RenderVertex));
      v5->flt_000020 = v13;
      v5++;
    }

    v18 = v19;
  }

  result = v22;
  if ( v22 < 3 )
    return 0;
  return result;
}

//----- (0042620A) --------------------------------------------------------
char __thiscall sub_42620A(int _this)
{
  double v2; // st6@7
  float v3; // ST04_4@7
  float v4; // ST00_4@7
  double v5; // st7@7
  double v6; // st6@8
  float v7; // ST04_4@8
  float v8; // ST00_4@8
  double v9; // st7@8

  if ( *(float *)(_this + 12) < 300.0 || *(float *)(_this + 60) < 300.0 )
  {
    if ( *(float *)(_this + 12) < 300.0 && *(float *)(_this + 60) < 300.0 )
      return 0;
    if ( *(float *)(_this + 12) >= 300.0 )
    {
      v6 = 1.0 / (*(float *)(_this + 12) - *(float *)(_this + 60));
      v7 = (*(float *)(_this + 16) - *(float *)(_this + 64)) * v6;
      v8 = (*(float *)(_this + 20) - *(float *)(_this + 68)) * v6;
      v9 = 300.0 - *(float *)(_this + 60);
      *(float *)(_this + 60) = v9 + *(float *)(_this + 60);
      *(float *)(_this + 64) = v7 * v9 + *(float *)(_this + 64);
      *(float *)(_this + 68) = v9 * v8 + *(float *)(_this + 68);
    }
    else
    {
      v2 = 1.0 / (*(float *)(_this + 60) - *(float *)(_this + 12));
      v3 = (*(float *)(_this + 64) - *(float *)(_this + 16)) * v2;
      v4 = (*(float *)(_this + 68) - *(float *)(_this + 20)) * v2;
      v5 = 300.0 - *(float *)(_this + 12);
      *(float *)(_this + 12) = v5 + *(float *)(_this + 12);
      *(float *)(_this + 16) = v3 * v5 + *(float *)(_this + 16);
      *(float *)(_this + 20) = v5 * v4 + *(float *)(_this + 20);
    }
  }
  return 1;
}





//----- (004268E3) --------------------------------------------------------
int __fastcall sub_4268E3(unsigned int a1)
{
  unsigned int v2; // eax@1
  unsigned int v3; // edx@1
  int v4; // eax@1
  int v5; // edx@1
  unsigned int v6; // ecx@1

  v2 = a1 >> 9;
  v3 = a1 >> 6;
  LOWORD(v2) = (a1 >> 9) & 0x7C00;
  LOWORD(v3) = (a1 >> 6) & 0x3E0;
  v4 = v3 | v2;
  v5 = (unsigned __int8)((_BYTE)a1 >> 3);
  v6 = a1 >> 16;
  LOWORD(v6) = v6 & 0x8000;
  return v6 | v5 | v4;
}

//----- (0042690D) --------------------------------------------------------
int __fastcall sub_42690D(unsigned int a1)
{
  unsigned int v2; // eax@1
  unsigned int v3; // edx@1

  v2 = a1 >> 8;
  v3 = a1 >> 5;
  LOWORD(v2) = (a1 >> 8) & 0xF800;
  LOWORD(v3) = (a1 >> 5) & 0x7E0;
  return (unsigned __int8)((_BYTE)a1 >> 3) | v3 | v2;
}

//----- (00426987) --------------------------------------------------------
int __thiscall sub_426987(int _this)
{
  int result; // eax@1

  result = _this;
  *(_WORD *)(_this + 8) = 0;
  *(_WORD *)_this = 0;
  *(_WORD *)(_this + 6) = 0;
  *(_WORD *)(_this + 4) = 0;
  *(_WORD *)(_this + 2) = 0;
  *(_DWORD *)(_this + 16) = 0;
  return result;
}

//----- (004269A2) --------------------------------------------------------
int __fastcall sub_4269A2_GivePartyExp(int a1)
{
  __int64 v1; // qax@1
  signed int v2; // ecx@1
  char *v3; // esi@1
  bool v4; // edi@6
  char *v5; // edi@10
  signed int v6; // esi@10
  int v7; // eax@13
  unsigned __int8 v8; // cf@13
  char v10[16]; // [sp+Ch] [bp-14h]@1
  int v11; // [sp+1Ch] [bp-4h]@10

  LODWORD(v1) = a1;
  v2 = 0;
  v3 = v10;
  //HIDWORD(v1) = &dword_ACD9F4;
  HIDWORD(v1) = (long)&pParty_global->pPlayers[0].pConditions[14];
  do
  {
    v4 = !(*(_DWORD *)(HIDWORD(v1) - 4) | *(_DWORD *)(HIDWORD(v1) - 8))
      && !*(_DWORD *)HIDWORD(v1)
      && !*(_QWORD *)(HIDWORD(v1) + 8)
      && !*(_QWORD *)(HIDWORD(v1) + 16);
    *(_DWORD *)v3 = v4;
    v1 += 29944511987712i64;
    v2 += v4;
    v3 += 4;
  }
  //while ( HIDWORD(v1) < (signed int)&unk_AD46E4 );
  while (HIDWORD(v1) < (int)&pParty_global->pHiredNPCs[1].dword_000024);

  if ( v2 )
  {
    LODWORD(v1) = (_DWORD)v1 / v2;
    v5 = v10;
    v11 = v1;
    for (unsigned int i = 0; i < 4; ++i)
    {
    v6 = (signed int)&pParty_global->pPlayers[i].uExperience;
      if ( *(_DWORD *)v5 )
      {
        if ( v11 )
        {
          LOBYTE(v7) = Player_sub_491317((Player *)(v6 - 160));
          v1 = v11 + v11 * v7 / 100;
          v8 = (_DWORD)v1 >= (unsigned int)-*(_DWORD *)v6;
          *(_DWORD *)v6 += v1;
          *(_DWORD *)(v6 + 4) += HIDWORD(v1) + v8;
          if ( *(_QWORD *)v6 > 4000000000i64 )
          {
            *(_DWORD *)(v6 + 4) = 0;
            *(_DWORD *)v6 = -294967296;
          }
        }
      }
      v5 += 4;
    }
  }
  return v1;
}

//----- (00426A5A) --------------------------------------------------------
void __stdcall sub_426A5A(int a1)
{
  signed int v1; // edi@1
  char v2; // zf@1
  int v3; // eax@13
  int v4; // esi@13
  int v5; // eax@14
  unsigned __int8 v6; // al@30
  void *v7; // esi@34
  int v8; // [sp-4h] [bp-3Ch]@10
  int v9; // [sp-4h] [bp-3Ch]@31
  int v10; // [sp-4h] [bp-3Ch]@38

  struct ItemGen local_0C;
  //char Dst[4]; // [sp+Ch] [bp-2Ch]@1
  //int v12; // [sp+10h] [bp-28h]@17
  //int v13; // [sp+1Ch] [bp-1Ch]@14
  //char v14; // [sp+25h] [bp-13h]@14

  int v15; // [sp+30h] [bp-8h]@1
  int v16; // [sp+34h] [bp-4h]@1

  sub_421B2C_DropPickedItem();
  ItemGen_Reset(&local_0C);
  v1 = 0;
  v2 = (0x00800000 & *(_DWORD *)(a1 + 36)) == 0;
  v15 = 0;
  v16 = 0;
  if ( v2 )
  {
    if ( !*(_BYTE *)(a1 + 54) )
      goto LABEL_9;
    do
    {
      ++v1;
      v16 += rand() % *(_BYTE *)(a1 + 55) + 1;
    }
    while ( v1 < *(_BYTE *)(a1 + 54) );
  }
  else
  {
   if (pClass40->pItems[*(_DWORD *)(a1 + 672) - 1].uEquipType != 18 )
      goto LABEL_9;
    v16 = *(_DWORD *)(a1 + 684);
    ItemGen_Reset((ItemGen *)(a1 + 672));
  }
  if ( v16 )
  {
    sub_420C05(v16, 0);
    struct_576FE8.dword_000044 = 1;
  }
LABEL_9:
  if ( *(_WORD *)(a1 + 180) )
  {
    ItemGen_Reset(&local_0C);
    local_0C.uItemID = *(_WORD *)(a1 + 180);
    v8 = dword_5D29EC[12 * local_0C.uItemID];
    if ( v16 )
      wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[490], v16, v8);
    else
      wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[471], v8);
    sub_44C175((char *)pStringBuffer, 2);
    v3 = local_0C.uItemID;
    v4 = 48 * local_0C.uItemID;
    if (pClass40->pItems[local_0C.uItemID - 1].uEquipType == 12 )
    {
     v4 = 48 * local_0C.uItemID;
     v5 = rand() % 6 + pClass40->pItems[local_0C.uItemID - 1].uDamageModifier + 1;
     local_0C.dword_000010 = v5;
     local_0C.byte_000019 = v5;
      v3 = local_0C.uItemID;
    }
    if (pClass40->pItems[v4/48 - 1].uEquipType == 14 )
    {
      if ( v3 != 220 )
       local_0C.dword_000004 = 2 * rand() % 4 + 2;
    }
    class40_sub_456D17(pClass40, &local_0C);
    if ( !Party_AddItem(pParty_global, &local_0C))
      Party_sub_4936E1_ReceiveItemInHandsWhileInGame(pParty_global, &local_0C);
    *(_WORD *)(a1 + 180) = 0;
    if ( *(_DWORD *)(a1 + 564) )
    {
      if ( !Party_AddItem(pParty_global, (ItemGen *)(a1 + 564)))
      {
        sub_421B2C_DropPickedItem();
        Party_sub_4936E1_ReceiveItemInHandsWhileInGame(pParty_global, (ItemGen *)(a1 + 564));
      }
      ItemGen_Reset((ItemGen *)(a1 + 564));
    }
    if ( *(_DWORD *)(a1 + 600) )
    {
      if ( !Party_AddItem(pParty_global, (ItemGen *)(a1 + 600)))
      {
        sub_421B2C_DropPickedItem();
        Party_sub_4936E1_ReceiveItemInHandsWhileInGame(pParty_global, (const ItemGen *)(a1 + 600));
      }
      ItemGen_Reset((ItemGen *)(a1 + 600));
    }
LABEL_55:
    sub_459667(a1);
    return;
  }
  if (0x00800000 & *(_DWORD *)(a1 + 36) )
  {
    if ( *(_DWORD *)(a1 + 672) )
    {
      memcpy(&local_0C, (const void *)(a1 + 672), sizeof(struct ItemGen));
      ItemGen_Reset((ItemGen *)(a1 + 672));
      v10 = dword_5D29EC[12 * local_0C.uItemID];
      if ( v16 )
        wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[490], v16, v10);
      else
        wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[471], v10);
      sub_44C175((char *)pStringBuffer, 2);
      if ( !Party_AddItem(pParty_global, &local_0C) )
        Party_sub_4936E1_ReceiveItemInHandsWhileInGame(pParty_global, &local_0C);
      v15 = 1;
    }
    goto LABEL_44;
  }
  if ( rand() % 100 >= *(_BYTE *)(a1 + 53) || (v6 = *(_BYTE *)(a1 + 56), !v6) )
  {
LABEL_44:
    v7 = pParty_global;
    goto LABEL_45;
  }
  class40_sub_456620_CreateSomeSemirandomItem(pClass40, v6, *(_BYTE *)(a1 + 57), &local_0C);
  v9 = dword_5D29EC[12 * local_0C.uItemID];
  if ( v16 )
    wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[490], v16, v9);
  else
    wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[471], v9);
  sub_44C175((char *)pStringBuffer, 2);
  v7 = pParty_global;
  if ( !Party_AddItem(pParty_global, &local_0C))
    Party_sub_4936E1_ReceiveItemInHandsWhileInGame(pParty_global, &local_0C);
  v15 = 1;
LABEL_45:
  if ( *(_DWORD *)(a1 + 564) )
  {
    if ( !Party_AddItem((Party *)v7, (ItemGen *)(a1 + 564)))
    {
      sub_421B2C_DropPickedItem();
      Party_sub_4936E1_ReceiveItemInHandsWhileInGame((Party *)v7, (const ItemGen *)(a1 + 564));
      v15 = 1;
    }
    ItemGen_Reset((ItemGen *)(a1 + 564));
  }
  if ( *(_DWORD *)(a1 + 600) )
  {
    if ( !Party_AddItem((Party *)v7, (ItemGen *)(a1 + 600)))
    {
      sub_421B2C_DropPickedItem();
      Party_sub_4936E1_ReceiveItemInHandsWhileInGame((Party *)v7, (const ItemGen *)(a1 + 600));
      v15 = 1;
    }
    ItemGen_Reset((ItemGen *)(a1 + 600));
  }
  if ( !v15 || rand() % 100 < 90 )
    goto LABEL_55;
}

//----- (00426E10) --------------------------------------------------------
int __stdcall sub_426E10(int a1)
{
  signed int v1; // ebx@1
  int v2; // ecx@2
  int v3; // eax@3
  signed int v4; // edx@3
  char v5; // zf@3
  int v6; // eax@6
  int v7; // eax@7
  int v8; // eax@8
  int v9; // eax@9
  int v10; // eax@10
  int v11; // eax@11
  int v12; // esi@35
  signed int v13; // edi@37
  signed int v14; // eax@44
  int v15; // ecx@47
  unsigned __int8 v16; // sf@50
  unsigned __int8 v17; // of@50
  int v18; // esi@52
  int v19; // ecx@53
  int result; // eax@57
  int v21[16]; // [sp+8h] [bp-140h]@3
  int v22[60]; // [sp+48h] [bp-100h]@48
  int v23; // [sp+138h] [bp-10h]@2
  int v24; // [sp+13Ch] [bp-Ch]@1
  int v25; // [sp+140h] [bp-8h]@1
  int v26; // [sp+144h] [bp-4h]@1

  v26 = -1;
  v25 = -1;
  v24 = -1;
  v1 = 0;
  if ( *(_DWORD *)(a1 + 128) )
  {
    v2 = 0;
    v23 = 0;
    do
    {
      v4 = 1;
      v3 = *(_DWORD *)(a1 + 128) & (1 << v2);
      v5 = (*(_DWORD *)(a1 + 128) & (1 << v2)) == 0;
      v21[v2] = v3;
      if ( !v5 )
      {
        if ( v3 > 128 )
        {
          switch ( v3 )
          {
            case 256:
              v26 = 8;
              break;
            case 512:
              v24 = 0;
              break;
            case 1024:
              v24 = 1;
              break;
            case 2048:
              v25 = 0;
              break;
            case 4096:
              v25 = 1;
              break;
            case 8192:
              v25 = 3;
              break;
            case 16384:
              v25 = 2;
              break;
          }
        }
        else
        {
          if ( v3 == 128 )
          {
            v26 = 4;
          }
          else
          {
            v6 = v3 - 1;
            if ( v6 )
            {
              v7 = v6 - 1;
              if ( v7 )
              {
                v8 = v7 - 2;
                if ( v8 )
                {
                  v9 = v8 - 4;
                  if ( v9 )
                  {
                    v10 = v9 - 8;
                    if ( v10 )
                    {
                      v11 = v10 - 16;
                      if ( v11 )
                      {
                        if ( v11 == 32 )
                          v26 = 20;
                      }
                      else
                      {
                        v26 = 32;
                      }
                    }
                    else
                    {
                      v26 = 24;
                    }
                  }
                  else
                  {
                    v26 = 28;
                  }
                }
                else
                {
                  v26 = 16;
                }
              }
              else
              {
                v26 = 12;
              }
            }
            else
            {
              v26 = 0;
            }
          }
        }
        v1 = 0;
        v12 = 0;
        while ( 1 )
        {
          v13 = 0;
          if ( v26 != -1 )
          {
            if ( v26 == *(_BYTE *)(pPlayers[v12] + 185) )
              v13 = v4;
          }
          if ( v24 != -1 )
          {
            if ( v24 == *(_BYTE *)(pPlayers[v12] + 184) )
              v13 = v4;
          }
          if ( v25 != -1 )
          {
            v14 = Player_GetRace(pPlayers[v12]);
            if ( v25 == v14 )
              v13 = 1;
          }
          if ( v13 == 1 )
          {
            v15 = (int)pPlayers[v12];
            if ( !(*(_QWORD *)(v15 + 96) | *(_QWORD *)(v15 + 104) | *(_QWORD *)(v15 + 112) | *(_QWORD *)(v15 + 120) | *(_QWORD *)(v15 + 128)) )
              v22[v1++] = v12;
          }
          ++v12;
          if ( v12 >= 4 )
            break;
          v4 = 1;
        }
      }
      v2 = v23 + 1;
      compile_error();//v17 = __SETO__(v23 + 1, 15);
      v16 = v23++ - 14 < 0;
    }
    while ( v16 ^ v17 );
    if ( v1 )
      goto LABEL_61;
  }
  v18 = 0;
  do
  {
    v19 = (int)pPlayers[v18];
    if ( !(*(_QWORD *)(v19 + 96) | *(_QWORD *)(v19 + 104) | *(_QWORD *)(v19 + 112) | *(_QWORD *)(v19 + 120) | *(_QWORD *)(v19 + 128)) )
      v22[v1++] = v18;
    ++v18;
  }
  while ( v18 < 4 );
  if ( v1 )
LABEL_61:
    result = v22[rand() % v1];
  else
    result = 0;
  return result;
}

//----- (0042704B) --------------------------------------------------------
bool __stdcall sub_42704B(int a1, int a2)
{
  signed int v2; // edi@5
  signed int v3; // ebx@5

  if ( *(_BYTE *)(a1 + 90) == 2 )
  {
    if ( *(_BYTE *)(a1 + 93) < 3u )
    {
      if ( rand() % 100 < 5 )
        sub_44FD29(a1, a2);
    }
  }
  v3 = sub_427102(a1, *(_BYTE *)(a1 + 77));
  v2 = sub_427102(a1, *(_BYTE *)(a1 + 79));
  if ( v3 && *(_BYTE *)(a1 + 76) && rand() % 100 < *(_BYTE *)(a1 + 76) )
    return 2;
  if ( v2 && *(_BYTE *)(a1 + 78) && rand() % 100 < *(_BYTE *)(a1 + 78) )
    return 3;
  return *(_BYTE *)(a1 + 70) && rand() % 100 < *(_BYTE *)(a1 + 70);
}

//----- (00427102) --------------------------------------------------------
signed int __stdcall sub_427102(int a1, signed int a2)
{
  unsigned __int8 v2; // cf@11
  unsigned __int8 v3; // zf@11
  signed int v5; // ecx@46
  signed int v6; // esi@49
  signed int v7; // edx@50
  signed int v8; // ecx@50

  if ( a2 > 73 )
  {
    if ( a2 == 77 )
    {
      if ( (signed int)*(_WORD *)(a1 + 40) >= *(_DWORD *)(a1 + 108) )
        return 0;
      return 1;
    }
    if ( a2 == 80 )
    {
      v5 = (signed int)pParty_global->pPartyBuffs;
      while ( *(_QWORD *)v5 <= 0i64 )
      {
        v5 += 16;
        if ( v5 >= (signed int)&pParty_global->pPlayers[0] )
        {
          v6 = (signed int)&unk_ACF124;
LABEL_50:
          v7 = 0;
          v8 = v6;
          while ( *(_QWORD *)v8 <= 0i64 )
          {
            ++v7;
            v8 += 16;
            if ( v7 >= 24 )
            {
              v6 += 6972;
              if ( v6 < (signed int)&unk_AD5E14 )
                goto LABEL_50;
              return 0;
            }
          }
          return 1;
        }
      }
      return 1;
    }
    if ( a2 == 85 )
    {
      if ( *(_DWORD *)(a1 + 424) < 0 )
        return 1;
      if ( *(_DWORD *)(a1 + 424) > 0 )
        return 0;
      v2 = 0;
      v3 = *(_DWORD *)(a1 + 420) == 0;
    }
    else
    {
      if ( a2 == 86 )
      {
        if ( *(_DWORD *)(a1 + 440) < 0 )
          return 1;
        if ( *(_DWORD *)(a1 + 440) > 0 )
          return 0;
        v2 = 0;
        v3 = *(_DWORD *)(a1 + 436) == 0;
      }
      else
      {
        if ( a2 != 95 || *(_DWORD *)(a1 + 536) < 0 )
          return 1;
        if ( *(_DWORD *)(a1 + 536) > 0 )
          return 0;
        v2 = 0;
        v3 = *(_DWORD *)(a1 + 532) == 0;
      }
    }
  }
  else
  {
    if ( a2 == 73 )
    {
      if ( *(_DWORD *)(a1 + 552) < 0 )
        return 1;
      if ( *(_DWORD *)(a1 + 552) > 0 )
        return 0;
      v2 = 0;
      v3 = *(_DWORD *)(a1 + 548) == 0;
      goto LABEL_15;
    }
    if ( a2 == 5 )
    {
      if ( *(_DWORD *)(a1 + 520) < 0 )
        return 1;
      if ( *(_DWORD *)(a1 + 520) > 0 )
        return 0;
      v2 = 0;
      v3 = *(_DWORD *)(a1 + 516) == 0;
      goto LABEL_15;
    }
    if ( a2 == 17 )
    {
      if ( *(_DWORD *)(a1 + 456) < 0 )
        return 1;
      if ( *(_DWORD *)(a1 + 456) > 0 )
        return 0;
      v2 = 0;
      v3 = *(_DWORD *)(a1 + 452) == 0;
      goto LABEL_15;
    }
    if ( a2 == 38 )
    {
      if ( *(_DWORD *)(a1 + 472) < 0 )
        return 1;
      if ( *(_DWORD *)(a1 + 472) > 0 )
        return 0;
      v2 = 0;
      v3 = *(_DWORD *)(a1 + 468) == 0;
      goto LABEL_15;
    }
    if ( a2 == 46 )
    {
      if ( *(_DWORD *)(a1 + 488) < 0 )
        return 1;
      if ( *(_DWORD *)(a1 + 488) > 0 )
        return 0;
      v2 = 0;
      v3 = *(_DWORD *)(a1 + 484) == 0;
      goto LABEL_15;
    }
    if ( a2 != 47 )
    {
      if ( a2 != 51 || *(_DWORD *)(a1 + 504) < 0 )
        return 1;
      if ( *(_DWORD *)(a1 + 504) <= 0 )
      {
        v2 = 0;
        v3 = *(_DWORD *)(a1 + 500) == 0;
        goto LABEL_15;
      }
      return 0;
    }
    if ( *(_DWORD *)(a1 + 392) < 0 )
      return 1;
    if ( *(_DWORD *)(a1 + 392) > 0 )
      return 0;
    v2 = 0;
    v3 = *(_DWORD *)(a1 + 388) == 0;
  }
LABEL_15:
  if ( !(v2 | v3) )
    return 0;
  return 1;
}

//----- (004272F5) --------------------------------------------------------
signed int __stdcall Player_sub_4272F5(Player *_this, int a2, int a3, int a4)
{
  signed int v4; // edi@1
  signed int v5; // esi@1
  int v6; // esi@8
  int v7; // eax@9
  int v8; // edx@11
  unsigned __int8 v9; // sf@13
  unsigned __int8 v10; // of@13
  int v11; // edx@13
  int v12; // esi@13
  int v13; // eax@14
  int v14; // edx@14
  signed int result; // eax@17

  v5 = *(_DWORD *)(a2 + 112);
  v4 = 0;
  if ( *(_QWORD *)(a2 + 340) > 0i64 )
    v5 /= 2;
  if ( *(_QWORD *)(a2 + 436) > 0i64 )
    v4 = *(_WORD *)(a2 + 460);
  if ( *(_QWORD *)(a2 + 468) > 0i64 )
  {
    if ( *(_WORD *)(a2 + 476) > v4 )
      v4 = *(_WORD *)(a2 + 476);
  }
  v6 = v4 + v5;
  if ( a3 )
    v7 = Player_sub_48D0B9(_this);
  else
    v7 = Player_GetAttackBonus(_this, 0);
  v8 = rand() % (v6 + 2 * v7 + 30);
  if ( a3 == 2 )
  {
    v14 = a4 + v8;
    v13 = ((v6 + 15) >> 1) + v6 + 15;
  }
  else
  {
    if ( a3 != 3 )
    {
      v11 = a4 + v8;
      v12 = v6 + 15;
      compile_error();//v10 = __SETO__(v11, v12);
      v9 = v11 - v12 < 0;
      goto LABEL_16;
    }
    v14 = a4 + v8;
    v13 = 2 * v6 + 30;
  }
  compile_error();//v10 = __SETO__(v14, v13);
  v9 = v14 - v13 < 0;
LABEL_16:
  if ( v9 ^ v10 )
    result = 0;
  else
    result = 1;
  return result;
}

//----- (004273BB) --------------------------------------------------------
bool __stdcall sub_4273BB(int a1, int a2, int a3, int a4)
{
  unsigned __int8 v4; // zf@1
  unsigned __int8 v5; // sf@1
  int v6; // ecx@1
  signed int v7; // ebx@1
  signed int v8; // esi@1
  int v9; // ebx@10
  signed int v11; // [sp+18h] [bp+Ch]@1

  v6 = a2;
  v7 = *(_DWORD *)(a2 + 112);
  v8 = 0;
  v4 = *(_DWORD *)(a2 + 344) == 0;
  v5 = *(_DWORD *)(a2 + 344) < 0;
  v11 = 0;
  if ( !v5 )
  {
    if ( !(v5 | v4) || *(_DWORD *)(v6 + 340) > 0u )
      v7 /= 2;
  }
  if ( *(_QWORD *)(v6 + 436) > 0i64 )
    v8 = *(_WORD *)(v6 + 444);
  if ( *(_QWORD *)(v6 + 468) > 0i64 )
  {
    if ( *(_WORD *)(v6 + 476) > v8 )
      v8 = *(_WORD *)(v6 + 476);
  }
  v9 = v8 + v7;
  if ( *(_QWORD *)(a1 + 436) > 0i64 )
    v11 = *(_WORD *)(a1 + 444);
  if ( *(_QWORD *)(a1 + 484) > 0i64 )
  {
    if ( *(_WORD *)(a1 + 492) > v11 )
      v11 = *(_WORD *)(a1 + 492);
  }
  if ( *(_QWORD *)(a1 + 388) > 0i64 )
  {
    v11 += *(_WORD *)(a1 + 396);
    SpellBuff_sub_458585((SpellBuff *)(a1 + 388));
  }
  return rand() % (v9 + 2 * *(_BYTE *)(a1 + 52) + 10) + v11 + 1 > v9 + 5;
}

//----- (004274AD) --------------------------------------------------------
bool __stdcall sub_4274AD(int a1, int a2)
{
  signed int v2; // edi@1
  signed int v4; // esi@8
  int v5; // esi@8

  v2 = 0;
  if ( *(_QWORD *)(a1 + 436) > 0i64 )
    v2 = *(_WORD *)(a1 + 444);
  if ( *(_QWORD *)(a1 + 484) > 0i64 )
  {
    if ( *(_WORD *)(a1 + 492) > v2 )
      v2 = *(_WORD *)(a1 + 492);
  }
  if ( *(_QWORD *)(a1 + 388) > 0i64 )
  {
    v2 += *(_WORD *)(a1 + 396);
    SpellBuff_sub_458585((SpellBuff *)(a1 + 388));
  }
  v4 = Player_sub_48E68F(a2) + 2 * *(_BYTE *)(a1 + 52) + 10;
  v5 = rand() % v4 + 1;
  return v2 + v5 > Player_sub_48E68F(a2) + 5;
}

//----- (00427546) --------------------------------------------------------
int __stdcall sub_427546(signed int a1)
{
  int result; // eax@2

  if ( a1 >= 0 )
  {
    if ( a1 >= 1 )
      result = (a1 >= 2) + 2;
    else
      result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0042756B) --------------------------------------------------------
signed int __stdcall Actor_sub_42756B(int a1, int a2, signed int a3)
{
  int v3; // edx@1
  int v4; // ecx@1
  signed int v5; // eax@4
  signed int result; // eax@17
  signed int v7; // esi@18

  v3 = 0;
  v4 = 0;
  if ( *(_QWORD *)(a1 + 436) > 0i64 )
    v4 = *(_WORD *)(a1 + 444);
  switch ( a2 )
  {
    case 4:
      v5 = *(_BYTE *)(a1 + 89);
      break;
    case 0:
      v5 = *(_BYTE *)(a1 + 80);
      goto LABEL_12;
    case 1:
      v5 = *(_BYTE *)(a1 + 81);
      goto LABEL_12;
    case 2:
      v5 = *(_BYTE *)(a1 + 82);
      goto LABEL_12;
    case 3:
      v5 = *(_BYTE *)(a1 + 83);
      goto LABEL_12;
    case 6:
      v5 = *(_BYTE *)(a1 + 85);
      break;
    case 7:
      v5 = *(_BYTE *)(a1 + 84);
      goto LABEL_12;
    case 8:
      v5 = *(_BYTE *)(a1 + 86);
LABEL_12:
      v3 = v4;
      break;
    case 9:
      v5 = *(_BYTE *)(a1 + 87);
      break;
    case 10:
      v5 = *(_BYTE *)(a1 + 88);
      break;
    default:
      v5 = 0;
      break;
  }
  if ( v5 < 200 )
  {
    v7 = v3 + v5 + 30;
    if ( rand() % v7 >= 30 )
    {
      a3 >>= 1;
      if ( rand() % v7 >= 30 )
      {
        a3 >>= 1;
        if ( rand() % v7 >= 30 )
        {
          a3 >>= 1;
          if ( rand() % v7 >= 30 )
            a3 >>= 1;
        }
      }
    }
    result = a3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00427662) --------------------------------------------------------
bool __stdcall sub_427662(int a1, int a2)
{
  int v2; // edi@2
  signed int v3; // esi@2
  bool result; // eax@13

  switch ( a2 )
  {
    case 0:
      v2 = a1;
      v3 = *(_BYTE *)(a1 + 80);
      goto LABEL_12;
    case 1:
      v2 = a1;
      v3 = *(_BYTE *)(a1 + 81);
      goto LABEL_12;
    case 2:
      v2 = a1;
      v3 = *(_BYTE *)(a1 + 82);
      goto LABEL_12;
    case 3:
      v2 = a1;
      v3 = *(_BYTE *)(a1 + 83);
      goto LABEL_12;
    case 7:
      v2 = a1;
      v3 = *(_BYTE *)(a1 + 84);
      goto LABEL_12;
    case 6:
      v2 = a1;
      v3 = *(_BYTE *)(a1 + 85);
      goto LABEL_12;
    case 8:
      v2 = a1;
      v3 = *(_BYTE *)(a1 + 86);
      goto LABEL_12;
    case 9:
      v2 = a1;
      v3 = *(_BYTE *)(a1 + 87);
      goto LABEL_12;
    case 10:
      v2 = a1;
      v3 = *(_BYTE *)(a1 + 88);
      goto LABEL_12;
    case 4:
      v2 = a1;
      v3 = *(_BYTE *)(a1 + 89);
LABEL_12:
      if ( v3 < 200 )
        result = rand() % (signed int)(((unsigned int)*(_BYTE *)(v2 + 52) >> 2) + v3 + 30) < 30;
      else
        result = 0;
      break;
    default:
      result = 1;
      break;
  }
  return result;
}

//----- (00427730) --------------------------------------------------------
signed int __thiscall sub_427730(int _this, int a2)
{
  int v2; // eax@1
  signed int result; // eax@2

  v2 = *(_DWORD *)(_this + 6464);
  if ( v2 >= a2 )
  {
    *(_DWORD *)(_this + 6464) = v2 - a2;
    result = 1;
  }
  else
  {
    pAudioPlayer->sub_4AA306(209, 0, 0, -1, 0, 0, 0, 0);
    result = 0;
  }
  return result;
}

//----- (00427769) --------------------------------------------------------
signed int __fastcall sub_427769(int a1)
{
  signed int result; // eax@2

  if ( word_4E3C68[a1].byte13 & 0xC )
    result = 1;
  else
    result = 0;
  return result;
}

//----- (0042777D) -----.text:00427F3B ---------------------------------------------------
int __fastcall sub_42777D_CastSpell(int a1, int a2, int a3, __int16 a4, int a5)
{
  int result; // eax@2
  int *v6; // eax@4
  __int16 v7; // bx@4
  char v8; // zf@12
  __int16 v9; // cx@16
  unsigned __int8 v10; // sf@18
  unsigned __int8 v11; // of@18
  signed int v12; // eax@18
  __int16 v13; // cx@21
  signed int v14; // eax@23
  signed int v15; // esi@27
  signed int v16; // eax@28
  char v17; // zf@34
  int v18; // eax@43
  int v19; // [sp-30h] [bp-48h]@44
  int v20; // [sp-2Ch] [bp-44h]@44
  int v21; // [sp-28h] [bp-40h]@44
  int v22; // [sp-24h] [bp-3Ch]@44
  int v23; // [sp-20h] [bp-38h]@44
  int v24; // [sp-1Ch] [bp-34h]@44
  int v25; // [sp-18h] [bp-30h]@44
  int v26; // [sp-14h] [bp-2Ch]@43
  int v27; // [sp-10h] [bp-28h]@43
  char v28; // [sp-Ch] [bp-24h]@43
  const char *v29; // [sp-8h] [bp-20h]@43
  int v30; // [sp-4h] [bp-1Ch]@43
  __int16 v31; // [sp+10h] [bp-8h]@1
  __int16 v32; // [sp+14h] [bp-4h]@1

  v31 = a2;
  v32 = a1;
  if (!pParty_global->bTurnBasedModeOn || (result = dword_4F885C, dword_4F885C != 1) && dword_4F885C != 3 )
  {
    v7 = a4;
    v6 = (int *)&pParty_global->pPlayers[a2];
    if ( !(a4 & 0x10) )
    {
      switch ( a1 )
      {
        case 47:
        case 68:
        case 89:
          HIBYTE(v7) = HIBYTE(a4) | 1;
          break;
        case 4:
        case 28:
        case 30:
        case 91:
          LOBYTE(v7) = a4 | 0x80;
          break;
        case 2:
        case 6:
        case 11:
        case 18:
        case 20:
        case 24:
        case 26:
        case 29:
        case 32:
        case 34:
        case 35:
        case 37:
        case 39:
        case 44:
        case 52:
        case 57:
        case 60:
        case 65:
        case 70:
        case 76:
        case 78:
        case 79:
        case 87:
        case 90:
        case 92:
        case 93:
        case 97:
          if ( !a5 )
            goto LABEL_9;
          break;
        case 59:
        case 62:
        case 66:
        case 81:
        case 94:
LABEL_9:
          v7 = a4 | 8;
          break;
        case 42:
          v7 = a4 | 0x40;
          break;
        case 46:
          if ( a3 )
            v8 = (a3 & 0x1C0) == 0;
          else
            v8 = (*((_WORD *)v6 + 148) & 0x1C0) == 0;
          if ( v8 )
            goto LABEL_25;
          break;
        case 50:
          v9 = a3;
          if ( !a3 )
            v9 = *((_WORD *)v6 + 148);
          goto LABEL_18;
        case 95:
          v9 = a3;
          if ( !a3 )
            v9 = *((_WORD *)v6 + 152);
LABEL_18:
          v12 = sub_458244_GetSkillMasteryLevel(v9);
          compile_error();//v11 = __SETO__(v12, 3);
          v10 = v12 - 3 < 0;
          goto LABEL_24;
        case 73:
          v13 = a3;
          if ( !a3 )
            v13 = *((_WORD *)v6 + 150);
          v14 = sub_458244_GetSkillMasteryLevel(v13);
          compile_error();//v11 = __SETO__(v14, 4);
          v10 = v14 - 4 < 0;
LABEL_24:
          if ( v10 ^ v11 )
            goto LABEL_25;
          break;
        case 40:
        case 49:
        case 53:
        case 55:
        case 56:
        case 61:
        case 64:
        case 67:
        case 71:
        case 72:
        case 74:
LABEL_25:
          v7 = a4 | 2;
          break;
        case 96:
          HIBYTE(v7) = HIBYTE(a4) | 2;
          break;
        default:
          break;
      }
    }
    v15 = (int)&struct_50C0C8;
    if ( v7 & 0x3CA )
    {
      v16 = (int)&struct_50C0C8;
      while ( !(*(_WORD *)(v16 + 8) & 0x3CA) )
      {
        v16 += 20;
        if ( v16 >= (signed int)&unk_50C190 )
          goto LABEL_33;
      }
      *(_WORD *)v16 = 0;
    }
    do
    {
LABEL_33:
      if ( *(_WORD *)v15 )
      {
        v17 = (*(_WORD *)(v15 + 8) & 0x3CA) == 0;
        *(_WORD *)v15 = 0;
        if ( !v17 )
        {
          GUIWindowDelete(ptr_507BD4);
          ptr_507BD4 = NULL;
          GUICursor_SetCursorBitmap(pGame->pGUICursor, "MICON1");
          dword_5C35B8_Some_GetTickCount_timer = 0;
          dword_50C9A0 = false;
          sub_4356FF();
        }
      }
      v15 += 20;
    }
    while ( v15 < (signed int)&unk_50C190 );
    result = sub_427DA0(&struct_50C0C8, v32, v31, a3, v7, a5);
    if ( result != -1 )
    {
      if ( v7 & 2 )
      {
        if ( ptr_507BD4 )
          return result;
        ptr_507BD4 = GUIWindowCreate(0, 0, 640, 480, 27, (GUIButton*)(20 * result + 5292232), 0);
        GUIButtonCreate(ptr_507BD4,  52, 422, 35, 0, 2, 0, 69, 0, 49, NULL, 0);
        GUIButtonCreate(ptr_507BD4, 165, 422, 35, 0, 2, 0, 69, 1, 50, NULL, 0);
        GUIButtonCreate(ptr_507BD4, 280, 422, 35, 0, 2, 0, 69, 2, 51, NULL, 0);
        GUIButtonCreate(ptr_507BD4, 390, 422, 35, 0, 2, 0, 69, 3, 52, NULL, 0);
        return sub_421B2C_DropPickedItem();
      }
      if ( v7 & 8 )
      {
        if ( ptr_507BD4 )
          return result;
        ptr_507BD4 = GUIWindowCreate(0, 0, 640, 480, 27, (GUIButton*)(20 * result + 5292232), 0);
        v30 = 0;
        v29 = "";
        v28 = 0;
        v27 = 0;
        v26 = 70;
LABEL_44:
        v25 = 0;
        v24 = 1;
        v23 = 344;
        v22 = 460;
        v21 = 8;
        v20 = 8;
       // ptr_507BD4 = v18;
     //   v19 = v18;
LABEL_56:
        GUIButtonCreate(ptr_507BD4, v20, v21, v22, v23, v24, v25, v26, v27, v28, (unsigned char *)v29, 0);
	//	  GUIButtonCreate(ptr_507BD4,       390, 422,  35,   0,   2,  1,  0,   70,  0,   0, NULL, 0);
        return sub_421B2C_DropPickedItem();
      }
      if ( v7 & 0x40 )
      {
        if ( ptr_507BD4 )
          return result;
        v18 = (int)GUIWindowCreate(0, 0, 640, 480, 27, (GUIButton*)(20 * result + 5292232), 0);
        v30 = 0;
        v29 = "";
        v28 = 0;
        v27 = 0;
        v26 = 190;
        goto LABEL_44;
      }
      if ( (_BYTE)v7 < 0 )
      {
        if ( ptr_507BD4 )
          return result;
        ++LODFile_Icons_LOD.uTexturePacksCount;
        if ( !LODFile_Icons_LOD.uPrevLoadedFiles )
          LODFile_Icons_LOD.uPrevLoadedFiles = LODFile_Icons_LOD.uNumLoadedFiles;
        ptr_507BD4 = (GUI::Window *)sub_4219BE((void *)(20 * result + 5292232));
        dword_50C9A0 = true;
        dword_50C0C4 = uActiveCharacter;
        return sub_421B2C_DropPickedItem();
      }
      if ( HIBYTE(v7) & 1 )
      {
        if ( ptr_507BD4 )
          return result;
        ptr_507BD4 = GUIWindowCreate(0, 0, 640, 480, 27, (GUIButton*)(20 * result + 5292232), 0);
        GUIButtonCreate(ptr_507BD4, 52, 422, 35, 0, 2, 0, 141, 0, 49, NULL, 0);
        GUIButtonCreate(ptr_507BD4, 165, 422, 35, 0, 2, 0, 141, 1, 50, NULL, 0);
        GUIButtonCreate(ptr_507BD4, 280, 422, 35, 0, 2, 0, 141, 2, 51, NULL, 0);
        GUIButtonCreate(ptr_507BD4, 390, 422, 35, 0, 2, 0, 141, 3, 52, NULL, 0);
        v30 = 0;
        v29 = "";
        v28 = 0;
        v27 = 0;
        v26 = 140;
        v25 = 0;
        v24 = 1;
        v23 = 344;
        v22 = 460;
        v21 = 8;
        v20 = 8;
       // v19 = ptr_507BD4;
        goto LABEL_56;
      }
      if ( HIBYTE(v7) & 2 )
      {
        if ( !ptr_507BD4 )
        {
          ptr_507BD4 = GUIWindowCreate(0, 0, 640, 480, 27, (GUIButton*)(20 * result + 5292232), 0);
          pBtn_Game_NPCScrollLeftDown = GUIButtonCreate(
                           ptr_507BD4,
                           469,
                           178,
						   (uTextureIdx_ib_npcld_a != -1 ? LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_npcld_a].uTextureWidth : 24),
                           (uTextureIdx_ib_npcld_a != -1 ? LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_npcld_a].uTextureHeight: 26),
                           1,
                           0,
                           188,
                           0,
                           0,
                           NULL,
                           uTextureIdx_ib_npcld_a != -1 ?  &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_npcld_a] : 0);
          pBtn_Game_NPCScrollRightDown = GUIButtonCreate(
                           ptr_507BD4,
                           626,
                           178,
                           (uTextureIdx_ib_npcrd_a != -1 ? LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_npcrd_a].uTextureWidth : 24),
                           (uTextureIdx_ib_npcrd_a != -1 ? LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_npcrd_a].uTextureHeight: 26),
                           1,
                           0,
                           188,
                           1,
                           0,
                           NULL,
                           uTextureIdx_ib_npcrd_a != -1 ? &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_npcrd_a] : 0);
          GUIButtonCreate(ptr_507BD4, 491, 149, 64, 74, 1, 0, 143, 4, 53, NULL, 0);
          result = (int)GUIButtonCreate(ptr_507BD4, 561, 149, 64, 74, 1, 0, 143, 5, 54, NULL, 0);
        }
      }
    }
  }
  return result;
}

//----- (00427D48) --------------------------------------------------------
void sub_427D48_MessWith_unnamed_50C0C8(struct unnamed_50C0C8 *_this, int a2)
{
 for (unsigned int i = 0; i < 10; ++i)
 {
  if (!_this->array_000000[i].word_000000)
    continue;

  if (_this->array_000000[i].word_000008 & 0x03CA)
  {
   _this->array_000000[i].word_000000 = 0;

   GUIWindowDelete(ptr_507BD4);
   ptr_507BD4 = 0;

   GUICursor_SetCursorBitmap(pGame->pGUICursor, "MICON1");
   dword_5C35B8_Some_GetTickCount_timer = 0;
   dword_50C9A0 = false;
   sub_4356FF();
  }
 }
}

//----- (00427DA0) --------------------------------------------------------
signed int __thiscall sub_427DA0(void *_this, __int16 a2, __int16 a3, __int16 a4, __int16 a5, int a6)
{
  signed int result; // eax@1
  void *v7; // edx@1
  int v8; // ecx@5

  result = 0;
  v7 = _this;
  while ( *(_WORD *)v7 )
  {
    ++result;
    v7 = (char *)v7 + 20;
    if ( result >= 10 )
      goto LABEL_8;
  }
  v8 = (int)((char *)_this + 20 * result);
  *(_WORD *)v8 = a2;
  *(_WORD *)(v8 + 2) = a3;
  if ( a5 & 0x10 )
    *(_WORD *)(v8 + 4) = a3;
  *(_WORD *)(v8 + 6) = 0;
  *(_DWORD *)(v8 + 12) = 0;
  *(_WORD *)(v8 + 8) = a5;
  *(_WORD *)(v8 + 10) = a4;
  *(_DWORD *)(v8 + 16) = a6;
LABEL_8:
  if ( result == 10 )
    result = -1;
  return result;
}

//----- (0042EB25) --------------------------------------------------------
void ItemGen_Reset_Dummy(ItemGen *_this)
{
 ItemGen_Reset(_this);
}

//----- (0042EB31) --------------------------------------------------------
signed int __thiscall sub_42EB31(void *_this)
{
  signed int result; // eax@1

  result = 0;
  if ( *(_QWORD *)_this > 0i64 )
    result = 1;
  return result;
}

//----- (0042EB42) --------------------------------------------------------
__int16 __thiscall ObjectDescriptionList_sub_42EB42(int _this, __int16 a2)
{
  int v2; // eax@1
  int v3; // edx@1
  int v4; // ecx@2

  v3 = *(_DWORD *)_this;
  v2 = 0;
  if ( *(_DWORD *)_this <= 0 )
  {
LABEL_5:
    LOWORD(v2) = 0;
  }
  else
  {
    v4 = *(_DWORD *)(_this + 4) + 32;
    while ( a2 != *(_WORD *)v4 )
    {
      ++v2;
      v4 += 56;
      if ( v2 >= v3 )
        goto LABEL_5;
    }
  }
  return v2;
}

//----- (0042EB6A) --------------------------------------------------------
int __thiscall Game_sub_42EB6A(int _this)
{
  return *(_DWORD *)(_this + 3664);
}

//----- (0042EB71) --------------------------------------------------------
int __thiscall Game_sub_42EB71(int _this)
{
  return *(_DWORD *)(_this + 3668);
}

//----- (0042EB78) --------------------------------------------------------
int __thiscall IconFrameTable_sub_42EB78(int _this, int a2)
{
  return 8 * *(_WORD *)(32 * a2 + *(_DWORD *)(_this + 4) + 26);
}



//----- (0042EBBE) --------------------------------------------------------
int __fastcall sub_42EBBE(int a1, int a2)
{
  return (unsigned __int64)(a2 * a1) >> 16;
}

//----- (0042EBDB) --------------------------------------------------------
int __thiscall class59_sub_42EBDB(int _this, int a2)
{
  return class59_SinCos((class59 *)_this, a2 - *(_DWORD *)(_this + 6244));
}

//----- (0042EBEE) --------------------------------------------------------
signed int __thiscall sub_42EBEE(void *_this)
{
  signed int result; // eax@1
  void *v2; // edi@1
  int v3; // esi@1
  signed int v4; // eax@2
  int v5; // ebx@2
  _UNKNOWN *v6; // esi@4
  int v7; // [sp+8h] [bp-4h]@1
  int v8; // [sp+8h] [bp-4h]@6

  v3 = uActiveCharacter;
  v7 = (int)_this;
  v2 = &pParty_global->pPlayers[uActiveCharacter - 1];
  result = Player_sub_492C0B_MaybeIfPlayerConscious(&pParty_global->pPlayers[uActiveCharacter - 1]);
  if ( result )
  {
    sub_427D48_MessWith_unnamed_50C0C8(&struct_50C0C8, v3);
    v5 = 0;
    compile_error(level file name should not be global);
    //v4 = CMapStats_FindLocation(pMapStats, CurrentLevelName);
    if ( v4 )
      v5 = pMapStats->pMapInfos[v4].dword_000024;
    v6 = &unk_6A12B8;
    if ( uCurrentlyLoadedLevelType != 2 )
      v6 = &unk_6BE68C;
    compile_error();//sub_48D88B((int)v2, v7, v5, *((_DWORD *)v6 + 2)++);
    v8 = Player_sub_GetAttackRecoveryTime((Player *)v2, 0);
    if ( v8 < 30 )
      v8 = 30;
    if (!pParty_global->bTurnBasedModeOn)
      Player_SetRecoveryTime((Player *)v2, (signed __int64)(flt_6BE3A4_debug_recmod1 * (double)v8 * 2.1333333333333333));
    sub_40471C(&unk_4F8858);
    result = 1;
  }
  return result;
}

//----- (0042ECB5) --------------------------------------------------------
bool sub_42ECB5_PlayerAttack()
{
  int v1; // ebx@1
  //int v2; // esi@1
  //int v3; // edi@2
  int v4; // eax@7
  //int v5; // eax@8
  int v6; // ecx@9
  signed int v7; // eax@16
  char *v8; // edi@20
  int v9; // ecx@21
  //int v10; // eax@26
  //int v11; // eax@26
  //int v12; // eax@47
  int v13; // eax@47
  //int v14; // eax@47
  int v15; // ebx@54
  int v16; // [sp-10h] [bp-4Ch]@24
  int v17; // [sp-10h] [bp-4Ch]@44
  int v18; // [sp-Ch] [bp-48h]@24
  int v19; // [sp-Ch] [bp-48h]@44
  __int16 v20; // [sp-8h] [bp-44h]@24
  __int16 v21; // [sp-8h] [bp-44h]@44
  int v22; // [sp-4h] [bp-40h]@24
  int v23; // [sp-4h] [bp-40h]@44
  int v24; // [sp-4h] [bp-40h]@58
  int v25; // [sp+Ch] [bp-30h]@19
  int v26; // [sp+10h] [bp-2Ch]@19
  int v27; // [sp+14h] [bp-28h]@19
  int v28; // [sp+18h] [bp-24h]@20
  int v29; // [sp+1Ch] [bp-20h]@1
  int v30; // [sp+20h] [bp-1Ch]@9
  int v31; // [sp+24h] [bp-18h]@16
  int v32; // [sp+28h] [bp-14h]@16
  int v33; // [sp+2Ch] [bp-10h]@4
  int v34; // [sp+30h] [bp-Ch]@7
  int v35; // [sp+34h] [bp-8h]@7
  int v36; // [sp+38h] [bp-4h]@17

  v1 = uActiveCharacter;
  v29 = 6972 * uActiveCharacter;
 Player *pPlayer = &pParty_global->pPlayers[uActiveCharacter - 1];

 if (!Player_sub_492C0B_MaybeIfPlayerConscious(pPlayer))
   return false;


 sub_427D48_MessWith_unnamed_50C0C8(&struct_50C0C8, uActiveCharacter);

    if (pParty_global->pPartyBuffs[11].qword_000000 > 0 )
      SpellBuff_sub_458585(&pParty_global->pPartyBuffs[11]);

 v33 = pPlayer->pEquippedItemIndices[2];
    //v33 = *(_DWORD *)(v2 + 6480);

 if (v33 != -1)
 {
  //if ( *(_BYTE *)(v2 + 36 * v33 + 516) & 2 )
  if (pPlayer->pInventorySlots[v33].dword_000014 & 0x02)
    v33 = -1;
 }

 v4 = pPlayer->pEquippedItemIndices[1];
     //v4 = *(_DWORD *)(v2 + 6476);

    v34 = -1;
    v35 = -1;
    if ( v4 )
    {
      //v5 = (int)pPlayer + 36 * v4;
      if (~pPlayer->pInventorySlots[v4].dword_000014 & 0x02)
      {
        //v30 = v5 + 496;
        v6 = pPlayer->pInventorySlots[v4].uItemID;
        if (pClass40->pItems[v6].uEquipType == 12 )
        {
         if (pPlayer->pInventorySlots[v4].dword_000010 <= 0)
         {
          pPlayer->pInventorySlots[v4].uItemID = -1;
          pPlayer->pEquippedItemIndices[1] = -1;
         }
          else
            v34 = pPlayer->pInventorySlots[v4].uItemID;
        }
        else
        {
          if ( v6 == 63 || v6 == 64 ) // blasters
            v35 = pPlayer->pInventorySlots[v4].uItemID;
        }
      }
    }





    v32 = 0;
    v31 = 0;
    v30 = 0;
    v7 = pGame->pGUICursor->dword_000000;
    if ( (v7 & 7) != 3 ||
        (v36 = pGame->pGUICursor->dword_000000, !Actor_sub_40894B(&pActors[(v7 >> 3)])) )
      v36 = sub_42F184(&unk_50C198, 0x1400u, 0, 0);
    v27 = 0;
    v26 = 0;
    v25 = 0;
    if ( (v36 & 7) == 3 )
    {
      v28 = v36 >> 3;
      v8 = (char *)pActors + 836 * (v36 >> 3);
      v36 = sub_452A9E((*((_WORD *)v8 + 71) - pParty_global->sPartyPosX) * (*((_WORD *)v8 + 71) - pParty_global->sPartyPosX) + (*((_WORD *)v8 + 72) - pParty_global->sPartyPosY) * (*((_WORD *)v8 + 72) - pParty_global->sPartyPosY) + (*((_WORD *)v8 + 73) - pParty_global->sPartyPosZ) * (*((_WORD *)v8 + 73) - pParty_global->sPartyPosZ))
          - *((_WORD *)v8 + 68);
      if ( v36 >= 0 )
      {
        v9 = 0;
      }
      else
      {
        v9 = 0;
        v36 = 0;
      }
      if ( v35 != v9 )
      {
        v30 = 1;
        v22 = v1 + 8;
        v20 = v9;
        v18 = v9;
        v16 = 102;
LABEL_34:
        sub_42777D_CastSpell(v16, v1 - 1, v18, v20, v22);
LABEL_28:
        goto LABEL_29;
      }
      if ( v34 != v9 )
      {
        v31 = 1;
        sub_42777D_CastSpell(
          dword_4E421C[*(int *)((char *)&dword_ACC038[9 * *(int *)((char *)&dword_ACD794 + v29)] + v29)],
          v1 - 1,
          8,
          v9,
          v1 + 8);

        runtime_warning(suspicious);
        if (--pPlayer->pInventorySlots[pPlayer->pEquippedItemIndices[1] + 1].uItemID == -1)
        {
         pPlayer->pInventorySlots[pPlayer->pEquippedItemIndices[1]].uItemID = -1;
         pPlayer->pEquippedItemIndices[1] = -1;
        }

        goto LABEL_28;
      }
      if ( (double)v36 <= 407.19999999999999 )
      {
        v25 = *((_WORD *)v8 + 71) - pParty_global->sPartyPosX;
        v26 = *((_WORD *)v8 + 72) - pParty_global->sPartyPosY;
        v27 = *((_WORD *)v8 + 73) - pParty_global->sPartyPosZ;
        sub_43AB61((int)&v25, (int)&v26, (int)&v27);
        DamageMonsterFromParty((8 * v1 - 8) | 4, v28, (int)&v25);
        if ( Player_sub_48D709(pPlayer, 506, 1) || Player_sub_48D709(pPlayer, 506, 0) )
          sub_42FA66(
            *((_WORD *)v8 + 71),
            *((_WORD *)v8 + 72),
            *((_WORD *)v8 + 73) + *((_WORD *)v8 + 69) / 2,
            0,
            512,
            v1);
      }
      else
      {
        if ( v33 != v9 )
        {
          v32 = 1;
          v22 = 0;
          v20 = 0;
          v18 = 0;
          v16 = 100;
          goto LABEL_34;
        }
      }
      goto LABEL_39;
    }
    if ( v35 )
    {
      v30 = 1;
      v23 = v1 + 8;
      v21 = 0;
      v19 = 0;
      v17 = 102;
    }
    else
    {
      if ( v34 )
      {
        v13 = pPlayer->pEquippedItemIndices[1];
        v31 = 1;
        sub_42777D_CastSpell(dword_4E421C[pPlayer->pInventorySlots[v13].uItemID], v1 - 1, 8, 0, v1 + 8);

        //v14 = v2 + 36 * pPlayer->pEquippedItemIndices[1] + 512;
        //--*(_DWORD *)v14;
        //v12 = v2 + 36 * pPlayer->pEquippedItemIndices[1];
        //if (*(_DWORD *)(v12 + 512) == 0)
        if (--pPlayer->pInventorySlots[pPlayer->pEquippedItemIndices[1] + 1].uItemID == -1)
        {
         pPlayer->pInventorySlots[pPlayer->pEquippedItemIndices[1] + 1].uItemID = -1;
         pPlayer->pEquippedItemIndices[1] = -1;
        }
LABEL_29:
        v36 = 0;
        if ( v32 == 0 )
        {
          if ( v31 != 0 )
            return 1;
          if ( v30 == 0 )
          {
            v15 = pPlayer->pEquippedItemIndices[1];
            if ( Player_sub_48D6AA(pPlayer, 1) )
             v36 = pClass40->pItems[pPlayer->pInventorySlots[pPlayer->pEquippedItemIndices[1]].uItemID].uSkillType;
            sub_40471C(&unk_4F8858);
          }
          else
          {
            v36 = 7;
          }
        }
        else
        {
          v36 = 5;
          Player_PlaySound(pPlayer, 50, 0);
        }
        switch ( v36 )
        {
          case 0:
            v24 = 81;
            goto LABEL_66;
          case 1:
            v24 = 84;
            goto LABEL_66;
          case 2:
            v24 = 85;
            goto LABEL_66;
          case 3:
            v24 = 78;
            goto LABEL_66;
          case 4:
            v24 = 80;
            goto LABEL_66;
          case 5:
            v24 = 71;
            goto LABEL_66;
          case 6:
            v24 = 83;
            goto LABEL_66;
          case 7:
            v24 = 67;
LABEL_66:
            pAudioPlayer->sub_4AA306(v24, 0, 0, -1, 0, 0, 0, 0);
            break;
          default:
            return 1;
        }
        return 1;
      }
      if ( !v33 )
      {
LABEL_39:
        v33 = Player_sub_GetAttackRecoveryTime(pPlayer, 0);
        if ( v33 < 30 )
          v33 = 30;
        if (!pParty_global->bTurnBasedModeOn)
          Player_SetRecoveryTime(pPlayer, (signed __int64)(flt_6BE3A4_debug_recmod1 * (double)v33 * 2.1333333333333333));
        goto LABEL_29;
      }
      v23 = 0;
      v21 = 0;
      v19 = 0;
      v32 = 1;
      v17 = 100;
    }
    sub_42777D_CastSpell(v17, v1 - 1, v19, v21, v23);
    goto LABEL_29;
}

//----- (0042F184) --------------------------------------------------------
unsigned int sub_42F184(void *_this, unsigned int a2, int a3, int a4)
{
  int v4; // edi@1
  //void *v5; // esi@1
  int v6; // eax@2
  //signed int v7; // eax@4
  int result; // eax@5
  int v9; // edx@8
  int v10; // ebx@10
  int v11; // edi@11
  __int16 v12; // ax@12
  char *v13; // esi@12
  int v14; // eax@22
  char v16; // zf@30
  int v17; // esi@32
  int v18; // ecx@34
  void *v19; // eax@39
  int v20; // edx@39
  int v21; // ecx@41
  __int16 v22; // ax@42
  int v23; // [sp+8h] [bp-24h]@11
  int v24; // [sp+Ch] [bp-20h]@7
  //void *v25; // [sp+10h] [bp-1Ch]@1
  int v26; // [sp+14h] [bp-18h]@8
  int v27; // [sp+18h] [bp-14h]@8
  int v28; // [sp+1Ch] [bp-10h]@10
  int v29; // [sp+20h] [bp-Ch]@10
  int v30; // [sp+24h] [bp-8h]@7
  int v31; // [sp+28h] [bp-4h]@6
  int i; // [sp+38h] [bp+Ch]@33
  signed int v33; // [sp+3Ch] [bp+10h]@32

  v4 = 0;
  //v5 = _this;
  //v25 = _this;
  if (pD3DRenderer->pRenderD3D3)
  {
    v6 = a3 != 0;
    if ( a4 )
      LOBYTE(v6) = v6 | 8;
    return (unsigned __int16)Vis_sub_4C1944(pGame->pVis, 3, a2, v6, 657456, -1);
  }
  
  /*else  //software render
  {
    v31 = 0;
    if ( pD3DRenderer->pActiveZBuffer )
    {
     v30 = struct_576FE8.dword_000010;
     v24 = struct_576FE8.dword_000018;
     if (struct_576FE8.dword_000014 < struct_576FE8.dword_00001C)
      {
       v26 = struct_576FE8.dword_00001C - struct_576FE8.dword_000014;
        v9 = (int)(pD3DRenderer->pActiveZBuffer + 4 * (struct_576FE8.dword_000010 + 640 * struct_576FE8.dword_000014));
        v27 = (int)(pD3DRenderer->pActiveZBuffer + 4 * (struct_576FE8.dword_000010 + 640 * struct_576FE8.dword_000014));
        do
        {
          if ( v30 < v24 )
          {
            v29 = v9;
            v10 = 4 * v4;
            v28 = v24 - v30;
            do
            {
              v23 = *(_DWORD *)v29;
              v11 = *(_DWORD *)v29 & 0xFFFF;
              if ( (*(_BYTE *)v29 & 7) == 3 )
              {
                v13 = (char *)pActors + 836 * ((unsigned int)v11 >> 3);
                v12 = *((_WORD *)v13 + 88);
                if ( v12 != 5 )
                {
                  if ( v12 != 4 )
                  {
                    if ( v12 != 11 )
                    {
                      if ( v12 != 19 )
                      {
                        if ( v12 != 17 )
                        {
                          if ( !a3 || Actor_GetActorsRelation(&pActors[((unsigned int)v11 >> 3)], 0))
                          {
                            if ( !a4 || sub_438BDF(*((_WORD *)v13 + 48), 1) )
                            {
                              if ( v23 <= a2 << 16 )
                              {
                                v14 = 0;
                                if ( v10 > 0 )
                                {
                                  do
                                  {
                                    if ( dword_50BDA0[v14] == v11 )
                                      break;
                                    ++v14;
                                  }
                                  while ( v14 < v31 );
                                }
                                if ( v14 == v31 )
                                {
                                  if ( v10 < 400 )
                                  {
                                    ++v31;
                                    *(int *)((char *)dword_50BC10 + v10) = v23;
                                    *(int *)((char *)dword_50BDA0 + v10) = v11;
                                    v10 += 4;
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
              v29 += 4;
            }
            while ( v28-- != 1 );
            v4 = v31;
            v5 = v25;
          }
          v9 = v27 + 2560;
          v16 = v26-- == 1;
          v27 += 2560;
        }
        while ( !v16 );
      }
      if ( v4 > 0 )
      {
        v33 = 1;
        v17 = (int)dword_50BC10;
        do
        {
          for ( i = v33; i < v4; ++i )
          {
            v18 = dword_50BC10[i];
            if ( v18 < *(_DWORD *)v17 )
            {
              dword_50BC10[i] = *(_DWORD *)v17;
              *(_DWORD *)v17 = v18;
            }
          }
          ++v33;
          v17 += 4;
        }
        while ( v33 - 1 < v4 );
        v5 = v25;
        if ( v4 > 0 )
        {
          v19 = v25;
          v20 = v4;
          do
          {
            compile_error();//*(_DWORD *)v19 = (*(_DWORD *)((char *)v19 + (char *)dword_50BC10 - v25) >> 3) & 0x1FFF;
            v19 = (char *)v19 + 4;
            --v20;
          }
          while ( v20 );
        }
      }
      v21 = 0;
      for ( *((_DWORD *)v5 + 500) = v4; v21 < v4; ++v21 )
      {
        v22 = pActors[*((_DWORD *)v5 + v21)].word_0000B0_state;
        if ( v22 != 4 && v22 != 5 )
          break;
      }
      if ( v21 != v4 )
      {
        result = 8 * *((_DWORD *)v5 + v21);
        LOBYTE(result) = result | 3;
        return result;
      }
    }
  }*/
  return 0;
}

//----- (0042F3D6) --------------------------------------------------------
void __cdecl sub_42F3D6()
{
 char pIconName[16];
 int  i;

 for (i = 0; i < 5; ++i)
 {
  wsprintfA(pIconName, "turn%u", i);
  dword_50C96C[i] = pIconFrameTable->FindAnimation(pIconName);
  pIconFrameTable->InitializeAnimation(dword_50C96C[i]);
 }

 dword_50C980 = pIconFrameTable->FindAnimation("turnstop");
 pIconFrameTable->InitializeAnimation(dword_50C980);

 dword_50C984 = pIconFrameTable->FindAnimation("turnhour");
 pIconFrameTable->InitializeAnimation(dword_50C984);

 uIconTableFrameID_CharacterFrame = pIconFrameTable->FindAnimation("aframe1");
 pIconFrameTable->InitializeAnimation(uIconTableFrameID_CharacterFrame);

 dword_50C990 = pIconFrameTable->FindAnimation("turnstart");
 pIconFrameTable->InitializeAnimation(dword_50C990);

 dword_50C99C = SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell11");
}

//----- (0042F4DA) --------------------------------------------------------
signed int __cdecl sub_42F4DA()
{
  signed int v0; // edi@1
  int v1; // esi@4
  int v2; // eax@5
  unsigned int v3; // ecx@5
  int v4; // ebx@5
  int v5; // ebx@5
  int v6; // edx@6
  unsigned int v7; // edx@8
  unsigned int v8; // edx@10
  __int16 v9; // ax@12
  signed int result; // eax@20
  int v11; // [sp+Ch] [bp-10h]@5
  int v12; // [sp+10h] [bp-Ch]@5
  signed int v13; // [sp+14h] [bp-8h]@3

  v0 = 5120;
  if ( uCurrentlyLoadedLevelType == 1 )
    v0 = 2560;
  v13 = 0;
  if ( (signed int)uNumActors <= 0 )
  {
LABEL_20:
    result = 0;
  }
  else
  {
    v1 = (int)&pActors[0].word_0000B0_state;
    while ( 1 )
    {
      v5 = abs(*(_WORD *)(v1 - 34) - pParty_global->sPartyPosX);
      v11 = abs(*(_WORD *)(v1 - 32) - pParty_global->sPartyPosY);
      v12 = abs(*(_WORD *)(v1 - 30) - pParty_global->sPartyPosZ);
      v2 = v5;
      v4 = v11;
      v3 = v12;
      if ( v2 < v11 )
      {
        v6 = v2;
        v2 = v11;
        v4 = v6;
      }
      if ( v2 < v12 )
      {
        v7 = v2;
        v2 = v12;
        v3 = v7;
      }
      if ( v4 < (signed int)v3 )
      {
        v8 = v3;
        v3 = v4;
        v4 = v8;
      }
      if ( (signed int)(((unsigned int)(11 * v4) >> 5) + (v3 >> 2) + v2) < v0 )
      {
        v9 = *(_WORD *)v1;
        if ( *(_WORD *)v1 != 5 )
        {
          if ( v9 != 4 && v9 != 11 && v9 != 19 && v9 != 17 && (*(_BYTE *)(v1 - 138) & 8 || Actor_GetActorsRelation(0, (Actor *)(v1 - 176))) )
            break;
        }
      }
      ++v13;
      v1 += 836;
      if ( v13 >= (signed int)uNumActors )
        goto LABEL_20;
    }
    result = 1;
  }
  return result;
}

//----- (0042F5ED) --------------------------------------------------------
signed int __fastcall sub_42F5ED(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // eax@1
  signed int v6; // ecx@2
  signed int v7; // ebx@2
  signed int result; // eax@6
  char *v9; // ebx@7
  int v10; // edx@11
  __int16 v11; // ax@18
  int v12; // edi@18
  int v13; // ST2C_4@20
  int v14; // [sp-28h] [bp-38h]@14
  int v15; // [sp-24h] [bp-34h]@11
  int v16; // [sp-20h] [bp-30h]@11
  int v17; // [sp-1Ch] [bp-2Ch]@11
  int v18; // [sp-18h] [bp-28h]@11
  int v19; // [sp-14h] [bp-24h]@11
  int v20; // [sp-10h] [bp-20h]@11
  int v21; // [sp-Ch] [bp-1Ch]@11
  signed int v22; // [sp+8h] [bp-8h]@2
  int v23; // [sp+Ch] [bp-4h]@1
  int v24; // [sp+1Ch] [bp+Ch]@20
  int v25; // [sp+1Ch] [bp+Ch]@20
  int v26; // [sp+1Ch] [bp+Ch]@20
  int v27; // [sp+20h] [bp+10h]@20

  v23 = a2;
  v5 = a1;
  if ( !*(_WORD *)(a1 + 2) )
    return -1;
  v7 = 0;
  v6 = (int)&pLayingItemsList[0].uObjectDescriptionID;
  v22 = 0;
  do
  {
    if ( !*(_WORD *)v6 )
      break;
    v6 += 112;
    ++v7;
    v22 = v7;
  }
  while ( v6 < 6817714 );
  if ( v7 >= 1000 )
    return -1;
  *(_DWORD *)(v5 + 100) = *(_DWORD *)(v5 + 4);
  *(_DWORD *)(v5 + 104) = *(_DWORD *)(v5 + 8);
  v9 = (char *)&pLayingItemsList[v7];
  *(_DWORD *)(v5 + 108) = *(_DWORD *)(v5 + 12);
  memcpy(v9, (const void *)v5, 0x70u);
  if ( a5 == 1 )
  {
    v21 = (int)(v9 + 12);
    v20 = (int)(v9 + 8);
    v19 = (int)(v9 + 4);
    v18 = *(_DWORD *)(v5 + 12);
    v17 = *(_DWORD *)(v5 + 8);
    v16 = *(_DWORD *)(v5 + 4);
    v15 = 0;
    v10 = pClass59_global->uIntegerHalfPi + *((_WORD *)v9 + 11);
    goto LABEL_16;
  }
  if ( a5 == 2 )
  {
    v21 = (int)(v9 + 12);
    v20 = (int)(v9 + 8);
    v19 = (int)(v9 + 4);
    v18 = *(_DWORD *)(v5 + 12);
    v17 = *(_DWORD *)(v5 + 8);
    v16 = *(_DWORD *)(v5 + 4);
    v15 = 0;
    v10 = pClass59_global->uIntegerHalfPi + *((_WORD *)v9 + 11);
    goto LABEL_14;
  }
  if ( a5 == 3 )
  {
    v21 = (int)(v9 + 12);
    v20 = (int)(v9 + 8);
    v19 = (int)(v9 + 4);
    v18 = *(_DWORD *)(v5 + 12);
    v17 = *(_DWORD *)(v5 + 8);
    v16 = *(_DWORD *)(v5 + 4);
    v15 = 0;
    v10 = *((_WORD *)v9 + 11) - pClass59_global->uIntegerHalfPi;
LABEL_14:
    v14 = 8;
LABEL_17:
    sub_43AA99(v14, v10, v15, v16, v17, v18, v19, v20, v21);
    goto LABEL_18;
  }
  if ( a5 == 4 )
  {
    v21 = (int)(v9 + 12);
    v20 = (int)(v9 + 8);
    v19 = (int)(v9 + 4);
    v18 = *(_DWORD *)(v5 + 12);
    v17 = *(_DWORD *)(v5 + 8);
    v16 = *(_DWORD *)(v5 + 4);
    v15 = 0;
    v10 = *((_WORD *)v9 + 11) - pClass59_global->uIntegerHalfPi;
LABEL_16:
    v14 = 24;
    goto LABEL_17;
  }
LABEL_18:
  v12 = a4;
  v11 = 0;
  if ( a4 )
  {
    v24 = class59_SinCos(pClass59_global, v23);
    v13 = (unsigned __int64)(v24 * class59_SinCos(pClass59_global, a3)) >> 16;
    v25 = class59_SinCos(pClass59_global, v23 - pClass59_global->uIntegerHalfPi);
    v27 = (unsigned __int64)(v25 * class59_SinCos(pClass59_global, a3)) >> 16;
    v26 = class59_SinCos(pClass59_global, a3 - pClass59_global->uIntegerHalfPi);
    *((_WORD *)v9 + 8) = (unsigned int)(v13 * v12) >> 16;
    *((_WORD *)v9 + 9) = (unsigned int)(v27 * v12) >> 16;
    v11 = (unsigned int)(v26 * v12) >> 16;
  }
  else
  {
    *((_WORD *)v9 + 9) = 0;
    *((_WORD *)v9 + 8) = 0;
  }
  *((_WORD *)v9 + 10) = v11;
  result = v22;
  if ( v22 >= (signed int)uNumLayingItems )
    uNumLayingItems = v22 + 1;
  return result;
}

//----- (0042F7EB) --------------------------------------------------------
signed int __fastcall sub_42F7EB_DropItemAt(int a1, int a2, signed int a3, int a4, int a5, int a6, int a7, __int16 a8, ItemGen *a9)
{
  int v9; // edi@1
  int v10; // edx@3
  int v11; // ecx@4
  __int16 v12; // ax@7
  int v13; // edx@9
  int v14; // ecx@10
  int v15; // esi@17
  int v16; // eax@18
  int v17; // edi@20
  int v18; // esi@20

  struct
  {
   short word_DDC;
   short word_DDE;
   int v687; // [sp+DE0h] [bp-A4h]@74
   __int64 v688; // [sp+DE4h] [bp-A0h]@74
   int dummy_at_0DEC;
   short dummy_at_0DF0;
   __int16 v689; // [sp+DF2h] [bp-92h]@74
   __int16 v690; // [sp+DF4h] [bp-90h]@74
   __int16 v691; // [sp+DF6h] [bp-8Eh]@74
   __int16 v692; // [sp+DF8h] [bp-8Ch]@79
   __int16 v693; // [sp+DFAh] [bp-8Ah]@74
   __int16 dummy_at_0DFC;
   __int16 dummy_at_0DFE;
   ItemGen v694; // [sp+E00h] [bp-84h]@72
   int v695; // [sp+E24h] [bp-60h]@72
   int v696; // [sp+E28h] [bp-5Ch]@72
   int v697; // [sp+E2Ch] [bp-58h]@72
  int dummy_0E30;
  int v698; // [sp+E34h] [bp-50h]@74
  int v699; // [sp+E38h] [bp-4Ch]@74
  char v700; // [sp+E3Ch] [bp-48h]@74
  char dummy_E3D[3]; //?
  } v20;

  /*__int16 v20; // [sp+Ch] [bp-78h]@1
  __int16 v21; // [sp+Eh] [bp-76h]@8
  int v22; // [sp+10h] [bp-74h]@8
  int v23; // [sp+14h] [bp-70h]@8
  int v24; // [sp+18h] [bp-6Ch]@8
  __int16 v25; // [sp+22h] [bp-62h]@18
  __int16 v26; // [sp+24h] [bp-60h]@8
  __int16 v27; // [sp+26h] [bp-5Eh]@8
  __int16 v28; // [sp+28h] [bp-5Ch]@8
  __int16 v29; // [sp+2Ah] [bp-5Ah]@8
  ItemGen v30; // [sp+30h] [bp-54h]@1
  int v31; // [sp+54h] [bp-30h]@3
  int v32; // [sp+58h] [bp-2Ch]@3
  int v33; // [sp+5Ch] [bp-28h]@3
  int v34; // [sp+60h] [bp-24h]@3
  int v35; // [sp+64h] [bp-20h]@8*/

  int v36; // [sp+68h] [bp-1Ch]@8
  int v37; // [sp+7Ch] [bp-8h]@1
  int v38; // [sp+80h] [bp-4h]@1

  v9 = a1;
  v37 = a2;
  v38 = a1;
  sub_404828(&v20);
  ItemGen_Reset(&v20.v694);
  if ( a9 )
  {
    memcpy(&v20.v694, a9, 0x24u);
    v9 = v38;
  }
  v10 = 0;
  v20.v697 = 0;
  v20.v696 = 0;
  v20.v695 = 0;
  v20.dummy_0E30 = 0;
  v20.word_DDC = v9;
  if ( pObjectDescriptionList->uNumObjects <= 0 )
  {
LABEL_7:
    v12 = 0;
  }
  else
  {
    v11 = (int)(pObjectDescriptionList->pDescriptions + 32);
    while ( (_WORD)v9 != *(_WORD *)v11 )
    {
      ++v10;
      v11 += 56;
      if ( v10 >= pObjectDescriptionList->uNumObjects )
        goto LABEL_7;
    }
    v12 = v10;
  }
  v20.word_DDE = v12;
  HIDWORD(v20.v688) = a4;
  v20.v687 = v37;
  LODWORD(v20.v688) = a3;
  v20.v690 = 0;
  v20.v691 = a8;
  v20.v692 = sub_49AC17((int)byte_6BE3C8, v37, a3, a4);
  v20.v693 = 0;
  v20.v698 = 0;
  v36 = 0;
  if ( !(v20.v691 & 0x10) )
  {
    v13 = 0;
    if ( pClass40->uNumItems > 0 )
    {
      v14 = (int)word_5D29F8;
      while ( *(_WORD *)v14 != v9 )
      {
        ++v13;
        v14 += 48;
        if ( v13 >= pClass40->uNumItems )
          goto LABEL_16;
      }
      v20.v694.uItemID = v13;
    }
  }
LABEL_16:
  if ( a7 )
  {
    v15 = a6;
    if ( a6 > 0 )
    {
      do
      {
        v20.v689 = rand() % pClass59_global->uIntegerDoublePi;
        v16 = rand();
        sub_42F5ED((int)&v20, v20.v689, (pClass59_global->uIntegerHalfPi >> 1) + (v16 % pClass59_global->uIntegerHalfPi >> 1), a5, 0);
        --v15;
      }
      while ( v15 );
    }
  }
  else
  {
    v17 = a6;
    v18 = pClass59_global->uIntegerHalfPi;
    v20.v689 = 0;
    if ( a6 > 0 )
    {
      do
      {
        sub_42F5ED((int)&v20, v20.v689, v18, a5, 0);
        --v17;
      }
      while ( v17 );
    }
  }
  return 1;
}

//----- (0042F960) --------------------------------------------------------
void __fastcall sub_42F960(int a1, signed int a2, int a3)
{
  int v3; // edx@1
  int v4; // ebx@1
  signed int v5; // edi@1
  int v6; // ecx@2
  __int16 v7; // ax@5
  signed int v8; // eax@6
  signed int v9; // eax@7
  __int16 v10; // [sp+Ch] [bp-70h]@1
  __int16 v11; // [sp+Eh] [bp-6Eh]@6
  int v12; // [sp+10h] [bp-6Ch]@6
  int v13; // [sp+14h] [bp-68h]@6
  int v14; // [sp+18h] [bp-64h]@6
  __int16 v15; // [sp+24h] [bp-58h]@6
  __int16 v16; // [sp+26h] [bp-56h]@6
  __int16 v17; // [sp+28h] [bp-54h]@6
  __int16 v18; // [sp+2Ah] [bp-52h]@6
  char v19; // [sp+30h] [bp-4Ch]@1
  int v20; // [sp+54h] [bp-28h]@1
  int v21; // [sp+58h] [bp-24h]@1
  int v22; // [sp+5Ch] [bp-20h]@1
  int v23; // [sp+60h] [bp-1Ch]@1
  int v24; // [sp+64h] [bp-18h]@6
  int v25; // [sp+68h] [bp-14h]@6

  v4 = a1;
  v5 = a2;
  sub_404828(&v10);
  ItemGen_Reset((ItemGen *)&v19);
  v3 = 0;
  v22 = 0;
  v21 = 0;
  v20 = 0;
  v23 = 0;
  v10 = 800;
  if ( pObjectDescriptionList->uNumObjects <= 0 )
  {
LABEL_5:
    v7 = 0;
  }
  else
  {
    v6 = (int)(pObjectDescriptionList->pDescriptions + 32);
    while ( *(_WORD *)v6 != 800 )
    {
      ++v3;
      v6 += 56;
      if ( v3 >= pObjectDescriptionList->uNumObjects )
        goto LABEL_5;
    }
    v7 = v3;
  }
  v11 = v7;
  v12 = v4;
  v13 = v5;
  v14 = a3;
  v15 = 0;
  v16 = 0;
  v17 = sub_49AC17((int)byte_6BE3C8, v4, v5, a3);
  v18 = 0;
  v24 = 0;
  v25 = 0;
  v8 = sub_42F5ED((int)&v10, 0, 0, 0, 0);
  if ( v8 != -1 )
  {
    v9 = 8 * v8;
    LOBYTE(v9) = v9 | 2;
    pAudioPlayer->sub_4AA306(220, v9, 0, -1, 0, 0, 0, 0);
  }
}

//----- (0042FA22) --------------------------------------------------------
signed int __cdecl sub_42FA22()
{
  signed int result; // eax@1
  size_t v1; // edx@1
  void *v2; // ebx@1
  int v3; // ebp@1

  v1 = 0;
  v3 = 0;
  result = (int)&pLayingItemsList[0].uObjectDescriptionID;
  v2 = pLayingItemsList;
  do
  {
    if ( *(_WORD *)result )
    {
      if ( v3 != v1 )
      {
        memcpy(v2, (const void *)(result - 2), 112);
        *(_WORD *)result = 0;
      }
      ++v1;
      v2 = (char *)v2 + 112;
    }
    result += 112;
    ++v3;
  }
  while ( result < 6817714 );
  uNumLayingItems = v1;
  return result;
}

//----- (0042FA66) --------------------------------------------------------
signed int __fastcall sub_42FA66(int a1, signed int a2, int a3, int a4, __int16 a5, signed int a6)
{
  int v6; // edi@1
  signed int v7; // esi@1
  int v8; // ecx@2
  __int16 v9; // ax@5
  int v10; // eax@10
  signed int result; // eax@11
  __int16 v12; // ax@12
  __int16 v13; // [sp+Ch] [bp-74h]@1
  __int16 v14; // [sp+Eh] [bp-72h]@6
  int v15; // [sp+10h] [bp-70h]@6
  int v16; // [sp+14h] [bp-6Ch]@6
  int v17; // [sp+18h] [bp-68h]@6
  __int16 v18; // [sp+22h] [bp-5Eh]@6
  __int16 v19; // [sp+24h] [bp-5Ch]@6
  __int16 v20; // [sp+26h] [bp-5Ah]@6
  __int16 v21; // [sp+28h] [bp-58h]@6
  __int16 v22; // [sp+2Ah] [bp-56h]@6
  char v23; // [sp+30h] [bp-50h]@1
  int v24; // [sp+54h] [bp-2Ch]@1
  int v25; // [sp+58h] [bp-28h]@1
  int v26; // [sp+5Ch] [bp-24h]@1
  int v27; // [sp+64h] [bp-1Ch]@8
  int v28; // [sp+68h] [bp-18h]@6
  char v29; // [sp+6Ch] [bp-14h]@6
  int v30; // [sp+7Ch] [bp-4h]@1

  v6 = a1;
  v7 = a2;
  sub_404828(&v13);
  v13 = 600;
  ItemGen_Reset((ItemGen *)&v23);
  v24 = 6;
  v25 = 8;
  v26 = 3;
  v30 = 0;
  if ( pObjectDescriptionList->uNumObjects <= 0 )
  {
LABEL_5:
    v9 = 0;
  }
  else
  {
    v8 = (int)(pObjectDescriptionList->pDescriptions + 32);
    while ( v13 != *(_WORD *)v8 )
    {
      ++v30;
      v8 += 56;
      if ( v30 >= pObjectDescriptionList->uNumObjects )
        goto LABEL_5;
    }
    v9 = v30;
  }
  v14 = v9;
  v15 = v6;
  v16 = v7;
  v17 = a3;
  v20 = 0;
  v21 = sub_49AC17((int)byte_6BE3C8, v6, v7, a3);
  v22 = 0;
  v28 = 0;
  v29 = 0;
  v18 = 0;
  v19 = 0;
  if ( a6 >= 1 || a6 <= 4 )
  {
    v10 = 8 * a6 - 8;
    LOBYTE(v10) = v10 | 4;
    v27 = v10;
  }
  else
  {
    v27 = 0;
  }
  result = sub_42F5ED((int)&v13, 0, 0, 0, 0);
  if ( result != -1 )
  {
    v12 = 8 * result;
    LOBYTE(v12) = v12 | 2;
    result = sub_40261D(&dword_50FE08, v12, a5, v15, v16, v17, 0, 0);
  }
  return result;
}

//----- (0042FB5C) --------------------------------------------------------
signed int __fastcall sub_42FB5C(signed int a1)
{
  int v1; // ecx@3
  int v2; // ecx@4
  int v3; // ecx@5
  int v4; // ecx@6
  int v5; // ecx@7
  int v6; // ecx@8
  char v7; // zf@9

  if ( a1 > 39 )
  {
    if ( a1 > 77 )
    {
      if ( a1 == 80 )
        return 0;
      if ( a1 > 84 )
      {
        if ( a1 <= 86 )
          return 0;
        v7 = a1 == 95;
        goto LABEL_20;
      }
    }
    else
    {
      if ( a1 == 77 )
        return 0;
      if ( a1 >= 46 )
      {
        if ( a1 <= 47 || a1 == 51 )
          return 0;
        v7 = a1 == 73;
        goto LABEL_20;
      }
    }
    return 1;
  }
  if ( a1 == 39 || (v1 = a1 - 2, !v1) )
    return 1;
  v2 = v1 - 3;
  if ( !v2 )
    return 0;
  v3 = v2 - 1;
  if ( !v3 || (v4 = v3 - 3, !v4) )
    return 1;
  v5 = v4 - 8;
  if ( !v5 )
    return 0;
  v6 = v5 - 1;
  if ( !v6 )
    return 1;
  v7 = v6 == 20;
LABEL_20:
  if ( !v7 )
    return 1;
  return 0;
}

//----- (0042FBDD) --------------------------------------------------------
signed int __cdecl sub_42FBDD()
{
  pAudioPlayer->sub_4AA306(75, 0, 0, -1, 0, 0, 0, 0);
  Render_DrawTransparentTexture(pD3DRenderer, dword_5076FC->uX, dword_5076FC->uY, *(cTexture **)((char*)dword_5076FC + 60));
  return pD3DRenderer->Present();
}

//----- (0042FC15) --------------------------------------------------------
signed int __cdecl sub_42FC15()
{
  pAudioPlayer->sub_4AA306(75, -2, 0, -1, 0, 0, 0, 0);
  Render_DrawTransparentTexture(pD3DRenderer, dword_5076F4->uX, dword_5076F4->uY, *(cTexture **)((char*)dword_5076F4 + 60));
  return pD3DRenderer->Present();
}

//----- (0042FC4E) --------------------------------------------------------
void __cdecl sub_42FC4E_ProcessPressedKeys()
{
  //int v1; // ebx@7
  //int v3; // ecx@8
  char v4; // al@9
  int v6; // ecx@86
  char v7; // bl@100
  int v8; // esi@100
  __int16 v9; // ax@102
  int v10; // eax@103
  int v11; // eax@127
  //signed int v12; // esi@157
  int v13; // ecx@158
  //char v14; // al@159
  int v15; // eax@168
  int v16; // esi@177
  int v17; // [sp-14h] [bp-1Ch]@8
  //int v18; // [sp-14h] [bp-1Ch]@20
  int v19; // [sp-14h] [bp-1Ch]@54
  __int16 v20; // [sp-14h] [bp-1Ch]@60
  int v21; // [sp-14h] [bp-1Ch]@68
  int v22; // [sp-Ch] [bp-14h]@158
  //signed int v23; // [sp+0h] [bp-8h]@7
  int v24; // [sp+4h] [bp-4h]@87

  if (!bAlwaysRun)
  {
   if (pUserInput->IsShiftToggled())
      goto LABEL_3;
LABEL_5:
    pParty_global->dword_000884 &= 0xFFFFFFFDu;
    goto LABEL_6;
  }
  if (pUserInput->IsShiftToggled())
    goto LABEL_5;
LABEL_3:
  pParty_global->dword_000884 |= 2;

LABEL_6:
 if (cClock1.dword_000004)
 {
  if (pUserInput->IsKeyToggled(Keyboard::Key::Interact))
  {
   if (!dword_4E28F8_PartyCantJumpIfTrue)
     dword_50CBD0.PutMessageToQueue(404, 0, 0);
   else if (dword_4E28F8_PartyCantJumpIfTrue == 4 ||
            dword_4E28F8_PartyCantJumpIfTrue == 19)
   {
    dword_50CBD0.CutQueueTail();
    dword_50CBD0.PutMessageToQueue(113,0,0);
   }
  }
 }
 else
 {

  struct event_blueprint
  {
   Keyboard::Key::Type event;
   void (*handler)();
  } events[] =
  {
   {Keyboard::Key::Forward,       PartyAction_OnMovingForward},
   {Keyboard::Key::Backwards,     PartyAction_OnMovingBackwards},
   {Keyboard::Key::TurnLeft,      PartyAction_OnTurningLeft},
   {Keyboard::Key::TurnRight,     PartyAction_OnTurningRight},
   {Keyboard::Key::Yell,          PartyAction_OnYell},
   {Keyboard::Key::Jump,          PartyAction_OnJump},
   {Keyboard::Key::Combat,        PartyAction_OnToggleTurnBasedMode},
   {Keyboard::Key::CastReady,     PartyAction_OnCastReady},
   {Keyboard::Key::Attack,        PartyAction_OnAttack},
   {Keyboard::Key::Interact,      PartyAction_OnInteract},
   {Keyboard::Key::Cast,          },
   {Keyboard::Key::Pass,          PartyAction_OnPass},
   {Keyboard::Key::CharCycle,     PartyAction_OnCharCycle},
   {Keyboard::Key::OpenQuestbook, 0},
   {Keyboard::Key::OpenQuickRef,  0},
   {Keyboard::Key::Rest,          0},
   {Keyboard::Key::OpenCalendar,  0},
   {Keyboard::Key::OpenAutonotes, 0},
   {Keyboard::Key::OpenMap,       0},
   {Keyboard::Key::AlwaysRun,     PartyAction_OnAlwaysRun},
   {Keyboard::Key::LookUp,        PartyAction_OnLookUp},
   {Keyboard::Key::LookDown,      PartyAction_OnLookDown},
   {Keyboard::Key::CenterView,    PartyAction_OnCenterView},
   {Keyboard::Key::ZoomIn,        PartyAction_OnZoomIn},
   {Keyboard::Key::ZoomOut,       PartyAction_OnZoomOut},
   {Keyboard::Key::FlyUp,         PartyAction_OnFlyUp},
   {Keyboard::Key::FlyDown,       PartyAction_OnFlyDown},
   {Keyboard::Key::Land,          PartyAction_OnLand},
   {Keyboard::Key::StrafeLeft,    PartyAction_OnStrafeLeft},
   {Keyboard::Key::StrafeRight,   PartyAction_OnStrafeRight}
  };

  for (unsigned int i = 0; i < 30; ++i)
    if (events[i].handler && pUserInput->IsKeyToggled(events[i].event))
      (events[i].handler)();
 }

  runtime_warning(async input);
  /*if ( *(_BYTE *)(&pGame->Win32Keyboard_obj->dword_000004) )
  {
    AsyncInput_sub_45B1FD_LeaveCS();
    v16 = pAsyncKeyboard;
    AsyncInput_sub_45B1FD_EnterCS();
    memset((void *)(v16 + 521), 0, 0x100u);
    AsyncInput_sub_45B1FD_LeaveCS();
  }*/
}

void unnamed_505898_ctor(struct unnamed_505898 *_this)
{
 _this->dword_000004 = 0;
 _this->class33_obj0.PCXTexture_Zero();
 _this->class33_obj1.PCXTexture_Zero();

 _this->byte_505991 = 0;
 _this->byte_505992 = 0;
}



//----- (00435694) --------------------------------------------------------
int __thiscall Game_sub_435694(int _this, int a2)
{
  int result; // eax@1

  result = *(_DWORD *)(_this + 3620);
  if ( result & a2 )
  {
    *(_DWORD *)(_this + 3620) = result & ~a2;
  }
  else
  {
    result |= a2;
    *(_DWORD *)(_this + 3620) = result;
  }
  return result;
}

//----- (004356FF) --------------------------------------------------------
void __cdecl sub_4356FF()
{
  dword_507BF0 = 0;
  dword_4E455C = 1;
  dword_50CDCC = 0;
  if (ptr_507BC4)
    sub_467F9F();
  if ( !dword_4E28F8_PartyCantJumpIfTrue )
  {
    if ( !ptr_507BD4 )
      cClock1.clock_sub_426363();
  }
  struct_576FE8.dword_000044 = 1;
}

//----- (00435748) --------------------------------------------------------
void __cdecl sub_435748_PlayerCreationUI_MessageProc()
{
  int v0; // ebx@2
  int v1; // ebp@2
  void *v2; // ecx@18
  int v3; // edi@21
  int v4; // ecx@29
  signed int v5; // eax@29
  signed int v6; // edi@37
  char v7; // sf@54
  int v8; // eax@56
  int v9; // edx@56
  struct Player *v10; // edi@57
  signed int v11; // eax@58
  int v12; // eax@59
  char v13; // sf@62
  signed int v14; // eax@64
  int v15; // eax@66
  signed int v16; // edi@70
  int v17; // eax@73
  char v18; // zf@73
  int v19; // eax@80
  int v20; // ecx@105
  void *v21; // ecx@116
  struct Player *v22; // edi@116
  char v23; // dl@116
  int v24; // eax@116
  //int v25; // eax@118
  struct Player *v26; // ebx@118
  char v27; // sf@118
  int v28; // eax@120
  int v29; // ecx@127
  int v30; // eax@129
  unsigned __int8 v31; // sf@129
  unsigned __int8 v32; // of@129
  int v33; // [sp-2Ch] [bp-3Ch]@36
  signed int v34; // [sp-28h] [bp-38h]@36
  int v35; // [sp-24h] [bp-34h]@36
  signed int v36; // [sp-20h] [bp-30h]@36
  int v37; // [sp-20h] [bp-30h]@105
  int v38; // [sp-1Ch] [bp-2Ch]@36
  int v39; // [sp-1Ch] [bp-2Ch]@105
  int v40; // [sp-18h] [bp-28h]@36
  signed int v41; // [sp-18h] [bp-28h]@105
  int v42; // [sp-14h] [bp-24h]@36
  int v43; // [sp-14h] [bp-24h]@56
  signed int v44; // [sp-10h] [bp-20h]@15
  signed int v45; // [sp-10h] [bp-20h]@29
  int v46; // [sp-10h] [bp-20h]@36
  int v47; // [sp-10h] [bp-20h]@56
  int v48; // [sp+4h] [bp-Ch]@3
  unsigned int v49; // [sp+8h] [bp-8h]@3
  int v50; // [sp+Ch] [bp-4h]@3

  if ( dword_50CBD0.msg_count )
  {
    v1 = (int)pAudioPlayer;
    v0 = (int)&pParty_global->pPlayers[0];
    do
    {
      dword_50CBD0.GetQueueMessage(&v49, &v48, &v50);

      if (v49 == 145) // button change voice (right)
      {
          Player               *pPlayer = &pParty_global->pPlayers[v48];
          Character::Sex::Type  eOriginalSex = Player_GetSexByVoice(pPlayer);

          do
          {
           pPlayer->uVoiceID = (pPlayer->uVoiceID + 1) % 20;
           Player_GetSexByVoice(pPlayer);
          }
          while (Player_GetSexByVoice(pPlayer) != eOriginalSex);

          GUIButton *pButton = pBtn_CharacterCreationUI_VoiceNext[v48];
          GUIWindowCreate(pButton->uX, pButton->uY, 0, 0, 92, pButton, 1);

          pAudioPlayer->sub_4AA306(66, 0, 0, -1, 0, 0, 0, 0);
          Player_PlaySound(pPlayer, Character::Voice::PickMe, 0);
          continue;
      }
      else if (v49 == 144) // button change voice (left)
      {
          Player *pPlayer = &pParty_global->pPlayers[v48];
            v50 = Player_GetSexByVoice(pPlayer);
            do
            {
              pPlayer->uVoiceID--;
              if ( pPlayer->uVoiceID  == -1)
                pPlayer->uVoiceID = 19;
              v14 = Player_GetSexByVoice(pPlayer);
            }
            while ( v14 != v50 );
            v12 = (int)pBtn_CharacterCreationUI_VoicePrev[v48];

            GUIWindowCreate(*(_DWORD *)v12, *(_DWORD *)(v12 + 4), 0, 0, 92, (GUIButton*)v12, 1);
            pAudioPlayer->sub_4AA306(66, 0, 0, -1, 0, 0, 0, 0);
            Player_PlaySound(pPlayer, Character::Voice::PickMe, 0);
            continue;
      }
      else
      if ( v49 > 75 )
      {
        if ( v49 > 163 )
        {
          if ( v49 == 164 )
          {
            v47 = 0;
            v43 = (int)pLoadSaveBtn;
            v9 = pGUIWindow_CurrentMenu->uFrameY + 302;
            v41 = 94;
            v20 = pGUIWindow_CurrentMenu->uFrameX + 241;
LABEL_133:
            v39 = 28;
            v37 = 61;
LABEL_134:
            GUIWindowCreate(v20, v9, v37, v39, v41, (GUIButton*)v43, v47);
            continue;
          }
          if ( v49 == 165 )
          {
            if ( pGUIWindow_CurrentMenu->dword_000040 == 1 )
              pUserInput->sub_459ED1(0);
            if ( dword_4E28F8_PartyCantJumpIfTrue != 11 || dword_6A0CA0_indx != v48 + dword_6A0C9C )
            {
              v29 = v48 + dword_6A0C9C;
              if ( dword_6BE138 == v48 + dword_6A0C9C )
              {
              /*  if ( dword_50CBD0[0] < 40 )
                {
                  dword_50CBD0[3 * dword_50CBD0[0] + 1] = 164;
                  dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
                  dword_50CBD0[3 * dword_50CBD0[0] + 3] = 0;
                  v30 = dword_50CBD0[0] + 1;
                  compile_error();//v32 = __SETO__(dword_50CBD0[0] + 1, 40);
                  v31 = dword_50CBD0[0]++ - 39 < 0;
                  if ( v31 ^ v32 )
                  {
                    dword_50CBD0[3 * v30 + 1] = 82;
                    dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
                    dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
                  }
                }	*/
				dword_50CBD0.PutMessageToQueue(164,0,0);
				dword_50CBD0.PutMessageToQueue(82,0,0);
              }
              dword_6A0CA0_indx = v29;
              dword_6BE138 = v29;
            }
            else
            {
              pUserInput->sub_459E5A(0, 19, (int)pGUIWindow_CurrentMenu);
              strcpy((char *)pUserInput->pPressedKeysBuffer, (const char *)&saves_hdr[dword_6A0CA0_indx].name1);
              pUserInput->uNumKeysPressed = strlen((char *)pUserInput->pPressedKeysBuffer);
            }
            continue;
          }
          if ( v49 == 166 )
          {
            v47 = 0;
            v43 = (int)pCancelBtn;
            v9 = pGUIWindow_CurrentMenu->uFrameY + 302;
            v41 = 95;
            v20 = pGUIWindow_CurrentMenu->uFrameX + 350;
            goto LABEL_133;
          }
          if ( v49 == 171 ) // change face button (left)
          {
            v26 = &pParty_global->pPlayers[v48];
            v27 = (v26->uFace - 1) < 0;
            v26->uFace--;
            if ( v27 )
              v26->uFace = 19;
            v26->uVoiceID = v26->uFace; //face to voice? strange, but double-checked
            Player_SetInitialStats(v26);
            sub_4901FC((int)v26);
            Player_RandomizeName(v26);
            v28 = v48;
            pGUIWindow_CurrentMenu->dword_00002C = (pGUIWindow_CurrentMenu->dword_00002C - pGUIWindow_CurrentMenu->dword_000038) % 7
                                           + pGUIWindow_CurrentMenu->dword_000038
                                           + 7 * v48;
            uPlayerCreationUI_SelectedCharacter = v28;
            GUIWindowCreate(*(_DWORD *)array_A74CAC[v28], *(_DWORD *)(array_A74CAC[v28] + 4), 0, 0, 92, (GUIButton*)array_A74CAC[v28], 1);
            v1 = (int)pAudioPlayer;
            pAudioPlayer->sub_4AA306(66, 0, 0, -1, 0, 0, 0, 0);
            v21 = (void *)v26;
            goto LABEL_117;
          }
          if ( v49 == 172 ) // change face button (right)
          {
            v22 = &pParty_global->pPlayers[v48];
            v23 = (v22->uFace + 1) % 20;
            v22->uFace = v23;
            v22->uVoiceID = v23;
            Player_SetInitialStats(v22);
            sub_4901FC((int)v22);
            Player_RandomizeName(v22);
            v24 = v48;
            pGUIWindow_CurrentMenu->dword_00002C = (pGUIWindow_CurrentMenu->dword_00002C - pGUIWindow_CurrentMenu->dword_000038) % 7
                                           + pGUIWindow_CurrentMenu->dword_000038
                                           + 7 * v48;
            uPlayerCreationUI_SelectedCharacter = v24;
            GUIWindowCreate(*(_DWORD *)array_A74CBC[v24], *(_DWORD *)(array_A74CBC[v24] + 4), 0, 0, 92, (GUIButton*)array_A74CBC[v24], 1);
            v1 = (int)pAudioPlayer;
            pAudioPlayer->sub_4AA306(66, 0, 0, -1, 0, 0, 0, 0);
            v21 = (void *)v22;
LABEL_117:
            Player_PlaySound((Player *)v21, 102, 0);
            v0 = (int)&pParty_global->pPlayers[0];
            continue;
          }
          if ( v49 == 173 )
          {
           GUIWindowCreate(pMainMenu_NewGame->uX, pMainMenu_NewGame->uY, 0, 0, 90, pMainMenu_NewGame, 0);
            goto LABEL_99;
          }
          if ( v49 != 174 )
            continue;
          GUIWindowCreate(pMainMenu_Exit->uX, pMainMenu_Exit->uY, 0, 0, 90, pMainMenu_Exit, 0);
LABEL_114:
          v44 = 10;
LABEL_89:
          v2 = (void *)v44;
LABEL_90:
          SetCurrentMenu((unsigned int)v2);
          continue;
        }
        if ( v49 == 163 )
        {
          ++dword_6A0C9C;
          if ( dword_6A0C9C >= v48 )
            dword_6A0C9C = v48 - 1;
          if ( dword_6A0C9C < 1 )
            dword_6A0C9C = 0;
          v8 = (int)pGUIWindow_CurrentMenu;
          v47 = 0;
          v43 = (int)pArrowDownBtn;
          v9 = pGUIWindow_CurrentMenu->uFrameY + 323;
          goto LABEL_105;
        }
        if ( v49 == 82 )
        {
          if ( !dword_69CF28[dword_6A0CA0_indx] )
            continue;
LABEL_99:
          v44 = 9;
          goto LABEL_89;
        }
        if ( v49 == 107 )
        {
          if ( dword_4E28F8_PartyCantJumpIfTrue )
          {
            GUIWindowDelete(pGUIWindow_CurrentMenu);
            cClock1.clock_sub_426363();
            dword_4E28F8_PartyCantJumpIfTrue = 0;
            struct_576FE8.dword_000044 = 1;
          }
          GUIWindowCreate(602, 450, 0, 0, 92, pBtn_Game_Options, 0);
       /*   if ( dword_50CBD0[0] >= 40 )
            continue;
          dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
          goto LABEL_93; */
		  dword_50CBD0.PutMessageToQueue(113,0,0);
		   continue;
        }
        if ( v49 == 113 )
        {
          if ( ptr_507BDC )
          {
            sub_41426F();
            continue;
          }
          if ( !(BYTE1(dword_6BE364) & 0x40) )
            continue;
          v16 = 1;

          if (!bNoVideo)
            pVideoPlayer->StopMovie();

          struct_576FE8.dword_000044 = 1;
          struct_576FE8.dword_000048 = 1;
          if ( !sub_466CA0() || sub_466CA0() == MENU_CREATEPARTY || sub_466CA0() == 7 )
          {
            v17 = dword_4E28F8_PartyCantJumpIfTrue;
LABEL_83:
            runtime_warning();
            //if ( v17 == 16 )
            //  pVideoPlayer->sub_4BECD5(pVideoPlayer->dword_000040);

            if ( sub_466CA0() == 7 )
            {
              v44 = 6;
              goto LABEL_89;
            }
            if ( sub_466CA0() == 8 )
            {
              v44 = 11;
              goto LABEL_89;
            }
     /*       if ( dword_50CBD0[0] < 40 )
            {
              dword_50CBD0[3 * dword_50CBD0[0] + 1] = 5;
LABEL_93:
              dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
              dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
              continue;
            }	*/
			dword_50CBD0.PutMessageToQueue(5,0,0);
            continue;
          }
          v18 = sub_466CA0() == 8;
          v17 = dword_4E28F8_PartyCantJumpIfTrue;
          if ( v18 && !dword_4E28F8_PartyCantJumpIfTrue )
            goto LABEL_83;
          if ( dword_4E28F8_PartyCantJumpIfTrue == 12 )
          {
            LODFile_Icons_LOD.LODFile_sub_4114F2();
            v19 = (int)sub_45E006();

			#ifndef OLD_CODE           
            LODFile_Icons_LOD.LODFile_ReleaseTexture( uTextureID_CurrentMenu);

			  uTextureID_CurrentMenu = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"Title");
#endif
#ifdef OLD_CODE
		   cPCXID_CurrentMenu.PCXTexture_Release();
		   cPCXID_CurrentMenu.LODPCXLoad("title.pcx", 0);
		  
#endif
           
            SetCurrentMenu(MENU_MAIN);
            v16 = 1;
LABEL_81:
            GUIWindowDelete(pGUIWindow_CurrentMenu);
            GUIWindowDelete(pGUIWindow2);
            pGUIWindow2 = 0;
            cClock1.clock_sub_426363();
            dword_4E28F8_PartyCantJumpIfTrue = 0;
            struct_576FE8.dword_000044 = v16;
            continue;
          }
          if ( dword_4E28F8_PartyCantJumpIfTrue == 16 )
          {
            pVideoPlayer->UnloadAll();
          }
          else
          {
            if ( dword_4E28F8_PartyCantJumpIfTrue != 27 )
              goto LABEL_81;
            sub_4BECBD(27, (int)pVideoPlayer);
          }
        }
        else
        {
          if ( v49 == 118 )
          {
            v15 = v48;
            pGUIWindow_CurrentMenu->dword_00002C = (pGUIWindow_CurrentMenu->dword_00002C - pGUIWindow_CurrentMenu->dword_000038) % 7
                                           + pGUIWindow_CurrentMenu->dword_000038
                                           + 7 * v48;
            uPlayerCreationUI_SelectedCharacter = v15;
LABEL_36:
            v46 = 0;
            v42 = 0;
            v40 = 0;
            v38 = 0;
            v36 = -1;
            v35 = 0;
            v34 = 0;
            v33 = 66;
LABEL_40:
            ((AudioPlayer *)v1)->sub_4AA306(v33, v34, v35, v36, v38, v40, v42, v46);
            continue;
          }

          if ( v49 == 162 )
          {
            v7 = dword_6A0C9C-- - 1 < 0;
            if ( v7 )
              dword_6A0C9C = 0;
            v8 = (int)pGUIWindow_CurrentMenu;
            v47 = 0;
            v43 = (int)pArrowUpBtn;
            v9 = pGUIWindow_CurrentMenu->uFrameY + 197;
LABEL_105:
            v41 = 90;
            v39 = 0;
            v37 = 0;
            v20 = *(_DWORD *)v8 + 215;
            goto LABEL_134;
          }
        }
      }
      else
      {
        if ( v49 == 75 )
        {
          uPlayerCreationUI_SelectedCharacter = v48;
          v45 = 3;
          v0 = (int)&pParty_global->pPlayers[0];
          v4 = (pGUIWindow_CurrentMenu->dword_00002C - pGUIWindow_CurrentMenu->dword_000038) % 7
             + pGUIWindow_CurrentMenu->dword_000038
             + 7 * v48;
          goto LABEL_44;
        }
        if ( v49 > 60 )
        {
          if ( v49 == 62 )
          {
            GUIWindowCreate(613, 393, 0, 0, 90, pPlayerCreationUI_BtnPlus, 1);
            PartyCreation_BtnPlusClick(&pParty_global->pPlayers[uPlayerCreationUI_SelectedCharacter], (pGUIWindow_CurrentMenu->dword_00002C - pGUIWindow_CurrentMenu->dword_000038) % 7);
            v46 = 0;
            v42 = 0;
            v40 = 0;
            v38 = 0;
            v36 = -1;
            v35 = 0;
            v34 = 0;
            v33 = 20;
            goto LABEL_40;
          }
          if ( v49 == 63 )
          {
            GUIWindowCreate(523, 393, 0, 0, 90, pPlayerCreationUI_BtnMinus, 1);            
            PartyCreation_BtnMinusClick(&pParty_global->pPlayers[uPlayerCreationUI_SelectedCharacter], (pGUIWindow_CurrentMenu->dword_00002C - pGUIWindow_CurrentMenu->dword_000038) % 7);
            v46 = 0;
            v42 = 0;
            v40 = 0;
            v38 = 0;
            v36 = -1;
            v35 = 0;
            v34 = 0;
            v33 = 23;
            goto LABEL_40;
          }
          if ( v49 == 64 )
          {
            v6 = GetSkillIdxByOrder(&pParty_global->pPlayers[uPlayerCreationUI_SelectedCharacter], v48 + 4);
            if ( GetSkillIdxByOrder(&pParty_global->pPlayers[uPlayerCreationUI_SelectedCharacter], 3) == 37 ) // 37 - no more skills
              pParty_global->pPlayers[uPlayerCreationUI_SelectedCharacter].pActiveSkills[v6] = 1;
            v46 = 0;
            v42 = 0;
            v40 = 0;
            v38 = 0;
            v36 = -1;
            v35 = 0;
            v34 = 0;
            v33 = 24;
            goto LABEL_40;
          }
          if ( v49 == 65 )
          {
            Player_Reset(&pParty_global->pPlayers[uPlayerCreationUI_SelectedCharacter], v48);
            goto LABEL_36;
          }
          if ( v49 == 66 ) // Character Creation :: OK
          {
            GUIWindowCreate(580, 431, 0, 0, 90, pPlayerCreationUI_BtnOK, 0);
            runtime_warning();
            /*if ( PlayerCreation_ComputeAttributeBonus() || !sub_4908DE() ) // check all points are destributed
              dword_5C35B8_Some_GetTickCount_timer = GetTickCount() + 4000;
            else*/
              dword_6A0D48 = 6;
            continue;
          }
          if ( v49 == 67 )
          {
            GUIWindowCreate(527, 431, 0, 0, 90, pPlayerCreationUI_BtnReset, 0);
            Party_Reset(pParty_global);
          }
          else
          {
            if ( v49 == 74 )
            {
              uPlayerCreationUI_SelectedCharacter = v48;
              v5 = pGUIWindow_CurrentMenu->dword_00002C - pGUIWindow_CurrentMenu->dword_000038;
              v50 = pGUIWindow_CurrentMenu->dword_000038;
              v45 = 2;
              v4 = v5 % 7 + v50 + 7 * v48;
LABEL_44:
              pGUIWindow_CurrentMenu->dword_00002C = v4;
              pParty_global->pPlayers[uPlayerCreationUI_SelectedCharacter].pActiveSkills[GetSkillIdxByOrder(&pParty_global->pPlayers[uPlayerCreationUI_SelectedCharacter], v45)] = 0;
              continue;
            }
          }
        }
        else
        {
          switch ( v49 )
          {
            case 60:
              ((AudioPlayer *)v1)->sub_4AA306(24, 0, 0, -1, 0, 0, 0, 0);
              v3 = v48;
              uPlayerCreationUI_SelectedCharacter = v48;
              pUserInput->sub_459E5A(0, 15, (int)pGUIWindow_CurrentMenu);
              pGUIWindow_CurrentMenu->dword_00001C = v3;
              break;
            case 5:
              dword_6A0D48 = 1;
              break;
            case 17:
              GUICursor_SetCursorBitmap(pGame->pGUICursor, "MICON2");
              break;
            default:
              if ( v49 == 54 )
              {
                GUIWindowCreate(495, 172, 0, 0, 90, pMainMenu_NewGame, 0);
                v2 = (void *)1;
                goto LABEL_90;
              }
              if ( v49 == 55 )
              {
                GUIWindowCreate(495, 227, 0, 0, 90, pMainMenu_LoadGame, 0);
                v44 = 3;
                goto LABEL_89;
              }
              if ( v49 == 56 )
              {
                GUIWindowCreate(495, 282, 0, 0, 90, pMainMenu_Credits, 0);
                v44 = 2;
                goto LABEL_89;
              }
              if ( v49 == 57 )
              {
                GUIWindowCreate(495, 337, 0, 0, 90, pMainMenu_Exit, 0);
                v44 = 4;
                goto LABEL_89;
              }
              if ( v49 == 58 )
                goto LABEL_114;
              break;
          }
        }
      }
    }
    while ( dword_50CBD0.msg_count );
  }
}


//----- (004363C6) --------------------------------------------------------
void __thiscall sub_4363C6(void *_this)
{
  void *v1; // esi@1

  v1 = _this;
  *(_DWORD *)_this = 5080468;
  _eh_vector_destructor_iterator_((int)_this + 52, 24, 6, (void (__fastcall *)(void *))class26_placeholder_detor);
  class26_default_ctor((class26 *)((char *)v1 + 36));
  class26_default_ctor((class26 *)((char *)v1 + 20));
  class26_default_ctor((class26 *)((char *)v1 + 4));
}

//----- (00436427) --------------------------------------------------------
double __cdecl sub_436427()
{
  double result; // st7@2

  if ( uCurrentlyLoadedLevelType == 2 )
    result = (double)pStruct9_global->shading_dist_mist;
  else
    result = 16192.0;
  return result;
}

//----- (0043643E) --------------------------------------------------------
double __cdecl sub_43643E()
{
  double result; // st7@2

  if ( uCurrentlyLoadedLevelType == 2 )
   result = (double)pStruct9_global->dword_000000;
  else
    result = 16192.0;
  return result;
}

//----- (00436455) --------------------------------------------------------
char __stdcall sub_436455(int a1)
{
  char v2; // [sp+8h] [bp-30h]@1

  sub_43648F((int)&v2, dword_6BE63C + 6 * **(_WORD **)(a1 + 48));
  return sub_438258(a1, (int)&v2);
}

//----- (0043648F) --------------------------------------------------------
int __thiscall sub_43648F(int _this, int a2)
{
  int result; // eax@1
  signed int v3; // edx@1
  double v4; // st7@1

  result = _this;
  *(float *)(_this + 44) = 0.0;
  v3 = *(_WORD *)(a2 + 2);
  v4 = (double)*(_WORD *)(a2 + 4);
  *(float *)_this = (double)*(_WORD *)a2;
  *(float *)(_this + 4) = (double)v3;
  *(float *)(_this + 8) = v4;
  return result;
}

//----- (004364C5) --------------------------------------------------------
void __stdcall sub_4364C5(int a1, int a2, int a3, int a4)
{
  int v4; // ebx@1
  int v5; // eax@2
  int v6; // edx@2

  v4 = a2;
  if ( a2 > 0 )
  {
    v6 = a3 + 8;
    v5 = a1 + 8;
    do
    {
      *(_DWORD *)(v6 - 8) = *(_DWORD *)(v5 - 8);
      *(_DWORD *)(v6 - 4) = *(_DWORD *)(v5 - 4);
      *(_DWORD *)v6 = *(_DWORD *)v5;
      v5 += 48;
      v6 += 48;
      --v4;
      *(float *)(v6 - 20) = (double)*(signed int *)(a4 + 60) + *(float *)(v5 - 20);
      *(float *)(v6 - 16) = (double)*(signed int *)(a4 + 64) + *(float *)(v5 - 16);
    }
    while ( v4 );
  }
  sub_436523((RenderVertex *)a3, a2);
}

//----- (00436523) --------------------------------------------------------
void __stdcall sub_436523(struct RenderVertex *a1, unsigned int uNumStructs)
{
  int v2; // esi@4
  int v3; // ecx@7
  int v6; // [sp+4h] [bp-4h]@7
 int i;

 if ( byte_4D8410[572] && pGame->uSomeFlags & 0x80 || uCurrentlyLoadedLevelType == 1 )
 {
  /*
      fld     pClass55_global->flt_000030
      fld     pClass55_global->flt_00002C
      fld     pClass55_global->flt_000038
  */

    v3 = uNumStructs;
    v6 = *(int *)&pOldCamera->fRotationXSine;
    if (pOldCamera->sRotationX)
    {
      if ( uNumStructs > 0 )
      {
        compile_error();//_EAX = a1;
        do
        {
          __asm
          {
           int 3
            //fild    pOldCamera->dword_000000
            fsubr   dword ptr [eax]
            //fstp    [ebp+arg_0]
            //fild    pOldCamera->dword_000004
            fsubr   dword ptr [eax+4]
            //fstp    [ebp+arg_4]
            //fild    pOldCamera->dword_000008
            fsubr   dword ptr [eax+8]
          }
          if ( pD3DRenderer->pRenderD3D3 )
          {
            __asm
            {
             int 3
              //fld     [ebp+arg_4]
              fmul    st, st(3)
              //fld     [ebp+arg_0]
              fmul    st, st(5)
              faddp   st(1), st
              //fld     [ebp+arg_0]
              fmul    st, st(4)
              //fld     [ebp+arg_4]
              fmul    st, st(6)
              fsubp   st(1), st
            }
          }
          else
          {
            __asm
            {
             int 3
              //fld     [ebp+arg_0]
              fmul    st, st(4)
              //fld     [ebp+arg_4]
              fmul    st, st(4)
              fsubp   st(1), st
              //fld     [ebp+arg_0]
              fmul    st, st(4)
              //fld     [ebp+arg_4]
              fmul    st, st(6)
              faddp   st(1), st
            }
          }
          __asm
          {
           int 3
            fld     st(1)
            fmul    st, st(4)
            fld     st(3)
            //fmul    [ebp+var_4]
          }
          compile_error();//_EAX += 48;
          --v3;
          __asm
          {
           int 3
            fsubp   st(1), st
            fstp    dword ptr [eax-24h]
            fstp    dword ptr [eax-20h]
            //fmul    [ebp+var_4]
            fld     st(1)
            fmul    st, st(3)
            faddp   st(1), st
            fstp    dword ptr [eax-1Ch]
            fstp    st
          }
        }
        while ( v3 );
      }
      __asm { fstp    st }
    }
    else
    {
      __asm { fstp    st }
      if ( uNumStructs > 0 )
      {
        compile_error();//_EAX = a1;
        do
        {
          __asm
          {
           int 3
            //fild    pOldCamera->dword_000000
            fsubr   dword ptr [eax]
            //fstp    [ebp+arg_0]
            //fild    pOldCamera->dword_000004
            fsubr   dword ptr [eax+4]
            //fstp    [ebp+arg_4]
            //fild    pOldCamera->dword_000008
            fsubr   dword ptr [eax+8]
          }
          if ( pD3DRenderer->pRenderD3D3 )
          {
            __asm
            {
             int 3
              //fld     [ebp+arg_4]
              fmul    st, st(2)
              //fld     [ebp+arg_0]
              fmul    st, st(4)
              faddp   st(1), st
              fstp    dword ptr [eax+0Ch]
              //fld     [ebp+arg_0]
              fmul    st, st(2)
              //fld     [ebp+arg_4]
              fmul    st, st(4)
              fsubp   st(1), st
            }
          }
          else
          {
            __asm
            {
             int 3
              //fld     [ebp+arg_0]
              fmul    st, st(3)
              //fld     [ebp+arg_4]
              fmul    st, st(3)
              fsubp   st(1), st
              fstp    dword ptr [eax+0Ch]
              //fld     [ebp+arg_0]
              fmul    st, st(2)
              //fld     [ebp+arg_4]
              fmul    st, st(4)
              faddp   st(1), st
            }
          }
          __asm
          {
            fstp    dword ptr [eax+10h]
            fstp    dword ptr [eax+14h]

            add eax, 48
          }
          --v3;
        }
        while ( v3 );
      }
    }
    __asm
    {
      fstp    st
      fstp    st
    }
  }
 else for (i = 0; i < uNumStructs; ++i)
   sub_481CCE((RenderVertex *)(a1 + i));
}

//----- (0043669D) --------------------------------------------------------
char __stdcall sub_43669D(int a1, int a2, int a3, signed int *a4, int a5, int a6, char a7)
{
  int v7; // esi@2
  int v8; // esi@2
  int v9; // ecx@3
  int v10; // ecx@5
  signed int *v11; // esi@5
  signed int v12; // esi@7
  int v14; // ecx@10
  int v15; // [sp+8h] [bp-4h]@3
  int v16; // [sp+14h] [bp+8h]@1
  int v17; // [sp+18h] [bp+Ch]@1
  int v18; // [sp+18h] [bp+Ch]@5
  int v19; // [sp+1Ch] [bp+10h]@2
  int v20; // [sp+1Ch] [bp+10h]@5
  int v21; // [sp+1Ch] [bp+10h]@10

  v16 = (a1 - dword_51B6E8) << 16;
  v17 = (a2 - dword_51B6EC) << 16;
  if ( dword_51B6F8 )
  {
    v8 = a3;
    v19 = dword_51B700;
    v7 = (v8 - dword_51B6F0) << 16;
    if ( pD3DRenderer->pRenderD3D3 )
    {
      v15 = ((unsigned __int64)(v16 * v19) >> 16) + ((unsigned __int64)(v17 * dword_51B704) >> 16);
      v9 = ((unsigned __int64)(v16 * dword_51B704) >> 16) - ((unsigned __int64)(v17 * dword_51B700) >> 16);
    }
    else
    {
      v15 = ((unsigned __int64)(v16 * v19) >> 16) - ((unsigned __int64)(v17 * dword_51B704) >> 16);
      v9 = ((unsigned __int64)(v16 * dword_51B704) >> 16) + ((unsigned __int64)(v17 * dword_51B700) >> 16);
    }
    v20 = v7;
    v18 = (unsigned __int64)(v7 * dword_51B70C) >> 16;
    v11 = a4;
    *a4 = ((unsigned __int64)(v15 * dword_51B708) >> 16) - v18;
    *(_DWORD *)a5 = v9;
    v10 = ((unsigned __int64)(v15 * dword_51B70C) >> 16) + ((unsigned __int64)(v20 * dword_51B708) >> 16);
  }
  else
  {
    v14 = a3;
    v21 = dword_51B700;
    v10 = (v14 - dword_51B6F0) << 16;
    if ( pD3DRenderer->pRenderD3D3 )
    {
      v11 = a4;
      *a4 = ((unsigned __int64)(v16 * v21) >> 16) + ((unsigned __int64)(v17 * dword_51B704) >> 16);
      *(_DWORD *)a5 = ((unsigned __int64)(v16 * dword_51B704) >> 16) - ((unsigned __int64)(v17 * dword_51B700) >> 16);
    }
    else
    {
      v11 = a4;
      *a4 = ((unsigned __int64)(v16 * v21) >> 16) - ((unsigned __int64)(v17 * dword_51B704) >> 16);
      *(_DWORD *)a5 = ((unsigned __int64)(v16 * dword_51B704) >> 16) + ((unsigned __int64)(v17 * dword_51B700) >> 16);
    }
  }
  *(_DWORD *)a6 = v10;
  return !a7 || (v12 = *v11, v12 >= 262144) && v12 <= 524288000;
}

//----- (00436932) --------------------------------------------------------
char __stdcall sub_436932_GetFacetOrientation(char a1, int a2, int a3, int a4)
{
  int v4; // eax@9
  double v5; // st7@9

  if ( a1 == 1 )
  {
    *(float *)a4 = -*(float *)(a2 + 4);
    *(_DWORD *)(a4 + 4) = *(_DWORD *)a2;
    *(float *)(a4 + 8) = 0.0;
LABEL_9:
    v4 = a3;
    *(float *)a3 = 0.0;
    *(float *)(a3 + 4) = 0.0;
    v5 = 1.0;
LABEL_11:
    *(float *)(v4 + 8) = v5;
    return 1;
  }
  if ( a1 == 3 || a1 == 5 )
  {
LABEL_10:
    *(float *)a4 = 1.0;
    *(float *)(a4 + 4) = 0.0;
    *(float *)(a4 + 8) = 0.0;
    v4 = a3;
    *(float *)a3 = 0.0;
    *(float *)(a3 + 4) = 1.0;
    v5 = 0.0;
    goto LABEL_11;
  }
  if ( a1 == 4 || a1 == 6 )
  {
    if ( fabs(*(float *)(a2 + 8)) < 0.7081136107444763 )
    {
      *(float *)a4 = -*(float *)(a2 + 4);
      *(_DWORD *)(a4 + 4) = *(_DWORD *)a2;
      *(float *)(a4 + 8) = 0.0;
      sub_4369DB(a4);
      goto LABEL_9;
    }
    goto LABEL_10;
  }
  return 1;
}

//----- (004369DB) --------------------------------------------------------
void __fastcall sub_4369DB(int a1)
{
  int v1; // esi@1
  double v2; // st7@1

  v1 = a1;
  v2 = memory_4D8410.d1_0
     / sqrt(*(float *)a1 * *(float *)a1 + *(float *)(a1 + 4) * *(float *)(a1 + 4) + *(float *)(a1 + 8)
                                                                                  * *(float *)(a1 + 8));
  *(float *)v1 = v2 * *(float *)v1;
  *(float *)(v1 + 4) = v2 * *(float *)(v1 + 4);
  *(float *)(v1 + 8) = v2 * *(float *)(v1 + 8);
}

//----- (00436A24) --------------------------------------------------------
int __stdcall sub_436A24(const char *Str1)
{
  return (int)LODFile_Bitmaps_LOD.pHardwareTextures[LODFile_Bitmaps_LOD.LODFile_LoadTexture( Str1, 0)];
}

//----- (00436A40) --------------------------------------------------------
double __stdcall sub_436A40(int a1, int a2)
{
  int v2; // edx@1
  double result; // st7@1
  double *v4; // ecx@2

  v2 = a2;
  result = 1.175494350822288e-38;
  if ( a2 > 0 )
  {
    v4 = (double *)(a1 + 8);
    do
    {
      if ( *(float *)v4 > result )
        result = *(float *)v4;
      v4 += 6;
      --v2;
    }
    while ( v2 );
  }
  return result;
}

//----- (00436A6D) --------------------------------------------------------
double __stdcall sub_436A6D(int a1, int a2)
{
  int v2; // edx@1
  double result; // st7@1
  double *v4; // ecx@2

  v2 = a2;
  result = 3.402823466385289e38;
  if ( a2 > 0 )
  {
    v4 = (double *)(a1 + 8);
    do
    {
      if ( *(float *)v4 < result )
        result = *(float *)v4;
      v4 += 6;
      --v2;
    }
    while ( v2 );
  }
  return result;
}

//----- (00436A9A) --------------------------------------------------------
int __thiscall class08_sub_436A9A(int _this, signed int a2, signed int a3, signed int a4, int a5, int a6)
{
  int result; // eax@2
  double v7; // ST00_8@2
  double v8; // ST08_8@2
  double v9; // ST00_8@2
  signed __int64 v10; // qtt@3
  int v11; // ST04_4@3
  float v12; // [sp+18h] [bp+8h]@2
  float v13; // [sp+18h] [bp+8h]@2

  if ( pD3DRenderer->pRenderD3D3 )
  {
    v7 = memory_4D8410.d1_0 / (double)a2;
    v12 = (double)a3 * *(float *)(_this + 196) * v7 + *(float *)(_this + 200);
    v8 = v12 + 6.755399441055744e15;
    *(_DWORD *)a5 = LODWORD(v8);
    v13 = (double)a4 * *(float *)(_this + 196) * v7 + *(float *)(_this + 204);
    v9 = v13 + 6.755399441055744e15;
    result = pOldViewport->uGameW - LODWORD(v9);
    *(_DWORD *)a6 = pOldViewport->uGameW - LODWORD(v9);
  }
  else
  {
    LODWORD(v10) = unk_51B720 << 16;
    HIDWORD(v10) = unk_51B720 >> 16;
    v11 = v10 / a2;
    LODWORD(v10) = unk_51B720 << 16;
    HIDWORD(v10) = unk_51B720 >> 16;
    *(_DWORD *)a5 = dword_51B754 - ((signed int)(((unsigned __int64)(v11 * a3) >> 16) + 32768) >> 16);
    result = a6;
    *(_DWORD *)a6 = dword_51B758 - ((signed int)(((unsigned __int64)(v10 / a2 * a4) >> 16) + 32768) >> 16);
  }
  return result;
}

//----- (00436CDC) --------------------------------------------------------
void __stdcall sub_436CDC(int a1, int a2, int a3, int a4)
{
  signed int v4; // esi@2
  int v5; // edx@5
  int v6; // eax@10
  int v7; // ecx@11
  double v8; // st6@11
  double v9; // st6@12
  int v10; // edi@14
  unsigned __int8 v11; // c2@16
  unsigned __int8 v12; // c3@16
  int v13; // edi@17
  int v15; // [sp+Ch] [bp+8h]@7

  if ( a2 )
  {
    *(_DWORD *)a4 = 0;
    memcpy((void *)(a1 + 48 * a2), (const void *)a1, 0x30u);
    v4 = 0;
    if ( *(float *)(a1 + 12) >= 8.0 )
      v4 = 1;
    if ( a2 + 1 > 1 )
    {
      v5 = a1 + 84;
      do
      {
        v15 = *(float *)(v5 - 24) >= 8.0;
        if ( v4 == v15 )
        {
          v7 = a3;
          goto LABEL_23;
        }
        v6 = *(_DWORD *)a4;
        if ( v15 )
        {
          v7 = a3;
          v8 = (8.0 - *(float *)(v5 - 72)) / (*(float *)(v5 - 24) - *(float *)(v5 - 72));
          *(float *)(48 * v6 + a3 + 16) = (*(float *)(v5 - 20) - *(float *)(v5 - 68)) * v8 + *(float *)(v5 - 68);
          *(float *)(48 * *(_DWORD *)a4 + a3 + 20) = (*(float *)(v5 - 16) - *(float *)(v5 - 64)) * v8
                                                   + *(float *)(v5 - 64);
          *(float *)(48 * *(_DWORD *)a4 + a3 + 36) = (*(float *)v5 - *(float *)(v5 - 48)) * v8 + *(float *)(v5 - 48);
          *(float *)(48 * *(_DWORD *)a4 + a3 + 40) = (*(float *)(v5 + 4) - *(float *)(v5 - 44)) * v8
                                                   + *(float *)(v5 - 44);
        }
        else
        {
          v9 = (8.0 - *(float *)(v5 - 24)) / (*(float *)(v5 - 72) - *(float *)(v5 - 24));
          *(float *)(48 * v6 + a3 + 16) = (*(float *)(v5 - 68) - *(float *)(v5 - 20)) * v9 + *(float *)(v5 - 20);
          *(float *)(48 * *(_DWORD *)a4 + a3 + 20) = (*(float *)(v5 - 64) - *(float *)(v5 - 16)) * v9
                                                   + *(float *)(v5 - 16);
          *(float *)(48 * *(_DWORD *)a4 + a3 + 36) = (*(float *)(v5 - 48) - *(float *)v5) * v9 + *(float *)v5;
          *(float *)(48 * *(_DWORD *)a4 + a3 + 40) = (*(float *)(v5 - 44) - *(float *)(v5 + 4)) * v9
                                                   + *(float *)(v5 + 4);
          v7 = a3;
        }
        *(float *)(48 * *(_DWORD *)a4 + v7 + 12) = 8.0;
        *(float *)(48 * *(_DWORD *)a4 + v7 + 32) = 0.125;
        if ( v4 )
        {
          v10 = 48 * *(_DWORD *)a4 + v7;
          if ( *(float *)(v10 + 12) != *(float *)(v5 - 72) || *(float *)(v10 + 16) != *(float *)(v5 - 68) )
            goto LABEL_21;
          v11 = 0;
          v12 = *(float *)(v10 + 20) == *(float *)(v5 - 64);
        }
        else
        {
          v13 = 48 * *(_DWORD *)a4 + v7;
          if ( *(float *)(v13 + 12) != *(float *)(v5 - 24) || *(float *)(v13 + 16) != *(float *)(v5 - 20) )
          {
LABEL_21:
            ++*(_DWORD *)a4;
            goto LABEL_23;
          }
          v11 = 0;
          v12 = *(float *)(v13 + 20) == *(float *)(v5 - 16);
        }
        if ( !(v12 | v11) )
          goto LABEL_21;
LABEL_23:
        if ( v15 )
        {
          memcpy((void *)(v7 + 48 * *(_DWORD *)a4), (const void *)(v5 - 36), 0x30u);
          *(float *)(48 * *(_DWORD *)a4++ + a3 + 32) = 1.0 / (*(float *)(v5 - 24) + 0.0000001000000011686097);
        }
        v4 = v15;
        v5 += 48;
      }
      while ( a2-- != 1 );
    }
    if ( *(_DWORD *)a4 < 3 )
      *(_DWORD *)a4 = 0;
  }
}

//----- (00436F09) --------------------------------------------------------
void __stdcall sub_436F09(int a1, int a2, int a3, int a4)
{
  int v4; // ebx@1
  signed int v5; // esi@2
  double v6; // st7@2
  int v7; // edx@5
  int v8; // eax@10
  int v9; // ecx@11
  double v10; // st6@11
  double v11; // st6@12
  int v12; // edi@14
  unsigned __int8 v13; // c2@16
  unsigned __int8 v14; // c3@16
  int v15; // edi@17
  int v17; // [sp+Ch] [bp+8h]@7
  int v18; // [sp+18h] [bp+14h]@5

  v4 = a4;
  *(_DWORD *)a4 = 0;
  if ( a2 )
  {
    memcpy((void *)(a1 + 48 * a2), (const void *)a1, 0x30u);
    v6 = (double)pStruct9_global->shading_dist_mist;
    v5 = 0;
    if ( v6 >= *(float *)(a1 + 12) )
      v5 = 1;
    if ( a2 + 1 > 1 )
    {
      v18 = a2;
      v7 = a1 + 84;
      do
      {
        v17 = v6 >= *(float *)(v7 - 24);
        if ( v5 == v17 )
        {
          v9 = a3;
          goto LABEL_23;
        }
        v8 = *(_DWORD *)v4;
        if ( v17 )
        {
          v9 = a3;
          v10 = (v6 - *(float *)(v7 - 72)) / (*(float *)(v7 - 24) - *(float *)(v7 - 72));
          *(float *)(48 * v8 + a3 + 16) = (*(float *)(v7 - 20) - *(float *)(v7 - 68)) * v10 + *(float *)(v7 - 68);
          *(float *)(48 * *(_DWORD *)v4 + a3 + 20) = (*(float *)(v7 - 16) - *(float *)(v7 - 64)) * v10
                                                   + *(float *)(v7 - 64);
          *(float *)(48 * *(_DWORD *)v4 + a3 + 36) = (*(float *)v7 - *(float *)(v7 - 48)) * v10 + *(float *)(v7 - 48);
          *(float *)(48 * *(_DWORD *)v4 + a3 + 40) = (*(float *)(v7 + 4) - *(float *)(v7 - 44)) * v10
                                                   + *(float *)(v7 - 44);
        }
        else
        {
          v11 = (v6 - *(float *)(v7 - 24)) / (*(float *)(v7 - 72) - *(float *)(v7 - 24));
          *(float *)(48 * v8 + a3 + 16) = (*(float *)(v7 - 68) - *(float *)(v7 - 20)) * v11 + *(float *)(v7 - 20);
          *(float *)(48 * *(_DWORD *)v4 + a3 + 20) = (*(float *)(v7 - 64) - *(float *)(v7 - 16)) * v11
                                                   + *(float *)(v7 - 16);
          *(float *)(48 * *(_DWORD *)v4 + a3 + 36) = (*(float *)(v7 - 48) - *(float *)v7) * v11 + *(float *)v7;
          *(float *)(48 * *(_DWORD *)v4 + a3 + 40) = (*(float *)(v7 - 44) - *(float *)(v7 + 4)) * v11
                                                   + *(float *)(v7 + 4);
          v9 = a3;
        }
        *(float *)(48 * *(_DWORD *)v4 + v9 + 12) = v6;
        *(float *)(48 * *(_DWORD *)v4 + v9 + 32) = 1.0 / v6;
        if ( v5 )
        {
          v12 = 48 * *(_DWORD *)v4 + v9;
          if ( *(float *)(v12 + 12) != *(float *)(v7 - 72) || *(float *)(v12 + 16) != *(float *)(v7 - 68) )
            goto LABEL_21;
          v13 = 0;
          v14 = *(float *)(v12 + 20) == *(float *)(v7 - 64);
        }
        else
        {
          v15 = 48 * *(_DWORD *)v4 + v9;
          if ( *(float *)(v15 + 12) != *(float *)(v7 - 24) || *(float *)(v15 + 16) != *(float *)(v7 - 20) )
          {
LABEL_21:
            ++*(_DWORD *)v4;
            goto LABEL_23;
          }
          v13 = 0;
          v14 = *(float *)(v15 + 20) == *(float *)(v7 - 16);
        }
        if ( !(v14 | v13) )
          goto LABEL_21;
LABEL_23:
        if ( v17 )
        {
          memcpy((void *)(v9 + 48 * *(_DWORD *)v4), (const void *)(v7 - 36), 0x30u);
          *(float *)(48 * *(_DWORD *)v4 + a3 + 32) = 1.0 / (*(float *)(v7 - 24) + 0.0000001000000011686097);
          *(float *)(48 * *(_DWORD *)v4++ + a3 + 44) = *(float *)(v7 + 8);
        }
        v5 = v17;
        v7 += 48;
      }
      while ( v18-- != 1 );
    }
    if ( *(_DWORD *)v4 < 3 )
      *(_DWORD *)v4 = 0;
  }
}

//----- (00437143) --------------------------------------------------------
int __stdcall sub_437143(int a1, int a2, int a3, int a4)
{
  int v4; // edi@1
  int v5; // eax@2
  int v6; // edx@2
  int v7; // ebx@2
  double v8; // st7@3
  double v9; // st6@3
  int result; // eax@5
  int v12; // [sp+10h] [bp+Ch]@2

  v4 = a1;
  if ( a1 > 0 )
  {
    v6 = a2 + 28;
    v5 = a3 + 32;
    v7 = a2 - a3;
    v12 = a1;
    do
    {
      *(float *)v5 = 1.0 / (*(float *)(v5 - 20) + 0.0000001000000011686097);
      memcpy((void *)(v6 - 28), (const void *)(v5 - 32), 0x30u);
      v8 = (double)pStruct9_global->dword_000014 * *(float *)(v7 + v5);
      v9 = (double)pOldViewport->dword_000028 - v8 * *(float *)(v5 - 16);
      v5 += 48;
      *(float *)(v6 - 4) = v9;
      *(float *)v6 = (double)pOldViewport->dword_00002C - v8 * *(float *)(v5 - 60);
      v6 += 48;
    }
    while ( v12-- != 1 );
    v4 = a1;
  }
  result = a4;
  *(_DWORD *)a4 = v4;
  return result;
}

//----- (004371C3) --------------------------------------------------------
char __thiscall sub_4371C3(void *_this, void *a2, int a3, int a4)
{
  _UNKNOWN *v4; // eax@2
  signed int v5; // ecx@2
  int v6; // edi@5
  void *v7; // esi@5
  int v8; // eax@6
  _UNKNOWN *v9; // ecx@6
  void *v11; // [sp+0h] [bp-Ch]@1
  int v12; // [sp+4h] [bp-8h]@5
  char *v13; // [sp+14h] [bp+8h]@6
  char *v14; // [sp+18h] [bp+Ch]@6

  v11 = _this;
  if ( !(byte_50F1E0 & 1) )
  {
    byte_50F1E0 |= 1u;
    v4 = &unk_50E60C[0];
    v5 = 64;
    do
    {
      *(float *)v4 = 0.0;
      v4 = (char *)v4 + 48;
      --v5;
    }
    while ( v5 );
   // atexit(0);
  }
  v12 = 0;
  v7 = a2;
  v6 = a3;
  if ( *(_DWORD *)a3 > 0 )
  {
    v14 = (char *)(&unk_50E5E0[0] - (char*)a2);
    v13 = (char *)(&unk_50E5FC[0] - (char*)a2);
    v9 = &unk_50E5E4[0];

    v8 = (int)((char *)v7 + 8);
    do
    {
      ++v12;
     // *((_DWORD *)v9 - 1) = *(_DWORD *)(v8 - 8);

     // *(_DWORD *)v9 = *(_DWORD *)(v8 - 4);

      v9 = (char *)v9 + 48;

      //*(float *)&v14[v8] = *(float *)v8;
     // *(float *)&v13[v8] = *(float *)(v8 + 28);

    //  *(float *)(&unk_50E600[0] - (char*)v7 + v8) = *(float *)(v8 + 32);

      v8 += 48;
    }
    while ( v12 < a3 );
  }
  return sub_437285((int)&unk_50E5E0[0], v6, v7, (int)((char *)v11 + 52), 4, 0, a4);
}

//----- (00437285) --------------------------------------------------------
char __stdcall sub_437285(int a1, int a2, void *a3, int a4, signed int a5, char a6, int a7)
{
  _UNKNOWN *v7; // eax@2
  signed int v8; // ecx@2
  signed int v9; // eax@5
  int v10; // ecx@5
  signed int v11; // ecx@6
  int v12; // esi@6
  void *v13; // eax@8
  int v14; // edx@8
  char v15; // zf@10
  char result; // al@14
  int v17; // [sp+18h] [bp-3Ch]@12
  float v18; // [sp+1Ch] [bp-38h]@12
  float v19; // [sp+20h] [bp-34h]@12
  float v20; // [sp+44h] [bp-10h]@1
  int v21; // [sp+48h] [bp-Ch]@5
  int v22; // [sp+4Ch] [bp-8h]@1
  int v23; // [sp+53h] [bp-1h]@5
  signed int v24; // [sp+70h] [bp+1Ch]@5

  v20 = 0.0;
  v22 = *(_DWORD *)(LODWORD(pGame) + 3672);
  if ( !(byte_50E5D8 & 1) )
  {
    byte_50E5D8 |= 1u;
    v7 = &unk_50DA04;
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
  v9 = 0;
  LOBYTE(v23) = 0;
  v10 = 2 * (a6 == 0) + 1;
  v24 = 0;
  v21 = v10;
  if ( a5 <= 0 )
  {
LABEL_14:
    result = v23;
  }
  else
  {
    v11 = *(_DWORD *)a2;
    v12 = a4 + 12;
    while ( 1 )
    {
      if ( v9 % 2 )
      {
        v13 = (void *)a1;
        v14 = (int)&unk_50D9D8;
      }
      else
      {
        v14 = a1;
        v13 = &unk_50D9D8;
      }
      v15 = v24++ + 1 == a5;
      if ( v15 )
        v13 = a3;
      *(float *)&v17 = *(float *)(v12 - 4);
      v18 = *(float *)v12;
      v19 = *(float *)(v12 + 4);
      sub_4985FB(v14, v11, v13, a2, (int)&v17, *(float *)(v12 + 8), (int)&v23, a7);
      v11 = *(_DWORD *)a2;
      if ( *(_DWORD *)a2 < v21 )
        break;
      v9 = v24;
      v12 += 24;
      if ( v24 >= a5 )
        goto LABEL_14;
    }
    *(_DWORD *)a2 = 0;
    result = 1;
  }
  return result;
}

//----- (00437376) --------------------------------------------------------
char __stdcall sub_437376(int a1, const void *a2, int *a3)
{
  int v3; // ebx@1
  const void *v4; // edx@2
  double v5; // st7@3
  int v6; // edi@5
  signed int v7; // esi@6
  int v8; // eax@8
  int v9; // ebx@8
  int v10; // ecx@14
  int v11; // eax@14
  int v12; // eax@15
  int v13; // ebx@17
  int v14; // eax@18
  int *v15; // eax@20
  char result; // al@24
  float v17; // [sp+Ch] [bp-34h]@2
  float v18; // [sp+10h] [bp-30h]@2
  float v19; // [sp+14h] [bp-2Ch]@2
  int v20; // [sp+3Ch] [bp-4h]@8
  signed int i; // [sp+48h] [bp+8h]@6
  char v22; // [sp+4Fh] [bp+Fh]@5

  v3 = *a3;
  if ( *a3 <= 3 )
    goto LABEL_28;
  v4 = a2;
  memcpy(&v17, a2, 0x30u);
  v5 = (v19 - (double)dword_51B6F0) * *(float *)(a1 + 12)
     + (v18 - (double)dword_51B6EC) * *(float *)(a1 + 8)
     + (v17 - (double)dword_51B6E8) * *(float *)(a1 + 4) < 0.0 ? 1.0 : -1.0;
  v22 = 0;
  memcpy((char *)v4 + 48 * v3, v4, 0x30u);
  memcpy((char *)v4 + 48 * (*a3 + 1), (char *)v4 + 48, 0x30u);
  v6 = *a3;
  if ( *a3 <= 0 )
    goto LABEL_28;
  v7 = 1;
  for ( i = 1; ; v7 = i )
  {
    v9 = v7 - 1;
    v8 = v7 + 1;
    v20 = v7 + 1;
    if ( v7 - 1 >= v6 )
      v9 -= v6;
    if ( v7 >= v6 )
      v7 -= v6;
    if ( v20 >= v6 )
      v8 = v20 - v6;
    v10 = (int)((char *)v4 + 48 * v8);
    v11 = (int)((char *)v4 + 48 * v9);
    if ( -(1.0 / 100.0) > ((*((float *)v4 + 12 * v7 + 6) - *(float *)(v11 + 24))
                                        * (*(float *)(v10 + 28) - *(float *)(v11 + 28))
                                        - (*((float *)v4 + 12 * v7 + 7) - *(float *)(v11 + 28))
                                        * (*(float *)(v10 + 24) - *(float *)(v11 + 24)))
                                       * v5 )
    {
      i = v20;
      v15 = a3;
    }
    else
    {
      v12 = i;
      if ( i >= v6 )
        v12 = i - v6;
      v13 = v12;
      if ( v12 < v6 )
      {
        v14 = (int)((char *)v4 + 48 * v12);
        do
        {
          memcpy((void *)v14, (const void *)(v14 + 48), 0x30u);
          ++v13;
          v14 += 48;
        }
        while ( v13 < *a3 );
      }
      v15 = a3;
      v22 = 1;
      --*v15;
    }
    v6 = *v15;
    if ( i - 1 >= *v15 )
      break;
  }
  if ( v22 )
    result = 1;
  else
LABEL_28:
    result = 0;
  return result;
}

//----- (004378BA) --------------------------------------------------------
void MatrixMultiply(struct Matrix *pM1, struct Matrix *pM2, struct Matrix *pResult)
{
 int i, j;

 for (i = 0; i < 3; ++i)
   for (j = 0; j < 3; ++j)
   {
    pResult->v[i][j] = pM1->v[i][0] * pM2->v[0][j] +
                       pM1->v[i][1] * pM2->v[1][j] +
                       pM1->v[i][2] * pM2->v[2][j];
   }
}

//----- (00437906) --------------------------------------------------------
char __thiscall sub_437906(void *_this, int a2, int a3)
{
  _UNKNOWN *v3; // eax@2
  signed int v4; // ecx@2
  signed int v5; // ebx@5
  int v6; // edx@6
  _UNKNOWN *v7; // esi@6
  int v8; // ecx@7
  void *v10; // [sp+8h] [bp-4h]@1

  v10 = _this;
  if ( !(byte_50D9D0 & 1) )
  {
    byte_50D9D0 |= 1u;
    v3 = &unk_50CDFC;
    v4 = 64;
    do
    {
      *(float *)v3 = 0.0;
      v3 = (char *)v3 + 48;
      --v4;
    }
    while ( v4 );
    atexit(0);
  }
  v5 = 0;
  if ( *(_BYTE *)(a2 + 93) )
  {
    v6 = dword_6BE63C;
    v7 = &unk_50CDD4;
    do
    {
      v8 = 2 * v5++;
      *((float *)v7 - 1) = (double)*(_WORD *)(v6 + 6 * *(_WORD *)(*(_DWORD *)(a2 + 48) + v8));
      *(float *)v7 = (double)*(_WORD *)(v6 + 6 * *(_WORD *)(*(_DWORD *)(a2 + 48) + v8) + 2);
      v7 = (char *)v7 + 48;
      *((float *)v7 - 11) = (double)*(_WORD *)(v6 + 6 * *(_WORD *)(*(_DWORD *)(a2 + 48) + v8) + 4);
      *((float *)v7 - 4) = (double)*(_WORD *)(*(_DWORD *)(a2 + 64) + v8);
      *((float *)v7 - 3) = (double)*(_WORD *)(*(_DWORD *)(a2 + 68) + v8);
    }
    while ( v5 < *(_BYTE *)(a2 + 93) );
  }
  return sub_4379EE(v10, (int)&unk_50CDD0, *(_BYTE *)(a2 + 93), a3, 0.0);
}

//----- (004379EE) --------------------------------------------------------
char __thiscall sub_4379EE(void *_this, int a2, int a3, int a4, float a5)
{
  int v5; // esi@1
  int v6; // eax@2
  int v7; // edi@3
  char v8; // zf@3
  void *v10; // [sp+10h] [bp-4h]@1
  int v11; // [sp+20h] [bp+Ch]@2

  v10 = _this;
  v5 = 0;
  if ( a3 - 1 > 0 )
  {
    v6 = a2;
    v5 = a3 - 1;
    v11 = a3 - 1;
    do
    {
      v7 = v6 + 48;
      sub_437AB5(v10, v6, a4, v6 + 48, a4, 0, a5);
      v8 = v11-- == 1;
      v6 = v7;
    }
    while ( !v8 );
  }
  return sub_437AB5(v10, a2 + 48 * v5, a4, a2, a4, 0, a5);
}

//----- (00437A55) --------------------------------------------------------
void *__stdcall sub_437A55(const void *a1, int a2, int a3, float a4)
{
  int v4; // esi@1
  const void *v5; // ecx@2
  int v6; // ebx@2
  int v7; // edi@3

  v4 = 0;
  if ( a2 - 1 > 0 )
  {
    v5 = a1;
    v6 = a2 - 1;
    v4 = a2 - 1;
    do
    {
      v7 = (int)((char *)v5 + 32);
      sub_437C96(v5, a3, (char *)v5 + 32, a3, a4);
      --v6;
      v5 = (const void *)v7;
    }
    while ( v6 );
  }
  return sub_437C96((char *)a1 + 32 * v4, a3, a1, a3, a4);
}

//----- (00437AB5) --------------------------------------------------------
char __thiscall sub_437AB5(void *_this, int a2, int a3, int a4, int a5, signed int a6, float a7)
{
  char *v7; // eax@2
  signed int v8; // edx@2
  int v9; // ecx@5
  int v10; // eax@5
  char *v11; // eax@6
  signed int v12; // edx@6
  char result; // al@8
  int v14; // edx@8
  int v15; // eax@8
  int v16; // eax@8
  double v17; // st7@11
  int v18; // eax@11
  char v19; // [sp-18h] [bp-7E4h]@12
  int v20; // [sp-14h] [bp-7E0h]@12
  int v21; // [sp-10h] [bp-7DCh]@12
  int v22; // [sp-Ch] [bp-7D8h]@8
  const char *v23; // [sp-8h] [bp-7D4h]@8
  int v24; // [sp-4h] [bp-7D0h]@8
  int v25; // [sp+8h] [bp-7C4h]@8
  int v26; // [sp+Ch] [bp-7C0h]@8
  int v27; // [sp+10h] [bp-7BCh]@8
  char v28; // [sp+34h] [bp-798h]@6
  int v29; // [sp+38h] [bp-794h]@8
  int v30; // [sp+3Ch] [bp-790h]@8
  int v31; // [sp+40h] [bp-78Ch]@8
  char v32; // [sp+3C8h] [bp-404h]@8
  int v33; // [sp+3E0h] [bp-3ECh]@5
  int v34; // [sp+3E4h] [bp-3E8h]@5
  char v35; // [sp+3F4h] [bp-3D8h]@2
  int v36; // [sp+410h] [bp-3BCh]@5
  int v37; // [sp+414h] [bp-3B8h]@5
  int v38; // [sp+788h] [bp-44h]@11
  int v39; // [sp+78Ch] [bp-40h]@11
  float v40; // [sp+790h] [bp-3Ch]@11
  float v41; // [sp+794h] [bp-38h]@11
  int v42; // [sp+798h] [bp-34h]@11
  int v43; // [sp+79Ch] [bp-30h]@11
  float v44; // [sp+7A0h] [bp-2Ch]@11
  float v45; // [sp+7A4h] [bp-28h]@11
  int v46; // [sp+7A8h] [bp-24h]@11
  int v47; // [sp+7ACh] [bp-20h]@11
  float v48; // [sp+7B0h] [bp-1Ch]@11
  float v49; // [sp+7B4h] [bp-18h]@11
  int v50; // [sp+7B8h] [bp-14h]@11
  int v51; // [sp+7BCh] [bp-10h]@11
  float v52; // [sp+7C0h] [bp-Ch]@11
  float v53; // [sp+7C4h] [bp-8h]@11
  void *v54; // [sp+7C8h] [bp-4h]@1

  v54 = _this;
  if ( pD3DRenderer->pRenderD3D3 )
  {
    v7 = &v35;
    v8 = 20;
    do
    {
      *(float *)v7 = 0.0;
      v7 += 48;
      --v8;
    }
    while ( v8 );
    if ( (_BYTE)a6 )
    {
      v9 = *(_DWORD *)(a2 + 24);
      v34 = *(_DWORD *)(a2 + 28);
      v33 = v9;
      v10 = *(_DWORD *)(a4 + 28);
      v36 = *(_DWORD *)(a4 + 24);
      v37 = v10;
LABEL_11:
      v17 = 0.001000000047497451 - a7;
      v43 = 0;
      v38 = v33;
      v39 = v34;
      v40 = v17;
      v42 = a3;
      v41 = 0.001000000047497451;
      v46 = v36;
      v44 = 0.0;
      v47 = v37;
      v45 = 0.0;
      v50 = a5;
      v48 = v17;
      v51 = 0;
      v24 = 0;
      v49 = 0.001000000047497451;
      v23 = 0;
      v52 = 0.0;
      v53 = 0.0;
      v22 = *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56);
      (*(void (**)(void))(*(_DWORD *)v22 + 152))();
      v18 = (*(int (__stdcall **)(_DWORD, signed int, signed int, int *, signed int, signed int, _DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 112))(
              *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
              2,
              452,
              &v38,
              2,
              16,
              (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Core3D.cpp",
              1379,
              0);
      return (unsigned int)CheckHRESULT((void **)&a6, v18, (const char *)v22, 0, 0);
    }
    v11 = &v28;
    v12 = 20;
    do
    {
      *(float *)v11 = 0.0;
      v11 += 48;
      --v12;
    }
    while ( v12 );
    v24 = 0;
    v23 = (const char *)1;
    v22 = 4;
    v14 = *(_DWORD *)a2;
    a6 = 2;
    v25 = v14;
    v15 = *(_DWORD *)(a2 + 8);
    v26 = *(_DWORD *)(a2 + 4);
    v27 = v15;
    v29 = *(_DWORD *)a4;
    v16 = *(_DWORD *)(a4 + 8);
    v30 = *(_DWORD *)(a4 + 4);
    v31 = v16;
    result = sub_437285((int)&v25, (int)&a6, &v32, (int)((char *)_this + 52), 4, 1, 0);
    if ( result != 1 || a6 >= 2 )
    {
      sub_436523((RenderVertex *)&v32, 2);
      class08_sub_436BB7((class08 *)v54, (RenderVertex *)&v32, 2, 0);
      goto LABEL_11;
    }
  }
  else
  {
    v24 = 1383;
    v23 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Core3D.cpp";
    a6 = (signed int)&v19;
    Game_sub_40E2C8(&v19, "draw_debug_line() not implemented for SW rendering", (int)((char *)&a6 + 3));
    result = (unsigned int)sub_466D09(&a2, *(int *)&v19, v20, v21, v22, v23, v24);
  }
  return result;
}

//----- (00437C96) --------------------------------------------------------
void *__stdcall sub_437C96(const void *a1, int a2, const void *a3, int a4, float a5)
{
  void *result; // eax@2
  double v6; // st7@2
  int v7; // eax@2
  int v8; // eax@2
  char v9; // [sp-18h] [bp-60h]@3
  int v10; // [sp-14h] [bp-5Ch]@3
  int v11; // [sp-10h] [bp-58h]@3
  int v12; // [sp-Ch] [bp-54h]@2
  const char *v13; // [sp-8h] [bp-50h]@2
  int v14; // [sp-4h] [bp-4Ch]@2
  char v15; // [sp+8h] [bp-40h]@2
  float v16; // [sp+10h] [bp-38h]@2
  int v17; // [sp+18h] [bp-30h]@2
  char v18; // [sp+28h] [bp-20h]@2
  float v19; // [sp+30h] [bp-18h]@2
  int v20; // [sp+38h] [bp-10h]@2

  if ( pD3DRenderer->pRenderD3D3 )
  {
    v6 = 0.001000000047497451 - a5;
    memcpy(&v15, a1, 0x20u);
    memcpy(&v18, a3, 0x20u);
    v16 = v6;
    v19 = v6;
    v14 = 0;
    v17 = a2;
    v20 = a4;
    v7 = *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56);
    v13 = 0;
    v12 = v7;
    (*(void (**)(void))(*(_DWORD *)v7 + 152))();
    v8 = (*(int (__stdcall **)(_DWORD, signed int, signed int, char *, signed int, signed int, _DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 112))(
           *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
           2,
           452,
           &v15,
           2,
           16,
           (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Core3D.cpp",
           1411,
           0);
    result = CheckHRESULT((void **)&a1, v8, (const char *)v12, 0, 0);
  }
  else
  {
    v14 = 1415;
    v13 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Core3D.cpp";
    a1 = &v9;
    Game_sub_40E2C8(&v9, "draw_debug_line() not implemented for SW rendering", (int)((char *)&a1 + 3));
    result = sub_466D09(&a3, *(int *)&v9, v10, v11, v12, v13, v14);
  }
  return result;
}

//----- (00437D4A) --------------------------------------------------------
void __thiscall sub_437D4A(void *_this, int a2, int a3, int a4, int a5, char a6, float a7)
{
  char *v7; // eax@1
  void *v8; // edx@1
  signed int v9; // ecx@1
  signed int v10; // edx@10
  char *v11; // ecx@10
  signed int v12; // edi@16
  int *v13; // ecx@24
  unsigned int v14; // eax@25
  unsigned int v15; // edx@25
  int v16; // ebx@25
  int v17; // eax@26
  int v18; // edx@26
  const char *v19; // ST24_4@27
  int v20; // eax@27
  int v21; // [sp+0h] [bp-680h]@6
  int v22; // [sp+4h] [bp-67Ch]@9
  int v23; // [sp+8h] [bp-678h]@9
  char v24; // [sp+Ch] [bp-674h]@10
  float v25; // [sp+18h] [bp-668h]@4
  float v26; // [sp+1Ch] [bp-664h]@4
  char v27; // [sp+2Ch] [bp-654h]@1
  float v28; // [sp+3C0h] [bp-2C0h]@15
  float v29; // [sp+3C4h] [bp-2BCh]@15
  signed int v30; // [sp+3C8h] [bp-2B8h]@16
  signed int v31; // [sp+3CCh] [bp-2B4h]@16
  int v32; // [sp+3D0h] [bp-2B0h]@15
  int v33; // [sp+3D4h] [bp-2ACh]@15
  float v34; // [sp+3D8h] [bp-2A8h]@16
  float v35; // [sp+3DCh] [bp-2A4h]@16
  float v36; // [sp+3E0h] [bp-2A0h]@16
  float v37; // [sp+3E4h] [bp-29Ch]@16
  float v38; // [sp+3E8h] [bp-298h]@16
  float v39; // [sp+3ECh] [bp-294h]@16
  int v40; // [sp+3F0h] [bp-290h]@16
  int v41; // [sp+3F4h] [bp-28Ch]@16
  float v42; // [sp+3F8h] [bp-288h]@16
  float v43; // [sp+3FCh] [bp-284h]@16
  float v44; // [sp+400h] [bp-280h]@16
  float v45; // [sp+404h] [bp-27Ch]@16
  float v46; // [sp+408h] [bp-278h]@16
  float v47; // [sp+40Ch] [bp-274h]@16
  int v48; // [sp+410h] [bp-270h]@16
  int v49; // [sp+414h] [bp-26Ch]@16
  float v50; // [sp+418h] [bp-268h]@16
  float v51; // [sp+41Ch] [bp-264h]@16
  float v52; // [sp+420h] [bp-260h]@16
  float v53; // [sp+424h] [bp-25Ch]@16
  float v54; // [sp+428h] [bp-258h]@16
  float v55; // [sp+42Ch] [bp-254h]@16
  int v56; // [sp+430h] [bp-250h]@16
  int v57; // [sp+434h] [bp-24Ch]@16
  float v58; // [sp+438h] [bp-248h]@16
  float v59; // [sp+43Ch] [bp-244h]@16
  float v60; // [sp+440h] [bp-240h]@16
  float v61; // [sp+444h] [bp-23Ch]@16
  float v62; // [sp+448h] [bp-238h]@16
  float v63; // [sp+44Ch] [bp-234h]@16
  int v64; // [sp+450h] [bp-230h]@16
  int v65; // [sp+454h] [bp-22Ch]@16
  float v66; // [sp+458h] [bp-228h]@16
  float v67; // [sp+45Ch] [bp-224h]@16
  int v68; // [sp+640h] [bp-40h]@5
  int v69; // [sp+644h] [bp-3Ch]@5
  int v70; // [sp+648h] [bp-38h]@5
  float v71; // [sp+66Ch] [bp-14h]@1
  double v72; // [sp+670h] [bp-10h]@25
  double v73; // [sp+678h] [bp-8h]@25
  void *v74; // [sp+67Ch] [bp-4h]@1

  v8 = _this;
  v71 = 0.0;
  v74 = _this;
  v7 = &v27;
  v9 = 20;
  do
  {
    *(float *)v7 = 0.0;
    v7 += 48;
    --v9;
  }
  while ( v9 );
  if (LOBYTE(a7) )
  {
    LODWORD(v25) = a2;
    LODWORD(v26) = a3;
LABEL_15:
    v28 = v25;
    v29 = v26;
    v33 = 0;
    v32 = a5;
    if ( a6 )
    {
      *(float *)&v30 = 0.00009999999747378752;
      v36 = v25;
      v44 = v25;
      *(float *)&v31 = 0.001000000047497451;
      v12 = 5;
      v34 = 0.0;
      v40 = a5;
      v41 = 0;
      v35 = 0.0;
      v48 = a5;
      v49 = 0;
      v53 = v26;
      v56 = a5;
      v57 = 0;
      v61 = v26;
      v37 = v26 - 1.0;
      v64 = a5;
      v65 = 0;
      v38 = 0.00009999999747378752;
      v39 = 0.001000000047497451;
      v42 = 0.0;
      v43 = 0.0;
      v45 = v26 + 1.0;
      v46 = 0.00009999999747378752;
      v47 = 0.001000000047497451;
      v50 = 0.0;
      v51 = 0.0;
      v52 = v25 - 1.0;
      v54 = 0.00009999999747378752;
      v55 = 0.001000000047497451;
      v58 = 0.0;
      v59 = 0.0;
      v60 = v25 + 1.0;
      v62 = 0.00009999999747378752;
      v63 = 0.001000000047497451;
      v66 = 0.0;
      v67 = 0.0;
    }
    else
    {
      v12 = 1;
      v30 = 953267991;
      v34 = 0.0;
      v31 = 981668463;
      v35 = 0.0;
    }
    if ( pD3DRenderer->pRenderD3D3 )
    {
      v19 = *(const char **)(pD3DRenderer->pRenderD3D3 + 56);
      (*(void (**)(void))(*(_DWORD *)v19 + 152))();
      v20 = (*(int (__stdcall **)(_DWORD, signed int, signed int, float *, signed int, signed int, _DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 112))(
              *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
              1,
              452,
              &v28,
              v12,
              16,
              (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Core3D.cpp",
              1548,
              0);
      CheckHRESULT((void **)&a7, v20, v19, 0, 0);
    }
    else
    {
      if ( (double)pOldViewport->uGameX <= v25 - 1.0 )
      {
        if ( (double)pOldViewport->uGameZ > v25 + 2.0 )
        {
          if ( (double)pOldViewport->uGameY <= v26 - 1.0 )
          {
            if ( (double)pOldViewport->uGameW > v26 + 2.0 )
            {
              if ( v12 > 0 )
              {
                v13 = &v32;
                do
                {
                  LODWORD(a7) = *(v13 - 3);
                  v73 = a7 + 6.755399441055744e15;
                  v72 = *((float *)v13 - 4) + 6.755399441055744e15;
                  v15 = *v13;
                  v14 = *v13;
                  v16 = ((unsigned int)*v13 >> 3) & 0x1F;
                  if ( pD3DRenderer->uNumTargetGBits == 5 )
                  {
                    v17 = (v14 >> 6) & 0x3E0;
                    v18 = (v15 >> 9) & 0x7C00;
                  }
                  else
                  {
                    v17 = (v14 >> 5) & 0x7E0;
                    v18 = (v15 >> 8) & 0xF800;
                  }
                  v13 += 8;
                  --v12;
                  pD3DRenderer->pTargetSurface[(LODWORD(v72) + pD3DRenderer->uTargetSurfacePitch * LODWORD(v73))] = v18 | v16 | (_WORD)v17;
                }
                while ( v12 );
              }
            }
          }
        }
      }
    }
    return;
  }
  v68 = a2;
  v69 = a3;
  v70 = a4;
  if ( pD3DRenderer->pRenderD3D3 )
  {
    LODWORD(a7) = 1;
    if ( sub_437285((int)&v68, (int)&a7, &v21, (int)((char *)v8 + 52), 4, 1, 0) == 1 && LODWORD(a7) < 1 )
      return;
  }
  else
  {
    v21 = a2;
    v22 = a3;
    v23 = a4;
  }
  sub_436523((RenderVertex *)&v21, 1);
  v10 = 0;
  v11 = &v24;
  do
  {
    if ( *(float *)v11 >= 8.0 )
      break;
    ++v10;
    v11 += 48;
  }
  while ( v10 < 1 );
  if ( v10 < 1 )
  {
    class08_sub_436BB7((class08 *)v74, (RenderVertex *)&v21, 1, 0);
    goto LABEL_15;
  }
}

//----- (00438250) --------------------------------------------------------
void class08_sub_438250(struct class08 *_this)
{
 _this->dword_0E037C = 0;
}

//----- (00438258) --------------------------------------------------------
char __stdcall sub_438258(int a1, int a2)
{
  char result; // al@2

  if ( (*(float *)(a2 + 8) - (double)pOldCamera->dword_000008) * (double)*(signed int *)(a1 + 24)
     + (*(float *)(a2 + 4) - (double)pOldCamera->dword_000004) * (double)*(signed int *)(a1 + 20)
     + (*(float *)a2 - (double)pOldCamera->dword_000000) * (double)*(signed int *)(a1 + 16) < 0.0
    || (result = 1, *(_BYTE *)(a1 + 44) & 1) )
    result = 0;
  return result;
}

//----- (004382BC) --------------------------------------------------------
//depricated

//----- (004383ED) --------------------------------------------------------
//int __usercall sub_4383ED<eax>(int a1<ebx>)
int __fastcall sub_4383ED()
{
 unsigned char pVendor[16];
  int v28; // [sp+30h] [bp-4h]@1

 __asm
 {
  xor eax, eax
  cpuid
  mov dword ptr [pVendor], ebx
  mov dword ptr [pVendor + 4], edx
  mov dword ptr [pVendor + 8], ecx
  mov dword ptr [pVendor + 12], 0
 }

 if (lstrcmpA((const char *)pVendor, "GenuineIntel"))
   bNotIntelCPU = true;

 __asm
 {
  xor eax, eax
  inc eax
  cpuid

  mov dword ptr [v28], edx
 }

 return v28;
}

//----- (0043847A) --------------------------------------------------------
function_error;//__int16 __usercall sub_43847A<ax>(int a1<ebx>)
__int16 __fastcall sub_43847A()
{
 unsigned int  v0;
 unsigned char pVendor[16];

  int v22; // [sp+2Eh] [bp-6h]@1
  char v23; // [sp+32h] [bp-2h]@6
  char v24; // [sp+33h] [bp-1h]@1



 {
  __asm
  {
   xor eax, eax
   cpuid
   mov dword ptr [pVendor], ebx
   mov dword ptr [pVendor + 4], edx
   mov dword ptr [pVendor + 8], ecx
   mov dword ptr [pVendor + 12], 0
  }
 }

 if (lstrcmpA((const char *)pVendor, "GenuineIntel"))
   bNotIntelCPU = true;

 __asm
 {
  xor eax, eax
  inc eax
  cpuid

  mov dword ptr [v0], eax
 }
 v24 = (v0 & 0x00F);
 v23 = (v0 & 0x0F0) >> 4;
 v22 = (v0 & 0xF00) >> 8;

 return v22;
}

//----- (00438659) --------------------------------------------------------
void *class11_fn1(class11 *_this, int a2)
{
  unsigned int v2; // edi@1
  int v3; // esi@1
  int result; // eax@14
  int v11; // ebx@14
  int v15; // edi@16
  int v31[4]; // [sp+Ch] [bp-60h]@1
  int v32; // [sp+10h] [bp-5Ch]@1
  int v33; // [sp+14h] [bp-58h]@1
  char v34; // [sp+18h] [bp-54h]@1
  int v35[4]; // [sp+1Ch] [bp-50h]@1
  int v36; // [sp+20h] [bp-4Ch]@1
  int v37; // [sp+24h] [bp-48h]@1
  char v38; // [sp+28h] [bp-44h]@1
  int v39[4]; // [sp+2Ch] [bp-40h]@1
  int v40; // [sp+30h] [bp-3Ch]@1
  int v41; // [sp+34h] [bp-38h]@1
  char v42; // [sp+38h] [bp-34h]@1
  int Str1[4]; // [sp+3Ch] [bp-30h]@1
  int v44; // [sp+40h] [bp-2Ch]@1
  int v45; // [sp+44h] [bp-28h]@1
  char v46; // [sp+48h] [bp-24h]@1
  char Str2[4]; // [sp+4Ch] [bp-20h]@1
  int v48; // [sp+50h] [bp-1Ch]@1
  int v49; // [sp+54h] [bp-18h]@1
  char v50; // [sp+58h] [bp-14h]@1
  int v51; // [sp+5Ch] [bp-10h]@1
  char *v52; // [sp+60h] [bp-Ch]@1
  int v53; // [sp+64h] [bp-8h]@1
  int v54; // [sp+68h] [bp-4h]@1

  v51 = (int)_this;
  Str1[0] = *(_DWORD *)"GenuineIntel";
  v44 = *(_DWORD *)&"GenuineIntel"[4];
  v45 = *(_DWORD *)&"GenuineIntel"[8];
  v46 = "GenuineIntel"[12];
  v39[0] = *(_DWORD *)"AuthenticAMD";
  v40 = *(_DWORD *)&"AuthenticAMD"[4];
  v41 = *(_DWORD *)&"AuthenticAMD"[8];
  v42 = "AuthenticAMD"[12];
  v31[0] = *(_DWORD *)"CyrixInstead";
  v32 = *(_DWORD *)&"CyrixInstead"[4];
  v33 = *(_DWORD *)&"CyrixInstead"[8];
  v34 = "CyrixInstead"[12];
  v35[0] = *(_DWORD *)"CentaurHauls";
  v36 = *(_DWORD *)&"CentaurHauls"[4];
  v37 = *(_DWORD *)&"CentaurHauls"[8];
  v54 = 0;
  v53 = 0;
  v38 = "CentaurHauls"[12];
  v52 = Str2;
  v50 = 0;
  compile_error();//_EAX = 0;
  __asm { cpuid }
  compile_error();//v54 = _EAX;
  *(_DWORD *)Str2 = a2;
  compile_error();//v48 = _EDX;
  compile_error();//v49 = _ECX;
  v3 = v51;
  compile_error();//v2 = _EAX;
  *(_DWORD *)(v51 + 4) = a2;
  *(_DWORD *)(v3 + 8) = v48;
  *(_DWORD *)(v3 + 12) = v49;
  compile_error();//*(_DWORD *)v3 = _EAX;
  strcpy((char *)(v3 + 16), Str2);
  if ( strcmp((const char *)Str1, Str2) )
  {
    if ( strcmp((const char *)v39, Str2) )
    {
      if ( strcmp((const char *)v31, Str2) )
      {
        if ( strcmp((const char *)v35, Str2) )
          *(_DWORD *)(v3 + 176) = 0;
        else
          *(_DWORD *)(v3 + 176) = 4;
      }
      else
      {
        *(_DWORD *)(v3 + 176) = 3;
      }
    }
    else
    {
      *(_DWORD *)(v3 + 176) = 2;
    }
  }
  else
  {
    *(_DWORD *)(v3 + 176) = 1;
  }
  if ( v2 >= 1 )
    sub_438821((void *)v3);
  if ( v2 >= 2 )
    sub_438992(v3, 2);
  compile_error();//_EAX = -2147483648;
  __asm { cpuid }
  v11 = result & 0x80000000;
  if ( !(result & 0x80000000) )
    result = -2147483648;
  v53 = result;
  *(_DWORD *)(v3 + 96) = result;
  v15 = result ^ 0x80000000;
  if ( (result ^ 0x80000000u) >= 1 )
  {
    compile_error();//_EAX = -2147483647;
    __asm { cpuid }
    compile_error();//v51 = _EAX;
    compile_error();//v52 = (char *)_EDX;
    compile_error();//*(_DWORD *)(v3 + 100) = _EAX;
    result = (int)v52;
    *(_DWORD *)(v3 + 104) = (int)v52;
  }
  if ( (unsigned int)v15 >= 4 )
    result = sub_438A67(v3, v11);
  if ( (unsigned int)v15 >= 5 )
  {
    compile_error();//_EAX = -2147483643;
    __asm { cpuid }
    v51 = v11;
    compile_error();//v52 = (char *)_ECX;
    compile_error();//v53 = _EDX;
    *(_DWORD *)(v3 + 156) = v11;
    *(_DWORD *)(v3 + 160) = (int)v52;
    result = v53;
    *(_DWORD *)(v3 + 164) = v53;
  }
  if ( (unsigned int)v15 >= 6 )
  {
    compile_error();//_EAX = -2147483642;
    __asm { cpuid }
    compile_error();//result = _ECX;
    compile_error();//*(_DWORD *)(v3 + 168) = _ECX;
  }
  return (void *)result;
}

//----- (00438821) --------------------------------------------------------
int __thiscall sub_438821(void *_this)
{
  unsigned int v2; // ecx@1
  void *v3; // esi@1
  int v8; // eax@3
  int result; // eax@10
  int v10; // ecx@11
  int v11; // ecx@19
  signed int v12; // eax@25
  int v13; // ecx@25
  int v14; // ecx@34

  v3 = _this;
  compile_error();//_EAX = 1;
  __asm { cpuid }
  compile_error();//v2 = _EAX;
  compile_error();//*((_DWORD *)v3 + 9) = _EDX;
  compile_error();//*((_DWORD *)v3 + 8) = _EAX;

  compile_error();//if ( (_EAX & 0x3000) == 8192 )
  if (1)
  {
    *((_BYTE *)v3 + 180) = 1;
    v2 = 0;
  }
  v8 = (v2 >> 8) & 0xF;
  switch ( v8 )
  {
    case 4:
      *((_DWORD *)v3 + 43) = 2;
      break;
    case 5:
      *((_DWORD *)v3 + 43) = 15;
      break;
    case 6:
      *((_DWORD *)v3 + 43) = 36;
      break;
    default:
      *((_DWORD *)v3 + 43) = 49;
      break;
  }
  result = *((_DWORD *)v3 + 44);
  if ( result == 1 )
  {
    result = 0;
    v10 = v2 & 0x3FF0;
    while ( v10 != dword_4E4948[2 * result] )
    {
      ++result;
      if ( result >= 17 )
        return result;
    }
    result = dword_4E4948[2 * result + 1];
    goto LABEL_39;
  }
  if ( result == 2 )
  {
    if ( (v2 & 0xF00) == dword_4E49D0[0] )
    {
      result = dword_4E49D0[1];
    }
    else
    {
      result = 1;
      v11 = v2 & 0x3FF0;
      while ( v11 != dword_4E49D0[2 * result] )
      {
        ++result;
        if ( result >= 9 )
          return result;
      }
      result = dword_4E49D0[2 * result + 1];
    }
    goto LABEL_39;
  }
  if ( result != 3 )
  {
    if ( result != 4 )
      return result;
    result = 0;
    v14 = v2 & 0x3FF0;
    while ( v14 != dword_4E4A40[2 * result] )
    {
      ++result;
      if ( result >= 2 )
        return result;
    }
    result = dword_4E4A40[2 * result + 1];
    goto LABEL_39;
  }
  v12 = 1;
  v13 = v2 & 0x3FF0;
  while ( v13 != dword_4E4A18[2 * v12] )
  {
    ++v12;
    if ( v12 >= 5 )
      goto LABEL_30;
  }
  *((_DWORD *)v3 + 43) = dword_4E4A18[2 * v12 + 1];
LABEL_30:
  result = 24;
  if ( *((_DWORD *)v3 + 43) == 24 )
  {
    compile_error();//if ( _EDX != 1 )
      compile_error();//result = (((_EDX != 261) - 1) & 0xA) + 15;
LABEL_39:
    *((_DWORD *)v3 + 43) = result;
  }
  return result;
}
// 438821: too many cbuild loops

//----- (00438992) --------------------------------------------------------
function_error;//char __usercall sub_438992<al>(int a1<ecx>, int a2<ebx>)
char __fastcall sub_438992(int a1, int a2)
{
  int v2; // eax@1
  int v3; // edi@1
  int *v5; // esi@1
  signed int v10; // ecx@2
  signed int v11; // ecx@14
  int v13; // [sp+Ch] [bp-14h]@1
  int v14; // [sp+10h] [bp-10h]@1
  int v15; // [sp+14h] [bp-Ch]@1
  int v16; // [sp+18h] [bp-8h]@1
  int *v17; // [sp+1Ch] [bp-4h]@1

  v3 = a1;
  v17 = &v13;
  compile_error();//_EAX = 2;
  v5 = &v13;
  __asm { cpuid }
  compile_error();//*v5 = _EAX;
  v14 = a2;
  compile_error();//v15 = _ECX;
  compile_error();//v16 = _EDX;
  *(_DWORD *)(v3 + 40) = v13;
  *(_DWORD *)(v3 + 44) = v14;
  *(_DWORD *)(v3 + 48) = v15;
  *(_DWORD *)(v3 + 52) = v16;
  v2 = *(_DWORD *)(v3 + 172);
  if ( v2 == 40 )
  {
    v10 = 0;
    while ( 1 )
    {
      LOBYTE(v2) = *((_BYTE *)&v13 + v10);
      if ( (_BYTE)v2 == 64 )
      {
        *(_DWORD *)(v3 + 172) = 43;
        return v2;
      }
      if ( (_BYTE)v2 >= 0x41u && (_BYTE)v2 <= 0x43u )
      {
        *(_DWORD *)(v3 + 172) = 41;
        return v2;
      }
      if ( (_BYTE)v2 >= 0x44u && (_BYTE)v2 <= 0x45u )
        break;
      ++v10;
      if ( v10 >= 16 )
        return v2;
    }
    *(_DWORD *)(v3 + 172) = 42;
  }
  else
  {
    if ( v2 == 45 )
    {
      v11 = 0;
      while ( 1 )
      {
        LOBYTE(v2) = *((_BYTE *)&v13 + v11);
        if ( (_BYTE)v2 >= 0x40u && (_BYTE)v2 <= 0x43u )
        {
          *(_DWORD *)(v3 + 172) = 46;
          return v2;
        }
        if ( (_BYTE)v2 >= 0x44u && (_BYTE)v2 <= 0x45u )
          break;
        ++v11;
        if ( v11 >= 16 )
          return v2;
      }
      *(_DWORD *)(v3 + 172) = 47;
    }
  }
  return v2;
}

//----- (00438A67) --------------------------------------------------------
function_error;//int __usercall sub_438A67<eax>(int a1<ecx>, int a2<ebx>)
int __fastcall sub_438A67(int a1, int a2)
{
  int result; // eax@1
  int v3; // edi@1
  char *v5; // esi@1
  char *v10; // esi@1
  char *v16; // esi@1
  char v22; // [sp+Ch] [bp-38h]@1
  int v23; // [sp+10h] [bp-34h]@1
  int v24; // [sp+14h] [bp-30h]@1
  int v25; // [sp+18h] [bp-2Ch]@1
  char v26; // [sp+1Ch] [bp-28h]@1
  int v27; // [sp+20h] [bp-24h]@1
  int v28; // [sp+24h] [bp-20h]@1
  int v29; // [sp+28h] [bp-1Ch]@1
  char v30; // [sp+2Ch] [bp-18h]@1
  int v31; // [sp+30h] [bp-14h]@1
  int v32; // [sp+34h] [bp-10h]@1
  int v33; // [sp+38h] [bp-Ch]@1
  int v34; // [sp+3Ch] [bp-8h]@1

  v3 = a1;
  v34 = a1;
  compile_error();//_EAX = -2147483646;
  v5 = &v22;
  __asm { cpuid }
  compile_error();//*(_DWORD *)v5 = _EAX;
  v23 = a2;
  compile_error();//v24 = _ECX;
  compile_error();//v25 = _EDX;
  v10 = &v26;
  compile_error();//_EAX = -2147483645;
  __asm { cpuid }
  compile_error();//*(_DWORD *)v10 = _EAX;
  v27 = a2;
  compile_error();//v28 = _ECX;
  compile_error();//v29 = _EDX;
  v16 = &v30;
  compile_error();//_EAX = -2147483644;
  __asm { cpuid }
  compile_error();//*(_DWORD *)v16 = _EAX;
  v31 = a2;
  compile_error();//v32 = _ECX;
  compile_error();//v33 = _EDX;
  result = v34;
  memcpy((void *)(v3 + 108), &v22, 0x30u);
  memcpy((void *)(result + 181), &v22, 0x30u);
  return result;
}


//----- (00451007) --------------------------------------------------------
signed int __thiscall sub_451007(int _this, int a2, signed int a3, signed int a4, int a5, signed int a6, signed int a7, signed int a8, int a9, int a10, int a11)
{
  signed int result; // eax@1
  signed int v12; // esi@1
  int v13; // edi@8
  int v14; // ecx@10
  double v15; // st6@11
  double v16; // st7@11
  float v17; // ST3C_4@12
  float v18; // ST38_4@12
  unsigned int v19; // esi@12
  int v20; // eax@16
  int v21; // eax@18
  char v22; // zf@23
  char v23; // zf@24
  unsigned int v24; // ecx@25
  unsigned int v25; // eax@29
  signed int v26; // ecx@29
  int v27; // edi@33
  int v28; // ecx@35
  double v29; // st6@36
  double v30; // st7@36
  float v31; // ST34_4@37
  float v32; // ST30_4@37
  unsigned int v33; // esi@37
  int v34; // eax@41
  int v35; // eax@43
  char v36; // zf@48
  char v37; // zf@49
  unsigned int v38; // ecx@50
  __int16 v39; // ax@54
  signed int v40; // ecx@54
  int v41; // edi@58
  int v42; // ecx@60
  double v43; // st6@61
  double v44; // st7@61
  float v45; // ST34_4@62
  float v46; // ST30_4@62
  unsigned int v47; // esi@62
  int v48; // eax@66
  int v49; // eax@68
  char v50; // zf@73
  char v51; // zf@74
  unsigned int v52; // ecx@75
  char v53; // al@79
  signed int v54; // ecx@79
  int v55; // edi@86
  int v56; // ecx@88
  double v57; // st6@89
  double v58; // st7@89
  float v59; // ST34_4@90
  float v60; // ST30_4@90
  unsigned int v61; // esi@90
  int v62; // eax@94
  int v63; // eax@96
  char v64; // zf@101
  char v65; // zf@102
  unsigned int v66; // ecx@103
  unsigned int v67; // eax@107
  signed int v68; // ecx@107
  int v69; // edi@111
  int v70; // ecx@113
  double v71; // st6@114
  double v72; // st7@114
  float v73; // ST34_4@115
  float v74; // ST30_4@115
  unsigned int v75; // esi@115
  int v76; // eax@119
  int v77; // eax@121
  char v78; // zf@126
  char v79; // zf@127
  unsigned int v80; // ecx@128
  __int16 v81; // ax@132
  signed int v82; // ecx@132
  int v83; // edi@136
  int v84; // ecx@138
  double v85; // st6@139
  double v86; // st7@139
  float v87; // ST34_4@140
  float v88; // ST30_4@140
  unsigned int v89; // esi@140
  int v90; // eax@144
  int v91; // eax@146
  char v92; // zf@151
  char v93; // zf@152
  unsigned int v94; // ecx@153
  char v95; // al@157
  signed int v96; // ecx@157
  int v97; // edi@164
  int v98; // ecx@166
  double v99; // st6@167
  double v100; // st7@167
  float v101; // ST34_4@168
  float v102; // ST30_4@168
  unsigned int v103; // esi@168
  int v104; // eax@170
  int v105; // eax@171
  int v106; // eax@173
  unsigned int v108; // ecx@181
  unsigned int v109; // eax@185
  signed int v110; // ecx@185
  int v111; // edi@189
  int v112; // ecx@191
  double v113; // st6@192
  double v114; // st7@192
  float v115; // ST34_4@193
  float v116; // ST30_4@193
  unsigned int v117; // esi@193
  int v118; // eax@195
  int v119; // eax@196
  int v120; // eax@198
  unsigned int v122; // ecx@206
  __int16 v123; // ax@210
  signed int v124; // ecx@210
  int v125; // edi@214
  int v126; // ecx@216
  double v127; // st6@217
  double v128; // st7@217
  float v129; // ST34_4@218
  float v130; // ST30_4@218
  unsigned int v131; // esi@218
  int v132; // eax@220
  int v133; // eax@221
  int v134; // eax@223
  unsigned int v136; // ecx@231
  char v137; // al@235
  signed int v138; // ecx@235
  double v139; // [sp+Ch] [bp-7Ch]@12
  double v140; // [sp+Ch] [bp-7Ch]@37
  double v141; // [sp+Ch] [bp-7Ch]@62
  double v142; // [sp+Ch] [bp-7Ch]@90
  double v143; // [sp+Ch] [bp-7Ch]@115
  double v144; // [sp+Ch] [bp-7Ch]@140
  double v145; // [sp+Ch] [bp-7Ch]@168
  double v146; // [sp+Ch] [bp-7Ch]@193
  double v147; // [sp+Ch] [bp-7Ch]@218
  double v148; // [sp+14h] [bp-74h]@12
  double v149; // [sp+14h] [bp-74h]@37
  double v150; // [sp+14h] [bp-74h]@62
  double v151; // [sp+14h] [bp-74h]@90
  double v152; // [sp+14h] [bp-74h]@115
  double v153; // [sp+14h] [bp-74h]@140
  double v154; // [sp+14h] [bp-74h]@168
  double v155; // [sp+14h] [bp-74h]@193
  double v156; // [sp+14h] [bp-74h]@218
  double v157; // [sp+1Ch] [bp-6Ch]@12
  double v158; // [sp+1Ch] [bp-6Ch]@37
  double v159; // [sp+1Ch] [bp-6Ch]@62
  double v160; // [sp+1Ch] [bp-6Ch]@90
  double v161; // [sp+1Ch] [bp-6Ch]@115
  double v162; // [sp+1Ch] [bp-6Ch]@140
  double v163; // [sp+1Ch] [bp-6Ch]@168
  double v164; // [sp+1Ch] [bp-6Ch]@193
  double v165; // [sp+1Ch] [bp-6Ch]@218
  double v166; // [sp+24h] [bp-64h]@12
  double v167; // [sp+24h] [bp-64h]@37
  double v168; // [sp+24h] [bp-64h]@62
  double v169; // [sp+24h] [bp-64h]@90
  double v170; // [sp+24h] [bp-64h]@115
  double v171; // [sp+24h] [bp-64h]@140
  double v172; // [sp+24h] [bp-64h]@168
  double v173; // [sp+24h] [bp-64h]@193
  double v174; // [sp+24h] [bp-64h]@218
  int v175; // [sp+3Ch] [bp-4Ch]@13
  int v176; // [sp+40h] [bp-48h]@15
  int v177; // [sp+44h] [bp-44h]@40
  int v178; // [sp+44h] [bp-44h]@65
  int v179; // [sp+44h] [bp-44h]@93
  int v180; // [sp+44h] [bp-44h]@118
  int v181; // [sp+44h] [bp-44h]@143
  int v182; // [sp+44h] [bp-44h]@169
  int v183; // [sp+44h] [bp-44h]@194
  int v184; // [sp+44h] [bp-44h]@219
  int v185; // [sp+48h] [bp-40h]@38
  int v186; // [sp+48h] [bp-40h]@63
  int v187; // [sp+48h] [bp-40h]@91
  int v188; // [sp+48h] [bp-40h]@116
  int v189; // [sp+48h] [bp-40h]@141
  int v190; // [sp+4Ch] [bp-3Ch]@13
  int *v191; // [sp+50h] [bp-38h]@15
  int *v192; // [sp+50h] [bp-38h]@40
  int *v193; // [sp+50h] [bp-38h]@65
  int *v194; // [sp+50h] [bp-38h]@93
  int *v195; // [sp+50h] [bp-38h]@118
  int *v196; // [sp+50h] [bp-38h]@143
  int v197; // [sp+50h] [bp-38h]@169
  int v198; // [sp+50h] [bp-38h]@194
  int v199; // [sp+50h] [bp-38h]@219
  int v200; // [sp+54h] [bp-34h]@38
  int v201; // [sp+54h] [bp-34h]@63
  int v202; // [sp+54h] [bp-34h]@91
  int v203; // [sp+54h] [bp-34h]@116
  int v204; // [sp+54h] [bp-34h]@141
  int v205; // [sp+54h] [bp-34h]@170
  int v206; // [sp+54h] [bp-34h]@195
  int v207; // [sp+54h] [bp-34h]@220
  signed int v208; // [sp+5Ch] [bp-2Ch]@7
  signed int v209; // [sp+5Ch] [bp-2Ch]@32
  signed int v210; // [sp+5Ch] [bp-2Ch]@57
  signed int v211; // [sp+5Ch] [bp-2Ch]@85
  signed int v212; // [sp+5Ch] [bp-2Ch]@110
  signed int v213; // [sp+5Ch] [bp-2Ch]@135
  signed int v214; // [sp+5Ch] [bp-2Ch]@163
  signed int v215; // [sp+5Ch] [bp-2Ch]@188
  signed int v216; // [sp+5Ch] [bp-2Ch]@213
  int v217; // [sp+60h] [bp-28h]@1
  int v218; // [sp+64h] [bp-24h]@12
  int v219; // [sp+64h] [bp-24h]@37
  int v220; // [sp+64h] [bp-24h]@62
  int v221; // [sp+64h] [bp-24h]@90
  int v222; // [sp+64h] [bp-24h]@115
  int v223; // [sp+64h] [bp-24h]@140
  int v224; // [sp+64h] [bp-24h]@168
  int v225; // [sp+64h] [bp-24h]@193
  int v226; // [sp+64h] [bp-24h]@218
  float v227; // [sp+6Ch] [bp-1Ch]@11
  float v228; // [sp+6Ch] [bp-1Ch]@36
  float v229; // [sp+6Ch] [bp-1Ch]@61
  float v230; // [sp+6Ch] [bp-1Ch]@89
  float v231; // [sp+6Ch] [bp-1Ch]@114
  float v232; // [sp+6Ch] [bp-1Ch]@139
  float v233; // [sp+6Ch] [bp-1Ch]@167
  float v234; // [sp+6Ch] [bp-1Ch]@192
  float v235; // [sp+6Ch] [bp-1Ch]@217
  float v236; // [sp+70h] [bp-18h]@11
  float v237; // [sp+70h] [bp-18h]@36
  float v238; // [sp+70h] [bp-18h]@61
  float v239; // [sp+70h] [bp-18h]@89
  float v240; // [sp+70h] [bp-18h]@114
  float v241; // [sp+70h] [bp-18h]@139
  float v242; // [sp+70h] [bp-18h]@167
  float v243; // [sp+70h] [bp-18h]@192
  float v244; // [sp+70h] [bp-18h]@217
  signed int v245; // [sp+74h] [bp-14h]@1
  signed int v246; // [sp+78h] [bp-10h]@7
  signed int v247; // [sp+78h] [bp-10h]@32
  signed int v248; // [sp+78h] [bp-10h]@57
  signed int v249; // [sp+78h] [bp-10h]@85
  signed int v250; // [sp+78h] [bp-10h]@110
  signed int v251; // [sp+78h] [bp-10h]@135
  signed int v252; // [sp+78h] [bp-10h]@163
  signed int v253; // [sp+78h] [bp-10h]@188
  signed int v254; // [sp+78h] [bp-10h]@213
  unsigned int v255; // [sp+7Ch] [bp-Ch]@12
  unsigned int v256; // [sp+7Ch] [bp-Ch]@37
  unsigned int v257; // [sp+7Ch] [bp-Ch]@62
  unsigned int v258; // [sp+7Ch] [bp-Ch]@90
  unsigned int v259; // [sp+7Ch] [bp-Ch]@115
  unsigned int v260; // [sp+7Ch] [bp-Ch]@140
  unsigned int v261; // [sp+7Ch] [bp-Ch]@168
  unsigned int v262; // [sp+7Ch] [bp-Ch]@193
  unsigned int v263; // [sp+7Ch] [bp-Ch]@218
  unsigned int v264; // [sp+80h] [bp-8h]@12
  unsigned int v265; // [sp+80h] [bp-8h]@37
  unsigned int v266; // [sp+80h] [bp-8h]@62
  unsigned int v267; // [sp+80h] [bp-8h]@90
  unsigned int v268; // [sp+80h] [bp-8h]@115
  unsigned int v269; // [sp+80h] [bp-8h]@140
  unsigned int v270; // [sp+80h] [bp-8h]@168
  unsigned int v271; // [sp+80h] [bp-8h]@193
  unsigned int v272; // [sp+80h] [bp-8h]@218
  unsigned int v273; // [sp+84h] [bp-4h]@12
  unsigned int v274; // [sp+84h] [bp-4h]@37
  unsigned int v275; // [sp+84h] [bp-4h]@62
  unsigned int v276; // [sp+84h] [bp-4h]@90
  unsigned int v277; // [sp+84h] [bp-4h]@115
  unsigned int v278; // [sp+84h] [bp-4h]@140
  unsigned int v279; // [sp+84h] [bp-4h]@168
  unsigned int v280; // [sp+84h] [bp-4h]@193
  unsigned int v281; // [sp+84h] [bp-4h]@218
  signed int v282; // [sp+A0h] [bp+18h]@10
  unsigned int v283; // [sp+A0h] [bp+18h]@12
  float v284; // [sp+A0h] [bp+18h]@12
  float v285; // [sp+A0h] [bp+18h]@12
  signed int v286; // [sp+A0h] [bp+18h]@35
  unsigned int v287; // [sp+A0h] [bp+18h]@37
  float v288; // [sp+A0h] [bp+18h]@37
  float v289; // [sp+A0h] [bp+18h]@37
  signed int v290; // [sp+A0h] [bp+18h]@60
  unsigned int v291; // [sp+A0h] [bp+18h]@62
  float v292; // [sp+A0h] [bp+18h]@62
  float v293; // [sp+A0h] [bp+18h]@62
  signed int v294; // [sp+A0h] [bp+18h]@88
  unsigned int v295; // [sp+A0h] [bp+18h]@90
  float v296; // [sp+A0h] [bp+18h]@90
  float v297; // [sp+A0h] [bp+18h]@90
  signed int v298; // [sp+A0h] [bp+18h]@113
  unsigned int v299; // [sp+A0h] [bp+18h]@115
  float v300; // [sp+A0h] [bp+18h]@115
  float v301; // [sp+A0h] [bp+18h]@115
  signed int v302; // [sp+A0h] [bp+18h]@138
  unsigned int v303; // [sp+A0h] [bp+18h]@140
  float v304; // [sp+A0h] [bp+18h]@140
  float v305; // [sp+A0h] [bp+18h]@140
  signed int v306; // [sp+A0h] [bp+18h]@166
  unsigned int v307; // [sp+A0h] [bp+18h]@168
  float v308; // [sp+A0h] [bp+18h]@168
  float v309; // [sp+A0h] [bp+18h]@168
  signed int v310; // [sp+A0h] [bp+18h]@191
  unsigned int v311; // [sp+A0h] [bp+18h]@193
  float v312; // [sp+A0h] [bp+18h]@193
  float v313; // [sp+A0h] [bp+18h]@193
  signed int v314; // [sp+A0h] [bp+18h]@216
  unsigned int v315; // [sp+A0h] [bp+18h]@218
  float v316; // [sp+A0h] [bp+18h]@218
  float v317; // [sp+A0h] [bp+18h]@218
  int v318; // [sp+ACh] [bp+24h]@8
  int v319; // [sp+ACh] [bp+24h]@33
  int v320; // [sp+ACh] [bp+24h]@86
  int v321; // [sp+ACh] [bp+24h]@111
  int v322; // [sp+ACh] [bp+24h]@164
  int v323; // [sp+ACh] [bp+24h]@189

  v12 = 0;
  result = *(_DWORD *)(_this + 12);
  v217 = _this;
  v245 = 0;
  if ( result != 8 )
  {
    if ( result != 16 )
    {
      if ( result != 32 )
        return result;
      result = *(_DWORD *)(_this + 44);
      if ( result != 8 )
      {
        if ( result != 16 )
        {
          if ( result != 32 || (result = a6, v208 = a6, v246 = 0, a8 <= 0) )
            return result;
          v13 = a7;
          v318 = 4 * (a9 - a7);
          while ( 1 )
          {
            v14 = 0;
            v282 = 0;
            if ( a7 > v12 )
              break;
LABEL_30:
            v208 += v318;
            ++v246;
            result = v246;
            if ( v246 >= a8 )
              return result;
            v12 = 0;
          }
          v236 = (double)a7;
          v227 = (double)a3;
          v16 = (double)a8;
          v15 = (double)a4;
          while ( 1 )
          {
            v284 = (double)v282 / v236 * v227;
            v166 = v284 + 6.755399441055744e15;
            v218 = v14 + 1;
            v285 = (double)(v14 + 1) / v236 * v227;
            v157 = v285 + 6.755399441055744e15;
            v17 = (double)v246 / v16 * v15;
            v148 = v17 + 6.755399441055744e15;
            v18 = (double)(v246 + 1) / v16 * v15;
            v139 = v18 + 6.755399441055744e15;
            v264 = 0;
            v19 = (LODWORD(v139) - LODWORD(v148)) * (LODWORD(v157) - LODWORD(v166));
            v273 = 0;
            v283 = 0;
            v255 = 0;
            if (LODWORD(v148) < LODWORD(v139) )
              break;
LABEL_25:
            v24 = v255 / ((LODWORD(v139) - LODWORD(v148)) * (LODWORD(v157) - LODWORD(v166)));
            if ( v19 )
            {
              v283 /= v19;
              v273 /= v19;
              v264 /= v19;
            }
            if ( v24 != 255 )
              v24 &= 0x7FFFFFFFu;
            v25 = sub_450F55(v217, v264 | ((v273 | ((v283 | (v24 << 8)) << 8)) << 8));
            v26 = v208;
            v208 += 4;
            *(_DWORD *)v26 = v25;
            v14 = v218;
            v282 = v218;
            if ( v218 >= a7 )
              goto LABEL_30;
          }
          v175 = LODWORD(v139) - LODWORD(v148);
          v190 = a2 + 4 * (LODWORD(v166) + a5 * LODWORD(v148));
          while (LODWORD(v166) >= LODWORD(v157) )
          {
LABEL_24:
            v190 += 4 * a5;
            v23 = v175-- == 1;
            if ( v23 )
              goto LABEL_25;
          }
          v191 = (int *)v190;
          v176 = LODWORD(v157) - LODWORD(v166);
          while ( 1 )
          {
            v20 = *v191;
            if ( a10 )
            {
              v245 = 1;
              v13 = v20 != a11 ? 0xFF : 0;
            }
            v21 = sub_450FB1(v217, v20);
            if ( !v245 )
              break;
            v255 += v13;
            v245 = 0;
            if ( v13 )
              goto LABEL_22;
            --v19;
LABEL_23:
            ++v191;
            v22 = v176-- == 1;
            if ( v22 )
              goto LABEL_24;
          }
          v255 += (unsigned int)v21 >> 24;
LABEL_22:
          v283 += BYTE2(v21);
          v273 += BYTE1(v21);
          v264 += (unsigned __int8)v21;
          goto LABEL_23;
        }
        result = a6;
        v209 = a6;
        v247 = 0;
        if ( a8 <= 0 )
          return result;
        v27 = a7;
        v319 = 2 * (a9 - a7);
        while ( 1 )
        {
          v28 = 0;
          v286 = 0;
          if ( a7 > v12 )
            break;
LABEL_55:
          v209 += v319;
          ++v247;
          result = v247;
          if ( v247 >= a8 )
            return result;
          v12 = 0;
        }
        v237 = (double)a7;
        v228 = (double)a3;
        v30 = (double)a8;
        v29 = (double)a4;
        while ( 1 )
        {
          v288 = (double)v286 / v237 * v228;
          v140 = v288 + 6.755399441055744e15;
          v219 = v28 + 1;
          v289 = (double)(v28 + 1) / v237 * v228;
          v149 = v289 + 6.755399441055744e15;
          v31 = (double)v247 / v30 * v29;
          v158 = v31 + 6.755399441055744e15;
          v32 = (double)(v247 + 1) / v30 * v29;
          v167 = v32 + 6.755399441055744e15;
          v265 = 0;
          v33 = (LODWORD(v167) - LODWORD(v158)) * (LODWORD(v149) - LODWORD(v140));
          v274 = 0;
          v287 = 0;
          v256 = 0;
          if (LODWORD(v158) < LODWORD(v167) )
            break;
LABEL_50:
          v38 = v256 / ((LODWORD(v167) - LODWORD(v158)) * (LODWORD(v149) - LODWORD(v140)));
          if ( v33 )
          {
            v287 /= v33;
            v274 /= v33;
            v265 /= v33;
          }
          if ( v38 != 255 )
            v38 &= 0x7FFFFFFFu;
          v39 = sub_450F55(v217, v265 | ((v274 | ((v287 | (v38 << 8)) << 8)) << 8));
          v40 = v209;
          v209 += 2;
          *(_WORD *)v40 = v39;
          v28 = v219;
          v286 = v219;
          if ( v219 >= a7 )
            goto LABEL_55;
        }
        v185 = LODWORD(v167) - LODWORD(v158);
        v200 = a2 + 4 * (LODWORD(v140) + a5 * LODWORD(v158));
        while (LODWORD(v140) >= LODWORD(v149) )
        {
LABEL_49:
          v200 += 4 * a5;
          v37 = v185-- == 1;
          if ( v37 )
            goto LABEL_50;
        }
        v192 = (int *)v200;
        v177 = LODWORD(v149) - LODWORD(v140);
        while ( 1 )
        {
          v34 = *v192;
          if ( a10 )
          {
            v245 = 1;
            v27 = v34 != a11 ? 0xFF : 0;
          }
          v35 = sub_450FB1(v217, v34);
          if ( !v245 )
            break;
          v256 += v27;
          v245 = 0;
          if ( v27 )
            goto LABEL_47;
          --v33;
LABEL_48:
          ++v192;
          v36 = v177-- == 1;
          if ( v36 )
            goto LABEL_49;
        }
        v256 += (unsigned int)v35 >> 24;
LABEL_47:
        v287 += BYTE2(v35);
        v274 += BYTE1(v35);
        v265 += (unsigned __int8)v35;
        goto LABEL_48;
      }
      result = a6;
      v210 = a6;
      v248 = 0;
      if ( a8 <= 0 )
        return result;
      v41 = a7;
      while ( 1 )
      {
        v42 = 0;
        v290 = 0;
        if ( a7 > v12 )
          break;
LABEL_80:
        v210 += a9 - a7;
        ++v248;
        result = v248;
        if ( v248 >= a8 )
          return result;
        v12 = 0;
      }
      v238 = (double)a7;
      v229 = (double)a3;
      v44 = (double)a8;
      v43 = (double)a4;
      while ( 1 )
      {
        v292 = (double)v290 / v238 * v229;
        v141 = v292 + 6.755399441055744e15;
        v220 = v42 + 1;
        v293 = (double)(v42 + 1) / v238 * v229;
        v150 = v293 + 6.755399441055744e15;
        v45 = (double)v248 / v44 * v43;
        v159 = v45 + 6.755399441055744e15;
        v46 = (double)(v248 + 1) / v44 * v43;
        v168 = v46 + 6.755399441055744e15;
        v266 = 0;
        v47 = (LODWORD(v168) - LODWORD(v159)) * (LODWORD(v150) - LODWORD(v141));
        v275 = 0;
        v291 = 0;
        v257 = 0;
        if (LODWORD(v159) < LODWORD(v168) )
          break;
LABEL_75:
        v52 = v257 / ((LODWORD(v168) - LODWORD(v159)) * (LODWORD(v150) - LODWORD(v141)));
        if ( v47 )
        {
          v291 /= v47;
          v275 /= v47;
          v266 /= v47;
        }
        if ( v52 != 255 )
          v52 &= 0x7FFFFFFFu;
        v53 = sub_450F55(v217, v266 | ((v275 | ((v291 | (v52 << 8)) << 8)) << 8));
        v54 = v210++;
        *(_BYTE *)v54 = v53;
        v42 = v220;
        v290 = v220;
        if ( v220 >= a7 )
          goto LABEL_80;
      }
      v186 = LODWORD(v168) - LODWORD(v159);
      v201 = a2 + 4 * (LODWORD(v141) + a5 * LODWORD(v159));
      while (LODWORD(v141) >= LODWORD(v150) )
      {
LABEL_74:
        v201 += 4 * a5;
        v51 = v186-- == 1;
        if ( v51 )
          goto LABEL_75;
      }
      v193 = (int *)v201;
      v178 = LODWORD(v150) - LODWORD(v141);
      while ( 1 )
      {
        v48 = *v193;
        if ( a10 )
        {
          v245 = 1;
          v41 = v48 != a11 ? 0xFF : 0;
        }
        v49 = sub_450FB1(v217, v48);
        if ( !v245 )
          break;
        v257 += v41;
        v245 = 0;
        if ( v41 )
          goto LABEL_72;
        --v47;
LABEL_73:
        ++v193;
        v50 = v178-- == 1;
        if ( v50 )
          goto LABEL_74;
      }
      v257 += (unsigned int)v49 >> 24;
LABEL_72:
      v291 += BYTE2(v49);
      v275 += BYTE1(v49);
      v266 += (unsigned __int8)v49;
      goto LABEL_73;
    }
    result = *(_DWORD *)(_this + 44);
    if ( result != 8 )
    {
      if ( result != 16 )
      {
        if ( result != 32 || (result = a6, v211 = a6, v249 = 0, a8 <= 0) )
          return result;
        v55 = a7;
        v320 = 4 * (a9 - a7);
        while ( 1 )
        {
          v56 = 0;
          v294 = 0;
          if ( a7 > v12 )
            break;
LABEL_108:
          v211 += v320;
          ++v249;
          result = v249;
          if ( v249 >= a8 )
            return result;
          v12 = 0;
        }
        v239 = (double)a7;
        v230 = (double)a3;
        v58 = (double)a8;
        v57 = (double)a4;
        while ( 1 )
        {
          v296 = (double)v294 / v239 * v230;
          v142 = v296 + 6.755399441055744e15;
          v221 = v56 + 1;
          v297 = (double)(v56 + 1) / v239 * v230;
          v151 = v297 + 6.755399441055744e15;
          v59 = (double)v249 / v58 * v57;
          v160 = v59 + 6.755399441055744e15;
          v60 = (double)(v249 + 1) / v58 * v57;
          v169 = v60 + 6.755399441055744e15;
          v267 = 0;
          v61 = (LODWORD(v169) - LODWORD(v160)) * (LODWORD(v151) - LODWORD(v142));
          v276 = 0;
          v295 = 0;
          v258 = 0;
          if (LODWORD(v160) < LODWORD(v169) )
            break;
LABEL_103:
          v66 = v258 / ((LODWORD(v169) - LODWORD(v160)) * (LODWORD(v151) - LODWORD(v142)));
          if ( v61 )
          {
            v295 /= v61;
            v276 /= v61;
            v267 /= v61;
          }
          if ( v66 != 255 )
            v66 &= 0x7FFFFFFFu;
          v67 = sub_450F55(v217, v267 | ((v276 | ((v295 | (v66 << 8)) << 8)) << 8));
          v68 = v211;
          v211 += 4;
          *(_DWORD *)v68 = v67;
          v56 = v221;
          v294 = v221;
          if ( v221 >= a7 )
            goto LABEL_108;
        }
        v187 = LODWORD(v169) - LODWORD(v160);
        v202 = a2 + 2 * (LODWORD(v142) + a5 * LODWORD(v160));
        while (LODWORD(v142) >= LODWORD(v151) )
        {
LABEL_102:
          v202 += 2 * a5;
          v65 = v187-- == 1;
          if ( v65 )
            goto LABEL_103;
        }
        v194 = (int *)v202;
        v179 = LODWORD(v151) - LODWORD(v142);
        while ( 1 )
        {
          v62 = *(_WORD *)v194;
          if ( a10 )
          {
            v245 = 1;
            v55 = v62 != a11 ? 0xFF : 0;
          }
          v63 = sub_450FB1(v217, v62);
          if ( !v245 )
            break;
          v258 += v55;
          v245 = 0;
          if ( v55 )
            goto LABEL_100;
          --v61;
LABEL_101:
          v194 = (int *)((char *)v194 + 2);
          v64 = v179-- == 1;
          if ( v64 )
            goto LABEL_102;
        }
        v258 += (unsigned int)v63 >> 24;
LABEL_100:
        v295 += BYTE2(v63);
        v276 += BYTE1(v63);
        v267 += (unsigned __int8)v63;
        goto LABEL_101;
      }
      result = a6;
      v212 = a6;
      v250 = 0;
      if ( a8 <= 0 )
        return result;
      v69 = a7;
      v321 = 2 * (a9 - a7);
      while ( 1 )
      {
        v70 = 0;
        v298 = 0;
        if ( a7 > v12 )
          break;
LABEL_133:
        v212 += v321;
        ++v250;
        result = v250;
        if ( v250 >= a8 )
          return result;
        v12 = 0;
      }
      v240 = (double)a7;
      v231 = (double)a3;
      v72 = (double)a8;
      v71 = (double)a4;
      while ( 1 )
      {
        v300 = (double)v298 / v240 * v231;
        v143 = v300 + 6.755399441055744e15;
        v222 = v70 + 1;
        v301 = (double)(v70 + 1) / v240 * v231;
        v152 = v301 + 6.755399441055744e15;
        v73 = (double)v250 / v72 * v71;
        v161 = v73 + 6.755399441055744e15;
        v74 = (double)(v250 + 1) / v72 * v71;
        v170 = v74 + 6.755399441055744e15;
        v268 = 0;
        v75 = (LODWORD(v170) - LODWORD(v161)) * (LODWORD(v152) - LODWORD(v143));
        v277 = 0;
        v299 = 0;
        v259 = 0;
        if (LODWORD(v161) < LODWORD(v170) )
          break;
LABEL_128:
        v80 = v259 / ((LODWORD(v170) - LODWORD(v161)) * (LODWORD(v152) - LODWORD(v143)));
        if ( v75 )
        {
          v299 /= v75;
          v277 /= v75;
          v268 /= v75;
        }
        if ( v80 != 255 )
          v80 &= 0x7FFFFFFFu;
        v81 = sub_450F55(v217, v268 | ((v277 | ((v299 | (v80 << 8)) << 8)) << 8));
        v82 = v212;
        v212 += 2;
        *(_WORD *)v82 = v81;
        v70 = v222;
        v298 = v222;
        if ( v222 >= a7 )
          goto LABEL_133;
      }
      v188 = LODWORD(v170) - LODWORD(v161);
      v203 = a2 + 2 * (LODWORD(v143) + a5 * LODWORD(v161));
      while (LODWORD(v143) >= LODWORD(v152) )
      {
LABEL_127:
        v203 += 2 * a5;
        v79 = v188-- == 1;
        if ( v79 )
          goto LABEL_128;
      }
      v195 = (int *)v203;
      v180 = LODWORD(v152) - LODWORD(v143);
      while ( 1 )
      {
        v76 = *(_WORD *)v195;
        if ( a10 )
        {
          v245 = 1;
          v69 = v76 != a11 ? 0xFF : 0;
        }
        v77 = sub_450FB1(v217, v76);
        if ( !v245 )
          break;
        v259 += v69;
        v245 = 0;
        if ( v69 )
          goto LABEL_125;
        --v75;
LABEL_126:
        v195 = (int *)((char *)v195 + 2);
        v78 = v180-- == 1;
        if ( v78 )
          goto LABEL_127;
      }
      v259 += (unsigned int)v77 >> 24;
LABEL_125:
      v299 += BYTE2(v77);
      v277 += BYTE1(v77);
      v268 += (unsigned __int8)v77;
      goto LABEL_126;
    }
    result = a6;
    v213 = a6;
    v251 = 0;
    if ( a8 <= 0 )
      return result;
    v83 = a7;
    while ( 1 )
    {
      v84 = 0;
      v302 = 0;
      if ( a7 > v12 )
        break;
LABEL_158:
      v213 += a9 - a7;
      ++v251;
      result = v251;
      if ( v251 >= a8 )
        return result;
      v12 = 0;
    }
    v241 = (double)a7;
    v232 = (double)a3;
    v86 = (double)a8;
    v85 = (double)a4;
    while ( 1 )
    {
      v304 = (double)v302 / v241 * v232;
      v144 = v304 + 6.755399441055744e15;
      v223 = v84 + 1;
      v305 = (double)(v84 + 1) / v241 * v232;
      v153 = v305 + 6.755399441055744e15;
      v87 = (double)v251 / v86 * v85;
      v162 = v87 + 6.755399441055744e15;
      v88 = (double)(v251 + 1) / v86 * v85;
      v171 = v88 + 6.755399441055744e15;
      v269 = 0;
      v278 = 0;
      v89 = (LODWORD(v171) - LODWORD(v162)) * (LODWORD(v153) - LODWORD(v144));
      v303 = 0;
      v260 = 0;
      if (LODWORD(v162) < LODWORD(v171) )
        break;
LABEL_153:
      v94 = v260 / ((LODWORD(v171) - LODWORD(v162)) * (LODWORD(v153) - LODWORD(v144)));
      if ( v89 )
      {
        v303 /= v89;
        v278 /= v89;
        v269 /= v89;
      }
      if ( v94 != 255 )
        v94 &= 0x7FFFFFFFu;
      v95 = sub_450F55(v217, v269 | ((v278 | ((v303 | (v94 << 8)) << 8)) << 8));
      v96 = v213++;
      *(_BYTE *)v96 = v95;
      v84 = v223;
      v302 = v223;
      if ( v223 >= a7 )
        goto LABEL_158;
    }
    v189 = LODWORD(v171) - LODWORD(v162);
    v204 = a2 + 2 * (LODWORD(v144) + a5 * LODWORD(v162));
    while (LODWORD(v144) >= LODWORD(v153) )
    {
LABEL_152:
      v204 += 2 * a5;
      v93 = v189-- == 1;
      if ( v93 )
        goto LABEL_153;
    }
    v181 = LODWORD(v153) - LODWORD(v144);
    v196 = (int *)v204;
    while ( 1 )
    {
      v90 = *(_WORD *)v196;
      if ( a10 )
      {
        v245 = 1;
        v83 = v90 != a11 ? 0xFF : 0;
      }
      v91 = sub_450FB1(v217, v90);
      if ( !v245 )
        break;
      v260 += v83;
      v245 = 0;
      if ( v83 )
        goto LABEL_150;
      --v89;
LABEL_151:
      v196 = (int *)((char *)v196 + 2);
      v92 = v181-- == 1;
      if ( v92 )
        goto LABEL_152;
    }
    v260 += (unsigned int)v91 >> 24;
LABEL_150:
    v303 += BYTE2(v91);
    v278 += BYTE1(v91);
    v269 += (unsigned __int8)v91;
    goto LABEL_151;
  }
  result = *(_DWORD *)(_this + 44);
  if ( result == 8 )
  {
    result = a6;
    v216 = a6;
    v254 = 0;
    if ( a8 <= 0 )
      return result;
    v125 = a7;
    while ( 1 )
    {
      v126 = 0;
      v314 = 0;
      if ( a7 <= v12 )
        goto LABEL_236;
      v244 = (double)a7;
      v235 = (double)a3;
      v128 = (double)a8;
      v127 = (double)a4;
      do
      {
        v316 = (double)v314 / v244 * v235;
        v147 = v316 + 6.755399441055744e15;
        v226 = v126 + 1;
        v317 = (double)(v126 + 1) / v244 * v235;
        v156 = v317 + 6.755399441055744e15;
        v129 = (double)v254 / v128 * v127;
        v165 = v129 + 6.755399441055744e15;
        v130 = (double)(v254 + 1) / v128 * v127;
        v174 = v130 + 6.755399441055744e15;
        v272 = 0;
        v131 = (LODWORD(v174) - LODWORD(v165)) * (LODWORD(v156) - LODWORD(v147));
        v281 = 0;
        v315 = 0;
        v263 = 0;
        if (LODWORD(v165) >= LODWORD(v174) )
          goto LABEL_231;
        v184 = LODWORD(v174) - LODWORD(v165);
        v199 = a2 + a5 * LODWORD(v165);
        do
        {
          v132 = LODWORD(v147);
          v207 = LODWORD(v147);
          while ( v132 < LODWORD(v156) )
          {
            v133 = *(_BYTE *)(v199 + v207);
            if ( a10 )
            {
              v245 = 1;
              v125 = v133 != a11 ? 0xFF : 0;
            }
            v134 = sub_450FB1(v217, v133);
            if ( v245 )
            {
              v263 += v125;
              v245 = 0;
              if ( !v125 )
              {
                --v131;
                goto LABEL_228;
              }
            }
            else
            {
              v263 += (unsigned int)v134 >> 24;
            }
            v315 += BYTE2(v134);
            v281 += BYTE1(v134);
            v272 += (unsigned __int8)v134;
LABEL_228:
            ++v207;
            v132 = v207;
          }
          v199 += a5;
        }
        while ( v184-- != 1 );
LABEL_231:
        v136 = v263 / ((LODWORD(v174) - LODWORD(v165)) * (LODWORD(v156) - LODWORD(v147)));
        if ( v131 )
        {
          v315 /= v131;
          v281 /= v131;
          v272 /= v131;
        }
        if ( v136 != 255 )
          v136 &= 0x7FFFFFFFu;
        v137 = sub_450F55(v217, v272 | ((v281 | ((v315 | (v136 << 8)) << 8)) << 8));
        v138 = v216++;
        *(_BYTE *)v138 = v137;
        v126 = v226;
        v314 = v226;
      }
      while ( v226 < a7 );
LABEL_236:
      v216 += a9 - a7;
      ++v254;
      result = v254;
      if ( v254 >= a8 )
        return result;
      v12 = 0;
    }
  }
  if ( result == 16 )
  {
    result = a6;
    v215 = a6;
    v253 = 0;
    if ( a8 <= 0 )
      return result;
    v111 = a7;
    v323 = 2 * (a9 - a7);
    while ( 1 )
    {
      v112 = 0;
      v310 = 0;
      if ( a7 <= v12 )
        goto LABEL_211;
      v243 = (double)a7;
      v234 = (double)a3;
      v114 = (double)a8;
      v113 = (double)a4;
      do
      {
        v312 = (double)v310 / v243 * v234;
        v146 = v312 + 6.755399441055744e15;
        v225 = v112 + 1;
        v313 = (double)(v112 + 1) / v243 * v234;
        v155 = v313 + 6.755399441055744e15;
        v115 = (double)v253 / v114 * v113;
        v164 = v115 + 6.755399441055744e15;
        v116 = (double)(v253 + 1) / v114 * v113;
        v173 = v116 + 6.755399441055744e15;
        v271 = 0;
        v117 = (LODWORD(v173) - LODWORD(v164)) * (LODWORD(v155) - LODWORD(v146));
        v280 = 0;
        v311 = 0;
        v262 = 0;
        if (LODWORD(v164) >= LODWORD(v173) )
          goto LABEL_206;
        v183 = LODWORD(v173) - LODWORD(v164);
        v198 = a2 + a5 * LODWORD(v164);
        do
        {
          v118 = LODWORD(v146);
          v206 = LODWORD(v146);
          while ( v118 < LODWORD(v155) )
          {
            v119 = *(_BYTE *)(v198 + v206);
            if ( a10 )
            {
              v245 = 1;
              v111 = v119 != a11 ? 0xFF : 0;
            }
            v120 = sub_450FB1(v217, v119);
            if ( v245 )
            {
              v262 += v111;
              v245 = 0;
              if ( !v111 )
              {
                --v117;
                goto LABEL_203;
              }
            }
            else
            {
              v262 += (unsigned int)v120 >> 24;
            }
            v311 += BYTE2(v120);
            v280 += BYTE1(v120);
            v271 += (unsigned __int8)v120;
LABEL_203:
            ++v206;
            v118 = v206;
          }
          v198 += a5;
        }
        while ( v183-- != 1 );
LABEL_206:
        v122 = v262 / ((LODWORD(v173) - LODWORD(v164)) * (LODWORD(v155) - LODWORD(v146)));
        if ( v117 )
        {
          v311 /= v117;
          v280 /= v117;
          v271 /= v117;
        }
        if ( v122 != 255 )
          v122 &= 0x7FFFFFFFu;
        v123 = sub_450F55(v217, v271 | ((v280 | ((v311 | (v122 << 8)) << 8)) << 8));
        v124 = v215;
        v215 += 2;
        *(_WORD *)v124 = v123;
        v112 = v225;
        v310 = v225;
      }
      while ( v225 < a7 );
LABEL_211:
      v215 += v323;
      ++v253;
      result = v253;
      if ( v253 >= a8 )
        return result;
      v12 = 0;
    }
  }
  if ( result != 32 || (result = a6, v214 = a6, v252 = 0, a8 <= 0) )
    return result;
  v97 = a7;
  v322 = 4 * (a9 - a7);
  while ( 2 )
  {
    v98 = 0;
    v306 = 0;
    if ( a7 <= v12 )
      goto LABEL_186;
    v242 = (double)a7;
    v233 = (double)a3;
    v100 = (double)a8;
    v99 = (double)a4;
    do
    {
      v308 = (double)v306 / v242 * v233;
      v145 = v308 + 6.755399441055744e15;
      v224 = v98 + 1;
      v309 = (double)(v98 + 1) / v242 * v233;
      v154 = v309 + 6.755399441055744e15;
      v101 = (double)v252 / v100 * v99;
      v163 = v101 + 6.755399441055744e15;
      v102 = (double)(v252 + 1) / v100 * v99;
      v172 = v102 + 6.755399441055744e15;
      v270 = 0;
      v103 = (LODWORD(v172) - LODWORD(v163)) * (LODWORD(v154) - LODWORD(v145));
      v279 = 0;
      v307 = 0;
      v261 = 0;
      if (LODWORD(v163) >= LODWORD(v172) )
        goto LABEL_181;
      v182 = LODWORD(v172) - LODWORD(v163);
      v197 = a2 + a5 * LODWORD(v163);
      do
      {
        v104 = LODWORD(v145);
        v205 = LODWORD(v145);
        while ( v104 < LODWORD(v154) )
        {
          v105 = *(_BYTE *)(v197 + v205);
          if ( a10 )
          {
            v245 = 1;
            v97 = v105 != a11 ? 0xFF : 0;
          }
          v106 = sub_450FB1(v217, v105);
          if ( v245 )
          {
            v261 += v97;
            v245 = 0;
            if ( !v97 )
            {
              --v103;
              goto LABEL_178;
            }
          }
          else
          {
            v261 += (unsigned int)v106 >> 24;
          }
          v307 += BYTE2(v106);
          v279 += BYTE1(v106);
          v270 += (unsigned __int8)v106;
LABEL_178:
          ++v205;
          v104 = v205;
        }
        v197 += a5;
      }
      while ( v182-- != 1 );
LABEL_181:
      v108 = v261 / ((LODWORD(v172) - LODWORD(v163)) * (LODWORD(v154) - LODWORD(v145)));
      if ( v103 )
      {
        v307 /= v103;
        v279 /= v103;
        v270 /= v103;
      }
      if ( v108 != 255 )
        v108 &= 0x7FFFFFFFu;
      v109 = sub_450F55(v217, v270 | ((v279 | ((v307 | (v108 << 8)) << 8)) << 8));
      v110 = v214;
      v214 += 4;
      *(_DWORD *)v110 = v109;
      v98 = v224;
      v306 = v224;
    }
    while ( v224 < a7 );
LABEL_186:
    v214 += v322;
    ++v252;
    result = v252;
    if ( v252 < a8 )
    {
      v12 = 0;
      continue;
    }
    return result;
  }
}

//----- (0045271F) --------------------------------------------------------
signed int __thiscall sub_45271F(int _this)
{
  int v1; // ebx@1
  int v2; // esi@1
  int v3; // eax@2
  unsigned int *v4; // edi@3
  size_t *v5; // edi@6
  FILE *v6; // ST24_4@6
  int v7; // ebx@7
  signed int v9; // [sp+0h] [bp-8h]@6
  FILE *v10; // [sp+4h] [bp-4h]@6

  v2 = _this;
  v1 = 0;
  if ( *(_DWORD *)(_this + 400016) )
  {
    v10 = fopen("logd3d.txt", "w");
    v6 = *(FILE **)v2;
    v5 = (size_t *)(v2 + 12);
    *(_DWORD *)(v2 + 8) = ftell(*(FILE **)v2);
    locked_fwrite((const void *)(v2 + 12), 4u, 1u, v6);
    v9 = 0;
    if ( *(_DWORD *)(v2 + 12) > 0 )
    {
      v7 = v2 + 16;
      do
      {
        locked_fwrite(*(const void **)v7, 1u, 0x14u, *(FILE **)v2);
        fprintf(v10, "D3D texture name:  %s\t\toffset: %x\n", *(_DWORD *)v7, *(_DWORD *)(v7 + 200000));
        ++v9;
        v7 += 4;
      }
      while ( v9 < (signed int)*v5 );
      v1 = 0;
    }
    locked_fwrite((const void *)(v2 + 200016), 4u, *v5, *(FILE **)v2);
    fseek(*(FILE **)v2, 4, v1);
    locked_fwrite((const void *)(v2 + 8), 4u, 1u, *(FILE **)v2);
    fclose(*(FILE **)v2);
    fclose(v10);
  }
  else
  {
    v3 = fclose(*(FILE **)_this);
    if ( *(_DWORD *)(v2 + 12) > 0 )
    {
      v4 = (unsigned int *)(v2 + 16);
      do
      {
        /*v3 = */operator_delete((void *)*v4);
        ++v1;
        ++v4;
      }
      while ( v1 < *(_DWORD *)(v2 + 12) );
    }
  }
  return 1;
}

//int __thiscall sub_45281E(void *_this, int X, int a3)
//{
//  int v3; // eax@1
//  int v4; // ecx@1
//  int v5; // ebx@1
//  signed int v6; // edi@1
//  void *v7; // esi@1
//  int result; // eax@5
//  signed int v9; // ebx@14
//  int v10; // eax@20
//  int v11; // edx@20
//  signed __int64 v12; // qtt@20
//  int v13; // eax@38
//  int v14; // ecx@38
//  int v15; // eax@43
//  signed int v16; // [sp-4h] [bp-10h]@13
//
//  v7 = _this;
//  v6 = a3;
//  v5 = abs(X);
//  v3 = abs(a3);
//  v4 = 0;
//  if ( v5 < 65536 )
//  {
//    if ( v3 >> 15 >= v5 )
//      X = 0;
//  }
//  if ( !X )
//  {
//    result = *((_DWORD *)v7 + 1561);
//    if ( a3 <= 0 )
//      result += *((_DWORD *)v7 + 1560);
//    return result;
//  }
//  if ( a3 )
//  {
//    if ( X <= 0 )
//    {
//      X = -X;
//      if ( a3 >= 0 )
//      {
//        v16 = 4;
//        goto LABEL_19;
//      }
//      v16 = 3;
//    }
//    else
//    {
//      if ( a3 >= 0 )
//      {
//        v9 = 1;
//        goto LABEL_20;
//      }
//      v16 = 2;
//    }
//    v6 = -a3;
//LABEL_19:
//    v9 = v16;
//LABEL_20:
//    LODWORD(v12) = v6 << 16;
//    HIDWORD(v12) = v6 >> 16;
//    v10 = *((_DWORD *)v7 + 1561);
//    v11 = v12 / X;
//    if ( v11 <= *((_DWORD *)v7 + (*((_DWORD *)v7 + 1561) >> 1)) )
//      v10 = *((_DWORD *)v7 + 1561) >> 1;
//    else
//      v4 = *((_DWORD *)v7 + 1561) >> 1;
//    if ( v11 <= *((_DWORD *)v7 + ((v4 + v10) >> 1)) )
//      v10 = (v4 + v10) >> 1;
//    else
//      v4 = (v4 + v10) >> 1;
//    if ( v11 <= *((_DWORD *)v7 + ((v4 + v10) >> 1)) )
//      v10 = (v4 + v10) >> 1;
//    else
//      v4 = (v4 + v10) >> 1;
//    if ( v11 <= *((_DWORD *)v7 + ((v4 + v10) >> 1)) )
//      v10 = (v4 + v10) >> 1;
//    else
//      v4 = (v4 + v10) >> 1;
//    if ( v11 <= *((_DWORD *)v7 + ((v4 + v10) >> 1)) )
//      v10 = (v4 + v10) >> 1;
//    else
//      v4 = (v4 + v10) >> 1;
//    if ( v11 <= *((_DWORD *)v7 + ((v4 + v10) >> 1)) )
//      v10 = (v4 + v10) >> 1;
//    else
//      v4 = (v4 + v10) >> 1;
//    v14 = v4 + 1;
//    v13 = v10 - 1;
//    while ( v14 < v13 && v11 >= *((_DWORD *)v7 + v14) )
//      ++v14;
//    if ( v9 == 2 )
//    {
//      v15 = *((_DWORD *)v7 + 1562);
//    }
//    else
//    {
//      if ( v9 == 3 )
//        return v14 + *((_DWORD *)v7 + 1560);
//      if ( v9 != 4 )
//        return v14;
//      v15 = *((_DWORD *)v7 + 1560);
//    }
//    return v15 - v14;
//  }
//  if ( X <= 0 )
//    result = *((_DWORD *)v7 + 1560);
//  else
//    result = 0;
//  return result;
//}

//----- (00452A9E) --------------------------------------------------------
signed int __fastcall sub_452A9E(signed int a1)
{
  signed int result; // eax@2
  int v2; // edx@3
  signed int v3; // ebx@3
  unsigned int v4; // edi@3
  int v5; // esi@4

  if ( a1 > 1 )
  {
    v2 = 0;
    v4 = a1;
    result = 0;
    v3 = 16;
    do
    {
      result *= 2;
      v2 = (v4 >> 30) | 4 * v2;
      v5 = 2 * result + 1;
      v4 *= 4;
      if ( v2 >= (unsigned int)v5 )
      {
        ++result;
        v2 -= v5;
      }
      --v3;
    }
    while ( v3 );
    if ( a1 - result * result >= (unsigned int)(result - 1) )
      ++result;
  }
  else
  {
    result = a1;
  }
  return result;
}

//----- (00452AE2) --------------------------------------------------------
int __fastcall MakeColorMaskFromBitDepth(int a1)
{
  signed __int64 v1; // qax@1

  v1 = 4294967296i64;
  if ( a1 > 0 )
  {
    do
    {
      LODWORD(v1) = HIDWORD(v1) + v1;
      HIDWORD(v1) *= 2;
      --a1;
    }
    while ( a1 );
  }
  return v1;
}

//----- (00452AF3) -----------.text:00453C52 ---------------------------------------------
void sub_452AF3(int a1, unsigned int *pRenderTarget, unsigned int a3)
{
  int result; // eax@1
  void *v4; // edi@1
  int i; // ecx@3
  int v6; // edi@3

  v4 = (void *)pRenderTarget;
  result = a1 | (a1 << 16);
  if ( (unsigned int)pRenderTarget & 4)
  {
    *pRenderTarget = result;
    v4 = pRenderTarget + 1;
    --a3;
  }

  memset_dw(v4, result, 4 * 2 * (a3 / 2));

  v6 = (int)((char *)v4 + 4 * 2 * (a3 / 2));
  for ( i = a3 & 1; i; --i )
  {
    *(_DWORD *)v6 = result;
    v6 += 4;
  }

}

//----- (00452B2E) --------------------------------------------------------
int __fastcall sub_452B2E(int a1, signed int a2)
{
  signed int v2; // edi@1
  int v3; // esi@1
  int result; // eax@2
  int v5; // ebx@4

  v2 = a2;
  v3 = 0;
  if ( a2 )
  {
    if ( a1 > 0 )
    {
      v5 = a1;
      do
      {
        --v5;
        v3 += rand() % v2 + 1;
      }
      while ( v5 );
    }
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00452B58) --------------------------------------------------------
int __fastcall memset_dw(void *a2, int a1, int a3)
{
  int i;

  for(i = 0;i < a3; i++)
    *((_DWORD*)a2 + i) = a1;
  //memset(a2, a1, 4 * a3);
  return a1;
}

//----- (004563FF) --------------------------------------------------------
signed int __thiscall sub_4563FF(int _this, const char *Str2)
{
  signed int v2; // ebx@1
  int v3; // esi@1
  int v4; // edi@2
  signed int result; // eax@6

  v3 = _this;
  v2 = 1;
  if ( *(_DWORD *)(_this + 23444) <= 1 )
  {
LABEL_6:
    result = -1;
  }
  else
  {
    v4 = _this + 88;
    while ( !*(_DWORD *)v4 || _strcmpi(*(const char **)(v4 + 4), Str2) )
    {
      ++v2;
      v4 += 88;
      if ( v2 >= *(_DWORD *)(v3 + 23444) )
        goto LABEL_6;
    }
    result = v2;
  }
  return result;
}

//----- (00456442) --------------------------------------------------------
int __thiscall ItemGen_sub_456442(ItemGen *_this)
{
  int v1; // edi@1
  int v2; // esi@1
  int v3; // eax@4
  int v4; // esi@5
  int result; // eax@7

  v2 = (int)_this;
  v1 = dword_5D29F4[12 * _this->uItemID];
  if ( *(_BYTE *)((int)_this + 20) & 8 || class40_sub_456D5E(pClass40, _this) )
    goto LABEL_12;
  if ( *(_DWORD *)(v2 + 4) )
  {
    v3 = 100 * *(_DWORD *)(v2 + 8);
    return v1 + v3;
  }
  v4 = *(_DWORD *)(v2 + 12);
  if ( !v4 )
  {
LABEL_12:
    result = v1;
  }
  else
  {
    v3 = dword_5DC1BC[7 * v4];
    if ( (unsigned int)v3 > 0xA )
      return v1 + v3;
    result = v1 * v3;
  }
  return result;
}

//----- (00456499) --------------------------------------------------------
int __thiscall ItemGen_sub_456499(ItemGen *_this)
{
  int result; // eax@2

  if ( *((_BYTE *)_this + 20) & 1 )
    result = ItemGen_sub_4564B3(_this);
  else
    result = dword_5D29EC[12 * _this->uItemID];
  return result;
}

//----- (004564B3) --------------------------------------------------------
int __thiscall ItemGen_sub_4564B3(ItemGen *_this)
{
  //int v1; // eax@1
  char v2; // cl@1
  int v3; // esi@1
  int v4; // edi@4
  unsigned __int8 v5; // al@6
  const char *v6; // esi@8
  int v7; // eax@15
  int v9; // [sp-Ch] [bp-14h]@14
  int v10; // [sp-8h] [bp-10h]@4
  const char *v11; // [sp-4h] [bp-Ch]@4

  v3 = (int)_this;
  //v1 = 48 * _this->uItemID;
  v2 = pClass40->pItems[_this->uItemID].uEquipType;
  if (v2 >= 0x0D && ((unsigned __int8)v2 <= 0xEu || v2 == 18) )
  {
    v11 = (char *)pClass40->pItems[_this->uItemID].pName;
    v4 = (int)byte_5C8678;
    v10 = (int)"%s";
LABEL_10:
    wsprintfA((char *)v4, (const char *)v10, v11);
    return v4;
  }
  v4 = (int)byte_5C8678;
  wsprintfA(byte_5C8678, "%s", pClass40->pItems[_this->uItemID].pName);
  if (_this->uItemID == 601 )
  {
    v5 = *(_BYTE *)(v3 + 26);
    if ( v5 >= 1u )
    {
      if ( v5 <= 4u )
      {
        v6 = (char *)pPlayers[v5] + 168;
        strlen(v6);
        v11 = v6;
        if ( v6[strlen(v6) - 1] == 115 )
          v10 = (int)pGlobalTXT_LocalizationStrings[655];
        else
          v10 = (int)pGlobalTXT_LocalizationStrings[654];
        goto LABEL_10;
      }
    }
  }
  if ( !class40_sub_456D5E(pClass40, (ItemGen *)v3) )
  {
    if ( *(_DWORD *)(v3 + 4) )
    {
      strcat(byte_5C8678, " ");
      v9 = dword_5DBFD0[5 * *(_DWORD *)(v3 + 4)];
    }
    else
    {
      v7 = *(_DWORD *)(v3 + 12);
      if ( !v7 )
        return v4;
      if ( v7 == 16
        || v7 == 39
        || v7 == 40
        || v7 == 45
        || v7 == 56
        || v7 == 57
        || v7 == 58
        || v7 == 60
        || v7 == 61
        || v7 == 59
        || v7 == 63
        || v7 == 64
        || v7 == 67
        || v7 == 68 )
      {
        wsprintfA(byte_5C8678, "%s %s", dword_5DC1A8[7 * v7], pClass40->pItems[*(_DWORD *)v3].pName);
        return v4;
      }
      strcat(byte_5C8678, " ");
      v9 = dword_5DC1A8[7 * *(_DWORD *)(v3 + 12)];
    }
    strcat(byte_5C8678, (const char *)v9);
  }
  return v4;
}

//----- (00456D43) --------------------------------------------------------
bool class40_sub_456D43(class40 *_this, ItemGen *pItem)
{
  return *((_BYTE *)_this + 48 * pItem->uItemID + 37) == 3;
}

//----- (00456D5E) --------------------------------------------------------
bool class40_sub_456D5E(struct class40 *_this, ItemGen *pItem)
{
  char v2; // al@1

  v2 = *((_BYTE *)_this + 48 * pItem->uItemID + 37);
  return v2 == 3 || v2 == 1 || v2 == 2;
}

//----- (0045814E) --------------------------------------------------------
int __thiscall class40_sub_45814E(void *_this)
{
  void *v1; // edi@1
  int result; // eax@23

  v1 = _this;
  if ( pMonstersTXT_Raw )
    //MemFree( (void *)pMonstersTXT_Raw);
    MemFree(pMonstersTXT_Raw);
  if ( pMonsterPlacementTXT_Raw )  //not alloc
    //MemFree( (void *)pMonsterPlacementTXT_Raw);
    MemFree(pMonsterPlacementTXT_Raw);
  if ( pClassDescriptions )
    //MemFree( (void *)pClassDescriptions);
    MemFree(pClassDescriptions);
  if ( *((_DWORD *)v1 + 17824) )		 //not allocade
       MemFree( (void *)*((_DWORD *)v1 + 17824));
  if ( *((_DWORD *)v1 + 17823) )
    MemFree( (void *)*((_DWORD *)v1 + 17823));
  if ( *((_DWORD *)v1 + 17822) )
    MemFree( (void *)*((_DWORD *)v1 + 17822));
  if ( *((_DWORD *)v1 + 17821) )
    MemFree( (void *)*((_DWORD *)v1 + 17821));
  if ( pHostileTXT_Raw )
    MemFree( (void *)pHostileTXT_Raw);
  if ( pHistoryTXT_Raw )
    MemFree( (void *)pHistoryTXT_Raw);
  if (pPotionsTXT_Raw)
    MemFree( (void *)pPotionsTXT_Raw);
  if ( pPotionNotesTXT_Raw )
    MemFree( (void *)pPotionNotesTXT_Raw);
  *((_DWORD *)v1 + 17824) = 0;
  pClassDescriptions[0] = 0;
  *((_DWORD *)v1 + 17823) = 0;
  *((_DWORD *)v1 + 17822) = 0;
  result = 0;
  *((_DWORD *)v1 + 17821) = 0;
  return result;
}

//----- (00458244) --------------------------------------------------------
int sub_458244_GetSkillMasteryLevel(unsigned int uSkillLevel)
{
  if (uSkillLevel & 0x100)
    return 4; // Magister
  else
  {
    if ( (_BYTE)uSkillLevel >= 0 )
    {
      if (uSkillLevel & 0x40 )
        return 2; // Expert
    }
   else return 3; // Master
  }
  return 1; // Normal
}

//----- (00458260) --------------------------------------------------------
char __thiscall sub_458260(int _this, __int64 a2)
{
  int v2; // eax@1

  v2 = *(_DWORD *)(_this + 20);
  if ( v2 & 8 )
  {
    if ( a2 > *(_QWORD *)(_this + 28) )
    {
      *(_DWORD *)(_this + 4) = 0;
      LOBYTE(v2) = v2 & 0xF7;
      *(_DWORD *)(_this + 12) = 0;
      *(_DWORD *)(_this + 20) = v2;
    }
  }
  return v2;
}

//----- (0045828B) --------------------------------------------------------
unsigned int __fastcall sub_45828B(signed int a1)
{
  unsigned __int16 v1; // dx@3
  unsigned __int16 v2; // cx@6
  unsigned __int16 v4; // [sp-4h] [bp-4h]@3

  if ( a1 < 1 )
  {
    if ( a1 < 12 )
    {
      if ( a1 < 23 )
      {
        if ( a1 < 34 )
        {
          if ( a1 < 45 )
          {
            if ( a1 < 56 )
            {
              if ( a1 < 67 )
              {
                if ( a1 < 78 )
                {
                  if ( a1 < 89 )
                    goto LABEL_31;
                  goto LABEL_28;
                }
LABEL_25:
                if ( a1 < 89 )
                {
                  v4 = 155;
                  v2 = 255;
                  goto LABEL_30;
                }
LABEL_28:
                if ( a1 < 100 )
                {
                  v4 = 240;
                  v2 = 192;
                  goto LABEL_30;
                }
LABEL_31:
                v4 = 0;
                v1 = 0;
                goto LABEL_32;
              }
LABEL_21:
              if ( a1 < 78 )
              {
                v4 = 0;
                v1 = 128;
                goto LABEL_23;
              }
              goto LABEL_25;
            }
LABEL_18:
            if ( a1 < 67 )
            {
              v4 = 255;
              v1 = 15;
              v2 = 235;
              return 0xFFEB0FFF;
            }
            goto LABEL_21;
          }
LABEL_15:
          if ( a1 < 56 )
          {
            v2 = 225;
            goto LABEL_13;
          }
          goto LABEL_18;
        }
LABEL_11:
        if ( a1 < 45 )
        {
          v2 = 128;
LABEL_13:
          v4 = v2;
LABEL_30:
          v1 = v2;
          return 0xFF000000 | (v2 << 16) | (v1 << 8) | v4;
        }
        goto LABEL_15;
      }
LABEL_8:
      if ( a1 < 34 )
      {
        v4 = 255;
        v1 = 128;
LABEL_32:
        v2 = 0;
        return 0xFF000000 | (v1 << 8) | v4;
      }
      goto LABEL_11;
    }
  }
  else
  {
    if ( a1 < 12 )
    {
      v4 = 0;
      v1 = 85;
LABEL_23:
      v2 = 255;
      return 0xFFFF0000 | (v1 << 8) | v4;
    }
  }
  if ( a1 >= 23 )
    goto LABEL_8;
  v4 = 255;
  v1 = 212;
  v2 = 150;
  return 0xFF96D4FF;
}

//----- (004583B0) --------------------------------------------------------
int __thiscall sub_4583B0(int _this)
{
  int result; // eax@1

  result = _this;
  *(_WORD *)(_this + 26) = 0;
  *(_WORD *)(_this + 24) = 0;
  *(_DWORD *)(_this + 12) = 0;
  *(_DWORD *)(_this + 8) = 0;
  *(_DWORD *)_this = 0;
  *(_WORD *)(_this + 2) = 0;
  *(_WORD *)(_this + 22) = 0;
  *(_WORD *)(_this + 20) = 0;
  return result;
}

//----- (004584B8) --------------------------------------------------------
int __thiscall sub_4584B8(int _this)
{
  int result; // eax@1

  result = _this;
  *(_WORD *)(_this + 10) = 0;
  *(_WORD *)(_this + 8) = 0;
  *(_WORD *)(_this + 6) = 0;
  *(_WORD *)(_this + 4) = 0;
  *(_WORD *)(_this + 2) = 0;
  *(_WORD *)(_this + 12) = 0;
  *(_WORD *)(_this + 14) = 0;
  *(_DWORD *)(_this + 16) = 65536;
  return result;
}

//----- (004584E0) --------------------------------------------------------
signed int __thiscall SpellBuf_sub_4584E0(struct SpellBuff *_this, unsigned int a2, int a3, __int16 a4, __int16 a5, int a6, char a7)
{
  int v7; // eax@1
  int v8; // esi@1
  signed int result; // eax@5
  int v10; // eax@6

  v8 = (int)_this;
  v7 = *(_DWORD *)(v8 + 4);
  if ( *(_QWORD *)_this && a3 <= v7 && (a3 < v7 || a2 < *(_DWORD *)_this) )
  {
    result = 0;
  }
  else
  {
    *(_WORD *)(v8 + 10) = a4;
    *(_WORD *)(v8 + 8) = a5;
    LOWORD(v10) = *(_WORD *)(_this + 12);
    *(_DWORD *)_this = a2;
    *(_DWORD *)(v8 + 4) = a3;
    if ( (_WORD)v10 )
    {
      v10 = (unsigned __int16)v10;
      if ( (unsigned __int16)v10 != a6 )
      {
        sub_45855F((void *)(20 * v10 + 0x5E4D44));
        dword_5E5144 = 1;
        *(_WORD *)(v8 + 12) = 0;
      }
    }
    *(_WORD *)(v8 + 12) = a6;
    *(_BYTE *)(v8 + 14) = a7;
    result = 1;
  }
  return result;
}

//----- (004585CA) --------------------------------------------------------
signed int __thiscall SpellBuff_sub_4585CA(struct SpellBuff *_this, unsigned int a2, int a3)
{
 int v0;
  int v3; // eax@1
  signed int result; // eax@5

 v0 = (int)_this;
  v3 = *(_DWORD *)(v0 + 4);
  if ( *(_QWORD *)v0 && v3 <= a3 && (v3 < a3 || *(_DWORD *)v0 < a2) )
  {
    *(_DWORD *)v0 = 0;
    *(_DWORD *)(v0 + 4) = 0;
    *(_WORD *)(v0 + 8) = 0;
    *(_WORD *)(v0 + 10) = 0;
    *(_WORD *)(v0 + 12) = 0;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}


//----- (00458B03) --------------------------------------------------------
int __thiscall sub_458B03(void *Str)
{
  FILE *v1; // eax@1
  FILE *v2; // edi@1
  void *v3; // esi@1

  v3 = Str;
  v1 = fopen("data\\dchest.bin", "wb");
  v2 = v1;
  if ( !v1 )
    erroneous_printf("Unable to save dchest.bin!");
  locked_fwrite(v3, 4u, 1u, v1);
  locked_fwrite(*((const void **)v3 + 1), 0x24u, *(_DWORD *)v3, v2);
  return fclose(v2);
}

//----- (00458B9C) --------------------------------------------------------
signed int __thiscall sub_458B9C(int _this, const char *a2)
{
  FILE *v2; // eax@1
  int v3; // ebx@1
  __int32 v4; // edi@1
  int v5; // esi@3
  int v6; // eax@9
  int v7; // ST18_4@9
  char *i; // eax@11
  FILE *v9; // ST0C_4@11
  const char *v10; // ST14_4@14
  const char *v11; // ST10_4@14
  char Buf; // [sp+8h] [bp-2F0h]@3
  char v14; // [sp+1FCh] [bp-FCh]@4
  int v15; // [sp+278h] [bp-80h]@4
  char *Source; // [sp+27Ch] [bp-7Ch]@5
  char *Str; // [sp+280h] [bp-78h]@14
  const char *v18; // [sp+284h] [bp-74h]@14
  const char *v19; // [sp+288h] [bp-70h]@14
  FILE *File; // [sp+2F4h] [bp-4h]@1
  int v21; // [sp+300h] [bp+8h]@3

  v3 = _this;
  MemFree( (void *)*(_DWORD **)(_this + 4));
  v4 = 0;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)v3 = 0;
  v2 = fopen(a2, "r");
  File = v2;
  if ( !v2 )
    erroneous_printf("ChestDescriptionList::load - Unable to open file: %s.");
  v5 = 0;
  v21 = 0;
  if ( fgets(&Buf, 490, v2) )
  {
    do
    {
      *strchr(&Buf, 10) = 0;
      memcpy(&v15, sub_4BE3BF((unsigned char *)&Buf, (StringSplitter *)&v14), 0x7Cu);
      if ( v15 )
      {
        if ( *Source != 47 )
          ++v21;
      }
    }
    while ( fgets(&Buf, 490, File) );
    v5 = v21;
    v4 = 0;
  }
  v7 = *(_DWORD *)(v3 + 4);
  *(_DWORD *)v3 = v5;
  v6 = (int)NamedMemAlloc(char, 36 * v5, "Chest Descrip");
  *(_DWORD *)(v3 + 4) = v6;
  if ( v6 == v4 )
    erroneous_printf("ChestDescriptionList::load - Out of Memory!");
  memset((void *)v6, v4, 36 * *(_DWORD *)v3);
  v9 = File;
  *(_DWORD *)v3 = v4;
  fseek(v9, v4, v4);
  for ( i = fgets(&Buf, 490, File); i; i = fgets(&Buf, 490, File) )
  {
    *strchr(&Buf, 10) = 0;
    memcpy(&v15, sub_4BE3BF((unsigned char *)&Buf, (StringSplitter *)&v14), 0x7Cu);
    if ( v15 )
    {
      if ( *Source != 47 )
      {
        strcpy((char *)(*(_DWORD *)(v3 + 4) + 36 * *(_DWORD *)v3), Source);
        v10 = v18;
        *(_BYTE *)(*(_DWORD *)(v3 + 4) + 36 * *(_DWORD *)v3 + 32) = atoi(Str);
        v11 = v19;
        *(_BYTE *)(*(_DWORD *)(v3 + 4) + 36 * *(_DWORD *)v3 + 33) = atoi(v10);
        *(_WORD *)(*(_DWORD *)(v3 + 4) + 36 * *(_DWORD *)v3++ + 34) = atoi(v11);
      }
    }
  }
  fclose(File);
  return 1;
}

//----- (00459667) --------------------------------------------------------
void __thiscall sub_459667(int _this)
{
  *(_WORD *)(_this + 176) = 11;
}

//----- (00459860) --------------------------------------------------------
int __thiscall sub_459860(void *Str)
{
  FILE *v1; // eax@1
  FILE *v2; // edi@1
  void *v3; // esi@1

  v3 = Str;
  v1 = fopen("data\\dmonlist.bin", "wb");
  v2 = v1;
  if ( !v1 )
    erroneous_printf("Unable to save dmonlist.bin!");
  locked_fwrite(v3, 4u, 1u, v1);
  locked_fwrite(*((const void **)v3 + 1), 0x98u, *(_DWORD *)v3, v2);
  return fclose(v2);
}

//----- (004598FC) --------------------------------------------------------
signed int __thiscall sub_4598FC(int _this, const char *a2)
{
  FILE *v2; // eax@1
  int v3; // ebx@1
  int v4; // esi@3
  int v5; // eax@9
  char *i; // eax@11
  FILE *v7; // ST14_4@11
  signed int v8; // esi@12
  signed int v9; // esi@16
  const char *v10; // ST18_4@16
  const char *v11; // ST14_4@16
  const char *v12; // ST10_4@16
  const char *v13; // ST0C_4@16
  int v14; // esi@16
  unsigned __int8 v15; // al@16
  __int16 v16; // ax@17
  int v17; // ecx@17
  char Buf; // [sp+4h] [bp-304h]@3
  char v20; // [sp+1F8h] [bp-110h]@4
  int v21; // [sp+274h] [bp-94h]@4
  char *Source[8]; // [sp+278h] [bp-90h]@5
  char *Str; // [sp+298h] [bp-70h]@16
  const char *v24; // [sp+29Ch] [bp-6Ch]@16
  const char *v25; // [sp+2A0h] [bp-68h]@16
  const char *v26; // [sp+2A4h] [bp-64h]@16
  const char *v27; // [sp+2A8h] [bp-60h]@16
  const char *v28; // [sp+2ACh] [bp-5Ch]@16
  const char *v29; // [sp+2B0h] [bp-58h]@16
  const char *v30; // [sp+2B4h] [bp-54h]@16
  int v31[13]; // [sp+2BCh] [bp-4Ch]@17
  int v32; // [sp+2F0h] [bp-18h]@16
  char v33; // [sp+2F4h] [bp-14h]@14
  char v34; // [sp+2F5h] [bp-13h]@14
  char v35; // [sp+2F6h] [bp-12h]@14
  char v36; // [sp+2F7h] [bp-11h]@14
  char v37; // [sp+2F8h] [bp-10h]@14
  char v38; // [sp+2F9h] [bp-Fh]@14
  char v39; // [sp+2FAh] [bp-Eh]@14
  char v40; // [sp+2FBh] [bp-Dh]@14
  char v41; // [sp+2FCh] [bp-Ch]@14
  char v42; // [sp+2FDh] [bp-Bh]@14
  char v43; // [sp+2FEh] [bp-Ah]@14
  char v44; // [sp+2FFh] [bp-9h]@14
  char v45; // [sp+300h] [bp-8h]@14
  char v46; // [sp+301h] [bp-7h]@14
  char v47; // [sp+302h] [bp-6h]@14
  char v48; // [sp+303h] [bp-5h]@14
  FILE *File; // [sp+304h] [bp-4h]@1
  int v50; // [sp+310h] [bp+8h]@3
  int v51; // [sp+310h] [bp+8h]@16

  v3 = _this;
  sub_487E1D(_this);
  v2 = fopen(a2, "r");
  File = v2;
  if ( !v2 )
    erroneous_printf("MonsterRaceListStruct::load - Unable to open file: %s.");
  v4 = 0;
  v50 = 0;
  if ( fgets(&Buf, 490, v2) )
  {
    do
    {
      *strchr(&Buf, 10) = 0;
      memcpy(&v21, sub_4BE485(&Buf, &v20), 0x7Cu);
      if ( v21 )
      {
        if ( *Source[0] != 47 )
          ++v50;
      }
    }
    while ( fgets(&Buf, 490, File) );
    v4 = v50;
  }
  *(_DWORD *)v3 = v4;
  //mem_mng.AllocatedNamedBuffer(
  v5 = (int)NamedMemAlloc(char, 152 * v4, "Mon Race");
  *(_DWORD *)(v3 + 4) = v5;
  if ( !v5 )
    erroneous_printf("MonsterRaceListStruct::load - Out of Memory!");
  v7 = File;
  *(_DWORD *)v3 = 0;
  fseek(v7, 0, 0);
  for ( i = fgets(&Buf, 490, File); i; i = fgets(&Buf, 490, File) )
  {
    *strchr(&Buf, 10) = 0;
    memcpy(&v21, sub_4BE485(&Buf, &v20), 0x7Cu);
    v8 = 0;
    if ( v21 )
    {
      if ( *Source[0] != 47 )
      {
        strcpy((char *)(152 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20), Source[0]);
        v41 = 0;
        v42 = 1;
        v43 = 7;
        v44 = 2;
        v45 = 3;
        v46 = 4;
        v47 = 5;
        v48 = 6;
        v33 = 1;
        v34 = 2;
        v35 = 3;
        v36 = 4;
        v37 = 4;
        v38 = 5;
        v39 = 6;
        v40 = 7;
        do
        {
          strcpy(
            (char *)(152 * *(_DWORD *)v3 + 10 * (unsigned __int8)*(&v41 + v8) + *(_DWORD *)(v3 + 4) + 52),
            Source[(unsigned __int8)*(&v33 + v8)]);
          ++v8;
        }
        while ( v8 < 8 );
        v10 = v24;
        *(_WORD *)(152 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4)) = atoi(Str);
        v11 = v25;
        *(_WORD *)(152 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 4) = atoi(v10);
        v12 = v26;
        *(_WORD *)(152 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 2) = atoi(v11);
        v13 = v27;
        *(_WORD *)(152 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 6) = atoi(v12);
        v14 = (unsigned __int8)atoi(v13);
        v51 = (unsigned __int8)atoi(v28);
        LOBYTE(v32) = atoi(v29);
        v32 = (unsigned __int8)v32;
        v15 = atoi(v30);
        *(_DWORD *)(152 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 8) = v15 | ((v32 | ((v51 | (v14 << 8)) << 8)) << 8);
        v9 = 0;
        do
        {
          v16 = atoi((const char *)v31[v9]);
          v17 = v9++ + 76 * *(_DWORD *)v3;
          *(_WORD *)(*(_DWORD *)(v3 + 4) + 2 * v17 + 12) = v16;
        }
        while ( v9 < 4 );
        ++*(_DWORD *)v3;
      }
    }
  }
  fclose(File);
  return 1;
}

//----- (00459C2B) --------------------------------------------------------
void GUIWindow_sub_459C2B(GUI::Window *a1, signed int a2, int a3, int a4)
{
  unsigned int v4; // eax@1
  signed int v6; // esi@1
  unsigned int v7; // ett@1

  v6 = a2;
  v7 = GetTickCount();
  v4 = v7 / 0x3E8;
  if ( v7 % 0x3E8 > 0x1F4 )
    FontDrawText(a1, (Font *)a4, v6, a3, "_", 0, 0, 0);
}


//----- (0045B15E) --------------------------------------------------------
BOOL __thiscall sub_45B15E(int _this)
{
  int v1; // ecx@1
  int v2; // edi@1
  int v3; // esi@1

  v3 = _this;
  v2 = _this + 1804;
  *(_DWORD *)_this = 5080760;
  v1 = *(_DWORD *)(_this + 1804);
  if ( v1 )
    (**(void (__stdcall ***)(_DWORD))v1)(1);
  *(_DWORD *)v2 = 0;
  return TerminateThread(*(HANDLE *)(v3 + 4), 0x1F4u);
}

//----- (0045B1B1) --------------------------------------------------------
void *__thiscall sub_45B1B1(int _this)
{
  int v2; // esi@1

  v2 = _this;
  memset((void *)(_this + 9), 0, 0x100u);
  memset((void *)(v2 + 265), 0, 0x100u);
  memset((void *)(v2 + 521), 0, 0x100u);
  return memset((void *)(v2 + 780), 0, 0x400u);
}

//----- (0045B229) --------------------------------------------------------
char __thiscall sub_45B229(DWORD lpParameter)
{
  HANDLE v1; // eax@1
  LPVOID v2; // esi@1
  char result; // al@2
  DWORD ThreadId; // [sp+0h] [bp-4h]@1

  ThreadId = lpParameter;
  v2 = (LPVOID)lpParameter;
  v1 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartAddress, (LPVOID)lpParameter, 4u, &ThreadId);
  *((_DWORD *)v2 + 1) = (int)v1;
  if ( v1 )
    result = SetThreadPriority(v1, 15) != 0;
  else
    result = 0;
  return result;
}

//----- (0045B260) --------------------------------------------------------
char __thiscall sub_45B260(void *_this)
{
  int v1; // ecx@1
  void *v2; // esi@1
  int v3; // eax@2

  v2 = _this;
  compile_error();//v1 = (int)operator new(0x120u);
  if ( v1 )
    v3 = sub_43B76D(v1);
  else
    v3 = 0;
  *((_DWORD *)v2 + 451) = v3;
  return v3 != 0;
}

//----- (0045B3A4) --------------------------------------------------------
char __thiscall sub_45B3A4(int _this)
{
  *(_BYTE *)(_this + 8) = 1;
  Sleep(0x85u);
  return 1;
}


//----- (0045BA60) --------------------------------------------------------
void __stdcall StartAddress(int a1)
{
  while ( 1 )
  {
    while ( !pAsyncKeyboard )
      ;
    if ( *(_BYTE *)(pAsyncKeyboard + 8) )
      ExitThread(0);
    CAsyncKeyboard_update_keyboard_data(pAsyncKeyboard);
    Sleep(33);
  }
}

//----- (0045BAB6) --------------------------------------------------------
int __fastcall sub_45BAB6(int a1)
{
  size_t v2; // eax@1

  byte_69BD44 = BYTE3(a1);
  Game_stru0_sub_40E2F6((Game_stru0 *)&byte_69BD44, 0);
  v2 = strlen("effpar03");
  return sub_40E32E((int)&byte_69BD44, "effpar03", v2);
}

//----- (0045BAE9) --------------------------------------------------------
void __cdecl sub_45BAE9()
{
  if ( !(byte_69BD41 & 1) )
  {
    byte_69BD41 |= 1u;
    Game_stru0_sub_40E2F6((Game_stru0 *)&byte_69BD44, 1);
  }
}

//----- (0045BBAA) --------------------------------------------------------
int __thiscall sub_45BBAA(void *_this)
{
  void *v2; // esi@1

  v2 = _this;
  *(_DWORD *)_this = 5080800;
  _eh_vector_destructor_iterator_((int)_this + 1587208, 3100, 768, (void (__fastcall *)(void *))class04_stru0_detor);
  _eh_vector_destructor_iterator_((int)v2 + 4, 3100, 512, (void (__fastcall *)(void *))class04_stru0_detor);
return 0;
}

void loc_45BE7B()
{
 //unk
}

//----- (0045BC07) --------------------------------------------------------
char __thiscall sub_45BC07(void *_this, int a2, int a3, signed int a4, int a5, float a6, int a7)
{
  _UNKNOWN *v7; // eax@3
  signed int v8; // ecx@3
  _UNKNOWN *v9; // eax@10
  int v10; // edx@10
  const void *v11; // esi@11
  void *v12; // edi@11
  char v13; // zf@11
  int v14; // esi@12
  double v16; // st7@17
  double v17; // st6@17
  int v18; // eax@17
  int v19; // esi@20
  int v20; // eax@21
  double v21; // st7@21
  int v22; // eax@21
  float v23; // ecx@23
  int v24; // ST04_4@23
  int v25; // [sp+8h] [bp-64h]@18
  int v26; // [sp+Ch] [bp-60h]@18
  int v27; // [sp+10h] [bp-5Ch]@18
  int v28; // [sp+14h] [bp-58h]@18
  int v29; // [sp+18h] [bp-54h]@17
  int v30; // [sp+1Ch] [bp-50h]@17
  int v31; // [sp+2Ch] [bp-40h]@21
  int v32; // [sp+30h] [bp-3Ch]@21
  int v33; // [sp+34h] [bp-38h]@21
  double v34; // [sp+38h] [bp-34h]@21
  double v35; // [sp+40h] [bp-2Ch]@21
  double v36; // [sp+48h] [bp-24h]@21
  int v37; // [sp+50h] [bp-1Ch]@24
  int v38; // [sp+54h] [bp-18h]@1
  int v39; // [sp+58h] [bp-14h]@21
  int v40; // [sp+5Ch] [bp-10h]@21
  int v41; // [sp+60h] [bp-Ch]@21
  int v42; // [sp+64h] [bp-8h]@21
  int v43; // [sp+68h] [bp-4h]@8
  float *v44; // [sp+78h] [bp+Ch]@18

  v38 = (int)_this;
  if ( !a4 )
    return 0;
  if ( !(byte_69BD40 & 1) )
  {
    byte_69BD40 |= 1u;
    v7 = &unk_69B16C;
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
  if (~byte_69BD40 & 2)
  {
    byte_69BD40 |= 2;
    sub_489B60((int)&object_69B110);
    atexit(loc_45BE7B);
  }
  v43 = a5;
  if (LODWORD(a6) )
  {
    if ( a4 > 0 )
    {
      v9 = &unk_69B140;
      v10 = a5 - (_DWORD)&unk_69B140;
      a5 = a4;
      do
      {
        v11 = (char *)v9 + v10;
        v12 = v9;
        v9 = (char *)v9 + 48;
        v13 = a5-- == 1;
        memcpy(v12, v11, 0x30u);
      }
      while ( !v13 );
    }
    v14 = a3;
    if ( sub_437376(a3, &unk_69B140, &a4) == 1 )
    {
      if ( !a4 )
        return 0;
      v43 = (int)&unk_69B140;
    }
  }
  else
  {
    v14 = a3;
  }
  v16 = *(float *)(v14 + 12);
  v17 = *(float *)(v14 + 8);
  v18 = *(_DWORD *)(v14 + 4);
  v30 = (int)&object_69B110.flt_00001C;
  object_69B110.flt_000008 = v17;
  object_69B110.flt_000004 = *(float *)&v18;
  v29 = (int)&object_69B110;
  object_69B110.flt_00000C = v16;
  dword_69B138 = *(_DWORD *)(v14 + 16);
  if ( !sub_436932_GetFacetOrientation(*(_BYTE *)(v14 + 20), (int)&object_69B110.flt_000004, (int)&object_69B110, (int)&object_69B110.flt_00001C) )
  {
    v30 = 119;
    v29 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
    v44 = (float *)&v25;
    Game_sub_40E2C8(&v25, "Error: Failed to get the facet orientation", (int)((char *)&a3 + 3));
    sub_466D09(&a5, v25, v26, v27, v28, (const char *)v29, v30);
  }
  a5 = 0;
  if ( *(_DWORD *)(a2 + 172) > 0 )
  {
    v19 = a2 + 416;
    do
    {
      v21 = *(float *)(v19 + 320) * 255.0;
      v31 = *(_DWORD *)(v19 - 80);
      v32 = *(_DWORD *)v19;
      v33 = *(_DWORD *)(v19 + 240);
      v22 = *(_DWORD *)(v19 - 240);
      a6 = v21;
      v39 = v22;
      v40 = *(_DWORD *)(v19 + 80);
      v36 = a6 + 6.755399441055744e15;
      a6 = *(float *)(v19 + 400) * 255.0;
      v35 = a6 + 6.755399441055744e15;
      v42 = LODWORD(v35);
      a6 = *(float *)(v19 + 480) * 255.0;
      v34 = a6 + 6.755399441055744e15;
      v41 = LODWORD(v34);
      v20 = LODWORD(v34) | ((LODWORD(v35) | (LODWORD(v36) << 8)) << 8);
      if ( !(LODWORD(v34) | ((LODWORD(v35) | (LODWORD(v36) << 8)) << 8)) )
        v20 = 16777215;
      v30 = a7;
      LODWORD(v23) = a5;
      v29 = v43;
      LOBYTE(v23) = *(_BYTE *)(a2 + a5 + 976);
      *(float *)&v25 = (double)v40;
      *(float *)&v24 = (double)v39;
      if ( !sub_45BE86(v38, (int)&v31, v24, *(float *)&v20, v25, v23, (int)&object_69B110, a4, v43, a7) )
      {
        v30 = 138;
        v29 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
        LODWORD(a6) = (int)&v25;
        Game_sub_40E2C8(&v25, "Error: Failed to build light polygon", (int)((char *)&a3 + 3));
        sub_466D09(&v37, v25, v26, v27, v28, (const char *)v29, v30);
        v37 = 5080748;
      }
      ++a5;
      v19 += 4;
    }
    while ( a5 < *(_DWORD *)(a2 + 172) );
  }
  return 1;
}

//----- (0045BE86) --------------------------------------------------------
char __thiscall sub_45BE86(int _this, int a2, int a3, float a4, signed int a5, float a6, int a7, signed int a8, int a9, char a10)
{
  int v10; // esi@1
  int v11; // edi@3
  int v12; // eax@5
  int v13; // edx@5
  signed int v14; // ecx@5
  int v15; // ebx@5
  double v16; // st7@5
  double v17; // st7@5
  double v18; // st7@5
  double v19; // st7@5
  double v20; // st7@5
  double v21; // st6@5
  double v22; // st5@5
  double v23; // st5@5
  double v24; // st7@6
  int v25; // eax@8
  unsigned int v26; // ecx@8
  int v27; // ebx@8
  int v28; // ebx@8
  double v29; // st7@8
  signed int v30; // eax@8
  double v31; // st6@8
  double v32; // st6@8
  double v33; // st5@8
  int v34; // edx@9
  int v35; // edx@11
  unsigned int v36; // edx@13
  unsigned int v37; // ecx@14
  double v38; // st7@14
  double v39; // st7@17
  double v40; // st7@17
  char result; // al@23
  double v42; // st7@23
  int v43; // ebx@24
  int v44; // eax@25
  int v45; // edi@28
  void *v46; // ecx@35
  unsigned __int8 v47; // sf@40
  unsigned __int8 v48; // of@40
  int v49; // eax@40
  int v50; // esi@40
  const char *v51; // [sp-Ch] [bp-58h]@35
  int v52; // [sp-8h] [bp-54h]@35
  char v53; // [sp-4h] [bp-50h]@20
  int v54; // [sp+0h] [bp-4Ch]@20
  int v55; // [sp+4h] [bp-48h]@20
  int v56; // [sp+8h] [bp-44h]@20
  const char *v57[5]; // [sp+Ch] [bp-40h]@17
  float v58; // [sp+20h] [bp-2Ch]@8
  float v59; // [sp+24h] [bp-28h]@8
  float v60; // [sp+28h] [bp-24h]@8
  float v61; // [sp+2Ch] [bp-20h]@8
  float v62; // [sp+30h] [bp-1Ch]@8
  float v63; // [sp+34h] [bp-18h]@8
  double v64; // [sp+38h] [bp-14h]@8
  int v65; // [sp+40h] [bp-Ch]@5
  float v66; // [sp+44h] [bp-8h]@5
  char v67; // [sp+4Bh] [bp-1h]@2
  int v68; // [sp+54h] [bp+8h]@8
  float v69; // [sp+54h] [bp+8h]@8
  int v70; // [sp+54h] [bp+8h]@8

  v10 = _this;
  if ( *(float *)&a3 == 0.0 )
    return 1;
  v67 = LOBYTE(a6) & 1;
  if (LOBYTE(a6) & 1 )
    v11 = 3100 * *(_DWORD *)(_this + 1587204) + _this + 4;
  else
    v11 = 3100 * *(_DWORD *)(_this + 3968008) + _this + 1587208;
  v16 = *(float *)&a3 - *(float *)&a5;
  *(float *)(_this + 3968036) = v16;
  v17 = sqrt((*(float *)&a3 + *(float *)&a3 - v16) * v16);
  *(float *)(v10 + 3968040) = v17;
  v15 = a7;
  v66 = 1.0 / *(float *)&a3;
  *(float *)(v10 + 3968044) = 1.0 - (*(float *)&a3 - v17) * v66;
  *(_WORD *)(v11 + 3080) = (signed __int64)((double)*(signed int *)a2 - *(float *)&a5 * *(float *)(v15 + 4));
  *(_WORD *)(v11 + 3082) = (signed __int64)((double)*(signed int *)(a2 + 4) - *(float *)&a5 * *(float *)(v15 + 8));
  v18 = *(float *)&a3;
  *(_WORD *)(v11 + 3084) = (signed __int64)((double)*(signed int *)(a2 + 8) - *(float *)&a5 * *(float *)(v15 + 12));
  v13 = v11 + 8;
  v19 = v18 * *(float *)(v10 + 3968044);
  v65 = v11 + 8;
  *(float *)(v10 + 3968048) = v19;
  *(float *)(v10 + 3968012) = v19 * *(float *)(v15 + 16);
  *(float *)(v10 + 3968016) = v19 * *(float *)(v15 + 20);
  *(float *)(v10 + 3968020) = v19 * *(float *)(v15 + 24);
  *(float *)(v10 + 3968024) = v19 * *(float *)(v15 + 28);
  *(float *)(v10 + 3968028) = v19 * *(float *)(v15 + 32);
  *(float *)(v10 + 3968032) = v19 * *(float *)(v15 + 36);
  a5 = *(_WORD *)(v11 + 3080);
  v20 = (double)a5;
  *(float *)(v11 + 8) = v20 - *(float *)(v10 + 3968024) + *(float *)(v10 + 3968012);
  a5 = *(_WORD *)(v11 + 3082);
  v12 = v11 + 12;
  v21 = (double)a5;
  v22 = v21 - *(float *)(v10 + 3968028);
  a5 = *(_WORD *)(v11 + 3084);
  v14 = 4;
  *(float *)(v11 + 12) = v22 + *(float *)(v10 + 3968016);
  v23 = (double)a5;
  *(float *)&a5 = v23;
  *(float *)(v11 + 16) = v23 - *(float *)(v10 + 3968032) + *(float *)(v10 + 3968020);
  *(float *)(v11 + 44) = 0.0;
  *(float *)(v11 + 48) = 0.0;
  *(float *)(v11 + 56) = v20 - *(float *)(v10 + 3968024) - *(float *)(v10 + 3968012);
  *(float *)(v11 + 60) = v21 - *(float *)(v10 + 3968028) - *(float *)(v10 + 3968016);
  *(float *)(v11 + 64) = v23 - *(float *)(v10 + 3968032) - *(float *)(v10 + 3968020);
  *(float *)(v11 + 92) = 0.0;
  *(float *)(v11 + 96) = 1.0;
  *(float *)(v11 + 104) = v20 + *(float *)(v10 + 3968024) - *(float *)(v10 + 3968012);
  *(float *)(v11 + 108) = v21 + *(float *)(v10 + 3968028) - *(float *)(v10 + 3968016);
  *(float *)(v11 + 112) = v23 + *(float *)(v10 + 3968032) - *(float *)(v10 + 3968020);
  *(float *)(v11 + 140) = 1.0;
  *(float *)(v11 + 144) = 1.0;
  *(float *)(v11 + 152) = v20 + *(float *)(v10 + 3968024) + *(float *)(v10 + 3968012);
  *(float *)(v11 + 156) = v21 + *(float *)(v10 + 3968028) + *(float *)(v10 + 3968016);
  *(float *)(v11 + 160) = *(float *)&a5 + *(float *)(v10 + 3968032) + *(float *)(v10 + 3968020);
  *(float *)(v11 + 188) = 1.0;
  *(float *)(v11 + 192) = 0.0;
  do
  {
    v24 = *(float *)(v15 + 8) * *(float *)v12
        + *(float *)(v12 + 4) * *(float *)(v15 + 12)
        + *(float *)(v15 + 4) * *(float *)(v12 - 4)
        + *(float *)(v15 + 40);
    *(float *)(v12 - 4) = *(float *)(v12 - 4) - v24 * *(float *)(v15 + 4);
    *(float *)v12 = *(float *)v12 - v24 * *(float *)(v15 + 8);
    v12 += 48;
    --v14;
    *(float *)(v12 - 44) = *(float *)(v12 - 44) - v24 * *(float *)(v15 + 12);
  }
  while ( v14 );
  *(_DWORD *)(v11 + 3088) = LODWORD(a4);
  *(_DWORD *)(v11 + 4) = 4;
  if ( *(_BYTE *)(LODWORD(pGame) + 3620) & 4 )
  {
    a5 = *(_WORD *)(v11 + 3084);
    v28 = a2;
    v29 = (double)a5;
    a5 = *(_WORD *)(v11 + 3082);
    v30 = *(_WORD *)(v11 + 3080);
    *(float *)&a5 = (double)a5;
    LODWORD(a4) = v30;
    v31 = (double)v30;
    LODWORD(v59) = a5;
    v58 = v31;
    v60 = v29;
    a4 = (double)*(signed int *)(a2 + 8);
    v69 = (double)*(signed int *)(a2 + 4);
    v32 = (double)*(signed int *)v28 - v31;
    v33 = v69 - *(float *)&a5;
    *(float *)&a5 = a4 - v29;
    v61 = v32;
    LODWORD(v63) = a5;
    v62 = v33;
    sub_4369DB((int)&v61);
    v64 = v60 + 6.755399441055744e15;
    a5 = LODWORD(v64);
    v64 = v59 + 6.755399441055744e15;
    v70 = LODWORD(v64);
    v64 = v58 + 6.755399441055744e15;
    LODWORD(a4) = LODWORD(v64);
    HIDWORD(v64) = abs(*(_DWORD *)(v28 + 8) - a5);
    v68 = abs(*(_DWORD *)(v28 + 4) - v70);
    v25 = abs(*(_DWORD *)v28 - LODWORD(a4));
    v27 = v68;
    v26 = HIDWORD(v64);
    if ( v25 < v68 )
    {
      v34 = v25;
      v25 = v68;
      v27 = v34;
    }
    if ( v25 < HIDWORD(v64) )
    {
      v35 = v25;
      v25 = HIDWORD(v64);
      v26 = v35;
    }
    if ( v27 < (signed int)v26 )
    {
      v36 = v26;
      v26 = v27;
      v27 = v36;
    }
    v37 = v26 >> 2;
    a5 = ((unsigned int)(11 * v27) >> 5) + v37 + v25;
    v38 = (double)a5;
    if ( v38 > *(float *)&a3 )
      return 1;
    *(float *)&a3 = v66 * v38;
    if (LOBYTE(a6) & 4 )
    {
      v57[1] = (const char *)v37;
      LODWORD(a6) = *(_DWORD *)&byte_4D8410[700];
      v57[0] = (const char *)v37;
      v40 = fabs(v61 * *(float *)(a7 + 4) + v63 * *(float *)(a7 + 12) + v62 * *(float *)(a7 + 8));
      v39 = v40 * 1.0 * a6;
    }
    else
    {
      if (LOBYTE(a6) & 8 )
      {
        v39 = 1.0 * 1.0;
      }
      else
      {
        v57[1] = (const char *)277;
        v57[0] = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
        LODWORD(a6) = (int)&v53;
        Game_sub_40E2C8(&v53, "Invalid light type!", (int)((char *)&a6 + 3));
        sub_466D09(&a5, *(int *)&v53, v54, v55, v56, v57[0], (int)v57[1]);
        v39 = a6;
      }
    }
    v15 = a7;
    v13 = v65;
    *(float *)(v11 + 3092) = v39 - *(float *)&a3 * v39;
  }
  else
  {
    *(_DWORD *)(v11 + 3092) = *(_DWORD *)(v10 + 3968044);
  }
  v42 = *(float *)(v15 + 12);
  v57[1] = (const char *)(v11 + 4);
  v57[0] = (const char *)v13;
  *(float *)&v56 = v42;
  *(float *)&v55 = *(float *)(v15 + 8);
  *(float *)&v54 = *(float *)(v15 + 4);
  result = sub_4980B9(a9, a8, *(float *)&v54, *(float *)&v55, *(float *)&v56, v13, v11 + 4);
  if ( !result )
    return result;
  v43 = v11 + 4;
  if ( !*(_DWORD *)(v11 + 4) )
    return 1;
  v44 = sub_45C6D6(a8, a9, v11);
  if ( v44 != a8 )
  {
    if ( v44 > 0 )
      sub_45C4B9(a8, a9, v11);
  }
  v57[1] = *(const char **)v43;
  v45 = v65;
  sub_436523((RenderVertex *)v65, (int)v57[1]);
  *(_QWORD *)v57 = *(_DWORD *)v43;
  class08_sub_436BB7(pGame->class08_obj, (RenderVertex *)v45, (int)v57[0], SLOBYTE(v57[1]));
  if ( !(a10 & 1) )
    goto LABEL_39;
  if ( uCurrentlyLoadedLevelType == 2 )
  {
    if ( a10 & 2 )
    {
      v57[1] = (const char *)&a3;
      v57[0] = (const char *)(v10 + 3968052);
      v56 = *(_DWORD *)v43;
      sub_436CDC(v45, v56, v10 + 3968052, (int)&a3);
LABEL_34:
      sub_437143(a3, v45, v10 + 3968052, v43);
      goto LABEL_38;
    }
    if ( a10 & 4 )
    {
      v57[1] = (const char *)&a3;
      v57[0] = (const char *)(v10 + 3968052);
      v56 = *(_DWORD *)v43;
      sub_436F09(v45, v56, v10 + 3968052, (int)&a3);
      goto LABEL_34;
    }
    v57[1] = (const char *)330;
    v57[0] = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
    v46 = &v53;
    LODWORD(a6) = (int)&v53;
    v52 = (int)((char *)&a6 + 3);
    v51 = "Undefined clip flag specified";
  }
  else
  {
    v57[1] = (const char *)335;
    v57[0] = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
    v46 = &v53;
    LODWORD(a6) = (int)&v53;
    v52 = (int)((char *)&a6 + 3);
    v51 = "Lightpoly builder native indoor clipping not implemented";
  }
  Game_sub_40E2C8(v46, v51, v52);
  sub_466D09(&a5, *(int *)&v53, v54, v55, v56, v57[0], (int)v57[1]);
LABEL_38:
  if ( a3 )
  {
LABEL_39:
    if ( v67 )
    {
      v50 = v10 + 1587204;
      v49 = *(_DWORD *)v50;
      compile_error();//v48 = __SETO__(*(_DWORD *)v50, 511);
      v47 = *(_DWORD *)v50 - 511 < 0;
    }
    else
    {
      v50 = v10 + 3968008;
      v49 = *(_DWORD *)v50;
      compile_error();//v48 = __SETO__(*(_DWORD *)v50, 767);
      v47 = *(_DWORD *)v50 - 767 < 0;
    }
    if ( v47 ^ v48 )
      *(_DWORD *)v50 = v49 + 1;
  }
  return 1;
}

//----- (0045C4B9) --------------------------------------------------------
int __stdcall sub_45C4B9(signed int a1, int a2, int a3)
{
  int v3; // eax@1
  signed int v4; // ecx@1
  int v5; // edi@1
  int v6; // ebx@2
  int v7; // edx@3
  int v8; // esi@3
  int v9; // eax@6
  int v10; // edi@7
  int v11; // ecx@8
  signed int v12; // edx@17
  char v13; // bl@17
  double v14; // st6@18
  double v15; // st6@21
  double v16; // st6@24
  signed int v17; // edx@33
  int v19; // [sp+4h] [bp-1Ch]@3
  int v20; // [sp+8h] [bp-18h]@8
  float v21; // [sp+Ch] [bp-14h]@23
  float v22; // [sp+10h] [bp-10h]@20
  int v23; // [sp+14h] [bp-Ch]@1
  int v24; // [sp+18h] [bp-8h]@2
  char v25; // [sp+1Eh] [bp-2h]@17
  char v26; // [sp+1Fh] [bp-1h]@17

  v5 = a3;
  v3 = 0;
  v4 = *(_DWORD *)(a3 + 4);
  v23 = 0;
  if ( v4 > 0 )
  {
    v6 = a3 + 8;
    v24 = a3 + 8;
    do
    {
      v19 = v3 + 1;
      v7 = (v3 + 1) % v4;
      v8 = 48 * v7 + v5 + 8;
      if ( *(float *)v6 != *(float *)v8
        || *(float *)(v6 + 4) != *(float *)(48 * v7 + v5 + 12)
        || *(float *)(v6 + 8) != *(float *)(48 * v7 + v5 + 16) )
      {
        v9 = 0;
        if ( a1 > 0 )
        {
          v10 = a2 + 8;
          do
          {
            v20 = v9 + 1;
            v11 = a2 + 48 * (v9 + 1) % a1;
            if ( *(float *)(v10 - 8) != *(float *)v11
              || *(float *)(v10 - 4) != *(float *)(v11 + 4)
              || *(float *)v10 != *(float *)(v11 + 8) )
            {
              if ( *(float *)v6 == *(float *)(v10 - 8) )
              {
                if ( *(float *)(v6 + 4) == *(float *)(v10 - 4) )
                {
                  if ( *(float *)(v6 + 8) == *(float *)v10 )
                  {
                    if ( *(float *)v8 != *(float *)v11
                      || *(float *)(v8 + 4) != *(float *)(v11 + 4)
                      || *(float *)(v8 + 8) != *(float *)(v11 + 8) )
                    {
                      v13 = 0;
                      v12 = 0;
                      v26 = 0;
                      v25 = 0;
                      if ( *(float *)v8 <= (double)*(float *)v11 )
                        v14 = *(float *)v11 - *(float *)v8;
                      else
                        v14 = *(float *)v8 - *(float *)v11;
                      v22 = v14;
                      if ( *(float *)(v8 + 4) <= (double)*(float *)(v11 + 4) )
                        v15 = *(float *)(v11 + 4) - *(float *)(v8 + 4);
                      else
                        v15 = *(float *)(v8 + 4) - *(float *)(v11 + 4);
                      v21 = v15;
                      if ( *(float *)(v8 + 8) <= (double)*(float *)(v11 + 8) )
                        v16 = *(float *)(v11 + 8) - *(float *)(v8 + 8);
                      else
                        v16 = *(float *)(v8 + 8) - *(float *)(v11 + 8);
                      if ( v22 < 1.0 )
                      {
                        v13 = 1;
                        v12 = 1;
                      }
                      if ( v21 < 1.0 )
                      {
                        v26 = 1;
                        ++v12;
                      }
                      if ( v16 < 1.0 )
                      {
                        v25 = 1;
                        ++v12;
                      }
                      if ( v12 > 1 )
                      {
                        v17 = 0;
                        if ( v13 )
                        {
                          if ( *(float *)v8 != *(float *)v11 )
                          {
                            v17 = 1;
                            *(_DWORD *)v8 = *(_DWORD *)v11;
                          }
                        }
                        if ( v26 )
                        {
                          if ( *(float *)(v8 + 4) != *(float *)(v11 + 4) )
                          {
                            ++v17;
                            *(_DWORD *)(v8 + 4) = *(_DWORD *)(v11 + 4);
                          }
                        }
                        if ( v25 )
                        {
                          if ( *(float *)(v8 + 8) != *(float *)(v11 + 8) )
                          {
                            ++v17;
                            *(_DWORD *)(v8 + 8) = *(_DWORD *)(v11 + 8);
                          }
                        }
                        if ( v17 > 0 )
                          ++v23;
                      }
                      v6 = v24;
                    }
                  }
                }
              }
            }
            ++v9;
            v10 += 48;
          }
          while ( v20 < a1 );
          v5 = a3;
        }
      }
      v3 = v19;
      v4 = *(_DWORD *)(v5 + 4);
      v6 += 48;
      v24 = v6;
    }
    while ( v19 < v4 );
  }
  return v23;
}

//----- (0045C6D6) --------------------------------------------------------
int __stdcall sub_45C6D6(signed int a1, int a2, int a3)
{
  int v3; // ebx@1
  int v4; // edi@1
  signed int v5; // esi@1
  int v6; // ecx@2
  int v7; // edx@4
  double v8; // st7@6
  double v9; // st6@10
  double v10; // st5@14
  double v11; // st7@17
  int v12; // eax@21
  int v14; // [sp+Ch] [bp-8h]@1
  float v15; // [sp+10h] [bp-4h]@1
  signed int v16; // [sp+24h] [bp+10h]@3

  v4 = a3;
  v3 = 0;
  v5 = -1;
  LODWORD(v15) = 2139095039;
  v14 = 0;
  if ( *(_DWORD *)(a3 + 4) > 0 )
  {
    v6 = a3 + 8;
    do
    {
      v16 = 0;
      if ( a1 > 0 )
      {
        v7 = a2 + 8;
        do
        {
          if ( *(float *)v6 <= (double)*(float *)(v7 - 8) )
            v8 = *(float *)(v7 - 8) - *(float *)v6;
          else
            v8 = *(float *)v6 - *(float *)(v7 - 8);
          if ( v8 < 2.0 )
          {
            if ( *(float *)(v6 + 4) <= (double)*(float *)(v7 - 4) )
              v9 = *(float *)(v7 - 4) - *(float *)(v6 + 4);
            else
              v9 = *(float *)(v6 + 4) - *(float *)(v7 - 4);
            if ( v9 < 2.0 )
            {
              if ( *(float *)(v6 + 8) <= (double)*(float *)v7 )
                v10 = *(float *)v7 - *(float *)(v6 + 8);
              else
                v10 = *(float *)(v6 + 8) - *(float *)v7;
              if ( v10 < 2.0 )
              {
                v11 = v8 + v10 + v9;
                if ( v11 < v15 )
                {
                  v15 = v11;
                  v5 = v16;
                }
              }
            }
          }
          ++v16;
          v7 += 48;
        }
        while ( v16 < a1 );
        if ( v5 != -1 )
        {
          v12 = a2 + 48 * v5;
          ++v14;
          *(_DWORD *)v6 = *(_DWORD *)v12;
          *(_DWORD *)(v6 + 4) = *(_DWORD *)(v12 + 4);
          *(_DWORD *)(v6 + 8) = *(_DWORD *)(v12 + 8);
        }
      }
      v5 = -1;
      ++v3;
      v6 += 48;
      LODWORD(v15) = 2139095039;
    }
    while ( v3 < *(_DWORD *)(v4 + 4) );
  }
  return v14;
}

//----- (0045C7F6) --------------------------------------------------------
char __stdcall sub_45C7F6(signed int a1)
{
  int v1; // ebx@1
  int v2; // edi@1
  int v3; // esi@1
  int v4; // ecx@5
  int v5; // eax@7
  unsigned __int8 v6; // sf@9
  unsigned __int8 v7; // of@9
  int v8; // edi@10
  int v10; // [sp+10h] [bp-8h]@2
  int v11; // [sp+10h] [bp-8h]@5
  int v12; // [sp+10h] [bp-8h]@11
  int v13; // [sp+14h] [bp-4h]@1
  int v14; // [sp+14h] [bp-4h]@5

  v3 = dword_6BE644 + 96 * a1;
  v1 = dword_51B6DC;
  v13 = 0;
  v2 = 116 * *(_WORD *)(v3 + 76);
  a1 = 0;
  dword_F8AD54 = (dword_F8B120 + *(_WORD *)(v2 + dword_6BE654 + 98)) << 16;
  if ( dword_51B6DC > 0 )
  {
    v10 = (int)array_519ABC;
    do
    {
      if ( a1 >= 20 )
        break;
      sub_45C911(v10, v3, (int)&a1, 1, 0);
      ++v13;
      v10 += 18;
    }
    while ( v13 < v1 );
  }
  v4 = 0;
  v14 = 0;
  v11 = *(_WORD *)(v2 + dword_6BE654 + 84);
  if ( (signed int)*(_WORD *)(v2 + dword_6BE654 + 84) > 0 )
  {
    do
    {
      if ( a1 >= 20 )
        break;
      v5 = dword_6BE65C + 16 * *(_WORD *)(*(_DWORD *)(v2 + dword_6BE654 + 88) + 2 * v4);
      if ( !(*(_BYTE *)(v5 + 12) & 8) )
        sub_45C911(v5, v3, (int)&a1, 0, (int)&byte_4E94D0);
      v4 = v14 + 1;
      compile_error();//v7 = __SETO__(v14 + 1, v11);
      v6 = v14++ + 1 - v11 < 0;
    }
    while ( v6 ^ v7 );
  }
  v8 = 0;
  if ( pStationaryLightsStack->uNumStationaryLightsActive > 0 )
  {
    v12 = (int)pStationaryLightsStack->pLights;
    do
    {
      if ( a1 >= 20 )
        break;
      sub_45C911(v12, v3, (int)&a1, 0, (int)&byte_4E94D0);
      v12 += 12;
      ++v8;
    }
    while ( v8 < pStationaryLightsStack->uNumStationaryLightsActive );
  }
  dword_F8ADD4 = a1;
  return 1;
}

//----- (0045C911) --------------------------------------------------------
char __stdcall sub_45C911(int a1, int a2, int a3, char X, int a5)
{
  signed int v5; // ecx@1
  int v6; // edi@1
  int v7; // eax@2
  int v8; // edx@2
  int v9; // edx@4
  int v10; // esi@4
  int v11; // edx@6
  double v12; // st7@8
  char result; // al@10
  signed int v14; // [sp+Ch] [bp-8h]@1
  signed int v15; // [sp+10h] [bp-4h]@2
  signed int v16; // [sp+1Ch] [bp+8h]@6
  float v17; // [sp+1Ch] [bp+8h]@8
  signed int v18; // [sp+20h] [bp+Ch]@4

  v6 = a1;
  v5 = *(_WORD *)(a1 + 6);
  v14 = *(_WORD *)(a1 + 6);
  if ( v5 > 0
    && (v7 = a2, v8 = *(_WORD *)a1, v15 = v8, v8 > *(_WORD *)(a2 + 80) - v5)
    && v8 < v5 + *(_WORD *)(a2 + 82)
    && (v9 = *(_WORD *)(a1 + 2), v10 = *(_WORD *)(a2 + 84) - v5, v18 = v9, v9 > v10)
    && v9 < v5 + *(_WORD *)(v7 + 86)
    && (v11 = *(_WORD *)(a1 + 4), v16 = v11, v11 > *(_WORD *)(v7 + 88) - v5)
    && v11 < v5 + *(_WORD *)(v7 + 90)
    && ((v12 = (double)v16 * *(float *)(v7 + 8)
             + (double)v18 * *(float *)(v7 + 4)
             + (double)v15 * *(float *)v7
             + *(float *)(v7 + 12),
         v17 = v12,
         X)
     || v12 >= 0.0)
    && v12 <= (double)v14 )
  {
    dword_F8ADD8[*(_DWORD *)a3] = v5;
    dword_F8AE28[*(_DWORD *)a3] = 65536 / v5;
    dword_F8AE78[*(_DWORD *)a3] = *(_WORD *)v6;
    dword_F8AEC8[*(_DWORD *)a3] = *(_WORD *)(v6 + 2);
    dword_F8AFB8[*(_DWORD *)a3] = *(_WORD *)(v6 + 4);
    flt_F8B008[*(_DWORD *)a3] = (double)*(_BYTE *)(v6 + 8) * 0.003921568859368563;
    flt_F8B058[*(_DWORD *)a3] = (double)*(_BYTE *)(v6 + 9) * 0.003921568859368563;
    flt_F8B0A8[*(_DWORD *)a3] = (double)*(_BYTE *)(v6 + 10) * 0.003921568859368563;
    compile_error();//dword_F8AF18[*(_DWORD *)a3] = abs(COERCE_UNSIGNED_INT64(v17 + 6.755399441055744e15));
    byte_F8B0F8[*(_DWORD *)a3++] = *(_BYTE *)(v6 + 11);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}


//----- (0045CBD4) --------------------------------------------------------
int __stdcall sub_45CBD4(int a1, int a2, int a3, int a4)
{
  int result; // eax@1
  int v5; // edx@1
  int v6; // ecx@2
  int v7; // esi@2

  result = a4;
  v5 = 0;
  for ( *(_DWORD *)a4 = 0; v5 < a2; ++v5 )
  {
    v6 = *(_DWORD *)a4;
    v7 = 0;
    if ( *(_DWORD *)a4 <= 0 )
    {
LABEL_5:
      *(_DWORD *)(a3 + 4 * v6) = v5;
      ++*(_DWORD *)a4;
    }
    else
    {
      while ( *(_DWORD *)(a3 + 4 * v7) != v5 )
      {
        ++v7;
        if ( v7 >= v6 )
          goto LABEL_5;
      }
    }
  }
  return result;
}

//----- (0045CC0C) --------------------------------------------------------
double __stdcall sub_45CC0C(float a1, float a2, float a3, float a4, float a5, int a6, float a7, float a8)
{
  int v8; // eax@1
  unsigned int v9; // ecx@1
  int v10; // ebx@1
  float v11; // esi@1
  int v12; // edx@2
  int v13; // edx@4
  int v14; // edx@6
  double v15; // st7@7
  double result; // st7@8
  const char *v17; // ecx@9
  double v18; // st7@9
  int v19; // esi@9
  double v20; // st7@10
  double v21; // st7@10
  char v22; // [sp-10h] [bp-40h]@13
  int v23; // [sp-Ch] [bp-3Ch]@13
  int v24; // [sp-8h] [bp-38h]@13
  int v25; // [sp-4h] [bp-34h]@13
  const char *v26[6]; // [sp+0h] [bp-30h]@10
  double v27; // [sp+18h] [bp-18h]@1
  double v28; // [sp+20h] [bp-10h]@1
  int v29; // [sp+28h] [bp-8h]@1
  int v30; // [sp+2Ch] [bp-4h]@1

  v11 = a7;
  LODWORD(a7) = *(_DWORD *)(LODWORD(a7) + 8);
  v28 = a7 + 6.755399441055744e15;
  v30 = LODWORD(v28);
  LODWORD(a7) = *(_DWORD *)(LODWORD(v11) + 4);
  v28 = a7 + 6.755399441055744e15;
  v29 = LODWORD(v28);
  compile_error();//LODWORD(a7) = *LODWORD(v11);
  v27 = a7 + 6.755399441055744e15;
  HIDWORD(v28) = LODWORD(v27);
  v30 = abs(LODWORD(a3) - v30);
  v29 = abs(LODWORD(a2) - LODWORD(v28));
  v8 = abs(LODWORD(a1) - LODWORD(v27));
  v10 = v29;
  v9 = v30;
  if ( v8 < v29 )
  {
    v12 = v8;
    v8 = v29;
    v10 = v12;
  }
  if ( v8 < v30 )
  {
    v13 = v8;
    v8 = v30;
    v9 = v13;
  }
  if ( v10 < (signed int)v9 )
  {
    v14 = v9;
    v9 = v10;
    v10 = v14;
  }
  v15 = (double)(signed int)(((unsigned int)(11 * v10) >> 5) + (v9 >> 2) + v8);
  if ( v15 <= a5 )
  {
    a7 = v15 / a5;
    v18 = (double)SLODWORD(a1);
    *(float *)&v27 = (double)SLODWORD(a2);
    compile_error();//LODWORD(a1) = *LODWORD(v11);
    v19 = LODWORD(v11) + 4;
    *((float *)&v27 + 1) = (double)SLODWORD(a3);
    LODWORD(a2) = *(_DWORD *)v19;
    LODWORD(a3) = *(_DWORD *)(v19 + 4);
    a5 = *((float *)&v27 + 1) - a3;
    a3 = a5;
    a1 = v18 - a1;
    a2 = (float)v27 - a2;
    sub_4369DB((int)&a1);
    if (LOBYTE(a8) & 4 )
    {
      v26[1] = v17;
      LODWORD(a8) = *(_DWORD *)&byte_4D8410[712];
      v26[0] = v17;
      v21 = fabs(a3 * *(float *)(a6 + 8) + a2 * *(float *)(a6 + 4) + a1 * *(float *)a6);
      v20 = v21 * a8 * a4;
    }
    else
    {
      if (LOBYTE(a8) & 8 )
      {
        v20 = 1.299999952316284 * a4;
      }
      else
      {
        v26[1] = (const char *)783;
        v26[0] = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
        LODWORD(a8) = (int)&v22;
        Game_sub_40E2C8(&v22, "Invalid light type detected!", (int)((char *)&a8 + 3));
        sub_466D09(&a5, *(int *)&v22, v23, v24, v25, v26[0], (int)v26[1]);
        v20 = a8;
      }
    }
    result = v20 - a7 * v20;
  }
  else
  {
    result = 0.0;
  }
  return result;
}

//----- (0045D036) --------------------------------------------------------
bool __stdcall sub_45D036(struct Vec3 *pNormal, int a2, struct RenderVertex *a3, int a4, signed int X)
{
  float v6; // ebx@2
  int v10; // [sp+Ch] [bp-4h]@1
 int i;

  v10 = 0;
  dword_F8AD54 = pClass51_global->dword_000CBC;
  for (i = 0; i < dword_51B6DC; ++i)
  {
      if ( v10 >= 20 )
        break;
      sub_45D0D5((struct6 *)&array_519ABC[i], pNormal, a2, a3, a4, X, (int)&v10);
  }
  /*
  for (i = 0; i < pStationaryLightsStack->uNumStationaryLightsActive; ++i)
  {
      if ( v10 >= 20 )
        break;
      sub_45D0D5((struct6 *)&pStationaryLightsStack->pLights[i], pNormal, a2, a3, a4, X, (int)&v10);
  }	  crushes */ 

  dword_F8ADD4 = v10;
  return true;
}

//----- (0045D0D5) --------------------------------------------------------
char __stdcall sub_45D0D5(struct struct6 *a1, struct Vec3 *pNormal, int a3, struct RenderVertex *a4, float a5, signed int X, int a7)
{
  float v7; // edi@1
  int v8; // eax@1
  int v9; // ebx@2
  int v10; // esi@2
  float v11; // eax@3
  int v12; // eax@4
  double v13; // st7@11
  double v14; // st7@11
  signed int v15; // eax@11
  double v16; // st7@13
  double v17; // st7@15
  signed int v18; // ecx@17
  int v19; // esi@17
  double v20; // st7@17
  double v21; // st6@17
  char v22; // dl@18
  int v23; // ecx@18
  int v24; // ebx@18
  int v25; // esi@18
  int v26; // eax@22
  char v28; // [sp-18h] [bp-38h]@10
  int v29; // [sp-14h] [bp-34h]@10
  int v30; // [sp-10h] [bp-30h]@10
  int v31; // [sp-Ch] [bp-2Ch]@10
  const char *v32; // [sp-8h] [bp-28h]@10
  int v33; // [sp-4h] [bp-24h]@10
  double v34; // [sp+Ch] [bp-14h]@17
  float v35; // [sp+10h] [bp-10h]@11
  float v36; // [sp+14h] [bp-Ch]@11
  int v37; // [sp+18h] [bp-8h]@1
  float v38; // [sp+1Ch] [bp-4h]@5

  v7 = *(float *)&a1;
  v8 = *(_WORD *)(LODWORD(a1) + 6);
  v37 = *(_WORD *)(LODWORD(a1) + 6);
  if ( v8 <= 0 )
    return 0;
  v10 = LODWORD(a5);
  v9 = LODWORD(a4);
  if (LODWORD(a5) == 4 )
  {
    compile_error();//LODWORD(a1) = *LODWORD(a4);
    LODWORD(v11) = *(_DWORD *)(LODWORD(a4) + 144);
  }
  else
  {
    if (LODWORD(a5) != 3 )
    {
      v33 = 981;
      v32 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
      X = (signed int)&v28;
      Game_sub_40E2C8(&v28, "Uknown strip type detected!", (int)((char *)&X + 3));
      sub_466D09(&a1, *(int *)&v28, v29, v30, v31, v32, v33);
      goto LABEL_11;
    }
    if ( (_BYTE)X )
    {
      compile_error();//LODWORD(a1) = *LODWORD(a4);
      LODWORD(a5) = *(_DWORD *)(LODWORD(a4) + 96);
      LODWORD(a4) = *(_DWORD *)(LODWORD(a4) + 52);
      v12 = *(_DWORD *)(v9 + 100);
      goto LABEL_5;
    }
    LODWORD(a1) = *(_DWORD *)(LODWORD(a4) + 48);
    LODWORD(v11) = *(_DWORD *)(LODWORD(a4) + 96);
  }
  a5 = v11;
  LODWORD(a4) = *(_DWORD *)(LODWORD(a4) + 52);
  v12 = *(_DWORD *)(v9 + 4);
LABEL_5:
  LODWORD(v38) = v12;
LABEL_11:
  v36 = sub_436A6D(v9, v10);
  v14 = sub_436A40(v9, v10);
  compile_error();//v15 = *LODWORD(v7);
  v35 = v14;
  v13 = (double)v15;
  *(float *)&X = (double)v37;

  compile_error();
  /*
  if ( v13 <= a1 - *(float *)&X
    || v13 >= *(float *)&X + a5
    || (LODWORD(a1) = *(_WORD *)(LODWORD(v7) + 2), v16 = (double)SLODWORD(a1), v16 <= a4 - *(float *)&X)
    || v16 >= *(float *)&X + v38
    || (LODWORD(a1) = *(_WORD *)(LODWORD(v7) + 4), v17 = (double)SLODWORD(a1), v17 <= v36 - *(float *)&X)
    || v17 >= *(float *)&X + v35
    || (v19 = a2,
        sub_49B02E(v9, a2, a3),
        X = *(_WORD *)(LODWORD(v7) + 2),
        v20 = (double)X * *(float *)(v19 + 4),
        X = *(_WORD *)(LODWORD(v7) + 4),
        v21 = (double)X * *(float *)(v19 + 8),
        X = *LODWORD(v7),
        *(float *)&a3 = v20 + v21 + (double)X * *(float *)v19 + *(float *)a3,
        v34 = *(float *)&a3 + 6.755399441055744e15,
        X = LODWORD(v34),
        v18 = v37,
        LODWORD(v34) > v37) )*/
  if (0)
    return 0;
  v25 = a7;
  v33 = X;
  dword_F8ADD8[*(_DWORD *)a7] = v37;
  dword_F8AE28[*(_DWORD *)v25] = 65536 / v18;
  compile_error();//dword_F8AE78[*(_DWORD *)v25] = *LODWORD(v7);
  dword_F8AEC8[*(_DWORD *)v25] = *(_WORD *)(LODWORD(v7) + 2);
  dword_F8AFB8[*(_DWORD *)v25] = *(_WORD *)(LODWORD(v7) + 4);
  a3 = *(_BYTE *)(LODWORD(v7) + 8);
  flt_F8B008[*(_DWORD *)v25] = (double)a3 * 0.003921568859368563;
  a3 = *(_BYTE *)(LODWORD(v7) + 9);
  flt_F8B058[*(_DWORD *)v25] = (double)a3 * 0.003921568859368563;
  a3 = *(_BYTE *)(LODWORD(v7) + 10);
  flt_F8B0A8[*(_DWORD *)v25] = (double)a3 * 0.003921568859368563;
  v24 = pD3DRenderer->bUsingSpecular;
  dword_F8AF18[*(_DWORD *)v25] = abs(v33);
  byte_F8B0F8[*(_DWORD *)v25] = *(_BYTE *)(LODWORD(v7) + 11);
  v23 = (int)pD3DRenderer->pRenderD3D3;
  v22 = byte_F8B0F8[*(_DWORD *)v25];
  if ( pD3DRenderer->pRenderD3D3 )
  {
    if ( v24 )
    {
      if ( v22 & 4 )
        v22 = byte_4E94D2;
    }
  }
  byte_F8B0F8[*(_DWORD *)v25] = v22;
  v26 = 4 * *(_DWORD *)v25;
  if ( v23 )
  {
    if ( v24 )
    {
      if ( byte_F8B0F8[*(_DWORD *)v25] & 4 )
      {
        *(float *)((char *)flt_F8B008 + v26) = *(float *)((char *)flt_F8B008 + v26) * 0.3300000131130219;
        *(float *)(v26 + 16298072) = *(float *)(v26 + 16298072) * 0.3300000131130219;
        *(float *)(v26 + 16298152) = *(float *)(v26 + 16298152) * 0.3300000131130219;
      }
    }
  }
  ++*(_DWORD *)v25;
  return 1;
}


//----- (0045D643) --------------------------------------------------------
double __stdcall sub_45D643(int a1, float a2)
{
  double result; // st7@1

  result = (*(float *)(a1 + 28) - *(float *)(a1 + 32))
         * -1.0
         / (*(float *)(a1 + 48) - *(float *)(a1 + 44))
         * (a2 - *(float *)(a1 + 44))
         + *(float *)(a1 + 28);
  if ( result < 0.0 || result <= 1.0 )
  {
    if ( result < 0.0 )
      result = 0.0;
  }
  else
  {
    result = 1.0;
  }
  return result;
}

//----- (0045D698) --------------------------------------------------------
bool class04_sub_45D698(struct class04 *_this, char a2)
{
  int v2; // esi@1
  int v3; // edi@3
  int v4; // edi@7
  void *v6; // [sp+10h] [bp-8h]@1
  int v7; // [sp+14h] [bp-4h]@2
  int v8; // [sp+20h] [bp+8h]@6
 unsigned int i;

  v2 = (int)_this;
  v6 = pGame->class08_obj;
  if ( a2 & 1 )
  {
    v7 = 0;
      v3 = (int)_this->std__vector_000004 + 8;
    for (i = 0; i < _this->std__vector_000004_size; ++i)
    {

        sub_4379EE(v6, v3, *(_DWORD *)(v3 - 4), 65280, 0.0);
        ++v7;
        v3 += 3100;

    }
  }

  if ( a2 & 2 )
  {
    v8 = 0;
      v4 = (int)_this->std__vector_183808 + 8;
    for (i = 0; i < _this->std__vector_183808_size; ++i)
    {

        sub_4379EE(v6, v4, *(_DWORD *)(v4 - 4), (int)pClass58_global->unk_11E458, 0.000199999994947575);
        ++v8;
        v4 += 3100;
    }
  }
  return true;
}

//----- (0045D74F) --------------------------------------------------------
char __thiscall sub_45D74F_MessWithLight(struct class04 *_this,int a2, int a3)
{
  char v3; // zf@1
  const char *v4; // eax@2
  int v5; // eax@2
  int v6; // eax@2
  int v7; // edi@4
  int v8; // eax@8
  int v9; // eax@8
  int v10; // eax@8
  int v11; // eax@8
  int v12; // eax@8
  int v13; // eax@8
  int v14; // eax@20
  int v15; // eax@20
  int v16; // eax@20
  int v17; // eax@20
  int v18; // eax@20
  int v19; // eax@20
  int v20; // eax@20
  int v21; // eax@20
  int v22; // eax@22
  int v24; // [sp+44h] [bp-44h]@12
  signed int v25; // [sp+48h] [bp-40h]@12
  int v26; // [sp+4Ch] [bp-3Ch]@12
  int v27; // [sp+50h] [bp-38h]@2
  unsigned int v28; // [sp+54h] [bp-34h]@2
  int v29; // [sp+58h] [bp-30h]@2
  int v30; // [sp+68h] [bp-20h]@8
  float v31; // [sp+6Ch] [bp-1Ch]@8
  float v32; // [sp+70h] [bp-18h]@8
  char *v33; // [sp+74h] [bp-14h]@18
  char *v34; // [sp+78h] [bp-10h]@2
  int v35; // [sp+7Ch] [bp-Ch]@10
  int v36; // [sp+80h] [bp-8h]@12
  float v37; // [sp+84h] [bp-4h]@1

  v3 = *(_DWORD *)(LODWORD(_this) + 1587204) == 0;
  v37 = *(float *)&_this;
  if ( !v3 )
  {
    v29 = 0;
    v28 = 1205;
    v5 = *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56);
    v27 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
    v6 = (*(int (__stdcall **)(int, _DWORD, signed int, signed int))(*(_DWORD *)v5 + 160))(v5, 0, 12, 3);
    CheckHRESULT((void **)&v34, v6, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp", 0x4B5u, 0);
    v4 = dword_69BD48;
    if ( !dword_69BD48 )
      v4 = (char *)byte_4D8410 + 736;
    v7 = sub_436A24(v4);
    if ( pD3DRenderer->bUsingSpecular )
      (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        28,
        0);
    if ( !byte_4D8410[572] || !(*(_BYTE *)(LODWORD(pGame) + 3616) & 1) )
    {
      v29 = 0;
      v28 = 1215;
      v27 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
      v9 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
             *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
             27,
             1);
      CheckHRESULT((void **)&v34, v9, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp", 0x4BFu, 0);
      v29 = 0;
      v28 = 1216;
      v27 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
      v10 = (*(int (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
              *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
              26,
              0);
      CheckHRESULT((void **)&v34, v10, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp", 0x4C0u, 0);
      v29 = 0;
      v28 = 1219;
      v27 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
      v11 = (*(int (__stdcall **)(_DWORD, _DWORD, int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 152))(
              *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
              0,
              v7);
      CheckHRESULT((void **)&v34, v11, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp", 0x4C3u, 0);
      v29 = 0;
      v28 = 1220;
      v27 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
      v12 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
              *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
              19,
              2);
      CheckHRESULT((void **)&v34, v12, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp", 0x4C4u, 0);
      v29 = 0;
      v28 = 1221;
      v27 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
      v13 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
              *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
              20,
              2);
      CheckHRESULT((void **)&v34, v13, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp", 0x4C5u, 0);
      v8 = a3;
      v32 = 1.0;
      v31 = 1.0;
      *(float *)&v30 = 1.0;
      if ( a3 )
      {
        if ( *(_DWORD *)a3 != -1 )
        {
          v35 = a3;
          do
          {
            v27 = 3100 * *(_DWORD *)v8 + LODWORD(v37) + 4;
            if ( !sub_45DAE8(v27, (int)&v30, 0.0) )
            {
              v29 = 1230;
              v28 = (unsigned int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
              v34 = (char *)&v24;
              Game_sub_40E2C8(&v24, "Invalid lightmap detected!", (int)((char *)&a3 + 3));
              sub_467834(&v36, v24, (const CHAR *)v25, v26, v27, (const char *)v28, v29);
              v36 = 5080812;
            }
            v8 = v35 + 4;
            v35 = v8;
          }
          while ( *(_DWORD *)v8 != -1 );
        }
      }
      else
      {
        v35 = 0;
        if ( *(_DWORD *)(LODWORD(v37) + 1587204) > 0 )
        {
          v36 = LODWORD(v37) + 4;
          do
          {
            if ( !sub_45DAE8(v36, (int)&v30, 0.0) )
            {
              v29 = 1238;
              v28 = (unsigned int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
              v33 = (char *)&v24;
              Game_sub_40E2C8(&v24, "Invalid lightmap detected!", (int)((char *)&a3 + 3));
              sub_467834(&v34, v24, (const CHAR *)v25, v26, v27, (const char *)v28, v29);
              v34 = (char *)byte_4D8410 + 732;
            }
            ++v35;
            v36 += 3100;
          }
          while ( v35 < *(_DWORD *)(LODWORD(v37) + 1587204) );
        }
      }
      v29 = 0;
      v28 = 1242;
      v27 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
      v14 = *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56);
      v26 = 2;
      v25 = 19;
      *(_DWORD *)&v24 = v14;
      v15 = (*(int (__stdcall **)(int, signed int, signed int))(*(_DWORD *)v14 + 88))(v14, 19, 2);
      CheckHRESULT((void **)&a3, v15, (const char *)v27, v28, v29);
      v29 = 0;
      v28 = 1243;
      v27 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
      v16 = *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56);
      v26 = 1;
      v25 = 20;
      *(_DWORD *)&v24 = v16;
      v17 = (*(int (__stdcall **)(int, signed int, signed int))(*(_DWORD *)v16 + 88))(v16, 20, 1);
      CheckHRESULT((void **)&a3, v17, (const char *)v27, v28, v29);
      v29 = 0;
      v28 = 1244;
      v27 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
      v18 = *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56);
      v26 = 0;
      v25 = 27;
      *(_DWORD *)&v24 = v18;
      v19 = (*(int (__stdcall **)(int, signed int, _DWORD))(*(_DWORD *)v18 + 88))(v18, 27, 0);
      CheckHRESULT((void **)&a3, v19, (const char *)v27, v28, v29);
      v29 = 0;
      v28 = 1245;
      v27 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
      v20 = *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56);
      v26 = 1;
      v25 = 26;
      *(_DWORD *)&v24 = v20;
      v21 = (*(int (__stdcall **)(int, signed int, signed int))(*(_DWORD *)v20 + 88))(v20, 26, 1);
      CheckHRESULT((void **)&a3, v21, (const char *)v27, v28, v29);
    }
    if ( pD3DRenderer->bUsingSpecular )
    {
      v29 = 1;
      v28 = 28;
      v27 = *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56);
      (*(void (__stdcall **)(int, signed int, signed int))(*(_DWORD *)v27 + 88))(v27, 28, 1);
      v29 = dword_EF524C;
      v22 = *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56);
      v28 = 34;
      v27 = v22;
      (*(void (__stdcall **)(int, signed int, int))(*(_DWORD *)v22 + 88))(v22, 34, dword_EF524C);
      v29 = 0;
      v28 = 35;
      v27 = *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56);
      (*(void (__stdcall **)(int, signed int, _DWORD))(*(_DWORD *)v27 + 88))(v27, 35, 0);
    }
  }
  return 1;
}

//----- (0045DA56) --------------------------------------------------------
char __thiscall sub_45DA56(int _this, float a2)
{
  int v2; // eax@1
  int v3; // esi@1
  int v4; // edi@2
  char v6; // [sp-14h] [bp-3Ch]@5
  const CHAR *v7; // [sp-10h] [bp-38h]@5
  int v8; // [sp-Ch] [bp-34h]@5
  int v9; // [sp-8h] [bp-30h]@5
  const char *v10; // [sp-4h] [bp-2Ch]@5
  int v11; // [sp+0h] [bp-28h]@5
  int v12; // [sp+Ch] [bp-1Ch]@2
  float v13; // [sp+10h] [bp-18h]@2
  float v14; // [sp+14h] [bp-14h]@2
  char *v15; // [sp+18h] [bp-10h]@5
  int v16; // [sp+1Ch] [bp-Ch]@5
  int v17; // [sp+20h] [bp-8h]@3
  int v18; // [sp+27h] [bp-1h]@5

  v3 = _this;
  v2 = *(_DWORD *)(_this + 3968008);
  if ( v2 )
  {
    v4 = 0;
    v14 = 1.0;
    v13 = 1.0;
    *(float *)&v12 = 1.0;
    if ( v2 > 0 )
    {
      v17 = _this + 1587208;
      do
      {
        if ( !sub_45DAE8(v17, (int)&v12, a2) )
        {
          v11 = 1288;
          v10 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
          v15 = &v6;
          Game_sub_40E2C8(&v6, "Invalid lightmap detected!", (int)&v18);
          sub_467834(&v16, v6, v7, v8, v9, v10, v11);
          v16 = 5080812;
        }
        v17 += 3100;
        ++v4;
      }
      while ( v4 < *(_DWORD *)(v3 + 3968008) );
    }
  }
  return 1;
}

//----- (0045DAE8) --------------------------------------------------------
char __stdcall sub_45DAE8(int a1, int a2, float a3)
{
  int v3; // edx@1
  char result; // al@2
  int v5; // edi@3
  int v6; // esi@3
  double v7; // st7@3
  int v8; // ecx@3
  double v9; // st7@4
  int v10; // ebx@6
  int v11; // edx@7
  char *v12; // ecx@7
  double v13; // st7@7
  double v14; // st3@8
  __int16 v15; // fps@8
  unsigned __int8 v16; // c2@8
  unsigned __int8 v17; // c3@8
  int v18; // eax@11
  double v19; // st3@11
  int v20; // eax@11
  char v21; // zf@11
  int v22; // eax@15
  signed int v23; // [sp-1Ch] [bp-670h]@13
  const char *v24; // [sp-18h] [bp-66Ch]@13
  unsigned int v25; // [sp-14h] [bp-668h]@13
  char v26; // [sp+0h] [bp-654h]@15
  char v27; // [sp+4h] [bp-650h]@7
  double v28; // [sp+640h] [bp-14h]@3
  __int64 v29; // [sp+648h] [bp-Ch]@3
  float v30; // [sp+650h] [bp-4h]@3
  signed int v31; // [sp+65Ch] [bp+8h]@3
  float v32; // [sp+65Ch] [bp+8h]@3
  float v33; // [sp+65Ch] [bp+8h]@3
  float v34; // [sp+65Ch] [bp+8h]@3
  int v35; // [sp+65Ch] [bp+8h]@7
  int v36; // [sp+660h] [bp+Ch]@3

  v3 = a1;
  if ( *(_DWORD *)(a1 + 4) >= 3 )
  {
    v7 = (double)*(_BYTE *)(a1 + 3089) * *(float *)(a1 + 3092);
    v29 = *(_DWORD *)(a1 + 3088) & 0xFFi64;
    v31 = *(_BYTE *)(a1 + 3090);
    v8 = a2;
    v30 = v7;
    *((float *)&v29 + 1) = (double)v29 * *(float *)(v3 + 3092);
    v32 = (double)v31 * *(float *)(v3 + 3092) * *(float *)a2;
    v28 = v32 + 6.755399441055744e15;
    v36 = LODWORD(v28);
    v33 = v30 * *(float *)(v8 + 4);
    v28 = v33 + 6.755399441055744e15;
    LODWORD(v30) = LODWORD(v28);
    v34 = *((float *)&v29 + 1) * *(float *)(v8 + 8);
    v28 = v34 + 6.755399441055744e15;
    HIDWORD(v29) = LODWORD(v28);
    v5 = uCurrentlyLoadedLevelType;
    v6 = LODWORD(v28) | ((LODWORD(v30) | (v36 << 8)) << 8);
    if ( uCurrentlyLoadedLevelType == 2 )
      v9 = (double)pStruct9_global->shading_dist_mist;
    else
      v9 = 16192.0;
    v10 = *(_DWORD *)(v3 + 4);
    if ( v10 > 0 )
    {
      v12 = &v27;
      v11 = v3 + 20;
      v13 = 1.0 / v9;
      v35 = v10;
      do
      {
        UNDEF(v15);
        v14 = 1.0 - 1.0 / (v13 * *(float *)v11 * 1000.0);
        if ( !(v17 | v16) )
        {
          v14 = v14 - a3;
          if ( v14 < 0.00009999999747378752 )
            v14 = 0.00009999999747378752;
        }
        *((float *)v12 + 1) = v14;
        v18 = *(_DWORD *)(v11 + 12);
        *((_DWORD *)v12 + 4) = 0;
        v19 = 1.0 / *(float *)v11;
        *((_DWORD *)v12 - 1) = v18;
        *(_DWORD *)v12 = *(_DWORD *)(v11 + 16);
        *((_DWORD *)v12 + 5) = *(_DWORD *)(v11 + 24);
        v20 = *(_DWORD *)(v11 + 28);
        *((_DWORD *)v12 + 3) = v6;
        *((_DWORD *)v12 + 6) = v20;
        v11 += 48;
        v12 += 32;
        v21 = v35-- == 1;
        *((float *)v12 - 6) = v19;
      }
      while ( !v21 );
    }
    if ( v5 == 1 )
    {
      v25 = 1346;
      v24 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
      v23 = 28;
    }
    else
    {
      v25 = 1354;
      v24 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp";
      v23 = 16;
    }
    v22 = (*(int (__stdcall **)(_DWORD, signed int, signed int, char *, int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56)
                                                                                        + 112))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            6,
            452,
            &v26,
            v10,
            v23);
    CheckHRESULT((void **)&a3, v22, v24, v25, 0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0045DCA9) --------------------------------------------------------
void __fastcall sub_45DCA9(unsigned int a1, const char *a2, int a3, int a4, int a5, int a6)
{
  const char *v10; // eax@4
  int v11; // eax@4
  int v12; // eax@4
  int v13; // eax@4
  int v14; // ebp@6
  int v15; // ST90_4@6
  const char *v16; // ST88_4@6
  int v17; // eax@6
  int v18; // eax@6
  int v19; // eax@6
  int v20; // eax@6
  int v21; // eax@6
  int v22; // eax@6
  int v23; // eax@6
  int v24; // eax@6
  unsigned int v25; // [sp+98h] [bp-8h]@1
  int v26; // [sp+9Ch] [bp-4h]@1

  v26 = a1;
  v25 = a1;
  if ( *(_DWORD *)(a1 + 3968008) )
  {
    if ( pD3DRenderer->bUsingSpecular )
      (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        28,
        0);
    (*(void (__stdcall **)(_DWORD, signed int, signed int, int, int, int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
      *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
      22,
      1,
      a5,
      a3,
      a4);
    v11 = (*(int (__stdcall **)(_DWORD, signed int, _DWORD, _DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56)
                                                                                       + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            14,
            0,
            (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp",
            __LINE__,
            0);
    CheckHRESULT((void **)0, v11, a2, v25, v26);
    v12 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            27,
            1);
    CheckHRESULT((void **)0, v12, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp", __LINE__, 0);
    v13 = (*(int (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            26,
            0);
    CheckHRESULT((void **)0, v13, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp", __LINE__, 0);
    v10 = dword_69BD48;
    if ( !dword_69BD48 )
      v10 = (char *)byte_4D8410 + 736;
    v14 = **(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56);
    v15 = sub_436A24(v10);
    v16 = *(const char **)(pD3DRenderer->pRenderD3D3 + 56);
    v17 = (*(int (**)(void))(v14 + 152))();
    CheckHRESULT((void **)0, v17, v16, 0, v15);
    v18 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            19,
            2);
    CheckHRESULT((void **)0, v18, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp", __LINE__, 0);
    v19 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            20,
            2);
    CheckHRESULT((void **)0, v19, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp", __LINE__, 0);
    sub_45DA56(a6, 0.0005000000237487257);
    v20 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            19,
            2);
    CheckHRESULT((void **)0, v20, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp", __LINE__, 0);
    v21 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            20,
            1);
    CheckHRESULT((void **)0, v21, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp", __LINE__, 0);
    v22 = (*(int (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            27,
            0);
    CheckHRESULT((void **)0, v22, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp", __LINE__, 0);
    v23 = (*(int (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            26,
            1);
    CheckHRESULT((void **)0, v23, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp", __LINE__, 0);
    v24 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
            *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
            14,
            1);
    CheckHRESULT((void **)0, v24, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Light.cpp", __LINE__, 0);
    (*(void (__cdecl **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
      *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
      22,
      2);
    if ( pD3DRenderer->bUsingSpecular )
      (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        28,
        1);
  }
}

//----- (0045DF48) --------------------------------------------------------
void __fastcall class04_stru0_detor(struct class04_stru0 *_this)
{
 _this->ptr_000000 = (char *)5080824;
  compile_error();//JUMPOUT(*(unsigned int *)loc_40E4FC);
}



//----- (0045E26C) --------------------------------------------------------
int __thiscall sub_45E26C(char *Filename)
{
  int v3; // eax@1
  unsigned int v4; // esi@1
  int v5; // eax@1

 // v3 = sub_45E03A_SomethingLikeCaptureAScreenshot(92, 68);
  v4 = v3;
  v5 = (int)sub_49F8B5(pD3DRenderer, Filename, v3, 92, 68);
  /*return */operator_delete((void *)v4);
  return rand();
}




//----- (00460A78) --------------------------------------------------------
char __thiscall PrepareToLoadBLV(void *_this)
{
  int v1; // ebx@1
  signed int v2; // eax@8
  int v3; // edi@9
  int v4; // eax@11
  int v5; // eax@12
  int v6; // eax@13
  int v7; // esi@27
  int v8; // edx@28
  char v9; // bl@33
  int v10; // eax@34
  void *v11; // ecx@37
  int v12; // edi@44
  int v13; // edi@48
  int v14; // esi@49
  __int16 v15; // ax@50
  int v16; // ecx@52
  int v17; // eax@54
  int v18; // ecx@55
  char v19; // dl@58
  int v20; // edi@58
  int v21; // eax@64
  char v22; // cl@64
  signed int v23; // ebx@67
  int v24; // esi@68
  int v25; // eax@70
  _UNKNOWN *v26; // esi@78
  int v27; // eax@79
  char v28; // zf@81
  __int16 v29; // ax@85
  signed int v30; // eax@93
  signed int v31; // edi@94
  int v32; // esi@94
  int v33; // edx@100
  char v35; // [sp+Ch] [bp-408h]@91
  __int16 v36; // [sp+6Ch] [bp-3A8h]@91
  char Args[152]; // [sp+350h] [bp-C4h]@16
  int v38[4]; // [sp+3E8h] [bp-2Ch]@96
  int v39; // [sp+3F8h] [bp-1Ch]@1
  int v40; // [sp+3FCh] [bp-18h]@58
  int v41; // [sp+400h] [bp-14h]@1
  int v42; // [sp+404h] [bp-10h]@1
  int v43; // [sp+408h] [bp-Ch]@8
  int v44; // [sp+40Ch] [bp-8h]@1
  int i; // [sp+410h] [bp-4h]@27

  v41 = (int)_this;
  v1 = 0;
  v39 = 0;
  compile_error();
            //LevelLoadingUI_Reset(pGameLoadingUI_ProgressBar, 32);
  byte_6BE3C4_MaybeDrowningFlag = 0;
  byte_6BE3C5 = 0;
  v42 = 0;
  v44 = 1;
  uCurrentlyLoadedLevelType = 1;
  *(_DWORD *)(LODWORD(pGame) + 3620) &= 0xFFFFFFF7u;
  if ( sub_464839() )
  {
    byte_6BE3C4_MaybeDrowningFlag = 1;
    *(_DWORD *)(LODWORD(pGame) + 3620) |= 8u;
  }
  
  compile_error(file name should not be global);
    //
  //if ( !_strcmpi(CurrentLevelName, "out15.odm") || !_strcmpi(CurrentLevelName, "d23.blv") )
    byte_6BE3C5 = 1;
  class35_obj.byte_267AD3 = 0;
  class35_obj.byte_267AD4 = 0;
  class35_obj.byte_267AD5 = 0;
  class35_sub_48A614(&class35_obj);
  if ( qword_A750D8 )
    qword_A750D8 = 0i64;
  compile_error(file name should not be global);
    //v2 = CMapStats_FindLocation(pMapStats, CurrentLevelName);
  v43 = v2;
  if ( v2 )
  {
   v3 = (int)pMapStats->pMapInfos[v2].pLocationName;
    v1 = *(_DWORD *)(v3 + 28);
    v42 = sub_450DA3();
  }
  else
  {
    v3 = v41;
  }
  dword_6BE13C = v43;


  pStationaryLightsStack->uNumStationaryLightsActive = 0;
  compile_error(file name should not be global);
    //
  /*v4 = sub_498E0A(
         byte_6BE3C8,
         CurrentLevelName,
         (unsigned int)(signed __int64)((double)pParty_global->qword_00002C * 0.234375) / 60 / 60 / 24 + 1,
         v1,
         (int)&v44)
     - 1;*/
  if ( !v4 )
  {
    compile_error(file name should not be global);
    //wsprintfA(Args, "Unable to open %s", CurrentLevelName);
    erroneous_printf(Args);
  }
  v5 = v4 - 1;
  if ( !v5 )
  {
    compile_error(file name should not be global);
    //wsprintfA(Args, "File %s is not a BLV File", CurrentLevelName);
    erroneous_printf(Args);
  }
  v6 = v5 - 1;
  if ( !v6 )
    erroneous_printf("Attempt to open new level before clearing old");
  if ( v6 == 1 )
    erroneous_printf("Out of memory loading indoor level");
  if ( !(BYTE1(dword_6BE364) & 0x20) )
  {
    UpdateActors();
    sub_408896();
  }
  BYTE1(dword_6BE364) &= 0xDFu;
  if ( !v43 )
    v44 = 0;
  if ( v44 == 1 )
  {
    v7 = 0;
    for ( i = 0; i < dword_6BE684; v7 += 24 )
    {
      v8 = dword_6BE688 + v7;
      if ( *(_WORD *)(dword_6BE688 + v7 + 14) == 3 )
        sub_44F57C_MaybeCreateRandomMonster(v3, v8, 0, 0, 0);
      else
        sub_44FFD8(v3, v8);
      ++i;
    }
    sub_450AAA();
  }
  sub_4A9A67(pSoundList, (unsigned __int16)word_4F0040[v43], 0);
  sub_4A9A67(pSoundList, (unsigned __int16)word_4F0040[v43] + 1, 0);
  i = 0;
  v9 = 2;
  if ( dword_6BE660 > 0 )
  {
    v10 = 0;
    while ( 1 )
    {
      if ( *((_BYTE *)Src + v10) & 1 )
      {
        *(_WORD *)((char *)Src + v10 + 76) = 1;
        *(_DWORD *)((char *)Src + v10 + 8) = 15360;
        *(_DWORD *)((char *)Src + v10) = 2;
      }
      v11 = (char *)Src + v10 + 76;
      if ( !*(_WORD *)v11 )
        break;
      if ( *(_WORD *)v11 == 2 )
      {
        *(_WORD *)v11 = 1;
        goto LABEL_41;
      }
LABEL_42:
      ++i;
      v10 += 80;
      if ( i >= dword_6BE660 )
        goto LABEL_43;
    }
    *(_WORD *)v11 = 3;
LABEL_41:
    *(_DWORD *)((char *)Src + v10 + 8) = 15360;
    *(_DWORD *)((char *)Src + v10) = 2;
    goto LABEL_42;
  }
LABEL_43:
  i = 0;
  if ( dword_6BE640 > 0 )
  {
    v12 = 0;
    do
    {
      if ( *(_WORD *)(dword_6BE644 + v12 + 74) != -1 ? 72 * *(_WORD *)(dword_6BE644 + v12 + 74) + 7278780 : 0 )
        *(_WORD *)(*(_WORD *)(dword_6BE644 + v12 + 74) != -1 ? 72 * *(_WORD *)(dword_6BE644 + v12 + 74) + 7278780 + 0x26 : 38) = class35_sub_48A3BC_MessWithPalettes(&class35_obj, *(_WORD *)(*(_WORD *)(dword_6BE644 + v12 + 74) != -1 ? 72 * *(_WORD *)(dword_6BE644 + v12 + 74) + 7278780 + 0x24 : 36));
      ++i;
      v12 += 96;
    }
    while ( i < dword_6BE640 );
  }
  v13 = 0;
  compile_error();
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  i = 0;
  if ( (signed int)uNumLevelDecorations > 0 )
  {
   v14 = (int)&pLevelDecorations[0].sPosY;
    do
    {
      sub_458693(pDecorationDescriptionList, *(_WORD *)(v14 - 8));
      v15 = *(_WORD *)(84 * *(_WORD *)(v14 - 8) + pDecorationDescriptionList->pDescriptions + 76);
      if ( v15 != (_WORD)v13 )
      {
        if ( dword_6807E0 < 9 )
        {
          sub_4A9A67(pSoundList, v15, v13);
          v16 = dword_6807E0++;
          dword_6807B8[v16] = i;
        }
      }
      if ( !(*(_BYTE *)(v14 - 6) & 0x20) )
      {
        v17 = (int)pDecorationDescriptionList->pDescriptions + 84 * *(_WORD *)(v14 - 8);
        if ( !((unsigned __int8)v9 & *(_BYTE *)(v17 + 74)) )
        {
          v18 = *(_WORD *)(v17 + 70);
          if ( v18 != v13 )
          {
            if ( (int)pD3DRenderer->pRenderD3D3 == v13 || pD3DRenderer->bUseColoredLights == v13 )
            {
              v19 = -1;
              v20 = 255;
              v40 = 255;
            }
            else
            {
              v20 = *(_BYTE *)(v17 + 80);
              v19 = *(_BYTE *)(v17 + 81);
              v40 = *(_BYTE *)(v17 + 82);
            }
            StationaryLightsStack_AddLight(pStationaryLightsStack,
              *(_DWORD *)(v14 - 4),
              *(_DWORD *)v14,
              *(_WORD *)(v14 + 4) + *(_WORD *)(v17 + 66) / 2,
              v18,
              v20,
              v19,
              v40,
              byte_4E94D0);
            v13 = 0;
            v9 = 2;
          }
        }
      }
      if ( *(_WORD *)(v14 + 14) == (_WORD)v13 )
      {
        if ( sub_44C2F4_SomeDecorationTypeCheck((LevelDecoration *)(v14 - 8)) )
        {
          if ( v39 < 124 )
          {
            v21 = v39 + 1;
            *(_WORD *)(v14 + 20) = v39 + 75;
            v22 = global_5E4C90.byte_000000[v21 + 74];
            v39 = v21;
            if ( !v22 )
              *(_BYTE *)(v14 - 6) |= 0x20u;
          }
        }
      }
      ++i;
      v14 += 32;
    }
    while ( i < (signed int)uNumLevelDecorations );
  }
  compile_error();
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  v23 = 0;
  if ( (signed int)uNumLayingItems > v13 )
  {
    v24 = (int)&pLayingItemsList[0].stru_000024;
    do
    {
      if ( *(_WORD *)(v24 - 34) != (_WORD)v13 )
      {
        v25 = *(_DWORD *)v24;
        if ( *(_DWORD *)v24 != v13 )
        {
          if ( v25 != 220 )
          {
           if (pClass40->pItems[v25 - 1].uEquipType == 14 )
            {
              if ( *(_DWORD *)(v24 + 4) == v13 )
                *(_DWORD *)(v24 + 4) = rand() % 15 + 5;
            }
          }
          class40_sub_456D17(pClass40, (ItemGen *)v24);
        }
      }
      ++v23;
      v24 += 112;
    }
    while ( v23 < (signed int)uNumLayingItems );
  }
  i = v13;
  if ( (signed int)uNumActors > v13 )
  {
   v26 = (char *)&pActors->dword_000024;
    do
    {
      v27 = *(_DWORD *)v26;
      if ( v27 & 0x100000 )
      {
        if ( !v43 )
          goto LABEL_84;
        v28 = v42 == 0;
      }
      else
      {
        v28 = v42 == 1;
      }
      if ( !v28 )
      {
        Actor_LinkSprites((Actor *)((char *)v26 - 36), 0);
        v29 = *((_WORD *)v26 + 70);
        *((_BYTE *)v26 + 25) = 0;
        if ( v29 != 11 )
        {
          if ( v29 != 19 )
          {
            if ( !*((_WORD *)v26 + 2) || !*((_DWORD *)v26 + 18) )
            {
              *((_WORD *)v26 + 70) = 5;
              Actor_sub_45976D((Actor *)((char *)v26 - 36));
            }
          }
        }
        goto LABEL_90;
      }
LABEL_84:
      *((_WORD *)v26 + 70) = 19;
      *(_DWORD *)v26 = v27 | 0x10000;
LABEL_90:
      ++i;
      v26 = (char *)v26 + 836;
    }
    while ( i < (signed int)uNumActors );
  }
  compile_error();
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);
  Actor_TotalReset((Actor *)&v35);
  v36 = 45;
  Actor_LinkSprites((Actor *)&v35, 0);
  if ( !v41 )
  {
    pParty_global->sRotationX = 0;
    pParty_global->sRotationY = 0;
    pParty_global->sPartyPosZ = 0;
    pParty_global->sPartyPosY = 0;
    pParty_global->sPartyPosX = 0;
    pParty_global->dword_000700 = 0;
    pParty_global->dword_0006E8 = 0;
    sub_4498D5_TeleportToStartingPoint(dword_6BE35C);
  }
  sub_443365(&struct_576FE8);
  compile_error(level name should not be globally-defined);
  //LOBYTE(v30) = LoadLevel_InitializeMusic();
  if ( !v41 )
  {
    v31 = 0;
    v32 = 1;
    do
    {
      v30 = Player_sub_492C0B_MaybeIfPlayerConscious(pPlayers[v32]);
      if ( v30 )
        v38[v31++] = v32;
      ++v32;
    }
    while ( v32 <= 4 );
    if ( v31 )
    {
      if ( v44 )
      {
        qword_A750D8 = 256i64;
        word_A750E0 = 46;
        v33 = rand() % v31;
        LOWORD(v30) = LOWORD(v38[v33]);
        word_A750E2 = LOWORD(v38[v33]);
      }
    }
  }
  return v30;
}







//----- (004621DA) --------------------------------------------------------
int __fastcall sub_4621DA(signed int a1, signed int a2, signed int a3)
{
  signed int v3; // eax@2
  signed int v4; // eax@3
  signed int v5; // esi@4
  signed int v6; // esi@6

  if ( a1 < a2 )
  {
    v3 = a1;
    a1 = a2;
    a2 = v3;
  }
  v4 = a3;
  if ( a1 < a3 )
  {
    v5 = a1;
    a1 = a3;
    v4 = v5;
  }
  if ( a2 < v4 )
  {
    v6 = a2;
    a2 = v4;
    v4 = v6;
  }
  return (11 * a2 >> 5) + a1 + (v4 >> 2);
}

//----- (00462272) --------------------------------------------------------
void *__thiscall sub_462272(void *_this)
{
  int v1; // ebx@1
  void *v2; // esi@1
  signed int v5; // [sp+4h] [bp-10h]@1

  v2 = _this;
 // sub_46175B(_this);
  v1 = (int)((char *)v2 + 572);
  v5 = 1000;
  do
  {
   // cTexture_Zero((cTexture *)v1);
    v1 += 72;
  }
  while ( v5-- != 1 );
  *((_DWORD *)v2 + 18151) = 0;
  *((_DWORD *)v2 + 18150) = 0;
  *((_DWORD *)v2 + 18145) = 0;
  *((_DWORD *)v2 + 18144) = 0;
  *((_DWORD *)v2 + 18143) = 0;
  *((_DWORD *)v2 + 18153) = 0;
  *((_DWORD *)v2 + 18154) = 0;
  *((_DWORD *)v2 + 18155) = 0;
  *((_DWORD *)v2 + 18156) = 0;
  *((_DWORD *)v2 + 18157) = 0;
  return v2;
}


//----- (004623E5) --------------------------------------------------------
void *__thiscall sub_4623E5(void *_this)
{
  void *v2; // esi@1

  v2 = _this;
 // sub_46175B(_this);
 // compile_error();//_eh_vector_constructor_iterator_((char *)v2 + 572, 40, 1500, loc_46244C, sub_462463);
  *((_DWORD *)v2 + 15145) = 0;
  *((_DWORD *)v2 + 15144) = 0;
  *((_DWORD *)v2 + 15148) = 0;
  *((_DWORD *)v2 + 15147) = 0;
  *((_DWORD *)v2 + 15149) = 0;
  return v2;
}

//----- (00462463) --------------------------------------------------------
void __fastcall sub_462463(char *_this)
{
  int v1; // esi@1
  int result; // eax@2

  v1 = (int)_this;
  if ( !(*(_BYTE *)(_this + 27) & 4) )
  {
    MemFree( (void *)*(_DWORD *)(_this + 36));
     MemFree( (void *)*(_DWORD *)(v1 + 32));
  }
  *(_DWORD *)(v1 + 36) = 0;
  *(_DWORD *)(v1 + 32) = 0;
}



//----- (00462607) --------------------------------------------------------
int __thiscall sub_462607(int _this)
{
  int result; // eax@1

  result = _this;
  *(_DWORD *)(_this + 4) = 0;
  *(_DWORD *)_this = 0;
  *(_DWORD *)(_this + 8) = 0;
  *(_DWORD *)(_this + 12) = 0;
  *(_DWORD *)(_this + 16) = 0;
  *(_DWORD *)(_this + 20) = 0;
  *(_DWORD *)(_this + 24) = 0;
  return result;
}

//----- (004626CD) --------------------------------------------------------
void *__thiscall sub_4626CD(void *_this)
{
  void *v2; // esi@1

  v2 = _this;
  sub_47C794((int)((char *)_this + 180));
  *((_WORD *)v2 + 120) = 0;
  *((_DWORD *)v2 + 61) = 1073741824;
  sub_462607((int)((char *)v2 + 1224));
  *((_DWORD *)v2 + 305) = 0;
  *((_DWORD *)v2 + 54) = 0;
  *((_DWORD *)v2 + 53) = 0;
  *((_DWORD *)v2 + 56) = 0;
  *((_DWORD *)v2 + 57) = 0;
  return v2;
}

//----- (0046271C) --------------------------------------------------------
int __cdecl sub_46271C()
{
  int result; // eax@1

  stru_6A0DA0.lStructSize = 76;
  stru_6A0DA0.hwndOwner = pAppWindow->GetAPIHandle();
  result = 0;
  stru_6A0DA0.hInstance = 0;
  stru_6A0DA0.lpstrFilter = "Indoor  BLV Files (*.blv)";
  stru_6A0DA0.lpstrCustomFilter = 0;
  stru_6A0DA0.nMaxCustFilter = 0;
  stru_6A0DA0.nFilterIndex = 0;
  stru_6A0DA0.lpstrFile = 0;
  stru_6A0DA0.nMaxFile = 260;
  stru_6A0DA0.nMaxFileTitle = 512;
  stru_6A0DA0.lpstrInitialDir = "levels";
  stru_6A0DA0.lpstrTitle = "Might and Magic® VII - Load Which Level?";
  stru_6A0DA0.Flags = 4;
  stru_6A0DA0.nFileOffset = 0;
  stru_6A0DA0.nFileExtension = 0;
  stru_6A0DA0.lpstrDefExt = "blv";
  stru_6A0DA0.lCustData = 0;
  stru_6A0DA0.lpfnHook = 0;
  stru_6A0DA0.lpTemplateName = 0;
  stru_6A0DA0.lpstrFileTitle = (LPSTR)(char *)TmpBuf;
  return result;
}

//----- (004646F0) --------------------------------------------------------
void __thiscall sub_4646F0(int _this)
{
  int v1; // ebx@1

  v1 = _this;
  if ( pD3DRenderer->pRenderD3D3 )
    Vis_sub_4C1A02(pGame->pVis);
  cClock1.clock_fn1();
  cClock2.clock_fn1();
  pParty_global->dword_007778 = 2;
  sub_427D48_MessWith_unnamed_50C0C8(&struct_50C0C8, 1);
  sub_464479_ResetCursorAndOther();
  compile_error(level name should not be globally-defined);
  //PrepareWorld(0, (v1 == 0) + 1);
  cClock2.clock_sub_426363();
  cClock1.clock_sub_426363();
}

//----- (00464761) --------------------------------------------------------
void Game_DeinitializeAndTerminate(void *Code)
{
  int v1; // esi@1
  HANDLE v2; // eax@1

  v1 = (int)Code;
  v2 = GetCurrentProcess();
  SetPriorityClass(v2, 0x20u);
  sub_464479_ResetCursorAndOther();
  /*v3 = */Game_Deinitialize();

  sub_49FC23(function_parameter_invalid(int)/*v3*/, (int)pD3DRenderer);
  
  MemFree(pAppWindow);
  pAppWindow = 0;
  //if ( !DestroyWindow(pAppWindow->GetAPIHandle()) )
  //  GetLastError();
  //hWnd_global = 0;


  exit(v1);
}

//----- (00464839) --------------------------------------------------------
char __cdecl sub_464839()
{
  compile_error(level file name should not be global);
    //return _strcmpi(CurrentLevelName, "out15.odm") == 0;
}

//----- (00464851) --------------------------------------------------------
void __cdecl sub_464851()
{
  dword_6BE040 = 50;
  dword_6BE044 = 5000;
}


//----- (00464F1B) --------------------------------------------------------
signed int __stdcall DialogFunc(HWND hDlg, int a2, __int16 a3, int a4)
{
  char v4; // zf@3
  int v6; // eax@10
  int v7; // eax@11
  int v8; // eax@12
  int v9; // eax@13
  BOOL (__stdcall *v10)(HWND, int, LPCSTR); // edi@15
  const CHAR *v11; // [sp-Ch] [bp-Ch]@15
  INT_PTR v12; // [sp-4h] [bp-4h]@5

  if ( a2 == 272 )
  {
    dword_6A0CFC = hDlg;
    v6 = (GetUserDefaultLangID() & 0x3FF) - 7;
    if ( v6 )
    {
      v7 = v6 - 3;
      if ( v7 )
      {
        v8 = v7 - 2;
        if ( v8 )
        {
          v9 = v8 - 4;
          if ( v9 )
          {
            if ( v9 != 5 )
              return 0;
            SetWindowTextA(hDlg, "Wloz CD-ROM numer 2");
            v10 = SetDlgItemTextA;
            SetDlgItemTextA(hDlg, 1010, "Wloz CD-ROM numer 2 Might and Magic® VII.");
            v11 = "Odwolaj";
          }
          else
          {
            SetWindowTextA(hDlg, "Inserire il secondo CD");
            v10 = SetDlgItemTextA;
            SetDlgItemTextA(hDlg, 1010, "Inserire il secondo CD di Might and Magic® VII.");
            v11 = "Annulla";
          }
        }
        else
        {
          SetWindowTextA(hDlg, "Insérez le CD 2");
          v10 = SetDlgItemTextA;
          SetDlgItemTextA(hDlg, 1010, "Insérez Might & Magic® VII CD 2.");
          v11 = "Supprimer";
        }
      }
      else
      {
        SetWindowTextA(hDlg, "Por favor, inserte disco 2");
        v10 = SetDlgItemTextA;
        SetDlgItemTextA(hDlg, 1010, "Por favor, inserte disco 2 de Might & Magic® VII.");
        v11 = "Cancelar";
      }
    }
    else
    {
      SetWindowTextA(hDlg, "Bitte CD 2 einlegen");
      v10 = SetDlgItemTextA;
      SetDlgItemTextA(hDlg, 1010, "Bitte CD 2 von Might and Magic® VII einlegen.");
      v11 = "Abbrechen";
    }
    v10(hDlg, 2, v11);
    return 0;
  }
  if ( a2 == 273 )
  {
    if ( a3 == 2 )
    {
      v12 = 0;
LABEL_9:
      EndDialog(hDlg, v12);
      return 1;
    }
    v4 = a3 == 1;
  }
  else
  {
    v4 = a2 == 1025;
  }
  if ( v4 )
  {
    v12 = 1;
    goto LABEL_9;
  }
  return 0;
}


//----- (004667E9) --------------------------------------------------------
void __cdecl sub_4667E9()
{
  float v0; // ST14_4@17
  int v1; // ecx@24
  int v2; // esi@25
  int v3; // edx@26
  int v4; // eax@26
 // cPCXTexture *v5; // esi@33
	void		  *v5;
  const char *v6; // eax@34
  const char *v7; // [sp-4h] [bp-28h]@33
  int v8; // [sp+0h] [bp-24h]@33
  struct tagRECT Rect; // [sp+14h] [bp-10h]@15

  if (pD3DRenderer->bWindowMode)
    goto LABEL_52;

  compile_error();
  /*if ( dword_6BE364 & 2 )  // if primary surface color depth == 32
  {
    sub_4141CA(pGlobalTXT_LocalizationStrings[62], 0);
    return;
  }*/
  if ( !pD3DRenderer->pRenderD3D3 || **(_DWORD **)(pD3DRenderer->pRenderD3D3 + 28) )
  {
LABEL_52:
    if ( cClock1.dword_000004 )
      BYTE1(dword_6BE364) |= 8u;
    else
      cClock1.clock_fn1();
    if (cClock2.dword_000004)
      BYTE1(dword_6BE364) |= 0x10u;
    else
      cClock2.clock_fn1();
    pGame->pGUICursor->dword_000004 = 0;
    if ( pD3DRenderer->pRenderD3D3 )
    {
      LODFile_Bitmaps_LOD.sub_4103BB();
      LODFile_Sprites_LOD.sub_4ACB70();
    }
    if (pD3DRenderer->bWindowMode)
    {
      if ( GetWindowRect(pAppWindow->GetAPIHandle(), &Rect) )
      {
        RegistryWriteInt("window X", Rect.left);
        RegistryWriteInt("window Y", Rect.top);
        uWindowPosX = Rect.left;
        uWindowPosY = Rect.top;
      }
      SetMenu(pAppWindow->GetAPIHandle(), 0);

      runtime_error;
      //SetWindowLongA(pAppWindow->GetAPIHandle(), -20, 0);
      //SetWindowLongA(pAppWindow->GetAPIHandle(), -16, 268435456);
      //Render_Initialize(pD3DRenderer, pAppWindow->GetAPIHandle());
      v0 = (double)dword_4E2900_GammaPos * 0.10000000000000001 + 0.59999999999999998;
      GammaController_sub_44F4D9(pGame->pGammaController, v0);
    }
    else
    {
      ClipCursor(0);
      pD3DRenderer->Initialize(pAppWindow);
      SetWindowLongA(pAppWindow->GetAPIHandle(), -16, dwNewLong);
      SetMenu(pAppWindow->GetAPIHandle(), hMenu);
    }
    if ( pD3DRenderer->pRenderD3D3 )
    {
      LODFile_Bitmaps_LOD.sub_410423();
      LODFile_Sprites_LOD.sub_4ACBE0();
    }
    if ( class35_obj.uNumTargetBBits == pD3DRenderer->uNumTargetBBits && class35_obj.uNumTargetGBits == pD3DRenderer->uNumTargetGBits && class35_obj.uNumTargetRBits == pD3DRenderer->uNumTargetRBits )
      goto LABEL_38;
    class35_SetColorChannelInfo(&class35_obj, pD3DRenderer->uNumTargetRBits, pD3DRenderer->uNumTargetGBits, pD3DRenderer->uNumTargetBBits);
    class35_sub_48A614(&class35_obj);
    v1 = 0;
    if ( pObjectDescriptionList->uNumObjects > 0 )
    {
      v2 = 0;
      do
      {
        BYTE3(v3) = 0;
        v4 = v2 + (int)pObjectDescriptionList->pDescriptions;
        v2 += 56;
        *(_WORD *)((char *)&v3 + 1) = *(_BYTE *)(v4 + 50);
        LOBYTE(v3) = *(_BYTE *)(v4 + 51);
        ++v1;
        *(_DWORD *)(v4 + 44) = *(_BYTE *)(v4 + 52) | (v3 << 8);
      }
      while ( v1 < pObjectDescriptionList->uNumObjects );
    }
    MenuUI_LoadTextures(pParty_global->uAlignment);
   // if ( pVideoPlayer->dword_000024 )
   //   (cPCXTexture *)pVideoPlayer->dword_00006C-> , (const char *)&unk_F8BBEC, 1);
    if (uCurrentMenuID != MENU_MAIN)
    {
      if ( uCurrentMenuID != MENU_CREATEPARTY)
      {
        if ( uCurrentMenuID == 8 )
          dword_A74C88 = 1;
        goto LABEL_38;
      }
#ifdef OLD_CODE
      //v5 = pRGBTexture_Menu;
      cPCXID_CurrentMenu.PCXTexture_Release();
	   v7 = "makeme.pcx";
#endif
#ifndef OLD_CODE
      v5 = (void *)uTextureID_CurrentMenu;
      LODFile_Icons_LOD.LODFile_ReleaseTexture( uTextureID_CurrentMenu);
      v8 = 0;
      v7 = (char *)L"makeme";
#endif
    }
    else
    {
#ifdef OLD_CODE
      //v5 = pRGBTexture_Menu;
      //RGBTexture_Release(pRGBTexture_Menu); 
	cPCXID_CurrentMenu.PCXTexture_Release();
	v6 = "title.pcx";
      if ( uCurrentMenuID != MENU_MAIN)
        v6 = "lsave640.pcx";
      v8 = 0;
      v7 = v6;
#endif
#ifndef OLD_CODE
      v5 = (void *)uTextureID_CurrentMenu;
      LODFile_Icons_LOD.LODFile_ReleaseTexture( uTextureID_CurrentMenu);
      
      v6 = (char *)L"title";
      if ( uCurrentMenuID != MENU_MAIN)
        v6 = (char *)L"lsave640";
      v8 = 0;
      v7 = v6;
 #endif
    }
#ifdef OLD_CODE
   
   cPCXID_CurrentMenu.LODPCXLoad(v7,0);
   // v5->LODPCXLoad(v7, 0);
#endif

LABEL_38:
    struct_576FE8.dword_000044 = 1;
    sub_443343_GenerateSomeColorTable(&struct_576FE8);
    GUICursor_sub_4698F6(pGame->pGUICursor);
    if (pD3DRenderer->bWindowMode)
    {
      InvalidateRect(0, 0, 0);
      MoveWindow(pAppWindow->GetAPIHandle(), uWindowPosX, uWindowPosY, uWindowWidth, uWindowHeight, 0);
      ShowWindow(pAppWindow->GetAPIHandle(), 1);
    }
    pGame->pGUICursor->dword_000004 = 1;
    if (pVideoPlayer->IsAnyMovieLoaded())
      pVideoPlayer->sub_4BF73A();
    if ( BYTE1(dword_6BE364) & 8 )
      BYTE1(dword_6BE364) &= 0xF7u;
    else
      cClock1.clock_sub_426363();
    if ( BYTE1(dword_6BE364) & 0x10 )
      BYTE1(dword_6BE364) &= 0xEFu;
    else
      cClock2.clock_sub_426363();
    CAsyncMouse_Clear();
    sub_465F5A_InitializeAsyncMouseAndSomething();
    if (pAsyncMouse)
      CAsyncMouse_ClipCursorToScreen();
  }
}

//----- (00466D09) --------------------------------------------------------
void *__thiscall sub_466D09(void *_this, int a2, int a3, int a4, int a5, const char *Str, int a7)
{
  void *v8; // esi@1
  char v9; // [sp-2Ch] [bp-40h]@1
  const CHAR *v10; // [sp-28h] [bp-3Ch]@1
  int v11; // [sp-24h] [bp-38h]@1
  int v12; // [sp-20h] [bp-34h]@1
  UINT v13; // [sp-1Ch] [bp-30h]@1
  char v14; // [sp-18h] [bp-2Ch]@1
  int v15; // [sp-14h] [bp-28h]@1
  int v16; // [sp-10h] [bp-24h]@1
  int v17; // [sp-Ch] [bp-20h]@1
  int v18; // [sp-8h] [bp-1Ch]@1
  void *v19; // [sp+0h] [bp-14h]@1
  char *v20; // [sp+4h] [bp-10h]@1
  int v21; // [sp+10h] [bp-4h]@1

  v19 = _this;
  v8 = _this;
  v18 = a7;
  v21 = 0;
  *(_DWORD *)_this = 5080748;
  v20 = &v14;
  Game_sub_40E2C8(&v14, Str, (int)((char *)&a7 + 3));
  v13 = 48;
  LOBYTE(v21) = 1;
  v19 = &v9;
  Game_sub_40E2C8(&v9, "Fatal Exception", (int)((char *)&Str + 3));
  LOBYTE(v21) = 0;
  sub_466D83((int)&a2, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18);
  v21 = -1;
  Game_stru0_sub_40E2F6((Game_stru0 *)&a2, 1);
  return v8;
}

//----- (00467834) --------------------------------------------------------
void *__thiscall sub_467834(void *_this, char a2, const CHAR *a3, int a4, int a5, const char *a6, int a7)
{
  const CHAR *v7; // eax@1
  void *v8; // esi@1
  int v9; // eax@1
  int v10; // eax@1
  char v12; // [sp-14h] [bp-48h]@1
  int v13; // [sp-10h] [bp-44h]@1
  int v14; // [sp-Ch] [bp-40h]@1
  int v15; // [sp-8h] [bp-3Ch]@1
  const char *v16; // [sp-4h] [bp-38h]@1
  char v17; // [sp+4h] [bp-30h]@1
  int v18; // [sp+14h] [bp-20h]@1
  char *v19; // [sp+24h] [bp-10h]@1
  int v20; // [sp+30h] [bp-4h]@1

  v8 = _this;
  v16 = "\n";
  v20 = 0;
  v19 = &v12;
  *(_DWORD *)_this = 5080812;
  Game_sub_40E2C8(&v12, a6, (int)((char *)&a6 + 3));
  v9 = sub_4678E2((int)&v17, a7, v12, v13, v14, v15);
  LOBYTE(v20) = 1;
  v10 = sub_467BCF((int)&v18, v9, v16);
  LOBYTE(v20) = 2;
  sub_467AAF((int)&a2, v10, 0, 0xFFFFFFFFu);
  LOBYTE(v20) = 1;
  Game_stru0_sub_40E2F6((Game_stru0 *)&v18, 1);
  LOBYTE(v20) = 0;
  Game_stru0_sub_40E2F6((Game_stru0 *)&v17, 1);
  v7 = a3;
  if ( !a3 )
    v7 = (char *)byte_4D8410 + 736;
  OutputDebugStringA(v7);
  v20 = -1;
  Game_stru0_sub_40E2F6((Game_stru0 *)&a2, 1);
  return v8;
}

//----- (004678E2) --------------------------------------------------------
int __fastcall sub_4678E2(int a1, int a2, char a3, int a4, int a5, int a6)
{
  int v7; // esi@1
  int v8; // eax@1
  int v9; // eax@1
  char Str; // [sp+8h] [bp-144h]@1
  char v11; // [sp+108h] [bp-44h]@1
  int v12; // [sp+118h] [bp-34h]@1
  int v13; // [sp+128h] [bp-24h]@1
  int v14; // [sp+12Ch] [bp-20h]@1
  int v15; // [sp+13Ch] [bp-10h]@1
  int v16; // [sp+148h] [bp-4h]@1

  v15 = 0;
  v7 = a1;
  v13 = a1;
  v16 = 1;
  _itoa(a2, &Str, 10);
  v8 = sub_467C50((int)&v11, " in file: ", (int)&a3);
  LOBYTE(v16) = 2;
  v9 = sub_467BCF((int)&v12, v8, " at line number: ");
  LOBYTE(v16) = 3;
  sub_467BCF((int)&v14, v9, &Str);
  LOBYTE(v16) = 6;
  Game_stru0_sub_40E2F6((Game_stru0 *)&v12, 1);
  LOBYTE(v16) = 5;
  Game_stru0_sub_40E2F6((Game_stru0 *)&v11, 1);
  *(_BYTE *)v7 = v14;
  Game_stru0_sub_40E2F6((Game_stru0 *)v7, 0);
  sub_4679E2(v7, (int)&v14, 0, 0xFFFFFFFFu);
  v15 = 1;
  LOBYTE(v16) = 1;
  Game_stru0_sub_40E2F6((Game_stru0 *)&v14, 1);
  LOBYTE(v16) = 0;
  Game_stru0_sub_40E2F6((Game_stru0 *)&a3, 1);
  return v7;
}

//----- (004679B4) --------------------------------------------------------
int __thiscall sub_4679B4(void *_this, int a2)
{
  int v3; // esi@1

  v3 = (int)_this;
  *(_BYTE *)_this = *(_BYTE *)a2;
  Game_stru0_sub_40E2F6((Game_stru0 *)_this, 0);
  sub_4679E2(v3, a2, 0, 0xFFFFFFFFu);
  return v3;
}

//----- (004679E2) --------------------------------------------------------
int __thiscall sub_4679E2(int _this, int a2, unsigned int a3, size_t a4)
{
  int v4; // edi@1
  unsigned int v5; // esi@3
  signed int v6; // eax@9
  signed int v7; // eax@12
  signed int v8; // eax@16
  int v9; // eax@18

  v4 = _this;
  if ( *(_DWORD *)(a2 + 8) < a3 )
    sub_4CA564();
  v5 = *(_DWORD *)(a2 + 8) - a3;
  if ( a4 < v5 )
    v5 = a4;
  if ( _this == a2 )
  {
    std__basic_string_char_std__char_traits_char__std__allocator_char____erase(a3 + v5, -1);
    std__basic_string_char_std__char_traits_char__std__allocator_char____erase(0, a3);
  }
  else
  {
    if ( !v5 )
      goto LABEL_22;
    if ( v5 != *(_DWORD *)(a2 + 8) )
      goto LABEL_22;
    v6 = *(_DWORD *)(a2 + 4);
    if ( !v6 )
      v6 = 5080816;
    if ( *(_BYTE *)(v6 - 1) < 0xFEu )
    {
      Game_stru0_sub_40E2F6((Game_stru0 *)_this, 1);
      v7 = *(_DWORD *)(a2 + 4);
      if ( !v7 )
        v7 = 5080816;
      *(_DWORD *)(v4 + 4) = v7;
      *(_DWORD *)(v4 + 8) = *(_DWORD *)(a2 + 8);
      *(_DWORD *)(v4 + 12) = *(_DWORD *)(a2 + 12);
      ++*(_BYTE *)(v7 - 1);
    }
    else
    {
LABEL_22:
      if ( sub_40E363(_this, v5, 1) )
      {
        v8 = *(_DWORD *)(a2 + 4);
        if ( !v8 )
          v8 = 5080816;
        memcpy(*(void **)(v4 + 4), (const void *)(a3 + v8), v5);
        v9 = *(_DWORD *)(v4 + 4);
        *(_DWORD *)(v4 + 8) = v5;
        *(_BYTE *)(v5 + v9) = 0;
      }
    }
  }
  return v4;
}

//----- (00467AAF) --------------------------------------------------------
int __thiscall sub_467AAF(int _this, int a2, unsigned int a3, size_t Size)
{
  int v4; // esi@1
  unsigned int v5; // edi@8
  signed int v6; // eax@9
  int v7; // eax@11

  v4 = _this;
  if ( *(_DWORD *)(a2 + 8) < a3 )
    sub_4CA564();
  if ( *(_DWORD *)(a2 + 8) - a3 < Size )
    Size = *(_DWORD *)(a2 + 8) - a3;
  if ( -1 - *(_DWORD *)(_this + 8) <= Size )
    sub_4CA338();
  if ( Size )
  {
    v5 = Size + *(_DWORD *)(_this + 8);
    if ( sub_40E363(_this, v5, 0) )
    {
      v6 = *(_DWORD *)(a2 + 4);
      if ( !v6 )
        v6 = 5080816;
      memcpy((void *)(*(_DWORD *)(v4 + 8) + *(_DWORD *)(v4 + 4)), (const void *)(a3 + v6), Size);
      v7 = *(_DWORD *)(v4 + 4);
      *(_DWORD *)(v4 + 8) = v5;
      *(_BYTE *)(v5 + v7) = 0;
    }
  }
  return v4;
}

//----- (00467B9F) --------------------------------------------------------
void __thiscall sub_467B9F(int _this)
{
  int v1; // edi@1
  const char *v2; // esi@1
  char v3; // al@2
  size_t v4; // eax@4

  v1 = _this;
  v2 = *(const char **)(_this + 4);
  if ( v2 )
  {
    v3 = *(v2 - 1);
    if ( v3 )
    {
      if ( v3 != -1 )
      {
        Game_stru0_sub_40E2F6((Game_stru0 *)_this, 1);
        v4 = strlen(v2);
        sub_40E32E(v1, v2, v4);
      }
    }
  }
}

//----- (00467BCF) --------------------------------------------------------
int __cdecl sub_467BCF(int a1, int a2, const char *Src)
{
  char v4; // al@1
  size_t v5; // eax@1
  int v6; // eax@1
  int v7; // ebx@1
  char v8; // [sp+Ch] [bp-20h]@1
  int v9; // [sp+1Ch] [bp-10h]@1
  int v10; // [sp+28h] [bp-4h]@1

  v4 = *(_BYTE *)a2;
  v9 = 0;
  v8 = v4;
  Game_stru0_sub_40E2F6((Game_stru0 *)&v8, 0);
  sub_4679E2((int)&v8, a2, 0, 0xFFFFFFFFu);
  v10 = 0;
  v5 = strlen(Src);
  v6 = sub_467CD1((int)&v8, Src, v5);
  v7 = v6;
  *(_BYTE *)a1 = *(_BYTE *)v6;
  Game_stru0_sub_40E2F6((Game_stru0 *)a1, 0);
  sub_4679E2(a1, v7, 0, 0xFFFFFFFFu);
  Game_stru0_sub_40E2F6((Game_stru0 *)&v8, 1);
  return a1;
}

//----- (00467C50) --------------------------------------------------------
int __cdecl sub_467C50(int a1, const char *a2, int a3)
{
  size_t v4; // eax@1
  int v5; // eax@1
  int v6; // ebx@1
  char v7; // [sp+Ch] [bp-20h]@1
  int v8; // [sp+1Ch] [bp-10h]@1
  int v9; // [sp+28h] [bp-4h]@1

  v8 = 0;
  v7 = BYTE3(a2);
  Game_stru0_sub_40E2F6((Game_stru0 *)&v7, 0);
  v4 = strlen(a2);
  sub_40E32E((int)&v7, a2, v4);
  v9 = 0;
  v5 = sub_467AAF((int)&v7, a3, 0, 0xFFFFFFFFu);
  v6 = v5;
  *(_BYTE *)a1 = *(_BYTE *)v5;
  Game_stru0_sub_40E2F6((Game_stru0 *)a1, 0);
  sub_4679E2(a1, v6, 0, 0xFFFFFFFFu);
  Game_stru0_sub_40E2F6((Game_stru0 *)&v7, 1);
  return a1;
}

//----- (00467CD1) --------------------------------------------------------
int __thiscall sub_467CD1(int _this, const void *Src, size_t Size)
{
  int v3; // esi@1
  unsigned int v4; // edi@4
  int v5; // eax@5

  v3 = _this;
  if ( -1 - *(_DWORD *)(_this + 8) <= Size )
    sub_4CA338();
  if ( Size )
  {
    v4 = Size + *(_DWORD *)(_this + 8);
    if ( sub_40E363(_this, v4, 0) )
    {
      memcpy((void *)(*(_DWORD *)(v3 + 4) + *(_DWORD *)(v3 + 8)), Src, Size);
      v5 = *(_DWORD *)(v3 + 4);
      *(_DWORD *)(v3 + 8) = v4;
      *(_BYTE *)(v4 + v5) = 0;
    }
  }
  return v3;
}

//----- (00467D45) --------------------------------------------------------
int __thiscall sub_467D45(int _this)
{
  int result; // eax@1

  result = _this;
  *(_DWORD *)(_this + 7204) = 0;
  *(_DWORD *)_this = 5080856;
  return result;
}

//----- (00467D88) --------------------------------------------------------
char __thiscall sub_467D88(int _this, __int16 a2, __int16 a3, __int16 a4, __int16 a5, int a6, char a7, char a8, char a9, char *a10)
{
  signed int v10; // eax@1
  char result; // al@2
  int v12; // esi@2
  int v13; // eax@2
  char v14; // [sp-18h] [bp-1Ch]@3
  const CHAR *v15; // [sp-14h] [bp-18h]@3
  int v16; // [sp-10h] [bp-14h]@3
  int v17; // [sp-Ch] [bp-10h]@3
  const char *v18; // [sp-8h] [bp-Ch]@3
  int v19; // [sp-4h] [bp-8h]@3

  v10 = *(_DWORD *)(_this + 7204);
  if ( v10 >= 400 )
  {
    v19 = 51;
    v18 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\MobileLightStack.cpp";
    a10 = &v14;
    Game_sub_40E2C8(&v14, "Too many mobile lights!", (int)((char *)&a10 + 3));
    sub_467834(&a2, v14, v15, v16, v17, v18, v19);
    result = 0;
  }
  else
  {
    v12 = a6;
    v13 = _this + 18 * v10 + 4;
    *(_WORD *)v13 = a2;
    *(_WORD *)(v13 + 2) = a3;
    *(_WORD *)(v13 + 4) = a4;
    *(_WORD *)(v13 + 6) = v12;
    *(_WORD *)(v13 + 12) = (((v12 < 0) - 1) & 0x3E) - 31;
    *(_WORD *)(v13 + 14) = a5;
    *(_WORD *)(v13 + 16) = v12 * v12 >> 5;
    *(_BYTE *)(v13 + 8) = a7;
    *(_BYTE *)(v13 + 9) = a8;
    *(_BYTE *)(v13 + 10) = a9;
    *(_BYTE *)(v13 + 11) = (_BYTE)a10;
    ++*(_DWORD *)(_this + 7204);
    result = 1;
  }
  return result;
}

//----- (00467E7F) --------------------------------------------------------
void sub_467E7F_EquipBody(unsigned int uEquipType)
{
 Player *v1; // eax@1
  int v2; // edx@1
  int v3; // ebx@1
  //char v5; // zf@1
  int v6; // esi@2
  //int v7; // eax@2
  signed int v8; // eax@3

  struct ItemGen local_0C;
  //char v9; // [sp+Ch] [bp-30h]@1
  //char v10; // [sp+24h] [bp-18h]@2

  //void *v11; // [sp+30h] [bp-Ch]@1
  int v12; // [sp+34h] [bp-8h]@1
  //int *v13; // [sp+38h] [bp-4h]@1

  ItemGen_Reset(&local_0C);
  v3 = byte_4E8398[uEquipType];
  v1 = pPlayers[uActiveCharacter - 1];

  v2 = v12 = v1->pEquippedItemIndices[v3];
  if (v1->pEquippedItemIndices[v3] == -1)  // no armour
  {
    v8 = Player_FindNextFreeInventorySlotIndex(v1);
    if (v8 != -1)
    {
      pParty_global->pickedItem.byte_000018 = v3;
      memcpy(&v1->pInventorySlots[v8], &pParty_global->pickedItem, sizeof(struct ItemGen));
      v1->pEquippedItemIndices[v3] = v8;
      GUICursor_ResetDefaultCursorAfterItemDragging(pGame->pGUICursor);
    }
  }
  else // replace armour
  {
    memcpy(&local_0C, &pParty_global->pickedItem, sizeof(struct ItemGen));
    v6 = (int)((char *)v1 + 4 * (9 * v2 - 9));
    *(_BYTE *)(v6 + 556) = 0;
    ItemGen_Reset(&pParty_global->pickedItem);
    Party_sub_4936E1_ReceiveItemInHandsWhileInGame(pParty_global, (ItemGen *)(v6 + 532));
    local_0C.byte_000018 = v3;
    memcpy((void *)(v6 + 532), &local_0C, sizeof(ItemGen));
    v1->pEquippedItemIndices[v3] = v12;
  }
}

//----- (00467F48) --------------------------------------------------------
void __fastcall sub_467F48(signed int a1)
{
  signed int v1; // esi@1

  v1 = a1;
  if ( !ptr_507BC4)
  {
    if ( a1 >= 700 )
    {
      if ( a1 <= 782 )
      {
        dword_720980 = LODFile_Icons_LOD.LODFile_LoadTexture( "leather", 2);
        ptr_507BC4 = GUIWindowCreate(0, 0, 640, 480, 30, (GUIButton *)(v1 - 700), 0);
      }
    }
  }
}

//----- (00467F9F) --------------------------------------------------------
void __cdecl sub_467F9F()
{
  if (ptr_507BC4)
  {
    GUIWindowDelete(ptr_507BC4);
    ptr_507BC4 = 0;
  }
}

//----- (00467FB6) --------------------------------------------------------
void __cdecl sub_467FB6()
{
  int v0; // eax@1
  int v2; // ST18_4@3
  unsigned int v3; // eax@3

  GUI::Window local_0C;
  //int v4; // [sp+Ch] [bp-54h]@1
  //int v5; // [sp+10h] [bp-50h]@1
  //int v6; // [sp+14h] [bp-4Ch]@1
  //int v7; // [sp+18h] [bp-48h]@1
  //int v8; // [sp+1Ch] [bp-44h]@3
  //int v9; // [sp+20h] [bp-40h]@3
  //int v10; // [sp+54h] [bp-Ch]@1

  memcpy(&local_0C, ptr_507BC4, sizeof(GUI::Window));
  local_0C.ptr_000048 = 0;
  local_0C.uFrameX = 1;
  local_0C.uFrameY = 1;
  local_0C.uFrameWidth = 468;
  v0 = GUIFont_CalculateTextHeight(pFontSmallnum, dword_723D38[4 * ptr_507BC4->dword_00001C], &local_0C, 0, 0)
     + 2 * *(_BYTE *)(pFontCreate + 5)
     + 24;
  local_0C.uFrameHeight = v0;
  if ( v0 + local_0C.uFrameY > 479 )
  {
    v0 = 479 - local_0C.uFrameY;
    local_0C.uFrameHeight = 479 - local_0C.uFrameY;
  }
  local_0C.uFrameZ = local_0C.uFrameWidth + local_0C.uFrameX - 1;
  local_0C.uFrameW = v0 + local_0C.uFrameY - 1;
  GUIWindow_sub_415551(&local_0C, 0);

  local_0C.uFrameX += 12;
  local_0C.uFrameWidth -= 24;
  local_0C.uFrameY += 12;
  local_0C.uFrameHeight -= 12;
  local_0C.uFrameZ = local_0C.uFrameWidth + local_0C.uFrameX - 1;
  local_0C.uFrameW = local_0C.uFrameHeight + local_0C.uFrameY - 1;

  v2 = dword_5DAD28[12 * ptr_507BC4->dword_00001C];
  v3 = 0xFFFFFF9B;
  wsprintfA((char *)TmpBuf, "\x0C%05d%s\x0C\x30\x30\x30\x30\x30", v3, v2);
  GUIWindow_DrawText(&local_0C, pFontCreate, 0, 0, 0, (char *)TmpBuf, 3);
  FontDrawText(&local_0C, pFontSmallnum,
           1,
           pFontCreate->uFontHeight - 3,
           (char *)dword_723D38[4 * ptr_507BC4->dword_00001C],
           0,
           0,
           0);
}