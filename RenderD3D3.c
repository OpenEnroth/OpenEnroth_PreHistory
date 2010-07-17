#include "RenderD3D3.h"



//----- (0049DE14) --------------------------------------------------------
bool RendererD3D3_Initialize(struct RendererD3D3 *_this, unsigned int uDeviceID, unsigned int bWindowMode, HWND hwnd)
{
  int v4; // esi@1
  int v7; // eax@11
  int v8; // eax@12
  int v9; // eax@16
  int v10; // eax@20
  int v11; // eax@20
  int v12; // ecx@20
  int v13; // eax@35
  int v14; // eax@37
  int v15; // eax@39
  int v16; // ecx@39
  int v17; // eax@54
  int v18; // edx@54
  int v19; // esi@63
  int v21; // edi@68
  int v22; // esi@68
  const char *v23; // [sp-4h] [bp-DCh]@9
  const char *v24; // [sp-4h] [bp-DCh]@13
  const char *v25; // [sp-4h] [bp-DCh]@19
  signed int v26; // [sp-4h] [bp-DCh]@30
  int v27; // [sp+Ch] [bp-CCh]@37
  int Dst; // [sp+1Ch] [bp-BCh]@11
  int v29; // [sp+20h] [bp-B8h]@11
  int v30; // [sp+24h] [bp-B4h]@16
  int v31; // [sp+28h] [bp-B0h]@16
  int v32; // [sp+30h] [bp-A8h]@35
  char v33; // [sp+64h] [bp-74h]@20
  int v34; // [sp+70h] [bp-68h]@12
  int v35; // [sp+84h] [bp-54h]@11
  int v36; // [sp+98h] [bp-40h]@28
  int v37; // [sp+A4h] [bp-34h]@54
  int v38; // [sp+A8h] [bp-30h]@54
  int v39; // [sp+ACh] [bp-2Ch]@54
  float v40; // [sp+B0h] [bp-28h]@28
  float v41; // [sp+B4h] [bp-24h]@28
  float v42; // [sp+B8h] [bp-20h]@28
  float v43; // [sp+BCh] [bp-1Ch]@28
  float v44; // [sp+C0h] [bp-18h]@28
  int v45; // [sp+C4h] [bp-14h]@18
  IDirectDraw *lpDD; // [sp+C8h] [bp-10h]@1
  int v48; // [sp+D0h] [bp-8h]@27
  int v49; // [sp+D4h] [bp-4h]@11
  int v50; // [sp+E0h] [bp+8h]@25
  int v51; // [sp+E4h] [bp+Ch]@16
  int v52; // [sp+E8h] [bp+10h]@20
 HRESULT hr;
 int v5, v47;

  v4 = _this;

 _this->bWindowMode = bWindowMode;
 _this->hOutputWindow = hwnd;

 if (DirectDrawCreate(_this->pAvailableDevices[uDeviceID].ptr_000020, &lpDD, 0) != S_OK)
 {
  wsprintfA(_this->pStatusMessage, "RendererD3D3::Initialize: DirectDrawCreate failed.");
  return false;
 }
 
 v5 = _this->pAvailableDevices;
 v47 = 40 * uDeviceID;

 hr = (lpDD->lpVtbl->QueryInterface)(lpDD, &memory_4D8410.IID_IDirectDraw4, &_this->pHostInterface);

 (lpDD->lpVtbl->Release)(lpDD);
 lpDD = 0;
 if (FAILED(hr))
 {
  wsprintfA(_this->pStatusMessage, "RendererD3D3::Initialize: no DirectDraw4.");

  return false;
 }

 if (bWindowMode && !_this->pAvailableDevices[uDeviceID].ptr_000020)
 {
  hr = (_this->pHostInterface->lpVtbl->SetCooperativeLevel)(_this->pHostInterface, hwnd, DDSCL_MULTITHREADED | DDSCL_NORMAL);

  if (FAILED(hr))
  {
LABEL_9:
      v23 = "RendererD3D3::Initialize: SetCooperativeLevel failed.";
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

  memset(&Dst, 0, 0x7Cu);
    v7 = _this->pHostInterface;
    Dst = 124;
    v49 = v4 + 48;
    v29 = 1;
    v35 = 512;
    if ( !(*(int (__stdcall **)(int, int *, int, _DWORD))(*(_DWORD *)v7 + 24))(v7, &Dst, v4 + 48, 0) )
    {
      v8 = _this->pHostInterface;
      Dst = 124;
      (*(void (__stdcall **)(int, int *))(*(_DWORD *)v8 + 48))(v8, &Dst);
      if ( v34 != 16 )
      {
        v24 = "RendererD3D3::Initialize: desktop isn't 16bit.";
        goto LABEL_14;
      }
      v9 = _this->pHostInterface;
      v51 = v4 + 44;
      v29 = 7;
      v35 = 8256;
      v31 = 640;
      v30 = 480;
      if ( (*(int (__stdcall **)(int, int *, int, _DWORD))(*(_DWORD *)v9 + 24))(v9, &Dst, v4 + 44, 0) )
      {
        v24 = "RendererD3D3::Initialize: failed to create back buffer.";
LABEL_14:
        wsprintfA(_this->pStatusMessage, v24);
        if ( *(_DWORD *)v49 )
        {
          (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v49 + 8))(*(_DWORD *)v49);
          *(_DWORD *)v49 = 0;
        }
        goto LABEL_65;
      }
      if ( (*(int (__stdcall **)(_DWORD, _DWORD, int *, _DWORD))(*(_DWORD *)_this->pHostInterface + 16))(_this->pHostInterface, 0, &v45, 0) )
      {
        v25 = "RendererD3D3::Initialize: failed to create clipper.";
        goto LABEL_45;
      }
      (*(void (__stdcall **)(int, _DWORD, int))(*(_DWORD *)v45 + 32))(v45, 0, hwnd);
      (*(void (__stdcall **)(_DWORD, int))(**(_DWORD **)v49 + 112))(*(_DWORD *)v49, v45);
      (*(void (__stdcall **)(int))(*(_DWORD *)v45 + 8))(v45);
      v10 = _this->pHostInterface;
      v45 = 0;
      v52 = v4 + 36;
      (**(void (__stdcall ***)(_DWORD, _DWORD, _DWORD))v10)(v10, 5085880, v4 + 36);
      v29 = 4103;
      v11 = *(_DWORD *)(v4 + 36);
      v12 = *(_DWORD *)(v4 + 28);
      v35 = 131072;
      v31 = 640;
      v30 = 480;
      if ( (*(int (__fastcall **)(int, int, _DWORD, _DWORD, int (__stdcall *)(void *, void *), char *))(*(_DWORD *)v11 + 40))(
             v52,
             v47,
             *(_DWORD *)v52,
             *(_DWORD *)(v12 + v47 + 12),
             sub_49D717,
             &v33) )
        goto LABEL_21;
      if ( uDeviceID == 2 || uDeviceID == 3 )
        BYTE1(v35) |= 8u;
      v50 = v4 + 52;
      if ( !(*(int (__stdcall **)(_DWORD, int *, int, _DWORD))(*(_DWORD *)_this->pHostInterface + 24))(_this->pHostInterface, &Dst, v4 + 52, 0) )
      {
        if ( !(*(int (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)v51 + 12))(*(_DWORD *)v51, *(_DWORD *)v50) )
        {
          v48 = v4 + 56;
          if ( !(*(int (__fastcall **)(int, int, _DWORD, _DWORD, _DWORD, int, _DWORD))(**(_DWORD **)v52 + 32))(
                  v52,
                  v47,
                  *(_DWORD *)v52,
                  *(_DWORD *)(*(_DWORD *)(v4 + 28) + v47 + 12),
                  *(_DWORD *)v51,
                  v4 + 56,
                  0) )
          {
            memset(&v36, 0, 0x2Cu);
            v41 = 2.0;
            v40 = 1.0;
            v42 = 2.0;
            v44 = 1.0;
            v43 = 0.0;
            goto LABEL_54;
          }
LABEL_51:
          wsprintfA(_this->pStatusMessage, "Init - Failed to create D3D device.\n");
          if ( *(_DWORD *)v52 )
          {
            (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v52 + 8))(*(_DWORD *)v52);
            *(_DWORD *)v52 = 0;
          }
          goto LABEL_59;
        }
LABEL_48:
        wsprintfA(_this->pStatusMessage, "Init - Failed to attach z-buffer to back buffer.\n");
        if ( *(_DWORD *)v50 )
        {
          (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v50 + 8))(*(_DWORD *)v50);
          *(_DWORD *)v50 = 0;
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
  memset(&Dst, 0, 0x7Cu);
  v13 = _this->pHostInterface;
  Dst = 124;
  v49 = v4 + 48;
  v29 = 33;
  v35 = 8728;
  v32 = 1;
  if ( (*(int (__stdcall **)(int, int *, int, _DWORD))(*(_DWORD *)v13 + 24))(v13, &Dst, v4 + 48, 0) )
    goto LABEL_36;
  v51 = v4 + 44;
  v14 = *(_DWORD *)v49;
  v27 = 4;
  v48 = (*(int (__stdcall **)(int, int *, int))(*(_DWORD *)v14 + 48))(v14, &v27, v4 + 44);
  v52 = v4 + 36;
  (**(void (__stdcall ***)(_DWORD, _DWORD, _DWORD))_this->pHostInterface)(_this->pHostInterface, 5085880, v4 + 36);
  if ( v48 )
  {
    v25 = "Init - Failed to get D3D interface.\n";
    goto LABEL_45;
  }
  v29 = 4103;
  v15 = *(_DWORD *)v52;
  v16 = *(_DWORD *)(v4 + 28);
  v35 = 131072;
  v31 = 640;
  v30 = 480;
  if ( (*(int (__fastcall **)(int, int, _DWORD, _DWORD, int (__stdcall *)(void *, void *), char *))(*(_DWORD *)v15 + 40))(
         v52,
         v47,
         *(_DWORD *)v52,
         *(_DWORD *)(v16 + v47 + 12),
         sub_49D717,
         &v33) )
  {
LABEL_21:
    v25 = "Init - Failed to enumerate Z buffer formats.\n";
    goto LABEL_45;
  }
  if ( uDeviceID == 2 || uDeviceID == 3 )
    BYTE1(v35) |= 8u;
  v50 = v4 + 52;
  if ( (*(int (__stdcall **)(_DWORD, int *, int, _DWORD))(*(_DWORD *)_this->pHostInterface + 24))(_this->pHostInterface, &Dst, v4 + 52, 0) )
  {
LABEL_44:
    v25 = "Init - Failed to create z-buffer.\n";
LABEL_45:
    wsprintfA(_this->pStatusMessage, v25);
    if ( *(_DWORD *)v51 )
    {
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v51 + 8))(*(_DWORD *)v51);
      *(_DWORD *)v51 = 0;
    }
LABEL_63:
    v19 = v49;
    if ( *(_DWORD *)v49 )
    {
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v49 + 8))(*(_DWORD *)v49);
      *(_DWORD *)v19 = 0;
    }
    goto LABEL_65;
  }
  if ( (*(int (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)v51 + 12))(*(_DWORD *)v51, *(_DWORD *)v50) )
    goto LABEL_48;
  v48 = v4 + 56;
  if ( (*(int (__fastcall **)(int, int, _DWORD, _DWORD, _DWORD, int, _DWORD))(**(_DWORD **)v52 + 32))(
         v52,
         v47,
         *(_DWORD *)v52,
         *(_DWORD *)(*(_DWORD *)(v4 + 28) + v47 + 12),
         *(_DWORD *)v51,
         v4 + 56,
         0) )
    goto LABEL_51;
  memset(&v36, 0, 0x2Cu);
  v41 = 2.0;
  v40 = 1.0;
  v42 = 2.0;
  v44 = 1.0;
