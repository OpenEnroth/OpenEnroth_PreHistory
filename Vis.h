#pragma once
#include "CoreDefinitions.h"
#include "Level.h"
#include "Math\Math.h"



struct struct12
{
 //----- (0046ED02) --------------------------------------------------------
 inline struct12()
 {
  uNumVertices = 0;

  uFaceAttributes = 0;
  pVertexIDs = nullptr;
  pXInterceptDisplacements = nullptr;
  pYInterceptDisplacements = nullptr;
  pZInterceptDisplacements = nullptr;

  word_000048 = 0;
 }

 float           pFaceNormalf[3]; // float[3] @ 000000
 float           fNormalDistance; // float    @ 00000C
 int             pFaceNormal[3];  // dword[3] @ 000010    BSPModel::Face::pFaceNormal
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
void sub_4C0EF2_BSPModel_Face_To_struct12(struct12 *_this, BSPModel::Face *a2);
char __stdcall sub_436455(struct12 *a1);
char __stdcall sub_438258(struct12 *a1, int a2);
int __stdcall sub_4C1D2B(struct12 *a1, Vec3<short>, unsigned int uModelID);





struct class25_stru0
{
 unsigned int uBillboardID; // dword @ 000000  Billboard ID for indoor,  class51_stru2 * for outdoor
 int          sZValue;      // dword @ 000004  RenderBillboard::sZValue, zbuf_val returned by sub_4C1BAA_Vis_get_object_zbuf_val
 int dword_000008; // object type for sub_4C1BAA_Vis_get_object_zbuf_val
                   // 1: sprite
};
//sizeof = 0C

//class25
struct class25
{
         class25();
 inline ~class25() {}

 void                 (*detor_ptr)(struct class25 *, unsigned int); // dword @ 000000
 struct class25_stru0  array_000004[512];
 struct class25_stru0 *array_001804[512];
 unsigned int          uNumPointers; // dword @ 002004
};
//sizeof = 2008
//void class25_detor(struct class25 *_this , unsigned int a2)                  class25::_dtor
//__int64 __thiscall sub_4C055C(void *_this)                         004C055C  class25::_ctor
//void *__thiscall sub_4C2591(int _this, int a2);
void class25_create_object_pointers(struct class25 *_this, int a2);
//void sub_4C264A(int a2, int a3, int a4);
/*private*/ void class25_sort_object_pointers(struct class25_stru0 **pPointers, int sLeft, int sRight);



struct Vis_stru0 // LOOKS LIKE RenderVertex
{
 float x; // float @ 000000
 float y; // float @ 000004
 float z; // float @ 000008
 float flt_00000C;
 int   unk_000010[2];
 float flt_000018;
 float flt_00001C;
 int   unk_000020[3];
 float flt_00002C;
};
//sizeof == 30

//Vis
struct Vis
{
         Vis();
 inline ~Vis() {}

 void              (*detor_ptr)(struct Vis *, unsigned int); // dword  @ 000000
 struct class25     class25_obj;                             // struct @ 000004
 struct Vis_stru0   struct_00200C;
 struct Vis_stru0   struct_00203C;
 struct Vis_stru0   struct_00206C;
 struct Vis_stru0   struct_00209C;
 int                dword_0020CC;

 
 Result::Code PickMouse(float fDepth, float fMouseX, float fMouseY, struct unnamed_F93E6C *a5, struct unnamed_F93E6C *a6);
 Result::Code PickKeyboard(struct unnamed_F93E6C *a3, struct unnamed_F93E6C *a4);

