#pragma once

#include <windows.h>

#pragma pack(push, 1)




template <typename Image>
  struct ImageTable;

template<typename Image>
  struct ImageTableLoader
{
 inline ImageTableLoader() {}

 unsigned int LoadFromFile(const wchar_t *pFilename, ImageTable<Image> **ppOut);
};


template <typename Image>
  struct ImageTable
{
 friend struct ImageTableLoader<Image>;
 public:
   inline unsigned int FindImage(const wchar_t *pName)
   {
    char pNameA[256];

    wsprintfA(pNameA, "%S", pName);
    for (unsigned int i = 0; i < uNumImages; ++i)
    {
     if (!lstrcmpiA(pNameA, (char *)pImages[i].sName))
      return i;
    }
    return 0;
   }

   inline unsigned int FindAnimation(const char *pName)
   {
    wchar_t pNameW[256];

    wsprintfW(pNameW, L"%S", pName);
    return FindAnimation(pNameW);
   }

   inline unsigned int FindAnimation(const wchar_t *pName)
   {
    char pNameA[256];

    wsprintfA(pNameA, "%S", pName);
    for (unsigned int i = 0; i < uNumImages; ++i)
    {
     if (!lstrcmpiA(pNameA, (char *)pImages[i].sAnimationName))
       return i;
    }
    return 0;
   }


   inline Image *GetImage(unsigned int uImageID)
   {
    return &pImages[uImageID];
   }

   inline Image *GetImage(unsigned int uAnimationID, unsigned int uFrameID)
   {
    int v6; // eax@3
    int v7; // edx@3
    int i; // ecx@3
    int v9; // esi@5

    if (pImages[uAnimationID].word_00001C & 0x0001 &&
        pImages[uAnimationID].word_00001A)
    {
     v7 = (uFrameID / 8) % pImages[uAnimationID].word_00001A;
     v6 = uAnimationID;
     for ( i = uAnimationID; ; ++i)
     {
      v9 = pImages[i].word_000018;
      if ( v7 <= v9 )
        break;
      v7 -= v9;
      ++v6;
     }
     return &pImages[v6];
    }
    else
      return &pImages[uAnimationID];
   }


   inline unsigned int InitializeImage(unsigned int uImageID)
   {
    return -1;
   }
// #define OLD_CODE
#ifndef OLD_CODE
   inline unsigned int InitializeAnimation(unsigned int uAnimationID)
   {

    for (unsigned int i = uAnimationID; pImages[i].word_00001C & 1; ++i)
    {
     wchar_t pFilepath[256];
     wsprintfW(pFilepath, L"%S", pImages[i].sTextureName);

     pImages[i].uTextureIdx = LODFile_Icons_LOD.LODFile_LoadTexture_New(pFilepath);
    }


    return 0;
   }
#endif
#ifdef OLD_CODE
   inline unsigned int InitializeAnimation(unsigned int uAnimationID)
   {

    for (unsigned int i = uAnimationID; pImages[i].word_00001C & 1; ++i)
    {


     pImages[i].uTextureIdx = LODFile_Icons_LOD.LODFile_LoadTexture((char *)&pImages[i].sTextureName[0],2);
    }


    return 0;
   }
#endif
#undef	OLD_CODE

 protected:
   inline ImageTable()
   {
    uNumImages = 0;
    pImages = 0;
   }

   unsigned int  uNumImages;
   Image        *pImages;
};







struct IconFrame
{
 unsigned char sAnimationName[12]; // byte[12] @ 000000
 unsigned char sTextureName[12];   // byte[12] @ 00000C
 short         word_000018;        // frame time?
 short         word_00001A;        // num frames?
 short         word_00001C;
 short         uTextureIdx;        // word @ 00001E
};
//sizeof = 20





