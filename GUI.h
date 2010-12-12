#pragma once

#include "defs.h"

#define MENU_MAIN        0
#define MENU_NEWGAME     1
#define MENU_CREDITS     2
#define MENU_LOAD        3
#define MENU_CREATEPARTY 6

#pragma pack(push, 1)



/*
struct GUIMessageQueue
{
 int dword_000000;
 int dword_000004;
 int dword_000008;
 int dword_00000C;
};	*/
struct Msg_param
	{
	 int msg_param1;
	 int msg_param2;
	 int msg_param3;
	};


class GUIMessageQueue
{
public:
 int msg_count;
 Msg_param prm[40];
//void __thiscall sub_4356B9(int _this, int a2, int a3, int a4);
bool GetQueueMessage(unsigned int *param1, int *param2, int *param3);
void PutMessageToQueue(unsigned int param1, int param2, int param3);	  //sub_42EB8D
void CutQueueTail();
};	//sizeof ==	1E4

extern class GUIMessageQueue dword_50C9E8; // 1 + 40*3
//int dword_50C9EC[]; // weak
//int dword_50C9F0[array_size_unknown]; // weak

extern class GUIMessageQueue dword_50CBD0; // 404 for action[def:space] key
//extern int dword_50CBD4; // weak; // weak
//int dword_50CBD8[array_size_unknown]; // weak
//int dword_50CBDC; // weak	 param 3!!!


struct GUIWindow
{
 unsigned int uFrameX;      // dword @ 000000
 unsigned int uFrameY;      // dword @ 000004
 unsigned int uFrameWidth;  // dword @ 000008
 unsigned int uFrameHeight; // dword @ 00000C
 unsigned int uFrameZ;      // dword @ 000010
 unsigned int uFrameW;      // dword @ 000014
 unsigned int uWindowType;    // dword @ 000018
 union 
	 {
 struct GUIButton* ptr_00001C; // looks like pointer to GUIButton, but not always;  maybe UserData
   int dword_00001C; // looks like pointer to GUIButton, but not always;  maybe UserData
	 };
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
 unsigned char    *ptr_000048; // some string ptr
 struct GUIButton *pControlsHead; // ptr @ 00004C
 struct GUIButton *pControlsTail; // ptr @ 000050
};
//sizeof = 54




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
 class cTexture   *pTexture[5];    // dword @ 00003C
// class cTexture   *pTexture2; //int dword_000040;
 //class cTexture   *pTexture3; // int dword_000044;
 //class cTexture   *pTexture4; //int dword_000048;
 //class cTexture   *pTexture5; //int dword_00004C;
 unsigned int uTexturesCount;// dword_000050;
// int dword_000054;
 unsigned char uHotkey; // byte @ 000054   hotkey shortcut
 unsigned char pButtonName[103]; // byte[?] @ 000055
/* int dword_000058;
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
 int dword_0000B8; */
};
//sizeof == BC




//LoadingUI
struct class56
{
 unsigned short     uX;               // word @ 000000
 unsigned short     uY;               // word @ 000002
 unsigned short     uWidth;           // word @ 000004
 unsigned short     uHeight;          // word @ 000006
 char               byte_000008;
 char               byte_000009;
 unsigned char      uProgressMax;     // byte @ 00000A
 unsigned char      uProgressCurrent; // byte @ 00000B
 int                uProgressBarType; // dword @ 00000C   loading screen, small loading window or whatever to render
 char               array_000010[8];
 class cPCXTexture *loading;          // struct @ 000018
 char               byte_000040[304];			   //158
 class cTexture    *loadprog;         // struct @ 000170

 unsigned int _addon_loadprog_id_in_Icons_LOD;
#ifndef OLD_CODE
 unsigned int uTextureID_Loading;
#endif

};
//sizeof ~ 198



void SetCurrentMenu(unsigned int uMenuID);



struct GUIWindow * GUIWindowCreate(unsigned int uFrameX, unsigned int uFrameY,
                                             unsigned int uFrameWidth, unsigned int uFrameHeight,
                                             unsigned int uWindowType, struct GUIButton *a6, int a7);

struct GUIButton*  GUIButtonCreate(struct GUIWindow *pParentWindow,
                                             unsigned int uX, unsigned int uY,
                                             unsigned int uWidth, unsigned int uHeight,
                                             int a6, int a7, unsigned int uControlID, int a9, unsigned int uHotkey, const unsigned char *pName,class cTexture* pButtnTexture1,  
											 class cTexture* pButtnTexture2=NULL);	 //was multiparametr function!!

