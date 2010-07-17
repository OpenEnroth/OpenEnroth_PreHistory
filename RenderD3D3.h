#pragma once
#include "Render.h"
#include <d3d.h>

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"



bool __stdcall Direct3D3EnumDevicesCallback(GUID *pGUID, const char *pDeviceDescription, const char *pDeviceName, D3DDEVICEDESC *a4, D3DDEVICEDESC *a5, int a6);



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



struct RendererD3D3_DeviceDescription
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

struct RendererD3D3
{
 unsigned int               bWindowMode;  // dword @ 000000
 int                        dword_000004;
 int                        dword_000008;
 HWND                       hOutputWindow; // dword @ 00000C
 int                        dword_000010;
 int                        dword_000014;
 int                        dword_000018;
 struct RendererD3D3_DeviceDescription *pAvailableDevices; // dword @ 00001C
 IDirectDraw4                          *pHostInterface;    // dword @ 000020
 int                        dword_000024;
 int                        dword_000028;
 int                        dword_00002C;
 int                        dword_000030;
 int                        dword_000034;
 int                        dword_000038;
 int                        dword_00003C;
 int                        dword_000040;
 int                        dword_000044;
 unsigned char              pStatusMessage[48 + array_size_unknown];
};
//sizeof = 0148
//int __thiscall sub_49DC58(int this);
void RendererD3D3_FindAvailableDevices(struct RendererD3D3 *_this);
//signed int __thiscall sub_49DE14(int this, int a2, int a3, int a4);
bool RendererD3D3_Initialize(struct RendererD3D3 *_this, unsigned int uDeviceID, unsigned int bWindowMode, HWND hwnd);