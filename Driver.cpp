#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "_lod.h"
#include "Clock.h"
#include "Game.h"
#include "AudioPlayer.h"
#include "VideoPlayer.h"
#include "Thread.h"
#include "UserInput.h"
#include "Tiles.h"





//----- (004BF794) --------------------------------------------------------
void ShowIntroVideo()
{
 dword_F8BC10 = 1;
 
 Render_ClearAndPresent(pD3DRenderer, 0xFF000000);
 if (!bNoVideo)
 {
  if (!bNoCredits)
  {
   pVideoPlayer->PlayMovie("3DOLogo", 0, 0, false);
   pVideoPlayer->PlayMovie("New World Logo", 0, 0, false);
   pVideoPlayer->PlayMovie("JVC", 0, 0, false);
  }

  if (!bNoIntro)
    pVideoPlayer->PlayMovie("Intro", 0, 0, false);
 }

 dword_F8BC10 = 0;
}





//----- (00465D0B) --------------------------------------------------------
Result::Code SecondaryInitialization()
{
  _UNKNOWN *v1; // edi@3
  __int16 v3; // ax@4
  int v5; // esi@5
  int v6; // ecx@6
  int v7; // edx@7
  struct ObjectDescription *v8;
  signed int result; // eax@18
 
 char *pNames[4] = {"glow03", "glow05", "torchA", "wizeyeA"};
 int i;







 //pLODFile_Bitmaps_LOD = new LODFile;
 ///LODFile_ctor(pLODFile_Bitmaps_LOD);
 if (Result::Code eStatus = LODFile_Bitmaps_LOD.LODFile_LoadLOD_Bitmaps("data\\bitmaps.lod"))
 {
  if (eStatus == Result::NotFound)
    MessageBoxW(0, L"File not found: data\\bitmaps.lod", L"Files Missing", 48);		
  else		
    MessageBoxW(0, L"Error loading: data\\bitmaps.lod", L"Error", 48);
  return Result::Generic;
 }



 LODFile_Icons_LOD.lod_IB_dword_011BA4 = 0;
 bool bUseLoResSprites = false;

 //pLODFile_Sprites_LOD = new LODFile;
 //LODFile_ctor(pLODFile_Sprites_LOD);
 if (Result::Code eStatus = LODFile_Sprites_LOD.LODFile_LoadLOD_Sprites(bUseLoResSprites ? "data\\spriteLO.lod" : "data\\sprites.lod") )
 {
  if (eStatus == Result::NotFound)
    MessageBoxW(0, L"File not found: data\\sprites.lod", L"Files Missing", 48);		
  else		
    MessageBoxW(0, L"Error loading: data\\sprites.lod", L"Error", 48);
  return Result::Generic;
 }




 dword_6BE378_ShowDamageFlag = ReadWindowsRegistry("ShowDamage", true) != 0;

 dword_6BE384_2dacceloff = ReadWindowsRegistry("2dacceloff", false);
 byte_6BE388_graphicsmode = ReadWindowsRegistry("graphicsmode", true);
 if (byte_6BE388_graphicsmode < 0 || byte_6BE388_graphicsmode > 2)
   byte_6BE388_graphicsmode = 0;


 bAlwaysRun = ReadWindowsRegistry("valAlwaysRun", 0);
 bFlipOnExit = ReadWindowsRegistry("FlipOnExit", 0) != 0;

 pD3DRenderer->bTinting = ReadWindowsRegistry("Tinting", true);

 dword_4E2900_GammaPos = ReadWindowsRegistry("GammaPos", 4);
 if (dword_4E2900_GammaPos < 0 || dword_4E2900_GammaPos > 9)
   dword_4E2900_GammaPos = 4;

 runtime_warning(no gamma controller anymore);
 //GammaController_sub_44F4D9(pGame->pGammaController, (double)dword_4E2900_GammaPos * 0.10000000000000001 + 0.59999999999999998);

 if (ReadWindowsRegistry("Bloodsplats", 1))
   pGame->dword_000E24 |= 0x20;
 else
   pGame->dword_000E24 &= 0xFFFFFFDF;

 uTurnSpeed = ReadWindowsRegistry("TurnDelta", 0);
 switch (uTurnSpeed)
 {
  case 0:
    uTurnSpeed = (unsigned int)dword_6A0D00 < 0xC7 ? 128 : 64;
  break;

  case 1:
    uTurnSpeed = 16;// 128;
  break;

  case 2:
    uTurnSpeed = 8;// 64;
  break;

  case 3:
    uTurnSpeed = 0;
  break;
 }














 {
  void *v22;

  pSpriteFrameTable = MemAlloc(SpriteFrameTable, 1);
  SpriteFrameTable_ctor(pSpriteFrameTable);
  v22 = LODFile_Events_LOD.LODFile_LoadRaw("dsft.bin", 1);
  SpriteFrameTable_Initialize(pSpriteFrameTable, (unsigned int *)v22);
  MemFree(v22);

  pTextureFrameTable = MemAlloc(CTextureFrameTable, 1);
  CTextureFrameTable_ctor(pTextureFrameTable);
  v22 = LODFile_Events_LOD.LODFile_LoadRaw("dtft.bin", 1);
  CTextureFrameTable_Initialize(pTextureFrameTable, (unsigned char *)v22);
  MemFree(v22);

  pTileTable = MemAlloc(CTileTable, 1);
  CTileTable_ctor(pTileTable);
  v22 = LODFile_Events_LOD.LODFile_LoadRaw("dtile.bin", 1);
  CTileTable_Initialize(pTileTable, (unsigned char *)v22);
  MemFree(v22);

  pPlayerFrameTable = MemAlloc(CPlayerFrameTable, 1);
  //CPlayerFrameTable_ctor(pPlayerFrameTable);
  v22 = LODFile_Events_LOD.LODFile_LoadRaw("dpft.bin", 1);
  pPlayerFrameTable->pft_Initialize((unsigned char *)v22);
  MemFree(v22);

  //pIconFrameTable = new CIconFrameTable;
  //CIconFrameTable_ctor(pIconFrameTable);
  //v34 = LODFile_LoadRaw(pLODFile_Events_LOD, "dift.bin", 1);
  //CIconFrameTable_Initialize(pIconFrameTable, v34);
  //call_delete(v34);
#ifndef OLD_CODE  
  ImageTableLoader<IconFrame>().LoadFromFile(L"dift.bin", &pIconFrameTable);
#else
  ImageTableLoader<IconFrame>().LoadFromFile("dift.bin", &pIconFrameTable);
#endif

  pDecorationDescriptionList = MemAlloc(DecorationDescriptionList, 1);
  DecorationDescriptionList_ctor(pDecorationDescriptionList);
  v22 = LODFile_Events_LOD.LODFile_LoadRaw("ddeclist.bin", 1);
  DecorationDescriptionList_Initialize(pDecorationDescriptionList, (unsigned char *)v22);
  MemFree(v22);

  pObjectDescriptionList = MemAlloc(CObjectDescriptionList, 1);
  CObjectDescriptionList_ctor(pObjectDescriptionList);
  v22 = LODFile_Events_LOD.LODFile_LoadRaw("dobjlist.bin", 1);
  CObjectDescriptionList_Initialize(pObjectDescriptionList, (unsigned char *)v22);
  MemFree(v22);

  pMonsterDescriptionList = MemAlloc(MonsterDescriptionList, 1);
  MonsterDescriptionList_ctor(pMonsterDescriptionList);
  v22 = LODFile_Events_LOD.LODFile_LoadRaw("dmonlist.bin", 1);
  MonsterDescriptionList_Initialize(pMonsterDescriptionList, (unsigned int *)v22);
  MemFree(v22);

  //chest descriptor
  v22 = LODFile_Events_LOD.LODFile_LoadRaw("dchest.bin", 1);
  sub_458B4F(chest_descriptor, v22);
  MemFree(v22);

  pOverlayDescriptionList = MemAlloc(COverlayDescriptionList, 1);
  COverlayDescriptionList_ctor(pOverlayDescriptionList);
  v22 = LODFile_Events_LOD.LODFile_LoadRaw("doverlay.bin", 1);
  COverlayDescriptionList_Initialize(pOverlayDescriptionList, (unsigned char *)v22);
  MemFree(v22);
 }


 LODFile_Icons_LOD.SetupPalettes(5, 6, 5); //pD3DRenderer->uNumTargetRBits, pD3DRenderer->uNumTargetGBits, pD3DRenderer->uNumTargetBBits);
 class35_SetColorChannelInfo(&class35_obj, pD3DRenderer->uNumTargetRBits, pD3DRenderer->uNumTargetGBits, pD3DRenderer->uNumTargetBBits);
 class35_sub_48A614(&class35_obj);

 for (unsigned int i = 0; i < 480; ++i)
   dword_5059A8[i] = i * 640;


 Render_Reset2DClippingRect(pD3DRenderer);


  MenuUI_LoadTextures(1);










 GUICursor_sub_469C65(pGame->pGUICursor, pAppWindow);

  sub_465F5A_InitializeAsyncMouseAndSomething();
  sub_465FF0_InitializeAsyncKeyboardAndSomething();

  pClass40 = MemAlloc(class40, 1);
  sub_456D84(pClass40);
  LODFile_Bitmaps_LOD.lod_IB_dword_011BA8=1;
  LODFile_Bitmaps_LOD.SetupPalettes(5, 6, 5);//pD3DRenderer->uNumTargetRBits, pD3DRenderer->uNumTargetGBits, pD3DRenderer->uNumTargetBBits);
  
  LODFile_Icons_LOD.SetupPalettes(5, 6, 5);//pD3DRenderer->uNumTargetRBits, pD3DRenderer->uNumTargetGBits, pD3DRenderer->uNumTargetBBits);
  class35_SetColorChannelInfo(&class35_obj, pD3DRenderer->uNumTargetRBits, pD3DRenderer->uNumTargetGBits, pD3DRenderer->uNumTargetBBits);
  class35_obj.byte_267AD0 = -128;
  class35_obj.byte_267AD1 = -128;
  class35_obj.byte_267AD2 = -128;
  class35_sub_48A614(&class35_obj);
   LODFile_Sprites_LOD.dword_00ECAC = 1;

  sub_459064(pObjectDescriptionList);
  sub_458D97(pOverlayDescriptionList);
  if (!bNoSound)
    pSoundList->LoadSounds();

  v1 = &unk_4E98D4;
  for (i = 0; i < 4; ++i)
  {
   array_6A0D14[i].uIconIdx = pIconFrameTable->FindAnimation(pNames[i]);
   pIconFrameTable->InitializeAnimation(array_6A0D14[i].uIconIdx);

   array_6A0D14[i].word_000004 = 0;
   array_6A0D14[i].word_000006 = 0;
   array_6A0D14[i].word_000008 = *((_WORD *)v1 - 2);
   array_6A0D14[i].word_00000A = *(_WORD *)v1;

    v1 = (char *)v1 + 8;
  }

  for (i = 0; i < pObjectDescriptionList->uNumObjects; ++i)
  {
   v8 = &pObjectDescriptionList->pDescriptions[i];

   BYTE3(v7) = 0;
   *(_WORD *)((char *)&v7 + 1) = v8->byte_000032;
   LOBYTE(v7) = v8->byte_000033;

   v8->dword_00002C = v8->byte_000034 | (v7 << 8);
  }

  flt_6BE3A0 = 0.55000001;
  GameUI_LoadIcons();
  class06_sub_4A90A0(pGame->class06_obj);
  for (i = 0; i < 8; ++i)
  {
#ifndef OLD_CODE
  wchar_t pWaterTileName[256]; // [sp+10h] [bp-Ch]@9

  wsprintfW(pWaterTileName, L"HDWTR%03u", i);
  uTextureID_WaterTiles[i] = LODFile_Bitmaps_LOD.LODFile_LoadTexture_New( pWaterTileName);
#else
  char pWaterTileName[16]; // [sp+10h] [bp-Ch]@9

  wsprintfA(pWaterTileName, "HDWTR%03u", i);
  uTextureID_WaterTiles[i] = LODFile_Bitmaps_LOD.LODFile_LoadTexture( pWaterTileName,2);
#endif
  }

 pNPCStats = MemAlloc(CNPCStats, 1);
 CNPCStats_ctor(pNPCStats);
 CNPCStats_Initialize(pNPCStats);

 Initialize_GlobalEVT();

 LODFile_Bitmaps_LOD.lod_IB_dword_011B80 = LODFile_Bitmaps_LOD.uNumLoadedFiles;
 if (LODFile_Bitmaps_LOD.lod_IB_dword_011B84 < LODFile_Bitmaps_LOD.uNumLoadedFiles)
   LODFile_Bitmaps_LOD.lod_IB_dword_011B84 = LODFile_Bitmaps_LOD.uNumLoadedFiles;
 LODFile_Sprites_LOD.dword_00ECA4 = LODFile_Sprites_LOD.uNumLoadedSprites;
 if (LODFile_Sprites_LOD.dword_00ECA0 < LODFile_Sprites_LOD.uNumLoadedSprites)
   LODFile_Sprites_LOD.dword_00ECA0 = LODFile_Sprites_LOD.uNumLoadedSprites;

 class35_sub_48A8A3(&class35_obj);
 CreateDirectoryW(L".\\Saves", 0);
 //_mkdir("Saves");

 pStationaryLightsStack = MemAlloc(StationaryLightsStack, 1);
 memset(pStationaryLightsStack, 0, sizeof(struct StationaryLightsStack));

 result = sub_46082C();
 dword_576E28 = 9;
 dword_576E2C_uDefaultMinimapZoom = 512;


 sub_42F3D6();
 LODFile_Bitmaps_LOD.lod_IB_dword_011B84 = LODFile_Bitmaps_LOD.uNumLoadedFiles;
 LODFile_Sprites_LOD.dword_00ECA0 = LODFile_Sprites_LOD.uNumLoadedSprites;
 LODFile_Icons_LOD.lod_IB_dword_011B84 = LODFile_Icons_LOD.uNumLoadedFiles;

 return Result::Success;
}







