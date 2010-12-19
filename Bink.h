#include "defs.h"

void BINKW32_DLL_Initialize();

struct BINK
{
 unsigned int Width;
 unsigned int Height;
 unsigned int Frames;
 unsigned int CurrentFrame;
 unsigned int Data1;
 unsigned int FrameRate;
 unsigned int Array[3];
 unsigned int Flags;
};

struct BINKBUF
{
 unsigned int               uWidth; // dword @ 000000
 unsigned int               uHeight; // dword @ 000004
 unsigned int               dword_000008;
 unsigned int               dword_00000C;
 unsigned int               uBinkDDSurfaceType; // dword @ 000010
 void                      *pDDrawSurfaceData;  // dword @ 000014
 unsigned int               uDDrawSurfacePitch; // dword @ 000018
 unsigned int               dword_00001C;
 unsigned int               dword_000020;
 unsigned int               dword_000024;
 unsigned int               dword_000028;
 unsigned int               dword_00002C;
 unsigned int               dword_000030;
 unsigned int               dword_000034;
 unsigned int               dword_000038;
 unsigned int               dword_00003C;
 unsigned int               dword_000040;
 unsigned int               dword_000044;
 struct IDirectDrawSurface *pTargetDDrawSurface; // dword @ 000048
 unsigned int               dword_00004C;
 unsigned int               uRectX; // dword @ 000050
 unsigned int               uRectY; // dword @ 000054
 unsigned int               hWnd;
 unsigned int               dword_00005C;
 unsigned int               dword_000060;
 unsigned int               dword_000064;
 unsigned int               dword_000068;
 unsigned int               dword_00006C;
 void                      *pDDrawSurfaceData_;  // dword @ 000070
 unsigned int               dword_000074;
 unsigned int               dword_000078;
};

typedef struct BINK    *HBINK;
typedef struct BINKBUF *HBINKBUF;


int __stdcall BinkDDSurfaceType(struct IDirectDrawSurface *);
int __stdcall BinkSetSoundSystem(void *pSoundSystem, HDIGDRIVER hDrv);
int __stdcall BinkOpenMiles(int);
HBINK __stdcall BinkOpen(void *hFileHandle, unsigned int uFlags);
int __stdcall BinkWait(HBINK);
int __stdcall BinkDoFrame(HBINK);
int __stdcall BinkNextFrame(HBINK);
int __stdcall BinkGetRects(HBINK hBink, unsigned int uFlags);
int __stdcall BinkCopyToBuffer(HBINK hBink, void *pBuffer, unsigned int lPitch, unsigned int unk, unsigned int uX, unsigned int uY, unsigned int uFlags);
int __stdcall BinkPause(HBINK, int bPause);
int __stdcall BinkClose(HBINK);

int __stdcall BinkBufferSetOffset(void *, int, int);
int __stdcall BinkBufferSetScale(void *, unsigned int uWidth, unsigned int uHeight);






int __stdcall BinkGoto(long a1, long a2, long a3);