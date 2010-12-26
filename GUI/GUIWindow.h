#ifndef GUIWINDOW_H
#define GUIWINDOW_H

#include "GUIImage.h"

#include "..\Extras\List.h"


class GUIWindow: public GUIControl
{
 public:
 unsigned int uFrameX;      // dword @ 000000
 unsigned int uFrameY;      // dword @ 000004
 unsigned int uFrameWidth;  // dword @ 000008
 unsigned int uFrameHeight; // dword @ 00000C
 unsigned int uFrameZ;      // dword @ 000010
 unsigned int uFrameW;      // dword @ 000014
 unsigned int uWindowType;    // dword @ 000018
 union 
	 {
 struct GUIButton* ptr_00001C; // looks like pointer to GUIButton, but not always;  maybe UserData
   int dword_00001C; // looks like pointer to GUIButton, but not always;  maybe UserData
	 };
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
 unsigned char    *ptr_000048; // some string ptr
 struct GUIButton *pControlsHead; // ptr @ 00004C
 struct GUIButton *pControlsTail; // ptr @ 000050


 Rect<float>         cClientArea;
 GUIImage           *pBackgroundImage;
 List<GUIControl *>  cChildren;

 Result::Code Initialize(Rect<float> *pArea, GUIImage *pBackground);
};
//sizeof = 54




void GUIWindow_DrawText(GUIWindow *_this, struct Font *pFont, unsigned int uHorizontalMargin, unsigned int uVerticalMargin, unsigned int uDefaultColor, const char *pString, int sLineSpacing);
int __thiscall GUIWindow_sub_411BFC(GUIWindow *_this);
void GUIButton_sub_415180(struct GUIButton *a1, const unsigned char *a2, struct Font *a3, __int16 a4, char *a5);
void __cdecl GUIWindow_DrawCopyrightWindow();
void GUIWindow_sub_415551(GUIWindow *_this, int a2);



#endif