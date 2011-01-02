#pragma once
#include "..\CoreDefinitions.h"
#include "..\Math\Math.h"

#include "Outdoor.h"


class IndoorLocation
{
 public:
   struct IndoorLocation_stru0
   {
    char unk_000000[104];
    int  dword_000068_sizeof_lf_data;
    char unk_0006C[28];
   };
   //sizeof == 88

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

     word_000048 = 0;
    }

    Vec3<float>     vFaceNormalf;    // float[3] @ 000000
    float           fNormalDistance; // float    @ 00000C
    Vec3<int>       vFaceNormal;     // dword[3] @ 000010    BSPModel::Face::pFaceNormal
    int             sNormalDistance; // dword    @ 00001C    BSPModel::Face::sNormalDistance
    int             zCalc1;          // dword @ 000020  BSPModel::Face::zCalc1
    int             zCalc2;          // dword @ 000024
    int             zCalc3;          // dword @ 000028
    unsigned int    uFaceAttributes; // dword @ 00002C  BSPModel::Face::uFaceAttributes
    unsigned short *pVertexIDs;               // dword @ 000030  vertex indices list
    unsigned short *pXInterceptDisplacements; // dword @ 000034  BSPModel::pXInterceptDisplacements
    unsigned short *pYInterceptDisplacements; // dword @ 000038
    unsigned short *pZInterceptDisplacements; // dowrd @ 00003C
    char            unk_000040[8];
    short           word_000048;
    unsigned short  uTextureID;    // word    @ 00004A
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




   IndoorLocation();
   char pLocationFileName[32];     // byte[32] @ 000020

   unsigned int bLoaded; // dword @ 000050

   IndoorLocation_stru0 struct_0001E8;

   unsigned int  uNumVertices; // dword @ 000270
   Vec3<short>  *pVertices;    // dword @ 000274
   unsigned int  uNumFaces;    // dword @ 000278
   BLVFace      *pFaces;       // dword @ 00027C
   int  dword_000280;
   int *ptr_0000284;   // 36 bytes
   int  dword_000288;
   int *ptr_000028C;   // 116 bytes
   int  dword_000290;
   int *ptr_0000294;   // 16 bytes
   int  dword_000298;
   int *ptr_000029C;   // 80 bytes/elem, related to doors  dword_000004 == door id
   int  dword_0002A0;
   BSPModel::BSPNode *pNodes; // dword @ 00002A4
   int *ptr_00002A8; // 12 bytes first seems to be dummy with num elems at 0th dw_000000
   char *ptr_00002AC;
   int *ptr_00002B0;
   int *ptr_00002B4;
   int *ptr_00002B8;
   int  dword_00002BC; // num 2c0
   int *ptr_00002C0; // 24 bytes/elem

   virtual Result::Code Clear();
   virtual Result::Code Load(const char *pFilename, int a3, int a5);
};
//sizeof == ?
//signed int sub_498E0A(void *Dest, const char *Args, int a3, int a5)   00498E0A  Indoor::Load
//int sub_498B15(int _this)                                             00498B15  Indoor::Clear

int IndoorLocation_sub_49AC17(int _this, int sPosX, int sPosY, int sPosZ);
signed int IndoorLocation_sub_498C45(int _this);







void sub_4C0EF2_BSPModel_Face_To_BLV_Face(IndoorLocation::BLVFace *_this, BSPModel::Face *a2);
char __stdcall sub_436455(IndoorLocation::BLVFace *a1);
char __stdcall sub_438258(IndoorLocation::BLVFace *a1, int a2);
int __stdcall sub_4C1D2B(IndoorLocation::BLVFace *a1, Vec3<short>, unsigned int uModelID);