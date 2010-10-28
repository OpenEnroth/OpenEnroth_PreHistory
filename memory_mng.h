 #pragma once



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
	private:
		void CreateFileDump(const char *a2);
	public:
	 bool AllocateBigBuffer( unsigned int uNumKBytes);
	 void DeleteBuffer(void *pMem);
	 void *AllocatedNamedBuffer(void* obj_test, long size, const char *pBufferName);
	 MemoryMng();
	~MemoryMng();
	};



