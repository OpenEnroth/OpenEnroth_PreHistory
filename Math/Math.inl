#include "Math.h"


template<typename TOut, typename T1, typename T2>
  inline TOut Dot(const Vec3<T1> &v1, const Vec3<T2> &v2)
{
 return (TOut)v1.x * (TOut)v2.x + (TOut)v1.y * (TOut)v2.y + (TOut)v1.z * (TOut)v2.z;
}

template<typename type>
  inline Vec3<type> Cross(const Vec3<type> &v1, const Vec3<type> &v2)
{
 return Vec3<type>(v1.y * v2.z - v1.z * v2.y,
                   v1.z * v2.x - v1.x * v2.z,
                   v1.x * v2.y - v1.y * v2.x);
}



template<typename type>
  inline Vec3<type> operator +(const Vec3<type> &lh, const Vec3<type> &rh)
{
 return Vec3<type>(lh.x + rh.x, lh.y + rh.y, lh.z + rh.z);
}

template<typename T1, typename T2>
  inline Vec3<T1> operator -(const Vec3<T1> &lh, const Vec3<T2> &rh)
{
 return Vec3<T1>(lh.x - rh.x, lh.y - rh.y, lh.z - rh.z);
}

template<typename type>
  inline Vec3<type> operator *(const Vec3<type> &lh, const type scale)
{
 return Vec3<type>(lh.x * scale, lh.y * scale, lh.z * scale);
}






inline float Dot_v4(const Vec4 &v1, const Vec4 &v2)
{
 return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}


inline Quaternion &Quaternion::Rotate(const Vec3<float> *vAxis, float angle)
{
 s = cosf(angle * 0.5f);
 x = vAxis->x * sinf(angle * 0.5f);
 y = vAxis->y * sinf(angle * 0.5f);
 z = vAxis->z * sinf(angle * 0.5f);

 return *this;
}






inline void Quaternion::Identity()
{
 s = 1;
 x = y = z = 0;
}

inline void Quaternion::Rotate(float lattitude, float longitude)
{
 //ô = lattitude from [0; ï)       ô runs from (1, 0, 0) to (-1, 0, 0) in orthogonal coordinate system
 //o = longitude from [0; 2ï)      o òåòà runs int the north pole direction
 //((0, 0) sperical  =  (1, 0, 0) orthogonal

 //let vp be normalized projection of desired vector onto XZ plane, vp = (cosô, 0, sinô)
 //then we need to rotate from vp for o radians
 //axis of rotation can be found by : axis = vp cross n, where n is the plane's normal; n = Y = (0, 1, 0) for XZ plane

 //v =
   //cosf(lattitude) * cosf(longitude)
   //sinf(longitude)
   //sinf(lattitude) * cosf(longitude)
 //X cross v = (0, -v.z, v.y)        v cross X = (0, v.z, -v.y)
 //X dot v = v.x
   

 //next we need to find roation axis and angle between v and (1 0 0)
 float angle = acosf(cosf(lattitude) * cosf(longitude));
 struct Vec3<float> vAxis(0,
                          -sinf(lattitude) * cosf(longitude),
                          sinf(longitude));
 vAxis.Normalize();
 Rotate(&vAxis, angle);
}

inline Quaternion Quaternion::operator *(const Quaternion &q) const
{
 //q = [s, v], |v| = 1
 //q * q' = (s * s' - v dot v', v cross v' + sv' + s'v)

 return Quaternion(s * q.s - (x * q.x + y * q.y + z * q.z),
                   y * q.z - z * q.y + s * q.x + q.s * x,
                   z * q.x - x * q.z + s * q.y + q.s * y,
                   x * q.y - y * q.x + s * q.z + q.s * z);
}

inline Quaternion Quaternion::Conjugate()
{
 return Quaternion(s, -x, -y, -z);
}


inline Vec3<float> Quaternion::Transform(const Vec3<float> &v)
{
 //]p = [0, v]:
 // v' = q * p * q^-1  , where v' is v roatated by q
 Quaternion qVec(0, v.x, v.y, v.z);

 qVec = *this * qVec * Conjugate();

 return Vec3<float>(qVec.x, qVec.y, qVec.z);
}





inline Vec4 &Vec4::operator =(const Vec4 &v)
{
 x = v.x, y = v.y, z = v.z, w = v.w;
 return *this;
}

inline float &Vec4::operator [](unsigned int uCol)
{
 return v[uCol];
}

