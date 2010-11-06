#pragma once

#include <stdio.h>
#include "c18.h"
#include "AIL.h"
#include "Party.h"
#include "Items.h"
#include "GUI.h"

#include "Render.h"

#pragma pack(push, 1)
//class00
struct CGame_stru0
{
 unsigned int    dword_000000;
 unsigned char  *ptr_000004;
 int             dword_000008;
 int             dword_00000C;
};

struct CGame
{
 int  dword_000000;  //pointer to pointer to destructor of the class
 int  dword_000004;
 int  dword_000008[699];
 int  dword_000704;     //num stationary lights?

 float array_000718[array_size_unknown];

                              // looks like ptr to current selected input device
 struct class03 *pClass03;    // ptr @ 000974
 unsigned int    dword_000978;
                              // looks like start of a struct or a class, sub_40E2F6 is a member of which
 struct CGame_stru0 unnamed_00097C;

 int  dword_000E08;
 int  dword_000E0C;
 int  dword_000E10;
 int  dword_000E14;
 int  dword_000E18;
 int  dword_000E1C;
 int  uSomeFlags;              //dword @ 000E20   & 0x01 == lighing on?
 int  dword_000E24;            // 0x20: bloodsplats
 float flt_000E28;
 __int64  qword_000E2C;
 //int  dword_000E30;
 int  dword_000E34;
 int  dword_000E38;
 struct class01 *class01_obj;  //dword ptr [0E3C]
 struct class02 *class02_obj;  //dword ptr [0E40]
 struct class03 *class03_obj;  //dword ptr [0E44]
 struct class04 *class04_obj;  //dword ptr [0E48]
 struct Vis     *pVis;         // dword @ 000E4C
 struct class06 *class06_obj;  //dword ptr [0E50]
 struct class08 *class08_obj;  //dword ptr [0E54]
 struct class09 *class09_obj;  //dword ptr [0E58]
 struct class10 *class10_obj;  //dword ptr [0E5C]
 struct class11 *class11_obj;  //dword ptr [0E60]
 struct class12 *class12_obj;  //dword ptr [0E64]
 struct class13 *class13_obj;  //dword ptr [0E68]
 struct class14 *class14_obj;  //dword ptr [0E6Ñ]
 struct CGammaController *pGammaController;  // dword @ 000E70
 int  dword_000E74;
};
//sizeof = 0E78
//int __thiscall sub_44E4B7(int _this);
void CGame_ctor(struct CGame *_this);
//int __thiscall sub_44F0FD(int _this);
int CGame_fn0(struct CGame *_this);
//int __thiscall sub_44F0D8(int _this, int a2);
int CGame_fn1(struct CGame *_this, int flags);
//char __thiscall Game_InitializeGammaController(int _this);
bool Game_InitializeGammaController(struct CGame *_this);
//char __thiscall sub_44EEA7(int _this);
char CGame_sub_44EEA7(struct CGame *_this);
//char __thiscall sub_44EA5E(int _this, float a2, signed int a3, signed int a4, char a5, int a6, int a7);
bool Game_Pick(struct CGame *_this, float a2, unsigned int uMouseX, unsigned int uMouseY, bool bOutline, int a6, int a7);
//char __thiscall sub_44F07B(int _this);
bool CGame_sub_44F07B(struct CGame *_this);
//void __thiscall sub_44F120(int _this, int a2);
void CGame_sub_44F120_MaybeStackStationaryLights(struct CGame *_this, int a2);
//void __fastcall sub_44F192(int a1);
void CGame_sub_44F192(struct CGame *_this);
//void __thiscall sub_44E904(void *_this);
void sub_44E904(struct CGame *_this);
//signed int __thiscall sub_44ED0A(int _this, int a2, int a3, signed int a4);
signed int __thiscall Game_sub_44ED0A(CGame *_this, struct struct8 *a2, int *a3, signed int a4);
//signed int __thiscall sub_44EC23(int _this, int a2, int a3, signed int a4);
signed int Game_sub_44EC23(struct CGame *_this, struct struct8 *a2, int *a3, signed int a4);
//void __thiscall sub_40E2F6(int _this, char a2);
void CGame_stru0_sub_40E2F6(struct CGame_stru0 *_this, char a2);
//char __thiscall sub_44EE30(int _this, int a2, void **a3);
bool Game_sub_44EE30(struct CGame *_this, struct class51_stru2 *a2, void **a3);
//char __thiscall sub_44EB12(int _this, char a2, int a3, int a4);
bool Game_sub_44EB12(struct CGame *_this, bool bOutline, int a3, int a4);

int CGame_scalar_deleting_destructor(struct CGame *_this, char flag);
int CGame_dtor(struct CGame *_this);


//class01
struct class01
{
 int              dword_000000;
 CRITICAL_SECTION cs1;           //struct @ 000004
 CRITICAL_SECTION cs2;           //struct @ 00001C
 CRITICAL_SECTION cs3;           //struct @ 000034
 CRITICAL_SECTION cs4;           //struct @ 00004C
};
//sizeof = 64
//int __thiscall sub_438B0B(int _this);
void *class01_ctor(struct class01 *_this);



//class03
struct class03
{
 int dword_000000; // when in Game, mouse over player portrait, highlighted player id is placed here
 int dword_000004;
 int dword_000008;
 int dword_00000C;
 int dword_000010;
 int dword_000014[4];
 int dword_000024;
 int dword_000028;
 HWND hWnd; // ptr @ 00002C
 unsigned char *ptr_000030;
 int dword_000034;
 unsigned char *ptr_000038;
 int dword_00003C;
 int dword_000040;
 int dword_000044;
 int dword_000048;
 int dword_00004C;
 int dword_000050[16];
 unsigned char *ptr_000090;
 int dword_000094;
 int dword_000098;
 int dword_00009C;
 int dword_0000A0;
 int dword_0000A4;
 int dword_0000A8;
 int dword_0000AC;
 int dword_0000B0;
 int dword_0000B4;
 int dword_0000B8;
 int dword_0000BC;
 int dword_0000C0;
 int dword_0000C4;
 int dword_0000C8;

 int dword_0000CC[16];

 unsigned char   array_0000F5[11];

