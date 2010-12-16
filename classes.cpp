
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "defs.h"
#include "RenderD3D3.h"
#include "AIL.h"
#include "clock.h"
#include "Smacker.h"
#include "Level.h"
#include "FrameTables.h"
 #include "_lod.h"
#include "data.h"




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





//----- (MM7.exe::0044E4B7) --------------------------------------------------------
void CGame_ctor(struct CGame *_this)
{
 void *v1, *v2;

 memset(_this, 0, sizeof(CGame));
 _this->dword_000000 = (int)&pCGame_scalar_dtor;
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
 _this->dword_000E34 = 0;
 _this->dword_000E38 = 0;

 _this->class01_obj = new class01;
 if (_this->class01_obj)
   class01_ctor(_this->class01_obj);

 _this->class02_obj = new class02;
 if (_this->class02_obj)
   class02_ctor(_this->class02_obj);

 _this->class03_obj = new GUICursor;
 if (_this->class03_obj)
   GUICursor_ctor(_this->class03_obj, _this->class01_obj);

 _this->class04_obj = new class04;
 if (_this->class04_obj)
   class04_ctor(_this->class04_obj);

 _this->pVis = new Vis;
 if (_this->pVis)
   Vis_ctor(_this->pVis);

 _this->class06_obj = new class06;
 if (_this->class06_obj)
   class06_ctor(_this->class06_obj);

 _this->class08_obj = new class08;
 if (_this->class08_obj)
   class08_ctor(_this->class08_obj);

 _this->class09_obj = new class09;
 if (_this->class09_obj)
   class09_ctor(_this->class09_obj);

 _this->class10_obj = new class10;
 if (_this->class10_obj)
   class10_ctor(_this->class10_obj);

 _this->class11_obj = new class11;
 if (_this->class11_obj)
   class11_ctor(_this->class11_obj, 0);

 _this->class12_obj = new class12;
 if (_this->class12_obj)
   class12_ctor(_this->class12_obj, _this->class11_obj);

 _this->class13_obj = new class13;
 if (_this->class13_obj)
   class13_ctor(_this->class13_obj);

 _this->class14_obj = new class14;
 if (_this->class14_obj)
   class14_ctor(_this->class14_obj);

 _this->pGammaController = new CGammaController;
 if (_this->pGammaController)
   CGammaController_ctor(_this->pGammaController);

 CGame_fn0(_this);
 if (dword_F79D7C != 2 || (dword_4E800C = 1, dword_F79D70 != 4))
   dword_4E800C = 0;
}

//----- (0044E7D7) --------------------------------------------------------

int CGame_scalar_deleting_destructor(struct CGame *_this, char flag)
{
  int v2; // eax@1
  
  v2 = CGame_dtor(_this);
  if ( flag & 1 )
    operator_delete(_this);

  return (int)_this;
}

//----- (0044E7F3) --------------------------------------------------------

int CGame_dtor(struct CGame *_this)
{
  int v1; // ecx@1
  unsigned int v2; // esi@1
  int v3; // ecx@3
  int v4; // ecx@5
  unsigned int v5; // edi@7
  int result = 0; // eax@8
  int v7; // eax@8
  unsigned int v8; // edi@9
  int v9; // eax@10
  int v10; // ecx@11
  int v11; // ecx@13
  int v12; // ecx@15
  unsigned int v13; // edi@17
  int v14; // eax@18
  int v15; // ecx@19
  int v16; // ecx@21
  unsigned int v17; // edi@23
  int v18; // eax@24
  unsigned int v19; // edi@25
  int v20; // eax@26
  int v21; // ecx@27

  v2 = (int)_this;
  v1 = *(_DWORD *)((DWORD)_this + 3696);
  *(_DWORD *)v2 = 5080668;
  if ( v1 )
    result = (**(int (__stdcall ***)(_DWORD))v1)(1);
  v3 = *(_DWORD *)(v2 + 3692);
  if ( v3 )
    result = (**(int (__stdcall ***)(_DWORD))v3)(1);
  v4 = *(_DWORD *)(v2 + 3688);
  if ( v4 )
    result = (**(int (__stdcall ***)(_DWORD))v4)(1);
  v5 = *(_DWORD *)(v2 + 3684);
  if ( v5 )
  {
    v7 = sub_489810(result, *(_DWORD *)(v2 + 3684));
    /*result = */operator_delete((void *)v5);
  }
  v8 = *(_DWORD *)(v2 + 3680);
  if ( v8 )
  {
    compile_error;//v9 = nullsub_1(*(_DWORD *)(v3 + 3680));
    /*result = */operator_delete((void *)v8);
  }
  v10 = *(_DWORD *)(v2 + 3676);
  if ( v10 )
    result = (**(int (__stdcall ***)(_DWORD))v10)(1);
  v11 = *(_DWORD *)(v2 + 3672);
  if ( v11 )
    result = (**(int (__stdcall ***)(_DWORD))v11)(1);
  v12 = *(_DWORD *)(v2 + 3668);
  if ( v12 )
    result = (**(int (__stdcall ***)(_DWORD))v12)(1);
  v13 = *(_DWORD *)(v2 + 3664);
  if ( v13 )
  {
    sub_4A71DC(*(_DWORD *)(v2 + 3664));
    /*result = */operator_delete((void *)v13);
  }
  v15 = *(_DWORD *)(v2 + 3660);
  if ( v15 )
    result = (**(int (__stdcall ***)(_DWORD))v15)(1);
  v16 = *(_DWORD *)(v2 + 3656);
  if ( v16 )
    result = (**(int (__stdcall ***)(_DWORD))v16)(1);
  v17 = *(_DWORD *)(v2 + 3652);
  if ( v17 )
  {
    v18 = sub_467E7A(*(_DWORD *)(v2 + 3652));
    /*result = */operator_delete((void *)v17);
  }
  v19 = *(_DWORD *)(v2 + 3648);
  if ( v19 )
  {
    v20 = sub_48AAF1(*(_DWORD *)(v2 + 3648));
    /*result = */operator_delete((void *)v19);
  }
  v21 = *(_DWORD *)(v2 + 3644);
  if ( v21 )
    result = (**(int (__stdcall ***)(_DWORD))v21)(1);
  return result;
}

