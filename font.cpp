#include "font.h"
#include "defs.h"
#include "localization_defs.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "RenderD3D3.h"

#include "data.h"

#include "FrameTables.h"
#include "_audio.h"
#include "_video.h"
 #include "_lod.h"





//----- (0044C59D) --------------------------------------------------------
int __fastcall Font_sub_44C59D(Font *pFontData, const char *pString, GUIWindow *a3, char a4, int a5)
{
  const char *v5; // ebx@1
  signed int v8; // ebx@3
  int v9; // esi@3
  size_t v10; // eax@3
  unsigned __int8 v11; // cl@4
  unsigned __int8 *v13; // [sp+14h] [bp+Ch]@3
 int i;

 if (!pString)
   return 0;

 v5 = pString;
 v9 = ((unsigned char *)(pFontData))[5] - 3;
 v13 = FitTextInAWindow(pString, pFontData, a3, a4, 0);
 v10 = strlen(pString);
 v8 = 0;

 for (i = 0; i < v10; ++i)
 {
  if (sub_44C4DE(*v13, (unsigned char *)pFontData))
  {
   v11 = *v13;
   if (v11 == 9)
     goto LABEL_8;

   switch (v11)
   {
    case 0xAu:
      v9 = v9 + *(_BYTE *)((int)pFontData + 5) - 3;
    break;

    case 0xCu:
      v13 += 5;
      v8 += 5;
    break;

    case 0xDu:
LABEL_8:
      if (a5 != 1)
      {
       v13 += 3;
       v8 += 3;
      }
    break;
   }
  }
  ++v8;
  ++v13;
 }

 return v9;
}



//----- (0044C448) --------------------------------------------------------
struct Font *__cdecl LoadFont(const char *pFontFile, const char *pFontPalette)
{
  int v5; // eax@3
 struct Font *pFont;

 pFont = (Font *)LODFile_Icons_LOD.LODFile_LoadRaw( pFontFile, 0);

 if (pFontPalette)
 {
  v5 = LODFile_Icons_LOD.LODFile_LoadTexture( pFontPalette, 2);
  if (v5 == -1)
  {
   wsprintfA((char *)TmpBuf, "Unable to open %s", pFontPalette);
   erroneous_printf((char *)TmpBuf);
  }

  pFont->pFontPalette = LODFile_Icons_LOD.aLODHeaders[v5].pPalette;
 }

 pFont->dword_000008 = 1;
 return pFont;
}


//----- (0049750E) --------------------------------------------------------
void __cdecl DeleteFontCChar()
{
  mem_mng.DeleteBuffer( (void *)pFontCChar);
  pFontCChar = 0;
}