 unsigned int    uMouseClickX;
 unsigned int    uMouseClickY;
 struct class01 *class01_obj;   // dword @ 000110
};
//sizeof = 0114
//int __thiscall sub_467E4E(int _this, int a2);
struct class03 *class03_ctor(struct class03 *_this, struct class01 *class01_obj);
//int __thiscall sub_46A080(int _this, int a2);
int class03_fn1(struct class03 *_this, int a2);
//int __thiscall sub_469C39(int _this, int a2);
POINT *class03_GetMousePos(struct class03 *_this, POINT *ptOut);
//void __thiscall sub_469C65(int _this, int a2)
void sub_469C65(struct class03 *_this, HWND hWnd);
//void __thiscall sub_469903(int _this, const char *Source);
void sub_469903(struct class03 *_this, const char *pSource);
//int __thiscall sub_469BA3(int _this);
int sub_469BA3(struct class03 *_this);
//void __thiscall sub_4698A6(void *_this)
void class03_sub_4698A6(struct class03 *_this);
//void sub_46A08A(int _this, int a2, int a3)
void class03_OnMouseLeftButton(struct class03 *_this, int x, int y);
//int __thiscall sub_469860(int _this, int a2, int a3);
void class03_GetMouseClickPos(struct class03 *_this, int *pX, int *pY);
//int __thiscall ckass03_sub_469E3B(int _this)
int ckass03_sub_469E3B(struct class03 *_this);



struct class04_stru0
{
 char *ptr_000000;
 int   dword_000004;
 char  unk_000008[16];
 float unk_000018[64][12]; //some struct of 40 bytes width array[64], where it start is unknown
 int   dword_000C18;
};
//sizeof == C1C
//int __fastcall sub_45DF13(char *_this)
void __fastcall class04_stru0_ctor(struct class04_stru0 *_this);
//void __fastcall sub_45DF48(void *_this)
void __fastcall class04_stru0_detor(struct class04_stru0 *_this);
//int __fastcall sub_40E4C2(int a1);
void sub_40E4C2(struct class04_stru0 *_this);

//class04
struct class04
{
 int dword_000000;
 struct class04_stru0 std__vector_000004[512]; // struct[512] @ 000004
 unsigned int         std__vector_000004_size; // dword       @ 183804
 struct class04_stru0 std__vector_183808[768]; // struct[768] @ 183808
 unsigned int         std__vector_183808_size; // dword       @ 3C8C08
 int                  dword_3CBC34;
};
//sizeof = 3CBC38
//void *__thiscall sub_45BB06(void *_this);
void class04_ctor(struct class04 *_this);
//char __thiscall sub_45D698(int _this, char a2);
bool class04_sub_45D698(struct class04 *_this, char a2);


struct class25_stru0
{
 unsigned int uBillboardID; // dword @ 000000
 int dword_000004; // RenderBillboard::000010, zbuf_val returned by sub_4C1BAA_Vis_get_object_zbuf_val
 int dword_000008; // object type for sub_4C1BAA_Vis_get_object_zbuf_val
};
//sizeof = 0C

//class25
struct class25
{
 void                 (*detor_ptr)(struct class25 *, unsigned int); // dword @ 000000
 struct class25_stru0  array_000004[512];
 struct class25_stru0 *array_001804[512];
 int                   dword_002004;
};
//sizeof = 2008
void class25_detor(struct class25 *_this , unsigned int a2);
//__int64 __thiscall sub_4C055C(void *_this);
__int64 class25_fn0(struct class25 *_this);
//void *__thiscall sub_4C2591(int _this, int a2);
void class25_create_object_pointers(struct class25 *_this, int a2);
//void sub_4C264A(int a2, int a3, int a4);
/*private*/ void class25_sort_object_pointers(struct class25_stru0 **pPointers, int sLeft, int sRight);



struct Vis_stru0
{
 float flt_000000;
 float flt_000004;
 float flt_000008;
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
 void              (*detor_ptr)(struct Vis *, unsigned int); // dword  @ 000000
 struct class25     class25_obj;                             // struct @ 000004
 struct Vis_stru0   struct_00200C;
 struct Vis_stru0   struct_00203C;
 struct Vis_stru0   struct_00206C;
 struct Vis_stru0   struct_00209C;
 int                dword_0020CC;
};
//sizeof = 0020D0
//int __thiscall sub_4C04AF(int _this);
void Vis_ctor(struct Vis *_this);
void Vis_detor(struct Vis *_this, unsigned int a2);
//int __thiscall sub_4C1A02(int _this);
void Vis_sub_4C1A02(struct Vis *_this);
//char __thiscall sub_4C0646(int _this, float a2, float a3, float a4, int a5, int a6);
bool Vis_sub_4C0646(struct Vis *_this, float a2, float fMouseX, float fMouseY, int a5, int a6);
//char __thiscall sub_4C05CC(int _this, int a2, int a3, int a4);
bool Vis_sub_4C05CC(struct Vis *_this, struct class25 *a2, int a3, int a4);
//void __thiscall sub_4C06F8(void *_this, float a2, int a3, int a4);
void Vis_sub_4C06F8(struct Vis *_this, float a2, struct class25 *a3, struct unnamed_F93E6C *a4);
//char __stdcall sub_4C0791(int a1, int a2);
bool Vis_is_part_of_selection(unsigned int uD3DBillboardID, struct unnamed_F93E6C *a2);
//char __thiscall sub_4C091D(void *_this, float a2, int a3);
bool Vis_sub_4C091D(struct Vis *_this, float a2, int a3);
//int __thiscall ub_4C0D32(void *_this, float a2, int a3, int a4);
int Vis_sub_4C0D32(struct Vis *_this, float a2, int a3, int a4);
//int __thiscall sub_4C0DEA(void *_this, float a2, int a3, int a4);
void Vis_sub_4C0DEA(struct Vis *_this, float a2, int a3, int a4);
//void __thiscall sub_4C1542(void *_this, float a2, float a3, float a4, int a5, int a6);
void Vis_sub_4C1542(struct Vis *_this, float a2, float fX, float fY, struct class25 *pClass25, int a6);
//int __thiscall sub_4C1026(void *_this, int a2, int a3, float a4);
int Vis_sub_4C1026(struct Vis *_this, int a2, int a3, float a4);
//char __thiscall sub_4C1ABA(void *_this, int a2, int a3, int a4);
bool Vis_sort_some_objects(struct Vis *_this, struct Vis_stru0 *pArray, int sLeft, int sRight);
//int __thiscall sub_4C1495(void *_this, const void *Src, int a3, int a4, int a5);
void Vis_sub_4C1495(struct Vis *_this, struct Vis_stru0 *Src, int a3, float *a4, float *a5);
//char __thiscall sub_4C288E(void *_this, int a2, int a3, int a4);
bool Vis_sort_some_objects_2(struct Vis *_this, struct Vis_stru0 *pArray, int sLeft, int sRight);
//char __thiscall sub_4C297E(void *_this, int a2, int a3, int a4);
bool Vis_sort_some_objects_3(struct Vis *_this, struct Vis_stru0 *pArray, int sLeft, int sRight);
//int __thiscall sub_4C1417(void *_this, const void *Src, int a3, int a4, int a5);
void Vis_ProbablyGetD3DBillboardCenter(struct Vis *_this, struct RenderVertexD3D3 *Src, unsigned int uNumVertices, float *fCenterX, float *fCenterY);
//char __thiscall sub_4C26D0(void *_this, int a2, int a3, int a4);
/*template*/ bool Vis_Sort_template_D3DXVECTOR_x(struct Vis *_this, struct RenderVertexD3D3 *pVertices, int sLeft, int sRight);
//char __thiscall sub_4C27AD(void *_this, int a2, int a3, int a4);
/*template*/ bool Vis_Sort_template_D3DXVECTOR_y(struct Vis *_this, struct RenderVertexD3D3 *pVertices, int sLeft, int sRight);


