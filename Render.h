#pragma once
#include "defs.h"

#include <stdio.h>
#include <windows.h>

#include "legacy dx\ddraw.h"

double __stdcall sub_44F377(DDGAMMARAMP *pddGammaRamp);
bool __stdcall LockSurface_DDraw4(struct IDirectDrawSurface4 *, DDSURFACEDESC2 *, unsigned int uLockFlags);
int __stdcall LockSurface_DDraw2(struct IDirectDrawSurface2 *, DDSURFACEDESC *, unsigned int uLockFlags);
void *__stdcall BltToFrontBuffer(RECT *pDestRect, IDirectDrawSurface *pddsSrc, RECT *pSrcRect, unsigned int uFlags);

bool __stdcall DDrawEnumCallback(GUID *pGUID, const char *pDriverDescription, const char *pDriverName, struct RenderD3D3_DeviceDescription *a4);
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
//int __thiscall sub_452347(int _this);
void Render_HWLContainer_ctor(struct Render_HWLContainer *_this);
//signed int __thiscall sub_45237F(void *_this, const char *Filename);
int Render_HWLContainer_LoadHWLHeaders(struct Render_HWLContainer *_this, const char *pFilename);
//void *__thiscall sub_4524D8(void *_this, int a2, int a3);
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



struct RenderVertex
{
 float x; // float @ 000000   looks like world coordinates
 float z; // float @ 000004
 float y; // float @ 000008
 float flt_00000C;
 float flt_000010;
 float flt_000014;
 float flt_000018;  // value lies between pOldViewport->uGameX and pOldViewport->uGameZ  screen-space transformed x
 float flt_00001C; //  value lies between pOldViewport->uGameY and pOldViewport->uGameW  screen-space transformed y
 float flt_000020;
 float u;          // float @ 000024   looks like texture coordinates
 float v;          // float @ 000028
 float flt_00002C;
};
//sizeof == 30


struct RenderBillboard
{
 int                 dword_000000;
 int                 dword_000004;
 char                byte_000008[8];
 int                 dword_000010;  // zbuffer value for the sprite
 int                 dword_000014;
 unsigned short      uHardwareSpriteID; // word @ 000018
 short               word_00001A;
 short               word_00001C;
 short               word_00001E;
 short               word_000020;
 short               word_000022;
 short               word_000024;
 short               word_000026;
 short               word_000028;
 short               word_00002A;
 int                 dword_00002C; // MonsterDescription::dword_000008   tint color?
 struct SpriteFrame *pSpriteFrame;  // dword  @ 000030
};
//sizeof = 34






struct BaseRender
{
 BaseRender();

 virtual unsigned int Initialize(class OSWindow *pTargetWindow) = 0;

 virtual unsigned int IsGammaControlSupported() = 0;

 virtual unsigned int BeginScene() = 0;
 virtual unsigned int EndScene() = 0;
 virtual unsigned int Present() = 0;

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
 struct IDirectDrawSurface4  *dword_040098;
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
 unsigned int                uD3D3SceneBegun;     // dword @ 04010C
 int                         dword_040110;

 struct Render_HWLContainer struct_040114;  // d3dbitmap
 struct Render_HWLContainer struct_0A1BAC;  // d3dsprite

 unsigned int                bUseColoredLights;               // dword @ 103644
 unsigned int                bRequiredTextureStagesAvailable; // dword @ 103648
 unsigned int                bTinting;             // dword @ 10364C
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
 
 unsigned int uNumBillboardsToDraw; // dword @ 129830

 int dword_129838;  // dst pitch
 int dword_12983C;  // dst buffer
 int dword_129840;  // src buffer

