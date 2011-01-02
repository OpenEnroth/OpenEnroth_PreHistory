#pragma once
#include <windows.h>
#include <stdio.h>

#include "defs.h"
#include "Items.h"
#include "Spells.h"
#include "Math\Math.inl"


bool InitializeActors(struct MapInfo *pMapInfo);
void __cdecl UpdateActors();



struct DirectionInfo
{
  //normalized vector of direction from first object to second object
 Vec3<int> vDirection; // dword[3] @ 000000  fixed-point format 16.16
  //int   sVecX;  // @ 000000  
  //int   sVecY;  // @ 000004  fixed-point format 16.16
  //int   sVecZ;  // @ 000008  fixed-point format 16.16

  unsigned int uDistance;   // @ 00000C distance between the objects 
  unsigned int uDistanceXY; // @ 000010 projection of distance to the XY plane
  unsigned int uYawAngle;   // @ 000014 yaw angle calculated from direction vector
  unsigned int uPitchAngle; // @ 000018 pitch angle calculated from direction vector
};
//sizeof = 1C



namespace AI
{
 namespace State
 {
  enum Type
  {
   Standing = 0,
   Tethered = 1,
   AttackingMelee = 2,
   AttackingRanged1 = 3,
   Dying = 4,
   Dead = 5,
   Pursuing = 6,
   Fleeing = 7,
   Stunned = 8,
   Fidgeting = 9,
   Interacting = 10,
   Removed = 11,
   AttackingRanged2 = 12,
   AttackingRanged3 = 13,
   Stoned = 14,
   Paralyzed = 15,
   Resurrected = 16,
   Summoned = 17,
   AttackingRanged4 = 18,
   Disabled = 19
  };
 };

 namespace Animation
 {
  enum Type
  {
   Standing = 0,
   Walking = 1,
   AttackingMelee = 2,
   AttackingRanged = 3,
   GotHit = 4,
   Dying = 5,
   Dead = 6,
   Bored = 7
  };
 };
};



struct ActorJob // not sure what it is actually
{
 short          sPosX;       // word @ 000000
 short          sPosY;       // word @ 000002
 short          sPosZ;       // word @ 000004
 unsigned short uAttributes; // word @ 000006
 	    // these might be in reverse order
 unsigned char  uAction;     // byte @ 000008
 unsigned char  uHour;       // byte @ 000009
 unsigned char  uDay;        // byte @ 00000A
 unsigned char  uMonth;      // byte @ 00000B
};
//sizeof == 0C




