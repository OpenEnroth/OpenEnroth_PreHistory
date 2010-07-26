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

  if (_this->array_0000D4[5].qword_000000 > 0i64 || _this->array_0000D4[6].qword_000000 > 0i64 )  
    v1 = true;

  v3 = _this->word_0000B0;
  return !(v1 || v3 == 4 || v3 == 5 || v3 == 11 || v3 == 17 || v3 == 19);
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
    v10 = pActors[v4].sActorPosZ - (unsigned int)((double)SLODWORD(v50) * -0.75);
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
      //WTF? something illogical happens here
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
    
    //v15 = pSpriteFrameTable->pSpriteSFrames;
    //v16 = *(_WORD *)(60 * *(_WORD *)(v3 + 192) + v15 + 56);
    v16 = pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[2]].word_000038;

    pActor->word_00009A = LOWORD(pStruc1->dword_000014);
    pActor->word_0000A0 = 8 * v16;
    pActor->dword_0000B8 = 0;
    pActor->word_0000B0 = 2;

    sub_402CED(uActorID, 0);

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
    Actor_sub_402AD7(uActorID, a2, rand() % 2, 64, pStruc1);
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
  {
    Actor_sub_402F87(uActorID, a2, pStruc1);
  }
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

  //uMonsterID - 1 ?
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

  //uMonsterID - 1 ?
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
    memcpy(&v18, Actor_sub_4040E9(8 * uActorID | 3, a2, &v17, v5), sizeof(struct Actor_struct1));
    pStruc1 = &v18;
  }

  //uMonsterID - 1 ?
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
void Actor_sub_402AD7(unsigned int uActorID, signed int a2, signed int a3, int a4, struct Actor_struct1 *pStruc1)
{
  struct Actor *pActor;
  int v5;
  struct Actor_struct1 v14;
  struct Actor_struct1 v15;

  pActor = &pActors[uActorID];
  v5 = 0;

  if ((pActor->byte_00002A[16] != 0 ) && (!pParty_global->dword_000704))
  {
    if (pActor->byte_00003E[7])
      v5 = pActor->word_000088 + 512;
    else
      v5 = pParty_global->uPartyHeight;
  }

  if ( !pStruc1 )
  {
    memcpy(&v15, Actor_sub_4040E9(8 * uActorID | 3, a2, &v14, v5), sizeof(struct Actor_struct1));       
    pStruc1 = &v15;
  }

  //uMonsterID - 1?
  if ( sub_438BDF(pActor->uMonsterID, 6) )  
  {
    if ( !a4 )
      a4 = 256;

    Actor_sub_403F58(uActorID, 4, a4, pStruc1);
    return;
  }
  else if ( (double)pStruc1->dword_00000C < 307.2 )
  {
    if ( !a4 )
      a4 = 256;

    Actor_sub_403EB6(uActorID, a2, a4, pStruc1);
    return;
  }
  else if ( !pActor->word_00008C)
  {
    Actor_sub_403EB6(uActorID, a2, a4, pStruc1);
    return;
  }

  {
    int v18 = ( a3 % 2 ) ? -16 : 16;

    int tmp = class59_SinCos(pClass59_global, v18 + pClass59_global->dword_001860 + pStruc1->dword_000014);
    int v12 = ((unsigned __int64)(tmp * pStruc1->X) >> 16) + pParty_global->sPartyPosX;
  
    tmp = pClass59_global->dword_001860 + pStruc1->dword_000014;
    tmp = class59_SinCos(pClass59_global, v18 + tmp - pClass59_global->uNumTableEntries);
    tmp = pParty_global->sPartyPosY + 
          ((unsigned __int64)(tmp * pStruc1->X) >> 16) - //why X? mm7 programmer's bug?     
          pActor->sActorPosY;       
    
    pActor->word_00009A = sub_45281E(pClass59_global, v12 - pActor->sActorPosX, tmp);
  }

  if ( a4 )
    pActor->word_0000A0 = a4;    
  else
    pActor->word_0000A0 = 128;

  pActor->word_00009C = LOWORD(pStruc1->dword_000018);
  pActor->word_0000B0 = 6;
  Actor_sub_45976D(pActor);
}

