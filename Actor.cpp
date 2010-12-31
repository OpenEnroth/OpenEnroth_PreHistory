#include "Actor.h"

#include "data.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "FrameTables.h"
#include "AudioPlayer.h"
#include "Vis.h"

#include "GUI\GUI.h"



//----- (0040894B) --------------------------------------------------------
bool Actor_sub_40894B(struct Actor *_this)
{
  bool v1; // esi@1

  v1 = false;

  if (_this->pActorBuffs[SPELLBUFF_FEATHERFALL].qword_000000 > 0i64 || _this->pActorBuffs[6].qword_000000 > 0i64 )  
    v1 = true;

  return !(v1 ||
           _this->uAIState == AI::State::Dying ||
           _this->uAIState == AI::State::Dead ||
           _this->uAIState == AI::State::Removed ||
           _this->uAIState == AI::State::Summoned ||
           _this->uAIState == AI::State::Disabled);
}

//----- (00408768) --------------------------------------------------------
void __cdecl UpdateActors()
{
  char v1;
  signed int v5; // [sp+Ch] [bp-10h]@1
  signed int v6; // [sp+10h] [bp-Ch]@1
  signed int v7; // [sp+14h] [bp-8h]@1
  signed int v8; // [sp+18h] [bp-4h]@1

  struct Actor *pActor;

  v8 = 0;
  v6 = 0;
  v7 = 0;
  v5 = 0;

  if ( !_strcmpi((char *)pClass51_global->pLocationFileName, "d25.blv") ) //Celeste
    v8 = 1;
  if ( !_strcmpi((char *)pClass51_global->pLocationFileName, "d26.blv") ) //The Pit
    v6 = 1;
  if ( (unsigned __int16)sub_449B57((unsigned char *)pParty_global->unk_000764 + 1, 99) )
    v7 = 1;  
  if ( sub_449B57((unsigned char *)pParty_global->unk_000764 + 1, 100) )
    v5 = 1;

  for (unsigned int i = 0; i < uNumActors; ++i)
  {
    pActor = &pActors[i];

    if ( Actor_sub_40894B(pActor) || pActor->uAIState == AI::State::Disabled)
    {
      pActor->vPosition = pActor->vInitialPosition;
      pActor->sCurrentHP = pActor->sTotalHP;
      if (pActor->uAIState != AI::State::Disabled)
        Actor_sub_403EB6(i, dword_4F6E08[i], pActor->uRecoveryTime, 0);
    }

    pActor->uHostilityType = 0;

    v1 = 0;
    if ( !v8 || v7 )
    {
      if ( !v6 || v5 )
      {
        if ( sub_438B9B((int)pActor) )
          pActor->uAttributes &= 0xFFF7FFFF;
      }
    }
    pActor->uAttributes &= 0xFF7FFFFF;
    if (pActor->uAttributes & 0x400000 )
      sub_4031C1(i, pParty_global->uCurrentHour, 1);
  }
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
    pActor->uCurrentActionLength = rand() % 256 + 256;
  else
    pActor->uCurrentActionLength = a3;

  pActor->uAIState = AI::State::Standing;
  pActor->vVelocity = Vec3<short>(0, 0, 0);
  pActor->uCurrentActionTime = 0;
    
  Actor_UpdateAnimation(pActor);
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
    x0 = pLayingItemsList[idx1].sItemPosX;
    y0 = pLayingItemsList[idx1].sItemPosY;
    z0 = pLayingItemsList[idx1].sItemPosZ;
  }  
  else if ( type1 == 3 )
  {
    x0 = pActors[idx1].vPosition.x;
    y0 = pActors[idx1].vPosition.y;    
    z0 = pActors[idx1].vPosition.z - (unsigned int)((double)pActors[idx1].uActorHeight * -0.75);
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
      int RotateVector_p0;
      int RotateVector_p1;

      switch (idx1)
      {
      case 1:
        RotateVector_p0 = 24;
        RotateVector_p1 = pClass59_global->uIntegerHalfPi + pParty_global->sRotationY; 
        break;
      case 2:
        RotateVector_p0 = 8;
        RotateVector_p1 = pClass59_global->uIntegerHalfPi + pParty_global->sRotationY;  
        break;
      case 3:
        RotateVector_p0 = 24;
        RotateVector_p1 = pParty_global->sRotationY - pClass59_global->uIntegerHalfPi;
        break;
      case 4:
        RotateVector_p0 = 8;
        RotateVector_p1 = pParty_global->sRotationY - pClass59_global->uIntegerHalfPi;
        break;
      }

      RotateVector(RotateVector_p0, 
                 RotateVector_p1,         
                 0, 
                 pParty_global->sPartyPosX, 
                 pParty_global->sPartyPosY, 
                 pParty_global->sPartyPosZ + pParty_global->uPartyHeight / 3, 
                 &x0, 
                 &y0, 
                 &z0);
    }   
  }
  else if ( type1 == 5 )
  {
    x0 = pLevelDecorations[idx1].sPosX;
    y0 = pLevelDecorations[idx1].sPosY;
    z0 = pLevelDecorations[idx1].sPosZ;
  }
  else if ( type1 == 6 )
  {
    if ( uCurrentlyLoadedLevelType == 1 )
    {
      char *ptr = (char *)ptr_6BE644 + 96 * idx1;
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
    x1 = pLayingItemsList[idx2].sItemPosX;
    y1 = pLayingItemsList[idx2].sItemPosY;
    z1 = pLayingItemsList[idx2].sItemPosZ;    
  }
  else if ( type2 == 3 )
  {
    x1 = pActors[idx2].vPosition.x;
    y1 = pActors[idx2].vPosition.y;
    z1 = pActors[idx2].vPosition.z - (unsigned int)(signed __int64)((double)pActors[idx2].uActorHeight * -0.75);    
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
    x1 = pLevelDecorations[idx2].sPosX;
    y1 = pLevelDecorations[idx2].sPosY;
    z1 = pLevelDecorations[idx2].sPosZ;
  }
  else if ( type2 == 6 )
  {
    char *ptr = (char *)ptr_6BE644 + 96 * idx2;
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
void Actor_UpdateAnimation(struct Actor *_this)
{
  _this->uAttributes &= 0xFFDFFFFF;
  switch (_this->uAIState)
  {
    case AI::State::Tethered:
      _this->uCurrentActionAnimation = AI::Animation::Walking;
      break;

    case AI::State::AttackingMelee:
      _this->uCurrentActionAnimation = AI::Animation::AttackingMelee;
      _this->uAttributes |= 0x200000; break;

    case AI::State::AttackingRanged1:
    case AI::State::AttackingRanged2:
    case AI::State::AttackingRanged3:
    case AI::State::AttackingRanged4:
      _this->uCurrentActionAnimation = AI::Animation::AttackingRanged;
      _this->uAttributes |= 0x200000; break;

    case AI::State::Dying:
    case AI::State::Resurrected:
      _this->uCurrentActionAnimation = AI::Animation::Dying;
      _this->uAttributes |= 0x200000; break;

    case AI::State::Pursuing:
    case AI::State::Fleeing:
      _this->uCurrentActionAnimation = AI::Animation::Walking;
      _this->uAttributes |= 0x200000; break;

    case AI::State::Stunned:
      _this->uCurrentActionAnimation = AI::Animation::GotHit;
      _this->uAttributes |= 0x200000; break;

    case AI::State::Fidgeting:
      _this->uCurrentActionAnimation = AI::Animation::Bored;
      _this->uAttributes |= 0x200000; break;

    case AI::State::Standing:
    case AI::State::Interacting:
    case AI::State::Summoned:
      _this->uCurrentActionAnimation = AI::Animation::Standing;
      _this->uAttributes |= 0x200000; break;

    case AI::State::Dead:
      if (pSpriteFrameTable->pSpriteSFrames[_this->pSpriteIDs[6]].pSpriteIDs[0] <= 0)
        _this->uAIState = AI::State::Removed;
      else
        _this->uCurrentActionAnimation = AI::Animation::Dead;
  }
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
    _this->pSpriteIDs[i] = SpriteFrameTable_FastFindSprite(pSpriteFrameTable, (char *)pActorDescription->pSpriteNames[i]);
    SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, _this->pSpriteIDs[i]);
  }

  _this->uActorRadius = pActorDescription->uMonsterRadius;
  _this->uActorHeight = pActorDescription->uMonsterHeight;
  _this->uMovementSpeed = pActorInfo->uMovementSpeed;
  if (~a2 & 1)
  {
    for (i = 0; i < 4; ++i)
      _this->pSoundSampleIDs[i] = pActorDescription->pSoundSampleIDs[i];
  }
}

