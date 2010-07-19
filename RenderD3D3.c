#include "RenderD3D3.h"



//----- (0049DE14) --------------------------------------------------------
bool RenderD3D3_Initialize(struct RenderD3D3 *_this, unsigned int uDeviceID, unsigned int bWindowMode, HWND hwnd)
{
  int v4; // esi@1
  int v12; // ecx@20
  int v13; // eax@35
  int v14; // eax@37
  int v15; // eax@39
  int v16; // ecx@39
  const char *v23; // [sp-4h] [bp-DCh]@9
  const char *v24; // [sp-4h] [bp-DCh]@13
  const char *v25; // [sp-4h] [bp-DCh]@19
  signed int v26; // [sp-4h] [bp-DCh]@30
  int v27; // [sp+Ch] [bp-CCh]@37

  DDSURFACEDESC2 ddsd2;
  //int Dst; // [sp+1Ch] [bp-BCh]@11
  //int v29; // [sp+20h] [bp-B8h]@11
  //int v30; // [sp+24h] [bp-B4h]@16
  //int v31; // [sp+28h] [bp-B0h]@16
  //            [sp+2Ch]
  //int v32; // [sp+30h] [bp-A8h]@35
  //char v33; // [sp+64h] [bp-74h]@20
  //int v34; // [sp+70h] [bp-68h]@12
  //int v35; // [sp+84h] [bp-54h]@11

  D3DVIEWPORT2 d3dViewport;
  //int v36; // [sp+98h] [bp-40h]@28
  //int v37; // [sp+A4h] [bp-34h]@54
  //int v38; // [sp+A8h] [bp-30h]@54
  //int v39; // [sp+ACh] [bp-2Ch]@54
  //float v40; // [sp+B0h] [bp-28h]@28
  //float v41; // [sp+B4h] [bp-24h]@28
  //float v42; // [sp+B8h] [bp-20h]@28
  //float v43; // [sp+BCh] [bp-1Ch]@28
  //float v44; // [sp+C0h] [bp-18h]@28

  IDirectDrawClipper *pClipper; // [sp+C4h] [bp-14h]@18
  IDirectDraw        *lpDD; // [sp+C8h] [bp-10h]@1
 HRESULT hr;
 int v5, v47;

  v4 = _this;

 _this->bWindowMode = bWindowMode;
 _this->hOutputWindow = hwnd;

 if (DirectDrawCreate(_this->pAvailableDevices[uDeviceID].ptr_000020, &lpDD, 0) != S_OK)
 {
  wsprintfA(_this->pStatusMessage, "RenderD3D3::Initialize: DirectDrawCreate failed.");
  return false;
 }
 
 v5 = _this->pAvailableDevices;
 v47 = 40 * uDeviceID;

 hr = (lpDD->lpVtbl->QueryInterface)(lpDD, &memory_4D8410.IID_IDirectDraw4, &_this->pHostInterface);

 (lpDD->lpVtbl->Release)(lpDD);
 lpDD = 0;
 if (FAILED(hr))
 {
  wsprintfA(_this->pStatusMessage, "RenderD3D3::Initialize: no DirectDraw4.");

  return false;
 }

 if (bWindowMode && !_this->pAvailableDevices[uDeviceID].ptr_000020)
 {
  hr = (_this->pHostInterface->lpVtbl->SetCooperativeLevel)(_this->pHostInterface, hwnd, DDSCL_MULTITHREADED | DDSCL_NORMAL);

  if (FAILED(hr))
  {
LABEL_9:
      v23 = "RenderD3D3::Initialize: SetCooperativeLevel failed.";
LABEL_10:
      wsprintfA(_this->pStatusMessage, v23);
LABEL_65:
      if (_this->pHostInterface)
      {
       (_this->pHostInterface->lpVtbl->Release)(_this->pHostInterface);
       _this->pHostInterface = 0;
      }
      return false;
  }

  memset(&ddsd2, 0, sizeof(DDSURFACEDESC2));
  ddsd2.dwSize = sizeof(DDSURFACEDESC2);
  ddsd2.dwFlags = DDSD_CAPS;
  ddsd2.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
  if ((_this->pHostInterface->lpVtbl->CreateSurface)(_this->pHostInterface, &ddsd2, &_this->pFontBuffer, 0) == S_OK)
  {
   ddsd2.dwSize = sizeof(DDSURFACEDESC2);
   (_this->pHostInterface->lpVtbl->GetDisplayMode)(_this->pHostInterface, &ddsd2);
   //if (ddsd2.ddpfPixelFormat.dwRGBBitCount != 16)
   if (ddsd2.ddpfPixelFormat.dwRGBBitCount != 32)
   {
    v24 = "RenderD3D3::Initialize: desktop isn't 16bit.";
    goto LABEL_14;
   }

   ddsd2.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;
   ddsd2.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_3DDEVICE;
   ddsd2.dwWidth = 640;
   ddsd2.dwHeight = 480;
   hr = (_this->pHostInterface->lpVtbl->CreateSurface)(_this->pHostInterface, &ddsd2, &_this->pBackBuffer, 0);
   if (FAILED(hr))
   {
        v24 = "RenderD3D3::Initialize: failed to create back buffer.";
LABEL_14:
        wsprintfA(_this->pStatusMessage, v24);
        if (_this->pFontBuffer)
        {
         (_this->pFontBuffer->lpVtbl->Release)(_this->pFontBuffer);
         _this->pFontBuffer = 0;
        }
        goto LABEL_65;
   }

   hr = (_this->pHostInterface->lpVtbl->CreateClipper)(_this->pHostInterface, 0, &pClipper, 0);
   if (FAILED(hr))
   {
    v25 = "RenderD3D3::Initialize: failed to create clipper.";
    goto LABEL_45;
   }

   (pClipper->lpVtbl->SetHWnd)(pClipper, 0, hwnd);
   (_this->pFontBuffer->lpVtbl->SetClipper)(_this->pFontBuffer, pClipper);

   (pClipper->lpVtbl->Release)(pClipper);
   pClipper = 0;

   (_this->pHostInterface->lpVtbl->QueryInterface)(_this->pHostInterface, &memory_4D8410.IID_IDirect3D3, &_this->pDirect3D3);
   
      v12 = _this->pAvailableDevices;

   ddsd2.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT | DDSD_PIXELFORMAT;
   ddsd2.ddsCaps.dwCaps = DDSCAPS_ZBUFFER;
   ddsd2.dwWidth = 640;
   ddsd2.dwHeight = 480;

   hr = (_this->pDirect3D3->lpVtbl->EnumZBufferFormats)(_this->pDirect3D3, _this->pAvailableDevices[uDeviceID].pDeviceGUID, Direct3D3EnumDeviceZBufferFormatsCallback, &ddsd2.ddpfPixelFormat);
   if (FAILED(hr))
     goto LABEL_21;
   if (uDeviceID == 2 || uDeviceID == 3)
     ddsd2.ddsCaps.dwCaps |= DDSCAPS_SYSTEMMEMORY;


   if ((_this->pHostInterface->lpVtbl->CreateSurface)(_this->pHostInterface, &ddsd2, &_this->pZBuffer, 0) == S_OK)
      {
        if ((_this->pBackBuffer->lpVtbl->AddAttachedSurface)(_this->pBackBuffer, _this->pZBuffer) == S_OK)
        {
          if ((_this->pDirect3D3->lpVtbl->CreateDevice)(_this->pDirect3D3, _this->pAvailableDevices[uDeviceID].pDeviceGUID,  _this->pBackBuffer, &_this->pDevice, 0) == S_OK)
          {
            memset(&d3dViewport, 0, sizeof(D3DVIEWPORT2));
            d3dViewport.dvClipY = 1.0;
            d3dViewport.dvClipWidth = 2.0;
            d3dViewport.dvClipHeight = 2.0;
            d3dViewport.dvMinZ = 0.0;
            d3dViewport.dvMaxZ = 1.0;
            goto LABEL_54;
          }
LABEL_51:
          wsprintfA(_this->pStatusMessage, "Init - Failed to create D3D device.\n");
          if (_this->pDirect3D3)
          {
           (_this->pDirect3D3->lpVtbl->Release)(_this->pDirect3D3);
           _this->pDirect3D3 = 0;
          }
          goto LABEL_59;
        }
LABEL_48:
        wsprintfA(_this->pStatusMessage, "Init - Failed to attach z-buffer to back buffer.\n");
        if (_this->pZBuffer)
        {
         (_this->pZBuffer->lpVtbl->Release)(_this->pZBuffer);
         _this->pZBuffer = 0;
        }
        goto LABEL_61;
      }
      goto LABEL_44;
    }
LABEL_36:
    v23 = "Init - Failed to create front buffer.\n";
    goto LABEL_10;
  }
  if ( uDeviceID == 1 )
    v26 = 1045;
  else
    v26 = 1041;
  if ( (*(int (__stdcall **)(_DWORD, int, signed int))(*(_DWORD *)_this->pHostInterface + 80))(_this->pHostInterface, hwnd, v26) )
    goto LABEL_9;
  if ( (*(int (__stdcall **)(_DWORD, signed int, signed int, signed int, _DWORD, _DWORD))(*(_DWORD *)_this->pHostInterface + 84))(
         _this->pHostInterface,
         640,
         480,
         16,
         0,
         0) )
  {
    v23 = "Init - Failed to set display mode.\n";
    goto LABEL_10;
  }
  memset(&ddsd2, 0, sizeof(DDSURFACEDESC2));
  v13 = _this->pHostInterface;
  ddsd2.dwSize = sizeof(DDSURFACEDESC2);

  ddsd2.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
  ddsd2.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE | DDSCAPS_3DDEVICE | DDSCAPS_FLIP | DDSCAPS_COMPLEX;
  ddsd2.dwBackBufferCount = 1;
  if ( (*(int (__stdcall **)(int, int *, int, _DWORD))(*(_DWORD *)v13 + 24))(v13, &ddsd2, v4 + 48, 0) )
    goto LABEL_36;

  v14 = _this->pFontBuffer;
  v27 = 4;
  hr = (*(int (__stdcall **)(int, int *, int))(*(_DWORD *)v14 + 48))(v14, &v27, v4 + 44);

  (**(void (__stdcall ***)(_DWORD, _DWORD, _DWORD))_this->pHostInterface)(_this->pHostInterface, 5085880, &_this->pDirect3D3);
  if (FAILED(hr))
  {
    v25 = "Init - Failed to get D3D interface.\n";
    goto LABEL_45;
  }
  ddsd2.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT | DDSD_PIXELFORMAT;
  v15 = _this->pDirect3D3;
  v16 = *(_DWORD *)(v4 + 28);
  ddsd2.ddsCaps.dwCaps = DDSCAPS_ZBUFFER;
  ddsd2.dwWidth = 640;
  ddsd2.dwHeight = 480;
  if ( (*(int (__fastcall **)(int, int, _DWORD, _DWORD, int (__stdcall *)(void *, void *), char *))(*(_DWORD *)v15 + 40))(
         &_this->pDirect3D3,
         v47,
         _this->pDirect3D3,
         *(_DWORD *)(v16 + v47 + 12),
         Direct3D3EnumDeviceZBufferFormatsCallback,
         &ddsd2.ddpfPixelFormat) )
  {
LABEL_21:
    v25 = "Init - Failed to enumerate Z buffer formats.\n";
    goto LABEL_45;
  }
  if ( uDeviceID == 2 || uDeviceID == 3 )
    ddsd2.ddsCaps.dwCaps |= DDSCAPS_SYSTEMMEMORY;

  if ( (*(int (__stdcall **)(_DWORD, int *, int, _DWORD))(*(_DWORD *)_this->pHostInterface + 24))(_this->pHostInterface, &ddsd2, v4 + 52, 0) )
  {
LABEL_44:
    v25 = "Init - Failed to create z-buffer.\n";
LABEL_45:
    wsprintfA(_this->pStatusMessage, v25);
    if (_this->pBackBuffer)
    {
     (_this->pBackBuffer->lpVtbl->Release)(_this->pBackBuffer);
     _this->pBackBuffer = 0;
    }

LABEL_63:
    if (_this->pFontBuffer)
    {
     (_this->pFontBuffer->lpVtbl->Release)(_this->pFontBuffer);
     _this->pFontBuffer = 0;
    }
    goto LABEL_65;
  }
  if ( (*(int (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)_this->pBackBuffer + 12))(_this->pBackBuffer, _this->pZBuffer) )
    goto LABEL_48;

  if ( (*(int (__fastcall **)(int, int, _DWORD, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)_this->pDirect3D3 + 32))(
         &_this->pDirect3D3,
         v47,
         _this->pDirect3D3,
         *(_DWORD *)(*(_DWORD *)(v4 + 28) + v47 + 12),
         _this->pBackBuffer,
         v4 + 56,
         0) )
    goto LABEL_51;
  memset(&d3dViewport, 0, sizeof(D3DVIEWPORT2));
  d3dViewport.dvClipY = 1.0;
  d3dViewport.dvClipWidth = 2.0;
  d3dViewport.dvClipHeight = 2.0;
  d3dViewport.dvMaxZ = 1.0;

LABEL_54:
  d3dViewport.dwSize = sizeof(D3DVIEWPORT2);
  d3dViewport.dwWidth = 640;
  d3dViewport.dwHeight = 480;
  d3dViewport.dvClipX = -1.0;

  if (FAILED((_this->pDirect3D3->lpVtbl->CreateViewport)(_this->pDirect3D3, &_this->pViewport, 0)))
  {
    wsprintfA(_this->pStatusMessage, "Init - Failed to create viewport.\n");
    if (_this->pDevice)
    {
     (_this->pDevice->lpVtbl->Release)(_this->pDevice);
     _this->pDevice = 0;
    }
    if (_this->pDirect3D3)
    {
     (_this->pDirect3D3->lpVtbl->Release)(_this->pDirect3D3);
     _this->pDirect3D3 = 0;
    }
LABEL_59:
    if (_this->pZBuffer)
    {
     (_this->pZBuffer->lpVtbl->Release)(_this->pZBuffer);
     _this->pZBuffer = 0;
    }
LABEL_61:
    if (_this->pBackBuffer)
    {
     (_this->pBackBuffer->lpVtbl->Release)(_this->pBackBuffer);
     _this->pBackBuffer = 0;
    }
    goto LABEL_63;
  }

 (_this->pDevice->lpVtbl->AddViewport)(_this->pDevice, _this->pViewport);
 (_this->pViewport->lpVtbl->SetViewport2)(_this->pViewport, &d3dViewport);
 (_this->pDevice->lpVtbl->SetCurrentViewport)(_this->pDevice, _this->pViewport);
 return true;
}

