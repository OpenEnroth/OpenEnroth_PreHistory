#include "Camera.h"


unsigned int Camera::GetViewOrientation(Matrix4x4 *pOutMatrix)
{
 if (!pOutMatrix)
   return -1;

 (*pOutMatrix)[0][0] = vRight.x; (*pOutMatrix)[0][1] = vUp.x; (*pOutMatrix)[0][2] = vDirection.x; (*pOutMatrix)[0][3] = 0;
 (*pOutMatrix)[1][0] = vRight.y; (*pOutMatrix)[1][1] = vUp.y; (*pOutMatrix)[1][2] = vDirection.y; (*pOutMatrix)[1][3] = 0;
 (*pOutMatrix)[2][0] = vRight.z; (*pOutMatrix)[2][1] = vUp.z; (*pOutMatrix)[2][2] = vDirection.z; (*pOutMatrix)[2][3] = 0;
 (*pOutMatrix)[3][0] = 0;        (*pOutMatrix)[3][1] = 0;     (*pOutMatrix)[3][2] = 0;            (*pOutMatrix)[3][3] = 1;
 return 0;
}


unsigned int Camera::Initialize(const Vec3 *pPosition, const Quaternion *pOrientation)
{
 vPosition = *pPosition;
 SetOrientation(pOrientation);

 return 0;
}



unsigned int Camera::SetOrientation(const Quaternion *qNewOrientation)
{
 qOrientation = *qNewOrientation;

 vDirection = qOrientation.Transform(Vec3(1, 0, 0));
 vRight = qOrientation.Transform(Vec3(0, 0, -1));
 vUp = qOrientation.Transform(Vec3(0, 1, 0));

 /*
  view matrix:

dir = normal(At - Eye)
right = normal(cross(Up, dir))
newup = cross(dir, right)

 right.x           newup.x           dir.x          0
 right.y           newup.y           dir.y          0
 right.z           newup.z           dir.z          0
-dot(right, eye)  -dot(newup, eye)  -dot(dir, eye)  1 */
 mView[0][0] = vRight.x;                mView[0][1] = vUp.x;                mView[0][2] = vDirection.z;                mView[1][3] = 0;
 mView[1][0] = vRight.y;                mView[1][1] = vUp.y;                mView[1][2] = vDirection.z;                mView[0][3] = 0;
 mView[2][0] = vRight.z;                mView[2][1] = vUp.z;                mView[2][2] = vDirection.z;                mView[2][3] = 0;
 mView[3][0] = -Dot(vRight, vPosition); mView[3][1] = -Dot(vUp, vPosition); mView[3][2] = -Dot(vDirection, vPosition); mView[3][3] = 1;

 return 0;
}

void Camera::Rotate(const Vec3 *pAxis, float angle)
{
 Quaternion qRotation;
 qRotation.Rotate(*pAxis, angle);

 qRotation = qRotation * qOrientation;
 SetOrientation(&qRotation);
}

void Camera::SetDirection(const Vec3 *pNewDirection)
{
 vDirection = *pNewDirection;
 vDirection.Normalize();

 qOrientation.Rotate(Cross(Vec3(1, 0, 0), vDirection), vDirection.x); // (1 0 0) cross dir, (1 0 0) dot dir
 SetOrientation(&qOrientation);
}




void Camera::SetProjection(float fovy, float viewportAspect, float znear, float zfar)
{
 float yScale = cos(0.5f * fovy) / sin(0.5f * fovy);
 float xScale = viewportAspect / yScale;
 float zdif = zfar - znear;

 mProjection.m[0][0] = xScale; mProjection.m[0][1] = 0;      mProjection.m[0][2] = 0;                    mProjection.m[0][3] = 0;
 mProjection.m[1][0] = 0;      mProjection.m[1][1] = yScale; mProjection.m[1][2] = 0;                    mProjection.m[1][3] = 0;
 mProjection.m[2][0] = 0;      mProjection.m[2][1] = 0;      mProjection.m[2][2] = zfar / zdif;          mProjection.m[2][3] = 1;
 mProjection.m[3][0] = 0;      mProjection.m[3][1] = 0;      mProjection.m[3][2] = -znear * zfar / zdif; mProjection.m[3][3] = 0;
}

const Matrix4x4 *Camera::GetProjection()
{
 return &mProjection;
}

const Matrix4x4 *Camera::GetViewProjection()
{
 mViewProjection = mView * mProjection;
 return &mViewProjection;
}

const Vec3 *Camera::GetDirection()
{
 return &vDirection;
}


void Camera::SetPosition(const Vec3 *pNewPosition)
{
 vPosition = *pNewPosition;
 
 mView[3][0] = -Dot(vRight, vPosition); mView[3][1] = -Dot(vUp, vPosition); mView[3][2] = -Dot(vDirection, vPosition);
}

const Vec3 *Camera::GetPosition()
{
 return &vPosition;
}





void *CreateCamera()
{
 return new Camera;
}

void Camera_SetProjection(void *_this, float fovy, float aspect, float znear, float zfar)
{
 Camera *pOldCamera = (Camera *)_this;
 pOldCamera->SetProjection(fovy, aspect, znear, zfar);
}

void Camera_SetPosition(void *_this, float x, float y, float z)
{
 Camera *pOldCamera = (Camera *)_this;
 pOldCamera->SetPosition(&Vec3(x, y, z));
}

void Camera_SetDirection(void *_this, float x, float y, float z)
{
 Camera *pOldCamera = (Camera *)_this;
 pOldCamera->SetDirection(&Vec3(x, y, z));
}

void Camera_Rotate(void *_this, float x, float y, float z, float angle)
{
 Camera *pOldCamera = (Camera *)_this;
 pOldCamera->Rotate(&Vec3(x, y, z), angle);
}