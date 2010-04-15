#include "FrameTables.h"
#include "classes.h"
#include "_audio.h"
#include "data.h"


//----- (0044E0A0) --------------------------------------------------------
extern char class23_instance[];
void *CTextureFrameTable_Initialize(struct CTextureFrameTable *_this, unsigned char *pSrc)
{
 _this->uNumTextures = *(int *)(pSrc);
 _this->pTextures = class23_AllocatedNamedBuffer(class23_instance, _this->pTextures, _this->uNumTextures * sizeof(struct TextureFrame), "Txt Frames");
 memcpy(_this->pTextures, pSrc + 4, _this->uNumTextures * sizeof(struct TextureFrame));
 return 0;
}



void CTextureFrameTable_ctor(struct CTextureFrameTable *_this)
{
 memset(_this, 0, sizeof(struct CTextureFrameTable));
}







void CIconFrameTable_ctor(struct CIconFrameTable *_this)
{
 memset(_this, 0, sizeof(struct CIconFrameTable));
}

//----- (MM7.exe::00495056) --------------------------------------------------------
void *CIconFrameTable_Initialize(struct CIconFrameTable *_this, void *pSrc)
{
 _this->uNumIcons = *(int *)pSrc;

 _this->pIcons = class23_AllocatedNamedBuffer(class23_instance, _this->pIcons, _this->uNumIcons * sizeof(struct IconFrame), "I Frames");
 memcpy(_this->pIcons, (char *)pSrc + 4, _this->uNumIcons * sizeof(struct IconFrame));

 return _this->pIcons;
}

//----- (MM7.exe::00494F3A) --------------------------------------------------------
unsigned int CIconFrameTable_FindIcon(struct CIconFrameTable *_this, const char *pIconName)
{
 int i;

 if (!_this->uNumIcons)
   return 0;

 for (i = 0; i < _this->uNumIcons; ++i)
 {
  if (!_strcmpi(pIconName, _this->pIcons[i].sIconName))
    return i;
 }
 return 0;
}

//----- (MM7.exe::00494FBF) --------------------------------------------------------
void CIconFrameTable_InitializeIcon(struct CIconFrameTable *_this, unsigned int uIconIdx)
{
 wchar_t pFilepath[256];
 int     i;

 if (uIconIdx >= _this->uNumIcons)
   return;

 i = uIconIdx;
 do
 {
  wsprintfW(pFilepath, L"%S", _this->pIcons[i].sTextureName);
  _this->pIcons[i].uTextureIdx = class17_LoadTextureFromCBM(pClass17_Icons_LOD, pFilepath);
 }
 while (_this->pIcons[i++].word_00001C & 1);
}

//----- (00494F70) --------------------------------------------------------
struct IconFrame *CIconFrameTable_GetFrame(struct CIconFrameTable *_this, unsigned int uIconIdx, unsigned int uFrame)
{
  signed __int16 v5; // dx@2
  int v6; // eax@3
  int v7; // edx@3
  int i; // ecx@3
  int v9; // esi@5

  v5 = _this->pIcons[uIconIdx].word_00001A;
  if ( _this->pIcons[uIconIdx].word_00001C & 0x0001 && v5 != 0 )
  {
    v7 = (uFrame >> 3) % (unsigned __int16)v5;
    v6 = uIconIdx;
    for ( i = uIconIdx; ; ++i)
    {
      v9 = _this->pIcons[i].word_000018;
      if ( v7 <= v9 )
        break;
      v7 -= v9;
      ++v6;
    }
    return &_this->pIcons[v6];
  }
  else
    return &_this->pIcons[uIconIdx];
}











void CSpriteFrameTable_ctor(struct CSpriteFrameTable *_this)
{
 _this->uNumSpriteFrames = 0;
 _this->dword_000004 = 0;
 _this->dword_000008 = 0;
 _this->pSpriteSFrames = 0;
 _this->pSpritePFrames = 0;
 _this->pSpriteEFrames = 0;
}

