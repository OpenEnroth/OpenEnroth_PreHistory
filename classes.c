#include "classes.h"
#include "defs.h"
#include "mm7DDrawRenderer.h"
#include "AIL.h"
#include "Smacker.h"

#include "data.h"


extern char off_4E7ECC[];
extern int dword_4E800C;
extern float flt_6BE3A0;
extern int dword_AD4730;
extern int dword_E31C7C;
extern char byte_6BE371;
extern int dword_4F00DC;
extern char unk_F79CC8[];
extern char byte_F79448[];
extern int dword_506128;
extern int dword_EF5294;


extern char unk_4EB8BC;
extern char unk_4EBBD0;
extern char byte_6BE36F;

extern int dword_4F00E4;
extern short word_F1B4C4;
extern int dword_4F00E4;
extern int dword_4F00E0;
extern short word_F1B4C6;
extern int dword_4F00E0;
extern int dword_4F00E4;
extern int dword_4F00E0;

extern int *dword_4F2688;

extern int dword_51B6E8;
extern int dword_51B6EC;
extern int dword_51B6F0;

extern int dword_6A0CA4;

extern int dword_720010;

extern int dword_720018;

extern int dword_F792F0;

extern int dword_F79D70;
extern int dword_F79D7C;


int sub_45DF13(); // weak
int sub_498038(); // weak
void __thiscall sub_45DF48(void *this);
int __thiscall sub_4898E6(int this);
void __thiscall sub_498069(void *this);

signed int __fastcall maybe_decompress_file(void *pDest, int *pDecompressedSize, void *pSrc, int uCompressedSize);
int __fastcall sub_4C57C0(unsigned int a1, unsigned char *pData, unsigned int uSize);
int __fastcall sub_4C4A30(int a1, int a2, int a3);
int __fastcall sub_4C7C50(int a1, int a2);
int __fastcall sub_4C74A0(int a1, int a2, int a3);
signed int __fastcall sub_4C81E0(unsigned int a1, int a2, int a3, unsigned int *a4, unsigned int *a5, int *a6, int *a7, int a8, struct class19 *);
signed int __fastcall sub_4C7C60(int a1, unsigned int *a2, int a3, unsigned int *class21_pArray_8x1440, struct class19 *pParent);
struct class27 *__fastcall AllocateClass27(int a1, int a2, unsigned int *a3, unsigned int *a4, struct class19 *pParent);
int __fastcall sub_4C8340(int a1, int a2, int a3, int a4, int a5);
DWORD __fastcall sub_426892(int a1, DWORD a2);
int __stdcall sub_401000(int a1, int a2, int a3, int (__thiscall *a4)(_DWORD));
signed int __fastcall LOD_DoDecompression(int a1, int a2, int a3, int a4, struct class21 *pClass21, struct class19 *pClass19);
char __cdecl sub_4A597D();
void __cdecl sub_4A57E9();
char __stdcall sub_4A0F40(int a1, void *Dst, int a3);
int unknown_libname_107();
double __stdcall sub_44F377(int a1);


//----- (MM7.exe::0044E4B7) --------------------------------------------------------
void *class00_ctor(struct class00 *_this)
{
 void *v1, *v2;

 _this->dword_000000 = 5080668;
 _this->dword_000704 = 0;
 _this->dword_000E08 = 0;
 _this->dword_000E0C = 0;
 _this->dword_000E10 = 0;
 _this->dword_000E14 = 0;
 _this->dword_000E18 = 0;
 _this->dword_000E1C = 0;
 _this->uSomeFlags = 0x0800;
 _this->dword_000E24 = 0x24;
 _this->dword_000E2C = 0;
 _this->dword_000E30 = 0;
 _this->dword_000E34 = 0;
 _this->dword_000E38 = 0;

 _this->class01_obj = malloc(0x64u);
 if (_this->class01_obj)
   class01_ctor(_this->class01_obj);

 _this->class02_obj = malloc(0xE430);
 if (_this->class02_obj)
   class02_ctor(_this->class02_obj);

 _this->class03_obj = malloc(0x114u);
 if (_this->class03_obj)
   class03_ctor(_this->class03_obj, _this->class01_obj);

 _this->class04_obj = malloc(0x3CBC38u);
 if (_this->class04_obj)
   class04_ctor(_this->class04_obj);

 _this->class05_obj = malloc(0x20D0u);
 if (_this->class05_obj)
   class05_ctor(_this->class05_obj);

 _this->class06_obj = malloc(0x5F8u);
 if (_this->class06_obj)
   class06_ctor(_this->class06_obj);

 _this->class08_obj = malloc(0x1A1384u);
 if (_this->class08_obj)
   class08_ctor(_this->class08_obj);

 _this->class09_obj = malloc(4u);
 if (_this->class09_obj)
   class09_ctor(_this->class09_obj);

 _this->class10_obj = malloc(8u);
 if (_this->class10_obj)
   class10_ctor(_this->class10_obj);

 _this->class11_obj = malloc(0xE8u);
 if (_this->class11_obj)
   class11_ctor(_this->class11_obj, 0);

 _this->class12_obj = malloc(0x90u);
 if (_this->class12_obj)
   class12_ctor(_this->class12_obj, _this->class11_obj);

 _this->class13_obj = malloc(4u);
 if (_this->class13_obj)
   class13_ctor(_this->class13_obj);

 _this->class14_obj = malloc(8u);
 if (_this->class14_obj)
   class14_ctor(_this->class14_obj);

 _this->pGammaController = malloc(0xC10u);
 if (_this->pGammaController)
   CGammaController_ctor(_this->pGammaController);

 class00_fn0(_this);
 if (dword_F79D7C != 2 || (dword_4E800C = 1, dword_F79D70 != 4))
   dword_4E800C = 0;
 return _this;
}

//----- (MM7.exe::0044F0FD) --------------------------------------------------------
int class00_fn0(struct class00 *_this)
{
 class00_fn1(_this, 1 << 6);
 if (!(_this->uSomeFlags & (1 << 6)))
 {
  _this->dword_000E08 = 0;
  _this->dword_000E0C = 0;
 }
 return _this->uSomeFlags;
}

//----- (MM7.exe::0044F0D8) --------------------------------------------------------
int class00_fn1(struct class00 *_this, int flags)
{
 if (_this->uSomeFlags & flags)
   _this->uSomeFlags &= ~flags;
 else
   _this->uSomeFlags |= flags;

  return _this->uSomeFlags;
}

//----- (MM7.exe::00438B0B) --------------------------------------------------------
void *class01_ctor(struct class01 *_this)
{
 //*(_DWORD *)_this = 5080528;
 _this->dword_000000 = 5080528;
 InitializeCriticalSection(&_this->cs1);
 InitializeCriticalSection(&_this->cs2);
 InitializeCriticalSection(&_this->cs3);
 InitializeCriticalSection(&_this->cs4);
  //InitializeCriticalSection((LPCRITICAL_SECTION)((char *)_this + 4));
  //InitializeCriticalSection((LPCRITICAL_SECTION)((char *)_this + 28));
  //InitializeCriticalSection((LPCRITICAL_SECTION)((char *)_this + 52));
  //InitializeCriticalSection((LPCRITICAL_SECTION)((char *)_this + 76));
 return _this;
}

//----- (MM7.exe::0048AAC5) --------------------------------------------------------
void *class02_ctor(struct class02 *_this)
{
  memset(_this->dword_000000, 0, 500 * 26 * 4);

  class02_fn0(_this);
  return _this;
}

//----- (MM7.exe::0048AAF6) --------------------------------------------------------
void *class02_fn0(struct class02 *_this)
{
 //*((_DWORD *)_this + 14601) = 500;
 //*((_DWORD *)_this + 14602) = 0;
 //*((_DWORD *)_this + 14603) = 0;
 _this->dword_000E424 = 500;
 _this->dword_000E428 = 0;
 _this->dword_000E42C = 0;
 //return memset(_this, 0, 0xCB20u);
 return memset(_this->dword_000000, 0, 500 * 26 * 4);
}

//----- (MM7.exe::00467E4E) --------------------------------------------------------
struct class03 *class03_ctor(struct class03 *_this, struct class01 *class01_obj)
{
 _this->dword_000024 = 0;
 _this->dword_000028 = 0;
 _this->dword_00002C = 0;
 _this->dword_000030 = 0;
 _this->dword_000034 = 0;
 _this->dword_000038 = 0;
 _this->dword_00003C = 0;
 _this->dword_000090 = 0;
 _this->class01_obj = class01_obj;
 return _this;
}

//----- (MM7.exe::0046A080) --------------------------------------------------------
int class03_fn1(struct class03 *_this, int a2)
{
 return _this->dword_000004 = a2;
}

//----- (MM7.exe::00469C39) --------------------------------------------------------
int *class03_fn2(struct class03 *_this, int *a2)
{
  int result; // eax@1
  int *v3; // edx@1
  int v4; // ecx@2
  int v5; // edx@3

 v3 = dword_720010;  //global class03 ref?
 result = a2;
 if (v3)
 {
    //*(_DWORD *)a2 = *(_DWORD *)(LODWORD(dword_720010) + 24);
    //v4 = *(_DWORD *)(LODWORD(v3) + 28);
  a2[0] = v3[6];
  a2[1] = v3[7];
 }
 else
 {
  a2[0] = _this->dword_000108;
  a2[1] = _this->dword_00010C;
   //v5 = *(_DWORD *)(this + 264);
   //v4 = *(_DWORD *)(this + 268);
   //*(_DWORD *)a2 = v5;
 }
 //*(_DWORD *)(a2 + 4) = v4;
 return a2;
}

//----- (MM7.exe::0045BB06) --------------------------------------------------------
void *class04_ctor(struct class04 *_this)
{
  int v1; // eax@1
  signed int v2; // ecx@1

 compile_error;//_eh_vector_constructor_iterator_((char *)_this + 4, 3100, 512, sub_45DF13, sub_45DF48);
 //*((_DWORD *)_this + 396801) = 0;
 _this->dword_183804 = 0;
 compile_error;//_eh_vector_constructor_iterator_((char *)_this + 1587208, 3100, 768, sub_45DF13, sub_45DF48);
 //*((_DWORD *)_this + 992002) = 0;
 _this->dword_3C8C08 = 0;
 v1 = (int)((char *)_this + 0x0F2318);
 v2 = 256;
 do
 {
   *(float *)v1 = 0.0;
   v1 += 48;
 }
 while (--v2);

 //*(_DWORD *)_this = 5080800;
 _this->dword_000000 = 5080800;
 return _this;
}

//----- (MM7.exe::004C04AF) --------------------------------------------------------
void *class05_ctor(struct class05 *_this)
{
 float v3; // [sp+Ch] [bp-60h]@1
 float v4; // [sp+10h] [bp-5Ch]@1
 float v5; // [sp+14h] [bp-58h]@1
 float v6; // [sp+38h] [bp-34h]@1
 float v7; // [sp+3Ch] [bp-30h]@1
 float v8; // [sp+40h] [bp-2Ch]@1
 float v9; // [sp+44h] [bp-28h]@1
 float v10; // [sp+68h] [bp-4h]@1

 //sub_4C055C((void *)((char *)_this + 4));
 class25_fn0(&_this->class25_obj);
 v6 = 0.0;
 v3 = 0.0;
 v4 = 65536.0;
 v5 = 0.0;
 v10 = 0.0;
 v7 = 65536.0;
 v8 = 0.0;
 v9 = 0.0;
 memcpy((void *)((char *)_this + 8204), &v7, 0x30u);
 v10 = 0.0;
 v7 = 0.0;
 v8 = 65536.0;
 v9 = 0.0;
 memcpy((void *)((char *)_this + 8252), &v3, 0x30u);
 v6 = 0.0;
 v3 = 65536.0;
 v4 = 0.0;
 v5 = 0.0;
 memcpy((void *)((char *)_this + 8300), &v3, 0x30u);
 memcpy((void *)((char *)_this + 8348), &v7, 0x30u);
 //*(_DWORD *)_this = 5081604;
 //*(_DWORD *)((char *)_this + 8396) = 512;
 _this->dword_000000 = 5081604;
 _this->dword_0020CC = 512;
 return _this;
}

//----- (MM7.exe::004A7155) --------------------------------------------------------
void *class06_ctor(struct class06 *_this)
{
 _this->dword_000204 = 0;
 _this->word_000208 = 0;
 _this->word_000218 = 0;
 _this->word_000218 = 0;
 _this->word_000238 = 0;
 _this->dword_0005C8 = 0;
 _this->dword_0005D8 = 0;

 _this->class07_obj = malloc(0x154);
 if (_this->class07_obj)
   class07_ctor(_this->class07_obj);

 class07_InitializeVectors(_this->class07_obj, 2.3439618e-038);
 return _this;
}

//----- (MM7.exe::004775B1) --------------------------------------------------------
void *class07_ctor(struct class07 *_this)
{
 _this->uNumVec4InArray1 = 0;
 _this->pFloatArray1 = 0;
 _this->uNumVec3InArray2 = 0;
 _this->pFloatArray2 = 0;
 _this->dword_000010 = 0;
 return _this;
}

//----- (MM7.exe::00478211) --------------------------------------------------------
void *class07_InitializeVectors(struct class07 *_this, float w)
{
 int v2;
 int v7; // eax@2
 float *v8; // ecx@2

 _this->uNumVec4InArray1 = 66;
 _this->pFloatArray1 = malloc(66 * 4 * sizeof(float));
 _this->uNumVec3InArray2 = 128;
 _this->pFloatArray2 = malloc(128 * 3 * sizeof(float));

 v2 = 0;
 v7 = 0;
 v8 = &unk_4EB8BC;
 do
 {
  _this->pFloatArray1[v7 + 0] = v8[-1];
  _this->pFloatArray1[v7 + 1] = v8[0];
  _this->pFloatArray1[v7 + 2] = v8[1];
  _this->pFloatArray1[v7 + 3] = w;

  v7 += 4;
  v8 += 3;
 }
 while (++v2 < _this->uNumVec4InArray1);

 //return memcpy(*(void **)(v3 + 12), &unk_4EBBD0, 12 * *(_DWORD *)(v3 + 8));
 return memcpy(_this->pFloatArray2, &unk_4EBBD0, 12 * _this->uNumVec3InArray2);
}

//----- (MM7.exe::004361EF) --------------------------------------------------------
struct class08 *class08_ctor(struct class08 *_this)
{
  float *v1; // eax@1
  signed int v2; // ecx@1
  int v3; // esi@1
  double v4; // st7@1
  double v5; // st6@1
  double v6; // st5@1
  double v7; // st7@1
  double v8; // st6@1
  double v9; // st5@1
  int *v10; // edi@3
  signed int v13; // [sp+4h] [bp-10h]@3

  v3 = _this;
  class26_ctor(&_this->class26_obj1);
  class26_ctor(&_this->class26_obj2);
  class26_ctor(&_this->class26_obj3);
  compile_error;//_eh_vector_constructor_iterator_(v3 + 52, 24, 6, sub_498038, sub_498069);
  //v4 = (double)dword_51B6F0;
  //v5 = (double)dword_51B6EC;
  //v6 = (double)dword_51B6E8;
  //*(float *)(v3 + 264) = 0.0;
  //*(float *)(v3 + 220) = v6;
  //*(float *)(v3 + 224) = v5;
  //*(float *)(v3 + 228) = v4;
  _this->flt_0000DC = dword_51B6E8;
  _this->flt_0000E0 = dword_51B6EC;
  _this->flt_0000E4 = dword_51B6F0;
  _this->flt_000108 = 0;
  //v7 = (double)dword_51B6F0;
  //v8 = (double)dword_51B6EC;
  //v9 = (double)(dword_51B6E8 + 300);
  //*(float *)(v3 + 268) = v9;
  //*(float *)(v3 + 272) = v8;
  //*(float *)(v3 + 276) = v7;
  //*(float *)(v3 + 312) = 0.0;
  _this->flt_00010C = dword_51B6E8 + 300;
  _this->flt_000110 = dword_51B6EC;
  _this->flt_000114 = dword_51B6F0;
  _this->flt_000138 = 0;

  //*(float *)(v3 + 360) = 0.0;
  //*(float *)(v3 + 408) = 0.0;
  //*(float *)(v3 + 456) = 0.0;
  //*(float *)(v3 + 504) = 0.0;
  //*(float *)(v3 + 552) = 0.0;
  //*(float *)(v3 + 600) = 0.0;
  //*(float *)(v3 + 648) = 0.0;
  _this->flt_000168 = 0;
  _this->flt_000198 = 0;
  _this->flt_0001C8 = 0;
  _this->flt_0001F8 = 0;
  _this->flt_000228 = 0;
  _this->flt_000258 = 0;
  _this->flt_000288 = 0;

  //*(float *)(v3 + 696) = 0.0;
  //*(float *)(v3 + 700) = 0.0;
  //*(float *)(v3 + 704) = 0.0;
  //*(float *)(v3 + 708) = 0.0;
  _this->flt_0002B8 = 0;
  _this->flt_0002BC = 0;
  _this->flt_0002C0 = 0;
  _this->flt_0002C4 = 0;
  //*(float *)(v3 + 744) = 0.0;
  //*(float *)(v3 + 748) = 0.0;
  //*(float *)(v3 + 752) = 0.0;
  //*(float *)(v3 + 756) = 0.0;
  _this->flt_0002E8 = 0;
  _this->flt_0002EC = 0;
  _this->flt_0002F0 = 0;
  _this->flt_0002F4 = 0;

  //*(float *)(v3 + 792) = 0.0;
  //*(float *)(v3 + 796) = 0.0;
  //*(float *)(v3 + 800) = 0.0;
  //*(float *)(v3 + 804) = 0.0;
  _this->flt_000318 = 0;
  _this->flt_00031C = 0;
  _this->flt_000320 = 0;
  _this->flt_000324 = 0;

  //*(float *)(v3 + 840) = 0.0;
  //*(float *)(v3 + 844) = 0.0;
  //*(float *)(v3 + 848) = 0.0;
  //*(float *)(v3 + 852) = 0.0;
  _this->flt_000348 = 0;
  _this->flt_00034C = 0;
  _this->flt_000350 = 0;
  _this->flt_000354 = 0;

  //*(float *)(v3 + 888) = 0.0;
  _this->flt_000378 = 0;

  v2 = 16384;
  //v1 = v3 + 892;
  v1 = _this->array_00037C;
  do
  {
    //*(_DWORD *)v1 = 0;
    //*(float *)(v1 + 48) = 0.0;
   *(int *)(v1) = 0;
   v1[12] = 0;
   v1 += 14;
  }
  while (--v2);

  //*(_DWORD *)(v3 + 918396) = 0;
  _this->dword_0E037C = 0;

  //v10 = v3 + 918400;
  v10 = _this->array_0E0380;
  v13 = 256;
  do
  {
   //*(_DWORD *)v10 = 0;
   v10[0] = 0;
   //sub_401000(v10 + 1, 48, 64, (int (__thiscall *)(_DWORD))loc_4363A2);
   v10 += 772;
  }
  while (v13-- != 1);

  //*(_DWORD *)(v3 + 1708928) = 0;
  //*(_DWORD *)v3 = 5080468;
  _this->dword_000000 = 5080468;
  _this->dword_1A1380 = 0;
  return _this;
}

//----- (MM7.exe::00498093) --------------------------------------------------------
struct class09 *class09_ctor(struct class09 *_this)
{
 _this->dword_000000 = 5081240;
 return _this;
}

//----- (MM7.exe::0049C5B0) --------------------------------------------------------
struct class10 *class10_ctor(struct class10 *_this)
{
 _this->dword_000000 = 5081272;
 _this->dword_000004 = 0;
 return _this;
}

