#pragma once
#if 0
#pragma pack(push, 1)



struct Edge
{
 float        flt_000000;
 float        flt_000004;
 int          dword_000008;
 struct Surf *pSurf;            // ptr @ 00000C
 struct Edge *pNext;            // ptr @ 000010
 struct Edge *pPrev;            // ptr @ 000014
 struct Edge *ptr_000018;
 float        flt_00001C;
 float        flt_000020;
 float        flt_000024;
 float        flt_000028;
 float        flt_00002C;
 float        flt_000030;
};
//sizeof == 34

struct Span
{
 struct Span    *pNext;        // dword @ 000000
 struct struct8 *pParent;      // dword @ 000004
 short           word_000008;  //  screen-space x?  -1 for final span
 short           word_00000A;  //  screen-space y?
 short           word_00000C;
 short           word_00000E;  // data_6BE060.dword_6BE064 goes here
 float           flt_000010;
 float           flt_000014;
};
//sizeof == 18

struct Surf
{
 float           flt_000000;
 float           flt_000004;
 float           flt_000008;
 float           flt_00000C;
 float           flt_000010;
 struct Surf    *pNext;      // dword @ 000014
 struct Surf    *pPrev;      // dword @ 000018
 struct struct8 *ptr_00001C;
 short           word_000020;
 short           word_000022;
};
//sizeof == 24


#pragma pack(pop)
#endif