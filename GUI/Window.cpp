#include "..\mm7_unparsed_data.h"

#include "GUI.h"
using namespace GUI;




Result::Code Window::OnDraw(float dt)
{
 pBackgroundImage->OnDraw(dt);
 for (List<Control *>::NodeType *pChild = cChildren.First(); pChild; pChild = pChild->pNext)
 {
  Control *pControl = pChild->pData;

  if (pControl->Active())
    pControl->OnDraw(dt);
 }

 return Result::Success;
}


Result::Code Window::Initialize(Rect<float> *pArea)
{
 cControlArea = *pArea;

 return Result::Success;
}

Result::Code Window::SetBackgroundImage(Image *pImage)
{
 pBackgroundImage = pImage;
 pBackgroundImage->SetControlArea(&cControlArea);

 return Result::Success;
}




Result::Code Window::SetControlArea(Rect<float> *pNewArea)
{
 cControlArea = *pNewArea;
 pBackgroundImage->SetControlArea(pNewArea);

 return Result::Success;
}




Window::Window():
  Control(), pBackgroundImage(nullptr)
{
}






//----- (0044D406) --------------------------------------------------------
void GUIWindow_DrawText(Window *_this, struct Font *pFont,
                        unsigned int uHorizontalMargin, unsigned int uVerticalMargin,
                        unsigned int uDefaultColor, const char *pString, int sLineSpacing)
{
  int v8; // ebx@1
  int v10; // esi@1
  char *v12; // eax@1
  int v13; // eax@2

  v8 = _this->uFrameWidth;
  v8 -= uHorizontalMargin;
  
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