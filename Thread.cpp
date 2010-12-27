#include "Thread.h"





bool Win32Thread::IsBusy()
{
 return WaitForSingleObject(hEvent_ThreadReady, 0) != WAIT_OBJECT_0;
}



Result::Code Win32Thread::Initialize()
{
 hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Win32Thread_JobSchedulerProxy, this, CREATE_SUSPENDED, &uThreadID);

 hEvent_ThreadReady = CreateEventW(0, true, true, 0);
 hEvent_JobAvailable = CreateEventW(0, true, false, 0);
 hEvent_ExitThread = CreateEventW(0, true, false, 0);

 ResumeThread(hThread);

 return Result::Success;
}



Result::Code Win32Thread::Execute(ThreadFunction pNewJob, unsigned int bWait)
{
 if (WaitForSingleObject(hEvent_ThreadReady, 0) != WAIT_OBJECT_0)
 {
  if (!bWait)
    return Result::Generic;

  WaitForSingleObject(hEvent_ThreadReady, INFINITE);
 }

 pCurrentJob = pNewJob;

 ResetEvent(hEvent_ThreadReady);
 SetEvent(hEvent_JobAvailable);

 return Result::Success;
}




Result::Code Win32Thread::Release()
{
 SetEvent(hEvent_ExitThread);
 SetEvent(hEvent_JobAvailable);

 while (WaitForSingleObject(hEvent_ThreadReady, 0) == WAIT_OBJECT_0)
   Sleep(0);

 CloseHandle(hThread);
 CloseHandle(hEvent_JobAvailable);
 CloseHandle(hEvent_ThreadReady);
 CloseHandle(hEvent_ExitThread);

 return Result::Success;
}










Result::Code Win32Thread::JobScheduler()
{
 while (true)
 {
  WaitForSingleObject(hEvent_JobAvailable, INFINITE);

  if (WaitForSingleObject(hEvent_ExitThread, 0) == WAIT_OBJECT_0)
    break;

  (pCurrentJob)();

  ResetEvent(hEvent_JobAvailable);
  SetEvent(hEvent_ThreadReady);
 }

 ResetEvent(hEvent_ThreadReady);
 return Result::Success;
}


DWORD __stdcall Win32Thread_JobSchedulerProxy(Win32Thread *pOwner)
{
 pOwner->JobScheduler();

 return 0;
}




Win32Thread::Win32Thread():
  OSThread()
{
 hThread = INVALID_HANDLE_VALUE;
}

Win32Thread::~Win32Thread()
{
}
