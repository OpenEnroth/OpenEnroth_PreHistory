long __cdecl std__basic_string_char_std__char_traits_char__std__allocator_char_____Copy(long);
long __stdcall std__basic_string_char_std__char_traits_char__std__allocator_char____erase(long, long);
long __stdcall _eh_vector_constructor_iterator_(long, long, long, long, long);
long __stdcall _eh_vector_destructor_iterator_(long, long, long, long);

#include <stdio.h>
#include <windows.h>

#include "AIL.h"

#pragma pack(push, 1)
//class00
struct class00
{
 int  dword_000000;
 int  dword_000004[700];
 int  dword_000704;
 int  dword_000E08;
 int  dword_000E0C;
 int  dword_000E10;
 int  dword_000E14;
 int  dword_000E18;
 int  dword_000E1C;
 int  uSomeFlags;              //dword ptr [0E20]
 int  dword_000E24;
 int  dword_000E2C;
 int  dword_000E30;
 int  dword_000E34;
 int  dword_000E38;
 struct class01 *class01_obj;  //dword ptr [0E3C]
 struct class02 *class02_obj;  //dword ptr [0E40]
 struct class03 *class03_obj;  //dword ptr [0E44]
 struct class04 *class04_obj;  //dword ptr [0E48]
 struct class05 *class05_obj;  //dword ptr [0E4C]
 struct class06 *class06_obj;  //dword ptr [0E50]
 struct class08 *class08_obj;  //dword ptr [0E54]
 struct class09 *class09_obj;  //dword ptr [0E58]
 struct class10 *class10_obj;  //dword ptr [0E5C]
 struct class11 *class11_obj;  //dword ptr [0E60]
 struct class12 *class12_obj;  //dword ptr [0E64]
 struct class13 *class13_obj;  //dword ptr [0E68]
 struct class14 *class14_obj;  //dword ptr [0E6Ñ]
 struct CGammaController *pGammaController;  //dword ptr [0E70]
 int  dword_000E74;
};
//sizeof = 0E78
//int __thiscall sub_44E4B7(int this);
void *class00_ctor(struct class00 *_this);
//int __thiscall sub_44F0FD(int this);
int class00_fn0(struct class00 *_this);
//int __thiscall sub_44F0D8(int this, int a2);
int class00_fn1(struct class00 *_this, int flags);



//class01
struct class01
{
 int              dword_000000;
 CRITICAL_SECTION cs1;           //struct ptr [04]
 CRITICAL_SECTION cs2;           //struct ptr [1C]
 CRITICAL_SECTION cs3;           //struct ptr [34]
 CRITICAL_SECTION cs4;           //struct ptr [4C]
};
//sizeof = 0064
//int __thiscall sub_438B0B(int this);
void *class01_ctor(struct class01 *_this);



//class02
struct class02
{
 int dword_000000[500][26];
 int dword_000CB20[1600];
 int dword_000E420;
 int dword_000E424;
 int dword_000E428;
 int dword_000E42C;
};
//sizeof = E430
//void *__thiscall sub_48AAC5(void *Dst);
void *class02_ctor(struct class02 *_this);
//void *__thiscall sub_48AAF6(void *Dst);
void *class02_fn0(struct class02 *_this);



//class03
struct class03
{
 int dword_000000;
 int dword_000004;
 int dword_000008[7];
 int dword_000024;
 int dword_000028;
 int dword_00002C;
 int dword_000030;
 int dword_000034;
 int dword_000038;
 int dword_00003C;
 int dword_000040[20];
 int dword_000090;
 int dword_000094[29];
 int dword_000108;
 int dword_00010C;
 struct class01 *class01_obj;   //dword ptr [0110]
};
//sizeof = 0114
//int __thiscall sub_467E4E(int this, int a2);
struct class03 *class03_ctor(struct class03 *_this, struct class01 *class01_obj);
//int __thiscall sub_46A080(int this, int a2);
int class03_fn1(struct class03 *_this, int a2);
//int __thiscall sub_469C39(int this, int a2);
int *class03_fn2(struct class03 *_this, int *a2);


//class04
struct class04
{
 int dword_000000;
 int dword_000004[3100 * 512 / 4];          //std::vector @ 000004
 int dword_183804;
 int dword_183808[3100 * 768 / 4];          //std::vector @ 183808
 int dword_3C8C08;
};
//sizeof = 3CBC38
//void *__thiscall sub_45BB06(void *this);
void *class04_ctor(struct class04 *_this);



