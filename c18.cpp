#include "c18.h"
#include "_lod.h"
#include "defs.h"
#include "mm7_unparsed_data.h"
//#include "mm7_unparsed_functions.h"

typedef struct tagPCXHEADER_1 {
	BYTE  manufacturer;		// Magic number (0x0A = ZSoft Z)
	BYTE  version;			// Version	0 == 2.5
							//          2 == 2.8 with palette info
							//          3 == 2.8 without palette info
							//          5 == 3.0 with palette info
	BYTE  encoding;			// Encoding: 0 = uncompressed, 1 = PCX rle compressed
	BYTE  bpp;				// Bits per pixel per plane (only 1 or 8)
	WORD  windowLeft;		// left, 
	WORD  windowUpper;       //upper, 
	WORD  windowRight;        //right,
	WORD  windowLower;        //lower pixel coord.
	WORD  hdpi;				// Horizontal resolution
	WORD  vdpi;				// Vertical resolution
	}  PCXHEADER_1;

typedef struct tagPCXHEADER_2 {
	BYTE  reserved;
	BYTE  planes;			// Number of planes (1, 3 or 4)
	WORD  bytes_per_line;	// Bytes per row (always even)
	WORD  palette_info;		// Palette information (1 = color or b&w; 2 = gray scale)

	}PCXHEADER_2;

//--------------------------------------  .text:00463766   sprite_header_constr

Sprites_Header::Sprites_Header()
	{

	uSomeSprtDataCount=0; // * 8 for sprite size                      
	uPaletteID=0; // dword @ 000014
	short_001A=0;
	pSomeSpriteData=NULL;
	ptr_000024=NULL; 

	}
//---------------------------------------------.text:0046377D     
Sprites_Header::~Sprites_Header()
	{
	if  (!(c0001B&4==0))
		{
		mem_mng.DeleteBuffer(pSomeSpriteData);
		mem_mng.DeleteBuffer(ptr_000024);
		}
	pSomeSpriteData=NULL;
	ptr_000024=NULL;
	}


//----- (00450D1D) --sub_450D1D--------.text:00451E32  ----------------------------------------------
void Sprites_Header::Clear_Data()
{
  int v1; // esi@1
  int result; // eax@3

  if  (!(c0001B&4==0))
		{
		mem_mng.DeleteBuffer(pSomeSpriteData);
		mem_mng.DeleteBuffer(ptr_000024);
		}
	pSomeSpriteData=NULL;
	ptr_000024=NULL;
	sContainerName[0]=0;
	dSpriteSize=0;
    word_000010=0;
	uSomeSprtDataCount=0; // * 8 for sprite size
	short_0016=0;
	uTextureWidth=0;
	uPaletteID=0; // dword @ 000014
	short_001A=0;

}


//----- (MM7.exe::0040F5BE) ----.text:0040F8B0  ----------------------------------------------------
void cTexture::cTexture_Zero()
{
	sContainerName[0] = 0;
	uSizeOfMaxLevelOfDetal = 0;
	uTextureSize = 0; 
	uTextureWidth = 0;
	uTextureHeight = 0;
	word_00001C = 0;
	word_00001E = 0;

	word_000024 = 0;
	word_000026 = 0;

	pIndexedPixels = NULL;
	pLevelOfDetal1 = NULL;
	pLevelOfDetal2 = NULL;
	pLevelOfDetal3 = NULL;
	pPalette = NULL;
	ptr_000044 = NULL;
	pTruecolorPixels=NULL;
}

  //----- (0040F77C) ---------text:0040FA6E-----------------------------------------------
void cTexture_Free(cTexture* cTxtr)
{
  //int v1; // esi@1
  char v2; // zf@2

  runtime_warning(no no more implace deleting);
  runtime_warning( this thing CRUSHES);
 
  /*
  if ( cTxtr )
  {
    cTxtr->sContainerName[0] = 0;
    if (!(cTxtr->word_00002C&0x400) )
    {
      mem_mng.DeleteBuffer( (void *)cTxtr->pIndexedPixels);
      mem_mng.DeleteBuffer( (void *)cTxtr->pPalette);
      mem_mng.DeleteBuffer( (void *)cTxtr->ptr_000044);
    }
	cTxtr->uSizeOfMaxLevelOfDetal = 0;
    cTxtr->pIndexedPixels = NULL;
	cTxtr->pLevelOfDetal1 = NULL;
	cTxtr->pLevelOfDetal2 = NULL;
	cTxtr->pLevelOfDetal3 = NULL;
    cTxtr->pPalette = NULL;
    cTxtr->ptr_000044 = NULL;
    cTxtr->uCompressedSize = 0;
    cTxtr->uTextureWidth = 0;
    cTxtr->uTextureHeight = 0;
    cTxtr->word_00001C = 0;
    cTxtr->word_00001E = 0;
    cTxtr->word_000024 = 0;
    cTxtr->word_000026 = 0;
    cTxtr->word_00002C = 0;
  }*/
}