struct class06_stru0
{
 short word_000000;
 short word_000002;
 int   dword_000004;
 int   dword_000008;
 int   dword_00000C;
};
//sizeof == 10

//class06
struct class06
{
 int    dword_000000[129];
 int    dword_000204;

 struct class06_stru0 array_000208[4];
 int    unk_000248[224];
 int    dword_0005C8;
 struct class07 *class07_obj;  // dword @ 0005CC
 int    dword_0005D0;
 int    dword_0005D4;
 int    dword_0005D8;
 int    dword_0005DC;
 int    dword_0005E0;
 int    dword_0005E4;
 int    dword_0005E8;
 int    dword_0005EC;
 int    dword_0005F0;
 int    dword_0005F4;
};
//sizeof = 5F8
//int __thiscall sub_4A7155(int _this);
void *class06_ctor(struct class06 *_this);
//char __thiscall sub_4A81CA(int _this, int a2);
bool class06_sub_4A81CA(struct class06 *_this, int a2);
//int __thiscall sub_4A8C27(int _this);
int class06_sub_4A8C27(struct class06 *_this);
//int __thiscall sub_4A7298(void *_this);
int class06_sub_4A7298(struct class06 *_this);
//void __thiscall sub_4A902A(void *_this);
void class06_sub_4A902A_DrawSomeIcon(struct class06 *_this);



//class07
struct class07
{
 int    uNumVec4InArray1; // dword @ 000000
 float *pFloatArray1;     // dword @ 000004
 int    uNumVec3InArray2; // dword @ 000008
 float *pFloatArray2;     // dword @ 00000C
 int    dword_000010;
 int    dword_000014[80];
};
//sizeof = 154
//int __thiscall sub_4775B1(int _this);
void *class07_ctor(struct class07 *_this);
//int __thiscall sub_478211(int _this, int a2);
void *class07_InitializeVectors(struct class07 *_this, float w);


//class26; 3d vector of some kind
struct class26
{
 void  (*detor_ptr)(struct class26 *, unsigned int); // dword @ 000000
 float   array_000004[3];
};
//sizeof = 16
//void *__thiscall sub_4C0376(void *_this)
void class26_ctor(struct class26 *_this);
//void __thiscall sub_4C039C(void *_this);
void class26_default_ctor(struct class26 *_this);
void class26_detor(struct class26 *_this, unsigned int a2);
//custom
float class26_DotProduct(struct class26 *v1, struct class26 *v2);

struct class26_placeholder
{
 void (__fastcall *detor_ptr)(struct class26_placeholder *, unsigned int); // dword @ 000000
 struct class26    objClass26;  // struct @ 000004
 float             flt_000014;  // float  @ 000014   looks like dot product with some other vec
};
//sizeof == 18
//void __fastcall sub_498038(char *_this)
void __fastcall class26_placeholder_ctor(struct class26_placeholder *_this);
//void __fastcall sub_498069(void *_this)
void __fastcall class26_placeholder_default_ctor(struct class26_placeholder *_this);
void __fastcall class26_placeholder_detor(struct class26_placeholder *_this, unsigned int a2);
//void __thiscall sub_498069(int _this)
void sub_498069(struct class26_placeholder *_this);



//class08
struct class08
{
 void                     (*detor_ptr)(struct class08 *, unsigned int); // dword @ 000000
 struct class26             class26_obj1;          // struct @ 000004   these 3 are a (world?) matrix
 struct class26             class26_obj2;          // struct @ 000014
 struct class26             class26_obj3;          // struct @ 000024
 struct class26_placeholder std__vector_000034[6]; // std::vector<class26_placeholder> @ 000034
 float flt_0000C4;
 float flt_0000C8;
 float flt_0000CC;
 float flt_0000D0;
 float flt_0000D4;
 float flt_0000D8;
 float flt_0000DC;
 float flt_0000E0;
 float flt_0000E4;
 int   dword_0000E8[8];
 float flt_000108;

 float flt_00010C;
 float flt_000110;
 float flt_000114;
 int   dword_000118[8];
 float flt_000138;

 int   dword_00013C[11];
 float flt_000168;

 int   dword_00016C[11];
 float flt_000198;

 int   dword_00019C[11];
 float flt_0001C8;

 int   dword_0001CC[11];
 float flt_0001F8;

 int   dword_0001FC[11];
 float flt_000228;

 int   dword_00022C[11];
 float flt_000258;

 int   dword_00025C[11];
 float flt_000288;

 int   dword_00028C[11];
 float flt_0002B8;
 float flt_0002BC;
 float flt_0002C0;
 float flt_0002C4;

 int   dword_0002C8[8];
 float flt_0002E8;
 float flt_0002EC;
 float flt_0002F0;
 float flt_0002F4;

 int   dword_0002F8[8];
 float flt_000318;
 float flt_00031C;
 float flt_000320;
 float flt_000324;

