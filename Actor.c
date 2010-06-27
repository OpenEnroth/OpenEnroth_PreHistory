#include "Actor.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "FrameTables.h"

#include "data.h"



//----- (0040894B) --------------------------------------------------------
bool sub_40894B(struct Actor *_this)
{
  bool v1; // esi@1
  __int16 v3; // ax@6

  v1 = false;
  if (*(_QWORD *)((char *)_this + 292) > 0i64 ||  *(_QWORD *)((char *)_this + 308) > 0i64 )
    v1 = true;
  v3 = _this->word_0000B0;
  return (v1 ||
          v3 == 4 || v3 == 5 || v3 == 11 || v3 == 17 || v3 == 19) == 0;
}



//----- (00408768) --------------------------------------------------------
char __cdecl sub_408768()
{
  __int16 v1; // ax@7
  signed int v5; // [sp+Ch] [bp-10h]@1
  signed int v6; // [sp+10h] [bp-Ch]@1
  signed int v7; // [sp+14h] [bp-8h]@1
  signed int v8; // [sp+18h] [bp-4h]@1

 struct Actor *pActor;
 int           i;

  v8 = 0;
  v6 = 0;
  v7 = 0;
  v5 = 0;
  if ( !_strcmpi(Str1, "d25.blv") )
    v8 = 1;
  if ( !_strcmpi(Str1, "d26.blv") )
    v6 = 1;
  if ( (unsigned __int16)sub_449B57((int)byte_ACD71D, 99) )
    v7 = 1;
  v1 = sub_449B57((int)byte_ACD71D, 100);
  if ( v1 )
    v5 = 1;

  for (i = 0; i < uNumActors; ++i)
  {
    pActor = &pActors[i];

      if ( sub_40894B(pActor) || pActor->word_0000B0 == 19 )
      {
        pActor->sActorPosX = pActor->word_0000A2;
        pActor->sActorPosY = pActor->word_0000A4;
        pActor->word_000092 = pActor->word_0000A6;
        pActor->word_000028 = pActor->word_00006C;
        if (pActor->word_0000B0 != 19)
          sub_403EB6(i, dword_4F6E08[i], pActor->dword_00007C, 0);
      }

      pActor->byte_00002A[19] = 0;

      LOBYTE(v1) = 0;
      if ( !v8 || v7 )
      {
        if ( !v6 || v5 )
        {
          LOBYTE(v1) = sub_438B9B(pActor);
          if ( (_BYTE)v1 )
           pActor->byte_000024[2] &= 0xF7u;
        }
      }
      pActor->byte_000024[2] &= 0x7Fu;
      if (pActor->byte_000024[2] & 0x40 )
        LOBYTE(v1) = sub_4031C1(i, pParty_global->dword_00071C, 1);
  }
  return v1;
}





//----- (00403EB6) --------------------------------------------------------
int __fastcall sub_403EB6(unsigned int uActorID, signed int a2, int a3, char *a4)
{
  char *v4; // eax@1
  int v5; // ebx@1
  int v6; // esi@1
  void *v7; // esi@2

  struct
  {
   char v9[0x1C]; // [sp+Ch] [bp-38h]@2
   char v10[0x1C + array_size_unknown]; // [sp+28h] [bp-1Ch]@2
  } v9;

 struct Actor *pActor;

  v4 = a4;
  v6 = 0;
  v5 = pActor = &pActors[uActorID];
  if ( !a4 )
  {
    v7 = sub_4040E9(8 * uActorID | 3, a2, &v9, 0);
    v4 = &v9.v10;
    memcpy(&v9.v10, v7, 0x1Cu);
    v6 = 0;
  }
  pActor->word_00009A = *((_WORD *)v4 + 10);
  if ( a3 == v6 )
    pActor->word_0000A0 = rand() % 256 + 256;
  else
    pActor->word_0000A0 = a3;

  pActor->word_0000B0 = v6;
  pActor->word_000094 = v6;
  pActor->word_000096 = v6;
  pActor->word_000098 = v6;

  *(_DWORD *)(v5 + 184) = v6;
  return sub_45976D(pActor);
}


