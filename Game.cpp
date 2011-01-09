#include "Game.h"

#include "mm7_unparsed_data.h"
#include "classes.h"
#include "clock.h"
#include "_lod.h"
#include "menus.h"
#include "AudioPlayer.h"
#include "VideoPlayer.h"
#include "UserInput.h"




Result::Code Game::PrepareForLoop()
{
  if (uCurrentMenuID == 9)
  {
    Party_Reset(pParty);
    dword_6BE340 = 0;
    dword_6A0D48 = 0;
    sub_45EE8A(dword_6A0CA0_indx);
  }	  
  SetCurrentMenu(-1);

  LoadPlayerPortraintsAndVoices();
  LODFile_Icons_LOD.lod_IB_dword_011B84 = LODFile_Icons_LOD.uNumLoadedFiles;

  pAudioPlayer->SetMusicVolume(64.0f * pSoundVolumeLevels[uMusicVolimeMultiplier]);

 return Result::Success;
}

//----- (00463149) --------------------------------------------------------
Result::Code Game::Loop(const char *pLevelName)
{
 int v17;
  signed int v0; // ebp@3
  signed int v1; // esi@4
  int v2; // edi@7
  int v5; // eax@46
  int v6; // ecx@58
  signed int v9; // edi@67
  int v10; // esi@67
  int v11; // edi@69
  signed int v12; // esi@71
  signed int v13; // esi@78
  int v14; // eax@83
  const char *v16; // [sp-4h] [bp-68h]@74
  signed int v18; // [sp+10h] [bp-54h]@19
  signed int v19; // [sp+14h] [bp-50h]@8
  int v20[4]; // [sp+18h] [bp-4Ch]@80
  MSG Msg; // [sp+28h] [bp-3Ch]@20
  char Source; // [sp+44h] [bp-20h]@76
 int i;


 
  v0 = 1;
  v2 = (int)pD3DRenderer;
  v17 = uCurrentMenuID == 9;
  while (true)
  {
    v19 = 1;
    if ( dword_50CBD0.msg_count )
			   if  (dword_50CBD0.prm[0].msg_param3)
                          dword_50CBD0.msg_count = 1;

    pPartyActionQueue->Clear();
    if (pParty->bTurnBasedModeOn)
    {
      sub_405CFF((int)&unk_4F8858, 0);
      pParty->bTurnBasedModeOn = false;
    }

    PrepareWorld(pLevelName, v17, 1);
    cEventTimer.Resume();
    dword_6BE364 |= 0x80;
    dword_6BE340 = 2;
    dword_4E28F8_PartyCantJumpIfTrue = 0;

    runtime_warning(async input);
    /*if (pAsyncMouse)
      CAsyncMouse_sub_46B105((void *)pAsyncMouse);
    if (pGame->Win32Keyboard_obj->dword_000004 && 0xFF)
    {
      if (pAsyncKeyboard)
        CAsyncKeyboard_Resume(pAsyncKeyboard);
    }*/
    Vis_sub_4C1A02(pGame->pVis);
    v18 = 0;


    do
    {
      while ( PeekMessageA(&Msg, 0, 0, 0, PM_REMOVE) )
      {
        if ( Msg.message == WM_QUIT )
          Game_DeinitializeAndTerminate(0);
        TranslateMessage(&Msg);
        DispatchMessageA(&Msg);
      }

      if ( BYTE1(dword_6BE364) & 1 )
      {
        WaitMessage();
        continue;
      }

      Game_sub_44EEA7(pGame);
      GameUI_Update();
      sub_42FC4E_ProcessPressedKeys();
      GameUI_Process();
      if ( struct_505898.byte_505992 )
      {
        sub_409E6A();
LABEL_89:
        ((BaseRender *)v2)->Present();
        continue;
      }

      if (pVideoPlayer)
      {
       if (pVideoPlayer->pSmackerMovie)
       {
        compile_error();
        /*if ( !SmackWait(pVideoPlayer->pSmackerMovie) )
        {
         ((BaseRender *)v2)->BeginScene();
          GUICursor_sub_469E3B(pGame->pGUICursor);
          pVideoPlayer->sub_4BF08B((int)pVideoPlayer->pWindow->GetAPIHandle());
          GUICursor_sub_469EA4_LooksLikeDrawPickedItem(pGame->pGUICursor);
          ((BaseRender *)v2)->EndScene();
        }*/
       }
       if (pVideoPlayer->pBinkMovie)
       {
        compile_error();
        /*if ( !BinkWait(pVideoPlayer->pBinkMovie) )
        {
          ((BaseRender *)v2)->BeginScene();
          GUICursor_sub_469E3B(pGame->pGUICursor);
          compile_error();//nullsub_2(dword_F8BB78);
          GUICursor_sub_469EA4_LooksLikeDrawPickedItem(pGame->pGUICursor);
          ((BaseRender *)v2)->EndScene();
        }*/
       }
      }

    cEventTimer.Update();
    cMiscTimer.Update();
      sub_448B67_ProcessEvents(false);
      sub_448B45_LooksLikeResetSomeTimer(false);
      if (cMiscTimer.bPaused)
      {
        if ( !cEventTimer.bPaused )
          cMiscTimer.Resume();
      }
      if ( cEventTimer.dword_000008 )
      {
        if (!pParty->bTurnBasedModeOn)
          cEventTimer.dword_000008 = 0;
      }
      if ( !cEventTimer.bPaused )
      {
        if ( !dword_6A0D48 )
        {
          if ( !cEventTimer.dword_000008 )
            sub_494035();
          if ( dword_6BE364 & 1 )
          {
            dword_6BE364 &= 0xFFFFFFFE;
          }
          else
          {
            sub_401A91();
            sub_46BDC0_UpdateUserInputAndOther(0);
          }
        }
      }
      if ( v19 )
      {
        v19 = 0;
        struct_576FE8.dword_000044 = 1;
      }

      pAudioPlayer->sub_4AAFCF();
      if ( dword_6A0D48 == 1 )
        goto LABEL_96;
      else if ( dword_6A0D48 == 2 )
      {
        pAudioPlayer->MessWithChannels(&Range<unsigned int>(0, 16));
        sub_4646F0(0);
        dword_6A0D48 = 0;
        continue;
      }
      if ( dword_6A0D48 <= 2 )
        goto LABEL_85;
      if ( dword_6A0D48 <= 5 || dword_6A0D48 == 7 )
      {
LABEL_96:
        v18 = 1;
        continue;
      }
      if ( dword_6A0D48 != 8 )
      {
        if ( dword_6A0D48 != 9 )
        {
LABEL_85:
          sub_44103C_Draw();
          continue;
        }
        ((BaseRender *)v2)->BeginScene();
        sub_4156F0_UI_UpdateWindows();
        ((BaseRender *)v2)->EndScene();
        goto LABEL_89;
      }
      pAudioPlayer->MessWithChannels(&Range<unsigned int>(0, 16));
      memset(&pParty->pHiredNPCs[0], 0, sizeof(struct NPCData));
      memset(&pParty->pHiredNPCs[1], 0, sizeof(struct NPCData));
      v6 = 0;
      if (pNPCStats->dword_017FC4 > 0)
      {
        do
        {
         if ( pNPCStats->pNPCData2[v6].dword_000020 )
            pNPCStats->pNPCData2[v6].dword_000008 &= 0x7Fu;
          ++v6;
        }
        while ( v6 < pNPCStats->dword_017FC4);
      }

      // Let's play First Act movie
      if (!bNoVideo)
      {
       if (pVideoPlayer->PlayMovie("Intro Post", 0, 0, false))
         pVideoPlayer->UnloadAll();
      }

      SaveGame(0, 0);
      ++pParty->uNumDeaths;

      for (i = 0; i < 4; ++i)
        Player_sub_44A5CB((char *)&pParty->pPlayers[i], 12, 85);

      pParty->unk_000764[0] = 0;
      pParty->qword_00002C += 2580480i64;
      LOWORD(pParty->dword_007778) = pParty->dword_007778 & 0xFDFB;
      sub_492B70(0);
      v10 = (int)array_5E4D58;
      v9 = 50;
      do
      {
        sub_45855F((void *)v10);
        v10 += 20;
        --v9;
      }
      while ( v9 );
      memset(pParty->pPartyBuffs, 0, 20 * 16);
      v11 = 1;
      if (pParty->bTurnBasedModeOn)
      {
        sub_405CFF((int)&unk_4F8858, 1);
        pParty->bTurnBasedModeOn = false;
      }
      v12 = (signed int)dword_ACF2C0;
      do
      {
        memset((void *)(v12 - 6460), 0, 0xA0u);
        memset((void *)(v12 - 412), 0, 0x180u);
        *(_DWORD *)v12 = 1;
        v12 += 6972;
        uActiveCharacter = 1;
      }
      while ( v12 < (signed int)&unk_AD5FB0 );
      if ( (unsigned __int16)sub_449B57((unsigned char *)pParty->unk_000764 + 1, 136) )
      {
        pParty->vPosition = Vec3<int>(-17331, 12547, 465);
        pParty->sRotationY = 0;
        v16 = "out02.odm";
      }
      else
      {
        pParty->vPosition = Vec3<int>(12552, 1816, 0);
        pParty->sRotationY = 512;
        v16 = "out01.odm";
      }
      strcpy(&Source, v16);
      pParty->dword_000700 = pParty->vPosition.x;
      pParty->sRotationX = 0;
      pParty->dword_0006E8 = 0;
      pParty->dword_0006E4 = 0;
      pParty->dword_0006E0 = 0;
      compile_error(level file name should not be global);
    //if ( _strcmpi(&Source, CurrentLevelName) )
      if (0)
      {
        compile_error(level file name should not be global);
    //strcpy(CurrentLevelName, &Source);
        dword_5B65A8 = pParty->vPosition.x;
        dword_5B65AC = pParty->vPosition.y;
        dword_5B65B0 = pParty->vPosition.z;
        dword_5B65B4 = pParty->sRotationY;
        dword_5B65B8 = pParty->sRotationX;
        dword_5B65C0 = 1;
        sub_4646F0(1);
      }
      UpdateActors();
      v13 = 0;
      do
      {
        if ( Player_sub_492C0B_MaybeIfPlayerConscious(pPlayers[v11]) )
          v20[v13++] = v11;
        ++v11;
      }
      while ( v11 <= 4 );
      if ( v13 )
      {
        v14 = rand();
        Player_PlaySound(pPlayers[v20[v14 % v13]], 99, 0);
      }
      sub_44C175((char *)pGlobalTXT_LocalizationStrings[524], 2);
      dword_6A0D48 = 0;
      v2 = (int)pD3DRenderer;
    }
    while ( !v18 );

    dword_6BE340 = 0;
    cEventTimer.Pause();
    sub_464479_ResetCursorAndOther();
    if ( dword_6A0D48 == 3 )
    {
      sub_491E3A();
      LoadPlayerPortraintsAndVoices();
      dword_6A0D48 = 0;
      LODFile_Icons_LOD.lod_IB_dword_011B84 = LODFile_Icons_LOD.uNumLoadedFiles;
      v17 = 1;
      continue;
    }
    break;
  }

  dword_4E28F8_PartyCantJumpIfTrue = 16;
  return (Result::Code)sub_491E3A();
}