//----- (0044EC23) --------------------------------------------------------
signed int Game_sub_44EC23(struct CGame *_this, struct struct8 *a2, int *a3, signed int a4)
{
  double v4; // st7@4
  signed int v6; // eax@5
  signed int result; // eax@8
  float v11; // [sp+14h] [bp+8h]@4
  float v12; // [sp+18h] [bp+Ch]@4
  float v13; // [sp+18h] [bp+Ch]@6
  float v14; // [sp+1Ch] [bp+10h]@9
  float v15; // [sp+1Ch] [bp+10h]@11

 if (_this->dword_000E24 & 0x00000002 && a2->byte_000059 == 5 && a2->ptr_000054->byte_000010[12] & 0x02)
 {
    v4 = (double)a4;
    v11 = v4;
    *a3 |= 2;
    v12 = (1.0 - _this->flt_000E28) * v4;
    if ((int)(floorf(v12 + 0.5f)) >= 0 )
    {
      v13 = (1.0 - _this->flt_000E28) * v11;
      v6 = floorf(v13 + 0.5f);
    }
    else
    {
      v6 = 0;
    }
    if ( a4 >= v6 )
    {
      v14 = (1.0 - _this->flt_000E28) * v11;
      if ((int)(floorf(v14 + 0.5f)) >= 0 )
      {
        v15 = (1.0 - _this->flt_000E28) * v11;
        result = floorf(v15 + 0.5f);
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = a4;
    }
  }
  else
  {
    result = -1;
  }
  return result;
}


//----- (0044ED0A) --------------------------------------------------------
signed int __thiscall Game_sub_44ED0A(CGame *_this, struct8 *a2, int *a3, signed int a4)
{
  double v4; // st7@3
  double v5; // ST00_8@3
  signed int v6; // eax@4
  double v7; // ST00_8@5
  signed int result; // eax@7
  double v9; // ST00_8@8
  double v10; // ST00_8@10
  float v11; // [sp+14h] [bp+8h]@3
  float v12; // [sp+18h] [bp+Ch]@3
  float v13; // [sp+18h] [bp+Ch]@5
  float v14; // [sp+1Ch] [bp+10h]@8
  float v15; // [sp+1Ch] [bp+10h]@10

  if ( *(_BYTE *)((char *)_this + 3620) & 2 && *(_BYTE *)(a2 + 44) & 2 )
  {
    v4 = (double)a4;
    v11 = v4;
    *(_DWORD *)a3 |= 2;
    v12 = (1.0 - *(float *)((char *)_this + 3624)) * v4;
    v5 = v12 + 6.755399441055744e15;
    if ( LODWORD(v5) >= 0 )
    {
      v13 = (1.0 - *(float *)((char *)_this + 3624)) * v11;
      v7 = v13 + 6.755399441055744e15;
      v6 = LODWORD(v7);
    }
    else
    {
      v6 = 0;
    }

    if ( a4 >= v6 )
    {
      v14 = (1.0 - *(float *)((char *)_this + 3624)) * v11;
      v9 = v14 + 6.755399441055744e15;
      if ( LODWORD(v9) >= 0 )
      {
        v15 = (1.0 - *(float *)((char *)_this + 3624)) * v11;
        v10 = v15 + 6.755399441055744e15;
        result = LODWORD(v10);
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = a4;
    }
  }
  else
  {
    result = -1;
  }

  return result;
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

//----- (0044F120) --------------------------------------------------------
void CGame_sub_44F120_MaybeStackStationaryLights(struct CGame *_this, int a2)
{
  int v4; // esi@2
 int i;

    v4 = (int)_this + 20;
 for (i = 0; i < _this->dword_000704; ++i)
 {
      StationaryLightsStack_AddLight(pStationaryLightsStack,
        (signed)*(float *)(v4 - 16),
        (signed)*(float *)(v4 - 12),
        (signed)*(float *)(v4 - 8),
        (signed)*(float *)(v4 + 8),
        (signed)*(float *)(v4 - 4),
        (signed)*(float *)v4,
        (signed)*(float *)(v4 + 4),
        byte_4E94D0);
      v4 += 28;
 }
}

//----- (0044F192) --------------------------------------------------------
void CGame_sub_44F192(struct CGame *_this)
{
  int v3; // esi@2
 int i;

    v3 = (int)_this->array_000718;
  for (i = 0; i < _this->dword_000E08; ++i)
  {
      class36_sub_43B6EF(&class36_global0,
        (signed)*(float *)(v3 - 16),
        (signed)*(float *)(v3 - 12),
        (signed)*(float *)(v3 - 8),
        (signed)*(float *)(v3 + 8),
        (signed)*(float *)(v3 - 4),
        (signed)*(float *)v3,
        (signed)*(float *)(v3 + 4));
      v3 += 28;
  }
}

//----- (0044EA17) --------------------------------------------------------
bool Game_InitializeGammaController(struct CGame *_this)
{
 if (dword_F79D7C != 2 || dword_F79D70 != 4)
   CGammaController_InitializeFromSurface(_this->pGammaController, pD3DRenderer->pdds4_FrontBuffer);

 _this->dword_000E1C = 1;
 _this->qword_000E2C = cClock1.clock_fn2();
 return true;
}

//----- (0040E2F6) --------------------------------------------------------
void CGame_stru0_sub_40E2F6(struct CGame_stru0 *_this, char a2)
{
  int v2; // esi@1
  int v3; // eax@2
  int v4; // eax@3

  v2 = (int)_this;
  if ( a2 )
  {
    v3 = (int)_this->ptr_000004;
    if ( v3 )
    {
      v4 = v3 - 1;
      if ( *(_BYTE *)v4 && *(_BYTE *)v4 != -1 )
        --*(_BYTE *)v4;
      else
        operator_delete((void *)v4);
    }
  }
  _this->ptr_000004 = 0;
  _this->dword_000008 = 0;
  _this->dword_00000C = 0;
}

//----- (0044EA5E) --------------------------------------------------------
bool Game_Pick(struct CGame *_this, float a2, unsigned int uMouseX, unsigned int uMouseY, bool bOutline, int a6, int a7)
{
  char v10; // [sp-4h] [bp-24h]@5
  int v11; // [sp+0h] [bp-20h]@5
  char *v16; // [sp+18h] [bp-8h]@5
  int v17; // [sp+1Fh] [bp-1h]@5

  if (!dword_4E28F8 && pD3DRenderer->pRenderD3D3)
  {
    if ( !_this->pVis)
    {
      v16 = &v10;
      Game_sub_40E2C8(&v10, "The 'Vis' object pointer has not been instatiated, but CGame::Pick() is trying to call through it.",(int)&v17);
      sub_466D09(&v16, *(int *)&v10, v11, 0, 0, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Game.cpp", __LINE__);
    }
    if (uMouseX >= pOldViewport->uScreenX && uMouseX <= pOldViewport->uScreenZ &&
        uMouseY >= pOldViewport->uScreenY && uMouseY <= pOldViewport->uScreenW)
    {
            Vis_sub_4C0646(_this->pVis, a2, uMouseX, uMouseY, a6, a7);
            if (bOutline)
              CGame_outline_selection((int)_this);
    }
    return true;
  }
  else return false;
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
  memset(_this->array_000000, 0, 500 * sizeof(struct class02_stru0));

  class02_fn0(_this);
  return _this;
}

//----- (MM7.exe::0048AAF6) --------------------------------------------------------
void *class02_fn0(struct class02 *_this)
{
 _this->dword_00E424 = 500;
 _this->dword_00E428 = 0;
 _this->dword_00E42C = 0;
 return memset(_this->array_000000, 0, 500 * sizeof(struct class02_stru0));
}

//----- (MM7.exe::00467E4E) --------------------------------------------------------
struct GUICursor *GUICursor_ctor(struct GUICursor *_this, struct class01 *class01_obj)
{
 _this->uCursorTextureID = 0;
 _this->dword_000028 = 0;
 _this->hWnd = 0;
 _this->ptr_000030 = 0;
 _this->dword_000034 = 0;
 _this->ptr_000038 = 0;
 _this->ptr_00003C = 0;
 _this->ptr_000090 = 0;
 _this->class01_obj = class01_obj;
 return _this;
}

//----- (MM7.exe::0046A080) --------------------------------------------------------
int GUICursor_fn1(struct GUICursor *_this, int a2)
{
 return _this->dword_000004 = a2;
}

//----- (MM7.exe::00469C39) --------------------------------------------------------
POINT *GUICursor_GetMousePos(struct GUICursor *_this, POINT *pOut)
{
 int *v3; // edx@1
 int v4; // ecx@2
 int v5; // edx@3

 v3 = (int *)dword_720010;
 if (dword_720010)
 {
  pOut->x = v3[6];
  pOut->y = v3[7];
 }
 else
 {
  GetCursorPos(pOut);
  ScreenToClient(pAppWindow->GetAPIHandle(), pOut);
 }
 return pOut;
}

//----- (00469860) --------------------------------------------------------
void GUICursor_GetMouseClickPos(struct GUICursor *_this, int *pX, int *pY)
{
  if (dword_720010)
  {
    *pX = *(_DWORD *)(dword_720010 + 24);
    *pY = *(_DWORD *)(dword_720010 + 28);
  }
  else
  {
    *pX = _this->uMouseClickX;
    *pY = _this->uMouseClickY;
  }
}

//----- (0046A08A) --------------------------------------------------------
void GUICursor_OnMouseLeftButton(struct GUICursor *_this, int x, int y)
{
 _this->uMouseClickX = x;
 _this->uMouseClickY = y;
}

//----- (00469C65) --------------------------------------------------------
void GUICursor_sub_469C65(struct GUICursor *_this, HWND hwnd)
{
 _this->dword_000004 = 0;

 _this->dword_000010 = 1;

 _this->hWnd = hwnd;
 _this->ptr_000030 = 0;
 _this->dword_000034 = 0;
 _this->ptr_000038 = 0;

 _this->dword_0000C4 = 0;
 _this->dword_0000C8 = 0;

 _this->uMouseClickY = 0;

 GUICursor_SetCursorBitmap(_this, "MICON3");
 GUICursor_SetCursorBitmap(_this, "MICON2");
 GUICursor_SetCursorBitmap(_this, "MICON1");
}

//----- (00469903) --------------------------------------------------------
void GUICursor_SetCursorBitmap(struct GUICursor *_this, const char *pSource)
{
 HCURSOR hCursor;
  int v9; // eax@21
  struct tagPOINT Point; // [sp+14h] [bp-8h]@20

 if (!_this->dword_000010 || !pSource)
   return;

 if (_strcmpi("MICON2", pSource))
    pGame->dword_000E24 &= 0xFFFFFFEF;
 else pGame->dword_000E24 |= 0x10;

 if (_strcmpi((char *)_this->array_0000F5, pSource))
   strcpy((char *)_this->array_0000F5, pSource);

 GUICursor_sub_469BA3(_this);

 if (_strnicmp(pSource, "MICON1", 5))
 {
#ifdef OLD_CODE
  v9 = LODFile_Icons_LOD.LODFile_LoadTexture(pSource, 2);
#else
  wchar_t pTextureNameW[256];
  wsprintfW(pTextureNameW, L"%S", pSource);

  v9 = LODFile_Icons_LOD.LODFile_LoadTexture_New(pTextureNameW);
#endif
  _this->uCursorTextureID = v9;
  _this->dword_000028 = v9;
  GUICursor_sub_469BE6(_this);

  _this->dword_00000C = 0;
  _this->dword_000014[0] = 1;
  _this->dword_000004 = 1;
  if (!bTextureLoading)
  {
   cTexture_Free((cTexture *)(*(_DWORD *)(_this + 36) != -1 ? 72 * *(_DWORD *)(_this + 36) + 7145548 : 0));
   LODFile_Icons_LOD.LODFile_sub_40F9C5();
  }
  return;
 }

 _this->dword_000004 = 0;
 _this->dword_00000C = 1;
 if (!strcmp(pSource, "MICON1"))
 {
  hCursor = LoadCursorA(GetModuleHandleW(0), "Arrow");
  SetClassLongPtrW(_this->hWnd, GCL_HCURSOR, (LONG_PTR)(hCursor));
  if (dword_720010)
  {
   sub_46B342(dword_720010, 0.0, 0.0);
   sub_46AE97((void *)dword_720010, (void *)pSource);
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
  SetClassLongPtrW(_this->hWnd, GCL_HCURSOR, (LONG_PTR)(hCursor));
  if (dword_720010)
  {
   sub_46B342(dword_720010, 14.0, 14.0);
   sub_46AE97((void *)dword_720010, (void *)pSource);
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
  SetClassLongPtrW(_this->hWnd, GCL_HCURSOR, (LONG_PTR)(hCursor));

  if (dword_720010)
    sub_46AE97((void *)dword_720010, (void *)pSource);
  else
  {
   GetCursorPos(&Point);
   SetCursorPos(Point.x, Point.y);
  }
 }
}

//----- (004698A6) --------------------------------------------------------
void GUICursor_ResetDefaultCursorAfterItemDragging(struct GUICursor *_this)
{
 ItemGen_Reset(&pParty_global->pickedItem);
 if (_strcmpi((char *)_this->array_0000F5, "MICON2"))
   GUICursor_SetCursorBitmap(_this, "MICON1");
}

//----- (00469BA3) --------------------------------------------------------
int GUICursor_sub_469BA3(struct GUICursor *_this)
{
 _this->dword_000004 = 0;

 if (_this->ptr_000030)
 {
  free(_this->ptr_000030);
  _this->ptr_000030 = 0;
 }

 if (_this->ptr_000038)
 {
  free(_this->ptr_000038);
  _this->ptr_000038 = 0;
 }

 if (_this->ptr_000090)
 {
  free(_this->ptr_000090);
  _this->ptr_000090 = 0;
 }

 return 0;
}






//----- (MM7.exe::0045BB06) --------------------------------------------------------
void class04_ctor(struct class04 *_this)
{
  int v1; // eax@1
  signed int v2; // ecx@1

 _eh_vector_constructor_iterator_((int)_this->std__vector_000004, sizeof(struct class04_stru0), 512, (void (__fastcall *)(void *))class04_stru0_ctor, (void (__fastcall *)(void *))class04_stru0_detor);
 _this->std__vector_000004_size = 0;

 _eh_vector_constructor_iterator_((int)_this->std__vector_183808, sizeof(struct class04_stru0), 768, (void (__fastcall *)(void *))class04_stru0_ctor, (void (__fastcall *)(void *))class04_stru0_detor);
 _this->std__vector_183808_size = 0;

 
  runtime_warning("struct shape and place is unknown, access to a random member");
 //v1 = (int)((char *)_this + 0x0F2314 + 4);  //::000808 inside[321]
  v1 = (int)((char *)&_this->std__vector_000004[321] + 0x808);
 v2 = 256;
 do
 {
   *(float *)v1 = 0.0;
   v1 += 48;
 }
 while (--v2);

 _this->dword_000000 = 0x4D86E0;
}

//----- (MM7.exe::004C05A2) --------------------------------------------------------
void Vis_detor(struct Vis *_this, unsigned int a2)
{
 Vis_sub_4C05BE((int)_this);
 if (a2 & 1)
   operator_delete(_this);
}

//----- (MM7.exe::004C04AF) --------------------------------------------------------
void Vis_ctor(struct Vis *_this)
{
 struct Vis_stru0 local_0C;
 //float v3; // [sp+Ch] [bp-60h]@1
 //float v4; // [sp+10h] [bp-5Ch]@1
 //float v5; // [sp+14h] [bp-58h]@1
 //float v6; // [sp+38h] [bp-34h]@1

 struct Vis_stru0 local_3C;
 //float v7; // [sp+3Ch] [bp-30h]@1
 //float v8; // [sp+40h] [bp-2Ch]@1
 //float v9; // [sp+44h] [bp-28h]@1
 //float v10; // [sp+68h] [bp-4h]@1
 
 _this->detor_ptr = Vis_detor;

 class25_fn0(&_this->class25_obj);

 local_3C.flt_000000 = 65536.0;
 local_3C.flt_000004 = 0.0;
 local_3C.flt_000008 = 0.0;
 local_3C.flt_00002C = 0.0;
 memcpy(&_this->struct_00200C, &local_3C, sizeof(struct Vis_stru0));
 
 local_0C.flt_000000 = 0.0;
 local_0C.flt_000004 = 65536.0;
 local_0C.flt_000008 = 0.0;
 local_0C.flt_00002C = 0.0;
 memcpy(&_this->struct_00203C, &local_0C, sizeof(struct Vis_stru0));
 
 local_0C.flt_000000 = 65536.0;
 local_0C.flt_000004 = 0.0;
 local_0C.flt_000008 = 0.0;
 local_0C.flt_00002C = 0.0;
 memcpy(&_this->struct_00206C, &local_0C, sizeof(struct Vis_stru0));
 
 local_3C.flt_000000 = 0.0;
 local_3C.flt_000004 = 65536.0;
 local_3C.flt_000008 = 0.0;
 local_3C.flt_00002C = 0.0;
 memcpy(&_this->struct_00209C, &local_3C, sizeof(struct Vis_stru0));

 _this->dword_0020CC = 512;
}

//----- (MM7.exe::004A7155) --------------------------------------------------------
void *class06_ctor(struct class06 *_this)
{
 _this->dword_000204 = 0;
 _this->array_000208[0].word_000000 = 0;
 _this->array_000208[1].word_000000 = 0;
 _this->array_000208[2].word_000000 = 0;
 _this->array_000208[3].word_000000 = 0;
 _this->dword_0005C8 = 0;
 _this->dword_0005D8 = 0;

 _this->class07_obj = new class07;
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
 int v7; // eax@2

 _this->uNumVec4InArray1 = 66;
 _this->pFloatArray1 = new float[66 * 4];
 _this->uNumVec3InArray2 = 128;
 _this->pFloatArray2 = new float[128 * 3];

 v7 = 0;
 for (unsigned int i = 0; i < _this->uNumVec4InArray1; ++i)
 {
  _this->pFloatArray1[v7 + 0] = array_4EB8B8[i].flt_000000;
  _this->pFloatArray1[v7 + 1] = array_4EB8B8[i].flt_000004;
  _this->pFloatArray1[v7 + 2] = array_4EB8B8[i].flt_000008;
  _this->pFloatArray1[v7 + 3] = w;

  v7 += 4;
 }

 return memcpy(_this->pFloatArray2, array_4EBBD0, 12 * _this->uNumVec3InArray2);
}


void class08_detor(struct class08 *_this, unsigned int a2)
{
 sub_4363C6(_this);
 if (a2 & 1)
   operator_delete(_this);
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

  v3 = (int)_this;
  class26_ctor(&_this->class26_obj1);
  class26_ctor(&_this->class26_obj2);
  class26_ctor(&_this->class26_obj3);
  _eh_vector_constructor_iterator_((int)_this->std__vector_000034, sizeof(struct class26_placeholder), 6, (void (__fastcall *)(void *))class26_placeholder_ctor, (void (__fastcall *)(void *))class26_placeholder_detor);

  _this->flt_0000DC = dword_51B6E8;
  _this->flt_0000E0 = dword_51B6EC;
  _this->flt_0000E4 = dword_51B6F0;
  _this->flt_000108 = 0;

  _this->flt_00010C = dword_51B6E8 + 300;
  _this->flt_000110 = dword_51B6EC;
  _this->flt_000114 = dword_51B6F0;
  _this->flt_000138 = 0;

  _this->flt_000168 = 0;
  _this->flt_000198 = 0;
  _this->flt_0001C8 = 0;
  _this->flt_0001F8 = 0;
  _this->flt_000228 = 0;
  _this->flt_000258 = 0;
  _this->flt_000288 = 0;

  _this->flt_0002B8 = 0;
  _this->flt_0002BC = 0;
  _this->flt_0002C0 = 0;
  _this->flt_0002C4 = 0;

  _this->flt_0002E8 = 0;
  _this->flt_0002EC = 0;
  _this->flt_0002F0 = 0;
  _this->flt_0002F4 = 0;

  _this->flt_000318 = 0;
  _this->flt_00031C = 0;
  _this->flt_000320 = 0;
  _this->flt_000324 = 0;

  _this->flt_000348 = 0;
  _this->flt_00034C = 0;
  _this->flt_000350 = 0;
  _this->flt_000354 = 0;

  _this->flt_000378 = 0;

  v2 = 16384;
  v1 = (float *)_this->array_00037C;
  do
  {
   *(int *)(v1) = 0;
   v1[12] = 0;
   v1 += 14;
  }
  while (--v2);

  _this->dword_0E037C = 0;

  v10 = (int *)_this->array_0E0380;
  v13 = 256;
  do
  {
   v10[0] = 0;
   v10 += 772;
  }
  while (v13-- != 1);

 _this->detor_ptr = class08_detor;
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
void *class11_fn0(class11 *_this, int a2)
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
    result = (int)_this;
    *(_DWORD *)((char *)_this + 172) = 1;
  }
  else
  {
    if ( v13 == 4 )
    {
      result = (int)_this;
      *(_DWORD *)((char *)_this + 172) = 2;
    }
    else
    {
      if ( v14 )
      {
        *(_DWORD *)((char *)_this + 172) = 2;
        result = (int)class11_fn1(_this, a2);
      }
      else
      {
        result = (int)_this;
        *(_DWORD *)((char *)_this + 172) = 0;
      }
    }
  }
  return (void *)result;
}

//----- (MM7.exe::004895B7) --------------------------------------------------------
struct class12 *class12_ctor(struct class12 *_this, struct class11 *class11_obj)
{
 _this->pMemberFn = (int (__cdecl *)(class_unk *))sub_4898E6;
 _this->dword_000044 = 1090519040;
 _this->dword_000048 = 0;
 _this->dword_00004C = 1174405120;
 _this->dword_000050 = 0;
 _this->dword_000054 = 869711765;
 _this->dword_000058 = 0;

 for (unsigned int i = 0; i < 12; ++i)
 {
  _this->class16_objs[i] = new class16;
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







//----- (MM7.exe::004C0585) --------------------------------------------------------
void class25_detor(struct class25 *_this , unsigned int a2)
{
 _this->detor_ptr = class25_detor;
 if (a2 & 1)
   operator_delete(_this);
}


//----- (MM7.exe::004C055C) --------------------------------------------------------
__int64 class25_fn0(struct class25 *_this)
{
  __int64 result; // qax@1
  signed int v2; // ecx@1

  LODWORD(result) = (int)_this;
  v2 = 512;
  HIDWORD(result) = (int)(char *)(_this) + 4;
  do
  {
    *(DWORD *)(HIDWORD(result)) = 0;
    *(_QWORD *)(HIDWORD(result) + 4) = 4294967295i64;
    result += 51539607552i64;
  }
  while ( --v2 );
  _this->detor_ptr = class25_detor;
  _this->dword_002004 = 0;
  return result;
}

//----- (MM7.exe::004D89FC) --------------------------------------------------------
void class26_detor(struct class26 *_this, unsigned int a2)
{
 _this->detor_ptr = class26_detor;
 if (a2 & 1)
   operator_delete(_this);
}

//----- (MM7.exe::004C0376) --------------------------------------------------------
void class26_ctor(struct class26 *_this)
{
 _this->detor_ptr = class26_detor;
}

//----- (MM7.exe::004C0262) --------------------------------------------------------
void Viewport_fn0(struct OldViewport *_this, int a2, int a3, int a4, int a5)
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
  _this->uScreenX = v5;
  _this->uScreenY = v8;
  _this->uScreenZ = v6;
  _this->uScreenW = v7;
  _this->dword_000020 = v6 - v5 + 1;
  _this->dword_000028 = (v6 + v5) >> 1;
  if (!pD3DRenderer->pRenderD3D3)
  {
    v10 = v7 - v8 + 1;
    _this->dword_000024 = v10;
    _this->dword_00002C = _this->uScreenW - ((unsigned __int64)(_this->dword_000030 * v10) >> 16);
  }
  else
  {
    _this->dword_000024 = v7 - v8 + 1;
    _this->dword_00002C = (v7 + v8) >> 1;
  }
 Viewport_SetGameViewport(_this, _this->uScreenX, _this->uScreenY, _this->uScreenZ, _this->uScreenW);
}

//----- (MM7.exe::004C0312) --------------------------------------------------------
void Viewport_SetGameViewport(struct OldViewport *_this, unsigned int uX, unsigned int uY, unsigned int uZ, unsigned int uW)
{
 _this->uGameX = uX;
 if (_this->uGameX < _this->uScreenX)
   _this->uGameX = _this->uScreenX;

 _this->uGameY = uY;
 if (_this->uGameY < _this->uScreenY)
   _this->uGameY = _this->uScreenY;

 _this->uGameZ = uZ;
 if (_this->uGameZ > _this->uScreenZ)
   _this->uGameZ = _this->uScreenZ;

 _this->uGameW = uW;
 if (_this->uGameW > _this->uScreenW)
   _this->uGameW = _this->uScreenW;
}

//----- (MM7.exe::004C02F8) --------------------------------------------------------
void Viewport_fn2(struct OldViewport *_this, int a2)
{
 _this->dword_000030 = a2;
 Viewport_fn0(_this, _this->uScreenX, _this->uScreenY, _this->uScreenZ, _this->uScreenW);
}







//----- (0048A8F5) --------------------------------------------------------
void class35_SetColorChannelInfo(struct class35 *_this, unsigned int uNumRBits, unsigned int uNumGBits, unsigned int uNumBBits)
{
 /*_this->uNumTargetRBits = uNumRBits;
 _this->uNumTargetGBits = uNumGBits;
 _this->uNumTargetBBits = uNumBBits;

 _this->uTargetRMask = MakeColorMaskFromBitDepth(uNumRBits) << (uNumGBits + uNumBBits);
 _this->uTargetGMask = MakeColorMaskFromBitDepth(uNumGBits) << (uNumBBits);
 _this->uTargetBMask = MakeColorMaskFromBitDepth(uNumBBits);*/

 //maintain original setup data so the code can generate correct colors. covert to R8G8B8 on the fly during render
 _this->uNumTargetRBits = 5;
 _this->uNumTargetGBits = 6;
 _this->uNumTargetBBits = 5;

 _this->uTargetRMask = 0xF800;
 _this->uTargetGMask = 0x07E0;
 _this->uTargetBMask = 0x001F;
}

//----- (0048A614) --------------------------------------------------------
int class35_sub_48A614(struct class35 *_this)
{
 int result; // eax@1
 int i;

 result = class35_sub_489BE0(_this, 0);
 for (i = 1; i < 50; ++i)
 {
  if (_this->array_267A00[i])
    result = class35_sub_489BE0(_this, i);
 }

 return result;
}

//----- (0048A300) -----
void class35_ctor(struct class35 *_this) // missing constructor from rtl
{
 int i;

 for (i = 0; i < 256; ++i)
 {
  _this->pBaseColors[0][i * 3 + 0] = i;
  _this->pBaseColors[0][i * 3 + 1] = i;
  _this->pBaseColors[0][i * 3 + 2] = i;
 }

 class35_sub_489BE0(_this, 0);

 memset(_this->array_267A00, 0, 50 * sizeof(int));
}


//----- (00489BE0) --------------------------------------------------------
int class35_sub_489BE0(struct class35 *_this, unsigned int idx)
{
  float v5; // ST08_4@5
  float v6; // ST04_4@5
  float v7; // ST00_4@5
  int v9; // edx@8
  int v10; // ST0C_4@8
  int v11; // ecx@8
  double v21; // st5@11
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

  //local structs
  int v74[1 + 8*array_size_unknown]; // [sp+C1Ch] [bp-38h]@43
  char v75[4 + 8*array_size_unknown]; // [sp+C20h] [bp-34h]@43
  char v76[8 + 4*array_size_unknown]; // [sp+C24h] [bp-30h]@43
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

 v2 = _this->pBaseColors[idx];
 if (_this->byte_267AD3 || _this->byte_267AD4 || _this->byte_267AD5)
 {
  for (i = 0; i < 256; ++i)
  {
   v5 = (double)(v2[i * 3 + 2] + _this->byte_267AD5) / 510.0;
   v6 = (double)(v2[i * 3 + 1] + _this->byte_267AD4) / 510.0;
   v7 = (double)(v2[i * 3 + 0] + _this->byte_267AD3) / 510.0;
   sub_48A7AA(&local_0[i].y, &local_0[i].x, v7, v6, v5, &local_0[i].z);
   v2 += 3;
  }
 }
 else
 {
  for (i = 0; i < 256; ++i)
  {
   v5 = (double)v2[i * 3 + 2] / 255.0;
   v6 = (double)v2[i * 3 + 1] / 255.0;
   v7 = (double)v2[i * 3 + 0] / 255.0;
   sub_48A7AA(&local_0[i].y, &local_0[i].x, v7, v6, v5, &local_0[i].z);
   v2 += 3;
  }
 }


 v81 = _this->pColorPalette0[idx];
 for (i = 0; i < 32; ++i)
 {
  scale = 1.0 - (double)i / 31.0;

  for (j = 0; j < 256; ++j)
  {
   v21 = local_0[j].z * scale;

   if (v21 < 0)
     v21 = 0.0;
   sub_48A643((int)&v85, (int)&v84, (int)&v86, local_0[j].y, local_0[j].x, v21);

   if (_this->uNumTargetGBits == 6)
   {
    v85 *= 31.0;
    v84 *= 62.0;
    v86 *= 31.0;
   }
   else
   {
    v85 *= 31.0;
    v84 *= 31.0;
    v86 *= 31.0;
   }

   v24 = (signed __int64)v86 | ((unsigned __int16)(signed __int64)v84 << _this->uNumTargetBBits) | (unsigned __int16)((unsigned __int16)(signed __int64)v85 << (_this->uNumTargetBBits + _this->uNumTargetGBits));
   v81[i * 256 + j] = v24;
  }
 }



 v81 = _this->pColorPalette2[idx];
 for (i = 0; i < 32; ++i)
 {
  scale = memory_4D8410.d1_0 - (double)i * (1.0 / 31.0);

  for (j = 0; j < 256; ++j)
  {
   v28 = local_0[j].z * scale;

   if (v28 < *(double *)(byte_4D8410 + 176))
     v28 = 0.0;
   sub_48A643((int)&v85, (int)&v84, (int)&v86, 1.0, 1.0, v28);

   v29 = _this->uNumTargetGBits;
   if ( v29 == 6 )
   {
    v85 *= 31.0;
    v84 *= 62.0;
    v86 *= 31.0;
   }
   else
   {
    v85 *= 31.0;
    v84 *= 31.0;
    v86 *= 31.0;
   }

   v24 = (signed __int64)*(float *)&v86 | ((unsigned __int16)(signed __int64)v84 << _this->uNumTargetBBits) | (unsigned __int16)((unsigned __int16)(signed __int64)v85 << (_this->uNumTargetBBits + v29));
   v81[i * 256 + j] = v24;
  }
 }


 v81 = _this->pColorPalette3[idx];
 for (i = 0; i < 256; ++i)
 {
  v36 = (local_0[i].z - 0.80000000000000004) * 0.83870967741935487 + 0.80000000000000004;
  if (v36 < 0.0)
    v36 = 0.0;

  v39 = local_0[i].x * 0.70343392299687835;
  sub_48A643((int)&v85, (int)&v84, (int)&v86, local_0[i].y, v39, v36);

  if (_this->uNumTargetGBits == 6)
  {
   v85 *= 31.0;
   v84 *= 62.0;
   v86 *= 31.0;
  }
  else
  {
   v85 *= 31.0;
   v84 *= 31.0;
   v86 *= 31.0;
  }

  v44 = (signed __int64)((v85 + v84 + v86) * 0.33333333333333331 * 8.0);
  v40 = (_DWORD)v44 >> (8 - (unsigned __int8)_this->uNumTargetRBits);
  v45 = 8 - _this->uNumTargetGBits;
  v42 = _this->uNumTargetBBits;
  v43 = (_DWORD)v44 >> v45;
  v41 = _this->uNumTargetRBits;
  v87 = (_DWORD)v44 >> (8 - v42);
  if ( v40 > (1 << v41) - 1 )
    v40 = (1 << v41) - 1;
  v46 = _this->uNumTargetGBits;
  if ( v43 > (1 << v46) - 1 )
    v43 = (1 << v46) - 1;
  if ( v87 > (1 << v42) - 1 )
    v87 = (1 << v42) - 1;
  v48 = v40 << (v42 + (unsigned char)_this->uNumTargetGBits);

  v81[i] = v87 | ((_WORD)v43 << v42) | (_WORD)v48;
 }


 if (_this->byte_267AD0 || _this->byte_267AD1 || _this->byte_267AD2 != _this->byte_267AD0)
 {
  v88 = _this->byte_267AD1;
  v53 = _this->byte_267AD2;
  v78 = (double)_this->byte_267AD0 * (1.0 / 255.0);
  v79 = (double)v88 * (1.0 / 255.0);
  v83 = (double)v53 * (1.0 / 255.0);
  sub_48A7AA((float *)v76, (float *)v75, v78, v79, v83, (float *)v74);
 }


 v81 = _this->pColorPalette1[idx];
 for (i = 0; i < 32; ++i)
 {
  for (j = 0; j < 256; ++j)
  {
   v55 = local_0[j].x;

   if ( v55 < 0.0 )
     v55 = 0.0;

   sub_48A643((int)&v85, (int)&v84, (int)&v86, local_0[j].y, v55, local_0[j].z);
   if (_this->uNumTargetGBits == 6 )
   {
    v85 *= 31.0;
    v84 *= 62.0;
    v86 *= 31.0;
   }
   else
   {
    v85 *= 31.0;
    v84 *= 31.0;
    v86 *= 31.0;
   }

   if (_this->byte_267AD0 || _this->byte_267AD1 || _this->byte_267AD2)
   {
    v61 = (double)i * (1.0 / 31.0);
    v60 = (signed __int64)((double)(1 << _this->uNumTargetRBits) * v78 * v61 + v85 * (1.0 - v61));
    v59 = (signed __int64)((double)(1 << _this->uNumTargetGBits) * v79 * v61 + v84 * (1.0 - v61));
    v58 = (signed __int64)((double)(1 << _this->uNumTargetBBits) * v83 * v61 + v86 * (1.0 - v61));
   }
   else
   {
    v60 = (signed __int64)v85;
    v59 = (signed __int64)v84;
    v58 = (signed __int64)v86;
   }

   v62 = _this->uNumTargetRBits;
   v90 = v58;
   if ( v60 > (1 << v62) - 1 )
     v60 = (1 << v62) - 1;

   v63 = _this->uNumTargetGBits;
   if ( v59 > (1 << v63) - 1 )
     v59 = (1 << v63) - 1;

   v64 = _this->uNumTargetBBits;
   v65 = _this->uNumTargetBBits;
   if ( v90 > (1 << v65) - 1 )
     v90 = (1 << v65) - 1;

   v66 = _this->uNumTargetGBits;
   v68 = v64 + v66;

   v81[i * 256 + j] = v90 | ((_WORD)v59 << v64) | (unsigned __int16)((_WORD)v60 << v68);
  }
 }
 return rand() % 0xFFFF;
}








//----- (0043B688) --------------------------------------------------------
void class36_ctor(struct class36 *_this)
{
 _this->dword_000000 = 0x4D8600;
 _eh_vector_constructor_iterator_((int)_this->std__vector_000004, 40, 64, (void (__fastcall *)(void *))sub_43B538, sub_43B569);
 _this->std__vector_000004_size = 0;

 _this->dword_000A08 = 0;
}






__declspec(naked) void __fastcall class37_loc_43F2A9(char *_this)
{
 __asm
 {
loc_43F2A9:                             // DATA XREF: .text:0043F266o
                                        // sub_43F282+3o
         push    offset class26_placeholder_detor
         push    4
         add     ecx, 7ACh
         push    18h
         push    ecx
         call    _eh_vector_destructor_iterator_
         retn
 }
}

__declspec(naked) void __fastcall class37_loc_43F2BF(char *_this)
{
 __asm
 {
loc_43F2BF:                             // DATA XREF: sub_43F282+8o
         push    esi
         mov     esi, ecx
         push    offset class26_placeholder_detor
         push    offset class26_placeholder_ctor
         push    4
         lea     eax, [esi+7ACh]
         push    18h
         push    eax
         call    _eh_vector_constructor_iterator_
         push    4
         lea     eax, [esi+838h]
         pop     ecx

loc_43F2E5:                             // CODE XREF: sub_43F282+6Bj
         fldz
         fstp    dword ptr [eax]
         add     eax, 30h
         dec     ecx
         jnz     short loc_43F2E5
         mov     eax, esi
         pop     esi
         retn
 }
}
//----- (0043F282) --------------------------------------------------------
void *class37_ctor(struct class37 *_this)
{
 _eh_vector_constructor_iterator_((int)_this->vector_000FA8, 2252, 150, (void (__fastcall *)(void *))class37_loc_43F2BF, (void (__fastcall *)(void *))class37_loc_43F2A9);
 return 0;
}





//----- (00456D84) --------------------------------------------------------
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
  int v39; // esi@199
  char *v41; // eax@200
  char v42; // dl@201
  int v43; // ecx@201
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
  signed int v64; // edi@348
  char v65; // dl@349
  int v66; // ecx@349
  int v67; // esi@353
  int v68; // [sp+Ch] [bp-18h]@1
  signed int v69; // [sp+Ch] [bp-18h]@22
  signed int v70; // [sp+Ch] [bp-18h]@25
  signed int v77; // [sp+Ch] [bp-18h]@311
  signed int v78; // [sp+Ch] [bp-18h]@347
  int v79; // [sp+10h] [bp-14h]@7
  signed int v80; // [sp+10h] [bp-14h]@21
  int v81; // [sp+10h] [bp-14h]@45
  int v82; // [sp+10h] [bp-14h]@77
  int v83; // [sp+10h] [bp-14h]@205
  int v85; // [sp+10h] [bp-14h]@239
  signed int v86; // [sp+14h] [bp-10h]@1
  int v88; // [sp+14h] [bp-10h]@175
  signed int v90; // [sp+18h] [bp-Ch]@67
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

  pMapStats = new CMapStats;
  CMapStats_ctor(pMapStats);
  CMapStats_Initialize(pMapStats);

  pMonsterStats = new CMonsterStats;
  CMonsterStats_ctor(pMonsterStats);
  CMonsterStats_Initialize(pMonsterStats);
  CMonsterStats_LoadMonsterPlacements(pMonsterStats);

  pSpellStats = new CSpellStats;
  CSpellStats_ctor(pSpellStats);
  CSpellStats_Initialize(pSpellStats);

  class40_LoadPotionsTable(_this);
  class40_LoadPotionNotes(_this);

  pClass48 = new class48;
  class48_ctor(pClass48);
  class48_Initialize(pClass48);

  pStorylineText = new StorylineText;
  StorylineText_Initialize(pStorylineText);

  _this->pStdItemsTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "stditems.txt", 0);

  strtok((char *)_this->pStdItemsTXT_Raw, "\r");
  strtok(0, "\r");
  strtok(0, "\r");
  strtok(0, "\r");
  v68 = (int)_this->pEnchantments;
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
           _this->pEnchantments[i].pName = (unsigned char *)RemoveQuote(v3);
          }
          else
          {
            if ( v104 > 1 )
              _this->pEnchantments[i].array_000008[v104 - 2] = atoi(v3);
          }
        }
        else
        {
         _this->pEnchantments[i].pParam = (unsigned char *)RemoveQuote(v3);
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



  _this->pSpcItemsTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "spcitems.txt", 0);
  strtok((char *)_this->pSpcItemsTXT_Raw, "\r");
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
           _this->pSpecialEnchantments[i].pName = (unsigned char *)RemoveQuote((char *)v17);
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
         _this->pSpecialEnchantments[i].pParam = (unsigned char *)RemoveQuote((char *)v17);
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


  _this->pItemsTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw ("items.txt", 0);
  strtok((char *)_this->pItemsTXT_Raw, "\r");
  v28 = 0;
  strtok(0, "\r");
  _this->uNumItems = 0;
  memset(_this->pItems, 0, 800 * sizeof(struct Item));
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
          case 1: _this->pItems[v28 - 1].pIconName = (unsigned char *)RemoveQuote(v30); break;
          case 2: _this->pItems[v28 - 1].pName = (unsigned char *)RemoveQuote(v30);     break;
          case 3: _this->pItems[v28 - 1].uValue = atoi(v30);          break;

          case 4:
            if (!strcmpi(v30, "weapon") || !strcmpi(v30, "weapon1or2"))
              _this->pItems[v28 - 1].uEquipType = 0;
            else if (!strcmpi(v30, "weapon2"))
              _this->pItems[v28 - 1].uEquipType = 1;
            else if (!strcmpi(v30, "missile") || !strcmpi(v30, "bow"))
              _this->pItems[v28 - 1].uEquipType = 2;
            else if (!strcmpi(v30, "armor"))
              _this->pItems[v28 - 1].uEquipType = 3;
            else if (!strcmpi(v30, "shield"))
              _this->pItems[v28 - 1].uEquipType = 4;
            else if (!strcmpi(v30, "helm"))
              _this->pItems[v28 - 1].uEquipType = 5;
            else if (!strcmpi(v30, "belt"))
              _this->pItems[v28 - 1].uEquipType = 6;
            else if (!strcmpi(v30, "cloak"))
              _this->pItems[v28 - 1].uEquipType = 7;
            else if (!strcmpi(v30, "gauntlets"))
              _this->pItems[v28 - 1].uEquipType = 8;
            else if (!strcmpi(v30, "boots"))
              _this->pItems[v28 - 1].uEquipType = 9;
            else if (!strcmpi(v30, "ring"))
              _this->pItems[v28 - 1].uEquipType = 10;
            else if (!strcmpi(v30, "amulet"))
              _this->pItems[v28 - 1].uEquipType = 11;
            else if (!strcmpi(v30, "weaponw"))
              _this->pItems[v28 - 1].uEquipType = 12;
            else if (!strcmpi(v30, "herb") || !_strcmpi(v30, "reagent"))
              _this->pItems[v28 - 1].uEquipType = 13;
            else if (!strcmpi(v30, "bottle"))
              _this->pItems[v28 - 1].uEquipType = 14;
            else if (!strcmpi(v30, "sscroll"))
              _this->pItems[v28 - 1].uEquipType = 15;
            else if (!strcmpi(v30, "book"))
              _this->pItems[v28 - 1].uEquipType = 16;
            else if (!strcmpi(v30, "mscroll"))
              _this->pItems[v28 - 1].uEquipType = 17;
            else if (!strcmpi(v30, "gold"))
              _this->pItems[v28 - 1].uEquipType = 18;
            else if (!strcmpi(v30, "gem"))
              _this->pItems[v28 - 1].uEquipType = 19;
            else
              _this->pItems[v28 - 1].uEquipType = 20;
            break;

          case 5:
            if (!strcmpi(v30, "staff"))
              _this->pItems[v28 - 1].uSkillType = 0;
            else if (!strcmpi(v30, "sword"))
              _this->pItems[v28 - 1].uSkillType = 1;
            else if (!strcmpi(v30, "dagger"))
              _this->pItems[v28 - 1].uSkillType = 2;
            else if (!strcmpi(v30, "axe"))
              _this->pItems[v28 - 1].uSkillType = 3;
            else if (!strcmpi(v30, "spear"))
              _this->pItems[v28 - 1].uSkillType = 4;
            else if (!strcmpi(v30, "bow"))
              _this->pItems[v28 - 1].uSkillType = 5;
            else if (!strcmpi(v30, "mace"))
              _this->pItems[v28 - 1].uSkillType = 6;
            else if (!strcmpi(v30, "blaster"))
              _this->pItems[v28 - 1].uSkillType = 7;
            else if (!strcmpi(v30, "shield"))
              _this->pItems[v28 - 1].uSkillType = 8;
            else if (!strcmpi(v30, "leather"))
              _this->pItems[v28 - 1].uSkillType = 9;
            else if (!strcmpi(v30, "chain"))
              _this->pItems[v28 - 1].uSkillType = 10;
            else if (!strcmpi(v30, "plate"))
              _this->pItems[v28 - 1].uSkillType = 11;
            else if (!strcmpi(v30, "club"))
              _this->pItems[v28 - 1].uSkillType = 37;
            else
              _this->pItems[v28 - 1].uSkillType = 38;
            break;

          case 6:
            if (strlen(v30) > 0)
            {
             unsigned int uDice, uRoll;
             sscanf(v30, "%ud%u", &uDice, &uRoll);

             _this->pItems[v28 - 1].uDamageDice = uDice;
             _this->pItems[v28 - 1].uDamageRoll = uRoll;
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

          case 9:  ((char *)(&_this->pItems[v28 - 1 + 1].dword_000000))[2] = atoi(v30); break;
          case 10: _this->pItems[v28 - 1].pUnidentifiedName = (unsigned char *)RemoveQuote(v30); break;
          case 11: _this->pItems[v28 - 1].uSpriteIndex = atoi(v30); break;

          case 12:
            v88 = (int)&_this->pItems[v28 - 1];
            if (_this->pItems[v28 - 1].uMaterial == 3) // 'special'
            {
              v92 = 0;
              while ( _strcmpi((char *)_this->pEnchantments[v92].pName, v30) )
              {
                ++v92;
                if ( v92 >= 24 )
                  goto LABEL_181;
              }
              _this->pItems[v28 - 1].byte_000027 = v92 + 1;

LABEL_181:
              if ( !*(_BYTE *)(v88 + 39) )
              {
                v93 = 0;
                while ( _strcmpi((char *)_this->pSpecialEnchantments[v92].pName, v30) )
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
            if (_this->pItems[v28 - 1].uMaterial == 3 && _this->pItems[v28 - 1].byte_000027) // uMaterial == special
            {
             _this->pItems[v28 - 1].byte_000028 = atoi(v30);
             if (!_this->pItems[v28 - 1].byte_000028)
               _this->pItems[v28 - 1].byte_000028 = 1;
            }
            else
              _this->pItems[v28 - 1].byte_000028 = 0;
            break;

          case 14: _this->pItems[v28 - 1].uEquipX = atoi(v30); break;
          case 15: _this->pItems[v28 - 1].uEquipY = atoi(v30); break;
          case 16: _this->pItems[v28 - 1].pDescription = (unsigned char *)RemoveQuote(v30); break;

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

  _this->pRndItemsTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "rnditems.txt", 0);
  strtok((char *)_this->pRndItemsTXT_Raw, "\r");
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
          switch ( v108 )
          {
            case 0: v39 = atoi(v41); break;

            case 2: _this->pItems[v39 - 1].byte_00002C[0] = atoi(v41); break;
            case 3: _this->pItems[v39 - 1].byte_00002C[1] = atoi(v41); break;
            case 4: _this->pItems[v39 - 1].byte_00002C[2] = atoi(v41); break;
            case 5: _this->pItems[v39 - 1].byte_00002C[3] = atoi(v41); break;
            case 6: _this->pItems[v39 - 1].byte_00002C[4] = atoi(v41); break;
            case 7: _this->pItems[v39 - 1].byte_00002C[5] = atoi(v41); break;
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
   mem_mng.DeleteBuffer( (void *)_this->pRndItemsTXT_Raw);
   _this->pRndItemsTXT_Raw = 0;
  }


  memset(_this->array_011684, 0, 6 * sizeof(int));
  for (i = 0; i < 6; ++i)
  {
    for (j = 0; j < 800; ++j)
     _this->array_011684[i] += _this->pItems[j].byte_00002C[i];
  }

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


  pSkillDescTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "skilldes.txt", 0);
  strtok((char *)pSkillDescTXT_Raw, "\r");
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
            pSkillDescription[v53] = (unsigned char *)RemoveQuote(v54);
            break;
          case 2:
            pNormalSkillDescr[v53] = (unsigned char *)RemoveQuote(v54);
            break;
          case 3:
            pExpertSkillDescr[v53] = (unsigned char *)RemoveQuote(v54);
            break;
          case 4:
            pMasterSkillDescr[v53] = (unsigned char *)RemoveQuote(v54);
            break;
          case 5:
            pGrandSkillDescr[v53] = (unsigned char *)RemoveQuote(v54);
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


  #ifdef OLD_CODE
  pStatsTXT_Raw = (unsigned char*)LODFile_Events_LOD.LODFile_LoadRaw( "stats.txt", 0);
#endif
  #ifndef OLD_CODE
  pStatsTXT_Raw = LODFile_Events_LOD.LODFile_LoadEvent( L"stats.txt");
  #endif
  strtok((char *)pStatsTXT_Raw, "\r");
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
            case 6:  pAttributeDescriptions[v77] = (unsigned char *)RemoveQuote(v58); break;
            case 7:  pHealthPointsAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 8:  pArmourClassAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 9:  pSpellPointsAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 10: pPlayerConditionAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 11: pFastSpellAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 12: pPlayerAgeAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 13: pPlayerLevelAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 14: pPlayerExperienceAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 15: pAttackBonusAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 16: pAttackDamageAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 17: pMissleBonusAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 18: pMissleDamageAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 19: pFireResistanceAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 20: pAirResistanceAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 21: pWaterResistanceAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 22: pEarthResistanceAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 23: pMindResistanceAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 24: pBodyResistanceAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
            case 25: pSkillPointsAttributeDescription = (unsigned char *)RemoveQuote(v58); break;
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




#ifndef OLD_CODE 
 pClassTXT_Raw = LODFile_Events_LOD.LODFile_LoadEvent(L"class.txt");
#endif
#ifdef OLD_CODE 
  pClassTXT_Raw = (unsigned char*)LODFile_Events_LOD.LODFile_LoadRaw("class.txt",2);
#endif
 v78 = (int)strstr((char *)pClassTXT_Raw, "\n") + 1;
 for (i = 0; i < 23; ++i)
 {
  pClassDescriptions[i] = (unsigned char *)strstr((char *)v78, "\"") + 1;
  v78 = (int)strstr((char *)pClassDescriptions[i], "\"");
  *(char *)v78 = 0;
  v78 = (int)strstr((char *)v78 + 1, "\n") + 1;
 }

 return 0;
}













void CMapStats_ctor(struct CMapStats *_this)
{
 memset(_this->pMapInfos, 0, 77 * sizeof(struct MapInfo));
 _this->uNumMaps = 0;
}

//----- (00453F62) --------------------------------------------------------
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
   mem_mng.DeleteBuffer( (void *)pMapStatsTXT_Raw);

 pMapStatsTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "MapStats.txt", 0);
 strtok((char *)pMapStatsTXT_Raw, "\r");
 strtok(0, "\r");
 strtok(0, "\r");

 do
 {
  pMapInfo = &_this->pMapInfos[_this->uNumMaps+1];
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
     case 1:  pMapInfo->pLocationName = (unsigned char *)RemoveQuote(v3);             break;
     case 2:  pMapInfo->pLocationFilename = (unsigned char *)RemoveQuote(v3);         break;
     case 16: pMapInfo->pEncounterMonster1Texture = (unsigned char *)RemoveQuote(v3); break;
     case 20: pMapInfo->pEncounterMonster2Texture = (unsigned char *)RemoveQuote(v3); break;
     case 24: pMapInfo->pEncounterMonster3Texture = (unsigned char *)RemoveQuote(v3); break;


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
       else 
		   pMapInfo->uEAXEnv = 25;
     break;

     default: break;
    }
   }
   else 
	   v16 = 1;


      ++v17;
      v3 = (char *)v15 + 1;
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

//----- (0045501E) ----------.text:00456186----------------------------------------------
int CMonsterStats_Initialize(struct CMonsterStats *_this)
{
  void *v1; // ebx@1
  //int v2; // ebx@4
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
  char *v44; // edi@184
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
  char v86;
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
  char *v108; // [sp+434h] [bp-24h]@9
  int v109; // [sp+438h] [bp-20h]@4
  int v110; // [sp+43Ch] [bp-1Ch]@4
  int v111; // [sp+444h] [bp-14h]@36
  int v112; // [sp+448h] [bp-10h]@36
  size_t v113; // [sp+44Ch] [bp-Ch]@19
  int v114; // [sp+450h] [bp-8h]@1
  int v115;
 struct MonsterInfo *pMonsterInfo;
 char *test_str;
 char c;
  v1 = _this;
  v114 = (int)_this;

 if (pMonstersTXT_Raw)
   mem_mng.DeleteBuffer( (void *)pMonstersTXT_Raw);

 pMonstersTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "monsters.txt", 0);
 test_str=(char *)pMonstersTXT_Raw;
 strtok(test_str, "\r");
 strtok(0, "\r");
 strtok(0, "\r");
 strtok(0, "\r");

 _this->uNumMonsters = 265;
 pMonsterInfo = _this->pMonsterInfos;
 for( int i=0; i<265; i++)
 {
    test_str = strtok(0, "\r") + 1;
    v110 = 0;
    v109 = 0;
    do
    {
      c = *test_str;
      v3 = 0;
      while ( (c != '\t') && c )
      {
        ++v3;
        c = *(test_str+ v3);
      }
      v108 = v3 + test_str;
      if ( !*(v3 + test_str) )
        v109 = 1;
      *(v3 + test_str) = 0;
      if ( v3 )
      {
        switch (v110)
        {
          case 0:
            pMonsterInfo->uID = atoi((char *)test_str);
          break;

          case 1:
            pMonsterInfo->pName = (unsigned char *)RemoveQuote((char *)test_str);
          break;

          case 2:
            pMonsterInfo->pTexture = (unsigned char *)RemoveQuote((char *)test_str);
          break;

          case 3:
            pMonsterInfo->uLevel = atoi((char *)test_str);
          break;

          case 4:

            if (*test_str == '"')
				 *test_str == ' ' ;
			strlen(test_str);

              pMonsterInfo->uHP = 10;   
            pMonsterInfo->uHP = atoi((char *)test_str);
          break;

          case 5:
            pMonsterInfo->uAC = atoi((char *)test_str);
          break;


          case 6:
			  {
            if ( *test_str == '"')
				 *test_str == ' ';
              pMonsterInfo->uExp = 10;
            pMonsterInfo->uExp = atoi((char *)test_str);
          break;
			  }

          case 7:
			  {
            v15 = 0;
            v111 = 0;
            v112 = 0;
            v16 = 0;
            v113 = strlen((char *)test_str);

            do
            {
              v86 = *(_BYTE *)(v16 + test_str);
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
                  v111 = (int)1;
                  break;
              }
              ++v16;
            }
            while ( v16 < v113 );

            if ( v15 )
              pMonsterInfo->byte_000009 = atoi((char *)test_str);
            else
              pMonsterInfo->byte_000009 = 100;

            if (v112)
            {
              v19 = 0;
              v112 = 0;
              do
              {
                v86 = *(_BYTE *)(v19 + test_str);
                v20 = tolower(v86);
                if ( v20 == 37 )
                {
                  //v86 = (_BYTE *)(v19 + test_str + 1);
                  pMonsterInfo->byte_00000A = atoi(v19 + test_str + 1);
                  v112 = 1;
                }
                else
                {
                  if ( v20 == 100 )
                  {
                    if ( !v112 )
                      pMonsterInfo->byte_00000A = atoi((char *)test_str);
                    //v86 = (_BYTE *)(v19 + test_str + 1);
                    v19 = v113;
                    pMonsterInfo->byte_00000B = atoi(v19 + test_str + 1);
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
                v86 = *(_BYTE *)(v21 + test_str);
                if ( tolower(v86) == 108 )
                  break;
                ++v21;
                if ( v21 >= v113 )
                  break;
              }

              v23 = *(_BYTE *)(v21 + test_str + 1);
              v22 = (char *)(v21 + test_str + 2);
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
			  }

          case 8:
			  {
            pMonsterInfo->bQuestMonster = atoi((char *)test_str);
          break;
			  }
          case 9:
			  {
            pMonsterInfo->uCanFly = *(char *)test_str == 'Y';
          break;
			  }
          case 10:
            v86 = *(_BYTE *)test_str;
            v113 = 4;
            if ( tolower(v86) == 115 )
            {
              v86 = *(_BYTE *)(test_str + 1);
              v25 = tolower(v86) != 104 ? 5 : 0;
            }
            else
            {
              v86 = *(_BYTE *)test_str;
              if ( tolower(v86) == 109 )
              {
                v113 = 1;
              }
              else
              {
                v86 = *(_BYTE *)test_str;
                if ( tolower(v86) == 108 )
                {
                  v113 = 2;
                }
                else
                {
                  v86 = *(_BYTE *)test_str;
                  if ( tolower(v86) == 103 )
                    v113 = 3;
                }
              }
              LOBYTE(v25) = v113;
            }
            pMonsterInfo->uMovement = LOBYTE(v25);
          break;

          case 11:
            v86 = *(_BYTE *)test_str;
            v113 = 3;
            if ( tolower(v86) == 115 )
            {
              v113 = 0;
            }
            else
            {
              v86 = *(_BYTE *)test_str;
              if ( tolower(v86) == 119 )
              {
                v113 = 1;
              }
              else
              {
                v86 = *(_BYTE *)test_str;
                if ( tolower(v86) == 110 )
                  v113 = 2;
              }
            }
            pMonsterInfo->uAIType = v113;
          break;

          case 12:
            pMonsterInfo->byte_000011 = atoi(test_str);
          break;

          case 13:
            pMonsterInfo->uSpeed = atoi(test_str);
          break;

          case 15:
            v26 = strlen((const char *)test_str);
            v112 = 0;
            v113 = v26;
            if ( (signed int)v26 > 0 )
            {
              v27 = _this->uNumMonsters;
              v28 = v114;
              do
              {
                v86 = *(_BYTE *)(v112 + test_str);
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
                      pMonsterInfo->byte_000054 |= 32;
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
            pMonsterInfo->uRecoveryTime = atoi((char *)test_str);
          break;

          case 16:
            v43 = strlen((char *)test_str);
            v41 = 0;
            v42 = (int)pMonsterInfo;
            v112 = v43;
            pMonsterInfo->byte_000014 = 1;
            if (v43 <= 0 )
              goto LABEL_185;
            
            while (true)
            {
             v86 = *(_BYTE *)(v41 + test_str);
             if ( tolower(v86) == 120 )
               break;
             ++v41;
             if ( v41 >= v112 )
               goto LABEL_185;
            }

            v44 = test_str + v41;
            *(_BYTE *)v44 = 0;
            *(_BYTE *)(v42 + 20) = atoi((const char *)(v44 + 1));
            *(_BYTE *)v44 = 100;
LABEL_185:
            _strlwr((char *)test_str);
            if (strstr((char *)test_str, "curse"))
              pMonsterInfo->uSpecialAttack = 1;
            else if (strstr((char *)test_str, "weak"))
              pMonsterInfo->uSpecialAttack = 2;
            else if (strstr((char *)test_str, "asleep"))
              pMonsterInfo->uSpecialAttack = 3;
            else if (strstr(test_str, "afraid"))
              pMonsterInfo->uSpecialAttack = 23;
            else if (strstr(test_str, "drunk"))
              pMonsterInfo->uSpecialAttack = 4;
            else if (strstr(test_str, "insane"))
              pMonsterInfo->uSpecialAttack = 5;
            else if (strstr(test_str, "poison1"))
              pMonsterInfo->uSpecialAttack = 6;
            else if (strstr(test_str, "poison2"))
              pMonsterInfo->uSpecialAttack = 7;
            else if (strstr(test_str, "poison3"))
              pMonsterInfo->uSpecialAttack = 8;
            else if (strstr(test_str, "disease1"))
              pMonsterInfo->uSpecialAttack = 9;
            else if (strstr(test_str, "disease2"))
              pMonsterInfo->uSpecialAttack = 10;
            else if (strstr(test_str, "disease3"))
              pMonsterInfo->uSpecialAttack = 11;
            else if (strstr(test_str, "paralyze"))
              pMonsterInfo->uSpecialAttack = 12;
            else if (strstr(test_str, "uncon"))
              pMonsterInfo->uSpecialAttack = 13;
            else if (strstr(test_str, "dead"))
              pMonsterInfo->uSpecialAttack = 14;
            else if (strstr(test_str, "stone"))
              pMonsterInfo->uSpecialAttack = 15;
            else if (strstr(test_str, "errad"))
              pMonsterInfo->uSpecialAttack = 16;
            else if (strstr(test_str, "brkitem"))
              pMonsterInfo->uSpecialAttack = 17;
            else if (strstr(test_str, "brkarmor"))
              pMonsterInfo->uSpecialAttack = 18;
            else if (strstr(test_str, "brkweapon"))
              pMonsterInfo->uSpecialAttack = 19;
            else if (strstr(test_str, "steal"))
              pMonsterInfo->uSpecialAttack = 20;
            else if (strstr(test_str, "age"))
              pMonsterInfo->uSpecialAttack = 21;
            else if (strstr(test_str, "drainsp"))
              pMonsterInfo->uSpecialAttack = 22;
            else pMonsterInfo->uSpecialAttack = 0;
           break;

          case 17:
            pMonsterInfo->uAttackType = sub_454CB4(test_str);
          break;

          case 18:
            sub_454D7D(test_str, &pMonsterInfo->byte_000016, &pMonsterInfo->byte_000017, &pMonsterInfo->byte_000018);
          break;

          case 19:
            pMonsterInfo->uMissleType = sub_454E3A(test_str);
          break;

          case 20:
            pMonsterInfo->byte_00001A = atoi(test_str);
          break;

          case 21:
            pMonsterInfo->uAttack2Type = sub_454CB4(test_str);
          break;

          case 22:
            sub_454D7D(test_str, &pMonsterInfo->byte_00001C, &pMonsterInfo->byte_00001D, &pMonsterInfo->byte_00001E);
          break;

          case 23:
            pMonsterInfo->uAttack2MissleType = sub_454E3A(test_str);
          break;

          case 24:
            pMonsterInfo->uSpell1UseChance = atoi(test_str);
          break;

          case 25:
            strcpy(Str, (char *)test_str);
            Str[0] = 32;
            Str[strlen(Str) - 1] = 32;
            sub_4BE3BF((unsigned char *)Str, &splitter);
            if (splitter.uNumSubstrings >= 3)
            {
             v111 = 1;
             pMonsterInfo->uSpell1Type = sub_4548E2(&splitter, &v111);
             pMonsterInfo->uSpell1Power = atoi((char *)splitter.pSubstrings[2 + v111]) & 0x3F;
             if (!_strcmpi((char *)splitter.pSubstrings[1 + v111], "E"))
               pMonsterInfo->uSpell1Power |= 0x40;
             else if (!_strcmpi((char *)splitter.pSubstrings[1 + v111], "M"))
               pMonsterInfo->uSpell1Power |= 0x80;
             else if (!_strcmpi((char *)splitter.pSubstrings[1 + v111], "G"))
               pMonsterInfo->uSpell1Power |= 0x100;
            }
            else
            {
             pMonsterInfo->uSpell1Type = 0;
             pMonsterInfo->uSpell1Power = 0;
            }
          break;


          case 26:
            pMonsterInfo->uSpell2UseChance = atoi((char *)test_str);
          break;

          case 27:
            strcpy(Str, (char *)test_str);
            Str[0] = 32;
            Str[strlen(Str) - 1] = 32;
            sub_4BE3BF((unsigned char *)Str, &splitter);
            if (splitter.uNumSubstrings >= 3)
            {
             v111 = 1;
             pMonsterInfo->uSpell2Type = sub_4548E2(&splitter, &v111);
             pMonsterInfo->uSpell2Power = atoi((char *)splitter.pSubstrings[2 + v111]) & 0x3F;
             if (!_strcmpi((char *)splitter.pSubstrings[1 + v111], "E"))
               pMonsterInfo->uSpell2Power |= 0x40;
             else if (!_strcmpi((char *)splitter.pSubstrings[1 + v111], "M"))
               pMonsterInfo->uSpell2Power |= 0x80;
             else if (!_strcmpi((char *)splitter.pSubstrings[1 + v111], "G"))
               pMonsterInfo->uSpell2Power |= 0x100;
            }
            else
            {
             pMonsterInfo->uSpell2Type = 0;
             pMonsterInfo->uSpell2Power = 0;
            }
          break;

          case 28:
            if (tolower(*(_BYTE *)test_str) == 'i')
              v63 = 200;
            else
              v63 = atoi((char *)test_str);
            pMonsterInfo->uResistanceFire = v63;
          break;

          case 29:
            if (tolower(*(_BYTE *)test_str) == 'i')
              v63 = 200;
            else
              v63 = atoi((char *)test_str);
            pMonsterInfo->uResistanceAir = v63;
          break;

          case 30:
            if (tolower(*(_BYTE *)test_str) == 'i')
              v63 = 200;
            else
              v63 = atoi((char *)test_str);
            pMonsterInfo->uResistanceWater = v63;
          break;

          case 31:
            if (tolower(*(_BYTE *)test_str) == 'i')
              v63 = 200;
            else
              v63 = atoi((char *)test_str);
            pMonsterInfo->uResistanceEarth = v63;
          break;

          case 32:
            if (tolower(*(_BYTE *)test_str) == 'i')
              v63 = 200;
            else
              v63 = atoi((char *)test_str);
            pMonsterInfo->uResistanceMind = v63;
          break;

          case 33:
            if (tolower(*(_BYTE *)test_str) == 'i')
              v63 = 200;
            else
              v63 = atoi((char *)test_str);
            pMonsterInfo->uResistanceSpirit = v63;
          break;

          case 34:
            if (tolower(*(_BYTE *)test_str) == 'i')
              v63 = 200;
            else
              v63 = atoi((char *)test_str);
            pMonsterInfo->uResistanceBody = v63;
          break;

          case 35:
            if (tolower(*(_BYTE *)test_str) == 'i')
              v63 = 200;
            else
              v63 = atoi((char *)test_str);
            pMonsterInfo->uResistanceLight = v63;
          break;

          case 36:
            if (tolower(*(_BYTE *)test_str) == 'i')
              v63 = 200;
            else
              v63 = atoi((char *)test_str);
            pMonsterInfo->uResistanceDark = v63;
          break;

          case 37:
            if (tolower(*(_BYTE *)test_str) == 'i')
              v63 = 200;
            else
              v63 = atoi((char *)test_str);
            pMonsterInfo->uResistancePhysical = v63;
          break;

          case 38:
          
            strcpy(Str, (char *)test_str);
            Str[0] = ' ';
            Str[strlen(Str) - 1] = ' ';
			 //!!!!!!!
			  v104=test_str;
			 //!!!!!!!
            sub_4BE3BF((unsigned char *)Str, &splitter);
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
                      sub_454D7D((char *)splitter.pSubstrings[2], &pMonsterInfo->byte_00002E, (unsigned char *)&pMonsterInfo->byte_000030, (unsigned char *)&pMonsterInfo->byte_000031);
                      pMonsterInfo->word_00003C = sub_454CB4(test_str);
                    }
                  }
                  else
                  {
                    v75 = 88 * v115 + v114;
                    pMonsterInfo->byte_00002E = 2;
                    if ( v73 > 1 )
                    {
                      TmpBuf[0] = 0;
                      strcpy((char *)TmpBuf, Source);
                      if ( v73 > 2 )
                      {
                        v112 = 3;
                        if ( v73 > 3 )
                        {
                          do
                          {
                            strcat((char *)TmpBuf, " ");
                            v76 = (&v104)[4 * v112];
                            v84 = (int)(&v104)[4 * v112];
                            strcat((char *)TmpBuf, (const char *)v84);
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
                      if (pMonsterDescriptionList->uNumDescriptions)
                      {
                        LOWORD(v77) = sub_44FA08(pMonsterDescriptionList, (char *)TmpBuf);
                        ++v77;
                        *(_WORD *)(v75 + 60) = v77;
                        if ( (_WORD)v77 == -1 )
                        {
                          v86 = (int)&v90;
                          wsprintfA(&v90, "Can't create random monster: '%s' See MapStats!", &v90);
                          v86 = 2239;
                          v85 = (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Itemdata.cpp";
                          v111 = (int)&v81;
                          Game_sub_40E2C8(&v81, &v90, (int)((char *)&v110 + 3));
                          sub_466D09(&v107, *(int *)&v81, v82, v83, v84, (const char *)v85, __LINE__);
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
      v110 +=1;
      test_str = v108 + 1;
    }
    while ( /*HIDWORD(v110) - 1 <= *(_DWORD *)(v114 + 23444) &&*/ !v109 );

    pMonsterInfo++;
  }

  return _this->uNumMonsters;
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

  v6 = (int)a2;
  v5 = Str;
  *(_BYTE *)a2 = 0;
  *(_BYTE *)a3 = 1;
  v11 = (int)a2;
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
        LOBYTE(v8) = (int)a3;
        *(_BYTE *)a3 = 1;
      }
    }
  }
  return v8;
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

 if (!_strcmpi((char *)pStrings->pSubstrings[0], "Dispel"))
 {
  return 80;
 }
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Day"))
 {
  *a2 += 1;
  return 85;
 }
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Hour"))
 {
  *a2 += 1;
  return 86;
 }
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Shield"))
 {
  *a2 += 1;
  return 17;
 }
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Spirit"))
   return 52;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Power"))
   return 77;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Meteor"))
   return 9;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Lightning"))
   return 18;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Implosion"))
   return 20;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Stone"))
   return 38;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Haste"))
   return 5;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Heroism"))
   return 51;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Pain"))
   return 95;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Sparks"))
   return 15;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Light"))
   return 78;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Toxic"))
   return 90;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "ShrapMetal"))
   return 93;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Paralyze"))
   return 81;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Fireball"))
   return 6;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Incinerate"))
   return 11;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Fire"))
   return 2;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Rock"))
   return 41;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Mass"))
   return 44;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Ice"))
   return 26;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Acid"))
   return 29;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Bless"))
   return 46;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Dragon"))
   return 97;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Reanimate"))
   return 89;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Summon"))
   return 82;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Fate"))
   return 47;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Harm"))
   return 70;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Mind") )
   return 57;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Blades"))
   return 39;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Psychic") )
   return 65;
 else if (!_strcmpi((char *)pStrings->pSubstrings[0], "Hammerhands"))
   return 73;
 else
 {
  wsprintfA((char *)TmpBuf, "Unknown monster spell %s", pStrings->pSubstrings[0]);
  v11 = &v5;
  Game_sub_40E2C8(&v5, (char *)TmpBuf, (int)&v12);
  sub_466D09(&v11, *(int *)&v5, v6, v7, v8, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Itemdata.cpp", 1562);
  *a2 += 1;
  return 0;
 }
}





//----- (00454F4E) --------------------------------------------------------
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

 pMonsterPlacementTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "placemon.txt", 0);
 strtok((char *)pMonsterPlacementTXT_Raw, "\r");

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
          _this->sPlacements.pSubstrings[i] = (unsigned char *)RemoveQuote(result);
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

//----- (0045384A) -------------------------.text:004549AB -------------------------------
void CSpellStats_Initialize(struct CSpellStats *_this)
{

  unsigned int column; // ebx@4
  char *string_pos; // esi@4
  char *next_string_pos; // esi@4
  int sub_str_len; // eax@5
  char test_char; // cl@
  int mode_flag; // eax@41
  unsigned int spell_count; // [sp+10h] [bp-10h]@3
  bool skip; // [sp+14h] [bp-Ch]@4
 struct SpellInfo *pSpellInfo;

 if (pSpellsTXT_Raw)
   mem_mng.DeleteBuffer( (void *)pSpellsTXT_Raw);

 pSpellsTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "spells.txt", 0);
 strtok((char *)pSpellsTXT_Raw, "\r");
 strtok(0, "\r");

 for (spell_count=1; spell_count<100; spell_count++)
	 {
	 pSpellInfo = &_this->pSpellInfos[spell_count];
	 column = 0;
	 string_pos = strtok(0, "\r") + 1;
	 skip = false;
	 do
		 {
		 test_char = *string_pos;
		 sub_str_len = 0;
		 while ( test_char != 9 && test_char )
			 {
			 ++sub_str_len;
			 test_char = *(string_pos+sub_str_len);
			 }
		 next_string_pos = string_pos+sub_str_len;

		 if ( ! *(string_pos+sub_str_len) )
			 skip = true;

		 *(string_pos+sub_str_len) = 0;

		 if ( sub_str_len )
			 {
			 switch (column )
				 {
			 case 2:
				 {
				 pSpellInfo->pSpellName = (unsigned char *)RemoveQuote(string_pos);
				 break;
				 }
			 case 3:
				 {
				 pSpellInfo->uSpellSchool = 4;

				 if (!strcmpi("fire", string_pos))
					 pSpellInfo->uSpellSchool = 0;
				 else if (!strcmpi("air", string_pos))
					 pSpellInfo->uSpellSchool = 1;
				 else if (!strcmpi("water", string_pos))
					 pSpellInfo->uSpellSchool = 2;
				 else if (!strcmpi("earth", string_pos))
					 pSpellInfo->uSpellSchool = 3;
				 else if (!strcmpi("spirit", string_pos))
					 pSpellInfo->uSpellSchool = 6;
				 else if (!strcmpi("mind", string_pos))
					 pSpellInfo->uSpellSchool = 7;
				 else if (!_strcmpi("body", string_pos))
					 pSpellInfo->uSpellSchool = 8;
				 else if (!strcmpi("light", string_pos))
					 pSpellInfo->uSpellSchool = 9;
				 else if (!strcmpi("dark", string_pos))
					 pSpellInfo->uSpellSchool = 10;
				 else if (!strcmpi("magic", string_pos))
					 pSpellInfo->uSpellSchool = 5;
				 break;
				 }
			 case 4:
				 {
				 pSpellInfo->pSpellNameShort = (unsigned char *)RemoveQuote(string_pos);
				 break;
				 }
			 case 5:
				 {
				 pSpellInfo->pSpellDescription = (unsigned char *)RemoveQuote(string_pos);
				 break;
				 }
			 case 6:
				 {
				 pSpellInfo->pSpellBasicSkillDesc = (unsigned char *)RemoveQuote(string_pos);
				 break;
				 }
			 case 7:
				 {
				 pSpellInfo->pSpellExpertSkillDesc = (unsigned char *)RemoveQuote(string_pos);
				 break;
				 }
			 case 8:
				 {
				 pSpellInfo->pSpellMasterSkillDesc = (unsigned char *)RemoveQuote(string_pos);
				 break;
				 }
			 case 9:
				 {
				 pSpellInfo->pSpellGrandmasterSkillDesc = (unsigned char *)RemoveQuote(string_pos);
				 break;
				 }
			 case 10:
				 {

				 sub_str_len = strlen(string_pos);
				 if ( sub_str_len > 0 )
					 {
					 for(int i=0; i<sub_str_len; i++)
						 {
						 mode_flag = tolower(*(string_pos+i)) - 99;
						 switch (mode_flag )
							 {
						 case 13:	word_4E3C68[spell_count].byte13|= 8;  //P
							 break;
						 case 10:	word_4E3C68[spell_count].byte13|= 1; //M
							 break;
						 case 2:   word_4E3C68[spell_count].byte13|= 2; //E 
							 break;
						 case 0:   word_4E3C68[spell_count].byte13|= 4;  //C
							  break;
							 }
						 }

					 }
				 break;
				 }
				 }
			 }
		 else
			 {
			 skip = true;
			 }
		 ++column;
		 string_pos=next_string_pos+1;
		 }
		 while ( column <12 && !skip );

		 if ( !(spell_count % 11) )
			 strtok(0, "\r");
	 }

 
}



//----- (00453B3C) --------------------------------------------------------
void class40_LoadPotionsTable(struct class40 *_this)
{
  char *i; // eax@3
  signed int v2; // esi@11
  char *v3; // eax@16
  char *v4; // edi@16
  int v5; // esi@17
  __int16 v6; // ax@17
  CHAR Text; // [sp+Ch] [bp-6Ch]@26
  void *v9; // [sp+68h] [bp-10h]@1
  int uRow; // [sp+6Ch] [bp-Ch]@10
  int v11; // [sp+70h] [bp-8h]@10
  char *v12; // [sp+74h] [bp-4h]@4
  int uCol;

  v9 = _this;

 if (pPotionsTXT_Raw)
   mem_mng.DeleteBuffer(pPotionsTXT_Raw);

 pPotionsTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "potion.txt", 0);
 for (i = strtok((char *)pPotionsTXT_Raw, "\t\r\n"); ; i = strtok(0, "\t\r\n"))
 {
  if (!strcmp(i, "222"))
    break;
  if (!i)
  {
   MessageBoxW(0, L"Error Pre-Parsing Potion Table", L"Load Error", 0x10);
   return;
  }
 }

 while (true)
 {
  v12 = strtok(0, "\t\r\n");
  if (!strcmp(v12, "222"))
    break;
  if (!v12)
  {
   MessageBoxW(0, L"Error Pre-Parsing Potion Table", L"Load Error", 0x10);
   return;
  }
 }

  uRow = 0;
  v11 = 30642;
  do
  {
    uCol = 0;
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
    uCol = 0;
    do
    {
      v3 = strtok(0, "\r\t\n");
      v4 = v3;
      if ( !v3 )
        break;
      v6 = atoi(v3);
      v5 = (_DWORD)v9 + (v11 + uCol)*2;
      *(_WORD *)v5 = v6;
      if ( !v6 )
      {
        if ( tolower((unsigned __int8)*v4) == 101 )
          *(_WORD *)v5 = atoi(v4 + 1);
        else
          *(_WORD *)v5 = 0;
      }
      ++uCol;
    }
    while (uCol < 50 );
    if (uCol != 50)
      break;
    strtok(0, "\r\t\n");
    v11 += 50;
    ++uRow;
  }
  while ( v11 < 33142 );
  if (uRow != 50 )
  {
    wsprintfA(&Text, "Error Parsing Potion Table at Row: %d Column: %d", uRow, uCol);
    MessageBoxA(0, &Text, "Parsing Error", 0x10u);
  }

  if (pPotionsTXT_Raw)
  {
    mem_mng.DeleteBuffer( (void *)pPotionsTXT_Raw);
    pPotionsTXT_Raw = 0;
  }
}



//----- (00453CE5) --------------------------------------------------------
void class40_LoadPotionNotes(struct class40 *_this)
{
  char *i; // eax@3
  signed int v2; // esi@11
  const char *result; // eax@12
  const char *v4; // edi@16
  int v5; // esi@17
  char Text[256]; // [sp+Ch] [bp-6Ch]@26
  void *v10; // [sp+68h] [bp-10h]@1
  int uRow; // [sp+6Ch] [bp-Ch]@10
  int v12; // [sp+70h] [bp-8h]@10
  char *v13; // [sp+74h] [bp-4h]@4

  v10 = _this;

 if (pPotionNotesTXT_Raw)
   mem_mng.DeleteBuffer( (void *)pPotionNotesTXT_Raw);

 pPotionNotesTXT_Raw = 0;
 pPotionNotesTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "potnotes.txt", 0);

 for ( i = strtok((char *)pPotionNotesTXT_Raw, "\t\r\n"); ; i = strtok(0, "\t\r\n") )
 {
    v13 = i;
    if ( !strcmp(i, "222") )
      break;
    if ( !v13 )
    {
LABEL_20:
      MessageBoxA(NULL, "Error Pre-Parsing Potion Table", "Load Error", 0x10);
      return;
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
  uRow = 0;
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
    ++uRow;
  }
  while ( v12 < 35642 );
  if (uRow != 50)
  {
    wsprintfA(Text, "Error Parsing Potion Autonote Table at Row: %d Column: %d", uRow, v13);
    MessageBoxA(NULL, Text, "Parsing Error", 0x10);
  }
}









void class48_ctor(struct class48 *_this)
{
 memset(_this, 0, sizeof(struct class48));
}

//----- (004547E4) --------------------------------------------------------
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
   mem_mng.DeleteBuffer( (void *)pHostileTXT_Raw);

 pHostileTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "hostile.txt", 0);

 strtok((char *)pHostileTXT_Raw, "\r");
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
    mem_mng.DeleteBuffer( (void *)pHostileTXT_Raw);
    pHostileTXT_Raw = 0;
  }
  return (int)pHostileTXT_Raw;
}






//----- (00453E6D) --------------------------------------------------------
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
    mem_mng.DeleteBuffer( (void *)pHistoryTXT_Raw);

 pHistoryTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw("history.txt", 0);
 strtok((char *)pHistoryTXT_Raw, "\r");

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
          *(_DWORD *)(v12 - 8) = (int)RemoveQuote(v3);
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
              *(_DWORD *)(v12 - 4) = (int)RemoveQuote(v3);
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
int class35_sub_48A3BC_MessWithPalettes(struct class35 *_this, int a2)
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
  cTexture cTexture_obj;//char cTexture_obj[128]; // [sp+318h] [bp-88h]@4
  //cTexture_obj::ptr_000044 //int v14; // [sp+35Ch] [bp-44h]@7
  char Source[32]; // [sp+360h] [bp-40h]@4
  void *v16; // [sp+380h] [bp-20h]@1
  float v17; // [sp+384h] [bp-1Ch]@7
  int v18; // [sp+388h] [bp-18h]@6
  float v19; // [sp+38Ch] [bp-14h]@7
  float v20; // [sp+390h] [bp-10h]@7
  float v21; // [sp+394h] [bp-Ch]@7
  float v22; // [sp+398h] [bp-8h]@7
  float v23; // [sp+39Ch] [bp-4h]@7

  runtime_warning(no palette textures for now);
  return 0;

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
      cTexture_obj.cTexture_Zero();
      if ( LODFile_Bitmaps_LOD.LoadTextureFromLOD( &cTexture_obj, Source, 1) == 1 )
      {
        v4 = 0;
        v18 = 1 - (_DWORD)&v10;
        do
        {
         v21 = cTexture_obj.ptr_000044[v4] * 0.003921568859368563;

         v20 = cTexture_obj.ptr_000044[cTexture_obj.ptr_000044[v4] + v18] * 0.003921568859368563;

         v23 = cTexture_obj.ptr_000044[v4 + 2] * 0.003921568859368563;

          sub_48A7AA((float *)&v17, (float *)&v19, v21, v20, v23, (float *)&v22);
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
        cTexture_Free(&struct_505898.Dest);
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
  char *v9; // ecx@19
  int v10; // eax@20
  char v11; // dl@20
  int result; // eax@39
  int v15; // [sp+10h] [bp-10h]@4
  int v16; // [sp+10h] [bp-10h]@24
  unsigned char **v17; // [sp+14h] [bp-Ch]@1
  signed int v18; // [sp+14h] [bp-Ch]@19
  signed int v19; // [sp+18h] [bp-8h]@1
  signed int v21; // [sp+1Ch] [bp-4h]@3
  signed int v22; // [sp+1Ch] [bp-4h]@19
 int i;

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

 _this->pNPCNamesTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "npcnames.txt", 0);
 strtok((char *)_this->pNPCNamesTXT_Raw, "\r");

  v19 = 0;
  v17 = (unsigned char **)_this->pNPCNames;
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
            v17[1] = (unsigned char *)RemoveQuote(v4);
        }
        else
        {
          v17[0] = (unsigned char *)RemoveQuote(v4);
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



  _this->pNPCProfTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "npcprof.txt", 0);
  strtok((char *)_this->pNPCProfTXT_Raw, "\r");
  strtok(0, "\r");
  strtok(0, "\r");
  strtok(0, "\r");

  for (i = 0; i < 58; ++i)
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
            _this->pProfessions[i].uHireCost = atoi(v9);
            break;
          case 3:
            _this->pProfessions[i].pActionText = (unsigned char *)RemoveQuote(v9);
            break;
          case 4:
            _this->pProfessions[i].pBenefits = (unsigned char *)RemoveQuote(v9);
            break;
          case 5:
            _this->pProfessions[i].pJoinText = (unsigned char *)RemoveQuote(v9);
            break;
          case 6:
            _this->pProfessions[i].pDismissText = (unsigned char *)RemoveQuote(v9);
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
  }
  _this->uNumNPCProfessions = 58;
}







