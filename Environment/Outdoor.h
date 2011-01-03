#pragma once
#include <windows.h>
#include <stdio.h>

#include "..\defs.h"

#include "..\Math\Math.h"

#include "Common.h"







#pragma pack(push, 1)


struct ODMFace
{
 Vec3<int>      vFaceNormal;                  // dword[3] @ 000000
 int            sNormalDistance;              // dword    @ 00000C
 int            zCalc1;                       // dword    @ 000010
 int            zCalc2;                       // dword    @ 000014
 int            zCalc3;                       // dword    @ 000018
 unsigned int   uFaceAttributes;              // dword    @ 00001C    & 0x40: word_000110 == TextureFrameTable ID  ?  plain Texture ID
                                              //                    & 0x0100  intersection in xy plane 
                                              //                    & 0x0200  intersection in xz plane
                                              //                    else      intersection in yz plane
                                              //                    0x00000001 - It's a portal.
                                              //                    0x00000010 - The texture is wavy, like water.
                                              //                    0x00002000 - Invisible.
                                              //                    0x00040000 - For facets that can be moved (are a part of door or lever). If set, the texture is moved accordingly.
                                              //                    0x00400000 - The texture moves slowly. For horizontal facets only.
                                              //                    0x02000000 - Event can be triggered by clicking on the facet.
                                              //                    0x04000000 - Event can be triggered by stepping on the facet.
                                              //                    0x20000000 - Untouchable You can pass through it.
 unsigned short pVertexIDs[20];               // word[20] @ 000020     list of face vertices, pVertexIDs[0] == pVertexIDs[uNumVertices]
 unsigned short pTextureUIDs[20];             // word[20] @ 000048    list of face texcoord u's
 unsigned short pTextureVIDs[20];             // word[20] @ 000070    list of face texcoord v's
 unsigned short pXInterceptDisplacements[20]; // word[20] @ 000098
 unsigned short pYInterceptDisplacements[20]; // word[20] @ 0000C0
 unsigned short pZInterceptDisplacements[20]; // word[20] @ 0000E8
 unsigned short uTextureID;                   // word     @ 000110
 short          sTextureDeltaU;               // word     @ 000112
 short          sTextureDeltaV;               // word     @ 000114
 Range<short>   cBoundingBoxX;                // word[2]  @ 000116
 Range<short>   cBoundingBoxY;                // word[2]  @ 00011A
 Range<short>   cBoundingBoxZ;                // word[2]  @ 00011E
 short          sCogNumber;                   // word @ 000122
 short          sCogTriggeredID;              // word @ 000124     Event::dword_000000
 short          sCogTriggerType;              // word @ 000126
 char           unk_000128[2];
 unsigned char  uGradientVertex1;             // byte @ 000012A
 unsigned char  uGradientVertex2;             // byte @ 000012B
 unsigned char  uGradientVertex3;             // byte @ 000012C
 unsigned char  uGradientVertex4;             // byte @ 000012D
 unsigned char  uNumVertices;                 // byte @ 000012E
 unsigned char  uPolygonType;                 // byte @ 000012F
                                              // 5 - ceiling, 6 - in-between ceiling and wall, 1 - vertical wall, 4 - in-between floor and wall, 3 - floor
#if 1  // mm7/8 stuff
 unsigned char  uShadeType;                   // byte @ 000130
 unsigned char  bVisible;                     // byte @ 000131
 char           unk_000132[2];
#endif
};
//sizeof == 134



#pragma pack(pop)





namespace Terrain
{
 namespace Tileset
 {
  enum Type
  {
   Grass = 0,
   Sand = 1,
   Volcanic = 2,

   // seems no 4 at all
   Water = 5


  };
 };
};





class OutdoorLocation
{
 protected:
   struct DDMHeader
   {
    int dword_000000;
    int dword_000004;
    int dword_000008;
    int dword_00000C;
    int dword_000010;  // [4] num faces in bmodels
    int dword_000014;  // [5] num decorations
    int dword_000018;  // [6] num bmodels
    int dword_00001C;
    int dword_000020;
    int dword_000024;
   };
   //sizeof == 28


