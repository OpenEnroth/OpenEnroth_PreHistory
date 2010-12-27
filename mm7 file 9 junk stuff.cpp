#include "defs.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"
 #include "_lod.h"
#include "data.h"

#include "Game.h"
#include "UserInput.h"

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



/*extern "C" _DWORD __cdecl _ld12cvt(_DWORD, _DWORD, void *)
{
 return 0;
}

extern "C" _DWORD __cdecl __strgtold12(void *, void *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD)
{
 return 0;
}*/

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

  compile_error();
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
  cmp     dword ptr [dword_4E28F8_PartyCantJumpIfTrue], 5
  jz      loc_41AE9C
 }*/
 byte_50697C = ~byte_50697C;
 if (!byte_50697C || dword_4E28F8_PartyCantJumpIfTrue == 5)
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
    Game_stru0_sub_40E2F6((Game_stru0 *)&v19, 0);
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
    Game_stru0_sub_40E2F6((Game_stru0 *)&v19, 1);
    return v3;
  }
  return 0;
}


//----- (0045B329) --------------------------------------------------------
void __thiscall CAsyncKeyboard_suspend(int _this)
{
  int v1; // esi@1
  char v2; // [sp-18h] [bp-24h]@2
  const CHAR *v3; // [sp-14h] [bp-20h]@2
  int v4; // [sp-10h] [bp-1Ch]@2
  int v5; // [sp-Ch] [bp-18h]@2
  const char *v6; // [sp-8h] [bp-14h]@2
  int v7; // [sp-4h] [bp-10h]@2
  char *v8; // [sp+4h] [bp-8h]@2
  int v9; // [sp+Bh] [bp-1h]@2

  v1 = _this;
  if ( *(_DWORD *)(_this + 1804) )
  {
    EnterCriticalSection(&pGame->class01_obj->cs4);
    SuspendThread(*(HANDLE *)(v1 + 4));
    set_acquire(*(_DWORD *)(v1 + 1804), 0);
    LeaveCriticalSection(&pGame->class01_obj->cs4);
  }
  else
  {
    v7 = 115;
    v6 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\KeyboardAsync.cpp";
    v8 = &v2;
    Game_sub_40E2C8(&v2, "Invalid DI_Keyboard, bailing out of suspend()", (int)&v9);
    sub_467834(&v8, v2, v3, v4, v5, v6, v7);
  }
}


//----- (0045B3B6) --------------------------------------------------------
void __thiscall CAsyncKeyboard_update_keyboard_data(int _this)
{
  int v1; // esi@1
  int v2; // eax@3
  signed int v3; // ecx@3
  int v4; // edx@6
  char v5; // [sp-18h] [bp-2Ch]@2
  const CHAR *v6; // [sp-14h] [bp-28h]@2
  int v7; // [sp-10h] [bp-24h]@2
  int v8; // [sp-Ch] [bp-20h]@2
  const char *v9; // [sp-8h] [bp-1Ch]@2
  int v10; // [sp-4h] [bp-18h]@2
  DWORD v11; // [sp+Ch] [bp-8h]@2
  int v12; // [sp+13h] [bp-1h]@2

  v1 = _this;
  if ( *(_DWORD *)(_this + 1804) )
  {
   EnterCriticalSection(&pGame->class01_obj->cs4);
    v11 = timeGetTime();
    memcpy((void *)(v1 + 9), (const void *)(*(_DWORD *)(v1 + 1804) + 29), 0x100u);
    update_data(*(_DWORD *)(v1 + 1804));
    memcpy((void *)(v1 + 265), (const void *)(*(_DWORD *)(v1 + 1804) + 29), 0x100u);
    v3 = 0;
    v2 = v1 + 780;
    do
    {
      if ( *(_BYTE *)(v1 + 265 + v3) & 0x80 )
      {
        if ( v11 - *(_DWORD *)v2 > 0xC8 )
        {
          v4 = v11;
          *(_BYTE *)(v3 + v1 + 521) |= 0x80u;
          *(_DWORD *)v2 = v4;
        }
      }
      ++v3;
      v2 += 4;
    }
    while ( v3 < 256 );
    LeaveCriticalSection(&pGame->class01_obj->cs4);
  }
  else
  {
    v10 = 169;
    v9 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\KeyboardAsync.cpp";
    v11 = (DWORD)&v5;
    Game_sub_40E2C8(&v5, "Invalid DI_Keyboard, bailing out of CAsyncKeyboard_update_keyboard_data()", (int)&v12);
    sub_467834(&v11, v5, v6, v7, v8, v9, v10);
  }
}

//----- (0045B18E) --------------------------------------------------------
char __thiscall CAsyncKeyboard_Initialize(LPVOID lpParameter)
{
  char result; // al@1
  void *v2; // esi@1

  v2 = lpParameter;
  sub_45B1B1((int)lpParameter);
  result = sub_45B229((DWORD)v2);
  if ( result )
    result = sub_45B260(v2) != 0;
  return result;
}


//----- (0045B2A7) --------------------------------------------------------
void __thiscall CAsyncKeyboard_Resume(int _this)
{
  int v1; // esi@1
  char v2; // [sp-18h] [bp-24h]@2
  const CHAR *v3; // [sp-14h] [bp-20h]@2
  int v4; // [sp-10h] [bp-1Ch]@2
  int v5; // [sp-Ch] [bp-18h]@2
  const char *v6; // [sp-8h] [bp-14h]@2
  int v7; // [sp-4h] [bp-10h]@2
  char *v8; // [sp+4h] [bp-8h]@2
  int v9; // [sp+Bh] [bp-1h]@2

  v1 = _this;
  if ( *(_DWORD *)(_this + 1804) )
  {
    EnterCriticalSection(&pGame->class01_obj->cs4);
    sub_45B1B1(v1);
    set_acquire(*(_DWORD *)(v1 + 1804), 1);
    ResumeThread(*(HANDLE *)(v1 + 4));
    LeaveCriticalSection(&pGame->class01_obj->cs4);
  }
  else
  {
    v7 = 97;
    v6 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\KeyboardAsync.cpp";
    v8 = &v2;
    Game_sub_40E2C8(&v2, "Invalid DI_Keyboard, bailing out of resume()", (int)&v9);
    sub_467834(&v8, v2, v3, v4, v5, v6, v7);
  }
}


//----- (00465FF0) --------------------------------------------------------
void __cdecl sub_465FF0_InitializeAsyncKeyboardAndSomething()
{
  //int v0; // eax@1
  int v1; // ecx@3
  int v2; // ecx@4
  char v3; // [sp+0h] [bp-24h]@1
  int v4; // [sp+10h] [bp-14h]@3
  char *v5; // [sp+14h] [bp-10h]@1
  int v6; // [sp+20h] [bp-4h]@3
 struct Win32Keyboard *pWin32Keyboard;

 /*
 pWin32Keyboard = pGame->Win32Keyboard_obj;
 v5 = &v3;
 if (pWin32Keyboard->dword_000004)
 {
    if ( !pAsyncKeyboard )
    {
      v6 = 0;
      compile_error();//v1 = (int)operator new(0x710u);
      v4 = v1;
      LOBYTE(v6) = 1;
      if ( v1 )
        v2 = CAsyncKeyboard_ctor(v1);
      else
        v2 = 0;
      LOBYTE(v6) = 0;
      pAsyncKeyboard = v2;
      if ( v2 )
        CAsyncKeyboard_Resume(v2);
    }
 }*/
}


