#pragma once

#include "defs.h"
#include "data.h"
#include "memory_mng.h"
#include "RenderD3D3.h"
#include "RenderSoftware.h"
#include "GUI.h"
#include "Level.h"
#include "Actor.h"
#include "Player.h"
#include "classes.h"
#include "Window.h"


#pragma pack(push, 1)

extern OSWindow *pAppWindow;



extern char aTooManyStation[]; // byte[] @ MM7.exe::004F0364

extern int dword_4C9890[10]; // weak
extern int dword_4C9920[16]; // weak
extern char a1[array_size_unknown];
extern int dword_4DF380[array_size_unknown]; // weak
extern int dword_4DF390; // weak
extern char Str2[array_size_unknown]; // idb
extern int dword_4DF3A4; // weak
extern char aBrickShortage[]; // byte[] @ MM7.exe::004DF3A8 
extern int dword_4DF3C8[array_size_unknown]; // weak
extern char byte_4DF3D3[array_size_unknown]; // weak
extern char byte_4E185C; // weak
extern char byte_4E185D; // weak
extern char byte_4E185E; // weak
extern int dword_4E1860; // weak
extern int dword_4E1864; // weak
extern int dword_4E1868; // weak
extern int dword_4E186C; // weak
extern int dword_4E1870; // weak
extern int dword_4E1874; // weak
extern int dword_4E1878; // weak
extern int dword_4E187C; // weak
extern int dword_4E1880; // weak
extern int dword_4E1884; // weak
extern int dword_4E1888; // weak
extern _UNKNOWN unk_4E19FC; // weak
extern char asc_4E1A08[1]; // idb
extern char asc_4E1A28[4]; // idb
extern char byte_4E1B18[array_size_unknown]; // weak
extern wchar_t *off_4E1D18; // weak
extern __int16 word_4E1D3A[array_size_unknown]; // weak
extern __int16 word_4E1D3C[array_size_unknown]; // weak
extern __int16 word_4E1D46[array_size_unknown]; // weak
extern __int16 word_4E1D48[array_size_unknown]; // weak
extern __int16 word_4E1D54[array_size_unknown]; // weak
extern __int16 word_4E1D60[array_size_unknown]; // weak
extern int dword_4E20D0; // weak
extern int dword_4E20D4; // weak
extern char byte_4E2430[array_size_unknown]; // weak
extern char byte_4E2431[array_size_unknown]; // weak
extern int dword_4E249C; // idb
extern int dword_4E24B0; // idb
extern int dword_4E24C4; // weak
extern int dword_4E24D8; // weak
extern char *dword_4E24E8; // idb
extern int dword_4E2544[array_size_unknown]; // weak
extern int dword_4E28F8; // weak
extern char byte_4E28FC; // weak
extern int dword_4E2900_GammaPos; // [0..9]
extern int dword_4E2910[array_size_unknown]; // weak
extern __int16 word_4E2930[array_size_unknown]; // weak
extern __int16 word_4E2938[array_size_unknown]; // weak
extern void *off_4E2942; // weak
extern void *off_4E2A12; // weak
extern int dword_4E2A18[5];
extern int dword_4E2A2C[9]; 
extern int dword_4E2A50[12];
extern int dword_4E2A80[9];
extern _BYTE byte_4E2AA4[20]; // idb
extern int dword_4E2AB8[]; // weak
extern int dword_4E2AC8[]; // weak
extern _UNKNOWN unk_4E2AD9; // weak
extern _UNKNOWN unk_4E2B21; // weak
extern char byte_4E2B70[array_size_unknown]; // weak
extern char byte_4E2BC8; // weak
extern int dword_4E2BCC; // weak
extern int dword_4E2BEC; // weak
extern int dword_4E2C0C[array_size_unknown]; // weak
extern int dword_4E2C2C[array_size_unknown]; // weak
//_UNKNOWN unk_4E2D80; // "\x0C%05d%s\x0C\x30\x30\x30\x30\x30"
//_UNKNOWN unk_4E2DC8; // "\x0C%05d" (this one looks like 16-bit color number)
extern _UNKNOWN unk_4E2DE8; // weak
extern _UNKNOWN unk_4E2E00; // weak
extern _UNKNOWN unk_4E2E10; // weak
extern _UNKNOWN unk_4E2FA0; // weak
extern char byte_4E2FD4; // idb
extern _UNKNOWN unk_4E3030; // weak
extern void *off_4E3044; // weak
//_UNKNOWN unk_4E3264; // "%s: \x0C%05d%s\0x0C\0x30\0x30\0x30\0x30\0x30\0xA"
//_UNKNOWN unk_4E3278; // "%s : \x0C%05u%d\x0C\x30\x30\x30\x30\x30 / %d\x0A"
//char byte_4E3294;    // "\x0C\x30\x30\x30\x30\x30\n"
extern _UNKNOWN unk_4E3308; // weak
extern _UNKNOWN unk_4E3318; // weak
extern _UNKNOWN unk_4E3328; // weak
extern _UNKNOWN unk_4E3338; // weak
extern _UNKNOWN unk_4E334C; // weak
extern _UNKNOWN unk_4E3364; // weak
extern _UNKNOWN unk_4E3374; // weak
extern _UNKNOWN unk_4E3384; // weak
extern __int16 word_4E3ACC[array_size_unknown]; // weak
extern __int16 word_4E3AEC; // weak
extern __int16 word_4E3AF0; // weak
extern __int16 word_4E3B08; // weak
extern __int16 word_4E3C40; // weak
extern __int16 word_4E3C66; // weak
extern __int16 word_4E3C68[array_size_unknown]; // weak
extern __int16 word_4E3C6A[array_size_unknown]; // weak
extern __int16 word_4E3C6C[array_size_unknown]; // weak
extern __int16 word_4E3C6E[array_size_unknown]; // weak
extern __int16 word_4E3C72[array_size_unknown]; // weak
extern char byte_4E3C78[array_size_unknown]; // weak
extern char byte_4E3C79[array_size_unknown]; // weak
extern char byte_4E3C7A[array_size_unknown]; // weak
extern __int16 word_4E3C7C[array_size_unknown]; // weak

extern unsigned char some_spell_stuff[98 * 20]; //struct[98] @ MM7.exe::004E3C8E  98 spells
//_UNKNOWN unk_4E3C8E; // weak
extern char byte_4E3FE8; // weak
extern int dword_4E421C[array_size_unknown]; // weak
//_UNKNOWN unk_4E4436; // weak

extern int dword_4E455C; // weak
extern int dword_4E4560; // weak
extern int dword_4E4578; // weak
extern int dword_4E4590; // weak
extern int dword_4E45A8; // weak
extern int dword_4E4948[array_size_unknown]; // weak
extern int dword_4E494C[array_size_unknown]; // weak
extern int dword_4E49D0[array_size_unknown]; // weak
extern _UNKNOWN dword_4E49D4; // idb
extern int dword_4E4A18[array_size_unknown]; // weak
extern int dword_4E4A1C[array_size_unknown]; // weak
extern int dword_4E4A40[array_size_unknown]; // weak
extern int dword_4E4A44[array_size_unknown]; // weak
extern float flt_4E4A80[array_size_unknown]; // weak
extern float flt_4E4A90; // weak
extern float flt_4E4A94[array_size_unknown]; // weak
extern int dword_4E4C28; // weak
extern int dword_4E4C2C; // weak
extern int dword_4E4C30[array_size_unknown]; // weak
extern int dword_4E4C34[array_size_unknown]; // weak
extern int dword_4E4C38[array_size_unknown]; // weak
extern int dword_4E4C3C[array_size_unknown]; // weak
extern int dword_4E4C40[array_size_unknown]; // weak
extern int dword_4E4C44[array_size_unknown]; // weak
extern int dword_4E4E30[array_size_unknown]; // weak
extern int dword_4E4E34[array_size_unknown]; // weak
extern int dword_4E5050[array_size_unknown]; // weak
extern int dword_4E5054[array_size_unknown]; // weak
extern int dword_4E5270[array_size_unknown]; // weak
extern int dword_4E5274[array_size_unknown]; // weak
extern int dword_4E5490; // weak
extern int dword_4E5494; // weak
extern int dword_4E54B8[array_size_unknown]; // weak
extern int dword_4E54BC[array_size_unknown]; // weak
extern int dword_4E54C0[array_size_unknown]; // weak
extern int dword_4E54C4[array_size_unknown]; // weak
extern int dword_4E5570[array_size_unknown]; // weak
extern int dword_4E5574[array_size_unknown]; // weak
extern int dword_4E56B0; // weak
extern int dword_4E56B4; // weak
extern int dword_4E57F0[array_size_unknown]; // weak
extern int dword_4E57F4[array_size_unknown]; // weak
extern int dword_4E58D0; // weak
extern int dword_4E58D4; // weak
extern int dword_4E5AD0[array_size_unknown]; // weak
extern int dword_4E5AD4[array_size_unknown]; // weak
extern int dword_4E5AE0[8]; 
extern int dword_4E5B00[8]; 
extern int dword_4E5B20[8]; 
extern int dword_4E5B40[8]; 
extern int dword_4E5C1C; // weak
extern int dword_4E5C34; // weak
extern int dword_4E5D68[array_size_unknown]; // weak
extern int dword_4E5D6C[array_size_unknown]; // weak
extern char byte_4E5DD8[array_size_unknown]; // weak
extern char byte_4E5DE8[array_size_unknown]; // weak
extern unsigned int uDialogueUIIconsOffsetX; // dword @ MM7.exe::004E5E50
extern int dword_4E5EC8[array_size_unknown]; // weak
extern unsigned int uDialogueUIIconsOffsetY; // dword @ MM7.exe::004E5EE0
extern char (*off_4E5F70)[8]; // weak
extern int dword_4E5F78[array_size_unknown]; // weak
extern char byte_4E5F7C[array_size_unknown]; // weak
extern char byte_4E5F7D[array_size_unknown]; // weak
extern char *off_4E6BB0; // idb
extern char *off_4E6BDC; // idb
extern _UNKNOWN unk_4E7E20; // weak
extern _UNKNOWN unk_4E7E24; // weak
extern _UNKNOWN unk_4E7E28; // weak
extern int dword_4E800C; // weak
extern unsigned short word_4E8152[];
extern unsigned char data_4E7168[];

extern int dword_4E82B4; // weak
extern int dword_4E82B8; // weak
extern int dword_4E82BC; // weak
extern int dword_4E82C0; // weak
extern char byte_4E8398[]; // weak
extern char unk_4E83B0[];
extern char unk_4E8408[];
extern char byte_4E94D0; // weak
extern char byte_4E94D2; // weak
extern char byte_4E94D3; // weak
extern int dword_4E94D4[array_size_unknown]; // weak
extern int dword_4E94DC[array_size_unknown]; // weak
extern int dword_4E94E4[array_size_unknown]; // weak
extern int dword_4E94EC[array_size_unknown]; // weak
extern int dword_4E98BC; // weak
extern _UNKNOWN unk_4E98D4; // weak
extern char *off_4EB080; // idb
extern const unsigned char *pTransitionStrings[]; // dword[464] @ MM7.exe::004EB084
extern struct unnamed_4EB8B8
{
 float flt_000000;
 float flt_000004;
 float flt_000008;
} array_4EB8B8[];
//_UNKNOWN unk_4EB8BC; // weak
extern struct unnamed_4EB8B8 array_4EBBD0[]; // struct[128] @ MM7.exe::004EBBD0
//_UNKNOWN unk_4EBBD0; // weak

extern int dword_4EC268[array_size_unknown]; // weak
extern int dword_4EC28C[array_size_unknown]; // weak
extern int dword_4EC2A8; // weak
extern int dword_4EC2AC; // weak

extern struct Edge defaultEdge; // struct @ MM7.exe::004EC3EC

extern char byte_4ECA93[array_size_unknown]; // weak
extern char byte_4ECACF[array_size_unknown]; // weak
extern _BYTE byte_4ECB0C[64]; // idb
extern int dword_4ECBB8[array_size_unknown]; // weak
extern int dword_4ECBBC[array_size_unknown]; // weak
extern int dword_4ECBC0[array_size_unknown]; // weak
extern __int16 word_4ECBC4[array_size_unknown]; // weak
extern __int16 word_4ECBC6[array_size_unknown]; // weak
extern __int16 word_4ECBC8[array_size_unknown]; // weak
extern char *off_4ECC30[25]; // weak
extern char *off_4ECC98; // idb
extern char *off_4ECD00; // idb
extern char *off_4ECD68; // idb
extern char *off_4ECDD0; // idb
extern char *off_4ECE38; // idb
extern char *off_4ECEA0; // idb
extern char byte_4ECEEF[array_size_unknown]; // weak
extern char byte_4ED3D8[856];
extern char byte_4ED498; // weak
extern __int16 word_4ED746[array_size_unknown]; // this and next 4 or 5 words are X offsets of player portraits/selection frames i the bottom GameUI hud
extern _WORD off_4ED748[4]; // idb
extern unsigned char byte_4ED750[0xC];

extern char byte_4ED75C[array_size_unknown]; // weak

extern unsigned char byte_4ED768[0x24];

extern unsigned char byte_4ED78C[0x24];


extern char byte_4ED94C[array_size_unknown]; // weak
extern char byte_4ED970[array_size_unknown]; // weak
extern char byte_4ED995[array_size_unknown]; // weak
extern char byte_4ED9BA[array_size_unknown]; // weak
extern char byte_4ED9DF[array_size_unknown]; // weak
extern int dword_4EDEA0[array_size_unknown]; // weak
extern int dword_4EDEB4[array_size_unknown]; // weak
extern int dword_4EDEC4; // weak
extern __int16 word_4EDED8[array_size_unknown]; // weak
extern __int16 word_4EDEDC; // weak
extern int dword_4EDEF8[array_size_unknown]; // weak
extern _UNKNOWN unk_4EDF40; // weak

extern unsigned char uConditionStrengthMultiplier[19]; 
extern unsigned char uConditionIntelligenceMultiplier[19];
extern unsigned char uConditionWillpowerMultiplier[19];
extern unsigned char uConditionEnduranceMultiplier[19];
extern unsigned char uConditionAccuracyMultiplier[19];
extern unsigned char uConditionSpeedMultiplier[19]; 
extern unsigned char uConditionLuckMultiplier[19]; 

extern unsigned int uAgeingTable[4];
extern unsigned char uAgeingStrengthMultiplier[4]; 
extern unsigned char uAgeingIntelligenceMultiplier[4]; 
extern unsigned char uAgeingWillpowerMultiplier[4]; 
extern unsigned char uAgeingEnduranceMultiplier[4]; 
extern unsigned char uAgeingAccuracyMultiplier[4]; 
extern unsigned char uAgeingSpeedMultiplier[4]; 
extern unsigned char uAgeingLuckMultiplier[4]; 

extern int dword_4EDFFC; // weak
extern char byte_4EE038[array_size_unknown]; // weak
extern int dword_4EE06C[array_size_unknown]; // weak
extern int dword_4EE074[array_size_unknown]; // weak

extern int array_4EE07C[2];
//_UNKNOWN unk_4EE07C; // weak
//extern _UNKNOWN unk_4EE084; // array_4EE07C bounding offset

extern __int16 word_4EE088[array_size_unknown]; // weak
extern __int16 word_4EE09A; // weak
extern __int16 word_4EE0A6; // weak
extern __int16 word_4EE128; // weak
extern __int16 word_4EE142; // weak
extern _UNKNOWN unk_4EE150; // weak
extern int dword_4EED78; // weak
extern _UNKNOWN unk_4EED80; // weak
extern int dword_4EFA80; // weak
extern int dword_4EFA84; // weak
extern _UNKNOWN unk_4EFCBC; // weak
extern void *off_4EFDB0; // weak
extern void *off_4EFFF0; // weak
extern __int16 word_4F0040[array_size_unknown]; // weak
extern int dword_4F00DC;
extern int dword_4F00E0; // weak
extern int dword_4F00E4; // weak
extern unsigned int array_4F031C[]; // weak
extern char *off_4F03B8; // idb
extern __int16 word_4F03FE[array_size_unknown]; // weak
extern __int16 word_4F0400[array_size_unknown]; // weak
extern __int16 word_4F0498[array_size_unknown]; // weak
extern __int16 word_4F0576[array_size_unknown]; // weak
extern __int16 word_4F0578[array_size_unknown]; // weak
extern __int16 word_4F05AE[array_size_unknown]; // weak
extern char byte_4F063C[array_size_unknown]; // weak
extern __int16 word_4F063E[array_size_unknown]; // weak
extern __int16 word_4F0640[array_size_unknown]; // weak
extern __int16 word_4F06D8[array_size_unknown]; // weak
extern __int16 word_4F0704[array_size_unknown]; // weak
extern __int16 word_4F0754[array_size_unknown]; // weak
extern __int16 word_4F07B6[array_size_unknown]; // weak
extern __int16 word_4F07B8[array_size_unknown]; // weak
extern __int16 word_4F0866[array_size_unknown]; // weak
extern void *off_4F0882; // weak
extern int dword_4F08EC[array_size_unknown]; // weak
extern char byte_4F09B0[array_size_unknown]; // weak
extern char byte_4F09B1[array_size_unknown]; // weak
extern char byte_4F09B8[array_size_unknown]; // weak
extern _UNKNOWN unk_4F09CC; // weak
extern char byte_4F0CCF[array_size_unknown]; // weak
extern char byte_4F0D38[array_size_unknown]; // weak
extern int dword_4F0E90[array_size_unknown]; // weak
extern int dword_4F0E94[array_size_unknown]; // weak
extern __int16 word_4F0F30[array_size_unknown]; // weak
extern _UNKNOWN unk_4F0F98; // weak

