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

    vDirection = Vec3(0, 0, 1);
    vUp = Vec3(0, 1, 0);
    vRight = Vec3(1, 0, 0);

    mOrientation.Identity();
   }
   
   unsigned int Initialize(const Vec3 *pPosition, const Quaternion *pOrientation);

   void             SetProjection(float fovy, float viewportAspect, float znear, float zfar);
   unsigned int     GetViewOrientation(Matrix4x4 *);  // view lacking position info
   unsigned int     GetView(Matrix4x4 *);             // complete view matrix
   const Matrix4x4 *GetProjection();
   unsigned int     GetViewProjection(Matrix4x4 *);

   void        SetPosition(const Vec3 *);
   const Vec3 *GetPosition();

   void        SetDirection(const Vec3 *);
   const Vec3 *GetDirection();

   unsigned int SetOrientation(const Quaternion *);
   unsigned int GetOrientation(Quaternion *);

   void         Move(float);
   void         Rotate(const Vec3 *pAxis, float angle);

 protected:
   Vec3       vPosition;
   Vec3       vDirection,
              vUp,
              vRight;
   Quaternion qOrientation;

   Matrix4x4  mProjection;
   Matrix4x4  mView;
   Matrix4x4  mViewProjection;

   Matrix4x4 mOrientation;
};

extern "C"
{
 void *CreateCamera();
 void Camera_SetProjection(void *, float fovy, float aspect, float znear, float zfar);
 void Camera_SetPosition(void *, float x, float y, float z);
 void Camera_SetDirection(void *, float x, float y, float z);
 void Camera_Rotate(void *, float x, float y, float z, float angle);
}