LABEL_54:
  v36 = 44;
  v17 = *(_DWORD *)v52;
  v37 = 640;
  v38 = 480;
  v39 = -1082130432;
  v18 = *(_DWORD *)v17;
  v47 = v4 + 60;
  if ( (*(int (__stdcall **)(int, int, _DWORD))(v18 + 24))(v17, v4 + 60, 0) )
  {
    wsprintfA(_this->pStatusMessage, "Init - Failed to create viewport.\n");
    if ( *(_DWORD *)v48 )
    {
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v48 + 8))(*(_DWORD *)v48);
      *(_DWORD *)v48 = 0;
    }
    if ( *(_DWORD *)v52 )
    {
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v52 + 8))(*(_DWORD *)v52);
      *(_DWORD *)v52 = 0;
    }
LABEL_59:
    if ( *(_DWORD *)v50 )
    {
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v50 + 8))(*(_DWORD *)v50);
      *(_DWORD *)v50 = 0;
    }
LABEL_61:
    if ( *(_DWORD *)v51 )
    {
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v51 + 8))(*(_DWORD *)v51);
      *(_DWORD *)v51 = 0;
    }
    goto LABEL_63;
  }
  v21 = v48;
  v22 = v47;
  (*(void (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)v48 + 20))(*(_DWORD *)v48, *(_DWORD *)v47);
  (*(void (__stdcall **)(_DWORD, int *))(**(_DWORD **)v22 + 68))(*(_DWORD *)v22, &v36);
  (*(void (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)v21 + 48))(*(_DWORD *)v21, *(_DWORD *)v22);

  return true;
}

//----- (0049DC58) --------------------------------------------------------
void RendererD3D3_FindAvailableDevices(struct RendererD3D3 *_this)
{
 _this->pHostInterface = 0;

 _this->dword_000024 = 0;
 _this->dword_000028 = 0;
 _this->dword_000030 = 0;
 _this->dword_000034 = 0;
 _this->dword_000038 = 0;
 _this->dword_00003C = 0;
 _this->dword_000040 = 1;
 _this->dword_000044 = 10;

 _this->pAvailableDevices = malloc(4 * sizeof(struct RendererD3D3_DeviceDescription));
 memset(_this->pAvailableDevices, 0, 4 * sizeof(struct RendererD3D3_DeviceDescription));

 DirectDrawEnumerateA((LPDDENUMCALLBACKA)(DDrawEnumCallback), _this->pAvailableDevices);
}




struct D3DRenderer_stru2
{
 struct RendererD3D3_DeviceDescription *pDeviceDesc;
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
