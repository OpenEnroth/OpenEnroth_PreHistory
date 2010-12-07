

#pragma once




//clock.bin
//class24
//struct class24
class Clock
{
public:
///some flags
 int dword_000000;
 int dword_000004;
 int dword_000008;

 signed int int_00000C;
 int dword_000010;
 int dword_000014;
 int dword_000018;
 int int_00001C;
 int dword_000020;
 int dword_000024;

 Clock();

void clock_fn1(); //void __thiscall sub_426349(int _this);

__int64 clock_fn2(); //__int64 __thiscall sub_426317(void *_this);


void clock_sub_426363();//class24_sub_426363(struct class24 *_this);
void clock_sub_426386();//class24_sub_426386(int _this);
void clock_sub_4263A0();// class24_sub_4263A0(class24 *_this);	

void clock_sub_4263B7(); //int class24_sub_4263B7(struct class24 *_this);	  //int __thiscall class24_sub_4263B7(int _this)

void Clock_In();  //void __thiscall sub_426402(int _this);

};
//sizeof ~ 28


