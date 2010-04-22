#pragma once
#pragma pack(push, 1)
#include <windows.h>
#include <stdio.h>

#include "defs.h"


char __cdecl sub_408768();


struct Actor
{
 unsigned char pActorName[32]; // byte[32] @ 000000
 short         word_000020;
 short         word_000022;
 char          byte_000024[4];
 short         word_000028;
 char          byte_00002A[54];
 short         word_000060;
 char          byte_000062[10];
 short         word_00006C;
 char          byte_00006E[6];
 int           dword_000074;
 int           dword_000078;
 int           dword_00007C;
 char          byte_000080[8];
 short         word_000088;
 short         word_00008A;
 short         word_00008C;
 short         word_00008E;
 short         word_000090;
 short         word_000092;
 short         word_000094;
 short         word_000096;
 short         word_000098;
 short         word_00009A;
 short         word_00009C;
 short         word_00009E;
 short         word_0000A0;
 short         word_0000A2;
 short         word_0000A4;
 short         word_0000A6;
 short         word_0000A8;
 short         word_0000AA;
 short         word_0000AC;
 short         word_0000AE;
 short         word_0000B0;
 short         word_0000B2;
 char          byte_0000B4[18];
 short         word_0000C6;  //some s-sprite index
 char          byte_0000C8[2];
 short         word_0000CA;   //some s-sprite index
 char          byte_0000CC[8];
 char          array_0000D4[22][16];
 char          byte_000234[272];
};
//sizeof == 344

bool sub_40894B(struct Actor *_this);
//int __thiscall sub_45976D(int this);
int sub_45976D(struct Actor *_this);
//signed int __fastcall sub_40104C(int a1, int a2);
signed int Actor_sub_40104C(struct Actor *pActor1, struct Actor *pActor2);


#pragma pack(pop)