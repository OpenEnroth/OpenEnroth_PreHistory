#pragma once
#include "CoreDefinitions.h"
#include "defs.h"

/*
//class23
class MemoryMng
{
	void         *pMemoryBuffers[6000];       //array ptr [000000]
    long          uMemoryBufferSizes[6000];   //array ptr [005DC0]
    char          aBufferNames[6000][12];     //array ptr [00BB80]
    int           dumps_count;
    int           uNumMemoryBuffersUsed;      //dword ptr [01D4C4]

    void         *pBigMemoryBuffer;           //dword ptr [01D4C8]
    long          uNextFreeOffsetInBigBuffer; //dword ptr [01D4CC]
    long          uBigBufferSizeAligned;   //dword ptr [01D4D0]
    bool          bBigBufferAllocated;        //dword ptr [01D4D4]
    bool          bUseBigBuff;			   //dword ptr [01D4D8]
    void         *pBigBufferAligned;   //dword ptr [01D4DC]


		void CreateFileDump(const char *a2);
 public:

	 bool AllocateBigBuffer( unsigned int uNumKBytes);
	 void DeleteBuffer(void *pMem);
	 void *AllocatedNamedBuffer(void* obj_test, long size, const char *pBufferName);
	 MemoryMng();
	~MemoryMng();
};
*/

























#ifdef _DEBUG
  #include <typeinfo>
  #include <windows.h>
  #include <stdio.h>
#else
  extern "C" void *__cdecl memset(void *, int, unsigned int);
  extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);
#endif

struct MemoryBlock
{
 unsigned int  uElementSize;
 unsigned int  uNumElements;

 void          *pAddress;
#ifdef _DEBUG
 char           pBlockName[32];
 char           pFileName[288];
 char           pFunctionName[64];
 unsigned int   uFileLine;
 char           pElementName[64];
 SYSTEMTIME     stAllocationTime;
#endif
};


class MemoryWatch
{
 public:
   inline MemoryWatch()
   {
    uOverallAllocations = 0;
    uOverallDeallocations = 0;
    uCurrentMemoryUsage = 0;
    uPeakMemoryUsage = 0;

    uNumBlocks = 0;
    uNumBlocksAllocated = 512;

#ifdef _DEBUG
    CreateDirectoryW(L".\\log", 0);
    pLog = _wfopen(L".\\log\\memory.log", L"w+t");

    memset(&stLastInfoOutput, 0, sizeof(SYSTEMTIME));
#endif

    pBlocks = new MemoryBlock *[uNumBlocksAllocated];
    memset(pBlocks, 0, uNumBlocksAllocated * sizeof(void *));
   }

   ~MemoryWatch()
   {
#ifdef _DEBUG
    fprintf(pLog, "\n\n\n-------------------------------------------------------\n");
    fprintf(pLog, "Overall number of allocations:\t\t%lu\n", uOverallAllocations);
    fprintf(pLog, "Overall number of deallocations:\t%lu\n", uOverallDeallocations);
    fprintf(pLog, "Peak Memory usage:\t\t\t%lu Gb %lu Mb %lu Kb %lub (%lu bytes)\n",
            uPeakMemoryUsage / (1024 * 1024 * 1024),
            uPeakMemoryUsage % (1024 * 1024 * 1024) / (1024 * 1024),
            uPeakMemoryUsage % (1024 * 1024) / 1024,
            uPeakMemoryUsage % 1024,
            uPeakMemoryUsage);
    if (uOverallAllocations - uOverallDeallocations)
    {
     fprintf(pLog, "Memory leaks:\t\t\t\t%lu\n", uOverallAllocations - uOverallDeallocations);

     unsigned int i = 0;
     for (unsigned int j = 0; j < uOverallAllocations - uOverallDeallocations; ++i, ++j)
     {
      while (!pBlocks[i])
        ++i;

      fprintf(pLog, "\t%s[%lu] @ %p (%lu bytes) is left behind\n", 
              pBlocks[i]->pElementName, pBlocks[i]->uNumElements,
              pBlocks[i]->pAddress,
              pBlocks[i]->uNumElements * pBlocks[i]->uElementSize);
     }
    }
    else fprintf(pLog, "Memory leaks:\t\t\t\tno");
    fclose(pLog);
#endif

    for (unsigned int i = 0; i < uNumBlocksAllocated; ++i)
      if (pBlocks[i])
        delete pBlocks[i];
   }


#ifdef _DEBUG
   inline Result::Code MakeRealtimeReport()
   {
    SYSTEMTIME stCurrentTime;
    GetSystemTime(&stCurrentTime);

    if (!stLastInfoOutput.wYear ||
        1000 * ((60 * stCurrentTime.wHour + stCurrentTime.wMinute) * 60 + stCurrentTime.wSecond) -
        1000 * ((60 * stLastInfoOutput.wHour + stLastInfoOutput.wMinute) * 60 + stLastInfoOutput.wSecond) >= 750)
    {
     char pMsg[256];
     sprintf(pMsg, "Current Memory usage:\t%lu Gb %lu Mb %lu Kb %lub (%lu bytes %u%% of peak %lu bytes)\n",
             uCurrentMemoryUsage / (1024 * 1024 * 1024),
             uCurrentMemoryUsage % (1024 * 1024 * 1024) / (1024 * 1024),
             uCurrentMemoryUsage % (1024 * 1024) / 1024,
             uCurrentMemoryUsage % 1024,
             uPeakMemoryUsage, (unsigned int)(100.0 * uCurrentMemoryUsage / uPeakMemoryUsage), uPeakMemoryUsage);

     OutputDebugStringA(pMsg);
     fflush(pLog);

     memcpy(&stLastInfoOutput, &stCurrentTime, sizeof(SYSTEMTIME));
    }

    return Result::Success;
   }

