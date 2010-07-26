#include "Actor.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "FrameTables.h"

#include "data.h"


//----- (0040894B) --------------------------------------------------------
bool Actor_sub_40894B(struct Actor *_this)
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
  int i;

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

      if ( Actor_sub_40894B(pActor) || pActor->word_0000B0 == 19 )
      {
        pActor->sActorPosX = pActor->word_0000A2;
        pActor->sActorPosY = pActor->word_0000A4;
        pActor->sActorPosZ = pActor->word_0000A6;
        pActor->word_000028 = pActor->word_00006C;
        if (pActor->word_0000B0 != 19)
          Actor_sub_403EB6(i, dword_4F6E08[i], pActor->dword_00007C, 0);
      }

      pActor->byte_00002A[19] = 0;

      LOBYTE(v1) = 0;
      if ( !v8 || v7 )
      {
        if ( !v6 || v5 )
        {
          LOBYTE(v1) = sub_438B9B(pActor);
          if ( (_BYTE)v1 )
           pActor->dword_000024 &= 0xFFF7FFFF;
        }
      }
      pActor->dword_000024 &= 0xFF7FFFFF;
      if (pActor->dword_000024 & 0x400000 )
        LOBYTE(v1) = sub_4031C1(i, pParty_global->uCurrentHour, 1);
  }
  return v1;
}


//----- (00403EB6) --------------------------------------------------------
void Actor_sub_403EB6(unsigned int uActorID, signed int a2, int a3, struct Actor_struct1 *pStruc1)
{
  struct Actor_struct1 v9;  // [sp+Ch] [bp-38h]@2
  struct Actor_struct1 v10; // [sp+28h] [bp-1Ch]@2
  struct Actor *pActor;

  pActor = &pActors[uActorID];
  if ( !pStruc1 )
  {
    struct Actor_struct1* p = Actor_sub_4040E9(8 * uActorID | 3, a2, &v9, 0);
    memcpy(&v10, p, sizeof(struct Actor_struct1));    
    pStruc1 = &v10;
  }
    
  pActor->word_00009A = LOWORD(pStruc1->dword_000014);

  if ( a3 == 0 )
    pActor->word_0000A0 = rand() % 256 + 256;
  else
    pActor->word_0000A0 = a3;

  pActor->word_0000B0 = 0;
  pActor->word_000094 = 0;
  pActor->word_000096 = 0;
  pActor->word_000098 = 0;
  pActor->dword_0000B8 = 0;
    
  Actor_sub_45976D(pActor);
}


//----- (004040E9) --------------------------------------------------------
void *__fastcall Actor_sub_4040E9(signed int a1, signed int a2, struct Actor_struct1 *pStruc1, signed int a4)
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
  int v35; // [sp-18h] [bp-64h]@17
  int v36; // [sp-14h] [bp-60h]@17
  int v37; // [sp-10h] [bp-5Ch]@17
  int v38; // [sp-Ch] [bp-58h]@17
  int v39; // [sp-8h] [bp-54h]@15
  int v40; // [sp-4h] [bp-50h]@15
  int v41; // [sp+0h] [bp-4Ch]@15
  int v42; // [sp+4h] [bp-48h]@15
  
  struct Actor_struct1 struc1; //TODO: rename

  float v50; // [sp+30h] [bp-1Ch]@23
  float v51; // [sp+34h] [bp-18h]@45
  int v52; // [sp+38h] [bp-14h]@33
  int v53; // [sp+3Ch] [bp-10h]@33
  int v54; // [sp+40h] [bp-Ch]@6
  int v55; // [sp+44h] [bp-8h]@6
  int v56; // [sp+48h] [bp-4h]@6
  float v57; // [sp+58h] [bp+Ch]@45

  v4 = a1 / 8;
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
    v10 = pActors[v4].sActorPosZ - (unsigned int)(signed __int64)((double)SLODWORD(v50) * -0.75);
    goto LABEL_24;
  }
  v8 = v7 - 1;
  if ( !v8 )
  {
    if ( !v4 )
    {
      v56 = pParty_global->sPartyPosX;
      v55 = pParty_global->sPartyPosY;
      v12 = pParty_global->sPartyPosZ + pParty_global->uPartyHeight / 3;
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
          v18 = pParty_global->sRotationY - pClass59_global->uNumTableEntries;
          v39 = pParty_global->sPartyPosZ + pParty_global->uPartyHeight / 3;
          goto LABEL_20;
        }
        v42 = (int)&v54;
        v41 = (int)&v55;
        v40 = (int)&v56;
        v18 = pParty_global->sRotationY - pClass59_global->uNumTableEntries;
        v39 = pParty_global->sPartyPosZ + pParty_global->uPartyHeight / 3;
      }
      else
      {
        v42 = (int)&v54;
        v41 = (int)&v55;
        v40 = (int)&v56;
        v39 = pParty_global->sPartyPosZ + pParty_global->uPartyHeight / 3;
        v18 = pClass59_global->uNumTableEntries + pParty_global->sRotationY;
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
    v39 = pParty_global->sPartyPosZ + pParty_global->uPartyHeight / 3;
    v18 = pClass59_global->uNumTableEntries + pParty_global->sRotationY;
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
    v56 = array_6836D0[v4].sPosX;
    v14 = array_6836D0[v4].sPosY;
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
  v20 = v21 / 8;
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
      v29 = pParty_global->uEyelevel;
    v26 = pParty_global->sPartyPosZ + v29;
    goto LABEL_44;
  }
  if ( v22 == 5 )
  {
    v27 = 32 * v20;
    v53 = array_6836D0[v20].sPosX;
    v28 = array_6836D0[v20].sPosY;
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
  if (v31 <= 1.0)
  {
    struc1.dword_000000 = 65536;
    struc1.dword_000004 = 0;
    struc1.dword_000008 = 0;
    struc1.dword_00000C = 1;
    struc1.X = 1;
    struc1.dword_000014 = 0;
    struc1.dword_000018 = 0;
  }
  else
  {
    struc1.dword_000000 = (signed __int64)(1.0 / v31 * v50 * 65536.0);
    struc1.dword_000004 = (signed __int64)(1.0 / v31 * v51 * 65536.0);
    struc1.dword_000008 = (signed __int64)(1.0 / v31 * v57 * 65536.0);
    struc1.dword_00000C = (signed __int64)v31;
    struc1.X = (signed __int64)sqrt(*(float *)&v52 + *(float *)&v53);
    struc1.dword_000014 = sub_45281E(pClass59_global, (signed __int64)v50, (signed __int64)v51);
    struc1.dword_000018 = sub_45281E(pClass59_global, struc1.X, (signed __int64)v57);
  }

  memcpy(pStruc1, &struc1, sizeof(struct Actor_struct1));
  return pStruc1;
}


