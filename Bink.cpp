#include "Bink.h"

int (__stdcall *binkw32_BinkDDSurfaceType)(struct IDirectDrawSurface *) = 0;
int (__stdcall *binkw32_BinkSetSoundSystem)(void *, HDIGDRIVER) = 0;
int (__stdcall *binkw32_BinkOpenMiles)(int) = 0;
HBINK (__stdcall *binkw32_BinkOpen)(void *, unsigned int) = 0;
int (__stdcall *binkw32_BinkWait)(HBINK) = 0;
int (__stdcall *binkw32_BinkDoFrame)(HBINK) = 0;
int (__stdcall *binkw32_BinkNextFrame)(HBINK) = 0;
int (__stdcall *binkw32_BinkGetRects)(HBINK, unsigned int) = 0;
int (__stdcall *binkw32_BinkCopyToBuffer)(HBINK, void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int) = 0;
int (__stdcall *binkw32_BinkPause)(HBINK, int) = 0;
int (__stdcall *binkw32_BinkClose)(HBINK) = 0;
int (__stdcall *binkw32_BinkBufferSetOffset)(void *, int, int) = 0;
int (__stdcall *binkw32_BinkBufferSetScale)(void *, unsigned int, unsigned int) = 0;
void BINKW32_DLL_Initialize()
{
 HMODULE pDll = LoadLibraryW(L"BinkW32.dll");

 binkw32_BinkDDSurfaceType = (int (__stdcall *)(struct IDirectDrawSurface *))GetProcAddress(pDll, "_BinkDDSurfaceType@4");
 binkw32_BinkSetSoundSystem = (int (__stdcall *)(void *, HDIGDRIVER))GetProcAddress(pDll, "_BinkSetSoundSystem@8");
 binkw32_BinkOpenMiles = (int (__stdcall *)(int))GetProcAddress(pDll, "_BinkOpenMiles@4");
 binkw32_BinkOpen = (HBINK (__stdcall *)(void *, unsigned int))GetProcAddress(pDll, "_BinkOpen@8");
 binkw32_BinkWait = (int (__stdcall *)(HBINK))GetProcAddress(pDll, "_BinkWait@4");
 binkw32_BinkBufferSetOffset = (int (__stdcall *)(void *, int, int))GetProcAddress(pDll, "_BinkBufferSetOffset@12");
 binkw32_BinkBufferSetScale = (int (__stdcall *)(void *, unsigned int, unsigned int))GetProcAddress(pDll, "_BinkBufferSetScale@12");
 binkw32_BinkDoFrame = (int (__stdcall *)(HBINK))GetProcAddress(pDll, "_BinkDoFrame@4");
 binkw32_BinkNextFrame = (int (__stdcall *)(HBINK))GetProcAddress(pDll, "_BinkNextFrame@4");
 binkw32_BinkGetRects = (int (__stdcall *)(HBINK, unsigned int))GetProcAddress(pDll, "_BinkGetRects@8");
 binkw32_BinkCopyToBuffer = (int (__stdcall *)(HBINK, void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))GetProcAddress(pDll, "_BinkCopyToBuffer@28");
 binkw32_BinkPause = (int (__stdcall *)(HBINK, int))GetProcAddress(pDll, "_BinkPause@8");
 binkw32_BinkClose = (int (__stdcall *)(HBINK))GetProcAddress(pDll, "_BinkClose@4");
}


int __stdcall BinkPause(HBINK hBink, int bPause)
{
 return (binkw32_BinkPause)(hBink, bPause);
}

int __stdcall BinkClose(HBINK hBink)
{
 return (binkw32_BinkClose)(hBink);
}

int __stdcall BinkGetRects(HBINK hBink, unsigned int uFlags)
{
 return (binkw32_BinkGetRects)(hBink, uFlags);
}

int __stdcall BinkCopyToBuffer(HBINK hBink, void *pBuffer, unsigned int lPitch, unsigned int unk, unsigned int uX, unsigned int uY, unsigned int uFlags)
{
 return (binkw32_BinkCopyToBuffer)(hBink, pBuffer, lPitch, unk, uX, uY, uFlags);
}

int __stdcall BinkDoFrame(HBINK hBink)
{
 return (binkw32_BinkDoFrame)(hBink);
}

int __stdcall BinkNextFrame(HBINK hBink)
{
 return (binkw32_BinkNextFrame)(hBink);
}

HBINK __stdcall BinkOpen(void *hFileHandle, unsigned int uFlags)
{
 return (binkw32_BinkOpen)(hFileHandle, uFlags);
}

int __stdcall BinkOpenMiles(int unk)
{
 return (binkw32_BinkOpenMiles)(unk);
}

int __stdcall BinkWait(HBINK hBink)
{
 return (binkw32_BinkWait)(hBink);
}



int __stdcall BinkBufferSetOffset(void *pStruct, int b, int c)
{
 return (binkw32_BinkBufferSetOffset)(pStruct, b, c);
}

int __stdcall BinkBufferSetScale(void *pStruct, unsigned int uWidth, unsigned int uHeight)
{
 return (binkw32_BinkBufferSetScale)(pStruct, uWidth, uHeight);
}

int __stdcall BinkDDSurfaceType(struct IDirectDrawSurface *pDDS)
{
 return (binkw32_BinkDDSurfaceType)(pDDS);
}

int __stdcall BinkSetSoundSystem(void *pSoundSystem, HDIGDRIVER hDrv)
{
 return (binkw32_BinkSetSoundSystem)(pSoundSystem, hDrv);
}






int __stdcall BinkGoto(long a1, long a2, long a3)
{
 __asm int 3
 return 0;
}