struct CIconFrameTable
{
 unsigned int      uNumIcons; // dword @ 000000
 struct IconFrame *pIcons;    // ptr   @ 000004
};
//sizeof ~ ?
void CIconFrameTable_ctor(struct CIconFrameTable *_this);
//void *__thiscall sub_495056(void *Dst, void *Src);
void CIconFrameTable_Initialize(struct CIconFrameTable *_this, void *pSrc);
//int __thiscall sub_494F3A(void *_this, const char *Str1);
unsigned int CIconFrameTable_FindIcon(struct CIconFrameTable *_this, const char *pIconName);
//custom
unsigned int CIconFrameTable_FindIcon_New(struct CIconFrameTable *_this, const wchar_t *pIconName);
//void __thiscall sub_494FBF(int _this, int a2);
void CIconFrameTable_InitializeIcon(struct CIconFrameTable *_this, unsigned int uIconIdx);
//int __thiscall sub_49500A(void *Str);
int CIconFrameTable_SaveToBIN(struct CIconFrameTable *_this);
//int __thiscall sub_494F70(int _this, int a2, signed int a3);
struct IconFrame *CIconFrameTable_GetFrame(struct CIconFrameTable *_this, unsigned int uIconIdx, unsigned int uFrame);







struct MonsterDescription
{
 short          uMonsterHeight;
 short          word_000002;
 char           byte_000004[4];
 int            dword_000008;      // hw tint color?
 unsigned short pSoundSampleIDs[4];  // word[4] @ 00000C
 char           byte_000014[32];
 unsigned char  pSpriteNames[8][10]; // byte[10] @ 000034
 char           byte_000084[20];
};
//sizeof = 98

struct MonsterDescriptionList
{
 unsigned int               uNumDescriptions; // dword @ 000000
 struct MonsterDescription *pDescriptions;    // dword @ 000004
};
//sizeof == 08
void MonsterDescriptionList_ctor(struct MonsterDescriptionList *_this);
//void *__thiscall sub_4598AF(void *Dst, void *Src);
void MonsterDescriptionList_Initialize(struct MonsterDescriptionList *_this, unsigned int *pSrc);





struct TextureFrame
{
 unsigned char sTextureName[12]; // byte[12] @ 000000
 unsigned int  dword_00000C;
 unsigned int  dword_000010;
};
//sizeof == 14

struct CTextureFrameTable
{
 unsigned int         uNumTextures; // dword @ 000000
 struct TextureFrame *pTextures;    // ptr   @ 000004
};

void CTextureFrameTable_ctor(struct CTextureFrameTable *_this);

//void *__thiscall sub_44E0A0(struct unk_class *Dst, void *Src);
void CTextureFrameTable_Initialize(struct CTextureFrameTable *_this, unsigned char *pSrc);
//signed int __thiscall sub_44E163(void *_this, const char *Str2);
signed int TextureFrameTable_sub_44E163(void *_this, const char *Str2);
//int __thiscall sub_44E0ED(void *_this, int a2);
int TextureFrameTable_sub_44E0ED(void *_this, int a2);

int TextureFrameTable_GetFrame(void *_this, int a2, signed int a3);









struct SpriteFrame
{
 unsigned char  sIconName[12];    // byte[12] @ 000000
 unsigned char  sTextureName[12]; // byte[12] @ 00000C
 unsigned short pSpriteIDs[8];    // word[8]  @ 000018
 int            dword_000028;
 int            dword_00002C;  // some flags   0x01 next frame sequence is a part of a current (animated sqeuences)   0x10 single frame per frame sequence
 short          word_000030; // looks like bool whether this object is a light source or can be lit by light source. StationaryLight is created if decoration has this field != 0
 short          word_000032;
 short          word_000034; // some palette info returned from sub_48A3BC
 short          word_000036;
 short          word_000038;
 short          word_00003A;
};
//sizeof == 3C

