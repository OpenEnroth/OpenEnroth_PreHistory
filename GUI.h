#pragma once
#pragma pack(push, 1)

#include "defs.h"

#include "RenderD3D3.h"

#define MENU_MAIN        0
#define MENU_CREATEPARTY 6


struct GUIMessageQueue
{
 int dword_000000;
 int dword_000004;
 int dword_000008;
 int dword_00000C;
};

//void __thiscall sub_4356B9(int this, int a2, int a3, int a4);
bool GUIMessageQueue_GetMessage(struct GUIMessageQueue *_this, int *a2, int *a3, int *a4);



struct GUIWindow
{
 unsigned int uFrameX;      // dword @ 000000
 unsigned int uFrameY;      // dword @ 000004
 unsigned int uFrameWidth;  // dword @ 000008
 unsigned int uFrameHeight; // dword @ 00000C
 unsigned int uFrameZ;      // dword @ 000010
 unsigned int uFrameW;      // dword @ 000014
 unsigned int bSlotUsed;    // dword @ 000018

 int dword_00001C; // looks like pointer to GUIButton, but not always
 unsigned int uNumControls; // dword @ 000020
 int dword_000024;
 int dword_000028;
 int dword_00002C; //looks like focus control id
 int dword_000030;
 int dword_000034;
 int dword_000038;
 int dword_00003C;
 int dword_000040;
 int dword_000044;
 int dword_000048;
 struct GUIButton *pControlsHead; // ptr @ 00004C
 struct GUIButton *pControlsTail; // ptr @ 000050
};
//sizeof == 0x54


struct GUIButton
{
 unsigned int uX;      // dword @ 000000
 unsigned int uY;      // dword @ 000004
 unsigned int uWidth;  // dword @ 000008
 unsigned int uHeight; // dword @ 00000C
 unsigned int uZ;      // dword @ 000010
 unsigned int uW;      // dword @ 000014
 int dword_000018;
 int dword_00001C;
 int dword_000020;
 int dword_000024;
 int dword_000028;
 int dword_00002C;
 struct GUIButton *pPrev;         // ptr   @ 000030
 struct GUIButton *pNext;         // ptr   @ 000034
 struct GUIWindow *pParentWindow; // ptr   @ 000038
 unsigned int      uTextureID;    // dword @ 00003C
 int dword_000040;
 int dword_000044;
 int dword_000048;
 int dword_00004C;
 int dword_000050;
// int dword_000054;
 unsigned char byte_000054;
 unsigned char pButtonName[3]; // byte[?] @ 000055
 int dword_000058;
 int dword_00005C;
 int dword_000060;
 int dword_000064;
 int dword_000068;
 int dword_00006C;
 int dword_000070;
 int dword_000074;
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
 int dword_0000A4;
 int dword_0000A8;
 int dword_0000AC;
 int dword_0000B0;
 int dword_0000B4;
 int dword_0000B8;
};
//sizeof == BC



struct Font
{
 unsigned char   uFirstChar;           // byte  @ 000000
 unsigned char   uLastChar;            // byte  @ 000001
 char            byte_000002[2];
 unsigned char   byte_000004;
 unsigned char   uFontHeight;          // byte  @ 000005
 char            byte_000006[2];
 int             dword_000008;
 unsigned short *pFontPalette;         // dword @ 00000C
 int             dword_000010[4];
 int             dword_000020[256][3];
 int             array_000C20[256];
 char            unk_001020;
};


//LoadingUI
struct class56
{
 unsigned short    uX;               // word @ 000000
 unsigned short    uY;               // word @ 000002
 unsigned short    uWidth;           // word @ 000004
 unsigned short    uHeight;          // word @ 000006
 char              byte_000008;
 char              byte_000009;
 unsigned char     uProgressMax;     // byte @ 00000A
 unsigned char     uProgressCurrent; // byte @ 00000B
 int               uProgressBarType; // dword @ 00000C   loading screen, small loading window or whatever to render
 char              array_000010[8];
 struct RGBTexture loading;          // struct @ 000018
 char              byte_000040[304];
 struct RGBTexture loadprog;         // struct @ 000170

 unsigned int _addon_loadprog_id_in_Icons_LOD;
 unsigned int uTextureID_Loading;
};
//sizeof ~ 198




