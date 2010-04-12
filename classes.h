long __cdecl std__basic_string_char_std__char_traits_char__std__allocator_char_____Copy(long);
long __stdcall std__basic_string_char_std__char_traits_char__std__allocator_char____erase(long, long);
long __stdcall _eh_vector_constructor_iterator_(long, long, long, long, long);
long __stdcall _eh_vector_destructor_iterator_(long, long, long, long);

#include <stdio.h>
#include <windows.h>

#include "AIL.h"
#include "defs.h"

#pragma pack(push, 1)
//class00
struct CGame
{
 int  dword_000000;
 int  dword_000004;
 int  dword_000008[699];
 int  dword_000704;
 int  dword_000E08;
 int  dword_000E0C;
 int  dword_000E10;
 int  dword_000E14;
 int  dword_000E18;
 int  dword_000E1C;
 int  uSomeFlags;              //dword ptr [0E20]
 int  dword_000E24;
 __int64  qword_000E2C;
 //int  dword_000E30;
 int  dword_000E34;
 int  dword_000E38;
 struct class01 *class01_obj;  //dword ptr [0E3C]
 struct class02 *class02_obj;  //dword ptr [0E40]
 struct class03 *class03_obj;  //dword ptr [0E44]
 struct class04 *class04_obj;  //dword ptr [0E48]
 struct class05 *class05_obj;  //dword ptr [0E4C] 'Vis' object
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
void CGame_ctor(struct CGame *_this);
//int __thiscall sub_44F0FD(int this);
int CGame_fn0(struct CGame *_this);
//int __thiscall sub_44F0D8(int this, int a2);
int CGame_fn1(struct CGame *_this, int flags);
//char __thiscall sub_44EA17(int this);
char sub_44EA17(struct CGame *_this);
//char __thiscall sub_44EEA7(int this);
char CGame_sub_44EEA7(struct CGame *_this);
//char __thiscall sub_44EA5E(int this, float a2, signed int a3, signed int a4, char a5, int a6, int a7);
bool CGame_Pick(struct CGame *_this, float a2, signed int a3, signed int a4, char a5, int a6, int a7);
//char __thiscall sub_44F07B(int this);
bool CGame_sub_44F07B(struct CGame *_this);



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
//signed int __thiscall sub_48AC65(int this);
int class02_sub_48AC65(struct class02 *_this);



//class03
struct class03
{
 int dword_000000;
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
 int dword_000040[20];
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