//----- (0040104C) --------------------------------------------------------
signed int Actor_GetActorsRelation(struct Actor *pActor1, struct Actor *pActor2)
{
 // if actor == 0 then party

 // 0: friendly

  int v3;
  int v4;
  int v7;
  int v8;
    
  if (pActor1)
  {   
    if ( pActor1->pActorBuffs[9].qword_000000 > 0i64)
    {
      return 4;
    }

    v3 = pActor1->uMonsterID - 1;
  }
  else
    v3 = 0;
 
  if (pActor2)
  {    
    if ( pActor2->pActorBuffs[9].qword_000000 > 0i64)
    {
      return 4;
    }

    v4 = pActor2->uMonsterID - 1;
  }
  else
    v4 = 0;

  if ( pActor2 && pActor1 )
  {
    int v5 = pActor2->uGroup;
    int v6 = pActor1->uGroup;

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
    if (( pActor1->uAlly > 0 ) && ( pActor1->uAlly != 9999 ))
    {
      v7 = pActor1->uAlly;
    }
    else
    {
      v7 = 0;
    }
    
    if ( pActor1->pActorBuffs[12].qword_000000 > 0i64 )
      v7 = 0;
  }

  if ( pActor2 )
  {    
    if (( pActor2->uAlly > 0 ) && ( pActor2->uAlly != 9999 ))   
    {
      v8 = pActor2->uAlly;       
    }
    else    
    {
      v8 = 0;
    }
    
    if ( pActor2->pActorBuffs[12].qword_000000 > 0i64 )
      v8 = 0;
  }
    
  if ( (pActor1 && (pActor1->pActorBuffs[1].qword_000000 > 0i64) && !v8) || 
       (pActor2 && (pActor2->pActorBuffs[1].qword_000000 > 0i64) && !v7) )
  {
    return 0;
  }

  if ( pActor1 && (pActor1->pActorBuffs[12].qword_000000 <= 0i64) && 
       (pActor1->uAttributes & 0x80000) && !v8 )
  {
    return 4;
  }

  if ( pActor2 && pActor1 && (pActor1->pActorBuffs[12].qword_000000 <= 0i64) && 
       (pActor2->uAttributes & 0x80000))  
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
    if ( (!pActor2 || pActor2->pActorBuffs[12].qword_000000 > 0i64 || !(pActor2->uAttributes & 0x80000)) && 
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
  struct DirectionInfo directionInfo;  
  int x1; 
  int y1;
  int z1;
  unsigned int recoveryTime; 
  short v16;
      
  pActor = &pActors[uActorID];
  if ( (pActor->uMovementType == 5) && (pActor->uAIType == 1) )
  {
    Actor_sub_403EB6(uActorID, a2, 0, pDirectionInfo);
    return;
  }
 
  if ( (a2 & 7) == 3 )
  {      
    x1 = pActors[a2 >> 3].vPosition.x;
    y1 = pActors[a2 >> 3].vPosition.y;
    z1 = (int)((double)pActors[a2 >> 3].uActorHeight * 0.75 + (double)pActors[a2 >> 3].vPosition.z);
  }
  else
  {
    if ( (a2 & 7) == 4 )
    {
      x1 = pParty_global->sPartyPosX;
      y1 = pParty_global->sPartyPosY;
      z1 = pParty_global->sPartyPosZ + pParty_global->uEyelevel;
    }
    else
    {
      //WTF? something illogical happens here
      x1 = (int)pDirectionInfo; 
      y1 = (int)pDirectionInfo;
    }
  }
    
  if ( sub_407A1C(x1, y1, z1, pActor->vPosition.x, pActor->vPosition.y,
                 (int)((double)pActor->uActorHeight * 0.75 + (double)pActor->vPosition.z)) )
  {
    if ( !pDirectionInfo )
    { 
      GetDirectionInfo(8 * uActorID | 3, a2, &directionInfo, 0);      
      pDirectionInfo = &directionInfo;
    }
    
    //v15 = pSpriteFrameTable->pSpriteSFrames;
    //v16 = *(_WORD *)(60 * *(_WORD *)(v3 + 192) + v15 + 56);
    v16 = pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[2]].word_000038;

    pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle);
    pActor->uCurrentActionLength = 8 * v16;
    pActor->uCurrentActionTime = 0;
    pActor->uAIState = AI::State::AttackingMelee;

    Actor_PlaySound(uActorID, 0);

    recoveryTime = pMonsterStats->pMonsterInfos[pActor->uMonsterID - 1].uRecoveryTime;
    if ( pActor->pActorBuffs[SPELLBUFF_FLY].qword_000000 > 0i64 )
    {
      recoveryTime *= 2;   
    }

    if (!pParty_global->bTurnBasedModeOn)
      recoveryTime = (int)(flt_6BE3A8_debug_recmod2 * (double)recoveryTime * 2.133333333333333);

    pActor->uRecoveryTime = recoveryTime;
    pActor->vVelocity = Vec3<short>(0, 0, 0);
    Actor_UpdateAnimation(pActor);
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
  pActor->uCurrentActionLength = 8 * pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[7]].word_000038;

  v7 = class59_Atan2(pClass59_global, 
                  pActor->vPosition.x - pOldCamera->sPosX, 
                  pActor->vPosition.y - pOldCamera->sPosY);
    
  v9 = pClass59_global->uIntegerPi + pActor->uYawAngle + (pClass59_global->uIntegerPi >> 3) - v7;
  
  //if ( BYTE1(v9) & 7 )
  if (v9 & 0x700)
  {
    Actor_sub_403EB6(uActorID, a2, pActor->uCurrentActionLength, pDirectionInfo);
  }
  else
  {
    pActor->uAIState = AI::State::Fidgeting;
    pActor->uCurrentActionTime = 0;
    pActor->vVelocity = Vec3<short>(0, 0, 0);
    
    if ( rand() % 100 < 5 )
      Actor_PlaySound(uActorID, 3);

    Actor_UpdateAnimation(pActor);
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
      pActor->uCurrentActionLength = rand() % 256 + 256;
    else
      pActor->uCurrentActionLength = a3;
      
    pActor->uCurrentActionTime = 0;
    pActor->uAIState = AI::State::Standing;
    pActor->vVelocity = Vec3<short>(0, 0, 0);

    Actor_UpdateAnimation(pActor);
  }
}

  
//----- (00404030) --------------------------------------------------------
void Actor_ProbablyForceToFaceParty(unsigned int uActorID, signed int a2, int a3, struct DirectionInfo *pDirectionInfo)
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
    pActor->uCurrentActionTime = 0;
    pActor->vVelocity = Vec3<short>(0, 0, 0);
    pActor->uPitchAngle = LOWORD(pDirectionInfo->uPitchAngle);
    pActor->uCurrentActionLength = 256;
    pActor->uAIState = AI::State::Interacting;
    Actor_UpdateAnimation(pActor);
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
    GetDirectionInfo(8 * uActorID | 3, a2, &v11, pActor->bFlying);
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
    if (pActor->uMovementSpeed)
      pActor->uCurrentActionLength = (pDirectionInfo->uDistanceXY << 7) / pActor->uMovementSpeed;      
    else
      pActor->uCurrentActionLength = 0;
    
    if (pActor->uCurrentActionLength > 256)
      pActor->uCurrentActionLength = 256;

    pActor->uYawAngle = pClass59_global->uIntegerHalfPi + LOWORD(pDirectionInfo->uYawAngle);
    pActor->uYawAngle = pClass59_global->uDoublePiMask & (pActor->uYawAngle + rand() % pClass59_global->uIntegerPi);

    pActor->uCurrentActionTime = 0;
    pActor->uPitchAngle = LOWORD(pDirectionInfo->uPitchAngle);
    pActor->uAIState = AI::State::Fleeing;
    Actor_UpdateAnimation(pActor);
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
  if (pActor->bFlying && !pParty_global->bFlying)
  {
    if (pActor->uAttack1MissleType && (uCurrentlyLoadedLevelType == 2))
      v4 = pActor->uActorRadius + 512;      
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
    pActor->uCurrentActionLength = a3 + rand() % a3;    
  }
  else
  {    
    if (pActor->uMovementSpeed)
      pActor->uCurrentActionLength = (pDirectionInfo->uDistanceXY << 7) / pActor->uMovementSpeed;
    else
      pActor->uCurrentActionLength = 0;

    if (pActor->uCurrentActionLength > 128)
      pActor->uCurrentActionLength = 128;
  }
  
  if ( rand() % 2 )
    pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle) + 256;
  else
    pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle) - 256;
  
  pActor->uCurrentActionTime = 0;
  pActor->uPitchAngle = LOWORD(pDirectionInfo->uPitchAngle);
  pActor->uAIState = AI::State::Pursuing;
  
  if ( rand() % 100 < 2 )
    Actor_PlaySound(uActorID, 2);

  Actor_UpdateAnimation(pActor);
}


