#pragma once
#include "..\CoreDefinitions.h"
#include "..\Math\Math.h"

#include "Common.h"
#include "Outdoor.h"




struct BLVFace
{
 //----- (0046ED02) --------------------------------------------------------
 inline BLVFace()
 {
  uNumVertices = 0;

  uFaceAttributes = 0;
  pVertexIDs = nullptr;
  pXInterceptDisplacements = nullptr;
  pYInterceptDisplacements = nullptr;
  pZInterceptDisplacements = nullptr;

  uFaceExtraID = 0;
 }


#if 1 // mm7/8 stuff
 Vec3<float>     vFaceNormalf;    // float[3] @ 000000
 float           fNormalDistance; // float    @ 00000C
#endif
 Vec3<int>       vFaceNormal;     // dword[3] @ 000010    BSPModel::Face::pFaceNormal
 int             sNormalDistance; // dword    @ 00001C    BSPModel::Face::sNormalDistance
 int             zCalc1;          // dword @ 000020  BSPModel::Face::zCalc1
 int             zCalc2;          // dword @ 000024
 int             zCalc3;          // dword @ 000028
 unsigned int    uFaceAttributes; // dword @ 00002C  BSPModel::Face::uFaceAttributes
 unsigned short *pVertexIDs;               // dword @ 000030  vertex indices list
 unsigned short *pXInterceptDisplacements; // dword @ 000034  BSPModel::pXInterceptDisplacements
 unsigned short *pYInterceptDisplacements; // dword @ 000038
 unsigned short *pZInterceptDisplacements; // dword @ 00003C
 unsigned short *pVertexUIDs;              // dword @ 000040
 unsigned short *pVertexVIDs;              // dword @ 000044
 unsigned short  uFaceExtraID;  // word    @ 000048  idx in Face Extras
 unsigned short  uBitmapID;     // word    @ 00004A
 char            unk_00004C[4];
 Range<short>    cBoundingBoxX; // word[2] @ 000050
 Range<short>    cBoundingBoxY; // word[2] @ 000054
 Range<short>    cBoundingBoxZ; // word[2] @ 000058
 unsigned char   uPolygonType;  // byte    @ 00005C
 unsigned char   uNumVertices;  // byte    @ 00005D
 char            byte_00005E;
 char            byte_00005F;
};
//sizeof == 60
void sub_4C0EF2_ODMFace_to_BLVFace(BLVFace *to, ODMFace *from);


struct BLVFaceExtra
{
 short          unk_000000[6];
 unsigned short word_00000C;         // some index
 unsigned short uAdditionalBitmapID; // word @ 00000E
 short          unk_000010[2];
 short          sTextureDeltaU;      // word @ 000014
 short          sTextureDeltaV;      // word @ 000016
 short          word_000018;
 unsigned short uEventID;            // word @ 00001A  in map evt
 short          unk_00001C[4];
};
//sizeof == 24




struct BLVDoor
{
 int             dword_000000;
 unsigned int    uDoorID;      // dword @ 000004
 int             dword_000008;
 char            unk_00000C[24];
 unsigned short *ptr_000024;
 unsigned short *pFaceIDs;     // dword @ 000028
 unsigned short *ptr_00002C;
 short          *pDeltaUs;     // dword @ 000030
 short          *pDeltaVs;     // dword @ 000034
 unsigned short *ptr_000038;
 unsigned short *ptr_00003C;
 unsigned short *ptr_000040;
 unsigned short  word_000044;
 unsigned short  uNumFaces;    // word @ 000046    pFaceIDs, pDeltaUs, pDeltaVs
 unsigned short  word_000048;
 unsigned short  word_00004A;
 short           word_00004C;
 short           word_00004E;
};
//sizeof == 50




class IndoorLocation
{
 public:
   struct BLVHeader
   {
    char unk_000000[104];
    unsigned int dword_000068_sizeof_faces_fdata;
    unsigned int dword_00006C_sizeof_sector_rdata;
    unsigned int dword_000070_sizeof_sector_lrdata;
    unsigned int dword_000074_sizeof_doors_ddata;
    char         unk_00078[16];
   };
   //sizeof == 88

   struct DLVHeader
   {
    int  dword_000000;
    int  dword_000004;
    char unk_000008[4];
    int  dword_00000C;
    int  dword_000010; // num faces
    int  dword_000014; // num decorations
    int  dword_000018; // ?   num bmodels? sometimes zero
    char unk_00001C[12];
   };
   //sizeof == 28