 unsigned char array_0000F5[11];

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
POINT *class03_GetMousePos(struct class03 *_this, POINT *ptOut);
//void __thiscall sub_469C65(int this, int a2)
void sub_469C65(struct class03 *_this, HWND hWnd);
//void __thiscall sub_469903(int this, const char *Source);
void sub_469903(struct class03 *_this, const char *pSource);
//int __thiscall sub_469BA3(int this);
int sub_469BA3(struct class03 *_this);
//void __thiscall sub_4698A6(void *this)
void class03_sub_4698A6(struct class03 *_this);
//void sub_46A08A(int this, int a2, int a3)
void class03_OnMouseLeftButton(struct class03 *_this, int x, int y);
//int __thiscall sub_469860(int this, int a2, int a3);
void sub_469860(struct class03 *_this, int *a2, int *a3);
//int __thiscall sub_469E3B(int this)
int sub_469E3B(struct class03 *_this);




//class04
struct class04
{
 int dword_000000;
 int dword_000004[3100 * 512 / 4];          //std::vector @ 000004
 int dword_183804;                          //std::vector::size ?
 int dword_183808[3100 * 768 / 4];          //std::vector @ 183808
 int dword_3C8C08;                          //std::vector::size ?
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
 int   dword_0005DC;
 int   dword_0005E0;
 int   dword_0005E4;
 int   dword_0005E8;
 int   dword_0005EC;
 int   dword_0005F0;
 int   dword_0005F4;
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
 float array_000004[3];
};
//sizeof = 16
//void *__thiscall sub_4C0376(void *this)
struct class26 *class26_ctor(struct class26 *_this);
//void __thiscall sub_4C039C(void *this);
void class26_sub_4C039C(struct class26 *_this);



//class08
struct class08
{
 int   dword_000000;
 struct class26 class26_obj1;  //struct @ 000004
 struct class26 class26_obj2;  //struct @ 000014
 struct class26 class26_obj3;  //struct @ 000024
 int   std__vector_000034[36];       //std::vector
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
//int __thiscall sub_4361EF(int this);
struct class08 *class08_ctor(struct class08 *_this);
//int __thiscall sub_4376E7(void *this);
void class08_sub_4376E7(struct class08 *_this);
//void __thiscall sub_4374E8(void *this);
void class08_sub_4374E8(struct class08 *_this);
//void __thiscall sub_437607(void *this, int a2, int a3);
void class08_sub_437607(struct class08 *_this, struct class26 *a2, unsigned char *a3);
//int __thiscall sub_437691(int this, int a2, int a3);
void class08_sub_437691(struct class08 *_this, struct class26 *a2, float *a3);
//void __thiscall sub_436BB7(void *this, int a2, int a3, char a4);
void class08_sub_436BB7(struct class08 *_this, int a2, int a3, char a4);



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
//char __thiscall sub_45B0A9(int this, int vKey);
char class14_sub_45B0A9(struct class14 *_this, int vKey);
//char __thiscall sub_45B0CE(int this, int vKey);
char class14_sub_45B0CE(struct class14 *_this, int vKey);



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
 char  sContainerName[8];
 int   dword_000008;
 int   dword_00000C;
 short   word_000010;
 short   word_000012;
 unsigned int   uCompressedSize; // dword @ 000014
 unsigned short uTextureWidth;   // word @ 000018
 unsigned short uTextureHeight;  // word @ 00001A
 union
 {
  int dword_00001C;
  struct
  {
   short  word_00001C;
   short  word_00001E;
  };
 };
 unsigned char *ptr_000020;
 union
 {
  unsigned char *ptr_000024;
  struct
  {
   short  word_000024;
   short  word_000026;
  };
 };
 unsigned int uDecompressedSize;   // dword @ 000028
 char   byte_00002C[4];
 unsigned char *pIndexedPixels; // ptr @ 000030
 int    dword_000034;
 int    dword_000038;
 int    dword_00003C;
 unsigned short *pPalette; // ptr @ 000040
 unsigned char  *ptr_000044;

 unsigned int *pTruecolorPixels;
};
//sizeof = 000048
//int __thiscall sub_40F5BE(int this);
void *class18_ctor(struct class18 *_this);
//int __thiscall sub_40F77C(int this);
int sub_40F77C(struct class18 *_this);



struct LODIndex
{
 unsigned char pFilename[8];
 char a[24];
};
//sizeof == 20

struct LODFileHeader
{
 unsigned int uSignature; // dword @ 000000
 char a[168];
 unsigned char array_0000AC[32]; // byte[32] @ 0000AC
 char b[52];
};
//sizeof == 100

//class17
struct class17
{
 FILE *pLODFile;               //dword ptr [0000]
 char  sLODName[32];           //dword ptr [0004]

 char   byte_000024[0x0000E0];
 int   dword_000104;
 unsigned char *pLODIOBuffer;  // ptr @ 000108
 unsigned int   uIOBufferSize; // dword @ 00010C
 struct LODFileHeader sLODFileHeader;  //struct @ 000110
 void *dword_000210;
 char   sContainerName[12];    //string ptr [0214]
 int   dword_000220;
 int   dword_000224;
 int   dword_000228;
 unsigned int   uNumSubidices; // dword @ 00022C
 struct LODIndex *pLODSubIndexNamedBuffer;  // ptr @ 000230
 int   dword_000234;
 int   dword_000238;