//----- (MM7.exe::0044D9D7) --------------------------------------------------------
int CSpriteFrameTable_Initialize(struct CSpriteFrameTable *_this, unsigned char *pSrc)
{
 int i;

 _this->uNumSpriteFrames = ((unsigned int *)pSrc)[0];
 _this->dword_000004 = ((unsigned int *)pSrc)[1];

 _this->pSpriteSFrames = class23_AllocatedNamedBuffer(class23_instance, _this->pSpriteSFrames, _this->uNumSpriteFrames * sizeof(struct SpriteFrame), "S Frames");
 _this->pSpritePFrames = class23_AllocatedNamedBuffer(class23_instance, _this->pSpritePFrames, 4 * _this->uNumSpriteFrames, "P Frames");
 _this->pSpriteEFrames = class23_AllocatedNamedBuffer(class23_instance, _this->pSpriteEFrames, 2 * _this->uNumSpriteFrames, "E Frames");

 pSrc += 8;
 memcpy(_this->pSpriteSFrames, pSrc, _this->uNumSpriteFrames * sizeof(struct SpriteFrame));

 pSrc +=_this->uNumSpriteFrames * sizeof(struct SpriteFrame);
 memcpy(_this->pSpriteEFrames, pSrc, _this->dword_000004 * sizeof(short));

 for (i = 0; i < _this->uNumSpriteFrames; ++i)
   _this->pSpritePFrames[i] = &_this->pSpriteSFrames[_this->pSpriteEFrames[i]];

 return _this->uNumSpriteFrames;
}

//----- (0044D8D0) --------------------------------------------------------
struct SpriteFrame *CSpriteFrameTable_fn1(struct CSpriteFrameTable *_this, unsigned int uID, signed int a3)
{
  int v3; // ecx@1
  signed __int16 v5; // dx@2
  int v6; // eax@3
  int v7; // edx@3
  int i; // ecx@3
  int v9; // esi@5
  int result; // eax@6

  v3 = &_this->pSpriteSFrames[uID];
  v5 = *(_WORD *)(v3 + 56);
  if ( *(_BYTE *)(v3 + 44) & 1 && v5 != 0 )
  {
    v7 = (a3 >> 3) % v5;
    v6 = uID;
    for ( i = v3 + 54; ; i += 60 )
    {
      v9 = *(_WORD *)i;
      if ( v7 <= v9 )
        break;
      v7 -= v9;
      ++v6;
    }
    return &_this->pSpriteSFrames[v6];
  }
  else
  {
    return &_this->pSpriteSFrames[uID];
  }
}

//----- (0044D91F) --------------------------------------------------------
int CSpriteFrameTable_fn2(struct CSpriteFrameTable *_this, int a2, signed int a3)
{
  int v3; // edi@1
  int v4; // esi@1
  signed __int16 v5; // ax@2
  int v6; // eax@3
  int i; // edx@3
  int v8; // ecx@3
  int v9; // ecx@3
  int v10; // edx@3
  int v11; // esi@5
  int result; // eax@6

  v3 = *(_DWORD *)(_this + 12);
  v4 = 60 * a2 + v3;
  if ( *(_BYTE *)(v4 + 44) & 1 && (v5 = *(_WORD *)(v4 + 56)) != 0 )
  {
    v9 = v5;
    v10 = a3 % v5;
    v6 = a2;
    v8 = v9 - v10;
    for ( i = v4 + 54; ; i += 60 )
    {
      v11 = *(_WORD *)i;
      if ( v8 <= v11 )
        break;
      v8 -= v11;
      ++v6;
    }
    result = v3 + 60 * v6;
  }
  else
  {
    result = 60 * a2 + v3;
  }
  return result;
}

//----- (0044D4F6) --------------------------------------------------------
int CSpriteFrameTable_fn3(struct CSpriteFrameTable *_this)
{
  int i; // edx@1
  int result; // eax@2

  for ( i = 0; i < _this->uNumSpriteFrames; ++i )
    result = _this->pSpriteSFrames[i].dword_00002C &= 0xFFFFFF7F;
  return result;
}