//----- (0045B10A) --------------------------------------------------------
int __thiscall CAsyncKeyboard_ctor(int _this)
{
  int v1; // esi@1
  int v3; // [sp+4h] [bp-4h]@2

  v1 = _this;
  *(_DWORD *)(_this + 4) = 0;
  *(_BYTE *)(_this + 8) = 0;
  *(_DWORD *)_this = 5080760;
  if ( !CAsyncKeyboard_Initialize((LPVOID)_this) )
  {
    v3 = (int)"Could not initialize asynchronos keyboard object";
    _CxxThrowException((int)&v3, 5094804);
  }
  return v1;
}


//----- (00465F5A) --------------------------------------------------------
void __cdecl sub_465F5A_InitializeAsyncMouseAndSomething()
{
  int v0; // ecx@4
  int v1; // ecx@5
  char v2; // [sp+0h] [bp-24h]@1
  int v3; // [sp+10h] [bp-14h]@4
  char *v4; // [sp+14h] [bp-10h]@1
  int v5; // [sp+20h] [bp-4h]@4

  v4 = &v2;
 if (pAsyncMouse)
   return;

 if (pD3DRenderer)
 {
  if (pD3DRenderer->uAcquiredDirect3DDevice == 1)
  {
        v5 = 0;
        compile_error();//v0 = (int)operator new(0x88u);
        v3 = v0;
        LOBYTE(v5) = 1;
        if ( v0 )
          v1 = sub_46ACA9(v0, (int)pD3DRenderer->pdd4);
        else
          v1 = 0;
        LOBYTE(v5) = 0;
        pAsyncMouse = v1;
        if ( v1 )
          CAsyncMouse_sub_46B105((void *)v1);
  }
 }
}


//----- (0046B105) --------------------------------------------------------
void __thiscall CAsyncMouse_sub_46B105(void *_this)
{
  void *v1; // esi@1

  v1 = _this;
  EnterCriticalSection(&pGame->class01_obj->cs3);
  sub_46B0A9(v1);
  CAsyncMouse_ClipCursorToScreen();
  ResumeThread(*((HANDLE *)v1 + 4));
  *((_BYTE *)v1 + 88) = 0;
  LeaveCriticalSection(&pGame->class01_obj->cs3);
}


//----- (0045B57D) --------------------------------------------------------
char __thiscall CAsyncKeyboard_sub_45B57D(void *_this, int a2)
{
  char result; // al@2
  char v3; // [sp-18h] [bp-1Ch]@99
  const CHAR *v4; // [sp-14h] [bp-18h]@99
  int v5; // [sp-10h] [bp-14h]@99
  int v6; // [sp-Ch] [bp-10h]@99
  const char *v7; // [sp-8h] [bp-Ch]@99
  int v8; // [sp-4h] [bp-8h]@99
  void *v9; // [sp+0h] [bp-4h]@1
  char *v10; // [sp+Ch] [bp+8h]@99

  v9 = _this;
  switch ( a2 )
  {
    case 8:
      result = 14;
      break;
    case 9:
      result = 15;
      break;
    case 13:
      result = 28;
      break;
    case 16:
    case 161:
      result = 54;
      break;
    case 160:
      result = 42;
      break;
    case 17:
    case 163:
      result = -99;
      break;
    case 162:
      result = 29;
      break;
    case 18:
      result = -72;
      break;
    case 20:
      result = 58;
      break;
    case 21:
      result = 112;
      break;
    case 25:
      result = -108;
      break;
    case 27:
      result = 1;
      break;
    case 28:
      result = 121;
      break;
    case 29:
      result = 123;
      break;
    case 32:
      result = 57;
      break;
    case 33:
      result = -55;
      break;
    case 34:
      result = -47;
      break;
    case 35:
      result = -49;
      break;
    case 36:
      result = -57;
      break;
    case 37:
      result = -53;
      break;
    case 38:
      result = -56;
      break;
    case 39:
      result = -51;
      break;
    case 40:
      result = -48;
      break;
    case 42:
      result = -73;
      break;
    case 45:
      result = -46;
      break;
    case 46:
      result = -45;
      break;
    case 48:
      result = 11;
      break;
    case 49:
      result = 2;
      break;
    case 50:
      result = 3;
      break;
    case 51:
      result = 4;
      break;
    case 52:
      result = 5;
      break;
    case 53:
      result = 6;
      break;
    case 54:
      result = 7;
      break;
    case 55:
      result = 8;
      break;
    case 56:
      result = 9;
      break;
    case 57:
      result = 10;
      break;
    case 65:
      result = 30;
      break;
    case 66:
      result = 48;
      break;
    case 67:
      result = 46;
      break;
    case 68:
      result = 32;
      break;
    case 69:
      result = 18;
      break;
    case 70:
      result = 33;
      break;
    case 71:
      result = 34;
      break;
    case 72:
      result = 35;
      break;
    case 73:
      result = 23;
      break;
    case 74:
      result = 36;
      break;
    case 75:
      result = 37;
      break;
    case 76:
      result = 38;
      break;
    case 77:
      result = 50;
      break;
    case 78:
      result = 49;
      break;
    case 79:
      result = 24;
      break;
    case 80:
      result = 25;
      break;
    case 81:
      result = 16;
      break;
    case 82:
      result = 19;
      break;
    case 83:
      result = 31;
      break;
    case 84:
      result = 20;
      break;
    case 85:
      result = 22;
      break;
    case 86:
      result = 47;
      break;
    case 87:
      result = 17;
      break;
    case 88:
      result = 45;
      break;
    case 89:
      result = 21;
      break;
    case 90:
      result = 44;
      break;
    case 91:
      result = -37;
      break;
    case 92:
      result = -36;
      break;
    case 93:
      result = -35;
      break;
    case 96:
      result = 82;
      break;
    case 97:
      result = 79;
      break;
    case 98:
      result = 80;
      break;
    case 99:
      result = 81;
      break;
    case 100:
      result = 75;
      break;
    case 101:
      result = 76;
      break;
    case 102:
      result = 77;
      break;
    case 103:
      result = 71;
      break;
    case 104:
      result = 72;
      break;
    case 105:
      result = 73;
      break;
    case 106:
      result = 55;
      break;
    case 107:
      result = 78;
      break;
    case 109:
      result = 74;
      break;
    case 110:
      result = 83;
      break;
    case 111:
      result = -75;
      break;
    case 112:
      result = 59;
      break;
    case 113:
      result = 60;
      break;
    case 114:
      result = 61;
      break;
    case 115:
      result = 62;
      break;
    case 116:
      result = 63;
      break;
    case 117:
      result = 64;
      break;
    case 118:
      result = 65;
      break;
    case 119:
      result = 66;
      break;
    case 120:
      result = 67;
      break;
    case 121:
      result = 68;
      break;
    case 122:
      result = 87;
      break;
    case 123:
      result = 88;
      break;
    case 124:
      result = 100;
      break;
    case 125:
      result = 101;
      break;
    case 126:
      result = 102;
      break;
    case 144:
      result = 69;
      break;
    case 145:
      result = 70;
      break;
    default:
      v8 = 999;
      v7 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\KeyboardAsync.cpp";
      v10 = &v3;
      Game_sub_40E2C8(&v3, "Uknown key detected!", (int)((char *)&a2 + 3));
      sub_467834(&v9, v3, v4, v5, v6, v7, v8);
      goto LABEL_100;
    case 1:
    case 2:
    case 3:
    case 4:
    case 12:
    case 19:
    case 23:
    case 24:
    case 30:
    case 31:
    case 41:
    case 43:
    case 44:
    case 47:
    case 108:
    case 127:
    case 128:
    case 129:
    case 130:
    case 131:
    case 132:
    case 133:
    case 134:
    case 135:
LABEL_100:
      result = -1;
      break;
  }
  return result;
}

