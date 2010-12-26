#include "Party.h"
#include "AudioPlayer.h"
#include "clock.h"
#include "_lod.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"



//----- (0049370F) --------------------------------------------------------
int Party_sub_49370F(struct Party *_this)
{
  void *v1; // esi@1
  int v2; // eax@4
  int v4; // edx@6
  signed int v5; // ecx@6
  int v6; // eax@7
  signed int v7; // edx@23
  int v8; // ecx@23
  int v9; // edi@23
  signed int v10; // esi@23
  int v11; // eax@24
  int v12; // [sp+Ch] [bp-4h]@1

  v1 = _this;
  v12 = 0;
  if (pParty_global->bTurnBasedModeOn)
  {
    if ( dword_4F885C != 2 || (dword_4F8878[0] & 7) != 4 )
      return 0;
    v2 = dword_4F8878[0] >> 3;
    return v2 + 1;
  }
  v5 = 1;
  v4 = (int)((char *)v1 + 8960);
  while ( 1 )
  {
    v6 = (int)pPlayers[v5];
    if ( *(_QWORD *)(v6 + 16)
      || *(_QWORD *)(v6 + 96)
      || *(_QWORD *)(v6 + 104)
      || *(_QWORD *)(v6 + 112)
      || *(_QWORD *)(v6 + 120)
      || *(_QWORD *)(v6 + 128)
      || *(_WORD *)v4 )
    {
      byte_AE3368[v5] = 1;
      goto LABEL_21;
    }
    if ( !byte_AE3368[v5] )
      break;
LABEL_21:
    ++v5;
    v4 += 6972;
    if ( v5 >= 4 )
      goto LABEL_16;
  }
  v12 = v5;
  byte_AE3368[v5] = 1;
LABEL_16:
  if ( (unsigned __int8)(algn_AE3369 & byte_AE336A & byte_AE336B) & byte_AE3368[0] )
    memset(byte_AE3368, 0, 4u);
  v2 = v12;
  if ( v12 )
    return v2 + 1;
  v8 = (int)((char *)v1 + 2714);
  v10 = 0;
  v7 = 1;
  v9 = (int)pPlayers;
  while ( 2 )
  {
    v11 = *(_DWORD *)v9;
    if ( !*(_QWORD *)(*(_DWORD *)v9 + 16)
      && !*(_QWORD *)(v11 + 96)
      && !*(_QWORD *)(v11 + 104)
      && !*(_QWORD *)(v11 + 112)
      && !*(_QWORD *)(v11 + 120)
      && !*(_QWORD *)(v11 + 128)
      && !*(_WORD *)(v8 + 6246) )
    {
      if ( v12 )
      {
        if ( *(_WORD *)v8 > v10 )
        {
          v10 = *(_WORD *)v8;
          goto LABEL_35;
        }
      }
      else
      {
        v10 = *(_WORD *)v8;
LABEL_35:
        v12 = v7;
      }
    }
    v9 += 4;
    ++v7;
    v8 += 6972;
    if ( v7 - 1 < 4 )
      continue;
    return v12;
  }
}




//----- (00497FC5) --------------------------------------------------------
bool Party_sub_497FC5(struct Party *_this)
{
  int v2; // edi@1
  signed int v5; // eax@3
  bool result; // eax@7
 int i;

  v2 = 0;
  for (i = 0; i < 4; ++i)
  {
    if ( Player_sub_492C0B_MaybeIfPlayerConscious(&_this->pPlayers[i]) )
    {
      v5 = Player_sub_49125A(&_this->pPlayers[i]);
      if ( v5 > v2 )
        v2 = v5;
    }
  }
  if ( uLevelMapStatsID && uLevelMapStatsID < 77 )
    result = v2 >= 2 * pMapStats->pMapInfos[uLevelMapStatsID].dword_000028;
  else
    result = 0;
  return result;
}