//----- (0044D513) --------------------------------------------------------
extern struct class35 class35_obj;
extern _UNKNOWN unk_4E7E20;
extern _UNKNOWN unk_4E7E24;
extern _UNKNOWN unk_4E7E28;
void CSpriteFrameTable_fn4(struct CSpriteFrameTable *_this, int a2)
{
  int v2; // esi@1
  __int16 v10; // ax@6
  signed int v11; // edi@10
  __int16 v12; // ax@16
  int v13; // ecx@16
  signed int v14; // edi@19
  size_t v15; // eax@19
  __int16 v16; // ax@27
  int v17; // ecx@27
  signed int v18; // edi@29
  int v19; // eax@30
  __int16 v20; // ax@45
  int v21; // ecx@45
  const char *v22; // [sp-8h] [bp-50h]@12
  const char *v23; // [sp-8h] [bp-50h]@21
  const char *v24; // [sp-8h] [bp-50h]@37
  char *v26; // [sp-4h] [bp-4Ch]@21
  int v27; // [sp-4h] [bp-4Ch]@37
  char v28; // [sp+9h] [bp-3Fh]@19
  char Str; // [sp+Ch] [bp-3Ch]@19
  char Size; // [sp+2Ch] [bp-1Ch]@15
  char Source[4]; // [sp+40h] [bp-8h]@19
  int v32; // [sp+44h] [bp-4h]@19
  int v33; // [sp+50h] [bp+8h]@4
 int i, j;

  v2 = _this;
  if ( a2 > _this->uNumSpriteFrames)
    return;

  if (_this->pSpriteSFrames[a2].dword_00002C >= 0 )
  {
   _this->pSpriteSFrames[a2].dword_00002C |= 0x80;
        v33 = 30 * a2 + 12;

        i = a2;
        while ( 1 )
        {
          _this->pSpriteSFrames[i].word_000034 = class35_sub_48A3BC(&class35_obj,
                                                             _this->pSpriteSFrames[i].word_000032);

          if (_this->pSpriteSFrames[i].dword_00002C & 0x10)
          {
           v10 = sub_4AC7C0(pClass17_Sprites_LOD, _this->pSpriteSFrames[i].sTextureName, _this->pSpriteSFrames[i].word_000032);

           _this->pSpriteSFrames[i].word_000018 = v10;
           for (j = 0; j < 7; ++j)
             _this->pSpriteSFrames[i].array_00001A[j] = v10;
           goto LABEL_46;
          }

          if (_this->pSpriteSFrames[i].dword_00002C & 0x10000)
          {
            v11 = 0;
            do
            {
              switch ( v11 )
              {
                case 3:
                case 4:
                case 5:
                  v22 = (const char *)&unk_4E7E28;
                case 2:
                case 6:
                  v22 = (const char *)&unk_4E7E24;
                case 0:
                case 1:
                case 7:
                  v22 = (const char *)&unk_4E7E20;
                  break;
              }
              sprintfex(&Size, v22, _this->pSpriteSFrames[i].sTextureName);

              v12 = sub_4AC7C0(pClass17_Sprites_LOD, &Size, _this->pSpriteSFrames[i].word_000032);
              v13 = v11++ + v33;
              *(_WORD *)(*(_DWORD *)(v2 + 12) + 2 * v13) = v12;
            }
            while ( v11 < 8 );
            goto LABEL_46;
          }
          if (!(_this->pSpriteSFrames[i].dword_00002C & 0x40))
            break;

          strcpy(Source, "stA");
          v32 = 0;
          strcpy(&Str, _this->pSpriteSFrames[i].sTextureName);
          v15 = strlen(&Str);
          strcpy(&v28 + v15, Source);
          v14 = 0;
          do
          {
            switch ( v14 )
            {
              case 0:
               v26 = _this->pSpriteSFrames[i].sTextureName;
                v23 = (const char *)&unk_4E7E20;
                goto LABEL_26;
              case 4:
                v26 = &Str;
                v23 = (const char *)&unk_4E7E28;
                goto LABEL_26;
              case 3:
              case 5:
                v26 = &Str;
                v23 = "%s3";
                goto LABEL_26;
              case 2:
              case 6:
               v26 = _this->pSpriteSFrames[i].sTextureName;
                v23 = (const char *)&unk_4E7E24;
                goto LABEL_26;
              case 1:
              case 7:
               v26 = _this->pSpriteSFrames[i].sTextureName;
                v23 = "%s1";
LABEL_26:
                sprintfex(&Size, v23, v26);
                break;
              default:
                break;
            }
            v16 = sub_4AC7C0(pClass17_Sprites_LOD, &Size, _this->pSpriteSFrames[i].word_000032);
            v17 = v14++ + v33;
            *(_WORD *)(*(_DWORD *)(v2 + 12) + 2 * v17) = v16;
          }
          while ( v14 < 8 );
LABEL_46:
          if (!(_this->pSpriteSFrames[i].dword_00002C & 1))
            return;
          v33 += 30;
          ++i;
        }



        v18 = 0;
        while ( 1 )
        {
          v19 = &_this->pSpriteSFrames[a2];
          if ( !((256 << v18) & *(_DWORD *)(v19 + 44)) )
          {
            sprintfex(&Size, "%s%i", v19 + 12, v18);
            goto LABEL_45;
          }
          if ( v18 == 1 )
          {
            v27 = v19 + 12;
            v24 = "%s7";
            goto LABEL_42;
          }
          if ( v18 == 2 )
          {
            v27 = v19 + 12;
            v24 = "%s6";
            goto LABEL_42;
          }
          if ( v18 == 3 )
          {
            v27 = v19 + 12;
            v24 = "%s5";
            goto LABEL_42;
          }
          if ( v18 == 5 )
          {
            v27 = v19 + 12;
            v24 = "%s3";
            goto LABEL_42;
          }
          if ( v18 == 6 )
            break;
          if ( v18 == 7 )
          {
            v27 = v19 + 12;
            v24 = "%s1";
LABEL_42:
            sprintfex(&Size, v24, v27);
          }
LABEL_45:
          v20 = sub_4AC7C0(pClass17_Sprites_LOD, &Size, _this->pSpriteSFrames[a2].word_000032);
          v21 = v18++ + v33;
          *(_WORD *)(*(_DWORD *)(v2 + 12) + 2 * v21) = v20;
          if ( v18 >= 8 )
            goto LABEL_46;
        }
        v27 = v19 + 12;
        v24 = (const char *)&unk_4E7E24;
        goto LABEL_42;
      }
}