//----- (004651F4) --------------------------------------------------------
Result::Code PrimaryInitialization()
{
 srand(GetTickCount());

 SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);
 

 cEventTimer.Initialize();
 cEventTimer.Pause();

 cMiscTimer.Initialize();
 cMiscTimer.Pause();

 sub_448B67(true);
 sub_448B45_LooksLikeResetSomeTimer(true);
 pGame = Game_Initialize();
 pGame->pGUICursor = pGame->class03_obj;


// pLODFile_Icons_LOD = new LODFile;
// LODFile_ctor(pLODFile_Icons_LOD);
 if (Result::Code eStatus = LODFile_Icons_LOD.LODFile_LoadLOD_Icons_Events("data\\icons.lod"))
 {
  if (eStatus == Result::NotFound)
    MessageBoxW(0, L"File not found: data\\icons.lod", L"Files Missing", 48);		
  else		
    MessageBoxW(0, L"Error loading: data\\icons.lod", L"Error", 48);
  return Result::Generic;
 }

 //pLODFile_Events_LOD = new LODFile;
 //LODFile_ctor(pLODFile_Events_LOD);
 if (Result::Code eStatus = LODFile_Events_LOD.LODFile_LoadLOD_Icons_Events("data\\events.lod"))
 {
  if (eStatus == Result::NotFound)
    MessageBoxW(0, L"File not found: data\\events.lod", L"Files Missing", 48);		
  else		
    MessageBoxW(0, L"Error loading: data\\events.lod", L"Error", 48);
  return Result::Generic;
 }

 InitializeGameText();


 wchar_t pGameDirectory[256],
         pMM6ConfigFilename[120];
 GetCurrentDirectoryW(255, pGameDirectory);
 wsprintfW(pMM6ConfigFilename, L"%s\\mm6.ini", pGameDirectory);
 ReadMM6_ini(pMM6ConfigFilename);



 sub_4666D5();

