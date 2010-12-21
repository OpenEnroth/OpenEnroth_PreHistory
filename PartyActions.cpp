#include "Party.h"
#include "clock.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"





void PartyAction_OnStrafeRight()
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return;

 if (!pParty_global->bTurnBasedModeOn)
 {
  sub_4760C1_QueuePlayerAction(&stru_7215D8, Action::StrafeRight);
  return;
 }

 if (dword_4F885C == 1 || dword_4F885C == 2 || dword_4F886C <= 0)
   return;

 dword_4F886C -= 26;
 sub_4760C1_QueuePlayerAction(&stru_7215D8, Action::StrafeRight);
}




void PartyAction_OnStrafeLeft()
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return;

 if (!pParty_global->bTurnBasedModeOn)
 {
  sub_4760C1_QueuePlayerAction(&stru_7215D8, Action::StrafeLeft);
  return;
 }

 if (dword_4F885C == 1 || dword_4F885C == 2 || dword_4F886C <= 0)
   return;

 dword_4F886C -= 26;
 sub_4760C1_QueuePlayerAction(&stru_7215D8, Action::StrafeLeft);
}




void PartyAction_OnLand()
{
 if (dword_4E28F8_PartyCantJumpIfTrue || cClock1.dword_000004)
   return;

 sub_4760C1_QueuePlayerAction(&stru_7215D8, Action::Land);
}


void PartyAction_OnFlyDown()
{
 if (dword_4E28F8_PartyCantJumpIfTrue || cClock1.dword_000004)
   return;

 sub_4760C1_QueuePlayerAction(&stru_7215D8, Action::FlyDown);
}





void PartyAction_OnFlyUp()
{
 if (dword_4E28F8_PartyCantJumpIfTrue || cClock1.dword_000004)
   return;

 sub_4760C1_QueuePlayerAction(&stru_7215D8, Action::FlyUp);
}



void PartyAction_OnZoomIn()
{
 dword_50C9E8.PutMessageToQueue(MESSAGE_MINIMAP_ZOOM_IN, 0, 0);
}



void PartyAction_OnZoomOut()
{
 dword_50C9E8.PutMessageToQueue(MESSAGE_MINIMAP_ZOOM_OUT, 0, 0);
}




void PartyAction_OnCenterView()
{
 if (cClock1.dword_000004)
   return;

 sub_4760C1_QueuePlayerAction(&stru_7215D8, Action::CenterView);
}

void PartyAction_OnLookDown()
{
 if (cClock1.dword_000004)
   return;

 sub_4760C1_QueuePlayerAction(&stru_7215D8, Action::LookDown);
}


void PartyAction_OnLookUp()
{
 if (cClock1.dword_000004)
   return;

 sub_4760C1_QueuePlayerAction(&stru_7215D8, Action::LookUp);
}



void PartyAction_OnAlwaysRun()
{
 bAlwaysRun = bAlwaysRun == 0;
}




void PartyAction_OnCharCycle()
{
 if (dword_4E28F8_PartyCantJumpIfTrue == 8)
   return;

 dword_50C9E8.PutMessageToQueue(MESSAGE_PROBABLY_CHARCYCLE, 0, 0);
}






void PartyAction_OnPass()
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return;

 if (pParty_global->bTurnBasedModeOn && dword_4F885C == 3)
 {
  dword_4F8870 |= 8;
  return;
 }

 if (uActiveCharacter)
 {
  Player *pPlayer = pPlayers[uActiveCharacter - 1];

  if (!pPlayer->uTimeToRecovery)
  {
   unsigned int uRecovery = Player_sub_GetAttackRecoveryTime(pPlayer, 0);

   if (!pParty_global->bTurnBasedModeOn)
     Player_SetRecoveryTime(pPlayer, flt_6BE3A4_debug_recmod1 * uRecovery * 2.1333333333333333);

   sub_427D48_MessWith_unnamed_50C0C8(&struct_50C0C8, uActiveCharacter);
   sub_40471C(&unk_4F8858);
  }
 }
}








void PartyAction_OnInteract()
{
 if (!dword_4E28F8_PartyCantJumpIfTrue)
 {
  dword_50CBD0.PutMessageToQueue(404, 0, 0);
  return;
 }
 else if (dword_4E28F8_PartyCantJumpIfTrue == 4)
 {
  dword_50CBD0.CutQueueTail();
  dword_50CBD0.PutMessageToQueue(113,0,0);
 }
}





void PartyAction_OnAttack()
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return;

 if (!pParty_global->bTurnBasedModeOn || dword_4F885C != 3)
 {
  dword_50CBD0.PutMessageToQueue(MESSAGE_ATTACK, 0, 0);
  return;
 }

 dword_4F8870 |= 8;
}