//----- (0045976D) --------------------------------------------------------
int Actor_sub_45976D(struct Actor *_this)
{
  _this->dword_000024 &= 0xFFDFFFFF;
  switch (_this->word_0000B0)
  {
    case 1:
      _this->word_0000B2 = 1;
      break;

    case 2:
      _this->word_0000B2 = 2;
      _this->dword_000024 |= 0x200000; break;

    case 3:
    case 12:
    case 13:
    case 18:
      _this->word_0000B2 = 3;
      _this->dword_000024 |= 0x200000; break;

    case 4:
    case 16:
      _this->word_0000B2 = 5;
      _this->dword_000024 |= 0x200000; break;

    case 6:
    case 7:
      _this->word_0000B2 = 1;
      _this->dword_000024 |= 0x200000; break;

    case 8:
      _this->word_0000B2 = 4;
      _this->dword_000024 |= 0x200000; break;

    case 9:
      _this->word_0000B2 = 7;
      _this->dword_000024 |= 0x200000; break;

    case 0:
    case 10:
    case 17:
      _this->word_0000B2 = 0;
      _this->dword_000024 |= 0x200000; break;

    case 5:
      if (pSpriteFrameTable->pSpriteSFrames[_this->pSpriteIDs[6]].uSpriteIDs[0] <= 0)
        _this->word_0000B0 = 11;
      else
        _this->word_0000B2 = 6;
  }
  //probably void fucntion
 return _this->dword_000024;
}


//----- (0045959A) --------------------------------------------------------
void Actor_LinkSprites(struct Actor *_this, char a2)
{
 int i;

 struct MonsterDescription *pActorDescription;
 struct MonsterInfo        *pActorInfo;

 pActorDescription = &pMonsterDescriptionList->pDescriptions[_this->uMonsterID - 1];
 pActorInfo = &pMonsterStats->pMonsterInfos[_this->uMonsterID - 1];

 for (i = 0; i < 8; ++i)
 {
  _this->pSpriteIDs[i] = CSpriteFrameTable_FastFindSprite(pSpriteFrameTable, pActorDescription->pSpriteNames[i]);
  CSpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, _this->pSpriteIDs[i]);
 }
 
 _this->word_000088 = pActorDescription->word_000002;
 _this->word_00008A = pActorDescription->word_000000;
 _this->word_00008C = pActorInfo->uSpeed;
 if (~a2 & 1)
   for (i = 0; i < 4; ++i)
     _this->array_0000CC[i] = pActorDescription->arrray_00000C[i];
}

//----- (0040104C) --------------------------------------------------------
signed int Actor_sub_40104C(struct Actor *pActor1, struct Actor *pActor2)
{  
  int v3; // ebp@5
  int v4; // edi@11
  int v7; // ebp@19
  int v8; // eax@22
    
  if (pActor1)
  {
    //if ( *(_DWORD *)((char *)pActor1 + 360) >= 0 && (*(_DWORD *)((char *)pActor1 + 360) > 0 || *(_DWORD *)((char *)pActor1 + 356) > 0))
    if ( pActor1->array_0000D4[9].qword_000000 > 0i64)
    {
      return 4;
    }

    v3 = pActor1->uMonsterID - 1;
  }
  else
    v3 = 0;
 
  if (pActor2)
  {
    //if ( *(_DWORD *)((char *)pActor2 + 360) >= 0 && (*(_DWORD *)((char *)pActor2 + 360) > 0 || *(_DWORD *)((char *)pActor2 + 356) > 0))        
    if ( pActor2->array_0000D4[9].qword_000000 > 0i64)
    {
      return 4;
    }

    v4 = pActor2->uMonsterID - 1;
  }
  else
    v4 = 0;

  if ( pActor2 && pActor1 )
  {
    int v5 = pActor2->dword_0002C4;
    int v6 = pActor1->dword_0002C4;

    if ( (v5 > 0) && (v6 > 0) && (v5 == v6) )
    {
      return 0;        
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
    if (( pActor1->dword_0002C8 > 0 ) && ( pActor1->dword_0002C8 != 9999 ))
    {
      v7 = pActor1->dword_0002C8;
    }
    else
    {
      v7 = 0;
    }
    
    //if ( *(_QWORD *)((char *)pActor1 + 404) > 0i64 )
    if ( pActor1->array_0000D4[12].qword_000000 > 0i64 )
      v7 = 0;
  }

  if ( pActor2 )
  {    
    if (( pActor2->dword_0002C8 > 0 ) && ( pActor2->dword_0002C8 != 9999 ))   
    {
      v8 = pActor2->dword_0002C8;       
    }
    else    
    {
      v8 = 0;
    }
    
    //if ( *(_QWORD *)(v2 + 404) > 0i64 )
    if ( pActor2->array_0000D4[12].qword_000000 > 0i64 )
      v8 = 0;
  }
    
  //if (pActor1 && *(_QWORD *)((char *)pActor1 + 228) > 0i64 && !v8 || v2 && *(_QWORD *)(v2 + 228) > 0i64 && !v7 )
  if ( (pActor1 && (pActor1->array_0000D4[1].qword_000000 > 0i64) && !v8) || 
       (pActor2 && (pActor2->array_0000D4[1].qword_000000 > 0i64) && !v7) )
  {
    return 0;
  }

  //if (pActor1 && *(_QWORD *)((char *)pActor1 + 404) <= 0i64 && *(_DWORD *)((char *)pActor1 + 36) & 0x80000 && !v8 )
  if ( pActor1 && (pActor1->array_0000D4[12].qword_000000 <= 0i64) && 
       (pActor1->dword_000024 & 0x80000) && !v8 )
  {
    return 4;
  }

  //if ( v2 && pActor1 && *(_QWORD *)((char *)pActor1 + 404) <= 0i64 && *(_DWORD *)(v2 + 36) & 0x80000 )
  if ( pActor2 && pActor1 && (pActor1->array_0000D4[12].qword_000000 <= 0i64) && 
       (pActor2->dword_000024 & 0x80000))  
  {
    if ( v7 )
    {
      if (v7 < 89 && v8 < 89)
        return pClass48->array_000000[v7][v8];      
      
      return 0;
    }

    return 4;
  }

  if ( !v7 )
  {
    //if ( (!v2 || *(_QWORD *)(v2 + 404) > 0i64 || !(*(_DWORD *)(v2 + 36) & 0x80000)) && !pClass48->array_000000[v8][0] )
    if ( (!pActor2 || pActor2->array_0000D4[12].qword_000000 > 0i64 || !(pActor2->dword_000024 & 0x80000)) && 
          !pClass48->array_000000[v8][0] )
    {
      if ( v8 < 89 )
        return pClass48->array_000000[v7][v8];
      return 0;
    }

    return 4;
  }

  return 0;
}


//----- (00403C6C) --------------------------------------------------------
void Actor_sub_403C6C(unsigned int uActorID, int a2, struct Actor_struct1 *pStruc1)
{
  struct Actor *pActor;
  struct Actor_struct1 v18;
  struct Actor_struct1 v19;
  
  int v6; // edi@6
  int v7; // esi@6       
  int v14; // qax@13
  short v16; // ax@13  
  int v22; // [sp+4Ch] [bp-8h]@6  
    
  pActor = &pActors[uActorID];

  if ( (pActor->byte_00002A[17] == 5) && (pActor->byte_00002A[18] == 1) )
  {
    Actor_sub_403EB6(uActorID, a2, 0, pStruc1);
    return;
  }
 
  if ( (a2 & 7) == 3 )
  {      
    v7 = pActors[a2 >> 3].sActorPosX;
    v6 = pActors[a2 >> 3].sActorPosY;
    v22 = (signed __int64)((double)pActors[a2 >> 3].word_00008A * 0.75 + 
          (double)pActors[a2 >> 3].sActorPosZ);
  }
  else
  {
    if ( (a2 & 7) == 4 )
    {
      v7 = pParty_global->sPartyPosX;
      v6 = pParty_global->sPartyPosY;
      v22 = pParty_global->sPartyPosZ + pParty_global->uEyelevel;
    }
    else
    {
      v7 = (int)pStruc1;
      v6 = (int)pStruc1;
    }
  }
    
  if ( sub_407A1C(v7, v6, v22, pActor->sActorPosX, pActor->sActorPosY, 
                 (int)((double)pActor->word_00008A * 0.75 + (double)pActor->sActorPosZ)) )
  {
    if ( !pStruc1 )
    { 
      struct Actor_struct1* p = Actor_sub_4040E9(8 * uActorID | 3, a2, &v18, 0);
      memcpy(&v19, p, sizeof(struct Actor_struct1));
      pStruc1 = &v19;
    }
    
    pActor->word_00009A = LOWORD(pStruc1->dword_000014);
    
    //v15 = pSpriteFrameTable->pSpriteSFrames;
    //v16 = *(_WORD *)(60 * *(_WORD *)(v3 + 192) + v15 + 56);
    v16 = pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[2]].word_000038;

    pActor->word_0000A0 = 8 * v16;
    pActor->dword_0000B8 = 0;
    pActor->word_0000B0 = 2;

    sub_402CED(uActorID, 0);

    //???
    v14 = pMonsterStats->pMonsterInfos[pActor->uMonsterID - 1].dword_000050;
    if ( pActor->array_0000D4[7].qword_000000 > 0i64 )
    {
      v14 *= 2;   
    }

    if ( dword_ACD834 != 1 )
      v14 = (int)(flt_6BE3A8 * (double)v14 * 2.133333333333333);

    pActor->dword_00007C = v14;
    pActor->word_000098 = 0;
    pActor->word_000096 = 0;
    pActor->word_000094 = 0;
    Actor_sub_45976D(pActor);
  }
  else
  {
    Actor_sub_402AD7(uActorID, a2, rand() % 2, 64, (signed int)pStruc1);
  }
}