   template<typename type>
     inline Result::Code TrackAllocation(type *pMemory, unsigned int uNumElements, const char *pAllocationName,
                                          const char *pFunction, const char *pFile, unsigned int uLine)
   {
    if (!uNumElements)
    {
     //excessive allocation
    }

    if (uNumBlocks == uNumBlocksAllocated)
    {
     unsigned int         uNewNumBlocks = uNumBlocksAllocated + 256;
     struct MemoryBlock **pNewBlocks = new MemoryBlock *[uNewNumBlocks];

     memcpy(pNewBlocks, pBlocks, uNumBlocksAllocated * sizeof(void *));
     memset(pNewBlocks + uNumBlocksAllocated, 0, (uNewNumBlocks - uNumBlocksAllocated) * sizeof(void *));
     delete [] pBlocks;

     pBlocks = pNewBlocks;
     uNumBlocksAllocated = uNewNumBlocks;
    }


    unsigned int i = 0;
    for (i; i < uNumBlocksAllocated; ++i)
      if (!pBlocks[i])
        break;

    struct MemoryBlock *pBlock = new struct MemoryBlock;
    pBlocks[i] = pBlock;

    pBlock->uElementSize = sizeof(type);
    pBlock->uNumElements = uNumElements;
    lstrcpyA(pBlock->pElementName, typeid(type).name());

    lstrcpyA(pBlock->pBlockName, pAllocationName);
    lstrcpyA(pBlock->pFileName, pFile);
    lstrcpyA(pBlock->pFunctionName, pFunction);
    pBlock->uFileLine = uLine;
    GetSystemTime(&pBlock->stAllocationTime);

    pBlock->pAddress = pMemory;

    uNumBlocks++;
    uCurrentMemoryUsage += uNumElements * sizeof(type);
    uOverallAllocations++;
    if (uPeakMemoryUsage < uCurrentMemoryUsage)
      uPeakMemoryUsage = uCurrentMemoryUsage;


    fprintf(pLog, "[%02hu/%02hu/%04hu %02hu:%02hu:%02hu] MemAlloc \"%s\": %s[%lu] @ %p (%lu bytes) in %s (line %lu in file \"%s\")\n",
            pBlock->stAllocationTime.wDay, pBlock->stAllocationTime.wMonth, pBlock->stAllocationTime.wYear,
            pBlock->stAllocationTime.wHour, pBlock->stAllocationTime.wMinute, pBlock->stAllocationTime.wSecond,
            pBlock->pBlockName,
            pBlock->pElementName, pBlock->uNumElements, pBlock->pAddress, uNumElements * sizeof(type), pFunction, uLine, pFile);


    if (!pMemory)
    {
     MessageBoxW(0, L"MemAlloc returned 0!", 0, 0);
     ExitProcess(0);
    }

    MakeRealtimeReport();
    return Result::Success;
   }
#else
   inline Result::Code TrackAllocation(void *pMemory, unsigned int uElemSize, unsigned int uNumElements)
   {
    if (uNumBlocks == uNumBlocksAllocated)
    {
     unsigned int         uNewNumBlocks = uNumBlocksAllocated + 256;
     struct MemoryBlock **pNewBlocks = new struct MemoryBlock *[uNewNumBlocks];

     memcpy(pNewBlocks, pBlocks, uNumBlocksAllocated * sizeof(void *));
     memset(pNewBlocks + uNumBlocksAllocated, 0, (uNewNumBlocks - uNumBlocksAllocated) * sizeof(void *));
     delete [] pBlocks;

     pBlocks = pNewBlocks;
     uNumBlocksAllocated = uNewNumBlocks;
    }

    unsigned int i;
    for (i = 0; i < uNumBlocksAllocated; ++i)
      if (!pBlocks[i])
        break;

    pBlocks[i] = new struct MemoryBlock;

    pBlocks[i]->uElementSize = uElemSize;
    pBlocks[i]->uNumElements = uNumElements;

    pBlocks[i]->pAddress = pMemory;

    uNumBlocks++;
    uCurrentMemoryUsage += uNumElements * uElemSize;
    uOverallAllocations++;
    if (uPeakMemoryUsage < uCurrentMemoryUsage)
      uPeakMemoryUsage = uCurrentMemoryUsage;

    return Result::Success;
   }
#endif


#ifdef _DEBUG
   template<typename type>
     inline Result::Code TrackDeallocation(type *pMemory, const char *pFunction, const char *pFile, unsigned int uLine)
   {
    if (!pMemory)
    {
     SYSTEMTIME st;
     GetSystemTime(&st);
     fprintf(pLog, "[%02hu/%02hu/%04hu %02hu:%02hu:%02hu] WARNING: Attempting to free nullptr in %s (line %lu in file \"%s\")\n",
             st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond, pFunction, uLine, pFile);
     fflush(pLog);
     
     MakeRealtimeReport();
     return Result::Success;
    }

    unsigned int bFound = false;
    for (unsigned int i = 0; i < uNumBlocksAllocated; ++i)
      if (pBlocks[i] && pBlocks[i]->pAddress == pMemory)
      {
       bFound = true;

       uCurrentMemoryUsage -= pBlocks[i]->uNumElements * pBlocks[i]->uElementSize;
       uNumBlocks--;

       struct MemoryBlock *pBlock = pBlocks[i];

       SYSTEMTIME st;
       GetSystemTime(&st);
       fprintf(pLog, "[%02hu/%02hu/%04hu %02hu:%02hu:%02hu] MemFree: %s[%lu] @ %p (%lu bytes) in %s (line %lu in file \"%s\")\n",
               st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond,
               pBlock->pElementName, pBlock->uNumElements, pBlock->pAddress, pBlock->uNumElements * pBlock->uElementSize, pFunction, uLine, pFile);


       delete pBlocks[i];
       pBlocks[i] = 0;
       uOverallDeallocations++;
      }

    if (!bFound)
    {
     SYSTEMTIME st;
     GetSystemTime(&st);
     fprintf(pLog, "[%02hu/%02hu/%04hu %02hu:%02hu:%02hu] WARNING: Uncharted allocation @ %p in %s (line %lu in file \"%s\")\n",
             st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond,
             pMemory, pFunction, uLine, pFile);
    }
    
    MakeRealtimeReport();
    return Result::Success;
   }
#else
   inline Result::Code TrackDeallocation()
   {
    uOverallDeallocations++;
    return Result::Success;
   }
#endif

