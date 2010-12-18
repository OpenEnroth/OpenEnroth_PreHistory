#pragma once
#include <windows.h>

#include "FrameTables.h"

#define PARTY_ALIGNMENT_NEUTRAL 1 // -A end
#define PARTY_ALIGNMENT_GOOD    0 // -B end
#define PARTY_ALIGNMENT_EVIL    2 // -C end

void nullsub_1();

extern int bUseLoResSprites;
extern int bUseRegistry;
extern int bLoadingFromCD;

extern float aMusicVolumeLevels[];

extern union unnamed_4D8410
{
 unsigned char byte_4D8410[17412];
 struct
 {
  char   unk_4D8410_0000[24];
  double d1_0;                        // double @ 0018     1.0
  double d_307_19_9;                  // double @ 0020     307.19999999999999
  double d_2_13_3;                    // double @ 0028     2.1333333333333333
  char   unk_4D8410_0030[24];
  double d_0_75;                      // double @ 0048     0.75
  char   unk_4D8410_0050[8];
  double d_0_46875;                   // double @ 0058     0.46875
  char   unk_4D8410_0060[8];
  double d_0_2;                       // double @ 0068     0.2
  double d_0_1_0_1;                   // double @ 0070     0.10000000000000001
  char   unk_4D8410_0078[8];
  double d_5_0;                       // double @ 0080     5.0
  double d_15_0;                      // double @ 0088     15.0
  char   unk_4D8410_0090[8];
  float  fOne;                        // float  @ 0098     1.0
  char   unk_4D8410_009C[20];
  double d_0_0;                       // double @ 00B0     0.0
  double d0_01;                       // double @ 00B8     0.01
  double d_70_0;                      // double @ 00C0     70.0
  double d_0_67_0_4;                  // double @ 00C8     0.67000000000000004
  double d_0_34_0_2;                  // double @ 00D0     0.34000000000000002
  float  fZero;                       // float  @ 00D8     0.0
  char   unk_4D8410_00DC[28];
  double double_0000F8;               // double @ 00F8     0.017453290000000000
  double d_0_5;                       // double @ 0100     0.5
  double fOneOver2048;                // double @ 0108     1 / 2048
  char   unk_4D8410_0110[24];
  double d_213_3_4;                   // double @ 0128     213.33333333333334
  char   unk_4D8410_0130[8];
  double d_neg_0_80_4;                // double @ 0138     -0.80000000000000004
  char   unk_4D8410_0140[8];
  double d_407_19_9;                  // double @ 0148      407.19999999999999
  char   unk_4D8410_0150[16];
  double d_0_59_8;                    // double @ 0160     0.59999999999999998
  char   unk_4D8410_0168[8];
  double d_1_div_100;                 // double @ 0170     1 / 100
  double dPi;                         // double @ 0178     ï (3.1415926535897931)
  char   unk_4D8410_0180[32];
  double fTwo;                        // double @ 01A0     2.0
  char   unk_4D8410_01A8[32];
  double d_42_6_4;                    // double @ 01C8     42.666666666666664
  double d_0_25;                      // double @ 01D0     0.25
  char   unk_4D8410_01D8[88];
  double d_65536_0;                   // double @ 0230     65536.0
  char   unk_4D8410_0238[72];
  double d_0_3_1;                     // double @ 0280     0.33333333333333331
  char   unk_4D8410_0288[8];
  double d_1_div_1024;                // double @ 0290     1 / 1024
  char   unk_4D8410_0298[104];
  double d_1_6_7;                     // double @ 0300     1.(6)7
  char   unk_4D8410_0308[64];
  double d_1_div_65536;               // double @ 0348     1 / 65536
  char   unk_4D8410_0350[24];
  double d_0_64577174186706543;       // double @ 0368     0.64577174186706543
  char   unk_4D8410_0370[8];
  double d_neg_16192_0;               // double @ 0378     -16192.0
  double d_16192_0;                   // double @ 0380     16192.0
  char   unk_4D8410_0388[40];
  double d_12288_0;                   // double @ 03B0     12288.0
  char   unk_4D8410_03B8[40];
  double d_52428_80_3;                // double @ 03E0     52428.800000000003
  char   unk_4D8410_03E8[16];
  double d_20_0;                      // double @ 03F8     20.0
  double d_1_div_480;                 // double @ 0400     1 / 480
  char   unk_4D8410_0408[16];
  double d_0_83870967741935487;       // double @ 0418     0.83870967741935487
  double d_0_80_4;                    // double @ 0420     0.80000000000000004
  double d_0_70343392299687835;       // double @ 0428     0.70343392299687835
  double d_62_0;                      // double @ 0430     62.0
  double d_31_0;                      // double @ 0438     31.0
  double d_1_div_31;                  // double @ 0440     1 / 31
  char   unk_4D8410_0448[8];
  double d_1_div_255;                 // double @ 0450     1 / 255
  char   unk_4D8410_0458[8];
  double d_1_div_60;                  // double @ 0460     1 / 60
  char   unk_4D8410_0468[96];
  double d_4_0;                       // double @ 04C8     4.0
  double d_1_3_3;                     // double @ 04D0     1.3333333333333333
  char   unk_4D8410_04D8[8];
  double d_50_0;                      // double @ 04E0     50.0
  double d_150_0;                     // double @ 04E8     150.0
  double d_200_0;                     // double @ 04F0     200.0
  double d_400_0;                     // double @ 04F8     400.0
  double d_40_0;                      // double @ 0500     40.0
  char   unk_4D8410_0508[8];
  double d_350_0;                     // double @ 0510     350.0
  double d_800_0;                     // double @ 0518     800.0
  char   unk_4D8410_0520[8];
  double f10_0;                       // double @ 0528     10.0
  double f0_9;                        // double @ 0530     0.93.1415926
  char   unk_4D8410_0538[16];
  double d_100_0;                     // double @ 0548     100.0
  double d_1_div_8192;                // double @ 0550     1 / 8192
  char   unk_4D8410_0558[32];
  double d_45875_19_7;                // double @ 0578     45875.199999999997
  double d_26214_40_1;                // double @ 0580     26214.400000000001
  double d_655_360_1;                 // double @ 0588     655.36000000000001
  char   unk_4D8410_0590[8];
  double dPi_7digits;                 // double @ 0598     3.1415926
  char   unk_4D8410_05A0[8];
  double d_1_5;                       // double @ 05A8     1.5
  char   unk_4D8410_05B0[8];
  double d_1_div_int_max;             // double @ 05B8     1 / 0xFFFFFFFF
  double d_5115_0;                    // double @ 05C0     5115.0
  double d_2111111111_0;              // double @ 05C8     2111111111.0
  double d_1776_0;                    // double @ 05D0     1776.0
  double d_1492_0;                    // double @ 05D8     1492.0
  char   unk_4D8410_05E0[3480];
  GUID   IID_IDirectDraw2;            // struct @ 1378     IID_IDirectDraw2
  GUID   IID_IDirectDraw4;            // struct @ 1388     IID_IDirectDraw4
  char   unk_4D8410_1398[208];
  GUID   IID_IDirectDrawGammaControl; // struct @ 1468     IID_IDirectDrawGammaControl
  char   unk_4D8410_1478[560];
  GUID   IID_IDirect3D3;              // struct @ 16A8     IID_IDirect3D3
  char   unk_4D8410_16B8[160];
  GUID   IID_IDirect3DTexture2;       // struct @ 1758     IID_IDirect3DTexture2
  char   unk_4D8410_1768[11420];
 };
} memory_4D8410;