 int   dword_000328[8];
 float flt_000348;
 float flt_00034C;
 float flt_000350;
 float flt_000354;

 int   dword_000358[8];
 float flt_000378;

 float array_00037C[16384][14];   //dword/float mixed array (see MM7.exe::004361EF)
 int   dword_0E037C;

 int   array_0E0380[256][772];
 int   dword_1A1380;
};
//sizeof = 1A1384
//int __thiscall sub_4361EF(int _this);
struct class08 *class08_ctor(struct class08 *_this);
void class08_detor(struct class08 *_this, unsigned int a2);
//int __thiscall sub_4376E7(void *_this);
void class08_CreateWorldMatrixAndSomeStuff(struct class08 *_this);
//void __thiscall sub_4374E8(void *_this);
void class08_PrepareSomeVectors(struct class08 *_this);
//void __thiscall sub_437607(void *_this, int a2, int a3);
void class08_sub_437607(struct class08 *_this, struct class26 *a2, struct class26_placeholder *a3);
//int __thiscall sub_437691(int _this, int a2, int a3);
void class08_Vec3Transform(struct class08 *_this, struct class26 *pVec, struct class26 *pOut);
//void __thiscall sub_436BB7(void *_this, int a2, int a3, char a4);
void class08_sub_436BB7(struct class08 *_this, struct RenderVertex *a2, int a3, char a4);
//void __thiscall sub_438240(int _this);
void class08_sub_438240(struct class08 *_this);
//void __fastcall sub_438141(int a1);
void class08_sub_438141(struct class08 *_this);
//void __thiscall class08_sub_438250(int _this);
void class08_sub_438250(struct class08 *_this);



//class09
struct class09
{
 int dword_000000;
};
//sizeof = 4
//int __thiscall sub_498093(int _this);
struct class09 *class09_ctor(struct class09 *_this);



//class10
struct class10
{
 int dword_000000;
 int dword_000004;
};
//sizeof = 8
//int __thiscall sub_49C5B0(int _this);
struct class10 *class10_ctor(struct class10 *_this);



//class11
struct class11
{
 int dword_000000;
 int dword_000004[7];
 int dword_000020;
 int dword_000024;
 int dword_000028;

 int dword_00002C[3];
 int dword_000038;
 int dword_00003C;

 int dword_000040[8];
 int dword_000060;
 int dword_000064;
 int dword_000068;

 int dword_00006C[12];
 int dword_00009C;
 int dword_0000A0;
 int dword_0000A4;
 int dword_0000A8;
 int dword_0000AC;
 int dword_0000B0;
 int dword_0000B4;
 int dword_0000B8[12];
};
//sizeof = 00E8
//int __thiscall sub_438526(int _this, int a2);
struct class11 *class11_ctor(struct class11 *_this, int a2);
//int __userpurge sub_4385B5(void *_this, int a2);
void *class11_fn0(struct class11 *_this, int a2);
//int __usercall sub_438659<eax>(int a1<ecx>, int a2<ebx>);
void *class11_fn1(struct class11 *_this, int a2);



//class12
struct class12
{
 int (*pMemberFn)(struct class_unk *_this);   //dword ptr [0000]
 int dword_000004[16];
 int dword_000044;
 int dword_000048;
 int dword_00004C;
 int dword_000050;
 int dword_000054;
 int dword_000058;
 struct class16 *class16_objs[12];    //array ptr [005C]
 int dword_00008C;
};
//sizeof = 0090
//int __thiscall sub_4895B7(int _this, int a2);
struct class12 *class12_ctor(struct class12 *_this, struct class11 *class11_obj);



//class13
struct class13
{
 int dword_000000;
};
//sizeof = 0004
//int __thiscall sub_4A9507(int _this);
struct class13 *class13_ctor(struct class13 *_this);



//class14
struct class14
{
 int dword_000000;
 int dword_000004;
};
//sizeof = 0008
//int __thiscall sub_45AFD9(int _this);
struct class14 *class14_ctor(struct class14 *_this);
//char __thiscall sub_45B0A9(int _this, int vKey);
bool class14_IsKeyHeld(struct class14 *_this, int vKey);
//char __thiscall sub_45B0CE(int _this, int vKey);
bool class14_IsKeyPressed(struct class14 *_this, int vKey);



//class16
struct class16
{
 void *pAlignedMem;
 void *pMemBlock;
};
//sizeof = 0008
//void *__thiscall sub_48958E(void *_this, int a2);
struct class16 *class16_ctor(struct class16 *_this, unsigned int uBlockSize);




struct SomeSpriteData
{
 int            dword_000000;
 unsigned char *ptr_000004;
};


 



struct HardwareSprite
{
 unsigned char *pSpriteName; // dword @ 000000
 int dword_000004;
 struct IDirectDrawSurface4 *pTextureSurface; // dword @ 000008
 struct IDirect3DTexture2   *pTexture;        // dword @ 00000C
 int dword_000010;
 int dword_000014;
 int dword_000018;
 int dword_00001C;
 int dword_000020;
 int dword_000024;
};
//sizeof ==  28



//class22
struct class22
{
 int dword_000000;
 int dword_000004;
 int dword_000008;
 int dword_00000C;
 int dword_000010;
 int dword_000014;
 int dword_000018;
 int dword_00001C;
 int dword_000020;
 int dword_000024;
 int dword_000028;
 int dword_00002C;
 int dword_000030;
 int dword_000034;
};
//sizeof ~ 56





//clock.bin
//class24
struct class24
{
 int dword_000000;
 int dword_000004;
 int dword_000008;
 int dword_00000C;
 int dword_000010;
 int dword_000014;
 int dword_000018;
 int int_00001C;
 int dword_000020;
 int dword_000024;
};
//sizeof ~ 28
//void __thiscall sub_426402(int _this);
void class24_ctor(struct class24 *_this);
//void __thiscall sub_426349(int _this);
void class24_fn1(struct class24 *_this);
//__int64 __thiscall sub_426317(void *_this);
__int64 class24_fn2(struct class24 *_this);
//int __thiscall class24_sub_4263B7(int _this)
int class24_sub_4263B7(struct class24 *_this);


