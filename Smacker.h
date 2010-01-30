#include "defs.h"

void SMACKW32_DLL_Initialize();



// sub_4D8408: using guessed type int __stdcall SmackSoundUseMSS(_DWORD);
int __stdcall SmackSoundUseMSS(HDIGDRIVER hDrv);



// sub_4D83CC: using guessed type int __stdcall SmackOpen(_DWORD, _DWORD, _DWORD);
int __stdcall SmackOpen(long a1, long a2, long a3);

// sub_4D83C4: using guessed type int __stdcall SmackBufferOpen(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall SmackBufferOpen(long a1, long a2, long a3, long a4, long a5, long a6);

// sub_4D83C8: using guessed type int __fastcall SmackVolumePan(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __fastcall SmackVolumePan(long a1, long a2, long a3, long a4, long a5, long a6);

// sub_4D8400: using guessed type int __stdcall SmackToBuffer(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall SmackToBuffer(long a1, long a2, long a3, long a4, long a5, long a6, long a7);

// sub_4D83C0: using guessed type int __stdcall SmackBlitOpen(_DWORD);
int __stdcall SmackBlitOpen(long a1);

// sub_4D83B8: using guessed type int __stdcall SmackGoto(_DWORD, _DWORD);
int __stdcall SmackGoto(long a1, long a2);

// sub_4D83E4: using guessed type int __stdcall SmackDoFrame(_DWORD);
int __stdcall SmackDoFrame(long a1);

// sub_4D83E8: using guessed type int __stdcall SmackNextFrame(_DWORD);
int __stdcall SmackNextFrame(long a1);

// sub_4D83D0: using guessed type int __stdcall SmackBufferNewPalette(_DWORD, _DWORD, _DWORD);
int __stdcall SmackBufferNewPalette(long a1, long a2, long a3);

// sub_4D83D4: using guessed type int __stdcall SmackColorRemapWithTrans(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall SmackColorRemapWithTrans(long a1, long a2, long a3, long a4, long a5);

// sub_4D83D8: using guessed type int __stdcall SmackBlitSetPalette(_DWORD, _DWORD, _DWORD);
int __stdcall SmackBlitSetPalette(long a1, long a2, long a3);

// sub_4D83DC: using guessed type int __stdcall SmackBlitClear(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall SmackBlitClear(long a1, long a2, long a3, long a4, long a5, long a6, long a7, long a8);

// sub_4D83E0: using guessed type int __stdcall SmackToBufferRect(_DWORD, _DWORD);
int __stdcall SmackToBufferRect(long a1, long a2);

// sub_4D8404: using guessed type int __stdcall SmackBlit(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall SmackBlit(long a1, long a2, long a3, long a4, long a5, long a6, long a7, long a8, long a9, long a10, long a11);

// sub_4D83EC: using guessed type int __stdcall SmackSoundOnOff(_DWORD, _DWORD);
int __stdcall SmackSoundOnOff(long a1, long a2);

// sub_4D83F0: using guessed type int __stdcall SmackClose(_DWORD);
int __stdcall SmackClose(long a1);

// sub_4D83F4: using guessed type int __stdcall SmackBufferClose(_DWORD);
int __stdcall SmackBufferClose(long a1);

// sub_4D83F8: using guessed type int __stdcall SmackBlitClose(_DWORD);
int __stdcall SmackBlitClose(long a1);

// sub_??????
long __stdcall SmackUseMMX(long a1);

// sub_??????
long __stdcall SmackWait(long a1);