#include "Smacker.h"


int (__stdcall *smackw32_SmackSoundUseMSS)(HDIGDRIVER) = 0;
unsigned int (__stdcall *smackw32_SmackUseMMX)(unsigned int) = 0;
HSMACK (__stdcall *smackw32_SmackOpen)(HANDLE, unsigned int, unsigned int) = 0;
HSMACKBLIT (__stdcall *smackw32_SmackBlitOpen)(unsigned int) = 0;
void (__stdcall *smackw32_SmackToBuffer)(struct SmackMovieInfo *, unsigned int, unsigned int, unsigned int, unsigned int, void *, unsigned int) = 0;
void SMACKW32_DLL_Initialize()
{
 void *pDll = LoadLibraryW(L"SmackW32.dll");

 smackw32_SmackSoundUseMSS = GetProcAddress(pDll, "_SmackSoundUseMSS@4");
 smackw32_SmackUseMMX = GetProcAddress(pDll, "_SmackUseMMX@4");
 smackw32_SmackOpen = GetProcAddress(pDll, "_SmackOpen@12");
 smackw32_SmackBlitOpen = GetProcAddress(pDll, "_SmackBlitOpen@4");
 smackw32_SmackToBuffer = GetProcAddress(pDll, "_SmackToBuffer@28");
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

void __stdcall SmackToBuffer(struct SmackMovieInfo *pMovie, unsigned int uX, unsigned int uY, unsigned int uPitch, unsigned int uHeight, void *pBuffer, unsigned int uFlags)
{
 (smackw32_SmackToBuffer)(pMovie, uX, uY, uPitch, uHeight, pBuffer, uFlags);
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

// sub_4D83E4: using guessed type int __stdcall SmackDoFrame(_DWORD);
int __stdcall SmackDoFrame(long a1)
{
 __asm int 3
 return 0;
}

// sub_4D83E8: using guessed type int __stdcall SmackNextFrame(_DWORD);
int __stdcall SmackNextFrame(long a1)
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

// sub_4D83D8: using guessed type int __stdcall SmackBlitSetPalette(_DWORD, _DWORD, _DWORD);
int __stdcall SmackBlitSetPalette(long a1, long a2, long a3)
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

// sub_4D83E0: using guessed type int __stdcall SmackToBufferRect(_DWORD, _DWORD);
int __stdcall SmackToBufferRect(long a1, long a2)
{
 __asm int 3
 return 0;
}

// sub_4D8404: using guessed type int __stdcall SmackBlit(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall SmackBlit(long a1, long a2, long a3, long a4, long a5, long a6, long a7, long a8, long a9, long a10, long a11)
{
 __asm int 3
 return 0;
}

// sub_4D83EC: using guessed type int __stdcall SmackSoundOnOff(_DWORD, _DWORD);
int __stdcall SmackSoundOnOff(long a1, long a2)
{
 __asm int 3
 return 0;
}

// sub_4D83F0: using guessed type int __stdcall SmackClose(_DWORD);
int __stdcall SmackClose(long a1)
{
 __asm int 3
 return 0;
}

// sub_4D83F4: using guessed type int __stdcall SmackBufferClose(_DWORD);
int __stdcall SmackBufferClose(long a1)
{
 __asm int 3
 return 0;
}

// sub_4D83F8: using guessed type int __stdcall SmackBlitClose(_DWORD);
int __stdcall SmackBlitClose(long a1)
{
 __asm int 3
 return 0;
}

// sub_??????
long __stdcall SmackWait(long a1)
{
 __asm int 3
 return 0;
}