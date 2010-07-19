#pragma once
#include "defs.h"

#include <stdio.h>
#include <windows.h>

#include "legacy dx\ddraw.h"

int __cdecl CheckIfDeviceSupportsGammaControl();
double __stdcall sub_44F377(DDGAMMARAMP *pddGammaRamp);
bool __stdcall LockSurface_DDraw4(struct IDirectDrawSurface4 *, DDSURFACEDESC2 *, unsigned int uLockFlags);
int __stdcall LockSurface_DDraw2(struct IDirectDrawSurface2 *, DDSURFACEDESC *, unsigned int uLockFlags);
void *__stdcall BltToFrontBuffer(RECT *pDestRect, IDirectDrawSurface *pddsSrc, RECT *pSrcRect, unsigned int uFlags);

bool __stdcall DDrawEnumCallback(GUID *pGUID, const char *pDriverDescription, const char *pDriverName, unsigned char *a4);
bool __stdcall DDrawEnumDisplayModesCallback(DDSURFACEDESC2 *pDDSurfaceDesc, unsigned short *a2);

#pragma pack(push, 1)

//class30
struct Render_HWLContainer
{
 FILE *pHWLFile;
 int   dword_000004;
 int   dword_000008;
 int   uNumElements;
 unsigned char *pSriteNames[50000];        // dword[50000] @ 000010
 unsigned int   pSpriteFileOffsets[50000]; // dword[50000] @ 030D50
 int   dword_061A90;
 int   dword_061A94;
};
//sizeof = 61A98
//int __thiscall sub_452347(int this);
void Render_HWLContainer_ctor(struct Render_HWLContainer *_this);
//signed int __thiscall sub_45237F(void *this, const char *Filename);
int Render_HWLContainer_LoadHWLHeaders(struct Render_HWLContainer *_this, const char *pFilename);
//void *__thiscall sub_4524D8(void *this, int a2, int a3);
struct Render_HWLBitmap *Render_LoadHWLTexture(struct Render_HWLContainer *_this, unsigned char *a2, int a3);


struct Render_HWLBitmap
{
 int dword_000000;
 int dword_000004;
 int dword_000008;
 int dword_00000C;
 int dword_000010;
 int dword_000014;
 int dword_000018;
 int dword_00001C;
 int dword_000020;
 int dword_000024;
 unsigned int uWidth;  // dword @ 000028
 unsigned int uHeight; // dword @ 00002C
 int dword_000030;
 int dword_000034;
 unsigned short *pPixels;  // dword @ 000038

 unsigned int *pTruecolorPixels; // new
};
//sizeof == 3C



struct Render
{
 unsigned int                 bUseDirect3D;            // dword @ 000000
 unsigned int                 bStartInWindow;          // dword @ 000004
 unsigned int                 uDesiredDirect3DDevice;  // dword @ 000008   device idx we desired
 unsigned int                 uAcquiredDirect3DDevice; // dword @ 00000C   device idx we were able to get
 int                          dword_000010;
 int                          dword_000014;
 int                          dword_000018; // related to currently locked surface pitch
 int                          dword_00001C; // ->
 int                          dword_000020;   // some kind
 int                          dword_000024;   // of clipping rect
 int                          dword_000028; // <-
 unsigned short               array_00002C[65536]; //byte[?] @ 00002C
 unsigned short               array_02002C[65536]; //byte[?] @ 02002C
 int                          dword_04002C;
 int                          dword_040030;
 int                         *pActiveZBuffer;     // ptr @ 040034
 int                         *pDefaultZBuffer;    // ptr @ 040038
 int                          dword_04003C;
 int                          dword_040040;
 int                          dword_040044;
 int                          dword_040048;
 int                          dword_04004C;
 HWND                         hWnd;               // ptr @ 040050
 int                          dword_040054;
 int                          dword_040058;       //maybe windowed flag
 int                          dword_04005C[11];   // for struct align ?
 struct RenderD3D3           *pRenderD3D3;        // dword @ 040088
 struct IDirectDraw4         *pdd4;               // ptr   @ 04008C
 struct IDirectDrawSurface4  *pdds4_FrontBuffer;  // ptr   @ 040090
 struct IDirectDrawSurface4  *pdds4_BackBuffer;   // ptr   @ 040094
 int                          dword_040098;
 struct IDirectDraw2         *pdd2;               // ptr   @ 04009C
 struct IDirectDrawSurface2  *pdds2_FrontBuffer;  // ptr   @ 0400A0
 struct IDirectDrawSurface2  *pdds2_BackBuffer;   // ptr   @ 0400A4
 int                          dword_0400A8;
 DDPIXELFORMAT                ddpfPrimarySurface; // struct[32] @ 0400AC