//----- (0046B342) --------------------------------------------------------
int __thiscall CAsyncMouse_sub_46B342(int _this, float a2, float a3)
{
  int result; // eax@1
  double v4; // ST00_8@1
  double v5; // ST00_8@1

  v4 = a2 + 6.755399441055744e15;
  *(_DWORD *)(_this + 40) = LODWORD(v4);
  v5 = a3 + 6.755399441055744e15;
  result = LODWORD(v5);
  *(_DWORD *)(_this + 44) = LODWORD(v5);
  return result;
}

//----- (0046B37C) --------------------------------------------------------
int __thiscall CAsyncMouse_update_mouse_data(int _this, int a2)
{
  int v2; // edi@1
  int result; // eax@2
  int v4; // eax@3
  int v5; // esi@3
  char v6; // [sp-18h] [bp-28h]@2
  const CHAR *v7; // [sp-14h] [bp-24h]@2
  int v8; // [sp-10h] [bp-20h]@2
  int v9; // [sp-Ch] [bp-1Ch]@2
  const char *v10; // [sp-8h] [bp-18h]@2
  char *v12; // [sp+8h] [bp-8h]@2
  int v13; // [sp+Fh] [bp-1h]@2

  v2 = _this;
  if ( *(_DWORD *)(_this + 132) )
  {
   EnterCriticalSection(&pGame->class01_obj->cs3);
    sub_43BB89(*(_DWORD *)(v2 + 132));
    v4 = *(_DWORD *)(v2 + 132);
    v5 = v4 + 32;
    sub_46B289(v2, v4 + 32, *(_DWORD *)(v4 + 40));
    LeaveCriticalSection(&pGame->class01_obj->cs3);
    result = a2;
    *(_DWORD *)a2 = *(_DWORD *)v5;
    *(_DWORD *)(a2 + 4) = *(_DWORD *)(v5 + 4);
  }
  else
  {
    v10 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\MouseAsync.cpp";
    v12 = &v6;
    Game_sub_40E2C8(&v6, "DI_Mouse pointer invalid bailing out from CAsyncMouse_update_mouse_data()", (int)&v13);
    sub_467834(&v12, v6, v7, v8, v9, v10, __LINE__);
    result = a2;
    *(_DWORD *)a2 = 0;
    *(_DWORD *)(a2 + 4) = 0;
  }
  return result;
}


//----- (0046AE6E) --------------------------------------------------------
char __thiscall CAsyncMouse_Initialize(LPVOID lpParameter)
{
  void *v1; // esi@1
  char result; // al@2

  v1 = lpParameter;
  if ( sub_46AF50(lpParameter) && sub_46B072((DWORD)v1) )
    result = sub_46B0A9(v1) != 0;
  else
    result = 0;
  return result;
}