//class25
struct class25
{
 int dword_000000;
 int dword_000004[2048];
 int dword_002004;
};
//sizeof ~ ?
//__int64 __thiscall sub_4C055C(void *this);
__int64 class25_fn0(struct class25 *_this);



//class05
struct class05
{
 int            dword_000000;
 struct class25 class25_obj;     //struct ptr [0004]
 float          flt_00200C[12];
 float          flt_00203C[12];
 float          flt_00206C[12];
 float          flt_00209C[12];
 int            dword_0020CC;
};
//sizeof = 0020D0
//int __thiscall sub_4C04AF(int this);
void *class05_ctor(struct class05 *_this);



//class06
struct class06
{
 int   dword_000000[129];
 int   dword_000204;
 short  word_000208;
 short  word_00020A[7];
 short  word_000218;
 short  word_00021A[7];
 short  word_000228;
 short  word_00022A[7];
 short  word_000238;
 short  word_00023A;
 int   dword_00023C[227];
 int   dword_0005C8;
 struct class07 *class07_obj;  //dword ptr [05CC]
 int   dword_0005D0;
 int   dword_0005D4;
 int   dword_0005D8;
 int   dword_0005DC[7];
};
//sizeof = 5F8
//int __thiscall sub_4A7155(int this);
void *class06_ctor(struct class06 *_this);



//class07
struct class07
{
 int    uNumVec4InArray1; //dword ptr [0000]
 float *pFloatArray1;     //dword ptr [0004]
 int    uNumVec3InArray2; //dword ptr [0008]
 float *pFloatArray2;     //dword ptr [000C]
 int dword_000010;
 int dword_000014[80];
};
//sizeof = 154
//int __thiscall sub_4775B1(int this);
void *class07_ctor(struct class07 *_this);
//int __thiscall sub_478211(int this, int a2);
void *class07_InitializeVectors(struct class07 *_this, float w);


//class26
struct class26
{
 int dword_000000;
 int dword_000004[3];
};
//sizeof = 16
//void *__thiscall sub_4C0376(void *this)
struct class26 *class26_ctor(struct class26 *_this);



//class08
struct class08
{
 int   dword_000000;
 struct class26 class26_obj1;  //struct ptr [0004]
 struct class26 class26_obj2;  //struct ptr [0014]
 struct class26 class26_obj3;  //struct ptr [0024]
 int   dword_000034[36];       //std::vector
 int   dword_0000C4[6];
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
//int __thiscall sub_4361EF(int this);
struct class08 *class08_ctor(struct class08 *_this);



//class09
struct class09
{
 int dword_000000;
};
//sizeof = 4
//int __thiscall sub_498093(int this);
struct class09 *class09_ctor(struct class09 *_this);



//class10
struct class10
{
 int dword_000000;
 int dword_000004;
};
//sizeof = 8
//int __thiscall sub_49C5B0(int this);
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
//int __thiscall sub_438526(int this, int a2);
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
 struct class16 **class16_objs[12];    //array ptr [005C]
 int dword_00008C;
};
//sizeof = 0090
//int __thiscall sub_4895B7(int this, int a2);
struct class12 *class12_ctor(struct class12 *_this, struct class11 *class11_obj);



//class13
struct class13
{
 int dword_000000;
};
//sizeof = 0004
//int __thiscall sub_4A9507(int this);
struct class13 *class13_ctor(struct class13 *_this);



//class14
struct class14
{
 int dword_000000;
 int dword_000004;
};
//sizeof = 0008
//int __thiscall sub_45AFD9(int this);
struct class14 *class14_ctor(struct class14 *_this);



//class16
struct class16
{
 void *pAlignedMem;
 void *pMemBlock;
};
//sizeof = 0008
//void *__thiscall sub_48958E(void *this, int a2);
struct class16 *class16_ctor(struct class16 *_this, unsigned int uBlockSize);




