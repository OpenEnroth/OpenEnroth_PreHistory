#pragma once
#include "Render.h"
#include "legacy dx\d3d.h"
#include "legacy dx\dinput.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"



bool __stdcall Direct3D3EnumDevicesCallback(GUID *pGUID, const char *pDeviceDescription, const char *pDeviceName, D3DDEVICEDESC *a4, D3DDEVICEDESC *a5, int a6);
int __stdcall Direct3D3EnumDeviceZBufferFormatsCallback(void *Src, void *Dst); // idb

char __cdecl sub_4A597D();


// RenderD3D3_GetDeviceCaps returned flags
#define CAPS_NO_CAPS 0x01
#define CAPS_FLAG0   0x02
#define CAPS_FLAG1   0x04
#define CAPS_FLAG2   0x08
#define CAPS_FLAG3   0x10
#define CAPS_FLAG4   0x20
#define CAPS_FLAG5   0x40
#define CAPS_FLAG6   0x80




struct HWLBitmap
{
 unsigned char  pName[20];    // byte[20] @ 000000
 int            uPalette;     // dword    @ 000014
 unsigned int   uFullWidth;   // dword    @ 000018
 unsigned int   uFullHeight;  // dword    @ 00001C
 unsigned int   uAreaWidth;   // dword    @ 000020
 unsigned int   uAreaHeight;  // dword    @ 000024
 unsigned int   uBufWidth;    // dword    @ 000028
 unsigned int   uBufHeight;   // dword    @ 00002C
 int            AreaX;        // dword    @ 000030
 int            AreaY;        // dword    @ 000034
 unsigned char *pData;        // dword    @ 000038
};



struct RenderD3D3_DeviceDescription
{
 unsigned int   bDeviceIsValid;     // dword @ 000000   if device meets required caps
 unsigned char *pDeviceName;        // dword @ 000004
 unsigned char *pDeviceDescription; // dword @ 000008
 GUID          *pDeviceGUID;        // dword @ 00000C
 unsigned int   uDeviceCaps;        // dword @ 000010
 unsigned char *ptr_000014;
 unsigned char *ptr_000018;
 unsigned char *ptr_00001C;
 GUID          *ptr_000020;
 int            dword_000024;
};
//sizeof == 28

struct RenderD3D3
{
 unsigned int               bWindowMode;  // dword @ 000000
 int                        dword_000004;
 int                        dword_000008;
 HWND                       hOutputWindow; // dword @ 00000C
 int                        dword_000010;
 int                        dword_000014;
 int                        dword_000018;
 struct RenderD3D3_DeviceDescription *pAvailableDevices; // dword @ 00001C
 IDirectDraw4                        *pHostInterface;    // dword @ 000020
 IDirect3D3                *pDirect3D3;   // dword @ 000024
 int                        dword_000028;
 IDirectDrawSurface4       *pBackBuffer; // dword @ 00002C
 IDirectDrawSurface4       *pFontBuffer; // dword @ 000030
 IDirectDrawSurface4       *pZBuffer;    // dword @ 000034
 IDirect3DDevice3          *pDevice;     // dword @ 000038
 IDirect3DViewport3        *pOldViewport;   // dword @ 00003C
 int                        dword_000040;
 int                        dword_000044;
 unsigned char              pStatusMessage[48 + array_size_unknown];
};
//sizeof = 0148
//int __thiscall sub_49DC58(int this);
void RenderD3D3_FindAvailableDevices(struct RenderD3D3 *_this);
//signed int __thiscall sub_49DE14(int this, int a2, int a3, int a4);
bool RenderD3D3_Initialize(struct RenderD3D3 *_this, unsigned int uDeviceID, unsigned int bWindowMode, HWND hwnd);
//signed int __thiscall sub_49E444(void *this)
unsigned int RenderD3D3_GetDeviceCaps(struct RenderD3D3 *_this);
//signed int __thiscall sub_49E5D4(void *this, void *a2, void *a3, int a4, int a5, int a6, int a7, void *a8);
bool RenderD3D3_CreateTexture(struct RenderD3D3 *_this, unsigned int uTextureWidth, unsigned int uTextureHeight, IDirectDrawSurface4 **pOutSurface, IDirect3DTexture2 **pOutTexture, bool bAlphaChannel, bool a7, void *a8);
HRESULT RenderD3D3_EndScene(struct RenderD3D3 *_this);
//int __thiscall RenderD3D3_Present(int this, char a2);
HRESULT RenderD3D3_Present(struct RenderD3D3 *_this, char a2);
//int __thiscall sub_49E4FC(int this, int a2, int a3, int a4, float a5);
void RenderD3D3_ClearTarget(struct RenderD3D3 *_this, int a2, D3DCOLOR uClearColor, int a4, float a5);