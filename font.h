
#pragma once

#include "defs.h"
#include "gui.h"



struct Font
{
 unsigned char   uFirstChar;           // byte  @ 000000
 unsigned char   uLastChar;            // byte  @ 000001
 char            byte_000002[2];
 unsigned char   byte_000004;
 unsigned char   uFontHeight;          // byte  @ 000005
 char            byte_000006[2];
 int             dword_000008;
 unsigned short *pFontPalette;         // dword @ 00000C
 int             dword_000010[4];
 int             dword_000020[256][3];
 int             array_000C20[256];
 char            unk_001020;
};


int __fastcall Font_sub_44C59D(Font *pFont, const char *pString, GUIWindow *a3, char a4, int a5);

//int __cdecl sub_49750E();
void __cdecl DeleteFontCChar();

struct Font *__cdecl LoadFont(const char *pFontFile, const char *pFontPalette);


int __fastcall AlignText_Center(int a1, const char *pString, struct Font *pFont);
unsigned char *__fastcall FitTextInAWindow(const char *pString, struct Font *pFont, struct GUIWindow *pParent, unsigned int uX, int a5);
void FontDrawText(struct GUIWindow *_this, struct Font *pFont, unsigned int uX, unsigned int uY, const char *pString, 
	               unsigned int uTextMainColor, signed int a8, unsigned int uTextShadowColor);

struct Font *__cdecl sub_44C448(const char *pFontName, const char *pFontPalette);
int __fastcall sub_44C51E(struct Font *pFont, const char *pString);
