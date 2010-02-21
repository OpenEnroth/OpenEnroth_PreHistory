#include "Smacker.h"


int (__stdcall *smackw32_SmackSoundUseMSS)(HDIGDRIVER) = 0;
unsigned int (__stdcall *smackw32_SmackUseMMX)(unsigned int) = 0;
HSMACK (__stdcall *smackw32_SmackOpen)(HANDLE, unsigned int, unsigned int) = 0;
HSMACKBLIT (__stdcall *smackw32_SmackBlitOpen)(unsigned int) = 0;
void (__stdcall *smackw32_SmackToBuffer)(HSMACK, unsigned int, unsigned int, unsigned int, unsigned int, void *, unsigned int) = 0;
void (__stdcall *smackw32_SmackBlitSetPalette)(HSMACKBLIT, void *, unsigned int) = 0;
unsigned int (__stdcall *smackw32_SmackDoFrame)(HSMACK) = 0;
unsigned int (__stdcall *smackw32_SmackToBufferRect)(HSMACK, unsigned int) = 0;
void (__stdcall *smackw32_SmackBlit)(HSMACKBLIT, void *, unsigned int, unsigned int, unsigned int, void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int) = 0;
void (__stdcall *smackw32_SmackNextFrame)(HSMACK) = 0;
unsigned int (__stdcall *smackw32_SmackWait)(HSMACK) = 0;
unsigned int (__stdcall *smackw32_SmackSoundOnOff)(HSMACK, unsigned int) = 0;
void (__stdcall *smackw32_SmackClose)(HSMACK) = 0;
void (__stdcall *smackw32_SmackBufferClose)(HSMACKBUF) = 0;
void (__stdcall *smackw32_SmackBlitClose)(HSMACKBLIT) = 0;
void SMACKW32_DLL_Initialize()
{
 void *pDll = LoadLibraryW(L"SmackW32.dll");

 smackw32_SmackSoundUseMSS = GetProcAddress(pDll, "_SmackSoundUseMSS@4");
 smackw32_SmackUseMMX = GetProcAddress(pDll, "_SmackUseMMX@4");
 smackw32_SmackOpen = GetProcAddress(pDll, "_SmackOpen@12");
 smackw32_SmackBlitOpen = GetProcAddress(pDll, "_SmackBlitOpen@4");
 smackw32_SmackToBuffer = GetProcAddress(pDll, "_SmackToBuffer@28");
 smackw32_SmackBlitSetPalette = GetProcAddress(pDll, "_SmackBlitSetPalette@12");
 smackw32_SmackDoFrame = GetProcAddress(pDll, "_SmackDoFrame@4");
 smackw32_SmackToBufferRect = GetProcAddress(pDll, "_SmackToBufferRect@8");
 smackw32_SmackBlit = GetProcAddress(pDll, "_SmackBlit@44");
 smackw32_SmackNextFrame = GetProcAddress(pDll, "_SmackNextFrame@4");
 smackw32_SmackWait = GetProcAddress(pDll, "_SmackWait@4");
 smackw32_SmackSoundOnOff = GetProcAddress(pDll, "_SmackSoundOnOff@8");
 smackw32_SmackClose = GetProcAddress(pDll, "_SmackClose@4");
 smackw32_SmackBufferClose = GetProcAddress(pDll, "_SmackBufferClose@4");
 smackw32_SmackBlitClose = GetProcAddress(pDll, "_SmackBlitClose@4");
}






void __stdcall SmackBlitClose(HSMACKBLIT hBlit)
{
 (smackw32_SmackBlitClose)(hBlit);
}

void __stdcall SmackBufferClose(HSMACKBUF hBuf)
{
 (smackw32_SmackBufferClose)(hBuf);
}

void __stdcall SmackClose(HSMACK hSmack)
{
 (smackw32_SmackClose)(hSmack);
}

