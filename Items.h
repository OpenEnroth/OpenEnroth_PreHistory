#pragma once
#pragma pack(push, 1)



#define EQUIP_HAND   0  //right, or both - unsure;   sword has equip type 0
#define EQUIP_ARMOUR 3



struct ItemGen
{
 unsigned int uItemID;      // dword @ 000000
 int          dword_000004;
 int          dword_000008;
 int          dword_00000C;
 int          dword_000010;
 int          dword_000014; // draw mode flags, maybe more
                            // & 0 - draw some way
                            // & 1 - DrawTransparentTexture
                            // & 2 - draw some other way
 char         byte_000018;
 char         byte_000019;
 char         byte_00001A;
 char         byte_00001B;
 short        word_00001C;
 short        word_00001E;
 int          dword_000020;
};
//sizeof = 24



//Item laying on the ground, pickable and rendered as a sprite billboard
struct LayingItem
{
 short          word_000000;
 short          uObjectDescriptionID;  // word  @ 000002
 int            sItemPosX;             // dword @ 000004
 int            sItemPosY;             // dword @ 000008
 int            sItemPosZ;             // dword @ 00000C
 short          uObjectDescriptionID2; // word  @ 000010
 short          word_000012;
 short          word_000014;
 short          word_000016;
 short          word_000018;
 short          word_00001A;
 short          word_00001C;
 unsigned short uSpriteFrameID; // word @ 00001E
 short          word_000020;
 short          word_000022;
 struct ItemGen stru_000024;
 //int            dword_000024;  // very much like ItemGen
 //char           unk_000028[36];
 int            dword_000048;  // probably local struct of the same type
 char           unk_00004Ñ[12];
 int            dword_000058;
 int            dword_00005C;
 char           unk_000060;
 unsigned char  byte_000061;
 char           unk_000062[14];
};
//sizeof == 70



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
 unsigned short uSpriteIndex;      // word  @ 000018
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

 struct Item                   pItems[800];              // struct[800] @ 000000
 struct ItemEnchantment        pEnchantments[24];        // struct[24]  @ 009604
 struct ItemSpecialEnchantment pSpecialEnchantments[72]; // struct[72]  @ 0097E4

 unsigned char *pItemsTXT_Raw;    // ptr @ 011674
 unsigned char *pRndItemsTXT_Raw; // ptr @ 011678
 unsigned char *pStdItemsTXT_Raw; // ptr @ 01167C
 unsigned char *pSpcItemsTXT_Raw; // ptr @ 011680

 int          array_011684[6];
 char         byte_01169C[72];
 unsigned int array_0116E4[9];

 int array_011700[6][2];

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
//char __thiscall class40_sub_456620(void *_this, int a2, signed int a3, int Dst);
char class40_sub_456620(struct class40 *_this, int a2, signed int a3, struct ItemGen *Dst);



#pragma pack(pop)