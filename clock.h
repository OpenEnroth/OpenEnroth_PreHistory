#pragma once
#include "CoreDefinitions.h"



//clock.bin
//class24
//struct class24
class Clock
{
 public:
           Clock();
   inline ~Clock() {}


   bool bReady;  // dword @ 000000
   bool bPaused; // dword @ 000004
   int  dword_000008;

   unsigned int uStartTime; // dword @ 00000C  time the clock was started,  in a (128 * sec) format
   unsigned int uStopTime;  // dword @ 000010  time the clock was stopped
   int dword_000014;
   int dword_000018;
   unsigned int uElapsedTime; // dword @ 00001C   time elapsed, max quant == 32 ms
   int dword_000020;
   unsigned int uTotalGameTimeElapsed; // dword @ 000024   


   Result::Code Initialize();
   Result::Code Pause();
   Result::Code Resume();
   unsigned int Time();



void clock_sub_426386();//class24_sub_426386(int _this);
void clock_sub_4263A0();// class24_sub_4263A0(class24 *_this);	

 Result::Code Update(); //int class24_sub_4263B7(struct class24 *_this);	  //int __thiscall class24_sub_4263B7(int _this)
};
//sizeof ~ 28

//void __thiscall sub_426402(int _this)       00426402  Clock::Initialize
//void __thiscall sub_426349(int _this)       00426349  Clock::Pause
//void sub_426363()                           00426363  Clock::Resume
//__int64 __thiscall sub_426317(void *_this)  00426317  Clock::Time