#pragma pack(push, 1)
struct Actor
{
 unsigned char  pActorName[32]; // byte[32] @ 000000
 short          uNPCID;         // word @ 000020  if < 500: offset in pNPCStats->pNPCData2[word_000020]               old npcs
                                //                else:     offset in pNPCStats->array_0013EF4[word_000020 - 5000]    new npcs
 short          word_000022;
 unsigned int   uAttributes;    // dword @ 000024
 short          sCurrentHP;   // word @ 000028
 char           unk_00002A[2];
 int            dword_00002C; 
 int            dword_000030; 
 unsigned char  uLevel;              // byte @ 000034
 unsigned char  uTreasureDropChance; // byte @ 000035
 unsigned char  uTreasureDiceRolls;  // byte @ 000036
 unsigned char  uTreasureDiceSides;  // byte @ 000037
 unsigned char  uTreasureLevel;      // byte @ 000038
 unsigned char  uTreasureItemType;   // byte @ 000039
                                        //TREASURE_ITEM_TYPE_WEAPON = 20;
                                        //TREASURE_ITEM_TYPE_ARMOR = 21;
                                        //TREASURE_ITEM_TYPE_MISC = 22;
                                        //TREASURE_ITEM_TYPE_SWORD = 23;
                                        //TREASURE_ITEM_TYPE_DAGGER = 24;
                                        //TREASURE_ITEM_TYPE_AXE = 25;
                                        //TREASURE_ITEM_TYPE_SPEAR = 26;
                                        //TREASURE_ITEM_TYPE_BOW = 27;
                                        //TREASURE_ITEM_TYPE_MACE = 28;
                                        //TREASURE_ITEM_TYPE_CLUB = 29;
                                        //TREASURE_ITEM_TYPE_STAFF = 30;
                                        //TREASURE_ITEM_TYPE_LEATHER = 31;
                                        //TREASURE_ITEM_TYPE_CHAIN = 32;
                                        //TREASURE_ITEM_TYPE_PLATE = 33;
                                        //TREASURE_ITEM_TYPE_SHIELD = 34;
                                        //TREASURE_ITEM_TYPE_HELM = 35;
                                        //TREASURE_ITEM_TYPE_BELT = 36;
                                        //TREASURE_ITEM_TYPE_CLOAK = 37;
                                        //TREASURE_ITEM_TYPE_GAUNTLETS = 38;
                                        //TREASURE_ITEM_TYPE_BOOTS = 39;
                                        //TREASURE_ITEM_TYPE_RING = 40;
                                        //TREASURE_ITEM_TYPE_AMULET = 41;
                                        //TREASURE_ITEM_TYPE_WAND = 42;
                                        //TREASURE_ITEM_TYPE_SCROLL = 43;
                                        //TREASURE_ITEM_TYPE_POTION = 44;
                                        ///TREASURE_ITEM_TYPE_REAGENT = 45;
                                        //TREASURE_ITEM_TYPE_GEM = 46;
                                        //TREASURE_ITEM_TYPE_ORE = 47;   // MM8-only
                                        //TREASURE_ITEM_TYPE_GOLD = 50;
 unsigned char  bFlying;             // byte @ 00003A
 unsigned char  uMovementType;       // byte @ 00003B
                                        //MOVE_TYPE_SHORT = 0;
                                        //MOVE_TYPE_MEDIUM = 1;
                                        //MOVE_TYPE_LONG = 2;
                                        //MOVE_TYPE_GUARD = 3;
                                        //MOVE_TYPE_FREE = 4;
                                        //MOVE_TYPE_STATIONARY = 5;
 unsigned char  uAIType;             // byte @ 00003C
                                        //AI_TYPE_SUICIDAL = 0;
                                        //AI_TYPE_WIMP = 1;
                                        //AI_TYPE_NORMAL = 2;
                                        //AI_TYPE_AGRESSIVE = 3;
 unsigned char  uHostilityType;      // byte @ 00003D
                                        //HOSTILE_TYPE_FRIENDLY = 0;
                                        //HOSTILE_TYPE_CLOSE = 1;
                                        //HOSTILE_TYPE_SHORT = 2;
                                        //HOSTILE_TYPE_MEDIUM = 3;
                                        //HOSTILE_TYPE_LONG = 4;
 char           unk_00003E;
 unsigned char  uSpecialAbility;     // byte @ 00003F
 unsigned char  uSpecialAbilityType; // byte @ 000040
                                        //SPECIAL_ABILITY_BONUS_CURSE = 1;
                                        //SPECIAL_ABILITY_BONUS_WEAK = 2;
                                        //SPECIAL_ABILITY_BONUS_ASLEEP = 3;
                                        //SPECIAL_ABILITY_BONUS_DRUNK = 4;
                                        //SPECIAL_ABILITY_BONUS_INSANE = 5;
                                        //SPECIAL_ABILITY_BONUS_POISON1 = 6;
                                        //SPECIAL_ABILITY_BONUS_POISON2 = 7;
                                        //SPECIAL_ABILITY_BONUS_POISON3 = 8;
                                        //SPECIAL_ABILITY_BONUS_DISEASE1 = 9;
                                        //SPECIAL_ABILITY_BONUS_DISEASE2 = 10;
                                        //SPECIAL_ABILITY_BONUS_DISEASE3 = 11;
                                        //SPECIAL_ABILITY_BONUS_PARALYZE = 12;
                                        //SPECIAL_ABILITY_BONUS_UNCONSCIOUS = 13;
                                        //SPECIAL_ABILITY_BONUS_DEAD = 14;
                                        //SPECIAL_ABILITY_BONUS_STONE = 15;
                                        //SPECIAL_ABILITY_BONUS_ERADICATE = 16;
                                        //SPECIAL_ABILITY_BONUS_BREAK_ITEM = 17;
                                        //SPECIAL_ABILITY_BONUS_BREAK_ARMOR = 18;
                                        //SPECIAL_ABILITY_BONUS_BREAK_WEAPON = 19;
                                        //SPECIAL_ABILITY_BONUS_STEAL = 20;
                                        //SPECIAL_ABILITY_BONUS_AGE = 21;
                                        //SPECIAL_ABILITY_BONUS_DRAIN_SPELL_POINTS = 22;
                                        //SPECIAL_ABILITY_BONUS_AFRAID = 23;
 unsigned char  uAttack1Type;        // byte @ 000041
                                        //ATTACK_TYPE_PHYSICAL = 0x01;
                                        //ATTACK_TYPE_FIRE = 0x02;
                                        //ATTACK_TYPE_ELECTRICITY = 0x04;
                                        //ATTACK_TYPE_COLD = 0x08;
                                        //ATTACK_TYPE_POISON = 0x10;
                                        //ATTACK_TYPE_ENERGY = 0x20;
                                        //ATTACK_TYPE_MAGICAL = 0x40;
 unsigned char uAttack1DamageDiceRolls; // byte @ 000042
 unsigned char uAttack1DamageDiceSides; // byte @ 000043
 unsigned char uAttack1DamageBonus;     // byte @ 000044
 unsigned char uAttack1MissleType;      // byte @ 000045
                                        //ATTACK_MISSILE_TYPE_NONE = 0;
                                        //ATTACK_MISSILE_TYPE_ARROW = 1;
                                        //ATTACK_MISSILE_TYPE_ARROW_FIRE = 2;
                                        //ATTACK_MISSILE_TYPE_FIRE = 3;
                                        //ATTACK_MISSILE_TYPE_AIR = 4;
                                        //ATTACK_MISSILE_TYPE_WATER = 5;
                                        //ATTACK_MISSILE_TYPE_EARTH = 6;
                                        //ATTACK_MISSILE_TYPE_SPIRIT = 7;
                                        //ATTACK_MISSILE_TYPE_MIND = 8;
                                        //ATTACK_MISSILE_TYPE_BODY = 9;
                                        //ATTACK_MISSILE_TYPE_LIGHT = 10;
                                        //ATTACK_MISSILE_TYPE_DARK = 11;
                                        //ATTACK_MISSILE_TYPE_MAGIC = 12;
                                        //ATTACK_MISSILE_TYPE_ENERGY = 13;
 unsigned char uAttack2Chance;          // byte @ 000046
 unsigned char uAttack2Type;            // byte @ 000047
 unsigned char uAttack2DamageDiceRolls; // byte @ 000048
 unsigned char uAttack2DamageDiceSides; // byte @ 000049
 unsigned char uAttack2DamageBonus;     // byte @ 00004A
 unsigned char uAttack2MissleType;      // byte @ 00004B
 unsigned char uSpell1Chance;           // byte @ 00004C
 unsigned char uSpell1ID;               // byte @ 00004D
 unsigned char uSpell2Chance;           // byte @ 00004E
 unsigned char uSpell2ID;               // byte @ 00004F
 char          sResistanceFire;         // byte @ 000050
 char          sResistanceAir;          // byte @ 000051
 char          sResistanceWater;        // byte @ 000052
 char          sResistanceEarth;        // byte @ 000053
 char          sResistanceMind;         // byte @ 000054
 char          sResistanceSpirit;       // byte @ 000055
 char          sResistanceBody;         // byte @ 000056
 char          sResistanceLight;        // byte @ 000057
 char          sResistanceDark;         // byte @ 000058
 char          sResistancePhysical;     // byte @ 000059
 unsigned char uSpecialAttackType;      // byte @ 00005A
                                        //SPECIAL_ATTACK_TYPE_NONE = 0;
                                        //SPECIAL_ATTACK_TYPE_SHOT = 1;
                                        //SPECIAL_ATTACK_TYPE_SUMMON = 2;
                                        //SPECIAL_ATTACK_TYPE_EXPLODE = 3;
                                        //more
 unsigned char  uSpecialAttackDamageDiceRolls;   // byte @ 00005B
 unsigned char  uSpecialAttackDamageDiceSides;   // byte @ 00005C
 unsigned char  uSpecialAttackDamageDiceBonus;   // byte @ 00005D
 unsigned char  uNumCharactersAttackedPerAttack; // byte @ 00005E
 char           unk_00005F;
 unsigned short uMonsterID;             // word @ 000060   (uMonsterID - 1) == monster id in MonsterDescriptionList and MonsterStats  (originally (- 0) in MonsterStats since 0th entry was dummy)
 unsigned short uMonsterAttributes;     // word @ 000062
 unsigned short uSpellSkillAndMastery1; // word @ 000064
 unsigned short uSpellSkillAndMastery2; // word @ 000066
 unsigned short word_000068_some_special_attack;
 short          unk_00006A;
 int            sTotalHP;          // dword @ 00006C
 int            sAC;               // dword @ 000070
 unsigned int   uExperience;       // dword @ 000074
 unsigned int   uBaseSpeed;        // dword @ 000078
 unsigned int   uRecoveryTime;     // dword @ 00007C
 unsigned int   uAttackPreference; // dword @ 000080
                                       //ATTACK_PREFERENCE_TYPE_NONE_MM7 = 0x0000;
                                       //ATTACK_PREFERENCE_TYPE_KNIGHT_MM7 = 0x0001;
                                       //ATTACK_PREFERENCE_TYPE_PALADIN_MM7 = 0x0002;
                                       //ATTACK_PREFERENCE_TYPE_ARCHER_MM7 = 0x0004;
                                       //ATTACK_PREFERENCE_TYPE_DRUID_MM7 = 0x0008;
                                       //ATTACK_PREFERENCE_TYPE_CLERIC_MM7 = 0x0010;
                                       //ATTACK_PREFERENCE_TYPE_SORCERER_MM7 = 0x0020;
                                       //ATTACK_PREFERENCE_TYPE_RANGER_MM7 = 0x0040;
                                       //ATTACK_PREFERENCE_TYPE_THIEF_MM7 = 0x0080;
                                       //ATTACK_PREFERENCE_TYPE_MONK_MM7 = 0x0100;
                                       //ATTACK_PREFERENCE_TYPE_MALE_MM7 = 0x0200;
                                       //ATTACK_PREFERENCE_TYPE_FEMALE_MM7 = 0x0400;
                                       //ATTACK_PREFERENCE_TYPE_HUMAN_MM7 = 0x0800;
                                       //ATTACK_PREFERENCE_TYPE_ELF_MM7 = 0x1000;
                                       //ATTACK_PREFERENCE_TYPE_DWARF_MM7 = 0x2000;
                                       //ATTACK_PREFERENCE_TYPE_GOBLIN_MM7 = 0x4000;
 short          word_000084_range_attack; // 0 = melee, bool?
 short          word_000086_some_monster_id;
 unsigned short uActorRadius;            // word @ 000088
 unsigned short uActorHeight;            // word @ 00008A
 unsigned short uMovementSpeed;          // word @ 00008C   = monster speed from MosnterInfo
 Vec3<short>    vPosition;               // word[3] @ 00008E
 //short          sActorPosX;              // word @ 00008E
 //short          sActorPosY;              // word @ 000090
 //short          sActorPosZ;              // word @ 000092
 Vec3<short>    vVelocity;               // word[3] @ 000092
 //short          sVelocityX;              // word @ 000094
 //short          sVelocityY;              // word @ 000096
 //short          sVelocityZ;              // word @ 000098
 unsigned short uYawAngle;               // word @ 00009A
 unsigned short uPitchAngle;             // word @ 00009C
 short          sRoom;                   // word @ 00009E
 unsigned short uCurrentActionLength;    // word @ 0000A0
 Vec3<short>    vInitialPosition;        // word[3] @ 0000A2
 //short          sInitialPosX;            // word @ 0000A2
 //short          sInitialPosY;            // word @ 0000A4
 //short          sInitialPosZ;            // word @ 0000A6
 Vec3<short>    vGuardingPosition;       // word[3] @ 0000A8
 //short          sGuardingPosX;           // word @ 0000A8
 //short          sGuardingPosY;           // word @ 0000AA
 //short          sGuardingPosZ;           // word @ 0000AC
 unsigned short uTetherDistance;         // word @ 0000AE  in pixels
 unsigned short uAIState;                // word @ 0000B0  AI::State   sadly cannot declare as enum since sizeof(enum == 4)
 unsigned short uCurrentActionAnimation; // word @ 0000B2  AI::Animation
                                            // 0: standing
                                            // 1: walking
                                            // 2: melee attack
                                            // 3: ranged attack
                                            // 4: got hit
                                            // 5: dying
                                            // 6: dead
                                            // 7: fidgeting
 unsigned short uCarriedItemID;       // word @ 0000B4   special item.  -1/0 == use standard loot
 char           unk_0000B6[2];
 unsigned int   uCurrentActionTime;   // dword @ 0000B8
 unsigned short pSpriteIDs[8]; // word[8] @ 0000BC   Sprite S-Frame IDs
                               // sprite names (for animated creatures):  xxxTnD, xxx - frameset name, T - type ('S' - standing, 'W' - walking, etc), n - frame number ('a' for 0, 'b' for 1, etc), D - creature direction (0, 1, 2, 3, 4 for 'front', 'front-right', 'right', 'back-right', 'back')
                               // e.g.   m342wa0 - frameset "m342" walking animation frame 0 towards player
                               //        m342wa4 - frameset "m342" walking animation frame 0 away from player
                               //        m342wb4 - frameset "m342" walking animation frame 1 away from player
                               // uSpriteIDs[0]: S - standing sequence
                               // uSpriteIDs[1]: W - walking sequence
                               // uSpriteIDs[2]: ? - melee attack
                               // uSpriteIDs[3]: ? - ranged attack
                               // uSpriteIDs[4]: N - got hit
                               // uSpriteIDs[5]: ? - dying
                               // uSpriteIDs[6]: X - dead
                               // uSpriteIDs[7]: F - bored, no direction
 unsigned short       pSoundSampleIDs[4]; // word[4] @ 0000CC
 struct SpellBuff     pActorBuffs[22]; // struct[22] @ 0000D4
 struct ItemGen       array_000234[4];
 unsigned int         uGroup;                // dword     @ 0002C4    index in NPCStats::word_017F5A
 unsigned int         uAlly;                 // dword     @ 0002C8   ?
 ActorJob             pScheduledJobs[8];     // struct[8] @ 0002CC
 unsigned int         uSummonerID;           // dword     @ 00032C
 unsigned int         uLastCharacterIDToHit; // dword     @ 000330
 unsigned int         dword_000334_unique_name;
 char                 unk_000338[12];
};
//sizeof == 344
#pragma pack(pop)