//----- (00465C8B) --------------------------------------------------------
Game *Game_Initialize()
{
 return MemAlloc(Game, 1);
}

//----- (00465CF3) --------------------------------------------------------
void Game_Destroy()
{
 if (pGame)
 {
  MemFree(pGame);
  pGame = nullptr;
 }
}


//----- (0044F07B) --------------------------------------------------------
bool Game_sub_44F07B(struct Game *_this)
{
 runtime_warning();
 /*if (!Win32Keyboard_IsKeyBeingHeld(_this->Win32Keyboard_obj, VK_SHIFT) &&
     !Win32Keyboard_IsKeyBeingHeld(_this->Win32Keyboard_obj, VK_LSHIFT) &&
     !Win32Keyboard_IsKeyBeingHeld(_this->Win32Keyboard_obj, VK_LSHIFT) ||
     !Win32Keyboard_IsKeyWasPressed(_this->Win32Keyboard_obj, VK_F11))
   Win32Keyboard_IsKeyWasPressed(_this->Win32Keyboard_obj, VK_F11);*/

 return true;
}


//----- (MM7.exe::0044E4B7) --------------------------------------------------------
Game::Game()
{
 void *v1, *v2;

 uNumStationaryLights = 0;
 dword_000E08 = 0;
 dword_000E0C = 0;
 dword_000E10 = 0;
 dword_000E14 = 0;
 dword_000E18 = 0;
 bGammaControlInitialized = false;
 uGammaControlInitializationTime = 0;
 uSomeFlags = 0x0800;
 dword_000E24 = 0x24;
 dword_000E34 = 0;
 dword_000E38 = 0;

 class01_obj = MemAlloc(class01, 1);
 if (class01_obj)
   class01_ctor(class01_obj);

 class02_obj = MemAlloc(class02, 1);
 if (class02_obj)
   class02_ctor(class02_obj);

 class03_obj = MemAlloc(GUICursor, 1);
 if (class03_obj)
   GUICursor_ctor(class03_obj, class01_obj);

 class04_obj = MemAlloc(class04, 1);
 if (class04_obj)
   class04_ctor(class04_obj);

 pVis = MemAlloc(Vis, 1);

 class06_obj = MemAlloc(class06, 1);
 if (class06_obj)
   class06_ctor(class06_obj);

 class08_obj = MemAlloc(class08, 1);
 if (class08_obj)
   class08_ctor(class08_obj);

 class09_obj = MemAlloc(class09, 1);
 if (class09_obj)
   class09_ctor(class09_obj);

 class10_obj = MemAlloc(class10, 1);
 if (class10_obj)
   class10_ctor(class10_obj);

 class11_obj = MemAlloc(class11, 1);
 if (class11_obj)
   class11_ctor(class11_obj, 0);

 class12_obj = MemAlloc(class12, 1);
 if (class12_obj)
   class12_ctor(class12_obj, class11_obj);

 class13_obj = MemAlloc(class13, 1);
 if (class13_obj)
   class13_ctor(class13_obj);

 pGammaController = MemAlloc(CGammaController, 1);
 if (pGammaController)
   CGammaController_ctor(pGammaController);

 Game_fn0(this);
 dword_4E800C = 0;
 if (dword_F79D70 != 4)
   dword_4E800C = 0;
}

