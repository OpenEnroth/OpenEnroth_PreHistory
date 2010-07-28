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
  char v1;
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
  if ( sub_449B57((int)byte_ACD71D, 100) )
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

    v1 = 0;
    if ( !v8 || v7 )
    {
      if ( !v6 || v5 )
      {
        v1 = sub_438B9B(pActor);
        if ( v1 )
          pActor->dword_000024 &= 0xFFF7FFFF;
      }
    }
    pActor->dword_000024 &= 0xFF7FFFFF;
    if (pActor->dword_000024 & 0x400000 )
      v1 = sub_4031C1(i, pParty_global->uCurrentHour, 1);
  }
  return v1;
}


//----- (00403EB6) --------------------------------------------------------
void Actor_sub_403EB6(unsigned int uActorID, signed int a2, int a3, struct DirectionInfo *pDirectionInfo)
{
  struct DirectionInfo v9;
  struct Actor *pActor;

  pActor = &pActors[uActorID];
  if ( !pDirectionInfo )
  {
    GetDirectionInfo(8 * uActorID | 3, a2, &v9, 0);    
    pDirectionInfo = &v9;
  }
    
  pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle);

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

// Get direction vector from object1 to object2,
// distance from object1 to object2 and Euler angles of the direction vector
//
//
// object1 & object2 format :  objectType | (objectID << 3)
//    objectType == 3 - Actor
//    objectType == 4 - Party
//
// originally this function had following prototype:
// struct DirectionInfo GetDirectionInfo(signed int object1, signed int object2, signed int a4)
// but compiler converts functions returning structures by value in the such way

struct DirectionInfo* GetDirectionInfo(signed int object1, signed int object2, struct DirectionInfo *pDirectionInfo, signed int a4)
{
  int type1;
  int type2;  
  int idx1;
  int idx2;  

  int x0;
  int z0;
  int y0;  
  int x1;
  int y1;
  int z1;

  double deltaX;
  double deltaY;
  double deltaZ;
  double distance;

  struct DirectionInfo direction;

  idx1 = object1 >> 3;
  type1 = (object1 & 7);

  if ( type1 == 2 )
  {    
    x0 = array_665230[idx1].sItemPosX;
    y0 = array_665230[idx1].sItemPosY;
    z0 = array_665230[idx1].sItemPosZ;
  }  
  else if ( type1 == 3 )
  {
    x0 = pActors[idx1].sActorPosX;
    y0 = pActors[idx1].sActorPosY;    
    z0 = pActors[idx1].sActorPosZ - (unsigned int)((double)pActors[idx1].uActorHeight * -0.75);
  }
  else if ( type1 == 4 )
  {
    if ( idx1 == 0 )
    {
      x0 = pParty_global->sPartyPosX;
      y0 = pParty_global->sPartyPosY;
      z0 = pParty_global->sPartyPosZ + pParty_global->uPartyHeight / 3;
    }
    else if (idx1 < 5)
    {
      int sub_43AA99_p0;
      int sub_43AA99_p1;

      switch (idx1)
      {
      case 1:
        sub_43AA99_p0 = 24;
        sub_43AA99_p1 = pClass59_global->uIntegerHalfPi + pParty_global->sRotationY; 
        break;
      case 2:
        sub_43AA99_p0 = 8;
        sub_43AA99_p1 = pClass59_global->uIntegerHalfPi + pParty_global->sRotationY;  
        break;
      case 3:
        sub_43AA99_p0 = 24;
        sub_43AA99_p1 = pParty_global->sRotationY - pClass59_global->uIntegerHalfPi;
        break;
      case 4:
        sub_43AA99_p0 = 8;
        sub_43AA99_p1 = pParty_global->sRotationY - pClass59_global->uIntegerHalfPi;
        break;
      }

      sub_43AA99(sub_43AA99_p0, 
                 sub_43AA99_p1,         
                 0, 
                 pParty_global->sPartyPosX, 
                 pParty_global->sPartyPosY, 
                 pParty_global->sPartyPosZ + pParty_global->uPartyHeight / 3, 
                 (int)&x0, 
                 (int)&y0, 
                 (int)&z0);
    }   
  }
  else if ( type1 == 5 )
  {
    x0 = array_6836D0[idx1].sPosX;
    y0 = array_6836D0[idx1].sPosY;
    z0 = array_6836D0[idx1].sPosZ;
  }
  else if ( type1 == 6 )
  {
    if ( dword_6BE360 == 1 )
    {
      char* ptr = dword_6BE644 + 96 * idx1;
      x0 = (*(_WORD *)(ptr + 80) + (signed int)*(_WORD *)(ptr + 82)) >> 1;
      y0 = (*(_WORD *)(ptr + 84) + (signed int)*(_WORD *)(ptr + 86)) >> 1;
      z0 = (*(_WORD *)(ptr + 88) + (signed int)*(_WORD *)(ptr + 90)) >> 1;
    }
  }
  else   
  {
    z0 = 0;
    y0 = 0;
    x0 = 0;
  }
    
