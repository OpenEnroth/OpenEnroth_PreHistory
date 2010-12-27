#include "memory_mng.h"
#include  "_lod.h"
#include "mm7_unparsed_data.h"
#include "Events.h"

#include "GUI\GUIWindow.h"




char aTooManyStation[] = "Too many stationary lights!"; // byte[] @ MM7.exe::004F0364

 int dword_4C9890[10]; // weak
 int dword_4C9920[16]; // weak
/*exter*/ char a1[array_size_unknown];
 int dword_4DF380[array_size_unknown]; // weak
 int dword_4DF390; // weak
 char Str2[array_size_unknown]; // idb
 int dword_4DF3A4; // weak
 char aBrickShortage[] = "Brick Shortage"; // byte[] @ MM7.exe::004DF3A8 
 int dword_4DF3C8[array_size_unknown]; // weak
 char byte_4DF3D3[array_size_unknown]; // weak
 char byte_4E185C; // weak
 char byte_4E185D; // weak
 char byte_4E185E; // weak
 int dword_4E1860; // weak
 int dword_4E1864; // weak
 int dword_4E1868; // weak
 int dword_4E186C; // weak
 int dword_4E1870; // weak
 int dword_4E1874; // weak
 int dword_4E1878; // weak
 int dword_4E187C; // weak
 int dword_4E1880; // weak
 int dword_4E1884; // weak
 int dword_4E1888; // weak
 _UNKNOWN unk_4E19FC; // weak
// char asc_4E1A08[1]; // idb
// char asc_4E1A28[4]; // idb

 char DayMoonPhase[28]= {
	0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x04, 0x04, 
	0x04, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01
};	   //moon phases	byte _4E1B18
 

 wchar_t *off_4E1D18; // weak
 __int16 word_4E1D3A[array_size_unknown]; // weak
 __int16 word_4E1D3C[array_size_unknown]; // weak
 __int16 word_4E1D46[array_size_unknown]; // weak
 __int16 word_4E1D48[array_size_unknown]; // weak
 __int16 word_4E1D54[array_size_unknown]; // weak
 __int16 word_4E1D60[array_size_unknown]; // weak
 int dword_4E20D0; // weak
 int dword_4E20D4; // weak
 char byte_4E2430[array_size_unknown]; // weak
 char byte_4E2431[array_size_unknown]; // weak

 int dword_4E249C[5] ={
	 61, 281, 61, 281, 171
	 }; //  button X

 int dword_4E24B0[5]={
	 84, 84, 228, 228, 155
	 }; // button y

 int dword_4E24C4; // weak
 int dword_4E24D8; // weak

 char *dword_4E24E8; // idb
 int dword_4E2544[array_size_unknown]; // weak
 int dword_4E28F8_PartyCantJumpIfTrue; // weak
 char byte_4E28FC; // weak
 int dword_4E2900_GammaPos; // weak
 int dword_4E2910[array_size_unknown]; // weak
 __int16 word_4E2930[4] = { 0x14,  0x83,  0xF2,  0x165};// weak	  array_size_unknown
 __int16 word_4E2938[4]=  { 0x53,  0xC6,  0x138,  0x1A7}; 	// weak	  array_size_unknown 

 Square g_StatsHintCoords[27] = 
	{{ 26, 57,220, 18},  { 26, 74,220, 18},    { 26, 91,220, 18},    { 26,108,220, 18},   { 26,125,220, 18},
	 { 26,142,220, 18},  { 26,159,220, 18},    { 26,198,220, 18},    { 26,215,220, 18},   { 26,232,220, 18},
	 { 26,268,220, 18},  { 26,286,220, 18},    {273, 54,186, 18},    {273, 71,186, 18},   {273, 88,186, 18},
	 {273,126,186, 18},  {273,143,186, 18},    {273,160,186, 18},    {273,177,186, 18},   {273,202,186, 18},
	 {273,221,186, 18},  {273,240,186, 18},    {273,259,186, 18},    {273,278,186, 18},   {273,297,186, 18},
	 {318, 18,137, 18},  { 24, 18,240, 18}};




 int dword_4E2A18[5] = {9, 10, 11, 8, 30};
 int dword_4E2A2C[9] = {3, 5, 2, 6, 4, 0, 1, 31, 7};
 int dword_4E2A50[12] = {35, 33, 24, 21, 32, 36, 29, 25, 22, 26, 23, 34};
 int dword_4E2A80[9] = {12, 13, 14, 15, 16, 17, 18, 19, 20};
 _BYTE byte_4E2AA4[20] = {248, 108, 160, 112, 220, 248, 192, 192, 240, 64, 244, 96, 232, 244, 96, 240, 252, 192, 0, 0};
 int uHealthBarPos[4] = {22, 137, 251, 366};		 //dword _4E2AB8
 int uManaBarPos[4] = {102, 217, 331, 447};		  //dword _4E2AC8
 _UNKNOWN unk_4E2AD9; // weak
 _UNKNOWN unk_4E2B21; // weak
 char byte_4E2B70[array_size_unknown]; // weak
 char byte_4E2BC8; // weak
 int dword_4E2BCC; // weak
 int dword_4E2BEC; // weak
 int dword_4E2C0C[array_size_unknown]; // weak
 int dword_4E2C2C[array_size_unknown]; // weak
 char byte_4E2FD4; // idb
 void *off_4E3044; // weak
 _UNKNOWN unk_4E3308; // weak
 _UNKNOWN unk_4E3318; // weak
 _UNKNOWN unk_4E3328; // weak
 _UNKNOWN unk_4E3338; // weak
 _UNKNOWN unk_4E334C; // weak
 _UNKNOWN unk_4E3364; // weak
 _UNKNOWN unk_4E3374; // weak
 _UNKNOWN unk_4E3384; // weak
 __int16 word_4E3ACC[array_size_unknown]; // weak
 __int16 word_4E3AEC; // weak
 __int16 word_4E3AF0; // weak
 __int16 word_4E3B08; // weak
 __int16 word_4E3C40; // weak
 __int16 word_4E3C66; // weak
 // spell data
   	 //0 	spell data	array
 /*__int16 word_4E3C68[array_size_unknown]; // weak
 __int16 word_4E3C6A[array_size_unknown]; // weak
 __int16 word_4E3C6C[array_size_unknown]; // weak
 __int16 word_4E3C6E[array_size_unknown]; // weak
 __int16 word_4E3C72[array_size_unknown]; // weak
 char byte_4E3C78[array_size_unknown]; // weak
 char byte_4E3C79[array_size_unknown]; // weak
 char byte_4E3C7A[array_size_unknown]; // weak */
	//0 	spell data	array
					// word_4E3C7C  rec 1
  Spell_data word_4E3C68[100]={
{ 0,  0,  0,  0, 0,  0,  0,  0,  0,  0,  0,  0}, //zero record for start from 1

{ 1,  1,  1,  1,  60,  60,  60,  40,  0,  0,  0,  0}, 
{ 2,  2,  2,  2,  110,  110,  100,  90,  0,  3,  0,  0}, 
{ 3,  3,  3,  3,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 4,  4,  4,  4,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 5,  5,  5,  5,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 8,  8,  8,  8,  100,  100,  90,  80,  0,  6,  0,  0}, 
{ 10,  10,  10,  10,  150,  150,  150,  150,  0,  6,  0,  0}, 
{ 15,  15,  15,  15,  120,  120,  120,  120,  0,  6,  0,  0}, 
{ 20,  20,  20,  20,  100,  100,  100,  90,  8,  1,  0,  0}, 
{ 25,  25,  25,  25,  100,  100,  100,  90,  12,  1,  0,  0}, 
{ 30,  30,  30,  30,  90,  90,  90,  90,  15,  15,  0,  0},

{ 1,  1,  1,  0,  60,  60,  60,  60,  0,  0,  0,  0}, 
{ 2,  2,  2,  2,  120,  120,  120,  100,  0,  0,  0,  0}, 
{ 3,  3,  3,  3,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 4,  4,  4,  4,  110,  100,  90,  80,  2,  1,  0,  0}, 
{ 5,  5,  5,  5,  90,  90,  70,  50,  0,  0,  0,  0}, 
{ 8,  8,  8,  8,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 10,  10,  10,  10,  100,  100,  90,  70,  0,  8,  0,  0}, 
{ 15,  15,  15,  15,  200,  200,  200,  200,  0,  0,  0,  0}, 
{ 20,  20,  20,  20,  100,  100,  100,  90,  10,  10,  0,  0}, 
{ 25,  25,  25,  25,  250,  250,  250,  250,  0,  0,  0,  0}, 
{ 30,  30,  30,  30,  90,  90,  90,  90,  20,  1,  0,  0}, 

{ 1,  1,  1,  1,  60,  60,  60,  20,  0,  0,  0,  0}, 
{ 2,  2,  2,  2,  110,  100,  90,  70,  2,  2,  0,  0}, 
{ 3,  3,  3,  3,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 4,  4,  4,  4,  110,  100,  90,  80,  0,  4,  0,  0}, 
{ 5,  5,  5,  5,  150,  150,  150,  150,  0,  0,  0,  0}, 
{ 8,  8,  8,  8,  200,  200,  200,  200,  0,  0,  0,  0}, 
{ 10,  10,  10,  10,  100,  100,  90,  80,  9,  9,  0,  0}, 
{ 15,  15,  15,  15,  140,  140,  140,  140,  0,  0,  0,  0}, 
{ 20,  20,  20,  20,  200,  200,  200,  200,  0,  0,  0,  0}, 
{ 25,  25,  25,  25,  80,  80,  80,  80,  12,  3,  0,  0}, 
{ 30,  30,  30,  30,  250,  250,  250,  250,  0,  0,  0,  0},

{ 1,  1,  1,  1,  80,  80,  80,  80,  0,  0,  0,  0}, 
{ 2,  2,  2,  2,  100,  100,  100,  100,  0,  0,  0,  0}, 
{ 3,  3,  3,  3,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 4,  4,  4,  4,  110,  100,  90,  80,  5,  3,  0,  0}, 
{ 5,  5,  5,  5,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 8,  8,  8,  8,  100,  100,  90,  80,  0,  9,  0,  0}, 
{ 10,  10,  10,  10,  140,  140,  140,  140,  0,  0,  0,  0}, 
{ 15,  15,  15,  15,  90,  90,  90,  80,  0,  8,  0,  0}, 
{ 20,  20,  20,  20,  150,  150,  150,  150,  0,  0,  0,  0}, 
{ 25,  25,  25,  25,  100,  100,  100,  90,  20,  1,  0,  0}, 
{ 30,  30,  30,  30,  90,  90,  90,  90,  25,  0,  0,  0}, 

{ 1,  1,  1,  1,  100,  100,  100,  100,  0,  0,  0,  0}, 
{ 2,  2,  2,  2,  100,  100,  100,  100,  0,  0,  0,  0}, 
{ 3,  3,  3,  3,  90,  90,  90,  90,  0,  0,  0,  0}, 
{ 4,  4,  4,  4,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 5,  5,  5,  5,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 8,  8,  8,  8,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 10,  10,  10,  10,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 15,  15,  15,  15,  100,  100,  100,  100,  10,  8,  0,  0}, 
{ 20,  20,  20,  20,  240,  240,  240,  240,  0,  0,  0,  0}, 
{ 25,  25,  25,  25,  150,  150,  150,  150,  0,  0,  0,  0}, 
{ 30,  30,  30,  30,  1000,  1000,  1000,  1000,  0,  0,  0,  0},

{ 1,  1,  1,  1,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 2,  2,  2,  2,  110,  110,  110,  110,  3,  3,  0,  0}, 
{ 3,  3,  3,  3,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 4,  4,  4,  4,  110,  100,  90,  80,  0,  0,  0,  0}, 
{ 5,  5,  5,  5,  100,  100,  100,  100,  0,  0,  0,  0}, 
{ 8,  8,  8,  8,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 10,  10,  10,  10,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 15,  15,  15,  15,  80,  80,  80,  80,  0,  0,  0,  0}, 
{ 20,  20,  20,  20,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 25,  25,  25,  25,  110,  110,  110,  100,  12,  1,  0,  0}, 
{ 30,  30,  30,  30,  120,  120,  120,  120,  0,  0,  0,  0}, 

{ 1,  1,  1,  1,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 2,  2,  2,  2,  100,  100,  100,  100,  0,  0,  0,  0}, 
{ 3,  3,  3,  3,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 4,  4,  4,  4,  110,  100,  90,  80,  8,  2,  0,  0}, 
{ 5,  5,  5,  5,  110,  110,  110,  110,  0,  0,  0,  0}, 
{ 8,  8,  8,  8,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 10,  10,  10,  10,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 15,  15,  15,  15,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 20,  20,  20,  20,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 25,  25,  25,  25,  110,  110,  110,  100,  30,  5,  0,  0}, 
{ 30,  30,  30,  30,  100,  100,  100,  100,  0,  0,  0,  0},

{ 5,  5,  5,  5,  110,  100,  90,  80,  0,  4,  0,  0}, 
{ 10,  10,  10,  10,  120,  110,  100,  90,  16,  16,  0,  0}, 
{ 15,  15,  15,  15,  120,  110,  100,  90,  0,  0,  0,  0}, 
{ 20,  20,  20,  20,  160,  140,  120,  100,  0,  0,  0,  0}, 
{ 25,  25,  25,  25,  140,  140,  140,  140,  0,  0,  0,  0}, 
{ 30,  30,  30,  30,  500,  500,  500,  500,  0,  0,  0,  0}, 
{ 35,  35,  35,  35,  135,  135,  120,  100,  25,  1,  0,  0}, 
{ 40,  40,  40,  40,  500,  500,  500,  500,  0,  0,  0,  0}, 
{ 45,  45,  45,  45,  250,  250,  250,  250,  0,  0,  0,  0}, 
{ 50,  50,  50,  50,  150,  150,  150,  135,  20,  20,  0,  0}, 
{ 55,  55,  55,  55,  300,  300,  300,  300,  0,  0,  0,  0}, 

{ 10,  10,  10,  10,  140,  140,  140,  140,  0,  0,  0,  0}, 
{ 15,  15,  15,  15,  120,  110,  100,  90,  25,  10,  0,  0}, 
{ 20,  20,  20,  20,  120,  100,  90,  120,  0,  0,  0,  0}, 
{ 25,  25,  25,  25,  120,  120,  120,  120,  0,  0,  0,  0}, 
{ 30,  30,  30,  30,  90,  90,  80,  70,  6,  6,  0,  0}, 
{ 35,  35,  35,  35,  120,  120,  100,  80,  0,  0,  0,  0}, 
{ 40,  40,  40,  40,  110,  110,  110,  110,  0,  0,  0,  0}, 
{ 45,  45,  45,  45,  200,  200,  200,  150,  0,  0,  0,  0}, 
{ 50,  50,  50,  50,  120,  120,  120,  100,  0,  25,  0,  0}, 
{ 55,  55,  55,  55,  250,  250,  250,  250,  50,  1,  0,  0}, 
{ 60,  60,  60,  60,  300,  300,  300,  300,  25,  8,  0,  0} 
};
// unsigned char some_spell_stuff[98 * 20]; //struct[98] @ MM7.exe::004E3C8E  98 spells

 //end spell data
//_UNKNOWN unk_4E3C8E; // weak
 char byte_4E3FE8; // weak

 int dword_4E421C[array_size_unknown]; // weak sound
