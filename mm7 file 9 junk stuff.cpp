#include "defs.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"
 #include "_lod.h"
#include "data.h"

/*x87 COMPARISON OPCODES

  if (a == b)
00D07D7D D9 45 A4             fld         dword ptr [ebp-5Ch]  
00D07D80 D9 45 A0             fld         dword ptr [ebp-60h]  
00D07D83 DA E9                fucompp  
00D07D85 DF E0                fnstsw      ax  
00D07D87 F6 C4 44             test        ah,44h  
00D07D8A 7A 11                jp          NOT_EQUAL

  if (a != b)
00D07D9E D9 45 A4             fld         dword ptr [ebp-5Ch]  
00D07DA1 D9 45 A0             fld         dword ptr [ebp-60h]  
00D07DA4 DA E9                fucompp  
00D07DA6 DF E0                fnstsw      ax  
00D07DA8 F6 C4 44             test        ah,44h  
00D07DAB 7B 11                jnp         EQUAL

  if (a > b)
00C97D7D D9 45 A4             fld         dword ptr [ebp-5Ch]  
00C97D80 D9 45 A0             fld         dword ptr [ebp-60h]  
00C97D83 DE D9                fcompp  
00C97D85 DF E0                fnstsw      ax  
00C97D87 F6 C4 05             test        ah,5  
00C97D8A 7A 11                jp          LESS_OR_EQUAL

  if (a >= b)
00C97D9E D9 45 A4             fld         dword ptr [ebp-5Ch]  
00C97DA1 D9 45 A0             fld         dword ptr [ebp-60h]  
00C97DA4 DE D9                fcompp  
00C97DA6 DF E0                fnstsw      ax  
00C97DA8 F6 C4 41             test        ah,41h  
00C97DAB 7A 11                jp/jz       LESS

  if (a < b)
00C97DBF D9 45 A4             fld         dword ptr [ebp-5Ch]  
00C97DC2 D9 45 A0             fld         dword ptr [ebp-60h]  
00C97DC5 DE D9                fcompp  
00C97DC7 DF E0                fnstsw      ax  
00C97DC9 F6 C4 41             test        ah,41h  
00C97DCC 75 11                jne         GREATER_OR_EQUAL

  if (a <= b)
00C97DE0 D9 45 A4             fld         dword ptr [ebp-5Ch]  
00C97DE3 D9 45 A0             fld         dword ptr [ebp-60h]  
00C97DE6 DE D9                fcompp  
00C97DE8 DF E0                fnstsw      ax  
00C97DEA F6 C4 01             test        ah,1  
00C97DED 75 11                jne         GREATER
*/




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

int __ArrayUnwind(char *a3, unsigned int a4, int a5, int (*a6)(void))
{
  char v6; // sf@2
  char v7; // [sp-Ch] [bp-24h]@1
  char *v8; // [sp+0h] [bp-18h]@1
  int v10; // [sp+8h] [bp-10h]@1
  int (__cdecl *v11)(int, int, int); // [sp+Ch] [bp-Ch]@1
  signed int v12; // [sp+10h] [bp-8h]@1
  int v13; // [sp+14h] [bp-4h]@1

  compile_error;
  v12 = 5091600;
  //v11 = unknown_libname_59;
  v8 = &v7;
  v13 = 0;
  while ( 1 )
  {
    v6 = a5-- - 1 < 0;
    if ( v6 )
      break;
    a3 -= a4;
    a6();
  }
}


void sub_4CC412(int a1)
{
  if ( !*(_DWORD *)(a1 - 32) )
    __ArrayUnwind(
      *(char **)(a1 + 8),
      *(_DWORD *)(a1 + 12),
      *(_DWORD *)(a1 - 28),
      *(int (__thiscall **)())(a1 + 24));
}


void sub_4CC31C(int a1)
{
  if ( !*(_DWORD *)(a1 - 28) )
    __ArrayUnwind(
      *(char **)(a1 + 8),
      *(_DWORD *)(a1 + 12),
      *(_DWORD *)(a1 + 16),
      *(int (__thiscall **)())(a1 + 20));
}


