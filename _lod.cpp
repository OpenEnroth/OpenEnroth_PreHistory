#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "defs.h"
#include "RenderD3D3.h"
#include "AIL.h"
#include "Smacker.h"
#include "Level.h"
#include "FrameTables.h"
 #include "_lod.h"
#include "data.h"

cTexture pending_texture;
void *hStdHandle = 0;




//static int st_dword_6A0CA4; // weak	dword_6A0CA4;
//-----------------------------.text:0046358C----------------
 
LODFile_IB::LODFile_IB()
{

	 for (int i=0; i<1000; i++)
		 cTexture_Zero(&aLODHeaders[i]);
	 uNumLoadedFiles=0;
	 lod_IB_dword_011B80=0;//
	 lod_IB_dword_011B84=0; //

	 lod_IB_dword_011B98=0; //
	 lod_IB_dword_011B9C=0; //

	 lod_IB_dword_011BA4=0; //
	 lod_IB_dword_011BA8=0; //
	 pHardwareSurfaces=NULL;
	 pHardwareTextures=NULL;
	 lod_IB_dword_011BB4=NULL;
	 
}
 //-------------------------------------------.text:0046361D------
 LODFile_IB::~LODFile_IB()
{

	 for (int i=0; i<uNumLoadedFiles; i++)
		 {
		 cTexture_Free(&aLODHeaders[i]);
		 if (pHardwareSurfaces)
			 if	 (pHardwareSurfaces[i])
				 {
				 pHardwareSurfaces[i]->Release();
				 pHardwareSurfaces[i]=NULL;
				 }
		 if (pHardwareTextures)
			 if	 (pHardwareTextures[i])
				 {
				 pHardwareTextures[i]->Release();
				 pHardwareTextures[i]=NULL;
				 }
		 }
	 if (pHardwareSurfaces)
		 delete(pHardwareSurfaces);
	 if (pHardwareTextures)
		 delete(pHardwareTextures);
	 if (lod_IB_dword_011BB4)
		 delete(lod_IB_dword_011BB4);

}


 LODFile_Sprite::LODFile_Sprite()
{
 

}
 //-------------------------------------------.text:0046361D------
 //----- (0046249B) -----destructor---------------------------------------------------
 /*
int __thiscall sub_46249B(int _this)
{
  int v1; // ebx@1
  int v2; // esi@1
  int v3; // edi@3
  int v4; // edi@6
  int v6; // [sp+4h] [bp-10h]@3
  int v7; // [sp+4h] [bp-10h]@7

  v2 = _this;
  v1 = 0;
  if ( *(_DWORD *)(_this + 60592) )
  {
    if ( *(_DWORD *)(_this + 60572) > 0 )
    {
      v6 = 0;
      v3 = _this + 572;
      do
      {
        sub_450D1D((Sprites_Header*)v3);
        sub_450D68((HardwareSprite *)(v6 + *(_DWORD *)(v2 + 60592)));
        v6 += 40;
        ++v1;
        v3 += 40;
      }
      while ( v1 < *(_DWORD *)(v2 + 60572) );
    }
  }
  else
  {
    v4 = _this + 60572;
    if ( *(_DWORD *)(_this + 60572) > 0 )
    {
      v7 = _this + 572;
      do
      {
        sub_450D1D((Sprites_Header*)v7);
        v7 += 40;
        ++v1;
      }
      while ( v1 < *(_DWORD *)v4 );
    }
  }
  _eh_vector_destructor_iterator_(v2 + 572, 40, 1500, (void (__fastcall *)(void *))sub_462463);
  return 0;
}
 */
 LODFile_Sprite::~LODFile_Sprite()
{
 

}


 //----- (0046175B) ------.text:00462A5E--------------------------------------------------
LOD_file::LOD_file()
{
  Reset_LODFileHeader(&sLODFileHeader);
  pLODFile = NULL;
  pLODSubIndexNamedBuffer = NULL;
  file_opened=false;
  pLODIOBuffer=NULL;  
  uIOBufferSize=0; 
  Close_Open_File();
}



 //----- (00461790) ----------.text:00462A93 ----------------------------------------------
LOD_file::~LOD_file()
{
  
  if ( sLODFileHeader.Signature )
  {
    fclose(pLODFile);
    mem_mng.DeleteBuffer(pLODSubIndexNamedBuffer);
  }
 
}

 //----- (004617B6) ----.text:00462AB9----------------------------------------------------
void Reset_LODFileHeader(LODFileHeader *p_hdr)
{
   p_hdr->Signature[0]=0;     // dword @ 000000    "LOD\0"
   p_hdr->a1[0]=0;		  //  byte   000004
   p_hdr->a2[0]=0;		  //  byte   000054
   p_hdr->dword00A4=0;        // dword @ 0000A4
   p_hdr->dword00A8=0;        // dword @ 0000A8
   p_hdr->uNumIndexDirs=0;        // dword @ 0000AC

}

//----- (0046172B) ---------.text:00462A2E-----------------------------------------------
void Reset_LODIndex(LODIndex *pLIndx)
{
 pLIndx->pFilename[0]=0;
 pLIndx->offset_from_unit_start=0;
 pLIndx->size_data=0;
 pLIndx->reserved1=0;
 pLIndx->uSubIndixes=0;
 pLIndx->reserved3=0;  
}


//----- (00461743) --------------------------------------------------------
/*	  same_as above
int __thiscall sub_461743(int _this)
{
  int result; // eax@1

  result = _this;
  *(_BYTE *)_this = 0;
  *(_DWORD *)(_this + 16) = 0;
  *(_DWORD *)(_this + 20) = 0;
  *(_DWORD *)(_this + 24) = 0;
  *(_WORD *)(_this + 28) = 0;
  *(_WORD *)(_this + 30) = 0;
  return result;
}
 */

//----- (00461431) ----------.text:00462734----------------------------------------------
void LOD_file::Close_Open_File()
{
 
  if (  file_opened )
  {
    sContainerName[0] = 0;	// 214
    current_index_dir = 0;  // 224
    mem_mng.DeleteBuffer( pLODSubIndexNamedBuffer);	  //230
    mem_mng.DeleteBuffer(pLODCArray); //210
    pLODSubIndexNamedBuffer = NULL;
    pLODCArray = NULL;
    fclose(pLODFile);
    file_opened = false;
    global_dword_6A0CA8 = 0;
  }

}



//----- (00461A11) -------------.text:00462D14 -------------------------------------------
void LOD_file::FreeSubIndxIOBuffers()
{ 
  mem_mng.DeleteBuffer( pLODSubIndexNamedBuffer);
  mem_mng.DeleteBuffer( pLODIOBuffer);
  pLODIOBuffer = NULL;
  pLODSubIndexNamedBuffer =NULL;
}

  //----- (0046161C) -----.text:0046291F------LODFile_Games_LOD_FindLeveL---------------------------------------------
bool LOD_file::IsContainerExist(const char *pContainerName)
{
  int index; // ebx@1

  index = 0;
  if (!uNumSubidices)
    return false;

  while (stricmp(pContainerName, (char *)pLODSubIndexNamedBuffer[index++].pFilename))
  {
   if ( index >= uNumSubidices)
     return false;
  }
 return true;
}



	//int __stdcall sub_462C57(int, size_t Size)
//----- (00461954) -------.text:00462C57--------------------- LODFile_AllocateSubidexAndIOBuffer----------------------------
void LOD_file::AllocateSubidexAndIOBuffer(unsigned int uNumSubInd, unsigned int uIOBuffSize)
{
if (pLODSubIndexNamedBuffer)
	{
	MessageBoxW(0, L"Attempt to reset a LOD subindex!", L"MM7", 0x30u);
	mem_mng.DeleteBuffer(pLODSubIndexNamedBuffer);
	pLODSubIndexNamedBuffer = NULL;
	}
pLODSubIndexNamedBuffer =
	(LODIndex *)mem_mng.AllocatedNamedBuffer(pLODSubIndexNamedBuffer, sizeof(LODIndex) * uNumSubInd, "LODsubindex");

if (pLODIOBuffer)
	{
	MessageBoxW(0, L"Attempt to reset a LOD IObuffer!", L"MM7", 0x30u);
	mem_mng.DeleteBuffer(pLODIOBuffer);
	pLODIOBuffer = NULL;
	uIOBufferSize = 0;
	}
if (uIOBuffSize)
	{
	pLODIOBuffer = (unsigned char *)mem_mng.AllocatedNamedBuffer(pLODIOBuffer, uIOBuffSize, "LODio");
	uIOBufferSize = uIOBuffSize;
	}
}


 //----- (MM7.exe::00461580) ---------.text:00462882  --------------------------LODFile_FindContainer---------------------
FILE *LOD_file::Find_Container(const char *pContainerName, bool linearSearch)
{
  unsigned int offset_to_record_data; // eax@4
  int container_index; // edi@5
 
  container_index=0;

  if (!file_opened)
	  return NULL;
  if (linearSearch)
	  {
	  if (!uNumSubidices)
		  return NULL;
	  container_index=-1;
	  while (stricmp(pContainerName, pLODSubIndexNamedBuffer[++container_index].pFilename))
		  {	 
		  if (container_index >= uNumSubidices)
			  return NULL;
		  }	
	  }
  else
	  {
	  container_index=Fast_Calc_Index( 0, uNumSubidices, pContainerName);
	  if ( container_index < 0 )
		  return NULL;
	  }
 
  offset_to_record_data = pLODSubIndexNamedBuffer[container_index].offset_from_unit_start;
  fseek(pLODFile, offset_to_subindex + offset_to_record_data, 0);
  return pLODFile;
}

 //----- (MM7.exe::0046165E) ------.text:00462961 --------------------------------------------------
int LOD_file::Fast_Calc_Index( int startIndex, int maxIndex, const char *pContainerName)
{
  int temp_start_indx; 
  int temp_end_indx;
  int reslt; 
  int search_range; 
  int look_index; 
  //  Binary search  in lod indexes
  temp_start_indx = startIndex;
  temp_end_indx =  maxIndex;
  while(temp_start_indx < temp_end_indx) 
	  {
	  search_range = temp_end_indx - temp_start_indx;
	  look_index=search_range / 2+ temp_start_indx;
	  reslt	= stricmp(pContainerName, (char *)pLODSubIndexNamedBuffer[look_index].pFilename);
	  if (reslt==0 )
		  {
		  return  look_index;
		  }
	  if (reslt<0 ) 
		  temp_end_indx = look_index;
	  else
		  temp_start_indx +=search_range / 2;

	  if ( search_range <= 4 )
		  {
		  while (temp_start_indx<temp_end_indx)
			  {	 
			  if (!(stricmp(pContainerName, pLODSubIndexNamedBuffer[temp_start_indx].pFilename)))
				  {
				  return temp_start_indx;
				  }
			  temp_start_indx++;
			  }
		  }
	  }
  return -1;

}