//----- (00402F87) --------------------------------------------------------
void Actor_sub_402F87(unsigned int uActorID, signed int a2, struct Actor_struct1* pStruc1)
{
  int v7; // eax@3
  int v9; // eax@3

  struct Actor *pActor;  
  struct Actor_struct1 v11; // [sp+Ch] [bp-5Ch]@2
  struct Actor_struct1 v12; // [sp+28h] [bp-40h]@2
    
  pActor = &pActors[uActorID];  
  if ( !pStruc1 )
  {
    struct Actor_struct1* p = Actor_sub_4040E9(8 * uActorID | 3, a2, &v11, 0);    
    memcpy(&v12, p, sizeof(struct Actor_struct1));    
    pStruc1 = &v12;
  }

  pActor->word_00009A = LOWORD(pStruc1->dword_000014);
  pActor->word_0000A0 = 8 * pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[7]].word_000038;

  v7 = sub_45281E(pClass59_global, 
                  pActor->sActorPosX - pOldCamera->dword_000000, 
                  pActor->sActorPosY - pOldCamera->dword_000004);
    
  v9 = pClass59_global->dword_001860 + pActor->word_00009A + (pClass59_global->dword_001860 >> 3) - v7;
  if ( BYTE1(v9) & 7 )
  {
    Actor_sub_403EB6(uActorID, a2, pActor->word_0000A0, pStruc1);
  }
  else
  {
    pActor->word_0000B0 = 9;
    pActor->dword_0000B8 = 0;
    pActor->word_000098 = 0;
    pActor->word_000096 = 0;
    pActor->word_000098 = 0;
    pActor->word_000094 = 0;
    
    if ( rand() % 100 < 5 )
      sub_402CED(uActorID, 3);

    Actor_sub_45976D(pActor);
  }
}


//----- (00403F58) --------------------------------------------------------
void Actor_sub_403F58(unsigned int uActorID, int a2, int a3, struct Actor_struct1* pStruc1)
{ 
  struct Actor_struct1 v10; // [sp+4h] [bp-3Ch]@4
  struct Actor_struct1 v11; // [sp+20h] [bp-20h]@4

  if ( rand() % 2 )
  {
    Actor_sub_402F87(uActorID, a2, pStruc1);
  }
  else
  {    
    struct Actor* pActor = &pActors[uActorID];    
    if ( !pStruc1 )
    {
      struct Actor_struct1* p = Actor_sub_4040E9(8 * uActorID | 3, a2, &v10, 0);      
      memcpy(&v11, p, 0x1Cu);
      pStruc1 = &v11;
    }

    pActor->word_00009A = LOWORD(pStruc1->dword_000014);
    pActor->word_00009C = LOWORD(pStruc1->dword_000018);

    if ( a3 == 0 )      
      pActor->word_0000A0 = rand() % 256 + 256;
    else
      pActor->word_0000A0 = a3;
      
    pActor->dword_0000B8 = 0;
    pActor->word_0000B0 = 0;
    pActor->word_000098 = 0;
    pActor->word_000096 = 0;
    pActor->word_000094 = 0;

    Actor_sub_45976D(pActor);
  }
}

  
//----- (00404030) --------------------------------------------------------
void Actor_sub_404030(unsigned int uActorID, signed int a2, int a3, struct Actor_struct1 *pStruc1)
{
  struct Actor_struct1 v12;
  struct Actor_struct1 v13;

  if ( rand() % 100 >= 5 )
  {
    struct Actor *pActor = &pActors[uActorID]; 
    if ( !pStruc1 )
    {
      struct Actor_struct1* p = Actor_sub_4040E9(8 * uActorID | 3, a2, &v12, 0);      
      memcpy(&v13, p, 0x1Cu);
      pStruc1 = &v13;
    }

    pActor->word_00009A = LOWORD(pStruc1->dword_000014);   
    pActor->dword_0000B8 = 0;
    pActor->word_000098 = 0;
    pActor->word_000096 = 0;
    pActor->word_000094 = 0;
    pActor->word_00009C = LOWORD(pStruc1->dword_000018);
    pActor->word_0000A0 = 256;
    pActor->word_0000B0 = 10;
    Actor_sub_45976D(pActor);
  }
  else
    Actor_sub_402F87(uActorID, a2, pStruc1);
}