   struct TerrainData
   {
    inline TerrainData():
      pHeightmap(nullptr), pTilemap(nullptr), pAttributemap(nullptr), ptr_00000C(nullptr)
    {}

    unsigned char *pHeightmap;    // ptr @ 000000    128x128 heightmap data scaled by 1/32
    unsigned char *pTilemap;      // ptr @ 000004    128x128 tilemap data
    unsigned char *pAttributemap; // ptr @ 000008    128x128 attributes
    unsigned char *ptr_00000C;
    short          word_000010;
    short          word_000012;
    short          word_000014;
    short          word_000016;
    int            dword_000018;
    int            dword_00001C;

    Result::Code Initialize();

    Result::Code Reset();
    Result::Code Clear();

    void sub_47C80A(int sX, int sY, int sZ, int sW);
   };
   //sizeof == 20
   //bool sub_47CD44(int_this)                                   0047CD44  TerrainData::Initialize
   //void sub_47C7C2(int_this)                                   0047C7C2  TerrainData::Clear
   //void sub_47C80A(int _this, int sX, int sY, int sZ, int sW)  0047C80A  TerrainData::sub_47C80A
   //signed int sub_47CCE2(void **_this)                         0047CCE2  TerrainData::Reset

   struct TileType
   {
    unsigned short uTileGroup; // word @ 000000   Terrain::Tileset
    unsigned short uTileID;    // word @ 000002
   };


 public:
   unsigned char  string_000000[32];
   unsigned char  pLocationFileName[32];        // byte[32] @ 000020
   unsigned char  pLocationFileDescription[32]; // byte[32] @ 000040
   unsigned char  pSkyTextureName[32];   // byte[32] @ 000060
   unsigned char  pGroundTileset[32];    // byte[32] @ 000080

 TileType       pTileTypes[4]; // struct[4] @ 0000A0

 unsigned int       uNumBModels;  // dword  @ 0000B0
 struct TerrainData cTerrainData; // struct @ 0000B4

 unsigned char         *ptr_0000D4;
 struct BSPModel       *pBModels;      // ptr @ 0000D8
 int                    dword_0000DC;
 unsigned short        *ptr_0000E0;   // IDLIST
 unsigned int          *ptr_0000E4;   // OMAP
 unsigned int           uSkyTextureID; // dword @ 0000E8
 int                    dword_0000EC;  // id in bitmaps.lod; main tile texture id?

 unsigned int   uNumSpawnPoints; // dword @ 0004C0
#if 0
 SpawnPointMM6 *pSpawnPoints;
#else
 SpawnPointMM7 *pSpawnPoints;   // dword @ 0004C4
#endif

 DDMHeader cDDMHeader; // struct @ 0004C8
 int array_0004F0[14];

 unsigned char array_000528[0x3C8];
 unsigned char array_0008F0[0x3C8];
 int           dword_000CB8;
 int           dword_000CBC;
 
 int dword_000D18;
 int dword_000D1C;
 int dword_000D20;

 int dword_000D30; // looks like some light vector
 int dword_000D34;
 int dword_000D38;

 float flt_01C284;
 int   dword_01C288;

 char maybe_more[0x30000];




          OutdoorLocation();
 virtual ~OutdoorLocation() {}


 virtual Result::Code Clear();
 virtual Result::Code Load(const char *pFilename, int File, int a5);

 unsigned int    uNumTerrainNormals;
 Vec3<float>    *pTerrainNormals;
 unsigned short  pTerrainNormalIndices[128 * 128 * 2];
 unsigned int    pTerrainSomeOtherData[128 * 128 * 2];
};
//sizeof ~ ?
//int  sub_47CF9C(int _this)                                                      0047CF9C  OutdoorLocation::Clear
//bool sub_488F5C(int _this, const char *Source, int File, signed int a4, int a5) 00488F5C  merged ->
//bool sub_47D0A6(int _this, const char *Source, int File, int a4, int a5)        0047D0A6  OutdoorLocation::Load