//----- (MM7.exe::00438526) --------------------------------------------------------
struct class11 *class11_ctor(struct class11 *_this, int a2)
{
  signed int v2; // eax@1
  int *v3; // edx@1

 _this->dword_000000 = 0;

 _this->dword_000020 = 0;
 _this->dword_000024 = 0;

 _this->dword_000038 = 0;
 _this->dword_00003C = 0;

 _this->dword_000060 = 0;
 _this->dword_000064 = 0;
 _this->dword_000068 = 0;

 _this->dword_00009C = 0;
 _this->dword_0000A0 = 0;
 _this->dword_0000A4 = 0;
 _this->dword_0000A8 = 0;
 _this->dword_0000AC = 0;
 _this->dword_0000B0 = 0;
 _this->dword_0000B4 = 0;

 v2 = 0;

  //v3 = (char *)_this + 40;
 v3 = &_this->dword_000028;
 do
 {
  if (v2 < 3)
    v3[-9] = 0;
  if (v2 < 4)
    v3[0] = 0;
  if (v2 < 12)
    v3[17] = 0;
  if (v2 < 13)
    *((char *)(_this) + v2 + 16) = 0;
  if (v2 < 30)
    *((char *)(_this) + v2 + 64) = 0;

  *((char *)(_this) + v2++ + 181) = 0;
  v3++;
 }
 while ( v2 < 48 );

 class11_fn0(_this, a2);
 return _this;
}

//----- (MM7.exe::004385B5) --------------------------------------------------------
void *class11_fn0(void *_this, int a2)
{
  int v6; // ST00_4@1
  int v11; // ST00_4@2
  int result; // eax@5
  signed int v13; // [sp+4h] [bp-8h]@1
  signed int v14; // [sp+8h] [bp-4h]@1

  compile_error;//_OF = 0;
  compile_error;//_CF = 0;
  compile_error;//_ZF = 1;
  compile_error;//_SF = 0;
  v14 = 0;
  compile_error;//__asm { pushf }
  v13 = 3;

  compile_error;//if ( v6 != (v6 ^ 0x40000) )
  if (0)
  {
    compile_error;//__asm { popf }
    v13 = 4;
    compile_error;//__asm { pushf }
    if ( v11 ^ v11 ^ 0x200000 )
    {
      v14 = 1;
      v13 = 0;
    }
  }
  if ( v13 == 3 )
  {
    result = _this;
    *(_DWORD *)((char *)_this + 172) = 1;
  }
  else
  {
    if ( v13 == 4 )
    {
      result = _this;
      *(_DWORD *)((char *)_this + 172) = 2;
    }
    else
    {
      if ( v14 )
      {
        *(_DWORD *)((char *)_this + 172) = 2;
        result = class11_fn1(_this, a2);
      }
      else
      {
        result = _this;
        *(_DWORD *)((char *)_this + 172) = 0;
      }
    }
  }
  return result;
}

//----- (MM7.exe::004895B7) --------------------------------------------------------
struct class12 *class12_ctor(struct class12 *_this, struct class11 *class11_obj)
{
 int i;

 _this->pMemberFn = sub_4898E6;
 _this->dword_000044 = 1090519040;
 _this->dword_000048 = 0;
 _this->dword_00004C = 1174405120;
 _this->dword_000050 = 0;
 _this->dword_000054 = 869711765;
 _this->dword_000058 = 0;

 for (i = 0; i < 12; ++i)
 {
  _this->class16_objs[i] = malloc(8);
  if (_this->class16_objs[i])
    class16_ctor(_this->class16_objs[i], 640);
 }

 _this->dword_00008C = 0;
 return _this;
}

//----- (MM7.exe::004A9507) --------------------------------------------------------
struct class13 *class13_ctor(struct class13 *_this)
{
 _this->dword_000000 = 5081416;
 return _this;
}

//----- (MM7.exe::0045AFD9) --------------------------------------------------------
struct class14 *class14_ctor(struct class14 *_this)
{
 _this->dword_000000 = 5080756;
 _this->dword_000004 = 0;

 if (dword_F79D7C == 2)
 {
  if (dword_F79D70 == 4)
    _this->dword_000004 = 0;
 }
 return _this;
}

//----- (MM7.exe::0048958E) --------------------------------------------------------
struct class16 *class16_ctor(struct class16 *_this, unsigned int uBlockSize)
{
 _this->pMemBlock = malloc(8 * uBlockSize + 16);
 _this->pAlignedMem = (char *)(_this->pMemBlock) + (-(signed int)_this->pMemBlock & 7);
 return _this;
}

//----- (MM7.exe::0040FAEE) --------------------------------------------------------
int class17_LoadLOD_Icons(struct class17 *_this, const char *pFilename)
{
 class17_fn4(_this);
 if (class17_MaybeLoadLODHeader(_this, pFilename, 1))
   return 0;
  
 return class17_fn6(_this, "icons") == 0;
}

//----- (MM7.exe::0040FA2E) --------------------------------------------------------
int class17_LoadLOD_Bitmaps(struct class17 *_this, const char *pFilename)
{
 class17_fn4(_this);
 if (class17_MaybeLoadLODHeader(_this, pFilename, 1))
   return 0;

 return class17_fn6(_this, "bitmaps") == 0;
}

//----- (MM7.exe::004AC795) --------------------------------------------------------
int class17_LoadLOD_Sprites(struct class17 *_this, const char *pFilename)
{
 if (class17_MaybeLoadLODHeader(_this, pFilename, 1))
   return 0;

 return class17_fn6(_this, "sprites08") == 0;
}

//----- (MM7.exe::0041088B) --------------------------------------------------------
void *class17_fn1(void *_this, const char *pContainer, int a3)
{
  unsigned char *result; // ebx@7
  unsigned char *v8; // edi@7
  struct class18 class18_obj; // [sp+Ch] [bp-4Ch]@1
  //class18::size1 size_t v12; // [sp+20h] [bp-38h]@3
  //class18::size2 size_t Size; // [sp+34h] [bp-24h]@3
  FILE *pContainerFile; // [sp+54h] [bp-4h]@1


  class18_ctor(&class18_obj);

  pContainerFile = class17_FindContainer(_this, pContainer, 0);
  if (!pContainerFile)
    sub_466BE5("Unable to load %s", pContainer);

  locked_fread(&class18_obj, 1, 0x30u, pContainerFile);
  if (class18_obj.uDecompressedSize)
  {
    if (a3)
      result = malloc(class18_obj.uDecompressedSize);
    else
      result = class23_AllocatedNamedBuffer(class23_instance, 0, class18_obj.uDecompressedSize, class18_obj.sContainerName);

    v8 = class23_AllocatedNamedBuffer(class23_instance, 0, class18_obj.uCompressedSize, class18_obj.sContainerName);
    locked_fread(v8, 1, class18_obj.uCompressedSize, pContainerFile);
    maybe_decompress_file(result, &class18_obj.uDecompressedSize, v8, class18_obj.uCompressedSize);
    class18_obj.uCompressedSize = class18_obj.uDecompressedSize;
    class23_fn1(class23_instance, v8);
  }
  else
  {
    if (a3)
      result = malloc(class18_obj.uCompressedSize);
    else
      result = class23_AllocatedNamedBuffer(class23_instance, 0, class18_obj.uCompressedSize, &class18_obj);
    locked_fread(result, 1u, class18_obj.uCompressedSize, pContainerFile);
  }
  return result;
}

//----- (MM7.exe::00461580) --------------------------------------------------------
FILE *class17_FindContainer(struct class17 *_this, const char *pContainerName, int a3)
{
  int v4; // eax@4
  int v5; // edi@5
  int v7; // [sp+18h] [bp+Ch]@6

  //if ( !*(_DWORD *)((char *)_this + 260) )
  if (!_this->dword_000104)
    return 0;
  if (a3)
  {
    v5 = 0;
    //if ( *(_DWORD *)((char *)_this + 556) > 0 )
    if (_this->dword_00022C > 0)
    {
      v7 = 0;
      //while ( _strcmpi(pContainerName, (const char *)(v7 + *(_DWORD *)(v3 + 560))) )
      while (_strcmpi(pContainerName, (const char *)(_this->pLODIndexNamedBuffer) + v7))
      {
        v7 += 32;
        ++v5;
        //if ( v5 >= *(_DWORD *)(v3 + 556) )
        if (v5 >= _this->dword_00022C)
          return 0;
      }
      v4 = *(_DWORD *)(32 * v5 + (char *)_this->pLODIndexNamedBuffer + 16);
      goto LABEL_12;
    }
    return 0;
  }
  class17_fn3(_this, 0, _this->dword_00022C, pContainerName);
  if ( dword_6A0CA4 < 0 )
    return 0;
  v4 = *(_DWORD *)((char *)_this->pLODIndexNamedBuffer + 32 * dword_6A0CA4 + 16);
LABEL_12:

 fseek(_this->pLODFile, _this->dword_000234 + v4, 0);
 return _this->pLODFile;
}

//----- (MM7.exe::0046165E) --------------------------------------------------------
int class17_fn3(struct class17 *_this, int a2, int a3, const char *pContainerName)
{
  int v4; // esi@1
  int result; // eax@2
  int v6; // ebx@2
  int v7; // edi@10
  int v8; // esi@11
  int v9; // esi@17
  void *v10; // [sp+Ch] [bp-4h]@1

  v4 = a2;
  v10 = _this;
  while (true)
  {
    while (true)
    {
      v6 = a3 - v4;
      result = _strcmpi(pContainerName, (const char *)(*((_DWORD *)v10 + 140) + 32 * ((a3 - v4) / 2 + v4)));
      if ( !result )
        dword_6A0CA4 = (a3 - v4) / 2 + v4;
      if ( v4 == a3 )
        goto LABEL_14;
      if ( result < 0 )
        break;
      if ( v6 <= 4 )
      {
        v7 = v4;
        if ( v4 < a3 )
        {
          v9 = 32 * v4;
          do
          {
            result = _strcmpi(pContainerName, (const char *)(v9 + *((_DWORD *)v10 + 140)));
            if ( !result )
              goto LABEL_21;
            ++v7;
            v9 += 32;
          }
          while ( v7 < a3 );
        }
LABEL_14:
        dword_6A0CA4 = -1;
        return result;
      }
      v4 += (a3 - v4) / 2;
    }
    if ( v6 <= 4 )
      break;
    a3 = (a3 - v4) / 2 + v4;
  }
  v7 = v4;
  if ( v4 >= a3 )
    goto LABEL_14;
  v8 = 32 * v4;
  while ( 1 )
  {
    result = _strcmpi(pContainerName, (const char *)(v8 + *((_DWORD *)v10 + 140)));
    if ( !result )
      break;
    ++v7;
    v8 += 32;
    if ( v7 >= a3 )
      goto LABEL_14;
  }
LABEL_21:
  dword_6A0CA4 = v7;
  return result;
}

//----- (MM7.exe::0040FA60) --------------------------------------------------------
void class17_fn4(struct class17 *_this)
{
  int v1; // edi@1
  int v2; // esi@1
  int v3; // ebp@2
  int v4; // eax@3
  int v5; // eax@4
  int v6; // eax@6
  int v7; // eax@7

 v2 = _this;
 //v1 = *(_DWORD *)(this + 72572) - 1;
 v1 = _this->dword_011B7C  - 1;

 if (v1 >= 0)
 {
  //v3 = this + 72 * v1 + 572;
  v3 = (char *)_this + 572 + 72 * v1;

  do
  {
   sub_40F77C(v3);
   //v4 = *(_DWORD *)(v2 + 72624);
   v4 = _this->dword_011BB0;
   if (v4)
   {
    v5 = *(_DWORD *)(v4 + 4 * v1);

        if ( v5 )
        {
          (*(void (__stdcall **)(int))(*(_DWORD *)v5 + 8))(v5);
          *(_DWORD *)(*(_DWORD *)(v2 + 72624) + 4 * v1) = 0;
        }
      }
      v6 = *(_DWORD *)(v2 + 72620);
      if ( v6 )
      {
        v7 = *(_DWORD *)(v6 + 4 * v1);
        if ( v7 )
        {
          (*(void (__stdcall **)(int))(*(_DWORD *)v7 + 8))(v7);
          *(_DWORD *)(*(_DWORD *)(v2 + 72620) + 4 * v1) = 0;
        }
      }
      --v1;
      v3 -= 72;
    }
    while ( v1 >= 0 );
  }
 _this->dword_011B7C = 0;
 _this->dword_011B80 = 0;
 _this->dword_011B84 = 0;

 _this->dword_011B98 = 0;
 _this->dword_011B9C = 0;
}

//----- (MM7.exe::004617D5) --------------------------------------------------------
int class17_MaybeLoadLODHeader(struct class17 *_this, const char *pFilename, char a3)
{
  int v3; // esi@1
  int v5; // eax@7
  const char *v7; // [sp-4h] [bp-Ch]@4


 if (_this->dword_000104)
   sub_461431(_this);

 if (a3 & 1)
   v7 = "rb";
 else v7 = "rb+";

 _this->pLODFile = fopen(pFilename, v7);
 if (!_this->pLODFile)
   return 1;

 //strcpy((char *)(v3 + 4), Filename);
 strcpy(_this->sLODName, pFilename);

 //locked_fread((void *)(v3 + 272), 0x100u, 1u, *(FILE **)v3);
 locked_fread(_this->aLODHeader, 256, 1, _this->pLODFile);

 //v5 = class23_fn2(class23_instance, *(_DWORD *)(v3 + 528), 160, "LOD CArray");
 v5 = class23_AllocatedNamedBuffer(class23_instance, _this->dword_000210, 160, "LOD CArray");

 //*(_DWORD *)(v3 + 528) = v5;
 _this->dword_000210 = v5;

 if (!_this->dword_000210)
 {
  fclose(_this->pLODFile);
  return 1;
 }

 //locked_fread(_this->dword_000210, 0x20u, *(_DWORD *)(v3 + 444), _this->pLODFile);
 locked_fread(_this->dword_000210, 0x20u, _this->aLODHeader[43], _this->pLODFile);

 fseek(_this->pLODFile, 0, SEEK_SET);
 //*(_DWORD *)(v3 + 260) = 1;
 _this->dword_000104 = 1;
 return 0;
}

//----- (MM7.exe::0046188A) --------------------------------------------------------
int class17_fn6(struct class17 *_this, const char *pContainer)
{
  int v2; // edi@1
  int v3; // esi@1
  int v4; // ebx@2
  signed int result; // eax@5
  int v6; // eax@7
  int v7; // eax@7
  int v8; // eax@7
  __int32 v9; // edx@7

 v3 = _this;
 class17_fn7(_this);
 v2 = 0;

 //if ( *(_DWORD *)(v3 + 444) <= 0 )
 if (_this->aLODHeader[43] <= 0)
 {
LABEL_5:
  result = 3;
 }
 else
 {
  v4 = 0;
  //while ( _strcmpi(Source, (const char *)(v4 + *(_DWORD *)(v3 + 528))) )
  while (strcmpi(pContainer, &((char *)(_this->dword_000210))[v4]))
  {
   ++v2;
   v4 += 32;
   //if (v2 >= *(_DWORD *)(v3 + 444))
   if (v2 >= _this->aLODHeader[43])
     goto LABEL_5;
  }

  //strcpy((char *)(v3 + 532), Source);
  strcpy(_this->sContainerName, pContainer);
  //v7 = *(_DWORD *)(v3 + 528);
  //*(_DWORD *)(v3 + 548) = v2;
  v7 = _this->dword_000210;
  _this->dword_000224 = v2;

  v8 = 32 * v2 + v7;
  v9 = *(_DWORD *)(v8 + 16);
  //*(_DWORD *)(v3 + 564) = v9;
  _this->dword_000234 = v9;

  //*(_DWORD *)(v3 + 556) = *(_WORD *)(v8 + 28);
  _this->dword_00022C = *(_WORD *)(v8 + 28);
  fseek(_this->pLODFile, v9, 0);

  //v6 = class23_AllocatedNamedBuffer(class23_instance, *(_DWORD *)(v3 + 560), 32 * (*(_DWORD *)(v3 + 556) + 5), "LOD Index");
  v6 = class23_AllocatedNamedBuffer(class23_instance, _this->pLODIndexNamedBuffer, 32 * (_this->dword_00022C + 5), "LOD Index");

  //*(_DWORD *)(v3 + 560) = v6;
  _this->pLODIndexNamedBuffer = v6;
  if (_this->pLODIndexNamedBuffer)
    locked_fread(_this->pLODIndexNamedBuffer, 0x20u, _this->dword_00022C, _this->pLODFile);
  result = 0;
 }
 return result;
}

//----- (0046153F) --------------------------------------------------------
int class17_fn7(struct class17 *_this)
{
 int result; // eax@2

 if (_this->dword_000104)
 {
  _this->sContainerName[0] = 0;
  _this->dword_000224 = 0;

  _this->dword_000228 = 0;
  _this->dword_00022C = 0;
  _this->dword_000234 = 0;

  result = class23_fn1(class23_instance, _this->pLODIndexNamedBuffer);
  _this->pLODIndexNamedBuffer = 0;
 }
 return result;
}

void class17_ctor(struct class17 *_this)
{
 memset(_this, 0, sizeof(struct class17));
}

//----- (MM7.exe::0040FB20) --------------------------------------------------------
int class17_LoadTexture(struct class17 *_this, const char *pContainerName, unsigned int a3)
{
  int v3; // edi@1
  struct class18 *pClass18; // ebx@2
  int v6; // ebx@8

 v3 = 0;
 dword_506128 = 1;
 if (_this->dword_011B7C <= 0 )
 {
LABEL_5:
  if (_this->dword_011B7C >= 1000)
    sub_466B8C();

  if (sub_40FC08(_this, &_this->class18_array[_this->dword_011B7C], pContainerName, a3) == -1)
  {
   v6 = 0;
   if (_this->dword_011B7C > 0)
   {
    pClass18 = _this->class18_array;
    while (_strcmpi(pClass18->sContainerName, "pending"))
    {
     pClass18++;
     ++v6;
     if (v6 >= _this->dword_011B7C)
       goto LABEL_15;
    }
    return v6;
   }

LABEL_15:
   sub_40FC08(_this, &_this->class18_array[_this->dword_011B7C], "pending", a3);
  }
  dword_506128 = 0;
  ++_this->dword_011B7C;
  return _this->dword_011B7C - 1;
 }

 pClass18 = _this->class18_array;
 while (_strcmpi(pClass18->sContainerName, pContainerName))
 {
  ++v3;
  pClass18++;
  if (v3 >= _this->dword_011B7C)
    goto LABEL_5;
 }
 return v3;
}

