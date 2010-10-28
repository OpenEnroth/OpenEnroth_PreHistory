#include "memory_mng.h"


#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

 void  CheckMemoryAccess(void *memory_base, long memory_size);

//mm7eng
/*
.text:00426C01                   c23_constr    
 //mm7ru
	00426429
*/
 MemoryMng::MemoryMng()
	{
	ulong i;
	 uBigBufferSizeAligned=0;
     bBigBufferAllocated=false;
	for(i=0; i<6000; ++i)
		{
		pMemoryBuffers[i]=NULL;
		uMemoryBufferSizes[i]=0;
		aBufferNames[i][0]=0;
		}
	 pBigBufferAligned=NULL;
	 }


 ///mm7eng destr 0046355A 
/*
 mov     eax, [ecx+1D4C8h]
 pop     ecx	*/
MemoryMng::~MemoryMng()
	{
	if (pBigMemoryBuffer)
		free(pBigMemoryBuffer);
	 }

//----- (MM7.exe::00426755) --------------------------------------------------------
void *MemoryMng::AllocatedNamedBuffer(void* obj_test, long size, const char *pBufferName)
{
 
  int aligned_size; 
  

 if (!(obj_test==NULL)&&(!pGame->dword_000004))
    err_show();

 if (!bBigBufferAllocated&&(!pGame->dword_000004 ))
    err_show();

 if (size==0)
 {
  if ( !pGame->dword_000004)
    err_show();
  return NULL;
 }
	 
  if ((uNumMemoryBuffersUsed >= 6000)&&(!pGame->dword_000004))
    err_show();

  uNumMemoryBuffersUsed++;

  if (!bUseBigBuff)
  {
    pMemoryBuffers[uNumMemoryBuffersUsed] = malloc(size);
   if (pMemoryBuffers[uNumMemoryBuffersUsed])
     uMemoryBufferSizes[uNumMemoryBuffersUsed] = size;
   else
   {
    if (!pGame->dword_000004)
      err_show();
   }
  }
  else
  {

   aligned_size =(size&0xFFFFFFFC) + 4;

   if ((uNextFreeOffsetInBigBuffer +aligned_size) > uBigBufferSizeAligned)
   {
    printf("Id: %s  Size: %i", pBufferName, aligned_size);
    CreateFileDump( "Memory");
    if (!pGame->dword_000004)
      err_show();
   }

   pMemoryBuffers[uNumMemoryBuffersUsed] = (char *)(pBigBufferAligned) + uNextFreeOffsetInBigBuffer;
   uMemoryBufferSizes[uNumMemoryBuffersUsed] =aligned_size;

   if (pBufferName)
     strncpy(aBufferNames[uNumMemoryBuffersUsed], pBufferName, 11);
   uNextFreeOffsetInBigBuffer += aligned_size;
  }
  return pMemoryBuffers[uNumMemoryBuffersUsed];

}

//----- (MM7.exe::00426474) -----00426C4C---------------------------------------------------
void  MemoryMng::DeleteBuffer(void *pMem)
{
 
 int i; 
 int j; 
 int  uBuffindx; 
 int indx;

 if (pMem)
 {
  if (!bBigBufferAllocated)
  {
   if (!pGame->dword_000004)
     err_show();
  }

 
  for (i = 0; i <= uNumMemoryBuffersUsed; ++i)
    if (pMemoryBuffers[i] == pMem)
		{
		indx=i;
		break;
		}
 
  if (i>uNumMemoryBuffersUsed)
  {
   if (!pGame->dword_000004)
      err_show();
   return;
  }

  if (!bUseBigBuff)
    free(pMemoryBuffers[indx]);

  pMemoryBuffers[indx] = NULL;
  uMemoryBufferSizes[indx] = 0;
  aBufferNames[indx][0] = 0;

  if (indx == (uNumMemoryBuffersUsed))
  {
   if (indx>0)
   {
    uBuffindx = 0;
    for (j = 0; j <= uNumMemoryBuffersUsed; ++j)
    {
     if (pMemoryBuffers[j])
        uBuffindx = j;
    }

    uNumMemoryBuffersUsed =  uBuffindx + 1;

    if (bUseBigBuff)
      uNextFreeOffsetInBigBuffer = 
	  ((long)((char*)pMemoryBuffers[uBuffindx] -(char*)pBigBufferAligned)+ uMemoryBufferSizes[uBuffindx]);
   }
   else
   {
    uNumMemoryBuffersUsed = 0;
    uNextFreeOffsetInBigBuffer = 0;
   }
  }
 }

}