//----- (0049DC58) --------------------------------------------------------
void RenderD3D3_FindAvailableDevices(struct RenderD3D3 *_this)
{
 _this->pHostInterface = 0;

 _this->pDirect3D3 = 0;
 _this->dword_000028 = 0;
 _this->pFontBuffer = 0;
 _this->pZBuffer = 0;
 _this->pDevice = 0;
 _this->pViewport = 0;
 _this->dword_000040 = 1;
 _this->dword_000044 = 10;

 _this->pAvailableDevices = malloc(4 * sizeof(struct RenderD3D3_DeviceDescription));
 memset(_this->pAvailableDevices, 0, 4 * sizeof(struct RenderD3D3_DeviceDescription));

 DirectDrawEnumerateA((LPDDENUMCALLBACKA)(DDrawEnumCallback), _this->pAvailableDevices);
}




struct D3DRenderer_stru2
{
 struct RenderD3D3_DeviceDescription *pDeviceDesc;
 unsigned char *ptr_000004;
};

//----- (0049D784) --------------------------------------------------------
bool __stdcall Direct3D3EnumDevicesCallback(GUID *pGUID, const char *pDeviceDescription, const char *pDeviceName, D3DDEVICEDESC *a4, D3DDEVICEDESC *a5, struct D3DRenderer_stru2 *a6)
//bool __stdcall Direct3D3EnumDevicesCallback(GUID *pGUID, const char *pDeviceDescription, const char *pDeviceName, unsigned char *a4, unsigned char *a5, struct D3DRenderer_stru3 *a6)
{
  int v6; // eax@1
  signed int v7; // edi@1
  int v8; // edi@14
  size_t v9; // eax@30
  size_t v10; // eax@30
  size_t v11; // eax@30
  size_t v12; // eax@30
  size_t v13; // eax@30

  v6 = a4->dwFlags;
  v7 = -1;
  if ( v6 )
  {
   if ( !*(_DWORD *)(a6->ptr_000004 + 32) )
      v7 = 0;
    if ( v6 )
    {
      if ( *(_DWORD *)(a6->ptr_000004 + 32) )
        v7 = 1;
    }
  }
  if ( !strcmp(pDeviceName, "RGB Emulation") )
  {
    if ( !*(_DWORD *)(a6->ptr_000004 + 32) )
      v7 = 2;
  }
  if ( !strcmp(pDeviceName, "Reference Rasterizer") )
  {
    if ( !*(_DWORD *)(a6->ptr_000004 + 32) )
      v7 = 3;
  }
  if ( v7 != -1 )
  {
    v8 = 40 * v7;
    a6->pDeviceDesc[v7].bDeviceIsValid = true;

    a6->pDeviceDesc[v7].uDeviceCaps = 0;
    if (~a4->dpcTriCaps.dwSrcBlendCaps & 0x10)
      a6->pDeviceDesc[v7].uDeviceCaps |= 0x02;
    if (~a4->dpcTriCaps.dwSrcBlendCaps & 0x02)
      a6->pDeviceDesc[v7].uDeviceCaps |= 0x04;
    if (~a4->dpcTriCaps.dwSrcBlendCaps & 0x01)
      a6->pDeviceDesc[v7].uDeviceCaps |= 0x08;
    if (~a4->dpcTriCaps.dwDestBlendCaps & 0x20)
      a6->pDeviceDesc[v7].uDeviceCaps |= 0x10;
    if (~a4->dpcTriCaps.dwDestBlendCaps & 0x02)
      a6->pDeviceDesc[v7].uDeviceCaps |= 0x20;
    if (~a4->dpcTriCaps.dwDestBlendCaps & 0x04)
      a6->pDeviceDesc[v7].uDeviceCaps |= 0x40;
    if (a4->dpcTriCaps.dwTextureCaps & 0x20)
      a6->pDeviceDesc[v7].uDeviceCaps |= 0x80;
    if (~a4->dwDevCaps & 0x1000)
      a6->pDeviceDesc[v7].uDeviceCaps |= 0x0100;

    v9 = strlen(pDeviceName);
    a6->pDeviceDesc[v7].pDeviceName = malloc(v9 + 1);//*(_DWORD *)(v8 + *(_DWORD *)a6 + 4) = operator new(v9 + 1);
    strcpy(a6->pDeviceDesc[v7].pDeviceName, pDeviceName);

    v10 = strlen(pDeviceDescription);
    a6->pDeviceDesc[v7].pDeviceDescription = malloc(v10 + 1);//*(_DWORD *)(v8 + *(_DWORD *)a6 + 8) = operator new(v10 + 1);
    strcpy(a6->pDeviceDesc[v7].pDeviceDescription, pDeviceDescription);

    a6->pDeviceDesc[v7].pDeviceGUID = malloc(0x10);//*(_DWORD *)(v8 + *(_DWORD *)a6 + 12) = operator new(0x10u);
    memcpy(a6->pDeviceDesc[v7].pDeviceGUID, pGUID, sizeof(GUID));

    v11 = strlen(*(const char **)(a6->ptr_000004 + 20));
    a6->pDeviceDesc[v7].ptr_000014 = malloc(v11 + 1);//*(_DWORD *)(v8 + *(_DWORD *)a6 + 20) = operator new(v11 + 1);
    strcpy(a6->pDeviceDesc[v7].ptr_000014, *(const char **)(a6->ptr_000004 + 20));

    v12 = strlen(*(const char **)(a6->ptr_000004 + 24));
    a6->pDeviceDesc[v7].ptr_000018 = malloc(v12 + 1);//*(_DWORD *)(v8 + *(_DWORD *)a6 + 24) = operator new(v12 + 1);
    strcpy(a6->pDeviceDesc[v7].ptr_000018, *(const char **)(a6->ptr_000004 + 24));

    v13 = strlen(*(const char **)(a6->ptr_000004 + 28));
    a6->pDeviceDesc[v7].ptr_00001C = malloc(v13 + 1);//*(_DWORD *)(v8 + *(_DWORD *)a6 + 28) = operator new(v13 + 1);
    strcpy(a6->pDeviceDesc[v7].ptr_00001C, *(const char **)(a6->ptr_000004 + 28));

    if ( *(_DWORD *)(a6->ptr_000004 + 32) )
    {
     a6->pDeviceDesc[v7].ptr_000020 = malloc(0x10);//*(_DWORD *)(v8 + *(_DWORD *)a6 + 32) = operator new(0x10u);
     memcpy(a6->pDeviceDesc[v7].ptr_000020, *(const void **)(a6->ptr_000004 + 32), sizeof(GUID));
    }
    else
    {
     a6->pDeviceDesc[v7].ptr_000020 = 0;
    }
    a6->pDeviceDesc[v7].dword_000024 = *(_DWORD *)(a6->ptr_000004 + 36);
  }
  return 1;
}