  type2 = object2 >> 3;
  idx2 = object2 / 8;

  if ( type2 == 2 )
  {
    x1 = array_665230[idx2].sItemPosX;
    y1 = array_665230[idx2].sItemPosY;
    z1 = array_665230[idx2].sItemPosZ;    
  }
  else if ( type2 == 3 )
  {
    x1 = pActors[idx2].sActorPosX;
    y1 = pActors[idx2].sActorPosY;
    z1 = pActors[idx2].sActorPosZ - (unsigned int)(signed __int64)((double)pActors[idx2].uActorHeight * -0.75);    
  }
  else if ( type2 == 4 )
  {
    x1 = pParty_global->sPartyPosX;
    y1 = pParty_global->sPartyPosY;   
    z1 = a4;
    if ( !z1 )
      z1 = pParty_global->uEyelevel;

    z1 += pParty_global->sPartyPosZ;
  }
  else if ( type2 == 5 )
  {    
    x1 = array_6836D0[idx2].sPosX;
    y1 = array_6836D0[idx2].sPosY;
    z1 = array_6836D0[idx2].sPosZ;
  }
  else if ( type2 == 6 )
  {
    char* ptr = dword_6BE644 + 96 * idx2;
    x1 = (*(_WORD *)(ptr + 80) + *(_WORD *)(ptr + 82)) >> 1;
    y1 = (*(_WORD *)(ptr + 84) + *(_WORD *)(ptr + 86)) >> 1;
    z1 = (*(_WORD *)(ptr + 88) + *(_WORD *)(ptr + 90)) >> 1;     
  }
  else
  {
    x1 = 0;
    y1 = 0;
    z1 = 0;
  }
  
  deltaX = (double)x1 - (double)x0;
  deltaY = (double)y1 - (double)y0;
  deltaZ = (double)z1 - (double)z0;

  distance = sqrt(deltaZ * deltaZ + deltaY * deltaY + deltaX * deltaX);

  if (distance <= 1.0)
  {
    direction.sVecX = 65536;
    direction.sVecY = 0;
    direction.sVecZ = 0;
    direction.uDistance = 1;
    direction.uDistanceXY = 1;
    direction.uYawAngle = 0;
    direction.uPitchAngle = 0;
  }
  else
  {
    direction.sVecX = (int)(1.0 / distance * deltaX * 65536.0);
    direction.sVecY = (int)(1.0 / distance * deltaY * 65536.0);
    direction.sVecZ = (int)(1.0 / distance * deltaZ * 65536.0);
    direction.uDistance = (unsigned int)distance;
    direction.uDistanceXY = (unsigned int)sqrt(deltaX * deltaX + deltaY * deltaY);
    direction.uYawAngle = class59_Atan2(pClass59_global, (int)deltaX, (int)deltaY);
    direction.uPitchAngle = class59_Atan2(pClass59_global, direction.uDistanceXY, (int)deltaZ);
  }

  memcpy(pDirectionInfo, &direction, sizeof(struct DirectionInfo));
  return pDirectionInfo;
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
  _this->uActorHeight = pActorDescription->uMonsterHeight;
  _this->uSpeed = pActorInfo->uSpeed;
  if (~a2 & 1)
  {
    for (i = 0; i < 4; ++i)
      _this->array_0000CC[i] = pActorDescription->arrray_00000C[i];
  }
}