 /*protected*/ Result::Code CastRayAtMousePosition(Vis_stru0 *a1, struct OldCamera *pCamera, float fMouseX, float fMouseY, float fDepth);
};
//sizeof = 0020D0
//int __thiscall sub_4C04AF(int _this)                            004C04AF  Vis::_ctor
//void Vis_detor(struct Vis *_this, unsigned int a2)                        Vis::_dtor
//int __stdcall sub_4C248E(int a1, float a2, float a3, float a4)  004C248E  Vis::CastRayAtMousePosition

//int __thiscall sub_4C1A02(int _this);
void Vis_sub_4C1A02(struct Vis *_this);
//char sub_4C0646(int _this, float a2, float a3, float a4, int a5, int a6)    004C0646  Vis::PickMouse
//char sub_4C05CC(int _this, int a2, int a3, int a4)                          004C05CC  Vis::PickKeyboard

//void __thiscall sub_4C06F8(void *_this, float a2, int a3, int a4);
void Vis_sub_4C06F8(struct Vis *_this, float a2, struct class25 *a3, struct unnamed_F93E6C *a4);
//char __stdcall sub_4C0791(int a1, int a2);
bool Vis_is_part_of_selection(unsigned int uD3DBillboardID, struct unnamed_F93E6C *a2);
//char __thiscall sub_4C091D(void *_this, float a2, int a3);
bool Vis_IsRayIntersectsSprite(struct Vis *_this, float fDepth, int a3);
//int __thiscall ub_4C0D32(void *_this, float a2, int a3, int a4);
int Vis_sub_4C0D32_DoSomeOtherPicking_Indoor(struct Vis *_this, float a2, class25 *a3, struct unnamed_F93E6C *a4);
//int __thiscall sub_4C0DEA(void *_this, float a2, int a3, int a4);
void Vis_sub_4C0DEA_DoSomeOtherPicking_Outdoor(struct Vis *_this, float a2, class25 *a3, struct unnamed_F93E6C *a4);
//void __thiscall sub_4C1542(void *_this, float a2, float a3, float a4, int a5, int a6);
void Vis_sub_4C1542(struct Vis *_this, float fDepth, float fX, float fY, struct class25 *pClass25, struct unnamed_F93E6C *a6);
//int __thiscall sub_4C1026(void *_this, int a2, int a3, float a4);
int Vis_sub_4C1026(struct Vis *_this, struct12 *a2, int a3, float a4);
//char __thiscall sub_4C1ABA(void *_this, int a2, int a3, int a4);
bool Vis_sort_some_objects(struct Vis *_this, struct Vis_stru0 *pArray, int sLeft, int sRight);
//int __thiscall sub_4C1495(void *_this, const void *Src, int a3, int a4, int a5);
void Vis_sub_4C1495(struct Vis *_this, struct Vis_stru0 *Src, int a3, float *a4, float *a5);
//char __thiscall sub_4C288E(void *_this, int a2, int a3, int a4);
bool Vis_sort_some_objects_2(struct Vis *_this, struct Vis_stru0 *pArray, int sLeft, int sRight);
//char __thiscall sub_4C297E(void *_this, int a2, int a3, int a4);
bool Vis_sort_some_objects_3(struct Vis *_this, struct Vis_stru0 *pArray, int sLeft, int sRight);

int Vis_sub_4C16B4_DoPicking_Indoor(Vis *_this, float fPickingDepth, Vis_stru0 *a3, class25 *a4, struct unnamed_F93E6C *a5);
char Vis_sub_4C17CF_DoPicking_Outdoor(Vis *_this, float fPickingDepth, Vis_stru0 *a3, class25 *a4, struct unnamed_F93E6C *a5, bool a6);

struct class25_stru0 *Vis_sub_4C1944(Vis *_this, int a2, unsigned int a3, int a4, int a5, int a6);
signed int sub_4C1BAA_Vis_get_object_zbuf_val(void *_this, int a2);
signed int Vis_sub_4C1BF1_LooksLikeFindTopmostZObject(struct Vis *_this);

char Vis_sub_4C1930(Vis *_this, float a2, int a3);

char __stdcall sub_4C1C0C(Vis_stru0 *pRayOrigin, Vis_stru0 *pRayDirection, float *pDepth, struct RenderVertex *pRay_SomePoint, struct12 *a5, int a6);




char __stdcall sub_4C1EE5_IntersectBModel(int *a1, int *a2, short *a3, short *a4, Vec3<short> *a5, struct struct12 *a6);
Result::Code __stdcall sub_4C2186_IntersectBModel(int *a1, int *a2, short *a3, short *a4, Vec3<short> *a5, struct struct12 *a6, unsigned int uModelID);





void RotateVector(int sDepth, int sRotationY, int sRotationX, int sPosX, int sPosY, int sPosZ, int *pOutX, int *pOutY, int *pOutZ);