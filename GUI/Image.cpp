#include "..\mm7_unparsed_data.h"
#include "..\_lod.h"

#include "GUI.h"
using namespace GUI;


Result::Code Image::OnDraw(float dt)
{
 Range<float> cTextureDim = Range<float>(pImageTexture->uTextureWidth, pImageTexture->uTextureHeight);
 Rect<float>  cFinalRect;

 if (eXAlign == Align::Negative || eXAlign == Align::Center || eXAlign == Align::Positive)
 {
  unsigned int uOutX,
               uOutWidth = cTextureDim.min;
  switch (eXAlign)
  {
   case Align::Negative:
      uOutX = cControlArea.x.min;
      uOutWidth = cTextureDim.min <= cControlArea.x.Length() ? cTextureDim.min : cControlArea.x.Length();
   break;

   case Align::Positive:  uOutX = cControlArea.x.max - cTextureDim.min; break;
   case Align::Center:    uOutX = cControlArea.x.min + cControlArea.x.Length() / 2 - cTextureDim.min / 2; break;
  }

  // 9 cases
  // (left, top),    (center, top),    (right, top)
  // (left, center), (center, center), (right, center)
  // (left, bottom), (center, bottom), (right, bottom)
  if (eYAlign == Align::Negative || eYAlign == Align::Center || eYAlign == Align::Positive)
  {
   unsigned int uOutY;
   switch (eYAlign)
   {
    case Align::Negative:  uOutY = cControlArea.y.min;  break;
    case Align::Positive:  uOutY = cControlArea.y.max - cTextureDim.max; break;
    case Align::Center:    uOutY = cControlArea.y.min + cControlArea.y.Length() / 2 - cTextureDim.max / 2; break;
   }
   //Render_DrawTransparentTexture(pD3DRenderer, uOutX, uOutY, pImageTexture);
   Render_DrawTransparentRect(pD3DRenderer, uOutX, uOutY, 0, 0, uOutWidth, cTextureDim.max, pImageTexture);

   return Result::Success;
  }

  switch (eYAlign)
  {
   // 3 cases
   // (left, wrap)   (center, wrap)   (right, wrap)
   case Align::Wrap:
     unsigned int uOutY = cControlArea.y.min;
     for (unsigned int uHeightLeft = cControlArea.y.Length(); ; uHeightLeft -= cTextureDim.max)
     {
      if (uHeightLeft < cTextureDim.max)
      {
       Render_DrawTransparentRect(pD3DRenderer, uOutX, uOutY,
                                  0, 0,
                                  cTextureDim.min, uHeightLeft, pImageTexture);
       break;
      }

      Render_DrawTransparentTexture(pD3DRenderer, uOutX, uOutY, pImageTexture);
      uOutY += cTextureDim.max;
     }
     return Result::Success;
  }
 }



 if (eYAlign == Align::Negative || eYAlign == Align::Center || eYAlign == Align::Positive)
 {
  unsigned int uOutY;
  switch (eYAlign)
  {
   case Align::Negative:  uOutY = cControlArea.y.min;  break;
   case Align::Positive:  uOutY = cControlArea.y.max - cTextureDim.max; break;
   case Align::Center:    uOutY = cControlArea.y.min + cControlArea.y.Length() / 2 - cTextureDim.max / 2; break;
  }

  switch (eXAlign)
  {
   // 3 cases
   // (wrap, top)   (wrap, center)   (wrap, bottom)
   case Align::Wrap:
     unsigned int uOutX = cControlArea.x.min;
     for (unsigned int uWidthLeft = cControlArea.x.Length(); ; uWidthLeft -= cTextureDim.min)
     {
      if (uWidthLeft < cTextureDim.min)
      {
       Render_DrawTransparentRect(pD3DRenderer, uOutX, uOutY,
                                  0, 0,
                                  uWidthLeft, cTextureDim.max, pImageTexture);
       break;
      }

      Render_DrawTransparentTexture(pD3DRenderer, uOutX, uOutY, pImageTexture);
      uOutX += cTextureDim.min;
     }
     return Result::Success;
  }
 }

 // 1 case
 // (wrap, wrap)
 if (eXAlign == Align::Wrap && eYAlign == Align::Wrap)
 {
  unsigned int uOutY = cControlArea.y.min;
  for (unsigned int uHeightLeft = cControlArea.y.Length(); ; uHeightLeft -= cTextureDim.max)
  {
   unsigned int uOutX = cControlArea.x.min;
   for (unsigned int uWidthLeft = cControlArea.x.Length(); ; uWidthLeft -= cTextureDim.min)
   {
    unsigned int uOutWidth = uWidthLeft >= cTextureDim.min ? cTextureDim.min : uWidthLeft,
                 uOutHeight = uHeightLeft >= cTextureDim.max ? cTextureDim.max : uHeightLeft;
    Render_DrawTransparentRect(pD3DRenderer, uOutX, uOutY,
                               0, 0,
                               uOutWidth, uOutHeight, pImageTexture);

    if (uWidthLeft <= cTextureDim.min)
      break;

    uOutX += cTextureDim.min;
   }

   if (uHeightLeft <= cTextureDim.max)
     break;

   uOutY += cTextureDim.max;
  }
  return Result::Success;
 }

/*
 switch (eXMode)
 {
  case Align::Negative:
    switch (eYMode)
    {
     case Align::Wrap:

     break;

     default:
       __asm int 3;
    }
  break;

  case Align::Center:
    switch (eYMode)
    {
     case Align::Center:   // center, center
       cFinalRect = Rect<float>(cControlArea.x.min + cControlArea.x.Length() / 2 - cTextureDim.min / 2,
                                cControlArea.x.min + cControlArea.x.Length() / 2 + cTextureDim.min / 2,
                                cControlArea.y.min + cControlArea.y.Length() / 2 - cTextureDim.max / 2,
                                cControlArea.y.min + cControlArea.y.Length() / 2 + cTextureDim.max / 2);
       Render_DrawTransparentTexture(pD3DRenderer, cFinalRect.x.min, cFinalRect.y.min, pImageTexture);
     break;

     default:
       __asm int 3
    }
  break;

  case Align::Positive:
  break;

  case Align::Wrap:
  break;

  case ImageRender::Stretch:
    __asm int 3
 }*/


 return Result::Success;
}




Result::Code Image::Initialize(const Rect<float> *pImageRect, const wchar_t *pTexture, Align::Type eHorizontalMode, Align::Type eVerticalMode)
{
 if (pImageRect)
   cControlArea = *pImageRect;

#ifndef OLD_CODE
 pImageTexture = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(pTexture)];
#else
 char pFilenameA[256];
 wsprintfA(pFilenameA, "%S", pTexture);

 pImageTexture = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture(pFilenameA, 2)];
#endif

 eXAlign = eHorizontalMode;
 eYAlign = eVerticalMode;

 return Result::Success;
}


Image::Image():
  Control(), pImageTexture(nullptr)
{
}