// sub_4CC3A8: using guessed type _DWORD __stdcall _eh vector constructor iterator_(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
void __stdcall _eh_vector_constructor_iterator_(int a1, unsigned int uElementSize, unsigned int uNumElements, void (__fastcall *a4)(void *), void (__fastcall *a5)(void *))
{
  int i; // [sp+4h] [bp-1Ch]@1

  for ( i = 0; i < uNumElements; ++i )
  {
    a4((void *)a1);
    a1 += uElementSize;
  }
  //sub_4CC412(1);
}

// sub_4CC2B4: using guessed type _DWORD __stdcall _eh vector destructor iterator_(_DWORD, _DWORD, _DWORD, _DWORD);
void __stdcall _eh_vector_destructor_iterator_(int a1, int a2, int a3, void (__fastcall *a4)(void *))
{
  char v4; // sf@2
  int i; // [sp+24h] [bp+8h]@1

  for ( i = a3 * a2 + a1; ; a4((void *)i) )
  {
    v4 = a3-- - 1 < 0;
    if ( v4 )
      break;
    i -= a2;
  }
  //sub_4CC31C(1);
}



//#error "FFFFFFFF: variables would overlap: edx/4 and edx/8 (funcsize=96)"
void sub_41AD6E()
{
 int     local_0,
         local_1;
 __int64 eax_ecx,
         ecx_eax;

 eax_ecx = pParty_global->qword_00002C - qword_507CC8;
 if (eax_ecx < 0)
   qword_507CC8 = 0;
 /*__asm
 {
  push    ecx
  push    ecx
  //mov     edx, dword ptr [qword_ACCFE4]
  {
   mov edx, dword ptr [pParty_global]
   mov edx, dword ptr [edx + 0x2C]
  }
  push    ebx
  push    esi
  //mov     esi, dword ptr [qword_ACCFE4+4]
  {
   mov esi, dword ptr [pParty_global]
   mov esi, dword ptr [esi + 0x2C + 4]
  }
  mov     ecx, edx
  mov     eax, esi
  sub     ecx, dword ptr [qword_507CC8]
  sbb     eax, dword ptr [qword_507CC8+4]  //eax:ecx = pParty_global->qword_00002C - qword_507CC8
  xor     ebx, ebx
  cmp     eax, ebx         
  jg      short loc_41ADA6                 //if      eax:ecx positive
  jl      short loc_41AD9A                 //else if eax:ecx negative
  cmp     ecx, ebx                         //else: eax:ecx fits in 32bits, 
  jnb     short loc_41ADA6                 //if ecx >= 0
                                           //else (negative)
  //if pParty_global->qword_00002C - qword_507CC8 < 0, qword_507CC8 = 0
loc_41AD9A:                               
  mov     dword ptr [qword_507CC8], ebx
  mov     dword ptr [qword_507CC8+4], ebx
 }*/



 ecx_eax = pParty_global->qword_00002C - qword_507CC8;
 local_0 = HIWORD(ecx_eax);
 /*__asm
 {
loc_41ADA6:                             ; CODE XREF: sub_41AD6E+24j
                                         ; sub_41AD6E+2Aj
  mov     eax, edx
  mov     ecx, esi
  sub     eax, dword ptr [qword_507CC8]
  sbb     ecx, dword ptr [qword_507CC8+4]
  mov     dword ptr [esp+16-4], ecx   // local var @ local frame:  -> ecx <- ecx ebx esi
 }*/

 __asm
 {
  {
   //restore asm state
   xor ebx, ebx
     mov edx, dword ptr [pParty_global]
     mov edx, dword ptr [edx + 0x2C]
   mov esi, dword ptr [pParty_global]
   mov esi, dword ptr [esi + 0x2C + 4]
     sub esp, 16     //local frame: ecx ecx ebx esi
   mov     eax, edx
   mov     ecx, esi
   sub     eax, dword ptr [qword_507CC8]
   sbb     ecx, dword ptr [qword_507CC8+4]
  }

  js      loc_41AE97
  jg      short loc_41ADCD

  {
   add esp, 16
  }
 }

 if (LODWORD(ecx_eax) <= 128)
   return;


 /*__asm
 {
  mov     dword ptr [qword_507CC8], edx
  mov     dword ptr [qword_507CC8+4], esi
 }*/
 
 qword_507CC8 = pParty_global->qword_00002C;


  __asm loc_41ADCD:
 /*
 __asm
 {
loc_41ADCD:                             ; CODE XREF: sub_41AD6E+52j
  cmp     byte ptr [byte_50697C], bl
  setz    al
  cmp     al, bl
  mov     byte ptr [byte_50697C], al
  jz      loc_41AE9C
  cmp     dword ptr [dword_4E28F8], 5
  jz      loc_41AE9C
 }*/
 byte_50697C = ~byte_50697C;
 if (!byte_50697C || dword_4E28F8 == 5)
 {
  /*__asm
  {
loc_41AE9C:                             ; CODE XREF: sub_41AD6E+7Bj
                                        ; sub_41AD6E+88j
  //push    offset unk_507ABC
  {
   mov esi, dword ptr [pTexture_RightFrame]
   push esi
  }
  push    ebx
  push    468
  mov ecx, dword ptr [pD3DRenderer]
  call    Render_DrawRGBTexture
  pop     esi
  pop     ebx
  add     esp, 8
  jmp     sub_491F87_DrawHiredNPCs
  }*/

  //Render_DrawRGBTexture(pD3DRenderer, 468, 0, pTexture_RightFrame);
  sub_491F87_DrawHiredNPCs();
  return;
 }

 /*__asm
 {
  cmp     byte ptr [byte_50794A], bl
  mov     esi, dword ptr [pD3DRenderer]
  jz      short loc_41AE33
  mov     eax, dword ptr [uTextureIdx_ib_td1_A]
  mov     ecx, eax
  inc     ecx
  lea     eax, [eax+eax*8]
  neg     ecx
  lea     eax, ds:6D084Ch[eax*8]
  sbb     ecx, ecx
  and     ecx, eax
  push    ecx
  push    163h
  push    1EDh
  mov     ecx, esi
  call    Render_DrawTransparentTexture
 }*/
 if (byte_50794A)
   Render_DrawTransparentTexture(pD3DRenderer, 493, 355, &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td1_A]);

 /*__asm
 {
loc_41AE33:                             ; CODE XREF: sub_41AD6E+99j
  cmp     byte ptr [byte_507949], bl
  jz      short loc_41AE65
  mov     eax, dword ptr [uTextureIdx_ib_td2_A]
  mov     ecx, eax
  inc     ecx
  lea     eax, [eax+eax*8]
  neg     ecx
  lea     eax, ds:6D084Ch[eax*8]
  sbb     ecx, ecx
  and     ecx, eax
  push    ecx
  push    161h
  push    20Fh
  mov     ecx, esi
  call    Render_DrawTransparentTexture
 }*/
 if (byte_507949)
   Render_DrawTransparentTexture(pD3DRenderer, 527, 353, &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td2_A]);

 /*__asm
 {
loc_41AE65:                             ; CODE XREF: sub_41AD6E+CBj
  cmp     byte ptr [byte_507948], bl
  jz      short loc_41AE97
  mov     eax, dword ptr [uTextureIdx_ib_td5_A]
  mov     ecx, eax
  inc     ecx
  lea     eax, [eax+eax*8]
  neg     ecx
  lea     eax, ds:6D084Ch[eax*8]
  sbb     ecx, ecx
  and     ecx, eax
  push    ecx
  push    169h
  push    258h
  mov     ecx, esi
  call    Render_DrawTransparentTexture
 }*/
 if (byte_507948)
   Render_DrawTransparentTexture(pD3DRenderer, 600, 361, &LODFile_Icons_LOD.aLODHeaders[uTextureIdx_ib_td5_A]);
 return;
 /*
 __asm
 {
loc_41AE97:                             ; CODE XREF: sub_41AD6E+4Cj
                                        ; sub_41AD6E+59j ...
  pop     esi
  pop     ebx
  pop     ecx
  pop     ecx
  retn
 ; ---------------------------------------------------------------------------

loc_41AE9C:                             ; CODE XREF: sub_41AD6E+7Bj
                                        ; sub_41AD6E+88j
  //push    offset unk_507ABC
  {
   mov esi, dword ptr [pTexture_RightFrame]
   push esi
  }
  push    ebx
  push    468
  mov ecx, dword ptr [pD3DRenderer]
  call    Render_DrawRGBTexture
  pop     esi
  pop     ebx
  add     esp, 8
  jmp     sub_491F87_DrawHiredNPCs
 }*/

 __asm loc_41AE97:
 return;
}