//----- (MM7.exe::004617D5) ---LODFile_MaybeLoadLODHeader-----------------------------------------------------
bool LOD_file::Load_LODHeader( const char *pFilename, bool openmode)
{
	const char *mode; // [sp-4h] [bp-Ch]@4

	if (file_opened)
		Close_Open_File();
	if (openmode)
		mode = "rb";
	else 
		mode = "rb+";
	fopen_s(&pLODFile, pFilename, mode);
	if (!pLODFile)
		return false;
	strcpy(sLODName, pFilename);
	locked_fread(&sLODFileHeader, sizeof(LODFileHeader), 1, pLODFile);
	pLODCArray =(char*) mem_mng.AllocatedNamedBuffer(pLODCArray, 160, "LOD CArray");
	if (!pLODCArray)
		{
		fclose(pLODFile);
		return false;
		}
	locked_fread(pLODCArray, sizeof(LODIndex), sLODFileHeader.uNumIndexDirs, pLODFile);
	fseek(pLODFile, 0, SEEK_SET);
	file_opened= true;
	return true;
}


//----- (00461A43) ---------.text:00462D4E-----LoadLOD_Games------------------------------------------
bool LOD_Writefile::Load_File(const char *pLODFilename, unsigned char uFileFlags)
{
	LODIndex lod_indx ; 

	if (uFileFlags & 1)
		pLODFile = fopen(pLODFilename, "rb");
	else
		pLODFile = fopen(pLODFilename, "rb+");
	if (!pLODFile)
		return false;

	strcpy(sLODName, pLODFilename);
	locked_fread(&sLODFileHeader, sizeof(struct LODFileHeader), 1, pLODFile);
	Reset_LODIndex(&lod_indx);
	locked_fread( &lod_indx,sizeof(LODIndex), 1, pLODFile);
	fseek(pLODFile, 0, SEEK_SET);
	file_opened = true;
	strcpy(sContainerName, "chapter");
	current_index_dir = 0;
	lLOD_Datasize = lod_indx.size_data;
	uNumSubidices = lod_indx.uSubIndixes;
	offset_to_subindex = lod_indx.offset_from_unit_start;
	fseek(pLODFile, offset_to_subindex, SEEK_SET);

	if (uNumSubidices > 300)
		{
		MessageBoxW(0, L"LODchapterPages exceed 300", L"LODFile", 0x30u);
		fclose(pLODFile);
		return false;
		}

	locked_fread(pLODSubIndexNamedBuffer, sizeof(struct LODIndex), uNumSubidices, pLODFile);
	return true;
}




	  //----- (00461EE9) -------------.text:004631FA  ----LODFile_sub_461EE9---------------------------------------
void LOD_Writefile::Close_Written_File()
{
if (file_opened)
	{
	sContainerName[0] = 0;
	current_index_dir = 0;
	file_opened = 0;
	global_dword_6A0CA8 = 0;
	fflush(pLODFile);
	fclose(pLODFile);
	}

}

//----- (00461F71) --------LODFile_sub_461F71------.text:00463287------------------------------------------
bool LOD_Writefile::Append_item_to_temp_file(const LODIndex *container_index, const void *container_data)
{
	if ( uNumSubidices < 299 )
		{
		memcpy(&pLODSubIndexNamedBuffer[uNumSubidices], container_index, sizeof(LODIndex));
		++uNumSubidices;
		locked_fwrite(container_data, 1, container_index->size_data, ptemp_write_file);
		return true;
		}
	else
		{
		MessageBoxW(0, L"Unable to append item!", L"LODFile", 0x30u);
		return false;
		}
}

//----- (004621A7) --------------------------------------------------------
signed int LOD_Writefile::LODFile_sub_4621A7()
{
  
  Close_Written_File();
  return Load_File( sLODName, 0);
}

//----- (00461B48) ------.text:00462E53 ---------LODFile_sub_461B48-----------------------------------------
unsigned int LOD_Writefile::Add_Container_to_File(const LODIndex *container_index, const void *container_data, int a4)
{
 
  char Filename[256]; 
  char NewFilename[256];
  LODIndex Lindx; 
  FILE *tmp_file; 
  int comp_res;
  bool bRewrite_data;
  int offset_to_data;
  int total_data_size;
  int size_correction;
  int Eax;
  int to_copy_size;
  int read_size;
  int curr_position;
  int insert_index;

  //insert new data in sorted index lod file
  bRewrite_data = false;
  insert_index=0;
  if (!file_opened)
	  return 1;
  if ( !pLODSubIndexNamedBuffer)
	  return 2;
  if (!pLODIOBuffer||!uIOBufferSize)
	  return 3;

  if ( uNumSubidices>0 )
	  {
	  for (int i=0;i<uNumSubidices; i++)
		  {
		  comp_res=stricmp(pLODSubIndexNamedBuffer[i].pFilename,container_index->pFilename);
		  if(comp_res==0)
			  {
			  if (a4==0)
				  {
				  bRewrite_data=true;
				  break;
				  }
			  if (a4==1)
				  { 
				  if(pLODSubIndexNamedBuffer[i].uSubIndixes<container_index->uSubIndixes)
					  {
					  if (pLODSubIndexNamedBuffer[i].reserved3<container_index->reserved3)
						  return 4;
					  }
				  else
					  bRewrite_data=true;	  
				  break;
				  }
			  if (a4==2)
				  return 4;
			  }
		  else if (comp_res>0)
			  break;
		  insert_index=i;
		  }
	  }
  strcpy(Filename, "lod.tmp");
  tmp_file = fopen(Filename, "wb+");
  if ( !tmp_file )
	  return 5;
  if (!bRewrite_data)
	  size_correction=0;
  else
	  size_correction=pLODSubIndexNamedBuffer[insert_index].size_data;
  //create chapter index
  Reset_LODIndex(&Lindx);
  strcpy(Lindx.pFilename, "chapter");
  Lindx.reserved1=0;
  Lindx.reserved3=0;
  Lindx.uSubIndixes= uNumSubidices;
  Lindx.offset_from_unit_start=sizeof(LODFileHeader)+sizeof(LODIndex);
  total_data_size=lLOD_Datasize+container_index->size_data-size_correction;
  if (!bRewrite_data)
	  {
	  total_data_size+=sizeof(LODIndex);
	  Lindx.uSubIndixes++;
	  }
 
  Lindx.size_data=total_data_size;
  uNumSubidices= Lindx.uSubIndixes;
  //move indexes +1 after insert point
  if  (!bRewrite_data&&(insert_index<uNumSubidices))
	  {
		 for(int i=uNumSubidices;i>insert_index; i--)
			   memcpy(&pLODSubIndexNamedBuffer[i],&pLODSubIndexNamedBuffer[i-1],sizeof(LODIndex));

	  }
  //insert
	 memcpy(&pLODSubIndexNamedBuffer[insert_index],container_index,sizeof(LODIndex));
  //correct offsets to data
  if (uNumSubidices>0)
	  {
		 offset_to_data=sizeof(LODIndex)*uNumSubidices;
		 for (int i=0;i<uNumSubidices; i++)
			 {
			  pLODSubIndexNamedBuffer[i].offset_from_unit_start=offset_to_data;
			  offset_to_data=+pLODSubIndexNamedBuffer[i].size_data;
			 }
	  }

  //construct  lod file	with added data
  locked_fwrite( &sLODFileHeader, sizeof(LODFileHeader), 1, tmp_file);
  locked_fwrite(&Lindx, sizeof(LODIndex), 1, tmp_file);
  fseek(pLODFile,Lindx.offset_from_unit_start, SEEK_SET);
  locked_fwrite(pLODSubIndexNamedBuffer, sizeof(LODIndex), uNumSubidices, tmp_file);

  offset_to_data = sizeof(LODIndex) * uNumSubidices;
  if ( bRewrite_data )
	  offset_to_data -= sizeof(LODIndex);

  fseek(pLODFile, offset_to_data, SEEK_CUR);
  //copy from open lod to temp 	lod	  first half
  to_copy_size=pLODSubIndexNamedBuffer[insert_index].offset_from_unit_start-pLODSubIndexNamedBuffer[0].offset_from_unit_start;
  while(to_copy_size>0)
	  {
	  read_size = uIOBufferSize;
	  if ( to_copy_size <= uIOBufferSize )
		  read_size = to_copy_size;
	  locked_fread(pLODIOBuffer, 1, read_size, pLODFile);
	  locked_fwrite(pLODIOBuffer, 1, read_size, tmp_file);
	  to_copy_size-=read_size;
	  }
  // add container data
  locked_fwrite(container_data, 1, container_index->size_data, tmp_file);
  if ( bRewrite_data )
	  fseek(pLODFile,size_correction , SEEK_CUR);

  //add remainng data  last half
  curr_position = ftell(pLODFile);
  fseek(pLODFile, 0, SEEK_END);
  to_copy_size = ftell(pLODFile) - curr_position;
  fseek(pLODFile, curr_position, SEEK_SET);
  while ( to_copy_size > 0 )
	  {
	  read_size = uIOBufferSize;
	  if ( to_copy_size <= uIOBufferSize )
		  read_size = to_copy_size;
	  locked_fread(pLODIOBuffer, 1, read_size, pLODFile);
	  locked_fwrite(pLODIOBuffer, 1, read_size, tmp_file);
	  to_copy_size-=read_size;
	  }
  //replace	  old file by new with added  data
  strcpy(NewFilename, sLODName);
  fclose(tmp_file);
  Close_Written_File();
  remove(NewFilename);
  rename(Filename, NewFilename);
  Close_Written_File();
  //reload new
  Load_File(sLODName, 0);
  return 0;
}