inline Quaternion &Quaternion::operator =(const Quaternion &q)
{
 s = q.s;
 x = q.x;
 y = q.y;
 z = q.z;
 return *this;
}

inline Matrix4x4 &Quaternion::ToMatrix(Matrix4x4 *pOut) const
{
 (*pOut)[0][0] = 1 - 2 * (y * y + z * z);
 (*pOut)[0][1] = 2 * (x * y + z * s);
 (*pOut)[0][2] = 2 * (x * z - y * s);
 (*pOut)[0][3] = 0;

 (*pOut)[1][0] = 2 * (x * y - z * s);
 (*pOut)[1][1] = 1 - 2 * (x * x + z * z);
 (*pOut)[1][2] = 2 * (z * y + x * s);
 (*pOut)[1][3] = 0;

 (*pOut)[2][0] = 2 * (x * z + y * s);
 (*pOut)[2][1] = 2 * (y * z - x * s);
 (*pOut)[2][2] = 1 - 2 * (x * x + y * y);
 (*pOut)[2][3] = 0;

 (*pOut)[3][0] = 0;
 (*pOut)[3][1] = 0;
 (*pOut)[3][2] = 0;
 (*pOut)[3][3] = 1;

 return *pOut;
}






inline Matrix4x4 &Matrix4x4::Identity()
{
 m[0][0] = 1;    m[0][1] = 0;   m[0][2] = 0;   m[0][3] = 0;
 m[1][0] = 0;    m[1][1] = 1;   m[1][2] = 0;   m[1][3] = 0;
 m[2][0] = 0;    m[2][1] = 0;   m[2][2] = 1;   m[2][3] = 0;
 m[3][0] = 0;    m[3][1] = 0;   m[3][2] = 0;   m[3][3] = 1;
 return *this;
}

inline Matrix4x4 &Matrix4x4::RotateX(float a)
{
 m[0][0] = 1;    m[0][1] =  0;         m[0][2] = 0;        m[0][3] = 0;
 m[1][0] = 0;    m[1][1] =  cosf(a);   m[1][2] = sinf(a);  m[1][3] = 0;
 m[2][0] = 0;    m[2][1] = -sinf(a);   m[2][2] = cosf(a);  m[2][3] = 0;
 m[3][0] = 0;    m[3][1] =  0;         m[3][2] = 0;        m[3][3] = 1;
 return *this;
}



inline Matrix4x4 &Matrix4x4::RotateY(float a)
{
 m[0][0] = cosf(a);    m[0][1] = 0;   m[0][2] = -sinf(a);  m[0][3] = 0;
 m[1][0] = 0;          m[1][1] = 1;   m[1][2] =  0;        m[1][3] = 0;
 m[2][0] = sinf(a);    m[2][1] = 0;   m[2][2] =  cosf(a);  m[2][3] = 0;
 m[3][0] = 0;          m[3][1] = 0;   m[3][2] =  0;        m[3][3] = 1;
 return *this;
}


inline Vec4 &Matrix4x4::operator [](unsigned int uRow)
{
 return m[uRow];
}

inline Matrix4x4 &Matrix4x4::operator =(Matrix4x4 &rv)
{
 m[0] = rv[0];
 m[1] = rv[1];
 m[2] = rv[2];
 m[3] = rv[3];
 return *this;
}

inline Matrix4x4 Matrix4x4::operator *(Matrix4x4 &rv)
{
 Matrix4x4 rval;
 for (unsigned int i = 0; i < 4; ++i)
   for (unsigned int j = 0; j < 4; ++j)
   {
    rval[i][j] = 0;

    for (unsigned int k = 0; k < 4; ++k)
       rval[i][j] += m[i][k] * rv[k][j];
   }

 return rval;
}


inline Vec3<float> Matrix4x4::Transofrm(Vec3<float> *vVec)
{
 Vec4 v(vVec->x * m[0][0] + vVec->y * m[1][0] + vVec->z * m[2][0] + m[3][0],
        vVec->x * m[0][1] + vVec->y * m[1][1] + vVec->z * m[2][1] + m[3][1],
        vVec->x * m[0][2] + vVec->y * m[1][2] + vVec->z * m[2][2] + m[3][2],
        vVec->x * m[0][3] + vVec->y * m[1][3] + vVec->z * m[2][3] + m[3][3]);
 return Vec3<float>(v.x / v.w, v.y / v.w, v.z / v.w);
}