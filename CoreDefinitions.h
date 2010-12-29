#pragma once

#ifndef nullptr
  #define nullptr (0)
#endif


namespace Result
{
 enum Code
 {
  Success = 0,

  Generic = 1,        // Generic error without description
  InvalidParams = 2,  // Invalid parameters passed to function
  NotFound = 3,       // Some data cannot be found
  OutOfMemory = 4,    // Ran out of memory during operation
  NotImplemented = 5  // Requested functionality is not implemented
 };
};


#undef min
#undef max
#define _max(__a,__b)    (((__a) > (__b)) ? (__a) : (__b))
#define _min(__a,__b)    (((__a) < (__b)) ? (__a) : (__b))

template<typename type>
  struct Range
{
 inline Range()
 {}

 inline Range(type x, type y):
   min(x), max(y)
 {}

 inline Range<type> &operator =(const Range<type> &rh)
 {
  min = rh.min, max = rh.max;
  return *this;
 }

 inline type Length() const             {return max - min;}
 inline bool InRange(type val) const    {return min <= val && val < max;}
 inline bool Inside(type val) const     {return min < val && val < max;}
 inline bool NotOutside(type val) const {return min <= val && val <= max;}


 type min,
      max;
};


template<typename type>
  struct Rect
{
 inline Rect()
 {}

 inline Rect(Range<type> &a, Range<type> &b):
   x(a), y(b)
 {}

 inline Rect(type x1, type x2, type y1, type y2):
   x(x1, x2), y(y1, y2)
 {}

 inline Rect &operator =(const Rect<type> &rh)
 {
  x.min = rh.x.min, x.max = rh.x.max;
  y.min = rh.y.min, y.max = rh.y.max;
  return *this;
 }


 Range<type> x;
 Range<type> y;
};



namespace _Render
{
 struct Color
 {
  union
  {
   struct {float w, x, y, z;};
   struct {float a, r, g, b;};
   float v[4];
  };

  inline Color()
  {}

  inline Color(float _a, float _r, float _g, float _b):
    a(_a), r(_r), g(_g), b(_b)
  {}

  inline Color(unsigned int _a, unsigned int _r, unsigned int _g, unsigned int _b):
    a(_a / 255.0f), r(_r / 255.0f), g(_g / 255.0f), b(_b / 255.0f)
  {}

  inline Color &operator =(const Color &rh)
  {
   a = rh.a, r = rh.r, g = rh.g, b = rh.b;
   return *this;
  }


  inline unsigned int ToA8R8G8B8_uint()
  {
   return (((unsigned int)(a * 256.0f) & 0xFF) << 24) +
          (((unsigned int)(r * 256.0f) & 0xFF) << 16) +
          (((unsigned int)(g * 256.0f) & 0xFF) << 8) +
           ((unsigned int)(b * 256.0f) & 0xFF);
  }
 };
};






//Next definitions help to exclude lib headers, optimizing compilation time
//Smacker & AIL types
typedef struct _DIG_DRIVER *HDIGDRIVER;
typedef struct _SMACK      *HSMACK;
typedef struct _SMACKBLIT  *HSMACKBLIT;
typedef struct _SMACKBUF   *HSMACKBUF;
//AIL
typedef struct _REDBOOK    *HREDBOOK;
typedef struct _SAMPLE     *HSAMPLE;
typedef struct _PROVIDER   *HPROVIDER;
typedef struct _SEQUENCE   *HSEQUENCE;
typedef struct _STREAM     *HSTREAM;
typedef __int32             HATTRIB;
typedef __int32             HASISTREAM; // Handle to stream being managed by ASI codec
//Bink
typedef struct _BINK    *HBINK;
typedef struct _BINKBUF *HBINKBUF;
