#include "classes.h"
#include "defs.h"
#include "mm7DDrawRenderer.h"
#include "AIL.h"
#include "Smacker.h"

#include "data.h"

extern int monster_list[];
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
void sub_402F07(int *_this);


//----- (MM7.exe::0044E4B7) --------------------------------------------------------
void CGame_ctor(struct CGame *_this)
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
 _this->qword_000E2C = 0;
 //_this->dword_000E30 = 0;
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

 CGame_fn0(_this);
 if (dword_F79D7C != 2 || (dword_4E800C = 1, dword_F79D70 != 4))
   dword_4E800C = 0;
}

//----- (MM7.exe::0044F0FD) --------------------------------------------------------
int CGame_fn0(struct CGame *_this)
{
 CGame_fn1(_this, 1 << 6);
 if (!(_this->uSomeFlags & (1 << 6)))
 {
  _this->dword_000E08 = 0;
  _this->dword_000E0C = 0;
 }
 return _this->uSomeFlags;
}

//----- (MM7.exe::0044F0D8) --------------------------------------------------------
int CGame_fn1(struct CGame *_this, int flags)
{
 if (_this->uSomeFlags & flags)
   _this->uSomeFlags &= ~flags;
 else
   _this->uSomeFlags |= flags;

  return _this->uSomeFlags;
}

//----- (0044EA17) --------------------------------------------------------
extern struct class24 *pClass24_global;
char sub_44EA17(struct CGame *_this)
{
 if (dword_F79D7C != 2 || dword_F79D70 != 4)
   CGammaController_InitializeFromSurface(_this->pGammaController, pD3DRenderer->pdds4_FrontBuffer);

 _this->dword_000E1C = 1;
 _this->qword_000E2C = class24_fn2(pClass24_global);
 return 1;
}

//----- (0044EA5E) --------------------------------------------------------
extern int dword_F8BC18;
extern int dword_F8BC1C;
extern int dword_F8BC20;
extern int dword_4E28F8;
char __thiscall sub_44EA5E(struct CGame *_this, float a2, signed int a3, signed int a4, char a5, int a6, int a7)
{
  int v7; // esi@1
  char result; // al@3
  int v9; // ecx@10
  char v10; // [sp-4h] [bp-24h]@5
  int v11; // [sp+0h] [bp-20h]@5
  int v12; // [sp+4h] [bp-1Ch]@5
  int v13; // [sp+8h] [bp-18h]@5
  const char *v14; // [sp+Ch] [bp-14h]@5
  int v15; // [sp+10h] [bp-10h]@5
  char *v16; // [sp+18h] [bp-8h]@5
  int v17; // [sp+1Fh] [bp-1h]@5

  v7 = _this;
  if (!dword_4E28F8 && pD3DRenderer->dword_040088)
  {
    if ( !_this->class05_obj)
    {
      v15 = 230;
      v14 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Game.cpp";
      v16 = &v10;
      sub_40E2C8(
        &v10,
        "The 'Vis' object pointer has not been instatiated, but CGame::Pick() is trying to call through it.",
        (int)&v17);
      sub_466D09(&v16, *(int *)&v10, v11, v12, v13, v14, v15);
    }
    if ( a3 >= *(int*)class28_global )
    {
      if ( a3 <= dword_F8BC1C )
      {
        if ( a4 >= dword_F8BC18 )
        {
          if ( a4 <= dword_F8BC20 )
          {
            v15 = a7;
            v9 = *(_DWORD *)(v7 + 3660);
            *(float *)&v13 = (double)a4;
            *(float *)&v12 = (double)a3;
            sub_4C0646(v9, a2, *(float *)&v12, *(float *)&v13, a6, a7);
            if ( a5 )
              sub_44EB5A(v7);
          }
        }
      }
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
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
 _this->dword_000E424 = 500;
 _this->dword_000E428 = 0;
 _this->dword_000E42C = 0;
 return memset(_this->dword_000000, 0, 500 * 26 * 4);
}

//----- (MM7.exe::00467E4E) --------------------------------------------------------
struct class03 *class03_ctor(struct class03 *_this, struct class01 *class01_obj)
{
 _this->dword_000024 = 0;
 _this->dword_000028 = 0;
 _this->hWnd = 0;
 _this->ptr_000030 = 0;
 _this->dword_000034 = 0;
 _this->ptr_000038 = 0;
 _this->dword_00003C = 0;
 _this->ptr_000090 = 0;
 _this->class01_obj = class01_obj;
 return _this;
}

//----- (MM7.exe::0046A080) --------------------------------------------------------
int class03_fn1(struct class03 *_this, int a2)
{
 return _this->dword_000004 = a2;
}

//----- (MM7.exe::00469C39) --------------------------------------------------------
POINT *class03_GetMousePos(struct class03 *_this, POINT *pOut)
{
  int *v3; // edx@1
  int v4; // ecx@2
  int v5; // edx@3

 v3 = dword_720010;
 if (dword_720010)
 {
    //*(_DWORD *)a2 = *(_DWORD *)(LODWORD(dword_720010) + 24);
    //v4 = *(_DWORD *)(LODWORD(v3) + 28);
  pOut->x = v3[6];
  pOut->y = v3[7];
 }
 else
 {
  GetCursorPos(pOut);
  //pOut->x = _this->dword_000108;
  //pOut->y = _this->dword_00010C;
 }
 //*(_DWORD *)(a2 + 4) = v4;
 return pOut;
}

//----- (00469860) --------------------------------------------------------
void sub_469860(struct class03 *_this, int *a2, int *a3)
{
  if (dword_720010)
  {
    *a2 = *(_DWORD *)(dword_720010 + 24);
    *a3 = *(_DWORD *)(dword_720010 + 28);
  }
  else
  {
    *a2 = _this->dword_000108;
    *a3 = _this->dword_00010C;
  }
}

//----- (0046A08A) --------------------------------------------------------
void class03_OnMouseLeftButton(struct class03 *_this, int x, int y)
{
 _this->dword_000108 = x;
 _this->dword_00010C = y;
}

//----- (00469C65) --------------------------------------------------------
void sub_469C65(struct class03 *_this, HWND hwnd)
{
 _this->dword_000004 = 0;

 _this->dword_000010 = 1;

 _this->hWnd = hwnd;
 _this->ptr_000030 = 0;
 _this->dword_000034 = 0;
 _this->ptr_000038 = 0;

 _this->dword_0000C4 = 0;
 _this->dword_0000C8 = 0;

 _this->dword_00010C = 0;

 sub_469903(_this, "MICON3");
 sub_469903(_this, "MICON2");
 sub_469903(_this, "MICON1");
}

//----- (00469903) --------------------------------------------------------
extern struct CGame *pGame;
void sub_469903(struct class03 *_this, const char *pSource)
{
 HCURSOR hCursor;
  int v9; // eax@21
  struct tagPOINT Point; // [sp+14h] [bp-8h]@20

 if (!_this->dword_000010 || !pSource)
   return;

 if (_strcmpi("MICON2", pSource))
    pGame->dword_000E24 &= 0xFFFFFFEF;
 else pGame->dword_000E24 |= 0x10;

 if (_strcmpi(_this->array_0000F5, pSource))
   strcpy(_this->array_0000F5, pSource);

 sub_469BA3(_this);

 if (_strnicmp(pSource, "MICON1", 5))
 {
  v9 = class17_LoadTexture(pClass17_Icons_LOD, pSource, 2);
  *(_DWORD *)(_this + 36) = v9;
  *(_DWORD *)(_this + 40) = v9;
  sub_469BE6(_this);
  *(_DWORD *)(_this + 12) = 0;
  *(_DWORD *)(_this + 20) = 1;
  *(_DWORD *)(_this + 4) = 1;
  if ( !dword_506128 )
  {
   sub_40F77C(*(_DWORD *)(_this + 36) != -1 ? 72 * *(_DWORD *)(_this + 36) + 7145548 : 0);
   sub_40F9C5(pClass17_Icons_LOD);
  }
  return;
 }

 _this->dword_000004 = 0;
 _this->dword_00000C = 1;
 if (!strcmp(pSource, "MICON1"))
 {
  hCursor = LoadCursorA(GetModuleHandleW(0), "Arrow");
  SetClassLongA(_this->hWnd, GCL_HCURSOR, hCursor);
  if (dword_720010)
  {
   sub_46B342(dword_720010, 0.0, 0.0);
   sub_46AE97(dword_720010, pSource);
  }
  else
  {
   GetCursorPos(&Point);
   SetCursorPos(Point.x, Point.y);
  }
 }
 else if (!strcmp(pSource, "MICON2"))
 {
  hCursor = LoadCursorA(GetModuleHandleW(0), "Target");
  SetClassLongA(_this->hWnd, GCL_HCURSOR, hCursor);
  if (dword_720010)
  {
   sub_46B342(dword_720010, 14.0, 14.0);
   sub_46AE97(dword_720010, pSource);
  }
  else
  {
   GetCursorPos(&Point);
   SetCursorPos(Point.x, Point.y);
  }
 }
 else if (!strcmp(pSource, "MICON3"))
 {
  hCursor = LoadCursorA(0, (LPCSTR)0x7F02);
  SetClassLongA(_this->hWnd, GCL_HCURSOR, hCursor);

  if (dword_720010)
    sub_46AE97(dword_720010, pSource);
  else
  {
   GetCursorPos(&Point);
   SetCursorPos(Point.x, Point.y);
  }
 }
}

//----- (004698A6) --------------------------------------------------------
extern int dword_AD470C;
void class03_sub_4698A6(struct class03 *_this)
{
 sub_402F07(&dword_AD470C);
 if (_strcmpi(_this->array_0000F5, "MICON2"))
   sub_469903(_this, "MICON1");
}

//----- (00469BA3) --------------------------------------------------------
int sub_469BA3(struct class03 *_this)
{
 _this->dword_000004 = 0;

 if (_this->ptr_000030)
 {
  call_delete(0, _this->ptr_000030);
  _this->ptr_000030 = 0;
 }

 if (_this->ptr_000038)
 {
  call_delete(0, _this->ptr_000038);
  _this->ptr_000038 = 0;
 }

 if (_this->ptr_000090)
 {
  call_delete(0, _this->ptr_000090);
  _this->ptr_000090 = 0;
 }

 return 0;
}






//----- (MM7.exe::0045BB06) --------------------------------------------------------
void *class04_ctor(struct class04 *_this)
{
  int v1; // eax@1
  signed int v2; // ecx@1

 compile_warning;//_eh_vector_constructor_iterator_((char *)_this + 4, 3100, 512, sub_45DF13, sub_45DF48);
 //*((_DWORD *)_this + 396801) = 0;
 _this->dword_183804 = 0;
 compile_warning;//_eh_vector_constructor_iterator_((char *)_this + 1587208, 3100, 768, sub_45DF13, sub_45DF48);
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
  compile_warning;//_eh_vector_constructor_iterator_(v3 + 52, 24, 6, sub_498038, sub_498069);
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

  compile_warning;//_OF = 0;
  compile_warning;//_CF = 0;
  compile_warning;//_ZF = 1;
  compile_warning;//_SF = 0;
  v14 = 0;
  compile_warning;//__asm { pushf }
  v13 = 3;

  compile_warning;//if ( v6 != (v6 ^ 0x40000) )
  if (0)
  {
    compile_warning;//__asm { popf }
    v13 = 4;
    compile_warning;//__asm { pushf }
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
void *class17_fn1(struct class17 *_this, const char *pContainer, int a3)
{
  unsigned char *result; // ebx@7
  unsigned char *v8; // edi@7
  struct class18 class18_obj; // [sp+Ch] [bp-4Ch]@1
  //class18::size1 size_t v12; // [sp+20h] [bp-38h]@3
  //class18::size2 size_t Size; // [sp+34h] [bp-24h]@3
  FILE *pContainerFile; // [sp+54h] [bp-4h]@1

  wchar_t  pLodFile[256];
  void    *hFile;
  DWORD    w;
  int      ofs;


  class18_ctor(&class18_obj);

  pContainerFile = class17_FindContainer(_this, pContainer, 0);
  if (!pContainerFile)
    erroneous_printf("Unable to load %s", pContainer);


    wsprintfW(pLodFile, L".\\%S", _this->sLODName);
    hFile = CreateFileW(pLodFile, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
    ofs = ftell(pContainerFile);
    SetFilePointer(hFile, ofs, 0, FILE_BEGIN);


  //locked_fread(&class18_obj, 1, 0x30u, pContainerFile);
  ReadFile(hFile, &class18_obj, 0x30, &w, 0);
  if (class18_obj.uDecompressedSize)
  {
    if (a3)
      result = malloc(class18_obj.uDecompressedSize);
    else
      result = class23_AllocatedNamedBuffer(class23_instance, 0, class18_obj.uDecompressedSize, class18_obj.sContainerName);

    v8 = class23_AllocatedNamedBuffer(class23_instance, 0, class18_obj.uCompressedSize, class18_obj.sContainerName);

    ReadFile(hFile, v8, class18_obj.uCompressedSize, &w, 0);
    //fread(v8, 1, class18_obj.uCompressedSize, pContainerFile);


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

    CloseHandle(hFile);
    fseek(pContainerFile, ofs + class18_obj.uCompressedSize, SEEK_SET);


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
    if (_this->uNumSubidices > 0)
    {
      v7 = 0;
      //while ( _strcmpi(pContainerName, (const char *)(v7 + *(_DWORD *)(v3 + 560))) )
      while (_strcmpi(pContainerName, (const char *)(_this->pLODSubIndexNamedBuffer) + v7))
      {
        v7 += 32;
        ++v5;
        if (v5 >= _this->uNumSubidices)
          return 0;
      }
      v4 = *(_DWORD *)(32 * v5 + (char *)_this->pLODSubIndexNamedBuffer + 16);
      goto LABEL_12;
    }
    return 0;
  }
  class17_fn3(_this, 0, _this->uNumSubidices, pContainerName);
  if ( dword_6A0CA4 < 0 )
    return 0;
  v4 = *(_DWORD *)((char *)_this->pLODSubIndexNamedBuffer + 32 * dword_6A0CA4 + 16);
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
 v1 = _this->uNumLoadedFiles  - 1;

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
 _this->uNumLoadedFiles = 0;
 _this->dword_011B80 = 0;
 _this->dword_011B84 = 0;

 _this->dword_011B98 = 0;
 _this->dword_011B9C = 0;
}

//----- (MM7.exe::004617D5) --------------------------------------------------------
int class17_MaybeLoadLODHeader(struct class17 *_this, const char *pFilename, char a3)
{
  int v3; // esi@1
  const char *v7; // [sp-4h] [bp-Ch]@4


 if (_this->dword_000104)
   sub_461431(_this);

 if (a3 & 1)
   v7 = "rb";
 else v7 = "rb+";

 _this->pLODFile = fopen(pFilename, v7);
 if (!_this->pLODFile)
   return 1;
 strcpy(_this->sLODName, pFilename);

 locked_fread(&_this->sLODFileHeader, sizeof(struct LODFileHeader), 1, _this->pLODFile);

 //v5 = class23_fn2(class23_instance, *(_DWORD *)(v3 + 528), 160, "LOD CArray");
 _this->dword_000210 = class23_AllocatedNamedBuffer(class23_instance, _this->dword_000210, 160, "LOD CArray");

 if (!_this->dword_000210)
 {
  fclose(_this->pLODFile);
  return 1;
 }

 //locked_fread(_this->dword_000210, 0x20u, *(_DWORD *)(v3 + 444), _this->pLODFile);
 locked_fread(_this->dword_000210, 0x20, _this->sLODFileHeader.array_0000AC, _this->pLODFile);

 fseek(_this->pLODFile, 0, SEEK_SET);
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
  int v7; // eax@7
  int v8; // eax@7
  __int32 v9; // edx@7

 v3 = _this;
 class17_fn7(_this);
 v2 = 0;

 //if ( *(_DWORD *)(v3 + 444) <= 0 )
 if (*(int *)(_this->sLODFileHeader.array_0000AC) <= 0)
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
   if (v2 >= *(int *)(_this->sLODFileHeader.array_0000AC))
     goto LABEL_5;
  }

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
  _this->uNumSubidices = *(_WORD *)(v8 + 28);
  fseek(_this->pLODFile, v9, 0);

  //v6 = class23_AllocatedNamedBuffer(class23_instance, *(_DWORD *)(v3 + 560), 32 * (*(_DWORD *)(v3 + 556) + 5), "LOD Index");
  _this->pLODSubIndexNamedBuffer = class23_AllocatedNamedBuffer(class23_instance, _this->pLODSubIndexNamedBuffer, (_this->uNumSubidices + 5) * sizeof(struct LODIndex), "LOD Index");

  if (_this->pLODSubIndexNamedBuffer)
    locked_fread(_this->pLODSubIndexNamedBuffer, sizeof(struct LODIndex), _this->uNumSubidices, _this->pLODFile);
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
  _this->uNumSubidices = 0;
  _this->dword_000234 = 0;

  result = class23_fn1(class23_instance, _this->pLODSubIndexNamedBuffer);
  _this->pLODSubIndexNamedBuffer = 0;
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
 if (_this->uNumLoadedFiles <= 0 )
 {
LABEL_5:
  if (_this->uNumLoadedFiles >= 1000)
    sub_466B8C();

  if (class17_LoadPalette(_this, &_this->aLODHeaders[_this->uNumLoadedFiles], pContainerName, a3) == -1)
  {
   v6 = 0;
   if (_this->uNumLoadedFiles > 0)
   {
    pClass18 = _this->aLODHeaders;
    while (_strcmpi(pClass18->sContainerName, "pending"))
    {
     pClass18++;
     ++v6;
     if (v6 >= _this->uNumLoadedFiles)
       goto LABEL_15;
    }
    return v6;
   }

LABEL_15:
   class17_LoadPalette(_this, &_this->aLODHeaders[_this->uNumLoadedFiles], "pending", a3);
  }
  dword_506128 = 0;
  _this->uNumLoadedFiles++;
  return _this->uNumLoadedFiles - 1;
 }

 pClass18 = _this->aLODHeaders;
 while (_strcmpi(pClass18->sContainerName, pContainerName))
 {
  ++v3;
  pClass18++;
  if (v3 >= _this->uNumLoadedFiles)
    goto LABEL_5;
 }
 return v3;
}




#include "CbmTools.h"
struct class18 pending_texture;
void *hStdHandle = 0;
unsigned int class17_LoadTextureFromCBM(struct class17 *_this, const wchar_t *pFilename)
{
 DWORD   w;
 wchar_t pFileNotFound[256];

 wchar_t      pFilePath[256];
 unsigned int uCBMWdith,
              uCBMHeight;

 if (_this->uNumLoadedFiles >= 1000)
   sub_466B8C();

 wsprintfW(pFilePath, L".\\Data\\%S\\%s", _this->sContainerName, pFilename);
 if (!LoadCBM(pFilePath, &uCBMWdith, &uCBMHeight, &_this->aLODHeaders[_this->uNumLoadedFiles].pTruecolorPixels))
 {
  if (!hStdHandle)
    hStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  wsprintfW(pFileNotFound, L"CBM not found: %s (%s)\n", pFilename, pFilePath);
  WriteConsoleW(hStdHandle, pFileNotFound, lstrlenW(pFileNotFound), &w, 0);

  if (!pending_texture.pTruecolorPixels)
    pending_texture.pTruecolorPixels = malloc(52 * 53 * 4);
  pending_texture.uTextureWidth = 52;
  pending_texture.uTextureHeight = 53;
  return -1;
 }

 WideCharToMultiByte(CP_ACP, 0, pFilename, -1, _this->aLODHeaders[_this->uNumLoadedFiles].sContainerName, lstrlenW(pFilename) - 4, 0, 0);
 _this->aLODHeaders[_this->uNumLoadedFiles].sContainerName[lstrlenW(pFilename) - 4] = 0;
 _this->aLODHeaders[_this->uNumLoadedFiles].uTextureWidth = uCBMWdith;
 _this->aLODHeaders[_this->uNumLoadedFiles].uTextureHeight = uCBMHeight;

 _this->uNumLoadedFiles++;
 return _this->uNumLoadedFiles - 1;
}

unsigned char *class17_LoadEvent(struct class17 *_this, const wchar_t *pFilename)
{
 DWORD          w;
 void          *hFile;
 unsigned char *pOut;
 wchar_t       pFilepath[256];

 wsprintfW(pFilepath, L".\\Data\\Events\\%s", pFilename);
 hFile = CreateFileW(pFilepath, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);

 pOut = malloc(GetFileSize(hFile, 0));
 ReadFile(hFile, pOut, GetFileSize(hFile, 0), &w, 0);

 CloseHandle(hFile);
 return pOut;
}




//----- (00461954) --------------------------------------------------------
void class17_AllocateSubidexAndIOBuffer(struct class17 *_this, unsigned int uNumSubIndices, signed int uIOBufferSize)
{
 if (_this->pLODSubIndexNamedBuffer)
 {
  MessageBoxW(0, L"Attempt to reset a LOD subindex!", L"MM7", 0x30u);
  class23_fn1(class23_instance, _this->pLODSubIndexNamedBuffer);
  _this->pLODSubIndexNamedBuffer = 0;
 }
 _this->pLODSubIndexNamedBuffer = class23_AllocatedNamedBuffer(class23_instance, _this->pLODSubIndexNamedBuffer, 32 * uNumSubIndices, "LODsubindex");

 if (_this->pLODIOBuffer)
 {
  MessageBoxW(0, L"Attempt to reset a LOD IObuffer!", L"MM7", 0x30u);
  class23_fn1(class23_instance, _this->pLODIOBuffer);
  _this->pLODIOBuffer = 0;
  _this->uIOBufferSize = 0;
 }
 else if (uIOBufferSize)
 {
  _this->pLODIOBuffer = class23_AllocatedNamedBuffer(&class23_instance, _this->pLODIOBuffer, uIOBufferSize, "LODiobuffer");
  _this->uIOBufferSize = uIOBufferSize;
 }
}

//----- (00461A43) --------------------------------------------------------
int class17_LoadLOD_Games(struct class17 *_this, const char *pLODFilename, unsigned char uFileFlags)
{
  void *v3; // esi@1
  char DstBuf[32]; // [sp+Ch] [bp-20h]@5
  //__int32 Offset; // DstBuf + 16
  //int v13; // DstBuf + 20
  //__int16 v14; // DstBuf + 28
  //__int16 v15; // DstBuf + 30

  v3 = _this;

 if (uFileFlags & 1)
   _this->pLODFile = fopen(pLODFilename, "rb");
 else
   _this->pLODFile = fopen(pLODFilename, "rb+");
 if (!_this->pLODFile)
   return false;

 strcpy(_this->sLODName, pLODFilename);

 locked_fread(&_this->sLODFileHeader, sizeof(struct LODFileHeader), 1, _this->pLODFile);

 sub_46172B(DstBuf);

 locked_fread(DstBuf, 0x20, 1, _this->pLODFile);
 fseek(_this->pLODFile, 0, SEEK_SET);

 _this->dword_000104 = 1;
  strcpy(_this->sContainerName, "chapter");

 _this->dword_000224 = 0;
 _this->dword_000228 = *(int *)(DstBuf + 20);
 _this->uNumSubidices = *(int *)(DstBuf + 28);

 _this->dword_000234 = *(int *)(DstBuf + 16);
 fseek(_this->pLODFile, _this->dword_000234, SEEK_SET);

 if (_this->uNumSubidices > 300)
 {
  MessageBoxW(0, L"LODchapterPages exceed 300", L"LODFile", 0x30u);
  fclose(_this->pLODFile);
  return false;
 }

 locked_fread(_this->pLODSubIndexNamedBuffer, sizeof(struct LODIndex), _this->uNumSubidices, _this->pLODFile);
 return true;
}

//----- (MM7.exe::0040FC08) --------------------------------------------------------
int class17_LoadPalette(struct class17 *_this, struct class18 *pClass18, const char *pContainerName, unsigned int uSomeInt)
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
  int v35;
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
  pClass18->pIndexedPixels = class23_AllocatedNamedBuffer(class23_instance, pClass18->pIndexedPixels, pClass18->uCompressedSize, pClass18->sContainerName);
  locked_fread(pClass18->pIndexedPixels, 1u, pClass18->uCompressedSize, f);
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
   pClass18->pIndexedPixels = class23_AllocatedNamedBuffer(class23_instance, pClass18->pIndexedPixels, pClass18->uDecompressedSize, pClass18->sContainerName);
   memcpy(pClass18->pIndexedPixels, pDecompressedBuffer, pClass18->uDecompressedSize);
  }
  call_delete(0, pDecompressedBuffer);
 }


 class23_fn1(class23_instance, pClass18->pPalette);
 class23_fn1(class23_instance, pClass18->ptr_000044);

 if (uSomeInt == 1)
 {
  pClass18->ptr_000044 = class23_AllocatedNamedBuffer(class23_instance, pClass18->ptr_000044, 768, pClass18->sContainerName);
  locked_fread(pClass18->ptr_000044, 1u, 0x300u, f);

LABEL_35:
  pClass18->pPalette = 0;
  goto LABEL_36;
 }

 pClass18->ptr_000044 = 0;
 if (uSomeInt != 2)
   goto LABEL_35;

 pClass18->pPalette = class23_AllocatedNamedBuffer(class23_instance, pClass18->pPalette, 512, pClass18->sContainerName);
 for (i = 0; i < 256; ++i)
 {
  locked_fread(aReadBuf, 3, 1, f);

  pClass18->pPalette[i] = (aReadBuf[0] >> (8 - _this->dword_011B8C)) << (_this->dword_011B94 + _this->dword_011B90);
  pClass18->pPalette[i] += (aReadBuf[1] >> (8 - _this->dword_011B90)) << _this->dword_011B94;
  pClass18->pPalette[i] += aReadBuf[2] >> (8 - _this->dword_011B94);
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
 while (1 << v40 != pClass18->uTextureWidth)
 {
  ++v40;
  if (v40 >= 15)
    goto LABEL_48;
 }
 pClass18->word_00001C = v40;

LABEL_48:
 v41 = 1;
 while ( 1 << v41 != pClass18->uTextureHeight)
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


//----- (0041097D) --------------------------------------------------------
int sub_41097D(struct class17 *_this, int a2, int a3, int a4)
{
 unsigned int v14;
 unsigned int v15;
 
 int             i, j;
 unsigned char   data[4];
 FILE           *f;
 struct class18 *pClass18;
 struct class18  class18_obj;


 if (_this->dword_011B8C != a2 || _this->dword_011B90 != a3 || _this->dword_011B94 != a4)
 {
  _this->dword_011B8C = a2;
  _this->dword_011B90 = a3;
  _this->dword_011B94 = a4;
  if (!_this->uNumLoadedFiles)
    return 0;

  for (i = 0; i < _this->uNumLoadedFiles; ++i)
  {
   pClass18 = &_this->aLODHeaders[i];

   class18_ctor(&class18_obj);
   if (!pClass18->pPalette)
     continue;

   f = class17_FindContainer(_this, pClass18->sContainerName, 0);
   if (!f)
     continue;

   locked_fread(&class18_obj, 1, 0x30, f);
   fseek(f, class18_obj.uCompressedSize, SEEK_CUR);

   for (j = 0; j < 512; ++j)
   {
    locked_fread(data + 0, 1, 1, f);
    locked_fread(data + 1, 1, 1, f);
    locked_fread(data + 2, 1, 1, f);

    v14 = (unsigned short)(data[0] >> (8 - (unsigned char)(_this->dword_011B8C)));
    v15 = (unsigned short)(data[1] >> (8 - (unsigned char)(_this->dword_011B90)));

    pClass18->pPalette[j] = v14 << ((unsigned char)(_this->dword_011B90) + (unsigned char)(_this->dword_011B94));
    pClass18->pPalette[j] |= v15 << (unsigned char)(_this->dword_011B94);
    pClass18->pPalette[j] |= data[2] >> (8 - (unsigned char)(_this->dword_011B94));
   }
  }
 }

 return _this->uNumLoadedFiles;
}

//----- (004114F2) --------------------------------------------------------
int sub_4114F2(struct class17 *_this)
{
  int result; // eax@1
  int v2; // ecx@1
  int v3; // esi@1
  int v4; // ecx@2
  int v5; // edi@3
  int v6; // ebx@4
  int v7; // eax@5
  int v8; // eax@6
  int v9; // eax@8
  int v10; // eax@9

  v3 = _this;
  result = &_this->dword_011B9C;
  v2 = _this->dword_011B9C;
  if ( v2 )
  {
    v4 = v2 - 1;
    _this->dword_011B9C = v4;
    if ( !v4 )
    {
      v5 = _this->uNumLoadedFiles - 1;
      if ( v5 >= _this->dword_011B98)
      {
        v6 = &_this->aLODHeaders[v5];
        do
        {
          sub_40F77C(v6);
          v7 = _this->dword_011BB0;
          if ( v7 )
          {
            v8 = *(_DWORD *)(v7 + 4 * v5);
            if ( v8 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v8 + 8))(v8);
              *(_DWORD *)(*(_DWORD *)(v3 + 72624) + 4 * v5) = 0;
            }
          }
          v9 = *(_DWORD *)(v3 + 72620);
          if ( v9 )
          {
            v10 = *(_DWORD *)(v9 + 4 * v5);
            if ( v10 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v10 + 8))(v10);
              *(_DWORD *)(*(_DWORD *)(v3 + 72620) + 4 * v5) = 0;
            }
          }
          --v5;
          v6 -= 72;
        }
        while ( v5 >= *(_DWORD *)(v3 + 72600) );
      }
      result = *(_DWORD *)(v3 + 72600);
      *(_DWORD *)(v3 + 72600) = 0;
      *(_DWORD *)(v3 + 72572) = result;
    }
  }
  return result;
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
  _this->dword_000020 = v6 - v5 + 1;
  _this->dword_000028 = (v6 + v5) >> 1;
  if (!pD3DRenderer->dword_040088)
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







