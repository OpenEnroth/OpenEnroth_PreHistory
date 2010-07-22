#include "Party.h"

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
  if ( dword_ACD834 == 1 )
  {
    if ( dword_4F885C != 2 || (dword_4F8878[0] & 7) != 4 )
      return 0;
    v2 = dword_4F8878[0] >> 3;
    return v2 + 1;
  }
  v5 = 0;
  v4 = (int)((char *)v1 + 8960);
  while ( 1 )
  {
    v6 = pPlayers[v5];
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
    if ( sub_492C0B(&_this->pPlayers[i]) )
    {
      v5 = sub_49125A(&_this->pPlayers[i]);
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

 memset(&_this->qword_00002C, 0, sizeof(struct Party) - 0x2C);

 
 _this->uEyelevel = 160;
 _this->pCamera = CreateCamera();
 Camera_SetProjection(_this->pCamera, 3.14159f * 0.361 /*65 deg*/, 640.0 / 480.0, 0.01, 100);

  _this->byte_000708 = 15;

  _this->uNumFood = 7;
  _this->uNumGold = 200;
  _this->uNumGoldInBank = 0;
  _this->dword_000884 = 0;

 _this->uAlignment = 1;
 SetupUserInterface(_this->uAlignment);

  _this->qword_00002C = 138240;
  _this->qword_000034 = 138240;

  _this->dword_00087C = 0;

 uActiveCharacter = 1;
 ptr_A750C4 = &_this->pPlayers[uActiveCharacter - 1];

 {
  pPlayers[0] = &_this->pPlayers[0];
  Player_Reset(&_this->pPlayers[0], CLASS_KNIGHT);

  _this->pPlayers[0].uFace = 17;
  _this->pPlayers[0].dword_001920 = 17;
  _this->pPlayers[0].dword_001924 = 17;
  Player_SetInitialStats(&_this->pPlayers[0]);

  _this->pPlayers[0].uSex = Player_GetSex(&_this->pPlayers[0]);
  Player_RandomizeName(&_this->pPlayers[0]);
 }


 {
  pPlayers[1] = &_this->pPlayers[1];
  Player_Reset(&_this->pPlayers[1], CLASS_THIEF);

  _this->pPlayers[1].uFace = 3;
  _this->pPlayers[1].dword_001920 = 3;
  _this->pPlayers[1].dword_001924 = 3;
  Player_SetInitialStats(&_this->pPlayers[1]);
 
  _this->pPlayers[1].uSex = Player_GetSex(&_this->pPlayers[1]);
  Player_RandomizeName(&_this->pPlayers[1]);
 }


 { 
  pPlayers[2] = &_this->pPlayers[2];
  Player_Reset(&_this->pPlayers[2], CLASS_CLERIC);
 
  _this->pPlayers[2].uFace = 14;
  _this->pPlayers[2].dword_001920 = 14;
  _this->pPlayers[2].dword_001924 = 14;
  Player_SetInitialStats(&_this->pPlayers[2]);
 
  _this->pPlayers[2].uSex = Player_GetSex(&_this->pPlayers[2]);
  Player_RandomizeName(&_this->pPlayers[2]);
 }


 { 
  pPlayers[3] = &_this->pPlayers[3];
  Player_Reset(&_this->pPlayers[3], CLASS_SORCERER);

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
    sub_458585(pPlayers[i]->array_0017A0[j]);
 }

 for (i = 0; i < 20; ++i)
   sub_458585(_this->array_00088C[i]);

 dword_506F48 = 100;
 _this->dword_007778 = 0;


  sub_449B7E(_this->unk_000765, 1, 1);
  sub_449B7E(_this->unk_000765, 2, 1);
  sub_449B7E(_this->unk_000765, 3, 1);
  sub_449B7E(_this->unk_000765, 4, 1);
  sub_449B7E(_this->unk_000765, 5, 1);
  sub_449B7E(_this->unk_000765, 6, 1);

 for (i = 0; i < 4; ++i)
 {
  pPlayers[i]->word_001A9C = 1;
  pPlayers[i]->word_001A9E = 0;
  pPlayers[i]->word_001AA0 = rand() % 256 + 128;
 }

 memcpy(pNPCStats->pNPCData2, pNPCStats->pNPCData, 501 * sizeof(struct NPCData));
 memcpy(pNPCStats->word_017F5A, pNPCStats->array_017EF4, 51 * sizeof(short));
 dword_72D778 |= 0x80u;
 sub_494035();
 class24_fn1(pClass24_global);
 return 0;
}



//----- (0048C6F6) --------------------------------------------------------
int Party_AddItem(struct Party *_this, int a2)
{
  int v2; // eax@1
  signed int v3; // edx@4
  int v4; // ecx@4
  const char *v5; // eax@8
  int v6; // ebx@10
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
  if (!byte_5D2A00[v2 + 18])
    *(_DWORD *)(a2 + 20) |= 1u;
  v18 = 0;
  v19 = 1;
  v21 = 3;
  v20 = 2;
  if ( uActiveCharacter )
  {
    v4 = uActiveCharacter - 1;
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
    v8 = LODFile_LoadTexture(pLODFile_Icons_LOD, v5, 2);
    v6 = v8 != -1 ? 72 * v8 + 7145548 : 0;
    v24 = dword_506128;
    v7 = 0;
    while ( 1 )
    {
      v10 = (int)((char *)v23 + 6972 * *(&v18 + v7) + 2508);
      v22 = (char *)v23 + 6972 * *(&v18 + v7) + 2508;
      v9 = CreateItemInInventory(v22, -1, *(_DWORD *)a2);
      if ( v9 )
        break;
      ++v7;
      if ( v7 >= 4 )
      {
        if ( v24 == v9 )
        {
          sub_40F77C(v6);
          sub_40F9C5(pLODFile_Icons_LOD);
        }
        goto LABEL_15;
      }
    }
    memcpy((void *)(v10 + 36 * v9 + 496), (const void *)a2, 0x24u);
    ItemGen_Reset(a2);
    AudioPlayer_sub_4AA306(pAudioPlayer, 200, 0, 0, -1, 0, 0, 0, 0);
    sub_4948B1(v22, 60, 0);
    if ( !v24 )
    {
      sub_40F77C(v6);
      sub_40F9C5(pLODFile_Icons_LOD);
    }
    result = 1;
  }
  else
  {
    v16 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Party.cpp";
    v25 = &v12;
    sub_40E2C8(&v12, "Invalid picture_name detected ::addItem()", (int)((char *)&a2 + 3));
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
  char Dst[32 + array_size_unknown]; // [sp+1Ch] [bp-24h]@10
 int i;

 lstrcpyA(_this->pPlayers[0].sName, pGlobalTXT_LocalizationStrings[509]);
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

 _this->pPlayers[0].pActiveSkills[SKILL_SWORD] = 1;
 _this->pPlayers[0].pActiveSkills[SKILL_BOW] = 1;
 _this->pPlayers[0].pActiveSkills[SKILL_LEATHER] = 1;
 _this->pPlayers[0].pActiveSkills[SKILL_ARMSMASTER] = 1;




 lstrcpyA(_this->pPlayers[1].sName, pGlobalTXT_LocalizationStrings[506]);
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

 _this->pPlayers[1].pActiveSkills[SKILL_DAGGER] = 1;
 _this->pPlayers[1].pActiveSkills[SKILL_LEATHER] = 1;
 _this->pPlayers[1].pActiveSkills[SKILL_DISARMTRAP] = 1;
 _this->pPlayers[1].pActiveSkills[SKILL_STEALING] = 1;



 lstrcpyA(_this->pPlayers[2].sName, pGlobalTXT_LocalizationStrings[508]);
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

 _this->pPlayers[2].pActiveSkills[SKILL_MACE] = 1;
 _this->pPlayers[2].pActiveSkills[SKILL_LEATHER] = 1;
 _this->pPlayers[2].pActiveSkills[SKILL_BODYMAGIC] = 1;
 _this->pPlayers[2].pActiveSkills[SKILL_ALCHEMY] = 1;



 lstrcpyA(_this->pPlayers[3].sName, pGlobalTXT_LocalizationStrings[507]);
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

 _this->pPlayers[3].pActiveSkills[SKILL_STAFF] = 1;
 _this->pPlayers[3].pActiveSkills[SKILL_LEATHER] = 1;
 _this->pPlayers[3].pActiveSkills[SKILL_FIREMAGIC] = 1;
 _this->pPlayers[3].pActiveSkills[SKILL_AIRMAGIC] = 1;

  
 v4 = _this;
 v2 = 10;

 v20 = 4;
 i = 0;
 while ( 1 )
  {
    v5 = &_this->pPlayers[i];

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
    ItemGen_Reset(Dst);
    if ( a2 )
    {
      sub_456620(pClass40, 2, 40, Dst);
      sub_492826(&_this->pPlayers[i], -1, Dst);
      v19 = 0;
      do
      {
        if (_this->pPlayers[i].pActiveSkills[v19])
        {
          switch (v19) // creating skill-related items
          {
            case SKILL_STAFF:
              v16 = 61;
              goto LABEL_25;
            case SKILL_SWORD:
              v16 = 1;
              goto LABEL_25;
            case SKILL_DAGGER:
              v16 = 15;
              goto LABEL_25;
            case SKILL_AXE:
              v16 = 23;
              goto LABEL_25;
            case SKILL_SPEAR:
              v16 = 31;
              goto LABEL_25;
            case SKILL_BOW:
              v16 = 47;
              goto LABEL_25;
            case SKILL_MACE:
              v16 = 50;
              goto LABEL_25;
            case SKILL_SHIELD:
              v16 = 84;
              goto LABEL_25;
            case SKILL_LEATHER:
              v16 = 66;
              goto LABEL_25;
            case SKILL_CHAIN:
              v16 = 71;
              goto LABEL_25;
            case SKILL_PLATE:
              v16 = 76;
LABEL_25:
              WearItem(&_this->pPlayers[i], v16);
              break;
            case SKILL_FIREMAGIC:
              v17 = 401;
              goto LABEL_36;
            case SKILL_AIRMAGIC:
              v17 = 412;
              goto LABEL_36;
            case SKILL_WATERMAGIC:
              v17 = 423;
              goto LABEL_36;
            case SKILL_EARTHMAGIC:
              v17 = 434;
              goto LABEL_36;
            case SKILL_SPIRITMAGIC:
              v17 = 445;
              goto LABEL_36;
            case SKILL_MINDMAGIC:
              v17 = 456;
              goto LABEL_36;
            case SKILL_BODYMAGIC:
              v17 = 467;
              goto LABEL_36;
            case SKILL_IDITEM:
            case SKILL_REPAIR:
            case SKILL_MEDITATION:
            case SKILL_PERCEPTION:
            case SKILL_DIPLOMACY:
            case SKILL_DISARMTRAP:
            case SKILL_LEARNING:
              CreateItemInInventory(&_this->pPlayers[i], -1, 220);
              v17 = 5 * (rand() % 3 + 40);
              goto LABEL_36;
            case SKILL_DODGING:
              v17 = 115;
              goto LABEL_36;
            case SKILL_UNARMED:
              v17 = 110;
LABEL_36:
              CreateItemInInventory(&_this->pPlayers[i], -1, v17);
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
   v1 = _this->array_00088C[i];

    *(_WORD *)(v1 + 10) = 0;
    *(_WORD *)(v1 + 8) = 0;
    *(_DWORD *)v1 = 0;
    *(_DWORD *)(v1 + 4) = 0;
    *(_BYTE *)(v1 + 14) = 0;
    *(_BYTE *)(v1 + 15) = 0;
  }

  for (i = 0; i < 4; ++i)
    sub_48C6AF(&_this->pPlayers[i]);

  ItemGen_Reset(v3 + 0x7754);
  v6 = 636;
  v8 = v3 + 0x777C;
  v7 = 636;
  do
  {
    ItemGen_Reset(v8);
    v8 += 36;
    --v7;
  }
  while ( v7 );

  v9 = v3 + 0xD0EC;
  do
  {
    ItemGen_Reset(v9);
    v9 += 36;
    --v6;
  }
  while ( v6 );

  v11 = v3 + 0x12A5C;
  v10 = 384;
  do
  {
    ItemGen_Reset(v11);
    v11 += 36;
    --v10;
  }
  while ( v10 );

 sub_491BF9(_this);
 _this->flt_01622C = 255.0;
 _this->flt_016230 = 255.0;
 _this->flt_016234 = 255.0;
}


//----- (00491BF9) --------------------------------------------------------
void sub_491BF9(struct Party *_this)
{
  int v1; // edi@1
  int v2; // esi@1
  int v3; // ebx@2
  signed int v9; // [sp+8h] [bp-8h]@1
  signed int v10; // [sp+Ch] [bp-4h]@2
 int i;

  v2 = _this;

 _this->sPartyPosX = 0;
 _this->sPartyPosY = 0;
 _this->sPartyPosZ = 0;

 _this->dword_000700 = 0;
 _this->sRotationX = 0;
 _this->sRotationY = 0;
 _this->dword_0006E8 = 0;

 _this->dword_000028 = 0;
 _this->uDefaultPartyHeight = 120;
 _this->dword_000014 = 37;
 _this->dword_000018 = 25;
 _this->uWalkSpeed = 384;
 _this->dword_000020 = 90;
 _this->dword_000024 = 5;

 _this->dword_0006FC = 0;
 _this->byte_000708 = 15;

 _this->dword_000000 = 25;

  v1 = v2 + 0x216C;
  v9 = 4;
  do
  {
    v3 = v1;
    v10 = 24;
    do
    {
      sub_458585(v3);
      v3 += 16;
    }
    while ( v10-- != 1 );
    v1 += 0x1B3C;
  }
  while ( v9-- != 1 );


 for (i = 0; i < 20; ++i)
   sub_458585(_this->array_00088C[i]);
}