//----- (0040281C) --------------------------------------------------------
void Actor_sub_40281C(unsigned int uActorID, signed int a2, signed int a3, struct DirectionInfo *pDirectionInfo, int a5)
{
  signed int v5;
  struct Actor* pActor;
  struct DirectionInfo v17;
    
  v5 = 0;
  pActor = &pActors[uActorID];
  if (pActor->bFlying && !pParty_global->bFlying)
  {
    if (pActor->uAttack1MissleType && (uCurrentlyLoadedLevelType == 2))
      v5 = pActor->uActorRadius + 512;      
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
    pActor->uCurrentActionLength = a3;
  }
  else
  {
    if (pActor->uMovementSpeed)
      pActor->uCurrentActionLength = (pDirectionInfo->uDistanceXY << 7) / pActor->uMovementSpeed;
    else
      pActor->uCurrentActionLength = 0;

    if (pActor->uCurrentActionLength > 32)
      pActor->uCurrentActionLength = 32;
  }

  pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle);  
  pActor->uCurrentActionTime = 0;
  pActor->uPitchAngle = LOWORD(pDirectionInfo->uPitchAngle);
  pActor->uAIState = AI::State::Pursuing;

  Actor_UpdateAnimation(pActor);
}

//----- (00402AD7) --------------------------------------------------------
void Actor_sub_402AD7(unsigned int uActorID, signed int a2, signed int a3, int a4, struct DirectionInfo *pDirectionInfo)
{
  struct Actor *pActor;
  int v5;
  struct DirectionInfo v14;

  pActor = &pActors[uActorID];
  v5 = 0;

  if (pActor->bFlying && !pParty_global->bFlying)
  {
    if (pActor->uAttack1MissleType)
      v5 = pActor->uActorRadius + 512;
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
  else if (!pActor->uMovementSpeed)
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
    tmpX = pParty_global->sPartyPosX + deltaX - pActor->vPosition.x;
  
    //-sin(pDirectionInfo->uYawAngle + v18)
    tmpSin = class59_SinCos(pClass59_global, v18 + pDirectionInfo->uYawAngle + pClass59_global->uIntegerHalfPi);
    deltaY =  ((unsigned __int64)(tmpSin * pDirectionInfo->uDistanceXY) >> 16);
    tmpY = pParty_global->sPartyPosY + deltaY - pActor->vPosition.y;
    
    pActor->uYawAngle = class59_Atan2(pClass59_global, tmpX, tmpY);
  }

  if (a4)
    pActor->uCurrentActionLength = a4;    
  else
    pActor->uCurrentActionLength = 128;

  pActor->uPitchAngle = LOWORD(pDirectionInfo->uPitchAngle);
  pActor->uAIState = AI::State::Pursuing;
  Actor_UpdateAnimation(pActor);
}