extern unsigned char *byte_4D8410;
extern unsigned char memory_4F2688[];

extern unsigned char *aNPCProfessionNames[];
extern unsigned char *aAMPMNames[];
extern unsigned char *aMoonPhaseNames[];
extern unsigned char *aSpellNames[];
extern unsigned char *aCharacterConditionNames[];
extern unsigned char *aSkillNames[];
extern unsigned char *aClassNames[];
extern unsigned char *aMonthNames[];
extern unsigned char *aDayNames[];
extern unsigned char *aSpellSchoolNames[];
extern unsigned char *aAttributeNames[];
extern unsigned char *pGlobalTXT_LocalizationStrings[];

extern unsigned char *pClassDescriptions[];

extern unsigned char *pHealthPointsAttributeDescription;
extern unsigned char *pSpellPointsAttributeDescription;
extern unsigned char *pArmourClassAttributeDescription;
extern unsigned char *pPlayerConditionAttributeDescription;
extern unsigned char *pFastSpellAttributeDescription;
extern unsigned char *pPlayerAgeAttributeDescription;
extern unsigned char *pPlayerLevelAttributeDescription;
extern unsigned char *pPlayerExperienceAttributeDescription;
extern unsigned char *pAttackBonusAttributeDescription;
extern unsigned char *pAttackDamageAttributeDescription;
extern unsigned char *pMissleBonusAttributeDescription;
extern unsigned char *pMissleDamageAttributeDescription;
extern unsigned char *pFireResistanceAttributeDescription;
extern unsigned char *pAirResistanceAttributeDescription;
extern unsigned char *pWaterResistanceAttributeDescription;
extern unsigned char *pEarthResistanceAttributeDescription;
extern unsigned char *pMindResistanceAttributeDescription;
extern unsigned char *pBodyResistanceAttributeDescription;
extern unsigned char *pSkillPointsAttributeDescription;