//----- (0049D717) --------------------------------------------------------
int __stdcall Direct3D3EnumDeviceZBufferFormatsCallback(DDPIXELFORMAT *Src, DDPIXELFORMAT *Dst)
{
  signed int v2; // esi@2

  if ( *((_DWORD *)Src + 1) & 0x400 | 0x2000 )
  {
    v2 = 0;
    if ( *((_DWORD *)Src + 3) == 16 && !*((_DWORD *)Src + 4) )
      goto LABEL_6;
    if ( !*(_DWORD *)Dst )
    {
      v2 = 1;
LABEL_6:
      memcpy(Dst, Src, sizeof(DDPIXELFORMAT));
      return v2;
    }
  }
  return 1;
}


//----- (0049E444) --------------------------------------------------------
unsigned int RenderD3D3_GetDeviceCaps(struct RenderD3D3 *_this)
{
  signed int v1; // ebx@1

  D3DDEVICEDESC d3ddd1;
  /*struct
  {
   int v5; // [sp+Ch] [bp-1F8h]@1
   char _010[0xFC - 4];
  } local_00C;*/
  
  D3DDEVICEDESC d3ddd2;
  /*struct
  {
   int v5; // [sp+108h] [bp-FCh]@1
   int _10C[0x70 / 4];
   int v7; // [sp+17Ch] [bp-88h]@3
   int v8; // [sp+180h] [bp-84h]@9
   char _184[8];
   int v9; // [sp+18Ch] [bp-78h]@15
   char _190[0x74];
  } local_108;*/


 memset(&d3ddd2, 0, sizeof(D3DDEVICEDESC));
 d3ddd2.dwSize = sizeof(D3DDEVICEDESC);

 memset(&d3ddd1, 0, sizeof(D3DDEVICEDESC));
 d3ddd1.dwSize = sizeof(D3DDEVICEDESC);

 if (FAILED((_this->pDevice->lpVtbl->GetCaps)(_this->pDevice, &d3ddd2, &d3ddd1)))
   return 1;
 else
 {
  v1 = 0;

  if (~d3ddd2.dpcTriCaps.dwSrcBlendCaps & 0x10)
      v1 |= CAPS_FLAG0;
  if (~d3ddd2.dpcTriCaps.dwSrcBlendCaps & 0x02)
      v1 |= CAPS_FLAG1;
  if (~d3ddd2.dpcTriCaps.dwSrcBlendCaps & 0x01)
      v1 |= CAPS_FLAG2;
  if (~d3ddd2.dpcTriCaps.dwDestBlendCaps & 0x20)
      v1 |= CAPS_FLAG3;
  if (~d3ddd2.dpcTriCaps.dwDestBlendCaps & 0x02)
      v1 |= CAPS_FLAG4;
  if (~d3ddd2.dpcTriCaps.dwDestBlendCaps & 0x04)
      v1 |= CAPS_FLAG5;
  if (d3ddd2.dpcTriCaps.dwTextureCaps & 0x20)
      v1 |= CAPS_FLAG6;

  return v1;
 }
}