//----- (00403854) --------------------------------------------------------
void Actor_sub_403854(unsigned int uActorID, signed int a2, struct DirectionInfo *pDirectionInfo)
{
  struct Actor *pActor;  
  struct DirectionInfo directionInfo;
  unsigned int recoveryTime;
  int x1;
  int y1;
  int z1;  
  short v13;
    
  pActor = &pActors[uActorID];
  if ( (a2 & 7) == 3 )
  {
    x1 = pActors[a2 >> 3].vPosition.x;
    y1 = pActors[a2 >> 3].vPosition.y;
    z1 = (signed __int64)((double)pActors[a2 >> 3].uActorHeight * 0.75
                         + (double)pActors[a2 >> 3].vPosition.z);
  }
  else
  {
    if ( (a2 & 7) == 4 )
    {
      x1 = pParty_global->sPartyPosX;
      y1 = pParty_global->sPartyPosY;
      z1 = pParty_global->sPartyPosZ + pParty_global->uEyelevel;
    }
    else
    {
      //WTF? something illogical happens here
      x1 = (int)pDirectionInfo;
      y1 = (int)pDirectionInfo;
    }
  }

  if ( sub_407A1C(x1, y1, z1, pActor->vPosition.x, pActor->vPosition.y,
                  pActor->vPosition.z - (int)((double)pActor->uActorHeight * -0.75)) )
  {
    if ( !pDirectionInfo )
    { 
      GetDirectionInfo(8 * uActorID | 3, a2, &directionInfo, 0);      
      pDirectionInfo = &directionInfo;      
    }

    //v12 = pSpriteFrameTable->pSpriteSFrames;
    //v13 = *(_WORD *)(60 * *(_WORD *)(pActor + 194) + v12 + 56);
    v13 = pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[3]].word_000038;

    pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle);        
    pActor->uCurrentActionLength = 8 * v13;
    pActor->uCurrentActionTime = 0;
    pActor->uAIState = AI::State::AttackingRanged3;

    Actor_PlaySound(uActorID, 0);

    recoveryTime = pMonsterStats->pMonsterInfos[pActor->uMonsterID - 1].uRecoveryTime;    
    if ( pActor->pActorBuffs[SPELLBUFF_FLY].qword_000000 > 0i64 )
    {
      recoveryTime *= 2;    
    }
    
    if (pParty_global->bTurnBasedModeOn)
      pActor->uRecoveryTime = recoveryTime;
    else
      pActor->uRecoveryTime = pActor->uCurrentActionLength - 
                             (int)(flt_6BE3A8_debug_recmod2 * (double)recoveryTime * -2.133333333333333); 

    pActor->vVelocity = Vec3<short>(0, 0, 0);

    if ( sub_42FB5C(pActor->uSpell1ID) )
    {
      pActor->uCurrentActionLength = 64;
      pActor->uCurrentActionTime = 0;
      pActor->uAIState = AI::State::Fidgeting;
      Actor_UpdateAnimation(pActor);

      pActor->uAIState = AI::State::AttackingRanged3;
    }
    else
    {
      Actor_UpdateAnimation(pActor);
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
  struct DirectionInfo directionInfo;
  int x1;
  int y1;    
  int z1;
  unsigned int recoveryTime;
  short v13;    
    
  pActor = &pActors[uActorID];  
  if ( (a2 & 7) == 3 )
  {    
    x1 = pActors[a2 >> 3].vPosition.x;
    y1 = pActors[a2 >> 3].vPosition.y;
    z1 = (int)((double)pActors[a2 >> 3].uActorHeight * 0.75
      + (double)pActors[a2 >> 3].vPosition.z);
  }
  else
  {
    if ( (a2 & 7) == 4 )
    {
      x1 = pParty_global->sPartyPosX;
      y1 = pParty_global->sPartyPosY;
      z1 = pParty_global->sPartyPosZ + pParty_global->uEyelevel;
    }
    else
    {
      //WTF? something illogical happens here
      x1 = (int)pDirectionInfo;
      y1 = (int)pDirectionInfo;
    }
  }

  if ( sub_407A1C(x1, y1, z1, pActor->vPosition.x, pActor->vPosition.y,
                  pActor->vPosition.z - (int)((double)pActor->uActorHeight * -0.75)) )
  {
    if ( !pDirectionInfo )
    {
      GetDirectionInfo(8 * uActorID | 3, a2, &directionInfo, 0);      
      pDirectionInfo = &directionInfo;      
    }

    //v12 = pSpriteFrameTable->pSpriteSFrames;
    //v13 = *(_WORD *)(60 * *(_WORD *)(pActor + 194) + v12 + 56);
    v13 = pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[3]].word_000038;

    pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle);    
    pActor->uCurrentActionLength = 8 * v13;
    pActor->uCurrentActionTime = 0;
    pActor->uAIState = AI::State::AttackingRanged2;

    Actor_PlaySound(uActorID, 0);

    recoveryTime = pMonsterStats->pMonsterInfos[pActor->uMonsterID - 1].uRecoveryTime;    
    if ( pActor->pActorBuffs[SPELLBUFF_FLY].qword_000000 > 0i64 )
    {
      recoveryTime *= 2;
    }

    if (!pParty_global->bTurnBasedModeOn)
      pActor->uRecoveryTime = (int)(flt_6BE3A8_debug_recmod2 * (double)recoveryTime * 2.133333333333333);
        
    pActor->vVelocity = Vec3<short>(0, 0, 0);
    Actor_UpdateAnimation(pActor);
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
  struct DirectionInfo directionInfo;
  unsigned int recoveryTime;
  int x1;
  int y1;
  int z1;  
  short v13;

  pActor = &pActors[uActorID];  
  if ( (a2 & 7) == 3 )
  {
    x1 = pActors[a2 >> 3].vPosition.x;
    y1 = pActors[a2 >> 3].vPosition.y;
    z1 = (signed __int64)((double)pActors[a2 >> 3].uActorHeight * 0.75
                         + (double)pActors[a2 >> 3].vPosition.z);
  }
  else
  {
    if ( (a2 & 7) == 4 )
    {
      x1 = pParty_global->sPartyPosX;
      y1 = pParty_global->sPartyPosY;
      z1 = pParty_global->sPartyPosZ + pParty_global->uEyelevel;
    }
    else
    {
      //WTF? something illogical happens here
      x1 = (int)pDirectionInfo;
      y1 = (int)pDirectionInfo;
    }
  }

  if ( sub_407A1C(x1, y1, z1, pActor->vPosition.x, pActor->vPosition.y,
                 pActor->vPosition.z - (int)((double)pActor->uActorHeight * -0.75)) 
       ||
       sub_407A1C(pActor->vPosition.x, pActor->vPosition.y,
                  pActor->vPosition.z - (int)((double)pActor->uActorHeight * -0.75),
                  x1, y1, z1) )
  {
    if ( !pDirectionInfo )
    {
      GetDirectionInfo(8 * uActorID | 3, a2, &directionInfo, 0);
      pDirectionInfo = &directionInfo; 
    }

    //v12 = pSpriteFrameTable->pSpriteSFrames;
    //v13 = *(_WORD *)(60 * *(_WORD *)(pActor + 194) + v12 + 56);
    v13 = pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[3]].word_000038;

    pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle);
    pActor->uCurrentActionLength = 8 * v13;
    pActor->uCurrentActionTime = 0;
    pActor->uAIState = AI::State::AttackingRanged1;

    Actor_PlaySound(uActorID, 0);

    recoveryTime = pMonsterStats->pMonsterInfos[pActor->uMonsterID - 1].uRecoveryTime;    
    if ( pActor->pActorBuffs[SPELLBUFF_FLY].qword_000000 > 0i64 )
    {
      recoveryTime *= 2;    
    }

    if (pParty_global->bTurnBasedModeOn)
      pActor->uRecoveryTime = recoveryTime;
    else
      pActor->uRecoveryTime = pActor->uCurrentActionLength - 
                             (int)(flt_6BE3A8_debug_recmod2 * (double)recoveryTime * -2.133333333333333);
    pActor->vVelocity = Vec3<short>(0, 0, 0);
    Actor_UpdateAnimation(pActor);
  }
  else
    Actor_sub_402AD7(uActorID, a2, uActorID, 64, pDirectionInfo);
}

