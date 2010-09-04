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
 pOrientation->ToMatrix(&mOrientation);
 //SetOrientation(pOrientation);

 return 0;
}


/*
unsigned int Camera::SetOrientation(const Quaternion *qNewOrientation)
{
 qOrientation = *qNewOrientation;

 vDirection = qOrientation.Transform(Vec3(0, 0, 1));
 vRight = qOrientation.Transform(Vec3(1, 0, 0));
 vUp = qOrientation.Transform(Vec3(0, 1, 0));

//  view matrix:

//dir = normal(At - Eye)
//right = normal(cross(Up, dir))
//newup = cross(dir, right)

// right.x           newup.x           dir.x          0
// right.y           newup.y           dir.y          0
// right.z           newup.z           dir.z          0
//-dot(right, eye)  -dot(newup, eye)  -dot(dir, eye)  1
 mView[0][0] = vRight.x;                mView[0][1] = vUp.x;                mView[0][2] = vDirection.x;                mView[1][3] = 0;
 mView[1][0] = vRight.y;                mView[1][1] = vUp.y;                mView[1][2] = vDirection.y;                mView[0][3] = 0;
 mView[2][0] = vRight.z;                mView[2][1] = vUp.z;                mView[2][2] = vDirection.z;                mView[2][3] = 0;
 mView[3][0] = -Dot(vRight, vPosition); mView[3][1] = -Dot(vUp, vPosition); mView[3][2] = -Dot(vDirection, vPosition); mView[3][3] = 1;

 return 0;
}*/

void Camera::Move(float fAmount)
{
 vPosition += vDirection * fAmount;
}

void Camera::RotateX(float angle)
{
 fRotationX += angle;
 if (fRotationX >= 3.14159 * 0.5 - 0.01)
 {
  angle -= fRotationX - (3.141519 * 0.5f - 0.01);
  fRotationX = 3.141519 * 0.5f - 0.01;
 }
 else if (fRotationX < -3.14159 * 0.5 + 0.01)
 {
  angle += fRotationX - (-3.141519 * 0.5f + 0.01);
  fRotationX = -3.141519 * 0.5f + 0.01;
 }

 Matrix4x4 rx;
 rx.RotateX(angle);
 mOrientation =  mOrientation * rx;

 vDirection = mOrientation.Transofrm(&Vec3(0, 0, 1));
 vUp = mOrientation.Transofrm(&Vec3(0, 1, 0));
 vRight = mOrientation.Transofrm(&Vec3(1, 0, 0));
}

void Camera::RotateY(float angle)
{
 Matrix4x4 ry;
 ry.RotateY(angle);
 mOrientation = mOrientation * ry;

 vDirection = mOrientation.Transofrm(&Vec3(0, 0, 1));
 vUp = mOrientation.Transofrm(&Vec3(0, 1, 0));
 vRight = mOrientation.Transofrm(&Vec3(1, 0, 0));
}

void Camera::Rotate(const Vec3 *pAxis, float angle)
{
 Quaternion qRotation;
 qRotation.Rotate(pAxis, angle);

 Matrix4x4 mIncementalRotation;

 mOrientation = qRotation.ToMatrix(&mIncementalRotation) * mOrientation;

 //qRotation = qRotation * qOrientation;
 //SetOrientation(&qRotation);
}

void Camera::SetDirection(const Vec3 *pNewDirection)
{
 vDirection = *pNewDirection;
 vDirection.Normalize();

 qOrientation.Rotate(&Cross(Vec3(0, 0, 1), vDirection), vDirection.z); // (1 0 0) cross dir, (1 0 0) dot dir
 qOrientation.ToMatrix(&mOrientation);
 //SetOrientation(&qOrientation);
}


//#include <d3dx9.h>
//#pragma comment(lib, "d3dx9.lib")

void Camera::SetProjection(float fovy, float viewportAspect, float znear, float zfar)
{
 float yScale = 1.0 / tan(0.5f * fovy);//cos(0.5f * fovy) / sin(0.5f * fovy);
 float xScale = yScale / viewportAspect;
 float zdif = zfar - znear;

 mProjection.m[0][0] = xScale; mProjection.m[0][1] = 0;      mProjection.m[0][2] = 0;                    mProjection.m[0][3] = 0;
 mProjection.m[1][0] = 0;      mProjection.m[1][1] = yScale; mProjection.m[1][2] = 0;                    mProjection.m[1][3] = 0;
 mProjection.m[2][0] = 0;      mProjection.m[2][1] = 0;      mProjection.m[2][2] = zfar / zdif;          mProjection.m[2][3] = 1;
 mProjection.m[3][0] = 0;      mProjection.m[3][1] = 0;      mProjection.m[3][2] = -znear * zfar / zdif; mProjection.m[3][3] = 0;

 //D3DXMatrixPerspectiveFovLH((D3DXMATRIX *)&mProjection.m, fovy, viewportAspect, znear, zfar);
}

const Matrix4x4 *Camera::GetProjection()
{
 return &mProjection;
}

unsigned int Camera::GetViewProjection(Matrix4x4 *pOut)
{
 if (!pOut)
   return -1;

 mView[0][0] = vRight.x;                mView[0][1] = vUp.x;                mView[0][2] = vDirection.x;                mView[1][3] = 0;
 mView[1][0] = vRight.y;                mView[1][1] = vUp.y;                mView[1][2] = vDirection.y;                mView[0][3] = 0;
 mView[2][0] = vRight.z;                mView[2][1] = vUp.z;                mView[2][2] = vDirection.z;                mView[2][3] = 0;
 mView[3][0] = -Dot(vRight, vPosition); mView[3][1] = -Dot(vUp, vPosition); mView[3][2] = -Dot(vDirection, vPosition); mView[3][3] = 1;
 
 //Vec3 vd = mOrientation.Transofrm(&Vec3(0, 0, 1)),
 //     vu = mOrientation.Transofrm(&Vec3(0, 1, 0));

 //Vec3 vLookAt = vPosition + vd;
 //D3DXMatrixLookAtLH((D3DXMATRIX *)&mView, (D3DXVECTOR3 *)&vPosition, (D3DXVECTOR3 *)&vLookAt, (D3DXVECTOR3 *)&vu);

 mViewProjection = mView * mProjection;
 *pOut = mViewProjection;
 return 0;
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