//----- (0046AE97) --------------------------------------------------------
char __thiscall CAsyncMouse_sub_46AE97(void *_this, void *Source)
{
  void *v2; // esi@1
  int v3; // eax@1
  int v4; // eax@1
  char result; // al@3
  int v6; // [sp+8h] [bp-B0h]@1
  int v7; // [sp+58h] [bp-60h]@1
  cTexture cTexture_obj; // [sp+6Ch] [bp-4Ch]@1
  char v9; // [sp+B4h] [bp-4h]@1

  v2 = _this;
  EnterCriticalSection(&pGame->class01_obj->cs2);
  v3 = *((_DWORD *)v2 + 1);
  v6 = 100;
  v7 = 0;
  v4 = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD, signed int, int *))(*(_DWORD *)v3 + 20))(
         v3,
         0,
         0,
         0,
         1024,
         &v6);
  CheckHRESULT((void **)&v9, v4, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\MouseAsync.cpp", 0x81u, 0);
  
  cTexture_obj.cTexture_Zero();
  if (LODFile_Icons_LOD.LoadTextureFromLOD( &cTexture_obj, (char *)Source, 2) != -1 && sub_46B1EC((int)&struct_505898.Dest, *((_DWORD *)v2 + 1), 0) )
  {
    cTexture_Free(&cTexture_obj);
    LeaveCriticalSection(&pGame->class01_obj->cs2);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}


//----- (0043B9FF) --------------------------------------------------------
int __thiscall sub_43B9FF(int _this)
{
  int v1; // esi@1
  int v3; // eax@5
  signed int v4; // [sp-18h] [bp-24h]@3
  int v5; // [sp-14h] [bp-20h]@3
  int v6; // [sp-10h] [bp-1Ch]@3
  const char *v7; // [sp-Ch] [bp-18h]@3
  unsigned int v8; // [sp-8h] [bp-14h]@3
  int v9; // [sp-4h] [bp-10h]@3
  char v10; // [sp+8h] [bp-4h]@5

  v1 = _this;
  *(_DWORD *)(_this + 8) = 0;
  *(_BYTE *)(_this + 28) = 0;
  *(_DWORD *)(_this + 40) = 0;
  *(_DWORD *)_this = 5080584;
  if (dword_F79D70 != 4 )
  {
    v9 = 1;
    v8 = 30;
    v7 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputMouse.cpp";
    v6 = 0;
    v5 = _this + 4;
    v4 = 1280;
  }
  else
  {
    v9 = 1;
    v8 = 28;
    v7 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputMouse.cpp";
    v6 = 0;
    v5 = _this + 4;
    v4 = 768;
  }
  compile_error();//v3 = DirectInputCreateA(hInstance, v4, v5, v6);
  CheckHRESULT((void **)&v10, v3, v7, v8, v9);
  sub_43BACE(v1);
  sub_43BB18(v1);
  *(_DWORD *)(v1 + 32) = 0;
  *(_DWORD *)(v1 + 36) = 0;
  return v1;
}

//----- (0043B76D) --------------------------------------------------------
int __thiscall sub_43B76D(int _this)
{
  int v1; // esi@1
  int v3; // eax@5
  signed int v4; // [sp-18h] [bp-20h]@3
  int v5; // [sp-14h] [bp-1Ch]@3
  int v6; // [sp-10h] [bp-18h]@3
  const char *v7; // [sp-Ch] [bp-14h]@3
  unsigned int v8; // [sp-8h] [bp-10h]@3
  int v9; // [sp-4h] [bp-Ch]@3
  char v10; // [sp+4h] [bp-4h]@5

  v1 = _this;
  *(_DWORD *)(_this + 8) = 0;
  *(_BYTE *)(_this + 28) = 0;
  *(_DWORD *)_this = 5080580;
  if (dword_F79D70 != 4 )
  {
    v9 = 1;
    v8 = 28;
    v7 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputKeyboard.cpp";
    v6 = 0;
    v5 = _this + 4;
    v4 = 1280;
  }
  else
  {
    v9 = 1;
    v8 = 26;
    v7 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\DirectInputKeyboard.cpp";
    v6 = 0;
    v5 = _this + 4;
    v4 = 768;
  }
  compile_error();//v3 = DirectInputCreateA(hInstance, v4, v5, v6);
  CheckHRESULT((void **)&v10, v3, v7, v8, v9);
  sub_43B831(v1);
  sub_43B87B(v1);
  return v1;
}


//----- (0046B736) --------------------------------------------------------
void __thiscall CAsyncMouse_sub_46B736(void *_this, char a2)
{
  void *v2; // esi@1

  v2 = _this;
  sub_46B76F();
  sub_46B879();
  if ( a2 )
  {
    sub_46BCAB((int)((char *)v2 + 104));
    sub_46BCAB((int)((char *)v2 + 116));
  }
  if ( *((_BYTE *)v2 + 102) )
  {
    sub_4356FF();
    *((_BYTE *)v2 + 102) = 0;
  }
}


//----- (0046BB0A) --------------------------------------------------------
void __thiscall CAsyncMouse_sub_46BB0A(int _this)
{
  int v1; // esi@1
  int v2; // eax@1
  int v3; // edx@1
  int v4; // ecx@1
  int v5; // edx@1
  int v6; // eax@1
  char v7; // zf@1
  int v8; // ST08_4@8
  int v9; // [sp+8h] [bp-74h]@8
  int v10; // [sp+Ch] [bp-70h]@8
  int v11; // [sp+6Ch] [bp-10h]@1
  int v12; // [sp+70h] [bp-Ch]@1
  int v13; // [sp+74h] [bp-8h]@1
  int v14; // [sp+78h] [bp-4h]@1

  v1 = _this;
  v2 = *(_DWORD *)(_this + 68) - *(_DWORD *)(_this + 40);
  v3 = *(_DWORD *)(_this + 56);
  v4 = *(_DWORD *)(_this + 72) - *(_DWORD *)(_this + 44);
  v11 = v2;
  v5 = v2 + v3;
  v6 = *(_DWORD *)(v1 + 60);
  v12 = v4;
  v7 = *(_BYTE *)(v1 + 90) == 0;
  v13 = v5;
  v14 = v4 + v6;
  if ( v7 || *(_BYTE *)(v1 + 128) & 1 )
  {
    if ( *(_BYTE *)(v1 + 88) )
      (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD, int, signed int))(pD3DRenderer->pdds4_FrontBuffer + 28))(
        (int)pD3DRenderer->pdds4_FrontBuffer,
        *(_DWORD *)(v1 + 32),
        *(_DWORD *)(v1 + 36),
        *(_DWORD *)(v1 + 8),
        v1 + 48,
        16);
    (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, int, int *, signed int))(**(_DWORD **)(v1 + 8) + 28))(
      *(_DWORD *)(v1 + 8),
      0,
      0,
      (int)pD3DRenderer->pdds4_FrontBuffer,
      &v11,
      16);
  }
  if ( *(_BYTE *)(v1 + 90) )
  {
    if ( !(*(_BYTE *)(v1 + 128) & 1) )
    {
      v8 = *(_DWORD *)(v1 + 4);
      v9 = 100;
      v10 = 8;
      (*(void (__stdcall **)(int, int *, int, int, signed int, int *))(pD3DRenderer->pdds4_FrontBuffer + 20))(
        (int)pD3DRenderer->pdds4_FrontBuffer,
        &v11,
        v8,
        v1 + 48,
        16812032,
        &v9);
    }
  }
  LeaveCriticalSection(&pGame->class01_obj->cs2);
}


//----- (0046BBD0) --------------------------------------------------------
void *__cdecl CAsyncMouse_ClipCursorToScreen()
{
  void *result; // eax@1
  char v1; // [sp-18h] [bp-30h]@2
  int v2; // [sp-14h] [bp-2Ch]@2
  int v3; // [sp-10h] [bp-28h]@2
  int v4; // [sp-Ch] [bp-24h]@2
  const char *v5; // [sp-8h] [bp-20h]@2
  int v6; // [sp-4h] [bp-1Ch]@2
  RECT Rect; // [sp+0h] [bp-18h]@1
  char *v8; // [sp+10h] [bp-8h]@2
  int v9; // [sp+17h] [bp-1h]@2

  SetWindowPos(pAppWindow->GetAPIHandle(), (HWND)((unsigned int)(HWND_MESSAGE)|0x2), 320, 240, 640, 480, 0);
  Rect.left = 325;
  Rect.top = 245;
  Rect.right = 326;
  Rect.bottom = 246;
  result = (void *)ClipCursor(&Rect);
  if ( !result )
  {
    v6 = 827;
    v5 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\MouseAsync.cpp";
    v8 = &v1;
    Game_sub_40E2C8(&v1, "Could not clip cursor to screen!", (int)&v9);
    result = sub_466D09(&v8, *(int *)&v1, v2, v3, v4, v5, v6);
  }
  return result;
}

//----- (0046BAEC) --------------------------------------------------------
void __thiscall CAsyncMouse_sub_46BAEC(void *_this)
{
  void *v1; // esi@1

  v1 = _this;
  EnterCriticalSection(&pGame->class01_obj->cs2);
  *((_BYTE *)v1 + 88) = 0;
}

//----- (00409E3D) --------------------------------------------------------
void __thiscall CAsyncMouse_sub_409E3D(int _this, char a2)
{
  if ( *(_BYTE *)(_this + 128) & 1 )
    *(_BYTE *)(_this + 103) = 1;
  else
    *(_BYTE *)(_this + 103) = 0;
  if ( a2 )
    *(_DWORD *)(_this + 128) |= 1u;
  else
    *(_DWORD *)(_this + 128) &= 0xFFFFFFFEu;
}

//----- (0046B944) --------------------------------------------------------
int __thiscall CAsyncMouse_sub_46B944(int _this)
{
  int v2; // esi@1

  v2 = _this;
  sub_46BCAB(_this + 104);
  return sub_46BCAB(v2 + 116);
}

