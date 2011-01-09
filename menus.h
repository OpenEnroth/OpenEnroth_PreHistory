#pragma once


#include "defs.h"
#include "GUI\GUI.h"

#pragma pack(push, 1)


#define MAX_SAVEGAME_PATH 280

//_UNKNOWN unk_69BD68; // weak
// char byte_69BD7C[20]; // idb

// int dword_69BD90[40 * 25 + array_size_unknown]; // weak

 struct	Save_Header	//unk_69BD68
	 {
	   char name1[20];	//unk_69BD68
	   char location_name[20];	// byte_69BD7C
	 __int64 qWorld_time;     		// dword_69BD90
	  char fill_1[52];
	 };//size 0x64 100	//69BDCC end

 struct	Save_files_list
	 {	
	    char unk_69CFE0[20]; // weak
	    char name_list[40][MAX_SAVEGAME_PATH]; // idb 40  byte_69CFF4[11200]
	 };


int __cdecl sub_45E93E();

void sub_45EE8A(int a1);

void sub_4601B7_SaveLoadWindow_Render(int a1);

void sub_45E297(int a1);

void  sub_45E361(int a1);

int __fastcall sub_460078(int a1);

int __fastcall SaveGame(int a1, int a2);

void  sub_4606F7_LoadWindow_Render();
void  sub_4606FE();
int __cdecl sub_410DEC_DrawSpellbook_Beacons();

void __cdecl sub_4B6943();

void *__cdecl sub_45E006_FreeSaveThumbnails();

extern int dword_69CF28[45]; // weak

extern Save_Header     saves_hdr[40];	
//extern _UNKNOWN unk_69BD68; // weak
//extern char byte_69BD7C[20]; // idb

extern cPCXTexture cSaveTumbnail[45];

//int dword_69BD94; // weak

extern class LOD_Writefile LODFile_New_LOD; // struct @ MM7.exe::006A0820
//_UNKNOWN unk_6A0820; // weak
//int dword_6A0A4C; // ::+22C    uNumSubidices

extern class LOD_Writefile LODFile_Games_LOD; // struct @ MM7.exe::006A0A60
//_UNKNOWN unk_6A0A60; // weak
//int dword_6A0C8C; // ::+22C   uNumSubidices
//int dword_6A0C90; // ::+230   pLODSubIndexNamedBuffer
extern int dword_6A0C9C;
extern int dword_6A0CA0_indx;

extern struct GUIButton *pArrowDownBtn; // weak
extern struct GUIButton *pArrowUpBtn; // weak	 dword_69BD5C
extern struct GUIButton *pCancelBtn; // weak dword_69BD60
extern struct GUIButton *pLoadSaveBtn; // weak







void LoadUI_MainMenu();


#pragma pack(pop)