 unsigned int                uNumTargetRBits;    // dword @ 0400CC
 unsigned int                uNumTargetGBits;    // dword @ 0400D0
 unsigned int                uNumTargetBBits;    // dword @ 0400D4
 unsigned int                uTargetRMask;       // dword @ 0400D8
 unsigned int                uTargetGMask;       // dword @ 0400DC
 unsigned int                uTargetBMask;       // dword @ 0400E0
 unsigned int                bSceneBegun;        // dword @ 0400E4
 int                         ptr_0400E8;
 unsigned int               *pTargetSurface;      // ptr   @ 0400EC
 unsigned int                uTargetSurfacePitch; // dword @ 0400F0
 unsigned int                uClipRectY;          // dword @ 0400F4
 unsigned int                uClipRectX;          // dword @ 0400F8
 unsigned int                uClipRectW;          // dword @ 0400FC
 unsigned int                uClipRectZ;          // dword @ 040100
 int                         dword_040104;
 int                         dword_040108;
 int                         dword_04010C;
 int                         dword_040110;

 struct Render_HWLContainer struct_040114;  // d3dbitmap
 struct Render_HWLContainer struct_0A1BAC;  // d3dsprite

 unsigned int                bUseColoredLights;               // dword @ 103644
 unsigned int                bRequiredTextureStagesAvailable; // dword @ 103648
 int                         dword_10364C;
 unsigned int                uLevelOfDetail;       // dword @ 103650
 unsigned int                uMaxDeviceTextureDim; // dword @ 103654
 unsigned int                uMinDeviceTextureDim; // dword @ 103658
 int                         dword_10365C;
 unsigned int                bUsingSpecular;       // dword @ 103660

 char                        byte_103668[4];

 struct IDirectDrawSurface4 *ptr_1036B0;
 struct IDirect3DTexture2   *ptr_1036B4;
 int                         dword_1036B8;
 int                         dword_1036BC;
 int               (__cdecl *pfn_1036C0)();
 
 int dword_129830;

