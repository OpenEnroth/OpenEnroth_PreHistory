#include "Party.h"
#include "clock.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"




unsigned int ActionQueue::Clear()
{
 uNumActions = 0;
 return Result::Success;
}


//----- (004760C1) --------------------------------------------------------
unsigned int ActionQueue::Add(Action::Type eAction)
{
 if (uNumActions < 30)
 {
  pActions[uNumActions++] = eAction;
  return Result::Success;
 }
 return Result::OutOfMemory;
}

//----- (004760D5) --------------------------------------------------------
unsigned int ActionQueue::Next(Action::Type *pOut)
{
 if (!uNumActions)
   return Result::NotFound;

 if (pOut)
   *pOut = pActions[0];

 for (unsigned int i = 1; i < uNumActions; ++i)
   pActions[i - 1] = pActions[i];

 --uNumActions;
 return Result::Success;
}
















void PartyAction_OnStrafeRight()
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return;

 if (!pParty_global->bTurnBasedModeOn)
 {
  pPartyActionQueue->Add(Action::StrafeRight);
  return;
 }

 if (dword_4F885C == 1 || dword_4F885C == 2 || dword_4F886C <= 0)
   return;

 dword_4F886C -= 26;
 pPartyActionQueue->Add(Action::StrafeRight);
}




void PartyAction_OnStrafeLeft()
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return;

 if (!pParty_global->bTurnBasedModeOn)
 {
  pPartyActionQueue->Add(Action::StrafeLeft);
  return;
 }

 if (dword_4F885C == 1 || dword_4F885C == 2 || dword_4F886C <= 0)
   return;

 dword_4F886C -= 26;
 pPartyActionQueue->Add(Action::StrafeLeft);
}




void PartyAction_OnLand()
{
 if (dword_4E28F8_PartyCantJumpIfTrue || cClock1.dword_000004)
   return;

 pPartyActionQueue->Add(Action::Land);
}


void PartyAction_OnFlyDown()
{
 if (dword_4E28F8_PartyCantJumpIfTrue || cClock1.dword_000004)
   return;

 pPartyActionQueue->Add(Action::FlyDown);
}





void PartyAction_OnFlyUp()
{
 if (dword_4E28F8_PartyCantJumpIfTrue || cClock1.dword_000004)
   return;

 pPartyActionQueue->Add(Action::FlyUp);
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

 pPartyActionQueue->Add(Action::CenterView);
}

void PartyAction_OnLookDown()
{
 if (cClock1.dword_000004)
   return;

 pPartyActionQueue->Add(Action::LookDown);
}


void PartyAction_OnLookUp()
{
 if (cClock1.dword_000004)
   return;

 pPartyActionQueue->Add(Action::LookUp);
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
   dword_50C9E8.PutMessageToQueue(MESSAGE_CAST_QUICKSPELL, 0, 0);
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
 
 pPartyActionQueue->Add(Action::Jump);
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

 pPartyActionQueue->Add(eAction);
 if (uCurrentlyLoadedLevelType == 2 && dword_6BE024 == 1)
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

 pPartyActionQueue->Add(eAction);
 if (uCurrentlyLoadedLevelType == 2 && dword_6BE024 == 1)
   sub_4C2F0B(&struct_6BD080, 10);
}





void PartyAction_OnMovingBackwards()
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return;

 if (!pParty_global->bTurnBasedModeOn)
 {
  if (pParty_global->dword_000884 & 2)
    pPartyActionQueue->Add((Action::Type)17);
  else
    pPartyActionQueue->Add(Action::WalkBackwards);
 }
 else if (dword_4F885C != 1 && dword_4F885C != 2 && dword_4F886C > 0)
 {
  dword_4F886C -= 26;

  if (pParty_global->dword_000884 & 2)
    pPartyActionQueue->Add((Action::Type)17);
  else
    pPartyActionQueue->Add(Action::WalkBackwards);
 }
}




void PartyAction_OnMovingForward()
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return;

 if (!pParty_global->bTurnBasedModeOn)
 {
  if (pParty_global->dword_000884 & 2)
    pPartyActionQueue->Add((Action::Type)16);
  else
    pPartyActionQueue->Add(Action::WalkForward);
 }
 else if (dword_4F885C != 1 && dword_4F885C != 2 && dword_4F886C > 0)
 {
  dword_4F886C -= 26;

  if (pParty_global->dword_000884 & 2)
    pPartyActionQueue->Add((Action::Type)16);
  else
    pPartyActionQueue->Add(Action::WalkForward);
 }
}