//----- (MM7.exe::0040FC08) --------------------------------------------------------
int sub_40FC08(struct class17 *_this, struct class18 *pClass18, const char *pContainerName, unsigned int uSomeInt)
{
  //int v4; // eax@1
  int v5; // ebx@1
  int v6; // edi@1
  struct class18 *v8; // esi@3
  void *v9; // ST24_4@8
  int v10; // esi@14
  size_t v11; // eax@14
  unsigned int v12; // eax@14
  int v13; // eax@21
  int v19; // eax@29
  int v21; // eax@29
  size_t v22; // ST2C_4@29
  const void *v23; // ecx@29
  __int16 v24; // ax@29
  int v25; // ecx@29
  int v26; // edx@29
  int v27; // ecx@29
  int v33; // eax@37
  signed int v34; // eax@37
  int v35; // ecx@37
  int v36; // ecx@37
  signed int v40; // ecx@43
  signed int v41; // ecx@48
  //FILE *v42; // [sp+14h] [bp-4h]@1
  signed int v45; // [sp+20h] [bp+8h]@29

  unsigned char *pCompressedBuffer,
                *pDecompressedBuffer;
  unsigned char aReadBuf[4];
  int   i;
  FILE *f;

  v5 = pContainerName;
  v6 = _this;
 v8 = pClass18;

 f = class17_FindContainer(_this, pContainerName, 0);
 if (!f)
   return -1;

 locked_fread(pClass18, 1, 0x30, f);
 strcpy(pClass18->sContainerName, pContainerName);

 if (pD3DRenderer->dword_040088 && pClass18->byte_00002C[0] & 2 && _this->dword_011BA8)
  {
    if ( !*(_DWORD *)(v6 + 72620) || !*(_DWORD *)(v6 + 72624) )
    {
      compile_error;//*(_DWORD *)(v6 + 72620) = new char[0xFA0u];
      compile_error;//*(_DWORD *)(v6 + 72624) = new char[0xFA0u];
      v9 = *(void **)(v6 + 72620);
      compile_error;//*(_DWORD *)(v6 + 72628) = new char[0x3E8u];
      memset(v9, 0, 0xFA0u);
      memset(*(void **)(v6 + 72624), 0, 0xFA0u);
      memset(*(void **)(v6 + 72628), 0, 0x3E8u);
    }
    if ( *(_BYTE *)v5 != 119
      || *(_BYTE *)(v5 + 1) != 116
      || *(_BYTE *)(v5 + 2) != 114
      || *(_BYTE *)(v5 + 3) != 100
      || *(_BYTE *)(v5 + 4) != 114 )
    {
      if ( *(_BYTE *)v5 != 87
        || *(_BYTE *)(v5 + 1) != 116
        || *(_BYTE *)(v5 + 2) != 114
        || *(_BYTE *)(v5 + 3) != 84
        || *(_BYTE *)(v5 + 4) != 121
        || *(_BYTE *)(v5 + 5) != 108 )
      {
        v13 = *(_DWORD *)(v6 + 72572);
      }
      else
      {
        dword_EF5294 = *(_DWORD *)(v6 + 72572);
        v13 = *(_DWORD *)(v6 + 72572);
      }
      v10 = sub_4A4DE1(
              pD3DRenderer,
              v5,
              *((_WORD *)v8 + 18),
              4 * v13 + *(_DWORD *)(v6 + 72620),
              4 * v13 + *(_DWORD *)(v6 + 72624));
    }
    else
    {
      v11 = strlen((const char *)v5);
      compile_error;//v12 = (unsigned int)operator new(v11 + 2);
      uSomeInt = v12;
      *(_BYTE *)v12 = 104;
      strcpy((char *)(v12 + 1), (const char *)v5);
      v10 = sub_4A4DE1(
              pD3DRenderer,
              uSomeInt,
              *((_WORD *)v8 + 18),
              4 * *(_DWORD *)(v6 + 72572) + *(_DWORD *)(v6 + 72620),
              4 * *(_DWORD *)(v6 + 72572) + *(_DWORD *)(v6 + 72624));
      sub_4CA32D(v10, uSomeInt);
    }
    return v10;
 }



 if (!pClass18->uDecompressedSize || _this->dword_011BA4)
 {
  pClass18->ptr_000030 = class23_AllocatedNamedBuffer(class23_instance, pClass18->ptr_000030, pClass18->uCompressedSize, pClass18->sContainerName);
  locked_fread(pClass18->ptr_000030, 1u, pClass18->uCompressedSize, f);
 }
 else
 {
  pCompressedBuffer = malloc(pClass18->uCompressedSize);
  pDecompressedBuffer = malloc(pClass18->uDecompressedSize);

  locked_fread(pCompressedBuffer, 1, pClass18->uCompressedSize, f);
  maybe_decompress_file(pDecompressedBuffer, &pClass18->uDecompressedSize, pCompressedBuffer, pClass18->uCompressedSize);
  call_delete(0, pCompressedBuffer);

  pClass18->uCompressedSize = pClass18->uDecompressedSize;


  if (bUseLoResSprites && pClass18->byte_00002C[0] & 2)
  {
      v45 = (*((_DWORD *)v8 + 4) >> 2) + (*((_DWORD *)v8 + 4) >> 4) + (*((_DWORD *)v8 + 4) >> 6);
      v21 = class23_AllocatedNamedBuffer(class23_instance, *((_DWORD *)v8 + 12), v45, (const char *)v8);
      v22 = v45;
      compile_error;//v23 = (const void *)(v31 + *((_WORD *)v8 + 12) * *((_WORD *)v8 + 13));
      *((_DWORD *)v8 + 12) = v21;
      memcpy((void *)v21, v23, v22);
      *((_WORD *)v8 + 12) >>= 1;
      v24 = *((_WORD *)v8 + 12);
      *((_WORD *)v8 + 13) >>= 1;
      LOWORD(v25) = *((_WORD *)v8 + 13);
      --*((_WORD *)v8 + 14);
      --*((_WORD *)v8 + 15);
      *((_WORD *)v8 + 16) = v24 - 1;
      v26 = v25 - 1;
      v27 = v24 * (signed __int16)v25;
      v19 = v45;
      *((_WORD *)v8 + 17) = v26;
      *((_DWORD *)v8 + 4) = v27;
      *((_DWORD *)v8 + 5) = v19;
  }
  else
  {
   pClass18->ptr_000030 = class23_AllocatedNamedBuffer(class23_instance, pClass18->ptr_000030, pClass18->uDecompressedSize, pClass18->sContainerName);
   memcpy(pClass18->ptr_000030, pDecompressedBuffer, pClass18->uDecompressedSize);
  }
  call_delete(0, pDecompressedBuffer);
 }


 class23_fn1(class23_instance, pClass18->ptr_000040);
 class23_fn1(class23_instance, pClass18->ptr_000044);

 if (uSomeInt == 1)
 {
  pClass18->ptr_000044 = class23_AllocatedNamedBuffer(class23_instance, pClass18->ptr_000044, 768, pClass18->sContainerName);
  locked_fread(pClass18->ptr_000044, 1u, 0x300u, f);

LABEL_35:
  pClass18->ptr_000040 = 0;
  goto LABEL_36;
 }

 pClass18->ptr_000044 = 0;
 if (uSomeInt != 2)
   goto LABEL_35;

 pClass18->ptr_000040 = class23_AllocatedNamedBuffer(class23_instance, pClass18->ptr_000040, 512, pClass18->sContainerName);
 for (i = 0; i < 256; ++i)
 {
  locked_fread(aReadBuf, 3, 1, f);

  pClass18->ptr_000040[i] = (aReadBuf[0] >> (8 - _this->byte_011B8C[0])) << (_this->byte_011B94[0] + _this->byte_011B90[0]);
  pClass18->ptr_000040[i] += (aReadBuf[1] >> (8 - _this->byte_011B90[0])) << *(unsigned int *)(_this->byte_011B94);
  pClass18->ptr_000040[i] += aReadBuf[2] >> (8 - _this->byte_011B94[0]);
 }

LABEL_36:
 if (pClass18->byte_00002C[0] & 2)
 {
    v34 = *((_DWORD *)v8 + 4);
    v35 = v34 + *((_DWORD *)v8 + 12);
    *((_DWORD *)v8 + 13) = v35;
    v36 = (v34 >> 2) + v35;
    *((_DWORD *)v8 + 14) = v36;
    v33 = v36 + (v34 >> 4);
 }
 else
 {
  v33 = 0;
  pClass18->dword_000034 = 0;
  pClass18->dword_000038 = 0;
 }

 pClass18->dword_00003C = v33;
 v40 = 1;
 while (1 << v40 != pClass18->word_000018)
 {
  ++v40;
  if (v40 >= 15)
    goto LABEL_48;
 }
 pClass18->word_00001C = v40;

LABEL_48:
 v41 = 1;
 while ( 1 << v41 != pClass18->word_00001A)
 {
  ++v41;
  if ( v41 >= 15 )
    goto LABEL_53;
 }
 pClass18->word_00001E = v41;

LABEL_53:
 switch (pClass18->word_00001C)
 {
  case 2:   *((_WORD *)v8 + 16) = 3;    break;
  case 3:   *((_WORD *)v8 + 16) = 7;    break;
  case 4:   *((_WORD *)v8 + 16) = 15;   break;
  case 5:   *((_WORD *)v8 + 16) = 31;   break;
  case 6:   *((_WORD *)v8 + 16) = 63;   break;
  case 7:   *((_WORD *)v8 + 16) = 127;  break;
  case 8:   *((_WORD *)v8 + 16) = 255;  break;
  case 9:   *((_WORD *)v8 + 16) = 511;  break;
  case 10:  *((_WORD *)v8 + 16) = 1023; break;
  case 11:  *((_WORD *)v8 + 16) = 2047; break;
  case 12:  *((_WORD *)v8 + 16) = 4095; break;
 }

 switch (pClass18->word_00001E)
 {
  case 2:   *((_WORD *)v8 + 17) = 3;    break;
  case 3:   *((_WORD *)v8 + 17) = 7;    break;
  case 4:   *((_WORD *)v8 + 17) = 15;   break;
  case 5:   *((_WORD *)v8 + 17) = 31;   break;
  case 6:   *((_WORD *)v8 + 17) = 63;   break;
  case 7:   *((_WORD *)v8 + 17) = 127;  break;
  case 8:   *((_WORD *)v8 + 17) = 255;  break;
  case 9:   *((_WORD *)v8 + 17) = 511;  break;
  case 10:  *((_WORD *)v8 + 17) = 1023; break;
  case 11:  *((_WORD *)v8 + 17) = 2047; break;
  case 12:  *((_WORD *)v8 + 17) = 4095; break;
 }

 return 1;
}






//----- (MM7.exe::0040F5BE) --------------------------------------------------------
void *class18_ctor(struct class18 *_this)
{
 _this->sContainerName[0] = 0;

 *(_DWORD *)((char *)_this + 16) = 0;
 *(_DWORD *)((char *)_this + 20) = 0;
 *(_WORD *)((char *)_this + 26) = 0;
 *(_WORD *)((char *)_this + 24) = 0;
 *(_WORD *)((char *)_this + 30) = 0;
 *(_WORD *)((char *)_this + 28) = 0;
 *(_WORD *)((char *)_this + 36) = 0;
 *(_WORD *)((char *)_this + 38) = 0;
 *(_DWORD *)((char *)_this + 48) = 0;
 *(_DWORD *)((char *)_this + 60) = 0;
 *(_DWORD *)((char *)_this + 56) = 0;
 *(_DWORD *)((char *)_this + 52) = 0;
 *(_DWORD *)((char *)_this + 64) = 0;
 *(_DWORD *)((char *)_this + 68) = 0;

 return _this;
}

//----- (MM7.exe::004C3190) --------------------------------------------------------
int class19_fn0(struct class19 *_this, int a2, const char *a3, int a4)
{
  int v4; // edi@1
  int v5; // esi@1
  signed int result; // eax@5
  int v8; // eax@10

  v4 = a2;
  v5 = _this;
  if ( a3 && *(_BYTE *)a3 == "1.1.3"[0] && a4 == 56 )
  {
    if (_this)
    {
     //*(_DWORD *)(a1 + 24) = 0;
     _this->pStatus = 0;

     if (!_this->pFunction1)
     {
      _this->pFunction1 = call_new;
      _this->dword_000028 = 0;
      //*(_DWORD *)(a1 + 32) = call_new;
      //*(_DWORD *)(a1 + 40) = 0;
     }
     //if ( !*(_DWORD *)(a1 + 36) )
     //  *(_DWORD *)(a1 + 36) = sub_4C5910;
     if (!_this->pFunction2)
       _this->pFunction2 = call_delete;

      //v8 = (*(int (__fastcall **)(_DWORD, signed int, signed int))(a1 + 32))(*(_DWORD *)(a1 + 40), 1, 24);
      v8 = (_this->pFunction1)(_this->dword_000028, 1, 24);

      //*(_DWORD *)(v5 + 28) = v8;
      _this->class20_obj = v8;

      if (_this->class20_obj)
      {
       _this->class20_obj->class21_obj = 0;
       //*(_DWORD *)(v8 + 20) = 0;
       _this->class20_obj->dword_00000C = 0;
       //*(_DWORD *)(*(_DWORD *)(v5 + 28) + 12) = 0;
       if (v4 < 0)
       {
        v4 = -v4;
        //*(_DWORD *)(*(_DWORD *)(v5 + 28) + 12) = 1;
        _this->class20_obj->dword_00000C = 1;
       }

       if (v4 < 8 || v4 > 15)
       {
        class19_fn1(_this);
        result = -2;
       }
       else
       {
        _this->class20_obj->dword_000010 = v4;
        // *(_DWORD *)(*(_DWORD *)(v5 + 28) + 16) = v4;
         //*(_DWORD *)(*(_DWORD *)(v5 + 28) + 20) = sub_4C4A30(
        _this->class20_obj->class21_obj = class19_AllocClass21Obj(_this,
                                                                  _this->class20_obj->dword_00000C == 0 ? (int)sub_4C57C0 : 0,
                                                                  1 << v4);
        if (_this->class20_obj->class21_obj)
        {
         class19_fn2(_this);
         result = 0;
        }
        else
        {
         class19_fn1(_this);
         result = -4;
        }
       }
      }
      else
      {
        result = -4;
      }
    }
    else
    {
      result = -2;
    }
  }
  else
  {
    result = -6;
  }
  return result;
}

//----- (MM7.exe::004C3150) --------------------------------------------------------
int class19_fn1(struct class19 *_this)
{
  struct class20 *v2; // eax@2
  struct class21 *v3; // ecx@4

  if (!_this)
    return -2;

  v2 = _this->class20_obj;
  if (_this && v2 && _this->pFunction2)
  {
   v3 = v2->class21_obj;
   if (v3)
     class21_fn0(v3, _this);

   (_this->pFunction2)(_this->dword_000028, _this->class20_obj);
   _this->class20_obj = 0;
   return 0;
  }
  else return -2;
}

//----- (MM7.exe::004C3110) --------------------------------------------------------
int class19_fn2(struct class19 *_this)
{
  struct class20 *v1; // eax@2

  if (!_this)
    return -2;

  v1 = _this->class20_obj;
  if (_this->class20_obj)
  {
    //*(_DWORD *)(this + 20) = 0;
   _this->dword_000014 = 0;
    //*(_DWORD *)(this + 8) = 0;
   _this->dword_000008 = 0;
    //*(_DWORD *)(this + 24) = 0;
   _this->pStatus = 0;
    //*(_DWORD *)v1 = *(_DWORD *)(v1 + 12) != 0 ? 7 : 0;
   v1->dword_000000 = v1->dword_00000C ? 7 : 0;
    //sub_4C49C0(*(_DWORD *)(*(_DWORD *)(this + 28) + 20), this, 0);
   class21_fn1(v1->class21_obj, _this, 0);
   return 0;
  }
  else return -2;
}