//----- (0048A8F5) --------------------------------------------------------
int __fastcall sub_452AE2(int a1);
int class35_sub_48A8F5(struct class35 *_this, int a2, int a3, int a4)
{
 _this->dword_267AD8 = a2;
 _this->dword_267ADC = a3;
 _this->dword_267AE0 = a4;

 _this->dword_267AE4 = sub_452AE2(a2) << (a3 + (unsigned char)_this->dword_267AE0);
 _this->dword_267AE8 = sub_452AE2(a3) << a4;
 _this->dword_267AEC = sub_452AE2(a4);
 return _this->dword_267AEC;
}

//----- (0048A614) --------------------------------------------------------
int class35_sub_48A614(struct class35 *_this)
{
 int result; // eax@1
 int i;

 result = class35_sub_489BE0(_this, 0);
 for (i = 1; i < 50; ++i)
 {
  if (_this->array_267A04[i])
    result = class35_sub_489BE0(_this, i);
 }

 return result;
}

//----- (00489BE0) --------------------------------------------------------
signed int __fastcall sub_48A643(float *a1, float *a2, float *a3, float a4, float a5, float a6);
void __fastcall sub_48A7AA(int a1, int a2, float a3, float a4, float a5, int a6);
int class35_sub_489BE0(struct class35 *_this, unsigned int idx)
{
  float v5; // ST08_4@5
  float v6; // ST04_4@5
  float v7; // ST00_4@5
  int v9; // edx@8
  int v10; // ST0C_4@8
  int v11; // ecx@8
  double v21; // st5@11
  int v22; // eax@13
  __int16 v24; // bx@16
  int v25; // eax@16
   double v28; // st7@20
  int v29; // eax@22
  int v32; // eax@25
  double v36; // st5@28
  float v39; // ST08_4@30
  int v40; // edx@33
  int v41; // ecx@33
  int v42; // ebx@33
  int v43; // edi@33
  signed __int64 v44; // qax@33
  int v45; // ecx@33
  int v46; // ecx@35
  int v47; // eax@39
  int v48; // edx@39
  signed int v53; // eax@43
  double v55; // st6@47
  signed __int64 v58; // qax@55
  int v59; // ebx@55
  int v60; // edi@55
  double v61; // st7@56
  int v62; // ecx@57
  int v63; // ecx@59
  int v64; // edx@61
  int v65; // ecx@61
  int v66; // eax@63
  int result; // eax@63
  int v68; // ecx@63

  float v71; // [sp+1Ch] [bp-C38h]@5
  float v72; // [sp+41Ch] [bp-838h]@5
  int v73[256]; // [sp+81Ch] [bp-438h]@5

  int v74; // [sp+C1Ch] [bp-38h]@43
  char v75; // [sp+C20h] [bp-34h]@43
  char v76; // [sp+C24h] [bp-30h]@43
  float v78; // [sp+C2Ch] [bp-28h]@43
  float v79; // [sp+C30h] [bp-24h]@10
  float v83; // [sp+C44h] [bp-10h]@5
  float v84; // [sp+C48h] [bp-Ch]@13
  float v85; // [sp+C4Ch] [bp-8h]@13
  float v86; // [sp+C50h] [bp-4h]@13
  int v87; // [sp+C5Ch] [bp+8h]@33
  signed int v88; // [sp+C5Ch] [bp+8h]@43
  int v90; // [sp+C5Ch] [bp+8h]@57

  struct some_local
  {
   float x;
   float y;
   float z;
   float dummy;
  };

 struct some_local  local_0[256];
 float              scale;
 char              *v2;
 short             *v81;
 int                i, j;

 v2 = _this->aSomeCoords[idx];
 if (_this->byte_267AD3 || _this->byte_267AD4 || _this->byte_267AD5)
 {
  scale = *(double *)(byte_4D8410 + 1096);

  for (i = 0; i < 256; ++i)
  {
   v5 = (double)(v2[i * 3 + 2] + _this->byte_267AD5) * scale;
   v6 = (double)(v2[i * 3 + 1] + _this->byte_267AD4) * scale;
   v7 = (double)(v2[i * 3 + 0] + _this->byte_267AD3) * scale;
   sub_48A7AA(&local_0[i].y, &local_0[i].x, v7, v6, v5, &local_0[i].z);
   v2 += 3;
  }
 }
 else
 {
  scale = *(double *)(byte_4D8410 + 1104);

  for (i = 0; i < 256; ++i)
  {
   v5 = (double)v2[i * 3 + 2] * scale;
   v6 = (double)v2[i * 3 + 1] * scale;
   v7 = (double)v2[i * 3 + 0] * scale;
   sub_48A7AA(&local_0[i].y, &local_0[i].x, v7, v6, v5, &local_0[i].z);
   v2 += 3;
  }
 }


 v81 = _this->aSomeIndices[idx];
 for (i = 0; i < 32; ++i)
 {
  scale = *(double *)&byte_4D8410[24] - (double)i * *(double *)&byte_4D8410[1088];

  for (j = 0; j < 256; ++j)
  {
   v21 = local_0[j].z * scale;

   if (v21 < *(double *)(byte_4D8410 + 176))
     v21 = 0.0;
   sub_48A643(&v85, &v84, &v86, local_0[j].y, local_0[j].x, v21);

   v22 = _this->dword_267ADC;
   if (v22 == 6)
   {
    v85 *= *(double *)(byte_4D8410 + 1080);
    v84 *= *(double *)(byte_4D8410 + 1072);
    v86 *= *(double *)(byte_4D8410 + 1080);
   }
   else
   {
    v85 *= *(double *)(byte_4D8410 + 1080);
    v84 *= *(double *)(byte_4D8410 + 1080);
    v86 *= *(double *)(byte_4D8410 + 1080);
   }

   v24 = (signed __int64)v86 | ((unsigned __int16)(signed __int64)v84 << _this->dword_267AE0) | (unsigned __int16)((unsigned __int16)(signed __int64)v85 << (_this->dword_267AE0 + v22));
   v81[i * 256 + j] = v24;
  }
 }



 v81 = _this->array_199600[idx];
 for (i = 0; i < 32; ++i)
 {
  scale = *(double *)&byte_4D8410[24] - (double)i * *(double *)&byte_4D8410[1088];

  for (j = 0; j < 256; ++j)
  {
   v28 = local_0[j].z * scale;

   if (v28 < *(double *)(byte_4D8410 + 176))
     v28 = 0.0;
   sub_48A643(&v85, &v84, &v86, 1.0, 1.0, v28);

   v29 = _this->dword_267ADC;
   if ( v29 == 6 )
   {
    v85 *= *(double *)&byte_4D8410[1080];
    v84 *= *(double *)&byte_4D8410[1072];
    v86 *= *(double *)&byte_4D8410[1080];
   }
   else
   {
    v85 *= *(double *)&byte_4D8410[1080];
    v84 *= *(double *)&byte_4D8410[1080];
    v86 *= *(double *)&byte_4D8410[1080];
   }

   v24 = (signed __int64)*(float *)&v86 | ((unsigned __int16)(signed __int64)v84 << _this->dword_267AE0) | (unsigned __int16)((unsigned __int16)(signed __int64)v85 << (_this->dword_267AE0 + v29));
   v81[i * 256 + j] = v24;
  }
 }


 v81 = _this->array_261600[idx];
 for (i = 0; i < 256; ++i)
 {
  v36 = (local_0[i].z - *(double *)&byte_4D8410[1056]) * *(double *)&byte_4D8410[1048] + *(double *)&byte_4D8410[1056];
  if (v36 < *(double *)&byte_4D8410[176])
    v36 = 0.0;

  v39 = local_0[i].x * *(double *)&byte_4D8410[1064];
  sub_48A643(&v85, &v84, &v86, local_0[i].y, v39, v36);

  if (_this->dword_267ADC == 6)
  {
   v85 *= *(double *)&byte_4D8410[1080];
   v84 *= *(double *)&byte_4D8410[1072];
   v86 *= *(double *)&byte_4D8410[1080];
  }
  else
  {
   v85 *= *(double *)&byte_4D8410[1080];
   v84 *= *(double *)&byte_4D8410[1080];
   v86 *= *(double *)&byte_4D8410[1080];
  }

  v44 = (signed __int64)((v85 + v84 + v86) * *(double *)&byte_4D8410[640] * 8.0);
  v40 = (_DWORD)v44 >> (8 - (unsigned __int8)_this->dword_267AD8);
  v45 = 8 - _this->dword_267ADC;
  v42 = _this->dword_267AE0;
  v43 = (_DWORD)v44 >> v45;
  v41 = _this->dword_267AD8;
  v87 = (_DWORD)v44 >> (8 - v42);
  if ( v40 > (1 << v41) - 1 )
    v40 = (1 << v41) - 1;
  v46 = _this->dword_267ADC;
  if ( v43 > (1 << v46) - 1 )
    v43 = (1 << v46) - 1;
  if ( v87 > (1 << v42) - 1 )
    v87 = (1 << v42) - 1;
  v48 = v40 << (v42 + (unsigned char)_this->dword_267ADC);

  v81[i] = v87 | ((_WORD)v43 << v42) | (_WORD)v48;
 }


 if (_this->byte_267AD0 || _this->byte_267AD1 || _this->byte_267AD2 != _this->byte_267AD0)
 {
  v88 = _this->byte_267AD1;
  v53 = _this->byte_267AD2;
  v78 = (double)_this->byte_267AD0 * *(double *)&byte_4D8410[1104];
  v79 = (double)v88 * *(double *)&byte_4D8410[1104];
  v83 = (double)v53 * *(double *)&byte_4D8410[1104];
  sub_48A7AA(&v76, &v75, v78, v79, v83, &v74);
 }


 v81 = _this->array_0D1600[idx];
 for (i = 0; i < 32; ++i)
 {
  for (j = 0; j < 256; ++j)
  {
   v55 = local_0[j].x;

   if ( v55 < *(double *)&byte_4D8410[176] )
     v55 = 0.0;

   sub_48A643(&v85, &v84, &v86, local_0[j].y, v55, local_0[j].z);
   if (_this->dword_267ADC == 6 )
   {
    v85 *= *(double *)&byte_4D8410[1080];
    v84 *= *(double *)&byte_4D8410[1072];
    v86 *= *(double *)&byte_4D8410[1080];
   }
   else
   {
    v85 *= *(double *)&byte_4D8410[1080];
    v84 *= *(double *)&byte_4D8410[1080];
    v86 *= *(double *)&byte_4D8410[1080];
   }

   if (_this->byte_267AD0 || _this->byte_267AD1 || _this->byte_267AD2)
   {
    v61 = (double)i * *(double *)&byte_4D8410[1088];
    v60 = (signed __int64)((double)(1 << _this->dword_267AD8) * v78 * v61 + v85 * (1.0 - v61));
    v59 = (signed __int64)((double)(1 << _this->dword_267ADC) * v79 * v61 + v84 * (1.0 - v61));
    v58 = (signed __int64)((double)(1 << _this->dword_267AE0) * v83 * v61 + v86 * (1.0 - v61));
   }
   else
   {
    v60 = (signed __int64)v85;
    v59 = (signed __int64)v84;
    v58 = (signed __int64)v86;
   }

   v62 = _this->dword_267AD8;
   v90 = v58;
   if ( v60 > (1 << v62) - 1 )
     v60 = (1 << v62) - 1;

   v63 = _this->dword_267ADC;
   if ( v59 > (1 << v63) - 1 )
     v59 = (1 << v63) - 1;

   v64 = _this->dword_267AE0;
   v65 = _this->dword_267AE0;
   if ( v90 > (1 << v65) - 1 )
     v90 = (1 << v65) - 1;

   v66 = _this->dword_267ADC;
   v68 = v64 + v66;

   v81[i * 256 + j] = v90 | ((_WORD)v59 << v64) | (unsigned __int16)((_WORD)v60 << v68);
  }
 }
 return rand() % 0xFFFF;
}








//----- (0043B688) --------------------------------------------------------
int sub_43B538(); // weak
int sub_43B569(); // weak
void *class36_ctor(struct class36 *_this)
{
 _this->dword_000000 = 0x4D8600;
 //_eh_vector_constructor_iterator_(_this->vector_000004, 40, 64, sub_43B538, sub_43B569);
 _this->dword_000A04 = 0;
 _this->dword_000A08 = 0;
 return _this;
}




//----- (0043F282) --------------------------------------------------------
int loc_43F2A9();
int loc_43F2BF();
void *class37_ctor(struct class37 *_this)
{
 //_eh_vector_constructor_iterator_(_this->vector_000FA8, 2252, 150, loc_43F2BF, loc_43F2A9);
 return _this;
}












