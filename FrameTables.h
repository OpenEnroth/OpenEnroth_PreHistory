#pragma once
#pragma pack(push, 1)

struct IconFrame
{
 unsigned char sIconName[12];    // byte[12] @ 000000
 unsigned char sTextureName[12]; // byte[12] @ 00000C
 short         word_000018; // frame time?
 short         word_00001A; // num frames?
 short         word_00001C;
 short         uTextureIdx;      // word @ 00001E
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
void *CIconFrameTable_Initialize(struct CIconFrameTable *_this, void *pSrc);
//signed int __thiscall sub_49509D(int this, const char *Args);
int CIconFrameTable_InitializeFromTXT(struct CIconFrameTable *_this, const char *pSourceFile);
//int __thiscall sub_494F3A(void *this, const char *Str1);
unsigned int CIconFrameTable_FindIcon(struct CIconFrameTable *_this, const char *pIconName);
//void __thiscall sub_494FBF(int this, int a2);
void CIconFrameTable_InitializeIcon(struct CIconFrameTable *_this, unsigned int uIconIdx);
//int __thiscall sub_49500A(void *Str);
int CIconFrameTable_SaveToBIN(struct CIconFrameTable *_this);
//int __thiscall sub_494F70(int this, int a2, signed int a3);
struct IconFrame *CIconFrameTable_GetFrame(struct CIconFrameTable *_this, int a2, signed int a3);





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
void *CTextureFrameTable_Initialize(struct CTextureFrameTable *_this, unsigned char *pSrc);
//signed int __thiscall sub_44E1EC(int this, const char *Args);
int CTextureFrameTable_InitializeFromTXT(struct CTextureFrameTable *_this, const char *pSourceFile);









struct SpriteFrame
{
 unsigned char sIconName[12];    // byte[12] @ 000000
 unsigned char sTextureName[12]; // byte[12] @ 00000C
 short         word_000018;
 short         array_00001A[7];
 int           dword_000028;
 int           dword_00002C;
 short         word_000030;
 short         word_000032;
 short         word_000034;
 short         word_000036;
 short         word_000038;
 short         word_00003A;
};
//sizeof == 3C

struct CSpriteFrameTable
{
 unsigned int    uNumSpriteFrames; // dword @ 000000
 int             dword_000004;
 int             dword_000008;
 struct SpriteFrame *pSpriteSFrames; // ptr @ 00000C
 struct SpriteFrame **pSpritePFrames; // ptr @ 000010
 unsigned short *pSpriteEFrames; // ptr @ 000014
};
//sizeof ~ 18
void CSpriteFrameTable_ctor(struct CSpriteFrameTable *_this);
//int __thiscall sub_44D9D7(void *Dst, void *Src)
int CSpriteFrameTable_Initialize(struct CSpriteFrameTable *_this, void *pSrc);
//int __thiscall sub_44D96D(void *Str);
int CSpriteFrameTable_SaveToBIN(struct CSpriteFrameTable *_this);

int CSpriteFrameTable_LoadFromTXT(struct CSpriteFrameTable *_this, const char *pSourceFile);
//int __thiscall sub_44D4D8(int this)
int CSpriteFrameTable_sub_44D4D8(struct CSpriteFrameTable *_this);
//int __thiscall class29_fn1(int this, int a2, signed int a3);
struct SpriteFrame *CSpriteFrameTable_fn1(struct CSpriteFrameTable *_this, unsigned int uID, signed int a3);
//int __thiscall class29_fn2(int this, int a2, signed int a3);
int CSpriteFrameTable_fn2(struct CSpriteFrameTable *_this, int a2, signed int a3);
//int __thiscall class29_fn3(int this);
void CSpriteFrameTable_fn3(struct CSpriteFrameTable *_this);
//void __thiscall class29_fn4(int this, int a2);
void CSpriteFrameTable_fn4(struct CSpriteFrameTable *_this, int a2);
//int __thiscall class29_fn5(int this, const char *Str1);
int CSpriteFrameTable_fn5(struct CSpriteFrameTable *_this, const char *Str1);





struct TileDesc
{
 unsigned char sTileName[12];
 int           dword_00000C;
 short         word_000010;
 short         word_000012;
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
//signed int __thiscall sub_488047(int this, const char *a2)
int CTileTable_InitializeFromTXT(struct CTileTable *_this, const char *pSourceFile);
//int __thiscall sub_487FB4(void *Str);
int CTileTable_SaveToBIN(struct CTileTable *_this);
//void *__thiscall sub_488000(void *Dst, void *Src);
void CTileTable_Initialize(struct CTileTable *_this, unsigned char *pSrc);
//int __thiscall sub_487ED6(void *this, int a2, int a3);
int sub_487ED6(struct CTileTable *_this, int a2, int a3);
//int __thiscall sub_487F84(int this, int a2, int a3);
int sub_487F84(struct CTileTable *_this, int a2, int a3);
//void __thiscall sub_487E58(void *this, int a2);
void CTileTable_LoadSomeTiles(struct CTileTable *_this, int a2);


struct PlayerFrame
{
 int   dword_000000;
 int   dword_000004;
 short word_000008;
};


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
//signed int __thiscall sub_494C5A(int this, const char *Args);
int CPlayerFrameTable_InitializeFromTXT(struct CPlayerFrameTable *_this, const char *pSourceFile);





struct DecorationDescription
{
 unsigned char array_000000[32];
 unsigned char array_000020[32];
 int           dword_000040;
 int           dword_000044;
 short         word_000048;
 short         word_00004A;
 short         word_00004C;
 short         word_00004E;
 int           dword_000050;
};
//sizeof == 54

struct CDecorationDescriptionList
{
 unsigned int                  uNumDecorations; // dword @ 000000
 struct DecorationDescription *pDescriptions;   // ptr @ 000004
};

void CDecorationDescriptionList_ctor(struct CDecorationDescriptionList *_this);
//signed int __thiscall sub_4586B0(int this, const char *Args);
int CDecorationDescriptionList_InitializeFromTXT(struct CDecorationDescriptionList *_this, const char *pSourceFile);
//void *__thiscall sub_45864C(void *Dst, void *Src);
void *CDecorationDescriptionList_Initialize(struct CDecorationDescriptionList *_this, unsigned char *pSrc);
//int __thiscall sub_458600(void *Str);
int CDecorationDescriptionList_SaveToBIN(struct CDecorationDescriptionList *_this);
//__int16 __thiscall sub_4488B6(void *this, const char *Str1);
__int16 sub_4488B6(struct CDecorationDescriptionList *_this, const char *Str1);
//void __thiscall sub_458693(int this, int a2);
void sub_458693(struct DecorationDescriptionList *_this, unsigned int uDecorationDescriptionID);


struct ObjectDescription
{
 unsigned char a[32];
 char b[6];
 char     byte_000026;
 char     byte_000027;
 short    word_000028;
 short    word_00002A;
 int      dword_00002C;
 char     byte_000030;
 char     byte_000031;
 char     byte_000032;
 char     byte_000033;
 char     byte_000034;
 char     byte_000035;
 char     byte_000036;
 char     byte_000037;
 char d[6];
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
//signed int __thiscall sub_459123(int this, const char *a2);
int CObjectDescriptionList_InitializeFromTXT(struct CObjectDescriptionList *_this, const char *pSourceFile);
//void *__thiscall sub_4590DC(void *Dst, void *Src);
void *CObjectDescriptionList_Initialize(struct CObjectDescriptionList *_this, unsigned char *pSrc);
//void __thiscall sub_459064(void *this);
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
//signed int __thiscall sub_458E4F(int this, const char *a2)
int COverlayDescriptionList_InitializeFromTXT(struct COverlayDescriptionList *_this, const char *pSourceFile);
//void *__thiscall sub_458E08(void *Dst, void *Src)
void *COverlayDescriptionList_Initialize(struct COverlayDescriptionList *_this, unsigned char *pSrc);
//void __thiscall sub_458D97(void *this)
void sub_458D97(struct COverlayDescriptionList *_this);



#pragma pack(pop)