//----- (MM7.exe::004C32D0) --------------------------------------------------------
int class19_fn3(struct class19 *_this, int a2)
{
  int v3; // ebx@4
  signed int v4; // ebp@4
  int v5; // edi@4
  struct class20 *v6; // eax@5
  //struct class20 *v8; // eax@7
  int v9; // ecx@7
  int v16; // eax@17
  struct class20 *v17; // eax@22
  int v18; // eax@25
  int v19; // ecx@26
  int v20; // edx@26
  int v21; // edx@26
  int v22; // eax@27
  int v23; // ecx@28
  int v24; // eax@29
  int v25; // ecx@30
  int v26; // eax@31
  int v27; // eax@32
  int v28; // ecx@32
  int v29; // edx@32
  int v30; // eax@32
  int v31; // edx@33
  signed int result; // eax@36
  int v34; // ecx@37
  int v35; // ecx@37
  int v37; // edx@40
  int v38; // edx@40
  int v40; // ecx@43
  int v42; // ecx@46
  int v43; // edx@46
  int v44; // eax@46
  int v45; // eax@46
  int v46; // eax@47
  int v47; // [sp+10h] [bp-4h]@4

 if (!_this || !_this->class20_obj || !_this->pCompressedData)
   return -2;

 v5 = -5;
 v3 = ((a2 != 4) - 1) & 0xFFFFFFFB;
 v4 = 5;
 v47 = ((a2 != 4) - 1) & 0xFFFFFFFB;

 while ( 2 )
 {
  v6 = _this->class20_obj;

  switch (v6->dword_000000)
  {
   case 0:
     if (!_this->uCompressedDataSize)
       goto LABEL_36;

     _this->uCompressedDataSize--;
     v5 = v3;

     _this->dword_000008++;
     v6->dword_000004 = *_this->pCompressedData++;

     v9 = v6->dword_000004 & 0x0F;
     if (v9 != 8)
     {
      v6->dword_000000 = 13;
      _this->pStatus = "unknown compression method";
      v6->dword_000004 = v4;
      return -3;
     }
     else if ((unsigned int)((v6->dword_000004 / 16) + 8) > v6->dword_000010)
     {
      v6->dword_000000 = 13;
      _this->pStatus = "invalid window size";
      v6->dword_000004 = v4;
      return -3;
     }

     v6->dword_000000 = 1;

LABEL_12:
     if (!_this->uCompressedDataSize)
       return v5;

     v5 = v3;
     _this->dword_000008++;
     v9 = *_this->pCompressedData++;
     _this->uCompressedDataSize--;

     if ((v9 + v6->dword_000004 * 256) % 0x1F)
     {
      v6->dword_000000 = 13;
      _this->pStatus = "incorrect header check";
      v6->dword_000004 = 5;
      return -3;
     }

     if (!(v9 & 0x20))
     {
      v6->dword_000000 = 7;
      v3 = v47;
      v4 = 5;
      continue;
     }
     v3 = v47;
     v4 = 5;
     //**(_DWORD **)(v2 + 28) = 2;
     _this->class20_obj->dword_000000 = 2;

LABEL_35:
     if (_this->uCompressedDataSize)
     {
      v34 = _this->pCompressedData;
      _this->dword_000008++;
      //*(_DWORD *)(v2 + 4) = v32 - 1;
      _this->uCompressedDataSize--;
      v5 = v3;
      //*(_DWORD *)(*(_DWORD *)(v2 + 28) + 8) = *(_BYTE *)v34 << 24;
      _this->class20_obj->dword_000008 = (int)(*_this->pCompressedData) << 24;
      //v35 = *(_DWORD *)(v2 + 28);
      //++*(_DWORD *)v2;
      //*(_DWORD *)v35 = 3;
      v35 = _this->class20_obj;
      _this->pCompressedData++;
      _this->class20_obj->dword_000000 = 3;

LABEL_38:
      if (_this->uCompressedDataSize)
      {
       //v37 = *(_DWORD *)v2;
       v37 = _this->pCompressedData;
       //*(_DWORD *)(v2 + 4) = v36 - 1;
       _this->uCompressedDataSize--;

       //++*(_DWORD *)(v2 + 8);
       _this->dword_000008++;
       v5 = v3;
       //*(_DWORD *)(*(_DWORD *)(v2 + 28) + 8) += *(_BYTE *)v37 << 16;
       //v38 = *(_DWORD *)(v2 + 28);
       //++*(_DWORD *)v2;
       //*(_DWORD *)v38 = 4;
       _this->class20_obj->dword_000008 += (int)(*_this->pCompressedData) << 16;

LABEL_41:
       if (_this->uCompressedDataSize)
       {
        //v40 = *(_DWORD *)v2;
        //*(_DWORD *)(v2 + 4) = v39 - 1;
        //++*(_DWORD *)(v2 + 8);
        v40 = _this->pCompressedData;
        _this->uCompressedDataSize--;
        _this->dword_000008++;
        v5 = v3;
        //*(_DWORD *)(*(_DWORD *)(v2 + 28) + 8) += *(_BYTE *)v40 << 8;
        //++*(_DWORD *)v2;
        //**(_DWORD **)(v2 + 28) = v4;
        _this->class20_obj->dword_000008 += (int)(*_this->pCompressedData) << 8;

LABEL_44:
        if (_this->uCompressedDataSize)
        {
         //v42 = *(_DWORD *)v2;
         //v43 = *(_DWORD *)(v2 + 8) + 1;
         //*(_DWORD *)(v2 + 4) = v41 - 1;
         //v44 = *(_DWORD *)(v2 + 28);
         v42 = _this->pCompressedData;
         v43 = _this->dword_000008 + 1;
         _this->uCompressedDataSize--;
         v44 = _this->class20_obj;
         //*(_DWORD *)(v2 + 8) = v43;
         //*(_DWORD *)(v44 + 8) += *(_BYTE *)v42;
         //++*(_DWORD *)v2;
         _this->dword_000008++;
         _this->class20_obj->dword_000008 += *_this->pCompressedData++;
         //v45 = *(_DWORD *)(v2 + 28);
         //*(_DWORD *)(v2 + 48) = *(_DWORD *)(v45 + 8);
         //*(_DWORD *)v45 = 6;
         v45 = _this->class20_obj;
         _this->dword_00002C = _this->class20_obj->dword_000008;
         _this->class20_obj->dword_000000 = 6;
         result = 2;
        }
        else
        {
         result = v5;
        }
       }
       else
       {
        result = v5;
       }
      }
      else
      {
       result = v5;
      }
     }
     else
     {
LABEL_36:
      result = v5;
     }
     return result;

   case 1:
     goto LABEL_12;

   case 7:
    v16 = class21_fn2(v6->class21_obj, _this, v5);
    //v16 = -3;
    v5 = v16;
    if ( v16 == -3 )
    {
     //**(_DWORD **)(v2 + 28) = 13;
     //*(_DWORD *)(*(_DWORD *)(v2 + 28) + 4) = 0;
     _this->class20_obj->dword_000000 = 13;
     _this->class20_obj->dword_000004 = 0;
    }
    else
    {
     if (!v16)
       v5 = v3;
     if (v5 != 1)
       goto LABEL_36;
     v5 = v3;
     //class21_fn1(*(_DWORD *)(*(_DWORD *)(v2 + 28) + 20), v2, *(_DWORD *)(v2 + 28) + 4);
     //v17 = *(_DWORD *)(v2 + 28);
     class21_fn1(_this->class20_obj->class21_obj, _this, &_this->class20_obj->dword_000004);
     v17 = _this->class20_obj;

     //if (*(_DWORD *)(v17 + 12))
       //*(_DWORD *)v17 = 12;
     if (_this->class20_obj->dword_00000C)
       _this->class20_obj->dword_000000 = 12;
     else
     {
      //*(_DWORD *)v17 = 8;
      _this->class20_obj->dword_000000 = 8;

LABEL_25:
      //v18 = *(_DWORD *)(v2 + 4);
      v18 = _this->uCompressedDataSize;
      if (!_this->uCompressedDataSize)
        goto LABEL_36;

      //v19 = *(_DWORD *)(v2 + 28);
      //++*(_DWORD *)(v2 + 8);
      //v20 = *(_DWORD *)v2;
      //*(_DWORD *)(v2 + 4) = v18 - 1;
      v19 = _this->class20_obj;
      _this->dword_000008++;
      v20 = _this->pCompressedData;
      _this->uCompressedDataSize--;
      v5 = v3;
      //*(_DWORD *)(v19 + 8) = *(_BYTE *)v20 << 24;
      //v21 = *(_DWORD *)(v2 + 28);
      //++*(_DWORD *)v2;
      //*(_DWORD *)v21 = 9;
      _this->class20_obj->dword_000008 = (unsigned int)(*_this->pCompressedData++) << 24;
      v21 = _this->class20_obj;
      _this->class20_obj->dword_000000 = 9;

LABEL_27:
      //v22 = *(_DWORD *)(v2 + 4);
      //if (!v22)
      v22 = _this->uCompressedDataSize;
      if (!_this->uCompressedDataSize)
        goto LABEL_36;

      //v23 = *(_DWORD *)v2;
      //++*(_DWORD *)(v2 + 8);
      //*(_DWORD *)(v2 + 4) = v22 - 1;
      v23 = _this->pCompressedData;
      _this->dword_000008++;
      _this->uCompressedDataSize--;
      v5 = v3;
      //*(_DWORD *)(*(_DWORD *)(v2 + 28) + 8) += *(_BYTE *)v23 << 16;
      //++*(_DWORD *)v2;
      //**(_DWORD **)(v2 + 28) = 10;
      _this->class20_obj->dword_000008 += (unsigned int)(*_this->pCompressedData++) << 16;
      _this->class20_obj->dword_000000 = 10;


LABEL_29:
      //v24 = *(_DWORD *)(v2 + 4);
      //if ( !v24 )
      v24 = _this->uCompressedDataSize;
      if (!_this->uCompressedDataSize)
        goto LABEL_36;

      //v25 = *(_DWORD *)v2;
      //++*(_DWORD *)(v2 + 8);
      //*(_DWORD *)(v2 + 4) = v24 - 1;
      v25 = _this->pCompressedData;
      _this->dword_000008++;
      _this->uCompressedDataSize--;
      v5 = v3;
      //*(_DWORD *)(*(_DWORD *)(v2 + 28) + 8) += *(_BYTE *)v25 << 8;
      //++*(_DWORD *)v2;
      //**(_DWORD **)(v2 + 28) = 11;
      _this->class20_obj->dword_000008 += (unsigned int)(*_this->pCompressedData++) << 8;
      _this->class20_obj->dword_000000 = 11;

LABEL_31:
      //v26 = *(_DWORD *)(v2 + 4);
      //if ( !v26 )
      v26 = _this->uCompressedDataSize;
      if (!_this->uCompressedDataSize)
        goto LABEL_36;

      //v28 = *(_DWORD *)v2;
      //v29 = *(_DWORD *)(v2 + 8) + 1;
      //*(_DWORD *)(v2 + 4) = v26 - 1;
      //v30 = *(_DWORD *)(v2 + 28);
      //*(_DWORD *)(v2 + 8) = v29;
      v28 = _this->pCompressedData;
      v29 = _this->dword_000008 + 1;
      v30 = _this->class20_obj;
      _this->uCompressedDataSize--;
      _this->dword_000008++;

      v5 = v3;
      //*(_DWORD *)(v30 + 8) += *(_BYTE *)v28;
      //++*(_DWORD *)v2;
      //v27 = *(_DWORD *)(v2 + 28);
      _this->class20_obj->dword_000008 += *_this->pCompressedData++;
      v27 = _this->class20_obj;

      //if ( *(_DWORD *)(v27 + 4) == *(_DWORD *)(v27 + 8) )
      if (_this->class20_obj->dword_000004 == _this->class20_obj->dword_000008)
      {
       //**(_DWORD **)(v2 + 28) = 12;
       _this->class20_obj->dword_000000 = 12;
       return 1;
      }
      //*(_DWORD *)v27 = 13;
      //v31 = *(_DWORD *)(v2 + 28);
      //*(_DWORD *)(v2 + 24) = "incorrect data check";
      //*(_DWORD *)(v31 + 4) = v4;
      _this->class20_obj->dword_000000 = 13;
      v31 = _this->class20_obj;
      _this->pStatus = "incorrect data check";
      _this->class20_obj->dword_000004 = v4;
     }
    }
    continue;

  case 8:
    goto LABEL_25;

  case 9:
    goto LABEL_27;

  case 0xA:
    goto LABEL_29;

  case 0xB:
    goto LABEL_31;

  case 2:
    goto LABEL_35;

  case 3:
    goto LABEL_38;

  case 4:
    goto LABEL_41;

  case 5:
    goto LABEL_44;

  case 6:
    _this->class20_obj->dword_000000 = 13;
    v46 = _this->class20_obj;
    _this->pStatus = "need dictionary";
    _this->class20_obj->dword_000004 = 0;
    return -2;

  case 0xC:
    return 1;
  case 0xD:
    return -3;

  default:
    return -2;
  }
 }
}

//----- (MM7.exe004C4A30) --------------------------------------------------------
struct class21 *class19_AllocClass21Obj(struct class19 *_this, int (__fastcall *pSomeFn)(unsigned int, int, unsigned int), int a3)
{
 int result; // eax@1
 struct class21 *v6; // esi@1
 int v8; // eax@5

 result = (_this->pFunction1)(_this->dword_000028, 1, 64);
 v6 = result;
 if (result)
 {
  v6->pArray_8x1440 = (_this->pFunction1)(_this->dword_000028, 8, 1440);
  if (v6->pArray_8x1440)
  {
   v8 = (_this->pFunction1)(_this->dword_000028, 1, a3);
   //*(_DWORD *)(v6 + 40) = v8;
   v6->dword_000028 = v8;
   if (v8)
   {
    v6->dword_00002C = a3 + v8;
    v6->pfn_000038 = pSomeFn;
    v6->dword_000000 = 0;
    class21_fn1(v6, _this, 0);
    return v6;
   }
   else
   {
    (_this->pFunction2)(_this->dword_000028, v6->pArray_8x1440);
    (_this->pFunction2)(_this->dword_000028, v6);
    return 0;
   }
  }
  else
  {
   (_this->pFunction2)(_this->dword_000028, v6);
   return 0;
  }
 }
 return result;
}

//----- (MM7.exe::004C5790) --------------------------------------------------------
int class21_fn0(struct class21 *_this, struct class19 *pParent)
{
  int v3; // esi@1
  int v4; // edi@1

  v3 = pParent;
  v4 = _this;
  class21_fn1(_this, pParent, 0);

  (pParent->pFunction2)(pParent->dword_000028, _this->dword_000028);
  (pParent->pFunction2)(pParent->dword_000028, _this->pArray_8x1440);
  (pParent->pFunction2)(pParent->dword_000028, _this);
  return 0;
}

//----- (MM7.exe::004C49C0) --------------------------------------------------------
int class21_fn1(struct class21 *_this, struct class19 *pParent, int *a3)
{
 int result; // eax@8

 if (a3)
   *a3 = _this->dword_00003C;

 if (_this->dword_000000 == 4 || _this->dword_000000)
  (pParent->pFunction2)(pParent->dword_000028, _this->dword_00000C);
 else if (_this->dword_000000 == 6)
   (pParent->pFunction2)(pParent->dword_000028, _this->class27_obj);

 _this->dword_000000 = 0;
 _this->pDecompressionBufferHead = _this->dword_000028;
 _this->pDecompressionBufferTail = _this->dword_000028;

 _this->dword_00001C = 0;
 _this->dword_000020 = 0;

 if (_this->pfn_000038)
 {
  result = (_this->pfn_000038)(0, 0, 0);
  pParent->dword_000030 = result;
  _this->dword_00003C = result;

  return result;
 }
 return 0;
}

