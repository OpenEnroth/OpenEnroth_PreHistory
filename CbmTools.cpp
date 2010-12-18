#include <stdio.h>
#include <windows.h>

#include "libs\libpng143\png.h"

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



void SaveHeighmap(const wchar_t *pFile, unsigned char *pBits)
{
 DWORD  w;
 void  *hFile = CreateFileW(pFile, GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, 0, 0);
 if (hFile == INVALID_HANDLE_VALUE)
   return;

 struct TGAHeader tgaHeader =
 {
  0, 0,
  2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  128, 128, 32, 0
 };

 int ppixels[128 * 128];
 for (int i = 0; i < 128 * 128; ++i)
   ppixels[i] = 0xFF000000 | (unsigned int)(pBits[i] * 3) | ((unsigned int)(pBits[i] * 3) << 8) | ((unsigned int)(pBits[i] * 3) << 16);

 WriteFile(hFile, &tgaHeader, sizeof(struct TGAHeader), &w, 0);
 WriteFile(hFile, ppixels, 128 * 128 * 4, &w, 0);
 CloseHandle(hFile);
 //SetFilePointer(hFile, tgaHeader.tgaSkip, 0, FILE_CURRENT);
 /*
 if (tgaHeader.tgaBPP != 32)
 {
  MessageBoxW(0, L"Invalid Targa format", L"LoadTGA", 0);

  CloseHandle(hFile);
  return 1;
 }

 *pWidth = tgaHeader.tgaWidth;
 *pHeight = tgaHeader.tgaHeight;
 *pPixels = new unsigned int[*pWidth * *pHeight];

 ReadFile(hFile, *pPixels, *pWidth * *pHeight * sizeof(__int32), &w, 0);
 CloseHandle(hFile);*/
}


unsigned int LoadTGA(const wchar_t *pFile, unsigned int *pWidth, unsigned int *pHeight, unsigned int **pPixels)
{
 DWORD  w;
 void  *hFile = CreateFileW(pFile, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
 if (hFile == INVALID_HANDLE_VALUE)
   return 1;

 struct TGAHeader tgaHeader;
 ReadFile(hFile, &tgaHeader, sizeof(struct TGAHeader), &w, 0);
 SetFilePointer(hFile, tgaHeader.tgaSkip, 0, FILE_CURRENT);

 if (tgaHeader.tgaBPP != 32)
 {
  MessageBoxW(0, L"Invalid Targa format", L"LoadTGA", 0);

  CloseHandle(hFile);
  return 1;
 }

 *pWidth = tgaHeader.tgaWidth;
 *pHeight = tgaHeader.tgaHeight;
 *pPixels = new unsigned int[*pWidth * *pHeight];

 ReadFile(hFile, *pPixels, *pWidth * *pHeight * sizeof(__int32), &w, 0);
 CloseHandle(hFile);

 return 0;
}




unsigned int LoadPNG(const wchar_t *pFile, unsigned int *pWidth, unsigned int *pHeight, unsigned int **pPixels)
{
 png_structp png_ptr;
 png_infop info_ptr;
 png_uint_32 width, height;
 int bit_depth, color_type, interlace_type;
 png_voidp user_error_ptr;
 FILE *fp;

 if (!(fp = _wfopen(pFile, L"rb")))
   return 1;

 png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);

 if (!png_ptr)
 {
  fclose(fp);
  return 1;
 }

   /* Allocate/initialize the memory for image information.  REQUIRED. */
 info_ptr = png_create_info_struct(png_ptr);
 if (!info_ptr)
 {
  fclose(fp);
  png_destroy_read_struct(&png_ptr, 0, 0);
  return 1;
 }

   /* Set error handling if you are using the setjmp/longjmp method (this is
    * the normal method of doing things with libpng).  REQUIRED unless you
    * set up your own error handlers in the png_create_read_struct() earlier.
    */
 if (setjmp(png_jmpbuf(png_ptr)))
 {
  png_destroy_read_struct(&png_ptr, &info_ptr, 0);
  fclose(fp);
  return 1;
 }

 png_init_io(png_ptr, fp);


   /*
    * If you have enough memory to read in the entire image at once,
    * and you need to specify only transforms that can be controlled
    * with one of the PNG_TRANSFORM_* bits (this presently excludes
    * quantizing, filling, setting background, and doing gamma
    * adjustment), then you can read the entire image (including
    * pixels) into the info structure with this call:
    */
 png_read_png(png_ptr, info_ptr, 0, 0);

 if (info_ptr->channels != 4)
 {
  wchar_t pErrorMsg[256];
  wsprintfW(pErrorMsg, L"\"%s\": Invalid PNG format [4-channel ARGB PNG required]", pFile);
  MessageBoxW(0, pErrorMsg, L"LoadPNG", 0);
  return 1;
 }


 *pWidth = info_ptr->width;
 *pHeight = info_ptr->height;

 *pPixels = new unsigned int[info_ptr->width * info_ptr->height];
 for (unsigned int i = 0; i < info_ptr->height; ++i)
 {
  unsigned int *pRow = *pPixels + i * info_ptr->width;

  memcpy(pRow, info_ptr->row_pointers[i], info_ptr->width * sizeof(__int32));
  for (unsigned int x = 0; x < info_ptr->width; ++x)
  {
   unsigned int abgr = pRow[x];
   pRow[x] = (abgr & 0xFF00FF00) | ((abgr & 0x00FF0000) >> 16) | ((abgr & 0x000000FF) << 16);
  }
 }


 
   /* Clean up after the read, and free any memory allocated - REQUIRED */
 png_destroy_read_struct(&png_ptr, &info_ptr, 0);

 fclose(fp);
 return 0;
}


unsigned int LoadCBM(const wchar_t *pFile, unsigned int *pWidth, unsigned int *pHeight, unsigned int **ppPixels)
{
 DWORD  w;
 void  *hFile = CreateFileW(pFile, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
 if (hFile == INVALID_HANDLE_VALUE)
   return 1;

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
 return 0;
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