//class27
struct class27
{
 int    dword_000000;
 int    dword_000004;
 int    dword_000008;
 int    dword_00000C;
 char   byte_000010;
 char   byte_000011;
 char   byte_000012;
 char   byte_000013;
 unsigned char *ptr_000014;
 unsigned char *ptr_000018;
};
//sizeof = 1C



struct OldViewport
{
 unsigned int uScreenX; // dword @ 000000  screen dimensions
 unsigned int uScreenY; // dword @ 000004
 unsigned int uScreenZ; // dword @ 000008
 unsigned int uScreenW; // dword @ 00000C
 unsigned int uGameX;   // dword @ 000010  game OldViewport dimensions
 unsigned int uGameY;   // dword @ 000014
 unsigned int uGameZ;   // dword @ 000018
 unsigned int uGameW;   // dword @ 00001C
 int  dword_000020;
 int  dword_000024;
 int  dword_000028;
 int  dword_00002C;
 int  dword_000030;
};
//sizeof ~ 34
//int __thiscall sub_4C0262(int _this, int a2, int a3, int a4, int a5);
void Viewport_fn0(struct OldViewport *_this, int a2, int a3, int a4, int a5);
//int __thiscall sub_4C0312(int _this, int a2, int a3, int a4, int a5)
void Viewport_SetGameViewport(struct OldViewport *_this, unsigned int uX, unsigned int uY, unsigned int uZ, unsigned int uW);
//int __thiscall sub_4C02F8(int _this, int a2)
void Viewport_fn2(struct OldViewport *_this, int a2);






//class35
struct class35
{
 char  pBaseColors[50][256 * 3];     // array @ 000000
 short pColorPalette0[50][256 * 32]; // array @ 009600
 short pColorPalette1[50][256 * 32]; // array @ 0D1600
 short pColorPalette2[50][256 * 32]; // array @ 199600
 short pColorPalette3[50][256];      // array @ 261600
 int   array_267A00[50];
 int   dword_267AC8;
 int   dword_267ACC;
 char byte_267AD0;
 char byte_267AD1;
 char byte_267AD2;
 char byte_267AD3;
 char byte_267AD4;
 char byte_267AD5;
 char byte_267AD6;
 char byte_267AD7;

 unsigned int uNumTargetRBits; // dword @ 267AD8
 unsigned int uNumTargetGBits; // dword @ 267ADC
 unsigned int uNumTargetBBits; // dword @ 267AE0
 unsigned int uTargetRMask;    // dword @ 267AE4
 unsigned int uTargetGMask;    // dword @ 267AE8
 unsigned int uTargetBMask;    // dword @ 267AEC
};
//sizeof ~ ?
//nt __thiscall sub_48A300(void *_this)
void class35_ctor(struct class35 *_this);
//int __thiscall sub_48A8F5(int _this, int a2, int a3, int a4)
void class35_SetColorChannelInfo(struct class35 *_this, unsigned int uNumRBits, unsigned int uNumGBits, unsigned int uNumBBits);
//int __thiscall sub_48A614(int _this);
int class35_sub_48A614(struct class35 *_this);
//int __thiscall sub_489BE0(int _this, int a2);
int class35_sub_489BE0(struct class35 *_this, unsigned int idx);
//signed int __thiscall sub_48A3BC(void *_this, int a2)
int class35_sub_48A3BC_MessWithPalettes(struct class35 *_this, int a2);
//int __thiscall sub_48A8A3(int _this);
int class35_sub_48A8A3(struct class35 *_this);
//signed int __thiscall sub_48A336(void *_this);
int sub_48A336(struct class35 *_this);
//int __thiscall sub_48A8CC(int _this)
int class35_sub_48A8CC(struct class35 *_this);




struct class36_stru0
{
 float flt_000000;
 float flt_000004;
 float flt_000008;
 float flt_00000C;
 float flt_000010;
 char  unk_000014[0x14];
};
//sizeof == 28

//class36
struct class36
{
 int                  dword_000000;
 struct class36_stru0 std__vector_000004[40];  // struct[40] @ 000004
 unsigned int         std__vector_000004_size; // dword      @ 000A04
 int                  dword_000A08;
};
//sizeof ~ ?
//void *__thiscall sub_43B688(void *_this);
void class36_ctor(struct class36 *_this);
//char __thiscall sub_43B6EF(int _this, int a2, int a3, int a4, int a5, char a6, char a7, char a8);
bool class36_sub_43B6EF(struct class36 *_this, int a2, int a3, int a4, int a5, char a6, char a7, char a8);



//class37
struct class37
{
 int dword_000000;

 char vector_000FA8[337800];
};
//sizeof ~ ?
//void *__thiscall sub_43F282(void *_this);
void *class37_ctor(struct class37 *_this);




struct MapInfo
{
 const unsigned char *pLocationName;             // ptr @ 000000
 const unsigned char *pLocationFilename;         // ptr @ 000004
 const unsigned char *pEncounterMonster1Texture; // ptr @ 000008
 const unsigned char *pEncounterMonster2Texture; // ptr @ 00000C
 const unsigned char *pEncounterMonster3Texture; // ptr @ 000010
 unsigned int uNumResets;       // dword @ 000014
 unsigned int uVisitedAt;       // dword @ 000018
 unsigned int uRespawnInterval; // dword @ 00001C
 int dword_000020;
 int dword_000024;
 int dword_000028;
 char byte_00002C;
 char byte_00002D;
 char byte_00002E;
 char byte_00002F;
 char byte_000030;
 char byte_000031;
 char byte_000032;
 char byte_000033;
 char byte_000034;
 unsigned char uEncounterMonster1AtLeast; // byte @ 000035
 unsigned char uEncounterMonster1AtMost;  // byte @ 000036
 char byte_000037;
 unsigned char uEncounterMonster2AtLeast; // byte @ 000038
 unsigned char uEncounterMonster2AtMost;  // byte @ 000039
 char byte_00003A;
 unsigned char uEncounterMonster3AtLeast; // byte @ 00003B
 unsigned char uEncounterMonster3AtMost;  // byte @ 00003C
 char byte_00003D;
 char byte_00003E;
 char byte_00003F;
 unsigned char uRedbookTrackNum; // byte @ 000040
 unsigned char uEAXEnv;          // byte @ 000041
 char byte_000042;
 char byte_000043;
};
//sizeof = 44

