#pragma pack(push, 1)

#define MENU_MAIN 0

struct GUIWindow
{
 unsigned int uFrameX;      // dword @ 000000
 unsigned int uFrameY;      // dword @ 000004
 unsigned int uFrameWidth;  // dword @ 000008
 unsigned int uFrameHeight; // dword @ 00000C
 unsigned int uFrameZ;      // dword @ 000010
 unsigned int uFrameW;      // dword @ 000014
 unsigned int bSlotUsed;    // dword @ 000018

 int dword_00001C;
 unsigned int uNumControls; // dword @ 000020
 int dword_000024;
 int dword_000028;
 int dword_00002C; //looks like focus control id
 int dword_000030;
 int dword_000034;
 int dword_000038;
 int dword_00003C;
 int dword_000040;
 int dword_000044;
 int dword_000048;
 struct GUIButton *pControlsHead; // ptr @ 00004C
 struct GUIButton *pControlsTail; // ptr @ 000050
};
//sizeof == 54


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
 int dword_000020;
 int dword_000024;
 int dword_000028;
 int dword_00002C;
 struct GUIButton *pPrev;         // ptr @ 000030
 struct GUIButton *pNext;         // ptr @ 000034
 struct GUIWindow *pParentWindow; // ptr @ 000038
 int dword_00003C;
 int dword_000040;
 int dword_000044;
 int dword_000048;
 int dword_00004C;
 int dword_000050;
// int dword_000054;
 unsigned char byte_000054;
 unsigned char pButtonName[3]; // byte[?] @ 000055
 int dword_000058;
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
 int dword_0000B8;
};
//sizeof == BC



struct Font
{
 unsigned char uFirstChar; // byte @ 000000
 unsigned char uLastChar;  // byte @ 000001
 char          byte_000002[2];
 unsigned char byte_000004;
 unsigned char uFontHeight; // byte @ 000005
 char          byte_000006[2];
 int           dword_000008;
 int           dword_00000C;
 int           dword_000010[4];
 int           dword_000020[256][3];
 int           array_000C20[256];
 char          unk_001020;
};



struct GUIWindow *__fastcall GUIWindowCreate(unsigned int uFrameX, unsigned int uFrameY,
                                             unsigned int uFrameWidth, unsigned int uFrameHeight,
                                             signed int a5, int a6, int a7);

struct GUIButton *__fastcall GUIButtonCreate(struct GUIWindow *pParentWindow,
                                             unsigned int uX, unsigned int uY,
                                             unsigned int uWidth, unsigned int uHeight,
                                             int a6, int a7, int a8, int a9, char a10, const char *pName, unsigned int uTextureID);

void GUIWindowDelete(struct GUIWindow *);

//int __thiscall sub_41CD3B(int this, int a2);
struct GUIButton *GUIWindow_GetChild(struct GUIWindow *_this, int uID);

unsigned char *__fastcall FitTextInAWindow(const char *pString, struct Font *pFont, struct GUIWindow *pParent, unsigned char uX, int a5);
char __fastcall FontDrawText(int a1, int a2, signed int a3, int a4, __int16 a5, const char *Str1, int a7, signed int a8, char *a9);

#pragma pack(pop)