//----- (MM7.exe::0041088B) --------------------------------------------------------
void *LODFile_IB::LODFile_LoadRaw( const char *pContainer, int a3)
{
  unsigned char *result; // ebx@7
  unsigned char *v8; // edi@7
  cTexture cTexture_obj; // [sp+Ch] [bp-4Ch]@1
  FILE *pContainerFile; // [sp+54h] [bp-4h]@1
 
  wchar_t  pLodFile[256];
  void    *hFile;
  DWORD    w;
  int      ofs;

  
  cTexture_Zero(&cTexture_obj);

  pContainerFile = Find_Container( pContainer, 0);
  if (!pContainerFile)
  {
    erroneous_printf("Unable to load %s", pContainer);
	return NULL;
  }

  

#ifndef OLD_CODE
    wsprintfW(pLodFile, L".\\%S",  sLODName);
    hFile = CreateFileW(pLodFile, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
    ofs = ftell(pContainerFile);
    SetFilePointer(hFile, ofs, 0, FILE_BEGIN);
    ReadFile(hFile, &cTexture_obj, 0x30, &w, 0);
#endif
#ifdef OLD_CODE
	 locked_fread(&cTexture_obj, 1, 0x30u, pContainerFile);
#endif
	
  if (cTexture_obj.uDecompressedSize)
  {
    if (a3)
      result = (unsigned char *)malloc(cTexture_obj.uDecompressedSize);
    else
      result = (unsigned char *)mem_mng.AllocatedNamedBuffer( NULL, cTexture_obj.uDecompressedSize, cTexture_obj.sContainerName);

    v8 = (unsigned char *)mem_mng.AllocatedNamedBuffer( NULL, cTexture_obj.uCompressedSize, cTexture_obj.sContainerName);
 #ifndef OLD_CODE
    ReadFile(hFile, v8, cTexture_obj.uCompressedSize, &w, 0);
  #endif
#ifdef OLD_CODE
    fread(v8, 1, cTexture_obj.uCompressedSize, pContainerFile);
  #endif

    MemUnzip(result, &cTexture_obj.uDecompressedSize, v8, cTexture_obj.uCompressedSize);
    cTexture_obj.uCompressedSize = cTexture_obj.uDecompressedSize;
    mem_mng.DeleteBuffer( (void *)v8);
  }
  else
  {
    if (a3)
      result = (unsigned char *)malloc(cTexture_obj.uCompressedSize);
    else
     result = (unsigned char *)mem_mng.AllocatedNamedBuffer( 0, cTexture_obj.uCompressedSize, cTexture_obj.sContainerName);
    locked_fread(result, 1u, cTexture_obj.uCompressedSize, pContainerFile);
  }
  #ifndef OLD_CODE
    CloseHandle(hFile);
  
    fseek(pContainerFile, ofs + cTexture_obj.uCompressedSize, SEEK_SET);
   #endif

  return result;

}



//----- (MM7.exe::0040FC08) --------------------------------------------------------
int LODFile_IB::LoadTextureFromLOD(cTexture *pcTexture, const char *pContainerName, unsigned int uTextureType)
{
 
  unsigned int total_l_o_d_size; // edi@1
  char* tmp_palette;
  unsigned char *pCompressedBuffer,
                *pDecompressedBuffer;
  int   i,j;
  int result;
  FILE *texture_file;

  texture_file = Find_Container(pContainerName, 0);
  if (!texture_file)
	  return -1;

  locked_fread(pcTexture, 1,48, texture_file);
  strcpy(pcTexture->sContainerName, pContainerName);

  if ((pD3DRenderer->pRenderD3D3) && (pcTexture->word_00002C & 0x0002) &&  lod_IB_dword_011BA8)
	  {
	  if ( !pHardwareSurfaces || !pHardwareTextures )
		  {
		  pHardwareSurfaces = new IDirectDrawSurface4 *[1000];
		  pHardwareTextures = new IDirect3DTexture2 *[1000];
		  lod_IB_dword_011BB4 = new int *[250];
		  memset(*pHardwareTextures, 0, 4000);
		  memset(*pHardwareSurfaces, 0, 4000);
		  memset(*lod_IB_dword_011BB4, 0, 1000);
		  }
	  if ( pContainerName[0] == 'w'		//wtrdr
		  && pContainerName[1] == 't'
		  && pContainerName[2] == 'r'
		  && pContainerName[3] == 'd'
		  && pContainerName[4] == 'r' )
		  {

		  tmp_palette = (char*) malloc(strlen(pContainerName)+2);
		  tmp_palette[0] = 'h';
		  strcpy((char *)(tmp_palette[1]), (const char *) pContainerName[0]);

		  result = Render_sub_4A4DE1(
			  (int)pD3DRenderer,
			  (int)tmp_palette,
			  pcTexture->word_000024,
			  (int)pHardwareSurfaces[uNumLoadedFiles],
			  (int)pHardwareTextures[uNumLoadedFiles]);

		  free( tmp_palette);
		  }
	  else
		  {
		  if (pContainerName[0] == 'W'			 //WtrTyl
			  && pContainerName[1] == 't'
			  && pContainerName[2] == 'r'
			  && pContainerName[3] == 'T'
			  && pContainerName[4] == 'y'
			  && pContainerName[5] == 'l' )
			  {
			  dword_EF5294 = uNumLoadedFiles;
			  }

		  result = Render_sub_4A4DE1(
			  (int)pD3DRenderer,
			  (int)pContainerName,
			  pcTexture->word_000024,
			  (int)pHardwareSurfaces[uNumLoadedFiles],
			  (int)pHardwareTextures[uNumLoadedFiles]);

		  }
	  return result;
	  }



  if (!pcTexture->uDecompressedSize ||  lod_IB_dword_011BA4)
	  {
	  pcTexture->pIndexedPixels = (unsigned char *)mem_mng.AllocatedNamedBuffer( pcTexture->pIndexedPixels, 
		  pcTexture->uCompressedSize, pcTexture->sContainerName);
	  locked_fread(pcTexture->pIndexedPixels, 1u, pcTexture->uCompressedSize, texture_file);
	  }
  else
	  {
	  pCompressedBuffer = (unsigned char *)malloc(pcTexture->uCompressedSize);
	  pDecompressedBuffer = (unsigned char *)malloc(pcTexture->uDecompressedSize);

	  locked_fread(pCompressedBuffer, 1, pcTexture->uCompressedSize, texture_file);
	  MemUnzip(pDecompressedBuffer, &pcTexture->uDecompressedSize, pCompressedBuffer, pcTexture->uCompressedSize);
	  free(pCompressedBuffer);

	  pcTexture->uCompressedSize = pcTexture->uDecompressedSize;


	  if (bUseLoResSprites && (pcTexture->word_00002C & 0x0002))
		  {
		  total_l_o_d_size=pcTexture->uSizeOfMaxLevelOfDetal/4+
						   pcTexture->uSizeOfMaxLevelOfDetal/16+
						   pcTexture->uSizeOfMaxLevelOfDetal/64;
	
		  pcTexture->pIndexedPixels =(unsigned char *)mem_mng.AllocatedNamedBuffer( pcTexture->pIndexedPixels,total_l_o_d_size, pcTexture->sContainerName);

		  total_l_o_d_size=pcTexture->uTextureHeight*pcTexture->uTextureWidth+ total_l_o_d_size;
		  memcpy(pcTexture->pIndexedPixels,pDecompressedBuffer,total_l_o_d_size);
		  pcTexture->uTextureHeight = pcTexture->uTextureHeight/2;
		  pcTexture->uTextureWidth = pcTexture->uTextureWidth/2;
		  --pcTexture->word_00001C;
		  --pcTexture->word_00001E;
		  pcTexture->word_000020=pcTexture->uTextureWidth-1;
		  pcTexture->word_000022=pcTexture->uTextureHeight-1;
		  pcTexture->uSizeOfMaxLevelOfDetal=pcTexture->uTextureHeight*pcTexture->uTextureWidth;
		  pcTexture->uCompressedSize=total_l_o_d_size;
		 
		  }
	  else
		  {
		  pcTexture->pIndexedPixels = (unsigned char *)mem_mng.AllocatedNamedBuffer( pcTexture->pIndexedPixels, pcTexture->uDecompressedSize, pcTexture->sContainerName);
		  memcpy(pcTexture->pIndexedPixels, pDecompressedBuffer, pcTexture->uDecompressedSize);
		  }
	  free(pDecompressedBuffer);
	  }

  mem_mng.DeleteBuffer( (void *)pcTexture->pPalette);
  mem_mng.DeleteBuffer( (void *)pcTexture->ptr_000044);

  if (uTextureType == 1)
	  {
	  pcTexture->ptr_000044 = (unsigned char *)mem_mng.AllocatedNamedBuffer( pcTexture->ptr_000044, 768, pcTexture->sContainerName);
	  locked_fread(pcTexture->ptr_000044, 1, 768, texture_file);
	  pcTexture->pPalette = NULL;
	  }
  else
	  pcTexture->ptr_000044 = NULL;

  if (uTextureType == 2)
	  {	    
	  pcTexture->pPalette = (unsigned short *)mem_mng.AllocatedNamedBuffer( pcTexture->pPalette, 512, pcTexture->sContainerName);
	  tmp_palette=(char*)malloc(768);
	  locked_fread(tmp_palette,768, 1, texture_file);
	  j=0;
	  for (i = 0; i < 256; i++)
		  { 
		  pcTexture->pPalette[i] = (tmp_palette[j] >> (8 -  uTextureRedBits)) << ( uTextureBlueBits + uTextureGreenBits);
		  pcTexture->pPalette[i] += (tmp_palette[j+1] >> (8 -  uTextureGreenBits)) <<  uTextureBlueBits;
		  pcTexture->pPalette[i] += tmp_palette[j+2] >> (8 -  uTextureBlueBits);
		  j+=3;
		  }
	  free(tmp_palette);
	  }
  else
	  {
	  pcTexture->pPalette=NULL;
	  }

  if (pcTexture->word_00002C & 0x0002)
	  {
	  pcTexture->pLevelOfDetal1 = pcTexture->pIndexedPixels+pcTexture->uSizeOfMaxLevelOfDetal;
	  pcTexture->pLevelOfDetal2 = pcTexture->pIndexedPixels+pcTexture->uSizeOfMaxLevelOfDetal/4;	
	  pcTexture->pLevelOfDetal3 = pcTexture->pIndexedPixels+pcTexture->uSizeOfMaxLevelOfDetal/4+pcTexture->uSizeOfMaxLevelOfDetal/16;
	  }
  else
	  {
	  pcTexture->pLevelOfDetal1 =NULL;
	  pcTexture->pLevelOfDetal2 =NULL;	
	  pcTexture->pLevelOfDetal3 =NULL;
	  }

  for (short i=1; i<=15; i++)
	  {
	  if ((1<<i)==pcTexture->uTextureWidth)
		  {
		  pcTexture->word_00001C=i;
		  break;
		  }
	  }

  for (short i=1; i<=15; i++)
	  {
	  if ((1<<i)==pcTexture->uTextureHeight)
		  {
		  pcTexture->word_00001E=i;
		  break;
		  }
	  }
  switch (pcTexture->word_00001C)
	  {
  case 2:   pcTexture->word_000020 = 3;    break;
  case 3:   pcTexture->word_000020 = 7;    break;
  case 4:   pcTexture->word_000020 = 15;   break;
  case 5:   pcTexture->word_000020 = 31;   break;
  case 6:   pcTexture->word_000020 = 63;   break;
  case 7:   pcTexture->word_000020 = 127;  break;
  case 8:   pcTexture->word_000020 = 255;  break;
  case 9:   pcTexture->word_000020 = 511;  break;
  case 10:  pcTexture->word_000020 = 1023; break;
  case 11:  pcTexture->word_000020 = 2047; break;
  case 12:  pcTexture->word_000020 = 4095; break;
	  }

  switch (pcTexture->word_00001E)
	  {
  case 2:   pcTexture->word_000022 = 3;    break;
  case 3:   pcTexture->word_000022 = 7;    break;
  case 4:   pcTexture->word_000022 = 15;   break;
  case 5:   pcTexture->word_000022 = 31;   break;
  case 6:   pcTexture->word_000022 = 63;   break;
  case 7:   pcTexture->word_000022 = 127;  break;
  case 8:   pcTexture->word_000022 = 255;  break;
  case 9:   pcTexture->word_000022 = 511;  break;
  case 10:  pcTexture->word_000022 = 1023; break;
  case 11:  pcTexture->word_000022 = 2047; break;
  case 12:  pcTexture->word_000022 = 4095; break;
	  }

  return 1;
}


//----- (0041097D) -----------------text:00410C8F---------------------------------------
////int __thiscall sub_41097D(void *_this, int a2, int a3, int a4);
void LODFile_IB::SetupPalettes( int uTargetRBits, int uTargetGBits, int uTargetBBits)
{
 //depricated, though somehow sets font colors
 //compile_warning

 int             i, j,k;
 unsigned char*  tmp_palette;
 FILE           *f;

 cTexture  cTexture_obj;


 if ( uTextureRedBits == uTargetRBits &&  uTextureGreenBits == uTargetGBits &&  uTextureBlueBits == uTargetBBits)
	 return;


 uTextureRedBits = uTargetRBits;
 uTextureGreenBits = uTargetGBits;
 uTextureBlueBits = uTargetBBits;
 if (! uNumLoadedFiles)
	 return;
 tmp_palette=(unsigned char*)malloc(768);
 for (i = 0; i <  uNumLoadedFiles; i++)
	 {

	 cTexture_Zero(&cTexture_obj);
	 if (! aLODHeaders[i].pPalette)
		 continue;

	 f = Find_Container( aLODHeaders[i].sContainerName, 0);
	 if (!f)
		 continue;

	 locked_fread(&cTexture_obj, 1, 48, f);
	 fseek(f, cTexture_obj.uCompressedSize, SEEK_CUR);
	 locked_fread(tmp_palette, 1,768, f);
	 k=0;
	 for (j = 0; j < 512; ++j)
		 {
		 aLODHeaders[i].pPalette[j] = (tmp_palette[k] >> (8 -  uTextureRedBits)) << ( uTextureBlueBits + uTextureGreenBits);
		 aLODHeaders[i].pPalette[j] += (tmp_palette[k+1] >> (8 -  uTextureGreenBits)) <<  uTextureBlueBits;
		 aLODHeaders[i].pPalette[j] += tmp_palette[k+2] >> (8 -  uTextureBlueBits);
		  k+=3;
		 }
	 }
 free(tmp_palette);

}

//----- (004114F2) --------------------------------------------------------
int LODFile_IB::LODFile_sub_4114F2()
{
  int result; // eax@1
  int v2; // ecx@1
  int v3; // esi@1
  int v4; // ecx@2
  int v5; // edi@3
  int v6; // ebx@4
  int v7; // eax@5
  int v8; // eax@6
  int v9; // eax@8
  int v10; // eax@9

  v3 = (int)this;
  result = (int)& lod_IB_dword_011B9C;
  v2 =  lod_IB_dword_011B9C;
  if ( v2 )
  {
    v4 = v2 - 1;
     lod_IB_dword_011B9C = v4;
    if ( !v4 )
    {
      v5 =  uNumLoadedFiles - 1;
      if ( v5 >=  lod_IB_dword_011B98)
      {
        v6 = (int)& aLODHeaders[v5];
        do
        {
          cTexture_Free((cTexture *)v6);
          v7 = (int) pHardwareTextures;
          if ( v7 )
          {
            v8 = *(_DWORD *)(v7 + 4 * v5);
            if ( v8 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v8 + 8))(v8);
              *(_DWORD *)(*(_DWORD *)(v3 + 72624) + 4 * v5) = 0;
            }
          }
          v9 = *(_DWORD *)(v3 + 72620);
          if ( v9 )
          {
            v10 = *(_DWORD *)(v9 + 4 * v5);
            if ( v10 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v10 + 8))(v10);
              *(_DWORD *)(*(_DWORD *)(v3 + 72620) + 4 * v5) = 0;
            }
          }
          --v5;
          v6 -= 72;
        }
        while ( v5 >= *(_DWORD *)(v3 + 72600) );
      }
      result = *(_DWORD *)(v3 + 72600);
      *(_DWORD *)(v3 + 72600) = 0;
      *(_DWORD *)(v3 + 72572) = result;
    }
  }
  return result;
}


