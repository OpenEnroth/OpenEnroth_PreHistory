#include "FrameTables.h"
#include "mm7_unparsed_data.h"
#include "AudioPlayer.h"
#include "data.h"
#include "_lod.h"



#ifndef OLD_CODE
template<> unsigned int ImageTableLoader<IconFrame>::LoadFromFile(const wchar_t *pFilename, struct ImageTable<IconFrame> **ppOut)
{
 char pFilenameA[256];

 wsprintfA(pFilenameA, "%S", pFilename);
 unsigned char *pRawData = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw(pFilenameA, 1);

 ImageTable<IconFrame> *pImageTable = MemAlloc(ImageTable<IconFrame>, 1);

 pImageTable->uNumImages = *(unsigned int *)pRawData;
 pImageTable->pImages = MemAlloc(IconFrame, pImageTable->uNumImages);
 memcpy(pImageTable->pImages, pRawData + 4, pImageTable->uNumImages * sizeof(IconFrame));

 *ppOut = pImageTable;
 return 0;
}
#endif


#ifdef OLD_CODE
template<> unsigned int ImageTableLoader<IconFrame>::LoadFromFile(const char *pFilename, struct ImageTable<IconFrame> **ppOut)
{
 unsigned char *pRawData = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw(pFilename, 1);

 ImageTable<IconFrame> *pImageTable = MemAlloc(ImageTable<IconFrame>, 1);

 pImageTable->uNumImages = *(unsigned int *)pRawData;
 pImageTable->pImages = MemAlloc(IconFrame, pImageTable->uNumImages);
 memcpy(pImageTable->pImages, pRawData + 4, pImageTable->uNumImages * sizeof(IconFrame));

 *ppOut = pImageTable;
 return 0;
}
#endif


void MonsterDescriptionList_ctor(struct MonsterDescriptionList *_this)
{
 _this->uNumDescriptions = 0;
 _this->pDescriptions = 0;
}

//----- (004598AF) --------------------------------------------------------
void MonsterDescriptionList_Initialize(struct MonsterDescriptionList *_this, unsigned int *pSrc)
{
 _this->uNumDescriptions = pSrc[0];
 //_this->pDescriptions = (MonsterDescription *)mem_mng.AllocatedNamedBuffer( _this->pDescriptions, _this->uNumDescriptions * sizeof(struct MonsterDescription), "Mon Race");
 _this->pDescriptions = NamedMemAlloc(MonsterDescription, _this->uNumDescriptions, "Monster Race descr");

 memcpy(_this->pDescriptions, pSrc + 1, _this->uNumDescriptions * sizeof(struct MonsterDescription));
}



