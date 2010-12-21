#pragma once
#pragma pack(push, 1)




//LoadingUI
struct class56
{
 unsigned short     uX;               // word @ 000000
 unsigned short     uY;               // word @ 000002
 unsigned short     uWidth;           // word @ 000004
 unsigned short     uHeight;          // word @ 000006
 char               byte_000008;
 char               byte_000009;
 unsigned char      uProgressMax;     // byte @ 00000A
 unsigned char      uProgressCurrent; // byte @ 00000B
 int                uProgressBarType; // dword @ 00000C   loading screen, small loading window or whatever to render
 char               array_000010[8];
 class cPCXTexture *loading;          // struct @ 000018
 char               byte_000040[304];			   //158
 class cTexture    *loadprog;         // struct @ 000170

 unsigned int _addon_loadprog_id_in_Icons_LOD;
#ifndef OLD_CODE
 unsigned int uTextureID_Loading;
#endif

};
//sizeof ~ 198

bool LevelLoadingUI_Initialize(struct class56 *_this, unsigned int uProgressBarType);
void LevelLoadingUI_UpdateAndDrawProgressBar(struct class56 *_this);
void DrawLoadingScreen(struct class56 *_this);
void LevelLoadingUI_Reset(struct class56 *_this, char a2);
void LevelLoadingUI_Release(struct class56 *_this);


#pragma pack(pop)