//----- (00476CB5) --------------------------------------------------------
void CNPCStats_sub_476CB5(struct CNPCStats *_this)
{
  void *v2; // esi@1
  char *v4; // eax@2
  char v5; // dl@3
  int v6; // ecx@3
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
  signed int v36; // [sp+18h] [bp-8h]@2
  signed int v37; // [sp+18h] [bp-8h]@27
  signed int v38; // [sp+18h] [bp-8h]@43
  signed int v39; // [sp+18h] [bp-8h]@57
  signed int v40; // [sp+1Ch] [bp-4h]@2
  signed int v41; // [sp+1Ch] [bp-4h]@27
  signed int v42; // [sp+1Ch] [bp-4h]@43
  signed int v43; // [sp+1Ch] [bp-4h]@57
 int i;

  v2 = _this;

 _this->pNPCDataTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "npcdata.txt", 0);
 strtok((char *)_this->pNPCDataTXT_Raw, "\r");
 strtok(0, "\r");

 for (i = 0; i < 501; ++i)
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
            _this->pNPCData[i].pNPCName = (unsigned char *)RemoveQuote(v4);
            _this->pNPCNames2[i] = (unsigned char *)RemoveQuote(v4);
            break;
          case 1:
            _this->pNPCData[i].uPortraitID = atoi(v4);
            break;
          case 5:
            _this->pNPCData[i].dword_000014 = atoi(v4);
            break;
          case 6:
            _this->pNPCData[i].uProfession = atoi(v4);
            break;
          case 7:
            _this->pNPCData[i].dword_00001C = atoi(v4);
            break;
          case 8:
            _this->pNPCData[i].dword_000020 = *v4 == 121;
            break;
          case 9:
            _this->pNPCData[i].dword_000028 = atoi(v4);
            break;
          case 10:
            _this->pNPCData[i].dword_00002C = atoi(v4);
            break;
          case 11:
            _this->pNPCData[i].dword_000030 = atoi(v4);
            break;
          case 12:
            _this->pNPCData[i].dword_000034 = atoi(v4);
            break;
          case 13:
            _this->pNPCData[i].dword_000038 = atoi(v4);
            break;
          case 14:
            _this->pNPCData[i].dword_00003C = atoi(v4);
            break;
          default:
            break;
        }
      }
      ++v40;
      v4 = (char *)(v27 + 1);
    }
    while ( v40 + 1 <= 15 && !v36 );
 }
 _this->dword_017FC4 = 501;


 _this->pNPCGreetTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "npcgreet.txt", 0);
 strtok((char *)_this->pNPCGreetTXT_Raw, "\r");

 for (i = 0; i < 206; ++i)
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
          _this->pNPCGreetings[i].pGreeting1 = (unsigned char *)RemoveQuote(v10);
        else if (v41 == 2)
          _this->pNPCGreetings[i].pGreeting2 = (unsigned char *)RemoveQuote(v10);
      }
      ++v41;
      v10 = (char *)(v13 + 1);
    }
    while ( v41 <= 2 && !v37 );
  }

 _this->pNCPGroupTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "npcgroup.txt", 0);
 strtok((char *)_this->pNCPGroupTXT_Raw, "\r");

 for (i = 0; i < 51; ++i)
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
          _this->array_017EF4[i] = atoi(v16);
      }
      ++v42;
      v16 = (char *)(v19 + 1);
    }
    while ( v42 <= 1 && !v38 );
  }

 _this->pNPCNewsTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "npcnews.txt", 0);
 strtok((char *)_this->pNPCNewsTXT_Raw, "\r");

 for (i = 0; i < 52; ++i)
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
          _this->pCatchPhrases[i] = (unsigned char *)RemoveQuote(result);
      }
      ++v43;
      result = (char *)(v25 + 1);
    }
    while ( v43 <= 1 && !v39 );
  }
}




//----- (00476977) --------------------------------------------------------
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

  v2 = (int)_this;
  if (_this->pNPCTextTXT_Raw)
    mem_mng.DeleteBuffer( (void *)_this->pNPCTextTXT_Raw);

  _this->pNPCTextTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "npctext.txt", 0);
  strtok((char *)_this->pNPCTextTXT_Raw, "\r");
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
          *(_DWORD *)(unk_72166C + v29) = (int)RemoveQuote(v4);
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
   mem_mng.DeleteBuffer( (void *)_this->pNPCTopicTXT_Raw);

 _this->pNPCTopicTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "npctopic.txt", 0);
 strtok((char *)_this->pNPCTopicTXT_Raw, "\r");

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
          *(_DWORD *)(unk_721668 + v30) = (int)RemoveQuote(v9);
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
   mem_mng.DeleteBuffer( (void *)_this->pNPCDistTXT_Raw);

 _this->pNPCDistTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "npcdist.txt", 0);
 strtok((char *)_this->pNPCDistTXT_Raw, "\r");
 strtok(0, "\r");

 v1 = 0;
  v31 = 1;
  v32 = (int)_this->unk_016544 + 5;
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
          *(_BYTE *)(v31 + (v1 << 6) + (_this->unk_016544 + 4)) = atoi(v14);
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
  v19 = (int)_this->unk_016544;
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
  mem_mng.DeleteBuffer( (void *)_this->pNPCDistTXT_Raw);
  _this->pNPCDistTXT_Raw = 0;
 }
 return 0;
}





//----- (0048A8A3) --------------------------------------------------------
int class35_sub_48A8A3(struct class35 *_this)
{
 unsigned int i;

 for (i = 1; i < 50; ++i)
 {
  if (_this->array_267A00[i])
    _this->dword_267AC8 = i + 1;
 }

 return _this->dword_267AC8;
}



//----- (00402F07) --------------------------------------------------------
void ItemGen_Reset(struct ItemGen *_this)
{
 _this->uItemID = -1;
 _this->dword_000004 = 0;
 _this->dword_000008 = 0;
 _this->dword_00000C = 0;
 _this->dword_000010 = 0;
 _this->dword_000014 = 0;
 _this->byte_000018 = 0;
 _this->byte_00001A = 0;
 _this->word_00001C = 0;
 _this->word_00001E = 0;
 _this->dword_000020 = 0;
}