#ifndef	OLD_CODE
unsigned int LODFile_IB::LODFile_LoadTexture_New(const wchar_t *pFilename)
{
 void    *hFile;
 DWORD    w;
 wchar_t  pFileNotFound[256];

 wchar_t      pFilePath[256];
 unsigned int uCBMWdith,
              uCBMHeight;

 int  i;
 char pAnsiFilename[256];

 wsprintfA(pAnsiFilename, "%S", pFilename);
 for (i = 0; i < uNumLoadedFiles; ++i)
 {
  if (!lstrcmpiA(pAnsiFilename, aLODHeaders[i].sContainerName))
    return i;
 }


 if (uNumLoadedFiles >= 2500) //>= 1000
   err_show();

 //try to open CBM
 wsprintfW(pFilePath, L".\\Data\\%S\\%s.cbm", sContainerName, pFilename);
 if (LoadCBM(pFilePath, &uCBMWdith, &uCBMHeight, &aLODHeaders[uNumLoadedFiles].pTruecolorPixels))
 {
  //try open TGA
  wsprintfW(pFilePath, L".\\Data\\%S\\%s.tga", sContainerName, pFilename);
  if (LoadTGA(pFilePath, &uCBMWdith, &uCBMHeight, &aLODHeaders[uNumLoadedFiles].pTruecolorPixels))
  {
   //try open PNG
   wsprintfW(pFilePath, L".\\Data\\%S\\%s.png",  sContainerName, pFilename);
   if (LoadPNG(pFilePath, &uCBMWdith, &uCBMHeight, &aLODHeaders[ uNumLoadedFiles].pTruecolorPixels))
   {
    if (LoadHWL(pFilename, &uCBMWdith, &uCBMHeight, &aLODHeaders[ uNumLoadedFiles].pTruecolorPixels))
    {
     if (!hStdHandle)
       hStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
     wsprintfW(pFileNotFound, L"Texture not found: %s\n", pFilename);
     WriteConsoleW(hStdHandle, pFileNotFound, lstrlenW(pFileNotFound), &w, 0);

     if (!pending_texture.pTruecolorPixels)
       pending_texture.pTruecolorPixels = new unsigned int[52 * 53];
     pending_texture.uTextureWidth = 52;
     pending_texture.uTextureHeight = 53;
     return -1;
    }
   }
  }
 }

 wsprintfA( aLODHeaders[ uNumLoadedFiles].sContainerName, "%S", pFilename);
 aLODHeaders[uNumLoadedFiles].uTextureWidth = uCBMWdith;
 aLODHeaders[uNumLoadedFiles].uTextureHeight = uCBMHeight;

 Render_MoveToGPU(pD3DRenderer, uCBMWdith, uCBMHeight,  aLODHeaders[ uNumLoadedFiles].pTruecolorPixels, & pHardwareSurfaces[ uNumLoadedFiles], & pHardwareTextures[ uNumLoadedFiles]);

 uNumLoadedFiles++;
 return uNumLoadedFiles - 1;
}



bool LODFile_IB::LODFile_ReleaseTexture( unsigned int uTextureID)
{
 return true;
}	
 