//----- (00402968) --------------------------------------------------------
void Actor_sub_402968(unsigned int uActorID, int a2, int a3, struct Actor_struct1 *pStruc1)
{
  struct Actor *pActor;
  struct Actor_struct1 v10; // [sp+8h] [bp-7Ch]@4
  struct Actor_struct1 v11; // [sp+24h] [bp-60h]@3
  struct Actor_struct1 v12; // [sp+40h] [bp-44h]@3
  struct Actor_struct1 v13; // [sp+5Ch] [bp-28h]@4
  
  pActor = &pActors[uActorID];
  if ( !Actor_sub_40894B(pActor) )
  {
    return;
  }

  if ( !pStruc1 )
  {
    pStruc1 = &v12;
    memcpy(&v12, Actor_sub_4040E9(8 * uActorID | 3, a2, &v11, pActor->byte_00002A[16]), 
           sizeof(struct Actor_struct1));
  }

  memcpy(&v11, Actor_sub_4040E9(8 * uActorID | 3, 4, &v10, 0), sizeof(struct Actor_struct1));
  memcpy(&v13, &v11, sizeof(struct Actor_struct1));

  //uMonsterID ?
  if ( sub_438BDF(pActor->uMonsterID, 6) || ((a2 & 7) == 3 && (double)v13.dword_00000C < 307.2) )
  {
    if ( !a3 )
      a3 = 256;
    Actor_sub_403F58(uActorID, 4, a3, &v13);
  }
  else
  {
    if ( pActor->word_00008C )
      pActor->word_0000A0 = (pStruc1->X << 7) / (signed int)pActor->word_00008C;      
    else
      pActor->word_0000A0 = 0;
    
    if ( pActor->word_0000A0 > 256 )
      pActor->word_0000A0 = 256;

    pActor->word_00009A = pClass59_global->uNumTableEntries + LOWORD(pStruc1->dword_000014);
    pActor->word_00009A = pClass59_global->dword_00186C & (pActor->word_00009A + rand() % pClass59_global->dword_001860);

    pActor->dword_0000B8 = 0;
    pActor->word_00009C = LOWORD(pStruc1->dword_000018);
    pActor->word_0000B0 = 7;
    Actor_sub_45976D(pActor);
  }
}


//----- (00402686) --------------------------------------------------------
void Actor_sub_402686(unsigned int uActorID, signed int a2, signed int a3, struct Actor_struct1 *pStruc1)
{
  signed int v4;
  struct Actor* pActor; 

  struct Actor_struct1 v19;
  struct Actor_struct1 v20;

  v4 = 0;
  pActor = &pActors[uActorID];
  if ((pActor->byte_00002A[16] != 0 ) && (!pParty_global->dword_000704))
  {
    if (pActor->byte_00003E[7] && (dword_6BE360 == 2))
      v4 = pActor->word_000088 + 512;      
    else
      v4 = pParty_global->uPartyHeight;
  }

  if ( !pStruc1 )
  {
    memcpy(&v20, Actor_sub_4040E9(8 * uActorID | 3, a2, &v19, v4), sizeof(struct Actor_struct1));
    pStruc1 = &v20;
  }

  //??? uMonsterID
  if ( sub_438BDF(pActor->uMonsterID, 6) )
  {
    if ( !a3 )
      a3 = 256;
    Actor_sub_403F58(uActorID, 4, a3, pStruc1);
    return;
  }

  if ( (double)pStruc1->dword_00000C < 307.2 )
  {
    if ( !a3 )
      a3 = 256;

    Actor_sub_403F58(uActorID, a2, a3, pStruc1);
    return;
  }

  if ( a3 )
  {
    pActor->word_0000A0 = a3 + rand() % a3;    
  }
  else
  {    
    if ( pActor->word_00008C )
      pActor->word_0000A0 = (pStruc1->X << 7) / (signed int)pActor->word_00008C;
    else
      pActor->word_0000A0 = 0;

    if ( pActor->word_0000A0 > 128 )
      pActor->word_0000A0 = 128;
  }
  
  if ( rand() % 2 )
    pActor->word_00009A = LOWORD(pStruc1->dword_000014) + 256;
  else
    pActor->word_00009A = LOWORD(pStruc1->dword_000014) - 256;
  
  pActor->dword_0000B8 = 0;
  pActor->word_00009C = LOWORD(pStruc1->dword_000018);
  pActor->word_0000B0 = 6;
  
  if ( rand() % 100 < 2 )
    sub_402CED(uActorID, 2);

  Actor_sub_45976D(pActor);
}


//----- (0040281C) --------------------------------------------------------
void Actor_sub_40281C(unsigned int uActorID, signed int a2, signed int a3, struct Actor_struct1 *pStruc1, int a5)
{
  signed int v5;
  struct Actor* pActor;
  struct Actor_struct1 v17;
  struct Actor_struct1 v18;
    
  v5 = 0;
  pActor = &pActors[uActorID];
  if ((pActor->byte_00002A[16] != 0 ) && (!pParty_global->dword_000704))
  {
    if (pActor->byte_00003E[7] && (dword_6BE360 == 2))
      v5 = pActor->word_000088 + 512;      
    else
      v5 = pParty_global->uPartyHeight;
  }

  if ( !pStruc1 )
  {
    memcpy(&v18, Actor_sub_4040E9(8 * uActorID | 3, a2, &v17, v5), 0x1Cu);
    pStruc1 = &v18;
  }

  //??? uMonsterID
  if ( sub_438BDF(pActor->uMonsterID, 6) )
  {
    if ( !a3 )
      a3 = 256;
    Actor_sub_403F58(uActorID, 4, a3, pStruc1);
    return;
  }

  if ( pStruc1->dword_00000C < a5 )
  {
    if ( !a3 )
      a3 = 256;

    Actor_sub_403F58(uActorID, a2, a3, pStruc1);
    return;
  }

  if ( a3 )
  {
    pActor->word_0000A0 = a3;
  }
  else
  {
    if ( pActor->word_00008C )
      pActor->word_0000A0 = (pStruc1->X << 7) / (signed int)pActor->word_00008C;
    else
      pActor->word_0000A0 = 0;

    if ( pActor->word_0000A0 > 32 )
      pActor->word_0000A0 = 32;
  }

  pActor->word_00009A = LOWORD(pStruc1->dword_000014);  
  pActor->dword_0000B8 = 0;
  pActor->word_00009C = LOWORD(pStruc1->dword_000018);
  pActor->word_0000B0 = 6;

  Actor_sub_45976D(pActor);
}