//----- (MM7.exe::004C4AD0) --------------------------------------------------------
int class21_fn2(struct class21 *_this, struct class19 *pParent, int a3)
{
  unsigned int v3; // eax@1
  unsigned int v4; // ecx@1
  int v6; // ebp@1
  unsigned int v8; // esi@6
  unsigned int   uDataSize; // eax@7
  unsigned char *pDataPtr; // edi@7
  int v11; // edx@9
  int v12; // ebp@13
  int v13; // ecx@13
  const void *v15; // eax@17
  unsigned int v16; // edi@17
  unsigned int v17; // esi@17
  int v18; // edx@19
  unsigned int v19; // edi@23
  int v20; // ecx@24
  void *v21; // edx@25
  void *v22; // ecx@25
  unsigned int v23; // eax@26
  unsigned int v24; // esi@26
  unsigned int v25; // edx@31
  unsigned int v26; // esi@31
  int v27; // eax@31
  int v28; // eax@34
  unsigned int v29; // eax@35
  unsigned int v30; // eax@42
  int v31; // edx@46
  int v32; // ecx@46
  unsigned int v33; // edi@48
  int v36; // edx@51
  int v37; // eax@52
  int v38; // ecx@52
  unsigned int v41; // edi@55
  char v43; // cl@61
  int v44;
  int v47; // ST14_4@65
  int v48; // ecx@65
  int v50; // edx@71
  unsigned int v51; // eax@72
  int v52; // edx@72
  int v53; // ecx@72
  int v54; // eax@72
  int v55; // eax@73
  int v56; // ecx@74
  int v57; // eax@76
  int v58; // eax@76
  int v59; // edx@78
  unsigned int v60; // edi@80
  int v61; // eax@80
  int v62; // ecx@83
  unsigned int v64; // ecx@87
  int v68; // eax@91
  const void *v69; // ebp@91
  int v70; // edi@91
  unsigned int v71; // eax@92
  void *v72; // ecx@92
  const void *v73; // edi@92
  int v74; // eax@93
  int result; // eax@97
  int v76; // ebp@97
  int v77; // esi@97
  int v78; // esi@98
  int v79; // ecx@98
  int v80; // esi@99
  int v81; // ecx@99
  int v82; // edi@100
  int v83; // esi@100
  int v85; // esi@102
  int v86; // ecx@102
  int v87; // ebp@103
  int v88; // esi@103
  int v89; // edi@104
  int v90; // esi@104
  int v91; // edi@105
  int v92; // edx@105
  unsigned int v93; // eax@106
  int v94; // edx@107
  int v95; // ecx@107
  const void *v96; // edi@110
  int v97; // ecx@110
  int v98; // ecx@111
  int v99; // edx@111
  const void *v100; // edi@112
  int v101; // edx@112
  const void *v102; // edi@115
  int v103; // edx@115
  const void *v104; // edi@116
  int v105; // ecx@116
  void *v106; // ecx@119
  const void *v107; // ebp@120
  const void *v108; // ebp@124
  int v109; // edx@124
  int v110; // edi@127
  int v111; // esi@127
  int v112; // edi@128
  int v113; // esi@128

  const void *v114; // [sp+10h] [bp-38h]@1
  unsigned int v115; // [sp+14h] [bp-34h]@1
  void *v116; // [sp+18h] [bp-30h]@1
  unsigned int v117; // [sp+1Ch] [bp-2Ch]@1
  int v118; // [sp+1Ch] [bp-2Ch]@65
  int v119; // [sp+1Ch] [bp-2Ch]@72
  int v120; // [sp+1Ch] [bp-2Ch]@80
  int v121; // [sp+1Ch] [bp-2Ch]@87
  int v122; // [sp+20h] [bp-28h]@1
  unsigned int v123; // [sp+24h] [bp-24h]@4
  int v124; // [sp+28h] [bp-20h]@34
  int v125; // [sp+2Ch] [bp-1Ch]@14
  int v126; // [sp+30h] [bp-18h]@14
  int v127; // [sp+34h] [bp-14h]@14

  int v128; // [sp+38h] [bp-10h]@14
  unsigned int v129; // [sp+3Ch] [bp-Ch]@72
  unsigned int *v130; // [sp+40h] [bp-8h]@87
  unsigned int *v131; // [sp+44h] [bp-4h]@87
  int v132; // [sp+4Ch] [bp+4h]@31

 v114 = pParent->pCompressedData;
 v115 = pParent->uCompressedDataSize;
 v122 = pParent;
 v3 = _this->pDecompressionBufferHead;
 v4 = _this->pDecompressionBufferTail;
 v6 = _this->dword_00001C;
 v116 = _this->pDecompressionBufferTail;
 v117 = _this->dword_000020;

 if (v4 >= v3)
   v123 = _this->dword_00002C - (unsigned int)_this->pDecompressionBufferTail;
 else
   v123 = _this->pDecompressionBufferHead - _this->pDecompressionBufferTail - 1;

 while (2)
 {
  switch (_this->dword_000000)
  {
   case 0:
     v8 = v117;

     if (v6 >= 3)
     {
      pDataPtr = v114;
LABEL_12:

      _this->bDecompressionComplete = v8 & 1;
      switch ((v117 & 7) >> 1)
      {
       case 0u:
         v12 = v6 - 3;
         _this->dword_000000 = 1;
         v13 = v12 & 7;
         v6 = v12 - v13;
         v117 = v8 >> 3 >> v13;
         continue;

        case 1u:
          sub_4C8340((int)&v128, (int)&v127, (int)&v126, (int)&v125, pParent);
          _this->class27_obj = AllocateClass27(v128, v127, v126, v125, pParent);
          if (_this->class27_obj)
          {
           v117 = v8 >> 3;
           v6 -= 3;
           _this->dword_000000 = 6;
           continue;
          }
          _this->dword_00001C = v6;
          _this->dword_000020 = v8;

          v78 = pParent->pCompressedData;
          pParent->uCompressedDataSize = v115;
          v79 = pParent->dword_000008;
          pParent->pCompressedData = pDataPtr;
          pParent->dword_000008 = pDataPtr + v79 - v78;

          _this->pDecompressionBufferTail = v116;
          result = class21_fn3(_this, pParent, -4);
        break;

        case 2u:
              v117 = v8 >> 3;
              v6 -= 3;
              _this->dword_000000 = 3;
              continue;
        case 3u:
              _this->dword_000000 = 9;
              pParent->pStatus = "invalid block type";
              _this->dword_00001C = v6 - 3;
              _this->dword_000020 = v8 >> 3;
              v80 = pParent->dword_000008;
              v81 = (int)(pDataPtr - pParent->pCompressedData);
              pParent->uCompressedDataSize = v115;
              pParent->dword_000008 = v81 + v80;
              pParent->pCompressedData = pDataPtr;
              _this->pDecompressionBufferTail = v116;
              return class21_fn3(_this, pParent, -3);
            default:
              continue;
          }
        }
        else
        {
          uDataSize = v115;
          pDataPtr = v114;
          while ( uDataSize-- )
          {
            a3 = 0;
            v11 = *pDataPtr++ << v6;
            v6 += 8;
            v115 = uDataSize;
            v8 |= v11;
            v117 = v8;
            v114 = pDataPtr;
            if ( (unsigned int)v6 >= 3 )
              goto LABEL_12;
          }
          _this->dword_00001C = v6;
          _this->dword_000020 = v8;
          v76 = pParent->pCompressedData;
          v77 = pParent->dword_000008;
          pParent->uCompressedDataSize = 0;
          pParent->pCompressedData = pDataPtr;
          pParent->dword_000008 = pDataPtr + v77 - v76;
          _this->pDecompressionBufferTail = v116;
          result = class21_fn3(_this, pParent, a3);
        }
        return result;
      case 1:
        v17 = v117;
        v16 = v115;
        v15 = v114;
        if ( (unsigned int)v6 >= 0x20 )
          goto LABEL_20;
        do
        {
          if ( !v16 )
          {
            _this->dword_00001C = v6;
            _this->dword_000020 = v17;
            v82 = pParent->pCompressedData;
            v83 = pParent->dword_000008;
            pParent->uCompressedDataSize = 0;
            pParent->pCompressedData = v15;
            pParent->dword_000008 = (char *)v15 + v83 - v82;
            _this->pDecompressionBufferTail = v116;
            return class21_fn3(_this, pParent, a3);
          }
          a3 = 0;
          v18 = *(_BYTE *)v15 << v6;
          --v16;
          v6 += 8;
          v115 = v16;
          v17 |= v18;
          v15 = (char *)v15 + 1;
          v114 = v15;
        }
        while ( (unsigned int)v6 < 0x20 );
LABEL_20:
        if ( (unsigned __int16)v17 != ~v17 >> 16 )
        {
          _this->dword_000000 = 9;
          pParent->pStatus = "invalid stored block lengths";
          _this->dword_00001C = v6;
          _this->dword_000020 = v17;
          pParent->uCompressedDataSize = v16;
          goto LABEL_127;
        }
        v6 = 0;
        _this->class27_obj = v17;
        v117 = 0;
        if ( (_WORD)v17 )
        {
         _this->dword_000000 = 2;
          continue;
        }
LABEL_47:
        _this->dword_000000 = _this->bDecompressionComplete ? 7 : 0;
        continue;
      case 2:
        v19 = v115;
        if ( !v115 )
        {
          _this->dword_00001C = v6;
          _this->dword_000020 = v117;
          v85 = pParent->dword_000008;
          v86 = (int)((char *)v114 - pParent->pCompressedData);
          pParent->pCompressedData = v114;
          pParent->uCompressedDataSize = 0;
          pParent->dword_000008 = v86 + v85;
          _this->pDecompressionBufferTail = v116;
          return class21_fn3(_this, pParent, a3);
        }
        v20 = v123;
        if ( v123
          || (v22 = _this->dword_00002C, v21 = v116, v116 == v22)
          && (v23 = _this->pDecompressionBufferHead, v24 = _this->dword_000028, v23 != v24)
          && ((v21 = _this->dword_000028, v116 = _this->dword_000028, v24 >= v23) ? (v20 = (int)((char *)v22 - v24)) : (v20 = v23 - v24 - 1),
              v123 = v20,
              v20) )
          goto LABEL_42;
        _this->pDecompressionBufferTail = v21;
        v27 = class21_fn3(_this, pParent, a3);
        v25 = _this->pDecompressionBufferTail;
        v26 = _this->pDecompressionBufferHead;
        v132 = v27;
        v116 = _this->pDecompressionBufferTail;
        if ( v25 >= v26 )
          v20 = _this->dword_00002C - v25;
        else
          v20 = v26 - v25 - 1;
        v28 = _this->dword_00002C;
        v123 = v20;
        v124 = v28;
        if ( v25 == v28 )
        {
          v29 = _this->dword_000028;
          if ( v26 != v29 )
          {
            v25 = _this->dword_000028;
            v116 = _this->dword_000028;
            if ( v29 >= v26 )
              v20 = v124 - v29;
            else
              v20 = v26 - v29 - 1;
            v123 = v20;
          }
        }
        if ( !v20 )
        {
          _this->dword_00001C = v6;
          _this->dword_000020 = v117;
          v87 = pParent->pCompressedData;
          v88 = pParent->dword_000008;
          pParent->uCompressedDataSize = v115;
          pParent->pCompressedData = v114;
          pParent->dword_000008 = (char *)v114 + v88 - v87;
          _this->pDecompressionBufferTail = v25;
          return class21_fn3(_this, pParent, v132);
        }
        v19 = v115;
LABEL_42:
        v30 = _this->class27_obj;
        a3 = 0;
        if ( v30 > v19 )
          v30 = v19;
        if ( v30 > v20 )
          v30 = v20;
        memcpy(v116, v114, 4 * (v30 >> 2));
        v31 = v123 - v30;
        memcpy((char *)v116 + 4 * (v30 >> 2), (char *)v114 + 4 * (v30 >> 2), v30 & 3);
        v114 = (char *)v114 + v30;
        v32 = (char *)_this->class27_obj - v30;
        v115 -= v30;
        v116 = (char *)v116 + v30;
        v123 = v31;
        _this->class27_obj = v32;
        if ( !v32 )
          goto LABEL_47;
        continue;
      case 3:
        v33 = v117;
        if ( (unsigned int)v6 >= 0xE )
          goto LABEL_52;

        uDataSize = v115;
        pDataPtr = v114;
        do
        {
         if (!uDataSize)
         {
            _this->dword_00001C = v6;
            _this->dword_000020 = v33;
            v89 = pParent->pCompressedData;
            v90 = pParent->dword_000008;
            pParent->pCompressedData = v114;
            pParent->uCompressedDataSize = 0;
            pParent->dword_000008 = (char *)v114 + v90 - v89;
            _this->pDecompressionBufferTail = v116;
            return class21_fn3(_this, pParent, a3);
         }

         a3 = 0;
         v36 = *pDataPtr++ << v6;
         v6 += 8;
         v115 = --uDataSize;
         v33 |= v36;
         v114 = pDataPtr;
        }
        while ( (unsigned int)v6 < 0xE );
LABEL_52:
        v37 = v33 & 0x3FFF;
        _this->class27_obj = v37;
        v38 = v33 & 0x1F;
        if ( (unsigned int)v38 > 0x1D || (v37 & 0x3E0u) > 0x3A0 )
        {
          v93 = v115;
          _this->dword_000000 = 9;
          pParent->pStatus = "too many length or distance symbols";
          _this->dword_00001C = v6;
          _this->dword_000020 = v33;
LABEL_126:
          pParent->uCompressedDataSize = v93;
          v15 = v114;
LABEL_127:
          v110 = pParent->pCompressedData;
          v111 = pParent->dword_000008;
          pParent->pCompressedData = v15;
          pParent->dword_000008 = (char *)v15 + v111 - v110;
          _this->pDecompressionBufferTail = v116;
          result = class21_fn3(_this, pParent, -3);
        }
        else
        {
         _this->dword_00000C = (pParent->pFunction1)(pParent->dword_000028, (((unsigned int)v37 >> 5) & 0x1F) + v38 + 258, 4);
          if (!_this->dword_00000C)
          {
           _this->dword_00001C = v6;
           _this->dword_000020 = v33;
           v91 = pParent->pCompressedData;
           pParent->uCompressedDataSize = v115;
           v92 = pParent->dword_000008;
           pParent->pCompressedData = v114;
           pParent->dword_000008 = (char *)v114 + v92 - v91;
            _this->pDecompressionBufferTail = v116;
            return class21_fn3(_this, pParent, -4);
          }
          v41 = v33 >> 14;
          v6 -= 14;
          _this->dword_000008 = 0;
          _this->dword_000000 = 4;
LABEL_57:
          if (_this->dword_000008 < (unsigned int)(((unsigned int)_this->class27_obj >> 10) + 4) )
          {
            do
            {
              if ( (unsigned int)v6 < 3 )
              {
                pDataPtr = v114;
                do
                {
                  if ( !v115 )
                  {
                    _this->dword_00001C = v6;
                    _this->dword_000020 = v41;
                    v94 = pParent->dword_000008;
                    v95 = (int)((char *)v114 - pParent->pCompressedData);
                    pParent->pCompressedData = v114;
                    pParent->dword_000008 = v95 + v94;
                    pParent->uCompressedDataSize = 0;
                    _this->pDecompressionBufferTail = v116;
                    return class21_fn3(_this, pParent, a3);
                  }
                  --v115;
                  v43 = v6;
                  v6 += 8;
                  a3 = 0;
                  v41 |= *pDataPtr++ << v43;
                  v114 = pDataPtr;
                }
                while ( (unsigned int)v6 < 3 );
              }
              v44 = v41 & 7;
              v6 -= 3;
              v41 >>= 3;
              _this->dword_00000C[*(_DWORD *)&byte_4D8410[4 * _this->dword_000008 + 1712]] = v44;
              _this->dword_000008++;
            }
            while (_this->dword_000008 < (unsigned int)(((unsigned int)_this->class27_obj >> 10) + 4) );
          }
          if (_this->dword_000008 < 0x13u )
          {
            do
            {
              _this->dword_00000C[*(_DWORD *)&byte_4D8410[4 * _this->dword_000008 + 1712]] = 0;
              _this->dword_000008++;
            }
            while ( (unsigned int)_this->dword_000008 < 0x13 );
          }
          v48 = _this->dword_00000C;
          _this->dword_000010 = 7;
          v118 = sub_4C7C60(_this->dword_00000C, &_this->dword_000010, &_this->dword_000014, _this->pArray_8x1440, pParent);
          if ( v118 )
          {
           (pParent->pFunction2)(pParent->dword_000028, _this->dword_00000C);
            if ( v118 == -3 )
              _this->dword_000000 = 9;
            _this->dword_00001C = v6;
            _this->dword_000020 = v41;
            v96 = pParent->pCompressedData;
            pParent->uCompressedDataSize = v115;
            v97 = pParent->dword_000008;
            pParent->pCompressedData = v114;
            pParent->dword_000008 = (char *)v114 - v96 + v97;
            _this->pDecompressionBufferTail = v116;
            result = class21_fn3(_this, pParent, v118);
          }
          else
          {
           _this->dword_000008 = 0;
           _this->dword_000000 = 5;
LABEL_68:
            while ( _this->dword_000008 < (((unsigned int)_this->class27_obj >> 5) & 0x1F) + ((unsigned int)_this->class27_obj & 0x1Fu) + 258 )
            {
              if (v6 < _this->dword_000010)
              {
               pDataPtr = v114;
                while ( v115 )
                {
                  a3 = 0;
                  --v115;
                  v50 = *pDataPtr++ << v6;
                  v6 += 8;
                  v41 |= v50;
                  v114 = pDataPtr;
                  if ( v6 >= _this->dword_000010)
                    goto LABEL_72;
                }
                goto LABEL_111;
              }
LABEL_72:
              v53 = _this->dword_000014;
              v54 = v41 & dword_4F2688[_this->dword_000010];
              v52 = *(_BYTE *)(v53 + 8 * v54 + 1);
              v119 = *(_BYTE *)(v53 + 8 * v54 + 1);
              v51 = *(_DWORD *)(v53 + 8 * v54 + 4);
              v129 = v51;
              if ( v51 >= 0x10 )
              {
                v56 = 7;
                if ( v51 != 18 )
                  v56 = v51 - 14;
                v123 = v56;
                v58 = -(v51 != 18);
                LOBYTE(v58) = v58 & 0xF8;
                v124 = v52 + v56;
                v57 = v58 + 11;
                if ( v6 < (unsigned int)(v52 + v56) )
                {
                  while ( v115 )
                  {
                    a3 = 0;
                    --v115;
                    v59 = *pDataPtr++ << v6;
                    v6 += 8;
                    v41 |= v59;
                    v114 = pDataPtr;
                    if ( v6 >= (unsigned int)v124 )
                    {
                      v52 = v119;
                      goto LABEL_80;
                    }
                  }
LABEL_111:
                  _this->dword_00001C = v6;
                  _this->dword_000020 = v41;
                  v98 = pParent->dword_000008;
                  v99 = (int)((char *)v114 - pParent->pCompressedData);
                  pParent->pCompressedData = v114;
                  pParent->dword_000008 = v99 + v98;
                  pParent->uCompressedDataSize = 0;
                  _this->pDecompressionBufferTail = v116;
                  return class21_fn3(_this, pParent, a3);
                }
LABEL_80:
                v60 = v41 >> v52;
                v61 = (v60 & dword_4F2688[v123]) + v57;
                v41 = v60 >> v123;
                v120 = v61;
                v6 -= v52 + v123;
                v123 = _this->dword_000008;
                if ( v123 + v61 > (((unsigned int)_this->class27_obj >> 5) & 0x1F) + ((unsigned int)_this->class27_obj & 0x1Fu) + 258 )
                  goto LABEL_112;
                if ( v129 == 16 )
                {
                  v55 = v123;
                  if ( v123 < 1 )
                  {
LABEL_112:
                   (pParent->pFunction2)(pParent->dword_000028, _this->dword_00000C);
                    _this->dword_000000 = 9;
                    pParent->pStatus = "invalid bit length repeat";
                    _this->dword_00001C = v6;
                    _this->dword_000020 = v41;
                    v100 = pParent->pCompressedData;
                    pParent->uCompressedDataSize = v115;
                    v101 = pParent->dword_000008;
                    pParent->pCompressedData = v114;
                    pParent->dword_000008 = (char *)v114 - v100 + v101;
                    _this->pDecompressionBufferTail = v116;
                    return class21_fn3(_this, pParent, -3);
                  }
                  v62 = _this->dword_00000C[v123 - 1];
                }
                else
                {
                  v55 = v123;
                  v62 = 0;
                }
                do
                {
                  ++v55;
                  _this->dword_00000C[v55 - 1] = v62;
                }
                while ( v120-- != 1 );
              }
              else
              {
                v6 -= v52;
                v41 >>= v52;
                _this->dword_00000C[_this->dword_000008] = v51;
                v55 = _this->dword_000008 + 1;
              }
              _this->dword_000008 = v55;
            }
            v64 = _this->class27_obj;
            _this->dword_000014 = 0;
            v124 = 9;
            v123 = 6;
            v121 = sub_4C81E0(
                     (v64 & 0x1F) + 257,
                     ((v64 >> 5) & 0x1F) + 1,
                     _this->dword_00000C,
                     (unsigned int *)&v124,
                     &v123,
                     &v131,
                     &v130,
                     _this->pArray_8x1440,
                     pParent);
            //(*(void (__fastcall **)(_DWORD, _DWORD))(v39 + 36))(*(_DWORD *)(v39 + 40), _this->dword_00000C);
            (pParent->pFunction2)(pParent->dword_000028, _this->dword_00000C);
            if ( v121 )
            {
              if ( v121 == -3 )
                _this->dword_000000 = 9;
              _this->dword_00001C = v6;
              _this->dword_000020 = v41;
              v102 = pParent->pCompressedData;
              v103 = pParent->dword_000008;
              pParent->uCompressedDataSize = v115;
              pParent->pCompressedData = v114;
              pParent->dword_000008 = (char *)v114 - v102 + v103;
              _this->pDecompressionBufferTail = v116;
              result = class21_fn3(_this, pParent, v121);
            }
            else
            {
             _this->class27_obj = AllocateClass27(v124, v123, v131, v130, pParent);
              if (!_this->class27_obj)
              {
                _this->dword_00001C = v6;
                _this->dword_000020 = v41;
                v104 = pParent->pCompressedData;
                pParent->uCompressedDataSize = v115;
                v105 = pParent->dword_000008;
                pParent->pCompressedData = v114;
                pParent->dword_000008 = (char *)v114 - v104 + v105;
                _this->pDecompressionBufferTail = v116;
                return class21_fn3(_this, pParent, -4);
              }
              _this->dword_000000;
LABEL_91:
              _this->dword_00001C = v6;
              _this->dword_000020 = v41;
              v69 = pParent->pCompressedData;
              v70 = pParent->dword_000008;
              pParent->uCompressedDataSize = v115;
              pParent->pCompressedData = v114;
              pParent->dword_000008 = (char *)v114 - v69 + v70;
              _this->pDecompressionBufferTail = v116;
              v68 = class21_fn4(_this, pParent, a3);
              if ( v68 != 1 )
                return class21_fn3(_this, pParent, v68);
              a3 = 0;
              (pParent->pFunction2)(pParent->dword_000028, _this->class27_obj);
              v71 = _this->pDecompressionBufferHead;
              v73 = pParent->pCompressedData;
              v6 = _this->dword_00001C;
              v115 = pParent->uCompressedDataSize;
              v72 = _this->pDecompressionBufferTail;
              v114 = pParent->pCompressedData;
              v117 = _this->dword_000020;
              v116 = _this->pDecompressionBufferTail;
              if ( (unsigned int)v72 >= v71 )
                v74 = _this->dword_00002C - (_DWORD)v72;
              else
                v74 = v71 - (_DWORD)v72 - 1;
              v123 = v74;
              if (!_this->bDecompressionComplete)
              {
                _this->dword_000000 = 0;
                continue;
              }
              _this->dword_000000 = 7;
LABEL_119:
              _this->pDecompressionBufferTail = v72;
              v68 = class21_fn3(_this, pParent, a3);
              v106 = _this->pDecompressionBufferTail;
              if (_this->pDecompressionBufferHead != v106 )
              {
                _this->dword_00001C = v6;
                _this->dword_000020 = v117;
                v107 = pParent->pCompressedData;
                pParent->uCompressedDataSize = v115;
                pParent->pCompressedData = v73;
                pParent->dword_000008 += (char *)v73 - v107;
                _this->pDecompressionBufferTail = v106;
                return class21_fn3(_this, pParent, v68);
              }
              _this->dword_000000 = 8;
LABEL_124:
              _this->dword_00001C = v6;
              _this->dword_000020 = v117;
              v108 = pParent->pCompressedData;
              pParent->uCompressedDataSize = v115;
              v109 = pParent->dword_000008;
              pParent->pCompressedData = v73;
              pParent->dword_000008 = (char *)v73 - v108 + v109;
              _this->pDecompressionBufferTail = v106;
              result = class21_fn3(_this, pParent, 1);
            }
          }
        }
        return result;
      case 4:
        v41 = v117;
        goto LABEL_57;
      case 5:
        v41 = v117;
        goto LABEL_68;
      case 6:
        v41 = v117;
        goto LABEL_91;
      case 7:
        v72 = v116;
        v73 = v114;
        goto LABEL_119;
      case 8:
        v106 = v116;
        v73 = v114;
        goto LABEL_124;
      case 9:
        v93 = v115;
        _this->dword_00001C = v6;
        _this->dword_000020 = v117;
        goto LABEL_126;
      default:
        _this->dword_00001C = v6;
        _this->dword_000020 = v117;
        v112 = pParent->pCompressedData;
        v113 = pParent->dword_000008;
        pParent->uCompressedDataSize = v115;
        pParent->pCompressedData = v114;
        pParent->dword_000008 = (char *)v114 + v113 - v112;
        _this->pDecompressionBufferTail = v116;
        return class21_fn3(_this, pParent, -2);
    }
  }
}

//----- (MM7.ee::004C8370) --------------------------------------------------------
int class21_fn3(struct class21 *_this, struct class19 *pParent, int a3)
{
 int i;
  unsigned int v6;
  unsigned int v7; // eax@3
  unsigned int uDecompressedBufferLen; // esi@3
  int v10; // edx@8
  int v11; // eax@9
  int v12; // eax@10
  int v13; // ecx@10
  const void *v14; // esi@11
  unsigned int v15; // eax@13
  unsigned int v16; // edi@13
  //int (__fastcall *v17)(_DWORD, _DWORD, _DWORD); // eax@18
  int v18; // edx@18
  int v19; // eax@19
  unsigned int v21; // [sp+10h] [bp-Ch]@3
  int v22; // [sp+10h] [bp-Ch]@13
  void *v23; // [sp+14h] [bp-8h]@1
  void *v24; // [sp+14h] [bp-8h]@10
  int v25; // [sp+18h] [bp-4h]@1
  int v26; // [sp+18h] [bp-4h]@11

  v6 = _this->pDecompressionBufferTail;
  v25 = _this->pDecompressionBufferHead;
  if (_this->pDecompressionBufferHead > _this->pDecompressionBufferTail)
    v6 = _this->dword_00002C;
  v7 = pParent->uDecompressedDataSize;
  uDecompressedBufferLen = v6 - (unsigned int)_this->pDecompressionBufferHead;
  v21 = uDecompressedBufferLen;
  if (uDecompressedBufferLen > pParent->uDecompressedDataSize)
  {
   v21 = pParent->uDecompressedDataSize;
   uDecompressedBufferLen = pParent->uDecompressedDataSize;
  }
  if (uDecompressedBufferLen)
  {
    if (a3 == -5)
      a3 = 0;
  }
  v10 = uDecompressedBufferLen + pParent->dword_000014;
  pParent->uDecompressedDataSize = v7 - uDecompressedBufferLen;
  pParent->dword_000014 = v10;

  if (_this->pfn_000038)
  {
   v11 = (_this->pfn_000038)(_this->dword_00003C, _this->pDecompressionBufferHead, uDecompressedBufferLen);
   _this->dword_00003C = v11;
   pParent->dword_00002C = v11;
  }

  memcpy(pParent->pDecompressedData, _this->pDecompressionBufferHead, uDecompressedBufferLen);
  v12 = v21 + v25;
  v13 = _this->dword_00002C;
  v24 = pParent->pDecompressedData + v21;
  if ( v21 + v25 == v13 )
  {
    v14 = _this->dword_000028;
    v26 = _this->dword_000028;
    if ( _this->pDecompressionBufferTail == v13 )
      _this->pDecompressionBufferTail = v14;
    v15 = pParent->uDecompressedDataSize;
    v16 = _this->pDecompressionBufferTail - (_DWORD)v14;
    v22 = _this->pDecompressionBufferTail - (_DWORD)v14;
    if ( v16 > v15 )
    {
      v22 = pParent->uDecompressedDataSize;
      v16 = pParent->uDecompressedDataSize;
    }
    if ( v16 )
    {
      if ( a3 == -5 )
        a3 = 0;
    }
    v18 = v16 + pParent->dword_000014;
    pParent->uDecompressedDataSize = v15 - v16;
    pParent->dword_000014 = v18;
    if (_this->pfn_000038)
    {
     v19 = (_this->pfn_000038)(_this->dword_00003C, v14, v16);
     _this->dword_00003C = v19;
     pParent->dword_00002C = v19;
    }
    memcpy(v24, v14, v16);
    v24 = (char *)v24 + v22;
    v12 = v22 + v26;
  }

 pParent->pDecompressedData = v24;
 _this->pDecompressionBufferHead = v12;
 return a3;
}

