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

static char temp_string[2048];	// byte_5C45B0

 //----- (0044C4DE) --------.text:0044D4A0 ------------------------------------------------
bool inline test_char(char c, Font *pFontData)
{
return 	((c >= pFontData->uFirstChar)&&(c <=pFontData->uLastChar)||( c == '\f' || c == '\r' || c == '\n' || c == '\t'));   
}



//----- (0044C59D) --------------.text:0044D568------------------------------------------
int  CalculateTextHeght(Font *pFontData, const char *pString, GUIWindow *parentW, int uXOff, int a5)
{

  int uAllHeght; // esi@3
  unsigned int uStringLen; // eax@3
  char c; // cl@4
  char *test_string; // [sp+14h] [bp+Ch]@3
 int i;

 if (!pString)
   return 0;

 
 uAllHeght = pFontData->uFontHeight - 3;
 test_string = FitTextInAWindow(pString, pFontData, parentW, uXOff, 0);
 uStringLen = strlen(pString);


 for (i = 0; i < uStringLen; ++i)
 {
  c = test_string[i];
  if (test_char(c, pFontData))
  {
   switch (c)
   {
   case '\n':	//Line Feed 0A 10:
      uAllHeght+= pFontData->uFontHeight - 3;
    break;

   case '\f':  //Form Feed, page eject  0C 12 
      i += 6;		  //was 5
    break;
   case '\t':	// Horizontal tab 09
   case '\r':   //Carriage Return 0D 13

      if (a5 != 1)
      {
       i += 3;
      }
    break;
   }
  }
 }

 return uAllHeght;
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




//----- (0044C768) -----------------.text:0044D751---------------------------------------
char *FitTextInAWindow(const char *pString, struct Font *pFont, struct GUIWindow *pParent, unsigned int uX, bool a5)
{
  
unsigned char c;
unsigned int uInStrLen,i;
char digits[4];
int possible_trasition_point;
int string_pixel_Width;
int start_pixel_offset;

if (!pString)
	{
	// *(_DWORD *)&uX = (int)&v29;
	// Game_sub_40E2C8(&v29, "Invalid string passed !", (int)(&uX + 3));
	// sub_466D09(&pParent, *(int *)&v29, v30, v31, v32, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Font.cpp", 445);
	return 0;
	}
uInStrLen = strlen(pString);
strcpy(&temp_string[0], pString);
if (uInStrLen==0)
	return &temp_string[0];
i=0;
start_pixel_offset=string_pixel_Width=uX;
possible_trasition_point=0;
for(i=0; i<uInStrLen; i++) 
	{
	c=temp_string[i];
	if ((c>= pFont->uFirstChar) &&(c <=pFont->uLastChar)||( c == '\f' || c == '\r' || c == '\n' || c == '\t'))
		{
		switch (c)
			{
		case '\t':	// Horizontal tab 09
			{
			strncpy(digits,&temp_string[i+1],3);
			digits[3]=0;
			string_pixel_Width= atoi(digits)+uX;
			i+=3;
			break;
			}
		case  '\n':	//Line Feed 0A 10
			{
			string_pixel_Width=start_pixel_offset;
			possible_trasition_point=i;
			break;
			}
		case  '\f':   //Form Feed, page eject  0C 12
			{
			i+=6;  //5 was
			break;
			}
		case  '\r':   //Carriage Return 0D 13
			{
			if (!a5)
				return (char*)pString;
			break;
			}
		case ' ' :
			{
			string_pixel_Width+=pFont->fw_table[c].letterW;
			possible_trasition_point=i;
			break;
			}
		default:

			if ((string_pixel_Width+pFont->fw_table[c].letterW+ pFont->fw_table[c].preWidth+
				pFont->fw_table[c].postWidth)<pParent->uFrameWidth)
				{
				if(i>possible_trasition_point)
					string_pixel_Width+=pFont->fw_table[c].preWidth;
				string_pixel_Width+=pFont->fw_table[c].letterW;
				if (i<uInStrLen)
					string_pixel_Width+=pFont->fw_table[c].postWidth;
				}
			else
				{
				temp_string[possible_trasition_point]='\n';
				string_pixel_Width=start_pixel_offset;
				if (i>possible_trasition_point)
					{
					for(int j=possible_trasition_point;j<i; ++j ) 
						{
						c=temp_string[j];
						if (((c >= pFont->uFirstChar)) &&(c <=pFont->uLastChar)||( c == '\f' || c == '\r' || c == '\n' || c == '\t'))
							{
							if(j>possible_trasition_point)
								string_pixel_Width+=pFont->fw_table[c].preWidth;
							string_pixel_Width+=pFont->fw_table[c].letterW;
							if (j<i)
								string_pixel_Width+=pFont->fw_table[c].postWidth;

							}
						}  
					}
				}
			}
		}
	}
return &temp_string[0];

}


//----- (0044CE08) -------.text:0044DEA3   -------------------------------------------------
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
 unsigned char c,b;
 unsigned int uOutX,
              uOutY;

unsigned int uInStrLen,i;
char *test_string;

  v34 = 0;
  v10 = (int)_this;
  v9 = (int)pFont;
 
 
	
  if (!strcmp(pString, "null"))
    return;
  
    uInStrLen = strlen(pString);

    if ( !uX )
      uX = 12;
    if ( a8 )
    {
      test_string = (char *)pString;
    }
    else
    {
      test_string = (char *)FitTextInAWindow(pString, pFont, _this, uX, 0);
    }
    uOutX = uX + _this->uFrameX;
    uOutY = uY + _this->uFrameY;
    v12 = 0;

  if (!a8 || uOutY + pFont->uFontHeight <= a8)
  {
//   v38 = 0;
   if (uInStrLen > 0)
      {
        for(i=0; i<uInStrLen; i++) 
        {
          c = test_string[i];
          if (c >= pFont->uFirstChar && c <= pFont->uLastChar
            || c == '\f' || c == '\r' || c == '\t' || c == '\n')
          {
            switch ( c )
            {
              case '\t': // number (3 digit always) after \t denotes tab amount (in pixels);  example:  "\t004skips 4 whitespaces before _this string"
              //  memset(&Dest,0, sizeof (Dest));
                strncpy(Dest, &test_string[i + 1], 3);
                Dest[3] = 0;
                i += 3;
                v34 = atoi(Dest);
              //  v19 = v34;
                uOutX = uX + _this->uFrameX + atoi(Dest);
                break;
              case '\n':
               // b = pFont->uFontHeight;
                uY = uY + pFont->uFontHeight - 3;
                uOutY = uY + _this->uFrameY;
                uOutX = uX + v34 + _this->uFrameX;
                if ( a8 )
					{
				 
                  if ( (pFont->uFontHeight + uOutY - 3) > a8 )
                    return;
					}
                break;
              case '\f':
              //  memset(Dest,0, sizeof (Dest));
                strncpy(Dest,  &test_string[i + 1], 6);	  //5
                Dest[6] = 0;
                sscanf(Dest,"%x",&uTextMainColor);
               
                i += 6;
                break;
              case '\r':
              //  memset(Dest,0, sizeof (Dest));
                strncpy(Dest, &test_string[i + 1], 3);
                Dest[3] = 0;
                i += 3;
              //  v18 = atoi(Dest);
                b = GetStringWidth(pFont, &test_string[i]);
                uOutX = _this->uFrameZ - (_DWORD)b -atoi(Dest);
                uOutY = uY + _this->uFrameY;
                if ( a8 )
                {
                  b = pFont->uFontHeight + uOutY - 3;
                  if ( (signed int)b > a8 )
                    return;
                }
                break;
              default:
                if (c == '"' )
                {
                  if ( test_string[i + 1] == '"' )
                  {
                    ++i;
                  //  i = v12;
                  }
                }
				 if(!uTextMainColor)
                 uTextMainColor = 0xFFFFFF;
                uTextMainColor|=0xFF000000;
				uTextShadowColor|=0xFF000000; 
               // v32 = (char*)&test_string[v12];
                c = test_string[i];
               // v16 = pFont->fw_table[c].letterW;
             //   v33 = pFont->fw_table[c].postWidth;
                if ( i > 0 )
                  uOutX += pFont->fw_table[c].preWidth;
                v17 = pFont->array_000C20[c] + (int)&pFont->unk_001020;

                Render_DrawText(pD3DRenderer, uOutX, uOutY, (unsigned char *)v17,
                    pFont->fw_table[c].letterW,
                    pFont->uFontHeight, pFont->pFontPalette,
                    uTextMainColor,
                    uTextShadowColor);
                uOutX += pFont->fw_table[c].letterW;
                if ( i < uInStrLen)
                {
                  uOutX += pFont->fw_table[c].postWidth;
                }
                break;
            }
          }
         // v12 = i + 1;
          //v21 = __SETO__(v38 + 1, v35);
          //v20 = (signed int)(v38++ + 1 - v35) < 0;
        }
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
    while ( !test_char(*v8, (Font*)v13) )
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
int  AlignText_Center(int a1, const char *pString, struct Font *pFont)
{
  int v3; // esi@1
  int result; // eax@2

  v3 = (a1 - GetStringWidth(pFont, pString)) / 2;
  if ( v3 >= 0 )
    result = v3;
  else
    result = 0;
  return result;
}

//----- (0044C51E) -----------.text:0044D4E0 ---------------------------------------------
int GetStringWidth(struct Font *pFont, const char *pString)
{
signed int i; // ebx@3
unsigned int str_len; // ebp@3
int string_width; // esi@3

unsigned char c;

if (!pString)
	return 0;

str_len = strlen(pString);
string_width = 0;
for ( i = 0; i < str_len; ++i )
	{
	c = pString[i];
	if (test_char(c, pFont))
		{
		switch (c)
			{
		case '\t':
		case '\n':
		case '\r':
			return string_width;
		case '\f':
			i += 6;	  //was 5  new 32 color!
			break;
		default:
			if (i > 0)
				string_width += pFont->fw_table[c].preWidth;
			string_width += pFont->fw_table[c].letterW;
			if (i < str_len)
				string_width +=pFont->fw_table[c].postWidth;
			}

		}
	}
return string_width;
}

							//  (const char *a1, int a2, char a3, int a4, int a5, int a6)
//----- (0044C933) ---------.text:0044D92F -----------------------------------------------
char * sub_44C933(const char *pString, struct Font *pFont1, struct Font *pFont2, struct GUIWindow *a4, int uX, bool a6)
{
 
  Font *current_font;
  unsigned char c;
unsigned int uInStrLen,i;
char digits[3];
int possible_trasition_point;
int string_pixel_Width;
int start_pixel_offset;
current_font=pFont1;
  if (!pString)
	{
	// *(_DWORD *)&uX = (int)&v29;
	// Game_sub_40E2C8(&v29, "Invalid string passed !", (int)(&uX + 3));
	// sub_466D09(&pParent, *(int *)&v29, v30, v31, v32, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Font.cpp", 445);
	return 0;
	}
uInStrLen = strlen(pString);
strcpy(&temp_string[0], pString);
if (uInStrLen==0)
	return &temp_string[0];
i=0;
start_pixel_offset=string_pixel_Width=uX;
possible_trasition_point=0;
for(i=0; i<uInStrLen; i++) 
	{
	c=temp_string[i];
	if ((c >= current_font->uFirstChar) &&(c <=current_font->uLastChar)||( c == '\f' || c == '\r' || c == '\n' || c == '\t'))
		{
		switch (c)
			{
		case '\t':	// Horizontal tab 09
			{
			strncpy(digits,&temp_string[i+1],3);
			digits[3]=0;
			string_pixel_Width= atoi(digits)+uX;
			i+=3;
			break;
			}
		case  '\n':	//Line Feed 0A 10
			{
			string_pixel_Width=start_pixel_offset;
			possible_trasition_point=i;
			current_font=pFont1;
			break;
			}
		case  '\f':   //Form Feed, page eject  0C 12
			{
			i+=6;  //was 5	new 32 color
			break;
			}
		case  '\r':   //Carriage Return 0D 13
			{
			if (!a6)
				return (char*)pString;
			break;
			}
		case ' ' :
			{
			string_pixel_Width+=current_font->fw_table[c].letterW;
			possible_trasition_point=i;
			break;
			}
		case '_' :	//5F
			{	//switch fonts
			 current_font=pFont2;
			break;
			}
		default:

			if ((string_pixel_Width+current_font->fw_table[c].letterW+ current_font->fw_table[c].preWidth+
				current_font->fw_table[c].postWidth)<a4->uFrameWidth)
				{
				if(i>possible_trasition_point)
					string_pixel_Width+=current_font->fw_table[c].preWidth;
				string_pixel_Width+=current_font->fw_table[c].letterW;
				if (i<uInStrLen)
					string_pixel_Width+=current_font->fw_table[c].postWidth;
				}
			else
				{
				temp_string[possible_trasition_point]='\n';
				string_pixel_Width=start_pixel_offset;
				if (current_font=pFont2)
					{
					  uInStrLen++;
					 for(int j=uInStrLen; j>=possible_trasition_point+1; j--)
						temp_string[j]=temp_string[j-1]; 
					 temp_string[possible_trasition_point]='_';
					 possible_trasition_point++;
					}

				if (i>possible_trasition_point)
					{
					for(int j=possible_trasition_point;j<i; ++j ) 
						{
						c=temp_string[j];
						if ((c >= current_font->uFirstChar) &&(c <=current_font->uLastChar)||( c == '\f' || c == '\r' || c == '\n' || c == '\t'))
							{
							if(j>possible_trasition_point)
								string_pixel_Width+=current_font->fw_table[c].preWidth;
							string_pixel_Width+=current_font->fw_table[c].letterW;
							if (j<i)
								string_pixel_Width+=current_font->fw_table[c].postWidth;

							}
						}  
					}
				}
			}
		}
	}
return &temp_string[0];

}


//----- (0044D1E7) --------------------------------------------------------
void  sub_44D1E7(Font *pFont, int a2, int a3, int a4, const char *pString, int a6)
{
  int v6; // ebx@1
  int v8; // edi@3
  unsigned __int8 v9; // cl@4
  int v10; // eax@5
  int v14; // edx@9
  int v15; // ecx@9
  int v16; // eax@12
  int v17; // cx@12
  char Dest1[7]; // [sp+Ch] [bp-1Ch]@16

  //char v19; // [sp+11h] [bp-17h]@16
 // size_t v20; // [sp+20h] [bp-8h]@2
  int v21; // [sp+24h] [bp-4h]@1
  int v22; // [sp+30h] [bp+8h]@9
  unsigned char c;
unsigned int uInStrLen,i;
  v6 = 0;
  v21 = a2;


 if (!pString)
   return;

 v21 = dword_5C6DB4;
 uInStrLen = strlen(pString);

 if (!uInStrLen)
   return;


 v8 = a3;
 for(i=0; i<uInStrLen; i++) 
	{
	c=pString[i];

  if (test_char(c, pFont))
  {
	 switch (c)
			{
			case  '\f':   //Form Feed, page eject  0C 12
				{
				 strncpy(Dest1, &pString[i + 1], 6);
            Dest1[6] = 0;
			
            sscanf(Dest1,"%x",&v21);
            if(!v21)
              v21 = 0xFFFFFF;
            v21|=0xFF000000;
            dword_5C6DB4 = v21;
            i += 6;	  //   was 5
				break;
				}
			case '\t':	// Horizontal tab 09
				{
				break;
				}
			case  '\n':	//Line Feed 0A 10
			  return;
	 default:
		 {
			//v15 = 3 * v10 + 9;
            //  v14 = *(_DWORD *)(pFont + 4 * v15);
            //  v22 = *(_DWORD *)(pFont + 4 * v15);
              if ( pFont->fw_table[c].letterW )
              {
                if ( i > 0 )
                  v8 +=pFont->fw_table[c].preWidth;
                v17 = v21;
                v16 = pFont->array_000C20[c] + (int)&pFont->unk_001020;
                if ( !v21 )
                  v17 = 0xFFFFFFFF;
                Render_DrawText(pD3DRenderer, v8, a4, (unsigned char *)v16, pFont->fw_table[c].letterW, pFont->uFontHeight, pFont->pFontPalette, v17, 0);
                v8 +=  pFont->fw_table[c].letterW;
                if (i <uInStrLen )
                  v8 += pFont->fw_table[c].postWidth;
		 }
		 }
		 }
	  }
	 }
}

//----- (0044C62E) ---.text:0044D607   -----------------------------------------------------
int  sub_44C62E(Font *pFont1, Font *pFont2, const char *pString, struct GUIWindow *a4, int a5, bool bParagraph)
{
  int i; // edi@1
  unsigned char *v8; // ebx@3
  int string_Height; // esi@3
 // size_t v10; // eax@3
  unsigned char c; // cl@4

  size_t str_len; // [sp+14h] [bp+10h]@3

  //v6 = a1;
  if ( !pString )
    return 0;
  string_Height = pFont1->uFontHeight - 3;
  v8 = (unsigned char *)sub_44C933(pString, pFont1, pFont2, a4, a5, false);
  

str_len = strlen(pString);
//pString[0]=0;
for ( i = 0; i < str_len; ++i )
	{
	c =v8[i];
	if (test_char(c, pFont1))
		{
		switch (c)
			{
		
		case '\n':	//Line Feed 0A 10
			   string_Height += pFont1->uFontHeight - 3;
				break;	
		case '\t': // Horizontal tab 09
		case '\r':	//Carriage Return 0D 13
			   if ( bParagraph )
				   i+=3;
		case '\f':
			i += 6;	  //was 5  new 32 color!
			break;
			}
		
		}
	}
return string_Height;

}



//----- (0044D0B5) --------------------------------------------------------
void __fastcall sub_44D0B5(struct Font *a1, int a2, int a3, int a4, const char *Str, int a6)
{
  int v6; // ebx@1
  struct Font *v7; // esi@1
  int v8; // edi@3
  unsigned __int8 v9; // cl@4
  int v10; // eax@5
  int v11; // ecx@5
  int v12; // ecx@6
  int v13; // ecx@7
  int v14; // ecx@8
  int v15; // ebx@10
  __int16 v16; // ax@13
  int v17; // edx@13
  unsigned __int8 v18; // sf@18
  unsigned __int8 v19; // of@18
  char Dest[7]; // [sp+Ch] [bp-20h]@17
  char v21; // [sp+11h] [bp-1Bh]@17
  size_t v22; // [sp+20h] [bp-Ch]@2
  int v23; // [sp+24h] [bp-8h]@1
  int v24; // [sp+28h] [bp-4h]@2
  char *v25; // [sp+38h] [bp+Ch]@4

  v6 = 0;
  v23 = a2;
  v7 = a1;
  if ( Str )
  {
    v23 = dword_5C6DB4;
    v22 = strlen(Str);
    v24 = 0;
    if ( (signed int)v22 > 0 )
    {
      v8 = a4;
      do
      {
        v25 = (char *)&Str[v6];
        if ( test_char(Str[v6], v7) )
        {
          v10 = v9;
          v11 = v9 - 9;
          if ( v11 )
          {
            v12 = v11 - 1;
            if ( !v12 )
              return;
            v13 = v12 - 2;
            if ( v13 )
            {
              v14 = v13 - 1;
              if ( v14 )
              {
                if ( v14 != 82 )
                {
                  v15 = *(_DWORD *)(v7 + 4 * (3 * v10 + 9));
                  if ( v15 )
                  {
                    if ( v24 > 0 )
                      v8 += 2 * *(_DWORD *)(v7 + 12 * v10 + 32);
                    v17 = *(_DWORD *)((int)v7 + 4 * v10 + 3104) + (int)v7 + 4128;
                    v16 = v23;
                    if ( !v23 )
                      v16 = -1;
                    sub_40F845(v8, v17, v15, *(_BYTE *)(v7 + 5), *(_DWORD *)(v7 + 12), v16, 2 * a6);
                    v8 += 2 * v15;
                    if ( v24 < (signed int)v22 )
                      v8 += 2 * *(_DWORD *)(v7 + 12 * (unsigned __int8)*v25 + 40);
                  }
                }
              }
            }
            else
            {
              strncpy(Dest, &Str[v6 + 1], 6u);	   //was 5
              v21 = 0;
               sscanf(Dest,"%x",&v23);;
              dword_5C6DB4 = v23;
              v24 = v6 + 6;
            }
          }
        }
        v6 = v24 + 1;
      //  compile_error;//v19 = __SETO__(v24 + 1, v22);
        v18 = (signed int)(v24++ + 1 - v22) < 0;
      }
      while ( v18 ^ v19 );
    }
  }
}


//----- (0044CB4F) -----------.text:0044DB6F  ---------------------------------------------
int __fastcall GUIWindow_sub_44CB4F(int a1, int a2, signed int a3, int a4, int a5, const char *Str1, signed int Source, int a8)
{
  int v8; // ebx@1
  int v9; // edi@1
  signed int v11; // esi@3
  unsigned __int8 v12; // cl@7
  int v13; // ebx@19
  int v14; // esi@19
  unsigned __int8 v15; // cl@21
  int v16; // eax@22
  int v17; // ecx@22
  int v18; // ecx@23
  int v19; // ecx@24
  int v20; // ecx@26
  int v21; // eax@28
  int v22; // ebx@34
  int v23; // eax@34
  int v24; // ebx@36
  char Dest[6]; // [sp+Ch] [bp-20h]@34
  char v26; // [sp+Fh] [bp-1Dh]@34
  char v27; // [sp+11h] [bp-1Bh]@35
  int v28; // [sp+20h] [bp-Ch]@17
  int v29; // [sp+24h] [bp-8h]@1
  size_t v30; // [sp+28h] [bp-4h]@1
  int i; // [sp+40h] [bp+14h]@5
  int v32; // [sp+40h] [bp+14h]@19
  const char *v33; // [sp+44h] [bp+18h]@20
  int v34; // [sp+48h] [bp+1Ch]@26

  //a5;//colored or white text flag
  v9 = a2;
  v29 = a1;
  v30 = strlen(Str1);
  v8 = GetStringWidth((Font *)v9, Str1);
  if ( v8 < Source )
  {
    FontDrawText((GUIWindow *)v29, (Font *)v9, a3, a4, Str1, 0xFFFFFF, 0, 0);
    return v8;
  }
  strcpy((char *)pStringBuffer, Str1);
  v11 = 0;
  if ( a8 )
    _strrev((char *)pStringBuffer);
  for ( i = 0; i < (signed int)v30; ++i )
  {
    if ( v11 >= Source )
      break;
    if (v12 = test_char((unsigned char)pStringBuffer[i], (Font *)v9) )
    {
      if ( v12 < 9u )
        goto LABEL_12;
      if ( v12 > 0xAu )
      {
        if ( v12 == 12 )
        {
          i += 6; //5
        }
        else
        {
          if ( v12 != 13 )
          {
LABEL_12:
            if ( i > 0 )
              v11 += *(_DWORD *)(v9 + 12 * v12 + 32);
            v11 += *(_DWORD *)(v9 + 4 * (3 * v12 + 9));
            if ( i < (signed int)v30 )
              v11 += *(_DWORD *)(v9 + 12 * v12 + 40);
            continue;
          }
        }
      }
    }
  }
  byte_5C657F[i] = 0;
  v30 = strlen((char *)pStringBuffer);
  v28 = GetStringWidth((Font *)v9, (char *)pStringBuffer);
  if ( a8 )
    _strrev((char *)pStringBuffer);
  v32 = 0;
  v14 = a3 + *(_DWORD *)v29;
  v13 = a4 + *(_DWORD *)(v29 + 4);
  if ( (signed int)v30 > 0 )
  {
    v33 = (char *)(char *)pStringBuffer + 1;
    do
    {
      if ( v15 = test_char((unsigned char)pStringBuffer[v32], (Font *)v9) )
      {
        v16 = v15;
        v17 = v15 - 9;
        if ( v17 )
        {
          v18 = v17 - 1;
          if ( v18 )
          {
            v19 = v18 - 2;
            if ( v19 )
            {
              if ( v19 == 1 )
              {
                strncpy(Dest, v33, 3u);
                Dest[3] = 0;
                v32 += 3;
                v33 += 3;
                v22 = atoi(Dest);
                v23 = GetStringWidth((Font *)v9, (char *)&pStringBuffer[v32]);
                v14 = *(_DWORD *)(v29 + 16) - v23 - v22;
                v13 = a4;
              }
              else
              {
                v20 = *(_DWORD *)(v9 + 4 * (3 * v16 + 9));
                v34 = *(_DWORD *)(v9 + 4 * (3 * v16 + 9));
                if ( v32 > 0 )
                  v14 += *(_DWORD *)(v9 + 12 * v16 + 32);
                v21 = *(_DWORD *)(v9 + 4 * v16 + 3104) + v9 + 4128;
                //if ( a5 )
                  Render_DrawText(pD3DRenderer, v14, v13, (unsigned char *)v21, v20, *(_BYTE *)(v9 + 5), (unsigned short *)*(_DWORD *)(v9 + 12), a5, 0);
                /*else
                  sub_4A6AB1(pD3DRenderer, v14, v13, v21, v20, *(_BYTE *)(v9 + 5), *(_DWORD *)(v9 + 12), 0);*/
                //sub_4A6AB1 is obsolete, replaces with Render_DrawText
                v14 += v34;
                if ( v32 < (signed int)v30 )
                  v14 += *(_DWORD *)(v9 + 12 * (unsigned __int8)(char *)pStringBuffer[v32] + 40);
              }
            }
            else
            {
              strncpy(Dest, v33, 6u);
              Dest[6] = 0;
              v32 += 6;	 //
              v33 += 6;	//
               sscanf(Dest,"%x",&a5);;
            }
          }
          else
          {
            v24 = *(_BYTE *)(v9 + 5);
            v14 = a3;
            a4 = a4 + v24 - 3;
            v13 = v24 + a4 - 3;
          }
        }
        else
        {
          strncpy(Dest, v33, 3u);
          Dest[3] = 0;
          atoi(Dest);
          v32 += 3;
          v33 += 3;
        }
      }
      ++v32;
      ++v33;
    }
    while ( v32 < (signed int)v30 );
  }
  return v28;
}

//----- (00452C30) --------.text:00453D8------------------------------------------------
char *RemoveQuote(char *pStr)
{
  if ( *pStr == '"' )
  {
    pStr[strlen(pStr) - 1] = 0;
    return pStr + 1;
  }
  return pStr;
}

//----- (0044D406) --------------------------------------------------------
char *__fastcall GUIWindow_sub_44D406(struct GUIWindow *a1, struct Font *pFont, int a3, int a4, unsigned __int16 a5, const char *pString, int a7)
{
  char *result; // eax@1
  int v8; // ebx@1
  int v9; // edi@1
  int v10; // esi@1
  char *v12; // eax@1
  int v13; // eax@2

  v8 = a1->uFrameWidth - a3;
  dword_5C6DB4 = a5;
  v12 = (char *)FitTextInAWindow(pString, pFont, a1, a3, 0);
  result = strtok(v12, "\n");
  v9 = a3 + a1->uFrameX;
  v10 = a4 + a1->uFrameY;
  while ( result )
  {
    v13 = (v8 - GetStringWidth(pFont, result)) >> 1;
    if ( v13 < 0 )
      v13 = 0;
    sub_44D1E7(pFont, a5, v9 + v13, v10, result, 640);
    v10 += pFont->uFontHeight - a7;
    result = strtok(0, "\n");
  }
  return result;
}

//----- (0044D2FD) --------------------------------------------------------
void sub_44D2FD(struct Font *a1, struct Font *a2, int Str, int a4, int a5, int a6, unsigned __int16 a7, unsigned __int16 a8, const char *a9, int a10, int a11)
{
  char *result; // eax@1
  int v12; // ebx@1
  signed int v13; // edi@1
  int v14; // esi@1
  char *v15; // eax@1
  signed int v16; // ecx@4
  int v17; // edi@4
  int v18; // eax@6
  char *v19; // [sp+Ch] [bp-5Ch]@1
  int v20; // [sp+10h] [bp-58h]@1
  int v21; // [sp+14h] [bp-54h]@1
  int v22; // [sp+18h] [bp-50h]@1
  char *v23; // [sp+1Ch] [bp-4Ch]@1
  int v24; // [sp+20h] [bp-48h]@1
  int v25; // [sp+60h] [bp-8h]@1
  int v26; // [sp+64h] [bp-4h]@1
  const char *v27; // [sp+70h] [bp+8h]@1
  int v28; // [sp+74h] [bp+Ch]@4
  signed int v29; // [sp+80h] [bp+18h]@2

  v12 = a7;
  v22 = a6;
  v13 = Str;
  v26 = (int)a1;
  v24 = a4 + a6 - 1;
  v21 = a5;
  v25 = (int)a2;
  v23 = (char *)(Str + a5 - 1);
  dword_5C6DB4 = a7;
  v19 = (char *)Str;
  v20 = a4;
  v15 = sub_44C933(a9, a1, a2, (GUIWindow*)&v19, 0, true);
  result = strtok(v15, "\n");
  v27 = result;
  v14 = a10 + 2 * a11 * a4;
  if ( result )
  {
    v29 = v13 >> 1;
    while ( 1 )
    {
      v17 = v26;
      dword_5C6DB4 = v12;
      v16 = 0;
      v28 = v12;
      if ( *result == 95 )
      {
        v17 = v25;
        v28 = a8;
        dword_5C6DB4 = a8;
        v16 = 1;
      }
      v18 = (a5 - GetStringWidth((Font *)v17, &result[v16])) >> 1;
      if ( v18 < 0 )
        v18 = 0;
      sub_44D0B5((Font *)v17, v28, a8, v14 + 2 * (v18 + v29), v27, a11);
      v14 += 2 * a11 * (*(_BYTE *)(v17 + 5) - 3);
      result = strtok(0, "\n");
      v27 = result;
      if ( !result )
        break;
      result = (char *)v27;
    }
  }

}

//----- (0040F845) --------------------------------------------------------
__int16 __fastcall sub_40F845(int a1, int a2, int a3, int a4, int a5, __int16 a6, int a7)
{
  int v7; // edi@1
  int v8; // esi@1
  int v9; // ecx@2
  int v10; // eax@3

  v7 = a1;
  v8 = a2; //string
  do
  {
    v9 = a3;
    do
    {
      v10 = *(_BYTE *)v8++;
      if ( (_BYTE)v10 )
      {
        if ( (_BYTE)v10 == 1 )
        {
          LOWORD(v10) = *(_WORD *)(a5 + 2 * v10);
          *(_WORD *)v7 = v10;
        }
        else
        {
          LOWORD(v10) = a6;
          *(_WORD *)v7 = a6;
        }
      }
      v7 += 2;
      --v9;
    }
    while ( v9 );
    v7 = a7 + v7 - a3 - a3;
  }
  while ( a4-- != 1 );
  return v10;
}

//----- (00452C49) --------------------------------------------------------
void  InitializeGameText()
{
 int i;
  unsigned char *test_string; // eax@3
  unsigned char *tmp_pos; // eax@3
  int step; // ebp@4
  unsigned char c; // dl@5
  int temp_str_len; // ecx@5

  bool string_end; // [sp+14h] [bp-4h]@4

 if (pGlobalTXT_Raw)
   mem_mng.DeleteBuffer( (void *)pGlobalTXT_Raw);

 pGlobalTXT_Raw = (unsigned char *)LODFile_Events_LOD.LODFile_LoadRaw( "global.txt", 0);
 
 strtok((char *)pGlobalTXT_Raw, "\r");	   //Carriage Return 0D 13
 strtok(NULL, "\r");					   	  //Carriage Return 0D 13
 test_string = (unsigned char *)strtok(NULL, "\r") + 1;	 //Carriage Return 0D 13

 for (i = 0; i < 677; ++i)
	 {
	 step = 0;
	 string_end = false;
	 do
		 {
		 c = *test_string;
		 temp_str_len = 0;
		 if (c!= '\t' )	// Horizontal tab 09 
			 {
			 do
				 {
				 if ( !c )
					 break; 
				 c = *(test_string+temp_str_len+1);
				 temp_str_len++;    
				 }
				 while ( c != '\t' );	// Horizontal tab 09 
			 }
		 tmp_pos=test_string+temp_str_len;
		 if (*tmp_pos == 0)
			 string_end = true;
		 *tmp_pos = 0;
		 if ( temp_str_len == 0)
			 string_end = true;
		 else
			 {
			 if ( step == 1 )
				 pGlobalTXT_LocalizationStrings[i] = (unsigned char *)RemoveQuote((char *)test_string);
			 }
		 ++step;
		 test_string=tmp_pos+1;
		 }
		 while ( step <= 2 && !string_end);  

		 test_string = (unsigned char *)strtok(NULL, "\r") + 1;  //Carriage Return 0D 13
	 }	


 aMonthNames[0] = pGlobalTXT_LocalizationStrings[415];  aMonthNames[1] = pGlobalTXT_LocalizationStrings[416];
 aMonthNames[2] = pGlobalTXT_LocalizationStrings[417];  aMonthNames[3] = pGlobalTXT_LocalizationStrings[418];
 aMonthNames[4] = pGlobalTXT_LocalizationStrings[419];  aMonthNames[5] = pGlobalTXT_LocalizationStrings[420];
 aMonthNames[6] = pGlobalTXT_LocalizationStrings[421];  aMonthNames[7] = pGlobalTXT_LocalizationStrings[422];
 aMonthNames[8] = pGlobalTXT_LocalizationStrings[423];  aMonthNames[9] = pGlobalTXT_LocalizationStrings[424];
 aMonthNames[10] = pGlobalTXT_LocalizationStrings[425]; aMonthNames[11] = pGlobalTXT_LocalizationStrings[426];

 aDayNames[0] = pGlobalTXT_LocalizationStrings[145];  aDayNames[1] = pGlobalTXT_LocalizationStrings[230];
 aDayNames[2] = pGlobalTXT_LocalizationStrings[243];  aDayNames[3] = pGlobalTXT_LocalizationStrings[227];
 aDayNames[4] = pGlobalTXT_LocalizationStrings[91];   aDayNames[5] = pGlobalTXT_LocalizationStrings[188];
 aDayNames[6] = pGlobalTXT_LocalizationStrings[222];

 pSomeItemsNames[0] = pGlobalTXT_LocalizationStrings[568];
 pSomeItemsNames[1] = pGlobalTXT_LocalizationStrings[271];
 pSomeItemsNames[2] = pGlobalTXT_LocalizationStrings[272];
 pSomeItemsNames[3] = pGlobalTXT_LocalizationStrings[273];
 pSomeItemsNames[4] = pGlobalTXT_LocalizationStrings[274];
 pSomeItemsNames[5] = pGlobalTXT_LocalizationStrings[275];
 pSomeItemsNames[6] = pGlobalTXT_LocalizationStrings[276];
 pSomeItemsNames[7] = pGlobalTXT_LocalizationStrings[277];
 pSomeItemsNames[8] = pGlobalTXT_LocalizationStrings[278];
 pSomeItemsNames[9] = pGlobalTXT_LocalizationStrings[279];
 pSomeItemsNames[10] = pGlobalTXT_LocalizationStrings[280];
 pSomeItemsNames[11] = pGlobalTXT_LocalizationStrings[281];
 pSomeItemsNames[12] = pGlobalTXT_LocalizationStrings[282];
 pSomeItemsNames[13] = pGlobalTXT_LocalizationStrings[143];

 aClassNames[0] = pGlobalTXT_LocalizationStrings[LOCSTR_KNIGHT];
 aClassNames[1] = pGlobalTXT_LocalizationStrings[LOCSTR_CAVALIER];
 aClassNames[2] = pGlobalTXT_LocalizationStrings[LOCSTR_CHAMPION];
 aClassNames[3] = pGlobalTXT_LocalizationStrings[LOCSTR_BLK_KNIGHT];

 aClassNames[4] = pGlobalTXT_LocalizationStrings[LOCSTR_THIEF];
 aClassNames[5] = pGlobalTXT_LocalizationStrings[LOCSTR_ROGUE];
 aClassNames[6] = pGlobalTXT_LocalizationStrings[LOCSTR_SPY];
 aClassNames[7] = pGlobalTXT_LocalizationStrings[LOCSTR_ASSASIN];

 aClassNames[8] = pGlobalTXT_LocalizationStrings[LOCSTR_MONK];
 aClassNames[9] = pGlobalTXT_LocalizationStrings[26];
 aClassNames[10] = pGlobalTXT_LocalizationStrings[432];
 aClassNames[11] = pGlobalTXT_LocalizationStrings[27];

 aClassNames[12] = pGlobalTXT_LocalizationStrings[LOCSTR_PALADIN];
 aClassNames[13] = pGlobalTXT_LocalizationStrings[263];
 aClassNames[14] = pGlobalTXT_LocalizationStrings[264];
 aClassNames[15] = pGlobalTXT_LocalizationStrings[28];

 aClassNames[16] = pGlobalTXT_LocalizationStrings[LOCSTR_ARCHER];
 aClassNames[17] = pGlobalTXT_LocalizationStrings[267];
 aClassNames[18] = pGlobalTXT_LocalizationStrings[119];
 aClassNames[19] = pGlobalTXT_LocalizationStrings[124];

 aClassNames[20] = pGlobalTXT_LocalizationStrings[LOCSTR_RANGER];
 aClassNames[21] = pGlobalTXT_LocalizationStrings[370];
 aClassNames[22] = pGlobalTXT_LocalizationStrings[33];
 aClassNames[23] = pGlobalTXT_LocalizationStrings[40];

 aClassNames[24] = pGlobalTXT_LocalizationStrings[LOCSTR_CLERIC];
 aClassNames[25] = pGlobalTXT_LocalizationStrings[257];
 aClassNames[26] = pGlobalTXT_LocalizationStrings[44];
 aClassNames[27] = pGlobalTXT_LocalizationStrings[46];

 aClassNames[28] = pGlobalTXT_LocalizationStrings[LOCSTR_DRUID];
 aClassNames[29] = pGlobalTXT_LocalizationStrings[269];
 aClassNames[30] = pGlobalTXT_LocalizationStrings[270];
 aClassNames[31] = pGlobalTXT_LocalizationStrings[48];

 aClassNames[32] = pGlobalTXT_LocalizationStrings[LOCSTR_SORCERER];
 aClassNames[33] = pGlobalTXT_LocalizationStrings[260];
 aClassNames[34] = pGlobalTXT_LocalizationStrings[261];
 aClassNames[35] = pGlobalTXT_LocalizationStrings[49];

 aCharacterConditionNames[0] = pGlobalTXT_LocalizationStrings[52];
 aCharacterConditionNames[1] = pGlobalTXT_LocalizationStrings[241];
 aCharacterConditionNames[2] = pGlobalTXT_LocalizationStrings[14];
 aCharacterConditionNames[3] = pGlobalTXT_LocalizationStrings[4];
 aCharacterConditionNames[4] = pGlobalTXT_LocalizationStrings[69];
 aCharacterConditionNames[5] = pGlobalTXT_LocalizationStrings[117];
 aCharacterConditionNames[6] = pGlobalTXT_LocalizationStrings[166];
 aCharacterConditionNames[7] = pGlobalTXT_LocalizationStrings[65];
 aCharacterConditionNames[8] = pGlobalTXT_LocalizationStrings[166];
 aCharacterConditionNames[9] = pGlobalTXT_LocalizationStrings[65];
 aCharacterConditionNames[10] = pGlobalTXT_LocalizationStrings[166];
 aCharacterConditionNames[11] = pGlobalTXT_LocalizationStrings[65];
 aCharacterConditionNames[12] = pGlobalTXT_LocalizationStrings[162];
 aCharacterConditionNames[13] = pGlobalTXT_LocalizationStrings[231];
 aCharacterConditionNames[14] = pGlobalTXT_LocalizationStrings[58];
 aCharacterConditionNames[15] = pGlobalTXT_LocalizationStrings[220];
 aCharacterConditionNames[16] = pGlobalTXT_LocalizationStrings[76];
 aCharacterConditionNames[17] = pGlobalTXT_LocalizationStrings[601];
 aCharacterConditionNames[18] = pGlobalTXT_LocalizationStrings[98];

 aSkillNames[0] = pGlobalTXT_LocalizationStrings[271];
 aSkillNames[1] = pGlobalTXT_LocalizationStrings[272];
 aSkillNames[2] = pGlobalTXT_LocalizationStrings[273];
 aSkillNames[3] = pGlobalTXT_LocalizationStrings[274];
 aSkillNames[4] = pGlobalTXT_LocalizationStrings[275];
 aSkillNames[5] = pGlobalTXT_LocalizationStrings[276];
 aSkillNames[6] = pGlobalTXT_LocalizationStrings[277];
 aSkillNames[7] = pGlobalTXT_LocalizationStrings[278];
 aSkillNames[8] = pGlobalTXT_LocalizationStrings[279];
 aSkillNames[9] = pGlobalTXT_LocalizationStrings[280];
 aSkillNames[10] = pGlobalTXT_LocalizationStrings[281];
 aSkillNames[11] = pGlobalTXT_LocalizationStrings[282];
 aSkillNames[12] = pGlobalTXT_LocalizationStrings[283];
 aSkillNames[13] = pGlobalTXT_LocalizationStrings[284];
 aSkillNames[14] = pGlobalTXT_LocalizationStrings[285];
 aSkillNames[15] = pGlobalTXT_LocalizationStrings[286];
 aSkillNames[16] = pGlobalTXT_LocalizationStrings[289];
 aSkillNames[17] = pGlobalTXT_LocalizationStrings[290];
 aSkillNames[18] = pGlobalTXT_LocalizationStrings[291];
 aSkillNames[19] = pGlobalTXT_LocalizationStrings[287];
 aSkillNames[20] = pGlobalTXT_LocalizationStrings[288];
 aSkillNames[21] = pGlobalTXT_LocalizationStrings[292];
 aSkillNames[22] = pGlobalTXT_LocalizationStrings[293];
 aSkillNames[23] = pGlobalTXT_LocalizationStrings[294];
 aSkillNames[24] = pGlobalTXT_LocalizationStrings[295];
 aSkillNames[25] = pGlobalTXT_LocalizationStrings[296];
 aSkillNames[26] = pGlobalTXT_LocalizationStrings[297];
 aSkillNames[27] = pGlobalTXT_LocalizationStrings[298];
 aSkillNames[28] = pGlobalTXT_LocalizationStrings[299];
 aSkillNames[29] = pGlobalTXT_LocalizationStrings[300];
 aSkillNames[30] = pGlobalTXT_LocalizationStrings[50];
 aSkillNames[31] = pGlobalTXT_LocalizationStrings[77];
 aSkillNames[32] = pGlobalTXT_LocalizationStrings[88];
 aSkillNames[33] = pGlobalTXT_LocalizationStrings[89];
 aSkillNames[34] = pGlobalTXT_LocalizationStrings[90];
 aSkillNames[35] = pGlobalTXT_LocalizationStrings[95];
 aSkillNames[36] = pGlobalTXT_LocalizationStrings[301];
 aSkillNames[37] = pGlobalTXT_LocalizationStrings[153];

 aSpellSchoolNames[0] = pGlobalTXT_LocalizationStrings[87];
 aSpellSchoolNames[1] = pGlobalTXT_LocalizationStrings[6];
 aSpellSchoolNames[2] = pGlobalTXT_LocalizationStrings[240];
 aSpellSchoolNames[3] = pGlobalTXT_LocalizationStrings[70];
 aSpellSchoolNames[4] = pGlobalTXT_LocalizationStrings[214];
 aSpellSchoolNames[5] = pGlobalTXT_LocalizationStrings[142];
 aSpellSchoolNames[6] = pGlobalTXT_LocalizationStrings[29];
 aSpellSchoolNames[7] = pGlobalTXT_LocalizationStrings[133];
 aSpellSchoolNames[8] = pGlobalTXT_LocalizationStrings[54];

 aAttributeNames[0] = pGlobalTXT_LocalizationStrings[144];
 aAttributeNames[1] = pGlobalTXT_LocalizationStrings[116];
 aAttributeNames[2] = pGlobalTXT_LocalizationStrings[163];
 aAttributeNames[3] = pGlobalTXT_LocalizationStrings[75];
 aAttributeNames[4] = pGlobalTXT_LocalizationStrings[1];
 aAttributeNames[5] = pGlobalTXT_LocalizationStrings[211];
 aAttributeNames[6] = pGlobalTXT_LocalizationStrings[136];

 aAMPMNames[0] = pGlobalTXT_LocalizationStrings[472];
 aAMPMNames[1] = pGlobalTXT_LocalizationStrings[473];

 aNPCProfessionNames[0] = pGlobalTXT_LocalizationStrings[153];
 aNPCProfessionNames[1] = pGlobalTXT_LocalizationStrings[308];
 aNPCProfessionNames[2] = pGlobalTXT_LocalizationStrings[309];
 aNPCProfessionNames[3] = pGlobalTXT_LocalizationStrings[7];
 aNPCProfessionNames[4] = pGlobalTXT_LocalizationStrings[306];
 aNPCProfessionNames[5] = pGlobalTXT_LocalizationStrings[310];
 aNPCProfessionNames[6] = pGlobalTXT_LocalizationStrings[311];
 aNPCProfessionNames[7] = pGlobalTXT_LocalizationStrings[312];
 aNPCProfessionNames[8] = pGlobalTXT_LocalizationStrings[313];
 aNPCProfessionNames[9] = pGlobalTXT_LocalizationStrings[314];
 aNPCProfessionNames[10] = pGlobalTXT_LocalizationStrings[105];
 aNPCProfessionNames[11] = pGlobalTXT_LocalizationStrings[315];
 aNPCProfessionNames[12] = pGlobalTXT_LocalizationStrings[316];
 aNPCProfessionNames[13] = pGlobalTXT_LocalizationStrings[317];
 aNPCProfessionNames[14] = pGlobalTXT_LocalizationStrings[115];
 aNPCProfessionNames[15] = pGlobalTXT_LocalizationStrings[318];
 aNPCProfessionNames[16] = pGlobalTXT_LocalizationStrings[319];
 aNPCProfessionNames[17] = pGlobalTXT_LocalizationStrings[320];
 aNPCProfessionNames[18] = pGlobalTXT_LocalizationStrings[321];
 aNPCProfessionNames[19] = pGlobalTXT_LocalizationStrings[322];
 aNPCProfessionNames[20] = pGlobalTXT_LocalizationStrings[323];
 aNPCProfessionNames[21] = pGlobalTXT_LocalizationStrings[293];
 aNPCProfessionNames[22] = pGlobalTXT_LocalizationStrings[324];
 aNPCProfessionNames[23] = pGlobalTXT_LocalizationStrings[498];
 aNPCProfessionNames[24] = pGlobalTXT_LocalizationStrings[525];
 aNPCProfessionNames[25] = pGlobalTXT_LocalizationStrings[327];
 aNPCProfessionNames[26] = pGlobalTXT_LocalizationStrings[328];
 aNPCProfessionNames[27] = pGlobalTXT_LocalizationStrings[329];
 aNPCProfessionNames[28] = pGlobalTXT_LocalizationStrings[330];
 aNPCProfessionNames[29] = pGlobalTXT_LocalizationStrings[331];
 aNPCProfessionNames[20] = pGlobalTXT_LocalizationStrings[332];
 aNPCProfessionNames[31] = pGlobalTXT_LocalizationStrings[333];
 aNPCProfessionNames[32] = pGlobalTXT_LocalizationStrings[334];
 aNPCProfessionNames[33] = pGlobalTXT_LocalizationStrings[335];
 aNPCProfessionNames[34] = pGlobalTXT_LocalizationStrings[336];
 aNPCProfessionNames[35] = pGlobalTXT_LocalizationStrings[337];
 aNPCProfessionNames[36] = pGlobalTXT_LocalizationStrings[338];
 aNPCProfessionNames[37] = pGlobalTXT_LocalizationStrings[339];
 aNPCProfessionNames[38] = pGlobalTXT_LocalizationStrings[340];
 aNPCProfessionNames[39] = pGlobalTXT_LocalizationStrings[341];
 aNPCProfessionNames[40] = pGlobalTXT_LocalizationStrings[342];
 aNPCProfessionNames[41] = pGlobalTXT_LocalizationStrings[343];
 aNPCProfessionNames[42] = pGlobalTXT_LocalizationStrings[596];
 aNPCProfessionNames[43] = pGlobalTXT_LocalizationStrings[345];
 aNPCProfessionNames[44] = pGlobalTXT_LocalizationStrings[346];
 aNPCProfessionNames[45] = pGlobalTXT_LocalizationStrings[347];
 aNPCProfessionNames[46] = pGlobalTXT_LocalizationStrings[348];
 aNPCProfessionNames[47] = pGlobalTXT_LocalizationStrings[349];  
 aNPCProfessionNames[48] = pGlobalTXT_LocalizationStrings[350];
 aNPCProfessionNames[49] = pGlobalTXT_LocalizationStrings[597];
 aNPCProfessionNames[50] = pGlobalTXT_LocalizationStrings[352];
 aNPCProfessionNames[51] = pGlobalTXT_LocalizationStrings[353];
 aNPCProfessionNames[52] = pGlobalTXT_LocalizationStrings[598];
 aNPCProfessionNames[53] = pGlobalTXT_LocalizationStrings[344];
 aNPCProfessionNames[54] = pGlobalTXT_LocalizationStrings[26];
 aNPCProfessionNames[55] = pGlobalTXT_LocalizationStrings[599];
 aNPCProfessionNames[56] = pGlobalTXT_LocalizationStrings[21];
 aNPCProfessionNames[57] = pGlobalTXT_LocalizationStrings[600];
 aNPCProfessionNames[58] = pGlobalTXT_LocalizationStrings[370];

 aMoonPhaseNames[0] = pGlobalTXT_LocalizationStrings[150];
 aMoonPhaseNames[1] = pGlobalTXT_LocalizationStrings[171];
 aMoonPhaseNames[2] = pGlobalTXT_LocalizationStrings[102];
 aMoonPhaseNames[3] = pGlobalTXT_LocalizationStrings[169];
 aMoonPhaseNames[4] = pGlobalTXT_LocalizationStrings[92];

 aSpellNames[0] = pGlobalTXT_LocalizationStrings[202];
 aSpellNames[1] = pGlobalTXT_LocalizationStrings[204];
 aSpellNames[2] = pGlobalTXT_LocalizationStrings[219];
 aSpellNames[3] = pGlobalTXT_LocalizationStrings[215];
 aSpellNames[4] = pGlobalTXT_LocalizationStrings[208];
 aSpellNames[5] = pGlobalTXT_LocalizationStrings[454];
 aSpellNames[6] = pGlobalTXT_LocalizationStrings[24];
 aSpellNames[7] = pGlobalTXT_LocalizationStrings[455];
 aSpellNames[8] = pGlobalTXT_LocalizationStrings[441];
 aSpellNames[9] = pGlobalTXT_LocalizationStrings[440];
 aSpellNames[10] = pGlobalTXT_LocalizationStrings[218];
 aSpellNames[11] = pGlobalTXT_LocalizationStrings[217];
 aSpellNames[12] = pGlobalTXT_LocalizationStrings[213];
 aSpellNames[13] = pGlobalTXT_LocalizationStrings[462];
 aSpellNames[14] = pGlobalTXT_LocalizationStrings[279];
 aSpellNames[15] = pGlobalTXT_LocalizationStrings[442];
 aSpellNames[16] = pGlobalTXT_LocalizationStrings[452];
 aSpellNames[17] = pGlobalTXT_LocalizationStrings[194];
 aSpellNames[18] = pGlobalTXT_LocalizationStrings[456];
 aSpellNames[19] = pGlobalTXT_LocalizationStrings[453];
 aSpellNames[20] = pGlobalTXT_LocalizationStrings[202];
 aSpellNames[21] = pGlobalTXT_LocalizationStrings[443];
 aSpellNames[22] = pGlobalTXT_LocalizationStrings[204];
 aSpellNames[23] = pGlobalTXT_LocalizationStrings[208];
 aSpellNames[24] = pGlobalTXT_LocalizationStrings[221];
 aSpellNames[25] = pGlobalTXT_LocalizationStrings[24];
 aSpellNames[26] = pGlobalTXT_LocalizationStrings[228];
 aSpellNames[27] = pGlobalTXT_LocalizationStrings[441];
 aSpellNames[28] = pGlobalTXT_LocalizationStrings[440];
 aSpellNames[29] = pGlobalTXT_LocalizationStrings[213];
 aSpellNames[30] = pGlobalTXT_LocalizationStrings[229];
 aSpellNames[31] = pGlobalTXT_LocalizationStrings[233];
 aSpellNames[32] = pGlobalTXT_LocalizationStrings[234];
 aSpellNames[33] = pGlobalTXT_LocalizationStrings[279];
 aSpellNames[34] = pGlobalTXT_LocalizationStrings[442];
 aSpellNames[35] = pGlobalTXT_LocalizationStrings[235];
 aSpellNames[36] = pGlobalTXT_LocalizationStrings[246];
 aSpellNames[37] = pGlobalTXT_LocalizationStrings[247];
 aSpellNames[38] = pGlobalTXT_LocalizationStrings[248];
 aSpellNames[39] = pGlobalTXT_LocalizationStrings[674];
 aSpellNames[40] = pGlobalTXT_LocalizationStrings[249];
 aSpellNames[41] = pGlobalTXT_LocalizationStrings[258];
 aSpellNames[42] = pGlobalTXT_LocalizationStrings[194];
 aSpellNames[43] = pGlobalTXT_LocalizationStrings[657];
}