//_UNKNOWN unk_4E4436; // weak

 int dword_4E455C; // weak
 int dword_4E4560; // weak
 int dword_4E4578; // weak
 int dword_4E4590; // weak
 int dword_4E45A8; // weak
 int dword_4E4948[34]; // weak
 int dword_4E49D0[18]; // weak
 int dword_4E4A18[10]; // weak
 int dword_4E4A40[16]; // weak
 float flt_4E4A80[4]; // weak
 float flt_4E4A90[array_size_unknown]; // weak
 int dword_4E4C28 = 481; // X offset for paperdoll
 int dword_4E4C2C = 0; // Y offset for paperdoll
 int dword_4E4C30[32 * array_size_unknown]; // 32 element array
 int dword_4E4E30[2 * array_size_unknown]; // 2 element array
 int dword_4E5050[8]; // weak
 int dword_4E5270[8]; // weak
 int dword_4E5490; // weak
 int dword_4E5494; // weak
 int dword_4E54B8[14 * array_size_unknown]; // 14 element array
 int dword_4E5570[array_size_unknown]; // weak
 int dword_4E56B0; // weak
 int dword_4E56B4; // weak
 int dword_4E57F0[array_size_unknown]; // weak
 int dword_4E58D0; // weak
 int dword_4E58D4; // weak
 int dword_4E5AD0[array_size_unknown]; // weak
 int dword_4E5AE0[8] = { 103, 106, 101, 108, 116, 141, 116, 147 };
 int dword_4E5B00[8] = { 26, 107,  40, 109,  25, 141,  32, 146 }; // XY of left hand position on paperdoll
 int dword_4E5B20[8] = { 30, 144,  34, 158,  25, 186,  31, 184 }; // XY of right hand position on paperdoll
 int dword_4E5B40[8] = { 128, 205, 131, 201, 131, 216, 123, 216 }; // XY position of left empty hand on paperdoll
 int dword_4E5C1C[6] = { 490, 538, 584, 490, 538, 584}; // weak
 int dword_4E5C34[6] = { 202, 202, 202, 250, 250, 250}; // weak
 int dword_4E5D68[array_size_unknown]; // weak
 char byte_4E5DD8[array_size_unknown]; // weak
 char byte_4E5DE8[array_size_unknown]; // weak
unsigned int uDialogueUIIconsOffsetX = 0x00000209; // dword @ MM7.exe::004E5E50
 int dword_4E5EC8[array_size_unknown]; // weak
unsigned int uDialogueUIIconsOffsetY = 0x00000026; // dword @ MM7.exe::004E5EE0
 char (*off_4E5F70)[8]; // weak
 int dword_4E5F78[array_size_unknown]; // weak
 char byte_4E5F7C[array_size_unknown]; // weak
 char byte_4E5F7D[array_size_unknown]; // weak
 char *off_4E6BB0; // idb
 char *off_4E6BDC; // idb
 int dword_4E800C; // weak

 //next two could be the same array or at least first 16 of data_4E7168 are word_4E8152
unsigned short word_4E8152[11] =
{
 0,  0,  0, 90, 8, 2, 70, 20,
 10, 50, 30
};
unsigned char data_4E7168[116] =
{
 0x14, 0x00, 0x1E, 0x00, 0x28, 0x00, 0x1E, 0x00,   0x0A, 0x00, 0x32, 0x00, 0x28, 0x00, 0x00, 0x00,
 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,   0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,   0x02, 0x02, 0x02, 0x02, 0x01, 0x02, 0x02, 0x02,
 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,   0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03,
 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,   0x02, 0x02, 0x02, 0x02, 0x03, 0x04, 0x04, 0x04,
 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0x02,   0x02, 0x02, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05,
 0x05, 0x06, 0x06, 0x06, 0x02, 0x02, 0x02, 0x02,   0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
 0x07, 0x07, 0x00, 0x00
};

 int dword_4E82B4; // weak
 int dword_4E82B8; // weak
 int dword_4E82BC; // weak
 int dword_4E82C0; // weak
 char byte_4E8398[8*array_size_unknown] =
{
 0x01, 0x01, 0x02, 0x03, 0x00, 0x04, 0x05, 0x06,   0x07, 0x08, 0x0A, 0x09, 0x01, 0x00, 0x00, 0x00,
 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00
 //....
};

 char unk_4E83B0[64*array_size_unknown];
 char unk_4E8408[64*array_size_unknown];
 char byte_4E94D0; // weak
 char byte_4E94D2; // weak
 char byte_4E94D3; // weak

 int dword_4E98BC; // weak
 _UNKNOWN unk_4E98D4; // weak
 char *off_4EB080; // idb
const unsigned char   *pTransitionStrings[464]; // dword[464]  @ MM7.exe::004EB084
struct unnamed_4EB8B8  array_4EB8B8[66];        // struct[66]  @ MM7.exe::004EB8B8
struct unnamed_4EB8B8  array_4EBBD0[128];       // struct[128] @ MM7.exe::004EBBD0
 int dword_4EC268[array_size_unknown]; // weak
 int dword_4EC28C[array_size_unknown]; // weak
 int dword_4EC2A8; // weak
 int dword_4EC2AC; // weak

 char byte_4ECA93[array_size_unknown]; // weak
 char byte_4ECACF[array_size_unknown]; // weak
 _BYTE byte_4ECB0C[64]; // idb

struct unnamed_4ECBB8 stru_4ECBB8[6]; // struct[] @ MM7.exe::004ECBB8
 char *off_4ECC30[25]; // weak
 char *off_4ECC98; // idb
 char *off_4ECD00; // idb
 char *off_4ECD68; // idb
 char *off_4ECDD0; // idb
 char *off_4ECE38; // idb
 char *off_4ECEA0; // idb
char byte_4ECEEF[32 * array_size_unknown] =
{
 0x00, 0xA8, 0xE1, 0x4E, 0x00, 0xA0, 0xE1, 0x4E, 0x00, 0x98, 0xE1, 0x4E, 0x00, 0x90, 0xE1, 0x4E,   0x00, 0x88, 0xE1, 0x4E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x02, 0x01, 0x02, 0x02, 0x02,
 0x02, 0x02, 0x02, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x02,   0x01, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01,
 0x02, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x02, 0x02, 0x02,   0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,   0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x02,
 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x02, 0x02, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,   0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x02, 0x02, 0x02,
 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,   0x02, 0x02, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,   0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x02, 0x01,
 0x01, 0x02, 0x01, 0x02, 0x02, 0x02, 0x02, 0x01, 0x02, 0x01, 0x02, 0x02, 0x02, 0x01, 0x02, 0x02,   0x01, 0x02, 0x02, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x02, 0x01, 0x01, 0x02
};

char byte_4ED3D8[856] =
{
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x25, 0x26, 0x2D, 0x00, 0x00,   0x25, 0x00, 0x00, 0x2F, 0x35, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00,
 0x01, 0x00, 0x00, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x29, 0x2A, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x15, 0x16, 0x17, 0x18, 0x2D,
 0x06, 0x00, 0x00, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x2B, 0x30, 0x00, 0x00, 0x00,   0x08, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00, 0x00,
 0x0D, 0x00, 0x00, 0x25, 0x26, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x25, 0x26, 0x2D, 0x00, 0x00, 0x19, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00,
 0x1A, 0x00, 0x00, 0x26, 0x2F, 0x00, 0x00, 0x00, 0x1B, 0x00, 0x00, 0x29, 0x2A, 0x00, 0x00, 0x00,   0x1C, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 0x00,
 0x1E, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00, 0x1D, 0x00, 0x00, 0x1B, 0x00, 0x00, 0x00, 0x00,   0x20, 0x21, 0x00, 0x25, 0x26, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00, 0x00,
 0x0F, 0x00, 0x00, 0x22, 0x23, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,   0x16, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00,
 0x14, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00,   0x15, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00,   0x18, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x29, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x30, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x30, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x29, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x30, 0x00, 0x00, 0x00,   0x29, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00,
 0x10, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x26, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x30, 0x31, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x26, 0x2D, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x29, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2F, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x27, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x30, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x25, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x26, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x25, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x2F, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00, 0x00,   0x16, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00,

 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x2D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1B, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x25, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x26, 0x2D, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x26, 0x2D, 0x00, 0x00,   0x00, 0x00, 0x00, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00,
 0x2C, 0x00, 0x00, 0x27, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x31, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00,
 0x20, 0x21, 0x00, 0x25, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x26, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x25, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2F, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x26, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00,   0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3A, 0x00, 0x00, 0x00, 0x00
};
 char byte_4ED498 = 15; // weak
 //__int16 word_4ED746[array_size_unknown]; // off_4ED748[-1] indexing
short off_4ED748[4] =
{
 34, 149, 264, 379
};
unsigned char byte_4ED750[0xC] =
{
 0x28, 0x23, 0x23, 0x1E, 0x1E, 0x1E, 0x19, 0x14, 0x14, 0x0, 0x0, 0x0
};

 char byte_4ED75C[array_size_unknown]; // weak

 unsigned char byte_4ED768[0x24] =
{
 0x05, 0x07, 0x09, 0x09, 0x04, 0x06, 0x08, 0x08, 0x05, 0x06, 0x08, 0x08, 0x04, 0x05, 0x06, 0x06,
 0x03, 0x04, 0x06, 0x06, 0x04, 0x05, 0x06, 0x06, 0x02, 0x03, 0x04, 0x04, 0x02, 0x03, 0x04, 0x04,
 0x02, 0x03, 0x03, 0x03
};

 unsigned char byte_4ED78C[0x24] =
{
 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x03, 0x03,
 0x01, 0x02, 0x03, 0x03, 0x00, 0x02, 0x03, 0x03, 0x03, 0x04, 0x05, 0x05, 0x03, 0x04, 0x05, 0x05,
 0x03, 0x04, 0x06, 0x06
};

 char byte_4ED94C[array_size_unknown]; // weak
 //one array  0x534 size
 //char byte_4ED970[array_size_unknown]; // weak
// char byte_4ED995[array_size_unknown]; // weak +1
 //char byte_4ED9BA[array_size_unknown]; // weak +2
 //char byte_4ED9DF[array_size_unknown]; // weak +3

 unsigned char byte_4ED970[36][37] = {
	0x02, 0x03, 0x02, 0x03, 0x03, 0x02, 0x03, 0x04, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x00, 0x02, 0x01, 0x00, 0x01, 0x02, 0x02, 
	0x00, 0x03, 0x00, 0x00, 0x01, 0x02, 0x03, 0x02, 0x03, 0x03, 0x02, 0x03, 0x04, 0x03, 0x03, 0x03, 
	0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x00, 0x02, 
	0x01, 0x00, 0x01, 0x02, 0x02, 0x00, 0x03, 0x00, 0x00, 0x01, 0x02, 0x04, 0x02, 0x03, 0x04, 0x02, 
	0x03, 0x04, 0x04, 0x03, 0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x02, 0x04, 0x04, 0x00, 0x02, 0x01, 0x00, 0x01, 0x02, 0x02, 0x00, 0x04, 0x00, 0x00, 0x01, 0x02, 
	0x04, 0x02, 0x03, 0x04, 0x02, 0x03, 0x04, 0x04, 0x03, 0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x04, 0x00, 0x02, 0x01, 0x00, 0x01, 0x02, 0x02, 0x00, 
	0x04, 0x00, 0x00, 0x01, 0x00, 0x03, 0x03, 0x00, 0x00, 0x02, 0x02, 0x04, 0x01, 0x03, 0x02, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x02, 0x00, 0x03, 0x00, 
	0x00, 0x03, 0x03, 0x02, 0x00, 0x03, 0x03, 0x02, 0x02, 0x00, 0x03, 0x03, 0x00, 0x00, 0x02, 0x02, 
	0x04, 0x01, 0x03, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 
	0x01, 0x02, 0x00, 0x03, 0x00, 0x00, 0x03, 0x03, 0x02, 0x00, 0x03, 0x03, 0x02, 0x02, 0x00, 0x03, 
	0x04, 0x00, 0x00, 0x02, 0x02, 0x04, 0x01, 0x04, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x02, 0x00, 0x03, 0x00, 0x00, 0x04, 0x03, 0x02, 0x00, 0x03, 
	0x04, 0x02, 0x02, 0x00, 0x03, 0x04, 0x00, 0x00, 0x02, 0x02, 0x04, 0x01, 0x04, 0x02, 0x00, 0x01, 
	0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x02, 0x00, 0x03, 0x00, 0x00, 
	0x04, 0x03, 0x02, 0x00, 0x03, 0x04, 0x02, 0x02, 0x03, 0x02, 0x02, 0x00, 0x02, 0x01, 0x00, 0x04, 
	0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x03, 0x00, 0x02, 0x01, 0x00, 0x01, 0x03, 0x03, 0x02, 0x03, 0x01, 0x00, 0x03, 0x03, 0x02, 0x02, 
	0x00, 0x02, 0x01, 0x00, 0x04, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x01, 0x00, 0x02, 0x03, 0x03, 0x02, 0x03, 0x01, 
	0x00, 0x03, 0x04, 0x02, 0x02, 0x00, 0x02, 0x01, 0x00, 0x04, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x02, 0x01, 0x00, 0x02, 
	0x04, 0x04, 0x02, 0x03, 0x01, 0x00, 0x04, 0x04, 0x02, 0x02, 0x00, 0x02, 0x01, 0x00, 0x04, 0x00, 
	0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 
	0x00, 0x02, 0x01, 0x00, 0x03, 0x04, 0x04, 0x02, 0x03, 0x02, 0x00, 0x04, 0x01, 0x03, 0x02, 0x02, 
	0x02, 0x02, 0x03, 0x04, 0x03, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 
	0x00, 0x00, 0x02, 0x03, 0x03, 0x02, 0x01, 0x03, 0x00, 0x00, 0x01, 0x01, 0x00, 0x02, 0x00, 0x00, 
	0x01, 0x01, 0x03, 0x02, 0x02, 0x02, 0x02, 0x03, 0x04, 0x03, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 
	0x00, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x02, 0x01, 0x03, 0x00, 0x00, 0x01, 
	0x01, 0x00, 0x02, 0x00, 0x00, 0x01, 0x01, 0x03, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x02, 
	0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x02, 0x04, 0x03, 0x02, 
	0x01, 0x04, 0x00, 0x00, 0x01, 0x01, 0x00, 0x02, 0x00, 0x00, 0x01, 0x01, 0x03, 0x02, 0x02, 0x02, 
	0x02, 0x04, 0x04, 0x04, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x01, 
	0x00, 0x02, 0x04, 0x03, 0x02, 0x01, 0x04, 0x00, 0x00, 0x01, 0x01, 0x00, 0x02, 0x00, 0x00, 0x01, 
	0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x00, 0x04, 0x00, 0x03, 0x03, 0x00, 0x01, 0x01, 0x01, 0x01, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x03, 0x00, 0x00, 0x01, 0x02, 0x01, 
	0x00, 0x02, 0x00, 0x00, 0x03, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x00, 0x04, 0x00, 0x03, 0x03, 
	0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x03, 
	0x00, 0x00, 0x01, 0x02, 0x01, 0x00, 0x02, 0x00, 0x00, 0x03, 0x01, 0x02, 0x02, 0x02, 0x03, 0x04, 
	0x00, 0x04, 0x00, 0x03, 0x04, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 
	0x02, 0x02, 0x02, 0x02, 0x04, 0x00, 0x00, 0x02, 0x02, 0x01, 0x00, 0x02, 0x00, 0x00, 0x03, 0x01, 
	0x02, 0x02, 0x02, 0x03, 0x04, 0x00, 0x04, 0x00, 0x03, 0x04, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x04, 0x00, 0x00, 0x02, 0x02, 0x01, 0x00, 
	0x02, 0x00, 0x00, 0x03, 0x01, 0x02, 0x02, 0x03, 0x02, 0x03, 0x00, 0x04, 0x02, 0x03, 0x03, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02, 0x01, 0x03, 0x02, 
	0x00, 0x02, 0x02, 0x01, 0x03, 0x02, 0x02, 0x01, 0x02, 0x01, 0x02, 0x02, 0x03, 0x02, 0x03, 0x00, 
	0x04, 0x02, 0x03, 0x03, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 
	0x01, 0x02, 0x01, 0x03, 0x02, 0x00, 0x02, 0x02, 0x01, 0x03, 0x02, 0x02, 0x01, 0x02, 0x01, 0x02, 
	0x02, 0x04, 0x02, 0x03, 0x00, 0x04, 0x02, 0x03, 0x03, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02, 0x01, 0x03, 0x02, 0x00, 0x02, 0x02, 0x01, 0x04, 0x02, 
	0x02, 0x01, 0x02, 0x01, 0x02, 0x02, 0x04, 0x02, 0x03, 0x00, 0x04, 0x02, 0x03, 0x03, 0x00, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02, 0x01, 0x03, 0x02, 0x00, 
	0x02, 0x02, 0x01, 0x04, 0x02, 0x02, 0x01, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x04, 
	0x03, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x03, 0x03, 
	0x01, 0x03, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x03, 0x01, 0x00, 0x00, 
	0x00, 0x00, 0x02, 0x03, 0x04, 0x03, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 
	0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x03, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 
	0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x04, 0x03, 0x02, 0x02, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x04, 0x03, 0x01, 0x03, 0x02, 0x03, 0x00, 0x00, 
	0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x04, 0x03, 
	0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x00, 0x04, 0x00, 0x04, 0x03, 0x01, 
	0x03, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x03, 0x01, 0x00, 0x03, 0x00, 
	0x00, 0x01, 0x02, 0x04, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 
	0x00, 0x02, 0x02, 0x00, 0x00, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x03, 
	0x03, 0x01, 0x00, 0x03, 0x00, 0x00, 0x01, 0x02, 0x04, 0x02, 0x02, 0x00, 0x00, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x02, 0x01, 0x00, 0x03, 0x03, 0x01, 0x00, 0x03, 0x00, 0x00, 0x01, 0x02, 0x04, 0x02, 0x02, 
	0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x04, 
	0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x04, 0x03, 0x01, 0x00, 0x03, 0x00, 0x00, 
	0x01, 0x02, 0x04, 0x02, 0x02, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 
	0x02, 0x02, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x04, 0x03, 
	0x03, 0x00, 0x02, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x02, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x02, 0x00, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 
	0x03, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x02, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x02, 0x00, 
	0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x02, 0x00, 0x03, 0x02, 
	0x01, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x02, 0x00, 0x00, 0x01, 
	0x00, 0x04, 0x00, 0x02, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x04, 
	0x01, 0x02, 0x00, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x03, 0x03, 0x03, 
	0x00, 0x02, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x02, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x00, 
	0x00, 0x00, 0x00, 0x04, 0x04, 0x01, 0x02, 0x00, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x04,
	0x00, 0x00, 0x03, 0x03
};

 //int dword_4EDEA0[array_size_unknown]; // weak
 int dword_4EDEA4[4]; // weak
 int dword_4EDEB4[array_size_unknown]; // weak
 int dword_4EDEC4; // weak
 __int16 word_4EDED8[array_size_unknown]; // weak
 __int16 word_4EDEDC; // weak
 int dword_4EDEF8[18]={16, 15, 14, 17, 2, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 1, 0}; // weak