//----- (00402AD7) --------------------------------------------------------
void Actor_sub_402AD7(unsigned int uActorID, signed int a2, signed int a3, int a4, signed int a5)
{
  signed int v5; // eax@1
  int v6; // ecx@1
  int v7; // ebx@1
  int v8; // edi@1
  char v9; // zf@1
  signed int v10; // esi@6
  int v12; // ecx@19
  int v13; // eax@19
  char v14; // [sp+Ch] [bp-5Ch]@7
  char v15; // [sp+28h] [bp-40h]@7
  char v16; // [sp+44h] [bp-24h]@7
  int v17; // [sp+60h] [bp-8h]@1
  int v18; // [sp+64h] [bp-4h]@1
  int v19; // [sp+70h] [bp+8h]@19

  v8 = uActorID;
  v5 = 0;
  v7 = (int)((char *)pActors + 836 * uActorID);
  v18 = a2;
  v6 = 8 * uActorID | 3;
  v9 = *(_BYTE *)(v7 + 58) == 0;
  v17 = v8;
  if ( !v9 )
  {
    if (!pParty_global->dword_000704)
    {
      if ( *(_BYTE *)(v7 + 69) )
        v5 = *(_WORD *)(v7 + 136) + 512;
      else
        v5 = pParty_global->uPartyHeight;
    }
  }
  v10 = a5;
  if ( !a5 )
  {
    memcpy(&v15, Actor_sub_4040E9(v6, a2, &v14, v5), 0x1Cu);
    memcpy(&v16, &v15, 0x1Cu);
    v8 = v17;
    v10 = (signed int)&v16;
  }
  if ( sub_438BDF(*(_WORD *)(v7 + 96), 6) )
  {
    if ( !a4 )
      a4 = 256;
    Actor_sub_403F58(v8, 4, a4, v10);
    return;
  }
  else if ( (double)*(signed int *)(v10 + 12) < *(double *)&byte_4D8410[32] )
  {
    if ( !a4 )
      a4 = 256;
    Actor_sub_403EB6(v8, v18, a4, (char *)v10);
    return;
  }
  else if ( !*(_WORD *)(v7 + 140) )
  {
   Actor_sub_403EB6(v8, v18, a4, (char *)v10);
   return;
  }
  v18 = 16;
  if ( a3 % 2 )
    v18 = -16;
  v12 = ((unsigned __int64)(class59_SinCos(pClass59_global, v18 + pClass59_global->dword_001860 + *(_DWORD *)(v10 + 20))
                          * *(_DWORD *)(v10 + 16)) >> 16)
      + pParty_global->sPartyPosX;
  v13 = pClass59_global->dword_001860 + *(_DWORD *)(v10 + 20);
  v17 = v12;
  v19 = class59_SinCos(pClass59_global, v18 + v13 - pClass59_global->uNumTableEntries);
  *(_WORD *)(v7 + 154) = sub_45281E(
                           pClass59_global,
                           v17 - *(_WORD *)(v7 + 142),
                           pParty_global->sPartyPosY + ((unsigned __int64)(v19 * *(_DWORD *)(v10 + 16)) >> 16) - *(_WORD *)(v7 + 144));
  if ( a4 )
    *(_WORD *)(v7 + 160) = a4;
  else
    *(_WORD *)(v7 + 160) = 128;
  *(_WORD *)(v7 + 156) = *(_WORD *)(v10 + 24);
  *(_WORD *)(v7 + 176) = 6;
  Actor_sub_45976D(v7);
}


//----- (00403854) --------------------------------------------------------
void Actor_sub_403854(unsigned int uActorID, signed int a2, signed int a3)
{
  int v3; // ebx@1
  int v4; // edi@3
  int v5; // esi@3
  int v6; // eax@4
  int result; // eax@7
  char *v8; // eax@8
  unsigned int v9; // esi@8
  void *v10; // esi@9
  int v11; // eax@10
  int v12; // ecx@10
  __int16 v13; // ax@10
  signed int v14; // ecx@10
  signed int v15; // ecx@17
  char v16; // [sp+Ch] [bp-48h]@9
  char v17; // [sp+28h] [bp-2Ch]@9
  int v18; // [sp+44h] [bp-10h]@6
  int v19; // [sp+48h] [bp-Ch]@1
  int v20; // [sp+4Ch] [bp-8h]@3
  int v21; // [sp+50h] [bp-4h]@1
  signed int v22; // [sp+5Ch] [bp+8h]@10

  v21 = uActorID;
  v3 = &pActors[uActorID];
  v19 = a2;
  if ( (a2 & 7) == 3 )
  {
    v6 = 836 * (a2 >> 3);
    v5 = pActors[a2 >> 3].sActorPosX;
    v4 = pActors[a2 >> 3].sActorPosY;
    v20 = (signed __int64)((double)pActors[a2 >> 3].word_00008A * *(double *)&byte_4D8410[72]
                         + (double)pActors[a2 >> 3].sActorPosZ);
  }
  else
  {
    if ( (a2 & 7) == 4 )
    {
      v5 = pParty_global->sPartyPosX;
      v4 = pParty_global->sPartyPosY;
      v20 = pParty_global->sPartyPosZ + pParty_global->uEyelevel;
    }
    else
    {
      v5 = a3;
      v4 = a3;
    }
  }
  v18 = *(_WORD *)(v3 + 138);
  if ( sub_407A1C(
         v5,
         v4,
         v20,
         *(_WORD *)(v3 + 142),
         *(_WORD *)(v3 + 144),
         *(_WORD *)(v3 + 146) - (unsigned int)(signed __int64)((double)v18 * *(double *)&byte_4D8410[64])) )
  {
    v8 = (char *)a3;
    v9 = 0;
    if ( !a3 )
    {
      v10 = Actor_sub_4040E9(8 * v21 | 3, v19, &v16, 0);
      v8 = &v17;
      memcpy(&v17, v10, 0x1Cu);
      v9 = 0;
    }

    v12 = pSpriteFrameTable->pSpriteSFrames;

    *(_WORD *)(v3 + 154) = *((_WORD *)v8 + 10);
    v13 = *(_WORD *)(60 * *(_WORD *)(v3 + 194) + v12 + 56);
    v14 = v21;
    *(_WORD *)(v3 + 160) = 8 * v13;
    *(_DWORD *)(v3 + 184) = v9;
    *(_WORD *)(v3 + 176) = 13;
    sub_402CED(v14, 0);
    v11 = pMonsterStats->pMonsterInfos[*(_WORD *)(v3 + 96)].dword_000050;
    v22 = pMonsterStats->pMonsterInfos[*(_WORD *)(v3 + 96)].dword_000050;
    if ( *(_DWORD *)(v3 + 328) >= (signed int)v9 )
    {
      if ( *(_DWORD *)(v3 + 328) > (signed int)v9 || *(_DWORD *)(v3 + 324) > v9 )
      {
        v11 *= 2;
        v22 = v11;
      }
    }
    if ( dword_ACD834 == 1 )
      *(_DWORD *)(v3 + 124) = v11;
    else
      *(_DWORD *)(v3 + 124) = *(_WORD *)(v3 + 160)
                            - (unsigned int)(signed __int64)(flt_6BE3A8 * (double)v22 * *(double *)&byte_4D8410[56]);
    v15 = *(_BYTE *)(v3 + 77);
    *(_WORD *)(v3 + 152) = v9;
    *(_WORD *)(v3 + 150) = v9;
    *(_WORD *)(v3 + 148) = v9;
    if ( sub_42FB5C(v15) )
    {
      *(_WORD *)(v3 + 160) = 64;
      *(_DWORD *)(v3 + 184) = v9;
      *(_WORD *)(v3 + 176) = 9;
      Actor_sub_45976D(v3);
      *(_WORD *)(v3 + 176) = 13;
    }
    else
    {
      Actor_sub_45976D(v3);
    }
  }
  else
  {
    Actor_sub_402AD7(v21, v19, v21, 64, a3);
  }
}