extern void *off_4F2D68; // weak
extern LPVOID off_4F2D6C; // idb
extern int dword_4F2D78; // weak
extern void **off_4F4D88; // weak
extern int dword_4F4D8C; // weak
extern int (__cdecl *off_4F4DA0)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // weak
extern double dbl_4F5372; // weak
extern _UNKNOWN unk_4F54B8; // weak
extern _UNKNOWN unk_4F54D0; // weak
extern int dword_4F5B24[array_size_unknown]; // weak
extern int dword_4F5B28[array_size_unknown]; // weak
extern int dword_4F5B2C[array_size_unknown]; // weak
extern int dword_4F5BF4[array_size_unknown]; // weak
extern int dword_4F5BF8[array_size_unknown]; // weak
extern int dword_4F5BFC; // weak
extern int dword_4F5CC4[array_size_unknown]; // weak
extern int dword_4F5CC8[array_size_unknown]; // weak
extern int dword_4F5CCC; // weak
extern int dword_4F5D98[array_size_unknown]; // weak
extern int dword_4F5D9C; // weak
extern int dword_4F5E68[array_size_unknown]; // weak
extern int dword_4F6638[array_size_unknown]; // weak
extern int dword_4F6E08[array_size_unknown]; // weak
extern int dword_4F75D8; // weak
extern int dword_4F75E0[array_size_unknown]; // weak
extern int dword_4F7DB0[array_size_unknown]; // weak
extern int dword_4F8580[array_size_unknown]; // weak
extern int dword_4F8584[array_size_unknown]; // weak
extern int dword_4F8588[array_size_unknown]; // weak
extern _UNKNOWN unk_4F8858; // weak
extern int dword_4F885C; // weak
extern int dword_4F8864; // weak
extern int dword_4F886C; // weak
extern int dword_4F8870; // weak
extern int dword_4F8874; // weak
extern int dword_4F8878[array_size_unknown]; // weak
extern int dword_4FA9B0[array_size_unknown]; // weak
extern int dword_4FA9B4[array_size_unknown]; // weak
extern char byte_4FAA00; // weak
extern _UNKNOWN unk_4FAA08; // weak
extern _UNKNOWN unk_4FAA20; // weak
extern char byte_4FAA24; // weak
extern int dword_4FAA28; // weak
extern char byte_4FAA2C; // weak
extern char byte_4FAA2D; // weak
extern char byte_4FAA2E; // weak
extern int dword_4FAA34; // weak
extern int dword_4FAA38; // weak
extern int dword_4FAA3C; // weak
extern int dword_4FAA40; // weak
extern int dword_4FAA44; // weak
extern int dword_4FAA48; // weak
extern int dword_4FAA4C; // weak
extern int dword_4FAA50; // weak
extern int dword_4FAA54; // weak
extern int dword_4FAA58; // weak
extern int dword_4FAA5C; // weak
extern int dword_4FAA60; // weak
extern int dword_4FAA64; // weak
extern int dword_4FAA68; // weak
extern int dword_4FAA6C; // weak
extern int dword_4FAA70; // weak
extern char byte_4FAA74; // weak
extern __int16 word_4FAA75; // weak
extern char byte_4FAA77; // weak
extern int dword_4FAA78[array_size_unknown]; // weak
extern char byte_4FAA7C[array_size_unknown]; // weak
extern int dword_4FAA80[array_size_unknown]; // weak
extern int dword_4FAA84[array_size_unknown]; // weak
extern int dword_4FAA88; // weak
extern int dword_4FAA8C; // weak
extern int dword_4FAA90; // weak
extern int dword_4FAA94; // weak
extern int dword_4FABB8; // weak
extern int dword_4FABBC; // weak
extern int dword_4FABC0; // weak
extern int dword_4FABC4; // weak
extern int dword_4FABC8; // weak
extern char byte_4FABD0[array_size_unknown]; // weak
extern char byte_4FABD1[array_size_unknown]; // weak
extern _UNKNOWN unk_4FABD4; // weak
extern int dword_4FABD8; // weak
extern int dword_4FABDC; // weak
extern int dword_4FABE0; // weak
extern int dword_4FABE4; // weak
extern int dword_4FABE8; // weak
extern int dword_4FABEC; // weak
extern int dword_4FABF0; // weak
extern int dword_4FABF4; // weak
extern int dword_4FABF8; // weak
extern int dword_4FABFC; // weak
extern int dword_4FAC00; // weak
extern int dword_4FAC04; // weak
extern int dword_4FAC08; // weak
extern int dword_4FAC0C; // weak
extern int dword_4FAC10; // weak
extern _UNKNOWN unk_4FAC14; // weak
extern _UNKNOWN unk_505289; // weak
extern char byte_5052A8[array_size_unknown]; // weak
extern _UNKNOWN unk_5052C8; // weak
extern int dword_505314[array_size_unknown]; // weak
extern char byte_5054C8[32]; // idb
extern char byte_5054E8[array_size_unknown]; // weak
extern char byte_5054EA[array_size_unknown]; // weak
extern int dword_505554[array_size_unknown]; // weak
extern _UNKNOWN unk_505704; // weak
extern char byte_505708[32]; // idb
extern char byte_505728[array_size_unknown]; // weak
extern int dword_50572C[array_size_unknown]; // weak
extern int dword_505730[array_size_unknown]; // weak
extern int dword_505734[array_size_unknown]; // weak
extern int dword_505738[array_size_unknown]; // weak
extern int dword_50573C[array_size_unknown]; // weak
extern int dword_505740[array_size_unknown]; // weak
extern int dword_505744[array_size_unknown]; // weak
extern int dword_505748[array_size_unknown]; // weak
extern int dword_50574C[array_size_unknown]; // weak
extern int dword_505774; // weak
extern int dword_505778[array_size_unknown]; // weak
extern char byte_5057C4[32]; // idb
extern char byte_5057E4; // weak
extern int dword_5057E8; // weak
extern int dword_5057EC; // weak
extern int dword_5057F0; // weak
extern int dword_5057F4; // weak
extern int dword_5057F8; // weak
extern int dword_5057FC; // weak
extern int dword_505800; // weak
extern int dword_505804; // weak
extern char byte_505880; // weak
extern char byte_505881; // weak
extern int dword_505884; // weak
extern int dword_505888; // weak
extern int dword_50588C; // weak
extern int dword_505890; // weak

extern struct unnamed_505898 struct_505898;
//sizeof ~ FB
//loc_40D707
void unnamed_505898_ctor(struct unnamed_505898 *_this);

extern int dword_5059A8[480]; // 
extern int dword_506128; // weak
extern char byte_506130[array_size_unknown]; // weak
extern int dword_506338; // weak
extern int dword_50633C; // idb
extern int dword_506340; // weak
extern int dword_506344; // weak
extern int dword_506348; // weak
extern __int64 qword_506350; // weak
extern int dword_506358[array_size_unknown]; // weak
extern int dword_50635C; // weak
extern char byte_506360; // weak
extern int dword_506364; // weak
extern int dword_506368; // weak
extern int dword_50636C; // idb
extern int dword_506370; // weak
extern int dword_506374; // idb
extern int dword_506378; // weak
extern int dword_50637C; // idb
extern int dword_506380; // weak
extern int dword_506384; // idb
extern int dword_506388; // weak
extern int dword_50638C; // idb
extern int dword_506390; // weak
extern int dword_506394; // idb
extern int dword_506398; // weak
extern int dword_50639C; // weak
extern int dword_5063A0; // idb
extern int dword_5063A4; // idb
extern int dword_5063A8[array_size_unknown]; // weak
extern int dword_5063AC; // weak
extern int dword_5063B0; // weak
extern int dword_5063B4; // weak
extern int dword_5063B8; // weak
extern int dword_5063BC; // weak
extern int dword_5063D8[array_size_unknown]; // weak
extern int dword_506404; // weak
extern int dword_506408[array_size_unknown]; // weak
extern int dword_50640C[array_size_unknown]; // weak
extern int dword_506434; // weak
extern int dword_506438_TextureID; // weak
extern int dword_50643C; // weak
extern int dword_506440; // idb
extern int dword_506444; // idb
extern int dword_506448; // weak
extern int dword_506450[array_size_unknown]; // weak
extern int dword_506454[array_size_unknown]; // weak
extern _UNKNOWN unk_506494; // weak
extern int dword_506498; // weak
extern int dword_50649C[array_size_unknown]; // weak
extern int dword_5064A0[array_size_unknown]; // weak
extern int dword_5064C4; // weak
extern int dword_5064C8; // weak
extern int dword_5064CC; // weak
extern int dword_5064D0; // weak
extern int dword_5064D4; // weak
extern int dword_5064D8; // weak
extern int dword_5064DC; // weak
extern int dword_5064E0; // weak
extern int dword_5064E4; // weak
extern int dword_5064E8; // weak
extern int dword_5064EC; // weak
extern int dword_5064F0; // weak
extern int dword_5064F4; // weak
extern int dword_5064F8; // weak
extern int dword_5064FC; // weak
extern int dword_506500; // weak
extern int dword_506504; // weak
extern int dword_506508; // weak
extern int dword_50650C; // weak
extern int dword_506510; // weak
extern int dword_506514; // weak
extern int dword_506518; // weak
extern int dword_50651C; // weak
extern int dword_506520; // weak
extern int dword_506524; // weak
extern int dword_506528; // weak
extern int dword_50652C; // weak
extern int dword_506530; // weak
extern int dword_506534; // weak
extern int dword_506538; // weak
extern int dword_50653C; // weak
extern int dword_506540; // weak
extern int dword_506544; // weak
extern int dword_506548; // weak
extern int dword_50654C; // weak
extern char byte_506550; // weak

extern int dword_506568; // weak
extern char byte_50656C; // weak
//extern char Class[array_size_unknown]; // "\0"
extern int dword_506578; // weak

extern Actor         stru_506580_MonsterInfoUI_Doll;             // struct @ MM7.exe::00506580
//extern _UNKNOWN unk_506580;
//extern __int16 word_5065E0; // 0060
//extern __int16 word_506620; // 00A0
//extern __int16 word_506632; // 00B2
//extern int dword_506638;    // 00B8
extern unsigned char stru_506580_MonsterInfoUI_bDollInitialized; // byte   @ MM7.exe::005068C4
//extern char byte_5068C4; // weak

extern int dword_506978; // weak
extern char byte_50697C;
extern int dword_506980; // weak
extern int dword_506984; // weak
extern int dword_506988; // weak
extern int dword_50698C; // weak
extern _UNKNOWN unk_506990; // weak

extern int dword_506E68; // weak
extern _WORD byte_506E6C[18]; // idb
extern int dword_506E90[]; // weak
extern int dword_506E94; // weak
extern int dword_506E98; // weak
extern int dword_506E9C; // weak
extern int dword_506EA0; // weak
extern int dword_506EA4; // weak
extern int dword_506EA8; // weak
extern int dword_506EAC; // weak
extern int dword_506EB0; // weak
extern int dword_506EB4; // weak
extern int dword_506EB8; // weak
extern int dword_506EBC; // weak
extern int dword_506EC0; // weak
extern int dword_506EC4; // weak
extern int dword_506EC8; // weak
extern int dword_506ECC; // weak
extern int dword_506ED0; // weak
extern int dword_506ED4; // weak
extern int dword_506ED8; // weak
extern int dword_506EDC; // weak
extern int dword_506EE0; // weak
extern int dword_506EE4; // weak
extern int dword_506EE8; // weak
extern int dword_506EEC; // weak
extern int dword_506EF0; // weak
extern int dword_506EF4; // weak
extern int dword_506EF8; // weak

extern int dword_506EFC; // weak
extern int dword_506F08; // weak
extern int dword_506F0C; // weak
extern int dword_506F10; // weak
extern int dword_506F14; // weak
extern int dword_506F18; // weak
extern int dword_506F1C; // weak

extern int dword_506F48; // weak

extern struct GUIWindow *pGUIWindow_MainMenu; // ptr @ MM7.exe::00506F4C
//int dword_506F4C; // idb


extern struct GUIWindow GUIWindow_List[20];  // struct array @ MM7.exe::00506F50
//int dword_506F50[array_size_unknown]; // weak
//int dword_506F54; // weak
//int dword_506F60; // weak
//int dword_506F64; // weak
//int array_506F68[420]; // GUIWindow_List[0]::bSlotUsed
//_UNKNOWN unk_506F68; // weak
//int dword_506F78; // weak
//int dword_506F7C; // weak
//int dword_506F80; // weak
//int dword_506F84; // weak
//int dword_506F88; // weak
//int dword_506F94; // weak
//int dword_506F9C; // weak

extern int array_5075E0[20]; // array @ MM7.exe::005075E0
extern int sLastGUIWindowIdx; // dword @ MM7.exe::00507630
extern int dword_507634; // weak
extern int dword_507638; // weak
extern int dword_50763C; // weak
extern int dword_507640; // weak
extern int dword_507644; // weak
extern int dword_507648; // weak
extern int dword_50764C; // weak
extern int dword_507650; // weak
extern int dword_507654; // weak
extern int dword_507658; // weak
extern int dword_50765C; // weak

extern unsigned int uTextureIdx_Leather; // dword @ MM7.exe::00507664

extern int dword_507668; // weak
extern int dword_50766C; // weak
extern int dword_507670; // weak
extern int dword_507674; // weak
extern struct GUIButton *pCharacterUI_BtnExit;      // dword @ MM7.exe::0050767C
extern struct GUIButton *pCharacterUI_BtnAwards;    // dword @ MM7.exe::00507680
extern struct GUIButton *pCharacterUI_BtnInventory; // dword @ MM7.exe::00507684
extern struct GUIButton *pCharacterUI_BtnSkills;    // dword @ MM7.exe::00507688
extern struct GUIButton *pCharacterUI_BtnStats;     // dword @ MM7.exe::0050768C
extern int dword_507690; // weak
extern int dword_507694; // weak

extern unsigned int uTextureID_WindowEdgeTop;          // dword @ MM7.exe::00507698
extern unsigned int uTextureID_WindowEdgeRight;        // dword @ MM7.exe::0050769C
extern unsigned int uTextureID_WindowEdgeLeft;         // dword @ MM7.exe::005076A0
extern unsigned int uTextureID_WindowEdgeBottom;       // dword @ MM7.exe::005076A4
extern unsigned int uTextureIdx_CornerUpperRight; // dword @ MM7.exe::005076A8
extern unsigned int uTextureIdx_CornerUpperLeft;  // dword @ MM7.exe::005076AC
extern unsigned int uTextureIdx_CornerLowerRight; // dword @ MM7.exe::005076B0
extern unsigned int uTextureIdx_CornerLowerLeft;  // dword @ MM7.exe::005076B4
extern unsigned int uTextureIdx_Parchment;        // dword @ MM7.exe::005076B8

extern unsigned int uTextureIdx_MonsterHP_BarYellow; // dword @ MM7.exe::005076BC
extern unsigned int uTextureIdx_MonsterHP_BarRed;    // dword @ MM7.exe::005076C0
extern unsigned int uTextureIdx_MonsterHP_BarGreen;  // dword @ MM7.exe::005076C4
extern unsigned int uTextureIdx_MonsterHP_CapRight;  // dword @ MM7.exe::005076C8
extern unsigned int uTextureIdx_MonsterHP_CapLeft;   // dword @ MM7.exe::005076CC
extern unsigned int uTextureIdx_MonsterHP_Bg;        // dword @ MM7.exe::005076D0

extern int dword_5076F4; // weak
extern int dword_5076FC; // weak


extern int dword_50792C; // weak
extern int dword_507930; // weak
extern int dword_507934; // weak
extern int dword_507938; // weak
extern int dword_50793C; // weak
extern int dword_507940; // weak
extern int dword_507944; // weak
extern char byte_507948; // weak
extern char byte_507949; // weak
extern char byte_50794A; // weak

extern unsigned int uTextureIdx_ib_td5_A; // dword @ MM7.exe::0050794C
extern unsigned int uTextureIdx_ib_td2_A; // dword @ MM7.exe::00507950
extern unsigned int uTextureIdx_ib_td1_A; // dword @ MM7.exe::00507954

extern unsigned int uTextureIdx_InventoryBackground; // dword @ MM7.exe::00507958
extern int dword_50795C_TextureID; // weak
extern int dword_507960_TextureID; // weak
extern int dword_507964_TextureID; // weak
extern int dword_507968_TextureID; // weak
extern int dword_50796C_TextureID; // weak

extern unsigned int uTextureIdx_ib_m4d_a;    // dword @ MM7.exe::00507970
extern unsigned int uTextureIdx_ib_m3d_a;    // dword @ MM7.exe::00507974
extern unsigned int uTextureIdx_ib_m2d_a;    // dword @ MM7.exe::00507978
extern unsigned int uTextureIdx_ib_m1d_a;    // dword @ MM7.exe::0050797Ñ
extern unsigned int uTextureIdx_ib_autout_a; // dword @ MM7.exe::00507980
extern unsigned int uTextureIdx_ib_autin_a;  // dword @ MM7.exe::00507984

extern int dword_507988; // weak
extern unsigned int uTextureIdx_ib_npcrd_a; // dword @ MM7.exe::0050798C
extern unsigned int uTextureIdx_ib_npcld_a; // dword @ MM7.exe::00507990

extern unsigned int uTextureID_MinimapDirections;
extern unsigned int uTextureIdx_MinimapCompass; // dword @ MM7.exe::005079B4