//----- (00456D84) --------------------------------------------------------
char *__fastcall sub_452C30(char *Str);
extern int dword_5C8B08; // weak
extern int dword_5C8B0C; // weak
extern int dword_5C8B10; // weak
extern char *dword_5C8B14; // idb
extern int dword_5C8B18; // weak
extern int dword_5C8B1C; // weak
extern int dword_5C8B20; // weak
extern int dword_5C8B24; // weak
extern int dword_5C8B28; // weak
extern int dword_5C8B2C; // weak
extern int dword_5C8B30; // weak
extern int dword_5C8B34; // weak
extern int dword_5C8B38; // weak
extern int dword_5C8B3C; // weak
extern int dword_5C8B40; // weak
extern int dword_5C8B44; // weak
extern int dword_5C8B48; // weak
extern int dword_5C8B4C; // weak
extern int dword_5C8B50; // weak
extern int dword_5CCE30;
extern int array_5C86E0[];
extern unsigned char *array_5C8810[];
extern unsigned char *array_5C88A8[];
extern unsigned char *array_5C8940[];
extern unsigned char *array_5C89D8[];
extern unsigned char *array_5C8A70[];
extern int dword_5C8778[];
extern int dword_5C88A8;
extern char unk_5C876C;
extern struct CMapStats *pMapStats;
extern struct CMonsterStats *pMonsterStats;
extern struct CSpellStats *pSpellStats;
extern struct class48 *pClass48;
extern struct StorylineText *pStorylineText;
extern unsigned char *pClassTXT_Raw;
extern unsigned char *pStatsTXT_Raw;
extern unsigned char *pSkillDescTXT_Raw;
char *sub_456D84(struct class40 *_this)
{
  void *v1; // edi@1
  char *v3; // eax@2
  char v4; // cl@3
  int v5; // esi@3
  int v9; // ecx@22
  char *v12; // eax@26
  char v13; // dl@27
  int v14; // ecx@27
  int v15; // esi@31
  int v17; // esi@40
  int v18; // eax@41
  char v19; // cl@41
  char v20; // zf@53
  int v21; // eax@57
  int v28; // esi@71
  char *v30; // ebx@72
  int v31; // eax@73
  char v32; // cl@73
  int v33; // ST3C_4@160
  int v34; // ST3C_4@163
  int v35; // eax@175
  int v36; // eax@188
  char v37; // al@190
  int v39; // esi@199
  char *v41; // eax@200
  char v42; // dl@201
  int v43; // ecx@201
  int v44; // eax@229
  int v45; // esi@229
  int v46; // ecx@230
  char *v49; // esi@233
  char *v50; // eax@234
  char v51; // dl@235
  int v52; // ecx@235
  signed int v53; // edi@287
  char *v54; // ecx@288
  int v55; // eax@289
  char v56; // dl@289
  int v57; // esi@293
  char *v58; // ecx@312
  signed int v59; // edi@312
  int v60; // eax@313
  char v61; // dl@313
  int v62; // esi@317
  char *result; // eax@348
  signed int v64; // edi@348
  char v65; // dl@349
  int v66; // ecx@349
  int v67; // esi@353
  int v68; // [sp+Ch] [bp-18h]@1
  signed int v69; // [sp+Ch] [bp-18h]@22
  signed int v70; // [sp+Ch] [bp-18h]@25
  signed int v73; // [sp+Ch] [bp-18h]@156
  signed int v76; // [sp+Ch] [bp-18h]@230
  signed int v77; // [sp+Ch] [bp-18h]@311
  signed int v78; // [sp+Ch] [bp-18h]@347
  int v79; // [sp+10h] [bp-14h]@7
  signed int v80; // [sp+10h] [bp-14h]@21
  int v81; // [sp+10h] [bp-14h]@45
  int v82; // [sp+10h] [bp-14h]@77
  int v83; // [sp+10h] [bp-14h]@205
  signed int v84; // [sp+10h] [bp-14h]@229
  int v85; // [sp+10h] [bp-14h]@239
  signed int v86; // [sp+14h] [bp-10h]@1
  int v88; // [sp+14h] [bp-10h]@175
  int v89; // [sp+14h] [bp-10h]@188
  signed int v90; // [sp+18h] [bp-Ch]@67
  size_t v91; // [sp+18h] [bp-Ch]@156
  signed int v92; // [sp+18h] [bp-Ch]@176
  signed int v93; // [sp+18h] [bp-Ch]@182
  signed int v94; // [sp+18h] [bp-Ch]@233
  signed int v95; // [sp+1Ch] [bp-8h]@2
  signed int v96; // [sp+1Ch] [bp-8h]@26
  signed int v97; // [sp+1Ch] [bp-8h]@40
  signed int v98; // [sp+1Ch] [bp-8h]@72
  signed int v99; // [sp+1Ch] [bp-8h]@200
  signed int v100; // [sp+1Ch] [bp-8h]@234
  signed int v101; // [sp+1Ch] [bp-8h]@288
  signed int v102; // [sp+1Ch] [bp-8h]@312
  signed int v103; // [sp+1Ch] [bp-8h]@348
  signed int v104; // [sp+20h] [bp-4h]@2
  signed int v105; // [sp+20h] [bp-4h]@26
  signed int v106; // [sp+20h] [bp-4h]@40
  signed int v107; // [sp+20h] [bp-4h]@72
  signed int v108; // [sp+20h] [bp-4h]@200
  signed int v109; // [sp+20h] [bp-4h]@234
  signed int v110; // [sp+20h] [bp-4h]@288
 int i, j;

  v1 = _this;

  pMapStats = malloc(sizeof(struct CMapStats));
  CMapStats_ctor(pMapStats);
  CMapStats_Initialize(pMapStats);

  pMonsterStats = malloc(sizeof(struct CMonsterStats));
  CMonsterStats_ctor(pMonsterStats);
  CMonsterStats_Initialize(pMonsterStats);
  CMonsterStats_LoadMonsterPlacements(pMonsterStats);

  pSpellStats = malloc(sizeof(struct CSpellStats));
  CSpellStats_ctor(pSpellStats);
  CSpellStats_Initialize(pSpellStats);

  sub_453B3C(_this);
  sub_453CE5(_this);

  pClass48 = malloc(sizeof(struct class48));
  class48_ctor(pClass48);
  class48_Initialize(pClass48);

  pStorylineText = malloc(sizeof(struct StorylineText));
  StorylineText_Initialize(pStorylineText);

  _this->pStdItemsTXT_Raw = class17_fn1(pClass17_Events_LOD, "stditems.txt", 0);

  strtok(_this->pStdItemsTXT_Raw, "\r");
  strtok(0, "\r");
  strtok(0, "\r");
  strtok(0, "\r");
  v68 = _this->pEnchantments;
  v86 = 24;

  i = 0;
  do
  {
    v3 = strtok(0, "\r") + 1;
    v104 = 0;
    v95 = 0;
    do
    {
      v4 = *v3;
      v5 = 0;
      while ( v4 != 9 && v4 )
      {
        ++v5;
        v4 = v3[v5];
      }
      v79 = (int)&v3[v5];
      if ( !v3[v5] )
        v95 = 1;
      v3[v5] = 0;
      if ( v5 )
      {
        if ( v104 )
        {
          if ( v104 == 1 )
          {
           _this->pEnchantments[i].pName = sub_452C30(v3);
          }
          else
          {
            if ( v104 > 1 )
              _this->pEnchantments[i].array_000008[v104 - 2] = atoi(v3);
          }
        }
        else
        {
         _this->pEnchantments[i].pParam = sub_452C30(v3);
        }
      }
      else
      {
        if ( !v104 )
          v95 = 1;
      }
      ++v104;
      v3 = (char *)(v79 + 1);
    }
    while ( v104 <= 10 && !v95 );
    v68 += 20;
    ++i;
  }
  while ( v86-- != 1 );

  memset(_this->array_0116E4, 0, 9 * sizeof(int));
  for (i = 0; i < 9; ++i)
    for (j = 0; j < 24; ++j)
      _this->array_0116E4[i] += _this->pEnchantments[j].array_000008[i];

  strtok(0, "\r");
  strtok(0, "\r");
  strtok(0, "\r");
  strtok(0, "\r");
  strtok(0, "\r");
  for (i = 0; i < 6; ++i)
  {
    v12 = strtok(0, "\r") + 1;
    v105 = 0;
    v96 = 0;
    do
    {
      v13 = *v12;
      v14 = 0;
      while ( v13 != 9 && v13 )
      {
        ++v14;
        v13 = v12[v14];
      }
      v15 = (int)&v12[v14];
      if ( !v12[v14] )
        v96 = 1;
      *(_BYTE *)v15 = 0;
      if ( v14 )
      {
        if ( v105 > 1 )
          _this->array_011700[i][v105 - 2] = atoi(v12);
      }
      ++v105;
      v12 = (char *)(v15 + 1);
    }
    while ( v105 < 4 && !v96 );
  }



  _this->pSpcItemsTXT_Raw = class17_fn1(pClass17_Events_LOD, "spcitems.txt", 0);
  strtok(_this->pSpcItemsTXT_Raw, "\r");
  strtok(0, "\r");
  strtok(0, "\r");
  strtok(0, "\r");

  for (i = 0; i < 72; ++i)
  {
    v106 = 0;
    v17 = (int)(strtok(0, "\r") + 1);
    v97 = 0;
    do
    {
      v19 = *(_BYTE *)v17;
      v18 = 0;
      while ( v19 != 9 && v19 )
      {
        ++v18;
        v19 = *(_BYTE *)(v18 + v17);
      }
      v81 = v18 + v17;
      if ( !*(_BYTE *)(v18 + v17) )
        v97 = 1;
      *(_BYTE *)(v18 + v17) = 0;
      if ( v18 )
      {
        if ( v106 )
        {
          if ( v106 == 1 )
          {
           _this->pSpecialEnchantments[i].pName = sub_452C30((const char *)v17);
          }
          else
          {
            if ( v106 <= 1 )
            {
              v20 = v106 == 14;
            }
            else
            {
              v20 = v106 == 14;
              if ( v106 < 14 )
              {
               _this->pSpecialEnchantments[i].array_000008[v106 - 2] = atoi((const char *)v17);
                goto LABEL_63;
              }
            }
            if ( v20 )
            {
              v21 = atoi((const char *)v17);
              _this->pSpecialEnchantments[i].dword_000014 = v21;
              if ( !v21 )
                _this->pSpecialEnchantments[i].dword_000014 = atoi((const char *)(v17 + 1));
            }
            else
            {
              if ( v106 == 15 )
                _this->pSpecialEnchantments[i].byte_000018 = tolower(*(_BYTE *)v17) - 97;
            }
          }
        }
        else
        {
         _this->pSpecialEnchantments[i].pParam = sub_452C30((const char *)v17);
        }
      }
      else
      {
        if ( !v106 )
          v97 = 1;
      }
LABEL_63:
      ++v106;
      v17 = v81 + 1;
    }
    while ( v106 <= 15 && !v97 );
  }




  memset(_this->array_011738, 0, 24 * sizeof(int));

  _this->dword_011798 = 71;
  for (i = 0; i < 12; ++i)
  { 
      for (j = 0; j < _this->dword_011798; ++j)
        _this->array_011738[i] += _this->pSpecialEnchantments[j].array_000008[i];
  }
  sub_443801();


  _this->pItemsTXT_Raw = class17_fn1(pClass17_Events_LOD, "items.txt", 0);
  strtok(_this->pItemsTXT_Raw, "\r");
  v28 = 0;
  strtok(0, "\r");
  _this->uNumItems = 0;
  while (true)
  {
    v107 = 0;
    v30 = strtok(0, "\r") + 1;
    v98 = 0;
    while (true)
    {
      v32 = *v30;
      v31 = 0;
      while ( v32 != 9 && v32 )
      {
        ++v31;
        v32 = v30[v31];
      }
      v82 = (int)&v30[v31];
      if ( !v30[v31] )
        v98 = 1;
      v30[v31] = 0;
      if ( v31 )
      {
        switch ( v107 )
        {
          case 0: v28 = atoi(v30); break;
          case 1: _this->pItems[v28 - 1].pIconName = sub_452C30(v30); break;
          case 2: _this->pItems[v28 - 1].pName = sub_452C30(v30);     break;
          case 3: _this->pItems[v28 - 1].uValue = atoi(v30);          break;

          case 4:
            if (!_strcmpi(v30, "weapon") || !_strcmpi(v30, "weapon1or2"))
              _this->pItems[v28 - 1].uEquipType = 0;
            else if (!_strcmpi(v30, "weapon2"))
              _this->pItems[v28 - 1].uEquipType = 1;
            else if (!_strcmpi(v30, "missile") || !_strcmpi(v30, "bow"))
              _this->pItems[v28 - 1].uEquipType = 2;
            else if (!_strcmpi(v30, "armor"))
              _this->pItems[v28 - 1].uEquipType = 3;
            else if (!_strcmpi(v30, "shield"))
              _this->pItems[v28 - 1].uEquipType = 4;
            else if (!_strcmpi(v30, "helm"))
              _this->pItems[v28 - 1].uEquipType = 5;
            else if (!_strcmpi(v30, "belt"))
              _this->pItems[v28 - 1].uEquipType = 6;
            else if (!_strcmpi(v30, "cloak"))
              _this->pItems[v28 - 1].uEquipType = 7;
            else if (!_strcmpi(v30, "gauntlets"))
              _this->pItems[v28 - 1].uEquipType = 8;
            else if (!_strcmpi(v30, "boots"))
              _this->pItems[v28 - 1].uEquipType = 9;
            else if (!_strcmpi(v30, "ring"))
              _this->pItems[v28 - 1].uEquipType = 10;
            else if (!_strcmpi(v30, "amulet"))
              _this->pItems[v28 - 1].uEquipType = 11;
            else if (!_strcmpi(v30, "weaponw"))
              _this->pItems[v28 - 1].uEquipType = 12;
            else if (!_strcmpi(v30, "herb") || !_strcmpi(v30, "reagent"))
              _this->pItems[v28 - 1].uEquipType = 13;
            else if (!_strcmpi(v30, "bottle"))
              _this->pItems[v28 - 1].uEquipType = 14;
            else if (!_strcmpi(v30, "sscroll"))
              _this->pItems[v28 - 1].uEquipType = 15;
            else if (!_strcmpi(v30, "book"))
              _this->pItems[v28 - 1].uEquipType = 16;
            else if (!_strcmpi(v30, "mscroll"))
              _this->pItems[v28 - 1].uEquipType = 17;
            else if (!_strcmpi(v30, "gold"))
              _this->pItems[v28 - 1].uEquipType = 18;
            else if (!_strcmpi(v30, "gem"))
              _this->pItems[v28 - 1].uEquipType = 19;
            else
              _this->pItems[v28 - 1].uEquipType = 20;
            break;

          case 5:
            if (!_strcmpi(v30, "staff"))
              _this->pItems[v28 - 1].uSkillType = 0;
            else if (!_strcmpi(v30, "sword"))
              _this->pItems[v28 - 1].uSkillType = 1;
            else if (!_strcmpi(v30, "dagger"))
              _this->pItems[v28 - 1].uSkillType = 2;
            else if (!_strcmpi(v30, "axe"))
              _this->pItems[v28 - 1].uSkillType = 3;
            else if (!_strcmpi(v30, "spear"))
              _this->pItems[v28 - 1].uSkillType = 4;
            else if (!_strcmpi(v30, "bow"))
              _this->pItems[v28 - 1].uSkillType = 5;
            else if (!_strcmpi(v30, "mace"))
              _this->pItems[v28 - 1].uSkillType = 6;
            else if (!_strcmpi(v30, "blaster"))
              _this->pItems[v28 - 1].uSkillType = 7;
            else if (!_strcmpi(v30, "shield"))
              _this->pItems[v28 - 1].uSkillType = 8;
            else if (!_strcmpi(v30, "leather"))
              _this->pItems[v28 - 1].uSkillType = 9;
            else if (!_strcmpi(v30, "chain"))
              _this->pItems[v28 - 1].uSkillType = 10;
            else if (!_strcmpi(v30, "plate"))
              _this->pItems[v28 - 1].uSkillType = 11;
            else if (!_strcmpi(v30, "club"))
              _this->pItems[v28 - 1].uSkillType = 37;
            else
              _this->pItems[v28 - 1].uSkillType = 38;
            break;

          case 6:
            v73 = 0;
            v91 = strlen(v30);
            if ( (signed int)v91 > 0 )
            {
              while ( tolower((unsigned __int8)v30[v73]) != 100 )
              {
                ++v73;
                if ( v73 >= (signed int)v91 )
                  goto LABEL_161;
              }
              v30[v73] = 0;
              v33 = (int)((char *)v1 + 48 * v28);
              *(_BYTE *)(v33 + 34) = atoi(v30);
              *(_BYTE *)(v33 + 35) = atoi(&v30[v73 + 1]);
              v30[v73] = 100;
            }
LABEL_161:
            if ( v73 == v91 )
            {
              if ( tolower((unsigned __int8)*v30) != 115 )
              {
                v34 = (int)((char *)v1 + 48 * v28);
                *(_BYTE *)(v34 + 34) = atoi(v30);
                *(_BYTE *)(v34 + 35) = 1;
              }
            }
            break;

          case 7: _this->pItems[v28 - 1].uDamageModifier = atoi(v30); break;

          case 8:
            if (!_strcmpi(v30, "artifact") )
              _this->pItems[v28 - 1].uMaterial = 1;
            else if (!_strcmpi(v30, "relic") )
              _this->pItems[v28 - 1].uMaterial = 2;
            else if (!_strcmpi(v30, "special") )
              _this->pItems[v28 - 1].uMaterial = 3;
            else
              _this->pItems[v28 - 1].uMaterial = 0;
            break;

          case 9:  break;//_this->pItems[v28 - 1].byte_000032 = atoi(v30); break;
          case 10: _this->pItems[v28 - 1].pUnidentifiedName = sub_452C30(v30); break;
          case 11: _this->pItems[v28 - 1].uSpriteIndex = atoi(v30); break;

          case 12:
            v35 = (int)((char *)v1 + 48 * v28);
            v88 = v35;
            if ( *(_BYTE *)(v35 + 37) == 3 )
            {
              v92 = 0;
              while ( _strcmpi(_this->pEnchantments[v92].pName, v30) )
              {
                ++v92;
                if ( v92 >= 24 )
                  goto LABEL_181;
              }
              *(_BYTE *)(v88 + 39) = v92 + 1;
LABEL_181:
              if ( !*(_BYTE *)(v88 + 39) )
              {
                v93 = 0;
                while ( _strcmpi(_this->pSpecialEnchantments[v92].pName, v30) )
                {
                  ++v93;
                  if ( v93 >= 72 )
                    goto LABEL_196;
                }
                *(_BYTE *)(v88 + 38) = v93 + 1;
              }
            }
            else
            {
              _this->pItems[v28 - 1].byte_000026 = 0;
              _this->pItems[v28 - 1].byte_000027 = 0;
            }
            break;

          case 13:
            v36 = (int)((char *)v1 + 48 * v28);
            v89 = v36;
            if ( *(_BYTE *)(v36 + 37) == 3 && *(_BYTE *)(v36 + 39) )
            {
              v37 = atoi(v30);
              *(_BYTE *)(v89 + 40) = v37;
              if ( !v37 )
                *(_BYTE *)(v89 + 40) = 1;
            }
            else
            {
              _this->pItems[v28 - 1].byte_000028 = 0;
            }
            break;

          case 14: _this->pItems[v28 - 1].uEquipX = atoi(v30); break;
          case 15: _this->pItems[v28 - 1].uEquipY = atoi(v30); break;
          case 16: _this->pItems[v28 - 1].pDescription = sub_452C30(v30); break;

          default:
            break;
        }
      }
LABEL_196:
      ++v107;
      v30 = (char *)(v82 + 1);
      if ( v107 <= 16 && !v98 )
        continue;
      break;
    }
    ++v28;
    if ( v28 < 800 )
      continue;
    break;
  }
  _this->uNumItems = v28;

  _this->pRndItemsTXT_Raw = class17_fn1(pClass17_Events_LOD, "rnditems.txt", 0);
  strtok(_this->pRndItemsTXT_Raw, "\r");
  v39 = 0;
  strtok(0, "\r");
  strtok(0, "\r");
  strtok(0, "\r");
  do
  {
    v108 = 0;
    v41 = strtok(0, "\r") + 1;
    v99 = 0;
    do
    {
      v42 = *v41;
      v43 = 0;
      while ( v42 != 9 && v42 )
      {
        ++v43;
        v42 = v41[v43];
      }
      v83 = (int)&v41[v43];
      if ( !v41[v43] )
        v99 = 1;
      *(_BYTE *)v83 = 0;
      if ( v43 )
      {
        if ( v108 )
        {
          switch ( v108 )
          {
            case 2:
              *((_BYTE *)v1 + 48 * v39 + 44) = atoi(v41);
              break;
            case 3:
              *((_BYTE *)v1 + 48 * v39 + 45) = atoi(v41);
              break;
            case 4:
              *((_BYTE *)v1 + 48 * v39 + 46) = atoi(v41);
              break;
            case 5:
              *((_BYTE *)v1 + 48 * v39 + 47) = atoi(v41);
              break;
            case 6:
              *((_BYTE *)v1 + 16 * (3 * v39 + 3)) = atoi(v41);
              break;
            case 7:
              *((_BYTE *)v1 + 48 * v39 + 49) = atoi(v41);
              break;
          }
        }
        else
        {
          v39 = atoi(v41);
        }
      }
      else
      {
        if ( !v108 )
          v99 = 1;
      }
      ++v108;
      v41 = (char *)(v83 + 1);
    }
    while ( v108 <= 7 && !v99 );
    ++v39;
  }
  while ( v39 < 619 );

  if (_this->pRndItemsTXT_Raw)
  {
   class23_fn1(class23_instance, _this->pRndItemsTXT_Raw);
   _this->pRndItemsTXT_Raw = 0;
  }
  v45 = (int)((char *)v1 + 71300);
  memset((char *)v1 + 71300, 0, 0x18u);
  v44 = (int)((char *)v1 + 44);
  v84 = 6;
  do
  {
    v46 = v44;
    v76 = 800;
    do
    {
      *(_DWORD *)v45 += *(_BYTE *)v46;
      v46 += 48;
    }
    while ( v76-- != 1 );
    v45 += 4;
    ++v44;
  }
  while ( v84-- != 1 );
  v49 = 0;
  strtok(0, "\r");
  strtok(0, "\r");
  strtok(0, "\r");
  strtok(0, "\r");
  strtok(0, "\r");
  v94 = 0;
  do
  {
    v50 = strtok(v49, "\r") + 1;
    v109 = (signed int)v49;
    v100 = (signed int)v49;
    do
    {
      v51 = *v50;
      v52 = 0;
      while ( v51 != 9 && v51 )
      {
        ++v52;
        v51 = v50[v52];
      }
      v85 = (int)&v50[v52];
      if ( !v50[v52] )
        v100 = 1;
      v49 = 0;
      *(_BYTE *)v85 = 0;
      if ( v52 )
      {
        switch ( v109 )
        {
          case 2:
            if ( v94 )
            {
              if ( v94 == 1 )
              {
                *((_DWORD *)v1 + 17837) = atoi(v50);
              }
              else
              {
                if ( v94 == 2 )
                  *((_DWORD *)v1 + 17843) = atoi(v50);
              }
            }
            else
            {
              *((_DWORD *)v1 + 17831) = atoi(v50);
            }
            break;
          case 3:
            if ( v94 )
            {
              if ( v94 == 1 )
              {
                *((_DWORD *)v1 + 17838) = atoi(v50);
              }
              else
              {
                if ( v94 == 2 )
                  *((_DWORD *)v1 + 17844) = atoi(v50);
              }
            }
            else
            {
              *((_DWORD *)v1 + 17832) = atoi(v50);
            }
            break;
          case 4:
            if ( v94 )
            {
              if ( v94 == 1 )
              {
                *((_DWORD *)v1 + 17839) = atoi(v50);
              }
              else
              {
                if ( v94 == 2 )
                  *((_DWORD *)v1 + 17845) = atoi(v50);
              }
            }
            else
            {
              *((_DWORD *)v1 + 17833) = atoi(v50);
            }
            break;
          case 5:
            if ( v94 )
            {
              if ( v94 == 1 )
              {
                *((_DWORD *)v1 + 17840) = atoi(v50);
              }
              else
              {
                if ( v94 == 2 )
                  *((_DWORD *)v1 + 17846) = atoi(v50);
              }
            }
            else
            {
              *((_DWORD *)v1 + 17834) = atoi(v50);
            }
            break;
          case 6:
            if ( v94 )
            {
              if ( v94 == 1 )
              {
                *((_DWORD *)v1 + 17841) = atoi(v50);
              }
              else
              {
                if ( v94 == 2 )
                  *((_DWORD *)v1 + 17847) = atoi(v50);
              }
            }
            else
            {
              *((_DWORD *)v1 + 17835) = atoi(v50);
            }
            break;
          case 7:
            if ( v94 )
            {
              if ( v94 == 1 )
              {
                *((_DWORD *)v1 + 17842) = atoi(v50);
              }
              else
              {
                if ( v94 == 2 )
                  *((_DWORD *)v1 + 17848) = atoi(v50);
              }
            }
            else
            {
              *((_DWORD *)v1 + 17836) = atoi(v50);
            }
            break;
        }
      }
      ++v109;
      v50 = (char *)(v85 + 1);
    }
    while ( v109 <= 7 && !v100 );
    ++v94;
  }
  while ( v94 < 3 );


  pSkillDescTXT_Raw = class17_fn1(pClass17_Events_LOD, "skilldes.txt", 0);
  strtok(pSkillDescTXT_Raw, "\r");
  v53 = 0;
  do
  {
    v110 = 0;
    v101 = 0;
    v54 = strtok(0, "\r") + 1;
    do
    {
      v56 = *v54;
      v55 = 0;
      while ( v56 != 9 && v56 )
      {
        ++v55;
        v56 = v54[v55];
      }
      v57 = (int)&v54[v55];
      if ( !v54[v55] )
        v101 = 1;
      *(_BYTE *)v57 = 0;
      if ( v55 )
      {
        switch ( v110 )
        {
          case 1:
            array_5C8A70[v53] = sub_452C30(v54);
            break;
          case 2:
            array_5C89D8[v53] = sub_452C30(v54);
            break;
          case 3:
            array_5C8940[v53] = sub_452C30(v54);
            break;
          case 4:
            array_5C88A8[v53] = sub_452C30(v54);
            break;
          case 5:
            array_5C8810[v53] = sub_452C30(v54);
            break;
        }
      }
      else
      {
        if ( !v110 )
          v101 = 1;
      }
      ++v110;
      v54 = (char *)(v57 + 1);
    }
    while ( v110 <= 5 && !v101 );
    v53++;
  }
  while ( v53 < 37 );

  pStatsTXT_Raw = class17_fn1(pClass17_Events_LOD, "stats.txt", 0);
  strtok(pStatsTXT_Raw, "\r");
  v77 = 0;
  do
  {
    v59 = 0;
    v102 = 0;
    v58 = strtok(0, "\r") + 1;
    do
    {
      v61 = *v58;
      v60 = 0;
      if ( *v58 != 9 )
      {
        do
        {
          if ( !v61 )
            break;
          ++v60;
          v61 = v58[v60];
        }
        while ( v61 != 9 );
      }
      v62 = (int)&v58[v60];
      if ( !v58[v60] )
        v102 = 1;
      *(_BYTE *)v62 = 0;
      if ( v60 )
      {
        if ( v59 )
        {
          switch ( v77 )
          {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
              dword_5C8778[v77] = (int)sub_452C30(v58);
              break;
            case 7:
              dword_5C8B08 = (int)sub_452C30(v58);
              break;
            case 8:
              dword_5C8B10 = (int)sub_452C30(v58);
              break;
            case 9:
              dword_5C8B0C = (int)sub_452C30(v58);
              break;
            case 10:
              dword_5C8B14 = sub_452C30(v58);
              break;
            case 11:
              dword_5C8B18 = (int)sub_452C30(v58);
              break;
            case 12:
              dword_5C8B1C = (int)sub_452C30(v58);
              break;
            case 13:
              dword_5C8B20 = (int)sub_452C30(v58);
              break;
            case 14:
              dword_5C8B24 = (int)sub_452C30(v58);
              break;
            case 15:
              dword_5C8B28 = (int)sub_452C30(v58);
              break;
            case 16:
              dword_5C8B2C = (int)sub_452C30(v58);
              break;
            case 17:
              dword_5C8B30 = (int)sub_452C30(v58);
              break;
            case 18:
              dword_5C8B34 = (int)sub_452C30(v58);
              break;
            case 19:
              dword_5C8B38 = (int)sub_452C30(v58);
              break;
            case 20:
              dword_5C8B3C = (int)sub_452C30(v58);
              break;
            case 21:
              dword_5C8B40 = (int)sub_452C30(v58);
              break;
            case 22:
              dword_5C8B44 = (int)sub_452C30(v58);
              break;
            case 23:
              dword_5C8B48 = (int)sub_452C30(v58);
              break;
            case 24:
              dword_5C8B4C = (int)sub_452C30(v58);
              break;
            case 25:
              dword_5C8B50 = (int)sub_452C30(v58);
              break;
            default:
              break;
          }
        }
      }
      else
      {
        if ( !v59 )
          v102 = 1;
      }
      ++v59;
      v58 = (char *)(v62 + 1);
    }
    while ( v59 < 2 && !v102 );
    ++v77;
  }
  while ( v77 < 26 );

  pClassTXT_Raw = class17_fn1(pClass17_Events_LOD, "class.txt", 0);
  strtok(pClassTXT_Raw, "\r");

  //v78 = (int)dword_5C86E0;
  v78 = 0;
  do
  {
    v64 = 0;
    result = strtok(0, "\r") + 1;
    v103 = 0;
    do
    {
      v65 = *result;
      v66 = 0;
      if ( *result != 9 )
      {
        do
        {
          if ( !v65 )
            break;
          ++v66;
          v65 = result[v66];
        }
        while ( v65 != 9 );
      }
      v67 = (int)&result[v66];
      if ( !result[v66] )
        v103 = 1;
      *(_BYTE *)v67 = 0;
      if ( v66 )
      {
        if ( v64 )
          array_5C86E0[v78] = sub_452C30(result);
      }
      else
      {
        if ( !v64 )
          v103 = 1;
      }
      ++v64;
      result = (char *)(v67 + 1);
    }
    while ( v64 < 2 && !v103 );
    v78++;
  }
  //while ( v78 <= (signed int)&unk_5C876C );
  while (v78 < 36);
  return result;
}