//class18
struct class18
{
 char  sContainerName[16];
 int   dword_000010;
 unsigned int uCompressedSize; // dword @ 000014
 short  word_000018;
 short  word_00001A;
 short  word_00001C;
 short  word_00001E;
 char   byte_000020[4];
 short  word_000024;
 short  word_000026;
 unsigned int uDecompressedSize;   // dword @ 000028
 char   byte_00002C[4];
 unsigned char *ptr_000030;
 int    dword_000034;
 int    dword_000038;
 int    dword_00003C;
 unsigned short *ptr_000040;
 unsigned char  *ptr_000044;
};
//sizeof = 000048
//int __thiscall sub_40F5BE(int this);
void *class18_ctor(struct class18 *_this);




//class17
struct class17
{
 FILE *pLODFile;               //dword ptr [0000]
 char  sLODName[32];           //dword ptr [0004]

 char   byte_000024[0x0000E0];
 int   dword_000104;
 int   dword_000108;
 int   dword_00010C;
 int   aLODHeader[64];         //array ptr [0110]
 void *dword_000210;
 char   sContainerName[12];    //string ptr [0214]
 int   dword_000220;
 int   dword_000224;
 int   dword_000228;
 int   dword_00022C;
 void *pLODIndexNamedBuffer;  //dword ptr [0230]
 int   dword_000234;
 int   dword_000238;

 struct class18 class18_array[128];  // class18[~ 1000] @ 00023C
 //char   byte_00023C[16];
 //short  array_00024C[0x7528];

 int   dword_00EC9C;
 int   dword_00ECA0;
 int   dword_00ECA4;
 int   dword_00ECA8;
 int   dword_00ECAC;
 int   dword_00ECB0;

 char byte_00ECB4[0x2EC8];

 int   dword_011B7C;
 int   dword_011B80;
 int   dword_011B84;
 int   dword_011B88;
 char  byte_011B8C[4];
 char  byte_011B90[4];
 char  byte_011B94[4];
 int   dword_011B98;
 int   dword_011B9C;
 int   dword_011BA0;
 int   dword_011BA4;
 int   dword_011BA8;
 int   dword_011BAC;
 int   dword_011BB0;
 int   dword_011BB4;
};
//sizeof = 011BB8
void class17_ctor(struct class17 *_this);
//bool __thiscall sub_40FAEE(int this, const char *Filename);
int class17_LoadLOD_Icons(struct class17 *_this, const char *pLODFilename);
//bool __thiscall sub_40FA2E(int this, const char *Filename);
int class17_LoadLOD_Bitmaps(struct class17 *_this, const char *pLODFilename);
//bool __thiscall sub_4AC795(int this, const char *Filename);
int class17_LoadLOD_Sprites(struct class17 *_this, const char *pLODFilename);
//int __thiscall sub_41088B(void *this, const char *Args, int a3);
void *class17_fn1(struct class17 *_this, const char *pLODContainer, int a3);
//int __thiscall sub_461580(int this, const char *Str1, int a3);
FILE *class17_FindContainer(struct class17 *_this, const char *pContainerName, int a3);
//int __thiscall sub_46165E(void *this, int a2, int a3, const char *Str1);
int class17_fn3(struct class17 *_this, int a2, int a3, const char *pContainerName);
//void __thiscall sub_40FA60(int this);
void class17_fn4(struct class17 *_this);
//signed int __thiscall sub_4617D5(int this, const char *Filename, char a3)
int class17_MaybeLoadLODHeader(struct class17 *_this, const char *pFilename, char a3);
//signed int __thiscall sub_46188A(int this, const char *Source);
int class17_fn6(struct class17 *_this, const char *pContainer);
//int __thiscall sub_46153F(int this);
int class17_fn7(struct class17 *_this);
//int __thiscall sub_40FB20(int this, const char *Source, unsigned int a3)
int class17_LoadTexture(struct class17 *_this, const char *pContainerName, unsigned int a3);
//signed int __thiscall sub_40FC08(int this, void *Dest, int Source, unsigned int DstBuf);
int sub_40FC08(struct class17 *_this, struct class18 *pClass18, const char *pContainerName, unsigned int DstBuf);