extern PCMWAVEFORMAT sPCMWaveFormat;



extern struct BaseRender *pD3DRenderer;
extern class LODFile_IB      LODFile_Icons_LOD;
extern class LODFile_IB      LODFile_Events_LOD;
extern class LODFile_IB      LODFile_Bitmaps_LOD;
extern class LODFile_Sprite      LODFile_Sprites_LOD;
extern struct AudioPlayer  *pAudioPlayer;
extern struct CVideoPlayer *pVideoPlayer;

extern class cPCXTexture      Class33_global0;
extern class cPCXTexture      Class33_global1;
extern class cPCXTexture      Class33_global3;

extern struct CTextureFrameTable *pTextureFrameTable;
extern struct SpriteFrameTable  *pSpriteFrameTable;

extern struct class59 *pClass59_global;


extern unsigned char TmpBuf[];
extern unsigned char pStringBuffer[];


//extern unsigned char GameCDDriveLetter;
extern wchar_t GameCDDriveLetter;


extern struct Edge *pNewEdgesBuf;
extern struct Surf *pSurfsBuf;
extern struct Edge *pEdgesBuf;
extern struct Span *pSpansBuf;



extern unsigned int uTextureID_PlayerCreationUI_BtnLeft;
extern unsigned int uTextureID_PlayerCreationUI_BtnRight;
extern unsigned int uTextureID_PlayerCreationUI_BtnMinus;
extern unsigned int uTextureID_PlayerCreationUI_BtnPlus;

extern struct GUIWindow *pGUIWindow_CurrentMenu;

extern unsigned int uTextureIdx_BtnEsc2;
extern unsigned int uTextureIdx_BtnXxU;
extern unsigned int uTextureIdx_BtnMake2;

extern unsigned int uTextureIdx_BtnMake;
extern unsigned int uTextureIdx_BtnYes2;
extern unsigned int uTextureIdx_BtnXokU;

extern struct GUIButton *pPlayerCreationUI_BtnReset;
extern struct GUIButton *pPlayerCreationUI_BtnOK;

extern struct GUIButton *pPlayerCreationUI_BtnPlus;
extern struct GUIButton *pPlayerCreationUI_BtnMinus;
extern class cTexture *pPlayerCreationUI_Sky;
extern class cTexture *pPlayerCreationUI_Top;

extern class Clock cClock2;  //struct class24 *cClock2
extern class Clock cClock1;

extern unsigned int uPlayerCreationUI_SelectedCharacter;

extern unsigned int uTextureID_PlayerCreationUI_FaceMask;

extern struct CMapStats     *pMapStats;
extern struct CSpellStats   *pSpellStats;
extern struct CMonsterStats *pMonsterStats;

extern struct COverlayDescriptionList    *pOverlayDescriptionList;
extern struct CObjectDescriptionList     *pObjectDescriptionList;
extern struct DecorationDescriptionList *pDecorationDescriptionList;

extern struct RenderVertex array_73D150[];

//extern struct CIconFrameTable *pIconFrameTable;
extern ImageTable<IconFrame> *pIconFrameTable;

extern struct Font *pFontArrus;
extern struct Font *pFontLucida;

extern struct Font *pFontCreate;
extern struct Font *pFontCChar;
extern struct Font *pFontComic;
extern struct Font *pFontSmallnum;




int __fastcall ReadWindowsRegistryString(const char *pKeyName, unsigned char *pOut, unsigned int uBufLen, const unsigned char *pDefaultValue);
int __fastcall ReadWindowsRegistry(const char *pKeyName, int iDefaultValue);
LSTATUS __stdcall sub_4ABC9B(char a1);


void *__stdcall call_new(int, int, int);
//int             free(void *ptr);