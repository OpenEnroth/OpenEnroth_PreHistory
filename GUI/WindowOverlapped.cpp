#include "GUI.h"
using namespace GUI;


Result::Code WindowOverlapped::OnDraw(float dt)
{
 pBackgroundImage->OnDraw(dt);

 for (unsigned int i = 0; i < 4; ++i)
   pBorders[i]->OnDraw(dt);

 for (unsigned int i = 0; i < 4; ++i)
   pCorners[i]->OnDraw(dt);

 for (List<Control *>::NodeType *pChild = cChildren.First(); pChild; pChild = pChild->pNext)
   pChild->pData->OnDraw(dt);

 return Result::Success;
}



Result::Code WindowOverlapped::SetStyle(Image *pBorderLeft, Image *pBorderRight,
                                        Image *pBorderTop, Image *pBorderBottom,
                                        Image *pCornerUpLeft, Image *pCornerUpRight,
                                        Image *pCornerBotLeft, Image *pCornerBotRight)
{
 pBorders[0] = pBorderLeft;
 pBorders[1] = pBorderRight;
 pBorders[2] = pBorderTop;
 pBorders[3] = pBorderBottom;

 pCorners[0] = pCornerUpLeft;
 pCorners[1] = pCornerUpRight;
 pCorners[2] = pCornerBotLeft;
 pCorners[3] = pCornerBotRight;

 for (unsigned int i = 0; i < 4; ++i)
 {
  pBorders[i]->SetControlArea(&cControlArea);
  pCorners[i]->SetControlArea(&cControlArea);
 }

 return Result::Success;
}




Result::Code WindowOverlapped::SetControlArea(Rect<float> *pNewArea)
{
 cControlArea = *pNewArea;

 pBackgroundImage->SetControlArea(pNewArea);
 for (unsigned int i = 0; i < 4; ++i)
 {
  pBorders[i]->SetControlArea(pNewArea);
  pCorners[i]->SetControlArea(pNewArea);
 }

 return Result::Success;
}



WindowOverlapped::WindowOverlapped():
  Window()
{
 pBorders[0] = nullptr, pBorders[1] = nullptr;
 pBorders[2] = nullptr, pBorders[3] = nullptr;
 pCorners[0] = nullptr, pCorners[1] = nullptr;
 pCorners[2] = nullptr, pCorners[3] = nullptr;
}