#if 0
 pD3DRenderer = MemAlloc(RenderOpenGL, 1);
#else
 pD3DRenderer = MemAlloc(RenderDirect3D3, 1);
#endif
 pD3DRenderer->Initialize(pAppWindow);


 pAudioPlayer = nullptr;
 if (!bNoSound)
 {
  pAudioPlayer = MemAlloc(AudioPlayer, 1);
  pAudioPlayer->Initialize(pAppWindow, cGameCDDriveLetter);


  dword_6BE374_WalkSoundFlag = ReadWindowsRegistry("WalkSound", true) != 0;

  uSoundVolumeMultiplier = ReadWindowsRegistry("soundflag", 9);
  if (uSoundVolumeMultiplier < 0 || uSoundVolumeMultiplier > 9)
    uSoundVolumeMultiplier = 9;
 
  uVoicesVolumeMultiplier = ReadWindowsRegistry("CharVoices", 9);
  if (uVoicesVolumeMultiplier < 0 || uVoicesVolumeMultiplier > 9)
    uVoicesVolumeMultiplier = 9;

  uMusicVolimeMultiplier = ReadWindowsRegistry("musicflag", 9);
  if (uMusicVolimeMultiplier < 0 || uMusicVolimeMultiplier > 9)
    uMusicVolimeMultiplier = 9;

  pAudioPlayer->SetMasterVolume(128.0f * pSoundVolumeLevels[uSoundVolumeMultiplier]);
  pAudioPlayer->SetMusicVolume(64.0f * pSoundVolumeLevels[uMusicVolimeMultiplier]);
 }
 else		
 {		
  dword_6BE374_WalkSoundFlag = false;

  uSoundVolumeMultiplier = 0;
  uVoicesVolumeMultiplier = 0;
  uMusicVolimeMultiplier = 0;
 }

 pVideoPlayer = nullptr;
 if (!bNoVideo)
 {
  pVideoPlayer = MemAlloc(VideoPlayer, 1);
  pVideoPlayer->Initialize(pAppWindow, pD3DRenderer, pAudioPlayer);
 }

 dword_6BE364 |= 0x4000;
 RegistryWriteInt("Ran once", true);

 dword_507988 = LODFile_Icons_LOD.LODFile_LoadTexture("FONTPAL", 2);

 pFontArrus = LoadFont("arrus.fnt", "FONTPAL");
 pFontArrus->byte_000002[0] = 0;

 pFontLucida = LoadFont("lucida.fnt", "FONTPAL");
 pFontLucida->byte_000002[0] = 0;

 pFontCreate = LoadFont("create.fnt", "FONTPAL");
 pFontCreate->byte_000002[0] = 0;

 pFontComic = LoadFont("comic.fnt", "FONTPAL");
 pFontSmallnum = LoadFont("smallnum.fnt", "FONTPAL");

 sLastGUIWindowIdx = -1;
 memset(array_5075E0, 0, 20 * sizeof(int));
 for (unsigned int i = 0; i < 20; ++i)
   GUIWindow_List[i].uWindowType = 0;


 return Result::Success;
}