//----- (004917CE) --------------------------------------------------------
int Party_Reset(struct Party *_this)
{
  int v11; // edx@17
  signed int v12; // edi@18
 int i, j;

 //memset(&_this->qword_00002C, 0, sizeof(struct Party) - 0x2C);

 
 _this->uEyelevel = _this->uDefaultEyelevel;
 _this->uPartyHeight = _this->uDefaultPartyHeight;
 //_this->pCamera = CreateCamera();
 //Camera_SetProjection(_this->pCamera, 3.14159f * 0.361 /*65 deg*/, 640.0 / 480.0, 0.01, 100);

  _this->byte_000708 = 15;

  _this->uNumFood = 7;
  _this->uNumGold = 200;
  _this->uNumGoldInBank = 0;
  _this->dword_000884 = 0;

 _this->uAlignment = 1;
 MenuUI_LoadTextures(_this->uAlignment);

  _this->qword_00002C = 138240;
  _this->qword_000034 = 138240;

 _this->bTurnBasedModeOn = false;

 uActiveCharacter = 1;

 {
  pPlayers[0] = &_this->pPlayers[0];
  Player_Reset(&_this->pPlayers[0], Character::Class::Knight);

  _this->pPlayers[0].uFace = 17;
  _this->pPlayers[0].dword_001920 = 17;
  _this->pPlayers[0].dword_001924 = 17;
  Player_SetInitialStats(&_this->pPlayers[0]);

  _this->pPlayers[0].uSex = Player_GetSex(&_this->pPlayers[0]);
  Player_RandomizeName(&_this->pPlayers[0]);
 }


 {
  pPlayers[1] = &_this->pPlayers[1];
  Player_Reset(&_this->pPlayers[1], Character::Class::Thief);

  _this->pPlayers[1].uFace = 3;
  _this->pPlayers[1].dword_001920 = 3;
  _this->pPlayers[1].dword_001924 = 3;
  Player_SetInitialStats(&_this->pPlayers[1]);
 
  _this->pPlayers[1].uSex = Player_GetSex(&_this->pPlayers[1]);
  Player_RandomizeName(&_this->pPlayers[1]);
 }


 { 
  pPlayers[2] = &_this->pPlayers[2];
  Player_Reset(&_this->pPlayers[2], Character::Class::Cleric);
 
  _this->pPlayers[2].uFace = 14;
  _this->pPlayers[2].dword_001920 = 14;
  _this->pPlayers[2].dword_001924 = 14;
  Player_SetInitialStats(&_this->pPlayers[2]);
 
  _this->pPlayers[2].uSex = Player_GetSex(&_this->pPlayers[2]);
  Player_RandomizeName(&_this->pPlayers[2]);
 }


 { 
  pPlayers[3] = &_this->pPlayers[3];
  Player_Reset(&_this->pPlayers[3], Character::Class::Sorcerer);

  _this->pPlayers[3].uFace = 10;
  _this->pPlayers[3].dword_001920 = 10;
  _this->pPlayers[3].dword_001924 = 10;
  Player_SetInitialStats(&_this->pPlayers[3]);
 
  _this->pPlayers[3].uSex = Player_GetSex(&_this->pPlayers[3]);
  Player_RandomizeName(&_this->pPlayers[3]);
 }


 for (i = 0; i < 4; ++i)
 {
  pPlayers[i]->uTimeToRecovery = 0;

  memset(pPlayers[i]->pConditions, 0, 20 * sizeof(__int64));

  for (j = 0; j < 24; ++j)
    SpellBuff_sub_458585(&pPlayers[i]->pPlayerBuffs[j]);
 }

 for (i = 0; i < 20; ++i)
   SpellBuff_sub_458585(&_this->pPartyBuffs[i]);

 dword_506F48 = 100;
 _this->dword_007778 = 0;


 sub_449B7E((int)_this->unk_000764 + 1, 1, 1);
 sub_449B7E((int)_this->unk_000764 + 1, 2, 1);
 sub_449B7E((int)_this->unk_000764 + 1, 3, 1);
 sub_449B7E((int)_this->unk_000764 + 1, 4, 1);
 sub_449B7E((int)_this->unk_000764 + 1, 5, 1);
 sub_449B7E((int)_this->unk_000764 + 1, 6, 1);

 for (i = 0; i < 4; ++i)
 {
  pPlayers[i]->uDefaultFaceID = 1;
  pPlayers[i]->word_001A9E = 0;
  pPlayers[i]->word_001AA0 = rand() % 256 + 128;
 }

 memcpy(pNPCStats->pNPCData2, pNPCStats->pNPCData, 501 * sizeof(struct NPCData));
 memcpy(pNPCStats->npc_group, pNPCStats->array_017EF4, 51 * sizeof(short));
 dword_72D778 |= 0x80u;
 sub_494035();
 //class24_fn1();
 cClock1.clock_fn1();
 return 0;
}