//----- (0049E5D4) --------------------------------------------------------
bool RenderD3D3_CreateTexture(struct RenderD3D3 *_this, unsigned int uTextureWidth, unsigned int uTextureHeight, IDirectDrawSurface4 **pOutSurface, IDirect3DTexture2 **pOutTexture, bool bAlphaChannel, bool a7, void *a8)
{
  int v8; // edx@4
  int v9; // edx@5
  int v10; // ebx@5
  int v11; // eax@5
  int v12; // edx@7

  DDSURFACEDESC2 ddsd;
  /*int Dst[0x7C/4]; // [sp+Ch] [bp-80h]@1
  int v15; // [sp+10h] [bp-7Ch]@1
  void *v16; // [sp+14h] [bp-78h]@1
  void *v17; // [sp+18h] [bp-74h]@1
  int v18; // [sp+24h] [bp-68h]@5
  int v19; // [sp+54h] [bp-38h]@12
  int v20; // [sp+58h] [bp-34h]@13
  int v21; // [sp+60h] [bp-2Ch]@12
  int v22; // [sp+64h] [bp-28h]@13
  int v23; // [sp+68h] [bp-24h]@13
  int v24; // [sp+6Ch] [bp-20h]@12
  int v25; // [sp+70h] [bp-1Ch]@13
  int (__stdcall *v26)(int, int, int, int); // [sp+74h] [bp-18h]@1
  int v27; // [sp+78h] [bp-14h]@1*/

 memset(&ddsd, 0, sizeof(DDSURFACEDESC2));
 ddsd.dwSize = sizeof(DDSURFACEDESC2);
 ddsd.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT | DDSD_PIXELFORMAT;
 ddsd.dwWidth = uTextureWidth;
 ddsd.dwHeight = uTextureHeight;
 ddsd.ddsCaps.dwCaps = DDSCAPS_TEXTURE;
 ddsd.ddsCaps.dwCaps2 = DDSCAPS2_TEXTUREMANAGE;
  if ( a7 )
  {
    if ( (signed int)uTextureHeight <= (signed int)uTextureWidth )
    {
      sub_49D700(uTextureHeight);
      v8 = v12 - sub_49D700(a8);
LABEL_8:
      ddsd.dwMipMapCount = v8;
      if ( !v8 )
        goto LABEL_12;
      goto LABEL_11;
    }
    if ( (signed int)uTextureWidth < (signed int)a8 )
    {
      v8 = sub_49D700(a8);
      goto LABEL_8;
    }
    v10 = sub_49D700(uTextureWidth);
    v11 = sub_49D700(a8);
    ddsd.dwMipMapCount = v10 - v11;
    if ( v10 == v11 )
    {
      ddsd.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT | DDSD_PIXELFORMAT;
      ddsd.ddsCaps.dwCaps = v9;
      goto LABEL_12;
    }
  }
  else
  {
    ddsd.dwMipMapCount = 1;
  }

LABEL_11:
  ddsd.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT | DDSD_PIXELFORMAT | DDSD_MIPMAPCOUNT;
  ddsd.ddsCaps.dwCaps = DDSCAPS_TEXTURE | DDSCAPS_COMPLEX | DDSCAPS_MIPMAP;

LABEL_12:
  //ddsd.ddpfPixelFormat.dwRGBBitCount = 16;
  ddsd.ddpfPixelFormat.dwSize = sizeof(DDPIXELFORMAT);
  ddsd.ddpfPixelFormat.dwRGBBitCount = 32;
  if (bAlphaChannel)
  {/*
   // A1R5G5B5
   ddsd.ddpfPixelFormat.dwFlags = DDPF_RGB | DDPF_ALPHAPIXELS;
   ddsd.ddpfPixelFormat.dwRBitMask = 0x7C00;
   ddsd.ddpfPixelFormat.dwGBitMask = 0x03E0;
   ddsd.ddpfPixelFormat.dwBBitMask = 0x001F;
   ddsd.ddpfPixelFormat.dwRGBAlphaBitMask = 0x8000;*/

   ddsd.ddpfPixelFormat.dwFlags = DDPF_RGB | DDPF_ALPHAPIXELS;
   ddsd.ddpfPixelFormat.dwRBitMask = 0x00FF0000;
   ddsd.ddpfPixelFormat.dwGBitMask = 0x0000FF00;
   ddsd.ddpfPixelFormat.dwBBitMask = 0x000000FF;
   ddsd.ddpfPixelFormat.dwRGBAlphaBitMask = 0xFF000000;
  }
  else
  {/*
   //   R5G6B5
   ddsd.ddpfPixelFormat.dwFlags = DDPF_RGB;
   ddsd.ddpfPixelFormat.dwRBitMask = 0xF800;
   ddsd.ddpfPixelFormat.dwGBitMask = 0x07E0;
   ddsd.ddpfPixelFormat.dwBBitMask = 0x001F;
   ddsd.ddpfPixelFormat.dwRGBAlphaBitMask = 0x0000;*/

   ddsd.ddpfPixelFormat.dwFlags = DDPF_RGB;
   ddsd.ddpfPixelFormat.dwRBitMask = 0x00FF0000;
   ddsd.ddpfPixelFormat.dwGBitMask = 0x0000FF00;
   ddsd.ddpfPixelFormat.dwBBitMask = 0x000000FF;
   ddsd.ddpfPixelFormat.dwRGBAlphaBitMask = 0x00000000;
  }
 if ((_this->pHostInterface->lpVtbl->CreateSurface)(_this->pHostInterface, &ddsd, pOutSurface, 0) != S_OK)
   return false;

 if (((*pOutSurface)->lpVtbl->QueryInterface)(*pOutSurface, &memory_4D8410.IID_IDirect3DTexture2, pOutTexture) != S_OK)
 {
    if (*pOutSurface)
    {
     ((*pOutSurface)->lpVtbl->Release)(*pOutSurface);
     *pOutSurface = 0;
    }
    return false;
 }
 return true;
}



