#include "GUI.h"

#include "defs.h"
#include "localization_defs.h"
#include <strsafe.h>
#include "font.h"
#include "clock.h"
#include "menus.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "RenderD3D3.h"

#include "data.h"

#include "FrameTables.h"
#include "_audio.h"
#include "_video.h"
 #include "_lod.h"

unsigned int uTextureID_CurrentMenu;

unsigned int uTextureIdx_MapDirs[8];     // dword[8] @ MM7.exe::00507994

unsigned int uTextureID_MainMenuUI_Title;

unsigned int uTextureID_PartyCreationUI_ClassIcons;
unsigned int uTextureID_PartyCreationUI_Arrows;

unsigned int uTextureID_GameUI_StatusBar;
unsigned int uTextureID_GameUI_ViewportTop;
unsigned int uTextureID_GameUI_ViewportLeft;
unsigned int uTextureID_GameUI_RightPanel;
unsigned int uTextureID_GameUI_PartyFrame;

class cTexture *pTextureIdx_PlayerFaces[4][56]; // dword[224] @ MM7.exe::00A74CF0

class cTexture *pPlayerCreationUI_ArrowR[20] = {0}; // ptr[19] @ MM7.exe::0050787C
class cTexture *pPlayerCreationUI_ArrowL[20] = {0}; // ptr[19] @ MM7.exe::005078CC

class cTexture *pPlayerCreatUI_ClIcons[9] = {0};   // ptr[9]  @ MM7.exe::00507760
class cTexture *pPlayerCreationUI_Sky = 0;               // ptr     @ MM7.exe::00507784
class cTexture *pPlayerCreationUI_Top = 0;               // ptr     @ MM7.exe::00507788
class cTexture *pTextureID_PCFaces[25];

class cPCXTexture  cPCXID_GameUI_StatusBar;
class cPCXTexture  cPCXID_GameUI_ViewportTop;
class cPCXTexture  cPCXID_GameUI_ViewportLeft;
class cPCXTexture  cPCXID_GameUI_RightPanel;
class cPCXTexture  cPCXID_GameUI_PartyFrame;

class cPCXTexture  cPCXID_MainMenuUI_Title;
class cPCXTexture  cPCXID_CurrentMenu;

unsigned int uTextureID_GameUI_MagnifyingGlass;         // dword @ MM7.exe::005118CC
unsigned int uTextureID_GameUI_PaperdollBackground;     // dword @ MM7.exe::005118D8
unsigned int uTextureID_GameUI_PaperdollJewelryOverlay; // dword @ MM7.exe::005118DC
 int dword_5118E0; // weak

 char *portret_names[25] =
	{ "pc01-", "pc02","pc03","pc04","pc05-","pc06","pc07","pc08","pc09-","pc10","pc11-","pc12","pc13",
	   "pc14", "pc15","pc16","pc17-","pc18","pc19","pc20","pc21-","pc22-","pc23","pc24-","pc25-"
	};

class GUIMessageQueue dword_50C9E8; // 1 + 40*3 [1 + 120]	  second

class GUIMessageQueue dword_50CBD0; // weak	 [array_size_unknown]  main


 //----- (00491DE7) --------.text:0049391C ------------------------------------------------
void sub_491DE7(int a1, int a2)
{
for(int i=a1; i< 56; i++)
	{
	wsprintfA((char *)TmpBuf, "%s%02d", portret_names[a2], i);
	LODFile_Icons_LOD.ReLoadTexture(pTextureIdx_PlayerFaces[a2][i], (char *)TmpBuf, 2);
	}
}

//----- (00421626) --------------------------------------------------------
struct GUIWindow *GameUI_InitializeCharacterWindow(int a1)
{
 struct GUIWindow *pCharacterWindow;

  ++LODFile_Icons_LOD.uTexturePacksCount;
  if ( !LODFile_Icons_LOD.uPrevLoadedFiles )
    LODFile_Icons_LOD.uPrevLoadedFiles = LODFile_Icons_LOD.uNumLoadedFiles;
  ++LODFile_Icons_LOD.uTexturePacksCount;
  if ( !LODFile_Icons_LOD.uPrevLoadedFiles )
    LODFile_Icons_LOD.uPrevLoadedFiles = LODFile_Icons_LOD.uNumLoadedFiles;
  	cClock1.clock_fn1();//	 class24_fn1);
  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);

 dword_5118E0 = 0;
 CharacterUI_LoadPaperdollTextures();
 dword_4E28F8 = a1;

 pCharacterWindow = GUIWindowCreate(0, 0, 640, 480, 4, (GUIButton*)uActiveCharacter, 0);

 pCharacterUI_BtnStats = GUIButtonCreate(pCharacterWindow, pOldViewport->uGameX + 12, pOldViewport->uGameY + 308,
                   LODFile_Icons_LOD.aLODHeaders[dword_51122C].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[dword_51122C].uTextureHeight,
                   1,
                   0,
                   115,
                   0,
                   83,
                   pGlobalTXT_LocalizationStrings[216],
                   &LODFile_Icons_LOD.aLODHeaders[dword_511230],0 );
 pCharacterUI_BtnSkills = GUIButtonCreate(pCharacterWindow, pOldViewport->uGameX + 102, pOldViewport->uGameY + 308,
                   LODFile_Icons_LOD.aLODHeaders[dword_511224].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[dword_511224].uTextureHeight,
                   1,
                   0,
                   114,
                   0,
                   75,
                   pGlobalTXT_LocalizationStrings[205],
                   &LODFile_Icons_LOD.aLODHeaders[dword_511228],0 );
 pCharacterUI_BtnInventory = GUIButtonCreate(pCharacterWindow, pOldViewport->uGameX + 192, pOldViewport->uGameY + 308,
                   LODFile_Icons_LOD.aLODHeaders[dword_51121C].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[dword_51121C].uTextureHeight,
                   1,
                   0,
                   116,
                   0,
                   73,
                   pGlobalTXT_LocalizationStrings[120],
                   &LODFile_Icons_LOD.aLODHeaders[dword_511220],0);
 pCharacterUI_BtnAwards = GUIButtonCreate(pCharacterWindow, pOldViewport->uGameX + 282, pOldViewport->uGameY + 308,
                   LODFile_Icons_LOD.aLODHeaders[dword_511214].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[dword_511214].uTextureHeight,
                   1,
                   0,
                   117,
                   0,
                   65,
                   pGlobalTXT_LocalizationStrings[22],
                   &LODFile_Icons_LOD.aLODHeaders[dword_511218],0 );
 pCharacterUI_BtnExit = GUIButtonCreate(pCharacterWindow, pOldViewport->uGameX + 371, pOldViewport->uGameY + 308,
                   LODFile_Icons_LOD.aLODHeaders[dword_51120C].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[dword_51120C].uTextureHeight,
                   1,
                   0,
                   168,
                   0,
                   0,
                   pGlobalTXT_LocalizationStrings[LOCSTR_EXIT],
                   &LODFile_Icons_LOD.aLODHeaders[uTextureID_ButtExit1],0 );
  GUIButtonCreate(pCharacterWindow, 0, 0, 476, 345, 1, 122, 120, 0, 0, (unsigned char *)"", 0);
  pCharacterUI_BtnDetail = 
  GUIButtonCreate(pCharacterWindow, 600, 300, 30, 30, 1, 0, 85, 0, 0, pGlobalTXT_LocalizationStrings[LOCSTR_DETAIL_TOGGLE], 0);
  dword_507690 = 
  GUIButtonCreate(pCharacterWindow, 476,   0, 164, 345, 1,  0, 133, 0,  0, (unsigned char *)"", 0);
  GUIButtonCreate(pCharacterWindow,  61, 424,  31,   0, 2, 94, 110, 1, 49, (unsigned char *)"", 0);
  GUIButtonCreate(pCharacterWindow, 177, 424,  31,   0, 2, 94, 110, 2, 50, (unsigned char *)"", 0);
  GUIButtonCreate(pCharacterWindow, 292, 424,  31,   0, 2, 94, 110, 3, 51, (unsigned char *)"", 0);
  GUIButtonCreate(pCharacterWindow, 407, 424,  31,   0, 2, 94, 110, 4, 52, (unsigned char *)"", 0);
  GUIButtonCreate(pCharacterWindow,   0,   0,   0,   0, 1,  0, 176, 0,  9, (unsigned char *)"", 0);
  sub_419100();
  return pCharacterWindow;
}

//----- (004356B9) --------------------------------------------------------
bool GUIMessageQueue::GetQueueMessage(unsigned int *param1, int *param2, int *param3)
{
if (!msg_count)
	return false;

*param1 = prm[0].msg_param1;
*param2 = prm[0].msg_param2;
*param3 = prm[0].msg_param3;

if (msg_count > 1)
	{
	for(int i=0; i<msg_count-1; i++)
		{
		prm[i].msg_param1 = prm[i+1].msg_param1;
		prm[i].msg_param2 = prm[i+1].msg_param2;
		prm[i].msg_param3 = prm[i+1].msg_param3;
		}
	}
msg_count--;
return true;
}

//----- (0042EB8D) --------------------------------------------------------
inline void  GUIMessageQueue::PutMessageToQueue(unsigned int param1, int param2, int param3)	  //sub_42EB8D
{
 if (msg_count < 40 )
	{
		prm[msg_count].msg_param1=param1;
		prm[msg_count].msg_param2=param2;
		prm[msg_count].msg_param3=param3;
		msg_count++;
	}  
}

inline void	 GUIMessageQueue::CutQueueTail()
{
if ((msg_count)&&(prm[0].msg_param3>0))
		msg_count = 1;
}


//----- (0041B690) --------------------------------------------------------
void GameUI_LoadIcons()
{
  int v12; // eax@1
  int v17; // eax@1
  int v22; // eax@1
 int i;
 #ifndef OLD_CODE
 wchar_t pFilepath[256];
#endif


 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("wizeyeC"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("wizeyeB"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("wizeyeA"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("torchC"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("torchB"));
 pIconFrameTable->InitializeAnimation(pIconFrameTable->FindAnimation("torchA"));
#ifndef OLD_CODE
 uTextureID_MinimapDirections = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"MinimDir");

 uTextureIdx_UIBarRed = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ui-bar_red");
 uTextureIdx_UIBarYellow = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ui-bar_yello");
 uTextureIdx_UIBarGreen = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ui-bar_gr");
 uTextureIdx_UIBarBlue = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ui-bar_blue");

 uTextureIdx_MonsterHP_BarYellow = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ui-MHP_BYe");
 uTextureIdx_MonsterHP_BarRed = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ui-MHP_BRd");
 uTextureIdx_MonsterHP_BarGreen = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ui-MHP_BGr");
 uTextureIdx_MonsterHP_CapRight = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ui-MHP_CR");
 uTextureIdx_MonsterHP_CapLeft = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ui-MHP_CL");
 uTextureIdx_MonsterHP_Bg = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ui-MHP_Bg");

 uTextureIdx_Leather = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"LEATHER");

 //pcTexture_ibground = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ibground")];
 uTextureID_ibground = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ibground");

 uTextureIdx_BtnMake = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"ButtMake");
 uTextureIdx_BtnYes2 = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ButtYes2");
 uTextureIdx_BtnXokU = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"x_ok_u");

 uTextureIdx_BtnEsc2 = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ButtEsc2");
 uTextureIdx_BtnXxU = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"x_x_u");
 uTextureIdx_BtnMake2 = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ButtMake2");

 pGUIWindow0 = GUIWindowCreate(0, 0, 640, 480, 1, 0, 0);
 GUIButtonCreate(pGUIWindow0, 7, 8, 460, 343, 1, 0, 10, 0, 0, (unsigned char *)"", 0);

 //player portraits in Game screen
 GUIButtonCreate(pGUIWindow0,  50, 424, 70, 90, 2, 94, 110, 1, 49, (unsigned char *)"p0", 0);
 GUIButtonCreate(pGUIWindow0, 160, 424, 70, 90, 2, 94, 110, 2, 50, (unsigned char *)"p1", 0);
 GUIButtonCreate(pGUIWindow0, 280, 424, 70, 90, 2, 94, 110, 3, 51, (unsigned char *)"p2", 0);
 GUIButtonCreate(pGUIWindow0, 390, 424, 70, 90, 2, 94, 110, 4, 52, (unsigned char *)"p3", 0);

 GUIButtonCreate(pGUIWindow0, 24, 404, 5, 49, 1, 93, 0, 1, 0, (unsigned char *)"", 0);
 GUIButtonCreate(pGUIWindow0, 139, 404, 5, 49, 1, 93, 0, 2, 0, (unsigned char *)"", 0);
 GUIButtonCreate(pGUIWindow0, 255, 404, 5, 49, 1, 93, 0, 3, 0, (unsigned char *)"", 0);
 GUIButtonCreate(pGUIWindow0, 370, 404, 5, 49, 1, 93, 0, 4, 0, (unsigned char *)"", 0);
 GUIButtonCreate(pGUIWindow0, 97, 404, 5, 49, 1, 93, 0, 1, 0, (unsigned char *)"", 0);
 GUIButtonCreate(pGUIWindow0, 212, 404, 5, 49, 1, 93, 0, 2, 0, (unsigned char *)"", 0);
 GUIButtonCreate(pGUIWindow0, 328, 404, 5, 49, 1, 93, 0, 3, 0, (unsigned char *)"", 0);
 GUIButtonCreate(pGUIWindow0, 443, 404, 5, 49, 1, 93, 0, 4, 0, (unsigned char *)"", 0);

 uTextureIdx_ib_td1_A = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ib-td1-A");
 pBtn_Game_Quests = GUIButtonCreate(pGUIWindow0, 491, 353,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td1_A].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td1_A].uTextureHeight,
                   1,
                   0,
                   200,
                   0,
                   KeyboardController_sub_459C82_LooksLikeBindKey(pKeyboardController, VK_RETURN),
                   pGlobalTXT_LocalizationStrings[174],
                    &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td1_A],0);



  uTextureIdx_ib_td2_A = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ib-td2-A");
  pBtn_Game_Autonotes = GUIButtonCreate(pGUIWindow0, 527, 353,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td1_A].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td1_A].uTextureHeight,
                   1,
                   0,
                   201,
                   0,
                   KeyboardController_sub_459C82_LooksLikeBindKey(pKeyboardController, VK_CONTROL),
                   pGlobalTXT_LocalizationStrings[154],
                    &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td2_A],0);



  v17 = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ib-td3-A");
  pBtn_Game_Maps = GUIButtonCreate(pGUIWindow0, 546, 353,
                   LODFile_Icons_LOD.aLODHeaders[v17].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[v17].uTextureHeight,
                   1,
                   0,
                   202,
                   0,
                   KeyboardController_sub_459C82_LooksLikeBindKey(pKeyboardController, VK_MENU),
                   pGlobalTXT_LocalizationStrings[139],
                    &LODFile_Icons_LOD.aLODHeaders[v17],0);



  v22 = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ib-td4-A");
#endif
#ifdef OLD_CODE
 
  uTextureIdx_MapDirs[0] =  LODFile_Icons_LOD.LODFile_LoadTexture( "MAPDIR8", 2);
  uTextureIdx_MapDirs[1] =  LODFile_Icons_LOD.LODFile_LoadTexture( "MAPDIR1", 2);
  uTextureIdx_MapDirs[2] =  LODFile_Icons_LOD.LODFile_LoadTexture( "MAPDIR2", 2);
  uTextureIdx_MapDirs[3] =  LODFile_Icons_LOD.LODFile_LoadTexture( "MAPDIR3", 2);
  uTextureIdx_MapDirs[4] =  LODFile_Icons_LOD.LODFile_LoadTexture( "MAPDIR4", 2);
  uTextureIdx_MapDirs[5] =  LODFile_Icons_LOD.LODFile_LoadTexture( "MAPDIR5", 2);
  uTextureIdx_MapDirs[6] =  LODFile_Icons_LOD.LODFile_LoadTexture( "MAPDIR6", 2);
  uTextureIdx_MapDirs[7] =  LODFile_Icons_LOD.LODFile_LoadTexture( "MAPDIR7", 2);
  


 uTextureIdx_UIBarRed = LODFile_Icons_LOD.LODFile_LoadTexture("ib-statR",2);
 uTextureIdx_UIBarYellow = LODFile_Icons_LOD.LODFile_LoadTexture("ib-statY",2);
 uTextureIdx_UIBarGreen = LODFile_Icons_LOD.LODFile_LoadTexture("ib-statG",2);
 uTextureIdx_UIBarBlue = LODFile_Icons_LOD.LODFile_LoadTexture("ib-statB",2);

 uTextureIdx_MonsterHP_BarYellow = LODFile_Icons_LOD.LODFile_LoadTexture("mhp_yel",2);
 uTextureIdx_MonsterHP_BarRed = LODFile_Icons_LOD.LODFile_LoadTexture("mhp_red",2);
 uTextureIdx_MonsterHP_BarGreen = LODFile_Icons_LOD.LODFile_LoadTexture("mhp_grn",2);
 uTextureIdx_MonsterHP_CapRight = LODFile_Icons_LOD.LODFile_LoadTexture("mhp_capr",2);
 uTextureIdx_MonsterHP_CapLeft = LODFile_Icons_LOD.LODFile_LoadTexture("mhp_capl",2);
 uTextureIdx_MonsterHP_Bg = LODFile_Icons_LOD.LODFile_LoadTexture("mhp_bg",2);

 uTextureIdx_Leather = LODFile_Icons_LOD.LODFile_LoadTexture("LEATHER",2);

 uTextureID_ibground = LODFile_Icons_LOD.LODFile_LoadTexture("ibground",2);

 uTextureIdx_BtnMake = LODFile_Icons_LOD.LODFile_LoadTexture("ButtMake",2);
 uTextureIdx_BtnYes2 = LODFile_Icons_LOD.LODFile_LoadTexture("ButtYes2",2);
 uTextureIdx_BtnXokU = LODFile_Icons_LOD.LODFile_LoadTexture("x_ok_u",2);

 uTextureIdx_BtnEsc2 = LODFile_Icons_LOD.LODFile_LoadTexture("BUTTESC2",2);
 uTextureIdx_BtnXxU = LODFile_Icons_LOD.LODFile_LoadTexture("x_x_u",2);
 uTextureIdx_BtnMake2 = LODFile_Icons_LOD.LODFile_LoadTexture("BUTTMAKE2",2);

 pGUIWindow0 = GUIWindowCreate(0, 0, 640, 480, 1, 0, 0);
 GUIButtonCreate(pGUIWindow0, 7, 8, 460, 343, 1, 0, 10, 0, 0, (unsigned char*)"", 0,0);

 //player portraits in Game screen
 GUIButtonCreate(pGUIWindow0,  50, 424, 70, 90, 2, 94, 110, 1, 49, (unsigned char*)"p0", 0);
 GUIButtonCreate(pGUIWindow0, 160, 424, 70, 90, 2, 94, 110, 2, 50, (unsigned char*)"p1", 0);
 GUIButtonCreate(pGUIWindow0, 280, 424, 70, 90, 2, 94, 110, 3, 51, (unsigned char*)"p2", 0);
 GUIButtonCreate(pGUIWindow0, 390, 424, 70, 90, 2, 94, 110, 4, 52, (unsigned char*)"p3", 0);

 GUIButtonCreate(pGUIWindow0,  24, 404, 5, 49, 1, 93, 0, 1, 0, (unsigned char*) "", 0);
 GUIButtonCreate(pGUIWindow0, 139, 404, 5, 49, 1, 93, 0, 2, 0, (unsigned char*)"", 0);
 GUIButtonCreate(pGUIWindow0, 255, 404, 5, 49, 1, 93, 0, 3, 0, (unsigned char*)"", 0);
 GUIButtonCreate(pGUIWindow0, 370, 404, 5, 49, 1, 93, 0, 4, 0, (unsigned char*)"", 0);
 GUIButtonCreate(pGUIWindow0,  97, 404, 5, 49, 1, 93, 0, 1, 0, (unsigned char*)"", 0);
 GUIButtonCreate(pGUIWindow0, 212, 404, 5, 49, 1, 93, 0, 2, 0, (unsigned char*)"", 0);
 GUIButtonCreate(pGUIWindow0, 328, 404, 5, 49, 1, 93, 0, 3, 0, (unsigned char*)"", 0);
 GUIButtonCreate(pGUIWindow0, 443, 404, 5, 49, 1, 93, 0, 4, 0, (unsigned char*)"", 0);

 uTextureIdx_ib_td1_A = LODFile_Icons_LOD.LODFile_LoadTexture( "ib-td1-A",2);
 pBtn_Game_Quests = GUIButtonCreate(pGUIWindow0, 491, 353,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td1_A].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td1_A].uTextureHeight,
                   1,
                   0,
                   200,
                   0,
                   KeyboardController_sub_459C82_LooksLikeBindKey(pKeyboardController, VK_RETURN),
                   pGlobalTXT_LocalizationStrings[174],
                   &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td1_A],0 );



  uTextureIdx_ib_td2_A = LODFile_Icons_LOD.LODFile_LoadTexture( "ib-td2-A",2);
  pBtn_Game_Autonotes = GUIButtonCreate(pGUIWindow0, 527, 353,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td1_A].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td1_A].uTextureHeight,
                   1,
                   0,
                   201,
                   0,
                   KeyboardController_sub_459C82_LooksLikeBindKey(pKeyboardController, VK_CONTROL),
                   pGlobalTXT_LocalizationStrings[154],
                   &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td2_A],0 );



  v17 = LODFile_Icons_LOD.LODFile_LoadTexture( "ib-td3-A",2);
  pBtn_Game_Maps = GUIButtonCreate(pGUIWindow0, 546, 353,
                   LODFile_Icons_LOD.aLODHeaders[v17].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[v17].uTextureHeight,
                   1,
                   0,
                   202,
                   0,
                   KeyboardController_sub_459C82_LooksLikeBindKey(pKeyboardController, VK_MENU),
                   pGlobalTXT_LocalizationStrings[139],
                   &LODFile_Icons_LOD.aLODHeaders[v17],0 );



  v22 = LODFile_Icons_LOD.LODFile_LoadTexture("ib-td4-A",2);
#endif
  pBtn_Game_Calendar = GUIButtonCreate(pGUIWindow0, 570, 353,
                   LODFile_Icons_LOD.aLODHeaders[v22].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[v22].uTextureHeight,
                   1,
                   0,
                   203,
                   0,
                   KeyboardController_sub_459C82_LooksLikeBindKey(pKeyboardController, VK_SHIFT),
                   pGlobalTXT_LocalizationStrings[78],
                   &LODFile_Icons_LOD.aLODHeaders[v22],0 );



  uTextureIdx_ib_td5_A = LODFile_Icons_LOD.LODFile_LoadTexture("ib-td5-A",2);
  pBtn_Game_Inventory = GUIButtonCreate(pGUIWindow0, 600, 361,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td5_A].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td5_A].uTextureHeight,
                   1,
                   0,
                   224,
                   0,
                   72,
                   pGlobalTXT_LocalizationStrings[159],
                   &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td5_A],0 );



  byte_507948 = 0;
  byte_507949 = 0;
  byte_50794A = 0;
  pBtn_Game_MinimapZoomOut = GUIButtonCreate(pGUIWindow0, 574, 136,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_autout_a].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_autout_a].uTextureHeight,
                   2,
                   0,
                   368,
                   0,
                   KeyboardController_sub_459C82_LooksLikeBindKey(pKeyboardController, VK_JUNJA),
                   pGlobalTXT_LocalizationStrings[252],
                   &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_autout_a],0 );



  pBtn_Game_MinimapZoomIn = GUIButtonCreate(pGUIWindow0, 519, 136,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_autin_a].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_autin_a].uTextureHeight,
                   2,
                   0,
                   367,
                   0,
                   KeyboardController_sub_459C82_LooksLikeBindKey(pKeyboardController, VK_FINAL),
                   pGlobalTXT_LocalizationStrings[251],
                   &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_autin_a],0 );



  GUIButtonCreate(pGUIWindow0, 481, 0, 153, 67, 1, 92, 0, 0, 0, (unsigned char *)"", 0);
  GUIButtonCreate(pGUIWindow0, 491, 149, 64, 74, 1, 0, 134, 0, 53, (unsigned char *)"", 0);
  GUIButtonCreate(pGUIWindow0, 561, 149, 64, 74, 1, 0, 135, 0, 54, (unsigned char *)"", 0);
  GUIButtonCreate(pGUIWindow0, 476, 322, 77, 17, 1, 100, 0, 0, 0, (unsigned char *)"", 0);
  GUIButtonCreate(pGUIWindow0, 555, 322, 77, 17, 1, 101, 0, 0, 0, (unsigned char *)"", 0);

  pBtn_Game_CastSpell = GUIButtonCreate(pGUIWindow0, 476, 450,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_m1d_a].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_m1d_a].uTextureHeight,
                   1,
                   0,
                   105,
                   0,
                   67,
                   pGlobalTXT_LocalizationStrings[38],
                   &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_m1d_a],0 );

  pBtn_Game_Rest = GUIButtonCreate(pGUIWindow0, 518, 450,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_m2d_a].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_m2d_a].uTextureHeight,
                   1,
                   0,
                   104,
                   0,
                   82,
                   pGlobalTXT_LocalizationStrings[182],
                   &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_m2d_a],0 );

  pBtn_Game_QuickRef = GUIButtonCreate(pGUIWindow0, 560, 450,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_m3d_a].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_m3d_a].uTextureHeight,
                   1,
                   0,
                   106,
                   0,
                   90,
                   pGlobalTXT_LocalizationStrings[173],
                   &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_m3d_a],0 );

  pBtn_Game_Options = GUIButtonCreate(pGUIWindow0, 602, 450,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_m4d_a].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_m4d_a].uTextureHeight,
                   1,
                   0,
                   107,
                   0,
                   0,
                   pGlobalTXT_LocalizationStrings[93],
                   &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_m4d_a],0 );

  pBtn_Game_NPCScrollLeftDown = GUIButtonCreate(pGUIWindow0, 469, 178,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_npcld_a].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_npcld_a].uTextureHeight,
                   1,
                   0,
                   188,
                   0,
                   0,
                   (unsigned char *)"",
                   &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_npcld_a],0 );

  pBtn_Game_NPCScrollRightDown = GUIButtonCreate(pGUIWindow0, 626, 178,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_npcrd_a].uTextureWidth,
                   LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_npcrd_a].uTextureHeight,
                   1,
                   0,
                   188,
                   1,
                   0,
                   (unsigned char *)"",
                   &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_npcrd_a],0 );


 for (i = 0; i < 14; ++i)
 {
  #ifndef OLD_CODE
  wsprintfW(pFilepath, L"isn-%02d", i + 1);
  uTextureIdx_SpellEffecIcons[i] = LODFile_Icons_LOD.LODFile_LoadTexture_New( pFilepath);
#endif
  #ifdef OLD_CODE

  char pFilepath[16];
   wsprintf(pFilepath, "isn-%02d", i + 1);
   uTextureIdx_SpellEffecIcons[i] = LODFile_Icons_LOD.LODFile_LoadTexture( pFilepath,2);
#endif
 }

 uIconIdx_Spell21 = pIconFrameTable->FindAnimation("spell21");
 uIconIdx_Spell27 = pIconFrameTable->FindAnimation("spell27");
}


//----- (00415485) --------.text:004158F7 ------------------------------------------------
char *__cdecl CreateCopyrightWindow()
{
 GUIWindow local_08;
 int text_h;

 memset(&local_08, 0, sizeof(GUIWindow));

 local_08.uFrameX = 8;
 local_08.uFrameY = 30;
 local_08.uFrameWidth = 624;
 local_08.uFrameHeight = 256;

 text_h=CalculateTextHeght(pFontSmallnum, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_3DO_COPYRHT], &local_08, 24, 0);
 text_h=text_h	 + 2 * pFontSmallnum->uFontHeight + 24;
 local_08.uFrameHeight=text_h; 
 local_08.uFrameY = 470 - text_h;
 local_08.uFrameZ = local_08.uFrameX + local_08.uFrameWidth - 1;
 local_08.uFrameW = 469;
 GUIWindow_sub_415551(&local_08, 0);

 local_08.uFrameWidth -= 24;
 local_08.uFrameX += 12;
 local_08.uFrameY += 12;
 local_08.uFrameHeight -= 12;
 local_08.uFrameZ = local_08.uFrameX + local_08.uFrameWidth - 1;
 local_08.uFrameW = local_08.uFrameY + local_08.uFrameHeight - 1;
 return GUIWindow_sub_44D406(&local_08, pFontSmallnum, 0, 12, 0, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_3DO_COPYRHT], 3);
}

//----- (00415551) --------------------------------------------------------
void __thiscall GUIWindow_sub_415551(GUIWindow *_this, int a2)
{
  int v3; // edi@1
  int v4; // eax@2
  int v5; // esi@2
  int v6; // ecx@6
  int v7; // eax@9
  int v8; // eax@10
  signed int v9; // eax@18
  int v10; // eax@18
  int v11; // edx@18
  const char *v12; // ecx@18
  int v13; // ecx@18
  signed int v14; // esi@19
  int v15; // eax@19
  int v17; // eax@26
  
  GUIWindow local_0C;//int v18; // [sp+Ch] [bp-60h]@18
  //int v19; // [sp+10h] [bp-5Ch]@18
  //int v20; // [sp+14h] [bp-58h]@18
  //int v21; // [sp+18h] [bp-54h]@18
  //int v22; // [sp+1Ch] [bp-50h]@18
  //int v23; // [sp+20h] [bp-4Ch]@18

  POINT v24;
  //char v24; // [sp+60h] [bp-Ch]@8
  //int v25; // [sp+64h] [bp-8h]@18
  int v26; // [sp+68h] [bp-4h]@18
  int v27; // [sp+74h] [bp+8h]@2
  int v28; // [sp+74h] [bp+8h]@18

  v3 = 0;
  if ( a2 )
  {
    v5 = pOldViewport->uGameX;
    v4 = pOldViewport->uGameZ;
    v3 = pOldViewport->uGameY;
    v27 = pOldViewport->uGameW;
  }
  else
  {
    v5 = 0;
    v4 = 640;
    v27 = 480;
  }
  if (_this->uFrameX >= v5 )
  {
   v6 = _this->uFrameWidth;
    if ( v6 + _this->uFrameX <= v4 )
      goto LABEL_9;
    _this->uFrameX = v4 - v6;
  }
  else
  {
    _this->uFrameX = v5;
  }
  _this->uFrameY = GUICursor_GetMousePos(pGame->pGUICursor, &v24)->y + 30;
LABEL_9:
  v7 = _this->uFrameY;
  if ( v7 >= v3 )
  {
   if ( v7 + _this->uFrameHeight <= v27 )
      goto LABEL_14;
   v8 = GUICursor_GetMousePos(pGame->pGUICursor, &v24)->y - _this->uFrameHeight - 30;
  }
  else
  {
    v8 = GUICursor_GetMousePos(pGame->pGUICursor, &v24)->y + 30;
  }
  _this->uFrameY = v8;
LABEL_14:
  if (_this->uFrameY < v3 )
    _this->uFrameY = v3;
  if (_this->uFrameX < v5 )
    _this->uFrameX = v5;
  v10 = _this->uFrameWidth;
  v13 = _this->uFrameX;
  v11 = _this->uFrameY;
  v26 = v10;
  v24.y = v13;
  _this->uFrameZ = v10 + v13 - 1;
  v9 = _this->uFrameHeight;
  _this->uFrameW = v9 + v11 - 1;
  memcpy(&local_0C, (const void *)_this, sizeof(GUIWindow));
  local_0C.uFrameX += 12;
  local_0C.uFrameWidth -= 24;
  local_0C.uFrameY += 12;
  local_0C.uFrameHeight -= 12;
  local_0C.uFrameZ = local_0C.uFrameWidth + local_0C.uFrameX - 1;
  v28 = v11;
  local_0C.uFrameW = local_0C.uFrameHeight + local_0C.uFrameY - 1;
  v12 = (char *)local_0C.ptr_000048;
  if ( v12 )
  {
    v15 = CalculateTextHeght(pFontLucida, v12, &local_0C, 0, 0);
    v11 = v28;
    v14 = v15 + 24;
  }
  else
  {
    v14 = v9;
  }
  if ( v14 < 64 )
    v14 = 64;
  if ( v14 + v11 > 479 )
    v14 = 479 - v11;
  DrawWindow(v24.y, v11, v26, v14);
  if (local_0C.ptr_000048)
  {
    v17 = CalculateTextHeght(pFontLucida, (char *)local_0C.ptr_000048, &local_0C, 0, 0);
    GUIWindow_sub_44D406(&local_0C, pFontLucida, 0, (v14 - v17) / 2 - 14, 0, (char *)local_0C.ptr_000048, 3);
  }
}


//----- (004BF794) --------------------------------------------------------
void __cdecl LoadMainMenu()
{
  //int v1; // eax@6
 float fVolume; // qax@8

  int v5; // [sp+34h] [bp-8h]@8
  int v6; // [sp+38h] [bp-4h]@8

 pVideoPlayer->dword_00006C = 0;
 pVideoPlayer->dword_000040 = 0;
 dword_F8BC10 = 1;

 bSkipVideo = true;
 if (!bSkipVideo)
 {
  Render_ClearBackBufferAndPresent(pD3DRenderer);

  PlayMovie(1, 1);

  if (!pVideoPlayer->dword_00006C)
  {
   PlayMovie(2, 1);
   if (!pVideoPlayer->dword_00006C)
   {
    PlayMovie(3, 1);
    if (!pVideoPlayer->dword_00006C)
      PlayMovie(5, 1);
   }
  }
 }

 MenuUI_LoadTextures(1);
 MenuUI_LoadFontsAndSomeStuff();

#ifndef OLD_CODE
 uTextureID_MainMenuUI_Title = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"mm7title");
#endif
 #ifdef OLD_CODE
      cPCXID_MainMenuUI_Title.LODPCXLoad("mm6title.pcx",0);
  #endif
 pD3DRenderer->BeginScene();
 {
 #ifndef OLD_CODE
  Render_DrawRGBTexture_New(pD3DRenderer, 0, 0, uTextureID_MainMenuUI_Title);
 #endif
 #ifdef OLD_CODE
	  Render_DrawRGBTexture(pD3DRenderer, 0, 0, &cPCXID_MainMenuUI_Title);
   #endif
  CreateCopyrightWindow();
 }

 pD3DRenderer->EndScene();
 pD3DRenderer->Present();

 if (~dword_6BE364 & 0x10) // if (!nosound)
 {
  if (pAudioPlayer->hAILRedbook)
  {
   fVolume = aMusicVolumeLevels[uMusicVolimeMultiplier] * 64.0;
   AudioPlayer_SetVolume(pAudioPlayer, fVolume);
   AIL_redbook_stop(pAudioPlayer->hAILRedbook);
   AIL_redbook_track_info(pAudioPlayer->hAILRedbook, 14, (unsigned int *)&v5, (unsigned int *)&v6);
   AIL_redbook_play(pAudioPlayer->hAILRedbook, v5 + 1, v6);
  }
 }
 dword_F8BC10 = 0;
}

//----- (00420EFF) --------------------------------------------------------
void GameUI_Update()
{
  int v1; // ebx@6
  int *v2; // edi@7
  unsigned int v4; // eax@19
  int v5; // ecx@19
  int v6; // eax@19
  char v7; // cl@19
  __int16 v8; // fps@23
  unsigned __int8 v9; // c0@23
  unsigned __int8 v10; // c3@23
  int v11; // esi@24
  int v12; // edx@25
  unsigned int v14; // eax@41
  void *v15; // ecx@44
  int v16; // ecx@46
  int v17; // eax@49
  signed int v18; // eax@55
  signed int v19; // ecx@63
  int v20; // eax@69
  __int16 v21; // ax@70
  char *v22; // eax@72
  __int16 v23; // ax@75
  __int16 *v24; // ecx@75
  __int16 *v25; // esi@75
  int v26; // ecx@79
  int v27; // eax@82
  char *v28; // ecx@82
  const CHAR *v29; // esi@82
  int v30; // ecx@88
  int v31; // eax@91
  int v35; // esi@110
  int v36; // edx@111
  int v37; // edx@117
  int v38; // ecx@118
  int v39; // [sp-8h] [bp-E8h]@20
  int v40; // [sp-8h] [bp-E8h]@83
  int v41; // [sp-4h] [bp-E4h]@20
  char Str1[200]; // [sp+Ch] [bp-D4h]@129
  int x; // [sp+D4h] [bp-Ch]@1
  int y; // [sp+D8h] [bp-8h]@1
 struct GUIButton *pControl;

  pGame->pGUICursor->dword_000000 = 0;
  GUICursor_GetMouseClickPos(pGame->pGUICursor, &x, &y);
  if (x < 0 || x > 639 ||
      y < 0 || y > 479)
    return;

  if ( !dword_4E28F8 )
  {
    if (x > 467 || y > 351)  //if pointer isn't inside game OldViewport
      goto _mouse_is_on_UI;

    if ( pD3DRenderer->pRenderD3D3 )
    {
      v18 = sub_4C1BF1_Vis_LooksLikeFindTopmostZObject(pGame->pVis);
      if (x < pOldViewport->uScreenX || x > pOldViewport->uScreenZ ||
          y < pOldViewport->uScreenY || y > pOldViewport->uScreenW)
        v18 = -1;
      if ( v18 == -1 )
        goto LABEL_61;
    }
    else
      v18 = pD3DRenderer->pActiveZBuffer[x + dword_5059A8[y]];

    pGame->pGUICursor->dword_000000 = (unsigned __int16)v18;
    v19 = (signed int)(unsigned __int16)v18 >> 3;
    if ( (v18 & 7) == 2 )
    {
      v30 = 112 * v19;
      if (pObjectDescriptionList->pDescriptions[pLayingItemsList[v19].uObjectDescriptionID].byte_000026 & 0x10)
        goto LABEL_73;
      if ( v18 >= 33554432 || pParty_global->pickedItem.uItemID)
      {
        v22 = (char *)ItemGen_sub_456499(&pLayingItemsList[v30/112].stru_000024);
LABEL_93:
        v26 = (int)v22;
        goto LABEL_87;
      }
      v31 = ItemGen_sub_456499(&pLayingItemsList[v30/112].stru_000024);
      v29 = (char *)TmpBuf;
      wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[470], v31);
    }
    else
    {
      if ( (v18 & 7) != 3 )
      {
        if ( (v18 & 7) == 5 )
        {
          v24 = (short *)&pLevelDecorations[v19];
          v25 = v24;
          v23 = v24[11];
          if ( !v23 )
          {
            if ( sub_44C2F4_SomeDecorationTypeCheck((LevelDecoration *)v24) )
             v26 = (int)dword_722240[2 * (unsigned __int8)global_5E4C90.byte_000000[v25[14]]];
            else
              v26 = (int)(84 * *v25 + pDecorationDescriptionList->pDescriptions + 32);
            goto LABEL_87;
          }
          v22 = sub_444732((void *)v23);
          if ( !v22 )
            goto LABEL_123;
          goto LABEL_93;
        }
        if ( (v18 & 7) == 6 )
        {
          if ( v18 < 33554432 )
          {
            if ( dword_6BE360 != 1 )
            {
              v21 = *(_WORD *)(*(_DWORD *)((char *)&pClass51_global->pBModels[((signed int)(unsigned __int16)v18 >> 9)] + 84)
                             + 308 * (v19 & 0x3F)
                             + 292);
              goto LABEL_71;
            }
            v20 = dword_6BE644 + 96 * v19;
            if ( *(_BYTE *)(v20 + 47) & 6 )
            {
              v21 = *(_WORD *)(dword_6BE64C + 36 * *(_WORD *)(v20 + 72) + 26);
LABEL_71:
              if ( !v21 || (v22 = sub_444732((void *)v21), !v22) )
                goto LABEL_73;
              goto LABEL_93;
            }
          }
LABEL_73:
          pGame->pGUICursor->dword_000000 = 0;
          goto LABEL_50;
        }
LABEL_61:
        pGame->pGUICursor->dword_000000 = 0;
        goto LABEL_123;
      }
      if ( v18 >= 335544320 )
        goto LABEL_61;
      v28 = (char *)pActors + 836 * v19;
      v29 = (char *)TmpBuf;
      v27 = *((_DWORD *)v28 + 205);
      if ( v27 )
        //v40 = dword_5D2958[v27];
        v40 = (int)pMonsterStats->sPlacements.pSubstrings[v27 - 1];
      else
        v40 = (int)pMonsterStats->pMonsterInfos[*((_WORD *)v28 + 48)].pName;
      strncpy((char *)(char *)TmpBuf, (const char *)v40, 0x7D0u);
    }
    v26 = (int)v29;
LABEL_87:
    sub_41C0B8((const char *)v26);
    goto LABEL_123;
  }
  v1 = sLastGUIWindowIdx;

  if ( sLastGUIWindowIdx <= 0 )
  {
LABEL_38:
    if ( dword_4E28F8 == 10 )
    {
      sub_42038D();
      goto LABEL_123;
    }
    if ( dword_4E28F8 == 13 )
    {
      if ( dword_F8B19C != 2
        || (v16 = pD3DRenderer->pActiveZBuffer[x + dword_5059A8[y]], v16 == 0)
        || v16 == -65536 )
        goto LABEL_123;
      v15 = (void *)(36 * (v16 + 12 * (int)ptr_507BC0->dword_00001C) + 11355920);
LABEL_49:
      v17 = ItemGen_sub_456499((ItemGen *)v15);
      sub_41C0B8((const char *)v17);
LABEL_50:
      dword_506578 = 1;
LABEL_123:
      if (pGame->pGUICursor->dword_000000 == 0)
      {
        if ( dword_506578 != 0 )
        {
          pStatusBarString[0] = 0;
          dword_5C35BC = 1;
        }
      }
      dword_506578 = pGame->pGUICursor->dword_000000;
      return;
    }
    if ( y < 350 )
    {
      v14 = pD3DRenderer->pActiveZBuffer[x + dword_5059A8[y]];
      if ( v14 == 0 || v14 == -65536 || v14 >= 0x1388 )
        goto LABEL_123;
      v15 = *((char **)pPlayers[uActiveCharacter] + 36 * v14 + 496);
      goto LABEL_49;
    }

_mouse_is_on_UI:
    if (x >= GUIWindow_List[0].uFrameX && x <= GUIWindow_List[0].uFrameZ &&
        y >= GUIWindow_List[0].uFrameY && y <= GUIWindow_List[0].uFrameW)
    {
      for ( pControl = GUIWindow_List[0].pControlsHead; pControl; pControl = pControl->pNext)
      {
        if (pControl->dword_000018 == 1 )
        {
          if (x >= pControl->uX && x <= pControl->uZ &&
              y >= pControl->uY && y <= pControl->uW)
          {
            v37 = pControl->dword_00001C;
            if (!v37)
            {
             sub_41C0B8((char *)pControl->pButtonName);
             dword_506578 = 1;
             return;
            }
            v38 = pControl->dword_000024;
         /*   if ( dword_50CBD0.msg_count < 40 )
            {
			  dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param1=v37;
			  dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param2=v38;
			  dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param3=0;
			  dword_50CBD0.msg_count++;
            }  */
			dword_50CBD0.PutMessageToQueue(pControl->dword_00001C,pControl->dword_000024,0);
            dword_506578 = 1;
            return;
          }
        }
        else if (pControl->dword_000018 == 2)
        {
           if (pControl->uWidth && pControl->uHeight)
           {
            // elliptic buttons
            //if ((x - pControl->uX) * (x - pControl->uX) / (float)(pControl->uWidth * pControl->uWidth) +
            //    (y - pControl->uY) * (y - pControl->uY) / (float)(pControl->uHeight * pControl->uHeight) < 1.0)
            if (x >= pControl->uX && x <= pControl->uZ &&
                y >= pControl->uY && y <= pControl->uW)
            {
                  v35 = pControl->dword_00001C;

                  if ( v35 != 0 )
                  {
                  /*  v36 = pControl->dword_000024;
					  if ( dword_50CBD0.msg_count < 40 )
						{
						  dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param1=v35;
						  dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param2=v36;
						  dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param3=0;
						  dword_50CBD0.msg_count++;
						}	*/
				   dword_50CBD0.PutMessageToQueue(pControl->dword_00001C,pControl->dword_000024,0);
                  }
              sub_41C0B8((char *)pControl->pButtonName);
              dword_506578 = 1;
              return;
            }
           }
         }
        else if (pControl->dword_000018 == 3 &&
                  x >= pControl->uX && x <= pControl->uZ &&
                  y >= pControl->uY && y <= pControl->uW)
            goto LABEL_19;
      }
    }
    pGame->pGUICursor->dword_000000 = sub_46A99B();
    goto LABEL_123;
  }
  while ( 1 )
  {
    v2 = (int *)&GUIWindow_List[array_5075E0[v1] - 1];
    if ( x >= *v2 && x <= v2[4] && y >= v2[1] && y <= v2[5] )
    {
     for (pControl = GUIWindow_List[array_5075E0[v1] - 1].pControlsHead; pControl; pControl = pControl->pNext)
      {
        if (pControl->dword_000018 == 1 )
        {
          if (x >= pControl->uX && x <= pControl->uZ &&
              y >= pControl->uY && y <= pControl->uW)
          {
LABEL_24:
            v11 = pControl->dword_00001C;
            if ( v11 )
            {
             /* v12 = pControl->dword_000024;
			    if ( dword_50CBD0.msg_count < 40 )
				{
				  dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param1=v11;
				  dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param2=v12;
				  dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param3=0;
				  dword_50CBD0.msg_count++;
				}  */
			  dword_50CBD0.PutMessageToQueue(pControl->dword_00001C,pControl->dword_000024,0);
            }

            sub_41C0B8((char *)pControl->pButtonName);
            dword_506578 = 1;
            return;
          }
        }
        else
        {
          if (pControl->dword_000018 == 2 )
          {
           //decompilation error
            /*45 = x - pControl->uX;
            v45 = y - pControl->uY;
            if ( (double)pControl->uWidth != 0.0 )
            {
             if ( (double)pControl->uHeight != 0.0 )
              {
                UNDEF(v8);
                if ( v9 | v10 )
                  goto LABEL_24;
              }
            }*/

            // elliptic buttons
            //if ((x - pControl->uX) * (x - pControl->uX) / (float)(pControl->uWidth * pControl->uWidth) +
            //    (y - pControl->uY) * (y - pControl->uY) / (float)(pControl->uHeight * pControl->uHeight) < 1.0)
            if (x >= pControl->uX && x <= pControl->uZ &&
                y >= pControl->uY && y <= pControl->uW)
              goto LABEL_24;
          }
          else
          {
            if (pControl->dword_000018 == 3 &&
                x >= pControl->uX && x <= pControl->uZ &&
                y >= pControl->uY && y <= pControl->uW)
            {
LABEL_19:
              v6 = (int)pPlayers[uActiveCharacter];
              v7 = *(_BYTE *)(v6 + 2 * pControl->dword_000024 + 264);
              v4 = *(_DWORD *)(v6 + 6456);
              v5 = (v7 & 0x3F) + 1;
              if ( v4 < v5 )
              {
                v41 = v5 - v4;
                v39 = (int)pGlobalTXT_LocalizationStrings[469];
              }
              else
              {
                v41 = v5;
                v39 = (int)pGlobalTXT_LocalizationStrings[468];
              }
              wsprintfA(Str1, (const char *)v39, v41);

              sub_41C0B8(Str1);
              dword_506578 = 1;
              return;
            }
          }
        }
      }
    }
    if ( v2[3] == 480 )
      break;
    --v1;
    if ( v1 <= 0 )
    {
      goto LABEL_38;
    }
  }
}

//----- (004304E7) --------------------------------------------------------
void GameUI_Process()
{
  int v0; // edi@6
  const char *v1; // esi@6
  int v2; // eax@7
  int v3; // edx@7
  char *v4; // ecx@13
  int v7; // edx@20
  int v8; // ecx@29
  char v9; // sf@57
  int v10; // edx@59
  int v11; // ecx@60
  int v12; // ecx@73
  int v13; // eax@75
  unsigned __int8 v14; // sf@75
  unsigned __int8 v15; // of@75
  int v16; // eax@98
  int v17; // eax@102
  unsigned __int8 v18; // al@104
  unsigned __int8 v19; // al@105
  int v20; // eax@106
  unsigned __int8 v21; // sf@106
  unsigned __int8 v22; // of@106
  char v23; // sf@119
  int v24; // ecx@121
  float v25; // ST64_4@121
  float v26; // ST64_4@126
  float v27; // ST64_4@127
  int v28; // ecx@135
  int v30; // ecx@149
  int v31; // ecx@165
  int v32; // eax@204
  int v33; // edx@204
  int v34; // ecx@204
  int v35; // eax@237
  int v36; // ecx@248
  int v37; // edx@258
  const CHAR *v38; // ecx@262
  signed int v39; // eax@269
  int v40; // eax@277
  unsigned __int8 v41; // al@279
  unsigned __int8 v42; // al@280
  const char *v43; // edx@289
  struct GUIWindow *v44; // ecx@332
  int v45; // eax@336
  int v46; // eax@336
  int v47; // eax@336
  int v48; // eax@341
  int v49; // eax@358
  signed int v50; // eax@365
  SHORT v51; // ax@365
  char *v52; // eax@380
  signed __int64 v53; // qax@385
  int v54; // eax@396
  int v55; // eax@397
  signed int v56; // eax@398
  int v57; // edx@398
  signed int v58; // ecx@398
  char v59; // zf@399
  char v60; // zf@405
  int v61; // ecx@410
  int v62; // ecx@412
  int v63; // ecx@415
  int v64; // eax@424
  __int16 v65; // ax@431
  int v66; // eax@432
  int v67; // ecx@432
  int v68; // edx@432
  int v69; // eax@432
  int v70; // edx@442
  signed int v71; // eax@445
  signed int v72; // ST64_4@459
  int v73; // eax@467
  int v74; // edx@467
  __int16 v75; // dx@479
  int v76; // ecx@486
  signed int v77; // eax@486
  int v78; // eax@488
  int v79; // eax@489
  __int16 v80; // dx@498
  int v81; // eax@512
  int v82; // eax@525
  int v83; // edi@527
  int v84; // esi@527
  char *v85; // ecx@533
  int v86; // eax@535
  signed int v87; // edi@535
  signed int v88; // esi@535
  int v89; // eax@537
  int v90; // ecx@549
  int v91; // edx@550
  int v92; // ecx@550
  signed int v93; // eax@552
  int v94; // eax@553
  signed int v95; // ecx@554
  signed int v96; // ecx@554
  int v97; // eax@578
  unsigned int v98; // eax@583
  const char *v99; // ecx@595
  const char *v100; // ecx@596
  int v101; // eax@598
  signed int v102; // eax@602
  int v103; // eax@605
  int v104; // edx@605
  int v105; // edx@605
  int v106; // edx@611
  int v107; // eax@611
  const char *v108; // ecx@621
  unsigned int v109; // eax@624
  int v110; // eax@636
  unsigned __int8 v111; // al@643
  int v112; // eax@648
  int v113; // ecx@648
  int v114; // edx@652
  char v115; // sf@656
  int v116; // eax@671
  int v117; // eax@703
  int v118; // eax@703
  int v119; // eax@718
  int v120; // ecx@718
  int v122; // eax@758
  int v123; // eax@758
  int v130; // eax@764
  int v131; // eax@776
  int v132; // eax@777
  signed int v133; // eax@785
  signed int v134; // ecx@786
  unsigned __int8 v135; // zf@799
  unsigned __int8 v136; // sf@799
  int v137; // [sp-28h] [bp-624h]@86
  int v138; // [sp-28h] [bp-624h]@711
  int v139; // [sp-24h] [bp-620h]@86
  int v140; // [sp-24h] [bp-620h]@711
  int v141; // [sp-20h] [bp-61Ch]@86
  int v142; // [sp-20h] [bp-61Ch]@711
  int v143; // [sp-1Ch] [bp-618h]@86
  int v144; // [sp-1Ch] [bp-618h]@107
  int v145; // [sp-1Ch] [bp-618h]@711
  int v146; // [sp-18h] [bp-614h]@86
  signed int v147; // [sp-18h] [bp-614h]@107
  int v148; // [sp-14h] [bp-610h]@86
  int v149; // [sp-14h] [bp-610h]@107
  int v150; // [sp-10h] [bp-60Ch]@60
  int v151; // [sp-10h] [bp-60Ch]@86
  signed int v152; // [sp-10h] [bp-60Ch]@107
  int v153; // [sp-10h] [bp-60Ch]@121
  int v154; // [sp-Ch] [bp-608h]@60
  int v155; // [sp-Ch] [bp-608h]@86
  int v156; // [sp-Ch] [bp-608h]@107
  int v157; // [sp-Ch] [bp-608h]@121
  signed int v158; // [sp-8h] [bp-604h]@56
  signed int v159; // [sp-8h] [bp-604h]@60
  char v160; // [sp-8h] [bp-604h]@86
  int v161; // [sp-8h] [bp-604h]@107
  signed int v162; // [sp-8h] [bp-604h]@121
  int v163; // [sp-8h] [bp-604h]@449
  int v164; // [sp-8h] [bp-604h]@550
  int v165; // [sp-4h] [bp-600h]@56
  int v166; // [sp-4h] [bp-600h]@59
  const char *v167; // [sp-4h] [bp-600h]@86
  int v168; // [sp-4h] [bp-600h]@107
  int v169; // [sp-4h] [bp-600h]@121
  int v170; // [sp-4h] [bp-600h]@135
  int v171; // [sp-4h] [bp-600h]@149
  int v172; // [sp-4h] [bp-600h]@165
  int v173; // [sp-4h] [bp-600h]@204
  int v174; // [sp-4h] [bp-600h]@444
  int v175; // [sp-4h] [bp-600h]@449
  __int16 v176; // [sp-4h] [bp-600h]@550
  int v177; // [sp-4h] [bp-600h]@599
  int v178; // [sp-4h] [bp-600h]@637
  int v179; // [sp+0h] [bp-5FCh]@56
  int v180; // [sp+0h] [bp-5FCh]@59
  int v181; // [sp+0h] [bp-5FCh]@86
  int v182; // [sp+0h] [bp-5FCh]@107
  int v183; // [sp+0h] [bp-5FCh]@121
  int v184; // [sp+0h] [bp-5FCh]@135
  int v185; // [sp+0h] [bp-5FCh]@149
  int v186; // [sp+0h] [bp-5FCh]@165
  int v187; // [sp+0h] [bp-5FCh]@204
  signed int v188; // [sp+0h] [bp-5FCh]@259
  int v189; // [sp+0h] [bp-5FCh]@287
  int v190; // [sp+0h] [bp-5FCh]@444
  int v191; // [sp+0h] [bp-5FCh]@449
  int v192; // [sp+0h] [bp-5FCh]@550
  int v193; // [sp+0h] [bp-5FCh]@599
  const char *v194; // [sp+0h] [bp-5FCh]@629
  int v195; // [sp+0h] [bp-5FCh]@637
  int v196; // [sp+14h] [bp-5E8h]@22
  signed int v197; // [sp+14h] [bp-5E8h]@251
  signed int v198; // [sp+14h] [bp-5E8h]@272
  int v201; // [sp+14h] [bp-5E8h]@445
  int v202; // [sp+14h] [bp-5E8h]@455
  int v203; // [sp+14h] [bp-5E8h]@467
  int v204; // [sp+14h] [bp-5E8h]@528
  int v205; // [sp+14h] [bp-5E8h]@535
  int v206; // [sp+14h] [bp-5E8h]@604
  int v207; // [sp+14h] [bp-5E8h]@641
  int v208; // [sp+14h] [bp-5E8h]@648
  int v209; // [sp+18h] [bp-5E4h]@7
  int v210; // [sp+1Ch] [bp-5E0h]@18
  int v211; // [sp+20h] [bp-5DCh]@23
  int v212; // [sp+24h] [bp-5D8h]@18
  char v213; // [sp+2Bh] [bp-5D1h]@101
  int v215; // [sp+30h] [bp-5CCh]@7
  int v216; // [sp+34h] [bp-5C8h]@518
  char v217; // [sp+38h] [bp-5C4h]@553
  char v218; // [sp+40h] [bp-5BCh]@141
  char v219; // [sp+48h] [bp-5B4h]@127
  char v220; // [sp+50h] [bp-5ACh]@777
  char v221; // [sp+58h] [bp-5A4h]@171
  char v222; // [sp+60h] [bp-59Ch]@553
  char v223; // [sp+68h] [bp-594h]@155
  char v224; // [sp+70h] [bp-58Ch]@397
  char v225; // [sp+78h] [bp-584h]@777
  char v226; // [sp+80h] [bp-57Ch]@397
  char v227; // [sp+88h] [bp-574h]@704
  __int64 v228; // [sp+90h] [bp-56Ch]@467
  char v229; // [sp+98h] [bp-564h]@385
  char Dest; // [sp+9Ch] [bp-560h]@380
  char Source; // [sp+BCh] [bp-540h]@370
  int v232; // [sp+DCh] [bp-520h]@524
  char *Str; // [sp+E0h] [bp-51Ch]@525
  const char *v234; // [sp+E4h] [bp-518h]@535
  const char *v235; // [sp+E8h] [bp-514h]@535
  int v236[9]; // [sp+158h] [bp-4A4h]@652
  char v237; // [sp+17Ch] [bp-480h]@524
  //char v238; // [sp+1F8h] [bp-404h]@467
  char Str2; // [sp+238h] [bp-3C4h]@527
  struct Actor Dst; // [sp+2B8h] [bp-344h]@4
//  __int16 v241; // [sp+2D8h] [bp-324h]@4
 int i;
 unsigned int uControlID;

  dword_50CDC8 = 0;
  if ( !cClock1.dword_000004 )
  {
    pParty_global->uEyelevel = pParty_global->uDefaultEyelevel;
    pParty_global->uPartyHeight = pParty_global->uDefaultPartyHeight;
  }
  if ( dword_5C35C4 )
  {
    Actor_TotalReset(&Dst);
    memset(&Dst, 0, sizeof(struct Actor));
    dword_5B65D0 = dword_5C35C4;
    Dst.word_000020 = dword_5C35C4;
    Actor_InitializeDialogue(&Dst, 0);
    dword_5C35C4 = 0;
  }

  v0 = 1;
  v1 = "";
  while (dword_50CBD0.GetQueueMessage(&uControlID, &v209, &v215))
   {
      v2 = uControlID - 5;
      switch (uControlID)
      {
        case 5:
          dword_6A0D48 = v0;
          goto LABEL_92;
        case 0x1D:
          VideoPlayer_sub_4BF5B2((int)pVideoPlayer);
          struct_505898.byte_505992 = 1;
          sub_409C8B();
          goto LABEL_92;

          //Initiate Dialogue
          // v209: Actor ID to speak with
        case 0xA1:
          if ( !uActiveCharacter )
            goto LABEL_92;
          struct_576FE8.dword_000048 = v0;
      //   if ( dword_50CBD0.msg_count )
		//	   if  (dword_50CBD0.prm[0].msg_param3)
             //             dword_50CBD0.msg_count = 1;
		  dword_50CBD0.CutQueueTail();
          dword_5B65D0 = pActors[v209].word_000020;	   

          Actor_InitializeDialogue(&pActors[v209], v0);
          goto LABEL_92;


        case 0x86:
        case 0x87:
          if ( byte_6BE3C5 != 1 )
          {
            if ( !dword_4E28F8 )
            {
            //if ( dword_50CBD0.msg_count )
			//   if  (dword_50CBD0.prm[0].msg_param3)
             //             dword_50CBD0.msg_count = 1;
			dword_50CBD0.CutQueueTail();
              v210 = 0;
              v212 = uControlID - 134;

              for (i = 0; i < 2; ++i)
                if (pParty_global->pHiredNPCs[i].pNPCName)
                {
                  v7 = v210++;
                  TmpBuf[v7] = i;
                }

              v196 = 0;
              if (pNPCStats->dword_017FC4 > 0)
              {
                v211 = (int)pNPCStats->pNPCData2;
                do
                {
                  if ( *(_BYTE *)(v211 + 8) & 0x80 )
                  {
                    if (!pParty_global->pHiredNPCs[0].pNPCName || strcmp(*(const char **)v211, (char *)pParty_global->pHiredNPCs[0].pNPCName))
                    {
                     if (!pParty_global->pHiredNPCs[1].pNPCName || strcmp(*(const char **)v211, (char *)pParty_global->pHiredNPCs[1].pNPCName))
                      {
                        v8 = v210++;
                        TmpBuf[v8] = v196 + 2;
                      }
                    }
                  }
                  ++v196;
                  v211 += 76;
                }
                while ( v196 < pNPCStats->dword_017FC4);
              }
              if ( v212 + (unsigned __int8)pParty_global->byte_000709 < v210 )
              {
                Actor_TotalReset(&Dst);
                memset(&Dst, 0, sizeof(struct Actor));
                Dst.word_000020+= -1 - (unsigned __int8)pParty_global->byte_000709 - v212;
                v4 = (char *)&Dst;
//LABEL_33:
                Actor_InitializeDialogue((Actor *)v4, v0);
              }
            }
          }
          goto LABEL_92;
        case 0x51:
          sub_4BDB56();
          goto LABEL_92;
        case 0xAF:
          sub_4B2001(v209);
          goto LABEL_92;
        case 0x195:
          sub_4BCACC(v209, v3);
          goto LABEL_92;
        case 0x88:
          sub_4BC49B((void *)v209);
          goto LABEL_92;
        case 0x19A:
          sub_4B4224((void *)v209);
          goto LABEL_92;
        case 0x7C:
          if ( dword_6BE138 == 124 || v209 )
          {
            LODFile_Icons_LOD.LODFile_sub_40F9C5();
            LODFile_Icons_LOD.LODFile_sub_4114F2();
       //  if ( dword_50CBD0.msg_count )
			//   if  (dword_50CBD0.prm[0].msg_param3)
             //             dword_50CBD0.msg_count = 1;
			dword_50CBD0.CutQueueTail();
            GUIWindowDelete(pGUIWindow_CurrentMenu);
            dword_6A0D48 = 4;
LABEL_188:
            dword_4E28F8 = 0;
            struct_576FE8.dword_000044 = v0;
          }
          else
          {
            sub_44C175((char *)pGlobalTXT_LocalizationStrings[201], 2);
            AudioPlayer_sub_4AA306(pAudioPlayer, 20001, 0, 0, -1, 0, 0, 0, 0);
            dword_6BE138 = 124;
          }
LABEL_189:
          Class33_global3.PCXTexture_Release(); //RGBTexture_Release((int));
          goto LABEL_92;
        case 0x7D:
          LODFile_Icons_LOD.LODFile_sub_40F9C5();
          LODFile_Icons_LOD.LODFile_sub_4114F2();
       // if ( dword_50CBD0.msg_count )
			//   if  (dword_50CBD0.prm[0].msg_param3)
               //           dword_50CBD0.msg_count = 1;
		  dword_50CBD0.CutQueueTail();
          GUIWindowDelete(pGUIWindow_CurrentMenu);
          dword_4E28F8 = 12;
          sub_45E361(v0);
          goto LABEL_92;
        case 0x84:
          if ( dword_6BE138 == 132 || v209 )
          {
            LODFile_Icons_LOD.LODFile_sub_40F9C5();
            LODFile_Icons_LOD.LODFile_sub_4114F2();
       // if ( dword_50CBD0.msg_count )
			 //  if  (dword_50CBD0.prm[0].msg_param3)
                    //      dword_50CBD0.msg_count = 1;
			dword_50CBD0.CutQueueTail();
            GUIWindowDelete(pGUIWindow_CurrentMenu);
            dword_4E28F8 = 0;
            struct_576FE8.dword_000044 = v0;
            if ( !v209 )
              AudioPlayer_sub_4AA306(pAudioPlayer, 7, 0, 0, -1, 0, 0, 0, 0);
            dword_6A0D48 = 7;
          }
          else
          {
            sub_44C175((char *)pGlobalTXT_LocalizationStrings[82], 2);
            AudioPlayer_sub_4AA306(pAudioPlayer, 20001, 0, 0, -1, 0, 0, 0, 0);
            dword_6BE138 = 132;
          }
          goto LABEL_189;
        case 0x80:
          LODFile_Icons_LOD.LODFile_sub_40F9C5();
          LODFile_Icons_LOD.LODFile_sub_4114F2();
          GUIWindowDelete(pGUIWindow_CurrentMenu);
          dword_4E28F8 = 2;
          v179 = 0;
          v165 = 0;
          v158 = 8;
          goto LABEL_439;
        case 0xA2:
          v9 = dword_6A0C9C-- - 1 < 0;
          if ( v9 )
            dword_6A0C9C = 0;
          v180 = 0;
          v10 = 199;
          v166 = (int)pArrowUpBtn;
          goto LABEL_60;
        case 0xA3:
          ++dword_6A0C9C;
          if ( dword_6A0C9C >= v209 )
            dword_6A0C9C = v209 - 1;
          v180 = 0;
          v10 = 323;
          v166 = (int)pArrowDownBtn;
LABEL_60:
          v159 = 90;
          v154 = 17;
          v150 = 17;
          v11 = 215;
          goto LABEL_733;
        case 0xA6:
          v180 = 0;
          v10 = 302;
          v166 = (int)pCancelBtn;
          v11 = 350;
          v159 = 96;
          v154 = 42;
          v150 = 106;
          goto LABEL_733;
        case 0xA4:
          v180 = 0;
          v10 = 302;
          v166 = (int)pLoadSaveBtn;
          v11 = 241;
          v159 = 94;
          v154 = 42;
          v150 = 106;
          goto LABEL_733;
        case 0xA5:
          if ( pGUIWindow_CurrentMenu->dword_000040 == v0 )
            KeyboardController_sub_459ED1(pKeyboardController, 0);
          if ( dword_4E28F8 != 11 || dword_6A0CA0_indx != dword_6A0C9C + v209 )
          {
            v12 = dword_6A0C9C + v209;
            if ( dword_6BE138 == dword_6A0C9C + v209 )
            {
             /* if ( dword_50CBD0[0] < 40 )
              {
                dword_50CBD0[3 * dword_50CBD0[0] + 1] = 164;
                dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
                dword_50CBD0[3 * dword_50CBD0[0] + 3] = 0;
                v13 = dword_50CBD0 + 1;
                compile_error;//v15 = __SETO__(dword_50CBD0[0] + 1, 40);
                v14 = dword_50CBD0++ - 39 < 0;
                if ( v14 ^ v15 )
                {
                  dword_50CBD0[3 * v13 + 1] = 82;
                  dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
                  dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
                }  */
				dword_50CBD0.PutMessageToQueue(164,0,0);
				dword_50CBD0.PutMessageToQueue(82,0,0);
             // }
            }
            dword_6A0CA0_indx = v12;
            dword_6BE138 = v12;
          }
          else
          {
            KeyboardController_sub_459E5A(pKeyboardController, 0, 19, (int)pGUIWindow_CurrentMenu);
            if ( strcmp((const char *)&saves_hdr[dword_6A0CA0_indx].name1, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_EMPTY]) )
              strcpy((char *)pKeyboardController->pPressedKeysBuffer, (const char *)&saves_hdr[dword_6A0CA0_indx].name1);
            pKeyboardController->uNumKeysPressed = strlen((char *)pKeyboardController->pPressedKeysBuffer);
          }
          goto LABEL_92;
        case 0x52:
          if ( dword_69CF28[dword_6A0CA0_indx] )
          {
            /*v2 = */sub_45EE8A(dword_6A0CA0_indx);
            dword_6A0D48 = 3;
          }
          goto LABEL_189;
        case 0x53:
          if ( pGUIWindow_CurrentMenu->dword_000040 == v0 )
          {
            KeyboardController_sub_459ED1(pKeyboardController, 0);
            strcpy((char *)&saves_hdr[dword_6A0CA0_indx].name1, (char *)pKeyboardController->pPressedKeysBuffer);
          }
          v2 = sub_460078(dword_6A0CA0_indx);
          goto LABEL_189;
        case 0x7E:
          GUIWindowDelete(pGUIWindow_CurrentMenu);
          dword_4E28F8 = 11;
          sub_45E93E();
          goto LABEL_92;
        case 0x7F:
       // if ( dword_50CBD0.msg_count )
		//	   if  (dword_50CBD0.prm[0].msg_param3)
                 //         dword_50CBD0.msg_count = 1;
		  dword_50CBD0.CutQueueTail();
          GUIWindowDelete(pGUIWindow_CurrentMenu);
          struct_576FE8.dword_000048 = v0;
          dword_4E28F8 = 2;
		
          dword_507C60 = LODFile_Icons_LOD.LODFile_LoadTexture( "ControlBG", 2);
		  dword_507C70 = LODFile_Icons_LOD.LODFile_LoadTexture( "con_ArrL", 2);
          dword_507C74 = LODFile_Icons_LOD.LODFile_LoadTexture( "con_ArrR", 2);
#ifndef OLD_CODE
          dword_507C64_TextureID[2] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"con_16x");
          dword_507C64_TextureID[1] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"con_32x");
          dword_507C64_TextureID[0] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"con_Smoo");
          uTextureID_SoundLevels[9] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol00");
          uTextureID_SoundLevels[0] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol10");
          uTextureID_SoundLevels[1] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol20");
          uTextureID_SoundLevels[2] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol30");
          uTextureID_SoundLevels[3] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol40");
          uTextureID_SoundLevels[4] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol50");
          uTextureID_SoundLevels[5] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol60");
          uTextureID_SoundLevels[6] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol70");
          uTextureID_SoundLevels[7] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol80");
          uTextureID_SoundLevels[8] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol90");

#endif
#ifdef OLD_CODE
		  dword_507C64_TextureID[2] = LODFile_Icons_LOD.LODFile_LoadTexture("con_16x",2);
          dword_507C64_TextureID[1] = LODFile_Icons_LOD.LODFile_LoadTexture("con_32x",2);
          dword_507C64_TextureID[0] = LODFile_Icons_LOD.LODFile_LoadTexture("con_Smoo",2);
          uTextureID_SoundLevels[9] = LODFile_Icons_LOD.LODFile_LoadTexture("convol00",2);
          uTextureID_SoundLevels[0] = LODFile_Icons_LOD.LODFile_LoadTexture("convol10",2);
          uTextureID_SoundLevels[1] = LODFile_Icons_LOD.LODFile_LoadTexture("convol20",2);
          uTextureID_SoundLevels[2] = LODFile_Icons_LOD.LODFile_LoadTexture("convol30",2);
          uTextureID_SoundLevels[3] = LODFile_Icons_LOD.LODFile_LoadTexture("convol40",2);
          uTextureID_SoundLevels[4] = LODFile_Icons_LOD.LODFile_LoadTexture("convol50",2);
          uTextureID_SoundLevels[5] = LODFile_Icons_LOD.LODFile_LoadTexture("convol60",2);
          uTextureID_SoundLevels[6] = LODFile_Icons_LOD.LODFile_LoadTexture("convol70",2);
          uTextureID_SoundLevels[7] = LODFile_Icons_LOD.LODFile_LoadTexture("convol80",2);
          uTextureID_SoundLevels[8] = LODFile_Icons_LOD.LODFile_LoadTexture("convol90",2);

#endif
          dword_507C84 = LODFile_Icons_LOD.LODFile_LoadTexture( "option04", 2);
          dword_507CB0 = LODFile_Icons_LOD.LODFile_LoadTexture( "option03", 2);
          dword_507CB8 = LODFile_Icons_LOD.LODFile_LoadTexture( "option02", 2);
          dword_507CB4 = LODFile_Icons_LOD.LODFile_LoadTexture( "option01", 2);
          pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 6, 0, 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu,
            22,
            270,
            (dword_507C64_TextureID[2] != -1 ? LODFile_Icons_LOD.aLODHeaders[dword_507C64_TextureID[2]].uTextureWidth : 24),
            (dword_507C64_TextureID[2] != -1 ? LODFile_Icons_LOD.aLODHeaders[dword_507C64_TextureID[2]].uTextureHeight  : 26),
            v0,
            0,
            184,
            128,
            0,
            (unsigned char *)v1,
            0);
          GUIButtonCreate(pGUIWindow_CurrentMenu,
            93,
            270,
            (dword_507C64_TextureID[1] != -1 ? LODFile_Icons_LOD.aLODHeaders[dword_507C64_TextureID[1]].uTextureWidth : 24),
            (dword_507C64_TextureID[1] != -1 ? LODFile_Icons_LOD.aLODHeaders[dword_507C64_TextureID[1]].uTextureHeight : 26),
            v0,
            0,
            184,
            64,
            0,
            (unsigned char *)v1,
            0);
          GUIButtonCreate(pGUIWindow_CurrentMenu,
            164,
            270,
            *(_WORD *)(dword_507C64_TextureID[0] != -1 ? LODFile_Icons_LOD.aLODHeaders[dword_507C64_TextureID[0]].uTextureWidth  : 24),
            *(_WORD *)(dword_507C64_TextureID[0] != -1 ? LODFile_Icons_LOD.aLODHeaders[dword_507C64_TextureID[0]].uTextureHeight : 26),
            v0,
            0,
            184,
            0,
            0,
            (unsigned char *)v1,
            0);
          GUIButtonCreate(pGUIWindow_CurrentMenu,
            20,
            303,
            (dword_507CB4 != -1 ? LODFile_Icons_LOD.aLODHeaders[dword_507CB4].uTextureWidth  : 24),
            (dword_507CB4 != -1 ? LODFile_Icons_LOD.aLODHeaders[dword_507CB4].uTextureHeight : 26),
            v0,
            0,
            185,
            0,
            0,
            (unsigned char *)v1,
            0);
          GUIButtonCreate(pGUIWindow_CurrentMenu,
            128,
            303,
            (dword_507CB8 != -1 ? LODFile_Icons_LOD.aLODHeaders[dword_507CB8].uTextureWidth  : 24),
            (dword_507CB8 != -1 ? LODFile_Icons_LOD.aLODHeaders[dword_507CB8].uTextureHeight : 26),
            v0,
            0,
            187,
            0,
            0,
            (unsigned char *)v1,
            0);
          GUIButtonCreate(pGUIWindow_CurrentMenu,
            20,
            325,
            (dword_507CB0 != -1 ? LODFile_Icons_LOD.aLODHeaders[dword_507CB0].uTextureWidth  : 24),
            (dword_507CB0 != -1 ? LODFile_Icons_LOD.aLODHeaders[dword_507CB0].uTextureHeight : 26),
            v0,
            0,
            225,
            0,
            0,
            (unsigned char *)v1,
            0);
          GUIButtonCreate(pGUIWindow_CurrentMenu,
            128,
            325,
            *(_WORD *)(dword_507C84 != -1 ? LODFile_Icons_LOD.aLODHeaders[dword_507C84].uTextureWidth  : 24),
            *(_WORD *)(dword_507C84 != -1 ? LODFile_Icons_LOD.aLODHeaders[dword_507C84].uTextureHeight : 26),
            v0,
            0,
            226,
            0,
            0,
            (unsigned char *)v1,
            0);
          dword_50C9CC = GUIButtonCreate(pGUIWindow_CurrentMenu, 243, 162, 16, 16, v0, 0, 111, 4, 0, (unsigned char *)v1, &LODFile_Icons_LOD.aLODHeaders[dword_507C70],0);
          dword_50C9C8 = GUIButtonCreate(pGUIWindow_CurrentMenu, 435, 162, 16, 16, v0, 0, 111, 5, 0, (unsigned char *)v1, &LODFile_Icons_LOD.aLODHeaders[dword_507C74],0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 263, 162, 172, 17, v0, 0, 111, 0, 0, (unsigned char *)v1, 0);

          dword_50C9CC = GUIButtonCreate(pGUIWindow_CurrentMenu, 243, 216, 16, 16, v0, 0, 112, 4, 0, (unsigned char *)v1, &LODFile_Icons_LOD.aLODHeaders[dword_507C70],0);
          dword_50C9C8 = GUIButtonCreate(pGUIWindow_CurrentMenu, 435, 216, 16, 16, v0, 0, 112, 5, 0, (unsigned char *)v1, &LODFile_Icons_LOD.aLODHeaders[dword_507C74],0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 263, 216, 172, 17, v0, 0, 112, 0, 0, (unsigned char *)v1, 0);

          dword_50C9CC = GUIButtonCreate(pGUIWindow_CurrentMenu, 243, 270, 16, 16, v0, 0, 186, 4, 0, (unsigned char *)v1, &LODFile_Icons_LOD.aLODHeaders[dword_507C70],0);
          dword_50C9C8 = GUIButtonCreate(pGUIWindow_CurrentMenu, 435, 270, 16, 16, v0, 0, 186, 5, 0, (unsigned char *)v1, &LODFile_Icons_LOD.aLODHeaders[dword_507C74],0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 263, 270, 172, 17, v0, 0, 186, 0, 0, (unsigned char *)v1, 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 241, 302, 214, 40, v0, 0, 113, 0, 0, pGlobalTXT_LocalizationStrings[619], 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 19, 140, 214, 40, v0, 0, 415, 0, 75, (unsigned char *)v1, 0);
          v181 = 0;
          v167 = v1;
          v160 = 86;
          v155 = 0;
          v151 = 421;
          v148 = 0;
          v146 = v0;
          v143 = 40;
          v141 = 214;
          v139 = 194;
          v137 = 19;
          goto LABEL_117;
        case 0x19F:
      // if ( dword_50CBD0.msg_count )
			//   if  (dword_50CBD0.prm[0].msg_param3)
               //           dword_50CBD0.msg_count = 1;
		  dword_50CBD0.CutQueueTail();
          GUIWindowDelete(pGUIWindow_CurrentMenu);
          struct_576FE8.dword_000048 = 1;
          dword_4E28F8 = 26;
          dword_507BF4 = LODFile_Icons_LOD.LODFile_LoadTexture( "optkb", 2);
          dword_507BF8 = LODFile_Icons_LOD.LODFile_LoadTexture( "optkb_h", 2);
          dword_507BFC = LODFile_Icons_LOD.LODFile_LoadTexture( "resume1", 2);
          dword_507C00 = LODFile_Icons_LOD.LODFile_LoadTexture( "optkb_1", 2);
          dword_507C04 = LODFile_Icons_LOD.LODFile_LoadTexture( "optkb_2", 2);
          pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 105, 0, 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 241, 302, 214, 40, 1, 0, 113, 0, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 19, 302, 108, 20, 1, 0, 416, 0, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 127, 302, 108, 20, 1, 0, 417, 0, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 127, 324, 108, 20, 1, 0, 418, 0, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 19, 324, 108, 20, 1, 0, 127, 0, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 129, 148, 70, 19, 1, 0, 419, 0, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 129, 167, 70, 19, 1, 0, 419, 1, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 129, 186, 70, 19, 1, 0, 419, 2, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 129, 205, 70, 19, 1, 0, 419, 3, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 129, 224, 70, 19, 1, 0, 419, 4, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 129, 243, 70, 19, 1, 0, 419, 5, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 129, 262, 70, 19, 1, 0, 419, 6, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 350, 148, 70, 19, 1, 0, 419, 7, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 350, 167, 70, 19, 1, 0, 419, 8, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 350, 186, 70, 19, 1, 0, 419, 9, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 350, 205, 70, 19, 1, 0, 419, 10, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 350, 224, 70, 19, 1, 0, 419, 11, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 350, 243, 70, 19, 1, 0, 419, 12, 0, (unsigned char *)"", 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 350, 262, 70, 19, 1, 0, 419, 13, 0, (unsigned char *)"", 0);
          dword_506E68 = -1;
          dword_506F08 = 1;
          memset(byte_506E6C, 0, 0x1Cu);
          byte_506E6C[14] = 0;
          memcpy(dword_506E90, pKeyboardController->array_00000C_vkeys, 30 * 4);
          goto LABEL_90;
        default:
          goto LABEL_92;
        case 0x1A3:
          if ( dword_506E68 != -1 )
            goto LABEL_623;
          v16 = v209;
          if ( dword_506F08 != v0 )
            v16 = v209 + 14;
          dword_506E68 = v16;
          KeyboardController_sub_459E5A(pKeyboardController, 0, v0, (int)pGUIWindow_CurrentMenu);
          goto LABEL_92;
        case 0x1A2:
          v213 = 1;
          KeyboardController_InitalizeKeys(pKeyboardController);
          v210 = 0;
          do
          {
            v17 = KeyboardController_sub_459C82_LooksLikeBindKey(pKeyboardController, v210);
            if ( v17 != dword_506E90[v210] )
            {
              if ( v213 )
              {
                v18 = KeyboardController_sub_459C82_LooksLikeBindKey(pKeyboardController, v210);
                sub_41B4E1(LOBYTE(dword_506E90[v210]), v18, v0);
                v213 = 0;
              }
              else
              {
                v19 = KeyboardController_sub_459C82_LooksLikeBindKey(pKeyboardController, v210);
                sub_41B4E1(LOBYTE(dword_506E90[v210]), v19, 0);
              }
            }
            dword_506E90[v210] = KeyboardController_sub_459C82_LooksLikeBindKey(pKeyboardController, v210);
            v20 = v210++;
            compile_error;//v22 = __SETO__(v210, 28);
            v21 = v210 - 28 < 0;
            *((_BYTE *)byte_506E6C + v20) = 0;
          }
          while ( v21 ^ v22 );
          v182 = 0;
          v168 = 0;
          v161 = 0;
          v156 = 0;
          v152 = -1;
          v149 = 0;
          v147 = 0;
          v144 = 219;
          goto LABEL_721;
        case 0x1A0:
          dword_506F08 = v0;
          goto LABEL_92;
        case 0x1A1:
          dword_506F08 = 2;
          goto LABEL_92;
        case 0x1A5:
         // if ( dword_50CBD0[0] )
          //     dword_50CBD0[0] = dword_50CBD0[3] != 0;
		  dword_50CBD0.CutQueueTail();
          GUIWindowDelete(pGUIWindow_CurrentMenu);
          struct_576FE8.dword_000048 = v0;
          dword_4E28F8 = 28;
          dword_507C10 = LODFile_Icons_LOD.LODFile_LoadTexture( "optvid", 2);
          dword_507C14 = LODFile_Icons_LOD.LODFile_LoadTexture( "opvdH-bs", 2);
          dword_507C18 = LODFile_Icons_LOD.LODFile_LoadTexture( "opvdH-cl", 2);
          dword_507C1C = LODFile_Icons_LOD.LODFile_LoadTexture( "opvdH-tn", 2);
          dword_507C20 = LODFile_Icons_LOD.LODFile_LoadTexture( "con_ArrL", 2);
          dword_507C24 = LODFile_Icons_LOD.LODFile_LoadTexture( "con_ArrR", 2);
#ifndef OLD_CODE
          uTextureID_GammaPositions[0] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol10");
          uTextureID_GammaPositions[1] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol20");
          uTextureID_GammaPositions[2] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol30");
          uTextureID_GammaPositions[3] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol40");
          uTextureID_GammaPositions[4] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol50");
          uTextureID_GammaPositions[5] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol60");
          uTextureID_GammaPositions[6] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol70");
          uTextureID_GammaPositions[7] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol80");
          uTextureID_GammaPositions[8] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol90");
          uTextureID_GammaPositions[9] = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"convol00");
#endif
#ifdef OLD_CODE
		  uTextureID_GammaPositions[0] = LODFile_Icons_LOD.LODFile_LoadTexture("convol10",2);
          uTextureID_GammaPositions[1] = LODFile_Icons_LOD.LODFile_LoadTexture("convol20",2);
          uTextureID_GammaPositions[2] = LODFile_Icons_LOD.LODFile_LoadTexture("convol30",2);
          uTextureID_GammaPositions[3] = LODFile_Icons_LOD.LODFile_LoadTexture("convol40",2);
          uTextureID_GammaPositions[4] = LODFile_Icons_LOD.LODFile_LoadTexture("convol50",2);
          uTextureID_GammaPositions[5] = LODFile_Icons_LOD.LODFile_LoadTexture("convol60",2);
          uTextureID_GammaPositions[6] = LODFile_Icons_LOD.LODFile_LoadTexture("convol70",2);
          uTextureID_GammaPositions[7] = LODFile_Icons_LOD.LODFile_LoadTexture("convol80",2);
          uTextureID_GammaPositions[8] = LODFile_Icons_LOD.LODFile_LoadTexture("convol90",2);
          uTextureID_GammaPositions[9] = LODFile_Icons_LOD.LODFile_LoadTexture("convol00",2);
#endif
          dword_507C50 = LODFile_Icons_LOD.LODFile_LoadTexture( "opvdG-bs", 2);
          dword_507C54 = LODFile_Icons_LOD.LODFile_LoadTexture( "opvdG-cl", 2);
          dword_507C58 = LODFile_Icons_LOD.LODFile_LoadTexture( "opvdG-tn", 2);
          pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 106, 0, 0);
          GUIButtonCreate(pGUIWindow_CurrentMenu, 241, 302, 214, 40, v0, 0, 113, 0, 0, (unsigned char *)v1, 0);
          if ( pD3DRenderer->pRenderD3D3 )
          {
            GUIButtonCreate(pGUIWindow_CurrentMenu, 19, 280, 214, 18, v0, 0, 422, 0, 0, (unsigned char *)v1, 0);
            GUIButtonCreate(pGUIWindow_CurrentMenu, 19, 302, 214, 18, v0, 0, 423, 0, 0, (unsigned char *)v1, 0);
            GUIButtonCreate(pGUIWindow_CurrentMenu, 19, 324, 214, 18, v0, 0, 424, 0, 0, (unsigned char *)v1, 0);
          }
          if ( !pD3DRenderer->dword_040058 )
          {
            v0 = 1;
            if (pD3DRenderer->IsGammaControlSupported())
            {
              dword_50C9CC = 
				 GUIButtonCreate(pGUIWindow_CurrentMenu,  21, 161, 16, 16, 1, 0, 425, 4, 0, (unsigned char *)v1, &LODFile_Icons_LOD.aLODHeaders[dword_507C20]);
              dword_50C9C8 = 
				 GUIButtonCreate(pGUIWindow_CurrentMenu, 213, 161, 16, 16, 1, 0, 425, 5, 0, (unsigned char *)v1, &LODFile_Icons_LOD.aLODHeaders[dword_507C24]);
              v181 = 0;
              v167 = v1;
              v160 = 0;
              v155 = 0;
              v151 = 425;
              v148 = 0;
              v146 = 1;
              v143 = 18;
              v141 = 170;
              v139 = 162;
              v137 = 42;
LABEL_117:
              GUIButtonCreate(pGUIWindow_CurrentMenu, v137, v139, v141, v143, v146, v148, v151, v155, v160, (unsigned char *)v167, &LODFile_Icons_LOD.aLODHeaders[v181],0);
            }
          }
          goto LABEL_92;
        case 0x1A9:
          if ( v209 == 4 )
          {
            v23 = dword_4E2900_GammaPos-- - 1 < 0;
            if ( v23 )
            {
              dword_4E2900_GammaPos = 0;
              goto LABEL_128;
            }
            v25 = (double)dword_4E2900_GammaPos * 0.10000000000000001 + 0.59999999999999998;
            GammaController_sub_44F4D9(pGame->pGammaController, v25);
            v183 = v0;
            //v169 = (int)dword_50C9CC;
            v162 = 90;
            v157 = 0;
            v153 = 0;
            v24 = 21;
            GUIWindowCreate(v24, 161, v153, v157, v162,  dword_50C9CC, v183);
            goto LABEL_128;							 
          }
          if ( v209 == 5 )
          {
            ++dword_4E2900_GammaPos;
            if ( dword_4E2900_GammaPos <= 9 )
            {
              v26 = (double)dword_4E2900_GammaPos * 0.10000000000000001 + 0.59999999999999998;
              GammaController_sub_44F4D9(pGame->pGammaController, v26);
              v24 = 213;
              v183 = v0;
             // v169 = (int)dword_50C9C8;
              v162 = 90;
              v157 = 0;
              v153 = 0;
              GUIWindowCreate(v24, 161, v153, v157, v162,  dword_50C9C8, v183);
              goto LABEL_128;							 
            }
            dword_4E2900_GammaPos = 9;
          }
          else
          {
            dword_4E2900_GammaPos = (*(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v219) - 42) / 17;
            v27 = (double)dword_4E2900_GammaPos * 0.10000000000000001 + 0.59999999999999998;
            GammaController_sub_44F4D9(pGame->pGammaController, v27);
          }
LABEL_128:
          v182 = 0;
          v168 = 0;
          v161 = 0;
          v156 = 0;
          v152 = -1;
          v149 = 0;
          v147 = 0;
          v144 = 21;
          goto LABEL_721;
        case 0x1A6:
          Game_sub_435694((int)pGame, 32);
          goto LABEL_92;
        case 0x1A7:
          pD3DRenderer->bUseColoredLights = pD3DRenderer->bUseColoredLights == 0;
          goto LABEL_92;
        case 0x1A8:
          pD3DRenderer->bTinting = pD3DRenderer->bTinting == 0;
          goto LABEL_92;
        case 0x70:
          if ( v209 == 4 )
          {
            --uMusicVolimeMultiplier;
            if ( uMusicVolimeMultiplier < 1 )
              uMusicVolimeMultiplier = 0;
            v184 = v0;
            v28 = 243;
           // v170 = (int);
            GUIWindowCreate(v28, 216, 0, 0, 90, dword_50C9CC, v184);
            goto LABEL_143;
          }
          if ( v209 == 5 )
          {
            ++uMusicVolimeMultiplier;
            if ( uMusicVolimeMultiplier > 9 )
              uMusicVolimeMultiplier = 9;
            v184 = v0;
            v28 = 435;
            //v170 = (int)dword_50C9C8;
            GUIWindowCreate(v28, 216, 0, 0, 90, dword_50C9C8, v184);
            goto LABEL_143;
          }
          uMusicVolimeMultiplier = (*(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v218) - 263) / 17;
          if ( uMusicVolimeMultiplier > 9 )
            uMusicVolimeMultiplier = 9;
LABEL_143:
          if ( uMusicVolimeMultiplier )
            AudioPlayer_sub_4AA306(pAudioPlayer, 217, -1, 0, -1, 0, 0, (signed __int64)(aMusicVolumeLevels[uMusicVolimeMultiplier] * 64.0), 0);
          AudioPlayer_SetVolume(pAudioPlayer, aMusicVolumeLevels[uMusicVolimeMultiplier] * 64.0);
          goto LABEL_92;
        case 0x6F:
          if ( v209 == 4 )
          {
            --uSoundVolumeMultiplier;
            if ( uSoundVolumeMultiplier < 1 )
              uSoundVolumeMultiplier = 0;
            v185 = v0;
            v30 = 243;
            //v171 = (int);
            GUIWindowCreate(v30, 162, 0, 0, 90, dword_50C9CC, v185);
            goto LABEL_157;
          }
          if ( v209 == 5 )
          {
            ++uSoundVolumeMultiplier;
            if ( uSoundVolumeMultiplier > 8 )
              uSoundVolumeMultiplier = 9;
            v185 = v0;
            v30 = 435;
            //v171 = (int)dword_50C9C8;
            GUIWindowCreate(v30, 162, 0, 0, 90, dword_50C9C8, v185);
            goto LABEL_157;
          }
          uSoundVolumeMultiplier = (*(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v223) - 263) / 17;
          if ( uSoundVolumeMultiplier > 8 )
            uSoundVolumeMultiplier = 9;
LABEL_157:
          AudioPlayer_sub_4AA214(pAudioPlayer, (signed __int64)(aMusicVolumeLevels[uSoundVolumeMultiplier] * 128.0));
          v182 = 0;
          v168 = 0;
          v161 = 0;
          v156 = 0;
          v152 = -1;
          v149 = 0;
          v147 = -1;
          v144 = 218;
          goto LABEL_721;
        case 0xE2:
          dword_6BE380 = dword_6BE380 == 0;
          goto LABEL_92;
        case 0xE1:
          dword_6BE37C = dword_6BE37C == 0;
          goto LABEL_92;
        case 0xB9:
          dword_6BE374_WalkSoundFlag = dword_6BE374_WalkSoundFlag == 0;
          goto LABEL_92;
        case 0xBB:
          dword_6BE378_ShowDamageFlag = dword_6BE378_ShowDamageFlag == 0;
          goto LABEL_92;
        case 0xBA:
          if ( v209 == 4 )
          {
            --uVoicesVolumeMultiplier;
            if ( uVoicesVolumeMultiplier < 1 )
              uVoicesVolumeMultiplier = 0;
            v186 = v0;
            v31 = 243;
           // v172 = (int);
            GUIWindowCreate(v31, 270, 0, 0, 90, dword_50C9CC, v186);
            goto LABEL_173;
          }
          if ( v209 == 5 )
          {
            ++uVoicesVolumeMultiplier;
            if ( uVoicesVolumeMultiplier > 8 )
              uVoicesVolumeMultiplier = 9;
            v186 = v0;
            v31 = 435;
            //v172 = (int)dword_50C9C8;
            GUIWindowCreate(v31, 270, 0, 0, 90, dword_50C9C8, v186);
            goto LABEL_173;
          }
          uVoicesVolumeMultiplier = (*(_DWORD *)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v221) - 263) / 17;
          if ( uVoicesVolumeMultiplier > 8 )
            uVoicesVolumeMultiplier = 9;
LABEL_173:
          if ( !uVoicesVolumeMultiplier )
            goto LABEL_92;
          v182 = 0;
          v168 = (signed __int64)(aMusicVolumeLevels[uVoicesVolumeMultiplier] * 128.0);
          v161 = 0;
          v156 = 0;
          v152 = -1;
          v149 = 0;
          v147 = -1;
          v144 = 5788;
          goto LABEL_721;
        case 0xB8:
          if ( v209 )
            pParty_global->sRotationY = v209 * pParty_global->sRotationY / v209;
          uTurnSpeed = v209;
          goto LABEL_92;
        case 0x83:
          if ( !bUseLoResSprites )
          {
            byte_6BE388_graphicsmode = v209;
LABEL_184:
            sub_4666D5();
            goto LABEL_92;
          }
          if ( v209 )
          {
            if ( v209 == 1 )
            {
              byte_6BE388_graphicsmode = 0;
            }
            else
            {
              if ( v209 != 2 )
                goto LABEL_92;
              byte_6BE388_graphicsmode = 1;
            }
            goto LABEL_184;
          }
          sub_4141CA(dword_722494, 0);
          goto LABEL_92;
        case 0x7B:
          GUIWindowDelete(pGUIWindow_CurrentMenu);
          //class24_sub_426363();
		  cClock1.clock_sub_426363();
          goto LABEL_188;


        case 0xC8:
          // open questbook
          if ( dword_50CBD0.msg_count )
			   if  (dword_50CBD0.prm[0].msg_param3)
                          dword_50CBD0.msg_count = 1;
          if ( dword_4E28F8 )
            GUIWindowDelete(pGUIWindow_CurrentMenu);
          cClock1.clock_fn1();
          AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
          pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 9, (GUIButton*)uControlID, 0);
          ptr_507BE0 = GUIWindowCreate(493, 355, 0, 0, 99, pBtn_Game_Quests, 0);
          byte_50794A = 0;
          goto LABEL_92;

        case 0xC9:
          // open autonotes
         //if ( dword_50CBD0.msg_count )
			//   if  (dword_50CBD0.prm[0].msg_param3)
               //           dword_50CBD0.msg_count = 1;
		  dword_50CBD0.CutQueueTail();
          if ( dword_4E28F8 )
            GUIWindowDelete(pGUIWindow_CurrentMenu);
          cClock1.clock_fn1();
          AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
          pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 9, (GUIButton*)uControlID, 0);
          ptr_507BE0 = GUIWindowCreate(527, 353, 0, 0, 99, pBtn_Game_Autonotes, 0);
          byte_507949 = 0;
          goto LABEL_92;
        case 0xCA:
          //if ( dword_50CBD0.msg_count )
			//   if  (dword_50CBD0.prm[0].msg_param3)
            //             dword_50CBD0.msg_count = 1;
			dword_50CBD0.CutQueueTail();
          if ( dword_4E28F8 )
            GUIWindowDelete(pGUIWindow_CurrentMenu);
          cClock1.clock_fn1();
          struct_576FE8.dword_000030 = pParty_global->sPartyPosX;
          struct_576FE8.dword_000034 = pParty_global->sPartyPosY;
          AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
          v32 = (int)GUIWindowCreate(0, 0, 640, 480, 9, (GUIButton*)uControlID, 0);
          v33 = 353;
          v34 = 546;
          v187 = 0;
          v173 = (int)pBtn_Game_Maps;
          goto LABEL_210;
        case 0xCB:
        // if ( dword_50CBD0.msg_count )
		//	   if  (dword_50CBD0.prm[0].msg_param3)
             //             dword_50CBD0.msg_count = 1;
			dword_50CBD0.CutQueueTail();
          if ( dword_4E28F8 )
            GUIWindowDelete(pGUIWindow_CurrentMenu);
          cClock1.clock_fn1();
          AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
          v32 = (int)GUIWindowCreate(0, 0, 640, 480, 9, (GUIButton*)uControlID, 0);
          v33 = 354;
          v34 = 570;
          v187 = 0;
          v173 = (int)pBtn_Game_Calendar;
LABEL_210:
          pGUIWindow_CurrentMenu = (GUIWindow *)v32;
          ptr_507BE0 = GUIWindowCreate(v34, v33, 0, 0, 99, pBtn_Game_Calendar, v187);
          goto LABEL_92;
        case 0xE0:
         // if ( dword_50CBD0.msg_count )
		//	   if  (dword_50CBD0.prm[0].msg_param3)
         //                 dword_50CBD0.msg_count = 1;
			dword_50CBD0.CutQueueTail();
          if ( dword_4E28F8 )
            GUIWindowDelete(pGUIWindow_CurrentMenu);
          cClock1.clock_fn1();
          AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
          pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 9, (GUIButton*)uControlID, 0);
          ptr_507BE0 = GUIWindowCreate(600, 361, 0, 0, 99, pBtn_Game_Inventory, 0);
          byte_507948 = 0;
          goto LABEL_92;
        case 0x71:
          sub_4356FF();
        //  if ( dword_50CBD0.msg_count )
		//	   if  (dword_50CBD0.prm[0].msg_param3)
             //             dword_50CBD0.msg_count = 1;
		  dword_50CBD0.CutQueueTail();
          if ( dword_4E28F8 > 15 )
          {
            if ( dword_4E28F8 >= 17 && (dword_4E28F8 <= 18 || dword_4E28F8 == 104) )
            {
LABEL_229:
              if ( dword_50CDC8 )
                goto LABEL_232;
              sub_42FC15();
              goto LABEL_231;
            }
          }
          else
          {
            if ( dword_4E28F8 >= 14 || dword_4E28F8 == 4 || dword_4E28F8 == 10 )
              goto LABEL_229;
            if ( dword_4E28F8 == 13 && !dword_50CDC8 && !dword_5C35C8 )
            {
              sub_42FC15();
              dword_5C35C8 = 0;
LABEL_231:
              v209 = v0;
              goto LABEL_232;
            }
          }
LABEL_232:
          if ( !ptr_507BDC )
          {
            Render_ClearZBuffer(pD3DRenderer, 0, 479);
            struct_576FE8.dword_000044 = v0;
            struct_576FE8.dword_000048 = v0;
            if ( dword_4E28F8 )
            {
              if ( dword_4E28F8 > 103 )
              {
                if ( dword_4E28F8 == 104 )
                  goto LABEL_321;
              }
              else
              {
                if ( dword_4E28F8 < 100 )
                {
                  v35 = dword_4E28F8 - 1;
                  switch ( dword_4E28F8 )
                  {
                    case 23:
                      LODFile_Icons_LOD.LODFile_sub_4114F2();
                      if ( dword_50C0C4 )
                      {
                        uActiveCharacter = dword_50C0C4;
                        uActiveCharacter = Party_sub_49370F(pParty_global);
                        dword_50C0C4 = 0;
                        if ( pParty_global->dword_00087C )
                          sub_40471C(&unk_4F8858);
                        dword_50C9D0 = 0;
                        dword_50C9D4 = 0;
                        dword_50C9D8 = 0;
                      }
                      if ( ptr_50C9A4 )
                      {
                        if ( *(_DWORD *)ptr_50C9A4 )
                        {
                          *(_BYTE *)(ptr_50C9A4 + 20) &= 0xFu;
                          dword_50C9A8 = 0;
                          ptr_50C9A4 = 0;
                        }
                      }
                      goto LABEL_322;
                    case 3:
                      GUIWindowDelete(ptr_507BE0);
                      sub_45E006();
                      ptr_507BE0 = 0;
                      cClock1.clock_sub_426363();
                      goto LABEL_322;
                    case 11:
                    case 12:
                      LODFile_Icons_LOD.LODFile_sub_4114F2();
                      v35 = (int)sub_45E006();
                      goto LABEL_291;
                    case 15:
                      dword_4E28F8 = 10;
                      goto LABEL_92;
                    case 10:
                      v36 = dword_507BB8;
                      goto LABEL_249;
                    case 25:
                      v36 = dword_507BC8;
LABEL_249:
                      GUIWindowDelete((GUIWindow *)v36);
                      LODFile_Icons_LOD.LODFile_sub_4114F2();
                      dword_4E28F8 = 0;
                      struct_576FE8.dword_000044 = v0;
                      cClock1.clock_sub_426363();
                      goto LABEL_92;
                    case 2:
                      v197 = (signed int)&dword_507C60;
                      do
                      {
                        if ( *(_DWORD *)v197 )
                          cTexture_Free(&LODFile_Icons_LOD.aLODHeaders[v197]);
                        v197 += 4;
                      }
                      while ( v197 < (signed int)&dword_507CBC );
                      memset(&dword_507C60, 0, 0x5Cu);
                      LODFile_Icons_LOD.LODFile_sub_40F9C5();
                      RegistryWriteInt("soundflag", uSoundVolumeMultiplier);
                      RegistryWriteInt("musicflag", uMusicVolimeMultiplier);
                      RegistryWriteInt("CharVoices", uVoicesVolumeMultiplier);
                      RegistryWriteInt("WalkSound", dword_6BE374_WalkSoundFlag);
                      RegistryWriteInt("ShowDamage", dword_6BE378_ShowDamageFlag);
                      RegistryWriteInt("graphicsmode", (unsigned __int8)byte_6BE388_graphicsmode);
                      RegistryWriteInt("valAlwaysRun", dword_6BE37C);
                      RegistryWriteInt("FlipOnExit", dword_6BE380);
                      if ( !uTurnSpeed )
                      {
                        v188 = 3;
                        goto LABEL_261;
                      }
                      if ( uTurnSpeed == 64 )
                      {
                        v188 = 2;
LABEL_261:
                        v37 = v188;
                        goto LABEL_262;
                      }
                      v35 = uTurnSpeed - 128;
                      if ( uTurnSpeed != 128 )
                        goto LABEL_291;
                      v37 = v0;
LABEL_262:
                      v38 = "TurnDelta";
LABEL_263:
                      v35 = RegistryWriteInt(v38, v37);
LABEL_291:
                    Class33_global3.PCXTexture_Release();
                      break;
                    case 1:
                      LODFile_Icons_LOD.LODFile_sub_40F9C5();
                      LODFile_Icons_LOD.LODFile_sub_4114F2();
                      LODFile_Icons_LOD.LODFile_sub_40F9C5();
                      v35 =0;
					  LODFile_Icons_LOD.LODFile_sub_4114F2();
                      goto LABEL_291;
                    case 28:
                      if ( pD3DRenderer->pRenderD3D3 )
                      {
                        RegistryWriteInt("Colored Lights", pD3DRenderer->bUseColoredLights);
                        RegistryWriteInt("Tinting", pD3DRenderer->bTinting);
                        v35 = RegistryWriteInt("Bloodsplats", (*(_BYTE *)(LODWORD(pGame) + 3620) >> 5) & 1);
                      }
                      if ( pD3DRenderer->dword_040058 )
                        goto LABEL_291;
                      v37 = dword_4E2900_GammaPos;
                      v38 = "GammaPos";
                      goto LABEL_263;
                    case 26:
                      v213 = 1;
                      v39 = 0;
                      while ( *((_BYTE *)byte_506E6C + v39) != 1 )
                      {
                        ++v39;
                        if ( v39 >= 28 )
                        {
                          v198 = (signed int)&dword_507BF4;
                          do
                          {
                            if ( *(_DWORD *)v198 )
                              cTexture_Free(&LODFile_Icons_LOD.aLODHeaders[v198]);
                            v198 += 4;
                          }
                          while ( v198 < (signed int)&dword_507C08 );
                          memset(&dword_507BF4, 0, 0x14u);
                          LODFile_Icons_LOD.LODFile_sub_40F9C5();
                          v210 = 0;
                          do
                          {
                            v40 = KeyboardController_sub_459C82_LooksLikeBindKey(pKeyboardController, v210);
                            if ( v40 != dword_506E90[v210] )
                            {
                              if ( v213 )
                              {
                                v41 = KeyboardController_sub_459C82_LooksLikeBindKey(pKeyboardController, v210);
                                sub_41B4E1(v41, LOBYTE(dword_506E90[v210]), v0);
                                v213 = 0;
                              }
                              else
                              {
                                v42 = KeyboardController_sub_459C82_LooksLikeBindKey(pKeyboardController, v210);
                                sub_41B4E1(v42, LOBYTE(dword_506E90[v210]), 0);
                              }
                            }
                            if ( v210 && v210 != 2 && v210 != 3 && v210 != v0 && v210 != 25 && v210 != 26 )
                              v189 = v0;
                            else
                              v189 = 0;
                            KeyboardController_InitalizeKey(pKeyboardController, v210, dword_506E90[v210], v189);
                            ++v210;
                          }
                          while ( v210 < 28 );
                          v35 = sub_45A960((char *)pKeyboardController, v43);
                          goto LABEL_291;
                        }
                      }
                      goto LABEL_623;
                    case 5:
                      if ( dword_506F14 )
                      {
                        sub_4938D1(dword_506F18);
                        qword_AD2B48 = 0i64;
                        qword_AD100C = 0i64;
                        qword_ACF4D0 = 0i64;
                        qword_ACD994 = 0i64;
                      }
                      cTexture_Free((cTexture *)dword_507BAC);
                      cTexture_Free((cTexture *)dword_507BB0);
                      dword_507BB0 = 0;
                      dword_507BAC = 0;
                      LODFile_Icons_LOD.LODFile_sub_40F9C5();
                      LODFile_Icons_LOD.LODFile_sub_4114F2();
                      dword_506F18 = 0;
                      dword_506F14 = 0;
                      dword_507B94 = v0;
                      goto LABEL_322;
                    case 14:
                      GUIWindowDelete(pGUIWindow_CurrentMenu);
                      dword_4E28F8 = 13;
                      LODFile_Icons_LOD.LODFile_sub_4114F2();
                      goto LABEL_92;
                    case 13:
                      if ( uDialogueType )
                        uDialogueType = 0;
                      if ( dword_6A0D48 == 2 )
                      {
                        while ( sub_4BD8B5() )
                          ;
                      }
                      else
                      {
                        if ( sub_4BD8B5() )
                          goto LABEL_92;
                      }
                      sub_4B1D27();
                      AudioPlayer_sub_4AA306(pAudioPlayer, 7, 814, 0, -1, 0, 0, 0, 0);
                      CVideoPlayer_UnloadAll(pVideoPlayer);
                      pGUIWindow_CurrentMenu = ptr_507BC0;
                      goto LABEL_322;
                    case 18:
                      if ( dword_591160 == 153 )
                        sub_4B1E92(153, 3);
                      CVideoPlayer_UnloadAll(pVideoPlayer);
                      goto LABEL_306;
                    case 4:
LABEL_306:
                      if ( dword_5B65CC )
                      {
                        pParty_global->byte_000709 = 0;
                        pNPCStats->pNPCData2[dword_5B65CC].dword_000008 &= 0x7Fu;
                        sub_44A56A();
                        struct_576FE8.dword_000044 = v0;
                        dword_5B65CC = 0;
                      }
                      goto LABEL_317;
                    case 19:
                      memset(&byte_5C3428, 0, 0xC8u);
                      sub_4452BB();
                      goto LABEL_317;
                    case 17:
                      if ( pParty_global->sPartyPosX < -22528 )
                        pParty_global->sPartyPosX = -22528;
                      if ( pParty_global->sPartyPosX > 22528 )
                        pParty_global->sPartyPosX = 22528;
                      if ( pParty_global->sPartyPosY < -22528 )
                        pParty_global->sPartyPosY = -22528;
                      if ( pParty_global->sPartyPosY > 22528 )
                        pParty_global->sPartyPosY = 22528;
                      goto LABEL_317;
                    case 16:
                      CVideoPlayer_UnloadAll(pVideoPlayer);
                      goto LABEL_92;
                    case 7:
                      goto LABEL_319;
                    default:
                      goto LABEL_322;
                  }
                  goto LABEL_322;
                }
LABEL_319:
                sub_4196A0();
                sub_419379();
LABEL_321:
                LODFile_Icons_LOD.LODFile_sub_4114F2();
              }
LABEL_322:
              if ( ptr_507BD4 )
              {
                if ( dword_4E28F8 == 7 )
                {
                  GUICursor_SetCursorBitmap(pGame->pGUICursor, "MICON2");
                }
                else
                {
                  GUIWindowDelete(ptr_507BD4);
                  ptr_507BD4 = NULL;
                  GUICursor_SetCursorBitmap(pGame->pGUICursor, "MICON1");
                  dword_5C35B8_Some_GetTickCount_timer = 0;
                  dword_50C9A0 = false;
                  sub_4356FF();
                }
              }
              if ( uActiveCharacter < v0 || uActiveCharacter > 4 )
                uActiveCharacter = Party_sub_49370F(pParty_global);
              GUIWindowDelete(pGUIWindow_CurrentMenu);
              if ( pGUIWindow_CurrentMenu == ptr_507BC0)
                ptr_507BC0 = 0;
              pGUIWindow_CurrentMenu = 0;
              cClock1.clock_sub_426363();
              dword_4E28F8 = 0;
              struct_576FE8.dword_000044 = v0;
              LODFile_Icons_LOD.sub_4355F7();
              goto LABEL_92;
            }
            v44 = ptr_507BD4;
            if ( !ptr_507BD4 )
            {
              dword_6BE138 = -1;
              GUIWindowCreate(602, 450, 0, 0, 90, pBtn_Game_Options, v0);
              cClock1.clock_fn1();
              AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
              ++LODFile_Icons_LOD.uTexturePacksCount;
              dword_4E28F8 = v0;
              if ( !LODFile_Icons_LOD.uPrevLoadedFiles )
                LODFile_Icons_LOD.uPrevLoadedFiles = LODFile_Icons_LOD.uNumLoadedFiles;
              pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 3, 0, 0);
              dword_507944 = LODFile_Icons_LOD.LODFile_LoadTexture( "options", 2);
              dword_507940 = LODFile_Icons_LOD.LODFile_LoadTexture( "new1", 2);
              dword_50793C = LODFile_Icons_LOD.LODFile_LoadTexture( "load1", 2);
              dword_507938 = LODFile_Icons_LOD.LODFile_LoadTexture( "save1", 2);
              dword_507934 = LODFile_Icons_LOD.LODFile_LoadTexture( "controls1", 2);
              dword_507930 = LODFile_Icons_LOD.LODFile_LoadTexture( "resume1", 2);
              dword_50792C = LODFile_Icons_LOD.LODFile_LoadTexture( "quit1", 2);
              dword_50C9C4 = GUIButtonCreate(pGUIWindow_CurrentMenu, 19, 155, 214, 40, v0, 0, 124, 0, 78,
                               pGlobalTXT_LocalizationStrings[614],
                               dword_507940 != -1 ? &LODFile_Icons_LOD.aLODHeaders[dword_507940]: NULL);
              dword_50C9C0 = GUIButtonCreate(pGUIWindow_CurrentMenu, 19, 209, 214, 40, v0, 0, 126, 0, 83,
                               pGlobalTXT_LocalizationStrings[615],
                               dword_507938 != -1 ? &LODFile_Icons_LOD.aLODHeaders[dword_507938] : NULL);
              dword_50C9BC = GUIButtonCreate(pGUIWindow_CurrentMenu,
                               19,
                               263,
                               214,
                               40,
                               v0,
                               0,
                               125,
                               0,
                               76,
                               pGlobalTXT_LocalizationStrings[616],
                               dword_50793C != -1 ? &LODFile_Icons_LOD.aLODHeaders[dword_50793C] : 0);
              dword_50C9B8 = GUIButtonCreate(pGUIWindow_CurrentMenu,
                               241,
                               155,
                               214,
                               40,
                               v0,
                               0,
                               127,
                               0,
                               67,
                               pGlobalTXT_LocalizationStrings[617],
                               dword_507934 != -1 ? &LODFile_Icons_LOD.aLODHeaders[ dword_507934 ] : 0);
              dword_50C9B4 = GUIButtonCreate(pGUIWindow_CurrentMenu,
                               241,
                               209,
                               214,
                               40,
                               v0,
                               0,
                               132,
                               0,
                               81,
                               pGlobalTXT_LocalizationStrings[618],
                               dword_50792C != -1 ? &LODFile_Icons_LOD.aLODHeaders[dword_50792C] : 0);
              dword_50C9B0 = GUIButtonCreate(pGUIWindow_CurrentMenu,
                               241,
                               263,
                               214,
                               40,
                               v0,
                               0,
                               123,
                               0,
                               82,
                               pGlobalTXT_LocalizationStrings[619],
                               dword_507930 != -1 ? &LODFile_Icons_LOD.aLODHeaders[dword_507930] : 0);
              v45 = GUIWindow_sub_41D08F(pGUIWindow_CurrentMenu, 6, v0, 0, 0);
              struct_576FE8.dword_000048 = v0;
              Class33_global3.PCXTexture_Release();
           //   v46 = sub_45E03A_SomethingLikeCaptureAScreenshot(155, 117);
           //   v212 = v46;
            //  v47 = (int)sub_49F8B5(pD3DRenderer, "gamma.pcx", v46, 155, 117);
           //   operator_delete((void *)v212);
           //   sub_40E55E(&Class33_global3, (unsigned int)"gamma.pcx", 0);
              goto LABEL_92;
            }
            goto LABEL_333;
          }
          sub_41426F();
LABEL_92:
          if ( !dword_50CBD0.msg_count )
            break;
          continue;
        case 0xBC:
          if ( v209 )
          {
            GUIWindowCreate(626, 179, 0, 0, 90, pBtn_Game_NPCScrollRightDown, 0);
            v48 = (pParty_global->pHiredNPCs[0].pNPCName != 0) + (pParty_global->pHiredNPCs[1].pNPCName != 0) + (unsigned __int8)pParty_global->byte_00070A - 2;
            if (pParty_global->byte_000709 < v48 )
            {
              ++pParty_global->byte_000709;
              if (pParty_global->byte_000709 >= v48 )
                pParty_global->byte_000709 = v48;
            }
          }
          else
          {
            GUIWindowCreate(469, 179, 0, 0, 90, pBtn_Game_NPCScrollLeftDown, 0);
            if (pParty_global->byte_000709)
            {
              --pParty_global->byte_000709;
              if ( pParty_global->byte_000709 < 1 )
                pParty_global->byte_000709 = 0;
            }
          }
          sub_491F87_DrawHiredNPCs();
          goto LABEL_92;
        case 0x19B:
          //if ( dword_50CBD0.msg_count )
		//	   if  (dword_50CBD0.prm[0].msg_param3)
           //               dword_50CBD0.msg_count = 1;
			dword_50CBD0.CutQueueTail();
          dword_50CDC8 = v0;
          sub_42FBDD();
          sub_4B1E92(dword_591160, 2);
          CVideoPlayer_UnloadAll(pVideoPlayer);
          sub_44603D();
          struct_576FE8.dword_000044 = v0;
          if ( dword_59117C | dword_591178 | dword_591174 | dword_591170 | dword_59116C | dword_591168 )
          {
            if ( dword_59117C )
            {
              pParty_global->sPartyPosX = dword_59117C;
              dword_5B65A8 = dword_59117C;
            }
            if ( dword_591178 )
            {
              pParty_global->sPartyPosY = dword_591178;
              dword_5B65AC = dword_591178;
            }
            if ( dword_591174 )
            {
              pParty_global->sPartyPosZ = dword_591174;
              dword_5B65B0 = dword_591174;
              pParty_global->dword_000700 = dword_591174;
            }
            if ( dword_591170 )
            {
              pParty_global->sRotationY = dword_591170;
              dword_5B65B4 = dword_591170;
            }
            if ( dword_59116C )
            {
              pParty_global->sRotationX = dword_59116C;
              dword_5B65B8 = dword_59116C;
              v49 = dword_591168;
              pParty_global->dword_0006E8 = dword_591168;
              dword_5B65BC = dword_591168;
            }
            else
            {
              v49 = dword_5B65BC;
            }
            if ( *dword_591164 != 48 )
            {
             pLoadingUI->uProgressBarType = 2;
              dword_5B65C0 = dword_5B65A8 | dword_5B65AC | dword_5B65B0 | dword_5B65B4 | dword_5B65B8 | v49;
              sub_443F95();
              sub_44987B(dword_591164, 0);
            }
          }
          else
          {
            dword_597F18 = dword_5C341C;
            sub_44684A_LooksLikeEventProcessor(dword_5C3418, 0, v0);
          }
          dword_597F18 = 0;
          if ( !strcmpi(byte_6BE3B0, "d05.blv") )
            pParty_global->qword_00002C += 1474560i64;
          goto LABEL_92;
        case 0x19C:
          sub_42FC15();
          CVideoPlayer_UnloadAll(pVideoPlayer);
          sub_44603D();
          dword_597F18 = 0;
          goto LABEL_422;
        case 0xB0:
          v51 = GetAsyncKeyState(VK_SHIFT);
          v50 = sub_49387A((void *)v51);
          goto LABEL_421;
        case 0x5A:
         // if ( dword_50CBD0.msg_count )
			//   if  (dword_50CBD0.prm[0].msg_param3)
            //              dword_50CBD0.msg_count = 1;
			dword_50CBD0.CutQueueTail();
          dword_50CDC8 = v0;
          sub_42FBDD();
          v211 = sub_444D80();
          strcpy((char *)pClass51_global->string_000000, CurrentLevelName);
          if ( byte_6BE3C4_MaybeDrowningFlag != 1 && pParty_global->dword_000704
           || sub_48902E((char *)pClass51_global->string_000000, pParty_global->sPartyPosX, pParty_global->sPartyPosY, &Source, 20) != v0 )
          {
            struct_576FE8.dword_000044 = v0;
LABEL_387:
            sub_42FC15();
            if ( pParty_global->sPartyPosX < -22528 )
              pParty_global->sPartyPosX = -22528;
            if ( pParty_global->sPartyPosX > 22528 )
              pParty_global->sPartyPosX = 22528;
            if ( pParty_global->sPartyPosY < -22528 )
              pParty_global->sPartyPosY = -22528;
            if ( pParty_global->sPartyPosY > 22528 )
              pParty_global->sPartyPosY = 22528;
LABEL_317:
            sub_44603D();
            dword_4E28F8 = 0;
          }
          else
          {
            pParty_global->dword_0006E4 = 0;
            pParty_global->dword_0006E0 = 0;
            sub_427D48_MessWith_unnamed_50C0C8(&struct_50C0C8, v0);
            sub_44603D();
            cClock1.clock_fn1();
            LevelLoadingUI_Initialize(pLoadingUI, 2);
            ++pLoadingUI->uProgressMax;
            SaveGame(v0, 0);
            LevelLoadingUI_UpdateAndDrawProgressBar(pLoadingUI);
            sub_4B1BDB(1440 * v211);
            if ( pParty_global->uNumFood )
            {
              sub_490D02(pParty_global);
              if ( pParty_global->uNumFood - v211 < 0 )
              {
               for (i = 0; i < 4; ++i)
                 Player_sub_492D65(&pParty_global->pPlayers[i], v0, 0);
                ++pParty_global->unk_000764[0];
              }
              sub_492B03((void *)v211);
            }
            else
            {
             for (i = 0; i < 4; ++i)
               Player_sub_492D65(&pParty_global->pPlayers[i], v0, 0);
              ++pParty_global->unk_000764[0];
            }
            sub_48A336(&class35_obj);
            SpriteFrameTable_fn3(pSpriteFrameTable);
            strcpy(CurrentLevelName, &Source);
            strcpy(&Dest, CurrentLevelName);
            v52 = strtok(&Dest, ".");
            strcpy(&Dest, v52);
            Level_LoadEvtAndStr(&Dest);
            class58_sub_49B525(pClass58_global, 0);
            LoadLevel_InitializeLevelEvt();
            uLevelMapStatsID = CMapStats_FindLocation(pMapStats, CurrentLevelName);
            byte_6BE3C4_MaybeDrowningFlag = 0;
            byte_6BE3C5 = 0;
            *(_DWORD *)(LODWORD(pGame) + 3620) &= 0xFFFFFFF7u;
            if ( sub_464839() )
            {
              byte_6BE3C4_MaybeDrowningFlag = 1;
              *(_DWORD *)(LODWORD(pGame) + 3620) |= 8u;
            }
            if ( !_strcmpi(CurrentLevelName, "out15.odm") || !_strcmpi(CurrentLevelName, "d47.blv") )
              byte_6BE3C5 = 1;
            v0 = 1;
            PrepareToLoadODM(1, (void *)1);
            LODWORD(v53) = AudioPlayer_sub_4AC041(pAudioPlayer);
            dword_5C35C4 = 0;
            sub_443FDC_MessWithEvents(v53);
            sub_489487();
            sub_4498D5((void *)dword_6BE35C);
            pParty_global->sPartyPosZ = sub_48257A(pParty_global->sPartyPosX, pParty_global->sPartyPosY, (int)&v229, 0);
            pParty_global->dword_000700 = pParty_global->sPartyPosZ;
            sub_461103();
            cClock1.clock_sub_426363();
            struct_576FE8.dword_000044 = 1;
            dword_4E28F8 = 0;
            LevelLoadingUI_Release(pLoadingUI);
          }
          goto LABEL_422;
        case 0x5B:
          goto LABEL_387;
        case 0xBE:
          if ( pD3DRenderer->pRenderD3D3 )
          {
            LOWORD(v54) = sub_4C1BF1_Vis_LooksLikeFindTopmostZObject(pGame->pVis);
          }
          else
          {
            v212 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v226);
            v55 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v224);
            v54 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * (*(_DWORD *)v212 + dword_5059A8[*(_DWORD *)(v55 + 4)]));
          }
          v56 = (unsigned __int16)v54;
          v57 = v56 & 7;
          v212 = v56;
          v58 = v56 >> 3;
          if ( v57 == 3 )
          {
            v59 = pActors[v58].word_0000B0_state == 5;
            goto LABEL_400;
          }
          if ( v57 == 2 )
          {
           v59 = (*(_BYTE *)(56 * pLayingItemsList[v58].uObjectDescriptionID + pObjectDescriptionList->pDescriptions + 38) & 0x10) == 0;
LABEL_400:
            if ( !v59 )
              goto LABEL_92;
            goto LABEL_415;
          }
          if ( v57 == 5 )
          {
           v60 = pLevelDecorations[v58].word_000016 == 0;
          }
          else
          {
            if ( v57 != 6 )
              goto LABEL_92;
            if ( dword_6BE360 != v0 )
            {
             v62 = (int)&pClass51_global->pBModels[(v56 >> 9)].ptr_000054[(v58 & 0x3F)];
              if ( !(*(_BYTE *)(v62 + 31) & 2) || !*(_WORD *)(v62 + 292) )
                goto LABEL_92;
              v56 = v212;
              goto LABEL_415;
            }
            v61 = dword_6BE644 + 96 * v58;
            if ( !(*(_BYTE *)(v61 + 47) & 2) )
              goto LABEL_92;
            v60 = *(_WORD *)(dword_6BE64C + 36 * *(_WORD *)(v61 + 72) + 26) == 0;
          }
          if ( v60 )
            goto LABEL_92;
LABEL_415:
          v63 = ptr_507BD4->dword_00001C; //*(_DWORD *)(dword_507BD4 + 28);
          *(_BYTE *)(v63 + 8) &= 0xBFu;
LABEL_416:
          *(_WORD *)(v63 + 4) = v209;
          *(_DWORD *)(v63 + 12) = v56;
          Player_SetRecoveryTime(&pParty_global->pPlayers[*(_WORD *)(v63 + 2)], 300);
          v44 = ptr_507BD4;
LABEL_333:
          GUIWindowDelete(v44);
          ptr_507BD4 = NULL;
          GUICursor_SetCursorBitmap(pGame->pGUICursor, "MICON1");
          dword_5C35B8_Some_GetTickCount_timer = 0;
          dword_50C9A0 = false;
          sub_4356FF();
          goto LABEL_92;
        case 0x45:
        case 0x8D:
        case 0x8F:
         //if ( dword_50CBD0.msg_count )
			//   if  (dword_50CBD0.prm[0].msg_param3)
          //                dword_50CBD0.msg_count = 1;
			dword_50CBD0.CutQueueTail();
          if ( dword_50C9A0 )
          {
            v50 = v209;
LABEL_421:
            uActiveCharacter = v50;
LABEL_422:
            struct_576FE8.dword_000044 = v0;
          }
          else
          {
            if ( ptr_507BD4 )
            {
              v64 = ptr_507BD4->dword_00001C;//*(_DWORD *)(dword_507BD4 + 28);
              switch (uControlID)
              {
                case 0x45:
                  *(_BYTE *)(v64 + 8) &= 0xFDu;
                  break;
                case 0x8D:
                  *(_BYTE *)(v64 + 9) &= 0xFEu;
                  break;
                case 0x8F:
                  *(_BYTE *)(v64 + 9) &= 0xFDu;
                  break;
              }
              *(_WORD *)(v64 + 4) = v209;
              Player_SetRecoveryTime(&pParty_global->pPlayers[*(_WORD *)(v64 + 2)], 300);
              GUIWindowDelete( ptr_507BD4);
               ptr_507BD4 = NULL;
              cClock1.clock_sub_426363();
              GUICursor_SetCursorBitmap(pGame->pGUICursor, "MICON1");
              dword_5C35B8_Some_GetTickCount_timer = 0;
              dword_50C9A0 = false;
            }
          }
          goto LABEL_92;
        case 0xBF:
          dword_50CDC8 = v0;
          sub_42FBDD();
          SaveGame(v0, 0);
          strcpy(CurrentLevelName, (char *)pMapStats->pMapInfos[dword_5C35D0].pLocationFilename);
          dword_6BE364 |= v0;
          dword_6A0D48 = 2;
          v65 = word_591468[26 * (int)ptr_507BC0->dword_00001C];
          if ( v65 < 0 )
          {
            v66 = 4 * (abs(v65) - 1);
            dword_5B65B8 = 0;
            dword_5B65BC = 0;
            v67 = *(int *)((char *)&dword_4E4560 + v66);
            dword_5B65AC = *(int *)((char *)&dword_4E4578 + v66);
            v68 = *(int *)((char *)&dword_4E4590 + v66);
            v69 = *(int *)((char *)&dword_4E45A8 + v66);
            dword_5B65A8 = v67;
            dword_5B65B4 = v69;
            dword_5B65B0 = v68;
            dword_5B65C0 = v67 | dword_5B65AC | v68 | v69;
          }
          sub_4BD8B5();
          goto LABEL_434;
        case 0xC3:
          AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
          v179 = v209;
          v165 = 195;
          goto LABEL_438;
        case 0xB1:
          AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
          v179 = 0;
          v165 = 177;
LABEL_438:
          v158 = 9;
LABEL_439:
          pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, v158, (GUIButton*)v165, v179);
          goto LABEL_92;
        case 0xB2:
          v182 = 0;
          v168 = 0;
          v161 = 0;
          v156 = 0;
          byte_50656C = v209;
          v152 = -1;
          v149 = 0;
          v147 = 0;
          v144 = v209 + 204;
          goto LABEL_721;
        case 0xB4:
          if ( !pGUIWindow_CurrentMenu )
            goto LABEL_92;
          v70 = (int)pPlayers[dword_506348];
          v212 = v70 + 28 * v209 + 6828;
          if ( byte_50656C )
          {
            if ( !cSaveTumbnail[v209].pPixels )
              goto LABEL_92;
            v190 = (int)pMapStats->pMapInfos[sub_410D99(*(_WORD *)(v70 + 28 * v209 + 6854))].pLocationName;
            v174 = (int)pGlobalTXT_LocalizationStrings[474];
            goto LABEL_520;
          }
          v71 = CMapStats_FindLocation(pMapStats, CurrentLevelName);
          v201 = (int)"Not in Map Stats";
          if ( v71 )
            v201 = (int)pMapStats->pMapInfos[v71].pLocationName;
          if ( !cSaveTumbnail[v209].pPixels || !v71 )
          {
            v190 = v201;
            v174 = (int)pGlobalTXT_LocalizationStrings[476];
            goto LABEL_520;
          }
          v191 = (int)pMapStats->pMapInfos[sub_410D99(*(_WORD *)(v212 + 26))].pLocationName;
          v175 = v201;
          v163 = (int)pGlobalTXT_LocalizationStrings[475];
LABEL_450:
          wsprintfA((char *)TmpBuf, (const char *)v163, v175, v191);
          goto LABEL_521;
        case 0xB5:
          dword_50CDC8 = v0;
          goto LABEL_453;
        case 0xB3:
          v202 = (int)pPlayers[dword_506348];
          v211 = 28 * v209 + v202 + 6828;
          if ( !*(_QWORD *)v211 && byte_50656C )
            goto LABEL_92;
          byte_506360 = 1;
          sub_427730(v202, dword_506344);
          if ( pParty_global->dword_00087C )
          {
            v72 = dword_506340;
            pParty_global->array_016144[dword_506348] = dword_506340;
            Player_SetRecoveryTime((Player *)v202, v72);
            sub_40471C(&unk_4F8858);
          }
          else
          {
            Player_SetRecoveryTime((Player *)v202, (signed __int64)(flt_6BE3A4_debug_recmod1 * (double)dword_506340 * 2.1333333333333333));
          }
          AudioPlayer_sub_4AA306(pAudioPlayer, word_4EE088[dword_506338], 0, 0, -1, 0, dword_50633C, 0, 0);
          if ( byte_50656C )
          {
           if ( _strcmpi(CurrentLevelName, LODFile_Games_LOD.pLODSubIndexNamedBuffer[*(_WORD *)(v211 + 26)].pFilename) )
            {
              SaveGame(v0, 0);
              sub_443F95();
              strcpy(CurrentLevelName, LODFile_Games_LOD.pLODSubIndexNamedBuffer[*(_WORD *)(v211 + 26)].pFilename);
              dword_6BE364 |= v0;
              dword_6A0D48 = 2;
              dword_5B65A8 = *(_DWORD *)(v211 + 8);
              dword_5B65AC = *(_DWORD *)(v211 + 12);
              dword_5B65B0 = *(_DWORD *)(v211 + 16);
              dword_5B65B4 = *(_WORD *)(v211 + 20);
              dword_5B65B8 = *(_WORD *)(v211 + 22);
              dword_5B65C0 = v0;
            }
            else
            {
              pParty_global->sPartyPosX = *(_DWORD *)(v211 + 8);
              pParty_global->sPartyPosY = *(_DWORD *)(v211 + 12);
              pParty_global->sPartyPosZ = *(_DWORD *)(v211 + 16);
              pParty_global->dword_000700 = pParty_global->sPartyPosZ;
              pParty_global->sRotationY = *(_WORD *)(v211 + 20);
              pParty_global->sRotationX = *(_WORD *)(v211 + 22);
            }
          /*  if ( dword_50CBD0[0] < 40 )
            {
              dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
              dword_50CBD0[3 * dword_50CBD0[0] + 2] = v0;
              dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
            }  */
			 dword_50CBD0.PutMessageToQueue(113,1,0);
            sub_45E006();
            GUIWindowDelete(ptr_507BE0);
            GUIWindowDelete(pGUIWindow_CurrentMenu);
            ptr_507BE0 = 0;
            pGUIWindow_CurrentMenu = 0;
          }
          else
          {
            wsprintfA((char *)TmpBuf, "data\\lloyd%d%d.pcx", dword_506348 + 1, v209 + 1);
            sub_45E26C((char *)TmpBuf);
            sub_411B59(v209, dword_506348 + 1);
            v228 = qword_506350 << 7;
            v73 = v211;
            v203 = 0;
            v74 = (unsigned __int64)(pParty_global->qword_00002C + (signed __int64)((double)(qword_506350 << 7) * 0.03333333507180214)) >> 32;
            *(_DWORD *)v211 = pParty_global->qword_00002C + (signed __int64)((double)(qword_506350 << 7) * 0.03333333507180214);
            *(_DWORD *)(v73 + 4) = v74;
            *(_DWORD *)(v73 + 8) = pParty_global->sPartyPosX;
            *(_DWORD *)(v73 + 12) = pParty_global->sPartyPosY;
            *(_DWORD *)(v73 + 16) = pParty_global->sPartyPosZ;
            *(_WORD *)(v73 + 20) = pParty_global->sRotationY;
            *(_WORD *)(v73 + 22) = pParty_global->sRotationX;
            if (LODFile_Games_LOD.uNumSubidices / 2 <= 0 )
              goto LABEL_92;
            v210 = 0;
            while ( _strcmpi((const char *)((char *)LODFile_Games_LOD.pLODSubIndexNamedBuffer + v210), CurrentLevelName) )
            {
              ++v203;
              v210 += 32;
              if ( v203 >= LODFile_Games_LOD.uNumSubidices / 2 )
                goto LABEL_92;
            }
            *(_WORD *)(v211 + 26) = v203;
          }
          goto LABEL_92;
        case 0xB7:
          if ( v209 )
          {
            switch ( v209 )
            {
              case 1:
                v75 = 208;
                break;
              case 2:
                v75 = 207;
                break;
              case 3:
                v75 = 211;
                break;
              case 4:
                v75 = 209;
                break;
              default:
                if ( v209 != 5 )
                {
LABEL_486:
                  SaveGame(v0, 0);
                  v77 = CMapStats_FindLocation(pMapStats, CurrentLevelName);
                  v76 = 20 * v209;
                  //if ( v77 == word_4ECBC8[10 * v209] )
                  if (v77 == stru_4ECBB8[v209].uMapInfoID)
                  {
                    //pParty_global->sPartyPosX = *(int *)((char *)dword_4ECBB8 + v76);
                    //pParty_global->sPartyPosY = *(int *)((char *)dword_4ECBBC + v76);
                    //pParty_global->sPartyPosZ = *(int *)((char *)dword_4ECBC0 + v76);
                    pParty_global->sPartyPosX = stru_4ECBB8[v209].sSomeX;
                    pParty_global->sPartyPosY = stru_4ECBB8[v209].sSomeY;
                    pParty_global->sPartyPosZ = stru_4ECBB8[v209].sSomeZ;

                    pParty_global->dword_000700 = pParty_global->sPartyPosZ;
                    //pParty_global->sRotationY = *(__int16 *)((char *)word_4ECBC4 + v76);
                    //pParty_global->sRotationX = *(__int16 *)((char *)word_4ECBC6 + v76);
                    pParty_global->sRotationY = stru_4ECBB8[v209].sSomeRotationY;
                    pParty_global->sRotationX = stru_4ECBB8[v209].sSomeRotationX;
                    
                  }
                  else
                  {
                    SaveGame(v0, 0);
                    sub_443F95();
                    dword_6BE364 |= v0;
                    dword_6A0D48 = 2;
                    strcpy(CurrentLevelName, (char *)pMapStats->pMapInfos[stru_4ECBB8[v209].uMapInfoID].pLocationFilename);
                    dword_5B65C0 = v0;
                    dword_5B65A8 = stru_4ECBB8[v209].sSomeX;
                    dword_5B65AC = stru_4ECBB8[v209].sSomeY;
                    dword_5B65B0 = stru_4ECBB8[v209].sSomeZ;
                    v78 = stru_4ECBB8[v209].sSomeRotationX;
                    dword_5B65B4 = stru_4ECBB8[v209].sSomeRotationY;
                    dword_5B65B8 = stru_4ECBB8[v209].sSomeRotationX;
                    UpdateActors();
                  }
                  v79 = (int)pGUIWindow_CurrentMenu->ptr_000048;
                  if ( v79 )
                    *(_DWORD *)(v79 + 68) = v0;
                  else
                    sub_427730((int)&pParty_global->pPlayers[(unsigned __int8)byte_50C0C0], 20);
LABEL_434:
               /*   if ( dword_50CBD0[0] < 40 )
                  {
                    dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
                    dword_50CBD0[3 * dword_50CBD0[0] + 2] = v0;
LABEL_771:
                    dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
                  }	 */
				  dword_50CBD0.PutMessageToQueue(113,1,0);
                  goto LABEL_92;
                }
                v75 = 210;
                break;
            }
          }
          else
          {
            v75 = 206;
          }
          if ( !(unsigned __int16)sub_449B57((unsigned char *)pParty_global->unk_000764 + 1, v75) )
            return;
          goto LABEL_486;
        case 0xB6:
          if ( v209 )
          {
            switch ( v209 )
            {
              case 1:
                v80 = 208;
                break;
              case 2:
                v80 = 207;
                break;
              case 3:
                v80 = 211;
                break;
              case 4:
                v80 = 209;
                break;
              default:
                if ( v209 != 5 )
                  goto LABEL_506;
                v80 = 210;
                break;
            }
          }
          else
          {
            v80 = 206;
          }
          if ( !(unsigned __int16)sub_449B57((unsigned char *)pParty_global->unk_000764 + 1, v80) )
          {
#ifndef OLD_CODE
           
            Render_DrawRGBTexture_New(pD3DRenderer, 0, 352, uTextureID_GameUI_StatusBar);
#endif
#ifdef OLD_CODE
		   Render_DrawRGBTexture(pD3DRenderer, 0, 352, &cPCXID_GameUI_StatusBar);
#endif
            goto LABEL_92;
          }
LABEL_506:
          if ( v209 )
          {
            switch ( v209 )
            {
              case 1:
                v81 = (int)pMapStats->pMapInfos[4].pLocationName;
                break;
              case 2:
                v81 = (int)pMapStats->pMapInfos[3].pLocationName;
                break;
              case 3:
                v81 = (int)pMapStats->pMapInfos[10].pLocationName;
                break;
              case 4:
                v81 = (int)pMapStats->pMapInfos[7].pLocationName;
                break;
              default:
                if ( v209 != 5 )
                  goto LABEL_519;
                v81 = (int)pMapStats->pMapInfos[8].pLocationName;
                break;
            }
          }
          else
          {
            v81 = (int)pMapStats->pMapInfos[21].pLocationName;
          }
          v216 = v81;
LABEL_519:
          v190 = v216;
          v174 = (int)pGlobalTXT_LocalizationStrings[35];
          goto LABEL_520;
        case 0xC5:
          wsprintfA(&unk_5C4DB0, "%s\n \n%s\n \n%s", pGlobalTXT_LocalizationStrings[151], pGlobalTXT_LocalizationStrings[118], pGlobalTXT_LocalizationStrings[167]);
          sub_4141CA((int)&unk_5C4DB0, 196);
          dword_6A0D48 = 9;
          goto LABEL_92;
        case 0xC4:
          dword_6A0D48 = 0;
          strcpy((char *)pKeyboardController->pPressedKeysBuffer, "2");
          goto LABEL_524;
        case 0xDD:
LABEL_524:
          wsprintfA((char *)TmpBuf, "%s", pKeyboardController->pPressedKeysBuffer);
          memcpy(&v232, sub_4BE3BF(pKeyboardController->pPressedKeysBuffer, (StringSplitter *)&v237), 0x7Cu);
          if ( v232 == 1 )
          {
            v211 = LODFile_Games_LOD.uNumSubidices / 2;
            v82 = atoi(Str);
            if ( v82 <= 0 || v82 >= 77 )
            {
LABEL_90:
              v1 = "";
LABEL_91:
              v0 = 1;
              goto LABEL_92;
            }
            v83 = 68 * v82;
            strcpy(&Str2, (char *)pMapStats->pMapInfos[v82].pLocationFilename);
            v84 = 0;
            if ( v211 > 0 )
            {
              v204 = 0;
              do
              {
               if ( !_strcmpi((const char *)((char *)LODFile_Games_LOD.pLODSubIndexNamedBuffer + v204), &Str2) )
                  break;
                v204 += 32;
                ++v84;
              }
              while ( v84 < v211 );
              if ( v84 < v211 )
              {
               strcpy(CurrentLevelName, LODFile_Games_LOD.pLODSubIndexNamedBuffer[v84].pFilename);
                dword_6BE364 |= 1u;
                dword_6A0D48 = 2;
                sub_443F95();
                goto LABEL_90;
              }
            }
            wsprintfA(&Str2, "No map found for %s", pMapStats->pMapInfos[v82].pLocationName);
            v85 = &Str2;
          }
          else
          {
            if ( v232 != 3 )
              goto LABEL_90;
            v87 = atoi(Str);
            v205 = atoi(v234);
            v86 = atoi(v235);
            v88 = v86;
            if ( dword_6BE360 == 1 )
            {
              if ( sub_49AC17((int)byte_6BE3C8, v87, v205, v86) )
              {
                v89 = v205;
LABEL_544:
                pParty_global->sPartyPosX = v87;
                pParty_global->sPartyPosY = v89;
                pParty_global->sPartyPosZ = v88;
                pParty_global->dword_000700 = v88;
                goto LABEL_90;
              }
            }
            else
            {
              if ( v87 > -32768 )
              {
                if ( v87 < 32768 )
                {
                  v89 = v205;
                  if ( v205 > -32768 )
                  {
                    if ( v205 < 32768 && v88 >= 0 && v88 < 10000 )
                      goto LABEL_544;
                  }
                }
              }
            }
            AudioPlayer_sub_4AA306(pAudioPlayer, 27, 0, 0, -1, 0, 0, 0, 0);
            v85 = "Can't jump to that location!";
          }
          sub_44C175(v85, 6);
          goto LABEL_90;
        case 0x19:
          if ( byte_6BE3C4_MaybeDrowningFlag == 1 )
            goto LABEL_682;
          if ( !uActiveCharacter || (v90 = (int)pPlayers[uActiveCharacter], *(_WORD *)(v90 + 6452)) )
            goto LABEL_90;
          v92 = *(_BYTE *)(v90 + 6735);
          v192 = uActiveCharacter;
          v176 = 0;
          v164 = 0;
          v91 = uActiveCharacter;
          goto LABEL_679;
        case 0x46:
        case 0x8C:
          if ( pD3DRenderer->pRenderD3D3 )
          {
            v93 = sub_4C1BF1_Vis_LooksLikeFindTopmostZObject(pGame->pVis);
          }
          else
          {
            v212 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v222);
            v94 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v217);
            v93 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * (*(_DWORD *)v212 + dword_5059A8[*(_DWORD *)(v94 + 4)]));
          }
          v96 = v93;
          v56 = (unsigned __int16)v93;
          v95 = v96 >> 16;
          if ( (v56 & 7) != 3 || v95 >= 5120 )
            goto LABEL_90;
          v63 =ptr_507BD4->dword_00001C;// *(_DWORD *)(dword_507BD4 + 28);
          if (uControlID == 70)
          {
            *(_BYTE *)(v63 + 8) &= 0xF7u;
          }
          else
          {
            if (uControlID == 140)
              *(_BYTE *)(v63 + 9) &= 0xFEu;
            else
              *(_BYTE *)(v63 + 9) &= 0xFDu;
          }
          goto LABEL_416;
        case 0x1C:
          if ( !uActiveCharacter || dword_4E28F8 )
            goto LABEL_90;
          dword_507BC8 = (int)GUIWindowCreate(0, 0, 640, 480, 104, (GUIButton *)v209, 0);
          dword_4E28F8 = 25;
          cClock1.clock_fn1();
          goto LABEL_92;
        case 0x1B:
          if ( !uActiveCharacter )
            goto LABEL_90;
          if ( pParty_global->dword_00087C != v0 )
            goto LABEL_569;
          if ( dword_4F885C == v0 || dword_4F885C == 3 )
            goto LABEL_90;
          if ( !(dword_4F8870 & 2) )
          {
LABEL_569:
            if ( pActors[v209].word_0000B0_state == 5 )
              sub_426A5A((int)((char *)pActors + 836 * v209));
            else
              sub_42EBEE((void *)v209);
          }
          goto LABEL_92;

          // attack ('A' default)
        case 0x17:
          if (!uActiveCharacter)
            goto LABEL_90;
          if ( pParty_global->dword_00087C != v0 )
          {
           sub_42ECB5_PlayerAttack();
           goto LABEL_92;
          }
          else if ( dword_4F885C == v0 || dword_4F885C == 3 )
            goto LABEL_90;
          else if ( !(dword_4F8870 & 2) )
            sub_42ECB5_PlayerAttack();
          goto LABEL_92;


        case 0xA7:
          v180 = (int)pGlobalTXT_LocalizationStrings[81];
          v97 = (int)dword_507638;
          v166 = (int)dword_507638;
          v159 = 96;
          goto LABEL_731;
        case 0x5F:
          if ( dword_506F14 == 2 )
            goto LABEL_621;
          GUIWindowCreate(dword_50763C->uX, dword_50763C->uY, 0, 0, 90, dword_50763C, (int)pGlobalTXT_LocalizationStrings[238]);
          dword_506F14 = v0;
          dword_506F18 = 5;
          goto LABEL_92;
        case 0x60:
          if ( dword_506F14 == 2 )
            goto LABEL_621;
          GUIWindowCreate(dword_507644->uX, dword_507644->uY, 0, 0, 90, dword_507644, (int)pGlobalTXT_LocalizationStrings[239]);
          dword_506F14 = v0;
          dword_506F18 = 60;
          goto LABEL_92;
        case 0x199:
          dword_506F14 = 2;
          sub_41F6C1();
          v98 = 60 * (sub_494820(pParty_global->uCurrentHour) + 1) - pParty_global->uCurrentMinute;
          dword_506F18 = v98;
          if ( v209 == 111 || v209 == 114 || v209 == 116 )
            dword_506F18 = v98 + 720;
          goto LABEL_615;
        case 0x68:
        //  if ( dword_50CBD0.msg_count )
		//	   if  (dword_50CBD0.prm[0].msg_param3)
           //               dword_50CBD0.msg_count = 1;
			dword_50CBD0.CutQueueTail();
          if ( dword_4E28F8 )
            goto LABEL_92;
          if ( sub_42F4DA() )
            goto LABEL_594;
          if ( pParty_global->dword_00087C == v0 )
            goto LABEL_595;
          if ( !(pParty_global->dword_007778 & 0x88) )
          {
            sub_41F6C1();
            goto LABEL_92;
          }
LABEL_594:
          if ( pParty_global->dword_00087C == v0 )
          {
LABEL_595:
            v99 = (char *)pGlobalTXT_LocalizationStrings[478];
            goto LABEL_723;
          }
          v100 = (char *)pGlobalTXT_LocalizationStrings[480];
          if ( pParty_global->dword_007778 & 0x88 )
            v100 = (char *)pGlobalTXT_LocalizationStrings[479];
          sub_44C175(v100, 2);
          v101 = uActiveCharacter;
          if ( !uActiveCharacter )
            goto LABEL_90;
          v193 = 0;
          v177 = 13;
          goto LABEL_619;
        case 0x61:
          if ( dword_506F14 )
            goto LABEL_621;
          if ( pParty_global->uNumFood < (unsigned int)dword_506F10 )
          {
            sub_44C175((char *)pGlobalTXT_LocalizationStrings[482], 2);
            if ( uActiveCharacter && Player_sub_492C0B_MaybeIfPlayerConscious(pPlayers[uActiveCharacter]) )
            {
              v101 = uActiveCharacter;
              v193 = 0;
              v177 = 108;
LABEL_619:
              Player_PlaySound(pPlayers[uActiveCharacter], v177, v193);
            }
          }
          else
          {
            qword_AD2B48 = pParty_global->qword_00002C;
            qword_AD100C = pParty_global->qword_00002C;
            qword_ACF4D0 = pParty_global->qword_00002C;
            qword_ACD994 = pParty_global->qword_00002C;
            v102 = CMapStats_FindLocation(pMapStats, CurrentLevelName);
            if ( !v102 )
              //v102 = rand() % pMapStats->uNumMaps + 1;
              v102 = rand() % pMapStats->uNumMaps;
            v206 = (int)&pMapStats->pMapInfos[v102];
            if ( rand() % 100 + 1 <= *(_BYTE *)(v206 + 48) )
            {
              v105 = rand() % 100;
              v103 = *(_BYTE *)(v206 + 49);
              v104 = v105 + 1;
              v211 = v104 > v103 ? (v104 > v103 + *(_BYTE *)(v206 + 50)) + 2 : v0;
              if ( !sub_45063B(v206, v211) )
                v211 = 0;
              if ( v211 )
              {
                v106 = 6972 * rand() % 4;
                *(_DWORD *)((char *)&qword_ACD994 + v106) = 0;
                *(_DWORD *)((char *)&qword_ACD994 + v106 + 4) = 0;
                v107 = rand();
                sub_4938D1(v107 % 6 + 60);
                dword_506F18 = 0;
                dword_506F14 = 0;
              /*  if ( dword_50CBD0[0] < 40 )
                {
                  dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
                  dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
                  dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
                } */
				dword_50CBD0.PutMessageToQueue(113,0,0);
                sub_44C175((char *)pGlobalTXT_LocalizationStrings[481], 2);
                v182 = 0;
                v168 = 0;
                v161 = 0;
                v156 = 0;
                v152 = -1;
                v149 = 0;
                v147 = 0;
                v144 = 227;
                goto LABEL_721;
              }
            }
            sub_492B03((void *)dword_506F10);
            dword_506F18 = 480;
LABEL_615:
            dword_506F14 = 2;
            sub_490D02(pParty_global);
            pParty_global->unk_000764[0] = 0;
            qword_AD2B48 = pParty_global->qword_00002C;
            qword_AD100C = pParty_global->qword_00002C;
            qword_ACF4D0 = pParty_global->qword_00002C;
            qword_ACD994 = pParty_global->qword_00002C;
          }
          goto LABEL_92;
        case 0x6D:
          if ( dword_506F14 == 2 )
          {
LABEL_621:
            v108 = (char *)pGlobalTXT_LocalizationStrings[477];
            goto LABEL_622;
          }
          GUIWindowCreate(dword_507640->uX, dword_507640->uY, 0, 0, 90, dword_507640, (int)pGlobalTXT_LocalizationStrings[237]);
          v109 = sub_494820(pParty_global->uCurrentHour);
          dword_506F14 = v0;
          dword_506F18 = 60 * v109 - pParty_global->uCurrentMinute;
          goto LABEL_92;
        case 0x4E:
          if ( dword_50654C && byte_506550 )
          {
            //dword_5CC030 == pSpellStats
            compile_error;//v190 = dword_5CC030[9 * (dword_50654C + 11 * *((_BYTE *)*(&ptr_A750C4 + uActiveCharacter) + 6734))];
            v174 = (int)pGlobalTXT_LocalizationStrings[483];
LABEL_520:
            wsprintfA((char *)TmpBuf, (const char *)v174, v190);
          }
          else
          {
            if ( *((_BYTE *)pPlayers[uActiveCharacter] + 6735) )
              v194 = (char *)pGlobalTXT_LocalizationStrings[584];
            else
              v194 = (char *)pGlobalTXT_LocalizationStrings[484];
            strcpy((char *)(char *)TmpBuf, v194);
          }
LABEL_521:
          sub_41C0B8((char *)TmpBuf);
          goto LABEL_92;
        case 0x4F:
          if ( !uActiveCharacter
            || (v212 = (int)pPlayers[uActiveCharacter],
                !*(_BYTE *)(v212 + 11 * *(_BYTE *)(v212 + 6734) + v209 + 402)) )
            goto LABEL_92;
          if ( sub_4637E0() )
            dword_507B00 = v209 + 1;
          v110 = *(_BYTE *)(v212 + 6734);
          if ( dword_50654C - 1 == v209 )
          {
           // v195 = dword_5CC054[9 * (v209 + 11 * v110)];
           v195 = (int)pSpellStats->pSpellInfos[1 + (v209 + 11 * v110) / 4].pSpellName;
            v178 = (int)pGlobalTXT_LocalizationStrings[485];
          }
          else
          {
           // v195 = dword_5CC054[9 * (v209 + 11 * v110)];
           v195 = (int)pSpellStats->pSpellInfos[1 + (v209 + 11 * v110) / 4].pSpellName;
            v178 = (int)pGlobalTXT_LocalizationStrings[486];
          }
          wsprintfA((char *)TmpBuf, (const char *)v178, v195);
          sub_41C0B8((char *)TmpBuf);
          goto LABEL_91;
        case 0x58:
          GUIWindowCreate(dword_5064F8->uX, dword_5064F8->uY, 0, 0, 90, dword_5064F8, 0);
          if ( !uActiveCharacter )
            goto LABEL_92;
          v207 = (int)pPlayers[uActiveCharacter];;
          if ( !byte_506550 || !dword_50654C )
          {
            v182 = 0;
            v168 = 0;
            v161 = 0;
            v156 = 0;
            v152 = -1;
            v149 = 0;
            *(_BYTE *)(v207 + 6735) = 0;
            v147 = 0;
            dword_50654C = 0;
            v144 = 203;
            goto LABEL_721;
          }
          v111 = dword_50654C + 11 * *(_BYTE *)*((char*)pPlayers[uActiveCharacter] + 6734);
          *(_BYTE *)*((char*)pPlayers[uActiveCharacter] + 6735) = v111;
          sub_494836((char *)&unk_AA1058 + 45016 * (uActiveCharacter-1), v111, uActiveCharacter);
          if ( uActiveCharacter )
            Player_PlaySound((Player *)v207, 12, 0);
          byte_506550 = 0;
          goto LABEL_92;
        case 0x33:
          if ( !uActiveCharacter )
            goto LABEL_92;
          v112 = (int)pPlayers[uActiveCharacter];
          v211 = 0;
          v210 = 0;
          v113 = 0;
          v208 = v112 + 288;
          do
          {
            if ( *(_WORD *)v208 )
            {
              if ( *(_BYTE *)(v112 + 6734) == v113 )
                v210 = v211;
              v114 = v211++;
              v236[v114] = v113;
            }
            v208 += 2;
            ++v113;
          }
          while ( v113 < 9 );
          if ( !v211 )
            goto LABEL_662;
          if ( GetAsyncKeyState(VK_SHIFT) )
          {
            v115 = v210-- - 1 < 0;
            if ( v115 )
              v210 = v211 - 1;
          }
          else
          {
            ++v210;
            if ( v210 >= v211 )
              v210 = 0;
          }
          sub_41140B();
          *((_BYTE *)pPlayers[uActiveCharacter] + 6734) = LOBYTE(v236[v210]);
          goto LABEL_661;
        case 0x57:
          if ( dword_4F885C == 3 || !uActiveCharacter || v209 == *(_BYTE *)*((char*)pPlayers[uActiveCharacter] + 6734) )
            goto LABEL_92;
          sub_41140B();
          *(_BYTE *)*((char*)pPlayers[uActiveCharacter] + 6734) = v209;
LABEL_661:
          sub_411621((void *)pGUIWindow_CurrentMenu);
LABEL_662:
          v182 = 0;
          v168 = 0;
          v161 = 0;
          v156 = 0;
          v152 = -1;
          v149 = 0;
          v147 = 0;
          v144 = rand() % 2 + 204;
          goto LABEL_721;
        case 0x56:
          if ( dword_4F885C != 3 )
          {
            if ( uActiveCharacter )
            {
              v212 = (int)pPlayers[uActiveCharacter];
              if ( *(_BYTE *)(v212 + 11 * *(_BYTE *)(v212 + 6734) + v209 + 402) )
              {
                if ( dword_50654C - 1 == v209 )
                {
                  GUIWindowDelete(pGUIWindow_CurrentMenu);
                 cClock1.clock_sub_426363();
                  struct_576FE8.dword_000044 = v0;
                  dword_4E28F8 = 0;
                  LODFile_Icons_LOD.LODFile_sub_4114F2();
                  v116 = dword_50654C + 11 * *(_BYTE *)(v212 + 6734);
                /*  if ( dword_50C9E8[0] < 40 )
                  {
                    dword_50C9E8[3 * dword_50C9E8[0] + 1] = 142;
                    dword_50C9E8[3 * dword_50C9E8[0] + 2] = v116;
                    dword_50C9E8[3 * dword_50C9E8[0]++ + 3] = uActiveCharacter ;
                  }	 */
				  dword_50C9E8.PutMessageToQueue(142,v116,uActiveCharacter); 
                }
                else
                {
                  byte_506550 = 1;
                  dword_50654C = v209 + 1;
                }
              }
            }
          }
          goto LABEL_92;
        case 0x8E:
          if ( dword_4F885C == 3 )
            goto LABEL_92;
          v192 = 0;
          v176 = 0;
          v164 = 0;
          goto LABEL_678;
        case 0x92:
          if ( dword_4F885C != 3 )
          {
            v192 = 0;
            v176 = v0;
            v164 = 133;
LABEL_678:
            v91 = v215;
            v92 = v209;
LABEL_679:
            sub_42777D(v92, v91, v164, v176, v192);
          }
          goto LABEL_92;
        case 0x69:
          if ( dword_4F885C == 3 )
            goto LABEL_92;
          if ( byte_6BE3C4_MaybeDrowningFlag == 1 )
          {
LABEL_682:
            v108 = (char *)pGlobalTXT_LocalizationStrings[652];
LABEL_622:
            sub_44C175(v108, 2);
LABEL_623:
            v182 = 0;
            v168 = 0;
            v161 = 0;
            v156 = 0;
            v152 = -1;
            v149 = 0;
            v147 = 0;
            v144 = 27;
LABEL_721:
            AudioPlayer_sub_4AA306(pAudioPlayer, v144, v147, v149, v152, v156, v161, v168, v182);
          }
          else
          {
           // if ( dword_50CBD0.msg_count )
			//   if  (dword_50CBD0.prm[0].msg_param3)
               //           dword_50CBD0.msg_count = 1;
		  dword_50CBD0.CutQueueTail();
            if ( uActiveCharacter && !pPlayers[uActiveCharacter - 1]->cInventorySlots[74].word_00001E)
            {
              if ( !dword_4E28F8 )
                goto LABEL_693;
              if ( dword_4E28F8 != 5 && dword_4E28F8 != 7 && (dword_4E28F8 <= 99 || dword_4E28F8 > 103) )
              {
                GUIWindowDelete(pGUIWindow_CurrentMenu);
LABEL_693:
                GUIWindowCreate(476, 450, 0, 0, 90, pBtn_Game_CastSpell, 0);
                dword_4E28F8 = 8;
                cClock1.clock_fn1();
                pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 18, 0, 0);
                AudioPlayer_sub_4AA306(pAudioPlayer, 48, 0, 0, -1, 0, 0, 0, 0);
                struct_576FE8.dword_000048 = v0;
                goto LABEL_92;
              }
            }
          }
          goto LABEL_92;
        case 0x6A:
         //if ( dword_50CBD0.msg_count )
			//   if  (dword_50CBD0.prm[0].msg_param3)
          //                dword_50CBD0.msg_count = 1;
			dword_50CBD0.CutQueueTail();
          if ( dword_4E28F8 )
            GUIWindowDelete(pGUIWindow_CurrentMenu);
          ++LODFile_Icons_LOD.uTexturePacksCount;
          if ( !LODFile_Icons_LOD.uPrevLoadedFiles )
            LODFile_Icons_LOD.uPrevLoadedFiles = LODFile_Icons_LOD.uNumLoadedFiles;
          GUIWindowCreate(560, 450, 0, 0, 90, pBtn_Game_QuickRef, 0);
          struct_576FE8.dword_000044 = v0;
          cClock1.clock_fn1();
          AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
          dword_4E28F8 = 104;
          pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 12, (GUIButton *)5, 0);
          uTextureID_ButtExit1 = LODFile_Icons_LOD.LODFile_LoadTexture("BUTTEXI1", 2);
          dword_5076F4 = GUIButtonCreate(pGUIWindow_CurrentMenu,
                           391,
                           316,
                           75,
                           33,
                           v0,
                           0,
                           113,
                           0,
                           0,
                           pGlobalTXT_LocalizationStrings[79],
                           &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_BtnEsc2]);
          goto LABEL_92;
        case 0x6B:
          if ( dword_4E28F8 )
          {
            GUIWindowDelete(pGUIWindow_CurrentMenu);
            cClock1.clock_sub_426363();
            dword_4E28F8 = 0;
            struct_576FE8.dword_000044 = v0;
          }
          Class33_global3.PCXTexture_Release();
        //  v117 = sub_45E03A_SomethingLikeCaptureAScreenshot(155, 117);
         // v212 = v117;
         // v118 = (int)sub_49F8B5(pD3DRenderer, "gamma.pcx", v117, 155, 117);
         // operator_delete((void *)v212);
         // sub_40E55E(&Class33_global3, (unsigned int)"gamma.pcx", 0);
          GUIWindowCreate(602, 450, 0, 0, 92, pBtn_Game_Options, 0);
LABEL_453:
         /* if ( dword_50CBD0.msg_count >= 40 )
            goto LABEL_92;
          dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param1 = 113;
           dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param2=0;
             dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param3=0;
		    dword_50CBD0.msg_count++; */
		    dword_50CBD0.PutMessageToQueue(113,0,0);
			goto LABEL_92;
        case 0xC0:
          dword_50651C = v0;
          if ( GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v227)->y > 178 )
            dword_50651C = -1;
          goto LABEL_92;
        case 0xA9:
          GUIWindowCreate(dword_507B9C->uX, dword_507B9C->uY, 0, 0, 91, dword_507B9C, 0);
LABEL_707:
          dword_506548 = v0;
          goto LABEL_92;
        case 0xAA:
          GUIWindowCreate(dword_507BA0->uX, dword_507BA0->uY, 0, 0, 91, dword_507BA0, 0);
LABEL_709:
          dword_506544 = v0;
          goto LABEL_92;
        case 0x55:
          dword_5118E0 ^= v0;
          GUIButton_sub_41D0D8(pCharacterUI_BtnDetail);
          GUIButton_sub_41D0D8(dword_507690);
          if ( dword_5118E0 )
          {
		    v145 = (dword_5118C8 != -1 ? LODFile_Icons_LOD.aLODHeaders[dword_5118C8].uTextureHeight : 26);
            v142 = (dword_5118C8 != -1 ? LODFile_Icons_LOD.aLODHeaders[dword_5118C8].uTextureWidth : 24);
            v140 = 445;
            v138 = 470;
          }
          else
          {
            v145 = 30;
            v142 = 30;
            v140 = 300;
            v138 = 600;
          }
          pCharacterUI_BtnDetail = 
			  GUIButtonCreate(pGUIWindow_CurrentMenu, v138, v140, v142, v145, v0, 0, 85, 0, 0, pGlobalTXT_LocalizationStrings[LOCSTR_DETAIL_TOGGLE], 0);
          dword_507690 = GUIButtonCreate(pGUIWindow_CurrentMenu, 476, 0, 164, 345, v0, 0, 133, 0, 0, (unsigned char *)v1, 0);
          goto LABEL_422;
        case 0x85:
          sub_468F8A_OnPaperdollLeftClick();
          goto LABEL_92;
        case 0x73:
          dword_506F48 = 100;
          sub_4196A0();
          sub_419379();
          v97 = (int)pCharacterUI_BtnStats;
          goto LABEL_716;
        case 0x72:
          dword_506F48 = 101;
          sub_4196A0();
          sub_419379();
          sub_419401();
          v97 = (int)pCharacterUI_BtnSkills;
          goto LABEL_716;
        case 0x79:
          v120 = (int)pPlayers[uActiveCharacter];
          v119 = v120 + 2 * v209 + 264;
          LOWORD(v3) = *(_WORD *)v119;
          v212 = v3;
          if ( *(_DWORD *)(v120 + 6456) < (v3 & 0x3Fu) + 1 )
          {
            v99 = (char *)pGlobalTXT_LocalizationStrings[488];
          }
          else
          {
            if ( (v212 & 0x3Fu) < 0x3C )
            {
              *(_WORD *)v119 = v212 + 1;
              *(_DWORD *)(v120 + 6456) -= *(_BYTE *)(v120 + 2 * v209 + 264) & 0x3F;
              Player_PlaySound((Player *)v120, 14, 0);
              v182 = 0;
              v168 = 0;
              v161 = 0;
              v156 = 0;
              v152 = -1;
              v149 = 0;
              v147 = 0;
              v144 = 20001;
              goto LABEL_721;
            }
            v99 = (char *)pGlobalTXT_LocalizationStrings[487];
          }
LABEL_723:
          sub_44C175(v99, 2);
          goto LABEL_92;
        case 0x74:
          dword_506F48 = 103;
          sub_419379();
          sub_4196A0();
          v97 = (int)pCharacterUI_BtnInventory;
LABEL_716:
          v180 = 0;
          v166 = v97;
          v159 = 91;
          goto LABEL_731;
        case 0xA8:
          v97 = (int)pCharacterUI_BtnExit;
          v180 = 0;
          v166 = (int)pCharacterUI_BtnExit;
          v159 = 97;
          goto LABEL_731;
        case 0x75:
          sub_419379();
          sub_4196A0();
          sub_419220();
          dword_506F48 = 102;
          GUIWindowCreate(*(_DWORD *)pCharacterUI_BtnAwards, *(_DWORD *)(pCharacterUI_BtnAwards + 4), 0, 0, 91, pCharacterUI_BtnAwards, 0);
          sub_419100();
          goto LABEL_92;
        case 0x47:
          switch ( v209 )
          {
            default:
              goto LABEL_92;
            case 11:
              goto LABEL_707;
            case 10:
              goto LABEL_709;
            case 0:
              v97 = (int)dword_506518;
              dword_506544 = v0;
              break;
            case 1:
              v97 = (int)dword_506514;
              dword_506548 = v0;
              break;
            case 2:
              dword_506540 = v0;
              if ( dword_506364 )
                goto LABEL_92;
              v97 = (int)dword_506510;
              break;
            case 3:
              dword_50653C = v0;
              if ( dword_506364 )
                goto LABEL_92;
              v97 = (int)dword_50650C;
              break;
            case 4:
              dword_506538 = v0;
              if ( dword_506364 )
                goto LABEL_92;
              v97 = (int)dword_506508;
              break;
            case 5:
              dword_506534 = v0;
              if ( dword_506364 )
                goto LABEL_92;
              v97 = (int)dword_506504;
              break;
            case 6:
              v97 = (int)dword_506500;
              dword_506530 = v0;
              break;
            case 7:
              v97 = (int)dword_5064FC;
              dword_50652C = v0;
              break;
          }
          v180 = v0;
          v166 = v97;
          v159 = 92;
LABEL_731:
          v10 = *(_DWORD *)(v97 + 4);
          v11 = *(_DWORD *)v97;
          goto LABEL_732;

        case 0x6E:
         // if ( dword_50CBD0.msg_count )
			//   if  (dword_50CBD0.prm[0].msg_param3)
           //               dword_50CBD0.msg_count = 1;
			dword_50CBD0.CutQueueTail();
          GameUI_OnPlayerPortraitLeftClick(v209);
          goto LABEL_92;

        case 0x65:
          v191 = pParty_global->uNumGoldInBank;
          v175 = pParty_global->uNumGold + pParty_global->uNumGoldInBank;
          v163 = (int)pGlobalTXT_LocalizationStrings[489];
          goto LABEL_450;
        case 0x5C:
          v211 = pParty_global->uCurrentHour;
          if ( pParty_global->uCurrentHour <= 12 )
          {
            if ( !v211 )
              v211 = 12;
          }
          else
          {
            v211 -= 12;
          }
          if ( (unsigned int)pParty_global->uCurrentHour < 0xC || (v212 = v0, (unsigned int)pParty_global->uCurrentHour >= 0x18) )
            v212 = 0;
          wsprintfA((char *)TmpBuf, "%d:%02d %s %s %d %s %d",
            v211,
            pParty_global->uCurrentMinute,
            aAMPMNames[v212],
            aDayNames[pParty_global->uDaysPlayed % 7],
            7 * pParty_global->uCurrentMonthWeek + pParty_global->uDaysPlayed % 7 + 1,
            aMonthNames[pParty_global->uCurrentMonth],
            pParty_global->uCurrentYear);
          goto LABEL_521;
        case 0x64:
          v190 = pParty_global->uNumFood;
          v174 = (int)pGlobalTXT_LocalizationStrings[501];
          goto LABEL_520;

        case 0x5E:
          wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[429], pPlayers[v209 - 1]->sName, aClassNames[pPlayers[v209 - 1]->uClass]);
          strcat((char *)TmpBuf, ": ");

          v122 = Player_GetConditionIdx(pPlayers[v209 - 1]);
          strcat((char *)TmpBuf, (char *)aCharacterConditionNames[v122]);

          sub_41C0B8((char *)TmpBuf);
          v123 = 8 * (v209 - 1);
          LOBYTE(v123) = v123 | 4;
          pGame->pGUICursor->dword_000000 = v123;
          break;

        case 0x5D:
          wsprintfA((char *)TmpBuf, "%d / %d %s    %d / %d %s",
            pPlayers[v209]->sHealth,
            Player_GetMaxHealth(pPlayers[v209]),
            pGlobalTXT_LocalizationStrings[108],
            pPlayers[v209]->sMana,
            Player_GetMaxMana(pPlayers[v209]),
            pGlobalTXT_LocalizationStrings[212]);
          goto LABEL_521;
        case 0xC:
          if ( dword_4E28F8 == 15 )
            goto LABEL_762;
          sub_420E01();
          goto LABEL_92;
        case 0x78:
LABEL_762:
          sub_421EA6_OnInventoryLeftClick();
          goto LABEL_92;
        case 0xA:
          runtime_warning(bred ->check in asm);
          if ( !pD3DRenderer->pRenderD3D3 )
			  {
           // goto LABEL_772;
			  //if ( dword_50CBD0.msg_count )
			 //  if  (dword_50CBD0.prm[0].msg_param3)
                //          dword_50CBD0.msg_count = 1;
				dword_50CBD0.CutQueueTail();
                       sub_42213C();
					    goto LABEL_92;
			  }
          v130 = dword_50CBD0.msg_count;
          if ( !dword_50CBD0.msg_count)
            goto LABEL_768;
          if (dword_50CBD0.prm[0].msg_param3)
          {
            v130 = v0;
            dword_50CBD0.msg_count = v0;
LABEL_769:
            ///dword_50CBD0[3 * v130 + 1] = 14;
			dword_50CBD0.prm[v130].msg_param1=14;
LABEL_770:
            //dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
			  dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param2=0;
             dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param3=0;
		    dword_50CBD0.msg_count++;
			goto LABEL_92;
          }
          v130 = 0;
          dword_50CBD0.msg_count = 0;


LABEL_768:
          if ( v130 < 40 )
            goto LABEL_769;
          goto LABEL_92;
        case 0xE:
LABEL_772:
       //  if ( dword_50CBD0.msg_count )
		//	   if  (dword_50CBD0.prm[0].msg_param3)
        //                  dword_50CBD0.msg_count = 1;
			dword_50CBD0.CutQueueTail();
          sub_42213C();
          goto LABEL_92;
        case 0xF:
          if ( pD3DRenderer->pRenderD3D3 )
          {
            LOWORD(v131) = sub_4C1BF1_Vis_LooksLikeFindTopmostZObject(pGame->pVis);
          }
          else
          {
            v212 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v225);
            v132 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v220);
            v131 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer + 4 * (*(_DWORD *)v212 + dword_5059A8[*(_DWORD *)(v132 + 4)]));
          }
          v180 = 0;
          v166 = (unsigned __int16)v131;
          v159 = 15;
          goto LABEL_779;
        case 0x54:
          v180 = 0;
          v166 = v209;
          v159 = 22;
LABEL_779:
          v10 = 0;
          v11 = 0;
LABEL_732:
          v154 = 0;
          v150 = 0;
LABEL_733:
          GUIWindowCreate(v11, v10, v150, v154, v159, (GUIButton *)v166, v180);
          goto LABEL_92;

        case 0x194: //action[def:space]
     //   if ( dword_50CBD0.msg_count )
		//	   if  (dword_50CBD0.prm[0].msg_param3)
           //               dword_50CBD0.msg_count = 1;
			dword_50CBD0.CutQueueTail();
          sub_46A14B_ProbablyDoInteraction();
        goto LABEL_92;

        case 0x16F:
          if ( dword_4E28F8 )
            goto LABEL_92;
          pParty_global->dword_007778 |= 2;
          GUIWindowCreate(519, 136, 0, 0, 90, pBtn_Game_MinimapZoomIn, 0);
          v212 = 131072;
          v133 = (unsigned __int64)((signed __int64)struct_576FE8.uMinimapZoom << 17) >> 16;
          ++struct_576FE8.dword_000028;
          struct_576FE8.uMinimapZoom = (unsigned __int64)((signed __int64)struct_576FE8.uMinimapZoom << 17) >> 16;
          if ( dword_6BE360 != 2 )
          {
            if ( v133 > 4096 )
            {
             struct_576FE8.uMinimapZoom = 4096;
             struct_576FE8.dword_000028 = 12;
            }
            goto LABEL_92;
          }
          v134 = 2048;
          if ( v133 <= 2048 )
            goto LABEL_789;
          struct_576FE8.dword_000028 = 11;
          goto LABEL_788;
        case 0x170:
          if ( dword_4E28F8 )
            goto LABEL_92;
          pParty_global->dword_007778 |= 2;
          GUIWindowCreate(574, 136, 0, 0, 90, pBtn_Game_MinimapZoomOut, 0);
          v212 = 32768;
          v133 = (unsigned __int64)((signed __int64)struct_576FE8.uMinimapZoom << 15) >> 16;
          --struct_576FE8.dword_000028;
          struct_576FE8.uMinimapZoom = (unsigned __int64)((signed __int64)struct_576FE8.uMinimapZoom << 15) >> 16;
          if ( dword_6BE360 == 2 )
          {
            v134 = 512;
            if ( v133 < 512 )
            {
             struct_576FE8.dword_000028 = 9;
LABEL_788:
              v133 = v134;
              struct_576FE8.uMinimapZoom = v134;
            }
LABEL_789:
            dword_576E2C = v133;
            dword_576E28 = struct_576FE8.dword_000028;
          }
          else
          {
            if ( v133 < 256 )
            {
             struct_576FE8.uMinimapZoom = 256;
             struct_576FE8.dword_000028 = 8;
            }
          }
          goto LABEL_92;
      }
    }


  dword_50CBD0.msg_count = dword_50C9E8.msg_count;
  memcpy(&dword_50CBD0.prm, &dword_50C9E8.prm, 12 * dword_50C9E8.msg_count);
  dword_50C9E8.msg_count = 0;

  if ( dword_50C9DC )
  {
  /*  if ( dword_50CBD0[0] < 40 )
    {
      dword_50CBD0[3 * dword_50CBD0[0] + 1] = dword_50C9DC;
      dword_50CBD0[3 * dword_50CBD0[0] + 2] = (int)dword_50C9E0;
      dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
    }	*/
	
	dword_50CBD0.PutMessageToQueue( dword_50C9DC,(int)dword_50C9E0,0);
    dword_50C9DC = 0;
  }
  else
  {
    if ( dword_50C9D0 > 0 )
    {
      v135 = dword_50C9D8 == cClock1.int_00001C;
      v136 = dword_50C9D8 - cClock1.int_00001C < 0;
      dword_50C9D8 -= cClock1.int_00001C;
      if ( v136 | v135 )
      {
      /*  if ( dword_50CBD0[0] < 40 )
        {
          dword_50CBD0[3 * dword_50CBD0[0] + 1] = dword_50C9D0;
          dword_50CBD0[3 * dword_50CBD0[0] + 2] = dword_50C9D4;
          dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
        }  */
		dword_50CBD0.PutMessageToQueue( dword_50C9D0,dword_50C9D4,0); 
        dword_50C9D0 = 0;
        dword_50C9D4 = 0;
        dword_50C9D8 = 0;
      }
    }
  }
  sub_427E01(&struct_50C0C8);
}


//----- (004219BE) --------------------------------------------------------
int __thiscall sub_4219BE(void *_this)
{
  int v2; // esi@1
  GUIWindow *v3; // ebx@1

  v2 = (int)_this;
  cClock1.clock_fn1();
  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
  dword_5118E0 = 0;
  CharacterUI_LoadPaperdollTextures();
  dword_4E28F8 = 23;
  v3 = GUIWindowCreate(0, 0, 640, 480, 31, (GUIButton*)v2, 0);
  pCharacterUI_BtnExit = GUIButtonCreate(
                   v3,
                   394,
                   318,
                   75,
                   33,
                   1,
                   0,
                   168,
                   0,
                   0,
                   pGlobalTXT_LocalizationStrings[LOCSTR_EXIT],
                    &LODFile_Icons_LOD.aLODHeaders[uTextureID_ButtExit1]);
  GUIButtonCreate(v3, 0, 0, 476, 345, 1, 122, 120, 0, 0, (unsigned char *)"", 0);
  dword_507690 = GUIButtonCreate(v3, 476, 0, 164, 345, 1, 0, 133, 0, 0, (unsigned char *)"", 0);
  GUIButtonCreate(v3, 61, 424, 31, 0, 2, 94, 110, 1, 49, (unsigned char *)"", 0);
  GUIButtonCreate(v3, 177, 424, 31, 0, 2, 94, 110, 2, 50, (unsigned char *)"", 0);
  GUIButtonCreate(v3, 292, 424, 31, 0, 2, 94, 110, 3, 51, (unsigned char *)"", 0);
  GUIButtonCreate(v3, 407, 424, 31, 0, 2, 94, 110, 4, 52, (unsigned char *)"", 0);
  return (int)v3;
}

//----- (00441D38) --------------------------------------------------------
void GameUI_DrawMinimap(unsigned int uX, unsigned int uY, unsigned int uZ, unsigned int uW, unsigned int uMinimapZoom)
{
  int v8; // eax@8
  int v9; // edx@9
  int v10; // edi@9
  int v11; // ebx@10
  __int16 v12; // cx@11
  int v13; // ecx@17
  int v14; // ecx@21
  int v15; // eax@23
  int v16; // ebx@23
  int v17; // ecx@28
  double v18; // st6@30
  __int16 v20; // di@30
  double v21; // st7@30
  int v24; // eax@37
  unsigned short *v25; // edx@37
  float v27; // ST3C_4@37
  double v28; // ST20_8@37
  double v29; // ST20_8@37
  signed int v30; // edi@40
  _UNKNOWN *v32; // ebx@43
  int v44; // ebx@91
  int v45; // edi@91
  int v52; // ebx@114
  int v53; // ST64_4@114
  int v71; // [sp+20h] [bp-34h]@23
  int v73; // [sp+24h] [bp-30h]@23
  signed int v74; // [sp+24h] [bp-30h]@37
  signed int v76; // [sp+28h] [bp-2Ch]@37
  int v77; // [sp+2Ch] [bp-28h]@30
  signed int v79; // [sp+34h] [bp-20h]@4
  signed int v82; // [sp+38h] [bp-1Ch]@37
  bool v84; // [sp+3Ch] [bp-18h]@2
  int v86; // [sp+40h] [bp-14h]@8
  signed int v93; // [sp+5Ch] [bp+8h]@7
  int i; // [sp+5Ch] [bp+8h]@27
  int v100; // [sp+60h] [bp+Ch]@23
  _UNKNOWN *v102; // [sp+60h] [bp+Ch]@37
  float v103; // [sp+60h] [bp+Ch]@37
  unsigned int v104; // [sp+60h] [bp+Ch]@95
  float v105; // [sp+64h] [bp+10h]@117

 unsigned int  x, y;
 unsigned int *pTargetSurface,
              *pSourceSurface;
 unsigned int  uMinimapCentreX,
               uMinimapCentreY;
 unsigned int  uMinimapWidth,
               uMinimapHeight;
 unsigned int *pMapPixels;
 unsigned int  uMinimapOffsetX,
               uMinimapOffsetY;


  uMinimapCentreX = (uX + uZ) / 2;
  uMinimapCentreY = (uY + uW) / 2;
  v84 = pParty_global->pPartyBuffs[SPELLBUFF_WIZARDEYE].qword_000000 > 0;
  v79 = pParty_global->pPartyBuffs[SPELLBUFF_WIZARDEYE].word_00000A;
  if (CheckHiredNPCSpeciality(0x26))
  {
    v84 = true;
    v79 = 2;
  }

 Render_sub_4A0E97(pD3DRenderer, uX, uY, uZ - 1, uW - 1);

 uMinimapWidth = uZ - uX;
 uMinimapHeight = uW - uY;

 if (dword_6BE360 != 1)
 {
  v20 = LODFile_Icons_LOD.aLODHeaders[struct_576FE8.uTextureID_LocationMap].word_00001C;
  v77 = (1 << (v20 + 16)) / uMinimapZoom;
  v21 = (double)(1 << (16 - (_BYTE)v20));

  //convert world-space xy to texture-space xy
  uMinimapOffsetX = LODFile_Icons_LOD.aLODHeaders[struct_576FE8.uTextureID_LocationMap].uTextureWidth * (32768 + pParty_global->sPartyPosX) / 65536;
  uMinimapOffsetY = LODFile_Icons_LOD.aLODHeaders[struct_576FE8.uTextureID_LocationMap].uTextureHeight * (32768 - pParty_global->sPartyPosY) / 65536;

  uMinimapOffsetX -= uMinimapWidth / (uMinimapZoom / 256);
  uMinimapOffsetY -= uMinimapHeight / (uMinimapZoom / 256);
             
  pMapPixels = LODFile_Icons_LOD.aLODHeaders[struct_576FE8.uTextureID_LocationMap].pTruecolorPixels;
  for (y = 0; y < uMinimapHeight; ++y)
  {
   pTargetSurface = pD3DRenderer->pTargetSurface + (uY + y) * pD3DRenderer->uTargetSurfacePitch + uX;
   pSourceSurface = pMapPixels + (uMinimapOffsetY + y) * LODFile_Icons_LOD.aLODHeaders[struct_576FE8.uTextureID_LocationMap].uTextureWidth + uMinimapOffsetX;
   for (x = 0; x < uMinimapWidth; ++x)
     *pTargetSurface++ = *pSourceSurface++;
  }
  dword_576D14 = 0;
 }
 else
 {
  Render_FillRect2(pD3DRenderer, uX, uY, uMinimapWidth, uMinimapHeight, 15);
  dword_576D14 = 0;
  v93 = 0;
  if ( *(_DWORD *)dword_6BE670 > 0 )
  {
    v86 = 0;
    v8 = dword_6BE644;
    do
    {
      v10 = v86 + dword_6BE670 + 4;
      v9 = *(_DWORD *)(96 * *(_WORD *)(v86 + dword_6BE670 + 8) + v8 + 44);
      if ( BYTE1(v9) & 0x20
        || (v11 = *(_DWORD *)(96 * *(_WORD *)(v86 + dword_6BE670 + 10) + v8 + 44), BYTE1(v11) & 0x20) )
        goto LABEL_26;
      v12 = *(_WORD *)(v86 + dword_6BE670 + 14);
      if ( !(v12 & 1) )
      {
        if ( (_BYTE)v9 >= 0 && (_BYTE)v11 >= 0 )
          goto LABEL_26;
        *(_WORD *)(v86 + dword_6BE670 + 14) = v12 | 1;
        byte_6BE6EC[v93 >> 3] |= 1 << (7 - v93 % 8);
        v8 = dword_6BE644;
      }
      if ( v84
        && v79 >= 3
        && ((v13 = v8 + 96 * *(_WORD *)(v10 + 4), *(_DWORD *)(v13 + 44) & 0x2000000)
         || *(_DWORD *)(96 * *(_WORD *)(v10 + 6) + v8 + 44) & 0x2000000)
        && (*(_WORD *)(dword_6BE64C + 36 * *(_WORD *)(v13 + 72) + 26)
         || *(_WORD *)(dword_6BE64C + 36 * *(_WORD *)(96 * *(_WORD *)(v10 + 6) + v8 + 72) + 26))
        && (v14 = dword_576D14, dword_576D14 < 49) )
      {
        word_576D80[dword_576D14] = v93;
        dword_576D14 = v14 + 1;
      }
      else
      {
        v73 = uMinimapCentreX
            + ((signed int)(((unsigned int)((unsigned __int64)(uMinimapZoom * *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)v10)) >> 16) << 16)
                          - uMinimapZoom * pParty_global->sPartyPosX) >> 16);
        v71 = uMinimapCentreY
            - ((signed int)(((unsigned int)((unsigned __int64)(uMinimapZoom * *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)v10 + 2)) >> 16) << 16)
                          - uMinimapZoom * pParty_global->sPartyPosY) >> 16);
        v100 = uMinimapCentreX
             + ((signed int)(((unsigned int)((unsigned __int64)(uMinimapZoom * *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v10 + 2))) >> 16) << 16)
                           - uMinimapZoom * pParty_global->sPartyPosX) >> 16);
        v16 = uMinimapCentreY
            - ((signed int)(((unsigned int)((unsigned __int64)(uMinimapZoom
                                                             * *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v10 + 2) + 2)) >> 16) << 16)
                          - uMinimapZoom * pParty_global->sPartyPosY) >> 16);
        v15 = abs(*(_WORD *)(v10 + 8) - pParty_global->sPartyPosZ) / 8;
        if ( v15 > 100 )
          v15 = 100;
        //Render_FillRect(pD3DRenderer, v73, v71, v100, v16, *((_WORD *)&unk_5771E4 - v15));
        Render_FillRect(pD3DRenderer, v73, v71, v100, v16, struct_576FE8.pSomeColorTable[200 - v15]);
        v8 = dword_6BE644;
      }
LABEL_26:
      ++v93;
      v86 += 12;
    }
    while ( v93 < *(_DWORD *)dword_6BE670 );
  }
  for ( i = 0; i < dword_576D14; ++i )
  {
    v17 = dword_6BE670 + 12 * (unsigned __int16)word_576D80[i] + 4;
    Render_FillRect(pD3DRenderer,
      uMinimapCentreX
    + ((signed int)(((unsigned int)((unsigned __int64)(uMinimapZoom * *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)v17)) >> 16) << 16)
                  - uMinimapZoom * pParty_global->sPartyPosX) >> 16),
      uMinimapCentreY
    - ((signed int)(((unsigned int)((unsigned __int64)(uMinimapZoom * *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)v17 + 2)) >> 16) << 16)
                  - uMinimapZoom * pParty_global->sPartyPosY) >> 16),
      uMinimapCentreX
    + ((signed int)(((unsigned int)((unsigned __int64)(uMinimapZoom
                                                     * *(_WORD *)(dword_6BE63C
                                                                + 6
                                                                * *(_WORD *)(dword_6BE670
                                                                           + 12 * (unsigned __int16)word_576D80[i]
                                                                           + 6))) >> 16) << 16)
                  - uMinimapZoom * pParty_global->sPartyPosX) >> 16),
      uMinimapCentreY
    - ((signed int)(((unsigned int)((unsigned __int64)(uMinimapZoom
                                                     * *(_WORD *)(dword_6BE63C
                                                                + 6
                                                                * *(_WORD *)(dword_6BE670
                                                                           + 12 * (unsigned __int16)word_576D80[i]
                                                                           + 6)
                                                                + 2)) >> 16) << 16)
                  - uMinimapZoom * pParty_global->sPartyPosY) >> 16),
      0xFF0000FF);
  }
 }

 if (v84)
 {
  for (i = 0; i < uNumLayingItems; ++i)
  {
   if (!pLayingItemsList[i].word_000000 || !pLayingItemsList[i].uObjectDescriptionID || v79 == 1)
     continue;

   v44 = uMinimapCentreX + uMinimapZoom * (pLayingItemsList[i].sItemPosX - pParty_global->sPartyPosX) / 65535;
   v45 = uMinimapCentreY - uMinimapZoom * (pLayingItemsList[i].sItemPosY - pParty_global->sPartyPosY) / 65535;
   if (v44 < pD3DRenderer->dword_00001C || v44 > pD3DRenderer->dword_000024 ||
       v45 < pD3DRenderer->dword_000020 || v45 > pD3DRenderer->dword_000028)
     continue;

   if (pObjectDescriptionList->pDescriptions[pLayingItemsList[i].uObjectDescriptionID].byte_000026 & 0x10)
     Render_FillRect(pD3DRenderer, v44 - 1, v45 - 1, v44 + 1, v45 + 1, 0xFF0000FF);
   else
     Render_FillRect(pD3DRenderer, v44 - 1, v45 - 1, v44 + 1, v45 + 1, 0xFF0000FF);
  }


  for (i = 0; i < uNumActors; ++i)
  {
   if (pActors[i].word_0000B0_state == 11 || pActors[i].word_0000B0_state == 19)
     continue;

   if (pActors[i].word_0000B0_state == 5 || pActors[i].dword_000024 & 0x8000)
   {
    v45 = uMinimapCentreX + uMinimapZoom * (pActors[i].sActorPosX - pParty_global->sPartyPosX) / 65535;
    v44 = uMinimapCentreY - uMinimapZoom * (pActors[i].sActorPosY - pParty_global->sPartyPosY) / 65535;

    if (v45 >= pD3DRenderer->dword_00001C && v45 <= pD3DRenderer->dword_000024 &&
        v44 >= pD3DRenderer->dword_000020 && v44 <= pD3DRenderer->dword_000028)
    {
     v104 = 0xFF00FF00;
     if (*((char *)&pActors[i] + 47) & 1 )
       v104 = 0xFFFF0000;
     if (pActors[i].word_0000B0_state == 5 )
       v104 = 0xFFFFFF00;

     Render_FillRect(pD3DRenderer, v45 - 1, v44 - 1, v45 + 1, v44 + 1, v104);
    }
   }
  }
 }


 for (i = 0; i < uNumLevelDecorations; ++i)
   if (pLevelDecorations[i].word_000002 & 8 )
   {
    v44 = uMinimapCentreX + uMinimapZoom * (pLevelDecorations[i].sPosX - pParty_global->sPartyPosX) / 65536;
    v45 = uMinimapCentreY - uMinimapZoom * (pLevelDecorations[i].sPosY - pParty_global->sPartyPosY) / 65536;
    if (v44 >= pD3DRenderer->dword_00001C && v44 <= pD3DRenderer->dword_000024 &&
        v45 >= pD3DRenderer->dword_000020 && v45 <= pD3DRenderer->dword_000028)
    {
         Render_FillRect(pD3DRenderer, v44 - 1, v45 - 1, v44 + 1, v45 + 1, 0xFFFFFFFF);
    }
   }
#ifndef OLD_CODE 
 Render_DrawTransparentRect(pD3DRenderer, uMinimapCentreX - 3, uMinimapCentreY - 3,
                                  7 * ((pParty_global->sRotationY % 2048) / (2048 / 8)), 0, 7, 7,
                                  &LODFile_Icons_LOD.aLODHeaders[uTextureID_MinimapDirections]); // angle -> [0.. 7]
#endif
#ifdef OLD_CODE 
 
   char angle= ((pParty_global->sRotationY+128)&pClass59_global->uDoublePiMask)>>8;

 
   Render_DrawTransparentTexture(pD3DRenderer, uMinimapCentreX - 3, uMinimapCentreY - 3,&LODFile_Icons_LOD.aLODHeaders[uTextureIdx_MapDirs[angle]]);
#endif
 Render_DrawTransparentTexture(pD3DRenderer, 468, 0, &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_MinimapMask]);

 v105 = (double)pParty_global->sRotationY * 0.1171875;

 Render_Set2DClippingRect(pD3DRenderer, 541, 0, 567, 480);
 Render_DrawIndexedTexture(pD3DRenderer, v105 + 285, 136, &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_MinimapCompass]);
 Render_Reset2DClippingRect(pD3DRenderer);
}

//----- (004151D9) --------------------------------------------------------
void __fastcall DrawWindow(unsigned int uWindowX, unsigned int uWindowY, unsigned int uWindowWidth, unsigned int uWindowHeight)
{
  //int v10; // ebx@14
  //int v11; // [sp+10h] [bp-28h]@5
  //signed int v12; // [sp+18h] [bp-20h]@1
  //int v13; // [sp+1Ch] [bp-1Ch]@7
  //int v14; // [sp+20h] [bp-18h]@1
  unsigned int uNumYTiles;//int v15; // [sp+24h] [bp-14h]@5
  //int v16; // [sp+24h] [bp-14h]@11
  //int v17; // [sp+28h] [bp-10h]@1
  unsigned int uNumXTiles;//int v18; // [sp+2Ch] [bp-Ch]@3
  //int v19; // [sp+2Ch] [bp-Ch]@6
  //int v20; // [sp+2Ch] [bp-Ch]@11
  //int v21; // [sp+30h] [bp-8h]@1
  //int v22; // [sp+34h] [bp-4h]@5
  //int v23; // [sp+34h] [bp-4h]@11
 int x, y;

 cTexture *pcTextureParchment;

 //v17 = uWindowX + uWindowWidth;
 Render_Set2DClippingRect(pD3DRenderer, uWindowX, uWindowY, uWindowX + uWindowWidth, uWindowY + uWindowHeight);


 pcTextureParchment = &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_Parchment];

 uNumXTiles = uWindowWidth / pcTextureParchment->uTextureWidth;
 if (uWindowWidth % pcTextureParchment->uTextureWidth)
   ++uNumXTiles;

 uNumYTiles = uWindowHeight / pcTextureParchment->uTextureHeight;
 if (uWindowHeight % pcTextureParchment->uTextureHeight)
   ++uNumYTiles;


 for (y = 0; y < uNumYTiles; ++y)
   for (x = 0; x < uNumXTiles; ++x)
     Render_DrawIndexedTexture(pD3DRenderer,
                uWindowX + x * pcTextureParchment->uTextureWidth,
                uWindowY + y * pcTextureParchment->uTextureHeight,
                pcTextureParchment);



 //v16 = uWindowY + uWindowHeight - 32;

 Render_DrawTransparentTexture(pD3DRenderer, uWindowX, uWindowY, &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_CornerUpperLeft]);
 Render_DrawTransparentTexture(pD3DRenderer, uWindowX, uWindowY + uWindowHeight - 32, &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_CornerLowerLeft]);
 Render_DrawTransparentTexture(pD3DRenderer, uWindowX + uWindowWidth - 32, uWindowY, &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_CornerUpperRight]);
 Render_DrawTransparentTexture(pD3DRenderer, uWindowX + uWindowWidth - 32, uWindowY + uWindowHeight - 32, &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_CornerLowerRight]);

 
  //v20 = uWindowX + 32;
  //v23 = uWindowY + uWindowHeight - 10;
 if (uWindowWidth > 64)
 {
  Render_Set2DClippingRect(pD3DRenderer, uWindowX + 32, uWindowY, uWindowX + uWindowWidth - 32, uWindowY + uWindowHeight);

  Render_DrawTransparentTexture(pD3DRenderer, uWindowX + 32, uWindowY, &LODFile_Icons_LOD.aLODHeaders[uTextureID_WindowEdgeTop]);
  Render_DrawTransparentTexture(pD3DRenderer, uWindowX + 32, uWindowY + uWindowHeight - 10, &LODFile_Icons_LOD.aLODHeaders[uTextureID_WindowEdgeBottom]);

  if (uWindowWidth > 512)
  {
   Render_DrawTransparentTexture(pD3DRenderer, uWindowX + 544, uWindowY, &LODFile_Icons_LOD.aLODHeaders[uTextureID_WindowEdgeTop]);
   Render_DrawTransparentTexture(pD3DRenderer, uWindowX + 544, uWindowY + uWindowHeight - 10, &LODFile_Icons_LOD.aLODHeaders[uTextureID_WindowEdgeBottom]);
  }
 }

  //v10 = uWindowY + 32;
 if (uWindowHeight > 64)
 {
  Render_Set2DClippingRect(pD3DRenderer, uWindowX, uWindowY + 32, uWindowX + uWindowWidth, uWindowY + uWindowHeight - 32);

  Render_DrawTransparentTexture(pD3DRenderer, uWindowX, uWindowY + 32, &LODFile_Icons_LOD.aLODHeaders[uTextureID_WindowEdgeLeft]);
  Render_DrawTransparentTexture(pD3DRenderer, uWindowX + uWindowWidth - 10, uWindowY + 32, &LODFile_Icons_LOD.aLODHeaders[uTextureID_WindowEdgeRight]);
 }

 Render_Reset2DClippingRect(pD3DRenderer);
}

//----- (0041CD3B) --------------------------------------------------------
struct GUIButton *GUIWindow_GetChild(struct GUIWindow *_this, int uID)
{
 struct GUIButton *v1;
 int               i;

 v1 = _this->pControlsHead;
 for (i = 0; i < uID; ++i)
   v1 = v1->pNext;

 return v1;
}

//----- (00466C40) --------------------------------------------------------
void SetCurrentMenu(unsigned int uMenuID)
{
  if ( uCurrentMenuID == -1 )
  {
    if ( uMenuID != -1 )
    {
      if (pGame->class14_obj->dword_000004 & 0xFF)
      {
        if (pAsyncKeyboard)
          Keyboard_suspend(pAsyncKeyboard);
      }
    }
  }
  else
  {
    if ( uMenuID == -1)
    {
      if (pGame->class14_obj->dword_000004 & 0xFF)
      {
        if (pAsyncKeyboard)
          CAsyncKeyboard_Resume(pAsyncKeyboard);
      }
    }
  }
  uCurrentMenuID = uMenuID;
}

//----- (0041D12F) --------------------------------------------------------
struct GUIButton *GUIButtonCreate(struct GUIWindow *pParentWindow,
                                             unsigned int uX, unsigned int uY,
                                             unsigned int uWidth, unsigned int uHeight,
                                             int a6, int a7, unsigned int uControlID, int a9, unsigned int uHotkey,
											 const unsigned char *pName,class cTexture* pButtnTexture1,
											 class cTexture* pButtnTexture2)
{
  
 struct GUIButton *pButton;

 pButton = (GUIButton *)mem_mng.AllocatedNamedBuffer( NULL, sizeof(struct GUIButton), "BUTTON");

 pButton->uX = uX + pParentWindow->uFrameX;
 pButton->uY = uY + pParentWindow->uFrameY;
 pButton->uWidth = uWidth;
 pButton->uHeight = uHeight;
 if (a6 == 2 && !uHeight)
   pButton->uHeight = uWidth;

 pButton->uZ = uX + pParentWindow->uFrameX + uWidth - 1;
 pButton->uW = uY + pParentWindow->uFrameY + uHeight - 1;
 pButton->dword_000018 = a6;
 pButton->dword_00001C = a7;
 pButton->dword_000020 = uControlID;
 pButton->dword_000024 = a9;
 pButton->dword_00002C = 0;
 pButton->pParentWindow = pParentWindow;

 pButton->uHotkey = uHotkey;
 strcpy((char *)pButton->pButtonName, (char *)pName);

 pButton->uTexturesCount = 0;
 
 if (pButtnTexture1)
	 {
	  pButton->pTexture[pButton->uTexturesCount]=pButtnTexture1;
     pButton->uTexturesCount++;
	 }
 if (pButtnTexture2)
	 {
	
     pButton->pTexture[pButton->uTexturesCount]=pButtnTexture2;
     pButton->uTexturesCount++;
	 }

 if (pParentWindow->pControlsTail)
   pParentWindow->pControlsTail->pNext = pButton;
 else
   pParentWindow->pControlsHead = pButton;

 pButton->pPrev = pParentWindow->pControlsTail;
 pButton->pNext = 0;

 pParentWindow->pControlsTail = pButton;
 pParentWindow->uNumControls++;

 return pButton;
}


//----- (0041C432) --------------------------------------------------------
struct GUIWindow *GUIWindowCreate(unsigned int uFrameX, unsigned int uFrameY,
                                             unsigned int uFrameWidth, unsigned int uFrameHeight,
                                             unsigned int uWindowType, struct GUIButton *a6, int a7)
{
  signed int v7; // eax@1
  int v8; // ebp@1
  //int *v9; // esi@4
  struct GUIWindow *v9;
  int v11; // ebx@15
  char *v12; // ebp@15
  void *v13; // ecx@18
  bool v14; // eax@20
  void *v15; // ecx@23
  bool v16; // eax@25
  void *v17; // ecx@28
  bool v18; // eax@30
  void *v19; // ecx@33
  bool v20; // eax@35
  void *v21; // ecx@38
  bool v22; // eax@40
  void *v23; // ecx@43
  bool v24; // eax@45
  int v25; // eax@65
  int v26; // ebx@65
  int v27; // eax@71
  int v29; // [sp-8h] [bp-18h]@68
  int v30; // [sp-4h] [bp-14h]@68
  char *v31; // [sp+14h] [bp+4h]@15
  int v32; // [sp+14h] [bp+4h]@66
  int v33; // [sp+20h] [bp+10h]@15
 int i;

  v8 = 0;
  for (i = 0; i < 20; ++i)
  {
   if (!GUIWindow_List[i].uWindowType)
     break;
   ++v8;
  }

  v9 = &GUIWindow_List[v8];
  v9->uFrameX = uFrameX;
  v9->uFrameY = uFrameY;
  v9->uFrameWidth = uFrameWidth;
  v9->uFrameHeight = uFrameHeight;
  v9->uFrameZ = uFrameX + uFrameWidth - 1;
  v9->uFrameW = uFrameY + uFrameHeight - 1;
  v9->uWindowType = uWindowType;
  v9->ptr_00001C = a6;
  v9->dword_000044 = 0;
  v9->ptr_000048 = (unsigned char *)a7;

  v9->dword_00003C = ++sLastGUIWindowIdx;
  array_5075E0[sLastGUIWindowIdx] = v8 + 1;

  switch ( uWindowType)
	  {
  case 9:
	  {
	  GUIWindow_sub_411BFC(v9);
	  break;
	  }
  case 10:
	  {
	  dword_506978 = dword_4E28F8;
	  dword_4E28F8 = 4;
	  dword_5076F4 = GUIButtonCreate( v9, 471, 445,	 169,  35,  1,  0,  113, 0,  0,
		  pGlobalTXT_LocalizationStrings[LOCSTR_EXIT],
		  uTextureID_right_backgr != -1 ?  &LODFile_Icons_LOD.aLODHeaders[uTextureID_right_backgr] : 0,0);
	  if (v9->dword_00001C!= 1 )
		  {
		  v33 = 0;
		  v11 = pFontArrus->uFontHeight - 3;
		  v12 = (char *)sub_4459F9_GetNPCData(uDialogue_SpeakingActorID);
		  v31 = v12;
		  if ( sub_445C8B(uDialogue_SpeakingActorID) == 1 )
			  {
			  if ( *((_DWORD *)v31 + 8) )
				  {
				  GUIButtonCreate(v9, 480, 130, 140, v11, 1, 0, 136, 13, 0, (unsigned char *)"", 0);
				  v33 = 1;
				  }
			  v13 = (void *)*((_DWORD *)v31 + 10);
			  if ( v13 )
				  {
				  if ( v33 < 4 )
					  {
					  v14 = sub_4466C4(v13);
					  if ( v14 == 1 || v14 == 2 )
						  GUIButtonCreate(v9, 480, v33++ * v11 + 130, 140, v11, 1, 0, 136, 19, 0, (unsigned char *)"", 0);
					  }
				  }
			  v15 = (void *)*((_DWORD *)v31 + 11);
			  if ( v15 )
				  {
				  if ( v33 < 4 )
					  {
					  v16 = sub_4466C4(v15);
					  if ( v16 == 1 || v16 == 2 )
						  GUIButtonCreate(v9, 480, v33++ * v11 + 130, 140, v11, 1, 0, 136, 20, 0, (unsigned char *)"", 0);
					  }
				  }
			  v17 = (void *)*((_DWORD *)v31 + 12);
			  if ( v17 )
				  {
				  if ( v33 < 4 )
					  {
					  v18 = sub_4466C4(v17);
					  if ( v18 == 1 || v18 == 2 )
						  GUIButtonCreate(v9, 480, v33++ * v11 + 130, 140, v11, 1, 0, 136, 21, 0, (unsigned char *)"", 0);
					  }
				  }
			  v19 = (void *)*((_DWORD *)v31 + 13);
			  if ( v19 )
				  {
				  if ( v33 < 4 )
					  {
					  v20 = sub_4466C4(v19);
					  if ( v20 == 1 || v20 == 2 )
						  GUIButtonCreate(v9, 480, v33++ * v11 + 130, 140, v11, 1, 0, 136, 22, 0, (unsigned char *)"", 0);
					  }
				  }
			  v21 = (void *)*((_DWORD *)v31 + 14);
			  if ( v21 )
				  {
				  if ( v33 < 4 )
					  {
					  v22 = sub_4466C4(v21);
					  if ( v22 == 1 || v22 == 2 )
						  GUIButtonCreate(v9, 480, v33++ * v11 + 130, 140, v11, 1, 0, 136, 23, 0, (unsigned char *)"", 0);
					  }
				  }
			  v23 = (void *)*((_DWORD *)v31 + 15);
			  if ( v23 )
				  {
				  if ( v33 < 4 )
					  {
					  v24 = sub_4466C4(v23);
					  if ( v24 == 1 || v24 == 2 )
						  GUIButtonCreate(v9, 480, v33++ * v11 + 130, 140, v11, 1, 0, 136, 24, 0, (unsigned char *)"", 0);
					  }
				  }
			  }
		  else
			  {
			  if ( *((_DWORD *)v12 + 8) )
				  {
				  GUIButtonCreate(v9, 480, 130, 140, v11, 1, 0, 136, 77, 0, pGlobalTXT_LocalizationStrings[407], 0);
				  if ( v31[8] & 0x80 )
					  {
					  wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[408], *(_DWORD *)v31);
					  GUIButtonCreate(v9, 480, v11 + 130, 140, v11, 1, 0, 136, 76, 0, TmpBuf, 0);
					  }
				  else
					  {
					  GUIButtonCreate(v9, 480, v11 + 130, 140, v11, 1, 0, 136, 76, 0, pGlobalTXT_LocalizationStrings[406], 0);
					  }
				  v33 = 2;
				  }
			  }
		  GUIWindow_sub_41D08F(v9, v33, 1, 0, 1);
		  }
	  break;
	  }
  case 17:
	  {
	  dword_506978 = dword_4E28F8;
	  dword_4E28F8 = 17;
	  dword_5076F4 = GUIButtonCreate(v9, 566, 445,  75,  33, 1,	0,  91,	0,  78,
		  pGlobalTXT_LocalizationStrings[LOCSTR_STAY_IN_AREA],
		  uTextureIdx_BtnEsc2!= -1 ? &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_BtnEsc2]  : NULL,0);
	  dword_5076FC = GUIButtonCreate(v9, 486, 445, 75, 33, 1,  0,  90,  0, 89,
		  v9->ptr_000048,
		  uTextureIdx_BtnYes2!= -1 ? &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_BtnYes2]  : NULL,0);
	  GUIButtonCreate(v9, uDialogueUIIconsOffsetX, uDialogueUIIconsOffsetY, 63, 73, 1, 0, 90, 1, 32, (const unsigned char *)v9->ptr_000048, 0);
	  GUIButtonCreate(v9, 8, 8, 460, 344, 1, 0, 90, 1, 0, (const unsigned char *)v9->ptr_000048, 0);
	  break;
	  }
  case 18:
	  {
	  sub_41192C();
	  sub_411621((void *)v9);
	  break;
	  }
  case 19:
	  {
	  dword_506978 = dword_4E28F8;
	  KeyboardController_sub_459E5A(pKeyboardController, 0, 15, (int)v9);
	  dword_4E28F8 = 19;
	  break;
	  }
  case 25:
	  {
	  dword_4E28F8 = 13;
	  dword_5076F4 = GUIButtonCreate(v9, 471, 445, 169, 35,  1,  0, 113, 0,	0,
		  pGlobalTXT_LocalizationStrings[LOCSTR_EXIT_BLDNG],
		  uTextureID_right_backgr != -1 ? &LODFile_Icons_LOD.aLODHeaders[uTextureID_right_backgr]  : NULL,0);
	  v25 = dword_591424;
	  v26 = 0;
	  if ( dword_591424 > 0 )
		  {
		  do
			  {
			  v32 = v26 + 1;
			  if ( v26 + 1 == v25 && dword_5C35D0 )
				  {
				  v30 = (int)pMapStats->pMapInfos[dword_5C35D0].pLocationName;
				  v29 = (int)pGlobalTXT_LocalizationStrings[LOCSTR_ENTER_S];
				  }
			  else
				  {
				  if ( v26 || !dword_591080 )
					  v27 = *(_DWORD *)dword_5913D8[v26 - (dword_591080 != 0)];
				  else
					  v27 = dword_591440[13 * (int)a6];
				  v30 = v27;
				  v29 = (int)pGlobalTXT_LocalizationStrings[435];
				  }
			  wsprintfA(&byte_591180[100 * v26], (const char *)v29, v30);
			  dword_5913F4[v26] = GUIButtonCreate( v9,
				  *(&uDialogueUIIconsOffsetX + v26 + 6 * dword_591424 - 6),
				  *(&uDialogueUIIconsOffsetY + v26 + 6 * dword_591424 - 6),
				  63, 73, 1, 0,	410, v26,   0,
				  (unsigned char *)&byte_591180[100 * v26],
				  NULL);
			  v26 = v32;
			  v25 = dword_591424;
			  }
			  while ( v32 < dword_591424 );
		  }
	  if ( v25 == 1 )
		  {
		  ptr_507BC0 = &GUIWindow_List[v8];
		  sub_4B4224(0);
		  }
	  break;
	  }
  case 26:
	  {
	  dword_506978 = dword_4E28F8;
	  dword_4E28F8 = 18;
	  dword_5076F4 = GUIButtonCreate(v9, 566, 445, 75, 33, 1, 0, 412, 0, 78,
		  pGlobalTXT_LocalizationStrings[LOCSTR_CANCEL],
		  uTextureIdx_BtnEsc2 + 1 != 0 ? &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_BtnEsc2] : 0,0);
	  dword_5076FC = GUIButtonCreate(v9,   486, 445, 75,  33, 1, 0, 411, 0,	 89, v9->ptr_000048,
		  uTextureIdx_BtnYes2 != -1 ? &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_BtnYes2] : 0,0);
	  GUIButtonCreate(v9, uDialogueUIIconsOffsetX, uDialogueUIIconsOffsetY, 63, 73, 1, 0, 411, 1, 32, v9->ptr_000048, 0);
	  GUIButtonCreate(v9, 8, 8, 460, 344, 1, 0, 411, 1, 0, v9->ptr_000048, 0);
	  break;
	  }
  case 27: 
	  {
	  cClock1.clock_fn1();
	  AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
	  GUICursor_SetCursorBitmap(pGame->pGUICursor, "MICON2");
	  sub_44C175((char *)pGlobalTXT_LocalizationStrings[LOCSTR_SELECT_TGT], 2);
	  break;
	  }
  case 30:
	  {
	  GUIButtonCreate(v9,  61, 424, 31, 0, 2, 94, 110, 1, 49, (unsigned char *)"", 0);
	  GUIButtonCreate(v9, 177, 424, 31, 0, 2, 94, 110, 2, 50, (unsigned char *)"", 0);
	  GUIButtonCreate(v9, 292, 424, 31, 0, 2, 94, 110, 3, 51, (unsigned char *)"", 0);
	  GUIButtonCreate(v9, 407, 424, 31, 0, 2, 94, 110, 4, 52, (unsigned char *)"", 0);
	  GUIButtonCreate(v9,   0,   0,  0, 0, 1,  0, 176, 0,  9, (unsigned char *)"", 0);
	  break;
	  }
  case 31: 
	  {
	  GUICursor_SetCursorBitmap(pGame->pGUICursor, "MICON2");
	  dword_5076F4 = GUIButtonCreate( v9, 392,  318, 75, 33, 1, 0,  113, 0, 0,
		  pGlobalTXT_LocalizationStrings[34],
		  uTextureIdx_BtnEsc2  != -1 ? &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_BtnEsc2]  : 0,0);
	  sub_44C175((char *)pGlobalTXT_LocalizationStrings[LOCSTR_SELECT_TGT], 2);
	   dword_506F48 = 103;
	  dword_4E28F8 = 23;
	  ++LODFile_Icons_LOD.uTexturePacksCount;
	  if ( !LODFile_Icons_LOD.uPrevLoadedFiles )
		  LODFile_Icons_LOD.uPrevLoadedFiles = LODFile_Icons_LOD.uNumLoadedFiles;
	  break;
	  }
	  }
  return v9;
}





//----- (0041C26A) --------------------------------------------------------
void GUIWindowDelete(GUIWindow *_this)
{
  int v1; // esi@1
  signed int v2; // eax@2
  int v3; // eax@5
  int v4; // eax@6
  int v5; // eax@14
  int v6; // eax@15
  int i; // edi@20
  int v8; // eax@26
  int v9; // edi@27
  int v10; // ecx@28
  int v11; // esi@28
  int v12; // edx@29

  v1 = (int)_this;
  if ( _this )
  {
    v2 = *(_DWORD *)(v1 + 24);
    if ( v2 > 18 )
    {
      v5 = v2 - 19;
      if ( !v5 )
      {
        LODFile_Icons_LOD.LODFile_sub_40F9C5();
        dword_4E28F8 = dword_506978;
        KeyboardController_sub_459ED1(pKeyboardController, 3);
        goto LABEL_26;
      }
      v6 = v5 - 6;
      if ( !v6 )
      {
        for ( i = 0; i < dword_591424; ++i )
          cTexture_Free((cTexture *)uTextureID_Dialogue_NPCPortrait[i]);
        cTexture_Free((cTexture *)uTextureID_Dialogue_Background);
        LODFile_Icons_LOD.LODFile_sub_40F9C5();
        dword_591424 = 0;
        LODFile_Icons_LOD.LODFile_sub_4114F2();
        dword_5C35D4 = 0;
        if ( dword_6BE380 )
        {
          pOldCamera->sRotationY = (pClass59_global->uIntegerDoublePi - 1) & (pClass59_global->uIntegerPi + pOldCamera->sRotationY);
          pParty_global->sRotationY = pOldCamera->sRotationY;
        }
        pParty_global->dword_007778 |= 2;
        goto LABEL_26;
      }
      if ( v6 == 1 )
      {
        CVideoPlayer_UnloadAll(pVideoPlayer);
        goto LABEL_18;
      }
    }
    else
    {
      if ( v2 == 18 )
      {
        sub_41140B();
        sub_411473();
      }
      else
      {
        if ( !v2 )
          return;
        v3 = v2 - 9;
        if ( v3 )
        {
          v4 = v3 - 1;
          if ( !v4 )
          {
            if ( !dword_591084 )
              cTexture_Free((cTexture *)uTextureID_Dialogue_NPCPortrait[0]); //fix portait index needed 
            cTexture_Free((cTexture *)uTextureID_Dialogue_Background);
            LODFile_Icons_LOD.LODFile_sub_40F9C5();
            dword_591424 = 0;
            goto LABEL_19;
          }
          if ( v4 != 7 )
            goto LABEL_26;
LABEL_18:
          cTexture_Free((cTexture *)dword_59142C);
          cTexture_Free((cTexture *)uTextureID_Dialogue_Background);
          LODFile_Icons_LOD.LODFile_sub_40F9C5();
LABEL_19:
          dword_4E28F8 = dword_506978;
          goto LABEL_26;
        }
        sub_411597();
      }
    }
LABEL_26:
    v8 = *(_DWORD *)(v1 + 76);
    if ( v8 )
    {
      do
      {
        v9 = *(_DWORD *)(v8 + 52);
        mem_mng.DeleteBuffer( (void *)v8);
        v8 = v9;
      }
      while ( v9 );
    }
    *(_DWORD *)(v1 + 76) = 0;
    *(_DWORD *)(v1 + 80) = 0;
    *(_DWORD *)(v1 + 32) = 0;
    *(_DWORD *)(v1 + 24) = 0;
    v11 = *(_DWORD *)(v1 + 60);
    v10 = sLastGUIWindowIdx;
    while ( v11 < v10 )
    {
      v12 = array_5075E0[v11 + 1];
      array_5075E0[v11] = v12;
      runtime_warning( gui deletes);
      //--*((_DWORD *)pRGBTexture_Menu->word_000018 + 21 * v12);
      ++v11;
    }
    array_5075E0[v10] = 0;
    sLastGUIWindowIdx = v10 - 1;
  }
}







//----- (0049695A) --------------------------------------------------------
void __cdecl PlayerCreationUI_Initialize()
{
  int v1; // ebx@5
  int v2; // eax@6
  signed int v3; // ecx@6
  int v4; // eax@8
  signed int v5; // ecx@8
  int result; // eax@19
  int v8; // [sp+10h] [bp-Ch]@9
  int v9; // [sp+10h] [bp-Ch]@11
  int v10; // [sp+10h] [bp-Ch]@13
  int v11; // [sp+10h] [bp-Ch]@15
  int v13; // [sp+14h] [bp-8h]@9
  int v14; // [sp+14h] [bp-8h]@11
  int v15; // [sp+14h] [bp-8h]@13
  signed int v16; // [sp+14h] [bp-8h]@16

 int i;
 wchar_t pFilename[256];
  if ( dword_50CBD0.msg_count )
			   if  (dword_50CBD0.prm[0].msg_param3)
                          dword_50CBD0.msg_count = 1;

  AudioPlayer_SetVolume(pAudioPlayer, aMusicVolumeLevels[uMusicVolimeMultiplier] * 64.0);

  ++LODFile_Icons_LOD.uTexturePacksCount;
  if ( !LODFile_Icons_LOD.uPrevLoadedFiles )
    LODFile_Icons_LOD.uPrevLoadedFiles = LODFile_Icons_LOD.uNumLoadedFiles;

  dword_4E28F8 = 21;
  dword_A74CD4 = 0;
  dword_A74CCC = 0;
  uPlayerCreationUI_SelectedCharacter = 0;
  v1 = pFontCreate->uFontHeight - 2;
 #ifndef OLD_CODE
  uTextureID_PartyCreationUI_ClassIcons = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ClassIcn");

  pPlayerCreationUI_Sky = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New( L"MAKESKY")];
  pPlayerCreationUI_Top = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New( L"MAKETOP")];

  for (i = 0; i < 25; ++i)
  {
   wsprintfW(pFilename, L"pc%02u-01", i + 1);
   pTextureID_PCFaces[i] = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New( pFilename)];
  }

  uTextureID_PlayerCreationUI_FaceMask = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"FACEMASK");

  uTextureID_PlayerCreationUI_BtnLeft = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"presleft");
  uTextureID_PlayerCreationUI_BtnRight = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"presrigh");
  uTextureID_PlayerCreationUI_BtnMinus = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"buttminu");
  uTextureID_PlayerCreationUI_BtnPlus = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"buttplus");

  uTextureID_PartyCreationUI_Arrows = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"Arrows");
#endif
   #ifdef OLD_CODE
	pPlayerCreatUI_ClIcons[0]= &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("IC_KNIGHT",2)];
	pPlayerCreatUI_ClIcons[1]= &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("IC_THIEF",2)];
	pPlayerCreatUI_ClIcons[2]= &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("IC_MONK",2)];
	pPlayerCreatUI_ClIcons[3]= &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("IC_PALAD",2)];
	pPlayerCreatUI_ClIcons[4]= &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("IC_ARCH",2)];
	pPlayerCreatUI_ClIcons[5]= &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("IC_RANGER",2)];
	pPlayerCreatUI_ClIcons[6]= &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("IC_CLER",2)];
	pPlayerCreatUI_ClIcons[7]= &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("IC_DRUID",2)];
	pPlayerCreatUI_ClIcons[8]= &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("IC_SORC",2)];


  pPlayerCreationUI_Sky = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("MAKESKY",2)];
  pPlayerCreationUI_Top = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("MAKETOP",2)];

  for (i = 0; i < 25; ++i)
  {
  char pFilename[16];
   wsprintf(pFilename, "%s01",portret_names[i]);
   pTextureID_PCFaces[i] =  &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( pFilename,2)];
  }

  uTextureID_PlayerCreationUI_FaceMask = LODFile_Icons_LOD.LODFile_LoadTexture("FACEMASK",2);

  uTextureID_PlayerCreationUI_BtnLeft = LODFile_Icons_LOD.LODFile_LoadTexture("presleft",2);
  uTextureID_PlayerCreationUI_BtnRight = LODFile_Icons_LOD.LODFile_LoadTexture("presrigh",2);
  uTextureID_PlayerCreationUI_BtnMinus = LODFile_Icons_LOD.LODFile_LoadTexture("buttminu",2);
  uTextureID_PlayerCreationUI_BtnPlus = LODFile_Icons_LOD.LODFile_LoadTexture("buttplus",2);
  for (i=1;i<20; i++)
	  {
		char stra1[16];
		sprintf(stra1,"arrowl%d",i);
		pPlayerCreationUI_ArrowL[i] =&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture(stra1,2)] ;
		sprintf(stra1,"arrowr%d",i);
		pPlayerCreationUI_ArrowR[i] =&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture(stra1,2)] ; 
	  }
 // uTextureID_PartyCreationUI_Arrows = LODFile_Icons_LOD.LODFile_LoadTexture("Arrows",2);
#endif
  pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 1, 0, 0);
  v8 = 0;
  v13 = 8;
  do
  {
    GUIButtonCreate(pGUIWindow_CurrentMenu, v13, 120, 145, 25, 1, 0, 60, v8, 0, (unsigned char *)"", 0);
    v13 += 158;
    ++v8;
  }
  while ( v13 < 640 );

  array_A74CAC[0] = GUIButtonCreate(pGUIWindow_CurrentMenu, 10, 32, 11, 13, 1, 0, 171, 0, 0, (unsigned char *)"", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnLeft],0);
  array_A74CAC[1] = GUIButtonCreate(pGUIWindow_CurrentMenu, 169, 32, 11, 13, 1, 0, 171, 1, 0, (unsigned char *)"", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnLeft],0);
  array_A74CAC[2] = GUIButtonCreate(pGUIWindow_CurrentMenu, 327, 32, 11, 13, 1, 0, 171, 2, 0, (unsigned char *)"", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnLeft],0);
  array_A74CAC[3] = GUIButtonCreate(pGUIWindow_CurrentMenu, 486, 32, 11, 13, 1, 0, 171, 3, 0, (unsigned char *)"", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnLeft],0);

  array_A74CBC[0] = GUIButtonCreate(pGUIWindow_CurrentMenu, 74, 32, 11, 13, 1, 0, 172, 0, 0, (unsigned char *)"", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnRight],0);
  array_A74CBC[1] = GUIButtonCreate(pGUIWindow_CurrentMenu, 233, 32, 11, 13, 1, 0, 172, 1, 0, (unsigned char *)"", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnRight],0);
  array_A74CBC[2] = GUIButtonCreate(pGUIWindow_CurrentMenu, 391, 32, 11, 13, 1, 0, 172, 2, 0, (unsigned char *)"", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnRight],0);
  array_A74CBC[3] = GUIButtonCreate(pGUIWindow_CurrentMenu, 549, 32, 11, 13, 1, 0, 172, 3, 0, (unsigned char *)"", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnRight],0);

  array_A74C9C[0] = GUIButtonCreate(pGUIWindow_CurrentMenu, 10, 103, 11, 13, 1, 0, 144, 0, 0, (unsigned char *)"", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnLeft],0);
  array_A74C9C[1] = GUIButtonCreate(pGUIWindow_CurrentMenu, 169, 103, 11, 13, 1, 0, 144, 1, 0, (unsigned char *)"", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnLeft],0);
  array_A74C9C[2] = GUIButtonCreate(pGUIWindow_CurrentMenu, 327, 103, 11, 13, 1, 0, 144, 2, 0, (unsigned char *)"", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnLeft],0);
  array_A74C9C[3] = GUIButtonCreate(pGUIWindow_CurrentMenu, 486, 103, 11, 13, 1, 0, 144, 3, 0, (unsigned char *)"", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnLeft],0);

  array_A74C8C[0] = GUIButtonCreate(pGUIWindow_CurrentMenu, 74, 103, 11, 13, 1, 0, 145, 0, 0, (unsigned char *)"", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnRight],0);
  array_A74C8C[1] = GUIButtonCreate(pGUIWindow_CurrentMenu, 233, 103, 11, 13, 1, 0, 145, 1, 0, (unsigned char *)"", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnRight],0);
  array_A74C8C[2] = GUIButtonCreate(pGUIWindow_CurrentMenu, 391, 103, 11, 13, 1, 0, 145, 2, 0, (unsigned char *)"", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnRight],0);
  array_A74C8C[3] = GUIButtonCreate(pGUIWindow_CurrentMenu, 549, 103, 11, 13, 1, 0, 145, 3, 0, (unsigned char *)"", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnRight],0);

  v9 = 0;
  v14 = 8;
  do
  {
    GUIButtonCreate(pGUIWindow_CurrentMenu, v14, 308, 150, v1, 1, 0, 72, v9, 0, (unsigned char *)"", 0);
    GUIButtonCreate(pGUIWindow_CurrentMenu, v14, v1 + 308, 150, v1, 1, 0, 73, v9, 0, (unsigned char *)"", 0);
    GUIButtonCreate(pGUIWindow_CurrentMenu, v14, 2 * v1 + 308, 150, v1, 1, 0, 74, v9, 0, (unsigned char *)"", 0);
    GUIButtonCreate(pGUIWindow_CurrentMenu, v14, 3 * v1 + 308, 150, v1, 1, 0, 75, v9, 0, (unsigned char *)"", 0);
    v14 += 158;
    ++v9;
  }
  while ( v14 < 640 );

  GUIButtonCreate(pGUIWindow_CurrentMenu, 5, 21, 153, 365, 1, 0, 118, 0, 49, (unsigned char *)"", 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 163, 21, 153, 365, 1, 0, 118, 1, 50, (unsigned char *)"", 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 321, 21, 153, 365, 1, 0, 118, 2, 51, (unsigned char *)"", 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 479, 21, 153, 365, 1, 0, 118, 3, 52, (unsigned char *)"", 0);
  v15 = 23;
  v10 = 2;
  do
  {
    GUIButtonCreate(pGUIWindow_CurrentMenu, v15, 169, 120, 20, 1, 0, 0, v10 - 2, 0, (unsigned char *)"", 0);
    GUIButtonCreate(pGUIWindow_CurrentMenu, v15, v1 + 169, 120, 20, 1, 0, 0, v10 - 1, 0, (unsigned char *)"", 0);
    GUIButtonCreate(pGUIWindow_CurrentMenu, v15, 2 * v1 + 169, 120, 20, 1, 0, 0, v10, 0, (unsigned char *)"", 0);
    GUIButtonCreate(pGUIWindow_CurrentMenu, v15, 3 * v1 + 169, 120, 20, 1, 0, 0, v10 + 1, 0, (unsigned char *)"", 0);
    GUIButtonCreate(pGUIWindow_CurrentMenu, v15, 4 * v1 + 169, 120, 20, 1, 0, 0, v10 + 2, 0, (unsigned char *)"", 0);
    GUIButtonCreate(pGUIWindow_CurrentMenu, v15, 5 * v1 + 169, 120, 20, 1, 0, 0, v10 + 3, 0, (unsigned char *)"", 0);
    GUIButtonCreate(pGUIWindow_CurrentMenu, v15, 6 * v1 + 169, 120, 20, 1, 0, 0, v10 + 4, 0, (unsigned char *)"", 0);
    v10 += 7;
    v15 += 158;
  }
  while ( v10 < 30 );

  GUIWindow_sub_41D08F(pGUIWindow_CurrentMenu, 28, 0, 7, 40);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 323, 417, 65, v1, 1, 0, 65, 0, 0, (unsigned char *)"", 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 323, v1 + 417, 65, v1, 1, 0, 65, 12, 0, (unsigned char *)"", 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 323, 2 * v1 + 417, 65, v1, 1, 0, 65, 20, 0, (unsigned char *)"", 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 388, 417, 65, v1, 1, 0, 65, 24, 0, (unsigned char *)"", 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 388, v1 + 417, 65, v1, 1, 0, 65, 28, 0, (unsigned char *)"", 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 388, 2 * v1 + 417, 65, v1, 1, 0, 65, 32, 0, (unsigned char *)"", 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 453, 417, 65, v1, 1, 0, 65, 16, 0, (unsigned char *)"", 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 453, v1 + 417, 65, v1, 1, 0, 65, 8, 0, (unsigned char *)"", 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 453, 2 * v1 + 417, 65, v1, 1, 0, 65, 4, 0, (unsigned char *)"", 0);

  v11 = 0;
  do
  {
    v16 = -5;
    if ( v11 <= 3 )
      v16 = 0;
    GUIButtonCreate(pGUIWindow_CurrentMenu, 100 * v11 / 3 + v16 + 17, v1 * v11 % 3 + 417, 100, v1, 1, 0, 64, v11, 0, (unsigned char *)"", 0);
    ++v11;
  }
  while ( v11 < 9 );

  pPlayerCreationUI_BtnOK = GUIButtonCreate(pGUIWindow_CurrentMenu,
                                            580, 431,
                                            51,
                                            39,
                                            1,
                                            0,
                                            66,
                                            0,
                                            13,
                                            (unsigned char *)"OK",
                                            &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_BtnMake],0);

  pPlayerCreationUI_BtnReset = GUIButtonCreate(pGUIWindow_CurrentMenu,
                                               527, 431,
                                               51,
                                               39,
                                               1,
                                               0,
                                               67,
                                               0,
                                               67,
                                               (unsigned char *)"Reset",
                                               &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_BtnMake2],0);

  pPlayerCreationUI_BtnMinus = GUIButtonCreate(pGUIWindow_CurrentMenu, 523, 393, 20, 35, 1, 0, 63, 0, 45, (unsigned char *)"BtnMinus", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnMinus],0);
  pPlayerCreationUI_BtnPlus = GUIButtonCreate(pGUIWindow_CurrentMenu, 613, 393, 20, 35, 1, 0, 62, 1, 43, (unsigned char *)"BtnPlus", &LODFile_Icons_LOD.aLODHeaders[uTextureID_PlayerCreationUI_BtnPlus],0);

  pFontCChar = LoadFont("cchar.fnt", "FONTPAL");
}



//----- (004435CD) --------------------------------------------------------
void LevelLoadingUI_UpdateAndDrawProgressBar(struct class56 *_this)
{
 if (++_this->uProgressCurrent > _this->uProgressMax)
   _this->uProgressCurrent = _this->uProgressMax;
 DrawLoadingScreen(_this);
}

//----- (00443484) --------------------------------------------------------
bool LevelLoadingUI_Initialize(struct class56 *_this, unsigned int uProgressBarType)
{
  void *v2; // esi@1
  int v5; // ecx@8
  int v6; // edi@8
  int v7; // edx@14
  const char *v8; // [sp-8h] [bp-84h]@20
  char Str1[32]; // [sp+4h] [bp-78h]@16
  wchar_t Str1W[32];
 int i;

  v2 = _this;
  if ( dword_720010)
    Mouse_suspend(dword_720010);

  if (uProgressBarType)
    _this->uProgressBarType = uProgressBarType;

  if (_this->uProgressBarType == 1)
  {
    v5 = 0;
    for (i = 1; i < 6; ++i)
      if (_this->array_000010[i] == 1)
        ++v5;

  //  v6 = (int)_this->array_000010[0];

    if (v5 == 5 )
      memset(_this->array_000010, 0, 8);

    v7 = rand() % 5 + 1;
    if (_this->array_000010[v7] == 1 )
    {
      do
        v7 = rand() % 5 + 1;
      while ( _this->array_000010[v7] == 1 );
    }
#ifndef OLD_CODE

    wsprintfW(Str1W, L"loading%d", v7);

    _this->uTextureID_Loading = LODFile_Icons_LOD.LODFile_LoadTexture_New( Str1W);
    _this->_addon_loadprog_id_in_Icons_LOD = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"loadprog");
#endif

#ifdef OLD_CODE
    wsprintfA(Str1, "loading%d.pcx", v7);
	// realy or not
	_this->loading=new cPCXTexture;
	_this->loading->PCXTexture_Zero();
    _this->loading->LODPCXLoad( Str1,2); 
    _this->loadprog = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "loadprog",2)];
#endif
    _this->uX = 122;
    _this->uY = 151;
    _this->uWidth = 449;
    _this->uHeight = 56;

    _this->uProgressMax = 26;
    _this->uProgressCurrent = 0;

    DrawLoadingScreen((class56 *)v2);
  }
  else
  {
   if (pParty_global->uAlignment == PARTY_ALIGNMENT_GOOD)
     LODFile_Icons_LOD.LODFile_sub_410522( _this->loadprog, "bardata-b", 2);
   else if (pParty_global->uAlignment == PARTY_ALIGNMENT_NEUTRAL)
     LODFile_Icons_LOD.LODFile_sub_410522(_this->loadprog, "bardata", 2);
   else
     LODFile_Icons_LOD.LODFile_sub_410522( _this->loadprog, "bardata-C", 2);

   *((_BYTE *)v2 + 11) = 0;
   *((_BYTE *)v2 + 10) = 26;
   DrawLoadingScreen((class56 *)v2);
  }
 return true;
}




//----- (00443670) --------------------------------------------------------
void DrawLoadingScreen(struct class56 *_this)
{
  int v1; // edi@1
  int v4; // eax@10
  float v5; // ST2C_4@10

  v1 = (int)_this;
  pD3DRenderer->BeginScene();
  if (_this->uProgressBarType != 1 )
  {
    if ( *(_DWORD *)(v1 + 344) )
    {
      if ( pD3DRenderer->pRenderD3D3 )
      {
        if ( !pD3DRenderer->dword_040058 )
          Render_sub_49FD3A((int)pD3DRenderer, v1);
      }
      Render_DrawIndexedTexture(pD3DRenderer, 80, 122, (cTexture *)(v1 + 296));
      v4 = (int)pIconFrameTable->GetImage(dword_50C984, 0);
      Render_DrawTransparentTexture(pD3DRenderer, 100, 146, (cTexture *)(&LODFile_Icons_LOD.aLODHeaders[(v4 + 30)]));
      v5 = (double)(113 * *(_BYTE *)(v1 + 11)) / (double)*(_BYTE *)(v1 + 10);
      compile_error;//Render_FillRect2(pD3DRenderer, 0, 174, 164, v5 + 6.755399441055744e15, 16, pD3DRenderer->uTargetRMask);

      pD3DRenderer->EndScene();
      pD3DRenderer->Present();
      return;
    }
    pD3DRenderer->EndScene();
    return;
  }
#ifndef OLD_CODE  
  Render_DrawRGBTexture_New(pD3DRenderer, 0, 0, _this->uTextureID_Loading);
#else
  Render_DrawRGBTexture(pD3DRenderer, 0, 0, _this->loading);
#endif
  Render_sub_4A0E97(pD3DRenderer, 0, 0, 639, 479);
  Render_Set2DClippingRect(pD3DRenderer, 172, 459,
    172 + 300 * ((float)(_this->uProgressCurrent) / (float)_this->uProgressMax),
    471);
#ifndef OLD_CODE 
  Render_DrawTransparentTexture(pD3DRenderer, 172, 459, &LODFile_Icons_LOD.aLODHeaders[_this->_addon_loadprog_id_in_Icons_LOD]);
#else
   Render_DrawTransparentTexture(pD3DRenderer, 172, 459, _this->loadprog);
#endif
  Render_Reset2DClippingRect(pD3DRenderer);
  pD3DRenderer->EndScene();
  pD3DRenderer->Present();
}


//----- (004435BB) --------------------------------------------------------
void LevelLoadingUI_Reset(struct class56 *_this, char a2)
{
 _this->byte_000009 = 0;
 _this->uProgressMax = a2;
 _this->uProgressCurrent = 0;
}

//----- (0041C179) --------------------------------------------------------
void __cdecl GameUI_DrawStatusBar()
{
  char *v0; // ebp@1
  int v1; // eax@5
  char *v2; // edi@5
  int v3; // esi@5
  size_t v4; // eax@6
  int v5; // ecx@6
  int v6; // eax@9
  size_t v7; // eax@10
  int v8; // ecx@10
  char v9; // zf@12
  __int16 v10; // ST08_2@13
  int v11; // eax@13

  v0 = *(char **)&dword_507AF8;
  if ( pStatusBarString[0] || dword_5C35B8_Some_GetTickCount_timer || dword_5C35BC )
  {

#ifndef OLD_CODE
    Render_DrawRGBTexture_New(pD3DRenderer, 0, 352, uTextureID_GameUI_StatusBar);
#endif
#ifdef OLD_CODE
    Render_DrawRGBTexture(pD3DRenderer, 0, 352, &cPCXID_GameUI_StatusBar);
#endif
    if ( dword_5C35B8_Some_GetTickCount_timer )
    {
      v2 = (char *)&byte_5C3428;
      v1 = GetStringWidth(pFontLucida, (char *)byte_5C3428);
      v3 = 450;
      while ( v1 > 450 )
      {
        v4 = strlen((char *)&byte_5C3428);
        v5 = (int)pFontLucida;
        byte_5C3427[v4] = 0;
        v1 = GetStringWidth(pFontLucida, (char *)byte_5C3428);
      }
    }
    else
    {
      v2 = (char *)pStatusBarString;
      v6 = GetStringWidth(pFontLucida, (char *)pStatusBarString);
      v3 = 450;
      while ( v6 > 450 )
      {
        v7 = strlen((char *)pStatusBarString);
        v8 = (int)pFontLucida;
        pStatusBarString[v7 - 1] = 0;
        v6 = GetStringWidth(pFontLucida, (char *)pStatusBarString);
      }
    }
    v9 = *v2 == 0;
    dword_5C35BC = 0;
    if ( !v9 )
    {
      v10 = dword_507AFC; //colored or white text flag
      v11 = AlignText_Center(v3, v2, pFontLucida);
      FontDrawText(pGUIWindow0, pFontLucida, v11 + 11, 357, v2, 0xFFFFFFFF, 0, (unsigned int)v0);
    }
  }
}



//----- (0041B3E2) --------------------------------------------------------
void GameUI_DrawFrames()
{
#ifndef OLD_CODE
 Render_DrawRGBTexture_New(pD3DRenderer, 0, 0, uTextureID_GameUI_ViewportTop);
 Render_DrawRGBTexture_New(pD3DRenderer, 0, 8, uTextureID_GameUI_ViewportLeft);
 Render_DrawRGBTexture_New(pD3DRenderer, 468, 0, uTextureID_GameUI_RightPanel);
 Render_DrawRGBTexture_New(pD3DRenderer, 0, 352, uTextureID_GameUI_PartyFrame);
#endif
#ifdef OLD_CODE
 Render_DrawRGBTexture(pD3DRenderer, 0, 0, &cPCXID_GameUI_ViewportTop);
 Render_DrawRGBTexture(pD3DRenderer, 0, 8, &cPCXID_GameUI_ViewportLeft);
 Render_DrawRGBTexture(pD3DRenderer, 468, 0, &cPCXID_GameUI_RightPanel);
 Render_DrawRGBTexture(pD3DRenderer, 0, 352, &cPCXID_GameUI_PartyFrame);
#endif
 GameUI_DrawFoodAndGold();

 sub_41AD6E();
}

//----- (0041AEBB) --------------------------------------------------------
void __cdecl GameUI_DrawFoodAndGold()
{
  __int16 v0; // bx@2
  char *v1; // ebp@2
  int v2; // esi@2

  if ( dword_6A0D48 != 9 )
  {
    v0 = dword_507AFC; //colored or white text
    v1 = *(char **)&dword_507AF8; //final param in DrawText
    v2 = sub_44100D() != 0 ? 381 : 322;
    wsprintfA((char *)TmpBuf, "\r087%lu", pParty_global->uNumFood);
    FontDrawText(pGUIWindow0, pFontSmallnum, 0, v2, (char *)TmpBuf, 0xFFFFFFFF, 0, 0);
    wsprintfA((char *)TmpBuf, "\r028%lu", pParty_global->uNumGold);
    FontDrawText(pGUIWindow0, pFontSmallnum, 0, v2, (char *)TmpBuf, 0xFFFFFFFF, 0, 0);
  }
}

//----- (0044162D) --------------------------------------------------------
void __cdecl GameUI_DrawPartySpells()
{
  signed int v0; // ebp@1
  int v2; // eax@2
  int v3; // ecx@5
  signed int v4; // ebx@25
  int v5; // edi@26
  signed int v6; // [sp-4h] [bp-1Ch]@11
  int v7; // [sp-4h] [bp-1Ch]@12
  signed int v8; // [sp-4h] [bp-1Ch]@20
  int v9; // [sp-4h] [bp-1Ch]@21
 int i;

  v0 = (signed __int64)((double)GetTickCount() * 0.05000000074505806);

 for (i = 0; i < 14; ++i)
  {
    v2 = 16 * (unsigned __int8)byte_4E5DD8[i];
    if (pParty_global->pPartyBuffs[(unsigned __int8)byte_4E5DD8[i]].dword_000004 >= 0 )
    {
     if (pParty_global->pPartyBuffs[(unsigned __int8)byte_4E5DD8[i]].dword_000004 > 0 || pParty_global->pPartyBuffs[(unsigned __int8)byte_4E5DD8[i]].dword_000000 > 0 )
      {
        v3 = uTextureIdx_SpellEffecIcons[i];
        Render_sub_4A65CC(
          (int)pD3DRenderer,
          dword_4E5D68[2 * i],
          dword_4E5D68[2 * i + 1],
          v3 != -1 ? LODFile_Icons_LOD.aLODHeaders[v3].uTextureWidth : 0,
          v3 != -1 ? LODFile_Icons_LOD.aLODHeaders[v3].uTextureHeight : 0,
          v0 + 20 * (unsigned __int8)byte_4E5DE8[i],
          0,
          63);
      }
    }
  }

  if ( !dword_4E28F8 || dword_4E28F8 == 4 )
  {
   if (pParty_global->pPartyBuffs[SPELLBUFF_FLY].qword_000000 > 0 )
    {
      if (pParty_global->dword_000704)
        v6 = v0;
      else
        v6 = 0;
      v7 = (int)&LODFile_Icons_LOD.aLODHeaders[pIconFrameTable->GetImage(uIconIdx_Spell21, v6)->uTextureIdx];
      if ( pD3DRenderer->pRenderD3D3 )
        Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (cTexture *)v7);
      else
        Render_DrawTransparentTexture(pD3DRenderer, 8, 8, (cTexture *)v7);
    }
    if ( HIDWORD(pParty_global->pPartyBuffs[SPELLBUFF_WATERWALK].qword_000000) >= 0 )
    {
      if ( HIDWORD(pParty_global->pPartyBuffs[SPELLBUFF_WATERWALK].qword_000000) > 0 || (_DWORD)pParty_global->pPartyBuffs[SPELLBUFF_WATERWALK].qword_000000)
      {
        if ( pParty_global->dword_007778 & 0x80 )
          v8 = v0;
        else
          v8 = 0;
        v9 = (int)&LODFile_Icons_LOD.aLODHeaders[(int)(pIconFrameTable->GetImage(uIconIdx_Spell27, v8) + 30)] ;
        if ( pD3DRenderer->pRenderD3D3 )
          Render_DrawIndexedTexture(pD3DRenderer, 396, 8, (cTexture *)v9);
        else
          Render_DrawTransparentTexture(pD3DRenderer, 396, 8, (cTexture *)v9);
      }
    }
  }

 // v4 = (signed int)&off_4ED748;

  for (i = 0; i < 4; ++i)
  {
    v5 = (int)pPlayers[i];
    if ( *(_QWORD *)(v5 + 6144) > 0i64 )
      Render_DrawIndexedTexture(pD3DRenderer, off_4ED748[i] + 72, 427, &LODFile_Icons_LOD.aLODHeaders[dword_507964_TextureID]);
    if ( *(_QWORD *)(v5 + 6064) > 0i64 )
      Render_DrawIndexedTexture(pD3DRenderer, off_4ED748[i] + 72, 393, &LODFile_Icons_LOD.aLODHeaders[dword_50796C_TextureID]);
    if ( *(_QWORD *)(v5 + 6224) > 0i64 )
      Render_DrawIndexedTexture(pD3DRenderer, off_4ED748[i] + 72, 410, &LODFile_Icons_LOD.aLODHeaders[dword_507968_TextureID]);
    if ( *(_QWORD *)(v5 + 6208) > 0i64 )
      Render_DrawIndexedTexture(pD3DRenderer, off_4ED748[i] + 72, 444, &LODFile_Icons_LOD.aLODHeaders[dword_507960_TextureID]);
   // v4 += 2;
  }
}


//----- (004435E2) --------------------------------------------------------
void LevelLoadingUI_Release(struct class56 *_this)
{
  void *v1; // esi@1
  int v6; // eax@8
  int v7; // eax@9

  v1 = _this;
 if (dword_720010)
   sub_46B105((void *)dword_720010);
}


//----- (00491CB5) --------------------------------------------------------
char __cdecl LoadPlayerPortraintsAndVoices()
{
  signed int v3; // esi@5
  char result; // al@6

 
 int i, j;

 LODFile_Icons_LOD.lod_IB_dword_011BA0 = LODFile_Icons_LOD.uNumLoadedFiles;
 #ifndef OLD_CODE
 wchar_t pFilename[256];

 for (i = 0; i < 4; ++i)
   for (j = 0; j < 56; ++j)
   {
    wsprintfW(pFilename, L"pc%02u-%02u", pParty_global->pPlayers[i].uFace + 1, j + 1);
    pTextureIdx_PlayerFaces[i][j] = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(pFilename)];
   }

 uTextureIdx_PlayerFaceEradicated = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"Eradcate");
 uTextureIdx_PlayerFaceDead = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"DEAD");
#else
 char pFilename[16];
	 for (i = 0; i < 4; ++i)
   for (j = 0; j < 56; ++j)
   {
    wsprintfA(pFilename, "%s%02d", portret_names[pParty_global->pPlayers[i].uFace], j + 1);
    pTextureIdx_PlayerFaces[i][j] =&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( pFilename,2)];
   }

 uTextureIdx_PlayerFaceEradicated = LODFile_Icons_LOD.LODFile_LoadTexture("Eradcate",2);
 uTextureIdx_PlayerFaceDead = LODFile_Icons_LOD.LODFile_LoadTexture("DEAD",2);
#endif
 

 for (i = 0; i < 4; ++i)
 {
    result = byte_4ED498;
    if ( byte_4ED498 )
    {
     sub_4A9A67(pSoundList, 2 * ((unsigned __int8)byte_4ED498 + 50 * pParty_global->pPlayers[i].dword_001920) + 4998, 0);
     result = sub_4A9A67(pSoundList, 2 * ((unsigned __int8)byte_4ED498 + 50 * pParty_global->pPlayers[i].dword_001920) + 4999, 0);
    }
  }
  return result;
}

//----- (004921C1) --------------------------------------------------------
void GameUI_DrawPortraits(void *_this)
{
  int v1;
  signed int v3; // esi@7
 cTexture *v4; // eax@10
  int v6; // eax@14
  int v7; // eax@17
  //int v8; // eax@21
  int v9; // eax@27
  bool v10; // eax@33
  bool v11; // edi@40
  bool v12; // edx@43
  bool v13; // ecx@46
  int v14; // esi@54
  int v15; // edi@55
  int v16; // eax@57
  int v19; // eax@62
  void *v22; // [sp+14h] [bp-4h]@1
 int i, j;
 struct PlayerFrame *pPlayerFaceIcon;

  v22 = _this;
  if ( qword_A750D8 )
  {
    qword_A750D8 -= cClock2.int_00001C;
    if ( qword_A750D8 <= 0 )
    {
      if ( Player_sub_492C0B_MaybeIfPlayerConscious(pPlayers[word_A750E2]) )
        Player_PlaySound(pPlayers[word_A750E2], word_A750E0, 0);
      qword_A750D8 = 0i64;
    }
  }

  v1 = 0;

  for (i = 0; i < 4; ++i)
  {
   v3 = (int)&pParty_global->pPlayers[i].pConditions[14];

   if (pParty_global->pPlayers[i].pConditions[14] || pParty_global->pPlayers[i].pConditions[16])
   {
    if (pParty_global->pPlayers[i].pConditions[14])
      v4 = &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_PlayerFaceEradicated];
    else if (pParty_global->pPlayers[i].pConditions[16])
      v4 = &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_PlayerFaceDead];

LABEL_27:
      v9 = off_4ED748[i];
      if (pParty_global->pPartyBuffs[11].qword_000000)
        sub_4A6E7E((int)pD3DRenderer, v9, 387, (int)v4);
      else
        Render_DrawTransparentTexture(pD3DRenderer, v9 + 1, 388, v4);
      v10 = *(_DWORD *)(v3 + 6164) >= v1 && (*(_DWORD *)(v3 + 6164) > v1 || *(_DWORD *)(v3 + 6160) > (unsigned int)v1);
      if ( *(_DWORD *)(v3 + 5956) >= v1 )
      {
        if ( *(_DWORD *)(v3 + 5956) > v1 || *(_DWORD *)(v3 + 5952) > (unsigned int)v1 )
          v1 = 1;
      }
      v11 = *(_QWORD *)(v3 + 6064) > 0i64;
      v12 = *(_QWORD *)(v3 + 6048) > 0i64;
      v13 = *(_QWORD *)(v3 + 6144) > 0i64;
      if ( v13 | v12 | v11 | v1 | v10 )
        sub_441A4E((void *)i);
      continue;
    }


    v7 = 1;
    for (j = 0; j < pPlayerFrameTable->uNumFrames; ++j)
      if (pPlayerFrameTable->pFrames[j].word_000000 == pParty_global->pPlayers[i].uDefaultFaceID)
      {
       v7 = j;
       break;
      }

    if (pParty_global->pPlayers[i].uDefaultFaceID == 21)
      pPlayerFaceIcon = pPlayerFrameTable->PlayerFrameTable_sub_494B5E((int)&pParty_global->pPlayers[i].dword_001AA8,
                                   (int)&pParty_global->pPlayers[i].dword_001AA4, cClock2.int_00001C);
    else
      pPlayerFaceIcon = pPlayerFrameTable->GetFrameFromFrameset(v7, pParty_global->pPlayers[i].word_001A9E);

    if (pParty_global->pPlayers[i].word_001AA2 != pPlayerFaceIcon->uTextureID - 1 || v22)
    {
     pParty_global->pPlayers[i].word_001AA2 = pPlayerFaceIcon->uTextureID - 1;
     v1 = 0;
     v4 = pTextureIdx_PlayerFaces[i][pPlayerFaceIcon->uTextureID - 1];
     goto LABEL_27;
    }
  }

  
  if ( pParty_global->dword_00087C == 1 )
  {
    if ( dword_4F885C != 1 )
    {
      if ( (dword_4F8878[0] & 7) == 4 )
      {
        v14 = 0;
        if ( dword_4F8864 > 0 )
        {
          v15 = (int)dword_4F8878;
          do
          {
            if ( (*(_BYTE *)v15 & 7) != 4 )
              break;
            v16 = uTextureIdx_SensorGreen;
            if ( pParty_global->dword_007778 & 0x10 )
            {
              v16 = dword_5079CC;
            }
            else
            {
              if ( pParty_global->dword_007778 & 0x20 )
                v16 = dword_5079C8;
            }
            Render_DrawTransparentTexture(pD3DRenderer, off_4ED748[*(_DWORD *)v15 >> 3] - 4, 385, (v16 != -1 ? &LODFile_Icons_LOD.aLODHeaders[ v16] : 0));
            ++v14;
            v15 += 16;
          }
          while ( v14 < dword_4F8864 );
        }
      }
    }
  }
  else
  {
    for (i = 0; i < 4; ++i)
    {
      if (Player_sub_492C0B_MaybeIfPlayerConscious(&pParty_global->pPlayers[i]))
      {
        if (!pParty_global->pPlayers[i].uTimeToRecovery)
        {
          v19 = uTextureIdx_SensorGreen;
          if ( pParty_global->dword_007778 & 0x10 )
            v19 = dword_5079CC;
          else if ( pParty_global->dword_007778 & 0x20 )
              v19 = dword_5079C8;
          Render_DrawTransparentTexture(pD3DRenderer, off_4ED748[i] - 4, 385, &LODFile_Icons_LOD.aLODHeaders[v19]);
        }
      }
    }
  }
}

//----- (00415180) -----.text:004155EC  ---------------------------------------------------
void GUIButton_sub_415180(struct GUIButton *a1, const unsigned char *a2, struct Font *a3, __int16 a4, char *a5)
{
  const char *v6; // ebx@1
  int v7; // esi@1
  int v8; // eax@1

  v6 = (char *)a2;
  v7 = (int)a1;
 // strlen((char *)a2);
  v8 = GetStringWidth(a3, v6);
  FontDrawText( a1->pParentWindow,
           a3,
		  a1->uX+(a1->uWidth-v8)/2,
          // *(_DWORD *)v7 + (*(_DWORD *)(v7 + 8) - v8) / 2,
		  a1->uY+(a1->uHeight-a3->uFontHeight)/2 ,
        //   *(_DWORD *)(v7 + 4) + (*(_DWORD *)(v7 + 12) - *(_BYTE *)(a3 + 5)) / 2,
           //a4,//colored or white text flag
           (const char *)a2,
           0,
           0,
           (unsigned int)a5);
}



//----- (0044158F) --------------------------------------------------------
void GameUI_DrawCharacterSelectionFrame()
{
 if (uActiveCharacter)
   Render_DrawTransparentTexture(pD3DRenderer, off_4ED748[uActiveCharacter - 1] - 9, 380, &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_CharacterSelectionFrame]);
}

//----- (0041B0C9) -------.text:0041B71E  -------------------------------------------------
void __cdecl GameUI_DrawLifeManaBars()
{
  cTexture *cBarGreen; // ebx@1
  Player *v1; // ecx@2
  double v2; // st7@3
 
  signed __int64 v4; // qax@6
  int v5; // ecx@24
  double v6; // st7@25
  float v7; // ST30_4@25
  bool v8; // ST38_4@27
  cTexture *v9; // [sp-4h] [bp-30h]@10
  cTexture *cBarBlue; // [sp+Ch] [bp-20h]@1
  int *v11; // [sp+10h] [bp-1Ch]@2
  signed int v12; // [sp+10h] [bp-1Ch]@24
  cTexture *cBarRed; // [sp+14h] [bp-18h]@1
  cTexture *cBarYellow; // [sp+18h] [bp-14h]@1
  float max_health_bar; // [sp+1Ch] [bp-10h]@1
  signed int player_num; // [sp+24h] [bp-8h]@1
  signed int v17; // [sp+28h] [bp-4h]@8

  cBarGreen =  uTextureIdx_UIBarGreen!=-1? &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_UIBarGreen] : NULL;
  cBarYellow = uTextureIdx_UIBarYellow!=-1?  &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_UIBarYellow]: NULL;
  cBarRed =    uTextureIdx_UIBarRed!=-1? &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_UIBarRed]: NULL;
  player_num = 0;
  cBarBlue =  uTextureIdx_UIBarBlue!=-1? &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_UIBarBlue]: NULL;
  max_health_bar = (double)LODFile_Icons_LOD.aLODHeaders[uTextureIdx_UIBarGreen].uTextureHeight;
  for(player_num=0; player_num<4;player_num++)
	  {
	  v1 = &pParty_global->pPlayers[player_num];
	  // v11 = (int *)v1;
	  if (v1->sHealth> 0 )
		  {
		  //  goto LABEL_24;
		  //  v11 = (int *)&pParty_global->pPlayers[player_num];

		  v2 = (double)(v1->sHealth) / (double)Player_GetMaxHealth(v1);	 
		  if ( player_num == 2 || player_num == 3 )
			  v17 = 2;
		  else
			  v17 = 0;
		  if ( v2 > 0.0 )
			  {
			  if ( v2 <= 0.5 )
				  {
				  if ( v2 <= 0.25 )
					  {

					  Render_Set2DClippingRect(
						  pD3DRenderer,
						  v17 + uHealthBarPos[player_num],
						  (signed __int64)((1.0 - v2) * max_health_bar) + 402,
						  v17 + uHealthBarPos[player_num] +  cBarRed->uTextureWidth,
						  cBarRed->uTextureHeight + 402);
					  v9 = cBarRed;

					  }
				  else
					  {

					  Render_Set2DClippingRect(
						  pD3DRenderer,
						  v17 + uHealthBarPos[player_num],
						  (signed __int64)((1.0 - v2) * max_health_bar) + 402,
						  v17 + uHealthBarPos[player_num] + cBarYellow->uTextureWidth,
						  cBarYellow->uTextureHeight + 402);
					  v9 = cBarYellow;
					  }
				  }
			  else
				  {
				  if ( v2 > 1.0 )
					  v2 = 1.0;
				  Render_Set2DClippingRect(
					  pD3DRenderer,
					  v17 + uHealthBarPos[player_num],
					  (signed __int64)((1.0 - v2) * max_health_bar) + 402,
					  v17 + uHealthBarPos[player_num] +cBarGreen->uTextureWidth,
					  cBarGreen->uTextureHeight + 402);
				  v9 = cBarGreen;
				  }
			  Render_DrawIndexedTexture(pD3DRenderer, v17 + uHealthBarPos[player_num], 402, v9);
			  Render_Reset2DClippingRect(pD3DRenderer);
			  }
		  }
	  //LABEL_24:
	  // v5 = (int)v11;
	  v12 =v1->sMana;
	  if ( v12 > 0 )
		  {
		  // v7 = (double)v12;
		  v6 = (double)v12 / (double)Player_GetMaxMana(v1);
		  if ( v6 > 1.0 )
			  v6 = 1.0;
		  v8 =0;
		  if (player_num==2)
			  v8 =1;
		  Render_Set2DClippingRect(
			  pD3DRenderer,
			  v8 + uManaBarPos[player_num],
			  (signed __int64)((1.0 - v6) *  max_health_bar) + 402,
			  v8 + uManaBarPos[player_num] + cBarBlue->uTextureWidth,
			  cBarBlue->uTextureHeight + 402);
		  Render_DrawIndexedTexture(pD3DRenderer,v8+ uManaBarPos[player_num], 402, cBarBlue);
		  Render_Reset2DClippingRect(pD3DRenderer);
		  }
	  }
}

//----- (00441498) --------------------------------------------------------
void __cdecl GameUI_DrawTorchlightAndWizardEye()
{
  signed int v0; // eax@15
  int v1; // eax@15
  signed int v2; // eax@19
  int v3; // eax@19

  if ( !dword_4E28F8
    || dword_4E28F8 == 1
    || dword_4E28F8 == 2
    || dword_4E28F8 == 5
    || dword_4E28F8 == 8
    || dword_4E28F8 == 10
    || dword_4E28F8 == 11
    || dword_4E28F8 == 12
    || dword_4E28F8 == 15
    || dword_4E28F8 == 3
    || dword_4E28F8 == 19 )
  {
   if ( HIDWORD(pParty_global->pPartyBuffs[16].qword_000000) >= 0 )
    {
     if ( HIDWORD(pParty_global->pPartyBuffs[16].qword_000000) > 0 || (_DWORD)pParty_global->pPartyBuffs[16].qword_000000 )
      {
        v0 = cClock1.clock_fn2();;
        v1 = (int)pIconFrameTable->GetImage(array_6A0D14[2].uIconIdx, v0);
        Render_DrawTransparentTexture(pD3DRenderer, array_6A0D14[2].word_000008, array_6A0D14[2].word_00000A, (cTexture *)(72 * *(_WORD *)(v1 + 30) + 0x6D084C));
      }
    }
   if ( HIDWORD(pParty_global->pPartyBuffs[SPELLBUFF_WIZARDEYE].qword_000000) >= 0 )
    {
     if (HIDWORD(pParty_global->pPartyBuffs[SPELLBUFF_WIZARDEYE].qword_000000) > 0 || LODWORD(pParty_global->pPartyBuffs[SPELLBUFF_WIZARDEYE].qword_000000))
      {
        v2 = cClock1.clock_fn2();;
        v3 = (int)pIconFrameTable->GetImage(array_6A0D14[3].uIconIdx, v2);
        Render_DrawTransparentTexture(pD3DRenderer, array_6A0D14[3].word_000008, array_6A0D14[3].word_00000A, (cTexture *)(72 * *(_WORD *)(v3 + 30) + 0x6D084C));
      }
    }
  }
}

//----- (00418511) --------------------------------------------------------
void CharacterUI_DrawStatsTab(unsigned int uSelectedCharacter) // character stats tab
{
  struct Player *pPlayer; // edi@1
  int v2; // eax@1
  unsigned int uClr; // eax@2
  int v5; // ebp@4
  int v6; // ST20_4@4
  int v7; // ST1C_4@4
  int v8; // ebp@4
  int v9; // eax@4
  unsigned int v10; // eax@4
  int v11; // ST34_4@4
  int v12; // ST20_4@4
  int v13; // ST1C_4@4
  int v14; // ebp@4
  int v15; // eax@4
  unsigned int v16; // eax@4
  int v17; // ST34_4@4
  int v18; // ST20_4@4
  int v19; // ST1C_4@4
  int v20; // ebp@4
  int v21; // eax@4
  unsigned int v22; // eax@4
  int v23; // ST34_4@4
  int v24; // ST20_4@4
  int v25; // ST1C_4@4
  int v26; // ebp@4
  int v27; // eax@4
  unsigned int v28; // eax@4
  int v29; // ST34_4@4
  int v30; // ST20_4@4
  int v31; // ST1C_4@4
  int v32; // ebp@4
  int v33; // eax@4
  unsigned int v34; // eax@4
  int v35; // ST34_4@4
  int v36; // ST20_4@4
  int v37; // ST1C_4@4
  int v38; // ebp@4
  int v39; // eax@4
  unsigned int v40; // eax@4
  int v41; // ST34_4@4
  int v42; // ST20_4@4
  int v43; // ST1C_4@4
  int v44; // ebp@4
  int v45; // eax@4
  unsigned int v46; // eax@4
  signed int v47; // ST20_4@6
  signed int v49; // eax@6
  unsigned int v50; // eax@6
  unsigned __int8 v51; // al@8
  int v52; // ebp@8
  int v53; // ST20_4@8
  int v55; // eax@8
  unsigned int v56; // eax@8
  int v57; // ST34_4@8
  int v58; // ST20_4@8
  int v59; // ST1C_4@8
  int v60; // ebp@8
  int v61; // eax@8
  unsigned int v62; // eax@8
  int v63; // ebp@8
  int v64; // eax@8
  char *v65; // ST20_4@8
  signed int v66; // eax@8
  char *v67; // eax@9
  int v68; // ST20_4@11
  int v69; // ST1C_4@11
  int v70; // ebp@11
  int v71; // eax@11
  unsigned int v72; // eax@11
  int v73; // ST20_4@13
  int v74; // ST1C_4@13
  int v75; // ebp@13
  int v76; // eax@13
  unsigned int v77; // eax@13
  int v78; // ecx@14
  int v79; // eax@16
  unsigned int v82; // eax@16
  int v83; // ST34_4@16
  int v84; // eax@16
  int v85; // ST34_4@16
  char *v86; // eax@16
  int v87; // ST34_4@16
  int v88; // eax@16
  int v89; // ST34_4@16
  char *v90; // eax@16
  int v91; // eax@19
  int v92; // ST20_4@19
  unsigned int v93; // eax@19
  int v94; // eax@22
  unsigned int v96; // eax@22
  int v97; // eax@25
  unsigned int v99; // eax@25
  int v100; // eax@27
  unsigned int v102; // eax@27
  unsigned int v104; // eax@30
  unsigned int v106; // eax@32
  int v107; // eax@33
  unsigned int v109; // eax@36
  unsigned int v111; // eax@38
  int v113; // [sp+10h] [bp-10h]@6
  int v114; // [sp+10h] [bp-10h]@11
  int v115; // [sp+10h] [bp-10h]@13
  int v116; // [sp+10h] [bp-10h]@16
  int v117; // [sp+10h] [bp-10h]@19
  int v118; // [sp+10h] [bp-10h]@22
  int v119; // [sp+10h] [bp-10h]@25
  int v120; // [sp+10h] [bp-10h]@27
  int v121; // [sp+10h] [bp-10h]@33
  const char *v122; // [sp+14h] [bp-Ch]@4
  const char *v123; // [sp+14h] [bp-Ch]@6
  const char *v124; // [sp+14h] [bp-Ch]@11
  const char *v125; // [sp+14h] [bp-Ch]@16
  const char *v126; // [sp+14h] [bp-Ch]@19
  const char *v127; // [sp+14h] [bp-Ch]@22
  const char *v128; // [sp+14h] [bp-Ch]@25
  const char *v129; // [sp+14h] [bp-Ch]@27
  const char *v130; // [sp+14h] [bp-Ch]@33
  int v131; // [sp+18h] [bp-8h]@16
  int v132; // [sp+18h] [bp-8h]@19
  int v133; // [sp+18h] [bp-8h]@22
  int v134; // [sp+18h] [bp-8h]@25
  int v135; // [sp+18h] [bp-8h]@27
  int v136; // [sp+18h] [bp-8h]@33
  int v137; // [sp+1Ch] [bp-4h]@27
  int v138; // [sp+1Ch] [bp-4h]@33

 pPlayer = pPlayers[uSelectedCharacter - 1];

#ifndef OLD_CODE
 Render_DrawIndexedTexture(pD3DRenderer, 8, 8, &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(L"fr_stats")]);
#else
 Render_DrawIndexedTexture(pD3DRenderer, 8, 8, &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture("fr_stats", 2)]);
#endif
  

 wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_S_THE_S], pPlayer->sName, aClassNames[pPlayer->uClass]);
 strcpy((char *)TmpBuf, (char *)pStringBuffer);
 if (pPlayer->uSkillPoints)
   uClr = 0x00FF00;
 else
   uClr = 0xFFFFFF;

  wsprintfA((char *)pStringBuffer, "\f000000\r180%s: \f%06x%d\f000000\n\n\n", pGlobalTXT_LocalizationStrings[LOCSTR_SKILL_POINTS], uClr, pPlayer->uSkillPoints);
  strcat((char *)TmpBuf, (char *)pStringBuffer);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 26, 18, (char *)TmpBuf, 0xFFFF9B, 0, 0);

  v6 = Player_GetBaseStrength(pPlayer);
  v7 = Player_GetActualStrength(pPlayer);
  v10 = sub_4178FE_GetColor(v7, v6);
  wsprintfA((char *)TmpBuf, "%s\f%06x\r424%d\f000000 /\t185%d\n", pGlobalTXT_LocalizationStrings[LOCSTR_MIGHT], v10, v7, v6);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 26, 53, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v11 = pFontArrus->uFontHeight + 51;
  v12 = Player_GetBaseIntelligence(pPlayer);
  v13 = Player_GetActualIntelligence(pPlayer);
  v16 = sub_4178FE_GetColor(v13, v12);
  wsprintfA((char *)TmpBuf, "%s\f%06x\r424%d\f000000 /\t185%d\n", pGlobalTXT_LocalizationStrings[116], v16, v13, v12);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 26, v11, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v17 = v11 - 2 + pFontArrus->uFontHeight;
  v18 = Player_GetBaseWillpower(pPlayer);
  v19 = Player_GetActualWillpower(pPlayer);
  v22 = sub_4178FE_GetColor(v19, v18);
  wsprintfA((char *)TmpBuf, "%s\f%06x\r424%d\f000000 /\t185%d\n", pGlobalTXT_LocalizationStrings[163], v22, v19, v18);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 26, v17, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v23 = v17 - 2 + pFontArrus->uFontHeight;
  v24 = Player_GetBaseEndurance(pPlayer);
  v25 = Player_GetActualEndurance(pPlayer);
  v28 = sub_4178FE_GetColor(v25, v24);
  wsprintfA((char *)TmpBuf, "%s\f%06x\r424%d\f000000 /\t185%d\n", pGlobalTXT_LocalizationStrings[75], v28, v25, v24);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 26, v23, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v29 = v23 - 2 + pFontArrus->uFontHeight;
  v30 = Player_GetBaseAccuracy(pPlayer);
  v31 = Player_GetActualAccuracy(pPlayer);
  v34 = sub_4178FE_GetColor(v31, v30);
  wsprintfA((char *)TmpBuf, "%s\f%06x\r424%d\f000000 /\t185%d\n", pGlobalTXT_LocalizationStrings[LOCSTR_ACCURACY], v34, v31, v30);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 26, v29, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v35 = v29 - 2 + pFontArrus->uFontHeight;
  v36 = Player_GetBaseSpeed(pPlayer);
  v37 = Player_GetActualSpeed(pPlayer);
  v40 = sub_4178FE_GetColor(v37, v36);
  wsprintfA((char *)TmpBuf, "%s\f%06x\r424%d\f000000 /\t185%d\n", pGlobalTXT_LocalizationStrings[211], v40, v37, v36);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 26, v35, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v41 = v35 - 2 + pFontArrus->uFontHeight;
  v42 = Player_GetBaseLuck(pPlayer);
  v43 = Player_GetActualLuck(pPlayer);
  v46 = sub_4178FE_GetColor(v43, v42);
  wsprintfA((char *)TmpBuf, "%s\f%06x\r424%d\f000000 /\t185%d\n\n", pGlobalTXT_LocalizationStrings[136], v46, v43, v42);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 26, v41, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v122 = "%s\f%06x\r424%d\f000000 /\t185%d\n";
  v5 = v41 + 5 + 2 * pFontArrus->uFontHeight;
  if ( Player_GetMaxHealth(pPlayer) >= 1000 )
    v122 = "%s\f%06x\r388%d\f000000 / %d\n";
  v47 = Player_GetMaxHealth(pPlayer);
  v50 = sub_4178FE_GetColor(pPlayer->sHealth, v47);
  wsprintfA((char *)TmpBuf, v122, pGlobalTXT_LocalizationStrings[108], v50, pPlayer->sHealth, v47);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 26, v5, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v123 = "%s\f%06x\r424%d\f000000 /\t185%d\n";
  v113 = v5 - 2 + pFontArrus->uFontHeight;
  if ( Player_GetMaxMana(pPlayer) >= 1000 )
    v123 = "%s\f%06x\r388%d\f000000 / %d\n";
  v53 = Player_GetMaxMana(pPlayer);
  v56 = sub_4178FE_GetColor(pPlayer->sMana, v53);
  wsprintfA((char *)TmpBuf, v123, pGlobalTXT_LocalizationStrings[212], v56, pPlayer->sMana, v53);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 26, v113, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v57 = v113 - 2 + pFontArrus->uFontHeight;
  v58 = Player_sub_48E656((int)pPlayer);
  v59 = Player_sub_48E68F((int)pPlayer);
  v62 = sub_4178FE_GetColor(v59, v58);
  wsprintfA((char *)TmpBuf, "%s\f%06x\r424%d\f000000 /\t185%d\n\n", pGlobalTXT_LocalizationStrings[12], v62, v59, v58);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 26, v57, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v63 = v57 - 2 + 2 * pFontArrus->uFontHeight;
  v64 = Player_GetConditionIdx(pPlayer);
  //v65 = (&dword_AE3280)[4 * v64];
  v65 = (char *)aCharacterConditionNames[v64];

  v66 = sub_417939(v64);
  wsprintfA((char *)TmpBuf, "%s: \f%06x%s\n", pGlobalTXT_LocalizationStrings[LOCSTR_CONDITION], v66, v65);
  GUIWindow_sub_44CB4F(pGUIWindow_CurrentMenu, pFontArrus, 26, v63, 0, (char *)TmpBuf, 226, 0);

  v52 = v63 - 1 + pFontArrus->uFontHeight;
  v51 = pPlayer->uQuickSpell;

  if ( v51 )
    v67 = (char *) pSpellStats->pSpellInfos[v51].pSpellNameShort;
  else
    v67 = (char *)pGlobalTXT_LocalizationStrings[153];
  wsprintfA((char *)TmpBuf, "%s: %s", pGlobalTXT_LocalizationStrings[172], v67);
  GUIWindow_sub_44CB4F(pGUIWindow_CurrentMenu, pFontArrus, 26, v52, 0, (char *)TmpBuf, 226, 0);

  v68 = Player_GetBaseAge(pPlayer);
  v69 = Player_GetActualAge(pPlayer);
  v72 = sub_4178FE_GetColor(v68, v69);
  wsprintfA((char *)TmpBuf, "%s\f%06x\t100%d\f000000 / %d\n", pGlobalTXT_LocalizationStrings[5], v72, v69, v68);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 266, 50, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v124 = "%s\f%06x\t100%d\f000000 / %d\n";
  v114 = pFontArrus->uFontHeight + 48;
  if ( Player_GetBaseLevel(pPlayer) > 99 )
    v124 = "%s\f%06x\t180%d\f000000 / %d\n";
  v73 = Player_GetBaseLevel(pPlayer);
  v74 = Player_GetActualLevel(pPlayer);
  v77 = sub_4178FE_GetColor(v74, v73);
  wsprintfA((char *)TmpBuf, v124, pGlobalTXT_LocalizationStrings[131], v77, v74, v73);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 266, v114, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v115 = v114 + pFontArrus->uFontHeight - 2;
  if (pPlayer->uExperience <= 9999999)
    v78 = (int)pGlobalTXT_LocalizationStrings[83];
  else
    v78 = (int)pGlobalTXT_LocalizationStrings[17];
  v82 = Player_sub_48D498((int)pPlayer);
  wsprintfA((char *)TmpBuf, "%s\r180\f%06x%lu\f000000\n\n", v78, v82, pPlayer->uExperience);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 266, v115, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v83 = v115 + 2 * pFontArrus->uFontHeight;
  v84 = Player_GetAttackBonus(pPlayer, 0);
 // wsprintfA((char *)TmpBuf, "%s\t100%+d\n", pGlobalTXT_LocalizationStrings[18], v84);
  StringCbPrintf((char *)TmpBuf,50 ,"%s\t100%+d\n", pGlobalTXT_LocalizationStrings[18], v84);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 266, v83, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v85 = v83 + pFontArrus->uFontHeight - 2;
  v86 = Player_GetMeleeDamage_String(pPlayer);
  wsprintfA((char *)TmpBuf, "%s\t100 %s\n", pGlobalTXT_LocalizationStrings[53], v86);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 266, v85, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v87 = v85 + pFontArrus->uFontHeight - 2;
  v88 = Player_sub_48D0B9(pPlayer);
  //wsprintfA((char *)TmpBuf, "%s\t100%+d\n", pGlobalTXT_LocalizationStrings[203], v88);
  StringCbPrintf((char *)TmpBuf,50 ,"%s\t100%+d\n", pGlobalTXT_LocalizationStrings[203], v88);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 266, v87, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v89 = v87 + pFontArrus->uFontHeight - 2;
  v90 = Player_sub_48D396((int)pPlayer);
  wsprintfA((char *)TmpBuf, "%s\t100 %s\n\n", pGlobalTXT_LocalizationStrings[53], v90);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 266, v89, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v125 = "%s\f%06x\t110%d\f000000 / %d\n";
  v116 = v89 + 2 * pFontArrus->uFontHeight - 4;
  v131 = Player_GetActualResistance(pPlayer, 10);
  v79 = Player_GetBaseResistance(pPlayer, 10);
  if ( v131 > 99 || v79 > 99 )
    v125 = "%s\f%06x\t180%d\f000000 / %d\n";
  v92 = v79;
  v93 = sub_4178FE_GetColor(v131, v79);
  wsprintfA((char *)TmpBuf, v125, pGlobalTXT_LocalizationStrings[87], v93, v131, v92);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 266, v116, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v126 = "%s\f%06x\t110%d\f000000 / %d\n";
  v117 = v116 + pFontArrus->uFontHeight - 2;
  v132 = Player_GetActualResistance(pPlayer, 11);
  v91 = Player_GetBaseResistance(pPlayer, 11);
  if ( v132 > 99 || v91 > 99 )
    v126 = "%s\f%06x\t180%d\f000000 / %d\n";
  v96 = sub_4178FE_GetColor(v132, v91);
  wsprintfA((char *)TmpBuf, v126, pGlobalTXT_LocalizationStrings[6], v96, v132, v91);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 266, v117, (char *)TmpBuf, 0xFFFFFFFF, 0, 0);

  v127 = "%s\f%06x\t110%d\f000000 / %d\n";
  v118 = v117 + pFontArrus->uFontHeight - 2;
  v133 = Player_GetActualResistance(pPlayer, 12);
  v94 = Player_GetBaseResistance(pPlayer, 12);
  if ( v133 > 99 || v94 > 99 )
    v127 = "%s\f%06x\t180%d\f000000 / %d\n";
  v99 = sub_4178FE_GetColor(v133, v94);
  wsprintfA((char *)TmpBuf, v127, pGlobalTXT_LocalizationStrings[240], v99, v133, v94);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 266, v118, (char *)TmpBuf, 0xFFFFFFFF, 0, 0);

  v128 = "%s\f%06x\t110%d\f000000 / %d\n";
  v119 = v118 + pFontArrus->uFontHeight - 2;
  v134 = Player_GetActualResistance(pPlayer, 13);
  v97 = Player_GetBaseResistance(pPlayer, 13);
  if ( v134 > 99 )
    v128 = "%s\f%06x\t180%d\f000000 / %d\n";
  v102 = sub_4178FE_GetColor(v134, v97);
  wsprintfA((char *)TmpBuf, v128, pGlobalTXT_LocalizationStrings[70], v102, v134, v97);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 266, v119, (char *)TmpBuf, 0xFFFFFF, 0, 0);

  v129 = "%s\f%06x\t110%d\f000000 / %d\n";
  v120 = v119 + pFontArrus->uFontHeight - 2;
  v135 = Player_GetActualResistance(pPlayer, 14);
  v100 = Player_GetBaseResistance(pPlayer, 14);
  v137 = v100;
  if ( v135 > 99 || v100 > 99 )
    v129 = "%s\f%06x\t180%d\f000000 / %d\n";
  v104 = sub_4178FE_GetColor(v135, v100);
  wsprintfA((char *)TmpBuf, v129, pGlobalTXT_LocalizationStrings[142], v104, v135, v100);
  if (pPlayer->uClass == 35)
  {
    if ( v137 == 200 )
    {
      v106 = sub_4178FE_GetColor(v135, 200);
      wsprintfA((char *)TmpBuf, "%s\f%06x\r180%s", (char *)pGlobalTXT_LocalizationStrings[142], v106, pGlobalTXT_LocalizationStrings[625]);
    }
  }
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 266, v120, (char *)TmpBuf, 0xFFFFFFFF, 0, 0);

  v130 = "%s\f%06x\t110%d\f000000 / %d\n";
  v121 = v120 + pFontArrus->uFontHeight - 2;
  v136 = Player_GetActualResistance(pPlayer, 15);
  v107 = Player_GetBaseResistance(pPlayer, 15);
  v138 = v107;
  if ( v136 > 99 || v107 > 99 )
    v130 = "%s\f%06x\t180%d\f000000 / %d\n";
  v109 = sub_4178FE_GetColor(v136, v107);
  wsprintfA((char *)TmpBuf, v130, (char *)pGlobalTXT_LocalizationStrings[29], v109, v136, v107);

  if (pPlayer->uClass == 35)
  {
    if ( v138 == 200 )
    {
      v111 = sub_4178FE_GetColor(v136, 200);
      wsprintfA((char *)TmpBuf, "%s\f%06x\r180%s", pGlobalTXT_LocalizationStrings[29], v111, pGlobalTXT_LocalizationStrings[625]);
    }
  }
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 266, v121, (char *)TmpBuf, 0xFFFFFF, 0, 0);
}

//----- (0041A2D1) --------------------------------------------------------
void __fastcall CharacterUI_DrawInventoryTab(unsigned int uSelectedCharacter, bool a2) // character inventory tab
{
 Player *pPlayer; // esi@1
  int v4; // eax@2
 ItemGen *pItem; // ebx@5
  signed int v8; // edx@6
  signed int v13; // eax@11
  int v14; // eax@13
  int v15; // eax@13
  signed int v16; // edx@13
  int v17; // ebx@15
  int v18; // edi@15
  int v19; // ebx@24
  unsigned __int8 v20; // zf@24
  unsigned __int8 v21; // sf@24
  double v22; // st7@26
  const char *v24; // [sp-8h] [bp-40h]@20
  int v28; // [sp+20h] [bp-18h]@5
  //int v32; // [sp+30h] [bp-8h]@5
  //int v33; // [sp+34h] [bp-4h]@5
 int i;

 Render_DrawIndexedTexture(pD3DRenderer, 8, 8, &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_InventoryBackground]);
 if (a2)
 {
#ifndef OLD_CODE
  v4 = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"fr_strip");
#else
  v4 = LODFile_Icons_LOD.LODFile_LoadTexture("fr_strip",2);
#endif
  Render_DrawIndexedTexture(pD3DRenderer, 8, 305, &LODFile_Icons_LOD.aLODHeaders[v4]);
 }

 
 pPlayer = pPlayers[uSelectedCharacter - 1];
 for (i = 0; i < 126; ++i)
   if (pPlayer->pInventoryIndices[i] != -1 &&
       pPlayer->pInventoryIndices[i] & 0x80000000)
   {
    v28 = pPlayer->pInventoryIndices[i];
    pItem = &pPlayer->pInventorySlots[v28];
    
    if (pItem->uItemID == -1)
      continue;
    
   //v33 = 32 * (i / 14) + 17;
   //v32 = 32 * (i % 14) + 14;
    unsigned int uDrawItemAtX = 32 * (i % 14) + 14,
                 uDrawItemAtY = 32 * (i / 14) + 17;

 
    unsigned int  uItemTextureIdx;
    cTexture     *pItemTexture;

#ifndef OLD_CODE
       wchar_t pItemIconNameW[256];
       wsprintfW(pItemIconNameW, L"%S", pClass40->pItems[pItem->uItemID].pIconName);

       uItemTextureIdx = LODFile_Icons_LOD.LODFile_LoadTexture_New(pItemIconNameW);
#else
       uItemTextureIdx = LODFile_Icons_LOD.LODFile_LoadTexture((const char *)pClass40->pItems[pItem->uItemID].pIconName, 2);
#endif
       pItemTexture = &LODFile_Icons_LOD.aLODHeaders[uItemTextureIdx];

        v8 = pItemTexture->uTextureWidth;
        if (pItemTexture->uTextureWidth < 14)
          v8 = 14;
        if ((v8 - 14) / 32 == 0)
        {
          if (pItemTexture->uTextureWidth < 32)
            uDrawItemAtX += (32 - pItemTexture->uTextureWidth) / 2;
        }

        v13 = pItemTexture->uTextureWidth;
        if (pItemTexture->uTextureWidth < 14)
          v13 = 14;
        v15 = v13 - 14;
        v16 = pItemTexture->uTextureHeight;
        LOBYTE(v15) = v15 & 0xE0;
        v14 = v15 + 32;
        if (pItemTexture->uTextureHeight < 14 )
          v16 = 14;
        v17 = pItem->dword_000014;
        v18 = uDrawItemAtX + ((v14 - pItemTexture->uTextureWidth) / 2) +
              dword_5059A8[uDrawItemAtY + ((((v16 - 14) & 0xFFFFFFE0) - pItemTexture->uTextureHeight + 32) / 2)];

        if ( !(v17 & 0xF0) )
        {
          if ( v17 & 1 || dword_4E28F8 != 13 )
          {
            if ( v17 & 2 )
              Render_sub_4A6776(pD3DRenderer, uDrawItemAtX, uDrawItemAtY, pItemTexture);
            else
              Render_DrawTransparentTexture(pD3DRenderer, uDrawItemAtX, uDrawItemAtY, pItemTexture);
          }
          else
          {
            Render_DrawTransparentGreenChannel(pD3DRenderer, uDrawItemAtX, uDrawItemAtY, pItemTexture);
          }
          goto LABEL_33;
        }
        if ( (unsigned __int8)(v17 & 0xF0) != 16 )
        {
          if ( (unsigned __int8)(v17 & 0xF0) == 32 )
          {
            v24 = "sp28a";
            goto LABEL_24;
          }
          if ( (unsigned __int8)(v17 & 0xF0) == 64 )
          {
            v24 = "sp30a";
            goto LABEL_24;
          }
          if ( (unsigned __int8)(v17 & 0xF0) == 128 )
          {
            v24 = "sp91a";
LABEL_24:
            v19 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( v24, 2)];
            //v20 = dword_50C9A8 == cClock1->int_00001C;
            //v21 = dword_50C9A8 - cClock1->int_00001C < 0;
            //dword_50C9A8 -= cClock1->int_00001C;
            v20 = dword_50C9A8 == cClock1.int_00001C;
            v21 = dword_50C9A8 - cClock1.int_00001C < 0;
            dword_50C9A8 -= cClock1.int_00001C;
            if ( v21 | v20 )
            {
              dword_50C9A8 = 0;
              pItem->dword_000014 &= 0xFFFFFF0F;
              ptr_50C9A4 = 0;
            }
            v22 = (double)GetTickCount() * 0.1000000014901161;
            Render_sub_4A63E6((int)pD3DRenderer, uDrawItemAtX, uDrawItemAtY, (int)pItemTexture, v19, (signed __int64)v22, 0, 255);
LABEL_33:
            array_AD4674_FillZBuffer(pD3DRenderer->pActiveZBuffer + v18, uItemTextureIdx, v28 + 1);
            continue;
          }
        }
        v24 = "sptext01";
        goto LABEL_24;
      }
}

//----- (0041A000) --------------.text:0041A623------------------------------------------
int __fastcall CharacterUI_DrawAwardsTab(unsigned int uCharacter)
{
  int result; // eax@1
  unsigned int v3; // ebx@1
  int v4; // eax@1
  int v5; // eax@15
  const char *v6; // ebx@15
  int v7; // eax@23
  int v8; // eax@24
  int v9; // eax@25
  int v10; // eax@27
  int v11; // eax@32
  int v12; // eax@33
  int v13; // eax@34
  signed int v14; // eax@43
  __int16 v15; // ax@43
  int v16; // eax@43
  int v17; // [sp-4h] [bp-D4h]@16
  char Source[100]; // [sp+Ch] [bp-C4h]@1
  int v19; // [sp+70h] [bp-60h]@1
  int v20; // [sp+74h] [bp-5Ch]@1
  int v21; // [sp+78h] [bp-58h]@1
  int v22; // [sp+7Ch] [bp-54h]@1
  int v23; // [sp+80h] [bp-50h]@1
  int v24; // [sp+84h] [bp-4Ch]@1
  int v25; // [sp+C4h] [bp-Ch]@15
  int v26; // [sp+C8h] [bp-8h]@14
  int v27; // [sp+CCh] [bp-4h]@40

  v3 = 0xFFFF9B;
  #ifndef OLD_CODE
  v4 = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"fr_award");
  #endif
#ifdef OLD_CODE
  v4 = LODFile_Icons_LOD.LODFile_LoadTexture( "fr_award",2);
  #endif
  Render_DrawIndexedTexture(pD3DRenderer, 8, 8, &LODFile_Icons_LOD.aLODHeaders[v4]);

  wsprintfA((char *)TmpBuf, "%s \f%06x", pGlobalTXT_LocalizationStrings[LOCSTR_AVARDS_FOR], v3);
  wsprintfA(Source, (char *)pGlobalTXT_LocalizationStrings[429], pParty_global->pPlayers[uCharacter].sName, aClassNames[pParty_global->pPlayers[uCharacter].uClass]);

  strcat((char *)TmpBuf, Source);
  strcat((char *)TmpBuf, &byte_4E2FD4);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 24, 18, (char *)TmpBuf, 0xFFFF9B, 0, 0x000000);
  result = dword_506528;
  v19 = 12;
  v20 = 48;
  v21 = 424;
  v22 = 290;
  v23 = 435;
  v24 = 337;
  if ( dword_506544 )
  {
    if ( dword_506520 + dword_506528 < dword_506524 )
      result = dword_506528++ + 1;
  }
  if ( dword_506548 )
  {
    if ( result )
    {
      --result;
      dword_506528 = result;
    }
  }
  if ( dword_50651C < 0 )
  {
    result += dword_506520;
    dword_506528 = result;
    if ( dword_506520 + result <= dword_506524 )
      goto LABEL_14;
    result = dword_506524 - dword_506520;
    goto LABEL_13;
  }
  if ( dword_50651C > 0 )
  {
    result -= dword_506520;
    dword_506528 = result;
    if ( result < 0 )
    {
      result = 0;
LABEL_13:
      dword_506528 = result;
      goto LABEL_14;
    }
  }
LABEL_14:
  dword_506544 = 0;
  dword_506548 = 0;
  dword_506520 = 0;
  dword_50651C = 0;
  v26 = result;
  if ( result < dword_506524 )
  {
    while ( 1 )
    {
      v5 = stru_5C3610.array_000000[v26];
      v25 = 8 * stru_5C3610.array_000000[v26];
      v6 = *(const char **)((char *)dword_723E80 + v25);
      if ( v5 != 1 )
        break;
      v17 = dword_AE31E0;
LABEL_42:
      wsprintfA((char *)TmpBuf, v6, v17);
      v6 = (char *)TmpBuf;
LABEL_43:
      v14 = *(int *)((char *)dword_723E84 + v25);
      ++dword_506520;
      v15 = 0xFF000000 | ((unsigned int)(byte_4E2AA4[3 * v14 % 6]) << 16) | ((unsigned int)(byte_4E2AA4[3 * v14 % 6 + 1]) << 8) | byte_4E2AA4[3 * v14 % 6 + 2];
      FontDrawText((GUIWindow *)&v19, pFontArrus, 0, 0, v6, 0, 0, 0);
      v16 = CalculateTextHeght(pFontArrus, v6, (GUIWindow *)&v19, 0, 0);
      result = v16 + v20 + 4;
      if ( result <= v22 )
      {
        ++v26;
        v20 = result;
        result = v26;
        if ( v26 < dword_506524 )
          continue;
      }
      return result;
    }
    if ( (v5 < 85 || v5 > 91) && (v5 < 103 || v5 > 104) )
      goto LABEL_43;
    if ( v5 > 89 )
    {
      v11 = v5 - 90;
      if ( !v11 )
      {
        v10 = (unsigned __int8)byte_ACD770;
        goto LABEL_40;
      }
      v12 = v11 - 1;
      if ( !v12 )
      {
        v10 = (unsigned __int8)byte_ACD771;
        goto LABEL_40;
      }
      v13 = v12 - 12;
      if ( !v13 )
      {
        v10 = dword_ACD82C;
        goto LABEL_40;
      }
      if ( v13 == 1 )
      {
        v10 = dword_ACD830;
        goto LABEL_40;
      }
    }
    else
    {
      if ( v5 == 89 )
      {
        v10 = (unsigned __int8)byte_ACD76F;
        goto LABEL_40;
      }
      v7 = v5 - 85;
      if ( !v7 )
      {
        v10 = pParty_global->dword_00073C;
        goto LABEL_40;
      }
      v8 = v7 - 1;
      if ( !v8 )
      {
        v10 = pParty_global->dword_000748;
        goto LABEL_40;
      }
      v9 = v8 - 1;
      if ( !v9 )
      {
        v10 = pParty_global->dword_000744;
        goto LABEL_40;
      }
      if ( v9 == 1 )
      {
        v10 = (unsigned __int8)byte_ACD76E;
LABEL_40:
        v27 = v10;
        goto LABEL_41;
      }
    }
LABEL_41:
    v17 = v27;
    goto LABEL_42;
  }
  return result;
}

//----- (00419719) --------------------------------------------------------
void CharacterUI_DrawSkillsTab(int uSelectedCharacter) // character skills tab
{
  struct Player *pp; 
  signed int uClr; // ecx@1
  char *v2; // ebp@1
  int v4; // eax@1
  int v6; // edi@3
  int v7; // eax@4
  int v8; // edx@5
  int v9; // eax@7
  int v10; // eax@9
  unsigned int v11; // ecx@9
  __int16 v12; // ax@9
  unsigned __int8 v13; // cf@12
  unsigned __int8 v14; // zf@12
  unsigned int v15; // eax@12
  int v16; // ecx@22
  int v20; // edx@34
  int v21; // eax@35
  int v22; // edx@37
  unsigned int v23; // eax@39
  __int16 v24; // cx@39
  int v25; // edi@39
  unsigned __int8 v26; // cf@42
  unsigned __int8 v27; // zf@42
  unsigned int v28; // eax@42
  char v29; // sf@52
  int v30; // ecx@52
  int v34; // edi@63
  int v35; // edx@64
  int v36; // eax@65
  int v37; // edx@67
  int v38; // eax@69
  unsigned int v39; // ecx@69
  unsigned __int8 v40; // cf@72
  unsigned __int8 v41; // zf@72
  unsigned int v42; // eax@72
  int v43; // ecx@82
  int v47; // eax@94
  int v48; // edx@94
  int v49; // edx@97
  unsigned int v50; // eax@99
  __int16 v51; // cx@99
  int v52; // edi@99
  unsigned __int8 v53; // cf@102
  unsigned __int8 v54; // zf@102
  unsigned int v55; // eax@102
  char v56; // sf@112
  int v57; // ecx@112
  int v61; // [sp-Ch] [bp-4Ch]@19
  int v62; // [sp-Ch] [bp-4Ch]@49
  int v63; // [sp-Ch] [bp-4Ch]@79
  int v64; // [sp-Ch] [bp-4Ch]@109
  unsigned int v65; // [sp-8h] [bp-48h]@19
  unsigned int v66; // [sp-8h] [bp-48h]@49
  unsigned int v67; // [sp-8h] [bp-48h]@79
  unsigned int v68; // [sp-8h] [bp-48h]@109
  int v69; // [sp-4h] [bp-44h]@19
  int v70; // [sp-4h] [bp-44h]@49
  int v71; // [sp-4h] [bp-44h]@79
  int v72; // [sp-4h] [bp-44h]@109
  unsigned int v73; // [sp+10h] [bp-30h]@9
  unsigned int v74; // [sp+10h] [bp-30h]@39
  unsigned int v75; // [sp+10h] [bp-30h]@69
  unsigned int v76; // [sp+10h] [bp-30h]@99
  int v77; // [sp+14h] [bp-2Ch]@4
  int v78; // [sp+14h] [bp-2Ch]@34
  int v79; // [sp+14h] [bp-2Ch]@64
  int v80; // [sp+14h] [bp-2Ch]@94
  int v81; // [sp+18h] [bp-28h]@4
  int v82; // [sp+18h] [bp-28h]@34
  int v83; // [sp+18h] [bp-28h]@64
  int v84; // [sp+18h] [bp-28h]@94
  int v85; // [sp+1Ch] [bp-24h]@3
  int v86; // [sp+1Ch] [bp-24h]@33
  int v87; // [sp+1Ch] [bp-24h]@63
  int v88; // [sp+1Ch] [bp-24h]@93
  int v89; // [sp+20h] [bp-20h]@9
  int v90; // [sp+20h] [bp-20h]@33
  int v91; // [sp+20h] [bp-20h]@69
  int v92; // [sp+20h] [bp-20h]@93
  unsigned int v93; // [sp+24h] [bp-1Ch]@1
  unsigned int v94; // [sp+28h] [bp-18h]@1
  unsigned int v99; // [sp+30h] [bp-10h]@1
  int v100; // [sp+34h] [bp-Ch]@1
  unsigned int v101; // [sp+38h] [bp-8h]@1
  __int16 v102; // [sp+3Ch] [bp-4h]@9
  int v103; // [sp+3Ch] [bp-4h]@24
  int v104; // [sp+3Ch] [bp-4h]@54
  __int16 v105; // [sp+3Ch] [bp-4h]@69
  int v106; // [sp+3Ch] [bp-4h]@84
  int v107; // [sp+3Ch] [bp-4h]@114
  int i;

  v93 = 0xFFFF9B;//colored or white text flag
  v99 = 0x00AFFF;
  v100 = pGUIWindow_CurrentMenu->dword_00002C;
  v101 = 0xFF0000;
  v94 = 0x00FF00;
  v2 = (char *)&pParty_global->pPlayers[uSelectedCharacter-1];
  pp = pPlayers[uSelectedCharacter];

  #ifndef OLD_CODE
  v4 = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"fr_skill");
  #else
  v4 = LODFile_Icons_LOD.LODFile_LoadTexture( "fr_skill",2);
  #endif
  Render_DrawIndexedTexture(pD3DRenderer, 8, 8, &LODFile_Icons_LOD.aLODHeaders[v4]);

  if (pp->uSkillPoints)
    uClr = 0x00FF00;
  else
    uClr = 0xFFFFFF;

  wsprintfA((char *)TmpBuf, "%s \f%06x%s\f000000\r177%s: \f%06x%d\f000000",
    pGlobalTXT_LocalizationStrings[206],
    v93,
    pp->sName,
    pGlobalTXT_LocalizationStrings[207],
    uClr,
    pp->uSkillPoints);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 24, 18, (char *)TmpBuf, 0xFFFFFFFF, 0, 0);
  v6 = 2 * pFontLucida->uFontHeight + 13;
  wsprintfA((char *)TmpBuf, "%s\r400%s", pGlobalTXT_LocalizationStrings[242], pGlobalTXT_LocalizationStrings[131]);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 24, v6, (char *)TmpBuf, 0xFFFFFF9B, 0, 0);
  v85 = 0;
  for(i = 0; i < 9; i++)
  {
    v77 = dword_4E2A2C[i];
    v7 = 0;
    for( v81 = 0; v81 < pGUIWindow_CurrentMenu->uNumControls; v81++ )
    {
      {
        v8 = (int)pGUIWindow_CurrentMenu->pControlsHead;
        v7 = v81;
        if ( v7 > 0 )
        {
          do
          {
            v8 = *(_DWORD *)(v8 + 52);
            --v7;
          }
          while ( v7 );
        }
        v9 = *(_DWORD *)(v8 + 28);
        if ( BYTE1(v9) >= 0 || (BYTE1(v9) &= 0x7Fu, v9 != v77) )
          continue;
        v6 = *(_DWORD *)(v8 + 4);
        v11 = pp->uSkillPoints;
        ++v85;
        v12 = *(_WORD *)&v2[2 * v77 + 264];
        v102 = *(_WORD *)&v2[2 * v77 + 264];
        v10 = v12 & 0x3F;
        v73 = 0;
        v89 = v10;
        if ( v11 >= v10 + 1 )
          v73 = v99;
        if ( v100 == v81 )
        {
          v13 = v11 < v10;
          v14 = v11 == v10;
          v15 = v101;
          if ( !(v13 | v14) )
            v15 = v94;
          v73 = v15;
        }
        else
        {
          v15 = v73;
        }
        if ( HIBYTE(v102) & 1 )
        {
          if ( !v15 )
            v15 = 0xFFFF9B;
          v69 = v89;
          v65 = v73;
          v61 = (int)pGlobalTXT_LocalizationStrings[96];
        }
        else
        {
          if ( !(v102 & 0xC0) )
          {
            wsprintfA((char *)TmpBuf, "%s\r400%2d", aSkillNames[v77], v89);
            FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 24, v6, (char *)TmpBuf, 0xFFFFFFFF, 0, 0);
            continue;
          }
          v16 = (int)pGlobalTXT_LocalizationStrings[432];
          if ( (_BYTE)v102 >= 0 )
            v16 = (int)pGlobalTXT_LocalizationStrings[433];
          v103 = v16;
          if ( !v15 )
            v15 = 0xFFFF9B;
          v69 = v89;
          v65 = v73;
          v61 = v103;
        }
        wsprintfA((char *)TmpBuf, "%s \r%05d%s\r%05d\n400%2d", aSkillNames[v77], v15, v61, v65, v69);
        FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 24, v6, (char *)TmpBuf, 0xFFFFFFFF, 0, 0);
      }
    }
  }
  if ( !v85 )
  {
    v6 = v6 + pFontLucida->uFontHeight - 3;
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 24, v6, (char *)pGlobalTXT_LocalizationStrings[153], 0, 0, 0);
  }
  v90 = v6 + 2 * pFontLucida->uFontHeight - 10;
  wsprintfA((char *)TmpBuf, "%s\r400%s", pGlobalTXT_LocalizationStrings[138], pGlobalTXT_LocalizationStrings[131]);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 24, v90, (char *)TmpBuf, 0xFFFFFF9B, 0, 0);
  v86 = 0;
  for(i = 0; i < 9; i++)
  {
    v20 = 0;
    v78 = dword_4E2A80[i];
    for( v82 = 0; v82 < pGUIWindow_CurrentMenu->uNumControls; v82++ )
    {
      {
        v21 = (int)pGUIWindow_CurrentMenu->pControlsHead;
        v20 = v82;
        if ( v20 > 0 )
        {
          do
          {
            v21 = *(_DWORD *)(v21 + 52);
            --v20;
          }
          while ( v20 );
        }
        v22 = *(_DWORD *)(v21 + 28);
        if ( BYTE1(v22) >= 0 || (BYTE1(v22) &= 0x7Fu, v22 != v78) )
          continue;
        ++v86;
        v90 = *(_DWORD *)(v21 + 4);
        v24 = *(_WORD *)&v2[2 * v78 + 264];
        v23 = pp->uSkillPoints;
        v25 = *(_WORD *)&v2[2 * v78 + 264] & 0x3F;
        v74 = 0;
        if ( v23 >= v25 + 1 )
          v74 = v99;
        if ( v100 == v82 )
        {
          v26 = v23 < v25;
          v27 = v23 == v25;
          v28 = v101;
          if ( !(v26 | v27) )
            v28 = v94;
          v74 = v28;
        }
        else
        {
          v28 = v74;
        }
        if ( HIBYTE(v24) & 1 )
        {
          if ( !v28 )
            v28 = 0xFFFFFF9B;
          v70 = v25;
          v66 = v74;
          v62 = (int)pGlobalTXT_LocalizationStrings[96];
        }
        else
        {
          if ( !(v24 & 0xC0) )
          {
            wsprintfA((char *)TmpBuf, "%s\r400%2d", aSkillNames[v78], v25);
            FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 24, v90, (char *)TmpBuf, 0xFFFFFFFF, 0, 0);
            continue;
          }
          v29 = (_BYTE)v24 < 0;
          v30 = (int)pGlobalTXT_LocalizationStrings[432];
          if ( !v29 )
            v30 = (int)pGlobalTXT_LocalizationStrings[433];
          v104 = v30;
          if ( !v28 )
            v28 = 0xFFFFFF9B;
          v70 = v25;
          v66 = v74;
          v62 = v104;
        }
        wsprintfA((char *)TmpBuf, "%s \r%05d%s\r%05d\n400%2d", aSkillNames[v78], v28, v62, v66, v70);
        FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 24, v90, (char *)TmpBuf, 0xFFFFFFFF, 0, 0);
      }
    }
  }

  if ( !v86 )
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 24, pFontLucida->uFontHeight + v90 - 3, (char *)pGlobalTXT_LocalizationStrings[153], 0xFFFFFFFF, 0, 0);
  v34 = 2 * pFontLucida->uFontHeight + 13;
  wsprintfA((char *)TmpBuf, "%s\r177%s", pGlobalTXT_LocalizationStrings[11], pGlobalTXT_LocalizationStrings[131]);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 248, v34, (char *)TmpBuf, 0xFFFFFF9B, 0, 0);
  v87 = 0;
  for(i = 0; i < 5; i++) 
  {
    v35 = 0;
    v79 = dword_4E2A18[i];
    for( v83 = 0; v83 < pGUIWindow_CurrentMenu->uNumControls; v83++ )
    {
      {
        v36 = (int)pGUIWindow_CurrentMenu->pControlsHead;
        v35 = v83;
        if ( v35 > 0 )
        {
          do
          {
            v36 = *(_DWORD *)(v36 + 52);
            --v35;
          }
          while ( v35 );
        }
        v37 = *(_DWORD *)(v36 + 28);
        if ( BYTE1(v37) >= 0 || (BYTE1(v37) &= 0x7Fu, v37 != v79) )
          continue;
        v34 = *(_DWORD *)(v36 + 4);
        ++v87;
        v75 = 0;
        v105 = *(_WORD *)&v2[2 * v79 + 264];
        v39 = pp->uSkillPoints;
        v38 = *(_WORD *)&v2[2 * v79 + 264] & 0x3F;
        v91 = v38;
        if ( v39 >= v38 + 1 )
          v75 = v99;
        if ( v100 == v83 )
        {
          v40 = v39 < v38;
          v41 = v39 == v38;
          v42 = v101;
          if ( !(v40 | v41) )
            v42 = v94;
          v75 = v42;
        }
        else
        {
          v42 = v75;
        }
        if ( (*(_WORD *)&v2[2 * v79 + 264] >> 8) & 1 )
        {
          if ( !v42 )
            v42 = 0xFFFFFF9B;
          v71 = v91;
          v67 = v75;
          v63 = (int)pGlobalTXT_LocalizationStrings[96];
        }
        else
        {
          if ( !(v105 & 0xC0) )
          {
            wsprintfA((char *)TmpBuf, "%s\r177%2d", aSkillNames[v79], v91);
            FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 248, v34, (char *)TmpBuf, 0xFFFFFFFF, 0, 0);
            continue;
          }
          v43 = (int)pGlobalTXT_LocalizationStrings[432];
          if ( (_BYTE)v105 >= 0 )
            v43 = (int)pGlobalTXT_LocalizationStrings[433];
          v106 = v43;
          if ( !v42 )
            v42 = 0xFFFFFF9B;
          v71 = v91;
          v67 = v75;
          v63 = v106;
        }
        wsprintfA((char *)TmpBuf, "%s \r%05d%s\r%05d\n177%2d", aSkillNames[v79], v42, v63, v67, v71);
        FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 248, v34, (char *)TmpBuf, 0xFFFFFFFF, 0, 0);
      }
    }
  }
  if ( !v87 )
  {
    v34 = v34 + pFontLucida->uFontHeight - 3;
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 248, v34, (char *)pGlobalTXT_LocalizationStrings[153], 0xFFFFFFFF, 0, 0);
  }
  v92 = v34 + 2 * pFontLucida->uFontHeight - 10;
  wsprintfA((char *)TmpBuf, "%s\r177%s", pGlobalTXT_LocalizationStrings[143], pGlobalTXT_LocalizationStrings[131]);
  FontDrawText(pGUIWindow_CurrentMenu, pFontArrus, 248, v92, (char *)TmpBuf, 0xFFFFFF9B, 0, 0);
  v88 = 0;
  for(i = 0; i < 12; i++) 
  {
    v48 = 0;
    v47 = dword_4E2A50[i];
    v80 = dword_4E2A50[i];
    for( v84 = 0; v84 < pGUIWindow_CurrentMenu->uNumControls; v84++ )
    {
      {
        v47 = (int)pGUIWindow_CurrentMenu->pControlsHead;
        v48 = v84;
        if ( v48 > 0 )
        {
          do
          {
            v47 = *(_DWORD *)(v47 + 52);
            --v48;
          }
          while ( v48 );
        }
        v49 = *(_DWORD *)(v47 + 28);
        if ( BYTE1(v49) >= 0 || (BYTE1(v49) &= 0x7Fu, v49 != v80) )
          continue;
        ++v88;
        v92 = *(_DWORD *)(v47 + 4);
        v51 = *(_WORD *)&v2[2 * v80 + 264];
        v50 = pp->uSkillPoints;
        v52 = *(_WORD *)&v2[2 * v80 + 264] & 0x3F;
        v76 = 0;
        if ( v50 >= v52 + 1 )
          v76 = v99;
        if ( v100 == v84 )
        {
          v53 = v50 < v52;
          v54 = v50 == v52;
          v55 = v101;
          if ( !(v53 | v54) )
            v55 = v94;
          v76 = v55;
        }
        else
        {
          v55 = v76;
        }
        if ( HIBYTE(v51) & 1 )
        {
          if ( !v55 )
            v55 = 0xFFFFFF9B;
          v72 = v52;
          v68 = v76;
          v64 = (int)pGlobalTXT_LocalizationStrings[96];
        }
        else
        {
          if ( !(v51 & 0xC0) )
          {
            wsprintfA((char *)TmpBuf, "%s\r177%2d", aSkillNames[v80], v52);
            FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 248, v92, (char *)TmpBuf, 0xFFFFFFFF, 0, 0);
            continue;
          }
          v56 = (_BYTE)v51 < 0;
          v57 = (int)pGlobalTXT_LocalizationStrings[432];
          if ( !v56 )
            v57 = (int)pGlobalTXT_LocalizationStrings[433];
          v107 = v57;
          if ( !v55 )
            v55 = 0xFFFFFF9B;
          v72 = v52;
          v68 = v76;
          v64 = v107;
        }
        wsprintfA((char *)TmpBuf, "%s \r%05d%s\r%05d\n177%2d", aSkillNames[v80], v55, v64, v68, v72);
        FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 248, v92, (char *)TmpBuf, 0xFFFFFFFF, 0, 0);
      }
    }
  }
  if ( !v88 )
    FontDrawText(pGUIWindow_CurrentMenu, pFontLucida, 248, pFontLucida->uFontHeight + v92 - 3, (char *)pGlobalTXT_LocalizationStrings[153], 0xFFFFFFFF, 0, 0);
}



//----- (0043BCA7) --------------------------------------------------------
int CharacterUI_LoadPaperdollTextures()
{
  signed int v0; // eax@7
  signed int v1; // ebx@7
  char v6; // al@16
  signed int v10; // edi@21
  int v12; // ebp@29
  int *v14; // edi@65
  signed int v15; // ebx@66
  int v16; // eax@67
  int v17; // ecx@67
  int v18; // ebx@68
  int v19; // ebp@73
  int v20; // edi@73
  int v21; // eax@76
  int v22; // ecx@76
  int v23; // eax@78
  int v24; // ecx@78
  int v25; // ebx@79
  int v26; // eax@80
  int v27; // ecx@80
  int result; // eax@83
  signed int v30; // [sp+10h] [bp-28h]@68
  signed int v31; // [sp+10h] [bp-28h]@75
  signed int v32; // [sp+10h] [bp-28h]@77
  int v33; // [sp+10h] [bp-28h]@79
  char *v34; // [sp+14h] [bp-24h]@65
  int v35; // [sp+14h] [bp-24h]@75
  int v36; // [sp+14h] [bp-24h]@77
  signed int v37; // [sp+14h] [bp-24h]@79
  int v38; // [sp+18h] [bp-20h]@66
  int *v39; // [sp+18h] [bp-20h]@73
  int *v40; // [sp+1Ch] [bp-1Ch]@73
  int v42; // [sp+20h] [bp-18h]@73
  
 int i;
 unsigned int uPlayer;

#ifndef OLD_CODE
 wchar_t Str1[100]; // [sp+24h] [bp-14h]@12

 uTextureID_GameUI_MagnifyingGlass = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"MAGNIF");
 uTextureID_GameUI_PaperdollBackground = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"PDoll-Bg");
 uTextureID_GameUI_PaperdollJewelryOverlay = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"BACKHAND");
#else
 char Str1[100]; // [sp+24h] [bp-14h]@12

 uTextureID_GameUI_MagnifyingGlass = LODFile_Icons_LOD.LODFile_LoadTexture("MAGNIF-B",2);
 uTextureID_GameUI_PaperdollBackground = LODFile_Icons_LOD.LODFile_LoadTexture("BACKDOLL",2);
 uTextureID_GameUI_PaperdollJewelryOverlay = LODFile_Icons_LOD.LODFile_LoadTexture("BACKHAND",2);
 uTextureID_507B04 = uTextureID_5079E4;
#endif
  dword_5118C8 = uTextureID_right_backgr;
 for (uPlayer = 0; uPlayer < 4; ++uPlayer)
 {
  unsigned int uFace;

    if ( sub_43EE77_ProbablyIfUnderwaterSuitIsEquipped(uPlayer) ) // underwater suits
    {
      v1 = Player_GetRace(pPlayers[uPlayer+1]);
      v0 = Player_GetVoiceSex(pPlayers[uPlayer+1]);
      if ( v1 && v1 != 1 && v1 != 2 )
        uFace = (v0 != 0) + 3;
      else
        uFace = (v0 != 0) + 1;
#ifndef OLD_CODE
      wsprintfW(Str1, L"pc23v%dBod", uFace);
      pPaperdollTextures_Bodies[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture_New( Str1);
      wsprintfW(Str1, L"pc23v%dlad", uFace);
      pPaperdollTextures_LeftArmsEmpty[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture_New( Str1);
      wsprintfW(Str1, L"pc23v%dlau", uFace);
      pPaperdollTextures_LeftArmsWeapon[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture_New( Str1);
      wsprintfW(Str1, L"pc23v%drh", uFace);
      pPaperdollTextures_RightHands[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture_New( Str1);
      wsprintfW(Str1, L"pc23v%dlh", uFace);
      pPaperdollTextures_LeftHandsEmpty[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture_New( Str1);
      wsprintfW(Str1, L"pc23v%dlhu", uFace);
      pPaperdollTextures_LeftHandsWeapon[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture_New( Str1);
#else
       wsprintf(Str1, "pc23v%dBod", uFace);
      pPaperdollTextures_Bodies[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture( Str1,2);
      wsprintf(Str1, "pc23v%dlad", uFace);
      pPaperdollTextures_LeftArmsEmpty[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture( Str1,2);
      wsprintf(Str1, "pc23v%dlau", uFace);
      pPaperdollTextures_LeftArmsWeapon[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture( Str1,2);
      wsprintf(Str1, "pc23v%drh", uFace);
      pPaperdollTextures_RightHands[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture( Str1,2);
      wsprintf(Str1, "pc23v%dlh", uFace);
      pPaperdollTextures_LeftHandsEmpty[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture( Str1,2);
      wsprintf(Str1, "pc23v%dlhu", uFace);
      pPaperdollTextures_LeftHandsWeapon[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture( Str1,2);
#endif
      uFace = pPlayers[uPlayer]->uFace;
      if ( uFace == 12 || uFace == 13 )
        pPaperdollTextures_Beards[uFace] = 0;
      pPaperdollTextures_Feet[uFace] = 0;
      IsPlayerWearingWatersuit[uPlayer] = 1;
    }
    else
    {
      uFace = pPlayers[uPlayer]->uFace;
#ifndef OLD_CODE
      wsprintfW(Str1, L"pc%02dbod", uFace + 1);
      pPaperdollTextures_Bodies[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture_New(Str1);
      wsprintfW(Str1, L"pc%02dlad", uFace + 1);
      pPaperdollTextures_LeftArmsEmpty[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture_New(Str1);
      wsprintfW(Str1, L"pc%02dlau", uFace + 1);
      pPaperdollTextures_LeftArmsWeapon[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture_New(Str1);
      wsprintfW(Str1, L"pc%02drh", uFace + 1);
      pPaperdollTextures_RightHands[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture_New(Str1);
      wsprintfW(Str1, L"pc%02dlh", uFace + 1);
      pPaperdollTextures_LeftHandsEmpty[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture_New(Str1);
      wsprintfW(Str1, L"pc%02dlhu", uFace + 1); // something strange with pc20lhu, needs to check
      pPaperdollTextures_LeftHandsWeapon[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture_New(Str1);

      if (uFace == 12 || uFace == 13) // dwarf male, load beard
      {
        wsprintfW(Str1, L"pc%02dbrd", uFace + 1);
        pPaperdollTextures_Beards[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture_New(Str1);
      }
      wsprintfW(Str1, L"item281pc%02d", uFace + 1);
      pPaperdollTextures_Feet[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture_New(Str1);
#else
      wsprintf(Str1, "pc%02dbod", uFace + 1);
      pPaperdollTextures_Bodies[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture(Str1, 2);
      wsprintf(Str1, "pc%02dlad", uFace + 1);
      pPaperdollTextures_LeftArmsEmpty[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture(Str1, 2);
      wsprintf(Str1, "pc%02dlau", uFace + 1);
      pPaperdollTextures_LeftArmsWeapon[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture(Str1, 2);
      wsprintf(Str1, "pc%02drh", uFace + 1);
      pPaperdollTextures_RightHands[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture(Str1, 2);
      wsprintf(Str1, "pc%02dlh", uFace + 1);
      pPaperdollTextures_LeftHandsEmpty[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture(Str1, 2);
      wsprintf(Str1, "pc%02dlhu", uFace + 1); // something strange with pc20lhu, needs to check
      pPaperdollTextures_LeftHandsWeapon[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture(Str1, 2);

      if (uFace == 12 || uFace == 13) // dwarf male, load beard
      {
        wsprintf(Str1, "pc%02dbrd", uFace + 1);
        pPaperdollTextures_Beards[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture(Str1, 2);
      }
      wsprintf(Str1, "item281pc%02d", uFace + 1);
      pPaperdollTextures_Feet[uPlayer] = LODFile_Icons_LOD.LODFile_LoadTexture(Str1, 2);
#endif
      IsPlayerWearingWatersuit[uPlayer] = 0;
    }
  }
#ifndef OLD_CODE
  dword_507674 = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"ar_up_up");
  dword_507670 = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"ar_up_dn");
  dword_50766C = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"ar_dn_up");
  dword_507668 = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"ar_dn_dn");
  dword_51122C = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"ib-cd1-d");
  dword_511224 = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"ib-cd2-d");
  dword_51121C = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"ib-cd3-d");
  dword_511214 = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"ib-cd4-d");
  dword_51120C = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"ib-cd5-d");
#else
  dword_507674 = LODFile_Icons_LOD.LODFile_LoadTexture("ar_up_up",2);
  dword_507670 = LODFile_Icons_LOD.LODFile_LoadTexture("ar_up_dn",2);
  dword_50766C = LODFile_Icons_LOD.LODFile_LoadTexture("ar_dn_up",2);
  dword_507668 = LODFile_Icons_LOD.LODFile_LoadTexture("ar_dn_dn",2);
  dword_51122C = LODFile_Icons_LOD.LODFile_LoadTexture("ib-cd1-d",2);
  dword_511224 = LODFile_Icons_LOD.LODFile_LoadTexture("ib-cd2-d",2);
  dword_51121C = LODFile_Icons_LOD.LODFile_LoadTexture("ib-cd3-d",2);
  dword_511214 = LODFile_Icons_LOD.LODFile_LoadTexture("ib-cd4-d",2);
  dword_51120C = LODFile_Icons_LOD.LODFile_LoadTexture("ib-cd5-d",2);
#endif

  
  for (v10 = 0; v10 < 54; ++v10)
  {
    byte_5111C0[v10] = 0;
    if (pParty_global->pickedItem.uItemID != v10 + 66 )
    {
     i = 0;
      while ( !sub_43EE15(v10 + 66, &pParty_global->pPlayers[i], 0) )
      {
        i++;
        if ( i >= 4)
          goto LABEL_28;
      }
    }
    byte_5111C0[v10] = 1;
LABEL_28:
    ;
  }

  memset(byte_5111F6, 0, sizeof(byte_5111F6));

  v12 = 1;
  for (i = 0; i < 4; ++i)
  {
    if ( sub_43EE15(516, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[2] = 1;
    if ( sub_43EE15(504, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[0] = 1;
    if ( sub_43EE15(505, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[1] = 1;
    if ( sub_43EE15(533, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[16] = 1;
    if ( sub_43EE15(512, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[3] = 1;
    if ( sub_43EE15(521, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[4] = 1;
    if ( sub_43EE15(522, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[5] = 1;
    if ( sub_43EE15(523, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[6] = 1;
    if ( sub_43EE15(532, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[7] = 1;
    if ( sub_43EE15(544, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[8] = 1;
    if ( sub_43EE15(524, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[9] = 1;
    if ( sub_43EE15(535, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[10] = 1;
    if ( sub_43EE15(525, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[11] = 1;
    if ( sub_43EE15(530, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[12] = 1;
    if ( sub_43EE15(547, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[13] = 1;
    if ( sub_43EE15(548, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[14] = 1;
    if ( sub_43EE15(550, &pParty_global->pPlayers[i], 1) )
      byte_5111F6[15] = 1;
  }

  v14 = (int *)&uTextureListForPaperdoll[35];
  v34 = (char *)&uTextureListForPaperdoll[62];
  do
  {
    v15 = 0;
    v38 = (int)(v34 - 24);
    do
    {
      sub_43C91D_FormTextureFileName((char *)Str1, v15 + 100, v12, 0);
      v16 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      ++v15;
      v17 = v38;
      v38 += 4;
      *(_DWORD *)v17 = v16;
    }
    while ( v15 < 5 );
    sub_43C91D_FormTextureFileName((char *)Str1, 535, v12, 0);
    v30 = 0;
    v18 = (int)(v14 - 11);
    *(_DWORD *)v34 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
    do
    {
      sub_43C91D_FormTextureFileName((char *)Str1, v30++ + 89, v12, 0);
      *(_DWORD *)v18 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      v18 += 4;
    }
    while ( v30 < 11 );
    sub_43C91D_FormTextureFileName((char *)Str1, 521, v12, 0);
    v14[0] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
    sub_43C91D_FormTextureFileName((char *)Str1, 522, v12, 0);
    v14[1] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
    sub_43C91D_FormTextureFileName((char *)Str1, 523, v12, 0);
    v14[2] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
    sub_43C91D_FormTextureFileName((char *)Str1, 532, v12, 0);
    v14[3] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
    sub_43C91D_FormTextureFileName((char *)Str1, 544, v12, 0);
    v14[4] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
    if ( sub_43ED6F(1) )
      dword_511234 = LODFile_Icons_LOD.LODFile_LoadTexture( "item092v3", 2);
    v34 += 28;
    ++v12;
    v14 += 16;
  }
  while ( v12 - 1 < 2 );
  v42 = 0;
  v20 = 1;
  v39 = (int *)&uTextureListForPaperdoll[5];
  v19 = 0;
  v40 = (int *)&uTextureListForPaperdoll[61];
  do
  {
    if ( sub_43EDB9(v20 - 1) )
    {
      sub_43C91D_FormTextureFileName((char *)Str1, 524, v20, 0);
      v31 = 66;
      *v40 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      v35 = 0;
    //  do
    //  {
        sub_43C91D_FormTextureFileName((char *)Str1, v31, v20, 0);
        dword_511290[v19 + v35 + 1] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
        sub_43C91D_FormTextureFileName((char *)Str1, v31, v20, 1);
        dword_511290[v19 + v35] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
        sub_43C91D_FormTextureFileName((char *)Str1, v31, v20, 2);
        dword_511290[v19 + v35 + 2] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
        v35 += 3;
        ++v31;
   //   }
   //   while ( v31 - 66 < 13 );
      sub_43C91D_FormTextureFileName((char *)Str1, 516, v20, 0);
      dword_511290[v19+39] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 516, v20, 1);
      dword_511290[v19+40] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 516, v20, 2);
      dword_511290[v19+41] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 505, v20, 0);
      dword_511290[v19+42] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 505, v20, 1);
      dword_511290[v19+43] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 505, v20, 2);
      dword_511290[v19+44] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 504, v20, 0);
      dword_511290[v19+45] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 504, v20, 1);
      dword_511290[v19+46] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 504, v20, 2);
      dword_511290[v19+47] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 533, v20, 0);
      dword_511290[v19+48] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 533, v20, 1);
      dword_511290[v19+49] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 533, v20, 2);
      dword_511290[v19+50] = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      v32 = 0;
      v36 = (int)(v39 - 5);
    //  do
   //   {
        sub_43C91D_FormTextureFileName((char *)Str1, v32 + 115, v20, 0);
        v23 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
        ++v32;
        v24 = v36;
        v36 += 4;
        *(_DWORD *)v24 = v23;
   //   }
    //  while ( v32 < 5 );
      sub_43C91D_FormTextureFileName((char *)Str1, 512, v20, 0);
      v25 = v42;
      v37 = 105;
      v33 = v42;
      *v39 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
    //  do
    //  {
        sub_43C91D_FormTextureFileName((char *)Str1, v37, v20, 0);
        *(int *)((char *)dword_511828 + v33) = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
        sub_43C91D_FormTextureFileName((char *)Str1, v37, v20, 1);
        v26 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
        v27 = v33;
        v33 += 4;
        ++v37;
        *(int *)((char *)&uTextureListForPaperdoll[84] + v27) = v26;
   //   }
   //   while ( v37 - 105 < 5 );
      sub_43C91D_FormTextureFileName((char *)Str1, 525, v20, 0);
      *(int *)((char *)&dword_51183C + v42) = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 530, v20, 0);
      *(int *)((char *)&dword_511840 + v42) = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 547, v20, 0);
      *(int *)((char *)&dword_511844 + v42) = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 548, v20, 0);
      *(int *)((char *)&dword_511848 + v42) = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 550, v20, 0);
      *(int *)((char *)&dword_51184C + v42) = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 525, v20, 1);
      *(int *)((char *)&dword_51179C + v42) = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 530, v20, 1);
      *(int *)((char *)&dword_5117A0 + v42) = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 547, v20, 1);
      *(int *)((char *)&dword_5117A4 + v42) = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 548, v20, 1);
      *(int *)((char *)&dword_5117A8 + v42) = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
      sub_43C91D_FormTextureFileName((char *)Str1, 550, v20, 1);
      *(int *)((char *)&dword_5117AC + v42) = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)Str1, 2);
    }
    else
    {
      v25 = v42;
    }
    v40 += 7;
    v39 += 6;
    v19 += 51;
    ++v20;
    result = v20 - 1;
    v42 = v25 + 40;
  }
  while ( v20 - 1 < 4 );
  return result;
}


//----- (0041ABFD) --------------------------------------------------------
void CharacterUI_DoDrawCharacterScreen(unsigned int uCharacter)
{
 struct GUIButton *v2; // eax@6
  int v3; // ecx@6

  if (!uCharacter)
    return;

    Render_ClearZBuffer(pD3DRenderer, 0, 479);
    switch ( dword_506F48 )
    {
      case 100: // stats 
        sub_4196A0();
        sub_419379();
        CharacterUI_DrawStatsTab(uCharacter);
#ifndef OLD_CODE
        v3 = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"ib-cd1-d");
#else
        v3 = LODFile_Icons_LOD.LODFile_LoadTexture("ib-cd1-d",2);
#endif
        v2 = pCharacterUI_BtnStats;
        break;
      case 101: // skills
        if ( dword_507CC0 != uCharacter )
        {
          sub_4196A0();
          sub_419401();
        }
        sub_419379();
        CharacterUI_DrawSkillsTab(uCharacter);
        #ifndef OLD_CODE
        v3 = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ib-cd2-d");
        #endif
#ifdef OLD_CODE	
        v3 = LODFile_Icons_LOD.LODFile_LoadTexture( "ib-cd2-d",2);
        #endif
        v2 = pCharacterUI_BtnSkills;
        break;
      case 102: // awards
        sub_4196A0();
        sub_419379();
        sub_419220();
        CharacterUI_DrawAwardsTab(uCharacter);
#ifndef OLD_CODE
        v3 = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"ib-cd4-d");
#else
        v3 = LODFile_Icons_LOD.LODFile_LoadTexture( "ib-cd4-d",2);
#endif
        v2 = pCharacterUI_BtnAwards;
        break;
      default:
        if ( dword_506F48 != 103 )
          goto LABEL_13;
        sub_4196A0();
        sub_419379();
        CharacterUI_DrawInventoryTab(uCharacter, 0);
#ifndef OLD_CODE
        v3 = LODFile_Icons_LOD.LODFile_LoadTexture_New(L"ib-cd3-d");
#else
        v3 = LODFile_Icons_LOD.LODFile_LoadTexture( "ib-cd3-d",2);
#endif
        v2 = pCharacterUI_BtnInventory;
        break;
    }
    Render_DrawIndexedTexture(pD3DRenderer, v2->uX, v2->uY, &LODFile_Icons_LOD.aLODHeaders[v3]);
LABEL_13:
    if ( dword_5118E0 )
      CharacterUI_DrawPaperdoll2(uCharacter);
    else
      CharacterUI_DrawPaperdoll(uCharacter);
}


//----- (0043CC7C) --------------------------------------------------------
void __fastcall CharacterUI_DrawPaperdoll(unsigned int uSelectedCharacter)
{
  int sex; // eax@1
  //int v2; // ebx@1
  int r; // edi@1
  //int v4; // esi@1
  bool v5; // edi@4
  int v6; // ecx@9
  int v7; // ecx@10
  int v8; // eax@14
  int v9; // eax@15
  int v10; // edi@15
  ItemGen *v11; // eax@15
  bool v12; // edx@15
  int v13; // ecx@15
  int v14; // ecx@18
  int v15; // ebx@18
  int v16; // ebp@27
  unsigned __int8 v17; // zf@27
  unsigned __int8 v18; // sf@27
  double v19; // st7@29
  int v20; // eax@30
  int v21; // edi@30
  int v22; // edi@31
  int v23; // eax@37
  int v24; // eax@38
  int v25; // ebx@38
  int v26; // edi@38
  int v27; // eax@38
  LODFile_IB* v28; // ecx@42
  unsigned __int8 v29; // zf@49
  unsigned __int8 v30; // sf@49
  int v31; // edi@51
  double v32; // st7@51
  char v33; // zf@54
  int v34; // eax@54
  int v35; // eax@59
  ItemGen *v36; // edx@60
  int v37; // eax@65
  int v38; // eax@74
  int v39; // ecx@74
  int v40; // ebx@74
  int v41; // eax@74
  LODFile_IB* v42; // ecx@78
  int v43; // edi@85
  unsigned __int8 v44; // zf@85
  unsigned __int8 v45; // sf@85
  double v46; // st7@87
  int v47; // edi@88
  cTexture* v48; // edi@89
  int v49; // eax@93
  ItemGen *v50; // edx@94
  int v51; // eax@98
  int v52; // eax@106
  int v53; // ecx@106
  int v54; // ebx@106
  int v55; // eax@106
  LODFile_IB* v56; // ecx@110
  int v57; // edi@117
  unsigned __int8 v58; // zf@117
  unsigned __int8 v59; // sf@117
  double v60; // st7@119
  int v61; // edi@120
  cTexture *v62; // edi@121
  char v63; // zf@122
 cTexture *v64; // eax@122
  int v65; // eax@127
  int v66; // ecx@128
  ItemGen *v67; // edi@128
  int v68; // ebx@129
  int v69; // ecx@132
  int v70; // eax@134
  int v71; // ecx@136
  int v72; // edi@145
  unsigned __int8 v73; // zf@145
  unsigned __int8 v74; // sf@145
  double v75; // st7@147
  cTexture *v76; // eax@148
  int v77; // edi@148
  cTexture *v78; // edi@149
  int v79; // edx@155
  //int v80; // ebx@155
  //int v81; // edx@156
  int v82; // eax@160
  ItemGen *v83; // edi@161
  int v84; // edx@163
  int v85; // ecx@168
  int v86; // ebx@170
  int v87; // ecx@172
  int v88; // edi@181
  unsigned __int8 v89; // zf@181
  unsigned __int8 v90; // sf@181
  double v91; // st7@183
  cTexture *v92; // eax@184
  int v93; // edi@184
  cTexture *v94; // edi@185
  int v95; // eax@192
  int v96; // eax@193
  int v97; // eax@197
  int v98; // eax@197
  int v99; // ecx@197
  int v100; // eax@197
  int v101; // eax@198
  int v102; // eax@199
  int v103; // edi@201
  int v104; // ebx@213
  int v105; // edi@213
  int v106; // eax@214
  int v107; // ebx@214
  int v108; // edi@214
  int v109; // ecx@217
  int v110; // edi@226
  unsigned __int8 v111; // zf@226
  unsigned __int8 v112; // sf@226
  double v113; // st7@228
  int v114; // eax@229
  //int v115; // ecx@229
  int v116; // edi@229
  char v117; // zf@229
  cTexture *v118; // edi@230
  int v119; // edi@236
  int v120; // eax@237
  int v121; // edx@237
  int v122; // ecx@237
  int v123; // edx@238
  int v124; // edx@239
  int v125; // edx@240
  unsigned __int8 v126; // zf@246
  unsigned __int8 v127; // sf@246
  cTexture *v128; // edx@250
  int v129; // edi@250
  int v130; // eax@259
  int v131; // eax@260
  ItemGen *v132; // eax@260
  int v133; // eax@265
  int v134; // ebx@274
  int v135; // edi@274
  int v136; // eax@274
  int v137; // ecx@275
  unsigned __int8 v138; // zf@284
  unsigned __int8 v139; // sf@284
  double v140; // st7@286
  cTexture *v141; // eax@287
  int v142; // edi@287
  cTexture *v143; // edi@288
  int v144; // edi@295
  int v145; // ebx@297
  ItemGen *v146; // edi@298
  int v147; // ecx@303
  int v148; // eax@312
  int v149; // ebx@314
  int v150; // ecx@316
  int v151; // edi@325
  unsigned __int8 v152; // zf@325
  unsigned __int8 v153; // sf@325
  double v154; // st7@327
  cTexture *v155; // eax@328
  int v156; // edi@328
  cTexture *v157; // edi@329
  int v158; // eax@335
  int v159; // eax@336
  ItemGen *v160; // eax@336
  int v161; // edx@336
  int v162; // ecx@339
  int v163; // ebx@339
  int v164; // edi@348
  unsigned __int8 v165; // zf@348
  unsigned __int8 v166; // sf@348
  double v167; // st7@350
  cTexture *v168; // eax@351
  int v169; // edi@351
  cTexture *v170; // edi@352
  int v171; // eax@358
  int v172; // eax@359
  int v173; // edx@359
  int v174; // ecx@359
  ItemGen *v175; // eax@359
  int v176; // ebx@362
  int v177; // ecx@363
  int v178; // ecx@364
  int v179; // eax@370
  int v180; // edi@370
  int v181; // eax@370
  LODFile_IB* v182; // ecx@374
  int v183; // ebp@381
  unsigned __int8 v184; // zf@381
  unsigned __int8 v185; // sf@381
  double v186; // st7@383
  cTexture *v187; // edi@385
  char v188; // zf@386
  cTexture *v189; // eax@386
  int v190; // eax@393
  int v191; // eax@394
  int v192; // [sp-Ch] [bp-58h]@230
  int v193; // [sp-Ch] [bp-58h]@233
  int v194; // [sp-Ch] [bp-58h]@235
  const char *v195; // [sp-8h] [bp-54h]@16
  const char *v196; // [sp-8h] [bp-54h]@23
  const char *v197; // [sp-8h] [bp-54h]@43
  const char *v198; // [sp-8h] [bp-54h]@79
  const char *v199; // [sp-8h] [bp-54h]@111
  const char *v200; // [sp-8h] [bp-54h]@141
  const char *v201; // [sp-8h] [bp-54h]@177
  const char *v202; // [sp-8h] [bp-54h]@222
  int v203; // [sp-8h] [bp-54h]@228
  int v204; // [sp-8h] [bp-54h]@230
  int v205; // [sp-8h] [bp-54h]@233
  int v206; // [sp-8h] [bp-54h]@235
  const char *v207; // [sp-8h] [bp-54h]@242
  const char *v208; // [sp-8h] [bp-54h]@280
  const char *v209; // [sp-8h] [bp-54h]@321
  const char *v210; // [sp-8h] [bp-54h]@337
  const char *v211; // [sp-8h] [bp-54h]@344
  const char *v212; // [sp-8h] [bp-54h]@375
  signed int v213; // [sp-4h] [bp-50h]@66
  signed int v214; // [sp-4h] [bp-50h]@99
  signed int v215; // [sp-4h] [bp-50h]@202
  int v216; // [sp-4h] [bp-50h]@228
  cTexture *v217; // [sp-4h] [bp-50h]@230
  cTexture *v218; // [sp-4h] [bp-50h]@233
  cTexture *v219; // [sp-4h] [bp-50h]@235
  signed int v220; // [sp-4h] [bp-50h]@266
  signed int v221; // [sp-4h] [bp-50h]@304
  int v222; // [sp+10h] [bp-3Ch]@7
  int v223; // [sp+10h] [bp-3Ch]@15
  int v224; // [sp+10h] [bp-3Ch]@38
  int v225; // [sp+10h] [bp-3Ch]@74
  int v226; // [sp+10h] [bp-3Ch]@106
  int v227; // [sp+10h] [bp-3Ch]@129
  int v228; // [sp+10h] [bp-3Ch]@168
  int v229; // [sp+10h] [bp-3Ch]@216
  int v230; // [sp+10h] [bp-3Ch]@274
  int v231; // [sp+10h] [bp-3Ch]@312
  int v232; // [sp+10h] [bp-3Ch]@336
  int v233; // [sp+10h] [bp-3Ch]@362
  int v234; // [sp+14h] [bp-38h]@7
  int v235; // [sp+14h] [bp-38h]@15
  int v236; // [sp+14h] [bp-38h]@49
  int v237; // [sp+14h] [bp-38h]@74
  int v238; // [sp+14h] [bp-38h]@106
  int v239; // [sp+14h] [bp-38h]@129
  int v240; // [sp+14h] [bp-38h]@168
  int v241; // [sp+14h] [bp-38h]@214
  int v242; // [sp+14h] [bp-38h]@274
  int v243; // [sp+14h] [bp-38h]@284
  int v244; // [sp+14h] [bp-38h]@312
  int v245; // [sp+14h] [bp-38h]@336
  //int v246; // [sp+18h] [bp-34h]@1
  //int v247; // [sp+1Ch] [bp-30h]@15
  //int v248; // [sp+1Ch] [bp-30h]@60
  //int v249; // [sp+1Ch] [bp-30h]@94
  //int v250; // [sp+1Ch] [bp-30h]@128
  //int v251; // [sp+1Ch] [bp-30h]@161
  int v252; // [sp+1Ch] [bp-30h]@213
  char v253; // [sp+1Ch] [bp-30h]@237
  //int v254; // [sp+1Ch] [bp-30h]@260
  //int v255; // [sp+1Ch] [bp-30h]@298
  //int v256; // [sp+1Ch] [bp-30h]@336
  //int v257; // [sp+1Ch] [bp-30h]@359
  int v258; // [sp+20h] [bp-2Ch]@15
  int v259; // [sp+20h] [bp-2Ch]@38
  int v260; // [sp+20h] [bp-2Ch]@60
  int v261; // [sp+20h] [bp-2Ch]@94
  int v262; // [sp+20h] [bp-2Ch]@128
  int v263; // [sp+20h] [bp-2Ch]@161
  int v264; // [sp+20h] [bp-2Ch]@197
  int v265; // [sp+20h] [bp-2Ch]@260
  int v266; // [sp+20h] [bp-2Ch]@298
  //int v267; // [sp+20h] [bp-2Ch]@336
  int v268; // [sp+24h] [bp-28h]@6
  //int v269; // [sp+28h] [bp-24h]@7
  int v270; // [sp+2Ch] [bp-20h]@38
  int v271; // [sp+2Ch] [bp-20h]@197
  int v272; // [sp+2Ch] [bp-20h]@370
  signed int v274; // [sp+34h] [bp-18h]@361
  int v276; // [sp+38h] [bp-14h]@9
  signed int v277; // [sp+40h] [bp-Ch]@4
  //int v278; // [sp+40h] [bp-Ch]@358

 Player *pPlayer = pPlayers[uSelectedCharacter - 1];


  LODFile_Icons_LOD.LODFile_LoadTexture("sptext01", 2);
  r = Player_GetRace(pPlayer);
  sex = Player_GetVoiceSex(pPlayer);
  v5=0;
  if ( r != Character::Race::Human && r != Character::Race::Elf && r != Character::Race::Goblin )
  {
    v277 = 1;
	if	(sex != Character::Sex::Male)
       v5 = 1;
	v5+=2;
  }
  else
  {
    v277 = 0;
	if (sex != Character::Sex::Male)
      v5 = 1;
  }
  v268 = v5;
  Render_Reset2DClippingRect(pD3DRenderer);
  Render_DrawIndexedTexture(pD3DRenderer, 467, 0, &LODFile_Icons_LOD.aLODHeaders[uTextureID_GameUI_PaperdollBackground]);

 if (!IsPlayerWearingWatersuit[uSelectedCharacter])
 {
    v23 = pPlayer->pEquppedItemIndices[2];
    if ( !v23 )
      goto LABEL_59;
    v259 = pPlayer->pEquppedItemIndices[2];
    v26 = (int)&pPlayer->pInventorySlots[v23 - 1];
    v27 = 48 * pPlayer->pInventorySlots[v23 - 1].uItemID;
    v25 = dword_4E4C28 + dword_4E4C30[32 * v268 + 4] - *(__int16 *)((char *)&word_5D29FC + v27);
    v224 = dword_4E4C2C + dword_4E4C30[32 * v268 + 5] - *(__int16 *)((char *)&word_5D29FE + v27);

#ifdef OLD_CODE
    v270 = LODFile_Icons_LOD.LODFile_LoadTexture( (const char*)pClass40->pItems[pPlayer->cInventorySlots[v23 - 1].uItemID].pIconName, 2);
#else
    wchar_t pTextureNameW[256];
    wsprintfW(pTextureNameW, L"%S", pClass40->pItems[pPlayer->pInventorySlots[v23 - 1].uItemID].pIconName);

    v270 = LODFile_Icons_LOD.LODFile_LoadTexture_New(pTextureNameW);
#endif

    v24 = *(_DWORD *)(v26 + 20);
    if ( !(*(_DWORD *)(v26 + 20) & 0xF0) )
    {
      if ( v24 & 2 )
      {
        v31 = v270 != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[v270] : 0;
        Render_sub_4A6776(pD3DRenderer, v25, v224, (cTexture *)v31);
      }
      else
      {
        v33 = (v24 & 1) == 0;
        v34 = (int)&LODFile_Icons_LOD.aLODHeaders[v270];
        if ( v33 )
        {
          v31 = v270 != -1 ? v34 : 0;
          Render_DrawTransparentGreenChannel(pD3DRenderer, v25, v224, v270 != -1 ? (cTexture *)v34 : 0);
        }
        else
        {
          v31 = v270 != -1 ? v34 : 0;
          Render_DrawTransparentTexture(pD3DRenderer, v25, v224, (cTexture *)(v270 != -1 ? v34 : 0));
        }
      }
      goto LABEL_57;
    }
    if ( (*(_DWORD *)(v26 + 20) & 0xF0) != 16 )
    {
      if ( (*(_DWORD *)(v26 + 20) & 0xF0) == 32 )
      {
        v197 = "sp28a";
      }
      else
      {
        if ( (*(_DWORD *)(v26 + 20) & 0xF0) != 64 )
        {
          v28 = &LODFile_Icons_LOD;
          if ( (*(_DWORD *)(v26 + 20) & 0xF0) == 128 )
          {
            v197 = "sp91a";
LABEL_49:
            v236 = (int)&LODFile_Icons_LOD.aLODHeaders[v28->LODFile_LoadTexture( v197, 2)];
            v29 = dword_50C9A8 == cClock1.int_00001C;
            v30 = dword_50C9A8 - cClock1.int_00001C < 0;
            dword_50C9A8 -= cClock1.int_00001C;
            if ( v30 | v29 )
            {
              dword_50C9A8 = 0;
              *(_BYTE *)(v26 + 20) &= 0xFu;
              ptr_50C9A4 = 0;
            }
            v31 = v270 != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[v270] : 0;
            v32 = (double)GetTickCount() * 0.1000000014901161;
            Render_sub_4A63E6((int)pD3DRenderer, v25, v224, v31, v236, (signed __int64)v32, 0, 255);
LABEL_57:
            if ( !dword_5118E0 )
              Render_DrawTextureToZBuffer(pD3DRenderer, v25, v224, (cTexture *)v31, v259);
LABEL_59:
            v35 = pPlayer->pInventoryIndices[6];
            if ( !v35 )
              goto LABEL_93;
            v260 = pPlayer->pInventoryIndices[6];
            v36 = &pPlayer->pInventorySlots[v35 - 1];

            if (v36->uItemID != 525)
            {
             switch (v36->uItemID)
              {
                case 0x212:
                  v213 = 6;
                  break;
                case 0x223:
                  v213 = 7;
                  break;
                case 0x224:
                  v213 = 8;
                  break;
                default:
                 if (v36->uItemID != 550 )
                  {
                   v37 = v36->uItemID - 105;
LABEL_72:
                    if ( v37 < 0 || v37 >= 10 )
                      goto LABEL_93;
                    goto LABEL_74;
                  }
                  v213 = 9;
                  break;
              }
              v37 = v213;
LABEL_74:
              v41 = v37 + 10 * v268;
              v40 = dword_511828[v41];
              v237 = dword_4E4C28 + dword_4E5570[2 * v41];
              v39 = dword_4E4C2C + dword_4E5570[2 * v41 + 1];
              v38 = *(_DWORD *)(v36 + 20);
              v225 = v39;
              if ( v38 & 0xF0 )
              {
                if ( (*(_DWORD *)(v36 + 20) & 0xF0) != 16 )
                {
                  if ( (*(_DWORD *)(v36 + 20) & 0xF0) == 32 )
                  {
                    v198 = "sp28a";
                  }
                  else
                  {
                    if ( (*(_DWORD *)(v36 + 20) & 0xF0) != 64 )
                    {
                      v42 = &LODFile_Icons_LOD;
                      if ( (*(_DWORD *)(v36 + 20) & 0xF0) == 128 )
                      {
                        v198 = "sp91a";
LABEL_85:
                        v43 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( v198, 2)];
                        v44 = dword_50C9A8 == cClock1.int_00001C;
                        v45 = dword_50C9A8 - cClock1.int_00001C < 0;
                        dword_50C9A8 -= cClock1.int_00001C;
                        if ( v45 | v44 )
                        {
                          dword_50C9A8 = 0;
                          *(_BYTE *)(&v36->dword_000014) &= 0xFu;
                          ptr_50C9A4 = 0;
                        }
                        v46 = (double)GetTickCount() * 0.1000000014901161;
                        Render_sub_4A63E6(
                          (int)pD3DRenderer,
                          v237,
                          v225,
                          v40 != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[v40] : 0,
                          v43,
                          (signed __int64)v46,
                          0,
                          255);
                        goto LABEL_93;
                      }
LABEL_84:
                      v198 = "sptext01";
                      goto LABEL_85;
                    }
                    v198 = "sp30a";
                  }
                  v42 = &LODFile_Icons_LOD;
                  goto LABEL_85;
                }
                v42 = &LODFile_Icons_LOD;
                goto LABEL_84;
              }
              v47 = v40 + 1;
              if ( v38 & 2 )
              {
                v48 = v47 != 0 ? &LODFile_Icons_LOD.aLODHeaders[v40] : 0;
                Render_sub_4A6776(pD3DRenderer, v237, v39, v48);
              }
              else
              {
                v48 = v47 != 0 ? &LODFile_Icons_LOD.aLODHeaders[v40] : 0;
                Render_DrawTransparentTexture(pD3DRenderer, v237, v39, v47 != 0 ? &LODFile_Icons_LOD.aLODHeaders[v40] : 0 );
              }
              if ( !dword_5118E0 )
                Render_DrawTextureToZBuffer(pD3DRenderer, v237, v225, v48, v260);
LABEL_93:
              Render_DrawTransparentTexture(pD3DRenderer, dword_4E4C28, dword_4E4C2C,
                &LODFile_Icons_LOD.aLODHeaders[pPaperdollTextures_Bodies[uSelectedCharacter - 1]]);
              v49 = pPlayer->pInventoryIndices[3];
              if ( !v49 )
                goto LABEL_127;
              v261 = pPlayer->pInventoryIndices[3];
              v50 = &pPlayer->pInventorySlots[v49 - 1];
              if (v50->uItemID != 504)
              {
                if (v50->uItemID == 505)
                {
                  v214 = 14;
                }
                else
                {
                  if (v50->uItemID == 516)
                  {
                    v214 = 13;
                  }
                  else
                  {
                    if (v50->uItemID != 533)
                    {
                      v51 = v50->uItemID - 66;
LABEL_104:
                      if ( v51 < 0 || v51 >= 17 )
                        goto LABEL_127;
                      goto LABEL_106;
                    }
                    v214 = 16;
                  }
                }
                v51 = v214;
LABEL_106:
                v55 = 17 * v268 + v51;
                v238 = dword_4E4C28 + dword_4E4E30[2 * v55];
                v53 = dword_4E4C2C + dword_4E4E30[2 * v55 + 1];
                v54 = dword_511290[3 * v55];
                v52 = *(_DWORD *)(v50 + 20);
                v226 = v53;
                if ( v52 & 0xF0 )
                {
                  if ( (*(_DWORD *)(v50 + 20) & 0xF0) != 16 )
                  {
                    if ( (*(_DWORD *)(v50 + 20) & 0xF0) == 32 )
                    {
                      v199 = "sp28a";
                    }
                    else
                    {
                      if ( (*(_DWORD *)(v50 + 20) & 0xF0) != 64 )
                      {
                        v56 = &LODFile_Icons_LOD;
                        if ( (*(_DWORD *)(v50 + 20) & 0xF0) == 128 )
                        {
                          v199 = "sp91a";
LABEL_117:
                          v57 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( v199, 2)];
                          v58 = dword_50C9A8 == cClock1.int_00001C;
                          v59 = dword_50C9A8 - cClock1.int_00001C < 0;
                          dword_50C9A8 -= cClock1.int_00001C;
                          if ( v59 | v58 )
                          {
                            dword_50C9A8 = 0;
                            *(_BYTE *)(&v50->dword_000014) &= 0xFu;
                            ptr_50C9A4 = 0;
                          }
                          v60 = (double)GetTickCount() * 0.1000000014901161;
                          Render_sub_4A63E6(
                            (int)pD3DRenderer,
                            v238,
                            v226,
                            v54 != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[v54] : 0,
                            v57,
                            (signed __int64)v60,
                            0,
                            255);
                          goto LABEL_127;
                        }
LABEL_116:
                        v199 = "sptext01";
                        goto LABEL_117;
                      }
                      v199 = "sp30a";
                    }
                    v56 = &LODFile_Icons_LOD;
                    goto LABEL_117;
                  }
                  v56 = &LODFile_Icons_LOD;
                  goto LABEL_116;
                }
                v61 = v54 + 1;
                if ( v52 & 2 )
                {
                  v62 = v61 != 0 ? &LODFile_Icons_LOD.aLODHeaders[v54] : 0;
                  Render_sub_4A6776(pD3DRenderer, v238, v53, v62);
                }
                else
                {
                  v63 = (v52 & 1) == 0;
                  v64 = &LODFile_Icons_LOD.aLODHeaders[v54];
                  if ( v63 )
                  {
                    v62 = v61 != 0 ? v64 : 0;
                    Render_DrawTransparentGreenChannel(pD3DRenderer, v238, v53, v62);
                  }
                  else
                  {
                    v62 = v61 != 0 ? v64 : 0;
                    Render_DrawTransparentTexture(pD3DRenderer, v238, v53, (cTexture *)v62);
                  }
                }
                if ( !dword_5118E0 )
                  Render_DrawTextureToZBuffer(pD3DRenderer, v238, v226, v62, v261);
LABEL_127:
                v65 = pPlayer->pInventoryIndices[8];
                if ( !v65 )
                  goto LABEL_155;
                v262 = pPlayer->pInventoryIndices[8];
                v67 = &pPlayer->pInventorySlots[v65 - 1];

                v66 = v67->uItemID;
                if (v67->uItemID == 529)
                {
                  v227 = dword_4E4C2C + dword_4E54B8[14 * v268 + 1];
                  v239 = dword_4E4C28 + dword_4E54B8[14 * v268];
                  v68 = pPaperdollTextures_Feet[pPlayer->uFace];
                }
                else
                {
                  if ( v66 == 512 )
                  {
                    v227 = dword_4E4C2C + dword_4E54B8[14 * v268 + 3];
                    v239 = dword_4E4C28 + dword_4E54B8[14 * v268 + 2];
                    v68 = uTextureListForPaperdoll[6 * v268 + 5];
                  }
                  else
                  {
                    v69 = v66 - 115;
                    if ( v69 < 0 || v69 >= 5 )
                    {
                      v239 = 0;
                      v227 = 0;
                      v68 = uTextureListForPaperdoll[6 * v268];
                    }
                    else
                    {
                      v70 = 8 * (v69 + 7 * v268);
                      v227 = dword_4E4C2C + *(int *)((char *)&dword_4E5494 + v70);
                      v239 = dword_4E4C28 + *(int *)((char *)&dword_4E5490 + v70);
                      v68 = uTextureListForPaperdoll[v69 + 6 * v268];
                    }
                  }
                }
                v71 = *(_DWORD *)(v67 + 20);
                if ( !(*(_DWORD *)(v67 + 20) & 0xF0) )
                {
                  v77 = v68 + 1;
                  v76 = &LODFile_Icons_LOD.aLODHeaders[v68];
                  if ( v71 & 2 )
                  {
                    v78 = v77 != 0 ? v76 : 0;
                    Render_sub_4A6776(pD3DRenderer, v239, v227, v78);
                  }
                  else
                  {
                    if ( v71 & 1 )
                    {
                      v78 = v77 != 0 ? v76 : 0;
                      Render_DrawTransparentTexture(pD3DRenderer, v239, v227, (cTexture *)v78);
                    }
                    else
                    {
                      v78 = v77 != 0 ? v76 : 0;
                      Render_DrawTransparentGreenChannel(pD3DRenderer, v239, v227, v78);
                    }
                  }
                  if ( !dword_5118E0 )
                    Render_DrawTextureToZBuffer(pD3DRenderer, v239, v227, v78, v262);
LABEL_155:
                  v79 = pPlayer->pInventoryIndices[1];
                  v276 = 8 * v268;
                  if ( !v79
                   || pClass40->pItems[pPlayer->pInventorySlots[v79 - 1].uItemID - 1].uEquipType != 1
                    && (pClass40->pItems[pPlayer->pInventorySlots[v79 - 1].uItemID - 1].uSkillType != Character::Skill::Spear || pPlayer->pInventoryIndices[0]) )
                    Render_DrawTransparentTexture(pD3DRenderer,
                      dword_4E4C28 + dword_4E5AE0[2 * v268],
                      dword_4E4C2C + dword_4E5AE0[2 * v268 + 1],
                      &LODFile_Icons_LOD.aLODHeaders[pPaperdollTextures_LeftArmsEmpty[uSelectedCharacter - 1]]);
                  v82 = pPlayer->pInventoryIndices[5];
                  if ( v82 )
                  {
                    v263 = pPlayer->pInventoryIndices[5];
                    v83 = &pPlayer->pInventorySlots[v82 - 1];

                    if (v83->uItemID == 524 )
                    {
                      v84 = 5;
                    }
                    else
                    {
                     if (v83->uItemID == 535 )
                      {
                        v84 = 6;
                        goto LABEL_168;
                      }
                     v84 = v83->uItemID - 100;
                    }
                    if ( v84 >= 0 && v84 < 7 )
                    {
LABEL_168:
                      v85 = 7 * v268 + v84;
                      v240 = dword_4E4C28 + dword_4E57F0[2 * v85];
                      v228 = dword_4E4C2C + dword_4E57F0[2 * v85 + 1];
                      if ( v277 != 1 || v84 == 5 )
                        v86 = uTextureListForPaperdoll[56 + v85];
                      else
                        v86 = uTextureListForPaperdoll[56 + (v84 + 7 * (v268 - 2))];
                      v87 = pPlayer->pInventorySlots[v82 - 1].dword_000014;
                      if ( !(pPlayer->pInventorySlots[v82 - 1].dword_000014 & 0xF0) )
                      {
                        v93 = v86 + 1;
                        v92 = &LODFile_Icons_LOD.aLODHeaders[v86];
                        if ( v87 & 2 )
                        {
                          v94 = v93 != 0 ? v92 : 0;
                          Render_sub_4A6776(pD3DRenderer, v240, v228, v94);
                        }
                        else
                        {
                          if ( v87 & 1 )
                          {
                            v94 = v93 != 0 ? v92 : 0;
                            Render_DrawTransparentTexture(pD3DRenderer, v240, v228, (cTexture *)v94);
                          }
                          else
                          {
                            v94 = v93 != 0 ? v92 : 0;
                            Render_DrawTransparentGreenChannel(pD3DRenderer, v240, v228, v94);
                          }
                        }
                        if ( !dword_5118E0 )
                          Render_DrawTextureToZBuffer(pD3DRenderer, v240, v228, v94, v263);
                        goto LABEL_191;
                      }
                      if ( (pPlayer->pInventorySlots[v82 - 1].dword_000014 & 0xF0) != 16 )
                      {
                        if ( (pPlayer->pInventorySlots[v82 - 1].dword_000014 & 0xF0) == 32 )
                        {
                          v201 = "sp28a";
                          goto LABEL_181;
                        }
                        if ( (pPlayer->pInventorySlots[v82 - 1].dword_000014 & 0xF0) == 64 )
                        {
                          v201 = "sp30a";
                          goto LABEL_181;
                        }
                        if ( (pPlayer->pInventorySlots[v82 - 1].dword_000014 & 0xF0) == 128 )
                        {
                          v201 = "sp91a";
LABEL_181:
                          v88 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( v201, 2)];
                          v89 = dword_50C9A8 == cClock1.int_00001C;
                          v90 = dword_50C9A8 - cClock1.int_00001C < 0;
                          dword_50C9A8 -= cClock1.int_00001C;
                          if ( v90 | v89 )
                          {
                            dword_50C9A8 = 0;
                            *(_BYTE *)(&v83->dword_000014) &= 0xFu;
                            ptr_50C9A4 = 0;
                          }
                          v91 = (double)GetTickCount() * 0.1000000014901161;
                          Render_sub_4A63E6(
                            (int)pD3DRenderer,
                            v240,
                            v228,
                            v86 != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[v86] : 0,
                            v88,
                            (signed __int64)v91,
                            0,
                            255);
LABEL_191:
                          goto LABEL_192;
                        }
                      }
                      v201 = "sptext01";
                      goto LABEL_181;
                    }
                  }
LABEL_192:
                  v95 = pPlayer->pInventoryIndices[1];
                  if ( v95 )
                  {
                   v96 = 48 * pPlayer->pInventorySlots[v95 - 1].uItemID;
                    if (pClass40->pItems[v96/48 - 1].uEquipType == 1 ||
                        pClass40->pItems[v96/48 - 1].uSkillType == Character::Skill::Spear && !pPlayer->pInventoryIndices[0])
                      Render_DrawTransparentTexture(pD3DRenderer,
                        dword_4E4C28 + dword_4E5B00[2 * v268],
                        dword_4E4C2C + dword_4E5B00[2 * v268 + 1],
                        //*(int *)((char *)pPaperdollTextures_LeftArmsWeapon + v269) != -1 ? 72 * *(int *)((char *)pPaperdollTextures_LeftArmsWeapon + v269) + 7145548 : 0);
                        &LODFile_Icons_LOD.aLODHeaders[pPaperdollTextures_LeftArmsWeapon[uSelectedCharacter - 1]]);

                  }
                  v98 = pPlayer->pInventoryIndices[3];
                  v264 = v98;
                  v100 = (int)pPlayer + 36 * v98;
                  v271 = v100;
                  v99 = pPlayer->pInventorySlots[v98 - 1].uItemID;
                  v97 = pPlayer->pInventorySlots[v98 - 1].uItemID - 504;
                  if ( v97 )
                  {
                    v101 = v97 - 1;
                    if ( v101 )
                    {
                      v102 = v101 - 11;
                      if ( v102 )
                      {
                        if ( v102 != 17 )
                        {
                          v103 = v99 - 66;
LABEL_207:
                          if ( v103 < 0 || v103 > 17 )
                          {
LABEL_259:
                            v130 = pPlayer->pInventoryIndices[6];
                            if ( !v130 )
                              goto LABEL_293;
                            v265 = pPlayer->pInventoryIndices[6];
                            v132 = &pPlayer->pInventorySlots[v130 - 1];

                            v131 = v132->uItemID;
                            if ( v131 != 525 )
                            {
                              switch ( v131 )
                              {
                                case 530:
                                  v220 = 6;
                                  break;
                                case 547:
                                  v220 = 7;
                                  break;
                                case 548:
                                  v220 = 8;
                                  break;
                                default:
                                  if ( v131 != 550 )
                                  {
                                    v133 = v131 - 105;
LABEL_272:
                                    if ( v133 >= 0 && v133 < 10 )
                                    {
LABEL_274:
                                      v136 = v133 + 10 * v268;
                                      v134 = uTextureListForPaperdoll[v136 + 84];
                                      v136 *= 8;
                                      v135 = dword_4E4C28 + *(int *)((char *)&dword_4E56B0 + v136);
                                      v242 = dword_4E4C28 + *(int *)((char *)&dword_4E56B0 + v136);
                                      v230 = dword_4E4C2C + *(int *)((char *)&dword_4E56B4 + v136);
                                      if ( v134 == LODFile_Icons_LOD.LODFile_sub_40F9F0( "pending") )
                                      {
LABEL_292:
                                        goto LABEL_293;
                                      }
                                      v137 = v132->dword_000014;
                                      if ( !(v132->dword_000014 & 0xF0) )
                                      {
                                        v142 = v134 + 1;
                                        v141 = &LODFile_Icons_LOD.aLODHeaders[v134];
                                        if ( v137 & 2 )
                                        {
                                          v143 = v142 != 0 ? v141 : 0;
                                          Render_sub_4A6776(pD3DRenderer, v242, v230, v143);
                                        }
                                        else
                                        {
                                          v143 = v142 != 0 ? v141 : 0;
                                          Render_DrawTransparentTexture(pD3DRenderer, v242, v230, (cTexture *)v143);
                                        }
                                        if ( !dword_5118E0 )
                                          Render_DrawTextureToZBuffer(pD3DRenderer, v242, v230, v143, v265);
                                        goto LABEL_292;
                                      }
                                      if ( (v132->dword_000014 & 0xF0) != 16 )
                                      {
                                        if ( (v132->dword_000014 & 0xF0) == 32 )
                                        {
                                          v208 = "sp28a";
                                          goto LABEL_284;
                                        }
                                        if ( (v132->dword_000014 & 0xF0) == 64 )
                                        {
                                          v208 = "sp30a";
                                          goto LABEL_284;
                                        }
                                        if ( (v132->dword_000014 & 0xF0) == 128 )
                                        {
                                          v208 = "sp91a";
LABEL_284:
                                          v243 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( v208, 2)];
                                          v138 = dword_50C9A8 == cClock1.int_00001C;
                                          v139 = dword_50C9A8 - cClock1.int_00001C < 0;
                                          dword_50C9A8 -= cClock1.int_00001C;
                                          if ( v139 | v138 )
                                          {
                                            dword_50C9A8 = 0;
                                            *(_BYTE *)(&v132->dword_000014) &= 0xFu;
                                            ptr_50C9A4 = 0;
                                          }
                                          v140 = (double)GetTickCount() * 0.1000000014901161;
                                          Render_sub_4A63E6((int)pD3DRenderer,
                                            v135,
                                            v230,
                                            v134 != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[v134]: 0,
                                            v243,
                                            (signed __int64)v140,
                                            0,
                                            255);
                                          goto LABEL_292;
                                        }
                                      }
                                      v208 = "sptext01";
                                      goto LABEL_284;
                                    }
LABEL_293:
                                    if (pPlayer->uFace == 12 || pPlayer->uFace == 13)
                                    {
                                      v144 = pPaperdollTextures_Beards[pPlayer->uFace];
                                      if ( v144 != LODFile_Icons_LOD.LODFile_sub_40F9F0( "Pending") )
                                        Render_DrawTransparentTexture(
                                          pD3DRenderer,
                                          dword_4E4C28 + dword_4E5AD0[2 * pPlayer->uFace - 24],
                                          dword_4E4C2C + dword_4E5AD0[2 * pPlayer->uFace - 24 + 1],
                                          (cTexture *)(v144 != -1 ? &LODFile_Icons_LOD.aLODHeaders[ v144 ] : 0));
                                    }
                                    v145 = pPlayer->pInventoryIndices[4];
                                    if ( !v145 )
                                      goto LABEL_335;
                                    v266 = v145;
                                    v146 = &pPlayer->pInventorySlots[v145 - 1];

                                    if (v146->uItemID != 521 )
                                    {
                                      switch (v146->uItemID)
                                      {
                                        case 0x20A:
                                          v221 = 12;
                                          break;
                                        case 0x20B:
                                          v221 = 13;
                                          break;
                                        case 0x214:
                                          v221 = 14;
                                          break;
                                        default:
                                          if (v146->uItemID != 544 )
                                          {
                                            v147 = v146->uItemID - 89;
LABEL_310:
                                            if ( v147 < 0 || v147 >= 16 )
                                              goto LABEL_335;
                                            goto LABEL_312;
                                          }
                                          v221 = 15;
                                          break;
                                      }
                                      v147 = v221;
LABEL_312:
                                      v148 = 8 * (v147 + 16 * v268);
                                      v244 = dword_4E4C28 + *(int *)((char *)&dword_4E58D0 + v148);
                                      v231 = dword_4E4C2C + *(int *)((char *)&dword_4E58D4 + v148);
                                      if ( v277 != 1 || *(_DWORD *)v146 != 92 )
                                        v149 = uTextureListForPaperdoll[24 + (v147 + 16 * sex)];
                                      else
                                        v149 = dword_511234;
                                      v150 = *(_DWORD *)(v146 + 20);
                                      if ( *(_DWORD *)(v146 + 20) & 0xF0 )
                                      {
                                        if ( (*(_DWORD *)(v146 + 20) & 0xF0) != 16 )
                                        {
                                          if ( (*(_DWORD *)(v146 + 20) & 0xF0) == 32 )
                                          {
                                            v209 = "sp28a";
                                            goto LABEL_325;
                                          }
                                          if ( (*(_DWORD *)(v146 + 20) & 0xF0) == 64 )
                                          {
                                            v209 = "sp30a";
                                            goto LABEL_325;
                                          }
                                          if ( (*(_DWORD *)(v146 + 20) & 0xF0) == 128 )
                                          {
                                            v209 = "sp91a";
LABEL_325:
                                            v151 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( v209, 2)];
                                            v152 = dword_50C9A8 == cClock1.int_00001C;
                                            v153 = dword_50C9A8 - cClock1.int_00001C < 0;
                                            dword_50C9A8 -= cClock1.int_00001C;
                                            if ( v153 | v152 )
                                            {
                                              dword_50C9A8 = 0;
                                              *(_BYTE *)(&v146->dword_000014) &= 0xFu;
                                              ptr_50C9A4 = 0;
                                            }
                                            v154 = (double)GetTickCount() * 0.1000000014901161;
                                            Render_sub_4A63E6(
                                              (int)pD3DRenderer,
                                              v244,
                                              v231,
                                              v149 != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[v149] : 0,
                                              v151,
                                              (signed __int64)v154,
                                              0,
                                              255);
                                            goto LABEL_335;
                                          }
                                        }
                                        v209 = "sptext01";
                                        goto LABEL_325;
                                      }
                                      v156 = v149 + 1;
                                      v155 = &LODFile_Icons_LOD.aLODHeaders[v149];
                                      if ( v150 & 2 )
                                      {
                                        v157 = v156 != 0 ? v155 : 0;
                                        Render_sub_4A6776(pD3DRenderer, v244, v231, v157);
                                      }
                                      else
                                      {
                                        if ( v150 & 1 )
                                        {
                                          v157 = v156 != 0 ? v155 : 0;
                                          Render_DrawTransparentTexture(pD3DRenderer, v244, v231, (cTexture *)v157);
                                        }
                                        else
                                        {
                                          v157 = v156 != 0 ? v155 : 0;
                                          Render_DrawTransparentGreenChannel(pD3DRenderer, v244, v231, v157);
                                        }
                                      }
                                      if ( !dword_5118E0 )
                                        Render_DrawTextureToZBuffer(pD3DRenderer, v244, v231, v157, v266);
LABEL_335:
                                      v158 = pPlayer->pInventoryIndices[1];
                                      if (v158 == -1)
                                        goto LABEL_358;
                                      v158 &= 0x7FFFFFFF;
                                      v160 = &pPlayer->pInventorySlots[v158];

                                      v161 = v160->uItemID;
                                      v159 = 48 * v160->uItemID;
                                      v245 = dword_4E4C28
                                           + dword_4E4C30[32 * v268 + 2]
                                           - *(__int16 *)((char *)&word_5D29FC + v159);
                                      v232 = dword_4E4C2C
                                           + dword_4E4C30[32 * v268 + 3]
                                           - *(__int16 *)((char *)&word_5D29FE + v159);
                                      if ( v161 == 64 )
                                        v210 = "item64v1";
                                      else
                                       v210 = (char *)pClass40->pItems[*(_DWORD *)v160].pIconName;
#ifdef OLD_CODE
                                      v163 = LODFile_Icons_LOD.LODFile_LoadTexture(v210, 2);
#else
                                      wchar_t pTextureNameW[256];
                                      wsprintfW(pTextureNameW, L"%S", v210);

                                      v163 = LODFile_Icons_LOD.LODFile_LoadTexture_New(pTextureNameW);
#endif

                                      v162 = v160->dword_000014;
                                      if ( !(v160->dword_000014 & 0xF0) )
                                      {
                                        v169 = v163 + 1;
                                        v168 = &LODFile_Icons_LOD.aLODHeaders[v163];
                                        if ( v162 & 2 )
                                        {
                                          v170 = v169 != 0 ? v168 : 0;
                                          Render_sub_4A6776(pD3DRenderer, v245, v232, v170);
                                        }
                                        else
                                        {
                                          if ( v162 & 1 )
                                          {
                                            v170 = v169 != 0 ? v168 : 0;
                                            Render_DrawTransparentTexture(pD3DRenderer, v245, v232, v170);
                                          }
                                          else
                                          {
                                            v170 = v169 != 0 ? v168 : 0;
                                            Render_DrawTransparentGreenChannel(pD3DRenderer, v245, v232, v170);
                                          }
                                        }
                                        if ( !dword_5118E0 )
                                          Render_DrawTextureToZBuffer(pD3DRenderer, v245, v232, v170, v158);
LABEL_358:
                                        v171 = pPlayer->pInventoryIndices[0];
                                        if (v171 == -1)
                                          goto LABEL_393;
                                        v171 &= 0x7FFFFFFF;
                                        v175 = &pPlayer->pInventorySlots[v171];

                                        v174 = v175->uItemID;
                                        v172 = 48 * v175->uItemID;
                                        v173 = pClass40->pItems[v172/48].uSkillType;
                                        if ( v173 != 2 && v173 != 1 )
                                        {
                                          v274 = 0;
LABEL_362:
                                          v176 = dword_4E4C28
                                               + dword_4E4C30[32 * v268]
                                               - *(__int16 *)((char *)&word_5D29FC + v172);
                                          v233 = dword_4E4C2C
                                               + dword_4E4C30[32 * v268 + 1]
                                               - *(__int16 *)((char *)&word_5D29FE + v172);
                                          goto LABEL_370;
                                        }
                                        v177 = v174 - 400;
                                        v274 = 1;
                                        if ( v177 )
                                        {
                                          v178 = v177 - 3;
                                          if ( v178 )
                                          {
                                            if ( v178 != 12 )
                                              goto LABEL_362;
                                            v176 = 595;
                                            v233 = 33;
LABEL_370:
#ifdef OLD_CODE
                                            v181 = LODFile_Icons_LOD.LODFile_LoadTexture(
                                                     (const char*)pClass40->pItems[v172 / 48].pIconName,
                                                     2);
#else
                                            wchar_t pTextureNameW[256];
                                            wsprintfW(pTextureNameW, L"%S", pClass40->pItems[v172 / 48].pIconName);

                                            v181 = LODFile_Icons_LOD.LODFile_LoadTexture_New(pTextureNameW);
#endif
                                            v180 = v181;
                                            v272 = v181;
                                            v179 = v175->dword_000014;
                                            if ( !(v175->dword_000014 & 0xF0) )
                                            {
                                              if ( v179 & 2 )
                                              {
                                                v187 = v272 != -1 ? &LODFile_Icons_LOD.aLODHeaders[v272] : 0;
                                                Render_sub_4A6776(pD3DRenderer, v176, v233, v187);
                                              }
                                              else
                                              {
                                                v188 = (v179 & 1) == 0;
                                                v189 = &LODFile_Icons_LOD.aLODHeaders[v272];
                                                if ( v188 )
                                                {
                                                  v187 = v272 != -1 ? v189 : 0;
                                                  Render_DrawTransparentGreenChannel(pD3DRenderer, v176, v233, v272 != -1 ? v189 : 0);
                                                }
                                                else
                                                {
                                                  v187 = v272 != -1 ? v189 : 0;
                                                  Render_DrawTransparentTexture(pD3DRenderer, v176, v233, v272 != -1 ? v189 : 0);
                                                }
                                              }
                                              if ( !dword_5118E0 )
                                                Render_DrawTextureToZBuffer(pD3DRenderer, v176, v233, v187, v171);
                                              goto LABEL_391;
                                            }
                                            if ( (v175->dword_000014 & 0xF0) != 16 )
                                            {
                                              if ( (v175->dword_000014 & 0xF0) == 32 )
                                              {
                                                v212 = "sp28a";
                                              }
                                              else
                                              {
                                                if ( (v175->dword_000014 & 0xF0) != 64 )
                                                {
                                                  v182 = &LODFile_Icons_LOD;
                                                  if ( (v175->dword_000014 & 0xF0) == 128 )
                                                  {
                                                    v212 = "sp91a";
LABEL_381:
                                                    v183 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( v212, 2)];
                                                    v184 = dword_50C9A8 == cClock1.int_00001C;
                                                    v185 = dword_50C9A8 - cClock1.int_00001C < 0;
                                                    dword_50C9A8 -= cClock1.int_00001C;
                                                    if ( v185 | v184 )
                                                    {
                                                      dword_50C9A8 = 0;
                                                      *(_BYTE *)(&v175->dword_000014) &= 0xFu;
                                                      ptr_50C9A4 = 0;
                                                    }
                                                    v186 = (double)GetTickCount() * 0.1000000014901161;
                                                    Render_sub_4A63E6(
                                                      (int)pD3DRenderer,
                                                      v176,
                                                      v233,
                                                      v180 != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[v180] : 0,
                                                      v183,
                                                      (signed __int64)v186,
                                                      0,
                                                      255);
LABEL_391:
                                                    if ( v274 )
                                                      Render_DrawTransparentTexture(
                                                        pD3DRenderer,
                                                        dword_4E4C28 + dword_4E5B40[2 * v268],
                                                        dword_4E4C2C + dword_4E5B40[2 * v268 + 1],
                                                        &LODFile_Icons_LOD.aLODHeaders[pPaperdollTextures_LeftHandsEmpty[uSelectedCharacter - 1]]);
                                                    goto LABEL_393;
                                                  }
LABEL_380:
                                                  v212 = "sptext01";
                                                  goto LABEL_381;
                                                }
                                                v212 = "sp30a";
                                              }
                                              v182 = &LODFile_Icons_LOD;
                                              goto LABEL_381;
                                            }
                                            v182 = &LODFile_Icons_LOD;
                                            goto LABEL_380;
                                          }
                                          v233 = 28;
                                        }
                                        else
                                        {
                                          v233 = 86;
                                        }
                                        v176 = 596;
                                        goto LABEL_370;
                                      }
                                      if ( (v160->dword_000014 & 0xF0) != 16 )
                                      {
                                        if ( (v160->dword_000014 & 0xF0) == 32 )
                                        {
                                          v211 = "sp28a";
                                          goto LABEL_348;
                                        }
                                        if ( (v160->dword_000014 & 0xF0) == 64 )
                                        {
                                          v211 = "sp30a";
                                          goto LABEL_348;
                                        }
                                        if ( (v160->dword_000014 & 0xF0) == 128 )
                                        {
                                          v211 = "sp91a";
LABEL_348:
                                          v164 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( v211, 2)];
                                          v165 = dword_50C9A8 == cClock1.int_00001C;
                                          v166 = dword_50C9A8 - cClock1.int_00001C < 0;
                                          dword_50C9A8 -= cClock1.int_00001C;
                                          if ( v166 | v165 )
                                          {
                                            dword_50C9A8 = 0;
                                            *(_BYTE *)(&v160->dword_000014) &= 0xFu;
                                            ptr_50C9A4 = 0;
                                          }
                                          v167 = (double)GetTickCount() * 0.1000000014901161;
                                          Render_sub_4A63E6(
                                            (int)pD3DRenderer,
                                            v245,
                                            v232,
                                            v163 != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[v163] : 0,
                                            v164,
                                            (signed __int64)v167,
                                            0,
                                            255);
                                          goto LABEL_358;
                                        }
                                      }
                                      v211 = "sptext01";
                                      goto LABEL_348;
                                    }
                                    v147 = 11;
                                    goto LABEL_310;
                                  }
                                  v220 = 9;
                                  break;
                              }
                              v133 = v220;
                              goto LABEL_274;
                            }
                            v133 = 5;
                            goto LABEL_272;
                          }
LABEL_209:
                          runtime_warning(GetItem with player.. wtf);
                          if (pPlayer->pInventoryIndices[1]
                            && (Player_GetEquippedItemEquipType(pPlayer, 1) == 1
                             || Player_GetEquippedItemSkillType(pPlayer, 1) == Character::Skill::Spear && !pPlayer->pInventoryIndices[0]) )
                          {
                            v105 = 17 * v268 + v103;
                            v104 = 12 * v105;
                            v252 = dword_511290[3 * v105 + 2];
                            if ( v252 == LODFile_Icons_LOD.LODFile_sub_40F9F0( "pending") )
                            {
                              v108 = 8 * v105;
                              v107 = *(int *)((char *)&dword_511290[1] + v104);
                              v241 = dword_4E4C28 + *(int *)((char *)dword_4E5050 + v108);
                              v106 = *(int *)((char *)dword_4E5050 + 4 + v108);
                            }
                            else
                            {
                              v107 = v252;
                              v241 = dword_4E4C28 + dword_4E5270[2 * v105];
                              v106 = dword_4E5270[2 * v105 + 1];
                            }
                            v229 = dword_4E4C2C + v106;
                            if ( v107 == LODFile_Icons_LOD.LODFile_sub_40F9F0( "pending") )
                              goto LABEL_258;
                            v109 = *(_DWORD *)(v271 + 516);
                            if ( *(_DWORD *)(v271 + 516) & 0xF0 )
                            {
                              if ( (*(_DWORD *)(v271 + 516) & 0xF0) != 16 )
                              {
                                if ( (*(_DWORD *)(v271 + 516) & 0xF0) == 32 )
                                {
                                  v202 = "sp28a";
                                  goto LABEL_226;
                                }
                                if ( (*(_DWORD *)(v271 + 516) & 0xF0) == 64 )
                                {
                                  v202 = "sp30a";
                                  goto LABEL_226;
                                }
                                if ( (*(_DWORD *)(v271 + 516) & 0xF0) == 128 )
                                {
                                  v202 = "sp91a";
LABEL_226:
                                  v110 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( v202, 2)];
                                  v111 = dword_50C9A8 == cClock1.int_00001C;
                                  v112 = dword_50C9A8 - cClock1.int_00001C < 0;
                                  dword_50C9A8 -= cClock1.int_00001C;
                                  if ( v112 | v111 )
                                  {
                                    dword_50C9A8 = 0;
                                    *(_BYTE *)(v271 + 516) &= 0xFu;
                                    ptr_50C9A4 = 0;
                                  }
                                  v216 = 255;
                                  v203 = 0;
                                  v113 = (double)GetTickCount();
LABEL_249:
                                  Render_sub_4A63E6(
                                    (int)pD3DRenderer,
                                    v241,
                                    v229,
                                    v107 != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[v107] : 0,
                                    v110,
                                    (signed __int64)(v113 * 0.1000000014901161),
                                    v203,
                                    v216);
                                  goto LABEL_258;
                                }
                              }
                              v202 = "sptext01";
                              goto LABEL_226;
                            }
                            v116 = v107 + 1;
                            v117 = (v109 & 2) == 0;
                            v114 = (int)&LODFile_Icons_LOD.aLODHeaders[v107];
                            if ( !v117 )
                            {
                              v118 = (cTexture *)v116 != 0 ? (cTexture *)v114 : 0;
                              v217 = v118;
                              v204 = v229;
                              v192 = v241;
LABEL_231:
                              Render_sub_4A6776(pD3DRenderer, v192, v204, v217);
                              goto LABEL_256;
                            }
                            if ( *(_BYTE *)(v271 + 516) & 1 )
                            {
                              v118 = (cTexture *)v116 != 0 ? (cTexture *)v114 : 0;
                              v218 = v118;
                              v205 = v229;
                              v193 = v241;
LABEL_234:
                              Render_DrawTransparentTexture(pD3DRenderer, v193, v205, v218);
                              goto LABEL_256;
                            }
                            v118 = (cTexture *)v116 != 0 ? (cTexture *)v114 : 0;
                            v219 = v118;
                            v206 = v229;
                            v194 = v241;
                            goto LABEL_255;
                          }
                          v119 = 17 * v268 + v103;
                          v107 = dword_511290[3 * v119 + 1];
                          if ( v107 == LODFile_Icons_LOD.LODFile_sub_40F9F0( "pending") )
                          {
LABEL_258:
                            goto LABEL_259;
                          }
                          v120 = dword_4E4C28 + dword_4E5050[2 * v119];
                          v122 = dword_4E4C2C + dword_4E5050[2 * v119 + 1];
                          v253 = *(_DWORD *)(v271 + 516);
                          v121 = *(_DWORD *)(v271 + 516) & 0xF0;
                          v241 = dword_4E4C28 + dword_4E5050[2 * v119];
                          v229 = dword_4E4C2C + dword_4E5050[2 * v119 + 1];
                          if ( !v121 )
                          {
                            v129 = v107 + 1;
                            v128 = &LODFile_Icons_LOD.aLODHeaders[v107];
                            if ( v253 & 2 )
                            {
                              v118 = v129 != 0 ? v128 : 0;
                              v217 = v118;
                              v204 = v122;
                              v192 = v120;
                              goto LABEL_231;
                            }
                            if ( v253 & 1 )
                            {
                              v118 = v129 != 0 ? v128 : 0;
                              v218 = v118;
                              v205 = v122;
                              v193 = v120;
                              goto LABEL_234;
                            }
                            v118 = v129 != 0 ? v128 : 0;
                            v219 = v118;
                            v206 = v122;
                            v194 = v120;
LABEL_255:
                            Render_DrawTransparentGreenChannel(pD3DRenderer, v194, v206, v219);
LABEL_256:
                            if ( !dword_5118E0 )
                              Render_DrawTextureToZBuffer(pD3DRenderer, v241, v229, v118, v264);
                            goto LABEL_258;
                          }
                          v123 = v121 - 16;
                          if ( v123 )
                          {
                            v124 = v123 - 16;
                            if ( !v124 )
                            {
                              v207 = "sp28a";
                              goto LABEL_246;
                            }
                            v125 = v124 - 32;
                            if ( !v125 )
                            {
                              v207 = "sp30a";
                              goto LABEL_246;
                            }
                            if ( v125 == 64 )
                            {
                              v207 = "sp91a";
LABEL_246:
                              v110 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( v207, 2)];
                              v126 = dword_50C9A8 == cClock1.int_00001C;
                              v127 = dword_50C9A8 - cClock1.int_00001C < 0;
                              dword_50C9A8 -= cClock1.int_00001C;
                              if ( v127 | v126 )
                              {
                                dword_50C9A8 = 0;
                                *(_BYTE *)(v271 + 516) &= 0xFu;
                                ptr_50C9A4 = 0;
                              }
                              v216 = 255;
                              v203 = 0;
                              v113 = (double)GetTickCount();
                              goto LABEL_249;
                            }
                          }
                          v207 = "sptext01";
                          goto LABEL_246;
                        }
                        v215 = 16;
                      }
                      else
                      {
                        v215 = 13;
                      }
                    }
                    else
                    {
                      v215 = 14;
                    }
                    v103 = v215;
                    goto LABEL_209;
                  }
                  v103 = 15;
                  goto LABEL_207;
                }
                if ( (*(_DWORD *)(v67 + 20) & 0xF0) != 16 )
                {
                  if ( (*(_DWORD *)(v67 + 20) & 0xF0) == 32 )
                  {
                    v200 = "sp28a";
                    goto LABEL_145;
                  }
                  if ( (*(_DWORD *)(v67 + 20) & 0xF0) == 64 )
                  {
                    v200 = "sp30a";
                    goto LABEL_145;
                  }
                  if ( (*(_DWORD *)(v67 + 20) & 0xF0) == 128 )
                  {
                    v200 = "sp91a";
LABEL_145:
                    v72 =(int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( v200, 2)];
                    v73 = dword_50C9A8 == cClock1.int_00001C;
                    v74 = dword_50C9A8 - cClock1.int_00001C < 0;
                    dword_50C9A8 -= cClock1.int_00001C;
                    if ( v74 | v73 )
                    {
                      dword_50C9A8 = 0;
                      *(_BYTE *)(&v67->dword_000014) &= 0xFu;
                      ptr_50C9A4 = 0;
                    }
                    v75 = (double)GetTickCount() * 0.1000000014901161;
                    Render_sub_4A63E6(
                      (int)pD3DRenderer,
                      v239,
                      v227,
                      v68 != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[v68] : 0,
                      v72,
                      (signed __int64)v75,
                      0,
                      255);
                    goto LABEL_155;
                  }
                }
                v200 = "sptext01";
                goto LABEL_145;
              }
              v51 = 15;
              goto LABEL_104;
            }
            v37 = 5;
            goto LABEL_72;
          }
LABEL_48:
          v197 = "sptext01";
          goto LABEL_49;
        }
        v197 = "sp30a";
      }
      v28 = &LODFile_Icons_LOD;
      goto LABEL_49;
    }
    v28 = &LODFile_Icons_LOD;
    goto LABEL_48;
  }
  v222 = dword_4E4C2C;
  v234 = dword_4E4C28;

  Render_DrawTransparentTexture(pD3DRenderer,
    dword_4E4C28,
    dword_4E4C2C,
    &LODFile_Icons_LOD.aLODHeaders[pPaperdollTextures_Bodies[uSelectedCharacter - 1]]);
  if ( !dword_5118E0 )
    Render_DrawTextureToZBuffer(pD3DRenderer,
      v234,
      v222,
      &LODFile_Icons_LOD.aLODHeaders[pPaperdollTextures_Bodies[uSelectedCharacter - 1]],
      pPlayer->pInventoryIndices[3]);
  v276 = 8 * v5;
  v6 = pPlayer->pInventoryIndices[1];
  if ( !v6 ||
      (v7 = 48 * pPlayer->pInventorySlots[v6 - 1].uItemID, pClass40->pItems[v7/48 - 1].uEquipType != 1) &&
      (pClass40->pItems[v7/48 - 1].uSkillType != Character::Skill::Spear || pPlayer->pInventoryIndices[0]) )
    Render_DrawTransparentTexture(pD3DRenderer,
      dword_4E4C28 + dword_4E5AE0[2 * v5],
      dword_4E4C2C + dword_4E5AE0[2 * v5 + 1],
      &LODFile_Icons_LOD.aLODHeaders[pPaperdollTextures_LeftArmsEmpty[uSelectedCharacter - 1]]);
  v8 = pPlayer->pInventoryIndices[1];
  if ( v8 )
  {
    v258 = pPlayer->pInventoryIndices[1];
    v11 = &pPlayer->pInventorySlots[v8 - 1];
    v12 = v5 << 7;

    v13 = v11->uItemID;
    v9 = 48 * v11->uItemID;
    v10 = dword_4E4C28 + dword_4E4C30[32 * v5 + 2] - *(__int16 *)((char *)&word_5D29FC + v9);
    v235 = v10;
    v223 = dword_4E4C2C + *(int *)((char *)dword_4E4C30 + 12 + v12) - *(__int16 *)((char *)&word_5D29FE + v9);
    if ( v13 == 64 )
      v195 = "item64v1";
    else
      v195 = *(const char **)(pClass40->pItems[0].pIconName + v9);
    v15 = LODFile_Icons_LOD.LODFile_LoadTexture( v195, 2);
    v14 = v11->dword_000014;
    if (v11->dword_000014 & 0xF0 )
    {
      if ( (v11->dword_000014 & 0xF0) != 16 )
      {
        if ( (v11->dword_000014 & 0xF0) == 32 )
        {
          v196 = "sp28a";
          goto LABEL_27;
        }
        if ( (v11->dword_000014 & 0xF0) == 64 )
        {
          v196 = "sp30a";
          goto LABEL_27;
        }
        if ( (v11->dword_000014 & 0xF0) == 128 )
        {
          v196 = "sp91a";
LABEL_27:
          v16 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( v196, 2)];
          v17 = dword_50C9A8 == cClock1.int_00001C;
          v18 = dword_50C9A8 - cClock1.int_00001C < 0;
          dword_50C9A8 -= cClock1.int_00001C;
          if ( v18 | v17 )
          {
            dword_50C9A8 = 0;
            *(_BYTE *)(&v11->dword_000014) &= 0xFu;
            ptr_50C9A4 = 0;
          }
          v19 = (double)GetTickCount() * 0.1000000014901161;
          Render_sub_4A63E6((int)pD3DRenderer,
            v10,
            v223,
            v15 != -1 ?(int)&LODFile_Icons_LOD.aLODHeaders[v15] : 0,
            v16,
            (signed __int64)v19,
            0,
            255);
          goto LABEL_393;
        }
      }
      v196 = "sptext01";
      goto LABEL_27;
    }
    v21 = v15 + 1;
    v20 = 72 * v15 + 7145548;
    if ( v14 & 2 )
    {
      v22 = v21 != 0 ? v20 : 0;
      Render_sub_4A6776(pD3DRenderer, v235, v223, (cTexture *)v22);
    }
    else
    {
      if ( v14 & 1 )
      {
        v22 = v21 != 0 ? v20 : 0;
        Render_DrawTransparentTexture(pD3DRenderer, v235, v223, (cTexture *)v22);
      }
      else
      {
        v22 = v21 != 0 ? v20 : 0;
        Render_DrawTransparentGreenChannel(pD3DRenderer, v235, v223, (cTexture *)v22);
      }
    }
    if ( !dword_5118E0 )
      Render_DrawTextureToZBuffer(pD3DRenderer, v235, v223, (cTexture *)v22, v258);
  }
LABEL_393:
  Render_DrawTransparentTexture(
    pD3DRenderer,
    dword_4E4C28 + dword_4E5B20[2 * v268],
    dword_4E4C2C + dword_4E5B20[2 * v268 + 1],
    //*(int *)((char *)pPaperdollTextures_RightHands + v269) != -1 ? 72 * *(int *)((char *)pPaperdollTextures_RightHands + v269) + 7145548 : 0);
    &LODFile_Icons_LOD.aLODHeaders[pPaperdollTextures_RightHands[uSelectedCharacter - 1]]);
  v190 = pPlayer->pInventoryIndices[1];
  if ( v190 )
  {
   v191 = 48 * pPlayer->pInventorySlots[v190 - 1].uItemID;
    if (pClass40->pItems[v191/48 - 1].uEquipType == 1 ||
        pClass40->pItems[v191/48 - 1].uSkillType == Character::Skill::Spear && !pPlayer->pInventoryIndices[0])
      Render_DrawTransparentTexture(pD3DRenderer,
        dword_4E4C28 + dword_4E5B00[2 * v268],
        dword_4E4C2C + dword_4E5B00[2 * v268 + 1],
        //*(int *)((char *)pPaperdollTextures_LeftHandsWeapon + v269) != -1 ? 72 * *(int *)((char *)pPaperdollTextures_LeftHandsWeapon + v269) + 7145548 : 0);
        &LODFile_Icons_LOD.aLODHeaders[pPaperdollTextures_LeftHandsWeapon[uSelectedCharacter - 1]]);
  }
  if ( !dword_5118E0 )
    Render_DrawTransparentTexture(pD3DRenderer, 603, 299, &LODFile_Icons_LOD.aLODHeaders[uTextureID_GameUI_MagnifyingGlass]);
  Render_DrawTransparentTexture(pD3DRenderer, 468, 0, &LODFile_Icons_LOD.aLODHeaders[uTextureID_507B04]);
}

//----- (0043E825) ----------.text:0043F396 ----------------------------------------------
void __fastcall CharacterUI_DrawPaperdoll2(int a1)
{
  int v1; // ecx@1
  Player *v2; // edi@1
  int v3; // ebx@1
  int v4; // eax@3
  int v5; // ebx@3
  ItemGen *v6; // edi@3
  LODFile_IB* v7; // ecx@7
  unsigned __int8 v8; // zf@14
  unsigned __int8 v9; // sf@14
  double v10; // st7@16
  int v11; // edi@17
  int v12; // edi@18
  char v13; // zf@19
  int v14; // eax@19
  unsigned __int8 v15; // zf@24
  char v16; // sf@24
  unsigned __int8 v17; // of@24
  int v18; // eax@25
  int v19; // eax@26
  int v20; // ebx@26
  LODFile_IB* v21; // ecx@30
  unsigned __int8 v22; // zf@37
  unsigned __int8 v23; // sf@37
  double v24; // st7@39
  int v25; // edi@40
  int v26; // eax@41
  int v27; // ebx@41
  int v28; // edi@41
  char v29; // zf@42
  int v30; // eax@42
  int v31; // eax@42
  int v32; // eax@46
  int v33; // eax@47
  int v34; // ebx@47
  ItemGen *v35; // edi@47
  LODFile_IB* v36; // ecx@51
  cTexture *v37; // esi@58
  unsigned __int8 v38; // zf@58
  unsigned __int8 v39; // sf@58
  double v40; // st7@60
  int v41; // esi@61
  cTexture *v42; // esi@62
  char v43; // zf@63
  cTexture *v44; // eax@63
  const char *v45; // [sp-8h] [bp-38h]@8
  const char *v46; // [sp-8h] [bp-38h]@31
  const char *v47; // [sp-8h] [bp-38h]@52
  int v48; // [sp+10h] [bp-20h]@3
  int v49; // [sp+10h] [bp-20h]@14
  int v50; // [sp+10h] [bp-20h]@26
  int v51; // [sp+10h] [bp-20h]@37
  int v52; // [sp+10h] [bp-20h]@47
  int v53; // [sp+14h] [bp-1Ch]@3
  int v54; // [sp+18h] [bp-18h]@3
  int v55; // [sp+1Ch] [bp-14h]@1
  Player *v56; // [sp+20h] [bp-10h]@1
  int v57; // [sp+24h] [bp-Ch]@1
  ItemGen *v58; // [sp+24h] [bp-Ch]@26

  v3 = a1;
  v2 = pPlayers[a1];
  v56 = pPlayers[a1];
  LODFile_Icons_LOD.LODFile_LoadTexture( "sptext01", 2);
  CharacterUI_DrawPaperdoll(v3);
  Render_DrawTransparentTexture(pD3DRenderer, 473, 0, (uTextureID_GameUI_PaperdollJewelryOverlay != -1 ? &LODFile_Icons_LOD.aLODHeaders[uTextureID_GameUI_PaperdollJewelryOverlay] : 0));
  Render_DrawTransparentTexture(pD3DRenderer, 468, 0, (uTextureID_507B04 != -1 ? &LODFile_Icons_LOD.aLODHeaders[uTextureID_507B04] : 0));
  Render_DrawTransparentTexture(pD3DRenderer,
    pCharacterUI_BtnDetail->uX,
    pCharacterUI_BtnDetail->uY,
    (dword_5118C8 != -1 ? &LODFile_Icons_LOD.aLODHeaders[dword_5118C8]: 0));
  v1 = 0;
  
  v57 = 0;
  for (v1=0; v1<=5; v1++)
  {	
     v55 = v2->pEquppedItemIndices[10+v1];  // + 6512
    if ( !(v55==0) )
		{
			v48 =v55;
			v6 = &v2->pInventorySlots[v55] ;//v2 + 36 * *(_DWORD *)v55 + 496
			v53 = dword_4E5C34[v1];
			v54 = dword_4E5C1C[v1];
			v5 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)pClass40->pItems[12 * v6->uItemID].pIconName, 2);
			v4 = (v6->dword_000014);
			
			switch 	((v6->dword_000014) & 0xF0)
				{
			case 16:
				{   
				v45 = "sptext01";
				break;
				}
			case 32:
				{   
				 v45 = "sp28a";
				break;
				}
			case 64:
				{   
				v45 = "sp30a";
				break;
				}
			case 128:
				{   
				v45 = "sp91a";
				break;
				}

			default:
				{
				
			    if ( v4 & 2 )
			  {
				v12 = v11 !=-1 ? (int)&LODFile_Icons_LOD.aLODHeaders[v5] : 0;
				Render_sub_4A6776(pD3DRenderer, v54, v53, (cTexture *)v12);
			  }
			  else
			  {
				
				
				if ( !(v4 & 1) )
				{
				  v12 = v5 != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[v5] : 0;
				  Render_DrawTransparentGreenChannel(pD3DRenderer, v54, v53, (cTexture *)v12);
				}
				else
				{
				  v12 = v5 != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[v5] : 0;
				  Render_DrawTransparentTexture(pD3DRenderer, v54, v53, (cTexture *)v12);
				}
			  }
			  Render_sub_4A601E(pD3DRenderer, v54, v53, (cTexture *)v12, v48);
				}
				}
			
			v49 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( v45, 2)];
			v8 = dword_50C9A8 == cClock1.int_00001C;
			v9 = dword_50C9A8 - cClock1.int_00001C < 0;
			dword_50C9A8 -= cClock1.int_00001C;
			if ( v9 | v8 )
			{
			  dword_50C9A8 = 0;
			  *(_BYTE *)(v6 + 20) &= 0xFu;
			  ptr_50C9A4 = 0;
			}
			v10 = (double)GetTickCount() * 0.1000000014901161;
			Render_sub_4A63E6((int)pD3DRenderer, v54, v53, v5 != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[v5]: 0, v49, (signed __int64)v10, 0, 255);
		//LABEL_23:
		//	v2 = v56;
		}
    //v55 = v2->pEquppedItemIndices[10+v1];

  //  v1++;// = v57 + 4;

   // compile_error;//v17 = __SETO__(v57 + 4, 20);
   // v15 = v57 == 16;
   // v16 = v57 - 16 < 0;
   // v57 += 4;
  }
 // while ( (unsigned __int8)(v16 ^ v17) | v15 );

  v18 = v2->pEquppedItemIndices[9];//	 *(_DWORD *)(v2 + 6508)
  if ( !(v18==0) )
	  {
  v50 = v2->pEquppedItemIndices[9];
  v58 =  &v2->pInventorySlots[v18];
  v20 = LODFile_Icons_LOD.LODFile_LoadTexture( (char *)pClass40->pItems[12 * v58->uItemID].pIconName, 2);
  v19 = (v58->dword_000014);
  if ( !(v58->dword_000014) & 0xF0) 
  {
    v25 = v20 + 1;
    if ( v19 & 2 )
    {
      //v26 = 9 * v20;
      v27 = 493;
      v28 = v25 != 0 ? (int)&LODFile_Icons_LOD.aLODHeaders[v20] : 0;
      Render_sub_4A6776(pD3DRenderer, 493, 91, (cTexture *)v28);
    }
    else
    {
      v29 = (v19 & 1) == 0;
     // v31 = 9 * v20;
      v27 = 493;
      v30 =(int)&LODFile_Icons_LOD.aLODHeaders[v20];
      if ( v29 )
      {
        v28 = v25 != 0 ? v30 : 0;
        Render_DrawTransparentGreenChannel(pD3DRenderer, 493, 91, (cTexture *)v28);
      }
      else
      {
        v28 = v25 != 0 ? v30 : 0;
        Render_DrawTransparentTexture(pD3DRenderer, 493, 91, (cTexture *)v28);
      }
    }
    Render_sub_4A601E(pD3DRenderer, v27, 91, (cTexture *)v28, v50);
    v2 = v56;
   
  }
  else
  if ( (*(_DWORD *)(v58 + 20) & 0xF0) == 16 )
  {
    v21 = &LODFile_Icons_LOD;
    goto LABEL_36;
  }
  if ( (*(_DWORD *)(v58 + 20) & 0xF0) == 32 )
  {
    v46 = "sp28a";
    goto LABEL_34;
  }
  if ( (*(_DWORD *)(v58 + 20) & 0xF0) == 64 )
  {
    v46 = "sp30a";
LABEL_34:
    v21 = &LODFile_Icons_LOD;
    goto LABEL_37;
  }
  v21 = &LODFile_Icons_LOD;
  if ( (*(_DWORD *)(v58 + 20) & 0xF0) == 128 )
  {
    v46 = "sp91a";
    goto LABEL_37;
  }
LABEL_36:
  v46 = "sptext01";
LABEL_37:
  v51 = (int)&LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( v46, 2)];
  v22 = dword_50C9A8 == cClock1.int_00001C;
  v23 = dword_50C9A8 - cClock1.int_00001C < 0;
  dword_50C9A8 -= cClock1.int_00001C;
  if ( v23 | v22 )
  {
    dword_50C9A8 = 0;
    *(_BYTE *)(v58 + 20) &= 0xFu;
    ptr_50C9A4 = 0;
  }
  v24 = (double)GetTickCount() * 0.1000000014901161;
  Render_sub_4A63E6((int)pD3DRenderer, 493, 91, v20 != -1 ?(int) &LODFile_Icons_LOD.aLODHeaders[v20] : 0, v51, (signed __int64)v24, 0, 255);
	  }
  v32 = v2->pEquppedItemIndices[7]; //*(_DWORD *)(v2 + 6500)
  if (v32==0 )
    return;
  v52 =v2->pEquppedItemIndices[7]; // *(_DWORD *)(v2 + 6500)
  v35 =&v2->pInventorySlots[v32];
  v34 =(int)LODFile_Icons_LOD.LODFile_LoadTexture( (char *)pClass40->pItems[12 *v35->uItemID].pIconName, 2);
  v33 = v35->dword_000014;
  if ( !((v35->dword_000014) & 0xF0) )
  {
    v41 = v34 + 1;
    if ( v33 & 2 )
    {
      v42 = v41 != 0 ? &LODFile_Icons_LOD.aLODHeaders[v34] : 0;
      Render_sub_4A6776(pD3DRenderer, 586, 88, v42);
    }
    else
    {
      v43 = (v33 & 1) == 0;
      v44 = &LODFile_Icons_LOD.aLODHeaders[v34];
      if ( v43 )
      {
        v42 = v41 != 0 ? v44 : 0;
        Render_DrawTransparentGreenChannel(pD3DRenderer, 586, 88, v42);
      }
      else
      {
        v42 = v41 != 0 ? v44 : 0;
        Render_DrawTransparentTexture(pD3DRenderer, 586, 88, v42);
      }
    }
    Render_sub_4A601E(pD3DRenderer, 586, 88, v42, v52);
    return;
  }
  if (( v35->dword_000014 & 0xF0) == 16 )
  {
    v36 = &LODFile_Icons_LOD;
    goto LABEL_57;
  }
  if ( (v35->dword_000014 & 0xF0) == 32 )
  {
    v47 = "sp28a";
    goto LABEL_55;
  }
  if (( v35->dword_000014 & 0xF0) == 64 )
  {
    v47 = "sp30a";
LABEL_55:
    v36 = &LODFile_Icons_LOD;
    goto LABEL_58;
  }
  v36 = &LODFile_Icons_LOD;
  if ( (v35->dword_000014 & 0xF0) == 128 )
  {
    v47 = "sp91a";
    goto LABEL_58;
  }
LABEL_57:
  v47 = "sptext01";
LABEL_58:
  v37 = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( v47, 2)];
  v38 = dword_50C9A8 == cClock1.int_00001C;
  v39 = dword_50C9A8 - cClock1.int_00001C < 0;
  dword_50C9A8 -= cClock1.int_00001C;
  if ( v39 | v38 )
  {
    dword_50C9A8 = 0;
    *(_BYTE *)(v35 + 20) &= 0xFu;
    ptr_50C9A4 = 0;
  }
  v40 = (double)GetTickCount() * 0.1000000014901161;
  Render_sub_4A63E6((int)pD3DRenderer, 586, 88, v34 != -1 ? (int)&LODFile_Icons_LOD.aLODHeaders[v34] : 0, (int)v37, (signed __int64)v40, 0, 255);
}

//----- (00417FE5) --------.text:004185E7    ------------------------------------------------
void __cdecl CharacterUI_SkillsTab_ShowHint()
{
 
  GUIButton *curr_button; // esi@6
  const char *v3; // eax@12
  POINT v5; // [sp+4h] [bp-8h]@1

  //GUICursor_GetMousePos(pGame->pGUICursor, (int)&v5, (int)&v6);
  GUICursor_GetMousePos(pGame->pGUICursor, &v5);
  if ( v5.x < 24 || v5.x > 455 || v5.y < 18 || v5.y > 36 )
  {
   	curr_button=pGUIWindow_CurrentMenu->pControlsHead;
    while(curr_button)
	 {
      if ( (curr_button->dword_000020 == 121)&&( v5.x >= curr_button->uX )&& (v5.x <= curr_button->uZ )&&
		     ( v5.y>= curr_button->uY )&&( v5.y <=curr_button->uW ) )
      {
             v3 = (const char *)sub_417BB5(uActiveCharacter-1, curr_button->dword_000024);
              sub_4179BC(aSkillNames[curr_button->dword_000024], v3);//sub_4179BC((int)(&dword_AE32D0)[4 * *(_DWORD *)(i + 36)], v3);      
      }
	  curr_button=curr_button->pNext;
    }
  }
  else
  {
    sub_4179BC(pGlobalTXT_LocalizationStrings[LOCSTR_SKILL_POINTS], (char *)pSkillPointsAttributeDescription);
  }
}

//----- (004B3157) --------------------------------------------------------
void __thiscall GUIWindow_sub_4B3157(const GUIWindow *_this)
{
  unsigned __int16 v1; // di@2
  const char *v2; // edx@4
  signed int v3; // edx@5
  int v4; // edi@9
  int v5; // eax@45
  int v6; // edi@45
  char *v7; // eax@45
  int v8; // edi@46
  int v9; // eax@50
  int v10; // [sp-10h] [bp-C8h]@53
  unsigned __int16 v11; // [sp-Ch] [bp-C4h]@53
  int v12; // [sp-Ch] [bp-C4h]@60
  int v13; // [sp-8h] [bp-C0h]@50
  int v14; // [sp-8h] [bp-C0h]@60
  int v15; // [sp-4h] [bp-BCh]@50
  cTexture *v16; // [sp-4h] [bp-BCh]@60
  char v17; // [sp+Ch] [bp-ACh]@5
  int v18; // [sp+14h] [bp-A4h]@4
  int v19; // [sp+18h] [bp-A0h]@4
  int v20; // [sp+1Ch] [bp-9Ch]@45

  GUIWindow local_60;
  //char v21; // [sp+60h] [bp-58h]@2
  //int v22; // [sp+68h] [bp-50h]@2
  //int v23; // [sp+70h] [bp-48h]@2

  __int16 v24[2]; // [sp+B4h] [bp-4h]@2

  if (ptr_507BC0)
  {
    memcpy(&local_60, _this, sizeof(GUIWindow));
    local_60.uFrameWidth -= 18;
    local_60.uFrameZ -= 18;
    v1 = 0xFFFFFFFF;
    *(_DWORD *)v24 = 0xFF1599E9;
    Render_DrawIndexedTexture(pD3DRenderer, 477, 0, &LODFile_Icons_LOD.aLODHeaders[uTextureID_Dialogue_Background]);
    Render_DrawTransparentTexture(pD3DRenderer, 468, 0, (uTextureID_507B04 != -1 ? &LODFile_Icons_LOD.aLODHeaders[uTextureID_507B04] : 0));
    if ( dword_5913F0 != dword_591424 || !dword_5C35D0 )
    {
      v18 = 130;
      v19 = 2 * pFontCreate->uFontHeight;
      v2 = (const char *)dword_59143C[13 * ptr_507BC0->dword_00001C];
      if ( v2 )
      {
        v3 = 2 * (pFontCreate->uFontHeight) - 6 - CalculateTextHeght(pFontCreate, v2, (GUIWindow *)&v17, 0, 0);
        if ( v3 < 0 )
          v3 = 0;
        GUIWindow_sub_44D406(&local_60,
          pFontCreate,
          490,
          v3 / 2 + 4,
          v1,
          (const char *)dword_59143C[13 * ptr_507BC0->dword_00001C],
          3);
      }
    }
    local_60.uFrameWidth += 8;
    local_60.uFrameZ += 8;
    if ( dword_5913F0 )
    {
      v4 = dword_5913F0 - 1;
      Render_DrawIndexedTexture(
        pD3DRenderer,
        uDialogueUIIconsOffsetX - 4,
        uDialogueUIIconsOffsetY - 4,
        (cTexture *)(dword_50795C_TextureID != -1 ? 72 * dword_50795C_TextureID + 7145548 : 0));
      Render_DrawIndexedTexture(pD3DRenderer, uDialogueUIIconsOffsetX, uDialogueUIIconsOffsetY, &LODFile_Icons_LOD.aLODHeaders[uTextureID_Dialogue_NPCPortrait[v4]]);
      if ( dword_4E28F8 == 14 )
      {
        CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
        goto LABEL_58;
      }
      if ( v4 || !dword_591080 )
      {
        sub_4B2A74();
      }
      else
      {
        wsprintfA((char *)TmpBuf,
          (char *)pGlobalTXT_LocalizationStrings[429],
          dword_591440[13 * (int)ptr_507BC0->dword_00001C],
          dword_591448[13 * (int)ptr_507BC0->dword_00001C]);
        GUIWindow_sub_44D406(&local_60, pFontCreate, 483, 113, v24[0], (char *)TmpBuf, 3);
        if ( dword_F8B198 <= 18 )
        {
          switch ( dword_F8B198 )
          {
            case 18:
              sub_4B6478();
              break;
            case 1:
              sub_4B910F();
              break;
            case 2:
              sub_4BA928();
              break;
            case 3:
              sub_4B4FCF();
              break;
            case 4:
              sub_4B9CC6();
              break;
            default:
              if ( dword_F8B198 > 4 )
              {
                if ( dword_F8B198 <= 16 )
                {
                  sub_4B5D7C();
                }
                else
                {
                  if ( dword_F8B198 == 17 )
                    sub_4B7911();
                }
              }
              break;
          }
          goto LABEL_58;
        }
        switch ( dword_F8B198 )
        {
          case 21:
            sub_4B8285();
            break;
          case 22:
            sub_4B7D7E();
            break;
          case 23:
            sub_4B705E();
            break;
          default:
            if ( dword_F8B198 <= 26 )
              break;
            if ( dword_F8B198 <= 28 )
            {
              sub_4B6943();
            }
            else
            {
              if ( dword_F8B198 != 30 )
              {
                if ( dword_F8B198 != 31 )
                  break;
                goto LABEL_36;
              }
              sub_4B4710();
            }
            break;
        }
      }
LABEL_58:
      if ( dword_5913F0 == dword_591424 && dword_5C35D0 )
      {
        Render_DrawIndexedTexture(pD3DRenderer, 556, 451, (uTextureIdx_BtnXxU != -1 ? &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_BtnXxU] : 0));
        v16 = uTextureIdx_BtnXokU != -1 ? &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_BtnXokU] : 0;
        v14 = 451;
        v12 = 476;
      }
      else
      {
        v16 = uTextureID_right_backgr != -1 ? &LODFile_Icons_LOD.aLODHeaders[uTextureID_right_backgr] : 0;
        v14 = 445;
        v12 = 471;
      }
      Render_DrawIndexedTexture(pD3DRenderer, v12, v14, v16);
      return;
    }
    if ( dword_F8B198 == 31 )
    {
LABEL_36:
      sub_4B4F4F();
      goto LABEL_58;
    }
    if ( dword_F8B1E8 )
    {
      v18 = 458;
      v20 = 457;
      v5 = CalculateTextHeght(pFontArrus, dword_F8B1E8, (GUIWindow *)&v17, 13, 0);
      v6 = v5 + 7;
      Render_sub_4A6A68(
        pD3DRenderer,
        8,
        352 - (v5 + 7),
        uTextureIdx_Leather != -1 ?(int) &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_Leather] : 0,
        (uTextureIdx_Leather != -1 ? LODFile_Icons_LOD.aLODHeaders[uTextureIdx_Leather].uTextureHeight : 26) - (v5 + 7));
      Render_DrawIndexedTexture(pD3DRenderer, 8, 347 - v6, pcTexture_EndcapTexture);
      v7 = (char *)FitTextInAWindow(dword_F8B1E8, pFontArrus, (GUIWindow *)&v17, 13, 0);
      FontDrawText(ptr_507BC0, pFontArrus, 13, 354 - v6, v7, 0, 0, 0);
    }
    v8 = 0;
    if ( dword_591424 <= 0 )
      goto LABEL_58;
    while ( 1 )
    {
      Render_DrawIndexedTexture(
        pD3DRenderer,
        *(&uDialogueUIIconsOffsetX + v8 + 6 * dword_591424 - 6) - 4,
        *(&uDialogueUIIconsOffsetY + v8 + 6 * dword_591424 - 6) - 4,
        (dword_50795C_TextureID != -1 ? &LODFile_Icons_LOD.aLODHeaders[dword_50795C_TextureID] : 0));
      Render_DrawIndexedTexture(pD3DRenderer,
        *(&uDialogueUIIconsOffsetX + v8 + 6 * dword_591424 - 6),
        *(&uDialogueUIIconsOffsetY + v8 + 6 * dword_591424 - 6),
        &LODFile_Icons_LOD.aLODHeaders[uTextureID_Dialogue_NPCPortrait[v8]]);
      if ( dword_591424 < 4 )
        break;
LABEL_57:
      ++v8;
      if ( v8 >= dword_591424 )
        goto LABEL_58;
    }
    if ( v8 + 1 == dword_591424 && dword_5C35D0 )
    {
      v15 = 3;
      v13 = (int)pMapStats->pMapInfos[dword_5C35D0].pLocationName;
      v9 = 94 * v8 + 113;
    }
    else
    {
      if ( !v8 && dword_591080 )
      {
        v15 = 3;
        v13 = dword_591448[13 * (int)ptr_507BC0->dword_00001C];
        v11 = v24[0];
        v10 = 113;
LABEL_56:
        GUIWindow_sub_44D406(&local_60, pFontCreate, 483, v10, v11, (const char *)v13, v15);
        goto LABEL_57;
      }
      v15 = 3;
      v13 = *(_DWORD *)dword_5913D8[v8 - (dword_591080 != 0)];
      v9 = dword_4E5EC8[v8 + 6 * dword_591424] +
           LODFile_Icons_LOD.aLODHeaders[uTextureID_Dialogue_NPCPortrait[v8]].uTextureHeight + 2;
    }
    v11 = v24[0];
    v10 = v9;
    goto LABEL_56;
  }
}


//----- (004156F0) --------------------------------------------------------
void __cdecl sub_4156F0_LooksLike_UI_ProcessCallbacks()
{
  signed int v0; // eax@4
 struct GUIWindow *pWnd; // esi@4
  int v2; // eax@10
  int v3; // eax@11
  int v4; // eax@12
  int v5; // eax@20
  int v6; // eax@21
  int v7; // eax@29
  int v8; // eax@30
  int v9; // eax@31
  int v10; // eax@41
  int v11; // ecx@42
  int v12; // eax@48
  int v13; // eax@49
  int v14; // eax@57
  int v15; // eax@58
  int v16; // eax@59
  int v17; // eax@60
  int v18; // eax@61
  int v19; // eax@62
  const char *v20; // edx@66
  struct GUIButton *v21; // ebp@66
  struct GUIButton *v22; // ebp@79
  const char *v23; // edx@80
  char v24; // zf@81
  signed int v25; // eax@91
  int v26; // eax@98
  __int16 v27; // bp@106
  int v28; // ecx@109
  int v29; // eax@111
  int v30; // ST1C_4@115
  int v31; // eax@115
  struct GUIButton *v32; // ebp@118
  //int v33; // eax@119
  int v34; // eax@120
  int v35; // eax@121
  int v36; // eax@122
  int v37; // eax@123
  int v38; // eax@124
  signed int v39; // eax@129
  const char *v40; // edx@138
  int v41; // eax@142
  const char *v42; // edx@146
  struct GUIButton *v43; // ebp@146
  int v44; // [sp-1Ch] [bp-124h]@17
  int v45; // [sp-18h] [bp-120h]@17
  cTexture *v46; // [sp-14h] [bp-11Ch]@17
  int v47; // [sp-14h] [bp-11Ch]@86
  signed int i; // [sp+0h] [bp-108h]@3

  struct ItemGen local_04;
  //int v49; // [sp+4h] [bp-104h]@98
  //int v50; // [sp+8h] [bp-100h]@104
  //int v51; // [sp+14h] [bp-F4h]@101
  //int v52; // [sp+18h] [bp-F0h]@100
  //char v53; // [sp+1Dh] [bp-EBh]@101

  struct GUIButton local_28;
  //int Dst; // [sp+28h] [bp-E0h]@133
  //int v55; // [sp+2Ch] [bp-DCh]@133
  //int v56; // [sp+30h] [bp-D8h]@133
  //int v57; // [sp+34h] [bp-D4h]@133
  //int v58; // [sp+38h] [bp-D0h]@133
  //int v59; // [sp+3Ch] [bp-CCh]@133
  //int v60; // [sp+60h] [bp-A8h]@133

  char v61; // [sp+E4h] [bp-24h]@129

  if ( sub_466CA0() != MENU_CREATEPARTY )
    sub_41CD4F_MaybeOnlyUI_OnKeyDown(VK_NEXT);
  for ( i = 1; i <= sLastGUIWindowIdx; ++i )
  {
    pWnd = &GUIWindow_List[array_5075E0[i] - 1];
    v0 = pWnd->uWindowType;
    if ( pWnd->uWindowType > 70 )
    {
      if ( pWnd->uWindowType > 95 )
      {
        if (pWnd->uWindowType == 96 )
        {
          if ((int)pWnd->ptr_000048 != 1)
            AudioPlayer_sub_4AA306(pAudioPlayer, 75, 0, 0, -1, 0, 0, 0, 0);
          v43 = pWnd->ptr_00001C;
          Render_DrawIndexedTexture(pD3DRenderer, pWnd->uFrameX, pWnd->uFrameY, v43->pTexture[0]);
          v42 = *(const char **)((char*)pWnd + 72);
          struct_576FE8.dword_000044 = 1;
          if ( v42 )
          {
            if ( v42 != (const char *)1 )
              GUIButton_sub_415180((GUIButton *)v43, (unsigned char *)v42, pFontCreate, 0, 0);
          }
          GUIWindowDelete(pWnd);
    /*      if ( dword_50CBD0[0] >= 40 )
            continue;
          v41 = dword_50CBD0[0];
LABEL_151:
          dword_50CBD0[3 * v41 + 1] = 113;
LABEL_152:
          dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
          dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;	 */

		   	dword_50CBD0.PutMessageToQueue(113,0,0);
			continue;
        }
        v34 = pWnd->uWindowType - 1;
        if ( v34 )
        {
          v35 = v34 - 1;
          if ( v35 )
          {
            v36 = v35 - 1;
            if ( v36 )
            {
              v37 = v36 - 4;
              if ( v37 )
              {
                v38 = v37 - 2;
                if ( v38 )
                {
                  if ( v38 == 1 )
                    sub_414D9A();
                }
                else
                {
                  sub_4142D3();
                }
              }
              else
              {
                GUIWindow_sub_415551(pWnd, 0);
                FontDrawText(pWnd, pFontLucida, 10, 20, "Making item number", 0, 0, 0);
                FontDrawText(pWnd, pFontLucida, 10, 40, (char *)pKeyboardController->pPressedKeysBuffer, 0, 0, 0);
                if ( !dword_69B004 )
                {
                  ItemGen_Reset((ItemGen *)&v61);
                  GUIWindowDelete(pWnd);
                 cClock1.clock_sub_426363();
                  dword_4E28F8 = 0;
                  struct_576FE8.dword_000044 = 1;
                  v39 = atoi((char *)pKeyboardController->pPressedKeysBuffer);
                  if ( v39 > 0 )
                  {
                    if ( v39 < 800 )
                      sub_450B0A(v39);
                  }
                }
              }
              continue;
            }
            v46 = pWnd->ptr_00001C->pTexture[0];
            v45 = pWnd->uFrameY;
            v44 = pWnd->uFrameX;
LABEL_18:
            Render_DrawIndexedTexture(pD3DRenderer, v44, v45, v46);
LABEL_114:
            struct_576FE8.dword_000044 = 1;
            continue;
          }
          memset(&local_28, 0, sizeof(struct GUIButton));
          local_28.uZ = 197;
          local_28.uW = 197;
          local_28.uX = 27;
          local_28.uY = 161;
          local_28.uWidth = 171;
          local_28.uHeight = 37;
          local_28.pParentWindow = dword_507640->pParentWindow;
          AudioPlayer_sub_4AA306(pAudioPlayer, 75, 0, 0, -1, 0, 0, 0, 0);
          Render_DrawIndexedTexture(pD3DRenderer, pWnd->uFrameX, pWnd->uFrameY, pWnd->ptr_00001C->pTexture[0]);
          struct_576FE8.dword_000044 = 1;
          GUIButton_sub_415180(&local_28, pGlobalTXT_LocalizationStrings[LOCSTR_REST_HEAL_8], pFontCreate, 0, 0);
          local_28.pParentWindow = 0;
          goto LABEL_134;
        }
        if ((int)pWnd->ptr_000048 != 1 )
          AudioPlayer_sub_4AA306(pAudioPlayer, 75, 0, 0, -1, 0, 0, 0, 0);
        v32 = pWnd->ptr_00001C;
        Render_DrawIndexedTexture(pD3DRenderer, pWnd->uFrameX, pWnd->uFrameY, v32->pTexture[1]);
        goto LABEL_138;
      }
      if ( v0 == 95 )
      {
        if ((int)pWnd->ptr_000048 != 1 )
          AudioPlayer_sub_4AA306(pAudioPlayer, 75, 0, 0, -1, 0, 0, 0, 0);
        v32 = pWnd->ptr_00001C;
        Render_DrawTransparentTexture(pD3DRenderer, pWnd->uFrameX, pWnd->uFrameY, v32->pTexture[0]);
LABEL_138:
        v40 = *(const char **)((char*)pWnd + 72);
        struct_576FE8.dword_000044 = 1;
        if ( v40 )
        {
          if ( v40 != (const char *)1 )
            GUIButton_sub_415180((GUIButton *)v32, (unsigned char *)v40, pFontCreate, 0, 0);
        }
        GUIWindowDelete(pWnd);
        goto LABEL_142;
      }
      v14 = v0 - 80;
      if ( v14 )
      {
        v15 = v14 - 9;
        if ( !v15 )
        {
          GUIWindow_sub_415551(pWnd, 0);
          FontDrawText(pWnd, pFontLucida, 10, 20, "Making item number", 0, 0, 0);
          FontDrawText(pWnd, pFontLucida, 10, 40, (char *)pKeyboardController->pPressedKeysBuffer, 0, 0, 0);
          if ( !dword_69B004 )
          {
            ItemGen_Reset(&local_04);
            GUIWindowDelete(pWnd);
            cClock1.clock_sub_426363();
            dword_4E28F8 = 0;
            struct_576FE8.dword_000044 = 1;
            v26 = atoi((char *)pKeyboardController->pPressedKeysBuffer);
            if ( v26 > 0 )
            {
              if ( v26 < 800 )
              {
               local_04.dword_000014 |= 1u;
                local_04.uItemID = v26;
                if (pClass40->pItems[v26].uEquipType == 12 )
                {
                 local_04.dword_000010 = rand() % 6 + pClass40->pItems[local_04.uItemID - 1].uDamageModifier + 1;
                 local_04.byte_000019 = local_04.dword_000010;
                }
                else
                {
                  if ( v26 >= 221 )
                  {
                    if ( v26 < 271 )
                     local_04.dword_000004 = rand() % 10 + 1;
                  }
                }
                class40_sub_456D17(pClass40, &local_04);
                Party_sub_4936E1(pParty_global, &local_04);
              }
            }
          }
          continue;
        }
        v16 = v15 - 1;
        if ( !v16 )
        {
          if ((int)pWnd->ptr_000048 != 1)
            AudioPlayer_sub_4AA306(pAudioPlayer, 75, 0, 0, -1, 0, 0, 0, 0);
          v22 = (GUIButton *)pWnd->dword_00001C;
          if (v22->uX >= 0 )
          {
            if ( v22->uX <= 640 )
            {
             v25 = v22->uY;
              if ( v25 >= 0 )
              {
                if ( v25 <= 480 )
                {
                 // v47 = v22->uTextureID;
                  Render_DrawIndexedTexture(pD3DRenderer, pWnd->uFrameX, pWnd->uFrameY, v22->pTexture[0]);
                  goto LABEL_80;
                }
              }
            }
          }
          v23 = *(const char **)((char*)pWnd + 72);
          struct_576FE8.dword_000044 = 1;
          if ( v23 )
          {
            v24 = v23 == (const char *)1;
            goto LABEL_82;
          }
LABEL_134:
          v28 = (int)pWnd;
          goto LABEL_110;
        }
        v17 = v16 - 1;
        if ( !v17 )
        {
          if ((int)pWnd->ptr_000048 != 1)
            AudioPlayer_sub_4AA306(pAudioPlayer, 75, 0, 0, -1, 0, 0, 0, 0);
          v22 = pWnd->ptr_00001C;
       //   v47 = ;
//LABEL_94:
          //Render_DrawIndexedTexture(pD3DRenderer, pWnd->uFrameX, pWnd->uFrameY, v47);
          Render_DrawIndexedTexture(pD3DRenderer, pWnd->uFrameX, pWnd->uFrameY, v22->pTexture[0]);
LABEL_80:
          v23 = (char *)pWnd->ptr_000048;
          struct_576FE8.dword_000044 = 1;
          if ( v23 )
          {
            v24 = v23 == (const char *)1;
LABEL_82:
            if ( !v24 )
              GUIButton_sub_415180((GUIButton *)v22, (unsigned char *)v23, pFontCreate, 0, 0);
          }
          goto LABEL_134;
        }
        v18 = v17 - 1;
        if ( !v18 )
        {
          if ((int)pWnd->ptr_000048 != 1)
            AudioPlayer_sub_4AA306(pAudioPlayer, 75, 0, 0, -1, 0, 0, 0, 0);
          v22 = pWnd->ptr_00001C;
          Render_DrawTransparentTexture(pD3DRenderer, pWnd->uFrameX, pWnd->uFrameY, v22->pTexture[0]);
          goto LABEL_80;
        }
        v19 = v18 - 1;
        if ( !v19 )
        {
          if ((int)pWnd->ptr_000048 != 1)
            AudioPlayer_sub_4AA306(pAudioPlayer, 75, 0, 0, -1, 0, 0, 0, 0);
          Render_DrawTransparentTexture(pD3DRenderer, pWnd->uFrameX, pWnd->uFrameY, pWnd->ptr_00001C->pTexture[1]);
          struct_576FE8.dword_000044 = 1;
          goto LABEL_134;
        }
        if ( v19 == 1 )
        {
          if ((int)pWnd->ptr_000048 != 1)
            AudioPlayer_sub_4AA306(pAudioPlayer, 75, 0, 0, -1, 0, 0, 0, 0);
          v21 = pWnd->ptr_00001C;
          Render_DrawIndexedTexture(pD3DRenderer, pWnd->uFrameX, pWnd->uFrameY,v21->pTexture[0] );
          v20 = (char*)pWnd->ptr_000048;
          struct_576FE8.dword_000044 = 1;
          if ( v20 )
          {
            if ( v20 != (const char *)1 )
              GUIButton_sub_415180((GUIButton *)v21, (unsigned char *)v20, pFontCreate, 0, 0);
          }
          GUIWindowDelete(pWnd);
          if ( dword_4E28F8 == 11 )
          {
          /*  if ( dword_50CBD0[0] < 40 )
            {
              dword_50CBD0[3 * dword_50CBD0[0] + 1] = 83;
              goto LABEL_152;
            }  */
			 dword_50CBD0.PutMessageToQueue(83,0,0);
			    continue;
          }
          else
          {
           /* if ( dword_50CBD0[0] < 40 )
            {
              dword_50CBD0[3 * dword_50CBD0[0] + 1] = 82;
              goto LABEL_152;
            }  */
		   dword_50CBD0.PutMessageToQueue(82,0,0);
				 continue;
          }
        }
      }
      else
      {
        v27 = 0xFFFFFF;//colored or white text flag
        if (ptr_507BD0->dword_000040 == 1)
        {
          GUIWindow_sub_415551(ptr_507BD0, 0);
          FontDrawText(ptr_507BD0, pFontCreate, 30, 40, (char *)pKeyboardController->pPressedKeysBuffer, 0, 0, 0);
          v30 = (int)pFontCreate;
          v31 = GetStringWidth(pFontCreate, (char *)pKeyboardController->pPressedKeysBuffer);
          GUIWindow_sub_459C2B(ptr_507BD0, v31 + 30, 40, v30);
          continue;
        }
        if (ptr_507BD0->dword_000040 == 2)
        {
         // v29 = dword_50CBD0[0];
          pWnd->dword_000040 = 0;
         /* if ( v29 < 40 )
          {
           dword_50CBD0[3 * v29 + 1] = (int)ptr_507BD0->dword_00001C;
            dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
            dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
          }	*/
		  dword_50CBD0.PutMessageToQueue(ptr_507BD0->dword_00001C,0,0);
          cClock1.clock_sub_426363();
          GUIWindowDelete(ptr_507BD0);
          dword_4E28F8 = 0;
          goto LABEL_114;
        }
        if (ptr_507BD0->dword_000040 == 3)
        {
          pWnd->dword_000040 = 0;
          cClock1.clock_sub_426363();
          v28 = (int)ptr_507BD0;
LABEL_110:
          GUIWindowDelete((GUIWindow *)v28);
          continue;
        }
      }
    }
    else
    {
      if ( v0 == 70 )
      {
        sub_41420D();
        continue;
      }
      if ( v0 > 18 )
      {
        if ( v0 > 25 )
        {
          v12 = v0 - 26;
          if ( v12 )
          {
            v13 = v12 - 4;
            if ( v13 )
            {
              if ( v13 == 1 )
              {
                Render_ClearZBuffer(pD3DRenderer, 0, 479);
                sub_41A556();
                CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
                CharacterUI_DrawPaperdoll(uActiveCharacter);
                Render_DrawTransparentTexture(
                  pD3DRenderer,
                  dword_5076F4->uX,
                  dword_5076F4->uY,
                  (uTextureIdx_BtnXxU != -1 ? &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_BtnXxU] : 0));
              }
            }
            else
            {
              sub_467FB6();
            }
          }
          else
          {
            sub_444A51();
          }
          continue;
        }
        if ( v0 != 25 )
        {
          v7 = v0 - 19;
          if ( v7 )
          {
            v8 = v7 - 1;
            if ( v8 )
            {
              v9 = v8 - 3;
              if ( v9 )
              {
                if ( v9 == 1 )
                  sub_4606F7();
              }
              else
              {
                sub_4606FE();
              }
            }
            else
            {
              if ( dword_4E28F8 == 10 )
              {
                sub_42092D((int)pWnd->dword_00001C);
              }
              else
              {
                if ( dword_4E28F8 == 15 )
                {
                  Render_ClearZBuffer(pD3DRenderer, 0, 479);
                  sub_41A556();
                  CharacterUI_DrawInventoryTab(uActiveCharacter, 1);
                  Render_DrawTransparentTexture(
                    pD3DRenderer,
                    dword_5076F4->uX,
                    dword_5076F4->uY,
                    uTextureID_right_backgr != -1 ? &LODFile_Icons_LOD.aLODHeaders[uTextureID_right_backgr] : 0);
                }
              }
            }
          }
          else
          {
            sub_444FBE_DrawBranchlessDialogueUI();
          }
          continue;
        }
        GUIWindow_sub_4B3157(&GUIWindow_List[array_5075E0[i] - 1]);
        if ( !ptr_507BC0)
          continue;
        v10 = (int)ptr_507BC0->dword_00001C;
        if ( v10 >= 53 )
          continue;
        v11 = pParty_global->Abc.array_000334[2 * v10 + 1];

        compile_error;//if ( !__PAIR__(v11, pParty_global->array_000334[2 * v10])
          //|| v11 < HIDWORD(pParty_global->qword_00002C)
          //|| v11 <= HIDWORD(pParty_global->qword_00002C) && (unsigned int)pParty_global->array_000334[2 * v10] <= (_DWORD)pParty_global->qword_00002C )
        if (0)
        {
          if ( v10 < 53 )
          {
            pParty_global->Abc.array_000334[2 * v10] = 0;
            pParty_global->Abc.array_000334[2 * v10 + 1] = 0;
          }
          continue;
        }
LABEL_142:
      //  v41 = dword_50CBD0[0];
       // if ( dword_50CBD0[0] < 40 )
       //   goto LABEL_151;
		  dword_50CBD0.PutMessageToQueue(113,0,0);
        continue;
      }
      if ( v0 == 18 )
      {
        sub_412B58();
      }
      else
      {
        if ( v0 > 10 )
        {
          v5 = v0 - 12;
          if ( v5 )
          {
            v6 = v5 - 4;
            if ( v6 )
            {
              if ( v6 == 1 )
                sub_444DCA();
            }
            else
            {
              sub_41FA01();
            }
          }
          else
          {
            QuickRefDraw();
          }
          continue;
        }
        if ( v0 != 10 )
        {
          v2 = v0 - 3;
          if ( v2 )
          {
            v3 = v2 - 1;
            if ( v3 )
            {
              v4 = v3 - 2;
              if ( v4 )
              {
                if ( v4 == 3 )
                  sub_413CC6_DrawSpellbook(pWnd->dword_00001C);
              }
              else
              {
                sub_414F82_DrawGameOptions();
              }
            }
            else
            {
              CharacterUI_DoDrawCharacterScreen(uActiveCharacter);
            }
            continue;
          }
          v46 = dword_507944 != -1 ? &LODFile_Icons_LOD.aLODHeaders[dword_507944] : 0;
          v45 = pOldViewport->uGameY;
          v44 = pOldViewport->uGameX;
          goto LABEL_18;
        }
        sub_445350_DrawDialogueUI();
      }
    }
  }
  if ( sub_466CA0() == -1 )
    GameUI_DrawFoodAndGold();
  if ( sub_4637E0() )
    sub_416D62_ShowPopupWindow_MonsterRecord_ItemInfo_etc(0);
}


//----- (00411150) --------------------------------------------------------
char *__cdecl sub_411150()
{
  signed int v0; // edi@1
  __int16 v1; // dx@8
  int v2; // edi@17
  int v3; // edi@17
  __int16 v4; // dx@24

  GUIWindow local_0C;
  //int v6; // [sp+Ch] [bp-64h]@1
  //int v7; // [sp+10h] [bp-60h]@1
  //int v8; // [sp+14h] [bp-5Ch]@1
  //int v9; // [sp+18h] [bp-58h]@1
  //int v10; // [sp+1Ch] [bp-54h]@1
  //int v11; // [sp+20h] [bp-50h]@1

  char v12; // [sp+60h] [bp-10h]@17
  char v13; // [sp+68h] [bp-8h]@17

  Render_ClearZBuffer(pD3DRenderer, 0, 479);
  Render_DrawTransparentTexture(pD3DRenderer, 8, 8, uTextureID_lb_bordr__townport__sbquicknot);
  Render_DrawTransparentTexture(pD3DRenderer, 8, 8, &LODFile_Icons_LOD.aLODHeaders[uTextureID_right_backgr]);
  local_0C.uFrameX = 8;
  local_0C.uFrameY = 8;
  local_0C.uFrameWidth = 460;
  local_0C.uFrameHeight = 344;
  local_0C.uFrameZ = 467;
  local_0C.uFrameW = 351;
  v0 = 0;
  do
  {
    if ( !v0 )
    {
      v1 = 206;
LABEL_14:
      if ( !(unsigned __int16)sub_449B57((unsigned char *)pParty_global->unk_000764 + 1, v1) )
        goto LABEL_16;
      goto LABEL_15;
    }
    if ( v0 == 1 )
    {
      v1 = 208;
      goto LABEL_14;
    }
    if ( v0 == 2 )
    {
      v1 = 207;
      goto LABEL_14;
    }
    if ( v0 == 3 )
    {
      v1 = 211;
      goto LABEL_14;
    }
    if ( v0 == 4 )
    {
      v1 = 209;
      goto LABEL_14;
    }
    if ( v0 == 5 )
    {
      v1 = 210;
      goto LABEL_14;
    }
LABEL_15:
    Render_DrawTextureToZBuffer(pD3DRenderer, word_4E1D3C[v0], word_4E1D48[v0], pTexture_TownPortal_Icons[v0], v0 + 1);
LABEL_16:
    ++v0;
  }
  while ( v0 < 6 );
  v3 = (int)GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v13);
  v2 = *(_DWORD *)(pD3DRenderer->pActiveZBuffer
                 + 4 * (*(_DWORD *)v3 + dword_5059A8[*(_DWORD *)(GUICursor_GetMousePos(pGame->pGUICursor, (POINT *)&v12) + 4)])) & 0xFFFF;
  if ( !v2 )
    return GUIWindow_sub_44D406(&local_0C, pBook2Font, 0, 22, 0, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_TOWN_PORTAL], 3);
  if ( v2 == 1 )
  {
    v4 = 206;
LABEL_30:
    if ( (unsigned __int16)sub_449B57((unsigned char *)pParty_global->unk_000764 + 1, v4) )
      goto LABEL_31;
    return GUIWindow_sub_44D406(&local_0C, pBook2Font, 0, 22, 0, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_TOWN_PORTAL], 3);
  }
  if ( v2 == 2 )
  {
    v4 = 208;
    goto LABEL_30;
  }
  if ( v2 == 3 )
  {
    v4 = 207;
    goto LABEL_30;
  }
  if ( v2 == 4 )
  {
    v4 = 211;
    goto LABEL_30;
  }
  if ( v2 == 5 )
  {
    v4 = 209;
    goto LABEL_30;
  }
  if ( v2 == 6 )
  {
    v4 = 210;
    goto LABEL_30;
  }
LABEL_31:
  Render_DrawIndexedTexture(pD3DRenderer, word_4E1D3A[v2], word_4E1D46[v2], (cTexture *)*(&uTextureID_tab_an_6b__zoom_on + v2));
  return GUIWindow_sub_44D406(&local_0C, pBook2Font, 0, 22, 0, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_TOWN_PORTAL], 3);
}

//----- (00418083) ------.text:00418683  --------------------------------------------------
void __cdecl CharacterUI_StatsTab_ShowHint()
{
  int v0; // eax@1
  signed int v1; // ecx@1
  int v2; // edi@1
  int v3; // esi@1
  int v4; // edx@2
  int v5; // edx@4
  unsigned char *v6; // ecx@9
  unsigned char *v7; // ebx@9
  int v8; // ebx@15
  int v9; // edx@15
  char *v10; // ST2C_4@15
  signed int v11; // eax@15
  int v12; // ecx@17
  int v13; // eax@20
  int v14; // ebx@28
  Player *v15; // esi@28
  int v16; // eax@29
  int v17; // edx@29
  int v18; // eax@35
  //__int64 v20; // [sp+Ch] [bp-24h]@1
  signed __int64 v21; // [sp+14h] [bp-1Ch]@15
  const CHAR *v22; // [sp+1Ch] [bp-14h]@13
  Player *v23; // [sp+20h] [bp-10h]@13
  unsigned int v24; // [sp+24h] [bp-Ch]@15
  int v25; // [sp+28h] [bp-8h]@13
  unsigned char *v26; // [sp+2Ch] [bp-4h]@10
  POINT ptMouse;
  _QWORD v27;
  

  GUICursor_GetMousePos(pGame->pGUICursor, &ptMouse);

  for(v2=0; v2<28;v2++)					   
  {
    if ((ptMouse.x >= g_StatsHintCoords[v2].x)&&(ptMouse.x <= g_StatsHintCoords[v2].x + g_StatsHintCoords[v2].width)&&
        (ptMouse.y >= g_StatsHintCoords[v2].y)&&(ptMouse.y <= g_StatsHintCoords[v2].y + g_StatsHintCoords[v2].heght))
            break;
  }
  if (v2==28)  return;

  switch ( v2 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
	case 6:
		{
      v7 = pAttributeDescriptions[v2]; 
	  v26 = aAttributeNames[v2];
		break;
		}
    case 7:
		{
      v7 = pHealthPointsAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[108];
     break;
		}
    case 8:
		{
      v7 =  pSpellPointsAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[212];
      break;
		}
    case 9:
		{
      v7 =   pArmourClassAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[12];
     break;
		}
    case 10:
		{
      v26 = pGlobalTXT_LocalizationStrings[LOCSTR_CONDITION];

      strcpy((char *)pStringBuffer, (char *)pPlayerConditionAttributeDescription);
      v7 = pStringBuffer;
      v22 = (char *)pStringBuffer;
      strcat((char *)pStringBuffer, "\n");
      //v25 = dword_4EDEF8[0];
	  v25=0;
      //v0 = pPlayers[uActiveCharacter];
      v23 = pPlayers[uActiveCharacter];
      do
      {
        if ( v23->pConditions[dword_4EDEF8[v25]] )
        {
          strcat((char *)pStringBuffer, " \n");
          v8 =  dword_4EDEF8[v25];
         // v9 = (unsigned __int64)(pParty_global->qword_00002C -v23->pConditions[dword_4EDEF8[v25]]) >> 32;
          v27 = pParty_global->qword_00002C - v23->pConditions[dword_4EDEF8[v25]];
         
          v21 = (v27* 0.234375) / 60 / 60;
          v24 = (_DWORD)v21 / 24;
		  v21 %= 24i64;

          v10 = (char *)aCharacterConditionNames[v8];          
          v11 = sub_417939(v8);

          wsprintfA((char *)TmpBuf, "\f%06x%s\f000000 - ", v11, v10);
          strcat((char *)pStringBuffer, (char *)TmpBuf);

          if ( LODWORD(v21) && LODWORD(v21) <= 1 )
            v12 = (int)pGlobalTXT_LocalizationStrings[LOCSTR_HOUR];
          else
            v12 = (int)pGlobalTXT_LocalizationStrings[LOCSTR_HOURS];
          if ( !v24 || (v24 > 1) )
			  v13 = (int)pGlobalTXT_LocalizationStrings[LOCSTR_DAY];
		  else
            v13 = (int)pGlobalTXT_LocalizationStrings[LOCSTR_DAYS];
          wsprintfA((char *)TmpBuf, "%lu %s, %lu %s", v24, v13, LODWORD(v21), v12);
          strcat((char *)pStringBuffer, (char *)TmpBuf);
         // v7 = v22;
         // v0 = v23;
        }
        ++v25;
      }
      while ( v25 < 18 );
      break;
		}
    case 11:
		{
      v7 =  pFastSpellAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[172];
     break;
		}
    case 12:
		{
      v7 =  pPlayerAgeAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[5];
      break;
		}
    case 13:
		{
      v7 =  pPlayerLevelAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[131];
     break;
		}
    case 14:
		{
         v15 = pPlayers[uActiveCharacter];
         v26 = pGlobalTXT_LocalizationStrings[LOCSTR_EXPIRIENCE];
         v14 = v15->uLevelBase;
      do
      {
        v16 = sub_4B46F8(v14);
        v17 =HIDWORD(v15->uExperience);
        if ( v17 < 0 )
          break;
        if ( v17 <= 0 && LODWORD(v15->uExperience) < (unsigned int)v16 )
          break;
        ++v14;
      }
      while ( v14 <= 10000 );
      TmpBuf[0] = 0;
      pStringBuffer[0] = 0;
      if ( v14 > v15->uLevelBase )
        wsprintfA((char *)TmpBuf, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_YOU_TO_TRAIN], v14);
      v18 = sub_4B46F8(v14);
      wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_NEED_MORE_EXP], v18 -LODWORD(v15->uExperience) , v14 + 1);
      strcat((char *)TmpBuf, "\n");
      strcat((char *)TmpBuf, (char *)pStringBuffer);
      wsprintfA((char *)pStringBuffer, "%s\n \n%s", pPlayerExperienceAttributeDescription, (char *)TmpBuf);
      v7 = pStringBuffer;
     break;
		}
    case 15:
		{
      v7 =  pAttackBonusAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[587];
      break;
		}
    case 16:
		{
      v7 =  pAttackDamageAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[588];
     break;
		}
    case 17:
		{
      v7 =  pMissleBonusAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[589];
     break;
		}
    case 18:
		{
      v7 =  pMissleDamageAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[590];
       break;
		}
    case 19:
		{
      v7 =  pFireResistanceAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[87];
      break;
		}
    case 20:
		{
      v7 =  pAirResistanceAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[6];
      break;
		}
    case 21:
		{
      v7 =  pWaterResistanceAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[240];
     break;
		}
    case 22:
		{
      v7 =  pEarthResistanceAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[70];
      break;
		}
    case 23:
		{
      v7 =  pMindResistanceAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[142];
     break;
		}
    case 24:
		{
      v7 =  pBodyResistanceAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[29];
     break;
		}
    case 25:
		{
      v7 =  pSkillPointsAttributeDescription;
      v26 = pGlobalTXT_LocalizationStrings[207];
      break;
		}
    case 26:
		{
      v0 =pPlayers[uActiveCharacter]->uClass;
      v26 = aClassNames[v0];
      v7 = pClassDescriptions[v0];    
      break;
		}
    default:

      return;
  }
   if ( v26 && v7)
        sub_4179BC(v26, (const char *)v7);
}

//----- (00495B39) --------------------------------------------------------
void PlayerCreationUI_Draw()
{
  struct IconFrame *v1;
  const char *v2; // ST10_4@3
  int v3; // eax@3
  signed int v4; // ecx@7
  struct GUIButton *v5;
  char v6; // sf@12
  unsigned int v7; // eax@14
  int v8; // esi@14
  char v9; // al@17
  int v10; // ecx@17
  char v11; // sf@17
  int v12; // ecx@19
  int v13; // eax@20
  int v14; // ecx@21
  int v15; // ecx@22
  char *v16; // ST14_4@24
  size_t v17; // eax@28
  int v18; // eax@33
  signed int v19; // eax@35
  int v20; // eax@36
  int v21; // eax@37
  __int16 v22; // ax@44
  __int16 v23; // ST0C_2@44
  int v24; // eax@44
  int v25; // eax@44
  int v27; // eax@44 
  int v29; // eax@44
  int v31; // eax@44
  int v33; // eax@44
  int v35; // eax@44
  int v37; // eax@44
  signed int v39; // eax@44
  int v40; // eax@44
  signed int v41; // eax@44
  int v42; // eax@44
  signed int v43; // eax@44
  int v46; // eax@44
  __int16 v47; // ax@46
  signed int v48; // eax@46
  int v51; // eax@46
  unsigned int v52; // eax@49
  char *v53; // edi@52
  char v54; // al@52
  char v55; // sf@52
  int v57; // edi@53
  __int16 v58; // ST0C_2@53
  int v59; // eax@53
  int v63; // eax@55
  int v67; // ST08_4@57
  int v68; // eax@57
  int v72; // ST08_4@59
  int v73; // eax@59
  int v77; // eax@61
  int v81; // ST08_4@63
  int v82; // eax@63
  int v86; // ST08_4@65
  int v87; // eax@65
  int v91; // eax@67
  int v95; // ST08_4@69
  int v96; // eax@69
  int v99; // ST08_4@71
  int v100; // eax@71
  int v103; // eax@71
  size_t v104; // eax@72
  signed int v105; // ecx@72
  signed int v106; // edi@72
  int v108; // edi@81
  __int16 v109; // ST0C_2@81
  int v110; // ST08_4@81
  int v111; // eax@81
  int v115; // eax@82
  int v117; // eax@82
  int v119; // [sp+0h] [bp-170h]@39
  unsigned char Str1[200]; // [sp+10h] [bp-160h]@14

  GUIWindow v121; // [sp+D8h] [bp-98h]@85 x
  //int v122; // [sp+DCh] [bp-94h]@85	   y
  //int v123; // [sp+E0h] [bp-90h]@85	  wd
  //int v124; // [sp+E4h] [bp-8Ch]@85	  ht
  //int v125; // [sp+E8h] [bp-88h]@85	  z
  //int v126; // [sp+ECh] [bp-84h]@85	  w
  //int v127; // [sp+120h] [bp-50h]@83   string

  int v128; // [sp+12Ch] [bp-44h]@18
  size_t v129; // [sp+130h] [bp-40h]@25
  int v130; // [sp+134h] [bp-3Ch]@18
  int v131; // [sp+138h] [bp-38h]@18
  int v132; // [sp+13Ch] [bp-34h]@11
  int v133; // [sp+140h] [bp-30h]@18
  int v135; // [sp+148h] [bp-28h]@25
  int v136; // [sp+14Ch] [bp-24h]@1
  int v137; // [sp+150h] [bp-20h]@14
  int v138; // [sp+154h] [bp-1Ch]@18
  int v141; // [sp+160h] [bp-10h]@18
  int v142;
  int v143; // [sp+168h] [bp-8h]@14
  unsigned char *Str;
 int i;
 unsigned int uColor;

  pD3DRenderer->BeginScene();
  {
#ifndef OLD_CODE
   Render_DrawRGBTexture_New(pD3DRenderer, 0, 0, uTextureID_CurrentMenu);
#endif
#ifdef OLD_CODE
   Render_DrawRGBTexture(pD3DRenderer, 0, 0,&cPCXID_CurrentMenu);
#endif
   Render_DrawIndexedTexture(pD3DRenderer, dword_A74CCC, 2, pPlayerCreationUI_Sky);
   Render_DrawIndexedTexture(pD3DRenderer, dword_A74CCC - 640, 2, pPlayerCreationUI_Sky);

   dword_A74CCC = (GetTickCount() / 20) % 640;

   Render_DrawTransparentTexture(pD3DRenderer, 0, 0, pPlayerCreationUI_Top);

   uPlayerCreationUI_SelectedCharacter = (pGUIWindow_CurrentMenu->dword_00002C - pGUIWindow_CurrentMenu->dword_000038) / 7;

   v3 = AlignText_Center(640, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_CREATE_PARTY], pFontCChar);
   FontDrawText(pGUIWindow_CurrentMenu, pFontCChar, v3 + 1, 3, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_CREATE_PARTY], 0xFFFFFF, 0, 0);
   Render_DrawTransparentTexture(pD3DRenderer,  17, 35, pTextureID_PCFaces[pParty_global->pPlayers[0].uFace]);
   Render_DrawTransparentTexture(pD3DRenderer, 176, 35, pTextureID_PCFaces[pParty_global->pPlayers[1].uFace]);
   Render_DrawTransparentTexture(pD3DRenderer, 335, 35, pTextureID_PCFaces[pParty_global->pPlayers[2].uFace]);
   Render_DrawTransparentTexture(pD3DRenderer, 494, 35, pTextureID_PCFaces[pParty_global->pPlayers[3].uFace]);

   v1 = pIconFrameTable->GetImage(uIconTableFrameID_CharacterFrame, cClock1.int_00000C);

   switch (uPlayerCreationUI_SelectedCharacter)
   {
      case 0:
        v4 = 12;
        break;
      case 1:
        v4 = 171;
        break;
      case 2:
        v4 = 329;
        break;
      case 3:
        v4 = 488;
        break;
      default:
        v4 = v132; 
        break;
   }
   Render_DrawTransparentTexture(pD3DRenderer, v4, 29, &LODFile_Icons_LOD.aLODHeaders[v1->uTextureIdx]);


   v5 = GUIWindow_GetChild(pGUIWindow_CurrentMenu, pGUIWindow_CurrentMenu->dword_00002C);
#ifndef	OLD_CODE
   Render_DrawTransparentRect(pD3DRenderer, v5->uZ - 4, v5->uY, 20 * dword_A74CD4, 0, 20, 16, &LODFile_Icons_LOD.aLODHeaders[uTextureID_PartyCreationUI_Arrows]);
   Render_DrawTransparentRect(pD3DRenderer, v5->uX - 12, v5->uY, 20 * dword_A74CD4, 16, 20, 16, &LODFile_Icons_LOD.aLODHeaders[uTextureID_PartyCreationUI_Arrows]);
#endif
#ifdef	OLD_CODE

   Render_DrawTransparentTexture(pD3DRenderer, v5->uZ - 4, v5->uY,pPlayerCreationUI_ArrowL[dword_A74CD4] );
   Render_DrawTransparentTexture(pD3DRenderer, v5->uX - 12, v5->uY,pPlayerCreationUI_ArrowR[dword_A74CD4]);
#endif

   dword_A74CD4 = (GetTickCount() / 25) % 18;



   v8 = pFontCreate->uFontHeight - 2;
   v137 = pFontCreate->uFontHeight - 2;
   strcpy((char *)Str1, (char *)pGlobalTXT_LocalizationStrings[205]);
   v7 = strlen((char *)Str1) - 1;
   v143 = v7;
   if ( (signed int)v7 >= 0 )
   {
     while ( 1 )
     {
       v9 = toupper((unsigned __int8)Str1[v7]);
       v10 = v143;
       v11 = v143-- - 1 < 0;
       Str1[v10] = v9;
       if ( v11 )
         break;
       v7 = v143;
     }
   }

   v143 = 18;
   v133 = 0;
   v141 = 32;
   v130 = 3 * v8 + 169;
   v131 = 5 * v8 + 169;
   v132 = 3 * v8 + 311;
   v138 = 493;
   v128 = 6 * v8 + 169;

  i = 0;
  do
  {
  
   FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v143 + 73, 100, (char *)aClassNames[pParty_global->pPlayers[i].uClass], 0xFFFFFF, 0, 0);
#ifndef OLD_CODE 
    unsigned int uClassIconCellX,
                uClassIconCellY;
   uClassIconCellX = (pParty_global->pPlayers[i].uClass / 4) % 3;
   uClassIconCellY = (pParty_global->pPlayers[i].uClass / 4) / 3;
   Render_DrawTransparentRect(pD3DRenderer, v143 + 77, 50,
                                    uClassIconCellX * 48, uClassIconCellY * 52, 48, 52, &LODFile_Icons_LOD.aLODHeaders[uTextureID_PartyCreationUI_ClassIcons]);
#endif
#ifdef OLD_CODE
   Render_DrawTransparentTexture(pD3DRenderer, v143 + 77, 50,  pPlayerCreatUI_ClIcons[pParty_global->pPlayers[i].uClass/4]);
#endif

   v12 = pGUIWindow_CurrentMenu->dword_000040;
   v13 = pGUIWindow_CurrentMenu->dword_00001C;
    if ( v12 && v13 == 0)
    {
     Str = (unsigned char *)&pParty_global->pPlayers[i] + 0xA8;
      v14 = v12 - 1;
      if ( v14 )
      {
        v15 = v14 - 1;
        if ( v15 )
        {
          if ( v15 == 1 )
          {
            v16 = (char *)Str;
            pGUIWindow_CurrentMenu->dword_000040 = 0;
            GUIWindow_sub_44CB4F(pGUIWindow_CurrentMenu, pFontCreate, v143, 124, 0, v16, 130, 0);
            SetCurrentMenu(7);
          }
        }
        else
        {
          pGUIWindow_CurrentMenu->dword_000040 = 0;
          v129 = strlen((char *)pKeyboardController->pPressedKeysBuffer);
          v135 = 0;
          v142 = 0;
          if ( strlen((char *)pKeyboardController->pPressedKeysBuffer) )
          {
            do
            {
              if (pKeyboardController->pPressedKeysBuffer[v142] == 32 )
                ++v135;
              ++v142;
              v17 = strlen((char *)pKeyboardController->pPressedKeysBuffer);
            }
            while ( v142 < v17 );
          }
          if ( v129 )
          {
            if ( v135 != v129 )
              strcpy((char *)Str, (char *)pKeyboardController->pPressedKeysBuffer);
          }
          GUIWindow_sub_44CB4F(pGUIWindow_CurrentMenu, pFontCreate, v143, 124, 0, (char *)Str, 130, 0);
          *((_WORD *)Str + 3323) = 1;
        }
      }
      else
      {
        v18 = GUIWindow_sub_44CB4F(pGUIWindow_CurrentMenu, pFontCreate, 159 * v13 + 18, 124, 0, (char *)pKeyboardController->pPressedKeysBuffer, 120, 1);
        GUIWindow_sub_459C2B(pGUIWindow_CurrentMenu, 159 * *(_DWORD *)(pGUIWindow_CurrentMenu + 28) + v18 + 20, 124, (int)pFontCreate);
      }
    }
    else
    {
      FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v143, 124, (char *)pParty_global->pPlayers[i].sName, 0xFFFFFFFF, 0, 0);
    }

    

    v19 = Player_GetRace(&pParty_global->pPlayers[i]);
    switch (v19)
    {
     case 0:  v119 = (int)pGlobalTXT_LocalizationStrings[99];   break;
     case 1:  v119 = (int)pGlobalTXT_LocalizationStrings[103];  break;
     case 2:  v119 = (int)pGlobalTXT_LocalizationStrings[106];  break;
     case 3:  v119 = (int)pGlobalTXT_LocalizationStrings[101];  break;
     default: v119 = (int)"";
    };
    strcpy((char *)TmpBuf, (char *)v119);

    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v143 + 72, v137 + 12, (char *)TmpBuf, 0xFFFFFFFF, 0, 0);
    v23 = 0xD1BB61;
    v24 = AlignText_Center(150, (char *)Str1, pFontCreate);
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v24 + v141 - 24, 291, (char *)Str1, 0xFFD1BB61, 0, 0);


    v25 = Player_GetActualStrength(&pParty_global->pPlayers[i]);
    if (pParty_global->pPlayers[i].uStrength < 10)
      wsprintfA((char *)TmpBuf, "%s\t099%d", pGlobalTXT_LocalizationStrings[144], pParty_global->pPlayers[i].uStrength);
    else 
	  wsprintfA((char *)TmpBuf, "%s\t092%d", pGlobalTXT_LocalizationStrings[144], pParty_global->pPlayers[i].uStrength);
    uColor = PlayerCreationUI_GetStatColor(&pParty_global->pPlayers[i], 0);
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v141, 169, (char *)TmpBuf, uColor, 0, 0);

    v27 = Player_GetActualIntelligence(&pParty_global->pPlayers[i]);
    if (pParty_global->pPlayers[i].uIntelligence < 10)
      wsprintfA((char *)TmpBuf, "%s\t099%d", pGlobalTXT_LocalizationStrings[116], pParty_global->pPlayers[i].uIntelligence);
    else 
	  wsprintfA((char *)TmpBuf, "%s\t092%d", pGlobalTXT_LocalizationStrings[116], pParty_global->pPlayers[i].uIntelligence);
    uColor = PlayerCreationUI_GetStatColor(&pParty_global->pPlayers[i], 1);
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v141, v137 + 169, (char *)TmpBuf, uColor, 0, 0);

    v29 = Player_GetActualWillpower(&pParty_global->pPlayers[i]);
    if (pParty_global->pPlayers[i].uWillpower < 10)
      wsprintfA((char *)TmpBuf, "%s\t099%d", pGlobalTXT_LocalizationStrings[163], pParty_global->pPlayers[i].uWillpower);
    else 
	  wsprintfA((char *)TmpBuf, "%s\t092%d", pGlobalTXT_LocalizationStrings[163], pParty_global->pPlayers[i].uWillpower);
    uColor = PlayerCreationUI_GetStatColor(&pParty_global->pPlayers[i], 2);
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v141, 2 * v137 + 169, (char *)TmpBuf, uColor, 0, 0);

    v31 = Player_GetActualEndurance(&pParty_global->pPlayers[i]);
    if (pParty_global->pPlayers[i].uEndurance < 10)
      wsprintfA((char *)TmpBuf, "%s\t099%d", pGlobalTXT_LocalizationStrings[75], pParty_global->pPlayers[i].uEndurance);
    else 
	  wsprintfA((char *)TmpBuf, "%s\t092%d", pGlobalTXT_LocalizationStrings[75], pParty_global->pPlayers[i].uEndurance);
    uColor = PlayerCreationUI_GetStatColor(&pParty_global->pPlayers[i], 3);
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v141, v130, (char *)TmpBuf, uColor, 0, 0);

    v33 = Player_GetActualAccuracy(&pParty_global->pPlayers[i]);
    if (pParty_global->pPlayers[i].uAccuracy < 10)
      wsprintfA((char *)TmpBuf, "%s\t099%d", pGlobalTXT_LocalizationStrings[LOCSTR_ACCURACY], pParty_global->pPlayers[i].uAccuracy);
    else 
	  wsprintfA((char *)TmpBuf, "%s\t092%d", pGlobalTXT_LocalizationStrings[LOCSTR_ACCURACY], pParty_global->pPlayers[i].uAccuracy);
    uColor = PlayerCreationUI_GetStatColor(&pParty_global->pPlayers[i], 4);
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v141, 4 * v137 + 169, (char *)TmpBuf, uColor, 0, 0);

    v35 = Player_GetActualSpeed(&pParty_global->pPlayers[i]);
    if (pParty_global->pPlayers[i].uSpeed < 10)
      wsprintfA((char *)TmpBuf, "%s\t099%d", pGlobalTXT_LocalizationStrings[211], pParty_global->pPlayers[i].uSpeed);
    else 
	  wsprintfA((char *)TmpBuf, "%s\t092%d", pGlobalTXT_LocalizationStrings[211], pParty_global->pPlayers[i].uSpeed);
    uColor = PlayerCreationUI_GetStatColor(&pParty_global->pPlayers[i], 5);
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v141, v131, (char *)TmpBuf, uColor, 0, 0);

    v37 = Player_GetActualLuck(&pParty_global->pPlayers[i]);
    if (pParty_global->pPlayers[i].uLuck < 10)
      wsprintfA((char *)TmpBuf, "%s\t099%d", pGlobalTXT_LocalizationStrings[136], pParty_global->pPlayers[i].uLuck);
    else 
	  wsprintfA((char *)TmpBuf, "%s\t092%d", pGlobalTXT_LocalizationStrings[136], pParty_global->pPlayers[i].uLuck);
    uColor = PlayerCreationUI_GetStatColor(&pParty_global->pPlayers[i], 6);
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v141, v128, (char *)TmpBuf, uColor, 0, 0);



    v39 = GetSkillIdxByOrder(&pParty_global->pPlayers[i], 0);
    v40 = AlignText_Center(150, (char *)aSkillNames[v39], pFontCreate);
    wsprintfA((char *)TmpBuf, "\t%03u%s", v40, aSkillNames[v39]);
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v141 - 24, 311, (char *)TmpBuf, 0xFFFFFF, 0, 0);

    v41 = GetSkillIdxByOrder(&pParty_global->pPlayers[i], 1);
    v42 = AlignText_Center(150, (char *)aSkillNames[v41], pFontCreate);
    wsprintfA((char *)TmpBuf, "\t%03u%s", v42, aSkillNames[v41]);
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v141 - 24, v137 + 311, (char *)TmpBuf, 0xFFFFFF, 0, 0);

    v43 = GetSkillIdxByOrder(&pParty_global->pPlayers[i], 2);
    v46 = AlignText_Center(150, (char *)aSkillNames[v43], pFontCreate);
    wsprintfA((char *)TmpBuf, "\t%03u%s", v46, aSkillNames[v43]);
    uColor = 0x00FF00;
    if (v43 >= 37)
      uColor = 0x00FFFF;
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v141 - 24, 2 * v137 + 311, (char *)TmpBuf, uColor, 0, 0);

    v48 = GetSkillIdxByOrder(&pParty_global->pPlayers[i], 3);
    v51 = AlignText_Center(150, (char *)aSkillNames[v48], pFontCreate);
    wsprintfA((char *)TmpBuf, "\t%03u%s", v51, aSkillNames[v48]);
    uColor = 0x00FF00;
    if (v48 >= 37)
      uColor = 0x00FFFF;
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v141 - 24, v132, (char *)TmpBuf, uColor, 0, 0);


    ++v133;
    v143 += 159;
    v138 -= 158;
    v141 += 158;
  }
  while (++i < 4);
  }



  strcpy((char *)Str1, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_CLASS]);
  v52 = strlen((char *)Str1) - 1;
  v143 = v52;
  if ( (signed int)v52 >= 0 )
  {
    while ( 1 )
    {
      v53 = (char *)&Str1[v52];
      v54 = toupper((unsigned __int8)Str1[v52]);
      v55 = v143-- - 1 < 0;
      *v53 = v54;
      if ( v55 )
        break;
      v52 = v143;
    }
  }

  v58 = 0xD1BB61;
  v59 = AlignText_Center(193, (char *)Str1, pFontCreate);
  FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v59 + 324, 395, (char *)Str1, 0xFFD1BB61, 0, 0);


  v57 = pParty_global->pPlayers[uPlayerCreationUI_SelectedCharacter].uClass;
  v142 = pParty_global->pPlayers[uPlayerCreationUI_SelectedCharacter].uClass;

  uColor = 0xFFFFFF;
  if (v57 == 0)
    uColor = 0x00FFFF;
  v63 = AlignText_Center(65, (char *)aClassNames[0], pFontCreate);
  FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v63 + 323, 417, (char *)aClassNames[0], uColor, 0, 0);

  uColor = 0xFFFFFF;
  if (v57 == 12)
    uColor = 0x00FFFF;
  v67 = v137 + 417;
  v136 = v137 + 417;
  v68 = AlignText_Center(65, (char *)aClassNames[12], pFontCreate);
  FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v68 + 323, v67, (char *)aClassNames[12], uColor, 0, 0);

  uColor = 0xFFFFFF;
  if (v57 == 20)
    uColor = 0x00FFFF;
  v72 = 2 * v137 + 417;
  v135 = 2 * v137 + 417;
  v73 = AlignText_Center(65, (char *)aClassNames[20], pFontCreate);
  FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v73 + 323, v72, (char *)aClassNames[20], uColor, 0, 0);

  uColor = 0xFFFFFF;
  if (v57 == 24)
    uColor = 0x00FFFF;
  v77 = AlignText_Center(65, (char *)aClassNames[24], pFontCreate);
  FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v77 + 388, 417, (char *)aClassNames[24], uColor, 0, 0);

  uColor = 0xFFFFFF;
  if (v57 == 28)
    uColor = 0x00FFFF;
  v81 = v136;
  v82 = AlignText_Center(65, (char *)aClassNames[28], pFontCreate);
  FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v82 + 388, v81, (char *)aClassNames[28], uColor, 0, 0);

  uColor = 0xFFFFFF;
  if (v57 == 32)
    uColor = 0x00FFFF;
  v86 = v135;
  v87 = AlignText_Center(65, (char *)aClassNames[32], pFontCreate);
  FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v87 + 388, v86, (char *)aClassNames[32], uColor, 0, 0);

  uColor = 0xFFFFFF;
  if (v57 == 16)
    uColor = 0x00FFFF;
  v91 = AlignText_Center(65, (char *)aClassNames[16], pFontCreate);
  FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v91 + 453, 417, (char *)aClassNames[16], uColor, 0, 0);

  uColor = 0xFFFFFF;
  if (v57 == 8)
    uColor = 0x00FFFF;
  v95 = v136;
  v96 = AlignText_Center(65, (char *)aClassNames[8], pFontCreate);
  FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v96 + 453, v95, (char *)aClassNames[8], uColor, 0, 0);

  uColor = 0xFFFFFF;
  if (v57 == 4)
    uColor = 0x00FFFF;
  v99 = v135;
  v100 = AlignText_Center(65, (char *)aClassNames[4], pFontCreate);
  FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v100 + 453, v99, (char *)aClassNames[4], uColor, 0, 0);

  v103 = AlignText_Center(236, (char *)pGlobalTXT_LocalizationStrings[20], pFontCreate);
  FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v103 + 37, 395, (char *)pGlobalTXT_LocalizationStrings[20], 0xFFD1BB61, 0, 0);

  for(v143 = 0; v143 < 9; ++v143)
  {
    v106 = GetSkillIdxByOrder(&pParty_global->pPlayers[uPlayerCreationUI_SelectedCharacter], v143 + 4);
    strcpy((char *)Str1, (char *)aSkillNames[v106]);
    v104 = strlen((char *)Str1);
    v105 = 0;
    if ( (signed int)v104 > 0 )
    {
      while ( Str1[v105] != 32 )
      {
        ++v105;
        if ( v105 >= (signed int)v104 )
          goto LABEL_77;
      }
      Str1[v105] = 0;
    }
LABEL_77:
    v136 = -5;
    if ( v133 <= 3 )
      v136 = 0;
    uColor = 0x00F7F7;
    if (!pParty_global->pPlayers[uPlayerCreationUI_SelectedCharacter].pActiveSkills[v106])
      uColor = 0xFFFFFF;
    v108 = v143 / 3;
    v110 = v137 * (v143 % 3) + 417;
    v111 = AlignText_Center(100, (char *)Str1, pFontCreate);
    FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, 100 * v108 + v111 + v136 + 17, v110, (char *)Str1, uColor, 0, 0);
  }

  v115 = AlignText_Center(92, (char *)pGlobalTXT_LocalizationStrings[30], pFontCreate);
  FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v115 + 533, 394, (char *)pGlobalTXT_LocalizationStrings[30], 0xD1BB61, 0, 0);

  wsprintfA((char *)TmpBuf, "%d", PlayerCreation_ComputeAttributeBonus());
  if (PlayerCreation_ComputeAttributeBonus() > 0)
    uColor = 0x00FF00;
  else 
	  uColor = 0xFFFFFF;
  v117 = AlignText_Center(90, (char *)TmpBuf, pFontCreate);
  FontDrawText(pGUIWindow_CurrentMenu, pFontCreate, v117 + 530, 410, (char *)TmpBuf, uColor, 0, 0);

  if ( dword_5C35B8_Some_GetTickCount_timer > GetTickCount() )
  {
    v121.ptr_000048 = pGlobalTXT_LocalizationStrings[412];
    if ( PlayerCreation_ComputeAttributeBonus() < 0 )
      v121.ptr_000048 = pGlobalTXT_LocalizationStrings[413];
    v121.uFrameWidth = 300;
    v121.uFrameHeight = 100;
    v121.uFrameX = 170;
    v121.uFrameY = 140;
    v121.uFrameZ = 469;
    v121.uFrameW = 239;
    GUIWindow_sub_415551(&v121, 0);
  }
  pD3DRenderer->EndScene();
}



//----- (0049048D) --------------------------------------------------------
__int16 __thiscall PartyCreation_BtnMinusClick(struct Player *_this, int a2)
{
  int v2;
  int v4; // ecx@1
  int r1; // ebx@1
  int r2; // esi@1
  int v7; // edi@8
  int v8; // edi@12
  int v9; // edi@16
  int v10; // edi@20
  int v11; // edi@24
  int v12; // edi@28
  int v13; // edi@32
  int v15; // [sp+Ch] [bp-4h]@1
  int r;

  r = Player_GetRace(_this);
  v4 = g_StatTable[r][a2].InitialStat; 
  r1 = g_StatTable[r][a2].Ratio1;
  v15 = v4 - 2;
  r2 = g_StatTable[r][a2].Ratio2;
  HIWORD(v2) = HIWORD(a2);
  if ( a2 )
  {
    v2 = a2 - 1;
    if ( a2 == 1 )
    {
      LOWORD(v2) = _this->uIntelligence;
      v12 = _this->uIntelligence;
      if ( v12 <= v4 )
        r2 = r1;
      if ( v12 - r2 >= v15 )
      {
        v2 -= r2;
        _this->uIntelligence = v2;
      }
    }
    else
    {
      v2 = a2 - 2;
      if ( a2 == 2 )
      {
        LOWORD(v2) = _this->uWillpower;
        v11 = _this->uWillpower;
        if ( v11 <= v4 )
          r2 = r1;
        if ( v11 - r2 >= v15 )
        {
          v2 -= r2;
          _this->uWillpower = v2;
        }
      }
      else
      {
        v2 = a2 - 3;
        if ( a2 == 3 )
        {
          LOWORD(v2) = _this->uEndurance;
          v10 = _this->uEndurance;
          if ( v10 <= v4 )
            r2 = r1;
          if ( v10 - r2 >= v15 )
          {
            v2 -= r2;
            _this->uEndurance = v2;
          }
        }
        else
        {
          v2 = a2 - 4;
          if ( a2 == 4 )
          {
            LOWORD(v2) = _this->uAccuracy;
            v9 = _this->uAccuracy;
            if ( v9 <= v4 )
              r2 = r1;
            if ( v9 - r2 >= v15 )
            {
              v2 -= r2;
              _this->uAccuracy = v2;
            }
          }
          else
          {
            v2 = a2 - 5;
            if ( a2 == 5 )
            {
              LOWORD(v2) = _this->uSpeed;
              v8 = _this->uSpeed;
              if ( v8 <= v4 )
                r2 = r1;
              if ( v8 - r2 >= v15 )
              {
                v2 -= r2;
                _this->uSpeed = v2;
              }
            }
            else
            {
              v2 = a2 - 6;
              if ( a2 == 6 )
              {
                LOWORD(v2) = _this->uLuck;
                v7 = _this->uLuck;
                if ( v7 <= v4 )
                  r2 = r1;
                if ( v7 - r2 >= v15 )
                {
                  v2 -= r2;
                  _this->uLuck = v2;
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
    LOWORD(v2) = _this->uStrength;
    v13 = _this->uStrength;
    if ( v13 <= v4 )
      r2 = r1;
    if ( v13 - r2 >= v15 )
    {
      v2 -= r2;
      _this->uStrength = v2;
    }
  }
  return v2;
}



//----- (004905F5) --------------------------------------------------------
signed int __thiscall PartyCreation_BtnPlusClick(struct Player *_this, int a2)
{
  int v2; // ebx@1
  signed int v3; // edi@1
  int v4; // esi@1
  int v6; // eax@8
  signed int v7; // eax@17
  signed int result; // eax@18
  int v9; // [sp+Ch] [bp-8h]@1
  signed int v10; // [sp+10h] [bp-4h]@1
  int r;

  v4 = (int)_this;
  
  r = Player_GetRace(_this);
  v2 = g_StatTable[r][a2].MaxStat;
  v3 = g_StatTable[r][a2].Ratio2;
  v9 = g_StatTable[r][a2].InitialStat; 
  v10 = g_StatTable[r][a2].Ratio1;
  PlayerCreation_ComputeAttributeBonus();
  switch ( a2 )
  {
      case 0:
        v6 = _this->uStrength;
        break;
      case 1:
        v6 = _this->uIntelligence;
        break;
      case 2:
        v6 = _this->uWillpower;
        break;
      case 3:
        v6 = _this->uEndurance;
        break;
      case 4:
        v6 = _this->uAccuracy;
        break;
      case 5:
        v6 = _this->uSpeed;
        break;
      case 6:
        v6 = _this->uLuck;
        break;
      default:
        v6 = a2;
        break;
  }
  if ( v6 < v9 )
  {
    v7 = v3;
    v3 = v10;
    v10 = v7;
  }
  result = PlayerCreation_ComputeAttributeBonus();
  if ( result >= v10 )
  {
    if ( a2 )
    {
      switch ( a2 )
      {
        case 1:
          result = v4 + 192;
          break;
        case 2:
          result = v4 + 196;
          break;
        case 3:
          result = v4 + 200;
          break;
        case 4:
          result = v4 + 208;
          break;
        case 5:
          result = v4 + 204;
          break;
        default:
          result = a2 - 6;
          if ( a2 != 6 )
            return result;
          result = v4 + 212;
          break;
      }
    }
    else
    {
      result = v4 + 188;
    }
    if ( v3 + *(_WORD *)result <= v2 )
      *(_WORD *)result += v3;
  }
  return result;
}

//----- (004907E7) --------------------------------------------------------
unsigned int PlayerCreationUI_GetStatColor(struct Player *_this, int Stat)
{
  int v7; // eax@1
  int v8; // edx@1

 switch (Stat)
 {
  case 0:  v8 = _this->uStrength;     break;
  case 1:  v8 = _this->uIntelligence; break;
  case 2:  v8 = _this->uWillpower;    break;
  case 3:  v8 = _this->uEndurance;    break;
  case 4:  v8 = _this->uAccuracy;     break;
  case 5:  v8 = _this->uSpeed;        break;
  case 6:  v8 = _this->uLuck;         break;
  default: v8 = Stat;                 break;
 }

 v7 = g_StatTable[Player_GetRace(_this)][Stat].InitialStat;

 if (v8 == v7)
   return 0xFFFFFFFF;
 else if (v8 > v7)
   return 0xFF00FF00;
 else
   return 0xFFFF2300;
}

#ifndef OLD_CODE
//----- (004226EF) --------------------------------------------------------
void MenuUI_LoadTextures(unsigned int uAlignment)
{
 unsigned int uTextureIdx_Endcap;

 const wchar_t *pGoodInterface[] =
 {
  L"ib-RPl-A", L"ib-PFr-A", L"ib-ET-A", L"ib-EL-A", L"ib-StatBar-A",
  L"ib-bcu-A",
  L"WE-t-A", L"WE-bot-A", L"WE-l-A", L"WE-r-A",
  L"C_UL-A", L"C_UR-A", L"C_LL-A", L"C_LR-A",
  L"Parchment",
  L"fr_inven-A",
  L"NPCSlot-A",
  L"iSg-04-A", L"iSg-03-A", L"iSg-02-A", L"iSg-01-A",
  L"ib-m4d-A", L"ib-m3d-A", L"ib-m2d-A", L"ib-m1d-A",
  L"ib-MZIn-A", L"ib-MZOu-A",
  L"ib-NPCSL0-A", L"ib-NPCSL1-A", L"ib-NPCSR0-A", L"ib-NPCSR1-A",
  L"ib-Cmps-A",
  L"ib-InitG-A", L"ib-InitY-A", L"ib-InitR-A",
  L"ib-MMask-A",
  L"ib-mb-A",
  L"ib-Selec-A",
  L"WizEyeA", L"TorchA",
  L"endcap-A",
 },
               *pNeutralInterface[] =
 {
  L"ib-RPl-B", L"ib-PFr-B", L"ib-ET-B", L"ib-EL-B", L"ib-StatBar-B",
  L"ib-bcu-B",
  L"WE-t-B", L"WE-bot-B", L"WE-l-B", L"WE-r-B",
  L"C_UL-B", L"C_UR-B", L"C_LL-B", L"C_LR-B",
  L"Parchment",
  L"fr_inven-B",
  L"NPCSlot-B",
  L"iSg-04-B", L"iSg-03-B", L"iSg-02-B", L"iSg-01-B",
  L"ib-m4d-B", L"ib-m3d-B", L"ib-m2d-B", L"ib-m1d-B",
  L"ib-MZIn-B", L"ib-MZOu-B",
  L"ib-NPCSL0-B", L"ib-NPCSL1-B", L"ib-NPCSR0-B", L"ib-NPCSR1-B",
  L"ib-Cmps-B",
  L"ib-InitG-B", L"ib-InitY-B", L"ib-InitR-B",
  L"ib-MMask-B",
  L"ib-mb-B",
  L"ib-Selec-B",
  L"WizEyeB", L"TorchB",
  L"endcap-B",
 },
               *pEvilInterface[] =
 {
  L"ib-RPl-C", L"ib-PFr-C", L"ib-ET-C", L"ib-EL-C", L"ib-StatBar-C",
  L"ib-bcu-C",
  L"WE-t-C", L"WE-bot-C", L"WE-l-C", L"WE-r-C",
  L"C_UL-C", L"C_UR-C", L"C_LL-C", L"C_LR-C",
  L"Parchment",
  L"fr_inven-C",
  L"NPCSlot-C",
  L"iSg-04-C", L"iSg-03-C", L"iSg-02-C", L"iSg-01-C",
  L"ib-m4d-C", L"ib-m3d-C", L"ib-m2d-C", L"ib-m1d-C",
  L"ib-MZIn-C", L"ib-MZOu-C",
  L"ib-NPCSL0-C", L"ib-NPCSL1-C", L"ib-NPCSR0-C", L"ib-NPCSR1-C",
  L"ib-Cmps-C",
  L"ib-InitG-C", L"ib-InitY-C", L"ib-InitR-C",
  L"ib-MMask-C",
  L"ib-mb-C",
  L"ib-Selec-C",
  L"WizEyeC", L"TorchC",
  L"endcap-C",
 },
               **pRequestedInterface;


 switch (uAlignment)
 {
  case 0:
    pRequestedInterface = pGoodInterface;

    dword_507AFC = 0xFF0000C8;
    dword_507AF8 = 0xFFFFE1FF;
  break;

  default:
  case 1:
    pRequestedInterface = pNeutralInterface;

    dword_507AFC = 0xFF0A0000;
    dword_507AF8 = 0xFFE6D6C1;
  break;

  case 2:
    pRequestedInterface = pEvilInterface;

    dword_507AFC = 0xFFC80000;
    dword_507AF8 = 0xFF0A0000;
  break;
 }

  

 uTextureID_GameUI_RightPanel = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[0]);
 uTextureID_GameUI_PartyFrame = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[1]);
 uTextureID_GameUI_ViewportTop = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[2]);
 uTextureID_GameUI_ViewportLeft = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[3]);
 uTextureID_GameUI_StatusBar = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[4]);

 uTextureID_right_backgr = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[5]);

 uTextureID_WindowEdgeTop = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[6]);
 uTextureID_WindowEdgeBottom = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[7]);
 uTextureID_WindowEdgeLeft = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[8]);
 uTextureID_WindowEdgeRight = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[9]);
 
 uTextureIdx_CornerUpperLeft = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[10]);
 uTextureIdx_CornerUpperRight = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[11]);
 uTextureIdx_CornerLowerLeft = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[12]);
 uTextureIdx_CornerLowerRight = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[13]);

 uTextureIdx_Parchment = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[14]);

 uTextureIdx_InventoryBackground = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[15]);

 dword_50795C_TextureID = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[16]);

 dword_507960_TextureID = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[17]);
 dword_507964_TextureID = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[18]);
 dword_507968_TextureID = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[19]);
 dword_50796C_TextureID = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[20]);

 uTextureIdx_ib_m4d_a = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[21]);
 uTextureIdx_ib_m3d_a = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[22]);
 uTextureIdx_ib_m2d_a = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[23]);
 uTextureIdx_ib_m1d_a = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[24]);
 
 uTextureIdx_ib_autin_a = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[25]);
 uTextureIdx_ib_autout_a = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[26]);
 
 uTextureIdx_ib_npcld_a = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[28]);
 uTextureIdx_ib_npcrd_a = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[30]);

 uTextureIdx_MinimapCompass = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[31]);
 
 uTextureIdx_SensorGreen = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[32]);
 dword_5079C8 = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[33]);
 dword_5079CC = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[34]);

 uTextureIdx_MinimapMask = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[35]);
 uTextureID_5079E4 = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[36]);

 uTextureIdx_CharacterSelectionFrame = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[37]);

 array_6A0D14[3].uIconIdx = pIconFrameTable->FindAnimation(pRequestedInterface[38]);
 pIconFrameTable->InitializeAnimation(array_6A0D14[3].uIconIdx);

 array_6A0D14[2].uIconIdx = pIconFrameTable->FindAnimation(pRequestedInterface[39]);
 pIconFrameTable->InitializeAnimation(array_6A0D14[2].uIconIdx);

 uTextureIdx_Endcap = LODFile_Icons_LOD.LODFile_LoadTexture_New(pRequestedInterface[40]);
 pcTexture_EndcapTexture = &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_Endcap];
}
#else
//----- (004226EF) --------------------------------------------------------
void MenuUI_LoadTextures(unsigned int uAlignment)
{
 unsigned int uTextureIdx_Endcap;
   

 const char  *pNeutralInterface[] =
 {
     "ib-r-A.pcx",	 //00
	 "ib-b-A.pcx", 	 //01
	 "ib-t-A.pcx", 	 //02
	 "ib-l-A.pcx", 	 //03
	 "IB-Foot-a.pcx",//04
     "ib-mb-a",		 //05
     "ib-autmask-a", //06
     "IB-COMP-a",	 //07
     "IB-InitG-a", 	 //08
     "IB-InitY-a", 	 //09
     "IB-InitR-a", 	 //10
     "IB-NPCLD-a", 	 //11
     "IB-NPCRD-a",	 //12
     "ib-autout-a",  //13
     "ib-autin-a", 	 //14
     "IB-selec-a", 	 //15
     "ib-m1d-a", 	 //16
     "ib-m2d-a", 	 //17
     "ib-m3d-a",	 //18
     "ib-m4d-a", 	 //19
     "isg-01-a", 	 //20
     "isg-02-a", 	 //21
     "isg-03-a", 	 //22
     "isg-04-a", 	 //23
	 "wizeyeA",		 //24
	 "torchA",		 //25
     "ib-bcu-a",	 //26
     "evtnpc", 	     //27
     "fr_inven", 	 //28
     "parchment", 	 //29
     "cornr_ll",	 //30
     "cornr_lr", 	 //31
     "cornr_ul", 	 //32
     "cornr_ur", 	 //33
     "edge_btm", 	 //34
     "edge_lf", 	 //35
     "edge_rt", 	 //36
     "edge_top", 	 //37
     "endcap" 	 //38
 },
        *pGoodInterface[] =       
 {
     "ib-r-B.pcx",	 //00
	 "ib-b-B.pcx", 	 //01
	 "ib-t-B.pcx", 	 //02
	 "ib-l-B.pcx", 	 //03
	 "IB-Foot-b.pcx",//04
     "ib-mb-B",		 //05
     "ib-autmask-b", //06
     "IB-COMP-B",	 //07
     "IB-InitG-b", 	 //08
     "IB-InitY-b", 	 //09
     "IB-InitR-b", 	 //10
     "IB-NPCLD-B", 	 //11
     "IB-NPCRD-B",	 //12
     "ib-autout-B",  //13
     "ib-autin-B", 	 //14
     "IB-selec-B", 	 //15
     "ib-m1d-b", 	 //16
     "ib-m2d-b", 	 //17
     "ib-m3d-b",	 //18
     "ib-m4d-b", 	 //19
     "isg-01-b", 	 //20
     "isg-02-b", 	 //21
     "isg-03-b", 	 //22
     "isg-04-b", 	 //23
	 "wizeyeB",		 //24
	 "torchB",		 //25
     "ib-bcu-b",	 //26
     "evtnpc-b", 	 //27
     "fr_inven-b", 	 //28
     "parchment", 	 //29
     "cornr_ll-b",	 //30
     "cornr_lr-b", 	 //31
     "cornr_ul-b", 	 //32
     "cornr_ur-b", 	 //33
     "edge_btm-b", 	 //34
     "edge_lf-b", 	 //35
     "edge_rt-b", 	 //36
     "edge_top-b", 	 //37
     "endcap-b" 	 //38
 },
               *pEvilInterface[] =
 {
     "ib-r-C.pcx",	 //00
	 "ib-b-C.pcx", 	 //01
	 "ib-t-C.pcx", 	 //02
	 "ib-l-C.pcx", 	 //03
	 "IB-Foot-c.pcx",//04
     "ib-mb-C",		 //05
     "ib-autmask-c", //06
     "IB-COMP-C",	 //07
     "IB-InitG-c", 	 //08
     "IB-InitY-c", 	 //09
     "IB-InitR-c", 	 //10
     "IB-NPCLD-C", 	 //11
     "IB-NPCRD-c",	 //12
     "ib-autout-C",  //13
     "ib-autin-C", 	 //14
     "IB-selec-C", 	 //15
     "ib-m1d-c", 	 //16
     "ib-m2d-c", 	 //17
     "ib-m3d-c",	 //18
     "ib-m4d-c", 	 //19
     "isg-01-c", 	 //20
     "isg-02-c", 	 //21
     "isg-03-c", 	 //22
     "isg-04-c", 	 //23
	 "wizeyeC",		 //24
	 "torchC",		 //25
     "ib-bcu-c",	 //26
     "evtnpc-c", 	 //27
     "fr_inven-c", 	 //28
     "parchment", 	 //29
     "cornr_ll-c",	 //30
     "cornr_lr-c", 	 //31
     "cornr_ul-c", 	 //32
     "cornr_ur-c", 	 //33
     "edge_btm-c", 	 //34
     "edge_lf-c", 	 //35
     "edge_rt-c", 	 //36
     "edge_top-c", 	 //37
     "endcap-c" 	 //38
 },
               **pRequestedInterface;

  
 switch (uAlignment)
 {
  case PARTY_ALIGNMENT_GOOD:
    pRequestedInterface = pGoodInterface;

    dword_507AFC = 0xFF0000C8;
    dword_507AF8 = 0xFFFFE1FF;
  break;
  case PARTY_ALIGNMENT_EVIL:
    pRequestedInterface = pEvilInterface;

    dword_507AFC = 0xFFC80000;
    dword_507AF8 = 0xFF0A0000;
  break;
  default:
  case  PARTY_ALIGNMENT_NEUTRAL:
    pRequestedInterface = pNeutralInterface;

    dword_507AFC = 0xFF0A0000;
    dword_507AF8 = 0xFFE6D6C1;
  break;

 
 }
 //  LODFile_Icons_LOD.SetupPalettes(5,6,5);
  cPCXID_GameUI_RightPanel.LODPCXLoad(pRequestedInterface[0],0);
  cPCXID_GameUI_StatusBar.LODPCXLoad( pRequestedInterface[4],0);
  cPCXID_GameUI_ViewportTop.LODPCXLoad(pRequestedInterface[2],0);
  cPCXID_GameUI_ViewportLeft.LODPCXLoad(pRequestedInterface[3],0);
  cPCXID_GameUI_PartyFrame.LODPCXLoad(pRequestedInterface[1],0);
 uTextureID_right_backgr = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[26],2);		//"ib-bcu-C",		 //05
    
 uTextureID_WindowEdgeTop = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[37],2);	  //"edge_top-c", 	 //37
 uTextureID_WindowEdgeBottom = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[34],2);  // "edge_btm-c", 	 //34
 uTextureID_WindowEdgeLeft = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[35],2);	   //"edge_lf-c", 	 //35
 uTextureID_WindowEdgeRight = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[36],2);	  //"edge_rt-c", 	 //36
 
 uTextureIdx_CornerUpperLeft = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[32],2);	// "cornr_ul-c", 	 //32
 uTextureIdx_CornerUpperRight = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[33],2);	// "cornr_ur-c", 	 //33
 uTextureIdx_CornerLowerLeft = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[30],2);	//"cornr_ll-c",	 //30
 uTextureIdx_CornerLowerRight = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[31],2);	//  "cornr_lr-c", 	 //31

 uTextureIdx_Parchment = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[29],2);		// "parchment", 	 //29

 uTextureIdx_InventoryBackground = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[28],2);   //"fr_inven-c", 	 //28

 dword_50795C_TextureID = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[27],2);	//"evtnpc-a", 	 //27

 dword_507960_TextureID = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[23],2);	  // "isg-04-a", 	 //23
 dword_507964_TextureID = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[22],2);	  // "isg-03-a", 	 //22
 dword_507968_TextureID = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[21],2);   //"isg-02-a", 	 //21
 dword_50796C_TextureID = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[20],2);	//"isg-01-a", 	 //20
	    		      
 uTextureIdx_ib_m4d_a = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[19],2);	 // 	   "ib-m4d-c", 	 //19
 uTextureIdx_ib_m3d_a = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[18],2);	//	 "ib-m3d-c",	 //18
 uTextureIdx_ib_m2d_a = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[17],2);	 //     "ib-m2d-c", 	 //17
 uTextureIdx_ib_m1d_a = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[16],2);	 // "ib-m1d-c", 	 //16
 																			    

 uTextureIdx_ib_autin_a = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[14],2); //	  "ib-autin-C", 	 //14
 uTextureIdx_ib_autout_a = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[13],2); // "ib-autout-C",  //13
 
 uTextureIdx_ib_npcld_a = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[11],2);	//  "IB-NPCLD-C", 	 //11   
 uTextureIdx_ib_npcrd_a = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[12],2);	//	 "IB-NPCRD-c",	 //12

 uTextureIdx_MinimapCompass = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[07],2);	 // "IB-COMP-C",	 //07
 																								 
 uTextureIdx_SensorGreen = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[8],2);	   //  "IB-InitG-c", 	 //08
 dword_5079C8 = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[9],2);				  //   "IB-InitY-c", 	 //09
 dword_5079CC = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[10],2);					//   "IB-InitR-c", 	 //10

 uTextureIdx_MinimapMask = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[06],2);	  //"ib-autmask-b", //06
 uTextureID_5079E4 = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[5],2);            // "ib-mb-C"

 uTextureIdx_CharacterSelectionFrame = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[15],2);  //"IB-selec-C", 	 //15

 array_6A0D14[3].uIconIdx = pIconFrameTable->FindAnimation(pRequestedInterface[24]);	  //"wizeyeC",		 //24	
 pIconFrameTable->InitializeAnimation(array_6A0D14[3].uIconIdx);

 array_6A0D14[2].uIconIdx = pIconFrameTable->FindAnimation(pRequestedInterface[25]);		// "torchC",		 //25
 pIconFrameTable->InitializeAnimation(array_6A0D14[2].uIconIdx);

 uTextureIdx_Endcap = LODFile_Icons_LOD.LODFile_LoadTexture(pRequestedInterface[38],2);    // "endcap-c" 	 //38
 pcTexture_EndcapTexture = &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_Endcap];
}

#endif