//----- (0040368B) --------------------------------------------------------
void Actor_sub_40368B(unsigned int uActorID, signed int a2, signed int a3)
{
  int v3; // ebx@1
  int v4; // edi@3
  int v5; // esi@3
  int v6; // eax@4
  int result; // eax@7
  char *v8; // eax@8
  unsigned int v9; // esi@8
  void *v10; // esi@9
  signed __int64 v11; // qax@10
  int v12; // ecx@10
  __int16 v13; // ax@10
  signed int v14; // ecx@10
  char v15; // [sp+Ch] [bp-48h]@9
  char v16; // [sp+28h] [bp-2Ch]@9
  int v17; // [sp+44h] [bp-10h]@6
  int v18; // [sp+48h] [bp-Ch]@1
  int v19; // [sp+4Ch] [bp-8h]@3
  int v20; // [sp+50h] [bp-4h]@1
  signed int v21; // [sp+5Ch] [bp+8h]@10

  v20 = uActorID;
  v3 = &pActors[uActorID];
  v18 = a2;
  if ( (a2 & 7) == 3 )
  {
    v6 = 836 * (a2 >> 3);
    v5 = pActors[a2 >> 3].sActorPosX;
    v4 = pActors[a2 >> 3].sActorPosY;
    v19 = (signed __int64)((double)pActors[a2 >> 3].word_00008A * *(double *)&byte_4D8410[72]
                         + (double)pActors[a2 >> 3].sActorPosZ);
  }
  else
  {
    if ( (a2 & 7) == 4 )
    {
      v5 = pParty_global->sPartyPosX;
      v4 = pParty_global->sPartyPosY;
      v19 = pParty_global->sPartyPosZ + pParty_global->uEyelevel;
    }
    else
    {
      v5 = a3;
      v4 = a3;
    }
  }
  v17 = *(_WORD *)(v3 + 138);
  if ( sub_407A1C(
         v5,
         v4,
         v19,
         *(_WORD *)(v3 + 142),
         *(_WORD *)(v3 + 144),
         *(_WORD *)(v3 + 146) - (unsigned int)(signed __int64)((double)v17 * *(double *)&byte_4D8410[64])) )
  {
    v8 = (char *)a3;
    v9 = 0;
    if ( !a3 )
    {
      v10 = Actor_sub_4040E9(8 * v20 | 3, v18, &v15, 0);
      v8 = &v16;
      memcpy(&v16, v10, 0x1Cu);
      v9 = 0;
    }

    v12 = pSpriteFrameTable->pSpriteSFrames;

    *(_WORD *)(v3 + 154) = *((_WORD *)v8 + 10);
    v13 = *(_WORD *)(60 * *(_WORD *)(v3 + 194) + v12 + 56);
    v14 = v20;
    *(_WORD *)(v3 + 160) = 8 * v13;
    *(_DWORD *)(v3 + 184) = v9;
    *(_WORD *)(v3 + 176) = 12;
    sub_402CED(v14, 0);
    LODWORD(v11) = pMonsterStats->pMonsterInfos[*(_WORD *)(v3 + 96)].dword_000050;
    v21 = pMonsterStats->pMonsterInfos[*(_WORD *)(v3 + 96)].dword_000050;
    if ( *(_DWORD *)(v3 + 328) >= (signed int)v9 )
    {
      if ( *(_DWORD *)(v3 + 328) > (signed int)v9 || *(_DWORD *)(v3 + 324) > v9 )
      {
        LODWORD(v11) = 2 * v11;
        v21 = v11;
      }
    }
    if ( dword_ACD834 != 1 )
      v11 = (signed __int64)(flt_6BE3A8 * (double)v21 * *(double *)&byte_4D8410[40]);
    *(_DWORD *)(v3 + 124) = v11;
    *(_WORD *)(v3 + 152) = v9;
    *(_WORD *)(v3 + 150) = v9;
    *(_WORD *)(v3 + 148) = v9;
    Actor_sub_45976D(v3);
  }
  else
  {
    Actor_sub_402AD7(v20, v18, v20, 64, a3);
  }
}

