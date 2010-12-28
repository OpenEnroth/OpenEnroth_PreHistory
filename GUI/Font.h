#pragma once

#include "..\defs.h"

namespace GUI
{
 class Window;
};

struct LetterMetrics
{
 unsigned int uLeftSpacing;
 unsigned int uWidth;
 unsigned int uRightSpacing;
};

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
 LetterMetrics   pMetrics[256];	       // struct[256] @ 000020
 int             array_000C20[256];
 char            unk_001020;
};




char *RemoveQuote(char *Str);  
unsigned int  GUIFont_GetLineWidth(Font *pFont, const unsigned char *pString);
bool GUIFont_IsCharacterValid(Font *pFont, unsigned char c);	 //bool __fastcall sub_44C4DE(unsigned char a1, unsigned char *a2);

int GUIFont_CalculateTextHeight(Font *pFont, const unsigned char *pString, class GUI::Window *pParent, int uXOff, int a5);
int __fastcall Font_sub_44C6C2(struct Font *a1, const unsigned char *a2, class GUI::Window *a3, char a4, int a5);
//int __cdecl sub_49750E();
void __cdecl DeleteFontCChar();
void __fastcall sub_44D0B5(Font *a1, int a2, int a3, int a4, const char *Str, int a6);
int  sub_44C62E(struct Font *pFont1, struct Font *pFont2, const char *pString, class GUI::Window *a4, int a5, bool bParagraph);
struct Font *__cdecl LoadFont(const char *pFontFile, const char *pFontPalette);
// char *__fastcall sub_44C933(const char *a1, int a2, char a3, int a4, int a5, int a6);
unsigned char *sub_44C933(const char *pString, char *pOutString, struct Font *pFont1, struct Font *pFont2, class GUI::Window *a4, int uX, bool bParagraph);
void sub_44D1E7_DrawTextLine(Font *_this, unsigned int uDefaultColor, unsigned int uOutX, unsigned int uOutY, const char *pString, int a6);

int  AlignText_Center(int a1, const char *pString, struct Font *pFont);
unsigned char *FitTextInAWindow(const unsigned char *pString,
                                unsigned char *pOutString,
                                struct Font *pFont, GUI::Window *pParent, unsigned int uX, bool a5);
void FontDrawText(class GUI::Window *_this, struct Font *pFont, unsigned int uX, unsigned int uY, const char *pString, 
	               unsigned int uTextMainColor, signed int a8, unsigned int uTextShadowColor);

struct Font *__cdecl sub_44C448(const char *pFontName, const char *pFontPalette);

int  GUIWindow_sub_44CB4F(class GUI::Window *a1, Font *a2, signed int a3, int a4, int a5, const char *Str1, signed int Source, int a8);

__int16 __fastcall sub_40F845(int a1, int a2, int a3, int a4, int a5, __int16 a6, int a7);

void sub_44D2FD(Font *a1, Font *a2, int Str, int a4, int a5, int a6, unsigned __int16 a7, unsigned __int16 a8, const char *a9, int a10, int a11);