//----- (0044D813) --------------------------------------------------------
int CSpriteFrameTable_fn5(struct CSpriteFrameTable *_this, const char *Str1)
{
 sub_44D83A(_this, 0, _this->dword_000004, Str1);
 if (_this->dword_000008 < 0)
   return 0;
 else return _this->pSpriteEFrames[_this->dword_000008];
}

//----- (MM7.exe::0044D4D8) --------------------------------------------------------
int CSpriteFrameTable_sub_44D4D8(struct CSpriteFrameTable *_this)
{
 if (_this->pSpriteSFrames)
 {
  class23_DeleteBuffer(class23_instance, _this->pSpriteSFrames);
  _this->pSpriteSFrames = 0;
 }
 _this->uNumSpriteFrames = 0;
 return 0;
}






void CTileTable_ctor(struct CTileTable *_this)
{
 memset(_this, 0, sizeof(struct CTileTable));
}


//----- (00488000) --------------------------------------------------------
void CTileTable_Initialize(struct CTileTable *_this, unsigned char *pSrc)
{
 _this->uNumTiles = *(int *)(pSrc);
 _this->pTiles = class23_AllocatedNamedBuffer(class23_instance, _this->pTiles, _this->uNumTiles * sizeof(struct TileDesc), "Tile Descrip");
 memcpy(_this->pTiles, pSrc + 4, _this->uNumTiles * sizeof(struct TileDesc));
}

//----- (00487ED6) --------------------------------------------------------
int sub_487ED6(struct CTileTable *_this, int a2, int a3)
{
  int v5; // edx@3
  int v6; // edx@11

 if (a2 > 8)
   return sub_487F84(_this, a2, 0);

 v5 = rand() % 50;
 if (a3 || v5 < 20)
   return sub_487F84(_this, a2, 0);
 else if (v5 < 30)
   return sub_487F84(_this, a2, 1);
 else if (v5 < 40)
   return sub_487F84(_this, a2, 2);
 else if (v5 < 48)
   return sub_487F84(_this, a2, 3);

 v6 = rand() % 8;
 return sub_487F84(_this, a2, 4 + v6);
}

//----- (00487F84) --------------------------------------------------------
int sub_487F84(struct CTileTable *_this, int a2, int a3)
{
 int i;

 if (!_this->uNumTiles)
   return 0;

 i = 0;
 while (_this->pTiles[i].word_000014 != a2 || _this->pTiles[i].word_000016 != a3 )
 {
  ++i;
  if (i >= _this->uNumTiles)
    return 0;
 }
 return i;
}

//----- (00487E58) --------------------------------------------------------
void CTileTable_LoadSomeTiles(struct CTileTable *_this, int a2)
{
 int     i;
 wchar_t pFilename[256];

 for ( i = 0; i < _this->uNumTiles; ++i)
 {
  if (_this->pTiles[i].word_000014 == a2)
  {
   if (_this->pTiles[i].sTileName[0])
   {
    wsprintfW(pFilename, L"%S", _this->pTiles[i].sTileName);
    _this->pTiles[i].word_000012 = class17_LoadTextureFromCBM(pClass17_Bitmaps_LOD, pFilename);

    if (_this->pTiles[i].word_000012 != -1)
      pClass17_Bitmaps_LOD->aLODHeaders[_this->pTiles[i].word_000012].word_000026 = class35_sub_48A3BC(&class35_obj, pClass17_Bitmaps_LOD->aLODHeaders[_this->pTiles[i].word_000012].word_000026);
   }
  }
 }
}






