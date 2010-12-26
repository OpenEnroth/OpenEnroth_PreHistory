#pragma once
#include "..\\CoreDefinitions.h"
#include "..\\memory_mng.h"





template<typename type>
  struct List
{
 struct Node
 {
  inline Node():
    pData(0), pPrev(0), pNext(0)
  {}

  inline Node(type pDataPtr):
    pData(pDataPtr)
  {}

  inline Node(type pItem, Node *prev, Node *next):
    pData(Item), pPrev(prev), pNext(next)
  {}

  type  pData;
  Node *pPrev,
       *pNext;
 };
 typedef struct List<type>::Node NodeType;


 inline List()
 {
  pHead = pTail = 0;

  pNodePool = MemAlloc(NodeType, uPoolSize = 32);
 }

 virtual ~List()
 {}


 inline Result::Code Clear()
 {
  pHead = pTail = 0;

  return Result::Success;
 }

 inline Result::Code Add(type pElement)
 {
  unsigned int uFreePoolSlot;
  for (uFreePoolSlot = 0; uFreePoolSlot < uPoolSize; ++uFreePoolSlot)
    if (!pNodePool[uFreePoolSlot].pData)
       break;

  if (uFreePoolSlot == uPoolSize)
  {
   unsigned int  uNewSize = uPoolSize + uPoolSize / 4 + 4;
   NodeType     *pNewPool = MemAlloc(NodeType, uNewSize);

   memcpy(pNewPool, pNodePool, uPoolSize * sizeof(NodeType));
   memset(pNewPool + uPoolSize, 0, (uNewSize - uPoolSize) * sizeof(NodeType));
   
   uFreePoolSlot = uPoolSize;
   MemFree(pNewPool);

   uPoolSize = uNewSize;
   pNodePool = pNewPool;
  }


  Node *pNewTail = &pNodePool[uFreePoolSlot];
  if (!pHead)
  {
   pHead = pTail = pNewTail;
   pNewTail->pData = pElement;
  }
  else
  {
   pNewTail->pData = pElement;
  }

  pTail->pNext = pNewTail;
  pTail = pNewTail;

  return Result::Success;
 }

 
 inline NodeType *First() {return pHead;}
 inline NodeType *Last()  {return pTail;}



 Node         *pHead,
              *pTail;

 unsigned int  uPoolSize;
 NodeType     *pNodePool;
};