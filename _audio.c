#include "_audio.h"
#include "_video.h"
#include "AIL.h"
#include "Smacker.h"

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





void class31_ctor(struct class31 *_this)
{
 char pCurrentDirectory[121];
 char pIniFile[132];

 memset(_this, 0, sizeof(struct class31));

 _this->cGameCDDriveLetter = cGameCDDriveLetter;

 _getcwd(pCurrentDirectory, 120);
 sprintfex(pIniFile, "%s\\mm6.ini", pCurrentDirectory);

 _this->iMixerChannels = GetPrivateProfileIntA("settings", "mixerchannels", 16, pIniFile);
 if (_this->iMixerChannels <= 16)
 {
  if (_this->iMixerChannels < 0)
    _this->iMixerChannels = 0;
 }
 else _this->iMixerChannels = 16;
}

//----- (MM7.exe::004AB8CE) --------------------------------------------------------
int __thiscall class31_Initialize(struct class31 *_this, HWND hWnd)
{
  int v5; // eax@9
  int v6; // ST00_4@9
  HSAMPLE hSample; // eax@15
  int v13; // [sp-4h] [bp-1Ch]@7
  int v14; // [sp+Ch] [bp-Ch]@9
  char *Str1; // [sp+10h] [bp-8h]@6
  int v16; // [sp+14h] [bp-4h]@5
  int i;

 _this->hWnd = hWnd;
 _this->hAILRedbook = 0;
 _this->hDigDriver = 0;
 _this->dword_0002AC = 0;
 _this->dword_0002B0 = 0;
 _this->dword_0002C4 = 127;
 _this->dword_0002C8 = 64;
 _this->dword_0002CC = 2;

 MSS32_DLL_Initialize();
 SMACKW32_DLL_Initialize();

 AIL_startup();

 _this->hAILRedbook = AIL_redbook_open_drive(_this->cGameCDDriveLetter);
 _this->hDigDriver = sub_4ABAF7();
 if (_this->hDigDriver)
   SmackSoundUseMSS(_this->hDigDriver);

 if (ReadWindowsRegistry("Disable3DSound", 0) != 1 && dword_F79D7C != 2)
 {
  v16 = 0;
    *(_DWORD *)_this = 0;
    *(_DWORD *)(_this + 4) = 0;
    ReadWindowsRegistry("3DSoundProvider", (BYTE *)(_this + 540), 0x80u, "NONE");
    sub_4ABC9B(1);
    while ( AIL_enumerate_3D_providers(&v16, &hWnd, &Str1) )
    {
      if ( !strcmp(Str1, (const char *)(_this + 540)) )
      {
        if ( AIL_open_3D_provider(v13, hWnd) )
        {
          *(_DWORD *)_this = 0;
          *(_DWORD *)(_this + 4) = 0;
          *(_DWORD *)(_this + 12) = 0;
        }
        else
        {
          v5 = hWnd;
          v6 = hWnd;
          *(_DWORD *)(_this + 4) = 1;
          *(_DWORD *)(_this + 12) = v5;
          *(_DWORD *)(_this + 16) = 4;
          AIL_3D_provider_attribute(v6, "EAX environment selection", &v14);
          if ( v14 != -1 )
            *(_DWORD *)_this = 1;
        }
        sub_4AC0A2(_this);
        break;
      }
    }
  }

 if (_this->iMixerChannels > 0)
 {
  for (i = 0; i < _this->iMixerChannels; ++i)
  {
   hSample = AIL_allocate_sample_handle(_this->hDigDriver);
   _this->array_0002E8[i * 4] = hSample;

   if (!hSample)
     break;
  }
 }

 if (_this->dword_00029C)
   sub_4AB71F(_this, -1, -1);
 _this->dword_00029C = 1;

 if (_this->hAILRedbook)
 {
  AIL_redbook_stop(_this->hAILRedbook);
  _this->dword_0002DC = AIL_redbook_tracks(_this->hAILRedbook);
 }

 //dword_F792F0 = AIL_redbook_volume(dword_F7937C);
 pClass31_global->dword_000218 = AIL_redbook_volume(pClass31_global->hAILRedbook);

 sub_4AA214(pClass31_global, 128.0 * aMusicVolumeLevels[byte_6BE36F]);
 if (pClass31_global->dword_00029C)
 {
  if (pClass31_global->hAILRedbook)
    AIL_redbook_set_volume(pClass31_global->hAILRedbook, 64.0 * aMusicVolumeLevels[byte_6BE371]);
 }
 class31_LoadSoundHeaders(_this);

 pClass32_global = malloc(sizeof(struct class32));
 class32_ctor(pClass32_global);
 return class32_LoadVideoHeaders(pClass32_global);
}

