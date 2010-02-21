#include "defs.h"
//#define sprintfex sprintf

#include "mm7DDrawRenderer.h"

#include "data.h"
extern HWND hWnd_global;

extern char off_4E7ECC[];
extern int dword_4E800C;
extern float flt_6BE3A0;
extern int dword_AD4730;
extern int dword_E31C7C;

extern char unk_4EB8BC;
extern char unk_4EBBD0;

extern char byte_4D8410[];

extern int *dword_4F2688;

extern int dword_51B6E8;
extern int dword_51B6EC;
extern int dword_51B6F0;

extern int dword_69B00C;
extern int dword_6A0CA4;

extern int dword_720010;

extern int dword_720018;

extern char class23_instance[];
extern char class28_global[];
extern char class00_global[];

extern int dword_E31C70;

extern int dword_F79D70;
extern int dword_F79D7C;


// sub_4CC57F: using guessed type _DWORD __stdcall _CxxThrowException(_DWORD, _DWORD);
long __stdcall _CxxThrowException(long a1, long a2)
{
 __asm int 3;
 return 0;
}

// sub_4CE3D3: using guessed type _DWORD __stdcall exception__exception(_DWORD);
long __stdcall exception__exception(long a1)
{
 __asm int 3
 return 0;
}
/*
// sub_4CADD0: using guessed type int sprintfex(_DWORD, const char *, ...);
int __cdecl sprintfex(long a1, const char * a2, ...)
{
 __asm int 3
 return 0;
}*/

// sub_4D83BC: using guessed type int __stdcall radmalloc(_DWORD);
int __stdcall radmalloc(long a1)
{
 __asm int 3
 return 0;
}

// sub_40E3E9: using guessed type _DWORD __cdecl std__basic_string_char_std__char_traits_char__std__allocator_char_____Copy(_DWORD);
long __cdecl std__basic_string_char_std__char_traits_char__std__allocator_char_____Copy(long a1)
{
 __asm int 3
 return 0;
}

// sub_467B38: using guessed type _DWORD __stdcall std__basic_string_char_std__char_traits_char__std__allocator_char____erase(_DWORD, _DWORD);
long __stdcall std__basic_string_char_std__char_traits_char__std__allocator_char____erase(long a1, long a2)
{
 __asm int 3
 return 0;
}

// sub_4CC3A8: using guessed type _DWORD __stdcall _eh vector constructor iterator_(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
long __stdcall _eh_vector_constructor_iterator_(long a1, long a2, long a3, long a4, long a5)
{
 compile_error;//__asm int 3
 return 0;
}

// sub_4CC2B4: using guessed type _DWORD __stdcall _eh vector destructor iterator_(_DWORD, _DWORD, _DWORD, _DWORD);
long __stdcall _eh_vector_destructor_iterator_(long a1, long a2, long a3, long a4)
{
 __asm int 3
 return 0;
}

// sub_??????
void terminate()
{
 __asm int 3
 return;
}


//#error "FFFFFFFF: variables would overlap: edx/4 and edx/8 (funcsize=96)"
int sub_41AD6E()
{
 __asm int 3
 return 0;
}

int sub_498038()
{
 __asm int 3
 return 0;
}

int sub_43B569()
{
 __asm int 3
 return 0;
}

int __stdcall sub_45D73F(long a1)
{
 __asm int 3
 return 0;
}

int sub_48AAF1(long a1)
{
 __asm int 3
 return 0;
}

int sub_467E7A(long a1)
{
 __asm int 3
 return 0;
}

int sub_45DF13()
{
 __asm int 3
 return 0;
}

int sub_4BF919()
{
 __asm int 3
 return 0;
}

int sub_486009(long a1)
{
 __asm int 3
 return 0;
}

int sub_43B60C()
{
 __asm int 3
 return 0;
}

int sub_4C5910()
{
 __asm int 3
 return 0;
}

int sub_43B538()
{
 __asm int 3
 return 0;
}

int unknown_libname_107()
{
 __asm int 3;
 return 0;
}

int loc_43F2A9()
{
 __asm int 3;
 return 0;
}

int loc_43F2BF()
{
 __asm int 3;
 return 0;
}