//----- (00456620) --------------------------------------------------------
char class40_sub_456620_CreateSomeSemirandomItem(struct class40 *_this, int a2, signed int a3, struct ItemGen *Dst)
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

  v5 = (unsigned char *)Dst;
  if (!v5)
    v5 = (unsigned char *)mem_mng.AllocatedNamedBuffer( NULL, 0x24, "newItemGen");
  memset(v5, 0, sizeof(ItemGen));

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
    memset(v50, 0, 0xC80);

    v51 = 0;
    v7 = (int *)v50;
    v60 = 1;
    if ( v52 == -1 )
    {
     v52 = (int)&_this->pItems[0].uEquipType;//(int)((char *)_this + 80);
     v9 = (int)&_this->pItems[0].byte_00002C[v6];//(int)((char *)_this + v6 + 92)
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
     v54 = (int)&_this->pItems[0].uSkillType;//(int)((char *)_this + 81);
     v8 = (int)&_this->pItems[0].byte_00002C[v6];//(int)((char *)_this + v6 + 92)
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
    v11 = (int)(&_this->pItems[*(_DWORD *)v5 - 1]) + v53 + 44;
    //v11 = *((_BYTE *)v4 + 48 * *(_DWORD *)v5 + v53 + 44);
    if ( v11 < v10 )
    {
      v12 = (int *)&v50;
      do
      {
        ++v12;
        v13 = *v12;
        *(_DWORD *)v5 = *v12;
        v11 += *((char *)&_this->pItems[v13] + v53 + 44);
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
      LOBYTE(v18) = class40_sub_456D17(_this, (ItemGen *)v5);
      return v18;
    }

    v56 = 0;
    v19 = rand() % _this->array_011684[v53];
    *(_DWORD *)v5 = 0;
    if ( v19 > 0 )
    {
      do
        v56 += _this->pItems[*(_DWORD *)v5++].byte_00002C[v53];
      while ( v56 < v19 );
    }
    if ( !v19 )
      *(_DWORD *)v5 = 1;
    if ( !*(_DWORD *)v5 )
      *(_DWORD *)v5 = 1;
    if ( *((char *)(&_this->pItems[*(_DWORD *)v5]) + 32) == 14 && *(_DWORD *)v5 != 220 )
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
    if ( !(unsigned __int16)sub_449B57((int)pParty_global->unk_000764 + 1, 239) )
      *(_DWORD *)v5 = 486;
  }
  if (*(&pClass40->pItems[*(_DWORD *)v5 - 1].uEquipType + 18))
    *(_DWORD *)(v5 + 20) = 0;
  else
    *(_DWORD *)(v5 + 20) = 1;
  if ( *((char *)&_this->pItems[*(_DWORD *)v5] + 32) != 14 )
  {
    *(_DWORD *)(v5 + 12) = 0;
    *(_DWORD *)(v5 + 4) = 0;
  }
  LOBYTE(v18) = *((char *)&_this->pItems[*(_DWORD *)v5] + 32);
  if ( (_BYTE)v18 <= 2 )
  {
    LOBYTE(v18) = v53;
    v33 = (int)((char *)_this + 4 * v53 + 0x116CC);
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
       v18 = rand() % 6 + pClass40->pItems[*(_DWORD *)v5 - 1].uDamageModifier + 1;
        *(_DWORD *)(v5 + 16) = v18;
        *(_BYTE *)(v5 + 25) = v18;
      }
      return v18;
    }
    LOBYTE(v18) = v53;
    v21 = (int)((char *)_this + 4 * v53 + 71324);
    if ( !*(_DWORD *)v21 )
      return v18;
    v23 = *(_DWORD *)v21;
    v22 = rand() % 100;
    if ( v22 < v23 )
      goto LABEL_128;
    LOBYTE(v18) = v53;
    if ( !*((_DWORD *)_this + v53 + 0x45AD) )
      return v18;
    if ( v22 < v23 )
    {
LABEL_128:
      v25 = rand() % *((_DWORD *)_this + *((char *)(&_this->pItems[*(_DWORD *)v5]) + 32) + 0x45B6);
      v26 = *(_DWORD *)v5;
      *(_DWORD *)(v5 + 4) = 0;

      //v24 = *((_BYTE *)_this + _this->pItems[v26]->uEquipType + 0x9609);
      v24 = (int)&_this->pEnchantments[0].array_000008[_this->pItems[v26].uEquipType + 1];

      for ( i = v25; v24 < i; v24 += *((_BYTE *)_this + 20 * *(_DWORD *)(v5 + 4) + *((char  *)(&_this->pItems[v27]) + 32) + 0x9609) )
      {
        v27 = *(_DWORD *)v5;
        ++*(_DWORD *)(v5 + 4);
      }
      ++*(_DWORD *)(v5 + 4);
      v29 = *((_DWORD *)_this + 2 * v53 + 17858);
      v30 = rand();
      v28 = *(_DWORD *)(v5 + 4) - 1;
      v18 = v30 % (*((_DWORD *)_this + 2 * v53 + 17859) - v29 + 1) + v29;
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
    v18 = v23 + *((_DWORD *)_this + v53 + 17837);
    compile_error;//v32 = __SETO__(v22, v18);
    v31 = v22 - v18 < 0;
  }
  if ( !(v31 ^ v32) )
    return v18;
  memset(&v50, 0, 0xC80u);
  v37 = 0;
  v61 = 0;
  if ( *((_DWORD *)_this + 17894) > 0 )
  {
    v51 = -16 - (_DWORD)v4;
    v58 = (int *)&v50;
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
  *(_DWORD *)(v5 + 12) = (int)v50;
  v18 = *((_BYTE *)v4 + 28 * *(v50 + 1389) + *((_BYTE *)v4 + 48 * *(_DWORD *)v5 + 32));
  v43 = v44 + 1;
  v62 = v18;
  if ( v18 < v43 )
  {
    for ( j = (int *)&v50; ; j = (int *)v59 )
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


//----- (00459E3F) --------------------------------------------------------
int __cdecl sub_459E3F()
{
 int i;
 int result;

 for (i = 0; i < 30; ++i)
   result = GetAsyncKeyState(pKeyboardController->array_00000C_vkeys[i]);

 return result;
}





//----- (0048A336) --------------------------------------------------------
int sub_48A336(struct class35 *_this)
{
 int i;
  int v3; // esi@1
  signed int result; // eax@3
  void *v5; // edi@4

  v3 = (int)_this;

 for (i = 0; i < 256; ++i)
 {
  _this->pBaseColors[0][i * 3 + 0] = i;
  _this->pBaseColors[0][i * 3 + 1] = i;
  _this->pBaseColors[0][i * 3 + 2] = i;
 }
 class35_sub_489BE0(_this, 0);

 result = _this->dword_267AC8;
 if (_this->dword_267AC8 < 50)
 {
  v5 = &_this->array_267A00[result];
  memset(v5, 0, 4 * (50 - result));

  result = 0;
 }
 return result;
}





//----- (004547A3) --------------------------------------------------------
unsigned int CMapStats_FindLocation(struct CMapStats *_this, const char *pLocationName)
{
 int i;

 for (i = 1; i < _this->uNumMaps; ++i)
   if (!lstrcmpiA((char *)_this->pMapInfos[i].pLocationFilename, pLocationName))
      return i;
 return 0;
}



//----- (0047CF9C) --------------------------------------------------------
int class51_sub_47CF9C(struct class51 *_this)
{
  int v1; // edi@1
  int v3; // ebx@2

 strcpy((char *)_this->string_000000, "blank");
 strcpy((char *)_this->pFileName, "default.odm");
 strcpy((char *)_this->pFileDescription, "MM6 Outdoor v1.00");
 strcpy((char *)_this->pSkyTextureName, "sky043");
 strcpy((char *)_this->pGroundTileset, "hm005");

  v1 = 0;
  if (_this->uNumBModels > 0 )
  {
    v3 = 0;
    do
    {
      sub_478389(v3 + *((_DWORD *)_this + 54) + 68);
      ++v1;
      v3 += 188;
    }
    while (v1 < _this->uNumBModels);
  }
 _this->uNumBModels = 0;
 _this->dword_0004C0 = 0;

 mem_mng.DeleteBuffer( (void *)_this->pBModels);
 _this->pBModels = 0;

 mem_mng.DeleteBuffer( (void *)_this->ptr_0004C4);
 _this->ptr_0004C4 = 0;

 class51_FreeGeodata(&_this->struct_0000B4);

 mem_mng.DeleteBuffer( (void *)_this->ptr_0000D4);
 _this->ptr_0000D4 = 0;

 mem_mng.DeleteBuffer( (void *)_this->ptr_0000E4);
 _this->ptr_0000E4 = 0;

 mem_mng.DeleteBuffer( (void *)_this->ptr_0000E0);
 _this->ptr_0000E0 = 0;

 mem_mng.DeleteBuffer( (void *)pTerrainNormals);
 pTerrainNormals = 0;

 return 0;
}






//----- (0044EEA7) --------------------------------------------------------
char CGame_sub_44EEA7(struct CGame *_this)
{
  int v1; // esi@1
  double v2; // st7@2
  char result; // al@9
  float v4; // ST00_4@9
  unsigned int v5; // eax@14
  int v6; // eax@21
  int v7; // [sp+4h] [bp-24h]@2
  int v8; // [sp+8h] [bp-20h]@2
  int *v10; // [sp+10h] [bp-18h]@2
  int v11; // [sp+14h] [bp-14h]@2
  POINT pt;

  v1 = (int)_this;
  ++qword_5C6DF0;
  class02_sub_48AC65(_this->class02_obj);
  GUICursor_GetMousePos(_this->class03_obj, &pt);
  if ( sub_4637E0() )
  {
    v11 = (int)&dword_F93E44;
    v10 = &dword_F93E30;
    v8 = pt.y;
    v7 = pt.x;
    v2 = sub_43643E();
  }
  else
  {
    if (_this->dword_000E24 & 0x10)
    {
      v11 = (int)&dword_F93E44;
      v10 = &dword_F93E1C;
    }
    else
    {
      if ( !(byte_5C6DEC & 1) )
      {
        byte_5C6DEC |= 1u;
        dword_5C6DE0 = -1;
        dword_5C6DD8 = 0;
        dword_5C6DDC = 2;
        dword_5C6DE4 = 0;
        dword_5C6DE8 = 0;
        atexit(0);
      }
      v11 = (int)&dword_F93E44;
      v10 = &dword_5C6DD8;
    }
    v2 = 5120.0;
    v8 = pt.y;
    v7 = pt.x;
  }

 v4 = v2;
 Game_Pick(pGame, v4, v7, v8, false, (int)v10, v11);
 _this->class04_obj->std__vector_000004_size = 0;
 _this->class04_obj->std__vector_183808_size = 0;

  runtime_warning(seems odd);
  //pClass58_global->dword_308004 = 0;
  //pClass58_global->dword_308008 = 0;
  pClass58_global->std__vector_30B00C[1022] = 0;
  pClass58_global->std__vector_30B00C[1023] = 0;

  result = CGame_sub_44F07B(_this);
  if ( result )
  {
    if (pGame->uSomeFlags & 0x08)
      _this->class10_obj->dword_000004 &= 0xFFFFFF00;
    if ( pD3DRenderer->pRenderD3D3 )
    {
      if ( dword_6BE360 == 2 )
      {
        v5 = sub_47C370();
        dword_EF524C = v5 & 0xFFFFFF;
      }
    }
    if ( *(_BYTE *)(v1 + 0xE21) & 4 )
      _this->dword_000E24 |= 0x01;
    if ( !pD3DRenderer->pRenderD3D3 )
    {
      if ( dword_6BE360 == 2 )
      {
        if ( dword_51B6DC )
        {
          *(_DWORD *)(v1 + 3620) |= 1u;
          *(_QWORD *)(v1 + 3600) = qword_5C6DF0;
        }
      }
    }
    v6 = qword_5C6DF0 - _this->dword_000E10;
    if ( v6 == 1 )
    {
      if ( !((unsigned __int64)(qword_5C6DF0 - *(unsigned __int64 *)&_this->dword_000E10) >> 32) )
        _this->dword_000E24 |= v6;
    }
    if (_this->dword_000E18 != pStationaryLightsStack->uNumStationaryLightsActive )
    {
      _this->dword_000E24 |= 1;
      _this->dword_000E18 = pStationaryLightsStack->uNumStationaryLightsActive;
    }
    sub_44E904(_this);
    result = 1;
  }
  return result;
}



//----- (0048AC65) --------------------------------------------------------
int class02_sub_48AC65(struct class02 *_this)
{
  int v3; // edi@1
  struct class02_stru0 *v4; // esi@2
  int v5; // eax@3
  char v6; // sf@4
  double v8; // st7@12
  int v9; // eax@12
  double v10; // st7@14
  float v12; // ST3C_4@14
  float v14; // ST3C_4@14
  float v16; // ST3C_4@14
  signed int v19; // [sp+38h] [bp-14h]@1
  signed int v20; // [sp+3Ch] [bp-10h]@1
  int v21; // [sp+40h] [bp-Ch]@1
  int v22; // [sp+44h] [bp-8h]@12
 int i;

  v3 = cClock2.dword_000004 == 0 ? cClock1.int_00001C : 0;

  v20 = 0;
  v19 = 500;

  v21 = cClock2.dword_000004 == 0 ? cClock1.int_00001C : 0;
  
 for (i = _this->dword_00E424; i <= _this->dword_00E428; ++i)
 {
  v4 = &_this->array_000000[i];

   v5 = v4->dword_000000;
    if (v5)
    {
     v6 = v4->dword_000020 - v3 < 0;
        v4->dword_000020 -= v3;
        if ( v6 )
        {
          v4->dword_000000 = 0;
        }
        else
        {
          if ( BYTE1(v5) & 2 )
          {
           v4->flt_00002C = v4->flt_000004;
            v4->flt_000030 = v4->flt_000008;
            v4->flt_000034 = v4->flt_00000C;
          }
          if ( v5 & 1 )
            v4->flt_000018 -= (double)v21 * 5.0;
          if ( v5 & 8 )
          {
            v4->flt_000004 += (double)(rand() % 5 - 2) * (double)v21 / 16;
            v4->flt_000008 += (double)(rand() % 5 - 2) * (double)v21 / 16;
            v4->flt_00000C += (double)(rand() % 5 + 4) * (double)v21 / 16;
          }
          v8 = (double)v21 / 128.0;
          v9 = v3 * v4->dword_000038 / 16;
          v4->flt_000004 += v8 * v4->flt_000010;
          v4->flt_000008 += v8 * v4->flt_000014;
          v4->flt_00000C += v8 * v4->flt_000018;
          v4->dword_00003Ñ += v9;
          v22 = 2 * v4->dword_000020;
          if (v22 > 255)
            v22 = 255;

          v10 = (double)v22 / 255.0;
          v12 = floorf((double)v4->byte_00001E * v10 + 1);
          v14 = floorf((double)v4->byte_00001D * v10 + 1);
          v16 = floorf((double)v4->byte_00001C * v10 + 1);
          v4->dword_000064 = (unsigned int)(v16) | (((unsigned int)(v14) | ((unsigned int)(v12) << 8)) << 8);
          if ( i < v19 )
            v19 = i;
          if ( i > v20 )
            v20 = i;
        }
    }
 }
 
 _this->dword_00E424 = v19;
 _this->dword_00E428 = v20;
 return v19;
}



//----- (0044F07B) --------------------------------------------------------
bool CGame_sub_44F07B(struct CGame *_this)
{
 if (!class14_IsKeyHeld(_this->class14_obj, VK_SHIFT) &&
     !class14_IsKeyHeld(_this->class14_obj, VK_LSHIFT) &&
     !class14_IsKeyHeld(_this->class14_obj, VK_LSHIFT) ||
     !class14_IsKeyPressed(_this->class14_obj, VK_F11))
   class14_IsKeyPressed(_this->class14_obj, VK_F11);

 return true;
}




//----- (0045B0A9) --------------------------------------------------------
bool class14_IsKeyHeld(struct class14 *_this, int vKey)
{
  char result; // al@2
  void *v3; // esi@2
  char v4; // bl@2

  if ( *(_BYTE *)(&_this->dword_000004) )
  {
    v3 = (void *)pAsyncKeyboard;
    EnterCriticalSection(&pGame->class01_obj->cs4);
    v4 = *((_BYTE *)v3 + (unsigned __int8)sub_45B57D(v3, vKey) + 265) >> 7;
    LeaveCriticalSection(&pGame->class01_obj->cs4);
    result = v4;
  }
  else
  {
    result = (GetAsyncKeyState(vKey) & 0x8001) != 0;
  }
  return result;
}


//----- (0045B0CE) --------------------------------------------------------
bool class14_IsKeyPressed(struct class14 *_this, int vKey)
{
  char result; // al@2
  void *v3; // esi@2
  char v4; // bl@2

  if ( *(_BYTE *)(&_this->dword_000004) )
  {
    v3 = (void *)pAsyncKeyboard;
    EnterCriticalSection(&pGame->class01_obj->cs4);
    v4 = *((_BYTE *)v3 + (unsigned __int8)sub_45B57D(v3, vKey) + 521) >> 7;
    LeaveCriticalSection(&pGame->class01_obj->cs4);
    result = v4;
  }
  else
  {
    result = GetAsyncKeyState(vKey) & 1;
  }
  return result;
}






//----- (004376E7) --------------------------------------------------------
void class08_CreateWorldMatrixAndSomeStuff(struct class08 *_this)
{
  void *v3; // esi@1
  double v4; // st7@1
  int result; // eax@5

  struct Matrix m0;
  //char v8[0x24]; // [sp+10h] [bp-B8h]@1

  struct Matrix m3;
  /*float v9[4*array_size_unknown]; // [sp+34h] [bp-94h]@1
  char v10[12]; // [sp+38h] [bp-90h]@2
  char v11[20]; // [sp+44h] [bp-84h]@2*/

  struct Matrix m4;
  /*float v12; // [sp+58h] [bp-70h]@1
  float v13; // [sp+5Ch] [bp-6Ch]@1
  float v14; // [sp+60h] [bp-68h]@1
  float v15; // [sp+64h] [bp-64h]@1
  float v16; // [sp+68h] [bp-60h]@1
  float v17; // [sp+6Ch] [bp-5Ch]@1
  float v18; // [sp+70h] [bp-58h]@1
  float v19; // [sp+74h] [bp-54h]@1
  float v20; // [sp+78h] [bp-50h]@1*/

  struct Matrix m1;
   /*float v21; // [sp+7Ch] [bp-4Ch]@1
  float v22; // [sp+80h] [bp-48h]@1
  float v23; // [sp+84h] [bp-44h]@1
  float v24; // [sp+88h] [bp-40h]@1
  float v25; // [sp+8Ch] [bp-3Ch]@1
  int v26; // [sp+90h] [bp-38h]@1
  float v27; // [sp+94h] [bp-34h]@1
  float v28; // [sp+98h] [bp-30h]@1
  float v29; // [sp+9Ch] [bp-2Ch]@1*/

  struct Matrix m2;
  /*float v30; // [sp+A0h] [bp-28h]@1
  float v31; // [sp+A4h] [bp-24h]@1
  float v32; // [sp+A8h] [bp-20h]@1
  float v33; // [sp+ACh] [bp-1Ch]@1
  float v34; // [sp+B0h] [bp-18h]@1
  float v35; // [sp+B4h] [bp-14h]@1
  float v36; // [sp+B8h] [bp-10h]@1
  float v37; // [sp+BCh] [bp-Ch]@1
  float v38; // [sp+C0h] [bp-8h]@1*/

  float v39; // [sp+C4h] [bp-4h]@1
 int i;

  v3 = _this;

  v39 = cos(0.0);
  v4 = sin(0.0);

 //RotationZ(0)
 m2._11 = cosf(0);                    m2._12 = sinf(0);                     m2._13 = 0;
 m2._21 = -sinf(0);                   m2._22 = cosf(0);                     m2._23 = 0;
 m2._31 = 0;                          m2._32 = 0;                           m2._33 = 1;

 //RotationX(some_other_angle)
 m1._11 = 1;                          m1._12 = 0;                              m1._13 = 0;
 m1._21 = 0;                          m1._22 = pOldCamera->fRotationXCosine;   m1._23 = pOldCamera->fRotationXSine;
 m1._31 = 0;                          m1._32 = -pOldCamera->fRotationXSine;    m1._33 = pOldCamera->fRotationXCosine;
  
 //RotationY(some_angle)
 m4._11 = pOldCamera->fRotationYCosine;  m4._12 = 0;                           m4._13 = -pOldCamera->fRotationYSine;
 m4._21 = 0;                             m4._22 = 1;                           m4._23 = 0;
 m4._31 = pOldCamera->fRotationYSine;    m4._32 = 0;                           m4._33 = pOldCamera->fRotationYCosine;


 MatrixMultiply(&m2, &m4, &m0); //m0 = RotationZ(0) * RotationY(some_angle)
 MatrixMultiply(&m1, &m0, &m3); //m3 = RotationX(some_other_angle) * RotationZ(0) * RotationY(some_angle)
 
 for (i = 0; i < 3; ++i)
 {
  _this->class26_obj1.array_000004[i] = m3.v[1][i];
  _this->class26_obj2.array_000004[i] = m3.v[0][i];
  _this->class26_obj3.array_000004[i] = m3.v[2][i];
 }

 _this->flt_0000D0 = (double)pOldViewport->dword_000020 * 0.8814736008644104;
 _this->flt_0000D4 = (double)pOldViewport->dword_000024 * 0.8814736008644104;
 _this->flt_0000D8 = 1.1344639f;

 _this->flt_0000C4 = max(_this->flt_0000D0, _this->flt_0000D4);
 _this->flt_0000C8 = (double)pOldViewport->dword_000028;
 _this->flt_0000CC = (double)(pOldViewport->dword_00002C - pOldViewport->uScreenY);
}


//----- (004374E8) --------------------------------------------------------
void class08_PrepareSomeVectors(struct class08 *_this)
{
 double v3;

 struct class26 local_0C;
/*  char v7[0x04]; // [sp+Ch] [bp-24h]@1
  float v8; // [sp+10h] [bp-20h]@1
  float v9; // [sp+14h] [bp-1Ch]@1
  float v10; // [sp+18h] [bp-18h]@1
*/
  //int v13; // [sp+2Ch] [bp-4h]@1

 class26_ctor(&local_0C);

 v3 = atan(2.0 / _this->flt_0000D8 * _this->flt_0000C4 / _this->flt_0000D0);

 local_0C.array_000004[0] = -sin(v3);
 local_0C.array_000004[1] = 0;
 local_0C.array_000004[2] = cos(v3);
 class08_sub_437607(_this, &local_0C, &_this->std__vector_000034[0]);

 local_0C.array_000004[0] = sin(v3);
 class08_sub_437607(_this, &local_0C, &_this->std__vector_000034[1]);


 v3 = atan(2.0 / _this->flt_0000D8 * _this->flt_0000C4 / (_this->flt_0000D4 + 0.5));

 local_0C.array_000004[0] = 0;
 local_0C.array_000004[1] = sin(v3);
 local_0C.array_000004[2] = cos(v3);
 class08_sub_437607(_this, &local_0C, &_this->std__vector_000034[2]);

 local_0C.array_000004[1] = -sin(v3);
 class08_sub_437607(_this, &local_0C, &_this->std__vector_000034[3]);

 class26_default_ctor(&local_0C);
}

//----- (00437607) --------------------------------------------------------
void class08_sub_437607(struct class08 *_this, struct class26 *a2, struct class26_placeholder *a3)
{
 struct class26 local_08;

 class08_Vec3Transform(_this, a2, &a3->objClass26);
  
 class26_ctor(&local_08);
 local_08.array_000004[0] = (double)pOldCamera->dword_000000;
 local_08.array_000004[1] = (double)pOldCamera->dword_000004;
 local_08.array_000004[2] = (double)pOldCamera->dword_000008;

 a3->flt_000014 = class26_DotProduct(&local_08, &a3->objClass26) + 0.00009999999747378752;

 class26_default_ctor(&local_08);
}

float class26_DotProduct(struct class26 *v1, struct class26 *v2)
{
 return v1->array_000004[0] * v2->array_000004[0] +
        v1->array_000004[1] * v2->array_000004[1] +
        v1->array_000004[2] * v2->array_000004[2];
}

//----- (00437691) --------------------------------------------------------
void class08_Vec3Transform(struct class08 *_this, struct class26 *pVec, struct class26 *pOut)
{
 pOut->array_000004[0] = _this->class26_obj2.array_000004[2] * pVec->array_000004[0] +
                         _this->class26_obj1.array_000004[2] * pVec->array_000004[1] +
                         _this->class26_obj3.array_000004[2] * pVec->array_000004[2];

 pOut->array_000004[1] = _this->class26_obj2.array_000004[0] * pVec->array_000004[0] +
                         _this->class26_obj1.array_000004[0] * pVec->array_000004[1] +
                         _this->class26_obj3.array_000004[0] * pVec->array_000004[2];

 pOut->array_000004[2] = _this->class26_obj2.array_000004[1] * pVec->array_000004[0] +
                         _this->class26_obj1.array_000004[1] * pVec->array_000004[1] +
                         _this->class26_obj3.array_000004[1] * pVec->array_000004[2];
}



//----- (00469E3B) --------------------------------------------------------
int GUICursor_sub_469E3B(struct GUICursor *_this)
{
  int result; // eax@1
  int v2; // edx@3
  int v3; // esi@3
  int v4; // edi@4
  int v5; // ebx@5
  int v6; // esi@6
  int v7; // [sp+4h] [bp-Ch]@2
  int v8; // [sp+8h] [bp-8h]@2
  int v9; // [sp+Ch] [bp-4h]@2

  result = (int)_this->ptr_00003C;
  if ( result )
  {
    v9 = (int)_this->ptr_00003C;
    v7 = pD3DRenderer->uTargetSurfacePitch;
    v8 = (int)pD3DRenderer->pTargetSurface;
    result = _this->dword_000044;
    if ( result < _this->dword_00004C )
    {
      v3 = _this->dword_000048;
      v2 = pD3DRenderer->uTargetSurfacePitch * result;
      do
      {
        v4 = _this->dword_000040;
        if ( v4 < v3 )
        {
          v5 = v8 + 2 * (v2 + v4);
          do
          {
            v6 = v9;
            v9 += 2;
            ++v4;
            *(_WORD *)v5 = *(_WORD *)v6;
            v3 = _this->dword_000048;
            v5 += 2;
          }
          while ( v4 < v3 );
        }
        v2 += v7;
        ++result;
      }
      while ( result < _this->dword_00004C );
    }
  }
  return result;
}



//----- (004239A7) --------------------------------------------------------
void OldCamera_CalculateSinCos(struct OldCamera *_this)
{
 double angle;

 angle = 2.0 * 3.1415926535897931 * ((double)_this->sRotationY / 2048);
 _this->fRotationYSine = sin(angle);
 _this->fRotationYCosine = cos(angle);


 if (byte_4D8410[572] && *(_BYTE *)(&pGame->uSomeFlags) & 0x80 || dword_6BE360 == 1)
   angle = 2 * 3.1415926535897931 * ((double)_this->sRotationX / 2048);
 else
   angle = -2 * 3.1415926535897931 * ((double)_this->sRotationX / 2048);

 _this->fRotationXSine = sin(angle);
 _this->fRotationXCosine = cos(angle);

 _this->some_angle_int_sine = class59_SinCos(pClass59_global, _this->sRotationY - pClass59_global->uIntegerHalfPi);
 _this->some_angle_int_cosine = class59_SinCos(pClass59_global, _this->sRotationY);
 _this->some_other_angle_int_sine = class59_SinCos(pClass59_global, _this->sRotationX - pClass59_global->uIntegerHalfPi);
 _this->some_other_angle_int_cosine = class59_SinCos(pClass59_global, _this->sRotationX);
}



//----- (0042394D) --------------------------------------------------------
void OldCamera_SetPerspective(struct OldCamera *_this, signed int sViewingAngle, signed int sViewportWidth, signed int sViewportHeight)
{
 int v0;

 v0 = 0.5 * (double)(sViewportWidth) / tan((double)(sViewingAngle / 2) * 0.017453290000000000) + 0.5;

 _this->flt_00001C = v0;
 _this->flt_000020 = 65536.0 / v0;
}

void OldCamera_ctor(struct OldCamera *_this)
{
 memset(_this, 0, sizeof(struct OldCamera));
}



//----- (004C039C) --------------------------------------------------------
void class26_default_ctor(struct class26 *_this)
{
 _this->detor_ptr = class26_detor;
}


//----- (00402CAE) --------------------------------------------------------
int class59_SinCos(struct class59 *_this, int a2)
{
  int v2; // eax@1

  //a2: (angle - uIntegerHalfPi)    for  sin(angle)
  //    (angle)                     for  cos(angle)

  v2 = _this->uDoublePiMask & a2;
  
  if ( v2 > _this->uIntegerPi )
    v2 = _this->uIntegerDoublePi - v2;
  if ( v2 >= _this->uIntegerHalfPi )
    return -_this->pCosTable[_this->uIntegerPi - v2];
  else
    return _this->pCosTable[v2];
}

//----- (0045281E) --------------------------------------------------------

//Calculates atan2(y/x)
//return value: angle in integer format (multiplier of Pi/1024)  
int class59_Atan2(struct class59 *_this, int X, int Y)
{
  signed int quadrant;
  __int64 dividend;
  int quotient;
  int lowIdx;
  int highIdx;
  int angle;

  if ( abs(X) < 65536 )
  {
    if ( (abs(Y) >> 15) >= abs(X) )
      X = 0;
  }

  if ( !X )
  {
    if ( Y > 0 )
    {
      return _this->uIntegerHalfPi;   //Pi/2
    }
    else
    {
      return _this->uIntegerHalfPi + _this->uIntegerPi; //3*(Pi/2)
    }
  }

  if ( Y )
  {
    if ( X < 0 )
    {
      X = -X;
      if ( Y > 0 )
      {
        quadrant = 4;        
      }
      else
      {
        quadrant = 3;        
      }      
    }
    else
    {
      if ( Y > 0 )
      {
        quadrant = 1;       
      }
      else
      {
        quadrant = 2;
      }      
    }

    if ( Y < 0 )
      Y = -Y;

    LODWORD(dividend) = Y << 16;
    HIDWORD(dividend) = Y >> 16;
    quotient = dividend / X;        

    //looks like binary search
    {
      int i;
      highIdx = _this->uIntegerHalfPi;
      lowIdx = 0;

      for (i = 0; i < 6; ++i)
      {        
        if (quotient <= _this->pTanTable[(lowIdx + highIdx) / 2])      
          highIdx = (lowIdx + highIdx) / 2;
        else
          lowIdx = (lowIdx + highIdx) / 2;    
      }
    }

    angle = lowIdx + 1;
    while ( angle < (highIdx - 1) && quotient >= _this->pTanTable[angle] )
      ++angle;

    switch (quadrant)
    {
    case 1: //X > 0, Y > 0
      return angle;        

    case 2: //X > 0, Y < 0
      return _this->uIntegerDoublePi - angle;   //2*Pi - angle

    case 3: //X > 0, Y < 0
      return _this->uIntegerPi + angle;        //Pi + angle 

    case 4: //X < 0, Y > 0
      return _this->uIntegerPi - angle;        //Pi - angle  
    }

    //should newer get here
    return 0;
  }

  if ( X < 0 )    //Y == 0, X < 0
    return _this->uIntegerPi;  

  return 0;
}


//----- (00436BB7) --------------------------------------------------------
void class08_sub_436BB7(struct class08 *_this, struct RenderVertex *a2, int a3, char a4)
{
  double v7; // st7@7
  double v8; // st7@9
  double v9; // st6@10
  double v10; // st5@12
  double v11; // st7@16
  double v12; // st6@17
  double v13; // st5@19
  float v14; // [sp+14h] [bp+Ch]@12
  float v15; // [sp+14h] [bp+Ch]@19
 int i;

 for (i = 0; i < a3; ++i)
 {
      if ( byte_4D8410[572] && pGame->uSomeFlags & 0x80 || dword_6BE360 == 1 )
      {
        v7 = 1.0 / a2[i].flt_00000C;
        a2[i].flt_000018 = a2[i].flt_000010 * _this->flt_0000C4 * v7 + _this->flt_0000C8;
        a2[i].flt_00001C = (double)pOldViewport->uGameW
                           - (a2[i].flt_000014 * _this->flt_0000C4 * v7 + _this->flt_0000CC);
      }
      else
      {
        sub_481D77(&a2[i]);
      }
      if ( a4 )
      {
        v8 = (double)pOldViewport->uGameZ;
        if ( v8 >= a2[i].flt_000018)
          v9 = a2[i].flt_000018;
        else
          v9 = v8;
        v10 = (double)pOldViewport->uGameX;
        v14 = v10;
        if ( v10 <= v9 )
        {
          if ( v8 >= a2[i].flt_000018)
            v8 = a2[i].flt_000018;
        }
        else
           v8 = v14;
        a2[i].flt_000018 = v8;

        v11 = (double)pOldViewport->uGameW;
        if ( v11 >= a2[i].flt_00001C)
          v12 = a2[i].flt_00001C;
        else
          v12 = v11;
        v13 = (double)pOldViewport->uGameY;
        v15 = v13;
        if ( v13 <= v12 )
        {
          if ( v11 >= a2[i].flt_00001C)
            v11 = a2[i].flt_00001C;
        }
        else
           v11 = v15;
        a2[i].flt_00001C= v11;
      }
  }
}



//----- (00486089) --------------------------------------------------------
void sub_486089_NormalizeVector(struct struct8 *_this)
{
  int v1; // esi@1
  double v2; // st5@1
  double v3; // st6@1
  double v4; // st7@1
  double v5; // st7@1
  float v8; // ST24_4@2
  float v9; // ST20_4@2
  float v11; // ST18_4@2
  float v13; // ST14_4@2

  v1 = (int)_this;
  v5 = (double)_this->dword_000018;
  v3 = (double)_this->dword_00001C;
  v2 = (double)_this->dword_000020;
  v4 = sqrt(v2 * v2 + v3 * v3 + v5 * v5);
  if ( v4 == 0.0 )
  {
   _this->dword_000018 = 0;
   _this->dword_00001C = 0;
   _this->dword_000020 = 65536;
  }
  else
  {
    v8 = 1.0 / v4;

    v9 = v8 * v5 * 65536.0;
    _this->dword_000018 = floorf(v9 + 0.5f);

    v11 = v8 * v3 * 65536.0;
    _this->dword_00001C = floorf(v11 + 0.5f);

    v13 = v8 * v2 * 65536.0;
    _this->dword_000020 = floorf(v13 + 0.5f);
  }
}




//----- (0048600E) --------------------------------------------------------
void struct9_sub_47A59E_ComputeSinCos(struct struct9 *_this)
{
 _this->camera_rotation_y_int_sine = class59_SinCos(pClass59_global, pOldCamera->sRotationY - pClass59_global->uIntegerHalfPi);
 _this->camera_rotation_x_int_sine = class59_SinCos(pClass59_global, pOldCamera->sRotationX - pClass59_global->uIntegerHalfPi);
 _this->camera_rotation_y_int_cosine = class59_SinCos(pClass59_global, pOldCamera->sRotationY);
 _this->camera_rotation_x_int_cosine = class59_SinCos(pClass59_global, pOldCamera->sRotationX);
}

//----- (0048616B) --------------------------------------------------------
int class57_sub_48616B(struct class57 *_this, int a2, int a3, int a4, int a5, int a6, int a7)
{
 int v1;
  int v7; // eax@1
  int v8; // edx@1
  int v9; // ebx@1
  int v10; // edi@1
  int v11; // esi@1
  int v12; // eax@2
  int v13; // esi@2
  int v14; // ST10_4@3
  int v15; // esi@3
  int v16; // eax@5
  int v17; // ST0C_4@6
  int v18; // eax@8
  int v19; // ST0C_4@9
  int result; // eax@10
  int v21; // eax@10
  int v22; // edx@10
  int v23; // eax@10
  int v24; // [sp+14h] [bp-14h]@1
  int v25; // [sp+18h] [bp-10h]@1
  int v26; // [sp+1Ch] [bp-Ch]@1
  int v27; // [sp+24h] [bp-4h]@1
  int v28; // [sp+30h] [bp+8h]@7
  int v29; // [sp+30h] [bp+8h]@10
  int v30; // [sp+3Ch] [bp+14h]@10

  v1 = (int)_this;
  v25 = pStruct9_global->camera_rotation_x_int_cosine;
  v9 = pStruct9_global->camera_rotation_y_int_sine;
  v27 = pStruct9_global->camera_rotation_x_int_sine;
  v11 = -pOldCamera->dword_000004;
  v10 = pStruct9_global->camera_rotation_y_int_cosine;
  v26 = -pOldCamera->dword_000008;
  v24 = -pOldCamera->dword_000000;
  v7 = pStruct9_global->camera_rotation_y_int_cosine * -pOldCamera->dword_000000;
  v8 = v7 + pStruct9_global->camera_rotation_y_int_sine * -pOldCamera->dword_000004;
  if (pOldCamera->sRotationX)
  {
    v14 = v7 + pStruct9_global->camera_rotation_y_int_sine * -pOldCamera->dword_000004;
    v15 = pStruct9_global->camera_rotation_y_int_cosine * v11 - pStruct9_global->camera_rotation_y_int_sine * v24;
    _this->dword_000000 = ((unsigned __int64)(v8 * pStruct9_global->camera_rotation_x_int_cosine) >> 16)
                    + ((unsigned __int64)(-65536 * pOldCamera->dword_000008 * pStruct9_global->camera_rotation_x_int_sine) >> 16);
    _this->dword_000004 = v15;
    v13 = v25;
    v12 = ((unsigned __int64)((v26 << 16) * v25) >> 16) - ((unsigned __int64)(v14 * v27) >> 16);
  }
  else
  {
    _this->dword_000000 = v8;
    _this->dword_000004 = (__int64)pStruct9_global->camera_rotation_y_int_cosine * v11 - (__int64)pStruct9_global->camera_rotation_y_int_sine * v24;
    v13 = v25;
    v12 = v26 << 16;
  }
  _this->dword_000008 = v12;
  if (pOldCamera->sRotationX)
  {
    v17 = ((unsigned __int64)(a2) * v10 >> 16) + ((unsigned __int64)(a3) * v9 >> 16);
    _this->dword_00000C = ((unsigned __int64)(v17) * v13 >> 16) + ((unsigned __int64)(a4) * v27 >> 16);
    _this->dword_000010 = ((unsigned __int64)(a3) * v10 >> 16) - ((unsigned __int64)(a2) * v9 >> 16);
    v16 = ((unsigned __int64)(a4) * v13 >> 16) - ((unsigned __int64)(v17) * v27 >> 16);
  }
  else
  {
    _this->dword_00000C = ((unsigned __int64)(a2) * v10 >> 16) + ((unsigned __int64)(a3) * v9 >> 16);
    _this->dword_000010 = ((unsigned __int64)(a3) * v10 >> 16) - ((unsigned __int64)(a2) * v9 >> 16);
    v16 = a4;
  }
  _this->dword_000014 = v16;
  v28 = v10;
  if (pOldCamera->sRotationX)
  {
    v19 = ((unsigned __int64)(a5) * v28 >> 16) + ((unsigned __int64)(a6) * v9 >> 16);
    _this->dword_000018 = ((unsigned __int64)(v19) * v13 >> 16) + ((unsigned __int64)(a7) * v27 >> 16);
    _this->dword_00001C = ((unsigned __int64)(a6) * v10 >> 16) - ((unsigned __int64)(a5) * v9 >> 16);
    v18 = ((unsigned __int64)(a7) * v13 >> 16) - ((unsigned __int64)(v19) * v27 >> 16);
  }
  else
  {
    _this->dword_000018 = ((unsigned __int64)(a5) * v28 >> 16) + ((unsigned __int64)(a6) * v9 >> 16);
    _this->dword_00001C = ((unsigned __int64)(a6) * v10 >> 16) - ((unsigned __int64)(a5) * v9 >> 16);
    v18 = a7;
  }
 _this->dword_000018 = -_this->dword_000018;
 _this->dword_00001C = -_this->dword_00001C;
 _this->dword_000020 = v18;
  v21 = _this->dword_00000C;
 _this->dword_000020 = -_this->dword_000020;
 v22 = ((unsigned __int64)(v21) * _this->dword_000000 >> 16)
      + ((unsigned __int64)(_this->dword_000010) * _this->dword_000004 >> 16)
      + ((unsigned __int64)(_this->dword_000014) * _this->dword_000008 >> 16);
  v29 = _this->dword_000018;
  v23 = _this->dword_000000;
 _this->dword_000024 = v22;
  v30 = (unsigned __int64)(v29) * v23 >> 16;
  result = (unsigned __int64)(_this->dword_00001C) * _this->dword_000004 >> 16;
 _this->dword_000028 = v30 + result + ((unsigned __int64)(_this->dword_000020) * _this->dword_000008 >> 16);
  return result;
}

//----- (0048694B) --------------------------------------------------------
int class57_sub_48694B(struct class57 *_this)
{
  int result; // eax@1
  int v2; // eax@1
  int v3; // ST04_4@1
  int v4; // ST00_4@1
  int v5; // eax@1
  int v6; // ST0C_4@1

  v2 = _this->dword_00000C;
  _this->dword_000018 = -_this->dword_000018;
  _this->dword_00001C = -_this->dword_00001C;
  _this->dword_000020 = -_this->dword_000020;
  v3 = (unsigned __int64)(v2 * _this->dword_000000) >> 16;
  v4 = _this->dword_000018;
  v5 = _this->dword_000000;
  _this->dword_000024 = v3 +
                         ((unsigned __int64)(_this->dword_000010 * _this->dword_000004) >> 16) +
                         ((unsigned __int64)(_this->dword_000014 * _this->dword_000008) >> 16);
  v6 = (unsigned __int64)(v4 * v5) >> 16;
  result = (unsigned __int64)(_this->dword_00001C * _this->dword_000004) >> 16;
  _this->dword_000028 = v6 + result + ((unsigned __int64)(_this->dword_000020 * _this->dword_000008) >> 16);
  return result;
}

//----- (00485F64) --------------------------------------------------------
int sub_485F64(struct struct9 *_this)
{
  int v1; // eax@1
  int v2; // eax@2
  signed __int64 v4; // qtt@4
  signed int v5; // eax@4


 _this->dword_000010 = 75;
  v1 = pClass59_global->uPiMask & 0xD5;
  if ( v1 >= pClass59_global->uIntegerHalfPi)
    v2 = -pClass59_global->pTanTable[pClass59_global->uIntegerPi - v1];
  else
    v2 = pClass59_global->pTanTable[v1];
  LODWORD(v4) = (struct_576FE8.dword_000008 - struct_576FE8.dword_000000) << 31;
  HIDWORD(v4) = (struct_576FE8.dword_000008 - struct_576FE8.dword_000000) << 15 >> 16;
  v5 = (signed int)(v4 / v2) >> 16;
 _this->dword_000014 = v5;
 _this->dword_000018 = 65536 / v5;
 _this->dword_00004C = 360000;
 _this->dword_000050 = 115;
  data_6BE060.dword_6BE064 = 1;
  struct9_sub_47A59E_ComputeSinCos(_this);
  return 0;
}




//----- (0049B525) --------------------------------------------------------
void class58_sub_49B525(struct class58 *_this, int a2)
{
 if (!a2)
 {
  class36_global0.std__vector_000004_size = 0;
  class36_global0.dword_000A08 = 0;
 }

 runtime_warning(seems odd);
 //_this->dword_308004 = 0;
 _this->std__vector_30B00C[1022] = 0;
}


void class59_ctor(struct class59 *_this)
{
  double v3; // ST18_8@2
  signed int v8; // [sp+20h] [bp-4h]@1
 int i;
 unsigned char pTanTable[0x820] = 
 {
	0x00, 0x00, 0x00, 0x00, 0xC9, 0x00, 0x00, 0x00, 0x92, 0x01, 0x00, 0x00, 0x5B, 0x02, 0x00, 0x00, 
	0x24, 0x03, 0x00, 0x00, 0xED, 0x03, 0x00, 0x00, 0xB7, 0x04, 0x00, 0x00, 0x80, 0x05, 0x00, 0x00, 
	0x49, 0x06, 0x00, 0x00, 0x12, 0x07, 0x00, 0x00, 0xDB, 0x07, 0x00, 0x00, 0xA5, 0x08, 0x00, 0x00, 
	0x6E, 0x09, 0x00, 0x00, 0x37, 0x0A, 0x00, 0x00, 0x01, 0x0B, 0x00, 0x00, 0xCA, 0x0B, 0x00, 0x00, 
	0x94, 0x0C, 0x00, 0x00, 0x5D, 0x0D, 0x00, 0x00, 0x27, 0x0E, 0x00, 0x00, 0xF1, 0x0E, 0x00, 0x00, 
	0xBA, 0x0F, 0x00, 0x00, 0x84, 0x10, 0x00, 0x00, 0x4E, 0x11, 0x00, 0x00, 0x18, 0x12, 0x00, 0x00, 
	0xE2, 0x12, 0x00, 0x00, 0xAC, 0x13, 0x00, 0x00, 0x77, 0x14, 0x00, 0x00, 0x41, 0x15, 0x00, 0x00, 
	0x0C, 0x16, 0x00, 0x00, 0xD6, 0x16, 0x00, 0x00, 0xA1, 0x17, 0x00, 0x00, 0x6C, 0x18, 0x00, 0x00, 
	0x37, 0x19, 0x00, 0x00, 0x02, 0x1A, 0x00, 0x00, 0xCD, 0x1A, 0x00, 0x00, 0x98, 0x1B, 0x00, 0x00, 
	0x64, 0x1C, 0x00, 0x00, 0x2F, 0x1D, 0x00, 0x00, 0xFB, 0x1D, 0x00, 0x00, 0xC7, 0x1E, 0x00, 0x00, 
	0x93, 0x1F, 0x00, 0x00, 0x5F, 0x20, 0x00, 0x00, 0x2C, 0x21, 0x00, 0x00, 0xF8, 0x21, 0x00, 0x00, 
	0xC5, 0x22, 0x00, 0x00, 0x92, 0x23, 0x00, 0x00, 0x5F, 0x24, 0x00, 0x00, 0x2C, 0x25, 0x00, 0x00, 
	0xF9, 0x25, 0x00, 0x00, 0xC7, 0x26, 0x00, 0x00, 0x95, 0x27, 0x00, 0x00, 0x63, 0x28, 0x00, 0x00, 
	0x31, 0x29, 0x00, 0x00, 0xFF, 0x29, 0x00, 0x00, 0xCE, 0x2A, 0x00, 0x00, 0x9D, 0x2B, 0x00, 0x00, 
	0x6C, 0x2C, 0x00, 0x00, 0x3B, 0x2D, 0x00, 0x00, 0x0A, 0x2E, 0x00, 0x00, 0xDA, 0x2E, 0x00, 0x00, 
	0xAA, 0x2F, 0x00, 0x00, 0x7A, 0x30, 0x00, 0x00, 0x4A, 0x31, 0x00, 0x00, 0x1B, 0x32, 0x00, 0x00, 
	0xEC, 0x32, 0x00, 0x00, 0xBD, 0x33, 0x00, 0x00, 0x8E, 0x34, 0x00, 0x00, 0x60, 0x35, 0x00, 0x00, 
	0x32, 0x36, 0x00, 0x00, 0x04, 0x37, 0x00, 0x00, 0xD7, 0x37, 0x00, 0x00, 0xAA, 0x38, 0x00, 0x00, 
	0x7D, 0x39, 0x00, 0x00, 0x50, 0x3A, 0x00, 0x00, 0x24, 0x3B, 0x00, 0x00, 0xF8, 0x3B, 0x00, 0x00, 
	0xCC, 0x3C, 0x00, 0x00, 0xA0, 0x3D, 0x00, 0x00, 0x75, 0x3E, 0x00, 0x00, 0x4A, 0x3F, 0x00, 0x00, 
	0x20, 0x40, 0x00, 0x00, 0xF6, 0x40, 0x00, 0x00, 0xCC, 0x41, 0x00, 0x00, 0xA2, 0x42, 0x00, 0x00, 
	0x79, 0x43, 0x00, 0x00, 0x51, 0x44, 0x00, 0x00, 0x28, 0x45, 0x00, 0x00, 0x00, 0x46, 0x00, 0x00, 
	0xD8, 0x46, 0x00, 0x00, 0xB1, 0x47, 0x00, 0x00, 0x8A, 0x48, 0x00, 0x00, 0x63, 0x49, 0x00, 0x00, 
	0x3D, 0x4A, 0x00, 0x00, 0x17, 0x4B, 0x00, 0x00, 0xF2, 0x4B, 0x00, 0x00, 0xCD, 0x4C, 0x00, 0x00, 
	0xA8, 0x4D, 0x00, 0x00, 0x84, 0x4E, 0x00, 0x00, 0x60, 0x4F, 0x00, 0x00, 0x3D, 0x50, 0x00, 0x00, 
	0x1A, 0x51, 0x00, 0x00, 0xF7, 0x51, 0x00, 0x00, 0xD5, 0x52, 0x00, 0x00, 0xB3, 0x53, 0x00, 0x00, 
	0x92, 0x54, 0x00, 0x00, 0x71, 0x55, 0x00, 0x00, 0x51, 0x56, 0x00, 0x00, 0x31, 0x57, 0x00, 0x00, 
	0x12, 0x58, 0x00, 0x00, 0xF3, 0x58, 0x00, 0x00, 0xD5, 0x59, 0x00, 0x00, 0xB7, 0x5A, 0x00, 0x00, 
	0x99, 0x5B, 0x00, 0x00, 0x7C, 0x5C, 0x00, 0x00, 0x60, 0x5D, 0x00, 0x00, 0x44, 0x5E, 0x00, 0x00, 
	0x28, 0x5F, 0x00, 0x00, 0x0E, 0x60, 0x00, 0x00, 0xF3, 0x60, 0x00, 0x00, 0xD9, 0x61, 0x00, 0x00, 
	0xC0, 0x62, 0x00, 0x00, 0xA7, 0x63, 0x00, 0x00, 0x8F, 0x64, 0x00, 0x00, 0x77, 0x65, 0x00, 0x00, 
	0x60, 0x66, 0x00, 0x00, 0x4A, 0x67, 0x00, 0x00, 0x34, 0x68, 0x00, 0x00, 0x1F, 0x69, 0x00, 0x00, 
	0x0A, 0x6A, 0x00, 0x00, 0xF6, 0x6A, 0x00, 0x00, 0xE2, 0x6B, 0x00, 0x00, 0xCF, 0x6C, 0x00, 0x00, 
	0xBD, 0x6D, 0x00, 0x00, 0xAB, 0x6E, 0x00, 0x00, 0x9A, 0x6F, 0x00, 0x00, 0x8A, 0x70, 0x00, 0x00, 
	0x7A, 0x71, 0x00, 0x00, 0x6B, 0x72, 0x00, 0x00, 0x5D, 0x73, 0x00, 0x00, 0x4F, 0x74, 0x00, 0x00, 
	0x42, 0x75, 0x00, 0x00, 0x35, 0x76, 0x00, 0x00, 0x2A, 0x77, 0x00, 0x00, 0x1F, 0x78, 0x00, 0x00, 
	0x14, 0x79, 0x00, 0x00, 0x0B, 0x7A, 0x00, 0x00, 0x02, 0x7B, 0x00, 0x00, 0xFA, 0x7B, 0x00, 0x00, 
	0xF2, 0x7C, 0x00, 0x00, 0xEC, 0x7D, 0x00, 0x00, 0xE6, 0x7E, 0x00, 0x00, 0xE0, 0x7F, 0x00, 0x00, 
	0xDC, 0x80, 0x00, 0x00, 0xD8, 0x81, 0x00, 0x00, 0xD6, 0x82, 0x00, 0x00, 0xD4, 0x83, 0x00, 0x00, 
	0xD2, 0x84, 0x00, 0x00, 0xD2, 0x85, 0x00, 0x00, 0xD2, 0x86, 0x00, 0x00, 0xD4, 0x87, 0x00, 0x00, 
	0xD6, 0x88, 0x00, 0x00, 0xD9, 0x89, 0x00, 0x00, 0xDC, 0x8A, 0x00, 0x00, 0xE1, 0x8B, 0x00, 0x00, 
	0xE7, 0x8C, 0x00, 0x00, 0xED, 0x8D, 0x00, 0x00, 0xF4, 0x8E, 0x00, 0x00, 0xFD, 0x8F, 0x00, 0x00, 
	0x06, 0x91, 0x00, 0x00, 0x10, 0x92, 0x00, 0x00, 0x1B, 0x93, 0x00, 0x00, 0x27, 0x94, 0x00, 0x00, 
	0x34, 0x95, 0x00, 0x00, 0x41, 0x96, 0x00, 0x00, 0x50, 0x97, 0x00, 0x00, 0x60, 0x98, 0x00, 0x00, 
	0x71, 0x99, 0x00, 0x00, 0x83, 0x9A, 0x00, 0x00, 0x95, 0x9B, 0x00, 0x00, 0xA9, 0x9C, 0x00, 0x00, 
	0xBE, 0x9D, 0x00, 0x00, 0xD4, 0x9E, 0x00, 0x00, 0xEB, 0x9F, 0x00, 0x00, 0x03, 0xA1, 0x00, 0x00, 
	0x1C, 0xA2, 0x00, 0x00, 0x36, 0xA3, 0x00, 0x00, 0x52, 0xA4, 0x00, 0x00, 0x6E, 0xA5, 0x00, 0x00, 
	0x8C, 0xA6, 0x00, 0x00, 0xAB, 0xA7, 0x00, 0x00, 0xCA, 0xA8, 0x00, 0x00, 0xEC, 0xA9, 0x00, 0x00, 
	0x0E, 0xAB, 0x00, 0x00, 0x31, 0xAC, 0x00, 0x00, 0x56, 0xAD, 0x00, 0x00, 0x7C, 0xAE, 0x00, 0x00, 
	0xA3, 0xAF, 0x00, 0x00, 0xCB, 0xB0, 0x00, 0x00, 0xF5, 0xB1, 0x00, 0x00, 0x20, 0xB3, 0x00, 0x00, 
	0x4C, 0xB4, 0x00, 0x00, 0x79, 0xB5, 0x00, 0x00, 0xA8, 0xB6, 0x00, 0x00, 0xD8, 0xB7, 0x00, 0x00, 
	0x09, 0xB9, 0x00, 0x00, 0x3C, 0xBA, 0x00, 0x00, 0x70, 0xBB, 0x00, 0x00, 0xA6, 0xBC, 0x00, 0x00, 
	0xDD, 0xBD, 0x00, 0x00, 0x15, 0xBF, 0x00, 0x00, 0x4F, 0xC0, 0x00, 0x00, 0x8A, 0xC1, 0x00, 0x00, 
	0xC7, 0xC2, 0x00, 0x00, 0x05, 0xC4, 0x00, 0x00, 0x45, 0xC5, 0x00, 0x00, 0x86, 0xC6, 0x00, 0x00, 
	0xC9, 0xC7, 0x00, 0x00, 0x0D, 0xC9, 0x00, 0x00, 0x53, 0xCA, 0x00, 0x00, 0x9A, 0xCB, 0x00, 0x00, 
	0xE3, 0xCC, 0x00, 0x00, 0x2E, 0xCE, 0x00, 0x00, 0x7A, 0xCF, 0x00, 0x00, 0xC8, 0xD0, 0x00, 0x00, 
	0x18, 0xD2, 0x00, 0x00, 0x69, 0xD3, 0x00, 0x00, 0xBC, 0xD4, 0x00, 0x00, 0x11, 0xD6, 0x00, 0x00, 
	0x68, 0xD7, 0x00, 0x00, 0xC0, 0xD8, 0x00, 0x00, 0x1A, 0xDA, 0x00, 0x00, 0x76, 0xDB, 0x00, 0x00, 
	0xD4, 0xDC, 0x00, 0x00, 0x33, 0xDE, 0x00, 0x00, 0x95, 0xDF, 0x00, 0x00, 0xF8, 0xE0, 0x00, 0x00, 
	0x5E, 0xE2, 0x00, 0x00, 0xC5, 0xE3, 0x00, 0x00, 0x2E, 0xE5, 0x00, 0x00, 0x99, 0xE6, 0x00, 0x00, 
	0x06, 0xE8, 0x00, 0x00, 0x76, 0xE9, 0x00, 0x00, 0xE7, 0xEA, 0x00, 0x00, 0x5A, 0xEC, 0x00, 0x00, 
	0xD0, 0xED, 0x00, 0x00, 0x47, 0xEF, 0x00, 0x00, 0xC1, 0xF0, 0x00, 0x00, 0x3D, 0xF2, 0x00, 0x00, 
	0xBB, 0xF3, 0x00, 0x00, 0x3C, 0xF5, 0x00, 0x00, 0xBF, 0xF6, 0x00, 0x00, 0x44, 0xF8, 0x00, 0x00, 
	0xCB, 0xF9, 0x00, 0x00, 0x55, 0xFB, 0x00, 0x00, 0xE1, 0xFC, 0x00, 0x00, 0x6F, 0xFE, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x00, 0x93, 0x01, 0x01, 0x00, 0x29, 0x03, 0x01, 0x00, 0xC2, 0x04, 0x01, 0x00, 
	0x5D, 0x06, 0x01, 0x00, 0xFA, 0x07, 0x01, 0x00, 0x9A, 0x09, 0x01, 0x00, 0x3D, 0x0B, 0x01, 0x00, 
	0xE3, 0x0C, 0x01, 0x00, 0x8B, 0x0E, 0x01, 0x00, 0x36, 0x10, 0x01, 0x00, 0xE4, 0x11, 0x01, 0x00, 
	0x94, 0x13, 0x01, 0x00, 0x48, 0x15, 0x01, 0x00, 0xFE, 0x16, 0x01, 0x00, 0xB8, 0x18, 0x01, 0x00, 
	0x74, 0x1A, 0x01, 0x00, 0x33, 0x1C, 0x01, 0x00, 0xF6, 0x1D, 0x01, 0x00, 0xBB, 0x1F, 0x01, 0x00, 
	0x84, 0x21, 0x01, 0x00, 0x50, 0x23, 0x01, 0x00, 0x1F, 0x25, 0x01, 0x00, 0xF1, 0x26, 0x01, 0x00, 
	0xC6, 0x28, 0x01, 0x00, 0x9F, 0x2A, 0x01, 0x00, 0x7C, 0x2C, 0x01, 0x00, 0x5C, 0x2E, 0x01, 0x00, 
	0x3F, 0x30, 0x01, 0x00, 0x26, 0x32, 0x01, 0x00, 0x10, 0x34, 0x01, 0x00, 0xFE, 0x35, 0x01, 0x00, 
	0xF0, 0x37, 0x01, 0x00, 0xE5, 0x39, 0x01, 0x00, 0xDF, 0x3B, 0x01, 0x00, 0xDC, 0x3D, 0x01, 0x00, 
	0xDD, 0x3F, 0x01, 0x00, 0xE2, 0x41, 0x01, 0x00, 0xEB, 0x43, 0x01, 0x00, 0xF8, 0x45, 0x01, 0x00, 
	0x09, 0x48, 0x01, 0x00, 0x1E, 0x4A, 0x01, 0x00, 0x37, 0x4C, 0x01, 0x00, 0x55, 0x4E, 0x01, 0x00, 
	0x77, 0x50, 0x01, 0x00, 0x9E, 0x52, 0x01, 0x00, 0xC9, 0x54, 0x01, 0x00, 0xF9, 0x56, 0x01, 0x00, 
	0x2D, 0x59, 0x01, 0x00, 0x66, 0x5B, 0x01, 0x00, 0xA4, 0x5D, 0x01, 0x00, 0xE6, 0x5F, 0x01, 0x00, 
	0x2E, 0x62, 0x01, 0x00, 0x7A, 0x64, 0x01, 0x00, 0xCC, 0x66, 0x01, 0x00, 0x22, 0x69, 0x01, 0x00, 
	0x7E, 0x6B, 0x01, 0x00, 0xDF, 0x6D, 0x01, 0x00, 0x45, 0x70, 0x01, 0x00, 0xB1, 0x72, 0x01, 0x00, 
	0x23, 0x75, 0x01, 0x00, 0x9A, 0x77, 0x01, 0x00, 0x17, 0x7A, 0x01, 0x00, 0x99, 0x7C, 0x01, 0x00, 
	0x22, 0x7F, 0x01, 0x00, 0xB0, 0x81, 0x01, 0x00, 0x44, 0x84, 0x01, 0x00, 0xDF, 0x86, 0x01, 0x00, 
	0x80, 0x89, 0x01, 0x00, 0x27, 0x8C, 0x01, 0x00, 0xD5, 0x8E, 0x01, 0x00, 0x8A, 0x91, 0x01, 0x00, 
	0x45, 0x94, 0x01, 0x00, 0x07, 0x97, 0x01, 0x00, 0xCF, 0x99, 0x01, 0x00, 0x9F, 0x9C, 0x01, 0x00, 
	0x76, 0x9F, 0x01, 0x00, 0x54, 0xA2, 0x01, 0x00, 0x3A, 0xA5, 0x01, 0x00, 0x27, 0xA8, 0x01, 0x00, 
	0x1C, 0xAB, 0x01, 0x00, 0x19, 0xAE, 0x01, 0x00, 0x1D, 0xB1, 0x01, 0x00, 0x2A, 0xB4, 0x01, 0x00, 
	0x3F, 0xB7, 0x01, 0x00, 0x5C, 0xBA, 0x01, 0x00, 0x82, 0xBD, 0x01, 0x00, 0xB0, 0xC0, 0x01, 0x00, 
	0xE7, 0xC3, 0x01, 0x00, 0x27, 0xC7, 0x01, 0x00, 0x71, 0xCA, 0x01, 0x00, 0xC3, 0xCD, 0x01, 0x00, 
	0x1F, 0xD1, 0x01, 0x00, 0x85, 0xD4, 0x01, 0x00, 0xF4, 0xD7, 0x01, 0x00, 0x6E, 0xDB, 0x01, 0x00, 
	0xF1, 0xDE, 0x01, 0x00, 0x7F, 0xE2, 0x01, 0x00, 0x18, 0xE6, 0x01, 0x00, 0xBB, 0xE9, 0x01, 0x00, 
	0x6A, 0xED, 0x01, 0x00, 0x23, 0xF1, 0x01, 0x00, 0xE8, 0xF4, 0x01, 0x00, 0xB9, 0xF8, 0x01, 0x00, 
	0x96, 0xFC, 0x01, 0x00, 0x7E, 0x00, 0x02, 0x00, 0x73, 0x04, 0x02, 0x00, 0x75, 0x08, 0x02, 0x00, 
	0x84, 0x0C, 0x02, 0x00, 0x9F, 0x10, 0x02, 0x00, 0xC9, 0x14, 0x02, 0x00, 0xFF, 0x18, 0x02, 0x00, 
	0x44, 0x1D, 0x02, 0x00, 0x97, 0x21, 0x02, 0x00, 0xF9, 0x25, 0x02, 0x00, 0x69, 0x2A, 0x02, 0x00, 
	0xE9, 0x2E, 0x02, 0x00, 0x78, 0x33, 0x02, 0x00, 0x18, 0x38, 0x02, 0x00, 0xC7, 0x3C, 0x02, 0x00, 
	0x87, 0x41, 0x02, 0x00, 0x58, 0x46, 0x02, 0x00, 0x3A, 0x4B, 0x02, 0x00, 0x2E, 0x50, 0x02, 0x00, 
	0x34, 0x55, 0x02, 0x00, 0x4D, 0x5A, 0x02, 0x00, 0x78, 0x5F, 0x02, 0x00, 0xB7, 0x64, 0x02, 0x00, 
	0x0A, 0x6A, 0x02, 0x00, 0x71, 0x6F, 0x02, 0x00, 0xED, 0x74, 0x02, 0x00, 0x7E, 0x7A, 0x02, 0x00, 
	0x26, 0x80, 0x02, 0x00, 0xE3, 0x85, 0x02, 0x00, 0xB8, 0x8B, 0x02, 0x00, 0xA4, 0x91, 0x02, 0x00, 
	0xA8, 0x97, 0x02, 0x00, 0xC4, 0x9D, 0x02, 0x00, 0xFB, 0xA3, 0x02, 0x00, 0x4B, 0xAA, 0x02, 0x00, 
	0xB5, 0xB0, 0x02, 0x00, 0x3B, 0xB7, 0x02, 0x00, 0xDD, 0xBD, 0x02, 0x00, 0x9C, 0xC4, 0x02, 0x00, 
	0x79, 0xCB, 0x02, 0x00, 0x74, 0xD2, 0x02, 0x00, 0x8E, 0xD9, 0x02, 0x00, 0xC8, 0xE0, 0x02, 0x00, 
	0x23, 0xE8, 0x02, 0x00, 0xA0, 0xEF, 0x02, 0x00, 0x40, 0xF7, 0x02, 0x00, 0x04, 0xFF, 0x02, 0x00, 
	0xEC, 0x06, 0x03, 0x00, 0xFB, 0x0E, 0x03, 0x00, 0x30, 0x17, 0x03, 0x00, 0x8E, 0x1F, 0x03, 0x00, 
	0x16, 0x28, 0x03, 0x00, 0xC8, 0x30, 0x03, 0x00, 0xA6, 0x39, 0x03, 0x00, 0xB1, 0x42, 0x03, 0x00, 
	0xEB, 0x4B, 0x03, 0x00, 0x56, 0x55, 0x03, 0x00, 0xF2, 0x5E, 0x03, 0x00, 0xC2, 0x68, 0x03, 0x00, 
	0xC6, 0x72, 0x03, 0x00, 0x02, 0x7D, 0x03, 0x00, 0x76, 0x87, 0x03, 0x00, 0x25, 0x92, 0x03, 0x00, 
	0x11, 0x9D, 0x03, 0x00, 0x3B, 0xA8, 0x03, 0x00, 0xA6, 0xB3, 0x03, 0x00, 0x54, 0xBF, 0x03, 0x00, 
	0x48, 0xCB, 0x03, 0x00, 0x84, 0xD7, 0x03, 0x00, 0x0A, 0xE4, 0x03, 0x00, 0xDE, 0xF0, 0x03, 0x00, 
	0x02, 0xFE, 0x03, 0x00, 0x7A, 0x0B, 0x04, 0x00, 0x49, 0x19, 0x04, 0x00, 0x71, 0x27, 0x04, 0x00, 
	0xF7, 0x35, 0x04, 0x00, 0xDE, 0x44, 0x04, 0x00, 0x2B, 0x54, 0x04, 0x00, 0xE1, 0x63, 0x04, 0x00, 
	0x05, 0x74, 0x04, 0x00, 0x9B, 0x84, 0x04, 0x00, 0xA9, 0x95, 0x04, 0x00, 0x33, 0xA7, 0x04, 0x00, 
	0x40, 0xB9, 0x04, 0x00, 0xD4, 0xCB, 0x04, 0x00, 0xF6, 0xDE, 0x04, 0x00, 0xAD, 0xF2, 0x04, 0x00, 
	0x00, 0x07, 0x05, 0x00, 0xF5, 0x1B, 0x05, 0x00, 0x96, 0x31, 0x05, 0x00, 0xE9, 0x47, 0x05, 0x00, 
	0xF9, 0x5E, 0x05, 0x00, 0xCF, 0x76, 0x05, 0x00, 0x75, 0x8F, 0x05, 0x00, 0xF6, 0xA8, 0x05, 0x00, 
	0x5D, 0xC3, 0x05, 0x00, 0xB8, 0xDE, 0x05, 0x00, 0x14, 0xFB, 0x05, 0x00, 0x7F, 0x18, 0x06, 0x00, 
	0x09, 0x37, 0x06, 0x00, 0xC4, 0x56, 0x06, 0x00, 0xC0, 0x77, 0x06, 0x00, 0x12, 0x9A, 0x06, 0x00, 
	0xD0, 0xBD, 0x06, 0x00, 0x10, 0xE3, 0x06, 0x00, 0xEC, 0x09, 0x07, 0x00, 0x7E, 0x32, 0x07, 0x00, 
	0xE6, 0x5C, 0x07, 0x00, 0x44, 0x89, 0x07, 0x00, 0xBB, 0xB7, 0x07, 0x00, 0x73, 0xE8, 0x07, 0x00, 
	0x98, 0x1B, 0x08, 0x00, 0x58, 0x51, 0x08, 0x00, 0xE9, 0x89, 0x08, 0x00, 0x86, 0xC5, 0x08, 0x00, 
	0x6E, 0x04, 0x09, 0x00, 0xEB, 0x46, 0x09, 0x00, 0x4D, 0x8D, 0x09, 0x00, 0xEE, 0xD7, 0x09, 0x00, 
	0x36, 0x27, 0x0A, 0x00, 0x97, 0x7B, 0x0A, 0x00, 0x93, 0xD5, 0x0A, 0x00, 0xC0, 0x35, 0x0B, 0x00, 
	0xC6, 0x9C, 0x0B, 0x00, 0x69, 0x0B, 0x0C, 0x00, 0x8A, 0x82, 0x0C, 0x00, 0x2C, 0x03, 0x0D, 0x00, 
	0x82, 0x8E, 0x0D, 0x00, 0xEF, 0x25, 0x0E, 0x00, 0x1B, 0xCB, 0x0E, 0x00, 0xFA, 0x7F, 0x0F, 0x00, 
	0xEA, 0x46, 0x10, 0x00, 0xC3, 0x22, 0x11, 0x00, 0x03, 0x17, 0x12, 0x00, 0xF6, 0x27, 0x13, 0x00, 
	0x00, 0x5B, 0x14, 0x00, 0xF1, 0xB6, 0x15, 0x00, 0x8D, 0x44, 0x17, 0x00, 0x4A, 0x0F, 0x19, 0x00, 
	0x72, 0x26, 0x1B, 0x00, 0xDA, 0x9E, 0x1D, 0x00, 0xAF, 0x95, 0x20, 0x00, 0x17, 0x35, 0x24, 0x00, 
	0x49, 0xBC, 0x28, 0x00, 0x9A, 0x8E, 0x2E, 0x00, 0x9A, 0x51, 0x36, 0x00, 0x4C, 0x2F, 0x41, 0x00, 
	0xB6, 0x7B, 0x51, 0x00, 0x8F, 0xA5, 0x6C, 0x00, 0xFD, 0xF8, 0xA2, 0x00, 0xC4, 0xF2, 0x45, 0x01, 
	0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xEF, 
	0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xEF
 },
 pCosTable[0x820] =
 {
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFD, 0xFF, 0x00, 0x00, 
	0xFB, 0xFF, 0x00, 0x00, 0xF8, 0xFF, 0x00, 0x00, 0xF5, 0xFF, 0x00, 0x00, 0xF1, 0xFF, 0x00, 0x00, 
	0xEC, 0xFF, 0x00, 0x00, 0xE7, 0xFF, 0x00, 0x00, 0xE1, 0xFF, 0x00, 0x00, 0xDB, 0xFF, 0x00, 0x00, 
	0xD4, 0xFF, 0x00, 0x00, 0xCC, 0xFF, 0x00, 0x00, 0xC4, 0xFF, 0x00, 0x00, 0xBB, 0xFF, 0x00, 0x00, 
	0xB1, 0xFF, 0x00, 0x00, 0xA7, 0xFF, 0x00, 0x00, 0x9C, 0xFF, 0x00, 0x00, 0x91, 0xFF, 0x00, 0x00, 
	0x85, 0xFF, 0x00, 0x00, 0x78, 0xFF, 0x00, 0x00, 0x6B, 0xFF, 0x00, 0x00, 0x5D, 0xFF, 0x00, 0x00, 
	0x4E, 0xFF, 0x00, 0x00, 0x3F, 0xFF, 0x00, 0x00, 0x30, 0xFF, 0x00, 0x00, 0x1F, 0xFF, 0x00, 0x00, 
	0x0E, 0xFF, 0x00, 0x00, 0xFD, 0xFE, 0x00, 0x00, 0xEB, 0xFE, 0x00, 0x00, 0xD8, 0xFE, 0x00, 0x00, 
	0xC4, 0xFE, 0x00, 0x00, 0xB0, 0xFE, 0x00, 0x00, 0x9C, 0xFE, 0x00, 0x00, 0x87, 0xFE, 0x00, 0x00, 
	0x71, 0xFE, 0x00, 0x00, 0x5A, 0xFE, 0x00, 0x00, 0x43, 0xFE, 0x00, 0x00, 0x2B, 0xFE, 0x00, 0x00, 
	0x13, 0xFE, 0x00, 0x00, 0xFA, 0xFD, 0x00, 0x00, 0xE1, 0xFD, 0x00, 0x00, 0xC7, 0xFD, 0x00, 0x00, 
	0xAC, 0xFD, 0x00, 0x00, 0x90, 0xFD, 0x00, 0x00, 0x74, 0xFD, 0x00, 0x00, 0x58, 0xFD, 0x00, 0x00, 
	0x3B, 0xFD, 0x00, 0x00, 0x1D, 0xFD, 0x00, 0x00, 0xFE, 0xFC, 0x00, 0x00, 0xDF, 0xFC, 0x00, 0x00, 
	0xC0, 0xFC, 0x00, 0x00, 0xA0, 0xFC, 0x00, 0x00, 0x7F, 0xFC, 0x00, 0x00, 0x5D, 0xFC, 0x00, 0x00, 
	0x3B, 0xFC, 0x00, 0x00, 0x18, 0xFC, 0x00, 0x00, 0xF5, 0xFB, 0x00, 0x00, 0xD1, 0xFB, 0x00, 0x00, 
	0xAD, 0xFB, 0x00, 0x00, 0x88, 0xFB, 0x00, 0x00, 0x62, 0xFB, 0x00, 0x00, 0x3C, 0xFB, 0x00, 0x00, 
	0x15, 0xFB, 0x00, 0x00, 0xED, 0xFA, 0x00, 0x00, 0xC5, 0xFA, 0x00, 0x00, 0x9C, 0xFA, 0x00, 0x00, 
	0x73, 0xFA, 0x00, 0x00, 0x49, 0xFA, 0x00, 0x00, 0x1F, 0xFA, 0x00, 0x00, 0xF3, 0xF9, 0x00, 0x00, 
	0xC8, 0xF9, 0x00, 0x00, 0x9B, 0xF9, 0x00, 0x00, 0x6E, 0xF9, 0x00, 0x00, 0x41, 0xF9, 0x00, 0x00, 
	0x13, 0xF9, 0x00, 0x00, 0xE4, 0xF8, 0x00, 0x00, 0xB4, 0xF8, 0x00, 0x00, 0x85, 0xF8, 0x00, 0x00, 
	0x54, 0xF8, 0x00, 0x00, 0x23, 0xF8, 0x00, 0x00, 0xF1, 0xF7, 0x00, 0x00, 0xBF, 0xF7, 0x00, 0x00, 
	0x8C, 0xF7, 0x00, 0x00, 0x58, 0xF7, 0x00, 0x00, 0x24, 0xF7, 0x00, 0x00, 0xEF, 0xF6, 0x00, 0x00, 
	0xBA, 0xF6, 0x00, 0x00, 0x84, 0xF6, 0x00, 0x00, 0x4E, 0xF6, 0x00, 0x00, 0x16, 0xF6, 0x00, 0x00, 
	0xDF, 0xF5, 0x00, 0x00, 0xA6, 0xF5, 0x00, 0x00, 0x6E, 0xF5, 0x00, 0x00, 0x34, 0xF5, 0x00, 0x00, 
	0xFA, 0xF4, 0x00, 0x00, 0xBF, 0xF4, 0x00, 0x00, 0x84, 0xF4, 0x00, 0x00, 0x48, 0xF4, 0x00, 0x00, 
	0x0C, 0xF4, 0x00, 0x00, 0xCF, 0xF3, 0x00, 0x00, 0x91, 0xF3, 0x00, 0x00, 0x53, 0xF3, 0x00, 0x00, 
	0x14, 0xF3, 0x00, 0x00, 0xD5, 0xF2, 0x00, 0x00, 0x95, 0xF2, 0x00, 0x00, 0x54, 0xF2, 0x00, 0x00, 
	0x13, 0xF2, 0x00, 0x00, 0xD2, 0xF1, 0x00, 0x00, 0x8F, 0xF1, 0x00, 0x00, 0x4C, 0xF1, 0x00, 0x00, 
	0x09, 0xF1, 0x00, 0x00, 0xC5, 0xF0, 0x00, 0x00, 0x80, 0xF0, 0x00, 0x00, 0x3B, 0xF0, 0x00, 0x00, 
	0xF5, 0xEF, 0x00, 0x00, 0xAF, 0xEF, 0x00, 0x00, 0x68, 0xEF, 0x00, 0x00, 0x21, 0xEF, 0x00, 0x00, 
	0xD9, 0xEE, 0x00, 0x00, 0x90, 0xEE, 0x00, 0x00, 0x47, 0xEE, 0x00, 0x00, 0xFD, 0xED, 0x00, 0x00, 
	0xB3, 0xED, 0x00, 0x00, 0x68, 0xED, 0x00, 0x00, 0x1C, 0xED, 0x00, 0x00, 0xD0, 0xEC, 0x00, 0x00, 
	0x83, 0xEC, 0x00, 0x00, 0x36, 0xEC, 0x00, 0x00, 0xE8, 0xEB, 0x00, 0x00, 0x9A, 0xEB, 0x00, 0x00, 
	0x4B, 0xEB, 0x00, 0x00, 0xFC, 0xEA, 0x00, 0x00, 0xAB, 0xEA, 0x00, 0x00, 0x5B, 0xEA, 0x00, 0x00, 
	0x0A, 0xEA, 0x00, 0x00, 0xB8, 0xE9, 0x00, 0x00, 0x66, 0xE9, 0x00, 0x00, 0x13, 0xE9, 0x00, 0x00, 
	0xBF, 0xE8, 0x00, 0x00, 0x6B, 0xE8, 0x00, 0x00, 0x17, 0xE8, 0x00, 0x00, 0xC2, 0xE7, 0x00, 0x00, 
	0x6C, 0xE7, 0x00, 0x00, 0x16, 0xE7, 0x00, 0x00, 0xBF, 0xE6, 0x00, 0x00, 0x67, 0xE6, 0x00, 0x00, 
	0x10, 0xE6, 0x00, 0x00, 0xB7, 0xE5, 0x00, 0x00, 0x5E, 0xE5, 0x00, 0x00, 0x04, 0xE5, 0x00, 0x00, 
	0xAA, 0xE4, 0x00, 0x00, 0x50, 0xE4, 0x00, 0x00, 0xF4, 0xE3, 0x00, 0x00, 0x99, 0xE3, 0x00, 0x00, 
	0x3C, 0xE3, 0x00, 0x00, 0xDF, 0xE2, 0x00, 0x00, 0x82, 0xE2, 0x00, 0x00, 0x24, 0xE2, 0x00, 0x00, 
	0xC6, 0xE1, 0x00, 0x00, 0x67, 0xE1, 0x00, 0x00, 0x07, 0xE1, 0x00, 0x00, 0xA7, 0xE0, 0x00, 0x00, 
	0x46, 0xE0, 0x00, 0x00, 0xE5, 0xDF, 0x00, 0x00, 0x83, 0xDF, 0x00, 0x00, 0x21, 0xDF, 0x00, 0x00, 
	0xBE, 0xDE, 0x00, 0x00, 0x5B, 0xDE, 0x00, 0x00, 0xF7, 0xDD, 0x00, 0x00, 0x92, 0xDD, 0x00, 0x00, 
	0x2D, 0xDD, 0x00, 0x00, 0xC8, 0xDC, 0x00, 0x00, 0x62, 0xDC, 0x00, 0x00, 0xFB, 0xDB, 0x00, 0x00, 
	0x94, 0xDB, 0x00, 0x00, 0x2C, 0xDB, 0x00, 0x00, 0xC4, 0xDA, 0x00, 0x00, 0x5C, 0xDA, 0x00, 0x00, 
	0xF2, 0xD9, 0x00, 0x00, 0x89, 0xD9, 0x00, 0x00, 0x1E, 0xD9, 0x00, 0x00, 0xB4, 0xD8, 0x00, 0x00, 
	0x48, 0xD8, 0x00, 0x00, 0xDC, 0xD7, 0x00, 0x00, 0x70, 0xD7, 0x00, 0x00, 0x03, 0xD7, 0x00, 0x00, 
	0x96, 0xD6, 0x00, 0x00, 0x28, 0xD6, 0x00, 0x00, 0xBA, 0xD5, 0x00, 0x00, 0x4B, 0xD5, 0x00, 0x00, 
	0xDB, 0xD4, 0x00, 0x00, 0x6B, 0xD4, 0x00, 0x00, 0xFB, 0xD3, 0x00, 0x00, 0x8A, 0xD3, 0x00, 0x00, 
	0x18, 0xD3, 0x00, 0x00, 0xA6, 0xD2, 0x00, 0x00, 0x34, 0xD2, 0x00, 0x00, 0xC1, 0xD1, 0x00, 0x00, 
	0x4D, 0xD1, 0x00, 0x00, 0xD9, 0xD0, 0x00, 0x00, 0x65, 0xD0, 0x00, 0x00, 0xF0, 0xCF, 0x00, 0x00, 
	0x7A, 0xCF, 0x00, 0x00, 0x04, 0xCF, 0x00, 0x00, 0x8E, 0xCE, 0x00, 0x00, 0x17, 0xCE, 0x00, 0x00, 
	0x9F, 0xCD, 0x00, 0x00, 0x27, 0xCD, 0x00, 0x00, 0xAE, 0xCC, 0x00, 0x00, 0x35, 0xCC, 0x00, 0x00, 
	0xBC, 0xCB, 0x00, 0x00, 0x42, 0xCB, 0x00, 0x00, 0xC7, 0xCA, 0x00, 0x00, 0x4D, 0xCA, 0x00, 0x00, 
	0xD1, 0xC9, 0x00, 0x00, 0x55, 0xC9, 0x00, 0x00, 0xD9, 0xC8, 0x00, 0x00, 0x5C, 0xC8, 0x00, 0x00, 
	0xDE, 0xC7, 0x00, 0x00, 0x61, 0xC7, 0x00, 0x00, 0xE2, 0xC6, 0x00, 0x00, 0x63, 0xC6, 0x00, 0x00, 
	0xE4, 0xC5, 0x00, 0x00, 0x64, 0xC5, 0x00, 0x00, 0xE4, 0xC4, 0x00, 0x00, 0x63, 0xC4, 0x00, 0x00, 
	0xE2, 0xC3, 0x00, 0x00, 0x60, 0xC3, 0x00, 0x00, 0xDE, 0xC2, 0x00, 0x00, 0x5C, 0xC2, 0x00, 0x00, 
	0xD8, 0xC1, 0x00, 0x00, 0x55, 0xC1, 0x00, 0x00, 0xD1, 0xC0, 0x00, 0x00, 0x4C, 0xC0, 0x00, 0x00, 
	0xC7, 0xBF, 0x00, 0x00, 0x42, 0xBF, 0x00, 0x00, 0xBC, 0xBE, 0x00, 0x00, 0x36, 0xBE, 0x00, 0x00, 
	0xAF, 0xBD, 0x00, 0x00, 0x28, 0xBD, 0x00, 0x00, 0xA0, 0xBC, 0x00, 0x00, 0x18, 0xBC, 0x00, 0x00, 
	0x8F, 0xBB, 0x00, 0x00, 0x06, 0xBB, 0x00, 0x00, 0x7D, 0xBA, 0x00, 0x00, 0xF3, 0xB9, 0x00, 0x00, 
	0x68, 0xB9, 0x00, 0x00, 0xDD, 0xB8, 0x00, 0x00, 0x52, 0xB8, 0x00, 0x00, 0xC6, 0xB7, 0x00, 0x00, 
	0x3A, 0xB7, 0x00, 0x00, 0xAD, 0xB6, 0x00, 0x00, 0x20, 0xB6, 0x00, 0x00, 0x93, 0xB5, 0x00, 0x00, 
	0x05, 0xB5, 0x00, 0x00, 0x77, 0xB4, 0x00, 0x00, 0xE8, 0xB3, 0x00, 0x00, 0x58, 0xB3, 0x00, 0x00, 
	0xC9, 0xB2, 0x00, 0x00, 0x39, 0xB2, 0x00, 0x00, 0xA8, 0xB1, 0x00, 0x00, 0x17, 0xB1, 0x00, 0x00, 
	0x86, 0xB0, 0x00, 0x00, 0xF4, 0xAF, 0x00, 0x00, 0x62, 0xAF, 0x00, 0x00, 0xCF, 0xAE, 0x00, 0x00, 
	0x3C, 0xAE, 0x00, 0x00, 0xA8, 0xAD, 0x00, 0x00, 0x14, 0xAD, 0x00, 0x00, 0x80, 0xAC, 0x00, 0x00, 
	0xEB, 0xAB, 0x00, 0x00, 0x56, 0xAB, 0x00, 0x00, 0xC1, 0xAA, 0x00, 0x00, 0x2A, 0xAA, 0x00, 0x00, 
	0x94, 0xA9, 0x00, 0x00, 0xFD, 0xA8, 0x00, 0x00, 0x66, 0xA8, 0x00, 0x00, 0xCE, 0xA7, 0x00, 0x00, 
	0x36, 0xA7, 0x00, 0x00, 0x9E, 0xA6, 0x00, 0x00, 0x05, 0xA6, 0x00, 0x00, 0x6C, 0xA5, 0x00, 0x00, 
	0xD2, 0xA4, 0x00, 0x00, 0x38, 0xA4, 0x00, 0x00, 0x9E, 0xA3, 0x00, 0x00, 0x03, 0xA3, 0x00, 0x00, 
	0x68, 0xA2, 0x00, 0x00, 0xCC, 0xA1, 0x00, 0x00, 0x30, 0xA1, 0x00, 0x00, 0x94, 0xA0, 0x00, 0x00, 
	0xF7, 0x9F, 0x00, 0x00, 0x5A, 0x9F, 0x00, 0x00, 0xBC, 0x9E, 0x00, 0x00, 0x1E, 0x9E, 0x00, 0x00, 
	0x80, 0x9D, 0x00, 0x00, 0xE1, 0x9C, 0x00, 0x00, 0x42, 0x9C, 0x00, 0x00, 0xA3, 0x9B, 0x00, 0x00, 
	0x03, 0x9B, 0x00, 0x00, 0x63, 0x9A, 0x00, 0x00, 0xC2, 0x99, 0x00, 0x00, 0x21, 0x99, 0x00, 0x00, 
	0x80, 0x98, 0x00, 0x00, 0xDE, 0x97, 0x00, 0x00, 0x3C, 0x97, 0x00, 0x00, 0x9A, 0x96, 0x00, 0x00, 
	0xF7, 0x95, 0x00, 0x00, 0x54, 0x95, 0x00, 0x00, 0xB0, 0x94, 0x00, 0x00, 0x0C, 0x94, 0x00, 0x00, 
	0x68, 0x93, 0x00, 0x00, 0xC4, 0x92, 0x00, 0x00, 0x1F, 0x92, 0x00, 0x00, 0x79, 0x91, 0x00, 0x00, 
	0xD4, 0x90, 0x00, 0x00, 0x2E, 0x90, 0x00, 0x00, 0x88, 0x8F, 0x00, 0x00, 0xE1, 0x8E, 0x00, 0x00, 
	0x3A, 0x8E, 0x00, 0x00, 0x93, 0x8D, 0x00, 0x00, 0xEB, 0x8C, 0x00, 0x00, 0x43, 0x8C, 0x00, 0x00, 
	0x9A, 0x8B, 0x00, 0x00, 0xF2, 0x8A, 0x00, 0x00, 0x49, 0x8A, 0x00, 0x00, 0x9F, 0x89, 0x00, 0x00, 
	0xF6, 0x88, 0x00, 0x00, 0x4C, 0x88, 0x00, 0x00, 0xA1, 0x87, 0x00, 0x00, 0xF7, 0x86, 0x00, 0x00, 
	0x4C, 0x86, 0x00, 0x00, 0xA0, 0x85, 0x00, 0x00, 0xF5, 0x84, 0x00, 0x00, 0x49, 0x84, 0x00, 0x00, 
	0x9C, 0x83, 0x00, 0x00, 0xF0, 0x82, 0x00, 0x00, 0x43, 0x82, 0x00, 0x00, 0x95, 0x81, 0x00, 0x00, 
	0xE8, 0x80, 0x00, 0x00, 0x3A, 0x80, 0x00, 0x00, 0x8C, 0x7F, 0x00, 0x00, 0xDD, 0x7E, 0x00, 0x00, 
	0x2F, 0x7E, 0x00, 0x00, 0x7F, 0x7D, 0x00, 0x00, 0xD0, 0x7C, 0x00, 0x00, 0x20, 0x7C, 0x00, 0x00, 
	0x70, 0x7B, 0x00, 0x00, 0xC0, 0x7A, 0x00, 0x00, 0x10, 0x7A, 0x00, 0x00, 0x5F, 0x79, 0x00, 0x00, 
	0xAD, 0x78, 0x00, 0x00, 0xFC, 0x77, 0x00, 0x00, 0x4A, 0x77, 0x00, 0x00, 0x98, 0x76, 0x00, 0x00, 
	0xE6, 0x75, 0x00, 0x00, 0x33, 0x75, 0x00, 0x00, 0x80, 0x74, 0x00, 0x00, 0xCD, 0x73, 0x00, 0x00, 
	0x1A, 0x73, 0x00, 0x00, 0x66, 0x72, 0x00, 0x00, 0xB2, 0x71, 0x00, 0x00, 0xFE, 0x70, 0x00, 0x00, 
	0x49, 0x70, 0x00, 0x00, 0x94, 0x6F, 0x00, 0x00, 0xDF, 0x6E, 0x00, 0x00, 0x2A, 0x6E, 0x00, 0x00, 
	0x74, 0x6D, 0x00, 0x00, 0xBE, 0x6C, 0x00, 0x00, 0x08, 0x6C, 0x00, 0x00, 0x52, 0x6B, 0x00, 0x00, 
	0x9B, 0x6A, 0x00, 0x00, 0xE4, 0x69, 0x00, 0x00, 0x2D, 0x69, 0x00, 0x00, 0x76, 0x68, 0x00, 0x00, 
	0xBE, 0x67, 0x00, 0x00, 0x06, 0x67, 0x00, 0x00, 0x4E, 0x66, 0x00, 0x00, 0x95, 0x65, 0x00, 0x00, 
	0xDD, 0x64, 0x00, 0x00, 0x24, 0x64, 0x00, 0x00, 0x6B, 0x63, 0x00, 0x00, 0xB1, 0x62, 0x00, 0x00, 
	0xF8, 0x61, 0x00, 0x00, 0x3E, 0x61, 0x00, 0x00, 0x84, 0x60, 0x00, 0x00, 0xC9, 0x5F, 0x00, 0x00, 
	0x0F, 0x5F, 0x00, 0x00, 0x54, 0x5E, 0x00, 0x00, 0x99, 0x5D, 0x00, 0x00, 0xDE, 0x5C, 0x00, 0x00, 
	0x22, 0x5C, 0x00, 0x00, 0x66, 0x5B, 0x00, 0x00, 0xAA, 0x5A, 0x00, 0x00, 0xEE, 0x59, 0x00, 0x00, 
	0x32, 0x59, 0x00, 0x00, 0x75, 0x58, 0x00, 0x00, 0xB9, 0x57, 0x00, 0x00, 0xFC, 0x56, 0x00, 0x00, 
	0x3E, 0x56, 0x00, 0x00, 0x81, 0x55, 0x00, 0x00, 0xC3, 0x54, 0x00, 0x00, 0x06, 0x54, 0x00, 0x00, 
	0x48, 0x53, 0x00, 0x00, 0x89, 0x52, 0x00, 0x00, 0xCB, 0x51, 0x00, 0x00, 0x0C, 0x51, 0x00, 0x00, 
	0x4D, 0x50, 0x00, 0x00, 0x8E, 0x4F, 0x00, 0x00, 0xCF, 0x4E, 0x00, 0x00, 0x10, 0x4E, 0x00, 0x00, 
	0x50, 0x4D, 0x00, 0x00, 0x90, 0x4C, 0x00, 0x00, 0xD1, 0x4B, 0x00, 0x00, 0x10, 0x4B, 0x00, 0x00, 
	0x50, 0x4A, 0x00, 0x00, 0x90, 0x49, 0x00, 0x00, 0xCF, 0x48, 0x00, 0x00, 0x0E, 0x48, 0x00, 0x00, 
	0x4D, 0x47, 0x00, 0x00, 0x8C, 0x46, 0x00, 0x00, 0xCB, 0x45, 0x00, 0x00, 0x09, 0x45, 0x00, 0x00, 
	0x47, 0x44, 0x00, 0x00, 0x85, 0x43, 0x00, 0x00, 0xC3, 0x42, 0x00, 0x00, 0x01, 0x42, 0x00, 0x00, 
	0x3F, 0x41, 0x00, 0x00, 0x7C, 0x40, 0x00, 0x00, 0xBA, 0x3F, 0x00, 0x00, 0xF7, 0x3E, 0x00, 0x00, 
	0x34, 0x3E, 0x00, 0x00, 0x71, 0x3D, 0x00, 0x00, 0xAE, 0x3C, 0x00, 0x00, 0xEA, 0x3B, 0x00, 0x00, 
	0x27, 0x3B, 0x00, 0x00, 0x63, 0x3A, 0x00, 0x00, 0x9F, 0x39, 0x00, 0x00, 0xDB, 0x38, 0x00, 0x00, 
	0x17, 0x38, 0x00, 0x00, 0x53, 0x37, 0x00, 0x00, 0x8E, 0x36, 0x00, 0x00, 0xCA, 0x35, 0x00, 0x00, 
	0x05, 0x35, 0x00, 0x00, 0x40, 0x34, 0x00, 0x00, 0x7C, 0x33, 0x00, 0x00, 0xB7, 0x32, 0x00, 0x00, 
	0xF1, 0x31, 0x00, 0x00, 0x2C, 0x31, 0x00, 0x00, 0x67, 0x30, 0x00, 0x00, 0xA1, 0x2F, 0x00, 0x00, 
	0xDC, 0x2E, 0x00, 0x00, 0x16, 0x2E, 0x00, 0x00, 0x50, 0x2D, 0x00, 0x00, 0x8A, 0x2C, 0x00, 0x00, 
	0xC4, 0x2B, 0x00, 0x00, 0xFE, 0x2A, 0x00, 0x00, 0x38, 0x2A, 0x00, 0x00, 0x71, 0x29, 0x00, 0x00, 
	0xAB, 0x28, 0x00, 0x00, 0xE4, 0x27, 0x00, 0x00, 0x1E, 0x27, 0x00, 0x00, 0x57, 0x26, 0x00, 0x00, 
	0x90, 0x25, 0x00, 0x00, 0xC9, 0x24, 0x00, 0x00, 0x02, 0x24, 0x00, 0x00, 0x3B, 0x23, 0x00, 0x00, 
	0x74, 0x22, 0x00, 0x00, 0xAD, 0x21, 0x00, 0x00, 0xE5, 0x20, 0x00, 0x00, 0x1E, 0x20, 0x00, 0x00, 
	0x56, 0x1F, 0x00, 0x00, 0x8F, 0x1E, 0x00, 0x00, 0xC7, 0x1D, 0x00, 0x00, 0xFF, 0x1C, 0x00, 0x00, 
	0x38, 0x1C, 0x00, 0x00, 0x70, 0x1B, 0x00, 0x00, 0xA8, 0x1A, 0x00, 0x00, 0xE0, 0x19, 0x00, 0x00, 
	0x18, 0x19, 0x00, 0x00, 0x50, 0x18, 0x00, 0x00, 0x87, 0x17, 0x00, 0x00, 0xBF, 0x16, 0x00, 0x00, 
	0xF7, 0x15, 0x00, 0x00, 0x2E, 0x15, 0x00, 0x00, 0x66, 0x14, 0x00, 0x00, 0x9E, 0x13, 0x00, 0x00, 
	0xD5, 0x12, 0x00, 0x00, 0x0D, 0x12, 0x00, 0x00, 0x44, 0x11, 0x00, 0x00, 0x7B, 0x10, 0x00, 0x00, 
	0xB3, 0x0F, 0x00, 0x00, 0xEA, 0x0E, 0x00, 0x00, 0x21, 0x0E, 0x00, 0x00, 0x59, 0x0D, 0x00, 0x00, 
	0x90, 0x0C, 0x00, 0x00, 0xC7, 0x0B, 0x00, 0x00, 0xFE, 0x0A, 0x00, 0x00, 0x35, 0x0A, 0x00, 0x00, 
	0x6C, 0x09, 0x00, 0x00, 0xA3, 0x08, 0x00, 0x00, 0xDA, 0x07, 0x00, 0x00, 0x11, 0x07, 0x00, 0x00, 
	0x48, 0x06, 0x00, 0x00, 0x7F, 0x05, 0x00, 0x00, 0xB6, 0x04, 0x00, 0x00, 0xED, 0x03, 0x00, 0x00, 
	0x24, 0x03, 0x00, 0x00, 0x5B, 0x02, 0x00, 0x00, 0x92, 0x01, 0x00, 0x00, 0xC9, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
 },
 pInvCosTable[0x820] =
 {
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 
	0x05, 0x00, 0x01, 0x00, 0x08, 0x00, 0x01, 0x00, 0x0B, 0x00, 0x01, 0x00, 0x0F, 0x00, 0x01, 0x00, 
	0x14, 0x00, 0x01, 0x00, 0x19, 0x00, 0x01, 0x00, 0x1F, 0x00, 0x01, 0x00, 0x25, 0x00, 0x01, 0x00, 
	0x2C, 0x00, 0x01, 0x00, 0x34, 0x00, 0x01, 0x00, 0x3C, 0x00, 0x01, 0x00, 0x45, 0x00, 0x01, 0x00, 
	0x4F, 0x00, 0x01, 0x00, 0x59, 0x00, 0x01, 0x00, 0x64, 0x00, 0x01, 0x00, 0x6F, 0x00, 0x01, 0x00, 
	0x7C, 0x00, 0x01, 0x00, 0x88, 0x00, 0x01, 0x00, 0x96, 0x00, 0x01, 0x00, 0xA3, 0x00, 0x01, 0x00, 
	0xB2, 0x00, 0x01, 0x00, 0xC1, 0x00, 0x01, 0x00, 0xD1, 0x00, 0x01, 0x00, 0xE1, 0x00, 0x01, 0x00, 
	0xF3, 0x00, 0x01, 0x00, 0x04, 0x01, 0x01, 0x00, 0x17, 0x01, 0x01, 0x00, 0x2A, 0x01, 0x01, 0x00, 
	0x3D, 0x01, 0x01, 0x00, 0x51, 0x01, 0x01, 0x00, 0x66, 0x01, 0x01, 0x00, 0x7C, 0x01, 0x01, 0x00, 
	0x92, 0x01, 0x01, 0x00, 0xA9, 0x01, 0x01, 0x00, 0xC0, 0x01, 0x01, 0x00, 0xD8, 0x01, 0x01, 0x00, 
	0xF1, 0x01, 0x01, 0x00, 0x0A, 0x02, 0x01, 0x00, 0x24, 0x02, 0x01, 0x00, 0x3E, 0x02, 0x01, 0x00, 
	0x5A, 0x02, 0x01, 0x00, 0x76, 0x02, 0x01, 0x00, 0x92, 0x02, 0x01, 0x00, 0xAF, 0x02, 0x01, 0x00, 
	0xCD, 0x02, 0x01, 0x00, 0xEC, 0x02, 0x01, 0x00, 0x0B, 0x03, 0x01, 0x00, 0x2A, 0x03, 0x01, 0x00, 
	0x4B, 0x03, 0x01, 0x00, 0x6C, 0x03, 0x01, 0x00, 0x8E, 0x03, 0x01, 0x00, 0xB0, 0x03, 0x01, 0x00, 
	0xD3, 0x03, 0x01, 0x00, 0xF7, 0x03, 0x01, 0x00, 0x1B, 0x04, 0x01, 0x00, 0x40, 0x04, 0x01, 0x00, 
	0x66, 0x04, 0x01, 0x00, 0x8D, 0x04, 0x01, 0x00, 0xB4, 0x04, 0x01, 0x00, 0xDB, 0x04, 0x01, 0x00, 
	0x04, 0x05, 0x01, 0x00, 0x2D, 0x05, 0x01, 0x00, 0x57, 0x05, 0x01, 0x00, 0x81, 0x05, 0x01, 0x00, 
	0xAC, 0x05, 0x01, 0x00, 0xD8, 0x05, 0x01, 0x00, 0x05, 0x06, 0x01, 0x00, 0x32, 0x06, 0x01, 0x00, 
	0x60, 0x06, 0x01, 0x00, 0x8F, 0x06, 0x01, 0x00, 0xBE, 0x06, 0x01, 0x00, 0xEE, 0x06, 0x01, 0x00, 
	0x1F, 0x07, 0x01, 0x00, 0x50, 0x07, 0x01, 0x00, 0x82, 0x07, 0x01, 0x00, 0xB5, 0x07, 0x01, 0x00, 
	0xE9, 0x07, 0x01, 0x00, 0x1D, 0x08, 0x01, 0x00, 0x52, 0x08, 0x01, 0x00, 0x88, 0x08, 0x01, 0x00, 
	0xBE, 0x08, 0x01, 0x00, 0xF5, 0x08, 0x01, 0x00, 0x2D, 0x09, 0x01, 0x00, 0x66, 0x09, 0x01, 0x00, 
	0x9F, 0x09, 0x01, 0x00, 0xD9, 0x09, 0x01, 0x00, 0x14, 0x0A, 0x01, 0x00, 0x50, 0x0A, 0x01, 0x00, 
	0x8C, 0x0A, 0x01, 0x00, 0xC9, 0x0A, 0x01, 0x00, 0x07, 0x0B, 0x01, 0x00, 0x46, 0x0B, 0x01, 0x00, 
	0x85, 0x0B, 0x01, 0x00, 0xC5, 0x0B, 0x01, 0x00, 0x06, 0x0C, 0x01, 0x00, 0x48, 0x0C, 0x01, 0x00, 
	0x8A, 0x0C, 0x01, 0x00, 0xCD, 0x0C, 0x01, 0x00, 0x11, 0x0D, 0x01, 0x00, 0x56, 0x0D, 0x01, 0x00, 
	0x9C, 0x0D, 0x01, 0x00, 0xE2, 0x0D, 0x01, 0x00, 0x29, 0x0E, 0x01, 0x00, 0x71, 0x0E, 0x01, 0x00, 
	0xBA, 0x0E, 0x01, 0x00, 0x03, 0x0F, 0x01, 0x00, 0x4E, 0x0F, 0x01, 0x00, 0x99, 0x0F, 0x01, 0x00, 
	0xE5, 0x0F, 0x01, 0x00, 0x32, 0x10, 0x01, 0x00, 0x7F, 0x10, 0x01, 0x00, 0xCE, 0x10, 0x01, 0x00, 
	0x1D, 0x11, 0x01, 0x00, 0x6D, 0x11, 0x01, 0x00, 0xBE, 0x11, 0x01, 0x00, 0x10, 0x12, 0x01, 0x00, 
	0x63, 0x12, 0x01, 0x00, 0xB6, 0x12, 0x01, 0x00, 0x0B, 0x13, 0x01, 0x00, 0x60, 0x13, 0x01, 0x00, 
	0xB6, 0x13, 0x01, 0x00, 0x0D, 0x14, 0x01, 0x00, 0x65, 0x14, 0x01, 0x00, 0xBE, 0x14, 0x01, 0x00, 
	0x18, 0x15, 0x01, 0x00, 0x72, 0x15, 0x01, 0x00, 0xCE, 0x15, 0x01, 0x00, 0x2A, 0x16, 0x01, 0x00, 
	0x87, 0x16, 0x01, 0x00, 0xE6, 0x16, 0x01, 0x00, 0x45, 0x17, 0x01, 0x00, 0xA5, 0x17, 0x01, 0x00, 
	0x06, 0x18, 0x01, 0x00, 0x68, 0x18, 0x01, 0x00, 0xCB, 0x18, 0x01, 0x00, 0x2F, 0x19, 0x01, 0x00, 
	0x93, 0x19, 0x01, 0x00, 0xF9, 0x19, 0x01, 0x00, 0x60, 0x1A, 0x01, 0x00, 0xC8, 0x1A, 0x01, 0x00, 
	0x30, 0x1B, 0x01, 0x00, 0x9A, 0x1B, 0x01, 0x00, 0x05, 0x1C, 0x01, 0x00, 0x70, 0x1C, 0x01, 0x00, 
	0xDD, 0x1C, 0x01, 0x00, 0x4B, 0x1D, 0x01, 0x00, 0xBA, 0x1D, 0x01, 0x00, 0x29, 0x1E, 0x01, 0x00, 
	0x9A, 0x1E, 0x01, 0x00, 0x0C, 0x1F, 0x01, 0x00, 0x7F, 0x1F, 0x01, 0x00, 0xF3, 0x1F, 0x01, 0x00, 
	0x68, 0x20, 0x01, 0x00, 0xDE, 0x20, 0x01, 0x00, 0x55, 0x21, 0x01, 0x00, 0xCD, 0x21, 0x01, 0x00, 
	0x46, 0x22, 0x01, 0x00, 0xC1, 0x22, 0x01, 0x00, 0x3C, 0x23, 0x01, 0x00, 0xB9, 0x23, 0x01, 0x00, 
	0x37, 0x24, 0x01, 0x00, 0xB6, 0x24, 0x01, 0x00, 0x36, 0x25, 0x01, 0x00, 0xB7, 0x25, 0x01, 0x00, 
	0x39, 0x26, 0x01, 0x00, 0xBD, 0x26, 0x01, 0x00, 0x41, 0x27, 0x01, 0x00, 0xC7, 0x27, 0x01, 0x00, 
	0x4E, 0x28, 0x01, 0x00, 0xD6, 0x28, 0x01, 0x00, 0x60, 0x29, 0x01, 0x00, 0xEB, 0x29, 0x01, 0x00, 
	0x76, 0x2A, 0x01, 0x00, 0x04, 0x2B, 0x01, 0x00, 0x92, 0x2B, 0x01, 0x00, 0x22, 0x2C, 0x01, 0x00, 
	0xB2, 0x2C, 0x01, 0x00, 0x45, 0x2D, 0x01, 0x00, 0xD8, 0x2D, 0x01, 0x00, 0x6D, 0x2E, 0x01, 0x00, 
	0x03, 0x2F, 0x01, 0x00, 0x9A, 0x2F, 0x01, 0x00, 0x33, 0x30, 0x01, 0x00, 0xCD, 0x30, 0x01, 0x00, 
	0x68, 0x31, 0x01, 0x00, 0x05, 0x32, 0x01, 0x00, 0xA3, 0x32, 0x01, 0x00, 0x43, 0x33, 0x01, 0x00, 
	0xE3, 0x33, 0x01, 0x00, 0x86, 0x34, 0x01, 0x00, 0x29, 0x35, 0x01, 0x00, 0xCF, 0x35, 0x01, 0x00, 
	0x75, 0x36, 0x01, 0x00, 0x1D, 0x37, 0x01, 0x00, 0xC7, 0x37, 0x01, 0x00, 0x72, 0x38, 0x01, 0x00, 
	0x1E, 0x39, 0x01, 0x00, 0xCC, 0x39, 0x01, 0x00, 0x7B, 0x3A, 0x01, 0x00, 0x2C, 0x3B, 0x01, 0x00, 
	0xDF, 0x3B, 0x01, 0x00, 0x93, 0x3C, 0x01, 0x00, 0x49, 0x3D, 0x01, 0x00, 0x00, 0x3E, 0x01, 0x00, 
	0xB9, 0x3E, 0x01, 0x00, 0x73, 0x3F, 0x01, 0x00, 0x2F, 0x40, 0x01, 0x00, 0xED, 0x40, 0x01, 0x00, 
	0xAD, 0x41, 0x01, 0x00, 0x6E, 0x42, 0x01, 0x00, 0x30, 0x43, 0x01, 0x00, 0xF5, 0x43, 0x01, 0x00, 
	0xBB, 0x44, 0x01, 0x00, 0x83, 0x45, 0x01, 0x00, 0x4D, 0x46, 0x01, 0x00, 0x18, 0x47, 0x01, 0x00, 
	0xE5, 0x47, 0x01, 0x00, 0xB4, 0x48, 0x01, 0x00, 0x85, 0x49, 0x01, 0x00, 0x58, 0x4A, 0x01, 0x00, 
	0x2C, 0x4B, 0x01, 0x00, 0x03, 0x4C, 0x01, 0x00, 0xDB, 0x4C, 0x01, 0x00, 0xB5, 0x4D, 0x01, 0x00, 
	0x91, 0x4E, 0x01, 0x00, 0x6F, 0x4F, 0x01, 0x00, 0x4F, 0x50, 0x01, 0x00, 0x31, 0x51, 0x01, 0x00, 
	0x15, 0x52, 0x01, 0x00, 0xFC, 0x52, 0x01, 0x00, 0xE4, 0x53, 0x01, 0x00, 0xCE, 0x54, 0x01, 0x00, 
	0xBA, 0x55, 0x01, 0x00, 0xA8, 0x56, 0x01, 0x00, 0x99, 0x57, 0x01, 0x00, 0x8C, 0x58, 0x01, 0x00, 
	0x80, 0x59, 0x01, 0x00, 0x78, 0x5A, 0x01, 0x00, 0x71, 0x5B, 0x01, 0x00, 0x6C, 0x5C, 0x01, 0x00, 
	0x6A, 0x5D, 0x01, 0x00, 0x6A, 0x5E, 0x01, 0x00, 0x6D, 0x5F, 0x01, 0x00, 0x71, 0x60, 0x01, 0x00, 
	0x78, 0x61, 0x01, 0x00, 0x82, 0x62, 0x01, 0x00, 0x8E, 0x63, 0x01, 0x00, 0x9C, 0x64, 0x01, 0x00, 
	0xAD, 0x65, 0x01, 0x00, 0xC1, 0x66, 0x01, 0x00, 0xD6, 0x67, 0x01, 0x00, 0xEF, 0x68, 0x01, 0x00, 
	0x0A, 0x6A, 0x01, 0x00, 0x28, 0x6B, 0x01, 0x00, 0x48, 0x6C, 0x01, 0x00, 0x6B, 0x6D, 0x01, 0x00, 
	0x91, 0x6E, 0x01, 0x00, 0xB9, 0x6F, 0x01, 0x00, 0xE4, 0x70, 0x01, 0x00, 0x12, 0x72, 0x01, 0x00, 
	0x43, 0x73, 0x01, 0x00, 0x77, 0x74, 0x01, 0x00, 0xAD, 0x75, 0x01, 0x00, 0xE7, 0x76, 0x01, 0x00, 
	0x23, 0x78, 0x01, 0x00, 0x63, 0x79, 0x01, 0x00, 0xA5, 0x7A, 0x01, 0x00, 0xEB, 0x7B, 0x01, 0x00, 
	0x34, 0x7D, 0x01, 0x00, 0x80, 0x7E, 0x01, 0x00, 0xCF, 0x7F, 0x01, 0x00, 0x21, 0x81, 0x01, 0x00, 
	0x77, 0x82, 0x01, 0x00, 0xD0, 0x83, 0x01, 0x00, 0x2C, 0x85, 0x01, 0x00, 0x8C, 0x86, 0x01, 0x00, 
	0xEF, 0x87, 0x01, 0x00, 0x55, 0x89, 0x01, 0x00, 0xC0, 0x8A, 0x01, 0x00, 0x2D, 0x8C, 0x01, 0x00, 
	0x9F, 0x8D, 0x01, 0x00, 0x14, 0x8F, 0x01, 0x00, 0x8C, 0x90, 0x01, 0x00, 0x09, 0x92, 0x01, 0x00, 
	0x89, 0x93, 0x01, 0x00, 0x0D, 0x95, 0x01, 0x00, 0x95, 0x96, 0x01, 0x00, 0x21, 0x98, 0x01, 0x00, 
	0xB1, 0x99, 0x01, 0x00, 0x45, 0x9B, 0x01, 0x00, 0xDD, 0x9C, 0x01, 0x00, 0x7A, 0x9E, 0x01, 0x00, 
	0x1A, 0xA0, 0x01, 0x00, 0xBF, 0xA1, 0x01, 0x00, 0x69, 0xA3, 0x01, 0x00, 0x16, 0xA5, 0x01, 0x00, 
	0xC9, 0xA6, 0x01, 0x00, 0x7F, 0xA8, 0x01, 0x00, 0x3B, 0xAA, 0x01, 0x00, 0xFB, 0xAB, 0x01, 0x00, 
	0xBF, 0xAD, 0x01, 0x00, 0x89, 0xAF, 0x01, 0x00, 0x57, 0xB1, 0x01, 0x00, 0x2A, 0xB3, 0x01, 0x00, 
	0x03, 0xB5, 0x01, 0x00, 0xE0, 0xB6, 0x01, 0x00, 0xC3, 0xB8, 0x01, 0x00, 0xAB, 0xBA, 0x01, 0x00, 
	0x98, 0xBC, 0x01, 0x00, 0x8A, 0xBE, 0x01, 0x00, 0x82, 0xC0, 0x01, 0x00, 0x80, 0xC2, 0x01, 0x00, 
	0x83, 0xC4, 0x01, 0x00, 0x8C, 0xC6, 0x01, 0x00, 0x9A, 0xC8, 0x01, 0x00, 0xAF, 0xCA, 0x01, 0x00, 
	0xCA, 0xCC, 0x01, 0x00, 0xEA, 0xCE, 0x01, 0x00, 0x11, 0xD1, 0x01, 0x00, 0x3E, 0xD3, 0x01, 0x00, 
	0x72, 0xD5, 0x01, 0x00, 0xAC, 0xD7, 0x01, 0x00, 0xEC, 0xD9, 0x01, 0x00, 0x34, 0xDC, 0x01, 0x00, 
	0x82, 0xDE, 0x01, 0x00, 0xD7, 0xE0, 0x01, 0x00, 0x33, 0xE3, 0x01, 0x00, 0x96, 0xE5, 0x01, 0x00, 
	0x00, 0xE8, 0x01, 0x00, 0x72, 0xEA, 0x01, 0x00, 0xEB, 0xEC, 0x01, 0x00, 0x6C, 0xEF, 0x01, 0x00, 
	0xF4, 0xF1, 0x01, 0x00, 0x85, 0xF4, 0x01, 0x00, 0x1D, 0xF7, 0x01, 0x00, 0xBE, 0xF9, 0x01, 0x00, 
	0x67, 0xFC, 0x01, 0x00, 0x18, 0xFF, 0x01, 0x00, 0xD2, 0x01, 0x02, 0x00, 0x95, 0x04, 0x02, 0x00, 
	0x61, 0x07, 0x02, 0x00, 0x35, 0x0A, 0x02, 0x00, 0x13, 0x0D, 0x02, 0x00, 0xFA, 0x0F, 0x02, 0x00, 
	0xEB, 0x12, 0x02, 0x00, 0xE5, 0x15, 0x02, 0x00, 0xEA, 0x18, 0x02, 0x00, 0xF8, 0x1B, 0x02, 0x00, 
	0x11, 0x1F, 0x02, 0x00, 0x34, 0x22, 0x02, 0x00, 0x62, 0x25, 0x02, 0x00, 0x9B, 0x28, 0x02, 0x00, 
	0xDF, 0x2B, 0x02, 0x00, 0x2E, 0x2F, 0x02, 0x00, 0x89, 0x32, 0x02, 0x00, 0xEF, 0x35, 0x02, 0x00, 
	0x61, 0x39, 0x02, 0x00, 0xE0, 0x3C, 0x02, 0x00, 0x6B, 0x40, 0x02, 0x00, 0x03, 0x44, 0x02, 0x00, 
	0xA7, 0x47, 0x02, 0x00, 0x59, 0x4B, 0x02, 0x00, 0x19, 0x4F, 0x02, 0x00, 0xE6, 0x52, 0x02, 0x00, 
	0xC1, 0x56, 0x02, 0x00, 0xAA, 0x5A, 0x02, 0x00, 0xA2, 0x5E, 0x02, 0x00, 0xAA, 0x62, 0x02, 0x00, 
	0xC0, 0x66, 0x02, 0x00, 0xE6, 0x6A, 0x02, 0x00, 0x1C, 0x6F, 0x02, 0x00, 0x62, 0x73, 0x02, 0x00, 
	0xB9, 0x77, 0x02, 0x00, 0x21, 0x7C, 0x02, 0x00, 0x9A, 0x80, 0x02, 0x00, 0x25, 0x85, 0x02, 0x00, 
	0xC2, 0x89, 0x02, 0x00, 0x72, 0x8E, 0x02, 0x00, 0x35, 0x93, 0x02, 0x00, 0x0C, 0x98, 0x02, 0x00, 
	0xF6, 0x9C, 0x02, 0x00, 0xF5, 0xA1, 0x02, 0x00, 0x08, 0xA7, 0x02, 0x00, 0x31, 0xAC, 0x02, 0x00, 
	0x70, 0xB1, 0x02, 0x00, 0xC5, 0xB6, 0x02, 0x00, 0x32, 0xBC, 0x02, 0x00, 0xB6, 0xC1, 0x02, 0x00, 
	0x52, 0xC7, 0x02, 0x00, 0x06, 0xCD, 0x02, 0x00, 0xD4, 0xD2, 0x02, 0x00, 0xBD, 0xD8, 0x02, 0x00, 
	0xC0, 0xDE, 0x02, 0x00, 0xDE, 0xE4, 0x02, 0x00, 0x18, 0xEB, 0x02, 0x00, 0x70, 0xF1, 0x02, 0x00, 
	0xE4, 0xF7, 0x02, 0x00, 0x78, 0xFE, 0x02, 0x00, 0x2A, 0x05, 0x03, 0x00, 0xFD, 0x0B, 0x03, 0x00, 
	0xF1, 0x12, 0x03, 0x00, 0x07, 0x1A, 0x03, 0x00, 0x3F, 0x21, 0x03, 0x00, 0x9C, 0x28, 0x03, 0x00, 
	0x1D, 0x30, 0x03, 0x00, 0xC5, 0x37, 0x03, 0x00, 0x93, 0x3F, 0x03, 0x00, 0x8A, 0x47, 0x03, 0x00, 
	0xAA, 0x4F, 0x03, 0x00, 0xF5, 0x57, 0x03, 0x00, 0x6D, 0x60, 0x03, 0x00, 0x11, 0x69, 0x03, 0x00, 
	0xE5, 0x71, 0x03, 0x00, 0xE8, 0x7A, 0x03, 0x00, 0x1E, 0x84, 0x03, 0x00, 0x87, 0x8D, 0x03, 0x00, 
	0x25, 0x97, 0x03, 0x00, 0xFA, 0xA0, 0x03, 0x00, 0x08, 0xAB, 0x03, 0x00, 0x50, 0xB5, 0x03, 0x00, 
	0xD6, 0xBF, 0x03, 0x00, 0x99, 0xCA, 0x03, 0x00, 0x9E, 0xD5, 0x03, 0x00, 0xE6, 0xE0, 0x03, 0x00, 
	0x73, 0xEC, 0x03, 0x00, 0x49, 0xF8, 0x03, 0x00, 0x69, 0x04, 0x04, 0x00, 0xD7, 0x10, 0x04, 0x00, 
	0x95, 0x1D, 0x04, 0x00, 0xA7, 0x2A, 0x04, 0x00, 0x10, 0x38, 0x04, 0x00, 0xD2, 0x45, 0x04, 0x00, 
	0xF2, 0x53, 0x04, 0x00, 0x74, 0x62, 0x04, 0x00, 0x5B, 0x71, 0x04, 0x00, 0xAB, 0x80, 0x04, 0x00, 
	0x69, 0x90, 0x04, 0x00, 0x99, 0xA0, 0x04, 0x00, 0x41, 0xB1, 0x04, 0x00, 0x66, 0xC2, 0x04, 0x00, 
	0x0D, 0xD4, 0x04, 0x00, 0x3B, 0xE6, 0x04, 0x00, 0xF8, 0xF8, 0x04, 0x00, 0x49, 0x0C, 0x05, 0x00, 
	0x36, 0x20, 0x05, 0x00, 0xC6, 0x34, 0x05, 0x00, 0x01, 0x4A, 0x05, 0x00, 0xF0, 0x5F, 0x05, 0x00, 
	0x9A, 0x76, 0x05, 0x00, 0x0B, 0x8E, 0x05, 0x00, 0x4B, 0xA6, 0x05, 0x00, 0x67, 0xBF, 0x05, 0x00, 
	0x69, 0xD9, 0x05, 0x00, 0x5F, 0xF4, 0x05, 0x00, 0x55, 0x10, 0x06, 0x00, 0x5B, 0x2D, 0x06, 0x00, 
	0x80, 0x4B, 0x06, 0x00, 0xD5, 0x6A, 0x06, 0x00, 0x6C, 0x8B, 0x06, 0x00, 0x5A, 0xAD, 0x06, 0x00, 
	0xB2, 0xD0, 0x06, 0x00, 0x8D, 0xF5, 0x06, 0x00, 0x04, 0x1C, 0x07, 0x00, 0x31, 0x44, 0x07, 0x00, 
	0x34, 0x6E, 0x07, 0x00, 0x2D, 0x9A, 0x07, 0x00, 0x3F, 0xC8, 0x07, 0x00, 0x93, 0xF8, 0x07, 0x00, 
	0x52, 0x2B, 0x08, 0x00, 0xAE, 0x60, 0x08, 0x00, 0xDA, 0x98, 0x08, 0x00, 0x11, 0xD4, 0x08, 0x00, 
	0x95, 0x12, 0x09, 0x00, 0xAD, 0x54, 0x09, 0x00, 0xAA, 0x9A, 0x09, 0x00, 0xE7, 0xE4, 0x09, 0x00, 
	0xCA, 0x33, 0x0A, 0x00, 0xC6, 0x87, 0x0A, 0x00, 0x5D, 0xE1, 0x0A, 0x00, 0x25, 0x41, 0x0B, 0x00, 
	0xC7, 0xA7, 0x0B, 0x00, 0x05, 0x16, 0x0C, 0x00, 0xC1, 0x8C, 0x0C, 0x00, 0xFF, 0x0C, 0x0D, 0x00, 
	0xF0, 0x97, 0x0D, 0x00, 0xF8, 0x2E, 0x0E, 0x00, 0xBF, 0xD3, 0x0E, 0x00, 0x3A, 0x88, 0x0F, 0x00, 
	0xC5, 0x4E, 0x10, 0x00, 0x3A, 0x2A, 0x11, 0x00, 0x15, 0x1E, 0x12, 0x00, 0xA4, 0x2E, 0x13, 0x00, 
	0x49, 0x61, 0x14, 0x00, 0xD5, 0xBC, 0x15, 0x00, 0x0D, 0x4A, 0x17, 0x00, 0x65, 0x14, 0x19, 0x00, 
	0x28, 0x2B, 0x1B, 0x00, 0x2B, 0xA3, 0x1D, 0x00, 0x9D, 0x99, 0x20, 0x00, 0xA0, 0x38, 0x24, 0x00, 
	0x6D, 0xBF, 0x28, 0x00, 0x59, 0x91, 0x2E, 0x00, 0xF5, 0x53, 0x36, 0x00, 0x43, 0x31, 0x41, 0x00, 
	0x48, 0x7D, 0x51, 0x00, 0xBC, 0xA6, 0x6C, 0x00, 0xC6, 0xF9, 0xA2, 0x00, 0x28, 0xF3, 0x45, 0x01, 
	0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xEF, 
	0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xEF
 };

 _this->pTanTable[0] = 0;
 _this->pCosTable[0] = 65536;
 _this->pInvCosTable[0] = 65536;

 _this->uIntegerPi = 1024;
 _this->uIntegerHalfPi = 512;
 _this->uIntegerDoublePi = 2048;

 _this->uDoublePiMask = 2047;
 _this->uPiMask = 1023;
 _this->uHalfPiMask = 511;

 memcpy(_this->pTanTable, pTanTable, 0x820);
 memcpy(_this->pCosTable, pCosTable, 0x820);
 memcpy(_this->pInvCosTable, pInvCosTable, 0x820);
 /*
  for (i = 0; i < _this->dword_001864; ++i)
  {
    v3 = (double)(i + 1) * memory_4D8410.dPi * (1.0 / 1024.0);  // i * ï * step
   _this->pTanTable[i] = tan(v3) * (double)_this->pCosTable[0] + memory_4D8410.d_0_5;
   _this->pCosTable[i] = cos(v3) * (double)_this->pCosTable[0] + memory_4D8410.d_0_5;
   _this->pInvCosTable[i] = memory_4D8410.d1_0 / cos(v3) * (double)_this->pCosTable[0] + memory_4D8410.d_0_5;
  }*/

 for (i = _this->uIntegerHalfPi; i < 520; ++i)
 {
  _this->pTanTable[i] = -268435457;
  _this->pCosTable[i] = 0;
  _this->pInvCosTable[i] = -268435457;
 }
}



//----- (0045D3C7) --------------------------------------------------------
bool __stdcall sub_45D3C7(struct struct8 *_this)
{
 struct struct8 *v2; // ecx@2
 struct Span    *i; // edi@5

 if (!_this->ptr_000040)
   return false;

 if (_this->ptr_000040->pParent)
 {
  v2 = _this->ptr_000040->pParent;
  if (v2->ptr_000040)
  {
   for (i = _this->ptr_000040; ; i = i->pNext)
   {
    compile_error;
    //if (i->pParent->byte_000108)
    //   sub_45D426((int)i, _this->array_000060, _this->dword_0000B0, _this->array_0000B4, _this->dword_000104);
     if (_this->ptr_000044 == i)
       break;
   }
   return true;
  }
 }
 return false;
}



//----- (00438240) --------------------------------------------------------
void class08_sub_438240(struct class08 *_this)
{
  int v1; // edi@2
  int v2; // ebx@3
  int v3; // esi@4
  double v4; // st7@6
  int v5; // ST00_4@8
  int v6; // ebp@1
  int v7; // esi@1
  int v8; // [sp+4h] [bp-28h]@6
  int v9; // [sp+8h] [bp-24h]@6
  int v10; // [sp+Ch] [bp-20h]@6
  char v11; // [sp+10h] [bp-1Ch]@6
  float v12; // [sp+14h] [bp-18h]@6
  int v13; // [sp+28h] [bp-4h]@1

  v7 = (int)_this;
  class08_sub_438141(_this);
  v13 = 0;
  v6 = v7;
  if (!_this->dword_1A1380)
    return;

    v1 = v7 + 921476;
    do
    {
      v2 = 0;
      if ( *(_DWORD *)v1 > 0 )
      {
        v3 = v1 - 3048;
        do
        {
          if ( *(_BYTE *)(v1 - 3076) & 1 )
          {
            LODWORD(v12) = 1;
            v11 = 1;
            v10 = *(_DWORD *)(v1 + 4);
            *(float *)&v9 = 0.0;
            *(float *)&v8 = *(float *)(v3 + 4);
            v4 = *(float *)v3;
          }
          else
          {
            LODWORD(v12) = 0;
            v11 = 1;
            v10 = *(_DWORD *)(v1 + 4);
            *(float *)&v9 = *(float *)(v3 - 16);
            *(float *)&v8 = *(float *)(v3 - 20);
            v4 = *(float *)(v3 - 24);
          }
          *(float *)&v5 = v4;
          sub_437D4A((void *)v6, v5, v8, v9, v10, v11, v12);
          ++v2;
          v3 += 48;
        }
        while ( v2 < *(_DWORD *)v1 );
      }
      ++v13;
      v1 += 3088;
    }
    while ( v13 < *(_DWORD *)(v6 + 1708928) );
}



//----- (00438141) --------------------------------------------------------
void class08_sub_438141(struct class08 *_this)
{
  int v1; // ebx@1
  int v2; // edi@1
  int v3; // esi@2
  double v4; // st7@4
  int v5; // ST00_4@6
  int v6; // [sp+4h] [bp-20h]@4
  int v7; // [sp+8h] [bp-1Ch]@4
  int v8; // [sp+Ch] [bp-18h]@4
  char v9; // [sp+10h] [bp-14h]@4
  float v10; // [sp+14h] [bp-10h]@4

  v2 = (int)_this;
  v1 = 0;
  if (!_this->dword_0E037C)
    return;

    v3 = v2 + 924;
    do
    {
      if ( *(_BYTE *)(v3 - 32) & 1 )
      {
        LODWORD(v10) = 1;
        v9 = 1;
        v8 = *(_DWORD *)(v3 + 20);
        *(float *)&v7 = 0.0;
        *(float *)&v6 = *(float *)v3;
        v4 = *(float *)(v3 - 4);
      }
      else
      {
        LODWORD(v10) = 0;
        v9 = 1;
        v8 = *(_DWORD *)(v3 + 20);
        *(float *)&v7 = *(float *)(v3 - 20);
        *(float *)&v6 = *(float *)(v3 - 24);
        v4 = *(float *)(v3 - 28);
      }
      *(float *)&v5 = v4;
      sub_437D4A((void *)v2, v5, v6, v7, v8, v9, v10);
      ++v1;
      v3 += 56;
    }
    while ( v1 < *(_DWORD *)(v2 + 918396) );

}

//----- (0048607B) --------------------------------------------------------
void sub_48607B_MessWithStruct8(struct struct8 *_this, struct class57 *pClass57)
{
 _this->ptr_000038 = pClass57;
 _this->ptr_00003C = 0;
}

//----- (0043B6EF) --------------------------------------------------------
bool class36_sub_43B6EF(struct class36 *_this, int a2, int a3, int a4, int a5, char a6, char a7, char a8)
{
 int v7;
  int v8; // esi@1
  int v9; // eax@3
  int v10; // ecx@3
  int v11; // eax@3
  int v12; // eax@3

  v7 = (int)_this;
  v8 = v7 + 2568;
  if ( *(_DWORD *)(v7 + 2568) == 64 )
    *(_DWORD *)v8 = 0;
  v11 = 5 * *(_DWORD *)v8++;
  v12 = v7 + 8 * v11 + 4;
  *(_DWORD *)(v12 + 4) = a2;
  *(_DWORD *)(v12 + 8) = a3;
  *(_DWORD *)(v12 + 12) = a4;
  *(_DWORD *)(v12 + 16) = a5;
  *(_BYTE *)(v12 + 24) = a6;
  *(_BYTE *)(v12 + 25) = a7;
  *(_BYTE *)(v12 + 26) = a8;
  v9 = v7 + 2564;
  v10 = *(_DWORD *)(v7 + 2564) + 1;
  if ( v10 > 64 )
    v10 = 64;
  *(_DWORD *)v9 = v10;
  return true;
}

//----- (004A81CA) --------------------------------------------------------
bool class06_sub_4A81CA(struct class06 *_this, int a2)
{
  signed int v2; // eax@1
  int v3; // ebx@1
  int v4; // eax@26
  int v5; // eax@27
  int v6; // eax@28
  int v8; // esi@41
  int v9; // eax@47
  int v10; // ecx@49
  int v11; // eax@53
  int v12; // eax@54
  int v13; // eax@55
  char v14; // zf@56
  int v15; // eax@59
  int v16; // eax@60
  int v17; // eax@61
  int v18; // eax@85
  int v19; // eax@86
  int v20; // eax@87
  int v21; // eax@94
  int v22; // eax@95
  int v23; // eax@96
  int v24; // eax@101
  int v25; // eax@102
  int v26; // eax@110
  int v27; // eax@111
  int v28; // eax@112
  int v29; // eax@118
  int v30; // eax@119
  int v31; // eax@120
  int v32; // eax@125
  int v33; // eax@126
  int v34; // eax@127
  int v35; // eax@131
  int v36; // eax@132
  int v37; // eax@139
  int v38; // eax@140
  int v39; // eax@141
  int v40; // eax@149
  int v41; // eax@150
  int v42; // eax@151
  int v43; // eax@160
  int v44; // eax@161
  int v45; // eax@162
  int v46; // eax@165
  int v47; // eax@166
  int v48; // [sp-8h] [bp-20h]@66
  int v49; // [sp-8h] [bp-20h]@81
  int v50; // [sp-4h] [bp-1Ch]@4
  int v51; // [sp-4h] [bp-1Ch]@5
  unsigned int v52; // [sp-4h] [bp-1Ch]@30
  int v53; // [sp-4h] [bp-1Ch]@57
  int v54; // [sp-4h] [bp-1Ch]@66
  int v55; // [sp-4h] [bp-1Ch]@81
  int v56; // [sp+0h] [bp-18h]@4
  int v57; // [sp+0h] [bp-18h]@5
  int v58; // [sp+0h] [bp-18h]@30
  int v59; // [sp+0h] [bp-18h]@45
  float v60; // [sp+0h] [bp-18h]@57
  float v61; // [sp+0h] [bp-18h]@66
  signed int v62; // [sp+0h] [bp-18h]@81
  int Str1; // [sp+10h] [bp-8h]@81
  __int16 v64; // [sp+14h] [bp-4h]@81
  char v65; // [sp+16h] [bp-2h]@81

  v3 = (int)_this;
  v2 = *(_WORD *)a2;
  if ( v2 <= 545 )
  {
    if ( v2 != 545 )
    {
      switch ( v2 )
      {
        case 500:
        case 530:
          v56 = *(_DWORD *)(v3 + 1508);
          v50 = 0xAAAFF;
          goto LABEL_8;
        case 501:
        case 531:
          v57 = *(_DWORD *)(v3 + 1508);
          v51 = 0xAAAFF;
          goto LABEL_32;
        case 505:
          v56 = *(_DWORD *)(v3 + 1508);
          v50 = (int)&unk_5C310E;
          goto LABEL_8;
        case 510:
          v56 = *(_DWORD *)(v3 + 1508);
          v50 = 0xFF3C1E;
          goto LABEL_8;
        case 515:
          v56 = *(_DWORD *)(v3 + 1508);
          v50 = 0x62D0;
          goto LABEL_8;
        case 516:
          v57 = *(_DWORD *)(v3 + 1508);
          v51 = 0x62D0;
          goto LABEL_32;
        case 520:
          v56 = *(_DWORD *)(v3 + 1508);
          v50 = 0xAB450;
          goto LABEL_8;
        case 521:
          v57 = *(_DWORD *)(v3 + 1508);
          v51 = 0xAB450;
          goto LABEL_32;
        case 525:
          v56 = *(_DWORD *)(v3 + 1508);
          v50 = (int)pClass58_global->unk_1A6C5D;
          goto LABEL_8;
        case 526:
          v57 = *(_DWORD *)(v3 + 1508);
          v51 = (int)pClass58_global->unk_1A6C5D;
          goto LABEL_32;
        case 535:
          v56 = *(_DWORD *)(v3 + 1508);
          v50 = 0xFFFFFF;
          goto LABEL_8;
        case 536:
          v57 = *(_DWORD *)(v3 + 1508);
          goto LABEL_154;
        case 540:
          goto LABEL_17;
        case 511:
          goto LABEL_31;
        case 506:
          goto LABEL_115;
        case 541:
          goto LABEL_164;
        default:
          return 0;
      }
      return 0;
    }
    return 1;
  }
  if ( v2 > 4051 )
  {
    if ( v2 <= 7090 )
    {
      if ( v2 == 7090 )
        return 1;
      if ( v2 > 6030 )
      {
        if ( v2 > 6091 )
        {
          v35 = v2 - 6100;
          if ( !v35 )
            return 1;
          v36 = v35 - 930;
          if ( v36 )
          {
            if ( v36 != 1 )
              return 0;
            v57 = *(_DWORD *)(v3 + 1508);
            v51 = 0xF00000;
            goto LABEL_32;
          }
          goto LABEL_63;
        }
        if ( v2 != 6091 )
        {
          v32 = v2 - 6040;
          if ( !v32 || (v33 = v32 - 20, !v33) || (v34 = v33 - 10, !v34) )
            return 1;
          v14 = v34 == 20;
          goto LABEL_129;
        }
      }
      else
      {
        if ( v2 == 6030 )
          return 1;
        if ( v2 <= 4091 )
        {
          if ( v2 == 4091 )
          {
            v61 = 200.0;
            v54 = *(_DWORD *)(v3 + 1508);
            v48 = 0x7E7E7E;
            goto LABEL_117;
          }
          v26 = v2 - 4070;
          if ( !v26 )
            return 1;
          v27 = v26 - 1;
          if ( v27 )
          {
            v28 = v27 - 9;
            if ( !v28 )
              return 1;
            if ( v28 == 10 )
            {
              sub_4A73AA((void *)v3, a2, 0x7E7E7E, *(_DWORD *)(v3 + 1508));
              return 1;
            }
            return 0;
          }
LABEL_115:
          v57 = *(_DWORD *)(v3 + 1508);
          v51 = (int)&unk_5C310E;
          goto LABEL_32;
        }
        v29 = v2 - 4092;
        if ( !v29 )
        {
LABEL_17:
          v56 = *(_DWORD *)(v3 + 1508);
          v50 = 0x7E7E7E;
          goto LABEL_8;
        }
        v30 = v29 - 8;
        if ( !v30 )
          return 0;
        v31 = v30 - 1910;
        if ( !v31 )
          return 1;
        if ( v31 != 1 )
          return 0;
      }
LABEL_122:
      sub_4A7948(a2);
      return 0;
    }
    if ( v2 <= 9000 )
    {
      if ( v2 == 9000 )
        return 1;
      if ( v2 <= 8030 )
      {
        if ( v2 == 8030 )
          return 1;
        v37 = v2 - 7091;
        if ( v37 )
        {
          v38 = v37 - 909;
          if ( !v38 )
          {
            v8 = 16777215;
            sub_4A73AA((void *)v3, a2, 16777215, *(_DWORD *)(v3 + 1516));
            v58 = 128;
            goto LABEL_44;
          }
          v39 = v38 - 1;
          if ( v39 )
          {
            if ( v39 == 9 )
            {
              v58 = 64;
              v52 = 16777215;
              goto LABEL_144;
            }
            return 0;
          }
          v59 = *(_DWORD *)(v3 + 1512);
          v8 = 16777215;
        }
        else
        {
          v59 = *(_DWORD *)(v3 + 1508);
          v8 = 0xF00000;
        }
        goto LABEL_146;
      }
      v40 = v2 - 8040;
      if ( !v40 || (v41 = v40 - 20, !v41) )
        return 1;
      v42 = v41 - 30;
      if ( v42 )
      {
        if ( v42 != 1 )
          return 0;
        v57 = *(_DWORD *)(v3 + 1516);
LABEL_154:
        v51 = 16777215;
        goto LABEL_32;
      }
      sub_4A7A27(a2, 0xFFFFFFu, 128);
      if ( !pD3DRenderer->pRenderD3D3 )
        return 1;
      v62 = -1;
      v55 = 100;
      v49 = a2;
      goto LABEL_157;
    }
    if ( v2 > 9050 )
    {
      v46 = v2 - 9070;
      if ( v46 )
      {
        v47 = v46 - 10;
        if ( v47 )
        {
          if ( v47 != 1 )
            return 0;
        }
      }
      return 1;
    }
    if ( v2 == 9050 || (v43 = v2 - 9010, !v43) || (v44 = v43 - 20, !v44) || (v45 = v44 - 10, !v45) )
      return 1;
    if ( v45 != 1 )
      return 0;
LABEL_164:
    v57 = *(_DWORD *)(v3 + 1508);
    v51 = 0x7E7E7E;
LABEL_32:
    sub_4A75CC(a2, v51, v57);
    return 0;
  }
  if ( v2 == 4051 )
    goto LABEL_122;
  if ( v2 > 2031 )
  {
    if ( v2 <= 3060 )
    {
      if ( v2 == 3060 )
        goto LABEL_171;
      if ( v2 <= 2101 )
      {
        if ( v2 == 2101 )
        {
          v60 = 200.0;
          v53 = *(_DWORD *)(v3 + 1508);
          goto LABEL_83;
        }
        if ( v2 != 2060 )
        {
          if ( v2 != 2061 )
          {
            if ( v2 <= 2079 )
              return 0;
            if ( v2 <= 2081 )
            {
              if ( pD3DRenderer->pRenderD3D3 )
                sub_4A77FD((void *)v3, a2);
              else
                sub_4A80DC((void *)v3, a2);
              return 0;
            }
            v14 = v2 == 2100;
            goto LABEL_129;
          }
          goto LABEL_67;
        }
        if ( !pD3DRenderer->pRenderD3D3 )
          return 1;
        Str1 = *(_DWORD *)"sp18h1";
        v64 = *(_WORD *)&"sp18h1"[4];
        v65 = "sp18h1"[6];
        sub_4BE59E((int)&unk_F8BAD8, 1, 6);
        HIBYTE(v64) = sub_4BE623((int)&unk_F8BAD8) + 48;
        v62 = LODFile_Bitmaps_LOD.LODFile_LoadTexture( (const char *)&Str1, 2);
        v55 = 100;
        v49 = a2;
LABEL_157:
        sub_4A7E05((void *)v3, v49, v55, v62);
        return 0;
      }
      v18 = v2 - 3010;
      if ( !v18 )
      {
LABEL_171:
        v8 = 701520;
        goto LABEL_42;
      }
      v19 = v18 - 1;
      if ( !v19 )
      {
        v59 = *(_DWORD *)(v3 + 1508);
        v8 = 701520;
        goto LABEL_146;
      }
      v20 = v19 - 19;
      if ( !v20 )
        return 1;
      if ( v20 != 1 )
        return 0;
LABEL_89:
      v59 = *(_DWORD *)(v3 + 1508);
      v8 = (int)(&class35_obj.pColorPalette2[17][73 * 32 + 12]) + 1;
      goto LABEL_146;
    }
    if ( v2 > 4000 )
    {
      v24 = v2 - 4030;
      if ( !v24 || (v25 = v24 - 1, !v25) )
        return 1;
      v14 = v25 == 19;
      goto LABEL_129;
    }
    if ( v2 == 4000 )
    {
      if ( !pD3DRenderer->pRenderD3D3 )
        return 1;
      sub_4A7C07((void *)v3, a2);
      return 0;
    }
    v21 = v2 - 3061;
    if ( !v21 || (v22 = v21 - 29, !v22) )
      return 1;
    v23 = v22 - 1;
    if ( !v23 )
      goto LABEL_89;
    if ( v23 != 1 )
      return 0;
    v56 = *(_DWORD *)(v3 + 1508);
    v50 = (int)(&class35_obj.pColorPalette2[17][73 * 32 + 12]) + 1;
LABEL_8:
    sub_4A73AA((void *)v3, a2, v50, v56);
    return 0;
  }
  if ( v2 == 2031 )
  {
LABEL_67:
    v60 = 200.0;
    v53 = *(_DWORD *)(v3 + 1512);
LABEL_83:
    v8 = (int)pClass58_global->unk_1A6C6C;
    goto LABEL_84;
  }
  if ( v2 > 1051 )
  {
    if ( v2 <= 1081 )
    {
      if ( v2 == 1081 )
      {
        v8 = 16727070;
        sub_4A7A66(a2, 16727070, *(_DWORD *)(v3 + 1508), 300.0);
        sub_4A7A66(a2, 16727070, *(_DWORD *)(v3 + 1508), 250.0);
        v60 = 200.0;
        v53 = *(_DWORD *)(v3 + 1508);
      }
      else
      {
        v11 = v2 - 1060;
        if ( !v11 )
          return 1;
        v12 = v11 - 1;
        if ( v12 )
        {
          v13 = v12 - 9;
          if ( !v13 )
          {
LABEL_31:
            v57 = *(_DWORD *)(v3 + 1508);
            v51 = 16727070;
            goto LABEL_32;
          }
          v14 = v13 == 10;
LABEL_129:
          if ( v14 )
            return 1;
          return 0;
        }
        v8 = 16727070;
        v60 = 250.0;
        v53 = *(_DWORD *)(v3 + 1508);
      }
LABEL_84:
      sub_4A7A66(a2, v8, v53, v60);
      goto LABEL_43;
    }
    v15 = v2 - 1090;
    if ( v15 )
    {
      v16 = v15 - 10;
      if ( !v16 )
        return 1;
      v17 = v16 - 1;
      if ( !v17 )
      {
        v8 = 16727070;
        sub_4A75CC(a2, 16727070, *(_DWORD *)(v3 + 1508));
        v59 = *(_DWORD *)(v3 + 1508);
        goto LABEL_146;
      }
      if ( v17 != 929 )
        return 0;
LABEL_63:
      if ( !pD3DRenderer->pRenderD3D3 )
        return 1;
      sub_4A78AE(a2);
      v58 = 128;
      v52 = (unsigned int)&unk_64640F;
      goto LABEL_144;
    }
    v61 = 250.0;
    v54 = *(_DWORD *)(v3 + 1508);
    v48 = 16727070;
LABEL_117:
    sub_4A7A66(a2, v48, v54, v61);
    return 0;
  }
  if ( v2 == 1051 )
  {
    sub_4A7A27(a2, 0xFF3C1Eu, 256);
    if ( pD3DRenderer->pRenderD3D3 )
    {
      v9 = *(_DWORD *)(a2 + 88) & 7;
      if ( v9 != 3 )
      {
        if ( v9 != 2 )
        {
          v10 = *(_DWORD *)(v3 + 516);
          if ( v10 != 4 )
          {
            *(_DWORD *)(v3 + 516) = v10 + 1;
            sub_4A7688((void *)v3, a2);
          }
          return 0;
        }
      }
    }
    return 1;
  }
  if ( v2 > 600 )
  {
    if ( v2 < 811 )
      return 0;
    if ( v2 <= 814 )
      return 1;
    if ( v2 == 1010 )
      goto LABEL_41;
    if ( v2 != 1011 )
    {
      if ( v2 != 1050 )
        return 0;
LABEL_41:
      v8 = 16727070;
LABEL_42:
      sub_4A73AA((void *)v3, a2, v8, *(_DWORD *)(v3 + 1508));
LABEL_43:
      v58 = 256;
LABEL_44:
      v52 = v8;
      goto LABEL_144;
    }
    v59 = *(_DWORD *)(v3 + 1508);
    v8 = 16727070;
LABEL_146:
    sub_4A75CC(a2, v8, v59);
    goto LABEL_43;
  }
  if ( v2 == 600 )
  {
    sub_4A7A27(a2, 0xFF3C1Eu, 256);
    return 1;
  }
  v4 = v2 - 550;
  if ( !v4 )
    return 1;
  v5 = v4 - 1;
  if ( !v5 )
    goto LABEL_31;
  v6 = v5 - 4;
  if ( !v6 )
    return 1;
  if ( v6 == 1 )
  {
    v58 = 256;
    v52 = 16711680;
LABEL_144:
    sub_4A7A27(a2, v52, v58);
  }
  return 0;
}

//----- (0048BBA6) --------------------------------------------------------
void class02_sub_48BBA6(struct class02 *_this)
{
  float v1; // eax@1
  int v2; // esi@1
  int v6; // ebx@2
  int v7; // edi@2
  int v8; // ecx@7
  int v9; // eax@10
  signed int v10; // eax@12
  int v11; // eax@18
  int v12; // edx@20
  int v13; // ecx@20
  unsigned __int8 v14; // zf@26
  char v15; // sf@26
  unsigned __int8 v16; // of@26
  int v17; // eax@28
  char v18; // [sp+Ch] [bp-58h]@15
  int v19; // [sp+14h] [bp-50h]@15
  int v20; // [sp+18h] [bp-4Ch]@15
  int v21; // [sp+1Ch] [bp-48h]@15
  int v22; // [sp+20h] [bp-44h]@15
  int v23; // [sp+34h] [bp-30h]@15
  int v24; // [sp+54h] [bp-10h]@1
  int v25; // [sp+5Ch] [bp-8h]@5
  int v26; // [sp+60h] [bp-4h]@1

  v24 = -1;
  v2 = (int)_this;
  LODWORD(v1) = _this->dword_00E424;
  //v5 = __SETO__(LODWORD(v1), *(_DWORD *)(this + 58408));
  //v3 = LODWORD(v1) == *(_DWORD *)(v2 + 58408);
  //v4 = LODWORD(v1) - *(_DWORD *)(v2 + 58408) < 0;
  v26 = _this->dword_00E424;
  if (LODWORD(v1) <= _this->dword_00E428)
  {
    v6 = (int)pD3DRenderer;
    v7 = 104 * LODWORD(v1) + v2 + 86;
    do
    {
      if ( *(_DWORD *)(v7 - 86) )
      {
        if ( sub_48AE74((void *)v2, v1) )
        {
          v25 = *(_DWORD *)(v7 - 22);
          if ( v25 >= dword_51B734 )
          {
            if ( v25 < dword_51B73C )
            {
              v8 = *(_DWORD *)(v7 - 18);
              if ( v8 >= dword_51B738 )
              {
                if ( v8 < dword_51B740 )
                {
                  if ( pD3DRenderer->pRenderD3D3 )
                  {
                    v9 = *(_DWORD *)(v7 - 86);
                    if ( BYTE1(v9) & 1 )
                    {
                      v17 = v2 + 104 * v26;
                      v21 = *(_DWORD *)(v17 + 88) >> 2;
                      v22 = *(_DWORD *)(v17 + 88) >> 2;
                      v19 = *(_DWORD *)(v17 + 64);
                      v20 = *(_DWORD *)(v17 + 68);
                      v23 = *(_DWORD *)(v17 + 80);
                      sub_4A354F(v6, (int)&v18, 0, *(_DWORD *)(v17 + 100), *(_DWORD *)(v17 + 60));
                      return;
                    }
                    if ( BYTE1(v9) & 2 )
                    {
                      v10 = *(_DWORD *)(v2 + 52000);
                      if ( v10 < 100 )
                      {
                        *(float *)((v10 << 6) + v2 + 52004) = (double)v25;
                        *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52008) = (double)*(signed int *)(v7 - 18);
                        v25 = *(_WORD *)(v7 - 4);
                        *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52012) = 1.0
                                                                                - 1.0
                                                                                / ((double)v25
                                                                                 * 0.06175889447331429);
                        *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52016) = 1.0;
                        *(_DWORD *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52020) = *(_DWORD *)(v7 + 14);
                        *(_DWORD *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52024) = 0;
                        *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52028) = 0.0;
                        *(float *)(((*(_DWORD *)(v2 + 52000) + 813) << 6) + v2) = 0.0;
                        *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52036) = (double)*(signed int *)(v7 - 14);
                        *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52040) = (double)*(signed int *)(v7 - 10);
                        v25 = *(_WORD *)v7;
                        *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52044) = 1.0
                                                                                - 1.0
                                                                                / ((double)v25
                                                                                 * 0.06175889447331429);
                        *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52048) = 1.0;
                        *(_DWORD *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52052) = *(_DWORD *)(v7 + 14);
                        *(_DWORD *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52056) = 0;
                        *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52060) = 0.0;
                        compile_error;//*(float *)((*(_DWORD *)(v2 + 52000)++ << 6) + v2 + 52064) = 0.0;
                      }
                    }
                    if ( *(_BYTE *)(v7 - 85) & 4 )
                    {
                      v21 = *(_DWORD *)(v7 + 2);
                      v22 = *(_DWORD *)(v7 + 2);
                      v19 = *(_DWORD *)(v7 - 22);
                      v20 = *(_DWORD *)(v7 - 18);
                      v23 = *(_DWORD *)(v7 - 6);
                      sub_4A354F(
                        v6,
                        (int)&v18,
                        LODFile_Bitmaps_LOD.pHardwareTextures[*(_DWORD *)(v7 - 50)],
                        *(_DWORD *)(v7 + 14),
                        *(_DWORD *)(v7 - 26));
                    }
                    if ( *(_BYTE *)(v7 - 85) & 8 )
                    {
                      v21 = *(_DWORD *)(v7 + 2);
                      v22 = *(_DWORD *)(v7 + 2);
                      v19 = *(_DWORD *)(v7 - 22);
                      v20 = *(_DWORD *)(v7 - 18);
                      v23 = *(_DWORD *)(v7 - 6);
                      sub_4A354F(
                        v6,
                        (int)&v18,
                        LODFile_Sprites_LOD.pHardwareSprites[*(_DWORD *)(v7 - 50)].pTexture,
                        *(_DWORD *)(v7 + 14),
                        *(_DWORD *)(v7 - 26));
                    }
                  }
                  else
                  {
                    v11 = 13 * *(_DWORD *)(v7 + 2) >> 16;
                    if ( v11 > 30 )
                      v11 = 30;
                    v13 = v8 - v11;
                    v12 = v25 - (v11 >> 1);
                    if ( v12 + v11 < pOldViewport->uGameX
                      || v12 >= pOldViewport->uGameZ
                      || v13 + v11 < pOldViewport->uGameY
                      || v13 >= pOldViewport->uGameW )
                    {
                      v6 = (int)pD3DRenderer;
                    }
                    else
                    {
                      v6 = (int)pD3DRenderer;
                      sub_4A48E4(v12, v13, *(_DWORD *)(v7 - 6), *(_DWORD *)(v7 + 14), v11);
                    }
                  }
                }
              }
            }
          }
        }
      }
      v7 += 104;
      LODWORD(v1) = v26 + 1;
      compile_error;//v16 = __SETO__(v26 + 1, *(_DWORD *)(v2 + 58408));
      v14 = v26 + 1 == *(_DWORD *)(v2 + 58408);
      v15 = v26++ + 1 - *(_DWORD *)(v2 + 58408) < 0;
    }
    while ( (unsigned __int8)(v15 ^ v16) | v14 );
  }
}


