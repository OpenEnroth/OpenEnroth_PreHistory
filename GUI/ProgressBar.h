#pragma once
#include "Control.h"

namespace GUI
{
 class Image;
 class ProgressBar: public Control
 {
  public:
  unsigned short     uX;               // word   @ 000000
  unsigned short     uY;               // word   @ 000002
  unsigned short     uWidth;           // word   @ 000004
  unsigned short     uHeight;          // word   @ 000006
  char               byte_000008;
  char               byte_000009;
  unsigned char      uProgressMax;      // byte  @ 00000A
  unsigned char      uProgressCurrent;  // byte  @ 00000B
  int                depricated_00000C; // dword @ 00000C        int uProgressBarType;   loading screen, small loading window or whatever to render
  char               array_000010[8];
  class cPCXTexture *depricated_000018; // struct @ 000018       class cPCXTexture *pBackgroundImage;
  char               byte_000040[304];			   //158
  class cTexture    *loadprog;         // struct @ 000170

  unsigned int _addon_loadprog_id_in_Icons_LOD;
 #ifndef OLD_CODE
  unsigned int uTextureID_Loading;
 #endif


  protected:
    Rect<float>  cBackgroundRect;
    Image       *pBackgroundImage;

    Rect<float>  cProgressRect;
    Image       *pProgressImage;
 
    _Render::Color  cColorMask;  // key used to colorize the progress
 
  public:
             ProgressBar();
    virtual ~ProgressBar() {}

    virtual Result::Code Reset() = 0;
 };
//sizeof ~ 198
//bool sub_443484(struct GUIProgressBar *_this, unsigned int uProgressBarType)  00443484  GUIProgressBar::Initialize




 // Long progress bar for level loading
 class ProgressBar_LevelLoading: public ProgressBar
 {
  public:
             ProgressBar_LevelLoading();
    virtual ~ProgressBar_LevelLoading() {}

    virtual Result::Code Initialize(const Rect<float> *pBackgroundRect, const Rect<float> *pProgressRect, _Render::Color *pColor);
    virtual Result::Code Reset();

    virtual Result::Code SetProgress(float fPercentage)
    {
     fProgress = fPercentage;
     return Result::Success;
    }


   
    // Event handlers override
    virtual Result::Code OnDraw(float dt);

  protected:
    float fProgress;
 };



// Small progress bar for short loadings
 class ProgressBar_Small: public ProgressBar
 {
  public:
 };
};