 //addons
 OSWindow *pTargetWindow;
};
//signed int __thiscall sub_49FDBF(int _this)
void Render_Initialize_ZBuffer(struct BaseRender *_this);
//signed int __thiscall sub_49FFD7(int _this);
bool Render_sub_49FFD7(struct BaseRender *_this);
//int __thiscall sub_4A10E4(void *_this)
int Render_CreateDirectDraw(struct BaseRender *_this);
//void *__thiscall sub_4A1169(int _this, int a2, char a3)
void *Render_SetCooperativeLevel(struct BaseRender *_this, HWND hwnd, int bFullscreen);
//void *__thiscall sub_4A11C6(int _this, int a2, int a3, int a4);
void *Render_SetDisplayMode(struct BaseRender *_this, unsigned int uWidth, unsigned int uHeight, unsigned int uBPP);
//void *__thiscall sub_4A139A(int _this);
void *Render_CreatePrimarySurface(struct BaseRender *_this);
//sub_4A15D8
HRESULT Render_GetPrimarySurfacePixelFormat(struct BaseRender *_this, DDPIXELFORMAT *pddpf);
//void *__thiscall sub_4A0EB6(void *_this);
void *Render_sub_4A0EB6(struct BaseRender *_this);
//int __thiscall sub_49EBF1(int _this);
int Render_sub_49EBF1(struct BaseRender *_this);
//signed int __thiscall sub_49ED18(int _this)
int Render_ClearBackBufferAndPresent(struct BaseRender *_this);
//int __thiscall sub_4A1814(void *_this);
HRESULT Render_RestoreFrontBuffer(struct BaseRender *_this);
//int __thiscall sub_4A194A(int _this, int a2, int a3, int a4);
HRESULT Render_PresentBackBuffer(struct BaseRender *_this, int a2, int a3, RECT *pRect);
//int __thiscall sub_49FBCD(int _this, int a2);
void Render_ClearTarget(struct BaseRender *_this, unsigned int uColor);
//signed int __thiscall sub_4A1605(void *_this, int a2, int a3);
int Render_LockBackBuffer(struct BaseRender *_this, void **ppOutSurfacePtr, unsigned int *pOutSurfaceWidth);
//void *__thiscall sub_4A16E1(int _this);
void *Render_UnlockBackBuffer(struct BaseRender *_this);
//signed int __thiscall sub_4A172E(void *_this, int a2, int a3);
int Render_LockFrontBuffer(struct BaseRender *_this, void **ppOutSurfacePtr, unsigned int *pOutSurfaceWidth);
//void *__thiscall sub_4A17C7(int _this);
void *Render_UnlockFrontBuffer(struct BaseRender *_this);
//void __thiscall sub_4A5BE3(int _this, int a2, int a3, int a4);
void Render_DrawRGBTexture(struct BaseRender *_this, unsigned int uX, unsigned int uY, struct RGBTexture *pClass33);
//custom
void Render_DrawRGBTexture_New(struct BaseRender *_this, unsigned int uX, unsigned int uY, unsigned int uTextureID);
//void __thiscall sub_4A6C4F(int _this, int a2, int a3, int a4, int a5, int a6, int a7, __int16 a8, __int16 a9);
void Render_DrawText(struct BaseRender *_this, unsigned int uOutX, unsigned int uOutY, unsigned char *pFontPixels, unsigned int uCharWidth, unsigned int uCharHeight, unsigned short *pFontPalette, unsigned int uMainColor, unsigned int uShadowColor);
//void __thiscall sub_4A5BB6(int _this);
void Render_Reset2DClippingRect(struct BaseRender *_this);
//int __thiscall sub_4A5B81(int _this, int a2, int a3, int a4, int a5);
void Render_Set2DClippingRect(struct BaseRender *_this, unsigned int uX, unsigned int uY, unsigned int uZ, unsigned int uW);
//void __thiscall sub_4A5EB2(int _this, int a2, int a3, int a4);
void Render_DrawIndexedTexture(struct BaseRender *_this, unsigned int uX, unsigned int uY, cTexture *pTexture);
void Render_DrawIndexedTextureHandle(struct BaseRender *_this, unsigned int uX, unsigned int uY, unsigned int uTextureID);
//void __thiscall sub_4A6274(int _this, int a2, int a3, int a4);
void Render_DrawTransparentTexture(struct BaseRender *_this, unsigned int uX, unsigned int uY, cTexture *pTexture);
//int __thiscall sub_4A0E97(int _this, int a2, int a3, int a4, int a5);
void Render_sub_4A0E97(struct BaseRender *_this, int a2, int a3, int a4, int a5);
//signed int __thiscall sub_4A0E80(int _this, int a2, int a3);
void Render_ClearZBuffer(struct BaseRender *_this, int a2, int a3);
//void *__thiscall sub_4A121C(void *_this);
void *Render_CreateSurface(struct BaseRender *_this);
//void *__thiscall sub_4A12CD(void *_this);
void *Render_CreateWndSurface(struct BaseRender *_this);
//void *__thiscall sub_4A14F4(int _this, int a2);
void *Render_CreateClipper(struct BaseRender *_this, HWND ClipWnd);
void *Render_PresentRegion(struct BaseRender *_this, RECT *pDestRect, RECT *pSrcRect);
//char __thiscall sub_4A0BEE(int _this, int a2, int a3, int a4, int a5, __int16 a6);
char Render_FillRect(struct BaseRender *_this, unsigned int uX, unsigned int uY, unsigned int uZ, unsigned int uW, unsigned int uColor);
//signed int __cdecl sub_49E79F();
bool Render_ValidateTextureStages();
//void *__thiscall sub_4A5048(int _this, int a2);
bool Render_MoveHWSpriteToVideoMemory(struct BaseRender *_this, struct HardwareSprite *pSprite);
//void __thiscall sub_4A2DA3(int _this, signed int a2, int a3, int a4);
void Render_DrawSomeFan(struct BaseRender *_this, unsigned int uNumVertices, struct struct8 *a3, struct IDirect3DTexture2 *pTexture);
// void __userpurge sub_4A6D87(int a1<ecx>, int a2<ebx>, int a3, int a4, unsigned int a5, int a6, __int16 a7);
void Render_FillRect2(struct BaseRender *_this, unsigned int uX, unsigned int uY, unsigned int a5, int a6, unsigned int a7);
//int sub_49FE05(int, void *_this)
void sub_49FE05(struct BaseRender *pD3DRenderer);
//void __thiscall sub_4A2050(int _this, signed int a2, int a3, int a4, int a5);
void Render_DrawPolygon(struct BaseRender *_this, unsigned int uNumVertices, struct struct8 *a3, struct class51_stru2 *a4, struct IDirect3DTexture2 *pTexture);
//void sub_4A26BC(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
void Render_DrawTerrainPolygon(struct BaseRender *_this, struct RenderVertex *a2, unsigned int uNumVertices, struct struct8 *a4, struct IDirect3DTexture2 *pTexture, bool a6, bool a7);
//void __thiscall sub_4A4023(int _this, int a2, int a3, int a4, int a5);
void Render_BillboardTransform(struct BaseRender *_this, struct Render_BillboardTransform_stru0 *a2, struct HardwareSprite *pSprite, int a4, struct RenderBillboard *pBillboard);

