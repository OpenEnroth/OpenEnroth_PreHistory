#pragma once
#include <math.h>

struct Vec3
{
 inline Vec3() {}
 inline Vec3(float a, float b, float c): x(a), y(b), z(c) {}

 inline void  Normalize();
 friend float Dot(const Vec3 &lh, const Vec3 &rh);
 friend Vec3  Cross(const Vec3 &lh, const Vec3 &rh);

 inline Vec3  &operator =(const Vec3 &v);
 inline Vec3  &operator +=(const Vec3 &v);
 friend Vec3   operator +(const Vec3 &lh, const Vec3 &rh);
 inline Vec3  &operator *=(float);
 friend Vec3   operator *(const Vec3 &lh, float scale);
 inline float &operator [](unsigned int uCol);

 union
 {
  float v[3];
  struct
  {
   float x, y, z;
  };
 };
};

struct Vec4
{
 inline Vec4() {}
 inline Vec4(float a, float b, float c, float d): x(a), y(b), z(c), w(d) {}

 inline void  Normalize();
 friend float Dot(const Vec4 &lh, const Vec4 &rh);

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
 inline Quaternion &Rotate(const Vec3 *pAxis, float angle);
 inline void        Rotate(float lattitude, float longitude);
 inline Matrix4x4  &ToMatrix(Matrix4x4 *pOut) const;

 inline Quaternion Conjugate();
 inline Vec3       Transform(const Vec3 &v);

 inline Quaternion  operator *(const Quaternion &q) const; 
 inline Quaternion &operator =(const Quaternion &q);

 float s, x, y, z;
};



struct Matrix4x4
{
 inline Vec4 &operator [](unsigned int uRow);


 inline Matrix4x4  operator *(Matrix4x4 &rv);
 inline Matrix4x4 &operator =(Matrix4x4 &rv);

 inline Vec3 Transofrm(Vec3 *);
 
 inline Matrix4x4 &Identity();
 inline Matrix4x4 &RotateX(float angle);
 inline Matrix4x4 &RotateY(float angle);
 inline Matrix4x4 &RotateZ(float angle);

 Vec4 m[4];
};