//----- (00403476) --------------------------------------------------------
void Actor_sub_403476(unsigned int uActorID, signed int a2, signed int a3)
{
  int v3; // ebx@1
  int v4; // edi@3
  int v5; // esi@3
  int v6; // eax@4
  int result; // eax@8
  char *v8; // eax@9
  unsigned int v9; // esi@9
  void *v10; // esi@10
  int v11; // eax@11
  int v12; // ecx@11
  __int16 v13; // ax@11
  signed int v14; // ecx@11
  char v15; // [sp+Ch] [bp-48h]@10
  char v16; // [sp+28h] [bp-2Ch]@10
  int v17; // [sp+44h] [bp-10h]@6
  int v18; // [sp+48h] [bp-Ch]@1
  int v19; // [sp+4Ch] [bp-8h]@1
  int v20; // [sp+50h] [bp-4h]@3
  signed int v21; // [sp+5Ch] [bp+8h]@11

  v19 = uActorID;
  v3 = (int)((char *)pActors + 836 * uActorID);
  v18 = a2;
  if ( (a2 & 7) == 3 )
  {
    v6 = 836 * (a2 >> 3);
    v5 = pActors[a2 >> 3].sActorPosX;
    v4 = pActors[a2 >> 3].sActorPosY;
    v20 = (signed __int64)((double)pActors[a2 >> 3].word_00008A * *(double *)&byte_4D8410[72]
                         + (double)pActors[a2 >> 3].sActorPosZ);
  }
  else
  {
    if ( (a2 & 7) == 4 )
    {
      v5 = pParty_global->sPartyPosX;
      v4 = pParty_global->sPartyPosY;
      v20 = pParty_global->sPartyPosZ + pParty_global->uEyelevel;
    }
    else
    {
      v5 = a3;
      v4 = a3;
    }
  }
  v17 = *(_WORD *)(v3 + 138);
  if ( sub_407A1C(
         v5,
         v4,
         v20,
         *(_WORD *)(v3 + 142),
         *(_WORD *)(v3 + 144),
         *(_WORD *)(v3 + 146) - (unsigned int)(signed __int64)((double)v17 * *(double *)&byte_4D8410[64]))
    || (v17 = *(_WORD *)(v3 + 138),
        sub_407A1C(
          *(_WORD *)(v3 + 142),
          *(_WORD *)(v3 + 144),
          *(_WORD *)(v3 + 146) - (unsigned int)(signed __int64)((double)v17 * *(double *)&byte_4D8410[64]),
          v5,
          v4,
          v20)) )
  {
    v8 = (char *)a3;
    v9 = 0;
    if ( !a3 )
    {
      v10 = Actor_sub_4040E9(8 * v19 | 3, v18, &v15, 0);
      v8 = &v16;
      memcpy(&v16, v10, 0x1Cu);
      v9 = 0;
    }

    v12 = pSpriteFrameTable->pSpriteSFrames;

    *(_WORD *)(v3 + 154) = *((_WORD *)v8 + 10);
    v13 = *(_WORD *)(60 * *(_WORD *)(v3 + 194) + v12 + 56);
    v14 = v19;
    *(_WORD *)(v3 + 160) = 8 * v13;
    *(_DWORD *)(v3 + 184) = v9;
    *(_WORD *)(v3 + 176) = 3;
    sub_402CED(v14, 0);
    v11 = pMonsterStats->pMonsterInfos[*(_WORD *)(v3 + 96)].dword_000050;
    v21 = pMonsterStats->pMonsterInfos[*(_WORD *)(v3 + 96)].dword_000050;
    if ( *(_DWORD *)(v3 + 328) >= (signed int)v9 )
    {
      if ( *(_DWORD *)(v3 + 328) > (signed int)v9 || *(_DWORD *)(v3 + 324) > v9 )
      {
        v11 *= 2;
        v21 = v11;
      }
    }
    if ( dword_ACD834 == 1 )
      *(_DWORD *)(v3 + 124) = v11;
    else
      *(_DWORD *)(v3 + 124) = *(_WORD *)(v3 + 160)
                            - (unsigned int)(signed __int64)(flt_6BE3A8 * (double)v21 * *(double *)&byte_4D8410[56]);
    *(_WORD *)(v3 + 152) = v9;
    *(_WORD *)(v3 + 150) = v9;
    *(_WORD *)(v3 + 148) = v9;
    Actor_sub_45976D(v3);
  }
  else
    Actor_sub_402AD7(v19, v18, v19, 64, a3);
}



//----- (00403A60) --------------------------------------------------------
void Actor_sub_403A60(unsigned int uActorID, signed int a2, signed int a3)
{
  int v3; // ebx@1
  int v4; // edi@3
  int v5; // esi@3
  int v6; // eax@4
  int result; // eax@7
  char *v8; // eax@8
  unsigned int v9; // esi@8
  void *v10; // esi@9
  int v11; // eax@10
  int v12; // ecx@10
  __int16 v13; // ax@10
  signed int v14; // ecx@10
  signed int v15; // ecx@17
  char v16; // [sp+Ch] [bp-48h]@9
  char v17; // [sp+28h] [bp-2Ch]@9
  int v18; // [sp+44h] [bp-10h]@6
  int v19; // [sp+48h] [bp-Ch]@1
  int v20; // [sp+4Ch] [bp-8h]@3
  int v21; // [sp+50h] [bp-4h]@1
  signed int v22; // [sp+5Ch] [bp+8h]@10

  v21 = uActorID;
  v3 = &pActors[uActorID];
  v19 = a2;
  if ( (a2 & 7) == 3 )
  {
    v6 = 836 * (a2 >> 3);
    v5 = pActors[a2 >> 3].sActorPosX;
    v4 = pActors[a2 >> 3].sActorPosY;
    v20 = (signed __int64)((double)pActors[a2 >> 3].word_00008A * *(double *)&byte_4D8410[72]
                         + (double)pActors[a2 >> 3].sActorPosZ);
  }
  else
  {
    if ( (a2 & 7) == 4 )
    {
      v5 = pParty_global->sPartyPosX;
      v4 = pParty_global->sPartyPosY;
      v20 = pParty_global->sPartyPosZ + pParty_global->uEyelevel;
    }
    else
    {
      v5 = a3;
      v4 = a3;
    }
  }
  v18 = *(_WORD *)(v3 + 138);
  if ( sub_407A1C(
         v5,
         v4,
         v20,
         *(_WORD *)(v3 + 142),
         *(_WORD *)(v3 + 144),
         *(_WORD *)(v3 + 146) - (unsigned int)(signed __int64)((double)v18 * *(double *)&byte_4D8410[64])) )
  {
    v8 = (char *)a3;
    v9 = 0;
    if ( !a3 )
    {
      v10 = Actor_sub_4040E9(8 * v21 | 3, v19, &v16, 0);
      v8 = &v17;
      memcpy(&v17, v10, 0x1Cu);
      v9 = 0;
    }

    v12 = pSpriteFrameTable->pSpriteSFrames;

    *(_WORD *)(v3 + 154) = *((_WORD *)v8 + 10);
    v13 = *(_WORD *)(60 * *(_WORD *)(v3 + 194) + v12 + 56);
    v14 = v21;
    *(_WORD *)(v3 + 160) = 8 * v13;
    *(_DWORD *)(v3 + 184) = v9;
    *(_WORD *)(v3 + 176) = 18;
    sub_402CED(v14, 0);
    v11 = pMonsterStats->pMonsterInfos[*(_WORD *)(v3 + 96)].dword_000050;
    v22 = pMonsterStats->pMonsterInfos[*(_WORD *)(v3 + 96)].dword_000050;
    if ( *(_DWORD *)(v3 + 328) >= (signed int)v9 )
    {
      if ( *(_DWORD *)(v3 + 328) > (signed int)v9 || *(_DWORD *)(v3 + 324) > v9 )
      {
        v11 *= 2;
        v22 = v11;
      }
    }
    if ( dword_ACD834 == 1 )
      *(_DWORD *)(v3 + 124) = v11;
    else
      *(_DWORD *)(v3 + 124) = *(_WORD *)(v3 + 160)
                            - (unsigned int)(signed __int64)(flt_6BE3A8 * (double)v22 * *(double *)&byte_4D8410[56]);
    v15 = *(_BYTE *)(v3 + 79);
    *(_WORD *)(v3 + 152) = v9;
    *(_WORD *)(v3 + 150) = v9;
    *(_WORD *)(v3 + 148) = v9;
    if ( sub_42FB5C(v15) )
    {
      *(_WORD *)(v3 + 160) = 64;
      *(_DWORD *)(v3 + 184) = v9;
      *(_WORD *)(v3 + 176) = 9;
      Actor_sub_45976D(v3);
      *(_WORD *)(v3 + 176) = 18;
    }
    else
    {
      Actor_sub_45976D(v3);
    }
  }
  else
    Actor_sub_402AD7(v21, v19, v21, 64, a3);
}


