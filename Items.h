#pragma once
#pragma pack(push, 1)

#include "Math\Math.h"

namespace Items
{
 namespace Material
 {
  enum
  {
   Ordinary = 0,
   Artifact = 1,
   Relic = 2,
   Special = 3
  };
 };

 namespace EquipType
 {
  enum
  {
   OneOrTwoHands = 0,
   TwoHands = 1,
   Bow = 2,
   Armour = 3,
   Shield = 4,
   Helmet = 5,
   Belt = 6,
   Cloak = 7,
   Gauntlets = 8,
   Boots = 9,
   Ring = 10,
   Amulet = 11,

   Reagent = 13,
   Potion = 14,

   Book = 16,

   Gold = 18,
   Gem = 19

  };
 };
};



struct ItemGen
{
 unsigned int uItemID;      // dword @ 000000
 int          dword_000004;
 int          dword_000008;
 int          dword_00000C;
 int          dword_000010;
 unsigned int uAttributes; //dword @ 000014   draw mode flags, maybe more
                            // & 0 - draw some way
                            // & 1 - DrawTransparentTexture
                            // & 2 - draw some other way
 char         byte_000018;  // 2 == equipped? (probably (right) hand)  3 == equipped (body leather)
 char         byte_000019;
 char         byte_00001A;
 char         byte_00001B;
 short        word_00001C;
 short        word_00001E;
 int          dword_000020;
};
//sizeof = 24

void ItemGen_Reset(struct ItemGen *_this);  // ctor apparently

int ItemGen_sub_456442(ItemGen *_this);
int ItemGen_sub_456499(ItemGen *_this);
int ItemGen_sub_4564B3(ItemGen *_this);
signed int sub_4505CC(void *_this);


//Item laying on the ground, pickable and rendered as a sprite billboard
struct LayingItem
{
 unsigned short uItemType;             // word     @ 000000
 short          uObjectDescriptionID;  // word     @ 000002
 Vec3<int>      vPosition;             // dword[3] @ 000004
 Vec3<short>    vVelocity;             // word[3]  @ 000010
 unsigned short uFacing;               // word     @ 000016
 unsigned short uSoundID;              // word     @ 000018
 unsigned short uAttributes;           // word     @ 00001A
 short          sRoom;                 // word     @ 00001C
 unsigned short uSpriteFrameID;        // word     @ 00001E
 short          word_000020;
 short          word_000022;
 struct ItemGen stru_000024;
 int            dword_000048;  // probably local struct of the same type
 int            dword_00004C;
 int            dword_000050;
 int            dword_000054;
 int            dword_000058;
 int            dword_00005C;
 char           unk_000060;
 unsigned char  byte_000061;
 char           unk_000062[14];
};
//sizeof == 70
void sub_404828_ctor(LayingItem *_this);
//void __stdcall sub_4A7A66(int a1, int a2, int a3, float a4);
void __stdcall sub_4A7A66(LayingItem *a1, int a2, int a3, float a4);
//char __stdcall sub_4A7A27(int a1, unsigned int a2, int a3);
char __stdcall sub_4A7A27(LayingItem *a1, unsigned int a2, int a3);
//void __stdcall sub_4A7948(int a1);
void __stdcall sub_4A7948(LayingItem *a1);
//void __stdcall sub_4A78AE(int a1);
void __stdcall sub_4A78AE(LayingItem *a1);
//void __stdcall sub_4A75CC(int a1, int a2, int a3);
void __stdcall sub_4A75CC(LayingItem *a1, int a2, int a3);
//signed int __fastcall sub_42F5ED(int a1, int a2, int a3, int a4, int a5);
signed int __fastcall sub_42F5ED(LayingItem *a1, int a2, int a3, int a4, int a5);








struct ItemEnchantment
{
 unsigned char *pName;  // ptr @ 000000
 unsigned char *pParam; // ptr @ 000004

 unsigned char  array_000008[9];

 char padding[3];
};
//sizeof == 14

struct ItemSpecialEnchantment
{
 unsigned char *pName;  // ptr @ 000000
 unsigned char *pParam; // ptr @ 000004

 unsigned char  array_000008[12];
 int            dword_000014;
 /*char*/int    byte_000018;
};
//sizeof == 1C

struct Item
{
 int            dword_000000;
 unsigned char *pIconName;         // ptr   @ 000004
 unsigned char *pName;             // ptr   @ 000008
 unsigned char *pUnidentifiedName; // ptr   @ 00000C
 unsigned char *pDescription;      // ptr   @ 000010
 unsigned int   uValue;            // dword @ 000014
 unsigned short uSpriteIndex;      // word  @ 000018   or ItemType from LayingItem::000000
 short          word_00001A;
 unsigned short uEquipX;           // word  @ 00001C
 unsigned short uEquipY;           // word  @ 00001E
 unsigned char  uEquipType;        // byte  @ 000020
 unsigned char  uSkillType;        // byte  @ 000021
 unsigned char  uDamageDice;       // byte  @ 000022
 unsigned char  uDamageRoll;       // byte  @ 000023
 unsigned char  uDamageModifier;   // byte  @ 000024
 unsigned char  uMaterial;         // byte  @ 000025
 char           byte_000026;
 char           byte_000027;
 char           byte_000028;
 char           byte_000029[3];
 char           byte_00002C[4];
 //char byte_000032;
};
//sizeof == 30




//many items desc
struct class40
{
 int  uNumItems; // dword @ 000000   looks like this sits in pItems[0]::dword_000000

 struct Item                    pItems[800];              // struct[800] @ 000000
 struct ItemEnchantment         pEnchantments[24];        // struct[24]  @ 009604
 struct ItemSpecialEnchantment  pSpecialEnchantments[72]; // struct[72]  @ 0097E4
 char                           unk_009FC4[0x4FA0];
 short                          unk_00EF64[0x1388/2];
 short                          unk_0102EC[0x1388/2];
 unsigned char                 *pItemsTXT_Raw;    // ptr @ 011674
 unsigned char                 *pRndItemsTXT_Raw; // ptr @ 011678
 unsigned char                 *pStdItemsTXT_Raw; // ptr @ 01167C
 unsigned char                 *pSpcItemsTXT_Raw; // ptr @ 011680

 int          array_011684[6];
 char         byte_01169C[60];
 int          unk_0116D8[24]; // exact size uknown
 //int          unk_0116D8[3];   // ~20 elements actually
 //unsigned int array_0116E4[7];
 //int array_011700[6][2];

 int array_011738[24];
 int dword_011798;

 char padding[50000];
};
//sizeof ~ ?

//char *__thiscall sub_456D84(void *_this);
char *sub_456D84(struct class40 *_this);
//int __thiscall sub_453B3C(void *_this);
void class40_LoadPotionsTable(struct class40 *_this);
//const char *__thiscall sub_453CE5(void *_this)
void class40_LoadPotionNotes(struct class40 *_this);
//char __thiscall class40_sub_456620_CreateSomeSemirandomItem(void *_this, int a2, signed int a3, int Dst);
char class40_sub_456620_CreateSomeSemirandomItem(struct class40 *_this, int a2, signed int a3, struct ItemGen *Dst);
//bool __thiscall sub_456D5E(void *_this, int a2);
bool class40_sub_456D5E(struct class40 *_this, ItemGen *pItem);
//int sub_456D17(struct class40 *_this, struct ItemGen *a2);
int class40_sub_456D17(struct class40 *_this, struct ItemGen *a2);
//bool __thiscall sub_456D43(void *_this, int a2);
bool class40_sub_456D43(class40 *_this, ItemGen *pItem);



#pragma pack(pop)