//----- (0048BEEF) --------------------------------------------------------
void class02_sub_48BEEF(struct class02 *_this)
{
  int v2; // esi@1
  int v6; // ebx@2
  int v7; // edi@2
  int v8; // eax@6
  signed int v9; // eax@8
  int v10; // eax@14
  int v11; // edx@16
  int v12; // ecx@16
  int v16; // eax@24
  char v17; // [sp+Ch] [bp-58h]@11
  int v18; // [sp+14h] [bp-50h]@11
  int v19; // [sp+18h] [bp-4Ch]@11
  int v20; // [sp+1Ch] [bp-48h]@11
  int v21; // [sp+20h] [bp-44h]@11
  int v22; // [sp+34h] [bp-30h]@11
  int v23; // [sp+54h] [bp-10h]@1
  int v24; // [sp+5Ch] [bp-8h]@9
 int i;

  v23 = -1;
  v2 = (int)_this;

    v6 = (int)pD3DRenderer;
 for (i = _this->dword_00E424; i <= _this->dword_00E428; ++i)
 {
    v7 = 104 * i + v2 + 82;
      if ( *(_DWORD *)(v7 - 82) && sub_48B5B3((void *)v2, i) )
      {
        if ( pD3DRenderer->pRenderD3D3 )
        {
          v8 = *(_DWORD *)(v7 - 82);
          if ( BYTE1(v8) & 1 )
          {
            v16 = v2 + 104 * i;
            v20 = *(_DWORD *)(v16 + 88) >> 2;
            v21 = *(_DWORD *)(v16 + 88) >> 2;
            v18 = *(_DWORD *)(v16 + 64);
            v19 = *(_DWORD *)(v16 + 68);
            v22 = *(_DWORD *)(v16 + 80);
            sub_4A3AD9(v6, (int)&v17, 0, *(_DWORD *)(v16 + 100), *(_DWORD *)(v16 + 60));
            return;
          }
          if ( BYTE1(v8) & 2 )
          {
            v9 = *(_DWORD *)(v2 + 52000);
            if ( v9 < 100 )
            {
              *(float *)((v9 << 6) + v2 + 52004) = (double)*(signed int *)(v7 - 18);
              *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52008) = (double)*(signed int *)(v7 - 14);
              v24 = *(_WORD *)v7;
              *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52012) = 1.0
                                                                      - 1.0
                                                                      / ((double)v24
                                                                       * 1000.0
                                                                       / (double)pStruct9_global->shading_dist_mist);
              *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52016) = 1.0;
              *(_DWORD *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52020) = *(_DWORD *)(v7 + 18);
              *(_DWORD *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52024) = 0;
              *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52028) = 0.0;
              *(float *)(((*(_DWORD *)(v2 + 52000) + 813) << 6) + v2) = 0.0;
              *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52036) = (double)*(signed int *)(v7 - 10);
              *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52040) = (double)*(signed int *)(v7 - 6);
              v24 = *(_WORD *)v7;
              *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52044) = 1.0
                                                                      - 1.0
                                                                      / ((double)v24
                                                                       * 1000.0
                                                                       / (double)pStruct9_global->shading_dist_mist);
              *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52048) = 1.0;
              *(_DWORD *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52052) = *(_DWORD *)(v7 + 18);
              *(_DWORD *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52056) = 0;
              *(float *)((*(_DWORD *)(v2 + 52000) << 6) + v2 + 52060) = 0.0;
              compile_error;//*(float *)((*(_DWORD *)(v2 + 52000)++ << 6) + v2 + 52064) = 0.0;
            }
          }
          if ( *(_BYTE *)(v7 - 81) & 4 )
          {
            v20 = *(_DWORD *)(v7 + 6);
            v21 = *(_DWORD *)(v7 + 6);
            v18 = *(_DWORD *)(v7 - 18);
            v19 = *(_DWORD *)(v7 - 14);
            v22 = *(_DWORD *)(v7 - 2);
            sub_4A3AD9(v6,
              (int)&v17,
              LODFile_Bitmaps_LOD.pHardwareTextures[*(_DWORD *)(v7 - 46)],
              *(_DWORD *)(v7 + 18),
              *(_DWORD *)(v7 - 22));
          }
          if ( *(_BYTE *)(v7 - 81) & 8 )
          {
            v20 = *(_DWORD *)(v7 + 6);
            v21 = *(_DWORD *)(v7 + 6);
            v18 = *(_DWORD *)(v7 - 18);
            v19 = *(_DWORD *)(v7 - 14);
            v22 = *(_DWORD *)(v7 - 2);
            sub_4A3AD9(
              v6,
              (int)&v17,
              LODFile_Sprites_LOD.pHardwareSprites[*(_DWORD *)(v7 - 46)].pTexture,
              *(_DWORD *)(v7 + 18),
              *(_DWORD *)(v7 - 22));
          }
        }
        else
        {
          v10 = 13 * *(_DWORD *)(v7 + 6) >> 16;
          if ( v10 > 30 )
            v10 = 30;
          v12 = *(_DWORD *)(v7 - 18) - (v10 >> 1);
          v11 = *(_DWORD *)(v7 - 14) - v10;
          if ( v12 + v10 < pOldViewport->uGameX
            || v12 >= pOldViewport->uGameZ
            || *(_DWORD *)(v7 - 14) < pOldViewport->uGameY
            || v11 >= pOldViewport->uGameW )
          {
            v6 = (int)pD3DRenderer;
          }
          else
          {
            v6 = (int)pD3DRenderer;
            sub_4A48E4(v12, v11, *(_DWORD *)(v7 - 2), *(_DWORD *)(v7 + 18), v10);
          }
        }
      }
  }
}


