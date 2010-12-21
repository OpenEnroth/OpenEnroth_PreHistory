#include "data.h"
#include "mm7_unparsed_data.h"

#include "Game.h"
#include "Actor.h"
#include "AudioPlayer.h"
#include "Clock.h"
#include "_lod.h"


unsigned int Game_OnStartNPCDialogue(unsigned int uSpekerActorID, int)
{
 if (uActiveCharacter)
 {
  struct_576FE8.dword_000048 = 1;

  dword_50CBD0.CutQueueTail();
  dword_5B65D0 = pActors[uSpekerActorID].word_000020;

  Actor_InitializeDialogue(&pActors[uSpekerActorID], 1);
 }
 return Error::Success;
}







unsigned int Game_OnInteract(int, int)
{
 sub_46A14B_ProbablyDoInteraction();
 return Error::Success;
}



unsigned int Game_OnCastQuickspell(int, int)
{
 if (byte_6BE3C4_MaybeDrowningFlag)
 {
  sub_44C175((char *)pGlobalTXT_LocalizationStrings[652], 2);

  AudioPlayer_sub_4AA306(pAudioPlayer, 27, 0, 0, -1, 0, 0, 0, 0);
 }
 else if (uActiveCharacter)
 {
  Player *pCaster = pPlayers[uActiveCharacter - 1];
  if (!pCaster->uTimeToRecovery)
    sub_42777D_CastSpell(pCaster->uQuickSpell, uActiveCharacter, 0, 0, uActiveCharacter);

  return Error::Success;
 }

 return Error::Generic;
}




unsigned int Game_OnAttack(int, int)
{
 if (!uActiveCharacter)
   return Error::Generic;

 if (!pParty_global->bTurnBasedModeOn)
   sub_42ECB5_PlayerAttack();
 else
 {
  if (dword_4F885C == 1 || dword_4F885C == 3)
    return Error::Success;
  else if (~dword_4F8870 & 2)
    sub_42ECB5_PlayerAttack();
 }
 return Error::Success;
}












unsigned int Game_OnOpenRest(int, int)
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return Error::Success;

 if (!sub_42F4DA())
   if (~pParty_global->dword_007778 & 0x88)
   {
    sub_41F6C1();
    return Error::Success;
   }


 if (pParty_global->bTurnBasedModeOn)
 {
  sub_44C175((char *)pGlobalTXT_LocalizationStrings[478], 2);
  return Error::Success;
 }

 if (pParty_global->dword_007778 & 0x88)
   sub_44C175((char *)pGlobalTXT_LocalizationStrings[479], 2);
 else
   sub_44C175((char *)pGlobalTXT_LocalizationStrings[480], 2);

 if (uActiveCharacter)
   Player_PlaySound(pPlayers[uActiveCharacter - 1], 13, 0);

 return Error::Success;
}



unsigned int Game_OnOpenQuickRef(int, int)
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   GUIWindowDelete(pGUIWindow_CurrentMenu);

 ++LODFile_Icons_LOD.uTexturePacksCount;
 if (!LODFile_Icons_LOD.uPrevLoadedFiles)
   LODFile_Icons_LOD.uPrevLoadedFiles = LODFile_Icons_LOD.uNumLoadedFiles;

 GUIWindowCreate(560, 450, 0, 0, 90, pBtn_Game_QuickRef, 0);
 struct_576FE8.dword_000044 = 1;
 cClock1.clock_fn1();
 AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
 dword_4E28F8_PartyCantJumpIfTrue = 104;
 pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 12, (GUIButton *)5, 0);
 uTextureID_ButtExit1 = LODFile_Icons_LOD.LODFile_LoadTexture("BUTTEXI1", 2);
 dword_5076F4 = GUIButtonCreate(pGUIWindow_CurrentMenu, 391, 316, 75, 33, 1, 0, 113, 0, 0, pGlobalTXT_LocalizationStrings[79], &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_BtnEsc2]);

 return Error::Success;
}



unsigned int Game_OnOpenSpellbook(int, int)
{
 if (dword_4F885C == 3)
   return Error::Generic;

 if (byte_6BE3C4_MaybeDrowningFlag)
 {
  sub_44C175((char *)pGlobalTXT_LocalizationStrings[652], 2);

  AudioPlayer_sub_4AA306(pAudioPlayer, 27, 0, 0, -1, 0, 0, 0, 0);
  return Error::Generic;
 }

 if (uActiveCharacter && !pPlayers[uActiveCharacter - 1]->pInventorySlots[74].word_00001E)
 {
  if (dword_4E28F8_PartyCantJumpIfTrue != 5 &&
      dword_4E28F8_PartyCantJumpIfTrue != 7 &&
      (dword_4E28F8_PartyCantJumpIfTrue <= 99 || dword_4E28F8_PartyCantJumpIfTrue > 103))
    GUIWindowDelete(pGUIWindow_CurrentMenu);
  else if (dword_4E28F8_PartyCantJumpIfTrue)
    return Error::Success;

  GUIWindowCreate(476, 450, 0, 0, 90, pBtn_Game_CastSpell, 0);
  dword_4E28F8_PartyCantJumpIfTrue = 8;
  cClock1.clock_fn1();
  pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 18, 0, 0);
  AudioPlayer_sub_4AA306(pAudioPlayer, 48, 0, 0, -1, 0, 0, 0, 0);
  struct_576FE8.dword_000048 = 1;
 }
 return Error::Success;
}


unsigned int Game_OnOpenCalendar(int, unsigned int uTriggeredContorlID)
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   GUIWindowDelete(pGUIWindow_CurrentMenu);

 cClock1.clock_fn1();
 AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);

 pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 9, (GUIButton *)uTriggeredContorlID, 0);
 ptr_507BE0 = GUIWindowCreate(570, 354, 0, 0, 99, pBtn_Game_Calendar, 0);

 return Error::Success;
}


unsigned int Game_OnOpenMap(int, unsigned int uTriggeredContorlID)
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   GUIWindowDelete(pGUIWindow_CurrentMenu);

 cClock1.clock_fn1();
 struct_576FE8.sPartyPosX = pParty_global->sPartyPosX;
 struct_576FE8.sPartyPosY = pParty_global->sPartyPosY;
 AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);

 pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 9, (GUIButton *)uTriggeredContorlID, 0);
 ptr_507BE0 = GUIWindowCreate(546, 353, 0, 0, 99, pBtn_Game_Calendar, 0);

 return Error::Success;
}



unsigned int Game_OnOpenAutonotes(int, unsigned int uTriggeredContorlID)
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   GUIWindowDelete(pGUIWindow_CurrentMenu);

 cClock1.clock_fn1();
 AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
 pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 9, (GUIButton *)uTriggeredContorlID, 0);
 ptr_507BE0 = GUIWindowCreate(527, 353, 0, 0, 99, pBtn_Game_Autonotes, 0);
 byte_507949 = 0;

 return Error::Success;
}


unsigned int Game_OnOpenQuestbook(int, unsigned int uTriggeredContorlID)
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   GUIWindowDelete(pGUIWindow_CurrentMenu);

 cClock1.clock_fn1();
 AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
 pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 9, (GUIButton *)uTriggeredContorlID, 0);
 ptr_507BE0 = GUIWindowCreate(493, 355, 0, 0, 99, pBtn_Game_Quests, 0);
 byte_50794A = 0;

 return Error::Success;
}