//----- (0048C6F6) --------------------------------------------------------
int Party_AddItem(struct Party *_this, struct ItemGen *a2)
{
  int v2; // eax@1
  signed int v3; // edx@4
  int v4; // ecx@4
  const char *v5; // eax@8
  cTexture *v6; // ebx@10
  signed int v7; // esi@10
  int v8; // eax@10
  int v9; // eax@11
  int v10; // edi@11
  signed int result; // eax@15
  char v12; // [sp-18h] [bp-40h]@9
  const CHAR *v13; // [sp-14h] [bp-3Ch]@9
  int v14; // [sp-10h] [bp-38h]@9
  int v15; // [sp-Ch] [bp-34h]@9
  const char *v16; // [sp-8h] [bp-30h]@9
  int v18; // [sp+Ch] [bp-1Ch]@3
  int v19; // [sp+10h] [bp-18h]@3
  int v20; // [sp+14h] [bp-14h]@3
  int v21; // [sp+18h] [bp-10h]@3
  void *v22; // [sp+1Ch] [bp-Ch]@9
  void *v23; // [sp+20h] [bp-8h]@1
  int v24; // [sp+24h] [bp-4h]@10
  char *v25; // [sp+30h] [bp+8h]@9

  v23 = _this;
  v2 = 48 * *(_DWORD *)a2;
  if (!*(&pClass40->pItems[v2/48 - 1].uEquipType + 18))
    *(_DWORD *)(a2 + 20) |= 1u;
  v18 = 0;
  v19 = 1;
  v21 = 3;
  v20 = 2;
  if ( uActiveCharacter )
  {
    v4 = uActiveCharacter;
    v3 = 0;
    do
    {
      *(&v18 + v3++) = v4++;
      if ( v4 >= 4 )
        v4 = 0;
    }
    while ( v3 < 4 );
  }
  v5 = *(const char **)(pClass40->pItems[0].pIconName + v2);
  if ( v5 )
  {
  #ifndef OLD_CODE
   wchar_t pTextureFilename[256];
   wsprintfW(pTextureFilename, L"%S", v5);
    v8 = LODFile_Icons_LOD.LODFile_LoadTexture_New( pTextureFilename);
#else
    v8 = LODFile_Icons_LOD.LODFile_LoadTexture( v5,0);
#endif
    v6 = v8 != -1 ? &LODFile_Icons_LOD.aLODHeaders[v8] : 0;
    v24 = bTextureLoading;
    v7 = 0;
    while ( 1 )
    {
      v10 = (int)((char *)v23 + 6972 * *(&v18 + v7) + 2508);
      v22 = (char *)v23 + 6972 * *(&v18 + v7) + 2508;
      v9 = AddItem((Player *)v22, -1, *(_DWORD *)a2);
      if ( v9 )
        break;
      ++v7;
      if ( v7 >= 4 )
      {
        if ( v24 == v9 )
        {
          cTexture_Free(v6);
          LODFile_Icons_LOD.LODFile_sub_40F9C5();
        }
        goto LABEL_15;
      }
    }
    memcpy((void *)(v10 + 36 * v9 + 496), (const void *)a2, 0x24u);
    ItemGen_Reset((ItemGen *)a2);
    pAudioPlayer->sub_4AA306(200, 0, 0, -1, 0, 0, 0, 0);
    Player_PlaySound((Player *)v22, 60, 0);
    if ( !v24 )
    {
      cTexture_Free((cTexture *)v6);
      LODFile_Icons_LOD.LODFile_sub_40F9C5();
    }
    result = 1;
  }
  else
  {
    v16 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Party.cpp";
    v25 = &v12;
    Game_sub_40E2C8(&v12, "Invalid picture_name detected ::addItem()", (int)((char *)&a2 + 3));
    sub_467834(&v22, v12, v13, v14, v15, v16, __LINE__);
LABEL_15:
    result = 0;
  }
  return result;
}