char __stdcall ErrorMessageFromHRESULT(signed int a1, const char *Str, size_t a3);
void __stdcall sub_466D83(int a1, char a2, LPCSTR lpCaption, int a4, int a5, UINT uType, char a7, int a8, int a9, int a10, int a11);
void *__thiscall sub_466CC2(void **pSmthn, HRESULT hr, const char *pSourceFile, unsigned int a4, int a5);
int __fastcall sub_4678E2(int a1, int a2, char a3, int a4, int a5, int a6);
char __stdcall sub_46778D(int a1, const char *Str, int a3);

//----- (MM7.exe::00466CC2) --------------------------------------------------------
void *CheckHRESULT(void **pSmthn, HRESULT hr, const char *pSourceFile, unsigned int uSourceline, int a5)
{
 char v6;

 //v5 = this;
 //*(_DWORD *)this = 5080748;
 *pSmthn = &byte_4D8410[668];

 if (a5)
 {
  if (a5 != 1)
  {
   sub_466B8C();
   return pSmthn;
  }
  v6 = sub_46778D(hr, pSourceFile, uSourceline);
 }
 else v6 = ErrorMessageFromHRESULT(hr, pSourceFile, uSourceline);

 if (v6)
   sub_466B8C();

 return pSmthn;
}
//----- (MM7.exe::00466EBF) --------------------------------------------------------
char __stdcall ErrorMessageFromHRESULT(signed int a1, const char *Str, size_t a3)
{
  char v3; // bl@1
  signed int v4; // esi@1
  const char *v5; // esi@16
  char v7; // [sp-28h] [bp-154h]@175
  const CHAR *v8; // [sp-24h] [bp-150h]@175
  int v9; // [sp-20h] [bp-14Ch]@175
  int v10; // [sp-1Ch] [bp-148h]@175
  UINT v11; // [sp-18h] [bp-144h]@175
  char v12; // [sp-14h] [bp-140h]@175
  int v13; // [sp-10h] [bp-13Ch]@175
  int v14; // [sp-Ch] [bp-138h]@175
  char *v15; // [sp-8h] [bp-134h]@173
  size_t v16; // [sp-4h] [bp-130h]@173
  char Src; // [sp+Ch] [bp-120h]@174
  char *v18; // [sp+10Ch] [bp-20h]@175
  int v19; // [sp+110h] [bp-1Ch]@2
  int v20; // [sp+128h] [bp-4h]@2

  v4 = a1;
  v3 = 0;
  if ( a1 )
  {
    LOBYTE(v19) = BYTE3(a1);
    sub_40E2F6((int)&v19, 0);
    v20 = 0;
    if ( v4 > -2005532222 )
    {
      switch ( v4 + 2005532212 )
      {
        case 0:
          v5 = "DDERR_SURFACENOTATTACHED";
          goto LABEL_173;
        case 10:
          v5 = "DDERR_TOOBIGHEIGHT";
          goto LABEL_173;
        case 20:
          v5 = "DDERR_TOOBIGSIZE";
          goto LABEL_173;
        case 30:
          v5 = "DDERR_TOOBIGWIDTH";
          goto LABEL_173;
        case 50:
          v5 = "DDERR_UNSUPPORTEDFORMAT";
          goto LABEL_173;
        case 60:
          v5 = "DDERR_UNSUPPORTEDMASK";
          goto LABEL_173;
        case 61:
          v5 = "DDERR_INVALIDSTREAM";
          goto LABEL_173;
        case 77:
          v5 = "DDERR_VERTICALBLANKINPROGRESS";
          goto LABEL_173;
        case 80:
          v5 = "DDERR_WASSTILLDRAWING";
          goto LABEL_173;
        case 100:
          v5 = "DDERR_XALIGN";
          goto LABEL_173;
        case 101:
          v5 = "DDERR_INVALIDDIRECTDRAWGUID";
          goto LABEL_173;
        case 102:
          v5 = "DDERR_DIRECTDRAWALREADYCREATED";
          goto LABEL_173;
        case 103:
          v5 = "DDERR_NODIRECTDRAWHW";
          goto LABEL_173;
        case 104:
          v5 = "DDERR_PRIMARYSURFACEALREADYEXISTS";
          goto LABEL_173;
        case 105:
          v5 = "DDERR_NOEMULATION";
          goto LABEL_173;
        case 106:
          v5 = "DDERR_REGIONTOOSMALL";
          goto LABEL_173;
        case 107:
          v5 = "DDERR_CLIPPERISUSINGHWND";
          goto LABEL_173;
        case 108:
          v5 = "DDERR_NOCLIPPERATTACHED";
          goto LABEL_173;
        case 109:
          v5 = "DDERR_NOHWND";
          goto LABEL_173;
        case 110:
          v5 = "DDERR_HWNDSUBCLASSED";
          goto LABEL_173;
        case 111:
          v5 = "DDERR_HWNDALREADYSET";
          goto LABEL_173;
        case 112:
          v5 = "DDERR_NOPALETTEATTACHED";
          goto LABEL_173;
        case 113:
          v5 = "DDERR_NOPALETTEHW";
          goto LABEL_173;
        case 114:
          v5 = "DDERR_BLTFASTCANTCLIP";
          goto LABEL_173;
        case 115:
          v5 = "DDERR_NOBLTHW";
          goto LABEL_173;
        case 116:
          v5 = "DDERR_NODDROPSHW";
          goto LABEL_173;
        case 117:
          v5 = "DDERR_OVERLAYNOTVISIBLE";
          goto LABEL_173;
        case 118:
          v5 = "DDERR_NOOVERLAYDEST";
          goto LABEL_173;
        case 119:
          v5 = "DDERR_INVALIDPOSITION";
          goto LABEL_173;
        case 120:
          v5 = "DDERR_NOTAOVERLAYSURFACE";
          goto LABEL_173;
        case 121:
          v5 = "DDERR_EXCLUSIVEMODEALREADYSET";
          goto LABEL_173;
        case 122:
          v5 = "DDERR_NOTFLIPPABLE";
          goto LABEL_173;
        case 123:
          v5 = "DDERR_CANTDUPLICATE";
          goto LABEL_173;
        case 125:
          v5 = "DDERR_CANTCREATEDC";
          goto LABEL_173;
        case 126:
          v5 = "DDERR_NODC";
          goto LABEL_173;
        case 127:
          v5 = "DDERR_WRONGMODE";
          goto LABEL_173;
        case 128:
          v5 = "DDERR_IMPLICITLYCREATED";
          goto LABEL_173;
        case 129:
          v5 = "DDERR_NOTPALETTIZED";
          goto LABEL_173;
        case 130:
          v5 = "DDERR_UNSUPPORTEDMODE";
          goto LABEL_173;
        case 131:
          v5 = "DDERR_NOMIPMAPHW";
          goto LABEL_173;
        case 132:
          v5 = "DDERR_INVALIDSURFACETYPE";
          goto LABEL_173;
        case 140:
          v5 = "DDERR_NOOPTIMIZEHW";
          goto LABEL_173;
        case 141:
          v5 = "DDERR_NOTLOADED";
          goto LABEL_173;
        case 142:
          v5 = "DDERR_NOFOCUSWINDOW";
          goto LABEL_173;
        case 160:
          v5 = "DDERR_DCALREADYCREATED";
          goto LABEL_173;
        case 170:
          v5 = "DDERR_NONONLOCALVIDMEM";
          goto LABEL_173;
        case 180:
          v5 = "DDERR_CANTPAGELOCK";
          goto LABEL_173;
        case 200:
          v5 = "DDERR_CANTPAGEUNLOCK";
          goto LABEL_173;
        case 220:
          v5 = "DDERR_NOTPAGELOCKED";
          goto LABEL_173;
        case 230:
          v5 = "DDERR_MOREDATA";
          goto LABEL_173;
        case 231:
          v5 = "DDERR_EXPIRED";
          goto LABEL_173;
        case 235:
          v5 = "DDERR_VIDEONOTACTIVE";
          goto LABEL_173;
        case 239:
          v5 = "DDERR_DEVICEDOESNTOWNSURFACE";
          goto LABEL_173;
        default:
          goto LABEL_174;
        case 124:
          goto LABEL_176;
      }
      goto LABEL_176;
    }
    if ( v4 != -2005532222 )
    {
      if ( v4 > -2005532447 )
      {
        if ( v4 <= -2005532337 )
        {
          if ( v4 == -2005532337 )
          {
            v5 = "DDERR_NOVSYNCHW";
            goto LABEL_173;
          }
          if ( v4 > -2005532392 )
          {
            if ( v4 == -2005532382 )
            {
              v5 = "DDERR_NOROTATIONHW";
              goto LABEL_173;
            }
            if ( v4 == -2005532362 )
            {
              v5 = "DDERR_NOSTRETCHHW";
              goto LABEL_173;
            }
            if ( v4 == -2005532356 )
            {
              v5 = "DDERR_NOT4BITCOLOR";
              goto LABEL_173;
            }
            if ( v4 == -2005532355 )
            {
              v5 = "DDERR_NOT4BITCOLORINDEX";
              goto LABEL_173;
            }
            if ( v4 == -2005532352 )
            {
              v5 = "DDERR_NOT8BITCOLOR";
              goto LABEL_173;
            }
            if ( v4 == -2005532342 )
            {
              v5 = "DDERR_NOTEXTUREHW";
              goto LABEL_173;
            }
          }
          else
          {
            if ( v4 == -2005532392 )
            {
              v5 = "DDERR_NORASTEROPHW";
              goto LABEL_173;
            }
            if ( v4 == -2005532442 )
            {
              v5 = "DDERR_NOFLIPHW";
              goto LABEL_173;
            }
            if ( v4 == -2005532432 )
            {
              v5 = "DDERR_NOGDI";
              goto LABEL_173;
            }
            if ( v4 == -2005532422 )
            {
              v5 = "DDERR_NOMIRRORHW";
              goto LABEL_173;
            }
            if ( v4 == -2005532417 )
            {
              v5 = "DDERR_NOTFOUND";
              goto LABEL_173;
            }
            if ( v4 == -2005532412 )
            {
              v5 = "DDERR_NOOVERLAYHW";
              goto LABEL_173;
            }
            if ( v4 == -2005532402 )
            {
              v5 = "DDERR_OVERLAPPINGRECTS";
              goto LABEL_173;
            }
          }
          goto LABEL_174;
        }
        if ( v4 <= -2005532285 )
        {
          if ( v4 == -2005532285 )
          {
            v5 = "DDERR_PALETTEBUSY";
            goto LABEL_173;
          }
          if ( v4 == -2005532332 )
          {
            v5 = "DDERR_NOZBUFFERHW";
            goto LABEL_173;
          }
          if ( v4 == -2005532322 )
          {
            v5 = "DDERR_NOZOVERLAYHW";
            goto LABEL_173;
          }
          if ( v4 == -2005532312 )
          {
            v5 = "DDERR_OUTOFCAPS";
            goto LABEL_173;
          }
          if ( v4 == -2005532292 )
          {
            v5 = "DDERR_OUTOFVIDEOMEMORY";
            goto LABEL_173;
          }
          if ( v4 == -2005532290 )
          {
            v5 = "DDERR_OVERLAYCANTCLIP";
            goto LABEL_173;
          }
          if ( v4 == -2005532288 )
          {
            v5 = "DDERR_OVERLAYCOLORKEYONLYONEACTIVE";
            goto LABEL_173;
          }
          goto LABEL_174;
        }
        if ( v4 == -2005532272 )
        {
          v5 = "DDERR_COLORKEYNOTSET";
          goto LABEL_173;
        }
        if ( v4 == -2005532262 )
        {
          v5 = "DDERR_SURFACEALREADYATTACHED";
          goto LABEL_173;
        }
        if ( v4 == -2005532252 )
        {
          v5 = "DDERR_SURFACEALREADYDEPENDENT";
          goto LABEL_173;
        }
        if ( v4 != -2005532242 )
        {
          if ( v4 == -2005532237 )
          {
            v5 = "DDERR_CANTLOCKSURFACE";
            goto LABEL_173;
          }
          if ( v4 == -2005532232 )
          {
            v5 = "DDERR_SURFACEISOBSCURED";
            goto LABEL_173;
          }
          goto LABEL_174;
        }
      }
      else
      {
        if ( v4 == -2005532447 )
        {
          v5 = "DDERR_NOEXCLUSIVEMODE";
          goto LABEL_173;
        }
        if ( v4 <= -2005532562 )
        {
          if ( v4 == -2005532562 )
          {
            v5 = "DDERR_INVALIDCLIPLIST";
            goto LABEL_173;
          }
          if ( v4 > -2005532662 )
          {
            if ( v4 == -2005532652 )
            {
              v5 = "DDERR_CANNOTDETACHSURFACE";
              goto LABEL_173;
            }
            if ( v4 == -2005532632 )
            {
              v5 = "DDERR_CURRENTLYNOTAVAIL";
              goto LABEL_173;
            }
            if ( v4 == -2005532617 )
            {
              v5 = "DDERR_EXCEPTION";
              goto LABEL_173;
            }
            if ( v4 == -2005532582 )
            {
              v5 = "DDERR_HEIGHTALIGN";
              goto LABEL_173;
            }
            if ( v4 == -2005532577 )
            {
              v5 = "DDERR_INCOMPATIBLEPRIMARY";
              goto LABEL_173;
            }
            if ( v4 == -2005532572 )
            {
              v5 = "DDERR_INVALIDCAPS";
              goto LABEL_173;
            }
          }
          else
          {
            if ( v4 == -2005532662 )
            {
              v5 = "DDERR_CANNOTATTACHSURFACE";
              goto LABEL_173;
            }
            if ( v4 == -2147467263 )
            {
              v5 = "DDERR_UNSUPPORTED";
              goto LABEL_173;
            }
            if ( v4 == -2147467259 )
            {
              v5 = "DDERR_GENERIC";
              goto LABEL_173;
            }
            if ( v4 == -2147221008 )
            {
              v5 = "DDERR_NOTINITIALIZED";
              goto LABEL_173;
            }
            if ( v4 == -2147024882 )
            {
              v5 = "DDERR_OUTOFMEMORY";
              goto LABEL_173;
            }
            if ( v4 == -2147024809 )
            {
              v5 = "DDERR_INVALIDPARAMS";
              goto LABEL_173;
            }
            if ( v4 == -2005532667 )
            {
              v5 = "DDERR_ALREADYINITIALIZED";
LABEL_173:
              v16 = strlen(v5);
              v15 = (char *)v5;
LABEL_175:
              sub_40E32E((int)&v19, v15, v16);
              v16 = a3;
              pD3DRenderer->dword_040110 = 0;
              v18 = &v12;
              sub_40E2C8(&v12, Str, (int)((char *)&a1 + 3));
              v11 = 48;
              LOBYTE(v20) = 1;
              Str = &v7;
              sub_40E2C8(&v7, "Direct Draw Error", (int)((char *)&a3 + 3));
              LOBYTE(v20) = 0;
              sub_466D83((int)&v19, v7, v8, v9, v10, v11, v12, v13, v14, (int)v15, v16);
              v3 = 1;
              goto LABEL_176;
            }
          }
LABEL_174:
          sprintfex(&Src, "Unknown DirectDraw/Direct3D error number %X", v4);
          v16 = strlen(&Src);
          v15 = &Src;
          goto LABEL_175;
        }
        if ( v4 > -2005532492 )
        {
          if ( v4 == -2005532467 )
          {
            v5 = "DDERR_NOCLIPLIST";
            goto LABEL_173;
          }
          if ( v4 == -2005532462 )
          {
            v5 = "DDERR_NOCOLORCONVHW";
            goto LABEL_173;
          }
          if ( v4 == -2005532460 )
          {
            v5 = "DDERR_NOCOOPERATIVELEVELSET";
            goto LABEL_173;
          }
          if ( v4 == -2005532457 )
          {
            v5 = "DDERR_NOCOLORKEY";
            goto LABEL_173;
          }
          if ( v4 == -2005532452 )
          {
            v5 = "DDERR_NOCOLORKEYHW";
            goto LABEL_173;
          }
          if ( v4 == -2005532450 )
          {
            v5 = "DDERR_NODIRECTDRAWSUPPORT";
            goto LABEL_173;
          }
          goto LABEL_174;
        }
        if ( v4 == -2005532492 )
        {
          v5 = "DDERR_NOALPHAHW";
          goto LABEL_173;
        }
        if ( v4 == -2005532552 )
        {
          v5 = "DDERR_INVALIDMODE";
          goto LABEL_173;
        }
        if ( v4 == -2005532542 )
        {
          v5 = "DDERR_INVALIDOBJECT";
          goto LABEL_173;
        }
        if ( v4 == -2005532527 )
        {
          v5 = "DDERR_INVALIDPIXELFORMAT";
          goto LABEL_173;
        }
        if ( v4 != -2005532522 )
        {
          if ( v4 == -2005532512 )
          {
            v5 = "DDERR_LOCKEDSURFACES";
            goto LABEL_173;
          }
          if ( v4 == -2005532502 )
          {
            v5 = "DDERR_NO3D";
            goto LABEL_173;
          }
          goto LABEL_174;
        }
      }
    }
LABEL_176:
    v20 = -1;
    sub_40E2F6((int)&v19, 1);
    return v3;
  }
  return 0;
}