void __fastcall sub_43B569(void *_this)
{
 __asm int 3
}

//----- (0045D73F) --------------------------------------------------------
//#error "45D747: call analysis failed (funcsize=6)"
void __stdcall class04_sub_45D73F(struct class04 *_this, long a1)
{
 if (a1 - 2)
   return;

 sub_45DCA9((int)_this, 0, 0, 0, 0, 0); // only first arg is checked, the rest may be redudant
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

void __fastcall class04_stru0_ctor(struct class04_stru0 *_this)
{
  sub_40E4C2(_this);
 _this->dword_000C18 = 0;
 _this->ptr_000000 = (char *)0x4D86F8;
}

int sub_486009()
{
  ReleaseDrawBuffers();
  return 0;
}

void __fastcall sub_43B60C(void *_this)
{
 __asm int 3
}

int sub_4C5910()
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

 //v5 = _this;
 //*(_DWORD *)_this = 5080748;
 if (pSmthn)
   *pSmthn = &byte_4D8410[668];

 if (a5)
 {
  if (a5 != 1)
  {
   err_show();
   return pSmthn;
  }
  v6 = sub_46778D(hr, pSourceFile, uSourceline);
 }
 else v6 = ErrorMessageFromHRESULT(hr, pSourceFile, uSourceline);

 if (v6)
   err_show();

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
    CGame_stru0_sub_40E2F6((CGame_stru0 *)&v19, 0);
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
              Game_sub_40E2C8(&v12, Str, (int)((char *)&a1 + 3));
              v11 = 48;
              LOBYTE(v20) = 1;
              Str = &v7;
              Game_sub_40E2C8(&v7, "Direct Draw Error", (int)((char *)&a3 + 3));
              LOBYTE(v20) = 0;
              sub_466D83((int)&v19, v7, v8, v9, v10, v11, v12, v13, v14, (int)v15, v16);
              v3 = 1;
              goto LABEL_176;
            }
          }
