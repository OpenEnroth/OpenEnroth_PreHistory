#pragma once
#include "..\\CoreDefinitions.h"
#include "..\\memory_mng.h"


template<typename type>
  struct Pool
{
 struct Slot
 {
  inline Slot():
    bUsed(false)
  {}

  bool bUsed;
  type cData;
 };
 typedef struct Pool<type>::Slot SlotType;


 inline Result::Code Allocate(unsigned int uSize)
 {
  pPool = MemAlloc(SlotType *, uSize);
  for (unsigned int i = 0; i < uSize; ++i)
    pPool[i] = MemAlloc(SlotType, 1);

  return Result::Success;
 }

 Result::Code GetSlot(type **pOutPtr)
 {
  for (unsigned int i = 0; i < uPoolSize; ++i)
    if (!pPool[i]->bUsed)
      return &pPool[i];

  unsigned int   uNewSize = uPoolSize + uPoolSize / 4 + 4;
  SlotType     **pNewPool = MemAlloc(SlotType *, uNewSize);

  for (unsigned int i = 0; i < uPoolSize; ++i)
    pNewPool[i] = pPool[i];
  for (unsigned int i = uPoolSize; i < uNewSize; ++i)
  {
   pNewPool[i] = MemAlloc(SlotType, 1);
   pNewPool[i]->bUsed = false;
  }

  MemFree(pPool);

  if (ppOutPtr)
  {
   pNewPool[uPoolSize]->bUsed = true;
   *pOutPtr = &pNewPool[uPoolSize]->cData;
  }

  uPoolSize = uNewSize;
  pPool = pNewPool;

  return Result::Success;
 }



 inline Pool():
   uPoolSize(0), pPool(nullptr)
 {}
 inline Pool(unsigned int uSize):
   uPoolSize(uSize)
 {
  Allocate(uSize);
 }

 unsigned int   uPoolSize;
 SlotType     **pPool;
};
