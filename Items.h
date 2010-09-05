#pragma once
#pragma pack(push, 1)


struct ItemGen
{
 unsigned int uItemID;
 int          dword_000004;
 int          dword_000008;
 int          dword_00000C;
 int          dword_000010;
 int          dword_000014;
 char         byte_000018;
 char         byte_000019; //alignment byte
 char         byte_00001A;
 char         byte_00001B; //alignment byte
 int          dword_00001C;
 int          dword_000020;
};
//sizeof = 24


#pragma pack(pop)