#endif
//----- (004AC7C0) --------------------------------------------------------
unsigned int LODFile_Sprite::LODFile_LoadSprite( const char *pSourceFile, int a3)
{
  //int v4; // esi@1
  FILE * v8; // eax@12
  signed int v12; // eax@22
  struct
  {
   char DstBuf[0x10]; // [sp+Ch] [bp-3Ch]@13
  __int16 v16; // [sp+1Ch] [bp-2Ch]@21
  __int16 v17; // [sp+1Eh] [bp-2Ah]@12
  __int16 v18; // [sp+20h] [bp-28h]@12
  short _22;
  short _24;
  __int16 v19; // [sp+26h] [bp-22h]@12
   short _28;
   short _2A;
  int v20; // [sp+2Ch] [bp-1Ch]@12
  int v21; // [sp+30h] [bp-18h]@12
  } local_0C;
  int v24; // [sp+44h] [bp-4h]@12
 int i;


 //v4 = (int)_this;
 if (pD3DRenderer->pRenderD3D3)
 {
  for (i = 0; i < uNumLoadedSprites; ++i)
   if (!strcmpi((char *)pHardwareSprites[i].pSpriteName, pSourceFile))
      return i;
 }
 else for (i = 0; i < uNumLoadedSprites; ++i)
   if (!strcmpi(aSpriteHeaders[i].sContainerName, pSourceFile))
     return i;

 if (uNumLoadedSprites >= 1500)
   return -1;


 if (pD3DRenderer->pRenderD3D3 && dword_00ECAC)
 {
  if (!pHardwareSprites)
  {
   pHardwareSprites = (HardwareSprite *)mem_mng.AllocatedNamedBuffer( NULL, 1500 * sizeof(struct HardwareSprite), "hardwareSprites");

   for (i = 0; i < 1500; ++i)
   {
    pHardwareSprites[i].pSpriteName = 0;
    pHardwareSprites[i].pTexture = 0;
    pHardwareSprites[i].pTextureSurface = 0;
   }
  }

    local_0C.v17 = 0;
    local_0C.v18 = 0;
    local_0C.v19 = 0;
    local_0C.v20 = 0;
    local_0C.v21 = 0;
    v24 = 0;
    v8 = Find_Container( pSourceFile, false);
    if ( !v8 )
    {
      v24 = -1;
      //sub_462463((int)&local_0C);
      return -1;
    }

    locked_fread(&local_0C, 1u, 0x20, v8);
    v24 = -1;
    pHardwareSprites[uNumLoadedSprites].dword_000018 = local_0C.v16;
    pHardwareSprites[uNumLoadedSprites].dword_00001C = local_0C.v17;
    aSpriteHeaders[uNumLoadedSprites].word_000010 = local_0C.v16;
    aSpriteHeaders[uNumLoadedSprites].word_000012 = local_0C.v17;
    //sub_462463(&local_0C);
    goto LABEL_29;
  }

  v12 = sub_4AC67E_LoadSpriteFromFile( &aSpriteHeaders[uNumLoadedSprites], pSourceFile);
  aSpriteHeaders[uNumLoadedSprites].c0001A = 0;
  if ( v12 != -1 )
  {
LABEL_28:
   aSpriteHeaders[uNumLoadedSprites].uPaletteID = class35_sub_48A3BC_MessWithPalettes(&class35_obj, aSpriteHeaders[uNumLoadedSprites].uPaletteID);

LABEL_29:
    if (pD3DRenderer->pRenderD3D3)
    {
     pHardwareSprites[uNumLoadedSprites].pSpriteName = (unsigned char *)mem_mng.AllocatedNamedBuffer(pHardwareSprites[uNumLoadedSprites].pSpriteName, 20, pSourceFile);
     strcpy((char *)pHardwareSprites[uNumLoadedSprites].pSpriteName, pSourceFile);
     pHardwareSprites[uNumLoadedSprites].dword_000004 = a3;
     Render_MoveHWSpriteToVideoMemory(pD3DRenderer, &pHardwareSprites[uNumLoadedSprites]);
    }
    ++uNumLoadedSprites;
    return uNumLoadedSprites - 1;
  }
  if (!uNumLoadedSprites)
  {
LABEL_27:
    if ( sub_4AC67E_LoadSpriteFromFile(&aSpriteHeaders[uNumLoadedSprites], "pending") == -1 )
      return -1;
    goto LABEL_28;
  }

 for (i = 0; i < uNumLoadedSprites; ++i)
   if (!stricmp(aSpriteHeaders[i].sContainerName, "pending"))
     return i;

 goto LABEL_27;
}



//----- (MM7.exe::0040FAEE) -------0040FDE7 -------------------------------------------------
bool LODFile_IB::LODFile_LoadLOD_Icons_Events( const char *pFilename)
{
 Reset_TextureBuffs();
 if (!Load_LODHeader( pFilename, 1))
   return 0;
#ifndef OLD_CODE 
 pHardwareSurfaces = new IDirectDrawSurface4 *[1000];
 pHardwareTextures = new IDirect3DTexture2 *[1000];
 lod_IB_dword_011BB4 = new int *[250];
#endif  
 return  Load_SubIndexes("icons") == 0;
}

//----- (MM7.exe::0040FA2E) ---------.text:0040FD27 -----------------------------------------------
bool LODFile_IB::LODFile_LoadLOD_Bitmaps( const char *pFilename)
{
 Reset_TextureBuffs();
 if (!Load_LODHeader( pFilename, 1))
   return 0;
 #ifndef OLD_CODE
 pHardwareSurfaces = new IDirectDrawSurface4 *[1000];
 pHardwareTextures = new IDirect3DTexture2 *[1000];
 lod_IB_dword_011BB4 = new int *[250];
#endif

 return  Load_SubIndexes( "bitmaps") == 0;
}

//----- (MM7.exe::004AC795) --------------------------------------------------------
bool LODFile_Sprite::LODFile_LoadLOD_Sprites(const char *pFilename)
{
 if (!Load_LODHeader(pFilename, 1))
   return 0;

 return  Load_SubIndexes("sprites08") == 0;
}



//----LODFile_fn4- (MM7.exe::0040FA60) --------.text:0040FD59------------------------------------------------
void LODFile_IB::Reset_TextureBuffs()
{
   for (int i=0; i<uNumLoadedFiles; i++)
		 {
		 cTexture_Free(&aLODHeaders[i]);
		  if (pHardwareSurfaces)
			 if	 (pHardwareSurfaces[i])
				 {
				 pHardwareSurfaces[i]->Release();
				 pHardwareSurfaces[i]=NULL;
				 }
		 if (pHardwareTextures)
			 if	 (pHardwareTextures[i])
				 {
				 pHardwareTextures[i]->Release();
				 pHardwareTextures[i]=NULL;
				 }
		 }

     uNumLoadedFiles=0;
	 lod_IB_dword_011B80=0;//
	 lod_IB_dword_011B84=0; //

	 lod_IB_dword_011B98=0; //
	 lod_IB_dword_011B9C=0; //	

}



//---LODFile_fn6-- (MM7.exe::0046188A) -------.text:00462B8D -------------------------------------------------
int LOD_file::Load_SubIndexes(const char *pContainer)
{
unsigned int uDirCount; // edi@1
LODIndex *curr_index;

//v3 = (int)this;
Reset_SubIndexBuffer();
uDirCount = 0;

if ( sLODFileHeader.uNumIndexDirs <= 0)
	return 3;
else
	{
	while (stricmp(pContainer, &(((LODIndex *)pLODCArray)[uDirCount].pFilename[0])))
		{
		++uDirCount;  
		if (uDirCount >=  sLODFileHeader.uNumIndexDirs)
			return 3;
		}
	strcpy( sContainerName, pContainer);
	current_index_dir = uDirCount;
	curr_index=(LODIndex *)&pLODCArray[uDirCount];
	offset_to_subindex =curr_index->offset_from_unit_start ;
	uNumSubidices =curr_index->uSubIndixes;// *(_WORD *)(v8 + 28);
	fseek( pLODFile, offset_to_subindex, 0);
	pLODSubIndexNamedBuffer = 
		(LODIndex *)mem_mng.AllocatedNamedBuffer( pLODSubIndexNamedBuffer, ( uNumSubidices + 5) * sizeof(struct LODIndex), "LOD Index");

	if ( pLODSubIndexNamedBuffer)
		locked_fread( pLODSubIndexNamedBuffer, sizeof(struct LODIndex),  uNumSubidices,  pLODFile);
	return 0;
	}

}

//-----LODFile_fn7 (0046153F) --------------------------------------------------------
void LOD_file::Reset_SubIndexBuffer()
{
 
 if (file_opened)
 {
   sContainerName[0] = 0;
   current_index_dir = 0;
   lLOD_Datasize = 0;
   uNumSubidices = 0;
   offset_to_subindex = 0;
   mem_mng.DeleteBuffer( (void *) pLODSubIndexNamedBuffer);
   pLODSubIndexNamedBuffer = 0;
 }

}



//----- (MM7.exe::0040FB20) ------.text:0040FE19 --------------------------------------------------
int LODFile_IB::LODFile_LoadTexture( const char *pContainerName, unsigned int a3)
{
  int i; // ebx@8
  int result;
  dword_506128 = 1;
  if ( uNumLoadedFiles > 0 )
	  {
	  //already loaded check
	  for ( i=0; i<uNumLoadedFiles; i++)
		  {
		  if (!stricmp(&((cTexture*)aLODHeaders)[i].sContainerName[0], pContainerName))
			  return i; 	 
		  }
	  }
  if ( uNumLoadedFiles >= 1000)
	  err_show();

  if (LoadTextureFromLOD( &aLODHeaders[uNumLoadedFiles], pContainerName, a3) == -1)
	  {
	  i=0;
	  if ( uNumLoadedFiles > 0)
		  {
		  for (i=0; i<uNumLoadedFiles; i++)
			  {
			  if (!stricmp(&((cTexture*)aLODHeaders)[i].sContainerName[0], "pending"))
				  return i; 	 
			  }
		  if (i=uNumLoadedFiles)
			  LoadTextureFromLOD( &aLODHeaders[ uNumLoadedFiles], "pending", a3);
		  }
	  }

  dword_506128 = 0;
  uNumLoadedFiles++;
  return  uNumLoadedFiles - 1;
}











//----- (004AC67E) --------------------------------------------------------
int LODFile_Sprite::sub_4AC67E_LoadSpriteFromFile( Sprites_Header *pDstBuf, const char *pFilename)
{
  signed int v6; // eax@3
  char *v8; // esi@3
  int i; // edx@6
  int v16; // [sp+10h] [bp+8h]@4
 FILE *f;

  f = Find_Container( pFilename, 0);
  if (!f)
    return -1;

   v8 = (char *)pDstBuf;
   locked_fread(pDstBuf, 1, 0x20, f);
   strcpy(pDstBuf->sContainerName, pFilename);
   pDstBuf->pSomeSpriteData = (SomeSpriteData *)mem_mng.AllocatedNamedBuffer( pDstBuf->pSomeSpriteData, 8 * pDstBuf->word_000012, pDstBuf->sContainerName);
   locked_fread(pDstBuf->pSomeSpriteData, 1, 8 * pDstBuf->word_000012, f);
   v6 = pDstBuf->dword_00001C;
    if ( v6 )
    {
     pDstBuf->ptr_000024 = (unsigned char *)mem_mng.AllocatedNamedBuffer( pDstBuf->ptr_000024, v6, pDstBuf->sContainerName);
     v16 = (int)mem_mng.AllocatedNamedBuffer( 0, pDstBuf->dword_00000C, pDstBuf->sContainerName);
     locked_fread((void *)v16, 1, pDstBuf->dword_00000C, f);
     MemUnzip(pDstBuf->ptr_000024, (unsigned int *)&pDstBuf->dword_00001C, (int *)v16, pDstBuf->dword_00000C);
     pDstBuf->dword_00000C = pDstBuf->dword_00001C;
     mem_mng.DeleteBuffer( (void *)(int *)v16);
    }
    else
    {
     pDstBuf->ptr_000024 = (unsigned char *)mem_mng.AllocatedNamedBuffer( pDstBuf->ptr_000024, pDstBuf->dword_00000C, pDstBuf->sContainerName);
     locked_fread(pDstBuf->ptr_000024, 1, pDstBuf->dword_00000C, f);
    }


    for (i = 0; i < pDstBuf->word_000012; ++i)
      pDstBuf->pSomeSpriteData[i].ptr_000004 += (unsigned int)pDstBuf->ptr_000024;
 
  return 1;
}


