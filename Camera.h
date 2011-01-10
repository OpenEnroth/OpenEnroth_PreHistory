#pragma once
#include "Math\\Math.h"
#include "Math\\Math.inl"

class Camera
{
 public:
   inline Camera()
   {
    vPosition = Vec3<float>(0, 0, 0);

    qOrientation.Identity();

    vDirection = Vec3<float>(0, 0, 1);
    vUp = Vec3<float>(0, 1, 0);
    vRight = Vec3<float>(1, 0, 0);

    mOrientation.Identity();
    fRotationX = 0;
    fRotationY = 0;
   }
   
   unsigned int Initialize(const Vec3<float> *pPosition, const Quaternion *pOrientation);

   void             SetProjection(float fovy, float viewportAspect, float znear, float zfar);
   unsigned int     GetViewOrientation(Matrix4x4 *);  // view lacking position info
   unsigned int     GetView(Matrix4x4 *);             // complete view matrix
   const Matrix4x4 *GetProjection();
   unsigned int     GetViewProjection(Matrix4x4 *);

   void               SetPosition(const Vec3<float> *);
   const Vec3<float> *GetPosition();

   void               SetDirection(const Vec3<float> *);
   const Vec3<float> *GetDirection();

   void         Move(float);
   void         RotateX(float angle);
   void         RotateY(float angle);
   void         Rotate(const Vec3<float> *pAxis, float angle);

 protected:
   Vec3<float> vPosition;
   Vec3<float> vDirection,
               vUp,
               vRight;
   Quaternion  qOrientation;

   Matrix4x4  mProjection;
   Matrix4x4  mView;
   Matrix4x4  mViewProjection;

   Matrix4x4 mOrientation;
   float     fRotationX;
   float     fRotationY;
};