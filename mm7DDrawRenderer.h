#include <stdio.h>
#include <windows.h>
#include <ddraw.h>

int __cdecl CheckIfDeviceSupportsGammaControl();
double __stdcall sub_44F377(DDGAMMARAMP *pddGammaRamp);

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
 int                         dword_000018;
 int                         dword_00001C;
 int                         dword_000020;
 int                         dword_000024;
 int                         dword_000028;

 unsigned short              array_00002C[65536]; //byte[?] @ 00002C

 int                         dword_04002C;
 int                         dword_040030;
 int                         dword_040034;
 int                        *pZBuffer;           // ptr @ 040038
 int                         dword_04003C;
 int                         dword_040040;
 int                         dword_040044;
 int                         dword_040048;
 int                         dword_04004C;
 HWND                        hWnd;               // ptr @ 040050
 int                         dword_040054;
 int                         dword_040058;
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
 int                         dword_0400E4;
 int                         dword_0400E8;
 int                         dword_0400EC;
 int                         dword_0400F0;
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

 char                        byte_103668[4];

 int                         dword_1036B8;
 int                         dword_1036BC;
 int               (__cdecl *pfn_1036C0)();
};
//int __thiscall sub_49E992(int this)
void CD3DRenderer_ctor(struct CD3DRenderer *_this);
//int __thiscall sub_49FFFB(int this, unsigned int a2);
int CD3DRenderer_Initialize(struct CD3DRenderer *_this, HWND hwnd);
//signed int __thiscall sub_49FDBF(int this)
int CD3DRenderer_Initialize_ZBuffer(struct CD3DRenderer *_this);
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
int sub_49FC37(struct CD3DRenderer *_this);
//int __thiscall sub_4A1814(void *this);
HRESULT CD3DRenderer_RestoreFrontBuffer(struct CD3DRenderer *_this);
//int __thiscall sub_4A194A(int this, int a2, int a3, int a4);
HRESULT CD3DRenderer_PresentBackBuffer(struct CD3DRenderer *_this, int a2, int a3, RECT *pRect);



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
#pragma pack(pop)