   struct BLVSector
   {
    char            unk_000000[4];
    unsigned short  word_000004;
    char            unk_000006[2];
    unsigned short *ptr_000008;
    unsigned short  word_00000C;
    char            unk_00000E[2];
    unsigned short *ptr_000010;
    unsigned short  word_000014;
    char            unk_000016[2];
    unsigned short *ptr_000018;
    unsigned short  word_00001C;
    char            unk_00001E[2];
    unsigned short *ptr_000020;
    unsigned short  word_000024;
    char            unk_000026[2];
    unsigned short *ptr_000028;
    unsigned short  word_00002C;
    char            unk_00002E[2];
    unsigned short *ptr_000030;
    char            unk_000034[8];
    unsigned short  word_00003C;
    char            unk_00003E[2];
    unsigned short *ptr_000040;
    unsigned short  word_000044;
    char            unk_000046[2];
    unsigned short *ptr_000048;
    unsigned short  word_00004C;
    char            unk_00004E[2];
    unsigned short *ptr_000050;
    unsigned short  word_000054;
    char            unk_000056[2];
    unsigned short *ptr_000058;
    char            unk_00005C[24];
#if 0 //mm8
    int dword_000074;
#endif
   };
   //sizeof == 74

   struct BLVLight
   {
    Vec3<short>    vPosition;   // word[3] @ 000000
    short          word_000006;
    short          word_000008;
    unsigned short uBrightness; // word @ 00000A
#if 1 // MM7
    unsigned char  uRed;        // byte @ 00000C
    unsigned char  uGreen;      // byte @ 00000D
    unsigned char  uBlue;       // byte @ 00000E
    unsigned char  unk_00000F;
 #if 0 // MM8
    char           unk_000010[4];
 #endif
#endif
   };
   //sizeof == 10

   struct BLVMapVertex
   {
    short sX1; // word @ 000000
    short sY1; // word @ 000002
    short sX2; // word @ 000004
    short sY2; // word @ 000006
    short sZ;  // word @ 000008
    short word_00000A;
   };
   //sizeof == 0C






   IndoorLocation();


   char pLocationFileName[32];     // byte[32] @ 000020

   unsigned int bLoaded; // dword @ 000050

   BLVHeader          cBLVHeader;     // struct @ 0001E8
   unsigned int       uNumVertices;   // dword  @ 000270
   Vec3<short>       *pVertices;      // dword  @ 000274
   unsigned int       uNumFaces;      // dword  @ 000278
   BLVFace           *pFaces;         // dword  @ 00027C
   unsigned int       uNumFaceExtras; // dword  @ 000280
   BLVFaceExtra      *pFaceExtras;    // dword  @ 000284
   unsigned int       uNumSectors;    // dword  @ 000288
   BLVSector         *pSectors;       // dword  @ 00028C
   unsigned int       uNumLights;     // dword  @ 000290
   BLVLight          *pLights;        // dword  @ 000294
   unsigned int       uNumDoors;      // dword  @ 000298
   struct BLVDoor    *pDoors;         // dword  @ 00029C dword_000004 == door id
   unsigned int       uNumNodes;      // dword  @ 0002A0
   BSPModel::BSPNode *pNodes;         // dword  @ 0002A4
   unsigned char     *ptr_0002A8;     // BLVMapVertex array;  first 4 bytes int = num struct following
   unsigned short    *ptr_0002AC;
   unsigned short    *ptr_0002B0_sector_rdata;
   unsigned short    *ptr_0002B4_doors_ddata;
   unsigned short    *ptr_0002B8_sector_lrdata;
   unsigned int       uNumSpawnPoints;          // dword  @ 0002BC
   SpawnPointMM7     *pSpawnPoints;             // dword  @ 0002C0
   DLVHeader          cDLVHeader;               // struct @ 0002C4
   char               unk_0002EC[56];
   unsigned char      unk_000324[0x36B];

   virtual Result::Code Clear();
   virtual Result::Code Load(const char *pFilename, int a3, int a5);
};
//sizeof == ?
//signed int sub_498E0A(void *Dest, const char *Args, int a3, int a5)   00498E0A  Indoor::Load
//int sub_498B15(int _this)                                             00498B15  Indoor::Clear

int IndoorLocation_sub_49AC17(int _this, int sPosX, int sPosY, int sPosZ);
signed int IndoorLocation_sub_498C45(int _this);







char __stdcall sub_436455(BLVFace *a1);
char __stdcall sub_438258(BLVFace *a1, int a2);
int __stdcall sub_4C1D2B(BLVFace *a1, Vec3<short>, unsigned int uModelID);


bool sub_44C23B(BLVFaceExtra *_this);