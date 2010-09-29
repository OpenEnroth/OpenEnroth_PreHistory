#pragma once
#pragma pack(push, 1)


struct ItemGen
{
 unsigned int uItemID;
 int          dword_000004;
 int          dword_000008;
 int          dword_00000C;
 int          dword_000010;
 int          dword_000014;
 char         byte_000018;
 char         byte_000019; //alignment byte
 char         byte_00001A;
 char         byte_00001B; //alignment byte
 int          dword_00001C;
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
 int            dword_000024;  // probably local struct
 char           unk_000028[36];
 int            dword_000048;  // probably local struct of the same type
 char           unk_00004Ñ[12];
 int            dword_000058;
 int            dword_00005C;
 char           unk_000060;
 unsigned char  byte_000061;
 char           unk_000062[14];
};
//sizeof == 70


#pragma pack(pop)