//----- (MM7.exe::004C74A0) --------------------------------------------------------
int class21_fn4(struct class21 *_this, struct class19 *pParent, int a3)
{
  struct class27 *v3; // eax@1
  unsigned char *v4; // edx@1
  unsigned int v5; // ecx@1
  unsigned int v6; // ebx@1
  unsigned char *v7; // ebp@1
  signed int v11; // eax@8
  unsigned int v12; // ecx@8
  int v13; // ebx@8
  int v14; // ecx@8
  int v15; // ecx@9
  unsigned int v17; // eax@14
  char v18; // cl@16
  int v19; // ecx@16
  unsigned char *v20; // eax@17
  int v21; // ecx@17
  int v22; // ecx@17
  int v23; // ecx@18
  int v24; // ecx@20
  unsigned int v25; // eax@25
  char v26; // cl@27
  int v27; // ecx@27
  int v28; // ecx@28
  unsigned int v29; // eax@29
  char v30; // cl@31
  int v31; // ecx@31
  int v32; // ecx@32
  int v33; // ecx@33
  unsigned int v34; // eax@36
  char v35; // cl@38
  int v36; // ecx@38
  unsigned int v37; // eax@40
  unsigned int v38; // eax@46
  unsigned int v39; // ecx@46
  int v40; // eax@48
  unsigned int v41; // eax@51
  int v42; // eax@51
  unsigned int v44; // ecx@55
  int v45; // eax@57
  unsigned int v47; // eax@68
  unsigned int v48; // ecx@68
  int v49; // eax@70
  unsigned int v50; // eax@73
  int v51; // eax@73
  int v52; // ecx@74
  unsigned int v53; // ecx@77
  int v54; // eax@79
  int result; // eax@86
  int v56; // ebx@86
  int v57; // ecx@86
  int v58; // ebx@88
  int v59; // ecx@88
  int v60; // ebx@89
  int v61; // ecx@89
  int v62; // eax@92
  int v63; // ebx@93
  int v64; // ebx@95
  int v65; // ecx@95
  int v66; // ebx@96
  int v67; // ecx@96
  int v68; // ebx@97
  int v69; // ecx@97

  unsigned int v70; // [sp+10h] [bp-18h]@1
  struct class27 *v71; // [sp+14h] [bp-14h]@1
  unsigned int v72; // [sp+18h] [bp-10h]@1
  unsigned int v73; // [sp+1Ch] [bp-Ch]@4
  unsigned int v74; // [sp+20h] [bp-8h]@14
  int v75; // [sp+20h] [bp-8h]@17
  unsigned int v76; // [sp+20h] [bp-8h]@25
  unsigned int v77; // [sp+20h] [bp-8h]@29
  unsigned int v78; // [sp+20h] [bp-8h]@36
  int v79; // [sp+24h] [bp-4h]@41
  int v80; // [sp+2Ch] [bp+4h]@51

  v3 = _this->class27_obj;
  v7 = pParent->pCompressedData;
  v6 = _this->dword_00001C;
  v72 = pParent->uCompressedDataSize;
  v5 = _this->pDecompressionBufferHead;
  v70 = _this->dword_000020;
  v4 = _this->pDecompressionBufferTail;
  v71 = _this->class27_obj;
  if ( v4 >= v5 )
    v73 = _this->dword_00002C - (unsigned int)v4;
  else
    v73 = v5 - (unsigned int)v4 - 1;
  while ( 2 )
  {
    switch (v3->dword_000000)
    {
      case 0:
        if ( v73 >= 0x102 )
        {
          if ( v72 >= 0xA )
          {
            _this->dword_000020 = v70;
            _this->dword_00001C = v6;
            v13 = pParent->pCompressedData;
            _this->class27_obj = v72;
            v14 = pParent->dword_000008;
            pParent->pCompressedData = v7;
            pParent->dword_000008 = v7 - v13 + v14;
            _this->pDecompressionBufferTail = v4;
            v11 = LOD_DoDecompression(v71->byte_000010, v71->byte_000011,
                                      v71->ptr_000014,
                                      v71->ptr_000018, _this, pParent);
            v7 = pParent->pCompressedData;
            v6 = _this->dword_00001C;
            v72 = pParent->uCompressedDataSize;
            v12 = _this->pDecompressionBufferHead;
            v70 = _this->dword_000020;
            v4 = _this->pDecompressionBufferTail;
            a3 = v11;
            v15 = v4 >= v12 ? _this->dword_00002C - (unsigned int)v4 : v12 - (unsigned int)v4 - 1;
            v73 = v15;
            if ( v11 )
            {
              v71->dword_000000 = v11 != 1 ? 9 : 7;
              v3 = v71;
              continue;
            }
          }
        }
        v3 = v71;
        v71->dword_000000 = 1;
        v71->dword_000008 = v71->ptr_000014;
        v71->dword_00000C = v71->byte_000010;
        goto LABEL_14;
      case 1:
LABEL_14:
        v17 = v3->dword_00000C;
        v74 = v17;
        if ( v6 >= v17 )
          goto LABEL_17;
        do
        {
          if ( !v72 )
            goto LABEL_86;
          v18 = v6;
          --v72;
          v6 += 8;
          a3 = 0;
          v19 = ((unsigned int)(*v7++) << v18) | v70;
          v17 = v74;
          v70 = v19;
        }
        while ( v6 < v74 );
LABEL_17:
        v20 = v71->dword_000008 + 8 * (v70 & dword_4F2688[v17]);
        v75 = v20;
        v22 = v20[1];
        v70 >>= v22;
        v6 -= v22;
        v21 = *v20;
        if (*v20)
        {
          if ( v21 & 0x10 )
          {
            v3 = v71;
            v71->dword_000008 = v21 & 0xF;
            v24 = *(_DWORD *)(v75 + 4);
            v71->dword_000000 = 2;
            v71->dword_000004 = v24;
          }
          else
          {
            if ( !(v21 & 0x40) )
              goto LABEL_22;
            v3 = v71;
            if ( !(v21 & 0x20) )
            {
             v71->dword_000000 = 9;
              pParent->pStatus = "invalid literal/length code";
LABEL_88:
              _this->dword_000020 = v70;
              _this->dword_00001C = v6;
              v58 = pParent->dword_000008;
              _this->class27_obj = v72;
              v59 = v7 - (unsigned int)pParent->pCompressedData;
              pParent->pCompressedData = v7;
              pParent->dword_000008 = v59 + v58;
              _this->pDecompressionBufferTail = v4;
              return class21_fn3(_this, pParent, -3);
            }
            v71->dword_000000 = 7;
          }
        }
        else
        {
          v23 = *(_DWORD *)(v20 + 4);
          v3 = v71;
          v71->dword_000008 = v23;
          v71->dword_000000 = 6;
        }
        continue;
      case 2:
        v25 = v3->dword_000008;
        v76 = v25;
        if ( v6 >= v25 )
          goto LABEL_28;
        do
        {
          if ( !v72 )
            goto LABEL_86;
          v26 = v6;
          --v72;
          v6 += 8;
          a3 = 0;
          v27 = ((unsigned int)(*v7++) << v26) | v70;
          v25 = v76;
          v70 = v27;
        }
        while ( v6 < v76 );
LABEL_28:
        v71->dword_000004 += v70 & dword_4F2688[v25];
        v70 >>= v76;
        v6 -= v76;
        v3 = v71;
        v28 = v71->byte_000011;
        v71->dword_000000 = 3;
        v71->dword_00000C = v28;
        v71->dword_000008 = v71->ptr_000018;
LABEL_29:
        v29 = v3->dword_00000C;
        v77 = v29;
        if ( v6 < v29 )
        {
          while ( v72 )
          {
            v30 = v6;
            --v72;
            v6 += 8;
            a3 = 0;
            v31 = ((unsigned int)(*v7++) << v30) | v70;
            v29 = v77;
            v70 = v31;
            if ( v6 >= v77 )
              goto LABEL_32;
          }
LABEL_86:
          _this->dword_00001C = v6;
          _this->dword_000020 = v70;
          v56 = pParent->dword_000008;
          v57 = v7 - (unsigned int)pParent->pCompressedData;
          _this->class27_obj = 0;
          pParent->pCompressedData = v7;
          pParent->dword_000008 = v57 + v56;
          _this->pDecompressionBufferTail = v4;
          return class21_fn3(_this, pParent, a3);
        }
LABEL_32:
        v75 = v71->dword_000008 + 8 * (v70 & dword_4F2688[v29]);
        v32 = *(unsigned char *)(v75 + 1);
        v6 -= v32;
        v70 >>= v32;
        v21 = *(unsigned char *)v75;
        if ( v21 & 0x10 )
        {
          v3 = v71;
          v71->dword_000008 = v21 & 0xF;
          v33 = *(_DWORD *)(v75 + 4);
          v71->dword_000000 = 4;
          v71->dword_00000C = v33;
        }
        else
        {
          if ( v21 & 0x40 )
          {
           v71->dword_000000 = 9;
            pParent->pStatus = "invalid distance code";
            goto LABEL_88;
          }
LABEL_22:
          v71->dword_00000C = v21;
          v3 = v71;
          v71->dword_000008 = v75 + 8 * *(_DWORD *)(v75 + 4);
        }
        continue;
      case 3:
        goto LABEL_29;
      case 4:
       v34 = v3->dword_000008;
        v78 = v34;
        if ( v6 >= v34 )
          goto LABEL_39;
        do
        {
          if ( !v72 )
            goto LABEL_86;
          v35 = v6;
          --v72;
          v6 += 8;
          a3 = 0;
          v36 = ((unsigned int)(*v7++) << v35) | v70;
          v34 = v78;
          v70 = v36;
        }
        while ( v6 < v78 );
LABEL_39:
        v71->dword_00000C += v70 & dword_4F2688[v34];
        v70 >>= v78;
        v6 -= v78;
        v71->dword_000000 = 5;


      case 5:
        v37 = v71->dword_00000C;
        if ((unsigned int)v4 - (unsigned int)_this->dword_000028 >= v37 )
          v79 = v4 - v37;
        else
         v79 = (unsigned int)v4 + (unsigned int)_this->dword_00002C - (unsigned int)_this->dword_000028 - v71->dword_00000C;
        v3 = v71;
        if ( !v71->dword_000004 )
        {
LABEL_65:
         v3->dword_000000 = 0;
          continue;
        }
        while ( v73 )
        {
LABEL_62:
          a3 = 0;
          *v4++ = *(unsigned char *)v79++;
          --v73;
          if ( v79 == _this->dword_00002C )
            v79 = _this->dword_000028;
          if (!--v3->dword_000004)
            goto LABEL_65;
        }
        if ((unsigned int)v4 == _this->dword_00002C )
        {
          v38 = _this->pDecompressionBufferHead;
          v39 = _this->dword_000028;
          if ( v38 != v39 )
          {
            v4 = _this->dword_000028;
            v40 = v39 >= v38 ? _this->dword_00002C - v39 : v38 - v39 - 1;
            v73 = v40;
            if ( v40 )
              goto LABEL_100;
          }
        }
        _this->pDecompressionBufferTail = v4;  //28 == head, 2c == tail
        v42 = class21_fn3(_this, pParent, a3); // 28 == head == tail, 2c
        v4 = _this->pDecompressionBufferTail;
        v80 = v42;
        v41 = _this->pDecompressionBufferHead;

        if (v4 >= v41)
          v73 = _this->dword_00002C - (unsigned int)v4;
        else
          v73 = v41 - (unsigned int)v4 - 1;

        if ((unsigned int)v4 == _this->dword_00002C )
        {
          v44 = _this->dword_000028;
          if ( v41 != v44 )
          {
            v4 = _this->dword_000028;
            if ( v44 >= v41 )
              v45 = _this->dword_00002C - v44;
            else
              v45 = v41 - v44 - 1;
            v73 = v45;
          }
        }
        if ( v73 )
        {
LABEL_100:
          v3 = v71;
          goto LABEL_62;
        }
LABEL_89:
        _this->dword_000020 = v70;
        _this->dword_00001C = v6;
        v60 = pParent->pCompressedData;
        _this->class27_obj = v72;
        v61 = pParent->dword_000008;
        pParent->pCompressedData = v7;
        pParent->dword_000008 = v7 - v60 + v61;
         _this->pDecompressionBufferTail = v4;
        return class21_fn3(_this, pParent, v80);


      case 6:
        if ( v73 )
          goto LABEL_84;
        if ((unsigned int)v4 != _this->dword_00002C
          || (v47 = _this->pDecompressionBufferHead, v48 = _this->dword_000028, v47 == v48)
          || ((v4 = _this->dword_000028, v48 >= v47) ? (v49 = _this->dword_00002C - v48) : (v49 = v47 - v48 - 1),
              v73 = v49,
              !v49) )
        {
          _this->pDecompressionBufferTail = v4;
          v51 = class21_fn3(_this, pParent, a3);
          v4 = _this->pDecompressionBufferTail;
          v80 = v51;
          v50 = _this->pDecompressionBufferHead;
          v52 = v4 >= v50 ? _this->dword_00002C - (unsigned int)v4 : v50 - (unsigned int)v4 - 1;
          v73 = v52;
          if ((unsigned int)v4 == _this->dword_00002C )
          {
            v53 = _this->dword_000028;
            if ( v50 != v53 )
            {
              v4 = _this->dword_000028;
              if ( v53 >= v50 )
                v54 = _this->dword_00002C - v53;
              else
                v54 = v50 - v53 - 1;
              v73 = v54;
            }
          }
          if ( !v73 )
            goto LABEL_89;
        }
        v3 = v71;
LABEL_84:
        a3 = 0;
        *v4++ = v3->dword_000008;
        --v73;
        v3->dword_000000 = 0;
        continue;
      case 7:
        if ( v6 > 7 )
        {
          v6 -= 8;
          --v7;
          ++v72;
        }
        _this->pDecompressionBufferTail = v4;
        v62 = class21_fn3(_this, pParent, a3);
        v4 = _this->pDecompressionBufferTail;
        if ( _this->pDecompressionBufferHead == v4 )
        {
          *(_DWORD *)v71 = 8;
LABEL_95:
          _this->dword_00001C = v6;
          _this->dword_000020 = v70;
          v64 = pParent->dword_000008;
          pParent->uCompressedDataSize = v72;
          v65 = v7 - (unsigned int)pParent->pCompressedData;
          pParent->pCompressedData = v7;
          pParent->dword_000008 = v65 + v64;
          _this->pDecompressionBufferTail = v4;
          result = class21_fn3(_this, pParent, 1);
        }
        else
        {
          _this->dword_00001C = v6;
          _this->dword_000020 = v70;
          v63 = pParent->pCompressedData;
          pParent->uCompressedDataSize = v72;
          pParent->pCompressedData = v7;
          pParent->dword_000008 += (unsigned int)v7 - v63;
          _this->pDecompressionBufferTail = v4;
          result = class21_fn3(_this, pParent, v62);
        }
        return result;
      case 8:
        goto LABEL_95;
      case 9:
        _this->dword_000020 = v70;
        _this->dword_00001C = v6;
        v66 = pParent->pCompressedData;
        _this->class27_obj = v72;
        v67 = pParent->dword_000008;
        pParent->pCompressedData = v7;
        pParent->dword_000008 = v7 - v66 + v67;
        _this->pDecompressionBufferTail = v4;
        return class21_fn3(_this, pParent, -3);
      default:
        _this->dword_000020 = v70;
        _this->dword_00001C = v6;
        v68 = pParent->dword_000008;
        _this->class27_obj = v72;
        v69 = v7 - (unsigned int)pParent->pCompressedData;
        pParent->pCompressedData = v7;
        pParent->dword_000008 = v69 + v68;
        _this->pDecompressionBufferTail = v4;
        return class21_fn3(_this, pParent, -2);
    }
  }
}

//----- (MM7.exe::00426755) --------------------------------------------------------
void *class23_AllocatedNamedBuffer(struct class23 *_this, int a2, int size, const char *pBufferName)
{
  signed int v5; // eax@7
  int result; // eax@8
  int v8; // edi@15
  int v10; // eax@16
  int v11; // ebx@19
  void *v12; // eax@22
  int v13; // [sp+14h] [bp+Ch]@16

 if (a2)
 {
  if (!dword_720018)
    sub_466B8C();
 }

 //if ( !*(_DWORD *)(v4 + 120020) )
 if (!_this->bBigBufferAllocated)
 {
  if ( !dword_720018 )
    sub_466B8C();
 }

 v5 = size;
 if (size)
 {
  if (size < 0 && !dword_720018)
    sub_466B8C();

  //if ( *(_DWORD *)(v4 + 120004) == 6000 )
  if (_this->uNumMemoryBuffersUsed >= 6000)
  {
   if (!dword_720018)
   {
    sub_466B8C();
    v5 = size;
   }
  }
  v8 = _this->uNumMemoryBuffersUsed++;

  if (!_this->dword_01D4D8)
  {
   //v12 = malloc(v5);
   //v11 = v4 + 4 * v8;
   //*(_DWORD *)v11 = v12;
   v12 = malloc(size);
   v11 = _this->pMemoryBuffers[v8];
   if (v12)
     //*(_DWORD *)(v4 + 4 * v8 + 24000) = Size;
     _this->uMemoryBufferSizes[v8] = size;
   else
   {
    if (!dword_720018)
      sub_466B8C();
   }
  }
  else
  {
   //LOBYTE(v5) = v5 & 0xFC;
   v5 &= 0xFFFFFFFC;
   v10 = v5 + 4;

   //if ((unsigned int)(v10 + *(_DWORD *)(v4 + 120012)) > *(_DWORD *)(v4 + 120016))
   if ((unsigned int)(_this->uNextFreeOffsetInBigBuffer + v10) > _this->uBigBufferSizeMinus1000h)
   {
    printf("Id: %s  Size: %i", pBufferName, v10);
    class23_CreateFileDump(_this, "Memory");
    if (!dword_720018)
      sub_466B8C();
   }

   //v11 = v4 + 4 * v8;
   //*(_DWORD *)v11 = *(_DWORD *)(v4 + 120012) + *(_DWORD *)(v4 + 120008);
   _this->pMemoryBuffers[v8] = (char *)(_this->pBigMemoryBuffer) + _this->uNextFreeOffsetInBigBuffer;
   //*(_DWORD *)(v4 + 4 * v8 + 24000) = v13;
   _this->uMemoryBufferSizes[v8] = v10;

   if (pBufferName)
     //strncpy((char *)(v4 + 4 * (3 * v8 + 12000)), Source, 0xBu);
     strncpy(_this->aBufferNames[v8], pBufferName, 11);
   //*(_DWORD *)(v4 + 120012) += v13;
   _this->uNextFreeOffsetInBigBuffer += v10;
  }
  //result = *(_DWORD *)v11;
  result = _this->pMemoryBuffers[v8];
 }
 else return 0;
 return result;
}