unsigned int __stdcall SmackSoundOnOff(HSMACK hSmack, unsigned int bOn)
{
 return (smackw32_SmackSoundOnOff)(hSmack, bOn);
}

unsigned int __stdcall SmackWait(HSMACK hSmack)
{
 return (smackw32_SmackWait)(hSmack);
}

void __stdcall SmackNextFrame(HSMACK hSmack)
{
 (smackw32_SmackNextFrame)(hSmack);
}

void __stdcall SmackBlit(HSMACKBLIT hBlit, void *pDest, unsigned int uDestPitch, unsigned int uDestX, unsigned int uDestY, void *pSrc, unsigned int uSrcPitch, unsigned int uSrcX, unsigned int uSrcY, unsigned int uSrcZ, unsigned int uSrcW)
{
 (smackw32_SmackBlit)(hBlit, pDest, uDestPitch, uDestX, uDestY, pSrc, uSrcPitch, uSrcX, uSrcY, uSrcZ, uSrcW);
}

unsigned int __stdcall SmackToBufferRect(HSMACK hSmack, unsigned int uSmackSurface)
{
 return (smackw32_SmackToBufferRect)(hSmack, uSmackSurface);
}

unsigned int __stdcall SmackDoFrame(HSMACK hSmack)
{
 return (smackw32_SmackDoFrame)(hSmack);
}

void __stdcall SmackBlitSetPalette(HSMACKBLIT hBlit, void *pPalette, unsigned int uPalType)
{
 (smackw32_SmackBlitSetPalette)(hBlit, pPalette, uPalType);
}

int __stdcall SmackSoundUseMSS(HDIGDRIVER hDrv)
{
 return (smackw32_SmackSoundUseMSS)(hDrv);
}

unsigned int __stdcall SmackUseMMX(unsigned int flag)
{
 return (smackw32_SmackUseMMX)(flag);
}

HSMACK __stdcall SmackOpen(HANDLE hSourceFile, unsigned int uFlags, unsigned int uExtraBuffers)
{
 return (smackw32_SmackOpen)(hSourceFile, uFlags, uExtraBuffers);
}

HSMACKBLIT __stdcall SmackBlitOpen(unsigned int uSurfaceFormat)
{
 return (smackw32_SmackBlitOpen)(uSurfaceFormat);
}

void __stdcall SmackToBuffer(HSMACK hSmack, unsigned int uX, unsigned int uY, unsigned int uPitch, unsigned int uHeight, void *pBuffer, unsigned int uFlags)
{
 (smackw32_SmackToBuffer)(hSmack, uX, uY, uPitch, uHeight, pBuffer, uFlags);
}




// sub_4D83C4: using guessed type int __stdcall SmackBufferOpen(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall SmackBufferOpen(long a1, long a2, long a3, long a4, long a5, long a6)
{
 __asm int 3
 return 0;
}

// sub_4D83C8: using guessed type int __fastcall SmackVolumePan(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __fastcall SmackVolumePan(long a1, long a2, long a3, long a4, long a5, long a6)
{
 __asm int 3
 return 0;
}

// sub_4D83B8: using guessed type int __stdcall SmackGoto(_DWORD, _DWORD);
int __stdcall SmackGoto(long a1, long a2)
{
 __asm int 3
 return 0;
}

// sub_4D83D0: using guessed type int __stdcall SmackBufferNewPalette(_DWORD, _DWORD, _DWORD);
int __stdcall SmackBufferNewPalette(long a1, long a2, long a3)
{
 __asm int 3
 return 0;
}

// sub_4D83D4: using guessed type int __stdcall SmackColorRemapWithTrans(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall SmackColorRemapWithTrans(long a1, long a2, long a3, long a4, long a5)
{
 __asm int 3
 return 0;
}

// sub_4D83DC: using guessed type int __stdcall SmackBlitClear(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall SmackBlitClear(long a1, long a2, long a3, long a4, long a5, long a6, long a7, long a8)
{
 __asm int 3
 return 0;
}