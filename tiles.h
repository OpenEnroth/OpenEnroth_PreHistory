#pragma once


#pragma pack(push, 1)
struct TileDesc
{
 unsigned char  sTileName[16];
 //int            dword_00000C;
 unsigned short uTileID;      // word @ 000010
 unsigned short uBitmapID;    // word @ 000012
 unsigned short uTerrainType; // word @ 000014
 unsigned short uSection;     // word @ 000016
 unsigned short uAttributes;  // word @ 000018
};
//sizeof == 1A
#pragma pack(pop)

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

//----- (00488047) --------------------------------------------------------
signed int __thiscall sub_488047(int _this, const char *a2);

#pragma pack(pop)