//----- (MM7.exe::00426474) --------------------------------------------------------
int class23_fn1(struct class23 *_this, void *pMem)
{
 int v2; // esi@1
 int v3; // eax@5
 int i; // edi@5
 int v5; // eax@13
 int j; // edx@16
 int v7; // ecx@16
 char v8; // zf@20

 v2 = _this;
 if (pMem)
 {
  //if ( !*(_DWORD *)(this + 120020) )
  if (!_this->bBigBufferAllocated)
  {
   if (!dword_720018)
     sub_466B8C();
  }

  //v3 = *(_DWORD *)(v2 + 120004);
  v3 = _this->uNumMemoryBuffersUsed;
  for (i = 0; i < v3; ++i)
    //if ( *(_DWORD *)(v2 + 4 * i) == a2 )
    if (_this->pMemoryBuffers[i] == pMem)
      break;
 
  if (i >= v3)
  {
   if (!dword_720018)
     v3 = sub_466B8C();
  }

  //if ( !*(_DWORD *)(v2 + 120024) )
  if (!_this->dword_01D4D8)
    //call_delete(v3, *(_DWORD *)(v2 + 4 * i));
    call_delete(v3, _this->pMemoryBuffers[i]);

  //*(_DWORD *)(v2 + 4 * i) = 0;
  //*(_DWORD *)(v2 + 4 * i + 24000) = 0;
  //*(_BYTE *)(v2 + 4 * (3 * i + 12000)) = 0;
  _this->pMemoryBuffers[i] = 0;
  _this->uMemoryBufferSizes[i] = 0;
  _this->aBufferNames[i][0] = 0;

  //v5 = *(_DWORD *)(v2 + 120004);
  v5 = _this->uNumMemoryBuffersUsed;
  if (i == v5 - 1)
  {
   if (i)
   {
    v7 = 0;
    for (j = 0; j < v5; ++j)
    {
     //if ( *(_DWORD *)(v2 + 4 * j) )
     if (_this->pMemoryBuffers[j])
       v7 = j;
    }

    //v8 = *(_DWORD *)(v2 + 120024) == 0;
    //*(_DWORD *)(v2 + 120004) = v7 + 1;
    v8 = _this->dword_01D4D8 == 0;
    _this->uNumMemoryBuffersUsed = v7 + 1;
    //if (!v8)
    if (_this->dword_01D4D8)
      //*(_DWORD *)(v2 + 120012) = *(_DWORD *)(v2 + 4 * v7) + *(_DWORD *)(v2 + 4 * v7 + 24000)
      //                           - *(_DWORD *)(v2 + 120008);
      _this->uNextFreeOffsetInBigBuffer = (char *)(_this->pMemoryBuffers[v7]) + _this->uMemoryBufferSizes[v7] - (unsigned int)(_this->pBigMemoryBuffer);
   }
   else
   {
    //*(_DWORD *)(v2 + 120012) = 0;
    //*(_DWORD *)(v2 + 120004) = 0;
    _this->uNumMemoryBuffersUsed = 0;
    _this->uNextFreeOffsetInBigBuffer = 0;
   }
  }
 }
 return 0;
}

//----- (MM7.exe::004266CD) --------------------------------------------------------
int class23_AllocateBigBuffer(struct class23 *_this, unsigned int uNumKBytes)
{
  int v2; // esi@1
  signed int result; // eax@2
  DWORD v4; // edi@5
  void *v5; // eax@5
  int v6; // eax@5

 v2 = _this;
 //if ( *(_DWORD *)(this + 120020) )
 if (_this->bBigBufferAllocated)
   return false;

 if (uNumKBytes)
 {
  v5 = malloc(uNumKBytes * 1024);
  //*(_DWORD *)(v2 + 120008) = v5;
  _this->pBigMemoryBuffer = v5;
  v4 = (uNumKBytes * 1024) - 4096;
  //v6 = (int)((char *)v5 - ((_WORD)v5 & 0xFFF));
  v6 = (int)(v5) & 0xFFFF0000;

  //*(_DWORD *)(v2 + 120028) = v6 + 4096;
  _this->pBigBufferAlignedAt1000h = v6 + 4096;

  sub_426892(v6 + 4096, v4);
  result = 0;
  //if ( !*(_DWORD *)(v2 + 120008) )
  if (!_this->pBigMemoryBuffer)
    return false;

  //*(_DWORD *)(v2 + 120004) = 0;
  //*(_DWORD *)(v2 + 120012) = 0;
  //*(_DWORD *)(v2 + 120016) = v4;
  //*(_DWORD *)(v2 + 120024) = 1;
  _this->uNumMemoryBuffersUsed = 0;
  _this->uNextFreeOffsetInBigBuffer = 0;
  _this->uBigBufferSizeMinus1000h = v4;
  _this->dword_01D4D8 = 1;
 }
 else
 {
  //*(_DWORD *)(this + 120024) = 0;
  _this->dword_01D4D8 = 0;
 }
 //*(_DWORD *)(v2 + 120020) = result;
 //return result;
 return _this->bBigBufferAllocated = true;
}

//----- (MM7.exe::0042654C) --------------------------------------------------------
int class23_CreateFileDump(struct class23 *_this, const char *a2)
{
  FILE *v2; // eax@1
  int v4; // esi@1
  signed int result; // eax@2
  int v7; // edx@5
  int v8; // ecx@5
  int v9; // eax@6
  int v10; // eax@8
  int v11; // ecx@8
  signed int v12; // ebx@8
  int v13; // ebx@10
  struct _MEMORYSTATUS Buffer; // [sp+8h] [bp-38h]@5
  char pFilename[256]; // [sp+28h] [bp-18h]@1
  int v16; // [sp+3Ch] [bp-4h]@11
  int v17; // [sp+48h] [bp+8h]@11

  v4 = _this;
  //v5 = *(_DWORD *)(this + 120000);
  //*(_DWORD *)(this + 120000) = v5 + 1;
  sprintf(pFilename, "Mem%03i.txt", _this->dword_01D4C0++);
  v2 = fopen(pFilename, "w");
  if (v2)
  {
   if (a2)
     fprintf(v2, "%s\n\n", a2);

   fprintf(v2, "Windows Memory Status");
   GlobalMemoryStatus(&Buffer);
   fprintf(v2, "dwLength:         %d\n\n", Buffer.dwLength);
   fprintf(v2, "dwMemoryLoad:     %d\n", Buffer.dwMemoryLoad);
   fprintf(v2, "dwTotalPhys:      %d\n", Buffer.dwTotalPhys);
   fprintf(v2, "dwAvailPhys:      %d\n", Buffer.dwAvailPhys);
   fprintf(v2, "dwTotalPageFile:  %d\n", Buffer.dwTotalPageFile);
   fprintf(v2, "dwAvailPageFile:  %d\n", Buffer.dwAvailPageFile);
   fprintf(v2, "dwTotalVirtual:   %d\n", Buffer.dwTotalVirtual);
   fprintf(v2, "dwAvailVirtual:   %d\n\n\n", Buffer.dwAvailVirtual);
   //v8 = *(_DWORD *)(v4 + 120004);
   v8 = _this->uNumMemoryBuffersUsed;
   v7 = 0;

   if (_this->uNumMemoryBuffersUsed > 0)
   {
    v9 = (char *)_this + 24000;
    do
    {
     v7 += *(_DWORD *)v9;
     v9 += 4;
     --v8;
    }
    while (v8);
   }

   v10 = 0;
   v11 = (char *)_this + 24000;
   v12 = 6000;
   do
   {
    v10 += *(_DWORD *)v11;
    v11 += 4;
    --v12;
   }
   while (v12);

   //fprintf(v2, "Size: %i  %i  %i\n\n", *(_DWORD *)(v4 + 120004), v7, v10);
   fprintf(v2, "Size: %i  %i  %i\n\n", _this->uNumMemoryBuffersUsed, v7, v10);
   v13 = 0;
   //if ( *(_DWORD *)(v4 + 120004) > 0 )
   if (_this->uNumMemoryBuffersUsed > 0)
   {
    v16 = (char *)v4 + 24000;
    v17 = (char *)v4 + 48000;

    do
    {
     fprintf(v2, "%10i %10i %s\n", v13, *(_DWORD *)v16, v17);
     v17 += 12;
     v16 += 4;
     ++v13;
    }
    //while ( v13 < *(_DWORD *)(v4 + 120004) );
    while (v13 < _this->uNumMemoryBuffersUsed);
   }
   fclose(v2);
   result = 0;
  }
  else result = 1;
  return result;
}

//----- (MM7.exe::00426402) --------------------------------------------------------
void class24_ctor(struct class24 *_this)
{
 memset(_this, 0, sizeof(struct class24));
 _this->dword_000000 = 1;
 _this->dword_000024 = 0;
}

//----- (MM7.exe::00426349) --------------------------------------------------------
void class24_fn1(struct class24 *_this)
{
 if (!_this->dword_000004)
 {
  _this->dword_000004 = 1;
  _this->dword_000010 = class24_fn2(_this);
 }
}

//----- (MM7.exe::00426317) --------------------------------------------------------
__int64 class24_fn2(struct class24 *_this)
{
 DWORD v1; // edi@1

 v1 = (timeGetTime() << 7) / 0x3E8;
 if ( v1 < (signed __int64)_this->dword_000008 )
   _this->dword_000004 = 0;
 return v1;
}



//----- (MM7.exe::004C055C) --------------------------------------------------------
__int64 class25_fn0(struct class25 *_this)
{
  __int64 result; // qax@1
  signed int v2; // ecx@1

  LODWORD(result) = _this;
  v2 = 512;
  HIDWORD(result) = (char *)(_this) + 4;
  do
  {
    *(DWORD *)(HIDWORD(result)) = 0;
    *(_QWORD *)(HIDWORD(result) + 4) = 4294967295i64;
    result += 51539607552i64;
  }
  while ( --v2 );
  _this->dword_000000 = 5081608;
  _this->dword_002004 = 0;
  return result;
}

//----- (MM7.exe::004C0376) --------------------------------------------------------
struct class26 *class26_ctor(struct class26 *_this)
{
 _this->dword_000000 = 5081596;
 return _this;
}

//----- (MM7.exe::004C0262) --------------------------------------------------------
int class28_fn0(struct class28 *_this, int a2, int a3, int a4, int a5)
{
  int v5; // edx@1
  int v6; // esi@1
  int v7; // eax@3
  int v8; // edi@3
  char v9; // zf@5
  int v10; // eax@7

  v5 = a2;
  v6 = a4;
  if ( a2 > a4 )
  {
    v6 = a4 ^ a2 ^ a4;
    v5 = v6 ^ a4 ^ a2;
  }
  v8 = a3;
  v7 = a5;
  if ( a3 > a5 )
  {
    v7 = a5 ^ a3 ^ a5;
    v8 = v7 ^ a5 ^ a3;
  }
  _this->dword_000000 = v5;
  _this->dword_000004 = v8;
  _this->dword_000008 = v6;
  _this->dword_00000C = v7;
  v9 = pD3DRenderer->dword_040088 == 0;
  _this->dword_000020 = v6 - v5 + 1;
  _this->dword_000028 = (v6 + v5) >> 1;
  if ( v9 )
  {
    v10 = v7 - v8 + 1;
    _this->dword_000024 = v10;
    _this->dword_00002C = _this->dword_00000C - ((unsigned __int64)(_this->dword_000030 * v10) >> 16);
  }
  else
  {
    _this->dword_000024 = v7 - v8 + 1;
    _this->dword_00002C = (v7 + v8) >> 1;
  }
  return class28_fn1(_this, _this->dword_000000, _this->dword_000004, _this->dword_000008, _this->dword_00000C);
}

//----- (MM7.exe::004C0312) --------------------------------------------------------
int class28_fn1(struct class28 *_this, int a2, int a3, int a4, int a5)
{
 _this->dword_000010 = a2;
 if (_this->dword_000010 < _this->dword_000000)
   _this->dword_000010 = _this->dword_000000;

 _this->dword_000014 = a3;
 if (_this->dword_000014 < _this->dword_000004)
   _this->dword_000014 = _this->dword_000004;

 _this->dword_000018 = a4;
 if (_this->dword_000018 > _this->dword_000008)
   _this->dword_000018 = _this->dword_000008;

 _this->dword_00001C = a5;
 if (_this->dword_00001C > _this->dword_00000C)
   _this->dword_00001C = _this->dword_00000C;
 return _this->dword_00001C;
}

//----- (MM7.exe::004C02F8) --------------------------------------------------------
int class28_fn2(struct class28 *_this, int a2)
{
  int v3; // ST0C_4@1

  v3 = _this->dword_00000C;
  _this->dword_000030 = a2;
  return class28_fn0(_this, _this->dword_000000, _this->dword_000004, _this->dword_000008, v3);
}



void CSpriteFrameTable_ctor(struct CSpriteFrameTable *_this)
{
 _this->dword_000000 = 0;
 _this->dword_000004 = 0;
 _this->dword_000008 = 0;
 _this->ptr_00000C = 0;
 _this->ptr_000010 = 0;
 _this->ptr_000014 = 0;
}

//----- (MM7.exe::0044D9D7) --------------------------------------------------------
int CSpriteFrameTable_LoadFromDSFT(struct CSpriteFrameTable *_this, void *pSrc)
{
 int i;
 size_t v4; // edi@1

 _this->dword_000000 = ((unsigned int *)pSrc)[0];
 _this->dword_000004 = ((unsigned int *)pSrc)[1];

 _this->ptr_00000C = class23_AllocatedNamedBuffer(class23_instance, _this->ptr_00000C, 60 * _this->dword_000000, "S Frames");
 _this->ptr_000014 = class23_AllocatedNamedBuffer(class23_instance, _this->ptr_000014, 2 * _this->dword_000000, "E Frames");
 _this->ptr_000010 = class23_AllocatedNamedBuffer(class23_instance, _this->ptr_000010, 4 * _this->dword_000000, "P Frames");
 v4 = _this->dword_000000 * 60;

 memcpy(_this->ptr_00000C, (char *)pSrc + 8, v4);
 memcpy(_this->ptr_000014, (char *)pSrc + v4 + 8, 2 * _this->dword_000004);

 for (i = 0; i < _this->dword_000000; ++i)
   _this->ptr_000010[i] = _this->ptr_00000C + 60 * _this->ptr_000014[i];

 return _this->dword_000000;
}

//----- (MM7.exe::0044D96D) --------------------------------------------------------
int CSpriteFrameTable_Save_DSFT_bin(struct CSpriteFrameTable *_this)
{
  FILE *v1; // eax@1

  v1 = fopen("data\\dsft.bin", "wb");
  if ( !v1 )
    sub_466BE5("Unable to save dsft.bin!");
  sub_4CB54C(_this, 4u, 1u, v1);
  sub_4CB54C((char *)_this + 4, 4u, 1u, v1);
  sub_4CB54C(*((const void **)_this + 3), 0x3Cu, *(_DWORD *)_this, v1);
  sub_4CB54C(*((const void **)_this + 5), 2u, *((_DWORD *)_this + 1), v1);
  return fclose(v1);
}