//----- (00440F07) --------------------------------------------------------
void sub_440F07(struct struct5 *pArray)
{
 int i;

 for (i = 0; i < 100; ++i)
   if (pArray[i].word_00000C > 0)
   {
    pArray[i].word_000006 += rand() % 5 - 2;
    pArray[i].word_000008 += rand() % 5 - 2;
    pArray[i].word_00000A += rand() % 5 + 4;
    pArray[i].word_00000C -= cClock1.int_00001C;
   }
}




//----- (004A8C27) --------------------------------------------------------
int class06_sub_4A8C27(struct class06 *_this)
{
  int v1; // ebx@1
  int v2; // edi@1
  int result; // eax@3
  double v4; // st6@4
  double v5; // st7@4
  double v6; // st7@4
  float v7; // ST14_4@6
  int v8; // edi@8
  signed int v9; // ST14_4@8
  int v10; // eax@8
  int v11; // eax@8
  double v12; // st7@9
  double v13; // st7@9
  double v14; // st7@9
  double v15; // st6@9
  int v16; // eax@9
  const char *v17; // ST18_4@9
  unsigned int v18; // ST1C_4@9
  int v19; // ST20_4@9
  int v20; // eax@9
  signed __int64 v21; // qtt@10
  int v22; // [sp+10h] [bp-DCh]@10
  int v23; // [sp+14h] [bp-D8h]@10
  int v24; // [sp+18h] [bp-D4h]@10
  int v25; // [sp+1Ch] [bp-D0h]@10
  int v26; // [sp+20h] [bp-CCh]@10
  int v27; // [sp+24h] [bp-C8h]@10
  char *v28; // [sp+30h] [bp-BCh]@10
  int v29; // [sp+38h] [bp-B4h]@10
  int v30; // [sp+3Ch] [bp-B0h]@10
  int v31; // [sp+40h] [bp-ACh]@10
  int v32; // [sp+44h] [bp-A8h]@10
  __int64 v33; // [sp+48h] [bp-A4h]@10
  int v34; // [sp+50h] [bp-9Ch]@10
  int v35; // [sp+58h] [bp-94h]@10
  float v36; // [sp+60h] [bp-8Ch]@9
  float v37; // [sp+64h] [bp-88h]@9
  float v38; // [sp+68h] [bp-84h]@9
  float v39; // [sp+6Ch] [bp-80h]@9
  int v40; // [sp+70h] [bp-7Ch]@9
  int v41; // [sp+74h] [bp-78h]@9
  float v42; // [sp+78h] [bp-74h]@9
  float v43; // [sp+7Ch] [bp-70h]@9
  float v44; // [sp+80h] [bp-6Ch]@9
  float v45; // [sp+84h] [bp-68h]@9
  float v46; // [sp+88h] [bp-64h]@9
  float v47; // [sp+8Ch] [bp-60h]@9
  int v48; // [sp+90h] [bp-5Ch]@9
  int v49; // [sp+94h] [bp-58h]@9
  float v50; // [sp+98h] [bp-54h]@9
  float v51; // [sp+9Ch] [bp-50h]@9
  float v52; // [sp+A0h] [bp-4Ch]@9
  float v53; // [sp+A4h] [bp-48h]@9
  float v54; // [sp+A8h] [bp-44h]@9
  float v55; // [sp+ACh] [bp-40h]@9
  int v56; // [sp+B0h] [bp-3Ch]@9
  int v57; // [sp+B4h] [bp-38h]@9
  float v58; // [sp+B8h] [bp-34h]@9
  float v59; // [sp+BCh] [bp-30h]@9
  float v60; // [sp+C0h] [bp-2Ch]@9
  float v61; // [sp+C4h] [bp-28h]@9
  float v62; // [sp+C8h] [bp-24h]@9
  float v63; // [sp+CCh] [bp-20h]@9
  int v64; // [sp+D0h] [bp-1Ch]@9
  int v65; // [sp+D4h] [bp-18h]@9
  float v66; // [sp+D8h] [bp-14h]@9
  float v67; // [sp+DCh] [bp-10h]@9
  int v68; // [sp+E0h] [bp-Ch]@10
  int v69; // [sp+E4h] [bp-8h]@8
  int v70; // [sp+E8h] [bp-4h]@3

  v1 = (int)_this;
  v2 = v1 + 1480;
  if (_this->dword_0005C8 )
  {
    class06_sub_4A7298(_this);
    _this->dword_0005C8 = 0;
  }
  _this->dword_000204 = 0;
  v70 = result = _this->dword_0005D8;
  if ( result > 0 )
  {
    v6 = (double)v70 / (double)*(signed int *)(v1 + 1500);
    v4 = 1.0 - v6 * v6;
    v5 = v4;
    if ( v4 > memory_4D8410.f0_9)
      v5 = 1.0 - (v4 - memory_4D8410.f0_9) * memory_4D8410.f10_0;
    v7 = v5;
    Render_sub_4A52F1((int)pD3DRenderer, *(_DWORD *)(v1 + 1504), v7);
    result = cClock1.int_00001C;
    *(_DWORD *)(v1 + 1496) -= cClock1.int_00001C;
  }


  //by the time we first get in this function, dword_0005D4  is still not initialized in the original exe
  //maybe the following code in never executed at all

  runtime_warning(additional test with original exe in _Hardware D3D_ mode required);
  if (_this->dword_0005D4 > 0 )
  {
    v9 = 8 * *(_WORD *)(60 * SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell84") + (unsigned int)(pSpriteFrameTable->pSpriteSFrames) + 56) - *(_DWORD *)(v1 + 1492);

    v10 = SpriteFrameTable_FastFindSprite(pSpriteFrameTable, "spell84");
    v11 = (int)CSpriteFrameTable_fn1(pSpriteFrameTable, v10, v9);
    v8 = *(_WORD *)(v11 + 24);
    v69 = v11;
    *(_DWORD *)(v1 + 1492) -= cClock1.int_00001C;
    if ( pD3DRenderer->pRenderD3D3 )
    {
      v12 = (double)pOldViewport->uGameX;
      v36 = v12;
      v44 = v12;
      v13 = (double)pOldViewport->uGameZ;
      v70 = pOldViewport->uGameW + 1;
      v40 = 0x7F7F7F;
      v48 = 0x7F7F7F;
      v52 = v13;
      v60 = v13;
      v14 = (double)pOldViewport->uGameY;
      v56 = 0x7F7F7F;
      v64 = 0x7F7F7F;
      v41 = 0;
      v49 = 0;
      v37 = v14;
      v15 = (double)(pOldViewport->uGameW + 1);
      v57 = 0;
      v65 = 0;
      v45 = v15;
      v53 = v15;
      v61 = v14;
      v38 = 0.0;
      v46 = 0.0;
      v54 = 0.0;
      v62 = 0.0;
      v39 = 1.0;
      v47 = 1.0;
      v55 = 1.0;
      v63 = 1.0;
      v42 = 0.0;
      v50 = 0.0;
      v58 = 1.0;
      v66 = 1.0;
      v43 = 0.0;
      v51 = 1.0;
      v59 = 1.0;
      v67 = 0.0;
      (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 152))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        0,
        *(_DWORD *)(LODFile_Sprites_LOD.pHardwareSprites + 40 * v8 + 12));
      (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        28,
        0);
      (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        27,
        1);
      (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        14,
        0);
      (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        19,
        2);
      (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        20,
        2);
      (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        26,
        0);
      (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        23,
        8);
      (*(void (__stdcall **)(_DWORD, signed int, signed int, float *, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56)
                                                                                             + 112))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        6,
        452,
        &v36,
        4,
        28);
      v16 = (*(int (__stdcall **)(_DWORD, signed int, signed int, _DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56)
                                                                                             + 88))(
              *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
              19,
              2,
              (int)"E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\seffects.cpp",
              1348,
              0);
      CheckHRESULT((void **)&v69, v16, v17, v18, v19);
      v20 = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
              *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
              20,
              1);
      CheckHRESULT((void **)&v69, v20, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\seffects.cpp", 0x545u, 0);
      (*(void (__cdecl **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        27,
        0);
      (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        14,
        1);
      (*(void (__stdcall **)(_DWORD, signed int, _DWORD))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
        *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
        26,
        1);
      result = (*(int (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)(pD3DRenderer->pRenderD3D3 + 56) + 88))(
                 *(_DWORD *)(pD3DRenderer->pRenderD3D3 + 56),
                 23,
                 2);
    }
    else
    {
     v22 = (int)pD3DRenderer->pTargetSurface;
      v35 = -1;
      v23 = (int)pD3DRenderer->pActiveZBuffer;
      v24 = (pOldViewport->uGameZ - pOldViewport->uGameX) / 2;
      v25 = pOldViewport->uGameW;
      LODWORD(v21) = 0;
      HIDWORD(v21) = (pOldViewport->uGameZ - pOldViewport->uGameX) << 16 >> 16;
      v68 = 16777216;
      v26 = v21 / 16777216;
      LODWORD(v21) = 0;
      HIDWORD(v21) = (pOldViewport->uGameW - pOldViewport->uGameY) << 16 >> 16;
      v70 = v21 / 16777216;
      v27 = v21 / 16777216;
      v28 = sub_41F50D(*(_WORD *)(v69 + 52), 0, 1);
      v31 = pD3DRenderer->uTargetSurfacePitch;
      v35 = -1;
      v32 = pOldViewport->uGameX;
      v33 = pOldViewport->uGameY;
      result = pOldViewport->uGameW;
      v29 = 0;
      v34 = pOldViewport->uGameW;
      v30 = 0;
      if ( v8 >= 0 )
        result = sub_4ACC38(40 * v8 + 7218180, (Render_BillboardTransform_stru0 *)&v22, 1);
    }
  }
  return result;
}