struct CMapStats
{
 struct MapInfo pMapInfos[77]; // struct array @ 000000
 unsigned int   uNumMaps;      // dword        @ 001474
};
//sizeof ~ ?
void CMapStats_ctor(struct CMapStats *_this);
//int __thiscall sub_453F62(void *_this)
int CMapStats_Initialize(struct CMapStats *_this);
//signed int __thiscall sub_4547A3(int _this, const char *Str2);
unsigned int CMapStats_FindLocation(struct CMapStats *_this, const char *pLocationName);




struct StringSplitter
{
 unsigned int   uNumSubstrings;  // dword @ 000000
 unsigned char *pSubstrings[30]; // ptr   @ 000004
};



struct MonsterInfo
{
 const unsigned char *pName;    // ptr @ 000000
 const unsigned char *pTexture; // ptr @ 000004
 unsigned char        uLevel;   // byte @ 000008
 unsigned char        byte_000009;
 unsigned char        byte_00000A;
 unsigned char        byte_00000B;
 unsigned char        byte_00000C;
 unsigned char        byte_00000D;
 unsigned char        uCanFly;        // byte @ 00000E
 unsigned char        uMovement;      // byte @ 00000F
 unsigned char        uAIType;        // byte @ 000010
 unsigned char        byte_000011;    // byte @ 000011
 unsigned char        byte_000012;    // byte @ 000012
 unsigned char        uSpecialAttack; // byte @ 000013
 unsigned char        byte_000014;    // byte @ 000014
 unsigned char        uAttackType;    // byte @ 000015
 unsigned char        byte_000016;
 unsigned char        byte_000017;
 unsigned char        byte_000018;
 unsigned char        uMissleType;    // byte @ 000019
 unsigned char        byte_00001A;
 unsigned char        uAttack2Type;   // byte @ 00001B
 unsigned char        byte_00001C;
 unsigned char        byte_00001D;
 unsigned char        byte_00001E;
 unsigned char        uAttack2MissleType;  // byte @ 00001F
 unsigned char        uSpell1UseChance;    // byte @ 000020
 unsigned char        uSpell1Type;         // byte @ 000021
 unsigned char        uSpell2UseChance;    // byte @ 000022
 unsigned char        uSpell2Type;         // byte @ 000023
 unsigned char        uResistanceFire;     // byte @ 000024
 unsigned char        uResistanceAir;      // byte @ 000025
 unsigned char        uResistanceWater;    // byte @ 000026
 unsigned char        uResistanceEarth;    // byte @ 000027
 unsigned char        uResistanceMind;     // byte @ 000028
 unsigned char        uResistanceSpirit;   // byte @ 000029
 unsigned char        uResistanceBody;     // byte @ 00002A
 unsigned char        uResistanceLight;    // byte @ 00002B
 unsigned char        uResistanceDark;     // byte @ 00002C
 unsigned char        uResistancePhysical; // byte @ 00002D
 unsigned char        byte_00002E;
 unsigned char        byte_00002F;
 unsigned char        byte_000030;
 unsigned char        byte_000031;
 unsigned char        byte_000032;
 unsigned char        byte_000033;

 unsigned short       uID;           // word @ 000034
 unsigned short       bQuestMonster; // word @ 000036
 unsigned short       uSpell1Power;  // word @ 000038
 unsigned short       uSpell2Power;  // word @ 00003A
 unsigned short       word_00003C;
 unsigned int         uHP;           // dword @ 000040
 unsigned int         uAC;           // dword @ 000044
 unsigned int         uExp;          // dword @ 000048
 unsigned int         uSpeed;        // dword @ 00004C
 unsigned int         uRecoveryTime;  // dword @ 000050

 unsigned char        byte_000054;
 unsigned char        byte_000055;
 unsigned char        byte_000056;
 unsigned char        byte_000057;
};
//sizeof = 58

struct CMonsterStats
{
 struct MonsterInfo    pMonsterInfos[265];
 struct StringSplitter sPlacements;           // struct @ 005B18
 unsigned int          uNumMonsters;          // dword  @ 005B94
 unsigned int          uNumMonsterPlacements; // dword  @ 005B98
};
//sizeof ~ ?
void CMonsterStats_ctor(struct CMonsterStats *_this);
//int __thiscall sub_45501E(void *_this);
int CMonsterStats_Initialize(struct CMonsterStats *_this);
//char *__thiscall sub_454F4E(void *_this)
char *CMonsterStats_LoadMonsterPlacements(struct CMonsterStats *_this);





struct SpellInfo
{
 unsigned char *pSpellName;                 // ptr   @ 000000
 unsigned char *pSpellNameShort;            // ptr   @ 000004
 unsigned char *pSpellDescription;          // ptr   @ 000008
 unsigned char *pSpellBasicSkillDesc;       // ptr   @ 00000Ñ
 unsigned char *pSpellExpertSkillDesc;      // ptr   @ 000010
 unsigned char *pSpellMasterSkillDesc;      // ptr   @ 000014
 unsigned char *pSpellGrandmasterSkillDesc; // ptr   @ 000018
 unsigned int   uSpellSchool;               // dword @ 00001C
 int            dword_000020;
};
//sizeof = 24


struct CSpellStats
{
 struct SpellInfo pSpellInfos[99]; // struct @ 000000
};
//sizeof ~ ?
void CSpellStats_ctor(struct CSpellStats *_this);
//char *__thiscall sub_45384A(void *_this)
char *CSpellStats_Initialize(struct CSpellStats *_this);





//hostile.txt
struct class48
{
 //char byte_000000[8];
 //char unknown[1024];
 char array_000000[4*array_size_unknown][89];
};
//sizeof ~ ?
void class48_ctor(struct class48 *_this);
//int __thiscall sub_4547E4(void *_this);
int class48_Initialize(struct class48 *_this);



struct StorylineText
{
 int dword_000000;
 char unknown[1024];
};
//int __thiscall sub_453E6D(void *_this)
int StorylineText_Initialize(struct StorylineText *_this);






struct LevelDecoration
{
 unsigned short uDecorationDescriptionID; // word  @ 000000
 short          word_000002;
 int            sPosX;                    // dword @ 000004
 int            sPosY;                    // dword @ 000008
 int            sPosZ;                    // dword @ 00000C
 int            dword_000010;
 short          word_000014;
 short          word_000016; // event associated with interaction/triggering
 short          word_000018;
 short          word_00001A;
 short          word_00001C;
 short          word_00001E;
};
//sizeof = 20