 struct class18 aLODHeaders[2500];  // class18[~ 1000] @ 00023C
 //char   byte_00023C[16];
 //short  array_00024C[0x7528];

 int   dword_00EC9C;
 int   dword_00ECA0;
 int   dword_00ECA4;
 int   dword_00ECA8;
 int   dword_00ECAC;
 int   dword_00ECB0;

 char byte_00ECB4[0x2EC8];

 unsigned int uNumLoadedFiles; // dword @ 011B7C
 int   dword_011B80;
 int   dword_011B84;
 int   dword_011B88;
 int   dword_011B8C;
 int   dword_011B90;
 int   dword_011B94;
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
int class17_LoadLOD_Icons_Events(struct class17 *_this, const char *pLODFilename);
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
int class17_LoadPalette(struct class17 *_this, struct class18 *pClass18, const char *pContainerName, unsigned int DstBuf);
//int __thiscall sub_41097D(void *this, int a2, int a3, int a4);
int sub_41097D(struct class17 *_this, int a2, int a3, int a4);
//int __thiscall sub_461954(int this, int a2, signed int Size);
void class17_AllocateSubidexAndIOBuffer(struct class17 *_this, unsigned int uNumSubIndices, signed int uIOBufferSize);
//signed int __thiscall sub_461A43(void *this, const char *Filename, char a3);
int class17_LoadLOD_Games(struct class17 *_this, const char *pLODFilename, unsigned char uFileFlags);
//int __thiscall sub_4114F2(_DWORD);
int sub_4114F2(struct class17 *_this);
//int __thiscall sub_46454B(int this);
int sub_46454B(struct class17 *_this);
//int __thiscall sub_4645DC(int this);
int sub_4645DC(struct class17 *_this);
//signed int __thiscall sub_46161C(int this, const char *Str1);
bool class17_Games_LOD_FindLeveL(struct class17 *_this, const char *pLevelName);
//signed int __thiscall sub_4AC67E(int this, char *DstBuf, const char *Size);
int sub_4AC67E(struct class17 *_this, struct class18 *DstBuf, const char *pFilename);

unsigned int   class17_LoadTextureFromCBM(struct class17 *_this, const wchar_t *pFilename);
unsigned char *class17_LoadEvent(struct class17 *_this, const wchar_t *pFilename);




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
int class23_DeleteBuffer(struct class23 *_this, void *pMem);
//void *__thiscall sub_426755(void *this, int a2, signed int Size, const char *Source);
void *class23_AllocatedNamedBuffer(struct class23 *_this, int a2, int size, const char *pBufferName);
//signed int __thiscall sub_42654C(int this, int a2)
int class23_CreateFileDump(struct class23 *_this, const char *a2);



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
 int dword_00001C;
 int dword_000020;
 int dword_000024;
};
//sizeof ~ 28
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






//class35
struct class35
{
 char  aSomeCoords[50][256 * 3];   // array @ 000000
 short aSomeIndices[50][256 * 32]; // array @ 009600
 short array_0D1600[50][256 * 32]; // array @ 0D1600
 short array_199600[50][256 * 32]; // array @ 199600
 short array_261600[50][256];      // array @ 261600
                                   // 267A00

 int array_267A04[50];

 char byte_267AD0;
 char byte_267AD1;
 char byte_267AD2;
 char byte_267AD3;
 char byte_267AD4;
 char byte_267AD5;
 char byte_267AD6;
 char byte_267AD7;

 int dword_267AD8;
 int dword_267ADC;
 int dword_267AE0;
 int dword_267AE4;
 int dword_267AE8;
 int dword_267AEC;
};
//sizeof ~ ?
//int __thiscall sub_48A8F5(int this, int a2, int a3, int a4)
int class35_sub_48A8F5(struct class35 *_this, int a2, int a3, int a4);
//int __thiscall sub_48A614(int this);
int class35_sub_48A614(struct class35 *_this);
//int __thiscall sub_489BE0(int this, int a2);
int class35_sub_489BE0(struct class35 *_this, unsigned int idx);
//signed int __thiscall sub_48A3BC(void *this, int a2)
int class35_sub_48A3BC(struct class35 *_this, int a2);
//int __thiscall sub_48A8A3(int this);
int class35_sub_48A8A3(struct class35 *_this);
//signed int __thiscall sub_48A336(void *this);
int sub_48A336(struct class35 *_this);




//class36
struct class36
{
 int  dword_000000;
 char vector_000004[2560];

