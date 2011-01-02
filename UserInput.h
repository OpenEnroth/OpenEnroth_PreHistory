#ifndef USERINPUT_H
#define USERINPUT_H

#include "CoreDefinitions.h"



namespace Keyboard
{
 namespace Key
 {
  enum Type
  {
   Forward = 0,        // default: arrow up
   Backwards = 1,      // default: arrow down
   TurnLeft = 2,       // default: arrow left
   TurnRight = 3,      // default: arrow right
   Yell = 4,           // default: y
   Jump = 5,           // default: x
   Combat = 6,         // default: enter
   CastReady = 7,      // default: s
   Attack = 8,         // default: a
   Interact = 9,       // default: space
   Cast = 10,          // default: c
   Pass = 11,          // default: b
   CharCycle = 12,     // default: tab
   OpenQuestbook = 13, // default: q
   OpenQuickRef = 14,  // default: z
   Rest = 15,          // default: r
   OpenCalendar = 16,  // default: t
   OpenAutonotes = 17, // default: n
   OpenMap = 18,       // default: m
   AlwaysRun = 19,     // default: u
   LookUp = 20,        // default: page down
   LookDown = 21,      // default: delete
   CenterView = 22,    // default: end
   ZoomIn = 23,        // default: +
   ZoomOut = 24,       // default: -
   FlyUp = 25,         // default: page up
   FlyDown = 26,       // default: insert
   Land = 27,          // default: home
   StrafeLeft = 28,    // default: [
   StrafeRight = 29    // default: ]
  };
 };




 namespace Toggle
 {
  enum Type
  {
   Holding = 0,      // Key is continuosly toggled while being held
   OneTimePress = 1  // Key is toggled only once, when pressed
  };
 };
};







class OSKeyboard;
class UserInput // keyboard controller
{
 public:
   UserInput();
   ~UserInput() {}

   Result::Code Initialize();
   Result::Code SetDefaultKeyMapping();  // reset key scheme to default


   bool         IsKeyToggled(Keyboard::Key::Type);      // checks if key was toggled.
                                                        // TODO change to event subscription
   bool         IsShiftToggled();                       // bawww.. OLD CODE
   Result::Code ResetKeyboard();                        // resets all key toggle status
   Result::Code GetVirtualCodeMappings(unsigned int *); // bawww... that OLD CODE


   Result::Code Deinitialize();




   int  sub_459C82_LooksLikeBindKey(unsigned int);
   void sub_459ED1(int a2);
   bool sub_459F10(unsigned int a2);
   void sub_459E5A(int a2, int a3, int a4);

 protected:
   Result::Code SetKeyMappingFromRegistry();

   unsigned int KeyNameToVKeyCode(const char *pName);


 public:
   unsigned int            uLastKeyPressed; // dword @ 000000
   unsigned int            dword_000004;
   unsigned int            dword_000008;
 protected:
   unsigned int            pVirtualKeyCodesMapping[30]; // dword[30] @ 00000C
   Keyboard::Toggle::Type  pActionToggleConditions[30]; // dword[30] @ 000084
 public:
   int                     dword_0000FC;
   unsigned char           pPressedKeysBuffer[257]; // byte[257] @ 000100
   unsigned char           uNumKeysPressed;         // byte @ 000201
   char                    byte_0000202;
   char                    byte_0000203;
   int                     dword_000204;
   int                    *ptr_000208;

   OSKeyboard             *pKeyboard; // new
};
// sizeof ~ ?

//void KeyboardController_ctor(struct UserInput *_this)                               @ 00459C8D  UserInput::UserInput
//void KeyboardController_InitalizeKeys(struct UserInput *_this)                      @ 00459CC4  UserInput::SetDefaultKeyMapping
//char KeyboardController_ReadKeyMapping(struct UserInput *_this)                     @ 00459FFC  UserInput::SetKeyMappingFromRegistry
//char __stdcall sub_45ABCA(const char *Str1)                                         @ 0045ABCA  UserInput::KeyNameToVKeyCode
//int KeyboardController_LooksLikeBindKey(struct UserInput *_this, unsigned int uKey) @ 00459C82  UserInput::sub_459C82_LooksLikeBindKey
//void KeyboardController_sub_459ED1(UserInput *_this, int a2)                        @ 00459ED1  UserInput::sub_459ED1
//void KeyboardController_sub_459E5A(UserInput *_this, int a2, int a3, int a4);       @ 00459E5A  UserInput::sub_459E5A
//bool sub_459F10(UserInput *_this, unsigned int a2);                                 @ 00459F10  UserInput::sub_459F10
//int __cdecl sub_459E3F();                                                           @ 00459E3F  UserInput::ResetKeyboard