struct struct3
{
 short          word_000000;
 short          word_000002;
 struct ItemGen array_000004[array_size_unknown];
 char           byte_000028[5320 - array_size_unknown * sizeof(struct ItemGen)];
};
//sizeof == 14CC

struct struct4
{
 char byte_000000[200];
 //char byte_00004A;
 //char byte_00004B;
};
//sizeof == C8

struct struct5
{
 char  byte_000000[6];
 short word_000006;
 short word_000008;
 short word_00000A;
 short word_00000C;
 char  byte_00000E[10];
};
//sizeof == 18
//void __thiscall sub_440F07(int _this);
void sub_440F07(struct struct5 *pArray);


struct struct8
{
 float                  flt_000000;
 float                  flt_000004;
 float                  flt_000008;
 float                  flt_00000C;
 float                  flt_000010;
 unsigned int           uNumVertices; // dword @ 000014
 int                    dword_000018;
 int                    dword_00001C;
 int                    dword_000020;
 int                    dword_000024;
 int                    dword_000028;
 int                    dword_00002C;
 short                  word_000030;  // word_000018 in struct TileDesc  0x4000 flag -> TextureFrameTable unsupported  0x0002 -> water tile
 short                  word_000032;
 int                    dword_000034;
 struct class57        *ptr_000038;
 cTexture              *ptr_00003C;
 struct Span           *ptr_000040; // head  ?
 struct Span           *ptr_000044;  // and tail ?
 int                  **ptr_000048;
 short                  uTextureID; // word @ 00004C    word_000012 in struct TileDesc, texture id in bitmaps.lod
 short                  word_00004E;
 short                  word_000050;
 short                  word_000052;
 struct class51_stru2  *ptr_000054;
 char                   byte_000058;    //0..31 steps (step = ï/32) of some rotation
 char                   byte_000059;
 char                   byte_00005A;
 char                   byte_00005B;
 char                   byte_00005C;
 char                   byte_00005D;
 char                   byte_00005E;     //bmodel id
 char                   byte_00005F;     //bmodel's class51_stru2 id
 struct Edge           *array_000060[20];
 int                    dword_0000B0;        //num ptrs in 000060
 struct Edge           *array_0000B4[20];
 int                    dword_000104;        //num ptrs in 0000B4
 char                   byte_000108;
 char                   byte_000109[3];
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



//struct class55
struct OldCamera
{
 signed int   dword_000000;
 signed int   dword_000004;
 signed int   dword_000008;
 unsigned int uMapGridCellX;    // dword @ 00000C  coordinates on map grid (height and tile maps etc)
 int          uMapGridCellZ;    // dword @ 000010
 signed int   sRotationX;       // dword @ 000014    dword @ 0006C4 in Player    OldCamera euler angles
 signed int   sRotationY;       // dword @ 000018    dword @ 0006C0 in Player
 float        flt_00001C;       // related to OldViewport width ang viewing angle, perspective projection parameters
 float        flt_000020;       // inverted 00001C (65536 / [00001C])
 int          dword_000024;
 int          dword_000028;
 float        fRotationYSine;             // float @ 00002C    = sin(2ï * (sRotationY / 2048))
 float        fRotationYCosine;           // float @ 000030    = cos(2ï * (sRotationY / 2048))
 float        fRotationXSine;             // float @ 000034    = +/- sin(2ï * (sRotationX / 2048))   sign depends on condition  (byte_4D8410[572] && *(_BYTE *)(&pGame->uSomeFlags) & 0x80 || dword_6BE360 == 1)
 float        fRotationXCosine;           // float @ 000038    = +/- cos(2ï * (sRotationX / 2048))   -//-
 int          some_angle_int_sine;         // dword @ 00003C   next four guys look like obsolete since are never used;  probably used in MM6 instead
 int          some_angle_int_cosine;       // dword @ 000040   65536 * cos(sRotationY)
 int          some_other_angle_int_sine;   // dword @ 000044   65536 * sin(sRotationX)
 int          some_other_angle_int_cosine; // dword @ 000048   65536 * cos(sRotationX)
 int          dword_00004C;
};
//sizeof == 50

void OldCamera_ctor(struct OldCamera *);
//void sub_4239A7(int _this);
void OldCamera_sub_4239A7(struct OldCamera *_this);
//signed __int64 __thiscall sub_42394D(void *_this, signed int a2, signed int a3, int a4);
void OldCamera_SetPerspective(struct OldCamera *_this, signed int sViewingAngle, signed int sViewportWidth, signed int sViewportHeight);
//
void OldCamera_CalculateSinCos(struct OldCamera *_this);







struct class57
{
 int        dword_000000;
 int        dword_000004;
 int        dword_000008;
 int        dword_00000C;
 int        dword_000010;
 int        dword_000014;
 signed int dword_000018;
 signed int dword_00001C;
 signed int dword_000020;
 int        dword_000024;
 int        dword_000028;
};
//sizeof ~ 38
//int __thiscall sub_48616B(int _this, int a2, int a3, int a4, int a5, int a6, int a7);
int class57_sub_48616B(struct class57 *_this, int a2, int a3, int a4, int a5, int a6, int a7);
//int __thiscall sub_48694B(int _this);
int class57_sub_48694B(struct class57 *_this);


//game render states/settings
struct struct9
{
 int          dword_000000;
 int          shading_dist_shade;     // dword @ 000004
 int          shading_dist_shademist; // dword @ 000008
 int          shading_dist_mist;      // dword @ 00000C
 int          dword_000010;
 int          dword_000014;
 int          dword_000018;
 int          camera_rotation_y_int_sine;   // dword @ 00001C  integer sine   65536*sin(OldCamera->rot_y)
 int          camera_rotation_y_int_cosine; // dword @ 000020
 int          camera_rotation_x_int_sine;   // dword @ 000024
 int          camera_rotation_x_int_cosine; // dword @ 000028
 int          dword_00002C;
 unsigned int uNumEdges; // dword @ 000030
 unsigned int uNumSurfs; // dword @ 000034
 unsigned int uNumSpans; // dword @ 000038
 int          dword_00003C;
 int          dword_000040;
 int          dword_000044;
 int          dword_000048;
 int          dword_00004C;
 int          dword_000050;
 int          dword_000054;
 unsigned int bDoNotRenderDecorations; // dword @ 000058
};
//sizeof ~ 60
//int __thiscall struct9_sub_47A59E_ComputeSinCos(int _this);
void struct9_sub_47A59E_ComputeSinCos(struct struct9 *_this);
//int __thiscall sub_485F64(int _this);
int sub_485F64(struct struct9 *_this);




struct class58
{
 char unk_000000[0x11E458];
 char unk_11E458[0x82400];
 char unk_1A0858[0x6405];
 char unk_1A6C5D[0xF];
 char unk_1A6C6C[0x161398];
 int  dword_308004;
 int  dword_308008;
 int  std__vector_30B00C[1024]; // dword[1024] @ 30B00C   template<int>
 int  std__vector_30B00C_size;  // dword @ 30800C
};
//sizeof == ?
//int __thiscall sub_49B525(int _this, int a2);
void class58_sub_49B525(struct class58 *_this, int a2);


//math predefines
struct class59
{
 int pTanTable[520];    // int[520] @ 000000
 int pCosTable[520];    // int[520] @ 000820
 int pInvCosTable[520]; // int[520] @ 001040
 unsigned int uIntegerPi;     // dword @ 001860
 unsigned int uIntegerHalfPi; // dword @ 001864   
 unsigned int uIntegerDoublePi;// dword @ 001868
 unsigned int uDoublePiMask;  // dword @ 00186C
 unsigned int uPiMask;        // dword @ 001870
 unsigned int uHalfPiMask;    // dword @ 001874
};
//sizeof ~
//
//loc_452969()
void class59_ctor(struct class59 *);
//int __thiscall sub_402CAE(int _this, int a2);
int class59_SinCos(struct class59 *_this, int a2);
//int __thiscall sub_45281E(void *_this, int X, int a3);
int class59_Atan2(struct class59 *_this, int X, int Y);


struct Event
{
 int          dword_000000; // event type?
 int          dword_000004;
 unsigned int uEventOffsetInEVT; // dword @ 000008
};
//sizeof == 0C


struct Matrix
{
 union
 {
  float v[3][3];
  struct
  {
   float _11, _12, _13;
   float _21, _22, _23;
   float _31, _32, _33;
  };
 };
};
//int __stdcall sub_4378BA(int a1, int a2, int a3)
void MatrixMultiply(struct Matrix *pM1, struct Matrix *pM2, struct Matrix *pResult);





struct sub_485975_stru0
{
 int    dword_000000;
 int    dword_000004;
 int    dword_000008;
 int    dword_00000C;
 int    dword_000010;
 int    dword_000014;
 int    dword_000018;
 int    dword_00001C;
 int    dword_000020;
 int    dword_000024;  // depth value/zid
 int    dword_000028;  // num pixels?
 int    dword_00002C;
 int    dword_000030;
 int    dword_000034;
 int    dword_000038; // some pixels pointer too, source texture?
 unsigned int *pDepthBuffer; // dword @ 00003C
 unsigned int *pColorBuffer; // dword @ 000040
};

struct sub_485975_stru1
{
 int dword_000000;
 int dword_000004;
 int dword_000008;
 int dword_00000C;
 int dword_000010;
 int dword_000014;
 int dword_000018;
 int dword_00001C;
 int dword_000020;
 int dword_000024;
};





struct StationaryLight
{
 short         sLightPosX;       // word @ 000000
 short         sLightPosY;       // word @ 000002
 short         sLightPosZ;       // word @ 000004
 short         word_000006; // light strength?
 unsigned char uLightColorRed;   // byte @ 000008
 unsigned char uLightColorGreen; // byte @ 000009
 unsigned char uLightColorBlue;  // byte @ 00000A
 char          byte_00000B;
};
//sizeof  = 0C
//char __stdcall sub_45CE50(int _this, int a2, int *a3, char a4);
bool __stdcall StationaryLight_sub_45CE50_ProbablyApplyLightToScene(struct StationaryLight *_this, struct class51_stru2 *a2, int *a3, char a4);

struct StationaryLightsStack
{
 int                    dword_000000;
 struct StationaryLight pLights[400];               // struct[400] @ 000004
 unsigned int           uNumStationaryLightsActive; // dword       @ 0012C4
};
//siezof ~ ?
//char __thiscall sub_4AD3C8(int _this, __int16 a2, __int16 a3, __int16 a4, __int16 a5, int a6, char a7, char a8, char a9);
bool StationaryLightsStack_AddLight(struct StationaryLightsStack *_this, int sLightPosX, int sLightPosY, int sLightPosZ, __int16 a5, unsigned int uLightColorRed, unsigned char uLightColorGreen, unsigned char uLightColorBlue, char a9);





//DERIVED from StationaryLight
struct struct6//: public StationaryLight
{
 short word_000000;
 short word_000002;
 short word_000004;
 short word_000006;
 char  byte_000008;
 char  byte_000009;
 char  byte_00000A;
 char  byte_00000B;
 char  byte_00000C[6];
};
//sizeof == 12









struct unnamed_505898
{
 char byte_505898; // weak
 int dword_000004; // 50989C
 int dword_5058A0; // weak
 _UNKNOWN unk_5058A4; // weak
 char byte_5058A8; // weak
 struct tagMSG Msg_global; // idb
 int dword_5058C8; // weak
 int dword_5058CC; // weak
 char byte_5058D0; // weak
 char byte_5058D2; // weak
 int dword_5058D4; // weak
 int dword_5058D8; // weak
 int dword_5058DC; // weak
 Font *dword_5058E0; // weak
 Font *dword_5058E4; // weak
 __int16 word_5058EC; // weak
 struct RGBTexture class33_obj0; // ::5058F0
 struct RGBTexture class33_obj1; // ::505918
 int dword_505940; // weak
 int dword_505944; // weak
 int dword_505948; // weak
 cTexture Dest;
 //char Dest[32]; // idb
 char byte_50596C[32]; // cTexture ?
 char byte_50598C; // weak
 char byte_50598D; // weak
 char byte_50598E; // weak
 char byte_50598F; // weak
 char byte_505990; // weak
 char byte_505991; // 0000F9
 char byte_505992; // 0000FA
};
//sizeof ~ FB
//loc_40D707





#pragma pack(pop)