//----- (0049137D) --------------------------------------------------------
int Party_CreateDefaultParty(struct Party *_this, char a2)
{
  signed __int16 v2; // ax@1
  int v4; // esi@1
  int v5; // esi@3
  short *v6; // eax@5
  signed int v7; // edx@5
  unsigned __int8 v9; // zf@37
  char v10; // sf@37
  unsigned __int8 v11; // of@37
  int v12; // eax@38
  signed int v13; // ecx@38
  int result; // eax@42
  char v15; // zf@42
  int v16; // [sp-4h] [bp-44h]@14
  int v17; // [sp-4h] [bp-44h]@26
  int v19; // [sp+14h] [bp-2Ch]@11
  signed int v20; // [sp+18h] [bp-28h]@1

  struct ItemGen local_1C;
  //char Dst[32 + array_size_unknown]; // [sp+1Ch] [bp-24h]@10

 int i;

 lstrcpyA((char *)_this->pPlayers[0].sName, (char *)pGlobalTXT_LocalizationStrings[509]);
 _this->pPlayers[0].uFace = 17;
 _this->pPlayers[0].dword_001920 = 17;
 _this->pPlayers[0].dword_001924 = 17;
 _this->pPlayers[0].dword_001928 = 17;

 _this->pPlayers[0].uStrength = 30;
 _this->pPlayers[0].uIntelligence = 5;
 _this->pPlayers[0].uWillpower = 5;
 _this->pPlayers[0].uEndurance = 13;
 _this->pPlayers[0].uAccuracy = 13;
 _this->pPlayers[0].uSpeed = 14;
 _this->pPlayers[0].uLuck = 7;

 _this->pPlayers[0].pActiveSkills[Character::Skill::Sword] = 1;
 _this->pPlayers[0].pActiveSkills[Character::Skill::Bow] = 1;
 _this->pPlayers[0].pActiveSkills[Character::Skill::Leather] = 1;
 _this->pPlayers[0].pActiveSkills[Character::Skill::Armsmaster] = 1;




 lstrcpyA((char *)_this->pPlayers[1].sName, (char *)pGlobalTXT_LocalizationStrings[506]);
 _this->pPlayers[1].uFace = 3;
 _this->pPlayers[1].dword_001920 = 3;
 _this->pPlayers[1].dword_001924 = 3;
 _this->pPlayers[1].dword_001928 = 3;

 _this->pPlayers[1].uStrength = 13;
 _this->pPlayers[1].uIntelligence = 9;
 _this->pPlayers[1].uWillpower = 9;
 _this->pPlayers[1].uEndurance = 13;
 _this->pPlayers[1].uAccuracy = 13;
 _this->pPlayers[1].uSpeed = 13;
 _this->pPlayers[1].uLuck = 13;

 _this->pPlayers[1].pActiveSkills[Character::Skill::Dagger] = 1;
 _this->pPlayers[1].pActiveSkills[Character::Skill::Leather] = 1;
 _this->pPlayers[1].pActiveSkills[Character::Skill::TrapDisarming] = 1;
 _this->pPlayers[1].pActiveSkills[Character::Skill::Stealing] = 1;



 lstrcpyA((char *)_this->pPlayers[2].sName, (char *)pGlobalTXT_LocalizationStrings[508]);
 _this->pPlayers[2].uFace = 14;
 _this->pPlayers[2].dword_001920 = 14;
 _this->pPlayers[2].dword_001924 = 14;
 _this->pPlayers[2].dword_001928 = 14;

 _this->pPlayers[2].uStrength = 12;
 _this->pPlayers[2].uIntelligence = 9;
 _this->pPlayers[2].uWillpower = 20;
 _this->pPlayers[2].uEndurance = 22;
 _this->pPlayers[2].uAccuracy = 7;
 _this->pPlayers[2].uSpeed = 13;
 _this->pPlayers[2].uLuck = 7;

 _this->pPlayers[2].pActiveSkills[Character::Skill::Mace] = 1;
 _this->pPlayers[2].pActiveSkills[Character::Skill::Leather] = 1;
 _this->pPlayers[2].pActiveSkills[Character::Skill::Body] = 1;
 _this->pPlayers[2].pActiveSkills[Character::Skill::Alchemy] = 1;



 lstrcpyA((char *)_this->pPlayers[3].sName, (char *)pGlobalTXT_LocalizationStrings[507]);
 _this->pPlayers[3].uFace = 10;
 _this->pPlayers[3].dword_001920 = 10;
 _this->pPlayers[3].dword_001924 = 10;
 _this->pPlayers[3].dword_001928 = 10;

 _this->pPlayers[3].uStrength = 5;
 _this->pPlayers[3].uIntelligence = 30;
 _this->pPlayers[3].uWillpower = 9;
 _this->pPlayers[3].uEndurance = 13;
 _this->pPlayers[3].uAccuracy = 13;
 _this->pPlayers[3].uSpeed = 13;
 _this->pPlayers[3].uLuck = 7;

 _this->pPlayers[3].pActiveSkills[Character::Skill::Staff] = 1;
 _this->pPlayers[3].pActiveSkills[Character::Skill::Leather] = 1;
 _this->pPlayers[3].pActiveSkills[Character::Skill::Fire] = 1;
 _this->pPlayers[3].pActiveSkills[Character::Skill::Air] = 1;

  
 v4 = (int)_this;
 v2 = 10;

 v20 = 4;
 i = 0;
 while ( 1 )
  {
    v5 = (int)&_this->pPlayers[i];

    if (!_this->pPlayers[i].uClass)
      _this->pPlayers[i].word_00177E = v2;

    v7 = 0;
    v6 = _this->pPlayers[i].pActiveSkills + 12;
    while (!*v6++)
    {
      ++v7;
      if ( v7 >= 9 )
        goto LABEL_10;
    }
    _this->pPlayers[i].byte_001A4E = v7;

LABEL_10:
    _this->pPlayers[i].word_001A9E = 0;
    ItemGen_Reset(&local_1C);
    if ( a2 )
    {
      class40_sub_456620_CreateSomeSemirandomItem(pClass40, 2, 40, &local_1C);
      AddItem(&_this->pPlayers[i], -1, &local_1C);
      v19 = 0;
      do
      {
        if (_this->pPlayers[i].pActiveSkills[v19])
        {
          switch (v19) // creating skill-related items
          {
            case Character::Skill::Staff:
              v16 = 61;
              goto LABEL_25;
            case Character::Skill::Sword:
              v16 = 1;
              goto LABEL_25;
            case Character::Skill::Dagger:
              v16 = 15;
              goto LABEL_25;
            case Character::Skill::Axe:
              v16 = 23;
              goto LABEL_25;
            case Character::Skill::Spear:
              v16 = 31;
              goto LABEL_25;
            case Character::Skill::Bow:
              v16 = 47;
              goto LABEL_25;
            case Character::Skill::Mace:
              v16 = 50;
              goto LABEL_25;
            case Character::Skill::Shield:
              v16 = 84;
              goto LABEL_25;
            case Character::Skill::Leather:
              v16 = 66;
              goto LABEL_25;
            case Character::Skill::Chain:
              v16 = 71;
              goto LABEL_25;
            case Character::Skill::Plate:
              v16 = 76;
LABEL_25:
              WearItem(&_this->pPlayers[i], v16);
              break;
            case Character::Skill::Fire:
              v17 = 401;
              goto LABEL_36;
            case Character::Skill::Air:
              v17 = 412;
              goto LABEL_36;
            case Character::Skill::Water:
              v17 = 423;
              goto LABEL_36;
            case Character::Skill::Earth:
              v17 = 434;
              goto LABEL_36;
            case Character::Skill::Spirit:
              v17 = 445;
              goto LABEL_36;
            case Character::Skill::Mind:
              v17 = 456;
              goto LABEL_36;
            case Character::Skill::Body:
              v17 = 467;
              goto LABEL_36;
            case Character::Skill::ItemID:
            case Character::Skill::Repair:
            case Character::Skill::Meditation:
            case Character::Skill::Perception:
            case Character::Skill::Diplomacy:
            case Character::Skill::TrapDisarming:
            case Character::Skill::Learning:
              AddItem(&_this->pPlayers[i], -1, 220);
              v17 = 5 * (rand() % 3 + 40);
              goto LABEL_36;
            case Character::Skill::Dodging:
              v17 = 115;
              goto LABEL_36;
            case Character::Skill::Unarmed:
              v17 = 110;
LABEL_36:
              AddItem(&_this->pPlayers[i], -1, v17);
              break;
            default:
              break;
          }
        }
        //v11 = __SETO__(v19 + 1, 36);
        //v9 = v19 == 35;
        //v10 = v19++ - 35 < 0;
        v9 = ++v19 < 37;
      }
      while (v9);

      v12 = v5 + 0x228;
      v13 = 138;
      do
      {
        if ( *(_DWORD *)(v12 - 20) )
          *(_DWORD *)v12 |= 1u;
        v12 += 36;
        --v13;
      }
      while ( v13 );
    }
    _this->pPlayers[i].sHealth = Player_GetMaxHealth(&_this->pPlayers[i]);
    result = Player_GetMaxMana(&_this->pPlayers[i]);
    v15 = v20-- == 1;
    _this->pPlayers[i].sMana = result;
    if ( v15 )
      return result;
    v2 = 10;
  }
}