//class19
struct class19
{
 unsigned char *pCompressedData;               // dword ptr [00]
 unsigned int   uCompressedDataSize;           // dword ptr [04]
 int   dword_000008;            //some offset in compressed data?
 unsigned char *pDecompressedData;             // dword ptr [0C]
 unsigned int   uDecompressedDataSize;         // dword ptr [10]
 int   dword_000014; // [sp+1Ch] [bp-24h]@5
 char *pStatus;                                // dword ptr [18]
 struct class20 *class20_obj;                  // dword ptr [1C]
 void *(__stdcall *pFunction1)(int, int, int); // dword ptr [20]    operator new-like mechanism
 int (__cdecl *pFunction2)(int, int);          // dword ptr [24]    operator delete-like mechanism
 int dword_000028;
 int dword_00002C;
 int dword_000030;
};
//sizeof ~ 52
//signed int sub_4C3190(struct class19 *_this, int a2, int a3, int a4);
int class19_fn0(struct class19 *_this, int a2, const char *a3, int a4);
//signed int __thiscall sub_4C3150(int this);
int class19_fn1(struct class19 *_this);
//signed int __thiscall sub_4C3110(int this);
int class19_fn2(struct class19 *_this);
//int __fastcall sub_4C4A30(int a1, int a2, int a3);
struct class21 *class19_AllocClass21Obj(struct class19 *_this, int (__fastcall *pSomeFn)(unsigned int, int, unsigned int), int a3);
//signed int __fastcall sub_4C32D0(int a1, int a2);
int class19_fn3(struct class19 *_this, int a2);

//class20
struct class20
{
 int dword_000000;
 int dword_000004;
 int dword_000008;
 int dword_00000C;
 int dword_000010;
 struct class21 *class21_obj;
 struct class22 *class22_obj;
};
//sizeof ~ 28

//class21
struct class21
{
 int  dword_000000;
 struct class27 *class27_obj;
 int  dword_000008;
 int *dword_00000C;
 int  dword_000010;
 int  dword_000014;
 int  bDecompressionComplete;  // dword @ 000018
 int  dword_00001C;
 int  dword_000020;
 unsigned int *pArray_8x1440;  //dword ptr [0024]
 int *dword_000028;
 int  dword_00002C;
 unsigned char *pDecompressionBufferHead;  //dword ptr [0030]
 unsigned char *pDecompressionBufferTail;  //dword ptr [0034]
 int (__fastcall *pfn_000038)(unsigned int, unsigned int *, unsigned char *);
 int  dword_00003C;
};
//sizeof = 64
//int __fastcall sub_4C5790(int a1, int a2);
int class21_fn0(struct class21 *_this, struct class19 *pParent);
//int __fastcall sub_4C49C0(int a1, int a2, int a3);
int class21_fn1(struct class21 *_this, struct class19 *pParent, int *a3);
//int __fastcall sub_4C4AD0(int a1, int a2, int a3);
int class21_fn2(struct class21 *_this, struct class19 *pParent, int a3);
//int __fastcall sub_4C8370(int a1, int a2, int a3);
int class21_fn3(struct class21 *_this, struct class19 *pParent, int a3);
//int __fastcall sub_4C74A0(int a1, int a2, int a3);
int class21_fn4(struct class21 *_this, struct class19 *pParent, int a3);



//class22
struct class22  //data block or smthn
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



//class23
struct class23
{
 void         *pMemoryBuffers[6000];       //array ptr [000000]
 unsigned int  uMemoryBufferSizes[6000];   //array ptr [005DC0]
 char          aBufferNames[6000][12];     //array ptr [00BB80]
 int           dword_01D4C0;
 int           uNumMemoryBuffersUsed;      //dword ptr [01D4C4]

 void         *pBigMemoryBuffer;           //dword ptr [01D4C8]
 unsigned int  uNextFreeOffsetInBigBuffer; //dword ptr [01D4CC]
 int           uBigBufferSizeMinus1000h;   //dword ptr [01D4D0]
 int           bBigBufferAllocated;        //dword ptr [01D4D4]
 int           dword_01D4D8;
 void         *pBigBufferAlignedAt1000h;   //dword ptr [01D4DC]
};
//sizeof ~
//signed int __thiscall sub_4266CD(int this, int a2);
int class23_AllocateBigBuffer(struct class23 *_this, unsigned int uNumKBytes);
//int __thiscall sub_426474(int this, int a2);
int class23_fn1(struct class23 *_this, void *pMem);
//void *__thiscall sub_426755(void *this, int a2, signed int Size, const char *Source);
void *class23_AllocatedNamedBuffer(struct class23 *_this, int a2, int size, const char *pBufferName);
//signed int __thiscall sub_42654C(int this, int a2)
int class23_CreateFileDump(struct class23 *_this, const char *a2);



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
 int dword_00001C;
 int dword_000020;
 int dword_000024;
};
//sizeof ~ ?
//void __thiscall sub_426402(int this);
void class24_ctor(struct class24 *_this);
//void __thiscall sub_426349(int this);
void class24_fn1(struct class24 *_this);
//__int64 __thiscall sub_426317(void *this);
__int64 class24_fn2(struct class24 *_this);


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



