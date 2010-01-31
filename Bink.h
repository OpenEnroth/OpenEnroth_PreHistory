#include "defs.h"

void BINKW32_DLL_Initialize();



int __stdcall BinkDDSurfaceType(struct IDirectDrawSurface *);
int __stdcall BinkSetSoundSystem(void *pSoundSystem, HDIGDRIVER hDrv);
int __stdcall BinkOpenMiles(int);



int __stdcall BinkBufferSetOffset(long a1, long a2, long a3);
int __stdcall BinkBufferSetScale(long a1, long a2, long a3);
int __stdcall BinkOpen(long a1, long a2);
int __stdcall BinkNextFrame(long a1);
int __stdcall BinkDoFrame(long a1);
int __stdcall BinkGoto(long a1, long a2, long a3);
int __stdcall BinkPause(long a1, long a2);
int __stdcall BinkClose(long a1);
int __stdcall BinkCopyToBuffer(long a1, long a2, long a3, long a4, long a5, long a6, long a7);
int __stdcall BinkGetRects(long a1, long a2);
long __stdcall BinkWait(long a1);