#pragma once
#include <stdio.h>
#include <windows.h>
#include <ddraw.h>

int __cdecl CheckIfDeviceSupportsGammaControl();
double __stdcall sub_44F377(DDGAMMARAMP *pddGammaRamp);
int __stdcall LockSurface_DDraw4(struct IDirectDrawSurface4 *, DDSURFACEDESC2 *, unsigned int uLockFlags);
int __stdcall LockSurface_DDraw2(struct IDirectDrawSurface2 *, DDSURFACEDESC *, unsigned int uLockFlags);
void *__stdcall BltToFrontBuffer(RECT *pDestRect, IDirectDrawSurface *pddsSrc, RECT *pSrcRect, unsigned int uFlags);


#pragma pack(push, 1)

//class30
struct CD3DRenderer_HWLContainer
{
 FILE *pHWLFile;
 int   dword_000004;
 int   dword_000008;
 int   uNumElements;
 unsigned char *array_000010[50000];
 int   array_030D50[50000];
 int   dword_061A90;
 int   dword_061A94;
};
//sizeof = 61A98
//int __thiscall sub_452347(int this);
void CD3DRenderer_HWLContainer_ctor(struct CD3DRenderer_HWLContainer *_this);
//signed int __thiscall sub_45237F(void *this, const char *Filename);
int CD3DRenderer_HWLContainer_LoadHWLHeaders(struct CD3DRenderer_HWLContainer *_this, const char *pFilename);

struct CD3DRenderer
{
 unsigned int                bUseDirect3D;       // dword @ 000000
 unsigned int                bStartInWindow;     // dword @ 000004
 unsigned int                bUseDirect3DDevice; // dword @ 000008
 int                         dword_00000C;
 int                         dword_000010;
 int                         dword_000014;
 int                         dword_000018; // related to currently locked surface pitch
 int                         dword_00001C;
 int                         dword_000020;
 int                         dword_000024;
 int                         dword_000028;

 unsigned short              array_00002C[65536]; //byte[?] @ 00002C

 int                         dword_04002C;
 int                         dword_040030;
 int                        *pActiveZBuffer;     // ptr @ 040034
 int                        *pDefaultZBuffer;    // ptr @ 040038
 int                         dword_04003C;
 int                         dword_040040;
 int                         dword_040044;
 int                         dword_040048;
 int                         dword_04004C;
 HWND                        hWnd;               // ptr @ 040050
 int                         dword_040054;
 int                         dword_040058;       //maybe windowed flag
 int                         dword_040088;
 struct IDirectDraw4        *pdd4;               // ptr @ 04008C
 struct IDirectDrawSurface4 *pdds4_FrontBuffer;  // ptr @ 040090
 struct IDirectDrawSurface4 *pdds4_BackBuffer;   // ptr @ 040094
 int                         dword_040098;
 struct IDirectDraw2        *pdd2;               // ptr @ 04009C
 struct IDirectDrawSurface2 *pdds2_FrontBuffer;  // ptr @ 0400A0
 struct IDirectDrawSurface2 *pdds2_BackBuffer;   // ptr @ 0400A4
 int                         dword_0400A8;
 DDPIXELFORMAT               ddpfPrimarySurface; // struct[32] @ 0400AC

 int                         dword_0400CC;
 int                         dword_0400D0;
 int                         dword_0400D4;
 int                         dword_0400D8;
 int                         dword_0400DC;
 int                         dword_0400E0;
 unsigned int                bSceneBegun; // dword @ 0400E4
 int                         dword_0400E8;

 unsigned short             *pTargetSurface;      // ptr @ 0400EC
 unsigned int                uTargetSurfacePitch; // dword @ 0400F0

 int                         dword_0400F4;
 int                         dword_0400F8;
 int                         dword_0400FC;
 int                         dword_040100;
 int                         dword_040104;
 int                         dword_040108;
 int                         dword_04010C;
 int                         dword_040110;

 struct CD3DRenderer_HWLContainer struct_040114;
 struct CD3DRenderer_HWLContainer struct_0A1BAC;

 unsigned int                bUseColoredLights; // dword @ 103644
 int                         dword_103648;
 int                         dword_10364C;
 unsigned int                uLevelOfDetail;    // dword @ 103650

 int                         dword_103660;

 char                        byte_103668[4];

