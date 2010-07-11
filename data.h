#pragma once
#include <windows.h>

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
  double f1_0;                        // double @ 0018     1.0
  char   unk_4D8410_0020[120];
  float  fOne;                        // float  @ 0098     1.0
  char   unk_4D8410_009C[28];
  double f0_01;                       // double @ 00B8     0.01
  char   unk_4D8410_00C0[24];
  float  fZero;                       // float  @ 00D8     0.0
  char   unk_4D8410_00DC[28];
  double double_0000F8;               // double @ 00F8     0.017453290000000000
  double d_0_5;                       // double @ 0100     0.5
  double fOneOver2048;                // double @ 0108     1 / 2048
  char   unk_4D8410_0110[104];
  double dPi;                         // double @ 0178     ï (3.1415926535897931)
  char   unk_4D8410_0180[32];
  double fTwo;                        // double @ 01A0     2.0
  char   unk_4D8410_01A8[896];
  double f10_0;                       // double @ 0528     10.0
  double f0_9;                        // double @ 0530     0.9
  char   unk_4D8410_0538[3648];
  GUID   IID_IDirectDraw2;            // struct @ 1378     IID_IDirectDraw2
  GUID   IID_IDirectDraw4;            // struct @ 1388     IID_IDirectDraw4
  char   unk_4D8410_1398[208];
  GUID   IID_IDirectDrawGammaControl; // struct @ 1468     IID_IDirectDrawGammaControl
  char   unk_4D8410_1478[560];
  GUID   IID_IDirect3D3;              // struct @ 16A8     IID_IDirect3D3
  char   unk_4D8410_16B8[11596];
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



extern struct CD3DRenderer *pD3DRenderer;
extern struct class17      *pClass17_Icons_LOD;
extern struct class17      *pClass17_Events_LOD;
extern struct class17      *pClass17_Bitmaps_LOD;
extern struct class17      *pClass17_Sprites_LOD;
extern struct AudioPlayer  *pAudioPlayer;
extern struct CVideoPlayer *pVideoPlayer;

extern struct RGBTexture      *pClass33_global0;
extern struct RGBTexture      *pClass33_global1;
extern struct RGBTexture      *pClass33_global3;

extern struct CTextureFrameTable *pTextureFrameTable;
extern struct CSpriteFrameTable  *pSpriteFrameTable;

extern struct class59 *pClass59_global;

extern char class23_instance[];


extern char TmpBuf[];
extern unsigned char pStringBuffer[];


extern unsigned char cGameCDDriveLetter;


extern struct Edge *pNewEdgesBuf;
extern struct Surf *pSurfsBuf;
extern struct Edge *pEdgesBuf;
extern struct Span *pSpansBuf;



extern unsigned int uTextureID_PlayerCreationUI_BtnLeft;
extern unsigned int uTextureID_PlayerCreationUI_BtnRight;
extern unsigned int uTextureID_PlayerCreationUI_BtnMinus;
extern unsigned int uTextureID_PlayerCreationUI_BtnPlus;

extern struct GUIWindow *pGUIWindow_PlayerCreation;

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
extern struct class18 *pPlayerCreationUI_Sky;
extern struct class18 *pPlayerCreationUI_Top;

extern struct class24 *pClass24_global2;

extern unsigned int uPlayerCreationUI_SelectedCharacter;

extern unsigned int uTextureID_PlayerCreationUI_FaceMask;

extern struct CMapStats     *pMapStats;
extern struct CSpellStats   *pSpellStats;
extern struct CMonsterStats *pMonsterStats;

extern struct COverlayDescriptionList    *pOverlayDescriptionList;
extern struct CObjectDescriptionList     *pObjectDescriptionList;
extern struct CDecorationDescriptionList *pDecorationDescriptionList;

extern struct struct14 array_73D150[];

extern struct CIconFrameTable *pIconFrameTable;

extern struct Font *pFontArrus;
extern struct Font *pFontLucida;

extern struct Font *pFontCreate;
extern struct Font *pFontCChar;
extern struct Font *pFontComic;
extern struct Font *pFontSmallnum;




int __fastcall ReadWindowsRegistry(const char *pKeyName, int iDefaultValue);
LSTATUS __stdcall sub_4ABC9B(char a1);


void *__stdcall call_new(int, int, int);
int             call_delete(int result, unsigned int a2);