#include "GUIFont.h"
#include "GUIWindow.h"

#include "..\mm7_unparsed_data.h"

//----- (0044D406) --------------------------------------------------------
void GUIWindow_DrawText(struct GUIWindow *_this, struct Font *pFont,
                        unsigned int uHorizontalMargin, unsigned int uVerticalMargin,
                        unsigned int uDefaultColor, const char *pString, int sLineSpacing)
{
  int v8; // ebx@1
  int v10; // esi@1
  char *v12; // eax@1
  int v13; // eax@2

  v8 = _this->uFrameWidth - uHorizontalMargin;
  
  unsigned char pOutString[2048];
  v12 = (char *)FitTextInAWindow((unsigned char *)pString, pOutString, pFont, _this, uHorizontalMargin, 0);

 v10 = 0;
 for (v12 = strtok(v12, "\n"); v12; v12 = strtok(0, "\n"))
 {
   v13 = (v8 - GUIFont_GetLineWidth(pFont, (unsigned char *)v12)) / 2;
   if ( v13 < 0 )
     v13 = 0;
   sub_44D1E7_DrawTextLine(pFont, uDefaultColor,
              _this->uFrameX + uHorizontalMargin + v13,
              _this->uFrameY + uVerticalMargin + v10, v12, 640);
   v10 += pFont->uFontHeight - sLineSpacing;
 }
}