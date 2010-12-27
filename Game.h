#ifndef MMGAME_H
#define MMGAME_H


#include "defs.h"

#include "classes.h"

#include "GUI\GUI.h"


#pragma pack(push, 1)

struct Game;


Game *Game_Initialize();
void  Game_Destroy();

void InitializeGameText();
void InitializeScrolls();
void InitializeMerchants();
void InitializeTransitions();
void InitializeAwards();
void InitializeAutonotes();
void InitializeQuests();

void Game_Deinitialize();
void Game_DeinitializeAndTerminate(void *Code);


struct Game_stru0
{
 unsigned int    dword_000000;
 unsigned char  *ptr_000004;
 int             dword_000008;
 int             dword_00000C;
};

//class00
struct Game
{
 void (*dtor_ptr)(Game *);  // dword @ 000000
 int    dword_000004;
 int    dword_000008[699];
 int    dword_000704;     //num stationary lights?

 float array_000718[array_size_unknown];

                              // looks like ptr to current selected input device
 struct GUICursor *pGUICursor;    // dword @ 000974
 unsigned int    dword_000978;
                              // looks like start of a struct or a class, sub_40E2F6 is a member of which
 struct Game_stru0 unnamed_00097C;

 int      dword_000E08;
 int      dword_000E0C;
 int      dword_000E10;
 int      dword_000E14;
 int      dword_000E18;
 int      dword_000E1C;
 int      uSomeFlags;              // dword @ 000E20   & 0x01 == lighing on?
 int      dword_000E24;            // 0x08: alter gravity strength
                                   // 0x20: bloodsplats
 float    flt_000E28;
 __int64  qword_000E2C;
 int      dword_000E34;
 int      dword_000E38;
 struct class01          *class01_obj;      // dword @ 000E3C
 struct class02          *class02_obj;      // dword @ 000E40
 GUICursor               *class03_obj;      // dword @ 000E44
 struct class04          *class04_obj;      // dword @ 000E48
 struct Vis              *pVis;             // dword @ 000E4C
 struct class06          *class06_obj;      // dword @ 000E50
 struct class08          *class08_obj;      // dword @ 000E54
 struct class09          *class09_obj;      // dword @ 000E58
 struct class10          *class10_obj;      // dword @ 000E5C
 struct class11          *class11_obj;      // dword @ 000E60
 struct class12          *class12_obj;      // dword @ 000E64
 struct class13          *class13_obj;      // dword @ 000E68
 //class Win32Keyboard *pWin32Keyboard; // dword @ 000E6Ñ
 int                      dummy_000E6C; //member moved to class UserInput
 struct CGammaController *pGammaController; // dword @ 000E70
 int                      dword_000E74;

 Result::Code PrepareForLoop(const char *pLevelName);
 Result::Code Loop(const char *pLevelName);
};
//sizeof = 0E78
//int __cdecl sub_463149()              00463149   Game::Loop

//int __thiscall sub_44E4B7(int _this);
void Game_ctor(Game *_this);
//int __thiscall sub_44F0FD(int _this);
int Game_fn0(Game *_this);
//int __thiscall sub_44F0D8(int _this, int a2);
int Game_fn1(Game *_this, int flags);
//char __thiscall Game_InitializeGammaController(int _this);
bool Game_InitializeGammaController(Game *_this);
//char __thiscall sub_44EEA7(int _this);
char Game_sub_44EEA7(Game *_this);
//char __thiscall sub_44EA5E(int _this, float a2, signed int a3, signed int a4, char a5, int a6, int a7);
bool Game_Pick(Game *_this, float a2, unsigned int uMouseX, unsigned int uMouseY, bool bOutline, int a6, int a7);
//char __thiscall sub_44F07B(int _this);
bool Game_sub_44F07B(Game *_this);
//void __thiscall sub_44F120(int _this, int a2);
void Game_sub_44F120_MaybeStackStationaryLights(Game *_this, int a2);
//void __fastcall sub_44F192(int a1);
void Game_sub_44F192(Game *_this);
//void __thiscall sub_44E904(void *_this);
void sub_44E904(Game *_this);
//signed int __thiscall sub_44ED0A(int _this, int a2, int a3, signed int a4);
signed int Game_sub_44ED0A(Game *_this, struct struct8 *a2, int *a3, signed int a4);
//signed int __thiscall sub_44EC23(int _this, int a2, int a3, signed int a4);
signed int Game_sub_44EC23(Game *_this, struct struct8 *a2, int *a3, signed int a4);
//void __thiscall sub_40E2F6(int _this, char a2);
void Game_stru0_sub_40E2F6(Game_stru0 *_this, char a2);
//char __thiscall sub_44EE30(int _this, int a2, void **a3);
bool Game_sub_44EE30(Game *_this, struct class51_stru2 *a2, void **a3);
//char __thiscall sub_44EB12(int _this, char a2, int a3, int a4);
bool Game_sub_44EB12(Game *_this, bool bOutline, int a3, int a4);

void Game_dtor(Game *_this);








unsigned int Game_OnStartNPCDialogue(unsigned int uSpekerActorID, int);
unsigned int Game_OnOpenQuestbook(int, unsigned int);
unsigned int Game_OnOpenAutonotes(int, unsigned int);
unsigned int Game_OnOpenMap(int, unsigned int);
unsigned int Game_OnOpenCalendar(int, unsigned int);
unsigned int Game_OnOpenSpellbook(int, int);
unsigned int Game_OnOpenQuickRef(int, int);
unsigned int Game_OnOpenRest(int, int);

unsigned int Game_OnAttack(int, int);
unsigned int Game_OnCastQuickspell(int, int);
unsigned int Game_OnInteract(int, int);








#pragma pack(pop)

#endif