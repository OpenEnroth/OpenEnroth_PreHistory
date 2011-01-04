
#include "defs.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"



#include "clock.h"
#include "UserInput.h"




//----- (MM7.exe::00426317) -----.text:00426AEF---------------------------------------------------
unsigned int Clock::Time()
{
 unsigned int uTime = (timeGetTime() * 128) / 1000;
 if (uStartTime > uTime)
   uStartTime = 0;

 return uTime;
}

//----- (MM7.exe::00426349) ----.text:00426B21----------------------------------------------------
Result::Code Clock::Pause()
{
 if (!bPaused)
 {
  uStopTime = Time();
  bPaused = true;

  return Result::Success;
 }
 return Result::Generic;
}
//----- (00426363) -----------------text:00426B3B---------------------------------------
Result::Code Clock::Resume()
{
 if (bPaused)
 {
  pUserInput->ResetKeyboard();
  uStartTime = Time();
  bPaused = false;

  return Result::Success;
 }
 return Result::Generic;
}

//----- (00426386) ----------------------.text:00426B5E----------------------------------
void Clock::clock_sub_426386()
{
  if ( !dword_000008)
  {
    dword_000014 = Time();
    dword_000008 = 1;
  }
}

//----- (004263A0) ---------------text:00426B78-----------------------------------------
void Clock::clock_sub_4263A0()
{

  if ( dword_000008 )
  {
    dword_000008 = 0;
    uStartTime = Time();
  }
}

//----- (004263B7) -----------.text:00426B8F---------------------------------------------
Result::Code Clock::Update()
{
  signed int v2; // eax@2

  do
  {
    v2 = Time() - uStartTime;
    uElapsedTime = v2;
  }
  while ( v2 <= 0 );

 uStartTime = Time();

 if (uElapsedTime > 32)
   uElapsedTime = 32;
 if (!bPaused && !dword_000008)
   uTotalGameTimeElapsed += uElapsedTime;
 dword_000020 = (uElapsedTime << 16) / 128; 

 return Result::Success;
}



//----- (MM7.exe::00426402) ------.text:00426BDA --------------------------------------------------
Result::Code Clock::Initialize()
{
 if (!bReady)
 {
  bReady = true;
  uTotalGameTimeElapsed = 0;

  return Result::Success;
 }
 return Result::Generic;
}



Clock::Clock()
{
 bReady = false;
 uTotalGameTimeElapsed = 0;
}