//class28       a viewport or smthn
struct class28
{
 int  dword_000000;
 int  dword_000004;
 int  dword_000008;
 int  dword_00000C;
 int  dword_000010;
 int  dword_000014;
 int  dword_000018;
 int  dword_00001C;
 int  dword_000020;
 int  dword_000024;
 int  dword_000028;
 int  dword_00002C;
 int  dword_000030;
};
//sizeof ~ ?
//int __thiscall sub_4C0262(int this, int a2, int a3, int a4, int a5);
int class28_fn0(struct class28 *_this, int a2, int a3, int a4, int a5);
//int __thiscall sub_4C0312(int this, int a2, int a3, int a4, int a5)
int class28_fn1(struct class28 *_this, int a2, int a3, int a4, int a5);
//int __thiscall sub_4C02F8(int this, int a2)
int class28_fn2(struct class28 *_this, int a2);


//class29
struct CSpriteFrameTable
{
 int             dword_000000;
 int             dword_000004;
 int             dword_000008;
 unsigned char  *ptr_00000C;
 unsigned int   *ptr_000010;
 unsigned short *ptr_000014;
};
//sizeof ~ ?
void CSpriteFrameTable_ctor(struct CSpriteFrameTable *_this);
//int __thiscall sub_44D9D7(void *Dst, void *Src)
int CSpriteFrameTable_LoadFromDSFT(struct CSpriteFrameTable *_this, void *pSrc);
//int __thiscall sub_44D96D(void *Str);
int CSpriteFrameTable_Save_DSFT_bin(struct CSpriteFrameTable *_this);

int CSpriteFrameTable_LoadFromTXT(struct CSpriteFrameTable *_this, const char *pSourceFile);
//int __thiscall sub_44D4D8(int this)
int CSpriteFrameTable_sub_44D4D8(struct CSpriteFrameTable *_this);



//class34
struct IconFrame
{
 unsigned char sIconName[12];   // byte[12] @ 000000
 unsigned char sTextureName[12];   // byte[12] @ 00000C
 short         word_000018;
 short         word_00001A;
 short         word_00001C;
 short         uTextureIdx;     // word @ 00001E
};
//sizeof = 20

struct CIconFrameTable
{
 unsigned int      uNumIcons;  // dword @ 000000
 struct IconFrame *pIcons;     // ptr   @ 000004
};
//sizeof ~ ?
void CIconFrameTable_ctor(struct CIconFrameTable *_this);
//void *__thiscall sub_495056(void *Dst, void *Src);
void *CIconFrameTable_Initialize(struct CIconFrameTable *_this, void *pSrc);
//int __thiscall sub_494F3A(void *this, const char *Str1);
unsigned int CIconFrameTable_FindIcon(struct CIconFrameTable *_this, const char *pIconName);
//void __thiscall sub_494FBF(int this, int a2);
void CIconFrameTable_InitializeIcon(struct CIconFrameTable *_this, unsigned int uIconIdx);







//class33
struct class33
{
 int dword_000000;
 int dword_000004;
 int dword_000008;
 int dword_00000C;
 unsigned int uNumPixels; // dword @ 000010
 short uWidth;  // word @ 000014
 short uHeight;  // word @ 000016
 short word_000018;
 short word_00001A;
 short word_00001C;
 short word_00001E;
 int dword_000020;
 unsigned short *pPixels; // ptr @ 000024
};
//sizeof = 28
//signed int __thiscall sub_40F414(void *this, const char *Str1, int a3);
int class33_fn0(struct class33 *_this, const char *pContainerName, int a3);
//signed int __thiscall sub_40F037(void *this, void *Src, int a3, int a4)
int class33_DecodePCX(struct class33 *_this, void *Src, void *a3, unsigned int uWidth);

#pragma pack(pop)