// _UNKNOWN unk_4EDF40; // weak	border
 
 unsigned char uConditionStrengthMultiplier[19] =     {100, 100, 100, 120,  50, 200,  75,  60,  50,  30,  25,  10, 100, 100, 100, 100, 100, 100, 100};
 unsigned char uConditionIntelligenceMultiplier[19] = {100, 100, 100,  50,  25,  10, 100, 100,  75,  60,  50,  30, 100, 100, 100, 100, 100,   1, 100};
 unsigned char uConditionWillpowerMultiplier[19] =    {100, 100, 100,  50,  25,  10, 100, 100,  75,  60,  50,  30, 100, 100, 100, 100, 100,   1, 100};
 unsigned char uConditionEnduranceMultiplier[19]    = {100, 100, 100, 100,  50, 150,  75,  60,  50,  30,  25,  10, 100, 100, 100, 100, 100, 100, 100};
 unsigned char uConditionAccuracyMultiplier[19]     = {100, 100, 100,  50,  10, 100,  75,  60,  50,  30,  25,  10, 100, 100, 100, 100, 100,  50, 100};
 unsigned char uConditionSpeedMultiplier[19]        = {100, 100, 100, 120,  20, 120,  75,  60,  50,  30,  25,  10, 100, 100, 100, 100, 100,  50, 100};
 unsigned char uConditionLuckMultiplier[19]         = {100, 100, 100, 100, 200, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};

 unsigned int uAgeingTable[4] = {50, 100, 150, 0xFFFF};  // player age
 unsigned char uAgeingStrengthMultiplier[4] = {100, 75, 40, 10}; // player weakens upon ageing
 unsigned char uAgeingIntelligenceMultiplier[4] = {100, 150, 100, 10};
 unsigned char uAgeingWillpowerMultiplier[4] = {100, 150, 100, 10}; 
 unsigned char uAgeingEnduranceMultiplier[4] = {100, 75, 40, 10}; 
 unsigned char uAgeingAccuracyMultiplier[4] = {100, 100, 40, 10};
 unsigned char uAgeingSpeedMultiplier[4] = {100, 100, 40, 10};
 unsigned char uAgeingLuckMultiplier[4] = {100, 100, 100, 100};
 
 int dword_4EDFFC; // weak
 char byte_4EE038[array_size_unknown]; // weak
unsigned int uHiredNPCsIconsOffsetsX[2] = // dword[2] @ MM7.exe::004EE06C
{
 489, 559
};
unsigned int uHiredNPCsIconsOffsetsY[2] = // dword[2] @ MM7.exe::004EE074
{
 152, 152
};
 int array_4EE07C[2] =
{
 0x07, 0x12
};
//_UNKNOWN unk_4EE07C; // weak
// _UNKNOWN unk_4EE084; // array_4EE07C bounding offset

 __int16 word_4EE088[array_size_unknown]; // weak
 __int16 word_4EE09A; // weak
 __int16 word_4EE0A6; // weak
 __int16 word_4EE128; // weak
 __int16 word_4EE142; // weak
 _UNKNOWN unk_4EE150; // weak
 int dword_4EED78; // weak
 _UNKNOWN unk_4EED80; // weak
 int dword_4EFA80; // weak
 int dword_4EFA84; // weak
 _UNKNOWN unk_4EFCBC; // weak
 void *off_4EFDB0; // weak
 void *off_4EFFF0; // weak
 __int16 word_4F0040[array_size_unknown]; // weak
 int dword_4F00DC = 0x5622;
 int dword_4F00E0 = 16; // weak
 int dword_4F00E4 = 2; // weak
unsigned int array_4F031C[12] =
{
 0x00000000, 0x00000000, 0x00000000, 0x00000073, 0x0000002F, 0x0000002B, 0x00000026, 0x00000026,
 0x00000026, 0x00000026, 0x00000026, 0x00000026
};
 char *off_4F03B8; // idb
 __int16 word_4F03FE[array_size_unknown]; // weak
 __int16 word_4F0400[array_size_unknown]; // weak
 __int16 word_4F0498[array_size_unknown]; // weak
 __int16 word_4F0576[array_size_unknown]; // weak
 __int16 word_4F0578[array_size_unknown]; // weak
 __int16 word_4F05AE[array_size_unknown]; // weak
 char byte_4F063C[array_size_unknown]; // weak
 __int16 word_4F063E[array_size_unknown]; // weak
 __int16 word_4F0640[array_size_unknown]; // weak
 __int16 word_4F06D8[array_size_unknown]; // weak
 __int16 word_4F0704[array_size_unknown]; // weak
 __int16 word_4F0754[array_size_unknown]; // weak
 __int16 word_4F07B6[array_size_unknown]; // weak
 __int16 word_4F07B8[array_size_unknown]; // weak
 __int16 word_4F0866[array_size_unknown]; // weak
 void *off_4F0882; // weak
 int dword_4F08EC[array_size_unknown]; // weak
 char byte_4F09B0[array_size_unknown]; // weak
 char byte_4F09B1[array_size_unknown]; // weak
 char byte_4F09B8[array_size_unknown]; // weak
 _UNKNOWN unk_4F09CC; // weak
 char byte_4F0CCF[array_size_unknown]; // weak
 char byte_4F0D38[array_size_unknown]; // weak
 int dword_4F0E90[array_size_unknown]; // weak
 int dword_4F0E94[array_size_unknown]; // weak
 __int16 word_4F0F30[array_size_unknown]; // weak


 void *off_4F2D68; // weak
 LPVOID off_4F2D6C; // idb
 int dword_4F2D78; // weak
 void **off_4F4D88; // weak
 int dword_4F4D8C; // weak
 int (__cdecl *off_4F4DA0)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // weak
 double dbl_4F5372; // weak
 _UNKNOWN unk_4F54B8; // weak
 _UNKNOWN unk_4F54D0; // weak
 int dword_4F5B24[array_size_unknown]; // weak
 int dword_4F5BF4[array_size_unknown]; // weak
 int dword_4F5CC4[array_size_unknown]; // weak
 int dword_4F5D98[array_size_unknown]; // weak
 int dword_4F5D9C; // weak
 int dword_4F5E68[array_size_unknown]; // weak
 int dword_4F6638[array_size_unknown]; // weak
 int dword_4F6E08[array_size_unknown]; // weak
 int dword_4F75D8; // weak
 int dword_4F75E0[array_size_unknown]; // weak
 int dword_4F7DB0[array_size_unknown]; // weak
 int dword_4F8580[array_size_unknown]; // weak
 int dword_4F8584[array_size_unknown]; // weak
 int dword_4F8588[array_size_unknown]; // weak
 _UNKNOWN unk_4F8858; // weak
 int dword_4F885C; // weak
 int dword_4F8864; // weak
 int dword_4F886C; // weak
 int dword_4F8870; // weak
 int dword_4F8874; // weak
 int dword_4F8878[array_size_unknown]; // weak
 int dword_4FA9B0[array_size_unknown]; // weak
 char byte_4FAA00; // weak
 _UNKNOWN unk_4FAA08; // weak
 _UNKNOWN unk_4FAA20; // weak
 char byte_4FAA24; // weak
 int dword_4FAA28; // weak
 char byte_4FAA2C; // weak
 char byte_4FAA2D; // weak
 char byte_4FAA2E; // weak
 int dword_4FAA34; // weak
 int dword_4FAA38; // weak
 int dword_4FAA3C; // weak
 int dword_4FAA40; // weak
 int dword_4FAA44; // weak
 int dword_4FAA48; // weak
 int dword_4FAA4C; // weak
 int dword_4FAA50; // weak
 int dword_4FAA54; // weak
 int dword_4FAA58; // weak
 int dword_4FAA5C; // weak
 int dword_4FAA60; // weak
 int dword_4FAA64; // weak
 int dword_4FAA68; // weak
 int dword_4FAA6C; // weak
 int dword_4FAA70; // weak
 char byte_4FAA74; // weak
 __int16 word_4FAA75; // weak
 char byte_4FAA77; // weak
 int dword_4FAA78[array_size_unknown]; // weak
 char byte_4FAA7C[array_size_unknown]; // weak
 int dword_4FAA80[array_size_unknown]; // weak
 int dword_4FAA84[array_size_unknown]; // weak
 int dword_4FAA88; // weak
 int dword_4FAA8C; // weak
 int dword_4FAA90; // weak
 int dword_4FAA94; // weak
 int dword_4FABB8; // weak
 int dword_4FABBC; // weak
 int dword_4FABC0; // weak
 int dword_4FABC4; // weak
 int dword_4FABC8; // weak
 char byte_4FABD0[array_size_unknown]; // weak
 char byte_4FABD1[array_size_unknown]; // weak
 _UNKNOWN unk_4FABD4; // weak
 int dword_4FABD8; // weak
 int dword_4FABDC; // weak
 int dword_4FABE0; // weak
 int dword_4FABE4; // weak
 int dword_4FABE8; // weak
 int dword_4FABEC; // weak
 int dword_4FABF0; // weak
 int dword_4FABF4; // weak
 int dword_4FABF8; // weak
 int dword_4FABFC; // weak
 int dword_4FAC00; // weak
 int dword_4FAC04; // weak
 int dword_4FAC08; // weak
 int dword_4FAC0C; // weak
 int dword_4FAC10; // weak
 _UNKNOWN unk_4FAC14; // weak
 _UNKNOWN unk_505289; // weak
 char byte_5052A8[array_size_unknown]; // weak
 _UNKNOWN unk_5052C8; // weak
 int dword_505314[array_size_unknown]; // weak
 char byte_5054C8[32]; // idb
 char byte_5054E8[array_size_unknown]; // weak
 char byte_5054EA[array_size_unknown]; // weak
 int dword_505554[array_size_unknown]; // weak
 _UNKNOWN unk_505704; // weak
 char byte_505708[32]; // idb
 char byte_505728[array_size_unknown]; // weak
 int dword_50572C[array_size_unknown]; // weak
 int dword_505730[array_size_unknown]; // weak
 int dword_505734[array_size_unknown]; // weak
 int dword_505738[array_size_unknown]; // weak
 int dword_50573C[array_size_unknown]; // weak
 int dword_505740[array_size_unknown]; // weak
 int dword_505744[array_size_unknown]; // weak
 int dword_505748[array_size_unknown]; // weak
 int dword_50574C[array_size_unknown]; // weak
 int dword_505774; // weak
 int dword_505778[array_size_unknown]; // weak
 char byte_5057C4[32]; // idb
 char byte_5057E4; // weak
 int dword_5057E8; // weak
 int dword_5057EC; // weak
 int dword_5057F0; // weak
 int dword_5057F4; // weak
 int dword_5057F8; // weak
 int dword_5057FC; // weak
 int dword_505800; // weak
 int dword_505804; // weak
 char byte_505880; // weak
 char byte_505881; // weak
 int dword_505884; // weak
 int dword_505888; // weak
 int dword_50588C; // weak
 int dword_505890; // weak

struct unnamed_505898 struct_505898;
 /*
 char byte_505898; // weak
 int dword_5058A0; // weak
 _UNKNOWN unk_5058A4; // weak
 char byte_5058A8; // weak
 struct tagMSG Msg_global; // idb
 int dword_5058C8; // weak
 int dword_5058CC; // weak
 char byte_5058D0; // weak
 char byte_5058D2; // weak
 int dword_5058D4; // weak
 int dword_5058D8; // weak
 int dword_5058DC; // weak
 int dword_5058E0; // weak
 int dword_5058E4; // weak
 __int16 word_5058EC; // weak
 int dword_505940; // weak
 int dword_505944; // weak
 int dword_505948; // weak
 char Dest[32]; // idb
 char byte_50596C[32]; // idb
 char byte_50598C; // weak
 char byte_50598D; // weak
 char byte_50598E; // weak
 char byte_50598F; // weak
 char byte_505990; // weak
 char byte_505991; // weak
 char byte_505992; // weak
 */
 int dword_5059A8[480]; // 
 bool bTextureLoading; // dword @ MM7.exe::00506128
 char byte_506130[array_size_unknown]; // weak
 int dword_506338; // weak
 int dword_50633C; // idb
 int dword_506340; // weak
 int dword_506344; // weak
 int dword_506348; // weak
 __int64 qword_506350; // weak

class cTexture* dword_506358[2]; // weak
 //int dword_50635C; // weak
 char byte_506360; // weak
 int dword_506364; // weak