//----- (004040E9) --------------------------------------------------------
void *__fastcall sub_4040E9(signed int a1, signed int a2, void *a3, signed int a4)
{
  signed int v4; // eax@1
  int v5; // ecx@1
  signed int v6; // ebx@1
  int v7; // ecx@2
  int v8; // ecx@3
  int v9; // ecx@4
  int v10; // ecx@8
  int v11; // eax@8
  int v12; // eax@9
  int v13; // eax@9
  int v14; // ecx@9
  int v15; // eax@11
  int v16; // eax@12
  int v17; // eax@13
  int v18; // edx@15
  int v19; // eax@25
  signed int v20; // eax@28
  signed int v21; // eax@28
  int v22; // ebx@28
  int v23; // ecx@35
  int v24; // eax@35
  int v25; // edx@35
  signed int v26; // eax@36
  int v27; // eax@36
  int v28; // ecx@36
  signed int v29; // eax@37
  int v30; // eax@42
  double v31; // st7@45
  double v32; // st7@45
  double v33; // st6@45
  void *result; // eax@48
  int v35; // [sp-18h] [bp-64h]@17
  int v36; // [sp-14h] [bp-60h]@17
  int v37; // [sp-10h] [bp-5Ch]@17
  int v38; // [sp-Ch] [bp-58h]@17
  int v39; // [sp-8h] [bp-54h]@15
  int v40; // [sp-4h] [bp-50h]@15
  int v41; // [sp+0h] [bp-4Ch]@15
  int v42; // [sp+4h] [bp-48h]@15
  int v43; // [sp+14h] [bp-38h]@46
  int v44; // [sp+18h] [bp-34h]@46
  int v45; // [sp+1Ch] [bp-30h]@46
  int v46; // [sp+20h] [bp-2Ch]@46
  int X; // [sp+24h] [bp-28h]@46
  int v48; // [sp+28h] [bp-24h]@46
  int v49; // [sp+2Ch] [bp-20h]@46
  float v50; // [sp+30h] [bp-1Ch]@23
  float v51; // [sp+34h] [bp-18h]@45
  int v52; // [sp+38h] [bp-14h]@33
  int v53; // [sp+3Ch] [bp-10h]@33
  int v54; // [sp+40h] [bp-Ch]@6
  int v55; // [sp+44h] [bp-8h]@6
  int v56; // [sp+48h] [bp-4h]@6
  float v57; // [sp+58h] [bp+Ch]@45

  v4 = a1 >> 3;
  v5 = (a1 & 7) - 2;
  v6 = a2;
  if ( !v5 )
  {
    v19 = 112 * v4;
    v56 = array_665230[v4].sItemPosX;
    v14 = array_665230[v4].sItemPosY;
    v12 = array_665230[v4].dword_00000C;
    goto LABEL_26;
  }
  v7 = v5 - 1;
  if ( !v7 )
  {
    v56 = pActors[v4].sActorPosX;
    v55 = pActors[v4].sActorPosY;
    LODWORD(v50) = pActors[v4].word_00008A;
    v10 = pActors[v4].word_000092 - (unsigned int)(signed __int64)((double)SLODWORD(v50) * -0.75);
    goto LABEL_24;
  }
  v8 = v7 - 1;
  if ( !v8 )
  {
    if ( !v4 )
    {
      v56 = pParty_global->sPartyPosX;
      v55 = pParty_global->sPartyPosY;
      v12 = pParty_global->dword_0006BC + pParty_global->dword_000004 / 3;
LABEL_27:
      v54 = v12;
      goto LABEL_28;
    }
    v15 = v4 - 1;
    if ( v15 )
    {
      v16 = v15 - 1;
      if ( v16 )
      {
        v17 = v16 - 1;
        if ( v17 )
        {
          if ( v17 != 1 )
            goto LABEL_28;
          v42 = (int)&v54;
          v41 = (int)&v55;
          v40 = (int)&v56;
          v18 = pParty_global->dword_0006C0 - pClass59_global->dword_001864;
          v39 = pParty_global->dword_0006BC + pParty_global->dword_000004 / 3;
          goto LABEL_20;
        }
        v42 = (int)&v54;
        v41 = (int)&v55;
        v40 = (int)&v56;
        v18 = pParty_global->dword_0006C0 - pClass59_global->dword_001864;
        v39 = pParty_global->dword_0006BC + pParty_global->dword_000004 / 3;
      }
      else
      {
        v42 = (int)&v54;
        v41 = (int)&v55;
        v40 = (int)&v56;
        v39 = pParty_global->dword_0006BC + pParty_global->dword_000004 / 3;
        v18 = pClass59_global->dword_001864 + pParty_global->dword_0006C0;
      }
      v38 = pParty_global->sPartyPosY;
      v37 = pParty_global->sPartyPosX;
      v36 = 0;
      v35 = 8;
LABEL_21:
      sub_43AA99(v35, v18, v36, v37, v38, v39, v40, v41, v42);
      goto LABEL_28;
    }
    v42 = (int)&v54;
    v41 = (int)&v55;
    v40 = (int)&v56;
    v39 = pParty_global->dword_0006BC + pParty_global->dword_000004 / 3;
    v18 = pClass59_global->dword_001864 + pParty_global->dword_0006C0;
LABEL_20:
    v38 = pParty_global->sPartyPosY;
    v37 = pParty_global->sPartyPosX;
    v36 = 0;
    v35 = 24;
    goto LABEL_21;
  }
  v9 = v8 - 1;
  if ( !v9 )
  {
    v13 = 32 * v4;
    v56 = array_6836D0[v4].dword_000004;
    v14 = array_6836D0[v4].dword_000008;
    v12 = array_6836D0[v4].dword_00000C;
LABEL_26:
    v55 = v14;
    goto LABEL_27;
  }
  if ( v9 != 1 )
  {
    v54 = 0;
    v55 = 0;
    v56 = 0;
    goto LABEL_28;
  }
  if ( dword_6BE360 == 1 )
  {
    v11 = dword_6BE644 + 96 * v4;
    v56 = (*(_WORD *)(v11 + 80) + (signed int)*(_WORD *)(v11 + 82)) >> 1;
    v55 = (*(_WORD *)(v11 + 84) + (signed int)*(_WORD *)(v11 + 86)) >> 1;
    v10 = (*(_WORD *)(v11 + 88) + (signed int)*(_WORD *)(v11 + 90)) >> 1;
LABEL_24:
    v54 = v10;
  }
LABEL_28:
  v21 = v6;
  v22 = v6 & 7;
  v20 = v21 >> 3;
  if ( v22 == 2 )
  {
    v30 = 112 * v20;
    v53 = array_665230[v20].sItemPosX;
    v28 = array_665230[v20].sItemPosY;
    v26 = array_665230[v20].dword_00000C;
    goto LABEL_43;
  }
  if ( v22 == 3 )
  {
    v53 = pActors[v20].sActorPosX;
    v52 = pActors[v20].sActorPosY;
    v23 = pActors[v20].word_00008A - (unsigned int)(signed __int64)((double)pActors[v20].word_00008A * -0.75);
    goto LABEL_41;
  }
  if ( v22 == 4 )
  {
    v53 = pParty_global->sPartyPosX;
    v52 = pParty_global->sPartyPosY;
    v29 = a4;
    if ( !a4 )
      v29 = pParty_global->dword_00000C;
    v26 = pParty_global->dword_0006BC + v29;
    goto LABEL_44;
  }
  if ( v22 == 5 )
  {
    v27 = 32 * v20;
    v53 = array_6836D0[v20].dword_000004;
    v28 = array_6836D0[v20].dword_000008;
    v26 = array_6836D0[v20].dword_00000C;
LABEL_43:
    v52 = v28;
LABEL_44:
    a4 = v26;
    goto LABEL_45;
  }
  if ( v22 != 6 )
  {
    a4 = 0;
    v52 = 0;
    v53 = 0;
    goto LABEL_45;
  }
  if ( dword_6BE360 == 1 )
  {
    v24 = dword_6BE644 + 96 * v20;
    v25 = *(_WORD *)(v24 + 84);
    v53 = (*(_WORD *)(v24 + 80) + (signed int)*(_WORD *)(v24 + 82)) >> 1;
    v52 = (v25 + *(_WORD *)(v24 + 86)) >> 1;
    v23 = (*(_WORD *)(v24 + 88) + (signed int)*(_WORD *)(v24 + 90)) >> 1;
LABEL_41:
    a4 = v23;
  }
LABEL_45:
  v32 = (double)v53 - (double)v56;
  v50 = v32;
  v33 = (double)v52 - (double)v55;
  v51 = v33;
  v57 = (double)a4 - (double)v54;
  *(float *)&v53 = v33 * v33;
  *(float *)&v52 = v32 * v32;
  v31 = sqrt(v57 * v57 + *(float *)&v52 + *(float *)&v53);
  if ( v31 <= *(double *)&byte_4D8410[24] )
  {
    v43 = 65536;
    v44 = 0;
    v45 = 0;
    v46 = 1;
    X = 1;
    v48 = 0;
    v49 = 0;
  }
  else
  {
    v43 = (signed __int64)(1.0 / v31 * v50 * 65536.0);
    v44 = (signed __int64)(1.0 / v31 * v51 * 65536.0);
    v45 = (signed __int64)(1.0 / v31 * v57 * 65536.0);
    v46 = (signed __int64)v31;
    X = (signed __int64)sqrt(*(float *)&v52 + *(float *)&v53);
    v48 = sub_45281E(pClass59_global, (signed __int64)v50, (signed __int64)v51);
    v49 = sub_45281E(pClass59_global, X, (signed __int64)v57);
  }
  result = a3;
  memcpy(a3, &v43, 0x1Cu);
  return result;
}



