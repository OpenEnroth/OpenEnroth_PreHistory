#pragma once
#include "GUIControl.h"


class GUIImage: public GUIControl
{
 public:
            GUIImage();
   virtual ~GUIImage() {}

   virtual Result::Code Initialize(const Rect<float> *pImageRect, const wchar_t *pTexture);



   // Event handlers override
   virtual Result::Code OnDraw(float dt);


 protected:
   class cTexture *pImageTexture;
};