class cTexture* dword_506368; // weak
class cTexture* dword_50636C; // idb
class cTexture* dword_506370; // weak
class cTexture* dword_506374; // idb
class cTexture* dword_506378; // weak
class cTexture* dword_50637C; // idb
class cTexture* dword_506380; // weak
class cTexture* dword_506384; // idb
class cTexture* dword_506388; // weak
class cTexture* dword_50638C; // idb
class cTexture* dword_506390; // weak
class cTexture* dword_506394; // idb
class cTexture* uTextureID_tab_an_7a__zoot_off = 0; // dword @ MM7.exe::00506398
class cTexture* uTextureID_tab_an_6a__zoom_off = 0; // dword @ MM7.exe::0050639C
class cTexture* uTextureID_tab_an_7b__zoot_on = 0;  // dword @ MM7.exe::005063A0
class cTexture* uTextureID_tab_an_6b__zoom_on = 0;  // dword @ MM7.exe::005063A4
class cTexture* pTexture_TownPortal_Icons[6]; // dword[6] @ MM7.exe::005063A8

 int dword_5063D8[array_size_unknown]; // weak
 int dword_506404; // weak
 int dword_506408[array_size_unknown]; // weak
 int dword_50640C[array_size_unknown]; // weak
 int dword_506434; // weak
 int uTextureID_right_backgr; // weak
 int dword_50643C; // weak
 int dword_506440; // idb
 int dword_506444; // idb
 int dword_506448; // weak
 int dword_506450[array_size_unknown]; // weak
 int dword_506454[array_size_unknown]; // weak
 _UNKNOWN unk_506494; // weak
unsigned int dword_506498_uTextureID_MapBrdr; // weak
 int dword_50649C[array_size_unknown]; // weak
 int dword_5064A0[array_size_unknown]; // weak
 int dword_5064C4; // weak
class cTexture* uTextureID_divbar = 0; // dword @ MM7.exe::005064C8
class cTexture* dword_5064CC; // weak
class cTexture* pTexture_SpellbookPage_Map; // dword @ MM7.exe::005064D0
class cTexture* dword_5064D4; // weak
class cTexture* uTextureID_sbAutonotes = 0;                    // dword @ MM7.exe::005064D8
class cTexture* uTextureID_lb_bordr__townport__sbquicknot = 0; // dword @ MM7.exe::005064DC
class cTexture* dword_5064E0; // weak
class cTexture* dword_5064E4; // weak
class cTexture* dword_5064E8; // weak
class cTexture* dword_5064EC; // weak
class cTexture* dword_5064F0; // weak
struct GUIButton *dword_5064F4 = 0; // weak
struct GUIButton *dword_5064F8 = 0; // weak
struct GUIButton *dword_5064FC = 0; // weak
struct GUIButton *dword_506500 = 0; // weak
struct GUIButton *dword_506504 = 0; // weak
struct GUIButton *dword_506508 = 0; // weak
struct GUIButton *dword_50650C = 0; // weak
struct GUIButton *dword_506510 = 0; // weak
struct GUIButton *dword_506514 = 0; // weak
struct GUIButton *dword_506518 = 0; // weak
 int dword_50651C; // weak
 int dword_506520; // weak
 int dword_506524; // weak
 int dword_506528; // weak
 int dword_50652C; // weak
 int dword_506530; // weak
 int dword_506534; // weak
 int dword_506538; // weak
 int dword_50653C; // weak
 int dword_506540; // weak
 int dword_506544; // weak
 int dword_506548; // weak
 int dword_50654C; // weak
 char byte_506550; // weak

 int dword_506568; // weak
 char byte_50656C; // weak
 int dword_506578; // weak

Actor         stru_506580_MonsterInfoUI_Doll;             // struct @ MM7.exe::00506580
unsigned char stru_506580_MonsterInfoUI_bDollInitialized; // byte   @ MM7.exe::005068C4

 int dword_506978; // weak
 char byte_50697C = 0;
 int dword_506980; // weak
 int dword_506984; // weak
 int dword_506988; // weak
 int dword_50698C; // weak


 int dword_506E68; // weak
 _WORD byte_506E6C[18]; // idb
 int dword_506E90[30]; // weak

 int dword_506F08; // weak
 int dword_506F0C; // weak
 int dword_506F10; // weak
 int dword_506F14; // weak
 int dword_506F18; // weak
 int dword_506F1C; // weak

 int dword_506F48; // weak

 GUIWindow *pGUIWindow_MainMenu = 0; // ptr @ MM7.exe::00506F4C
//int dword_506F4C; // idb


 GUIWindow GUIWindow_List[20];  // struct array @ MM7.exe::00506F50
//int dword_506F50[array_size_unknown]; // weak
//int dword_506F54; // weak
//int dword_506F60; // weak
//int dword_506F64; // weak
//int array_506F68[420]; // GUIWindow_List[0]::bSlotUsed
//_UNKNOWN unk_506F68; // weak
//int dword_506F78; // weak
//int dword_506F7C; // weak
//int dword_506F80; // weak
//int dword_506F84; // weak
//int dword_506F88; // weak
//int dword_506F94; // weak
//int dword_506F9C; // weak

 int array_5075E0[20]; // array @ MM7.exe::005075E0
int sLastGUIWindowIdx; // dword @ MM7.exe::00507630
struct GUIButton *dword_507634; // weak
struct GUIButton *dword_507638; // weak
struct GUIButton *dword_50763C; // weak
struct GUIButton *dword_507640; // weak
struct GUIButton *dword_507644; // weak
 int dword_507648; // weak
 int dword_50764C; // weak
 int dword_507650; // weak
 int dword_507654; // weak
 int dword_507658; // weak
 int dword_50765C; // weak

 unsigned int uTextureIdx_Leather; // dword @ MM7.exe::00507664

 int dword_507668; // weak
 int dword_50766C; // weak
 int dword_507670; // weak
 int dword_507674; // weak
struct GUIButton *pCharacterUI_BtnExit;      // dword @ MM7.exe::0050767C
struct GUIButton *pCharacterUI_BtnAwards;    // dword @ MM7.exe::00507680
struct GUIButton *pCharacterUI_BtnInventory; // dword @ MM7.exe::00507684
struct GUIButton *pCharacterUI_BtnSkills;    // dword @ MM7.exe::00507688
struct GUIButton *pCharacterUI_BtnStats;     // dword @ MM7.exe::0050768C
struct GUIButton *dword_507690; // weak
struct GUIButton *pCharacterUI_BtnDetail; // weak		dword_507694

 unsigned int uTextureID_WindowEdgeTop;          // dword @ MM7.exe::00507698
 unsigned int uTextureID_WindowEdgeRight;        // dword @ MM7.exe::0050769C
 unsigned int uTextureID_WindowEdgeLeft;         // dword @ MM7.exe::005076A0
 unsigned int uTextureID_WindowEdgeBottom;       // dword @ MM7.exe::005076A4
 unsigned int uTextureIdx_CornerUpperRight; // dword @ MM7.exe::005076A8
 unsigned int uTextureIdx_CornerUpperLeft;  // dword @ MM7.exe::005076AC
 unsigned int uTextureIdx_CornerLowerRight; // dword @ MM7.exe::005076B0
 unsigned int uTextureIdx_CornerLowerLeft;  // dword @ MM7.exe::005076B4
 unsigned int uTextureIdx_Parchment;        // dword @ MM7.exe::005076B8

 unsigned int uTextureIdx_MonsterHP_BarYellow; // dword @ MM7.exe::005076BC
 unsigned int uTextureIdx_MonsterHP_BarRed;    // dword @ MM7.exe::005076C0
 unsigned int uTextureIdx_MonsterHP_BarGreen;  // dword @ MM7.exe::005076C4
 unsigned int uTextureIdx_MonsterHP_CapRight;  // dword @ MM7.exe::005076C8
 unsigned int uTextureIdx_MonsterHP_CapLeft;   // dword @ MM7.exe::005076CC
 unsigned int uTextureIdx_MonsterHP_Bg;        // dword @ MM7.exe::005076D0

struct GUIButton *dword_5076F4; // ptr_507BC0->pControlsHead
struct GUIButton *dword_5076FC; // weak


 int dword_50792C; // weak
 int dword_507930; // weak
 int dword_507934; // weak
 int dword_507938; // weak
 int dword_50793C; // weak
 int dword_507940; // weak
 int dword_507944; // weak
 char byte_507948; // weak
 char byte_507949; // weak
 char byte_50794A; // weak

 unsigned int uTextureIdx_ib_td5_A; // dword @ MM7.exe::0050794C
 unsigned int uTextureIdx_ib_td2_A; // dword @ MM7.exe::00507950
 unsigned int uTextureIdx_ib_td1_A; // dword @ MM7.exe::00507954

unsigned int uTextureIdx_InventoryBackground; // dword @ MM7.exe::00507958
 int dword_50795C_TextureID; // weak NPC slot texture
 int dword_507960_TextureID; // weak 4 small spell icons around player portrait
 int dword_507964_TextureID; // weak
 int dword_507968_TextureID; // weak
 int dword_50796C_TextureID; // weak

 unsigned int uTextureIdx_ib_m4d_a;    // dword @ MM7.exe::00507970
 unsigned int uTextureIdx_ib_m3d_a;    // dword @ MM7.exe::00507974
 unsigned int uTextureIdx_ib_m2d_a;    // dword @ MM7.exe::00507978
 unsigned int uTextureIdx_ib_m1d_a;    // dword @ MM7.exe::0050797Ñ
 unsigned int uTextureIdx_ib_autout_a; // dword @ MM7.exe::00507980
 unsigned int uTextureIdx_ib_autin_a;  // dword @ MM7.exe::00507984

 int dword_507988; // weak
 unsigned int uTextureIdx_ib_npcrd_a; // dword @ MM7.exe::0050798C
 unsigned int uTextureIdx_ib_npcld_a; // dword @ MM7.exe::00507990

unsigned int uTextureID_MinimapDirections;

unsigned int uTextureIdx_MinimapCompass; // dword    @ MM7.exe::005079B4

 unsigned int uTextureIdx_UIBarRed;    // dword @ MM7.exe::005079B8
 unsigned int uTextureIdx_UIBarYellow; // dword @ MM7.exe::005079BC
 unsigned int uTextureIdx_UIBarGreen;  // dword @ MM7.exe::005079C0
 unsigned int uTextureIdx_UIBarBlue;   // dword @ MM7.exe::005079C4

 int dword_5079C8; // weak
 int dword_5079CC; // weak
unsigned int uTextureIdx_SensorGreen; // dword @ MM7.exe::005079D0
unsigned int uTextureIdx_MinimapMask; // dword @ MM7.exe::005079D8
unsigned int uTextureID_5079E4; // weak
struct GUIButton *pBtn_Game_NPCScrollRightDown = 0; // dword @ MM7.exe::005079E8
struct GUIButton *pBtn_Game_NPCScrollLeftDown = 0;  // dword @ MM7.exe::005079EC
struct GUIButton *pBtn_Game_Options = 0;            // dword @ MM7.exe::005079F0
struct GUIButton *pBtn_Game_QuickRef = 0;           // dword @ MM7.exe::005079F4
struct GUIButton *pBtn_Game_CastSpell = 0;          // dword @ MM7.exe::005079F8
struct GUIButton *pBtn_Game_Rest = 0;               // dword @ MM7.exe::005079FC
struct GUIButton *pBtn_Game_Inventory = 0;          // dword @ MM7.exe::00507A00
struct GUIButton *pBtn_Game_Calendar = 0;           // dword @ MM7.exe::00507A04
struct GUIButton *pBtn_Game_Maps = 0;               // dword @ MM7.exe::00507A08
struct GUIButton *pBtn_Game_Autonotes = 0;          // dword @ MM7.exe::00507A0C
struct GUIButton *pBtn_Game_Quests = 0;             // dword @ MM7.exe::00507A10
struct GUIButton *pBtn_Game_MinimapZoomIn = 0;      // dword @ MM7.exe::00507A14
struct GUIButton *pBtn_Game_MinimapZoomOut = 0;     // dword @ MM7.exe::00507A18

struct GUIButton *pMainMenu_Exit = 0;     // ptr @ MM7.exe::00507AE4
struct GUIButton *pMainMenu_Credits = 0;  // ptr @ MM7.exe::00507AE8
struct GUIButton *pMainMenu_LoadGame = 0; // ptr @ MM7.exe::00507AEC
struct GUIButton *pMainMenu_NewGame = 0;  // ptr @ MM7.exe::00507AF0

int dword_507AF8; // idb
 int dword_507AFC; // idb
 int dword_507B00; // weak
unsigned int uTextureID_507B04_CurrentRightPanelType; // weak



 int dword_507B94; // weak
 int dword_507B98_bCtrlPressed; // weak
struct GUIButton *dword_507B9C; // weak
struct GUIButton *dword_507BA0; // weak
struct GUIButton *dword_507BA4; // weak

// struct cTexture *pcTexture_ibground = 0; // ptr @ MM7.exe::00507BA8
unsigned int uTextureID_ibground = -1; // dword @ MM7.exe::00507BA8 addon, used to be obj ptr

 int dword_507BAC; // weak
 int dword_507BB0; // weak

//int dword_507BB4; // idb
 GUIWindow *pGUIWindow0 = 0; // ptr @ MM7.exe::00507BB4

 int dword_507BB8; // idb
GUIWindow *pDialogueWindow = 0; // dword @ MM7.exe::00507BBC
GUIWindow *ptr_507BC0 = 0;      // dword @ MM7.exe::00507BC0
GUIWindow *ptr_507BC4 = 0;      // dword @ MM7.exe::00507BC4
 int dword_507BC8; // weak

GUIWindow *ptr_507BD0 = 0; //  dword @ MM7.exe::00507BD0
GUIWindow *ptr_507BD4 = 0; // idb  dword @ MM7.exe::00507B4
GUIWindow *ptr_507BDC = 0; // weak
GUIWindow *ptr_507BE0 = 0; // dword @ MM7.exe::00507BE0

 GUIWindow *pGUIWindow2 = 0;         // ptr   @ MM7.exe::00507BE4
 unsigned int      uActiveCharacter; // dword @ MM7.exe::00507BEC
 int dword_507BF0; // weak
 int dword_507BF4; // weak
 int dword_507BF8; // weak
 int dword_507BFC; // weak
 int dword_507C00; // weak
 int dword_507C04; // weak
 int dword_507C08; // weak
 int dword_507C0C; // weak
 int dword_507C10; // weak
 int dword_507C14; // weak
 int dword_507C18; // weak
 int dword_507C1C; // weak
 int dword_507C20; // weak
 int dword_507C24; // weak

unsigned int uTextureID_GammaPositions[10]; // dword[10] @ MM7.exe::00507C28
 int dword_507C50; // weak
 int dword_507C54; // weak
 int dword_507C58; // weak
 int dword_507C60; // weak
unsigned int dword_507C64_TextureID[3]; // weak
 int dword_507C70; // weak
 int dword_507C74; // weak
 int dword_507C84; // weak
unsigned int uTextureID_SoundLevels[10]; // dword[10] @ MM7.exe::00507C88
 int dword_507CB0; // weak
 int dword_507CB4; // weak
 int dword_507CB8; // weak
 int dword_507CBC; // weak
 int dword_507CC0; // weak
 __int64 qword_507CC8; // weak
 int dword_507CD4; // weak
 int dword_507CD8; // weak