extern unsigned int uTextureIdx_UIBarRed;    // dword @ MM7.exe::005079B8
extern unsigned int uTextureIdx_UIBarYellow; // dword @ MM7.exe::005079BC
extern unsigned int uTextureIdx_UIBarGreen;  // dword @ MM7.exe::005079C0
extern unsigned int uTextureIdx_UIBarBlue;   // dword @ MM7.exe::005079C4

extern int dword_5079C8; // weak
extern int dword_5079CC; // weak
extern unsigned int uTextureIdx_SensorGreen; // dword @ MM7.exe::005079D0
extern unsigned int uTextureIdx_MinimapMask; // dword @ MM7.exe::005079D8
extern unsigned int uTextureID_5079E4; // weak
extern struct GUIButton *pBtn_Game_NPCScrollRightDown; // dword @ MM7.exe::005079E8
extern struct GUIButton *pBtn_Game_NPCScrollLeftDown;  // dword @ MM7.exe::005079EC
extern struct GUIButton *pBtn_Game_Options;            // dword @ MM7.exe::005079F0
extern struct GUIButton *pBtn_Game_QuickRef;           // dword @ MM7.exe::005079F4
extern struct GUIButton *pBtn_Game_CastSpell;          // dword @ MM7.exe::005079F8
extern struct GUIButton *pBtn_Game_Rest;               // dword @ MM7.exe::005079FC
extern struct GUIButton *pBtn_Game_Inventory;          // dword @ MM7.exe::00507A00
extern struct GUIButton *pBtn_Game_Calendar;           // dword @ MM7.exe::00507A04
extern struct GUIButton *pBtn_Game_Maps;               // dword @ MM7.exe::00507A08
extern struct GUIButton *pBtn_Game_Autonotes;          // dword @ MM7.exe::00507A0C
extern struct GUIButton *pBtn_Game_Quests;             // dword @ MM7.exe::00507A10
extern struct GUIButton *pBtn_Game_MinimapZoomIn;      // dword @ MM7.exe::00507A14
extern struct GUIButton *pBtn_Game_MinimapZoomOut;     // dword @ MM7.exe::00507A18

extern struct GUIButton *pMainMenu_Exit;     // ptr @ MM7.exe::00507AE4
extern struct GUIButton *pMainMenu_Credits;  // ptr @ MM7.exe::00507AE8
extern struct GUIButton *pMainMenu_LoadGame; // ptr @ MM7.exe::00507AEC
extern struct GUIButton *pMainMenu_NewGame;  // ptr @ MM7.exe::00507AF0
//int dword_507AE4; // weak
//int dword_507AE8; // weak
//int dword_507AEC; // weak
//int dword_507AF0; // weak

extern int dword_507AF8; // idb
extern int dword_507AFC; // idb
extern int dword_507B00; // weak
extern unsigned int uTextureID_507B04; // weak



extern int dword_507B94; // weak
extern int dword_507B98_bCtrlPressed; // weak
extern int dword_507B9C; // weak
extern int dword_507BA0; // weak
extern int dword_507BA4; // weak

//extern struct class18 *pClass18_ibground; // ptr @ MM7.exe::00507BA8
extern unsigned int uTextureID_ibground; // dword @ MM7.exe::00507BA8 addon, used to be obj ptr

extern int dword_507BAC; // weak
extern int dword_507BB0; // weak

//int dword_507BB4; // idb
extern struct GUIWindow *pGUIWindow0; // ptr @ MM7.exe::00507BB4

extern int dword_507BB8; // idb
extern struct GUIWindow *pDialogueWindow; // dword @ MM7.exe::00507BBC
extern int dword_507BC0; // idb
extern int dword_507BC4; // weak
extern int dword_507BC8; // weak

extern int dword_507BD0; // GUIWindow *
extern int dword_507BD4; // idb
extern int dword_507BDC; // weak
extern int dword_507BE0; // weak

extern struct GUIWindow *pGUIWindow2;         // ptr   @ MM7.exe::00507BE4
extern unsigned int      uActiveCharacter; // dword @ MM7.exe::00507BEC
extern int dword_507BF0; // weak
extern int dword_507BF4; // weak
extern int dword_507BF8; // weak
extern int dword_507BFC; // weak
extern int dword_507C00; // weak
extern int dword_507C04; // weak
extern int dword_507C08; // weak
extern int dword_507C0C; // weak
extern int dword_507C10; // weak
extern int dword_507C14; // weak
extern int dword_507C18; // weak
extern int dword_507C1C; // weak
extern int dword_507C20; // weak
extern int dword_507C24; // weak
extern int dword_507C28[array_size_unknown]; // weak
extern int dword_507C2C; // weak
extern int dword_507C30; // weak
extern int dword_507C34; // weak
extern int dword_507C38; // weak
extern int dword_507C3C; // weak
extern int dword_507C40; // weak
extern int dword_507C44; // weak
extern int dword_507C48; // weak
extern int dword_507C4C; // weak
extern int dword_507C50; // weak
extern int dword_507C54; // weak
extern int dword_507C58; // weak
extern int dword_507C60; // weak
extern int dword_507C64[array_size_unknown]; // weak
extern int dword_507C68; // weak
extern int dword_507C6C; // weak
extern int dword_507C70; // weak
extern int dword_507C74; // weak
extern int dword_507C84; // weak
extern int dword_507C88[array_size_unknown]; // weak
extern int dword_507C8C; // weak
extern int dword_507C90; // weak
extern int dword_507C94; // weak
extern int dword_507C98; // weak
extern int dword_507C9C; // weak
extern int dword_507CA0; // weak
extern int dword_507CA4; // weak
extern int dword_507CA8; // weak
extern int dword_507CAC; // weak
extern int dword_507CB0; // weak
extern int dword_507CB4; // weak
extern int dword_507CB8; // weak
extern int dword_507CBC; // weak
extern int dword_507CC0; // weak
extern __int64 qword_507CC8; // weak
extern int dword_507CD4; // weak
extern int dword_507CD8; // weak



extern struct OldCamera *pOldCamera;

extern struct RenderVertex array_507D30[];
extern struct RenderVertex array_508690[];
extern struct RenderVertex array_508FF0[];
extern struct RenderVertex array_509950[];
extern struct RenderVertex array_50A2B0[];
extern struct RenderVertex array_50AC10[];

extern int dword_50B570[array_size_unknown]; // weak
extern int dword_50B638[array_size_unknown]; // weak
extern int dword_50B700; // weak
extern int dword_50B738[array_size_unknown]; // weak
extern int dword_50B740; // weak
extern int dword_50B744[array_size_unknown]; // weak
extern int dword_50B828[array_size_unknown]; // weak
extern int dword_50B830; // weak
extern int dword_50B834[array_size_unknown]; // weak
extern int dword_50B918[array_size_unknown]; // weak
extern int dword_50B920; // weak
extern int dword_50B924[array_size_unknown]; // weak
extern int dword_50B9D4[array_size_unknown]; // weak
extern int dword_50B9D8[array_size_unknown]; // weak
extern int dword_50B9DC[array_size_unknown]; // weak
extern int dword_50B9E0[array_size_unknown]; // weak
extern int dword_50B9E4[array_size_unknown]; // weak
extern int dword_50B9EC[array_size_unknown]; // weak
extern int dword_50B9F0[array_size_unknown]; // weak
extern int dword_50B9F8[array_size_unknown]; // weak
extern int dword_50B9FC[array_size_unknown]; // weak
extern int dword_50BA04; // weak
extern int dword_50BA08; // weak
extern int dword_50BAC4[array_size_unknown]; // weak
extern int dword_50BAC8[array_size_unknown]; // weak
extern int dword_50BACC[array_size_unknown]; // weak
extern int dword_50BAD0[array_size_unknown]; // weak
extern int dword_50BAD4[array_size_unknown]; // weak
extern int dword_50BADC[array_size_unknown]; // weak
extern int dword_50BAE0[array_size_unknown]; // weak
extern int dword_50BAE8[array_size_unknown]; // weak
extern int dword_50BAEC[array_size_unknown]; // weak
extern int dword_50BAF4; // weak
extern int dword_50BAF8; // weak


extern struct class24 *pClass24_global;  //struct @ MM7.exe::0050BBE0
//struct class24 class24_global;
/* //class24_global
 int dword_50BBE0; // weak
 int dword_50BBE4; // weak
 int dword_50BBE8; // weak
 int dword_50BBEC; // weak
 int dword_50BBFC; // weak
 int dword_50BC00; // weak
 int dword_50BC04; // weak
*/
extern int dword_50BC10[array_size_unknown]; // weak
extern int dword_50BDA0[array_size_unknown]; // weak
extern int dword_50BF30[array_size_unknown]; // weak
extern char byte_50C0C0; // weak
extern int dword_50C0C4; // weak

struct unnamed_50C0C8_stru0
{
 short          word_000000;
 unsigned short uPlayerID;       // word @ 000002
 short          word_000004;
 short          word_000006;
 short          word_000008;
 short          word_00000A;
 short          word_00000C;
 short          word_00000E;
 int            dword_000010;
};
extern struct unnamed_50C0C8
{
 struct unnamed_50C0C8_stru0 array_000000[10];
} struct_50C0C8;
//loc_42696D
void struct_50C0C8_ctor(struct unnamed_50C0C8 *_this);
//int __thiscall sub_426987(int _this)
void struct_50C0C8_ctor_sub0(struct unnamed_50C0C8_stru0 *_this);

//extern _UNKNOWN unk_50C0C8[256*array_size_unknown]; // weak
extern _UNKNOWN unk_50C190; // weak
extern _UNKNOWN unk_50C198; // weak

extern unsigned int dword_50C96C[5]; // weak
//int dword_50C970; // weak
//int dword_50C974; // weak
//int dword_50C978; // weak
//int dword_50C97C; // weak

extern int dword_50C980; // weak
extern int dword_50C984; // weak

extern unsigned int uIconTableFrameID_CharacterFrame; // dword @ MM7.exe::0050C988
extern unsigned int uTextureIdx_CharacterSelectionFrame; // dword @ MM7.exe::0050C98C
extern int dword_50C990; // weak
extern int dword_50C994; // weak
extern int dword_50C998; // weak
extern int dword_50C99C; // weak
extern int dword_50C9A0; // weak
extern int dword_50C9A4; // weak
extern int dword_50C9A8; // weak
extern int dword_50C9AC; // weak
extern int dword_50C9B0; // weak
extern int dword_50C9B4; // weak
extern int dword_50C9B8; // weak
extern int dword_50C9BC; // weak
extern int dword_50C9C0; // weak
extern int dword_50C9C4; // weak
extern int dword_50C9C8; // weak
extern int dword_50C9CC; // weak
extern int dword_50C9D0; // weak
extern int dword_50C9D4; // weak
extern int dword_50C9D8; // weak
extern int dword_50C9DC; // weak
extern int dword_50C9E0; // weak
extern int dword_50C9E8[array_size_unknown]; // weak
extern int dword_50C9EC[array_size_unknown]; // weak
extern int dword_50C9F0[array_size_unknown]; // weak

extern int dword_50CBD0[array_size_unknown]; // 404 for action[def:space] key
//int dword_50CBD4[array_size_unknown]; // weak
//int dword_50CBD8[array_size_unknown]; // weak
//int dword_50CBDC; // weak
extern int dword_50CDC8; // weak
extern int dword_50CDCC; // weak
extern _UNKNOWN unk_50CDD0; // weak
extern _UNKNOWN unk_50CDD4; // weak
extern _UNKNOWN unk_50CDFC; // weak
extern char byte_50D9D0; // weak
extern _UNKNOWN unk_50D9D8; // weak
extern _UNKNOWN unk_50DA04; // weak
extern char byte_50E5D8; // weak
extern _UNKNOWN unk_50E5E0; // weak
extern _UNKNOWN unk_50E5E4; // weak
extern _UNKNOWN unk_50E5FC; // weak
extern _UNKNOWN unk_50E600; // weak
extern _UNKNOWN unk_50E60C; // weak
extern char byte_50F1E0; // weak
extern unsigned int bNotIntelCPU; // dword @ MM7.exe::0050FDEC
extern int dword_50FDFC; // weak
extern int dword_50FE00; // weak
extern int dword_50FE04; // weak
extern int dword_50FE08; // weak
extern _UNKNOWN unk_510064; // weak
extern char byte_5101F4[array_size_unknown]; // weak
extern char byte_510258[array_size_unknown]; // weak
extern _UNKNOWN unk_5102BC; // weak
extern int dword_51076C; // weak
extern int dword_510774; // weak

extern unsigned char pStartMapName[36]; // idb

extern struct class36 class36_global0; // struct @ MM7.exe::005107A8
//_UNKNOWN unk_5107A8;
//_UNKNOWN unk_5107B4; // 000008
//float flt_5107B8[620]; // 000010
//extern char byte_51117E[array_size_unknown]; // weak
//int dword_5111AC; // 000A04
//int dword_5111B0; // 000A08
extern char byte_5111B9[4]; // weak
extern char byte_5111C0[54];
extern char byte_5111F6[18]; 
extern unsigned int pPaperdollTextures_Beards[]; // dword[4] @ MM7.exe::00511208
extern int dword_51120C; // weak
extern unsigned int uTextureID_ButtExit1; // weak
extern int dword_511214; // weak
extern int dword_511218; // weak
extern int dword_51121C; // weak
extern int dword_511220; // weak
extern int dword_511224; // weak
extern int dword_511228; // weak
extern int dword_51122C; // weak
extern int dword_511230; // weak
extern int dword_511234; // weak
extern unsigned int pPaperdollTextures_RightHands[]; // dword[4] @ MM7.exe::0051124C
extern unsigned int pPaperdollTextures_LeftHandsWeapon[]; // weak
extern unsigned int pPaperdollTextures_LeftHandsEmpty[]; // dword[4] @ MM7.exe::0051126C
extern unsigned int pPaperdollTextures_Bodies[]; // dword[4] @ MM7.exe::0051127C
extern int dword_511290[204]; 
//extern int dword_511294[array_size_unknown]; // weak
//extern int dword_511298[array_size_unknown]; // weak
extern unsigned int pPaperdollTextures_LeftArmsWeapon[]; // dword[4] @ MM7.exe::005115C0
extern unsigned int pPaperdollTextures_LeftArmsEmpty[];  // dword[4] @ MM7.exe::005115D0
extern unsigned int pPaperdollTextures_Feet[];           // dword[4] @ MM7.exe::005115E0

extern unsigned int uTextureListForPaperdoll[89];  // dword @ MM7.exe::00511638
extern int dword_51179C; // weak
extern int dword_5117A0; // weak
extern int dword_5117A4; // weak
extern int dword_5117A8; // weak
extern int dword_5117AC; // weak
extern int dword_511828[array_size_unknown]; // weak
extern int dword_51183C; // weak
extern int dword_511840; // weak
extern int dword_511844; // weak
extern int dword_511848; // weak
extern int dword_51184C; // weak
extern int dword_5118C8; // weak
extern unsigned int uTextureID_GameUI_MagnifyingGlass;         // dword @ MM7.exe::005118CC
extern unsigned int uTextureID_GameUI_PaperdollBackground;     // dword @ MM7.exe::005118D8
extern unsigned int uTextureID_GameUI_PaperdollJewelryOverlay; // dword @ MM7.exe::005118DC
extern int dword_5118E0; // weak

extern struct struct5 array_5118E8[100]; // struct[100] @ MM7.exe::005118E8
//_UNKNOWN unk_5118E8; // weak
//_UNKNOWN unk_5118F4; // weak

extern struct RenderBillboard pBillboardRenderList[500];              // struct[500] @ MM7.exe::00512250
//_UNKNOWN unk_512250;
//_UNKNOWN unk_512254; // weak
//int dword_512260[array_size_unknown]; // weak
//_UNKNOWN unk_512278; // weak
//extern _UNKNOWN unk_51227A; // weak
extern unsigned int uNumBillboardsToDraw; // dword @ MM7.exe::005187E0

extern int dword_5187E4; // weak
extern int dword_5187E8; // weak
extern int dword_5187EC; // weak
extern struct StationaryLightsStack *pStationaryLightsStack; // struct @ MM7.exe::005187F0
//_UNKNOWN unk_5187F0; // weak
//struct struct7 array_5187F4[400]; // struct[400] @ MM7.exe::005187F4
//int            dword_519AB4; // num of elements in array_5187F4

extern _UNKNOWN unk_519AB8; // weak

extern struct struct6 array_519ABC[400]; // struct[400] @ MM7.exe::00519ABC
extern int dword_51B6DC; // num of elements in array_519ABC

extern int dword_51B6E0; // weak
extern char byte_51B6E4; // weak
extern int dword_51B6E8; // weak
extern int dword_51B6EC; // weak
extern int dword_51B6F0; // weak
extern int dword_51B6F4; // weak
extern int dword_51B6F8; // weak
extern int dword_51B6FC; // weak
extern int dword_51B700; // weak
extern int dword_51B704; // weak
extern int dword_51B708; // weak
extern int dword_51B70C; // weak
extern float flt_51B710; // weak
extern int dword_51B714; // weak
extern int dword_51B718; // weak
extern int dword_51B71C; // weak
extern _UNKNOWN unk_51B720; // weak
extern __int16 word_51B722; // weak
extern int dword_51B724; // weak
extern int dword_51B728; // weak
extern int dword_51B734; // weak
extern int dword_51B738; // weak
extern int dword_51B73C; // weak
extern int dword_51B740; // weak
extern int dword_51B748; // weak
extern int dword_51B754; // weak
extern int dword_51B758; // weak
extern int dword_51B75C; // weak
extern int dword_51B760; // weak
extern int dword_51B764; // weak
extern int dword_51B768; // weak
extern int dword_51B76C; // weak
extern int dword_51B770; // weak
extern int dword_51B774; // weak

