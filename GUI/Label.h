#pragma once
#include "Control.h"
#include "Align.h"


namespace GUI
{
 class Label: public Control
 {
  public:
             Label() {}
    virtual ~Label() {}

    virtual Result::Code Initialize(const Rect<float> *pRect, const char *pText,
                                    struct Font *pFont, _Render::Color *pColor,
                                    Align::Type eAlignType, unsigned int uHorizontalMargin, unsigned int uVerticalMargin);

    virtual Result::Code SetFont(struct Font *)     {return Result::NotImplemented;}
    virtual Result::Code SetColor(_Render::Color *) {return Result::NotImplemented;}




   // Event handlers override
    virtual Result::Code OnDraw(float dt);


  protected:
    Align::Type   eAlign;
    unsigned int  uXMargin,
                  uYMargin;

    struct Font    *pFont;
    _Render::Color  cTextColor;
    char            pString[2048];
 };
};