struct OldCamera *pOldCamera = 0;          // struct     @ MM7.exe::00507CE0
struct RenderVertex array_507D30[50];    // struct[50] @ MM7.exe::00507D30
struct RenderVertex array_508690[50];    // struct[50] @ MM7.exe::00508690
struct RenderVertex array_508FF0[50];    // struct[50] @ MM7.exe::00508FF0
struct RenderVertex array_509950[50];    // struct[50] @ MM7.exe::00509950
struct RenderVertex array_50A2B0[50];    // struct[50] @ MM7.exe::0050A2B0
struct RenderVertex array_50AC10[50];    // struct[50] @ MM7.exe::0050AC10


 int dword_50B570[array_size_unknown]; // weak
 int dword_50B638[array_size_unknown]; // weak
 int dword_50B700; // weak
 int dword_50B738[array_size_unknown]; // weak
 int dword_50B740; // weak
 int dword_50B744[array_size_unknown]; // weak
 int dword_50B828[array_size_unknown]; // weak
 int dword_50B830; // weak
 int dword_50B834[array_size_unknown]; // weak
 int dword_50B918[array_size_unknown]; // weak
 int dword_50B920; // weak
 int dword_50B924[array_size_unknown]; // weak
 int dword_50B9D4[array_size_unknown]; // weak
 int dword_50B9D8[array_size_unknown]; // weak
 int dword_50B9DC[array_size_unknown]; // weak
 int dword_50B9E0[array_size_unknown]; // weak
 int dword_50B9E4[array_size_unknown]; // weak
 int dword_50B9EC[array_size_unknown]; // weak
 int dword_50B9F0[array_size_unknown]; // weak
 int dword_50B9F8[array_size_unknown]; // weak
 int dword_50B9FC[array_size_unknown]; // weak
 int dword_50BA04; // weak
 int dword_50BA08; // weak
 int dword_50BAC4[array_size_unknown]; // weak
 int dword_50BAC8[array_size_unknown]; // weak
 int dword_50BACC[array_size_unknown]; // weak
 int dword_50BAD0[array_size_unknown]; // weak
 int dword_50BAD4[array_size_unknown]; // weak
 int dword_50BADC[array_size_unknown]; // weak
 int dword_50BAE0[array_size_unknown]; // weak
 int dword_50BAE8[array_size_unknown]; // weak
 int dword_50BAEC[array_size_unknown]; // weak
 int dword_50BAF4; // weak
 int dword_50BAF8; // weak


 int dword_50BC10[array_size_unknown]; // weak
 int dword_50BDA0[array_size_unknown]; // weak
 int dword_50BF30[array_size_unknown]; // weak
 char byte_50C0C0; // weak
 int dword_50C0C4; // weak
 

struct unnamed_50C0C8 struct_50C0C8;
 //_UNKNOWN unk_50C0C8[256*array_size_unknown]; // weak
 _UNKNOWN unk_50C190; // weak
 _UNKNOWN unk_50C198; // weak

 unsigned int dword_50C96C[5]; //
//int dword_50C970; // weak
//int dword_50C974; // weak
//int dword_50C978; // weak
//int dword_50C97C; // weak

 int dword_50C980; // weak
 int dword_50C984; // weak

 unsigned int uIconTableFrameID_CharacterFrame = -1; // dword @ MM7.exe::0050C988
 unsigned int uTextureIdx_CharacterSelectionFrame; // dword @ MM7.exe::0050C98C
 int dword_50C990; // weak
 int dword_50C994; // weak
 int dword_50C998; // weak
 int dword_50C99C; // weak
 int dword_50C9A0; // weak
struct ItemGen *ptr_50C9A4; // dword @ MM7.exe::0050C9A4
 int dword_50C9A8; // weak
 int dword_50C9AC; // weak
struct GUIButton *dword_50C9B0; // weak
struct GUIButton *dword_50C9B4; // weak
struct GUIButton *dword_50C9B8; // weak
struct GUIButton *dword_50C9BC; // weak
struct GUIButton *dword_50C9C0; // weak
struct GUIButton *dword_50C9C4; // weak
struct GUIButton *dword_50C9C8; // weak
struct GUIButton *dword_50C9CC; // weak

 int dword_50C9D0; // weak
 int dword_50C9D4; // weak
 int dword_50C9D8; // weak

 int dword_50C9DC; // weak

struct NPCData *dword_50C9E0; // weak

// int dword_50CBD4[40][3]; // weak
//int dword_50CBD8[array_size_unknown]; // weak
// int dword_50CBDC; // weak
 int dword_50CDC8; // weak
 int dword_50CDCC; // weak
 _UNKNOWN unk_50CDD0; // weak
 _UNKNOWN unk_50CDD4; // weak
 _UNKNOWN unk_50CDFC; // weak
 char byte_50D9D0; // weak
 _UNKNOWN unk_50D9D8; // weak
 _UNKNOWN unk_50DA04; // weak
 char byte_50E5D8; // weak
 _UNKNOWN unk_50E5E0[1000]; // weak	   arrays!!!
 _UNKNOWN unk_50E5E4[1000]; // weak
 _UNKNOWN unk_50E5FC[1000]; // weak
 _UNKNOWN unk_50E600[1000]; // weak
 _UNKNOWN unk_50E60C[1000]; // weak
 char byte_50F1E0; // weak



unsigned int bNotIntelCPU; // dword @ MM7.exe::0050FDEC
 int dword_50FDFC; // weak
 int dword_50FE00; // weak
 int dword_50FE04; // weak
 int dword_50FE08; // weak
 _UNKNOWN unk_510064; // weak
 char byte_5101F4[array_size_unknown]; // weak
 char byte_510258[array_size_unknown]; // weak
 _UNKNOWN unk_5102BC; // weak
 int dword_51076C; // weak
 int dword_510774; // weak

 struct class36 class36_global0; // struct @ MM7.exe::005107A8
 float flt_5107B8[620]; // idb
 //char byte_51117E[array_size_unknown]; // byte_5111C0 - 66
//int dword_5111AC; // class36_global0::dword_000A04
//int dword_5111B0; // class36_global0::dword_000A08

// char byte_5111B8[4]; // shifted IsPlayerWearingWatersuit
char IsPlayerWearingWatersuit[4]; // byte @ MM7.exe::005111B9      4-5 bytes ?

 char byte_5111C0[54]; 
 char byte_5111F6[18]; 
unsigned int pPaperdollTextures_Beards[4]; // dword[4] @ MM7.exe::00511208
 int dword_51120C; // weak
unsigned int uTextureID_ButtExit1; // dword @ MM7.exe::00511210
 int dword_511214; // weak
 int dword_511218; // weak
 int dword_51121C; // weak
 int dword_511220; // weak
 int dword_511224; // weak
 int dword_511228; // weak
 int dword_51122C; // weak
 int dword_511230; // weak
 int dword_511234; // weak
unsigned int pPaperdollTextures_RightHands[4];      // dword[4] @ MM7.exe::0051124C
unsigned int pPaperdollTextures_LeftHandsWeapon[4]; // dword[4] @ MM7.exe::0051125C
unsigned int pPaperdollTextures_LeftHandsEmpty[4];  // dword[4] @ MM7.exe::0051126C
unsigned int pPaperdollTextures_Bodies[4];          // dword[4] @ MM7.exe::0051127C
 
 int dword_511290[204]; // texture ids for players in party (ends at 5115C0)
 //int dword_511294[array_size_unknown]; // weak
 //int dword_511298[array_size_unknown]; // weak
 //int dword_51132C; 

unsigned int pPaperdollTextures_LeftArmsWeapon[4]; // dword[4] @ MM7.exe::005115C0
unsigned int pPaperdollTextures_LeftArmsEmpty[4];  // dword[4] @ MM7.exe::005115D0
unsigned int pPaperdollTextures_Feet[4];           // dword[4] @ MM7.exe::005115E0

unsigned int uTextureListForPaperdoll[89]; // dword @ MM7.exe::00511638
 //int dword_51164C[array_size_unknown]; // 00511638 + 20
 //int dword_511698[52];  // 00511638 + 96 
 //int dword_511718[array_size_unknown]; // weak
 //int dword_51172C[]; 
 //_UNKNOWN unk_511730; // weak
 //int dword_511788[array_size_unknown]; // weak

 int dword_51179C; // weak
 int dword_5117A0; // weak
 int dword_5117A4; // weak
 int dword_5117A8; // weak
 int dword_5117AC; // weak
 int dword_511828[array_size_unknown]; // weak
 int dword_51183C; // weak
 int dword_511840; // weak
 int dword_511844; // weak
 int dword_511848; // weak
 int dword_51184C; // weak
 int dword_5118C8; // weak


struct struct5         array_5118E8[100]; // struct[100] @ MM7.exe::005118E8
struct RenderBillboard pBillboardRenderList[500]; // struct[500] @ MM7.exe::00512250
unsigned int           uNumBillboardsToDraw;      // dword       @ MM7.exe::005187E0

 int dword_5187E4; // weak
 int dword_5187E8; // weak
 int dword_5187EC; // weak

struct StationaryLightsStack *pStationaryLightsStack = 0; // struct @ MM7.exe::005187F0


 _UNKNOWN unk_519AB8; // weak

struct struct6 array_519ABC[400]; // struct[400] @ MM7.exe::00519ABC
//_UNKNOWN unk_519ABC; // weak
//_UNKNOWN unk_519ABE; // weak
//_UNKNOWN unk_519AC2; // weak
 int dword_51B6DC; // num of elements in array_519ABC

 int dword_51B6E0; // weak
 char byte_51B6E4; // weak
 int dword_51B6E8; // weak
 int dword_51B6EC; // weak
 int dword_51B6F0; // weak
 int dword_51B6F4; // weak
 int dword_51B6F8; // weak
 int dword_51B6FC; // weak
 int dword_51B700; // weak
 int dword_51B704; // weak
 int dword_51B708; // weak
 int dword_51B70C; // weak
 float flt_51B710; // weak
 int dword_51B714; // weak
 int dword_51B718; // weak
 int dword_51B71C; // weak
 _UNKNOWN unk_51B720; // weak
 __int16 word_51B722; // weak
 int dword_51B724; // weak
 int dword_51B728; // weak
 int dword_51B734; // weak
 int dword_51B738; // weak
 int dword_51B73C; // weak
 int dword_51B740; // weak
 int dword_51B748; // weak
 int dword_51B754; // weak
 int dword_51B758; // weak
 int dword_51B75C; // weak
 int dword_51B760; // weak
 int dword_51B764; // weak
 int dword_51B768; // weak
 int dword_51B76C; // weak
 int dword_51B770; // weak
 int dword_51B774; // weak

struct class37 class37_global0; // struct @ MM7.exe::0051B778
 __int16 word_51B77C[array_size_unknown]; // weak
 int dword_51C71C; // weak
 __int16 word_51C720[array_size_unknown]; // weak
 __int16 word_51C722; // weak
 __int16 word_51C724; // weak
 __int16 word_51C726; // weak
 __int16 word_51C728; // weak
 _UNKNOWN unk_51C72C; // weak
 _UNKNOWN unk_51C730; // weak
 __int16 word_51CEC4; // weak
 int dword_51CEC8; // weak
 _UNKNOWN unk_51CECC; // weak
 _UNKNOWN unk_51CF2C; // weak


 int dword_56EEA8; // weak
 __int16 word_56EEAC[array_size_unknown]; // weak
 //unsigned short array_56EFD8[137 * 117 + array_size_unknown]; // used in drawing minimap, now obsolete
 int dword_576D14; // weak
 __int16 word_576D80[array_size_unknown]; // weak


unsigned int uTextureIdx_SpellEffecIcons[14]; // dword[14] @ MM7.exe::00576DE8
unsigned int uIconIdx_Spell21;                // dword     @ MM7.exe::00576E20
unsigned int uIconIdx_Spell27;                // dword     @ MM7.exe::00576E24
 int dword_576E28; // weak
unsigned int dword_576E2C_uDefaultMinimapZoom; // weak

GUIWindow              *pGameLoadingWindow = 0; // new
GUIProgressBar_Generic *pLevelLoadingUI = 0;    // struct @ MM7.exe::00576E30
struct unnamed_576FE8   struct_576FE8;          // struct @ MM7.exe::00576FE8

 __int64 qword_5773B8; // weak
 int dword_5773C0; // weak

struct Event   pSomeOtherEVT_Events[4400]; // struct[4400] @ MM7.exe::005773F0
// int dword_5773F4; // weak
// int dword_5773F8; // weak
unsigned int   uSomeOtherEVT_NumEvents; // dword @ MM7.exe::00584230
unsigned char *pSomeOtherEVT;           // dword @ MM7.exe::00584234

struct Event   pSomeEVT_Events[4400];   // struct[4400] @ MM7.exe::00584238
// int dword_58423C; // weak
// int dword_584240; // weak
unsigned int   uSomeEVT_NumEvents;      // dword @ MM7.exe::00591078
unsigned char *pSomeEVT;                // dword @ MM7.exe::0059107C

 int dword_591080; // weak
 int dword_591084; // weak
struct Actor *pDialogue_SpeakingActor = 0;    // dword @ MM7.exe::00591088
unsigned int  uDialogueType = 0;              // dword @ MM7.exe::0059108C
unsigned int  uDialogue_SpeakingActorID = -1; // dword @ MM7.exe::00591090
 int dword_591094; // weak
 char byte_591098[200]; // idb
 int dword_591160; // weak
 char *dword_591164; // idb
 int dword_591168; // weak
 int dword_59116C; // weak
 int dword_591170; // weak
 int dword_591174; // weak
 int dword_591178; // weak
 int dword_59117C; // weak
 char byte_591180[600]; // idb
 int dword_5913D8[array_size_unknown]; // weak
 int dword_5913F0; // weak
struct GUIButton *dword_5913F4[array_size_unknown]; // weak
unsigned int uTextureID_Dialogue_NPCPortrait[array_size_unknown]; // dword @ MM7.exe::0059140C
 int dword_591424; // weak

cTexture *pcTexture_EndcapTexture; // ptr @ MM7.exe::00591428
//int dword_591428; // idb

 int dword_59142C; // weak
cTexture *uTextureID_Dialogue_Background; // dword @ MM7.exe::00591430
 __int16 word_591438[array_size_unknown]; // weak
 __int16 word_59143A[array_size_unknown]; // weak
 int dword_59143C[array_size_unknown]; // weak
 int dword_591440[array_size_unknown]; // weak
 int dword_591448[array_size_unknown]; // weak
 __int16 word_591454[array_size_unknown]; // weak
 _UNKNOWN unk_591458; // weak
 _UNKNOWN unk_59145C; // weak
 __int16 word_591460; // weak
 __int16 word_591462; // weak
 __int16 word_591464; // weak
 __int16 word_591466; // weak
 __int16 word_591468[array_size_unknown]; // weak
 _UNKNOWN unk_59146C; // weak
 __int16 word_593A36; // weak
 _UNKNOWN unk_597F10; // weak
 int dword_597F18; // weak

unsigned int  uLevelStrOffsets[500]; // dword[500]  @ MM7.exe::00597F20

struct Event  pGlobalEVT_Events[4400]; // struct[4400] @ MM7.exe::005986F0
unsigned int  uGlobalEVT_NumEvents;    // dword        @ MM7.exe::005A5530
unsigned int  uGlobalEVT_Size;         // dword        @ MM7.exe::005A5534
unsigned char pGlobalEVT[46080];       // byte[46080]  @ MM7.exe::005A5538

unsigned char byte_5B0938[2000];   // byte[2000] @ MM7.exe::005B0938
unsigned int  uLevelStrNumStrings; // dword      @ MM7.exe::005B1108
unsigned int  uLevelStrFileSize;   // dword      @ MM7.exe::005B110C
unsigned int  uLevelEVT_NumEvents; // dword      @ MM7.exe::005B1110
unsigned int  uLevelEVT_Size;      // dword      @ MM7.exe::005B1114
unsigned char pLevelStr[9216];     // byte[9216] @ MM7.exe::005B1120
unsigned char pLevelEVT[9216];     // byte[9216] @ MM7.exe::005B3520
 int dword_5B5920; // weak
 int dword_5B5924; // weak