//----- (MM7.exe::004AB818) --------------------------------------------------------
int class31_LoadSoundHeaders(struct class31 *_this)
{
 DWORD w;

 strcpy(ExistingFileName, "Sounds\\Audio.snd");
 _this->hSoundsSource = CreateFileA("Sounds\\Audio.snd", GENERIC_READ, 1u, 0, 3u, 0x8000080u, 0);
 if (_this->hSoundsSource == INVALID_HANDLE_VALUE)
 {
  sprintfex(pStringBuffer, "Can't open file - %s", ExistingFileName);
  return MessageBoxA(0, pStringBuffer, "Sound File Error", 0);
 }

 ReadFile(_this->hSoundsSource, &_this->uNumSounds, 4, &w, 0);

 _this->pSoundHeaders = class23_AllocatedNamedBuffer(class23_instance, 0, _this->uNumSounds * sizeof(struct class31_sound_header_struct) + 2, 0);

 return ReadFile(_this->hSoundsSource, _this->pSoundHeaders, _this->uNumSounds * sizeof(struct class31_sound_header_struct), &w, 0);
}

//----- (MM7.exe::004AA214) --------------------------------------------------------
void sub_4AA214(struct class31 *_this, signed int a2)
{
 if (_this->dword_00029C)
 {
  _this->dword_0002C4 = a2;
  if (_this->hDigDriver)
    AIL_set_digital_master_volume(_this->hDigDriver, a2);

  if (_this->dword_000004)
    _this->dword_000008 = (signed __int64)((double)a2 * *(double *)&byte_4D8410[256]);
 }
}

//----- (MM7.exe::004ABAF7) --------------------------------------------------------
HDIGDRIVER __cdecl sub_4ABAF7()
{
  int v0; // ecx@1
  int i;
  size_t v2; // eax@4
  int v4; // [sp-4h] [bp-20h]@5
  int *v5; // [sp+10h] [bp-Ch]@2
  HDIGDRIVER hDrv;

  AIL_set_preference(15, 0);
  AIL_set_preference(33, 1);

  v0 = dword_4F00DC;
  pClass31_global->aDeviceNames[0][0] = 0;
  pClass31_global->uNumDevices = 0;
  if (dword_4F00DC < 11025)
    return 0;
 v5 = pClass31_global->array_000BF0;
 i = 0;
 while (true)
 {
  while (true)
  {
   sPCMWaveFormat.wf.wFormatTag = 1;
   sPCMWaveFormat.wf.nChannels = dword_4F00E4;
   sPCMWaveFormat.wf.nSamplesPerSec = v0;
   sPCMWaveFormat.wf.nBlockAlign = dword_4F00E4 * dword_4F00E0 / 8;
   sPCMWaveFormat.wf.nAvgBytesPerSec = v0 * dword_4F00E4 * dword_4F00E0 / 8;
   sPCMWaveFormat.wBitsPerSample = dword_4F00E0;

   if (!AIL_waveOutOpen(&hDrv, 0, -1, &sPCMWaveFormat))
     break;

      if ( !AIL_get_preference(15) )
        goto LABEL_8;
      v0 = dword_4F00DC / 2;
      dword_4F00DC /= 2;
      if ( dword_4F00DC < 11025 )
      {
        if ( dword_4F00E0 == 8 )
        {
          v0 = 22050;
          dword_4F00E0 = 8;
          dword_4F00DC = 22050;
        }
        goto LABEL_12;
      }
    }
    //strcpy(&byte_F794C8[v1], "Device: ");
    //v2 = strlen(&byte_F794C8[v1]);
    strcpy(&pClass31_global->aDeviceNames[i], "Device: ");
    v2 = strlen(&pClass31_global->aDeviceNames[i]);

    //AIL_digital_configuration(v7, v5, (char *)v5 + 64, &byte_F794C8[v2] + v1);
    AIL_digital_configuration(hDrv, v5, v5 + 16, &pClass31_global->aDeviceNames[i][v2]);

    v5++;
    pClass31_global->uNumDevices = ++i;

    if (AIL_get_preference(15))
      return hDrv;
    if (!strstr(pClass31_global->aDeviceNames[i - 1], "Emulated"))
      return hDrv;
    AIL_waveOutClose(v4, hDrv);
    AIL_set_preference(15, 1);
LABEL_8:
    AIL_set_preference(15, 1);
    v0 = dword_4F00DC;
LABEL_12:
    if ( v0 < 11025 )
      return 0;
  }
}