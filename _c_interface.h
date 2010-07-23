#pragma once

struct _Camera *CreateCamera();
void Camera_SetProjection(struct _Camera *, float fovy, float aspect, float znear, float zfar);
void Camera_SetPosition(struct _Camera *, float x, float y, float z);
void Camera_SetDirection(struct _Camera *, float x, float y, float z);
void Camera_Rotate(struct _Camera *, float x, float y, float z, float angle);





struct Viewport
{
 float x,     y;
 float z,     w;
 float znear, zfar;
};

void         *NewRender_CreateD3D10();
void         *NewRender_CreateOGL();
unsigned int  NewRender_Initialize(void *);
unsigned int  NewRender_Reset(void *, void *pTargetWindow, bool bFullscreen, void *pViewport);




void         *Window_Initialize(const wchar_t *pClass, const wchar_t *pWindow, bool bFrame);
unsigned int  Window_SetClientArea(void *, struct Viewport *);
unsigned int  Window_Show(void *);
unsigned int  Window_Update(void *, float);