struct unnamed_5B5928 array_5B5928[100];  // struct[100] @ MM7.exe::005B5928
int dword_5B65A8; // weak
int dword_5B65AC; // weak
int dword_5B65B0; // weak
int dword_5B65B4; // weak
int dword_5B65B8; // weak
int dword_5B65BC; // weak
int dword_5B65C0; // weak
int dword_5B65C4; // weak
int dword_5B65C8; // num elements in array_5B5928
int dword_5B65CC; // weak
int dword_5B65D0; // weak

struct Event pLevelEVT_Events[4400]; // struct[4400] @ MM7.exe::005B65D8
//_UNKNOWN unk_5B65D8[0xCE40 + 64*array_size_unknown]; // pLevelEVT_Events[0]::dword_000000
//_UNKNOWN unk_5B65DC; // pLevelEVT_Events[0]::dword_000004
//int dword_5B65E0; // pLevelEVT_Events[0]::dword_000008
//int dword_5B65EC; // pLevelEVT_Events[1]::dword_000008
 _UNKNOWN unk_5C310E; // weak
 int dword_5C3418; // weak
 int dword_5C341C; // weak
 int dword_5C3420; // weak
 char byte_5C3427[array_size_unknown]; // weak
unsigned char byte_5C3428[200]; // idb
unsigned char pStatusBarString[200]; // byte[200] @ MM7.exe::005C34F0
 int dword_5C35B8_Some_GetTickCount_timer; // weak
 int dword_5C35BC; // weak
 int dword_5C35C0; // weak
 int dword_5C35C4; // weak
 int dword_5C35C8; // weak

unsigned char *p2DEventsTXT_Raw = 0; // ptr @ MM7.exe::005C35CC

 int dword_5C35D0; // weak
 int dword_5C35D4; // weak

struct Font *ptr_5C35E0 = 0; // dword @ MM7.exe::005C35E0
struct Font *ptr_5C35E4 = 0; // dword @ MM7.exe::005C35E4

struct Font *pBook2Font = 0; // dword @ MM7.exe::005C35F0
struct Font *pBookFont = 0; // dword @ MM7.exe::005C35F4


struct unnamed_5C3610 stru_5C3610; // struct @ MM7.exe::005C3610


 _UNKNOWN unk_5C4DB0; // weak
unsigned char TmpBuf[array_size_unknown + 2000]; // byte[~2000] @ MM7.exe::005C5DB0
 char byte_5C657F[array_size_unknown]; // weak

 char byte_5C6D50[100]; // weak

 int dword_5C6DD8; // weak
 int dword_5C6DDC; // weak
 int dword_5C6DE0; // weak
 int dword_5C6DE4; // weak
 int dword_5C6DE8; // weak
 char byte_5C6DEC; // weak
 __int64 qword_5C6DF0; // weak
 int dword_5C6DF8; // weak



char byte_5C8678[104]; // idb
//next is pClassDescriptions @ 005C86E0


unsigned char *pAttributeDescriptions[7]; // ptr[7] @ MM7.exe::005C8778
//int dword_5C8778[array_size_unknown]; // weak
 unsigned char *pGrandSkillDescr[38];  //array_5C8810
 unsigned char *pMasterSkillDescr[38];	//array_5C88A8
 unsigned char *pExpertSkillDescr[38];	//array_5C8940
 unsigned char *pNormalSkillDescr[38];  //array_5C89D8
 unsigned char *pSkillDescription[38];	//array_5C8A70

unsigned char *pClassTXT_Raw = 0; // ptr @ MM7.exe::005C8B54
unsigned char *pStatsTXT_Raw = 0; // ptr @ MM7.exe::005C8B58
unsigned char *pSkillDescTXT_Raw = 0; // ptr @ MM7.exe::005C8B5C

struct StorylineText *pStorylineText = 0; // struct @ MM7.exe::005C8B60
//LPCSTR lpsz; // idb
 _DWORD dword_5C8B64[87]; // idb

struct class48 *pClass48 = 0; // struct @ MM7.exe::005C8CC0 
//char byte_5C8CC0[8]; // weak
 _UNKNOWN unk_5C8CC8; // weak
 char byte_5C8D1A[array_size_unknown]; // weak

struct class40 *pClass40 = 0; // struct @ MM7.exe::005D29E0
 int dword_5D29EC[array_size_unknown]; // weak
 int dword_5D29F4[array_size_unknown]; // weak
 __int16 word_5D29F8[array_size_unknown]; // weak
 __int16 word_5D29FC; // weak
 __int16 word_5D29FE; // weak
 int dword_5DAD28[array_size_unknown]; // weak
 int dword_5DBFD0[array_size_unknown]; // weak
 char byte_5DBFE9[array_size_unknown]; // weak
 int dword_5DC1A8[array_size_unknown]; // weak
 int dword_5DC1BC[array_size_unknown]; // weak
 char byte_5DC1CC[array_size_unknown]; // weak
 char byte_5DC1DC[array_size_unknown]; // weak
 __int16 word_5E1944[array_size_unknown]; // weak
 __int16 word_5E2CCC[array_size_unknown]; // weak
 int dword_5E40B8[array_size_unknown]; // weak
 int dword_5E40F8; // weak
 int dword_5E40FC; // weak
 int dword_5E4100; // weak
 int dword_5E4104; // weak
 int dword_5E4108; // weak
 int dword_5E410C; // weak
 int dword_5E4178; // weak


 _UNKNOWN unk_5E4C14; // weak
 char byte_5E4C15[array_size_unknown]; // weak
unsigned char *pSomeItemsNames[14];          // dword[14] @ MM7.exe::005E4C18
unsigned char *pGlobalTXT_Raw = 0;           // dword     @ MM7.exe::005E4C68
unsigned char *pMonstersTXT_Raw = 0;         // dword     @ MM7.exe::005E4C6C
unsigned char *pMonsterPlacementTXT_Raw = 0; // dword     @ MM7.exe::005E4C70
unsigned char *pSpellsTXT_Raw = 0;           // dword     @ MM7.exe005E4C74
unsigned char *pMapStatsTXT_Raw = 0;         // dword     @ MM7.exe::005E4C78
unsigned char *pHostileTXT_Raw = 0;          // dword     @ MM7.exe::005E4C7C
unsigned char *pPotionsTXT_Raw = 0;          // dword     @ MM7.exe::005E4C80
unsigned char *pPotionNotesTXT_Raw = 0;      // dword     @ MM7.exe::005E4C84
unsigned char *pHistoryTXT_Raw = 0;          // dword     @ MM7.exe::005E4C88

struct struct4 global_5E4C90; // struct @ MM7.exe::005E4C90
//char byte_5E4C90[array_size_unknown]; // weak
//char byte_5E4CDA[array_size_unknown]; // weak
//char byte_5E4CDB[array_size_unknown]; // weak
_UNKNOWN unk_5E4D52; // weak


//_UNKNOWN unk_5E4D58; // weak	 
//overlay	 1008 size
unsigned short array_5E4D58[50][10];  // [42][12];

//_UNKNOWN unk_5E4D64; // weak
 //int dword_5E5130[array_size_unknown]; // weak
 int dword_5E5144; // weak

struct struct3                 array_5E5150[20]; // struct[20] @ MM7.exe::005E5150
unsigned int dword_5FF140; // idb

int                            chest_descriptor[2];   //struct @ MM7.exe::005FF144
struct MonsterDescriptionList *pMonsterDescriptionList = 0; // struct @ MM7.exe::05FF14C
//int dword_5FF14C; // weak
//int dword_5FF150; // weak

struct Actor pActors[500]; // struct[500] @ MM7.exe::005FF158
 _UNKNOWN unk_64640F; // weak

unsigned int      uNumActors;             // dword        @ MM7.exe::00665228
unsigned int      uNumLayingItems;        // dword        @ MM7.exe::0066522C
struct LayingItem pLayingItemsList[1000]; // struct[1000] @ MM7.exe::00665230

 int dword_6807B8[array_size_unknown]; // weak
 int dword_6807E0; // weak
 int dword_6807E8[array_size_unknown]; // weak
 int dword_6836C8; // weak

struct LevelDecoration pLevelDecorations[3000]; // struct[3000] @ MM7.exe::006836D0
unsigned int           uNumLevelDecorations;    // dword        @ MM7.exe::0069ADD0

 char word_69ADE0; // idb
class UserInput *pUserInput = 0; // struct @ MM7.exe::0069AE00
// int dword_69AE00; // weak
// int vKey[30]; // dword[30] @ MM7.exe::0069AE0C
// int dword_69AE84[array_size_unknown]; // weak
//unsigned char byte_69AF00[256]; // idb
// char byte_69B001; // weak
 int dword_69B004; // weak
 int pAsyncKeyboard; // dword @ 69B00C
 int dword_69B010[array_size_unknown]; // weak


struct unnamed_69B110 object_69B110; // struct @ MM7.exe::0069B110

 int dword_69B138; // weak
 _UNKNOWN unk_69B140; // weak
 _UNKNOWN unk_69B16C; // weak
 char byte_69BD40; // weak
 char byte_69BD41; // weak
 char byte_69BD44; // weak
 char *dword_69BD48; // idb





 


 _UNKNOWN unk_69FBB4; // weak
 
 //int dword_6A013C[array_size_unknown]; // weak

 //_UNKNOWN unk_6A07A4; // weak


 int global_dword_6A0CA8; // weak
 HWND dword_6A0CFC; // idb
 int dword_6A0D00; // weak

struct unnamed_6A0D14 array_6A0D14[4]; // struct[4] @ MM7.exe::006A0D14
unsigned int          uCurrentMenuID;  // dword     @ MM7.exe::006A0D44

 int dword_6A0D48; // weak

OutdoorLocation class51_6A0DA0_dwReserved;
OutdoorLocation *pClass51_global = &class51_6A0DA0_dwReserved; // struct @ stru_6A0DA0.dwReserved
 struct tagOFNA stru_6A0DA0; // idb
//dwReserved @ 6A0DF0 @ pClass51_global::000000
 int dword_6A12B0; // weak
 int dword_6A12B4; // weak
 //struct 40 bytes
 _UNKNOWN unk_6A12B8; // weak
 int dword_6A12C4; // weak
 int dword_6A12C8; // weak
 int dword_6A12CC; // weak
 int dword_6A12D0; // weak
 //
 __int64 qword_6A12E0; // weak
 int dword_6A12F4; // weak
 int dword_6A12F8; // weak
 int dword_6A12FC; // weak
 _UNKNOWN unk_6A1318; // weak
 //
 _UNKNOWN unk_6A16E0; // weak


 float flt_6BD074; // weak
 int dword_6BD078; // weak
 int dword_6BD07C; // weak

struct unnamed_6BD080 struct_6BD080;
//_UNKNOWN unk_6BD080[1000 + 64*array_size_unknown]; // weak
//int dword_6BE020; // ::dword_000FA4
 int dword_6BE024; // weak
 int dword_6BE030; // weak
 int dword_6BE040; // weak
 int dword_6BE044; // weak

 struct CTileTable *pTileTable = 0; // struct @ MM7.exe::006BE048
//_UNKNOWN unk_6BE048; // pTileTable::uNumTiles
//int dword_6BE04C; // pTileTable::pTiles
 int dword_6BE050; // weak
 int dword_6BE054; // weak
 int dword_6BE058; // weak
 int dword_6BE05C; // weak

union unnamed_6BE060 data_6BE060;


struct struct9 *pStruct9_global; // struct @ MM7.exe::006BE070
 int dword_6BE0C4; // weak
 int dword_6BE0D4; // weak
 int dword_6BE0D8; // weak
 int dword_6BE0DC; // idb
 int dword_6BE0E0; // idb
 int dword_6BE0E4; // weak
 int dword_6BE0E8; // weak
 int dword_6BE0EC; // weak
 int dword_6BE0F0; // weak
 int dword_6BE0F4; // weak
 int dword_6BE0F8; // weak
 int dword_6BE0FC; // weak
 int dword_6BE100; // weak
 int dword_6BE104; // weak
 char byte_6BE108; // weak
 char byte_6BE109; // weak
 char byte_6BE10A; // weak
 char byte_6BE10B; // weak
 char byte_6BE10C; // weak
 char byte_6BE10D; // weak
 char byte_6BE10E; // weak
 char byte_6BE10F; // weak
 char byte_6BE110; // weak
 char byte_6BE111; // weak
 char byte_6BE112; // weak
 char byte_6BE113; // weak
 char byte_6BE114_cfg_textures_DefaultSkyTexture[16]; // idb
 char byte_6BE124_cfg_textures_DefaultGroundTexture[16]; // idb
 int dword_6BE134; // weak
 int dword_6BE138; // weak
 int dword_6BE13C; // weak
 float fWalkSpeedMultiplier = 1.0; // float @ MM7.exe::006BE144
 float flt_6BE148 = 1.0; // weak
 float fTurnSpeedMultiplier = 1.0; // float @ MM7.exe::006BE14C
 float flt_6BE150 = 1.0; // weak
//char byte_6BE2D8[20];
 HINSTANCE hInstance; // idb
 const char *pCommand = 0; // dword @ MM7.exe::006BE2F0     command line passed to application on startup
 unsigned int uWindowWidth; // idb
 unsigned int uWindowHeight; // idb
 unsigned int uWindowPosX; // idb
 unsigned int uWindowPosY; // idb
 LONG dwNewLong; // idb
 HMENU hMenu; // idb
 int dword_6BE340; // weak
unsigned int uLevelMapStatsID; // dword @ MM7.exe::006BE358
 int dword_6BE35C; // weak
unsigned int uCurrentlyLoadedLevelType; // dword @ MM7.exe::006BE360
 int dword_6BE364; // game settings
                   // 0x0001: ?
                   // 0x0002: desktop color depth != 16, unable to start in window
                   // 0x0004: no intro
                   // 0x0008: no logo
                   // 0x0010: no sound
                   // 0x0020: no walk sound
                   // 0x0040: no anim
                   // 0x0100: application is minimized to tray/not active right now
                   // 0x2000: ?
                   // 0x4000: ?

 int dword_6BE368; // debug flags
                   // 0x0001: windowed mode
                   // 0x0002: show FR
                   // 0x0004: no monsters
                   // 0x0008: no decorations
                   // 0x0010: no damage

unsigned char uSoundVolumeMultiplier;  // byte @ 6BE36F  0..9
unsigned char uVoicesVolumeMultiplier; // byte @ 6BE370  0..9
unsigned char uMusicVolimeMultiplier;  // byte @ 6BE371  0..9
 int dword_6BE374_WalkSoundFlag; // weak
 int dword_6BE378_ShowDamageFlag; // weak
unsigned int bAlwaysRun; // dword @ MM7.exe::006BE37C
unsigned int bFlipOnExit; // dword @ MM7.exe::006BE380
 int dword_6BE384_2dacceloff; // weak
 char byte_6BE388_graphicsmode; // weak
