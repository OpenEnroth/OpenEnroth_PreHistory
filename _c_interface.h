#pragma once

struct _Camera *CreateCamera();
void Camera_SetProjection(struct _Camera *, float fovy, float aspect, float znear, float zfar);
void Camera_SetPosition(struct _Camera *, float x, float y, float z);
void Camera_SetDirection(struct _Camera *, float x, float y, float z);
void Camera_Rotate(struct _Camera *, float x, float y, float z, float angle);