//----- (0046B76F) --------------------------------------------------------
void __cdecl sub_46B76F()
{
  int v0; // ebx@1
  int v1; // edi@1
  int v2; // eax@1
  int v3; // eax@2
  signed int *v4; // esi@2
  signed int v5; // ST08_4@7
  signed int v6; // ST04_4@7
  float v7; // ST00_4@7
  signed int v8; // ST08_4@9
  signed int v9; // ST04_4@9
  float v10; // ST00_4@9

  EnterCriticalSection(&pGame->class01_obj->cs1);
  v0 = pAsyncMouse + 108;
  v2 = *(_DWORD *)(pAsyncMouse + 108);
  v1 = *(_DWORD *)v2;
  if ( *(_DWORD *)v2 != v2 )
  {
    do
    {
      v3 = *(_DWORD *)(v1 + 20);
      v4 = (signed int *)(v1 + 12);
      if ( v3 & 1 )
      {
        Game_Pick(pGame, 512.0, *v4, *(_DWORD *)(v1 + 16), 0, (int)&stru_F93E6C, (int)&dword_F93E58);
        if ( sub_466CA0() == MENU_CREATEPARTY )
          sub_41CD4F_MaybeOnlyUI_OnKeyDown(VK_SELECT);
        OnMouseLeftClick((void *)(v1 + 12));
      }
      else
      {
        if ( v3 & 2 )
        {
          v5 = *(_DWORD *)(v1 + 16);
          v6 = *v4;
          v7 = sub_43643E();
          Game_Pick(pGame, v7, v6, v5, 0, (int)&dword_F93E30, (int)&dword_F93E44);
          sub_416D62_ShowPopupWindow_MonsterRecord_ItemInfo_etc(v1 + 12);
        }
        else
        {
          if ( v3 & 4 )
          {
            v8 = *(_DWORD *)(v1 + 16);
            v9 = *v4;
            v10 = sub_43643E();
            Game_Pick(pGame, v10, v9, v8, 1, (int)&stru_F93E6C, (int)&dword_F93E44);
          }
        }
      }
      v1 = *(_DWORD *)v1;
    }
    while ( v1 != *(_DWORD *)v0 );
  }
  LeaveCriticalSection(&pGame->class01_obj->cs1);
}

//----- (0046B879) --------------------------------------------------------
void __cdecl sub_46B879()
{
  int v0; // ebx@1
  int v1; // edi@1
  int v2; // eax@1
  int v3; // eax@2
  signed int *v4; // esi@2
  signed int v5; // ST08_4@5
  signed int v6; // ST04_4@5
  float v7; // ST00_4@5

  EnterCriticalSection(&pGame->class01_obj->cs1);
  v0 = pAsyncMouse + 120;
  v2 = *(_DWORD *)(pAsyncMouse + 120);
  v1 = *(_DWORD *)v2;
  if ( *(_DWORD *)v2 != v2 )
  {
    do
    {
      v3 = *(_DWORD *)(v1 + 20);
      v4 = (signed int *)(v1 + 12);
      if ( v3 & 1 )
      {
        Game_Pick(pGame, 512.0, *v4, *(_DWORD *)(v1 + 16), 0, (int)&stru_F93E6C, (int)&dword_F93E58);
        sub_4178C4();
      }
      else
      {
        if ( v3 & 2 )
        {
          v5 = *(_DWORD *)(v1 + 16);
          v6 = *v4;
          v7 = sub_43643E();
          Game_Pick(pGame, v7, v6, v5, 0, (int)&dword_F93E30, (int)&dword_F93E58);
          sub_4178E1();
        }
        else
        {
          if ( v3 & 4 )
            compile_error();//nullsub_1(v1 + 12);
        }
      }
      v1 = *(_DWORD *)v1;
    }
    while ( v1 != *(_DWORD *)v0 );
  }
  LeaveCriticalSection(&pGame->class01_obj->cs1);
}

//----- (0046B1DD) --------------------------------------------------------
char __thiscall CAsyncMouse_sub_46B1DD(int _this)
{
  *(_BYTE *)(_this + 20) = 1;
  Sleep(0x76u);
  return 1;
}


//----- (0046B14F) --------------------------------------------------------
void __thiscall CAsyncMouse_suspend(int _this)
{
  int v1; // esi@1
  int v2; // eax@3
  char v3; // [sp-18h] [bp-24h]@2
  const CHAR *v4; // [sp-14h] [bp-20h]@2
  int v5; // [sp-10h] [bp-1Ch]@2
  int v6; // [sp-Ch] [bp-18h]@2
  const char *v7; // [sp-8h] [bp-14h]@2
  int v8; // [sp-4h] [bp-10h]@2
  char *v9; // [sp+4h] [bp-8h]@2
  int v10; // [sp+Bh] [bp-1h]@2

  v1 = _this;
  if ( *(_DWORD *)(_this + 132) )
  {
    v2 = (int)pGame->pVis;
    if ( v2 )
      *(_DWORD *)(v2 + 8200) = 0;
    EnterCriticalSection(&pGame->class01_obj->cs3);
    SuspendThread(*(HANDLE *)(v1 + 16));
    sub_46B0ED(v1);
    LeaveCriticalSection(&pGame->class01_obj->cs3);
  }
  else
  {
    v8 = 233;
    v7 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\MouseAsync.cpp";
    v9 = &v3;
    Game_sub_40E2C8(&v3, "DI_Mouse pointer invalid; bailing out from suspend()", (int)&v10);
    sub_467834(&v9, v3, v4, v5, v6, v7, v8);
  }
}