extern struct class37 class37_global0; // struct @ MM7.exe::0051B778
//int dword_51B778; // weak
extern __int16 word_51B77C[array_size_unknown]; // weak
extern __int16 word_51B77E[array_size_unknown]; // weak
extern int dword_51C71C; // weak
extern __int16 word_51C720[array_size_unknown]; // weak
extern __int16 word_51C722; // weak
extern __int16 word_51C724; // weak
extern __int16 word_51C726; // weak
extern __int16 word_51C728; // weak
extern _UNKNOWN unk_51C72C; // weak
extern _UNKNOWN unk_51C730; // weak
extern __int16 word_51CEC4; // weak
extern int dword_51CEC8; // weak
extern _UNKNOWN unk_51CECC; // weak
extern _UNKNOWN unk_51CF2C; // weak



extern int dword_56EEA8; // weak
extern __int16 word_56EEAC[array_size_unknown]; // weak
extern int dword_576D14; // weak
extern __int16 word_576D80[array_size_unknown]; // weak

extern unsigned int uTextureIdx_SpellEffecIcons[14]; // dword[14] @ MM7.exe::00576DE8
extern unsigned int uIconIdx_Spell21;                // dword     @ MM7.exe::00576E20
extern unsigned int uIconIdx_Spell27;                // dword     @ MM7.exe::00576E24
extern int dword_576E28; // weak
extern int dword_576E2C; // weak

//struct related to loading screen
extern struct class56 *pLoadingUI; // struct @ MM7.exe::00576E30
//_UNKNOWN unk_576E30; // weak
//char byte_576E3A; // pLoadingUI::uProgressMax
//int dword_576E3C; // 00000C


//definetly a OldViewport, used for initialization of game OldCamera; maybe OldViewport class instance
extern struct unnamed_576FE8
{
 int dword_000000;
 int dword_000004;
 int dword_000008;
 int dword_00000C;
 int dword_000010;  //screen::vx1 config entry
 int dword_000014;  //screen::vy1
 int dword_000018;  //screen::vx2
 int dword_00001C;  //screen::vy2
 int dword_000020;
 unsigned int uMinimapZoom; // dword @ 000024    256/512/1024/2048/4096, 512 default
 int dword_000028;
 int dword_00002C;
 int dword_000030;
 int dword_000034;
 short word_000038;
 short word_00003A;
 int   dword_00003C;
 unsigned int uTextureID_LocationMap; // 000040, dword @ MM7.exe::00577028
 int dword_000044; // dword_57702C
 int dword_000048; // dword_577030
 int dword_00004C; // dword_577034
 int dword_000050; // dword_577038
 int dword_000054; // dword_57703C
 int dword_000058;
 int dword_00005C;
 int dword_000060;
 int dword_000064;
 int dword_000068;
 int pSomeColorTable[256]; //used to be word[256] @ 00006C, a color table, 0x200 bytes long, now in dwords 0x400 bytes long
} struct_576FE8;      // struct @ MM7.exe::00576FE8


extern __int64 qword_5773B8; // weak
extern int dword_5773C0; // weak

extern struct Event   pSomeOtherEVT_Events[]; // weak
extern unsigned int   uSomeOtherEVT_NumEvents; // weak
extern unsigned char *pSomeOtherEVT; // weak

extern struct Event   pSomeEVT_Events[];  // struct[4400] @ MM7.exe::00584238
extern unsigned int   uSomeEVT_NumEvents; // dword        @ MM7.exe::00591078
extern unsigned char *pSomeEVT; // weak



//enum DIALOGUE_TYPE
#define DIALOGUE_ARENA_WELCOME            89
#define DIALOGUE_ARENA_FIGHT_NOT_OVER_YET 90
#define DIALOGUE_ARENA_REWARD             91
#define DIALOGUE_ARENA_ALREADY_WON        92


extern int dword_591080; // weak
extern int dword_591084; // weak
extern struct Actor *pDialogue_SpeakingActor;   // dword @ MM7.exe::00591088
extern unsigned int  uDialogueType;             // dword @ MM7.exe::0059108C     enum DIALOGUE_TYPE
extern unsigned int  uDialogue_SpeakingActorID; // dword @ MM7.exe::00591090
extern int dword_591094; // weak
extern char byte_591098[200]; // idb
extern int dword_591160; // weak
extern char *dword_591164; // idb
extern int dword_591168; // weak
extern int dword_59116C; // weak
extern int dword_591170; // weak
extern int dword_591174; // weak
extern int dword_591178; // weak
extern int dword_59117C; // weak
extern char byte_591180[600]; // idb
extern int dword_5913D8[array_size_unknown]; // weak
extern int dword_5913F0; // weak
extern int dword_5913F4[array_size_unknown]; // weak
extern unsigned int uTextureID_Dialogue_NPCPortrait[]; // dword @ MM7.exe::0059140C
extern int dword_591424; // weak

extern struct class18 *pClass18_EndcapTexture; // ptr @ MM7.exe::00591428
//int dword_591428; // idb

extern int dword_59142C; // weak
extern unsigned int uTextureID_Dialogue_Background; // dword @ MM7.exe::00591430
extern __int16 word_591438[array_size_unknown]; // weak
extern __int16 word_59143A[array_size_unknown]; // weak
extern int dword_59143C[array_size_unknown]; // weak
extern int dword_591440[array_size_unknown]; // weak
extern int dword_591448[array_size_unknown]; // weak
extern __int16 word_591454[array_size_unknown]; // weak
extern _UNKNOWN unk_591458; // weak
extern _UNKNOWN unk_59145C; // weak
extern __int16 word_591460; // weak
extern __int16 word_591462; // weak
extern __int16 word_591464; // weak
extern __int16 word_591466; // weak
extern __int16 word_591468[array_size_unknown]; // weak
extern _UNKNOWN unk_59146C; // weak
extern __int16 word_593A36; // weak
extern _UNKNOWN unk_597F10; // weak
extern int dword_597F18; // weak

extern unsigned int  uLevelStrOffsets[500]; // dword[500] @ MM7.exe::00597F20

extern struct Event  pGlobalEVT_Events[4400];  // struct[4400] @ MM7.exe::005986F0
extern unsigned int  uGlobalEVT_NumEvents; // dword        @ MM7.exe::005A5530
extern unsigned int  uGlobalEVT_Size;      // dword        @ MM7.exe::005A5534
extern unsigned char pGlobalEVT[];         // byte[46080]  @ MM7.exe::005A5538

extern unsigned char byte_5B0938[]; // idb
extern unsigned int  uLevelStrNumStrings; // dword      @ MM7.exe::005B1108
extern unsigned int  uLevelStrFileSize;   // dword      @ MM7.exe::005B110C
extern unsigned int  uLevelEVT_NumEvents; // dword      @ MM7.exe::005B1110
extern unsigned int  uLevelEVT_Size;      // dword      @ MM7.exe::005B1114
extern unsigned char pLevelStr[9216];     // byte[9216] @ MM7.exe::005B1120
extern unsigned char pLevelEVT[9216];     // byte[9216] @ MM7.exe::005B3520
//unsigned char byte_5B3521[array_size_unknown]; // pLevelEVT + 1
//unsigned char byte_5B3522[array_size_unknown]; // pLevelEVT + 2
//unsigned char byte_5B3523[array_size_unknown]; // pLevelEVT + 3
//unsigned char byte_5B3524[array_size_unknown]; // pLevelEVT + 4
//unsigned char byte_5B3525[array_size_unknown]; // weak
//unsigned char byte_5B3526[array_size_unknown]; // weak
//unsigned char byte_5B3527[array_size_unknown]; // weak
//unsigned char byte_5B3528[array_size_unknown]; // weak
//unsigned char byte_5B3529[array_size_unknown]; // weak
//unsigned char byte_5B352A[array_size_unknown]; // weak
//unsigned char byte_5B352B[array_size_unknown]; // weak
//unsigned char byte_5B352C[array_size_unknown]; // weak
extern int dword_5B5920; // weak
extern int dword_5B5924; // weak
extern _UNKNOWN unk_5B5928[]; // 100x32 bytes struct array around here
//extern _UNKNOWN unk_5B5934[]; // weak
extern int dword_5B65A8; // weak
extern int dword_5B65AC; // weak
extern int dword_5B65B0; // weak
extern int dword_5B65B4; // weak
extern int dword_5B65B8; // weak
extern int dword_5B65BC; // weak
extern int dword_5B65C0; // weak
extern int dword_5B65C4; // weak
extern int dword_5B65C8; // weak
extern int dword_5B65CC; // weak
extern int dword_5B65D0; // weak

extern struct Event pLevelEVT_Events[4400]; // struct[4400] @ MM7.exe::005B65D8
//_UNKNOWN unk_5B65D8[0xCE40 + 64*array_size_unknown]; // pLevelEVT_Events[0]::dword_000000
//_UNKNOWN unk_5B65DC; // pLevelEVT_Events[0]::dword_000004
//int dword_5B65E0; // pLevelEVT_Events[0]::dword_000008
//int dword_5B65EC; // pLevelEVT_Events[1]::dword_000008
extern _UNKNOWN unk_5C310E; // weak
extern int dword_5C3418; // weak
extern int dword_5C341C; // weak
extern int dword_5C3420; // weak
extern char byte_5C3427[array_size_unknown]; // weak
extern unsigned char byte_5C3428[]; // idb
//extern char byte_5C34EF[array_size_unknown]; // pStatusBarString[-1] addressing
extern unsigned char pStatusBarString[200]; // byte[200] @ MM7.exe::005C34F0
extern int dword_5C35B8; // weak
extern int dword_5C35BC; // weak
extern int dword_5C35C0; // weak
extern int dword_5C35C4; // weak
extern int dword_5C35C8; // weak

extern unsigned char *p2DEventsTXT_Raw ; // ptr @ MM7.exe::005C35CC

extern int dword_5C35D0; // weak
extern int dword_5C35D4; // weak

extern int dword_5C35E0; // Font *
extern int dword_5C35E4; // Font *

extern int dword_5C35F0; // weak
extern int dword_5C35F4; // weak


extern int dword_5C3610[1000 + array_size_unknown]; // weak
extern char byte_5C45AF[array_size_unknown]; // weak
extern unsigned char byte_5C45B0[2048];
//char byte_5C45B1[array_size_unknown]; // weak

extern _UNKNOWN unk_5C4DB0; // weak
extern unsigned char TmpBuf[array_size_unknown + 2000]; // byte[~2000] @ MM7.exe::005C5DB0
extern char byte_5C657F[array_size_unknown]; // weak

extern char byte_5C6D50[100]; // weak
extern int dword_5C6DB4; // weak

extern int dword_5C6DD8; // weak
extern int dword_5C6DDC; // weak
extern int dword_5C6DE0; // weak
extern int dword_5C6DE4; // weak
extern int dword_5C6DE8; // weak
extern char byte_5C6DEC; // weak
extern __int64 qword_5C6DF0; // weak
extern int dword_5C6DF8; // weak



extern char byte_5C8678[104]; // idb
//next is pClassDescriptions @ 005C86E0


extern unsigned char *pAttributeDescriptions[7]; // ptr[7] @ MM7.exe::005C8778
//int dword_5C8778[array_size_unknown]; // weak
extern unsigned char *array_5C8810[38];
extern unsigned char *array_5C88A8[38];
extern unsigned char *array_5C8940[38];
extern unsigned char *array_5C89D8[38];
extern unsigned char *array_5C8A70[38];

extern unsigned char *pClassTXT_Raw; // ptr @ MM7.exe::005C8B54
extern unsigned char *pStatsTXT_Raw; // ptr @ MM7.exe::005C8B58
extern unsigned char *pSkillDescTXT_Raw; // ptr @ MM7.exe::005C8B5C

extern struct StorylineText *pStorylineText; // struct @ MM7.exe::005C8B60
//LPCSTR lpsz; // idb
extern _DWORD dword_5C8B64[87]; // idb

extern struct class48 *pClass48; // struct @ MM7.exe::005C8CC0 
//char byte_5C8CC0[8]; // weak
extern _UNKNOWN unk_5C8CC8; // weak
extern char byte_5C8D1A[array_size_unknown]; // weak

extern struct class40 *pClass40; // struct @ MM7.exe::005D29E0
//int dword_5D29E0; // weak
//int dword_5D29E4[array_size_unknown]; // pClass40::pItems[0]::pName
extern int dword_5D29E8[array_size_unknown]; // weak
extern int dword_5D29EC[array_size_unknown]; // weak
extern int dword_5D29F4[array_size_unknown]; // weak
extern __int16 word_5D29F8[array_size_unknown]; // weak
extern __int16 word_5D29FC; // weak
extern __int16 word_5D29FE; // weak
//char byte_5D2A00[]; // pItems[0]+20
//char byte_5D2A01[array_size_unknown]; // weak
//char byte_5D2A02[array_size_unknown]; // weak
//char byte_5D2A03[array_size_unknown]; // weak
//char byte_5D2A04[array_size_unknown]; // weak
//char byte_5D2A05[array_size_unknown]; // weak
//char byte_5D2A12[array_size_unknown]; // weak
extern int dword_5DAD28[array_size_unknown]; // weak
extern int dword_5DBFD0[array_size_unknown]; // weak
extern int dword_5DBFD4[array_size_unknown]; // weak
extern char byte_5DBFE9[array_size_unknown]; // weak
extern int dword_5DC1A8[array_size_unknown]; // weak
extern int dword_5DC1AC[array_size_unknown]; // weak
extern int dword_5DC1BC[array_size_unknown]; // weak
extern char byte_5DC1CC[array_size_unknown]; // weak
extern char byte_5DC1DC[array_size_unknown]; // weak
extern __int16 word_5E1944[array_size_unknown]; // weak
extern __int16 word_5E2CCC[array_size_unknown]; // weak
extern int dword_5E40B8[array_size_unknown]; // weak
extern int dword_5E40F8; // weak
extern int dword_5E40FC; // weak
extern int dword_5E4100; // weak
extern int dword_5E4104; // weak
extern int dword_5E4108; // weak
extern int dword_5E410C; // weak
extern int dword_5E4178; // weak


extern _UNKNOWN unk_5E4C14; // weak
extern char byte_5E4C15[array_size_unknown]; // weak
extern unsigned char *pSomeItemsNames[]; // dword[14] @ MM7.exe::005E4C18
/*extern char *dword_5E4C1C; // weak
extern char *dword_5E4C20; // weak
extern char *dword_5E4C24; // weak
extern char *dword_5E4C28; // weak
extern char *dword_5E4C2C; // weak
extern char *dword_5E4C30; // weak
extern char *dword_5E4C34; // weak
extern char *dword_5E4C38; // weak
extern char *dword_5E4C3C; // weak
extern char *dword_5E4C40; // weak
extern char *dword_5E4C44; // weak
extern char *dword_5E4C48; // weak
extern char *dword_5E4C4C; // weak
*/
extern unsigned char *pGlobalTXT_Raw;           // ptr @ MM7.exe::005E4C68
extern unsigned char *pMonstersTXT_Raw;         // ptr @ MM7.exe::005E4C6C
extern unsigned char *pMonsterPlacementTXT_Raw; // ptr @ MM7.exe::005E4C70
extern unsigned char *pSpellsTXT_Raw;           // ptr @ MM7.exe::005E4C74
extern unsigned char *pMapStatsTXT_Raw;         // ptr @ MM7.exe::005E4C78
extern unsigned char *pHostileTXT_Raw;          // ptr @ MM7.exe::005E4C7C
extern unsigned char *pPotionsTXT_Raw;          // ptr @ MM7.exe::005E4C80
extern unsigned char *pPotionNotesTXT_Raw;      // ptr @ MM7.exe::005E4C84
extern unsigned char *pHistoryTXT_Raw;          // ptr @ MM7.exe::005E4C88

extern struct struct4 global_5E4C90; // struct @ MM7.exe::005E4C90
//char byte_5E4C90[array_size_unknown]; // weak
//char byte_5E4CDA[array_size_unknown]; // weak
//char byte_5E4CDB[array_size_unknown]; // weak
extern _UNKNOWN unk_5E4D52; // weak


//_UNKNOWN unk_5E4D58; // weak
extern unsigned short array_5E4D58[50][10];
//_UNKNOWN unk_5E4D64; // weak
extern int dword_5E5130[array_size_unknown]; // weak
extern int dword_5E5144; // weak

extern struct struct3 array_5E5150[20]; // struct[20] @ MM7.exe::005E5150
//__int16 word_5E5150[array_size_unknown]; // weak
//char byte_5E5152[array_size_unknown]; // 000002
//_UNKNOWN unk_5E5154; // 000004
//int dword_5E5160; // 000010
//int dword_5E5164; // 000014
//_UNKNOWN unk_5E5168; // 000018
//char byte_5E516D[array_size_unknown]; // weak
//__int16 word_5E6502[array_size_unknown]; // 13B2
//__int16 word_5E6504[array_size_unknown]; // 13B4
extern unsigned int dword_5FF140; // idb

extern int chest_descriptor[2];   //struct @ MM7.exe::005FF144
//int dword_5FF144; // weak
//int dword_5FF148; // weak

extern struct MonsterDescriptionList *pMonsterDescriptionList; // struct @ MM7.exe::05FF14C
//int dword_5FF14C; // weak
//int dword_5FF150; // weak