void CPlayerFrameTable_ctor(struct CPlayerFrameTable *_this)
{
 memset(_this, 0, sizeof(struct CPlayerFrameTable));
}

//----- (00494C0F) --------------------------------------------------------
void *CPlayerFrameTable_Initialize(struct CPlayerFrameTable *_this, unsigned char *pSrc)
{
 _this->uNumFrames = *(int *)(pSrc);
 _this->pFrames = class23_AllocatedNamedBuffer(class23_instance, _this->pFrames, _this->uNumFrames * sizeof(struct PlayerFrame), "P Frames");
 memcpy(_this->pFrames, pSrc + 4, _this->uNumFrames * sizeof(struct PlayerFrame));
 return 0;
}





 

void CDecorationDescriptionList_ctor(struct CDecorationDescriptionList *_this)
{
 memset(_this, 0, sizeof(struct CDecorationDescriptionList));
}

//----- (0045864C) --------------------------------------------------------
void *CDecorationDescriptionList_Initialize(struct CDecorationDescriptionList *_this, unsigned char *pSrc)
{
 _this->uNumDecorations = *(int *)(pSrc);

 _this->pDescriptions = class23_AllocatedNamedBuffer(class23_instance, _this->pDescriptions, _this->uNumDecorations * sizeof(struct DecorationDescription), "Dec Descrip");
 memcpy(_this->pDescriptions, pSrc + 4, _this->uNumDecorations * sizeof(struct DecorationDescription));
 return 0;
}

//----- (004488B6) --------------------------------------------------------
__int16 sub_4488B6(struct CDecorationDescriptionList *_this, const char *Str1)
{
  void *v2; // esi@1
  signed int v3; // edi@2
  signed int v4; // ebx@3
  __int16 result; // ax@6

  v2 = _this;
  if ( Str1 && _this->uNumDecorations > 1)
  {
   v3 = 1;
    v4 = 84;
    while ( _strcmpi(Str1, _this->pDescriptions[v3].array_000000) )
    {
      ++v3;
      v4 += 84;
      if ( v3 >= _this->uNumDecorations)
        return 0;
    }
    return v3;
  }

  return 0;
}

//----- (00458693) --------------------------------------------------------
void sub_458693(struct CDecorationDescriptionList *_this, unsigned int uDecorationDescriptionID)
{
  CSpriteFrameTable_fn4(pSpriteFrameTable, _this->pDescriptions[uDecorationDescriptionID].word_000048);
}







void CObjectDescriptionList_ctor(struct CObjectDescriptionList *_this)
{
 memset(_this, 0, sizeof(struct CObjectDescriptionList));
}

//----- (004590DC) --------------------------------------------------------
void *CObjectDescriptionList_Initialize(struct CObjectDescriptionList *_this, unsigned char *pSrc)
{
 _this->uNumObjects = *(int *)(pSrc);

 _this->pDescriptions = class23_AllocatedNamedBuffer(class23_instance, _this->pDescriptions, _this->uNumObjects * sizeof(struct ObjectDescription), "Obj Descrip");
 memcpy(_this->pDescriptions, pSrc + 4, _this->uNumObjects * sizeof(struct ObjectDescription));
 return 0;
}


//----- (00459064) --------------------------------------------------------
void sub_459064(struct CObjectDescriptionList *_this)
{
 int i;

 for (i = 0; i < _this->uNumObjects; ++i)
   CSpriteFrameTable_fn4(pSpriteFrameTable, _this->pDescriptions[i].word_000028);
}




void COverlayDescriptionList_ctor(struct COverlayDescriptionList *_this)
{
 memset(_this, 0, sizeof(struct COverlayDescriptionList));
}

//----- (00458E08) --------------------------------------------------------
void *COverlayDescriptionList_Initialize(struct COverlayDescriptionList *_this, unsigned char *pSrc)
{
 _this->uNumOverlays = *(int *)(pSrc);

 _this->pDescriptions = class23_AllocatedNamedBuffer(class23_instance, _this->pDescriptions, _this->uNumOverlays * sizeof(struct OverlayDescription), "Ovl Des.");
 memcpy(_this->pDescriptions, pSrc + 4, _this->uNumOverlays * sizeof(struct OverlayDescription));
 return 0;
}


//----- (00458D97) --------------------------------------------------------
void sub_458D97(struct COverlayDescriptionList *_this)
{
 int i;

 for (i = 0; i < _this->uNumOverlays; ++i)
   CSpriteFrameTable_fn4(pSpriteFrameTable, _this->pDescriptions[i].word_000004);
}

