#ifndef GUIWINDOW_H
#define GUIWINDOW_H
#include "Control.h"
#include "..\Extras\List.h"

struct GUIButton;
namespace GUI
{
 class Control;
 class Image;
 class Window: public Control
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
   struct ::GUIButton* ptr_00001C; // looks like pointer to GUIButton, but not always;  maybe UserData
   int dword_00001C; // looks like pointer to GUIButton, but not always;  maybe UserData
                     // when uWindowType == 9 (book),
                     // dword_00001C:   177  Lloyd Beacons book
                     //                 195  Town Portals book
                     //                 200  Quests book
                     //                 201  Autonotes book
                     //                 202  Map book
                     //                 203  Calendar book
                     //                 224  Timeline bool
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
  struct ::GUIButton *pControlsHead; // ptr @ 00004C
  struct ::GUIButton *pControlsTail; // ptr @ 000050


           Window();
  virtual ~Window() {}

  Image           *pBackgroundImage;
  List<Control *>  cChildren;

  virtual Result::Code Initialize(Rect<float> *pArea);
  virtual Result::Code SetBackgroundImage(Image *pImage);

  virtual Result::Code AddChild(Control *pNewChild)
  {
   cChildren.Add(pNewChild);
   return Result::Success;
  }

  virtual Result::Code SetControlArea(Rect<float> *pNewArea);




 
   // Event handlers override
  virtual Result::Code OnDraw(float dt);
 };
//sizeof = 54
















 // window with borders
 class WindowOverlapped: public Window
 {
  public:
             WindowOverlapped();
    virtual ~WindowOverlapped() {}


    virtual Result::Code SetStyle(Image *pBorderLeft, Image *pBorderRight, Image *pBorderTop, Image *pBorderBottom,
                                  Image *pCornerUpLeft, Image *pCornerUpRight, Image *pCornerBotLeft, Image *pCornerBotRight);


    virtual Result::Code SetControlArea(Rect<float> *pNewArea);



   // Event handlers override
  virtual Result::Code OnDraw(float dt);

  protected:
    Image *pBorders[4];
    Image *pCorners[4];
 };
};





void GUIWindow_DrawText(GUI::Window *_this, struct Font *pFont, unsigned int uHorizontalMargin, unsigned int uVerticalMargin, unsigned int uDefaultColor, const char *pString, int sLineSpacing);
int __thiscall GUIWindow_sub_411BFC_InitializeBookViewWindow(GUI::Window *_this);
void GUIButton_sub_415180(struct GUIButton *a1, const unsigned char *a2, struct Font *a3, __int16 a4, char *a5);
void __cdecl GUIWindow_DrawCopyrightWindow();
void GUIWindow_sub_415551(GUI::Window *_this, int a2);
int __thiscall GUIWindow_sub_41D08F(class GUI::Window *_this, int a2, int a3, int a4, int a5);
void GUIWindow_sub_41D3B7(class GUI::Window *_this);
void GUIWindow_sub_41D73D(int _this);
void __thiscall GUIWindow_sub_4B3157(const GUI::Window *_this);



extern class GUI::Window *pGUIWindow_CurrentMenu;



#endif