//----- (00 ) --------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  long pWindowDims[4];

  signed int v9; // edi@44
  signed __int64 v12; // qax@55
  HANDLE hProcess; // eax@68
  int v16; // [sp+8h] [bp-24h]@55
  RECT _Rect; // [sp+Ch] [bp-20h]@15


 HWND hPreviouslyActiveWindow = GetActiveWindow();

 if (lpCmdLine)
 {
  if (lpCmdLine[0])
  {
   if (strstr(lpCmdLine, "-usedefs"))
     bUseOverrideData = true;
   if (strstr(lpCmdLine, "-window"))
     dword_6BE368 |= 0x01;

   if (strstr(lpCmdLine, "-nosound"))
   {
    bNoSound = true;
    bNo3DSound = true;
   }
   else if (strstr(lpCmdLine, "-no3dsound"))
     bNo3DSound = true;

   if (strstr(lpCmdLine, "-noanim"))
     dword_6BE364 |= 0x40;


   if (strstr(lpCmdLine, "-novideo"))
     bNoVideo = true;
   
   if (strstr(lpCmdLine, "-nocredits"))
     bNoCredits = true;

   if (strstr(lpCmdLine, "-nointro"))
     bNoIntro = true;

   if (!strstr(lpCmdLine, "-nocd"))
   {
    if (!CheckForMM7CD(&cGameCDDriveLetter))
      return 0;

    bCanLoadFromCD = true;
   }
   else bCanLoadFromCD = false;
  }
 }

 
 AllocConsole();

 pAppWindow = MemAlloc(Win32Window, 1);
 if (pAppWindow->Initialize(L"MM7cls", L"Might and Magic® VII", WindowCreationParams::Framed | ::WindowCreationParams::Unique))
 {
  MemFree(pAppWindow);
  return 0;
 }

 unsigned int uWindowPosX = ReadWindowsRegistry("window X", 0),
              uWindowPosY = ReadWindowsRegistry("window Y", 0);
 if (uWindowPosX >= GetSystemMetrics(SM_CXSCREEN))
   uWindowPosX = 0;
 if (uWindowPosY >= GetSystemMetrics(SM_CYSCREEN))
   uWindowPosY = 0;


 Rect<float> wndArea = Rect<float>(uWindowPosX, uWindowPosX + 640,
                                   uWindowPosY, uWindowPosY + 480);
 pAppWindow->SetClientArea(&wndArea);
 pAppWindow->Show();

 RtlCallCtors();

 //ACHTUNG    4AC1C9 needs refactoring
 sub_4AC1C9(0, pWindowDims);
 _Rect.left = pWindowDims[0];
 _Rect.top = pWindowDims[1];
 _Rect.right = pWindowDims[2];
 _Rect.bottom = pWindowDims[3];
 dword_6A0D00 = _Rect.bottom;

 hInstance = hInst;
 if (!PrimaryInitialization())
 {
  ShowIntroVideo();
  if (!bNoSound)
    pAudioPlayer->PlayMusicTrack(14, 64.0f * pSoundVolumeLevels[uMusicVolimeMultiplier]);



  extern void LoadUI_MainMenu();
  LoadUI_MainMenu();

  OSThread *pLoadingThread = MemAlloc(Win32Thread, 1);
  pLoadingThread->Initialize();
  pLoadingThread->Execute(SecondaryInitialization, true);

  DWORD uLastTime,
        uNewTime = GetTickCount();
  uLastTime = uNewTime;
  while (pLoadingThread->IsBusy())
  {
   float dt = (GetTickCount() - uLastTime) / 1000.0f;

   uLastTime = uNewTime;
   uNewTime = GetTickCount();

   pMainGUI->Update(dt);

   pD3DRenderer->BeginScene();
   {
    pMainGUI->Draw(0);
   }
   pD3DRenderer->EndScene();
   pD3DRenderer->Present();
   Sleep(250);
  }
  pLoadingThread->Release();
  MemFree(pLoadingThread);



  Sleep(250);
  while (true)
    {
      MenuLoop_Main();
LABEL_21:
      dword_6A0D48 = 0;
      while ( 1 )
      {
        if ( dword_6A0D48 == 1 )
          goto LABEL_68;
        if (uCurrentMenuID == MENU_NEWGAME)
        {
         if (!bNoSound)
           pAudioPlayer->StopMusic();

          Party_Reset(pParty_global);

          for (v9 = 0; v9 < 50; ++v9)
            sub_45855F(array_5E4D58[v9++]);

          Party_CreateDefaultParty(pParty_global, 0);

          PlayerCreationUI_Initialize();
          if (MenuLoop_CharacterCreation())
          {
            DeleteFontCChar();
            goto LABEL_53;
          }

          //DeleteFontCChar();
          byte_50794A = 1;

          //if (!bNoVideo)
          //  pVideoPlayer->PlayMovie("Intro Post", 0, 0, false);

          runtime_warning(tries to save not yet loaded level; need to rethink this mechanism);

          pGame->PrepareForLoop("out01.odm");
          pGame->Loop("out01.odm");

          goto LABEL_49;
        }
        if (uCurrentMenuID == MENU_CREDITS)
          break;
        if ( uCurrentMenuID == 4 )
        {
          dword_6A0D48 = 1;
          goto LABEL_49;
        }
        if ( uCurrentMenuID == 5 || uCurrentMenuID == 9 )
        {
          dword_6A0D48 = 0;
        }
        else
        {
          if ( uCurrentMenuID != 10 )
            goto LABEL_49;
          GUICursor_fn1(pGame->pGUICursor, 0);
          
    runtime_warning(async input);
          /*if (pAsyncMouse)
            CAsyncMouse_suspend(pAsyncMouse);
          
          if (pGame->Win32Keyboard_obj->dword_000004 & 0xFF)
          {
            if (pAsyncKeyboard)
              CAsyncKeyboard_suspend(pAsyncKeyboard);
          }*/
          Party_Reset(pParty_global);
          Party_CreateDefaultParty(pParty_global, 1);
          sub_46271C();
          if ( !GetOpenFileNameA(&stru_6A0DA0) )
          {
            GUICursor_fn1(pGame->pGUICursor, 1);
            
    runtime_warning(async input);
            /*if (pAsyncMouse)
              CAsyncMouse_sub_46B105((void*)pAsyncMouse);
            if (pGame->Win32Keyboard_obj->dword_000004 & 0xFF)
            {
              if (pAsyncKeyboard)
                CAsyncKeyboard_Resume(pAsyncKeyboard);
            }*/
            goto LABEL_53;
          }
          SetCurrentDirectoryW(L"..\\");

          compile_error(level file name should not be global);
         //strcpy(CurrentLevelName, stru_6A0DA0.lpstrFileTitle);

          GUICursor_fn1(pGame->pGUICursor, 1);
    runtime_warning(async input);
          /*if (pAsyncMouse)
            CAsyncMouse_sub_46B105((void*)pAsyncMouse);
          if (pGame->Win32Keyboard_obj->dword_000004 & 0xFF)
          {
            if (pAsyncKeyboard)
              CAsyncKeyboard_Resume(pAsyncKeyboard);
          }*/
        }
    compile_error(level name should not be globally-defined);
    //sub_463149();

LABEL_49:
        if ( dword_6A0D48 == 3 )
        {
          SetCurrentMenu(5);
          goto LABEL_21;
        }
        if ( dword_6A0D48 == 4 )
        {
          SetCurrentMenu(MENU_NEWGAME);
          goto LABEL_21;
        }
        if ( dword_6A0D48 == 7 )
        {
          pAudioPlayer->MessWithChannels(&Range<unsigned int>(0, 16));
          dword_6A0D48 = 0;
          goto LABEL_53;
        }
      }

      if (!bNoSound)
        pAudioPlayer->StopMusic();

      CreditsMenuLoop();
LABEL_53:
      if (!bNoSound)
          pAudioPlayer->PlayMusicTrack(14, 64.0f * pSoundVolumeLevels[uMusicVolimeMultiplier]);
    }
  }