//----- (MM7.exe::00466D83) --------------------------------------------------------
void __stdcall sub_466D83(int a1, char a2, LPCSTR lpCaption, int a4, int a5, UINT uType, char a7, int a8, int a9, int a10, int a11)
{
  int v11; // eax@4
  const CHAR *v12; // edx@11
  int v13; // eax@11
  const CHAR *v14; // eax@13
  int v15; // eax@16
  char v16; // [sp-10h] [bp-3Ch]@11
  int v17; // [sp-Ch] [bp-38h]@11
  int v18; // [sp-8h] [bp-34h]@11
  int v19; // [sp-4h] [bp-30h]@11
  char v20; // [sp+Ch] [bp-20h]@11
  char *v21; // [sp+1Ch] [bp-10h]@11
  int v22; // [sp+28h] [bp-4h]@1

  v22 = 1;
  if ( LODWORD(dword_720010) )
    sub_46B14F(SLODWORD(dword_720010));
  if ( LODWORD(class00_global) )
  {
    v11 = *(_DWORD *)(LODWORD(class00_global) + 3692);
    if ( v11 )
    {
      if ( *(_BYTE *)(v11 + 4) )
      {
        if ( dword_69B00C )
          sub_45B329(dword_69B00C);
      }
    }
  }
  if (pD3DRenderer)
  {
    if (pD3DRenderer->dword_00000C == 1 )
      SetWindowPos(hWnd_global, (HWND)0xFFFFFFFE, 0, 0, 0, 0, 0x18u);
  }
  ClipCursor(0);
  v21 = &v16;
  sub_4679B4(&v16, (int)&a7);
  v13 = sub_4678E2((int)&v20, a11, v16, v17, v18, v19);
  LOBYTE(v22) = 2;
  sub_467AAF(a1, v13, 0, 0xFFFFFFFFu);
  LOBYTE(v22) = 1;
  sub_40E2F6((int)&v20, 1);
  v12 = lpCaption;
  if ( !lpCaption )
    v12 = byte_4D8410 + 736;
  v14 = *(const CHAR **)(a1 + 4);
  if ( !v14 )
    v14 = byte_4D8410 + 736;
  MessageBoxA(hWnd_global, v14, v12, uType);
  if ( LODWORD(class00_global) )
  {
    v15 = *(_DWORD *)(LODWORD(class00_global) + 3692);
    if ( v15 )
    {
      if ( *(_BYTE *)(v15 + 4) )
      {
        if ( dword_69B00C )
          sub_45B2A7(dword_69B00C);
      }
    }
  }
  if ( LODWORD(dword_720010) )
    sub_46B105(LODWORD(dword_720010));
  LOBYTE(v22) = 0;
  sub_40E2F6((int)&a2, 1);
  v22 = -1;
  sub_40E2F6((int)&a7, 1);
}

