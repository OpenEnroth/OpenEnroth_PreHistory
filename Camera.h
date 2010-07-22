#pragma once
#include "Math\\Math.h"
#include "Math\\Math.inl"

class Camera
{
 public:
   inline Camera()
   {
    vPosition = Vec3(0, 0, 0);

    qOrientation.Identity();

    vDirection = Vec3(1, 0, 0);
    vUp = Vec3(0, 1, 0);
    vRight = Vec3(0, 0, -1);
   }
   
   void             SetProjection(float fovy, float viewportAspect, float znear, float zfar);
   const Matrix4x4 *GetProjection();
   const Matrix4x4 *GetViewProjection();

   void        SetPosition(const Vec3 *);
   const Vec3 *GetPosition();

   void        SetDirection(const Vec3 *);
   const Vec3 *GetDirection();

   void        SetOrientation(const Quaternion *);

   void        Rotate(const Vec3 *pAxis, float angle);

 protected:
   Vec3       vPosition;
   Vec3       vDirection,
              vUp,
              vRight;
   Quaternion qOrientation;

   Matrix4x4  mProjection;
   Matrix4x4  mView;
   Matrix4x4  mViewProjection;
};

extern "C"
{
 void *CreateCamera();
 void Camera_SetProjection(void *, float fovy, float aspect, float znear, float zfar);
 void Camera_SetPosition(void *, float x, float y, float z);
 void Camera_SetDirection(void *, float x, float y, float z);
 void Camera_Rotate(void *, float x, float y, float z, float angle);
}