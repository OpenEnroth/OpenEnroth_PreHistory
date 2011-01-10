#include <io.h>
#include "localization_defs.h"
#include "defs.h"
#include "menus.h"

#include "_lod.h"
#include "clock.h"
#include "data.h"
#include "AudioPlayer.h"
#include "VideoPlayer.h"
#include "FrameTables.h"
#include "Vis.h"

#include "GUI\GUI.h"

#include "Environment\Outdoor.h"
#include "Actor.h"
#include "UserInput.h"
 
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

int dword_4E94D4[2] = { 82,   0}; // weak
int dword_4E94DC[2] = { 60,   0}; // weak
int dword_4E94E4[2] = {460, 640}; // weak
int dword_4E94EC[2] = {344, 480}; // weak

struct save_struct01
	{
	int data1;
	char signature[4];
	int data2;
	int data3;
	};

 int uGUIx_u; // weak	 dword_69CEFC
 int uGUILS_saveU; // weak
 int uGUILS_loadU; // weak dword_69CF04
 int uGUIar_dn_dn; // weak	dword_69CF08
 int uGUIar_up_dn; // weak	 dword_69CF0C
 int uGUIL_S_txtr; // weak	dword_69CF10
 int uGUIx_d; // weak	 dword_69CF14
 int uGUISaveUp; // weak  dword_69CF18
 int uGUILoadUp; // weak dword_69CF1C
 int uGUILoadSave; // weak	 dword_69CF20
 int uSaveFileCount; // idb	dword_69CF24

 int dword_69CF28[45]; // weak

 Save_files_list saves_lst;	  // unk_69CFE0	[20]  +	  byte_69CFF4[11200]
 Save_Header     saves_hdr[40];	  //unk_69BD68

cPCXTexture cSaveTumbnail[45]; // weak  [1800]	  45*0x28	 unk_6A0118		dword_6A013C
 //  _UNKNOWN unk_6A0758; // weak	 end  
//_UNKNOWN unk_6A07A4; //end pPixels

LOD_Writefile LODFile_New_LOD;   // struct @ MM7.exe::006A0820



LOD_Writefile LODFile_Games_LOD; // struct @ MM7.exe::006A0A60

 int dword_6A0C9C;
 int dword_6A0CA0_indx; // weak 

struct GUIButton *pArrowDownBtn; // weak	  dword_69BD58
struct GUIButton *pArrowUpBtn; // weak	 dword_69BD5C
struct GUIButton *pCancelBtn; // weak	  dword_69BD60
struct GUIButton *pLoadSaveBtn; // weak	   dword_69BD64





//----- (0045E93E) --------------------------------------------------------
int __cdecl sub_45E93E()
{
  int v0; // eax@4
  int v1; // ebp@4
  int v2; // ebp@6
  signed int v3; // eax@7
  FILE *v4; // eax@11
  FILE *v5; // eax@11
  const char *v6; // ST64_4@14
  int v8; // eax@16
  signed int v9; // [sp+10h] [bp-254h]@6
  char *v10; // [sp+14h] [bp-250h]@6
  void *v11; // [sp+18h] [bp-24Ch]@6
  LOD_Writefile v12; // [sp+1Ch] [bp-248h]@1
  int v13; // [sp+260h] [bp-4h]@1

 // v12=new(LOD_Writefile);
  ++LODFile_Icons_LOD.uTexturePacksCount;
  v13 = 0;
  if ( !LODFile_Icons_LOD.uPrevLoadedFiles )
    LODFile_Icons_LOD.uPrevLoadedFiles = LODFile_Icons_LOD.uNumLoadedFiles;
  memset(dword_69CF28, 0, 45*sizeof(int));
  memset(&cSaveTumbnail[0], 0, 1800);
  uGUILoadSave = LODFile_Icons_LOD.LODFile_LoadTexture("loadsave", 2);		  //dword_69CF20
  uGUILoadUp   = LODFile_Icons_LOD.LODFile_LoadTexture("load_up", 2);		   //dword_69CF1C
  uGUISaveUp   = LODFile_Icons_LOD.LODFile_LoadTexture("save_up", 2);		  // dword_69CF18
  uGUILS_loadU = LODFile_Icons_LOD.LODFile_LoadTexture("LS_loadU", 2);		   //dword_69CF04 
  uGUILS_saveU = LODFile_Icons_LOD.LODFile_LoadTexture("LS_saveU", 2);		  //dword_69CF00
  uGUIx_u      = LODFile_Icons_LOD.LODFile_LoadTexture("x_u", 2);			   //dword_69CEFC
  Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (uGUILoadSave != -1 ? &LODFile_Icons_LOD.aLODHeaders[uGUILoadSave] : 0));
  if ( dword_4E28F8_PartyCantJumpIfTrue == 11 )
  {
    v1 = uGUISaveUp;
    v0 = uGUILS_saveU;
  }
  else
  {
    v1 = uGUILoadUp;
    v0 = uGUILS_loadU;
  }
  Render_DrawIndexedTexture(pD3DRenderer, 241, 302, (v0 != -1 ? &LODFile_Icons_LOD.aLODHeaders[v0] : 0));
  Render_DrawIndexedTexture(pD3DRenderer, 351, 302, (uGUIx_u != -1 ? &LODFile_Icons_LOD.aLODHeaders[uGUIx_u] : 0));
  Render_DrawIndexedTexture(pD3DRenderer,  18, 141, (v1 != -1 ? &LODFile_Icons_LOD.aLODHeaders[v1] : 0));
  FontDrawText(pGUIWindow_CurrentMenu, pFontSmallnum, 25, 199, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_READING], 0, 0, 0);
  pD3DRenderer->Present();
  sub_45E297(1);
  v12.AllocateSubidexAndIOBuffer( 300, 0);
  v2 = (int)dword_69CF28;
  v10 = (char *)&saves_hdr[0].name1;
  v11 = &cSaveTumbnail[0];
 // v9 = (signed int)byte_69CFF4;
/*  do
  {
    v3 = v9;
    if ( !*(_BYTE *)v9 )
      v3 = (signed int)"1.mm7";
    wsprintfA((char *)TmpBuf, "saves\\%s", v3);
    if ( _access((char *)TmpBuf, 0) || _access((char *)TmpBuf, 6) )
    {
      v6 = (char *)pGlobalTXT_LocalizationStrings[72];
      *(_DWORD *)v2 = 0;
      strcpy(v10, v6);
    }
    else
    {
      v12->Load_File( (char *)TmpBuf, 1);
      v5 = v12->Find_Container( "header.bin", 1);
      locked_fread(v10, 0x64u, 1u, (FILE *)v5);
      v4 = v12->Find_Container( "image.pcx", 1);
      if ( v4 )
      {
        sub_40EAD8(v11, (FILE *)v4, 0, 1);
        v12->Close_Written_File();
        *(_DWORD *)v2 = 1;
      }
      else
      {
        *(_DWORD *)v2 = 0;
      }
    }
    v9 += 280;
    v11 = (char *)v11 + 40;
    v10 += 100;
    v2 += 4;
  }
  while ( v9 < (signed int)&unk_69FBB4 );  */
  v12.FreeSubIndxIOBuffers();
  uGUIx_d      = LODFile_Icons_LOD.LODFile_LoadTexture( "x_d", 2);
  uGUIL_S_txtr = LODFile_Icons_LOD.LODFile_LoadTexture( "LS_saveD", 2);
  uGUIar_up_dn = LODFile_Icons_LOD.LODFile_LoadTexture( "AR_UP_DN", 2);
  uGUIar_dn_dn = LODFile_Icons_LOD.LODFile_LoadTexture( "AR_DN_DN", 2);
  pGUIWindow_CurrentMenu = GUIWindowCreate(0, 0, 640, 480, 23, 0, 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 21, 198, 191, 18, 1, 0, 165, 0, 0, NULL, 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 21, 218, 191, 18, 1, 0, 165, 1, 0, NULL, 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 21, 238, 191, 18, 1, 0, 165, 2, 0, NULL, 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 21, 258, 191, 18, 1, 0, 165, 3, 0, NULL, 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 21, 278, 191, 18, 1, 0, 165, 4, 0, NULL, 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 21, 298, 191, 18, 1, 0, 165, 5, 0, NULL, 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu, 21, 318, 191, 18, 1, 0, 165, 6, 0, NULL, 0);
  pLoadSaveBtn = 
  GUIButtonCreate(pGUIWindow_CurrentMenu,241, 302, 105, 40, 1, 0, 164, 0, 0, NULL,
                   uGUIL_S_txtr != -1 ?  &LODFile_Icons_LOD.aLODHeaders[uGUIL_S_txtr] : 0);
  pCancelBtn = 
  GUIButtonCreate(pGUIWindow_CurrentMenu,350, 302, 105, 40, 1, 0, 166, 0, 0, NULL,
                   uGUIx_d != -1 ?  &LODFile_Icons_LOD.aLODHeaders[uGUIx_d] : 0);
  pArrowUpBtn = 
  GUIButtonCreate(pGUIWindow_CurrentMenu,215, 199,  17, 17,	1, 0, 162, 0, 0, NULL,
                   uGUIar_up_dn != -1 ?  &LODFile_Icons_LOD.aLODHeaders[uGUIar_up_dn] : 0);
  pArrowDownBtn = 
  GUIButtonCreate(pGUIWindow_CurrentMenu,215, 323,  17, 17,	1, 0, 163,34, 0, NULL,
                   uGUIar_dn_dn != -1 ?  &LODFile_Icons_LOD.aLODHeaders[uGUIar_dn_dn] : 0);
 
  return 0/*sub_461790((int)&v12)*/;
}