 int dword_000A04;
 int dword_000A08;
};
//sizeof ~ ?
//void *__thiscall sub_43B688(void *this);
void *class36_ctor(struct class36 *_this);



//class37
struct class37
{
 int dword_000000;

 char vector_000FA8[337800];
};
//void *__thiscall sub_43F282(void *this);
void *class37_ctor(struct class37 *_this);




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
 int dword_000000;

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
 char           byte_000022;
 char           byte_000023;
 unsigned char  uDamageModifier;   // byte @ 000024
 unsigned char  uMaterial;         // byte @ 000025
 char           byte_000026;
 char           byte_000027;
 char           byte_000028;
 char padding[7];
 //char byte_000032;
};
//sizeof == 30


//many items desc
struct class40
{
 int  uNumItems; // dword @ 000000

 struct Item pItems[800]; //struct[?] @ ?

 char byte_000004[71288];

 char unk_009604[1024 + array_size_unknown];
 struct ItemEnchantment pEnchantments[24]; // struct[24] @ 009604

 struct ItemSpecialEnchantment pSpecialEnchantments[72]; // struct[72} @ 0097E4

 unsigned char *pItemsTXT_Raw;    // ptr @ 011674
 unsigned char *pRndItemsTXT_Raw; // ptr @ 011678
 unsigned char *pStdItemsTXT_Raw; // ptr @ 01167C
 unsigned char *pSpcItemsTXT_Raw; // ptr @ 011680

 char byte_011684[96];
 unsigned int array_0116E4[9];

 int array_011700[6][2];

 int array_011738[24];
 int dword_011798;
};
//char *__thiscall sub_456D84(void *this);
char *sub_456D84(struct class40 *_this);
//int __thiscall sub_453B3C(void *this);
int sub_453B3C(struct class40 *_this);
//const char *__thiscall sub_453CE5(void *this)
const char *sub_453CE5(struct class40 *_this);
//char __thiscall sub_456620(void *this, int a2, signed int a3, int Dst);
char sub_456620(struct class40 *_this, int a2, signed int a3, int Dst);




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
//int __thiscall sub_453F62(void *this)
int CMapStats_Initialize(struct CMapStats *_this);
//signed int __thiscall sub_4547A3(int this, const char *Str2);
int CMapStats_FindLocation(struct CMapStats *_this, const char *pLocationFilename);




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
 unsigned int         dword_000050;  // dword @ 000050

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
//int __thiscall sub_45501E(void *this);
int CMonsterStats_Initialize(struct CMonsterStats *_this);
//char *__thiscall sub_454F4E(void *this)
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
//char *__thiscall sub_45384A(void *this)
char *CSpellStats_Initialize(struct CSpellStats *_this);





//hostile.txt
struct class48
{
 char byte_000000[8];
 char unknown[1024];
};
void class48_ctor(struct class48 *_this);
//int __thiscall sub_4547E4(void *this);
int class48_Initialize(struct class48 *_this);



struct StorylineText
{
 int dword_000000;
 char unknown[1024];
};
//int __thiscall sub_453E6D(void *this)
int StorylineText_Initialize(struct StorylineText *_this);





struct NPCProfesstion
{
 unsigned int   uHireCost;    // dword @ 000000
 unsigned char *pBenefits;    // ptr   @ 000004
 unsigned char *pActionText;  // ptr   @ 000008
 unsigned char *pJoinText;    // ptr   @ 00000C
 unsigned char *pDismissText; // ptr   @ 000010
};
//sizeof == 14

struct CNPCStats
{
 char a[98284];