//----- (0044E7D7) --------------------------------------------------------
//int Game_scalar_deleting_destructor(struct Game *_this, char flag);

//----- (0044E7F3) --------------------------------------------------------
Game::~Game()
{
  int v1; // ecx@1
  unsigned int v2; // esi@1
  int v3; // ecx@3
  int v4; // ecx@5
  unsigned int v5; // edi@7
  int v7; // eax@8
  unsigned int v8; // edi@9
  int v9; // eax@10
  int v10; // ecx@11
  int v11; // ecx@13
  int v12; // ecx@15
  unsigned int v13; // edi@17
  int v14; // eax@18
  int v15; // ecx@19
  int v16; // ecx@21
  unsigned int v17; // edi@23
  int v18; // eax@24
  unsigned int v19; // edi@25
  int v20; // eax@26
  int v21; // ecx@27

  v2 = (int)this;
  v1 = *(_DWORD *)((DWORD)this + 3696);
  *(_DWORD *)v2 = 5080668;
  if ( v1 )
    (**(int (__stdcall ***)(_DWORD))v1)(1);
  v3 = *(_DWORD *)(v2 + 3692);
  if ( v3 )
    (**(int (__stdcall ***)(_DWORD))v3)(1);
  v4 = *(_DWORD *)(v2 + 3688);
  if ( v4 )
    (**(int (__stdcall ***)(_DWORD))v4)(1);
  v5 = *(_DWORD *)(v2 + 3684);
  if ( v5 )
  {
    v7 = sub_489810(function_parameter_invalid(int), *(_DWORD *)(v2 + 3684));
    operator_delete((void *)v5);
  }
  v8 = *(_DWORD *)(v2 + 3680);
  if ( v8 )
  {
    compile_error();//v9 = nullsub_1(*(_DWORD *)(v3 + 3680));
    /*result = */operator_delete((void *)v8);
  }
  v10 = *(_DWORD *)(v2 + 3676);
  if ( v10 )
    (**(int (__stdcall ***)(_DWORD))v10)(1);
  v11 = *(_DWORD *)(v2 + 3672);
  if ( v11 )
    (**(int (__stdcall ***)(_DWORD))v11)(1);
  v12 = *(_DWORD *)(v2 + 3668);
  if ( v12 )
    (**(int (__stdcall ***)(_DWORD))v12)(1);
  v13 = *(_DWORD *)(v2 + 3664);
  if ( v13 )
  {
    sub_4A71DC(*(_DWORD *)(v2 + 3664));
    operator_delete((void *)v13);
  }
  v15 = *(_DWORD *)(v2 + 3660);
  if ( v15 )
    (**(int (__stdcall ***)(_DWORD))v15)(1);
  v16 = *(_DWORD *)(v2 + 3656);
  if ( v16 )
    (**(int (__stdcall ***)(_DWORD))v16)(1);
  v17 = *(_DWORD *)(v2 + 3652);
  if ( v17 )
  {
    v18 = sub_467E7A(*(_DWORD *)(v2 + 3652));
    operator_delete((void *)v17);
  }
  v19 = *(_DWORD *)(v2 + 3648);
  if ( v19 )
  {
    v20 = sub_48AAF1(*(_DWORD *)(v2 + 3648));
    operator_delete((void *)v19);
  }
  v21 = *(_DWORD *)(v2 + 3644);
  if ( v21 )
    (**(int (__stdcall ***)(_DWORD))v21)(1);
}


