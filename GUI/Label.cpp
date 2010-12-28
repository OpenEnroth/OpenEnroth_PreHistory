#include "GUI.h"
using namespace GUI;

#include <windows.h>

//----- (0044D406) --------------------------------------------------------
Result::Code Label::OnDraw(float dt)
{
  int v8; // ebx@1
  int v10; // esi@1
  char *v12; // eax@1
  int v13; // eax@2

  v8 = cControlArea.x.Length() - uXMargin;

  
  unsigned char pOutString[2048];
  Window dummy;
  dummy.uFrameX = cControlArea.x.min;
  dummy.uFrameWidth = cControlArea.x.Length();

  v12 = (char *)FitTextInAWindow((unsigned char *)pString, pOutString, pFont, &dummy, uXMargin, 0);


 v10 = 0;
 for (v12 = strtok(v12, "\n"); v12; v12 = strtok(0, "\n"))
 {
   v13 = (v8 - GUIFont_GetLineWidth(pFont, (unsigned char *)v12)) / 2;
   if ( v13 < 0 )
     v13 = 0;
   sub_44D1E7_DrawTextLine(pFont, cTextColor.ToA8R8G8B8_uint(),
              cControlArea.x.min + uXMargin + v13,
              cControlArea.y.min + uYMargin + v10, v12, 640);
   v10 += pFont->uFontHeight;
 }

 return Result::Success;
}



Result::Code Label::Initialize(const Rect<float> *pRect, const char *pText,
                               struct Font *pFontToUse, _Render::Color *pColor,
                               Align::Type eAlignType, unsigned int uHorizontalMargin, unsigned int uVerticalMargin)
{
 if (pRect)
   cControlArea = *pRect;

 lstrcpyA(pString, pText);

 pFont = pFontToUse;
 cTextColor = *pColor;

 eAlign = eAlignType;
 uXMargin = uHorizontalMargin;
 uYMargin = uVerticalMargin;

 return Result::Success;
}