extern struct Actor pActors[500]; // struct[500] @ MM7.exe::005FF158
//_UNKNOWN unk_5FF158; // weak
//__int16 word_5FF178[array_size_unknown]; // weak
//_UNKNOWN unk_5FF17C; // weak
//char byte_5FF17D[array_size_unknown]; // weak
//char byte_5FF17E[array_size_unknown]; // weak
extern _UNKNOWN unk_5FF180; // weak
//_UNKNOWN unk_5FF184; // this + 0x34 == pActors::word_000060
extern char byte_5FF18C[array_size_unknown]; // weak
//_UNKNOWN unk_5FF191; // 000039 == 2A + 0F
extern char byte_5FF193[array_size_unknown]; // weak
extern char byte_5FF195[array_size_unknown]; // weak
extern char byte_5FF1B4[array_size_unknown]; // weak
extern __int16 word_5FF1B8[array_size_unknown]; // weak
extern int dword_5FF1D4[array_size_unknown]; // weak
extern _UNKNOWN unk_5FF1DE; // weak
//__int16 word_5FF1E0[array_size_unknown]; // pActors[0]::000088
//__int16 word_5FF1E2[array_size_unknown]; // pActors[0]::00008A
//__int16 word_5FF1E6[array_size_unknown]; // pActors[0]::00008E
//__int16 word_5FF1E8[array_size_unknown]; // pActors[0]::000090
//__int16 word_5FF1EA[array_size_unknown]; // pActors[0]::000092
extern _UNKNOWN unk_5FF1F2; // weak
extern __int16 word_5FF1F6[array_size_unknown]; // weak
//__int16 word_5FF208[array_size_unknown]; // pActors[0]::0000B0
extern _UNKNOWN unk_5FF20C; // weak
extern _UNKNOWN unk_5FF22C; // weak
extern _UNKNOWN unk_5FF23C; // weak
extern _UNKNOWN unk_5FF29C; // weak
extern _UNKNOWN unk_5FF2BC; // weak
extern _UNKNOWN unk_5FF2CC; // weak
extern _UNKNOWN unk_5FF2DC; // weak
extern _UNKNOWN unk_5FF2EC; // weak
extern _UNKNOWN unk_5FF38C; // weak
extern _UNKNOWN unk_5FF3B0; // weak
extern int dword_5FF41C[array_size_unknown]; // weak
extern _UNKNOWN unk_5FF420; // weak
extern _UNKNOWN unk_64640F; // weak

extern unsigned int      uNumActors;             // dword        @ MM7.exe::00665228
extern unsigned int      uNumLayingItems;        // dword        @ MM7.exe::0066522C
extern struct LayingItem pLayingItemsList[1000]; // struct[1000] @ MM7.exe::00665230
//_UNKNOWN unk_665230; // 000000
//__int16 word_665232[56000 + array_size_unknown]; // 000002
//int dword_665234; // 000004
//int dword_665238; // 000008
//int dword_66523C; // 00000C
//__int16 word_665240; // 000010
//__int16 word_665242; // 000012
//__int16 word_665244; // 000014
//char byte_66524A[array_size_unknown]; // 00001A
//__int16 word_66524C; // 00001C
//_UNKNOWN unk_66524E; // 00001E
//_UNKNOWN unk_665254; // 000024
//_UNKNOWN unk_665278; // 000048
//int dword_665288[array_size_unknown]; // 000058
//char byte_665291[array_size_unknown]; // 000061

extern int dword_6807B8[array_size_unknown]; // weak
extern int dword_6807E0; // weak
extern int dword_6807E8[array_size_unknown]; // weak
extern int dword_6836C8; // weak

extern struct LevelDecoration pLevelDecorations[3000];
//__int16 word_6836D0[array_size_unknown]; // weak
//_UNKNOWN unk_6836D2; // weak
//int dword_6836D4[array_size_unknown]; // weak
//int dword_6836D8[array_size_unknown]; // weak
//int dword_6836DC; // weak
//int dword_6836E0; // weak
//__int16 word_6836E4; // weak
//__int16 word_6836E6[array_size_unknown]; // weak
//__int16 word_6836EA; // weak
extern unsigned int uNumLevelDecorations; // dword @ MM7.exe::0069ADD0


extern char word_69ADE0; // idb
extern struct KeyboardController
{
 unsigned int  uLastKeyPressed; // dword @ 000000
 unsigned int  dword_000004;
 unsigned int  dword_000008;
 unsigned int  array_00000C_vkeys[30]; // dword[30] @ 00000C
 int           unk_000084[30];
 int           dword_0000FC;
 unsigned char pPressedKeysBuffer[257]; // byte[257] @ 000100
 unsigned char uNumKeysPressed;         // byte @ 000201
 char          byte_0000202;
 char          byte_0000203;
 int           dword_000204;
 int          *ptr_000208;
} *pKeyboardController; // struct @ MM7.exe::0069AE00
// sizeof ~ ?
//void *__thiscall sub_459C8D(void *_this)
void KeyboardController_ctor(struct KeyboardController *_this);
//int __thiscall sub_459C82_LooksLikeBindKey(void *_this, int a2);
int KeyboardController_sub_459C82_LooksLikeBindKey(struct KeyboardController *_this, unsigned int uKey);
//int __thiscall sub_459CC4(int _this);
void KeyboardController_InitalizeKeys(struct KeyboardController *_this);
//int __thiscall sub_459C68(void *_this, int a2, int a3, int a4);
/*private*/ void KeyboardController_InitalizeKey(struct KeyboardController *_this, unsigned int uSlot, unsigned int uVKey, bool bActive);
//char __thiscall sub_459FFC(void *_this);
char KeyboardController_ReadKeyMapping(struct KeyboardController *_this);

//extern int dword_69AE00; // last pressed key
//extern int vKey[30]; // dword[30] @ MM7.exe::0069AE0C
//extern int dword_69AE84[array_size_unknown]; // weak
//extern unsigned char byte_69AF00[256]; // pressed keys buffer
//extern char byte_69B000;
//extern char byte_69B001; // num keys in buffer
extern int dword_69B004; // weak
extern int pAsyncKeyboard; // dword @ 69B00C
extern int dword_69B010[array_size_unknown]; // weak

extern struct unnamed_69B110
{
 void  (*detor_ptr)(struct unnamed_69B110 *, unsigned int); // dword @ 000000
 float   flt_000004;
 float   flt_000008;
 float   flt_00000C;
 float   flt_000010;
 float   flt_000014;
 float   flt_000018;
 float   flt_00001C;
 float   flt_000020;
 float   flt_000024;
} object_69B110; // struct @ MM7.exe::0069B110
//sizeof ~ 28
//_UNKNOWN unk_69B110; // weak
//int dword_69B114; // 000004
//float flt_69B118; // 000008
//float flt_69B11C; // 00000C
//_UNKNOWN unk_69B120; // 000010
//_UNKNOWN unk_69B12C; // 00001C

extern int dword_69B138; // weak
extern _UNKNOWN unk_69B140; // weak
extern _UNKNOWN unk_69B16C; // weak
extern char byte_69BD40; // weak
extern char byte_69BD41; // weak
extern char byte_69BD44; // weak
extern char *dword_69BD48; // idb
extern int dword_69BD58; // weak
extern int dword_69BD5C; // weak
extern int dword_69BD60; // weak
extern int dword_69BD64; // weak
extern _UNKNOWN unk_69BD68; // weak
extern char byte_69BD7C[20]; // idb
extern int dword_69BD90[array_size_unknown]; // weak
extern int dword_69BD94; // weak
extern int dword_69CEFC; // weak
extern int dword_69CF00; // weak
extern int dword_69CF04; // weak
extern int dword_69CF08; // weak
extern int dword_69CF0C; // weak
extern int dword_69CF10; // weak
extern int dword_69CF14; // weak
extern int dword_69CF18; // weak
extern int dword_69CF1C; // weak
extern int dword_69CF20; // weak
extern int dword_69CF24; // idb
extern int dword_69CF28[array_size_unknown]; // weak
extern _UNKNOWN unk_69CFE0; // weak
extern char byte_69CFF4[11200]; // idb
extern _UNKNOWN unk_69FBB4; // weak
extern _UNKNOWN unk_6A0118; // weak
extern int dword_6A013C[array_size_unknown]; // weak
extern _UNKNOWN unk_6A0758; // weak
extern _UNKNOWN unk_6A07A4; // weak

extern struct LODFile *pLODFile_New_LOD; // struct @ MM7.exe::006A0820
//_UNKNOWN unk_6A0820; // weak
extern int dword_6A0A4C; // weak

extern struct LODFile *pLODFile_Games_LOD; // struct @ MM7.exe::006A0A60
//_UNKNOWN unk_6A0A60; // weak
extern int dword_6A0C8C; // weak
extern int dword_6A0C90; // weak
extern int dword_6A0C9C; // weak
extern int dword_6A0CA0; // weak
extern int dword_6A0CA4; // weak
extern int dword_6A0CA8; // weak
extern HWND dword_6A0CFC; // idb
extern int dword_6A0D00; // weak

extern unsigned char *dword_6A0D08; // idb
extern int dword_6A0D0C; // weak
extern _UNKNOWN unk_6A0D10; // weak

struct unnamed_6A0D14 //glow3, glow5, torchlight and wizard eye spell anims
{
 unsigned int uIconIdx; // word @ 000000
 short word_000002;
 short word_000004;
 short word_000006;
 short word_000008;
 short word_00000A;
};
//sizeof == 0C

extern struct unnamed_6A0D14 array_6A0D14[4]; // struct[4] @ MM7.exe::006A0D14
/*extern __int16 word_6A0D14; // weak
extern __int16 word_6A0D18; // weak
extern __int16 word_6A0D1A; // weak
extern __int16 word_6A0D20; // weak
extern __int16 word_6A0D24; // weak
extern __int16 word_6A0D26; // weak

extern unsigned int uIconIdx_Torch; // word @ MM7.exe::006A0D2C

extern __int16 word_6A0D34; // weak
extern __int16 word_6A0D36; // weak

extern unsigned int uIconIdx_WizardEye; // word @ MM7.exe::006A0D38

extern __int16 word_6A0D40; // weak
extern __int16 word_6A0D42; // weak*/

extern unsigned int uCurrentMenuID; // dword @ MM7.exe::006A0D44
extern int dword_6A0D48; // weak

extern struct class51 class51_6A0DA0_dwReserved;
extern struct class51 *pClass51_global; // struct @ stru_6A0DA0.dwReserved
extern struct tagOFNA stru_6A0DA0; // idb
//dwReserved @ 6A0DF0 @ pClass51_global::000000
//int dword_6A0EA0; // ::dword_0000B0
//int dword_6A0EC8; // ::ptr_0000D8
//int dword_6A0ED0; // 0000E0
//int dword_6A0ED4; // 0000E4
//int dword_6A0ED8; // 0000E8
//int dword_6A0EDC; // 0000EC
extern int dword_6A12B0; // weak
extern int dword_6A12B4; // weak
extern _UNKNOWN unk_6A12B8; // weak
extern int dword_6A12C4; // weak
extern int dword_6A12C8; // weak
extern int dword_6A12CC; // weak
extern int dword_6A12D0; // weak
extern __int64 qword_6A12E0; // weak
extern int dword_6A12F4; // weak
extern int dword_6A12F8; // weak
extern int dword_6A12FC; // weak
extern _UNKNOWN unk_6A1318; // weak
extern _UNKNOWN unk_6A16E0; // weak
//int dword_6A1AAC; // 000CBC
//int dword_6A1B20; // 000D30
//int dword_6A1B24; // 000D34
//int dword_6A1B28; // 000D38

extern float flt_6BD074; // weak
extern int dword_6BD078; // weak
extern int dword_6BD07C; // weak

extern struct unnamed_6BD080
{
 short word_000000[2000];
 int dword_000FA0;
 int dword_000FA4;
} struct_6BD080;
//_UNKNOWN unk_6BD080[1000 + 64*array_size_unknown]; // weak
//int dword_6BE020; // ::dword_000FA4
extern int dword_6BE024; // weak
extern int dword_6BE030; // weak
extern int dword_6BE040; // weak
extern int dword_6BE044; // weak

extern struct CTileTable *pTileTable; // struct @ MM7.exe::006BE048
//_UNKNOWN unk_6BE048; // pTileTable::uNumTiles
//int dword_6BE04C; // pTileTable::pTiles
extern int dword_6BE050; // weak
extern int dword_6BE054; // weak
extern int dword_6BE058; // weak
extern int dword_6BE05C; // weak

extern union unnamed_6BE060
{
 int dword_6BE060; // weak
 int dword_6BE064; // weak
} data_6BE060;


extern struct struct9 *pStruct9_global; // struct @ MM7.exe::006BE070
//int dword_6BE070; // 000000
//int dword_6BE074; // shading::dist_shade
//int dword_6BE078; // shading::dist_shademist
//int dword_6BE07C; // shading::dist_mist
//int dword_6BE080; // 000010
//int dword_6BE084; // 000014
//int dword_6BE088; // 000018
//int dword_6BE08C; // 00001C
//int dword_6BE090; // 000020
//int dword_6BE094; // 000024
//int dword_6BE098; // 000028
//int dword_6BE09C; // 00002C
//int dword_6BE0A0; // 000030
//int dword_6BE0A4; // weak
//int dword_6BE0A8; // weak
//int dword_6BE0AC; // weak
//int dword_6BE0B0; // 000040
//int dword_6BE0B4; // weak
//int dword_6BE0B8; // 000048
extern int dword_6BE0C4; // weak
//int dword_6BE0C8; // 000058
extern int dword_6BE0D4; // weak
extern int dword_6BE0D8; // weak
extern int dword_6BE0DC; // idb
extern int dword_6BE0E0; // idb
extern int dword_6BE0E4; // weak
extern int dword_6BE0E8; // weak
extern int dword_6BE0EC; // weak
extern int dword_6BE0F0; // weak
extern int dword_6BE0F4; // weak
extern int dword_6BE0F8; // weak
extern int dword_6BE0FC; // weak
extern int dword_6BE100; // weak
extern int dword_6BE104; // weak
extern char byte_6BE108; // weak
extern char byte_6BE109; // weak
extern char byte_6BE10A; // weak
extern char byte_6BE10B; // weak
extern char byte_6BE10C; // weak
extern char byte_6BE10D; // weak
extern char byte_6BE10E; // weak
extern char byte_6BE10F; // weak
extern char byte_6BE110; // weak
extern char byte_6BE111; // weak
extern char byte_6BE112; // weak
extern char byte_6BE113; // weak
extern char byte_6BE114_cfg_textures_DefaultSkyTexture[16]; // idb
extern char byte_6BE124_cfg_textures_DefaultGroundTexture[16]; // idb
extern int dword_6BE134; // weak
extern int dword_6BE138; // weak
extern int dword_6BE13C; // weak
extern float fWalkSpeedMultiplier; // float @ MM7.exe::006BE144
extern float flt_6BE148; // weak
extern float fTurnSpeedMultiplier; // float @ MM7.exe::006BE14C
extern float flt_6BE150; // weak
//char byte_6BE2D8[20];
//extern wchar_t pWindowClassName[20];
extern HINSTANCE hInstance; // idb
extern const char *pCommand;
//extern HWND hWnd_global; // idb
extern unsigned int uWindowWidth;
extern unsigned int uWindowHeight;
extern unsigned int uWindowPosX;
extern unsigned int uWindowPosY;
extern LONG dwNewLong; // idb
extern HMENU hMenu; // idb
extern int dword_6BE340; // weak
extern char Str1[20]; // idb
extern unsigned int uLevelMapStatsID; // dword @ MM7.exe::006BE358
extern int dword_6BE35C; // weak
extern int dword_6BE360; // weak
extern int dword_6BE364; // weak
extern int dword_6BE368; // weak

extern unsigned char uSoundVolumeMultiplier;
extern unsigned char uVoicesVolumeMultiplier;
extern unsigned char uMusicVolimeMultiplier;
extern int dword_6BE374_WalkSoundFlag; // weak
extern int dword_6BE378_ShowDamageFlag; // weak
extern int dword_6BE37C; // weak
extern int dword_6BE380; // weak
extern int dword_6BE384_2dacceloff; // weak
extern char byte_6BE388_graphicsmode; // weak
extern int uTurnSpeed; // dword @ MM7.exe::006BE38C
extern float flt_6BE3A0; // weak
extern float flt_6BE3A4_debug_recmod1; // weak
extern float flt_6BE3A8_debug_recmod2; // weak
extern float flt_6BE3AC_debug_recmod1_x_1_6; // weak
extern char byte_6BE3B0[20]; // idb
extern char byte_6BE3C4_MaybeDrowningFlag; // underwater flag?
extern char byte_6BE3C5; // weak
extern char byte_6BE3C8[604]; // idb
extern size_t Size; // idb
extern int dword_6BE63C; // weak
extern int dword_6BE640; // weak
extern int dword_6BE644; // weak
extern int dword_6BE648; // weak
extern int dword_6BE64C; // weak
extern int dword_6BE654; // array of some structs
extern int dword_6BE658; // weak
extern int dword_6BE65C; // weak
extern int dword_6BE660; // weak
extern void *Src; // idb
extern int dword_6BE66C; // weak
extern int dword_6BE670; // weak
extern void *dword_6BE67C; // idb
extern int dword_6BE684; // weak
extern int dword_6BE688; // weak
extern _UNKNOWN unk_6BE68C; // weak
extern int dword_6BE698; // weak
extern int dword_6BE69C; // weak
extern int dword_6BE6A0; // weak
extern int dword_6BE6A4; // weak
extern __int64 qword_6BE6B4; // weak
extern char byte_6BE6EC[array_size_unknown]; // weak



