#pragma once

#include "defs.h"
#include "Player.h"
#include "NPC.h"
#include "Items.h"
#include "Spells.h"


#pragma pack(push, 1)

#define KEY_FORWARD         0   // default: arrow up
#define KEY_BACKWARDS       1   // default: arrow down
#define KEY_TURN_LEFT       2   // default: arrow left
#define KEY_TURN_RIGHT      3   // default: arrow right
#define KEY_YELL            4   // default: y
#define KEY_JUMP            5   // default: x
#define KEY_TOGGLE_REALTIME 6   // default: enter
#define KEY_ATTACK          8   // default: a
#define KEY_INTERACT        9   // default: space

#define PARTY_ACTION_TURN_LEFT      1
#define PARTY_ACTION_TURN_RIGHT     2
//3 turning left with Ctrl pressed
//4 turning right with Ctrl pressed
#define PARTY_ACTION_WALK_FORWARD   5
#define PARTY_ACTION_WALK_BACKWARDS 6
#define PARTY_ACTION_JUMP           12
//16 probably FLY FORWARD
//17 probably FLY BACKWARDS
//18 turning left under some sircumstances
//19 turning right under some sircumstances




struct Party
{
 int           dword_000000;
 unsigned int  uPartyHeight;        // dword @ 000004
 unsigned int  uDefaultPartyHeight; // dword @ 000008
 unsigned int  uEyelevel;           // dword @ 00000C
 unsigned int  uDefaultEyelevel;    // dword @ 000010
 int           dword_000014;
 int           dword_000018;
 unsigned int  uWalkSpeed;          // dword @ 00001C
 int           dword_000020;
 int           dword_000024;
 int           dword_000028;
 __int64       qword_00002C;  // world time
 __int64       qword_000034;
 union
	 {
      int 		   array2_00003C[413];
	
struct abc	 {
 int           array_00003C[20];
 int           array_00008C[170];
 int           array_000334[82];
 int           array_00047C[43];//44   align to original
 int           array_00052C[38];
 char          byte_0005C4[2];
 char          byte_0005C6[238];
	 } Abc;
	 };
 runtime_warning(addition)
 struct Camera *pCamera;
 runtime_warning(deprication)
	 
 int           sPartyPosX;       // dword @ 0006B4     world coordinates are  x: -32768..  32767
 int           sPartyPosY;       // dword @ 0006B8                            y:  32767.. -32768
 int           sPartyPosZ;       // dword @ 0006BC
 int           sRotationY;       // dword @ 0006C0     rotation about Y, angle is 2ï*(sRotationY/2048) or ï*(sRotation/1024)    radians (0.. 2ï) -> (0.. 2048);  (0, ï/2, ï, 3ï/2, 2ï) -> (0, 512, 1024, 1536, 2048)
 int           sRotationX;       // dword @ 0006C4     about X, bend
 int           sOldPosX;         // dword @ 0006C8
 int           sOldPosY;         // dword @ 0006CC
 int           sOldPosZ;         // dword @ 0006D0
 int           sOldRotationY;    // dword @ 0006D4
 int           sOldRotationX;    // dword @ 0006D8
 int           sOldEyelevel;     // dword @ 0006DC

 int           dword_0006E0;
 int           dword_0006E4;
 int           dword_0006E8;
 int           dword_0006EC;
 int           dword_0006F0; // copy of PartyPosZ
 int           dword_0006F4; // / 512 == some bmodel id
 int           dword_0006F8;
 int           dword_0006FC;
 int           dword_000700;
 unsigned int  bFlying;      // dword @ 000704   or maybe 'in air', 'falling'; unclear

 unsigned char byte_000708;
 unsigned char byte_000709;
 unsigned char byte_00070A;
 unsigned char byte_00070B;

 unsigned int  uCurrentYear;      // dword @ 00070C
 unsigned int  uCurrentMonth;     // dword @ 000710
 int           uCurrentMonthWeek; // dword @ 000014
 unsigned int  uDaysPlayed;       // dword @ 000718
 unsigned int  uCurrentHour;      // dword @ 00071C
 unsigned int  uCurrentMinute;    // dword @ 000720
 int           dword_000724;
 unsigned int  uNumFood;       // dword @ 000728
 int           dword_00072C;
 int           dword_000730;
 unsigned int  uNumGold;       // dword @ 000734
 unsigned int  uNumGoldInBank; // dword @ 000738
 int           dword_00073C; // num deaths? looks very like it

 int           dword_000740;
 int           dword_000744;
 int           dword_000748;
 int           dword_00074C;
 short         array_000750[5];
 short         array_00075A[5];

 char          unk_000764[240]; // quests?

 unsigned char byte_000854[32];

 int                dword_000874;
 int                dword_000878;
 unsigned int       bTurnBasedModeOn;    // dword @ 00087C
 int                dword_000880;
 int                dword_000884; //flags   &2 probably flying
 unsigned int       uAlignment;       // dword      @ 000888   enum (0, 1, 2) = (good, neutral, evil)
 struct SpellBuff   pPartyBuffs[20];  // struct[20] @ 00088C
 struct Player      pPlayers[4];      // struct[4]  @ 0009CC
 struct NPCData     pHiredNPCs[2];    // struct[2]  @ 0076BC
 struct ItemGen     pickedItem;       // struct     @ 007754   item picked in inventory
 int                dword_007778;     // party flags;     0x0002 - party position/direction/eyelevel changed
                                      //                  0x0004 - You're Drowning!  message displayed - in water
                                      //                  0x0200 - You are Burning!  message displayed - in lava

 char pad[100000];

 float flt_01622C;
 float flt_016230;
 float flt_016234;

 int dword_01613C; // connected to sLastGUIWindowIdx

 int array_016144[array_size_unknown]; // 016144


 char pad2[100000];
};
//sizeof ~ 16238  90680		   

//int __thiscall Party_sub_49135E_GetAllPartyExpDiv1000(void *_this)
void Party_ctor(struct Party *_this);
//unsigned __int16 __thiscall Party_sub_491BF9_ResetPosMiscAndSpellBuffs(int _this);
void Party_sub_491BF9_ResetPosMiscAndSpellBuffs(struct Party *_this);
//int __thiscall sub_49370F(void *_this);
int Party_sub_49370F(struct Party *_this);
//bool __thiscall sub_497FC5(void *_this);
bool Party_sub_497FC5(struct Party *_this);
//signed int __thiscall sub_48C6F6(void *_this, int a2);
int Party_AddItem(struct Party *_this, struct ItemGen *a2);
//int __thiscall sub_49137D(int _this, char a2);
int Party_CreateDefaultParty(struct Party *_this, char a2);

int Party_Reset(struct Party *_this);


//void __thiscall sub_4936E1(void *_this, const struct ItemGen *a2);
void Party_sub_4936E1_ReceiveItemInHandsWhileInGame(Party *_this, const struct ItemGen *pItem);

#pragma pack(pop)