LABEL_174:
          wsprintfA(&Src, "Unknown DirectDraw/Direct3D error number %X", v4);
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
    CGame_stru0_sub_40E2F6((CGame_stru0 *)&v19, 1);
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
  if (dword_720010)
    Mouse_suspend(dword_720010);
  if (pGame)
  {
    v11 = (int)pGame->class14_obj;
    if ( v11 )
    {
      if (*(_BYTE *)(v11 + 4))
      {
        if (pAsyncKeyboard)
          Keyboard_suspend(pAsyncKeyboard);
      }
    }
  }
  if (pD3DRenderer)
  {
    if (pD3DRenderer->uAcquiredDirect3DDevice == 1 )
      SetWindowPos(pAppWindow->GetAPIHandle(), (HWND)0xFFFFFFFE, 0, 0, 0, 0, 0x18u);
  }
  ClipCursor(0);
  v21 = &v16;
  sub_4679B4(&v16, (int)&a7);
  v13 = sub_4678E2((int)&v20, a11, v16, v17, v18, v19);
  LOBYTE(v22) = 2;
  sub_467AAF(a1, v13, 0, 0xFFFFFFFFu);
  LOBYTE(v22) = 1;
  CGame_stru0_sub_40E2F6((CGame_stru0 *)&v20, 1);
  v12 = lpCaption;
  if ( !lpCaption )
    v12 = (char *)byte_4D8410 + 736;
  v14 = *(const CHAR **)(a1 + 4);
  if ( !v14 )
    v14 = (char *)byte_4D8410 + 736;
  MessageBoxA(pAppWindow->GetAPIHandle(), v14, v12, uType);
  if (pGame)
  {
    v15 = (int)pGame->class14_obj;
    if ( v15 )
    {
      if ( *(_BYTE *)(v15 + 4) )
      {
        if (pAsyncKeyboard)
          CAsyncKeyboard_Resume(pAsyncKeyboard);
      }
    }
  }
  if (dword_720010)
    sub_46B105((void *)dword_720010);
  LOBYTE(v22) = 0;
  CGame_stru0_sub_40E2F6((CGame_stru0 *)&a2, 1);
  v22 = -1;
  CGame_stru0_sub_40E2F6((CGame_stru0 *)&a7, 1);
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
    CGame_stru0_sub_40E2F6((CGame_stru0 *)&v15, 0);
    v4 = strlen("Unknown Direct Input error");
    sub_40E32E((int)&v15, "Unknown Direct Input error", v4);
    v14 = a3;
    v17 = 0;
    v16 = &v10;
    Game_sub_40E2C8(&v10, Str, (int)((char *)&a1 + 3));
    v9 = 48;
    LOBYTE(v17) = 1;
    Str = &v5;
    Game_sub_40E2C8(&v5, "Direct Input Error", (int)((char *)&a3 + 3));
    LOBYTE(v17) = 0;
    sub_466D83((int)&v15, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14);
    v17 = -1;
    CGame_stru0_sub_40E2F6((CGame_stru0 *)&v15, 1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004CEE48) --------------------------------------------------------