//----- (004A7298) --------------------------------------------------------
int class06_sub_4A7298(struct class06 *_this)
{
  char *v1; // eax@1
  signed int v2; // ecx@1
  void *v3; // ebx@1
  int result; // eax@3
  int v5; // edi@3
  unsigned __int8 v6; // zf@3
  unsigned __int8 v7; // sf@3
  int v8; // esi@4
  int v9; // eax@5
  float v10; // ST1C_4@8
  float v11; // ST0C_4@8
  int v12; // [sp+20h] [bp-78h]@6
  float v13; // [sp+30h] [bp-68h]@5
  float v14; // [sp+34h] [bp-64h]@5
  float v15; // [sp+38h] [bp-60h]@5
  float v16; // [sp+3Ch] [bp-5Ch]@8
  float v17; // [sp+48h] [bp-50h]@8
  float v18; // [sp+4Ch] [bp-4Ch]@8
  char v19; // [sp+5Ch] [bp-3Ch]@1
  float v20; // [sp+60h] [bp-38h]@5
  float v21; // [sp+64h] [bp-34h]@5
  float v22; // [sp+68h] [bp-30h]@5
  float v23; // [sp+6Ch] [bp-2Ch]@8
  float v24; // [sp+78h] [bp-20h]@8
  float v25; // [sp+7Ch] [bp-1Ch]@8
  float v26; // [sp+90h] [bp-8h]@3
  int v27; // [sp+94h] [bp-4h]@3

  v3 = _this;
  v1 = &v19;
  v2 = 2;
  do
  {
    *(float *)v1 = 0.0;
    v1 += 48;
    --v2;
  }
  while ( v2 );
  v27 = 0;
  v6 = *((_DWORD *)v3 + 370) == 0;
  v7 = *((_DWORD *)v3 + 370) < 0;
  v5 = (int)pGame->class08_obj;
  result = *(_DWORD *)(v5 + 208);
  LODWORD(v26) = *(_DWORD *)(v5 + 208);
  if ( !(v7 | v6) )
  {
    v8 = (int)((char *)v3 + 588);
    do
    {
      v13 = *(float *)(v8 - 4);
      v14 = *(float *)v8;
      v15 = *(float *)(v8 + 4);
      v20 = *(float *)(v8 + 8);
      v21 = *(float *)(v8 + 12);
      v22 = *(float *)(v8 + 16);
      sub_436523((RenderVertex *)&v13, 2);
      sub_42620A((int)&v13);
      class08_sub_436BB7((class08 *)v5, (RenderVertex *)&v13, 2, 0);
      v9 = *(_DWORD *)(v8 + 20);
      if ( v9 == -1 )
        v12 = 0;
      else
        v12 = (int)LODFile_Bitmaps_LOD.pHardwareTextures[v9];
      v10 = v26 / v23 * 20.0;
      v11 = v26 / v16 * 20.0;
      sub_4A49D0(v17, v18, v16, v11, v24, v25, v23, v10, v12);
      ++v27;
      v8 += 28;
      result = v27;
    }
    while ( v27 < *((_DWORD *)v3 + 370) );
  }
  return result;
}

//----- (004A902A) --------------------------------------------------------
void class06_sub_4A902A_DrawSomeIcon(struct class06 *_this)
{
 struct IconFrame *pIcon;
 int i;

 for (i = 0; i < 4; ++i)
 {
  if (_this->array_000208[i].word_000000)
  {
   _this->array_000208[i].dword_000004 += cClock1.int_00001C;
   if (_this->array_000208[i].dword_000004 <= _this->array_000208[i].dword_000008)
   {
    pIcon = pIconFrameTable->GetImage(_this->array_000208[i].dword_00000C, _this->array_000208[i].dword_000004);
    Render_DrawTransparentTexture(pD3DRenderer, off_4ED748[i], 385, &LODFile_Icons_LOD.aLODHeaders[pIcon->uTextureIdx]);
    dword_5E5144 = 1;
   }
   else
     _this->array_000208[i].word_000000 = 0;
  }
 }
}














