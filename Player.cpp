#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "defs.h"
#include "_lod.h"
#include "RenderD3D3.h"
#include "Level.h"
#include "FrameTables.h"
#include "AudioPlayer.h"

#include "data.h"





// 4 races, 7 stats
struct StatTable g_StatTable[4][7] = // byte[] @ MM7.exe::004ED7B0
{
  {{11, 25, 1, 1}, {11, 25, 1, 1}, {11, 25, 1, 1}, { 9, 25, 1, 1}, {11, 25, 1, 1}, {11, 25, 1, 1}, {9, 25, 1, 1},},
  {{ 7, 15, 2, 1}, {14, 30, 1, 2}, {11, 25, 1, 1}, { 7, 15, 2, 1}, {14, 30, 1, 2}, {11, 25, 1, 1}, {9, 20, 1, 1},},
  {{14, 30, 1, 2}, { 7, 15, 2, 1}, { 7, 15, 2, 1}, {11, 25, 1, 1}, {11, 25, 1, 1}, {14, 30, 1, 2}, {9, 20, 1, 1},},
  {{14, 30, 1, 2}, {11, 25, 1, 1}, {11, 25, 1, 1}, {14, 30, 1, 2}, { 7, 15, 2, 1}, { 7, 15, 2, 1}, {9, 20, 1, 1}}
};

 // available skills per class ( 9 classes X 37 skills )
 // 0 - not available
 // 1 - available
 // 2 - primary skill
