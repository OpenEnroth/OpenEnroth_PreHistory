#pragma once

#include "..\Window.h"


//GUICursor
struct GUICursor
{
 int dword_000000; // when in Game, mouse over player portrait, highlighted player id is placed here
                   // monster id here as well
 int dword_000004;
 int dword_000008;
 int dword_00000C;
 int dword_000010;
 int dword_000014[4];
 unsigned int uCursorTextureID; // dword @ 000024  cursor texture id
 int dword_000028;   // cursor texture id

 //HWND            hWnd;        // dword @ 00002C
 OSWindow       *pWindow;     // dword @ 00002C

 unsigned char  *ptr_000030;  // cursor bitmap sysmem copy
 int             dword_000034;
 unsigned char  *ptr_000038;  // cursor bitmap sysmem copy

#ifdef OLD_CODE
 unsigned short *ptr_00003C; // cursor bitmap sysmem copy (16bit) - old
#else
 unsigned int   *ptr_00003C;  // cursor bitmap sysmem copy (32bit) - new
#endif

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
struct GUICursor *GUICursor_ctor(GUICursor *_this, struct class01 *class01_obj);
//int __thiscall sub_46A080(int _this, int a2);
int GUICursor_fn1(GUICursor *_this, int a2);
//int __thiscall sub_469C39(int _this, int a2);
POINT *GUICursor_GetMousePos(GUICursor *_this, POINT *ptOut);
//void __thiscall sub_469C65(int _this, int a2)
void GUICursor_sub_469C65(GUICursor *_this, OSWindow *pWindow);
//void __thiscall sub_469903(int _this, const char *Source);
void GUICursor_SetCursorBitmap(GUICursor *_this, const char *pSource);
//int __thiscall GUICursor_sub_469BA3(int _this);
int GUICursor_sub_469BA3(GUICursor *_this);
//void __thiscall sub_4698A6(void *_this)
void GUICursor_ResetDefaultCursorAfterItemDragging(GUICursor *_this);
//void sub_46A08A(int _this, int a2, int a3)
void GUICursor_OnMouseLeftButton(GUICursor *_this, int x, int y);
//int __thiscall sub_469860(int _this, int a2, int a3);
void GUICursor_GetMouseClickPos(GUICursor *_this, int *pX, int *pY);
//int __thiscall sub_469E3B(int _this)
int GUICursor_sub_469E3B(GUICursor *_this);
//void __thiscall sub_469EA4(int _this);
void GUICursor_sub_469EA4_LooksLikeDrawPickedItem(GUICursor *_this);
//void sub_469BE6(int this);
void GUICursor_sub_469BE6(GUICursor *_this);
//void *__thiscall 469C0D(int this);
void *GUICursor_sub_469C0D(GUICursor *_this);
//void __thiscall sub_469CC2(int this);
void GUICursor_sub_469CC2(GUICursor *_this);
//void __thiscall sub_469CCD(int this);
void GUICursor_sub_469CCD(GUICursor *_this);
//void __thiscall sub_469E1C(int this);
void GUICursor_sub_469E1C(GUICursor *_this);
//void __thiscall sub_4698F6(int _this);
void GUICursor_sub_4698F6(GUICursor *_this);
//LONG __thiscall sub_469AE4(int _this);
LONG GUICursor_sub_469AE4(GUICursor *_this);

void __stdcall SetCursorBitmapFromItemID(int a1);