//----- (0045976D) --------------------------------------------------------
int sub_45976D(struct Actor *_this)
{
  int result; // eax@1
  int v2; // edx@1

  v2 = *(_WORD *)(_this + 176);
  *(_BYTE *)(_this + 38) &= 0xDFu;
  result = *(_DWORD *)(_this + 36);
  switch ( v2 )
  {
    case 1:
      *(_WORD *)(_this + 178) = 1;
      return result;
    case 2:
      *(_WORD *)(_this + 178) = 2;
      goto LABEL_10;
    case 3:
    case 12:
    case 13:
    case 18:
      *(_WORD *)(_this + 178) = 3;
      goto LABEL_10;
    case 4:
    case 16:
      *(_WORD *)(_this + 178) = 5;
      goto LABEL_10;
    case 6:
    case 7:
      *(_WORD *)(_this + 178) = 1;
      goto LABEL_10;
    case 8:
      *(_WORD *)(_this + 178) = 4;
      goto LABEL_10;
    case 9:
      *(_WORD *)(_this + 178) = 7;
      goto LABEL_10;
    case 0:
    case 10:
    case 17:
      *(_WORD *)(_this + 178) = 0;
LABEL_10:
      result |= 0x200000u;
      *(_DWORD *)(_this + 36) = result;
      break;
    case 5:
      result = 60 * *(_WORD *)(_this + 200);
      //if ( *(_WORD *)(result + dword_5C6DCC + 24) <= 0 )
      if ( *(_WORD *)(result + (unsigned int)(pSpriteFrameTable->pSpriteSFrames) + 24) <= 0 )
        *(_WORD *)(_this + 176) = 11;
      else
        *(_WORD *)(_this + 178) = 6;
      break;
    default:
      return result;
  }
  return result;
}