//_UNKNOWN unk_702B28[26 * 1024 * 1024];  //some 26 or 16 Mb pointer is allocated at *(int *)((char *)(pClass23) + 120020) at startup
extern MemoryMng mem_mng;  // struct @ MM7.exe::00702B28;  // struct @ MM7.exe::00702B28
extern int dword_71FFF4; // weak
extern int dword_71FFF8; // weak
extern unsigned int bUseOverrideData; // dword @ MM7.exe::00720008
extern unsigned int bSkipVideo;       // dword @ MM7.exe::0072000C
extern int dword_720010; // idb

extern struct CGame *pGame; //struct @ MM7.exe::00720014
//float pGame;
//int dword_720018; // pGame::000004
extern _BYTE dword_720020[400]; // idb
extern int dword_7201B0[array_size_unknown]; // weak
extern int dword_72065C; // weak
extern int dword_720660[array_size_unknown]; // weak
extern int dword_7207EC; // weak
extern int dword_7207F0[array_size_unknown]; // weak
extern int dword_720980; // weak
extern int dword_720984; // weak
extern __int16 word_7209A0[]; // weak
//extern __int16 word_7209A2[array_size_unknown]; // weak
extern __int16 word_720A70[]; // weak
//extern __int16 word_720A72[array_size_unknown]; // weak
extern __int16 word_720B40[]; // weak
//extern __int16 word_720B42[array_size_unknown]; // weak
extern __int16 word_720C10[]; // weak
//extern __int16 word_720C12[array_size_unknown]; // weak
extern int dword_720CDC; // weak
extern __int16 word_720CE0[]; // weak
//extern __int16 word_720CE2; // word_720CE0+02
extern __int16 word_720DB0[]; // weak
//extern __int16 word_720DB2[array_size_unknown]; // weak
extern int dword_720E80[]; // weak
extern int dword_720ED0[]; // weak
extern int dword_720F20[]; // weak
extern __int16 word_720F70[]; // weak
extern __int16 word_721040[]; // weak
extern int dword_721110[]; // weak
extern int dword_721160[]; // weak
extern int dword_7211B0[]; // weak
extern int dword_721200[array_size_unknown]; // weak
extern int dword_7212C8[array_size_unknown]; // weak
extern __int16 word_721390[array_size_unknown]; // weak
extern __int16 word_721392[array_size_unknown]; // weak
extern __int16 word_721460[array_size_unknown]; // weak
extern __int16 word_721462[array_size_unknown]; // weak

extern struct unnamed_721530
{
 int dword_000000;
 int dword_000004;
 int dword_000008;
 int dword_00000C;
 int dword_000010;
 int dword_000014;
 int dword_000018;
 int dword_00001C;
 int dword_000020;
 int dword_000024;
 int dword_000028; // looks like some local struct
 int dword_00002C;
 int dword_000030;
 int dword_000034; // looks like some local struct
 int dword_000038;
 int dword_00003C;
 int dword_000040;
 int dword_000044;
 int dword_000048;
 int dword_00004C;
 int dword_000050;
 int dword_000054;
 int dword_000058; // looks like some local struct
 int dword_00005C;
 int dword_000060;
 int dword_000064;
 int dword_000068;
 int dword_00006C;
 int dword_000070;
 int dword_000074; // some index
 int dword_000078;
 int dword_00007C;
 int dword_000080;
 int dword_000084;
 int dword_000088;
 int dword_00008C;
 int dword_000090;
 int dword_000094;
 int dword_000098;
 int dword_00009C;
 int dword_0000A0;
} stru_721530; // struct @ MM7.exe::00721530
//sizeof ~ A4
//int dword_721530; // 000000
//int dword_721534; // weak
//int dword_721538; // weak
//int dword_72153C; // weak
//int dword_72154C; // weak
//int dword_721550; // 000020
//int dword_721554; // weak
//int dword_721558; // weak
//int dword_72155C; // weak
//int dword_721560; // 000030
//int dword_721564; // weak
//int dword_721568; // weak
//int dword_72156C; // weak
//int dword_721570; // 000040
//int dword_721574; // weak
//int dword_721578; // weak
//int dword_72157C; // weak
//int dword_721580; // 000050
//int dword_721584; // weak
//int dword_721588; // weak
//int dword_72158C; // weak
//int dword_721590; // 000060
//int dword_721594; // weak
//int dword_72159C; // weak
//int dword_7215A0; // 000070
//int dword_7215A4; // weak
//int dword_7215A8; // weak
//int dword_7215AC; // weak
//int dword_7215B0; // 000080
//int dword_7215B4; // weak
//int dword_7215BC; // weak
//int dword_7215C0; // 000090
//int dword_7215C4; // weak
//int dword_7215C8; // weak
//int dword_7215CC; // weak
//int dword_7215D0; // 0000A0

extern struct unnamed_7215D8_PlayerActionBuffer
{
 unsigned int uNumActions;  // dword     @ 000000
 unsigned int pActions[30]; // dword[30] @ 000004
} stru_7215D8; // struct @ MM7.exe::007215D8
//extern int dword_7215D8; // weak

extern int dword_721654; // weak
extern int dword_721658; // weak
extern int dword_72165C; // weak
extern char *dword_721660; // idb
extern char *dword_721664; // idb
extern _UNKNOWN unk_721668[]; // npctopic
extern _UNKNOWN unk_72166C[]; // npctext
extern int dword_721824; // weak
extern int dword_72193C; // weak
extern int dword_721984[array_size_unknown]; // weak
extern int dword_7219DC[array_size_unknown]; // weak
extern char *dword_721A34; // idb
extern char *dword_721A3C; // idb
extern int dword_721A44; // weak
extern int dword_721A4C; // weak
extern int dword_721A64; // weak
extern int dword_721A6C[array_size_unknown]; // weak
extern int dword_721A84; // weak
extern int dword_721BAC[array_size_unknown]; // weak
extern char *dword_721BC4; // idb
extern _UNKNOWN dword_721E24; // idb
extern int dword_722164; // weak
extern int dword_72216C; // weak
extern int dword_722174; // weak
extern char *dword_72217C; // idb
extern int dword_722240[array_size_unknown]; // weak
extern int dword_722320; // weak
extern int dword_722494; // weak
extern int dword_72266C; // weak
extern _UNKNOWN unk_722880; // weak
extern int dword_722B3C; // weak
extern int dword_722B44; // weak
extern char *dword_722F10; // idb
extern _UNKNOWN unk_722F14[0x800 + array_size_unknown]; // quests.txt
extern _UNKNOWN unk_723714; // weak
extern char *dword_723718; // idb
extern int dword_72371C[array_size_unknown]; // weak
extern _UNKNOWN unk_723724[]; // autonotes.txt
extern char *dword_723D38; // scroll.txt
extern _UNKNOWN unk_723D3C; // weak
extern int dword_723E80[210]; // weak
extern int dword_723E84[array_size_unknown]; // weak
extern _UNKNOWN unk_723E88[]; // awards.txt
extern int dword_7241C8; // weak

extern struct CNPCStats *pNPCStats; // struct @ MM7.exe::007241D0
//_UNKNOWN unk_7241D0; // weak
//extern _UNKNOWN unk_72D5F4; // 009424, pNPCStats::pNPCData[499]
//int dword_72D5F8[array_size_unknown]; // 9428
//extern struct NPCData array_72D68C[]; // 0094BC, struct[] @ MM7.exe::0072D68C
//extern int dword_72D694[array_size_unknown]; // weak
extern int dword_72D6A0[array_size_unknown]; // weak
extern int dword_72D6A8; // weak
//extern _UNKNOWN unk_72D6D0; // 009500  [0]+44   dword_017FC4 x 4C-byte struct array around here
extern _UNKNOWN unk_72D6E0; // weak
extern int dword_72D778; // weak
extern char byte_72E780; // weak
//char dword_736B48[1048]; // pNPCStats::pNPCNames
extern int dword_737C28[array_size_unknown]; // weak
//LPCSTR dword_737C2C; // 13A5C
extern int dword_737C30[array_size_unknown]; // weak
//LPCSTR dword_737C34; // 013A64   013A6C[-1]+0C
//int dword_737C38[]; // 013A68    013A6C[-1]+10
//_UNKNOWN unk_7380C4; // 0013EF4
//char dword_739E74[7136]; // 15CA4
extern int dword_73BA54[array_size_unknown]; // weak
//extern _UNKNOWN unk_73C0C4; // weak
//extern short array_73C0C4[]; // 017EF4, short[51] @ MM7.exe::0073C0C4
//__int16 word_73C12A[102 + array_size_unknown]; // pNPCStats::word_017F5A
//int dword_73C190; // 0017FC0
//extern int dword_73C194; // 017FC4
//int dword_73C1A0[array_size_unknown]; // pNPCStats::dword_017FD0

extern unsigned char *pAwardsTXT_Raw;    // ptr @ MM7.exe::0073C37C
extern unsigned char *pScrollsTXT_Raw;   // ptr @ MM7.exe::0073C380
extern unsigned char *pMerchantsTXT_Raw; // ptr @ MM7.exe::0073C384

extern CHAR dword_73C388[28]; // idb
extern int dword_73C3A4[array_size_unknown]; // weak
extern CHAR dword_73C3C0[28]; // merchant.txt
extern int dword_73C3DC[array_size_unknown]; // weak

extern unsigned char *pTransitionsTXT_Raw; // ptr @ MM7.exe::0073C3F8
extern unsigned char *pAutonoteTXT_Raw;    // ptr @ MM7.exe::0073C3FC
extern unsigned char *pQuestsTXT_Raw;      // ptr @ MM7.exe::0073C400

extern _UNKNOWN unk_73C818; // weak
extern float flt_73C81C; // weak
extern float flt_73C820; // weak
extern float flt_73C824; // weak
extern char byte_73C830; // weak
extern _UNKNOWN unk_73C834[]; // weak
extern char byte_73C84C; // weak


extern unsigned int uNumTerrainNormals;
extern _UNKNOWN unk_73D514[0x20000]; // weak
extern unsigned short uTerrainNormalIndices[]; // weak

extern struct Normal
{
 float x;
 float z;
 float y;
} *pTerrainNormals;                      // ptr @ MM7.exe::0076D514  terrain normals?

extern int dword_76D518; // weak
extern int dword_76D51C; // weak
extern int dword_76D520; // weak
extern int dword_76D524; // weak
extern int dword_76D528; // weak
extern int dword_76D52C; // weak
extern int dword_76D530; // weak
extern int dword_76D534; // weak
extern int dword_76D538; // weak
extern int dword_76D53C; // weak
extern int dword_76D540; // weak
extern int dword_76D544; // weak
extern int dword_76D548; // weak
extern int dword_76D54C; // weak
extern int dword_76D550; // weak
extern int dword_76D554; // weak
extern int dword_76D558; // weak
extern int dword_76D55C; // weak
extern int dword_76D560; // weak
extern int dword_76D564; // weak
extern int dword_76D568; // weak
extern int dword_76D56C; // weak
extern int dword_76D570; // weak
extern int dword_76D574; // weak
extern _UNKNOWN unk_76D578; // weak
extern _UNKNOWN unk_76D590; // weak
extern _UNKNOWN unk_76D5A8; // weak
extern char byte_76D5C0; // weak
extern int dword_76D5C8[12*array_size_unknown]; // weak
extern int dword_76D7C8[12*array_size_unknown]; // weak
extern int dword_76D9C8[12*array_size_unknown]; // weak
extern int dword_76DBC8[12*array_size_unknown]; // weak
extern int dword_76DDC8[];
extern int dword_76DFC8[];
extern int dword_76E1C8[];
extern int dword_76E3C8[];
extern _BYTE byte_76E5C8[]; // idb

extern struct RenderVertexD3D3 pVertices[50];  // struct[50] @ MM7.exe::0077E5C8
//extern _UNKNOWN unk_77E5C8; // x
//extern _UNKNOWN unk_77E5CC; // y
//extern _UNKNOWN unk_77E5D8; // diffuse
//extern _UNKNOWN unk_77E5DC; // specular

extern struct struct8 array_77EC08[2000]; //struct[2000] @ MM7.exe::0077EC08
//_UNKNOWN unk_77EC08; // weak
//_UNKNOWN unk_77EC38; // weak
//_UNKNOWN unk_77EC40; // ::ptr_000038
//_UNKNOWN unk_77EC4C; // ::dword_000044
//_UNKNOWN unk_77EC5C; // ::byte_000048[12]
//_UNKNOWN unk_77ED10; // weak
//             7E7E5C     &array_77EC08[1607]
//_UNKNOWN unk_7E7E7E; // array_77EC08[1607]::000022
//_UNKNOWN unk_7F7F7F; // weak
extern _UNKNOWN unk_800000; // weak
//_UNKNOWN unk_8018BC; // &array_77EC08[1999]
//extern int dword_8018D4; // array_77EC08[1999]::000018
//extern int dword_8018D8; // array_77EC08[1999]::00001C
//extern int dword_8018DC; // array_77EC08[1999]::000020
//extern int dword_8018E0; // array_77EC08[1999]::000024
//extern int dword_8018E4; // array_77EC08[1999]::000028
//extern int dword_8018E8; // array_77EC08[1999]::00002C
//int dword_8018F4; // array_77EC08[1999]::000038
//extern struct class18 *dword_8018F8; // 00003C
//extern char byte_801914; // 000058




extern struct class57  *pClass57_global; // struct @ MM7.exe::008019C8
extern struct RenderVertex *ptr_801A04;
extern struct RenderVertex *ptr_801A08;
extern struct RenderVertex  array_801A10[384];
extern struct RenderVertex  array_806210[384];

extern char byte_80AA10; // weak
extern int dword_80AA14; // weak
extern int dword_80AA18; // weak
extern int dword_80AA1C; // weak
extern int dword_80AA20; // weak
extern unsigned int    uNumElementsIn80AA28; // dword        @ MM7.exe::0080AA24
extern struct struct8 *array_80AA28[2000];   // dword[~2000] @ MM7.exe::0080AA28
extern struct Edge *ptr_80C978; // ptr @ MM7.exe::0080C978
extern struct Surf *ptr_80C97C; // ptr @ MM7.exe::0080C97C

extern struct Surf someSurf;  // struct @ MM7.exe::0080C980
extern struct Edge someEdge1; // struct @ MM7.exe::0080C9A4
extern struct Edge someEdge2; // struct @ MM7.exe::0080C9D8
extern struct Edge *ptr_80CA10[];

extern struct class35 class35_obj; // struct @ MM7.exe::0080D198
//_UNKNOWN unk_80D198; // weak
//extern _UNKNOWN unk_816798; // 009600
//extern _UNKNOWN unk_8DE798; // 0D1600
//extern _UNKNOWN unk_989680; // 17C4E8
//extern _UNKNOWN unk_9A6798; // 199600
//extern _UNKNOWN unk_9EB9F1; // 1DE859
//extern _UNKNOWN unk_A6E798; // 261600
//char byte_A74C68; // class35_obj::byte_267AD0
//char byte_A74C69; // class35_obj::byte_267AD1
//char byte_A74C6A; // class35_obj::byte_267AD2
//char byte_A74C6B; // class35_obj::byte_267AD3
//char byte_A74C6C; // class35_obj::byte_267AD4
//char byte_A74C6D; // class35_obj::byte_267AD5
//int dword_A74C70; // class35_obj::dword_267AD8
//int dword_A74C74; // class35_obj::dword_267ADC
//int dword_A74C78; // class35_obj::dword_267AE0
extern int dword_A74C88; // weak

extern struct GUIButton *array_A74C8C[4]; // ptr[4] @ MM7.exe::00A74C8C
//int dword_A74C8C[array_size_unknown]; // weak
//int dword_A74C90; // weak
//int dword_A74C94; // weak
//int dword_A74C98; // weak

extern struct GUIButton *array_A74C9C[4]; // ptr[4] @ MM7.exe::00A74C9C
//int dword_A74C9C[array_size_unknown]; // weak
//int dword_A74CA0; // weak
//int dword_A74CA4; // weak
//int dword_A74CA8; // weak

extern struct GUIButton *array_A74CAC[4]; // ptr[4] @ MM7.exe::00A74CAC
//int dword_A74CAC[array_size_unknown]; // weak
//int dword_A74CB0; // weak
//int dword_A74CB4; // weak
//int dword_A74CB8; // weak

extern struct GUIButton *array_A74CBC[4]; // ptr[4] @ MM7.exe::00A74CBC
//int dword_A74CBC[array_size_unknown]; // weak
//int dword_A74CC0; // weak
//int dword_A74CC4; // weak
//int dword_A74CC8; // weak

extern int dword_A74CCC; // weak
extern int dword_A74CD4; // weak

extern int dword_A74CDC; // weak

extern unsigned int uTextureIdx_PlayerFaceEradicated; // dword @ MM7.exe::00A74CE4
extern unsigned int uTextureIdx_PlayerFaceDead;       // dword @ MM7.exe::00A74CE8

extern int dword_A74CEC[array_size_unknown]; // weak

extern unsigned int uTextureIdx_PlayerFaces[4][56]; // dword[224] @ MM7.exe::00A74CF0
//_UNKNOWN unk_A74CF0; // weak

extern int dword_A75070; // weak
extern char byte_A75074[40]; // idb
extern char byte_A7509C[40]; // idb