void CMapStats_ctor(struct CMapStats *_this)
{
 memset(_this->pMapInfos, 0, 77 * sizeof(struct MapInfo));
 _this->uNumMaps = 0;
}

//----- (00453F62) --------------------------------------------------------
extern unsigned char *pMapStatsTXT_Raw;
int CMapStats_Initialize(struct CMapStats *_this)
{
  //void *v1; // esi@1
  signed int v2; // ebx@3
  char *v3; // edi@4
  char *v4; // eax@4
  int v5; // eax@5
  char v6; // cl@5
  size_t v7; // eax@32
  size_t v8; // eax@35
  size_t v9; // eax@42
  size_t v10; // eax@45
  size_t v11; // eax@52
  size_t v12; // eax@55
  int result; // eax@113
  char Str[32]; // [sp+Ch] [bp-34h]@30
  const char *v15; // [sp+2Ch] [bp-14h]@9
  int v16; // [sp+30h] [bp-10h]@4
  int v17; // [sp+34h] [bp-Ch]@4
  unsigned int v18; // [sp+38h] [bp-8h]@30
  char *v19; // [sp+3Ch] [bp-4h]@30
 struct MapInfo *pMapInfo;

 if (pMapStatsTXT_Raw)
   class23_fn1(class23_instance, pMapStatsTXT_Raw);

 pMapStatsTXT_Raw = class17_fn1(pClass17_Events_LOD, "MapStats.txt", 0);
 strtok(pMapStatsTXT_Raw, "\r");
 strtok(0, "\r");
 strtok(0, "\r");

 do
 {
  pMapInfo = &_this->pMapInfos[_this->uNumMaps];
  v4 = strtok(0, "\r");
  v17 = 0;
  v16 = 0;
  v3 = v4;

  do
  {
   v6 = *v3;
   v5 = 0;
   while (v6 != 9 && v6)
   {
    ++v5;
    v6 = v3[v5];
   }

   v15 = &v3[v5];
   if (!v3[v5])
     v16 = 1;
   v3[v5] = 0;
   if (v5)
   {
    switch ( v17 )
    {
     case 1:  pMapInfo->pLocationName = sub_452C30(v3);             break;
     case 2:  pMapInfo->pLocationFilename = sub_452C30(v3);         break;
     case 16: pMapInfo->pEncounterMonster1Texture = sub_452C30(v3); break;
     case 20: pMapInfo->pEncounterMonster2Texture = sub_452C30(v3); break;
     case 24: pMapInfo->pEncounterMonster3Texture = sub_452C30(v3); break;


     case 3:  pMapInfo->uNumResets = atoi(v3); break;
     case 4:  pMapInfo->uVisitedAt = atoi(v3); break;
     case 5:  pMapInfo->dword_000028 = atoi(v3); break;
     case 6:  pMapInfo->uRespawnInterval = atoi(v3); break;
     case 7:  pMapInfo->dword_000020 = atoi(v3); break;
     case 8:  pMapInfo->dword_000024 = atoi(v3); break;

     case 9:  pMapInfo->byte_00002D = atoi(v3); break;
     case 10: pMapInfo->byte_00002E = atoi(v3); break;
     case 11: pMapInfo->byte_00002F = atoi(v3); break;
     case 12: pMapInfo->byte_000030 = atoi(v3); break;
     case 13: pMapInfo->byte_000031 = atoi(v3); break;
     case 14: pMapInfo->byte_000032 = atoi(v3); break;
     case 15: pMapInfo->byte_000033 = atoi(v3); break;
     case 18: pMapInfo->byte_000034 = atoi(v3); break;

     case 19:
       pMapInfo->uEncounterMonster1AtLeast = 1;
       pMapInfo->uEncounterMonster1AtMost = 2;

       sscanf(v3, "%u-%u", &pMapInfo->uEncounterMonster1AtLeast, &pMapInfo->uEncounterMonster1AtMost);
     break;

     case 23:
       pMapInfo->uEncounterMonster2AtLeast = 1;
       pMapInfo->uEncounterMonster2AtMost = 2;

       sscanf(v3, "%u-%u", &pMapInfo->uEncounterMonster2AtLeast, &pMapInfo->uEncounterMonster2AtMost);
     break;

     case 27:
       pMapInfo->uEncounterMonster3AtLeast = 1;
       pMapInfo->uEncounterMonster3AtMost = 2;

       sscanf(v3, "%u-%u", &pMapInfo->uEncounterMonster3AtLeast, &pMapInfo->uEncounterMonster3AtMost);
     break;

     case 22:
       pMapInfo->byte_000037 = atoi(v3);
     break;

     case 26:
       pMapInfo->byte_00003A = atoi(v3);
     break;

     case 28:
       pMapInfo->uRedbookTrackNum = atoi(v3);
     break;

     case 29:
       if (!strcmp(v3, "GENERIC"))
         pMapInfo->uEAXEnv = 0;
       else if (!strcmp(v3, "PADDEDCELL"))
         pMapInfo->uEAXEnv = 1;
       else if (!strcmp(v3, "ROOM"))
         pMapInfo->uEAXEnv = 2;
       else if (!strcmp(v3, "BATHROOM"))
         pMapInfo->uEAXEnv = 3;
       else if (!strcmp(v3, "LIVINGROOM"))
         pMapInfo->uEAXEnv = 4;
       else if (!strcmp(v3, "STONEROOM"))
         pMapInfo->uEAXEnv = 5;
       else if (!strcmp(v3, "AUDITORIUM"))
         pMapInfo->uEAXEnv = 6;
       else if (!strcmp(v3, "CONCERTHALL"))
         pMapInfo->uEAXEnv = 7;
       else if (!strcmp(v3, "CAVE"))
         pMapInfo->uEAXEnv = 8;
       else if (!strcmp(v3, "ARENA"))
         pMapInfo->uEAXEnv = 9;
       else if (!strcmp(v3, "HANGAR"))
         pMapInfo->uEAXEnv = 10;
       else if (!strcmp(v3, "CARPETEDHALLWAY"))
         pMapInfo->uEAXEnv = 11;
       else if (!strcmp(v3, "HALLWAY"))
         pMapInfo->uEAXEnv = 12;
       else if (!strcmp(v3, "STONECORRIDOR"))
         pMapInfo->uEAXEnv = 13;
       else if (!strcmp(v3, "ALLEY"))
         pMapInfo->uEAXEnv = 14;
       else if (!strcmp(v3, "FOREST"))
         pMapInfo->uEAXEnv = 15;
       else if (!strcmp(v3, "CITY"))
         pMapInfo->uEAXEnv = 16;
       else if (!strcmp(v3, "MOUNTAINS"))
         pMapInfo->uEAXEnv = 17;
       else if (!strcmp(v3, "QUARRY"))
         pMapInfo->uEAXEnv = 18;
       else if (!strcmp(v3, "PLAIN"))
         pMapInfo->uEAXEnv = 19;
       else if (!strcmp(v3, "PARKINGLOT"))
         pMapInfo->uEAXEnv = 20;
       else if (!strcmp(v3, "SEWERPIPE"))
         pMapInfo->uEAXEnv = 21;
       else if (!strcmp(v3, "UNDERWATER"))
         pMapInfo->uEAXEnv = 22;
       else if (!strcmp(v3, "DRUGGED"))
         pMapInfo->uEAXEnv = 23;
       else if (!strcmp(v3, "DIZZY"))
         pMapInfo->uEAXEnv = 24;
       else if (!strcmp(v3, "PSYCHOTIC"))
         pMapInfo->uEAXEnv = 26;
       else pMapInfo->uEAXEnv = 25;
     break;

     default: break;
    }
   }
   else v16 = 1;


      ++v17;
      v3 = v15 + 1;
      result = v17 - 1;
    }
    while ( v17 - 1 <= 29 && !v16 );
    ++_this->uNumMaps;
  }
  while (_this->uNumMaps < 77);
  return result;
}
















void CMonsterStats_ctor(struct CMonsterStats *_this)
{
}

