#include "c18.h"
#include "_lod.h"
#include "defs.h"
#include "mm7_unparsed_data.h"
//#include "mm7_unparsed_functions.h"


extern class cTexture pending_texture;
extern void *hStdHandle;
void cTexture::cTexture_Load(const wchar_t *pPath)
{
 DWORD w;
 unsigned int uWidth,
              uHeight;
 if (LoadPNG(pPath, &uWidth, &uHeight, &pTruecolorPixels))
  {
    if (!hStdHandle)
      hStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    wchar_t pFileNotFound[256];
    wsprintfW(pFileNotFound, L"Texture not found: %s\n", pPath);
    WriteConsoleW(hStdHandle, pFileNotFound, lstrlenW(pFileNotFound), &w, 0);

    if (!pending_texture.pTruecolorPixels)
      pending_texture.pTruecolorPixels = NamedMemAlloc(unsigned int, 52 * 53, "Pending Texture pixels");
    pending_texture.uTextureWidth = 52;
    pending_texture.uTextureHeight = 53;
    return;
 }
 uTextureWidth = uWidth;
 uTextureHeight = uHeight;
}





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
		MemFree(pSomeSpriteData);
		MemFree(ptr_000024);
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
		MemFree(pSomeSpriteData);
		MemFree(ptr_000024);
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
 
 // runtime_warning(no no more implace deleting);
 // runtime_warning( this thing CRUSHES);
 
  
  if ( cTxtr )
  {
    cTxtr->sContainerName[0] = 0;
    if (!(cTxtr->word_00002C&0x400) )
    {
      MemFree( (void *)cTxtr->pIndexedPixels);
      MemFree( (void *)cTxtr->pPalette);
      MemFree( (void *)cTxtr->ptr_000044);
	  if  (cTxtr->pTruecolorPixels)		// new
		  MemFree(cTxtr->pTruecolorPixels);	 //
    }
	cTxtr->uSizeOfMaxLevelOfDetal = 0;
	cTxtr->pTruecolorPixels	= NULL;	  //new
    cTxtr->pIndexedPixels = NULL;
	cTxtr->pLevelOfDetal1 = NULL;
	cTxtr->pLevelOfDetal2 = NULL;
	cTxtr->pLevelOfDetal3 = NULL;
    cTxtr->pPalette = NULL;
    cTxtr->ptr_000044 = NULL;
    cTxtr->uTextureSize = 0;
    cTxtr->uTextureWidth = 0;
    cTxtr->uTextureHeight = 0;
    cTxtr->word_00001C = 0;
    cTxtr->word_00001E = 0;
    cTxtr->word_000024 = 0;
    cTxtr->word_000026 = 0;
    cTxtr->word_00002C = 0;
  }
}


