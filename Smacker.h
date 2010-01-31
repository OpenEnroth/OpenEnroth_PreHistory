#include "defs.h"

void SMACKW32_DLL_Initialize();

struct SMACK
{
  unsigned int Version;           // SMK2 only right now
  unsigned int Width;             // Width (1 based, 640 for example)
  unsigned int Height;            // Height (1 based, 480 for example)
  unsigned int Frames;            // Number of frames (1 based, 100 = 100 frames)
  unsigned int MSPerFrame;        // Frame Rate
  unsigned int SmackerType;       // bit 0 set=ring frame
  unsigned int LargestInTrack[7]; // Largest single size for each track
  unsigned int tablesize;         // Size of the init tables
  unsigned int codesize;          // Compression info   
  unsigned int absize;            // ditto
  unsigned int detailsize;        // ditto
  unsigned int typesize;          // ditto
  unsigned int TrackType[7];      // high byte=0x80-Comp,0x40-PCM data,0x20-16 bit,0x10-stereo
  unsigned int extra;             // extra value (should be zero)
  unsigned int NewPalette;        // set to one if the palette changed
  unsigned char Palette[772];      // palette data
  unsigned int PalType;           // type of palette
  unsigned int FrameNum;          // Frame Number to be displayed
  unsigned int FrameSize;         // The current frame's size in bytes
  unsigned int SndSize;           // The current frame sound tracks' size in bytes
  int LastRectx;         // Rect set in from SmackToBufferRect (X coord)
  int LastRecty;         // Rect set in from SmackToBufferRect (Y coord)
  int LastRectw;         // Rect set in from SmackToBufferRect (Width)
  int LastRecth;         // Rect set in from SmackToBufferRect (Height)
  unsigned int OpenFlags;         // flags used on open
  unsigned int LeftOfs;           // Left Offset used in SmackTo
  unsigned int TopOfs;            // Top Offset used in SmackTo
  unsigned int LargestFrameSize;  // Largest frame size
  unsigned int Highest1SecRate;   // Highest 1 sec data rate
  unsigned int Highest1SecFrame;  // Highest 1 sec data rate starting frame
  unsigned int ReadError;         // Set to non-zero if a read error has ocurred
  unsigned int addr32;            // translated address for 16 bit interface
};

struct SMACKBLIT
{
  unsigned int    Flags;
  unsigned char  *Palette;
  unsigned int    PalType;
  unsigned short *SmoothTable;
  unsigned short *Conv8to16Table;
  unsigned int    whichmode;
  unsigned int    palindex;
  unsigned int    t16index;
  unsigned int    smoothindex;
  unsigned int    smoothtype;
  unsigned int    firstpalette;
};

typedef struct SMACK     *HSMACK;
typedef struct SMACKBLIT *HSMACKBLIT;



int __stdcall SmackSoundUseMSS(HDIGDRIVER hDrv);
unsigned int __stdcall SmackUseMMX(unsigned int flag);
HSMACK __stdcall SmackOpen(HANDLE hSourceFile, unsigned int uFlags, unsigned int uExtraBuffers);
HSMACKBLIT __stdcall SmackBlitOpen(unsigned int uSurfaceFormat);
void __stdcall SmackToBuffer(struct SmackMovieInfo *pMovie, unsigned int uX, unsigned int uY, unsigned int uPitch, unsigned int uHeight, void *pBuffer, unsigned int uFlags);


// sub_4D83C4: using guessed type int __stdcall SmackBufferOpen(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall SmackBufferOpen(long a1, long a2, long a3, long a4, long a5, long a6);

// sub_4D83C8: using guessed type int __fastcall SmackVolumePan(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __fastcall SmackVolumePan(long a1, long a2, long a3, long a4, long a5, long a6);

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
long __stdcall SmackWait(long a1);