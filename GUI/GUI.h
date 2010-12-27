#pragma once
#include "GUIImage.h"
#include "GUIWindow.h"
#include "GUICursor.h"
#include "GUIProgressBar.h"
#include "GUIButton.h"

#include "..\defs.h"
#include "..\Extras\List.h"

#define MENU_MAIN        0
#define MENU_NEWGAME     1
#define MENU_CREDITS     2
#define MENU_LOAD        3
#define MENU_CREATEPARTY 6


#define MESSAGE_ATTACK                 0x17

#define MESSAGE_CAST_QUICKSPELL        0x19

#define MESSAGE_OPEN_REST_DIALOG       0x68
#define MESSAGE_OPEN_SPELLBOOK         0x69
#define MESSAGE_OPEN_QUICKREFERENCE    0x6A

#define MESSAGE_START_NPC_DIALOGUE     0xA1

#define MESSAGE_PROBABLY_CHARCYCLE     0xB0

#define MESSAGE_OPEN_QUESTBOOK         0xC8
#define MESSAGE_OPEN_AUTONOTES         0xC9
#define MESSAGE_OPEN_MAP_DIALOGUE      0xCA
#define MESSAGE_OPEN_DATETIME_DIALOGUE 0xCB

#define MESSAGE_MINIMAP_ZOOM_IN        0x16F
#define MESSAGE_MINIMAP_ZOOM_OUT       0x170

#define MESSAGE_INTERACT               0x194





class GUI
{
 public:
   virtual Result::Code Update(float dt)
   {
    return Result::Success;
   }

   virtual Result::Code Draw(float dt)
   {
    for (List<GUIControl *>::NodeType *pNode = cChildren.First(); pNode; pNode = pNode->pNext)
      pNode->pData->OnDraw(dt);

    return Result::Success;
   }


   virtual Result::Code Reset()
   {
    cChildren.Clear();
    cDrawList.Clear();
    return Result::Success;
   }

   template<typename tControl>
     tControl *CreateControl(GUIControl *pParent)
   {
    tControl *pNewControl = MemAlloc(tControl, 1);

    pNewControl->pHostInterface = this;
    pNewControl->pParent = pParent;
    if (pParent)
      pParent->AddChild(pNewControl);

    return pNewControl;
   }

   List<GUIControl *> *GetChildrenList()
   {
    return &cChildren;
   }

 protected:
   List<GUIControl *> cChildren;
   List<GUIControl *> cDrawList;
};









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













void SetCurrentMenu(unsigned int uMenuID);



class GUIWindow * GUIWindowCreate(unsigned int uFrameX, unsigned int uFrameY,
                                             unsigned int uFrameWidth, unsigned int uFrameHeight,
                                             unsigned int uWindowType, struct GUIButton *a6, int a7);

struct GUIButton*  GUIButtonCreate(class GUIWindow *pParentWindow,
                                             unsigned int uX, unsigned int uY,
                                             unsigned int uWidth, unsigned int uHeight,
                                             int a6, int a7, unsigned int uControlID, unsigned int uControlParam,
                                             unsigned int uHotkey, const unsigned char *pName,class cTexture* pButtnTexture1,  
											 class cTexture* pButtnTexture2=NULL);	 //was multiparametr function!!

void GUIWindowDelete(class GUIWindow *);
void GUIWindow_sub_459C2B(class GUIWindow *a1, signed int a2, int a3, int a4);

//int __thiscall sub_41CD3B(int _this, int a2);
struct GUIButton *GUIWindow_GetChild(GUIWindow *_this, int uID);

void __fastcall DrawWindow(unsigned int uWindowX, unsigned int uWindowY, unsigned int uWindowWidth, unsigned int uWindowHeight);

int __thiscall sub_4219BE(void *_this);




extern unsigned int uTextureIdx_MapDirs[8];  
extern unsigned int uTextureID_CurrentMenu;
extern class cPCXTexture  cPCXID_CurrentMenu;

void ShowIntroVideo_LoadMainMenu_ShowGreetingWindow();

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


GUIWindow *GameUI_InitializeCharacterWindow(int a1);

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

void __cdecl sub_411150();
void __cdecl sub_4156F0_LooksLike_UI_ProcessCallbacks();

void sub_491DE7(int a1, int a2);


unsigned char *__fastcall sub_495461_DrawAn_AreYouSureWishTo_Join_Dismiss_ThisNPC_Dialogue(unsigned char *lpsz, unsigned __int8 a2, int a3, int a4, int a5, __int64 *a6);