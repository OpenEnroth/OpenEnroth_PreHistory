#pragma once
#pragma pack(push, 1)
#include <windows.h>
#include <stdio.h>

#include "defs.h"
#include "classes.h"


char __cdecl sub_408768();

bool InitializeActors(unsigned int uLocationID);


struct Actor_struct0
{
 int   dword_000000;
 int   dword_000004;
 short word_000008;
 short word_00000A;
 char  byte_00000C;
 char  byte_00000D;
 char  byte_00000E;
 char  byte_00000F;
};
//sizeof == 10

struct Actor_struct1
{
  //possibly some of this members have word type instead of dword (due to alignment)
  int   dword_000000;
  int   dword_000004;
  int   dword_000008;
  int   dword_00000C;
  int   X;            //@ dword 000010
  int   dword_000014;
  int   dword_000018;  
};
//sizeof == 1C


struct Actor
{
 unsigned char  pActorName[32]; // byte[32] @ 000000
 short          word_000020;
 short          word_000022;
 int            dword_000024; // some flags
 short          word_000028;
 char           byte_00002A[19];
 char           byte_00003D;
 char           byte_00003E[34];
 unsigned short uMonsterID;     // word @ 000060   (uMonsterID - 1) == monster id in MonsterDescriptionList and MonsterStats  (originally (- 0) in MonsterStats since 0th entry was dummy)
 char           byte_000062[10];
 short          word_00006C;
 char           maybe_hiword_of_dword_00006C[2];
 char           byte_000070[4];
 int            dword_000074;
 int            dword_000078;
 int            dword_00007C;
 char           byte_000080[6];
 short          word_000086;
 short          word_000088;
 short          word_00008A;
 short          word_00008C; // related to monster speed from MosnterInfo
 short          sActorPosX; // word @ 00008E
 short          sActorPosY; // word @ 000090
 short          sActorPosZ; // word @ 000092
 short          word_000094;
 short          word_000096;
 short          word_000098;
 short          word_00009A;
 short          word_00009C;
 short          word_00009E;
 short          word_0000A0;
 short          word_0000A2;
 short          word_0000A4;
 short          word_0000A6;
 short          word_0000A8;
 short          word_0000AA;
 short          word_0000AC;
 short          word_0000AE;
 short          word_0000B0; // if == 5 then monster is rendered as dead on minimap
 short          word_0000B2;
 short          word_0000B4;
 char           byte_0000B6[2];
 int            dword_0000B8;
 unsigned short pSpriteIDs[8]; // word[8] @ 0000BC   Sprite S-Frame IDs
                               // sprite names (for animated creatures):  xxxTnD, xxx - frameset name, T - type ('S' - standing, 'W' - walking, etc), n - frame number ('a' for 0, 'b' for 1, etc), D - creature direction (0, 1, 2, 3, 4 for 'front', 'front-right', 'right', 'back-right', 'back')
                               // e.g.   m342wa0 - frameset "m342" walking animation frame 0 towards player
                               //        m342wa4 - frameset "m342" walking animation frame 0 away from player
                               //        m342wb4 - frameset "m342" walking animation frame 1 away from player
                               // uSpriteIDs[0]: S - standing seqence
                               // uSpriteIDs[1]: W - walking seqence
                               // uSpriteIDs[2]: ?
                               // uSpriteIDs[3]: ?
                               // uSpriteIDs[4]: N - got hit
                               // uSpriteIDs[5]: ?
                               // uSpriteIDs[6]: X - dead
                               // uSpriteIDs[7]: F - bored, no direction
 short                array_0000CC[4];
 struct Actor_struct0 array_0000D4[22];
 struct ItemGen       array_000234[4];
 int   dword_0002C4;
 int   dword_0002C8;
 char  unk_0002CC[96];
 int   dword_00032C;
 int   dword_000330;
 int   dword_000334;
 char  unk_000338[12];
};
//sizeof == 344

bool Actor_sub_40894B(struct Actor *_this);
//int __thiscall Actor_sub_45976D(int this);
int Actor_sub_45976D(struct Actor *_this);
//signed int __fastcall sub_40104C(int a1, int a2);
signed int Actor_sub_40104C(struct Actor *pActor1, struct Actor *pActor2);
//int __fastcall sub_403EB6(unsigned int uActorID, signed int a2, int a3, char *a4);
void Actor_sub_403EB6(unsigned int uActorID, signed int a2, int a3, char *a4);
//int __fastcall sub_403C6C(int a1, int a2, char *a3);
void Actor_sub_403C6C(unsigned int uActorID, int a2, char *a3);
//int __fastcall sub_402F87(int a1, signed int a2, signed int a3);
void Actor_sub_402F87(unsigned int uActorID, signed int a2, signed int a3);
//int __fastcall sub_403F58(int a1, int a2, int a3, signed int a4);
void Actor_sub_403F58(unsigned int uActorID, int a2, int a3, signed int a4);
//int __fastcall sub_404030(int a1, signed int a2, int a3, signed int a4);
void Actor_sub_404030(unsigned int uActorID, signed int a2, int a3, signed int a4);
//int __fastcall sub_402968(int a1, int a2, int a3, char *a4);
void Actor_sub_402968(unsigned int uActorID, int a2, int a3, char *a4);
//int __fastcall sub_402686(int a1, signed int a2, signed int a3, signed int a4);
void Actor_sub_402686(unsigned int uActorID, signed int a2, signed int a3, signed int a4);
//int __fastcall sub_40281C(int a1, signed int a2, signed int a3, signed int a4, int a5);
void Actor_sub_40281C(unsigned int uActorID, signed int a2, signed int a3, signed int a4, int a5);
//int __fastcall sub_402AD7(int a1, signed int a2, signed int a3, int a4, signed int a5);
void Actor_sub_402AD7(unsigned int uActorID, signed int a2, signed int a3, int a4, signed int a5);
//int __fastcall sub_403854(int a1, signed int a2, signed int a3);
void Actor_sub_403854(unsigned int uActorID, signed int a2, signed int a3);
//int __fastcall sub_40368B(int a1, signed int a2, signed int a3);
void Actor_sub_40368B(unsigned int uActorID, signed int a2, signed int a3);
//int __fastcall sub_403476(int a1, signed int a2, signed int a3);
void Actor_sub_403476(unsigned int uActorID, signed int a2, signed int a3);
//int __fastcall sub_403A60(int a1, signed int a2, signed int a3);
void Actor_sub_403A60(unsigned int uActorID, signed int a2, signed int a3);
//int __fastcall sub_4032B2(int a1, int a2, int a3, int a4);
void Actor_sub_4032B2(unsigned int uActorID, int a2, int a3, int a4);
//__int16 __thiscall sub_45959A(int this, char a2);
void Actor_LinkSprites(struct Actor *_this, char a2);
//void *__thiscall sub_459671(int this);
void Actor_Reset(struct Actor *_this);
//int __thiscall sub_41F4C1(void *this);
void Actor_TotalReset(struct Actor *_this);


#pragma pack(pop)