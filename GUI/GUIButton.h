#pragma once



struct GUIButton
{
 unsigned int uX;      // dword @ 000000
 unsigned int uY;      // dword @ 000004
 unsigned int uWidth;  // dword @ 000008
 unsigned int uHeight; // dword @ 00000C
 unsigned int uZ;      // dword @ 000010
 unsigned int uW;      // dword @ 000014
 int dword_000018;
 int dword_00001C;
 unsigned int uControlID;    // dword @ 000020
 unsigned int uControlParam; // dword @ 000024
 int dword_000028;
 int dword_00002C;
 struct GUIButton *pPrev;         // ptr   @ 000030
 struct GUIButton *pNext;         // ptr   @ 000034
 class GUIWindow *pParentWindow; // ptr   @ 000038
 class cTexture   *pTexture[5];    // dword @ 00003C
// class cTexture   *pTexture2; //int dword_000040;
 //class cTexture   *pTexture3; // int dword_000044;
 //class cTexture   *pTexture4; //int dword_000048;
 //class cTexture   *pTexture5; //int dword_00004C;
 unsigned int uTexturesCount;// dword_000050;
// int dword_000054;
 unsigned char uHotkey; // byte @ 000054   hotkey shortcut
 unsigned char pButtonName[103]; // byte[?] @ 000055
/* int dword_000058;
 int dword_00005C;
 int dword_000060;
 int dword_000064;
 int dword_000068;
 int dword_00006C;
 int dword_000070;
 int dword_000074;
 int dword_000078;
 int dword_00007C;
 int dword_000080;
 int dword_000084;
 int dword_000088;
 int dword_00008C;
 int dword_000090;
 int dword_000094;
 int dword_000098;
 int dword_00009C;
 int dword_0000A0;
 int dword_0000A4;
 int dword_0000A8;
 int dword_0000AC;
 int dword_0000B0;
 int dword_0000B4;
 int dword_0000B8; */
};
//sizeof == BC