//----- (0040104C) --------------------------------------------------------
signed int Actor_sub_40104C(struct Actor *pActor1, struct Actor *pActor2)
{  
  int v3;
  int v4;
  int v7;
  int v8;
    
  if (pActor1)
  {   
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
    v7 = (v3 - 1) / 3 + 1; //are -1 and +1 needed? 
  else
    v7 = 0;

  if ( v4 )
    v8 = (v4 - 1) / 3 + 1; //are -1 and +1 needed? 
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
    
    if ( pActor2->array_0000D4[12].qword_000000 > 0i64 )
      v8 = 0;
  }
    
  if ( (pActor1 && (pActor1->array_0000D4[1].qword_000000 > 0i64) && !v8) || 
       (pActor2 && (pActor2->array_0000D4[1].qword_000000 > 0i64) && !v7) )
  {
    return 0;
  }

  if ( pActor1 && (pActor1->array_0000D4[12].qword_000000 <= 0i64) && 
       (pActor1->dword_000024 & 0x80000) && !v8 )
  {
    return 4;
  }

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
void Actor_sub_403C6C(unsigned int uActorID, int a2, struct DirectionInfo *pDirectionInfo)
{
  struct Actor *pActor;
  struct DirectionInfo v18;
  
  int v6;
  int v7; 
  int v14; 
  short v16;
  int v22;
    
  pActor = &pActors[uActorID];

  if ( (pActor->byte_00002A[17] == 5) && (pActor->byte_00002A[18] == 1) )
  {
    Actor_sub_403EB6(uActorID, a2, 0, pDirectionInfo);
    return;
  }
 
  if ( (a2 & 7) == 3 )
  {      
    v7 = pActors[a2 >> 3].sActorPosX;
    v6 = pActors[a2 >> 3].sActorPosY;
    v22 = (signed __int64)((double)pActors[a2 >> 3].uActorHeight * 0.75 + 
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
      v7 = (int)pDirectionInfo; 
      v6 = (int)pDirectionInfo;
    }
  }
    
  if ( sub_407A1C(v7, v6, v22, pActor->sActorPosX, pActor->sActorPosY, 
                 (int)((double)pActor->uActorHeight * 0.75 + (double)pActor->sActorPosZ)) )
  {
    if ( !pDirectionInfo )
    { 
      GetDirectionInfo(8 * uActorID | 3, a2, &v18, 0);      
      pDirectionInfo = &v18;
    }
    
    //v15 = pSpriteFrameTable->pSpriteSFrames;
    //v16 = *(_WORD *)(60 * *(_WORD *)(v3 + 192) + v15 + 56);
    v16 = pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[2]].word_000038;

    pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle);
    pActor->word_0000A0 = 8 * v16;
    pActor->dword_0000B8 = 0;
    pActor->word_0000B0 = 2;

    Actor_sub_402CED(uActorID, 0);

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
    Actor_sub_402AD7(uActorID, a2, rand() % 2, 64, pDirectionInfo);
  }
}

//----- (00402F87) --------------------------------------------------------
void Actor_sub_402F87(unsigned int uActorID, signed int a2, struct DirectionInfo* pDirectionInfo)
{
  int v7;
  int v9;

  struct Actor *pActor;  
  struct DirectionInfo v11;
      
  pActor = &pActors[uActorID];  
  if ( !pDirectionInfo )
  {
    GetDirectionInfo(8 * uActorID | 3, a2, &v11, 0);    
    pDirectionInfo = &v11;
  }

  pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle);
  pActor->word_0000A0 = 8 * pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[7]].word_000038;

  v7 = class59_Atan2(pClass59_global, 
                  pActor->sActorPosX - pOldCamera->dword_000000, 
                  pActor->sActorPosY - pOldCamera->dword_000004);
    
  v9 = pClass59_global->uIntegerPi + pActor->uYawAngle + (pClass59_global->uIntegerPi >> 3) - v7;
  
  //if ( BYTE1(v9) & 7 )
  if (v9 & 0x700)
  {
    Actor_sub_403EB6(uActorID, a2, pActor->word_0000A0, pDirectionInfo);
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
      Actor_sub_402CED(uActorID, 3);

    Actor_sub_45976D(pActor);
  }
}


//----- (00403F58) --------------------------------------------------------
void Actor_sub_403F58(unsigned int uActorID, int a2, int a3, struct DirectionInfo* pDirectionInfo)
{ 
  struct DirectionInfo v10;

  if ( rand() % 2 )
  {
    Actor_sub_402F87(uActorID, a2, pDirectionInfo);
  }
  else
  {    
    struct Actor* pActor = &pActors[uActorID];    
    if ( !pDirectionInfo )
    {
      GetDirectionInfo(8 * uActorID | 3, a2, &v10, 0);            
      pDirectionInfo = &v10;
    }

    pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle);
    pActor->uPitchAngle = LOWORD(pDirectionInfo->uPitchAngle);

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
void Actor_sub_404030(unsigned int uActorID, signed int a2, int a3, struct DirectionInfo *pDirectionInfo)
{
  struct DirectionInfo v12;

  if ( rand() % 100 >= 5 )
  {
    struct Actor *pActor = &pActors[uActorID]; 
    if ( !pDirectionInfo )
    {
      GetDirectionInfo(8 * uActorID | 3, a2, &v12, 0);      
      pDirectionInfo = &v12;
    }

    pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle);   
    pActor->dword_0000B8 = 0;
    pActor->word_000098 = 0;
    pActor->word_000096 = 0;
    pActor->word_000094 = 0;
    pActor->uPitchAngle = LOWORD(pDirectionInfo->uPitchAngle);
    pActor->word_0000A0 = 256;
    pActor->word_0000B0 = 10;
    Actor_sub_45976D(pActor);
  }
  else
  {
    Actor_sub_402F87(uActorID, a2, pDirectionInfo);
  }
}