//----- (MM7.exe::0044DA92) --------------------------------------------------------
int CSpriteFrameTable_LoadFromTXT(struct CSpriteFrameTable *_this, const char *pSourceFile)
{
  FILE *v2; // eax@1
  int v3; // ebx@1
  int v4; // esi@3
  signed int result; // eax@10
  char *i; // eax@11
  FILE *v7; // ST18_4@11
  int v8; // eax@14
  char *v9; // ST20_4@14
  char *v10; // ST0C_4@14
  double v11; // st7@14
  const char *v12; // ST04_4@14
  const char *v13; // ST00_4@14
  int v14; // eax@17
  int v15; // eax@23
  int v16; // eax@24
  int v17; // eax@25
  int v18; // eax@28
  int v19; // eax@29
  signed int j; // edi@30
  const char *v21; // esi@31
  int v22; // eax@32
  int v23; // edx@53
  int v24; // ecx@54
  int v25; // eax@55
  int k; // edx@58
  int v27; // ecx@59
  int v28; // esi@59
  int l; // eax@60
  signed int v30; // eax@65
  int v31; // edi@66
  int v32; // esi@66
  int v33; // eax@69
  int v34; // ecx@69
  int v35; // edx@69
  int v36; // eax@69
  int v37; // ecx@69
  char Buf; // [sp+Ch] [bp-2F0h]@3
  char v39; // [sp+200h] [bp-FCh]@4
  int v40; // [sp+27Ch] [bp-80h]@4
  char *Source; // [sp+280h] [bp-7Ch]@5
  const char *v42; // [sp+284h] [bp-78h]@14
  char *Str1; // [sp+288h] [bp-74h]@16
  char *Str; // [sp+28Ch] [bp-70h]@14
  char *String; // [sp+290h] [bp-6Ch]@14
  const char *v46; // [sp+294h] [bp-68h]@14
  const char *v47; // [sp+298h] [bp-64h]@14
  const char *v48; // [sp+29Ch] [bp-60h]@24
  const char *v49; // [sp+2A8h] [bp-54h]@18
  const char *v50; // [sp+2ACh] [bp-50h]@20
  const char *v51; // [sp+2B0h] [bp-4Ch]@22
  FILE *File; // [sp+2F8h] [bp-4h]@1
  int v53; // [sp+304h] [bp+8h]@3
  int v54; // [sp+304h] [bp+8h]@59
  FILE *v55; // [sp+304h] [bp+8h]@67

  v3 = _this;
  CSpriteFrameTable_sub_44D4D8(_this);
  v2 = fopen(pSourceFile, L"r");
  File = v2;
  if ( !v2 )
    sub_466BE5("CSpriteFrameTable::load - Unable to open file: %s.", pSourceFile);
  v4 = 0;
  v53 = 0;
  if ( fgets(&Buf, 490, v2) )
  {
    do
    {
      *strchr(&Buf, 10) = 0;
      memcpy(&v40, sub_4BE485(&Buf, &v39), 0x7Cu);
      if ( v40 )
      {
        if ( *Source != 47 )
          ++v53;
      }
    }
    while ( fgets(&Buf, 490, File) );
    v4 = v53;
  }
  *(_DWORD *)v3 = v4;
  *(_DWORD *)(v3 + 12) = class23_AllocatedNamedBuffer(class23_instance, *(_DWORD *)(v3 + 12), 60 * v4, "S Frames");
  *(_DWORD *)(v3 + 20) = class23_AllocatedNamedBuffer(class23_instance, *(_DWORD *)(v3 + 20), 2 * *(_DWORD *)v3, "E Frames");
  *(_DWORD *)(v3 + 16) = class23_AllocatedNamedBuffer(class23_instance, *(_DWORD *)(v3 + 16), 4 * *(_DWORD *)v3, "P Frames");
  if ( *(_DWORD *)(v3 + 12) )
  {
    v7 = File;
    *(_DWORD *)v3 = 0;
    fseek(v7, 0, 0);
    for ( i = fgets(&Buf, 490, File); i; i = fgets(&Buf, 490, File) )
    {
      *strchr(&Buf, 10) = 0;
      memcpy(&v40, sub_4BE485(&Buf, &v39), 0x7Cu);
      if ( v40 )
      {
        if ( *Source != 47 )
        {
          v9 = Source;
          *(_DWORD *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 44) = 0;
          *(_WORD *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 52) = 0;
          strcpy((char *)(*(_DWORD *)(v3 + 12) + 60 * *(_DWORD *)v3), v9);
          strcpy((char *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 12), v42);
          v10 = String;
          *(_WORD *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 50) = atoi(Str);
          v11 = atof(v10) * *(double *)&byte_4D8410[560];
          v12 = v46;
          *(_DWORD *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 40) = abs((signed __int64)v11);
          v13 = v47;
          *(_WORD *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 48) = atoi(v12);
          *(_WORD *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 54) = atoi(v13);
          v8 = *(_DWORD *)(v3 + 12) + 60 * *(_DWORD *)v3;
          if ( *(_WORD *)(v8 + 48) )
            *(_DWORD *)(v8 + 44) |= 2u;
          if ( !_strcmpi(Str1, off_4E7ECC) )
          {
            v14 = 60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 44;
            *(_DWORD *)v14 |= 4u;
            *(_DWORD *)(*(_DWORD *)(v3 + 16) + 4 * *(_DWORD *)(v3 + 4)) = *(_DWORD *)(v3 + 12) + 60 * *(_DWORD *)v3;
            compile_error;//*(_WORD *)(*(_DWORD *)(v3 + 20) + 2 * *(_DWORD *)(v3 + 4)++) = *(_WORD *)v3;
          }
          if ( !_strcmpi(v49, L"1") )
            *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 46) |= 4u;
          if ( !_strcmpi(v50, L"1") )
            *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 46) |= 2u;
          if ( !_strcmpi(v51, L"1") )
          {
            v15 = 60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 44;
            *(_DWORD *)v15 |= 0x20u;
          }
          v16 = atoi(v48) - 1;
          if ( v16 )
          {
            v17 = v16 - 2;
            if ( v17 )
            {
              if ( v17 == 2 )
                *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 0xE0u;
            }
            else
            {
              v18 = 60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 44;
              *(_DWORD *)v18 |= 0x1E000u;
            }
          }
          else
          {
            v19 = 60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 44;
            *(_DWORD *)v19 |= 0x10u;
          }
          for ( j = 13; j < v40; ++j )
          {
            v21 = (&Source)[4 * j];
            if ( _strcmpi((&Source)[4 * j], "Luminous") )
            {
              if ( _strcmpi(v21, "Mirror0") )
              {
                if ( _strcmpi(v21, "Mirror1") )
                {
                  if ( _strcmpi(v21, "Mirror2") )
                  {
                    if ( _strcmpi(v21, "Mirror3") )
                    {
                      if ( _strcmpi(v21, "Mirror4") )
                      {
                        if ( _strcmpi(v21, "Mirror5") )
                        {
                          if ( _strcmpi(v21, "Mirror6") )
                          {
                            if ( !_strcmpi(v21, "Mirror7") )
                              *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 0x80u;
                          }
                          else
                          {
                            *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 0x40u;
                          }
                        }
                        else
                        {
                          *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 0x20u;
                        }
                      }
                      else
                      {
                        *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 0x10u;
                      }
                    }
                    else
                    {
                      *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 8u;
                    }
                  }
                  else
                  {
                    *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 4u;
                  }
                }
                else
                {
                  *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 2u;
                }
              }
              else
              {
                *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 1u;
              }
            }
            else
            {
              v22 = 60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 44;
              *(_DWORD *)v22 |= 2u;
            }
          }
          ++*(_DWORD *)v3;
        }
      }
    }
    fclose(File);
    v23 = 0;
    if ( *(_DWORD *)v3 - 1 > 0 )
    {
      v24 = 0;
      do
      {
        v25 = v24 + *(_DWORD *)(v3 + 12);
        if ( !(*(_BYTE *)(v25 + 104) & 4) )
          *(_DWORD *)(v25 + 44) |= 1u;
        ++v23;
        v24 += 60;
      }
      while ( v23 < *(_DWORD *)v3 - 1 );
    }
    for ( k = 0; k < *(_DWORD *)v3; *(_WORD *)(v54 + 56) = v28 )
    {
      v27 = *(_DWORD *)(v3 + 12);
      v54 = v27 + 60 * k;
      v28 = *(_WORD *)(v54 + 54);
      if ( *(_BYTE *)(v54 + 44) & 1 )
      {
        ++k;
        for ( l = v27 + 60 * k; *(_BYTE *)(l + 44) & 1; l += 60 )
        {
          v28 += *(_WORD *)(l + 54);
          ++k;
        }
        v28 += *(_WORD *)(60 * k + v27 + 54);
      }
      ++k;
    }
    v30 = *(_DWORD *)(v3 + 4);
    if ( v30 > 0 )
    {
      v31 = 0;
      v32 = 0;
      File = (FILE *)1;
      do
      {
        v55 = File;
        if ( (signed int)File < v30 )
        {
          do
          {
            if ( _strcmpi(
                   *(const char **)(*(_DWORD *)(v3 + 16) + 4 * (_DWORD)v55),
                   *(const char **)(*(_DWORD *)(v3 + 16) + v32)) < 0 )
            {
              v33 = *(_DWORD *)(v3 + 16);
              v34 = v33 + 4 * (_DWORD)v55;
              v35 = *(_DWORD *)v34;
              *(_DWORD *)v34 = *(_DWORD *)(v33 + v32);
              *(_DWORD *)(v32 + *(_DWORD *)(v3 + 16)) = v35;
              v36 = *(_DWORD *)(v3 + 20);
              v37 = v36 + 2 * (_DWORD)v55;
              LOWORD(v35) = *(_WORD *)v37;
              *(_WORD *)v37 = *(_WORD *)(v36 + v31);
              *(_WORD *)(v31 + *(_DWORD *)(v3 + 20)) = v35;
            }
            v55 = (FILE *)((char *)v55 + 1);
          }
          while ( (signed int)v55 < *(_DWORD *)(v3 + 4) );
        }
        File = (FILE *)((char *)File + 1);
        v30 = *(_DWORD *)(v3 + 4);
        v32 += 4;
        v31 += 2;
      }
      while ( (signed int)((char *)File - 1) < v30 );
    }
    result = 1;
  }
  else
  {
    sub_4BE386("CSpriteFrameTable::load - Out of Memory!");
    fclose(File);
    result = 0;
  }
  return result;
}

//----- (MM7.exe::0044D4D8) --------------------------------------------------------
int CSpriteFrameTable_sub_44D4D8(struct CSpriteFrameTable *_this)
{
  int result; // eax@1

 result = _this->ptr_00000C;
 if (result)
 {
  result = class23_fn1(class23_instance, _this->ptr_00000C);
  _this->ptr_00000C = 0;
 }
 _this->dword_000000 = 0;
 return result;
}


//----- (MM7.exe::0040F414) --------------------------------------------------------
int class33_fn0(struct class33 *_this, const char *pContainerName, int a3)
{
  void *v6; // ebx@5
  int v8; // eax@9
  int v9; // ecx@9
  void *v11; // eax@13
  int v14; // eax@20

  void *pPCXData;

  //v16
  char local_1[48]; // [sp+Ch] [bp-98h]@7

  struct class18 class18_obj;
  //char DstBuf[48]; // [sp+3Ch] [bp-68h]@1
  //size_t v18; // [sp+50h] [bp-54h]@4
  //size_t Size; // [sp+64h] [bp-40h]@4

  char local_2[24];  //v21 == local_2 + 3
  //char Dst; // [sp+84h] [bp-20h]@7
  //char v21; // [sp+87h] [bp-1Dh]@7
  //int v22; // [sp+88h] [bp-1Ch]@9
  //int v23; // [sp+8Ch] [bp-18h]@9
  //char v24; // [sp+94h] [bp-10h]@7
  FILE *f; // [sp+9Ch] [bp-8h]@1
  //size_t Count; // [sp+A0h] [bp-4h]@4
  //unsigned int v27; // [sp+ACh] [bp+8h]@5

 class18_ctor(&class18_obj);
 f = class17_FindContainer(pClass17_Icons_LOD, pContainerName, 0);
 if (!f)
 {
  sprintfex(ExistingFileName, "Unable to load %s", pContainerName);
  sub_466BE5(ExistingFileName);
 }

 locked_fread(&class18_obj, 1, 0x30, f);
 if (class18_obj.uDecompressedSize)
 {
  pPCXData = malloc(class18_obj.uDecompressedSize);
  v6 = class23_AllocatedNamedBuffer(class23_instance, 0, class18_obj.uCompressedSize, class18_obj.sContainerName);
  locked_fread(v6, 1, class18_obj.uCompressedSize, f);
  maybe_decompress_file(pPCXData, &class18_obj.uDecompressedSize, v6, class18_obj.uCompressedSize);
  class18_obj.uCompressedSize = class18_obj.uDecompressedSize;
  class23_fn1(class23_instance, v6);
 }
 else
 {
  pPCXData = malloc(class18_obj.uCompressedSize);
  locked_fread(pPCXData, 1, class18_obj.uCompressedSize, f);
 }

  memcpy(local_2, pPCXData, 0x10u);
  memcpy(local_1, (char *)pPCXData + 16, 0x30u);
  memcpy(local_2 + 16, (char *)pPCXData + 64, 6u);

  if ( local_2[3] != 8 )
    return 3;

  v8 = *(int *)(local_2 + 8) - *(int *)(local_2 + 4) + 1;
  v9 = *(int *)(local_2 + 10) - *(int *)(local_2 + 6) + 1;

  _this->uWidth = v8 & 0xFFFF;
  _this->uHeight = v9 & 0xFFFF;

  _this->uNumPixels = (signed __int16)v8 * (signed __int16)v9;

  if (_this->pPixels)
  {
   if (a3)
     goto LABEL_14;
   class23_fn1(class23_instance, _this->pPixels);
  }
  if (!a3)
  {
   _this->pPixels = class23_AllocatedNamedBuffer(class23_instance, _this->pPixels, 2 * _this->uNumPixels + 4, "16bit PCX");
   goto LABEL_17;
  }

LABEL_14:
  if ( a3 != 2 )
    goto LABEL_17;
  _this->pPixels = malloc(2 * _this->uNumPixels + 4);
  _this->dword_000020 |= 1;

LABEL_17:
 if (!_this->pPixels)
   return 2;

 v14 = class33_DecodePCX(_this, pPCXData, _this->pPixels, _this->uWidth);
 call_delete(v14, pPCXData);
 return 0;
}

//----- (MM7.exe::0040F037) --------------------------------------------------------
int class33_DecodePCX(struct class33 *_this, unsigned char *pPCXData, unsigned short *pOutBuffer, unsigned int uWidth)
{
  void *v4; // esi@1
  signed int result; // eax@2
  int v6; // eax@3
  int v7; // edx@3
  signed int v8; // ecx@3
  int v9; // ecx@3
  signed int v10; // ecx@8
  signed int v11; // ebx@37
  unsigned short *v12; // eax@40
  int v13; // edi@40
  int v14; // ebx@41
  unsigned __int8 v15; // bl@42
  unsigned short *v17; // eax@50
  int v18; // ebx@51
  unsigned __int8 v19; // bl@52
  unsigned short *v21; // eax@61
  unsigned __int8 v22; // dl@62
  unsigned __int8 v23; // dl@63
  unsigned __int8 v24; // cl@63

  char local_1[48];
  char v26; // [sp+8h] [bp-54h]@1

  char local_2[24];
  char Dst; // [sp+38h] [bp-24h]@1
  //char v28; // [sp+3Bh] [bp-21h]@1
  //int v29; // [sp+3Ch] [bp-20h]@3
  //int v30; // [sp+40h] [bp-1Ch]@3
  //char v31; // [sp+48h] [bp-14h]@1
  //char v32; // [sp+49h] [bp-13h]@37
  //unsigned __int16 v33; // [sp+4Ah] [bp-12h]@40

  int v34; // [sp+50h] [bp-Ch]@43
  int v35; // [sp+54h] [bp-8h]@38
  unsigned short *v36; // [sp+58h] [bp-4h]@3
  int v37; // [sp+68h] [bp+Ch]@41
  int v38; // [sp+68h] [bp+Ch]@51
  unsigned __int8 v39; // [sp+6Bh] [bp+Fh]@63

  v4 = _this;
 memcpy(local_2, pPCXData, 0x10u);
 memcpy(local_1, (char *)pPCXData + 16, 0x30u);
 memcpy(local_2 + 16, (char *)pPCXData + 64, 6u);

 if (local_2[3] != 8 )
   return 3;

 v6 = *(int *)(local_2 + 8) - *(int *)(local_2 + 4) + 1;
 v9 = *(int *)(local_2 + 10) - *(int *)(local_2 + 6) + 1;

 _this->uWidth = v6 & 0xFFFF;
 _this->uHeight = v9 & 0xFFFF;

 v9 = (signed __int16)v9;
 v36 = v9;

 _this->uNumPixels = (signed __int16)v9 * (signed __int16)v6;

 HIWORD(v7) = 0;
 v8 = 1;
 while (1 << v8 != (signed __int16)v6)
 {
  ++v8;
  if (v8 >= 15)
    goto LABEL_8;
 }
 _this->word_000018 = v8;

LABEL_8:
 v10 = 1;
 while ( 1 << v10 != v36 )
 {
  ++v10;
  if ( v10 >= 15 )
    goto LABEL_13;
 }
 _this->word_00001A = v10;

LABEL_13:
 switch (_this->word_000018)
 {
  case 2:  _this->word_00001C = 3;    break;
  case 3:  _this->word_00001C = 7;    break;
  case 4:  _this->word_00001C = 15;   break;
  case 5:  _this->word_00001C = 31;   break;
  case 6:  _this->word_00001C = 63;   break;
  case 7:  _this->word_00001C = 127;  break;
  case 8:  _this->word_00001C = 255;  break;
  case 9:  _this->word_00001C = 511;  break;
  case 10: _this->word_00001C = 1023; break;
  case 11: _this->word_00001C = 2047; break;
  case 12: _this->word_00001C = 4095; break;
 }

 switch (_this->word_00001A)
 {
  case 2:  _this->word_00001E = 3;    break;
  case 3:  _this->word_00001E = 7;    break;
  case 4:  _this->word_00001E = 15;   break;
  case 5:  _this->word_00001E = 31;   break;
  case 6:  _this->word_00001E = 63;   break;
  case 7:  _this->word_00001E = 127;  break;
  case 8:  _this->word_00001E = 255;  break;
  case 9:  _this->word_00001E = 511;  break;
  case 10: _this->word_00001E = 1023; break;
  case 11: _this->word_00001E = 2047; break;
  case 12: _this->word_00001E = 4095; break;
 }

 v11 = 128;
 if (local_2[17] == 3)
 {
  v35 = 0;
  if ( v36 > 0 )
  {
   v36 = pOutBuffer;
   do
   {
    v12 = v36;
    v13 = 0;
    if (*(short *)(local_2 + 18))
    {
     do
     {
      LOBYTE(v7) = *(pPCXData + v11);
      v14 = v11 + 1;
      v37 = v14;
      if ((v7 & 0xC0) == -64)
      {
       ++v37;
       v15 = *(pPCXData + v14);
       if ((v7 & 0x3F) > 0)
       {
        v34 = v7 & 0x3F;
        do
        {
         ++v13;
         *v12++ = pD3DRenderer->dword_0400D8 & (v15 << (pD3DRenderer->dword_0400D0 + (_BYTE)pD3DRenderer->dword_0400CC + (_BYTE)pD3DRenderer->dword_0400D4 - 8));
         if (v13 == *(short *)(local_2 + 18))
           v12 += (uWidth - *(short *)(local_2 + 18)) - 1;
        }
        while (v34-- != 1);
       }
      }
      else
      {
       v7 &= 0xFFFF00FF;
       v7 = pD3DRenderer->dword_0400D8 & (v7 << (pD3DRenderer->dword_0400D0 + (_BYTE)pD3DRenderer->dword_0400CC + (_BYTE)pD3DRenderer->dword_0400D4 - 8));
       ++v13;
       *v12++ = v7;
      }
      v11 = v37;
     }
     while (v13 < *(short *)(local_2 + 18));
    }

    v17 = v36;
    while (v13 < 2 * *(short *)(local_2 + 18))
    {
     LOBYTE(v7) = *(pPCXData + v11);
     v18 = v11 + 1;
     v38 = v18;
     if ((v7 & 0xC0) == -64)
     {
      ++v38;
      v19 = *(pPCXData + v18);
      if ((v7 & 0x3F) > 0)
      {
       v34 = v7 & 0x3F;
       do
       {
        *v17++ |= (_WORD)pD3DRenderer->dword_0400DC & (unsigned __int16)(v19 << (pD3DRenderer->dword_0400D0
                                                                                  + (_BYTE)pD3DRenderer->dword_0400D4
                                                                                  - 8));
        ++v13;
        if (v13 == *(short *)(local_2 + 18))
          v17 += (uWidth - *(short *)(local_2 + 18)) - 1;
       }
       while (v34-- != 1);
      }
     }
     else
     {
      v7 &= 0xFFFF00FF;
      v7 = pD3DRenderer->dword_0400DC & (v7 << (pD3DRenderer->dword_0400D0 + (_BYTE)pD3DRenderer->dword_0400D4 - 8));
      *v17++ |= v7;
      ++v13;
     }
     v11 = v38;
    }

    v21 = v36;
    while (v13 < 3 * *(short *)(local_2 + 18))
    {
     v22 = *(pPCXData + v11++);
     if ((v22 & 0xC0) == -64)
     {
      v23 = v22 & 0x3F;
      v24 = *(pPCXData + v11++);
      v39 = v24;
      if ((signed int)v23 > 0)
      {
       v34 = v23;
       do
       {
        *v21++ |= v39 >> (8 - pD3DRenderer->dword_0400D4);
        ++v13;
        if (v13 == *(short *)(local_2 + 18))
        {
         v7 = uWidth - *(short *)(local_2 + 18);
         v21 += (uWidth - *(short *)(local_2 + 18)) - 1;
        }
       }
       while (v34-- != 1);
      }
     }
     else
     {
      *v21++ |= v22 >> (8 - pD3DRenderer->dword_0400D4);
      ++v13;
     }
    }
    ++v35;
    v36 += uWidth;
   }
   while (v35 < _this->uHeight);
  }
 }
 result = 0;

 return result;
}









void CIconFrameTable_ctor(struct CIconFrameTable *_this)
{
 memset(_this, 0, sizeof(struct CIconFrameTable));
}

//----- (MM7.exe::00495056) --------------------------------------------------------
void *CIconFrameTable_Initialize(struct CIconFrameTable *_this, void *pSrc)
{
 _this->uNumIcons = *(int *)pSrc;

 _this->pIcons = class23_AllocatedNamedBuffer(class23_instance, _this->pIcons, _this->uNumIcons * sizeof(struct IconFrame), "I Frames");
 memcpy(_this->pIcons, (char *)pSrc + 4, _this->uNumIcons * sizeof(struct IconFrame));

 return _this->pIcons;
}

//----- (MM7.exe::00494F3A) --------------------------------------------------------
unsigned int CIconFrameTable_FindIcon(struct CIconFrameTable *_this, const char *pIconName)
{
 int i;

 if (!_this->uNumIcons)
   return 0;

 for (i = 0; i < _this->uNumIcons; ++i)
 {
  if (!_strcmpi(pIconName, _this->pIcons[i].sIconName))
    return i;
 }
 return 0;
}

//----- (MM7.exe::00494FBF) --------------------------------------------------------
void CIconFrameTable_InitializeIcon(struct CIconFrameTable *_this, unsigned int uIconIdx)
{
 int i;

 if (uIconIdx >= _this->uNumIcons)
   return;

 i = uIconIdx;
 do
 {
  _this->pIcons[i].uTextureIdx = class17_LoadTexture(pClass17_Icons_LOD, _this->pIcons[i].sTextureName, 2);
 }
 while (_this->pIcons[i++].word_00001C & 1);
}