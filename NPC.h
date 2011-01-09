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


struct NPCData
{
 const unsigned char *pNPCName;     // dword @ 000000
 unsigned int         uPortraitID;  // dword @ 000004
 int                  dword_000008; // flags;   0x80:  hired
 int                  dword_00000C;
 int                  dword_000010;
 int                  dword_000014;
 unsigned int         uProfession;  // dword @ 000018   0 no profession else prof ID
 int                  dword_00001C;
 int                  dword_000020;
 int                  dword_000024;
 int                  dword_000028; // bool whether spell or some animation is drawn
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

struct NPCStats_stru0
{
 int  dword_000000;
 char unk_000004[60];
};
//sizeof == 40

struct CNPCStats
{
 struct NPCData         pNPCData[501];      // struct[501]  @ 000000
 struct NPCData         pNPCData2[501];     // struct[501]  @ 0094BC
 unsigned char         *pNPCNames[540][2];  // ptr[2] array @ 012978
 int                    dword_013A58;
 int                    dword_013A5C;
 int                    dword_013A60;
 int                    dword_013A64;
 int                    dword_013A68;
 struct NPCProfesstion  pProfessions[58];   // struct[58]  @ 013A6C
 struct NPCData         array_013EF4[100];  // struct[100] @ 013EF4
 unsigned char         *pCatchPhrases[52];  // dword[52]   @ 015CA4
 unsigned char         *pNPCNames2[500];    // dword[500]  @ 015D74
 NPCStats_stru0         array_016544[77];   // struct[~77] @ 016544
 int                    dword_017884;
 int                    dword_017888;
 struct NPCGreeting     pNPCGreetings[205]; // struct[205] @ 01788C
 short                  array_017EF4[51];
 unsigned short         npc_group[51];   //word_017F5A
 int                    dword_017FC0;
 int                    dword_017FC4;  // num elems in pNPCData2
 int                    dword_017FC8;
 unsigned int           uNumNPCProfessions; // dword    @ 017FCC
 unsigned int           uNumNPCNames[2];    // dword[2] @ 017FD0 number of NPC names: [0] for male, [1] for female
 unsigned char         *pNPCDataTXT_Raw;  // ptr @ 017FD8
 unsigned char         *pNPCNamesTXT_Raw; // ptr @ 017FDC
 unsigned char         *pNPCProfTXT_Raw;  // ptr @ 017FE0
 unsigned char         *pNPCNewsTXT_Raw;  // ptr @ 017FE4
 unsigned char         *pNPCTopicTXT_Raw; // ptr @ 017FE8
 unsigned char         *pNPCTextTXT_Raw;  // ptr @ 017FEC
 unsigned char         *pNPCDistTXT_Raw;  // ptr @ 017FF0
 unsigned char         *pNPCGreetTXT_Raw; // ptr @ 017FF4
 unsigned char         *pNCPGroupTXT_Raw; // ptr @ 017FF8
};

void CNPCStats_ctor(struct CNPCStats *_this);
//int __thiscall sub_47702F(void *_this);
void CNPCStats_Initialize(struct CNPCStats *_this);
//char *__thiscall sub_476CB5(void *_this);
void CNPCStats_sub_476CB5(struct CNPCStats *_this);
//int __thiscall sub_476977(int _this);
int CNPCStats_sub_476977(struct CNPCStats *_this);


#pragma pack(pop)