//----- (0044C768) --------------------------------------------------------
unsigned char *__fastcall FitTextInAWindow(const char *pString, struct Font *pFont, struct GUIWindow *pParent, unsigned int uX, int a5)
{
  const char *v5; // edi@1
  unsigned char *v6; // esi@1
  int v8; // eax@3
  int v9; // edi@3
  int *v12; // ecx@10
  int v16; // edx@15
  int v17; // ecx@15
  int v18; // esi@15
  int v19; // ebx@16
  int v20; // edi@16
  unsigned __int8 v24; // dl@17
  int v27; // edi@39
  int v28; // eax@42
  char v29; // [sp-18h] [bp-40h]@2
  int v30; // [sp-14h] [bp-3Ch]@2
  int v31; // [sp-10h] [bp-38h]@2
  int v32; // [sp-Ch] [bp-34h]@2
  const char *v35; // [sp+Ch] [bp-1Ch]@1
  char Dest[3+256+array_size_unknown];
  char v37; // [sp+13h] [bp-15h]@42
  size_t v38; // [sp+14h] [bp-14h]@3
  int v39; // [sp+18h] [bp-10h]@3
  int v40; // [sp+1Ch] [bp-Ch]@1
  int v41; // [sp+20h] [bp-8h]@3
  int v42; // [sp+24h] [bp-4h]@3
 unsigned char c;

 v5 = pString;
 v35 = pString;
 v6 = (unsigned char *)pFont;
 v40 = (int)pFont;
 if (!pString)
 {
   *(_DWORD *)&uX = (int)&v29;
   Game_sub_40E2C8(&v29, "Invalid string passed !", (int)(&uX + 3));
   sub_466D09(&pParent, *(int *)&v29, v30, v31, v32, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Font.cpp", 445);
   return 0;
 }

 strcpy((char *)byte_5C45B0, pString);
 v8 = uX;
 v9 = 0;
 v41 = 0;
 v39 = uX;
 v42 = 0;

 v38 = strlen(pString);
 if (!v38)
   return byte_5C45B0;

 while (true)
 {
  c = byte_5C45B0[v9];
  if ((c < v6[0] || c > v6[1]) && c != '\f' && c != '\r' && c != '\n' && c != '\t')
    goto LABEL_34;

  v12 = pFont->dword_000020[c];
  if (c == '\t')
  {
   strncpy(Dest, (char *)&byte_5C45B0[v9 + 1], 3);
   v28 = atoi(Dest);
   v37 = 0;
   v8 = uX + v28;
   v27 = v9 + 3;
   v39 = v8;
   v42 = v27;
   goto LABEL_34;
  }
  else if (c == '\n')
    break;
  else if (c == '\f')
  {
   v27 = v9 + 5;
   v42 = v27;
   goto LABEL_34;
  }
  else if (c != '\r')
  {
   if (c != ' ')
   {
    v17 = v12[0];
    v16 = v12[1];
    v18 = v12[2];

    if ((unsigned int)(v8 + v18 + v17 + v16) < pParent->uFrameWidth)
    {
     if ( v42 > v41 )
       v8 += v17;
     v8 += v16;
     if (v42 < (signed int)v38)
       v8 += v18;
     v6 = (unsigned char *)v40;
    }
    else
    {
     v19 = v41;
     v8 = v39;
     v6 = (unsigned char *)v40;
     byte_5C45B0[v41] = '\n';
     v20 = v19;

     //compile_error;//v23 = __SETO__(v41, v42);
     //v21 = v41 == v42;
     //v22 = v41 - v42 < 0;
     //if ( (unsigned __int8)(v22 ^ v23) | v21 )
     if (v41 <= v42)
     {
      do
      {
       v24 = byte_5C45B0[v20];
       if (v24 >= v6[0] && v24 <= v6[1] || v24 == '\f' || v24 == '\r' || v24 == '\n' || v24 ==  '\t')
       {
        if ( v20 > v19 )
          v8 += *(_DWORD *)(v6 + 12 * v24 + 32);
        v8 += *(_DWORD *)(v6 + 4 * (3 * v24 + 9));
        if ( v20 < v42 )
          v8 += *(_DWORD *)(v6 + 12 * v24 + 40);
       }
       ++v20;
      }
      while ( v20 <= v42 );
     }
    }
    goto LABEL_34;
   }
   v8 += *(_DWORD *)(v12 + 4);
   goto LABEL_41;
  }
  if (!a5)
    return (unsigned char *)v35;

LABEL_34:
  v9 = v42 + 1;
  v42++;
  //compile_error;//v26 = __SETO__(v42, v38);
  //v25 = (signed int)(v42 - v38) < 0;
  if (v42 >= v38)//if ( !(v25 ^ v26) )
    return byte_5C45B0;
 }
 v8 = v39;

LABEL_41:
 v41 = v9;
 goto LABEL_34;
}


//----- (0044CE08) --------------------------------------------------------
void FontDrawText(struct GUIWindow *_this, struct Font *pFont, unsigned int uX, unsigned int uY, const char *pString, unsigned int uTextMainColor, signed int a8, unsigned int uTextShadowColor)
{
  int v9; // ebx@1
  int v10; // edi@1
  int v12; // edx@9
  int v15; // eax@25
  int v16; // ecx@25
  int v17; // eax@27
  int v18; // edi@32
  int v19; // esi@38
  unsigned __int8 v20; // sf@39
  unsigned __int8 v21; // of@39
  char v23; // [sp-18h] [bp-50h]@2
  int v24; // [sp-14h] [bp-4Ch]@2
  int v25; // [sp-10h] [bp-48h]@2
  int v26; // [sp-Ch] [bp-44h]@2
  char Dest[8]; // [sp+Ch] [bp-2Ch]@32
  char v30; // [sp+Fh] [bp-29h]@32
  char v31; // [sp+11h] [bp-27h]@34
  char *v32; // [sp+20h] [bp-18h]@25
  int v33; // [sp+24h] [bp-14h]@25
  int v34; // [sp+28h] [bp-10h]@1
  size_t v35; // [sp+2Ch] [bp-Ch]@4
  char *v37; // [sp+34h] [bp-4h]@7
  int v38; // [sp+4Ch] [bp+14h]@11
 unsigned char c;
 unsigned int uOutX,
              uOutY;

  v34 = 0;
  v10 = (int)_this;
  v9 = (int)pFont;

  if (!strcmp(pString, "null"))
    return;

    v35 = strlen(pString);

    if ( !uX )
      uX = 12;
    if ( a8 )
    {
      v37 = (char *)pString;
    }
    else
    {
      v37 = (char *)FitTextInAWindow(pString, pFont, _this, uX, 0);
    }
    uOutX = uX + _this->uFrameX;
    uOutY = uY + _this->uFrameY;
    v12 = 0;

  if (!a8 || uOutY + pFont->uFontHeight <= a8)
  {
   v38 = 0;
   if ((signed int)v35 > 0)
      {
        do
        {
          c = v37[v12];
          if (c >= pFont->uFirstChar && c <= pFont->uLastChar
            || c == '\f' || c == '\r' || c == '\t' || c == '\n')
          {
            switch ( c )
            {
              case 9u: // number (3 digit always) after \t denotes tab amount (in pixels);  example:  "\t004skips 4 whitespaces before _this string"
                memset(&Dest,0, sizeof (Dest));
                strncpy(Dest, &v37[v12 + 1], 3);
                v30 = 0;
                v38 += 3;
                v34 = atoi(Dest);
                v19 = atoi(Dest);
                uOutX = uX + _this->uFrameX + v19;
                break;
              case 0xAu:
                c = pFont->uFontHeight;
                uY = uY + pFont->uFontHeight - 3;
                uOutY = uY + _this->uFrameY;
                uOutX = uX + v34 + _this->uFrameX;
                if ( a8 )
                  goto LABEL_36;
                break;
              case 0xCu:
                memset(Dest,0, sizeof (Dest));
                strncpy(Dest, &v37[v12 + 1], 6);
                v31 = 0;
                sscanf(Dest,"%x",&uTextMainColor);
                if(!uTextMainColor)
                 uTextMainColor = 0xFFFFFF;
                uTextMainColor|=0xFF000000;
                v38 += 6;
                break;
              case 0xDu:
                memset(Dest,0, sizeof (Dest));
                strncpy(Dest, &v37[v12 + 1], 3u);
                v30 = 0;
                v38 += 3;
                v18 = atoi(Dest);
                c = sub_44C51E((Font *)v9, &v37[v38]);
                uOutX = *(_DWORD *)(v10 + 16) - (_DWORD)c - v18;
                uOutY = uY + *(_DWORD *)(v10 + 4);
                if ( a8 )
                {
                 c = pFont->uFontHeight;
LABEL_36:
                  c = pFont->uFontHeight + uOutY - 3;
                  if ( (signed int)c > a8 )
                    return;
                  break;
                }
                break;
              default:
                if (c == 34 )
                {
                  if ( v37[v12 + 1] == 34 )
                  {
                    ++v12;
                    v38 = v12;
                  }
                }
                v32 = &v37[v12];
                v15 = (unsigned __int8)v37[v12];
                v16 = pFont->dword_000020[v15][1];
                v33 = pFont->dword_000020[v15][2];
                if ( v12 > 0 )
                  uOutX += pFont->dword_000020[v15][0];
                v17 = pFont->array_000C20[v15] + (int)&pFont->unk_001020;

                Render_DrawText(pD3DRenderer, uOutX, uOutY, (unsigned char *)v17,
                    v16,
                    pFont->uFontHeight, pFont->pFontPalette,
                    uTextMainColor,
                    uTextShadowColor);
                uOutX += pFont->dword_000020[v15][1];
                if ( v38 < (signed int)v35)
                {
                  uOutX += pFont->dword_000020[v15][2];
                }
                break;
            }
          }
          v12 = v38 + 1;
          //v21 = __SETO__(v38 + 1, v35);
          //v20 = (signed int)(v38++ + 1 - v35) < 0;
        }
        while ( ++v38 < v35);
      }
    }
}

//----- (0044C6C2) --------------------------------------------------------
int __fastcall Font_sub_44C6C2(struct Font *a1, const char *a2, struct GUIWindow *a3, char a4, int a5)
{
  int v5; // edi@1
  const char *v6; // esi@1
  unsigned __int8 *v8; // ebx@3
  signed int v9; // esi@3
  size_t v10; // eax@3
  int v11; // edx@4
  unsigned __int8 v12; // cl@4
  int v13; // [sp+Ch] [bp-4h]@1
  size_t v14; // [sp+1Ch] [bp+Ch]@3

  v6 = a2;
  v5 = 0;
  v13 = (int)a1;
  if ( !a2 )
    return 0;
  v8 = (unsigned __int8 *)FitTextInAWindow(a2, (Font *)a1, a3, a4, 0);
  v10 = strlen(v6);
  v9 = 0;
  v14 = v10;
  if ( (signed int)v10 > 0 )
  {
    while ( !sub_44C4DE(*v8, (unsigned char *)v13) )
    {
LABEL_11:
      ++v9;
      ++v8;
      if ( v9 >= (signed int)v14 )
        return (int)v8;
    }
    if ( v12 != 9 )
    {
      if ( v12 == 10 )
      {
        v5 = v5 + *(_BYTE *)(v11 + 5) - 3;
        if ( v5 >= a5 * a3->uFrameHeight)
          return (int)(v8 + 1);
        goto LABEL_10;
      }
      if ( v12 == 12 )
      {
        v8 += 5;
        v9 += 5;
LABEL_10:
        if ( v5 >= a5 * a3->uFrameHeight)
          return (int)v8;
        goto LABEL_11;
      }
      if ( v12 != 13 )
        goto LABEL_10;
    }
    v8 += 3;
    v9 += 3;
    goto LABEL_10;
  }
  return (int)v8;
}

//----- (0044C502) --------------------------------------------------------
int __fastcall AlignText_Center(int a1, const char *pString, struct Font *pFont)
{
  int v3; // esi@1
  int result; // eax@2

  v3 = (a1 - sub_44C51E(pFont, pString)) / 2;
  if ( v3 >= 0 )
    result = v3;
  else
    result = 0;
  return result;
}

//----- (0044C51E) --------------------------------------------------------
int __fastcall sub_44C51E(struct Font *_this, const char *pString)
{
  signed int i; // ebx@3
  size_t v5; // ebp@3
  int v6; // esi@3
  const char *v8; // [sp+0h] [bp-4h]@1
 unsigned char c;

 if (!pString)
   return 0;

 v8 = pString;
 v5 = strlen(pString);
 v6 = 0;
 for ( i = 0; i < v5; ++i )
 {
  c = pString[i];
  if (sub_44C4DE(c, (unsigned char *)_this))
  {
   if (c == '\n' || c == '\r')
     return v6;
   if (c != '\f')
   {
    if (i > 0)
      v6 += _this->dword_000020[c][0];
    v6 += _this->dword_000020[c][1];
    if (i < v5)
      v6 += _this->dword_000020[c][2];
   }
   else
     i += 5;
  }
 }
 return v6;
}


//----- (0044C933) --------------------------------------------------------
char *__fastcall sub_44C933(const char *a1, int a2, char a3, int a4, int a5, int a6)
{
  const char *v6; // esi@1
  int v8; // eax@3
  int v9; // ebx@3
  size_t v10; // edi@3
  int v11; // esi@3
  size_t v12; // eax@3
  unsigned __int8 v13; // cl@5
  int v14; // edx@11
  int v15; // ecx@11
  int v16; // edx@12
  int v17; // edx@13
  int v18; // edx@14
  int v19; // edx@15
  int v20; // edx@17
  int v21; // ecx@17
  int v22; // edi@17
  int v23; // edi@18
  char v24; // zf@18
  int v25; // eax@19
  int v26; // ecx@19
  unsigned __int8 v27; // dl@24
  int v28; // eax@46
  char v29; // [sp-18h] [bp-48h]@2
  int v30; // [sp-14h] [bp-44h]@2
  int v31; // [sp-10h] [bp-40h]@2
  int v32; // [sp-Ch] [bp-3Ch]@2
  const char *v33; // [sp-8h] [bp-38h]@2
  int v34; // [sp-4h] [bp-34h]@2
  const char *v35; // [sp+Ch] [bp-24h]@1
  char Dest; // [sp+10h] [bp-20h]@46
  char v37; // [sp+13h] [bp-1Dh]@46
  int v38; // [sp+14h] [bp-1Ch]@1
  int v39; // [sp+18h] [bp-18h]@3
  int v40; // [sp+1Ch] [bp-14h]@3
  int v41; // [sp+20h] [bp-10h]@4
  int v42; // [sp+24h] [bp-Ch]@3
  int v43; // [sp+28h] [bp-8h]@3
  int i; // [sp+2Ch] [bp-4h]@17
  char *v45; // [sp+38h] [bp+8h]@2

  v6 = a1;
  v38 = a2;
  v35 = a1;
  if ( !a1 )
  {
    v34 = 558;
    v33 = "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Font.cpp";
    v45 = &v29;
    Game_sub_40E2C8(&v29, "Invalid string passed !", (int)(&a3 + 3));
    sub_466D09(&a5, *(int *)&v29, v30, v31, v32, v33, v34);
    return 0;
  }
  v12 = strlen(a1);
  v10 = v12;
  v42 = v12;
  strcpy((char *)byte_5C45B0, v6);
  v8 = a5;
  v11 = v38;
  v9 = 0;
  v43 = 0;
  v40 = a5;
  v39 = 0;
  if ( (signed int)v10 > 0 )
  {
    v41 = v10 - 1;
    do
    {
      v13 = byte_5C45B0[v9];
      if ( v13 >= *(_BYTE *)v11 && v13 <= *(_BYTE *)(v11 + 1) || v13 == 12 || v13 == 13 || v13 == 9 || v13 == 10 )
      {
        v14 = v13 - 9;
        v15 = v11 + 12 * v13 + 32;
        if ( v14 )
        {
          v16 = v14 - 1;
          if ( v16 )
          {
            v17 = v16 - 2;
            if ( v17 )
            {
              v18 = v17 - 1;
              if ( v18 )
              {
                v19 = v18 - 19;
                if ( v19 )
                {
                  if ( v19 == 63 )
                  {
                    v11 = a3;
                  }
                  else
                  {
                    v22 = *(_DWORD *)(v15 + 8);
                    v20 = *(_DWORD *)(v15 + 4);
                    v21 = *(_DWORD *)v15;
                    i = v22;
                    if ( (unsigned int)(v8 + v22 + v21 + v20) < *(_DWORD *)(a4 + 8) )
                    {
                      v9 = v39;
                      if ( v39 > v43 )
                        v8 += v21;
                      v8 += v20;
                      if ( v39 < v42 )
                        v8 += i;
                    }
                    else
                    {
                      v23 = v43;
                      v24 = v11 == a3;
                      *(byte_5C45B0 + v43) = 10;
                      if ( v24 )
                      {
                        v26 = v41;
                        v25 = v23 + 1;
                        while ( v26 >= v25 )
                        {
                         byte_5C45B0[v26] = stru_5C3610.byte_000F9C[v26];
                          --v26;
                        }
                        ++v42;
                        ++v41;
                        byte_5C45B0[1 + v23++] = 95;
                        v43 = v25;
                      }
                      v9 = v39;
                      v8 = v40;
                      for ( i = v23; i <= v39; ++i )
                      {
                        v27 = byte_5C45B0[i];
                        if ( v27 >= *(_BYTE *)v11 && v27 <= *(_BYTE *)(v11 + 1)
                          || v27 == 12
                          || v27 == 13
                          || v27 == 9
                          || v27 == 10 )
                        {
                          if ( i > v23 )
                            v8 += *(_DWORD *)(v11 + 12 * v27 + 32);
                          v8 += *(_DWORD *)(v11 + 4 * (3 * v27 + 9));
                          if ( i < v39 )
                            v8 += *(_DWORD *)(v11 + 12 * v27 + 40);
                        }
                      }
                    }
                  }
                }
                else
                {
                  v8 += *(_DWORD *)(v15 + 4);
                  v43 = v9;
                }
              }
              else
              {
                if ( !a6 )
                  return (char *)v35;
              }
            }
            else
            {
              v9 += 5;
            }
          }
          else
          {
            v8 = v40;
            v11 = v38;
            v43 = v9;
          }
        }
        else
        {
          strncpy(&Dest, (char *)&byte_5C45B0[v9 + 1], 3u);
          v37 = 0;
          v28 = atoi(&Dest);
          v8 = a5 + v28;
          v9 += 3;
          v40 = v8;
        }
      }
      ++v9;
      v39 = v9;
    }
    while ( v9 < v42 );
  }
  return (char *)byte_5C45B0;
}