void *sub_4CEE48(int a1, const void *Src, int Size)
{
  const void *v3; // ebx@1
  int v4; // edi@1
  void *result; // eax@2
  int v6; // esi@3
  int v7; // eax@7
  size_t v8; // eax@12
  size_t v9; // eax@19
  int v10; // eax@36
  size_t v11; // eax@41
  size_t v12; // eax@47
  int v13; // [sp+0h] [bp-38h]@36
  size_t v14; // [sp+4h] [bp-34h]@41
  int v15; // [sp+8h] [bp-30h]@36
  int v16; // [sp+Ch] [bp-2Ch]@36
  unsigned int v17; // [sp+10h] [bp-28h]@7
  void *Dst; // [sp+14h] [bp-24h]@6
  size_t v19; // [sp+18h] [bp-20h]@12
  int v20; // [sp+28h] [bp-10h]@1
  int (__cdecl *v21)(int, int, int); // [sp+2Ch] [bp-Ch]@1
  signed int v22; // [sp+30h] [bp-8h]@1
  int v23; // [sp+34h] [bp-4h]@1

  compile_error;
  return 0;
  /*
  v23 = -1;
  v22 = 5091904;
  compile_error;//v21 = unknown_libname_59;
  v20 = a1;
  v3 = Src;
  v4 = 0;
  if ( Src )
  {
    v6 = Size;
    if ( Size )
    {
      if ( dword_F94508 == 3 )
      {
        while ( 1 )
        {
          Dst = 0;
          if ( (unsigned int)v6 <= 0xFFFFFFE0 )
          {
            _lock(9);
            v23 = 0;
            v7 = __sbh_find_block(Src);
            v17 = v7;
            if ( v7 )
            {
              if ( v6 <= (unsigned int)dword_F94500 )
              {
                if ( __sbh_resize_block(v7, Src, v6) )
                {
                  Dst = (void *)Src;
                }
                else
                {
                  Dst = (void *)__sbh_alloc_block(v6);
                  if ( Dst )
                  {
                    v8 = *((_DWORD *)Src - 1) - 1;
                    v19 = v8;
                    if ( v8 >= v6 )
                      v8 = v6;
                    memcpy(Dst, Src, v8);
                    v17 = __sbh_find_block(Src);
                    sub_4CFDE7(v17, (int)Src);
                  }
                }
              }
              if ( !Dst )
              {
                if ( !v6 )
                  v6 = 1;
                v6 = (v6 + 15) & 0xFFFFFFF0;
                Dst = HeapAlloc(hHeap, 0, v6);
                if ( Dst )
                {
                  v9 = *((_DWORD *)Src - 1) - 1;
                  v19 = v9;
                  if ( v9 >= v6 )
                    v9 = v6;
                  memcpy(Dst, Src, v9);
                  sub_4CFDE7(v17, (int)Src);
                }
              }
            }
            v23 = -1;
            sub_4CEFD3();
            if ( !v17 )
            {
              if ( !v6 )
                v6 = 1;
              v6 = (v6 + 15) & 0xFFFFFFF0;
              Dst = HeapReAlloc(hHeap, 0, (LPVOID)Src, v6);
            }
          }
          result = Dst;
          if ( Dst )
            break;
          if ( !dword_F94004 )
            break;
          if ( !_callnewh(v6) )
            goto LABEL_63;
        }
      }
      else
      {
        if ( dword_F94508 == 2 )
        {
          if ( (unsigned int)Size <= 0xFFFFFFE0 )
          {
            if ( (unsigned int)Size <= 0 )
              v6 = 16;
            else
              v6 = (Size + 15) & 0xFFFFFFF0;
          }
          while ( 1 )
          {
            Dst = (void *)v4;
            if ( (unsigned int)v6 <= 0xFFFFFFE0 )
            {
              _lock(9);
              v23 = 1;
              v10 = sub_4D0B17((unsigned int)v3, (int)&v13, (int)&v16);
              v4 = v10;
              v15 = v10;
              if ( v10 )
              {
                if ( v6 < (unsigned int)dword_4F4D8C )
                {
                  if ( sub_4D0EDF(v13, v16, v10, (unsigned int)v6 >> 4) )
                  {
                    Dst = (void *)Src;
                  }
                  else
                  {
                    Dst = (void *)sub_4D0BB3((unsigned int)v6 >> 4);
                    if ( Dst )
                    {
                      v11 = 16 * *(_BYTE *)v4;
                      v14 = v11;
                      if ( v11 >= v6 )
                        v11 = v6;
                      memcpy(Dst, Src, v11);
                      sub_4D0B6E(v13, v16, v4);
                    }
                  }
                  v3 = Src;
                }
                if ( !Dst )
                {
                  Dst = HeapAlloc(hHeap, 0, v6);
                  if ( Dst )
                  {
                    v12 = 16 * *(_BYTE *)v4;
                    v14 = v12;
                    if ( v12 >= v6 )
                      v12 = v6;
                    memcpy(Dst, v3, v12);
                    sub_4D0B6E(v13, v16, v4);
                  }
                }
              }
              else
              {
                Dst = HeapReAlloc(hHeap, 0, (LPVOID)v3, v6);
              }
              v23 = -1;
              sub_4CF121();
            }
            result = Dst;
            if ( Dst != (void *)v4 )
              break;
            if ( dword_F94004 == v4 )
              break;
            if ( !_callnewh(v6) )
              goto LABEL_63;
          }
        }
        else
        {
          while ( 1 )
          {
            result = 0;
            if ( (unsigned int)v6 <= 0xFFFFFFE0 )
            {
              if ( !v6 )
                v6 = 1;
              v6 = (v6 + 15) & 0xFFFFFFF0;
              result = HeapReAlloc(hHeap, 0, (LPVOID)Src, v6);
            }
            if ( result || !dword_F94004 )
              break;
            if ( !_callnewh(v6) )
              goto LABEL_63;
          }
        }
      }
    }
    else
    {
      free(a1, (unsigned int)Src);
LABEL_63:
      result = 0;
    }
  }
  else
  {
    result = malloc(Size);
  }
  return result;*/
}