struct SpriteFrameTable
{
 unsigned int         uNumSpriteFrames; // dword @ 000000
 int                  dword_000004;
 int                  dword_000008;   // result of binary search. indexing E-Frames with this yeild actual sprite in S-Frames
 struct SpriteFrame *pSpriteSFrames;  // dword @ 00000C
 struct SpriteFrame **pSpritePFrames; // dword @ 000010   optimized for binary search S-Frames?
 unsigned short      *pSpriteEFrames; // dword @ 000014   after binary search, idx returned index this array here to get idx of sprite in S-Frames:   SFrames[EFrames[dword_000008]] == desired sprite
};
//sizeof ~ 18
void SpriteFrameTable_ctor(struct SpriteFrameTable *_this);
//int __thiscall sub_44D9D7(void *Dst, void *Src)
int SpriteFrameTable_Initialize(struct SpriteFrameTable *_this, unsigned int *pSrc);
//int __thiscall sub_44D96D(void *Str);
int SpriteFrameTable_SaveToBIN(struct SpriteFrameTable *_this);
//int __thiscall sub_44D4D8(int _this)
int SpriteFrameTable_sub_44D4D8(struct SpriteFrameTable *_this);
//int __thiscall class29_fn1(int _this, int a2, signed int a3);
struct SpriteFrame *CSpriteFrameTable_fn1(struct SpriteFrameTable *_this, unsigned int uID, signed int a3);
//int __thiscall class29_fn2(int _this, int a2, signed int a3);
struct SpriteFrame *CSpriteFrameTable_fn2(struct SpriteFrameTable *_this, int a2, signed int a3);
//int __thiscall class29_fn3(int _this);
void SpriteFrameTable_fn3(struct SpriteFrameTable *_this);
//void __thiscall class29_fn4(int _this, int a2);
void SpriteFrameTable_InitializeSpriteFrame(struct SpriteFrameTable *_this, unsigned int uSpriteFrameID);
//int __thiscall class29_fn5(int _this, const char *Str1);
unsigned int SpriteFrameTable_FastFindSprite(struct SpriteFrameTable *_this, const char *Str1); // find sprite using biary search, returns sprite ID
//int __thiscall sub_44D83A(void *_this, int a2, int a3, const char *pSpriteName)
void SpriteFrameTablsub_SpriteBinarySearch(struct SpriteFrameTable *_this, int a2, int a3, const char *pSpriteName);





struct TileDesc
{
 unsigned char sTileName[12];
 int           dword_00000C;
 short         word_000010;
 short         word_000012; // texture id in bitmaps.lod?
 short         word_000014;
 short         word_000016;
 short         word_000018;
};
//sizeof == 1A

struct CTileTable
{
 unsigned int     uNumTiles; // dword @ 000000
 struct TileDesc *pTiles;    // ptr   @ 000004
};
//sizeof == ?

void CTileTable_ctor(struct CTileTable *_this);
//int __thiscall sub_487FB4(void *Str);
int CTileTable_SaveToBIN(struct CTileTable *_this);
//void *__thiscall sub_488000(void *Dst, void *Src);
void CTileTable_Initialize(struct CTileTable *_this, unsigned char *pSrc);
//int __thiscall sub_487ED6(void *_this, int a2, int a3);
int sub_487ED6(struct CTileTable *_this, int a2, int a3);
//int __thiscall sub_487F84(int _this, int a2, int a3);
int sub_487F84(struct CTileTable *_this, int a2, int a3);
//void __thiscall sub_487E58(void *_this, int a2);
void CTileTable_LoadSomeTiles(struct CTileTable *_this, int a2);
//int __thiscall sub_487E3B(int _this, int a2)
struct TileDesc *TileTable_GetTile(struct CTileTable *_this, unsigned int uTileID);


struct PlayerFrame
{
 short          word_000000;
 unsigned short uTextureID; // word @ 000002
 short          word_000004;
 unsigned short word_000006;
 short          word_000008;
};
//sizeof == 0A

struct CPlayerFrameTable
{
 unsigned int        uNumFrames;
 struct PlayerFrame *pFrames;
};

void CPlayerFrameTable_ctor(struct CPlayerFrameTable *_this);
//int __thiscall sub_494BC3(void *Str);
int CPlayerFrameTable_SaveToBIN(struct CPlayerFrameTable *_this);
//void *__thiscall sub_494C0F(void *Dst, void *Src);
void *CPlayerFrameTable_Initialize(struct CPlayerFrameTable *_this, unsigned char *pSrc);
//int __thiscall sub_494B10(int _this, int a2, signed int a3);
struct PlayerFrame *CPlayerFrameTable_GetFrame(struct CPlayerFrameTable *_this, unsigned int uFramesetID, unsigned int uFrameID);