//----- (0044EEA7) --------------------------------------------------------
char Game_sub_44EEA7(struct Game *_this)
{
  int v1; // esi@1
  double v2; // st7@2
  char result; // al@9
  float v4; // ST00_4@9
  unsigned int v5; // eax@14
  int v6; // eax@21
  int v7; // [sp+4h] [bp-24h]@2
  int v8; // [sp+8h] [bp-20h]@2
  struct unnamed_F93E6C *v10; // [sp+10h] [bp-18h]@2
  struct unnamed_F93E6C *v11; // [sp+14h] [bp-14h]@2
  POINT pt;

  v1 = (int)_this;
  ++qword_5C6DF0;
  class02_sub_48AC65(_this->class02_obj);
  GUICursor_GetMousePos(_this->class03_obj, &pt);
  if ( sub_4637E0() )
  {
    v11 = &stru_F93E44;
    v10 = &stru_F93E30;
    v8 = pt.y;
    v7 = pt.x;
    v2 = sub_43643E();
  }
  else
  {
    if (_this->dword_000E24 & 0x10)
    {
      v11 = &stru_F93E44;
      v10 = &stru_F93E1C;
    }
    else
    {
      if ( !(byte_5C6DEC & 1) )
      {
        byte_5C6DEC |= 1u;
        stru_5C6DD8.dword_000000 = 0;
        stru_5C6DD8.dword_000004 = 2;
        stru_5C6DD8.dword_000008 = -1;
        stru_5C6DD8.dword_00000C = 0;
        stru_5C6DD8.dword_000010 = 0;
        atexit(0);
      }
      v11 = &stru_F93E44;
      v10 = &stru_5C6DD8;
    }
    v2 = 5120.0;
    v8 = pt.y;
    v7 = pt.x;
  }

 v4 = v2;
 pGame->PickMouse(v4, v7, v8, false, v10, v11);
 _this->class04_obj->std__vector_000004_size = 0;
 _this->class04_obj->std__vector_183808_size = 0;

  runtime_warning(seems odd);
  //pClass58_global->dword_308004 = 0;
  //pClass58_global->dword_308008 = 0;
  pClass58_global->std__vector_30B00C[1022] = 0;
  pClass58_global->std__vector_30B00C[1023] = 0;

  result = Game_sub_44F07B(_this);
  if ( result )
  {
    if (pGame->uSomeFlags & 0x08)
      _this->class10_obj->dword_000004 &= 0xFFFFFF00;
    if ( pD3DRenderer->pRenderD3D3 )
    {
      if ( uCurrentlyLoadedLevelType == 2 )
      {
        v5 = sub_47C370();
        dword_EF524C = v5 & 0xFFFFFF;
      }
    }
    if (_this->uSomeFlags & 0x0400 )
      _this->dword_000E24 |= 0x01;

    v6 = qword_5C6DF0 - _this->dword_000E10;
    if ( v6 == 1 )
    {
      if ( !((unsigned __int64)(qword_5C6DF0 - *(unsigned __int64 *)&_this->dword_000E10) >> 32) )
        _this->dword_000E24 |= v6;
    }
    if (_this->dword_000E18 != pStationaryLightsStack->uNumLightsActive )
    {
      _this->dword_000E24 |= 1;
      _this->dword_000E18 = pStationaryLightsStack->uNumLightsActive;
    }
    sub_44E904(_this);
    result = 1;
  }
  return result;
}