//----- (MM7.exe::004CAF5C) -----crt free---------------------------------------------------
/*int call_delete(void *ptr)
{
  unsigned int v2; // eax@3
  char v3; // zf@5
  int v4; // eax@7
  void *v5; // [sp-10h] [bp-38h]@11
  int v6; // [sp+0h] [bp-28h]@7
  int v7; // [sp+4h] [bp-24h]@7
  int v8; // [sp+8h] [bp-20h]@7
  unsigned int v9; // [sp+Ch] [bp-1Ch]@3
  int v10; // [sp+18h] [bp-10h]@1
  int (__cdecl *v11)(int, int, int); // [sp+1Ch] [bp-Ch]@1
  signed int v12; // [sp+20h] [bp-8h]@1
  int v13; // [sp+24h] [bp-4h]@1

  runtime_warning();
  return 1;
  /*
  v13 = -1;
  v12 = 5091560;
  compile_error;//v11 = unknown_libname_59;
  v10 = result;
  if ( a2 )
  {
    if ( dword_F94508 == 3 )
    {
      _lock(9);
      v13 = 0;
      v2 = __sbh_find_block(a2);
      v9 = v2;
      if ( v2 )
        sub_4CFDE7(v2, a2);
      v13 = -1;
      result = sub_4CAFC6();
      v3 = v9 == 0;
    }
    else
    {
      if ( dword_F94508 != 2 )
      {
        v5 = (void *)a2;
        return HeapFree(hHeap, 0, v5);
      }
      _lock(9);
      v13 = 1;
      v4 = sub_4D0B17(a2, (int)&v6, (int)&v8);
      v7 = v4;
      if ( v4 )
        sub_4D0B6E(v6, v8, v4);
      v13 = -1;
      result = sub_4CB01E();
      v3 = v7 == 0;
    }
    if ( !v3 )
      return result;
    v5 = (void *)a2;
    return HeapFree(hHeap, 0, v5);
  }
  return result;
}
 */