void Render_DrawTransparentRect(struct BaseRender *_this, unsigned int uOutX, unsigned int uOutY,
                                      unsigned int uSrcX, unsigned int uSrcY, unsigned int uSrcWidth, unsigned int uSrcHeight,
                                      cTexture *pTexture);
unsigned int Render_MoveToGPU(struct BaseRender *_this, unsigned int uWidth, unsigned int uHeight, unsigned int *pData, struct IDirectDrawSurface4 **pOutSurface, struct IDirect3DTexture2 **pOutTexture);




struct RenderOpenGL: public BaseRender
{
 RenderOpenGL();

 virtual unsigned int Initialize(OSWindow *pTargetWindow);

 virtual unsigned int IsGammaControlSupported();
 
 virtual unsigned int BeginScene();
 virtual unsigned int EndScene();
 virtual unsigned int Present();

 HDC hTargetWindowDC;
};


struct RenderDirect3D3: public BaseRender
{
 RenderDirect3D3();

 virtual unsigned int Initialize(OSWindow *pTargetWindow);

 virtual unsigned int IsGammaControlSupported();

 virtual unsigned int BeginScene();
 virtual unsigned int EndScene();
 virtual unsigned int Present();
};

















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
//int __thiscall sub_44F215(int _this);
struct CGammaController *CGammaController_ctor(struct CGammaController *_this);
//void *__thiscall GammaController_sub_44F4D9(int _this, float a2);
void *GammaController_sub_44F4D9(struct CGammaController *_this, float a2);
//void __thiscall sub_44F24B(int _this, int a2);
void CGammaController_InitializeFromSurface(struct CGammaController *_this, struct IDirectDrawSurface4 *pdds);
//void *__thiscall sub_44F324(int _this);
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
//int __thiscall sub_40D73D(int _this);
int RGBTexture_ctor(struct RGBTexture *_this);
//signed int __thiscall sub_40F414(void *_this, const char *Str1, int a3);
int RGBTexture_Load(struct RGBTexture *_this, const char *pContainerName, int a3);
//signed int __thiscall sub_40F414(void *_this, const char *Str1, int a3);
#ifndef OLD_CODE
int RGBTexture_Load_New(struct RGBTexture *_this, const wchar_t *pTextureName);
#endif
//signed int __thiscall sub_40F037(void *_this, void *Src, int a3, int a4)
int RGBTexture_DecodePCX(struct RGBTexture *_this, unsigned char *pPCXData, unsigned short *pOutBuffer, unsigned int uWidth);















struct Render_BillboardTransform_stru0
{
 unsigned int *pDestSurface; // dword @ 000000
 int          *pDestZBuffer; // dword @ 000004
 int dword_000008;
 int dword_00000C;
 union
 {
  struct
  {
   int dword_000010;
   int dword_000014;
  };
  struct
  {
   short word_000010;
   short word_000012;
   short word_000014;
   short word_000016;
  };
 };
 char byte_000018[8];
 int dword_000020;  // palette ptr
 int dword_000024;
 union
 {
  int    dword_000028;
  struct
  {
   short word_000028;
   short word_00002A;
  };
 };
 int          dword_00002C; // flags
 unsigned int uDestSurfacePitch; // dword @ 000030
 unsigned int uGameX;            // dword @ 000034
 unsigned int uGameY;            // dword @ 000038
 unsigned int uGameZ;            // dword @ 00003C
 unsigned int uGameW;            // dword @ 000040
 int          dword_000044;
 int          dword_000048;
 int          dword_00004C; // tint color?
};
//sizeof ~ 50


#pragma pack(pop)