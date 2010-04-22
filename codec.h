#pragma once
#pragma pack(push, 1)

void __fastcall MemUnzip(void *pDest, unsigned int *pDecompressedSize, void *pSrc, int uCompressedSize);
int __fastcall sub_4C57C0_MaybeCalcHash(unsigned int a1, unsigned char *pData, unsigned int uSize);
struct class27 *__fastcall AllocateClass27(int a1, int a2, unsigned int *a3, unsigned int *a4, struct class19 *pParent);
signed int __fastcall sub_4C7C60(int a1, unsigned int *a2, int *a3, unsigned int *class21_pArray_8x1440, struct class19 *pParent);
signed int __fastcall sub_4C7D10(int *pSomeIndices, unsigned int uNumIndices, unsigned int a3, int a4, int a5, unsigned int **a6, unsigned int **a7, int a8, int a9, unsigned int a10);
signed int __fastcall sub_4C81E0(unsigned int a1, int a2, int *pSomeIndices, unsigned int *a4, unsigned int *a5, int a6, int a7, int a8, int a9);
int __fastcall sub_4C8340(int a1, int a2, int a3, int a4, int a5);
signed int __fastcall LOD_DoDecompression(int a1, int a2, int a3, int a4, struct class21 *pClass21, struct class19 *pClass19);




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



#pragma pack(pop)