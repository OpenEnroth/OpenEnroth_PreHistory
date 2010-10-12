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

typedef struct BINK *HBINK;


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