//----- (MM7.exe::004266CD) ---------text:00426EB3-----------------------------------------------
bool MemoryMng::AllocateBigBuffer( unsigned int uNumKBytes)
{
 
 if (bBigBufferAllocated)
   return false;

 if (uNumKBytes)
 {
  pBigMemoryBuffer = malloc(uNumKBytes * 1024);
  if (!pBigMemoryBuffer)
    return false;
  uBigBufferSizeAligned = (uNumKBytes * 1024) - 4096;
 

  pBigBufferAligned = (void *)((int)(pBigMemoryBuffer) & 0xFFFF0000 + 4096);

 CheckMemoryAccess(pBigBufferAligned, uBigBufferSizeAligned);   
  uNumMemoryBuffersUsed = 0;
  uNextFreeOffsetInBigBuffer = 0;
 
  bUseBigBuff =true;
  bBigBufferAllocated = true;
 }
 else
 {
  bUseBigBuff = false;
 }
 return bBigBufferAllocated;
}

//----- (00426892) --------.text:00427082------------------------------------------------
void  CheckMemoryAccess(void *memory_base, long memory_size)
{
  
  SYSTEM_INFO SystemInfo; // [sp+8h] [bp-24h]@1
  long mem_pos, mem_pos2;

  GetSystemInfo(&SystemInfo);
  if  (SystemInfo.dwPageSize*16<memory_size)
	  {
  	  char d;
	  mem_pos=SystemInfo.dwPageSize*16;
	 
	  do
		 {
		  mem_pos2=mem_pos-SystemInfo.dwPageSize*16;
	      d=*((char*)memory_base+mem_pos);
	      d=*((char*)memory_base+mem_pos2);
		  mem_pos+=SystemInfo.dwPageSize;
		 }	
	 while(memory_size>mem_pos);
	  }

}

//----- (MM7.exe::0042654C) --------------------------------------------------------
void MemoryMng::CreateFileDump( const char *type_of_dump)
{
  FILE *dump_file; 
  int i; 
  unsigned int counted_size; 
  unsigned int all_size; 
  struct _MEMORYSTATUS Buffer; 
  char pFilename[256]; 

  sprintf(pFilename, "Mem%03i.txt", dumps_count++);
 dump_file = fopen(pFilename, "w");
  if (dump_file)
  {
   if (type_of_dump)
     fprintf(dump_file, "%s\n\n",type_of_dump);

   fprintf(dump_file, "Windows Memory Status");
   GlobalMemoryStatus(&Buffer);
   fprintf(dump_file, "dwLength:         %d\n\n", Buffer.dwLength);
   fprintf(dump_file, "dwMemoryLoad:     %d\n", Buffer.dwMemoryLoad);
   fprintf(dump_file, "dwTotalPhys:      %d\n", Buffer.dwTotalPhys);
   fprintf(dump_file, "dwAvailPhys:      %d\n", Buffer.dwAvailPhys);
   fprintf(dump_file, "dwTotalPageFile:  %d\n", Buffer.dwTotalPageFile);
   fprintf(dump_file, "dwAvailPageFile:  %d\n", Buffer.dwAvailPageFile);
   fprintf(dump_file, "dwTotalVirtual:   %d\n", Buffer.dwTotalVirtual);
   fprintf(dump_file, "dwAvailVirtual:   %d\n\n\n", Buffer.dwAvailVirtual);

   
   counted_size = 0;

   if (uNumMemoryBuffersUsed > 0)
   {
    for (i=0; i<uNumMemoryBuffersUsed; ++i) 
      counted_size += uMemoryBufferSizes[i];
    
   }

   all_size = 0;
   for (i=0; i<6000; ++i) 
      all_size += uMemoryBufferSizes[i];
   
   fprintf(dump_file, "Size: %i  %i  %i\n\n", uNumMemoryBuffersUsed, counted_size , all_size);
   if (uNumMemoryBuffersUsed > 0)
   {
     for (i=0; i<=uNumMemoryBuffersUsed; ++i) 

           fprintf(dump_file, "%10i %10i %s\n", i, uMemoryBufferSizes[i], aBufferNames[i]);
   }
   fclose(dump_file);
  }
  
}