bool Actor_sub_40894B(struct Actor *_this);
//int __thiscall Actor_UpdateAnimation(int _this);
void Actor_UpdateAnimation(struct Actor *_this);
//signed int __fastcall sub_40104C(int a1, int a2);
signed int Actor_GetActorsRelation(struct Actor *pActor1, struct Actor *pActor2);
//int __fastcall sub_403EB6(unsigned int uActorID, signed int a2, int a3, char *a4);
void Actor_sub_403EB6(unsigned int uActorID, signed int a2, unsigned int uActorRecoveryTime, struct DirectionInfo *pDirectionInfo);
//int __fastcall sub_403C6C(int a1, int a2, char *a3);
void Actor_sub_403C6C(unsigned int uActorID, int a2, struct DirectionInfo *pDirectionInfo);
//int __fastcall sub_402F87(int a1, signed int a2, signed int a3);
void Actor_sub_402F87(unsigned int uActorID, signed int a2, struct DirectionInfo *pDirectionInfo);
//int __fastcall sub_403F58(int a1, int a2, int a3, signed int a4);
void Actor_sub_403F58(unsigned int uActorID, int a2, int a3, struct DirectionInfo *pDirectionInfo);
//int __fastcall sub_404030(int a1, signed int a2, int a3, signed int a4);
void Actor_ProbablyForceToFaceParty(unsigned int uActorID, signed int a2, int a3, struct DirectionInfo *pDirectionInfo);
//int __fastcall sub_402968(int a1, int a2, int a3, char *a4);
void Actor_sub_402968(unsigned int uActorID, int a2, int a3, struct DirectionInfo *pDirectionInfo);
//int __fastcall sub_402686(int a1, signed int a2, signed int a3, signed int a4);
void Actor_sub_402686(unsigned int uActorID, signed int a2, signed int a3, struct DirectionInfo *pDirectionInfo);
//int __fastcall sub_40281C(int a1, signed int a2, signed int a3, signed int a4, int a5);
void Actor_sub_40281C(unsigned int uActorID, signed int a2, signed int a3, struct DirectionInfo *pDirectionInfo, int a5);
//int __fastcall sub_402AD7(int a1, signed int a2, signed int a3, int a4, signed int a5);
void Actor_sub_402AD7(unsigned int uActorID, signed int a2, signed int a3, int a4, struct DirectionInfo *pDirectionInfo);
//int __fastcall sub_403854(int a1, signed int a2, signed int a3);
void Actor_sub_403854(unsigned int uActorID, signed int a2, struct DirectionInfo *pDirectionInfo);
//int __fastcall sub_40368B(int a1, signed int a2, signed int a3);
void Actor_sub_40368B(unsigned int uActorID, signed int a2, struct DirectionInfo *pDirectionInfo);
//int __fastcall sub_403476(int a1, signed int a2, signed int a3);
void Actor_sub_403476(unsigned int uActorID, signed int a2, struct DirectionInfo *pDirectionInfo);
//int __fastcall sub_403A60(int a1, signed int a2, signed int a3);
void Actor_sub_403A60(unsigned int uActorID, signed int a2, struct DirectionInfo *pDirectionInfo);
//int __fastcall sub_4032B2(int a1, int a2, int a3, int a4);
void Actor_sub_4032B2(unsigned int uActorID, int a2, int a3, int a4);
//__int16 __thiscall sub_45959A(int _this, char a2);
void Actor_LinkSprites(struct Actor *_this, char a2);
//void *__thiscall sub_459671(int _this);
void Actor_Reset(struct Actor *_this);
//int __thiscall sub_41F4C1(void *_this);
void Actor_TotalReset(struct Actor *_this);
//void *__fastcall sub_402CED(signed int a1, int a2);
void Actor_PlaySound(unsigned int uActorID, int soundId);
//int __fastcall sub_402D6E(int a1);
void Actor_Die(unsigned int uActorID);
//char __thiscall sub_438B9B(int _this);
char Actor_sub_438B9B(Actor *_this);

//void *__fastcall sub_4040E9(signed int a1, signed int a2, void *a3, signed int a4);
struct DirectionInfo* GetDirectionInfo(unsigned int uObject1, unsigned int uObject2, DirectionInfo *pDirectionInfo, signed int a4);


signed int __stdcall Actor_sub_42756B(int a1, int a2, signed int a3);