//----- (004CD96F) --------------------------------------------------------
void *__cdecl sub_4CD96F(int a1, int a2)
{
  int v2; // esi@1
  int v3; // ebx@2
  void *result; // eax@20
  size_t v5; // [sp-18h] [bp-38h]@10
  void *v6; // [sp+0h] [bp-20h]@6
  int v7; // [sp+4h] [bp-1Ch]@1

  compile_warning;
  return (void *)1;
  /*
  v2 = a2 * a1;
  v7 = a2 * a1;
  if ( (unsigned int)(a2 * a1) > 0xFFFFFFE0 )
  {
    v3 = 0;
  }
  else
  {
    v3 = 0;
    if ( !v2 )
      v2 = 1;
    v2 = (v2 + 15) & 0xFFFFFFF0;
  }
  while ( 1 )
  {
    v6 = (void *)v3;
    if ( (unsigned int)v2 <= 0xFFFFFFE0 )
    {
      if ( dword_F94508 == 3 )
      {
        if ( v7 > (unsigned int)dword_F94500 )
          goto LABEL_16;
        _lock(9);
        v6 = (void *)__sbh_alloc_block(v7);
        _unlock(9);
        if ( v6 != (void *)v3 )
        {
          v5 = a2 * a1;
LABEL_15:
          memset(v6, v3, v5);
          goto LABEL_16;
        }
      }
      else
      {
        if ( dword_F94508 != 2 || v2 > (unsigned int)dword_4F4D8C )
        {
LABEL_16:
          if ( v6 != (void *)v3 )
            return v6;
          goto LABEL_17;
        }
        _lock(9);
        v6 = (void *)sub_4D0BB3((unsigned int)v2 >> 4);
        _unlock(9);
        if ( v6 != (void *)v3 )
        {
          v5 = v2;
          goto LABEL_15;
        }
      }
LABEL_17:
      v6 = HeapAlloc(hHeap, 8u, v2);
    }
    if ( v6 != (void *)v3 || dword_F94004 == v3 )
      return v6;
    result = (void *)_callnewh(v2);
    if ( !result )
      return result;
  }*/
}