//----- (004032B2) --------------------------------------------------------
void Actor_sub_4032B2(unsigned int uActorID, int a2, int a3, int a4)
{
  int v4; // eax@1
  int v5; // ebx@1
  int v6; // edi@1
  int v7; // esi@1
  int v8; // ST08_4@1
  int v10; // ebx@11
  int v11; // ebx@13
  signed __int16 v12; // cx@17
  int v13; // [sp-8h] [bp-44h]@10
  char *v14; // [sp-4h] [bp-40h]@10
  char v15; // [sp+Ch] [bp-30h]@7
  int v16; // [sp+28h] [bp-14h]@11
  int v17; // [sp+2Ch] [bp-10h]@1
  int X; // [sp+30h] [bp-Ch]@1
  int v19; // [sp+34h] [bp-8h]@1
  int v20; // [sp+38h] [bp-4h]@1

  v19 = uActorID;
  v6 = 836 * uActorID;
  v7 = (int)((char *)pActors + 836 * uActorID);
  v17 = a2;
  v5 = *(_WORD *)(v7 + 162) - *(_WORD *)(v7 + 142);
  v8 = *(_WORD *)(v7 + 162) - *(_WORD *)(v7 + 142);
  X = *(_WORD *)(v7 + 164) - *(_WORD *)(v7 + 144);
  v20 = abs(v8);
  v4 = abs(X);
  if ( v20 <= v4 )
    v20 = v4 + (v20 >> 1);
  else
    v20 += v4 >> 1;
  if ( sub_438BDF(*(_WORD *)(v7 + 96), 6) )
  {
    if ( !a4 )
      a4 = 256;
    return Actor_sub_403F58(v19, 4, a4, (signed int)&v15);
  }
  if ( byte_5FF193[v6] == 3 && v20 < 128 )
  {
    v14 = &v15;
    v13 = 256;
    return Actor_sub_403EB6(v19, v17, v13, v14);
  }
  v16 = (rand() & 0xF) << 12;
  v20 += (unsigned __int64)(v16 * a3) >> 16;
  v10 = (pClass59_global->dword_001868 - 1) & sub_45281E(pClass59_global, v5, X);
  if ( rand() % 100 < 25 )
  {
   sub_403E61(v19);
   return;
  }
  v11 = v10 + rand() % 256 - 128;
  if ( abs(v11 - *(_WORD *)(v7 + 154)) > 256 && !(*(_BYTE *)(v7 + 38) & 0x20) )
  {
    v14 = &v15;
    v13 = 256;
    Actor_sub_403EB6(v19, v17, v13, v14);
    return;
  }
  v12 = *(_WORD *)(v7 + 140);
  *(_WORD *)(v7 + 154) = v11;
  if ( v12 )
    *(_WORD *)(v7 + 160) = 32 * v20 / v12;
  else
    *(_WORD *)(v7 + 160) = 0;
  *(_DWORD *)(v7 + 184) = 0;
  *(_WORD *)(v7 + 176) = 1;
  if ( rand() % 100 < 2 )
    sub_402CED(v19, 3);
  Actor_sub_45976D(v7);
}

//----- (0041F4C1) --------------------------------------------------------
void Actor_TotalReset(struct Actor *_this)
{
 int i;

 for (i = 0; i < 22; ++i)
 {
  _this->array_0000D4[i].qword_000000 = 0i64;  
  _this->array_0000D4[i].word_000008 = 0;
  _this->array_0000D4[i].word_00000A = 0;
  _this->array_0000D4[i].byte_00000E = 0;
  _this->array_0000D4[i].byte_00000F = 0;
 }

 for (i = 0; i < 4; ++i)
   ItemGen_Reset(&_this->array_000234[i]);

 Actor_Reset(_this);
}


//----- (00459671) --------------------------------------------------------
void Actor_Reset(struct Actor *_this)
{
 _this->pActorName[0] = 0;

 _this->word_000020 = 0;
 _this->dword_000024 = 0;
 
 _this->word_000086 = 0;
 _this->word_000088 = 32;
 _this->word_00008A = 128;
 _this->word_00008C = 200;

 _this->sActorPosX = 0;
 _this->sActorPosY = 0;
 _this->sActorPosZ = 0;
 
 _this->word_000094 = 0;
 _this->word_000096 = 0;
 _this->word_000098 = 0;
 _this->word_00009A = 0;
 _this->word_00009C = 0;
 _this->word_00009E = 0;



 _this->word_0000A2 = 0;
 _this->word_0000A4 = 0;
 _this->word_0000A6 = 0;
 _this->word_0000A8 = 0;
 _this->word_0000AA = 0;
 _this->word_0000AC = 0;
 _this->word_0000AE = 256;
 _this->word_0000B0 = 0;
 _this->word_0000B2 = 0;
 _this->word_0000B4 = 0;
 _this->dword_0000B8 = 0;

 memset(_this->pSpriteIDs, 0, 8 * sizeof(unsigned short));

 _this->dword_0002C4 = 0;
 _this->dword_0002C8 = 0;

 _this->dword_00032C = 0;
 _this->dword_000330 = 0;
 _this->dword_000334 = 0;

 memset(_this->array_0000D4, 0, 22 * sizeof(struct Actor_struct0));
}