int uTurnSpeed; // dword @ MM7.exe::006BE38C
 float flt_6BE3A0; // weak
 float flt_6BE3A4_debug_recmod1; // weak
 float flt_6BE3A8_debug_recmod2; // weak
 float flt_6BE3AC_debug_recmod1_x_1_6; // weak
 char byte_6BE3B0[20]; // idb
 char byte_6BE3C4_MaybeDrowningFlag; // weak
 char byte_6BE3C5; // weak
 char byte_6BE3C8[604]; // idb
 size_t Size; // idb
 int dword_6BE63C; // weak
 int dword_6BE640; // weak
 int dword_6BE644; // weak
 int dword_6BE648; // weak
 int dword_6BE64C; // weak
 int dword_6BE654; // weak
 int dword_6BE658; // weak
 int dword_6BE65C; // weak
 int dword_6BE660; // weak
 void *Src; // idb
 int dword_6BE66C; // weak
 int dword_6BE670; // weak
 void *dword_6BE67C; // idb
 int dword_6BE684; // weak
 int dword_6BE688; // weak

 //struct 40 bytes
 _UNKNOWN unk_6BE68C; // weak
 int dword_6BE694; // weak 8
 int dword_6BE698; // weak	12
 int dword_6BE69C; // weak	16
 int dword_6BE6A0; // weak	20
 int dword_6BE6A4; // weak	24


 //
 __int64 qword_6BE6B4[7]; // weak 
 // bytes875
 char byte_6BE6EC[875]; // weak



//_UNKNOWN unk_702B28[26 * 1024 * 1024];  //some 26 or 16 Mb pointer is allocated at *(int *)((char *)(pClass23) + 120020) at startup
//MemoryMng mem_mng;  // struct @ MM7.exe::00702B28
 int dword_71FFF4; // weak
 int dword_71FFF8; // weak
unsigned int bUseOverrideData;   // dword @ MM7.exe::00720008
unsigned int bNoVideo = false;   // dword @ MM7.exe::0072000C
unsigned int bNoCredits = false; // new
unsigned int bNoIntro = false;   // new
unsigned int bNoSound = false;   // new
unsigned int bNo3DSound = false; // new
int pAsyncMouse; // dword @ MM7.exe::00720010

struct Game *pGame = 0; //struct @ MM7.exe::00720014
//float pGame;
//int dword_720018; // pGame::000004
 _BYTE dword_720020[400]; // idb
 int dword_7201B0[array_size_unknown]; // weak
 int dword_72065C; // weak
 int dword_720660[array_size_unknown]; // weak
 int dword_7207EC; // weak
 int dword_7207F0[array_size_unknown]; // weak
 int dword_720980; // weak
 int dword_720984; // weak
//struct GUICursor *pClass03_global;  //Game::000974, dword @ MM7.exe::00720988
//char  byte_72098C;                //Game::000978, dword @ MM7.exe::00720988
//char  byte_720990;                //Game::00097C, dword @ MM7.exe::00720990
//void *dword_720994;               //Game::000980, ptr   @ MM7.exe::00720994
 __int16 word_7209A0[104]; // weak
 __int16 word_720A70[104]; // weak
 __int16 word_720B40[104]; // weak
 __int16 word_720C10[array_size_unknown]; // weak
 int dword_720CDC; // weak
 __int16 word_720CE0[104]; // weak
 __int16 word_720DB0[104]; // weak
 int dword_720E80[20]; // weak
 int dword_720ED0[20]; // weak
 int dword_720F20[20]; // weak
 __int16 word_720F70[104]; // weak
 __int16 word_721040[104]; // weak
 int dword_721110[20]; // weak
 int dword_721160[20]; // weak
 int dword_7211B0[20]; // weak
 int dword_721200[array_size_unknown]; // weak
 int dword_7212C8[array_size_unknown]; // weak
 __int16 word_721390[104]; // weak
 __int16 word_721460[104]; // weak

struct unnamed_721530 stru_721530; // struct @ MM7.exe::00721530
struct ActionQueue *pPartyActionQueue; // struct @ MM7.exe::007215D8
 int dword_721654; // weak
 int dword_721658; // weak
 int dword_72165C; // weak
unsigned char *dword_721660[array_size_unknown]; // idb
// char *dword_721664; // idb
 _UNKNOWN unk_721668[1024 + 92*array_size_unknown * 2]; // weak
 _UNKNOWN unk_72166C[0x18AC]; // weak
 int dword_721824; // weak
 unsigned char *dword_72193C; // weak
 unsigned char *dword_721984[array_size_unknown]; // weak
 unsigned char *dword_7219DC[array_size_unknown]; // weak
 unsigned char *dword_721A34; // idb
 unsigned char *dword_721A3C; // idb
 unsigned char *dword_721A44; // weak
 unsigned char *dword_721A4C; // weak
 unsigned char *dword_721A64; // weak
 unsigned char *dword_721A6C[array_size_unknown]; // weak
 unsigned char *dword_721A84; // weak
 unsigned char *dword_721BAC[array_size_unknown]; // weak
 unsigned char *dword_721BC4; // idb
 _UNKNOWN dword_721E24; // idb
 int dword_722164; // weak
 int dword_72216C; // weak
 int dword_722174; // weak
 char *dword_72217C; // idb
 int dword_722240[array_size_unknown]; // weak
 int dword_722320; // weak
 int dword_722494; // weak
 int dword_72266C; // weak
 _UNKNOWN unk_722880; // weak
 unsigned char *dword_722B3C; // weak
 unsigned char *dword_722B44; // weak
 char *dword_722F10; // idb
 _UNKNOWN unk_722F14[0x800 + array_size_unknown]; // weak
 _UNKNOWN unk_723714; // weak
 char *dword_723718; // idb
 int dword_72371C[array_size_unknown]; // weak
 _UNKNOWN unk_723724[128 * array_size_unknown]; // weak
 unsigned char *dword_723D38[array_size_unknown]; // idb
 _UNKNOWN unk_723D3C; // weak
 int dword_723E80[210]; // weak
 int dword_723E84[array_size_unknown]; // weak
 _UNKNOWN unk_723E88[832 + array_size_unknown*4]; // weak
 int dword_7241C8; // weak

struct CNPCStats *pNPCStats = 0; // struct @ MM7.exe::007241D0
 int dword_72D6A0[array_size_unknown]; // weak
 int dword_72D6A8; // weak
 _UNKNOWN unk_72D6E0; // weak
 int dword_72D778; // weak
 char byte_72E780; // weak
 int dword_737C28[array_size_unknown]; // weak
 int dword_737C30[array_size_unknown]; // weak
 int dword_73BA54[array_size_unknown]; // weak
 _UNKNOWN unk_73C0C4; // weak
 int dword_73C194; // weak
//int dword_73C1A0[array_size_unknown]; // pNPCStats::dword_017FD0

unsigned char *pAwardsTXT_Raw = 0;    // ptr @ MM7.exe::0073C37C
unsigned char *pScrollsTXT_Raw = 0;   // ptr @ MM7.exe::0073C380
unsigned char *pMerchantsTXT_Raw = 0; // ptr @ MM7.exe::0073C384

 unsigned char dword_73C388[28]; // idb
 int dword_73C3A4[array_size_unknown]; // weak
 CHAR dword_73C3C0[28]; // idb
 int dword_73C3DC[array_size_unknown]; // weak

unsigned char *pTransitionsTXT_Raw = 0; // ptr @ MM7.exe::0073C3F8
unsigned char *pAutonoteTXT_Raw = 0;    // ptr @ MM7.exe::0073C3FC
unsigned char *pQuestsTXT_Raw = 0;      // ptr @ MM7.exe::0073C400

 _UNKNOWN unk_73C818; // weak
 float flt_73C81C; // weak
 float flt_73C820; // weak
 float flt_73C824; // weak
 char byte_73C830; // weak
 _UNKNOWN unk_73C834[array_size_unknown]; // weak
 char byte_73C84C; // weak

/*
unsigned int uNumTerrainNormals; // dword @ MM7.exe::0073D510
 _UNKNOWN unk_73D514[0x20000]; // weak
unsigned short uTerrainNormalIndices[128 * 128 * 2]; // word[32768] @ MM7.exe::0075D514

struct Normal *pTerrainNormals = 0;         // ptr @ MM7.exe::0076D514*/

 int dword_76D518; // weak
 int dword_76D51C; // weak
 int dword_76D520; // weak
 int dword_76D524; // weak
 int dword_76D528; // weak
 int dword_76D52C; // weak
 int dword_76D530; // weak
 int dword_76D534; // weak
 int dword_76D538; // weak
 int dword_76D53C; // weak
 int dword_76D540; // weak
 int dword_76D544; // weak
 int dword_76D548; // weak
 int dword_76D54C; // weak
 int dword_76D550; // weak
 int dword_76D554; // weak
 int dword_76D558; // weak
 int dword_76D55C; // weak
 int dword_76D560; // weak
 int dword_76D564; // weak
 int dword_76D568; // weak
 int dword_76D56C; // weak
 int dword_76D570; // weak
 int dword_76D574; // weak
 _UNKNOWN unk_76D578; // weak
 _UNKNOWN unk_76D590; // weak
 _UNKNOWN unk_76D5A8; // weak

 char byte_76D5C0; // weak

 int dword_76D5C8[128]; // weak

 int dword_76D7C8[128]; // weak

 int dword_76D9C8[128]; // weak

 int dword_76DBC8[128]; // weak

int dword_76DDC8[128]; // dword[128] @ MM7.exe::0076DDC8
int dword_76DFC8[128]; // dword[128] @ MM7.exe::0076DFC8
int dword_76E1C8[128]; // dword[128] @ MM7.exe::0076E1C8
int dword_76E3C8[128]; // dword[128] @ MM7.exe::0076E3C8
 _BYTE byte_76E5C8[64 * 1024]; // idb

struct RenderVertexD3D3  pVertices[50];      // struct[50]   @ MM7.exe::0077E5C8
struct struct8    array_77EC08[2000]; // struct[2000] @ MM7.exe::0077EC08
struct class57   *pClass57_global;    // struct       @ MM7.exe::008019C8
struct RenderVertex  *ptr_801A04;         // ptr          @ MM7.exe::00801A04
struct RenderVertex  *ptr_801A08;         // ptr          @ MM7.exe::00801A08
struct RenderVertex   array_801A10[384];  // struct[384]  @ MM7.exe::00801A10
struct RenderVertex   array_806210[384];  // struct[384]  @ MM7.exe::00806210


 char byte_80AA10; // weak
 int dword_80AA14; // weak
 int dword_80AA18; // weak
 int dword_80AA1C; // weak
 int dword_80AA20; // weak
unsigned int    uNumElementsIn80AA28; // dword        @ MM7.exe::0080AA24
struct struct8 *array_80AA28[2000];   // dword[~2000] @ MM7.exe::0080AA28

struct Edge *ptr_80CA10[480]; // dword[480] @ MM7.exe::0080CA10

struct class35 class35_obj; // struct @ MM7.exe::0080D198
//_UNKNOWN unk_80D198; // weak
//char byte_A74C68; // class35_obj::byte_267AD0
//char byte_A74C69; // class35_obj::byte_267AD1
//char byte_A74C6A; // class35_obj::byte_267AD2
//char byte_A74C6B; // class35_obj::byte_267AD3
//char byte_A74C6C; // class35_obj::byte_267AD4
//char byte_A74C6D; // class35_obj::byte_267AD5
//int dword_A74C70; // class35_obj::dword_267AD8
//int dword_A74C74; // class35_obj::dword_267ADC
//int dword_A74C78; // class35_obj::dword_267AE0
 int dword_A74C88; // weak

struct GUIButton *pBtn_CharacterCreationUI_VoiceNext[4]; // ptr[4] @ MM7.exe::00A74C8C
//int dword_A74C8C[array_size_unknown]; // weak
//int dword_A74C90; // weak
//int dword_A74C94; // weak
//int dword_A74C98; // weak

struct GUIButton *pBtn_CharacterCreationUI_VoicePrev[4]; // ptr[4] @ MM7.exe::00A74C9C
//int dword_A74C9C[array_size_unknown]; // weak
//int dword_A74CA0; // weak
//int dword_A74CA4; // weak
//int dword_A74CA8; // weak

struct GUIButton *array_A74CAC[4]; // ptr[4] @ MM7.exe::00A74CAC
//int dword_A74CAC[array_size_unknown]; // weak
//int dword_A74CB0; // weak
//int dword_A74CB4; // weak
//int dword_A74CB8; // weak

struct GUIButton *array_A74CBC[4]; // ptr[4] @ MM7.exe::00A74CBC
//int dword_A74CBC[array_size_unknown]; // weak
//int dword_A74CC0; // weak
//int dword_A74CC4; // weak
//int dword_A74CC8; // weak

 int dword_A74CCC; // weak
 int dword_A74CD4; // weak

 int dword_A74CDC; // weak

unsigned int uTextureIdx_PlayerFaceEradicated; // dword @ MM7.exe::00A74CE4
unsigned int uTextureIdx_PlayerFaceDead;       // dword @ MM7.exe::00A74CE8

//int dword_A74CEC[array_size_unknown]; // related to indexing of below

//_UNKNOWN unk_A74CF0; // weak

 int dword_A75070; // weak
 char byte_A75074[40]; // idb
 char byte_A7509C[40]; // idb

//struct Player *ptr_A750C4;   //pPlayers[-1] indexing	 0
struct Player *pPlayers[5]; // ptr[4] @ MM7.exe::00A750C8 1
//int dword_A750CC; // weak								  2
//int dword_A750D0; // weak								  3
//int dword_A750D4; // looks like pPlayers[5] indexing	  4	   points to the end of Players[4], used in *pPlayers++ loops to stop

 __int64 qword_A750D8; // 
 __int16 word_A750E0; // weak
 __int16 word_A750E2; // weak

class CPlayerFrameTable *pPlayerFrameTable = 0; // struct @ MM7.exe::00A750EC
//int dword_A750EC; // pPlayerFrameTable::uNumFrames
//int dword_A750F0; // pPlayerFrameTable::pFrames
//start
    char unk_A750F8[4][45016]; // weak	 size 4*AFD8  =2BF60    //sound buffers	 weapon sound 
 _UNKNOWN unk_A81376; // weak
 //_UNKNOWN unk_A96080; // weak	-1 to   unk_AA1058
 //end
 //start
   char unk_AA1058[4][45016]; // weak	size	4*AFD8 = 2BF60	 //sound buffers spell sound
 int dword_ACC038[array_size_unknown]; // weak
 int dword_ACCCEC[21 * 2]; // weak
 int dword_ACCD94[16]; // weak
 int dword_ACCDD4[array_size_unknown]; // weak
  //end