//----- (MM7.exe::0046778D) --------------------------------------------------------
char __stdcall sub_46778D(int a1, const char *Str, int a3)
{
  char result; // al@2
  size_t v4; // eax@2
  char v5; // [sp-28h] [bp-50h]@2
  const CHAR *v6; // [sp-24h] [bp-4Ch]@2
  int v7; // [sp-20h] [bp-48h]@2
  int v8; // [sp-1Ch] [bp-44h]@2
  UINT v9; // [sp-18h] [bp-40h]@2
  char v10; // [sp-14h] [bp-3Ch]@2
  int v11; // [sp-10h] [bp-38h]@2
  int v12; // [sp-Ch] [bp-34h]@2
  int v13; // [sp-8h] [bp-30h]@2
  int v14; // [sp-4h] [bp-2Ch]@2
  int v15; // [sp+8h] [bp-20h]@2
  char *v16; // [sp+18h] [bp-10h]@2
  int v17; // [sp+24h] [bp-4h]@2

  if ( a1 )
  {
    LOBYTE(v15) = BYTE3(a1);
    sub_40E2F6((int)&v15, 0);
    v4 = strlen("Unknown Direct Input error");
    sub_40E32E((int)&v15, "Unknown Direct Input error", v4);
    v14 = a3;
    v17 = 0;
    v16 = &v10;
    sub_40E2C8(&v10, Str, (int)((char *)&a1 + 3));
    v9 = 48;
    LOBYTE(v17) = 1;
    Str = &v5;
    sub_40E2C8(&v5, "Direct Input Error", (int)((char *)&a3 + 3));
    LOBYTE(v17) = 0;
    sub_466D83((int)&v15, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14);
    v17 = -1;
    sub_40E2F6((int)&v15, 1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}