//----- (0040F806) --------------------------------------------------------
int cTexture_UnzipPalette(cTexture *_this)
{
  int v2; // esi@1
  int v3; // edi@1
  int v4; // [sp+0h] [bp-4h]@1

  v4 = (int)_this;
  v2 = (int)_this;
  v3 = (int)MemAlloc(char, _this->uDecompressedSize);
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
 pPixels = nullptr; //24

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
		pDecompressedBuffer = MemAlloc(unsigned char, cTexture_obj.uTextureSize);
		locked_fread(pDecompressedBuffer, 1, cTexture_obj.uTextureSize, texture_file);
		}
	else
    {
		pCompressedBuffer = NamedMemAlloc(unsigned char, cTexture_obj.uTextureSize, "PCX loading tmp");
		pDecompressedBuffer = MemAlloc(unsigned char, cTexture_obj.uDecompressedSize);

		locked_fread(pCompressedBuffer, 1, cTexture_obj.uTextureSize, texture_file);
		MemUnzip(pDecompressedBuffer, &cTexture_obj.uDecompressedSize, pCompressedBuffer, cTexture_obj.uTextureSize);
		MemFree(pCompressedBuffer);
		cTexture_obj.uTextureSize = cTexture_obj.uDecompressedSize;
    }
	memcpy(&psx_head1,pDecompressedBuffer,16);
	memcpy(&color_map,pDecompressedBuffer+16,48);
	memcpy(&psx_head2,pDecompressedBuffer+64,6);
	if (psx_head1.bpp!=8)
		{
		MemFree(pDecompressedBuffer);
		return 3; 
		}

	uWidth=psx_head1.windowRight-psx_head1.windowLeft+1;  // word @ 000014
	uHeight=psx_head1.windowLower-psx_head1.windowUpper+1;  // word @ 000016
	uNumPixels=uWidth*uHeight;		  // dword @ 000010
	if (mode==0)
		{
		if  (pPixels)
			MemFree(pPixels);
		//allocate for ARGB now, not for 16 bit color
		pPixels = NamedMemAlloc(unsigned int, uNumPixels, "32bit PCX image data");
		}
	else if (mode==2)
		{
		//allocate for ARGB now, not for 16 bit color
		pPixels = MemAlloc(unsigned int, (uNumPixels+2));
		word_000020^=1;
		}
	else
		{
		MemFree(pDecompressedBuffer);
		return 2; 
		}
	if  (!pPixels)
		{
		MemFree(pDecompressedBuffer);
		return 2; 
		}
	
	    	
	DecodePCX(pDecompressedBuffer, (unsigned long *)pPixels, uWidth); 
	MemFree(pDecompressedBuffer);
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
		pDecompressedBuffer = MemAlloc(unsigned char, cTexture_obj.uTextureSize);
		locked_fread(pDecompressedBuffer, 1, cTexture_obj.uTextureSize, texture_file);
		}
	else
		{
		pCompressedBuffer = NamedMemAlloc(unsigned char, cTexture_obj.uTextureSize, "PCX reload tmp");
		pDecompressedBuffer = MemAlloc(unsigned char, cTexture_obj.uDecompressedSize);

		locked_fread(pCompressedBuffer, 1, cTexture_obj.uTextureSize, texture_file);
		MemUnzip(pDecompressedBuffer, &cTexture_obj.uDecompressedSize, pCompressedBuffer, cTexture_obj.uTextureSize);
		MemFree(pCompressedBuffer);
		cTexture_obj.uTextureSize = cTexture_obj.uDecompressedSize;
		}
	memcpy(&psx_head1,pDecompressedBuffer,16);
	memcpy(&color_map,pDecompressedBuffer+16,48);
	memcpy(&psx_head2,pDecompressedBuffer+64,6);
	if (psx_head1.bpp!=8)
		{
		MemFree(pDecompressedBuffer);
		return 3; 
		}
	width=psx_head1.windowRight-psx_head1.windowLeft+1;
	height=psx_head1.windowLower-psx_head1.windowUpper+1;
	if (uNumPixels< width*height)
		{
		MemFree(pDecompressedBuffer);
		return -1; 
		}
	uWidth=width;  // word @ 000014 
	uNumPixels=uHeight*width;	// dword @ 000010	 
	uHeight=(short)uNumPixels;  // word @ 000016
	DecodePCX(pDecompressedBuffer, (unsigned long *)pPixels, uWidth);
	MemFree(pDecompressedBuffer);
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

 if (psx_head1.bpp!=8)
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
 if (psx_head2.planes != 3)
 	  return 3;
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


//----- (0040E51F) --------------------------------------------------------

void  cPCXTexture::PCXTexture_Release()
{

	sContainerName[0] = 0;
	if ( (word_000020&1))
    {
		MemFree(pPixels);
    }
	else
		MemFree(pPixels);

	word_000020 = 0;
	pPixels = NULL; //24
	uNumPixels = 0;
	uHeight=0;  // 22 word @ 000016
	uWidth=0;  // 20 word @ 000014
	word_00001A=0;			//26
	word_000018=0;		   //24
}