//----- (0040F806) --------------------------------------------------------
int cTexture_UnzipPalette(cTexture *_this)
{
  int v2; // esi@1
  int v3; // edi@1
  int v4; // [sp+0h] [bp-4h]@1

  v4 = (int)_this;
  v2 = (int)_this;
  v3 = (int)malloc(_this->uDecompressedSize);
  MemUnzip((void *)v3, (unsigned int *)&v4, _this->pIndexedPixels, *(_DWORD *)(v2 + 20));
  return v3;
}

//----- (0040D73D) --------------------------------------------------------
void cPCXTexture::PCXTexture_Zero()
{
 sContainerName[0] = 0;
 uNumPixels = 0;
 word_000020 = 0;
 word_000022 = 0;
 pPixels = NULL; //24

}
///------ (MM7.exe::0040F414) -------------.text:0040F703------------------- 
int cPCXTexture::LODPCXLoad(const char *pContainerName, int mode)
	{
	cTexture cTexture_obj;
	FILE *texture_file;
	PCXHEADER_1 psx_head1;
	PCXHEADER_2 psx_head2;
	BYTE  color_map[48];	// Colormap for 16-color images
	unsigned char *pCompressedBuffer,
		*pDecompressedBuffer; 

	cTexture_obj.cTexture_Zero();
	texture_file = LODFile_Icons_LOD.Find_Container(pContainerName, 0);
	if (!texture_file)
		{
		erroneous_printf("Unable to load %s", pContainerName);
		return 2;
		}

	locked_fread(&cTexture_obj, 1,48, texture_file);
	if (!cTexture_obj.uDecompressedSize)
		{
		pDecompressedBuffer = (unsigned char *)malloc(cTexture_obj.uTextureSize);
		locked_fread(pDecompressedBuffer, 1, cTexture_obj.uTextureSize, texture_file);
		}
	else
		{
		pCompressedBuffer = (unsigned char *)mem_mng.AllocatedNamedBuffer(NULL,cTexture_obj.uTextureSize,NULL);
		pDecompressedBuffer = (unsigned char *)malloc(cTexture_obj.uDecompressedSize);

		locked_fread(pCompressedBuffer, 1, cTexture_obj.uTextureSize, texture_file);
		MemUnzip(pDecompressedBuffer, &cTexture_obj.uDecompressedSize, pCompressedBuffer, cTexture_obj.uTextureSize);
		mem_mng.DeleteBuffer(pCompressedBuffer);
		cTexture_obj.uTextureSize = cTexture_obj.uDecompressedSize;
		}
	memcpy(&psx_head1,pDecompressedBuffer,16);
	memcpy(&color_map,pDecompressedBuffer+16,48);
	memcpy(&psx_head2,pDecompressedBuffer+64,6);
	if (!psx_head1.bpp==8)
		{
		free(pDecompressedBuffer);
		return 3; 
		}

	uWidth=psx_head1.windowRight-psx_head1.windowLeft+1;  // word @ 000014
	uHeight=psx_head1.windowLower-psx_head1.windowUpper+1;  // word @ 000016
	uNumPixels=uWidth*uHeight;		  // dword @ 000010
	if (mode==0)
		{
		if  (pPixels)
			mem_mng.DeleteBuffer(pPixels);
		//allocate for ARGB now, not for 16 bit color
		pPixels=(unsigned int*)mem_mng.AllocatedNamedBuffer(NULL,(uNumPixels+2)*4,"32bit PCX");
		}
	else if (mode==2)
		{
		//allocate for ARGB now, not for 16 bit color
		pPixels=(unsigned int*)malloc((uNumPixels+2)*4);
		word_000020^=1;
		}
	else
		{
		free(pDecompressedBuffer);
		return 2; 
		}
	if  (!pPixels)
		{
		free(pDecompressedBuffer);
		return 2; 
		}
	
	    	
	DecodePCX(pDecompressedBuffer, (unsigned long *)pPixels, uWidth); 
	free(pDecompressedBuffer);
	return 0;

	}