//----- (0045501E) --------------------------------------------------------
extern unsigned char *pMonstersTXT_Raw;
extern int dword_5FF14C;
unsigned int __fastcall sub_4548E2(struct StringSplitter *pStrings, int *a2);
char __fastcall sub_454D7D(const char *Str, int a2, int a3, int a4);
int sub_454CB4(const char *pString);
int CMonsterStats_Initialize(struct CMonsterStats *_this)
{
  void *v1; // ebx@1
  int v2; // ebx@4
  int v3; // eax@5
  char v4; // cl@5
  size_t v5; // eax@19
  signed int v6; // edi@19
  int v7; // ecx@23
  int v8; // eax@23
  int v9; // esi@23
  size_t v10; // eax@29
  signed int v11; // edi@29
  int v12; // ecx@33
  int v13; // eax@33
  int v14; // esi@33
  signed int v15; // edi@36
  int v16; // esi@36
  int v17; // eax@37
  int v19; // edi@50
  int v20; // eax@51
  int v21; // edi@59
  char *v22; // edi@63
  char v23; // cl@63
  int v24; // esi@114
  int v25; // eax@118
  size_t v26; // eax@136
  int v27; // edi@137
  int v28; // esi@137
  int v29; // eax@138
  int v30; // eax@142
  int v31; // eax@143
  int v32; // eax@144
  int v33; // eax@151
  int v34; // eax@152
  int v35; // eax@153
  int v36; // eax@162
  int v37; // eax@163
  int v38; // eax@164
  int v39; // eax@171
  int v40; // eax@172
  int v41; // edi@180
  int v42; // esi@180
  size_t v43; // eax@180
  int v44; // edi@184
  int v45; // edx@232
  int v46; // ecx@232
  int v47; // eax@232
  int v48; // eax@236
  int v49; // eax@240
  int v51; // eax@241
  char *v52; // edi@242
  int v53; // esi@242
  int v54; // edi@242
  char v55; // al@242
  int v56; // eax@249
  void *v57; // esi@249
  int v58; // eax@250
  char *v59; // edi@251
  int v60; // esi@251
  int v61; // edi@251
  char v62; // al@251
  char v63; // al@258
  char v64; // al@262
  char v65; // al@266
  char v66; // al@270
  char v67; // al@274
  char v68; // al@278
  char v69; // al@282
  char v70; // al@286
  char v71; // al@290
  char v72; // al@294
  signed int v73; // edi@298
  int v74; // esi@300
  int v75; // esi@302
  char *v76; // edi@306
  int v77; // eax@316
  int v78; // esi@323
  char *v79; // ecx@323
  int result; // eax@328
  char v81; // [sp-14h] [bp-46Ch]@317
  int v82; // [sp-10h] [bp-468h]@317
  int v83; // [sp-Ch] [bp-464h]@317
  int v84; // [sp-8h] [bp-460h]@306
  int v85; // [sp-4h] [bp-45Ch]@23
  int v86; // [sp+0h] [bp-458h]@37
  char v87; // [sp+10h] [bp-448h]@297
  char v88; // [sp+8Ch] [bp-3CCh]@249
  char v89; // [sp+108h] [bp-350h]@240
  char v90; // [sp+184h] [bp-2D4h]@317
  int v91; // [sp+1FCh] [bp-25Ch]@249
  int v92; // [sp+200h] [bp-258h]@251
  int v93[29]; // [sp+204h] [bp-254h]@251
 struct StringSplitter splitter;//int v94; // [sp+278h] [bp-1E0h]@240
  char *Str1; // [sp+27Ch] [bp-1DCh]@242
  _DWORD Str2[28]; // [sp+280h] [bp-1D8h]@242
  char v97; // [sp+2F3h] [bp-165h]@240
  char Str[256]; // [sp+2F4h] [bp-164h]@240
  char v99; // [sp+333h] [bp-125h]@249
  char v100; // [sp+334h] [bp-124h]@249
  char v101; // [sp+373h] [bp-E5h]@297
  char v102; // [sp+374h] [bp-E4h]@297
  int v103; // [sp+3B4h] [bp-A4h]@297
  char *v104; // [sp+3B8h] [bp-A0h]@299
  char *v105; // [sp+3BCh] [bp-9Ch]@300
  char *Source; // [sp+3C0h] [bp-98h]@303
  int v107; // [sp+430h] [bp-28h]@317
  int v108; // [sp+434h] [bp-24h]@9
  int v109; // [sp+438h] [bp-20h]@4
  __int64 v110; // [sp+43Ch] [bp-1Ch]@4
  int v111; // [sp+444h] [bp-14h]@36
  int v112; // [sp+448h] [bp-10h]@36
  size_t v113; // [sp+44Ch] [bp-Ch]@19
  int v114; // [sp+450h] [bp-8h]@1
  int v115;
 struct MonsterInfo *pMonsterInfo;

  v1 = _this;
  v114 = (int)_this;

 if (pMonstersTXT_Raw)
   class23_fn1(class23_instance, pMonstersTXT_Raw);

 pMonstersTXT_Raw = class17_fn1(pClass17_Events_LOD, "monsters.txt", 0);
 strtok(pMonstersTXT_Raw, "\r");
 strtok(0, "\r");
 strtok(0, "\r");
 strtok(0, "\r");

 _this->uNumMonsters = 0;
 pMonsterInfo = _this->pMonsterInfos;
 do
 {
    v2 = (int)(strtok(0, "\r") + 1);
    HIDWORD(v110) = 0;
    v109 = 0;
    do
    {
      v4 = *(_BYTE *)v2;
      v3 = 0;
      while ( v4 != 9 && v4 )
      {
        ++v3;
        v4 = *(_BYTE *)(v3 + v2);
      }
      v108 = v3 + v2;
      if ( !*(_BYTE *)(v3 + v2) )
        v109 = 1;
      *(_BYTE *)(v3 + v2) = 0;
      if ( v3 )
      {
        switch ( HIDWORD(v110) )
        {
          case 0:
            pMonsterInfo->uID = _this->uNumMonsters;
          break;

          case 1:
            pMonsterInfo->pName = sub_452C30(v2);
          break;

          case 2:
            pMonsterInfo->pTexture = sub_452C30(v2);
          break;

          case 3:
            pMonsterInfo->uLevel = atoi(v2);
          break;

          case 4:
            if (*(char *)v2 == ' ' || *(char *)v2 == '"')
              pMonsterInfo->uHP = 10;
            else pMonsterInfo->uHP = atoi(v2);
          break;

          case 5:
            pMonsterInfo->uAC = atoi(v2);
          break;


          case 6:
            if (*(char *)v2 == ' ' || *(char *)v2 == '"')
              pMonsterInfo->uExp = 10;
            else pMonsterInfo->uExp = atoi(v2);
          break;


          case 7:
            v15 = 0;
            v111 = 0;
            v112 = 0;
            v16 = 0;
            v113 = strlen(v2);

            do
            {
              v86 = *(_BYTE *)(v16 + v2);
              v17 = tolower(v86);
              switch ( v17 )
              {
                case 37:
                  v15 = 1;
                  break;
                case 100:
                  v112 = 1;
                  break;
                case 108:
                  v111 = (char *)1;
                  break;
              }
              ++v16;
            }
            while ( v16 < v113 );

            if ( v15 )
              pMonsterInfo->byte_000009 = atoi(v2);
            else
              pMonsterInfo->byte_000009 = 100;

            if (v112)
            {
              v19 = 0;
              v112 = 0;
              do
              {
                v86 = *(_BYTE *)(v19 + v2);
                v20 = tolower(v86);
                if ( v20 == 37 )
                {
                  v86 = v19 + v2 + 1;
                  pMonsterInfo->byte_00000A = atoi(v86);
                  v112 = 1;
                }
                else
                {
                  if ( v20 == 100 )
                  {
                    if ( !v112 )
                      pMonsterInfo->byte_00000A = atoi(v2);
                    v86 = v19 + v2 + 1;
                    v19 = v113;
                    pMonsterInfo->byte_00000B = atoi(v86);
                  }
                }
                ++v19;
              }
              while ( v19 < v113 );
            }

            if ( v111 )
            {
              v21 = 0;
              while ( 1 )
              {
                v86 = *(_BYTE *)(v21 + v2);
                if ( tolower(v86) == 108 )
                  break;
                ++v21;
                if ( v21 >= v113 )
                  break;
              }
              v23 = *(_BYTE *)(v21 + v2 + 1);
              v22 = (const char *)(v21 + v2 + 2);
              pMonsterInfo->byte_00000C = v23 - 48;
              if ( *v22 )
              {
               if (!_strcmpi(v22, "WEAPON"))
                 pMonsterInfo->byte_00000C = 20;
               else if (!_strcmpi(v22, "ARMOR"))
                 pMonsterInfo->byte_00000C = 21;
               else if (!_strcmpi(v22, "MISC"))
                 pMonsterInfo->byte_00000C = 22;
               else if (!_strcmpi(v22, "SWORD"))
                 pMonsterInfo->byte_00000C = 23;
               else if (!_strcmpi(v22, "DAGGER"))
                 pMonsterInfo->byte_00000C = 24;
               else if (!_strcmpi(v22, "AXE"))
                 pMonsterInfo->byte_00000C = 25;
               else if (!_strcmpi(v22, "SPEAR"))
                 pMonsterInfo->byte_00000C = 26;
               else if (!_strcmpi(v22, "BOW"))
                 pMonsterInfo->byte_00000C = 27;
               else if (!_strcmpi(v22, "MACE"))
                 pMonsterInfo->byte_00000C = 28;
               else if (!_strcmpi(v22, "CLUB"))
                 pMonsterInfo->byte_00000C = 29;
               else if (!_strcmpi(v22, "STAFF"))
                 pMonsterInfo->byte_00000C = 30;
               else if (!_strcmpi(v22, "LEATHER"))
                 pMonsterInfo->byte_00000C = 31;
               else if (!_strcmpi(v22, "CHAIN"))
                 pMonsterInfo->byte_00000C = 32;
               else if (_strcmpi(v22, "PLATE"))
                 pMonsterInfo->byte_00000C = 33;
               else if (!_strcmpi(v22, "SHIELD"))
                 pMonsterInfo->byte_00000C = 34;
               else if (!_strcmpi(v22, "HELM"))
                 pMonsterInfo->byte_00000C = 35;
               else if (!_strcmpi(v22, "BELT"))
                 pMonsterInfo->byte_00000C = 36;
               else if (!_strcmpi(v22, "CAPE"))
                 pMonsterInfo->byte_00000C = 37;
               else if (!_strcmpi(v22, "GAUNTLETS"))
                 pMonsterInfo->byte_00000C = 38;
               else if (!_strcmpi(v22, "BOOTS"))
                 pMonsterInfo->byte_00000C = 39;
               else if (!_strcmpi(v22, "RING"))
                 pMonsterInfo->byte_00000C = 40;
               else if (!_strcmpi(v22, "AMULET"))
                 pMonsterInfo->byte_00000C = 41;
               else if (!_strcmpi(v22, "WAND"))
                 pMonsterInfo->byte_00000C = 42;
               else if (!_strcmpi(v22, "SCROLL"))
                 pMonsterInfo->byte_00000C = 43;
               else if (!_strcmpi(v22, "GEM"))
                 pMonsterInfo->byte_00000C = 46;
              }
            }
          break;


          case 8:
            pMonsterInfo->bQuestMonster = atoi(v2);
          break;

          case 9:
            pMonsterInfo->uCanFly = *(char *)v2 == 'Y';
          break;

          case 10:
            v86 = *(_BYTE *)v2;
            v113 = 4;
            if ( tolower(v86) == 115 )
            {
              v86 = *(_BYTE *)(v2 + 1);
              v25 = tolower(v86) != 104 ? 5 : 0;
            }
            else
            {
              v86 = *(_BYTE *)v2;
              if ( tolower(v86) == 109 )
              {
                v113 = 1;
              }
              else
              {
                v86 = *(_BYTE *)v2;
                if ( tolower(v86) == 108 )
                {
                  v113 = 2;
                }
                else
                {
                  v86 = *(_BYTE *)v2;
                  if ( tolower(v86) == 103 )
                    v113 = 3;
                }
              }
              LOBYTE(v25) = v113;
            }
            pMonsterInfo->uMovement = LOBYTE(v25);
          break;

          case 11:
            v86 = *(_BYTE *)v2;
            v113 = 3;
            if ( tolower(v86) == 115 )
            {
              v113 = 0;
            }
            else
            {
              v86 = *(_BYTE *)v2;
              if ( tolower(v86) == 119 )
              {
                v113 = 1;
              }
              else
              {
                v86 = *(_BYTE *)v2;
                if ( tolower(v86) == 110 )
                  v113 = 2;
              }
            }
            pMonsterInfo->uAIType = v113;
          break;

          case 12:
            pMonsterInfo->byte_000011 = atoi(v2);
          break;

          case 13:
            pMonsterInfo->uSpeed = atoi(v2);
          break;

          case 15:
            v26 = strlen((const char *)v2);
            v112 = 0;
            v113 = v26;
            if ( (signed int)v26 > 0 )
            {
              v27 = _this->uNumMonsters;
              v28 = v114;
              do
              {
                v86 = *(_BYTE *)(v112 + v2);
                v29 = tolower(v86);
                if ( v29 > 107 )
                {
                  if ( v29 > 115 )
                  {
                    v39 = v29 - 116;
                    if ( v39 )
                    {
                      v40 = v39 - 3;
                      if ( v40 )
                      {
                        if ( v40 == 1 )
                          pMonsterInfo->byte_000055 |= 2u;
                      }
                      else
                      {
                        pMonsterInfo->byte_000055 |= 0x20u;
                      }
                    }
                    else
                    {
                      pMonsterInfo->byte_000054 |= 0x80u;
                    }
                  }
                  else
                  {
                    if ( v29 == 115 )
                    {
                      pMonsterInfo->byte_000054 |= 0x20u;
                    }
                    else
                    {
                      v36 = v29 - 109;
                      if ( v36 )
                      {
                        v37 = v36 - 2;
                        if ( v37 )
                        {
                          v38 = v37 - 1;
                          if ( v38 )
                          {
                            if ( v38 == 2 )
                              pMonsterInfo->byte_000054 |= 0x40u;
                          }
                          else
                          {
                            pMonsterInfo->byte_000054 |= 2u;
                          }
                        }
                        else
                        {
                          pMonsterInfo->byte_000055 |= 4u;
                        }
                      }
                      else
                      {
                        pMonsterInfo->byte_000055 |= 1u;
                      }
                    }
                  }
                }
                else
                {
                  if ( v29 == 107 )
                  {
                    pMonsterInfo->byte_000054 |= 1u;
                  }
                  else
                  {
                    if ( v29 > 99 )
                    {
                      v33 = v29 - 100;
                      if ( v33 )
                      {
                        v34 = v33 - 1;
                        if ( v34 )
                        {
                          v35 = v34 - 2;
                          if ( v35 )
                          {
                            if ( v35 == 1 )
                              pMonsterInfo->byte_000055 |= 8u;
                          }
                          else
                          {
                            pMonsterInfo->byte_000055 |= 0x40u;
                          }
                        }
                        else
                        {
                          pMonsterInfo->byte_000055 |= 0x10u;
                        }
                      }
                      else
                      {
                        pMonsterInfo->byte_000054 |= 8u;
                      }
                    }
                    else
                    {
                      if ( v29 == 99 )
                      {
                        pMonsterInfo->byte_000054 |= 0x10u;
                      }
                      else
                      {
                        v30 = v29 - 50;
                        if ( v30 )
                        {
                          v31 = v30 - 1;
                          if ( v31 )
                          {
                            v32 = v31 - 1;
                            if ( v32 )
                            {
                              if ( v32 == 45 )
                                pMonsterInfo->byte_000054 |= 4u;
                            }
                            else
                            {
                              pMonsterInfo->byte_000032 = 4;
                            }
                          }
                          else
                          {
                            pMonsterInfo->byte_000032 = 3;
                          }
                        }
                        else
                        {
                          pMonsterInfo->byte_000032 = 2;
                        }
                      }
                    }
                  }
                }
                ++v112;
              }
              while ( v112 < v113 );
            }
          break;



          case 14:
            pMonsterInfo->dword_000050 = atoi(v2);
          break;

          case 16:
            v43 = strlen(v2);
            v41 = 0;
            v42 = pMonsterInfo;
            v112 = v43;
            pMonsterInfo->byte_000014 = 1;
            if (v43 <= 0 )
              goto LABEL_185;
            
            while (true)
            {
             v86 = *(_BYTE *)(v41 + v2);
             if ( tolower(v86) == 120 )
               break;
             ++v41;
             if ( v41 >= v112 )
               goto LABEL_185;
            }

            v44 = v2 + v41;
            *(_BYTE *)v44 = 0;
            *(_BYTE *)(v42 + 20) = atoi((const char *)(v44 + 1));
            *(_BYTE *)v44 = 100;
LABEL_185:
            _strlwr(v2);
            if (strstr(v2, "curse"))
              pMonsterInfo->uSpecialAttack = 1;
            else if (strstr(v2, "weak"))
              pMonsterInfo->uSpecialAttack = 2;
            else if (strstr(v2, "asleep"))
              pMonsterInfo->uSpecialAttack = 3;
            else if (strstr(v2, "afraid"))
              pMonsterInfo->uSpecialAttack = 23;
            else if (strstr(v2, "drunk"))
              pMonsterInfo->uSpecialAttack = 4;
            else if (strstr(v2, "insane"))
              pMonsterInfo->uSpecialAttack = 5;
            else if (strstr(v2, "poison1"))
              pMonsterInfo->uSpecialAttack = 6;
            else if (strstr(v2, "poison2"))
              pMonsterInfo->uSpecialAttack = 7;
            else if (strstr(v2, "poison3"))
              pMonsterInfo->uSpecialAttack = 8;
            else if (strstr(v2, "disease1"))
              pMonsterInfo->uSpecialAttack = 9;
            else if (strstr(v2, "disease2"))
              pMonsterInfo->uSpecialAttack = 10;
            else if (strstr(v2, "disease3"))
              pMonsterInfo->uSpecialAttack = 11;
            else if (strstr(v2, "paralyze"))
              pMonsterInfo->uSpecialAttack = 12;
            else if (strstr(v2, "uncon"))
              pMonsterInfo->uSpecialAttack = 13;
            else if (strstr(v2, "dead"))
              pMonsterInfo->uSpecialAttack = 14;
            else if (strstr(v2, "stone"))
              pMonsterInfo->uSpecialAttack = 15;
            else if (strstr(v2, "errad"))
              pMonsterInfo->uSpecialAttack = 16;
            else if (strstr(v2, "brkitem"))
              pMonsterInfo->uSpecialAttack = 17;
            else if (strstr(v2, "brkarmor"))
              pMonsterInfo->uSpecialAttack = 18;
            else if (strstr(v2, "brkweapon"))
              pMonsterInfo->uSpecialAttack = 19;
            else if (strstr(v2, "steal"))
              pMonsterInfo->uSpecialAttack = 20;
            else if (strstr(v2, "age"))
              pMonsterInfo->uSpecialAttack = 21;
            else if (strstr(v2, "drainsp"))
              pMonsterInfo->uSpecialAttack = 22;
            else pMonsterInfo->uSpecialAttack = 0;
           break;

          case 17:
            pMonsterInfo->uAttackType = sub_454CB4(v2);
          break;

          case 18:
            sub_454D7D(v2, &pMonsterInfo->byte_000016, &pMonsterInfo->byte_000017, &pMonsterInfo->byte_000018);
          break;

          case 19:
            pMonsterInfo->uMissleType = sub_454E3A(v2);
          break;

          case 20:
            pMonsterInfo->byte_00001A = atoi(v2);
          break;

          case 21:
            pMonsterInfo->uAttack2Type = sub_454CB4(v2);
          break;

          case 22:
            sub_454D7D(v2, &pMonsterInfo->byte_00001C, &pMonsterInfo->byte_00001D, &pMonsterInfo->byte_00001E);
          break;

          case 23:
            pMonsterInfo->uAttack2MissleType = sub_454E3A(v2);
          break;

          case 24:
            pMonsterInfo->uSpell1UseChance = atoi(v2);
          break;

          case 0x19:
            strcpy(Str, v2);
            Str[0] = 32;
            Str[strlen(Str) - 1] = 32;
            sub_4BE3BF(Str, &splitter);
            if (splitter.uNumSubstrings >= 3)
            {
             v111 = 1;
             pMonsterInfo->uSpell1Type = sub_4548E2(&splitter, &v111);
             pMonsterInfo->uSpell1Power = atoi(splitter.pSubstrings[2 + v111]) & 0x3F;
             if (!_strcmpi(splitter.pSubstrings[1 + v111], "E"))
               pMonsterInfo->uSpell1Power |= 0x40;
             else if (!_strcmpi(splitter.pSubstrings[1 + v111], "M"))
               pMonsterInfo->uSpell1Power |= 0x80;
             else if (!_strcmpi(splitter.pSubstrings[1 + v111], "G"))
               pMonsterInfo->uSpell1Power |= 0x100;
            }
            else
            {
             pMonsterInfo->uSpell1Type = 0;
             pMonsterInfo->uSpell1Power = 0;
            }
          break;


          case 0x1A:
            pMonsterInfo->uSpell2UseChance = atoi(v2);
          break;

          case 0x1B:
            strcpy(Str, v2);
            Str[0] = 32;
            Str[strlen(Str) - 1] = 32;
            sub_4BE3BF(Str, &splitter);
            if (splitter.uNumSubstrings >= 3)
            {
             v111 = 1;
             pMonsterInfo->uSpell2Type = sub_4548E2(&splitter, &v111);
             pMonsterInfo->uSpell2Power = atoi(splitter.pSubstrings[2 + v111]) & 0x3F;
             if (!_strcmpi(splitter.pSubstrings[1 + v111], "E"))
               pMonsterInfo->uSpell2Power |= 0x40;
             else if (!_strcmpi(splitter.pSubstrings[1 + v111], "M"))
               pMonsterInfo->uSpell2Power |= 0x80;
             else if (!_strcmpi(splitter.pSubstrings[1 + v111], "G"))
               pMonsterInfo->uSpell2Power |= 0x100;
            }
            else
            {
             pMonsterInfo->uSpell2Type = 0;
             pMonsterInfo->uSpell2Power = 0;
            }
          break;

          case 0x1C:
            if (tolower(*(_BYTE *)v2) == 'i')
              v63 = 200;
            else
              v63 = atoi(v2);
            pMonsterInfo->uResistanceFire = v63;
          break;

          case 0x1D:
            if (tolower(*(_BYTE *)v2) == 'i')
              v63 = 200;
            else
              v63 = atoi(v2);
            pMonsterInfo->uResistanceAir = v63;
          break;

          case 0x1E:
            if (tolower(*(_BYTE *)v2) == 'i')
              v63 = 200;
            else
              v63 = atoi(v2);
            pMonsterInfo->uResistanceWater = v63;
          break;

          case 0x1F:
            if (tolower(*(_BYTE *)v2) == 'i')
              v63 = 200;
            else
              v63 = atoi(v2);
            pMonsterInfo->uResistanceEarth = v63;
          break;

          case 0x20:
            if (tolower(*(_BYTE *)v2) == 'i')
              v63 = 200;
            else
              v63 = atoi(v2);
            pMonsterInfo->uResistanceMind = v63;
          break;

          case 0x21:
            if (tolower(*(_BYTE *)v2) == 'i')
              v63 = 200;
            else
              v63 = atoi(v2);
            pMonsterInfo->uResistanceSpirit = v63;
          break;

          case 0x22:
            if (tolower(*(_BYTE *)v2) == 'i')
              v63 = 200;
            else
              v63 = atoi(v2);
            pMonsterInfo->uResistanceBody = v63;
          break;

          case 0x23:
            if (tolower(*(_BYTE *)v2) == 'i')
              v63 = 200;
            else
              v63 = atoi(v2);
            pMonsterInfo->uResistanceLight = v63;
          break;

          case 0x24:
            if (tolower(*(_BYTE *)v2) == 'i')
              v63 = 200;
            else
              v63 = atoi(v2);
            pMonsterInfo->uResistanceDark = v63;
          break;

          case 0x25:
            if (tolower(*(_BYTE *)v2) == 'i')
              v63 = 200;
            else
              v63 = atoi(v2);
            pMonsterInfo->uResistancePhysical = v63;
          break;

          case 0x26:
          break;
            strcpy(Str, v2);
            Str[0] = ' ';
            Str[strlen(Str) - 1] = ' ';


            sub_4BE3BF(Str, &splitter);
            if (splitter.uNumSubstrings)
            {
              v73 = splitter.uNumSubstrings;
              if ( splitter.uNumSubstrings < 10 )
              {
                if ( _strcmpi(v104, "shot") )
                {
                  if ( _strcmpi(v104, "summon") )
                  {
                    if ( !_strcmpi(v104, "explode") )
                    {
                      v78 = 88 * v115 + v114;
                      v79 = v105;
                      v86 = v78 + 49;
                      v85 = v78 + 48;
                      pMonsterInfo->byte_00002E = 3;
                      sub_454D7D(splitter.pSubstrings[2], &pMonsterInfo->byte_00002E, pMonsterInfo->byte_000030, pMonsterInfo->byte_000031);
                      pMonsterInfo->word_00003C = sub_454CB4((int *)v2);
                    }
                  }
                  else
                  {
                    v75 = 88 * v115 + v114;
                    pMonsterInfo->byte_00002E = 2;
                    if ( v73 > 1 )
                    {
                      ExistingFileName[0] = 0;
                      strcpy(ExistingFileName, Source);
                      if ( v73 > 2 )
                      {
                        v112 = 3;
                        if ( v73 > 3 )
                        {
                          do
                          {
                            strcat(ExistingFileName, L" ");
                            v76 = (&v104)[4 * v112];
                            v84 = (int)(&v104)[4 * v112];
                            strcat(ExistingFileName, (const char *)v84);
                            if ( v112 == v103 - 1 )
                            {
                              v86 = (unsigned __int8)*v76;
                              if ( tolower(v86) == 97 )
                              {
                                *(_BYTE *)(v75 + 47) = 1;
                              }
                              else
                              {
                                v86 = (unsigned __int8)*v76;
                                if ( tolower(v86) == 98 )
                                {
                                  *(_BYTE *)(v75 + 47) = 2;
                                }
                                else
                                {
                                  v86 = (unsigned __int8)*v76;
                                  if ( tolower(v86) == 99 )
                                    *(_BYTE *)(v75 + 47) = 3;
                                  else
                                    *(_BYTE *)(v75 + 47) = 0;
                                }
                              }
                            }
                            ++v112;
                          }
                          while ( v112 < v103 );
                        }
                      }
                      else
                      {
                        *(_BYTE *)(v75 + 47) = 0;
                      }
                      if ( monster_list[0] )
                      {
                        LOWORD(v77) = sub_44FA08(monster_list, &ExistingFileName);
                        ++v77;
                        *(_WORD *)(v75 + 60) = v77;
                        if ( (_WORD)v77 == -1 )
                        {
                          v86 = (int)&v90;
                          sprintfex(&v90, "Can't create random monster: '%s' See MapStats!", &v90);
                          v86 = 2239;
                          v85 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Itemdata.cpp";
                          v111 = &v81;
                          sub_40E2C8(&v81, &v90, (int)((char *)&v110 + 3));
                          sub_466D09(&v107, *(int *)&v81, v82, v83, v84, (const char *)v85, v86);
                          v107 = 5080748;
                        }
                      }
                      *(_BYTE *)(v75 + 48) = 0;
                      if ( !_strcmpi(v105, "ground") )
                        *(_BYTE *)(v75 + 48) = 1;
                      if ( *(_WORD *)(v75 + 60) == -1 )
                        *(_BYTE *)(v75 + 46) = 0;
                    }
                  }
                }
                else
                {
                  v74 = 88 * v115 + v114;
                  v86 = (int)(v105 + 1);
                  *(_BYTE *)(v74 + 46) = 1;
                  *(_BYTE *)(v74 + 49) = atoi((const char *)v86);
                }
              }
            }
          break;
          default:
          break;
        }
      }
      else
      {
        v109 = 1;
      }
      v110 += 4294967296i64;
      v2 = v108 + 1;
    }
    while ( /*HIDWORD(v110) - 1 <= *(_DWORD *)(v114 + 23444) &&*/ !v109 );

    pMonsterInfo++;
  }
  while ( ++_this->uNumMonsters < 265);//278 );
  return _this->uNumMonsters;
}

//----- (00454CB4) --------------------------------------------------------
int sub_454CB4(const char *pString)
{
  int result; // eax@4
  int v3; // eax@15
  int v4; // eax@18

  if ( !pString )
    return 4;
  if ( tolower(*pString) == 102 )
    return 0;
  if ( tolower(*pString) == 97 )
    return 1;
  if ( tolower(*pString) == 119 )
    return 2;
  if ( tolower(*pString) == 101 )
  {
    tolower(pString[1]);
    return 3;
  }
  if ( tolower(*pString) == 115 )
    return 6;
  if ( tolower(*pString) == 109 )
  {
    v3 = -(tolower(pString[1]) != 105);
    LOBYTE(v3) = v3 & 0xFE;
    result = v3 + 7;
  }
  else
  {
    if ( tolower(*pString) == 108 )
      return 9;
    v4 = -(tolower(*pString) != 100);
    LOBYTE(v4) = v4 & 0xFA;
    result = v4 + 10;
  }
  return result;
}