 unsigned char *pNPCNames[540][2]; // ptr[2] array @ 012978

 struct NPCProfesstion pProfessions[59]; //struct[59} @ 013A6C

 short word_017F5A[51];

 int dword_017FC0;

 unsigned int uNumNPCProfessions; // dword    @ 017FCC
 unsigned int uNumNPCNames[2];    // dword[2] @ 017FD0 number of NPC names: [0] for male, [1] for female

 unsigned char *pNPCDataTXT_Raw;  // ptr @ 017FD8
 unsigned char *pNPCNamesTXT_Raw; // ptr @ 017FDC
 unsigned char *pNPCProfTXT_Raw;  // ptr @ 017FE0
 unsigned char *pNPCNewsTXT_Raw;  // ptr @ 017FE4
 unsigned char *pNPCTopicTXT_Raw; // ptr @ 017FE8
 unsigned char *pNPCTextTXT_Raw;  // ptr @ 017FEC
 unsigned char *pNPCDistTXT_Raw;  // ptr @ 017FF0
 unsigned char *pNPCGreetTXT_Raw; // ptr @ 017FF4
 unsigned char *pNCPGroupTXT_Raw; // ptr @ 017FF8
};

void CNPCStats_ctor(struct CNPCStats *_this);
//int __thiscall sub_47702F(void *this);
void CNPCStats_Initialize(struct CNPCStats *_this);
//char *__thiscall sub_476CB5(void *this);
char *CNPCStats_sub_476CB5(struct CNPCStats *_this);
//int __thiscall sub_476977(int this);
int CNPCStats_sub_476977(struct CNPCStats *_this);














struct Player
{
 union
 {
  struct
  {
   int     array_000000[40];
   __int64 qword_0000A0;

   unsigned char sName[16]; // byte[16] @ 0000A8
   unsigned char uSex;      // byte     @ 0000B8  0 male 1 female
   unsigned char uClass;    // byte     @ 0000B9
   unsigned char uFace;     // byte     @ 0000BA

   unsigned short uStrength;     // word @ 0000BC
   short word_0000BE;
   unsigned short uIntelligence; // word @ 0000C0
   short word_0000C2;
   unsigned short uWillpower;    // word @ 0000C4
   short word_0000C6;
   unsigned short uEndurance;    // word @ 0000C8
   short word_0000CA;
   unsigned short uAccuracy;     // word @ 0000CC
   short word_0000CE;
   unsigned short uSpeed;        // word @ 0000D0
   short word_0000D2;
   unsigned short uLuck;         // word @ 0000D4
   short word_0000D6;

   short word_0000DA;

   short word_0000DE;

   short array_000108[37];
   char array_000152[64];
   char array_000192[100];

   char byte_000192;

   char byte_00019D;

   char byte_0001A8;

   char byte_0001B3;

   char byte_0001BE;

   char byte_0001C9;

   char byte_0001D4;

   char byte_0001DF;

   char byte_0001EA;

   int array_000214[10 + array_size_unknown];

   int array_00157C[128];

   short word_00177E;

   char array_0017A0[24][16];
   int  dword_001920; //related to voice in SoundList
   int  dword_001924;
   int  dword_001928;

   short word_001934;

   int dword_00193C;
   int dword_001940;
   int dword_001944;

   char byte_001A4E;

   char byte_001A98;

   short word_001A9C;
   short word_001A9E;
   short word_001AA0;
  };
  struct
  {
   unsigned char _[0x1B3C];
  };
 };
};
//sizeof == 1B3C

struct Party
{
 int dword_000000;
 int dword_000004; // partyHeight registry key
 int dword_000008; // partyHeight registry key
 int dword_00000C; // eyelevel registry key
 int dword_000010; // eyelevel registry key

 unsigned char array_00002C[90636];