//----- (00402968) --------------------------------------------------------
void Actor_sub_402968(unsigned int uActorID, int a2, int a3, struct DirectionInfo *pDirectionInfo)
{
  struct Actor *pActor;
  struct DirectionInfo v10;
  struct DirectionInfo v11;
  
  pActor = &pActors[uActorID];
  if ( !Actor_sub_40894B(pActor) )
  {
    return;
  }

  if ( !pDirectionInfo )
  {
    GetDirectionInfo(8 * uActorID | 3, a2, &v11, pActor->byte_00002A[16]);
    pDirectionInfo = &v11;    
  }

  GetDirectionInfo(8 * uActorID | 3, 4, &v10, 0);

  //uMonsterID - 1 ?
  if ( sub_438BDF(pActor->uMonsterID, 6) || ((a2 & 7) == 3 && (double)v10.uDistance < 307.2) )
  {
    if ( !a3 )
      a3 = 256;
    Actor_sub_403F58(uActorID, 4, a3, &v10);
  }
  else
  {
    if ( pActor->uSpeed )
      pActor->word_0000A0 = (pDirectionInfo->uDistanceXY << 7) / (signed int)pActor->uSpeed;      
    else
      pActor->word_0000A0 = 0;
    
    if ( pActor->word_0000A0 > 256 )
      pActor->word_0000A0 = 256;

    pActor->uYawAngle = pClass59_global->uIntegerHalfPi + LOWORD(pDirectionInfo->uYawAngle);
    pActor->uYawAngle = pClass59_global->uDoublePiMask & (pActor->uYawAngle + rand() % pClass59_global->uIntegerPi);

    pActor->dword_0000B8 = 0;
    pActor->uPitchAngle = LOWORD(pDirectionInfo->uPitchAngle);
    pActor->word_0000B0 = 7;
    Actor_sub_45976D(pActor);
  }
}


//----- (00402686) --------------------------------------------------------
void Actor_sub_402686(unsigned int uActorID, signed int a2, signed int a3, struct DirectionInfo *pDirectionInfo)
{
  signed int v4;
  struct Actor* pActor;
  struct DirectionInfo v19;

  v4 = 0;
  pActor = &pActors[uActorID];
  if ((pActor->byte_00002A[16] != 0 ) && (!pParty_global->dword_000704))
  {
    if (pActor->byte_00003E[7] && (dword_6BE360 == 2))
      v4 = pActor->word_000088 + 512;      
    else
      v4 = pParty_global->uPartyHeight;
  }

  if ( !pDirectionInfo )
  {
    GetDirectionInfo(8 * uActorID | 3, a2, &v19, v4);
    pDirectionInfo = &v19;
  }
    
  if ( sub_438BDF(pActor->uMonsterID - 1, 6) )
  {
    if ( !a3 )
      a3 = 256;
    Actor_sub_403F58(uActorID, 4, a3, pDirectionInfo);
    return;
  }

  if ( (double)pDirectionInfo->uDistance < 307.2 )
  {
    if ( !a3 )
      a3 = 256;

    Actor_sub_403F58(uActorID, a2, a3, pDirectionInfo);
    return;
  }

  if ( a3 )
  {
    pActor->word_0000A0 = a3 + rand() % a3;    
  }
  else
  {    
    if ( pActor->uSpeed )
      pActor->word_0000A0 = (pDirectionInfo->uDistanceXY << 7) / (signed int)pActor->uSpeed;
    else
      pActor->word_0000A0 = 0;

    if ( pActor->word_0000A0 > 128 )
      pActor->word_0000A0 = 128;
  }
  
  if ( rand() % 2 )
    pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle) + 256;
  else
    pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle) - 256;
  
  pActor->dword_0000B8 = 0;
  pActor->uPitchAngle = LOWORD(pDirectionInfo->uPitchAngle);
  pActor->word_0000B0 = 6;
  
  if ( rand() % 100 < 2 )
    Actor_sub_402CED(uActorID, 2);

  Actor_sub_45976D(pActor);
}