//----- (0040F5F5) ---------.text:0040F8E7 -----------------------------------------------
int cPCXTexture::LODPCXReLoad(const char *pContainerName)
	{
	cTexture cTexture_obj;
	FILE *texture_file;
	PCXHEADER_1 psx_head1;
	PCXHEADER_2 psx_head2;
	short int width, height;
	BYTE  color_map[48];	// Colormap for 16-color images
	unsigned char *pCompressedBuffer,
		*pDecompressedBuffer;

	if (!pPixels)
		return 2;
	cTexture_obj.cTexture_Zero();

	texture_file = LODFile_Icons_LOD.Find_Container(pContainerName, 0);
	if (!texture_file)
		{
		erroneous_printf("Unable to load %s", pContainerName);
		return 2;
		}

	locked_fread(&cTexture_obj, 1,48, texture_file);
	if (!cTexture_obj.uDecompressedSize)
		{
		pDecompressedBuffer = (unsigned char *)malloc(cTexture_obj.uTextureSize);
		locked_fread(pDecompressedBuffer, 1, cTexture_obj.uTextureSize, texture_file);
		}
	else
		{
		pCompressedBuffer = (unsigned char *)mem_mng.AllocatedNamedBuffer(NULL,cTexture_obj.uTextureSize,NULL);
		pDecompressedBuffer = (unsigned char *)malloc(cTexture_obj.uDecompressedSize);

		locked_fread(pCompressedBuffer, 1, cTexture_obj.uTextureSize, texture_file);
		MemUnzip(pDecompressedBuffer, &cTexture_obj.uDecompressedSize, pCompressedBuffer, cTexture_obj.uTextureSize);
		mem_mng.DeleteBuffer(pCompressedBuffer);
		cTexture_obj.uTextureSize = cTexture_obj.uDecompressedSize;
		}
	memcpy(&psx_head1,pDecompressedBuffer,16);
	memcpy(&color_map,pDecompressedBuffer+16,48);
	memcpy(&psx_head2,pDecompressedBuffer+64,6);
	if (!psx_head1.bpp==8)
		{
		free(pDecompressedBuffer);
		return 3; 
		}
	width=psx_head1.windowRight-psx_head1.windowLeft+1;
	height=psx_head1.windowLower-psx_head1.windowUpper+1;
	if (uNumPixels< width*height)
		{
		free(pDecompressedBuffer);
		return -1; 
		}
	uWidth=width;  // word @ 000014 
	uNumPixels=uHeight*width;	// dword @ 000010	 
	uHeight=(short)uNumPixels;  // word @ 000016
	DecodePCX(pDecompressedBuffer, (unsigned long *)pPixels, uWidth);
	free(pDecompressedBuffer);
	return 0;
	}