 int                         dword_1036B8;
 int                         dword_1036BC;
 int               (__cdecl *pfn_1036C0)();
};
//int __thiscall sub_49E992(int this)
void CD3DRenderer_ctor(struct CD3DRenderer *_this);
//int __thiscall sub_49FFFB(int this, unsigned int a2);
int CD3DRenderer_Initialize(struct CD3DRenderer *_this, HWND hwnd);
int CD3DRenderer_InitWnd(struct CD3DRenderer *_this, HWND hwnd);

//signed int __thiscall sub_49FDBF(int this)
void CD3DRenderer_Initialize_ZBuffer(struct CD3DRenderer *_this);
//int __thiscall sub_4A10E4(void *this)
int CD3DRenderer_CreateDirectDraw(struct CD3DRenderer *_this);
//void *__thiscall sub_4A1169(int this, int a2, char a3)
void *CD3DRenderer_SetCooperativeLevel(struct CD3DRenderer *_this, HWND hwnd, int bFullscreen);
//void *__thiscall sub_4A11C6(int this, int a2, int a3, int a4);
void *CD3DRenderer_SetDisplayMode(struct CD3DRenderer *_this, unsigned int uWidth, unsigned int uHeight, unsigned int uBPP);
//void *__thiscall sub_4A139A(int this);
void *CD3DRenderer_CreatePrimarySurface(struct CD3DRenderer *_this);
//sub_4A15D8
HRESULT CD3DRenderer_GetPrimarySurfacePixelFormat(struct CD3DRenderer *_this, DDPIXELFORMAT *pddpf);
//void *__thiscall sub_4A0EB6(void *this);
void *CD3DRenderer_sub_4A0EB6(struct CD3DRenderer *_this);
//int __thiscall sub_49EBF1(int this);
int CD3DRenderer_sub_49EBF1(struct CD3DRenderer *_this);
//signed int __thiscall sub_49ED18(int this)
int CD3DRenderer_ClearBackBufferAndPresent(struct CD3DRenderer *_this);
//signed int __thiscall sub_49FC37(int this);
int CD3DRenderer_Present(struct CD3DRenderer *_this);
//int __thiscall sub_4A1814(void *this);
HRESULT CD3DRenderer_RestoreFrontBuffer(struct CD3DRenderer *_this);
//int __thiscall sub_4A194A(int this, int a2, int a3, int a4);
HRESULT CD3DRenderer_PresentBackBuffer(struct CD3DRenderer *_this, int a2, int a3, RECT *pRect);
//char __thiscall sub_4A51CB(int this)
unsigned int CD3DRenderer_BeginScene(struct CD3DRenderer *_this);
//int __thiscall sub_49FBCD(int this, int a2);
int sub_49FBCD(struct CD3DRenderer *_this, int a2);
//signed int __thiscall sub_4A1605(void *this, int a2, int a3);
int CD3DRenderer_LockBackBuffer(struct CD3DRenderer *_this, void **ppOutSurfacePtr, unsigned int *pOutSurfaceWidth);
//void *__thiscall sub_4A527D(int this);
HRESULT CD3DRenderer_EndScene(struct CD3DRenderer *_this);
//void *__thiscall sub_4A16E1(int this);
void *CD3DRenderer_UnlockBackBuffer(struct CD3DRenderer *_this);
//signed int __thiscall sub_4A172E(void *this, int a2, int a3);
int CD3DRenderer_LockFrontBuffer(struct CD3DRenderer *_this, void **ppOutSurfacePtr, unsigned int *pOutSurfaceWidth);
//void *__thiscall sub_4A17C7(int this);
void *CD3DRenderer_UnlockFrontBuffer(struct CD3DRenderer *_this);
//void __thiscall sub_4A5BE3(int this, int a2, int a3, int a4);
void CD3DRenderer_DrawRGBTexture(struct CD3DRenderer *_this, unsigned int uX, unsigned int uY, struct class33 *pClass33);
//void __thiscall sub_4A6C4F(int this, int a2, int a3, int a4, int a5, int a6, int a7, __int16 a8, __int16 a9);
void sub_4A6C4F(struct CD3DRenderer *_this, int a2, int a3, int a4, int a5, int a6, unsigned short *a7, unsigned int a8, unsigned int a9);
//void __thiscall sub_4A5BB6(int this);
void CD3DRenderer_sub_4A5BB6(struct CD3DRenderer *_this);
//int __thiscall sub_4A5B81(int this, int a2, int a3, int a4, int a5);
int sub_4A5B81(struct CD3DRenderer *_this, int a2, int a3, int a4, int a5);
//void __thiscall sub_4A5EB2(int this, int a2, int a3, int a4);
void CD3DRenderer_DrawIndexedTexture(struct CD3DRenderer *_this, unsigned int uX, unsigned int uY, struct class18 *pTexture);
//void __thiscall sub_4A6274(int this, int a2, int a3, int a4);
void CD3DRenderer_DrawTransparentTexture(struct CD3DRenderer *_this, unsigned int uX, unsigned int uY, struct class18 *pTexture);
//int __thiscall sub_4A0E97(int this, int a2, int a3, int a4, int a5);
void CD3DRenderer_sub_4A0E97(struct CD3DRenderer *_this, int a2, int a3, int a4, int a5);
//void __thiscall sub_4A6AB1(int this, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
void sub_4A6AB1(struct CD3DRenderer *_this, unsigned int uX, unsigned int uY, unsigned char *pData, int a5, int a6, int a7, int a8);
//signed int __thiscall sub_4A0E80(int this, int a2, int a3);
void CD3DRenderer_ClearZBuffer(struct CD3DRenderer *_this, int a2, int a3);
//int __thiscall sub_4A1EB6(int this);
void *sub_4A1EB6(struct CD3DRenderer *_this);
//int __thiscall sub_4A1FE1(int this);
void CD3DRenderer_sub_4A1FE1_MaybeRenderSpecialEffects(struct CD3DRenderer *_this);
//void *__thiscall sub_4A121C(void *this);
void* CD3DRenderer_CreateSurface(struct CD3DRenderer *_this);
//void *__thiscall sub_4A12CD(void *this);
void* CD3DRenderer_CreateWndSurface(struct CD3DRenderer *_this);
//void *__thiscall sub_4A14F4(int this, int a2);
void* CD3DRenderer_CreateClipper(struct CD3DRenderer *_this, HWND ClipWnd);
void* CD3DRenderer_Blt(struct CD3DRenderer *_this, RECT *pDestRect, RECT *pSrcRect);