//----- (00403854) --------------------------------------------------------
void Actor_sub_403854(unsigned int uActorID, signed int a2, struct Actor_struct1 *pStruc1)
{
  struct Actor *pActor;
  int v4;
  int v5;
  int v11;
  short v13;
  struct Actor_struct1 v16;
  struct Actor_struct1 v17;
  int v20;

  pActor = &pActors[uActorID];
  if ( (a2 & 7) == 3 )
  {
    v5 = pActors[a2 >> 3].sActorPosX;
    v4 = pActors[a2 >> 3].sActorPosY;
    v20 = (signed __int64)((double)pActors[a2 >> 3].word_00008A * 0.75
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
      //WTF? something illogical happens here
      v5 = (int)pStruc1;
      v4 = (int)pStruc1;
    }
  }

  if ( sub_407A1C(v5, v4, v20, pActor->sActorPosX, pActor->sActorPosY,
                  pActor->sActorPosZ - (int)((double)pActor->word_00008A * -0.75)) )
  {
    if ( !pStruc1 )
    { 
      struct Actor_struct1* p = Actor_sub_4040E9(8 * uActorID | 3, a2, &v16, 0);
      memcpy(&v17, p, sizeof(struct Actor_struct1));
      pStruc1 = &v17;      
    }

    //v12 = pSpriteFrameTable->pSpriteSFrames;
    //v13 = *(_WORD *)(60 * *(_WORD *)(pActor + 194) + v12 + 56);
    v13 = pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[3]].word_000038;

    pActor->word_00009A = LOWORD(pStruc1->dword_000014);        
    pActor->word_0000A0 = 8 * v13;
    pActor->dword_0000B8 = 0;
    pActor->word_0000B0 = 13;

    sub_402CED(uActorID, 0);

    v11 = pMonsterStats->pMonsterInfos[pActor->uMonsterID - 1].dword_000050;    
    if ( pActor->array_0000D4[7].qword_000000 > 0i64 )
    {
      v11 *= 2;    
    }
    
    if ( dword_ACD834 == 1 )
      pActor->dword_00007C = v11;
    else
      pActor->dword_00007C = pActor->word_0000A0 - 
                             (int)(flt_6BE3A8 * (double)v11 * -2.133333333333333);        
    pActor->word_000098 = 0;
    pActor->word_000096 = 0;
    pActor->word_000094 = 0;
    if ( sub_42FB5C(pActor->byte_00003E[15]) )
    {
      pActor->word_0000A0 = 64;
      pActor->dword_0000B8 = 0;
      pActor->word_0000B0 = 9;
      Actor_sub_45976D(pActor);
      pActor->word_0000B0 = 13;
    }
    else
    {
      Actor_sub_45976D(pActor);
    }
  }
  else
  {
    Actor_sub_402AD7(uActorID, a2, uActorID, 64, pStruc1);
  }
}


//----- (0040368B) --------------------------------------------------------
void Actor_sub_40368B(unsigned int uActorID, signed int a2, struct Actor_struct1 *pStruc1)
{
  struct Actor *pActor;  
  int v4;
  int v5;
  int v11;
  short v13;
  struct Actor_struct1 v15;
  struct Actor_struct1 v16;
  int v19;
    
  pActor = &pActors[uActorID];  
  if ( (a2 & 7) == 3 )
  {    
    v5 = pActors[a2 >> 3].sActorPosX;
    v4 = pActors[a2 >> 3].sActorPosY;
    v19 = (signed __int64)((double)pActors[a2 >> 3].word_00008A * 0.75
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
      //WTF? something illogical happens here
      v5 = (int)pStruc1;
      v4 = (int)pStruc1;
    }
  }

  if ( sub_407A1C(v5, v4, v19, pActor->sActorPosX, pActor->sActorPosY,
                  pActor->sActorPosZ - (int)((double)pActor->word_00008A * -0.75)) )
  {
    if ( !pStruc1 )
    {
      struct Actor_struct1* p = Actor_sub_4040E9(8 * uActorID | 3, a2, &v15, 0);      
      memcpy(&v16, p, sizeof(struct Actor_struct1));
      pStruc1 = &v16;      
    }

    //v12 = pSpriteFrameTable->pSpriteSFrames;
    //v13 = *(_WORD *)(60 * *(_WORD *)(pActor + 194) + v12 + 56);
    v13 = pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[3]].word_000038;

    pActor->word_00009A = LOWORD(pStruc1->dword_000014);    
    pActor->word_0000A0 = 8 * v13;
    pActor->dword_0000B8 = 0;
    pActor->word_0000B0 = 12;

    sub_402CED(uActorID, 0);

    v11 = pMonsterStats->pMonsterInfos[pActor->uMonsterID - 1].dword_000050;    
    if ( pActor->array_0000D4[7].qword_000000 > 0i64 )
    {
      v11 *= 2;
    }

    if ( dword_ACD834 != 1 )
      pActor->dword_00007C = (int)(flt_6BE3A8 * (double)v11 * 2.133333333333333);
        
    pActor->word_000098 = 0;
    pActor->word_000096 = 0;
    pActor->word_000094 = 0;
    Actor_sub_45976D(pActor);
  }
  else
  {
    Actor_sub_402AD7(uActorID, a2, uActorID, 64, pStruc1);
  }
}