//----- (004CAE60) --------------------------------------------------------
LPVOID __cdecl sub_4CAE60(unsigned int a1)
{
  LPVOID result; // eax@3
  void *v2; // ST18_4@3
  int v3; // esi@7
  int v4; // ST18_4@10
  signed int v5; // eax@12
  int v6; // eax@14
  SIZE_T v7; // [sp-10h] [bp-2Ch]@11

  compile_error;
  return 0;
  /*
  if ( dword_F94508 == 3 )
  {
    if ( a1 <= dword_F94500 )
    {
      _lock(9);
      v2 = (void *)__sbh_alloc_block(a1);
      sub_4CAEC7();
      result = v2;
      if ( v2 )
        return result;
    }
    goto LABEL_12;
  }
  if ( dword_F94508 != 2 )
  {
LABEL_12:
    v5 = a1;
    if ( !a1 )
      v5 = 1;
    v6 = v5 + 15;
    LOBYTE(v6) = v6 & 0xF0;
    v7 = v6;
    goto LABEL_15;
  }
  if ( a1 )
    v3 = (a1 + 15) & 0xFFFFFFF0;
  else
    v3 = 16;
  if ( v3 > (unsigned int)dword_4F4D8C
    || (_lock(9), v4 = sub_4D0BB3((unsigned int)v3 >> 4), sub_4CAF26(), result = (LPVOID)v4, !v4) )
  {
    v7 = v3;
LABEL_15:
    result = HeapAlloc(hHeap, 0, v7);
  }
  return result;*/
}

//----- (004CF177) --------------------------------------------------------
SIZE_T sub_4CF177(int a1, unsigned int lpMem)
{
  int v2; // esi@3
  char v3; // zf@5
  int v4; // eax@7
  char v6; // [sp+0h] [bp-2Ch]@7
  int v7; // [sp+4h] [bp-28h]@7
  char v8; // [sp+8h] [bp-24h]@7
  int v9; // [sp+Ch] [bp-20h]@3
  int v10; // [sp+10h] [bp-1Ch]@2
  int v11; // [sp+1Ch] [bp-10h]@1
  int (__cdecl *v12)(int, int, int); // [sp+20h] [bp-Ch]@1
  signed int v13; // [sp+24h] [bp-8h]@1
  int v14; // [sp+28h] [bp-4h]@1

  compile_error;
  return 0;
  /*
  v14 = -1;
  v13 = 5091928;
  compile_error;//v12 = unknown_libname_59;
  v11 = a1;
  if ( dword_F94508 == 3 )
  {
    _lock(9);
    v14 = 0;
    v10 = __sbh_find_block(lpMem);
    if ( v10 )
    {
      v2 = *(_DWORD *)(lpMem - 4) - 9;
      v9 = *(_DWORD *)(lpMem - 4) - 9;
    }
    else
    {
      v2 = v9;
    }
    v14 = -1;
    sub_4CF1E1();
    v3 = v10 == 0;
  }
  else
  {
    if ( dword_F94508 != 2 )
      return HeapSize(hHeap, 0, (LPCVOID)lpMem);
    _lock(9);
    v14 = 1;
    v4 = sub_4D0B17(lpMem, (int)&v6, (int)&v8);
    v7 = v4;
    if ( v4 )
    {
      v2 = 16 * *(_BYTE *)v4;
      v9 = 16 * *(_BYTE *)v4;
    }
    else
    {
      v2 = v9;
    }
    v14 = -1;
    sub_4CF25C();
    v3 = v7 == 0;
  }
  if ( v3 )
    return HeapSize(hHeap, 0, (LPCVOID)lpMem);
  return v2;*/
}

//----- (004CFD17) --------------------------------------------------------
signed int __cdecl sub_4CFD17(int a1)
{
  __int32 v1; // eax@2
  LPVOID v2; // eax@3

  compile_error;
  return 0;
  /*
  hHeap = HeapCreate(a1 == 0, 0x1000u, 0);
  if ( !hHeap )
    return 0;
  v1 = sub_4CFBCF();
  dword_F94508 = v1;
  if ( v1 == 3 )
  {
    v2 = (LPVOID)__sbh_heap_init(1016);
  }
  else
  {
    if ( v1 != 2 )
      return 1;
    v2 = sub_4D08BB();
  }
  if ( !v2 )
  {
    HeapDestroy(hHeap);
    return 0;
  }
  return 1;*/
}