extern struct Player *ptr_A750C4;   //pPlayers[-1] indexing
extern struct Player *pPlayers[4]; // ptr[4] @ MM7.exe::00A750C8
//int dword_A750CC; // weak
//int dword_A750D0; // weak
extern int dword_A750D4; // looks like pPlayers[5] indexing

extern __int64 qword_A750D8; // weak
extern __int16 word_A750E0; // weak
extern __int16 word_A750E2; // weak

extern struct CPlayerFrameTable *pPlayerFrameTable; // struct @ MM7.exe::00A750EC
//int dword_A750EC; // pPlayerFrameTable::uNumFrames
//int dword_A750F0; // pPlayerFrameTable::pFrames
extern _UNKNOWN unk_A750F8; // weak
extern _UNKNOWN unk_A81376; // weak
extern _UNKNOWN unk_A96080; // weak
extern _UNKNOWN unk_AA1058; // weak
//extern _UNKNOWN unk_ACBE48; // pParty_global->pPlayers[-1] indexing
extern int dword_ACC038[array_size_unknown]; // weak
extern int dword_ACCCEC[array_size_unknown]; // weak
extern int dword_ACCCF0[array_size_unknown]; // weak
extern int dword_ACCD94[array_size_unknown]; // weak
extern int dword_ACCD98[array_size_unknown]; // weak
extern int dword_ACCDD4[array_size_unknown]; // weak
extern int dword_ACCDD8[array_size_unknown]; // weak



extern struct Party *pParty_global; // struct @ MM7.exe::00ACCFB8
//int dword_ACCFBC; // 000004
//int dword_ACCFC0; // 000008
//int dword_ACCFC4; // 00000C
//int dword_ACCFC8; // 000010
//int dword_ACCFCC; // 000014
//int dword_ACCFD0; // 000018
//int dword_ACCFD4; // 00001C
//int dword_ACCFD8; // 000020
//int dword_ACCFDC; // 000024
//__int64 qword_ACCFE4; // 00002C
//__int64 qword_ACCFEC; // 000034
//_DWORD dword_ACCFF4[20]; // idb
//int dword_ACD044[array_size_unknown]; // 00008C
//int dword_ACD048[array_size_unknown]; // 00008C[1]
//int dword_ACD2EC[array_size_unknown]; // 000334
//int dword_ACD2F0[array_size_unknown]; // 000334[1]
//int dword_ACD434[array_size_unknown]; // 00047C
//int dword_ACD438[array_size_unknown]; // 00047C[1]
//int dword_ACD4E4; // 00052C
//_DWORD dword_ACD4E8[36]; // 00052C[1]
//char byte_ACD57E[array_size_unknown]; // 0005C6
//int dword_ACD66C; // 0006B4
//int dword_ACD670; // 0006B8
//int dword_ACD674; // 0006BÑ
//int dword_ACD678; // pParty_global::0006C0
//int dword_ACD67C; // pParty_global::0006C4
//int dword_ACD680; // pParty_global::0006C8
//int dword_ACD684; // pParty_global::0006CC
//int dword_ACD688; // pParty_global::0006D0
//int dword_ACD68C; // pParty_global::0006D4
//int dword_ACD690; // pParty_global::0006D8
//int dword_ACD694; // pParty_global::0006DC
//int dword_ACD698; // pParty_global::0006E0
//int dword_ACD69C; // pParty_global::0006E4
//int dword_ACD6A0; // pParty_global::0006E8
//int dword_ACD6A8; // pParty_global::0006F0
//int dword_ACD6AC; // pParty_global::0006F4
//int dword_ACD6B0; // pParty_global::0006F8
//int dword_ACD6B4; // pParty_global::0006FC
//int dword_ACD6B8; // 000700
//int dword_ACD6BC; // 000704
//char byte_ACD6C1; // 000709
//char byte_ACD6C2; // 00070A
//int dword_ACD6C4; // 00070C
//int dword_ACD6C8; // 000710
//int dword_ACD6CC; // 000714
//int dword_ACD6D0; // pParty_global::dword_000718
//int dword_ACD6D4; // pParty_global::dword_00071C
//int dword_ACD6D8; // pParty_global::dword_000720
//int dword_ACD6DC; // 000724
//int dword_ACD6E0; // ::000728
//int dword_ACD6EC; // ::000734
//_UNKNOWN unk_ACD6F0; // 000738
//char byte_ACD6F1[array_size_unknown]; // 000739
//int dword_ACD6F4; // 00073C
//int dword_ACD6FC; // 000744
//int dword_ACD700; // 000748
//extern __int16 word_ACD708[array_size_unknown]; // 000750
//extern __int16 word_ACD712[array_size_unknown]; // 00075A
extern char byte_ACD719[array_size_unknown]; // weak
//char byte_ACD71C; // 000764
//char byte_ACD71D[array_size_unknown]; // 000764 + 01
extern char byte_ACD76D; // weak
extern char byte_ACD76E; // weak
extern char byte_ACD76F; // weak
extern char byte_ACD770; // weak
extern char byte_ACD771; // weak
extern char byte_ACD772[array_size_unknown]; // weak
extern int dword_ACD788[array_size_unknown]; // weak
extern int dword_ACD794; // weak
//char byte_ACD7B6[array_size_unknown]; // 764 + 9A
//char byte_ACD80C[array_size_unknown]; // weak
extern int dword_ACD82C; // weak
extern int dword_ACD830; // weak
//int dword_ACD834; // 00087C
//int dword_ACD83C; // 000884
//int dword_ACD840; // pParty_global::dword_000888
//int dword_ACD844[array_size_unknown]; //pParty_global::unk_00088C
//int dword_ACD848; // [0]+04
//__int16 word_ACD84C; // [0]+08
//_UNKNOWN unk_ACD854; // 00088C + 0010
//__int16 word_ACD85C; // [1]+08
//_UNKNOWN unk_ACD864; // 00088C + 0020
//__int16 word_ACD86C; // [2]+08
//__int64 qword_ACD874; // 00088C + 0030
//_UNKNOWN unk_ACD884;  // 00088Ñ + 0040
//__int16 word_ACD88C; // [4]+08
//_UNKNOWN unk_ACD894; // 00088Ñ + 0050
//char byte_ACD896[array_size_unknown]; // 0008DE
//int dword_ACD898; // 0008E0
//_UNKNOWN unk_ACD8A4; // 0008EC  088C + 0060
//__int16 word_ACD8AC; // [6]+08
//__int64 qword_ACD8B4; // 0008FC  088Ñ + 0070
//__int16 word_ACD8BC; // [7]+08
//__int16 word_ACD8C0; // [7]+0C
extern char byte_ACD8C2; // weak
extern char byte_ACD8C3; // weak
//__int64 qword_ACD8C4; // 00090C  + 0080
//_UNKNOWN unk_ACD8D4; // 00091C   + 0090
//__int16 word_ACD8DC; // [9]+08
//int dword_ACD8E4; // 00092C + 00A0
//int dword_ACD8E8; // [10]+04
//__int16 word_ACD8EC; // [10]+08
//__int16 word_ACD8EE; // [10]+0A
extern char byte_ACD8F2; // weak
//__int64 qword_ACD8F4; // 00093C   + 00B0
//_UNKNOWN unk_ACD904; // 00094C    + 00C0
//__int16 word_ACD90C; // [12]+08
//__int64 qword_ACD914; // 00095C   + 00D0
//__int16 word_ACD91C; // [13]+08
//__int16 word_ACD91E; // [13]+0A
//_UNKNOWN unk_ACD924; // 00096C    + 00E0
//_UNKNOWN unk_ACD934; // 00097C    + 00F0
//__int16 word_ACD93C; // [15]+08
//__int64 qword_ACD944; // 00098C   + 0100
//__int16 word_ACD94C; // [16]+08
//_UNKNOWN unk_ACD954; // 00099C    + 0110
//__int16 word_ACD95C; // [17]+08
//__int64 qword_ACD964; // 0009AC   + 0120
//__int16 word_ACD970; // 0009B8
//char byte_ACD972; // 0009BA
//char byte_ACD973; // 0009BB
//__int64 qword_ACD974; // 0009BC   + 0130
//__int16 word_ACD97E; // [19]+0A
//int dword_ACD984[array_size_unknown]; // pParty_global::pPlayers[0]::000000
extern int dword_ACD988[array_size_unknown]; // weak
extern int dword_ACD98C; // weak
extern int dword_ACD990; // weak
extern __int64 qword_ACD994; // weak
extern _UNKNOWN unk_ACD99C; // weak
extern int dword_ACD9AC; // weak
extern int dword_ACD9B0; // weak
extern int dword_ACD9B4; // weak
extern int dword_ACD9B8; // weak
extern int dword_ACD9BC; // weak
extern int dword_ACD9C0; // weak
extern int dword_ACD9C4; // weak
extern int dword_ACD9C8; // weak
extern int dword_ACD9CC; // weak
extern int dword_ACD9D0; // weak
extern int dword_ACD9D4; // weak
extern int dword_ACD9D8; // weak
extern int dword_ACD9DC; // weak
extern int dword_ACD9E0; // weak
extern _UNKNOWN unk_ACD9E4; // weak
//extern int dword_ACD9EC; // weak
//extern int dword_ACD9F0; // weak
//extern int dword_ACD9F4; // weak
//extern int dword_ACD9F8; // weak
extern _UNKNOWN unk_ACD9FC; // weak
//extern int dword_ACDA04; // weak
//extern int dword_ACDA08; // weak
extern _UNKNOWN unk_ACDA24; // weak
//_UNKNOWN unk_ACDA2C; // pParty_global::pPlayers[0]::sName
//char byte_ACDA3D[array_size_unknown]; // pParty_global::pPlayers[0]::uClass
//char byte_ACDA3E; // pParty_global::pPlayers[0]::uFace
//__int16 word_ACDA40; // ::0000BC   pParty_global::pPlayers[0]::uStrength
//__int16 word_ACDA44; // ::0000C0
//__int16 word_ACDA48; // ::0000C4
//__int16 word_ACDA4C; // ::0000C8
//__int16 word_ACDA50; // ::0000CC
//__int16 word_ACDA54; // ::0000D0
//__int16 word_ACDA58; // ::0000D4
//__int16 word_ACDA8C[array_size_unknown]; // pParty_global::pPlayers[0]::array_000108
extern _UNKNOWN unk_ACDA9C; // weak
extern _UNKNOWN unk_ACDAD6; // weak
//_UNKNOWN unk_ACDB74; // pPlayers[0]::01F0
extern _UNKNOWN unk_ACDB98; // weak
extern _UNKNOWN unk_ACDBB2; // weak
//_UNKNOWN unk_ACF102; // weak
extern _UNKNOWN unk_ACF124; // weak
extern _UNKNOWN unk_ACF134; // weak
extern _UNKNOWN unk_ACF164; // weak
extern _UNKNOWN unk_ACF184; // weak
extern _UNKNOWN unk_ACF1C4; // weak
extern _UNKNOWN unk_ACF1D4; // weak
extern _UNKNOWN unk_ACF1E4; // weak
//_UNKNOWN unk_ACF2A4; // pParty_global::pPlayers[0]::dword_001920
extern __int16 word_ACF2B8[array_size_unknown]; // weak
extern int dword_ACF2C0[array_size_unknown]; // weak
extern _UNKNOWN unk_ACF3D3; // weak
//extern _UNKNOWN unk_ACF4BC; // pPlayers[0]::001B38

extern __int64 qword_ACF4D0; // weak
//char byte_ACF57A; // pParty_global::pPlayers[1]::uFace
extern _UNKNOWN unk_AD0CC0; // weak
extern int dword_AD0F84[array_size_unknown]; // weak
extern int dword_AD0F98[array_size_unknown]; // weak
extern __int64 qword_AD100C; // weak
//char byte_AD10B6; // pParty_global::pPlayers[2]::uFace
extern _UNKNOWN unk_AD27FC; // weak
extern __int64 qword_AD2B48; // weak
//char byte_AD2BF2; // pParty_global::pPlayers[3]::uFace
extern _UNKNOWN unk_AD4338; // weak
extern int dword_AD4650; // weak
extern int dword_AD4654[array_size_unknown]; // weak
extern int dword_AD4658; // weak
//extern struct NPCData array_AD4674[]; // struct[2] @ MM7.exe::00AD4674
 //char *dword_AD46C0; // idb
 //int dword_AD46D8;    // [1]:000018
 //_UNKNOWN unk_AD46E4; // [1]:000024
 //_UNKNOWN unk_AD46EC; // weak
 //int dword_AD46F0; // weak
 //int dword_AD4704; // [1]:000044
//int dword_AD470C; // start of ItemGen
//int dword_AD4710; // weak
//_UNKNOWN unk_AD4714; // weak
//_UNKNOWN unk_AD471C; // weak
//char byte_AD4720; // ItemGen::14
//char byte_AD4724; // ItemGen::18
//_UNKNOWN unk_AD472D; // weak
//_UNKNOWN unk_AD472E; // 2F - end of ItemGen
//int dword_AD4730; // ::dword_007778
extern int dword_AD4734[array_size_unknown]; // weak
extern _UNKNOWN unk_AD4738; // weak
extern int dword_AD4748[array_size_unknown]; // weak
extern _UNKNOWN unk_AD477C; // weak
extern _UNKNOWN unk_AD478C; // weak
extern _UNKNOWN unk_AD47C6; // weak
extern int dword_AD480C[array_size_unknown]; // weak
extern _UNKNOWN unk_AD4888; // weak
extern _UNKNOWN unk_AD48A2; // weak
extern _UNKNOWN unk_AD5DF2; // weak
extern _UNKNOWN unk_AD5E14; // weak
extern _UNKNOWN unk_AD5E24; // weak
extern _UNKNOWN unk_AD5EB4; // weak
extern _UNKNOWN unk_AD5EC4; // weak
extern _UNKNOWN unk_AD5FB0; // weak
extern _UNKNOWN unk_AD61AC; // weak
extern int dword_ADA0A4; // idb
extern int dword_ADA0B8[array_size_unknown]; // weak
extern int dword_ADA17C[array_size_unknown]; // weak
extern char byte_AE302C[100]; // idb
extern _UNKNOWN unk_AE3090; // weak
//extern int dword_AE30F4; // 01613C
extern int dword_AE30F8[array_size_unknown]; // weak
//int dword_AE30FC[array_size_unknown]; // 016144
extern int dword_AE310C[array_size_unknown]; // weak
extern int dword_AE31E0; // weak
extern int dword_AE31E4; // weak
extern int dword_AE31E8; // weak
extern int dword_AE31EC; // weak


extern char byte_AE3368[array_size_unknown]; // weak
extern char algn_AE3369; // weak
extern char byte_AE336A; // weak
extern char byte_AE336B; // weak
extern int dword_AE336C; // weak
extern int dword_AE3370; // weak
extern float flt_AE3378; // weak
extern float flt_AE337C; // weak
extern float flt_AE3380; // weak
extern float flt_AE3388; // weak
extern float flt_AE338C; // weak
extern float flt_AE3390; // weak
extern char byte_AE3398; // weak
extern _UNKNOWN unk_AE33A0; // weak
extern _UNKNOWN unk_AE33A4; // weak
extern _UNKNOWN unk_AE33C0; // weak
extern _UNKNOWN unk_AE33C4; // weak
extern int dword_AE3FA0; // weak
extern float flt_AE3FA4; // weak
extern float flt_AE3FA8; // weak
extern float flt_AE3FAC; // weak
extern _UNKNOWN unk_AE3FB4; // weak
extern float flt_AE3FE0; // weak
extern char byte_AE3FE4; // weak
extern _UNKNOWN unk_AE3FE8; // weak
extern _UNKNOWN unk_AE3FEC; // weak
extern _UNKNOWN unk_AE4008; // weak
extern _UNKNOWN unk_AE400C; // weak
extern int dword_AE4BE8; // weak
extern float flt_AE4BEC; // weak
extern float flt_AE4BF0; // weak
extern float flt_AE4BF4; // weak
extern _UNKNOWN unk_AE4BFC; // weak
extern float flt_AE4C28; // weak
extern char byte_AE4C2C; // weak
extern _UNKNOWN unk_AE4F60; // weak
extern int dword_AE4F64; // weak
extern float flt_AE4F68; // weak
extern float flt_AE4F6C; // weak
extern _UNKNOWN unk_AE4F70; // weak
extern _UNKNOWN unk_AE4F7C; // weak
extern int dword_AE4F88; // weak
extern _UNKNOWN unk_AE4F90; // weak
extern _UNKNOWN unk_AE4FBC; // weak
extern char byte_AE5B90; // weak
extern char byte_AE5B91; // weak
extern char byte_AE5B94; // weak
extern char *dword_AE5B98; // idb

extern struct class58 *pClass58_global; // struct @ MM7.exe::00AE5BA8
//_UNKNOWN unk_AE5BA8; // weak
//_UNKNOWN unk_C04000; // weak
//_UNKNOWN unk_C86400; // weak
//_UNKNOWN unk_C8C805; // weak
//_UNKNOWN unk_C8C814; // weak
//int dword_DEDBAC; // ::dword_308004
//int dword_DEDBB0; // ::dword_308008
//int dword_DF1BB4; // 30800C
extern IDirectDrawClipper *pDDrawClipper; // dword @ MM7.exe::00FD1BE0