unsigned char AvailSkillPerClass[9][37] =  // byte[] @ MM7.exe::004ED820
{
  {0, 2, 0, 1, 1, 1, 1, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
  {0, 1, 2, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 2, 1, 0},
  {1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 2, 2, 1, 1, 0, 0, 0},
  {0, 1, 1, 1, 0, 0, 2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
  {0, 1, 0, 1, 1, 2, 0, 0, 0, 1, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
  {0, 1, 1, 2, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 2, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 2, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 2, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
  {2, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0} // some of these are started at 4ED94C, but needs to be here
};


//----- (0048D6AA) --------------------------------------------------------
bool Player_sub_48D6AA(struct Player *_this, unsigned int uSlotID)
{
  int v2; // eax@1

 v2 = _this->pEquippedItemIndices[uSlotID];
 if (v2 == -1)
   return false;

 return !(_this->pInventorySlots[v2].dword_000014 & 0x02);
 //return !(*((_BYTE *)_this + 36 * v2 + 0x204) & 2);
}


//----- (0049024A) --------------------------------------------------------
void Player_Reset(struct Player *_this, unsigned int uDesiredClass)
{
 _this->uExperience = rand() % 100 + 251;

 _this->uClass = uDesiredClass;
 _this->uStrengthBonus = 0;
 _this->uIntelligenceBonus = 0;
 _this->uWillpowerBonus = 0;
 _this->uEnduranceBonus = 0;
 _this->uSpeedBonus = 0;
 _this->uAccuracyBonus = 0;
 _this->uLuckBonus = 0;
 _this->uLevelBase = 1;

 _this->uBirthYear = 1147 - rand() % 6;
 memset(_this->pActiveSkills, 0, 37 * sizeof(short));
 memset(_this->array_000152, 0, 0x40);

 memset(&_this->cFireSpellbook, 0, sizeof(struct Spellbook));
 memset(&_this->cAirSpellbook, 0, sizeof(struct Spellbook));
 memset(&_this->cWaterSpellbook, 0, sizeof(struct Spellbook));
 memset(&_this->cEarthSpellbook, 0, sizeof(struct Spellbook));
 memset(&_this->cSpiritSpellbook, 0, sizeof(struct Spellbook));
 memset(&_this->cMindSpellbook, 0, sizeof(struct Spellbook));
 memset(&_this->cBodySpellbook, 0, sizeof(struct Spellbook));
 memset(&_this->cLightSpellbook, 0, sizeof(struct Spellbook));
 memset(&_this->cDarkSpellbook, 0, sizeof(struct Spellbook));

 memset(_this->array_0001F5, 0, 31);

 for (unsigned int i = 0; i < 37; ++i)
 {
  if (AvailSkillPerClass[_this->uClass / 4][i] == 2)
  {
   _this->pActiveSkills[i] = 1;
      if ( (unsigned int)(i - 12) <= 8 )
      {
        switch (i)
        {
         case Character::Skill::Fire:   _this->cFireSpellbook.bIsSpellbookAvailable = true;   break;
         case Character::Skill::Air:    _this->cAirSpellbook.bIsSpellbookAvailable = true;    break;
         case Character::Skill::Water:  _this->cWaterSpellbook.bIsSpellbookAvailable = true;  break;
         case Character::Skill::Earth:  _this->cEarthSpellbook.bIsSpellbookAvailable = true;  break;
         case Character::Skill::Spirit: _this->cSpiritSpellbook.bIsSpellbookAvailable = true; break;
         case Character::Skill::Mind:   _this->cMindSpellbook.bIsSpellbookAvailable = true;   break;
         case Character::Skill::Body:   _this->cBodySpellbook.bIsSpellbookAvailable = true;   break;
         case Character::Skill::Light:  _this->cLightSpellbook.bIsSpellbookAvailable = true;  break;
         case Character::Skill::Dark:   _this->cDarkSpellbook.bIsSpellbookAvailable = true;   break;
        }
      }
    }
  }

 _this->sHealth = Player_GetMaxHealth(_this);
 _this->sMana = Player_GetMaxMana(_this);
}

//----- (0048D6D0) --------------------------------------------------------
bool Player_sub_48D6D0(struct Player *_this, int a2)
{
  int v2; // esi@1
  int v3; // edx@2

  v2 = 0;
  while (!Player_sub_48D6AA(_this, v2) || *((int *)((char *)_this + 0x2FC) + 9 * _this->pEquippedItemIndices[v2]) != a2)
  {
    ++v2;
    if ( v2 >= 16 )
      return false;
  }
  return true;
}


//----- (004903C9) --------------------------------------------------------
signed int __thiscall GetSkillIdxByOrder(struct Player *_this, int Order)
{
  signed int i; // eax@5
  int v3; // edx@5
  char *v4; // ecx@5
  int v6; // esi@11
  int v8; // esi@18
  int skidx = 0;

  if ( Order >= 0 )
  {
    if ( Order <= 1 )
    {
      v8 = 0;
      
      for (i = 0; i < 37; ++i)
      {
        if ( _this->pActiveSkills[skidx] &&  AvailSkillPerClass[_this->uClass >> 2][i] == 2 )
        {
          if ( v8 == Order )
            return i;
          ++v8;
        }
        skidx++;
      }
    }
    else
    {
      if ( Order <= 3 )
      {

        v6 = 0;
        for (i = 0; i < 37; ++i)
        {
          if ( _this->pActiveSkills[skidx] && AvailSkillPerClass[_this->uClass >> 2][i] == 1 )
          {
            if ( v6 == Order - 2 )
              return i;
            ++v6;
          }
          skidx++;
        }
      }
      else
      {
        if ( Order <= 12 )
        {
          v3 = 0;
          v4 = (char *)&AvailSkillPerClass[_this->uClass >> 2];
          for (i = 0; i < 37; ++i)
          {
            if ( *v4 == 1 )
            {
              if ( v3 == Order - 4 )
                return i;
              ++v3;
            }
            ++v4;
          }
        }
      }
    }
  }
  return 37;
}

//----- (00490188) --------------------------------------------------------
__int16 Player_SetInitialStats(struct Player *_this)
{
  int r = Player_GetRace(_this);
  _this->uStrength = g_StatTable[r][0].InitialStat;
  _this->uIntelligence = g_StatTable[r][1].InitialStat;
  _this->uWillpower = g_StatTable[r][2].InitialStat;
  _this->uEndurance = g_StatTable[r][3].InitialStat;
  _this->uSpeed = g_StatTable[r][5].InitialStat;
  _this->uAccuracy = g_StatTable[r][4].InitialStat;
  _this->uLuck = g_StatTable[r][6].InitialStat;
  return g_StatTable[r][6].InitialStat;
}

//----- (0048E9B7) --------------------------------------------------------
void Player_RandomizeName(struct Player *_this)
{
 if (!_this->word_001A9E)
   lstrcpyA((char *)_this->sName, (char *)pNPCStats->pNPCNames[rand() % pNPCStats->uNumNPCNames[_this->uSex]][_this->uSex]);
}

//----- (00490109) --------------------------------------------------------
int Player_GetRace(struct Player *_this)
{
 /*faces are:  0  1  2  3   human males
               4  5  6  7   human females
                     8  9   elf males
                    10 11   elf females
                    12 13   dwarf males
                    14 15   dwarf females
                    16 17   goblin males
                    18 19   goblin females
                       20   lich male
                       21   lich female
                       22   underwater suits (unused)
                       23   zombie male
                       24   zombie female
              */

 if (_this->uFace >= 0 && _this->uFace <= 7)
   return Character::Race::Human;
 else if (_this->uFace > 7 && _this->uFace <= 11)
   return Character::Race::Elf;
 else if (_this->uFace > 11 && _this->uFace <= 15)
   return Character::Race::Dwarf;
 else if (_this->uFace > 15 && _this->uFace <= 19)
   return Character::Race::Goblin;
 else if (_this->uFace > 19 && _this->uFace <= 25)
   return Character::Race::Undead;

 return -1;
}

int Player_GetSex(struct Player *_this)
{
 if (_this->uFace < 4 || _this->uFace == 8 || _this->uFace == 9 || _this->uFace == 12 || _this->uFace == 13 ||
     _this->uFace == 16 || _this->uFace == 17 || _this->uFace == 20 || _this->uFace == 23)
   return 0;

 return 1;
}

//----- (0048C855) --------------------------------------------------------
int __thiscall Player_GetBaseStrength(struct Player *_this)
{
  return _this->uStrength + Player_MaybeGetWearItemsBonus(_this, 0, 0);
}

//----- (0048C86C) --------------------------------------------------------
int __thiscall Player_GetBaseIntelligence(struct Player *_this)
{
  return _this->uIntelligence + Player_MaybeGetWearItemsBonus(_this, 1, 0);
}

//----- (0048C883) --------------------------------------------------------
int __thiscall Player_GetBaseWillpower(struct Player *_this)
{
  return _this->uWillpower + Player_MaybeGetWearItemsBonus(_this, 2, 0);
}

//----- (0048C89A) --------------------------------------------------------
int __thiscall Player_GetBaseEndurance(struct Player *_this)
{
  return _this->uEndurance + Player_MaybeGetWearItemsBonus(_this, 3, 0);
}

//----- (0048C8B1) --------------------------------------------------------
int __thiscall Player_GetBaseAccuracy(struct Player *_this)
{
  return _this->uAccuracy + Player_MaybeGetWearItemsBonus(_this, 4, 0);
}

//----- (0048C8C8) --------------------------------------------------------
int __thiscall Player_GetBaseSpeed(struct Player *_this)
{
  return _this->uSpeed + Player_MaybeGetWearItemsBonus(_this, 5, 0);
}

//----- (0048C8DF) --------------------------------------------------------
int __thiscall Player_GetBaseLuck(struct Player *_this)
{
  return _this->uLuck + Player_MaybeGetWearItemsBonus(_this, 6, 0);
}

//----- (0048C8F6) --------------------------------------------------------
int __thiscall Player_GetBaseLevel(struct Player *_this)
{
  return _this->uLevelBase + Player_MaybeGetWearItemsBonus(_this, 24, 0);
}

//----- (0048C93C) --------------------------------------------------------
int Player_GetActualStrength(struct Player *_this)
{
  int v1; // eax@1
  signed int v2; // ecx@1
  signed int v4; // ebx@4
  int v6; // edi@5
  int v7; // ST14_4@5

  v1 = Player_GetActualAge(_this);
  v2 = 0;
  while ( v1 >= uAgeingTable[v2] )
  {
    ++v2;
    if ( v2 >= 4 )
    {
      v4 = 100;
      goto LABEL_5;
    }
  }
  v4 = uAgeingStrengthMultiplier[v2];
LABEL_5:
  v6 = uConditionStrengthMultiplier[Player_GetConditionIdx(_this)];
  v7 = Player_MaybeGetWearItemsBonus(_this, 0, 0);
  return v6 * v4 * _this->uStrength / 100 / 100 + Player_MaybeGetCastSpellBonus(_this, 0) + v7 + _this->uStrengthBonus;
}

//----- (0048CABC) --------------------------------------------------------
int Player_GetActualEndurance(struct Player *_this)
{
  int v1; // eax@1
  signed int v2; // ecx@1
  signed int v4; // ebx@4
  int v6; // edi@5
  int v7; // ebp@5

  v1 = Player_GetActualAge(_this);
  v2 = 0;
  while ( v1 >= uAgeingTable[v2] )
  {
    ++v2;
    if ( v2 >= 4 )
    {
      v4 = 100;
      goto LABEL_5;
    }
  }
  v4 = uAgeingEnduranceMultiplier[v2];
LABEL_5:
  v6 = uConditionEnduranceMultiplier[Player_GetConditionIdx(_this)];
  v7 = Player_MaybeGetWearItemsBonus(_this, 3, 0);
  return v6 * v4 * _this->uEndurance / 100 / 100 + Player_MaybeGetCastSpellBonus(_this, 3) + v7 + _this->uEnduranceBonus;
}

//----- (0048C90D) --------------------------------------------------------
int Player_GetActualLevel(struct Player *_this)
{
  return Player_GetBaseLevel(_this) + _this->uLevelModifier + Player_MaybeGetCastSpellBonus(_this, 24);
}

//----- (0048E72C) --------------------------------------------------------
int Player_GetActualAge(struct Player *_this)
{
  return Player_GetBaseAge(_this) + _this->sAgeModifier;
}

//----- (0048E6DC) --------------------------------------------------------
int Player_GetBaseAge(struct Player *_this)
{
  double d = pParty_global->qword_00002C;
  return (signed int)((unsigned int)((signed __int64)(d * 0.234375) / 60 / 60) / 24) / 7 / 4 / 12
       - _this->uBirthYear + 1168;
}

//----- (0048C9C2) --------------------------------------------------------
int __thiscall Player_GetActualIntelligence(struct Player *_this)
{
  int v1; // eax@1
  signed int v2; // ecx@1
  signed int v4; // ebx@4
  int v6; // edi@5
  int v7; // ebp@5

  v1 = Player_GetActualAge(_this);
  v2 = 0;
  while ( v1 >= uAgeingTable[v2] )
  {
    ++v2;
    if ( v2 >= 4 )
    {
      v4 = 100;
      goto LABEL_5;
    }
  }
  v4 = uAgeingIntelligenceMultiplier[v2];
LABEL_5:
  v6 = uConditionIntelligenceMultiplier[Player_GetConditionIdx(_this)];
  v7 = Player_MaybeGetWearItemsBonus(_this, 1, 0);
  return v6 * v4 * _this->uIntelligence / 100 / 100 + Player_MaybeGetCastSpellBonus(_this, 1) + v7 + _this->uIntelligenceBonus;
}

//----- (0048CA3F) --------------------------------------------------------
int __thiscall Player_GetActualWillpower(struct Player *_this)
{
  int v1; // eax@1
  signed int v2; // ecx@1
  signed int v4; // ebx@4
  int v6; // edi@5
  int v7; // ebp@5

  v1 = Player_GetActualAge(_this);
  v2 = 0;
  while ( v1 >= uAgeingTable[v2] )
  {
    ++v2;
    if ( v2 >= 4 )
    {
      v4 = 100;
      goto LABEL_5;
    }
  }
  v4 = uAgeingWillpowerMultiplier[v2];
LABEL_5:
  v6 = uConditionWillpowerMultiplier[Player_GetConditionIdx(_this)];
  v7 = Player_MaybeGetWearItemsBonus(_this, 2, 0);
  return v6 * v4 * _this->uWillpower / 100 / 100 + Player_MaybeGetCastSpellBonus(_this, 2) + v7 + _this->uWillpowerBonus;
}

//----- (0048CB39) --------------------------------------------------------
int __thiscall Player_GetActualAccuracy(struct Player *_this)
{
  int v1; // eax@1
  signed int v2; // ecx@1
  signed int v4; // ebx@4
  int v6; // edi@5
  int v7; // ebp@5

  v1 = Player_GetActualAge(_this);
  v2 = 0;
  while ( v1 >= uAgeingTable[v2] )
  {
    ++v2;
    if ( v2 >= 4 )
    {
      v4 = 100;
      goto LABEL_5;
    }
  }
  v4 = uAgeingAccuracyMultiplier[v2];
LABEL_5:
  v6 = uConditionAccuracyMultiplier[Player_GetConditionIdx(_this)];
  v7 = Player_MaybeGetWearItemsBonus(_this, 4, 0);
  return v6 * v4 * _this->uAccuracy / 100 / 100 + Player_MaybeGetCastSpellBonus(_this, 4) + v7 + _this->uAccuracyBonus;
}

//----- (0048CBB6) --------------------------------------------------------
int __thiscall Player_GetActualSpeed(struct Player *_this)
{
  int v1; // eax@1
  signed int v2; // ecx@1
  signed int v4; // ebx@4
  int v6; // edi@5
  int v7; // ebp@5

  v1 = Player_GetActualAge(_this);
  v2 = 0;
  while ( v1 >= uAgeingTable[v2] )
  {
    ++v2;
    if ( v2 >= 4 )
    {
      v4 = 100;
      goto LABEL_5;
    }
  }
  v4 = uAgeingSpeedMultiplier[v2];
LABEL_5:
  v6 = uConditionSpeedMultiplier[Player_GetConditionIdx(_this)];
  v7 = Player_MaybeGetWearItemsBonus(_this, 5, 0);
  return v6 * v4 * _this->uSpeed / 100 / 100 + Player_MaybeGetCastSpellBonus(_this, 5) + v7 + _this->uSpeedBonus;
}

//----- (0048CC33) --------------------------------------------------------
int __thiscall Player_GetActualLuck(struct Player *_this)
{
  int v2; // eax@1
  int v3; // eax@3
  int v4; // eax@5
  int v5; // eax@7
  signed int v6; // ecx@7
  signed int v7; // ebx@10
  int v9; // edi@11
  int v10; // ebp@11
  signed int v11; // [sp+10h] [bp-4h]@1

  v11 = 0;
  v2 = CheckHiredNPCSpeciality(0x1B);
  if ( v2 )
    v11 = 5;
  v3 = CheckHiredNPCSpeciality(0x1C);
  if ( v3 )
    v11 += 20;
  v4 = CheckHiredNPCSpeciality(0x2F);
  if ( v4 )
    v11 += 10;
  v5 = Player_GetActualAge(_this);
  v6 = 0;
  while ( v5 >= uAgeingTable[v6] )
  {
    ++v6;
    if ( v6 >= 4 )
    {
      v7 = 100;
      goto LABEL_11;
    }
  }
  v7 = uAgeingLuckMultiplier[v6];
LABEL_11:
  v9 = uConditionLuckMultiplier[Player_GetConditionIdx(_this)];
  v10 = Player_MaybeGetWearItemsBonus(_this, 6, 0);
  return Player_MaybeGetCastSpellBonus(_this, 6) + v10 + v11 + v9 * v7 * _this->uLuck / 100 / 100 + _this->uLuckBonus;
}

//----- (0048E4F8) --------------------------------------------------------
int Player_GetMaxHealth(struct Player *_this)
{
  signed int result; // eax@1
  int v2; // esi@1
  int v4; // eax@1
  int v5; // esi@1
  int v6; // esi@1
  int v7; // esi@1

  v4 = Player_GetActualEndurance(_this);
  v5 = sub_48EA1B(v4);
  v6 = byte_4ED768[_this->uClass] * (Player_GetActualLevel(_this) + v5);
  v7 = Player_MaybeGetWearItemsBonus(_this, 7, 0) + v6;
  v2 = _this->byte_001A98
     + byte_4ED750[_this->uClass >> 2]
     + Player_sub_48FC00(_this, 7)
     + v7;
  result = 1;
  if ( v2 >= 1 )
    result = v2;
  return result;
}

//----- (0048E565) --------------------------------------------------------
int __thiscall Player_GetMaxMana(struct Player *_this)
{
  Player *v1; // edi@1
  int v2; // eax@2
  int v3; // esi@4
  int v4; // eax@5
  int v5; // esi@5
  int v6; // eax@5
  int v7; // esi@6
  int v8; // esi@6
  int v9; // esi@6
  int result; // eax@7

  v1 = _this;
  switch ( _this->uClass )
  {
    case 5:
    case 6:
    case 7:
    case 16:
    case 17:
    case 18:
    case 19:
    case 32:
    case 33:
    case 34:
    case 35:
      v2 = Player_GetActualIntelligence(_this);
      v3 = sub_48EA1B(v2);
      break;
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 24:
    case 25:
    case 26:
    case 27:
      v2 = Player_GetActualWillpower(_this);
      v3 = sub_48EA1B(v2);
     break;
    case 21:
    case 22:
    case 23:
    case 28:
    case 29:
    case 30:
    case 31:
      v4 = Player_GetActualWillpower(_this);
      v5 = sub_48EA1B(v4);
      v6 = Player_GetActualIntelligence(_this);
      v3 = sub_48EA1B(v6) + v5;     
      break;
    default:

      return 0;
      break;
  }
   v8 = (unsigned __int8)byte_4ED78C[_this->uClass] * (Player_GetActualLevel(v1) + v3);
      v9 = Player_MaybeGetWearItemsBonus(v1, 8, 0) + v8;
      v7 = v1->array_001A99[1]//*(_BYTE *)(v1 + 6810)
         + (unsigned __int8)byte_4ED75C[_this->uClass >> 2]	//need get bytes from exe
         + Player_sub_48FC00(v1, 8)
         + v9;
      if ( v7 < 1 )
        result = 0;
	  else
        result = v7;
  return result;
}

//----- (0048E9F4) --------------------------------------------------------
int Player_GetConditionIdx(struct Player *_this)
{
  signed int v1; // edx@1

  v1 = 0;
  while (true)
  {
   if (*((int *)_this + 2 * dword_4EDEF8[v1]) | *((int *)_this + 2 * dword_4EDEF8[v1] + 1))
     break;

   if (++v1 >= 18)
     return 18;
  }
  return dword_4EDEF8[v1];
}

//----- (00492745) --------------------------------------------------------
int __thiscall WearItem(void *_this, int a2)
{
  signed int v2; // eax@1
  int v3; // edx@1
  int v4; // edi@6
  int v5; // eax@6
  char *v6; // esi@6

  v2 = 0;
  v3 = (int)((char *)_this + 532);
  while ( *(_DWORD *)v3 )
  {
    ++v2;
    v3 += 36;
    if ( v2 >= 126 )
    {
      v2 = -1;
      break;
    }
  }
  if ( v2 != -1 )
  {
    v4 = v2 + 1;
    v5 = (int)((char *)_this + 36 * v2);
    v6 = &byte_4E8398[pClass40->pItems[a2 - 1].uEquipType];
    *((_DWORD *)_this + (unsigned __int8)*v6 + 1618) = v4;
    *(_DWORD *)(v5 + 532) = a2;
    *(_BYTE *)(v5 + 556) = *v6 + 1;
  }
  return 0;
}

//----- (0049107D) --------------------------------------------------------
int sub_49107D(struct Player *_this)
{
  int v1; // al@1
  int v2; // ecx@1
  int v4; // eax@3
  signed int v6; // [sp-4h] [bp-4h]@2

  v1 = Player_GetActualSkillLevel(_this, 24);
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

//----- (0048FC00) --------------------------------------------------------
int Player_sub_48FC00(struct Player *_this, signed int a2)
{
  int v2; // eax@1
  signed int v3; // ebx@1
  char v4; // di@1
  //void *v5; // esi@1
  signed int v6; // eax@2
  int v7;
  int v9; // ebx@19
  //void *v10; // ecx@20
  int v11; // edi@21
  signed int v12; // edi@21
  int v13; // eax@21
  char v14; // di@25
  signed int v15; // esi@25
  char v16; // al@32
  int v18; // eax@36
  signed int v19; // eax@37
  int v20; // edi@40
  //int v21; // edx@41
  int v22; // eax@42
  signed int v23; // eax@45
  __int16 v24; // bx@45
  signed int v25; // edi@45
  __int16 v26; // ax@45
  unsigned __int8 v27; // sf@50
  unsigned __int8 v28; // of@50
  signed int v29; // eax@52
  int v30; // eax@55
  int v31; // eax@58
  signed int v32; // eax@59
  int v33; // eax@65
  char v34; // si@65
  int v35; // edi@69
  //int v36; // edx@70
  int v37; // eax@71
  signed int v38; // edi@74
  int v39; // eax@74
  int v40; // eax@89
  char v41; // si@89
  int v42; // eax@96
  int v43; // eax@97
  signed int v44; // edx@97
  int v45; // eax@98
  int v46; // eax@99
  int v47; // eax@100
  int v48; // eax@101
  int v49; // eax@102
  signed int v50; // eax@113
  signed int i; // ecx@113
  int v52; // edi@113
  __int16 v53; // ax@113
  char v54; // di@113
  signed int v56; // eax@118
  char v57; // si@118
  __int16 v58; // ax@118
  signed int j; // ecx@121
  int v60; // esi@121
  int v61; // eax@126
  int v62; // edi@126
  signed int v63; // [sp-4h] [bp-30h]@26
  signed int v64; // [sp-4h] [bp-30h]@80
  int v65; // [sp+Ch] [bp-20h]@104
  int v66; // [sp+10h] [bp-1Ch]@104
  int v67; // [sp+14h] [bp-18h]@104
  int v68; // [sp+18h] [bp-14h]@104
  int v69; // [sp+1Ch] [bp-10h]@69
  char *v70; // [sp+20h] [bp-Ch]@1
  int v71; // [sp+24h] [bp-8h]@1
  int v72; // [sp+28h] [bp-4h]@1
  int v73; // [sp+34h] [bp+8h]@21
  int v74; // [sp+34h] [bp+8h]@74
  signed int v75; // [sp+34h] [bp+8h]@94

  v71 = 0;
  v70 = 0;
  v72 = 0;
  LOBYTE(v2) = Player_GetActualSkillLevel(_this, Character::Skill::Armsmaster);
  v4 = v2;
  v3 = 1;
  if ((_BYTE)v2 )
  {
    v6 = sub_458244_GetSkillMasteryLevel((_BYTE)v2);
    if ( a2 == 26 )
    {
      if ( v6 >= 4 )
        goto LABEL_4;
      //v8 = __SETO__(v6, 3);
      //v7 = v6 - 3 < 0;
      v7 = v6 < 3;
    }
    else
    {
      if ( a2 != 25 )
        goto LABEL_11;
      if ( v6 >= 4 )
      {
LABEL_4:
        v72 = 2;
LABEL_11:
        v70 = (char *)(v72 * (v4 & 0x3F));
        goto LABEL_12;
      }
      //v8 = __SETO__(v6, 2);
      //v7 = v6 - 2 < 0;
      v7 = v6 < 2;
    }
    if ( !(v7) )
      v72 = 1;
    goto LABEL_11;
  }
LABEL_12:
  if ( a2 == 7 )
  {
    v62 = byte_4ED768[_this->uClass];
    v61 = sub_49107D(_this);
    return v62 * v61;
  }
  if ( a2 == 8 )
  {
    v62 = byte_4ED78C[_this->uClass];
    v61 = Player_sub_4910A8(_this);
    return v62 * v61;
  }
  if ( a2 != 9 )
  {
    if ( a2 != 25 )
    {
      if ( a2 <= 25 )
        return v71;
      if ( a2 > 28 )
      {
        if ( a2 != 29 )
          return v71;
        v72 = 0;
        v9 = (int)_this->pEquippedItemIndices;
        while ( 1 )
        {
          if ( Player_sub_48D6AA(_this, v72) )
          {
           v12 = pClass40->pItems[_this->pInventorySlots[*(_DWORD *)v9].uItemID].uEquipType;
            LOBYTE(v13) = Player_GetActualSkillLevel(_this, v12);
            v73 = (_BYTE)v13;
            sub_458244_GetSkillMasteryLevel((_BYTE)v13);
            v11 = v12 - 5;
            if ( !v11 )
              return v73 & 0x3F;
            if ( v11 == 2 )
              break;
          }
          ++v72;
          v9 += 4;
          if ( v72 >= 16 )
            return v71;
        }
        v14 = v73;
        v15 = 1;
        if ( sub_458244_GetSkillMasteryLevel(v73) >= 4 )
        {
          v63 = 5;
          goto LABEL_31;
        }
        if ( sub_458244_GetSkillMasteryLevel(v73) >= 3 )
        {
          v63 = 3;
          goto LABEL_31;
        }
        if ( sub_458244_GetSkillMasteryLevel(v73) < 2 )
          goto LABEL_32;
        goto LABEL_30;
      }
      if (Player_sub_48D676(_this))
      {
        LOBYTE(v18) = Player_GetActualSkillLevel(_this, 31);
        v14 = v18;
        if ( !v18 )
          return v71;
        v15 = 0;
        v19 = sub_458244_GetSkillMasteryLevel(v18);
        if ( v19 < 3 )
        {
          if ( v19 >= 2 )
            v15 = 1;
LABEL_32:
          v16 = v14;
          return v15 * (v16 & 0x3F);
        }
LABEL_30:
        v63 = 2;
LABEL_31:
        v15 = v63;
        goto LABEL_32;
      }
      v20 = 0;
      while ( 1 )
      {
        if ( Player_sub_48D6AA(_this, v20) )
        {
         v22 = _this->pInventorySlots[_this->pEquippedItemIndices[v20]].uItemID;
          if (pClass40->pItems[v22].uEquipType <= 1u )
            break;
        }
        ++v20;
        if ( v20 >= 16 )
          return v71;
      }
      v72 = 0;
      v25 = pClass40->pItems[v22].uSkillType;
      LOBYTE(v26) = Player_GetActualSkillLevel(_this, v25);
      v24 = v26;
      v23 = sub_458244_GetSkillMasteryLevel(v26);
      if ( !v25 )
      {
        if ( sub_458244_GetSkillMasteryLevel(v24) >= 4 )
        {
          LOBYTE(v31) = Player_GetActualSkillLevel(_this, 31);
          LOBYTE(v24) = v31;
          if ( v31 )
          {
            v15 = 0;
            v32 = sub_458244_GetSkillMasteryLevel(v31);
            if ( v32 < 3 )
            {
              if ( v32 >= 2 )
                v15 = 1;
            }
            else
            {
              v15 = 2;
            }
            v16 = v24;
            return v15 * (v16 & 0x3F);
          }
        }
        goto LABEL_55;
      }
      if ( v25 == 2 )
      {
        v29 = sub_458244_GetSkillMasteryLevel(v24);
        //v28 = __SETO__(v29, 4);
        //v27 = v29 - 4 < 0;
        v27 = v29 < 4;
      }
      else
      {
        if ( v25 <= 2 )
          goto LABEL_55;
        if ( v25 > 4 )
        {
          if ( v25 == 6 )
          {
            compile_error();//v28 = __SETO__(v23, 2);
            v27 = v23 - 2 < 0;
            goto LABEL_53;
          }
LABEL_55:
          v30 = v72 * (v24 & 0x3F);
          return (int)&v70[v30];
        }
        compile_error();//v28 = __SETO__(v23, 3);
        v27 = v23 - 3 < 0;
      }
LABEL_53:
      if ( !(v27 ^ v28) )
        v72 = 1;
      goto LABEL_55;
    }
    if ( Player_sub_48D676(_this) == 1 )
    {
      LOBYTE(v33) = Player_GetActualSkillLevel(_this, 31);
      v34 = v33;
      if ( !v33 )
        return v71;
      if ( sub_458244_GetSkillMasteryLevel(v33) >= 3 )
        v3 = 2;
      v30 = v3 * (v34 & 0x3F);
      return (int)&v70[v30];
    }
    v35 = 0;
    v69 = 0;
    while ( 1 )
    {
      if ( Player_sub_48D6AA(_this, v35) )
      {
       v37 = _this->pInventorySlots[v35].uItemID;
        if (pClass40->pItems[v37].uEquipType <= 1)
          break;
      }
      ++v35;
      if ( v35 >= 16 )
        return v71;
    }
    v38 = pClass40->pItems[v37].uSkillType;
    LOBYTE(v39) = Player_GetActualSkillLevel(_this, v38);
    v74 = v39;
    sub_458244_GetSkillMasteryLevel(v39);
    v72 = 0;
    if ( v38 )
    {
      if ( v38 > 0 )
      {
        if ( v38 <= 4 || v38 == 6 )
        {
          v72 = 1;
        }
        else
        {
          if ( v38 == 7 )
          {
            if ( sub_458244_GetSkillMasteryLevel(v74) < 4 )
            {
              if ( sub_458244_GetSkillMasteryLevel(v74) < 3 )
              {
                if ( sub_458244_GetSkillMasteryLevel(v74) < 2 )
                  return v3 * (v74 & 0x3F);
                v64 = 2;
              }
              else
              {
                v64 = 3;
              }
            }
            else
            {
              v64 = 5;
            }
            v3 = v64;
            return v3 * (v74 & 0x3F);
          }
        }
      }
    }
    else
    {
      v72 = 1;
      if ( sub_458244_GetSkillMasteryLevel(v74) >= 4 )
      {
        LOBYTE(v40) = Player_GetActualSkillLevel(_this, 31);
        v41 = v40;
        if ( v40 )
        {
          if ( sub_458244_GetSkillMasteryLevel(v40) >= 3 )
            v3 = 2;
          v69 = v3 * (v41 & 0x3F);
        }
      }
    }
    v30 = v69 + v72 * (v74 & 0x3F);
    return (int)&v70[v30];
  }
  v75 = 0;
  v72 = 0;
  v69 = 16;
  v70 = (char *)_this + 6472;
  do
  {
    if ( *(_DWORD *)v70 )
    {
      v42 = (int)((char *)_this + 36 * *(_DWORD *)v70);
      if ( !(*(_BYTE *)(v42 + 516) & 2) )
      {
       v44 = pClass40->pItems[*(_DWORD *)(v42 + 496)].uSkillType;
       v43 = pClass40->pItems[*(_DWORD *)(v42 + 496)].uSkillType;
        if ( v43 )
        {
          v45 = v43 - 1;
          if ( !v45 || (v46 = v45 - 3, !v46) )
          {
            v65 = 0;
            v66 = 0;
            v67 = 0;
            v68 = 1;
            goto LABEL_113;
          }
          v47 = v46 - 4;
          if ( v47 )
          {
            v48 = v47 - 1;
            if ( v48 )
            {
              v49 = v48 - 1;
              if ( v49 )
              {
                if ( v49 != 1 )
                  goto LABEL_117;
                v75 = 1;
                v65 = 1;
                v66 = 0;
                v67 = 0;
                v68 = 0;
                goto LABEL_113;
              }
              v75 = 1;
              v65 = 1;
              v66 = 0;
              goto LABEL_111;
            }
            v72 = 1;
          }
          else
          {
            v75 = 1;
          }
          v65 = 1;
          v66 = 0;
          v67 = 1;
LABEL_112:
          v68 = 0;
LABEL_113:
          LOBYTE(v53) = Player_GetActualSkillLevel(_this, v44);
          v54 = v53;
          v50 = sub_458244_GetSkillMasteryLevel(v53);
          v52 = v54 & 0x3F;
          for ( i = 0; i < v50; ++i )
          {
            if ( *(&v65 + i) )
              v71 += v52;
          }
          goto LABEL_117;
        }
        v65 = 0;
        v66 = 1;
LABEL_111:
        v67 = 0;
        goto LABEL_112;
      }
    }
LABEL_117:
    v70 += 4;
  }
  while ( v69-- != 1 );
  v65 = 1;
  v66 = 1;
  v67 = 1;
  v68 = 0;
  LOBYTE(v58) = Player_GetActualSkillLevel(_this, 30);
  v57 = v58;
  v56 = sub_458244_GetSkillMasteryLevel(v58);
  if ( !v75 )
  {
    if ( !v72 || v56 == 4 )
    {
      v60 = v57 & 0x3F;
      for ( j = 0; j < v56; ++j )
      {
        if ( *(&v65 + j) )
          v71 += v60;
      }
    }
  }
  return v71;
}

//----- (004927A8) --------------------------------------------------------
unsigned int AddItem(struct Player *_this, unsigned int uInventorySlot, unsigned int uItemID)
{
  signed int v3; // ebx@2
  signed int v4; // edi@3
  signed int v5; // esi@3

  if (uInventorySlot == -1) // need to find appropriate place for item
  {
   /*
    v3 = 0;
    while ( 2 )
    {
      v4 = 0;
      v5 = v3;
      do
      {
        if ( CanPlaceItemInInventory(_this, v5, itemid) )
          return CreateItemInInventory(_this, v5, itemid);
        
        ++v4;
        v5 += 14;
      }
      while ( v4 < 9 );
      ++v3;
      if ( v3 < 14 )
        continue;
      break;
    }
    return 0;*/
   uInventorySlot = FindPlaceForItemInInventory(_this, uItemID);
   if (uInventorySlot == -1)
   {
    if (uActiveCharacter)
      Player_PlaySound(pPlayers[uActiveCharacter - 1], Character::Voice::NoRoom, 0);

    return -1;
   }
   else return CreateItemInInventory(_this, uInventorySlot, uItemID);
  }

  if (!CanPlaceItemInInventory(_this, uInventorySlot, uItemID))
  {
    pAudioPlayer->sub_4AA306(27, 0, 0, -1, 0, 0, 0, 0);

    if ( uActiveCharacter )
      Player_PlaySound(pPlayers[uActiveCharacter - 1], Character::Voice::NoRoom, 0);

    return -1;
  }
  return CreateItemInInventory(_this, uInventorySlot, uItemID);
}

//----- (0048CCF5) --------------------------------------------------------
int Player_GetAttackBonus(Player *_this, int a2)
{
  int v4; // eax@1
  int v5; // edi@1
  int v6; // ebx@1
  int v7; // ebp@1

  v4 = Player_GetActualAccuracy(_this);
  v5 = sub_48EA1B(v4);
  v6 = Player_sub_48FC00(_this, 25);
  v7 = Player_MaybeGetWearItemsBonus(_this, 25, a2);
  return v5 + v6 + v7 + Player_MaybeGetCastSpellBonus(_this, 25) + _this->byte_001A90;
}

//----- (0048CD45) --------------------------------------------------------
signed int __thiscall Player_GetMeleeDamageMinimal(Player *_this)
{
  signed int result; // eax@1
  int v2; // esi@1
  int v4; // eax@1
  int v5; // esi@1
  int v6; // esi@1
  int v7; // esi@1

  v4 = Player_GetActualStrength(_this);
  v5 = sub_48EA1B(v4);
  v6 = Player_MaybeGetWearItemsBonus(_this, 27, 0) + v5;
  v7 = Player_sub_48FC00(_this, 26) + v6;
  v2 = _this->byte_001A92 + Player_MaybeGetCastSpellBonus(_this, 26) + v7;
  result = 1;
  if ( v2 >= 1 )
    result = v2;
  return result;
}

//----- (0048CD90) --------------------------------------------------------
signed int __thiscall Player_GetMeleeDamageMaximal(Player *_this)
{
  signed int result; // eax@1
  int v2; // esi@1
  int v3; // edi@1
  int v4; // eax@1
  int v5; // esi@1
  int v6; // esi@1
  int v7; // esi@1

  v4 = Player_GetActualStrength(_this);
  v5 = sub_48EA1B(v4);
  v6 = Player_MaybeGetWearItemsBonus(_this, 28, 0) + v5;
  v7 = Player_sub_48FC00(_this, 26) + v6;
  v2 = _this->byte_001A92 + Player_MaybeGetCastSpellBonus(_this, 26) + v7;
  result = 1;
  if ( v2 >= 1 )
    result = v2;
  return result;
}

//----- (0048CDDB) --------------------------------------------------------
signed int __thiscall Player_sub_48CDDB(Player *_this, int a2, int a3, signed int a4)
{
  int v4; // edi@1
  int v5; // esi@1
  int v6; // eax@4
  int v7; // ebx@4
  int v8; // ebp@4
  int v9; // esi@4
  int v10; // eax@9
  char v11; // zf@9
  int v12; // esi@10
  int v13; // eax@11
  int v14; // edx@24
  int v15; // ebx@35
  int v16; // ebp@35
  int v17; // esi@35
  int v18; // edx@38
  char v19; // zf@38
  int v20; // eax@40
  int v21; // edx@53
  int v22; // esi@62
  int v23; // eax@63
  int v24; // ebx@63
  int v25; // ebx@63
  signed int result; // eax@64
  signed int v27; // [sp-4h] [bp-24h]@20
  signed int v28; // [sp-4h] [bp-24h]@49
  int v29; // [sp+10h] [bp-10h]@1
  int v30; // [sp+10h] [bp-10h]@33
  signed int v31; // [sp+14h] [bp-Ch]@7
  signed int v32; // [sp+14h] [bp-Ch]@36
  int v33; // [sp+18h] [bp-8h]@1
  int v34; // [sp+18h] [bp-8h]@8
  int v35; // [sp+1Ch] [bp-4h]@1
  int v36; // [sp+28h] [bp+8h]@37

  v5 = 0;
  v4 = (int)_this;
  v35 = 0;
  v33 = 0;
  v29 = 0;
  if ( Player_sub_48D676(_this) == 1 )
  {
    v33 = rand() % 3 + 1;
LABEL_61:
    v35 = v5;
    goto LABEL_62;
  }
  if ( Player_sub_48D6AA((Player *)v4, 1) )
  {
    v7 = v4 + 36 * *(_DWORD *)(v4 + 6476) + 496;
    v8 = *(_DWORD *)v7;
    v9 = 48 * *(_DWORD *)v7;
    v6 = pClass40->pItems[v9/48 - 1].uDamageDice;
    if (pClass40->pItems[v9/48 - 1].uSkillType == 4 )
    {
      if ( !*(_DWORD *)(v4 + 6472) )
        ++v6;
    }
    v31 = pClass40->pItems[v9/48 - 1].uDamageRoll;
    if ( v6 > 0 )
    {
      v34 = v6;
      do
      {
        v10 = rand();
        v11 = v34-- == 1;
        v29 += v10 % v31 + 1;
      }
      while ( !v11 );
    }
    v12 = pClass40->pItems[v9/48 - 1].uDamageModifier + v29;
    if ( !a4 )
      goto LABEL_28;
    v13 = *(_DWORD *)(v7 + 12);
    if ( v13 == 64 || v8 == 507 || v8 == 508 || v8 == 527 )
    {
      v14 = 1;
    }
    else
    {
      if ( v13 == 39 )
      {
        v27 = 2;
      }
      else
      {
        if ( v13 == 40 )
        {
          v27 = 3;
        }
        else
        {
          if ( v13 == 63 || v8 == 517 )
          {
            v27 = 4;
          }
          else
          {
            if ( v13 != 65 )
            {
LABEL_28:
              if ( sub_458244_GetSkillMasteryLevel(*(_WORD *)(v4 + 268)) >= 3 )
              {
               if (pClass40->pItems[*(_DWORD *)v7 - 1].uSkillType == 2 )
                {
                  if ( rand() % 100 < 10 )
                    v12 *= 3;
                }
              }
              v33 = v12;
              goto LABEL_33;
            }
            v27 = 7;
          }
        }
      }
      v14 = v27;
    }
    if ( sub_438BDF(a4, v14) )
      v12 *= 2;
    goto LABEL_28;
  }
LABEL_33:
  v30 = 0;
  if ( !a3 )
  {
    if ( Player_sub_48D6AA((Player *)v4, 0) )
    {
      v15 = v4 + 36 * *(_DWORD *)(v4 + 6472) + 496;
      v16 = *(_DWORD *)v15;
      v17 = 48 * *(_DWORD *)v15;
      if (pClass40->pItems[v17/48 - 1].uEquipType != 4 )
      {
       v32 = pClass40->pItems[v17/48 - 1].uDamageRoll;
       if ( (signed int)pClass40->pItems[v17/48 - 1].uDamageDice > 0 )
        {
         v36 = pClass40->pItems[v17/48 - 1].uDamageDice;
          do
          {
            v18 = rand() % v32;
            v19 = v36-- == 1;
            v30 += v18 + 1;
          }
          while ( !v19 );
        }
        v5 = pClass40->pItems[v17/48 - 1].uDamageModifier + v30;
        if ( !a4 )
          goto LABEL_57;
        v20 = *(_DWORD *)(v15 + 12);
        if ( v20 == 64 || v16 == 507 || v16 == 508 || v16 == 527 )
        {
          v21 = 1;
        }
        else
        {
          if ( v20 == 39 )
          {
            v28 = 2;
          }
          else
          {
            if ( v20 == 40 )
            {
              v28 = 3;
            }
            else
            {
              if ( v20 == 63 || v16 == 517 )
              {
                v28 = 4;
              }
              else
              {
                if ( v20 != 65 )
                {
LABEL_57:
                 if (pClass40->pItems[*(_DWORD *)v15 - 1].uSkillType == 2 )
                  {
                    if ( sub_458244_GetSkillMasteryLevel(*(_WORD *)(v4 + 268) >= 3u) )
                    {
                      if ( rand() % 100 < 10 )
                        v5 *= 3;
                    }
                  }
                  goto LABEL_61;
                }
                v28 = 7;
              }
            }
          }
          v21 = v28;
        }
        if ( sub_438BDF(a4, v21) )
          v5 *= 2;
        goto LABEL_57;
      }
    }
  }
LABEL_62:
  v22 = v33 + v35;
  if ( !a2 )
  {
    v23 = Player_GetActualStrength((Player *)v4);
    v24 = sub_48EA1B(v23);
    v25 = Player_sub_48FC00((Player *)v4, 26) + v24;
    v22 += *(_BYTE *)(v4 + 6802) + Player_MaybeGetCastSpellBonus((Player *)v4, 26) + v25;
  }
  result = 1;
  if ( v22 >= 1 )
    result = v22;
  return result;
}

//----- (0048D0B9) --------------------------------------------------------
int Player_sub_48D0B9(Player *_this)
{
  signed int v1; // eax@1
  int v3; // edi@3
  int v4; // eax@4
  int v5; // edi@4
  int v6; // edi@4
  int v7; // edi@4

  v1 = _this->pInventorySlots[_this->pEquippedItemIndices[1]].uItemID;
  if (v1 < 63 || v1 > 64) // if not blasters
  {
    v4 = Player_GetActualAccuracy(_this);
    v5 = sub_48EA1B(v4);
    v6 = Player_MaybeGetWearItemsBonus(_this, 29, 0) + v5;
    v7 = Player_sub_48FC00(_this, 29) + v6;
    v3 = _this->byte_001A94 + Player_MaybeGetCastSpellBonus(_this, 29) + v7;
  }
  else
  {
    v3 = Player_GetAttackBonus(_this, 1);
  }
  return v3;
}

//----- (0048D124) --------------------------------------------------------
int __thiscall sub_48D124(void *_this)
{
  __int16 v1; // ax@1
  int v2; // edi@1
  int v3; // esi@1
  int v4; // edi@1
  int v5; // edi@1
  int result; // eax@6

  v3 = (int)_this;
  v4 = Player_MaybeGetWearItemsBonus((Player *)_this, 31, 0);
  v5 = Player_sub_48FC00((Player *)v3, 30) + v4;
  v2 = *(_BYTE *)(v3 + 6806) + Player_MaybeGetCastSpellBonus((Player *)v3, 30) + v5;
  v1 = *(_WORD *)(v3 + 274);
  if ( v1 )
  {
    if ( sub_458244_GetSkillMasteryLevel(v1) >= 4 )
    {
      if ( Player_sub_48D6AA((Player *)v3, 2) )
        v2 += *(_BYTE *)(v3 + 274) & 0x3F;
    }
  }
  if ( v2 >= 1 )
    result = v2;
  else
    result = 0;
  return result;
}

//----- (0048D191) --------------------------------------------------------
int __thiscall sub_48D191(void *_this)
{
  __int16 v1; // ax@1
  int v2; // edi@1
  int v3; // esi@1
  int v4; // edi@1
  int v5; // edi@1
  int result; // eax@6

  v3 = (int)_this;
  v4 = Player_MaybeGetWearItemsBonus((Player *)_this, 32, 0);
  v5 = Player_sub_48FC00((Player *)v3, 30) + v4;
  v2 = *(_BYTE *)(v3 + 6806) + Player_MaybeGetCastSpellBonus((Player *)v3, 30) + v5;
  v1 = *(_WORD *)(v3 + 274);
  if ( v1 )
  {
    if ( sub_458244_GetSkillMasteryLevel(v1) >= 4 )
    {
      if ( Player_sub_48D6AA((Player *)v3, 2) )
        v2 += *(_BYTE *)(v3 + 274) & 0x3F;
    }
  }
  if ( v2 >= 1 )
    result = v2;
  else
    result = 0;
  return result;
}

//----- (0048D2EA) --------------------------------------------------------
char *__thiscall Player_GetMeleeDamage_String(Player *_this)
{
  signed int v1; // eax@1
  signed int v3; // eax@3
  signed int v4; // edi@3
  signed int v6; // ST0C_4@6
  signed int v7; // ST08_4@7
  int v8; // eax@8
  signed int v9; // esi@9

  v1 = _this->pInventorySlots[_this->pEquippedItemIndices[1]].uItemID;
  if (v1 < 63 || v1 > 64) // if not blasters
  {
    v4 = Player_GetMeleeDamageMinimal(_this);
    v3 = Player_GetMeleeDamageMaximal(_this);
  }
  else //blasters
  {
    v4 = Player_MaybeGetWearItemsBonus(_this, 27, 0);
    v3 = Player_MaybeGetWearItemsBonus(_this, 28, 0);
  }
  if ( v4 == v3 )
  {
    v6 = v4;
    wsprintfA(byte_A7509C, "%d", v6);
  }
  else
  {
    v7 = v4;
    wsprintfA(byte_A7509C, "%d - %d", v7, v3);
  }
  v8 = _this->pEquippedItemIndices[1];
  if ( v8 )
  {
   v9 = _this->pInventorySlots[v8].uItemID;
    if (v9 >= 134 && v9 <= 158)  // wand
      strcpy(byte_A7509C, (char *)pGlobalTXT_LocalizationStrings[595]);
  }
  return byte_A7509C;
}

//----- (0048D396) --------------------------------------------------------
char *__thiscall Player_sub_48D396(int _this)
{
  signed int v1; // eax@1
  int v2; // esi@1
  int v3; // eax@3
  int v4; // edi@3
  char *v5; // edi@6
  int v6; // ST0C_4@8
  int v7; // ST08_4@9
  int v8; // eax@10
  signed int v9; // esi@11

  v2 = _this;
  v1 = *(_DWORD *)(_this + 36 * *(_DWORD *)(_this + 6476) + 496);
  if ( v1 < 64 || v1 > 65 )
  {
    v4 = sub_48D124((void *)_this);
    v3 = sub_48D191((void *)v2);
  }
  else
  {
    v4 = Player_MaybeGetWearItemsBonus((Player *)_this, 27, 1);
    v3 = Player_MaybeGetWearItemsBonus((Player *)v2, 28, 1);
  }
  if ( v3 )
  {
    if ( v4 == v3 )
    {
      v6 = v4;
      v5 = byte_A75074;
      wsprintfA(byte_A75074, "%d", v6);
    }
    else
    {
      v7 = v4;
      v5 = byte_A75074;
      wsprintfA(byte_A75074, "%d - %d", v7, v3);
    }
  }
  else
  {
    v5 = byte_A75074;
    strcpy(byte_A75074, "N/A");
  }
  v8 = *(_DWORD *)(v2 + 6476);
  if ( v8 )
  {
    v9 = *(_DWORD *)(v2 + 36 * v8 + 496);
    if ( v9 >= 135 )
    {
      if ( v9 <= 159 )
        strcpy(v5, (char *)pGlobalTXT_LocalizationStrings[595]);
    }
  }
  return v5;
}

//----- (0048E8F5) --------------------------------------------------------
bool Player_sub_48E8F5(struct Player *_this, signed int a2)
{
  signed __int64 v2; // qax@1
  void *v3; // esi@1

  v3 = _this;
  v2 = (signed __int64)((double)(a2 * Player_sub_48EA46(_this, 17)) * memory_4D8410.d0_01 + (double)a2);
  if ( *((_WORD *)v3 + 3226) - (_DWORD)v2 > 0 )
  {
    *((_WORD *)v3 + 3226) -= v2;
    return true;
  }
  else
  {
    *((_WORD *)v3 + 3226) = 0;
    struct_576FE8.dword_000044 = 1;
    if ( !uActiveCharacter )
      uActiveCharacter = Party_sub_49370F(pParty_global);
    return false;
  }
}

//----- (0048EA46) --------------------------------------------------------
signed int Player_sub_48EA46(struct Player *_this, int a2)
{
  int v2; // edi@1
  int v3; // esi@1
  int v5; // eax@3
  int v6; // eax@4

  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    if ( !Player_sub_48D6AA(_this, v3) )
      goto LABEL_11;
    v5 = _this->pEquippedItemIndices[0] - 1;
    if ( a2 != 17 )
      break;
    v6 = (int)((char *)_this + 36 * v5);
    if ( *(_DWORD *)(v6 + 532) == 533 || *(_DWORD *)(v6 + 544) == 17 )
      return 50;
LABEL_11:
    ++v3;
    if ( v3 >= 16 )
      return v2;
  }
  if ( a2 != 24 || *((_DWORD *)_this + 9 * v5 + 136) != 24 )
    goto LABEL_11;
  return 5;
}

//----- (00492D65) --------------------------------------------------------
signed int Player_sub_492D65(struct Player *_this, int a2, int a3)
{
  int v3; // esi@1
  void *v5; // ecx@21
  void *v6; // ecx@22
  void *v7; // ecx@29
  void *v8; // ecx@30
  void *v9; // ecx@37
  void *v10; // ecx@38
  void *v11; // ecx@45
  void *v12; // ecx@46
  int v13; // eax@49
  void *v14; // ecx@58
  void *v15; // ecx@59
  void *v16; // ecx@60
  signed int result; // eax@76
  signed int v18; // ecx@77
  int v19; // eax@77
  char v20; // al@80
  signed int v21; // ebx@82
  signed int v22; // esi@82
  int v23; // [sp-8h] [bp-1Ch]@7
  int v24; // [sp-8h] [bp-1Ch]@15
  int v25; // [sp-8h] [bp-1Ch]@53
  int v26; // [sp-4h] [bp-18h]@7
  int v27; // [sp-4h] [bp-18h]@15
  int v28; // [sp-4h] [bp-18h]@53
  char *v29; // [sp+Ch] [bp-8h]@1
  int v30; // [sp+10h] [bp-4h]@2
  int v31; // [sp+20h] [bp+Ch]@82
 int i;

  v3 = (int)_this;
  v29 = (char *)(v3 + 8 * a2);
  if ( *(_QWORD *)v29 )
  {
LABEL_76:
    return 0;
  }
  else
  {
    v30 = 0;
    for (i = 0; i < 4; ++i)
    {
      if ( Player_sub_492C0B_MaybeIfPlayerConscious(pPlayers[i]) )
        ++v30;
    }

    switch ( a2 )
    {
      case 0:
        v26 = 0;
        v23 = 30;
        goto LABEL_81;
      case 1:
       if ( a3 == 1 && pParty_global->pPartyBuffs[13].qword_000000 > 0 )
          goto LABEL_10;
        v26 = 0;
        v23 = 25;
        goto LABEL_81;
      case 2:
        if ( a3 != 1 )
          goto LABEL_82;
        if ( Player_sub_48D6D0((Player *)v3, 22) )
          goto LABEL_76;
        v27 = 3;
        v24 = 505;
        goto LABEL_16;
      case 3:
        v26 = 0;
        v23 = 26;
        goto LABEL_81;
      case 4:
        v26 = 0;
        v23 = 31;
        goto LABEL_81;
      case 5:
        if ( a3 == 1 && (Player_sub_48D6D0((Player *)v3, 19) || Player_sub_48D709((Player *)v5, 505, 3) || Player_sub_48D709((Player *)v6, 530, 6)) )
          goto LABEL_76;
        v26 = 0;
        v23 = 29;
        goto LABEL_81;
      case 6:
      case 8:
      case 10:
        if ( a3 == 1 )
        {
         if ( pParty_global->pPartyBuffs[13].qword_000000 > 0 )
          {
            --pParty_global->pPartyBuffs[13].word_000008;
            if (pParty_global->pPartyBuffs[13].word_000008 < 1u )
              SpellBuff_sub_458585(&pParty_global->pPartyBuffs[13]);
          }
          if ( Player_sub_48D6D0((Player *)v3, 21) || Player_sub_48D709((Player *)v7, 505, 3) || Player_sub_48D709((Player *)v8, 530, 6) )
            goto LABEL_76;
        }
        v26 = 0;
        v23 = 27;
        goto LABEL_81;
      case 7:
      case 9:
      case 11:
        if ( a3 != 1 )
          goto LABEL_40;
        if ( HIDWORD(pParty_global->pPartyBuffs[13].qword_000000) >= 0 && (HIDWORD(pParty_global->pPartyBuffs[13].qword_000000) > 0 || (_DWORD)pParty_global->pPartyBuffs[13].qword_000000 > 0u) )
          goto LABEL_10;
        if ( Player_sub_48D6D0((Player *)v3, 18) || Player_sub_48D709((Player *)v9, 505, 3) || Player_sub_48D709((Player *)v10, 530, 6) )
          goto LABEL_76;
LABEL_40:
        v26 = 0;
        v23 = 28;
        goto LABEL_81;
      case 12:
        if ( a3 != 1 )
          goto LABEL_82;
        if ( HIDWORD(pParty_global->pPartyBuffs[13].qword_000000) >= 0 && (HIDWORD(pParty_global->pPartyBuffs[13].qword_000000) > 0 || (_DWORD)pParty_global->pPartyBuffs[13].qword_000000 > 0u) )
          goto LABEL_10;
        if ( Player_sub_48D6D0((Player *)v3, 20) || Player_sub_48D709((Player *)v11, 505, 3) || Player_sub_48D709((Player *)v12, 507, 16) )
          goto LABEL_76;
        v27 = 6;
        v24 = 530;
LABEL_16:
        if ( Player_sub_48D709((Player *)v3, v24, v27) )
          goto LABEL_76;
        goto LABEL_82;
      case 13:
        Player_PlaySound((Player *)v3, 32, 0);
        v13 = v3 + 6460;
        goto LABEL_70;
      case 14:
       if ( a3 == 1 && pParty_global->pPartyBuffs[13].qword_000000 > 0 && pParty_global->pPartyBuffs[13].word_00000A >= 4u )
          goto LABEL_10;
        v28 = 0;
        v25 = 33;
        goto LABEL_67;
      case 15:
        if ( a3 == 1
         && (HIDWORD(pParty_global->pPartyBuffs[13].qword_000000) >= 0 && (HIDWORD(pParty_global->pPartyBuffs[13].qword_000000) > 0 || (_DWORD)pParty_global->pPartyBuffs[13].qword_000000 > 0u)
           || Player_sub_48D6D0((Player *)v3, 23)
           || Player_sub_48D709((Player *)v14, 520, 16)
           || Player_sub_48D709((Player *)v15, 505, 3)
           || Player_sub_48D709((Player *)v16, 530, 6)) )
          goto LABEL_76;
        v26 = 0;
        v23 = 34;
        goto LABEL_81;
      case 16:
       if ( a3 == 1 && pParty_global->pPartyBuffs[13].qword_000000 > 0 && pParty_global->pPartyBuffs[13].word_00000A >= 4u )
        {
LABEL_10:
          --pParty_global->pPartyBuffs[13].word_000008;
          if (pParty_global->pPartyBuffs[13].word_000008 < 1u )
            SpellBuff_sub_458585(&pParty_global->pPartyBuffs[13]);
          goto LABEL_76;
        }
        v28 = 0;
        v25 = 35;
LABEL_67:
        Player_PlaySound((Player *)v3, v25, v28);
        if ( *(_DWORD *)(v3 + 6460) > 0 )
          *(_DWORD *)(v3 + 6460) = 0;
        v13 = v3 + 6464;
LABEL_70:
        if ( *(_DWORD *)v13 > 0 )
          *(_DWORD *)v13 = 0;
LABEL_82:
        v21 = 0;
        *(_QWORD *)v29 = pParty_global->qword_00002C;
        v31 = 0;
        v22 = 1;
        do
        {
          //if ( Player_sub_492C0B_MaybeIfPlayerConscious(*(&ptr_A750C4 + v22)) )
          if ( Player_sub_492C0B_MaybeIfPlayerConscious(pPlayers[v22]))
          {
            ++v31;
            v21 = v22;
          }
          ++v22;
        }
        while ( v22 <= 4 );
        if ( v30 == 2 )
        {
          if ( v31 == 1 )
            Player_PlaySound(pPlayers[v21], 107, 0);
        }
        result = 1;
        break;
      case 17:
        if ( *(_BYTE *)(v3 + 185) == 35 || *(_QWORD *)(v3 + 128) || *(_QWORD *)(v3 + 136) || !*(_QWORD *)(v3 + 112) )
          goto LABEL_76;
        memset((void *)v3, 0, 0xA0u);
        *(_DWORD *)(v3 + 6460) = Player_GetMaxHealth((Player *)v3);
        v18 = 0;
        *(_DWORD *)(v3 + 6440) = *(_BYTE *)(v3 + 186);
        v19 = *(_DWORD *)(v3 + 6432);
        *(_DWORD *)(v3 + 6464) = 0;
        *(_DWORD *)(v3 + 6436) = v19;
        switch ( v19 )
        {
          case 0:
          case 1:
          case 2:
          case 3:
          case 8:
          case 9:
          case 12:
          case 13:
          case 16:
          case 17:
          case 20:
          case 23:
            v18 = 0;
            break;
          case 4:
          case 5:
          case 6:
          case 7:
          case 10:
          case 11:
          case 14:
          case 15:
          case 18:
          case 19:
          case 21:
          case 24:
            v18 = 1;
            break;
          default:
            break;
        }
        v26 = 0;
        v20 = (v18 != 0) + 23;
        v23 = 99;
        *(_BYTE *)(v3 + 186) = v20;
        *(_DWORD *)(v3 + 6432) = v20;
LABEL_81:
        Player_PlaySound((Player *)v3, v23, v26);
        goto LABEL_82;
      default:
        goto LABEL_82;
    }
  }
  return result;
}

//----- (0048E656) --------------------------------------------------------
int __thiscall Player_sub_48E656(int _this)
{
  int v1; // esi@1
  void *v2; // edi@1
  int v3; // eax@1
  int v4; // esi@1
  int v5; // esi@1
  int result; // eax@2

  v2 = (void *)_this;
  v3 = Player_GetActualSpeed((Player *)_this);
  v4 = sub_48EA1B(v3);
  v5 = Player_MaybeGetWearItemsBonus((Player *)v2, 9, 0) + v4;
  v1 = Player_sub_48FC00((Player *)v2, 9) + v5;
  if ( v1 >= 1 )
    result = v1;
  else
    result = 0;
  return result;
}

//----- (0048E68F) --------------------------------------------------------
int __thiscall Player_sub_48E68F(int _this)
{
  int v1; // esi@1
  int v2; // edi@1
  int v3; // eax@1
  int v4; // esi@1
  int v5; // esi@1
  int v6; // esi@1
  int result; // eax@2

  v2 = _this;
  v3 = Player_GetActualSpeed((Player *)_this);
  v4 = sub_48EA1B(v3);
  v5 = Player_MaybeGetWearItemsBonus((Player *)v2, 9, 0) + v4;
  v6 = Player_sub_48FC00((Player *)v2, 9) + v5;
  v1 = *(_WORD *)(v2 + 216) + Player_MaybeGetCastSpellBonus((Player *)v2, 9) + v6;
  if ( v1 >= 1 )
    result = v1;
  else
    result = 0;
  return result;
}

//----- (0048E73F) --------------------------------------------------------
int __thiscall Player_GetBaseResistance(struct Player *_this, signed int a2)
{
  unsigned int uRace; // eax@1
  int result; // eax@21
  int ResValue, ResRaceBonus;

  ResValue = 0;
  ResRaceBonus = 0;
  uRace = Player_GetRace(_this);

  switch ( a2 )
  {
    case 10:
      ResValue = _this->sFireResistanceBase;
      if (uRace == Character::Race::Goblin)
        ResRaceBonus = 5;
      break;
    case 11:
      ResValue = _this->sAirResistanceBase;
      if (uRace == Character::Race::Goblin)
        ResRaceBonus = 5;
      break;
    case 12:
      ResValue = _this->sWaterResistanceBase;
      if (uRace == Character::Race::Dwarf)
        ResRaceBonus = 5;
      break;
    case 13:
      ResValue = _this->sEarthResistanceBase;
      if (uRace == Character::Race::Dwarf)
        ResRaceBonus = 5;
      break;
    case 14:
      ResValue = _this->sMindResistanceBase;
      if (uRace == Character::Race::Elf)
        ResRaceBonus = 10;
      break;
    case 15:
    case 33:
      ResValue = _this->sBodyResistanceBase;
      if (uRace == Character::Race::Human)
        ResRaceBonus = 5;
      break;
  }

  result = ResValue + ResRaceBonus + Player_MaybeGetWearItemsBonus(_this, a2, 0);
  if ( _this->uClass == 35 )
  {
    if ( result > 200 )
      result = 200;
  }
  return result;
}

//----- (0048E7D0) --------------------------------------------------------
int __thiscall Player_GetActualResistance(struct Player *_this, signed int a2)
{
  unsigned int uRace; // ebx@1
  int result; // eax@28
  int ResValue, ResBonus, ResRaceBonus;

  ResValue = 0;
  ResBonus = 0;
  ResRaceBonus = 0;
  uRace = Player_GetRace(_this);
  if (CheckHiredNPCSpeciality(0x25))
    ResBonus = 20;
  if ( a2 == 10 || a2 == 11 || a2 == 12 || a2 == 13 )
  {
    if ( sub_458244_GetSkillMasteryLevel(_this->pActiveSkills[Character::Skill::Leather]) == 4 )  // Grandmaster leather bonus
    {  
      if ( Player_sub_48D6AA(_this, 3) ) // check equip?
      {
        if ( Player_GetEquippedItemSkillType(_this, 3) == 9 )
          ResBonus += _this->pActiveSkills[Character::Skill::Leather] & 0x3F;
      }
    }
  }
  switch ( a2 )
  {
    case 10:
      ResValue = _this->sFireResistanceBase + _this->sFireResistanceBonus;
      if (uRace == Character::Race::Goblin)
        ResRaceBonus = 5;
      break;
    case 11:
      ResValue = _this->sAirResistanceBase + _this->sAirResistanceBonus;
      if (uRace == Character::Race::Goblin)
        ResRaceBonus = 5;
      break;
    case 12:
      ResValue = _this->sWaterResistanceBase + _this->sWaterResistanceBonus;
      if (uRace == Character::Race::Dwarf)
        ResRaceBonus = 5;
      break;
    case 13:
      ResValue = _this->sEarthResistanceBase + _this->sEarthResistanceBonus;
      if (uRace == Character::Race::Dwarf)
        ResRaceBonus = 5;
      break;
    case 14:
      ResValue = _this->sMindResistanceBase + _this->sMindResistanceBonus;
      if (uRace == Character::Race::Elf)
        ResRaceBonus = 10;
      break;
    case 15:
    case 33:
      ResValue = _this->sBodyResistanceBase + _this->sBodyResistanceBonus;
      if (uRace == Character::Race::Human)
        ResRaceBonus = 5;
      break;
  }
  result = ResValue + ResBonus + ResRaceBonus + Player_MaybeGetCastSpellBonus(_this, a2) + Player_MaybeGetWearItemsBonus(_this, a2, 0);
  if ( _this->uClass == 35 )
  {
    if ( result > 200 )
      result = 200;
  }
  return result;
}

//----- (0048E96A) --------------------------------------------------------
bool Player_SetRecoveryTime(struct Player *_this, int sRecoveryTime)
{
  signed int v2; // edx@1

 v2 = sRecoveryTime;
 if (sRecoveryTime < 0 )
   v2 = 0;
 if (v2 > _this->uTimeToRecovery)
   _this->uTimeToRecovery = v2;

  if (pPlayers[uActiveCharacter - 1] == _this)
  {
    if ( !dword_50C0C4 )
      uActiveCharacter = Party_sub_49370F(pParty_global);
  }
  struct_576FE8.dword_000044 = 1;

 return true;
}

//----- (0048F73C) --------------------------------------------------------
int Player_MaybeGetCastSpellBonus(struct Player *_this, signed int a2)
{
  int result; // eax@1
  int v3; // eax@4
  int v4; // ecx@5

  result = 0;
  if ( a2 > 10 )
  {
    if ( a2 <= 15 )
    {
      switch ( a2 )
      {
        case 15:
          v3 = *(_WORD *)((char *)_this + 6088);
          v4 = pParty_global->pPartyBuffs[1].word_000008;
          break;
        case 11:
          v3 = *(_WORD *)((char *)_this + 6056);
          v4 = pParty_global->pPartyBuffs[0].word_000008;
          break;
        case 12:
          v3 = *(_WORD *)((char *)_this + 6408);
          v4 = pParty_global->pPartyBuffs[17].word_000008;
          break;
        case 13:
          v3 = *(_WORD *)((char *)_this + 6104);
          v4 = pParty_global->pPartyBuffs[4].word_000008;
          break;
        default:
          if ( a2 != 14 )
            return result;
          v3 = *(_WORD *)((char *)_this + 6200);
          v4 = pParty_global->pPartyBuffs[12].word_000008;
          break;
      }
      return v4 + v3;
    }
    if ( a2 != 25 )
    {
      if ( a2 == 26 )
      {
        v3 = *(_WORD *)((char *)_this + 6184);
        v4 = pParty_global->pPartyBuffs[9].word_000008;
        return v4 + v3;
      }
      if ( a2 != 29 )
        return result;
    }
    return *(_WORD *)((char *)_this + 6072);
  }
  if ( a2 == 10 )
  {
    v3 = *(_WORD *)((char *)_this + 6136);
    v4 = pParty_global->pPartyBuffs[6].word_000008;
    return v4 + v3;
  }
  switch ( a2 )
  {
    case 0:
      v3 = *(_WORD *)((char *)_this + 6360);
      goto LABEL_5;
    case 1:
      v3 = *(_WORD *)((char *)_this + 6328);
      goto LABEL_5;
    case 2:
      v3 = *(_WORD *)((char *)_this + 6376);
      goto LABEL_5;
    case 3:
      v3 = *(_WORD *)((char *)_this + 6312);
      goto LABEL_5;
    case 4:
      v3 = *(_WORD *)((char *)_this + 6296);
      goto LABEL_5;
    case 5:
      v3 = *(_WORD *)((char *)_this + 6392);
      goto LABEL_5;
    case 6:
      v3 = *(_WORD *)((char *)_this + 6344);
LABEL_5:
      v4 = pParty_global->pPartyBuffs[2].word_000008;
      return v4 + v3;
    case 9:
      v3 = *(_WORD *)((char *)_this + 6280);
      v4 = pParty_global->pPartyBuffs[SPELLBUFF_WATERWALK].word_000008;
      return v4 + v3;
    default:
      return result;
  }
  return result;
}

//----- (00490141) --------------------------------------------------------
Character::Sex::Type Player_GetSexByVoice(Player *_this)
{
 switch (_this->dword_001920)
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
    return Character::Sex::Male;

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
    return Character::Sex::Female;
 }
}

//----- (0048EAAE) --------------------------------------------------------
int Player_MaybeGetWearItemsBonus(struct Player *_this, signed int a2, int a3) 
{
 //a2 ==
   //4:   accuracy
   //25:  attack


  signed int v3; // eax@1
  //void *v4; // ebx@1
  int v5; // edi@1
  signed int v6; // esi@1
  //void *v8; // ecx@48
  int v9; // eax@49
  //int v10; // edx@49
  //void *v11; // ecx@55
  int v12; // eax@56
  //int v13; // edx@56
  int v14; // eax@58
  int v15; // ecx@58
  //void *v16; // ecx@61
  int v17; // eax@62
  //void *v18; // ecx@66
  int v19; // eax@67
  int v20; // eax@69
  //void *v21; // ecx@75
  int v22; // eax@76
  int v23; // edx@76
  //int v24; // eax@79
  int v25; // ecx@80
  int v26; // edi@80
  //void *v27; // ecx@84
  int v28; // eax@85
  int v29; // edx@85
  //void *v30; // ecx@96
  int v31; // ebp@97
  int v32; // eax@98
  int v33; // eax@100
  int v34; // eax@103
  char v35; // zf@104
  char v36; // zf@107
  unsigned __int8 v37; // zf@119
  char v38; // sf@119
  unsigned __int8 v39; // of@119
  char v40; // zf@122
  char v41; // zf@145
  char v42; // zf@164
  char v43; // zf@173
  char v44; // zf@189
  char v45; // zf@198
  char v46; // zf@239
  int v47; // eax@268
  int v48; // eax@269
  int v49; // eax@291
  char v50; // zf@295
  int v51; // eax@306
  int v52; // eax@307
  char v53; // zf@312
  char v54; // zf@336
  char v55; // zf@348
  int v56; // eax@365
  int v57; // ebx@368
  signed int v58; // [sp-4h] [bp-20h]@10
  signed int v59; // [sp-4h] [bp-20h]@71
  signed int v60; // [sp-4h] [bp-20h]@347
  int v61; // [sp+10h] [bp-Ch]@1
  int v62; // [sp+14h] [bp-8h]@1
  //int v63; // [sp+18h] [bp-4h]@101
  //int v64; // [sp+20h] [bp+4h]@101
  int v65; // [sp+24h] [bp+8h]@95
  v29=0; ///to prevent crash
  v6 = a2;
  v3 = 36;
  v5 = 0;
  //v4 = _this;
  v62 = 0;
  v61 = 0;
  if ( a2 > 36 )
  {
    switch ( a2 )
    {
      case 37:
        v58 = 15;
        goto LABEL_35;
      case 38:
        v58 = 16;
        goto LABEL_35;
      case 39:
        v58 = 17;
        goto LABEL_35;
      case 40:
        v58 = 18;
        goto LABEL_35;
      case 41:
        v58 = 19;
        goto LABEL_35;
      case 42:
        v58 = 20;
        goto LABEL_35;
      case 43:
        v58 = 25;
        goto LABEL_35;
      case 44:
        v58 = 5;
        goto LABEL_35;
      case 45:
        v58 = 8;
        goto LABEL_35;
      case 46:
        goto LABEL_36;
      default:
        break;
    }
  }
  else
  {
    if ( a2 == 36 )
    {
      v58 = 14;
    }
    else
    {
      if ( a2 > 21 )
      {
        switch ( a2 )
        {
          case 22:
            v58 = 30;
            break;
          case 23:
            v58 = 31;
            break;
          case 34:
            v58 = 12;
            break;
          default:
            if ( a2 != 35 )
              goto LABEL_38;
            v58 = 13;
            break;
        }
      }
      else
      {
        switch ( a2 )
        {
          case 21:
            v58 = 33;
            break;
          case 16:
            v58 = 35;
            break;
          case 17:
            v58 = 34;
            break;
          case 18:
            v58 = 29;
            break;
          case 19:
            v58 = 21;
            break;
          default:
            if ( a2 != 20 )
              goto LABEL_38;
            v58 = 32;
            break;
        }
      }
    }
LABEL_35:
    v3 = v58;
LABEL_36:
    if ( !*((_WORD *)_this + v3 + 132) )
      return 0;
  }
LABEL_38:
  if ( a2 > 28 )
  {
    if ( a2 < 29 )
      return v5 + v62 + v61;
    if ( a2 <= 30 )
    {
      if ( Player_sub_48D6AA(_this, 2) )
        v5 = (*&pClass40->pItems[0].uEquipType + *((_DWORD *)_this + 9 * *((_DWORD *)_this + 1620) + 124) + 4);
      return v5 + v62 + v61;
    }
    if ( a2 == 31 )
    {
      if ( !Player_sub_48D6AA(_this, 2) )
        return v5 + v62 + v61;
      v57 = *((_DWORD *)_this + 9 * *((_DWORD *)_this + 1620) + 124);
      v5 = pClass40->pItems[v57 - 1].uDamageModifier;
      v56 = pClass40->pItems[v57 -1].uDamageDice;
      goto LABEL_366;
    }
    if ( a2 == 32 )
    {
      if ( !Player_sub_48D6AA(_this, 2) )
        return v5 + v62 + v61;
      v20 = 48 * *((_DWORD *)_this + 9 * *((_DWORD *)_this + 1620) + 124);
      v5 = *(&pClass40->pItems[0].uDamageDice + v20) * *(&pClass40->pItems[0].uDamageRoll + v20);
LABEL_365:
      v56 = *(&pClass40->pItems[0].uDamageModifier + v20);
LABEL_366:
      v5 += v56;
      return v5 + v62 + v61;
    }
    if ( a2 <= 33 || a2 > 46 )
      return v5 + v62 + v61;
LABEL_95:
    v65 = 0;
    while ( 1 )
    {
      if ( !Player_sub_48D6AA(_this, v65) )
        goto LABEL_361;
      v31 = _this->pEquippedItemIndices[v65];
      if ( v6 == 9 )
      {
        v32 = Player_GetEquippedItemEquipType(_this, v65);
        if ( v32 >= 3 )
        {
          if ( v32 <= 11 )
          {
           v33 = 48 * _this->pInventorySlots[v31].uItemID;
            v5 += pClass40->pItems[v33/48].uDamageDice + pClass40->pItems[v33/48].uDamageModifier;
          }
        }
      }
      //v63 = (int)((char *)v4 + 36 * v31);
      //v64 = v63 + 0x214;
      if ( class40_sub_456D5E(pClass40, &_this->pInventorySlots[v31]) == 1 &&
          !class40_sub_456D43(pClass40, &_this->pInventorySlots[v31]) )
      {
        v34 = _this->pInventorySlots[v31].uItemID;
        switch (_this->pInventorySlots[v31].uItemID)
        {
          case 0x1F4:
            v35 = v6 == 5;
            goto LABEL_105;
          case 0x1F5:
            v36 = v6 == 0;
            goto LABEL_108;
          case 0x1F6:
            if ( v6 == 21 )
              v61 += 10;
            v36 = v6 == 2;
            goto LABEL_108;
          case 0x1F7:
            if ( v6 == 17 )
              v61 += 5;
            if ( v6 == 18 )
              v61 += 5;
            v36 = v6 == 6;
            goto LABEL_108;
          case 0x1F8:
            goto LABEL_118;
          case 0x1F9:
            v40 = v6 == 3;
            goto LABEL_123;
          case 0x1FA:
            v35 = v6 == 10;
            goto LABEL_105;
          case 0x1FE:
            v35 = v6 == 4;
            goto LABEL_105;
          case 0x1FF:
            if ( v6 == 23 )
              v61 += 10;
            if ( v6 == 22 )
              v61 += 10;
            goto LABEL_361;
          case 0x200:
            if ( v6 == 36 )
            {
              LOBYTE(v34) = *((_BYTE *)_this + 292);
              v62 = ((unsigned int)v34 >> 1) & 0x1F;
            }
            v36 = v6 == 5;
LABEL_108:
            if ( v36 )
              v5 += 40;
            goto LABEL_361;
          case 0x201:
            if ( v6 == 39 )
            {
              LOBYTE(v34) = *((_BYTE *)_this + 298);
              v34 = ((unsigned int)v34 >> 1) & 0x1F;
              v62 = v34;
            }
            goto LABEL_136;
          case 0x202:
            if ( !v6 )
              v5 += 150;
            if ( v6 == 1 )
              v5 -= 40;
            if ( v6 == 2 )
              v5 -= 40;
            goto LABEL_145;
          case 0x203:
            if ( v6 == 42 )
            {
              LOBYTE(v34) = *((_BYTE *)_this + 304);
              v62 = ((unsigned int)v34 >> 1) & 0x1F;
            }
            if ( v6 == 43 )
              v61 += 15;
            goto LABEL_361;
          case 0x204:
            if ( v6 == 17 )
              v61 += 5;
            if ( v6 == 18 )
              v61 += 5;
            if ( v6 == 6 )
              v5 += 50;
            if ( v6 == 11 || v6 == 10 || v6 == 12 || v6 == 13 || v6 == 33 || v6 == 14 )
              goto LABEL_166;
            v42 = v6 == 15;
            goto LABEL_165;
          case 0x205:
            if ( v6 == 18 )
              v61 += 5;
            goto LABEL_361;
          case 0x206:
            if ( !v6 )
              v5 += 100;
            if ( v6 == 3 )
              v5 += 100;
            v43 = v6 == 9;
            goto LABEL_174;
          case 0x207:
            if ( v6 == 45 )
              v61 += 5;
            if ( v6 == 15 )
              v5 -= 10;
            v42 = v6 == 14;
LABEL_165:
            if ( v42 )
LABEL_166:
              v5 -= 10;
            goto LABEL_361;
          case 0x208:
            v35 = v6 == 3;
            goto LABEL_105;
          case 0x209:
            if ( v6 == 2 )
              v5 += 15;
            if ( !v6 )
              v5 += 15;
            v41 = v6 == 6;
            goto LABEL_146;
          case 0x20A:
            if ( v6 == 46 )
              v61 += 15;
            v44 = v6 == 3;
            goto LABEL_190;
          case 0x20B:
            if ( v6 == 34 )
            {
              LOBYTE(v34) = *((_BYTE *)_this + 288);
              v62 = ((unsigned int)v34 >> 1) & 0x1F;
            }
            if ( v6 == 12 )
              v5 += 50;
            if ( v6 == 2 )
              v5 += 30;
            v45 = v6 == 9;
            goto LABEL_199;
          case 0x20C:
            if ( !v6 )
              v5 += 75;
            goto LABEL_145;
          case 0x20D:
            if ( v6 == 5 )
              v5 += 50;
            if ( v6 == 6 )
              v5 += 50;
            if ( v6 == 11 || v6 == 10 || v6 == 12 || v6 == 13 || v6 == 33 || v6 == 14 )
              goto LABEL_374;
            v43 = v6 == 15;
LABEL_174:
            if ( v43 )
LABEL_374:
              v5 -= 15;
            goto LABEL_361;
          case 0x20E:
            if ( v6 == 4 )
              v5 += 150;
            if ( v6 == 44 )
              v61 += 5;
            if ( v6 == 9 )
              v5 -= 25;
            goto LABEL_361;
          case 0x20F:
            if ( v6 == 39 )
            {
              LOBYTE(v34) = *((_BYTE *)_this + 298);
              v34 = ((unsigned int)v34 >> 1) & 0x1F;
              v62 = v34;
            }
            if ( v6 == 40 )
            {
              LOBYTE(v34) = *((_BYTE *)_this + 300);
              v62 = ((unsigned int)v34 >> 1) & 0x1F;
            }
LABEL_145:
            v41 = v6 == 5;
LABEL_146:
            if ( v41 )
              v5 -= 40;
            goto LABEL_361;
          case 0x210:
            if ( v6 == 38 )
            {
              LOBYTE(v34) = *((_BYTE *)_this + 296);
              v62 = ((unsigned int)v34 >> 1) & 0x1F;
            }
            if ( !v6 )
              v5 += 75;
            v44 = v6 == 11;
LABEL_190:
            if ( v44 )
              v5 -= 50;
            goto LABEL_361;
          case 0x211:
            if ( v6 == 5 )
              v5 += 100;
            if ( v6 == 4 )
              v5 += 50;
            v35 = v6 == 11;
LABEL_105:
            if ( v35 )
              v5 += 50;
            goto LABEL_361;
          case 0x212:
            if ( v6 == 1 )
              v5 -= 20;
            v45 = v6 == 2;
LABEL_199:
            if ( v45 )
              v5 -= 20;
            goto LABEL_361;
          case 0x214:
            if ( v6 == 1 )
              v5 += 15;
            v46 = v6 == 2;
            goto LABEL_240;
          case 0x215:
            if ( v6 == 5 )
              v5 += 15;
            v46 = v6 == 4;
            goto LABEL_240;
          case 0x216:
            if ( v6 == 10 )
              v5 += 30;
            if ( !v6 )
              v5 += 15;
            goto LABEL_315;
          case 0x217:
            if ( v6 == 21 )
              v61 += 5;
            if ( !v6 )
              v5 += 15;
            goto LABEL_253;
          case 0x218:
            goto LABEL_253;
          default:
            goto LABEL_361;
        }
        goto LABEL_361;
      }
      if (_this->pInventorySlots[v31].dword_000004 == v6 + 1 )
      {
        if ( v6 >= 0 )
        {
          if ( v6 <= 15 )
          {
            v5 += *((_DWORD *)_this + 9 * v31 + 135);
          }
          else
          {
            if ( v6 <= 23 )
            {
              if ( v5 < *((_DWORD *)_this + 9 * v31 + 135) )
                v5 = *((_DWORD *)_this + 9 * v31 + 135);
            }
          }
        }
        goto LABEL_361;
      }
      v34 = _this->pInventorySlots[v31].dword_00000C;
      if ( v34 > 48 )
      {
        switch ( v34 )
        {
          case 54:
            goto LABEL_315;
          case 49:
            if ( v6 == 6 )
              goto LABEL_121;
            v50 = v6 == 1;
            goto LABEL_296;
          case 51:
            if ( v6 != 5 && v6 != 1 )
              goto LABEL_309;
            goto LABEL_121;
          case 52:
            if ( v6 == 3 )
              goto LABEL_121;
            v50 = v6 == 4;
            goto LABEL_296;
          case 53:
            if ( !v6 )
              goto LABEL_121;
            v50 = v6 == 2;
            goto LABEL_296;
          case 55:
            v46 = v6 == 6;
            goto LABEL_240;
          case 56:
            if ( !v6 )
              goto LABEL_351;
            v53 = v6 == 3;
            goto LABEL_350;
          case 57:
            if ( v6 == 1 )
              goto LABEL_351;
            v53 = v6 == 2;
            goto LABEL_350;
          case 50:
            if ( v6 == 10 )
              v5 += 30;
            goto LABEL_361;
          case 60:
            if ( v6 != 23 )
              goto LABEL_336;
            if ( v5 >= 3 )
              goto LABEL_361;
            v5 = 3;
LABEL_336:
            v54 = v6 == 22;
            goto LABEL_345;
          case 61:
            if ( v6 != 17 )
              goto LABEL_340;
            if ( v5 >= 3 )
              goto LABEL_361;
            v5 = 3;
LABEL_340:
            v54 = v6 == 18;
            goto LABEL_345;
          case 62:
            if ( v6 != 19 )
              goto LABEL_344;
            if ( v5 >= 3 )
              goto LABEL_361;
            v5 = 3;
LABEL_344:
            v54 = v6 == 20;
LABEL_345:
            if ( !v54 )
              goto LABEL_361;
            if ( v5 >= 3 )
              goto LABEL_361;
            v60 = 3;
            goto LABEL_360;
          case 67:
            v55 = v6 == 18;
            goto LABEL_357;
          case 68:
            v53 = v6 == 9;
            goto LABEL_350;
          case 69:
            if ( v6 == 11 )
              v5 += 20;
            break;
          case 70:
            if ( v6 == 12 )
              v5 += 10;
            v55 = v6 == 16;
LABEL_357:
            if ( v55 && v5 < 2 )
            {
              v60 = 2;
LABEL_360:
              v5 = v60;
            }
            break;
          default:
            goto LABEL_361;
        }
        goto LABEL_361;
      }
      if ( v34 == 48 )
      {
        if ( v6 == 9 )
          v5 += 5;
LABEL_315:
        v46 = v6 == 3;
LABEL_240:
        if ( v46 )
          v5 += 15;
        goto LABEL_361;
      }
      if ( v34 > 32 )
      {
        if ( v34 > 44 )
        {
          v51 = v34 - 45;
          if ( !v51 )
          {
            if ( v6 == 5 )
              goto LABEL_351;
            v53 = v6 == 4;
LABEL_350:
            if ( v53 )
LABEL_351:
              v5 += 5;
            goto LABEL_361;
          }
          v52 = v51 - 1;
          if ( !v52 )
          {
            v40 = v6 == 0;
LABEL_123:
            if ( v40 )
              v5 += 25;
            goto LABEL_361;
          }
          if ( v52 == 1 )
          {
LABEL_309:
            v50 = v6 == 8;
            goto LABEL_296;
          }
        }
        else
        {
          if ( v34 == 44 )
          {
            v50 = v6 == 7;
            goto LABEL_296;
          }
          v34 -= 33;
          if ( !v34 )
          {
            if ( v6 != 38 )
              goto LABEL_361;
            LOBYTE(v34) = *((_BYTE *)_this + 296);
            goto LABEL_138;
          }
          --v34;
          if ( !v34 )
          {
            if ( v6 != 36 )
              goto LABEL_361;
            LOBYTE(v34) = *((_BYTE *)_this + 292);
            goto LABEL_138;
          }
          v49 = v34 - 8;
          if ( !v49 )
          {
            if ( v6 >= 0 )
            {
              if ( v6 <= 15 )
                ++v5;
            }
            goto LABEL_361;
          }
          if ( v49 == 1 )
          {
            if ( v6 != 3 && v6 != 7 )
            {
              v50 = v6 == 9;
LABEL_296:
              if ( !v50 )
                goto LABEL_361;
            }
LABEL_121:
            v5 += 10;
            goto LABEL_361;
          }
        }
      }
      else
      {
        if ( v34 == 32 )
        {
          if ( v6 != 39 )
            goto LABEL_361;
          LOBYTE(v34) = *((_BYTE *)_this + 298);
          goto LABEL_138;
        }
        if ( v34 > 28 )
        {
          v34 -= 29;
          if ( v34 )
          {
            --v34;
            if ( v34 )
            {
              --v34;
              if ( v34 || v6 != 41 )
                goto LABEL_361;
              LOBYTE(v34) = *((_BYTE *)_this + 302);
            }
            else
            {
              if ( v6 != 34 )
                goto LABEL_361;
              LOBYTE(v34) = *((_BYTE *)_this + 288);
            }
          }
          else
          {
            if ( v6 != 37 )
              goto LABEL_361;
            LOBYTE(v34) = *((_BYTE *)_this + 294);
          }
          goto LABEL_138;
        }
        if ( v34 == 28 )
        {
LABEL_136:
          if ( v6 == 42 )
          {
            LOBYTE(v34) = *((_BYTE *)_this + 304);
LABEL_138:
            v62 = ((unsigned int)v34 >> 1) & 0x1F;
            goto LABEL_361;
          }
        }
        else
        {
          v47 = v34 - 1;
          if ( v47 )
          {
            v48 = v47 - 1;
            if ( v48 )
            {
              v34 = v48 - 24;
              if ( v34 )
              {
                --v34;
                if ( v34 || v6 != 40 )
                  goto LABEL_361;
                LOBYTE(v34) = *((_BYTE *)_this + 300);
              }
              else
              {
                if ( v6 != 35 )
                  goto LABEL_361;
                LOBYTE(v34) = *((_BYTE *)_this + 290);
              }
              goto LABEL_138;
            }
LABEL_118:
            if ( v6 < 0 )
              goto LABEL_361;
            compile_error();//v39 = __SETO__(v6, 6);
            v37 = v6 == 6;
            v38 = v6 - 6 < 0;
          }
          else
          {
LABEL_253:
            if ( v6 < 10 )
              goto LABEL_361;
            compile_error();//v39 = __SETO__(v6, 15);
            v37 = v6 == 15;
            v38 = v6 - 15 < 0;
          }
          if ( (unsigned __int8)(v38 ^ v39) | v37 )
            goto LABEL_121;
        }
      }
LABEL_361:
      ++v65;
      if ( v65 >= 16 )
        return v5 + v62 + v61;
    }
  }
  if ( a2 == 28 )
  {
    if ( Player_sub_48D676(_this) != 1 )
    {
      if ( Player_sub_48D6AA(_this, 1) )
      {
        v22 = Player_GetEquippedItemEquipType(_this, 1);
        if ( v22 >= 0 )
        {
          if ( v22 <= 2 )
          {
           v23 = _this->pInventorySlots[_this->pEquippedItemIndices[1]].uItemID;

            if (_this->pEquippedItemIndices[0] != -1 || pClass40->pItems[v23].uSkillType != Character::Skill::Spear)
            {
              v26 = pClass40->pItems[v23].uDamageRoll;
              v25 = pClass40->pItems[v23].uDamageDice;
            }
            else
            {
             v25 = pClass40->pItems[v23].uDamageRoll;
              v26 = pClass40->pItems[v23].uDamageDice + 1;
            }
            v5 = pClass40->pItems[v23].uDamageModifier + v25 * v26;
          }
        }
      }
      if ( a3 || !Player_sub_48D6AA(_this, 0) || (v28 = Player_GetEquippedItemEquipType(_this, 0), v28 < 0) || v28 > 2 )
        return v5 + v62 + v61;
      v14 = pClass40->pItems[v29].uDamageModifier;
      v15 = pClass40->pItems[v29].uDamageDice * pClass40->pItems[v29].uDamageRoll;
      goto LABEL_88;
    }
    v59 = 3;
LABEL_74:
    v5 = v59;
    return v5 + v62 + v61;
  }
  if ( a2 < 0 )
    return v5 + v62 + v61;
  if ( a2 <= 23 )
    goto LABEL_95;
  if ( a2 == 24 )
  {
    if ( !Player_sub_48D6D0(_this, 25) )
      return v5 + v62 + v61;
    v59 = 5;
    goto LABEL_74;
  }
  if ( a2 <= 24 )
    return v5 + v62 + v61;
  if ( a2 <= 26 )
  {
    if ( Player_sub_48D676(_this) == 1 )
    {
      v5 = 0;
      return v5 + v62 + v61;
    }
    if ( Player_sub_48D6AA(_this, 1) )
    {
      v17 = Player_GetEquippedItemEquipType(_this, 1);
      if ( v17 >= 0 )
      {
        if ( v17 <= 2 )
         v5 = pClass40->pItems[*((_DWORD *)_this + 9 * *((_DWORD *)_this + 1619) + 124)].uDamageModifier;
      }
    }
    if ( a3 || !Player_sub_48D6AA(_this, 0) || (v19 = Player_GetEquippedItemEquipType(_this, 0), v19 < 0) || v19 > 2 )
      return v5 + v62 + v61;
    v20 = 48 * *((_DWORD *)_this + 9 * *((_DWORD *)_this + 1618) + 124);
    goto LABEL_365;
  }
  if ( a2 == 27 )
  {
    if ( Player_sub_48D676(_this) == 1 )
    {
      v5 = 1;
      return v5 + v62 + v61;
    }
    if ( Player_sub_48D6AA(_this, 1) )
    {
      v9 = Player_GetEquippedItemEquipType(_this, 1);
      if ( v9 >= 0  && v9 <= 2 )
      {
         v5 = pClass40->pItems[_this->pInventorySlots[_this->pEquippedItemIndices[1]].uItemID].uDamageDice +
              pClass40->pItems[_this->pInventorySlots[_this->pEquippedItemIndices[1]].uItemID].uDamageModifier;
          if (_this->pEquippedItemIndices[0] == -1)
          {
           if (pClass40->pItems[_this->pInventorySlots[_this->pEquippedItemIndices[1]].uItemID].uSkillType == Character::Skill::Spear)
              ++v5;
          }
      }
    }
    if ( a3 || !Player_sub_48D6AA(_this, 0) || (v12 = Player_GetEquippedItemEquipType(_this, 0), v12 < 0) || v12 > 2 )
      return v5 + v62 + v61;
    v15 = pClass40->pItems[_this->pInventorySlots[_this->pEquippedItemIndices[0]].uItemID].uDamageModifier;
    v14 = pClass40->pItems[_this->pInventorySlots[_this->pEquippedItemIndices[0]].uItemID].uDamageDice;
LABEL_88:
    v5 += v14 + v15;
  }
  return v5 + v62 + v61;
}




//----- (new) --------------------------------------------------------
unsigned int FindPlaceForItemInInventory(struct Player *_this, unsigned int uItemID)
{
 unsigned int uNumSlotsX;
  cTexture *v4; // esi@1
  int v5; // eax@1
  //int v6; // edi@5
  //int v7; // ecx@6
  //int v8; // edx@7
  //int *v9; // eax@8
  //void *v11; // [sp+Ch] [bp-4h]@1
 unsigned int uNumSlotsY;


#ifndef OLD_CODE
 wchar_t pFilename[256];
 wsprintfW(pFilename, L"%S", pClass40->pItems[uItemID].pIconName);

 v5 = LODFile_Icons_LOD.LODFile_LoadTexture_New(pFilename);
#else
 v5 = LODFile_Icons_LOD.LODFile_LoadTexture((const char *)pClass40->pItems[uItemID].pIconName, 2);
#endif
 v4 = &LODFile_Icons_LOD.aLODHeaders[v5];

 uNumSlotsX = GetSizeInInventorySlots(v4->uTextureWidth);
 uNumSlotsY = GetSizeInInventorySlots(v4->uTextureHeight);

  if ( !bTextureLoading )
  {
   runtime_warning("When texture is unavailable, -1 index is returned. Then, here -1 index overwrites the LODFile containing the textures");
    cTexture_Free(v4);
    LODFile_Icons_LOD.LODFile_sub_40F9C5();
  }

 for (unsigned int uSlotY = 0; uSlotY < 10 - uNumSlotsY; ++uSlotY)
   for (unsigned int uSlotX = 0; uSlotX < 15 - uNumSlotsX; ++uSlotX)
   {
    unsigned int uFits = true;
    for (unsigned int y = uSlotY; y < uSlotY + uNumSlotsY; ++y)
    {
     for (unsigned int x = uSlotX; x < uSlotX + uNumSlotsX; ++x)
       if (_this->pInventoryIndices[y * 14 + x] != -1)
       {
        uFits = false;
        break;
       }

     if (!uFits)
       break;
    }

    if (uFits)
      return uSlotY * 14 + uSlotX;
   }
 return -1;
}


//----- (00492528) --------------------------------------------------------
bool CanPlaceItemInInventory(struct Player *_this, unsigned int uInventorySlot, unsigned int uItemID)
{
 unsigned int uNumSlotsX;
  cTexture *v4; // esi@1
  int v5; // eax@1
  //int v6; // edi@5
  //int v7; // ecx@6
  //int v8; // edx@7
  //int *v9; // eax@8
  //void *v11; // [sp+Ch] [bp-4h]@1
 unsigned int uNumSlotsY;


#ifndef OLD_CODE
 wchar_t pFilename[256];
 wsprintfW(pFilename, L"%S", pClass40->pItems[uItemID].pIconName);

 v5 = LODFile_Icons_LOD.LODFile_LoadTexture_New(pFilename);
#else
 v5 = LODFile_Icons_LOD.LODFile_LoadTexture((const char *)pClass40->pItems[uItemID].pIconName, 2);
#endif
 v4 = &LODFile_Icons_LOD.aLODHeaders[v5];

 uNumSlotsX = GetSizeInInventorySlots(v4->uTextureWidth);
 uNumSlotsY = GetSizeInInventorySlots(v4->uTextureHeight);

  if ( !bTextureLoading )
  {
   runtime_warning("When texture is unavailable, -1 index is returned. Then, here -1 index overwrites the LODFile containing the textures");
   if  (v4>=0)
    cTexture_Free(v4);
    LODFile_Icons_LOD.LODFile_sub_40F9C5();
  }

 unsigned int uInventorySlotX = uInventorySlot % 14,
              uInventorySlotY = uInventorySlot / 14;
 if (uNumSlotsX + uInventorySlotX > 14 ||
     uNumSlotsY + uInventorySlotY > 9)
   return false;   // won't fit rightside


 unsigned int uFits = true;
 for (unsigned int y = uInventorySlotY; y < uInventorySlotY + uNumSlotsY; ++y)
 {
  for (unsigned int x = uInventorySlotX; x < uInventorySlotX + uNumSlotsX; ++x)
    if (_this->pInventoryIndices[y * 14 + x] != -1)
    {
     uFits = false;
     break;
    }

  if (!uFits)
    break;
 }

 return uFits;
}






//----- (new) --------------------------------------------------------
unsigned int FindPlaceForItemInInventory(struct Player *_this, ItemGen *pItem)
{
 unsigned int uNumSlotsX;
  cTexture *v4; // esi@1
  int v5; // eax@1
 unsigned int uNumSlotsY;


#ifndef OLD_CODE
 wchar_t pFilename[256];
 wsprintfW(pFilename, L"%S", pClass40->pItems[pItem->uItemID].pIconName);

 v5 = LODFile_Icons_LOD.LODFile_LoadTexture_New(pFilename);
#else
 v5 = LODFile_Icons_LOD.LODFile_LoadTexture((const char *)pClass40->pItems[pItem->uItemID].pIconName, 2);
#endif
 v4 = &LODFile_Icons_LOD.aLODHeaders[v5];

 uNumSlotsX = GetSizeInInventorySlots(v4->uTextureWidth);
 uNumSlotsY = GetSizeInInventorySlots(v4->uTextureHeight);

  if ( !bTextureLoading )
  {
   runtime_warning("When texture is unavailable, -1 index is returned. Then, here -1 index overwrites the LODFile containing the textures");
   if  (v4>=0)
     cTexture_Free(v4);
    LODFile_Icons_LOD.LODFile_sub_40F9C5();
  }

 for (unsigned int uSlotY = 0; uSlotY < 10 - uNumSlotsY; ++uSlotY)
   for (unsigned int uSlotX = 0; uSlotX < 15 - uNumSlotsX; ++uSlotX)
   {
    unsigned int uFits = true;
    for (unsigned int y = uSlotY; y < uSlotY + uNumSlotsY; ++y)
    {
     for (unsigned int x = uSlotX; x < uSlotX + uNumSlotsX; ++x)
       if (_this->pInventoryIndices[y * 14 + x] != -1)
       {
        uFits = false;
        break;
       }

     if (!uFits)
       break;
    }

    if (uFits)
      return uSlotY * 14 + uSlotX;
   }
 return -1;
}


//----- (00492826) --------------------------------------------------------
unsigned int AddItem(struct Player *_this, unsigned int uInventorySlot, struct ItemGen *pItem)
{
  int v3; // ebx@1
  signed int v4; // edi@3
  signed int v5; // esi@3
  signed int v10; // [sp+18h] [bp+8h]@2

 v3 = pItem->uItemID;
 class40_sub_456D17(pClass40, pItem);

 if (uInventorySlot == -1)
 {
  uInventorySlot = FindPlaceForItemInInventory(_this, pItem);
  if (uInventorySlot == -1)
  {
   if (uActiveCharacter)
     Player_PlaySound(pPlayers[uActiveCharacter - 1], Character::Voice::NoRoom, 0);

   return -1;
  }

  return CreateItemInInventory(_this, uInventorySlot, pItem);
  /*
    v10 = 0;
    while ( 2 )
    {
      v5 = v10;
      v4 = 0;
      do
      {
        if ( CanPlaceItemInInventory(_this, v5, v3) )
        {
          return CreateItemInInventory(_this, v5, pItem);
        }
        ++v4;
        v5 += 14;
      }
      while ( v4 < 14 );
      ++v10;
      if ( v10 < 9 )
        continue;
      break;
    }
    return 0;*/
 }

 if (!CanPlaceItemInInventory(_this, uInventorySlot, pItem->uItemID))
 {
  if (uActiveCharacter)
    Player_PlaySound(pPlayers[uActiveCharacter - 1], Character::Voice::NoRoom, 0);

   return -1;
 }
 return CreateItemInInventory(_this, uInventorySlot, pItem);
}

//----- (0049289C) ----------------.text:004943FA  ----------------------------------------
unsigned int CreateItemInInventory(struct Player *_this, unsigned int uInventorySlot, struct ItemGen *pItem)
{
  //int v3, i, x; // eax@1
  //signed int  items_count; // ebx@1
  //int result; // eax@6
  cTexture *v6; // esi@7
  int v7; // eax@7
  //void *v9; // esi@10
  //int  slotsW; // [sp+4h] [bp-Ch]@7
  //int slotsH; // [sp+8h] [bp-8h]@7
  //void *v13; // [sp+Ch] [bp-4h]@1
  



 unsigned int uItemsPoolSlotID = -1;
 for (unsigned int i = 0; i < 126; ++i)
   if (_this->pInventorySlots[i].uItemID == -1)
   {
    uItemsPoolSlotID = i;
    break;
   }

 if (uItemsPoolSlotID == -1)
   return -1;

#ifndef OLD_CODE
 wchar_t pItemIconNameW[64];

 MultiByteToWideChar(CP_ACP, 0, (char *)pClass40->pItems[pItem->uItemID].pIconName, -1, pItemIconNameW, 64);
 v7 = LODFile_Icons_LOD.LODFile_LoadTexture_New(pItemIconNameW);
#else
 v7 = LODFile_Icons_LOD.LODFile_LoadTexture((char *)pClass40->pItems[pItem->uItemID].pIconName,2);
#endif

 v6 = &LODFile_Icons_LOD.aLODHeaders[v7];
 unsigned int uItemSizeX = GetSizeInInventorySlots(v6->uTextureWidth),
              uItemSizeY = GetSizeInInventorySlots(v6->uTextureHeight);

    if ( !bTextureLoading )
    {
     runtime_warning("When texture is unavailable, -1 index is returned. Then, here -1 index overwrites the LODFile containing the textures");
	 if  (v6>=0)
      cTexture_Free(v6);
      LODFile_Icons_LOD.LODFile_sub_40F9C5();
    }

    /*if ( uNumSlotsY > 0 ) // reserving space for large items in inventory
    {
      for(x = uInventorySlot; uNumSlotsY-- != 0; x+=14) // 14 is the columns count, so getting to next row
      {
        for(i = 0; i < uNumSlotsX; i++) // filling number of columns horizontally
         _this->pInventoryIndices[x + i] = -1 - uInventorySlot;
      }
    }*/

 // fill X x Y area of pInvIndices with index, item form pool with ID
 unsigned int uInventorySlotX = uInventorySlot % 14,
              uInventorySlotY = uInventorySlot / 14;
 for (unsigned int y = uInventorySlotY; y < uInventorySlotY + uItemSizeY; ++y)
   for (unsigned int x = uInventorySlotX; x < uInventorySlotX + uItemSizeX; ++x)
      _this->pInventoryIndices[y * 14 + x] = uItemsPoolSlotID;

 _this->pInventoryIndices[uInventorySlotY * 14 + uInventorySlotX] |= 0x80000000; // draw flag. the whole inventory thing is a hack
 memcpy(&_this->pInventorySlots[uItemsPoolSlotID], pItem, sizeof(ItemGen));
  //}
 return uItemsPoolSlotID;
}

//----- (00492600) --------.text:00494156  ------------------------------------------------
unsigned int CreateItemInInventory(struct Player *_this, unsigned int uInventorySlot, unsigned int uItemID)
{
  //int v3;
  //int i, x; // eax@1
  //signed int v4; // edx@1
  //int result; // eax@8
 cTexture *v7; // esi@10
  int v8; // eax@10
  void *v9; // esi@13
  //int slotsW; // [sp+0h] [bp-Ch]@10
  //void *v12; // [sp+4h] [bp-8h]@1
  //signed int v13; // [sp+8h] [bp-4h]@4
  //int slotsH; // [sp+18h] [bp+Ch]@10

  //v12 = _this;
  //v4 = 0;
  //v3 = (int)((char *)_this + 532);  //pInventorySlots


 unsigned int uItemsPoolSlotID = -1;
 for (unsigned int i = 0; i < 126; ++i)
   if (_this->pInventorySlots[i].uItemID == -1)
   {
    uItemsPoolSlotID = i;
    break;
   }

 if (uItemsPoolSlotID == -1)
   return -1;
  /*
  v3 = _this->pInventorySlots[v4].uItemID;
  while (v3 )
  {
    ++v4;
    v3 = _this->pInventorySlots[v4].uItemID;
    if ( v4 >= 126 )
    {
      v13 = -1;
      break;
    }
  }
  v13 = v4;
  if ( v13 == -1 )
  {
    if ( uActiveCharacter )
      Player_PlaySound(pPlayers[uActiveCharacter - 1], Character::Voice::NoRoom, 0);
    result = 0;
  }
  else
  {*/
#ifndef OLD_CODE
 wchar_t pItemIconNameW[64];

 MultiByteToWideChar(CP_ACP, 0, (char *)pClass40->pItems[uItemID].pIconName, -1, pItemIconNameW, 64);
 v8 = LODFile_Icons_LOD.LODFile_LoadTexture_New(pItemIconNameW);
#else
 v8 = LODFile_Icons_LOD.LODFile_LoadTexture((char *)pClass40->pItems[uItemID].pIconName,2);
#endif

 v7 = &LODFile_Icons_LOD.aLODHeaders[v8];
 unsigned int uItemSizeX = GetSizeInInventorySlots(v7->uTextureWidth),
              uItemSizeY = GetSizeInInventorySlots(v7->uTextureHeight);

    if ( !bTextureLoading )
    {
     runtime_warning("When texture is unavailable, -1 index is returned. Then, here -1 index overwrites the LODFile containing the textures");
	 if  (v7>=0)
      cTexture_Free(v7);
      LODFile_Icons_LOD.LODFile_sub_40F9C5();
    }

    /*if ( uNumSlotsY > 0 ) // reserving space for large items in inventory
    {
      for(x = uInventorySlot; uNumSlotsY-- != 0; x+=14) // 14 is the columns count, so getting to next row
      {
        for(i = 0; i < uNumSlotsX; i++) // filling number of columns horizontally
         _this->pInventoryIndices[x + i] = -1 - uInventorySlot;
      }
    }*/

 // fill X x Y area of pInvIndices with index, item form pool with ID
 unsigned int uInventorySlotX = uInventorySlot % 14,
              uInventorySlotY = uInventorySlot / 14;
 for (unsigned int y = uInventorySlotY; y < uInventorySlotY + uItemSizeY; ++y)
   for (unsigned int x = uInventorySlotX; x < uInventorySlotX + uItemSizeX; ++x)
      _this->pInventoryIndices[y * 14 + x] = uItemsPoolSlotID;

 _this->pInventoryIndices[uInventorySlotY * 14 + uInventorySlotX] |= 0x80000000; // draw flag. the whole inventory thing is a hack
 _this->pInventorySlots[uItemsPoolSlotID].uItemID = uItemID;
  //}
 return uItemsPoolSlotID;
}