//----- (MM7.exe::0040F037) --------------------------------------------------------
int cPCXTexture::DecodePCX( unsigned char *pPCXData, unsigned long *pOutBuffer, unsigned int uWidth)
{
  signed int result; // eax@2
  unsigned char test_byte; // edx@3
  unsigned int read_offset; // ebx@37
  unsigned int row_position; // edi@40
  unsigned char value; // cl@63
  char count; // [sp+50h] [bp-Ch]@43
  unsigned short current_line; // [sp+54h] [bp-8h]@38
  unsigned long *dec_position; 
  unsigned long *temp_dec_position; 
  PCXHEADER_1 psx_head1;
  PCXHEADER_2 psx_head2;
	short int width, height;
	BYTE  color_map[48];	// Colormap for 16-color images

 
 memcpy(&psx_head1,pPCXData,16);
 memcpy(&color_map,pPCXData+16,48);
 memcpy(&psx_head2,pPCXData+64,6);

 if (!psx_head1.bpp==8)
		return 3; 
 uWidth=(short int )(psx_head1.windowRight-psx_head1.windowLeft+1);  // word @ 000014
 uHeight=(short int )(psx_head1.windowLower-psx_head1.windowUpper+1);  // word @ 000016

 uNumPixels=uWidth*uHeight;		  // dword @ 000010
  for (short i=1; i<=15; i++)
	  {
	  if ((1<<i)==uWidth)
		  {
		  word_000018=i;
		  break;
		  }
	  }

  for (short i=1; i<=15; i++)
	  {
	  if ((1<<i)==uHeight)
		  {
		  word_00001A=i;
		  break;
		  }
	  }
  switch (word_000018)
	  {
  case 2:   word_00001C = 3;    break;
  case 3:   word_00001C = 7;    break;
  case 4:   word_00001C = 15;   break;
  case 5:   word_00001C = 31;   break;
  case 6:   word_00001C = 63;   break;
  case 7:   word_00001C = 127;  break;
  case 8:   word_00001C = 255;  break;
  case 9:   word_00001C = 511;  break;
  case 10:  word_00001C = 1023; break;
  case 11:  word_00001C = 2047; break;
  case 12:  word_00001C = 4095; break;
	  }

  switch (word_00001A)
	  {
  case 2:   word_00001E = 3;    break;
  case 3:   word_00001E = 7;    break;
  case 4:   word_00001E = 15;   break;
  case 5:   word_00001E = 31;   break;
  case 6:   word_00001E = 63;   break;
  case 7:   word_00001E = 127;  break;
  case 8:   word_00001E = 255;  break;
  case 9:   word_00001E = 511;  break;
  case 10:  word_00001E = 1023; break;
  case 11:  word_00001E = 2047; break;
  case 12:  word_00001E = 4095; break;
	  }

 
 read_offset = 128;
 if (psx_head2.planes == 3)
 {
  current_line = 0;
  if ( uWidth > 0 )
  {
   dec_position = pOutBuffer;
   do
   {
    temp_dec_position = dec_position;
    row_position = 0;
	//decode red line
    if (psx_head2.bytes_per_line)
    {
     do
     {
      test_byte = *(pPCXData + read_offset);
      ++read_offset;
      if ((test_byte & 0xC0) == 0xC0)
      {	
	    value = *(pPCXData + read_offset);
       	++read_offset; 
      
       if ((test_byte & 0x3F) > 0)
       {
        count = test_byte & 0x3F;
        do
        {

         ++row_position;
          *temp_dec_position =0xFF000000;
		  *temp_dec_position|=(unsigned long)value<<16;
		   temp_dec_position++;
         if (row_position == psx_head2.bytes_per_line)
			 break;
        }
        while (count-- != 1);
       }
      }
      else
      {
       ++row_position;
	   *temp_dec_position =0xFF000000; 
	  *temp_dec_position|= (unsigned long)test_byte<<16;
       temp_dec_position++;
      }
    
     }
     while (row_position < psx_head2.bytes_per_line);
    }
 
    temp_dec_position = dec_position;
	row_position=0;
	//decode green line
    while (row_position <  psx_head2.bytes_per_line)
    {
     test_byte = *(pPCXData + read_offset);
     ++read_offset;
     if ((test_byte & 0xC0) == 0xC0)
     {
      value = *(pPCXData + read_offset);
	  ++read_offset;
      if ((test_byte & 0x3F) > 0)
      {
       count = test_byte & 0x3F;
       do
       {
        *temp_dec_position|= (unsigned int)value<<8;
		temp_dec_position++;
        ++row_position;
        if (row_position == psx_head2.bytes_per_line)
			break;
  
       }
       while (count-- != 1);
      }
     }
     else
     {
      *temp_dec_position |=(unsigned int) test_byte<<8;
	  temp_dec_position++;
      ++row_position;
     }
    }

    temp_dec_position = dec_position;
	row_position=0;
	//decode blue line
    while (row_position < psx_head2.bytes_per_line)
    {
     test_byte = *(pPCXData + read_offset);
	 read_offset++;
     if ((test_byte & 0xC0) ==  0xC0)
     {
       value = *(pPCXData + read_offset);
	  ++read_offset;
      if ((test_byte & 0x3F) > 0)
      {
       count = test_byte & 0x3F;
       do
       {
        *temp_dec_position|= value;
		 temp_dec_position++;
        ++row_position;
        if (row_position == psx_head2.bytes_per_line)
		 break;
       }
       while (count-- != 1);
      }
     }
     else
     {
      *temp_dec_position|= test_byte;
	   temp_dec_position++;
      ++row_position;
     }
     
    }
    ++current_line;
    dec_position += uWidth;
   }
   while (current_line < uHeight);
  }
   return 0;
 }
 else
   return 3;
}


//----- (0040E51F) --------------------------------------------------------

void  cPCXTexture::PCXTexture_Release()
{

	sContainerName[0] = 0;
	if ( (word_000020&1))
		free(pPixels);
	else
		mem_mng.DeleteBuffer( pPixels);
	word_000020 = 0;
	pPixels = NULL; //24
	uNumPixels = 0;
	uHeight=0;  // 22 word @ 000016
	uWidth=0;  // 20 word @ 000014
	word_00001A=0;			//26
	word_000018=0;		   //24
}


#ifndef OLD_CODE
int RGBTexture_Load_New( cPCXTexture *_this, const wchar_t *pTextureName)
{
 unsigned int uTextureID;

 uTextureID = LODFile_Icons_LOD.LODFile_LoadTexture_New( pTextureName);

 _this->pPixels = LODFile_Icons_LOD.aLODHeaders[uTextureID].pTruecolorPixels;
 _this->uWidth = LODFile_Icons_LOD.aLODHeaders[uTextureID].uTextureWidth;
 _this->uHeight = LODFile_Icons_LOD.aLODHeaders[uTextureID].uTextureHeight;
 _this->uNumPixels = _this->uWidth * _this->uHeight;

 return 0;
}
#endif


#ifndef OLD_CODE
//----- (MM7.exe::0040F414) --------------------------------------------------------
int RGBTexture_Load(cPCXTexture *_this, const char *pContainerName, int a3)
{
  

 wchar_t      pFilepath[256];

 wsprintfW(pFilepath, L"%S", pContainerName);

 return RGBTexture_Load_New(_this, pFilepath);


}
#endif