//struct Render *pD3DRenderer = 0;  // struct @ MM7.exe::00DF1BE8
//int dword_DF1BE8; // @ pD3DRenderer::bUseDirect3D
//int dword_DF1BF4; // @ pD3DRenderer::dword_00000C
//int dword_DF1BF8; // @ pD3DRenderer::dword_000010
//int dword_DF1BFC; // @ pD3DRenderer::dword_000014
//int dword_DF1C04; // @ pD3DRenderer::dword_00001Ñ
//int dword_DF1C08; // @ pD3DRenderer::dword_000020
//int dword_DF1C0C; // @ pD3DRenderer::dword_000024
//int dword_DF1C10; // @ pD3DRenderer::dword_000028
//int dword_E31C1C; // @ pD3DRenderer::dword_040034
//int dword_E31C40; // @ pD3DRenderer::dword_040058
//int dword_E31C70; // @ pD3DRenderer::dword_040088
//int dword_E31C74; // @ pD3DRenderer::pdd4
//int dword_E31C78; // @ pD3DRenderer::pdds4
//int dword_E31C7C; // @ pD3DRenderer::dword_040094
//int dword_E31C80; // @ pD3DRenderer::dword_040098
//int dword_E31C84; // @ pD3DRenderer::pdd2
//int dword_E31C88; // @ pD3DRenderer::pdds2
//int dword_E31C8C; // @ pD3DRenderer::dword_0400A4
//int dword_E31CB4; // @ pD3DRenderer::dword_0400CC
//int dword_E31CB8; // @ pD3DRenderer::dword_0400D0
//int dword_E31CBC; // @ pD3DRenderer::dword_0400D4
//int dword_E31CC0; // @ pD3DRenderer::dword_0400D8
//int dword_E31CC4; // @ pD3DRenderer::dword_0400DC
//int dword_E31CC8; // @ pD3DRenderer::dword_0400E0
//int dword_E31CCC; // @ pD3DRenderer::dword_0400E4
//int dword_E31CD4; // @ pD3DRenderer::dword_0400EC
//int dword_E31CD8; // @ pD3DRenderer::dword_0400F0
//int dword_E31CF8; // @ pD3DRenderer::dword_040110
// int dword_EF522C; // @ pD3DRenderer::bUseColoredLights
// int dword_EF5234; // @ pD3DRenderer::dword_10364C
//int dword_EF5248; // @ pD3DRenderer::dword_103660
extern int dword_EF524C; // weak
extern unsigned int uTextureID_WaterTiles[8]; // dword[8] @ MM7.exe::00EF5254
extern int dword_EF5290; // weak
extern int dword_EF5294; // weak
extern int dword_EF52A0; // weak
extern int dword_EF52A4; // weak
extern int (*dword_EF52A8)(void); // weak
extern int dword_EF52B0; // weak

extern struct RenderBillboardD3D3 pBillboardRenderListD3D3[]; // struct[1000] @ MM7.exe::00EF52B8
//extern int dword_EF52B8[array_size_unknown]; // weak
//extern int dword_EF52BC; // weak
//extern struct unnamed_EF52C0 stru_EF52C0;  // struct @ MM7.exe::00EF52C0
//extern _UNKNOWN unk_EF52C0; // weak
//float                2C0    000000
//float                2C4    000004
//float                2C8    000008
//float                2CC    00000C
//extern int dword_EF52C4[array_size_unknown]; // weak
//extern int dword_EF52C8; // weak
//extern int dword_EF52CC; // weak
//extern int dword_EF52D0; // 000010 tint color mask
//extern int dword_EF52D4; // 000014
//float               2D8     000018
//float               2DC     00001C
//extern struct unnamed_EF52E0 stru_EF52E0; // struct @ MM7.exe::00EF52E0
//extern _UNKNOWN unk_EF52E0; // weak
//extern int dword_EF52E4[array_size_unknown]; // weak
//extern int dword_EF52E8; // weak
//extern int dword_EF52EC; // weak
//extern int dword_EF52F0; // weak
//extern int dword_EF52F4; // weak
//extern struct unnamed_EF5300 stru_EF5300; // struct @ MM7.exe::00EF5300
//extern _UNKNOWN unk_EF5300; // weak
//extern int dword_EF5308; // weak
//extern int dword_EF530C; // weak
//extern int dword_EF5310; // weak
//extern int dword_EF5314; // weak
//extern struct unnamed_EF5320 stru_EF5320; // struct @ MM7.exe::00EF5320
//extern _UNKNOWN unk_EF5320; // weak
//extern int dword_EF5328; // weak
//extern int dword_EF532C; // weak
//extern int dword_EF5330; // weak
//extern int dword_EF5334; // weak
//extern int dword_EF5340[array_size_unknown]; // weak
//extern int dword_EF5344[array_size_unknown]; // weak
//extern int dword_EF5348; // weak
//extern int dword_EF534C; // weak
//extern int dword_EF5350[array_size_unknown]; // weak
extern _UNKNOWN unk_F00000; // weak
//int dword_F1B418; // 129830
//int dword_F1B420; // 129838
//int dword_F1B424; // 12983C
//int dword_F1B428; // 129840
extern _UNKNOWN unk_F1B430; // weak
extern BYTE dword_F1B4B0; // idb
extern BYTE Data; // idb

extern int dword_F1B4C8; // weak
extern int dword_F1B4D0; // weak
extern int dword_F1B4D4; // weak

extern struct unnamed_F1B4D8
{
 int dword_000000; // weak
 unsigned char string_000004[120]; // byte[?]
 int dword_00007C; // weak
//extern _UNKNOWN unk_F1B4DC; // weak
 //int dword_F1B554[4800]; // idb
 //int unk_F20054[91169]; // weak
} struct_F1B4D8[];

//struct AudioPlayer *pAudioPlayer = 0; // struct @ MM7.exe::00F790D8
//_UNKNOWN unk_F790D8; // weak
//int dword_F790DC; // AudioPlayer::dword_00004
extern _UNKNOWN unk_F79154; // weak
//int dword_F792F0; // AudioPlayer::dword_000218
//int dword_F79374; // AudioPlayer::dword_00029C
//int dword_F7937C; // AudioPlayer::hAILRedbook (0002A4)
//int dword_F79380; // AudioPlayer::hDigDriver
//int dword_F79390; // AudioPlayer::pSoundHeaders
//HANDLE hFile;  //MM7.exe::dword_F79394    AudioPlayer::hSoundsSource
//int dword_F79398; // AudioPlayer::uNumSounds
//extern char byte_F79448[120]; // idb
//int dword_F794C0; // AudioPlayer::dword_0003E8
//char byte_F794C8[array_size_unknown]; // weak
//_UNKNOWN unk_F79CC8; // weak
//int dword_F79D48; // weak
//char cGameCDDriveLetter; //byte @ MM7.exe::F79D58; // weak

extern struct CSoundList *pSoundList; // struct @ MM7.exe::00F79D5C
//int dword_F79D5C; // weak
//int dword_F79D60; // weak

extern int dword_F79D64; // weak
extern int dword_F79D70; // weak
extern int dword_F79D7C; // weak
extern _UNKNOWN unk_F79E08; // weak
extern _UNKNOWN unk_F79E34; // weak
extern _UNKNOWN unk_F7AA08; // weak
extern _UNKNOWN unk_F7AA10; // weak
extern _UNKNOWN unk_F7AA34; // weak
extern char byte_F7B608; // weak
extern _UNKNOWN unk_F7B60C; // weak
extern float flt_F7B610; // weak
extern float flt_F7B614; // weak
extern float flt_F7B618; // weak
extern float flt_F7B61C; // weak
extern char byte_F7B620; // weak
extern _UNKNOWN unk_F7B628; // weak
extern _UNKNOWN unk_F7B654; // weak
extern _UNKNOWN unk_F7C228; // weak
extern _UNKNOWN unk_F7C230; // weak
extern _UNKNOWN unk_F7C254; // weak
extern char byte_F7CE28; // weak
extern int dword_F81018; // weak
extern _UNKNOWN unk_F8101C; // weak
extern __int16 word_F8101E; // weak
extern _UNKNOWN unk_F81020; // weak
extern __int16 word_F81022; // weak
extern int dword_F81028; // weak
extern _UNKNOWN unk_F81054; // weak
extern int dword_F83B80[array_size_unknown]; // weak
extern int dword_F83B84[array_size_unknown]; // weak
extern int dword_F83BA8[array_size_unknown]; // weak
extern int dword_F8A590; // weak
extern int dword_F8A594; // weak
extern __int16 word_F8A5A8[array_size_unknown]; // weak
extern __int16 word_F8A968[array_size_unknown]; // weak
extern int dword_F8AD28; // weak
extern int dword_F8AD2C; // weak
extern int dword_F8AD30; // weak
extern int dword_F8AD34; // weak
extern int dword_F8AD38; // weak
extern int dword_F8AD3C; // weak
extern int dword_F8AD40; // weak
extern int dword_F8AD44; // weak
extern int dword_F8AD48; // weak
extern int dword_F8AD4C; // weak
extern int dword_F8AD50; // weak
extern int dword_F8AD54; // weak
extern int dword_F8AD5C; // weak
extern int dword_F8AD60; // weak
extern int dword_F8AD64; // weak
extern int dword_F8AD68; // weak
extern int dword_F8AD6C; // weak
extern int dword_F8AD70; // weak
extern int dword_F8AD7C; // weak
extern int dword_F8AD80; // idb
extern int dword_F8AD84; // weak
extern int dword_F8AD88; // weak
extern int dword_F8AD8C; // weak
extern int dword_F8AD90; // weak
extern int dword_F8AD94; // weak
extern int dword_F8AD98; // weak
extern int dword_F8AD9C; // weak
extern int dword_F8ADA0; // weak
extern int dword_F8ADA4; // weak
extern int dword_F8ADA8; // weak
extern int dword_F8ADAC; // weak
extern int dword_F8ADB0; // idb
extern int dword_F8ADB4; // weak
extern int dword_F8ADB8; // weak
extern int dword_F8ADBC; // weak
extern int dword_F8ADC0; // weak
extern int dword_F8ADC4; // weak
extern int dword_F8ADC8; // weak
extern int dword_F8ADCC; // weak
extern int dword_F8ADD0; // weak
extern int dword_F8ADD4; // weak
extern int dword_F8ADD8[array_size_unknown]; // weak
extern int dword_F8AE28[array_size_unknown]; // weak
extern int dword_F8AE78[array_size_unknown]; // weak
extern int dword_F8AEC8[array_size_unknown]; // weak
extern int dword_F8AF18[array_size_unknown]; // weak
extern int dword_F8AF68; // weak
extern int dword_F8AFB8[array_size_unknown]; // weak
extern float flt_F8B008[array_size_unknown]; // weak
extern float flt_F8B058[array_size_unknown]; // weak
extern float flt_F8B0A8[array_size_unknown]; // weak
extern char byte_F8B0F8[array_size_unknown]; // weak
extern int dword_F8B10C; // weak
extern int dword_F8B110; // weak
extern int dword_F8B114; // weak
extern int dword_F8B118; // weak
extern int dword_F8B11C; // weak
extern int dword_F8B120; // weak
extern _DWORD dword_F8B144; // idb
extern _UNKNOWN unk_F8B148; // weak
extern __int16 word_F8B158[array_size_unknown]; // weak
extern int dword_F8B164[array_size_unknown]; // weak
extern int dword_F8B168[array_size_unknown]; // weak
extern int dword_F8B17C; // weak
extern int dword_F8B180[array_size_unknown]; // weak
extern int dword_F8B194; // weak
extern int dword_F8B198; // weak
extern int dword_F8B19C; // weak
extern __int16 word_F8B1A0; // weak
extern int dword_F8B1A4; // weak
extern int dword_F8B1A8; // weak
extern int dword_F8B1AC; // idb
extern int dword_F8B1B0; // weak
extern unsigned int uArenaReward; // dword @ MM7.exe::00F8B1B4
extern int dword_F8B1B8[array_size_unknown]; // weak
extern int dword_F8B1BC; // weak
extern int dword_F8B1C0; // weak
extern int dword_F8B1C4; // weak
extern _UNKNOWN unk_F8B1C8; // weak
extern int dword_F8B1D8; // weak
extern int dword_F8B1DC; // weak
extern int dword_F8B1E0; // weak
extern int dword_F8B1E4; // weak
extern char *dword_F8B1E8; // idb
extern char byte_F8B1EC; // weak
extern char byte_F8B1EF[array_size_unknown]; // weak
extern _UNKNOWN unk_F8B1F0; // weak
extern int dword_F8B1F4; // weak
extern _UNKNOWN unk_F8B1F8; // weak
extern _UNKNOWN unk_F8B5E0; // weak
extern int dword_F8B5E8; // weak
extern int dword_F8B5EC[array_size_unknown]; // weak
extern _UNKNOWN unk_F8B668; // weak
extern _UNKNOWN unk_F8BA50; // weak

extern struct StringSplitter splitter_global; // struct @ MM7.exe::00F8BA58
//int dword_F8BA58; // weak
//int dword_F8BA5C[30]; // weak

extern int dword_F8BAD4;
extern _UNKNOWN unk_F8BAD8; // weak

//struct class32 *pVideoPlayer; // struct @ MM7.exe::00F8BB08
/*
_UNKNOWN unk_F8BB08; // weak
int dword_F8BB2C; // pVideoPlayer::dword_000024
int dword_F8BB30; // weak
int dword_F8BB48; // weak
int dword_F8BB4C; // weak
int dword_F8BB5C; // weak
int dword_F8BB60; // weak
int dword_F8BB6C; // weak
int dword_F8BB74 // weak
HWND dword_F8BB78; // idb
HANDLE dword_F8BB80; // idb
HANDLE hObject; // idb*/
//int dword_F8BB88; // pVideoPlayer::ptr_000080
//int dword_F8BB8C; // pVideoPlayer::ptr_000084
//int dword_F8BBA4; // pVideoPlayer::dword_00009C
                            //maybe overlaps following
extern _UNKNOWN unk_F8BBEC; // weak
extern int dword_F8BC10; // weak

extern struct OldViewport *pOldViewport;  // struct @ MM7.exe::00F8BC14
// int dword_F8BC14; // 000000
// int dword_F8BC18; // 000004
// int dword_F8BC1C; // 000008
// int dword_F8BC20; // 00000C
// int dword_F8BC24; // 000010
// int dword_F8BC28; // 000014
// int dword_F8BC2C; // 000018
// int dword_F8BC30; // 00001C
// int dword_F8BC34; // 000020
// int dword_F8BC38; // 000024
// int dword_F8BC3C; // 000028
// int dword_F8BC40; // 00002C
// int dword_F8BC44; // 000030

extern __int16 word_F8BC48[array_size_unknown]; // weak
extern __int16 word_F8BC4A; // weak
extern __int16 word_F8BD18[array_size_unknown]; // weak
extern __int16 word_F8BD1A[array_size_unknown]; // weak
extern int dword_F8BDE8; // begin of class25
extern int dword_F8D5EC; // class25_stru0 **

extern _UNKNOWN unk_F8DDE0; // weak
extern _UNKNOWN unk_F8DDE4; // weak
extern int dword_F8DDEC; // weak
extern char byte_F8DDF0; // weak

//probably Vis_stru0, but surely 64x48
extern struct Vis_stru0 array_F8DDF8[64]; // struc[64] @ MM7.exe::00F8DDF8
//_UNKNOWN unk_F8DDF8; // weak
//float flt_F8DE10; // 000018
//float flt_F8DE14; // 00001C
//_UNKNOWN unk_F8DE24; // 00002C

extern _UNKNOWN unk_F8E9E0; // [63]+18
extern _UNKNOWN unk_F8E9E4; // [63]+1C
extern char byte_F8E9F8; // weak

//float flt_F8EA00; // weak
//float flt_F8EA04; // weak

extern struct RenderVertexD3D3 array_F8EA00[array_size_unknown]; // struct[?

//probably Vis_stru0, but surely 64x48
extern struct Vis_stru0 array_F8F200[64]; // struct[64] @ MM7.exe::00F8F200
//extern _UNKNOWN unk_F8F200; // weak
//extern _UNKNOWN unk_F8F204; // weak
//extern float flt_F8F20C; // weak
//extern _UNKNOWN unk_F8F22C; // weak

extern struct class25 class25_F8FE00; // struct @ MM7.exe::00F8FE00
//extern int dword_F8FE00; // 000000
//extern int dword_F91604; // 001804
//extern int dword_F91E04; // 002004
extern char byte_F91E08; // weak
extern struct class25 class25_F91E10;  //struct @ MM7.exe::00F91E10
//extern int dword_F91E10; // 000000
//extern int dword_F93614; // 001804
//extern int class25_F91E10.dword_002004; // 002004
extern char byte_F93E18; // weak
extern int dword_F93E1C; // weak
extern int dword_F93E30; // weak
extern int dword_F93E44; // weak
extern int dword_F93E58; // weak

extern struct unnamed_F93E6C
{
 int dword_000000;
 int dword_000004;
 int dword_000008;
 int dword_00000C;
 int dword_000010;
} stru_F93E6C; // struct @ MM7.exe::00F93E6C
//sizeof ~ ?
//int dword_F93E6C; // 000000
extern int dword_F94004; // weak7
extern int dword_F9400C; // weak
extern char byte_F94298; // weak
extern float flt_F942A0; // weak
extern float flt_F942A4; // weak
extern float flt_F942A8; // weak
extern float flt_F942B0; // weak
extern int dword_F944EC; // weak
extern int dword_F944F0; // weak
extern void *dword_F944F4; // idb
extern int dword_F944F8; // weak
extern LPVOID lpMem; // idb
extern int dword_F94500; // weak
extern HANDLE hHeap; // idb

extern int dword_F94508; // weak
extern const void* pCGame_scalar_dtor;

#pragma pack(pop)