//----- (0045B4EC) --------------------------------------------------------
char __thiscall CAsyncKeyboard_sub_45B4EC(void *_this, unsigned __int8 a2)
{
  void *v3; // esi@1
  char v4; // bl@1

  v3 = _this;
  EnterCriticalSection(&pGame->class01_obj->cs4);
  v4 = *((_BYTE *)v3 + a2 + 265) >> 7;
  LeaveCriticalSection(&pGame->class01_obj->cs4);
  return v4;
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
  if (pAsyncMouse)
    CAsyncMouse_suspend(pAsyncMouse);
  if (pGame)
  {
   runtime_warning(async input);
    /*v11 = (int)pGame->Win32Keyboard_obj;
    if ( v11 )
    {
      if (*(_BYTE *)(v11 + 4))
      {
        if (pAsyncKeyboard)
          CAsyncKeyboard_suspend(pAsyncKeyboard);
      }
    }*/
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
  Game_stru0_sub_40E2F6((Game_stru0 *)&v20, 1);
  v12 = lpCaption;
  if ( !lpCaption )
    v12 = (char *)byte_4D8410 + 736;
  v14 = *(const CHAR **)(a1 + 4);
  if ( !v14 )
    v14 = (char *)byte_4D8410 + 736;
  MessageBoxA(pAppWindow->GetAPIHandle(), v14, v12, uType);
  if (pGame)
  {
   runtime_warning(async input);
    /*v15 = (int)pGame->Win32Keyboard_obj;
    if ( v15 )
    {
      if ( *(_BYTE *)(v15 + 4) )
      {
        if (pAsyncKeyboard)
          CAsyncKeyboard_Resume(pAsyncKeyboard);
      }
    }*/
  }
  if (pAsyncMouse)
    CAsyncMouse_sub_46B105((void *)pAsyncMouse);
  LOBYTE(v22) = 0;
  Game_stru0_sub_40E2F6((Game_stru0 *)&a2, 1);
  v22 = -1;
  Game_stru0_sub_40E2F6((Game_stru0 *)&a7, 1);
}


//----- (00465C2C) --------------------------------------------------------
void __cdecl CAsyncMouse_Clear()
{
 runtime_warning(async input);
 /*
  if (pAsyncMouse)
  {
    CAsyncMouse_suspend(pAsyncMouse);
    if (pAsyncMouse)
      (*(void (__stdcall **)(_DWORD))*pAsyncMouse)(1);
  }
  pAsyncMouse = 0;*/
}
/*
//----- (0045B019) --------------------------------------------------------
void __thiscall Win32Keyboard_BeginReadingInput(int _this)
{
  if ( *(_BYTE *)(_this + 4) )
    AsyncInput_sub_45B1FD_EnterCS();
}*/


//----- (0045B1FD) --------------------------------------------------------
void __cdecl AsyncInput_sub_45B1FD_EnterCS()
{
  EnterCriticalSection(&pGame->class01_obj->cs4);
}

//----- (0045B213) --------------------------------------------------------
void __cdecl AsyncInput_sub_45B1FD_LeaveCS()
{
  LeaveCriticalSection(&pGame->class01_obj->cs4);
}

//----- (00465C53) --------------------------------------------------------
void __cdecl CAsyncKeyboard_Clear()
{
 runtime_warning(async input);
  /*if (*(_BYTE *)(pGame->Win32Keyboard_obj + 4))
  {
    if (pAsyncKeyboard)
    {
      CAsyncKeyboard_suspend(pAsyncKeyboard);
      if (pAsyncKeyboard)
        (**(void (__stdcall ***)(_DWORD))pAsyncKeyboard)(1);
    }
    pAsyncKeyboard = 0;
  }*/
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
    Game_stru0_sub_40E2F6((Game_stru0 *)&v15, 0);
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
    Game_stru0_sub_40E2F6((Game_stru0 *)&v15, 1);
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

  compile_error();
  return 0;
  /*
  v23 = -1;
  v22 = 5091904;
  compile_error();//v21 = unknown_libname_59;
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
  compile_error();//v11 = unknown_libname_59;
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

  compile_error();
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

  compile_error();
  return 0;
  /*
  v14 = -1;
  v13 = 5091928;
  compile_error();//v12 = unknown_libname_59;
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

  compile_error();
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





//----- (004A952D) --------------------------------------------------------
/*void __stdcall PlayMovie(unsigned int uVideoID, char a2)
{
  int v2; // edx@5
  const char *v3; // ecx@5

  char  CShow[256];
  int v5; // [sp-14h] [bp-20h]@4
  int v6; // [sp-10h] [bp-1Ch]@4
  int v7; // [sp-Ch] [bp-18h]@4
  char v10; // [sp+0h] [bp-Ch]@14
  char v11; // [sp+4h] [bp-8h]@4
  int v12; // [sp+Bh] [bp-1h]@14

 if (pAsyncMouse)
   CAsyncMouse_suspend(pAsyncMouse);

 switch (uVideoID)
 {
    case 0:
      Game_sub_40E2C8(CShow, "No movie", (int)((char *)&a1 + 3));
      sub_467834(&v11, (char)CShow, (const CHAR *)v5, v6, v7, __FILE__, __LINE__);
      break;

    case 1: MoviePlayerLoop("3dologo", 0, 0, 1);
    break;

    case 2: MoviePlayerLoop("new world logo", 0, 1, 1);
    break;

    case 3: MoviePlayerLoop("jvc", 0, 1, 1);
    break;

    case 4: MoviePlayerLoop("Intro Post", 0, 1, 1);
    break;

    case 5: MoviePlayerLoop("Intro", 0, 1, 1);
    break;

    case 6: MoviePlayerLoop("losegame", 2, 1, 1);
    break;

    case 7: MoviePlayerLoop("end_seq1", 20, 1, 1);
    break;

    default:
      Game_sub_40E2C8(CShow, "Invalid movie requested in CShow::Run()", (int)&v12);
      sub_466D09(&v10, (int)CShow, v5, v6, v7, __FILE__, __LINE__);
      break;
  }

 if (a2)
 {
  if (pAsyncMouse)
    CAsyncMouse_sub_46B105((void *)pAsyncMouse);
 }
}*/

//----- (004BF8F6) --------------------------------------------------------
/*void PlayFirstActMovie()
{
 pVideoPlayer->dword_00006C = 0;
 pVideoPlayer->dword_000040 = 0;
 PlayMovie(4, 1);
}*/


//----- (004BE70E) --------------------------------------------------------
/*void __fastcall MoviePlayerLoop(const char pMovieName, int a2, int a3, int a4)
{
  int v4; // ebp@1
 MSG msg;

 v4 = a2;
 if (dword_6BE364 & 0x44)  //no movies
   return;

 if (a2 == 2)
   v4 = 0;

 ShowCursor(0);
 pVideoPlayer->OpenMovie(pMovieName, 0, a3);
 pVideoPlayer->dword_000058 = 1;
 pVideoPlayer->dword_000044 = v4;

 if (pD3DRenderer->pRenderD3D3)
   Render_ClearTarget(pD3DRenderer, 0);
 else
 {
  pD3DRenderer->BeginScene();
  Render_ClearTarget(pD3DRenderer, 0);
  pD3DRenderer->EndScene();
 }
 dword_4E28F8_PartyCantJumpIfTrue = 16;


 if (pVideoPlayer->dword_00009C == 2)
 {
  if (pVideoPlayer->pBinkMovie)
  {
   pVideoPlayer->BinkDoFrame(pVideoPlayer->pWindow->GetAPIHandle(), v4, a3);
   while (pVideoPlayer->pBinkMovie)
   {
    if (pVideoPlayer->dword_00006C)
      break;

    while (PeekMessageA(&msg, 0, 0, 0, PM_REMOVE))
    {
     if (msg.message == WM_QUIT)
       Game_DeinitializeAndTerminate(0);
     if (msg.message == WM_PAINT)
       break;

     TranslateMessage(&msg);
     DispatchMessageA(&msg);
    }

    sub_435748_PlayerCreationUI_MessageProc();
    if (!pVideoPlayer->pBinkMovie)
      break;

    if (!BinkWait(pVideoPlayer->pBinkMovie))
    {
     if (!pVideoPlayer->dword_00006C)
       pVideoPlayer->BinkDoFrame(pVideoPlayer->pWindow->GetAPIHandle(), v4, a3);
    }
   }
  }
  if (pVideoPlayer->dword_00006C == 1)
   Sleep(1000);
 }

 else if (pVideoPlayer->dword_00009C == 1)
 {
  if (pVideoPlayer->pSmackerMovie)
  {
   pVideoPlayer->SmackDrawFrame(pVideoPlayer->pWindow->GetAPIHandle(), v4, a3);

   while (pVideoPlayer->pSmackerMovie)
   {
    if (pVideoPlayer->dword_00006C)
      break;

    while (PeekMessageA(&msg, 0, 0, 0, PM_REMOVE))
    {
     if (msg.message == WM_QUIT)
       Game_DeinitializeAndTerminate(0);
     else if (msg.message == WM_PAINT)
       break;

     TranslateMessage(&msg);
     DispatchMessageA(&msg);
    }
    sub_435748_PlayerCreationUI_MessageProc();

    if (!pVideoPlayer->pSmackerMovie)
      break;
    if (!SmackWait(pVideoPlayer->pSmackerMovie))
    {
     if (!pVideoPlayer->dword_00006C)
       pVideoPlayer->SmackDrawFrame(pVideoPlayer->pWindow->GetAPIHandle(), v4, a3);
    }
   }
  }
 }

 if (a4 == 1)
   dword_4E28F8_PartyCantJumpIfTrue = 0;

 pVideoPlayer->dword_000058 = 0;
 ShowCursor(1);

 if (dword_4E28F8_PartyCantJumpIfTrue == 16)
   dword_4E28F8_PartyCantJumpIfTrue = 0;
}*/

/*
//----- (00459C68) --------------------------------------------------------
void KeyboardController_InitalizeKey(struct UserInput *_this, unsigned int uSlot, unsigned int uVKey, bool bActive)
{
 _this->pVirtualKeyCodesMapping[uSlot] = uVKey;
 _this->unk_000084[uSlot] = bActive;
}
*/

/*

//----- (00464BEF) --------------------------------------------------------
int __fastcall ReadRegistryKeyMapping(const CHAR *a1, BYTE *a2, DWORD Count, const char *Source)
{
  LSTATUS (__stdcall *v4)(HKEY); // esi@1
  int result; // eax@7
  DWORD Type; // [sp+Ch] [bp-24h]@5
  LPCSTR lpValueName; // [sp+10h] [bp-20h]@1
  DWORD cbData; // [sp+14h] [bp-1Ch]@1
  LPBYTE Dest; // [sp+18h] [bp-18h]@1
  DWORD dwDisposition; // [sp+1Ch] [bp-14h]@2
  HKEY phkResult; // [sp+20h] [bp-10h]@1
  HKEY hKey; // [sp+24h] [bp-Ch]@1
  HKEY v13; // [sp+28h] [bp-8h]@1
  HKEY v14; // [sp+2Ch] [bp-4h]@1

  cbData = Count;
  Dest = a2;
  lpValueName = a1;
  v14 = 0;
  v13 = 0;
  hKey = 0;
  phkResult = 0;
  v4 = RegCloseKey;
  if ( RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE", 0, 0x2001Fu, &hKey)
    || RegCreateKeyExA(hKey, "New World Computing", 0, "", 0, 983103u, 0, &phkResult, &dwDisposition)
    || RegCreateKeyExA(phkResult, "Might and Magic VII", 0, "", 0, 0xF003Fu, 0, &v13, &dwDisposition)
    || RegCreateKeyExA(v13, "1.0", 0, "", 0, 0xF003Fu, 0, &v14, &dwDisposition) )
    goto LABEL_7;
  if ( RegQueryValueExA(v14, lpValueName, 0, &Type, Dest, &cbData) )
  {
    RegCloseKey(v14);
    v14 = 0;
LABEL_7:
    result = (int)strncpy((char *)Dest, Source, Count);
    goto LABEL_8;
  }
  v4 = RegCloseKey;
  RegCloseKey(v14);
  v14 = 0;
  RegCloseKey(v13);
  v13 = 0;
  RegCloseKey(phkResult);
  phkResult = 0;
  result = RegCloseKey(hKey);
  hKey = 0;
LABEL_8:
  if ( v14 )
    result = v4(v14);
  if ( v13 )
    result = v4(v13);
  if ( hKey )
    result = v4(hKey);
  if ( phkResult )
    result = v4(phkResult);
  return result;
}*/


/*

/*
//----- (00488F5C) ------.text:0048A961 --------------------------------------------------
bool LoadLevel(OutdoorLocation *_this, const char *Source, int File, signed int a4, int a5)
{
  if ( Source )
  {
    class51_sub_47CF9C(_this);
    LODFile_Bitmaps_LOD.sub_46454B();
    LODFile_Sprites_LOD.sub_4645DC();
    SpriteFrameTable_fn3(pSpriteFrameTable);
    LODFile_Icons_LOD.sub_46454B();
    sub_46080D_Clear_LevelLod();
    sub_460706_Load_LevelLod(Source);
    if ( !_this->Load(Source, File, a4, a5) )
    {
      MessageBoxA(0, "Error!", "Couldn't Load Map!", 0);
      class51_sub_47CDE2((int)_this);
    }
    dword_6BE030 = _this->array_0004F0[5];
    dword_6BE040 = _this->array_0004F0[6];
    dword_6BE044 = _this->array_0004F0[7];
    if (!_strcmpi(Source, "out15.odm"))
      sub_464851();
    dword_6BE134 = _this->array_0000A0[0];
    return true;
  }
  else return false;
}*/


/*
//----- (00486A28) --------------------------------------------------------
void AllocateSoftwareDrawBuffers(void *_this)
{
  if ( !_this || !pSpansBuf )
  {
    ReleaseSoftwareDrawBuffers();

    //pSpansBuf = (Span *)mem_mng.AllocatedNamedBuffer( pSpansBuf, 12500 * sizeof(struct Span), "SPANS");
    pSpansBuf = NamedMemAlloc(Span, 12500, "SPANS");
    memset(pSpansBuf, 0, 12500 * sizeof(struct Span));

    //pEdgesBuf = (Edge *)mem_mng.AllocatedNamedBuffer( pEdgesBuf, 6000 * sizeof(struct Edge), "EDGES");
    pEdgesBuf = NamedMemAlloc(Edge, 6000, "EDGES");
    memset(pEdgesBuf, 0, 6000 * sizeof(struct Edge));

    //pSurfsBuf = (Surf *)mem_mng.AllocatedNamedBuffer( pSurfsBuf, 2000 * sizeof(struct Surf), "SURFS");
    pSurfsBuf = NamedMemAlloc(Surf, 2000, "SURFS");
    memset(pSurfsBuf, 0, 2000 * sizeof(struct Surf));

    //pNewEdgesBuf = (Edge *)mem_mng.AllocatedNamedBuffer( pNewEdgesBuf, 480 * sizeof(struct Edge), "NEWEDGES");
    pNewEdgesBuf = NamedMemAlloc(Edge, 480, "NEWEDGES");
    memset(pNewEdgesBuf, 0, 480 * sizeof(struct Edge));
  }
}

//----- (00486AFC) --------------------------------------------------------
void __cdecl ReleaseSoftwareDrawBuffers()
{
 MemFree(pSpansBuf);
 MemFree(pEdgesBuf);
 MemFree(pSurfsBuf);
 MemFree(pNewEdgesBuf);
 
  pSpansBuf = 0;
  pEdgesBuf = 0;
  pSurfsBuf = 0;
  pNewEdgesBuf = 0;
}


int ReleaseSoftwareDrawBuffers_proxy()
{
  ReleaseSoftwareDrawBuffers();
  return 0;
}


//----- (0048901B) --------------------------------------------------------
signed int __thiscall class51_sub_48901B_clear_and_ReleaseSoftwareDrawBuffers(OutdoorLocation *_this)
{
 _this->Clear();
 ReleaseSoftwareDrawBuffers_proxy();
  return 1;
}
*/

/*
//----- (MM7.exe::004AB818) --------------------------------------------------------
int AudioPlayer_LoadSoundHeaders(struct AudioPlayer *_this)
{
 DWORD w;

 strcpy((char *)TmpBuf, "Sounds\\Audio.snd");
 _this->hSoundsSource = CreateFileA("Sounds\\Audio.snd", GENERIC_READ, 1, 0, 3, 0x8000080, 0);
 if (_this->hSoundsSource == INVALID_HANDLE_VALUE)
 {
  wsprintfA((char *)pStringBuffer, "Can't open file - %s", (char *)TmpBuf);
  return MessageBoxA(0, (char *)pStringBuffer, "Sound File Error", 0);
 }

 ReadFile(_this->hSoundsSource, &_this->uNumSounds, 4, &w, 0);

 //_this->pSoundHeaders = (AudioPlayer_sound_header_struct *)mem_mng.AllocatedNamedBuffer(NULL, _this->uNumSounds * sizeof(struct AudioPlayer_sound_header_struct) + 2, 0);
 _this->pSoundHeaders = NamedMemAlloc(AudioPlayer_sound_header_struct, _this->uNumSounds, "AudioPlayer audio headers");

 return ReadFile(_this->hSoundsSource, _this->pSoundHeaders, _this->uNumSounds * sizeof(struct AudioPlayer_sound_header_struct), &w, 0);
}*/


/*//----- (00487DBE) --------------------------------------------------------
void __cdecl sub_487DBE_LooksLikeResetNewEdgesBuf()
{
 int i;

 for (i = 0; i < 480; ++i)
 {
  pNewEdgesBuf[i].pNext = &defaultEdge;
  ptr_80CA10[i] = 0;
 }

 runtime_warning(wtf is _this shit? o_O);
 for (i = 0; i < 2000; ++i)
   *((_WORD *)pSurfsBuf + 17) = 0;
}

//----- (00487DA9) --------------------------------------------------------
void __cdecl sub_487DA9_ResetSomeStruct8ArrayFlags()
{
 int i;

 for (i = 0; i < 2000; ++i)
   array_77EC08[i].byte_000108 = 0;
}




//----- (00479332) --------------------------------------------------------
signed int __cdecl sub_479332_SoftwareRender_OnDraw_NoRedraw()
{
  signed int result; // eax@1
  unsigned int v1; // edi@1
  _UNKNOWN *v2; // esi@2
  char v3; // cl@3
  double v4; // st7@4
  int v5; // eax@6
  float v6; // ST34_4@6
  double v7; // ST24_8@6
  int v8; // eax@11
  int v9; // eax@13
  int v10; // eax@14
  double v11; // st7@17
  float v12; // ST34_4@19
  double v13; // ST1C_8@19
  float v14; // [sp+4h] [bp-34h]@1
  float v15; // [sp+8h] [bp-30h]@1
  float v16; // [sp+Ch] [bp-2Ch]@1
 int i;

  v14 = (double)pClass51_global->dword_000D30 * 0.0000152587890625;
  result = 0;
  v1 = (int)&array_77EC08[pStruct9_global->dword_00002C];
  v15 = (double)pClass51_global->dword_000D34 * 0.0000152587890625;
  v16 = (double)pClass51_global->dword_000D38 * 0.0000152587890625;
  if ( pStruct9_global->dword_00002C > 0)
  {
   i = 0;
   v2 = (char *)&array_77EC08[0].ptr_000048;
    while ( 1 )
    {
      v3 = *((_BYTE *)v2 + 5);
      if ( v3 == 5 )
        break;
      if ( v3 == 1 )
      {
       v9 = (unsigned __int16)pClass51_global->pTerrainNormalIndices[((*((_DWORD *)v2 - 9) >> 15) & 1)
                                         + 2 * (*((_BYTE *)v2 + 9) + (*((_BYTE *)v2 + 8) << 7))];
       if ( v9 > pClass51_global->uNumTerrainNormals - 1 )
          v10 = 0;
        else
         v10 = (int)pClass51_global->pTerrainNormals + v9;
        if ( v10 )
        {
          v11 = -(v16 * *(float *)(v10 + 8) + v15 * *(float *)(v10 + 4) + v14 * *(float *)v10);
          if ( v11 < 0.0 )
            v11 = 0.0;
          v12 = v11 * 31.0;
          v13 = v12 + 6.755399441055744e15;
          *((_BYTE *)v2 + 4) = 31 - LOBYTE(v13);
        }
        else
        {
          *((_BYTE *)v2 + 4) = 0;
        }
        if ( *((_BYTE *)v2 + 4) < 0 )
          *((_BYTE *)v2 + 4) = 0;
        goto LABEL_23;
      }
LABEL_24:
      //v2 = (char *)v2 + 268;
      //if ( (unsigned int)((char *)v2 - 84) >= v1 )
      //  return result;
      if ((int)&array_77EC08[i++].array_0000B4[19] >= v1)
         return result;
     v2 = (char *)&array_77EC08[i].ptr_000048;
    }

    v4 = ((__int64)(*array_77EC08[i].ptr_000048)[0] * -pClass51_global->dword_000D30 / 65536 +
         (__int64)(*array_77EC08[i].ptr_000048)[1] * -pClass51_global->dword_000D34 / 65536 +
         (__int64)(*array_77EC08[i].ptr_000048)[2] * -pClass51_global->dword_000D38 / 65536) / 65536.0;
    if ( v4 < 0.0 )
      v4 = 0.0;
    v6 = v4 * 31.0;
    v7 = v6 + 6.755399441055744e15;
    v5 = (int)((char *)v2 + 4);
    *((_BYTE *)v2 + 4) = 31 - LOBYTE(v7);
    if ( (char)(31 - LOBYTE(v7)) < 0 )
      *(_BYTE *)v5 = 0;
    if ( *(_BYTE *)v5 > 31 )
      *(_BYTE *)v5 = 31;
    if ( *(_BYTE *)((char *)array_77EC08[i].ptr_000048 + 29) & 0x40 )
    {
      v8 = TextureFrameTable_GetFrame(pTextureFrameTable, *((_WORD *)v2 - 4), cClock1.dword_000024);
      *((_DWORD *)v2 - 6) = v8 != -1 ? 72 * v8 + 7278780 : 0;
    }
LABEL_23:
    result = 1;
    goto LABEL_24;
  }
  return result;
}
*/


/*
//----- (004ABFDB) --------------------------------------------------------
void LoadLevel_InitializeMusic(const char *pLevelFilename)
{
  signed int v0; // eax@1

  v0 = CMapStats_FindLocation(pMapStats, pLevelFilename);
  if (v0)
  {
   pAudioPlayer->SetMusicVolume(64.0f * pSoundVolumeLevels[uMusicVolimeMultiplier]);
   pAudioPlayer->PlayMusicTrack(pMapStats->pMapInfos[v0].uRedbookTrackNum);
  }
}
*/