//----- (004645DC) ---------text:004658FC    -----------------------------------------------
int  LODFile_Sprite::sub_4645DC()
{
  int result; // eax@1
  int v1;
  int v2; // esi@1
  int v3; // edi@1

  
  v2 = uNumLoadedSprites;
  v3 = dword_00ECA8;
 uNumLoadedSprites=Delete_sprites_Range(  dword_00ECA8,uNumLoadedSprites);
  result = uNumLoadedSprites;
 // *(_DWORD *)v2 = *(_DWORD *)v3;
  return result;
}



//----- (0046454B) ---------------------.text:0046586B -----------------------------------
int LODFile_IB::sub_46454B()
{
  int v1; // edi@1
  int v2; // esi@1
  cTexture *v3; // ebx@2
  int v4; // eax@3
  int v5; // eax@4
  int v6; // eax@6
  int v7; // eax@7
  int result; // eax@10

  v2 = (int)this;
  v1 =  0;
  if ( (uNumLoadedFiles - 1) >=  lod_IB_dword_011B84)
  {
    //v3 = v2 + 72 * v1 + 572;
    v3 = & aLODHeaders[v1];
    do
    {
     runtime_warning(this stuff kills textures being drawn);
      //cTexture_Free(v3);
      v4 = *(_DWORD *)(v2 + 72624);	 //bb0 *pHardwareTextures
      if ( v4 )
      {
        v5 = *(_DWORD *)(v4 + 4 * v1);
        if ( v5 )
        {
          (*(void (__stdcall **)(int))(*(_DWORD *)v5 + 8))(v5);
          *(_DWORD *)(*(_DWORD *)(v2 + 72624) + 4 * v1) = 0;
        }
      }
      v6 = *(_DWORD *)(v2 + 72620);	  //pHardwareSurfaces
      if ( v6 )
      {
        v7 = *(_DWORD *)(v6 + 4 * v1);
        if ( v7 )
        {
          (*(void (__stdcall **)(int))(*(_DWORD *)v7 + 8))(v7);
          *(_DWORD *)(*(_DWORD *)(v2 + 72620) + 4 * v1) = 0;
        }
      }
      --v1;
      v3 -= 72;
    }
    while ( v1 >=  lod_IB_dword_011B84);
  }
  result = *(_DWORD *)(v2 + 72580);
  *(_DWORD *)(v2 + 72604) = 0;
  *(_DWORD *)(v2 + 72600) = 0;
  *(_DWORD *)(v2 + 72572) = result;
  return result;
}