//----- (0040281C) --------------------------------------------------------
void Actor_sub_40281C(unsigned int uActorID, signed int a2, signed int a3, struct DirectionInfo *pDirectionInfo, int a5)
{
  signed int v5;
  struct Actor* pActor;
  struct DirectionInfo v17;
    
  v5 = 0;
  pActor = &pActors[uActorID];
  if ((pActor->byte_00002A[16] != 0 ) && (!pParty_global->dword_000704))
  {
    if (pActor->byte_00003E[7] && (dword_6BE360 == 2))
      v5 = pActor->word_000088 + 512;      
    else
      v5 = pParty_global->uPartyHeight;
  }

  if ( !pDirectionInfo )
  {
    GetDirectionInfo(8 * uActorID | 3, a2, &v17, v5);  
    pDirectionInfo = &v17;
  }
    
  if ( sub_438BDF(pActor->uMonsterID - 1, 6) )
  {
    if ( !a3 )
      a3 = 256;
    Actor_sub_403F58(uActorID, 4, a3, pDirectionInfo);
    return;
  }

  if ( pDirectionInfo->uDistance < a5 )
  {
    if ( !a3 )
      a3 = 256;

    Actor_sub_403F58(uActorID, a2, a3, pDirectionInfo);
    return;
  }

  if ( a3 )
  {
    pActor->word_0000A0 = a3;
  }
  else
  {
    if ( pActor->uSpeed )
      pActor->word_0000A0 = (pDirectionInfo->uDistanceXY << 7) / (signed int)pActor->uSpeed;
    else
      pActor->word_0000A0 = 0;

    if ( pActor->word_0000A0 > 32 )
      pActor->word_0000A0 = 32;
  }

  pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle);  
  pActor->dword_0000B8 = 0;
  pActor->uPitchAngle = LOWORD(pDirectionInfo->uPitchAngle);
  pActor->word_0000B0 = 6;

  Actor_sub_45976D(pActor);
}

//----- (00402AD7) --------------------------------------------------------
void Actor_sub_402AD7(unsigned int uActorID, signed int a2, signed int a3, int a4, struct DirectionInfo *pDirectionInfo)
{
  struct Actor *pActor;
  int v5;
  struct DirectionInfo v14;

  pActor = &pActors[uActorID];
  v5 = 0;

  if ((pActor->byte_00002A[16] != 0 ) && (!pParty_global->dword_000704))
  {
    if (pActor->byte_00003E[7])
      v5 = pActor->word_000088 + 512;
    else
      v5 = pParty_global->uPartyHeight;
  }

  if ( !pDirectionInfo )
  {
    GetDirectionInfo(8 * uActorID | 3, a2, &v14, v5);    
    pDirectionInfo = &v14;
  }
    
  if ( sub_438BDF(pActor->uMonsterID - 1, 6) )  
  {
    if ( !a4 )
      a4 = 256;

    Actor_sub_403F58(uActorID, 4, a4, pDirectionInfo);
    return;
  }
  else if ( (double)pDirectionInfo->uDistance < 307.2 )
  {
    if ( !a4 )
      a4 = 256;

    Actor_sub_403EB6(uActorID, a2, a4, pDirectionInfo);
    return;
  }
  else if ( !pActor->uSpeed)
  {
    Actor_sub_403EB6(uActorID, a2, a4, pDirectionInfo);
    return;
  }

  {
    int tmpCos;
    int tmpSin;
    int deltaX;
    int deltaY;
    int tmpX;
    int tmpY;

    int v18 = ( a3 % 2 ) ? -16 : 16;

    //-cos(pDirectionInfo->uYawAngle + v18)
    tmpCos = class59_SinCos(pClass59_global, v18 + pDirectionInfo->uYawAngle + pClass59_global->uIntegerPi); 
    deltaX = ((unsigned __int64)(tmpCos * pDirectionInfo->uDistanceXY) >> 16);
    tmpX = pParty_global->sPartyPosX + deltaX - pActor->sActorPosX;
  
    //-sin(pDirectionInfo->uYawAngle + v18)
    tmpSin = class59_SinCos(pClass59_global, v18 + pDirectionInfo->uYawAngle + pClass59_global->uIntegerHalfPi);
    deltaY =  ((unsigned __int64)(tmpSin * pDirectionInfo->uDistanceXY) >> 16);
    tmpY = pParty_global->sPartyPosY + deltaY - pActor->sActorPosY;
    
    pActor->uYawAngle = class59_Atan2(pClass59_global, tmpX, tmpY);
  }

  if ( a4 )
    pActor->word_0000A0 = a4;    
  else
    pActor->word_0000A0 = 128;

  pActor->uPitchAngle = LOWORD(pDirectionInfo->uPitchAngle);
  pActor->word_0000B0 = 6;
  Actor_sub_45976D(pActor);
}