 int dword_00002C;
 int dword_000030;
 int dword_000034;
 int dword_000038;

 int dword_0006B4;
 int dword_0006B8;
 int dword_0006BC;
 int dword_0006C0;
 int dword_0006C4;
 int dword_0006C8;
 int dword_0006CC;
 int dword_0006D0;
 int dword_0006D4;
 int dword_0006D8;

 int dword_000700;

 int dword_000718; //related to a day number
 int dword_00071C;
 int dword_000720;

 unsigned char byte_000708;
 unsigned char byte_000709;
 unsigned char byte_00070A;
 unsigned char byte_00070B;

 int dword_000728;

 int dword_000734;
 int dword_000738;

 char unk_000765[0x100];

 unsigned char byte_000854[32 + array_size_unknown];

 int dword_00087C;

 int dword_000884;
 int dword_000888;

 char          array_00088C[20][16];
 struct Player pPlayers[4];          // struct[4] @ 0009CC

 int dword_007778;

 char pad[50000];
};
//sizeof ~ 16238

//int __thiscall sub_49370F(void *this);
int Party_sub_49370F(struct Party *_this);
//bool __thiscall sub_497FC5(void *this);
bool Party_sub_497FC5(struct Party *_this);






int Party_CreateDefault(struct Party *_this);

//void __thiscall sub_48E9B7(int this);
void Player_RandomizeName(struct Player *_this);
//signed int __thiscall sub_490109(int this);
int sub_490109(struct Player *_this);





struct struct0
{
 unsigned short uDescorationDescriptionID; // word @ 000000
 short word_000002;
 int   dword_000004;
 int   dword_000008;
 int   dword_00000C;
 int   dword_000010;
 short word_000014;
 short word_000016;
 short word_000018;
 short word_00001A;
 short word_00001C;
 short word_00001E;
};
//sizeof == 20

struct struct2
{
 char  byte_000000[2];
 short uObjectDescriptionID; // word @ 000002
 int   dword_000004;
 int   dword_000008;
 int   dword_00000C;
 char  byte_000010[96];
};
//sizeof == 70


struct struct3
{
 short word_000000;
 short word_000002;
 int   dword_000004;
 char  byte_000008[5316];
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
 short word_000000;
 char  byte_000002[22];
};
//sizeof == 18


//DERIVED from struct7
struct struct6//: public struct7
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

struct struct7
{
 short word_000000;
 short word_000002;
 short word_000004;
 short word_000006;
 char  byte_000008;
 char  byte_000009;
 char  byte_00000A;
 char  byte_00000B;
};
//sizeof == 0C

struct struct8
{
 char                  byte_000000[20];
 int                   dword_000014;
 char                  byte_000018[24];
 int                   dword_000030;
 char                  byte_000034[4];
 unsigned char        *ptr_000038;
 struct class18       *ptr_00003C;
 int                   dword_000040;
 int                   dword_000044;
 char                  byte_000048[12];
 struct class51_stru2 *ptr_000054;
 char                  byte_000058[180];
};
//sizeof == 10C
//void __thiscall sub_486089(int this);
void sub_486089(struct struct8 *_this);



struct class55
{
 signed int   dword_000000;
 signed int   dword_000004;
 signed int   dword_000008;
 int          dword_00000C;
 int          dword_000010;
 signed int   dword_000014;
 signed int   dword_000018;
 float        flt_00001C;
 float        flt_000020;

 float flt_00002C;
 float flt_000030;
 float flt_000034;
 float flt_000038;
 int   dword_00003C;
 int   dword_000040;
 int   dword_000044;
 int   dword_000048;
};
//sizeof ~ 4C 
//void sub_4239A7(int this);
void sub_4239A7(struct class55 *_this);
//signed __int64 __thiscall sub_42394D(void *this, signed int a2, signed int a3, int a4);
void class55_sub_42394D(struct class55 *_this, signed int a2, signed int a3, int a4);


#pragma pack(pop)