unsigned char *LODFile_IB::LODFile_LoadEvent(const wchar_t *pFilename)
{
 DWORD          w;
 void          *hFile;
 unsigned char *pOut;
 wchar_t        pFilepath[256];
 char           pFilenameA[256];

 wsprintfW(pFilepath, L".\\Data\\Events\\%s", pFilename);
 hFile = CreateFileW(pFilepath, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
 if (hFile == INVALID_HANDLE_VALUE)
 {
  wsprintfA(pFilenameA, "%S", pFilename);
  return (unsigned char *)LODFile_LoadRaw( pFilenameA, 0);
 }

 pOut = new unsigned char[GetFileSize(hFile, 0)];
 ReadFile(hFile, pOut, GetFileSize(hFile, 0), &w, 0);

 CloseHandle(hFile);
 return pOut;
}

//----- (004101B1) --------------------------------------------------------
signed int  LODFile_IB::LODFile_sub_4101B1( char *DstBuf, const char *Source, size_t Count)
{
  FILE* v4; // eax@1
  int v5; // edi@1
  char *v6; // esi@2
  size_t v7; // ecx@6
  signed int v8; // ebx@6
  signed int result; // eax@7
  size_t *v10; // ebx@8
  int v11; // eax@10
  int v12; // eax@10
  signed int v13; // ebx@12
  size_t v14; // eax@13
  int v15; // edx@13
  FILE *v16; // [sp+Ch] [bp-8h]@1
  unsigned __int8 v17; // [sp+11h] [bp-3h]@13
  unsigned __int8 v18; // [sp+12h] [bp-2h]@13
  unsigned __int8 v19; // [sp+13h] [bp-1h]@13
  void *v20; // [sp+1Ch] [bp+8h]@10
  void *v21; // [sp+20h] [bp+Ch]@10
  size_t v22; // [sp+24h] [bp+10h]@6

  v5 = (int)this;
  v4 = Find_Container( Source, 0);
  //v16 = (FILE *)v4;
  if ( v4
    && (v6 = DstBuf, *((_DWORD *)DstBuf + 12))
    && Count == 2
    && *((_DWORD *)DstBuf + 16)
    && !*((_DWORD *)DstBuf + 17)
    && (v8 = *((_DWORD *)DstBuf + 5),
        locked_fread(DstBuf, 1u, 0x30u, v4),
        strcpy(DstBuf, Source),
        v7 = *((_DWORD *)DstBuf + 5),
        v22 = *((_DWORD *)DstBuf + 5),
        (signed int)v7 <= v8) )
  {
    v10 = (size_t *)(DstBuf + 40);
    if ( !*((_DWORD *)DstBuf + 10) || *(_DWORD *)(v5 + 72612) )
    {
      locked_fread(*((void **)DstBuf + 12), 1u, v7, v4);
    }
    else
    {
      v21 = malloc(*((_DWORD *)DstBuf + 10));
      v20 = malloc(*((_DWORD *)DstBuf + 5));
      locked_fread(v20, 1u, v22, v16);
      MemUnzip(v21, (unsigned int *)v6 + 10, v20, *((_DWORD *)v6 + 5));
      v11 = *v10;
      *((_DWORD *)v6 + 5) = *v10;
      free(v20);
      v12 = (int)memcpy(*((void **)v6 + 12), v21, *v10);
      free(v21);
    }
    v13 = 0;
    do
    {
      locked_fread(&v19, 1u, 1u, v4);
      locked_fread(&v18, 1u, 1u, v4);
      v14 = locked_fread(&v17, 1u, 1u, v4);
      LOWORD(v14) = (unsigned __int8)(v19 >> (8 - *(_BYTE *)(v5 + 72588)));
      *(_WORD *)(v13 + *((_DWORD *)v6 + 16)) = v14 << (*(_BYTE *)(v5 + 72596) + *(_BYTE *)(v5 + 72592));
      LOWORD(v15) = (unsigned __int8)(v18 >> (8 - *(_BYTE *)(v5 + 72592)));
      *(_WORD *)(v13 + *((_DWORD *)v6 + 16)) += v15 << *(_DWORD *)(v5 + 72596);
      *(_WORD *)(v13 + *((_DWORD *)v6 + 16)) += (unsigned __int8)(v17 >> (8 - *(_BYTE *)(v5 + 72596)));
      v13 += 2;
    }
    while ( v13 < 512 );
    result = 1;
  }
  else
  {
    result = -1;
  }
  return result;
}


//----- (0040F9C5) --------------------------------------------------------
int  LODFile_IB::LODFile_sub_40F9C5()
{
  int result; // eax@1
  int i; // edx@1

  result = *(_DWORD *)((int)this + 72572);
  for ( i = (int)this + 72 * result + 572; !*(_BYTE *)i; i -= 72 )
    --result;
  if ( result < *(_DWORD *)((int)this + 72572) )
  {
    ++result;
    *(_DWORD *)((int)this + 72572) = result;
  }
  return result;
}

//----- (0040F9F0) --------------------------------------------------------
signed int  LODFile_IB::LODFile_sub_40F9F0( const char *Str2)
{
  signed int v2; // edi@1
  int v3; // esi@1
  const char *v4; // ebx@2
  signed int result; // eax@5

  v3 = (int)this;
  v2 = 0;
  if ( *(_DWORD *)(v3 + 72572) <= 0 )
  {
LABEL_5:
    result = -1;
  }
  else
  {
    v4 = (const char *)(v3 + 572);
    while ( stricmp(v4, Str2) )
    {
      ++v2;
      v4 += 72;
      if ( v2 >= *(_DWORD *)(v3 + 72572) )
        goto LABEL_5;
    }
    result = v2;
  }
  return result;
}

//----- (00410522) --------------------------------------------------------
signed int LODFile_IB::LODFile_sub_410522( void *DstBuf, const char *Source, int a4)
{
  int v4; // edi@1
  unsigned int v5; // eax@5
  int v6; // ebx@5
  char *v7; // esi@5
  unsigned int v8; // ST28_4@6
  int v9; // eax@6
  unsigned int v10; // ST2C_4@6
  void *v11; // eax@7
  FILE *v12; // ST28_4@7
  void *v13; // eax@9
  FILE *v14; // ST28_4@9
  int v15; // eax@12
  signed int v16; // eax@12
  int v17; // ecx@12
  int v18; // ecx@12
  signed int v19; // ebx@14
  size_t v20; // eax@15
  int v21; // edx@15
  signed int v22; // ecx@18
  signed int v23; // ecx@23
  char Args[100]; // [sp+4h] [bp-68h]@3
  FILE *File1; // [sp+68h] [bp-4h]@1
  int v27; // [sp+74h] [bp+8h]@5
  size_t v28; // [sp+74h] [bp+8h]@6
  size_t v29; // [sp+74h] [bp+8h]@7

  v4 = (int)this;
  File1 = Find_Container( Source, 0);
  if ( !File1 )
  {
    File1 = Find_Container( "pending", 0);
    if ( !File1 )
    {
      wsprintfA(Args, "Can't find %s!", Source);
      erroneous_printf(Args);
    }
  }
  v7 = (char *)DstBuf;
  locked_fread(DstBuf, 1u, 0x30u, File1);
  strcpy(v7, Source);
  v6 = (int)(v7 + 40);
  v27 = *((_DWORD *)v7 + 5);
  v5 = *((_DWORD *)v7 + 10);
  *((_DWORD *)v7 + 12) = 0;
  if ( v5 )
  {
    v8 = *((_DWORD *)v7 + 5);
    compile_error;//*((_DWORD *)v7 + 12) = new char[v5];
    compile_error;//Source = (const char *)new char[v8];
    locked_fread((void *)Source, 1u, v28, File1);
    MemUnzip(*((_DWORD **)v7 + 12), (unsigned int *)v7 + 10, Source, *((_DWORD *)v7 + 5));
    v9 = *(_DWORD *)v6;
    v10 = (unsigned int)Source;
    *((_DWORD *)v7 + 5) = *(_DWORD *)v6;
    operator_delete((void *)v10);
  }
  else
  {
    compile_error;//v11 = new char[0];
    v12 = File1;
    *((_DWORD *)v7 + 12) = (int)v11;
    locked_fread(v11, 1u, v29, v12);
  }
  *((_DWORD *)v7 + 17) = 0;
  if ( a4 == 1 )
  {
    compile_error;//v13 = new char[0x300u];
    v14 = File1;
    *((_DWORD *)v7 + 17) = (int)v13;
    locked_fread(v13, 1u, 0x300u, v14);
  }
  else
  {
    if ( a4 == 2 )
    {
      v19 = 0;
      *((_DWORD *)v7 + 16) = 0;
      compile_error;//*((_DWORD *)v7 + 16) = operator new(0x400u);
      do
      {
        locked_fread((char *)&Source + 3, 1u, 1u, File1);
        locked_fread((char *)&a4 + 3, 1u, 1u, File1);
        v20 = locked_fread((char *)&DstBuf + 3, 1u, 1u, File1);
        LOWORD(v20) = (unsigned __int8)(BYTE3(Source) >> (8 - *(_BYTE *)(v4 + 72588)));
        *(_WORD *)(v19 + *((_DWORD *)v7 + 16)) = v20 << (*(_BYTE *)(v4 + 72596) + *(_BYTE *)(v4 + 72592));
        LOWORD(v21) = (unsigned __int8)(BYTE3(a4) >> (8 - *(_BYTE *)(v4 + 72592)));
        *(_WORD *)(v19 + *((_DWORD *)v7 + 16)) += v21 << *(_DWORD *)(v4 + 72596);
        *(_WORD *)(v19 + *((_DWORD *)v7 + 16)) += (unsigned __int8)(BYTE3(DstBuf) >> (8 - *(_BYTE *)(v4 + 72596)));
        v19 += 2;
      }
      while ( v19 < 512 );
      goto LABEL_11;
    }
  }
  *((_DWORD *)v7 + 16) = 0;
LABEL_11:
  if ( v7[44] & 2 )
  {
    v16 = *((_DWORD *)v7 + 4);
    v17 = v16 + *((_DWORD *)v7 + 12);
    *((_DWORD *)v7 + 13) = v17;
    v18 = (v16 >> 2) + v17;
    *((_DWORD *)v7 + 14) = v18;
    v15 = v18 + (v16 >> 4);
  }
  else
  {
    v15 = 0;
    *((_DWORD *)v7 + 14) = 0;
    *((_DWORD *)v7 + 13) = 0;
  }
  *((_DWORD *)v7 + 15) = v15;
  v22 = 1;
  while ( 1 << v22 != *((_WORD *)v7 + 12) )
  {
    ++v22;
    if ( v22 >= 15 )
      goto LABEL_23;
  }
  *((_WORD *)v7 + 14) = v22;
LABEL_23:
  v23 = 1;
  while ( 1 << v23 != *((_WORD *)v7 + 13) )
  {
    ++v23;
    if ( v23 >= 15 )
      goto LABEL_28;
  }
  *((_WORD *)v7 + 15) = v23;
LABEL_28:
  switch ( *((_WORD *)v7 + 14) )
  {
    case 2:
      *((_WORD *)v7 + 16) = 3;
      break;
    case 3:
      *((_WORD *)v7 + 16) = 7;
      break;
    case 4:
      *((_WORD *)v7 + 16) = 15;
      break;
    case 5:
      *((_WORD *)v7 + 16) = 31;
      break;
    case 6:
      *((_WORD *)v7 + 16) = 63;
      break;
    case 7:
      *((_WORD *)v7 + 16) = 127;
      break;
    case 8:
      *((_WORD *)v7 + 16) = 255;
      break;
    case 9:
      *((_WORD *)v7 + 16) = 511;
      break;
    case 10:
      *((_WORD *)v7 + 16) = 1023;
      break;
    case 11:
      *((_WORD *)v7 + 16) = 2047;
      break;
    case 12:
      *((_WORD *)v7 + 16) = 4095;
      break;
    default:
      break;
  }
  switch ( *((_WORD *)v7 + 15) )
  {
    case 2:
      *((_WORD *)v7 + 17) = 3;
      break;
    case 3:
      *((_WORD *)v7 + 17) = 7;
      break;
    case 4:
      *((_WORD *)v7 + 17) = 15;
      break;
    case 5:
      *((_WORD *)v7 + 17) = 31;
      break;
    case 6:
      *((_WORD *)v7 + 17) = 63;
      break;
    case 7:
      *((_WORD *)v7 + 17) = 127;
      break;
    case 8:
      *((_WORD *)v7 + 17) = 255;
      break;
    case 9:
      *((_WORD *)v7 + 17) = 511;
      break;
    case 10:
      *((_WORD *)v7 + 17) = 1023;
      break;
    case 11:
      *((_WORD *)v7 + 17) = 2047;
      break;
    case 12:
      *((_WORD *)v7 + 17) = 4095;
      break;
    default:
      return 1;
  }
  return 1;
}

//----- (004355F7) --------------------------------------------------------
void LODFile_IB::sub_4355F7()
{
  int v1; // esi@1
  int v2; // edi@2
  int v3; // ebp@3
  int v4; // eax@4
  int v5; // eax@5
  int v6; // eax@7
  int v7; // eax@8
  int v8; // eax@11

  v1 = (int)this;
  if ( *(_DWORD *)(v1 + 72604) )
  {
    v2 = *(_DWORD *)(v1 + 72572) - 1;
    if ( v2 >= *(_DWORD *)v1 + 72600) 
    {
      v3 = v1 + 72 * v2 + 572;
      do
      {
        cTexture_Free((cTexture *)v3);
        v4 = *(_DWORD *)(v1 + 72624);
        if ( v4 )
        {
          v5 = *(_DWORD *)(v4 + 4 * v2);
          if ( v5 )
          {
            (*(void (__stdcall **)(int))(*(_DWORD *)v5 + 8))(v5);
            *(_DWORD *)(*(_DWORD *)(v1 + 72624) + 4 * v2) = 0;
          }
        }
        v6 = *(_DWORD *)(v1 + 72620);
        if ( v6 )
        {
          v7 = *(_DWORD *)(v6 + 4 * v2);
          if ( v7 )
          {
            (*(void (__stdcall **)(int))(*(_DWORD *)v7 + 8))(v7);
            *(_DWORD *)(*(_DWORD *)(v1 + 72620) + 4 * v2) = 0;
          }
        }
        --v2;
        v3 -= 72;
      }
      while ( v2 >= *(_DWORD *)(v1 + 72600) );
    }
    v8 = *(_DWORD *)(v1 + 72600);
    *(_DWORD *)(v1 + 72600) = 0;
    *(_DWORD *)(v1 + 72572) = v8;
    *(_DWORD *)(v1 + 72604) = 0;
  }
}

//----- (00461397) --------------------------------------------------------
int LODFile_Sprite::LODFile_sub_461397()
{
  int result; // eax@1
  int v2; // edi@1
  int v3; // esi@1
  int v4; // ecx@3

  result = *(_DWORD *)((int)this + 60572);
  v2 = (int)this + 60576;
  v3 = *(_DWORD *)((int)this + 60576);
  *(_DWORD *)((int)this + 60584) = result;
  if ( result < v3 )
    *(_DWORD *)((int)this + 60584) = v3;
  v4 = *(_DWORD *)((int)this + 60580);
  if ( v3 < v4 )
    *(_DWORD *)v2 = v4;
  return result;
}

//----- (00461492) ------LODFile_sub_461492---.text:00462798 -----------------------------------------------
 int LOD_Writefile::Write_Lod_Header( LODFileHeader* file_header, LODIndex *indx, const char *Source)
{

  FILE *open_file; 
  if ( file_opened )
    return 1;
  if ( !(indx->pFilename[0]) )
    return 2;
  strcpy(file_header->Signature, "LOD");
  file_header->dword00A4 = 100;	// A4
  file_header->uNumIndexDirs = 1;	  //AC
  indx->pFilename[15] = 0;
  indx->offset_from_unit_start= 288;
  indx->size_data=0;
  strcpy((char *)sLODName, Source);
  open_file = fopen(sLODName, "wb+");
  if ( !open_file )
    return 3;
  pLODFile = open_file;
  locked_fwrite(file_header, sizeof(LODFileHeader), 1, pLODFile);
  locked_fwrite(indx, sizeof(LODIndex), 1, pLODFile);
  fclose(pLODFile);
  pLODFile = NULL;
  return 0;
}

//----- (00461FD4) ---LODFile_sub_461FD4---text:004632EA  --------------------------------------------------
int LOD_Writefile::Write_SubIndex()
{
  
int total_size; // edi@1
int temp_offset; // ecx@5
FILE *tmp_file; // eax@9
size_t write_size; // edi@12
int result;
char Filename[256]; // [sp+Ch] [bp-228h]@9
char NewFilename[256]; // [sp+10Ch] [bp-128h]@15
int i;
LODIndex Lindx; // [sp+20Ch] [bp-28h]@11

total_size = 0;
if ( uNumSubidices > 0 )
	{

	for (i=0;i<uNumSubidices;i++)
		{
		total_size+=pLODSubIndexNamedBuffer[i].size_data;
		}
	}
temp_offset = sizeof(LODIndex) * uNumSubidices;
if ( uNumSubidices  > 0 )
	{
	for (i=0;i<uNumSubidices;i++)
		{
		pLODSubIndexNamedBuffer[i].offset_from_unit_start=temp_offset;
		temp_offset+=pLODSubIndexNamedBuffer[i].size_data;
		}
	}
strcpy(Filename, "lod.tmp");
tmp_file = fopen(Filename, "wb+");

if ( tmp_file )
	{
	locked_fwrite((const void *)&sLODFileHeader, sizeof(LODFileHeader), 1, tmp_file);
	Reset_LODIndex(&Lindx);
	strcpy(Lindx.pFilename, "chapter");
	Lindx.offset_from_unit_start=offset_to_subindex; //10h 16
	Lindx.size_data=sizeof(LODIndex) * uNumSubidices + total_size;		   //14h 20
	Lindx.reserved1=0;		   //18h 24 
	Lindx.uSubIndixes=uNumSubidices;		   //1ch 28
	Lindx.reserved3=0;		   // 1Eh 30
	locked_fwrite(&Lindx, sizeof(LODIndex), 1, tmp_file);
	locked_fwrite(pLODSubIndexNamedBuffer, sizeof(LODIndex), uNumSubidices, tmp_file);
	fseek(ptemp_write_file, 0, 0);
	if ( total_size > 0 )
		{
		do
			{
			write_size = uIOBufferSize;
			if ( total_size <= (signed int)uIOBufferSize )
				write_size =total_size;
			locked_fread(pLODIOBuffer, 1,  write_size,  ptemp_write_file);
			locked_fwrite(pLODIOBuffer, 1,  write_size, tmp_file);
			total_size -=  write_size;
			}
			while ( total_size > 0 );
		}
	strcpy(NewFilename, (const char *)&sLODName);
	fclose(tmp_file);
	fclose(ptemp_write_file);
	Close_Written_File();
	remove("lodapp.tmp");
	remove(NewFilename);
	rename(Filename, NewFilename);
	Close_Written_File();
	Load_File( (const char *)&sLODName, 0);
	result = 0;
	}
else
	{
	result = 5;
	}
return result;
}




//----- (00461F1E) --------------------------------------------------------
int LOD_Writefile::LODFile_sub_461F1E()
{
 
  int result; // eax@2
  FILE *v3; // eax@5
  int v4; // eax@5

  if (file_opened )
  {
    if ( pLODIOBuffer && uIOBufferSize )
    {
      current_index_dir = 0;
      uNumSubidices = 0;
      v3 = fopen("lodapp.tmp", "wb+");
     ptemp_write_file = v3;
      v4 = -(v3 != 0);
      LOBYTE(v4) = v4 & 0xF9;
      result = v4 + 7;
    }
    else
      result = 5;
  }
  else
    result = 1;
  return result;
}

//----- (00450C8B) --------------------------------------------------------
void  LODFile_Sprite::LODFile_sub_450C8B()
{
  
  int v2; // esi@1
  int v3; // edi@1

  v2 = uNumLoadedSprites;
  v3 = dword_00ECA8;
 
  uNumLoadedSprites=Delete_sprites_Range(  dword_00ECA8,uNumLoadedSprites);
  
 
}

//----- (00450CA9) -----.text:00451DBE---------------------------------------------------
int   LODFile_Sprite::Delete_sprites_Range( int start_indx, int stop_indx)
{
  int  result; // eax@1
 
  result=stop_indx;
  if ( pHardwareSprites )
  {
    if ( start_indx < stop_indx )
    {
     
	  for(int i=start_indx; i<stop_indx; i++) 
      {
        aSpriteHeaders[i].Clear_Data();
        sub_450D68(&pHardwareSprites[i]); 
		result--;
      }
     
    }
  }
  else
  {
    if ( start_indx < stop_indx )
    {
     for(int i=start_indx; i<stop_indx; i++)
		 {
        aSpriteHeaders[i].Clear_Data(); 
		result--;
		 }

    }
  }
  return result;
}


//----- (004103BB) --------------------------------------------------------
void LODFile_IB::sub_4103BB()
{
  int v1; // edi@1
  int v2; // esi@1
  int v3; // eax@2
  int v4; // eax@3
  int v5; // eax@5
  int v6; // eax@6

 // v2 = _this;
  v1 = uNumLoadedFiles;
  while ( 1 )
  {
    --v1;
    if ( v1 < 0 )
      break;
    v3 = (int)pHardwareTextures;
    if ( v3 )
    {
      v4 = *(_DWORD *)(v3 + 4 * v1);
      if ( v4 )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)v4 + 8))(v4);
        *(_DWORD *)((int)pHardwareTextures + 4 * v1) = 0;
        *(_BYTE *)(v1 + (int)pHardwareTextures) = 1;
      }
    }
    v5 = (int)pHardwareSurfaces;
    if ( v5 )
    {
      v6 = *(_DWORD *)(v5 + 4 * v1);
      if ( v6 )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v6);
        *(_DWORD *)((int)pHardwareSurfaces + 4 * v1) = 0;
        *(_BYTE *)(v1 + (int)pHardwareTextures) = 1;
      }
    }
  }
}