 int dword_129838;  // dst pitch
 int dword_12983C;  // dst buffer
 int dword_129840;  // src buffer
};
//int __thiscall sub_49E992(int this)
void Render_ctor(struct Render *_this);
//int __thiscall sub_49FFFB(int this, unsigned int a2);
int Render_Initialize(struct Render *_this, HWND hwnd);
//int __thiscall sub_4A05F3
int Render_InitWindowed(struct Render *_this, HWND hwnd);
//signed int __thiscall sub_49FDBF(int this)
void Render_Initialize_ZBuffer(struct Render *_this);
//signed int __thiscall sub_49FFD7(int this);
bool Render_sub_49FFD7(struct Render *_this);
//int __thiscall sub_4A10E4(void *this)
int Render_CreateDirectDraw(struct Render *_this);
//void *__thiscall sub_4A1169(int this, int a2, char a3)
void *Render_SetCooperativeLevel(struct Render *_this, HWND hwnd, int bFullscreen);
//void *__thiscall sub_4A11C6(int this, int a2, int a3, int a4);
void *Render_SetDisplayMode(struct Render *_this, unsigned int uWidth, unsigned int uHeight, unsigned int uBPP);
//void *__thiscall sub_4A139A(int this);
void *Render_CreatePrimarySurface(struct Render *_this);
//sub_4A15D8
HRESULT Render_GetPrimarySurfacePixelFormat(struct Render *_this, DDPIXELFORMAT *pddpf);
//void *__thiscall sub_4A0EB6(void *this);
void *Render_sub_4A0EB6(struct Render *_this);
//int __thiscall sub_49EBF1(int this);
int Render_sub_49EBF1(struct Render *_this);
//signed int __thiscall sub_49ED18(int this)
int Render_ClearBackBufferAndPresent(struct Render *_this);
//signed int __thiscall sub_49FC37(int this);
int Render_Present(struct Render *_this);
//int __thiscall sub_4A1814(void *this);
HRESULT Render_RestoreFrontBuffer(struct Render *_this);
//int __thiscall sub_4A194A(int this, int a2, int a3, int a4);
HRESULT Render_PresentBackBuffer(struct Render *_this, int a2, int a3, RECT *pRect);
//char __thiscall sub_4A51CB(int this)
unsigned int Render_BeginScene(struct Render *_this);
//int __thiscall sub_49FBCD(int this, int a2);
void Render_ClearTarget(struct Render *_this, int a2);
//signed int __thiscall sub_4A1605(void *this, int a2, int a3);
int Render_LockBackBuffer(struct Render *_this, void **ppOutSurfacePtr, unsigned int *pOutSurfaceWidth);
//void *__thiscall sub_4A527D(int this);
HRESULT Render_EndScene(struct Render *_this);
//void *__thiscall sub_4A16E1(int this);
void *Render_UnlockBackBuffer(struct Render *_this);
//signed int __thiscall sub_4A172E(void *this, int a2, int a3);
int Render_LockFrontBuffer(struct Render *_this, void **ppOutSurfacePtr, unsigned int *pOutSurfaceWidth);
//void *__thiscall sub_4A17C7(int this);
void *Render_UnlockFrontBuffer(struct Render *_this);
//void __thiscall sub_4A5BE3(int this, int a2, int a3, int a4);
void Render_DrawRGBTexture(struct Render *_this, unsigned int uX, unsigned int uY, struct RGBTexture *pClass33);
//custom
void Render_DrawRGBTexture_New(struct Render *_this, unsigned int uX, unsigned int uY, unsigned int uTextureID);
//void __thiscall sub_4A6C4F(int this, int a2, int a3, int a4, int a5, int a6, int a7, __int16 a8, __int16 a9);
void Render_DrawText(struct Render *_this, unsigned int uOutX, unsigned int uOutY, unsigned char *pFontPixels, unsigned int uCharWidth, unsigned int uCharHeight, unsigned short *pFontPalette, unsigned int uMainColor, unsigned int uShadowColor);
//void __thiscall sub_4A5BB6(int this);
void Render_Reset2DClippingRect(struct Render *_this);
//int __thiscall sub_4A5B81(int this, int a2, int a3, int a4, int a5);
void Render_Set2DClippingRect(struct Render *_this, int a2, int a3, int a4, int a5);
//void __thiscall sub_4A5EB2(int this, int a2, int a3, int a4);
void Render_DrawIndexedTexture(struct Render *_this, unsigned int uX, unsigned int uY, struct class18 *pTexture);
void Render_DrawIndexedTextureHandle(struct Render *_this, unsigned int uX, unsigned int uY, unsigned int uTextureID);
//void __thiscall sub_4A6274(int this, int a2, int a3, int a4);
void Render_DrawTransparentTexture(struct Render *_this, unsigned int uX, unsigned int uY, struct class18 *pTexture);
//int __thiscall sub_4A0E97(int this, int a2, int a3, int a4, int a5);
void Render_sub_4A0E97(struct Render *_this, int a2, int a3, int a4, int a5);
//signed int __thiscall sub_4A0E80(int this, int a2, int a3);
void Render_ClearZBuffer(struct Render *_this, int a2, int a3);
//int __thiscall sub_4A1EB6(int this);
void Render_BeginScene2(struct Render *_this);
//int __thiscall sub_4A1FE1(int this);
void Render_sub_4A1FE1_MaybeRenderSpecialEffects(struct Render *_this);
//void *__thiscall sub_4A121C(void *this);
void *Render_CreateSurface(struct Render *_this);
//void *__thiscall sub_4A12CD(void *this);
void *Render_CreateWndSurface(struct Render *_this);
//void *__thiscall sub_4A14F4(int this, int a2);
void *Render_CreateClipper(struct Render *_this, HWND ClipWnd);
void *Render_PresentRegion(struct Render *_this, RECT *pDestRect, RECT *pSrcRect);
//char __thiscall sub_4A0BEE(int this, int a2, int a3, int a4, int a5, __int16 a6);
char Render_FillRect(struct Render *_this, int a2, int a3, int a4, int a5, unsigned int uColor);
//signed int __cdecl sub_49E79F();
bool Render_ValidateTextureStages();
//void *__thiscall sub_4A5048(int this, int a2);
bool Render_MoveHWSpriteToVideoMemory(struct Render *_this, struct HardwareSprite *pSprite);
//void __thiscall sub_4A2DA3(int this, signed int a2, int a3, int a4);
void Render_DrawSomeFan(struct Render *_this, unsigned int uNumVertices, int a3, struct IDirect3DTexture2 *pTexture);

void Render_DrawTransparentRect(struct Render *_this, unsigned int uOutX, unsigned int uOutY,
                                      unsigned int uSrcX, unsigned int uSrcY, unsigned int uSrcWidth, unsigned int uSrcHeight,
                                      struct class18 *pTexture);
bool Render_MoveToGPU(struct Render *_this, unsigned int uWidth, unsigned int uHeight, unsigned int *pData, struct IDirectDrawSurface4 **pOutSurface, struct IDirect3DTexture2 **pOutTexture);

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
//signed int __thiscall sub_40F414(void *this, const char *Str1, int a3);
int RGBTexture_Load_New(struct RGBTexture *_this, const wchar_t *pTextureName);
//signed int __thiscall sub_40F037(void *this, void *Src, int a3, int a4)
int RGBTexture_DecodePCX(struct RGBTexture *_this, void *Src, void *a3, unsigned int uWidth);


#pragma pack(pop)