//----- (0045EE8A) -------.text:00460131  -------------------------------------------------
bool sub_45EE8A_LoadGame(const char *pFilename, unsigned int idx)
{
  //int v1; // ebx@1
  char v2; // zf@1
  int v4; // esi@8
  int v5; // eax@9
  int v6; // eax@12
  int v7; // esi@13
  int v8; // ecx@14
  FILE *v9; // eax@22
  FILE *v10; // eax@26
  FILE *v11; // eax@29
  FILE *v12; // eax@32
  FILE *v13; // eax@35
  FILE *v14; // eax@38
  int v15; // edi@41
  int v16; // esi@41
  int v17; // ebx@46
  int v18; // edi@46
  int *v19; // esi@46
  int v20; // ecx@49
  int v21; // eax@51
  int v22; // ecx@56
  //int v23; // ebx@60
  bool v24; // eax@62
  signed int v25; // esi@62
  char *v26; // eax@66
  int v27; // esi@66
  int v28; // edi@67
  int result; // eax@71
  int v31; // [sp-18h] [bp-108h]@25
  int v32; // [sp-14h] [bp-104h]@25
  int v33; // [sp-10h] [bp-100h]@25
  int v34; // [sp-Ch] [bp-FCh]@25
  int v35; // [sp-8h] [bp-F8h]@4
  int v36; // [sp-4h] [bp-F4h]@4
  Save_Header loc_hdr;
  //char DstBuf; // [sp+Ch] [bp-E4h]@23
  //char Source[80]; // [sp+20h] [bp-D0h]@62

  char Str; // [sp+70h] [bp-80h]@25
  int v40; // [sp+E8h] [bp-8h]@2

  
  wsprintfA((char *)TmpBuf, "saves\\%s", pFilename);
  if (_access((char *)TmpBuf, 0))
    return false;

  v2 = dword_69CF28[idx] == 0;
  dword_5B65C8 = 0;
  if ( v2 )
    pAudioPlayer->sub_4AA306(27, 0, 0, -1, 0, 0, 0, 0);
  else
  {
   for (unsigned int i = 0; i < 4; ++i)
     for (unsigned int j = 0; j < 5; ++j)
     {
      wsprintfA((char *)TmpBuf, "data\\lloyd%d%d.pcx", i + 1, j + 1);
      remove((char *)TmpBuf);
     }


    for (unsigned int i = 0; i < 4; ++i)
    {
      v40 = (int)&pParty->pPlayers[i];
      if ( byte_4ED498 )
      {
        v4 = 0;
        if ( pSoundList->uNumSounds <= 0 )
        {
LABEL_12:
          v6 = 0;
        }
        else
        {
         v5 = (int)pSoundList->pSounds + 32;
          while ( *(_DWORD *)v5 != 2 * ((unsigned __int8)byte_4ED498 + 50 * *(_DWORD *)(v40 + 6432)) + 4998 )
          {
            ++v4;
            v5 += 120;
            if ( v4 >= pSoundList->uNumSounds )
              goto LABEL_12;
          }
          v6 = v4;
        }
        SoundList_sub_4A9DCD((int)pSoundList, v6, 1);
        v7 = 0;
        if ( pSoundList->uNumSounds <= 0 )
        {
LABEL_17:
          v7 = 0;
        }
        else
        {
          v8 = (int)pSoundList->pSounds + 32;
          while ( *(_DWORD *)v8 != 2 * ((unsigned __int8)byte_4ED498 + 50 * *(_DWORD *)(v40 + 6432)) + 4999 )
          {
            ++v7;
            v8 += 120;
            if ( v7 >= pSoundList->uNumSounds )
              goto LABEL_17;
          }
        }
        SoundList_sub_4A9DCD((int)pSoundList, v7, 1);
      }
    }

    wsprintfA((char *)TmpBuf, "saves\\%s", pFilename);
    LODFile_New_LOD.Close_Written_File();
    CopyFileA((char *)TmpBuf, "data\\new.lod", 0);
    LODFile_New_LOD.Load_File("data\\new.lod", 0);
    v9 = LODFile_New_LOD.Find_Container("header.bin", 1);
    if ( v9 )
    {
      locked_fread(&loc_hdr,100, 1, v9);
    }
    else
    {
      wsprintfA((char *)&Str, (char *)pGlobalTXT_LocalizationStrings[612], 100);
      Game_sub_40E2C8(&v31, &Str, (int)((char *)&v40 + 3));
      sub_466D09((char *)&v40 + 4, *(int *)&v31, v32, v33, v34, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }
    v10 = LODFile_New_LOD.Find_Container("party.bin", 1);
    if ( v10 )
    {
      locked_fread(pParty, 90680, 1, v10);
    }
    else
    {
      wsprintfA(&Str, (char *)pGlobalTXT_LocalizationStrings[612], 101);
      Game_sub_40E2C8(&v31, &Str, (int)((char *)&v40 + 3));
      sub_466D09((char *)&v40 + 4, *(int *)&v31, v32, v33, v34, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }
    v11 = LODFile_New_LOD.Find_Container("clock.bin", 1);
    if ( v11 )
    {
      locked_fread(&cEventTimer, 40, 1, v11);
    }
    else
    {
      wsprintfA(&Str, (char *)pGlobalTXT_LocalizationStrings[612], 102);
      Game_sub_40E2C8(&v31, &Str, (int)((char *)&v40 + 3));
      sub_466D09((char *)&v40 + 4, *(int *)&v31, v32, v33, v34, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }
    v12 = LODFile_New_LOD.Find_Container("overlay.bin", 1);
    if ( v12 )
    {
      locked_fread(&stru_5E4D58, 1008, 1, v12);
    }
    else
    {
      wsprintfA(&Str, (char *)pGlobalTXT_LocalizationStrings[612], 103);
      Game_sub_40E2C8(&v31, &Str, (int)((char *)&v40 + 3));
      sub_466D09((char *)&v40 + 4, *(int *)&v31, v32, v33, v34, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }
    v13 = LODFile_New_LOD.Find_Container( "npcdata.bin", 0);
    if ( v13 )
    {
      locked_fread(pNPCStats->pNPCData2, 501 * sizeof(struct NPCData), 1, v13);
      NPCStats_sub_476C60((int)pNPCStats);
    }
    else
    {
      wsprintfA(&Str, (char *)pGlobalTXT_LocalizationStrings[612], 104);
      Game_sub_40E2C8(&v31, &Str, (int)((char *)&v40 + 3));
      sub_466D09((char *)&v40 + 4, *(int *)&v31, v32, v33, v34, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }
    v14 = LODFile_New_LOD.Find_Container( "npcgroup.bin", 0);
    if ( v14 )
    {
      locked_fread(pNPCStats->npc_group, 102, 1, v14);
    }
    else
    {
      wsprintfA(&Str, (char *)pGlobalTXT_LocalizationStrings[612], 105);
      Game_sub_40E2C8(&v31, &Str, (int)((char *)&v40 + 3));
      sub_466D09((char *)&v40 + 4, *(int *)&v31, v32, v33, v34, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }

   for (unsigned int i = 0; i < 4; ++i) 
      if (Player_sub_492C0B_MaybeIfPlayerConscious(&pParty->pPlayers[i]))
      {
       uActiveCharacter = i + 1;
       break;
      }
  
//    v19 = pParty->pPlayers[];  //global_paarty playersu QuickSpell		 (int *)&unk_ACF3D3
    v18 = 9;
    v17 = 0;
   for (unsigned int i = 0; i < 4; ++i)
    {
      if ( pParty->pPlayers[i].uQuickSpell )
        sub_494836((char *)unk_AA1058[i][0], pParty->pPlayers[i].uQuickSpell, i+1);
     v40 = 0;
      //v20 = (int)((char *)v19 - 263);
	  v20 = 0;
      while ( 1 )
      {
       int item_index = pParty->pPlayers[i].cEquippedItems.pIndices[v20]; 
        if (item_index)
        {
         // v21 = *(int *)((char *)&v19[9 * *(_DWORD *)v20 - 1559]);
		  v21 = pParty->pPlayers[i].pInventorySlots[item_index + 5].uItemID; //5 offset	need to verify
          if (pClass40->pItems[v21 - 1].uEquipType == 12 )
			  {
			  // v36 = v18;
               v35 = dword_4E421C[v21];
               sub_494836((char *)&unk_A750F8[i][0], v35, i+9);	//v18
                break;
			  }
        }
        v40 += 1;
        v20 ++;
        if ( v40 > 1 )
          break	;
      }
    
    //  v19 += 1743;

    //  ++v18;
     // v17 += 45016;
    }
 //   while ( v18 - 9 < 4 );


    GUIWindowDelete(pGUIWindow_CurrentMenu);
    dword_4E28F8_PartyCantJumpIfTrue = 0;
    v22 = 1;
    struct_576FE8.dword_000044 = 1;
    if ( pParty->uAlignment )
    {
      if ( pParty->uAlignment == 2 )
        v22 = 2;
    }
    else
    {
      v22 = 0;
    }
    MenuUI_LoadTextures(v22);
    cEventTimer.Resume();
    cEventTimer.clock_sub_4263A0();
  }

//load level
  v25 = LODFile_Games_LOD.IsContainerExist(loc_hdr.location_name);
  v36 = (int)&loc_hdr.location_name;
  wsprintfA((char *)TmpBuf, "levels\\%s",loc_hdr.location_name);
  v24 = _access((char *)TmpBuf, 4) != -1;
  if ( !v25 )
  {
    if ( !v24 )
    {
      v36 = (int)&loc_hdr.location_name;
      wsprintfA((char *)TmpBuf, "Unable to find: %s!",loc_hdr.location_name);
      erroneous_printf((char *)TmpBuf, v34, v35, v36);
    }
  }

  LOWORD(dword_6BE364) = dword_6BE364 | 0x2001;

  v27 = 0;
  if (uSaveFileCount > 0 )
  {
	for(int i=0; i<uSaveFileCount;i++) 
       cSaveTumbnail[i].PCXTexture_Release();
  
  }

  LODFile_Icons_LOD.LODFile_sub_4114F2();
  v36 = (signed __int64)(pSoundVolumeLevels[uSoundVolumeMultiplier] * 128.0);
  pAudioPlayer->SetMasterVolume(128.0f * pSoundVolumeLevels[uSoundVolumeMultiplier]);
  pAudioPlayer->SetMusicVolume(64.0f * pSoundVolumeLevels[uMusicVolimeMultiplier]);
  if ( uTurnSpeed )
    pParty->sRotationY = uTurnSpeed * pParty->sRotationY / uTurnSpeed;

  if (strstr(loc_hdr.location_name, ".odm"))
    uCurrentlyLoadedLevelType = 2;
  else if (strstr(loc_hdr.location_name, ".blv"))
    uCurrentlyLoadedLevelType = 1;
  sub_4666D5();

  byte_50794A = 0;
  struct_576FE8.dword_000044 = 1;





 pParty->pickedItem.uItemID = -1;
 for (unsigned int i = 0; i < 4; ++i)
 {
  Player *pPlayer = &pParty->pPlayers[i];

  for (unsigned int j = 0; j < 16; ++j)
    pPlayer->cEquippedItems.pIndices[j] -= 1;

  for (unsigned int j = 0; j < 126; ++j)
    pPlayer->pInventoryIndices[j] -= 1;
 }

  PrepareWorld(loc_hdr.location_name, true, 1);
 return true;
}


//----- (004601B7) ---------.text:00461464   -----------------------------------------------
void sub_4601B7_SaveLoadWindow_Render(int a1)		 //render save_load
{
  unsigned __int16 v1; // bx@1
  int v2; // eax@4
  int v3; // edi@4
  int v4; // eax@8
  int v5; // eax@8
  int v6; // edi@8
  __int64 v7; // qax@10
  int v8; // ecx@10
  int v9; // edi@10
  signed int v10; // eax@10
  signed __int64 v11; // qax@10
  int v12; // ebx@10
  unsigned int v13; // ett@10
  __int64 v14; // qax@10
  signed __int64 v15; // ST14_8@10
  char v16; // di@10
  unsigned __int64 v17; // qtt@10
  unsigned __int8 v18; // cf@21
  signed int v19; // ebx@22
  const char *v20; // ST14_4@32
  int v21; // eax@32
  const char *v22; // ST18_4@32
  int v23; // eax@32
  const char *v24; // ST14_4@32
  int v25; // eax@32
  const char *v26; // edi@36
  int v27; // eax@43

  GUI::Window local_0C;
  //int Dst; // [sp+Ch] [bp-78h]@8
  //int v30; // [sp+10h] [bp-74h]@8
  //int v31; // [sp+14h] [bp-70h]@8
  //int v32; // [sp+18h] [bp-6Ch]@8
  //int v33; // [sp+1Ch] [bp-68h]@8
  //int v34; // [sp+20h] [bp-64h]@8

  __int64 v35; // [sp+60h] [bp-24h]@10
  int v36; // [sp+68h] [bp-1Ch]@10
  unsigned int v37; // [sp+70h] [bp-14h]@10
  __int64 v38; // [sp+74h] [bp-10h]@10
  int v39; // [sp+7Ch] [bp-8h]@10
  int v40; // [sp+80h] [bp-4h]@1

  v1 = 255;
  v40 = a1;
  0xFFFFFF;
  0xFFFF9B;
  pD3DRenderer->BeginScene();
  if ( sub_466CA0() != 3 )
  {
    if ( sub_466CA0() != 9 )
    {
      Render_DrawIndexedTexture(pD3DRenderer, 8, 8, (uGUILoadSave != -1 ? &LODFile_Icons_LOD.aLODHeaders[uGUILoadSave] : 0));
      if ( v40 )
      {
        v3 = uGUISaveUp;
        v2 = uGUILS_saveU;
      }
      else
      {
        v3 = uGUILoadUp;
        v2 = uGUILS_loadU;
      }
      Render_DrawIndexedTexture(pD3DRenderer, 241, 302, (v2 != -1 ? &LODFile_Icons_LOD.aLODHeaders[v2] : 0));
      Render_DrawIndexedTexture(pD3DRenderer, 18, 139, (v3 != -1 ? &LODFile_Icons_LOD.aLODHeaders[v3] : 0));
      Render_DrawIndexedTexture(pD3DRenderer, 351, 302, (uGUIx_u != -1 ? &LODFile_Icons_LOD.aLODHeaders[uGUIx_u] : 0));
      v1 = 255;
    }
  }
  if ( dword_69CF28[dword_6A0CA0_indx] )
  {
    memset(&local_0C, 0, sizeof(GUI::Window));
    local_0C.uFrameX = pGUIWindow_CurrentMenu->uFrameX + 240;
    v5 = pGUIWindow_CurrentMenu->uFrameY -pFontSmallnum->uFontHeight+157;
    local_0C.uFrameWidth = 220;
   // v5 += 157;
    local_0C.uFrameY = v5;
    v6 = pFontSmallnum->uFontHeight;
    local_0C.uFrameZ = local_0C.uFrameX + 219;
    local_0C.uFrameHeight = v6;
    local_0C.uFrameW = v6 + v5 - 1;
    //v4 = dword_6A0CA0_indx;
    if (cSaveTumbnail[dword_6A0CA0_indx].pPixels )
    {
      Render_DrawRGBTexture(pD3DRenderer,
        pGUIWindow_CurrentMenu->uFrameX + 276,
        pGUIWindow_CurrentMenu->uFrameY + 171,
       &cSaveTumbnail[dword_6A0CA0_indx]);
    }

    //v10 = CMapStats_FindLocation(pMapStats,(char *)&saves_hdr[dword_6A0CA0_indx].location_name);
    //GUIWindow_DrawText(&local_0C, pFontSmallnum, 0, 0, 0, (const char *)pMapStats->pMapInfos[v10].pLocationName, 3);
    GUIWindow_DrawText(&local_0C, pFontSmallnum, 0, 0, 0, (char *)pMapStats->GetMapInfo((char *)&saves_hdr[dword_6A0CA0_indx].location_name)->pLocationFilename, 3);

	v11 = 	(saves_hdr[dword_6A0CA0_indx].qWorld_time * 0.234375) / 60;
   // v11 = (signed __int64)((double)*(signed __int64 *)&dword_69BD90[25 * dword_6A0CA0_indx] * 0.234375) / 60;
    //v12 = (signed __int64)((double)*(signed __int64 *)&dword_69BD90[25 * dword_6A0CA0_indx] * 0.234375) / 60;
   // HIDWORD(v35) = (unsigned __int64)((signed __int64)((double)*(signed __int64 *)&dword_69BD90[25 * dword_6A0CA0_indx]
    v12=LODWORD(v11);                                             //    * 0.234375)/ 60) >> 32;
    v11 /= 60;
    v38 = v11;
    v13 = v11;
    v37 = (_DWORD)v11 / 24;
    v14 = (_DWORD)v11 / 24 / 7;
    //HIDWORD(v15) = HIDWORD(v35);
   // LODWORD(v15) = v12;
    v16 = v14;
    LODWORD(v17) = v13 /24 / 28;
    HIDWORD(v17) = HIDWORD(v14);
    v36 = v17 % 12;
    v39 = v17 /12;
    v35 = v12 % 60;	 //   v15 % 60;
    v7 = v38 % 24;
    LODWORD(v38) = v38 % 24;
    v8 = HIDWORD(v7);
    HIDWORD(v7) = v37 % 28;
    v39 += 1168;
    v9 = v16 & 3;
    local_0C.uFrameY = pGUIWindow_CurrentMenu->uFrameY + 261;
    HIDWORD(v38) = v8 >= 0 && (v8 > 0 || (_DWORD)v7 >= 12) && v8 <= 0 && (v8 < 0 || (_DWORD)v7 < 24);
    if ( v8 < 0 || v8 <= 0 && (_DWORD)v7 <= 12 )
    {
      if ( !(v8 | (_DWORD)v7) )
      {
        v37 = 0;
        v19 = 12;
        goto LABEL_23;
      }
    }
    else
    {
      v18 = (_DWORD)v7 < 12;
      LODWORD(v7) = v7 - 12;
      v8 -= v18;
    }
    v19 = v7;
    v37 = v8;
LABEL_23:
    wsprintfA((char *)TmpBuf,
      "%s %d:%02d%s\n%d %s %d",		  //day hour:min am  month year
      aDayNames[HIDWORD(v7) % 7],
      v19,
      LODWORD(v35),
      aAMPMNames[HIDWORD(v38)],
      7 * v9 + HIDWORD(v7) % 7 + 1,
      aMonthNames[v36],
      v39);
    GUIWindow_DrawText(&local_0C, pFontSmallnum, 0, 0, 0, (char *)TmpBuf, 3);
    v1 = 255;
  }
  if ( pGUIWindow_CurrentMenu->dword_000040 == 2 )
  {
    pGUIWindow_CurrentMenu->dword_000040 = 0;
    strcpy((char *)&saves_hdr[dword_6A0CA0_indx].name1, (char *)pUserInput->pPressedKeysBuffer);
	/* if ( dword_50CBD0.msg_count < 40 )
            {
			  dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param1=83;
			  dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param2=0;
			  dword_50CBD0.prm[dword_50CBD0.msg_count].msg_param3=0;
			  dword_50CBD0.msg_count++;
            }  */
	 dword_50CBD0.PutMessageToQueue(83,0,0);
  }
  else
  {
    if ( pGUIWindow_CurrentMenu->dword_000040 == 3 )
      pGUIWindow_CurrentMenu->dword_000040 = 0;
  }
  if ( sub_466CA0() == 9 )
  {
    v20 = (char *)pGlobalTXT_LocalizationStrings[LOCSTR_LOADING];
    v21 = AlignText_Center(186, v20, pFontSmallnum);
    FontDrawText(pGUIWindow_CurrentMenu, pFontSmallnum, v21 + 25, 220, v20, 0, 0, 0);

    v22 = (char *)&saves_hdr[dword_6A0CA0_indx].name1;
    v23 = AlignText_Center(186, (const char *)&saves_hdr[dword_6A0CA0_indx].name1, pFontSmallnum);
    GUIWindow_sub_44CB4F(pGUIWindow_CurrentMenu, pFontSmallnum, v23 + 25, 262, 0, v22, 185, 0);

    v24 = (char *)pGlobalTXT_LocalizationStrings[LOCSTR_PLEASE_WAIT];
    v25 = AlignText_Center(186, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_PLEASE_WAIT], pFontSmallnum);
    FontDrawText(pGUIWindow_CurrentMenu, pFontSmallnum, v25 + 25, 304, v24, 0, 0, 0);
  }
  else
  {
    if ( v40 )
      v37 = 40;
    else
      v37 = uSaveFileCount;
    v40 = 199;
    v39 = dword_6A0C9C;
  //  v26 = (char *)&saves_hdr[dword_6A0C9C].name1;
    do
    {
      if ( v39 >= (signed int)v37 )
        break;
      v38 = v39 == dword_6A0CA0_indx ? 0xFFFF64  : 0;
      if ( pGUIWindow_CurrentMenu->dword_000040 != 1 || v39 != dword_6A0CA0_indx )
      {
        GUIWindow_sub_44CB4F(pGUIWindow_CurrentMenu, pFontSmallnum, 27, v40, v38,(char*)&saves_hdr[v39].name1, 185, 0);
      }
      else
      {
        v27 = GUIWindow_sub_44CB4F(pGUIWindow_CurrentMenu, pFontSmallnum, 27, v40, v38, (char *)pUserInput->pPressedKeysBuffer, 175, 1);
        GUIWindow_sub_459C2B(pGUIWindow_CurrentMenu, v27 + 27, v40, (int)pFontSmallnum);
      }
      v40 += 21;
      ++v39;
    //  v26 += 100;
    }
    while ( v40 < 346 );
  }
  pD3DRenderer->EndScene();
}



//----- (0045E297) -------------.text:0045F527-------------------------------------------
void sub_45E297(int a1)
{
  signed int v1; // edi@4
  int v2; // eax@6
  int v4; // [sp+10h] [bp-4h]@1

  v4 = a1;
  memset(&saves_lst, 0,sizeof(Save_files_list));
  SetCurrentDirectoryW(L".\\Saves");
  uSaveFileCount = 0;
  if ( !v4 )
  {
    if ( _access((char *)pGlobalTXT_LocalizationStrings[LOCSTR_AUTOSAVE_MM7], 0) != -1 )
		{
        strcpy((char *)&saves_lst.name_list[uSaveFileCount], (char *)pGlobalTXT_LocalizationStrings[LOCSTR_AUTOSAVE_MM7]);
	    uSaveFileCount++;
		}
  }
 
  for(int i=0;i<40; i++) 
  {
    wsprintfA((char *)TmpBuf, "save%03d.mm7",i);
    if ( _access((char *)TmpBuf, 0) != -1 )
    {
      v2 = i;
      if ( !v4 )
        v2 = uSaveFileCount;
      strcpy((char *)&saves_lst.name_list[v2], (char *)TmpBuf);
      ++uSaveFileCount;
    }
  }

  SetCurrentDirectoryW(L"..");
}

//----- (0045E361) -------.text:0045F5F1   -------------------------------------------------
void sub_45E361(int a1)  //saveload menu
{
  int v1; // eax@5
  int v2; // ebp@5
  int v3; // ebp@11
  FILE * v4; // eax@14
  FILE *v5; // eax@18
  int v6; // eax@25
  int v8; // eax@27
  const char *v9; // [sp-8h] [bp-26Ch]@25
  const char *v10; // [sp-4h] [bp-268h]@19
  unsigned int v11; // [sp-4h] [bp-268h]@25
  int v12; // [sp+10h] [bp-254h]@1
  void *v13; // [sp+10h] [bp-254h]@12
  void *v14; // [sp+14h] [bp-250h]@12
  const char *v15; // [sp+18h] [bp-24Ch]@12
  LOD_Writefile v16; // [sp+1Ch] [bp-248h]@1
  int v17; // [sp+260h] [bp-4h]@1

  v12 = a1;
 // v16=new (LOD_Writefile);		//sub_46175B(
  dword_6BE138 = -1;
  ++LODFile_Icons_LOD.uTexturePacksCount;
  v17 = 0;
  if ( !LODFile_Icons_LOD.uPrevLoadedFiles )
    LODFile_Icons_LOD.uPrevLoadedFiles = LODFile_Icons_LOD.uNumLoadedFiles;
  memset(&dword_69CF28, 0, 45*sizeof(int));
  memset(&cSaveTumbnail[0], 0, 45*sizeof(cPCXTexture));
  uGUILoadSave = LODFile_Icons_LOD.LODFile_LoadTexture( "loadsave", 2);
  uGUILoadUp   = LODFile_Icons_LOD.LODFile_LoadTexture( "load_up", 2);
  uGUISaveUp = LODFile_Icons_LOD.LODFile_LoadTexture( "save_up", 2);
  uGUILS_loadU = LODFile_Icons_LOD.LODFile_LoadTexture( "LS_loadU", 2);
  uGUILS_saveU = LODFile_Icons_LOD.LODFile_LoadTexture( "LS_saveU", 2);
  uGUIx_u = LODFile_Icons_LOD.LODFile_LoadTexture( "x_u", 2);
  if ( v12 )
  {
    Render_DrawIndexedTexture(pD3DRenderer, 8, 8,(uGUILoadSave != -1 ? &LODFile_Icons_LOD.aLODHeaders[uGUILoadSave] : 0));
    if ( dword_4E28F8_PartyCantJumpIfTrue == 11 )
    {
      v2 = uGUISaveUp;
      v1 = uGUILS_saveU;
    }
    else
    {
      v2 = uGUILoadUp;
      v1 = uGUILS_loadU;
    }
    Render_DrawIndexedTexture(pD3DRenderer, 241, 302, (v1 != -1 ? &LODFile_Icons_LOD.aLODHeaders[v1] : 0));
    Render_DrawIndexedTexture(pD3DRenderer, 18, 141, (v2 != -1 ? &LODFile_Icons_LOD.aLODHeaders[v2] : 0));
    Render_DrawIndexedTexture(pD3DRenderer, 351, 302, (uGUIx_u != -1 ? &LODFile_Icons_LOD.aLODHeaders[uGUIx_u] : 0));
  }
  else
  {
#ifndef OLD_CODE
    Render_DrawRGBTexture_New(pD3DRenderer, 0, 0, uTextureID_CurrentMenu);
#endif
#ifdef OLD_CODE
    Render_DrawRGBTexture(pD3DRenderer, 0, 0, &cPCXID_CurrentMenu);
#endif
  }
  pGUIWindow_CurrentMenu = GUIWindowCreate(dword_4E94D4[v12], dword_4E94DC[v12], dword_4E94E4[v12], dword_4E94EC[v12], 24, 0, 0);
  FontDrawText(pGUIWindow_CurrentMenu, pFontSmallnum, 25, 199, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_READING], 0, 0, 0);
  pD3DRenderer->Present();
  sub_45E297(0);
  if ( dword_6A0C9C > uSaveFileCount)
  {
    dword_6A0C9C = 0;
    dword_6A0CA0_indx = 0;
  }
  v16.AllocateSubidexAndIOBuffer( 300, 0);
  v3 = 0;
   
  if ( uSaveFileCount > 0 )
	  {
	  for( v3=0; v3<uSaveFileCount; v3++)
		  {
		  wsprintfA((char *)TmpBuf, "saves\\%s",saves_lst.name_list[v3]);
		  if ( _access((char *)TmpBuf, 6) )	  //Read and write
			  continue;
		  v16.Load_File( (char *)TmpBuf, 1);
		  v4 = v16.Find_Container( "header.bin", 1);
		  if ( v4 )
			  locked_fread(&saves_hdr[v3],100, 1, v4);
		  if ( !_strcmpi(saves_lst.name_list[v3], (char *)pGlobalTXT_LocalizationStrings[LOCSTR_AUTOSAVE_MM7]) )
			  strcpy((char *)&saves_hdr[v3].name1, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_AUTOSAVE]);
		  v5 = v16.Find_Container( "image.pcx", 1);
		  if ( !v5 )
			  {
			  dword_69CF28[v3] = 0;
			  strcpy((char *)&saves_hdr[v3].name1, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_EMPTY]);

			  }
		  else
			  {
			  cSaveTumbnail[v3].LoadPCXFromFile(v5, 0, true);
			  v16.Close_Written_File();
			  dword_69CF28[v3] = 1;
			  }
		  }
	  }
  v16.FreeSubIndxIOBuffers();
  if ( dword_4E28F8_PartyCantJumpIfTrue == 11 )
    v9 = "LS_saveD";
  else
    v9 = "LS_loadD";

  uGUIx_d      = LODFile_Icons_LOD.LODFile_LoadTexture( "x_d", 2);
  uGUIL_S_txtr = LODFile_Icons_LOD.LODFile_LoadTexture( v9, 2);
  uGUIar_up_dn = LODFile_Icons_LOD.LODFile_LoadTexture( "AR_UP_DN", 2);
  uGUIar_dn_dn = LODFile_Icons_LOD.LODFile_LoadTexture( "AR_DN_DN", 2);
  GUIButtonCreate(pGUIWindow_CurrentMenu,  21, 198, 191, 18, 1, 0, 165, 0, 0, NULL, 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu,  21, 219, 191, 18, 1, 0, 165, 1, 0, NULL, 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu,  21, 240, 191, 18, 1, 0, 165, 2, 0, NULL, 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu,  21, 261, 191, 18, 1, 0, 165, 3, 0, NULL, 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu,  21, 282, 191, 18, 1, 0, 165, 4, 0, NULL, 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu,  21, 303, 191, 18, 1, 0, 165, 5, 0, NULL, 0);
  GUIButtonCreate(pGUIWindow_CurrentMenu,  21, 324, 191, 18, 1, 0, 165, 6, 0, NULL, 0);
  pLoadSaveBtn = 
  GUIButtonCreate(pGUIWindow_CurrentMenu, 241, 302, 105, 40, 1,	0, 164, 0, 0, NULL,
                                 uGUIL_S_txtr != -1 ? &LODFile_Icons_LOD.aLODHeaders[uGUIL_S_txtr] : 0);
  pCancelBtn = 
  GUIButtonCreate(pGUIWindow_CurrentMenu, 350, 302, 105, 40, 1, 0, 166, 0, 0, NULL,
                                 uGUIx_d != -1 ? &LODFile_Icons_LOD.aLODHeaders[uGUIx_d] : 0);
  pArrowUpBtn = 
  GUIButtonCreate(pGUIWindow_CurrentMenu, 215, 199,  17, 17, 1, 0, 162, 0, 0, NULL,
                                 uGUIar_up_dn != -1 ? &LODFile_Icons_LOD.aLODHeaders[uGUIar_up_dn] : 0);
  pArrowDownBtn = 
  GUIButtonCreate(pGUIWindow_CurrentMenu, 215, 323,	 17, 17, 1, 0, 163,	uSaveFileCount, 0,  NULL,
                                 uGUIar_dn_dn != -1 ?  &LODFile_Icons_LOD.aLODHeaders[uGUIar_dn_dn]: 0);

}



//----- (00460078) --------------------------------------------------------
int __fastcall sub_460078(int a1)
{
  int v1; // esi@1
  int v2; // esi@2
  int v3; // eax@3
  int v4; // ebx@3
  int result; // eax@8
  LODIndex St; // [sp+Ch] [bp-28h]@2
  int v7; // [sp+20h] [bp-14h]@2
  int v8; // [sp+2Ch] [bp-8h]@1
  int v9; // [sp+30h] [bp-4h]@1

  v1 = a1;
  v9 = a1;
  compile_error(level name should not be globally-defined);
  //v8 = _strcmpi(CurrentLevelName, "d05.blv");
  if ( v8 )
  {
    SaveGame(0, 0);
    Reset_LODIndex(&St);
    //v2 = 100 * v1;
    compile_error(level name should not be globally-defined);
  //strcpy((char *)&saves_hdr[v1].location_name, CurrentLevelName);
    //*(int *)((char *)dword_69BD90 + v2) = pParty->qword_00002C;
    //*(int *)((char *)&dword_69BD90 + 4 + v2) = HIDWORD(pParty->qword_00002C);
	saves_hdr[v1].qWorld_time=pParty->qword_00002C;
    strcpy(St.pFilename, "header.bin");
    St.size_data = 100;
    LODFile_New_LOD.Add_Container_to_File( &St, &saves_hdr[v1], 0);
    wsprintfA((char *)TmpBuf, "saves\\save%03d.mm7", v9);
    LODFile_New_LOD.Close_Written_File();
    CopyFileA("data\\new.lod", (char *)TmpBuf, 0);
  }
  sub_4156F0_UI_UpdateWindows();
  GUIWindowDelete(pGUIWindow_CurrentMenu);
  dword_4E28F8_PartyCantJumpIfTrue = 0;
  v4 = 0;
  struct_576FE8.dword_000044 = 1;
  for(int i=0; i<40;i++) 
       cSaveTumbnail[i].PCXTexture_Release();
  
  if ( v8 )
    LODFile_New_LOD.ReloadFile();
  else
    sub_44C175((char *)pGlobalTXT_LocalizationStrings[LOCSTR_NO_SAVING], 2);
  LODFile_Icons_LOD.sub_4355F7();
  cEventTimer.Resume();
  result = sub_44C175((char *)pGlobalTXT_LocalizationStrings[LOCSTR_GAME_SAVED], 2);
  struct_576FE8.dword_000044 = 1;
  return result;
}

//----- (004606F7) --------------------------------------------------------
void sub_4606F7_LoadWindow_Render()
{
  sub_4601B7_SaveLoadWindow_Render(0);
}

//----- (004606FE) --------------------------------------------------------
void sub_4606FE()
{
 sub_4601B7_SaveLoadWindow_Render(1);
}


//----- (0045F469) -----.text:00460713  ---------------------------------------------------
int __fastcall SaveGame(int a1, int a2)
{
  int result; // eax@1
  int v5; // eax@6
  int v6; // eax@6
  int v7; // eax@6
  int v8; // edi@8
  int v9; // eax@24
  FILE *v10; // edi@24
  unsigned int v11; // edi@30
  void *v12; // esi@31
  void *v13; // esi@31
  int v14; // esi@37
  void *v15; // esi@37
  void *v16; // esi@37
  void *v17; // esi@37
  void *v18; // esi@37
  void *v19; // esi@37
  int v20; // ecx@38
  int v21; // edx@39
  int v22; // esi@39
  void *v23; // esi@41
  void *v24; // esi@41
  int v25; // eax@42
  signed int v26; // edi@42
  unsigned __int8 v27; // zf@43
  unsigned __int8 v28; // sf@43
  signed int v29; // edi@47
  void *v30; // esi@50
  void *v31; // esi@50
  void *v32; // esi@50
  void *v33; // esi@50
  int v34; // esi@51
  int v35; // eax@51
  int  v36; // eax@54
  DWORD v37; // eax@59
  char v38; // [sp-18h] [bp-288h]@8
  int v39; // [sp-14h] [bp-284h]@8
  const char *v40; // [sp-10h] [bp-280h]@6
  const char *v41; // [sp-Ch] [bp-27Ch]@6
  int v42; // [sp-8] [bp-278]@6
  CHAR Buffer; // [sp+Ch] [bp-264h]@59
  char Dir[32]; // [sp+8Ch] [bp-1E4h]@51
  char Drive[32]; // [sp+ACh] [bp-1C4h]@51

  Save_Header v47; // int v47; // [sp+CCh] [bp-1A4h]@10
 // char v48[20]; // [sp+E0h] [bp-190h]@10
 // __int64 v49; // [sp+F4h] [bp-17Ch]@10

  char v50[32]; // [sp+130h] [bp-140h]@51

  char Ext[32]; // [sp+150h] [bp-120h]@51

 // char v52; // [sp+151h] [bp-11Fh]@51

  char FullPath[32]; // [sp+170h] [bp-100h]@51
  char Str[120]; // [sp+190h] [bp-E0h]@8

  int v55; // [sp+208h] [bp-68h]@2
  int v56; // [sp+20Ch] [bp-64h]@2
  int v57; // [sp+210h] [bp-60h]@2
  int v58; // [sp+214h] [bp-5Ch]@2
  save_struct01 Src; // [sp+218h] [bp-58h]@30
 // char v60; // [sp+21Ch] [bp-54h]@30
 // char v61; // [sp+21Dh] [bp-53h]@30
//  char v62; // [sp+21Eh] [bp-52h]@30
//  char v63; // [sp+21Fh] [bp-51h]@30
//  int v64; // [sp+220h] [bp-50h]@30
//  int v65; // [sp+224h] [bp-4Ch]@30
  int v66; // [sp+228h] [bp-48h]@2

  //local struct
  LODIndex St2; // [sp+22Ch] [bp-44h]@2
  int ElementSize; // [sp+240h] [bp-30h]@5
  int v69; // [sp+24Ch] [bp-24h]@1
  size_t Size; // [sp+250h] [bp-20h]@26
  int v71; // [sp+254h] [bp-1Ch]@1
  void *DstBuf; // [sp+258h] [bp-18h]@2
  const void *v73; // [sp+25Ch] [bp-14h]@32
  int v74; // [sp+260h] [bp-10h]@23
  int v75; // [sp+264h] [bp-Ch]@22
  unsigned int v76; // [sp+268h] [bp-8h]@8
  int v77; // [sp+26Fh] [bp-1h]@8

  v71 = a2;
  v69 = a1;
  compile_error(level name should not be globally-defined);
  //strcpy(byte_6BE3B0, CurrentLevelName);
  compile_error(level name should not be globally-defined);
  //result = stricmp(CurrentLevelName, "d05.blv");
  if ( result )
  {
    DstBuf = MemAlloc(char, 1000000);//DstBuf = operator new(0xF4240u);
    Reset_LODIndex(&St2);
    v56 = pParty->vPosition.x;
    v55 = pParty->vPosition.y;
    v66 = pParty->vPosition.z;
    v57 = pParty->sRotationY;
    v58 = pParty->sRotationX;
    pParty->vPosition = pParty->vOldPosition;
    pParty->sRotationY = pParty->sOldRotationY;
    pParty->sRotationX = pParty->sOldRotationX;
    pParty->dword_000700 = pParty->vOldPosition.z;

    if (uCurrentlyLoadedLevelType == 1)
      *(__int64 *)pIndoor->unk_0002EC = pParty->qword_00002C;
    else
      *(__int64 *)pOutdoor->array_0004F0 = pParty->qword_00002C;

    runtime_warning(aint workin);
    //v3 = sub_45E03A_SomethingLikeCaptureAScreenshot(150, 112);
    //sub_49F5A2(pD3DRenderer, v3, 150, 112, DstBuf, 1000000, (int)&ElementSize);
    //operator_delete(0, v3);

    strcpy(St2.pFilename, "image.pcx");
    if ( dword_4E28F8_PartyCantJumpIfTrue == 11 )
    {
      Render_DrawIndexedTexture(pD3DRenderer,  8,   8, (uGUILoadSave != -1 ? &LODFile_Icons_LOD.aLODHeaders[uGUILoadSave] : 0));
      Render_DrawIndexedTexture(pD3DRenderer, 18, 141, (uGUISaveUp != -1 ? &LODFile_Icons_LOD.aLODHeaders[uGUISaveUp] : 0));
      v40 = (char *)pGlobalTXT_LocalizationStrings[LOCSTR_SAVING];
      v5 = AlignText_Center(186, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_SAVING], pFontSmallnum);
      FontDrawText(pGUIWindow_CurrentMenu, pFontSmallnum, v5 + 25, 219, v40, 0, 0, 0);

      v41 = (char *)&saves_hdr[dword_6A0CA0_indx].name1;
      v6 = AlignText_Center(186, (const char *)&saves_hdr[dword_6A0CA0_indx].name1, pFontSmallnum);
      GUIWindow_sub_44CB4F(pGUIWindow_CurrentMenu, pFontSmallnum, v6 + 25, 259, 0, v41, 185, 0);
      v40 = (char *)pGlobalTXT_LocalizationStrings[LOCSTR_PLEASE_WAIT];
      v7 = AlignText_Center(186, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_PLEASE_WAIT], pFontSmallnum);
      FontDrawText(pGUIWindow_CurrentMenu, pFontSmallnum, v7 + 25, 299, v40, 0, 0, 0);
      pD3DRenderer->Present();
    }
  /* if (LODFile_New_LOD.Add_Container_to_File( &St2, DstBuf, 0) )
    {
      wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[612], 200);
      v76 = (unsigned int)&v38;
      Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
      sub_466D09(&v76, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    } 	*/

    compile_error(level name should not be globally-defined);
  //strcpy(v47.location_name, CurrentLevelName);
    v47.qWorld_time = pParty->qword_00002C;
    strcpy(&St2.pFilename[0], "header.bin");
    St2.size_data = 100;
    if (LODFile_New_LOD.Add_Container_to_File( &St2, &v47, 0) )
    {
      wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[612], 201);
      v76 = (unsigned int)&v38;
      Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
      sub_466D09(&v76, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }

    strcpy(&St2.pFilename[0], "party.bin");
    St2.size_data = 90680;
    if (LODFile_New_LOD.Add_Container_to_File( &St2, pParty, 0) )
    {
      wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[612], 202);
      v76 = (unsigned int)&v38;
      Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
      sub_466D09(&v76, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }

    strcpy(&St2.pFilename[0], "clock.bin");
    St2.size_data = 40;
    if (LODFile_New_LOD.Add_Container_to_File( &St2, &cEventTimer, 0) )
    {
      wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[612], 203);
      v76 = (unsigned int)&v38;
      Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
      sub_466D09(&v76, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }

    strcpy(&St2.pFilename[0], "overlay.bin");
    St2.size_data = 1008;
    if (LODFile_New_LOD.Add_Container_to_File(&St2, &stru_5E4D58, 0) )
    {
      wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[612], 204);
      v76 = (unsigned int)&v38;
      Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
      sub_466D09(&v76, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }

    strcpy(&St2.pFilename[0], "npcdata.bin");
    St2.size_data = 38076;
    if (LODFile_New_LOD.Add_Container_to_File(&St2, pNPCStats->pNPCData2, 0) )
    {
      wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[165], 205);
      v76 = (unsigned int)&v38;
      Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
      sub_466D09(&v76, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }

    strcpy(&St2.pFilename[0], "npcgroup.bin");
    St2.size_data = 102;
    if (LODFile_New_LOD.Add_Container_to_File( &St2, pNPCStats->npc_group, 0) )
    {
      wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[165], 206);
      v76 = (unsigned int)&v38;
      Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
      sub_466D09(&v76, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
    }
	   
    v75 = 1;
    do
    {
      v74 = 1;
      do
      {
        v42 = v75;
        wsprintfA(Str, "data\\lloyd%d%d.pcx", v75, v74);
        v10 = fopen(Str, "rb");
        //v10 = (FILE *)v9;
        if ( v10 )
        {
          v42 = v75;
          wsprintfA(St2.pFilename, "lloyd%d%d.pcx", v75, v74);
          fseek(v10, 0, 2);
          St2.size_data = ftell(v10);
          rewind(v10);
          locked_fread(DstBuf, ElementSize, 1u, v10);
          strcpy(Str2, Str);
          fclose(v10);
          remove(Str);
          v9 =LODFile_New_LOD.Add_Container_to_File( &St2, DstBuf, 0);
          if ( v9 )
          {
            wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[165], 207);
            v76 = (unsigned int)&v38;
            Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
            //v9 = 
			sub_466D09(&Size, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
            Size = 5080748;
          }
        }
        ++v74;
      }
      while ( v74 <= 5 );
      ++v75;
    }
    while ( v75 <= 4 );

    if ( !a2 )
    {
      sub_42FA22();
      v11 = (unsigned int)MemAlloc(char, 1000000);
      v76 = v11;

      Src.data1 = 91969;
      Src.signature[0] = 'm';
      Src.signature[1] = 'v';
      Src.signature[2] = 'i';
      Src.signature[3] = 'i';
      Src.data2 = 0;
      Src.data3 = 0;
      memcpy((void *)v11, &Src, 16);
      if ( uCurrentlyLoadedLevelType == 1 )
      {
        v13 = DstBuf;
        pIndoor->cDLVHeader.dword_000010 = pIndoor->uNumFaces;
        pIndoor->cDLVHeader.dword_000018 = 0;
        pIndoor->cDLVHeader.dword_000014 = uNumLevelDecorations;
        memcpy(DstBuf, (char *)&pIndoor->cDLVHeader, 40);
        v13 = (char *)v13 + 40;
        memcpy(v13, pIndoor->unk_000324, 875);
        v12 = (char *)v13 + 875;
        v75 = 0;
        if ( pIndoor->uNumFaces > 0 )
        {
          v73 = 0;
          do
          {
            v42 = (int)((int)v73/96 + pIndoor->pFaces) + 44;
            memcpy(v12, (const void *)v42, 4);
            v73 = (char *)v73 + 96;
            v12 = (char *)v12 + 4;
            ++v75;
          }
          while ( v75 < pIndoor->uNumFaces );
        }

        v75 = 0;
        if ( (signed int)uNumLevelDecorations > 0 )
        {
         v73 = &pLevelDecorations[0].word_000002;
          do
          {
            memcpy(v12, v73, 2);
            v73 = (char *)v73 + 32;
            v12 = (char *)v12 + 2;
            ++v75;
          }
          while ( v75 < (signed int)uNumLevelDecorations );
        }

        memcpy(v12, &uNumActors, 4);
        v15 = (char *)v12 + 4;
        memcpy(v15, pActors, 836 * uNumActors);
        v16 = (char *)v15 + 836 * uNumActors;

        memcpy(v16, &uNumLayingItems, 4);
        v16 = (char *)v16 + 4;
        memcpy(v16, pLayingItemsList, 112 * uNumLayingItems);
        v17 = (char *)v16 + 112 * uNumLayingItems;

        memcpy(v17, &dword_5FF140, 4);
        v17 = (char *)v17 + 4;
        memcpy(v17, array_5E5150, 5324 * dword_5FF140);
        v18 = (char *)v17 + 5324 * dword_5FF140;
        compile_error();//memcpy(v18, ::Src, 0x3E80u);
        v18 = (char *)v18 + 16000;
        compile_error();//memcpy(v18, dword_6BE67C, ::Size);
        compile_error();//v19 = (char *)v18 + ::Size;
        memcpy(v19, &global_5E4C90, sizeof(struct struct4));
        v14 = (int)((char *)v19 + 200);
        memcpy((void *)v14, pIndoor->unk_0002EC, 56);
      }
      else
      {
        
        pOutdoor->cDDMHeader.dword_000010 = 0;
		  for (v20 = 0;v20 < pOutdoor->uNumBModels; ++v20)
          {
		      pOutdoor->cDDMHeader.dword_000010 += pOutdoor->pBModels[v20].uNumFaces;
          }

        v24 = DstBuf;
        pOutdoor->cDDMHeader.dword_000018 = pOutdoor->uNumBModels;
        pOutdoor->cDDMHeader.dword_000014 = uNumLevelDecorations;
        memcpy(DstBuf, (char *)&pOutdoor->cDDMHeader, 40);
        v24 = (char *)v24 + 40;
        memcpy(v24, pOutdoor->array_000528, 968);
        v24 = (char *)v24 + 968;
        memcpy(v24, pOutdoor->array_0008F0, 968);
        v23 = (char *)v24 + 968;  
        if ( pOutdoor->uNumBModels > 0 )
        {
        
           for (v75 = 0;v75 < pOutdoor->uNumBModels; v75++)
          {
             for (v71 = 0;v71 < pOutdoor->pBModels->uNumFaces; v71++)
              {		
                memcpy(v23, &pOutdoor->pBModels[v75].pFaces[v71].uFaceAttributes, 4);
                v23 = (char *)v23 + 4;
              }

          }
         	 
        }
        v29 = 0;
        if ( (signed int)uNumLevelDecorations > 0 )
        {
         v71 = (int)&pLevelDecorations[0].word_000002;
          do
          {
            memcpy(v23, (const void *)v71, 2);
            v71 += 32;
            v23 = (char *)v23 + 2;
            ++v29;
          }
          while ( v29 < (signed int)uNumLevelDecorations );
        }
        memcpy(v23, &uNumActors, 4);
        v30 = (char *)v23 + 4;
        memcpy(v30, pActors, 836 * uNumActors);
        v31 = (char *)v30 + 836 * uNumActors;

        memcpy(v31, &uNumLayingItems, 4u);
        v31 = (char *)v31 + 4;
        memcpy(v31, pLayingItemsList, 112 * uNumLayingItems);
        v32 = (char *)v31 + 112 * uNumLayingItems;

        memcpy(v32, &dword_5FF140, 4);
        v32 = (char *)v32 + 4;
        memcpy(v32, array_5E5150, 5324 * dword_5FF140);
        v33 = (char *)v32 + 5324 * dword_5FF140;

        memcpy(v33, &global_5E4C90, sizeof(struct struct4));
        v14 = (int)((char *)v33 + 200);
        memcpy((void *)v14, pOutdoor->array_0004F0, 56);
        v11 = v76;
      }
      v34 = v14 + 56;
      compile_error(level name should not be globally-defined);
  //strcpy(FullPath, CurrentLevelName);
      _splitpath(FullPath, (char*)&Drive, (char*)&Dir, (char*)&v50, (char*)&Ext);
      Ext[1] = 'd';
      Size = v34 - (_DWORD)DstBuf;
      v74 = 999984;
      LOBYTE(v35) = compress((void *)(v11 + 16), (unsigned int *)&v74, DstBuf, v34 - (_DWORD)DstBuf);
      if ( v35 || v74 > (signed int)Size )
      {
        memcpy((void *)(v11 + 16), DstBuf, Size);
        v74 = Size;
      }
      v74 += 16;
      memcpy((void *)(v11 + 8), &v74, 4);
      memcpy((void *)(v11 + 12), &Size, 4);
      wsprintfA(FullPath, "%s%s", &v50, &Ext);
      strcpy(St2.pFilename, FullPath);
      St2.size_data = v74;
      v36 = LODFile_New_LOD.Add_Container_to_File( &St2, (const void *)v11, 0);
      if ( v36 )
      {
        wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[165], 208);
        v76 = (unsigned int)&v38;
        Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
       // v36 = 
		sub_466D09(&v76, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
      }
     // v9 = (void *)free();
	  MemFree((void *)v11);
    }

    MemFree(DstBuf);
    if ( v69 )
    {
      if ( !CopyFileA("data\\new.lod", "saves\\autosave.mm7", 0) )
      {
        v37 = GetLastError();
        FormatMessageA(0x1000u, 0, v37, 0x400u, &Buffer, 0x80u, 0);
        wsprintfA(Str, (char *)pGlobalTXT_LocalizationStrings[612], 300);
        v69 = (int)&v38;
        Game_sub_40E2C8(&v38, (char *)&Str, (int)&v77);
        sub_466D09(&v69, *(int *)&v38, v39, (int)v40, (int)v41, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\LoadSave.cpp", __LINE__);
      }
    }
    pParty->vPosition = Vec3<int>(v56, v55, v66);
    pParty->dword_000700 = v66;
    pParty->sRotationY = v57;
    result = v58;
    pParty->sRotationX = v58;
  }
  return result;
}

//----- (004B6943) --------------------------------------------------------
void __cdecl sub_4B6943()
{
  signed int v0; // ebx@1
  signed int v1; // edi@1
  int v2; // ebx@1
  void *v3; // esi@1
  int v4; // eax@1
  char *v5; // esi@7
  int v6; // eax@9
  int v7; // eax@9
  int v8; // eax@12
  int v9; // edi@12
  int v10; // edx@12
  int v11; // ecx@12
  signed int v12; // esi@13
  signed int v13; // edi@14
  int v14; // eax@15
  int v15; // eax@17
  int v16; // eax@20
  int v17; // eax@22
  DWORD v18; // eax@26
  DWORD v19; // edi@26
  int v20; // ebx@36
  int v21; // esi@36
  int v22; // eax@36
  int v23; // ecx@36
  int v24; // esi@36
  int v25; // eax@36
  int v26; // ebx@39
  void *v27; // esi@39
  int v28; // eax@39
  signed int v29; // eax@41
  int v30; // esi@44
  int v31; // eax@46
  int v32; // eax@50
  int v33; // eax@52
  int v34; // eax@55
  int v35; // eax@57
  char *v36; // eax@62
  int v37; // eax@62
  int v38; // ecx@62
  char *v39; // eax@63
  int v40; // eax@67
  char v41; // [sp-3Ch] [bp-2CCh]@62
  int v42; // [sp-38h] [bp-2C8h]@62
  int v43; // [sp-34h] [bp-2C4h]@62
  int v44; // [sp-30h] [bp-2C0h]@62
  int v45; // [sp-2Ch] [bp-2BCh]@62
  int v46; // [sp-28h] [bp-2B8h]@62
  int v47; // [sp-24h] [bp-2B4h]@62
  int v48; // [sp-20h] [bp-2B0h]@62
  int v49; // [sp-1Ch] [bp-2ACh]@62
  int v50; // [sp-18h] [bp-2A8h]@62
  int v51; // [sp-14h] [bp-2A4h]@62
  const CHAR *v52; // [sp-10h] [bp-2A0h]@62
  char *v53; // [sp-Ch] [bp-29Ch]@62
  char *v54; // [sp-8h] [bp-298h]@62
  char *v55; // [sp-4h] [bp-294h]@62
  const char *v56[5]; // [sp+0h] [bp-290h]@7
  char v57; // [sp+14h] [bp-27Ch]@37
  char v58; // [sp+78h] [bp-218h]@68
  char v59; // [sp+DCh] [bp-1B4h]@68
  char v60; // [sp+140h] [bp-150h]@68
  char Dest; // [sp+1A4h] [bp-ECh]@36

  GUI::Window local_208;
  //int v62; // [sp+208h] [bp-88h]@1
  //int v63; // [sp+210h] [bp-80h]@1
  //int v64; // [sp+218h] [bp-78h]@1

  int v65; // [sp+25Ch] [bp-34h]@36
  int v66; // [sp+260h] [bp-30h]@36
  unsigned int v67; // [sp+264h] [bp-2Ch]@1
  __int16 v68[2]; // [sp+268h] [bp-28h]@1
  void *v69; // [sp+26Ch] [bp-24h]@36
  int v70; // [sp+270h] [bp-20h]@1
  int v71; // [sp+274h] [bp-1Ch]@36
  void *v72; // [sp+278h] [bp-18h]@1
  int v73; // [sp+27Ch] [bp-14h]@36
  int v74; // [sp+280h] [bp-10h]@14
  char *v75; // [sp+284h] [bp-Ch]@37
  int v76; // [sp+288h] [bp-8h]@1
  int v77; // [sp+28Ch] [bp-4h]@48

  v2 = (int)ptr_507BC0;
  memcpy(&local_208, ptr_507BC0, sizeof(GUI::Window));
  v1 = 255;
  v72 = pPlayers[uActiveCharacter - 1];
  v3 = v72;
  local_208.uFrameX = 483;
  local_208.uFrameWidth = 148;
  local_208.uFrameZ = 334;
  *(_DWORD *)v68 = 0xFFFFFFFF;
  v67 = 0xFFFFFF9B;
  v4 = 52 * *(_DWORD *)(v2 + 28);
  v70 = (((array_59146C[v4/52 - 1].uPicture != 27) - 1) & 0xFFFFFFE7) + 50;
  v0 = (signed __int64)((double)v70 * *(float *)(v4 + 5837912));
  v76 = v0 * (100 - Player_sub_4911F3((Player *)v3)) / 100;
  if ( v76 < v0 / 3 )
    v76 = v0 / 3;
  if ( dword_F8B19C == 1 )
  {
    if ( sub_4B1784() )
    {
      v20 = (int)pDialogueWindow;
      v69 = (void *)-1;
      v73 = 0;
      v21 = *(_BYTE *)(pFontArrus + 5) - 3;
      v70 = (int)pDialogueWindow;
      v65 = v21;
      strcpy(&Dest, "");
      wsprintfA((char *)pStringBuffer, (char *)pGlobalTXT_LocalizationStrings[LOCSTR_TRAVEL_COST], v76);
      v22 = GUIFont_CalculateTextHeight(pFontArrus, pStringBuffer, &local_208, 0, 0);
      v23 = *(_DWORD *)(v20 + 40);
      v24 = v22 + v21 + 146;
      v25 = *(_DWORD *)(v20 + 56);
      v74 = v24;
      v66 = v24;
      v71 = v25;
      if ( v25 >= v25 + v23 )
        goto LABEL_71;
      v76 = 2;
      v75 = &v57;
      while ( 1 )
      {
        v56[1] = (const char *)v71;
        v28 = ptr_507BC0->dword_00001C;
        v27 = (void *)(unsigned __int8)*(&byte_4F0D38[4 * v28] + v73);
        v72 = (void *)(unsigned __int8)*(&byte_4F0D38[4 * v28] + v73);
        v26 = (int)GUIWindow_GetChild((GUI::Window *)v20, v71);
        if ( v27 != v69
          && (v76 >= 6 ? (v29 = 1) : (v29 = (unsigned __int8)*(&byte_4F09B1[32 * (_DWORD)v27] + pParty->uDaysPlayed % 7u)),
              v29
           && ((v30 = 32 * (_DWORD)v27, !*(_DWORD *)((char *)&unk_4F09CC + v30))
            || (unsigned __int16)sub_449B57((unsigned char *)pParty->unk_000764 + 1, *(_WORD *)((char *)&unk_4F09CC + v30)))) )
        {
          v69 = v72;
          v31 = v67;
          if (pDialogueWindow->dword_00002C != v76 )
            v31 = *(_DWORD *)v68;
          v56[1] = (const char *)v31;
          wsprintfA(v75, "\f%06x", v31);
          v77 = (unsigned __int8)byte_4F09B8[v30];
          if (ptr_507BC0->dword_00001C >= 63 )
          {
            v32 = CheckHiredNPCSpeciality(8);
            if ( v32 )
              v77 -= 2;
            v33 = CheckHiredNPCSpeciality(9);
            if ( v33 )
              v77 -= 3;
            v56[1] = (const char *)45;
          }
          else
          {
            v56[1] = (const char *)35;
          }
          v34 = CheckHiredNPCSpeciality((int)v56[1]);
          if ( v34 )
            v77 -= 2;
          v35 = CheckHiredNPCSpeciality(0x2C);
          if ( v35 )
            --v77;
          if ( v77 < 1 )
            v77 = 1;
          if ( v72 != (void *)v1 )
          {
            memcpy(&v41, &pMapStats->pMapInfos[(unsigned __int8)byte_4F09B0[v30]], sizeof(struct MapInfo));
            wsprintfA((char *)TmpBuf,
              (char *)pGlobalTXT_LocalizationStrings[LOCSTR_D_DAYS_TO_S],
              v77,
              *(_DWORD *)&v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              *(_QWORD *)v56);
            strcat(v75, (char *)TmpBuf);
            v36 = v75;
            v75 += 100;
            ++v73;
            ++v76;
            strcat(v36, "\n \n");
            *(_DWORD *)(v26 + 4) = v74;
            v37 = GUIFont_CalculateTextHeight(pFontArrus, TmpBuf, &local_208, 0, 0);
            v38 = *(_DWORD *)(v26 + 4);
            *(_DWORD *)(v26 + 12) = v37;
            v1 = 255;
            *(_DWORD *)(v26 + 20) = v38 + v37 - 1;
            v74 += v65 + v37;
          }
        }
        else
        {
          v39 = v75;
          ++v73;
          ++v76;
          v75 += 100;
          strcpy(v39, "");
          if ( v26 )
          {
            *(_DWORD *)(v26 + 20) = 0;
            *(_DWORD *)(v26 + 12) = 0;
            *(_DWORD *)(v26 + 4) = 0;
          }
        }
        ++v71;
        if ( v71 >= *(_DWORD *)(v70 + 40) + *(_DWORD *)(v70 + 56) )
          break;
        v20 = v70;
      }
      if ( v74 != v66 )
      {
        v56[1] = &Dest;
        v56[0] = &v60;
        v55 = &v59;
        v54 = &v58;
        v53 = &v57;
        v52 = (char *)pStringBuffer;
        wsprintfA((char *)TmpBuf, "%s\n \n%s%s%s%s%s", (char *)pStringBuffer, &v57, &v58, &v59, &v60, &Dest);
        GUIWindow_DrawText(&local_208, pFontArrus, 0, 146, 0, (char *)TmpBuf, 3);
      }
      else
      {
LABEL_71:
        v56[1] = (const char *)3;
        v56[0] = (char *)pGlobalTXT_LocalizationStrings[561];
        v55 = *(char **)v68;
        v40 = GUIFont_CalculateTextHeight(pFontArrus, pGlobalTXT_LocalizationStrings[561], &local_208, 0, 0);
        GUIWindow_DrawText(&local_208, pFontArrus, 0, (174 - v40) / 2 + 138, (unsigned __int16)v55, v56[0], (int)v56[1]);
        pAudioPlayer->MessWithChannels(&Range<unsigned int>(0, 16));;
      }
    }
  }
  else
  {
    if ( dword_F8B19C > 104 && dword_F8B19C <= 108 )
    {
      if ( pParty->uNumGold < (unsigned int)v76 )
      {
        sub_44C175((char *)pGlobalTXT_LocalizationStrings[155], 2);
        sub_4B1E92(ptr_507BC0->dword_00001C, 3);
       /* if ( dword_50CBD0[0] >= 40 )
          return;
        dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
        dword_50CBD0[3 * dword_50CBD0[0] + 2] = 1;
        goto LABEL_33;*/
		 dword_50CBD0.PutMessageToQueue(113,1,0);
		 return;
      }
      sub_492BB6(v76);
      v56[1] = (const char *)7;
      v5 = &byte_4F09B0[32 * (unsigned __int8)*(&byte_4F0CCF[4 * ptr_507BC0->dword_00001C] + dword_F8B19C)];
      if ( v5[pParty->uDaysPlayed % 7u + 1] )
      {
        compile_error(level name should not be globally-defined);
  //if ( _strcmpi(CurrentLevelName, (char *)pMapStats->pMapInfos[(unsigned __int8)*v5].pLocationFilename))
        if (0)
        {
          SaveGame(1, 0);
          compile_error(level name should not be globally-defined);
  //strcpy(CurrentLevelName, (char *)pMapStats->pMapInfos[(unsigned __int8)*v5].pLocationFilename);
          v8 = *((_DWORD *)v5 + 6);
          v9 = *((_DWORD *)v5 + 5);
          v10 = *((_DWORD *)v5 + 4);
          dword_6BE364 |= 1u;
          dword_5B65B8 = 0;
          dword_5B65BC = 0;
          dword_5B65B4 = v8;
          v11 = *((_DWORD *)v5 + 3);
          uGameState = 2;
          dword_5B65A8 = v11;
          dword_5B65AC = v10;
          dword_5B65B0 = v9;
          dword_5B65C0 = v11 | v10 | v9 | v8;
        }
        else
        {
          v6 = *((_DWORD *)v5 + 3);
          pParty->sRotationX = 0;
          pParty->vPosition.x = v6;
          v7 = *((_DWORD *)v5 + 4);
          pOldCamera->sRotationY = 0;
          pParty->dword_007778 |= 2;
          pParty->vPosition.y = v7;
          pParty->vPosition.z = *((_DWORD *)v5 + 5);
          pParty->dword_000700 = pParty->vPosition.z;
          pParty->sRotationY = *((_DWORD *)v5 + 6);
        }
        sub_4B1E92(ptr_507BC0->dword_00001C, 2);
        v12 = (unsigned __int8)v5[8];
        if (ptr_507BC0->dword_00001C >= 63 )
        {
          v74 = 72;
          v13 = 2500;
          v14 = CheckHiredNPCSpeciality(8);
          if ( v14 )
            v12 -= 2;
          v15 = CheckHiredNPCSpeciality(9);
          if ( v15 )
            v12 -= 3;
          v56[1] = (const char *)45;
        }
        else
        {
          v74 = 71;
          v13 = 1500;
          v56[1] = (const char *)35;
        }
        v16 = CheckHiredNPCSpeciality((int)v56[1]);
        if ( v16 )
          v12 -= 2;
        v17 = CheckHiredNPCSpeciality(0x2C);
        if ( v17 )
          --v12;
        if ( v12 < 1 )
          v12 = 1;
        sub_4B1BDB(1440 * v12);
        Player_PlaySound((Player *)v72, v74, 0);
        v18 = GetTickCount();
        v19 = v18 + v13;
        if ( v19 < v18 )
          v19 = v18;
        while ( GetTickCount() < v19 )
          sqrt(3.1415926);
        while ( sub_4BD8B5() )
          ;
		 dword_50CBD0.PutMessageToQueue(113,0,0);
       /* if ( dword_50CBD0[0] < 40 )
        {
          dword_50CBD0[3 * dword_50CBD0[0] + 1] = 113;
          dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
LABEL_33:
          dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
          return;
        }	*/
      }
      else
      {
        dword_F8B19C = 1;
        pAudioPlayer->sub_4AA306(27, 0, 0, -1, 0, 0, 0, 0);
      }
    }
  }
}

//----- (0046086A) --------------------------------------------------------
bool MaybeDoAutosave()
{
  int v1; // eax@4
  int v2; // edx@5
  FILE *v3; // eax@7
  char v4; // zf@7

  //local struct
  LODFileHeader lod_header; // [sp+Ch] [bp-16Ch]@3
 // char Dest[80 + 4*array_size_unknown]; // [sp+10h] [bp-168h]@3
 // char v8[80 + 4*array_size_unknown]; // [sp+60h] [bp-118h]@3
 // int v9; // [sp+B0h] [bp-C8h]@3	dword00A4
//  int v10; // [sp+B4h] [bp-C4h]@3  dword00A8

  LODIndex  v11; // [sp+10Ch] [bp-6Ch]@4

  LODIndex v12; // [sp+12Ch] [bp-4Ch]@9
 // int v13; // [sp+140h] [bp-38h]@9	   size_data

  //local struct
  LODIndex v14; ; // [sp+14Ch] [bp-2Ch]@3
 // int v15; // [sp+164h] [bp-14h]@3		 reserved1
 // __int16 v16; // [sp+16Ah] [bp-Eh]@3	reserved3

  int v17; // [sp+16Ch] [bp-Ch]@5
  void *DstBuf; // [sp+170h] [bp-8h]@3
  int v19; // [sp+174h] [bp-4h]@5

  if (pVideoPlayer && pVideoPlayer->IsAnyMovieLoaded())
    pVideoPlayer->UnloadAll();

  DstBuf = NamedMemAlloc(char, 1000000, "Autosave tmp data");
  LODFile_New_LOD.Close_Written_File();
  remove("data\\new.lod");

  Reset_LODFileHeader(&lod_header);
  strcpy(lod_header.a1, "MMVII");
  strcpy(lod_header.a2, "newmaps for MMVII");
  lod_header.dword00A4 = 100;
  lod_header.dword00A8 = 0;

  Reset_LODIndex(&v14);
  v14.reserved1 = 0;
  v14.reserved3 = 0;

  strcpy(&v14.pFilename[0], "current");

  LODFile_New_LOD.Write_Lod_Header(&lod_header, &v14, "data\\new.lod");

  if (!LODFile_New_LOD.Load_File("data\\new.lod", 0))
  { 
   MemFree(DstBuf);
   return false;
  }

    LODFile_New_LOD.OpenTempFile();
    LODFile_New_LOD.uNumSubidices = 0;
    Reset_LODIndex(&v11);
    v1 = LODFile_Games_LOD.uNumSubidices / 2;
    if (LODFile_Games_LOD.uNumSubidices / 2 < LODFile_Games_LOD.uNumSubidices)
    {
      v2 = v1;
      v19 = v1;
      v17 = LODFile_Games_LOD.uNumSubidices - v1;
      while ( 1 )
      {
       memcpy(&v11, &LODFile_Games_LOD.pLODSubIndexNamedBuffer[v2], sizeof(LODIndex));
       v3 = LODFile_Games_LOD.Find_Container(LODFile_Games_LOD.pLODSubIndexNamedBuffer[v2].pFilename, 1);
       locked_fread(DstBuf, LODFile_Games_LOD.pLODSubIndexNamedBuffer[v2].size_data, 1, v3);
        LODFile_New_LOD.Append_item_to_temp_file( &v11, DstBuf);
        v19 += 1;
        v17-- ;
        if (v17==0)
          break;
        v2 = v19;
      }
    }
    Reset_LODIndex(&v12);
    strcpy((char*)&saves_hdr[0].name1, "out01.odm");
    strcpy(&v12.pFilename[0], "header.bin");
    v12.size_data = 100;
    LODFile_New_LOD.Append_item_to_temp_file(&v12, &saves_hdr[0]);
    LODFile_New_LOD.Write_SubIndex();

    pParty->vPosition = Vec3<int>(12552, 1816, 0);

    //Camera_SetDirection(pParty->pCamera, 0, 0, 1);
    runtime_warning(deprication);
    {
     pParty->sRotationX = 0;
     pParty->sRotationY = 512;
    }

    pParty->vOldPosition = Vec3<int>(12552, 1816, 0);
    pParty->sOldRotationY = 512;
    pParty->sOldRotationX = 0;

    pParty->dword_000700 = 0;


    SaveGame(1, 1);

  MemFree(DstBuf);
  return true;
}


//----- (00410DEC) --------------------------------------------------------
int __cdecl sub_410DEC_DrawSpellbook_Beacons()
{
  char *v0; // eax@1
  Player *v1; // esi@1
  __int16 v2; // ax@6
  int result; // eax@11
  int v4; // esi@13
  int v5; // ecx@13
  char v6; // zf@13
  unsigned int v7; // eax@14
  unsigned int v8; // esi@14
  int v9; // esi@14
  int v10; // eax@14
  __int64 v11; // edx@15
  int v12; // eax@19
  int v13; // ecx@22
  int v14; // eax@27
  unsigned __int8 v15; // sf@29
  unsigned __int8 v16; // of@29
  int v17; // [sp-10h] [bp-98h]@25
  unsigned __int16 v18; // [sp-Ch] [bp-94h]@25
  int v19; // [sp-8h] [bp-90h]@21
  const char *v20; // [sp-8h] [bp-90h]@25
  class cTexture* v21; // [sp-4h] [bp-8Ch]@4
  int v22; // [sp-4h] [bp-8Ch]@21
  int v23; // [sp-4h] [bp-8Ch]@25

  GUI::Window local_0C;
  //int v24; // [sp+Ch] [bp-7Ch]@1
  //int v25; // [sp+10h] [bp-78h]@1
  //int v26; // [sp+14h] [bp-74h]@1
  //int v27; // [sp+18h] [bp-70h]@1
  //int v28; // [sp+1Ch] [bp-6Ch]@1
  //int v29; // [sp+20h] [bp-68h]@1

  int v30; // [sp+64h] [bp-24h]@14
  __int64 v31; // [sp+68h] [bp-20h]@14
  int v32; // [sp+70h] [bp-18h]@13
  char *Str; // [sp+74h] [bp-14h]@14
  int v34; // [sp+78h] [bp-10h]@11
  int v35; // [sp+7Ch] [bp-Ch]@12
  int v36; // [sp+80h] [bp-8h]@12
  int v37; // [sp+84h] [bp-4h]@6

  v1 = &pParty->pPlayers[dword_506348];
  Render_DrawIndexedTexture(pD3DRenderer, 8, 8, dword_506358[byte_50656C]);
  v0 = (char *)pGlobalTXT_LocalizationStrings[LOCSTR_RECALL_BEACON];
  local_0C.uFrameX = 8;
  local_0C.uFrameY = 8;
  local_0C.uFrameWidth = 428;
  local_0C.uFrameHeight = 344;
  local_0C.uFrameZ = 435;
  local_0C.uFrameW = 351;
  if ( !byte_50656C )
    v0 = (char *)pGlobalTXT_LocalizationStrings[LOCSTR_SET_BEACON];
  wsprintfA((char *)TmpBuf, "%s", v0);
  GUIWindow_DrawText(&local_0C, pBook2Font, 0, 22, 0, (char *)TmpBuf, 3);
  if ( byte_50656C )
  {
   Render_DrawTransparentTexture(pD3DRenderer, dword_506518->uX, dword_506518->uY, uTextureID_tab_an_6b__zoom_on);
    v21 = uTextureID_tab_an_6a__zoom_off;
  }
  else
  {
    Render_DrawTransparentTexture(pD3DRenderer, dword_506518->uX, dword_506518->uY, uTextureID_tab_an_6a__zoom_off);
    v21 = uTextureID_tab_an_6b__zoom_on;
  }
  Render_DrawTransparentTexture(pD3DRenderer, dword_506514->uX, dword_506514->uY, v21);
  v2 = *((_WORD *)v1 + 146);
  v37 = 1;
  if ( HIBYTE(v2) & 1 || (_BYTE)v2 < 0 )
  {
    v37 = 5;
  }
  else
  {
    if ( v2 & 0x40 )
      v37 = 3;
  }
  result = 0;
  v34 = 0;
  if ( v37 > 0 )
  {
    v36 = (int)&cSaveTumbnail[0];
    v35 = (int)(v1 + 1707);
    while ( 1 )
    {
      local_0C.uFrameWidth = 92;
      v4 = 4 * result;
      local_0C.uFrameHeight = 68;
      v5 = dword_4E249C[result];
      local_0C.uFrameY = dword_4E24B0[result];
      v32 = local_0C.uFrameY;
      local_0C.uFrameX = v5;
      local_0C.uFrameW = local_0C.uFrameY + 67;
      v6 = *(_DWORD *)(v36 + 36) == 0;
      local_0C.uFrameZ = v5 + 91;
      if ( !v6 )
        break;
      if ( !byte_50656C )
      {
        Render_DrawTransparentTexture(
          pD3DRenderer,
          *(int *)((char *)&dword_4E24C4 + v4),
          *(int *)((char *)&dword_4E24D8 + v4),
          uTextureID_lb_bordr__townport__sbquicknot);
        v23 = 3;
        v20 = (char *)pGlobalTXT_LocalizationStrings[LOCSTR_AVAILABLE];
        v18 = 1;
        v14 = GUIFont_CalculateTextHeight(ptr_5C35E4, pGlobalTXT_LocalizationStrings[LOCSTR_AVAILABLE], &local_0C, 0, 0);
        v17 = local_0C.uFrameHeight / 2 - v14 / 2;
        goto LABEL_28;
      }
LABEL_29:
      v36 += 40;
      v35 += 28;
      result = v34 + 1;
      compile_error();//v16 = __SETO__(v34 + 1, v37);
      v15 = v34++ + 1 - v37 < 0;
      if ( !(v15 ^ v16) )
        goto LABEL_30;
    }
    Render_DrawTransparentTexture(
      pD3DRenderer,
      *(int *)((char *)&dword_4E24C4 + v4),
      *(int *)((char *)&dword_4E24D8 + v4),
      uTextureID_lb_bordr__townport__sbquicknot);

    Render_DrawRGBTexture(pD3DRenderer, *(int *)((char *)&dword_4E249C + v4), *(int *)((char *)&dword_4E24B0 + v4), (cPCXTexture *)v36);
    v9 = v35;
    Str = (char *)pMapStats->pMapInfos[sub_410D99(*(_WORD *)(v35 + 26))].pLocationName;
    v10 = GUIFont_CalculateTextHeight(ptr_5C35E4, (unsigned char *)Str, &local_0C, 0, 0);
    local_0C.uFrameY += -6 - v10;
    GUIWindow_DrawText(&local_0C, ptr_5C35E4, 0, 0, 1u, Str, 3);

    v31 = *(_QWORD *)v9 - pParty->qword_00002C;	   //time
    v30 = (unsigned __int64)((signed __int64)((double)v31 * 0.234375) / 60 / 60) >> 32;	 //hours
    v8 = (signed __int64)((double)v31 * 0.234375) / 60 / 60;
    v7 = v8 / 24;
    if ( (unsigned int)((signed __int64)((double)v31 * 0.234375) / 60 / 60) / 24 )
    {
      v13 = (int)pGlobalTXT_LocalizationStrings[LOCSTR_DAYS];
      if ( v7 > 1 )
      {
LABEL_24:
        v22 = v13;
        v19 = v7 + 1;
LABEL_25:
        wsprintfA((char *)TmpBuf, "%lu %s", v19, v22);
        v23 = 3;
        v20 = (char *)TmpBuf;
        v18 = 1;
        local_0C.uFrameY = v32 + local_0C.uFrameHeight + 4;
        v17 = 0;
LABEL_28:
        GUIWindow_DrawText(&local_0C, ptr_5C35E4, 0, v17, v18, v20, v23);
        goto LABEL_29;
      }
    }
    else
    {
      HIDWORD(v11) = v30;
      LODWORD(v11) = (signed __int64)((double)v31 * 0.234375) / 60 / 60;
      if ( v11 + 1 <= 23 )
      {
        if ( v30 < 0 || v30 <= 0 && v8 <= 1 )
          v12 = (int)pGlobalTXT_LocalizationStrings[LOCSTR_HOUR];
        else
          v12 = (int)pGlobalTXT_LocalizationStrings[LOCSTR_HOURS];
        v22 = v12;
        v19 = v8 + 1;
        goto LABEL_25;
      }
    }
    v13 = (int)pGlobalTXT_LocalizationStrings[LOCSTR_DAY];
    goto LABEL_24;
  }
LABEL_30:
  if ( byte_506360 )
  {
    result = 0;
  /*  if ( dword_50CBD0[0] < 40 )
    {
      dword_50CBD0[3 * dword_50CBD0[0] + 1] = 181;
      dword_50CBD0[3 * dword_50CBD0[0] + 2] = 0;
      result = 3 * dword_50CBD0[0] + 3;
      dword_50CBD0[3 * dword_50CBD0[0] + 3] = 0;
      ++dword_50CBD0[0];
    }	*/
	 dword_50CBD0.PutMessageToQueue(181,0,0);
  }
  return result;
}


//----- (00411B59) --------------------------------------------------------
void sub_411B59(int a1, int a2)
{
  FILE *v2; // ebx@1
 // int v3; // edi@1
//  int v4; // esi@1
  FILE *v5; // eax@2
 // int result; // eax@3
  char Str1[64]; // [sp+Ch] [bp-44h]@1
 // int v8; // [sp+4Ch] [bp-4h]@1

 // v4 = a1;
 // v8 = a2;
 // v3 = a1 + 1;
  wsprintfA(Str1, "data\\lloyd%d%d.pcx", a2, a1 + 1);
  v2 = fopen(Str1, "rb");
  if ( v2 )
  {
    cSaveTumbnail[a1].LoadPCXFromFile(v2, 0, true);
    fclose(v2);
  }
  else
  {
    wsprintfA(Str1, "lloyd%d%d.pcx", a2, a1 + 1);
    v5 = LODFile_New_LOD.Find_Container( Str1, 1);
    if ( v5 )
    {
      cSaveTumbnail[a1].LoadPCXFromFile(v5, 0, false);
    }
    else
    {
      cSaveTumbnail[a1].pPixels = 0;
    }
  }
 // return result;
}

//----- (0045E006) --------------------------------------------------------
void *__cdecl sub_45E006_FreeSaveThumbnails()
{
 
  void *result=NULL; // eax@2
  for (int i=0; i<45; i++)
	  {
		if (cSaveTumbnail[i].pPixels)
			{  
			MemFree(cSaveTumbnail[i].pPixels);
			memset(&cSaveTumbnail[i],0, sizeof(cPCXTexture));
			}

	  }
  
  return result;
}













void LoadUI_MainMenu()
{
 /* Main menu:

    GUI
    |___ Window [HostWindow]
         |
         |_________ Image [Window Background, mm7title.png]
         |
         |_________ WindowOverlapped [CopyrightWindow]
         |          |
         |          |____________ Image    [Window Background]
         |          |
         |          |____________ Image[4] [Window Borders]
         |          |
         |          |____________ Image[4] [Window Corners]
         |          |
         |          |____________ Label    [Copyright text]
         |
         |
         |_________ Window [MenuWindow]
                    |
                    |__________ Image  [Window Background]
                    |
                    |__________ Button [New Game]
                    |
                    |__________ Button [Load Game]
                    |
                    |__________ Button [Options]
                    |
                    |__________ Button [Credits]
                    |
                    |__________ Button [Exit]
*/
 pMainGUI->Reset();
 {
   // MainMenu Background Window
  GUI::Window *pMainMenu_HostWindow = pMainGUI->CreateControl<GUI::Window>(0);
  pMainMenu_HostWindow->Initialize(&Rect<float>(0, 640, 0, 480));
  {
   GUI::Image *pMainMenu_WindowBackground = pMainGUI->CreateControl<GUI::Image>(pMainMenu_HostWindow);
   pMainMenu_WindowBackground->Initialize(0, L"mm7title", GUI::Align::Center, GUI::Align::Center);

   pMainMenu_HostWindow->SetBackgroundImage(pMainMenu_WindowBackground);
  }

  // MainMenu Copyright Window
  GUI::WindowOverlapped *pMainMenu_CopyrightWindow = pMainGUI->CreateControl<GUI::WindowOverlapped>(pMainMenu_HostWindow);
  pMainMenu_CopyrightWindow->Initialize(&Rect<float>(6, 634, 330, 470));
  {
   GUI::Image *pMainMenu_CopyrightWindowBackground = pMainGUI->CreateControl<GUI::Image>(pMainMenu_CopyrightWindow);
   pMainMenu_CopyrightWindowBackground->Initialize(0, L"Parchment", GUI::Align::Wrap, GUI::Align::Wrap);
   pMainMenu_CopyrightWindow->SetBackgroundImage(pMainMenu_CopyrightWindowBackground);

   GUI::Image *pMainMenu_CopyrightWindowCornerUL = pMainGUI->CreateControl<GUI::Image>(pMainMenu_CopyrightWindow),
              *pMainMenu_CopyrightWindowCornerUR = pMainGUI->CreateControl<GUI::Image>(pMainMenu_CopyrightWindow),
              *pMainMenu_CopyrightWindowCornerLL = pMainGUI->CreateControl<GUI::Image>(pMainMenu_CopyrightWindow),
              *pMainMenu_CopyrightWindowCornerLR = pMainGUI->CreateControl<GUI::Image>(pMainMenu_CopyrightWindow);
   GUI::Image *pMainMenu_CopyrightWindowBorderLeft = pMainGUI->CreateControl<GUI::Image>(pMainMenu_CopyrightWindow),
              *pMainMenu_CopyrightWindowBorderRight = pMainGUI->CreateControl<GUI::Image>(pMainMenu_CopyrightWindow),
              *pMainMenu_CopyrightWindowBorderTop = pMainGUI->CreateControl<GUI::Image>(pMainMenu_CopyrightWindow),
              *pMainMenu_CopyrightWindowBorderBottom = pMainGUI->CreateControl<GUI::Image>(pMainMenu_CopyrightWindow);

   pMainMenu_CopyrightWindowCornerUL->Initialize(0, L"C_UL-b", GUI::Align::Negative, GUI::Align::Negative);
   pMainMenu_CopyrightWindowCornerUR->Initialize(0, L"C_UR-b", GUI::Align::Positive, GUI::Align::Negative);
   pMainMenu_CopyrightWindowCornerLL->Initialize(0, L"C_LL-b", GUI::Align::Negative, GUI::Align::Positive);
   pMainMenu_CopyrightWindowCornerLR->Initialize(0, L"C_LR-b", GUI::Align::Positive, GUI::Align::Positive);

   pMainMenu_CopyrightWindowBorderLeft->Initialize(0, L"WE-l-b", GUI::Align::Negative, GUI::Align::Wrap);
   pMainMenu_CopyrightWindowBorderRight->Initialize(0, L"WE-r-b", GUI::Align::Positive, GUI::Align::Wrap);
   pMainMenu_CopyrightWindowBorderTop->Initialize(0, L"WE-t-b", GUI::Align::Wrap, GUI::Align::Negative);
   pMainMenu_CopyrightWindowBorderBottom->Initialize(0, L"WE-bot-b", GUI::Align::Wrap, GUI::Align::Positive);

   pMainMenu_CopyrightWindow->SetStyle(pMainMenu_CopyrightWindowBorderLeft, pMainMenu_CopyrightWindowBorderRight,
                                       pMainMenu_CopyrightWindowBorderTop, pMainMenu_CopyrightWindowBorderBottom,
                                       pMainMenu_CopyrightWindowCornerUL, pMainMenu_CopyrightWindowCornerUR,
                                       pMainMenu_CopyrightWindowCornerLL, pMainMenu_CopyrightWindowCornerLR);

   GUI::Label *pMainMenu_CopyrightWindowText = pMainGUI->CreateControl<GUI::Label>(pMainMenu_CopyrightWindow);
   pMainMenu_CopyrightWindowText->Initialize(&Rect<float>(12, 620, 347, 468), (char *)pGlobalTXT_LocalizationStrings[LOCSTR_3DO_COPYRHT],
                                            pFontSmallnum, &_Render::Color(1.0f, 1.0f, 1.0f, 1.0f), GUI::Align::Center, 0, 0);

   pMainMenu_CopyrightWindow->AddChild(pMainMenu_CopyrightWindowText);
   pMainMenu_CopyrightWindow->Activate(true);
  }
  pMainMenu_HostWindow->AddChild(pMainMenu_CopyrightWindow);


  // MainMenu Right tab with buttons
  GUI::Window *pMainMenu_MenuWindow = pMainGUI->CreateControl<GUI::Window>(pMainMenu_HostWindow);
  pMainMenu_MenuWindow->Initialize(&Rect<float>(400, 600, 200, 400));
  {
   pMainMenu_MenuWindow->Activate(false);
  }
  pMainMenu_HostWindow->AddChild(pMainMenu_MenuWindow);


  pMainMenu_HostWindow->Activate(true);
  pMainGUI->SetMainWindow(pMainMenu_HostWindow);
 }
}