//----- (004ACB70) --------------------------------------------------------
void  LODFile_Sprite::sub_4ACB70()
{
  int v1; // esi@1
  int v2; // ebx@2
  int v3; // edi@3
  int v4; // eax@4
  int v5; // eax@5
  int v6; // eax@7
  int v7; // eax@8

  //v1 = _this;
  if ( pHardwareSprites )
  {
    v2 = 0;
    if ( uNumLoadedSprites > 0 )
    {
      v3 = 0;
      do
      {
        v4 = (int)pHardwareSprites;
        if ( v4 )
        {
          v5 = *(_DWORD *)(v3 + v4 + 12);
          if ( v5 )
          {
            (*(void (__stdcall **)(int))(*(_DWORD *)v5 + 8))(v5);
            *(_DWORD *)(v3 + (int)pHardwareSprites + 12) = 0;
          }
          v6 = (int)pHardwareSprites;
          if ( v6 )
          {
            v7 = *(_DWORD *)(v3 + v6 + 8);
            if ( v7 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v7 + 8))(v7);
              *(_DWORD *)(v3 + (int)pHardwareSprites + 8) = 0;
            }
          }
        }
        ++v2;
        v3 += 40;
      }
      while ( v2 < uNumLoadedSprites );
    }
  }
}


//----- (00410423) --------------------------------------------------------
void   LODFile_IB::sub_410423()
{
  int v1; // edi@1
  int v2; // esi@1
  int v3; // ebx@2
  size_t v4; // eax@9
  unsigned int v5; // ST1C_4@9
  int v6; // eax@9
  void *result; // eax@12
  signed int v8; // esi@13
  /*
  //v2 = _this;
  v1 = uNumLoadedSprites - 1;
  if ( v1 >= 0 )
  {
    v3 = dword0023E+72 * v1 ;
    do
    {
      if ( *(_BYTE *)(v1 + dword_011BB4) )
      {
        if ( *(_BYTE *)(v3 - 2) != 119
          || *(_BYTE *)(v3 - 1) != 116
          || *(_BYTE *)v3 != 114
          || *(_BYTE *)(v3 + 1) != 100
          || *(_BYTE *)(v3 + 2) != 114 )
        {
          Render_sub_4A4DE1(
            (int)pD3DRenderer,
            v3 - 2,
            *(_WORD *)(v3 + 34),
            4 * v1 + (int)pHardwareSurfaces,
            4 * v1 + (int)pHardwareSurfaces);
        }
        else
        {
          v4 = strlen((const char *)(v3 - 2));
          compile_error;//v5 = (unsigned int)(new char[v4 + 2]);
          *(_BYTE *)v5 = 104;
          strcpy((char *)(v5 + 1), (const char *)(v3 - 2));
          v6 = Render_sub_4A4DE1(
                 (int)pD3DRenderer,
                 v5,
                 *(_WORD *)(v3 + 34),
                 4 * v1 + (int)pHardwareSurfaces,
                 4 * v1 + (int)pHardwareSurfaces);
          operator_delete((void *)v5);
        }
      }
      --v1;
      v3 -= 72;
    }
    while ( v1 >= 0 );
  }
  result = *(void **)(v2 + 72628);
  if ( result )
  {
    v8 = *(_DWORD *)(v2 + 72572);
    if ( v8 > 1 )
      result = memset(result, 0, v8 - 1);
  }	   */
  return;
}


//----- (004ACBE0) --------------------------------------------------------
void  LODFile_Sprite::sub_4ACBE0()
{
  int v1; // ebx@1
  int v2; // esi@1
  int v3; // edi@2
 

 // v2 = _this;
  v1 = 0;
  if (pHardwareSprites )
  {
    v3 = 0;
    if ( uNumLoadedSprites > 0 )
    {
      do
      {
       (void *)Render_MoveHWSpriteToVideoMemory(pD3DRenderer, (HardwareSprite *)(v1 + (int)pHardwareSprites));
        ++v3;
        v1 += 40;
      }
      while ( v3 <uNumLoadedSprites);
    }
  }
 
}


//----- (004ACADA) --------------------------------------------------------
void  LODFile_Sprite::sub_4ACADA()
{
  int v1; // esi@1
  int v2; // ebx@2
  int v3; // edi@3
  int v4; // eax@4
  int v5; // eax@6
  int v6; // ST00_4@8

  v1 = (int)this;
  if ( *(_DWORD *)(v1 + 60592) )
  {
    v2 = 0;
    if ( *(_DWORD *)(v1+ 60572) > 0 )
    {
      v3 = 0;
      do
      {
        v4 = *(_DWORD *)(v3 + *(_DWORD *)(v1 + 60592) + 8);
        if ( v4 )
        {
          if ( (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v4 + 96))(*(_DWORD *)(v3 + *(_DWORD *)(v1 + 60592) + 8)) == -2005532222 )
          {
            v5 = *(_DWORD *)(v3 + *(_DWORD *)(v1 + 60592) + 12);
            if ( v5 )
            {
              (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(*(_DWORD *)(v3 + *(_DWORD *)(v1 + 60592) + 12));
              *(_DWORD *)(v3 + *(_DWORD *)(v1 + 60592) + 12) = 0;
            }
            v6 = *(_DWORD *)(v3 + *(_DWORD *)(v1 + 60592) + 8);
            (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v6);
            *(_DWORD *)(v3 + *(_DWORD *)(v1 + 60592) + 8) = 0;
            Render_MoveHWSpriteToVideoMemory(pD3DRenderer, (HardwareSprite *)(v3 + *(_DWORD *)(v1 + 60592)));
          }
        }
        ++v2;
        v3 += 40;
      }
      while ( v2 < *(_DWORD *)(v1 + 60572) );
    }
  }
}

//----- (0041033D) --------------------------------------------------------
void  LODFile_IB::sub_41033D()
{
  int i; // ebx@1
  int v2; // edi@1
  int v3; // eax@2
  int v4; // eax@3
  int v5; // esi@3
  int v6; // eax@5
  int v7; // eax@6

  v2 = (int)this;
  for ( i = *(_DWORD *)(v2 + 72572) - 1; i >= 0; --i )
  {
    v3 = *(_DWORD *)(v2 + 72620);
    if ( v3 )
    {
      v5 = 4 * i;
      v4 = *(_DWORD *)(4 * i + v3);
      if ( v4 )
      {
        if ( (*(int (__stdcall **)(int))(*(_DWORD *)v4 + 96))(v4) == 0x887601C2 )
        {
          v6 = *(_DWORD *)(v2 + 72624);
          if ( v6 )
          {
            v7 = *(_DWORD *)(v6 + v5);
            if ( v7 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v7 + 8))(v7);
              *(_DWORD *)(v5 + *(_DWORD *)(v2 + 72624)) = 0;
            }
          }
          (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v5 + *(_DWORD *)(v2 + 72620)) + 8))(*(_DWORD *)(v5 + *(_DWORD *)(v2 + 72620)));
          *(_DWORD *)(v5 + *(_DWORD *)(v2 + 72620)) = 0;
          *(_BYTE *)(i + *(_DWORD *)(v2 + 72628)) = 1;
        }
      }
    }
  }
}