//----- (00403854) --------------------------------------------------------
void Actor_sub_403854(unsigned int uActorID, signed int a2, struct DirectionInfo *pDirectionInfo)
{
  struct Actor *pActor;
  int v4;
  int v5;
  int v11;
  short v13;
  struct DirectionInfo v16;
  int v20;

  pActor = &pActors[uActorID];
  if ( (a2 & 7) == 3 )
  {
    v5 = pActors[a2 >> 3].sActorPosX;
    v4 = pActors[a2 >> 3].sActorPosY;
    v20 = (signed __int64)((double)pActors[a2 >> 3].uActorHeight * 0.75
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
      v5 = (int)pDirectionInfo;
      v4 = (int)pDirectionInfo;
    }
  }

  if ( sub_407A1C(v5, v4, v20, pActor->sActorPosX, pActor->sActorPosY,
                  pActor->sActorPosZ - (int)((double)pActor->uActorHeight * -0.75)) )
  {
    if ( !pDirectionInfo )
    { 
      GetDirectionInfo(8 * uActorID | 3, a2, &v16, 0);      
      pDirectionInfo = &v16;      
    }

    //v12 = pSpriteFrameTable->pSpriteSFrames;
    //v13 = *(_WORD *)(60 * *(_WORD *)(pActor + 194) + v12 + 56);
    v13 = pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[3]].word_000038;

    pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle);        
    pActor->word_0000A0 = 8 * v13;
    pActor->dword_0000B8 = 0;
    pActor->word_0000B0 = 13;

    Actor_sub_402CED(uActorID, 0);

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
    Actor_sub_402AD7(uActorID, a2, uActorID, 64, pDirectionInfo);
  }
}


//----- (0040368B) --------------------------------------------------------
void Actor_sub_40368B(unsigned int uActorID, signed int a2, struct DirectionInfo *pDirectionInfo)
{
  struct Actor *pActor;  
  int v4;
  int v5;
  int v11;
  short v13;
  struct DirectionInfo v15;
  int v19;
    
  pActor = &pActors[uActorID];  
  if ( (a2 & 7) == 3 )
  {    
    v5 = pActors[a2 >> 3].sActorPosX;
    v4 = pActors[a2 >> 3].sActorPosY;
    v19 = (signed __int64)((double)pActors[a2 >> 3].uActorHeight * 0.75
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
      v5 = (int)pDirectionInfo;
      v4 = (int)pDirectionInfo;
    }
  }

  if ( sub_407A1C(v5, v4, v19, pActor->sActorPosX, pActor->sActorPosY,
                  pActor->sActorPosZ - (int)((double)pActor->uActorHeight * -0.75)) )
  {
    if ( !pDirectionInfo )
    {
      GetDirectionInfo(8 * uActorID | 3, a2, &v15, 0);      
      pDirectionInfo = &v15;      
    }

    //v12 = pSpriteFrameTable->pSpriteSFrames;
    //v13 = *(_WORD *)(60 * *(_WORD *)(pActor + 194) + v12 + 56);
    v13 = pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[3]].word_000038;

    pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle);    
    pActor->word_0000A0 = 8 * v13;
    pActor->dword_0000B8 = 0;
    pActor->word_0000B0 = 12;

    Actor_sub_402CED(uActorID, 0);

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
    Actor_sub_402AD7(uActorID, a2, uActorID, 64, pDirectionInfo);
  }
}

//----- (00403476) --------------------------------------------------------
void Actor_sub_403476(unsigned int uActorID, signed int a2, struct DirectionInfo *pDirectionInfo)
{
  struct Actor *pActor; 
  int v4;
  int v5;
  int v11;
  short v13;
  struct DirectionInfo v15;
  int v20;

  pActor = &pActors[uActorID];  
  if ( (a2 & 7) == 3 )
  {
    v5 = pActors[a2 >> 3].sActorPosX;
    v4 = pActors[a2 >> 3].sActorPosY;
    v20 = (signed __int64)((double)pActors[a2 >> 3].uActorHeight * 0.75
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
      v5 = (int)pDirectionInfo;
      v4 = (int)pDirectionInfo;
    }
  }

  if ( sub_407A1C(v5, v4, v20, pActor->sActorPosX, pActor->sActorPosY, 
                 pActor->sActorPosZ - (int)((double)pActor->uActorHeight * -0.75)) 
       ||
       sub_407A1C(pActor->sActorPosX, pActor->sActorPosY, 
                  pActor->sActorPosZ - (int)((double)pActor->uActorHeight * -0.75),
                  v5, v4, v20) )
  {
    if ( !pDirectionInfo )
    {
      GetDirectionInfo(8 * uActorID | 3, a2, &v15, 0);
      pDirectionInfo = &v15; 
    }

    //v12 = pSpriteFrameTable->pSpriteSFrames;
    //v13 = *(_WORD *)(60 * *(_WORD *)(pActor + 194) + v12 + 56);
    v13 = pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[3]].word_000038;

    pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle);
    pActor->word_0000A0 = 8 * v13;
    pActor->dword_0000B8 = 0;
    pActor->word_0000B0 = 3;

    Actor_sub_402CED(uActorID, 0);

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
    Actor_sub_402AD7(uActorID, a2, uActorID, 64, pDirectionInfo);
}