//----- (0044E0A0) --------------------------------------------------------
void CTextureFrameTable_Initialize(struct CTextureFrameTable *_this, unsigned char *pSrc)
{
 _this->uNumTextures = *(int *)(pSrc);
 //_this->pTextures = (TextureFrame *)mem_mng.AllocatedNamedBuffer(_this->pTextures, _this->uNumTextures * sizeof(struct TextureFrame), "Txt Frames");
 _this->pTextures = NamedMemAlloc(TextureFrame, _this->uNumTextures, "Texture Frames");

 memcpy(_this->pTextures, pSrc + 4, _this->uNumTextures * sizeof(struct TextureFrame));
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
void CIconFrameTable_Initialize(struct CIconFrameTable *_this, void *pSrc)
{
 _this->uNumIcons = *(int *)pSrc;

 _this->pIcons = NamedMemAlloc(IconFrame, _this->uNumIcons, "Icon Frames");
 memcpy(_this->pIcons, (char *)pSrc + 4, _this->uNumIcons * sizeof(struct IconFrame));
}


#ifndef OLD_CODE
//----- (MM7.exe::00494F3A) --------------------------------------------------------
unsigned int CIconFrameTable_FindIcon_New(struct CIconFrameTable *_this, const wchar_t *pIconName)
{
 char pIconNameA[256];
 int  i;

 if (!_this->uNumIcons)
   return 0;

 wsprintfA(pIconNameA, "%S", pIconName);
 for (i = 0; i < _this->uNumIcons; ++i)
 {
  if (!_strcmpi(pIconNameA, (char *)_this->pIcons[i].sAnimationName))
    return i;
 }
 return 0;
}

//----- (MM7.exe::00494F3A) --------------------------------------------------------
unsigned int CIconFrameTable_FindIcon(struct CIconFrameTable *_this, const char *pIconName)
{
 wchar_t pIconNameW[256];

 wsprintfW(pIconNameW, L"%S", pIconName);
 return CIconFrameTable_FindIcon_New(_this, pIconNameW);
}

#endif

//----- (MM7.exe::00494FBF) --------------------------------------------------------
void CIconFrameTable_InitializeIcon(struct CIconFrameTable *_this, unsigned int uIconIdx)
{

 int     i;

 if (uIconIdx >= _this->uNumIcons)
   return;

 i = uIconIdx;
 do
 {
#ifndef OLD_CODE
  wchar_t pFilepath[256];
  wsprintfW(pFilepath, L"%S", _this->pIcons[i].sTextureName);
  _this->pIcons[i].uTextureIdx = LODFile_Icons_LOD.LODFile_LoadTexture_New( pFilepath);
  #endif
#ifdef OLD_CODE

  _this->pIcons[i].uTextureIdx = LODFile_Icons_LOD.LODFile_LoadTexture( _this->pIcons[i].sTextureName,2);
#endif
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
    v7 = (uFrame / 8) % (unsigned __int16)v5;
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











void SpriteFrameTable_ctor(struct SpriteFrameTable *_this)
{
 _this->uNumSpriteFrames = 0;
 _this->dword_000004 = 0;
 _this->dword_000008 = 0;
 _this->pSpriteSFrames = 0;
 _this->pSpritePFrames = 0;
 _this->pSpriteEFrames = 0;
}

//----- (MM7.exe::0044D9D7) --------------------------------------------------------
int SpriteFrameTable_Initialize(struct SpriteFrameTable *_this, unsigned int *pSrc)
{
 int i;

 _this->uNumSpriteFrames = pSrc[0];
 _this->dword_000004 = pSrc[1];

 //_this->pSpriteSFrames = (SpriteFrame *)mem_mng.AllocatedNamedBuffer( _this->pSpriteSFrames, _this->uNumSpriteFrames * sizeof(struct SpriteFrame), "S Frames");
 //_this->pSpritePFrames = (SpriteFrame **)mem_mng.AllocatedNamedBuffer( _this->pSpritePFrames, 4 * _this->uNumSpriteFrames, "P Frames");
 //_this->pSpriteEFrames = (unsigned short *)mem_mng.AllocatedNamedBuffer( _this->pSpriteEFrames, 2 * _this->uNumSpriteFrames, "E Frames");
 _this->pSpriteSFrames = NamedMemAlloc(SpriteFrame, _this->uNumSpriteFrames, "S Frames");
 _this->pSpritePFrames = NamedMemAlloc(SpriteFrame *, _this->uNumSpriteFrames, "P Frames");
 _this->pSpriteEFrames = NamedMemAlloc(unsigned short, _this->uNumSpriteFrames, "E Frames");

 pSrc += 2;
 memcpy(_this->pSpriteSFrames, pSrc, _this->uNumSpriteFrames * sizeof(struct SpriteFrame));

 pSrc = (unsigned int *)((char *)pSrc + _this->uNumSpriteFrames * sizeof(struct SpriteFrame));
 memcpy(_this->pSpriteEFrames, pSrc, _this->dword_000004 * sizeof(short));

 for (i = 0; i < _this->uNumSpriteFrames; ++i)
   _this->pSpritePFrames[i] = &_this->pSpriteSFrames[_this->pSpriteEFrames[i]];

 return _this->uNumSpriteFrames;
}

//----- (0044D8D0) --------------------------------------------------------
struct SpriteFrame *CSpriteFrameTable_fn1(struct SpriteFrameTable *_this, unsigned int uID, signed int a3)
{
  int v3; // ecx@1
  signed __int16 v5; // dx@2
  int v6; // eax@3
  int v7; // edx@3
  int i; // ecx@3
  int v9; // esi@5
  int result; // eax@6

  v3 = (int)&_this->pSpriteSFrames[uID];
  v5 = _this->pSpriteSFrames[uID].word_000038;
  if (_this->pSpriteSFrames[uID].dword_00002C & 0x01 && v5 != 0 )
  {
    v7 = (a3 >> 3) % v5;
    v6 = uID;
    for ( i = uID; ; ++i)
    {
      v9 = _this->pSpriteSFrames[i].word_000036;
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
struct SpriteFrame *CSpriteFrameTable_fn2(struct SpriteFrameTable *_this, int a2, signed int a3)
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
  return (SpriteFrame *)result;
}

//----- (0044D4F6) --------------------------------------------------------
void SpriteFrameTable_fn3(struct SpriteFrameTable *_this)
{
 int i;

 for (i = 0; i < _this->uNumSpriteFrames; ++i)
   _this->pSpriteSFrames[i].dword_00002C &= 0xFFFFFF7F;
}

//----- (0044D513) --------------------------------------------------------
void SpriteFrameTable_InitializeSpriteFrame(struct SpriteFrameTable *_this, unsigned int uSpriteFrameID)
{
  int v2; // esi@1
  __int16 v10; // ax@6
  signed int v11; // edi@10
  __int16 v12; // ax@16
  signed int v14; // edi@19
  size_t v15; // eax@19
  __int16 v16; // ax@27
  struct SpriteFrame *v19; // eax@30
  __int16 v20; // ax@45
  const char *v22; // [sp-8h] [bp-50h]@12
  const char *v23; // [sp-8h] [bp-50h]@21
  char *v26; // [sp-4h] [bp-4Ch]@21
  char v28; // [sp+9h] [bp-3Fh]@19
  char Str; // [sp+Ch] [bp-3Ch]@19
  char Size[20]; // [sp+2Ch] [bp-1Ch]@15
  char Source[4]; // [sp+40h] [bp-8h]@19
 int i, j; 

  v2 = (int)_this;
  if (uSpriteFrameID > _this->uNumSpriteFrames)
    return;

  if (_this->pSpriteSFrames[uSpriteFrameID].dword_00002C & 0x80000000)
    return;

   _this->pSpriteSFrames[uSpriteFrameID].dword_00002C |= 0x80;

 for (i = uSpriteFrameID; true; ++i)
 {
  _this->pSpriteSFrames[i].word_000034 = class35_sub_48A3BC_MessWithPalettes(&class35_obj, _this->pSpriteSFrames[i].word_000032);

  if (_this->pSpriteSFrames[i].dword_00002C & 0x10)
  {

   v10 = LODFile_Sprites_LOD.LODFile_LoadSprite( (char *)_this->pSpriteSFrames[i].sTextureName, _this->pSpriteSFrames[i].word_000032);

   for (j = 0; j < 8; ++j)
     _this->pSpriteSFrames[i].pSpriteIDs[j] = v10;

  }
  else if (_this->pSpriteSFrames[i].dword_00002C & 0x10000)
  {
            v11 = 0;
            do
            {
              switch ( v11 )
              {
                case 3:
                case 4:
                case 5:
                  v22 = "%s4";
                case 2:
                case 6:
                  v22 = "%s2";
                case 0:
                case 1:
                case 7:
                  v22 = "%s0";
                  break;
              }
              wsprintfA(Size, v22, _this->pSpriteSFrames[i].sTextureName);

              v12 = LODFile_Sprites_LOD.LODFile_LoadSprite( (char *)&Size, _this->pSpriteSFrames[i].word_000032);

              _this->pSpriteSFrames[i].pSpriteIDs[v11++] = v12;
            }
            while ( v11 < 8 );
  }
  else if (!(_this->pSpriteSFrames[i].dword_00002C & 0x40))
  {
   for (j = 0; j < 8; ++j)
   {
    v19 = &_this->pSpriteSFrames[i];
    if ( !((0x100 << j) & v19->dword_00002C) )
      wsprintfA(Size, "%s%i", v19->sTextureName, j);
    else
      wsprintfA(Size, "%s%i", v19->sTextureName, 8 - j);

    v20 = LODFile_Sprites_LOD.LODFile_LoadSprite( Size, _this->pSpriteSFrames[i].word_000032);

    _this->pSpriteSFrames[i].pSpriteIDs[j] = v20;
   }
  }
  else
  {
          strcpy(Source, "stA");
          strcpy(&Str, (char *)_this->pSpriteSFrames[i].sTextureName);
          v15 = strlen(&Str);
          strcpy(&v28 + v15, Source);
          v14 = 0;
          do
          {
            switch ( v14 )
            {
              case 0:
               v26 = (char *)_this->pSpriteSFrames[i].sTextureName;
                v23 = "%s0";
                goto LABEL_26;
              case 4:
                v26 = &Str;
                v23 = "%s4";
                goto LABEL_26;
              case 3:
              case 5:
                v26 = &Str;
                v23 = "%s3";
                goto LABEL_26;
              case 2:
              case 6:
               v26 = (char *)_this->pSpriteSFrames[i].sTextureName;
                v23 = "%s2";
                goto LABEL_26;
              case 1:
              case 7:
               v26 = (char *)_this->pSpriteSFrames[i].sTextureName;
                v23 = "%s1";
LABEL_26:
                wsprintfA(Size, v23, v26);
                break;
              default:
                break;
            }
            v16 = LODFile_Sprites_LOD.LODFile_LoadSprite( (char *)&Size, _this->pSpriteSFrames[i].word_000032);

            _this->pSpriteSFrames[i].pSpriteIDs[v14++] = v16;
          }
          while ( v14 < 8 );
  }

  if (!(_this->pSpriteSFrames[i].dword_00002C & 0x01))
    break;
  }
}

//----- (0044D813) --------------------------------------------------------
unsigned int SpriteFrameTable_FastFindSprite(struct SpriteFrameTable *_this, const char *pSpriteName)
{
 SpriteFrameTablsub_SpriteBinarySearch(_this, 0, _this->dword_000004, pSpriteName);
 if (_this->dword_000008 < 0)
   return 0;
 else return _this->pSpriteEFrames[_this->dword_000008];
}

//----- (MM7.exe::0044D4D8) --------------------------------------------------------
int SpriteFrameTable_sub_44D4D8(struct SpriteFrameTable *_this)
{
 if (_this->pSpriteSFrames)
 {
  //MemFree( (void *)_this->pSpriteSFrames);
  MemFree(_this->pSpriteSFrames);
  _this->pSpriteSFrames = 0;
 }
 _this->uNumSpriteFrames = 0;
 return 0;
}

//----- (0044D83A) --------------------------------------------------------
void SpriteFrameTablsub_SpriteBinarySearch(struct SpriteFrameTable *_this, int a2, int a3, const char *pSpriteName)
{
  int v4; // ebx@1
  void *v5; // edi@1
  int result; // eax@2
  int v7; // esi@2
  int v8; // [sp+14h] [bp+8h]@2

  v4 = a2;
  v5 = _this;
  while ( 1 )
  {
    v8 = a3 - v4;
    v7 = (a3 - v4) / 2 + v4;

    result = strcmpi(pSpriteName, (char *)_this->pSpritePFrames[v7]->sIconName);
    if (!result)
      _this->dword_000008 = v7;

    if ( v4 == a3 )
      break;


      if ( v8 <= 4 )
      {
        while ( v4 < a3 )
        {
          result = strcmpi(pSpriteName, (char *)_this->pSpritePFrames[v4]->sIconName);
          if ( !result )
          {
            _this->dword_000008 = v4;
            return;
          }
          ++v4;
        }
        break;
      }

      if (result >= 0)
      {
       v4 += (a3 - v4) / 2;
      }
      else
      {
       a3 = (a3 - v4) / 2 + v4;
      }
  }

 _this->dword_000008 = -1;
}






CPlayerFrameTable::CPlayerFrameTable()
{
 this->uNumFrames =0;
 this->pFrames=NULL;
}

//----- (00494C0F) --------------------------------------------------------
void CPlayerFrameTable::pft_Initialize(unsigned char *pSrc)
{
 uNumFrames = *(int *)(pSrc);
 //pFrames = (PlayerFrame *)mem_mng.AllocatedNamedBuffer( this->pFrames, this->uNumFrames * sizeof(struct PlayerFrame), "P Frames");
 pFrames = NamedMemAlloc(PlayerFrame, uNumFrames, "Player Frames");
 memcpy(pFrames, pSrc + 4, uNumFrames * sizeof(PlayerFrame));
}

//----- (00494B10) --------------------------------------------------------
struct PlayerFrame *CPlayerFrameTable::GetFrameFromFrameset(unsigned int uFramesetID, unsigned int uFrameID)
{
  int v8; // edx@3
 int i;

 if (pFrames[uFramesetID].word_000008 & 0x0001 &&
     pFrames[uFramesetID].word_000006)
 {
  v8 = (uFrameID / 8) % pFrames[uFramesetID].word_000006;
  for (i = 0; ; ++i)
  {
   if ( v8 <= pFrames[i].word_000004)
     break;
   v8 -= pFrames[i].word_000004;
  }
  return &pFrames[i];
 }
 else 
	 return &pFrames[uFramesetID];
}


 //----- (00494AED) --------------------------------------------------------
int  CPlayerFrameTable::GetFrameByNum( unsigned int uNumFrame)
{
  int i;
  
  i = 0;
  if ( uNumFrames> 0 )
    while( pFrames[i].word_000000!= uNumFrame )
    {
      ++i;
      if ( i >= uNumFrames )
		  {
		  i=0;
		  break;
		  }
    }
  return i;
}

//----- (00494B5E) --------------------------------------------------------
struct PlayerFrame *CPlayerFrameTable::PlayerFrameTable_sub_494B5E( int a2, int a3, int a4)
{
  int v4; // edi@1
  signed int v5; // esi@1
  int v6; // eax@2

  v4 = (int)this;
  v5 = a4 + a3;
  if ( v5 < 8 * *(_WORD *)(*(_DWORD *)(this + 4) + 10 * *(_DWORD *)a2 + 4) )
  {
    a3 = v5;
  }
  else
  {
    v6 = rand() % 4 + 21;
    a2 = v6;
    a3 = 8 * v5 % *(_WORD *)(*(_DWORD *)(v4 + 4) + 10 * v6 + 4);
  }
  return &pFrames[a2];
}



 

void DecorationDescriptionList_ctor(struct DecorationDescriptionList *_this)
{
 memset(_this, 0, sizeof(struct DecorationDescriptionList));
}

//----- (0045864C) --------------------------------------------------------
void *DecorationDescriptionList_Initialize(struct DecorationDescriptionList *_this, unsigned char *pSrc)
{
 _this->uNumLevelDecorations = *(int *)(pSrc);

 //_this->pDescriptions = (DecorationDescription *)mem_mng.AllocatedNamedBuffer( _this->pDescriptions, _this->uNumLevelDecorations * sizeof(struct DecorationDescription), "Dec Descrip");
 _this->pDescriptions = NamedMemAlloc(DecorationDescription, _this->uNumLevelDecorations, "Decoration Descrip");
 memcpy(_this->pDescriptions, pSrc + 4, _this->uNumLevelDecorations * sizeof(struct DecorationDescription));
 return 0;
}

//----- (004488B6) --------------------------------------------------------
__int16 sub_4488B6(struct DecorationDescriptionList *_this, const char *Str1)
{
  void *v2; // esi@1
  signed int v3; // edi@2
  signed int v4; // ebx@3
  __int16 result; // ax@6

  v2 = _this;
  if ( Str1 && _this->uNumLevelDecorations > 1)
  {
   v3 = 1;
    v4 = 84;
    while ( _strcmpi(Str1, (char *)_this->pDescriptions[v3].array_000000) )
    {
      ++v3;
      v4 += 84;
      if ( v3 >= _this->uNumLevelDecorations)
        return 0;
    }
    return v3;
  }

  return 0;
}

//----- (00458693) --------------------------------------------------------
void sub_458693(struct DecorationDescriptionList *_this, unsigned int uDecorationDescriptionID)
{
  SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, _this->pDescriptions[uDecorationDescriptionID].uSpriteID);
}







void CObjectDescriptionList_ctor(struct CObjectDescriptionList *_this)
{
 memset(_this, 0, sizeof(struct CObjectDescriptionList));
}

//----- (004590DC) --------------------------------------------------------
void *CObjectDescriptionList_Initialize(struct CObjectDescriptionList *_this, unsigned char *pSrc)
{
 _this->uNumObjects = *(int *)(pSrc);

 //_this->pDescriptions = (ObjectDescription *)mem_mng.AllocatedNamedBuffer( _this->pDescriptions, _this->uNumObjects * sizeof(struct ObjectDescription), "Obj Descrip");
 _this->pDescriptions = NamedMemAlloc(ObjectDescription,_this->uNumObjects, "Object Descrip");
 memcpy(_this->pDescriptions, pSrc + 4, _this->uNumObjects * sizeof(struct ObjectDescription));
 return 0;
}


//----- (00459064) --------------------------------------------------------
void sub_459064(struct CObjectDescriptionList *_this)
{
 int i;

 for (i = 0; i < _this->uNumObjects; ++i)
   SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, _this->pDescriptions[i].uSpriteID);
}




void COverlayDescriptionList_ctor(struct COverlayDescriptionList *_this)
{
 memset(_this, 0, sizeof(struct COverlayDescriptionList));
}

//----- (00458E08) --------------------------------------------------------
void *COverlayDescriptionList_Initialize(struct COverlayDescriptionList *_this, unsigned char *pSrc)
{
 _this->uNumOverlays = *(int *)(pSrc);

 //_this->pDescriptions = (OverlayDescription *)mem_mng.AllocatedNamedBuffer( _this->pDescriptions, _this->uNumOverlays * sizeof(struct OverlayDescription), "Ovl Des.");
 _this->pDescriptions = NamedMemAlloc(OverlayDescription, _this->uNumOverlays, "Overlay Descrip");
 memcpy(_this->pDescriptions, pSrc + 4, _this->uNumOverlays * sizeof(struct OverlayDescription));
 return 0;
}


//----- (00458D97) --------------------------------------------------------
void sub_458D97(struct COverlayDescriptionList *_this)
{
 int i;
										 
 for (i = 0; i < _this->uNumOverlays; ++i)
   SpriteFrameTable_InitializeSpriteFrame(pSpriteFrameTable, _this->pDescriptions[i].word_000004);
}