//----- (0044EC23) --------------------------------------------------------
signed int Game_sub_44EC23(struct Game *_this, struct struct8 *a2, int *a3, signed int a4)
{
  double v4; // st7@4
  signed int v6; // eax@5
  signed int result; // eax@8
  float v11; // [sp+14h] [bp+8h]@4
  float v12; // [sp+18h] [bp+Ch]@4
  float v13; // [sp+18h] [bp+Ch]@6
  float v14; // [sp+1Ch] [bp+10h]@9
  float v15; // [sp+1Ch] [bp+10h]@11

 if (_this->dword_000E24 & 0x00000002 && a2->byte_000059 == 5 && a2->ptr_000054->uFaceAttributes & 0x02)
 {
    v4 = (double)a4;
    v11 = v4;
    *a3 |= 2;
    v12 = (1.0 - _this->flt_000E28) * v4;
    if ((int)(floorf(v12 + 0.5f)) >= 0 )
    {
      v13 = (1.0 - _this->flt_000E28) * v11;
      v6 = floorf(v13 + 0.5f);
    }
    else
    {
      v6 = 0;
    }
    if ( a4 >= v6 )
    {
      v14 = (1.0 - _this->flt_000E28) * v11;
      if ((int)(floorf(v14 + 0.5f)) >= 0 )
      {
        v15 = (1.0 - _this->flt_000E28) * v11;
        result = floorf(v15 + 0.5f);
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = a4;
    }
  }
  else
  {
    result = -1;
  }
  return result;
}


//----- (0044ED0A) --------------------------------------------------------
signed int __thiscall Game_sub_44ED0A(Game *_this, struct8 *a2, int *a3, signed int a4)
{
  double v4; // st7@3
  double v5; // ST00_8@3
  signed int v6; // eax@4
  double v7; // ST00_8@5
  signed int result; // eax@7
  double v9; // ST00_8@8
  double v10; // ST00_8@10
  float v11; // [sp+14h] [bp+8h]@3
  float v12; // [sp+18h] [bp+Ch]@3
  float v13; // [sp+18h] [bp+Ch]@5
  float v14; // [sp+1Ch] [bp+10h]@8
  float v15; // [sp+1Ch] [bp+10h]@10

  if ( *(_BYTE *)((char *)_this + 3620) & 2 && *(_BYTE *)(a2 + 44) & 2 )
  {
    v4 = (double)a4;
    v11 = v4;
    *(_DWORD *)a3 |= 2;
    v12 = (1.0 - *(float *)((char *)_this + 3624)) * v4;
    v5 = v12 + 6.755399441055744e15;
    if (LODWORD(v5) >= 0 )
    {
      v13 = (1.0 - *(float *)((char *)_this + 3624)) * v11;
      v7 = v13 + 6.755399441055744e15;
      v6 = LODWORD(v7);
    }
    else
    {
      v6 = 0;
    }

    if ( a4 >= v6 )
    {
      v14 = (1.0 - *(float *)((char *)_this + 3624)) * v11;
      v9 = v14 + 6.755399441055744e15;
      if (LODWORD(v9) >= 0 )
      {
        v15 = (1.0 - *(float *)((char *)_this + 3624)) * v11;
        v10 = v15 + 6.755399441055744e15;
        result = LODWORD(v10);
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = a4;
    }
  }
  else
  {
    result = -1;
  }

  return result;
}


//----- (MM7.exe::0044F0FD) --------------------------------------------------------
int Game_fn0(struct Game *_this)
{
 Game_fn1(_this, 1 << 6);
 if (!(_this->uSomeFlags & (1 << 6)))
 {
  _this->dword_000E08 = 0;
  _this->dword_000E0C = 0;
 }
 return _this->uSomeFlags;
}

//----- (MM7.exe::0044F0D8) --------------------------------------------------------
int Game_fn1(struct Game *_this, int flags)
{
 if (_this->uSomeFlags & flags)
   _this->uSomeFlags &= ~flags;
 else
   _this->uSomeFlags |= flags;

  return _this->uSomeFlags;
}

//----- (0044F120) --------------------------------------------------------
void Game_StackStationaryLights(struct Game *_this, int a2)
{
 for (unsigned int i = 0; i < _this->uNumStationaryLights; ++i)
   pStationaryLightsStack->AddLight_Stationary(&_this->pStationaryLights[i].vPosition,
                                    _this->pStationaryLights[i].flt_000018,
                                    _this->pStationaryLights[i].vRGBColor.x,
                                    _this->pStationaryLights[i].vRGBColor.y,
                                    _this->pStationaryLights[i].vRGBColor.z,
                                    byte_4E94D0);
}

//----- (0044F192) --------------------------------------------------------
void Game_sub_44F192(struct Game *_this)
{
  int v3; // esi@2
 int i;

    v3 = (int)_this->array_000718;
  for (i = 0; i < _this->dword_000E08; ++i)
  {
      class36_sub_43B6EF(&class36_global0,
        (signed)*(float *)(v3 - 16),
        (signed)*(float *)(v3 - 12),
        (signed)*(float *)(v3 - 8),
        (signed)*(float *)(v3 + 8),
        (signed)*(float *)(v3 - 4),
        (signed)*(float *)v3,
        (signed)*(float *)(v3 + 4));
      v3 += 28;
  }
}

//----- (0044EA17) --------------------------------------------------------
bool Game_InitializeGammaController(struct Game *_this)
{
 if (dword_F79D70 != 4)
   CGammaController_InitializeFromSurface(_this->pGammaController, pD3DRenderer->pdds4_FrontBuffer);

 _this->bGammaControlInitialized = true;
 _this->uGammaControlInitializationTime = cEventTimer.Time();
 return true;
}

//----- (0040E2F6) --------------------------------------------------------
void Game_stru0_sub_40E2F6(struct Game_stru0 *_this, char a2)
{
  int v2; // esi@1
  int v3; // eax@2
  int v4; // eax@3

  v2 = (int)_this;
  if ( a2 )
  {
    v3 = (int)_this->ptr_000004;
    if ( v3 )
    {
      v4 = v3 - 1;
      if ( *(_BYTE *)v4 && *(_BYTE *)v4 != -1 )
        --*(_BYTE *)v4;
      else
        operator_delete((void *)v4);
    }
  }
  _this->ptr_000004 = 0;
  _this->dword_000008 = 0;
  _this->dword_00000C = 0;
}

//----- (0044EA5E) --------------------------------------------------------
Result::Code Game::PickMouse(float a2, unsigned int uMouseX, unsigned int uMouseY, bool bOutline, struct unnamed_F93E6C *a6, struct unnamed_F93E6C *a7)
{
 if (dword_4E28F8_PartyCantJumpIfTrue)
   return Result::Generic;

 if (uMouseX >= pOldViewport->uScreenX && uMouseX <= pOldViewport->uScreenZ &&
     uMouseY >= pOldViewport->uScreenY && uMouseY <= pOldViewport->uScreenW)
 {
  pVis->PickMouse(a2, uMouseX, uMouseY, a6, a7);
  if (bOutline)
    Game_outline_selection((int)this);
 }
 return Result::Success;
}