struct GUIWindow *__fastcall GUIWindowCreate(unsigned int uFrameX, unsigned int uFrameY,
                                             unsigned int uFrameWidth, unsigned int uFrameHeight,
                                             signed int a5, int a6, int a7);

struct GUIButton *__fastcall GUIButtonCreate(struct GUIWindow *pParentWindow,
                                             unsigned int uX, unsigned int uY,
                                             unsigned int uWidth, unsigned int uHeight,
                                             int a6, int a7, int a8, int a9, char a10, const char *pName, unsigned int uTextureID);

void GUIWindowDelete(struct GUIWindow *);

//int __thiscall sub_41CD3B(int this, int a2);
struct GUIButton *GUIWindow_GetChild(struct GUIWindow *_this, int uID);

int __fastcall AlignText_Center(int a1, const char *a2, int a3);
unsigned char *__fastcall FitTextInAWindow(const char *pString, struct Font *pFont, struct GUIWindow *pParent, unsigned char uX, int a5);
void FontDrawText(struct GUIWindow *_this, struct Font *pFont, unsigned int uX, unsigned int uY, const char *pString, unsigned int uTextMainColor, signed int a8, unsigned int uTextShadowColor);

void __fastcall DrawWindow(unsigned int uWindowX, unsigned int uWindowY, unsigned int uWindowWidth, unsigned int uWindowHeight);


struct Font *__cdecl sub_44C448(const char *pFontName, const char *pFontPalette);
int __fastcall sub_44C51E(unsigned char *pFontData, const char *pString);

//int __cdecl sub_49750E();
void __cdecl DeleteFontCChar();


extern unsigned int uTextureID_CurrentMenu;

void LoadMainMenu();

extern unsigned int uTextureID_MainMenuUI_Title;



void SetupUserInterface(unsigned int uPartyAlignment);

void __cdecl PlayerCreationUI_Initialize();
unsigned int PlayerCreationUI_GetStatColor(struct Player *_this, int Stat);
__int16 __thiscall PartyCreation_BtnMinusClick(struct Player *_this, int a2);
signed int __thiscall PartyCreation_BtnPlusClick(struct Player *_this, int a2);
void PlayerCreationUI_Draw();

extern unsigned int uTextureID_PartyCreationUI_ClassIcons;
extern unsigned int uTextureID_PartyCreationUI_Arrows;


bool LevelLoadingUI_Initialize(struct class56 *_this, int a2);
void LevelLoadingUI_UpdateAndDrawProgressBar(struct class56 *_this);
void DrawLoadingScreen(struct class56 *_this);
void LevelLoadingUI_Reset(struct class56 *_this, char a2);
void LevelLoadingUI_Release(struct class56 *_this);

void __cdecl GameUI_DrawStatusBar();
void GameUI_DrawFrames();
void __cdecl GameUI_DrawFoodAndGold();
void __cdecl GameUI_DrawPartySpells();
void GameUI_DrawPortraits(void *this);
void GameUI_DrawCharacterSelectionFrame();
void GameUI_DrawMinimap(unsigned int uX, unsigned int uY, unsigned int uZ, unsigned int uW, unsigned int uMinimapZoom);
void GameUI_DrawTorchlightAndWizardEye();
void GameUI_DrawLifeManaBars();
void GameUI_Update();
void GameUI_Process();
void GameUI_OnPlayerPortraitLeftClick(unsigned int uCharacterCLicked);
int GameUI_LoadPaperdollTextures();
void __fastcall GameUI_DrawPaperdoll(unsigned int uSelectedCharacter);
void __fastcall GameUI_DrawPaperdoll2(int a1);

extern unsigned int uTextureID_GameUI_StatusBar;
extern unsigned int uTextureID_GameUI_ViewportTop;
extern unsigned int uTextureID_GameUI_ViewportLeft;
extern unsigned int uTextureID_GameUI_RightPanel;
extern unsigned int uTextureID_GameUI_PartyFrame;


struct GUIWindow *GameUI_InitializeCharacterWindow(int a1);

void __cdecl GameUI_SkillsTab_ShowHint();
void GameUI_DrawSkillsTab(int a1);

void __cdecl GameUI_StatsTab_ShowHint();
void GameUI_DrawStatsTab(unsigned int uSelectedCharacter);

int __fastcall GameUI_DrawAwardsTab(int a1);
void __fastcall GameUI_DrawInventory(unsigned int uSelectedCharacter, char a2);

#pragma pack(pop)