//----- (00403A60) --------------------------------------------------------
void Actor_sub_403A60(unsigned int uActorID, signed int a2, struct DirectionInfo *pDirectionInfo)
{
  struct Actor *pActor; 
  int v4;
  int v5;
  int v11;
  short v13;
  struct DirectionInfo v16;
  int v20;

  pActor = &pActors[uActorID];
  if ( (a2 & 7) == 3 )
  {
    v5 = pActors[a2 >> 3].sActorPosX;
    v4 = pActors[a2 >> 3].sActorPosY;
    v20 = (signed __int64)((double)pActors[a2 >> 3].uActorHeight * 0.75
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
      v5 = (int)pDirectionInfo;
      v4 = (int)pDirectionInfo;
    }
  }

  if ( sub_407A1C(v5, v4, v20, pActor->sActorPosX, pActor->sActorPosY, 
                  pActor->sActorPosZ - (int)((double)pActor->uActorHeight * -0.75)) )
  {
    if ( !pDirectionInfo )
    {
      GetDirectionInfo(8 * uActorID | 3, a2, &v16, 0);      
      pDirectionInfo = &v16;
    }

    //v12 = pSpriteFrameTable->pSpriteSFrames;
    //v13 = *(_WORD *)(60 * *(_WORD *)(pActor + 194) + v12 + 56);
    v13 = pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[3]].word_000038;

    pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle);
    pActor->word_0000A0 = 8 * v13;
    pActor->dword_0000B8 = 0;
    pActor->word_0000B0 = 18;

    Actor_sub_402CED(uActorID, 0);

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
    Actor_sub_402AD7(uActorID, a2, uActorID, 64, pDirectionInfo);
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
  struct DirectionInfo v15;
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
    
  if ( sub_438BDF(pActor->uMonsterID - 1, 6) )
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
  v10 = (pClass59_global->uIntegerDoublePi - 1) & class59_Atan2(pClass59_global, deltaX, deltaY);

  if ( rand() % 100 < 25 )
  {
    sub_403E61(uActorID);
    return;
  }

  v11 = v10 + rand() % 256 - 128;
  if ( abs(v11 - pActor->uYawAngle) > 256 && !(pActor->dword_000024 & 0x00200000) )
  {
    Actor_sub_403EB6(uActorID, a2, 256, &v15);
    return;
  }

  pActor->uYawAngle = v11;

  if ( pActor->uSpeed )
    pActor->word_0000A0 = 32 * v20 / pActor->uSpeed;
  else
    pActor->word_0000A0 = 0;

  pActor->dword_0000B8 = 0;
  pActor->word_0000B0 = 1;  
  
  if ( rand() % 100 < 2 )
    Actor_sub_402CED(uActorID, 3);

  Actor_sub_45976D(pActor);
}

//----- (00402CED) --------------------------------------------------------
void Actor_sub_402CED(unsigned int uActorID, int a2)
{
  struct Actor *pActor;
  signed int v8;
  int v12;

  pActor = &pActors[uActorID];  
  if ( pActor->array_0000CC[a2] )
  {
    if ( pActor->array_0000D4[3].qword_000000 <= 0i64 )
    {
      v12 = 0;
      v8 = -1;
    }
    else
    {
      switch (pActor->array_0000D4[3].word_000008)
      {
      case 2:
        v12 = 33075;
        break;

      case 3:
        v12 = 44100;
        break;

      case 4:
        v12 = 55125;
        break;
        
      default:
        v12 = uActorID;
        break;
      }
            
      v8 = 0;
    }
    
    AudioPlayer_sub_4AA306(pAudioPlayer, pActor->array_0000CC[a2], 
                           (uActorID * 8) | 3, 0, v8, 0, 0, 0, v12);
  }
}