//----- (00454D7D) --------------------------------------------------------
char __fastcall sub_454D7D(const char *Str, unsigned char *a2, unsigned char *a3, unsigned char *a4)
{
  signed int v4; // ebx@1
  const char *v5; // edi@1
  int v6; // esi@1
  int *v7; // esi@2
  int v8; // eax@3
  size_t v10; // [sp+Ch] [bp-Ch]@1
  int v11; // [sp+10h] [bp-8h]@1
  signed int v12; // [sp+14h] [bp-4h]@1

  v6 = a2;
  v5 = Str;
  *(_BYTE *)a2 = 0;
  *(_BYTE *)a3 = 1;
  v11 = a2;
  *(_BYTE *)a4 = 0;
  v4 = 0;
  v10 = strlen(Str);
  v12 = 0;
  if ( (signed int)v10 <= 0 )
    goto LABEL_9;
  do
  {
    v7 = (int *)&v5[v4];
    if ( tolower((unsigned __int8)v5[v4]) == 100 )
    {
      *(_BYTE *)v7 = 0;
      *(_BYTE *)v11 = atoi(v5);
      LOBYTE(v8) = atoi(&v5[v4 + 1]);
      v12 = 1;
      *(_BYTE *)a3 = v8;
      *(_BYTE *)v7 = 100;
    }
    else
    {
      v8 = tolower(*(_BYTE *)v7);
      if ( v8 == 43 )
      {
        LOBYTE(v8) = atoi(&v5[v4 + 1]);
        *(_BYTE *)a4 = v8;
      }
    }
    ++v4;
  }
  while ( v4 < (signed int)v10 );
  if ( !v12 )
  {
    v6 = v11;
LABEL_9:
    LOBYTE(v8) = *v5;
    if ( (unsigned __int8)*v5 >= 0x30u )
    {
      if ( (_BYTE)v8 <= 0x39u )
      {
        *(_BYTE *)v6 = atoi(v5);
        LOBYTE(v8) = a3;
        *(_BYTE *)a3 = 1;
      }
    }
  }
  return v8;
}

//----- (00454E3A) --------------------------------------------------------
signed int __thiscall sub_454E3A(const char *Str1)
{
  int v1; // edi@1
  const char *v2; // esi@1
  signed int v4; // [sp-4h] [bp-Ch]@4

  v2 = Str1;
  v1 = 0;
  if ( _strcmpi(Str1, "ARROW") )
  {
    if ( _strcmpi(v2, "ARROWF") )
    {
      if ( _strcmpi(v2, "FIRE") )
      {
        if ( _strcmpi(v2, "AIR") )
        {
          if ( _strcmpi(v2, "WATER") )
          {
            if ( _strcmpi(v2, "EARTH") )
            {
              if ( _strcmpi(v2, "SPIRIT") )
              {
                if ( _strcmpi(v2, "MIND") )
                {
                  if ( _strcmpi(v2, "BODY") )
                  {
                    if ( _strcmpi(v2, "LIGHT") )
                    {
                      if ( _strcmpi(v2, "DARK") )
                      {
                        if ( _strcmpi(v2, "ENER") )
                          return v1;
                        v4 = 13;
                      }
                      else
                      {
                        v4 = 11;
                      }
                    }
                    else
                    {
                      v4 = 10;
                    }
                  }
                  else
                  {
                    v4 = 9;
                  }
                }
                else
                {
                  v4 = 8;
                }
              }
              else
              {
                v4 = 7;
              }
            }
            else
            {
              v4 = 6;
            }
          }
          else
          {
            v4 = 5;
          }
        }
        else
        {
          v4 = 4;
        }
      }
      else
      {
        v4 = 3;
      }
    }
    else
    {
      v4 = 2;
    }
    return v4;
  }
  return 1;
}


