#pragma once

#include <stdio.h>
#include <windows.h>

#include "AIL.h"
#include "defs.h"
#include "mm7_unparsed_data.h"

#pragma pack(push, 1)



#define SKILL_STAFF         0
#define SKILL_SWORD		    1
#define SKILL_DAGGER		2
#define SKILL_AXE		    3
#define SKILL_SPEAR		    4
#define SKILL_BOW		    5
#define SKILL_MACE		    6
#define SKILL_BLASTER		7
#define SKILL_SHIELD		8
#define SKILL_LEATHER		9
#define SKILL_CHAIN		    10
#define SKILL_PLATE		    11
#define SKILL_FIREMAGIC		12
#define SKILL_AIRMAGIC		13
#define SKILL_WATERMAGIC	14
#define SKILL_EARTHMAGIC	15
#define SKILL_SPIRITMAGIC	16
#define SKILL_MINDMAGIC		17
#define SKILL_BODYMAGIC		18
#define SKILL_LIGHTMAGIC	19
#define SKILL_DARKMAGIC		20
#define SKILL_IDITEM		21
#define SKILL_MERCHANT		22
#define SKILL_REPAIR		23
#define SKILL_BODYBUILDING	24
#define SKILL_MEDITATION    25
#define SKILL_PERCEPTION	26
#define SKILL_DIPLOMACY		27
#define SKILL_THIEVERY		28 // NOT USED
#define SKILL_DISARMTRAP	29
#define SKILL_DODGING		30
#define SKILL_UNARMED		31
#define SKILL_IDMONSTER		32
#define SKILL_ARMSMASTER	33
#define SKILL_STEALING		34
#define SKILL_ALCHEMY		35
#define SKILL_LEARNING		36


#define CLASS_KNIGHT   0
#define CLASS_THIEF    4
#define CLASS_CLERIC   24
#define CLASS_SORCERER 32

#define RACE_HUMAN  0
#define RACE_ELF    1
#define RACE_GOBLIN 2
#define RACE_DWARF  3
#define RACE_UNDEAD 4

#define SEX_MALE    0
#define SEX_FEMALE  1

extern unsigned int uTextureID_PCFaces[];


struct InventorySlot
{
 unsigned int  uItemID; // dword @ 000000
 int           dword_000004[3];
 int           dword_000014;
 short         word_00001C;
 short         word_00001E;
 int           dword_000020[3];
};
//sizeof == 0x24

struct Spellbook
{
 unsigned char bIsSpellbookAvailable;
 unsigned char bAvailableSpells[10];
};

struct Player
{
 union
 {
  struct
  {
   __int64          pConditions[20];      // qword[20] @ 000000   [14] eradicated  [16] dead
   unsigned __int64 uExperience;          // qword     @ 0000A0
   unsigned char    sName[16];            // byte[16]  @ 0000A8
   unsigned char    uSex;                 // byte      @ 0000B8    0 male 1 female
   unsigned char    uClass;               // byte      @ 0000B9
   unsigned char    uFace;                // byte      @ 0000BA
   unsigned char    unknown;              // byte      @ 0000BB
   unsigned short   uStrength;            // word      @ 0000BC
   unsigned short   uStrengthBonus;       // word      @ 0000BE
   unsigned short   uIntelligence;        // word      @ 0000C0
   unsigned short   uIntelligenceBonus;   // word      @ 0000C2
   unsigned short   uWillpower;           // word      @ 0000C4
   unsigned short   uWillpowerBonus;      // word      @ 0000C6
   unsigned short   uEndurance;           // word      @ 0000C8
   unsigned short   uEnduranceBonus;      // word      @ 0000CA
   unsigned short   uSpeed;               // word      @ 0000CC
   unsigned short   uSpeedBonus;          // word      @ 0000CE
   unsigned short   uAccuracy;            // word      @ 0000D0
   unsigned short   uAccuracyBonus;       // word      @ 0000D2
   unsigned short   uLuck;                // word      @ 0000D4
   unsigned short   uLuckBonus;           // word      @ 0000D6
   short            sArmourClassModifier; // word      @ 0000D8
   unsigned short   uLevelBase;           // word      @ 0000DA
   unsigned short   uLevelModifier;       // word      @ 0000DC
   short            sAgeModifier;         // word      @ 0000DE
   int   dword_0000E0;
   int   dword_0000E4;
   int   dword_0000E8;
   int   dword_0000EC;
   int   dword_0000F0;
   int   dword_0000F4;
   int   dword_0000F8;
   int   dword_0000FC;
   int   dword_000100;
   int   dword_000104;

   short pActiveSkills[37];  // word[37] @ 000108
   char array_000152[64];    // awards?

