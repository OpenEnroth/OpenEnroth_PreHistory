#pragma once
#include "..\CoreDefinitions.h"

namespace GUI
{
 class Control
 {
  friend class GUI;
  public:
    inline   Control() {bActive = false, bVisible = false;}
    virtual ~Control() {}

     virtual Result::Code AddChild(Control *)
     {
      return Result::NotImplemented;
     }

     bool                 Active() const        {return bActive;}
     virtual Result::Code Activate(bool bState) {bActive = bState; return Result::Success;}

     virtual Result::Code SetControlArea(Rect<float> *pNewArea)
     {
      cControlArea = *pNewArea;
      return Result::Success;
     }


     virtual Result::Code OnCreation()     {return Result::NotImplemented;}
     virtual Result::Code OnActivation()   {return Result::NotImplemented;}
     virtual Result::Code OnDestruction()  {return Result::NotImplemented;}

     virtual Result::Code OnUpdate()       {return Result::NotImplemented;}
     virtual Result::Code OnDraw(float dt) {return Result::NotImplemented;}

     virtual Result::Code OnMouseOver()    {return Result::NotImplemented;}

     virtual Result::Code OnMouseDown()    {return Result::NotImplemented;}
     virtual Result::Code OnMouseUp()      {return Result::NotImplemented;}
     virtual Result::Code OnMouseWheel()   {return Result::NotImplemented;}

     virtual Result::Code OnKeyDown()      {return Result::NotImplemented;}
     virtual Result::Code OnKeyUp()        {return Result::NotImplemented;}

     virtual Result::Code OnFocusSet()     {return Result::NotImplemented;}
     virtual Result::Code OnFocusLost()    {return Result::NotImplemented;}

   protected:
     GUI     *pHostInterface;
     Control *pParent;
     bool     bActive;
     bool     bVisible;

     Rect<float> cControlArea;
 };
};