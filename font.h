
#pragma once

#include "defs.h"
#include "gui.h"


struct FontWidth
	{
	int preWidth;
	int letterW;
	int postWidth;
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
 struct FontWidth  fw_table[256];	  //dword_000020
 int             array_000C20[256];
 char            unk_001020;
};

char *RemoveQuote(char *Str);  
int  GetStringWidth(struct Font *pFont, const char *pString);
void  InitializeGameText();
bool inline test_char(char c, Font *pFontData);	 //bool __fastcall sub_44C4DE(unsigned char a1, unsigned char *a2);

int  CalculateTextHeght(struct Font *pFontData, const char *pString, GUIWindow *parentW, int uXOff, int a5);
int __fastcall Font_sub_44C6C2(struct Font *a1, const char *a2, struct GUIWindow *a3, char a4, int a5);
//int __cdecl sub_49750E();
void __cdecl DeleteFontCChar();
void __fastcall sub_44D0B5(Font *a1, int a2, int a3, int a4, const char *Str, int a6);
int  sub_44C62E(struct Font *pFont1, struct Font *pFont2, const char *pString, struct GUIWindow *a4, int a5, bool bParagraph);
struct Font *__cdecl LoadFont(const char *pFontFile, const char *pFontPalette);
// char *__fastcall sub_44C933(const char *a1, int a2, char a3, int a4, int a5, int a6);
char *sub_44C933(const char *pString, struct Font *pFont1, struct Font *pFont2, struct GUIWindow *a4, int uX, bool bParagraph);
void  sub_44D1E7(Font *pFontData, int a2, int a3, int a4, const char *pString, int a6);

int  AlignText_Center(int a1, const char *pString, struct Font *pFont);
char *FitTextInAWindow(const char *pString, struct Font *pFont, struct GUIWindow *pParent, unsigned int uX, bool a5);
void FontDrawText(struct GUIWindow *_this, struct Font *pFont, unsigned int uX, unsigned int uY, const char *pString, 
	               unsigned int uTextMainColor, signed int a8, unsigned int uTextShadowColor);

struct Font *__cdecl sub_44C448(const char *pFontName, const char *pFontPalette);

int __fastcall GUIWindow_sub_44CB4F(int a1, int a2, signed int a3, int a4, __int16 a5, const char *Str1, signed int Source, int a8);

__int16 __fastcall sub_40F845(int a1, int a2, int a3, int a4, int a5, __int16 a6, int a7);

void sub_44D2FD(Font *a1, Font *a2, int Str, int a4, int a5, int a6, unsigned __int16 a7, unsigned __int16 a8, const char *a9, int a10, int a11);
char *__fastcall GUIWindow_sub_44D406(struct GUIWindow *a1, struct Font *pFont, int a3, int a4, unsigned __int16 a5, const char *pString, int a7);