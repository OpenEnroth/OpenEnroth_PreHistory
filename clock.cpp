
#include "defs.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"



#include "clock.h"
#include "UserInput.h"


//----- --------------------------------------------------------
Clock::Clock()
{
// memset(_this, 0, sizeof(class class24));
 dword_000000 = 0;
 dword_000024 = 0;
}



//----- (MM7.exe::00426317) -----.text:00426AEF---------------------------------------------------
__int64 Clock::clock_fn2()
{
 DWORD v1; // edi@1

 v1 = (timeGetTime() * 128) / 1000;
 if((int_00000C<0)||int_00000C>v1)
   int_00000C=0;

 return v1;
}

//----- (MM7.exe::00426349) ----.text:00426B21----------------------------------------------------
void Clock::clock_fn1()
{
 if (!dword_000004)
 {
   dword_000004 = 1;
   dword_000010 = clock_fn2();
 }
}
//----- (00426363) -----------------text:00426B3B---------------------------------------
void Clock::clock_sub_426363()
{
  if (dword_000004)
  {
    pUserInput->ResetKeyboard();
    int_00000C = clock_fn2();
    dword_000004 = 0;
  }
}

//----- (00426386) ----------------------.text:00426B5E----------------------------------
void Clock::clock_sub_426386()
{
 
  if ( !dword_000008)
  {
    dword_000014 = clock_fn2();
    dword_000008 = 1;
  }
}

//----- (004263A0) ---------------text:00426B78-----------------------------------------
void Clock::clock_sub_4263A0()
{

  if ( dword_000008 )
  {
    dword_000008 = 0;
    int_00000C = clock_fn2();
  }
}

//----- (004263B7) -----------.text:00426B8F---------------------------------------------
void Clock::clock_sub_4263B7()
{
 
  signed int v2; // eax@2

  do
  {
    v2 = clock_fn2() - int_00000C;
    int_00001C = v2;
  }
  while ( v2 <= 0 );

  int_00000C = clock_fn2();

  if ( int_00001C > 32 )
    int_00001C = 32;
  if ((dword_000004==0)&&(dword_000008==0))
	dword_000024+=int_00001C;
  dword_000020=(int_00001C<<16)/128; 
}



//----- (MM7.exe::00426402) ------.text:00426BDA --------------------------------------------------
void Clock::Clock_In()
{
// memset(_this, 0, sizeof(class class24));
 dword_000000 = 1;
 dword_000024 = 0;
}