//----- (0040EAD8) ------------.text:0040EDB9   --------------------------------------------
int cPCXTexture::LoadPCXFromFile(FILE *File, unsigned int mode, bool close_file)
{

  char v22[60]; // [sp+Ch] [bp-90h]@3
  PCXHEADER_1 psx_head1;
  PCXHEADER_2 psx_head2;
	short int width, height;
  BYTE  color_map[48];	// Colormap for 16-color images
  unsigned char test_byte; // edx@3
  unsigned int row_position; // edi@40
  unsigned char value; // cl@63
  char count; // [sp+50h] [bp-Ch]@43
  unsigned short current_line; // [sp+54h] [bp-8h]@38
  unsigned long *dec_position; 
  unsigned long *temp_dec_position; 


  if ( !File )
	  return 1;

  locked_fread(&psx_head1,sizeof(PCXHEADER_1),1,File);


  locked_fread(&color_map,48,1,File);
  locked_fread(&psx_head2,sizeof(PCXHEADER_2),1,File);

  locked_fread(&v22, 58, 1, File);

  if ( psx_head1.bpp != 8 )
	  return 3;

  uWidth = psx_head1.windowRight-psx_head1.windowLeft+1;
  uHeight = psx_head1.windowLower-psx_head1.windowUpper+1;
  uNumPixels = uWidth*uHeight;
  if ( mode == 0 )
	  {
	  if ( pPixels )
		  {
		  MemFree( pPixels);
		  pPixels = NULL;
		  }
	  pPixels = NamedMemAlloc(unsigned int, uNumPixels, sContainerName);

	  }
  else if ( mode == 2  )
	  {
	  //allocate for ARGB now, not for 16 bit color
		pPixels = MemAlloc(unsigned int, (uNumPixels+2));
		word_000020^=1;
	  }
  else
	  return 2;

  if (!pPixels)
	  return 2;

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
  if ( psx_head2.planes == 1 )
	  erroneous_printf("24bit PCX Only!");
  if ( psx_head2.planes == 3 )
	  {
	  current_line = 0;
	  dec_position=(unsigned long*)pPixels;
	  if ( uWidth > 0 )
		  {
		  do
			  {
			  temp_dec_position = dec_position;
			  row_position = 0;
			  //decode red line
			  if (psx_head2.bytes_per_line)
				  {
				  do
					  {
					  locked_fread(&test_byte, 1, 1, File);

					  if ((test_byte & 0xC0) == 0xC0)
						  {	 
						  locked_fread(&value, 1, 1, File);
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
				  locked_fread(&test_byte, 1u, 1u, File);
				  if ((test_byte & 0xC0) == 0xC0)
					  {
					  locked_fread(&value, 1, 1, File);
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
				  locked_fread(&test_byte, 1, 1, File);
				  if ((test_byte & 0xC0) ==  0xC0)
					  {
					  locked_fread(&value, 1, 1, File);
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
	  }
	
  if (close_file )
	  fclose(File);

  return 0;
}

//----- (0040E55E) --------------------------------------------------------
signed int __thiscall sub_40E55E(void *Source, unsigned int Filename, unsigned int a3)
{
  char *v3; // esi@1
  signed int result; // eax@2
  char *v5; // eax@3
  int v6; // edx@3
  FILE *v7; // edi@3
  char v8; // cl@4
  int v9; // eax@9
  int v10; // ecx@9
  int v11; // eax@9
  char v12; // zf@9
  int v13; // eax@12
  signed int v14; // ecx@19
  signed int v15; // ecx@24
  int v16; // edi@57
  int v17; // eax@57
  int v18; // ecx@57
  signed int v19; // eax@59
  int v20; // edi@64
  signed int v21; // eax@66
  int v22; // edi@71
  signed int v23; // eax@73
  int v24; // eax@78
  char v25; // [sp+Ch] [bp-54h]@3
  char DstBuf; // [sp+3Ch] [bp-24h]@3
  char v27; // [sp+3Dh] [bp-23h]@3
  char v28; // [sp+3Eh] [bp-22h]@3
  char v29; // [sp+3Fh] [bp-21h]@3
  int v30; // [sp+40h] [bp-20h]@3
  int v31; // [sp+44h] [bp-1Ch]@3
  char v32; // [sp+48h] [bp-18h]@3
  char v33; // [sp+4Ah] [bp-16h]@3
  char v34; // [sp+4Ch] [bp-14h]@3
  char v35; // [sp+4Dh] [bp-13h]@3
  unsigned __int16 v36; // [sp+4Eh] [bp-12h]@3
  int v37; // [sp+54h] [bp-Ch]@3
  int v38; // [sp+58h] [bp-8h]@57
  FILE *File; // [sp+5Ch] [bp-4h]@1

  v3 = (char *)Source;
  File = fopen((const char *)Filename, "rb");
  if ( !File )
    return 1;
  v7 = File;
  locked_fread(&DstBuf, 1u, 1u, File);
  locked_fread(&v27, 1u, 1u, v7);
  locked_fread(&v28, 1u, 1u, v7);
  locked_fread(&v29, 1u, 1u, v7);
  locked_fread(&v30, 2, 1u, v7);
  locked_fread((char *)&v30 + 2, 2, 1u, File);
  locked_fread(&v31, 2, 1u, File);
  locked_fread((char *)&v31 + 2, 2, 1u, File);
  locked_fread(&v32, 2, 1u, File);
  locked_fread(&v33, 2, 1u, File);
  locked_fread(&v25, 0x30u, 1u, File);
  locked_fread(&v34, 1u, 1u, File);
  locked_fread(&v35, 1u, 1u, File);
  locked_fread(&v36, 2, 1u, File);
  v5 = (char *)Filename;
  v37 = 0;
  v6 = (int)&v3[-Filename];

  do
  {
    v8 = *v5;
    if ( !*v5 )
      break;
    if ( v8 == 46 )
      break;
    ++v37;
    (v5++)[v6] = v8;
  }
  while ( v37 < 15 );

  v3[v37] = 0;
  if ( v29 != 8 )
    return 3;
  v10 = v31 - v30 + 1;
  v11 = *(int *)((char *)&v31 + 2) - *(int *)((char *)&v30 + 2);
  *((_WORD *)v3 + 10) = v10;
  ++v11;
  *((_WORD *)v3 + 11) = v11;
  v9 = (signed __int16)v10 * (signed __int16)v11;
  v12 = a3 == 0;
  *((_DWORD *)v3 + 4) = v9;
  if ( v12 )
  {
    if ( *((_DWORD *)v3 + 9) )
      MemFree( (void *)*((_DWORD *)v3 + 9));
    v13 = (int)NamedMemAlloc(char, 2 * *((_DWORD *)v3 + 4) + 4, v3);
    goto LABEL_16;
  }
  if ( a3 != 1 && a3 == 2 )
  {
    compile_error();//v13 = (int)operator new(4 * v9 + 8);
    *((_DWORD *)v3 + 8) |= 1u;
LABEL_16:
    *((_DWORD *)v3 + 9) = v13;
  }
  if ( *((_DWORD *)v3 + 9) )
  {
    v14 = 1;
    while ( 1 << v14 != *((_WORD *)v3 + 10) )
    {
      ++v14;
      if ( v14 >= 15 )
        goto LABEL_24;
    }
    *((_WORD *)v3 + 12) = v14;
LABEL_24:
    v15 = 1;
    while ( 1 << v15 != *((_WORD *)v3 + 11) )
    {
      ++v15;
      if ( v15 >= 15 )
        goto LABEL_29;
    }
    *((_WORD *)v3 + 13) = v15;
LABEL_29:
    switch ( *((_WORD *)v3 + 12) )
    {
      case 2:
        *((_WORD *)v3 + 14) = 3;
        break;
      case 3:
        *((_WORD *)v3 + 14) = 7;
        break;
      case 4:
        *((_WORD *)v3 + 14) = 15;
        break;
      case 5:
        *((_WORD *)v3 + 14) = 31;
        break;
      case 6:
        *((_WORD *)v3 + 14) = 63;
        break;
      case 7:
        *((_WORD *)v3 + 14) = 127;
        break;
      case 8:
        *((_WORD *)v3 + 14) = 255;
        break;
      case 9:
        *((_WORD *)v3 + 14) = 511;
        break;
      case 10:
        *((_WORD *)v3 + 14) = 1023;
        break;
      case 11:
        *((_WORD *)v3 + 14) = 2047;
        break;
      case 12:
        *((_WORD *)v3 + 14) = 4095;
        break;
      default:
        break;
    }
    switch ( *((_WORD *)v3 + 13) )
    {
      case 2:
        *((_WORD *)v3 + 15) = 3;
        break;
      case 3:
        *((_WORD *)v3 + 15) = 7;
        break;
      case 4:
        *((_WORD *)v3 + 15) = 15;
        break;
      case 5:
        *((_WORD *)v3 + 15) = 31;
        break;
      case 6:
        *((_WORD *)v3 + 15) = 63;
        break;
      case 7:
        *((_WORD *)v3 + 15) = 127;
        break;
      case 8:
        *((_WORD *)v3 + 15) = 255;
        break;
      case 9:
        *((_WORD *)v3 + 15) = 511;
        break;
      case 10:
        *((_WORD *)v3 + 15) = 1023;
        break;
      case 11:
        *((_WORD *)v3 + 15) = 2047;
        break;
      case 12:
        *((_WORD *)v3 + 15) = 4095;
        break;
      default:
        break;
    }
    fseek(File, 128, 0);
    ftell(File);
    if ( v35 == 1 )
      erroneous_printf("24bit PCX Only!");
    if ( v35 == 3 )
    {
      v37 = 0;
      if ( *((_WORD *)v3 + 11) > 0 )
      {
        do
        {
          v17 = v37 * *((_WORD *)v3 + 10);
          v18 = *((_DWORD *)v3 + 9);
          v38 = 0;
          v16 = v18 + 2 * v17;
          if ( v36 )
          {
            do
            {
              locked_fread((char *)&Filename + 3, 1u, 1u, File);
              if ( (BYTE3(Filename) & 0xC0) == -64 )
              {
                BYTE3(Filename) &= 0x3Fu;
                locked_fread((char *)&a3 + 3, 1u, 1u, File);
                v19 = 0;
                if ( BYTE3(Filename) )
                {
                  do
                  {
                    ++v38;
                    *(_WORD *)v16 = pD3DRenderer->uTargetRMask & (BYTE3(a3) << (pD3DRenderer->uNumTargetGBits
                                                                + (_BYTE)pD3DRenderer->uNumTargetRBits
                                                                + (_BYTE)pD3DRenderer->uNumTargetBBits
                                                                - 8));
                    v16 += 2;
                    ++v19;
                  }
                  while ( v19 < BYTE3(Filename) );
                }
              }
              else
              {
                ++v38;
                *(_WORD *)v16 = pD3DRenderer->uTargetRMask & (BYTE3(Filename) << (pD3DRenderer->uNumTargetGBits
                                                                  + (_BYTE)pD3DRenderer->uNumTargetRBits
                                                                  + (_BYTE)pD3DRenderer->uNumTargetBBits
                                                                  - 8));
                v16 += 2;
              }
            }
            while ( v38 < v36 );
          }
          v20 = *((_DWORD *)v3 + 9) + 2 * v37 * *((_WORD *)v3 + 10);
          while ( v38 < 2 * v36 )
          {
            locked_fread((char *)&Filename + 3, 1u, 1u, File);
            if ( (BYTE3(Filename) & 0xC0) == -64 )
            {
              BYTE3(Filename) &= 0x3Fu;
              locked_fread((char *)&a3 + 3, 1u, 1u, File);
              v21 = 0;
              if ( BYTE3(Filename) )
              {
                do
                {
                  *(_WORD *)v20 |= (_WORD)pD3DRenderer->uTargetGMask & (unsigned __int16)(BYTE3(a3) << (pD3DRenderer->uNumTargetGBits
                                                                                        + (_BYTE)pD3DRenderer->uNumTargetBBits
                                                                                        - 8));
                  ++v38;
                  v20 += 2;
                  ++v21;
                }
                while ( v21 < BYTE3(Filename) );
              }
            }
            else
            {
              *(_WORD *)v20 |= (_WORD)pD3DRenderer->uTargetGMask & (unsigned __int16)(BYTE3(Filename) << (pD3DRenderer->uNumTargetGBits
                                                                                          + (_BYTE)pD3DRenderer->uNumTargetBBits
                                                                                          - 8));
              ++v38;
              v20 += 2;
            }
          }
          v22 = *((_DWORD *)v3 + 9) + 2 * v37 * *((_WORD *)v3 + 10);
          while ( v38 < 3 * v36 )
          {
            locked_fread((char *)&Filename + 3, 1u, 1u, File);
            if ( (BYTE3(Filename) & 0xC0) == -64 )
            {
              BYTE3(Filename) &= 0x3Fu;
              locked_fread((char *)&a3 + 3, 1u, 1u, File);
              v23 = 0;
              if ( BYTE3(Filename) )
              {
                do
                {
                  *(_WORD *)v22 |= BYTE3(a3) >> (8 - pD3DRenderer->uNumTargetBBits);
                  ++v38;
                  v22 += 2;
                  ++v23;
                }
                while ( v23 < BYTE3(Filename) );
              }
            }
            else
            {
              *(_WORD *)v22 |= BYTE3(Filename) >> (8 - pD3DRenderer->uNumTargetBBits);
              ++v38;
              v22 += 2;
            }
          }
          v24 = *((_WORD *)v3 + 11);
          ++v37;
        }
        while ( v37 < v24 );
      }
    }
    fclose(File);
    result = 0;
  }
  else
  {
    result = 2;
  }
  return result;
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