   struct Spellbook cFireSpellbook;   // struct @ 000192
   struct Spellbook cAirSpellbook;    // struct @ 00019D
   struct Spellbook cWaterSpellbook;  // struct @ 0001A8
   struct Spellbook cEarthSpellbook;  // struct @ 0001B3
   struct Spellbook cSpiritSpellbook; // struct @ 0001BE
   struct Spellbook cMindSpellbook;   // struct @ 0001C9
   struct Spellbook cBodySpellbook;   // struct @ 0001D4
   struct Spellbook cLightSpellbook;  // struct @ 0001DF
   struct Spellbook cDarkSpellbook;   // struct @ 0001EA
   
   char           array_0001F5[31];

   struct InventorySlot cInventorySlots[126]; // struct[14*9] @ 000214 
   char           array_0013CC[432];
   int            sInventoryIndexes[126]; // dword[14*9] @ 00157C
   short          sFireResistanceBase;    // word @ 001774
   short          sAirResistanceBase;     // word @ 001776
   short          sWaterResistanceBase;   // word @ 001778
   short          sEarthResistanceBase;   // word @ 00177A
   short          word_00177C;
   short          word_00177E;
   short          sSpiritResistanceBase;  // word @ 001780
   short          sMindResistanceBase;    // word @ 001782
   short          sBodyResistanceBase;    // word @ 001784
   short          word_001786;
   short          word_001788;
   short          sFireResistanceBonus;   // word @ 00178A
   short          sAirResistanceBonus;    // word @ 00178C
   short          sWaterResistanceBonus;  // word @ 00178E
   short          sEarthResistanceBonus;  // word @ 001790
   short          word_001792;
   short          word_001794;
   short          sSpiritResistanceBonus; // word @ 001796
   short          sMindResistanceBonus;   // word @ 001798
   short          sBodyResistanceBonus;   // word @ 00179A
   short          word_00179C;
   short          word_00179E;
   char           array_0017A0[24][16];  // related to spells
   int            dword_001920; //related to voice in SoundList
   int            dword_001924;
   int            dword_001928;
   int            dword_00192C;
   int            dword_001930;
   unsigned short uTimeToRecovery;   // word @ 001934
   char           array_001936[2];
   unsigned int   uSkillPoints;      // dword @ 001938
   int            sHealth;           // dword @ 00193C
   int            sMana;             // dword @ 001940
   unsigned int   uBirthYear;        // dword @ 001944
   int            sEquppedItemIndexes[16]; // dword[16] @ 001948
   int            array_001988[65]; // dword[] @ 001988

   char          byte_001A4E;
   unsigned char uQuickSpell;     // byte  @ 001A4F
   char          array_001A50[72];

   char byte_001A98;
   char array_001A99[3];

   short word_001A9C; //id in PlayerFrameTable, face set
   short word_001A9E; //subframe in FrameTable, current face emotion?   doesnt generate random name if this is not zero
   short word_001AA0;
   short word_001AA2; //PlayerFrame::word_000002 - 1
   int dword_001AA4;
   int dword_001AA8;

   int dword_001B38;
  };
  struct
  {
   unsigned char _[0x1B3C];
  };
 };
};
//sizeof == 1B3C

__int16 __thiscall Player_SetInitialStats(struct Player *_this);
void Player_RandomizeName(struct Player *_this);

//int __thiscall sub_49024A(int this, char a2);
void Player_Reset(struct Player *_this, unsigned int uClass);

int __thiscall Player_GetActualStrength(struct Player *_this);
int __thiscall Player_GetActualIntelligence(struct Player *_this);
int __thiscall Player_GetActualWillpower(struct Player *_this);
int __thiscall Player_GetActualEndurance(struct Player *_this);
int __thiscall Player_GetActualAccuracy(struct Player *_this);
int __thiscall Player_GetActualSpeed(struct Player *_this);
int __thiscall Player_GetActualLuck(struct Player *_this);
int __thiscall Player_GetBaseResistance(struct Player *_this, signed int a2);
int __thiscall Player_GetActualResistance(struct Player *_this, signed int a2);

int Player_GetMaxHealth(struct Player *_this);
int Player_GetMaxMana(struct Player *_this);

int __thiscall Player_MaybeGetCastSpellBonus(struct Player *_this, signed int a2);
signed int __thiscall Player_GetVoiceSex(struct Player *_this);

int Player_GetRace(struct Player *_this);
int Player_GetSex(struct Player *_this);

signed int Player_sub_48E8F5(struct Player *_this, signed int a2);
signed int Player_sub_48EA46(struct Player *_this, int a2);
signed int Player_sub_492D65(struct Player *_this, int a2, int a3);
int CanPlaceItemInInventory(struct Player *_this, signed int a2, int a3);

signed int __thiscall GetSkillIdxByOrder(struct Player *_this, int Order);
int __thiscall Player_GetConditionIdx(void *this);
int __thiscall WearItem(void *this, int a2);
int __thiscall CreateItemInInventory(struct Player *_this, signed int a2, int itemid);
int __thiscall sub_49107D(void *this);
int __thiscall sub_48FC00(void *this, signed int a2);

#pragma pack(pop)