 protected:
   unsigned int uOverallAllocations;
   unsigned int uOverallDeallocations;
   unsigned int uCurrentMemoryUsage;
   unsigned int uPeakMemoryUsage;

   unsigned int uNumBlocks;
   unsigned int uNumBlocksAllocated;
   
   struct MemoryBlock **pBlocks;
#ifdef _DEBUG
   FILE       *pLog;
   SYSTEMTIME  stLastInfoOutput;
#endif
  };



extern MemoryWatch *pMemoryWatch;











#ifdef _DEBUG
  template<typename type>
    type *Allocator(unsigned int uNumElements, const char *pAllocationName, const char *pFile,
                    const char *pFunction, unsigned int uLine)
  {
   type *pMemory = new type[uNumElements];
   pMemoryWatch->TrackAllocation(pMemory, uNumElements, pAllocationName, pFunction, pFile, uLine);

   return pMemory;
  }
    
  #define MemAlloc(type, elements) \
    Allocator<type>(elements, "unnamed", __FILE__, __FUNCTION__, __LINE__)

  #define NamedMemAlloc(type, elements, name) \
    Allocator<type>(elements, name, __FILE__, __FUNCTION__, __LINE__)


  #define MemFree(what)\
  {\
   pMemoryWatch->TrackDeallocation(what, __FUNCTION__, __FILE__, __LINE__);\
   delete [] what;\
  }

#else
  template<typename type>
    type *Allocator(unsigned int uNumElements)
  {
   type *pMemory = new type[uNumElemes];
   pMemoryWatch->TrackAllocation(sizeof(type), uNumElements);
  }
    
  #define MemAlloc(type, elements) \
    Allocator(elements)

  #define NamedMemAlloc(type, elements, name) \
    Allocator(elements)

  #define MemFree(what)\
  {\
   pMemoryWatch->TrackDeallocation();\
   delete [] what;\
  }
#endif