void GUIWindowDelete(struct GUIWindow *);
void GUIWindow_sub_459C2B(struct GUIWindow *a1, signed int a2, int a3, int a4);

//int __thiscall sub_41CD3B(int _this, int a2);
struct GUIButton *GUIWindow_GetChild(struct GUIWindow *_this, int uID);

void __fastcall DrawWindow(unsigned int uWindowX, unsigned int uWindowY, unsigned int uWindowWidth, unsigned int uWindowHeight);

int __thiscall sub_4219BE(void *_this);




extern unsigned int uTextureIdx_MapDirs[8];  
extern unsigned int uTextureID_CurrentMenu;
extern class cPCXTexture  cPCXID_CurrentMenu;

void LoadMainMenu();

extern unsigned int uTextureID_MainMenuUI_Title;
extern class cPCXTexture  cPCXID_GameUI_StatusBar;


void MenuUI_LoadTextures(unsigned int uPartyAlignment);

void __cdecl PlayerCreationUI_Initialize();
unsigned int PlayerCreationUI_GetStatColor(struct Player *_this, int Stat);
__int16 __thiscall PartyCreation_BtnMinusClick(struct Player *_this, int a2);
signed int __thiscall PartyCreation_BtnPlusClick(struct Player *_this, int a2);
void PlayerCreationUI_Draw();

extern unsigned int uTextureID_PartyCreationUI_ClassIcons;
extern unsigned int uTextureID_PartyCreationUI_Arrows;


bool LevelLoadingUI_Initialize(struct class56 *_this, unsigned int uProgressBarType);
void LevelLoadingUI_UpdateAndDrawProgressBar(struct class56 *_this);
void DrawLoadingScreen(struct class56 *_this);
void LevelLoadingUI_Reset(struct class56 *_this, char a2);
void LevelLoadingUI_Release(struct class56 *_this);

void __cdecl GameUI_DrawStatusBar();
void GameUI_DrawFrames();
void __cdecl GameUI_DrawFoodAndGold();
void __cdecl GameUI_DrawPartySpells();
void GameUI_DrawPortraits(void *_this);
void GameUI_DrawCharacterSelectionFrame();
void GameUI_DrawMinimap(unsigned int uX, unsigned int uY, unsigned int uZ, unsigned int uW, unsigned int uMinimapZoom);
void GameUI_DrawTorchlightAndWizardEye();
void GameUI_DrawLifeManaBars();
void GameUI_Update();
void GameUI_Process();
void GameUI_OnPlayerPortraitLeftClick(unsigned int uCharacterCLicked);

extern unsigned int uTextureID_GameUI_StatusBar;
extern unsigned int uTextureID_GameUI_ViewportTop;
extern unsigned int uTextureID_GameUI_ViewportLeft;
extern unsigned int uTextureID_GameUI_RightPanel;
extern unsigned int uTextureID_GameUI_PartyFrame;


struct GUIWindow *GameUI_InitializeCharacterWindow(int a1);

void __cdecl CharacterUI_SkillsTab_ShowHint();
void CharacterUI_DrawSkillsTab(int uSelectedCharacter);
void __cdecl CharacterUI_StatsTab_ShowHint();
void CharacterUI_DrawStatsTab(unsigned int uSelectedCharacter);
int __fastcall CharacterUI_DrawAwardsTab(int a1);
void __fastcall CharacterUI_DrawInventoryTab(unsigned int uSelectedCharacter, bool a2);
void CharacterUI_DoDrawCharacterScreen(unsigned int uActiveCharacter);
int CharacterUI_LoadPaperdollTextures();
void __fastcall CharacterUI_DrawPaperdoll(unsigned int uSelectedCharacter);
void __fastcall CharacterUI_DrawPaperdoll2(int a1);

char *__cdecl sub_411150();
int __thiscall GUIWindow_sub_411BFC(GUIWindow *_this);
void GUIButton_sub_415180(struct GUIButton *a1, const unsigned char *a2, struct Font *a3, __int16 a4, char *a5);
char *__cdecl CreateCopyrightWindow();
void GUIWindow_sub_415551(GUIWindow *_this, int a2);
void __cdecl sub_4156F0_LooksLike_UI_ProcessCallbacks();

void sub_491DE7(int a1, int a2);

#pragma pack(pop)