//----- (0049E54D) --------------------------------------------------------
HRESULT RenderD3D3_Present(struct RenderD3D3 *_this, char a2)
{
  struct tagRECT Rect; // [sp+8h] [bp-28h]@4
  RECT src;
  int v9; // [sp+20h] [bp-10h]@1
  int v10; // [sp+24h] [bp-Ch]@1
  struct tagPOINT Point; // [sp+28h] [bp-8h]@4

  src.left = 0;
  src.top = 0;
  src.right = 640;
  src.bottom = 480;
  if (_this->bWindowMode || a2 )
  {
    GetClientRect(_this->hOutputWindow, &Rect);
    Point.y = 0;
    Point.x = 0;
    ClientToScreen(_this->hOutputWindow, &Point);
    OffsetRect(&Rect, Point.x, Point.y);
    return (_this->pFontBuffer->lpVtbl->Blt)(_this->pFontBuffer, &Rect, _this->pBackBuffer, &src, 0x1000000, 0);
  }
  else
   return (_this->pFontBuffer->lpVtbl->Flip)(_this->pFontBuffer, 0, 1);
}


//----- (004A597D) --------------------------------------------------------
char __cdecl sub_4A597D()
{
  int v1; // eax@4
  int v4; // edi@4
  int v5; // esi@4
  void *v7; // edi@7
  const void *v8; // esi@7
  signed int v9; // ebx@8
  int v10; // ecx@10
  int v11; // ebx@10
  int v12; // edi@10
  int v13; // esi@10
  int v14; // eax@10
  int v15; // eax@11
  int v16; // eax@13
  int v17; // eax@14
  int v18; // eax@16
  char v19; // zf@21
  int v20; // eax@22

  DDSURFACEDESC2 ddsd;
  /*int Dst; // [sp+Ch] [bp-98h]@3
  int v22; // [sp+1Ch] [bp-88h]@4
  int v23; // [sp+30h] [bp-74h]@4*/

  int v24; // [sp+88h] [bp-1Ch]@10
  int v25; // [sp+8Ch] [bp-18h]@10
  int v26; // [sp+90h] [bp-14h]@10
  int v27; // [sp+94h] [bp-10h]@10
  int v28; // [sp+98h] [bp-Ch]@4
  int v29; // [sp+9Ch] [bp-8h]@10
  int v30; // [sp+A0h] [bp-4h]@4
 int y;

 if (pD3DRenderer->bSceneBegun || !pD3DRenderer->dword_040110)
   return 0;

  memset(&ddsd, 0, sizeof(DDSURFACEDESC2));
  ddsd.dwSize = sizeof(DDSURFACEDESC2);
  if (!LockSurface_DDraw4(pD3DRenderer->pdds4_BackBuffer, &ddsd, 1))
    return 0;

  runtime_warning(screw it, some really weird working-surface-to-back-buffer update. for now make it plain and simple);
        memcpy(ddsd.lpSurface, pD3DRenderer->pTargetSurface, 640 * 480 * 4);
        (pD3DRenderer->pdds4_BackBuffer->lpVtbl->Unlock)(pD3DRenderer->pdds4_BackBuffer, 0);
        /*
        v1 = pD3DRenderer->pTargetSurface;
        v30 = ddsd.lpSurface;
        pD3DRenderer->dword_12983C = ddsd.lpSurface;
        v28 = pD3DRenderer->uTargetGMask | pD3DRenderer->uTargetBMask | ((pD3DRenderer->uTargetGMask | pD3DRenderer->uTargetBMask) << 16);
        pD3DRenderer->dword_129840 = pD3DRenderer->pTargetSurface;
        pD3DRenderer->dword_129838 = ddsd.lPitch / 4;
        v5 = pD3DRenderer->dword_129840;
        v4 = pD3DRenderer->dword_12983C;

        for (y = 0; y < 8; ++y)
        {
          memcpy(v4, v5, 640 * 4);
          v5 += pD3DRenderer->dword_129838 * 4;
          v4 += pD3DRenderer->dword_129838 * 4;
        }

        for (y = 8; y < 344 + 8; ++y)
        {
          *(int *)(v4 + 0) = *(int *)(v5 + 0);
          *(int *)(v4 + 4) = *(int *)(v5 + 4);

          v8 = (const void *)(v5 + 4);
          v7 = (void *)(v4 + 4);
          //*(_DWORD *)v7 = *(_DWORD *)v8;
          *(int *)(v4 + 8) = *(int *)(v5 + 8);
          *(int *)(v4 + 12) = *(int *)(v5 + 12);

          v8 = (char *)v8 + 4;
          v7 = (char *)v7 + 4;
          //*(_DWORD *)v7 = *(_DWORD *)v8;
          *(int *)(v4 + 16) = *(int *)(v5 + 16);
          *(int *)(v4 + 20) = *(int *)(v5 + 20);

          v8 = (char *)v8 + 4;
          v7 = (char *)v7 + 4;
          //*(_DWORD *)v7 = *(_DWORD *)v8;
          *(int *)(v4 + 24) = *(int *)(v5 + 24);
          *(int *)(v4 + 28) = *(int *)(v5 + 28);

          v7 = (char *)v7 + 924;
          v8 = (char *)v8 + 924;
          memcpy(v7, v8, 0x158);
          v5 = (int)((char *)v8 + 344);
          v4 = (int)((unsigned char *)v7 + v2 + 344);
        }

        v9 = 128;
        do
        {
          memcpy((void *)v4, (const void *)v5, 640 * 4);
          v5 += pD3DRenderer->dword_129838 * 4;
          v4 += pD3DRenderer->dword_129838 * 4;
          --v9;
        }
        while ( v9 );

        v29 = v1 + 4 * ((class28_global.dword_000010 >> 1) + 320 * class28_global.dword_000014);
        v27 = v30 + 4 * ((class28_global.dword_000010 >> 1) + (ddsd.lPitch >> 2) * class28_global.dword_000014);
        v14 = (class28_global.dword_000010 >> 1) - (class28_global.dword_000018 >> 1);
        v24 = (class28_global.dword_000018 >> 1) - (class28_global.dword_000010 >> 1);
        v26 = 4 * ((ddsd.lPitch >> 2) + v14);
        v25 = 4 * v14 + 1280;
        v30 = class28_global.dword_00001C - class28_global.dword_000014 + 1;
        v13 = v29;
        v12 = v27;
        v10 = (class28_global.dword_000018 >> 1) - (class28_global.dword_000010 >> 1);
        v11 = v28;
        while ( 1 )
        {
          v15 = *(_DWORD *)v13;
          v13 += 4;
          if ( v15 == v11 )
          {
            v12 += 4;
            --v10;
            if ( !v10 )
            {
LABEL_21:
              v13 += v25;
              v12 += v26;
              v10 = v24;
              v19 = v30-- == 1;
              if ( v19 )
              {
                v20 = (*(int (__stdcall **)(int, _DWORD))(*(_DWORD *)pD3DRenderer->pdds4_BackBuffer + 128))(pD3DRenderer->pdds4_BackBuffer, 0);
                return (unsigned int)CheckHRESULT(
                                       &v29,
                                       v20,
                                       "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\screen16blt.cpp",
                                       0x3F6u,
                                       0);
              }
            }
          }
          else
          {
            if ( (_WORD)v15 == (_WORD)v11 )
            {
              *(_DWORD *)v12 = *(_DWORD *)v12 & 0xFFFF | v15 & 0xFFFF0000;
              v12 += 4;
              --v10;
              if ( !v10 )
                goto LABEL_21;
            }
            else
            {
              compile_error;//v16 = __ROL__(v15, 16);
              if ( (_WORD)v16 == (_WORD)v11 )
              {
                compile_error;//v18 = __ROR__(v16, 16);
                *(_DWORD *)v12 = *(_DWORD *)v12 & 0xFFFF0000 | (unsigned __int16)v18;
                v12 += 4;
                --v10;
                if ( !v10 )
                  goto LABEL_21;
              }
              else
              {
                compile_error;//v17 = __ROR__(v16, 16);
                *(_DWORD *)v12 = v17;
                v12 += 4;
                --v10;
                if ( !v10 )
                  goto LABEL_21;
              }
            }
          }
        }*/
}



//----- (0049E4FC) --------------------------------------------------------
void RenderD3D3_ClearTarget(struct RenderD3D3 *_this, int a2, D3DCOLOR uClearColor, int a4, float a5)
{
 signed int v5; // esi@1
 D3DRECT d3drc;


 v5 = 0;
 if (a2)
   v5 = 1;
 if (a4)
   v5 |= 2;
 if (v5)
 {
  d3drc.x1 = 0;
  d3drc.y1 = 0;
  d3drc.x2 = 640;
  d3drc.y2 = 480;

  (_this->pViewport->lpVtbl->Clear2)(_this->pViewport, 1, &d3drc, v5, uClearColor, a5, 0);
 }
}