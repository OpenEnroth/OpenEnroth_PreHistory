#pragma once
#include "Control.h"
#include "Align.h"


class cTexture;
namespace GUI
{
 class Image: public Control
 {
  public:
             Image();
    virtual ~Image() {}

    virtual Result::Code Initialize(const Rect<float> *pImageRect, const wchar_t *pTexture,
                                    Align::Type eHorizontalAlign, Align::Type eVerticalAlign);



   // Event handlers override
    virtual Result::Code OnDraw(float dt);


  protected:
    Align::Type eXAlign,
                eYAlign;

    class ::cTexture *pImageTexture;
 };
};