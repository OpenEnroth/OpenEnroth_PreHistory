#pragma once

namespace GUI
{
 namespace Align
 {
  enum Type
  {
   Negative = - 1, // align left, top
   Center = 0,     // align center
   Positive = 1,   // align right, bottom
   Wrap = 2,       // repeat item along axis
   Stretch = 3     // stretch item along axis
  };
 };
}