//----- (0045959A) --------------------------------------------------------
__int16 __thiscall sub_45959A(struct Actor *_this, char a2)
{
  int v2; // edi@1
  int v3; // esi@1
  __int16 v4; // ax@2
  int v6; // eax@3
  signed int v7; // edx@4
  int v8; // ecx@4
  char Str1[120]; // [sp+Ch] [bp-88h]@2
  int v11; // [sp+84h] [bp-10h]@1
  int v12; // [sp+88h] [bp-Ch]@1
  char *Source; // [sp+8Ch] [bp-8h]@1
  int v14; // [sp+90h] [bp-4h]@1

  v2 = _this;
  v12 = 8;
  v3 = monster_list[1] + 152 * (_this->word_000060 - 1);
  //v11 = (int)((char *)&unk_5CCE98 + 88 * (*(_WORD *)(v2 + 96) - 1));
  v11 = &pMonsterStats->pMonsterInfos[1 + (*(_WORD *)(v2 + 96) - 1)];
  v14 = v2 + 188;
  Source = (char *)(v3 + 52);
  do
  {
    strcpy(Str1, Source);
    v4 = CSpriteFrameTable_fn5(pSpriteFrameTable, Str1);
    *(_WORD *)v14 = v4;
    CSpriteFrameTable_fn4(pSpriteFrameTable, v4);
    v14 += 2;
    Source += 10;
  }
  while ( v12-- != 1 );
  *(_WORD *)(v2 + 138) = *(_WORD *)v3;
  *(_WORD *)(v2 + 136) = *(_WORD *)(v3 + 2);
  LOWORD(v6) = *(_WORD *)(v11 + 76);
  *(_WORD *)(v2 + 140) = v6;
  if ( !(a2 & 1) )
  {
    v8 = v2 + 204;
    v6 = v3 + 12;
    v7 = 4;
    do
    {
      *(_WORD *)v8 = *(_WORD *)v6;
      v6 += 2;
      v8 += 2;
      --v7;
    }
    while ( v7 );
  }
  return v6;
}