//----- (004548E2) --------------------------------------------------------
unsigned int __fastcall sub_4548E2(struct StringSplitter *pStrings, int *a2)
{
  char v5; // [sp-18h] [bp-28h]@75
  int v6; // [sp-14h] [bp-24h]@75
  int v7; // [sp-10h] [bp-20h]@75
  int v8; // [sp-Ch] [bp-1Ch]@75
  char *v11; // [sp+8h] [bp-8h]@75
  int v12; // [sp+Fh] [bp-1h]@75


 if (!pStrings->pSubstrings[0])
   return 0;

 if (!_strcmpi(pStrings->pSubstrings[0], "Dispel"))
 {
  return 80;
 }
 else if (!_strcmpi(pStrings->pSubstrings[0], "Day"))
 {
  *a2 += 1;
  return 85;
 }
 else if (!_strcmpi(pStrings->pSubstrings[0], "Hour"))
 {
  *a2 += 1;
  return 86;
 }
 else if (!_strcmpi(pStrings->pSubstrings[0], "Shield"))
 {
  *a2 += 1;
  return 17;
 }
 else if (!_strcmpi(pStrings->pSubstrings[0], "Spirit"))
   return 52;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Power"))
   return 77;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Meteor"))
   return 9;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Lightning"))
   return 18;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Implosion"))
   return 20;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Stone"))
   return 38;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Haste"))
   return 5;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Heroism"))
   return 51;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Pain"))
   return 95;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Sparks"))
   return 15;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Light"))
   return 78;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Toxic"))
   return 90;
 else if (!_strcmpi(pStrings->pSubstrings[0], "ShrapMetal"))
   return 93;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Paralyze"))
   return 81;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Fireball"))
   return 6;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Incinerate"))
   return 11;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Fire"))
   return 2;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Rock"))
   return 41;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Mass"))
   return 44;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Ice"))
   return 26;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Acid"))
   return 29;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Bless"))
   return 46;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Dragon"))
   return 97;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Reanimate"))
   return 89;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Summon"))
   return 82;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Fate"))
   return 47;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Harm"))
   return 70;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Mind") )
   return 57;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Blades"))
   return 39;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Psychic") )
   return 65;
 else if (!_strcmpi(pStrings->pSubstrings[0], "Hammerhands"))
   return 73;
 else
 {
  sprintfex(ExistingFileName, "Unknown monster spell %s", pStrings->pSubstrings[0]);
  v11 = &v5;
  sub_40E2C8(&v5, ExistingFileName, (int)&v12);
  sub_466D09(&v11, *(int *)&v5, v6, v7, v8, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Itemdata.cpp", 1562);
  *a2 += 1;
  return 0;
 }
}





//----- (00454F4E) --------------------------------------------------------
extern unsigned char *pMonsterPlacementTXT_Raw;
char *CMonsterStats_LoadMonsterPlacements(struct CMonsterStats *_this)
{
  char *v1; // ebx@1
  char *result; // eax@2
  char v4; // dl@3
  char *v5; // ecx@3
  int v6; // esi@7
  signed int v8; // [sp+Ch] [bp-10h]@1
  signed int v10; // [sp+14h] [bp-8h]@2
  char *v11; // [sp+18h] [bp-4h]@2
 int i;

  v1 = 0;

 pMonsterPlacementTXT_Raw = class17_fn1(pClass17_Events_LOD, "placemon.txt", 0);
 strtok(pMonsterPlacementTXT_Raw, "\r");

 v8 = 30;

 i = 0;
 _this->uNumMonsterPlacements = 0;
 _this->sPlacements.uNumSubstrings = 0;
 do
 {
    result = strtok(v1, "\r") + 1;
    v11 = v1;
    v10 = (signed int)v1;
    do
    {
      v4 = *result;
      v5 = 0;
      if ( *result != 9 )
      {
        v1 = 0;
        do
        {
          if ( !v4 )
            break;
          ++v5;
          v4 = *(_BYTE *)((_DWORD)v5 + (_DWORD)result);
        }
        while ( v4 != 9 );
      }
      v6 = (_DWORD)v5 + (_DWORD)result;
      if ( *(_BYTE *)((_DWORD)v5 + (_DWORD)result) == (_BYTE)v1 )
        v10 = 1;
      *(_BYTE *)v6 = (_BYTE)v1;
      if ( v5 == v1 )
      {
        v10 = 1;
      }
      else
      {
        if ( v11 == (char *)1 )
          _this->sPlacements.pSubstrings[i] = sub_452C30(result);
      }
      ++v11;
      result = (char *)(v6 + 1);
    }
    while ( (signed int)(v11 - 1) <= 31 && (char *)v10 == v1 );

    ++i;
    _this->sPlacements.uNumSubstrings++;
  }
  while (++_this->uNumMonsterPlacements < 30);

 return result;
}




void CSpellStats_ctor(struct CSpellStats *_this)
{
 memset(_this, 0, sizeof(struct CSpellStats));
}

//----- (0045384A) --------------------------------------------------------
extern unsigned char *pSpellsTXT_Raw;
extern unsigned char some_spell_stuff[];
char *CSpellStats_Initialize(struct CSpellStats *_this)
{
  void *v1; // esi@1
  signed int v4; // ebx@4
  char *v5; // esi@4
  int v6; // eax@5
  char v7; // cl@5
  size_t v8; // ebp@40
  int v9; // eax@41
  int v10; // eax@42
  int v11; // eax@43
  char *result; // eax@53
  signed int v13; // [sp+10h] [bp-10h]@3
  signed int v14; // [sp+14h] [bp-Ch]@4
  signed int v15; // [sp+18h] [bp-8h]@3
  int v16; // [sp+1Ch] [bp-4h]@9
 struct SpellInfo *pSpellInfo;

  v1 = _this;
 if (pSpellsTXT_Raw)
   class23_fn1(class23_instance, pSpellsTXT_Raw);

 pSpellsTXT_Raw = class17_fn1(pClass17_Events_LOD, "spells.txt", 0);
 strtok(pSpellsTXT_Raw, "\r");
 strtok(0, "\r");

  v15 = 1;
  //v13 = (signed int)&unk_4E3C8E;
  v13 = 0;

  pSpellInfo = _this->pSpellInfos;

 do
 {
   v4 = 0;
   v5 = strtok(0, "\r") + 1;
   v14 = 0;
   do
   {
    v7 = *v5;
    v6 = 0;
    while ( v7 != 9 && v7 )
    {
     ++v6;
     v7 = v5[v6];
    }
    v16 = (int)&v5[v6];
    if ( !v5[v6] )
      v14 = 1;
    v5[v6] = 0;
    if ( v6 )
    {
     switch ( v4 )
     {
      case 2:
        pSpellInfo->pSpellName = sub_452C30(v5);
      break;

      case 3:
        pSpellInfo->uSpellSchool = 4;

        if (!_strcmpi("fire", v5))
          pSpellInfo->uSpellSchool = 0;
        else if (!_strcmpi("air", v5))
          pSpellInfo->uSpellSchool = 1;
        else if (!_strcmpi("water", v5))
          pSpellInfo->uSpellSchool = 2;
        else if (!_strcmpi("earth", v5))
          pSpellInfo->uSpellSchool = 3;
        else if (!_strcmpi("spirit", v5))
          pSpellInfo->uSpellSchool = 6;
        else if (!_strcmpi("mind", v5))
          pSpellInfo->uSpellSchool = 7;
        else if (!_strcmpi("body", v5))
          pSpellInfo->uSpellSchool = 8;
        else if (!_strcmpi("light", v5))
          pSpellInfo->uSpellSchool = 9;
        else if (!_strcmpi("dark", v5))
          pSpellInfo->uSpellSchool = 10;
        else if (!_strcmpi("magic", v5))
          pSpellInfo->uSpellSchool = 5;
      break;

      case 4:
        pSpellInfo->pSpellNameShort = sub_452C30(v5);
      break;

      case 5:
        pSpellInfo->pSpellDescription = sub_452C30(v5);
      break;

      case 6:
        pSpellInfo->pSpellBasicSkillDesc = sub_452C30(v5);
      break;

      case 7:
        pSpellInfo->pSpellExpertSkillDesc = sub_452C30(v5);
      break;

      case 8:
        pSpellInfo->pSpellMasterSkillDesc = sub_452C30(v5);
      break;

      case 9:
        pSpellInfo->pSpellGrandmasterSkillDesc = sub_452C30(v5);
      break;

      case 10:
            v4 = 0;
            v8 = strlen(v5);
            if ( (signed int)v8 > 0 )
            {
              do
              {
                v9 = tolower((unsigned __int8)v5[v4]) - 99;
                if ( v9 )
                {
                  v10 = v9 - 2;
                  if ( v10 )
                  {
                    v11 = v10 - 8;
                    if ( v11 == 11)
                      some_spell_stuff[v13 * 20] |= 8;
                    else
                      some_spell_stuff[v13 * 20] |= 1;
                  }
                  else
                    some_spell_stuff[v13 * 20] |= 2;
                }
                else
                  some_spell_stuff[v13 * 20] |= 4;

                ++v4;
              }
              while (v4 < v8);
            }
          break;

          default:
            break;
        }
      }
      else
      {
        v14 = 1;
      }
      ++v4;
      v5 = (char *)(v16 + 1);
    }
    while ( v4 - 1 <= 10 && !v14 );
    result = (char *)(v15 / 11);
    if ( !(v15 % 11) )
      result = strtok((char *)(v15 % 11), "\r");
    v13++;
    ++v15;
    pSpellInfo++;
  }
  while (v13 < 99);
  return result;
}



//----- (00453B3C) --------------------------------------------------------
extern unsigned char *pPotionsTXT_Raw;
int sub_453B3C(struct class40 *_this)
{
  char *i; // eax@3
  signed int v2; // esi@11
  char *v3; // eax@16
  char *v4; // edi@16
  int v5; // esi@17
  __int16 v6; // ax@17
  CHAR Text; // [sp+Ch] [bp-6Ch]@26
  void *v9; // [sp+68h] [bp-10h]@1
  int v10; // [sp+6Ch] [bp-Ch]@10
  int v11; // [sp+70h] [bp-8h]@10
  char *v12; // [sp+74h] [bp-4h]@4

  v9 = _this;

 if (pPotionsTXT_Raw)
   class23_fn1(class23_instance, pPotionsTXT_Raw);

 pPotionsTXT_Raw = class17_fn1(pClass17_Events_LOD, "potion.txt", 0);
 for (i = strtok(pPotionsTXT_Raw, "\t\r\n"); ; i = strtok(0, "\t\r\n"))
 {
  if (!strcmp(i, "222"))
    break;
  if (!i)
    return MessageBoxW(0, L"Error Pre-Parsing Potion Table", L"Load Error", 0x10);
 }

 while (true)
 {
  v12 = strtok(0, "\t\r\n");
  if (!strcmp(v12, "222"))
    break;
  if (!v12)
    return MessageBoxW(0, L"Error Pre-Parsing Potion Table", L"Load Error", 0x10);
 }

  v10 = 0;
  v11 = 30642;
  do
  {
    v12 = 0;
    v2 = 0;
    do
    {
      if ( !strtok(0, "\r\t\n") )
        break;
      ++v2;
    }
    while ( v2 < 6 );
    if ( v2 != 6 )
      break;
    v12 = 0;
    do
    {
      v3 = strtok(0, "\r\t\n");
      v4 = v3;
      if ( !v3 )
        break;
      v6 = atoi(v3);
      v5 = (int)((char *)v9 + 2 * (_DWORD)&v12[v11]);
      *(_WORD *)v5 = v6;
      if ( !v6 )
      {
        if ( tolower((unsigned __int8)*v4) == 101 )
          *(_WORD *)v5 = atoi(v4 + 1);
        else
          *(_WORD *)v5 = 0;
      }
      ++v12;
    }
    while ( (signed int)v12 < 50 );
    if ( v12 != (char *)50 )
      break;
    strtok(0, "\r\t\n");
    v11 += 50;
    ++v10;
  }
  while ( v11 < 33142 );
  if ( v10 != 50 )
  {
    wsprintfA(&Text, "Error Parsing Potion Table at Row: %d Column: %d", v10, v12);
    MessageBoxA(0, &Text, "Parsing Error", 0x10u);
  }

  if (pPotionsTXT_Raw)
  {
    class23_fn1(class23_instance, pPotionsTXT_Raw);
    pPotionsTXT_Raw = 0;
  }
  return pPotionsTXT_Raw;
}



//----- (00453CE5) --------------------------------------------------------
extern unsigned char *pPotionNotesTXT_Raw;
const char *sub_453CE5(struct class40 *_this)
{
  char *i; // eax@3
  signed int v2; // esi@11
  const char *result; // eax@12
  const char *v4; // edi@16
  int v5; // esi@17
  CHAR *v6; // [sp-Ch] [bp-84h]@20
  const CHAR *v7; // [sp-8h] [bp-80h]@20
  UINT v8; // [sp-4h] [bp-7Ch]@20
  CHAR Text; // [sp+Ch] [bp-6Ch]@26
  void *v10; // [sp+68h] [bp-10h]@1
  int v11; // [sp+6Ch] [bp-Ch]@10
  int v12; // [sp+70h] [bp-8h]@10
  char *v13; // [sp+74h] [bp-4h]@4

  v10 = _this;

 if (pPotionNotesTXT_Raw)
   class23_fn1(class23_instance, pPotionNotesTXT_Raw);

 pPotionNotesTXT_Raw = 0;
 pPotionNotesTXT_Raw = class17_fn1(pClass17_Events_LOD, "potnotes.txt", 0);

 for ( i = strtok(pPotionNotesTXT_Raw, "\t\r\n"); ; i = strtok(0, "\t\r\n") )
 {
    v13 = i;
    if ( !strcmp(i, "222") )
      break;
    if ( !v13 )
    {
LABEL_20:
      v8 = 16;
      v7 = "Load Error";
      v6 = "Error Pre-Parsing Potion Table";
      return (const char *)MessageBoxA(0, v6, v7, v8);
    }
 }

 while (true)
 {
    v13 = strtok(0, "\t\r\n");
    if ( !strcmp(v13, "222") )
      break;
    if ( !v13 )
      goto LABEL_20;
  }
  v11 = 0;
  v12 = 33142;
  do
  {
    v13 = 0;
    v2 = 0;
    do
    {
      result = strtok(0, "\r\t\n");
      if ( !result )
        break;
      ++v2;
    }
    while ( v2 < 6 );
    if ( v2 != 6 )
      break;
    v13 = 0;
    do
    {
      result = strtok(0, "\r\t\n");
      v4 = result;
      if ( !result )
        break;
      result = (const char *)atoi(result);
      v5 = (int)((char *)v10 + 2 * (_DWORD)&v13[v12]);
      *(_WORD *)v5 = (_WORD)result;
      if ( !(_WORD)result )
      {
        result = (const char *)tolower((unsigned __int8)*v4);
        if ( result == (const char *)101 )
        {
          result = (const char *)atoi(v4 + 1);
          *(_WORD *)v5 = (_WORD)result;
        }
        else
        {
          *(_WORD *)v5 = 0;
        }
      }
      ++v13;
    }
    while ( (signed int)v13 < 50 );
    if ( v13 != (char *)50 )
      break;
    result = strtok(0, "\r\t\n");
    v12 += 50;
    ++v11;
  }
  while ( v12 < 35642 );
  if ( v11 != 50 )
  {
    wsprintfA(&Text, "Error Parsing Potion Autonote Table at Row: %d Column: %d", v11, v13);
    v8 = 16;
    v7 = "Parsing Error";
    v6 = &Text;
    return (const char *)MessageBoxA(0, v6, v7, v8);
  }
  return result;
}









void class48_ctor(struct class48 *_this)
{
 memset(_this, 0, sizeof(struct class48));
}

//----- (004547E4) --------------------------------------------------------
extern unsigned char *pHostileTXT_Raw;
int class48_Initialize(struct class48 *_this)
{
  char *v2; // eax@4
  int v3; // ebp@4
  signed int v4; // edi@4
  char v5; // dl@5
  char *v6; // ecx@5
  int v7; // esi@9
  signed int v9; // [sp+4h] [bp-Ch]@3
  signed int v10; // [sp+8h] [bp-8h]@4
  void *v11; // [sp+Ch] [bp-4h]@1


  v11 = _this;

 if (pHostileTXT_Raw)
   class23_fn1(class23_instance, pHostileTXT_Raw);

 pHostileTXT_Raw = class17_fn1(pClass17_Events_LOD, "hostile.txt", 0);

 strtok(pHostileTXT_Raw, "\r");
 v9 = 0;
  do
  {
    v2 = strtok(0, "\r") + 1;
    v4 = 0;
    v10 = 0;
    v3 = (int)((char *)v11 + v9 - 89);
    do
    {
      v5 = *v2;
      v6 = 0;
      if ( *v2 != 9 )
      {
        do
        {
          if ( !v5 )
            break;
          ++v6;
          v5 = *(_BYTE *)((_DWORD)v6 + (_DWORD)v2);
        }
        while ( v5 != 9 );
      }
      v7 = (_DWORD)v6 + (_DWORD)v2;
      if ( *(_BYTE *)((_DWORD)v6 + (_DWORD)v2) == 0 )
        v10 = 1;
      *(_BYTE *)v7 = 0;
      if ( v6 == 0 )
      {
        v10 = 1;
      }
      else
      {
        if ( v4 >= 1 )
        {
          if ( v4 <= 90 )
            *(_BYTE *)v3 = atoi(v2);
        }
      }
      ++v4;
      v3 += 89;
      v2 = (char *)(v7 + 1);
    }
    while ( v4 - 1 <= 90 && (char *)v10 == 0 );
    ++v9;
  }
  while ( v9 < 89 );

  if (pHostileTXT_Raw)
  {
    class23_fn1(class23_instance, pHostileTXT_Raw);
    pHostileTXT_Raw = 0;
  }
  return pHostileTXT_Raw;
}






//----- (00453E6D) --------------------------------------------------------
extern unsigned char *pHistoryTXT_Raw;
int StorylineText_Initialize(struct StorylineText *_this)
{
  void *v2; // esi@1
  char *v3; // ecx@4
  char *v4; // eax@5
  char v5; // dl@5
  int v6; // esi@9
  int result; // eax@19
  signed int v9; // [sp+Ch] [bp-10h]@3
  signed int v10; // [sp+10h] [bp-Ch]@4
  char *v11; // [sp+14h] [bp-8h]@4
  int v12; // [sp+18h] [bp-4h]@3

  v2 = _this;

 if (pHistoryTXT_Raw)
    class23_fn1(class23_instance, pHistoryTXT_Raw);

 pHistoryTXT_Raw = class17_fn1(pClass17_Events_LOD, "history.txt", 0);
 strtok(pHistoryTXT_Raw, "\r");

  v12 = (int)((char *)v2 + 20);
  v9 = 29;
  do
  {
    v11 = 0;
    v10 = 0;
    v3 = strtok(0, "\r");
    do
    {
      v5 = *v3;
      v4 = 0;
      if ( *v3 != 9 )
      {
        do
        {
          if ( !v5 )
            break;
          ++v4;
          v5 = *(_BYTE *)((_DWORD)v4 + (_DWORD)v3);
        }
        while ( v5 != 9 );
      }
      v6 = (_DWORD)v4 + (_DWORD)v3;
      if ( *(_BYTE *)((_DWORD)v4 + (_DWORD)v3) == 0)
        v10 = 1;
      *(_BYTE *)v6 = 0;
      if ( v4 == 0 )
      {
        v10 = 1;
      }
      else
      {
        if ( v11 == (char *)1 )
        {
          *(_DWORD *)(v12 - 8) = sub_452C30(v3);
        }
        else
        {
          if ( v11 == (char *)2 )
          {
            *(_BYTE *)v12 = atoi(v3);
          }
          else
          {
            if ( v11 - 2 == (char *)1 )
              *(_DWORD *)(v12 - 4) = sub_452C30(v3);
          }
        }
      }
      ++v11;
      v3 = (char *)(v6 + 1);
      result = (int)(v11 - 1);
    }
    while ( (signed int)(v11 - 1) <= 3 && (char *)v10 == 0 );
    v12 += 12;
  }
  while ( v9-- != 1 );
  return result;
}


//----- (0048A3BC) --------------------------------------------------------
extern char Dest[];
int class35_sub_48A3BC(struct class35 *_this, int a2)
{
  signed int result; // eax@1
  int v3; // ecx@1
  signed int v4; // esi@6
  double v5; // st7@7
  double v6; // st7@12
  double v7; // st6@17
  signed __int64 v8; // qax@17
  double v9; // st6@17
  char v10; // [sp+18h] [bp-388h]@6
  char v11; // [sp+19h] [bp-387h]@17
  char v12[766]; // [sp+1Ah] [bp-386h]@17
  struct class18 class18_obj;//char class18_obj[128]; // [sp+318h] [bp-88h]@4
  //class18_obj::ptr_000044 //int v14; // [sp+35Ch] [bp-44h]@7
  char Source[32]; // [sp+360h] [bp-40h]@4
  void *v16; // [sp+380h] [bp-20h]@1
  float v17; // [sp+384h] [bp-1Ch]@7
  int v18; // [sp+388h] [bp-18h]@6
  float v19; // [sp+38Ch] [bp-14h]@7
  float v20; // [sp+390h] [bp-10h]@7
  float v21; // [sp+394h] [bp-Ch]@7
  float v22; // [sp+398h] [bp-8h]@7
  float v23; // [sp+39Ch] [bp-4h]@7

  v16 = _this;
  v3 = (int)((char *)_this + 0x267A04);
  result = 1;
  while ( *(_DWORD *)v3 != a2 )
  {
    ++result;
    v3 += 4;
    if ( result >= 50 )
    {
      sprintf(Source, "pal%03i", a2);
      class18_ctor(&class18_obj);
      if ( class17_LoadPalette(pClass17_Bitmaps_LOD, &class18_obj, Source, 1u) == 1 )
      {
        v4 = 0;
        v18 = 1 - (_DWORD)&v10;
        do
        {
         v21 = class18_obj.ptr_000044[v4] * 0.003921568859368563;

         v20 = class18_obj.ptr_000044[class18_obj.ptr_000044[v4] + v18] * 0.003921568859368563;

         v23 = class18_obj.ptr_000044[v4 + 2] * 0.003921568859368563;

          sub_48A7AA(&v17, &v19, v21, v20, v23, &v22);
          v5 = *(float *)&v22 * 1.100000023841858;
          if ( v5 >= 0.0 && v5 >= 1.0 )
          {
            v5 = 1.0;
          }
          else
          {
            if ( v5 < 0.0 )
              v5 = 0.0;
          }
          *(float *)&v22 = v5;
          v6 = v19 * 0.6499999761581421;
          if ( v6 >= 0.0 && v6 >= 1.0 )
          {
            v6 = 1.0;
          }
          else
          {
            if ( v6 < 0.0 )
              v6 = 0.0;
          }
          v19 = v6;
          sub_48A643((int)&v21, (int)&v20, (int)&v23, v17, v19, *(float *)&v22);
          v7 = v20 * 255.0;
          *(&v10 + v4) = (signed __int64)(v21 * 255.0);
          v8 = (signed __int64)v7;
          v9 = *(float *)&v23 * 255.0;
          *(&v11 + v4) = v8;
          v12[v4] = (signed __int64)v9;
          v4 += 3;
        }
        while ( v4 < 768 );
        sub_40F77C((int)&Dest);
        result = sub_48A5A4(v16, a2, (int)&v10);
      }
      else
      {
        result = 0;
      }
      return result;
    }
  }
  return result;
}












//----- (004AC7C0) --------------------------------------------------------
extern struct class35 class35_obj;
int sub_4AC7C0(struct class17 *_this, const char *pSourceFile, int a3)
{
  int v3; // edi@1
  int v4; // esi@1
  int v5; // eax@6
  signed int v6; // ecx@10
  int v7; // eax@11
  int v8; // eax@12
  int v10; // edx@21
  int v11; // eax@21
  signed int v12; // eax@22
  unsigned __int8 v13; // zf@23
  unsigned __int8 v14; // sf@23
  char DstBuf; // [sp+Ch] [bp-3Ch]@13
  __int16 v16; // [sp+1Ch] [bp-2Ch]@21
  __int16 v17; // [sp+1Eh] [bp-2Ah]@12
  __int16 v18; // [sp+20h] [bp-28h]@12
  __int16 v19; // [sp+26h] [bp-22h]@12
  int v20; // [sp+2Ch] [bp-1Ch]@12
  int v21; // [sp+30h] [bp-18h]@12
  char *Str1; // [sp+34h] [bp-14h]@24
  const char *v23; // [sp+38h] [bp-10h]@3
  int v24; // [sp+44h] [bp-4h]@12

 v3 = 0;
 v4 = _this;
 if (pD3DRenderer->dword_040088)
 {
  if ( *(_DWORD *)((char *)_this + 60572) > 0 )
    {
      v23 = 0;
      while ( _strcmpi(*(const char **)&v23[*(_DWORD *)(v4 + 60592)], pSourceFile) )
      {
        v23 += 40;
        ++v3;
        if ( v3 >= *(_DWORD *)(v4 + 60572) )
          goto LABEL_6;
      }
      return v3;
    }
  }
  else
  {
    if (_this->dword_00EC9C > 0)
    {
      v23 = (const char *)((char *)_this + 572);
      while ( _strcmpi(v23, pSourceFile) )
      {
        v23 += 40;
        ++v3;
        if ( v3 >= *(_DWORD *)(v4 + 60572) )
          goto LABEL_6;
      }
      return v3;
    }
  }

LABEL_6:
 v5 = _this->dword_00EC9C;
 if ( v5 == 1500 )
   return -1;
 if (pD3DRenderer->dword_040088 && _this->dword_00ECAC)
 {
  if (!_this->dword_00ECB0)
  {
   _this->dword_00ECB0 = class23_AllocatedNamedBuffer(class23_instance, 0, 1500 * 40, "hardSprites");
   v6 = 0;
   do
   {
        v7 = v6++ * 40 + _this->dword_00ECB0;
        *(_DWORD *)v7 = 0;
        *(_DWORD *)(v7 + 8) = 0;
        *(_DWORD *)(v7 + 12) = 0;
      }
      while (v6 < 1500 );
    }

    v17 = 0;
    v18 = 0;
    v19 = 0;
    v20 = 0;
    v21 = 0;
    v24 = 0;
    v8 = class17_FindContainer(_this, pSourceFile, 0);
    if ( !v8 )
    {
      v24 = -1;
      sub_462463((int)&DstBuf);
      return -1;
    }
    locked_fread(&DstBuf, 1u, 0x20u, (FILE *)v8);
    v10 = *(_DWORD *)(v4 + 60592);
    v11 = 5 * *(_DWORD *)(v4 + 60572);
    v24 = -1;
    *(_DWORD *)(v10 + 8 * v11 + 24) = v16;
    *(_DWORD *)(*(_DWORD *)(v4 + 60592) + 40 * *(_DWORD *)(v4 + 60572) + 28) = v17;
    *(_WORD *)(v4 + 40 * *(_DWORD *)(v4 + 60572) + 588) = v16;
    *(_WORD *)(v4 + 40 * *(_DWORD *)(v4 + 60572) + 590) = v17;
    sub_462463((int)&DstBuf);
    goto LABEL_29;
  }

  //v12 = sub_4AC67E(_this, (char *)(_this + 40 * v5 + 0x23C), pSourceFile);
  v12 = sub_4AC67E(_this, &_this->aLODHeaders[v5], pSourceFile);
  *(_WORD *)(v4 + 40 * _this->dword_00EC9C + 0x256) = 0;
  if ( v12 != -1 )
  {
LABEL_28:
    *(_WORD *)(v4 + 40 * *(_DWORD *)(v4 + 60572) + 592) = class35_sub_48A3BC(
                                                            &class35_obj,
                                                            *(_WORD *)(v4 + 40 * *(_DWORD *)(v4 + 60572) + 592));
LABEL_29:
    if ( pD3DRenderer->dword_040088 )
    {
      *(_DWORD *)(*(_DWORD *)(v4 + 60592) + 40 * *(_DWORD *)(v4 + 60572)) = class23_AllocatedNamedBuffer(
                                                                              &class23_instance,
                                                                              *(_DWORD *)(*(_DWORD *)(v4 + 60592)
                                                                                        + 40 * *(_DWORD *)(v4 + 60572)),
                                                                              20,
                                                                              pSourceFile);
      strcpy(*(char **)(*(_DWORD *)(v4 + 60592) + 40 * *(_DWORD *)(v4 + 60572)), pSourceFile);
      *(_DWORD *)(*(_DWORD *)(v4 + 60592) + 40 * *(_DWORD *)(v4 + 60572) + 4) = a3;
      sub_4A5048(pD3DRenderer, *(_DWORD *)(v4 + 60592) + 40 * *(_DWORD *)(v4 + 60572));
    }
    ++*(_DWORD *)(v4 + 60572);
    return *(_DWORD *)(v4 + 60572) - 1;
  }
  v13 = *(_DWORD *)(v4 + 60572) == 0;
  v14 = *(_DWORD *)(v4 + 60572) < 0;
  v23 = 0;
  if ( v14 | v13 )
  {
LABEL_27:
    if ( sub_4AC67E(v4, (char *)(v4 + 40 * *(_DWORD *)(v4 + 60572) + 572), "pending") == -1 )
      return -1;
    goto LABEL_28;
  }
  Str1 = (char *)(v4 + 572);
  while ( _strcmpi(Str1, "pending") )
  {
    ++v23;
    Str1 += 40;
    if ( (signed int)v23 >= *(_DWORD *)(v4 + 60572) )
      goto LABEL_27;
  }
  return (int)v23;
}











void CNPCStats_ctor(struct CNPCStats *_this)
{
 memset(_this, 0, sizeof(struct CNPCStats));
}

//----- (0047702F) --------------------------------------------------------
void CNPCStats_Initialize(struct CNPCStats *_this)
{
  int v2; // edi@1
  char *v4; // ebx@3
  char v5; // al@4
  int v6; // ecx@4
  int v7; // ebx@18
  char *v9; // ecx@19
  int v10; // eax@20
  char v11; // dl@20
  int result; // eax@39
  char v13; // zf@41
  signed int v14; // [sp+Ch] [bp-14h]@18
  int v15; // [sp+10h] [bp-10h]@4
  int v16; // [sp+10h] [bp-10h]@24
  unsigned char **v17; // [sp+14h] [bp-Ch]@1
  signed int v18; // [sp+14h] [bp-Ch]@19
  signed int v19; // [sp+18h] [bp-8h]@1
  int v20; // [sp+18h] [bp-8h]@18
  signed int v21; // [sp+1Ch] [bp-4h]@3
  signed int v22; // [sp+1Ch] [bp-4h]@19

  v2 = (int)_this;
  CNPCStats_sub_476CB5(_this);
  CNPCStats_sub_476977(_this);
  InitializeQuests();
  InitializeAutonotes();
  InitializeAwards();
  InitializeTransitions();
  InitializeMerchants();
  InitializeScrolls();

  _this->dword_017FC0 = 0;

 _this->pNPCNamesTXT_Raw = class17_fn1(pClass17_Events_LOD, "npcnames.txt", 0);
 strtok(_this->pNPCNamesTXT_Raw, "\r");

  v19 = 0;
  v17 = _this->pNPCNames;
  while ( 1 )
  {
    v4 = strtok(0, "\r") + 1;
    v21 = 0;
    do
    {
      v5 = *v4;
      v6 = 0;
      v15 = 0;
      if ( *v4 == 9 )
        goto LABEL_45;
      do
      {
        if ( !v5 )
          break;
        if ( v5 == 10 )
          break;
        ++v6;
        v15 = v6;
        v5 = v4[v6];
      }
      while ( v5 != 9 );
      if ( v6 )
      {
        v4[v6] = 0;
        if ( v21 )
        {
          if ( v21 == 1 )
            v17[1] = sub_452C30(v4);
        }
        else
        {
          v17[0] = sub_452C30(v4);
        }
      }
      else
      {
LABEL_45:
        if ( v21 == 1 )
        {
          if (!_this->uNumNPCNames[1])
            _this->uNumNPCNames[1] = v19;
        }
      }
      ++v21;
      v4 += v15 + 1;
    }
    while ( v21 <= 1 );
    ++v19;
    v17 += 2;
    if ( v19 >= 540 )
      break;
  }
  _this->uNumNPCNames[0] = v19;

  _this->pNPCProfTXT_Raw = class17_fn1(pClass17_Events_LOD, "npcprof.txt", 0);
  strtok(_this->pNPCProfTXT_Raw, "\r");
  strtok(0, "\r");
  strtok(0, "\r");
  strtok(0, "\r");
  v7 = v2 + 80504;
  v20 = v2 + 80504;
  v14 = 58;
  do
  {
    v22 = 0;
    v9 = strtok(0, "\r") + 1;
    v18 = 0;
    do
    {
      v11 = *v9;
      v10 = 0;
      if ( *v9 != 9 )
      {
        do
        {
          if ( !v11 )
            break;
          ++v10;
          v11 = v9[v10];
        }
        while ( v11 != 9 );
        v7 = v20;
      }
      v16 = (int)&v9[v10];
      if ( !v9[v10] )
        v18 = 1;
      *(_BYTE *)v16 = 0;
      if ( v10 )
      {
        switch ( v22 )
        {
          case 2:
            *(_DWORD *)(v7 - 12) = atoi(v9);
            break;
          case 3:
            *(_DWORD *)(v7 - 4) = sub_452C30(v9);
            break;
          case 4:
            *(_DWORD *)(v7 - 8) = sub_452C30(v9);
            break;
          case 5:
            *(_DWORD *)v7 = sub_452C30(v9);
            break;
          case 6:
            *(_DWORD *)(v7 + 4) = sub_452C30(v9);
            break;
        }
      }
      else
      {
        if ( !v22 )
          v18 = 1;
      }
      ++v22;
      result = v16;
      v9 = (char *)(v16 + 1);
    }
    while ( v22 <= 6 && !v18 );
    v7 += 20;
    v13 = v14-- == 1;
    v20 = v7;
  }
  while ( !v13 );
  *(_DWORD *)(v2 + 98252) = 59;
}







//----- (00476CB5) --------------------------------------------------------
char *CNPCStats_sub_476CB5(struct CNPCStats *_this)
{
  int v1; // edi@1
  void *v2; // esi@1
  char *v4; // eax@2
  char v5; // dl@3
  int v6; // ecx@3
  char *v7; // eax@11
  char *v10; // ecx@27
  int v11; // eax@28
  char v12; // dl@28
  int v13; // edi@32
  char *v16; // eax@43
  char v17; // dl@44
  int v18; // ecx@44
  int v19; // edi@48
  char *result; // eax@57
  char v23; // cl@58
  int v24; // edi@58
  int v25; // esi@62
  int v27; // [sp+Ch] [bp-14h]@7
  signed int v28; // [sp+10h] [bp-10h]@1
  signed int v29; // [sp+10h] [bp-10h]@26
  signed int v30; // [sp+10h] [bp-10h]@42
  signed int v31; // [sp+10h] [bp-10h]@56
  int v32; // [sp+14h] [bp-Ch]@1
  int v33; // [sp+14h] [bp-Ch]@26
  int v34; // [sp+14h] [bp-Ch]@42
  int v35; // [sp+14h] [bp-Ch]@56
  signed int v36; // [sp+18h] [bp-8h]@2
  signed int v37; // [sp+18h] [bp-8h]@27
  signed int v38; // [sp+18h] [bp-8h]@43
  signed int v39; // [sp+18h] [bp-8h]@57
  signed int v40; // [sp+1Ch] [bp-4h]@2
  signed int v41; // [sp+1Ch] [bp-4h]@27
  signed int v42; // [sp+1Ch] [bp-4h]@43
  signed int v43; // [sp+1Ch] [bp-4h]@57

  v2 = _this;

 _this->pNPCDataTXT_Raw = class17_fn1(pClass17_Events_LOD, "npcdata.txt", 0);
 strtok(_this->pNPCDataTXT_Raw, "\r");
 strtok(0, "\r");

  v1 = (int)((char *)_this + 96);
  v32 = (int)((char *)_this + 89460);
  v28 = 500;
  do
  {
    v36 = 0;
    v4 = strtok(0, "\r") + 1;
    v40 = -1;
    do
    {
      v5 = *v4;
      v6 = 0;
      while ( v5 != 9 && v5 )
      {
        ++v6;
        v5 = v4[v6];
      }
      v27 = (int)&v4[v6];
      if ( !v4[v6] )
        v36 = 1;
      v4[v6] = 0;
      if ( v6 )
      {
        switch ( v40 )
        {
          case 0:
            v7 = sub_452C30(v4);
            *(_DWORD *)(v1 - 20) = v7;
            *(_DWORD *)v32 = v7;
            break;
          case 1:
            *(_DWORD *)(v1 - 16) = atoi(v4);
            break;
          case 5:
            *(_DWORD *)v1 = atoi(v4);
            break;
          case 6:
            *(_DWORD *)(v1 + 4) = atoi(v4);
            break;
          case 7:
            *(_DWORD *)(v1 + 8) = atoi(v4);
            break;
          case 8:
            *(_DWORD *)(v1 + 12) = *v4 == 121;
            break;
          case 9:
            *(_DWORD *)(v1 + 20) = atoi(v4);
            break;
          case 10:
            *(_DWORD *)(v1 + 24) = atoi(v4);
            break;
          case 11:
            *(_DWORD *)(v1 + 28) = atoi(v4);
            break;
          case 12:
            *(_DWORD *)(v1 + 32) = atoi(v4);
            break;
          case 13:
            *(_DWORD *)(v1 + 36) = atoi(v4);
            break;
          case 14:
            *(_DWORD *)(v1 + 40) = atoi(v4);
            break;
          default:
            break;
        }
      }
      ++v40;
      v4 = (char *)(v27 + 1);
    }
    while ( v40 + 1 <= 15 && !v36 );
    v32 += 4;
    v1 += 76;
  }
  while ( v28-- != 1 );
  *((_DWORD *)v2 + 24561) = 501;


 _this->pNPCGreetTXT_Raw = class17_fn1(pClass17_Events_LOD, "npcgreet.txt", 0);
 strtok(_this->pNPCGreetTXT_Raw, "\r");

  v33 = (int)((char *)v2 + 96396);
  v29 = 205;
  do
  {
    v41 = 0;
    v37 = 0;
    v10 = strtok(0, "\r") + 1;
    do
    {
      v12 = *v10;
      v11 = 0;
      while ( v12 != 9 && v12 )
      {
        ++v11;
        v12 = v10[v11];
      }
      v13 = (int)&v10[v11];
      if ( !v10[v11] )
        v37 = 1;
      *(_BYTE *)v13 = 0;
      if ( v11 )
      {
        if ( v41 == 1 )
        {
          *(_DWORD *)v33 = sub_452C30(v10);
        }
        else
        {
          if ( v41 == 2 )
            *(_DWORD *)(v33 + 4) = sub_452C30(v10);
        }
      }
      ++v41;
      v10 = (char *)(v13 + 1);
    }
    while ( v41 <= 2 && !v37 );
    v33 += 8;
  }
  while ( v29-- != 1 );

 _this->pNCPGroupTXT_Raw = class17_fn1(pClass17_Events_LOD, "npcgroup.txt", 0);
 strtok(_this->pNCPGroupTXT_Raw, "\r");

  v34 = (int)((char *)v2 + 98036);
  v30 = 51;
  do
  {
    v16 = strtok(0, "\r") + 1;
    v42 = 0;
    v38 = 0;
    do
    {
      v17 = *v16;
      v18 = 0;
      while ( v17 != 9 && v17 )
      {
        ++v18;
        v17 = v16[v18];
      }
      v19 = (int)&v16[v18];
      if ( !v16[v18] )
        v38 = 1;
      *(_BYTE *)v19 = 0;
      if ( v18 )
      {
        if ( v42 == 1 )
          *(_WORD *)v34 = atoi(v16);
      }
      ++v42;
      v16 = (char *)(v19 + 1);
    }
    while ( v42 <= 1 && !v38 );
    v34 += 2;
  }
  while ( v30-- != 1 );

 _this->pNPCNewsTXT_Raw = class17_fn1(pClass17_Events_LOD, "npcnews.txt", 0);
 strtok(_this->pNPCNewsTXT_Raw, "\r");

  v35 = (int)((char *)v2 + 89252);
  v31 = 51;
  do
  {
    result = strtok(0, "\r") + 1;
    v43 = 0;
    v39 = 0;
    do
    {
      v23 = *result;
      v24 = 0;
      while ( v23 != 9 && v23 )
      {
        ++v24;
        v23 = result[v24];
      }
      v25 = (int)&result[v24];
      if ( !result[v24] )
        v39 = 1;
      *(_BYTE *)v25 = 0;
      if ( v24 )
      {
        if ( v43 == 1 )
          *(_DWORD *)v35 = sub_452C30(result);
      }
      ++v43;
      result = (char *)(v25 + 1);
    }
    while ( v43 <= 1 && !v39 );
    v35 += 4;
  }
  while ( v31-- != 1 );
  return result;
}




//----- (00476977) --------------------------------------------------------
extern char unk_72166C;
extern char unk_721668;
int CNPCStats_sub_476977(struct CNPCStats *_this)
{
 int v1;
  int v2; // esi@1
  char *v4; // eax@4
  char v5; // dl@5
  int v6; // ecx@5
  int v7; // edi@9
  int v8; // eax@20
  char *v9; // eax@21
  char v10; // dl@22
  int v11; // ecx@22
  int v12; // edi@26
  int v13; // eax@37
  char *v14; // eax@39
  char v15; // dl@40
  int v16; // ecx@40
  int v17; // edi@44
  char v18; // zf@47
  int v19; // eax@57
  signed int v20; // edx@57
  signed int v21; // ecx@58
  int result; // eax@61
  int v23; // [sp+10h] [bp-10h]@4
  int v24; // [sp+10h] [bp-10h]@21
  int v25; // [sp+10h] [bp-10h]@39
  signed int v26; // [sp+14h] [bp-Ch]@4
  signed int v27; // [sp+14h] [bp-Ch]@21
  signed int v28; // [sp+14h] [bp-Ch]@39
  signed int v29; // [sp+18h] [bp-8h]@3
  signed int v30; // [sp+18h] [bp-8h]@20
  signed int v31; // [sp+18h] [bp-8h]@37
  int v32; // [sp+1Ch] [bp-4h]@37

  v2 = _this;
  if (_this->pNPCTextTXT_Raw)
    class23_fn1(class23_instance, _this->pNPCTextTXT_Raw);

  _this->pNPCTextTXT_Raw = class17_fn1(pClass17_Events_LOD, "npctext.txt", 0);
  strtok(_this->pNPCTextTXT_Raw, "\r");
  //v29 = (signed int)&unk_72166C;
  v29 = 0;
  do
  {
    v4 = strtok(0, "\r") + 1;
    v23 = 0;
    v26 = 0;
    do
    {
      v5 = *v4;
      v6 = 0;
      if ( *v4 != 9 )
      {
        do
        {
          if ( !v5 )
            break;
          ++v6;
          v5 = v4[v6];
        }
        while ( v5 != 9 );
      }
      v7 = (int)&v4[v6];
      if ( !v4[v6] )
        v26 = 1;
      *(_BYTE *)v7 = 0;
      if ( v6 == 0 )
      {
        v26 = 1;
      }
      else
      {
        if ( v23 == 1 )
          *(_DWORD *)(&unk_72166C + v29) = sub_452C30(v4);
      }
      ++v23;
      v4 = (char *)(v7 + 1);
    }
    while ( v23 - 1 <= 1 && v26 == 0 );
    v29 += 8;
  }
  //while ( v29 < (signed int)&unk_722F14 );
  while (v29 < 0x18A8);

 if (_this->pNPCTopicTXT_Raw)
   class23_fn1(class23_instance, _this->pNPCTopicTXT_Raw);

 _this->pNPCTopicTXT_Raw = class17_fn1(pClass17_Events_LOD, "npctopic.txt", 0);
 strtok(_this->pNPCTopicTXT_Raw, "\r");

  //v30 = (signed int)&unk_721668;
  v30 = 0;
  do
  {
    v9 = strtok(0, "\r") + 1;
    v24 = 0;
    v27 = 0;
    do
    {
      v10 = *v9;
      v11 = 0;
      if ( *v9 != 9 )
      {
        do
        {
          if ( !v10 )
            break;
          ++v11;
          v10 = v9[v11];
        }
        while ( v10 != 9 );
      }
      v12 = (int)&v9[v11];
      if ( !v9[v11] )
        v27 = 1;
      *(_BYTE *)v12 = 0;
      if ( v11 == 0 )
      {
        v27 = 1;
      }
      else
      {
        if ( v24 == 1 )
          *(_DWORD *)(&unk_721668 + v30) = sub_452C30(v9);
      }
      ++v24;
      v9 = (char *)(v12 + 1);
    }
    while ( v24 - 1 <= 1 && v27 == 0 );
    v30 += 8;
  }
  //while ( v30 < (signed int)&unk_722880 );
  while (v30 < 0x1218);


 if (_this->pNPCDistTXT_Raw)
   class23_fn1(class23_instance, _this->pNPCDistTXT_Raw);

 _this->pNPCDistTXT_Raw = class17_fn1(pClass17_Events_LOD, "npcdist.txt", 0);
 strtok(_this->pNPCDistTXT_Raw, "\r");
 strtok(0, "\r");

 v1 = 0;
  v31 = 1;
  v32 = v2 + 91465;
  while ( 2 )
  {
    v14 = strtok(0, "\r") + 1;
    v28 = 0;
    v25 = v1;
    do
    {
      v15 = *v14;
      v16 = 0;
      if ( *v14 != 9 )
      {
        do
        {
          if ( !v15 )
            break;
          ++v16;
          v15 = v14[v16];
        }
        while ( v15 != 9 );
        v1 = v25;
      }
      v17 = (int)&v14[v16];
      if ( !v14[v16] )
        v28 = 1;
      *(_BYTE *)v17 = 0;
      if ( !v16 )
      {
        v28 = 1;
        goto LABEL_54;
      }
      v18 = v1 == 0;
      if ( v1 > 0 )
      {
        if ( v1 < 77 )
        {
          *(_BYTE *)(v31 + (v1 << 6) + v2 + 91464) = atoi(v14);
          goto LABEL_54;
        }
        v18 = v1 == 0;
      }
      if ( v18 )
        *(_BYTE *)v32 = 10;
LABEL_54:
      ++v1;
      v14 = (char *)(v17 + 1);
      v25 = 0;
    }
    while ( v1 - 1 <= 77 && !v28 );
    ++v31;
    ++v32;
    if ( v31 < 59 )
    {
      v1 = 0;
      continue;
    }
    break;
  }
  v19 = v2 + 91460;
  v20 = 77;
  do
  {
    *(_DWORD *)v19 = 0;
    v21 = 1;
    do
      *(_DWORD *)v19 += *(_BYTE *)(v19 + v21++ + 4);
    while ( v21 < 59 );
    v19 += 64;
    --v20;
  }
  while ( v20 );

 if (_this->pNPCDistTXT_Raw)
 {
  class23_fn1(class23_instance, _this->pNPCDistTXT_Raw);
  _this->pNPCDistTXT_Raw = 0;
 }
 return 0;
}





//----- (0048A8A3) --------------------------------------------------------
int class35_sub_48A8A3(struct class35 *_this)
{
  signed int v1; // eax@1
  int v2; // edx@1

  v2 = (char *)_this + 0x267A04;
  v1 = 1;
 do
 {
  if ( *(_DWORD *)v2 )
    *(_DWORD *)((char *)_this + 0x267AC8) = v1 + 1;
  ++v1;
  v2 += 4;
 }
 while ( v1 < 50 );
 return *(_DWORD *)((char *)_this + 0x267AC8);
}



//----- (00402F07) --------------------------------------------------------
void sub_402F07(int *_this)
{
 _this[0] = 0;
 _this[1] = 0;
 _this[2] = 0;
 _this[3] = 0;
 _this[4] = 0;
 _this[5] = 0;
 ((char *)(_this))[24] = 0;
 ((char *)(_this))[26] = 0;
 _this[7] = 0;
 _this[8] = 0;
}




//----- (00456620) --------------------------------------------------------
extern char byte_ACD772[];
extern char byte_ACD71D[];
extern char byte_5D2A12[];
extern char byte_0D2A84[];
extern char byte_5D2A04[];
unsigned int __fastcall sub_449B57(int a1, __int16 a2);
char sub_456620(struct class40 *_this, int a2, signed int a3, unsigned char *Dst)
{
  void *v4; // edi@1
  unsigned char *v5; // esi@1
  int v6; // ebx@3
  int *v7; // ecx@33
  int v8; // eax@34
  int v9; // eax@39
  int v10; // ebx@43
  int v11; // ecx@47
  int *v12; // edx@48
  int v13; // eax@49
  signed int v14; // ebx@52
  int v15; // eax@53
  signed int v16; // eax@55
  int v17; // ebx@57
  int v18; // eax@61
  int v19; // edx@62
  signed int v20; // ebx@70
  int v21; // ebx@85
  int v22; // edx@86
  int v23; // ebx@86
  int v24; // ebx@89
  int v25; // edx@89
  int v26; // eax@89
  int v27; // ecx@90
  int v28; // ecx@91
  int v29; // ebx@91
  int v30; // eax@91
  unsigned __int8 v31; // sf@97
  unsigned __int8 v32; // of@97
  int v33; // ebx@98
  int v34; // eax@99
  int v35; // edx@99
  signed __int64 v36; // qtt@99
  signed int v37; // ebx@101
  int v38; // ecx@102
  char v39; // zf@107
  char v40; // al@108
  char v41; // al@111
  int *v42; // edx@118
  int v43; // edx@120
  int v44; // edx@120
  int *j; // eax@121
  int v46; // ecx@123
  int v47; // eax@123
  int v48; // eax@123
  unsigned char v50[0xC80]; // [sp+Ch] [bp-C88h]@33
  int v51; // [sp+C8Ch] [bp-8h]@33
  int v52; // [sp+C90h] [bp-4h]@1
  int v53; // [sp+C9Ch] [bp+8h]@3
  int v54; // [sp+CA0h] [bp+Ch]@34
  signed int v55; // [sp+CA0h] [bp+Ch]@55
  int v56; // [sp+CA0h] [bp+Ch]@62
  int i; // [sp+CA0h] [bp+Ch]@89
  int *v58; // [sp+CA0h] [bp+Ch]@102
  int v59; // [sp+CA0h] [bp+Ch]@123
  signed int v60; // [sp+CA4h] [bp+10h]@33
  int v61; // [sp+CA4h] [bp+10h]@101
  int v62; // [sp+CA4h] [bp+10h]@120

  v52 = -1;
  v4 = _this;

  v5 = Dst;
  if (!v5)
    v5 = class23_AllocatedNamedBuffer(class23_instance, 0, 0x24, "newItemGen");
  memset(v5, 0, 0x24);

  v6 = a2 - 1;
  v53 = a2 - 1;

  if ( a3 )
  {
    switch ( a3 )
    {
      case 20:         a3 = 0;        break;
      case 21:        a3 = 3;        break;
      case 22:        v52 = 38;        break;
      case 23:        v52 = 1;        break;
      case 24:        v52 = 2;        break;
      case 25:        v52 = 3;        break;
      case 26:        v52 = 4;        break;
      case 27:        v52 = 5;        break;
      case 28:        v52 = 6;        break;
      case 30:        v52 = 0;        break;
      case 31:        v52 = 9;        break;
      case 32:        v52 = 10;        break;
      case 33:        v52 = 11;        break;
      case 34:        a3 = 4;        break;
      case 35:        a3 = 5;        break;
      case 36:        a3 = 6;        break;
      case 37:        a3 = 7;        break;
      case 38:        a3 = 8;        break;
      case 39:        a3 = 9;        break;
      case 40:        a3 = 10;        break;
      case 41:        a3 = 11;        break;
      case 42:        a3 = 12;        break;
      case 43:        a3 = 15;        break;
      case 44:        a3 = 14;        break;
      case 45:        a3 = 13;        break;
      case 46:        a3 = 19;        break;
      case 29:        v52 = 37;        break;
      default:        --a3;        break;
    }
    memset(&v50, 0, 0xC80);

    v51 = 0;
    v7 = v50;
    v60 = 1;
    if ( v52 == -1 )
    {
     v52 = &_this->pItems[0].uEquipType;//(int)((char *)v4 + 80);
      v9 = (int)((char *)v4 + v6 + 92);
      do
      {
        if ( *(_BYTE *)v52 == a3 )
        {
          *v7 = v60;
          ++v7;
          v51 += *(_BYTE *)v9;
        }
        ++v60;
        v52 += 48;
        v9 += 48;
      }
      while ( v60 < 500 );
    }
    else
    {
      v54 = (int)((char *)v4 + 81);
      v8 = (int)((char *)v4 + v6 + 92);
      do
      {
        if ( *(_BYTE *)v54 == v52 )
        {
          *v7 = v60;
          ++v7;
          v51 += *(_BYTE *)v8;
        }
        ++v60;
        v54 += 48;
        v8 += 48;
      }
      while ( v60 < 500 );
    }
    v10 = 0;
    if ( v51 )
      v10 = rand() % v51;
    v5 = v50;
    if ( !v50 )
      *(_DWORD *)v5 = 1;
    v11 = (char *)(&_this->pItems[*(_DWORD *)v5 - 1]) + v53 + 44;
    //v11 = *((_BYTE *)v4 + 48 * *(_DWORD *)v5 + v53 + 44);
    if ( v11 < v10 )
    {
      v12 = &v50;
      do
      {
        ++v12;
        v13 = *v12;
        *(_DWORD *)v5 = *v12;
        v11 += *((_BYTE *)v4 + 48 * v13 + v53 + 44);
      }
      while ( v11 < v10 );
    }

    if (_this->pItems[*(_DWORD *)v5 - 1].uEquipType == 14 && *(_DWORD *)v5 != 220 )
    //if ( *((_BYTE *)v4 + 48 * *(_DWORD *)v5 + 32) == 14 && *(_DWORD *)v5 != 220 )
    {
      *(_DWORD *)(v5 + 4) = 0;
      v14 = 2;
      do
      {
        *(_DWORD *)(v5 + 4) += rand() % 4 + 1;
        v15 = *(_DWORD *)(v5 + 4);
        --v14;
      }
      while ( v14 );
LABEL_72:
      *(_DWORD *)(v5 + 4) = v15 * (v53 + 1);
      goto LABEL_73;
    }
  }
  else
  {
    v16 = 0;
    v55 = 0;
    do
      v55 += (unsigned __int8)byte_ACD772[v16++];
    while ( v16 < 29 );
    v17 = rand() % 29;
    if ( v53 == 5 && rand() % 100 < 5 && !byte_ACD772[v17] && v55 < 13 )
    {
      byte_ACD772[v17] = 1;
      *(_DWORD *)(v5 + 20) = 0;
      *(_DWORD *)v5 = v17 + 500;
      LOBYTE(v18) = sub_456D17(v4, v5);
      return v18;
    }
    v56 = 0;
    v19 = rand() % *((_DWORD *)v4 + v53 + 17825);
    *(_DWORD *)v5 = 0;
    if ( v19 > 0 )
    {
      do
        v56 += *((_BYTE *)v4 + 48 * *(_DWORD *)v5++ + v53 + 92);
      while ( v56 < v19 );
    }
    if ( !v19 )
      *(_DWORD *)v5 = 1;
    if ( !*(_DWORD *)v5 )
      *(_DWORD *)v5 = 1;
    if ( *((_BYTE *)v4 + 48 * *(_DWORD *)v5 + 32) == 14 && *(_DWORD *)v5 != 220 )
    {
      *(_DWORD *)(v5 + 4) = 0;
      v20 = 2;
      do
      {
        *(_DWORD *)(v5 + 4) += rand() % 4 + 1;
        v15 = *(_DWORD *)(v5 + 4);
        --v20;
      }
      while ( v20 );
      goto LABEL_72;
    }
  }
LABEL_73:
  if ( *(_DWORD *)v5 == 487 )
  {
    if ( !(unsigned __int16)sub_449B57((int)byte_ACD71D, 239) )
      *(_DWORD *)v5 = 486;
  }
  if ( byte_5D2A12[48 * *(_DWORD *)v5] )
    *(_DWORD *)(v5 + 20) = 0;
  else
    *(_DWORD *)(v5 + 20) = 1;
  if ( *((_BYTE *)v4 + 48 * *(_DWORD *)v5 + 32) != 14 )
  {
    *(_DWORD *)(v5 + 12) = 0;
    *(_DWORD *)(v5 + 4) = 0;
  }
  LOBYTE(v18) = *((_BYTE *)v4 + 48 * *(_DWORD *)v5 + 32);
  if ( (_BYTE)v18 <= 2 )
  {
    LOBYTE(v18) = v53;
    v33 = (int)((char *)v4 + 4 * v53 + 71372);
    if ( !*(_DWORD *)v33 )
      return v18;
    v34 = rand();
    v36 = v34;
    v18 = v34 / 100;
    v35 = v36 % 100;
    compile_error;//v32 = __SETO__(v35, *(_DWORD *)v33);
    v31 = v35 - *(_DWORD *)v33 < 0;
  }
  else
  {
    if ( (_BYTE)v18 > 0xBu )
    {
      if ( (_BYTE)v18 == 12 )
      {
        v18 = rand() % 6 + (unsigned __int8)byte_5D2A04[48 * *(_DWORD *)v5] + 1;
        *(_DWORD *)(v5 + 16) = v18;
        *(_BYTE *)(v5 + 25) = v18;
      }
      return v18;
    }
    LOBYTE(v18) = v53;
    compile_error;//v21 = (int)(v4 + 4 * v53 + 71324);
    if ( !*(_DWORD *)v21 )
      return v18;
    v23 = *(_DWORD *)v21;
    v22 = rand() % 100;
    if ( v22 < v23 )
      goto LABEL_128;
    LOBYTE(v18) = v53;
    if ( !*((_DWORD *)v4 + v53 + 17837) )
      return v18;
    if ( v22 < v23 )
    {
LABEL_128:
      v25 = rand() % *((_DWORD *)v4 + *((_BYTE *)v4 + 48 * *(_DWORD *)v5 + 32) + 17846);
      v26 = *(_DWORD *)v5;
      *(_DWORD *)(v5 + 4) = 0;
      v24 = *((_BYTE *)v4 + *((_BYTE *)v4 + 48 * v26 + 32) + 38409);
      for ( i = v25; v24 < i; v24 += *((_BYTE *)v4 + 20 * *(_DWORD *)(v5 + 4) + *((_BYTE *)v4 + 48 * v27 + 32) + 38409) )
      {
        v27 = *(_DWORD *)v5;
        ++*(_DWORD *)(v5 + 4);
      }
      ++*(_DWORD *)(v5 + 4);
      v29 = *((_DWORD *)v4 + 2 * v53 + 17858);
      v30 = rand();
      v28 = *(_DWORD *)(v5 + 4) - 1;
      v18 = v30 % (*((_DWORD *)v4 + 2 * v53 + 17859) - v29 + 1) + v29;
      *(_DWORD *)(v5 + 8) = v18;
      if ( v28 == 21 || v28 == 22 || v28 == 23 )
      {
        v18 >>= 1;
        *(_DWORD *)(v5 + 8) = v18;
      }
      if ( *(_DWORD *)(v5 + 8) <= 0 )
        *(_DWORD *)(v5 + 8) = 1;
      return v18;
    }
    v18 = v23 + *((_DWORD *)v4 + v53 + 17837);
    compile_error;//v32 = __SETO__(v22, v18);
    v31 = v22 - v18 < 0;
  }
  if ( !(v31 ^ v32) )
    return v18;
  memset(&v50, 0, 0xC80u);
  v37 = 0;
  v61 = 0;
  if ( *((_DWORD *)v4 + 17894) > 0 )
  {
    v51 = -16 - (_DWORD)v4;
    v58 = &v50;
    v38 = (int)((char *)v4 + 38908);
    do
    {
      switch ( v53 )
      {
        case 2:
          if ( !*(_BYTE *)v38 )
            goto LABEL_117;
          v39 = *(_BYTE *)v38 == 1;
          break;
        case 3:
          v41 = *(_BYTE *)v38;
          if ( !*(_BYTE *)v38 || v41 == 1 )
          {
LABEL_117:
            v37 += *((_BYTE *)v4 + v38 + v51 + *((_BYTE *)v4 + 48 * *(_DWORD *)v5 + 32));
            if ( *((_BYTE *)v4 + v38 + v51 + *((_BYTE *)v4 + 48 * *(_DWORD *)v5 + 32)) )
            {
              v42 = v58;
              ++v58;
              *v42 = v61;
            }
            goto LABEL_119;
          }
          v39 = v41 == 2;
          break;
        case 4:
          v40 = *(_BYTE *)v38;
          if ( *(_BYTE *)v38 == 1 || v40 == 2 )
            goto LABEL_117;
          v39 = v40 == 3;
          break;
        default:
          if ( v53 != 5 )
            goto LABEL_119;
          v39 = *(_BYTE *)v38 == 3;
          break;
      }
      if ( v39 )
        goto LABEL_117;
LABEL_119:
      ++v61;
      v38 += 28;
    }
    while ( v61 < *((_DWORD *)v4 + 17894) );
  }
  v44 = rand() % v37;
  *(_DWORD *)(v5 + 12) = v50;
  v18 = *((_BYTE *)v4 + 28 * *(v50 + 1389) + *((_BYTE *)v4 + 48 * *(_DWORD *)v5 + 32));
  v43 = v44 + 1;
  v62 = v18;
  if ( v18 < v43 )
  {
    for ( j = &v50; ; j = (int *)v59 )
    {
      v46 = *(_DWORD *)v5;
      v47 = (int)(j + 1);
      v59 = v47;
      v48 = *(_DWORD *)v47;
      *(_DWORD *)(v5 + 12) = v48;
      v18 = *((_BYTE *)v4 + 28 * (v48 + 1389) + *((_BYTE *)v4 + 48 * v46 + 32));
      v62 += v18;
      if ( v62 >= v43 )
        break;
    }
  }
  ++*(_DWORD *)(v5 + 12);
  return v18;
}