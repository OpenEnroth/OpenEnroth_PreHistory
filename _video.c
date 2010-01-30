#include "_video.h"

#include <stdio.h>


#include "data.h"


extern char off_4E7ECC[];
extern int dword_4E800C;
extern float flt_6BE3A0;
extern int dword_AD4730;
extern int dword_E31C7C;
extern char byte_6BE371;
extern int dword_4F00DC;
extern char unk_F79CC8[];
extern char byte_F79448[];


extern char unk_4EB8BC;
extern char unk_4EBBD0;
extern char byte_6BE36F;

extern int dword_4F00E4;
extern short word_F1B4C4;
extern int dword_4F00E4;
extern int dword_4F00E0;
extern short word_F1B4C6;
extern int dword_4F00E0;
extern int dword_4F00E4;
extern int dword_4F00E0;

extern char byte_4D8410[];

extern int *dword_4F2688;

extern int dword_51B6E8;
extern int dword_51B6EC;
extern int dword_51B6F0;

extern int dword_6A0CA4;

extern int dword_720010;

extern int dword_720018;

extern int dword_E31C70;

extern int dword_F792F0;

extern int dword_F79D70;
extern int dword_F79D7C;





//----- (MM7.exe::004BE9D8) --------------------------------------------------------
int class32_LoadVideoHeaders(struct class32 *_this)
{
 DWORD w;

 strcpy(ExistingFileName, "anims\\might7.vid");
 _this->hMightVid = CreateFileW(L"anims\\might7.vid", GENERIC_READ, 1, 0, 3, 0x8000080, 0);
 if (_this->hMightVid == INVALID_HANDLE_VALUE)
 {
  MessageBoxW(0, L"Can't open file: Might7.vid", L"Video File Error", 0);
  return false;
 }

 strcpy(ExistingFileName, "anims\\magic7.vid");
 _this->hMagicVid = CreateFileW(L"anims\\magic7.vid", GENERIC_READ, 1, 0, 3, 0x8000080, 0);
 if (_this->hMagicVid == INVALID_HANDLE_VALUE)
 {
  if (!bLoadingFromCD)
  {
   MessageBoxW(0, L"Can't open file: Magic7.vid", L"Video File Error", 0);
   return false;
  }

  sprintfex(pStringBuffer, "%c:\\%s", cGameCDDriveLetter, "anims\\magic7.vid");
  _this->hMagicVid = CreateFileA(pStringBuffer, GENERIC_READ, 1u, 0, 3u, 0x8000080u, 0);
  if ( _this->hMagicVid == INVALID_HANDLE_VALUE )
  {
   MessageBoxW(0, L"Can't open file: Magic7.vid", L"Video File Error", 0);
   return false;
  }
 }

 ReadFile(_this->hMightVid, &_this->uNumMightVideoHeaders, 4, &w, 0);
 ReadFile(_this->hMagicVid, &_this->uNumMagicVideoHeaders, 4, &w, 0);

 _this->pMightVideoHeaders = class23_AllocatedNamedBuffer(class23_instance, 0, _this->uNumMightVideoHeaders * sizeof(struct class32_smk_header_struct) + 2, 0);
 _this->pMagicVideoHeaders = class23_AllocatedNamedBuffer(class23_instance, 0, _this->uNumMagicVideoHeaders * sizeof(struct class32_smk_header_struct) + 2, 0);

 ReadFile(_this->hMightVid, _this->pMightVideoHeaders, _this->uNumMightVideoHeaders * sizeof(struct class32_smk_header_struct), &w, 0);
 ReadFile(_this->hMagicVid, _this->pMagicVideoHeaders, _this->uNumMagicVideoHeaders * sizeof(struct class32_smk_header_struct), &w, 0);

 return true;
}



void class32_ctor(struct class32 *_this)
{
 memset(_this, 0, sizeof(struct class32));
}