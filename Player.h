#pragma once

#include <stdio.h>
#include <windows.h>

#include "AIL.h"
#include "defs.h"
#include "Spells.h"
#include "Items.h"

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

extern  class cTexture *pTextureID_PCFaces[];

struct Beacon
{
__int64 uBeaconTime;
int  dword_00008;
int  dword_0000C;
int  dword_00010;
int  dword_00014;
int  dword_00018;
};
//0x1C

struct StatTable
{
  unsigned char InitialStat;
  unsigned char MaxStat;
  unsigned char Ratio1;
  unsigned char Ratio2;
};
extern struct StatTable g_StatTable[4][7]; // byte[] @ MM7.exe::004ED7B0
extern unsigned char AvailSkillPerClass[9][37]; // byte[] @ MM7.exe::004ED820


struct Spellbook
{
 unsigned char bIsSpellbookAvailable;
 unsigned char bAvailableSpells[10];
};

struct Player
{

   __int64          pConditions[20];      // qword[20] @ 000000   [14] eradicated  [16] dead  condition time may be
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

   struct ItemGen   cInventorySlots[126];   // struct[14][9] @ 000214
   struct ItemGen   array_0013CC[12];       // struct[12]    @ 0013CC     probably equipped items
   int              pInventoryIndices[126]; // dword[14][9]  @ 00157C
   short            sFireResistanceBase;    // word @ 001774
   short            sAirResistanceBase;     // word @ 001776
   short            sWaterResistanceBase;   // word @ 001778
   short            sEarthResistanceBase;   // word @ 00177A
   short            word_00177C;
   short            word_00177E;
   short            sSpiritResistanceBase;  // word @ 001780
   short            sMindResistanceBase;    // word @ 001782
   short            sBodyResistanceBase;    // word @ 001784
   short            word_001786;
   short            word_001788;
   short            sFireResistanceBonus;   // word @ 00178A
   short            sAirResistanceBonus;    // word @ 00178C
   short            sWaterResistanceBonus;  // word @ 00178E
   short            sEarthResistanceBonus;  // word @ 001790
   short            word_001792;
   short            word_001794;
   short            sSpiritResistanceBonus; // word @ 001796
   short            sMindResistanceBonus;   // word @ 001798
   short            sBodyResistanceBonus;   // word @ 00179A
   short            word_00179C;
   short            word_00179E;
   struct SpellBuff pPlayerBuffs[24]; // struct[24] @ 0017A0
   int              dword_001920; //related to voice in SoundList
   int              dword_001924;
   int              dword_001928;
   int              dword_00192C;
   int              dword_001930;
   unsigned short   uTimeToRecovery;   // word @ 001934
   char             array_001936[2];
   unsigned int     uSkillPoints;      // dword @ 001938
   int              sHealth;           // dword @ 00193C
   int              sMana;             // dword @ 001940
   unsigned int     uBirthYear;        // dword @ 001944
   int              pEquppedItemIndices[16]; // dword[16] @ 001948
                                             // 1: right hand
                                             // 3: body, leather armour
   int              array_001988[65]; // dword[] @ 001988    looks like pEquppedItemIndices

   char          byte_001A4E;	//spell skill? or school?
   unsigned char uQuickSpell;     // byte  @ 001A4F
   char          array_001A50[10];	 // was 72  changed to solve align problem

   char byte_001A98;
   char array_001A99[3];

   unsigned short uDefaultFaceID; // word @ 001A9C    id in PlayerFrameTable, face set
   short word_001A9E; //subframe in FrameTable, current face emotion?   doesnt generate random name if this is not zero
   short word_001AA0;
   short word_001AA2; //PlayerFrame::word_000002 - 1
   int dword_001AA4;
   int dword_001AA8;

   struct Beacon stBeacons[5]; // struct[5] @ 001AAC   beacons 5 struct 0x1C size 

 //  int array_align[7];	  // 001B1C

   int dword_001B38;

};
//sizeof == 1B3C

__int16 __thiscall Player_SetInitialStats(struct Player *_this);
void Player_RandomizeName(struct Player *_this);

//int __thiscall sub_49024A(int _this, char a2);
void Player_Reset(struct Player *_this, unsigned int uClass);

//void *__thiscall sub_48C6AF(void *_this);
void Player_ctor(Player *_this);

//signed int __thiscall Player_sub_48D709(void *_this, int a2, int a3);
signed int Player_sub_48D709(struct Player *_this, int a2, int a3);
//bool __thiscall Player_sub_48D6AA(void *_this, int a2);
bool Player_sub_48D6AA(struct Player *_this, unsigned int uItemID);

int Player_GetActualStrength(struct Player *_this);
int Player_GetActualIntelligence(struct Player *_this);
int Player_GetActualWillpower(struct Player *_this);
int Player_GetActualEndurance(struct Player *_this);
int Player_GetActualAccuracy(struct Player *_this);
int Player_GetActualSpeed(struct Player *_this);
int Player_GetActualLuck(struct Player *_this);
int Player_GetBaseResistance(struct Player *_this, signed int a2);
int Player_GetActualResistance(struct Player *_this, signed int a2);


//int __thiscall sub_48C90D(void *_this);
int Player_GetActualLevel(struct Player *_this);

//int __thiscall sub_48EAAE(void *_this, signed int a2, int a3);
int Player_MaybeGetWearItemsBonus(struct Player *_this, signed int a2, int a3);

