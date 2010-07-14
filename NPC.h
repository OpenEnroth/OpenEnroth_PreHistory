#pragma once

#pragma pack(push, 1)

struct NPCProfesstion
{
 unsigned int   uHireCost;    // dword @ 000000
 unsigned char *pBenefits;    // ptr   @ 000004
 unsigned char *pActionText;  // ptr   @ 000008
 unsigned char *pJoinText;    // ptr   @ 00000C
 unsigned char *pDismissText; // ptr   @ 000010
};
//sizeof == 14

struct NPCStats_stru1 //some npc data
{
 char byte_000000[0x4C];
};
//sizeof == 4C

struct NPCData
{
 const unsigned char *pNPCName;     // dword @ 000000
 unsigned int         uPortraitID;  // dword @ 000004
 int                  dword_000008;
 int                  dword_00000C;
 int                  dword_000010;
 int                  dword_000014;
 int                  dword_000018;
 int                  dword_00001C;
 int                  dword_000020;
 int                  dword_000024;
 int                  dword_000028;
 int                  dword_00002C;
 int                  dword_000030;
 int                  dword_000034;
 int                  dword_000038;
 int                  dword_00003C;
 int                  dword_000040;
 int                  dword_000044;
 int                  dword_000048;
};
//sizeof == 4C

struct NPCGreeting
{
 const unsigned char *pGreeting1; // dword @ 000000
 const unsigned char *pGreeting2; // dword @ 000004
};
//sizeof == 8

struct CNPCStats
{
 struct NPCData  pNPCData[501];     // struct[501]  @ 000000
 struct NPCData  pNPCData2[501];    // struct[501]  @ 0094BC
 unsigned char  *pNPCNames[540][2]; // ptr[2] array @ 012978

 struct NPCProfesstion pProfessions[58]; //struct[58] @ 013A6C
 struct NPCStats_stru1 array_0013EF4[array_size_unknown];

 int            array_015CA4[52];
 unsigned char *pNPCNames2[501]; // dword[?] @ 015D74

 char unk_016544[128*array_size_unknown];

 struct NPCGreeting pNPCGreetings[206]; // struct[205] @ 01788C

 short array_017EF4[51];
 short word_017F5A[51];

 int dword_017FC0;
 int dword_017FC4;

 unsigned int uNumNPCProfessions; // dword    @ 017FCC
 unsigned int uNumNPCNames[2];    // dword[2] @ 017FD0 number of NPC names: [0] for male, [1] for female

 unsigned char *pNPCDataTXT_Raw;  // ptr @ 017FD8
 unsigned char *pNPCNamesTXT_Raw; // ptr @ 017FDC
 unsigned char *pNPCProfTXT_Raw;  // ptr @ 017FE0
 unsigned char *pNPCNewsTXT_Raw;  // ptr @ 017FE4
 unsigned char *pNPCTopicTXT_Raw; // ptr @ 017FE8
 unsigned char *pNPCTextTXT_Raw;  // ptr @ 017FEC
 unsigned char *pNPCDistTXT_Raw;  // ptr @ 017FF0
 unsigned char *pNPCGreetTXT_Raw; // ptr @ 017FF4
 unsigned char *pNCPGroupTXT_Raw; // ptr @ 017FF8
};

void CNPCStats_ctor(struct CNPCStats *_this);
//int __thiscall sub_47702F(void *this);
void CNPCStats_Initialize(struct CNPCStats *_this);
//char *__thiscall sub_476CB5(void *this);
char *CNPCStats_sub_476CB5(struct CNPCStats *_this);
//int __thiscall sub_476977(int this);
int CNPCStats_sub_476977(struct CNPCStats *_this);


#pragma pack(pop, 1)