//class15
struct CGammaController
{
 int   dword_000000;
 struct IDirectDrawSurface4     *pdds4;        // ptr @ 000004
 struct IDirectDrawGammaControl *pddgc;        // ptr @ 000008
 DDGAMMARAMP                     ddGammaRamp;  // struct @ 00000C
 DDGAMMARAMP                     ddGammaRamp2; //struct @ 00060C
 float                           flt_000C0C;
};
//sizeof = 0C10
//int __thiscall sub_44F215(int this);
struct CGammaController *CGammaController_ctor(struct CGammaController *_this);
//void *__thiscall sub_44F4D9(int this, float a2);
void *sub_44F4D9(struct class15 *_this, float a2);
//void __thiscall sub_44F24B(int this, int a2);
void CGammaController_InitializeFromSurface(struct class15 *_this, struct IDirectDrawSurface4 *pdds);
//void *__thiscall sub_44F324(int this);
void *CGammaController_InitializeGammaRamp(struct CGammaController *_this);






//class33
struct RGBTexture
{
 int dword_000000;
 int dword_000004;
 int dword_000008;
 int dword_00000C;
 unsigned int uNumPixels; // dword @ 000010
 short uWidth;  // word @ 000014
 short uHeight;  // word @ 000016
 short word_000018;
 short word_00001A;
 short word_00001C;
 short word_00001E;
 short word_000020;
 short word_000022;
 unsigned int *pPixels; // ptr @ 000024
};
//sizeof = 28
//int __thiscall sub_40D73D(int this);
int RGBTexture_ctor(struct RGBTexture *_this);
//signed int __thiscall sub_40F414(void *this, const char *Str1, int a3);
int RGBTexture_Load(struct RGBTexture *_this, const char *pContainerName, int a3);
//signed int __thiscall sub_40F037(void *this, void *Src, int a3, int a4)
int RGBTexture_DecodePCX(struct RGBTexture *_this, void *Src, void *a3, unsigned int uWidth);
unsigned int RGBTexture_LoadFromCBM(struct RGBTexture *_this, const char *pFilename);


#pragma pack(pop)