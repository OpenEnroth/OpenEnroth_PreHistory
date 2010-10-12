#pragma once

#include "defs.h"
#include "Player.h"
#include "NPC.h"


#pragma pack(push, 1)

#define PARTYBUFF_FEATHERFALL 5
#define PARTYBUFF_FLY         7
#define PARTYBUFF_WATERWALK  15
#define PARTYBUFF_WIZARDEYE  19

struct PartySpellBuff
{
 union
 {
  __int64 qword_000000;
  struct
  {
   int dword_000000;
   int dword_000004;
  };
  struct
  {
   char  byte_000000;
   char  byte_000001;
   char  byte_000002;
   char  byte_000003;
   char  byte_000004;
   char  byte_000005;
   char  byte_000006;
   char  byte_000007;
  };
 };
 unsigned short word_000008;
 unsigned short word_00000A; // looks like caster mastery
 unsigned short word_00000C;
 unsigned char  byte_00000E;
 char byte_00000F;
};
//sizeof = 10


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
 __int64       qword_00002C;  // time played ?
 __int64       qword_000034;
 int           array_00003C[20];
 int           array_00008C[170];
 int           array_000334[82];
 int           array_00047C[44];
 int           array_00052C[38];
 char          byte_0005C4[2];
 char          byte_0005C6[238];

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
 int           dword_000704; // flying flag?
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
 short         array_000750[5];
 short         array_00075A[5];

 char unk_000765[0x100];

 unsigned char byte_000854[32 + array_size_unknown];

 int dword_00087C;

 int                   dword_000884; //flags
 unsigned int          uAlignment;       // dword      @ 000888   enum (0, 1, 2) = (good, neutral, evil)
 struct PartySpellBuff pPartyBuffs[20];  // struct[20] @ 00088C
 struct Player         pPlayers[4];      // struct[4]  @ 0009CC
 struct NPCData        pHiredNPCs[2];    // struct[2]  @ 0076BC

 int dword_007778;  // party flags;     0x0002 - party position/direction/eyelevel changed
                    //                  0x0004 - You're Drowning!  message displayed
                    //                  0x0200 - You are Burning!  message displayed

 char pad[100000];
 
 float flt_01622C;
 float flt_016230;
 float flt_016234;

 int dword_01613C; // connected to sLastGUIWindowIdx

 int array_016144[array_size_unknown]; // 016144


 char pad2[100000];
};
//sizeof ~ 16238

//int __thiscall Party_sub_49135E_GetAllPartyExpDiv1000(void *_this)
void Party_ctor(struct Party *_this);
//unsigned __int16 __thiscall sub_491BF9(int _this);
void sub_491BF9(struct Party *_this);
//int __thiscall sub_49370F(void *_this);
int Party_sub_49370F(struct Party *_this);
//bool __thiscall sub_497FC5(void *_this);
bool Party_sub_497FC5(struct Party *_this);
//signed int __thiscall sub_48C6F6(void *_this, int a2);
int Party_AddItem(struct Party *_this, int a2);
//int __thiscall sub_49137D(int _this, char a2);
int Party_CreateDefaultParty(struct Party *_this, char a2);

int Party_Reset(struct Party *_this);