//----- (00402D6E) --------------------------------------------------------
void Actor_sub_402D6E(unsigned int uActorID)
{  
  unsigned short monsterID;  
  struct ItemGen itemGen;
  struct Actor *pActor;
  int i;

  pActor = &pActors[uActorID];
      
  pActor->word_0000B0 = 4;
  pActor->word_0000B2 = 5;
  pActor->dword_0000B8 = 0;  
  pActor->word_000028 = 0;
  pActor->word_0000A0 = 8 * pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[5]].word_000038;
  
  sub_458585(LODWORD(pActor->array_0000D4[6].qword_000000));
  sub_458585(LODWORD(pActor->array_0000D4[5].qword_000000));

  Actor_sub_402CED(uActorID, 1);
  Actor_sub_45976D(pActor);

  monsterID = pActor->uMonsterID - 1;  
  for (i = 0; i < 5; ++i)
  {
    if ( monsterID == pParty_global->array_000750[i] )
      pParty_global->array_00075A[i] = 1;
  }
  
  for (i = 0; i < 22; ++i)
    sub_458585(&pActor->array_0000D4[i].qword_000000);

  ItemGen_Reset(&itemGen);
  ItemGen_Reset(&itemGen);
  
  if (monsterID >= 20 && monsterID <= 22) //devil worker, devil warrior, devil captain
  {
    itemGen.dword_000000 = 214;  
  }
  else if (monsterID >= 24 && monsterID <= 26) //green dragon, blue dragon, red dragon
  {
    itemGen.dword_000000 = 204;
  }
  else if (monsterID >= 84  && monsterID <= 86) //harpy, harpy hag, harpy queen
  {
    itemGen.dword_000000 = 207;
  }
  else if (monsterID >= 111 && monsterID <= 113) //emerald ooze, sapphire ooze, bloodstone ooze
  {
    itemGen.dword_000000 = 217;
  }
  else if (monsterID >= 249 && monsterID <= 251) //swamp troll, river troll, mountain troll
  {
    itemGen.dword_000000 = 202;
  }

  if ( itemGen.dword_000000 )
  {
    if ( (rand() % 100) < 20 )
    {
      sub_42F7EB(
        (unsigned __int16)word_5D29F8[24 * itemGen.dword_000000],
        pActor->sActorPosX,
        pActor->sActorPosY,
        pActor->sActorPosZ + 16,
        rand() % 200 + 200,
        1,
        1,
        0,
        &itemGen);
    }
  }

  if ( pActor->byte_00003E[28] == 3 )
    sub_404736(uActorID);
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
 _this->uActorHeight = 128;
 _this->uSpeed = 200;

 _this->sActorPosX = 0;
 _this->sActorPosY = 0;
 _this->sActorPosZ = 0;
 
 _this->word_000094 = 0;
 _this->word_000096 = 0;
 _this->word_000098 = 0;
 _this->uYawAngle = 0;
 _this->uPitchAngle = 0;
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

//----- (0047F2D3) --------------------------------------------------------
bool InitializeActors(unsigned int uLocationID)
{
  int          i;
  struct Actor v6;
  int v8; // [sp+348h] [bp-8h]@1

  v8 = 0;
  for (i = 0; i < uNumActors; ++i)
  {
    bool bIsSomeFlagSet = pActors[i].dword_000024 & 0x100000;
    if ( (!bIsSomeFlagSet && v8 != 1) || (uLocationID != 0 && v8 != 0) )
    {
      pActors[i].dword_0000B8 = 0;
      pActors[i].word_0000A0 = 0;
      if ( pActors[i].dword_000024 & 0x10000 )
        pActors[i].word_0000B0 = 19;

      if (pActors[i].word_0000B0 != 11 && pActors[i].word_0000B0 != 19)
      {
        if (!pActors[i].word_000028 || *(int *)&pActors[i].word_00006C == 0 )
          pActors[i].word_0000B0 = 5;
      }
      pActors[i].word_000094 = 0;
      pActors[i].word_000096 = 0;
      pActors[i].word_000098 = 0;
      Actor_sub_45976D(&pActors[i]);
      pActors[i].byte_00003D = 0;

      Actor_LinkSprites(&pActors[i], 0);
    }
    else
    {
      pActors[i].word_0000B0 = 19;
      pActors[i].dword_000024 |= 0x10000;
      if (bIsSomeFlagSet && (uLocationID != 0) && !v8)
      {
        v8 = sub_450DA3();
      }
    }
  }

  LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);

  Actor_TotalReset(&v6);
  v6.uMonsterID = 45;

  //initialize light elemental, probably since it's not on the map but can be summoned at any time

  //[inviZ_khv] WTF? v6 is local variable and it's destroyed when function returns
  Actor_LinkSprites(&v6, 0);
  return true;
}