//----- (00403A60) --------------------------------------------------------
void Actor_sub_403A60(unsigned int uActorID, signed int a2, struct DirectionInfo *pDirectionInfo)
{
  struct Actor *pActor; 
  struct DirectionInfo directionInfo;  
  unsigned int recoveryTime;
  int x1;
  int y1;  
  int z1;
  short v13;  

  pActor = &pActors[uActorID];
  if ( (a2 & 7) == 3 )
  {
    x1 = pActors[a2 >> 3].vPosition.x;
    y1 = pActors[a2 >> 3].vPosition.y;
    z1 = (signed __int64)((double)pActors[a2 >> 3].uActorHeight * 0.75
                         + (double)pActors[a2 >> 3].vPosition.z);
  }
  else
  {
    if ( (a2 & 7) == 4 )
    {
      x1 = pParty_global->sPartyPosX;
      y1 = pParty_global->sPartyPosY;
      z1 = pParty_global->sPartyPosZ + pParty_global->uEyelevel;
    }
    else
    {
      //WTF? something illogical happens here
      x1 = (int)pDirectionInfo;
      y1 = (int)pDirectionInfo;
    }
  }

  if ( sub_407A1C(x1, y1, z1, pActor->vPosition.x, pActor->vPosition.y,
                  pActor->vPosition.z - (int)((double)pActor->uActorHeight * -0.75)) )
  {
    if ( !pDirectionInfo )
    {
      GetDirectionInfo(8 * uActorID | 3, a2, &directionInfo, 0);      
      pDirectionInfo = &directionInfo;
    }

    //v12 = pSpriteFrameTable->pSpriteSFrames;
    //v13 = *(_WORD *)(60 * *(_WORD *)(pActor + 194) + v12 + 56);
    v13 = pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[3]].word_000038;

    pActor->uYawAngle = LOWORD(pDirectionInfo->uYawAngle);
    pActor->uCurrentActionLength = 8 * v13;
    pActor->uCurrentActionTime = 0;
    pActor->uAIState = AI::State::AttackingRanged4;

    Actor_PlaySound(uActorID, 0);

    recoveryTime = pMonsterStats->pMonsterInfos[pActor->uMonsterID - 1].uRecoveryTime;    
    if ( pActor->pActorBuffs[SPELLBUFF_FLY].qword_000000 > 0i64 )
    {
      recoveryTime *= 2;    
    }

    if (pParty_global->bTurnBasedModeOn)
      pActor->uRecoveryTime = recoveryTime;
    else
      pActor->uRecoveryTime = pActor->uCurrentActionLength - 
                             (int)(flt_6BE3A8_debug_recmod2 * (double)recoveryTime * -2.133333333333333);
    pActor->vVelocity = Vec3<short>(0, 0, 0);

    if ( sub_42FB5C(pActor->uSpell2ID) )
    {
      pActor->uCurrentActionLength = 64;
      pActor->uCurrentActionTime = 0;
      pActor->uAIState = AI::State::Fidgeting;
      Actor_UpdateAnimation(pActor);

      pActor->uAIState = AI::State::AttackingRanged4;
    }
    else
    {
      Actor_UpdateAnimation(pActor);
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

  deltaX = pActor->vInitialPosition.x - pActor->vPosition.x;
  deltaY = pActor->vInitialPosition.y - pActor->vPosition.y;
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
  if ( pActor->uMovementType == 3 && v20 < 128 )
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
  if ( abs(v11 - pActor->uYawAngle) > 256 && !(pActor->uAttributes & 0x00200000) )
  {
    Actor_sub_403EB6(uActorID, a2, 256, &v15);
    return;
  }

  pActor->uYawAngle = v11;

  if (pActor->uMovementSpeed)
    pActor->uCurrentActionLength = 32 * v20 / pActor->uMovementSpeed;
  else
    pActor->uCurrentActionLength = 0;

  pActor->uCurrentActionTime = 0;
  pActor->uAIState = AI::State::Tethered;  
  
  if ( rand() % 100 < 2 )
    Actor_PlaySound(uActorID, 3);

  Actor_UpdateAnimation(pActor);
}

//----- (00402CED) --------------------------------------------------------

//soundID (0-4): 
//1 - die sound
void Actor_PlaySound(unsigned int uActorID, int soundId)
{
  struct Actor *pActor;
  signed int v8;
  int v12;

  pActor = &pActors[uActorID];  
  if ( pActor->pSoundSampleIDs[soundId] )
  {
    if ( pActor->pActorBuffs[3].qword_000000 <= 0i64 )
    {
      v12 = 0;
      v8 = -1;
    }
    else
    {
      switch (pActor->pActorBuffs[3].word_000008)
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
    
    pAudioPlayer->sub_4AA306(pActor->pSoundSampleIDs[soundId], (uActorID * 8) | 3, 0, v8, 0, 0, 0, v12);
  }
}

//----- (00402D6E) --------------------------------------------------------
void Actor_Die(unsigned int uActorID)
{  
  unsigned short monsterID;  
  struct ItemGen itemGen;
  struct Actor *pActor;
  int i;

  pActor = &pActors[uActorID];
      
  pActor->uAIState = AI::State::Dying;
  pActor->uCurrentActionAnimation = AI::Animation::Dying;
  pActor->uCurrentActionTime = 0;  
  pActor->sCurrentHP = 0;
  pActor->uCurrentActionLength = 8 * pSpriteFrameTable->pSpriteSFrames[pActor->pSpriteIDs[5]].word_000038;
  
  SpellBuff_sub_458585(&pActor->pActorBuffs[6]);
  SpellBuff_sub_458585(&pActor->pActorBuffs[SPELLBUFF_FEATHERFALL]);

  Actor_PlaySound(uActorID, 1);
  Actor_UpdateAnimation(pActor);

  monsterID = pActor->uMonsterID - 1;  
  for (i = 0; i < 5; ++i)
  {
    if ( monsterID == pParty_global->array_000750[i] )
      pParty_global->array_00075A[i] = 1;
  }
  
  for (i = 0; i < 22; ++i)
    SpellBuff_sub_458585(&pActor->pActorBuffs[i]);

  ItemGen_Reset((ItemGen *)&itemGen);
  
  if (monsterID >= 20 && monsterID <= 22) //devil worker, devil warrior, devil captain
  {
    itemGen.uItemID = 214;  //Vial of Devil Ichor
  }
  else if (monsterID >= 24 && monsterID <= 26) //green dragon, blue dragon, red dragon
  {
    itemGen.uItemID = 204; //Dragon's Eye
  }
  else if (monsterID >= 84  && monsterID <= 86) //harpy, harpy hag, harpy queen
  {
    itemGen.uItemID = 207;  //Harpy Feather
  }
  else if (monsterID >= 111 && monsterID <= 113) //emerald ooze, sapphire ooze, bloodstone ooze
  {
    itemGen.uItemID = 217; //Vial of Ooze Endoplasm
  }
  else if (monsterID >= 249 && monsterID <= 251) //swamp troll, river troll, mountain troll
  {
    itemGen.uItemID = 202; //Vial of Troll Blood
  }

  if ( itemGen.uItemID )
  {
    if ( (rand() % 100) < 20 )
    {
      sub_42F7EB_DropItemAt((unsigned __int16)word_5D29F8[24 * itemGen.uItemID],
        pActor->vPosition.x,
        pActor->vPosition.y,
        pActor->vPosition.z + 16,
        rand() % 200 + 200,
        1,
        1,
        0,
        &itemGen);
    }
  }

  if ( pActor->uSpecialAttackType == 3 )
    sub_404736(uActorID);
}

//----- (00401221) --------------------------------------------------------
__int16 __fastcall sub_401221(unsigned int uActorID, int a2, int a3)
{
  int v3; // eax@1
  int v4; // ecx@1
  int v5; // ebx@1
  int v6; // esi@1
  int v7; // edi@2
  int v8; // eax@10
  int v9; // ebx@16
  int v12; // edi@43
  int v13; // ebx@45
  int v14; // ecx@48
  int v16; // [sp+Ch] [bp-24h]@16
  int v17; // [sp+10h] [bp-20h]@1
  int v18; // [sp+14h] [bp-1Ch]@1
  int v19; // [sp+18h] [bp-18h]@1
  int v20; // [sp+1Ch] [bp-14h]@16
  int v21; // [sp+20h] [bp-10h]@1
  int v22; // [sp+24h] [bp-Ch]@1
  int v23; // [sp+28h] [bp-8h]@1
  int v24; // [sp+2Ch] [bp-4h]@16
  int v25; // [sp+2Ch] [bp-4h]@45

  v22 = -1;
  v19 = uActorID;
  v6 = (int)&pActors[uActorID];
  v5 = 0;
  v4 = 0;
  v3 = *(_DWORD *)(v6 + 816);
  *(_DWORD *)a2 = 0;
  v17 = a2;
  v18 = 0;
  v21 = v3;
  v23 = 0;

  if (uNumActors > 0)
  {
    v7 = (int)&pActors[0].uAIState;
    while ( 1 )
    {
      v7 = (int)&pActors[v23].uAIState;

      LOWORD(v3) = pActors[v23].uAIState;
      if (pActors[v23].uAIState == AI::State::Dying ||
          pActors[v23].uAIState == AI::State::Dead ||
          pActors[v23].uAIState == AI::State::Removed ||
          pActors[v23].uAIState == AI::State::Summoned ||
          pActors[v23].uAIState == AI::State::Disabled ||
          v19 == v4 )
        goto LABEL_23;

      if ( v21 != v5 )
      {
        v8 = 8 * v4;
        LOBYTE(v8) = 8 * v4 | 3;
        if ( v21 == v8 )
        {
          if ( sub_4089C7((int)&pActors[v23]) != 1 )
          {
            v3 = *(_DWORD *)(v7 + 532);
            if ( (v3 != v5 || *(_DWORD *)(v6 + 708) != v5) && v3 == *(_DWORD *)(v6 + 708) )
              goto LABEL_23;
            v3 = 4;
LABEL_14:
            if ( *(_BYTE *)(v6 + 61) )
              v3 = pMonsterStats->pMonsterInfos[pActors[uActorID].uMonsterID - 1].byte_000011;
            v9 = dword_4DF380[v3];
            v20 = abs(pActors[uActorID].vPosition.x - pActors[v23].vPosition.x);
            v24 = abs(pActors[uActorID].vPosition.y - pActors[v23].vPosition.y);
            v3 = abs(pActors[uActorID].vPosition.z - pActors[v23].vPosition.z);
            v16 = v3;
            if ( v20 <= v9 )
            {
              if ( v24 <= v9 )
              {
                if ( v3 <= v9 )
                {
                  v3 = sub_4070EF(8 * v23 | 3, 8 * v19 | 3);
                  if ( v3 )
                  {
                    v3 = v20 * v20 + v24 * v24 + v16 * v16;
                    if ( v3 < (unsigned int)v22 )
                    {
                      v22 = v20 * v20 + v24 * v24 + v16 * v16;
                      LOWORD(v3) = v23;
                      v18 = v23;
                    }
                  }
                }
              }
            }
            v5 = 0;
            goto LABEL_23;
          }
          v21 = v5;
          *(_DWORD *)(v6 + 816) = v5;
        }
      }
      v3 = Actor_GetActorsRelation(&pActors[uActorID], &pActors[v23]);
      if ( v3 != v5 )
        goto LABEL_14;
LABEL_23:
      v7 += 836;
      v4 = v23 + 1;
      //v11 = __SETO__(v23 + 1, uNumActors);
      //v10 = (signed int)(v23++ + 1 - uNumActors) < 0;
      if (++v23 >= uNumActors)
      {
        if ( v22 != -1 )
        {
          v3 = 8 * v18;
          LOBYTE(v3) = 8 * v18 | 3;
          *(_DWORD *)v17 = v3;
        }
        break;
      }
    }
  }



  if ( HIDWORD(pParty_global->pPartyBuffs[11].qword_000000) >= v5 )
  {
   if ( HIDWORD(pParty_global->pPartyBuffs[11].qword_000000) > v5 || (_DWORD)pParty_global->pPartyBuffs[11].qword_000000 > (unsigned int)v5 )
      a3 = v5;
  }
  if ( a3 != v5 )
  {
    v3 = Actor_GetActorsRelation((Actor *)v6, 0);
    if ( *(_BYTE *)(v6 + 38) & 8 )
    {
      if ( *(_DWORD *)(v6 + 408) <= v5 )
      {
        if ( *(_DWORD *)(v6 + 408) < v5 || *(_DWORD *)(v6 + 404) <= (unsigned int)v5 )
        {
          if ( *(_DWORD *)(v6 + 232) <= v5 )
          {
            if ( *(_DWORD *)(v6 + 232) < v5 || *(_DWORD *)(v6 + 228) <= (unsigned int)v5 )
            {
              if ( *(_DWORD *)(v6 + 248) <= v5 )
              {
                if ( *(_DWORD *)(v6 + 248) < v5 || *(_DWORD *)(v6 + 244) <= (unsigned int)v5 )
                  v3 = 4;
              }
            }
          }
        }
      }
    }
    if ( v3 != v5 )
    {
      v12 = dword_4DF390;
      if ( !*(_BYTE *)(v6 + 61) )
        v12 = dword_4DF380[v3];
      v13 = abs(*(_WORD *)(v6 + 142) - pParty_global->sPartyPosX);
      v25 = abs(*(_WORD *)(v6 + 144) - pParty_global->sPartyPosY);
      v3 = abs(*(_WORD *)(v6 + 146) - pParty_global->sPartyPosZ);
      if ( v13 <= v12 )
      {
        if ( v25 <= v12 )
        {
          if ( v3 <= v12 )
          {
            v14 = v25 * v25 + v3 * v3;
            LOWORD(v3) = v13 * v13;
            if ( v13 * v13 + v14 < (unsigned int)v22 )
            {
              LOWORD(v3) = v17;
              *(_DWORD *)v17 = 4;
            }
          }
        }
      }
    }
  }
  return v3;
}

//----- (0041F4C1) --------------------------------------------------------
void Actor_TotalReset(struct Actor *_this)
{
 int i;

 for (i = 0; i < 22; ++i)
 {
  _this->pActorBuffs[i].qword_000000 = 0i64;  
  _this->pActorBuffs[i].word_000008 = 0;
  _this->pActorBuffs[i].word_00000A = 0;
  _this->pActorBuffs[i].byte_00000E = 0;
  _this->pActorBuffs[i].byte_00000F = 0;
 }

 for (i = 0; i < 4; ++i)
   ItemGen_Reset((ItemGen *)&_this->array_000234[i]);

 Actor_Reset(_this);
}


//----- (00459671) --------------------------------------------------------
void Actor_Reset(struct Actor *_this)
{
 _this->pActorName[0] = 0;

 _this->uNPCID = -1;
 _this->uAttributes = 0;
 
 _this->word_000086_some_monster_id = 0;
 _this->uActorRadius = 32;
 _this->uActorHeight = 128;
 _this->uMovementSpeed = 200;

 _this->vPosition = Vec3<short>(0, 0, 0);
 
 _this->vVelocity = Vec3<short>(0, 0, 0);
 _this->uYawAngle = 0;
 _this->uPitchAngle = 0;
 _this->sRoom = 0;

 _this->vInitialPosition = Vec3<short>(0, 0, 0); 
 _this->vGuardingPosition = Vec3<short>(0, 0, 0);
 _this->uTetherDistance = 256;
 _this->uAIState = AI::State::Standing;
 _this->uCurrentActionAnimation = AI::Animation::Standing;
 _this->uCarriedItemID = -1;
 _this->uCurrentActionTime = 0;

 memset(_this->pSpriteIDs, 0, 8 * sizeof(unsigned short));

 _this->uGroup = 0;
 _this->uAlly = 0;

 _this->uSummonerID = 0;
 _this->uLastCharacterIDToHit = 0;
 _this->dword_000334_unique_name = 0;

 memset(_this->pActorBuffs, 0, 22 * sizeof(struct SpellBuff));
}

//----- (0047F2D3) --------------------------------------------------------
bool InitializeActors(struct MapInfo *pMapInfo)
{
  int          i;
  struct Actor v6;
  int v8; // [sp+348h] [bp-8h]@1

  v8 = 0;
  for (i = 0; i < uNumActors; ++i)
  {
    bool bIsSomeFlagSet = pActors[i].uAttributes & 0x100000;
    if ( (!bIsSomeFlagSet && v8 != 1) || v8 != 0 )
    {
      pActors[i].uCurrentActionTime = 0;
      pActors[i].uCurrentActionLength = 0;
      if ( pActors[i].uAttributes & 0x10000 )
        pActors[i].uAIState == AI::State::Disabled;

      if (pActors[i].uAIState != AI::State::Removed && pActors[i].uAIState != AI::State::Disabled)
      {
        if (!pActors[i].sCurrentHP || !pActors[i].sTotalHP)
          pActors[i].uAIState = AI::State::Dead;
      }
      pActors[i].vVelocity = Vec3<short>(0, 0, 0);
      Actor_UpdateAnimation(&pActors[i]);
      pActors[i].uHostilityType = 0;

      Actor_LinkSprites(&pActors[i], 0);
    }
    else
    {
      pActors[i].uAIState = AI::State::Disabled;
      pActors[i].uAttributes |= 0x10000;
      if (bIsSomeFlagSet && !v8)
      {
        v8 = sub_450DA3();
      }
    }
  }

  runtime_warning();
  //LevelLoadingUI_UpdateAndDrawProgressBar(pGameLoadingUI_ProgressBar);

  Actor_TotalReset(&v6);
  v6.uMonsterID = 45;

  //initialize light elemental, probably since it's not on the map but can be summoned at any time

  //[inviZ_khv] WTF? v6 is local variable and it's destroyed when function returns
  Actor_LinkSprites(&v6, 0);
  return true;
}