void Party_ctor(struct Party *_this)
{
  int v1; // eax@1
  int v3; // esi@1
  signed int v6; // ebx@5
  signed int v7; // ebp@5
  int v8; // edi@5
  int v9; // edi@7
  signed int v10; // ebx@9
  int v11; // edi@9
 int i;

  v3 = (int)_this;

  for (i = 0; i < 20; ++i)
  {
   v1 = (int)&_this->pPartyBuffs[i];

    *(_WORD *)(v1 + 10) = 0;
    *(_WORD *)(v1 + 8) = 0;
    *(_DWORD *)v1 = 0;
    *(_DWORD *)(v1 + 4) = 0;
    *(_BYTE *)(v1 + 14) = 0;
    *(_BYTE *)(v1 + 15) = 0;
  }

  for (i = 0; i < 4; ++i)
    Player_ctor(&_this->pPlayers[i]);

  ItemGen_Reset((ItemGen *)(v3 + 0x7754));
  v6 = 636;
  v8 = v3 + 0x777C;
  v7 = 636;
  do
  {
    ItemGen_Reset((ItemGen *)v8);
    v8 += 36;
    --v7;
  }
  while ( v7 );

  v9 = v3 + 0xD0EC;
  do
  {
    ItemGen_Reset((ItemGen *)v9);
    v9 += 36;
    --v6;
  }
  while ( v6 );

  v11 = v3 + 0x12A5C;
  v10 = 384;
  do
  {
    ItemGen_Reset((ItemGen *)v11);
    v11 += 36;
    --v10;
  }
  while ( v10 );

 Party_sub_491BF9_ResetPosMiscAndSpellBuffs(_this);
 _this->flt_01622C = 255.0;
 _this->flt_016230 = 255.0;
 _this->flt_016234 = 255.0;

 _this->pickedItem.uItemID = -1;

 _this->dword_007778 = 0;


 _this->uEyelevel = _this->uDefaultEyelevel = 160;
 _this->uPartyHeight = _this->uDefaultPartyHeight = 192;

 pPartyActionQueue = NamedMemAlloc(ActionQueue, 1, "Party Action Queue");

}


//----- (00491BF9) --------------------------------------------------------
void Party_sub_491BF9_ResetPosMiscAndSpellBuffs(struct Party *_this)
{
 _this->sPartyPosX = 0;
 _this->sPartyPosY = 0;
 _this->sPartyPosZ = 0;

 _this->dword_000700 = 0;
 _this->sRotationX = 0;
 _this->sRotationY = 0;
 _this->dword_0006E8 = 0;

 _this->dword_000028 = 0;
 _this->dword_000014 = 37;
 _this->dword_000018 = 25;
 _this->uWalkSpeed = 384;
 _this->dword_000020 = 90;
 _this->dword_000024 = 5;

 _this->dword_0006FC = 0;
 _this->byte_000708 = 15;

 _this->dword_000000 = 25;

 for (unsigned int i = 0; i < 4; ++i)
   for (unsigned int j = 0; j < 24; ++j)
     SpellBuff_sub_458585(&_this->pPlayers[i].pPlayerBuffs[j]);

 for (unsigned int i = 0; i < 20; ++i)
   SpellBuff_sub_458585(&_this->pPartyBuffs[i]);
}