#pragma once


struct SpawnPointMM6
{
 int            sPosX;       // dword @ 000000
 int            sPosY;       // dword @ 000004
 int            sPosZ;       // dword @ 000008
 unsigned short uRadius;     // word  @ 00000C
 unsigned short uKind;       // word  @ 00000E
 unsigned short uIndex;      // word  @ 000010  Index: monster (1-3: M1-M3,  4-6: M1a-M1c,  7-9: M2a-M2c,  10-12: M3a-M3c) or item (1-6)
 unsigned short uAttributes; // word  @ 000012
};
// sizeof == 14

struct SpawnPointMM7: public SpawnPointMM6
{
 unsigned int uGroup; // dword @ 000014
};
// sizeof == 18