LABEL_68:
  hProcess = GetCurrentProcess();
  SetPriorityClass(hProcess, NORMAL_PRIORITY_CLASS);
  Game_Deinitialize();

 if (hPreviouslyActiveWindow)
   SetActiveWindow(hPreviouslyActiveWindow);
 return 0;
}































/*
#include "Render\\Render.h"
#include "OSWindow.h"
#include "Camera.h"




Camera *pGameCamera = 0;

OSWindow *pDxWindow = 0,
         *pOglWindow = 0;
Render   *pDxRender = 0,
         *pOglRender = 0;

void Game_Initialize()
{
 pGameCamera = new Camera;
 pGameCamera->Initialize(&Vec3(0, 0, 0), &Quaternion(1, 0, 0, 0));
 pGameCamera->SetProjection(3.14159f * (45.0 / 360.0), 1024.0 / 768.0, 0.1, 1000.0);

 Rect<float> dxWindowArea = Rect<float>(400, 0, 1200, 600);
 Rect<float> dxRenderArea = Rect<float>(0, 0, 800, 600);

 pDxWindow = new Win32Window;
 pDxWindow->Initialize(L"MM7w2dx", L"MM7 C++ Direct3D10 Render", true);
 pDxWindow->SetClientArea(&dxWindowArea);
 pDxWindow->Show();

 pDxRender = CreateDirect3D10Render();
 pDxRender->Initialize();
 pDxRender->Reset(pDxWindow, false, &dxRenderArea);



 //struct Viewport oglWindowArea =
 //{
 // 450,   300,
 // 1250,  990,
 // 0,    0
 //};

 //struct Viewport oglRenderArea =
 //{
 // 0,    0,
 // 800,  600,
 // 0,    0
 //};

 //pOglWindow = new Win32Window;
 //pOglWindow->Initialize(L"MM7w2ogl", L"MM7 C++ OpenGL 3.2 Render", true);
 //pOglWindow->SetClientArea(&oglWindowArea);
 //pOglWindow->Show();

 //pOglRender = CreateOpenGL32Render();
 //pOglRender->Initialize();
 //pOglRender->Reset(pOglWindow, false, &oglRenderArea);

 extern void InitializeRenderOperators();
 InitializeRenderOperators();
}





RenderOperator                 *pDxRoot = 0;
RenderOperator_Clear           *pDxClearColorOperator = 0,
                               *pDxClearDepthOperator = 0;
RenderOperator_DrawEnvironment *pDxDrawEnvironmentOperator = 0;
RenderOperator_DrawTerrain     *pDxDrawTerrainOperator = 0;
RenderOperator_Present         *pDxPresentOperator = 0;
Texture                        *pDxEnvTexture,
                               *pDxHeightmapTexture;

RenderOperator         *pOglRoot = 0;
RenderOperator_Clear   *pOglClearColorOperator = 0,
                       *pOglClearDepthOperator = 0;
RenderOperator_Present *pOglPresentOperator = 0;

void Game_Process_cpp()
{
 //dirty dirty hack
 {
  static bool first_run = true;
  static POINT old_pos = {0},
               new_pos = {0};
  if (first_run)
  {
   first_run = false;
   GetCursorPos(&old_pos);
   GetCursorPos(&new_pos);
  }
  else
  {
   old_pos.x = new_pos.x;
   old_pos.y = new_pos.y;
   GetCursorPos(&new_pos);
  
   if (old_pos.x - new_pos.x)
     pGameCamera->RotateY(-(old_pos.x - new_pos.x) * 0.0125f);
   if (old_pos.y - new_pos.y)
     pGameCamera->RotateX(-(old_pos.y - new_pos.y) * 0.0125f);

   float fMovementAmount = 7.5;
   if (GetAsyncKeyState(VK_LSHIFT))
     fMovementAmount *= 2.25f;

   if (GetAsyncKeyState('W'))
     pGameCamera->Move(fMovementAmount);
   else if (GetAsyncKeyState('S'))
     pGameCamera->Move(-fMovementAmount);
  }
 }

 //pGameCamera->RotateX(0.01250f);

 while (pDxWindow->Update(0));
 pDxRoot->Execute();
 //while (pOglWindow->Update(0));
 //pOglRoot->Execute();
}





void InitializeRenderOperators()
{
 pDxRender->CreateTextureCube(L"data\\new\\cubemap-evul.dds", &pDxEnvTexture);
 pDxRender->CreateTexture(L"data\\new\\Emerald Island.png", &pDxHeightmapTexture);

 Texture *pDxPrimaryColorTarget,
         *pDxPrimaryDepthTarget;
 pDxRender->GetPrimaryColorTarget(&pDxPrimaryColorTarget);
 pDxRender->GetPrimaryDepthTarget(&pDxPrimaryDepthTarget);

 float pDxColorClear[4] = {0.5, 0.5, 0.5, 1},
       pDxDepthClear[4] = {1, 0, 0, 0};

 pDxClearColorOperator = pDxRender->CreateClearOperator();
 pDxClearColorOperator->Initialize(pDxRender, pDxPrimaryColorTarget, pDxColorClear);

 pDxClearDepthOperator = pDxRender->CreateClearOperator();
 pDxClearDepthOperator->Initialize(pDxRender, pDxPrimaryDepthTarget, pDxDepthClear);

 pDxDrawEnvironmentOperator = pDxRender->CreateDrawEnvironmentOperator();
 pDxDrawEnvironmentOperator->Initialize(pDxRender, pDxEnvTexture, pGameCamera);

 pDxDrawTerrainOperator = pDxRender->CreateDrawTerrainOperator();
 pDxDrawTerrainOperator->Initialize(pDxRender, pDxHeightmapTexture, 256, 256, 15, pGameCamera);

 pDxPresentOperator = pDxRender->CreatePresentOperator();
 pDxPresentOperator->Initialize(pDxRender);

 
 pDxRoot = pDxDrawEnvironmentOperator;

 //pDxRoot = pDxClearColorOperator;
 //pDxRoot->pChildren = pDxClearDepthOperator;
 //pDxClearDepthOperator->pChildren = pDxDrawEnvironmentOperator;
 pDxDrawEnvironmentOperator->pChildren = pDxDrawTerrainOperator;
 pDxDrawTerrainOperator->pChildren = pDxPresentOperator;
 pDxPresentOperator->pChildren = 0;



 //Texture *pOglPrimaryColorTarget,
 //        *pOglPrimaryDepthTarget;
 //pOglRender->GetPrimaryColorTarget(&pOglPrimaryColorTarget);
 //pOglRender->GetPrimaryDepthTarget(&pOglPrimaryDepthTarget);

 //float pOglColorClear[4] = {0.75, 0.75, 0.75, 1},
 //      pOglDepthClear[4] = {1, 0, 0, 0};

 //pOglClearColorOperator = pOglRender->CreateClearOperator();
 //pOglClearColorOperator->Initialize(pOglRender, pOglPrimaryColorTarget, pOglColorClear);

 //pOglClearDepthOperator = pOglRender->CreateClearOperator();
 //pOglClearDepthOperator->Initialize(pOglRender, pOglPrimaryDepthTarget, pOglDepthClear);

 //pOglPresentOperator = pOglRender->CreatePresentOperator();
 //pOglPresentOperator->Initialize(pOglRender);

 //pOglRoot = pOglClearColorOperator;
 //pOglClearColorOperator->pChildren = pOglClearDepthOperator;
 //pOglClearDepthOperator->pChildren = pOglPresentOperator;
 //pOglPresentOperator->pChildren = 0;
}
*/