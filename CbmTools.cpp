#include <stdio.h>
#include <windows.h>

//#include "CbmTools.h"




#pragma pack(push, 1)
struct CBMHeader
{
 unsigned long cbmSignature;
 unsigned long cbmWidth;
 unsigned long cbmHeight;
 unsigned long cbmCompression;
 unsigned long cbmAlphaSize;
 unsigned long cbmRedSize;
 unsigned long cbmGreenSize;
 unsigned long cbmBlueSize;
};
#pragma pack(pop)





unsigned long rle8_estimate(const unsigned char *pSource, unsigned long ulSize);
unsigned char *rle8_compress(const unsigned char *pSource, unsigned long ulSize, unsigned long *pCompressedSize);
unsigned char *rle8_decompress(const unsigned char *pSource, unsigned long ulCompressedSize, unsigned long ulSize);

unsigned long rle16_estimate(const unsigned char *pSource, unsigned long ulSize);
unsigned char *rle16_compress(const unsigned char *pSource, unsigned long ulSize, unsigned long *pCompressedSize);
unsigned char *rle16_decompress(const unsigned char *pSource, unsigned long ulCompressedSize, unsigned long ulSize);





extern "C" unsigned int LoadCBM(const wchar_t *pFile, unsigned int *pWidth, unsigned int *pHeight, unsigned int **ppPixels)
{
 DWORD  w;
 void  *hFile = CreateFileW(pFile, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
 if (hFile == INVALID_HANDLE_VALUE)
   return false;

 struct CBMHeader cbmHeader;
 ReadFile(hFile, &cbmHeader, sizeof(struct CBMHeader), &w, 0);

 unsigned int  *pPixels = (unsigned int *)(malloc(cbmHeader.cbmWidth * cbmHeader.cbmHeight * 4));
 unsigned char *pCompressedChannel = new unsigned char[cbmHeader.cbmWidth * cbmHeader.cbmHeight],
               *pChannel;

 ReadFile(hFile, pCompressedChannel, cbmHeader.cbmAlphaSize, &w, 0);
 if (cbmHeader.cbmCompression & 0x08000000)
   pChannel = rle8_decompress(pCompressedChannel, cbmHeader.cbmAlphaSize, cbmHeader.cbmWidth * cbmHeader.cbmHeight);
 else if (cbmHeader.cbmCompression & 0x10000000)
   pChannel = rle16_decompress(pCompressedChannel, cbmHeader.cbmAlphaSize, cbmHeader.cbmWidth * cbmHeader.cbmHeight);
 else
 {
  pChannel = (unsigned char *)(malloc(cbmHeader.cbmWidth * cbmHeader.cbmHeight));
  memcpy(pChannel, pCompressedChannel, cbmHeader.cbmWidth * cbmHeader.cbmHeight);
 }

 for (int i = 0; i < cbmHeader.cbmWidth * cbmHeader.cbmHeight; ++i)
 {
  pPixels[i] = (unsigned int)(pChannel[i]) << 24;
 }
 free(pChannel);



 ReadFile(hFile, pCompressedChannel, cbmHeader.cbmRedSize, &w, 0);
 if (cbmHeader.cbmCompression & 0x00080000)
   pChannel = rle8_decompress(pCompressedChannel, cbmHeader.cbmRedSize, cbmHeader.cbmWidth * cbmHeader.cbmHeight);
 else if (cbmHeader.cbmCompression & 0x00100000)
   pChannel = rle16_decompress(pCompressedChannel, cbmHeader.cbmRedSize, cbmHeader.cbmWidth * cbmHeader.cbmHeight);
 else
 {
  pChannel = (unsigned char *)(malloc(cbmHeader.cbmWidth * cbmHeader.cbmHeight));
  memcpy(pChannel, pCompressedChannel, cbmHeader.cbmWidth * cbmHeader.cbmHeight);
 }

 for (int i = 0; i < cbmHeader.cbmWidth * cbmHeader.cbmHeight; ++i)
 {
  pPixels[i] |= (unsigned int)(pChannel[i]) << 16;
 }
 free(pChannel);





 ReadFile(hFile, pCompressedChannel, cbmHeader.cbmGreenSize, &w, 0);
 if (cbmHeader.cbmCompression & 0x00000800)
   pChannel = rle8_decompress(pCompressedChannel, cbmHeader.cbmGreenSize, cbmHeader.cbmWidth * cbmHeader.cbmHeight);
 else if (cbmHeader.cbmCompression & 0x00001000)
   pChannel = rle16_decompress(pCompressedChannel, cbmHeader.cbmGreenSize, cbmHeader.cbmWidth * cbmHeader.cbmHeight);
 else
 {
  pChannel = (unsigned char *)(malloc(cbmHeader.cbmWidth * cbmHeader.cbmHeight));
  memcpy(pChannel, pCompressedChannel, cbmHeader.cbmWidth * cbmHeader.cbmHeight);
 }

 for (int i = 0; i < cbmHeader.cbmWidth * cbmHeader.cbmHeight; ++i)
 {
  pPixels[i] |= (unsigned int)(pChannel[i]) << 8;
 }
 free(pChannel);






 ReadFile(hFile, pCompressedChannel, cbmHeader.cbmBlueSize, &w, 0);
 if (cbmHeader.cbmCompression & 0x00000008)
   pChannel = rle8_decompress(pCompressedChannel, cbmHeader.cbmBlueSize, cbmHeader.cbmWidth * cbmHeader.cbmHeight);
 else if (cbmHeader.cbmCompression & 0x00000010)
   pChannel = rle16_decompress(pCompressedChannel, cbmHeader.cbmBlueSize, cbmHeader.cbmWidth * cbmHeader.cbmHeight);
 else
 {
  pChannel = (unsigned char *)(malloc(cbmHeader.cbmWidth * cbmHeader.cbmHeight));
  memcpy(pChannel, pCompressedChannel, cbmHeader.cbmWidth * cbmHeader.cbmHeight);
 }

 for (int i = 0; i < cbmHeader.cbmWidth * cbmHeader.cbmHeight; ++i)
 {
  pPixels[i] |= (unsigned int)(pChannel[i]);
 }
 free(pChannel);


 *pWidth = cbmHeader.cbmWidth;
 *pHeight = cbmHeader.cbmHeight;
 *ppPixels = pPixels;

 delete [] pCompressedChannel;
 return true;
}


unsigned char *rle8_compress(const unsigned char *pSource, unsigned long ulSize, unsigned long *pCompressedSize)
{
 unsigned long ulNewSize = 0;
 unsigned char *p = (unsigned char *)(malloc(ulSize * 2));

 for (unsigned long i = 0; i < ulSize;)
 {
  if (pSource[i] == pSource[i + 1] && pSource[i + 1] == pSource[i + 2])
  {
   unsigned long ulSequenceLength = 3;
   while (i + ulSequenceLength < ulSize && pSource[i] == pSource[i + ulSequenceLength] && ulSequenceLength < 0x7F)
     ulSequenceLength++;

   p[ulNewSize] = ulSequenceLength | 0x80;
   p[ulNewSize + 1] = pSource[i];

   ulNewSize += 2;
   i += ulSequenceLength;
  }
  else
  {
   unsigned long ulSequenceLength = 1;
   while (i + ulSequenceLength < ulSize && ulSequenceLength < 0x7F &&
          !(pSource[i + ulSequenceLength] == pSource[i + ulSequenceLength + 1] && pSource[i + ulSequenceLength + 1] == pSource[i + ulSequenceLength + 2]) )
     ulSequenceLength++;

   p[ulNewSize] = ulSequenceLength;
   memcpy(&p[ulNewSize + 1], &pSource[i], ulSequenceLength);

   ulNewSize += ulSequenceLength + 1;
   i += ulSequenceLength;
  }
 }

 *pCompressedSize = ulNewSize;
 return p;
}




unsigned long rle8_estimate(const unsigned char *pSource, unsigned long ulSize)
{
 unsigned long ulNewSize = 0;

 for (unsigned long i = 0; i < ulSize;)
 {
  if (pSource[i] == pSource[i + 1] && pSource[i + 1] == pSource[i + 2])  //repeating sequence
  {
   unsigned long ulSequenceLength = 3;
   while (i + ulSequenceLength < ulSize && pSource[i] == pSource[i + ulSequenceLength] && ulSequenceLength < 0x7F)
     ulSequenceLength++;

   ulNewSize += 2;
   i += ulSequenceLength;
  }
  else
  {
   unsigned long ulSequenceLength = 1;
   while (i + ulSequenceLength < ulSize && ulSequenceLength < 0x7F &&
          !(pSource[i + ulSequenceLength] == pSource[i + ulSequenceLength + 1] && pSource[i + ulSequenceLength + 1] == pSource[i + ulSequenceLength + 2]) )
     ulSequenceLength++;

   ulNewSize += ulSequenceLength + 1;
   i += ulSequenceLength;
  }
 }

 return ulNewSize;
}




unsigned char *rle16_compress(const unsigned char *pSource, unsigned long ulSize, unsigned long *pCompressedSize)
{
 unsigned long ulNewSize = 0;
 unsigned char *p = (unsigned char *)(malloc(ulSize * 4));

 for (unsigned long i = 0; i < ulSize;)
 {
  if (pSource[i] == pSource[i + 1] && pSource[i + 1] == pSource[i + 2])  //repeating sequence
  {
   unsigned long ulSequenceLength = 3;
   while (i + ulSequenceLength < ulSize && pSource[i] == pSource[i + ulSequenceLength] && ulSequenceLength < 0x7FFF)
     ulSequenceLength++;

   *(unsigned short *)(&p[ulNewSize]) = ulSequenceLength | 0x8000;
   p[ulNewSize + 2] = pSource[i];

   ulNewSize += 3;
   i += ulSequenceLength;
  }
  else
  {
   unsigned long ulSequenceLength = 1;
   while (i + ulSequenceLength < ulSize && ulSequenceLength < 0x7FFF &&
          !(pSource[i + ulSequenceLength] == pSource[i + ulSequenceLength + 1] && pSource[i + ulSequenceLength + 1] == pSource[i + ulSequenceLength + 2]) )
     ulSequenceLength++;

   *(unsigned short *)(&p[ulNewSize]) = ulSequenceLength;
   memcpy(&p[ulNewSize + 2], &pSource[i], ulSequenceLength);

   ulNewSize += ulSequenceLength + 2;
   i += ulSequenceLength;
  }
 }

 *pCompressedSize = ulNewSize;
 return p;
}



unsigned long rle16_estimate(const unsigned char *pSource, unsigned long ulSize)
{
 unsigned long ulNewSize = 0;

 for (unsigned long i = 0; i < ulSize;)
 {
  if (pSource[i] == pSource[i + 1] && pSource[i + 1] == pSource[i + 2])  //repeating sequence
  {
   unsigned long ulSequenceLength = 3;
   while (i + ulSequenceLength < ulSize && pSource[i] == pSource[i + ulSequenceLength] && ulSequenceLength < 0x7FFF)
     ulSequenceLength++;

   ulNewSize += 3;
   i += ulSequenceLength;
  }
  else
  {
   unsigned long ulSequenceLength = 1;
   while (i + ulSequenceLength < ulSize && ulSequenceLength < 0x7FFF &&
          !(pSource[i + ulSequenceLength] == pSource[i + ulSequenceLength + 1] && pSource[i + ulSequenceLength + 1] == pSource[i + ulSequenceLength + 2]) )
     ulSequenceLength++;

   ulNewSize += ulSequenceLength + 2;
   i += ulSequenceLength;
  }
 }

 return ulNewSize;
}



unsigned char *rle8_decompress(const unsigned char *pSource, unsigned long ulCompressedSize, unsigned long ulSize)
{
 unsigned char *p = (unsigned char *)(malloc(ulSize));

 for (unsigned long i = 0, j = 0; i < ulCompressedSize;)
 {
  if (pSource[i] & 0x80)
  {
   memset(&p[j], pSource[i + 1], pSource[i] - 0x80);

   j += pSource[i] - 0x80;
   i += 2;
  }
  else
  {
   memcpy(&p[j], &pSource[i + 1], pSource[i]);

   j += pSource[i];
   i += pSource[i] + 1;
  }
 }
 return p;
}



unsigned char *rle16_decompress(const unsigned char *pSource, unsigned long ulCompressedSize, unsigned long ulSize)
{
 unsigned char *p = (unsigned char *)(malloc(ulSize));

 for (unsigned long i = 0, j = 0; i < ulCompressedSize;)
 {
  unsigned short signature = *(unsigned short *)(&pSource[i]);

  if (signature & 0x8000)
  {
   memset(&p[j], pSource[i + 2], signature - 0x8000);

   j += signature - 0x8000;
   i += 3;
  }
  else
  {
   memcpy(&p[j], &pSource[i + 2], signature);

   j += signature;
   i += signature + 2;
  }
 }
 return p;
}













extern "C" unsigned long Tga2CbmW(const wchar_t *pFile)
{

 wchar_t pTgaFile[256],
         pBmaFile[256];
 wsprintfW(pTgaFile, L"%s.tga", pFile);
 wsprintfW(pBmaFile, L"%s.cbm", pFile);

 DWORD  w;
 void  *hFile = CreateFileW(pTgaFile, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
 if (hFile == INVALID_HANDLE_VALUE)
 {
  MessageBoxW(0, L"Targa not found", L"Tga2Cbm", 0);
  return 1;
 }

 #pragma pack(push, 1)
 struct TGAHeader
 {
  unsigned char  tgaSkip;
  unsigned char  tgaDontCare1;
  unsigned char  tgaType;
  unsigned char  tgaDontCare2[9];
  unsigned short tgaWidth;
  unsigned short tgaHeight;
  unsigned char  tgaBPP;
  unsigned char  tgaDontCare3;
 };
 #pragma pack(pop)

 struct TGAHeader tgaHeader;
 ReadFile(hFile, &tgaHeader, sizeof(struct TGAHeader), &w, 0);
 SetFilePointer(hFile, tgaHeader.tgaSkip, 0, FILE_CURRENT);

 if (tgaHeader.tgaBPP != 32)
 {
  MessageBoxW(0, L"Invalid Targa format", L"Tga2Cbm", 0);

  CloseHandle(hFile);
  return 1;
 }

 unsigned int  ulWidth = tgaHeader.tgaWidth;
 unsigned int  ulHeight = tgaHeader.tgaHeight;
 unsigned int *pPixels = (unsigned int *)(malloc(ulWidth * ulHeight * sizeof(__int32)));

 ReadFile(hFile, pPixels, ulWidth * ulHeight * 4, &w, 0);
 CloseHandle(hFile);

 unsigned char *pAlpha = (unsigned char *)(malloc(ulWidth * ulHeight)),
               *pRed = (unsigned char *)(malloc(ulWidth * ulHeight)),
               *pGreen = (unsigned char *)(malloc(ulWidth * ulHeight)),
               *pBlue = (unsigned char *)(malloc(ulWidth * ulHeight));
 for (unsigned int i = 0; i < ulWidth * ulHeight; ++i)
 {
  pAlpha[i] = (pPixels[i] & 0xFF000000) >> 24;
  pRed[i] = (pPixels[i] & 0x00FF0000) >> 16;
  pGreen[i] = (pPixels[i] & 0x0000FF00) >> 8;
  pBlue[i] = pPixels[i] & 0x000000FF;
 }
 free(pPixels);



 struct CBMHeader cbmHeader;
 cbmHeader.cbmSignature = 'AMBC';
 cbmHeader.cbmWidth = ulWidth;
 cbmHeader.cbmHeight = ulHeight;
 cbmHeader.cbmCompression = 0;

 unsigned char *pOutChannel;
 unsigned long  size = ulWidth * ulHeight,
                size8, size16;
 size8 = rle8_estimate(pAlpha, size);
 size16 = rle16_estimate(pAlpha, size);
 if (size8 < size && size8 < size16)
 {
  pOutChannel = rle8_compress(pAlpha, size, &cbmHeader.cbmAlphaSize);
  cbmHeader.cbmCompression |= 0x08000000;

  free(pAlpha);
 }
 else if (size16 < size && size16 < size8)
 {
  pOutChannel = rle16_compress(pAlpha, size, &cbmHeader.cbmAlphaSize);
  cbmHeader.cbmCompression |= 0x10000000;

  free(pAlpha);
 }
 else
 {
  cbmHeader.cbmAlphaSize = size;
  pOutChannel = pAlpha;
 }
 pAlpha = pOutChannel;



 size8 = rle8_estimate(pRed, size);
 size16 = rle16_estimate(pRed, size);
 if (size8 < size && size8 < size16)
 {
  pOutChannel = rle8_compress(pRed, size, &cbmHeader.cbmRedSize);
  cbmHeader.cbmCompression |= 0x00080000;

  free(pRed);
 }
 else if (size16 < size && size16 < size8)
 {
  pOutChannel = rle16_compress(pRed, size, &cbmHeader.cbmRedSize);
  cbmHeader.cbmCompression |= 0x00100000;

  free(pRed);
 }
 else
 {
  cbmHeader.cbmRedSize = size;
  pOutChannel = pRed;
 }
 pRed = pOutChannel;






 size8 = rle8_estimate(pGreen, size);
 size16 = rle16_estimate(pGreen, size);
 if (size8 <= size && size8 <= size16)
 {
  pOutChannel = rle8_compress(pGreen, size, &cbmHeader.cbmGreenSize);
  cbmHeader.cbmCompression |= 0x00000800;

  free(pGreen);
 }
 else if (size16 < size && size16 < size8)
 {
  pOutChannel = rle16_compress(pGreen, size, &cbmHeader.cbmGreenSize);
  cbmHeader.cbmCompression |= 0x00001000;

  free(pGreen);
 }
 else
 {
  cbmHeader.cbmGreenSize = size;
  pOutChannel = pGreen;
 }
 pGreen = pOutChannel;



 size8 = rle8_estimate(pBlue, size);
 size16 = rle16_estimate(pBlue, size);
 if (size8 < size && size8 < size16)
 {
  pOutChannel = rle8_compress(pBlue, size, &cbmHeader.cbmBlueSize);
  cbmHeader.cbmCompression |= 0x00000008;

  free(pBlue);
 }
 else if (size16 < size && size16 < size8)
 {
  pOutChannel = rle16_compress(pBlue, size, &cbmHeader.cbmBlueSize);
  cbmHeader.cbmCompression |= 0x00000010;

  free(pBlue);
 }
 else
 {
  cbmHeader.cbmBlueSize = size;
  pOutChannel = pBlue;
 }
 pBlue = pOutChannel;




 hFile = CreateFileW(pBmaFile, GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, 0, 0);
 WriteFile(hFile, &cbmHeader, sizeof(struct CBMHeader), &w, 0);
 WriteFile(hFile, pAlpha, cbmHeader.cbmAlphaSize, &w, 0);
 WriteFile(hFile, pRed, cbmHeader.cbmRedSize, &w, 0);
 WriteFile(hFile, pGreen, cbmHeader.cbmGreenSize, &w, 0);
 WriteFile(hFile, pBlue, cbmHeader.cbmBlueSize, &w, 0);
 CloseHandle(hFile);


 free(pAlpha);
 free(pRed);
 free(pGreen);
 free(pBlue);
 return 0;
}


extern "C" unsigned long Tga2CbmA(const char *pFile)
{
 wchar_t pFilepath[256];

 wsprintfW(pFilepath, L"%S", pFile);
 return Tga2CbmW(pFilepath);
}