struct Party *pParty_global = 0; // struct @ MM7.exe::00ACCFB8

 _DWORD dword_ACD4E8[36]; // idb
 char byte_ACD719[array_size_unknown]; // weak
 char byte_ACD76D; // weak
 char byte_ACD76E; // weak
 char byte_ACD76F; // weak
 char byte_ACD770; // weak
 char byte_ACD771; // weak
 char byte_ACD772[array_size_unknown]; // weak
 int dword_ACD788[array_size_unknown]; // weak
 int dword_ACD794; // weak
 int dword_ACD82C; // weak
 int dword_ACD830; // weak
 char byte_ACD8C2; // weak
 char byte_ACD8C3; // weak
 char byte_ACD8F2; // weak
 int dword_ACD988[array_size_unknown]; // weak
 int dword_ACD98C; // weak
 int dword_ACD990; // weak
 __int64 qword_ACD994; // weak
 _UNKNOWN unk_ACD99C; // weak
 int dword_ACD9AC; // weak
 int dword_ACD9B0; // weak
 int dword_ACD9B4; // weak
 int dword_ACD9B8; // weak
 int dword_ACD9BC; // weak
 int dword_ACD9C0; // weak
 int dword_ACD9C4; // weak
 int dword_ACD9C8; // weak
 int dword_ACD9CC; // weak
 int dword_ACD9D0; // weak
 int dword_ACD9D4; // weak
 int dword_ACD9D8; // weak
 int dword_ACD9DC; // weak
 int dword_ACD9E0; // weak
 _UNKNOWN unk_ACD9E4; // weak
 _UNKNOWN unk_ACD9FC; // weak
 _UNKNOWN unk_ACDA9C; // weak
 _UNKNOWN unk_ACDAD6; // weak
 _UNKNOWN unk_ACDB98; // weak
 _UNKNOWN unk_ACDBB2; // weak
 _UNKNOWN unk_ACF124; // weak
 _UNKNOWN unk_ACF134; // weak
 _UNKNOWN unk_ACF164; // weak
 _UNKNOWN unk_ACF1C4; // weak
 _UNKNOWN unk_ACF1D4; // weak
 _UNKNOWN unk_ACF1E4; // weak
 __int16 word_ACF2B8[array_size_unknown]; // weak
 int dword_ACF2C0[array_size_unknown]; // weak

 _UNKNOWN unk_ACF3D3; // weak
 _UNKNOWN unk_ACF4BC; // weak
 __int64 qword_ACF4D0; // weak
 int dword_AD0F84[array_size_unknown]; // weak
 int dword_AD0F98[array_size_unknown]; // weak
 __int64 qword_AD100C; // weak
 __int64 qword_AD2B48; // weak
 int dword_AD4650; // weak
 int dword_AD4654[array_size_unknown]; // weak
 int dword_AD4658; // weak
 int dword_AD4734[array_size_unknown]; // weak
 _UNKNOWN unk_AD4738; // weak
 int dword_AD4748[array_size_unknown]; // weak
 _UNKNOWN unk_AD477C; // weak
 _UNKNOWN unk_AD478C; // weak
 _UNKNOWN unk_AD47C6; // weak
 int dword_AD480C[array_size_unknown]; // weak
 _UNKNOWN unk_AD4888; // weak
 _UNKNOWN unk_AD48A2; // weak
 _UNKNOWN unk_AD5DF2; // weak
 _UNKNOWN unk_AD5E14; // weak
 _UNKNOWN unk_AD5E24; // weak
 _UNKNOWN unk_AD5EB4; // weak
 _UNKNOWN unk_AD5EC4; // weak
 _UNKNOWN unk_AD5FB0; // weak
 _UNKNOWN unk_AD61AC; // weak
 int dword_ADA0A4; // idb
 int dword_ADA0B8[array_size_unknown]; // weak
 int dword_ADA17C[array_size_unknown]; // weak
 char byte_AE302C[100]; // idb
 _UNKNOWN unk_AE3090; // weak
 int dword_AE30F8[array_size_unknown]; // weak
 int dword_AE310C[array_size_unknown]; // weak
 int dword_AE31E0; // weak
 int dword_AE31E4; // weak
 int dword_AE31E8; // weak
 int dword_AE31EC; // weak
	//end  AE31F0

 char byte_AE3368[array_size_unknown]; // weak
 char algn_AE3369; // weak
 char byte_AE336A; // weak
 char byte_AE336B; // weak
 int dword_AE336C; // weak
 int dword_AE3370; // weak
 float flt_AE3378; // weak
 float flt_AE337C; // weak
 float flt_AE3380; // weak
 float flt_AE3388; // weak
 float flt_AE338C; // weak
 float flt_AE3390; // weak
 char byte_AE3398; // weak
 _UNKNOWN unk_AE33A0; // weak
 _UNKNOWN unk_AE33A4; // weak
 _UNKNOWN unk_AE33C0; // weak
 _UNKNOWN unk_AE33C4; // weak
 int dword_AE3FA0; // weak
 float flt_AE3FA4; // weak
 float flt_AE3FA8; // weak
 float flt_AE3FAC; // weak
 _UNKNOWN unk_AE3FB4; // weak
 float flt_AE3FE0; // weak
 char byte_AE3FE4; // weak
 _UNKNOWN unk_AE3FE8; // weak
 _UNKNOWN unk_AE3FEC; // weak
 _UNKNOWN unk_AE4008; // weak
 _UNKNOWN unk_AE400C; // weak
 int dword_AE4BE8; // weak
 float flt_AE4BEC; // weak
 float flt_AE4BF0; // weak
 float flt_AE4BF4; // weak
 _UNKNOWN unk_AE4BFC; // weak
 float flt_AE4C28; // weak
 char byte_AE4C2C; // weak
 _UNKNOWN unk_AE4F60; // weak
 int dword_AE4F64; // weak
 float flt_AE4F68; // weak
 float flt_AE4F6C; // weak
 _UNKNOWN unk_AE4F70; // weak
 _UNKNOWN unk_AE4F7C; // weak
 int dword_AE4F88; // weak
 _UNKNOWN unk_AE4F90; // weak
 _UNKNOWN unk_AE4FBC; // weak
 char byte_AE5B90; // weak
 char byte_AE5B91; // weak
 char byte_AE5B94; // weak
 char *dword_AE5B98; // idb

struct class58 *pClass58_global = 0; // struct @ MM7.exe::00AE5BA8
IDirectDrawClipper *pDDrawClipper = 0; // dword @ MM7.exe::00FD1BE0
//struct Render *pD3DRenderer = 0;  // struct @ MM7.exe::00DF1BE8
 int dword_EF524C; // weak
 unsigned int uTextureID_WaterTiles[8]; // dword[8] @ MM7.exe::00EF5254
 int dword_EF5290; // weak
 int dword_EF5294; // weak
 int dword_EF52A0; // weak
 int dword_EF52A4; // weak
 int (*dword_EF52A8)(void); // weak
 int dword_EF52B0; // weak
struct RenderBillboardD3D3  pBillboardRenderListD3D3[1000]; // struct[1000] @ MM7.exe::00EF52B8
 _UNKNOWN unk_F00000; // weak
 _UNKNOWN unk_F1B430; // weak
 BYTE dword_F1B4B0; // idb
 BYTE Data; // idb

 int dword_F1B4C8; // weak
 int dword_F1B4D0; // weak
 int sLastTrackLengthMS; // dword @ MM7.exe::00F1B4D4

struct unnamed_F1B4D8 struct_F1B4D8[3000];
//_UNKNOWN unk_F1B4D8; // weak
//_UNKNOWN unk_F1B4DC; // weak
//int dword_F1B554[4800]; // idb
//int unk_F20054[91169]; // weak

//struct AudioPlayer *pAudioPlayer = 0; // struct @ MM7.exe::00F790D8
//_UNKNOWN unk_F790D8; // weak
//int dword_F790DC; // AudioPlayer::dword_00004
 _UNKNOWN unk_F79154; // weak
//int dword_F792F0; // AudioPlayer::dword_000218
//int dword_F79374; // AudioPlayer::dword_00029C
//int dword_F7937C; // AudioPlayer::hAILRedbook (0002A4)
//int dword_F79380; // AudioPlayer::hDigDriver
//int dword_F79390; // AudioPlayer::pSoundHeaders
//HANDLE hFile;  //MM7.exe::dword_F79394    AudioPlayer::hSoundsSource
//int dword_F79398; // AudioPlayer::uNumSounds
// char byte_F79448[120]; // idb
//int dword_F794C0; // AudioPlayer::dword_0003E8
//char byte_F794C8[array_size_unknown]; // weak
//_UNKNOWN unk_F79CC8; // weak
//int dword_F79D48; // weak
//char cGameCDDriveLetter; //byte @ MM7.exe::F79D58; // weak

SoundList *pSoundList = 0; // struct @ MM7.exe::00F79D5C
//int dword_F79D5C; // weak
//int dword_F79D60; // weak

 int dword_F79D70; // weak
 _UNKNOWN unk_F79E08; // weak
 _UNKNOWN unk_F79E34; // weak
 _UNKNOWN unk_F7AA08; // weak
 _UNKNOWN unk_F7AA10; // weak
 _UNKNOWN unk_F7AA34; // weak
 char byte_F7B608; // weak
 _UNKNOWN unk_F7B60C; // weak
 float flt_F7B610; // weak
 float flt_F7B614; // weak
 float flt_F7B618; // weak
 float flt_F7B61C; // weak
 char byte_F7B620; // weak
 _UNKNOWN unk_F7B628; // weak
 _UNKNOWN unk_F7B654; // weak
 _UNKNOWN unk_F7C228; // weak
 _UNKNOWN unk_F7C230; // weak
 _UNKNOWN unk_F7C254; // weak
 char byte_F7CE28; // weak
 int dword_F81018; // weak
 _UNKNOWN unk_F8101C; // weak
 __int16 word_F8101E; // weak
 _UNKNOWN unk_F81020; // weak
 __int16 word_F81022; // weak
 int dword_F81028; // weak
 _UNKNOWN unk_F81054; // weak
 int dword_F83B80[array_size_unknown]; // weak
 int dword_F83BA8[array_size_unknown]; // weak
 int dword_F8A590; // weak
 int dword_F8A594; // weak
 __int16 word_F8A5A8[array_size_unknown]; // weak
 __int16 word_F8A968[array_size_unknown]; // weak
 int dword_F8AD28; // weak
 int dword_F8AD2C; // weak
 int dword_F8AD30; // weak
 int dword_F8AD34; // weak
 int dword_F8AD38; // weak
 int dword_F8AD3C; // weak
 int dword_F8AD40; // weak
 int dword_F8AD44; // weak
 int dword_F8AD48; // weak
 int dword_F8AD4C; // weak
 int dword_F8AD50; // weak
 int dword_F8AD54; // weak
 int dword_F8AD5C; // weak
 int dword_F8AD60; // weak
 int dword_F8AD64; // weak
 int dword_F8AD68; // weak
 int dword_F8AD6C; // weak
 int dword_F8AD70; // weak
 int dword_F8AD7C; // weak
 int dword_F8AD80; // idb
 int dword_F8AD84; // weak
 int dword_F8AD88; // weak
 int dword_F8AD8C; // weak
 int dword_F8AD90; // weak
 int dword_F8AD94; // weak
 int dword_F8AD98; // weak
 int dword_F8AD9C; // weak
 int dword_F8ADA0; // weak
 int dword_F8ADA4; // weak
 int dword_F8ADA8; // weak
 int dword_F8ADAC; // weak
 int dword_F8ADB0; // idb
 int dword_F8ADB4; // weak
 int dword_F8ADB8; // weak
 int dword_F8ADBC; // weak
 int dword_F8ADC0; // weak
 int dword_F8ADC4; // weak
 int dword_F8ADC8; // weak
 int dword_F8ADCC; // weak
 int dword_F8ADD0; // weak
 int dword_F8ADD4; // weak
 int dword_F8ADD8[array_size_unknown]; // weak
 int dword_F8AE28[array_size_unknown]; // weak
 int dword_F8AE78[array_size_unknown]; // weak
 int dword_F8AEC8[array_size_unknown]; // weak
 int dword_F8AF18[array_size_unknown]; // weak
 int dword_F8AF68; // weak
 int dword_F8AFB8[array_size_unknown]; // weak
 float flt_F8B008[array_size_unknown]; // weak
 float flt_F8B058[array_size_unknown]; // weak
 float flt_F8B0A8[array_size_unknown]; // weak
 char byte_F8B0F8[array_size_unknown]; // weak
 int dword_F8B10C; // weak
 int dword_F8B110; // weak
 int dword_F8B114; // weak
 int dword_F8B118; // weak
 int dword_F8B11C; // weak
 int dword_F8B120; // weak
 _DWORD dword_F8B144; // idb
 _UNKNOWN unk_F8B148; // weak
 __int16 word_F8B158[array_size_unknown]; // weak
 int dword_F8B164[array_size_unknown]; // weak
 int dword_F8B168[array_size_unknown]; // weak
 int dword_F8B17C; // weak
 int dword_F8B180[array_size_unknown]; // weak
 int dword_F8B194; // weak
 int dword_F8B198; // weak
 int dword_F8B19C; // weak
 __int16 word_F8B1A0; // weak
 int dword_F8B1A4; // weak
 int dword_F8B1A8; // weak
 int dword_F8B1AC; // idb
 int dword_F8B1B0; // weak
unsigned int uArenaReward = 0; // dword @ MM7.exe::00F8B1B4
unsigned char *dword_F8B1B8[4]; // weak
 _UNKNOWN unk_F8B1C8; // weak
 int dword_F8B1D8; // weak
 int dword_F8B1DC; // weak
 int dword_F8B1E0; // weak
 int dword_F8B1E4; // weak
 unsigned char *dword_F8B1E8; // idb
 char byte_F8B1EC; // weak
 char byte_F8B1EF[array_size_unknown]; // weak
 _UNKNOWN unk_F8B1F0; // weak
 int dword_F8B1F4; // weak
 _UNKNOWN unk_F8B1F8; // weak
 _UNKNOWN unk_F8B5E0; // weak
 int dword_F8B5E8; // weak
 int dword_F8B5EC[array_size_unknown]; // weak
 _UNKNOWN unk_F8B668; // weak
 _UNKNOWN unk_F8BA50; // weak

struct StringSplitter splitter_global; // struct @ MM7.exe::00F8BA58
//int dword_F8BA58; // weak
//int dword_F8BA5C[30]; // weak

int dword_F8BAD4;
 _UNKNOWN unk_F8BAD8; // weak

//struct class32 *pVideoPlayer; // struct @ MM7.exe::00F8BB08
/*
_UNKNOWN unk_F8BB08; // weak
int dword_F8BB2C; // pVideoPlayer::dword_000024
int dword_F8BB30; // weak
int dword_F8BB48; // weak
int dword_F8BB4C; // weak
int dword_F8BB5C; // weak
int dword_F8BB60; // weak
int dword_F8BB6C; // weak
int dword_F8BB74 // weak
HWND dword_F8BB78; // idb
HANDLE dword_F8BB80; // idb
HANDLE hObject; // idb*/
//int dword_F8BB88; // pVideoPlayer::ptr_000080
//int dword_F8BB8C; // pVideoPlayer::ptr_000084
//int dword_F8BBA4; // pVideoPlayer::dword_00009C
                            //maybe overlaps following
_UNKNOWN unk_F8BBEC; // weak
int dword_F8BC10; // weak

struct OldViewport *pOldViewport = 0;  // struct @ MM7.exe::00F8BC14

 __int16 word_F8BC48[104]; // weak
 __int16 word_F8BD18[104]; // weak
struct class25 class25_F8BDE8;                      // struct @ MM7.exe::00F8BDE8
unsigned char  bIs_class25_F8BDE8_sub4C055C_Called; // byte   @ MM7.exe::00F8DDF0
struct Vis_stru0 array_F8DDF8[64]; // struc[64] @ MM7.exe::00F8DDF8
 char byte_F8E9F8; // weak
struct RenderVertexD3D3 array_F8EA00[64]; // struct[64] @ MM7.exe::00F8EA00
struct Vis_stru0        array_F8F200[64]; // struct[64] @ MM7.exe::00F8F200
struct class25 class25_F8FE00;     // struct     @ MM7.exe::00F8FE00
 char byte_F91E08; // weak
struct class25 class25_F91E10;  // struct @ MM7.exe::00F91E10
 char byte_F93E18; // weak
 int dword_F93E1C; // weak
 int dword_F93E30; // weak
 int dword_F93E44; // weak
 int dword_F93E58; // weak

 struct unnamed_F93E6C stru_F93E6C; // struct @ MM7.exe::00F93E6C
 int dword_F94004; // weak
 int dword_F9400C; // weak
 char byte_F94298; // weak
 float flt_F942A0; // weak
 float flt_F942A4; // weak
 float flt_F942A8; // weak
 float flt_F942B0; // weak
 int dword_F944EC; // weak
 int dword_F944F0; // weak
 void *dword_F944F4; // idb
 int dword_F944F8; // weak
 LPVOID lpMem; // idb
 int dword_F94500; // weak
 HANDLE hHeap; // idb
 int dword_F94508; // weak