//----- (00403476) --------------------------------------------------------
void Actor_sub_403476(unsigned int uActorID, signed int a2, struct Actor_struct1 *pStruc1)
{
  struct Actor *pActor; 
  int v4;
  int v5;
  int v11;
  short v13;
  struct Actor_struct1 v15;
  struct Actor_struct1 v16;  
  int v20;

  pActor = &pActors[uActorID];  
  if ( (a2 & 7) == 3 )
  {
    v5 = pActors[a2 >> 3].sActorPosX;
    v4 = pActors[a2 >> 3].sActorPosY;
    v20 = (signed __int64)((double)pActors[a2 >> 3].word_00008A * 0.75
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
      //WTF? something illogical happens here
      v5 = (int)pStruc1;
      v4 = (int)pStruc1;
    }
  }

  if ( sub_407A1C(v5, v4, v20, pActor->sActorPosX, pActor->sActorPosY, 
                 pActor->sActorPosZ - (int)((double)pActor->word_00008A * -0.75)) 
       ||
       sub_407A1C(pActor->sActorPosX, pActor->sActorPosY, 
                  pActor->sActorPosZ - (int)((double)pActor->word_00008A * -0.75),
                  v5, v4, v20) )
  {
    if ( !pStruc1 )
    {
      struct Actor_struct1* p = Actor_sub_4040E9(8 * uActorID | 3, a2, &v15, 0);
      memcpy(&v16, p, sizeof(struct Actor_struct1));
      pStruc1 = &v16;      
    }

    //v12 = pSpriteFrameTable->pSpriteSFrames;
    //v13 = *(_WORD *)(60 * *(_WORD *)(pActor + 194) + v12 + 56);
    v13 = pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[3]].word_000038;

    pActor->word_00009A = LOWORD(pStruc1->dword_000014);
    pActor->word_0000A0 = 8 * v13;
    pActor->dword_0000B8 = 0;
    pActor->word_0000B0 = 3;

    sub_402CED(uActorID, 0);

    v11 = pMonsterStats->pMonsterInfos[pActor->uMonsterID - 1].dword_000050;    
    if ( pActor->array_0000D4[7].qword_000000 > 0i64 )
    {
      v11 *= 2;    
    }

    if ( dword_ACD834 == 1 )
      pActor->dword_00007C = v11;
    else
      pActor->dword_00007C = pActor->word_0000A0 - 
                             (int)(flt_6BE3A8 * (double)v11 * -2.133333333333333);
    pActor->word_000098 = 0;
    pActor->word_000096 = 0;
    pActor->word_000094 = 0;
    Actor_sub_45976D(pActor);
  }
  else
    Actor_sub_402AD7(uActorID, a2, uActorID, 64, pStruc1);
}

