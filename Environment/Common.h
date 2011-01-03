#pragma once
#include "..\CoreDefinitions.h"




struct ODMFace;
struct BLVFace;




struct BSPModel
{
 struct BSPNode
 {
  int dword_000000;
  int dword_000004;
 };
 //sizeof == 08


 //runtime_warning(read direcrlty from file)
 #pragma pack(push, 1)
   unsigned char         pModelName[32];   // byte[32] @ 000000
   unsigned char         pModelName2[32];  // byte[32] @ 000020
   int                   dword_000040;
   unsigned int          uNumVertices;     // dword  @ 000044
   Vec3<int>            *pVertices;        // dword  @ 000048
   unsigned int          uNumFaces;        // dword  @ 00004C
   unsigned int          uNumConvexFaces;  // d/word @ 000050
   ODMFace              *pFaces;           // dword  @ 000054
   unsigned short       *pFacesOrdering;   // dword  @ 000058
   unsigned int          uNumNodes;        // dword  @ 00005C
   BSPNode              *pNodes;           // dword  @ 000060
   unsigned int          uNumDecorations;  // dword  @ 000064
   int                   sCenterX;         // dword  @ 000068
   int                   sCenterY;         // dword  @ 00006C
   int                   sPosX;            // dword  @ 000070
   int                   sPosY;            // dword  @ 000074
   int                   sPosZ;            // dword  @ 000078
   int                   sMinX;            // dword  @ 00007C
   int                   sMinY;            // dword  @ 000080
   int                   sMinZ;            // dword  @ 000084
   int                   sMaxX;            // dword  @ 000088
   int                   sMaxY;            // dword  @ 00008C
   int                   sMaxZ;            // dword  @ 000090
   int                   sSomeOtherMinX;   // dword  @ 000094
   int                   sSomeOtherMinY;   // dword  @ 000098
   int                   sSomeOtherMinZ;   // dword  @ 00009C
   int                   sSomeOtherMaxX;   // dword  @ 0000A0
   int                   sSomeOtherMaxY;   // dword  @ 0000A4
   int                   sSomeOtherMaxZ;   // dword  @ 0000A8
   int                   sBoundingCenterX; // dword  @ 0000AC
   int                   sBoundingCenterY; // dword  @ 0000B0
   int                   sBoundingCenterZ; // dword  @ 0000B4
   int                   sBoundingRadius;  // dword  @ 0000B8
 #pragma pack(pop)
};
//sizeof == BC







struct SpawnPointMM6
{
 int            sPosX;       // dword @ 000000
 int            sPosY;       // dword @ 000004
 int            sPosZ;       // dword @ 000008
 unsigned short uRadius;     // word  @ 00000C
 unsigned short uKind;       // word  @ 00000E
 unsigned short uIndex;      // word  @ 000010  Index: monster (1-3: M1-M3,  4-6: M1a-M1c,  7-9: M2a-M2c,  10-12: M3a-M3c) or item (1-6)
 unsigned short uAttributes; // word  @ 000012
};
// sizeof == 14

struct SpawnPointMM7: public SpawnPointMM6
{
 unsigned int uGroup; // dword @ 000014
};
// sizeof == 18
