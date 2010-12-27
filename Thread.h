#pragma once
#include "CoreDefinitions.h"
#include <windows.h>

class OSThread
{
 public:
   typedef Result::Code (*ThreadFunction)();

            OSThread() {}
   virtual ~OSThread() {}

   virtual Result::Code Initialize() = 0;
   virtual Result::Code Execute(ThreadFunction, unsigned int bWait) = 0;
   virtual bool         IsBusy() = 0;

   virtual Result::Code Release() = 0;

 protected:
   virtual Result::Code JobScheduler() = 0;

   ThreadFunction pCurrentJob;
};


class Win32Thread: public OSThread
{
 friend DWORD __stdcall Win32Thread_JobSchedulerProxy(Win32Thread *);
 public:
            Win32Thread();
   virtual ~Win32Thread();

   virtual Result::Code Initialize();
   virtual Result::Code Execute(ThreadFunction, unsigned int bWait);
   virtual bool         IsBusy();

   virtual Result::Code Release();


 protected:
   virtual Result::Code JobScheduler();

   HANDLE hThread;
   DWORD  uThreadID;

   HANDLE hEvent_JobAvailable;
   HANDLE hEvent_ThreadReady;
   HANDLE hEvent_ExitThread;
};