int PlayerFrameTable_sub_494AED(int _this, int a2);
int PlayerFrameTable_sub_494B5E(int _this, int a2, int a3, int a4);




struct DecorationDescription
{
 unsigned char  array_000000[32];
 unsigned char  array_000020[32];
 short          word_000040;
 unsigned short uDecorationHeight;  // word_000042    or actually light source height from the decoration base
 int            dword_000044;
 unsigned short uSpriteID;          // word @ 000048
 short          word_00004A;
 short          word_00004C;
 short          word_00004E;
 unsigned char  uColoredLightRed;   // byte @ 000050
 unsigned char  uColoredLightGreen; // byte @ 000051
 unsigned char  uColoredLightBlue;  // byte @ 000052
 char           _padding;           // byte @ 000053
};
//sizeof == 54

struct DecorationDescriptionList
{
 unsigned int                  uNumLevelDecorations; // dword @ 000000
 struct DecorationDescription *pDescriptions;   // ptr @ 000004
};

void DecorationDescriptionList_ctor(struct DecorationDescriptionList *_this);
//void *__thiscall sub_45864C(void *Dst, void *Src);
void *DecorationDescriptionList_Initialize(struct DecorationDescriptionList *_this, unsigned char *pSrc);
//int __thiscall sub_458600(void *Str);
int DecorationDescriptionList_SaveToBIN(struct DecorationDescriptionList *_this);
//__int16 __thiscall sub_4488B6(void *_this, const char *Str1);
__int16 sub_4488B6(struct DecorationDescriptionList *_this, const char *Str1);
//void __thiscall sub_458693(int _this, int a2);
void sub_458693(struct DecorationDescriptionList *_this, unsigned int uDecorationDescriptionID);


struct ObjectDescription
{
 unsigned char  a[32];
 char           b[4];   // 000020
 char           byte_000024;
 char           byte_000025;
 char           byte_000026;
 char           byte_000027;
 unsigned short uSpriteID; // word @ 000028
 short          word_00002A;
 int            dword_00002C;
 char           byte_000030;
 char           byte_000031;
 char           byte_000032;
 char           byte_000033;
 char           byte_000034;
 char           byte_000035;
 char           byte_000036;
 char           byte_000037;
};
//sizeof == 38

struct CObjectDescriptionList
{
 unsigned int              uNumObjects; // dword @ 000000
 struct ObjectDescription *pDescriptions;   // ptr @ 000004
};

void CObjectDescriptionList_ctor(struct CObjectDescriptionList *_this);
//int __thiscall sub_459090(void *Str);
int CObjectDescriptionList_SaveToBIN(struct CObjectDescriptionList *_this);
//void *__thiscall sub_4590DC(void *Dst, void *Src);
void *CObjectDescriptionList_Initialize(struct CObjectDescriptionList *_this, unsigned char *pSrc);
//void __thiscall sub_459064(void *_this);
void sub_459064(struct CObjectDescriptionList *_this);



struct OverlayDescription
{
 short word_000000;
 short word_000002;
 short word_000004;
 short word_000006;
};
//sizeof == 8

struct COverlayDescriptionList
{
 unsigned int               uNumOverlays;  // dword @ 000000
 struct OverlayDescription *pDescriptions; // ptr @ 000004
};
//sizeof == 8

void COverlayDescriptionList_ctor(struct COverlayDescriptionList *_this);
//int __thiscall sub_458DBC(void *Str)
int COverlayDescriptionList_SaveToBIN(struct COverlayDescriptionList *_this);
//void *__thiscall sub_458E08(void *Dst, void *Src)
void *COverlayDescriptionList_Initialize(struct COverlayDescriptionList *_this, unsigned char *pSrc);
//void __thiscall sub_458D97(void *_this)
void sub_458D97(struct COverlayDescriptionList *_this);



#pragma pack(pop)