//int __thiscall sub_488F2E(int _this, signed int a2, signed int a3);
int class51_sub_488F2E_GetHeightOnTerrain(OutdoorLocation *_this, unsigned int uX, unsigned int uY);
//int __thiscall sub_47EE16(int _this, signed int a2, signed int a3);
int class51_sub_47EE16_ActuallyGetHeightOnTerrain(OutdoorLocation *_this, unsigned int uX, unsigned int uY);
//signed int __thiscall sub_47EF60(void *_this, int a2, int a3, int a4);
bool class51_sub_47EF60(OutdoorLocation *_this, int a2, int a3, int a4);
bool class51_sub_47F420(OutdoorLocation *_this);
bool class51_sub_47F3EA(OutdoorLocation *_this);
//int __thiscall sub_488EEF(void *_this, signed int a2, signed int a3);
int class51_GetTileTexture(OutdoorLocation *_this, int a2, int a3);
//int __thiscall sub_47ED08(int _this, signed int a2, signed int a3);
int class51_GetTileTexture2(OutdoorLocation *_this, unsigned int uX, unsigned int uY);
//int __thiscall sub_488EB1(void *_this, signed int a2, signed int a3);
int class51_sub_488EB1_GetSomeOtherTileInfo(OutdoorLocation *_this, int sX, int sY);
//int __thiscall sub_47EDB3(int _this, signed int a2, signed int a3);
int class51_sub_47EDB3_ActuallyGetSomeOtherTileInfo(OutdoorLocation *_this, unsigned int uX, unsigned int uY);


int __thiscall class51_CreateDefaultMap(int Dest);




bool sub_44C1E8(ODMFace *_this);
bool sub_482170(ODMFace *_this, struct RenderVertex *a2, struct struct8 *a3);
bool __stdcall sub_45CDB7_Face_ApplyLight(ODMFace *_this, struct class04 *);


















struct struct8
{
 float                flt_000000;
 float                flt_000004;
 float                flt_000008;
 float                flt_00000C;
 float                flt_000010;
 unsigned int         uNumVertices; // dword @ 000014
 int                   dword_000018;
 int                  dword_00001C;
 int                  dword_000020;
 int                  dword_000024;
 int                  sTextureDeltaU; // dword @ 000028  BSPModel::Face::sTextureDeltaU
 int                  sTextureDeltaV; // dword @ 00002C
 short                word_000030;  // word_000018 in struct TileDesc  0x4000 flag -> TextureFrameTable unsupported  0x0002 -> water tile
 short                word_000032;
 int                  dword_000034;
 struct class57      *ptr_000038;
 struct cTexture     *ptr_00003C;
 struct Span         *ptr_000040; // head  ?
 struct Span         *ptr_000044;  // and tail ?
 int                **ptr_000048;
 short                uTextureID; // word @ 00004C    word_000012 in struct TileDesc, texture id in bitmaps.lod
 short                word_00004E;
 short                 word_000050;
 short                word_000052;
 ODMFace             *ptr_000054;
 char                 byte_000058;    //0..31 steps (step = ï/32) of some rotation
 char                 byte_000059;
 char                 byte_00005A;
 char                 byte_00005B;
 char                 byte_00005C;
 char                 byte_00005D;
 char                 byte_00005E;     //bmodel id
 char                 byte_00005F;     //bmodel's class51_stru2 id
 struct Edge         *array_000060[20];
 int                  dword_0000B0;        //num ptrs in 000060
 struct Edge         *array_0000B4[20];
 int                  dword_000104;        //num ptrs in 0000B4
 char                 byte_000108;
 char                 byte_000109[3];
};
//sizeof == 10C
//void __thiscall sub_486089_NormalizeVector(int _this);
void sub_486089_NormalizeVector(struct struct8 *_this);
//char __stdcall sub_45D3C7(int a1);
bool __stdcall sub_45D3C7(struct struct8 *_this);
//int __thiscall sub_48607B(int _this, int a2);
void sub_48607B_MessWithStruct8(struct struct8 *_this, struct class57 *pClass57);
//signed int __thiscall sub_479295(int _this);
bool struct8_sub_479295(struct struct8 *_this);