//int __thiscall sub_48C855(int _this);
int Player_GetBaseStrength(struct Player *_this);
//int __thiscall sub_48C86C(int _this);
int Player_GetBaseIntelligence(struct Player *_this);
//int __thiscall sub_48C883(int _this);
int Player_GetBaseWillpower(struct Player *_this);
//int __thiscall sub_48C89A(int _this);
int Player_GetBaseEndurance(struct Player *_this);
//int __thiscall sub_48C8B1(int _this);
int Player_GetBaseAccuracy(struct Player *_this);
//int __thiscall sub_48C8C8(int _this);
int Player_GetBaseSpeed(struct Player *_this);
//int __thiscall sub_48C8DF(int _this);
int Player_GetBaseLuck(struct Player *_this);
//int __thiscall sub_48C8F6(int _this);
int Player_GetBaseLevel(struct Player *_this);

int Player_GetActualAge(struct Player *_this);
int Player_GetBaseAge(struct Player *_this);


int Player_GetMaxHealth(struct Player *_this);
int Player_GetMaxMana(struct Player *_this);

int __thiscall Player_MaybeGetCastSpellBonus(struct Player *_this, signed int a2);
signed int __thiscall Player_GetVoiceSex(struct Player *_this);

bool Player_SetRecoveryTime(struct Player *_this, int sRecoveryTime);

int Player_GetRace(struct Player *_this);
int Player_GetSex(struct Player *_this);

bool Player_sub_48E8F5(struct Player *_this, signed int a2);
signed int Player_sub_48EA46(struct Player *_this, int a2);
signed int Player_sub_492D65(struct Player *_this, int a2, int a3);

bool CanPlaceItemInInventory(struct Player *_this, unsigned int uInventorySlot, unsigned int uItemID);
unsigned int FindPlaceForItemInInventory(struct Player *_this, unsigned int uItemID);
unsigned int FindPlaceForItemInInventory(struct Player *_this, struct ItemGen *pItem);
unsigned int AddItem(struct Player *_this, unsigned int uInventorySlot, unsigned int uItemID);
unsigned int AddItem(struct Player *_this, unsigned int uInventorySlot, struct ItemGen *pItem);
unsigned int CreateItemInInventory(struct Player *_this, unsigned int uInventorySlot, unsigned int uItemID);
unsigned int CreateItemInInventory(struct Player *_this, unsigned int uInventorySlot, struct ItemGen *pItem);

signed int __thiscall GetSkillIdxByOrder(struct Player *_this, int Order);
int Player_GetConditionIdx(struct Player *_this);
int __thiscall WearItem(void *_this, int a2);
int __thiscall sub_49107D(void *_this);
int Player_sub_48FC00(struct Player *_this, signed int a2);

//int __thiscall sub_48E1B5(void *_this, int a2);
int Player_sub_GetAttackRecoveryTime(Player *_this, int a2);
bool Player_sub_48D6D0(struct Player *_this, int a2);
signed int Player_sub_48DC1E(struct Player *_this, signed int a2, int a3);


//signed int __thiscall sub_492C0B(int _this);
bool Player_sub_492C0B_MaybeIfPlayerConscious(struct Player *_this);

int Player_sub_421E75_GetItemAtInventoryIndex(Player *_this, int *a2);

void Player_sub_492A36_RemoveItemFromIndexMatrix(struct Player *_this, unsigned int uInventorySlot);



int __thiscall Player_sub_48D0B9(int _this);
char *__thiscall Player_sub_48D396(int _this);
unsigned int __thiscall Player_sub_48D498(int _this);
signed int __thiscall Player_sub_48D4B3(int _this, int a2, signed int a3);
int __thiscall Player_sub_48DBB9(int _this, int a2);
int __thiscall Player_sub_48E656(int _this);
int __thiscall Player_sub_48E68F(int _this);
char __thiscall Player_sub_48F882(Player *_this, signed int a2);
__int16 __thiscall Player_PlaySound(struct Player *_this, int a2, int a3);
__int16 __thiscall Player_sub_494A25(int _this, int a2, int a3);
bool Player_sub_492C4E(Player *_this, int sItemID);
//signed int __thiscall sub_492700(int this, signed int a2);
bool Player_CheckIfHasSkill(Player *_this, unsigned int uSkillType);
unsigned int Player_FindNextFreeInventorySlotIndex(Player *_this);
void __thiscall Player_sub_4680ED(Player *_this, signed int a2, int a3);
int __thiscall Player_sub_490EEE(Player *_this, int a2, int a3, int a4, int a5);
int __thiscall Player_sub_4910A8(Player *_this);
signed int __thiscall Player_sub_491151(Player *_this, int a2);
int __thiscall Player_sub_4911F3(Player *_this);
signed int __thiscall Player_sub_49125A(Player *_this);
signed int __thiscall Player_sub_4912B0(Player *_this);
char __thiscall Player_sub_491317(Player *_this);
bool __thiscall Player_sub_492C40(Player *_this);
int __thiscall Player_sub_4B807C(Player *_this, float a2);
signed int __thiscall Player_sub_4B8102(Player *_this, signed int a2, float a3);
int __thiscall Player_sub_4B8142(Player *_this, signed int a2, float a3);
signed int __thiscall Player_sub_4B6FF9(Player *_this);
signed int __thiscall Player_sub_4B8179(Player *_this, float a2);
signed int __thiscall Player_sub_4B81C3(Player *_this, signed int a2, float a3);
void __thiscall Player_sub_4BE2DD(Player *_this, int a2, int a3, int a4);
char __thiscall Player_sub_43EEF3(Player *_this);
signed int __thiscall Player_sub_48CDDB(Player *_this, int a2, int a3, signed int a4);

int __thiscall sub_48D62C_GetSomeItemEquipType(struct Player *_this, int a2);
int __thiscall sub_48D651_GetSomeItemSkillType(struct Player *_this, int a2);
bool __thiscall Player_sub_48D676(Player *_this);


int sub_458244_GetSkillMasteryLevel(unsigned int uSkillLevel);

#pragma pack(pop)