class OSKeyboard
{
 friend class UserInput;
 public:
            OSKeyboard() {}
   virtual ~OSKeyboard() {}
   
   virtual bool IsKeyBeingHeld(unsigned int uVirtualKeyCode) = 0;
   virtual bool IsKeyPressed(unsigned int uVirtualKeyCode) = 0;

   virtual Result::Code Reset(unsigned int uVirtualKey) = 0;
   virtual Result::Code Reset(unsigned int *pVirtualKeys, unsigned int uNumKeys) = 0;
   
   virtual bool IsShiftToggled() = 0;

 protected:
   void        (*detor_ptr)(OSKeyboard *); // dword @ 000000
   unsigned int  bUsingAsyncClass;         // dword @ 000004
};


//class14
class Win32Keyboard: public OSKeyboard
{
 public:
            Win32Keyboard();
   virtual ~Win32Keyboard() {}

   virtual bool IsKeyBeingHeld(unsigned int uVirtualKeyCode);
   virtual bool IsKeyPressed(unsigned int uVirtualKeyCode);

   virtual Result::Code Reset(unsigned int uVirtualKey);
   virtual Result::Code Reset(unsigned int *pVirtualKeys, unsigned int uNumKeys);

   virtual bool IsShiftToggled();
};
//struct Win32Keyboard *Win32Keyboard_ctor(struct Win32Keyboard *_this) @ 0045AFD9  Win32Keyboard::Win32Keyboard
//bool Win32Keyboard_IsKeyBeingHeld(struct Win32Keyboard *_this, int vKey)   @ 0045B0A9  Win32Keyboard::IsKeyBeingHeld
//bool Win32Keyboard_IsKeyWasPressed(struct Win32Keyboard *_this, int vKey)  @ 0045B0CE  Win32Keyboard::IsKeyPressed
//void Win32Keyboard_BeginReadingInput(int _this)                            @ 0045B019  Win32Keyboard::sub_45B019
//char Win32Keyboard_sub_45B06E(int _this)                                   @ 0045B06E  Win32Keyboard::IsShiftToggled














void __cdecl sub_465F5A_InitializeAsyncMouseAndSomething();
void __cdecl sub_465FF0_InitializeAsyncKeyboardAndSomething();

void __cdecl AsyncInput_sub_45B1FD_EnterCS();
void __cdecl AsyncInput_sub_45B1FD_LeaveCS();


int CAsyncKeyboard_ctor(int _this);
char CAsyncKeyboard_Initialize(LPVOID lpParameter);
void CAsyncKeyboard_Resume(int _this);
void CAsyncKeyboard_suspend(int _this);
void CAsyncKeyboard_update_keyboard_data(int _this);
char CAsyncKeyboard_sub_45B4EC(void *_this, unsigned __int8 a2);
char CAsyncKeyboard_sub_45B57D(void *_this, int a2);
void CAsyncKeyboard_Clear();


char CAsyncMouse_Initialize(LPVOID lpParameter);
int CMouseAsync_ctor_or_initialization(int _this, int a2);
void CAsyncMouse_suspend(int _this);
int CAsyncMouse_update_mouse_data(int _this, int a2);
void CAsyncMouse_sub_46B105(void *_this);
int CAsyncMouse_sub_46B342(int _this, float a2, float a3);
char CAsyncMouse_sub_46AE97(void *_this, void *Source);
char CAsyncMouse_sub_46B1DD(int _this);
void CAsyncMouse_sub_46B736(void *_this, char a2);
int CAsyncMouse_sub_46B944(int _this);
void CAsyncMouse_sub_409E3D(int _this, char a2);
void CAsyncMouse_sub_46BAEC(void *_this);
void CAsyncMouse_sub_46BB0A(int _this);
void *CAsyncMouse_ClipCursorToScreen();
void CAsyncMouse_Clear();

#endif