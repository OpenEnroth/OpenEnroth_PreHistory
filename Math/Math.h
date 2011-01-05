#pragma once
#include <math.h>



template<typename type>
  struct Vec1
{
 inline Vec1() {}
 inline Vec1(type a): x(a) {}
 inline Vec1(const Vec1<type> &other): x(other.x) {}

 type x;
};

template<typename type>
  struct Vec2: public Vec1<type>
{
 inline Vec2() {}
 inline Vec2(type a, type b): Vec1(a), y(b) {}
 inline Vec2(const Vec2<type> &other): x(other.x), y(other.y) {}

 type y;
};

template<typename type>
  struct Vec3
{
 inline Vec3() {}
 inline Vec3(type a, type b, type c): x(a), y(b), z(c) {}
 inline Vec3(const Vec3<type> &other): x(other.x), y(other.y), z(other.z) {}

 inline type Length()
 {
  return sqrt(x *x + y * y + z * z);
 }

 inline void Normalize()
 {
  type dot = x * x + y * y + z * z;
  if (dot < 0 || dot > 0)
  {
   type invm = (type)1 / sqrt(dot);
   x *= invm;
   y *= invm;
   z *= invm;
  }
  else
  {
   x = (type)1;
   y = z = (type)0;
  }
 }

 template<typename TOut, typename T1, typename T2>
   friend TOut Dot(const Vec3<T1> &lh, const Vec3<T2> &rh);
 template<typename T>
   friend Vec3<T> Cross(const Vec3<T> &lh, const Vec3<T> &rh);

 template<typename T>
   friend Vec3<T> operator +(const Vec3<T> &lh, const Vec3<T> &rh);
 template<typename T>
   friend Vec3<T> operator -(const Vec3<T> &lh, const Vec3<T> &rh);
 template<typename T>
   friend Vec3<T> operator *(const Vec3<T> &lh, const T scale);


 inline Vec3<type> &operator =(const Vec3<type> &v)
 {
  x = v.x, y = v.y, z = v.z;
  return *this;
 }

 template<typename vtype>
   inline Vec3<type> &operator =(const Vec3<vtype> &v)
 {
  x = v.x, y = v.y, z = v.z;
  return *this;
 }

 inline Vec3<type> &operator +=(const Vec3<type> &v)
 {
  x += v.x, y += v.y, z += v.z;
  return *this;
 }

 inline Vec3<type> &operator *=(type scale)
 {
  x *= scale, y *= scale, z *= scale;
  return *this;
 }


 type x, y, z;
};

  





struct Vec4
{
 inline Vec4() {}
 inline Vec4(float a, float b, float c, float d): x(a), y(b), z(c), w(d) {}

 inline void  Normalize();
 friend float Dot_v4(const Vec4 &lh, const Vec4 &rh);

 inline Vec4  &operator =(const Vec4 &v);
 inline float &operator [](unsigned int uCol);


 union
 {
  float v[4];
  struct
  {
   float x, y, z, w;
  };
 };
};

struct Matrix4x4;
struct Quaternion
{
 inline Quaternion() {}
 inline Quaternion(float a, float b, float c, float d): s(a), x(b), y(c), z(d) {}

 inline void        Identity();
 inline Quaternion &Rotate(const Vec3<float> *pAxis, float angle);
 inline void        Rotate(float lattitude, float longitude);
 inline Matrix4x4  &ToMatrix(Matrix4x4 *pOut) const;

 inline Quaternion  Conjugate();
 inline Vec3<float> Transform(const Vec3<float> &v);

 inline Quaternion  operator *(const Quaternion &q) const; 
 inline Quaternion &operator =(const Quaternion &q);

 float s, x, y, z;
};



struct Matrix4x4
{
 inline Vec4 &operator [](unsigned int uRow);


 inline Matrix4x4  operator *(Matrix4x4 &rv);
 inline Matrix4x4 &operator =(Matrix4x4 &rv);

 inline Vec3<float> Transofrm(Vec3<float> *);
 
 inline Matrix4x4 &Identity();
 inline Matrix4x4 &RotateX(float angle);
 inline Matrix4x4 &RotateY(float angle);
 inline Matrix4x4 &RotateZ(float angle);

 Vec4 m[4];
};