void PartyAction_OnCastReady()
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return;

 if (pParty_global->bTurnBasedModeOn && dword_4F885C == 3)
 {
  dword_4F8870 |= 8;
  return;
 }

 if (!uActiveCharacter)
   return;


 Player *pCaster = pPlayers[uActiveCharacter - 1];
 if (!pCaster->uQuickSpell || byte_6BE3C4_MaybeDrowningFlag)
 {
  dword_50CBD0.PutMessageToQueue(MESSAGE_ATTACK, 0, 0);
  return;
 }

 unsigned short v9 = pCaster->pActiveSkills[pCaster->uQuickSpell / 11 + 12],
                v10;
 if (v9 & 0x0100)
   v10 = word_4E3C68[pCaster->uQuickSpell].uMagisterLevelMana;
 else if (v9 & 0x0080)
   v10 = word_4E3C68[pCaster->uQuickSpell].uMasterLevelMana;
 else if (v9 & 0x0040)
   v10 = word_4E3C68[pCaster->uQuickSpell].uExpertLevelMana;
 else
   v10 = word_4E3C68[pCaster->uQuickSpell].uNormalLevelMana;

 if (v10 > pCaster->sMana)
   dword_50CBD0.PutMessageToQueue(MESSAGE_ATTACK, 0, 0);
 else
   dword_50C9E8.PutMessageToQueue(MESSAGE_PROBABLY_CAST_QUICKSPELL, 0, 0);
}










void PartyAction_OnToggleTurnBasedMode()
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return;

 if (pParty_global->bTurnBasedModeOn)
 {
  if (dword_4F885C == 3 || (dword_4F8878[0] & 7) == 4)
  {
   pParty_global->bTurnBasedModeOn = false;
   sub_405CFF((int)&unk_4F8858, 1);
  }
 }
 else
 {
  sub_4059DB_ProbablyStartTurn(&unk_4F8858);
  pParty_global->bTurnBasedModeOn = true;
 }
}





void PartyAction_OnJump()
{
 if (dword_4E28F8_PartyCantJumpIfTrue || pParty_global->bTurnBasedModeOn)
   return;
 
 sub_4760C1_QueuePlayerAction(&stru_7215D8, Action::Jump);
}





void PartyAction_OnYell()
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return;

 if (uActiveCharacter)
 {
  sub_43AD34();
  Player_PlaySound(pPlayers[uActiveCharacter - 1], 65, 0);
 }
}





void PartyAction_OnTurningRight()
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return;

 Action::Type eAction;
 if (GetAsyncKeyState(VK_CONTROL))
 {
  if (pParty_global->bTurnBasedModeOn)
  {
   if (dword_4F885C == 1 || dword_4F885C == 2 || dword_4F886C <= 0)
     return;

   dword_4F886C -= 26;
  }
  eAction = Action::StrafeRight;
 }
 else
 {
  if (pParty_global->dword_000884 & 2)
    eAction = (Action::Type)19;
  else
    eAction = Action::TurnRight;
 }

 sub_4760C1_QueuePlayerAction(&stru_7215D8, eAction);
 if (dword_6BE360 == 2 && dword_6BE024 == 1)
   sub_4C2F0B(&struct_6BD080, -10);
}




void PartyAction_OnTurningLeft()
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return;

 Action::Type eAction;
 if (GetAsyncKeyState(VK_CONTROL))
 {
  if (pParty_global->bTurnBasedModeOn)
  {
   if (dword_4F885C == 1 || dword_4F885C == 2 || dword_4F886C <= 0)
     return;
   dword_4F886C -= 26;
  }
  eAction = Action::StrafeLeft;
 }
 else
 {
  if (pParty_global->dword_000884 & 2)
    eAction = (Action::Type)18;
  else
    eAction = Action::TurnLeft;
 }

 sub_4760C1_QueuePlayerAction(&stru_7215D8, eAction);
 if (dword_6BE360 == 2 && dword_6BE024 == 1)
   sub_4C2F0B(&struct_6BD080, 10);
}





void PartyAction_OnMovingBackwards()
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return;

 if (!pParty_global->bTurnBasedModeOn)
 {
  if (pParty_global->dword_000884 & 2)
    sub_4760C1_QueuePlayerAction(&stru_7215D8, (Action::Type)17);
  else
    sub_4760C1_QueuePlayerAction(&stru_7215D8, Action::WalkBackwards);
 }
 else if (dword_4F885C != 1 && dword_4F885C != 2 && dword_4F886C > 0)
 {
  dword_4F886C -= 26;

  if (pParty_global->dword_000884 & 2)
    sub_4760C1_QueuePlayerAction(&stru_7215D8, (Action::Type)17);
  else
    sub_4760C1_QueuePlayerAction(&stru_7215D8, Action::WalkBackwards);
 }
}




void PartyAction_OnMovingForward()
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return;

 if (!pParty_global->bTurnBasedModeOn)
 {
  if (pParty_global->dword_000884 & 2)
    sub_4760C1_QueuePlayerAction(&stru_7215D8, (Action::Type)16);
  else
    sub_4760C1_QueuePlayerAction(&stru_7215D8, Action::WalkForward);
 }
 else if (dword_4F885C != 1 && dword_4F885C != 2 && dword_4F886C > 0)
 {
  dword_4F886C -= 26;

  if (pParty_global->dword_000884 & 2)
    sub_4760C1_QueuePlayerAction(&stru_7215D8, (Action::Type)16);
  else
    sub_4760C1_QueuePlayerAction(&stru_7215D8, Action::WalkForward);
 }
}