//----- (00403A60) --------------------------------------------------------
void Actor_sub_403A60(unsigned int uActorID, signed int a2, struct Actor_struct1 *pStruc1)
{
  struct Actor *pActor; 
  int v4;
  int v5;
  int v11;
  short v13;
  struct Actor_struct1 v16;
  struct Actor_struct1 v17;
  int v20;

  pActor = &pActors[uActorID];
  if ( (a2 & 7) == 3 )
  {
    v5 = pActors[a2 >> 3].sActorPosX;
    v4 = pActors[a2 >> 3].sActorPosY;
    v20 = (signed __int64)((double)pActors[a2 >> 3].word_00008A * 0.75
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
      //WTF? something illogical happens here
      v5 = (int)pStruc1;
      v4 = (int)pStruc1;
    }
  }

  if ( sub_407A1C(v5, v4, v20, pActor->sActorPosX, pActor->sActorPosY, 
                  pActor->sActorPosZ - (int)((double)pActor->word_00008A * -0.75)) )
  {
    if ( !pStruc1 )
    {
      struct Actor_struct1* p = Actor_sub_4040E9(8 * uActorID | 3, a2, &v16, 0);      
      memcpy(&v17, p, sizeof(struct Actor_struct1));
      pStruc1 = &v17;
    }

    //v12 = pSpriteFrameTable->pSpriteSFrames;
    //v13 = *(_WORD *)(60 * *(_WORD *)(pActor + 194) + v12 + 56);
    v13 = pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[3]].word_000038;

    pActor->word_00009A = LOWORD(pStruc1->dword_000014);
    pActor->word_0000A0 = 8 * v13;
    pActor->dword_0000B8 = 0;
    pActor->word_0000B0 = 18;

    sub_402CED(uActorID, 0);

    v11 = pMonsterStats->pMonsterInfos[pActor->uMonsterID - 1].dword_000050;    
    if ( pActor->array_0000D4[7].qword_000000 > 0i64 )
    {
      v11 *= 2;    
    }

    if ( dword_ACD834 == 1 )
      pActor->dword_00007C = v11;
    else
      pActor->dword_00007C = pActor->word_0000A0 - 
                             (int)(flt_6BE3A8 * (double)v11 * -2.133333333333333);
    pActor->word_000098 = 0;
    pActor->word_000096 = 0;
    pActor->word_000094 = 0;
    if ( sub_42FB5C(pActor->byte_00003E[17]) )
    {
      pActor->word_0000A0 = 64;
      pActor->dword_0000B8 = 0;
      pActor->word_0000B0 = 9;
      Actor_sub_45976D(pActor);
      pActor->word_0000B0 = 18;
    }
    else
    {
      Actor_sub_45976D(pActor);
    }
  }
  else
    Actor_sub_402AD7(uActorID, a2, uActorID, 64, pStruc1);
}


//----- (004032B2) --------------------------------------------------------
void Actor_sub_4032B2(unsigned int uActorID, int a2, int a3, int a4)
{
  struct Actor* pActor;
  int v4;
  int deltaX;
  int deltaY;
  int v10;
  int v11;
  struct Actor_struct1 v15;
  int v16;    
  int v20;

  pActor = &pActors[uActorID];

  deltaX = pActor->word_0000A2 - pActor->sActorPosX;
  deltaY = pActor->word_0000A4 - pActor->sActorPosY;
  v20 = abs(deltaX);
  v4 = abs(deltaY);

  if ( v20 <= v4 )
    v20 = v4 + (v20 >> 1);
  else
    v20 = v20 + (v4 >> 1);

  //? uMonsterID - 1  
  if ( sub_438BDF(pActor->uMonsterID, 6) )
  {
    if ( !a4 )
      a4 = 256;
    return Actor_sub_403F58(uActorID, 4, a4, &v15); //WTF: why v15 uninitialized?
  }

  //if ( byte_5FF193[uActorID * 836] == 3 && v20 < 128 )
  if ( pActor->byte_00002A[17] == 3 && v20 < 128 )
  {
    return Actor_sub_403EB6(uActorID, a2, 256, &v15);
  }
    
  v20 += (unsigned __int64)( ((rand() & 0xF) << 12) * a3 ) >> 16;
  v10 = (pClass59_global->dword_001868 - 1) & sub_45281E(pClass59_global, deltaX, deltaY);

  if ( rand() % 100 < 25 )
  {
    sub_403E61(uActorID);
    return;
  }

  v11 = v10 + rand() % 256 - 128;
  if ( abs(v11 - pActor->word_00009A) > 256 && !(pActor->dword_000024 & 0x00200000) )
  {
    Actor_sub_403EB6(uActorID, a2, 256, &v15);
    return;
  }

  pActor->word_00009A = v11;

  if ( pActor->word_00008C )
    pActor->word_0000A0 = 32 * v20 / pActor->word_00008C;
  else
    pActor->word_0000A0 = 0;

  pActor->dword_0000B8 = 0;
  pActor->word_0000B0 = 1;  
  
  if ( rand() % 100 < 2 )
    sub_402CED(uActorID, 3);

  Actor_sub_45976D(pActor);
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