//----- (0040104C) --------------------------------------------------------
signed int Actor_sub_40104C(struct Actor *pActor1, struct Actor *pActor2)
{
  int v2; // esi@1
  int v3; // ebp@5
  int v4; // edi@11
  int v5; // edx@15
  int v6; // eax@16
  int v7; // ebp@19
  int v8; // eax@22
  int v9; // edx@25
  int v10; // edx@33

  v2 = pActor2;
  if (pActor1)
  {
    if ( *(_DWORD *)((char *)pActor1 + 360) >= 0 && (*(_DWORD *)((char *)pActor1 + 360) > 0 || *(_DWORD *)((char *)pActor1 + 356) > 0))
      return 4;
    v3 = pActor1->word_000060;
  }
  else
    v3 = 0;
 
  if (pActor2)
  {
    if ( *(_DWORD *)((char *)pActor2 + 360) >= 0 && (*(_DWORD *)((char *)pActor2 + 360) > 0 || *(_DWORD *)((char *)pActor2 + 356) > 0))
      return 4;
    v4 = pActor2->word_000060;
  }
  else
    v4 = 0;

  if (pActor2)
  {
    if (pActor1)
    {
      v5 = *(_DWORD *)((char *)pActor2 + 708);
      if ( v5 )
      {
        v6 = *(_DWORD *)((char *)pActor1 + 708);
        if ( v6 )
        {
          if ( v5 == v6 )
            return 0;
        }
      }
    }
  }
  if ( v3 )
    v7 = (v3 - 1) / 3 + 1;
  else
    v7 = 0;
  if ( v4 )
    v8 = (v4 - 1) / 3 + 1;
  else
    v8 = 0;
  if (pActor1)
  {
    v9 = *(_DWORD *)((char *)pActor1 + 712);
    if ( v9 <= 0 )
    {
      if ( v9 != 9999 )
        goto LABEL_30;
    }
    else
    {
      if ( v9 != 9999 )
      {
        v7 = *(_DWORD *)((char *)pActor1 + 712);
        goto LABEL_30;
      }
    }
    v7 = 0;
LABEL_30:
    if ( *(_QWORD *)((char *)pActor1 + 404) > 0i64 )
      v7 = 0;
  }
  if ( !v2 )
    goto LABEL_40;
  v10 = *(_DWORD *)((char *)pActor2 + 712);
  if ( v10 <= 0 )
  {
    if ( v10 != 9999 )
      goto LABEL_38;
  }
  else
  {
    if ( v10 != 9999 )
    {
      v8 = *(_DWORD *)(v2 + 712);
      goto LABEL_38;
    }
  }
  v8 = 0;
LABEL_38:
  if ( *(_QWORD *)(v2 + 404) > 0i64 )
    v8 = 0;
LABEL_40:
  if (pActor1 && *(_QWORD *)((char *)pActor1 + 228) > 0i64 && !v8 || v2 && *(_QWORD *)(v2 + 228) > 0i64 && !v7 )
    return 0;
  if (pActor1 && *(_QWORD *)((char *)pActor1 + 404) <= 0i64 && *(_DWORD *)((char *)pActor1 + 36) & 0x80000 && !v8 )
    return 4;
  if ( v2 && pActor1 && *(_QWORD *)((char *)pActor1 + 404) <= 0i64 && *(_DWORD *)(v2 + 36) & 0x80000 )
  {
    if ( v7 )
      goto LABEL_55;
    return 4;
  }
  if ( !v7 )
  {
    if ( (!v2 || *(_QWORD *)(v2 + 404) > 0i64 || !(*(_DWORD *)(v2 + 36) & 0x80000)) && !pClass48->array_000000[v8][0] )
    {
LABEL_56:
      if ( v8 < 89 )
        return pClass48->array_000000[v7][v8];
      return 0;
    }
    return 4;
  }
LABEL_55:
  if ( v7 < 89 )
    goto LABEL_56;
  return 0;
}